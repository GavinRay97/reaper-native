import re
from collections import Counter
from dataclasses import dataclass


@dataclass
class FnPtrDefinition:
    name: str
    args: str
    return_type: str
    needs_manual_fixing: bool

    # Prefixes the names in the header/implementation files so
    # that they don't collide with reaper_plugin_function.h names
    @staticmethod
    def name_prefix():
        return "_"

    @dataclass
    class Argument:
        name: str
        type: str

    @property
    def argument_list(self) -> list[Argument]:
        return self.process_args()

    def process_args(self) -> list[Argument]:
        results: list[FnPtrDefinition.Argument] = []
        if self.args == "":
            return []
        for entry in self.args.split(", "):
            params = entry.split(" ")
            if len(params) == 3:
                name = params.pop()
                ctype = " ".join(params)
                results.append(FnPtrDefinition.Argument(name=name, type=ctype))
            elif len(params) == 2:
                ctype, name = params
                results.append(FnPtrDefinition.Argument(name=name, type=ctype))
            else:
                raise Exception(f"What the fuck? params = {params}")
        return results

    def to_wrapper_function_impl(self) -> str:
        arg_names = map(lambda it: it.name, self.process_args())
        return f"""
REAPER_PLUGIN_DLL_EXPORT {self.return_type} {self.name_prefix()}{self.name}({self.args}) {{
  return {self.name}({", ".join(arg_names)});
}}
"""

    def to_wrapper_function_header(self) -> str:
        arg_names = map(lambda it: it.name, self.process_args())
        return f"REAPER_PLUGIN_DLL_EXPORT {self.return_type} {self.name_prefix()}{self.name}({self.args});\n"


def is_fn_ptr_definition_line(line: str) -> bool:
    return all(char in line for char in ["(", "*", ")", ";"]) and "//" not in line


def process_fn_ptr_definition_line(line: str) -> FnPtrDefinition:
    first_l_paren = line.index("(")
    first_r_paren = line.index(")")

    return_type: str = line[0:first_l_paren].strip()
    fn_name: str = line[first_l_paren:first_r_paren].removeprefix("(*")
    fn_args: str = line[first_r_paren:].removeprefix(")(").removesuffix(");")

    # Normalize whitespace to prevent weird errors later on in text processing arising from accidental double-spaces, etc
    return_type = " ".join(return_type.split())
    fn_name = " ".join(fn_name.split())
    fn_args = " ".join(fn_args.split())

    # If num parens greater than 2, it has arguments which are function pointers
    # These are just too fucking complicated to try to parse programmatically, and currently only "__mergesort" has this
    needs_manual_fixing = line.count("(") > 2
    return FnPtrDefinition(name=fn_name, args=fn_args, return_type=return_type, needs_manual_fixing=needs_manual_fixing)


#########################################################################################################################

def parse_header_to_fn_ptr_definitions(header_path: str) -> list[FnPtrDefinition]:
    with open(header_path, "r") as f:
        reaper_plugin_functions_header = f.read()

        first_function_char_idx = reaper_plugin_functions_header.index(
            "#if defined(REAPERAPI_WANT")

        end_of_functions_idx = reaper_plugin_functions_header.index(
            "REAPERAPI_IMPLEMENT", first_function_char_idx) - (len("REAPERAPI_IMPLEMENT") - 2)

        raw_functions_text = reaper_plugin_functions_header[
            first_function_char_idx:end_of_functions_idx]

        text_to_strip = [
            r"#if defined\(REAPERAPI_WANT_\w+\) \|\| !defined\(REAPERAPI_MINIMAL\)",
            r"REAPERAPI_DEF ",
            r"#ifndef REAPERAPI_NO_LICE",
            r"#endif"
        ]

        processed_text = raw_functions_text
        for it in text_to_strip:
            processed_text = re.sub(it, '', processed_text)

        processed_text = re.sub(r"\n\n", r"\n", processed_text)

        results: list[FnPtrDefinition] = []
        for line in processed_text.splitlines():
            if is_fn_ptr_definition_line(line):
                fn_ptr = process_fn_ptr_definition_line(line)
                results.append(fn_ptr)
        return results


def generate_wrapper_header():
    fn_ptrs = parse_header_to_fn_ptr_definitions(
        "C:\\Users\\rayga\\Projects\\tmp\\ReaperDNNE\\reaper-sdk\\sdk\\reaper_plugin_functions.h")

    header_output = """
    // reaper_plugin_functions_wrapper.hpp
    #include "reaper_plugin_functions.h"

    REAPER_PLUGIN_DLL_EXPORT int REAPERAPI_LoadAPIWrapper(void *(*getAPI)(const char*));

    """

    implementation_output = """
    // reaper_plugin_functions_wrapper.cpp
    #define REAPERAPI_IMPLEMENT
    #include "reaper_plugin_functions_wrapper.hpp"

    REAPER_PLUGIN_DLL_EXPORT int REAPERAPI_LoadAPIWrapper(void *(*getAPI)(const char*)) {
    return REAPERAPI_LoadAPI(getAPI);
    }

    """

    for fn_ptr in fn_ptrs:
        header_output += fn_ptr.to_wrapper_function_header()
        implementation_output += fn_ptr.to_wrapper_function_impl()

    with open("./wrapper/reaper_plugin_functions_wrapper.hpp", "w+") as f:
        f.write(header_output)

    with open("./wrapper/reaper_plugin_functions_wrapper.cpp", "w+") as f:
        f.write(implementation_output)


def generate_csharp_dllimport_wrapper():
    fn_ptrs = parse_header_to_fn_ptr_definitions(
        "C:\\Users\\rayga\\Projects\\tmp\\ReaperDNNE\\reaper-sdk\\sdk\\reaper_plugin_functions.h")

    basic_c_types = ["void", "char", "int", "double", "long", "float", "short"]

    type_substitutions = (
        ("const char*", "string"),
        ("char*", "string"),
        ("void*", "IntPtr"),
        ("unsigned char", "byte"),
        ("unsigned short", "ushort"),
        ("unsigned int", "uint"),
        # Per Tanner: "C long is not C# long, its actually int on Windows and nint on Unix"
        ("long", "int"),
        # uint on Windows and nuint on Unix
        ("unsigned long", "uint"),
    )

    c_types = [c_type for (c_type, csharp_type) in type_substitutions]
    csharp_types = [csharp_type for (
        c_type, csharp_type) in type_substitutions]

    for fn_ptr in fn_ptrs:
        fails_type_substitution = False

        for arg in fn_ptr.argument_list:
            if not arg.type in c_types:
                fails_type_substitution = True

        if fails_type_substitution:
            continue
        else:
            args = fn_ptr.args
            return_type = fn_ptr.return_type

            for (c_type, csharp_type) in type_substitutions:
                args = args.replace(c_type, csharp_type)
                return_type = return_type.replace(c_type, csharp_type)

            if return_type in basic_c_types:
                print(
                    f'[GeneratedDllImport(NativeExportsNE_Binary, EntryPoint = "_{fn_ptr.name}", CharSet = CharSet.Auto)]')
                print("public static extern", return_type, fn_ptr.name, "(", args, ");")
                print()


generate_csharp_dllimport_wrapper()

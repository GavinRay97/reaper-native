#include <stdio.h>
#include <string.h>
#include <windows.h>

#define EXPORTED_ENTRYPOINT_FN_NAME "ReaperPluginEntry"
#define DLL_NAME "../bin/Debug/net6.0/win-x64/ReaperDNNENE.dll"

typedef struct {
  int caller_version;
  HWND hwnd_main;
  int (*Register)(const char *name, void *infostruct);
  void *(*GetFunc)(const char *name);
} reaper_plugin_info_t;

void ShowConsoleMsg(const char *msg) {
  printf("[ShowConsoleMsg]: %s \n", msg);
  return;
}

void *GetFunc(const char *name) {
  printf("GetFunc called with function name: %s \n", name);
  if (strcmp(name, "ShowConsoleMsg") == 0)
    return &ShowConsoleMsg;
  return NULL;
}

int main() {
  HMODULE hTargetDll = LoadLibraryA(DLL_NAME);
  if (!hTargetDll) {
    printf("[!] LoadLibraryA failed. Error: %lu\n", GetLastError());
    return 0;
  }
  printf("[+] Target DLL base address: 0x%p\n", hTargetDll);

  FARPROC entrypointFuncPtr = GetProcAddress(hTargetDll, EXPORTED_ENTRYPOINT_FN_NAME);
  void (*ReaperPluginEntry)(void *, reaper_plugin_info_t *) =
      (void (*)(void *, reaper_plugin_info_t *))entrypointFuncPtr;

  reaper_plugin_info_t rec;
  rec.caller_version = 1;
  rec.hwnd_main = NULL;
  rec.GetFunc = &GetFunc;
  rec.Register = NULL;

  ReaperPluginEntry(NULL, &rec);
  printf("[+] done\n");

  return 1;
}
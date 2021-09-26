using System;
using System.Runtime.InteropServices;

namespace ReaperSharp
{
  public static unsafe class MyReaperPlugin
  {

    private const string ReaperPluginInfoStructString = @"
      struct reaper_plugin_info_t
      {
        int caller_version;
        void* hwnd_main;
        int (*Register)(const char* name, void* infostruct);
        void* (*GetFunc)(const char* name);
      };
    ";

    [UnmanagedCallersOnly(EntryPoint = "ReaperPluginEntry")]
    [DNNE.C99DeclCode(ReaperPluginInfoStructString)]
    public static int ReaperPluginEntry(IntPtr hInstance, [DNNE.C99Type("struct reaper_plugin_info_t*")] reaper_plugin_info_t* rec)
    {
      try
      {
        // Initialize
        reaper_plugin_functions reaper = new();
        reaper.Initialize(rec);

        // Hello World
        IntPtr msgPtr = Marshal.StringToHGlobalAnsi("Hello From C#");
        try
        {
          reaper.ShowConsoleMsg((sbyte*)msgPtr);
        }
        finally
        {
          Marshal.FreeHGlobal(msgPtr);
        }

        return 1;
      }
      // Handle exception
      catch (Exception e)
      {
        System.Diagnostics.Debug.WriteLine(e);
        return 0;
      }
    }
  }
}
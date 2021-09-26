using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace ReaperSharp
{

  /* Opaque Types (manual) */
  public partial struct HWND { }
  public partial struct GUID { }
  public partial struct RECT { }
  public partial struct MSG { }
  public partial struct HMENU { }
  public partial struct ACCEL { }
  public partial struct HINSTANCE { }
  public partial struct HDC { }
  public partial struct HFONT { }


  public partial struct LICE_IBitmap { }

  public partial struct LICE_IFont { }

  public partial struct WDL_VirtualWnd_BGCfg { }

  public partial struct AudioAccessor { }

  public partial struct joystick_device { }

  /* */
  public partial struct ReaProject { }

  public partial struct MediaTrack { }

  public partial struct MediaItem { }

  public partial struct MediaItem_Take { }

  public partial struct TrackEnvelope { }

  /* */

  public partial struct PCM_sink { }
  public partial struct PCM_source { }
  public partial struct PCM_source_transfer_t { }
  public partial struct PCM_source_peaktransfer_t { }
  public partial struct KbdSectionInfo { }
  public partial struct MIDI_event_t { }
  public partial struct ISimpleMediaDecoder { }
  public partial struct REAPER_PeakBuild_Interface { }
  public partial struct REAPER_PeakGet_Interface { }
  public partial struct preview_register_t { }

  public partial struct midi_Input { }
  public partial struct midi_Output { }
  public partial struct IReaperControlSurface { }
  public partial struct audio_hook_register_t { }
  public partial struct MIDI_eventlist { }
  public partial struct IReaperPitchShift { }
  public partial struct REAPER_Resample_Interface { }

  public unsafe partial struct reaper_plugin_info_t
  {
    public int caller_version;

    public IntPtr hwnd_main;

    [NativeTypeName("int (*)(const char *, void *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void*, int> Register;

    [NativeTypeName("void *(*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void*> GetFunc;
  }

  public unsafe struct reaper_plugin_functions
  {
    public void Initialize(reaper_plugin_info_t* rec)
    {
      foreach (FieldInfo field in typeof(reaper_plugin_functions).GetFields())
      {
        IntPtr offset = Marshal.OffsetOf<reaper_plugin_functions>(field.Name);
        ref reaper_plugin_functions r0 = ref Unsafe.AddByteOffset(ref this, offset);
        ref nint r1 = ref Unsafe.As<reaper_plugin_functions, nint>(ref r0);
        IntPtr buffer = Marshal.StringToCoTaskMemUTF8(field.Name);

        try
        {
          r1 = (nint)rec->GetFunc((sbyte*)buffer);
        }
        finally
        {
          Marshal.FreeCoTaskMem(buffer);
        }
      }
    }

    [NativeTypeName("bool (*)(const char *, const char *, const char *, bool)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, sbyte*, byte, byte> AddCustomizableMenu;

    [NativeTypeName("bool (*)()")]
    public delegate* unmanaged[Cdecl]<byte> AddExtensionsMainMenu;

    [NativeTypeName("MediaItem *(*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, MediaItem*> AddMediaItemToTrack;

    [NativeTypeName("int (*)(ReaProject *, bool, double, double, const char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte, double, double, sbyte*, int, int> AddProjectMarker;

    [NativeTypeName("int (*)(ReaProject *, bool, double, double, const char *, int, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte, double, double, sbyte*, int, int, int> AddProjectMarker2;

    [NativeTypeName("int (*)(bool, int, const char *, bool)")]
    public delegate* unmanaged[Cdecl]<byte, int, sbyte*, byte, int> AddRemoveReaScript;

    [NativeTypeName("MediaItem_Take *(*)(MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, MediaItem_Take*> AddTakeToMediaItem;

    [NativeTypeName("bool (*)(ReaProject *, double, double, int, int, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, double, int, int, byte, byte> AddTempoTimeSigMarker;

    [NativeTypeName("void (*)(double, int, bool, int)")]
    public delegate* unmanaged[Cdecl]<double, int, byte, int, void> adjustZoom;

    [NativeTypeName("bool (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte> AnyTrackSolo;

    [NativeTypeName("bool (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, byte> APIExists;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> APITest;

    [NativeTypeName("bool (*)(ReaProject *, int, int, int, double, bool, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, int, int, double, byte, int, byte> ApplyNudge;

    [NativeTypeName("void (*)(int, const char *)")]
    public delegate* unmanaged[Cdecl]<int, sbyte*, void> ArmCommand;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> Audio_Init;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> Audio_IsPreBuffer;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> Audio_IsRunning;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> Audio_Quit;

    [NativeTypeName("int (*)(bool, audio_hook_register_t *)")]
    public delegate* unmanaged[Cdecl]<byte, audio_hook_register_t*, int> Audio_RegHardwareHook;

    [NativeTypeName("bool (*)(AudioAccessor *)")]
    public delegate* unmanaged[Cdecl]<AudioAccessor*, byte> AudioAccessorStateChanged;

    [NativeTypeName("void (*)(AudioAccessor *)")]
    public delegate* unmanaged[Cdecl]<AudioAccessor*, void> AudioAccessorUpdate;

    [NativeTypeName("bool (*)(AudioAccessor *)")]
    public delegate* unmanaged[Cdecl]<AudioAccessor*, byte> AudioAccessorValidateState;

    [NativeTypeName("void (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, void> BypassFxAllTracks;

    [NativeTypeName("int (*)(PCM_source_transfer_t *, PCM_source_peaktransfer_t *)")]
    public delegate* unmanaged[Cdecl]<PCM_source_transfer_t*, PCM_source_peaktransfer_t*, int> CalculatePeaks;

    [NativeTypeName("int (*)(PCM_source_transfer_t *, PCM_source_peaktransfer_t *)")]
    public delegate* unmanaged[Cdecl]<PCM_source_transfer_t*, PCM_source_peaktransfer_t*, int> CalculatePeaksFloatSrcPtr;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> ClearAllRecArmed;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> ClearConsole;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> ClearPeakCache;

    [NativeTypeName("void (*)(int, int *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<int, int*, int*, int*, void> ColorFromNative;

    [NativeTypeName("int (*)(int, int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, int, int> ColorToNative;

    [NativeTypeName("int (*)(KbdSectionInfo *, int)")]
    public delegate* unmanaged[Cdecl]<KbdSectionInfo*, int, int> CountActionShortcuts;

    [NativeTypeName("int (*)(TrackEnvelope *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int> CountAutomationItems;

    [NativeTypeName("int (*)(TrackEnvelope *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int> CountEnvelopePoints;

    [NativeTypeName("int (*)(TrackEnvelope *, int)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, int> CountEnvelopePointsEx;

    [NativeTypeName("int (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int> CountMediaItems;

    [NativeTypeName("int (*)(ReaProject *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int*, int*, int> CountProjectMarkers;

    [NativeTypeName("int (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int> CountSelectedMediaItems;

    [NativeTypeName("int (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int> CountSelectedTracks;

    [NativeTypeName("int (*)(ReaProject *, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte, int> CountSelectedTracks2;

    [NativeTypeName("int (*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int> CountTakeEnvelopes;

    [NativeTypeName("int (*)(MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, int> CountTakes;

    [NativeTypeName("int (*)(ReaProject *, MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, MediaTrack*, int> CountTCPFXParms;

    [NativeTypeName("int (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int> CountTempoTimeSigMarkers;

    [NativeTypeName("int (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int> CountTrackEnvelopes;

    [NativeTypeName("int (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int> CountTrackMediaItems;

    [NativeTypeName("int (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int> CountTracks;

    [NativeTypeName("void *(*)(void *, void *)")]
    public delegate* unmanaged[Cdecl]<void*, void*, void*> CreateLocalOscHandler;

    [NativeTypeName("midi_Input *(*)(int)")]
    public delegate* unmanaged[Cdecl]<int, midi_Input*> CreateMIDIInput;

    [NativeTypeName("midi_Output *(*)(int, bool, int *)")]
    public delegate* unmanaged[Cdecl]<int, byte, int*, midi_Output*> CreateMIDIOutput;

    [NativeTypeName("MediaItem *(*)(MediaTrack *, double, double, const bool *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, double, double, bool*, MediaItem*> CreateNewMIDIItemInProj;

    [NativeTypeName("AudioAccessor *(*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, AudioAccessor*> CreateTakeAudioAccessor;

    [NativeTypeName("AudioAccessor *(*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, AudioAccessor*> CreateTrackAudioAccessor;

    [NativeTypeName("int (*)(MediaTrack *, MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, MediaTrack*, int> CreateTrackSend;

    [NativeTypeName("void (*)(bool)")]
    public delegate* unmanaged[Cdecl]<byte, void> CSurf_FlushUndo;

    [NativeTypeName("bool (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte> CSurf_GetTouchState;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> CSurf_GoEnd;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> CSurf_GoStart;

    [NativeTypeName("int (*)(bool)")]
    public delegate* unmanaged[Cdecl]<byte, int> CSurf_NumTracks;

    [NativeTypeName("void (*)(int, bool)")]
    public delegate* unmanaged[Cdecl]<int, byte, void> CSurf_OnArrow;

    [NativeTypeName("void (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, void> CSurf_OnFwd;

    [NativeTypeName("bool (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte> CSurf_OnFXChange;

    [NativeTypeName("int (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int> CSurf_OnInputMonitorChange;

    [NativeTypeName("int (*)(MediaTrack *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte, int> CSurf_OnInputMonitorChangeEx;

    [NativeTypeName("bool (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte> CSurf_OnMuteChange;

    [NativeTypeName("bool (*)(MediaTrack *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte, byte> CSurf_OnMuteChangeEx;

    [NativeTypeName("void (*)(const char *, const float *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, float*, void> CSurf_OnOscControlMessage;

    [NativeTypeName("double (*)(MediaTrack *, double, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, double, byte, double> CSurf_OnPanChange;

    [NativeTypeName("double (*)(MediaTrack *, double, bool, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, double, byte, byte, double> CSurf_OnPanChangeEx;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> CSurf_OnPause;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> CSurf_OnPlay;

    [NativeTypeName("void (*)(double)")]
    public delegate* unmanaged[Cdecl]<double, void> CSurf_OnPlayRateChange;

    [NativeTypeName("bool (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte> CSurf_OnRecArmChange;

    [NativeTypeName("bool (*)(MediaTrack *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte, byte> CSurf_OnRecArmChangeEx;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> CSurf_OnRecord;

    [NativeTypeName("double (*)(MediaTrack *, int, double, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, double, byte, double> CSurf_OnRecvPanChange;

    [NativeTypeName("double (*)(MediaTrack *, int, double, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, double, byte, double> CSurf_OnRecvVolumeChange;

    [NativeTypeName("void (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, void> CSurf_OnRew;

    [NativeTypeName("void (*)(int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, void> CSurf_OnRewFwd;

    [NativeTypeName("void (*)(int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, void> CSurf_OnScroll;

    [NativeTypeName("bool (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte> CSurf_OnSelectedChange;

    [NativeTypeName("double (*)(MediaTrack *, int, double, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, double, byte, double> CSurf_OnSendPanChange;

    [NativeTypeName("double (*)(MediaTrack *, int, double, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, double, byte, double> CSurf_OnSendVolumeChange;

    [NativeTypeName("bool (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte> CSurf_OnSoloChange;

    [NativeTypeName("bool (*)(MediaTrack *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte, byte> CSurf_OnSoloChangeEx;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> CSurf_OnStop;

    [NativeTypeName("void (*)(double)")]
    public delegate* unmanaged[Cdecl]<double, void> CSurf_OnTempoChange;

    [NativeTypeName("void (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, void> CSurf_OnTrackSelection;

    [NativeTypeName("double (*)(MediaTrack *, double, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, double, byte, double> CSurf_OnVolumeChange;

    [NativeTypeName("double (*)(MediaTrack *, double, bool, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, double, byte, byte, double> CSurf_OnVolumeChangeEx;

    [NativeTypeName("double (*)(MediaTrack *, double, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, double, byte, double> CSurf_OnWidthChange;

    [NativeTypeName("double (*)(MediaTrack *, double, bool, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, double, byte, byte, double> CSurf_OnWidthChangeEx;

    [NativeTypeName("void (*)(int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, void> CSurf_OnZoom;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> CSurf_ResetAllCachedVolPanStates;

    [NativeTypeName("void (*)(double)")]
    public delegate* unmanaged[Cdecl]<double, void> CSurf_ScrubAmt;

    [NativeTypeName("void (*)(int, IReaperControlSurface *)")]
    public delegate* unmanaged[Cdecl]<int, IReaperControlSurface*, void> CSurf_SetAutoMode;

    [NativeTypeName("void (*)(bool, bool, bool, IReaperControlSurface *)")]
    public delegate* unmanaged[Cdecl]<byte, byte, byte, IReaperControlSurface*, void> CSurf_SetPlayState;

    [NativeTypeName("void (*)(bool, IReaperControlSurface *)")]
    public delegate* unmanaged[Cdecl]<byte, IReaperControlSurface*, void> CSurf_SetRepeatState;

    [NativeTypeName("void (*)(MediaTrack *, bool, IReaperControlSurface *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, byte, IReaperControlSurface*, void> CSurf_SetSurfaceMute;

    [NativeTypeName("void (*)(MediaTrack *, double, IReaperControlSurface *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, double, IReaperControlSurface*, void> CSurf_SetSurfacePan;

    [NativeTypeName("void (*)(MediaTrack *, bool, IReaperControlSurface *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, byte, IReaperControlSurface*, void> CSurf_SetSurfaceRecArm;

    [NativeTypeName("void (*)(MediaTrack *, bool, IReaperControlSurface *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, byte, IReaperControlSurface*, void> CSurf_SetSurfaceSelected;

    [NativeTypeName("void (*)(MediaTrack *, bool, IReaperControlSurface *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, byte, IReaperControlSurface*, void> CSurf_SetSurfaceSolo;

    [NativeTypeName("void (*)(MediaTrack *, double, IReaperControlSurface *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, double, IReaperControlSurface*, void> CSurf_SetSurfaceVolume;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> CSurf_SetTrackListChange;

    [NativeTypeName("MediaTrack *(*)(int, bool)")]
    public delegate* unmanaged[Cdecl]<int, byte, MediaTrack*> CSurf_TrackFromID;

    [NativeTypeName("int (*)(MediaTrack *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, byte, int> CSurf_TrackToID;

    [NativeTypeName("double (*)(double)")]
    public delegate* unmanaged[Cdecl]<double, double> DB2SLIDER;

    [NativeTypeName("bool (*)(KbdSectionInfo *, int, int)")]
    public delegate* unmanaged[Cdecl]<KbdSectionInfo*, int, int, byte> DeleteActionShortcut;

    [NativeTypeName("bool (*)(TrackEnvelope *, int, int)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, int, byte> DeleteEnvelopePointEx;

    [NativeTypeName("bool (*)(TrackEnvelope *, double, double)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, double, double, byte> DeleteEnvelopePointRange;

    [NativeTypeName("bool (*)(TrackEnvelope *, int, double, double)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, double, double, byte> DeleteEnvelopePointRangeEx;

    [NativeTypeName("void (*)(const char *, const char *, bool)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, byte, void> DeleteExtState;

    [NativeTypeName("bool (*)(ReaProject *, int, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte, byte> DeleteProjectMarker;

    [NativeTypeName("bool (*)(ReaProject *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte> DeleteProjectMarkerByIndex;

    [NativeTypeName("bool (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte> DeleteTakeMarker;

    [NativeTypeName("int (*)(MediaItem_Take *, int, const int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int*, int> DeleteTakeStretchMarkers;

    [NativeTypeName("bool (*)(ReaProject *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte> DeleteTempoTimeSigMarker;

    [NativeTypeName("void (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, void> DeleteTrack;

    [NativeTypeName("bool (*)(MediaTrack *, MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, MediaItem*, byte> DeleteTrackMediaItem;

    [NativeTypeName("void (*)(AudioAccessor *)")]
    public delegate* unmanaged[Cdecl]<AudioAccessor*, void> DestroyAudioAccessor;

    [NativeTypeName("void (*)(void *)")]
    public delegate* unmanaged[Cdecl]<void*, void> DestroyLocalOscHandler;

    [NativeTypeName("bool (*)(HWND, KbdSectionInfo *, int, int)")]
    public delegate* unmanaged[Cdecl]<HWND, KbdSectionInfo*, int, int, byte> DoActionShortcutDialog;

    [NativeTypeName("void (*)(const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, void> Dock_UpdateDockID;

    [NativeTypeName("int (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, int> DockGetPosition;

    [NativeTypeName("int (*)(HWND, bool *)")]
    public delegate* unmanaged[Cdecl]<HWND, bool*, int> DockIsChildOfDock;

    [NativeTypeName("void (*)(HWND)")]
    public delegate* unmanaged[Cdecl]<HWND, void> DockWindowActivate;

    [NativeTypeName("void (*)(HWND, const char *, int, bool)")]
    public delegate* unmanaged[Cdecl]<HWND, sbyte*, int, byte, void> DockWindowAdd;

    [NativeTypeName("void (*)(HWND, const char *, const char *, bool)")]
    public delegate* unmanaged[Cdecl]<HWND, sbyte*, sbyte*, byte, void> DockWindowAddEx;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> DockWindowRefresh;

    [NativeTypeName("void (*)(HWND)")]
    public delegate* unmanaged[Cdecl]<HWND, void> DockWindowRefreshForHWND;

    [NativeTypeName("void (*)(HWND)")]
    public delegate* unmanaged[Cdecl]<HWND, void> DockWindowRemove;

    [NativeTypeName("bool (*)(void *, void *)")]
    public delegate* unmanaged[Cdecl]<void*, void*, byte> DuplicateCustomizableMenu;

    [NativeTypeName("bool (*)(ReaProject *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte> EditTempoTimeSigMarker;

    [NativeTypeName("void (*)(RECT *)")]
    public delegate* unmanaged[Cdecl]<RECT*, void> EnsureNotCompletelyOffscreen;

    [NativeTypeName("const char *(*)(const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, sbyte*> EnumerateFiles;

    [NativeTypeName("const char *(*)(const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, sbyte*> EnumerateSubdirectories;

    [NativeTypeName("bool (*)(int, const char **)")]
    public delegate* unmanaged[Cdecl]<int, sbyte**, byte> EnumPitchShiftModes;

    [NativeTypeName("const char *(*)(int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, sbyte*> EnumPitchShiftSubModes;

    [NativeTypeName("int (*)(int, bool *, double *, double *, const char **, int *)")]
    public delegate* unmanaged[Cdecl]<int, bool*, double*, double*, sbyte**, int*, int> EnumProjectMarkers;

    [NativeTypeName("int (*)(ReaProject *, int, bool *, double *, double *, const char **, int *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, bool*, double*, double*, sbyte**, int*, int> EnumProjectMarkers2;

    [NativeTypeName("int (*)(ReaProject *, int, bool *, double *, double *, const char **, int *, int *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, bool*, double*, double*, sbyte**, int*, int*, int> EnumProjectMarkers3;

    [NativeTypeName("ReaProject *(*)(int, char *, int)")]
    public delegate* unmanaged[Cdecl]<int, sbyte*, int, ReaProject*> EnumProjects;

    [NativeTypeName("bool (*)(ReaProject *, const char *, int, char *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, int, sbyte*, int, sbyte*, int, byte> EnumProjExtState;

    [NativeTypeName("MediaTrack *(*)(ReaProject *, int, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, int, MediaTrack*> EnumRegionRenderMatrix;

    [NativeTypeName("bool (*)(int, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<int, int, sbyte*, int, byte> EnumTrackMIDIProgramNames;

    [NativeTypeName("bool (*)(ReaProject *, MediaTrack *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, MediaTrack*, int, sbyte*, int, byte> EnumTrackMIDIProgramNamesEx;

    [NativeTypeName("int (*)(TrackEnvelope *, double, double, int, double *, double *, double *, double *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, double, double, int, double*, double*, double*, double*, int> Envelope_Evaluate;

    [NativeTypeName("void (*)(TrackEnvelope *, double, char *, int)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, double, sbyte*, int, void> Envelope_FormatValue;

    [NativeTypeName("MediaItem_Take *(*)(TrackEnvelope *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int*, int*, MediaItem_Take*> Envelope_GetParentTake;

    [NativeTypeName("MediaTrack *(*)(TrackEnvelope *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int*, int*, MediaTrack*> Envelope_GetParentTrack;

    [NativeTypeName("bool (*)(TrackEnvelope *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, byte> Envelope_SortPoints;

    [NativeTypeName("bool (*)(TrackEnvelope *, int)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, byte> Envelope_SortPointsEx;

    [NativeTypeName("const char *(*)(const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, sbyte*> ExecProcess;

    [NativeTypeName("bool (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, byte> file_exists;

    [NativeTypeName("int (*)(ReaProject *, double)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, int> FindTempoTimeSigMarker;

    [NativeTypeName("void (*)(double, char *, int)")]
    public delegate* unmanaged[Cdecl]<double, sbyte*, int, void> format_timestr;

    [NativeTypeName("void (*)(double, char *, int, double, int)")]
    public delegate* unmanaged[Cdecl]<double, sbyte*, int, double, int, void> format_timestr_len;

    [NativeTypeName("void (*)(double, char *, int, int)")]
    public delegate* unmanaged[Cdecl]<double, sbyte*, int, int, void> format_timestr_pos;

    [NativeTypeName("void (*)(void *)")]
    public delegate* unmanaged[Cdecl]<void*, void> FreeHeapPtr;

    [NativeTypeName("void (*)(GUID *)")]
    public delegate* unmanaged[Cdecl]<GUID*, void> genGuid;

    [NativeTypeName("void *(*)(const char *, int *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int*, void*> get_config_var;

    [NativeTypeName("bool (*)(const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, byte> get_config_var_string;

    [NativeTypeName("const char *(*)()")]
    public delegate* unmanaged[Cdecl]<sbyte*> get_ini_file;

    [NativeTypeName("void *(*)(const char *, int *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int*, void*> get_midi_config_var;

    [NativeTypeName("bool (*)(KbdSectionInfo *, int, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<KbdSectionInfo*, int, int, sbyte*, int, byte> GetActionShortcutDesc;

    [NativeTypeName("MediaItem_Take *(*)(MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, MediaItem_Take*> GetActiveTake;

    [NativeTypeName("int (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int> GetAllProjectPlayStates;

    [NativeTypeName("const char *(*)()")]
    public delegate* unmanaged[Cdecl]<sbyte*> GetAppVersion;

    [NativeTypeName("int (*)(char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, int> GetArmedCommand;

    [NativeTypeName("double (*)(AudioAccessor *)")]
    public delegate* unmanaged[Cdecl]<AudioAccessor*, double> GetAudioAccessorEndTime;

    [NativeTypeName("void (*)(AudioAccessor *, char *)")]
    public delegate* unmanaged[Cdecl]<AudioAccessor*, sbyte*, void> GetAudioAccessorHash;

    [NativeTypeName("int (*)(AudioAccessor *, int, int, double, int, double *)")]
    public delegate* unmanaged[Cdecl]<AudioAccessor*, int, int, double, int, double*, int> GetAudioAccessorSamples;

    [NativeTypeName("double (*)(AudioAccessor *)")]
    public delegate* unmanaged[Cdecl]<AudioAccessor*, double> GetAudioAccessorStartTime;

    [NativeTypeName("bool (*)(const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, byte> GetAudioDeviceInfo;

    [NativeTypeName("INT_PTR (*)(int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, long> GetColorTheme;

    [NativeTypeName("void *(*)(int *)")]
    public delegate* unmanaged[Cdecl]<int*, void*> GetColorThemeStruct;

    [NativeTypeName("int (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int> GetConfigWantsDock;

    [NativeTypeName("HMENU (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, HMENU*> GetContextMenu;

    [NativeTypeName("ReaProject *(*)()")]
    public delegate* unmanaged[Cdecl]<ReaProject*> GetCurrentProjectInLoadSave;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetCursorContext;

    [NativeTypeName("int (*)(bool)")]
    public delegate* unmanaged[Cdecl]<byte, int> GetCursorContext2;

    [NativeTypeName("double (*)()")]
    public delegate* unmanaged[Cdecl]<double> GetCursorPosition;

    [NativeTypeName("double (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double> GetCursorPositionEx;

    [NativeTypeName("int (*)(MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, int> GetDisplayedMediaItemColor;

    [NativeTypeName("int (*)(MediaItem *, MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, MediaItem_Take*, int> GetDisplayedMediaItemColor2;

    [NativeTypeName("double (*)(TrackEnvelope *, const char *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, sbyte*, double> GetEnvelopeInfo_Value;

    [NativeTypeName("bool (*)(TrackEnvelope *, char *, int)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, sbyte*, int, byte> GetEnvelopeName;

    [NativeTypeName("bool (*)(TrackEnvelope *, int, double *, double *, int *, double *, bool *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, double*, double*, int*, double*, bool*, byte> GetEnvelopePoint;

    [NativeTypeName("int (*)(TrackEnvelope *, double)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, double, int> GetEnvelopePointByTime;

    [NativeTypeName("int (*)(TrackEnvelope *, int, double)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, double, int> GetEnvelopePointByTimeEx;

    [NativeTypeName("bool (*)(TrackEnvelope *, int, int, double *, double *, int *, double *, bool *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, int, double*, double*, int*, double*, bool*, byte> GetEnvelopePointEx;

    [NativeTypeName("int (*)(TrackEnvelope *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int> GetEnvelopeScalingMode;

    [NativeTypeName("bool (*)(TrackEnvelope *, char *, int, bool)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, sbyte*, int, byte, byte> GetEnvelopeStateChunk;

    [NativeTypeName("const char *(*)()")]
    public delegate* unmanaged[Cdecl]<sbyte*> GetExePath;

    [NativeTypeName("const char *(*)(const char *, const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, sbyte*> GetExtState;

    [NativeTypeName("int (*)(int *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<int*, int*, int*, int> GetFocusedFX;

    [NativeTypeName("int (*)(int *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<int*, int*, int*, int> GetFocusedFX2;

    [NativeTypeName("int (*)(ReaProject *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, int> GetFreeDiskSpaceForRecordPath;

    [NativeTypeName("TrackEnvelope *(*)(MediaTrack *, int, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, byte, TrackEnvelope*> GetFXEnvelope;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetGlobalAutomationOverride;

    [NativeTypeName("double (*)()")]
    public delegate* unmanaged[Cdecl]<double> GetHZoomLevel;

    [NativeTypeName("void *(*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void*> GetIconThemePointer;

    [NativeTypeName("void *(*)(const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, void*> GetIconThemePointerForDPI;

    [NativeTypeName("void *(*)(int *)")]
    public delegate* unmanaged[Cdecl]<int*, void*> GetIconThemeStruct;

    [NativeTypeName("const char *(*)(int)")]
    public delegate* unmanaged[Cdecl]<int, sbyte*> GetInputChannelName;

    [NativeTypeName("void (*)(int *, int *)")]
    public delegate* unmanaged[Cdecl]<int*, int*, void> GetInputOutputLatency;

    [NativeTypeName("double (*)(PCM_source **, int *)")]
    public delegate* unmanaged[Cdecl]<PCM_source**, int*, double> GetItemEditingTime2;

    [NativeTypeName("MediaItem *(*)(int, int, bool, MediaItem_Take **)")]
    public delegate* unmanaged[Cdecl]<int, int, byte, MediaItem_Take**, MediaItem*> GetItemFromPoint;

    [NativeTypeName("ReaProject *(*)(MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, ReaProject*> GetItemProjectContext;

    [NativeTypeName("bool (*)(MediaItem *, char *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, sbyte*, int, byte, byte> GetItemStateChunk;

    [NativeTypeName("const char *(*)()")]
    public delegate* unmanaged[Cdecl]<sbyte*> GetLastColorThemeFile;

    [NativeTypeName("void (*)(ReaProject *, double, int *, int *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, int*, int*, void> GetLastMarkerAndCurRegion;

    [NativeTypeName("bool (*)(int *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<int*, int*, int*, byte> GetLastTouchedFX;

    [NativeTypeName("MediaTrack *(*)()")]
    public delegate* unmanaged[Cdecl]<MediaTrack*> GetLastTouchedTrack;

    [NativeTypeName("HWND (*)()")]
    public delegate* unmanaged[Cdecl]<HWND> GetMainHwnd;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetMasterMuteSoloFlags;

    [NativeTypeName("MediaTrack *(*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, MediaTrack*> GetMasterTrack;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetMasterTrackVisibility;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetMaxMidiInputs;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetMaxMidiOutputs;

    [NativeTypeName("int (*)(PCM_source *, const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, sbyte*, sbyte*, int, int> GetMediaFileMetadata;

    [NativeTypeName("MediaItem *(*)(ReaProject *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, MediaItem*> GetMediaItem;

    [NativeTypeName("MediaTrack *(*)(MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, MediaTrack*> GetMediaItem_Track;

    [NativeTypeName("double (*)(MediaItem *, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, sbyte*, double> GetMediaItemInfo_Value;

    [NativeTypeName("int (*)(MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, int> GetMediaItemNumTakes;

    [NativeTypeName("MediaItem_Take *(*)(MediaItem *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, int, MediaItem_Take*> GetMediaItemTake;

    [NativeTypeName("MediaItem *(*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, MediaItem*> GetMediaItemTake_Item;

    [NativeTypeName("int (*)(MediaItem_Take *, double, double, int, int, int, double *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, double, double, int, int, int, double*, int> GetMediaItemTake_Peaks;

    [NativeTypeName("PCM_source *(*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, PCM_source*> GetMediaItemTake_Source;

    [NativeTypeName("MediaTrack *(*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, MediaTrack*> GetMediaItemTake_Track;

    [NativeTypeName("MediaItem_Take *(*)(ReaProject *, const GUID *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, GUID*, MediaItem_Take*> GetMediaItemTakeByGUID;

    [NativeTypeName("double (*)(MediaItem_Take *, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, sbyte*, double> GetMediaItemTakeInfo_Value;

    [NativeTypeName("MediaTrack *(*)(MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, MediaTrack*> GetMediaItemTrack;

    [NativeTypeName("void (*)(PCM_source *, char *, int)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, sbyte*, int, void> GetMediaSourceFileName;

    [NativeTypeName("double (*)(PCM_source *, bool *)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, bool*, double> GetMediaSourceLength;

    [NativeTypeName("int (*)(PCM_source *)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, int> GetMediaSourceNumChannels;

    [NativeTypeName("PCM_source *(*)(PCM_source *)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, PCM_source*> GetMediaSourceParent;

    [NativeTypeName("int (*)(PCM_source *)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, int> GetMediaSourceSampleRate;

    [NativeTypeName("void (*)(PCM_source *, char *, int)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, sbyte*, int, void> GetMediaSourceType;

    [NativeTypeName("double (*)(MediaTrack *, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, double> GetMediaTrackInfo_Value;

    [NativeTypeName("bool (*)(int, char *, int)")]
    public delegate* unmanaged[Cdecl]<int, sbyte*, int, byte> GetMIDIInputName;

    [NativeTypeName("bool (*)(int, char *, int)")]
    public delegate* unmanaged[Cdecl]<int, sbyte*, int, byte> GetMIDIOutputName;

    [NativeTypeName("MediaTrack *(*)()")]
    public delegate* unmanaged[Cdecl]<MediaTrack*> GetMixerScroll;

    [NativeTypeName("void (*)(const char *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, sbyte*, int, void> GetMouseModifier;

    [NativeTypeName("void (*)(int *, int *)")]
    public delegate* unmanaged[Cdecl]<int*, int*, void> GetMousePosition;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetNumAudioInputs;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetNumAudioOutputs;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetNumMIDIInputs;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetNumMIDIOutputs;

    [NativeTypeName("int (*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int> GetNumTakeMarkers;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetNumTracks;

    [NativeTypeName("const char *(*)()")]
    public delegate* unmanaged[Cdecl]<sbyte*> GetOS;

    [NativeTypeName("const char *(*)(int)")]
    public delegate* unmanaged[Cdecl]<int, sbyte*> GetOutputChannelName;

    [NativeTypeName("double (*)()")]
    public delegate* unmanaged[Cdecl]<double> GetOutputLatency;

    [NativeTypeName("MediaTrack *(*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, MediaTrack*> GetParentTrack;

    [NativeTypeName("void (*)(const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, void> GetPeakFileName;

    [NativeTypeName("void (*)(const char *, char *, int, bool)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, byte, void> GetPeakFileNameEx;

    [NativeTypeName("void (*)(const char *, char *, int, bool, const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, byte, sbyte*, void> GetPeakFileNameEx2;

    [NativeTypeName("void *(*)(PCM_source_peaktransfer_t *, double, int, int, LICE_IBitmap *)")]
    public delegate* unmanaged[Cdecl]<PCM_source_peaktransfer_t*, double, int, int, LICE_IBitmap*, void*> GetPeaksBitmap;

    [NativeTypeName("double (*)()")]
    public delegate* unmanaged[Cdecl]<double> GetPlayPosition;

    [NativeTypeName("double (*)()")]
    public delegate* unmanaged[Cdecl]<double> GetPlayPosition2;

    [NativeTypeName("double (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double> GetPlayPosition2Ex;

    [NativeTypeName("double (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double> GetPlayPositionEx;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> GetPlayState;

    [NativeTypeName("int (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int> GetPlayStateEx;

    [NativeTypeName("void (*)(int *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<int*, int*, int*, void> GetPreferredDiskReadMode;

    [NativeTypeName("void (*)(int *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<int*, int*, int*, void> GetPreferredDiskReadModePeak;

    [NativeTypeName("void (*)(int *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<int*, int*, int*, void> GetPreferredDiskWriteMode;

    [NativeTypeName("double (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double> GetProjectLength;

    [NativeTypeName("void (*)(ReaProject *, char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, int, void> GetProjectName;

    [NativeTypeName("void (*)(char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, void> GetProjectPath;

    [NativeTypeName("void (*)(ReaProject *, char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, int, void> GetProjectPathEx;

    [NativeTypeName("int (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int> GetProjectStateChangeCount;

    [NativeTypeName("double (*)(ReaProject *, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte, double> GetProjectTimeOffset;

    [NativeTypeName("void (*)(double *, double *)")]
    public delegate* unmanaged[Cdecl]<double*, double*, void> GetProjectTimeSignature;

    [NativeTypeName("void (*)(ReaProject *, double *, double *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double*, double*, void> GetProjectTimeSignature2;

    [NativeTypeName("int (*)(ReaProject *, const char *, const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, sbyte*, sbyte*, int, int> GetProjExtState;

    [NativeTypeName("const char *(*)()")]
    public delegate* unmanaged[Cdecl]<sbyte*> GetResourcePath;

    [NativeTypeName("TrackEnvelope *(*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, TrackEnvelope*> GetSelectedEnvelope;

    [NativeTypeName("MediaItem *(*)(ReaProject *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, MediaItem*> GetSelectedMediaItem;

    [NativeTypeName("MediaTrack *(*)(ReaProject *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, MediaTrack*> GetSelectedTrack;

    [NativeTypeName("MediaTrack *(*)(ReaProject *, int, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte, MediaTrack*> GetSelectedTrack2;

    [NativeTypeName("TrackEnvelope *(*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, TrackEnvelope*> GetSelectedTrackEnvelope;

    [NativeTypeName("void (*)(ReaProject *, bool, int, int, double *, double *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte, int, int, double*, double*, void> GetSet_ArrangeView2;

    [NativeTypeName("void (*)(bool, bool, double *, double *, bool)")]
    public delegate* unmanaged[Cdecl]<byte, byte, double*, double*, byte, void> GetSet_LoopTimeRange;

    [NativeTypeName("void (*)(ReaProject *, bool, bool, double *, double *, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte, byte, double*, double*, byte, void> GetSet_LoopTimeRange2;

    [NativeTypeName("double (*)(TrackEnvelope *, int, const char *, double, bool)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, sbyte*, double, byte, double> GetSetAutomationItemInfo;

    [NativeTypeName("bool (*)(TrackEnvelope *, int, const char *, char *, bool)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, sbyte*, sbyte*, byte, byte> GetSetAutomationItemInfo_String;

    [NativeTypeName("bool (*)(TrackEnvelope *, const char *, char *, bool)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, sbyte*, sbyte*, byte, byte> GetSetEnvelopeInfo_String;

    [NativeTypeName("bool (*)(TrackEnvelope *, char *, int)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, sbyte*, int, byte> GetSetEnvelopeState;

    [NativeTypeName("bool (*)(TrackEnvelope *, char *, int, bool)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, sbyte*, int, byte, byte> GetSetEnvelopeState2;

    [NativeTypeName("bool (*)(MediaItem *, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, sbyte*, int, byte> GetSetItemState;

    [NativeTypeName("bool (*)(MediaItem *, char *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, sbyte*, int, byte, byte> GetSetItemState2;

    [NativeTypeName("void *(*)(MediaItem *, const char *, void *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, sbyte*, void*, void*> GetSetMediaItemInfo;

    [NativeTypeName("bool (*)(MediaItem *, const char *, char *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, sbyte*, sbyte*, byte, byte> GetSetMediaItemInfo_String;

    [NativeTypeName("void *(*)(MediaItem_Take *, const char *, void *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, sbyte*, void*, void*> GetSetMediaItemTakeInfo;

    [NativeTypeName("bool (*)(MediaItem_Take *, const char *, char *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, sbyte*, sbyte*, byte, byte> GetSetMediaItemTakeInfo_String;

    [NativeTypeName("void *(*)(MediaTrack *, const char *, void *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, void*, void*> GetSetMediaTrackInfo;

    [NativeTypeName("bool (*)(MediaTrack *, const char *, char *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, sbyte*, byte, byte> GetSetMediaTrackInfo_String;

    [NativeTypeName("char *(*)(void *, const char *)")]
    public delegate* unmanaged[Cdecl]<void*, sbyte*, sbyte*> GetSetObjectState;

    [NativeTypeName("char *(*)(void *, const char *, bool)")]
    public delegate* unmanaged[Cdecl]<void*, sbyte*, byte, sbyte*> GetSetObjectState2;

    [NativeTypeName("void (*)(ReaProject *, bool, char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte, sbyte*, int, void> GetSetProjectAuthor;

    [NativeTypeName("int (*)(ReaProject *, bool, double *, int *, double *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte, double*, int*, double*, int> GetSetProjectGrid;

    [NativeTypeName("double (*)(ReaProject *, const char *, double, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, double, byte, double> GetSetProjectInfo;

    [NativeTypeName("bool (*)(ReaProject *, const char *, char *, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, sbyte*, byte, byte> GetSetProjectInfo_String;

    [NativeTypeName("void (*)(ReaProject *, bool, char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte, sbyte*, int, void> GetSetProjectNotes;

    [NativeTypeName("int (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, int> GetSetRepeat;

    [NativeTypeName("int (*)(ReaProject *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, int> GetSetRepeatEx;

    [NativeTypeName("unsigned int (*)(MediaTrack *, const char *, unsigned int, unsigned int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, uint, uint, uint> GetSetTrackGroupMembership;

    [NativeTypeName("unsigned int (*)(MediaTrack *, const char *, unsigned int, unsigned int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, uint, uint, uint> GetSetTrackGroupMembershipHigh;

    [NativeTypeName("const char *(*)(ReaProject *, MediaTrack *, int, const char *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, MediaTrack*, int, sbyte*, sbyte*> GetSetTrackMIDISupportFile;

    [NativeTypeName("void *(*)(MediaTrack *, int, int, const char *, void *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, sbyte*, void*, void*> GetSetTrackSendInfo;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, const char *, char *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, sbyte*, sbyte*, byte, byte> GetSetTrackSendInfo_String;

    [NativeTypeName("bool (*)(MediaTrack *, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, int, byte> GetSetTrackState;

    [NativeTypeName("bool (*)(MediaTrack *, char *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, int, byte, byte> GetSetTrackState2;

    [NativeTypeName("ReaProject *(*)(PCM_source *)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, ReaProject*> GetSubProjectFromSource;

    [NativeTypeName("MediaItem_Take *(*)(MediaItem *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, int, MediaItem_Take*> GetTake;

    [NativeTypeName("TrackEnvelope *(*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, TrackEnvelope*> GetTakeEnvelope;

    [NativeTypeName("TrackEnvelope *(*)(MediaItem_Take *, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, sbyte*, TrackEnvelope*> GetTakeEnvelopeByName;

    [NativeTypeName("double (*)(MediaItem_Take *, int, char *, int, int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, sbyte*, int, int*, double> GetTakeMarker;

    [NativeTypeName("const char *(*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, sbyte*> GetTakeName;

    [NativeTypeName("int (*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int> GetTakeNumStretchMarkers;

    [NativeTypeName("int (*)(MediaItem_Take *, int, double *, double *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, double*, double*, int> GetTakeStretchMarker;

    [NativeTypeName("double (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, double> GetTakeStretchMarkerSlope;

    [NativeTypeName("bool (*)(ReaProject *, MediaTrack *, int, int *, int *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, MediaTrack*, int, int*, int*, byte> GetTCPFXParm;

    [NativeTypeName("bool (*)(PCM_source *, double, double, double, double *, double *)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, double, double, double, double*, double*, byte> GetTempoMatchPlayRate;

    [NativeTypeName("bool (*)(ReaProject *, int, double *, int *, double *, double *, int *, int *, bool *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, double*, int*, double*, double*, int*, int*, bool*, byte> GetTempoTimeSigMarker;

    [NativeTypeName("int (*)(const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, int> GetThemeColor;

    [NativeTypeName("int (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, int> GetToggleCommandState;

    [NativeTypeName("int (*)(KbdSectionInfo *, int)")]
    public delegate* unmanaged[Cdecl]<KbdSectionInfo*, int, int> GetToggleCommandState2;

    [NativeTypeName("int (*)(int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, int> GetToggleCommandStateEx;

    [NativeTypeName("int (*)(KbdSectionInfo *, int)")]
    public delegate* unmanaged[Cdecl]<KbdSectionInfo*, int, int> GetToggleCommandStateThroughHooks;

    [NativeTypeName("HWND (*)()")]
    public delegate* unmanaged[Cdecl]<HWND> GetTooltipWindow;

    [NativeTypeName("MediaTrack *(*)(ReaProject *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, MediaTrack*> GetTrack;

    [NativeTypeName("int (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int> GetTrackAutomationMode;

    [NativeTypeName("int (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int> GetTrackColor;

    [NativeTypeName("int (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int> GetTrackDepth;

    [NativeTypeName("TrackEnvelope *(*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, TrackEnvelope*> GetTrackEnvelope;

    [NativeTypeName("TrackEnvelope *(*)(MediaTrack *, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, TrackEnvelope*> GetTrackEnvelopeByChunkName;

    [NativeTypeName("TrackEnvelope *(*)(MediaTrack *, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, TrackEnvelope*> GetTrackEnvelopeByName;

    [NativeTypeName("MediaTrack *(*)(int, int, int *)")]
    public delegate* unmanaged[Cdecl]<int, int, int*, MediaTrack*> GetTrackFromPoint;

    [NativeTypeName("GUID *(*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, GUID*> GetTrackGUID;

    [NativeTypeName("const char *(*)(INT_PTR, int *)")]
    public delegate* unmanaged[Cdecl]<long, int*, sbyte*> GetTrackInfo;

    [NativeTypeName("MediaItem *(*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, MediaItem*> GetTrackMediaItem;

    [NativeTypeName("bool (*)(MediaTrack *, int, char *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, sbyte*, int*, byte> GetTrackMIDILyrics;

    [NativeTypeName("const char *(*)(int, int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, int, sbyte*> GetTrackMIDINoteName;

    [NativeTypeName("const char *(*)(ReaProject *, MediaTrack *, int, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, MediaTrack*, int, int, sbyte*> GetTrackMIDINoteNameEx;

    [NativeTypeName("void (*)(ReaProject *, MediaTrack *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, MediaTrack*, int*, int*, void> GetTrackMIDINoteRange;

    [NativeTypeName("bool (*)(MediaTrack *, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, int, byte> GetTrackName;

    [NativeTypeName("int (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int> GetTrackNumMediaItems;

    [NativeTypeName("int (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int> GetTrackNumSends;

    [NativeTypeName("bool (*)(MediaTrack *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, sbyte*, int, byte> GetTrackReceiveName;

    [NativeTypeName("bool (*)(MediaTrack *, int, bool *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, bool*, byte> GetTrackReceiveUIMute;

    [NativeTypeName("bool (*)(MediaTrack *, int, double *, double *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, double*, double*, byte> GetTrackReceiveUIVolPan;

    [NativeTypeName("double (*)(MediaTrack *, int, int, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, sbyte*, double> GetTrackSendInfo_Value;

    [NativeTypeName("bool (*)(MediaTrack *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, sbyte*, int, byte> GetTrackSendName;

    [NativeTypeName("bool (*)(MediaTrack *, int, bool *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, bool*, byte> GetTrackSendUIMute;

    [NativeTypeName("bool (*)(MediaTrack *, int, double *, double *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, double*, double*, byte> GetTrackSendUIVolPan;

    [NativeTypeName("const char *(*)(MediaTrack *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int*, sbyte*> GetTrackState;

    [NativeTypeName("bool (*)(MediaTrack *, char *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, int, byte, byte> GetTrackStateChunk;

    [NativeTypeName("bool (*)(MediaTrack *, bool *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, bool*, byte> GetTrackUIMute;

    [NativeTypeName("bool (*)(MediaTrack *, double *, double *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, double*, double*, int*, byte> GetTrackUIPan;

    [NativeTypeName("bool (*)(MediaTrack *, double *, double *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, double*, double*, byte> GetTrackUIVolPan;

    [NativeTypeName("void (*)(unsigned int *, unsigned int *, unsigned int *)")]
    public delegate* unmanaged[Cdecl]<uint*, uint*, uint*, void> GetUnderrunTime;

    [NativeTypeName("bool (*)(char *, const char *, const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, sbyte*, byte> GetUserFileNameForRead;

    [NativeTypeName("bool (*)(const char *, int, const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, sbyte*, sbyte*, int, byte> GetUserInputs;

    [NativeTypeName("void (*)(ReaProject *, int, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte, void> GoToMarker;

    [NativeTypeName("void (*)(ReaProject *, int, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte, void> GoToRegion;

    [NativeTypeName("int (*)(HWND, int *)")]
    public delegate* unmanaged[Cdecl]<HWND, int*, int> GR_SelectColor;

    [NativeTypeName("int (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, int> GSC_mainwnd;

    [NativeTypeName("void (*)(const GUID *, char *)")]
    public delegate* unmanaged[Cdecl]<GUID*, sbyte*, void> guidToString;

    [NativeTypeName("bool (*)(const char *, const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, byte> HasExtState;

    [NativeTypeName("const char *(*)(int)")]
    public delegate* unmanaged[Cdecl]<int, sbyte*> HasTrackMIDIPrograms;

    [NativeTypeName("const char *(*)(ReaProject *, MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, MediaTrack*, sbyte*> HasTrackMIDIProgramsEx;

    [NativeTypeName("void (*)(const char *, bool)")]
    public delegate* unmanaged[Cdecl]<sbyte*, byte, void> Help_Set;

    [NativeTypeName("void (*)(PCM_source *, PCM_source_peaktransfer_t *)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, PCM_source_peaktransfer_t*, void> HiresPeaksFromSource;

    [NativeTypeName("void (*)(const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, void> image_resolve_fn;

    [NativeTypeName("int (*)(TrackEnvelope *, int, double, double)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, double, double, int> InsertAutomationItem;

    [NativeTypeName("bool (*)(TrackEnvelope *, double, double, int, double, bool, bool *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, double, double, int, double, byte, bool*, byte> InsertEnvelopePoint;

    [NativeTypeName("bool (*)(TrackEnvelope *, int, double, double, int, double, bool, bool *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, double, double, int, double, byte, bool*, byte> InsertEnvelopePointEx;

    [NativeTypeName("int (*)(const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, int> InsertMedia;

    [NativeTypeName("int (*)(const char *, int, double, double, double)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, double, double, double, int> InsertMediaSection;

    [NativeTypeName("void (*)(int, bool)")]
    public delegate* unmanaged[Cdecl]<int, byte, void> InsertTrackAtIndex;

    [NativeTypeName("int (*)()")]
    public delegate* unmanaged[Cdecl]<int> IsInRealTimeAudio;

    [NativeTypeName("bool (*)(MediaItem *, MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, MediaItem_Take*, byte> IsItemTakeActiveForPlayback;

    [NativeTypeName("bool (*)(const char *, bool)")]
    public delegate* unmanaged[Cdecl]<sbyte*, byte, byte> IsMediaExtension;

    [NativeTypeName("bool (*)(MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, byte> IsMediaItemSelected;

    [NativeTypeName("int (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int> IsProjectDirty;

    [NativeTypeName("bool (*)()")]
    public delegate* unmanaged[Cdecl]<byte> IsREAPER;

    [NativeTypeName("bool (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, byte> IsTrackSelected;

    [NativeTypeName("bool (*)(MediaTrack *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, byte, byte> IsTrackVisible;

    [NativeTypeName("joystick_device *(*)(const GUID *)")]
    public delegate* unmanaged[Cdecl]<GUID*, joystick_device*> joystick_create;

    [NativeTypeName("void (*)(joystick_device *)")]
    public delegate* unmanaged[Cdecl]<joystick_device*, void> joystick_destroy;

    [NativeTypeName("const char *(*)(int, const char **)")]
    public delegate* unmanaged[Cdecl]<int, sbyte**, sbyte*> joystick_enum;

    [NativeTypeName("double (*)(joystick_device *, int)")]
    public delegate* unmanaged[Cdecl]<joystick_device*, int, double> joystick_getaxis;

    [NativeTypeName("unsigned int (*)(joystick_device *)")]
    public delegate* unmanaged[Cdecl]<joystick_device*, uint> joystick_getbuttonmask;

    [NativeTypeName("int (*)(joystick_device *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<joystick_device*, int*, int*, int> joystick_getinfo;

    [NativeTypeName("double (*)(joystick_device *, int)")]
    public delegate* unmanaged[Cdecl]<joystick_device*, int, double> joystick_getpov;

    [NativeTypeName("bool (*)(joystick_device *)")]
    public delegate* unmanaged[Cdecl]<joystick_device*, byte> joystick_update;

    [NativeTypeName("int (*)(KbdSectionInfo *, int, const char **)")]
    public delegate* unmanaged[Cdecl]<KbdSectionInfo*, int, sbyte**, int> kbd_enumerateActions;

    [NativeTypeName("void (*)(ACCEL *, char *)")]
    public delegate* unmanaged[Cdecl]<ACCEL*, sbyte*, void> kbd_formatKeyName;

    [NativeTypeName("void (*)(int, char *, KbdSectionInfo *)")]
    public delegate* unmanaged[Cdecl]<int, sbyte*, KbdSectionInfo*, void> kbd_getCommandName;

    [NativeTypeName("const char *(*)(DWORD, KbdSectionInfo *)")]
    public delegate* unmanaged[Cdecl]<uint, KbdSectionInfo*, sbyte*> kbd_getTextFromCmd;

    [NativeTypeName("int (*)(int, int, int, int, HWND, ReaProject *)")]
    public delegate* unmanaged[Cdecl]<int, int, int, int, HWND, ReaProject*, int> KBD_OnMainActionEx;

    [NativeTypeName("void (*)(MIDI_event_t *, int)")]
    public delegate* unmanaged[Cdecl]<MIDI_event_t*, int, void> kbd_OnMidiEvent;

    [NativeTypeName("void (*)(MIDI_eventlist *, int)")]
    public delegate* unmanaged[Cdecl]<MIDI_eventlist*, int, void> kbd_OnMidiList;

    [NativeTypeName("void (*)(HMENU, KbdSectionInfo *)")]
    public delegate* unmanaged[Cdecl]<HMENU*, KbdSectionInfo*, void> kbd_ProcessActionsMenu;

    [NativeTypeName("bool (*)(MIDI_event_t *, KbdSectionInfo *, HWND)")]
    public delegate* unmanaged[Cdecl]<MIDI_event_t*, KbdSectionInfo*, HWND, byte> kbd_processMidiEventActionEx;

    [NativeTypeName("void (*)(HMENU, KbdSectionInfo *)")]
    public delegate* unmanaged[Cdecl]<HMENU*, KbdSectionInfo*, void> kbd_reprocessMenu;

    [NativeTypeName("bool (*)(KbdSectionInfo *, int *, int *, int *, int *, HWND)")]
    public delegate* unmanaged[Cdecl]<KbdSectionInfo*, int*, int*, int*, int*, HWND, byte> kbd_RunCommandThroughHooks;

    [NativeTypeName("int (*)(HWND, MSG *, KbdSectionInfo *)")]
    public delegate* unmanaged[Cdecl]<HWND, MSG*, KbdSectionInfo*, int> kbd_translateAccelerator;

    [NativeTypeName("bool (*)(void *, unsigned char *)")]
    public delegate* unmanaged[Cdecl]<void*, byte*, byte> kbd_translateMouse;

    [NativeTypeName("void (*)(LICE_IBitmap *)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, void> LICE__Destroy;

    [NativeTypeName("void (*)(LICE_IFont *)")]
    public delegate* unmanaged[Cdecl]<LICE_IFont*, void> LICE__DestroyFont;

    [NativeTypeName("int (*)(LICE_IFont *, LICE_IBitmap *, const char *, int, RECT *, UINT)")]
    public delegate* unmanaged[Cdecl]<LICE_IFont*, LICE_IBitmap*, sbyte*, int, RECT*, uint, int> LICE__DrawText;

    [NativeTypeName("void *(*)(LICE_IBitmap *)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, void*> LICE__GetBits;

    [NativeTypeName("HDC (*)(LICE_IBitmap *)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, HDC*> LICE__GetDC;

    [NativeTypeName("int (*)(LICE_IBitmap *)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int> LICE__GetHeight;

    [NativeTypeName("int (*)(LICE_IBitmap *)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int> LICE__GetRowSpan;

    [NativeTypeName("int (*)(LICE_IBitmap *)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int> LICE__GetWidth;

    [NativeTypeName("bool (*)(LICE_IBitmap *)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, byte> LICE__IsFlipped;

    [NativeTypeName("bool (*)(LICE_IBitmap *, int, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, byte> LICE__resize;

    [NativeTypeName("LICE_pixel (*)(LICE_IFont *, LICE_pixel)")]
    public delegate* unmanaged[Cdecl]<LICE_IFont*, uint, uint> LICE__SetBkColor;

    [NativeTypeName("void (*)(LICE_IFont *, HFONT, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IFont*, HFONT*, int, void> LICE__SetFromHFont;

    [NativeTypeName("LICE_pixel (*)(LICE_IFont *, LICE_pixel)")]
    public delegate* unmanaged[Cdecl]<LICE_IFont*, uint, uint> LICE__SetTextColor;

    [NativeTypeName("void (*)(LICE_IFont *, int, float)")]
    public delegate* unmanaged[Cdecl]<LICE_IFont*, int, float, void> LICE__SetTextCombineMode;

    [NativeTypeName("void (*)(LICE_IBitmap *, float, float, float, float, float, LICE_pixel, float, int, bool)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, float, float, float, float, float, uint, float, int, byte, void> LICE_Arc;

    [NativeTypeName("void (*)(LICE_IBitmap *, LICE_IBitmap *, int, int, int, int, int, int, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, LICE_IBitmap*, int, int, int, int, int, int, float, int, void> LICE_Blit;

    [NativeTypeName("void (*)(LICE_IBitmap *, LICE_IBitmap *, int, int, int, int, int, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, LICE_IBitmap*, int, int, int, int, int, int, void> LICE_Blur;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, int, int, LICE_pixel, LICE_pixel, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, int, int, uint, uint, float, int, void> LICE_BorderedRect;

    [NativeTypeName("void (*)(LICE_IBitmap *, float, float, float, LICE_pixel, float, int, bool)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, float, float, float, uint, float, int, byte, void> LICE_Circle;

    [NativeTypeName("void (*)(LICE_IBitmap *, LICE_pixel)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, uint, void> LICE_Clear;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, int, int, LICE_pixel, LICE_pixel)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, int, int, uint, uint, void> LICE_ClearRect;

    [NativeTypeName("bool (*)(int *, int *, int *, int *, int, int, int, int)")]
    public delegate* unmanaged[Cdecl]<int*, int*, int*, int*, int, int, int, int, byte> LICE_ClipLine;

    [NativeTypeName("void (*)(LICE_IBitmap *, LICE_IBitmap *)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, LICE_IBitmap*, void> LICE_Copy;

    [NativeTypeName("LICE_IBitmap *(*)(int, int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, int, LICE_IBitmap*> LICE_CreateBitmap;

    [NativeTypeName("LICE_IFont *(*)()")]
    public delegate* unmanaged[Cdecl]<LICE_IFont*> LICE_CreateFont;

    [NativeTypeName("void (*)(LICE_IBitmap *, double, double, double, double, double, double, double, double, LICE_pixel, float, int, bool, double)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, double, double, double, double, double, double, double, double, uint, float, int, byte, double, void> LICE_DrawCBezier;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, char, LICE_pixel, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, sbyte, uint, float, int, void> LICE_DrawChar;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, LICE_pixel, LICE_pixel_chan *, int, int, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, uint, byte*, int, int, float, int, void> LICE_DrawGlyph;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, int, int, LICE_pixel, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, int, int, uint, float, int, void> LICE_DrawRect;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, const char *, LICE_pixel, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, sbyte*, uint, float, int, void> LICE_DrawText;

    [NativeTypeName("void (*)(LICE_IBitmap *, double, double, double, double, double, double, double, double, int, LICE_pixel, float, int, bool, double)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, double, double, double, double, double, double, double, double, int, uint, float, int, byte, double, void> LICE_FillCBezier;

    [NativeTypeName("void (*)(LICE_IBitmap *, float, float, float, LICE_pixel, float, int, bool)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, float, float, float, uint, float, int, byte, void> LICE_FillCircle;

    [NativeTypeName("void (*)(LICE_IBitmap *, int *, int *, int, LICE_pixel, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int*, int*, int, uint, float, int, void> LICE_FillConvexPolygon;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, int, int, LICE_pixel, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, int, int, uint, float, int, void> LICE_FillRect;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, int, int, int, int, LICE_pixel, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, int, int, int, int, uint, float, int, void> LICE_FillTrapezoid;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, int, int, int, int, LICE_pixel, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, int, int, int, int, uint, float, int, void> LICE_FillTriangle;

    [NativeTypeName("LICE_pixel (*)(LICE_IBitmap *, int, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, uint> LICE_GetPixel;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, int, int, float, float, float, float, float, float, float, float, float, float, float, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, int, int, float, float, float, float, float, float, float, float, float, float, float, float, int, void> LICE_GradRect;

    [NativeTypeName("void (*)(LICE_IBitmap *, float, float, float, float, LICE_pixel, float, int, bool)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, float, float, float, float, uint, float, int, byte, void> LICE_Line;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, int, int, LICE_pixel, float, int, bool)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, int, int, uint, float, int, byte, void> LICE_LineInt;

    [NativeTypeName("LICE_IBitmap *(*)(const char *, LICE_IBitmap *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, LICE_IBitmap*, LICE_IBitmap*> LICE_LoadPNG;

    [NativeTypeName("LICE_IBitmap *(*)(HINSTANCE, const char *, LICE_IBitmap *)")]
    public delegate* unmanaged[Cdecl]<HINSTANCE*, sbyte*, LICE_IBitmap*, LICE_IBitmap*> LICE_LoadPNGFromResource;

    [NativeTypeName("void (*)(const char *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int*, int*, void> LICE_MeasureText;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, int, int, float, float, float, float, float, float, float, float)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, int, int, float, float, float, float, float, float, float, float, void> LICE_MultiplyAddRect;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, LICE_pixel, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, uint, float, int, void> LICE_PutPixel;

    [NativeTypeName("void (*)(LICE_IBitmap *, LICE_IBitmap *, int, int, int, int, float, float, float, float, float, bool, float, int, float, float)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, LICE_IBitmap*, int, int, int, int, float, float, float, float, float, byte, float, int, float, float, void> LICE_RotatedBlit;

    [NativeTypeName("void (*)(LICE_IBitmap *, float, float, float, float, int, LICE_pixel, float, int, bool)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, float, float, float, float, int, uint, float, int, byte, void> LICE_RoundRect;

    [NativeTypeName("void (*)(LICE_IBitmap *, LICE_IBitmap *, int, int, int, int, float, float, float, float, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, LICE_IBitmap*, int, int, int, int, float, float, float, float, float, int, void> LICE_ScaledBlit;

    [NativeTypeName("void (*)(LICE_IBitmap *, int, int, LICE_pixel, LICE_pixel, LICE_pixel)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, int, int, uint, uint, uint, void> LICE_SimpleFill;

    [NativeTypeName("const char *(*)(const char *, const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, sbyte*> LocalizeString;

    [NativeTypeName("bool (*)(ReaProject *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte> Loop_OnArrow;

    [NativeTypeName("void (*)(int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, void> Main_OnCommand;

    [NativeTypeName("void (*)(int, int, ReaProject *)")]
    public delegate* unmanaged[Cdecl]<int, int, ReaProject*, void> Main_OnCommandEx;

    [NativeTypeName("void (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void> Main_openProject;

    [NativeTypeName("void (*)(ReaProject *, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte, void> Main_SaveProject;

    [NativeTypeName("void (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, void> Main_UpdateLoopInfo;

    [NativeTypeName("void (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, void> MarkProjectDirty;

    [NativeTypeName("void (*)(MediaTrack *, MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, MediaItem*, void> MarkTrackItemsDirty;

    [NativeTypeName("double (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double> Master_GetPlayRate;

    [NativeTypeName("double (*)(double, ReaProject *)")]
    public delegate* unmanaged[Cdecl]<double, ReaProject*, double> Master_GetPlayRateAtTime;

    [NativeTypeName("double (*)()")]
    public delegate* unmanaged[Cdecl]<double> Master_GetTempo;

    [NativeTypeName("double (*)(double, bool)")]
    public delegate* unmanaged[Cdecl]<double, byte, double> Master_NormalizePlayRate;

    [NativeTypeName("double (*)(double, bool)")]
    public delegate* unmanaged[Cdecl]<double, byte, double> Master_NormalizeTempo;

    [NativeTypeName("int (*)(const char *, const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, int> MB;

    [NativeTypeName("int (*)(MediaItem *, MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, MediaTrack*, int> MediaItemDescendsFromTrack;

    [NativeTypeName("int (*)(MediaItem_Take *, int *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int*, int*, int*, int> MIDI_CountEvts;

    [NativeTypeName("bool (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte> MIDI_DeleteCC;

    [NativeTypeName("bool (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte> MIDI_DeleteEvt;

    [NativeTypeName("bool (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte> MIDI_DeleteNote;

    [NativeTypeName("bool (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte> MIDI_DeleteTextSysexEvt;

    [NativeTypeName("void (*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, void> MIDI_DisableSort;

    [NativeTypeName("int (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int> MIDI_EnumSelCC;

    [NativeTypeName("int (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int> MIDI_EnumSelEvts;

    [NativeTypeName("int (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int> MIDI_EnumSelNotes;

    [NativeTypeName("int (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int> MIDI_EnumSelTextSysexEvts;

    [NativeTypeName("MIDI_eventlist *(*)()")]
    public delegate* unmanaged[Cdecl]<MIDI_eventlist*> MIDI_eventlist_Create;

    [NativeTypeName("void (*)(MIDI_eventlist *)")]
    public delegate* unmanaged[Cdecl]<MIDI_eventlist*, void> MIDI_eventlist_Destroy;

    [NativeTypeName("bool (*)(MediaItem_Take *, char *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, sbyte*, int*, byte> MIDI_GetAllEvts;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, bool *, bool *, double *, int *, int *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, bool*, bool*, double*, int*, int*, int*, int*, byte> MIDI_GetCC;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int *, double *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int*, double*, byte> MIDI_GetCCShape;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, bool *, bool *, double *, char *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, bool*, bool*, double*, sbyte*, int*, byte> MIDI_GetEvt;

    [NativeTypeName("double (*)(MediaItem_Take *, double *, double *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, double*, double*, double> MIDI_GetGrid;

    [NativeTypeName("bool (*)(MediaItem_Take *, bool, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, byte, sbyte*, int, byte> MIDI_GetHash;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, bool *, bool *, double *, double *, int *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, bool*, bool*, double*, double*, int*, int*, int*, byte> MIDI_GetNote;

    [NativeTypeName("double (*)(MediaItem_Take *, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, double, double> MIDI_GetPPQPos_EndOfMeasure;

    [NativeTypeName("double (*)(MediaItem_Take *, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, double, double> MIDI_GetPPQPos_StartOfMeasure;

    [NativeTypeName("double (*)(MediaItem_Take *, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, double, double> MIDI_GetPPQPosFromProjQN;

    [NativeTypeName("double (*)(MediaItem_Take *, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, double, double> MIDI_GetPPQPosFromProjTime;

    [NativeTypeName("double (*)(MediaItem_Take *, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, double, double> MIDI_GetProjQNFromPPQPos;

    [NativeTypeName("double (*)(MediaItem_Take *, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, double, double> MIDI_GetProjTimeFromPPQPos;

    [NativeTypeName("bool (*)(MediaItem_Take *, int *, int *, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int*, int*, sbyte*, int, byte> MIDI_GetScale;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, bool *, bool *, double *, int *, char *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, bool*, bool*, double*, int*, sbyte*, int*, byte> MIDI_GetTextSysexEvt;

    [NativeTypeName("bool (*)(MediaTrack *, bool, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, byte, sbyte*, int, byte> MIDI_GetTrackHash;

    [NativeTypeName("bool (*)(MediaItem_Take *, bool, bool, double, int, int, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, byte, byte, double, int, int, int, int, byte> MIDI_InsertCC;

    [NativeTypeName("bool (*)(MediaItem_Take *, bool, bool, double, const char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, byte, byte, double, sbyte*, int, byte> MIDI_InsertEvt;

    [NativeTypeName("bool (*)(MediaItem_Take *, bool, bool, double, double, int, int, int, const bool *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, byte, byte, double, double, int, int, int, bool*, byte> MIDI_InsertNote;

    [NativeTypeName("bool (*)(MediaItem_Take *, bool, bool, double, int, const char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, byte, byte, double, int, sbyte*, int, byte> MIDI_InsertTextSysexEvt;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> midi_reinit;

    [NativeTypeName("void (*)(MediaItem_Take *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, byte, void> MIDI_SelectAll;

    [NativeTypeName("bool (*)(MediaItem_Take *, const char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, sbyte*, int, byte> MIDI_SetAllEvts;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, const bool *, const bool *, const double *, const int *, const int *, const int *, const int *, const bool *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, bool*, bool*, double*, int*, int*, int*, int*, bool*, byte> MIDI_SetCC;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int, double, const bool *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, double, bool*, byte> MIDI_SetCCShape;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, const bool *, const bool *, const double *, const char *, int, const bool *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, bool*, bool*, double*, sbyte*, int, bool*, byte> MIDI_SetEvt;

    [NativeTypeName("bool (*)(MediaItem *, double, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, double, double, byte> MIDI_SetItemExtents;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, const bool *, const bool *, const double *, const double *, const int *, const int *, const int *, const bool *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, bool*, bool*, double*, double*, int*, int*, int*, bool*, byte> MIDI_SetNote;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, const bool *, const bool *, const double *, const int *, const char *, int, const bool *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, bool*, bool*, double*, int*, sbyte*, int, bool*, byte> MIDI_SetTextSysexEvt;

    [NativeTypeName("void (*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, void> MIDI_Sort;

    [NativeTypeName("HWND (*)()")]
    public delegate* unmanaged[Cdecl]<HWND> MIDIEditor_GetActive;

    [NativeTypeName("int (*)(HWND)")]
    public delegate* unmanaged[Cdecl]<HWND, int> MIDIEditor_GetMode;

    [NativeTypeName("int (*)(HWND, const char *)")]
    public delegate* unmanaged[Cdecl]<HWND, sbyte*, int> MIDIEditor_GetSetting_int;

    [NativeTypeName("bool (*)(HWND, const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<HWND, sbyte*, sbyte*, int, byte> MIDIEditor_GetSetting_str;

    [NativeTypeName("MediaItem_Take *(*)(HWND)")]
    public delegate* unmanaged[Cdecl]<HWND, MediaItem_Take*> MIDIEditor_GetTake;

    [NativeTypeName("bool (*)(int, bool)")]
    public delegate* unmanaged[Cdecl]<int, byte, byte> MIDIEditor_LastFocused_OnCommand;

    [NativeTypeName("bool (*)(HWND, int)")]
    public delegate* unmanaged[Cdecl]<HWND, int, byte> MIDIEditor_OnCommand;

    [NativeTypeName("bool (*)(HWND, const char *, int)")]
    public delegate* unmanaged[Cdecl]<HWND, sbyte*, int, byte> MIDIEditor_SetSetting_int;

    [NativeTypeName("void (*)(char *, double)")]
    public delegate* unmanaged[Cdecl]<sbyte*, double, void> mkpanstr;

    [NativeTypeName("void (*)(char *, double, double)")]
    public delegate* unmanaged[Cdecl]<sbyte*, double, double, void> mkvolpanstr;

    [NativeTypeName("void (*)(char *, double)")]
    public delegate* unmanaged[Cdecl]<sbyte*, double, void> mkvolstr;

    [NativeTypeName("void (*)(double, bool)")]
    public delegate* unmanaged[Cdecl]<double, byte, void> MoveEditCursor;

    [NativeTypeName("bool (*)(MediaItem *, MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, MediaTrack*, byte> MoveMediaItemToTrack;

    [NativeTypeName("void (*)(bool)")]
    public delegate* unmanaged[Cdecl]<byte, void> MuteAllTracks;

    [NativeTypeName("void (*)(RECT *, const RECT *, bool)")]
    public delegate* unmanaged[Cdecl]<RECT*, RECT*, byte, void> my_getViewport;

    [NativeTypeName("int (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int> NamedCommandLookup;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> OnPauseButton;

    [NativeTypeName("void (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, void> OnPauseButtonEx;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> OnPlayButton;

    [NativeTypeName("void (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, void> OnPlayButtonEx;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> OnStopButton;

    [NativeTypeName("void (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, void> OnStopButtonEx;

    [NativeTypeName("bool (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, byte> OpenColorThemeFile;

    [NativeTypeName("HWND (*)(const char *, bool)")]
    public delegate* unmanaged[Cdecl]<sbyte*, byte, HWND> OpenMediaExplorer;

    [NativeTypeName("void (*)(const char *, const double *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, double*, void> OscLocalMessageToHost;

    [NativeTypeName("double (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, double> parse_timestr;

    [NativeTypeName("double (*)(const char *, double, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, double, int, double> parse_timestr_len;

    [NativeTypeName("double (*)(const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, double> parse_timestr_pos;

    [NativeTypeName("double (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, double> parsepanstr;

    [NativeTypeName("PCM_sink *(*)(const char *, const char *, int, int, int, bool)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, int, int, byte, PCM_sink*> PCM_Sink_Create;

    [NativeTypeName("PCM_sink *(*)(ReaProject *, const char *, const char *, int, int, int, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, sbyte*, int, int, int, byte, PCM_sink*> PCM_Sink_CreateEx;

    [NativeTypeName("PCM_sink *(*)(const char *, const char *, int, double, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, double, int, PCM_sink*> PCM_Sink_CreateMIDIFile;

    [NativeTypeName("PCM_sink *(*)(ReaProject *, const char *, const char *, int, double, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, sbyte*, int, double, int, PCM_sink*> PCM_Sink_CreateMIDIFileEx;

    [NativeTypeName("unsigned int (*)(int, const char **)")]
    public delegate* unmanaged[Cdecl]<int, sbyte**, uint> PCM_Sink_Enum;

    [NativeTypeName("const char *(*)(const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, sbyte*> PCM_Sink_GetExtension;

    [NativeTypeName("HWND (*)(const char *, int, HWND)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, HWND, HWND> PCM_Sink_ShowConfig;

    [NativeTypeName("PCM_source *(*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, PCM_source*> PCM_Source_CreateFromFile;

    [NativeTypeName("PCM_source *(*)(const char *, bool)")]
    public delegate* unmanaged[Cdecl]<sbyte*, byte, PCM_source*> PCM_Source_CreateFromFileEx;

    [NativeTypeName("PCM_source *(*)(ISimpleMediaDecoder *, const char *)")]
    public delegate* unmanaged[Cdecl]<ISimpleMediaDecoder*, sbyte*, PCM_source*> PCM_Source_CreateFromSimple;

    [NativeTypeName("PCM_source *(*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, PCM_source*> PCM_Source_CreateFromType;

    [NativeTypeName("void (*)(PCM_source *)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, void> PCM_Source_Destroy;

    [NativeTypeName("int (*)(PCM_source *, double, double, int, int, int, double *)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, double, double, int, int, int, double*, int> PCM_Source_GetPeaks;

    [NativeTypeName("bool (*)(PCM_source *, double *, double *, bool *)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, double*, double*, bool*, byte> PCM_Source_GetSectionInfo;

    [NativeTypeName("REAPER_PeakBuild_Interface *(*)(PCM_source *, const char *, int, int)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, sbyte*, int, int, REAPER_PeakBuild_Interface*> PeakBuild_Create;

    [NativeTypeName("REAPER_PeakBuild_Interface *(*)(PCM_source *, const char *, int, int, int)")]
    public delegate* unmanaged[Cdecl]<PCM_source*, sbyte*, int, int, int, REAPER_PeakBuild_Interface*> PeakBuild_CreateEx;

    [NativeTypeName("REAPER_PeakGet_Interface *(*)(const char *, int, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, int, REAPER_PeakGet_Interface*> PeakGet_Create;

    [NativeTypeName("int (*)(HWND, int, int, int, int)")]
    public delegate* unmanaged[Cdecl]<HWND, int, int, int, int, int> PitchShiftSubModeMenu;

    [NativeTypeName("int (*)(preview_register_t *)")]
    public delegate* unmanaged[Cdecl]<preview_register_t*, int> PlayPreview;

    [NativeTypeName("int (*)(preview_register_t *, int, double)")]
    public delegate* unmanaged[Cdecl]<preview_register_t*, int, double, int> PlayPreviewEx;

    [NativeTypeName("int (*)(preview_register_t *)")]
    public delegate* unmanaged[Cdecl]<preview_register_t*, int> PlayTrackPreview;

    [NativeTypeName("int (*)(ReaProject *, preview_register_t *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, preview_register_t*, int> PlayTrackPreview2;

    [NativeTypeName("int (*)(ReaProject *, preview_register_t *, int, double)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, preview_register_t*, int, double, int> PlayTrackPreview2Ex;

    [NativeTypeName("void *(*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void*> plugin_getapi;

    [NativeTypeName("const char *(*)()")]
    public delegate* unmanaged[Cdecl]<sbyte*> plugin_getFilterList;

    [NativeTypeName("const char *(*)()")]
    public delegate* unmanaged[Cdecl]<sbyte*> plugin_getImportableProjectFilterList;

    [NativeTypeName("int (*)(const char *, void *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void*, int> plugin_register;

    [NativeTypeName("void (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, void> PluginWantsAlwaysRunFx;

    [NativeTypeName("void (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, void> PreventUIRefresh;

    [NativeTypeName("void *(*)(ReaProject *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, void*> projectconfig_var_addr;

    [NativeTypeName("int (*)(const char *, int *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int*, int> projectconfig_var_getoffs;

    [NativeTypeName("int (*)(int, int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, int, int> PromptForAction;

    [NativeTypeName("bool (*)(char **, int *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte**, int*, int, byte> realloc_cmd_ptr;

    [NativeTypeName("IReaperPitchShift *(*)(int)")]
    public delegate* unmanaged[Cdecl]<int, IReaperPitchShift*> ReaperGetPitchShiftAPI;

    [NativeTypeName("void (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void> ReaScriptError;

    [NativeTypeName("int (*)(const char *, size_t)")]
    public delegate* unmanaged[Cdecl]<sbyte*, nuint, int> RecursiveCreateDirectory;

    [NativeTypeName("int (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, int> reduce_open_files;

    [NativeTypeName("void (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, void> RefreshToolbar;

    [NativeTypeName("void (*)(int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, void> RefreshToolbar2;

    [NativeTypeName("void (*)(const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, void> relative_fn;

    [NativeTypeName("bool (*)(MediaTrack *, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, byte> RemoveTrackSend;

    [NativeTypeName("bool (*)(const char *, const char *, double, double, double)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, double, double, double, byte> RenderFileSection;

    [NativeTypeName("bool (*)(int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, byte> ReorderSelectedTracks;

    [NativeTypeName("const char *(*)(int)")]
    public delegate* unmanaged[Cdecl]<int, sbyte*> Resample_EnumModes;

    [NativeTypeName("REAPER_Resample_Interface *(*)()")]
    public delegate* unmanaged[Cdecl]<REAPER_Resample_Interface*> Resampler_Create;

    [NativeTypeName("void (*)(const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, void> resolve_fn;

    [NativeTypeName("void (*)(const char *, char *, int, const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, sbyte*, void> resolve_fn2;

    [NativeTypeName("const char *(*)(int)")]
    public delegate* unmanaged[Cdecl]<int, sbyte*> ReverseNamedCommandLookup;

    [NativeTypeName("double (*)(int, double)")]
    public delegate* unmanaged[Cdecl]<int, double, double> ScaleFromEnvelopeMode;

    [NativeTypeName("double (*)(int, double)")]
    public delegate* unmanaged[Cdecl]<int, double, double> ScaleToEnvelopeMode;

    [NativeTypeName("void (*)(char *, void *, void *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void*, void*, void> screenset_register;

    [NativeTypeName("void (*)(char *, screensetNewCallbackFunc, void *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, delegate* unmanaged[Cdecl]<int, sbyte*, void*, void*, int, long>, void*, void> screenset_registerNew;

    [NativeTypeName("void (*)(char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void> screenset_unregister;

    [NativeTypeName("void (*)(void *)")]
    public delegate* unmanaged[Cdecl]<void*, void> screenset_unregisterByParam;

    [NativeTypeName("void (*)(HWND)")]
    public delegate* unmanaged[Cdecl]<HWND, void> screenset_updateLastFocus;

    [NativeTypeName("KbdSectionInfo *(*)(int)")]
    public delegate* unmanaged[Cdecl]<int, KbdSectionInfo*> SectionFromUniqueID;

    [NativeTypeName("void (*)(ReaProject *, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, byte, void> SelectAllMediaItems;

    [NativeTypeName("void (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, void> SelectProjectInstance;

    [NativeTypeName("void (*)(void *, const char *, int)")]
    public delegate* unmanaged[Cdecl]<void*, sbyte*, int, void> SendLocalOscMessage;

    [NativeTypeName("void (*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, void> SetActiveTake;

    [NativeTypeName("void (*)(int, bool)")]
    public delegate* unmanaged[Cdecl]<int, byte, void> SetAutomationMode;

    [NativeTypeName("void (*)(ReaProject *, double, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, byte, void> SetCurrentBPM;

    [NativeTypeName("void (*)(int, TrackEnvelope *)")]
    public delegate* unmanaged[Cdecl]<int, TrackEnvelope*, void> SetCursorContext;

    [NativeTypeName("void (*)(double, bool, bool)")]
    public delegate* unmanaged[Cdecl]<double, byte, byte, void> SetEditCurPos;

    [NativeTypeName("void (*)(ReaProject *, double, bool, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, byte, byte, void> SetEditCurPos2;

    [NativeTypeName("bool (*)(TrackEnvelope *, int, double *, double *, int *, double *, bool *, bool *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, double*, double*, int*, double*, bool*, bool*, byte> SetEnvelopePoint;

    [NativeTypeName("bool (*)(TrackEnvelope *, int, int, double *, double *, int *, double *, bool *, bool *)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, int, int, double*, double*, int*, double*, bool*, bool*, byte> SetEnvelopePointEx;

    [NativeTypeName("bool (*)(TrackEnvelope *, const char *, bool)")]
    public delegate* unmanaged[Cdecl]<TrackEnvelope*, sbyte*, byte, byte> SetEnvelopeStateChunk;

    [NativeTypeName("void (*)(const char *, const char *, const char *, bool)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, sbyte*, byte, void> SetExtState;

    [NativeTypeName("void (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, void> SetGlobalAutomationOverride;

    [NativeTypeName("bool (*)(MediaItem *, const char *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, sbyte*, byte, byte> SetItemStateChunk;

    [NativeTypeName("int (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, int> SetMasterTrackVisibility;

    [NativeTypeName("bool (*)(MediaItem *, const char *, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, sbyte*, double, byte> SetMediaItemInfo_Value;

    [NativeTypeName("bool (*)(MediaItem *, double, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, double, byte, byte> SetMediaItemLength;

    [NativeTypeName("bool (*)(MediaItem *, double, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, double, byte, byte> SetMediaItemPosition;

    [NativeTypeName("void (*)(MediaItem *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, byte, void> SetMediaItemSelected;

    [NativeTypeName("bool (*)(MediaItem_Take *, PCM_source *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, PCM_source*, byte> SetMediaItemTake_Source;

    [NativeTypeName("bool (*)(MediaItem_Take *, const char *, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, sbyte*, double, byte> SetMediaItemTakeInfo_Value;

    [NativeTypeName("bool (*)(MediaTrack *, const char *, double)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, double, byte> SetMediaTrackInfo_Value;

    [NativeTypeName("void (*)(ReaProject *, double)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, void> SetMIDIEditorGrid;

    [NativeTypeName("MediaTrack *(*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, MediaTrack*> SetMixerScroll;

    [NativeTypeName("void (*)(const char *, int, const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, sbyte*, void> SetMouseModifier;

    [NativeTypeName("void (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, void> SetOnlyTrackSelected;

    [NativeTypeName("void (*)(ReaProject *, double)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, void> SetProjectGrid;

    [NativeTypeName("bool (*)(int, bool, double, double, const char *)")]
    public delegate* unmanaged[Cdecl]<int, byte, double, double, sbyte*, byte> SetProjectMarker;

    [NativeTypeName("bool (*)(ReaProject *, int, bool, double, double, const char *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte, double, double, sbyte*, byte> SetProjectMarker2;

    [NativeTypeName("bool (*)(ReaProject *, int, bool, double, double, const char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte, double, double, sbyte*, int, byte> SetProjectMarker3;

    [NativeTypeName("bool (*)(ReaProject *, int, bool, double, double, const char *, int, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte, double, double, sbyte*, int, int, byte> SetProjectMarker4;

    [NativeTypeName("bool (*)(ReaProject *, int, bool, double, double, int, const char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte, double, double, int, sbyte*, int, byte> SetProjectMarkerByIndex;

    [NativeTypeName("bool (*)(ReaProject *, int, bool, double, double, int, const char *, int, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, byte, double, double, int, sbyte*, int, int, byte> SetProjectMarkerByIndex2;

    [NativeTypeName("int (*)(ReaProject *, const char *, const char *, const char *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, sbyte*, sbyte*, int> SetProjExtState;

    [NativeTypeName("void (*)(ReaProject *, int, MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, MediaTrack*, int, void> SetRegionRenderMatrix;

    [NativeTypeName("void (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void> SetRenderLastError;

    [NativeTypeName("int (*)(MediaItem_Take *, int, const char *, double *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, sbyte*, double*, int*, int> SetTakeMarker;

    [NativeTypeName("int (*)(MediaItem_Take *, int, double, const double *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, double, double*, int> SetTakeStretchMarker;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, double, byte> SetTakeStretchMarkerSlope;

    [NativeTypeName("bool (*)(ReaProject *, int, double, int, double, double, int, int, bool)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, double, int, double, double, int, int, byte, byte> SetTempoTimeSigMarker;

    [NativeTypeName("int (*)(const char *, int, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, int, int> SetThemeColor;

    [NativeTypeName("bool (*)(int, int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, int, byte> SetToggleCommandState;

    [NativeTypeName("void (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, void> SetTrackAutomationMode;

    [NativeTypeName("void (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, void> SetTrackColor;

    [NativeTypeName("bool (*)(MediaTrack *, int, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, sbyte*, byte> SetTrackMIDILyrics;

    [NativeTypeName("bool (*)(int, int, int, const char *)")]
    public delegate* unmanaged[Cdecl]<int, int, int, sbyte*, byte> SetTrackMIDINoteName;

    [NativeTypeName("bool (*)(ReaProject *, MediaTrack *, int, int, const char *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, MediaTrack*, int, int, sbyte*, byte> SetTrackMIDINoteNameEx;

    [NativeTypeName("void (*)(MediaTrack *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, byte, void> SetTrackSelected;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, const char *, double)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, sbyte*, double, byte> SetTrackSendInfo_Value;

    [NativeTypeName("bool (*)(MediaTrack *, int, double, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, double, int, byte> SetTrackSendUIPan;

    [NativeTypeName("bool (*)(MediaTrack *, int, double, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, double, int, byte> SetTrackSendUIVol;

    [NativeTypeName("bool (*)(MediaTrack *, const char *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, byte, byte> SetTrackStateChunk;

    [NativeTypeName("void (*)(KbdSectionInfo *, HWND)")]
    public delegate* unmanaged[Cdecl]<KbdSectionInfo*, HWND, void> ShowActionList;

    [NativeTypeName("void (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void> ShowConsoleMsg;

    [NativeTypeName("int (*)(const char *, const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, int, int> ShowMessageBox;

    [NativeTypeName("void (*)(const char *, int, int, HWND, void *, int, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, int, HWND, void*, int, int, void> ShowPopupMenu;

    [NativeTypeName("double (*)(double)")]
    public delegate* unmanaged[Cdecl]<double, double> SLIDER2DB;

    [NativeTypeName("double (*)(ReaProject *, double)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, double> SnapToGrid;

    [NativeTypeName("void (*)(int)")]
    public delegate* unmanaged[Cdecl]<int, void> SoloAllTracks;

    [NativeTypeName("HWND (*)()")]
    public delegate* unmanaged[Cdecl]<HWND> Splash_GetWnd;

    [NativeTypeName("MediaItem *(*)(MediaItem *, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, double, MediaItem*> SplitMediaItem;

    [NativeTypeName("int (*)(preview_register_t *)")]
    public delegate* unmanaged[Cdecl]<preview_register_t*, int> StopPreview;

    [NativeTypeName("int (*)(preview_register_t *)")]
    public delegate* unmanaged[Cdecl]<preview_register_t*, int> StopTrackPreview;

    [NativeTypeName("int (*)(void *, preview_register_t *)")]
    public delegate* unmanaged[Cdecl]<void*, preview_register_t*, int> StopTrackPreview2;

    [NativeTypeName("void (*)(const char *, GUID *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, GUID*, void> stringToGuid;

    [NativeTypeName("void (*)(int, int, int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, int, int, void> StuffMIDIMessage;

    [NativeTypeName("int (*)(MediaItem_Take *, const char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, sbyte*, int, int> TakeFX_AddByName;

    [NativeTypeName("void (*)(MediaItem_Take *, int, MediaItem_Take *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, MediaItem_Take*, int, byte, void> TakeFX_CopyToTake;

    [NativeTypeName("void (*)(MediaItem_Take *, int, MediaTrack *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, MediaTrack*, int, byte, void> TakeFX_CopyToTrack;

    [NativeTypeName("bool (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte> TakeFX_Delete;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, byte> TakeFX_EndParamEdit;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int, double, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, double, sbyte*, int, byte> TakeFX_FormatParamValue;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int, double, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, double, sbyte*, int, byte> TakeFX_FormatParamValueNormalized;

    [NativeTypeName("int (*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int> TakeFX_GetChainVisible;

    [NativeTypeName("int (*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int> TakeFX_GetCount;

    [NativeTypeName("bool (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte> TakeFX_GetEnabled;

    [NativeTypeName("TrackEnvelope *(*)(MediaItem_Take *, int, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, byte, TrackEnvelope*> TakeFX_GetEnvelope;

    [NativeTypeName("HWND (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, HWND> TakeFX_GetFloatingWindow;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, sbyte*, int, byte> TakeFX_GetFormattedParamValue;

    [NativeTypeName("GUID *(*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, GUID*> TakeFX_GetFXGUID;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, sbyte*, int, byte> TakeFX_GetFXName;

    [NativeTypeName("int (*)(MediaItem_Take *, int, int *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int*, int*, int> TakeFX_GetIOSize;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, sbyte*, sbyte*, int, byte> TakeFX_GetNamedConfigParm;

    [NativeTypeName("int (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int> TakeFX_GetNumParams;

    [NativeTypeName("bool (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte> TakeFX_GetOffline;

    [NativeTypeName("bool (*)(MediaItem_Take *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte> TakeFX_GetOpen;

    [NativeTypeName("double (*)(MediaItem_Take *, int, int, double *, double *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, double*, double*, double> TakeFX_GetParam;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int, double *, double *, double *, bool *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, double*, double*, double*, bool*, byte> TakeFX_GetParameterStepSizes;

    [NativeTypeName("double (*)(MediaItem_Take *, int, int, double *, double *, double *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, double*, double*, double*, double> TakeFX_GetParamEx;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, sbyte*, int, byte> TakeFX_GetParamName;

    [NativeTypeName("double (*)(MediaItem_Take *, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, double> TakeFX_GetParamNormalized;

    [NativeTypeName("int (*)(MediaItem_Take *, int, int, int, int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, int, int*, int> TakeFX_GetPinMappings;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, sbyte*, int, byte> TakeFX_GetPreset;

    [NativeTypeName("int (*)(MediaItem_Take *, int, int *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int*, int> TakeFX_GetPresetIndex;

    [NativeTypeName("void (*)(MediaItem_Take *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, sbyte*, int, void> TakeFX_GetUserPresetFilename;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, byte> TakeFX_NavigatePresets;

    [NativeTypeName("void (*)(MediaItem_Take *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte, void> TakeFX_SetEnabled;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, const char *, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, sbyte*, sbyte*, byte> TakeFX_SetNamedConfigParm;

    [NativeTypeName("void (*)(MediaItem_Take *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte, void> TakeFX_SetOffline;

    [NativeTypeName("void (*)(MediaItem_Take *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, byte, void> TakeFX_SetOpen;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, double, byte> TakeFX_SetParam;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int, double)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, double, byte> TakeFX_SetParamNormalized;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int, int, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, int, int, int, byte> TakeFX_SetPinMappings;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, sbyte*, byte> TakeFX_SetPreset;

    [NativeTypeName("bool (*)(MediaItem_Take *, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, byte> TakeFX_SetPresetByIndex;

    [NativeTypeName("void (*)(MediaItem_Take *, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, int, int, void> TakeFX_Show;

    [NativeTypeName("bool (*)(MediaItem_Take *)")]
    public delegate* unmanaged[Cdecl]<MediaItem_Take*, byte> TakeIsMIDI;

    [NativeTypeName("bool (*)(const char *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, sbyte*, int, byte> ThemeLayout_GetLayout;

    [NativeTypeName("const char *(*)(int, const char **, int *, int *, int *, int *)")]
    public delegate* unmanaged[Cdecl]<int, sbyte**, int*, int*, int*, int*, sbyte*> ThemeLayout_GetParameter;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> ThemeLayout_RefreshAll;

    [NativeTypeName("bool (*)(const char *, const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, sbyte*, byte> ThemeLayout_SetLayout;

    [NativeTypeName("bool (*)(int, int, bool)")]
    public delegate* unmanaged[Cdecl]<int, int, byte, byte> ThemeLayout_SetParameter;

    [NativeTypeName("double (*)()")]
    public delegate* unmanaged[Cdecl]<double> time_precise;

    [NativeTypeName("double (*)(ReaProject *, double, const int *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, int*, double> TimeMap2_beatsToTime;

    [NativeTypeName("double (*)(ReaProject *, double)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, double> TimeMap2_GetDividedBpmAtTime;

    [NativeTypeName("double (*)(ReaProject *, double)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, double> TimeMap2_GetNextChangeTime;

    [NativeTypeName("double (*)(ReaProject *, double)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, double> TimeMap2_QNToTime;

    [NativeTypeName("double (*)(ReaProject *, double, int *, int *, double *, int *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, int*, int*, double*, int*, double> TimeMap2_timeToBeats;

    [NativeTypeName("double (*)(ReaProject *, double)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, double> TimeMap2_timeToQN;

    [NativeTypeName("double (*)(ReaProject *, bool *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, bool*, double> TimeMap_curFrameRate;

    [NativeTypeName("double (*)(double)")]
    public delegate* unmanaged[Cdecl]<double, double> TimeMap_GetDividedBpmAtTime;

    [NativeTypeName("double (*)(ReaProject *, int, double *, double *, int *, int *, double *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int, double*, double*, int*, int*, double*, double> TimeMap_GetMeasureInfo;

    [NativeTypeName("int (*)(ReaProject *, double, char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, sbyte*, int, int> TimeMap_GetMetronomePattern;

    [NativeTypeName("void (*)(ReaProject *, double, int *, int *, double *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, int*, int*, double*, void> TimeMap_GetTimeSigAtTime;

    [NativeTypeName("int (*)(ReaProject *, double, double *, double *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, double*, double*, int> TimeMap_QNToMeasures;

    [NativeTypeName("double (*)(double)")]
    public delegate* unmanaged[Cdecl]<double, double> TimeMap_QNToTime;

    [NativeTypeName("double (*)(ReaProject *, double)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, double> TimeMap_QNToTime_abs;

    [NativeTypeName("double (*)(double)")]
    public delegate* unmanaged[Cdecl]<double, double> TimeMap_timeToQN;

    [NativeTypeName("double (*)(ReaProject *, double)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, double, double> TimeMap_timeToQN_abs;

    [NativeTypeName("bool (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte> ToggleTrackSendUIMute;

    [NativeTypeName("double (*)(MediaTrack *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte, double> Track_GetPeakHoldDB;

    [NativeTypeName("double (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, double> Track_GetPeakInfo;

    [NativeTypeName("void (*)(const char *, int, int, bool)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, int, byte, void> TrackCtl_SetToolTip;

    [NativeTypeName("int (*)(MediaTrack *, const char *, bool, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, byte, int, int> TrackFX_AddByName;

    [NativeTypeName("void (*)(MediaTrack *, int, MediaItem_Take *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, MediaItem_Take*, int, byte, void> TrackFX_CopyToTake;

    [NativeTypeName("void (*)(MediaTrack *, int, MediaTrack *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, MediaTrack*, int, byte, void> TrackFX_CopyToTrack;

    [NativeTypeName("bool (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte> TrackFX_Delete;

    [NativeTypeName("bool (*)(MediaTrack *, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, byte> TrackFX_EndParamEdit;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, double, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, double, sbyte*, int, byte> TrackFX_FormatParamValue;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, double, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, double, sbyte*, int, byte> TrackFX_FormatParamValueNormalized;

    [NativeTypeName("int (*)(MediaTrack *, const char *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, sbyte*, byte, int> TrackFX_GetByName;

    [NativeTypeName("int (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int> TrackFX_GetChainVisible;

    [NativeTypeName("int (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int> TrackFX_GetCount;

    [NativeTypeName("bool (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte> TrackFX_GetEnabled;

    [NativeTypeName("int (*)(MediaTrack *, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, byte, int> TrackFX_GetEQ;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, int, byte> TrackFX_GetEQBandEnabled;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, int *, int *, int *, double *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, int*, int*, int*, double*, byte> TrackFX_GetEQParam;

    [NativeTypeName("HWND (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, HWND> TrackFX_GetFloatingWindow;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, sbyte*, int, byte> TrackFX_GetFormattedParamValue;

    [NativeTypeName("GUID *(*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, GUID*> TrackFX_GetFXGUID;

    [NativeTypeName("bool (*)(MediaTrack *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, sbyte*, int, byte> TrackFX_GetFXName;

    [NativeTypeName("int (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int> TrackFX_GetInstrument;

    [NativeTypeName("int (*)(MediaTrack *, int, int *, int *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int*, int*, int> TrackFX_GetIOSize;

    [NativeTypeName("bool (*)(MediaTrack *, int, const char *, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, sbyte*, sbyte*, int, byte> TrackFX_GetNamedConfigParm;

    [NativeTypeName("int (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int> TrackFX_GetNumParams;

    [NativeTypeName("bool (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte> TrackFX_GetOffline;

    [NativeTypeName("bool (*)(MediaTrack *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte> TrackFX_GetOpen;

    [NativeTypeName("double (*)(MediaTrack *, int, int, double *, double *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, double*, double*, double> TrackFX_GetParam;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, double *, double *, double *, bool *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, double*, double*, double*, bool*, byte> TrackFX_GetParameterStepSizes;

    [NativeTypeName("double (*)(MediaTrack *, int, int, double *, double *, double *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, double*, double*, double*, double> TrackFX_GetParamEx;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, sbyte*, int, byte> TrackFX_GetParamName;

    [NativeTypeName("double (*)(MediaTrack *, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, double> TrackFX_GetParamNormalized;

    [NativeTypeName("int (*)(MediaTrack *, int, int, int, int *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, int, int*, int> TrackFX_GetPinMappings;

    [NativeTypeName("bool (*)(MediaTrack *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, sbyte*, int, byte> TrackFX_GetPreset;

    [NativeTypeName("int (*)(MediaTrack *, int, int *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int*, int> TrackFX_GetPresetIndex;

    [NativeTypeName("int (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int> TrackFX_GetRecChainVisible;

    [NativeTypeName("int (*)(MediaTrack *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int> TrackFX_GetRecCount;

    [NativeTypeName("void (*)(MediaTrack *, int, char *, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, sbyte*, int, void> TrackFX_GetUserPresetFilename;

    [NativeTypeName("bool (*)(MediaTrack *, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, byte> TrackFX_NavigatePresets;

    [NativeTypeName("void (*)(MediaTrack *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte, void> TrackFX_SetEnabled;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, int, byte, byte> TrackFX_SetEQBandEnabled;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, int, int, double, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, int, int, double, byte, byte> TrackFX_SetEQParam;

    [NativeTypeName("bool (*)(MediaTrack *, int, const char *, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, sbyte*, sbyte*, byte> TrackFX_SetNamedConfigParm;

    [NativeTypeName("void (*)(MediaTrack *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte, void> TrackFX_SetOffline;

    [NativeTypeName("void (*)(MediaTrack *, int, bool)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, byte, void> TrackFX_SetOpen;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, double)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, double, byte> TrackFX_SetParam;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, double)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, double, byte> TrackFX_SetParamNormalized;

    [NativeTypeName("bool (*)(MediaTrack *, int, int, int, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, int, int, int, byte> TrackFX_SetPinMappings;

    [NativeTypeName("bool (*)(MediaTrack *, int, const char *)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, sbyte*, byte> TrackFX_SetPreset;

    [NativeTypeName("bool (*)(MediaTrack *, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, byte> TrackFX_SetPresetByIndex;

    [NativeTypeName("void (*)(MediaTrack *, int, int)")]
    public delegate* unmanaged[Cdecl]<MediaTrack*, int, int, void> TrackFX_Show;

    [NativeTypeName("void (*)(bool)")]
    public delegate* unmanaged[Cdecl]<byte, void> TrackList_AdjustWindows;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> TrackList_UpdateAllExternalSurfaces;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> Undo_BeginBlock;

    [NativeTypeName("void (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, void> Undo_BeginBlock2;

    [NativeTypeName("const char *(*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*> Undo_CanRedo2;

    [NativeTypeName("const char *(*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*> Undo_CanUndo2;

    [NativeTypeName("int (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int> Undo_DoRedo2;

    [NativeTypeName("int (*)(ReaProject *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, int> Undo_DoUndo2;

    [NativeTypeName("void (*)(const char *, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, void> Undo_EndBlock;

    [NativeTypeName("void (*)(ReaProject *, const char *, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, int, void> Undo_EndBlock2;

    [NativeTypeName("void (*)(const char *)")]
    public delegate* unmanaged[Cdecl]<sbyte*, void> Undo_OnStateChange;

    [NativeTypeName("void (*)(ReaProject *, const char *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, void> Undo_OnStateChange2;

    [NativeTypeName("void (*)(ReaProject *, const char *, MediaItem *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, MediaItem*, void> Undo_OnStateChange_Item;

    [NativeTypeName("void (*)(const char *, int, int)")]
    public delegate* unmanaged[Cdecl]<sbyte*, int, int, void> Undo_OnStateChangeEx;

    [NativeTypeName("void (*)(ReaProject *, const char *, int, int)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, sbyte*, int, int, void> Undo_OnStateChangeEx2;

    [NativeTypeName("void (*)(int, int)")]
    public delegate* unmanaged[Cdecl]<int, int, void> update_disk_counters;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> UpdateArrange;

    [NativeTypeName("void (*)(MediaItem *)")]
    public delegate* unmanaged[Cdecl]<MediaItem*, void> UpdateItemInProject;

    [NativeTypeName("void (*)()")]
    public delegate* unmanaged[Cdecl]<void> UpdateTimeline;

    [NativeTypeName("bool (*)(void *, const char *)")]
    public delegate* unmanaged[Cdecl]<void*, sbyte*, byte> ValidatePtr;

    [NativeTypeName("bool (*)(ReaProject *, void *, const char *)")]
    public delegate* unmanaged[Cdecl]<ReaProject*, void*, sbyte*, byte> ValidatePtr2;

    [NativeTypeName("void (*)(int, const char *)")]
    public delegate* unmanaged[Cdecl]<int, sbyte*, void> ViewPrefs;

    [NativeTypeName("bool (*)(LICE_IBitmap *, WDL_VirtualWnd_BGCfg *, int, int, int, int, int, int, int, int, float, int)")]
    public delegate* unmanaged[Cdecl]<LICE_IBitmap*, WDL_VirtualWnd_BGCfg*, int, int, int, int, int, int, int, int, float, int, byte> WDL_VirtualWnd_ScaledBlitBG;
  }

}
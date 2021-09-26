#include "reaper_plugin.h"

typedef unsigned int LICE_pixel;
typedef unsigned char LICE_pixel_chan;
class LICE_IBitmap;
class LICE_IFont;

class WDL_VirtualWnd_BGCfg;
class AudioAccessor;
class joystick_device;

struct reaper_plugin_functions {

  //==============================================
  // __mergesort
  // __mergesort is a stable sorting function with an API similar to qsort().
  // HOWEVER, it requires some temporary space, equal to the size of the data
  // being sorted, so you can pass it as the last parameter, or NULL and it will
  // allocate and free space internally.
  void (*__mergesort)(void *base, size_t nmemb, size_t size,
                      int (*cmpfunc)(const void *, const void *),
                      void *tmpspace);

  //==============================================
  // AddCustomizableMenu
  // menuidstr is some unique identifying string
  // menuname is for main menus only (displayed in a menu bar somewhere), NULL
  // otherwise kbdsecname is the name of the KbdSectionInfo registered by this
  // plugin, or NULL for the main actions section
  bool (*AddCustomizableMenu)(const char *menuidstr, const char *menuname,
                              const char *kbdsecname, bool addtomainmenu);

  //==============================================
  // AddExtensionsMainMenu
  // Add an Extensions main menu, which the extension can populate/modify with
  // plugin_register("hookcustommenu")
  bool (*AddExtensionsMainMenu)();

  //==============================================
  // AddMediaItemToTrack
  // creates a new media item.
  MediaItem *(*AddMediaItemToTrack)(MediaTrack *tr);

  //==============================================
  // AddProjectMarker
  // Returns the index of the created marker/region, or -1 on failure. Supply
  // wantidx>=0 if you want a particular index number, but you'll get a
  // different index number a region and wantidx is already in use.
  int (*AddProjectMarker)(ReaProject *proj, bool isrgn, double pos,
                          double rgnend, const char *name, int wantidx);

  //==============================================
  // AddProjectMarker2
  // Returns the index of the created marker/region, or -1 on failure. Supply
  // wantidx>=0 if you want a particular index number, but you'll get a
  // different index number a region and wantidx is already in use. color should
  // be 0 (default color), or ColorToNative(r,g,b)|0x1000000
  int (*AddProjectMarker2)(ReaProject *proj, bool isrgn, double pos,
                           double rgnend, const char *name, int wantidx,
                           int color);

  //==============================================
  // AddRemoveReaScript
  // Add a ReaScript (return the new command ID, or 0 if failed) or remove a
  // ReaScript (return >0 on success). Use commit==true when adding/removing a
  // single script. When bulk adding/removing n scripts, you can optimize the
  // n-1 first calls with commit==false and commit==true for the last call.
  int (*AddRemoveReaScript)(bool add, int sectionID, const char *scriptfn,
                            bool commit);

  //==============================================
  // AddTakeToMediaItem
  // creates a new take in an item
  MediaItem_Take *(*AddTakeToMediaItem)(MediaItem *item);

  //==============================================
  // AddTempoTimeSigMarker
  // Deprecated. Use SetTempoTimeSigMarker with ptidx=-1.
  bool (*AddTempoTimeSigMarker)(ReaProject *proj, double timepos, double bpm,
                                int timesig_num, int timesig_denom,
                                bool lineartempochange);

  //==============================================
  // adjustZoom
  // forceset=0,doupd=true,centermode=-1 for default
  void (*adjustZoom)(double amt, int forceset, bool doupd, int centermode);

  //==============================================
  // AnyTrackSolo
  bool (*AnyTrackSolo)(ReaProject *proj);

  //==============================================
  // APIExists
  // Returns true if function_name exists in the REAPER API
  bool (*APIExists)(const char *function_name);

  //==============================================
  // APITest
  // Displays a message window if the API was successfully called.
  void (*APITest)();

  //==============================================
  // ApplyNudge
  // nudgeflag: &1=set to value (otherwise nudge by value), &2=snap
  // nudgewhat: 0=position, 1=left trim, 2=left edge, 3=right edge, 4=contents,
  // 5=duplicate, 6=edit cursor nudgeunit: 0=ms, 1=seconds, 2=grid, 3=256th
  // notes, ..., 15=whole notes, 16=measures.beats (1.15 = 1 measure + 1.5
  // beats), 17=samples, 18=frames, 19=pixels, 20=item lengths, 21=item
  // selections value: amount to nudge by, or value to set to reverse: in nudge
  // mode, nudges left (otherwise ignored) copies: in nudge duplicate mode,
  // number of copies (otherwise ignored)
  bool (*ApplyNudge)(ReaProject *project, int nudgeflag, int nudgewhat,
                     int nudgeunits, double value, bool reverse, int copies);

  //==============================================
  // ArmCommand
  // arms a command (or disarms if 0 passed) in section sectionname (empty
  // string for main)
  void (*ArmCommand)(int cmd, const char *sectionname);

  //==============================================
  // Audio_Init
  // open all audio and MIDI devices, if not open
  void (*Audio_Init)();

  //==============================================
  // Audio_IsPreBuffer
  // is in pre-buffer? threadsafe
  int (*Audio_IsPreBuffer)();

  //==============================================
  // Audio_IsRunning
  // is audio running at all? threadsafe
  int (*Audio_IsRunning)();

  //==============================================
  // Audio_Quit
  // close all audio and MIDI devices, if open
  void (*Audio_Quit)();

  //==============================================
  // Audio_RegHardwareHook
  // return >0 on success
  int (*Audio_RegHardwareHook)(bool isAdd, audio_hook_register_t *reg);

  //==============================================
  // AudioAccessorStateChanged
  // Returns true if the underlying samples (track or media item take) have
  // changed, but does not update the audio accessor, so the user can
  // selectively call AudioAccessorValidateState only when needed. See
  // CreateTakeAudioAccessor, CreateTrackAudioAccessor, DestroyAudioAccessor,
  // GetAudioAccessorEndTime, GetAudioAccessorSamples.
  bool (*AudioAccessorStateChanged)(AudioAccessor *accessor);

  //==============================================
  // AudioAccessorUpdate
  // Force the accessor to reload its state from the underlying track or media
  // item take. See CreateTakeAudioAccessor, CreateTrackAudioAccessor,
  // DestroyAudioAccessor, AudioAccessorStateChanged, GetAudioAccessorStartTime,
  // GetAudioAccessorEndTime, GetAudioAccessorSamples.
  void (*AudioAccessorUpdate)(AudioAccessor *accessor);

  //==============================================
  // AudioAccessorValidateState
  // Validates the current state of the audio accessor -- must ONLY call this
  // from the main thread. Returns true if the state changed.
  bool (*AudioAccessorValidateState)(AudioAccessor *accessor);

  //==============================================
  // BypassFxAllTracks
  // -1 = bypass all if not all bypassed,otherwise unbypass all
  void (*BypassFxAllTracks)(int bypass);

  //==============================================
  // CalculatePeaks
  int (*CalculatePeaks)(PCM_source_transfer_t *srcBlock,
                        PCM_source_peaktransfer_t *pksBlock);

  //==============================================
  // CalculatePeaksFloatSrcPtr
  // NOTE: source samples field is a pointer to floats instead
  int (*CalculatePeaksFloatSrcPtr)(PCM_source_transfer_t *srcBlock,
                                   PCM_source_peaktransfer_t *pksBlock);

  //==============================================
  // ClearAllRecArmed
  void (*ClearAllRecArmed)();

  //==============================================
  // ClearConsole
  // Clear the ReaScript console. See ShowConsoleMsg
  void (*ClearConsole)();

  //==============================================
  // ClearPeakCache
  // resets the global peak caches
  void (*ClearPeakCache)();

  //==============================================
  // ColorFromNative
  // Extract RGB values from an OS dependent color. See ColorToNative.
  void (*ColorFromNative)(int col, int *rOut, int *gOut, int *bOut);

  //==============================================
  // ColorToNative
  // Make an OS dependent color from RGB values (e.g. RGB() macro on Windows).
  // r,g and b are in [0..255]. See ColorFromNative.
  int (*ColorToNative)(int r, int g, int b);

  //==============================================
  // CountActionShortcuts
  // Returns the number of shortcuts that exist for the given command ID.
  // see GetActionShortcutDesc, DeleteActionShortcut, DoActionShortcutDialog.
  int (*CountActionShortcuts)(KbdSectionInfo *section, int cmdID);

  //==============================================
  // CountAutomationItems
  // Returns the number of automation items on this envelope. See
  // GetSetAutomationItemInfo
  int (*CountAutomationItems)(TrackEnvelope *env);

  //==============================================
  // CountEnvelopePoints
  // Returns the number of points in the envelope. See CountEnvelopePointsEx.
  int (*CountEnvelopePoints)(TrackEnvelope *envelope);

  //==============================================
  // CountEnvelopePointsEx
  // Returns the number of points in the envelope.
  // autoitem_idx=-1 for the underlying envelope, 0 for the first automation
  // item on the envelope, etc. For automation items, pass
  // autoitem_idx|0x10000000 to base ptidx on the number of points in one full
  // loop iteration, even if the automation item is trimmed so that not all
  // points are visible. Otherwise, ptidx will be based on the number of visible
  // points in the automation item, including all loop iterations. See
  // GetEnvelopePointEx, SetEnvelopePointEx, InsertEnvelopePointEx,
  // DeleteEnvelopePointEx.
  int (*CountEnvelopePointsEx)(TrackEnvelope *envelope, int autoitem_idx);

  //==============================================
  // CountMediaItems
  // count the number of items in the project (proj=0 for active project)
  int (*CountMediaItems)(ReaProject *proj);

  //==============================================
  // CountProjectMarkers
  // num_markersOut and num_regionsOut may be NULL.
  int (*CountProjectMarkers)(ReaProject *proj, int *num_markersOut,
                             int *num_regionsOut);

  //==============================================
  // CountSelectedMediaItems
  // count the number of selected items in the project (proj=0 for active
  // project)
  int (*CountSelectedMediaItems)(ReaProject *proj);

  //==============================================
  // CountSelectedTracks
  // Count the number of selected tracks in the project (proj=0 for active
  // project). This function ignores the master track, see CountSelectedTracks2.
  int (*CountSelectedTracks)(ReaProject *proj);

  //==============================================
  // CountSelectedTracks2
  // Count the number of selected tracks in the project (proj=0 for active
  // project).
  int (*CountSelectedTracks2)(ReaProject *proj, bool wantmaster);

  //==============================================
  // CountTakeEnvelopes
  // See GetTakeEnvelope
  int (*CountTakeEnvelopes)(MediaItem_Take *take);

  //==============================================
  // CountTakes
  // count the number of takes in the item
  int (*CountTakes)(MediaItem *item);

  //==============================================
  // CountTCPFXParms
  // Count the number of FX parameter knobs displayed on the track control
  // panel.
  int (*CountTCPFXParms)(ReaProject *project, MediaTrack *track);

  //==============================================
  // CountTempoTimeSigMarkers
  // Count the number of tempo/time signature markers in the project. See
  // GetTempoTimeSigMarker, SetTempoTimeSigMarker, AddTempoTimeSigMarker.
  int (*CountTempoTimeSigMarkers)(ReaProject *proj);

  //==============================================
  // CountTrackEnvelopes
  // see GetTrackEnvelope
  int (*CountTrackEnvelopes)(MediaTrack *track);

  //==============================================
  // CountTrackMediaItems
  // count the number of items in the track
  int (*CountTrackMediaItems)(MediaTrack *track);

  //==============================================
  // CountTracks
  // count the number of tracks in the project (proj=0 for active project)
  int (*CountTracks)(ReaProject *projOptional);

  //==============================================
  // CreateLocalOscHandler
  // callback is a function pointer: void (*callback)(void* obj, const char*
  // msg, int msglen), which handles OSC messages sent from REAPER. The function
  // return is a local osc handler. See SendLocalOscMessage, DestroyOscHandler.
  void *(*CreateLocalOscHandler)(void *obj, void *callback);

  //==============================================
  // CreateMIDIInput
  // Can only reliably create midi access for devices not already opened in
  // prefs/MIDI, suitable for control surfaces etc.
  midi_Input *(*CreateMIDIInput)(int dev);

  //==============================================
  // CreateMIDIOutput
  // Can only reliably create midi access for devices not already opened in
  // prefs/MIDI, suitable for control surfaces etc. If streamMode is set,
  // msoffset100 points to a persistent variable that can change and reflects
  // added delay to output in 100ths of a millisecond.
  midi_Output *(*CreateMIDIOutput)(int dev, bool streamMode, int *msoffset100);

  //==============================================
  // CreateNewMIDIItemInProj
  // Create a new MIDI media item, containing no MIDI events. Time is in seconds
  // unless qn is set.
  MediaItem *(*CreateNewMIDIItemInProj)(MediaTrack *track, double starttime,
                                        double endtime,
                                        const bool *qnInOptional);

  //==============================================
  // CreateTakeAudioAccessor
  // Create an audio accessor object for this take. Must only call from the main
  // thread. See CreateTrackAudioAccessor, DestroyAudioAccessor,
  // AudioAccessorStateChanged, GetAudioAccessorStartTime,
  // GetAudioAccessorEndTime, GetAudioAccessorSamples.
  AudioAccessor *(*CreateTakeAudioAccessor)(MediaItem_Take *take);

  //==============================================
  // CreateTrackAudioAccessor
  // Create an audio accessor object for this track. Must only call from the
  // main thread. See CreateTakeAudioAccessor, DestroyAudioAccessor,
  // AudioAccessorStateChanged, GetAudioAccessorStartTime,
  // GetAudioAccessorEndTime, GetAudioAccessorSamples.
  AudioAccessor *(*CreateTrackAudioAccessor)(MediaTrack *track);

  //==============================================
  // CreateTrackSend
  // Create a send/receive (desttrInOptional!=NULL), or a hardware output
  // (desttrInOptional==NULL) with default properties, return >=0 on success (==
  // new send/receive index). See RemoveTrackSend, GetSetTrackSendInfo,
  // GetTrackSendInfo_Value, SetTrackSendInfo_Value.
  int (*CreateTrackSend)(MediaTrack *tr, MediaTrack *desttrInOptional);

  //==============================================
  // CSurf_FlushUndo
  // call this to force flushing of the undo states after using
  // CSurf_On*Change()
  void (*CSurf_FlushUndo)(bool force);

  //==============================================
  // CSurf_GetTouchState
  bool (*CSurf_GetTouchState)(MediaTrack *trackid, int isPan);

  //==============================================
  // CSurf_GoEnd
  void (*CSurf_GoEnd)();

  //==============================================
  // CSurf_GoStart
  void (*CSurf_GoStart)();

  //==============================================
  // CSurf_NumTracks
  int (*CSurf_NumTracks)(bool mcpView);

  //==============================================
  // CSurf_OnArrow
  void (*CSurf_OnArrow)(int whichdir, bool wantzoom);

  //==============================================
  // CSurf_OnFwd
  void (*CSurf_OnFwd)(int seekplay);

  //==============================================
  // CSurf_OnFXChange
  bool (*CSurf_OnFXChange)(MediaTrack *trackid, int en);

  //==============================================
  // CSurf_OnInputMonitorChange
  int (*CSurf_OnInputMonitorChange)(MediaTrack *trackid, int monitor);

  //==============================================
  // CSurf_OnInputMonitorChangeEx
  int (*CSurf_OnInputMonitorChangeEx)(MediaTrack *trackid, int monitor,
                                      bool allowgang);

  //==============================================
  // CSurf_OnMuteChange
  bool (*CSurf_OnMuteChange)(MediaTrack *trackid, int mute);

  //==============================================
  // CSurf_OnMuteChangeEx
  bool (*CSurf_OnMuteChangeEx)(MediaTrack *trackid, int mute, bool allowgang);

  //==============================================
  // CSurf_OnOscControlMessage
  void (*CSurf_OnOscControlMessage)(const char *msg, const float *arg);

  //==============================================
  // CSurf_OnPanChange
  double (*CSurf_OnPanChange)(MediaTrack *trackid, double pan, bool relative);

  //==============================================
  // CSurf_OnPanChangeEx
  double (*CSurf_OnPanChangeEx)(MediaTrack *trackid, double pan, bool relative,
                                bool allowGang);

  //==============================================
  // CSurf_OnPause
  void (*CSurf_OnPause)();

  //==============================================
  // CSurf_OnPlay
  void (*CSurf_OnPlay)();

  //==============================================
  // CSurf_OnPlayRateChange
  void (*CSurf_OnPlayRateChange)(double playrate);

  //==============================================
  // CSurf_OnRecArmChange
  bool (*CSurf_OnRecArmChange)(MediaTrack *trackid, int recarm);

  //==============================================
  // CSurf_OnRecArmChangeEx
  bool (*CSurf_OnRecArmChangeEx)(MediaTrack *trackid, int recarm,
                                 bool allowgang);

  //==============================================
  // CSurf_OnRecord
  void (*CSurf_OnRecord)();

  //==============================================
  // CSurf_OnRecvPanChange
  double (*CSurf_OnRecvPanChange)(MediaTrack *trackid, int recv_index,
                                  double pan, bool relative);

  //==============================================
  // CSurf_OnRecvVolumeChange
  double (*CSurf_OnRecvVolumeChange)(MediaTrack *trackid, int recv_index,
                                     double volume, bool relative);

  //==============================================
  // CSurf_OnRew
  void (*CSurf_OnRew)(int seekplay);

  //==============================================
  // CSurf_OnRewFwd
  void (*CSurf_OnRewFwd)(int seekplay, int dir);

  //==============================================
  // CSurf_OnScroll
  void (*CSurf_OnScroll)(int xdir, int ydir);

  //==============================================
  // CSurf_OnSelectedChange
  bool (*CSurf_OnSelectedChange)(MediaTrack *trackid, int selected);

  //==============================================
  // CSurf_OnSendPanChange
  double (*CSurf_OnSendPanChange)(MediaTrack *trackid, int send_index,
                                  double pan, bool relative);

  //==============================================
  // CSurf_OnSendVolumeChange
  double (*CSurf_OnSendVolumeChange)(MediaTrack *trackid, int send_index,
                                     double volume, bool relative);

  //==============================================
  // CSurf_OnSoloChange
  bool (*CSurf_OnSoloChange)(MediaTrack *trackid, int solo);

  //==============================================
  // CSurf_OnSoloChangeEx
  bool (*CSurf_OnSoloChangeEx)(MediaTrack *trackid, int solo, bool allowgang);

  //==============================================
  // CSurf_OnStop
  void (*CSurf_OnStop)();

  //==============================================
  // CSurf_OnTempoChange
  void (*CSurf_OnTempoChange)(double bpm);

  //==============================================
  // CSurf_OnTrackSelection
  void (*CSurf_OnTrackSelection)(MediaTrack *trackid);

  //==============================================
  // CSurf_OnVolumeChange
  double (*CSurf_OnVolumeChange)(MediaTrack *trackid, double volume,
                                 bool relative);

  //==============================================
  // CSurf_OnVolumeChangeEx
  double (*CSurf_OnVolumeChangeEx)(MediaTrack *trackid, double volume,
                                   bool relative, bool allowGang);

  //==============================================
  // CSurf_OnWidthChange
  double (*CSurf_OnWidthChange)(MediaTrack *trackid, double width,
                                bool relative);

  //==============================================
  // CSurf_OnWidthChangeEx
  double (*CSurf_OnWidthChangeEx)(MediaTrack *trackid, double width,
                                  bool relative, bool allowGang);

  //==============================================
  // CSurf_OnZoom
  void (*CSurf_OnZoom)(int xdir, int ydir);

  //==============================================
  // CSurf_ResetAllCachedVolPanStates
  void (*CSurf_ResetAllCachedVolPanStates)();

  //==============================================
  // CSurf_ScrubAmt
  void (*CSurf_ScrubAmt)(double amt);

  //==============================================
  // CSurf_SetAutoMode
  void (*CSurf_SetAutoMode)(int mode, IReaperControlSurface *ignoresurf);

  //==============================================
  // CSurf_SetPlayState
  void (*CSurf_SetPlayState)(bool play, bool pause, bool rec,
                             IReaperControlSurface *ignoresurf);

  //==============================================
  // CSurf_SetRepeatState
  void (*CSurf_SetRepeatState)(bool rep, IReaperControlSurface *ignoresurf);

  //==============================================
  // CSurf_SetSurfaceMute
  void (*CSurf_SetSurfaceMute)(MediaTrack *trackid, bool mute,
                               IReaperControlSurface *ignoresurf);

  //==============================================
  // CSurf_SetSurfacePan
  void (*CSurf_SetSurfacePan)(MediaTrack *trackid, double pan,
                              IReaperControlSurface *ignoresurf);

  //==============================================
  // CSurf_SetSurfaceRecArm
  void (*CSurf_SetSurfaceRecArm)(MediaTrack *trackid, bool recarm,
                                 IReaperControlSurface *ignoresurf);

  //==============================================
  // CSurf_SetSurfaceSelected
  void (*CSurf_SetSurfaceSelected)(MediaTrack *trackid, bool selected,
                                   IReaperControlSurface *ignoresurf);

  //==============================================
  // CSurf_SetSurfaceSolo
  void (*CSurf_SetSurfaceSolo)(MediaTrack *trackid, bool solo,
                               IReaperControlSurface *ignoresurf);

  //==============================================
  // CSurf_SetSurfaceVolume
  void (*CSurf_SetSurfaceVolume)(MediaTrack *trackid, double volume,
                                 IReaperControlSurface *ignoresurf);

  //==============================================
  // CSurf_SetTrackListChange
  void (*CSurf_SetTrackListChange)();

  //==============================================
  // CSurf_TrackFromID
  MediaTrack *(*CSurf_TrackFromID)(int idx, bool mcpView);

  //==============================================
  // CSurf_TrackToID
  int (*CSurf_TrackToID)(MediaTrack *track, bool mcpView);

  //==============================================
  // DB2SLIDER
  double (*DB2SLIDER)(double x);

  //==============================================
  // DeleteActionShortcut
  // Delete the specific shortcut for the given command ID.
  // See CountActionShortcuts, GetActionShortcutDesc, DoActionShortcutDialog.
  bool (*DeleteActionShortcut)(KbdSectionInfo *section, int cmdID,
                               int shortcutidx);

  //==============================================
  // DeleteEnvelopePointEx
  // Delete an envelope point. If setting multiple points at once, set
  // noSort=true, and call Envelope_SortPoints when done. autoitem_idx=-1 for
  // the underlying envelope, 0 for the first automation item on the envelope,
  // etc. For automation items, pass autoitem_idx|0x10000000 to base ptidx on
  // the number of points in one full loop iteration, even if the automation
  // item is trimmed so that not all points are visible. Otherwise, ptidx will
  // be based on the number of visible points in the automation item, including
  // all loop iterations. See CountEnvelopePointsEx, GetEnvelopePointEx,
  // SetEnvelopePointEx, InsertEnvelopePointEx.
  bool (*DeleteEnvelopePointEx)(TrackEnvelope *envelope, int autoitem_idx,
                                int ptidx);

  //==============================================
  // DeleteEnvelopePointRange
  // Delete a range of envelope points. See DeleteEnvelopePointRangeEx,
  // DeleteEnvelopePointEx.
  bool (*DeleteEnvelopePointRange)(TrackEnvelope *envelope, double time_start,
                                   double time_end);

  //==============================================
  // DeleteEnvelopePointRangeEx
  // Delete a range of envelope points. autoitem_idx=-1 for the underlying
  // envelope, 0 for the first automation item on the envelope, etc.
  bool (*DeleteEnvelopePointRangeEx)(TrackEnvelope *envelope, int autoitem_idx,
                                     double time_start, double time_end);

  //==============================================
  // DeleteExtState
  // Delete the extended state value for a specific section and key.
  // persist=true means the value should remain deleted the next time REAPER is
  // opened. See SetExtState, GetExtState, HasExtState.
  void (*DeleteExtState)(const char *section, const char *key, bool persist);

  //==============================================
  // DeleteProjectMarker
  // Delete a marker.  proj==NULL for the active project.
  bool (*DeleteProjectMarker)(ReaProject *proj, int markrgnindexnumber,
                              bool isrgn);

  //==============================================
  // DeleteProjectMarkerByIndex
  // Differs from DeleteProjectMarker only in that markrgnidx is 0 for the first
  // marker/region, 1 for the next, etc (see EnumProjectMarkers3), rather than
  // representing the displayed marker/region ID number (see SetProjectMarker4).
  bool (*DeleteProjectMarkerByIndex)(ReaProject *proj, int markrgnidx);

  //==============================================
  // DeleteTakeMarker
  // Delete a take marker. Note that idx will change for all following take
  // markers. See GetNumTakeMarkers, GetTakeMarker, SetTakeMarker
  bool (*DeleteTakeMarker)(MediaItem_Take *take, int idx);

  //==============================================
  // DeleteTakeStretchMarkers
  // Deletes one or more stretch markers. Returns number of stretch markers
  // deleted.
  int (*DeleteTakeStretchMarkers)(MediaItem_Take *take, int idx,
                                  const int *countInOptional);

  //==============================================
  // DeleteTempoTimeSigMarker
  // Delete a tempo/time signature marker.
  bool (*DeleteTempoTimeSigMarker)(ReaProject *project, int markerindex);

  //==============================================
  // DeleteTrack
  // deletes a track
  void (*DeleteTrack)(MediaTrack *tr);

  //==============================================
  // DeleteTrackMediaItem
  bool (*DeleteTrackMediaItem)(MediaTrack *tr, MediaItem *it);

  //==============================================
  // DestroyAudioAccessor
  // Destroy an audio accessor. Must only call from the main thread. See
  // CreateTakeAudioAccessor, CreateTrackAudioAccessor,
  // AudioAccessorStateChanged, GetAudioAccessorStartTime,
  // GetAudioAccessorEndTime, GetAudioAccessorSamples.
  void (*DestroyAudioAccessor)(AudioAccessor *accessor);

  //==============================================
  // DestroyLocalOscHandler
  // See CreateLocalOscHandler, SendLocalOscMessage.
  void (*DestroyLocalOscHandler)(void *local_osc_handler);

  //==============================================
  // DoActionShortcutDialog
  // Open the action shortcut dialog to edit or add a shortcut for the given
  // command ID. If (shortcutidx >= 0 && shortcutidx < CountActionShortcuts()),
  // that specific shortcut will be replaced, otherwise a new shortcut will be
  // added. See CountActionShortcuts, GetActionShortcutDesc,
  // DeleteActionShortcut.
  bool (*DoActionShortcutDialog)(HWND hwnd, KbdSectionInfo *section, int cmdID,
                                 int shortcutidx);

  //==============================================
  // Dock_UpdateDockID
  // updates preference for docker window ident_str to be in dock whichDock on
  // next open
  void (*Dock_UpdateDockID)(const char *ident_str, int whichDock);

  //==============================================
  // DockGetPosition
  // -1=not found, 0=bottom, 1=left, 2=top, 3=right, 4=floating
  int (*DockGetPosition)(int whichDock);

  //==============================================
  // DockIsChildOfDock
  // returns dock index that contains hwnd, or -1
  int (*DockIsChildOfDock)(HWND hwnd, bool *isFloatingDockerOut);

  //==============================================
  // DockWindowActivate
  void (*DockWindowActivate)(HWND hwnd);

  //==============================================
  // DockWindowAdd
  void (*DockWindowAdd)(HWND hwnd, const char *name, int pos, bool allowShow);

  //==============================================
  // DockWindowAddEx
  void (*DockWindowAddEx)(HWND hwnd, const char *name, const char *identstr,
                          bool allowShow);

  //==============================================
  // DockWindowRefresh
  void (*DockWindowRefresh)();

  //==============================================
  // DockWindowRefreshForHWND
  void (*DockWindowRefreshForHWND)(HWND hwnd);

  //==============================================
  // DockWindowRemove
  void (*DockWindowRemove)(HWND hwnd);

  //==============================================
  // DuplicateCustomizableMenu
  // Populate destmenu with all the entries and submenus found in srcmenu
  bool (*DuplicateCustomizableMenu)(void *srcmenu, void *destmenu);

  //==============================================
  // EditTempoTimeSigMarker
  // Open the tempo/time signature marker editor dialog.
  bool (*EditTempoTimeSigMarker)(ReaProject *project, int markerindex);

  //==============================================
  // EnsureNotCompletelyOffscreen
  // call with a saved window rect for your window and it'll correct any
  // positioning info.
  void (*EnsureNotCompletelyOffscreen)(RECT *rInOut);

  //==============================================
  // EnumerateFiles
  // List the files in the "path" directory. Returns NULL/nil when all files
  // have been listed. Use fileindex = -1 to force re-read of directory
  // (invalidate cache). See EnumerateSubdirectories
  const char *(*EnumerateFiles)(const char *path, int fileindex);

  //==============================================
  // EnumerateSubdirectories
  // List the subdirectories in the "path" directory. Use subdirindex = -1 to
  // force re-read of directory (invalidate cache). Returns NULL/nil when all
  // subdirectories have been listed. See EnumerateFiles
  const char *(*EnumerateSubdirectories)(const char *path, int subdirindex);

  //==============================================
  // EnumPitchShiftModes
  // Start querying modes at 0, returns FALSE when no more modes possible, sets
  // strOut to NULL if a mode is currently unsupported
  bool (*EnumPitchShiftModes)(int mode, const char **strOut);

  //==============================================
  // EnumPitchShiftSubModes
  // Returns submode name, or NULL
  const char *(*EnumPitchShiftSubModes)(int mode, int submode);

  //==============================================
  // EnumProjectMarkers
  int (*EnumProjectMarkers)(int idx, bool *isrgnOut, double *posOut,
                            double *rgnendOut, const char **nameOut,
                            int *markrgnindexnumberOut);

  //==============================================
  // EnumProjectMarkers2
  int (*EnumProjectMarkers2)(ReaProject *proj, int idx, bool *isrgnOut,
                             double *posOut, double *rgnendOut,
                             const char **nameOut, int *markrgnindexnumberOut);

  //==============================================
  // EnumProjectMarkers3
  int (*EnumProjectMarkers3)(ReaProject *proj, int idx, bool *isrgnOut,
                             double *posOut, double *rgnendOut,
                             const char **nameOut, int *markrgnindexnumberOut,
                             int *colorOut);

  //==============================================
  // EnumProjects
  // idx=-1 for current project,projfn can be NULL if not interested in
  // filename. use idx 0x40000000 for currently rendering project, if any.
  ReaProject *(*EnumProjects)(int idx, char *projfnOutOptional,
                              int projfnOutOptional_sz);

  //==============================================
  // EnumProjExtState
  // Enumerate the data stored with the project for a specific extname. Returns
  // false when there is no more data. See SetProjExtState, GetProjExtState.
  bool (*EnumProjExtState)(ReaProject *proj, const char *extname, int idx,
                           char *keyOutOptional, int keyOutOptional_sz,
                           char *valOutOptional, int valOutOptional_sz);

  //==============================================
  // EnumRegionRenderMatrix
  // Enumerate which tracks will be rendered within this region when using the
  // region render matrix. When called with rendertrack==0, the function returns
  // the first track that will be rendered (which may be the master track);
  // rendertrack==1 will return the next track rendered, and so on. The function
  // returns NULL when there are no more tracks that will be rendered within
  // this region.
  MediaTrack *(*EnumRegionRenderMatrix)(ReaProject *proj, int regionindex,
                                        int rendertrack);

  //==============================================
  // EnumTrackMIDIProgramNames
  // returns false if there are no plugins on the track that support MIDI
  // programs,or if all programs have been enumerated
  bool (*EnumTrackMIDIProgramNames)(int track, int programNumber,
                                    char *programName, int programName_sz);

  //==============================================
  // EnumTrackMIDIProgramNamesEx
  // returns false if there are no plugins on the track that support MIDI
  // programs,or if all programs have been enumerated
  bool (*EnumTrackMIDIProgramNamesEx)(ReaProject *proj, MediaTrack *track,
                                      int programNumber, char *programName,
                                      int programName_sz);

  //==============================================
  // Envelope_Evaluate
  // Get the effective envelope value at a given time position. samplesRequested
  // is how long the caller expects until the next call to Envelope_Evaluate
  // (often, the buffer block size). The return value is how many samples beyond
  // that time position that the returned values are valid. dVdS is the change
  // in value per sample (first derivative), ddVdS is the second derivative,
  // dddVdS is the third derivative. See GetEnvelopeScalingMode.
  int (*Envelope_Evaluate)(TrackEnvelope *envelope, double time,
                           double samplerate, int samplesRequested,
                           double *valueOutOptional, double *dVdSOutOptional,
                           double *ddVdSOutOptional, double *dddVdSOutOptional);

  //==============================================
  // Envelope_FormatValue
  // Formats the value of an envelope to a user-readable form
  void (*Envelope_FormatValue)(TrackEnvelope *env, double value, char *bufOut,
                               int bufOut_sz);

  //==============================================
  // Envelope_GetParentTake
  // If take envelope, gets the take from the envelope. If FX, indexOutOptional
  // set to FX index, index2OutOptional set to parameter index, otherwise -1.
  MediaItem_Take *(*Envelope_GetParentTake)(TrackEnvelope *env,
                                            int *indexOutOptional,
                                            int *index2OutOptional);

  //==============================================
  // Envelope_GetParentTrack
  // If track envelope, gets the track from the envelope. If FX,
  // indexOutOptional set to FX index, index2OutOptional set to parameter index,
  // otherwise -1.
  MediaTrack *(*Envelope_GetParentTrack)(TrackEnvelope *env,
                                         int *indexOutOptional,
                                         int *index2OutOptional);

  //==============================================
  // Envelope_SortPoints
  // Sort envelope points by time. See SetEnvelopePoint, InsertEnvelopePoint.
  bool (*Envelope_SortPoints)(TrackEnvelope *envelope);

  //==============================================
  // Envelope_SortPointsEx
  // Sort envelope points by time. autoitem_idx=-1 for the underlying envelope,
  // 0 for the first automation item on the envelope, etc. See SetEnvelopePoint,
  // InsertEnvelopePoint.
  bool (*Envelope_SortPointsEx)(TrackEnvelope *envelope, int autoitem_idx);

  //==============================================
  // ExecProcess
  // Executes command line, returns NULL on total failure, otherwise the return
  // value, a newline, and then the output of the command. If timeoutmsec is 0,
  // command will be allowed to run indefinitely (recommended for large amounts
  // of returned output). timeoutmsec is -1 for no wait/terminate, -2 for no
  // wait and minimize
  const char *(*ExecProcess)(const char *cmdline, int timeoutmsec);

  //==============================================
  // file_exists
  // returns true if path points to a valid, readable file
  bool (*file_exists)(const char *path);

  //==============================================
  // FindTempoTimeSigMarker
  // Find the tempo/time signature marker that falls at or before this time
  // position (the marker that is in effect as of this time position).
  int (*FindTempoTimeSigMarker)(ReaProject *project, double time);

  //==============================================
  // format_timestr
  // Format tpos (which is time in seconds) as hh:mm:ss.sss. See
  // format_timestr_pos, format_timestr_len.
  void (*format_timestr)(double tpos, char *buf, int buf_sz);

  //==============================================
  // format_timestr_len
  // time formatting mode overrides: -1=proj default.
  // 0=time
  // 1=measures.beats + time
  // 2=measures.beats
  // 3=seconds
  // 4=samples
  // 5=h:m:s:f
  // offset is start of where the length will be calculated from
  void (*format_timestr_len)(double tpos, char *buf, int buf_sz, double offset,
                             int modeoverride);

  //==============================================
  // format_timestr_pos
  // time formatting mode overrides: -1=proj default.
  // 0=time
  // 1=measures.beats + time
  // 2=measures.beats
  // 3=seconds
  // 4=samples
  // 5=h:m:s:f
  //
  void (*format_timestr_pos)(double tpos, char *buf, int buf_sz,
                             int modeoverride);

  //==============================================
  // FreeHeapPtr
  // free heap memory returned from a Reaper API function
  void (*FreeHeapPtr)(void *ptr);

  //==============================================
  // genGuid
  void (*genGuid)(GUID *g);

  //==============================================
  // get_config_var
  void *(*get_config_var)(const char *name, int *szOut);

  //==============================================
  // get_config_var_string
  // gets ini configuration variable value as string
  bool (*get_config_var_string)(const char *name, char *bufOut, int bufOut_sz);

  //==============================================
  // get_ini_file
  // Get reaper.ini full filename.
  const char *(*get_ini_file)();

  //==============================================
  // get_midi_config_var
  // Deprecated.
  void *(*get_midi_config_var)(const char *name, int *szOut);

  //==============================================
  // GetActionShortcutDesc
  // Get the text description of a specific shortcut for the given command ID.
  // See CountActionShortcuts,DeleteActionShortcut,DoActionShortcutDialog.
  bool (*GetActionShortcutDesc)(KbdSectionInfo *section, int cmdID,
                                int shortcutidx, char *desc, int desclen);

  //==============================================
  // GetActiveTake
  // get the active take in this item
  MediaItem_Take *(*GetActiveTake)(MediaItem *item);

  //==============================================
  // GetAllProjectPlayStates
  // returns the bitwise OR of all project play states (1=playing, 2=pause,
  // 4=recording)
  int (*GetAllProjectPlayStates)(ReaProject *ignoreProject);

  //==============================================
  // GetAppVersion
  // Returns app version which may include an OS/arch signifier, such as: "6.17"
  // (windows 32-bit), "6.17/x64" (windows 64-bit), "6.17/OSX64" (macOS 64-bit
  // Intel), "6.17/OSX" (macOS 32-bit), "6.17/macOS-arm64", "6.17/linux-x86_64",
  // "6.17/linux-i686", "6.17/linux-aarch64", "6.17/linux-armv7l", etc
  const char *(*GetAppVersion)();

  //==============================================
  // GetArmedCommand
  // gets the currently armed command and section name (returns 0 if nothing
  // armed). section name is empty-string for main section.
  int (*GetArmedCommand)(char *secOut, int secOut_sz);

  //==============================================
  // GetAudioAccessorEndTime
  // Get the end time of the audio that can be returned from this accessor. See
  // CreateTakeAudioAccessor, CreateTrackAudioAccessor, DestroyAudioAccessor,
  // AudioAccessorStateChanged, GetAudioAccessorStartTime,
  // GetAudioAccessorSamples.
  double (*GetAudioAccessorEndTime)(AudioAccessor *accessor);

  //==============================================
  // GetAudioAccessorHash
  // Deprecated. See AudioAccessorStateChanged instead.
  void (*GetAudioAccessorHash)(AudioAccessor *accessor, char *hashNeed128);

  //==============================================
  // GetAudioAccessorSamples
  // Get a block of samples from the audio accessor. Samples are extracted
  // immediately pre-FX, and returned interleaved (first sample of first
  // channel, first sample of second channel...). Returns 0 if no audio, 1 if
  // audio, -1 on error. See CreateTakeAudioAccessor, CreateTrackAudioAccessor,
  // DestroyAudioAccessor, AudioAccessorStateChanged, GetAudioAccessorStartTime,
  // GetAudioAccessorEndTime.//
  //
  // This function has special handling in Python, and only returns two objects,
  // the API function return value, and the sample buffer. Example usage:
  //
  // <code>tr = RPR_GetTrack(0, 0)
  // aa = RPR_CreateTrackAudioAccessor(tr)
  // buf = list([0]*2*1024) # 2 channels, 1024 samples each, initialized to zero
  // pos = 0.0
  // (ret, buf) = GetAudioAccessorSamples(aa, 44100, 2, pos, 1024, buf)
  // # buf now holds the first 2*1024 audio samples from the track.
  // # typically GetAudioAccessorSamples() would be called within a loop,
  // increasing pos each time.
  // </code>
  int (*GetAudioAccessorSamples)(AudioAccessor *accessor, int samplerate,
                                 int numchannels, double starttime_sec,
                                 int numsamplesperchannel,
                                 double *samplebuffer);

  //==============================================
  // GetAudioAccessorStartTime
  // Get the start time of the audio that can be returned from this accessor.
  // See CreateTakeAudioAccessor, CreateTrackAudioAccessor,
  // DestroyAudioAccessor, AudioAccessorStateChanged, GetAudioAccessorEndTime,
  // GetAudioAccessorSamples.
  double (*GetAudioAccessorStartTime)(AudioAccessor *accessor);

  //==============================================
  // GetAudioDeviceInfo
  // get information about the currently open audio device. attribute can be
  // MODE, IDENT_IN, IDENT_OUT, BSIZE, SRATE, BPS. returns false if unknown
  // attribute or device not open.
  bool (*GetAudioDeviceInfo)(const char *attribute, char *desc, int desc_sz);

  //==============================================
  // GetColorTheme
  // Deprecated, see GetColorThemeStruct.
  INT_PTR (*GetColorTheme)(int idx, int defval);

  //==============================================
  // GetColorThemeStruct
  // returns the whole color theme (icontheme.h) and the size
  void *(*GetColorThemeStruct)(int *szOut);

  //==============================================
  // GetConfigWantsDock
  // gets the dock ID desired by ident_str, if any
  int (*GetConfigWantsDock)(const char *ident_str);

  //==============================================
  // GetContextMenu
  // gets context menus. submenu 0:trackctl, 1:mediaitems, 2:ruler, 3:empty
  // track area
  HMENU (*GetContextMenu)(int idx);

  //==============================================
  // GetCurrentProjectInLoadSave
  // returns current project if in load/save (usually only used from
  // project_config_extension_t)
  ReaProject *(*GetCurrentProjectInLoadSave)();

  //==============================================
  // GetCursorContext
  // return the current cursor context: 0 if track panels, 1 if items, 2 if
  // envelopes, otherwise unknown
  int (*GetCursorContext)();

  //==============================================
  // GetCursorContext2
  // 0 if track panels, 1 if items, 2 if envelopes, otherwise unknown (unlikely
  // when want_last_valid is true)
  int (*GetCursorContext2)(bool want_last_valid);

  //==============================================
  // GetCursorPosition
  // edit cursor position
  double (*GetCursorPosition)();

  //==============================================
  // GetCursorPositionEx
  // edit cursor position
  double (*GetCursorPositionEx)(ReaProject *proj);

  //==============================================
  // GetDisplayedMediaItemColor
  // see GetDisplayedMediaItemColor2.
  int (*GetDisplayedMediaItemColor)(MediaItem *item);

  //==============================================
  // GetDisplayedMediaItemColor2
  // Returns the custom take, item, or track color that is used (according to
  // the user preference) to color the media item. The returned color is OS
  // dependent|0x01000000 (i.e. ColorToNative(r,g,b)|0x01000000), so a return of
  // zero means "no color", not black.
  int (*GetDisplayedMediaItemColor2)(MediaItem *item, MediaItem_Take *take);

  //==============================================
  // GetEnvelopeInfo_Value
  // Gets an envelope numerical-value attribute:
  // I_TCPY : int *, Y offset of envelope relative to parent track (may be
  // separate lane or overlap with track contents)I_TCPH : int *, visible height
  // of envelopeI_TCPY_USED : int *, Y offset of envelope relative to parent
  // track, exclusive of paddingI_TCPH_USED : int *, visible height of envelope,
  // exclusive of paddingP_TRACK : MediaTrack *, parent track pointer (if
  // any)P_ITEM : MediaItem *, parent item pointer (if any)P_TAKE :
  // MediaItem_Take *, parent take pointer (if any)
  double (*GetEnvelopeInfo_Value)(TrackEnvelope *tr, const char *parmname);

  //==============================================
  // GetEnvelopeName
  bool (*GetEnvelopeName)(TrackEnvelope *env, char *bufOut, int bufOut_sz);

  //==============================================
  // GetEnvelopePoint
  // Get the attributes of an envelope point. See GetEnvelopePointEx.
  bool (*GetEnvelopePoint)(TrackEnvelope *envelope, int ptidx,
                           double *timeOutOptional, double *valueOutOptional,
                           int *shapeOutOptional, double *tensionOutOptional,
                           bool *selectedOutOptional);

  //==============================================
  // GetEnvelopePointByTime
  // Returns the envelope point at or immediately prior to the given time
  // position. See GetEnvelopePointByTimeEx.
  int (*GetEnvelopePointByTime)(TrackEnvelope *envelope, double time);

  //==============================================
  // GetEnvelopePointByTimeEx
  // Returns the envelope point at or immediately prior to the given time
  // position. autoitem_idx=-1 for the underlying envelope, 0 for the first
  // automation item on the envelope, etc. For automation items, pass
  // autoitem_idx|0x10000000 to base ptidx on the number of points in one full
  // loop iteration, even if the automation item is trimmed so that not all
  // points are visible. Otherwise, ptidx will be based on the number of visible
  // points in the automation item, including all loop iterations. See
  // GetEnvelopePointEx, SetEnvelopePointEx, InsertEnvelopePointEx,
  // DeleteEnvelopePointEx.
  int (*GetEnvelopePointByTimeEx)(TrackEnvelope *envelope, int autoitem_idx,
                                  double time);

  //==============================================
  // GetEnvelopePointEx
  // Get the attributes of an envelope point.
  // autoitem_idx=-1 for the underlying envelope, 0 for the first automation
  // item on the envelope, etc. For automation items, pass
  // autoitem_idx|0x10000000 to base ptidx on the number of points in one full
  // loop iteration, even if the automation item is trimmed so that not all
  // points are visible. Otherwise, ptidx will be based on the number of visible
  // points in the automation item, including all loop iterations. See
  // CountEnvelopePointsEx, SetEnvelopePointEx, InsertEnvelopePointEx,
  // DeleteEnvelopePointEx.
  bool (*GetEnvelopePointEx)(TrackEnvelope *envelope, int autoitem_idx,
                             int ptidx, double *timeOutOptional,
                             double *valueOutOptional, int *shapeOutOptional,
                             double *tensionOutOptional,
                             bool *selectedOutOptional);

  //==============================================
  // GetEnvelopeScalingMode
  // Returns the envelope scaling mode: 0=no scaling, 1=fader scaling. All API
  // functions deal with raw envelope point values, to convert raw from/to
  // scaled values see ScaleFromEnvelopeMode, ScaleToEnvelopeMode.
  int (*GetEnvelopeScalingMode)(TrackEnvelope *env);

  //==============================================
  // GetEnvelopeStateChunk
  // Gets the RPPXML state of an envelope, returns true if successful. Undo flag
  // is a performance/caching hint.
  bool (*GetEnvelopeStateChunk)(TrackEnvelope *env, char *strNeedBig,
                                int strNeedBig_sz, bool isundoOptional);

  //==============================================
  // GetExePath
  // returns path of REAPER.exe (not including EXE), i.e. C:\Program
  // Files\REAPER
  const char *(*GetExePath)();

  //==============================================
  // GetExtState
  // Get the extended state value for a specific section and key. See
  // SetExtState, DeleteExtState, HasExtState.
  const char *(*GetExtState)(const char *section, const char *key);

  //==============================================
  // GetFocusedFX
  // This function is deprecated (returns GetFocusedFX2()&3), see GetFocusedFX2.
  int (*GetFocusedFX)(int *tracknumberOut, int *itemnumberOut,
                      int *fxnumberOut);

  //==============================================
  // GetFocusedFX2
  // Return value has 1 set if track FX, 2 if take/item FX, 4 set if FX is no
  // longer focused but still open. tracknumber==0 means the master track, 1
  // means track 1, etc. itemnumber is zero-based (or -1 if not an item). For
  // interpretation of fxnumber, see GetLastTouchedFX.
  int (*GetFocusedFX2)(int *tracknumberOut, int *itemnumberOut,
                       int *fxnumberOut);

  //==============================================
  // GetFreeDiskSpaceForRecordPath
  // returns free disk space in megabytes, pathIdx 0 for normal, 1 for
  // alternate.
  int (*GetFreeDiskSpaceForRecordPath)(ReaProject *proj, int pathidx);

  //==============================================
  // GetFXEnvelope
  // Returns the FX parameter envelope. If the envelope does not exist and
  // create=true, the envelope will be created.
  TrackEnvelope *(*GetFXEnvelope)(MediaTrack *track, int fxindex,
                                  int parameterindex, bool create);

  //==============================================
  // GetGlobalAutomationOverride
  // return -1=no override, 0=trim/read, 1=read, 2=touch, 3=write, 4=latch,
  // 5=bypass
  int (*GetGlobalAutomationOverride)();

  //==============================================
  // GetHZoomLevel
  // returns pixels/second
  double (*GetHZoomLevel)();

  //==============================================
  // GetIconThemePointer
  // returns a named icontheme entry
  void *(*GetIconThemePointer)(const char *name);

  //==============================================
  // GetIconThemePointerForDPI
  // returns a named icontheme entry for a given DPI-scaling (256=1:1). Note:
  // the return value should not be stored, it should be queried at each paint!
  // Querying name=NULL returns the start of the structure
  void *(*GetIconThemePointerForDPI)(const char *name, int dpisc);

  //==============================================
  // GetIconThemeStruct
  // returns a pointer to the icon theme (icontheme.h) and the size of that
  // struct
  void *(*GetIconThemeStruct)(int *szOut);

  //==============================================
  // GetInputChannelName
  const char *(*GetInputChannelName)(int channelIndex);

  //==============================================
  // GetInputOutputLatency
  // Gets the audio device input/output latency in samples
  void (*GetInputOutputLatency)(int *inputlatencyOut, int *outputLatencyOut);

  //==============================================
  // GetItemEditingTime2
  // returns time of relevant edit, set which_item to the pcm_source (if
  // applicable), flags (if specified) will be set to 1 for edge resizing, 2 for
  // fade change, 4 for item move, 8 for item slip edit (edit cursor time or
  // start of item)
  double (*GetItemEditingTime2)(PCM_source **which_itemOut, int *flagsOut);

  //==============================================
  // GetItemFromPoint
  // Returns the first item at the screen coordinates specified. If allow_locked
  // is false, locked items are ignored. If takeOutOptional specified, returns
  // the take hit.
  MediaItem *(*GetItemFromPoint)(int screen_x, int screen_y, bool allow_locked,
                                 MediaItem_Take **takeOutOptional);

  //==============================================
  // GetItemProjectContext
  ReaProject *(*GetItemProjectContext)(MediaItem *item);

  //==============================================
  // GetItemStateChunk
  // Gets the RPPXML state of an item, returns true if successful. Undo flag is
  // a performance/caching hint.
  bool (*GetItemStateChunk)(MediaItem *item, char *strNeedBig,
                            int strNeedBig_sz, bool isundoOptional);

  //==============================================
  // GetLastColorThemeFile
  const char *(*GetLastColorThemeFile)();

  //==============================================
  // GetLastMarkerAndCurRegion
  // Get the last project marker before time, and/or the project region that
  // includes time. markeridx and regionidx are returned not necessarily as the
  // displayed marker/region index, but as the index that can be passed to
  // EnumProjectMarkers. Either or both of markeridx and regionidx may be NULL.
  // See EnumProjectMarkers.
  void (*GetLastMarkerAndCurRegion)(ReaProject *proj, double time,
                                    int *markeridxOut, int *regionidxOut);

  //==============================================
  // GetLastTouchedFX
  // Returns true if the last touched FX parameter is valid, false otherwise.
  // The low word of tracknumber is the 1-based track index -- 0 means the
  // master track, 1 means track 1, etc. If the high word of tracknumber is
  // nonzero, it refers to the 1-based item index (1 is the first item on the
  // track, etc). For track FX, the low 24 bits of fxnumber refer to the FX
  // index in the chain, and if the next 8 bits are 01, then the FX is record
  // FX. For item FX, the low word defines the FX index in the chain, and the
  // high word defines the take number.
  bool (*GetLastTouchedFX)(int *tracknumberOut, int *fxnumberOut,
                           int *paramnumberOut);

  //==============================================
  // GetLastTouchedTrack
  MediaTrack *(*GetLastTouchedTrack)();

  //==============================================
  // GetMainHwnd
  HWND (*GetMainHwnd)();

  //==============================================
  // GetMasterMuteSoloFlags
  // &1=master mute,&2=master solo. This is deprecated as you can just query the
  // master track as well.
  int (*GetMasterMuteSoloFlags)();

  //==============================================
  // GetMasterTrack
  MediaTrack *(*GetMasterTrack)(ReaProject *proj);

  //==============================================
  // GetMasterTrackVisibility
  // returns &1 if the master track is visible in the TCP, &2 if visible in the
  // mixer. See SetMasterTrackVisibility.
  int (*GetMasterTrackVisibility)();

  //==============================================
  // GetMaxMidiInputs
  // returns max dev for midi inputs/outputs
  int (*GetMaxMidiInputs)();

  //==============================================
  // GetMaxMidiOutputs
  int (*GetMaxMidiOutputs)();

  //==============================================
  // GetMediaFileMetadata
  // Get text-based metadata from a media file for a given identifier. Call with
  // identifier="" to list all identifiers contained in the file, separated by
  // newlines. May return "[Binary data]" for metadata that REAPER doesn't
  // handle.
  int (*GetMediaFileMetadata)(PCM_source *mediaSource, const char *identifier,
                              char *bufOutNeedBig, int bufOutNeedBig_sz);

  //==============================================
  // GetMediaItem
  // get an item from a project by item count (zero-based) (proj=0 for active
  // project)
  MediaItem *(*GetMediaItem)(ReaProject *proj, int itemidx);

  //==============================================
  // GetMediaItem_Track
  // Get parent track of media item
  MediaTrack *(*GetMediaItem_Track)(MediaItem *item);

  //==============================================
  // GetMediaItemInfo_Value
  // Get media item numerical-value attributes.
  // B_MUTE : bool * : muted (item solo overrides). setting this value will
  // clear C_MUTE_SOLO. B_MUTE_ACTUAL : bool * : muted (ignores solo). setting
  // this value will not affect C_MUTE_SOLO. C_MUTE_SOLO : char * : solo
  // override (-1=soloed, 0=no override, 1=unsoloed). note that this API does
  // not automatically unsolo other items when soloing (nor clear the unsolos
  // when clearing the last soloed item), it must be done by the caller via
  // action or via this API. B_LOOPSRC : bool * : loop source B_ALLTAKESPLAY :
  // bool * : all takes play B_UISEL : bool * : selected in arrange view
  // C_BEATATTACHMODE : char * : item timebase, -1=track or project default,
  // 1=beats (position, length, rate), 2=beats (position only). for auto-stretch
  // timebase: C_BEATATTACHMODE=1, C_AUTOSTRETCH=1 C_AUTOSTRETCH: : char * :
  // auto-stretch at project tempo changes, 1=enabled, requires
  // C_BEATATTACHMODE=1 C_LOCK : char * : locked, &1=locked D_VOL : double * :
  // item volume,  0=-inf, 0.5=-6dB, 1=+0dB, 2=+6dB, etc D_POSITION : double * :
  // item position in seconds D_LENGTH : double * : item length in seconds
  // D_SNAPOFFSET : double * : item snap offset in seconds
  // D_FADEINLEN : double * : item manual fadein length in seconds
  // D_FADEOUTLEN : double * : item manual fadeout length in seconds
  // D_FADEINDIR : double * : item fadein curvature, -1..1
  // D_FADEOUTDIR : double * : item fadeout curvature, -1..1
  // D_FADEINLEN_AUTO : double * : item auto-fadein length in seconds, -1=no
  // auto-fadein D_FADEOUTLEN_AUTO : double * : item auto-fadeout length in
  // seconds, -1=no auto-fadeout C_FADEINSHAPE : int * : fadein shape, 0..6,
  // 0=linear C_FADEOUTSHAPE : int * : fadeout shape, 0..6, 0=linear I_GROUPID :
  // int * : group ID, 0=no group I_LASTY : int * : Y-position of track in
  // pixels (read-only) I_LASTH : int * : height in track in pixels (read-only)
  // I_CUSTOMCOLOR : int * : custom color, OS dependent color|0x100000 (i.e.
  // ColorToNative(r,g,b)|0x100000). If you do not |0x100000, then it will not
  // be used, but will store the color I_CURTAKE : int * : active take number
  // IP_ITEMNUMBER : int, item number on this track (read-only, returns the item
  // number directly) F_FREEMODE_Y : float * : free item positioning Y-position,
  // 0=top of track, 1=bottom of track (will never be 1) F_FREEMODE_H : float *
  // : free item positioning height, 0=no height, 1=full height of track (will
  // never be 0) P_TRACK : MediaTrack * (read-only)
  //
  double (*GetMediaItemInfo_Value)(MediaItem *item, const char *parmname);

  //==============================================
  // GetMediaItemNumTakes
  int (*GetMediaItemNumTakes)(MediaItem *item);

  //==============================================
  // GetMediaItemTake
  MediaItem_Take *(*GetMediaItemTake)(MediaItem *item, int tk);

  //==============================================
  // GetMediaItemTake_Item
  // Get parent item of media item take
  MediaItem *(*GetMediaItemTake_Item)(MediaItem_Take *take);

  //==============================================
  // GetMediaItemTake_Peaks
  // Gets block of peak samples to buf. Note that the peak samples are
  // interleaved, but in two or three blocks (maximums, then minimums, then
  // extra). Return value has 20 bits of returned sample count, then 4 bits of
  // output_mode (0xf00000), then a bit to signify whether extra_type was
  // available (0x1000000). extra_type can be 115 ('s') for spectral
  // information, which will return peak samples as integers with the low 15
  // bits frequency, next 14 bits tonality.
  int (*GetMediaItemTake_Peaks)(MediaItem_Take *take, double peakrate,
                                double starttime, int numchannels,
                                int numsamplesperchannel, int want_extra_type,
                                double *buf);

  //==============================================
  // GetMediaItemTake_Source
  // Get media source of media item take
  PCM_source *(*GetMediaItemTake_Source)(MediaItem_Take *take);

  //==============================================
  // GetMediaItemTake_Track
  // Get parent track of media item take
  MediaTrack *(*GetMediaItemTake_Track)(MediaItem_Take *take);

  //==============================================
  // GetMediaItemTakeByGUID
  MediaItem_Take *(*GetMediaItemTakeByGUID)(ReaProject *project,
                                            const GUID *guid);

  //==============================================
  // GetMediaItemTakeInfo_Value
  // Get media item take numerical-value attributes.
  // D_STARTOFFS : double * : start offset in source media, in seconds
  // D_VOL : double * : take volume, 0=-inf, 0.5=-6dB, 1=+0dB, 2=+6dB, etc,
  // negative if take polarity is flipped D_PAN : double * : take pan, -1..1
  // D_PANLAW : double * : take pan law, -1=default, 0.5=-6dB, 1.0=+0dB, etc
  // D_PLAYRATE : double * : take playback rate, 0.5=half speed, 1=normal,
  // 2=double speed, etc D_PITCH : double * : take pitch adjustment in
  // semitones, -12=one octave down, 0=normal, +12=one octave up, etc B_PPITCH :
  // bool * : preserve pitch when changing playback rate I_CHANMODE : int * :
  // channel mode, 0=normal, 1=reverse stereo, 2=downmix, 3=left, 4=right
  // I_PITCHMODE : int * : pitch shifter mode, -1=projext default, otherwise
  // high 2 bytes=shifter, low 2 bytes=parameter I_CUSTOMCOLOR : int * : custom
  // color, OS dependent color|0x100000 (i.e. ColorToNative(r,g,b)|0x100000). If
  // you do not |0x100000, then it will not be used, but will store the color
  // IP_TAKENUMBER : int : take number (read-only, returns the take number
  // directly) P_TRACK : pointer to MediaTrack (read-only) P_ITEM : pointer to
  // MediaItem (read-only) P_SOURCE : PCM_source *. Note that if setting this,
  // you should first retrieve the old source, set the new, THEN delete the old.
  //
  double (*GetMediaItemTakeInfo_Value)(MediaItem_Take *take,
                                       const char *parmname);

  //==============================================
  // GetMediaItemTrack
  MediaTrack *(*GetMediaItemTrack)(MediaItem *item);

  //==============================================
  // GetMediaSourceFileName
  // Copies the media source filename to typebuf. Note that in-project MIDI
  // media sources have no associated filename. See GetMediaSourceParent.
  void (*GetMediaSourceFileName)(PCM_source *source, char *filenamebuf,
                                 int filenamebuf_sz);

  //==============================================
  // GetMediaSourceLength
  // Returns the length of the source media. If the media source is beat-based,
  // the length will be in quarter notes, otherwise it will be in seconds.
  double (*GetMediaSourceLength)(PCM_source *source, bool *lengthIsQNOut);

  //==============================================
  // GetMediaSourceNumChannels
  // Returns the number of channels in the source media.
  int (*GetMediaSourceNumChannels)(PCM_source *source);

  //==============================================
  // GetMediaSourceParent
  // Returns the parent source, or NULL if src is the root source. This can be
  // used to retrieve the parent properties of sections or reversed sources for
  // example.
  PCM_source *(*GetMediaSourceParent)(PCM_source *src);

  //==============================================
  // GetMediaSourceSampleRate
  // Returns the sample rate. MIDI source media will return zero.
  int (*GetMediaSourceSampleRate)(PCM_source *source);

  //==============================================
  // GetMediaSourceType
  // copies the media source type ("WAV", "MIDI", etc) to typebuf
  void (*GetMediaSourceType)(PCM_source *source, char *typebuf, int typebuf_sz);

  //==============================================
  // GetMediaTrackInfo_Value
  // Get track numerical-value attributes.
  // B_MUTE : bool * : muted
  // B_PHASE : bool * : track phase inverted
  // B_RECMON_IN_EFFECT : bool * : record monitoring in effect (current
  // audio-thread playback state, read-only) IP_TRACKNUMBER : int : track number
  // 1-based, 0=not found, -1=master track (read-only, returns the int directly)
  // I_SOLO : int * : soloed, 0=not soloed, 1=soloed, 2=soloed in place, 5=safe
  // soloed, 6=safe soloed in place I_FXEN : int * : fx enabled, 0=bypassed,
  // !0=fx active I_RECARM : int * : record armed, 0=not record armed, 1=record
  // armed I_RECINPUT : int * : record input, <0=no input. if 4096 set, input is
  // MIDI and low 5 bits represent channel (0=all, 1-16=only chan), next 6 bits
  // represent physical input (63=all, 62=VKB). If 4096 is not set, low 10 bits
  // (0..1023) are input start channel (ReaRoute/Loopback start at 512). If 2048
  // is set, input is multichannel input (using track channel count), or if 1024
  // is set, input is stereo input, otherwise input is mono. I_RECMODE : int * :
  // record mode, 0=input, 1=stereo out, 2=none, 3=stereo out w/latency
  // compensation, 4=midi output, 5=mono out, 6=mono out w/ latency
  // compensation, 7=midi overdub, 8=midi replace I_RECMON : int * : record
  // monitoring, 0=off, 1=normal, 2=not when playing (tape style) I_RECMONITEMS
  // : int * : monitor items while recording, 0=off, 1=on I_AUTOMODE : int * :
  // track automation mode, 0=trim/off, 1=read, 2=touch, 3=write, 4=latch
  // I_NCHAN : int * : number of track channels, 2-64, even numbers only
  // I_SELECTED : int * : track selected, 0=unselected, 1=selected
  // I_WNDH : int * : current TCP window height in pixels including envelopes
  // (read-only) I_TCPH : int * : current TCP window height in pixels not
  // including envelopes (read-only) I_TCPY : int * : current TCP window
  // Y-position in pixels relative to top of arrange view (read-only) I_MCPX :
  // int * : current MCP X-position in pixels relative to mixer container I_MCPY
  // : int * : current MCP Y-position in pixels relative to mixer container
  // I_MCPW : int * : current MCP width in pixels
  // I_MCPH : int * : current MCP height in pixels
  // I_FOLDERDEPTH : int * : folder depth change, 0=normal, 1=track is a folder
  // parent, -1=track is the last in the innermost folder, -2=track is the last
  // in the innermost and next-innermost folders, etc I_FOLDERCOMPACT : int * :
  // folder compacted state (only valid on folders), 0=normal, 1=small, 2=tiny
  // children I_MIDIHWOUT : int * : track midi hardware output index,
  // <0=disabled, low 5 bits are which channels (0=all, 1-16), next 5 bits are
  // output device index (0-31) I_PERFFLAGS : int * : track performance flags,
  // &1=no media buffering, &2=no anticipative FX I_CUSTOMCOLOR : int * : custom
  // color, OS dependent color|0x100000 (i.e. ColorToNative(r,g,b)|0x100000). If
  // you do not |0x100000, then it will not be used, but will store the color
  // I_HEIGHTOVERRIDE : int * : custom height override for TCP window, 0 for
  // none, otherwise size in pixels B_HEIGHTLOCK : bool * : track height lock
  // (must set I_HEIGHTOVERRIDE before locking) D_VOL : double * : trim volume
  // of track, 0=-inf, 0.5=-6dB, 1=+0dB, 2=+6dB, etc D_PAN : double * : trim pan
  // of track, -1..1 D_WIDTH : double * : width of track, -1..1 D_DUALPANL :
  // double * : dualpan position 1, -1..1, only if I_PANMODE==6 D_DUALPANR :
  // double * : dualpan position 2, -1..1, only if I_PANMODE==6 I_PANMODE : int
  // * : pan mode, 0=classic 3.x, 3=new balance, 5=stereo pan, 6=dual pan
  // D_PANLAW : double * : pan law of track, <0=project default, 1=+0dB, etc
  // P_ENV:<envchunkname : TrackEnvelope*, read only. Call with :<VOLENV,
  // :<PANENV, etc appended. B_SHOWINMIXER : bool * : track control panel
  // visible in mixer (do not use on master track) B_SHOWINTCP : bool * : track
  // control panel visible in arrange view (do not use on master track)
  // B_MAINSEND : bool * : track sends audio to parent
  // C_MAINSEND_OFFS : char * : channel offset of track send to parent
  // B_FREEMODE : bool * : track free item positioning enabled (call
  // UpdateTimeline() after changing) C_BEATATTACHMODE : char * : track
  // timebase, -1=project default, 0=time, 1=beats (position, length, rate),
  // 2=beats (position only) F_MCP_FXSEND_SCALE : float * : scale of fx+send
  // area in MCP (0=minimum allowed, 1=maximum allowed) F_MCP_FXPARM_SCALE :
  // float * : scale of fx parameter area in MCP (0=minimum allowed, 1=maximum
  // allowed) F_MCP_SENDRGN_SCALE : float * : scale of send area as proportion
  // of the fx+send total area (0=minimum allowed, 1=maximum allowed)
  // F_TCP_FXPARM_SCALE : float * : scale of TCP parameter area when TCP FX are
  // embedded (0=min allowed, default, 1=max allowed) I_PLAY_OFFSET_FLAG : int *
  // : track playback offset state, &1=bypassed, &2=offset value is measured in
  // samples (otherwise measured in seconds) D_PLAY_OFFSET : double * : track
  // playback offset, units depend on I_PLAY_OFFSET_FLAG P_PARTRACK : MediaTrack
  // * : parent track (read-only) P_PROJECT : ReaProject * : parent project
  // (read-only)
  //
  double (*GetMediaTrackInfo_Value)(MediaTrack *tr, const char *parmname);

  //==============================================
  // GetMIDIInputName
  // returns true if device present
  bool (*GetMIDIInputName)(int dev, char *nameout, int nameout_sz);

  //==============================================
  // GetMIDIOutputName
  // returns true if device present
  bool (*GetMIDIOutputName)(int dev, char *nameout, int nameout_sz);

  //==============================================
  // GetMixerScroll
  // Get the leftmost track visible in the mixer
  MediaTrack *(*GetMixerScroll)();

  //==============================================
  // GetMouseModifier
  // Get the current mouse modifier assignment for a specific modifier key
  // assignment, in a specific context. action will be filled in with the
  // command ID number for a built-in mouse modifier or built-in REAPER command
  // ID, or the custom action ID string. See SetMouseModifier for more
  // information.
  //
  void (*GetMouseModifier)(const char *context, int modifier_flag, char *action,
                           int action_sz);

  //==============================================
  // GetMousePosition
  // get mouse position in screen coordinates
  void (*GetMousePosition)(int *xOut, int *yOut);

  //==============================================
  // GetNumAudioInputs
  // Return number of normal audio hardware inputs available
  int (*GetNumAudioInputs)();

  //==============================================
  // GetNumAudioOutputs
  // Return number of normal audio hardware outputs available
  int (*GetNumAudioOutputs)();

  //==============================================
  // GetNumMIDIInputs
  // returns max number of real midi hardware inputs
  int (*GetNumMIDIInputs)();

  //==============================================
  // GetNumMIDIOutputs
  // returns max number of real midi hardware outputs
  int (*GetNumMIDIOutputs)();

  //==============================================
  // GetNumTakeMarkers
  // Returns number of take markers. See GetTakeMarker, SetTakeMarker,
  // DeleteTakeMarker
  int (*GetNumTakeMarkers)(MediaItem_Take *take);

  //==============================================
  // GetNumTracks
  int (*GetNumTracks)();

  //==============================================
  // GetOS
  // Returns "Win32", "Win64", "OSX32", "OSX64", "macOS-arm64", or "Other".
  const char *(*GetOS)();

  //==============================================
  // GetOutputChannelName
  const char *(*GetOutputChannelName)(int channelIndex);

  //==============================================
  // GetOutputLatency
  // returns output latency in seconds
  double (*GetOutputLatency)();

  //==============================================
  // GetParentTrack
  MediaTrack *(*GetParentTrack)(MediaTrack *track);

  //==============================================
  // GetPeakFileName
  // get the peak file name for a given file (can be either filename.reapeaks,or
  // a hashed filename in another path)
  void (*GetPeakFileName)(const char *fn, char *buf, int buf_sz);

  //==============================================
  // GetPeakFileNameEx
  // get the peak file name for a given file (can be either filename.reapeaks,or
  // a hashed filename in another path)
  void (*GetPeakFileNameEx)(const char *fn, char *buf, int buf_sz,
                            bool forWrite);

  //==============================================
  // GetPeakFileNameEx2
  // Like GetPeakFileNameEx, but you can specify peaksfileextension such as
  // ".reapeaks"
  void (*GetPeakFileNameEx2)(const char *fn, char *buf, int buf_sz,
                             bool forWrite, const char *peaksfileextension);

  //==============================================
  // GetPeaksBitmap
  // see note in reaper_plugin.h about PCM_source_peaktransfer_t::samplerate
  void *(*GetPeaksBitmap)(PCM_source_peaktransfer_t *pks, double maxamp, int w,
                          int h, LICE_IBitmap *bmp);

  //==============================================
  // GetPlayPosition
  // returns latency-compensated actual-what-you-hear position
  double (*GetPlayPosition)();

  //==============================================
  // GetPlayPosition2
  // returns position of next audio block being processed
  double (*GetPlayPosition2)();

  //==============================================
  // GetPlayPosition2Ex
  // returns position of next audio block being processed
  double (*GetPlayPosition2Ex)(ReaProject *proj);

  //==============================================
  // GetPlayPositionEx
  // returns latency-compensated actual-what-you-hear position
  double (*GetPlayPositionEx)(ReaProject *proj);

  //==============================================
  // GetPlayState
  // &1=playing,&2=pause,&=4 is recording
  int (*GetPlayState)();

  //==============================================
  // GetPlayStateEx
  // &1=playing,&2=pause,&=4 is recording
  int (*GetPlayStateEx)(ReaProject *proj);

  //==============================================
  // GetPreferredDiskReadMode
  // Gets user configured preferred disk read mode. mode/nb/bs are all
  // parameters that should be passed to WDL_FileRead, see for more information.
  void (*GetPreferredDiskReadMode)(int *mode, int *nb, int *bs);

  //==============================================
  // GetPreferredDiskReadModePeak
  // Gets user configured preferred disk read mode for use when building peaks.
  // mode/nb/bs are all parameters that should be passed to WDL_FileRead, see
  // for more information.
  void (*GetPreferredDiskReadModePeak)(int *mode, int *nb, int *bs);

  //==============================================
  // GetPreferredDiskWriteMode
  // Gets user configured preferred disk write mode. nb will receive two values,
  // the initial and maximum write buffer counts. mode/nb/bs are all parameters
  // that should be passed to WDL_FileWrite, see for more information.
  void (*GetPreferredDiskWriteMode)(int *mode, int *nb, int *bs);

  //==============================================
  // GetProjectLength
  // returns length of project (maximum of end of media item, markers, end of
  // regions, tempo map
  double (*GetProjectLength)(ReaProject *proj);

  //==============================================
  // GetProjectName
  void (*GetProjectName)(ReaProject *proj, char *buf, int buf_sz);

  //==============================================
  // GetProjectPath
  // Get the project recording path.
  void (*GetProjectPath)(char *buf, int buf_sz);

  //==============================================
  // GetProjectPathEx
  // Get the project recording path.
  void (*GetProjectPathEx)(ReaProject *proj, char *buf, int buf_sz);

  //==============================================
  // GetProjectStateChangeCount
  // returns an integer that changes when the project state changes
  int (*GetProjectStateChangeCount)(ReaProject *proj);

  //==============================================
  // GetProjectTimeOffset
  // Gets project time offset in seconds (project settings - project start
  // time). If rndframe is true, the offset is rounded to a multiple of the
  // project frame size.
  double (*GetProjectTimeOffset)(ReaProject *proj, bool rndframe);

  //==============================================
  // GetProjectTimeSignature
  // deprecated
  void (*GetProjectTimeSignature)(double *bpmOut, double *bpiOut);

  //==============================================
  // GetProjectTimeSignature2
  // Gets basic time signature (beats per minute, numerator of time signature in
  // bpi) this does not reflect tempo envelopes but is purely what is set in the
  // project settings.
  void (*GetProjectTimeSignature2)(ReaProject *proj, double *bpmOut,
                                   double *bpiOut);

  //==============================================
  // GetProjExtState
  // Get the value previously associated with this extname and key, the last
  // time the project was saved. See SetProjExtState, EnumProjExtState.
  int (*GetProjExtState)(ReaProject *proj, const char *extname, const char *key,
                         char *valOutNeedBig, int valOutNeedBig_sz);

  //==============================================
  // GetResourcePath
  // returns path where ini files are stored, other things are in
  // subdirectories.
  const char *(*GetResourcePath)();

  //==============================================
  // GetSelectedEnvelope
  // get the currently selected envelope, returns NULL/nil if no envelope is
  // selected
  TrackEnvelope *(*GetSelectedEnvelope)(ReaProject *proj);

  //==============================================
  // GetSelectedMediaItem
  // get a selected item by selected item count (zero-based) (proj=0 for active
  // project)
  MediaItem *(*GetSelectedMediaItem)(ReaProject *proj, int selitem);

  //==============================================
  // GetSelectedTrack
  // Get a selected track from a project (proj=0 for active project) by selected
  // track count (zero-based). This function ignores the master track, see
  // GetSelectedTrack2.
  MediaTrack *(*GetSelectedTrack)(ReaProject *proj, int seltrackidx);

  //==============================================
  // GetSelectedTrack2
  // Get a selected track from a project (proj=0 for active project) by selected
  // track count (zero-based).
  MediaTrack *(*GetSelectedTrack2)(ReaProject *proj, int seltrackidx,
                                   bool wantmaster);

  //==============================================
  // GetSelectedTrackEnvelope
  // get the currently selected track envelope, returns NULL/nil if no envelope
  // is selected
  TrackEnvelope *(*GetSelectedTrackEnvelope)(ReaProject *proj);

  //==============================================
  // GetSet_ArrangeView2
  // Gets or sets the arrange view start/end time for screen coordinates. use
  // screen_x_start=screen_x_end=0 to use the full arrange view's start/end time
  void (*GetSet_ArrangeView2)(ReaProject *proj, bool isSet, int screen_x_start,
                              int screen_x_end, double *start_timeOut,
                              double *end_timeOut);

  //==============================================
  // GetSet_LoopTimeRange
  void (*GetSet_LoopTimeRange)(bool isSet, bool isLoop, double *startOut,
                               double *endOut, bool allowautoseek);

  //==============================================
  // GetSet_LoopTimeRange2
  void (*GetSet_LoopTimeRange2)(ReaProject *proj, bool isSet, bool isLoop,
                                double *startOut, double *endOut,
                                bool allowautoseek);

  //==============================================
  // GetSetAutomationItemInfo
  // Get or set automation item information. autoitem_idx=0 for the first
  // automation item on an envelope, 1 for the second item, etc. desc can be any
  // of the following: D_POOL_ID : double * : automation item pool ID (as an
  // integer); edits are propagated to all other automation items that share a
  // pool ID D_POSITION : double * : automation item timeline position in
  // seconds D_LENGTH : double * : automation item length in seconds D_STARTOFFS
  // : double * : automation item start offset in seconds D_PLAYRATE : double *
  // : automation item playback rate D_BASELINE : double * : automation item
  // baseline value in the range [0,1] D_AMPLITUDE : double * : automation item
  // amplitude in the range [-1,1] D_LOOPSRC : double * : nonzero if the
  // automation item contents are looped D_UISEL : double * : nonzero if the
  // automation item is selected in the arrange view D_POOL_QNLEN : double * :
  // automation item pooled source length in quarter notes (setting will affect
  // all pooled instances)
  //
  double (*GetSetAutomationItemInfo)(TrackEnvelope *env, int autoitem_idx,
                                     const char *desc, double value,
                                     bool is_set);

  //==============================================
  // GetSetAutomationItemInfo_String
  // Get or set automation item information. autoitem_idx=0 for the first
  // automation item on an envelope, 1 for the second item, etc. returns true on
  // success. desc can be any of the following: P_POOL_NAME : char *, name of
  // the underlying automation item pool P_POOL_EXT:xyz : char *,
  // extension-specific persistent data
  //
  bool (*GetSetAutomationItemInfo_String)(TrackEnvelope *env, int autoitem_idx,
                                          const char *desc,
                                          char *valuestrNeedBig, bool is_set);

  //==============================================
  // GetSetEnvelopeInfo_String
  // Gets/sets an attribute string:
  // P_EXT:xyz : char * : extension-specific persistent data
  //
  bool (*GetSetEnvelopeInfo_String)(TrackEnvelope *env, const char *parmname,
                                    char *stringNeedBig, bool setNewValue);

  //==============================================
  // GetSetEnvelopeState
  // deprecated -- see SetEnvelopeStateChunk, GetEnvelopeStateChunk
  bool (*GetSetEnvelopeState)(TrackEnvelope *env, char *str, int str_sz);

  //==============================================
  // GetSetEnvelopeState2
  // deprecated -- see SetEnvelopeStateChunk, GetEnvelopeStateChunk
  bool (*GetSetEnvelopeState2)(TrackEnvelope *env, char *str, int str_sz,
                               bool isundo);

  //==============================================
  // GetSetItemState
  // deprecated -- see SetItemStateChunk, GetItemStateChunk
  bool (*GetSetItemState)(MediaItem *item, char *str, int str_sz);

  //==============================================
  // GetSetItemState2
  // deprecated -- see SetItemStateChunk, GetItemStateChunk
  bool (*GetSetItemState2)(MediaItem *item, char *str, int str_sz, bool isundo);

  //==============================================
  // GetSetMediaItemInfo
  // P_TRACK : MediaTrack * (read-only)
  // B_MUTE : bool * : muted (item solo overrides). setting this value will
  // clear C_MUTE_SOLO. B_MUTE_ACTUAL : bool * : muted (ignores solo). setting
  // this value will not affect C_MUTE_SOLO. C_MUTE_SOLO : char * : solo
  // override (-1=soloed, 0=no override, 1=unsoloed). note that this API does
  // not automatically unsolo other items when soloing (nor clear the unsolos
  // when clearing the last soloed item), it must be done by the caller via
  // action or via this API. B_LOOPSRC : bool * : loop source B_ALLTAKESPLAY :
  // bool * : all takes play B_UISEL : bool * : selected in arrange view
  // C_BEATATTACHMODE : char * : item timebase, -1=track or project default,
  // 1=beats (position, length, rate), 2=beats (position only). for auto-stretch
  // timebase: C_BEATATTACHMODE=1, C_AUTOSTRETCH=1 C_AUTOSTRETCH: : char * :
  // auto-stretch at project tempo changes, 1=enabled, requires
  // C_BEATATTACHMODE=1 C_LOCK : char * : locked, &1=locked D_VOL : double * :
  // item volume,  0=-inf, 0.5=-6dB, 1=+0dB, 2=+6dB, etc D_POSITION : double * :
  // item position in seconds D_LENGTH : double * : item length in seconds
  // D_SNAPOFFSET : double * : item snap offset in seconds
  // D_FADEINLEN : double * : item manual fadein length in seconds
  // D_FADEOUTLEN : double * : item manual fadeout length in seconds
  // D_FADEINDIR : double * : item fadein curvature, -1..1
  // D_FADEOUTDIR : double * : item fadeout curvature, -1..1
  // D_FADEINLEN_AUTO : double * : item auto-fadein length in seconds, -1=no
  // auto-fadein D_FADEOUTLEN_AUTO : double * : item auto-fadeout length in
  // seconds, -1=no auto-fadeout C_FADEINSHAPE : int * : fadein shape, 0..6,
  // 0=linear C_FADEOUTSHAPE : int * : fadeout shape, 0..6, 0=linear I_GROUPID :
  // int * : group ID, 0=no group I_LASTY : int * : Y-position of track in
  // pixels (read-only) I_LASTH : int * : height in track in pixels (read-only)
  // I_CUSTOMCOLOR : int * : custom color, OS dependent color|0x100000 (i.e.
  // ColorToNative(r,g,b)|0x100000). If you do not |0x100000, then it will not
  // be used, but will store the color I_CURTAKE : int * : active take number
  // IP_ITEMNUMBER : int, item number on this track (read-only, returns the item
  // number directly) F_FREEMODE_Y : float * : free item positioning Y-position,
  // 0=top of track, 1=bottom of track (will never be 1) F_FREEMODE_H : float *
  // : free item positioning height, 0=no height, 1=full height of track (will
  // never be 0) P_NOTES : char * : item note text (do not write to returned
  // pointer, use setNewValue to update) P_EXT:xyz : char * : extension-specific
  // persistent data GUID : GUID * : 16-byte GUID, can query or update. If using
  // a _String() function, GUID is a string {xyz-...}.
  //
  void *(*GetSetMediaItemInfo)(MediaItem *item, const char *parmname,
                               void *setNewValue);

  //==============================================
  // GetSetMediaItemInfo_String
  // Gets/sets an item attribute string:
  // P_NOTES : char * : item note text (do not write to returned pointer, use
  // setNewValue to update) P_EXT:xyz : char * : extension-specific persistent
  // data GUID : GUID * : 16-byte GUID, can query or update. If using a
  // _String() function, GUID is a string {xyz-...}.
  //
  bool (*GetSetMediaItemInfo_String)(MediaItem *item, const char *parmname,
                                     char *stringNeedBig, bool setNewValue);

  //==============================================
  // GetSetMediaItemTakeInfo
  // P_TRACK : pointer to MediaTrack (read-only)
  // P_ITEM : pointer to MediaItem (read-only)
  // P_SOURCE : PCM_source *. Note that if setting this, you should first
  // retrieve the old source, set the new, THEN delete the old. P_NAME : char *
  // : take name P_EXT:xyz : char * : extension-specific persistent data GUID :
  // GUID * : 16-byte GUID, can query or update. If using a _String() function,
  // GUID is a string {xyz-...}. D_STARTOFFS : double * : start offset in source
  // media, in seconds D_VOL : double * : take volume, 0=-inf, 0.5=-6dB, 1=+0dB,
  // 2=+6dB, etc, negative if take polarity is flipped D_PAN : double * : take
  // pan, -1..1 D_PANLAW : double * : take pan law, -1=default,
  // 0.5=-6dB, 1.0=+0dB, etc D_PLAYRATE : double * : take playback rate,
  // 0.5=half speed, 1=normal, 2=double speed, etc D_PITCH : double * : take
  // pitch adjustment in semitones, -12=one octave down, 0=normal, +12=one
  // octave up, etc B_PPITCH : bool * : preserve pitch when changing playback
  // rate I_CHANMODE : int * : channel mode, 0=normal, 1=reverse stereo,
  // 2=downmix, 3=left, 4=right I_PITCHMODE : int * : pitch shifter mode,
  // -1=projext default, otherwise high 2 bytes=shifter, low 2 bytes=parameter
  // I_CUSTOMCOLOR : int * : custom color, OS dependent color|0x100000 (i.e.
  // ColorToNative(r,g,b)|0x100000). If you do not |0x100000, then it will not
  // be used, but will store the color IP_TAKENUMBER : int : take number
  // (read-only, returns the take number directly)
  //
  void *(*GetSetMediaItemTakeInfo)(MediaItem_Take *tk, const char *parmname,
                                   void *setNewValue);

  //==============================================
  // GetSetMediaItemTakeInfo_String
  // Gets/sets a take attribute string:
  // P_NAME : char * : take name
  // P_EXT:xyz : char * : extension-specific persistent data
  // GUID : GUID * : 16-byte GUID, can query or update. If using a _String()
  // function, GUID is a string {xyz-...}.
  //
  bool (*GetSetMediaItemTakeInfo_String)(MediaItem_Take *tk,
                                         const char *parmname,
                                         char *stringNeedBig, bool setNewValue);

  //==============================================
  // GetSetMediaTrackInfo
  // Get or set track attributes.
  // P_PARTRACK : MediaTrack * : parent track (read-only)
  // P_PROJECT : ReaProject * : parent project (read-only)
  // P_NAME : char * : track name (on master returns NULL)
  // P_ICON : const char * : track icon (full filename, or relative to
  // resource_path/data/track_icons) P_MCP_LAYOUT : const char * : layout name
  // P_TCP_LAYOUT : const char * : layout name
  // P_EXT:xyz : char * : extension-specific persistent data
  // GUID : GUID * : 16-byte GUID, can query or update. If using a _String()
  // function, GUID is a string {xyz-...}. B_MUTE : bool * : muted B_PHASE :
  // bool * : track phase inverted B_RECMON_IN_EFFECT : bool * : record
  // monitoring in effect (current audio-thread playback state, read-only)
  // IP_TRACKNUMBER : int : track number 1-based, 0=not found, -1=master track
  // (read-only, returns the int directly) I_SOLO : int * : soloed, 0=not
  // soloed, 1=soloed, 2=soloed in place, 5=safe soloed, 6=safe soloed in place
  // I_FXEN : int * : fx enabled, 0=bypassed, !0=fx active
  // I_RECARM : int * : record armed, 0=not record armed, 1=record armed
  // I_RECINPUT : int * : record input, <0=no input. if 4096 set, input is MIDI
  // and low 5 bits represent channel (0=all, 1-16=only chan), next 6 bits
  // represent physical input (63=all, 62=VKB). If 4096 is not set, low 10 bits
  // (0..1023) are input start channel (ReaRoute/Loopback start at 512). If 2048
  // is set, input is multichannel input (using track channel count), or if 1024
  // is set, input is stereo input, otherwise input is mono. I_RECMODE : int * :
  // record mode, 0=input, 1=stereo out, 2=none, 3=stereo out w/latency
  // compensation, 4=midi output, 5=mono out, 6=mono out w/ latency
  // compensation, 7=midi overdub, 8=midi replace I_RECMON : int * : record
  // monitoring, 0=off, 1=normal, 2=not when playing (tape style) I_RECMONITEMS
  // : int * : monitor items while recording, 0=off, 1=on I_AUTOMODE : int * :
  // track automation mode, 0=trim/off, 1=read, 2=touch, 3=write, 4=latch
  // I_NCHAN : int * : number of track channels, 2-64, even numbers only
  // I_SELECTED : int * : track selected, 0=unselected, 1=selected
  // I_WNDH : int * : current TCP window height in pixels including envelopes
  // (read-only) I_TCPH : int * : current TCP window height in pixels not
  // including envelopes (read-only) I_TCPY : int * : current TCP window
  // Y-position in pixels relative to top of arrange view (read-only) I_MCPX :
  // int * : current MCP X-position in pixels relative to mixer container I_MCPY
  // : int * : current MCP Y-position in pixels relative to mixer container
  // I_MCPW : int * : current MCP width in pixels
  // I_MCPH : int * : current MCP height in pixels
  // I_FOLDERDEPTH : int * : folder depth change, 0=normal, 1=track is a folder
  // parent, -1=track is the last in the innermost folder, -2=track is the last
  // in the innermost and next-innermost folders, etc I_FOLDERCOMPACT : int * :
  // folder compacted state (only valid on folders), 0=normal, 1=small, 2=tiny
  // children I_MIDIHWOUT : int * : track midi hardware output index,
  // <0=disabled, low 5 bits are which channels (0=all, 1-16), next 5 bits are
  // output device index (0-31) I_PERFFLAGS : int * : track performance flags,
  // &1=no media buffering, &2=no anticipative FX I_CUSTOMCOLOR : int * : custom
  // color, OS dependent color|0x100000 (i.e. ColorToNative(r,g,b)|0x100000). If
  // you do not |0x100000, then it will not be used, but will store the color
  // I_HEIGHTOVERRIDE : int * : custom height override for TCP window, 0 for
  // none, otherwise size in pixels B_HEIGHTLOCK : bool * : track height lock
  // (must set I_HEIGHTOVERRIDE before locking) D_VOL : double * : trim volume
  // of track, 0=-inf, 0.5=-6dB, 1=+0dB, 2=+6dB, etc D_PAN : double * : trim pan
  // of track, -1..1 D_WIDTH : double * : width of track, -1..1 D_DUALPANL :
  // double * : dualpan position 1, -1..1, only if I_PANMODE==6 D_DUALPANR :
  // double * : dualpan position 2, -1..1, only if I_PANMODE==6 I_PANMODE : int
  // * : pan mode, 0=classic 3.x, 3=new balance, 5=stereo pan, 6=dual pan
  // D_PANLAW : double * : pan law of track, <0=project default, 1=+0dB, etc
  // P_ENV:<envchunkname : TrackEnvelope*, read only. Call with :<VOLENV,
  // :<PANENV, etc appended. B_SHOWINMIXER : bool * : track control panel
  // visible in mixer (do not use on master track) B_SHOWINTCP : bool * : track
  // control panel visible in arrange view (do not use on master track)
  // B_MAINSEND : bool * : track sends audio to parent
  // C_MAINSEND_OFFS : char * : channel offset of track send to parent
  // B_FREEMODE : bool * : track free item positioning enabled (call
  // UpdateTimeline() after changing) C_BEATATTACHMODE : char * : track
  // timebase, -1=project default, 0=time, 1=beats (position, length, rate),
  // 2=beats (position only) F_MCP_FXSEND_SCALE : float * : scale of fx+send
  // area in MCP (0=minimum allowed, 1=maximum allowed) F_MCP_FXPARM_SCALE :
  // float * : scale of fx parameter area in MCP (0=minimum allowed, 1=maximum
  // allowed) F_MCP_SENDRGN_SCALE : float * : scale of send area as proportion
  // of the fx+send total area (0=minimum allowed, 1=maximum allowed)
  // F_TCP_FXPARM_SCALE : float * : scale of TCP parameter area when TCP FX are
  // embedded (0=min allowed, default, 1=max allowed) I_PLAY_OFFSET_FLAG : int *
  // : track playback offset state, &1=bypassed, &2=offset value is measured in
  // samples (otherwise measured in seconds) D_PLAY_OFFSET : double * : track
  // playback offset, units depend on I_PLAY_OFFSET_FLAG
  //
  void *(*GetSetMediaTrackInfo)(MediaTrack *tr, const char *parmname,
                                void *setNewValue);

  //==============================================
  // GetSetMediaTrackInfo_String
  // Get or set track string attributes.
  // P_NAME : char * : track name (on master returns NULL)
  // P_ICON : const char * : track icon (full filename, or relative to
  // resource_path/data/track_icons) P_MCP_LAYOUT : const char * : layout name
  // P_TCP_LAYOUT : const char * : layout name
  // P_EXT:xyz : char * : extension-specific persistent data
  // GUID : GUID * : 16-byte GUID, can query or update. If using a _String()
  // function, GUID is a string {xyz-...}.
  //
  bool (*GetSetMediaTrackInfo_String)(MediaTrack *tr, const char *parmname,
                                      char *stringNeedBig, bool setNewValue);

  //==============================================
  // GetSetObjectState
  // get or set the state of a {track,item,envelope} as an RPPXML chunk
  // str="" to get the chunk string returned (must call FreeHeapPtr when done)
  // supply str to set the state (returns zero)
  char *(*GetSetObjectState)(void *obj, const char *str);

  //==============================================
  // GetSetObjectState2
  // get or set the state of a {track,item,envelope} as an RPPXML chunk
  // str="" to get the chunk string returned (must call FreeHeapPtr when done)
  // supply str to set the state (returns zero)
  // set isundo if the state will be used for undo purposes (which may allow
  // REAPER to get the state more efficiently
  char *(*GetSetObjectState2)(void *obj, const char *str, bool isundo);

  //==============================================
  // GetSetProjectAuthor
  // gets or sets project author, author_sz is ignored when setting
  void (*GetSetProjectAuthor)(ReaProject *proj, bool set, char *author,
                              int author_sz);

  //==============================================
  // GetSetProjectGrid
  // Get or set the arrange view grid division. 0.25=quarter note, 1.0/3.0=half
  // note triplet, etc. swingmode can be 1 for swing enabled, swingamt is -1..1.
  // swingmode can be 3 for measure-grid. Returns grid configuration flags
  int (*GetSetProjectGrid)(ReaProject *project, bool set,
                           double *divisionInOutOptional,
                           int *swingmodeInOutOptional,
                           double *swingamtInOutOptional);

  //==============================================
  // GetSetProjectInfo
  // Get or set project information.
  // RENDER_SETTINGS : &(1|2)=0:master mix, &1=stems+master mix, &2=stems only,
  // &4=multichannel tracks to multichannel files, &8=use render matrix,
  // &16=tracks with only mono media to mono files, &32=selected media items,
  // &64=selected media items via master, &128=selected tracks via master,
  // &256=embed transients if format supports, &512=embed metadata if format
  // supports, &1024=embed take markers if format supports, &2048=2nd pass
  // render RENDER_BOUNDSFLAG : 0=custom time bounds, 1=entire project, 2=time
  // selection, 3=all project regions, 4=selected media items, 5=selected
  // project regions RENDER_CHANNELS : number of channels in rendered file
  // RENDER_SRATE : sample rate of rendered file (or 0 for project sample rate)
  // RENDER_STARTPOS : render start time when RENDER_BOUNDSFLAG=0
  // RENDER_ENDPOS : render end time when RENDER_BOUNDSFLAG=0
  // RENDER_TAILFLAG : apply render tail setting when rendering: &1=custom time
  // bounds, &2=entire project, &4=time selection, &8=all project regions,
  // &16=selected media items, &32=selected project regions RENDER_TAILMS : tail
  // length in ms to render (only used if RENDER_BOUNDSFLAG and RENDER_TAILFLAG
  // are set) RENDER_ADDTOPROJ : &1=add rendered files to project, &2=do not
  // render files that are likely silent RENDER_DITHER : &1=dither, &2=noise
  // shaping, &4=dither stems, &8=noise shaping on stems PROJECT_SRATE :
  // samplerate (ignored unless PROJECT_SRATE_USE set) PROJECT_SRATE_USE : set
  // to 1 if project samplerate is used
  //
  double (*GetSetProjectInfo)(ReaProject *project, const char *desc,
                              double value, bool is_set);

  //==============================================
  // GetSetProjectInfo_String
  // Get or set project information.
  // MARKER_GUID:X : get the GUID (unique ID) of the marker or region with index
  // X, where X is the index passed to EnumProjectMarkers, not necessarily the
  // displayed number RECORD_PATH : recording directory -- may be blank or a
  // relative path, to get the effective path see GetProjectPathEx() RENDER_FILE
  // : render directory RENDER_PATTERN : render file name (may contain
  // wildcards) RENDER_METADATA : get or set the metadata saved with the project
  // (not metadata embedded in project media). Example, ID3 album name metadata:
  // "ID3:TALB" to get, "ID3:TALB|my album name" to set. RENDER_TARGETS :
  // semicolon separated list of files that would be written if the project is
  // rendered using the most recent render settings RENDER_FORMAT :
  // base64-encoded sink configuration (see project files, etc). Callers can
  // also pass a simple 4-byte string (non-base64-encoded), e.g. "evaw" or
  // "l3pm", to use default settings for that sink type. RENDER_FORMAT2 :
  // base64-encoded secondary sink configuration. Callers can also pass a simple
  // 4-byte string (non-base64-encoded), e.g. "evaw" or "l3pm", to use default
  // settings for that sink type, or "" to disable secondary render.
  //
  bool (*GetSetProjectInfo_String)(ReaProject *project, const char *desc,
                                   char *valuestrNeedBig, bool is_set);

  //==============================================
  // GetSetProjectNotes
  // gets or sets project notes, notesNeedBig_sz is ignored when setting
  void (*GetSetProjectNotes)(ReaProject *proj, bool set, char *notesNeedBig,
                             int notesNeedBig_sz);

  //==============================================
  // GetSetRepeat
  // -1 == query,0=clear,1=set,>1=toggle . returns new value
  int (*GetSetRepeat)(int val);

  //==============================================
  // GetSetRepeatEx
  // -1 == query,0=clear,1=set,>1=toggle . returns new value
  int (*GetSetRepeatEx)(ReaProject *proj, int val);

  //==============================================
  // GetSetTrackGroupMembership
  // Gets or modifies the group membership for a track. Returns group state
  // prior to call (each bit represents one of the 32 group numbers). if setmask
  // has bits set, those bits in setvalue will be applied to group. Group can be
  // one of: VOLUME_LEAD VOLUME_FOLLOW VOLUME_VCA_LEAD VOLUME_VCA_FOLLOW
  // PAN_LEAD
  // PAN_FOLLOW
  // WIDTH_LEAD
  // WIDTH_FOLLOW
  // MUTE_LEAD
  // MUTE_FOLLOW
  // SOLO_LEAD
  // SOLO_FOLLOW
  // RECARM_LEAD
  // RECARM_FOLLOW
  // POLARITY_LEAD
  // POLARITY_FOLLOW
  // AUTOMODE_LEAD
  // AUTOMODE_FOLLOW
  // VOLUME_REVERSE
  // PAN_REVERSE
  // WIDTH_REVERSE
  // NO_LEAD_WHEN_FOLLOW
  // VOLUME_VCA_FOLLOW_ISPREFX
  //
  // Note: REAPER v6.11 and earlier used _MASTER and _SLAVE rather than _LEAD
  // and _FOLLOW, which is deprecated but still supported (scripts that must
  // support v6.11 and earlier can use the deprecated strings).
  //
  unsigned int (*GetSetTrackGroupMembership)(MediaTrack *tr,
                                             const char *groupname,
                                             unsigned int setmask,
                                             unsigned int setvalue);

  //==============================================
  // GetSetTrackGroupMembershipHigh
  // Gets or modifies the group membership for a track. Returns group state
  // prior to call (each bit represents one of the high 32 group numbers). if
  // setmask has bits set, those bits in setvalue will be applied to group.
  // Group can be one of: VOLUME_LEAD VOLUME_FOLLOW VOLUME_VCA_LEAD
  // VOLUME_VCA_FOLLOW
  // PAN_LEAD
  // PAN_FOLLOW
  // WIDTH_LEAD
  // WIDTH_FOLLOW
  // MUTE_LEAD
  // MUTE_FOLLOW
  // SOLO_LEAD
  // SOLO_FOLLOW
  // RECARM_LEAD
  // RECARM_FOLLOW
  // POLARITY_LEAD
  // POLARITY_FOLLOW
  // AUTOMODE_LEAD
  // AUTOMODE_FOLLOW
  // VOLUME_REVERSE
  // PAN_REVERSE
  // WIDTH_REVERSE
  // NO_LEAD_WHEN_FOLLOW
  // VOLUME_VCA_FOLLOW_ISPREFX
  //
  // Note: REAPER v6.11 and earlier used _MASTER and _SLAVE rather than _LEAD
  // and _FOLLOW, which is deprecated but still supported (scripts that must
  // support v6.11 and earlier can use the deprecated strings).
  //
  unsigned int (*GetSetTrackGroupMembershipHigh)(MediaTrack *tr,
                                                 const char *groupname,
                                                 unsigned int setmask,
                                                 unsigned int setvalue);

  //==============================================
  // GetSetTrackMIDISupportFile
  // Get or set the filename for storage of various track MIDI characteristics.
  // 0=MIDI colormap image file, 1 or 2=MIDI bank/program select file (2=set new
  // default). If fn != NULL, a new track MIDI storage file will be set;
  // otherwise the existing track MIDI storage file will be returned.
  const char *(*GetSetTrackMIDISupportFile)(ReaProject *proj, MediaTrack *track,
                                            int which, const char *filename);

  //==============================================
  // GetSetTrackSendInfo
  // Get or set send/receive/hardware output attributes.
  // category is <0 for receives, 0=sends, >0 for hardware outputs
  //  sendidx is 0..n (to enumerate, iterate over sendidx until it returns NULL)
  // parameter names:
  // P_DESTTRACK : read only, returns MediaTrack *, destination track, only
  // applies for sends/recvs P_SRCTRACK : read only, returns MediaTrack *,
  // source track, only applies for sends/recvs P_ENV:<envchunkname : read only,
  // returns TrackEnvelope *. Call with :<VOLENV, :<PANENV, etc appended.
  // P_EXT:xyz : char * : extension-specific persistent data
  // B_MUTE : bool *
  // B_PHASE : bool *, true to flip phase
  // B_MONO : bool *
  // D_VOL : double *, 1.0 = +0dB etc
  // D_PAN : double *, -1..+1
  // D_PANLAW : double *,1.0=+0.0db, 0.5=-6dB, -1.0 = projdef etc
  // I_SENDMODE : int *, 0=post-fader, 1=pre-fx, 2=post-fx (deprecated),
  // 3=post-fx I_AUTOMODE : int * : automation mode (-1=use track automode,
  // 0=trim/off, 1=read, 2=touch, 3=write, 4=latch) I_SRCCHAN : int *,
  // index,&1024=mono, -1 for none I_DSTCHAN : int *, index, &1024=mono,
  // otherwise stereo pair, hwout:&512=rearoute I_MIDIFLAGS : int *, low 5
  // bits=source channel 0=all, 1-16, next 5 bits=dest channel, 0=orig,
  // 1-16=chanSee CreateTrackSend, RemoveTrackSend.
  void *(*GetSetTrackSendInfo)(MediaTrack *tr, int category, int sendidx,
                               const char *parmname, void *setNewValue);

  //==============================================
  // GetSetTrackSendInfo_String
  // Gets/sets a send attribute string:
  // P_EXT:xyz : char * : extension-specific persistent data
  //
  bool (*GetSetTrackSendInfo_String)(MediaTrack *tr, int category, int sendidx,
                                     const char *parmname, char *stringNeedBig,
                                     bool setNewValue);

  //==============================================
  // GetSetTrackState
  // deprecated -- see SetTrackStateChunk, GetTrackStateChunk
  bool (*GetSetTrackState)(MediaTrack *track, char *str, int str_sz);

  //==============================================
  // GetSetTrackState2
  // deprecated -- see SetTrackStateChunk, GetTrackStateChunk
  bool (*GetSetTrackState2)(MediaTrack *track, char *str, int str_sz,
                            bool isundo);

  //==============================================
  // GetSubProjectFromSource
  ReaProject *(*GetSubProjectFromSource)(PCM_source *src);

  //==============================================
  // GetTake
  // get a take from an item by take count (zero-based)
  MediaItem_Take *(*GetTake)(MediaItem *item, int takeidx);

  //==============================================
  // GetTakeEnvelope
  TrackEnvelope *(*GetTakeEnvelope)(MediaItem_Take *take, int envidx);

  //==============================================
  // GetTakeEnvelopeByName
  TrackEnvelope *(*GetTakeEnvelopeByName)(MediaItem_Take *take,
                                          const char *envname);

  //==============================================
  // GetTakeMarker
  // Get information about a take marker. Returns the position in media item
  // source time, or -1 if the take marker does not exist. See
  // GetNumTakeMarkers, SetTakeMarker, DeleteTakeMarker
  double (*GetTakeMarker)(MediaItem_Take *take, int idx, char *nameOut,
                          int nameOut_sz, int *colorOutOptional);

  //==============================================
  // GetTakeName
  // returns NULL if the take is not valid
  const char *(*GetTakeName)(MediaItem_Take *take);

  //==============================================
  // GetTakeNumStretchMarkers
  // Returns number of stretch markers in take
  int (*GetTakeNumStretchMarkers)(MediaItem_Take *take);

  //==============================================
  // GetTakeStretchMarker
  // Gets information on a stretch marker, idx is 0..n. Returns false if stretch
  // marker not valid. posOut will be set to position in item, srcposOutOptional
  // will be set to source media position. Returns index. if input index is -1,
  // next marker is found using position (or source position if position is -1).
  // If position/source position are used to find marker position, their values
  // are not updated.
  int (*GetTakeStretchMarker)(MediaItem_Take *take, int idx, double *posOut,
                              double *srcposOutOptional);

  //==============================================
  // GetTakeStretchMarkerSlope
  // See SetTakeStretchMarkerSlope
  double (*GetTakeStretchMarkerSlope)(MediaItem_Take *take, int idx);

  //==============================================
  // GetTCPFXParm
  // Get information about a specific FX parameter knob (see CountTCPFXParms).
  bool (*GetTCPFXParm)(ReaProject *project, MediaTrack *track, int index,
                       int *fxindexOut, int *parmidxOut);

  //==============================================
  // GetTempoMatchPlayRate
  // finds the playrate and target length to insert this item stretched to a
  // round power-of-2 number of bars, between 1/8 and 256
  bool (*GetTempoMatchPlayRate)(PCM_source *source, double srcscale,
                                double position, double mult, double *rateOut,
                                double *targetlenOut);

  //==============================================
  // GetTempoTimeSigMarker
  // Get information about a tempo/time signature marker. See
  // CountTempoTimeSigMarkers, SetTempoTimeSigMarker, AddTempoTimeSigMarker.
  bool (*GetTempoTimeSigMarker)(ReaProject *proj, int ptidx, double *timeposOut,
                                int *measureposOut, double *beatposOut,
                                double *bpmOut, int *timesig_numOut,
                                int *timesig_denomOut, bool *lineartempoOut);

  //==============================================
  // GetThemeColor
  // Returns the theme color specified, or -1 on failure. If the low bit of
  // flags is set, the color as originally specified by the theme (before any
  // transformations) is returned, otherwise the current (possibly transformed
  // and modified) color is returned. See SetThemeColor for a list of valid
  // ini_key.
  int (*GetThemeColor)(const char *ini_key, int flagsOptional);

  //==============================================
  // GetToggleCommandState
  // See GetToggleCommandStateEx.
  int (*GetToggleCommandState)(int command_id);

  //==============================================
  // GetToggleCommandState2
  // See GetToggleCommandStateEx.
  int (*GetToggleCommandState2)(KbdSectionInfo *section, int command_id);

  //==============================================
  // GetToggleCommandStateEx
  // For the main action context, the MIDI editor, or the media explorer,
  // returns the toggle state of the action. 0=off, 1=on, -1=NA because the
  // action does not have on/off states. For the MIDI editor, the action state
  // for the most recently focused window will be returned.
  int (*GetToggleCommandStateEx)(int section_id, int command_id);

  //==============================================
  // GetToggleCommandStateThroughHooks
  // Returns the state of an action via extension plugins' hooks.
  int (*GetToggleCommandStateThroughHooks)(KbdSectionInfo *section,
                                           int command_id);

  //==============================================
  // GetTooltipWindow
  // gets a tooltip window,in case you want to ask it for font information. Can
  // return NULL.
  HWND (*GetTooltipWindow)();

  //==============================================
  // GetTrack
  // get a track from a project by track count (zero-based) (proj=0 for active
  // project)
  MediaTrack *(*GetTrack)(ReaProject *proj, int trackidx);

  //==============================================
  // GetTrackAutomationMode
  // return the track mode, regardless of global override
  int (*GetTrackAutomationMode)(MediaTrack *tr);

  //==============================================
  // GetTrackColor
  // Returns the track custom color as OS dependent color|0x100000 (i.e.
  // ColorToNative(r,g,b)|0x100000). Black is returned as 0x01000000, no color
  // setting is returned as 0.
  int (*GetTrackColor)(MediaTrack *track);

  //==============================================
  // GetTrackDepth
  int (*GetTrackDepth)(MediaTrack *track);

  //==============================================
  // GetTrackEnvelope
  TrackEnvelope *(*GetTrackEnvelope)(MediaTrack *track, int envidx);

  //==============================================
  // GetTrackEnvelopeByChunkName
  // Gets a built-in track envelope by configuration chunk name, e.g. "<VOLENV".
  //
  TrackEnvelope *(*GetTrackEnvelopeByChunkName)(MediaTrack *tr,
                                                const char *cfgchunkname);

  //==============================================
  // GetTrackEnvelopeByName
  TrackEnvelope *(*GetTrackEnvelopeByName)(MediaTrack *track,
                                           const char *envname);

  //==============================================
  // GetTrackFromPoint
  // Returns the track from the screen coordinates specified. If the screen
  // coordinates refer to a window associated to the track (such as FX), the
  // track will be returned. infoOutOptional will be set to 1 if it is likely an
  // envelope, 2 if it is likely a track FX.
  MediaTrack *(*GetTrackFromPoint)(int screen_x, int screen_y,
                                   int *infoOutOptional);

  //==============================================
  // GetTrackGUID
  GUID *(*GetTrackGUID)(MediaTrack *tr);

  //==============================================
  // GetTrackInfo
  // gets track info (returns name).
  // track index, -1=master, 0..n, or cast a MediaTrack* to int
  // if flags is non-NULL, will be set to:
  // &1=folder
  // &2=selected
  // &4=has fx enabled
  // &8=muted
  // &16=soloed
  // &32=SIP'd (with &16)
  // &64=rec armed
  // &128=rec monitoring on
  // &256=rec monitoring auto
  // &512=hide from TCP
  // &1024=hide from MCP
  const char *(*GetTrackInfo)(INT_PTR track, int *flags);

  //==============================================
  // GetTrackMediaItem
  MediaItem *(*GetTrackMediaItem)(MediaTrack *tr, int itemidx);

  //==============================================
  // GetTrackMIDILyrics
  // Get all MIDI lyrics on the track. Lyrics will be returned as one string
  // with tabs between each word. flag&1: double tabs at the end of each measure
  // and triple tabs when skipping measures, flag&2: each lyric is preceded by
  // its beat position in the project (example with flag=2: "1.1.2\tLyric for
  // measure 1 beat 2\t.1.1\tLyric for measure 2 beat 1	"). See
  // SetTrackMIDILyrics
  bool (*GetTrackMIDILyrics)(MediaTrack *track, int flag, char *bufWantNeedBig,
                             int *bufWantNeedBig_sz);

  //==============================================
  // GetTrackMIDINoteName
  // see GetTrackMIDINoteNameEx
  const char *(*GetTrackMIDINoteName)(int track, int pitch, int chan);

  //==============================================
  // GetTrackMIDINoteNameEx
  // Get note/CC name. pitch 128 for CC0 name, 129 for CC1 name, etc. See
  // SetTrackMIDINoteNameEx
  const char *(*GetTrackMIDINoteNameEx)(ReaProject *proj, MediaTrack *track,
                                        int pitch, int chan);

  //==============================================
  // GetTrackMIDINoteRange
  void (*GetTrackMIDINoteRange)(ReaProject *proj, MediaTrack *track,
                                int *note_loOut, int *note_hiOut);

  //==============================================
  // GetTrackName
  // Returns "MASTER" for master track, "Track N" if track has no name.
  bool (*GetTrackName)(MediaTrack *track, char *bufOut, int bufOut_sz);

  //==============================================
  // GetTrackNumMediaItems
  int (*GetTrackNumMediaItems)(MediaTrack *tr);

  //==============================================
  // GetTrackNumSends
  // returns number of sends/receives/hardware outputs - category is <0 for
  // receives, 0=sends, >0 for hardware outputs
  int (*GetTrackNumSends)(MediaTrack *tr, int category);

  //==============================================
  // GetTrackReceiveName
  // See GetTrackSendName.
  bool (*GetTrackReceiveName)(MediaTrack *track, int recv_index, char *buf,
                              int buf_sz);

  //==============================================
  // GetTrackReceiveUIMute
  // See GetTrackSendUIMute.
  bool (*GetTrackReceiveUIMute)(MediaTrack *track, int recv_index,
                                bool *muteOut);

  //==============================================
  // GetTrackReceiveUIVolPan
  // See GetTrackSendUIVolPan.
  bool (*GetTrackReceiveUIVolPan)(MediaTrack *track, int recv_index,
                                  double *volumeOut, double *panOut);

  //==============================================
  // GetTrackSendInfo_Value
  // Get send/receive/hardware output numerical-value attributes.
  // category is <0 for receives, 0=sends, >0 for hardware outputs
  // parameter names:
  // B_MUTE : bool *
  // B_PHASE : bool *, true to flip phase
  // B_MONO : bool *
  // D_VOL : double *, 1.0 = +0dB etc
  // D_PAN : double *, -1..+1
  // D_PANLAW : double *,1.0=+0.0db, 0.5=-6dB, -1.0 = projdef etc
  // I_SENDMODE : int *, 0=post-fader, 1=pre-fx, 2=post-fx (deprecated),
  // 3=post-fx I_AUTOMODE : int * : automation mode (-1=use track automode,
  // 0=trim/off, 1=read, 2=touch, 3=write, 4=latch) I_SRCCHAN : int *,
  // index,&1024=mono, -1 for none I_DSTCHAN : int *, index, &1024=mono,
  // otherwise stereo pair, hwout:&512=rearoute I_MIDIFLAGS : int *, low 5
  // bits=source channel 0=all, 1-16, next 5 bits=dest channel, 0=orig,
  // 1-16=chanP_DESTTRACK : read only, returns MediaTrack *, destination track,
  // only applies for sends/recvs P_SRCTRACK : read only, returns MediaTrack *,
  // source track, only applies for sends/recvs P_ENV:<envchunkname : read only,
  // returns TrackEnvelope *. Call with :<VOLENV, :<PANENV, etc appended. See
  // CreateTrackSend, RemoveTrackSend, GetTrackNumSends.
  double (*GetTrackSendInfo_Value)(MediaTrack *tr, int category, int sendidx,
                                   const char *parmname);

  //==============================================
  // GetTrackSendName
  // send_idx>=0 for hw ouputs, >=nb_of_hw_ouputs for sends. See
  // GetTrackReceiveName.
  bool (*GetTrackSendName)(MediaTrack *track, int send_index, char *buf,
                           int buf_sz);

  //==============================================
  // GetTrackSendUIMute
  // send_idx>=0 for hw ouputs, >=nb_of_hw_ouputs for sends. See
  // GetTrackReceiveUIMute.
  bool (*GetTrackSendUIMute)(MediaTrack *track, int send_index, bool *muteOut);

  //==============================================
  // GetTrackSendUIVolPan
  // send_idx>=0 for hw ouputs, >=nb_of_hw_ouputs for sends. See
  // GetTrackReceiveUIVolPan.
  bool (*GetTrackSendUIVolPan)(MediaTrack *track, int send_index,
                               double *volumeOut, double *panOut);

  //==============================================
  // GetTrackState
  // Gets track state, returns track name.
  // flags will be set to:
  // &1=folder
  // &2=selected
  // &4=has fx enabled
  // &8=muted
  // &16=soloed
  // &32=SIP'd (with &16)
  // &64=rec armed
  // &128=rec monitoring on
  // &256=rec monitoring auto
  // &512=hide from TCP
  // &1024=hide from MCP
  const char *(*GetTrackState)(MediaTrack *track, int *flagsOut);

  //==============================================
  // GetTrackStateChunk
  // Gets the RPPXML state of a track, returns true if successful. Undo flag is
  // a performance/caching hint.
  bool (*GetTrackStateChunk)(MediaTrack *track, char *strNeedBig,
                             int strNeedBig_sz, bool isundoOptional);

  //==============================================
  // GetTrackUIMute
  bool (*GetTrackUIMute)(MediaTrack *track, bool *muteOut);

  //==============================================
  // GetTrackUIPan
  bool (*GetTrackUIPan)(MediaTrack *track, double *pan1Out, double *pan2Out,
                        int *panmodeOut);

  //==============================================
  // GetTrackUIVolPan
  bool (*GetTrackUIVolPan)(MediaTrack *track, double *volumeOut,
                           double *panOut);

  //==============================================
  // GetUnderrunTime
  // retrieves the last timestamps of audio xrun (yellow-flash, if available),
  // media xrun (red-flash), and the current time stamp (all milliseconds)
  void (*GetUnderrunTime)(unsigned int *audio_xrunOutOptional,
                          unsigned int *media_xrunOutOptional,
                          unsigned int *curtimeOutOptional);

  //==============================================
  // GetUserFileNameForRead
  // returns true if the user selected a valid file, false if the user canceled
  // the dialog
  bool (*GetUserFileNameForRead)(char *filenameNeed4096, const char *title,
                                 const char *defext);

  //==============================================
  // GetUserInputs
  // Get values from the user.
  // If a caption begins with *, for example "*password", the edit field will
  // not display the input text. Maximum fields is 16. Values are returned as a
  // comma-separated string. Returns false if the user canceled the dialog. You
  // can supply special extra information via additional caption fields:
  // extrawidth=XXX to increase text field width, separator=X to use a different
  // separator for returned fields.
  bool (*GetUserInputs)(const char *title, int num_inputs,
                        const char *captions_csv, char *retvals_csv,
                        int retvals_csv_sz);

  //==============================================
  // GoToMarker
  // Go to marker. If use_timeline_order==true, marker_index 1 refers to the
  // first marker on the timeline.  If use_timeline_order==false, marker_index 1
  // refers to the first marker with the user-editable index of 1.
  void (*GoToMarker)(ReaProject *proj, int marker_index,
                     bool use_timeline_order);

  //==============================================
  // GoToRegion
  // Seek to region after current region finishes playing (smooth seek). If
  // use_timeline_order==true, region_index 1 refers to the first region on the
  // timeline.  If use_timeline_order==false, region_index 1 refers to the first
  // region with the user-editable index of 1.
  void (*GoToRegion)(ReaProject *proj, int region_index,
                     bool use_timeline_order);

  //==============================================
  // GR_SelectColor
  // Runs the system color chooser dialog.  Returns 0 if the user cancels the
  // dialog.
  int (*GR_SelectColor)(HWND hwnd, int *colorOut);

  //==============================================
  // GSC_mainwnd
  // this is just like win32 GetSysColor() but can have overrides.
  int (*GSC_mainwnd)(int t);

  //==============================================
  // guidToString
  // dest should be at least 64 chars long to be safe
  void (*guidToString)(const GUID *g, char *destNeed64);

  //==============================================
  // HasExtState
  // Returns true if there exists an extended state value for a specific section
  // and key. See SetExtState, GetExtState, DeleteExtState.
  bool (*HasExtState)(const char *section, const char *key);

  //==============================================
  // HasTrackMIDIPrograms
  // returns name of track plugin that is supplying MIDI programs,or NULL if
  // there is none
  const char *(*HasTrackMIDIPrograms)(int track);

  //==============================================
  // HasTrackMIDIProgramsEx
  // returns name of track plugin that is supplying MIDI programs,or NULL if
  // there is none
  const char *(*HasTrackMIDIProgramsEx)(ReaProject *proj, MediaTrack *track);

  //==============================================
  // Help_Set
  void (*Help_Set)(const char *helpstring, bool is_temporary_help);

  //==============================================
  // HiresPeaksFromSource
  void (*HiresPeaksFromSource)(PCM_source *src,
                               PCM_source_peaktransfer_t *block);

  //==============================================
  // image_resolve_fn
  void (*image_resolve_fn)(const char *in, char *out, int out_sz);

  //==============================================
  // InsertAutomationItem
  // Insert a new automation item. pool_id < 0 collects existing envelope points
  // into the automation item; if pool_id is >= 0 the automation item will be a
  // new instance of that pool (which will be created as an empty instance if it
  // does not exist). Returns the index of the item, suitable for passing to
  // other automation item API functions. See GetSetAutomationItemInfo.
  int (*InsertAutomationItem)(TrackEnvelope *env, int pool_id, double position,
                              double length);

  //==============================================
  // InsertEnvelopePoint
  // Insert an envelope point. If setting multiple points at once, set
  // noSort=true, and call Envelope_SortPoints when done. See
  // InsertEnvelopePointEx.
  bool (*InsertEnvelopePoint)(TrackEnvelope *envelope, double time,
                              double value, int shape, double tension,
                              bool selected, bool *noSortInOptional);

  //==============================================
  // InsertEnvelopePointEx
  // Insert an envelope point. If setting multiple points at once, set
  // noSort=true, and call Envelope_SortPoints when done. autoitem_idx=-1 for
  // the underlying envelope, 0 for the first automation item on the envelope,
  // etc. For automation items, pass autoitem_idx|0x10000000 to base ptidx on
  // the number of points in one full loop iteration, even if the automation
  // item is trimmed so that not all points are visible. Otherwise, ptidx will
  // be based on the number of visible points in the automation item, including
  // all loop iterations. See CountEnvelopePointsEx, GetEnvelopePointEx,
  // SetEnvelopePointEx, DeleteEnvelopePointEx.
  bool (*InsertEnvelopePointEx)(TrackEnvelope *envelope, int autoitem_idx,
                                double time, double value, int shape,
                                double tension, bool selected,
                                bool *noSortInOptional);

  //==============================================
  // InsertMedia
  // mode: 0=add to current track, 1=add new track, 3=add to selected items as
  // takes, &4=stretch/loop to fit time sel, &8=try to match tempo 1x, &16=try
  // to match tempo 0.5x, &32=try to match tempo 2x, &64=don't preserve pitch
  // when matching tempo, &128=no loop/section if startpct/endpct set,
  // &256=force loop regardless of global preference for looping imported items,
  // &512=use high word as absolute track index if mode&3==0, &1024=insert into
  // reasamplomatic on a new track, &2048=insert into open reasamplomatic
  // instance, &4096=move to source preferred position (BWF start offset),
  // &8192=reverse
  int (*InsertMedia)(const char *file, int mode);

  //==============================================
  // InsertMediaSection
  // See InsertMedia.
  int (*InsertMediaSection)(const char *file, int mode, double startpct,
                            double endpct, double pitchshift);

  //==============================================
  // InsertTrackAtIndex
  // inserts a track at idx,of course this will be clamped to 0..GetNumTracks().
  // wantDefaults=TRUE for default envelopes/FX,otherwise no enabled fx/env
  void (*InsertTrackAtIndex)(int idx, bool wantDefaults);

  //==============================================
  // IsInRealTimeAudio
  // are we in a realtime audio thread (between OnAudioBuffer calls,not in some
  // worker/anticipative FX thread)? threadsafe
  int (*IsInRealTimeAudio)();

  //==============================================
  // IsItemTakeActiveForPlayback
  // get whether a take will be played (active take, unmuted, etc)
  bool (*IsItemTakeActiveForPlayback)(MediaItem *item, MediaItem_Take *take);

  //==============================================
  // IsMediaExtension
  // Tests a file extension (i.e. "wav" or "mid") to see if it's a media
  // extension. If wantOthers is set, then "RPP", "TXT" and other project-type
  // formats will also pass.
  bool (*IsMediaExtension)(const char *ext, bool wantOthers);

  //==============================================
  // IsMediaItemSelected
  bool (*IsMediaItemSelected)(MediaItem *item);

  //==============================================
  // IsProjectDirty
  // Is the project dirty (needing save)? Always returns 0 if 'undo/prompt to
  // save' is disabled in preferences.
  int (*IsProjectDirty)(ReaProject *proj);

  //==============================================
  // IsREAPER
  // Returns true if dealing with REAPER, returns false for ReaMote, etc
  bool (*IsREAPER)();

  //==============================================
  // IsTrackSelected
  bool (*IsTrackSelected)(MediaTrack *track);

  //==============================================
  // IsTrackVisible
  // If mixer==true, returns true if the track is visible in the mixer.  If
  // mixer==false, returns true if the track is visible in the track control
  // panel.
  bool (*IsTrackVisible)(MediaTrack *track, bool mixer);

  //==============================================
  // joystick_create
  // creates a joystick device
  joystick_device *(*joystick_create)(const GUID *guid);

  //==============================================
  // joystick_destroy
  // destroys a joystick device
  void (*joystick_destroy)(joystick_device *device);

  //==============================================
  // joystick_enum
  // enumerates installed devices, returns GUID as a string
  const char *(*joystick_enum)(int index, const char **namestrOutOptional);

  //==============================================
  // joystick_getaxis
  // returns axis value (-1..1)
  double (*joystick_getaxis)(joystick_device *dev, int axis);

  //==============================================
  // joystick_getbuttonmask
  // returns button pressed mask, 1=first button, 2=second...
  unsigned int (*joystick_getbuttonmask)(joystick_device *dev);

  //==============================================
  // joystick_getinfo
  // returns button count
  int (*joystick_getinfo)(joystick_device *dev, int *axesOutOptional,
                          int *povsOutOptional);

  //==============================================
  // joystick_getpov
  // returns POV value (usually 0..655.35, or 655.35 on error)
  double (*joystick_getpov)(joystick_device *dev, int pov);

  //==============================================
  // joystick_update
  // Updates joystick state from hardware, returns true if successful
  // (joystick_get* will not be valid until joystick_update() is called
  // successfully)
  bool (*joystick_update)(joystick_device *dev);

  //==============================================
  // kbd_enumerateActions
  int (*kbd_enumerateActions)(KbdSectionInfo *section, int idx,
                              const char **nameOut);

  //==============================================
  // kbd_formatKeyName
  void (*kbd_formatKeyName)(ACCEL *ac, char *s);

  //==============================================
  // kbd_getCommandName
  // Get the string of a key assigned to command "cmd" in a section.
  // This function is poorly named as it doesn't return the command's name, see
  // kbd_getTextFromCmd.
  void (*kbd_getCommandName)(int cmd, char *s, KbdSectionInfo *section);

  //==============================================
  // kbd_getTextFromCmd
  const char *(*kbd_getTextFromCmd)(DWORD cmd, KbdSectionInfo *section);

  //==============================================
  // KBD_OnMainActionEx
  // val/valhw are used for midi stuff.
  // val=[0..127] and valhw=-1 (midi CC),
  // valhw >=0 (midi pitch (valhw | val<<7)),
  // relmode absolute (0) or 1/2/3 for relative adjust modes
  int (*KBD_OnMainActionEx)(int cmd, int val, int valhw, int relmode, HWND hwnd,
                            ReaProject *proj);

  //==============================================
  // kbd_OnMidiEvent
  // can be called from anywhere (threadsafe)
  void (*kbd_OnMidiEvent)(MIDI_event_t *evt, int dev_index);

  //==============================================
  // kbd_OnMidiList
  // can be called from anywhere (threadsafe)
  void (*kbd_OnMidiList)(MIDI_eventlist *list, int dev_index);

  //==============================================
  // kbd_ProcessActionsMenu
  void (*kbd_ProcessActionsMenu)(HMENU menu, KbdSectionInfo *section);

  //==============================================
  // kbd_processMidiEventActionEx
  bool (*kbd_processMidiEventActionEx)(MIDI_event_t *evt,
                                       KbdSectionInfo *section, HWND hwndCtx);

  //==============================================
  // kbd_reprocessMenu
  // Reprocess a menu recursively, setting key assignments to what their command
  // IDs are mapped to.
  void (*kbd_reprocessMenu)(HMENU menu, KbdSectionInfo *section);

  //==============================================
  // kbd_RunCommandThroughHooks
  // actioncommandID may get modified
  bool (*kbd_RunCommandThroughHooks)(KbdSectionInfo *section,
                                     int *actionCommandID, int *val, int *valhw,
                                     int *relmode, HWND hwnd);

  //==============================================
  // kbd_translateAccelerator
  // Pass in the HWND to receive commands, a MSG of a key command,  and a valid
  // section, and kbd_translateAccelerator() will process it looking for any
  // keys bound to it, and send the messages off. Returns 1 if processed, 0 if
  // no key binding found.
  int (*kbd_translateAccelerator)(HWND hwnd, MSG *msg, KbdSectionInfo *section);

  //==============================================
  // kbd_translateMouse
  bool (*kbd_translateMouse)(void *winmsg, unsigned char *midimsg);

  //==============================================
  // LICE__Destroy
  void (*LICE__Destroy)(LICE_IBitmap *bm);

  //==============================================
  // LICE__DestroyFont
  void (*LICE__DestroyFont)(LICE_IFont *font);

  //==============================================
  // LICE__DrawText
  int (*LICE__DrawText)(LICE_IFont *font, LICE_IBitmap *bm, const char *str,
                        int strcnt, RECT *rect, UINT dtFlags);

  //==============================================
  // LICE__GetBits
  void *(*LICE__GetBits)(LICE_IBitmap *bm);

  //==============================================
  // LICE__GetDC
  HDC (*LICE__GetDC)(LICE_IBitmap *bm);

  //==============================================
  // LICE__GetHeight
  int (*LICE__GetHeight)(LICE_IBitmap *bm);

  //==============================================
  // LICE__GetRowSpan
  int (*LICE__GetRowSpan)(LICE_IBitmap *bm);

  //==============================================
  // LICE__GetWidth
  int (*LICE__GetWidth)(LICE_IBitmap *bm);

  //==============================================
  // LICE__IsFlipped
  bool (*LICE__IsFlipped)(LICE_IBitmap *bm);

  //==============================================
  // LICE__resize
  bool (*LICE__resize)(LICE_IBitmap *bm, int w, int h);

  //==============================================
  // LICE__SetBkColor
  LICE_pixel (*LICE__SetBkColor)(LICE_IFont *font, LICE_pixel color);

  //==============================================
  // LICE__SetFromHFont
  // font must REMAIN valid,unless LICE_FONT_FLAG_PRECALCALL is set
  void (*LICE__SetFromHFont)(LICE_IFont *font, HFONT hfont, int flags);

  //==============================================
  // LICE__SetTextColor
  LICE_pixel (*LICE__SetTextColor)(LICE_IFont *font, LICE_pixel color);

  //==============================================
  // LICE__SetTextCombineMode
  void (*LICE__SetTextCombineMode)(LICE_IFont *ifont, int mode, float alpha);

  //==============================================
  // LICE_Arc
  void (*LICE_Arc)(LICE_IBitmap *dest, float cx, float cy, float r,
                   float minAngle, float maxAngle, LICE_pixel color,
                   float alpha, int mode, bool aa);

  //==============================================
  // LICE_Blit
  void (*LICE_Blit)(LICE_IBitmap *dest, LICE_IBitmap *src, int dstx, int dsty,
                    int srcx, int srcy, int srcw, int srch, float alpha,
                    int mode);

  //==============================================
  // LICE_Blur
  void (*LICE_Blur)(LICE_IBitmap *dest, LICE_IBitmap *src, int dstx, int dsty,
                    int srcx, int srcy, int srcw, int srch);

  //==============================================
  // LICE_BorderedRect
  void (*LICE_BorderedRect)(LICE_IBitmap *dest, int x, int y, int w, int h,
                            LICE_pixel bgcolor, LICE_pixel fgcolor, float alpha,
                            int mode);

  //==============================================
  // LICE_Circle
  void (*LICE_Circle)(LICE_IBitmap *dest, float cx, float cy, float r,
                      LICE_pixel color, float alpha, int mode, bool aa);

  //==============================================
  // LICE_Clear
  void (*LICE_Clear)(LICE_IBitmap *dest, LICE_pixel color);

  //==============================================
  // LICE_ClearRect
  void (*LICE_ClearRect)(LICE_IBitmap *dest, int x, int y, int w, int h,
                         LICE_pixel mask, LICE_pixel orbits);

  //==============================================
  // LICE_ClipLine
  // Returns false if the line is entirely offscreen.
  bool (*LICE_ClipLine)(int *pX1Out, int *pY1Out, int *pX2Out, int *pY2Out,
                        int xLo, int yLo, int xHi, int yHi);

  //==============================================
  // LICE_Copy
  void (*LICE_Copy)(LICE_IBitmap *dest, LICE_IBitmap *src);

  //==============================================
  // LICE_CreateBitmap
  // create a new bitmap. this is like calling new LICE_MemBitmap (mode=0) or
  // new LICE_SysBitmap (mode=1).
  LICE_IBitmap *(*LICE_CreateBitmap)(int mode, int w, int h);

  //==============================================
  // LICE_CreateFont
  LICE_IFont *(*LICE_CreateFont)();

  //==============================================
  // LICE_DrawCBezier
  void (*LICE_DrawCBezier)(LICE_IBitmap *dest, double xstart, double ystart,
                           double xctl1, double yctl1, double xctl2,
                           double yctl2, double xend, double yend,
                           LICE_pixel color, float alpha, int mode, bool aa,
                           double tol);

  //==============================================
  // LICE_DrawChar
  void (*LICE_DrawChar)(LICE_IBitmap *bm, int x, int y, char c,
                        LICE_pixel color, float alpha, int mode);

  //==============================================
  // LICE_DrawGlyph
  void (*LICE_DrawGlyph)(LICE_IBitmap *dest, int x, int y, LICE_pixel color,
                         LICE_pixel_chan *alphas, int glyph_w, int glyph_h,
                         float alpha, int mode);

  //==============================================
  // LICE_DrawRect
  void (*LICE_DrawRect)(LICE_IBitmap *dest, int x, int y, int w, int h,
                        LICE_pixel color, float alpha, int mode);

  //==============================================
  // LICE_DrawText
  void (*LICE_DrawText)(LICE_IBitmap *bm, int x, int y, const char *string,
                        LICE_pixel color, float alpha, int mode);

  //==============================================
  // LICE_FillCBezier
  void (*LICE_FillCBezier)(LICE_IBitmap *dest, double xstart, double ystart,
                           double xctl1, double yctl1, double xctl2,
                           double yctl2, double xend, double yend, int yfill,
                           LICE_pixel color, float alpha, int mode, bool aa,
                           double tol);

  //==============================================
  // LICE_FillCircle
  void (*LICE_FillCircle)(LICE_IBitmap *dest, float cx, float cy, float r,
                          LICE_pixel color, float alpha, int mode, bool aa);

  //==============================================
  // LICE_FillConvexPolygon
  void (*LICE_FillConvexPolygon)(LICE_IBitmap *dest, int *x, int *y,
                                 int npoints, LICE_pixel color, float alpha,
                                 int mode);

  //==============================================
  // LICE_FillRect
  void (*LICE_FillRect)(LICE_IBitmap *dest, int x, int y, int w, int h,
                        LICE_pixel color, float alpha, int mode);

  //==============================================
  // LICE_FillTrapezoid
  void (*LICE_FillTrapezoid)(LICE_IBitmap *dest, int x1a, int x1b, int y1,
                             int x2a, int x2b, int y2, LICE_pixel color,
                             float alpha, int mode);

  //==============================================
  // LICE_FillTriangle
  void (*LICE_FillTriangle)(LICE_IBitmap *dest, int x1, int y1, int x2, int y2,
                            int x3, int y3, LICE_pixel color, float alpha,
                            int mode);

  //==============================================
  // LICE_GetPixel
  LICE_pixel (*LICE_GetPixel)(LICE_IBitmap *bm, int x, int y);

  //==============================================
  // LICE_GradRect
  void (*LICE_GradRect)(LICE_IBitmap *dest, int dstx, int dsty, int dstw,
                        int dsth, float ir, float ig, float ib, float ia,
                        float drdx, float dgdx, float dbdx, float dadx,
                        float drdy, float dgdy, float dbdy, float dady,
                        int mode);

  //==============================================
  // LICE_Line
  void (*LICE_Line)(LICE_IBitmap *dest, float x1, float y1, float x2, float y2,
                    LICE_pixel color, float alpha, int mode, bool aa);

  //==============================================
  // LICE_LineInt
  void (*LICE_LineInt)(LICE_IBitmap *dest, int x1, int y1, int x2, int y2,
                       LICE_pixel color, float alpha, int mode, bool aa);

  //==============================================
  // LICE_LoadPNG
  LICE_IBitmap *(*LICE_LoadPNG)(const char *filename, LICE_IBitmap *bmp);

  //==============================================
  // LICE_LoadPNGFromResource
  LICE_IBitmap *(*LICE_LoadPNGFromResource)(HINSTANCE hInst, const char *resid,
                                            LICE_IBitmap *bmp);

  //==============================================
  // LICE_MeasureText
  void (*LICE_MeasureText)(const char *string, int *w, int *h);

  //==============================================
  // LICE_MultiplyAddRect
  void (*LICE_MultiplyAddRect)(LICE_IBitmap *dest, int x, int y, int w, int h,
                               float rsc, float gsc, float bsc, float asc,
                               float radd, float gadd, float badd, float aadd);

  //==============================================
  // LICE_PutPixel
  void (*LICE_PutPixel)(LICE_IBitmap *bm, int x, int y, LICE_pixel color,
                        float alpha, int mode);

  //==============================================
  // LICE_RotatedBlit
  // these coordinates are offset from the center of the image,in source pixel
  // coordinates
  void (*LICE_RotatedBlit)(LICE_IBitmap *dest, LICE_IBitmap *src, int dstx,
                           int dsty, int dstw, int dsth, float srcx, float srcy,
                           float srcw, float srch, float angle,
                           bool cliptosourcerect, float alpha, int mode,
                           float rotxcent, float rotycent);

  //==============================================
  // LICE_RoundRect
  void (*LICE_RoundRect)(LICE_IBitmap *drawbm, float xpos, float ypos, float w,
                         float h, int cornerradius, LICE_pixel col, float alpha,
                         int mode, bool aa);

  //==============================================
  // LICE_ScaledBlit
  void (*LICE_ScaledBlit)(LICE_IBitmap *dest, LICE_IBitmap *src, int dstx,
                          int dsty, int dstw, int dsth, float srcx, float srcy,
                          float srcw, float srch, float alpha, int mode);

  //==============================================
  // LICE_SimpleFill
  void (*LICE_SimpleFill)(LICE_IBitmap *dest, int x, int y, LICE_pixel newcolor,
                          LICE_pixel comparemask, LICE_pixel keepmask);

  // !REAPERAPI_NO_LICE
  //==============================================
  // LocalizeString
  // Returns a localized version of src_string, in section section. flags can
  // have 1 set to only localize if sprintf-style formatting matches the
  // original.
  const char *(*LocalizeString)(const char *src_string, const char *section,
                                int flagsOptional);

  //==============================================
  // Loop_OnArrow
  // Move the loop selection left or right. Returns true if snap is enabled.
  bool (*Loop_OnArrow)(ReaProject *project, int direction);

  //==============================================
  // Main_OnCommand
  // See Main_OnCommandEx.
  void (*Main_OnCommand)(int command, int flag);

  //==============================================
  // Main_OnCommandEx
  // Performs an action belonging to the main action section. To perform
  // non-native actions (ReaScripts, custom or extension plugins' actions)
  // safely, see NamedCommandLookup().
  void (*Main_OnCommandEx)(int command, int flag, ReaProject *proj);

  //==============================================
  // Main_openProject
  // opens a project. will prompt the user to save unless name is prefixed with
  // 'noprompt:'. If name is prefixed with 'template:', project file will be
  // loaded as a template. If passed a .RTrackTemplate file, adds the template
  // to the existing project.
  void (*Main_openProject)(const char *name);

  //==============================================
  // Main_SaveProject
  // Save the project.
  void (*Main_SaveProject)(ReaProject *proj, bool forceSaveAsInOptional);

  //==============================================
  // Main_UpdateLoopInfo
  void (*Main_UpdateLoopInfo)(int ignoremask);

  //==============================================
  // MarkProjectDirty
  // Marks project as dirty (needing save) if 'undo/prompt to save' is enabled
  // in preferences.
  void (*MarkProjectDirty)(ReaProject *proj);

  //==============================================
  // MarkTrackItemsDirty
  // If track is supplied, item is ignored
  void (*MarkTrackItemsDirty)(MediaTrack *track, MediaItem *item);

  //==============================================
  // Master_GetPlayRate
  double (*Master_GetPlayRate)(ReaProject *project);

  //==============================================
  // Master_GetPlayRateAtTime
  double (*Master_GetPlayRateAtTime)(double time_s, ReaProject *proj);

  //==============================================
  // Master_GetTempo
  double (*Master_GetTempo)();

  //==============================================
  // Master_NormalizePlayRate
  // Convert play rate to/from a value between 0 and 1, representing the
  // position on the project playrate slider.
  double (*Master_NormalizePlayRate)(double playrate, bool isnormalized);

  //==============================================
  // Master_NormalizeTempo
  // Convert the tempo to/from a value between 0 and 1, representing bpm in the
  // range of 40-296 bpm.
  double (*Master_NormalizeTempo)(double bpm, bool isnormalized);

  //==============================================
  // MB
  // type 0=OK,1=OKCANCEL,2=ABORTRETRYIGNORE,3=YESNOCANCEL,4=YESNO,5=RETRYCANCEL
  // : ret 1=OK,2=CANCEL,3=ABORT,4=RETRY,5=IGNORE,6=YES,7=NO
  int (*MB)(const char *msg, const char *title, int type);

  //==============================================
  // MediaItemDescendsFromTrack
  // Returns 1 if the track holds the item, 2 if the track is a folder
  // containing the track that holds the item, etc.
  int (*MediaItemDescendsFromTrack)(MediaItem *item, MediaTrack *track);

  //==============================================
  // MIDI_CountEvts
  // Count the number of notes, CC events, and text/sysex events in a given MIDI
  // item.
  int (*MIDI_CountEvts)(MediaItem_Take *take, int *notecntOut, int *ccevtcntOut,
                        int *textsyxevtcntOut);

  //==============================================
  // MIDI_DeleteCC
  // Delete a MIDI CC event.
  bool (*MIDI_DeleteCC)(MediaItem_Take *take, int ccidx);

  //==============================================
  // MIDI_DeleteEvt
  // Delete a MIDI event.
  bool (*MIDI_DeleteEvt)(MediaItem_Take *take, int evtidx);

  //==============================================
  // MIDI_DeleteNote
  // Delete a MIDI note.
  bool (*MIDI_DeleteNote)(MediaItem_Take *take, int noteidx);

  //==============================================
  // MIDI_DeleteTextSysexEvt
  // Delete a MIDI text or sysex event.
  bool (*MIDI_DeleteTextSysexEvt)(MediaItem_Take *take, int textsyxevtidx);

  //==============================================
  // MIDI_DisableSort
  // Disable sorting for all MIDI insert, delete, get and set functions, until
  // MIDI_Sort is called.
  void (*MIDI_DisableSort)(MediaItem_Take *take);

  //==============================================
  // MIDI_EnumSelCC
  // Returns the index of the next selected MIDI CC event after ccidx (-1 if
  // there are no more selected events).
  int (*MIDI_EnumSelCC)(MediaItem_Take *take, int ccidx);

  //==============================================
  // MIDI_EnumSelEvts
  // Returns the index of the next selected MIDI event after evtidx (-1 if there
  // are no more selected events).
  int (*MIDI_EnumSelEvts)(MediaItem_Take *take, int evtidx);

  //==============================================
  // MIDI_EnumSelNotes
  // Returns the index of the next selected MIDI note after noteidx (-1 if there
  // are no more selected events).
  int (*MIDI_EnumSelNotes)(MediaItem_Take *take, int noteidx);

  //==============================================
  // MIDI_EnumSelTextSysexEvts
  // Returns the index of the next selected MIDI text/sysex event after
  // textsyxidx (-1 if there are no more selected events).
  int (*MIDI_EnumSelTextSysexEvts)(MediaItem_Take *take, int textsyxidx);

  //==============================================
  // MIDI_eventlist_Create
  // Create a MIDI_eventlist object. The returned object must be deleted with
  // MIDI_eventlist_destroy().
  MIDI_eventlist *(*MIDI_eventlist_Create)();

  //==============================================
  // MIDI_eventlist_Destroy
  // Destroy a MIDI_eventlist object that was created using
  // MIDI_eventlist_Create().
  void (*MIDI_eventlist_Destroy)(MIDI_eventlist *evtlist);

  //==============================================
  // MIDI_GetAllEvts
  // Get all MIDI data. MIDI buffer is returned as a list of { int offset, char
  // flag, int msglen, unsigned char msg[] }. offset: MIDI ticks from previous
  // event flag: &1=selected &2=muted flag high 4 bits for CC shape: &16=linear,
  // &32=slow start/end, &16|32=fast start, &64=fast end, &64|16=bezier msg: the
  // MIDI message. A meta-event of type 0xF followed by 'CCBZ ' and 5 more bytes
  // represents bezier curve data for the previous MIDI event: 1 byte for the
  // bezier type (usually 0) and 4 bytes for the bezier tension as a float. For
  // tick intervals longer than a 32 bit word can represent, zero-length meta
  // events may be placed between valid events. See MIDI_SetAllEvts.
  bool (*MIDI_GetAllEvts)(MediaItem_Take *take, char *bufNeedBig,
                          int *bufNeedBig_sz);

  //==============================================
  // MIDI_GetCC
  // Get MIDI CC event properties.
  bool (*MIDI_GetCC)(MediaItem_Take *take, int ccidx, bool *selectedOut,
                     bool *mutedOut, double *ppqposOut, int *chanmsgOut,
                     int *chanOut, int *msg2Out, int *msg3Out);

  //==============================================
  // MIDI_GetCCShape
  // Get CC shape and bezier tension. See MIDI_GetCC, MIDI_SetCCShape
  bool (*MIDI_GetCCShape)(MediaItem_Take *take, int ccidx, int *shapeOut,
                          double *beztensionOut);

  //==============================================
  // MIDI_GetEvt
  // Get MIDI event properties.
  bool (*MIDI_GetEvt)(MediaItem_Take *take, int evtidx, bool *selectedOut,
                      bool *mutedOut, double *ppqposOut, char *msg,
                      int *msg_sz);

  //==============================================
  // MIDI_GetGrid
  // Returns the most recent MIDI editor grid size for this MIDI take, in QN.
  // Swing is between 0 and 1. Note length is 0 if it follows the grid size.
  double (*MIDI_GetGrid)(MediaItem_Take *take, double *swingOutOptional,
                         double *noteLenOutOptional);

  //==============================================
  // MIDI_GetHash
  // Get a string that only changes when the MIDI data changes. If
  // notesonly==true, then the string changes only when the MIDI notes change.
  // See MIDI_GetTrackHash
  bool (*MIDI_GetHash)(MediaItem_Take *take, bool notesonly, char *hash,
                       int hash_sz);

  //==============================================
  // MIDI_GetNote
  // Get MIDI note properties.
  bool (*MIDI_GetNote)(MediaItem_Take *take, int noteidx, bool *selectedOut,
                       bool *mutedOut, double *startppqposOut,
                       double *endppqposOut, int *chanOut, int *pitchOut,
                       int *velOut);

  //==============================================
  // MIDI_GetPPQPos_EndOfMeasure
  // Returns the MIDI tick (ppq) position corresponding to the end of the
  // measure.
  double (*MIDI_GetPPQPos_EndOfMeasure)(MediaItem_Take *take, double ppqpos);

  //==============================================
  // MIDI_GetPPQPos_StartOfMeasure
  // Returns the MIDI tick (ppq) position corresponding to the start of the
  // measure.
  double (*MIDI_GetPPQPos_StartOfMeasure)(MediaItem_Take *take, double ppqpos);

  //==============================================
  // MIDI_GetPPQPosFromProjQN
  // Returns the MIDI tick (ppq) position corresponding to a specific project
  // time in quarter notes.
  double (*MIDI_GetPPQPosFromProjQN)(MediaItem_Take *take, double projqn);

  //==============================================
  // MIDI_GetPPQPosFromProjTime
  // Returns the MIDI tick (ppq) position corresponding to a specific project
  // time in seconds.
  double (*MIDI_GetPPQPosFromProjTime)(MediaItem_Take *take, double projtime);

  //==============================================
  // MIDI_GetProjQNFromPPQPos
  // Returns the project time in quarter notes corresponding to a specific MIDI
  // tick (ppq) position.
  double (*MIDI_GetProjQNFromPPQPos)(MediaItem_Take *take, double ppqpos);

  //==============================================
  // MIDI_GetProjTimeFromPPQPos
  // Returns the project time in seconds corresponding to a specific MIDI tick
  // (ppq) position.
  double (*MIDI_GetProjTimeFromPPQPos)(MediaItem_Take *take, double ppqpos);

  //==============================================
  // MIDI_GetScale
  // Get the active scale in the media source, if any. root 0=C, 1=C#, etc.
  // scale &0x1=root, &0x2=minor 2nd, &0x4=major 2nd, &0x8=minor 3rd,
  // &0xF=fourth, etc.
  bool (*MIDI_GetScale)(MediaItem_Take *take, int *rootOut, int *scaleOut,
                        char *name, int name_sz);

  //==============================================
  // MIDI_GetTextSysexEvt
  // Get MIDI meta-event properties. Allowable types are -1:sysex (msg should
  // not include bounding F0..F7), 1-14:MIDI text event types, 15=REAPER
  // notation event. For all other meta-messages, type is returned as -2 and msg
  // returned as all zeroes. See MIDI_GetEvt.
  bool (*MIDI_GetTextSysexEvt)(MediaItem_Take *take, int textsyxevtidx,
                               bool *selectedOutOptional,
                               bool *mutedOutOptional,
                               double *ppqposOutOptional, int *typeOutOptional,
                               char *msgOptional, int *msgOptional_sz);

  //==============================================
  // MIDI_GetTrackHash
  // Get a string that only changes when the MIDI data changes. If
  // notesonly==true, then the string changes only when the MIDI notes change.
  // See MIDI_GetHash
  bool (*MIDI_GetTrackHash)(MediaTrack *track, bool notesonly, char *hash,
                            int hash_sz);

  //==============================================
  // MIDI_InsertCC
  // Insert a new MIDI CC event.
  bool (*MIDI_InsertCC)(MediaItem_Take *take, bool selected, bool muted,
                        double ppqpos, int chanmsg, int chan, int msg2,
                        int msg3);

  //==============================================
  // MIDI_InsertEvt
  // Insert a new MIDI event.
  bool (*MIDI_InsertEvt)(MediaItem_Take *take, bool selected, bool muted,
                         double ppqpos, const char *bytestr, int bytestr_sz);

  //==============================================
  // MIDI_InsertNote
  // Insert a new MIDI note. Set noSort if inserting multiple events, then call
  // MIDI_Sort when done.
  bool (*MIDI_InsertNote)(MediaItem_Take *take, bool selected, bool muted,
                          double startppqpos, double endppqpos, int chan,
                          int pitch, int vel, const bool *noSortInOptional);

  //==============================================
  // MIDI_InsertTextSysexEvt
  // Insert a new MIDI text or sysex event. Allowable types are -1:sysex (msg
  // should not include bounding F0..F7), 1-14:MIDI text event types, 15=REAPER
  // notation event.
  bool (*MIDI_InsertTextSysexEvt)(MediaItem_Take *take, bool selected,
                                  bool muted, double ppqpos, int type,
                                  const char *bytestr, int bytestr_sz);

  //==============================================
  // midi_reinit
  // Reset all MIDI devices
  void (*midi_reinit)();

  //==============================================
  // MIDI_SelectAll
  // Select or deselect all MIDI content.
  void (*MIDI_SelectAll)(MediaItem_Take *take, bool select);

  //==============================================
  // MIDI_SetAllEvts
  // Set all MIDI data. MIDI buffer is passed in as a list of { int offset, char
  // flag, int msglen, unsigned char msg[] }. offset: MIDI ticks from previous
  // event flag: &1=selected &2=muted flag high 4 bits for CC shape: &16=linear,
  // &32=slow start/end, &16|32=fast start, &64=fast end, &64|16=bezier msg: the
  // MIDI message. A meta-event of type 0xF followed by 'CCBZ ' and 5 more bytes
  // represents bezier curve data for the previous MIDI event: 1 byte for the
  // bezier type (usually 0) and 4 bytes for the bezier tension as a float. For
  // tick intervals longer than a 32 bit word can represent, zero-length meta
  // events may be placed between valid events. See MIDI_GetAllEvts.
  bool (*MIDI_SetAllEvts)(MediaItem_Take *take, const char *buf, int buf_sz);

  //==============================================
  // MIDI_SetCC
  // Set MIDI CC event properties. Properties passed as NULL will not be set.
  // set noSort if setting multiple events, then call MIDI_Sort when done.
  bool (*MIDI_SetCC)(MediaItem_Take *take, int ccidx,
                     const bool *selectedInOptional,
                     const bool *mutedInOptional,
                     const double *ppqposInOptional,
                     const int *chanmsgInOptional, const int *chanInOptional,
                     const int *msg2InOptional, const int *msg3InOptional,
                     const bool *noSortInOptional);

  //==============================================
  // MIDI_SetCCShape
  // Set CC shape and bezier tension. set noSort if setting multiple events,
  // then call MIDI_Sort when done. See MIDI_SetCC, MIDI_GetCCShape
  bool (*MIDI_SetCCShape)(MediaItem_Take *take, int ccidx, int shape,
                          double beztension, const bool *noSortInOptional);

  //==============================================
  // MIDI_SetEvt
  // Set MIDI event properties. Properties passed as NULL will not be set.  set
  // noSort if setting multiple events, then call MIDI_Sort when done.
  bool (*MIDI_SetEvt)(MediaItem_Take *take, int evtidx,
                      const bool *selectedInOptional,
                      const bool *mutedInOptional,
                      const double *ppqposInOptional, const char *msgOptional,
                      int msgOptional_sz, const bool *noSortInOptional);

  //==============================================
  // MIDI_SetItemExtents
  // Set the start/end positions of a media item that contains a MIDI take.
  bool (*MIDI_SetItemExtents)(MediaItem *item, double startQN, double endQN);

  //==============================================
  // MIDI_SetNote
  // Set MIDI note properties. Properties passed as NULL (or negative values)
  // will not be set. Set noSort if setting multiple events, then call MIDI_Sort
  // when done. Setting multiple note start positions at once is done more
  // safely by deleting and re-inserting the notes.
  bool (*MIDI_SetNote)(MediaItem_Take *take, int noteidx,
                       const bool *selectedInOptional,
                       const bool *mutedInOptional,
                       const double *startppqposInOptional,
                       const double *endppqposInOptional,
                       const int *chanInOptional, const int *pitchInOptional,
                       const int *velInOptional, const bool *noSortInOptional);

  //==============================================
  // MIDI_SetTextSysexEvt
  // Set MIDI text or sysex event properties. Properties passed as NULL will not
  // be set. Allowable types are -1:sysex (msg should not include bounding
  // F0..F7), 1-14:MIDI text event types, 15=REAPER notation event. set noSort
  // if setting multiple events, then call MIDI_Sort when done.
  bool (*MIDI_SetTextSysexEvt)(MediaItem_Take *take, int textsyxevtidx,
                               const bool *selectedInOptional,
                               const bool *mutedInOptional,
                               const double *ppqposInOptional,
                               const int *typeInOptional,
                               const char *msgOptional, int msgOptional_sz,
                               const bool *noSortInOptional);

  //==============================================
  // MIDI_Sort
  // Sort MIDI events after multiple calls to MIDI_SetNote, MIDI_SetCC, etc.
  void (*MIDI_Sort)(MediaItem_Take *take);

  //==============================================
  // MIDIEditor_GetActive
  // get a pointer to the focused MIDI editor window
  // see MIDIEditor_GetMode, MIDIEditor_OnCommand
  HWND (*MIDIEditor_GetActive)();

  //==============================================
  // MIDIEditor_GetMode
  // get the mode of a MIDI editor (0=piano roll, 1=event list, -1=invalid
  // editor) see MIDIEditor_GetActive, MIDIEditor_OnCommand
  int (*MIDIEditor_GetMode)(HWND midieditor);

  //==============================================
  // MIDIEditor_GetSetting_int
  // Get settings from a MIDI editor. setting_desc can be:
  // snap_enabled: returns 0 or 1
  // active_note_row: returns 0-127
  // last_clicked_cc_lane: returns 0-127=CC, 0x100|(0-31)=14-bit CC,
  // 0x200=velocity, 0x201=pitch, 0x202=program, 0x203=channel pressure,
  // 0x204=bank/program select, 0x205=text, 0x206=sysex, 0x207=off velocity,
  // 0x208=notation events, 0x210=media item lane default_note_vel: returns
  // 0-127 default_note_chan: returns 0-15 default_note_len: returns default
  // length in MIDI ticks scale_enabled: returns 0-1 scale_root: returns 0-12
  // (0=C) if setting_desc is unsupported, the function returns -1. See
  // MIDIEditor_SetSetting_int, MIDIEditor_GetActive, MIDIEditor_GetSetting_str
  //
  int (*MIDIEditor_GetSetting_int)(HWND midieditor, const char *setting_desc);

  //==============================================
  // MIDIEditor_GetSetting_str
  // Get settings from a MIDI editor. setting_desc can be:
  // last_clicked_cc_lane: returns text description ("velocity", "pitch", etc)
  // scale: returns the scale record, for example "102034050607" for a major
  // scale if setting_desc is unsupported, the function returns false. See
  // MIDIEditor_GetActive, MIDIEditor_GetSetting_int
  //
  bool (*MIDIEditor_GetSetting_str)(HWND midieditor, const char *setting_desc,
                                    char *buf, int buf_sz);

  //==============================================
  // MIDIEditor_GetTake
  // get the take that is currently being edited in this MIDI editor
  MediaItem_Take *(*MIDIEditor_GetTake)(HWND midieditor);

  //==============================================
  // MIDIEditor_LastFocused_OnCommand
  // Send an action command to the last focused MIDI editor. Returns false if
  // there is no MIDI editor open, or if the view mode (piano roll or event
  // list) does not match the input. see MIDIEditor_OnCommand
  bool (*MIDIEditor_LastFocused_OnCommand)(int command_id,
                                           bool islistviewcommand);

  //==============================================
  // MIDIEditor_OnCommand
  // Send an action command to a MIDI editor. Returns false if the supplied MIDI
  // editor pointer is not valid (not an open MIDI editor). see
  // MIDIEditor_GetActive, MIDIEditor_LastFocused_OnCommand
  bool (*MIDIEditor_OnCommand)(HWND midieditor, int command_id);

  //==============================================
  // MIDIEditor_SetSetting_int
  // Set settings for a MIDI editor. setting_desc can be:
  // active_note_row: 0-127
  // See MIDIEditor_GetSetting_int
  //
  bool (*MIDIEditor_SetSetting_int)(HWND midieditor, const char *setting_desc,
                                    int setting);

  //==============================================
  // mkpanstr
  void (*mkpanstr)(char *strNeed64, double pan);

  //==============================================
  // mkvolpanstr
  void (*mkvolpanstr)(char *strNeed64, double vol, double pan);

  //==============================================
  // mkvolstr
  void (*mkvolstr)(char *strNeed64, double vol);

  //==============================================
  // MoveEditCursor
  void (*MoveEditCursor)(double adjamt, bool dosel);

  //==============================================
  // MoveMediaItemToTrack
  // returns TRUE if move succeeded
  bool (*MoveMediaItemToTrack)(MediaItem *item, MediaTrack *desttr);

  //==============================================
  // MuteAllTracks
  void (*MuteAllTracks)(bool mute);

  //==============================================
  // my_getViewport
  void (*my_getViewport)(RECT *r, const RECT *sr, bool wantWorkArea);

  //==============================================
  // NamedCommandLookup
  // Get the command ID number for named command that was registered by an
  // extension such as "_SWS_ABOUT" or "_113088d11ae641c193a2b7ede3041ad5" for a
  // ReaScript or a custom action.
  int (*NamedCommandLookup)(const char *command_name);

  //==============================================
  // OnPauseButton
  // direct way to simulate pause button hit
  void (*OnPauseButton)();

  //==============================================
  // OnPauseButtonEx
  // direct way to simulate pause button hit
  void (*OnPauseButtonEx)(ReaProject *proj);

  //==============================================
  // OnPlayButton
  // direct way to simulate play button hit
  void (*OnPlayButton)();

  //==============================================
  // OnPlayButtonEx
  // direct way to simulate play button hit
  void (*OnPlayButtonEx)(ReaProject *proj);

  //==============================================
  // OnStopButton
  // direct way to simulate stop button hit
  void (*OnStopButton)();

  //==============================================
  // OnStopButtonEx
  // direct way to simulate stop button hit
  void (*OnStopButtonEx)(ReaProject *proj);

  //==============================================
  // OpenColorThemeFile
  bool (*OpenColorThemeFile)(const char *fn);

  //==============================================
  // OpenMediaExplorer
  // Opens mediafn in the Media Explorer, play=true will play the file
  // immediately (or toggle playback if mediafn was already open), =false will
  // just select it.
  HWND (*OpenMediaExplorer)(const char *mediafn, bool play);

  //==============================================
  // OscLocalMessageToHost
  // Send an OSC message directly to REAPER. The value argument may be NULL. The
  // message will be matched against the default OSC patterns. Only supported if
  // control surface support was enabled when installing REAPER.
  void (*OscLocalMessageToHost)(const char *message,
                                const double *valueInOptional);

  //==============================================
  // parse_timestr
  // Parse hh:mm:ss.sss time string, return time in seconds (or 0.0 on error).
  // See parse_timestr_pos, parse_timestr_len.
  double (*parse_timestr)(const char *buf);

  //==============================================
  // parse_timestr_len
  // time formatting mode overrides: -1=proj default.
  // 0=time
  // 1=measures.beats + time
  // 2=measures.beats
  // 3=seconds
  // 4=samples
  // 5=h:m:s:f
  //
  double (*parse_timestr_len)(const char *buf, double offset, int modeoverride);

  //==============================================
  // parse_timestr_pos
  // Parse time string, time formatting mode overrides: -1=proj default.
  // 0=time
  // 1=measures.beats + time
  // 2=measures.beats
  // 3=seconds
  // 4=samples
  // 5=h:m:s:f
  //
  double (*parse_timestr_pos)(const char *buf, int modeoverride);

  //==============================================
  // parsepanstr
  double (*parsepanstr)(const char *str);

  //==============================================
  // PCM_Sink_Create
  PCM_sink *(*PCM_Sink_Create)(const char *filename, const char *cfg,
                               int cfg_sz, int nch, int srate, bool buildpeaks);

  //==============================================
  // PCM_Sink_CreateEx
  PCM_sink *(*PCM_Sink_CreateEx)(ReaProject *proj, const char *filename,
                                 const char *cfg, int cfg_sz, int nch,
                                 int srate, bool buildpeaks);

  //==============================================
  // PCM_Sink_CreateMIDIFile
  PCM_sink *(*PCM_Sink_CreateMIDIFile)(const char *filename, const char *cfg,
                                       int cfg_sz, double bpm, int div);

  //==============================================
  // PCM_Sink_CreateMIDIFileEx
  PCM_sink *(*PCM_Sink_CreateMIDIFileEx)(ReaProject *proj, const char *filename,
                                         const char *cfg, int cfg_sz,
                                         double bpm, int div);

  //==============================================
  // PCM_Sink_Enum
  unsigned int (*PCM_Sink_Enum)(int idx, const char **descstrOut);

  //==============================================
  // PCM_Sink_GetExtension
  const char *(*PCM_Sink_GetExtension)(const char *data, int data_sz);

  //==============================================
  // PCM_Sink_ShowConfig
  HWND (*PCM_Sink_ShowConfig)(const char *cfg, int cfg_sz, HWND hwndParent);

  //==============================================
  // PCM_Source_CreateFromFile
  // See PCM_Source_CreateFromFileEx.
  PCM_source *(*PCM_Source_CreateFromFile)(const char *filename);

  //==============================================
  // PCM_Source_CreateFromFileEx
  // Create a PCM_source from filename, and override pref of MIDI files being
  // imported as in-project MIDI events.
  PCM_source *(*PCM_Source_CreateFromFileEx)(const char *filename,
                                             bool forcenoMidiImp);

  //==============================================
  // PCM_Source_CreateFromSimple
  // Creates a PCM_source from a ISimpleMediaDecoder
  // (if fn is non-null, it will open the file in dec)
  PCM_source *(*PCM_Source_CreateFromSimple)(ISimpleMediaDecoder *dec,
                                             const char *fn);

  //==============================================
  // PCM_Source_CreateFromType
  // Create a PCM_source from a "type" (use this if you're going to load its
  // state via LoadState/ProjectStateContext). Valid types include "WAVE",
  // "MIDI", or whatever plug-ins define as well.
  PCM_source *(*PCM_Source_CreateFromType)(const char *sourcetype);

  //==============================================
  // PCM_Source_Destroy
  // Deletes a PCM_source -- be sure that you remove any project reference
  // before deleting a source
  void (*PCM_Source_Destroy)(PCM_source *src);

  //==============================================
  // PCM_Source_GetPeaks
  // Gets block of peak samples to buf. Note that the peak samples are
  // interleaved, but in two or three blocks (maximums, then minimums, then
  // extra). Return value has 20 bits of returned sample count, then 4 bits of
  // output_mode (0xf00000), then a bit to signify whether extra_type was
  // available (0x1000000). extra_type can be 115 ('s') for spectral
  // information, which will return peak samples as integers with the low 15
  // bits frequency, next 14 bits tonality.
  int (*PCM_Source_GetPeaks)(PCM_source *src, double peakrate, double starttime,
                             int numchannels, int numsamplesperchannel,
                             int want_extra_type, double *buf);

  //==============================================
  // PCM_Source_GetSectionInfo
  // If a section/reverse block, retrieves offset/len/reverse. return true if
  // success
  bool (*PCM_Source_GetSectionInfo)(PCM_source *src, double *offsOut,
                                    double *lenOut, bool *revOut);

  //==============================================
  // PeakBuild_Create
  REAPER_PeakBuild_Interface *(*PeakBuild_Create)(PCM_source *src,
                                                  const char *fn, int srate,
                                                  int nch);

  //==============================================
  // PeakBuild_CreateEx
  // flags&1 for FP support
  REAPER_PeakBuild_Interface *(*PeakBuild_CreateEx)(PCM_source *src,
                                                    const char *fn, int srate,
                                                    int nch, int flags);

  //==============================================
  // PeakGet_Create
  REAPER_PeakGet_Interface *(*PeakGet_Create)(const char *fn, int srate,
                                              int nch);

  //==============================================
  // PitchShiftSubModeMenu
  // menu to select/modify pitch shifter submode, returns new value (or old
  // value if no item selected)
  int (*PitchShiftSubModeMenu)(HWND hwnd, int x, int y, int mode,
                               int submode_sel);

  //==============================================
  // PlayPreview
  // return nonzero on success
  int (*PlayPreview)(preview_register_t *preview);

  //==============================================
  // PlayPreviewEx
  // return nonzero on success. bufflags &1=buffer source, &2=treat length
  // changes in source as varispeed and adjust internal state accordingly if
  // buffering. measure_align<0=play immediately, >0=align playback with measure
  // start
  int (*PlayPreviewEx)(preview_register_t *preview, int bufflags,
                       double measure_align);

  //==============================================
  // PlayTrackPreview
  // return nonzero on success,in these,m_out_chan is a track index (0-n)
  int (*PlayTrackPreview)(preview_register_t *preview);

  //==============================================
  // PlayTrackPreview2
  // return nonzero on success,in these,m_out_chan is a track index (0-n)
  int (*PlayTrackPreview2)(ReaProject *proj, preview_register_t *preview);

  //==============================================
  // PlayTrackPreview2Ex
  // return nonzero on success,in these,m_out_chan is a track index (0-n). see
  // PlayPreviewEx
  int (*PlayTrackPreview2Ex)(ReaProject *proj, preview_register_t *preview,
                             int flags, double measure_align);

  //==============================================
  // plugin_getapi
  void *(*plugin_getapi)(const char *name);

  //==============================================
  // plugin_getFilterList
  // Returns a double-NULL terminated list of importable media files, suitable
  // for passing to GetOpenFileName() etc. Includes *.* (All files).
  const char *(*plugin_getFilterList)();

  //==============================================
  // plugin_getImportableProjectFilterList
  // Returns a double-NULL terminated list of importable project files, suitable
  // for passing to GetOpenFileName() etc. Includes *.* (All files).
  const char *(*plugin_getImportableProjectFilterList)();

  //==============================================
  // plugin_register
  // Alias for reaper_plugin_info_t::Register, see reaper_plugin.h for
  // documented uses.
  int (*plugin_register)(const char *name, void *infostruct);

  //==============================================
  // PluginWantsAlwaysRunFx
  void (*PluginWantsAlwaysRunFx)(int amt);

  //==============================================
  // PreventUIRefresh
  // adds prevent_count to the UI refresh prevention state; always add then
  // remove the same amount, or major disfunction will occur
  void (*PreventUIRefresh)(int prevent_count);

  //==============================================
  // projectconfig_var_addr
  void *(*projectconfig_var_addr)(ReaProject *proj, int idx);

  //==============================================
  // projectconfig_var_getoffs
  // returns offset to pass to projectconfig_var_addr() to get project-config
  // var of name. szout gets size of object.
  int (*projectconfig_var_getoffs)(const char *name, int *szOut);

  //==============================================
  // PromptForAction
  // Uses the action list to choose an action. Call with session_mode=1 to
  // create a session (init_id will be the initial action to select, or 0), then
  // poll with session_mode=0, checking return value for user-selected action
  // (will return 0 if no action selected yet, or -1 if the action window is no
  // longer available). When finished, call with session_mode=-1.
  int (*PromptForAction)(int session_mode, int init_id, int section_id);

  //==============================================
  // realloc_cmd_ptr
  // special use for NeedBig script API functions - reallocates a NeedBig buffer
  // and updates its size, returns false on error
  bool (*realloc_cmd_ptr)(char **ptr, int *ptr_size, int new_size);

  //==============================================
  // ReaperGetPitchShiftAPI
  // version must be REAPER_PITCHSHIFT_API_VER
  IReaperPitchShift *(*ReaperGetPitchShiftAPI)(int version);

  //==============================================
  // ReaScriptError
  // Causes REAPER to display the error message after the current ReaScript
  // finishes.
  void (*ReaScriptError)(const char *errmsg);

  //==============================================
  // RecursiveCreateDirectory
  // returns positive value on success, 0 on failure.
  int (*RecursiveCreateDirectory)(const char *path, size_t ignored);

  //==============================================
  // reduce_open_files
  // garbage-collects extra open files and closes them. if flags has 1 set, this
  // is done incrementally (call this from a regular timer, if desired). if
  // flags has 2 set, files are aggressively closed (they may need to be
  // re-opened very soon). returns number of files closed by this call.
  int (*reduce_open_files)(int flags);

  //==============================================
  // RefreshToolbar
  // See RefreshToolbar2.
  void (*RefreshToolbar)(int command_id);

  //==============================================
  // RefreshToolbar2
  // Refresh the toolbar button states of a toggle action.
  void (*RefreshToolbar2)(int section_id, int command_id);

  //==============================================
  // relative_fn
  // Makes a filename "in" relative to the current project, if any.
  void (*relative_fn)(const char *in, char *out, int out_sz);

  //==============================================
  // RemoveTrackSend
  // Remove a send/receive/hardware output, return true on success. category is
  // <0 for receives, 0=sends, >0 for hardware outputs. See CreateTrackSend,
  // GetSetTrackSendInfo, GetTrackSendInfo_Value, SetTrackSendInfo_Value,
  // GetTrackNumSends.
  bool (*RemoveTrackSend)(MediaTrack *tr, int category, int sendidx);

  //==============================================
  // RenderFileSection
  // Not available while playing back.
  bool (*RenderFileSection)(const char *source_filename,
                            const char *target_filename, double start_percent,
                            double end_percent, double playrate);

  //==============================================
  // ReorderSelectedTracks
  // Moves all selected tracks to immediately above track specified by index
  // beforeTrackIdx, returns false if no tracks were selected. makePrevFolder=0
  // for normal, 1 = as child of track preceding track specified by
  // beforeTrackIdx, 2 = if track preceding track specified by beforeTrackIdx is
  // last track in folder, extend folder
  bool (*ReorderSelectedTracks)(int beforeTrackIdx, int makePrevFolder);

  //==============================================
  // Resample_EnumModes
  const char *(*Resample_EnumModes)(int mode);

  //==============================================
  // Resampler_Create
  REAPER_Resample_Interface *(*Resampler_Create)();

  //==============================================
  // resolve_fn
  // See resolve_fn2.
  void (*resolve_fn)(const char *in, char *out, int out_sz);

  //==============================================
  // resolve_fn2
  // Resolves a filename "in" by using project settings etc. If no file found,
  // out will be a copy of in.
  void (*resolve_fn2)(const char *in, char *out, int out_sz,
                      const char *checkSubDirOptional);

  //==============================================
  // ReverseNamedCommandLookup
  // Get the named command for the given command ID. The returned string will
  // not start with '_' (e.g. it will return "SWS_ABOUT"), it will be NULL if
  // command_id is a native action.
  const char *(*ReverseNamedCommandLookup)(int command_id);

  //==============================================
  // ScaleFromEnvelopeMode
  // See GetEnvelopeScalingMode.
  double (*ScaleFromEnvelopeMode)(int scaling_mode, double val);

  //==============================================
  // ScaleToEnvelopeMode
  // See GetEnvelopeScalingMode.
  double (*ScaleToEnvelopeMode)(int scaling_mode, double val);

  //==============================================
  // screenset_register
  void (*screenset_register)(char *id, void *callbackFunc, void *param);

  //==============================================
  // screenset_registerNew
  void (*screenset_registerNew)(char *id, screensetNewCallbackFunc callbackFunc,
                                void *param);

  //==============================================
  // screenset_unregister
  void (*screenset_unregister)(char *id);

  //==============================================
  // screenset_unregisterByParam
  void (*screenset_unregisterByParam)(void *param);

  //==============================================
  // screenset_updateLastFocus
  void (*screenset_updateLastFocus)(HWND prevWin);

  //==============================================
  // SectionFromUniqueID
  KbdSectionInfo *(*SectionFromUniqueID)(int uniqueID);

  //==============================================
  // SelectAllMediaItems
  void (*SelectAllMediaItems)(ReaProject *proj, bool selected);

  //==============================================
  // SelectProjectInstance
  void (*SelectProjectInstance)(ReaProject *proj);

  //==============================================
  // SendLocalOscMessage
  // Send an OSC message to REAPER. See CreateLocalOscHandler,
  // DestroyLocalOscHandler.
  void (*SendLocalOscMessage)(void *local_osc_handler, const char *msg,
                              int msglen);

  //==============================================
  // SetActiveTake
  // set this take active in this media item
  void (*SetActiveTake)(MediaItem_Take *take);

  //==============================================
  // SetAutomationMode
  // sets all or selected tracks to mode.
  void (*SetAutomationMode)(int mode, bool onlySel);

  //==============================================
  // SetCurrentBPM
  // set current BPM in project, set wantUndo=true to add undo point
  void (*SetCurrentBPM)(ReaProject *__proj, double bpm, bool wantUndo);

  //==============================================
  // SetCursorContext
  // You must use this to change the focus programmatically. mode=0 to focus
  // track panels, 1 to focus the arrange window, 2 to focus the arrange window
  // and select env (or env==NULL to clear the current track/take envelope
  // selection)
  void (*SetCursorContext)(int mode, TrackEnvelope *envInOptional);

  //==============================================
  // SetEditCurPos
  void (*SetEditCurPos)(double time, bool moveview, bool seekplay);

  //==============================================
  // SetEditCurPos2
  void (*SetEditCurPos2)(ReaProject *proj, double time, bool moveview,
                         bool seekplay);

  //==============================================
  // SetEnvelopePoint
  // Set attributes of an envelope point. Values that are not supplied will be
  // ignored. If setting multiple points at once, set noSort=true, and call
  // Envelope_SortPoints when done. See SetEnvelopePointEx.
  bool (*SetEnvelopePoint)(TrackEnvelope *envelope, int ptidx,
                           double *timeInOptional, double *valueInOptional,
                           int *shapeInOptional, double *tensionInOptional,
                           bool *selectedInOptional, bool *noSortInOptional);

  //==============================================
  // SetEnvelopePointEx
  // Set attributes of an envelope point. Values that are not supplied will be
  // ignored. If setting multiple points at once, set noSort=true, and call
  // Envelope_SortPoints when done. autoitem_idx=-1 for the underlying envelope,
  // 0 for the first automation item on the envelope, etc. For automation items,
  // pass autoitem_idx|0x10000000 to base ptidx on the number of points in one
  // full loop iteration, even if the automation item is trimmed so that not all
  // points are visible. Otherwise, ptidx will be based on the number of visible
  // points in the automation item, including all loop iterations. See
  // CountEnvelopePointsEx, GetEnvelopePointEx, InsertEnvelopePointEx,
  // DeleteEnvelopePointEx.
  bool (*SetEnvelopePointEx)(TrackEnvelope *envelope, int autoitem_idx,
                             int ptidx, double *timeInOptional,
                             double *valueInOptional, int *shapeInOptional,
                             double *tensionInOptional,
                             bool *selectedInOptional, bool *noSortInOptional);

  //==============================================
  // SetEnvelopeStateChunk
  // Sets the RPPXML state of an envelope, returns true if successful. Undo flag
  // is a performance/caching hint.
  bool (*SetEnvelopeStateChunk)(TrackEnvelope *env, const char *str,
                                bool isundoOptional);

  //==============================================
  // SetExtState
  // Set the extended state value for a specific section and key. persist=true
  // means the value should be stored and reloaded the next time REAPER is
  // opened. See GetExtState, DeleteExtState, HasExtState.
  void (*SetExtState)(const char *section, const char *key, const char *value,
                      bool persist);

  //==============================================
  // SetGlobalAutomationOverride
  // mode: see GetGlobalAutomationOverride
  void (*SetGlobalAutomationOverride)(int mode);

  //==============================================
  // SetItemStateChunk
  // Sets the RPPXML state of an item, returns true if successful. Undo flag is
  // a performance/caching hint.
  bool (*SetItemStateChunk)(MediaItem *item, const char *str,
                            bool isundoOptional);

  //==============================================
  // SetMasterTrackVisibility
  // set &1 to show the master track in the TCP, &2 to show in the mixer.
  // Returns the previous visibility state. See GetMasterTrackVisibility.
  int (*SetMasterTrackVisibility)(int flag);

  //==============================================
  // SetMediaItemInfo_Value
  // Set media item numerical-value attributes.
  // B_MUTE : bool * : muted (item solo overrides). setting this value will
  // clear C_MUTE_SOLO. B_MUTE_ACTUAL : bool * : muted (ignores solo). setting
  // this value will not affect C_MUTE_SOLO. C_MUTE_SOLO : char * : solo
  // override (-1=soloed, 0=no override, 1=unsoloed). note that this API does
  // not automatically unsolo other items when soloing (nor clear the unsolos
  // when clearing the last soloed item), it must be done by the caller via
  // action or via this API. B_LOOPSRC : bool * : loop source B_ALLTAKESPLAY :
  // bool * : all takes play B_UISEL : bool * : selected in arrange view
  // C_BEATATTACHMODE : char * : item timebase, -1=track or project default,
  // 1=beats (position, length, rate), 2=beats (position only). for auto-stretch
  // timebase: C_BEATATTACHMODE=1, C_AUTOSTRETCH=1 C_AUTOSTRETCH: : char * :
  // auto-stretch at project tempo changes, 1=enabled, requires
  // C_BEATATTACHMODE=1 C_LOCK : char * : locked, &1=locked D_VOL : double * :
  // item volume,  0=-inf, 0.5=-6dB, 1=+0dB, 2=+6dB, etc D_POSITION : double * :
  // item position in seconds D_LENGTH : double * : item length in seconds
  // D_SNAPOFFSET : double * : item snap offset in seconds
  // D_FADEINLEN : double * : item manual fadein length in seconds
  // D_FADEOUTLEN : double * : item manual fadeout length in seconds
  // D_FADEINDIR : double * : item fadein curvature, -1..1
  // D_FADEOUTDIR : double * : item fadeout curvature, -1..1
  // D_FADEINLEN_AUTO : double * : item auto-fadein length in seconds, -1=no
  // auto-fadein D_FADEOUTLEN_AUTO : double * : item auto-fadeout length in
  // seconds, -1=no auto-fadeout C_FADEINSHAPE : int * : fadein shape, 0..6,
  // 0=linear C_FADEOUTSHAPE : int * : fadeout shape, 0..6, 0=linear I_GROUPID :
  // int * : group ID, 0=no group I_LASTY : int * : Y-position of track in
  // pixels (read-only) I_LASTH : int * : height in track in pixels (read-only)
  // I_CUSTOMCOLOR : int * : custom color, OS dependent color|0x100000 (i.e.
  // ColorToNative(r,g,b)|0x100000). If you do not |0x100000, then it will not
  // be used, but will store the color I_CURTAKE : int * : active take number
  // IP_ITEMNUMBER : int, item number on this track (read-only, returns the item
  // number directly) F_FREEMODE_Y : float * : free item positioning Y-position,
  // 0=top of track, 1=bottom of track (will never be 1) F_FREEMODE_H : float *
  // : free item positioning height, 0=no height, 1=full height of track (will
  // never be 0)
  //
  bool (*SetMediaItemInfo_Value)(MediaItem *item, const char *parmname,
                                 double newvalue);

  //==============================================
  // SetMediaItemLength
  // Redraws the screen only if refreshUI == true.
  // See UpdateArrange().
  bool (*SetMediaItemLength)(MediaItem *item, double length, bool refreshUI);

  //==============================================
  // SetMediaItemPosition
  // Redraws the screen only if refreshUI == true.
  // See UpdateArrange().
  bool (*SetMediaItemPosition)(MediaItem *item, double position,
                               bool refreshUI);

  //==============================================
  // SetMediaItemSelected
  void (*SetMediaItemSelected)(MediaItem *item, bool selected);

  //==============================================
  // SetMediaItemTake_Source
  // Set media source of media item take. The old source will not be destroyed,
  // it is the caller's responsibility to retrieve it and destroy it after. If
  // source already exists in any project, it will be duplicated before being
  // set. C/C++ code should not use this and instead use
  // GetSetMediaItemTakeInfo() with P_SOURCE to manage ownership directly.
  bool (*SetMediaItemTake_Source)(MediaItem_Take *take, PCM_source *source);

  //==============================================
  // SetMediaItemTakeInfo_Value
  // Set media item take numerical-value attributes.
  // D_STARTOFFS : double * : start offset in source media, in seconds
  // D_VOL : double * : take volume, 0=-inf, 0.5=-6dB, 1=+0dB, 2=+6dB, etc,
  // negative if take polarity is flipped D_PAN : double * : take pan, -1..1
  // D_PANLAW : double * : take pan law, -1=default, 0.5=-6dB, 1.0=+0dB, etc
  // D_PLAYRATE : double * : take playback rate, 0.5=half speed, 1=normal,
  // 2=double speed, etc D_PITCH : double * : take pitch adjustment in
  // semitones, -12=one octave down, 0=normal, +12=one octave up, etc B_PPITCH :
  // bool * : preserve pitch when changing playback rate I_CHANMODE : int * :
  // channel mode, 0=normal, 1=reverse stereo, 2=downmix, 3=left, 4=right
  // I_PITCHMODE : int * : pitch shifter mode, -1=projext default, otherwise
  // high 2 bytes=shifter, low 2 bytes=parameter I_CUSTOMCOLOR : int * : custom
  // color, OS dependent color|0x100000 (i.e. ColorToNative(r,g,b)|0x100000). If
  // you do not |0x100000, then it will not be used, but will store the color
  // IP_TAKENUMBER : int : take number (read-only, returns the take number
  // directly)
  //
  bool (*SetMediaItemTakeInfo_Value)(MediaItem_Take *take, const char *parmname,
                                     double newvalue);

  //==============================================
  // SetMediaTrackInfo_Value
  // Set track numerical-value attributes.
  // B_MUTE : bool * : muted
  // B_PHASE : bool * : track phase inverted
  // B_RECMON_IN_EFFECT : bool * : record monitoring in effect (current
  // audio-thread playback state, read-only) IP_TRACKNUMBER : int : track number
  // 1-based, 0=not found, -1=master track (read-only, returns the int directly)
  // I_SOLO : int * : soloed, 0=not soloed, 1=soloed, 2=soloed in place, 5=safe
  // soloed, 6=safe soloed in place I_FXEN : int * : fx enabled, 0=bypassed,
  // !0=fx active I_RECARM : int * : record armed, 0=not record armed, 1=record
  // armed I_RECINPUT : int * : record input, <0=no input. if 4096 set, input is
  // MIDI and low 5 bits represent channel (0=all, 1-16=only chan), next 6 bits
  // represent physical input (63=all, 62=VKB). If 4096 is not set, low 10 bits
  // (0..1023) are input start channel (ReaRoute/Loopback start at 512). If 2048
  // is set, input is multichannel input (using track channel count), or if 1024
  // is set, input is stereo input, otherwise input is mono. I_RECMODE : int * :
  // record mode, 0=input, 1=stereo out, 2=none, 3=stereo out w/latency
  // compensation, 4=midi output, 5=mono out, 6=mono out w/ latency
  // compensation, 7=midi overdub, 8=midi replace I_RECMON : int * : record
  // monitoring, 0=off, 1=normal, 2=not when playing (tape style) I_RECMONITEMS
  // : int * : monitor items while recording, 0=off, 1=on I_AUTOMODE : int * :
  // track automation mode, 0=trim/off, 1=read, 2=touch, 3=write, 4=latch
  // I_NCHAN : int * : number of track channels, 2-64, even numbers only
  // I_SELECTED : int * : track selected, 0=unselected, 1=selected
  // I_WNDH : int * : current TCP window height in pixels including envelopes
  // (read-only) I_TCPH : int * : current TCP window height in pixels not
  // including envelopes (read-only) I_TCPY : int * : current TCP window
  // Y-position in pixels relative to top of arrange view (read-only) I_MCPX :
  // int * : current MCP X-position in pixels relative to mixer container I_MCPY
  // : int * : current MCP Y-position in pixels relative to mixer container
  // I_MCPW : int * : current MCP width in pixels
  // I_MCPH : int * : current MCP height in pixels
  // I_FOLDERDEPTH : int * : folder depth change, 0=normal, 1=track is a folder
  // parent, -1=track is the last in the innermost folder, -2=track is the last
  // in the innermost and next-innermost folders, etc I_FOLDERCOMPACT : int * :
  // folder compacted state (only valid on folders), 0=normal, 1=small, 2=tiny
  // children I_MIDIHWOUT : int * : track midi hardware output index,
  // <0=disabled, low 5 bits are which channels (0=all, 1-16), next 5 bits are
  // output device index (0-31) I_PERFFLAGS : int * : track performance flags,
  // &1=no media buffering, &2=no anticipative FX I_CUSTOMCOLOR : int * : custom
  // color, OS dependent color|0x100000 (i.e. ColorToNative(r,g,b)|0x100000). If
  // you do not |0x100000, then it will not be used, but will store the color
  // I_HEIGHTOVERRIDE : int * : custom height override for TCP window, 0 for
  // none, otherwise size in pixels B_HEIGHTLOCK : bool * : track height lock
  // (must set I_HEIGHTOVERRIDE before locking) D_VOL : double * : trim volume
  // of track, 0=-inf, 0.5=-6dB, 1=+0dB, 2=+6dB, etc D_PAN : double * : trim pan
  // of track, -1..1 D_WIDTH : double * : width of track, -1..1 D_DUALPANL :
  // double * : dualpan position 1, -1..1, only if I_PANMODE==6 D_DUALPANR :
  // double * : dualpan position 2, -1..1, only if I_PANMODE==6 I_PANMODE : int
  // * : pan mode, 0=classic 3.x, 3=new balance, 5=stereo pan, 6=dual pan
  // D_PANLAW : double * : pan law of track, <0=project default, 1=+0dB, etc
  // P_ENV:<envchunkname : TrackEnvelope*, read only. Call with :<VOLENV,
  // :<PANENV, etc appended. B_SHOWINMIXER : bool * : track control panel
  // visible in mixer (do not use on master track) B_SHOWINTCP : bool * : track
  // control panel visible in arrange view (do not use on master track)
  // B_MAINSEND : bool * : track sends audio to parent
  // C_MAINSEND_OFFS : char * : channel offset of track send to parent
  // B_FREEMODE : bool * : track free item positioning enabled (call
  // UpdateTimeline() after changing) C_BEATATTACHMODE : char * : track
  // timebase, -1=project default, 0=time, 1=beats (position, length, rate),
  // 2=beats (position only) F_MCP_FXSEND_SCALE : float * : scale of fx+send
  // area in MCP (0=minimum allowed, 1=maximum allowed) F_MCP_FXPARM_SCALE :
  // float * : scale of fx parameter area in MCP (0=minimum allowed, 1=maximum
  // allowed) F_MCP_SENDRGN_SCALE : float * : scale of send area as proportion
  // of the fx+send total area (0=minimum allowed, 1=maximum allowed)
  // F_TCP_FXPARM_SCALE : float * : scale of TCP parameter area when TCP FX are
  // embedded (0=min allowed, default, 1=max allowed) I_PLAY_OFFSET_FLAG : int *
  // : track playback offset state, &1=bypassed, &2=offset value is measured in
  // samples (otherwise measured in seconds) D_PLAY_OFFSET : double * : track
  // playback offset, units depend on I_PLAY_OFFSET_FLAG
  //
  bool (*SetMediaTrackInfo_Value)(MediaTrack *tr, const char *parmname,
                                  double newvalue);

  //==============================================
  // SetMIDIEditorGrid
  // Set the MIDI editor grid division. 0.25=quarter note, 1.0/3.0=half note
  // tripet, etc.
  void (*SetMIDIEditorGrid)(ReaProject *project, double division);

  //==============================================
  // SetMixerScroll
  // Scroll the mixer so that leftmosttrack is the leftmost visible track.
  // Returns the leftmost track after scrolling, which may be different from the
  // passed-in track if there are not enough tracks to its right.
  MediaTrack *(*SetMixerScroll)(MediaTrack *leftmosttrack);

  //==============================================
  // SetMouseModifier
  // Set the mouse modifier assignment for a specific modifier key assignment,
  // in a specific context. Context is a string like "MM_CTX_ITEM". Find these
  // strings by modifying an assignment in Preferences/Editing/Mouse Modifiers,
  // then looking in reaper-mouse.ini. Modifier flag is a number from 0 to 15:
  // add 1 for shift, 2 for control, 4 for alt, 8 for win. (macOS: add 1 for
  // shift, 2 for command, 4 for opt, 8 for control.) For left-click and
  // double-click contexts, the action can be any built-in command ID number or
  // any custom action ID string. Find built-in command IDs in the REAPER
  // actions window (enable "show action IDs" in the context menu), and find
  // custom action ID strings in reaper-kb.ini. For built-in mouse modifier
  // behaviors, find action IDs (which will be low numbers) by modifying an
  // assignment in Preferences/Editing/Mouse Modifiers, then looking in
  // reaper-mouse.ini. Assigning an action of -1 will reset that mouse modifier
  // behavior to factory default. See GetMouseModifier.
  //
  void (*SetMouseModifier)(const char *context, int modifier_flag,
                           const char *action);

  //==============================================
  // SetOnlyTrackSelected
  // Set exactly one track selected, deselect all others
  void (*SetOnlyTrackSelected)(MediaTrack *track);

  //==============================================
  // SetProjectGrid
  // Set the arrange view grid division. 0.25=quarter note, 1.0/3.0=half note
  // triplet, etc.
  void (*SetProjectGrid)(ReaProject *project, double division);

  //==============================================
  // SetProjectMarker
  bool (*SetProjectMarker)(int markrgnindexnumber, bool isrgn, double pos,
                           double rgnend, const char *name);

  //==============================================
  // SetProjectMarker2
  bool (*SetProjectMarker2)(ReaProject *proj, int markrgnindexnumber,
                            bool isrgn, double pos, double rgnend,
                            const char *name);

  //==============================================
  // SetProjectMarker3
  bool (*SetProjectMarker3)(ReaProject *proj, int markrgnindexnumber,
                            bool isrgn, double pos, double rgnend,
                            const char *name, int color);

  //==============================================
  // SetProjectMarker4
  // color should be 0 to not change, or ColorToNative(r,g,b)|0x1000000, flags&1
  // to clear name
  bool (*SetProjectMarker4)(ReaProject *proj, int markrgnindexnumber,
                            bool isrgn, double pos, double rgnend,
                            const char *name, int color, int flags);

  //==============================================
  // SetProjectMarkerByIndex
  // See SetProjectMarkerByIndex2.
  bool (*SetProjectMarkerByIndex)(ReaProject *proj, int markrgnidx, bool isrgn,
                                  double pos, double rgnend, int IDnumber,
                                  const char *name, int color);

  //==============================================
  // SetProjectMarkerByIndex2
  // Differs from SetProjectMarker4 in that markrgnidx is 0 for the first
  // marker/region, 1 for the next, etc (see EnumProjectMarkers3), rather than
  // representing the displayed marker/region ID number (see SetProjectMarker3).
  // Function will fail if attempting to set a duplicate ID number for a region
  // (duplicate ID numbers for markers are OK). , flags&1 to clear name.
  bool (*SetProjectMarkerByIndex2)(ReaProject *proj, int markrgnidx, bool isrgn,
                                   double pos, double rgnend, int IDnumber,
                                   const char *name, int color, int flags);

  //==============================================
  // SetProjExtState
  // Save a key/value pair for a specific extension, to be restored the next
  // time this specific project is loaded. Typically extname will be the name of
  // a reascript or extension section. If key is NULL or "", all extended data
  // for that extname will be deleted.  If val is NULL or "", the data
  // previously associated with that key will be deleted. Returns the size of
  // the state for this extname. See GetProjExtState, EnumProjExtState.
  int (*SetProjExtState)(ReaProject *proj, const char *extname, const char *key,
                         const char *value);

  //==============================================
  // SetRegionRenderMatrix
  // Add (addorremove > 0) or remove (addorremove < 0) a track from this region
  // when using the region render matrix.
  void (*SetRegionRenderMatrix)(ReaProject *proj, int regionindex,
                                MediaTrack *track, int addorremove);

  //==============================================
  // SetRenderLastError
  // Used by pcmsink objects to set an error to display while creating the
  // pcmsink object.
  void (*SetRenderLastError)(const char *errorstr);

  //==============================================
  // SetTakeMarker
  // Inserts or updates a take marker. If idx<0, a take marker will be added,
  // otherwise an existing take marker will be updated. Returns the index of the
  // new or updated take marker (which may change if srcPos is updated). See
  // GetNumTakeMarkers, GetTakeMarker, DeleteTakeMarker
  int (*SetTakeMarker)(MediaItem_Take *take, int idx, const char *nameIn,
                       double *srcposInOptional, int *colorInOptional);

  //==============================================
  // SetTakeStretchMarker
  // Adds or updates a stretch marker. If idx<0, stretch marker will be added.
  // If idx>=0, stretch marker will be updated. When adding, if srcposInOptional
  // is omitted, source position will be auto-calculated. When updating a
  // stretch marker, if srcposInOptional is omitted, srcpos will not be
  // modified. Position/srcposition values will be constrained to nearby stretch
  // markers. Returns index of stretch marker, or -1 if did not insert (or
  // marker already existed at time).
  int (*SetTakeStretchMarker)(MediaItem_Take *take, int idx, double pos,
                              const double *srcposInOptional);

  //==============================================
  // SetTakeStretchMarkerSlope
  // See GetTakeStretchMarkerSlope
  bool (*SetTakeStretchMarkerSlope)(MediaItem_Take *take, int idx,
                                    double slope);

  //==============================================
  // SetTempoTimeSigMarker
  // Set parameters of a tempo/time signature marker. Provide either timepos
  // (with measurepos=-1, beatpos=-1), or measurepos and beatpos (with
  // timepos=-1). If timesig_num and timesig_denom are zero, the previous time
  // signature will be used. ptidx=-1 will insert a new tempo/time signature
  // marker. See CountTempoTimeSigMarkers, GetTempoTimeSigMarker,
  // AddTempoTimeSigMarker.
  bool (*SetTempoTimeSigMarker)(ReaProject *proj, int ptidx, double timepos,
                                int measurepos, double beatpos, double bpm,
                                int timesig_num, int timesig_denom,
                                bool lineartempo);

  //==============================================
  // SetThemeColor
  // Temporarily updates the theme color to the color specified (or the theme
  // default color if -1 is specified). Returns -1 on failure, otherwise returns
  // the color (or transformed-color). Note that the UI is not updated by this,
  // the caller should call UpdateArrange() etc as necessary. If the low bit of
  // flags is set, any color transformations are bypassed. To read a value see
  // GetThemeColor.
  int (*SetThemeColor)(const char *ini_key, int color, int flagsOptional);

  //==============================================
  // SetToggleCommandState
  // Updates the toggle state of an action, returns true if succeeded. Only
  // ReaScripts can have their toggle states changed programmatically. See
  // RefreshToolbar2.
  bool (*SetToggleCommandState)(int section_id, int command_id, int state);

  //==============================================
  // SetTrackAutomationMode
  void (*SetTrackAutomationMode)(MediaTrack *tr, int mode);

  //==============================================
  // SetTrackColor
  // Set the custom track color, color is OS dependent (i.e.
  // ColorToNative(r,g,b).
  void (*SetTrackColor)(MediaTrack *track, int color);

  //==============================================
  // SetTrackMIDILyrics
  // Set all MIDI lyrics on the track. Lyrics will be stuffed into any MIDI
  // items found in range. Flag is unused at present. str is passed in as beat
  // position, tab, text, tab (example with flag=2: "1.1.2\tLyric for measure 1
  // beat 2\t.1.1\tLyric for measure 2 beat 1	"). See GetTrackMIDILyrics
  bool (*SetTrackMIDILyrics)(MediaTrack *track, int flag, const char *str);

  //==============================================
  // SetTrackMIDINoteName
  // channel < 0 assigns these note names to all channels.
  bool (*SetTrackMIDINoteName)(int track, int pitch, int chan,
                               const char *name);

  //==============================================
  // SetTrackMIDINoteNameEx
  // channel < 0 assigns note name to all channels. pitch 128 assigns name for
  // CC0, pitch 129 for CC1, etc.
  bool (*SetTrackMIDINoteNameEx)(ReaProject *proj, MediaTrack *track, int pitch,
                                 int chan, const char *name);

  //==============================================
  // SetTrackSelected
  void (*SetTrackSelected)(MediaTrack *track, bool selected);

  //==============================================
  // SetTrackSendInfo_Value
  // Set send/receive/hardware output numerical-value attributes, return true on
  // success. category is <0 for receives, 0=sends, >0 for hardware outputs
  // parameter names:
  // B_MUTE : bool *
  // B_PHASE : bool *, true to flip phase
  // B_MONO : bool *
  // D_VOL : double *, 1.0 = +0dB etc
  // D_PAN : double *, -1..+1
  // D_PANLAW : double *,1.0=+0.0db, 0.5=-6dB, -1.0 = projdef etc
  // I_SENDMODE : int *, 0=post-fader, 1=pre-fx, 2=post-fx (deprecated),
  // 3=post-fx I_AUTOMODE : int * : automation mode (-1=use track automode,
  // 0=trim/off, 1=read, 2=touch, 3=write, 4=latch) I_SRCCHAN : int *,
  // index,&1024=mono, -1 for none I_DSTCHAN : int *, index, &1024=mono,
  // otherwise stereo pair, hwout:&512=rearoute I_MIDIFLAGS : int *, low 5
  // bits=source channel 0=all, 1-16, next 5 bits=dest channel, 0=orig,
  // 1-16=chanSee CreateTrackSend, RemoveTrackSend, GetTrackNumSends.
  bool (*SetTrackSendInfo_Value)(MediaTrack *tr, int category, int sendidx,
                                 const char *parmname, double newvalue);

  //==============================================
  // SetTrackSendUIPan
  // send_idx<0 for receives, >=0 for hw ouputs, >=nb_of_hw_ouputs for sends.
  // isend=1 for end of edit, -1 for an instant edit (such as reset), 0 for
  // normal tweak.
  bool (*SetTrackSendUIPan)(MediaTrack *track, int send_idx, double pan,
                            int isend);

  //==============================================
  // SetTrackSendUIVol
  // send_idx<0 for receives, >=0 for hw ouputs, >=nb_of_hw_ouputs for sends.
  // isend=1 for end of edit, -1 for an instant edit (such as reset), 0 for
  // normal tweak.
  bool (*SetTrackSendUIVol)(MediaTrack *track, int send_idx, double vol,
                            int isend);

  //==============================================
  // SetTrackStateChunk
  // Sets the RPPXML state of a track, returns true if successful. Undo flag is
  // a performance/caching hint.
  bool (*SetTrackStateChunk)(MediaTrack *track, const char *str,
                             bool isundoOptional);

  //==============================================
  // ShowActionList
  void (*ShowActionList)(KbdSectionInfo *caller, HWND callerWnd);

  //==============================================
  // ShowConsoleMsg
  // Show a message to the user (also useful for debugging). Send "\n" for
  // newline, "" to clear the console. See ClearConsole
  void (*ShowConsoleMsg)(const char *msg);

  //==============================================
  // ShowMessageBox
  // type 0=OK,1=OKCANCEL,2=ABORTRETRYIGNORE,3=YESNOCANCEL,4=YESNO,5=RETRYCANCEL
  // : ret 1=OK,2=CANCEL,3=ABORT,4=RETRY,5=IGNORE,6=YES,7=NO
  int (*ShowMessageBox)(const char *msg, const char *title, int type);

  //==============================================
  // ShowPopupMenu
  // shows a context menu, valid names include: track_input, track_panel,
  // track_area, track_routing, item, ruler, envelope, envelope_point,
  // envelope_item. ctxOptional can be a track pointer for track_*, item pointer
  // for item* (but is optional). for envelope_point, ctx2Optional has point
  // index, ctx3Optional has item index (0=main envelope, 1=first AI). for
  // envelope_item, ctx2Optional has AI index (1=first AI)
  void (*ShowPopupMenu)(const char *name, int x, int y, HWND hwndParentOptional,
                        void *ctxOptional, int ctx2Optional, int ctx3Optional);

  //==============================================
  // SLIDER2DB
  double (*SLIDER2DB)(double y);

  //==============================================
  // SnapToGrid
  double (*SnapToGrid)(ReaProject *project, double time_pos);

  //==============================================
  // SoloAllTracks
  // solo=2 for SIP
  void (*SoloAllTracks)(int solo);

  //==============================================
  // Splash_GetWnd
  // gets the splash window, in case you want to display a message over it.
  // Returns NULL when the sphah window is not displayed.
  HWND (*Splash_GetWnd)();

  //==============================================
  // SplitMediaItem
  // the original item becomes the left-hand split, the function returns the
  // right-hand split (or NULL if the split failed)
  MediaItem *(*SplitMediaItem)(MediaItem *item, double position);

  //==============================================
  // StopPreview
  // return nonzero on success
  int (*StopPreview)(preview_register_t *preview);

  //==============================================
  // StopTrackPreview
  // return nonzero on success
  int (*StopTrackPreview)(preview_register_t *preview);

  //==============================================
  // StopTrackPreview2
  // return nonzero on success
  int (*StopTrackPreview2)(void *proj, preview_register_t *preview);

  //==============================================
  // stringToGuid
  void (*stringToGuid)(const char *str, GUID *g);

  //==============================================
  // StuffMIDIMessage
  // Stuffs a 3 byte MIDI message into either the Virtual MIDI Keyboard queue,
  // or the MIDI-as-control input queue, or sends to a MIDI hardware output.
  // mode=0 for VKB, 1 for control (actions map etc), 2 for
  // VKB-on-current-channel; 16 for external MIDI device 0, 17 for external MIDI
  // device 1, etc; see GetNumMIDIOutputs, GetMIDIOutputName.
  void (*StuffMIDIMessage)(int mode, int msg1, int msg2, int msg3);

  //==============================================
  // TakeFX_AddByName
  // Adds or queries the position of a named FX in a take. See
  // TrackFX_AddByName() for information on fxname and instantiate.
  int (*TakeFX_AddByName)(MediaItem_Take *take, const char *fxname,
                          int instantiate);

  //==============================================
  // TakeFX_CopyToTake
  // Copies (or moves) FX from src_take to dest_take. Can be used with
  // src_track=dest_track to reorder.
  void (*TakeFX_CopyToTake)(MediaItem_Take *src_take, int src_fx,
                            MediaItem_Take *dest_take, int dest_fx,
                            bool is_move);

  //==============================================
  // TakeFX_CopyToTrack
  // Copies (or moves) FX from src_take to dest_track. dest_fx can have
  // 0x1000000 set to reference input FX.
  void (*TakeFX_CopyToTrack)(MediaItem_Take *src_take, int src_fx,
                             MediaTrack *dest_track, int dest_fx, bool is_move);

  //==============================================
  // TakeFX_Delete
  // Remove a FX from take chain (returns true on success)
  bool (*TakeFX_Delete)(MediaItem_Take *take, int fx);

  //==============================================
  // TakeFX_EndParamEdit
  bool (*TakeFX_EndParamEdit)(MediaItem_Take *take, int fx, int param);

  //==============================================
  // TakeFX_FormatParamValue
  // Note: only works with FX that support Cockos VST extensions.
  bool (*TakeFX_FormatParamValue)(MediaItem_Take *take, int fx, int param,
                                  double val, char *buf, int buf_sz);

  //==============================================
  // TakeFX_FormatParamValueNormalized
  // Note: only works with FX that support Cockos VST extensions.
  bool (*TakeFX_FormatParamValueNormalized)(MediaItem_Take *take, int fx,
                                            int param, double value, char *buf,
                                            int buf_sz);

  //==============================================
  // TakeFX_GetChainVisible
  // returns index of effect visible in chain, or -1 for chain hidden, or -2 for
  // chain visible but no effect selected
  int (*TakeFX_GetChainVisible)(MediaItem_Take *take);

  //==============================================
  // TakeFX_GetCount
  int (*TakeFX_GetCount)(MediaItem_Take *take);

  //==============================================
  // TakeFX_GetEnabled
  // See TakeFX_SetEnabled
  bool (*TakeFX_GetEnabled)(MediaItem_Take *take, int fx);

  //==============================================
  // TakeFX_GetEnvelope
  // Returns the FX parameter envelope. If the envelope does not exist and
  // create=true, the envelope will be created.
  TrackEnvelope *(*TakeFX_GetEnvelope)(MediaItem_Take *take, int fxindex,
                                       int parameterindex, bool create);

  //==============================================
  // TakeFX_GetFloatingWindow
  // returns HWND of floating window for effect index, if any
  HWND (*TakeFX_GetFloatingWindow)(MediaItem_Take *take, int index);

  //==============================================
  // TakeFX_GetFormattedParamValue
  bool (*TakeFX_GetFormattedParamValue)(MediaItem_Take *take, int fx, int param,
                                        char *buf, int buf_sz);

  //==============================================
  // TakeFX_GetFXGUID
  GUID *(*TakeFX_GetFXGUID)(MediaItem_Take *take, int fx);

  //==============================================
  // TakeFX_GetFXName
  bool (*TakeFX_GetFXName)(MediaItem_Take *take, int fx, char *buf, int buf_sz);

  //==============================================
  // TakeFX_GetIOSize
  // sets the number of input/output pins for FX if available, returns plug-in
  // type or -1 on error
  int (*TakeFX_GetIOSize)(MediaItem_Take *take, int fx,
                          int *inputPinsOutOptional,
                          int *outputPinsOutOptional);

  //==============================================
  // TakeFX_GetNamedConfigParm
  // gets plug-in specific named configuration value (returns true on success).
  // see TrackFX_GetNamedConfigParm
  bool (*TakeFX_GetNamedConfigParm)(MediaItem_Take *take, int fx,
                                    const char *parmname, char *bufOut,
                                    int bufOut_sz);

  //==============================================
  // TakeFX_GetNumParams
  int (*TakeFX_GetNumParams)(MediaItem_Take *take, int fx);

  //==============================================
  // TakeFX_GetOffline
  // See TakeFX_SetOffline
  bool (*TakeFX_GetOffline)(MediaItem_Take *take, int fx);

  //==============================================
  // TakeFX_GetOpen
  // Returns true if this FX UI is open in the FX chain window or a floating
  // window. See TakeFX_SetOpen
  bool (*TakeFX_GetOpen)(MediaItem_Take *take, int fx);

  //==============================================
  // TakeFX_GetParam
  double (*TakeFX_GetParam)(MediaItem_Take *take, int fx, int param,
                            double *minvalOut, double *maxvalOut);

  //==============================================
  // TakeFX_GetParameterStepSizes
  bool (*TakeFX_GetParameterStepSizes)(MediaItem_Take *take, int fx, int param,
                                       double *stepOut, double *smallstepOut,
                                       double *largestepOut, bool *istoggleOut);

  //==============================================
  // TakeFX_GetParamEx
  double (*TakeFX_GetParamEx)(MediaItem_Take *take, int fx, int param,
                              double *minvalOut, double *maxvalOut,
                              double *midvalOut);

  //==============================================
  // TakeFX_GetParamName
  bool (*TakeFX_GetParamName)(MediaItem_Take *take, int fx, int param,
                              char *buf, int buf_sz);

  //==============================================
  // TakeFX_GetParamNormalized
  double (*TakeFX_GetParamNormalized)(MediaItem_Take *take, int fx, int param);

  //==============================================
  // TakeFX_GetPinMappings
  // gets the effective channel mapping bitmask for a particular pin.
  // high32OutOptional will be set to the high 32 bits
  int (*TakeFX_GetPinMappings)(MediaItem_Take *tr, int fx, int isoutput,
                               int pin, int *high32OutOptional);

  //==============================================
  // TakeFX_GetPreset
  // Get the name of the preset currently showing in the REAPER dropdown, or the
  // full path to a factory preset file for VST3 plug-ins (.vstpreset). Returns
  // false if the current FX parameters do not exactly match the preset (in
  // other words, if the user loaded the preset but moved the knobs afterward).
  // See TakeFX_SetPreset.
  bool (*TakeFX_GetPreset)(MediaItem_Take *take, int fx, char *presetname,
                           int presetname_sz);

  //==============================================
  // TakeFX_GetPresetIndex
  // Returns current preset index, or -1 if error. numberOfPresetsOut will be
  // set to total number of presets available. See TakeFX_SetPresetByIndex
  int (*TakeFX_GetPresetIndex)(MediaItem_Take *take, int fx,
                               int *numberOfPresetsOut);

  //==============================================
  // TakeFX_GetUserPresetFilename
  void (*TakeFX_GetUserPresetFilename)(MediaItem_Take *take, int fx, char *fn,
                                       int fn_sz);

  //==============================================
  // TakeFX_NavigatePresets
  // presetmove==1 activates the next preset, presetmove==-1 activates the
  // previous preset, etc.
  bool (*TakeFX_NavigatePresets)(MediaItem_Take *take, int fx, int presetmove);

  //==============================================
  // TakeFX_SetEnabled
  // See TakeFX_GetEnabled
  void (*TakeFX_SetEnabled)(MediaItem_Take *take, int fx, bool enabled);

  //==============================================
  // TakeFX_SetNamedConfigParm
  // gets plug-in specific named configuration value (returns true on success)
  bool (*TakeFX_SetNamedConfigParm)(MediaItem_Take *take, int fx,
                                    const char *parmname, const char *value);

  //==============================================
  // TakeFX_SetOffline
  // See TakeFX_GetOffline
  void (*TakeFX_SetOffline)(MediaItem_Take *take, int fx, bool offline);

  //==============================================
  // TakeFX_SetOpen
  // Open this FX UI. See TakeFX_GetOpen
  void (*TakeFX_SetOpen)(MediaItem_Take *take, int fx, bool open);

  //==============================================
  // TakeFX_SetParam
  bool (*TakeFX_SetParam)(MediaItem_Take *take, int fx, int param, double val);

  //==============================================
  // TakeFX_SetParamNormalized
  bool (*TakeFX_SetParamNormalized)(MediaItem_Take *take, int fx, int param,
                                    double value);

  //==============================================
  // TakeFX_SetPinMappings
  // sets the channel mapping bitmask for a particular pin. returns false if
  // unsupported (not all types of plug-ins support this capability)
  bool (*TakeFX_SetPinMappings)(MediaItem_Take *tr, int fx, int isoutput,
                                int pin, int low32bits, int hi32bits);

  //==============================================
  // TakeFX_SetPreset
  // Activate a preset with the name shown in the REAPER dropdown. Full paths to
  // .vstpreset files are also supported for VST3 plug-ins. See
  // TakeFX_GetPreset.
  bool (*TakeFX_SetPreset)(MediaItem_Take *take, int fx,
                           const char *presetname);

  //==============================================
  // TakeFX_SetPresetByIndex
  // Sets the preset idx, or the factory preset (idx==-2), or the default user
  // preset (idx==-1). Returns true on success. See TakeFX_GetPresetIndex.
  bool (*TakeFX_SetPresetByIndex)(MediaItem_Take *take, int fx, int idx);

  //==============================================
  // TakeFX_Show
  // showflag=0 for hidechain, =1 for show chain(index valid), =2 for hide
  // floating window(index valid), =3 for show floating window (index valid)
  void (*TakeFX_Show)(MediaItem_Take *take, int index, int showFlag);

  //==============================================
  // TakeIsMIDI
  // Returns true if the active take contains MIDI.
  bool (*TakeIsMIDI)(MediaItem_Take *take);

  //==============================================
  // ThemeLayout_GetLayout
  // Gets theme layout information. section can be 'global' for global layout
  // override, 'seclist' to enumerate a list of layout sections, otherwise a
  // layout section such as 'mcp', 'tcp', 'trans', etc. idx can be -1 to query
  // the current value, -2 to get the description of the section (if not
  // global), -3 will return the current context DPI-scaling (256=normal,
  // 512=retina, etc), or 0..x. returns false if failed.
  bool (*ThemeLayout_GetLayout)(const char *section, int idx, char *nameOut,
                                int nameOut_sz);

  //==============================================
  // ThemeLayout_GetParameter
  // returns theme layout parameter. return value is cfg-name, or nil/empty if
  // out of range.
  const char *(*ThemeLayout_GetParameter)(int wp, const char **descOutOptional,
                                          int *valueOutOptional,
                                          int *defValueOutOptional,
                                          int *minValueOutOptional,
                                          int *maxValueOutOptional);

  //==============================================
  // ThemeLayout_RefreshAll
  // Refreshes all layouts
  void (*ThemeLayout_RefreshAll)();

  //==============================================
  // ThemeLayout_SetLayout
  // Sets theme layout override for a particular section -- section can be
  // 'global' or 'mcp' etc. If setting global layout, prefix a ! to the layout
  // string to clear any per-layout overrides. Returns false if failed.
  bool (*ThemeLayout_SetLayout)(const char *section, const char *layout);

  //==============================================
  // ThemeLayout_SetParameter
  // sets theme layout parameter to value. persist=true in order to have change
  // loaded on next theme load. note that the caller should update layouts via
  // ??? to make changes visible.
  bool (*ThemeLayout_SetParameter)(int wp, int value, bool persist);

  //==============================================
  // time_precise
  // Gets a precise system timestamp in seconds
  double (*time_precise)();

  //==============================================
  // TimeMap2_beatsToTime
  // convert a beat position (or optionally a beats+measures if measures is
  // non-NULL) to time.
  double (*TimeMap2_beatsToTime)(ReaProject *proj, double tpos,
                                 const int *measuresInOptional);

  //==============================================
  // TimeMap2_GetDividedBpmAtTime
  // get the effective BPM at the time (seconds) position (i.e. 2x in /8
  // signatures)
  double (*TimeMap2_GetDividedBpmAtTime)(ReaProject *proj, double time);

  //==============================================
  // TimeMap2_GetNextChangeTime
  // when does the next time map (tempo or time sig) change occur
  double (*TimeMap2_GetNextChangeTime)(ReaProject *proj, double time);

  //==============================================
  // TimeMap2_QNToTime
  // converts project QN position to time.
  double (*TimeMap2_QNToTime)(ReaProject *proj, double qn);

  //==============================================
  // TimeMap2_timeToBeats
  // convert a time into beats.
  // if measures is non-NULL, measures will be set to the measure count, return
  // value will be beats since measure. if cml is non-NULL, will be set to
  // current measure length in beats (i.e. time signature numerator) if
  // fullbeats is non-NULL, and measures is non-NULL, fullbeats will get the
  // full beat count (same value returned if measures is NULL). if cdenom is
  // non-NULL, will be set to the current time signature denominator.
  double (*TimeMap2_timeToBeats)(ReaProject *proj, double tpos,
                                 int *measuresOutOptional, int *cmlOutOptional,
                                 double *fullbeatsOutOptional,
                                 int *cdenomOutOptional);

  //==============================================
  // TimeMap2_timeToQN
  // converts project time position to QN position.
  double (*TimeMap2_timeToQN)(ReaProject *proj, double tpos);

  //==============================================
  // TimeMap_curFrameRate
  // Gets project framerate, and optionally whether it is drop-frame timecode
  double (*TimeMap_curFrameRate)(ReaProject *proj, bool *dropFrameOutOptional);

  //==============================================
  // TimeMap_GetDividedBpmAtTime
  // get the effective BPM at the time (seconds) position (i.e. 2x in /8
  // signatures)
  double (*TimeMap_GetDividedBpmAtTime)(double time);

  //==============================================
  // TimeMap_GetMeasureInfo
  // Get the QN position and time signature information for the start of a
  // measure. Return the time in seconds of the measure start.
  double (*TimeMap_GetMeasureInfo)(ReaProject *proj, int measure,
                                   double *qn_startOut, double *qn_endOut,
                                   int *timesig_numOut, int *timesig_denomOut,
                                   double *tempoOut);

  //==============================================
  // TimeMap_GetMetronomePattern
  // Fills in a string representing the active metronome pattern. For example,
  // in a 7/8 measure divided 3+4, the pattern might be "1221222". The length of
  // the string is the time signature numerator, and the function returns the
  // time signature denominator.
  int (*TimeMap_GetMetronomePattern)(ReaProject *proj, double time,
                                     char *pattern, int pattern_sz);

  //==============================================
  // TimeMap_GetTimeSigAtTime
  // get the effective time signature and tempo
  void (*TimeMap_GetTimeSigAtTime)(ReaProject *proj, double time,
                                   int *timesig_numOut, int *timesig_denomOut,
                                   double *tempoOut);

  //==============================================
  // TimeMap_QNToMeasures
  // Find which measure the given QN position falls in.
  int (*TimeMap_QNToMeasures)(ReaProject *proj, double qn,
                              double *qnMeasureStartOutOptional,
                              double *qnMeasureEndOutOptional);

  //==============================================
  // TimeMap_QNToTime
  // converts project QN position to time.
  double (*TimeMap_QNToTime)(double qn);

  //==============================================
  // TimeMap_QNToTime_abs
  // Converts project quarter note count (QN) to time. QN is counted from the
  // start of the project, regardless of any partial measures. See
  // TimeMap2_QNToTime
  double (*TimeMap_QNToTime_abs)(ReaProject *proj, double qn);

  //==============================================
  // TimeMap_timeToQN
  // converts project QN position to time.
  double (*TimeMap_timeToQN)(double tpos);

  //==============================================
  // TimeMap_timeToQN_abs
  // Converts project time position to quarter note count (QN). QN is counted
  // from the start of the project, regardless of any partial measures. See
  // TimeMap2_timeToQN
  double (*TimeMap_timeToQN_abs)(ReaProject *proj, double tpos);

  //==============================================
  // ToggleTrackSendUIMute
  // send_idx<0 for receives, >=0 for hw ouputs, >=nb_of_hw_ouputs for sends.
  bool (*ToggleTrackSendUIMute)(MediaTrack *track, int send_idx);

  //==============================================
  // Track_GetPeakHoldDB
  double (*Track_GetPeakHoldDB)(MediaTrack *track, int channel, bool clear);

  //==============================================
  // Track_GetPeakInfo
  double (*Track_GetPeakInfo)(MediaTrack *track, int channel);

  //==============================================
  // TrackCtl_SetToolTip
  // displays tooltip at location, or removes if empty string
  void (*TrackCtl_SetToolTip)(const char *fmt, int xpos, int ypos,
                              bool topmost);

  //==============================================
  // TrackFX_AddByName
  // Adds or queries the position of a named FX from the track FX chain
  // (recFX=false) or record input FX/monitoring FX (recFX=true, monitoring FX
  // are on master track). Specify a negative value for instantiate to always
  // create a new effect, 0 to only query the first instance of an effect, or a
  // positive value to add an instance if one is not found. If instantiate is <=
  // -1000, it is used for the insertion position (-1000 is first item in chain,
  // -1001 is second, etc). fxname can have prefix to specify type:
  // VST3:,VST2:,VST:,AU:,JS:, or DX:, or FXADD: which adds selected items from
  // the currently-open FX browser, FXADD:2 to limit to 2 FX added, or FXADD:2e
  // to only succeed if exactly 2 FX are selected. Returns -1 on failure or the
  // new position in chain on success.
  int (*TrackFX_AddByName)(MediaTrack *track, const char *fxname, bool recFX,
                           int instantiate);

  //==============================================
  // TrackFX_CopyToTake
  // Copies (or moves) FX from src_track to dest_take. src_fx can have 0x1000000
  // set to reference input FX.
  void (*TrackFX_CopyToTake)(MediaTrack *src_track, int src_fx,
                             MediaItem_Take *dest_take, int dest_fx,
                             bool is_move);

  //==============================================
  // TrackFX_CopyToTrack
  // Copies (or moves) FX from src_track to dest_track. Can be used with
  // src_track=dest_track to reorder, FX indices have 0x1000000 set to reference
  // input FX.
  void (*TrackFX_CopyToTrack)(MediaTrack *src_track, int src_fx,
                              MediaTrack *dest_track, int dest_fx,
                              bool is_move);

  //==============================================
  // TrackFX_Delete
  // Remove a FX from track chain (returns true on success)
  bool (*TrackFX_Delete)(MediaTrack *track, int fx);

  //==============================================
  // TrackFX_EndParamEdit
  bool (*TrackFX_EndParamEdit)(MediaTrack *track, int fx, int param);

  //==============================================
  // TrackFX_FormatParamValue
  // Note: only works with FX that support Cockos VST extensions.
  bool (*TrackFX_FormatParamValue)(MediaTrack *track, int fx, int param,
                                   double val, char *buf, int buf_sz);

  //==============================================
  // TrackFX_FormatParamValueNormalized
  // Note: only works with FX that support Cockos VST extensions.
  bool (*TrackFX_FormatParamValueNormalized)(MediaTrack *track, int fx,
                                             int param, double value, char *buf,
                                             int buf_sz);

  //==============================================
  // TrackFX_GetByName
  // Get the index of the first track FX insert that matches fxname. If the FX
  // is not in the chain and instantiate is true, it will be inserted. See
  // TrackFX_GetInstrument, TrackFX_GetEQ. Deprecated in favor of
  // TrackFX_AddByName.
  int (*TrackFX_GetByName)(MediaTrack *track, const char *fxname,
                           bool instantiate);

  //==============================================
  // TrackFX_GetChainVisible
  // returns index of effect visible in chain, or -1 for chain hidden, or -2 for
  // chain visible but no effect selected
  int (*TrackFX_GetChainVisible)(MediaTrack *track);

  //==============================================
  // TrackFX_GetCount
  int (*TrackFX_GetCount)(MediaTrack *track);

  //==============================================
  // TrackFX_GetEnabled
  // See TrackFX_SetEnabled
  bool (*TrackFX_GetEnabled)(MediaTrack *track, int fx);

  //==============================================
  // TrackFX_GetEQ
  // Get the index of ReaEQ in the track FX chain. If ReaEQ is not in the chain
  // and instantiate is true, it will be inserted. See TrackFX_GetInstrument,
  // TrackFX_GetByName.
  int (*TrackFX_GetEQ)(MediaTrack *track, bool instantiate);

  //==============================================
  // TrackFX_GetEQBandEnabled
  // Returns true if the EQ band is enabled.
  // Returns false if the band is disabled, or if track/fxidx is not ReaEQ.
  // Bandtype: 0=lhipass, 1=loshelf, 2=band, 3=notch, 4=hishelf, 5=lopass.
  // Bandidx: 0=first band matching bandtype, 1=2nd band matching bandtype, etc.
  // See TrackFX_GetEQ, TrackFX_GetEQParam, TrackFX_SetEQParam,
  // TrackFX_SetEQBandEnabled.
  bool (*TrackFX_GetEQBandEnabled)(MediaTrack *track, int fxidx, int bandtype,
                                   int bandidx);

  //==============================================
  // TrackFX_GetEQParam
  // Returns false if track/fxidx is not ReaEQ.
  // Bandtype: -1=master gain, 0=lhipass, 1=loshelf, 2=band, 3=notch, 4=hishelf,
  // 5=lopass. Bandidx (ignored for master gain): 0=first band matching
  // bandtype, 1=2nd band matching bandtype, etc. Paramtype (ignored for master
  // gain): 0=freq, 1=gain, 2=Q. See TrackFX_GetEQ, TrackFX_SetEQParam,
  // TrackFX_GetEQBandEnabled, TrackFX_SetEQBandEnabled.
  bool (*TrackFX_GetEQParam)(MediaTrack *track, int fxidx, int paramidx,
                             int *bandtypeOut, int *bandidxOut,
                             int *paramtypeOut, double *normvalOut);

  //==============================================
  // TrackFX_GetFloatingWindow
  // returns HWND of floating window for effect index, if any
  HWND (*TrackFX_GetFloatingWindow)(MediaTrack *track, int index);

  //==============================================
  // TrackFX_GetFormattedParamValue
  bool (*TrackFX_GetFormattedParamValue)(MediaTrack *track, int fx, int param,
                                         char *buf, int buf_sz);

  //==============================================
  // TrackFX_GetFXGUID
  GUID *(*TrackFX_GetFXGUID)(MediaTrack *track, int fx);

  //==============================================
  // TrackFX_GetFXName
  bool (*TrackFX_GetFXName)(MediaTrack *track, int fx, char *buf, int buf_sz);

  //==============================================
  // TrackFX_GetInstrument
  // Get the index of the first track FX insert that is a virtual instrument, or
  // -1 if none. See TrackFX_GetEQ, TrackFX_GetByName.
  int (*TrackFX_GetInstrument)(MediaTrack *track);

  //==============================================
  // TrackFX_GetIOSize
  // sets the number of input/output pins for FX if available, returns plug-in
  // type or -1 on error
  int (*TrackFX_GetIOSize)(MediaTrack *track, int fx, int *inputPinsOutOptional,
                           int *outputPinsOutOptional);

  //==============================================
  // TrackFX_GetNamedConfigParm
  // gets plug-in specific named configuration value (returns true on success).
  // Special values: 'pdc' returns PDC latency. 'in_pin_0' returns name of first
  // input pin (if available), 'out_pin_0' returns name of first output pin (if
  // available), etc.
  bool (*TrackFX_GetNamedConfigParm)(MediaTrack *track, int fx,
                                     const char *parmname, char *bufOut,
                                     int bufOut_sz);

  //==============================================
  // TrackFX_GetNumParams
  int (*TrackFX_GetNumParams)(MediaTrack *track, int fx);

  //==============================================
  // TrackFX_GetOffline
  // See TrackFX_SetOffline
  bool (*TrackFX_GetOffline)(MediaTrack *track, int fx);

  //==============================================
  // TrackFX_GetOpen
  // Returns true if this FX UI is open in the FX chain window or a floating
  // window. See TrackFX_SetOpen
  bool (*TrackFX_GetOpen)(MediaTrack *track, int fx);

  //==============================================
  // TrackFX_GetParam
  double (*TrackFX_GetParam)(MediaTrack *track, int fx, int param,
                             double *minvalOut, double *maxvalOut);

  //==============================================
  // TrackFX_GetParameterStepSizes
  bool (*TrackFX_GetParameterStepSizes)(MediaTrack *track, int fx, int param,
                                        double *stepOut, double *smallstepOut,
                                        double *largestepOut,
                                        bool *istoggleOut);

  //==============================================
  // TrackFX_GetParamEx
  double (*TrackFX_GetParamEx)(MediaTrack *track, int fx, int param,
                               double *minvalOut, double *maxvalOut,
                               double *midvalOut);

  //==============================================
  // TrackFX_GetParamName
  bool (*TrackFX_GetParamName)(MediaTrack *track, int fx, int param, char *buf,
                               int buf_sz);

  //==============================================
  // TrackFX_GetParamNormalized
  double (*TrackFX_GetParamNormalized)(MediaTrack *track, int fx, int param);

  //==============================================
  // TrackFX_GetPinMappings
  // gets the effective channel mapping bitmask for a particular pin.
  // high32OutOptional will be set to the high 32 bits
  int (*TrackFX_GetPinMappings)(MediaTrack *tr, int fx, int isoutput, int pin,
                                int *high32OutOptional);

  //==============================================
  // TrackFX_GetPreset
  // Get the name of the preset currently showing in the REAPER dropdown, or the
  // full path to a factory preset file for VST3 plug-ins (.vstpreset). Returns
  // false if the current FX parameters do not exactly match the preset (in
  // other words, if the user loaded the preset but moved the knobs afterward).
  // See TrackFX_SetPreset.
  bool (*TrackFX_GetPreset)(MediaTrack *track, int fx, char *presetname,
                            int presetname_sz);

  //==============================================
  // TrackFX_GetPresetIndex
  // Returns current preset index, or -1 if error. numberOfPresetsOut will be
  // set to total number of presets available. See TrackFX_SetPresetByIndex
  int (*TrackFX_GetPresetIndex)(MediaTrack *track, int fx,
                                int *numberOfPresetsOut);

  //==============================================
  // TrackFX_GetRecChainVisible
  // returns index of effect visible in record input chain, or -1 for chain
  // hidden, or -2 for chain visible but no effect selected
  int (*TrackFX_GetRecChainVisible)(MediaTrack *track);

  //==============================================
  // TrackFX_GetRecCount
  // returns count of record input FX. To access record input FX, use a FX
  // indices [0x1000000..0x1000000+n). On the master track, this accesses
  // monitoring FX rather than record input FX.
  int (*TrackFX_GetRecCount)(MediaTrack *track);

  //==============================================
  // TrackFX_GetUserPresetFilename
  void (*TrackFX_GetUserPresetFilename)(MediaTrack *track, int fx, char *fn,
                                        int fn_sz);

  //==============================================
  // TrackFX_NavigatePresets
  // presetmove==1 activates the next preset, presetmove==-1 activates the
  // previous preset, etc.
  bool (*TrackFX_NavigatePresets)(MediaTrack *track, int fx, int presetmove);

  //==============================================
  // TrackFX_SetEnabled
  // See TrackFX_GetEnabled
  void (*TrackFX_SetEnabled)(MediaTrack *track, int fx, bool enabled);

  //==============================================
  // TrackFX_SetEQBandEnabled
  // Enable or disable a ReaEQ band.
  // Returns false if track/fxidx is not ReaEQ.
  // Bandtype: 0=lhipass, 1=loshelf, 2=band, 3=notch, 4=hishelf, 5=lopass.
  // Bandidx: 0=first band matching bandtype, 1=2nd band matching bandtype, etc.
  // See TrackFX_GetEQ, TrackFX_GetEQParam, TrackFX_SetEQParam,
  // TrackFX_GetEQBandEnabled.
  bool (*TrackFX_SetEQBandEnabled)(MediaTrack *track, int fxidx, int bandtype,
                                   int bandidx, bool enable);

  //==============================================
  // TrackFX_SetEQParam
  // Returns false if track/fxidx is not ReaEQ. Targets a band matching
  // bandtype. Bandtype: -1=master gain, 0=lhipass, 1=loshelf, 2=band, 3=notch,
  // 4=hishelf, 5=lopass. Bandidx (ignored for master gain): 0=target first band
  // matching bandtype, 1=target 2nd band matching bandtype, etc. Paramtype
  // (ignored for master gain): 0=freq, 1=gain, 2=Q. See TrackFX_GetEQ,
  // TrackFX_GetEQParam, TrackFX_GetEQBandEnabled, TrackFX_SetEQBandEnabled.
  bool (*TrackFX_SetEQParam)(MediaTrack *track, int fxidx, int bandtype,
                             int bandidx, int paramtype, double val,
                             bool isnorm);

  //==============================================
  // TrackFX_SetNamedConfigParm
  // sets plug-in specific named configuration value (returns true on success)
  bool (*TrackFX_SetNamedConfigParm)(MediaTrack *track, int fx,
                                     const char *parmname, const char *value);

  //==============================================
  // TrackFX_SetOffline
  // See TrackFX_GetOffline
  void (*TrackFX_SetOffline)(MediaTrack *track, int fx, bool offline);

  //==============================================
  // TrackFX_SetOpen
  // Open this FX UI. See TrackFX_GetOpen
  void (*TrackFX_SetOpen)(MediaTrack *track, int fx, bool open);

  //==============================================
  // TrackFX_SetParam
  bool (*TrackFX_SetParam)(MediaTrack *track, int fx, int param, double val);

  //==============================================
  // TrackFX_SetParamNormalized
  bool (*TrackFX_SetParamNormalized)(MediaTrack *track, int fx, int param,
                                     double value);

  //==============================================
  // TrackFX_SetPinMappings
  // sets the channel mapping bitmask for a particular pin. returns false if
  // unsupported (not all types of plug-ins support this capability)
  bool (*TrackFX_SetPinMappings)(MediaTrack *tr, int fx, int isoutput, int pin,
                                 int low32bits, int hi32bits);

  //==============================================
  // TrackFX_SetPreset
  // Activate a preset with the name shown in the REAPER dropdown. Full paths to
  // .vstpreset files are also supported for VST3 plug-ins. See
  // TrackFX_GetPreset.
  bool (*TrackFX_SetPreset)(MediaTrack *track, int fx, const char *presetname);

  //==============================================
  // TrackFX_SetPresetByIndex
  // Sets the preset idx, or the factory preset (idx==-2), or the default user
  // preset (idx==-1). Returns true on success. See TrackFX_GetPresetIndex.
  bool (*TrackFX_SetPresetByIndex)(MediaTrack *track, int fx, int idx);

  //==============================================
  // TrackFX_Show
  // showflag=0 for hidechain, =1 for show chain(index valid), =2 for hide
  // floating window(index valid), =3 for show floating window (index valid)
  void (*TrackFX_Show)(MediaTrack *track, int index, int showFlag);

  //==============================================
  // TrackList_AdjustWindows
  void (*TrackList_AdjustWindows)(bool isMinor);

  //==============================================
  // TrackList_UpdateAllExternalSurfaces
  void (*TrackList_UpdateAllExternalSurfaces)();

  //==============================================
  // Undo_BeginBlock
  // call to start a new block
  void (*Undo_BeginBlock)();

  //==============================================
  // Undo_BeginBlock2
  // call to start a new block
  void (*Undo_BeginBlock2)(ReaProject *proj);

  //==============================================
  // Undo_CanRedo2
  // returns string of next action,if able,NULL if not
  const char *(*Undo_CanRedo2)(ReaProject *proj);

  //==============================================
  // Undo_CanUndo2
  // returns string of last action,if able,NULL if not
  const char *(*Undo_CanUndo2)(ReaProject *proj);

  //==============================================
  // Undo_DoRedo2
  // nonzero if success
  int (*Undo_DoRedo2)(ReaProject *proj);

  //==============================================
  // Undo_DoUndo2
  // nonzero if success
  int (*Undo_DoUndo2)(ReaProject *proj);

  //==============================================
  // Undo_EndBlock
  // call to end the block,with extra flags if any,and a description
  void (*Undo_EndBlock)(const char *descchange, int extraflags);

  //==============================================
  // Undo_EndBlock2
  // call to end the block,with extra flags if any,and a description
  void (*Undo_EndBlock2)(ReaProject *proj, const char *descchange,
                         int extraflags);

  //==============================================
  // Undo_OnStateChange
  // limited state change to items
  void (*Undo_OnStateChange)(const char *descchange);

  //==============================================
  // Undo_OnStateChange2
  // limited state change to items
  void (*Undo_OnStateChange2)(ReaProject *proj, const char *descchange);

  //==============================================
  // Undo_OnStateChange_Item
  void (*Undo_OnStateChange_Item)(ReaProject *proj, const char *name,
                                  MediaItem *item);

  //==============================================
  // Undo_OnStateChangeEx
  // trackparm=-1 by default,or if updating one fx chain,you can specify track
  // index
  void (*Undo_OnStateChangeEx)(const char *descchange, int whichStates,
                               int trackparm);

  //==============================================
  // Undo_OnStateChangeEx2
  // trackparm=-1 by default,or if updating one fx chain,you can specify track
  // index
  void (*Undo_OnStateChangeEx2)(ReaProject *proj, const char *descchange,
                                int whichStates, int trackparm);

  //==============================================
  // update_disk_counters
  // Updates disk I/O statistics with bytes transferred since last call. notify
  // REAPER of a write error by calling with readamt=0, writeamt=-101010110 for
  // unknown or -101010111 for disk full
  void (*update_disk_counters)(int readamt, int writeamt);

  //==============================================
  // UpdateArrange
  // Redraw the arrange view
  void (*UpdateArrange)();

  //==============================================
  // UpdateItemInProject
  void (*UpdateItemInProject)(MediaItem *item);

  //==============================================
  // UpdateTimeline
  // Redraw the arrange view and ruler
  void (*UpdateTimeline)();

  //==============================================
  // ValidatePtr
  // see ValidatePtr2
  bool (*ValidatePtr)(void *pointer, const char *ctypename);

  //==============================================
  // ValidatePtr2
  // Return true if the pointer is a valid object of the right type in proj
  // (proj is ignored if pointer is itself a project). Supported types are:
  // ReaProject*, MediaTrack*, MediaItem*, MediaItem_Take*, TrackEnvelope* and
  // PCM_source*.
  bool (*ValidatePtr2)(ReaProject *proj, void *pointer, const char *ctypename);

  //==============================================
  // ViewPrefs
  // Opens the prefs to a page, use pageByName if page is 0.
  void (*ViewPrefs)(int page, const char *pageByName);

  //==============================================
  // WDL_VirtualWnd_ScaledBlitBG
  bool (*WDL_VirtualWnd_ScaledBlitBG)(LICE_IBitmap *dest,
                                      WDL_VirtualWnd_BGCfg *src, int destx,
                                      int desty, int destw, int desth,
                                      int clipx, int clipy, int clipw,
                                      int cliph, float alpha, int mode);
};

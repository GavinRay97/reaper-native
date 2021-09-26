
  // reaper_plugin_functions_wrapper.cpp
  #define REAPERAPI_IMPLEMENT
  #include "reaper_plugin_functions_wrapper.hpp"

  REAPER_PLUGIN_DLL_EXPORT int REAPERAPI_LoadAPIWrapper(void *(*getAPI)(const char*)) {
    return REAPERAPI_LoadAPI(getAPI);
  }

  
REAPER_PLUGIN_DLL_EXPORT bool _AddCustomizableMenu(const char* menuidstr, const char* menuname, const char* kbdsecname, bool addtomainmenu) {
  return AddCustomizableMenu(menuidstr, menuname, kbdsecname, addtomainmenu);
}

REAPER_PLUGIN_DLL_EXPORT bool _AddExtensionsMainMenu() {
  return AddExtensionsMainMenu();
}

REAPER_PLUGIN_DLL_EXPORT MediaItem* _AddMediaItemToTrack(MediaTrack* tr) {
  return AddMediaItemToTrack(tr);
}

REAPER_PLUGIN_DLL_EXPORT int _AddProjectMarker(ReaProject* proj, bool isrgn, double pos, double rgnend, const char* name, int wantidx) {
  return AddProjectMarker(proj, isrgn, pos, rgnend, name, wantidx);
}

REAPER_PLUGIN_DLL_EXPORT int _AddProjectMarker2(ReaProject* proj, bool isrgn, double pos, double rgnend, const char* name, int wantidx, int color) {
  return AddProjectMarker2(proj, isrgn, pos, rgnend, name, wantidx, color);
}

REAPER_PLUGIN_DLL_EXPORT int _AddRemoveReaScript(bool add, int sectionID, const char* scriptfn, bool commit) {
  return AddRemoveReaScript(add, sectionID, scriptfn, commit);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem_Take* _AddTakeToMediaItem(MediaItem* item) {
  return AddTakeToMediaItem(item);
}

REAPER_PLUGIN_DLL_EXPORT bool _AddTempoTimeSigMarker(ReaProject* proj, double timepos, double bpm, int timesig_num, int timesig_denom, bool lineartempochange) {
  return AddTempoTimeSigMarker(proj, timepos, bpm, timesig_num, timesig_denom, lineartempochange);
}

REAPER_PLUGIN_DLL_EXPORT void _adjustZoom(double amt, int forceset, bool doupd, int centermode) {
  return adjustZoom(amt, forceset, doupd, centermode);
}

REAPER_PLUGIN_DLL_EXPORT bool _AnyTrackSolo(ReaProject* proj) {
  return AnyTrackSolo(proj);
}

REAPER_PLUGIN_DLL_EXPORT bool _APIExists(const char* function_name) {
  return APIExists(function_name);
}

REAPER_PLUGIN_DLL_EXPORT void _APITest() {
  return APITest();
}

REAPER_PLUGIN_DLL_EXPORT bool _ApplyNudge(ReaProject* project, int nudgeflag, int nudgewhat, int nudgeunits, double value, bool reverse, int copies) {
  return ApplyNudge(project, nudgeflag, nudgewhat, nudgeunits, value, reverse, copies);
}

REAPER_PLUGIN_DLL_EXPORT void _ArmCommand(int cmd, const char* sectionname) {
  return ArmCommand(cmd, sectionname);
}

REAPER_PLUGIN_DLL_EXPORT void _Audio_Init() {
  return Audio_Init();
}

REAPER_PLUGIN_DLL_EXPORT int _Audio_IsPreBuffer() {
  return Audio_IsPreBuffer();
}

REAPER_PLUGIN_DLL_EXPORT int _Audio_IsRunning() {
  return Audio_IsRunning();
}

REAPER_PLUGIN_DLL_EXPORT void _Audio_Quit() {
  return Audio_Quit();
}

REAPER_PLUGIN_DLL_EXPORT int _Audio_RegHardwareHook(bool isAdd, audio_hook_register_t* reg) {
  return Audio_RegHardwareHook(isAdd, reg);
}

REAPER_PLUGIN_DLL_EXPORT bool _AudioAccessorStateChanged(AudioAccessor* accessor) {
  return AudioAccessorStateChanged(accessor);
}

REAPER_PLUGIN_DLL_EXPORT void _AudioAccessorUpdate(AudioAccessor* accessor) {
  return AudioAccessorUpdate(accessor);
}

REAPER_PLUGIN_DLL_EXPORT bool _AudioAccessorValidateState(AudioAccessor* accessor) {
  return AudioAccessorValidateState(accessor);
}

REAPER_PLUGIN_DLL_EXPORT void _BypassFxAllTracks(int bypass) {
  return BypassFxAllTracks(bypass);
}

REAPER_PLUGIN_DLL_EXPORT int _CalculatePeaks(PCM_source_transfer_t* srcBlock, PCM_source_peaktransfer_t* pksBlock) {
  return CalculatePeaks(srcBlock, pksBlock);
}

REAPER_PLUGIN_DLL_EXPORT int _CalculatePeaksFloatSrcPtr(PCM_source_transfer_t* srcBlock, PCM_source_peaktransfer_t* pksBlock) {
  return CalculatePeaksFloatSrcPtr(srcBlock, pksBlock);
}

REAPER_PLUGIN_DLL_EXPORT void _ClearAllRecArmed() {
  return ClearAllRecArmed();
}

REAPER_PLUGIN_DLL_EXPORT void _ClearConsole() {
  return ClearConsole();
}

REAPER_PLUGIN_DLL_EXPORT void _ClearPeakCache() {
  return ClearPeakCache();
}

REAPER_PLUGIN_DLL_EXPORT void _ColorFromNative(int col, int* rOut, int* gOut, int* bOut) {
  return ColorFromNative(col, rOut, gOut, bOut);
}

REAPER_PLUGIN_DLL_EXPORT int _ColorToNative(int r, int g, int b) {
  return ColorToNative(r, g, b);
}

REAPER_PLUGIN_DLL_EXPORT int _CountActionShortcuts(KbdSectionInfo* section, int cmdID) {
  return CountActionShortcuts(section, cmdID);
}

REAPER_PLUGIN_DLL_EXPORT int _CountAutomationItems(TrackEnvelope* env) {
  return CountAutomationItems(env);
}

REAPER_PLUGIN_DLL_EXPORT int _CountEnvelopePoints(TrackEnvelope* envelope) {
  return CountEnvelopePoints(envelope);
}

REAPER_PLUGIN_DLL_EXPORT int _CountEnvelopePointsEx(TrackEnvelope* envelope, int autoitem_idx) {
  return CountEnvelopePointsEx(envelope, autoitem_idx);
}

REAPER_PLUGIN_DLL_EXPORT int _CountMediaItems(ReaProject* proj) {
  return CountMediaItems(proj);
}

REAPER_PLUGIN_DLL_EXPORT int _CountProjectMarkers(ReaProject* proj, int* num_markersOut, int* num_regionsOut) {
  return CountProjectMarkers(proj, num_markersOut, num_regionsOut);
}

REAPER_PLUGIN_DLL_EXPORT int _CountSelectedMediaItems(ReaProject* proj) {
  return CountSelectedMediaItems(proj);
}

REAPER_PLUGIN_DLL_EXPORT int _CountSelectedTracks(ReaProject* proj) {
  return CountSelectedTracks(proj);
}

REAPER_PLUGIN_DLL_EXPORT int _CountSelectedTracks2(ReaProject* proj, bool wantmaster) {
  return CountSelectedTracks2(proj, wantmaster);
}

REAPER_PLUGIN_DLL_EXPORT int _CountTakeEnvelopes(MediaItem_Take* take) {
  return CountTakeEnvelopes(take);
}

REAPER_PLUGIN_DLL_EXPORT int _CountTakes(MediaItem* item) {
  return CountTakes(item);
}

REAPER_PLUGIN_DLL_EXPORT int _CountTCPFXParms(ReaProject* project, MediaTrack* track) {
  return CountTCPFXParms(project, track);
}

REAPER_PLUGIN_DLL_EXPORT int _CountTempoTimeSigMarkers(ReaProject* proj) {
  return CountTempoTimeSigMarkers(proj);
}

REAPER_PLUGIN_DLL_EXPORT int _CountTrackEnvelopes(MediaTrack* track) {
  return CountTrackEnvelopes(track);
}

REAPER_PLUGIN_DLL_EXPORT int _CountTrackMediaItems(MediaTrack* track) {
  return CountTrackMediaItems(track);
}

REAPER_PLUGIN_DLL_EXPORT int _CountTracks(ReaProject* projOptional) {
  return CountTracks(projOptional);
}

REAPER_PLUGIN_DLL_EXPORT void* _CreateLocalOscHandler(void* obj, void* callback) {
  return CreateLocalOscHandler(obj, callback);
}

REAPER_PLUGIN_DLL_EXPORT midi_Input* _CreateMIDIInput(int dev) {
  return CreateMIDIInput(dev);
}

REAPER_PLUGIN_DLL_EXPORT midi_Output* _CreateMIDIOutput(int dev, bool streamMode, int* msoffset100) {
  return CreateMIDIOutput(dev, streamMode, msoffset100);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem* _CreateNewMIDIItemInProj(MediaTrack* track, double starttime, double endtime, const bool* qnInOptional) {
  return CreateNewMIDIItemInProj(track, starttime, endtime, qnInOptional);
}

REAPER_PLUGIN_DLL_EXPORT AudioAccessor* _CreateTakeAudioAccessor(MediaItem_Take* take) {
  return CreateTakeAudioAccessor(take);
}

REAPER_PLUGIN_DLL_EXPORT AudioAccessor* _CreateTrackAudioAccessor(MediaTrack* track) {
  return CreateTrackAudioAccessor(track);
}

REAPER_PLUGIN_DLL_EXPORT int _CreateTrackSend(MediaTrack* tr, MediaTrack* desttrInOptional) {
  return CreateTrackSend(tr, desttrInOptional);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_FlushUndo(bool force) {
  return CSurf_FlushUndo(force);
}

REAPER_PLUGIN_DLL_EXPORT bool _CSurf_GetTouchState(MediaTrack* trackid, int isPan) {
  return CSurf_GetTouchState(trackid, isPan);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_GoEnd() {
  return CSurf_GoEnd();
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_GoStart() {
  return CSurf_GoStart();
}

REAPER_PLUGIN_DLL_EXPORT int _CSurf_NumTracks(bool mcpView) {
  return CSurf_NumTracks(mcpView);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnArrow(int whichdir, bool wantzoom) {
  return CSurf_OnArrow(whichdir, wantzoom);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnFwd(int seekplay) {
  return CSurf_OnFwd(seekplay);
}

REAPER_PLUGIN_DLL_EXPORT bool _CSurf_OnFXChange(MediaTrack* trackid, int en) {
  return CSurf_OnFXChange(trackid, en);
}

REAPER_PLUGIN_DLL_EXPORT int _CSurf_OnInputMonitorChange(MediaTrack* trackid, int monitor) {
  return CSurf_OnInputMonitorChange(trackid, monitor);
}

REAPER_PLUGIN_DLL_EXPORT int _CSurf_OnInputMonitorChangeEx(MediaTrack* trackid, int monitor, bool allowgang) {
  return CSurf_OnInputMonitorChangeEx(trackid, monitor, allowgang);
}

REAPER_PLUGIN_DLL_EXPORT bool _CSurf_OnMuteChange(MediaTrack* trackid, int mute) {
  return CSurf_OnMuteChange(trackid, mute);
}

REAPER_PLUGIN_DLL_EXPORT bool _CSurf_OnMuteChangeEx(MediaTrack* trackid, int mute, bool allowgang) {
  return CSurf_OnMuteChangeEx(trackid, mute, allowgang);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnOscControlMessage(const char* msg, const float* arg) {
  return CSurf_OnOscControlMessage(msg, arg);
}

REAPER_PLUGIN_DLL_EXPORT double _CSurf_OnPanChange(MediaTrack* trackid, double pan, bool relative) {
  return CSurf_OnPanChange(trackid, pan, relative);
}

REAPER_PLUGIN_DLL_EXPORT double _CSurf_OnPanChangeEx(MediaTrack* trackid, double pan, bool relative, bool allowGang) {
  return CSurf_OnPanChangeEx(trackid, pan, relative, allowGang);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnPause() {
  return CSurf_OnPause();
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnPlay() {
  return CSurf_OnPlay();
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnPlayRateChange(double playrate) {
  return CSurf_OnPlayRateChange(playrate);
}

REAPER_PLUGIN_DLL_EXPORT bool _CSurf_OnRecArmChange(MediaTrack* trackid, int recarm) {
  return CSurf_OnRecArmChange(trackid, recarm);
}

REAPER_PLUGIN_DLL_EXPORT bool _CSurf_OnRecArmChangeEx(MediaTrack* trackid, int recarm, bool allowgang) {
  return CSurf_OnRecArmChangeEx(trackid, recarm, allowgang);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnRecord() {
  return CSurf_OnRecord();
}

REAPER_PLUGIN_DLL_EXPORT double _CSurf_OnRecvPanChange(MediaTrack* trackid, int recv_index, double pan, bool relative) {
  return CSurf_OnRecvPanChange(trackid, recv_index, pan, relative);
}

REAPER_PLUGIN_DLL_EXPORT double _CSurf_OnRecvVolumeChange(MediaTrack* trackid, int recv_index, double volume, bool relative) {
  return CSurf_OnRecvVolumeChange(trackid, recv_index, volume, relative);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnRew(int seekplay) {
  return CSurf_OnRew(seekplay);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnRewFwd(int seekplay, int dir) {
  return CSurf_OnRewFwd(seekplay, dir);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnScroll(int xdir, int ydir) {
  return CSurf_OnScroll(xdir, ydir);
}

REAPER_PLUGIN_DLL_EXPORT bool _CSurf_OnSelectedChange(MediaTrack* trackid, int selected) {
  return CSurf_OnSelectedChange(trackid, selected);
}

REAPER_PLUGIN_DLL_EXPORT double _CSurf_OnSendPanChange(MediaTrack* trackid, int send_index, double pan, bool relative) {
  return CSurf_OnSendPanChange(trackid, send_index, pan, relative);
}

REAPER_PLUGIN_DLL_EXPORT double _CSurf_OnSendVolumeChange(MediaTrack* trackid, int send_index, double volume, bool relative) {
  return CSurf_OnSendVolumeChange(trackid, send_index, volume, relative);
}

REAPER_PLUGIN_DLL_EXPORT bool _CSurf_OnSoloChange(MediaTrack* trackid, int solo) {
  return CSurf_OnSoloChange(trackid, solo);
}

REAPER_PLUGIN_DLL_EXPORT bool _CSurf_OnSoloChangeEx(MediaTrack* trackid, int solo, bool allowgang) {
  return CSurf_OnSoloChangeEx(trackid, solo, allowgang);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnStop() {
  return CSurf_OnStop();
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnTempoChange(double bpm) {
  return CSurf_OnTempoChange(bpm);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnTrackSelection(MediaTrack* trackid) {
  return CSurf_OnTrackSelection(trackid);
}

REAPER_PLUGIN_DLL_EXPORT double _CSurf_OnVolumeChange(MediaTrack* trackid, double volume, bool relative) {
  return CSurf_OnVolumeChange(trackid, volume, relative);
}

REAPER_PLUGIN_DLL_EXPORT double _CSurf_OnVolumeChangeEx(MediaTrack* trackid, double volume, bool relative, bool allowGang) {
  return CSurf_OnVolumeChangeEx(trackid, volume, relative, allowGang);
}

REAPER_PLUGIN_DLL_EXPORT double _CSurf_OnWidthChange(MediaTrack* trackid, double width, bool relative) {
  return CSurf_OnWidthChange(trackid, width, relative);
}

REAPER_PLUGIN_DLL_EXPORT double _CSurf_OnWidthChangeEx(MediaTrack* trackid, double width, bool relative, bool allowGang) {
  return CSurf_OnWidthChangeEx(trackid, width, relative, allowGang);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_OnZoom(int xdir, int ydir) {
  return CSurf_OnZoom(xdir, ydir);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_ResetAllCachedVolPanStates() {
  return CSurf_ResetAllCachedVolPanStates();
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_ScrubAmt(double amt) {
  return CSurf_ScrubAmt(amt);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_SetAutoMode(int mode, IReaperControlSurface* ignoresurf) {
  return CSurf_SetAutoMode(mode, ignoresurf);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_SetPlayState(bool play, bool pause, bool rec, IReaperControlSurface* ignoresurf) {
  return CSurf_SetPlayState(play, pause, rec, ignoresurf);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_SetRepeatState(bool rep, IReaperControlSurface* ignoresurf) {
  return CSurf_SetRepeatState(rep, ignoresurf);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_SetSurfaceMute(MediaTrack* trackid, bool mute, IReaperControlSurface* ignoresurf) {
  return CSurf_SetSurfaceMute(trackid, mute, ignoresurf);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_SetSurfacePan(MediaTrack* trackid, double pan, IReaperControlSurface* ignoresurf) {
  return CSurf_SetSurfacePan(trackid, pan, ignoresurf);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_SetSurfaceRecArm(MediaTrack* trackid, bool recarm, IReaperControlSurface* ignoresurf) {
  return CSurf_SetSurfaceRecArm(trackid, recarm, ignoresurf);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_SetSurfaceSelected(MediaTrack* trackid, bool selected, IReaperControlSurface* ignoresurf) {
  return CSurf_SetSurfaceSelected(trackid, selected, ignoresurf);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_SetSurfaceSolo(MediaTrack* trackid, bool solo, IReaperControlSurface* ignoresurf) {
  return CSurf_SetSurfaceSolo(trackid, solo, ignoresurf);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_SetSurfaceVolume(MediaTrack* trackid, double volume, IReaperControlSurface* ignoresurf) {
  return CSurf_SetSurfaceVolume(trackid, volume, ignoresurf);
}

REAPER_PLUGIN_DLL_EXPORT void _CSurf_SetTrackListChange() {
  return CSurf_SetTrackListChange();
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _CSurf_TrackFromID(int idx, bool mcpView) {
  return CSurf_TrackFromID(idx, mcpView);
}

REAPER_PLUGIN_DLL_EXPORT int _CSurf_TrackToID(MediaTrack* track, bool mcpView) {
  return CSurf_TrackToID(track, mcpView);
}

REAPER_PLUGIN_DLL_EXPORT double _DB2SLIDER(double x) {
  return DB2SLIDER(x);
}

REAPER_PLUGIN_DLL_EXPORT bool _DeleteActionShortcut(KbdSectionInfo* section, int cmdID, int shortcutidx) {
  return DeleteActionShortcut(section, cmdID, shortcutidx);
}

REAPER_PLUGIN_DLL_EXPORT bool _DeleteEnvelopePointEx(TrackEnvelope* envelope, int autoitem_idx, int ptidx) {
  return DeleteEnvelopePointEx(envelope, autoitem_idx, ptidx);
}

REAPER_PLUGIN_DLL_EXPORT bool _DeleteEnvelopePointRange(TrackEnvelope* envelope, double time_start, double time_end) {
  return DeleteEnvelopePointRange(envelope, time_start, time_end);
}

REAPER_PLUGIN_DLL_EXPORT bool _DeleteEnvelopePointRangeEx(TrackEnvelope* envelope, int autoitem_idx, double time_start, double time_end) {
  return DeleteEnvelopePointRangeEx(envelope, autoitem_idx, time_start, time_end);
}

REAPER_PLUGIN_DLL_EXPORT void _DeleteExtState(const char* section, const char* key, bool persist) {
  return DeleteExtState(section, key, persist);
}

REAPER_PLUGIN_DLL_EXPORT bool _DeleteProjectMarker(ReaProject* proj, int markrgnindexnumber, bool isrgn) {
  return DeleteProjectMarker(proj, markrgnindexnumber, isrgn);
}

REAPER_PLUGIN_DLL_EXPORT bool _DeleteProjectMarkerByIndex(ReaProject* proj, int markrgnidx) {
  return DeleteProjectMarkerByIndex(proj, markrgnidx);
}

REAPER_PLUGIN_DLL_EXPORT bool _DeleteTakeMarker(MediaItem_Take* take, int idx) {
  return DeleteTakeMarker(take, idx);
}

REAPER_PLUGIN_DLL_EXPORT int _DeleteTakeStretchMarkers(MediaItem_Take* take, int idx, const int* countInOptional) {
  return DeleteTakeStretchMarkers(take, idx, countInOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _DeleteTempoTimeSigMarker(ReaProject* project, int markerindex) {
  return DeleteTempoTimeSigMarker(project, markerindex);
}

REAPER_PLUGIN_DLL_EXPORT void _DeleteTrack(MediaTrack* tr) {
  return DeleteTrack(tr);
}

REAPER_PLUGIN_DLL_EXPORT bool _DeleteTrackMediaItem(MediaTrack* tr, MediaItem* it) {
  return DeleteTrackMediaItem(tr, it);
}

REAPER_PLUGIN_DLL_EXPORT void _DestroyAudioAccessor(AudioAccessor* accessor) {
  return DestroyAudioAccessor(accessor);
}

REAPER_PLUGIN_DLL_EXPORT void _DestroyLocalOscHandler(void* local_osc_handler) {
  return DestroyLocalOscHandler(local_osc_handler);
}

REAPER_PLUGIN_DLL_EXPORT bool _DoActionShortcutDialog(HWND hwnd, KbdSectionInfo* section, int cmdID, int shortcutidx) {
  return DoActionShortcutDialog(hwnd, section, cmdID, shortcutidx);
}

REAPER_PLUGIN_DLL_EXPORT void _Dock_UpdateDockID(const char* ident_str, int whichDock) {
  return Dock_UpdateDockID(ident_str, whichDock);
}

REAPER_PLUGIN_DLL_EXPORT int _DockGetPosition(int whichDock) {
  return DockGetPosition(whichDock);
}

REAPER_PLUGIN_DLL_EXPORT int _DockIsChildOfDock(HWND hwnd, bool* isFloatingDockerOut) {
  return DockIsChildOfDock(hwnd, isFloatingDockerOut);
}

REAPER_PLUGIN_DLL_EXPORT void _DockWindowActivate(HWND hwnd) {
  return DockWindowActivate(hwnd);
}

REAPER_PLUGIN_DLL_EXPORT void _DockWindowAdd(HWND hwnd, const char* name, int pos, bool allowShow) {
  return DockWindowAdd(hwnd, name, pos, allowShow);
}

REAPER_PLUGIN_DLL_EXPORT void _DockWindowAddEx(HWND hwnd, const char* name, const char* identstr, bool allowShow) {
  return DockWindowAddEx(hwnd, name, identstr, allowShow);
}

REAPER_PLUGIN_DLL_EXPORT void _DockWindowRefresh() {
  return DockWindowRefresh();
}

REAPER_PLUGIN_DLL_EXPORT void _DockWindowRefreshForHWND(HWND hwnd) {
  return DockWindowRefreshForHWND(hwnd);
}

REAPER_PLUGIN_DLL_EXPORT void _DockWindowRemove(HWND hwnd) {
  return DockWindowRemove(hwnd);
}

REAPER_PLUGIN_DLL_EXPORT bool _DuplicateCustomizableMenu(void* srcmenu, void* destmenu) {
  return DuplicateCustomizableMenu(srcmenu, destmenu);
}

REAPER_PLUGIN_DLL_EXPORT bool _EditTempoTimeSigMarker(ReaProject* project, int markerindex) {
  return EditTempoTimeSigMarker(project, markerindex);
}

REAPER_PLUGIN_DLL_EXPORT void _EnsureNotCompletelyOffscreen(RECT* rInOut) {
  return EnsureNotCompletelyOffscreen(rInOut);
}

REAPER_PLUGIN_DLL_EXPORT const char* _EnumerateFiles(const char* path, int fileindex) {
  return EnumerateFiles(path, fileindex);
}

REAPER_PLUGIN_DLL_EXPORT const char* _EnumerateSubdirectories(const char* path, int subdirindex) {
  return EnumerateSubdirectories(path, subdirindex);
}

REAPER_PLUGIN_DLL_EXPORT bool _EnumPitchShiftModes(int mode, const char** strOut) {
  return EnumPitchShiftModes(mode, strOut);
}

REAPER_PLUGIN_DLL_EXPORT const char* _EnumPitchShiftSubModes(int mode, int submode) {
  return EnumPitchShiftSubModes(mode, submode);
}

REAPER_PLUGIN_DLL_EXPORT int _EnumProjectMarkers(int idx, bool* isrgnOut, double* posOut, double* rgnendOut, const char** nameOut, int* markrgnindexnumberOut) {
  return EnumProjectMarkers(idx, isrgnOut, posOut, rgnendOut, nameOut, markrgnindexnumberOut);
}

REAPER_PLUGIN_DLL_EXPORT int _EnumProjectMarkers2(ReaProject* proj, int idx, bool* isrgnOut, double* posOut, double* rgnendOut, const char** nameOut, int* markrgnindexnumberOut) {
  return EnumProjectMarkers2(proj, idx, isrgnOut, posOut, rgnendOut, nameOut, markrgnindexnumberOut);
}

REAPER_PLUGIN_DLL_EXPORT int _EnumProjectMarkers3(ReaProject* proj, int idx, bool* isrgnOut, double* posOut, double* rgnendOut, const char** nameOut, int* markrgnindexnumberOut, int* colorOut) {
  return EnumProjectMarkers3(proj, idx, isrgnOut, posOut, rgnendOut, nameOut, markrgnindexnumberOut, colorOut);
}

REAPER_PLUGIN_DLL_EXPORT ReaProject* _EnumProjects(int idx, char* projfnOutOptional, int projfnOutOptional_sz) {
  return EnumProjects(idx, projfnOutOptional, projfnOutOptional_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _EnumProjExtState(ReaProject* proj, const char* extname, int idx, char* keyOutOptional, int keyOutOptional_sz, char* valOutOptional, int valOutOptional_sz) {
  return EnumProjExtState(proj, extname, idx, keyOutOptional, keyOutOptional_sz, valOutOptional, valOutOptional_sz);
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _EnumRegionRenderMatrix(ReaProject* proj, int regionindex, int rendertrack) {
  return EnumRegionRenderMatrix(proj, regionindex, rendertrack);
}

REAPER_PLUGIN_DLL_EXPORT bool _EnumTrackMIDIProgramNames(int track, int programNumber, char* programName, int programName_sz) {
  return EnumTrackMIDIProgramNames(track, programNumber, programName, programName_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _EnumTrackMIDIProgramNamesEx(ReaProject* proj, MediaTrack* track, int programNumber, char* programName, int programName_sz) {
  return EnumTrackMIDIProgramNamesEx(proj, track, programNumber, programName, programName_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _Envelope_Evaluate(TrackEnvelope* envelope, double time, double samplerate, int samplesRequested, double* valueOutOptional, double* dVdSOutOptional, double* ddVdSOutOptional, double* dddVdSOutOptional) {
  return Envelope_Evaluate(envelope, time, samplerate, samplesRequested, valueOutOptional, dVdSOutOptional, ddVdSOutOptional, dddVdSOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT void _Envelope_FormatValue(TrackEnvelope* env, double value, char* bufOut, int bufOut_sz) {
  return Envelope_FormatValue(env, value, bufOut, bufOut_sz);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem_Take* _Envelope_GetParentTake(TrackEnvelope* env, int* indexOutOptional, int* index2OutOptional) {
  return Envelope_GetParentTake(env, indexOutOptional, index2OutOptional);
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _Envelope_GetParentTrack(TrackEnvelope* env, int* indexOutOptional, int* index2OutOptional) {
  return Envelope_GetParentTrack(env, indexOutOptional, index2OutOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _Envelope_SortPoints(TrackEnvelope* envelope) {
  return Envelope_SortPoints(envelope);
}

REAPER_PLUGIN_DLL_EXPORT bool _Envelope_SortPointsEx(TrackEnvelope* envelope, int autoitem_idx) {
  return Envelope_SortPointsEx(envelope, autoitem_idx);
}

REAPER_PLUGIN_DLL_EXPORT const char* _ExecProcess(const char* cmdline, int timeoutmsec) {
  return ExecProcess(cmdline, timeoutmsec);
}

REAPER_PLUGIN_DLL_EXPORT bool _file_exists(const char* path) {
  return file_exists(path);
}

REAPER_PLUGIN_DLL_EXPORT int _FindTempoTimeSigMarker(ReaProject* project, double time) {
  return FindTempoTimeSigMarker(project, time);
}

REAPER_PLUGIN_DLL_EXPORT void _format_timestr(double tpos, char* buf, int buf_sz) {
  return format_timestr(tpos, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT void _format_timestr_len(double tpos, char* buf, int buf_sz, double offset, int modeoverride) {
  return format_timestr_len(tpos, buf, buf_sz, offset, modeoverride);
}

REAPER_PLUGIN_DLL_EXPORT void _format_timestr_pos(double tpos, char* buf, int buf_sz, int modeoverride) {
  return format_timestr_pos(tpos, buf, buf_sz, modeoverride);
}

REAPER_PLUGIN_DLL_EXPORT void _FreeHeapPtr(void* ptr) {
  return FreeHeapPtr(ptr);
}

REAPER_PLUGIN_DLL_EXPORT void _genGuid(GUID* g) {
  return genGuid(g);
}

REAPER_PLUGIN_DLL_EXPORT void* _get_config_var(const char* name, int* szOut) {
  return get_config_var(name, szOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _get_config_var_string(const char* name, char* bufOut, int bufOut_sz) {
  return get_config_var_string(name, bufOut, bufOut_sz);
}

REAPER_PLUGIN_DLL_EXPORT const char* _get_ini_file() {
  return get_ini_file();
}

REAPER_PLUGIN_DLL_EXPORT void* _get_midi_config_var(const char* name, int* szOut) {
  return get_midi_config_var(name, szOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetActionShortcutDesc(KbdSectionInfo* section, int cmdID, int shortcutidx, char* desc, int desclen) {
  return GetActionShortcutDesc(section, cmdID, shortcutidx, desc, desclen);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem_Take* _GetActiveTake(MediaItem* item) {
  return GetActiveTake(item);
}

REAPER_PLUGIN_DLL_EXPORT int _GetAllProjectPlayStates(ReaProject* ignoreProject) {
  return GetAllProjectPlayStates(ignoreProject);
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetAppVersion() {
  return GetAppVersion();
}

REAPER_PLUGIN_DLL_EXPORT int _GetArmedCommand(char* secOut, int secOut_sz) {
  return GetArmedCommand(secOut, secOut_sz);
}

REAPER_PLUGIN_DLL_EXPORT double _GetAudioAccessorEndTime(AudioAccessor* accessor) {
  return GetAudioAccessorEndTime(accessor);
}

REAPER_PLUGIN_DLL_EXPORT void _GetAudioAccessorHash(AudioAccessor* accessor, char* hashNeed128) {
  return GetAudioAccessorHash(accessor, hashNeed128);
}

REAPER_PLUGIN_DLL_EXPORT int _GetAudioAccessorSamples(AudioAccessor* accessor, int samplerate, int numchannels, double starttime_sec, int numsamplesperchannel, double* samplebuffer) {
  return GetAudioAccessorSamples(accessor, samplerate, numchannels, starttime_sec, numsamplesperchannel, samplebuffer);
}

REAPER_PLUGIN_DLL_EXPORT double _GetAudioAccessorStartTime(AudioAccessor* accessor) {
  return GetAudioAccessorStartTime(accessor);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetAudioDeviceInfo(const char* attribute, char* desc, int desc_sz) {
  return GetAudioDeviceInfo(attribute, desc, desc_sz);
}

REAPER_PLUGIN_DLL_EXPORT INT_PTR _GetColorTheme(int idx, int defval) {
  return GetColorTheme(idx, defval);
}

REAPER_PLUGIN_DLL_EXPORT void* _GetColorThemeStruct(int* szOut) {
  return GetColorThemeStruct(szOut);
}

REAPER_PLUGIN_DLL_EXPORT int _GetConfigWantsDock(const char* ident_str) {
  return GetConfigWantsDock(ident_str);
}

REAPER_PLUGIN_DLL_EXPORT HMENU _GetContextMenu(int idx) {
  return GetContextMenu(idx);
}

REAPER_PLUGIN_DLL_EXPORT ReaProject* _GetCurrentProjectInLoadSave() {
  return GetCurrentProjectInLoadSave();
}

REAPER_PLUGIN_DLL_EXPORT int _GetCursorContext() {
  return GetCursorContext();
}

REAPER_PLUGIN_DLL_EXPORT int _GetCursorContext2(bool want_last_valid) {
  return GetCursorContext2(want_last_valid);
}

REAPER_PLUGIN_DLL_EXPORT double _GetCursorPosition() {
  return GetCursorPosition();
}

REAPER_PLUGIN_DLL_EXPORT double _GetCursorPositionEx(ReaProject* proj) {
  return GetCursorPositionEx(proj);
}

REAPER_PLUGIN_DLL_EXPORT int _GetDisplayedMediaItemColor(MediaItem* item) {
  return GetDisplayedMediaItemColor(item);
}

REAPER_PLUGIN_DLL_EXPORT int _GetDisplayedMediaItemColor2(MediaItem* item, MediaItem_Take* take) {
  return GetDisplayedMediaItemColor2(item, take);
}

REAPER_PLUGIN_DLL_EXPORT double _GetEnvelopeInfo_Value(TrackEnvelope* tr, const char* parmname) {
  return GetEnvelopeInfo_Value(tr, parmname);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetEnvelopeName(TrackEnvelope* env, char* bufOut, int bufOut_sz) {
  return GetEnvelopeName(env, bufOut, bufOut_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetEnvelopePoint(TrackEnvelope* envelope, int ptidx, double* timeOutOptional, double* valueOutOptional, int* shapeOutOptional, double* tensionOutOptional, bool* selectedOutOptional) {
  return GetEnvelopePoint(envelope, ptidx, timeOutOptional, valueOutOptional, shapeOutOptional, tensionOutOptional, selectedOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT int _GetEnvelopePointByTime(TrackEnvelope* envelope, double time) {
  return GetEnvelopePointByTime(envelope, time);
}

REAPER_PLUGIN_DLL_EXPORT int _GetEnvelopePointByTimeEx(TrackEnvelope* envelope, int autoitem_idx, double time) {
  return GetEnvelopePointByTimeEx(envelope, autoitem_idx, time);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetEnvelopePointEx(TrackEnvelope* envelope, int autoitem_idx, int ptidx, double* timeOutOptional, double* valueOutOptional, int* shapeOutOptional, double* tensionOutOptional, bool* selectedOutOptional) {
  return GetEnvelopePointEx(envelope, autoitem_idx, ptidx, timeOutOptional, valueOutOptional, shapeOutOptional, tensionOutOptional, selectedOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT int _GetEnvelopeScalingMode(TrackEnvelope* env) {
  return GetEnvelopeScalingMode(env);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetEnvelopeStateChunk(TrackEnvelope* env, char* strNeedBig, int strNeedBig_sz, bool isundoOptional) {
  return GetEnvelopeStateChunk(env, strNeedBig, strNeedBig_sz, isundoOptional);
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetExePath() {
  return GetExePath();
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetExtState(const char* section, const char* key) {
  return GetExtState(section, key);
}

REAPER_PLUGIN_DLL_EXPORT int _GetFocusedFX(int* tracknumberOut, int* itemnumberOut, int* fxnumberOut) {
  return GetFocusedFX(tracknumberOut, itemnumberOut, fxnumberOut);
}

REAPER_PLUGIN_DLL_EXPORT int _GetFocusedFX2(int* tracknumberOut, int* itemnumberOut, int* fxnumberOut) {
  return GetFocusedFX2(tracknumberOut, itemnumberOut, fxnumberOut);
}

REAPER_PLUGIN_DLL_EXPORT int _GetFreeDiskSpaceForRecordPath(ReaProject* proj, int pathidx) {
  return GetFreeDiskSpaceForRecordPath(proj, pathidx);
}

REAPER_PLUGIN_DLL_EXPORT TrackEnvelope* _GetFXEnvelope(MediaTrack* track, int fxindex, int parameterindex, bool create) {
  return GetFXEnvelope(track, fxindex, parameterindex, create);
}

REAPER_PLUGIN_DLL_EXPORT int _GetGlobalAutomationOverride() {
  return GetGlobalAutomationOverride();
}

REAPER_PLUGIN_DLL_EXPORT double _GetHZoomLevel() {
  return GetHZoomLevel();
}

REAPER_PLUGIN_DLL_EXPORT void* _GetIconThemePointer(const char* name) {
  return GetIconThemePointer(name);
}

REAPER_PLUGIN_DLL_EXPORT void* _GetIconThemePointerForDPI(const char* name, int dpisc) {
  return GetIconThemePointerForDPI(name, dpisc);
}

REAPER_PLUGIN_DLL_EXPORT void* _GetIconThemeStruct(int* szOut) {
  return GetIconThemeStruct(szOut);
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetInputChannelName(int channelIndex) {
  return GetInputChannelName(channelIndex);
}

REAPER_PLUGIN_DLL_EXPORT void _GetInputOutputLatency(int* inputlatencyOut, int* outputLatencyOut) {
  return GetInputOutputLatency(inputlatencyOut, outputLatencyOut);
}

REAPER_PLUGIN_DLL_EXPORT double _GetItemEditingTime2(PCM_source** which_itemOut, int* flagsOut) {
  return GetItemEditingTime2(which_itemOut, flagsOut);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem* _GetItemFromPoint(int screen_x, int screen_y, bool allow_locked, MediaItem_Take** takeOutOptional) {
  return GetItemFromPoint(screen_x, screen_y, allow_locked, takeOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT ReaProject* _GetItemProjectContext(MediaItem* item) {
  return GetItemProjectContext(item);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetItemStateChunk(MediaItem* item, char* strNeedBig, int strNeedBig_sz, bool isundoOptional) {
  return GetItemStateChunk(item, strNeedBig, strNeedBig_sz, isundoOptional);
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetLastColorThemeFile() {
  return GetLastColorThemeFile();
}

REAPER_PLUGIN_DLL_EXPORT void _GetLastMarkerAndCurRegion(ReaProject* proj, double time, int* markeridxOut, int* regionidxOut) {
  return GetLastMarkerAndCurRegion(proj, time, markeridxOut, regionidxOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetLastTouchedFX(int* tracknumberOut, int* fxnumberOut, int* paramnumberOut) {
  return GetLastTouchedFX(tracknumberOut, fxnumberOut, paramnumberOut);
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _GetLastTouchedTrack() {
  return GetLastTouchedTrack();
}

REAPER_PLUGIN_DLL_EXPORT HWND _GetMainHwnd() {
  return GetMainHwnd();
}

REAPER_PLUGIN_DLL_EXPORT int _GetMasterMuteSoloFlags() {
  return GetMasterMuteSoloFlags();
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _GetMasterTrack(ReaProject* proj) {
  return GetMasterTrack(proj);
}

REAPER_PLUGIN_DLL_EXPORT int _GetMasterTrackVisibility() {
  return GetMasterTrackVisibility();
}

REAPER_PLUGIN_DLL_EXPORT int _GetMaxMidiInputs() {
  return GetMaxMidiInputs();
}

REAPER_PLUGIN_DLL_EXPORT int _GetMaxMidiOutputs() {
  return GetMaxMidiOutputs();
}

REAPER_PLUGIN_DLL_EXPORT int _GetMediaFileMetadata(PCM_source* mediaSource, const char* identifier, char* bufOutNeedBig, int bufOutNeedBig_sz) {
  return GetMediaFileMetadata(mediaSource, identifier, bufOutNeedBig, bufOutNeedBig_sz);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem* _GetMediaItem(ReaProject* proj, int itemidx) {
  return GetMediaItem(proj, itemidx);
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _GetMediaItem_Track(MediaItem* item) {
  return GetMediaItem_Track(item);
}

REAPER_PLUGIN_DLL_EXPORT double _GetMediaItemInfo_Value(MediaItem* item, const char* parmname) {
  return GetMediaItemInfo_Value(item, parmname);
}

REAPER_PLUGIN_DLL_EXPORT int _GetMediaItemNumTakes(MediaItem* item) {
  return GetMediaItemNumTakes(item);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem_Take* _GetMediaItemTake(MediaItem* item, int tk) {
  return GetMediaItemTake(item, tk);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem* _GetMediaItemTake_Item(MediaItem_Take* take) {
  return GetMediaItemTake_Item(take);
}

REAPER_PLUGIN_DLL_EXPORT int _GetMediaItemTake_Peaks(MediaItem_Take* take, double peakrate, double starttime, int numchannels, int numsamplesperchannel, int want_extra_type, double* buf) {
  return GetMediaItemTake_Peaks(take, peakrate, starttime, numchannels, numsamplesperchannel, want_extra_type, buf);
}

REAPER_PLUGIN_DLL_EXPORT PCM_source* _GetMediaItemTake_Source(MediaItem_Take* take) {
  return GetMediaItemTake_Source(take);
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _GetMediaItemTake_Track(MediaItem_Take* take) {
  return GetMediaItemTake_Track(take);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem_Take* _GetMediaItemTakeByGUID(ReaProject* project, const GUID* guid) {
  return GetMediaItemTakeByGUID(project, guid);
}

REAPER_PLUGIN_DLL_EXPORT double _GetMediaItemTakeInfo_Value(MediaItem_Take* take, const char* parmname) {
  return GetMediaItemTakeInfo_Value(take, parmname);
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _GetMediaItemTrack(MediaItem* item) {
  return GetMediaItemTrack(item);
}

REAPER_PLUGIN_DLL_EXPORT void _GetMediaSourceFileName(PCM_source* source, char* filenamebuf, int filenamebuf_sz) {
  return GetMediaSourceFileName(source, filenamebuf, filenamebuf_sz);
}

REAPER_PLUGIN_DLL_EXPORT double _GetMediaSourceLength(PCM_source* source, bool* lengthIsQNOut) {
  return GetMediaSourceLength(source, lengthIsQNOut);
}

REAPER_PLUGIN_DLL_EXPORT int _GetMediaSourceNumChannels(PCM_source* source) {
  return GetMediaSourceNumChannels(source);
}

REAPER_PLUGIN_DLL_EXPORT PCM_source* _GetMediaSourceParent(PCM_source* src) {
  return GetMediaSourceParent(src);
}

REAPER_PLUGIN_DLL_EXPORT int _GetMediaSourceSampleRate(PCM_source* source) {
  return GetMediaSourceSampleRate(source);
}

REAPER_PLUGIN_DLL_EXPORT void _GetMediaSourceType(PCM_source* source, char* typebuf, int typebuf_sz) {
  return GetMediaSourceType(source, typebuf, typebuf_sz);
}

REAPER_PLUGIN_DLL_EXPORT double _GetMediaTrackInfo_Value(MediaTrack* tr, const char* parmname) {
  return GetMediaTrackInfo_Value(tr, parmname);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetMIDIInputName(int dev, char* nameout, int nameout_sz) {
  return GetMIDIInputName(dev, nameout, nameout_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetMIDIOutputName(int dev, char* nameout, int nameout_sz) {
  return GetMIDIOutputName(dev, nameout, nameout_sz);
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _GetMixerScroll() {
  return GetMixerScroll();
}

REAPER_PLUGIN_DLL_EXPORT void _GetMouseModifier(const char* context, int modifier_flag, char* action, int action_sz) {
  return GetMouseModifier(context, modifier_flag, action, action_sz);
}

REAPER_PLUGIN_DLL_EXPORT void _GetMousePosition(int* xOut, int* yOut) {
  return GetMousePosition(xOut, yOut);
}

REAPER_PLUGIN_DLL_EXPORT int _GetNumAudioInputs() {
  return GetNumAudioInputs();
}

REAPER_PLUGIN_DLL_EXPORT int _GetNumAudioOutputs() {
  return GetNumAudioOutputs();
}

REAPER_PLUGIN_DLL_EXPORT int _GetNumMIDIInputs() {
  return GetNumMIDIInputs();
}

REAPER_PLUGIN_DLL_EXPORT int _GetNumMIDIOutputs() {
  return GetNumMIDIOutputs();
}

REAPER_PLUGIN_DLL_EXPORT int _GetNumTakeMarkers(MediaItem_Take* take) {
  return GetNumTakeMarkers(take);
}

REAPER_PLUGIN_DLL_EXPORT int _GetNumTracks() {
  return GetNumTracks();
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetOS() {
  return GetOS();
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetOutputChannelName(int channelIndex) {
  return GetOutputChannelName(channelIndex);
}

REAPER_PLUGIN_DLL_EXPORT double _GetOutputLatency() {
  return GetOutputLatency();
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _GetParentTrack(MediaTrack* track) {
  return GetParentTrack(track);
}

REAPER_PLUGIN_DLL_EXPORT void _GetPeakFileName(const char* fn, char* buf, int buf_sz) {
  return GetPeakFileName(fn, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT void _GetPeakFileNameEx(const char* fn, char* buf, int buf_sz, bool forWrite) {
  return GetPeakFileNameEx(fn, buf, buf_sz, forWrite);
}

REAPER_PLUGIN_DLL_EXPORT void _GetPeakFileNameEx2(const char* fn, char* buf, int buf_sz, bool forWrite, const char* peaksfileextension) {
  return GetPeakFileNameEx2(fn, buf, buf_sz, forWrite, peaksfileextension);
}

REAPER_PLUGIN_DLL_EXPORT void* _GetPeaksBitmap(PCM_source_peaktransfer_t* pks, double maxamp, int w, int h, LICE_IBitmap* bmp) {
  return GetPeaksBitmap(pks, maxamp, w, h, bmp);
}

REAPER_PLUGIN_DLL_EXPORT double _GetPlayPosition() {
  return GetPlayPosition();
}

REAPER_PLUGIN_DLL_EXPORT double _GetPlayPosition2() {
  return GetPlayPosition2();
}

REAPER_PLUGIN_DLL_EXPORT double _GetPlayPosition2Ex(ReaProject* proj) {
  return GetPlayPosition2Ex(proj);
}

REAPER_PLUGIN_DLL_EXPORT double _GetPlayPositionEx(ReaProject* proj) {
  return GetPlayPositionEx(proj);
}

REAPER_PLUGIN_DLL_EXPORT int _GetPlayState() {
  return GetPlayState();
}

REAPER_PLUGIN_DLL_EXPORT int _GetPlayStateEx(ReaProject* proj) {
  return GetPlayStateEx(proj);
}

REAPER_PLUGIN_DLL_EXPORT void _GetPreferredDiskReadMode(int* mode, int* nb, int* bs) {
  return GetPreferredDiskReadMode(mode, nb, bs);
}

REAPER_PLUGIN_DLL_EXPORT void _GetPreferredDiskReadModePeak(int* mode, int* nb, int* bs) {
  return GetPreferredDiskReadModePeak(mode, nb, bs);
}

REAPER_PLUGIN_DLL_EXPORT void _GetPreferredDiskWriteMode(int* mode, int* nb, int* bs) {
  return GetPreferredDiskWriteMode(mode, nb, bs);
}

REAPER_PLUGIN_DLL_EXPORT double _GetProjectLength(ReaProject* proj) {
  return GetProjectLength(proj);
}

REAPER_PLUGIN_DLL_EXPORT void _GetProjectName(ReaProject* proj, char* buf, int buf_sz) {
  return GetProjectName(proj, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT void _GetProjectPath(char* buf, int buf_sz) {
  return GetProjectPath(buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT void _GetProjectPathEx(ReaProject* proj, char* buf, int buf_sz) {
  return GetProjectPathEx(proj, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _GetProjectStateChangeCount(ReaProject* proj) {
  return GetProjectStateChangeCount(proj);
}

REAPER_PLUGIN_DLL_EXPORT double _GetProjectTimeOffset(ReaProject* proj, bool rndframe) {
  return GetProjectTimeOffset(proj, rndframe);
}

REAPER_PLUGIN_DLL_EXPORT void _GetProjectTimeSignature(double* bpmOut, double* bpiOut) {
  return GetProjectTimeSignature(bpmOut, bpiOut);
}

REAPER_PLUGIN_DLL_EXPORT void _GetProjectTimeSignature2(ReaProject* proj, double* bpmOut, double* bpiOut) {
  return GetProjectTimeSignature2(proj, bpmOut, bpiOut);
}

REAPER_PLUGIN_DLL_EXPORT int _GetProjExtState(ReaProject* proj, const char* extname, const char* key, char* valOutNeedBig, int valOutNeedBig_sz) {
  return GetProjExtState(proj, extname, key, valOutNeedBig, valOutNeedBig_sz);
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetResourcePath() {
  return GetResourcePath();
}

REAPER_PLUGIN_DLL_EXPORT TrackEnvelope* _GetSelectedEnvelope(ReaProject* proj) {
  return GetSelectedEnvelope(proj);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem* _GetSelectedMediaItem(ReaProject* proj, int selitem) {
  return GetSelectedMediaItem(proj, selitem);
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _GetSelectedTrack(ReaProject* proj, int seltrackidx) {
  return GetSelectedTrack(proj, seltrackidx);
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _GetSelectedTrack2(ReaProject* proj, int seltrackidx, bool wantmaster) {
  return GetSelectedTrack2(proj, seltrackidx, wantmaster);
}

REAPER_PLUGIN_DLL_EXPORT TrackEnvelope* _GetSelectedTrackEnvelope(ReaProject* proj) {
  return GetSelectedTrackEnvelope(proj);
}

REAPER_PLUGIN_DLL_EXPORT void _GetSet_ArrangeView2(ReaProject* proj, bool isSet, int screen_x_start, int screen_x_end, double* start_timeOut, double* end_timeOut) {
  return GetSet_ArrangeView2(proj, isSet, screen_x_start, screen_x_end, start_timeOut, end_timeOut);
}

REAPER_PLUGIN_DLL_EXPORT void _GetSet_LoopTimeRange(bool isSet, bool isLoop, double* startOut, double* endOut, bool allowautoseek) {
  return GetSet_LoopTimeRange(isSet, isLoop, startOut, endOut, allowautoseek);
}

REAPER_PLUGIN_DLL_EXPORT void _GetSet_LoopTimeRange2(ReaProject* proj, bool isSet, bool isLoop, double* startOut, double* endOut, bool allowautoseek) {
  return GetSet_LoopTimeRange2(proj, isSet, isLoop, startOut, endOut, allowautoseek);
}

REAPER_PLUGIN_DLL_EXPORT double _GetSetAutomationItemInfo(TrackEnvelope* env, int autoitem_idx, const char* desc, double value, bool is_set) {
  return GetSetAutomationItemInfo(env, autoitem_idx, desc, value, is_set);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetAutomationItemInfo_String(TrackEnvelope* env, int autoitem_idx, const char* desc, char* valuestrNeedBig, bool is_set) {
  return GetSetAutomationItemInfo_String(env, autoitem_idx, desc, valuestrNeedBig, is_set);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetEnvelopeInfo_String(TrackEnvelope* env, const char* parmname, char* stringNeedBig, bool setNewValue) {
  return GetSetEnvelopeInfo_String(env, parmname, stringNeedBig, setNewValue);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetEnvelopeState(TrackEnvelope* env, char* str, int str_sz) {
  return GetSetEnvelopeState(env, str, str_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetEnvelopeState2(TrackEnvelope* env, char* str, int str_sz, bool isundo) {
  return GetSetEnvelopeState2(env, str, str_sz, isundo);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetItemState(MediaItem* item, char* str, int str_sz) {
  return GetSetItemState(item, str, str_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetItemState2(MediaItem* item, char* str, int str_sz, bool isundo) {
  return GetSetItemState2(item, str, str_sz, isundo);
}

REAPER_PLUGIN_DLL_EXPORT void* _GetSetMediaItemInfo(MediaItem* item, const char* parmname, void* setNewValue) {
  return GetSetMediaItemInfo(item, parmname, setNewValue);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetMediaItemInfo_String(MediaItem* item, const char* parmname, char* stringNeedBig, bool setNewValue) {
  return GetSetMediaItemInfo_String(item, parmname, stringNeedBig, setNewValue);
}

REAPER_PLUGIN_DLL_EXPORT void* _GetSetMediaItemTakeInfo(MediaItem_Take* tk, const char* parmname, void* setNewValue) {
  return GetSetMediaItemTakeInfo(tk, parmname, setNewValue);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetMediaItemTakeInfo_String(MediaItem_Take* tk, const char* parmname, char* stringNeedBig, bool setNewValue) {
  return GetSetMediaItemTakeInfo_String(tk, parmname, stringNeedBig, setNewValue);
}

REAPER_PLUGIN_DLL_EXPORT void* _GetSetMediaTrackInfo(MediaTrack* tr, const char* parmname, void* setNewValue) {
  return GetSetMediaTrackInfo(tr, parmname, setNewValue);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetMediaTrackInfo_String(MediaTrack* tr, const char* parmname, char* stringNeedBig, bool setNewValue) {
  return GetSetMediaTrackInfo_String(tr, parmname, stringNeedBig, setNewValue);
}

REAPER_PLUGIN_DLL_EXPORT char* _GetSetObjectState(void* obj, const char* str) {
  return GetSetObjectState(obj, str);
}

REAPER_PLUGIN_DLL_EXPORT char* _GetSetObjectState2(void* obj, const char* str, bool isundo) {
  return GetSetObjectState2(obj, str, isundo);
}

REAPER_PLUGIN_DLL_EXPORT void _GetSetProjectAuthor(ReaProject* proj, bool set, char* author, int author_sz) {
  return GetSetProjectAuthor(proj, set, author, author_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _GetSetProjectGrid(ReaProject* project, bool set, double* divisionInOutOptional, int* swingmodeInOutOptional, double* swingamtInOutOptional) {
  return GetSetProjectGrid(project, set, divisionInOutOptional, swingmodeInOutOptional, swingamtInOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT double _GetSetProjectInfo(ReaProject* project, const char* desc, double value, bool is_set) {
  return GetSetProjectInfo(project, desc, value, is_set);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetProjectInfo_String(ReaProject* project, const char* desc, char* valuestrNeedBig, bool is_set) {
  return GetSetProjectInfo_String(project, desc, valuestrNeedBig, is_set);
}

REAPER_PLUGIN_DLL_EXPORT void _GetSetProjectNotes(ReaProject* proj, bool set, char* notesNeedBig, int notesNeedBig_sz) {
  return GetSetProjectNotes(proj, set, notesNeedBig, notesNeedBig_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _GetSetRepeat(int val) {
  return GetSetRepeat(val);
}

REAPER_PLUGIN_DLL_EXPORT int _GetSetRepeatEx(ReaProject* proj, int val) {
  return GetSetRepeatEx(proj, val);
}

REAPER_PLUGIN_DLL_EXPORT unsigned int _GetSetTrackGroupMembership(MediaTrack* tr, const char* groupname, unsigned int setmask, unsigned int setvalue) {
  return GetSetTrackGroupMembership(tr, groupname, setmask, setvalue);
}

REAPER_PLUGIN_DLL_EXPORT unsigned int _GetSetTrackGroupMembershipHigh(MediaTrack* tr, const char* groupname, unsigned int setmask, unsigned int setvalue) {
  return GetSetTrackGroupMembershipHigh(tr, groupname, setmask, setvalue);
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetSetTrackMIDISupportFile(ReaProject* proj, MediaTrack* track, int which, const char* filename) {
  return GetSetTrackMIDISupportFile(proj, track, which, filename);
}

REAPER_PLUGIN_DLL_EXPORT void* _GetSetTrackSendInfo(MediaTrack* tr, int category, int sendidx, const char* parmname, void* setNewValue) {
  return GetSetTrackSendInfo(tr, category, sendidx, parmname, setNewValue);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetTrackSendInfo_String(MediaTrack* tr, int category, int sendidx, const char* parmname, char* stringNeedBig, bool setNewValue) {
  return GetSetTrackSendInfo_String(tr, category, sendidx, parmname, stringNeedBig, setNewValue);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetTrackState(MediaTrack* track, char* str, int str_sz) {
  return GetSetTrackState(track, str, str_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetSetTrackState2(MediaTrack* track, char* str, int str_sz, bool isundo) {
  return GetSetTrackState2(track, str, str_sz, isundo);
}

REAPER_PLUGIN_DLL_EXPORT ReaProject* _GetSubProjectFromSource(PCM_source* src) {
  return GetSubProjectFromSource(src);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem_Take* _GetTake(MediaItem* item, int takeidx) {
  return GetTake(item, takeidx);
}

REAPER_PLUGIN_DLL_EXPORT TrackEnvelope* _GetTakeEnvelope(MediaItem_Take* take, int envidx) {
  return GetTakeEnvelope(take, envidx);
}

REAPER_PLUGIN_DLL_EXPORT TrackEnvelope* _GetTakeEnvelopeByName(MediaItem_Take* take, const char* envname) {
  return GetTakeEnvelopeByName(take, envname);
}

REAPER_PLUGIN_DLL_EXPORT double _GetTakeMarker(MediaItem_Take* take, int idx, char* nameOut, int nameOut_sz, int* colorOutOptional) {
  return GetTakeMarker(take, idx, nameOut, nameOut_sz, colorOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetTakeName(MediaItem_Take* take) {
  return GetTakeName(take);
}

REAPER_PLUGIN_DLL_EXPORT int _GetTakeNumStretchMarkers(MediaItem_Take* take) {
  return GetTakeNumStretchMarkers(take);
}

REAPER_PLUGIN_DLL_EXPORT int _GetTakeStretchMarker(MediaItem_Take* take, int idx, double* posOut, double* srcposOutOptional) {
  return GetTakeStretchMarker(take, idx, posOut, srcposOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT double _GetTakeStretchMarkerSlope(MediaItem_Take* take, int idx) {
  return GetTakeStretchMarkerSlope(take, idx);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTCPFXParm(ReaProject* project, MediaTrack* track, int index, int* fxindexOut, int* parmidxOut) {
  return GetTCPFXParm(project, track, index, fxindexOut, parmidxOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTempoMatchPlayRate(PCM_source* source, double srcscale, double position, double mult, double* rateOut, double* targetlenOut) {
  return GetTempoMatchPlayRate(source, srcscale, position, mult, rateOut, targetlenOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTempoTimeSigMarker(ReaProject* proj, int ptidx, double* timeposOut, int* measureposOut, double* beatposOut, double* bpmOut, int* timesig_numOut, int* timesig_denomOut, bool* lineartempoOut) {
  return GetTempoTimeSigMarker(proj, ptidx, timeposOut, measureposOut, beatposOut, bpmOut, timesig_numOut, timesig_denomOut, lineartempoOut);
}

REAPER_PLUGIN_DLL_EXPORT int _GetThemeColor(const char* ini_key, int flagsOptional) {
  return GetThemeColor(ini_key, flagsOptional);
}

REAPER_PLUGIN_DLL_EXPORT int _GetToggleCommandState(int command_id) {
  return GetToggleCommandState(command_id);
}

REAPER_PLUGIN_DLL_EXPORT int _GetToggleCommandState2(KbdSectionInfo* section, int command_id) {
  return GetToggleCommandState2(section, command_id);
}

REAPER_PLUGIN_DLL_EXPORT int _GetToggleCommandStateEx(int section_id, int command_id) {
  return GetToggleCommandStateEx(section_id, command_id);
}

REAPER_PLUGIN_DLL_EXPORT int _GetToggleCommandStateThroughHooks(KbdSectionInfo* section, int command_id) {
  return GetToggleCommandStateThroughHooks(section, command_id);
}

REAPER_PLUGIN_DLL_EXPORT HWND _GetTooltipWindow() {
  return GetTooltipWindow();
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _GetTrack(ReaProject* proj, int trackidx) {
  return GetTrack(proj, trackidx);
}

REAPER_PLUGIN_DLL_EXPORT int _GetTrackAutomationMode(MediaTrack* tr) {
  return GetTrackAutomationMode(tr);
}

REAPER_PLUGIN_DLL_EXPORT int _GetTrackColor(MediaTrack* track) {
  return GetTrackColor(track);
}

REAPER_PLUGIN_DLL_EXPORT int _GetTrackDepth(MediaTrack* track) {
  return GetTrackDepth(track);
}

REAPER_PLUGIN_DLL_EXPORT TrackEnvelope* _GetTrackEnvelope(MediaTrack* track, int envidx) {
  return GetTrackEnvelope(track, envidx);
}

REAPER_PLUGIN_DLL_EXPORT TrackEnvelope* _GetTrackEnvelopeByChunkName(MediaTrack* tr, const char* cfgchunkname) {
  return GetTrackEnvelopeByChunkName(tr, cfgchunkname);
}

REAPER_PLUGIN_DLL_EXPORT TrackEnvelope* _GetTrackEnvelopeByName(MediaTrack* track, const char* envname) {
  return GetTrackEnvelopeByName(track, envname);
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _GetTrackFromPoint(int screen_x, int screen_y, int* infoOutOptional) {
  return GetTrackFromPoint(screen_x, screen_y, infoOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT GUID* _GetTrackGUID(MediaTrack* tr) {
  return GetTrackGUID(tr);
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetTrackInfo(INT_PTR track, int* flags) {
  return GetTrackInfo(track, flags);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem* _GetTrackMediaItem(MediaTrack* tr, int itemidx) {
  return GetTrackMediaItem(tr, itemidx);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackMIDILyrics(MediaTrack* track, int flag, char* bufWantNeedBig, int* bufWantNeedBig_sz) {
  return GetTrackMIDILyrics(track, flag, bufWantNeedBig, bufWantNeedBig_sz);
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetTrackMIDINoteName(int track, int pitch, int chan) {
  return GetTrackMIDINoteName(track, pitch, chan);
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetTrackMIDINoteNameEx(ReaProject* proj, MediaTrack* track, int pitch, int chan) {
  return GetTrackMIDINoteNameEx(proj, track, pitch, chan);
}

REAPER_PLUGIN_DLL_EXPORT void _GetTrackMIDINoteRange(ReaProject* proj, MediaTrack* track, int* note_loOut, int* note_hiOut) {
  return GetTrackMIDINoteRange(proj, track, note_loOut, note_hiOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackName(MediaTrack* track, char* bufOut, int bufOut_sz) {
  return GetTrackName(track, bufOut, bufOut_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _GetTrackNumMediaItems(MediaTrack* tr) {
  return GetTrackNumMediaItems(tr);
}

REAPER_PLUGIN_DLL_EXPORT int _GetTrackNumSends(MediaTrack* tr, int category) {
  return GetTrackNumSends(tr, category);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackReceiveName(MediaTrack* track, int recv_index, char* buf, int buf_sz) {
  return GetTrackReceiveName(track, recv_index, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackReceiveUIMute(MediaTrack* track, int recv_index, bool* muteOut) {
  return GetTrackReceiveUIMute(track, recv_index, muteOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackReceiveUIVolPan(MediaTrack* track, int recv_index, double* volumeOut, double* panOut) {
  return GetTrackReceiveUIVolPan(track, recv_index, volumeOut, panOut);
}

REAPER_PLUGIN_DLL_EXPORT double _GetTrackSendInfo_Value(MediaTrack* tr, int category, int sendidx, const char* parmname) {
  return GetTrackSendInfo_Value(tr, category, sendidx, parmname);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackSendName(MediaTrack* track, int send_index, char* buf, int buf_sz) {
  return GetTrackSendName(track, send_index, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackSendUIMute(MediaTrack* track, int send_index, bool* muteOut) {
  return GetTrackSendUIMute(track, send_index, muteOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackSendUIVolPan(MediaTrack* track, int send_index, double* volumeOut, double* panOut) {
  return GetTrackSendUIVolPan(track, send_index, volumeOut, panOut);
}

REAPER_PLUGIN_DLL_EXPORT const char* _GetTrackState(MediaTrack* track, int* flagsOut) {
  return GetTrackState(track, flagsOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackStateChunk(MediaTrack* track, char* strNeedBig, int strNeedBig_sz, bool isundoOptional) {
  return GetTrackStateChunk(track, strNeedBig, strNeedBig_sz, isundoOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackUIMute(MediaTrack* track, bool* muteOut) {
  return GetTrackUIMute(track, muteOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackUIPan(MediaTrack* track, double* pan1Out, double* pan2Out, int* panmodeOut) {
  return GetTrackUIPan(track, pan1Out, pan2Out, panmodeOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetTrackUIVolPan(MediaTrack* track, double* volumeOut, double* panOut) {
  return GetTrackUIVolPan(track, volumeOut, panOut);
}

REAPER_PLUGIN_DLL_EXPORT void _GetUnderrunTime(unsigned int* audio_xrunOutOptional, unsigned int* media_xrunOutOptional, unsigned int* curtimeOutOptional) {
  return GetUnderrunTime(audio_xrunOutOptional, media_xrunOutOptional, curtimeOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetUserFileNameForRead(char* filenameNeed4096, const char* title, const char* defext) {
  return GetUserFileNameForRead(filenameNeed4096, title, defext);
}

REAPER_PLUGIN_DLL_EXPORT bool _GetUserInputs(const char* title, int num_inputs, const char* captions_csv, char* retvals_csv, int retvals_csv_sz) {
  return GetUserInputs(title, num_inputs, captions_csv, retvals_csv, retvals_csv_sz);
}

REAPER_PLUGIN_DLL_EXPORT void _GoToMarker(ReaProject* proj, int marker_index, bool use_timeline_order) {
  return GoToMarker(proj, marker_index, use_timeline_order);
}

REAPER_PLUGIN_DLL_EXPORT void _GoToRegion(ReaProject* proj, int region_index, bool use_timeline_order) {
  return GoToRegion(proj, region_index, use_timeline_order);
}

REAPER_PLUGIN_DLL_EXPORT int _GR_SelectColor(HWND hwnd, int* colorOut) {
  return GR_SelectColor(hwnd, colorOut);
}

REAPER_PLUGIN_DLL_EXPORT int _GSC_mainwnd(int t) {
  return GSC_mainwnd(t);
}

REAPER_PLUGIN_DLL_EXPORT void _guidToString(const GUID* g, char* destNeed64) {
  return guidToString(g, destNeed64);
}

REAPER_PLUGIN_DLL_EXPORT bool _HasExtState(const char* section, const char* key) {
  return HasExtState(section, key);
}

REAPER_PLUGIN_DLL_EXPORT const char* _HasTrackMIDIPrograms(int track) {
  return HasTrackMIDIPrograms(track);
}

REAPER_PLUGIN_DLL_EXPORT const char* _HasTrackMIDIProgramsEx(ReaProject* proj, MediaTrack* track) {
  return HasTrackMIDIProgramsEx(proj, track);
}

REAPER_PLUGIN_DLL_EXPORT void _Help_Set(const char* helpstring, bool is_temporary_help) {
  return Help_Set(helpstring, is_temporary_help);
}

REAPER_PLUGIN_DLL_EXPORT void _HiresPeaksFromSource(PCM_source* src, PCM_source_peaktransfer_t* block) {
  return HiresPeaksFromSource(src, block);
}

REAPER_PLUGIN_DLL_EXPORT void _image_resolve_fn(const char* in, char* out, int out_sz) {
  return image_resolve_fn(in, out, out_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _InsertAutomationItem(TrackEnvelope* env, int pool_id, double position, double length) {
  return InsertAutomationItem(env, pool_id, position, length);
}

REAPER_PLUGIN_DLL_EXPORT bool _InsertEnvelopePoint(TrackEnvelope* envelope, double time, double value, int shape, double tension, bool selected, bool* noSortInOptional) {
  return InsertEnvelopePoint(envelope, time, value, shape, tension, selected, noSortInOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _InsertEnvelopePointEx(TrackEnvelope* envelope, int autoitem_idx, double time, double value, int shape, double tension, bool selected, bool* noSortInOptional) {
  return InsertEnvelopePointEx(envelope, autoitem_idx, time, value, shape, tension, selected, noSortInOptional);
}

REAPER_PLUGIN_DLL_EXPORT int _InsertMedia(const char* file, int mode) {
  return InsertMedia(file, mode);
}

REAPER_PLUGIN_DLL_EXPORT int _InsertMediaSection(const char* file, int mode, double startpct, double endpct, double pitchshift) {
  return InsertMediaSection(file, mode, startpct, endpct, pitchshift);
}

REAPER_PLUGIN_DLL_EXPORT void _InsertTrackAtIndex(int idx, bool wantDefaults) {
  return InsertTrackAtIndex(idx, wantDefaults);
}

REAPER_PLUGIN_DLL_EXPORT int _IsInRealTimeAudio() {
  return IsInRealTimeAudio();
}

REAPER_PLUGIN_DLL_EXPORT bool _IsItemTakeActiveForPlayback(MediaItem* item, MediaItem_Take* take) {
  return IsItemTakeActiveForPlayback(item, take);
}

REAPER_PLUGIN_DLL_EXPORT bool _IsMediaExtension(const char* ext, bool wantOthers) {
  return IsMediaExtension(ext, wantOthers);
}

REAPER_PLUGIN_DLL_EXPORT bool _IsMediaItemSelected(MediaItem* item) {
  return IsMediaItemSelected(item);
}

REAPER_PLUGIN_DLL_EXPORT int _IsProjectDirty(ReaProject* proj) {
  return IsProjectDirty(proj);
}

REAPER_PLUGIN_DLL_EXPORT bool _IsREAPER() {
  return IsREAPER();
}

REAPER_PLUGIN_DLL_EXPORT bool _IsTrackSelected(MediaTrack* track) {
  return IsTrackSelected(track);
}

REAPER_PLUGIN_DLL_EXPORT bool _IsTrackVisible(MediaTrack* track, bool mixer) {
  return IsTrackVisible(track, mixer);
}

REAPER_PLUGIN_DLL_EXPORT joystick_device* _joystick_create(const GUID* guid) {
  return joystick_create(guid);
}

REAPER_PLUGIN_DLL_EXPORT void _joystick_destroy(joystick_device* device) {
  return joystick_destroy(device);
}

REAPER_PLUGIN_DLL_EXPORT const char* _joystick_enum(int index, const char** namestrOutOptional) {
  return joystick_enum(index, namestrOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT double _joystick_getaxis(joystick_device* dev, int axis) {
  return joystick_getaxis(dev, axis);
}

REAPER_PLUGIN_DLL_EXPORT unsigned int _joystick_getbuttonmask(joystick_device* dev) {
  return joystick_getbuttonmask(dev);
}

REAPER_PLUGIN_DLL_EXPORT int _joystick_getinfo(joystick_device* dev, int* axesOutOptional, int* povsOutOptional) {
  return joystick_getinfo(dev, axesOutOptional, povsOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT double _joystick_getpov(joystick_device* dev, int pov) {
  return joystick_getpov(dev, pov);
}

REAPER_PLUGIN_DLL_EXPORT bool _joystick_update(joystick_device* dev) {
  return joystick_update(dev);
}

REAPER_PLUGIN_DLL_EXPORT int _kbd_enumerateActions(KbdSectionInfo* section, int idx, const char** nameOut) {
  return kbd_enumerateActions(section, idx, nameOut);
}

REAPER_PLUGIN_DLL_EXPORT void _kbd_formatKeyName(ACCEL* ac, char* s) {
  return kbd_formatKeyName(ac, s);
}

REAPER_PLUGIN_DLL_EXPORT void _kbd_getCommandName(int cmd, char* s, KbdSectionInfo* section) {
  return kbd_getCommandName(cmd, s, section);
}

REAPER_PLUGIN_DLL_EXPORT const char* _kbd_getTextFromCmd(DWORD cmd, KbdSectionInfo* section) {
  return kbd_getTextFromCmd(cmd, section);
}

REAPER_PLUGIN_DLL_EXPORT int _KBD_OnMainActionEx(int cmd, int val, int valhw, int relmode, HWND hwnd, ReaProject* proj) {
  return KBD_OnMainActionEx(cmd, val, valhw, relmode, hwnd, proj);
}

REAPER_PLUGIN_DLL_EXPORT void _kbd_OnMidiEvent(MIDI_event_t* evt, int dev_index) {
  return kbd_OnMidiEvent(evt, dev_index);
}

REAPER_PLUGIN_DLL_EXPORT void _kbd_OnMidiList(MIDI_eventlist* list, int dev_index) {
  return kbd_OnMidiList(list, dev_index);
}

REAPER_PLUGIN_DLL_EXPORT void _kbd_ProcessActionsMenu(HMENU menu, KbdSectionInfo* section) {
  return kbd_ProcessActionsMenu(menu, section);
}

REAPER_PLUGIN_DLL_EXPORT bool _kbd_processMidiEventActionEx(MIDI_event_t* evt, KbdSectionInfo* section, HWND hwndCtx) {
  return kbd_processMidiEventActionEx(evt, section, hwndCtx);
}

REAPER_PLUGIN_DLL_EXPORT void _kbd_reprocessMenu(HMENU menu, KbdSectionInfo* section) {
  return kbd_reprocessMenu(menu, section);
}

REAPER_PLUGIN_DLL_EXPORT bool _kbd_RunCommandThroughHooks(KbdSectionInfo* section, int* actionCommandID, int* val, int* valhw, int* relmode, HWND hwnd) {
  return kbd_RunCommandThroughHooks(section, actionCommandID, val, valhw, relmode, hwnd);
}

REAPER_PLUGIN_DLL_EXPORT int _kbd_translateAccelerator(HWND hwnd, MSG* msg, KbdSectionInfo* section) {
  return kbd_translateAccelerator(hwnd, msg, section);
}

REAPER_PLUGIN_DLL_EXPORT bool _kbd_translateMouse(void* winmsg, unsigned char* midimsg) {
  return kbd_translateMouse(winmsg, midimsg);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE__Destroy(LICE_IBitmap* bm) {
  return LICE__Destroy(bm);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE__DestroyFont(LICE_IFont* font) {
  return LICE__DestroyFont(font);
}

REAPER_PLUGIN_DLL_EXPORT int _LICE__DrawText(LICE_IFont* font, LICE_IBitmap* bm, const char* str, int strcnt, RECT* rect, UINT dtFlags) {
  return LICE__DrawText(font, bm, str, strcnt, rect, dtFlags);
}

REAPER_PLUGIN_DLL_EXPORT void* _LICE__GetBits(LICE_IBitmap* bm) {
  return LICE__GetBits(bm);
}

REAPER_PLUGIN_DLL_EXPORT HDC _LICE__GetDC(LICE_IBitmap* bm) {
  return LICE__GetDC(bm);
}

REAPER_PLUGIN_DLL_EXPORT int _LICE__GetHeight(LICE_IBitmap* bm) {
  return LICE__GetHeight(bm);
}

REAPER_PLUGIN_DLL_EXPORT int _LICE__GetRowSpan(LICE_IBitmap* bm) {
  return LICE__GetRowSpan(bm);
}

REAPER_PLUGIN_DLL_EXPORT int _LICE__GetWidth(LICE_IBitmap* bm) {
  return LICE__GetWidth(bm);
}

REAPER_PLUGIN_DLL_EXPORT bool _LICE__IsFlipped(LICE_IBitmap* bm) {
  return LICE__IsFlipped(bm);
}

REAPER_PLUGIN_DLL_EXPORT bool _LICE__resize(LICE_IBitmap* bm, int w, int h) {
  return LICE__resize(bm, w, h);
}

REAPER_PLUGIN_DLL_EXPORT LICE_pixel _LICE__SetBkColor(LICE_IFont* font, LICE_pixel color) {
  return LICE__SetBkColor(font, color);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE__SetFromHFont(LICE_IFont* font, HFONT hfont, int flags) {
  return LICE__SetFromHFont(font, hfont, flags);
}

REAPER_PLUGIN_DLL_EXPORT LICE_pixel _LICE__SetTextColor(LICE_IFont* font, LICE_pixel color) {
  return LICE__SetTextColor(font, color);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE__SetTextCombineMode(LICE_IFont* ifont, int mode, float alpha) {
  return LICE__SetTextCombineMode(ifont, mode, alpha);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_Arc(LICE_IBitmap* dest, float cx, float cy, float r, float minAngle, float maxAngle, LICE_pixel color, float alpha, int mode, bool aa) {
  return LICE_Arc(dest, cx, cy, r, minAngle, maxAngle, color, alpha, mode, aa);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_Blit(LICE_IBitmap* dest, LICE_IBitmap* src, int dstx, int dsty, int srcx, int srcy, int srcw, int srch, float alpha, int mode) {
  return LICE_Blit(dest, src, dstx, dsty, srcx, srcy, srcw, srch, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_Blur(LICE_IBitmap* dest, LICE_IBitmap* src, int dstx, int dsty, int srcx, int srcy, int srcw, int srch) {
  return LICE_Blur(dest, src, dstx, dsty, srcx, srcy, srcw, srch);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_BorderedRect(LICE_IBitmap* dest, int x, int y, int w, int h, LICE_pixel bgcolor, LICE_pixel fgcolor, float alpha, int mode) {
  return LICE_BorderedRect(dest, x, y, w, h, bgcolor, fgcolor, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_Circle(LICE_IBitmap* dest, float cx, float cy, float r, LICE_pixel color, float alpha, int mode, bool aa) {
  return LICE_Circle(dest, cx, cy, r, color, alpha, mode, aa);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_Clear(LICE_IBitmap* dest, LICE_pixel color) {
  return LICE_Clear(dest, color);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_ClearRect(LICE_IBitmap* dest, int x, int y, int w, int h, LICE_pixel mask, LICE_pixel orbits) {
  return LICE_ClearRect(dest, x, y, w, h, mask, orbits);
}

REAPER_PLUGIN_DLL_EXPORT bool _LICE_ClipLine(int* pX1Out, int* pY1Out, int* pX2Out, int* pY2Out, int xLo, int yLo, int xHi, int yHi) {
  return LICE_ClipLine(pX1Out, pY1Out, pX2Out, pY2Out, xLo, yLo, xHi, yHi);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_Copy(LICE_IBitmap* dest, LICE_IBitmap* src) {
  return LICE_Copy(dest, src);
}

REAPER_PLUGIN_DLL_EXPORT LICE_IBitmap* _LICE_CreateBitmap(int mode, int w, int h) {
  return LICE_CreateBitmap(mode, w, h);
}

REAPER_PLUGIN_DLL_EXPORT LICE_IFont* _LICE_CreateFont() {
  return LICE_CreateFont();
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_DrawCBezier(LICE_IBitmap* dest, double xstart, double ystart, double xctl1, double yctl1, double xctl2, double yctl2, double xend, double yend, LICE_pixel color, float alpha, int mode, bool aa, double tol) {
  return LICE_DrawCBezier(dest, xstart, ystart, xctl1, yctl1, xctl2, yctl2, xend, yend, color, alpha, mode, aa, tol);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_DrawChar(LICE_IBitmap* bm, int x, int y, char c, LICE_pixel color, float alpha, int mode) {
  return LICE_DrawChar(bm, x, y, c, color, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_DrawGlyph(LICE_IBitmap* dest, int x, int y, LICE_pixel color, LICE_pixel_chan* alphas, int glyph_w, int glyph_h, float alpha, int mode) {
  return LICE_DrawGlyph(dest, x, y, color, alphas, glyph_w, glyph_h, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_DrawRect(LICE_IBitmap* dest, int x, int y, int w, int h, LICE_pixel color, float alpha, int mode) {
  return LICE_DrawRect(dest, x, y, w, h, color, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_DrawText(LICE_IBitmap* bm, int x, int y, const char* string, LICE_pixel color, float alpha, int mode) {
  return LICE_DrawText(bm, x, y, string, color, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_FillCBezier(LICE_IBitmap* dest, double xstart, double ystart, double xctl1, double yctl1, double xctl2, double yctl2, double xend, double yend, int yfill, LICE_pixel color, float alpha, int mode, bool aa, double tol) {
  return LICE_FillCBezier(dest, xstart, ystart, xctl1, yctl1, xctl2, yctl2, xend, yend, yfill, color, alpha, mode, aa, tol);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_FillCircle(LICE_IBitmap* dest, float cx, float cy, float r, LICE_pixel color, float alpha, int mode, bool aa) {
  return LICE_FillCircle(dest, cx, cy, r, color, alpha, mode, aa);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_FillConvexPolygon(LICE_IBitmap* dest, int* x, int* y, int npoints, LICE_pixel color, float alpha, int mode) {
  return LICE_FillConvexPolygon(dest, x, y, npoints, color, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_FillRect(LICE_IBitmap* dest, int x, int y, int w, int h, LICE_pixel color, float alpha, int mode) {
  return LICE_FillRect(dest, x, y, w, h, color, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_FillTrapezoid(LICE_IBitmap* dest, int x1a, int x1b, int y1, int x2a, int x2b, int y2, LICE_pixel color, float alpha, int mode) {
  return LICE_FillTrapezoid(dest, x1a, x1b, y1, x2a, x2b, y2, color, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_FillTriangle(LICE_IBitmap* dest, int x1, int y1, int x2, int y2, int x3, int y3, LICE_pixel color, float alpha, int mode) {
  return LICE_FillTriangle(dest, x1, y1, x2, y2, x3, y3, color, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT LICE_pixel _LICE_GetPixel(LICE_IBitmap* bm, int x, int y) {
  return LICE_GetPixel(bm, x, y);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_GradRect(LICE_IBitmap* dest, int dstx, int dsty, int dstw, int dsth, float ir, float ig, float ib, float ia, float drdx, float dgdx, float dbdx, float dadx, float drdy, float dgdy, float dbdy, float dady, int mode) {
  return LICE_GradRect(dest, dstx, dsty, dstw, dsth, ir, ig, ib, ia, drdx, dgdx, dbdx, dadx, drdy, dgdy, dbdy, dady, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_Line(LICE_IBitmap* dest, float x1, float y1, float x2, float y2, LICE_pixel color, float alpha, int mode, bool aa) {
  return LICE_Line(dest, x1, y1, x2, y2, color, alpha, mode, aa);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_LineInt(LICE_IBitmap* dest, int x1, int y1, int x2, int y2, LICE_pixel color, float alpha, int mode, bool aa) {
  return LICE_LineInt(dest, x1, y1, x2, y2, color, alpha, mode, aa);
}

REAPER_PLUGIN_DLL_EXPORT LICE_IBitmap* _LICE_LoadPNG(const char* filename, LICE_IBitmap* bmp) {
  return LICE_LoadPNG(filename, bmp);
}

REAPER_PLUGIN_DLL_EXPORT LICE_IBitmap* _LICE_LoadPNGFromResource(HINSTANCE hInst, const char* resid, LICE_IBitmap* bmp) {
  return LICE_LoadPNGFromResource(hInst, resid, bmp);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_MeasureText(const char* string, int* w, int* h) {
  return LICE_MeasureText(string, w, h);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_MultiplyAddRect(LICE_IBitmap* dest, int x, int y, int w, int h, float rsc, float gsc, float bsc, float asc, float radd, float gadd, float badd, float aadd) {
  return LICE_MultiplyAddRect(dest, x, y, w, h, rsc, gsc, bsc, asc, radd, gadd, badd, aadd);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_PutPixel(LICE_IBitmap* bm, int x, int y, LICE_pixel color, float alpha, int mode) {
  return LICE_PutPixel(bm, x, y, color, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_RotatedBlit(LICE_IBitmap* dest, LICE_IBitmap* src, int dstx, int dsty, int dstw, int dsth, float srcx, float srcy, float srcw, float srch, float angle, bool cliptosourcerect, float alpha, int mode, float rotxcent, float rotycent) {
  return LICE_RotatedBlit(dest, src, dstx, dsty, dstw, dsth, srcx, srcy, srcw, srch, angle, cliptosourcerect, alpha, mode, rotxcent, rotycent);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_RoundRect(LICE_IBitmap* drawbm, float xpos, float ypos, float w, float h, int cornerradius, LICE_pixel col, float alpha, int mode, bool aa) {
  return LICE_RoundRect(drawbm, xpos, ypos, w, h, cornerradius, col, alpha, mode, aa);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_ScaledBlit(LICE_IBitmap* dest, LICE_IBitmap* src, int dstx, int dsty, int dstw, int dsth, float srcx, float srcy, float srcw, float srch, float alpha, int mode) {
  return LICE_ScaledBlit(dest, src, dstx, dsty, dstw, dsth, srcx, srcy, srcw, srch, alpha, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _LICE_SimpleFill(LICE_IBitmap* dest, int x, int y, LICE_pixel newcolor, LICE_pixel comparemask, LICE_pixel keepmask) {
  return LICE_SimpleFill(dest, x, y, newcolor, comparemask, keepmask);
}

REAPER_PLUGIN_DLL_EXPORT const char* _LocalizeString(const char* src_string, const char* section, int flagsOptional) {
  return LocalizeString(src_string, section, flagsOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _Loop_OnArrow(ReaProject* project, int direction) {
  return Loop_OnArrow(project, direction);
}

REAPER_PLUGIN_DLL_EXPORT void _Main_OnCommand(int command, int flag) {
  return Main_OnCommand(command, flag);
}

REAPER_PLUGIN_DLL_EXPORT void _Main_OnCommandEx(int command, int flag, ReaProject* proj) {
  return Main_OnCommandEx(command, flag, proj);
}

REAPER_PLUGIN_DLL_EXPORT void _Main_openProject(const char* name) {
  return Main_openProject(name);
}

REAPER_PLUGIN_DLL_EXPORT void _Main_SaveProject(ReaProject* proj, bool forceSaveAsInOptional) {
  return Main_SaveProject(proj, forceSaveAsInOptional);
}

REAPER_PLUGIN_DLL_EXPORT void _Main_UpdateLoopInfo(int ignoremask) {
  return Main_UpdateLoopInfo(ignoremask);
}

REAPER_PLUGIN_DLL_EXPORT void _MarkProjectDirty(ReaProject* proj) {
  return MarkProjectDirty(proj);
}

REAPER_PLUGIN_DLL_EXPORT void _MarkTrackItemsDirty(MediaTrack* track, MediaItem* item) {
  return MarkTrackItemsDirty(track, item);
}

REAPER_PLUGIN_DLL_EXPORT double _Master_GetPlayRate(ReaProject* project) {
  return Master_GetPlayRate(project);
}

REAPER_PLUGIN_DLL_EXPORT double _Master_GetPlayRateAtTime(double time_s, ReaProject* proj) {
  return Master_GetPlayRateAtTime(time_s, proj);
}

REAPER_PLUGIN_DLL_EXPORT double _Master_GetTempo() {
  return Master_GetTempo();
}

REAPER_PLUGIN_DLL_EXPORT double _Master_NormalizePlayRate(double playrate, bool isnormalized) {
  return Master_NormalizePlayRate(playrate, isnormalized);
}

REAPER_PLUGIN_DLL_EXPORT double _Master_NormalizeTempo(double bpm, bool isnormalized) {
  return Master_NormalizeTempo(bpm, isnormalized);
}

REAPER_PLUGIN_DLL_EXPORT int _MB(const char* msg, const char* title, int type) {
  return MB(msg, title, type);
}

REAPER_PLUGIN_DLL_EXPORT int _MediaItemDescendsFromTrack(MediaItem* item, MediaTrack* track) {
  return MediaItemDescendsFromTrack(item, track);
}

REAPER_PLUGIN_DLL_EXPORT int _MIDI_CountEvts(MediaItem_Take* take, int* notecntOut, int* ccevtcntOut, int* textsyxevtcntOut) {
  return MIDI_CountEvts(take, notecntOut, ccevtcntOut, textsyxevtcntOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_DeleteCC(MediaItem_Take* take, int ccidx) {
  return MIDI_DeleteCC(take, ccidx);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_DeleteEvt(MediaItem_Take* take, int evtidx) {
  return MIDI_DeleteEvt(take, evtidx);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_DeleteNote(MediaItem_Take* take, int noteidx) {
  return MIDI_DeleteNote(take, noteidx);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_DeleteTextSysexEvt(MediaItem_Take* take, int textsyxevtidx) {
  return MIDI_DeleteTextSysexEvt(take, textsyxevtidx);
}

REAPER_PLUGIN_DLL_EXPORT void _MIDI_DisableSort(MediaItem_Take* take) {
  return MIDI_DisableSort(take);
}

REAPER_PLUGIN_DLL_EXPORT int _MIDI_EnumSelCC(MediaItem_Take* take, int ccidx) {
  return MIDI_EnumSelCC(take, ccidx);
}

REAPER_PLUGIN_DLL_EXPORT int _MIDI_EnumSelEvts(MediaItem_Take* take, int evtidx) {
  return MIDI_EnumSelEvts(take, evtidx);
}

REAPER_PLUGIN_DLL_EXPORT int _MIDI_EnumSelNotes(MediaItem_Take* take, int noteidx) {
  return MIDI_EnumSelNotes(take, noteidx);
}

REAPER_PLUGIN_DLL_EXPORT int _MIDI_EnumSelTextSysexEvts(MediaItem_Take* take, int textsyxidx) {
  return MIDI_EnumSelTextSysexEvts(take, textsyxidx);
}

REAPER_PLUGIN_DLL_EXPORT MIDI_eventlist* _MIDI_eventlist_Create() {
  return MIDI_eventlist_Create();
}

REAPER_PLUGIN_DLL_EXPORT void _MIDI_eventlist_Destroy(MIDI_eventlist* evtlist) {
  return MIDI_eventlist_Destroy(evtlist);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_GetAllEvts(MediaItem_Take* take, char* bufNeedBig, int* bufNeedBig_sz) {
  return MIDI_GetAllEvts(take, bufNeedBig, bufNeedBig_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_GetCC(MediaItem_Take* take, int ccidx, bool* selectedOut, bool* mutedOut, double* ppqposOut, int* chanmsgOut, int* chanOut, int* msg2Out, int* msg3Out) {
  return MIDI_GetCC(take, ccidx, selectedOut, mutedOut, ppqposOut, chanmsgOut, chanOut, msg2Out, msg3Out);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_GetCCShape(MediaItem_Take* take, int ccidx, int* shapeOut, double* beztensionOut) {
  return MIDI_GetCCShape(take, ccidx, shapeOut, beztensionOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_GetEvt(MediaItem_Take* take, int evtidx, bool* selectedOut, bool* mutedOut, double* ppqposOut, char* msg, int* msg_sz) {
  return MIDI_GetEvt(take, evtidx, selectedOut, mutedOut, ppqposOut, msg, msg_sz);
}

REAPER_PLUGIN_DLL_EXPORT double _MIDI_GetGrid(MediaItem_Take* take, double* swingOutOptional, double* noteLenOutOptional) {
  return MIDI_GetGrid(take, swingOutOptional, noteLenOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_GetHash(MediaItem_Take* take, bool notesonly, char* hash, int hash_sz) {
  return MIDI_GetHash(take, notesonly, hash, hash_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_GetNote(MediaItem_Take* take, int noteidx, bool* selectedOut, bool* mutedOut, double* startppqposOut, double* endppqposOut, int* chanOut, int* pitchOut, int* velOut) {
  return MIDI_GetNote(take, noteidx, selectedOut, mutedOut, startppqposOut, endppqposOut, chanOut, pitchOut, velOut);
}

REAPER_PLUGIN_DLL_EXPORT double _MIDI_GetPPQPos_EndOfMeasure(MediaItem_Take* take, double ppqpos) {
  return MIDI_GetPPQPos_EndOfMeasure(take, ppqpos);
}

REAPER_PLUGIN_DLL_EXPORT double _MIDI_GetPPQPos_StartOfMeasure(MediaItem_Take* take, double ppqpos) {
  return MIDI_GetPPQPos_StartOfMeasure(take, ppqpos);
}

REAPER_PLUGIN_DLL_EXPORT double _MIDI_GetPPQPosFromProjQN(MediaItem_Take* take, double projqn) {
  return MIDI_GetPPQPosFromProjQN(take, projqn);
}

REAPER_PLUGIN_DLL_EXPORT double _MIDI_GetPPQPosFromProjTime(MediaItem_Take* take, double projtime) {
  return MIDI_GetPPQPosFromProjTime(take, projtime);
}

REAPER_PLUGIN_DLL_EXPORT double _MIDI_GetProjQNFromPPQPos(MediaItem_Take* take, double ppqpos) {
  return MIDI_GetProjQNFromPPQPos(take, ppqpos);
}

REAPER_PLUGIN_DLL_EXPORT double _MIDI_GetProjTimeFromPPQPos(MediaItem_Take* take, double ppqpos) {
  return MIDI_GetProjTimeFromPPQPos(take, ppqpos);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_GetScale(MediaItem_Take* take, int* rootOut, int* scaleOut, char* name, int name_sz) {
  return MIDI_GetScale(take, rootOut, scaleOut, name, name_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_GetTextSysexEvt(MediaItem_Take* take, int textsyxevtidx, bool* selectedOutOptional, bool* mutedOutOptional, double* ppqposOutOptional, int* typeOutOptional, char* msgOptional, int* msgOptional_sz) {
  return MIDI_GetTextSysexEvt(take, textsyxevtidx, selectedOutOptional, mutedOutOptional, ppqposOutOptional, typeOutOptional, msgOptional, msgOptional_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_GetTrackHash(MediaTrack* track, bool notesonly, char* hash, int hash_sz) {
  return MIDI_GetTrackHash(track, notesonly, hash, hash_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_InsertCC(MediaItem_Take* take, bool selected, bool muted, double ppqpos, int chanmsg, int chan, int msg2, int msg3) {
  return MIDI_InsertCC(take, selected, muted, ppqpos, chanmsg, chan, msg2, msg3);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_InsertEvt(MediaItem_Take* take, bool selected, bool muted, double ppqpos, const char* bytestr, int bytestr_sz) {
  return MIDI_InsertEvt(take, selected, muted, ppqpos, bytestr, bytestr_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_InsertNote(MediaItem_Take* take, bool selected, bool muted, double startppqpos, double endppqpos, int chan, int pitch, int vel, const bool* noSortInOptional) {
  return MIDI_InsertNote(take, selected, muted, startppqpos, endppqpos, chan, pitch, vel, noSortInOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_InsertTextSysexEvt(MediaItem_Take* take, bool selected, bool muted, double ppqpos, int type, const char* bytestr, int bytestr_sz) {
  return MIDI_InsertTextSysexEvt(take, selected, muted, ppqpos, type, bytestr, bytestr_sz);
}

REAPER_PLUGIN_DLL_EXPORT void _midi_reinit() {
  return midi_reinit();
}

REAPER_PLUGIN_DLL_EXPORT void _MIDI_SelectAll(MediaItem_Take* take, bool select) {
  return MIDI_SelectAll(take, select);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_SetAllEvts(MediaItem_Take* take, const char* buf, int buf_sz) {
  return MIDI_SetAllEvts(take, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_SetCC(MediaItem_Take* take, int ccidx, const bool* selectedInOptional, const bool* mutedInOptional, const double* ppqposInOptional, const int* chanmsgInOptional, const int* chanInOptional, const int* msg2InOptional, const int* msg3InOptional, const bool* noSortInOptional) {
  return MIDI_SetCC(take, ccidx, selectedInOptional, mutedInOptional, ppqposInOptional, chanmsgInOptional, chanInOptional, msg2InOptional, msg3InOptional, noSortInOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_SetCCShape(MediaItem_Take* take, int ccidx, int shape, double beztension, const bool* noSortInOptional) {
  return MIDI_SetCCShape(take, ccidx, shape, beztension, noSortInOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_SetEvt(MediaItem_Take* take, int evtidx, const bool* selectedInOptional, const bool* mutedInOptional, const double* ppqposInOptional, const char* msgOptional, int msgOptional_sz, const bool* noSortInOptional) {
  return MIDI_SetEvt(take, evtidx, selectedInOptional, mutedInOptional, ppqposInOptional, msgOptional, msgOptional_sz, noSortInOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_SetItemExtents(MediaItem* item, double startQN, double endQN) {
  return MIDI_SetItemExtents(item, startQN, endQN);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_SetNote(MediaItem_Take* take, int noteidx, const bool* selectedInOptional, const bool* mutedInOptional, const double* startppqposInOptional, const double* endppqposInOptional, const int* chanInOptional, const int* pitchInOptional, const int* velInOptional, const bool* noSortInOptional) {
  return MIDI_SetNote(take, noteidx, selectedInOptional, mutedInOptional, startppqposInOptional, endppqposInOptional, chanInOptional, pitchInOptional, velInOptional, noSortInOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDI_SetTextSysexEvt(MediaItem_Take* take, int textsyxevtidx, const bool* selectedInOptional, const bool* mutedInOptional, const double* ppqposInOptional, const int* typeInOptional, const char* msgOptional, int msgOptional_sz, const bool* noSortInOptional) {
  return MIDI_SetTextSysexEvt(take, textsyxevtidx, selectedInOptional, mutedInOptional, ppqposInOptional, typeInOptional, msgOptional, msgOptional_sz, noSortInOptional);
}

REAPER_PLUGIN_DLL_EXPORT void _MIDI_Sort(MediaItem_Take* take) {
  return MIDI_Sort(take);
}

REAPER_PLUGIN_DLL_EXPORT HWND _MIDIEditor_GetActive() {
  return MIDIEditor_GetActive();
}

REAPER_PLUGIN_DLL_EXPORT int _MIDIEditor_GetMode(HWND midieditor) {
  return MIDIEditor_GetMode(midieditor);
}

REAPER_PLUGIN_DLL_EXPORT int _MIDIEditor_GetSetting_int(HWND midieditor, const char* setting_desc) {
  return MIDIEditor_GetSetting_int(midieditor, setting_desc);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDIEditor_GetSetting_str(HWND midieditor, const char* setting_desc, char* buf, int buf_sz) {
  return MIDIEditor_GetSetting_str(midieditor, setting_desc, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT MediaItem_Take* _MIDIEditor_GetTake(HWND midieditor) {
  return MIDIEditor_GetTake(midieditor);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDIEditor_LastFocused_OnCommand(int command_id, bool islistviewcommand) {
  return MIDIEditor_LastFocused_OnCommand(command_id, islistviewcommand);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDIEditor_OnCommand(HWND midieditor, int command_id) {
  return MIDIEditor_OnCommand(midieditor, command_id);
}

REAPER_PLUGIN_DLL_EXPORT bool _MIDIEditor_SetSetting_int(HWND midieditor, const char* setting_desc, int setting) {
  return MIDIEditor_SetSetting_int(midieditor, setting_desc, setting);
}

REAPER_PLUGIN_DLL_EXPORT void _mkpanstr(char* strNeed64, double pan) {
  return mkpanstr(strNeed64, pan);
}

REAPER_PLUGIN_DLL_EXPORT void _mkvolpanstr(char* strNeed64, double vol, double pan) {
  return mkvolpanstr(strNeed64, vol, pan);
}

REAPER_PLUGIN_DLL_EXPORT void _mkvolstr(char* strNeed64, double vol) {
  return mkvolstr(strNeed64, vol);
}

REAPER_PLUGIN_DLL_EXPORT void _MoveEditCursor(double adjamt, bool dosel) {
  return MoveEditCursor(adjamt, dosel);
}

REAPER_PLUGIN_DLL_EXPORT bool _MoveMediaItemToTrack(MediaItem* item, MediaTrack* desttr) {
  return MoveMediaItemToTrack(item, desttr);
}

REAPER_PLUGIN_DLL_EXPORT void _MuteAllTracks(bool mute) {
  return MuteAllTracks(mute);
}

REAPER_PLUGIN_DLL_EXPORT void _my_getViewport(RECT* r, const RECT* sr, bool wantWorkArea) {
  return my_getViewport(r, sr, wantWorkArea);
}

REAPER_PLUGIN_DLL_EXPORT int _NamedCommandLookup(const char* command_name) {
  return NamedCommandLookup(command_name);
}

REAPER_PLUGIN_DLL_EXPORT void _OnPauseButton() {
  return OnPauseButton();
}

REAPER_PLUGIN_DLL_EXPORT void _OnPauseButtonEx(ReaProject* proj) {
  return OnPauseButtonEx(proj);
}

REAPER_PLUGIN_DLL_EXPORT void _OnPlayButton() {
  return OnPlayButton();
}

REAPER_PLUGIN_DLL_EXPORT void _OnPlayButtonEx(ReaProject* proj) {
  return OnPlayButtonEx(proj);
}

REAPER_PLUGIN_DLL_EXPORT void _OnStopButton() {
  return OnStopButton();
}

REAPER_PLUGIN_DLL_EXPORT void _OnStopButtonEx(ReaProject* proj) {
  return OnStopButtonEx(proj);
}

REAPER_PLUGIN_DLL_EXPORT bool _OpenColorThemeFile(const char* fn) {
  return OpenColorThemeFile(fn);
}

REAPER_PLUGIN_DLL_EXPORT HWND _OpenMediaExplorer(const char* mediafn, bool play) {
  return OpenMediaExplorer(mediafn, play);
}

REAPER_PLUGIN_DLL_EXPORT void _OscLocalMessageToHost(const char* message, const double* valueInOptional) {
  return OscLocalMessageToHost(message, valueInOptional);
}

REAPER_PLUGIN_DLL_EXPORT double _parse_timestr(const char* buf) {
  return parse_timestr(buf);
}

REAPER_PLUGIN_DLL_EXPORT double _parse_timestr_len(const char* buf, double offset, int modeoverride) {
  return parse_timestr_len(buf, offset, modeoverride);
}

REAPER_PLUGIN_DLL_EXPORT double _parse_timestr_pos(const char* buf, int modeoverride) {
  return parse_timestr_pos(buf, modeoverride);
}

REAPER_PLUGIN_DLL_EXPORT double _parsepanstr(const char* str) {
  return parsepanstr(str);
}

REAPER_PLUGIN_DLL_EXPORT PCM_sink* _PCM_Sink_Create(const char* filename, const char* cfg, int cfg_sz, int nch, int srate, bool buildpeaks) {
  return PCM_Sink_Create(filename, cfg, cfg_sz, nch, srate, buildpeaks);
}

REAPER_PLUGIN_DLL_EXPORT PCM_sink* _PCM_Sink_CreateEx(ReaProject* proj, const char* filename, const char* cfg, int cfg_sz, int nch, int srate, bool buildpeaks) {
  return PCM_Sink_CreateEx(proj, filename, cfg, cfg_sz, nch, srate, buildpeaks);
}

REAPER_PLUGIN_DLL_EXPORT PCM_sink* _PCM_Sink_CreateMIDIFile(const char* filename, const char* cfg, int cfg_sz, double bpm, int div) {
  return PCM_Sink_CreateMIDIFile(filename, cfg, cfg_sz, bpm, div);
}

REAPER_PLUGIN_DLL_EXPORT PCM_sink* _PCM_Sink_CreateMIDIFileEx(ReaProject* proj, const char* filename, const char* cfg, int cfg_sz, double bpm, int div) {
  return PCM_Sink_CreateMIDIFileEx(proj, filename, cfg, cfg_sz, bpm, div);
}

REAPER_PLUGIN_DLL_EXPORT unsigned int _PCM_Sink_Enum(int idx, const char** descstrOut) {
  return PCM_Sink_Enum(idx, descstrOut);
}

REAPER_PLUGIN_DLL_EXPORT const char* _PCM_Sink_GetExtension(const char* data, int data_sz) {
  return PCM_Sink_GetExtension(data, data_sz);
}

REAPER_PLUGIN_DLL_EXPORT HWND _PCM_Sink_ShowConfig(const char* cfg, int cfg_sz, HWND hwndParent) {
  return PCM_Sink_ShowConfig(cfg, cfg_sz, hwndParent);
}

REAPER_PLUGIN_DLL_EXPORT PCM_source* _PCM_Source_CreateFromFile(const char* filename) {
  return PCM_Source_CreateFromFile(filename);
}

REAPER_PLUGIN_DLL_EXPORT PCM_source* _PCM_Source_CreateFromFileEx(const char* filename, bool forcenoMidiImp) {
  return PCM_Source_CreateFromFileEx(filename, forcenoMidiImp);
}

REAPER_PLUGIN_DLL_EXPORT PCM_source* _PCM_Source_CreateFromSimple(ISimpleMediaDecoder* dec, const char* fn) {
  return PCM_Source_CreateFromSimple(dec, fn);
}

REAPER_PLUGIN_DLL_EXPORT PCM_source* _PCM_Source_CreateFromType(const char* sourcetype) {
  return PCM_Source_CreateFromType(sourcetype);
}

REAPER_PLUGIN_DLL_EXPORT void _PCM_Source_Destroy(PCM_source* src) {
  return PCM_Source_Destroy(src);
}

REAPER_PLUGIN_DLL_EXPORT int _PCM_Source_GetPeaks(PCM_source* src, double peakrate, double starttime, int numchannels, int numsamplesperchannel, int want_extra_type, double* buf) {
  return PCM_Source_GetPeaks(src, peakrate, starttime, numchannels, numsamplesperchannel, want_extra_type, buf);
}

REAPER_PLUGIN_DLL_EXPORT bool _PCM_Source_GetSectionInfo(PCM_source* src, double* offsOut, double* lenOut, bool* revOut) {
  return PCM_Source_GetSectionInfo(src, offsOut, lenOut, revOut);
}

REAPER_PLUGIN_DLL_EXPORT REAPER_PeakBuild_Interface* _PeakBuild_Create(PCM_source* src, const char* fn, int srate, int nch) {
  return PeakBuild_Create(src, fn, srate, nch);
}

REAPER_PLUGIN_DLL_EXPORT REAPER_PeakBuild_Interface* _PeakBuild_CreateEx(PCM_source* src, const char* fn, int srate, int nch, int flags) {
  return PeakBuild_CreateEx(src, fn, srate, nch, flags);
}

REAPER_PLUGIN_DLL_EXPORT REAPER_PeakGet_Interface* _PeakGet_Create(const char* fn, int srate, int nch) {
  return PeakGet_Create(fn, srate, nch);
}

REAPER_PLUGIN_DLL_EXPORT int _PitchShiftSubModeMenu(HWND hwnd, int x, int y, int mode, int submode_sel) {
  return PitchShiftSubModeMenu(hwnd, x, y, mode, submode_sel);
}

REAPER_PLUGIN_DLL_EXPORT int _PlayPreview(preview_register_t* preview) {
  return PlayPreview(preview);
}

REAPER_PLUGIN_DLL_EXPORT int _PlayPreviewEx(preview_register_t* preview, int bufflags, double measure_align) {
  return PlayPreviewEx(preview, bufflags, measure_align);
}

REAPER_PLUGIN_DLL_EXPORT int _PlayTrackPreview(preview_register_t* preview) {
  return PlayTrackPreview(preview);
}

REAPER_PLUGIN_DLL_EXPORT int _PlayTrackPreview2(ReaProject* proj, preview_register_t* preview) {
  return PlayTrackPreview2(proj, preview);
}

REAPER_PLUGIN_DLL_EXPORT int _PlayTrackPreview2Ex(ReaProject* proj, preview_register_t* preview, int flags, double measure_align) {
  return PlayTrackPreview2Ex(proj, preview, flags, measure_align);
}

REAPER_PLUGIN_DLL_EXPORT void* _plugin_getapi(const char* name) {
  return plugin_getapi(name);
}

REAPER_PLUGIN_DLL_EXPORT const char* _plugin_getFilterList() {
  return plugin_getFilterList();
}

REAPER_PLUGIN_DLL_EXPORT const char* _plugin_getImportableProjectFilterList() {
  return plugin_getImportableProjectFilterList();
}

REAPER_PLUGIN_DLL_EXPORT int _plugin_register(const char* name, void* infostruct) {
  return plugin_register(name, infostruct);
}

REAPER_PLUGIN_DLL_EXPORT void _PluginWantsAlwaysRunFx(int amt) {
  return PluginWantsAlwaysRunFx(amt);
}

REAPER_PLUGIN_DLL_EXPORT void _PreventUIRefresh(int prevent_count) {
  return PreventUIRefresh(prevent_count);
}

REAPER_PLUGIN_DLL_EXPORT void* _projectconfig_var_addr(ReaProject* proj, int idx) {
  return projectconfig_var_addr(proj, idx);
}

REAPER_PLUGIN_DLL_EXPORT int _projectconfig_var_getoffs(const char* name, int* szOut) {
  return projectconfig_var_getoffs(name, szOut);
}

REAPER_PLUGIN_DLL_EXPORT int _PromptForAction(int session_mode, int init_id, int section_id) {
  return PromptForAction(session_mode, init_id, section_id);
}

REAPER_PLUGIN_DLL_EXPORT bool _realloc_cmd_ptr(char** ptr, int* ptr_size, int new_size) {
  return realloc_cmd_ptr(ptr, ptr_size, new_size);
}

REAPER_PLUGIN_DLL_EXPORT IReaperPitchShift* _ReaperGetPitchShiftAPI(int version) {
  return ReaperGetPitchShiftAPI(version);
}

REAPER_PLUGIN_DLL_EXPORT void _ReaScriptError(const char* errmsg) {
  return ReaScriptError(errmsg);
}

REAPER_PLUGIN_DLL_EXPORT int _RecursiveCreateDirectory(const char* path, size_t ignored) {
  return RecursiveCreateDirectory(path, ignored);
}

REAPER_PLUGIN_DLL_EXPORT int _reduce_open_files(int flags) {
  return reduce_open_files(flags);
}

REAPER_PLUGIN_DLL_EXPORT void _RefreshToolbar(int command_id) {
  return RefreshToolbar(command_id);
}

REAPER_PLUGIN_DLL_EXPORT void _RefreshToolbar2(int section_id, int command_id) {
  return RefreshToolbar2(section_id, command_id);
}

REAPER_PLUGIN_DLL_EXPORT void _relative_fn(const char* in, char* out, int out_sz) {
  return relative_fn(in, out, out_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _RemoveTrackSend(MediaTrack* tr, int category, int sendidx) {
  return RemoveTrackSend(tr, category, sendidx);
}

REAPER_PLUGIN_DLL_EXPORT bool _RenderFileSection(const char* source_filename, const char* target_filename, double start_percent, double end_percent, double playrate) {
  return RenderFileSection(source_filename, target_filename, start_percent, end_percent, playrate);
}

REAPER_PLUGIN_DLL_EXPORT bool _ReorderSelectedTracks(int beforeTrackIdx, int makePrevFolder) {
  return ReorderSelectedTracks(beforeTrackIdx, makePrevFolder);
}

REAPER_PLUGIN_DLL_EXPORT const char* _Resample_EnumModes(int mode) {
  return Resample_EnumModes(mode);
}

REAPER_PLUGIN_DLL_EXPORT REAPER_Resample_Interface* _Resampler_Create() {
  return Resampler_Create();
}

REAPER_PLUGIN_DLL_EXPORT void _resolve_fn(const char* in, char* out, int out_sz) {
  return resolve_fn(in, out, out_sz);
}

REAPER_PLUGIN_DLL_EXPORT void _resolve_fn2(const char* in, char* out, int out_sz, const char* checkSubDirOptional) {
  return resolve_fn2(in, out, out_sz, checkSubDirOptional);
}

REAPER_PLUGIN_DLL_EXPORT const char* _ReverseNamedCommandLookup(int command_id) {
  return ReverseNamedCommandLookup(command_id);
}

REAPER_PLUGIN_DLL_EXPORT double _ScaleFromEnvelopeMode(int scaling_mode, double val) {
  return ScaleFromEnvelopeMode(scaling_mode, val);
}

REAPER_PLUGIN_DLL_EXPORT double _ScaleToEnvelopeMode(int scaling_mode, double val) {
  return ScaleToEnvelopeMode(scaling_mode, val);
}

REAPER_PLUGIN_DLL_EXPORT void _screenset_register(char* id, void* callbackFunc, void* param) {
  return screenset_register(id, callbackFunc, param);
}

REAPER_PLUGIN_DLL_EXPORT void _screenset_registerNew(char* id, screensetNewCallbackFunc callbackFunc, void* param) {
  return screenset_registerNew(id, callbackFunc, param);
}

REAPER_PLUGIN_DLL_EXPORT void _screenset_unregister(char* id) {
  return screenset_unregister(id);
}

REAPER_PLUGIN_DLL_EXPORT void _screenset_unregisterByParam(void* param) {
  return screenset_unregisterByParam(param);
}

REAPER_PLUGIN_DLL_EXPORT void _screenset_updateLastFocus(HWND prevWin) {
  return screenset_updateLastFocus(prevWin);
}

REAPER_PLUGIN_DLL_EXPORT KbdSectionInfo* _SectionFromUniqueID(int uniqueID) {
  return SectionFromUniqueID(uniqueID);
}

REAPER_PLUGIN_DLL_EXPORT void _SelectAllMediaItems(ReaProject* proj, bool selected) {
  return SelectAllMediaItems(proj, selected);
}

REAPER_PLUGIN_DLL_EXPORT void _SelectProjectInstance(ReaProject* proj) {
  return SelectProjectInstance(proj);
}

REAPER_PLUGIN_DLL_EXPORT void _SendLocalOscMessage(void* local_osc_handler, const char* msg, int msglen) {
  return SendLocalOscMessage(local_osc_handler, msg, msglen);
}

REAPER_PLUGIN_DLL_EXPORT void _SetActiveTake(MediaItem_Take* take) {
  return SetActiveTake(take);
}

REAPER_PLUGIN_DLL_EXPORT void _SetAutomationMode(int mode, bool onlySel) {
  return SetAutomationMode(mode, onlySel);
}

REAPER_PLUGIN_DLL_EXPORT void _SetCurrentBPM(ReaProject* __proj, double bpm, bool wantUndo) {
  return SetCurrentBPM(__proj, bpm, wantUndo);
}

REAPER_PLUGIN_DLL_EXPORT void _SetCursorContext(int mode, TrackEnvelope* envInOptional) {
  return SetCursorContext(mode, envInOptional);
}

REAPER_PLUGIN_DLL_EXPORT void _SetEditCurPos(double time, bool moveview, bool seekplay) {
  return SetEditCurPos(time, moveview, seekplay);
}

REAPER_PLUGIN_DLL_EXPORT void _SetEditCurPos2(ReaProject* proj, double time, bool moveview, bool seekplay) {
  return SetEditCurPos2(proj, time, moveview, seekplay);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetEnvelopePoint(TrackEnvelope* envelope, int ptidx, double* timeInOptional, double* valueInOptional, int* shapeInOptional, double* tensionInOptional, bool* selectedInOptional, bool* noSortInOptional) {
  return SetEnvelopePoint(envelope, ptidx, timeInOptional, valueInOptional, shapeInOptional, tensionInOptional, selectedInOptional, noSortInOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetEnvelopePointEx(TrackEnvelope* envelope, int autoitem_idx, int ptidx, double* timeInOptional, double* valueInOptional, int* shapeInOptional, double* tensionInOptional, bool* selectedInOptional, bool* noSortInOptional) {
  return SetEnvelopePointEx(envelope, autoitem_idx, ptidx, timeInOptional, valueInOptional, shapeInOptional, tensionInOptional, selectedInOptional, noSortInOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetEnvelopeStateChunk(TrackEnvelope* env, const char* str, bool isundoOptional) {
  return SetEnvelopeStateChunk(env, str, isundoOptional);
}

REAPER_PLUGIN_DLL_EXPORT void _SetExtState(const char* section, const char* key, const char* value, bool persist) {
  return SetExtState(section, key, value, persist);
}

REAPER_PLUGIN_DLL_EXPORT void _SetGlobalAutomationOverride(int mode) {
  return SetGlobalAutomationOverride(mode);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetItemStateChunk(MediaItem* item, const char* str, bool isundoOptional) {
  return SetItemStateChunk(item, str, isundoOptional);
}

REAPER_PLUGIN_DLL_EXPORT int _SetMasterTrackVisibility(int flag) {
  return SetMasterTrackVisibility(flag);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetMediaItemInfo_Value(MediaItem* item, const char* parmname, double newvalue) {
  return SetMediaItemInfo_Value(item, parmname, newvalue);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetMediaItemLength(MediaItem* item, double length, bool refreshUI) {
  return SetMediaItemLength(item, length, refreshUI);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetMediaItemPosition(MediaItem* item, double position, bool refreshUI) {
  return SetMediaItemPosition(item, position, refreshUI);
}

REAPER_PLUGIN_DLL_EXPORT void _SetMediaItemSelected(MediaItem* item, bool selected) {
  return SetMediaItemSelected(item, selected);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetMediaItemTake_Source(MediaItem_Take* take, PCM_source* source) {
  return SetMediaItemTake_Source(take, source);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetMediaItemTakeInfo_Value(MediaItem_Take* take, const char* parmname, double newvalue) {
  return SetMediaItemTakeInfo_Value(take, parmname, newvalue);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetMediaTrackInfo_Value(MediaTrack* tr, const char* parmname, double newvalue) {
  return SetMediaTrackInfo_Value(tr, parmname, newvalue);
}

REAPER_PLUGIN_DLL_EXPORT void _SetMIDIEditorGrid(ReaProject* project, double division) {
  return SetMIDIEditorGrid(project, division);
}

REAPER_PLUGIN_DLL_EXPORT MediaTrack* _SetMixerScroll(MediaTrack* leftmosttrack) {
  return SetMixerScroll(leftmosttrack);
}

REAPER_PLUGIN_DLL_EXPORT void _SetMouseModifier(const char* context, int modifier_flag, const char* action) {
  return SetMouseModifier(context, modifier_flag, action);
}

REAPER_PLUGIN_DLL_EXPORT void _SetOnlyTrackSelected(MediaTrack* track) {
  return SetOnlyTrackSelected(track);
}

REAPER_PLUGIN_DLL_EXPORT void _SetProjectGrid(ReaProject* project, double division) {
  return SetProjectGrid(project, division);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetProjectMarker(int markrgnindexnumber, bool isrgn, double pos, double rgnend, const char* name) {
  return SetProjectMarker(markrgnindexnumber, isrgn, pos, rgnend, name);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetProjectMarker2(ReaProject* proj, int markrgnindexnumber, bool isrgn, double pos, double rgnend, const char* name) {
  return SetProjectMarker2(proj, markrgnindexnumber, isrgn, pos, rgnend, name);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetProjectMarker3(ReaProject* proj, int markrgnindexnumber, bool isrgn, double pos, double rgnend, const char* name, int color) {
  return SetProjectMarker3(proj, markrgnindexnumber, isrgn, pos, rgnend, name, color);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetProjectMarker4(ReaProject* proj, int markrgnindexnumber, bool isrgn, double pos, double rgnend, const char* name, int color, int flags) {
  return SetProjectMarker4(proj, markrgnindexnumber, isrgn, pos, rgnend, name, color, flags);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetProjectMarkerByIndex(ReaProject* proj, int markrgnidx, bool isrgn, double pos, double rgnend, int IDnumber, const char* name, int color) {
  return SetProjectMarkerByIndex(proj, markrgnidx, isrgn, pos, rgnend, IDnumber, name, color);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetProjectMarkerByIndex2(ReaProject* proj, int markrgnidx, bool isrgn, double pos, double rgnend, int IDnumber, const char* name, int color, int flags) {
  return SetProjectMarkerByIndex2(proj, markrgnidx, isrgn, pos, rgnend, IDnumber, name, color, flags);
}

REAPER_PLUGIN_DLL_EXPORT int _SetProjExtState(ReaProject* proj, const char* extname, const char* key, const char* value) {
  return SetProjExtState(proj, extname, key, value);
}

REAPER_PLUGIN_DLL_EXPORT void _SetRegionRenderMatrix(ReaProject* proj, int regionindex, MediaTrack* track, int addorremove) {
  return SetRegionRenderMatrix(proj, regionindex, track, addorremove);
}

REAPER_PLUGIN_DLL_EXPORT void _SetRenderLastError(const char* errorstr) {
  return SetRenderLastError(errorstr);
}

REAPER_PLUGIN_DLL_EXPORT int _SetTakeMarker(MediaItem_Take* take, int idx, const char* nameIn, double* srcposInOptional, int* colorInOptional) {
  return SetTakeMarker(take, idx, nameIn, srcposInOptional, colorInOptional);
}

REAPER_PLUGIN_DLL_EXPORT int _SetTakeStretchMarker(MediaItem_Take* take, int idx, double pos, const double* srcposInOptional) {
  return SetTakeStretchMarker(take, idx, pos, srcposInOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetTakeStretchMarkerSlope(MediaItem_Take* take, int idx, double slope) {
  return SetTakeStretchMarkerSlope(take, idx, slope);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetTempoTimeSigMarker(ReaProject* proj, int ptidx, double timepos, int measurepos, double beatpos, double bpm, int timesig_num, int timesig_denom, bool lineartempo) {
  return SetTempoTimeSigMarker(proj, ptidx, timepos, measurepos, beatpos, bpm, timesig_num, timesig_denom, lineartempo);
}

REAPER_PLUGIN_DLL_EXPORT int _SetThemeColor(const char* ini_key, int color, int flagsOptional) {
  return SetThemeColor(ini_key, color, flagsOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetToggleCommandState(int section_id, int command_id, int state) {
  return SetToggleCommandState(section_id, command_id, state);
}

REAPER_PLUGIN_DLL_EXPORT void _SetTrackAutomationMode(MediaTrack* tr, int mode) {
  return SetTrackAutomationMode(tr, mode);
}

REAPER_PLUGIN_DLL_EXPORT void _SetTrackColor(MediaTrack* track, int color) {
  return SetTrackColor(track, color);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetTrackMIDILyrics(MediaTrack* track, int flag, const char* str) {
  return SetTrackMIDILyrics(track, flag, str);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetTrackMIDINoteName(int track, int pitch, int chan, const char* name) {
  return SetTrackMIDINoteName(track, pitch, chan, name);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetTrackMIDINoteNameEx(ReaProject* proj, MediaTrack* track, int pitch, int chan, const char* name) {
  return SetTrackMIDINoteNameEx(proj, track, pitch, chan, name);
}

REAPER_PLUGIN_DLL_EXPORT void _SetTrackSelected(MediaTrack* track, bool selected) {
  return SetTrackSelected(track, selected);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetTrackSendInfo_Value(MediaTrack* tr, int category, int sendidx, const char* parmname, double newvalue) {
  return SetTrackSendInfo_Value(tr, category, sendidx, parmname, newvalue);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetTrackSendUIPan(MediaTrack* track, int send_idx, double pan, int isend) {
  return SetTrackSendUIPan(track, send_idx, pan, isend);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetTrackSendUIVol(MediaTrack* track, int send_idx, double vol, int isend) {
  return SetTrackSendUIVol(track, send_idx, vol, isend);
}

REAPER_PLUGIN_DLL_EXPORT bool _SetTrackStateChunk(MediaTrack* track, const char* str, bool isundoOptional) {
  return SetTrackStateChunk(track, str, isundoOptional);
}

REAPER_PLUGIN_DLL_EXPORT void _ShowActionList(KbdSectionInfo* caller, HWND callerWnd) {
  return ShowActionList(caller, callerWnd);
}

REAPER_PLUGIN_DLL_EXPORT void _ShowConsoleMsg(const char* msg) {
  return ShowConsoleMsg(msg);
}

REAPER_PLUGIN_DLL_EXPORT int _ShowMessageBox(const char* msg, const char* title, int type) {
  return ShowMessageBox(msg, title, type);
}

REAPER_PLUGIN_DLL_EXPORT void _ShowPopupMenu(const char* name, int x, int y, HWND hwndParentOptional, void* ctxOptional, int ctx2Optional, int ctx3Optional) {
  return ShowPopupMenu(name, x, y, hwndParentOptional, ctxOptional, ctx2Optional, ctx3Optional);
}

REAPER_PLUGIN_DLL_EXPORT double _SLIDER2DB(double y) {
  return SLIDER2DB(y);
}

REAPER_PLUGIN_DLL_EXPORT double _SnapToGrid(ReaProject* project, double time_pos) {
  return SnapToGrid(project, time_pos);
}

REAPER_PLUGIN_DLL_EXPORT void _SoloAllTracks(int solo) {
  return SoloAllTracks(solo);
}

REAPER_PLUGIN_DLL_EXPORT HWND _Splash_GetWnd() {
  return Splash_GetWnd();
}

REAPER_PLUGIN_DLL_EXPORT MediaItem* _SplitMediaItem(MediaItem* item, double position) {
  return SplitMediaItem(item, position);
}

REAPER_PLUGIN_DLL_EXPORT int _StopPreview(preview_register_t* preview) {
  return StopPreview(preview);
}

REAPER_PLUGIN_DLL_EXPORT int _StopTrackPreview(preview_register_t* preview) {
  return StopTrackPreview(preview);
}

REAPER_PLUGIN_DLL_EXPORT int _StopTrackPreview2(void* proj, preview_register_t* preview) {
  return StopTrackPreview2(proj, preview);
}

REAPER_PLUGIN_DLL_EXPORT void _stringToGuid(const char* str, GUID* g) {
  return stringToGuid(str, g);
}

REAPER_PLUGIN_DLL_EXPORT void _StuffMIDIMessage(int mode, int msg1, int msg2, int msg3) {
  return StuffMIDIMessage(mode, msg1, msg2, msg3);
}

REAPER_PLUGIN_DLL_EXPORT int _TakeFX_AddByName(MediaItem_Take* take, const char* fxname, int instantiate) {
  return TakeFX_AddByName(take, fxname, instantiate);
}

REAPER_PLUGIN_DLL_EXPORT void _TakeFX_CopyToTake(MediaItem_Take* src_take, int src_fx, MediaItem_Take* dest_take, int dest_fx, bool is_move) {
  return TakeFX_CopyToTake(src_take, src_fx, dest_take, dest_fx, is_move);
}

REAPER_PLUGIN_DLL_EXPORT void _TakeFX_CopyToTrack(MediaItem_Take* src_take, int src_fx, MediaTrack* dest_track, int dest_fx, bool is_move) {
  return TakeFX_CopyToTrack(src_take, src_fx, dest_track, dest_fx, is_move);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_Delete(MediaItem_Take* take, int fx) {
  return TakeFX_Delete(take, fx);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_EndParamEdit(MediaItem_Take* take, int fx, int param) {
  return TakeFX_EndParamEdit(take, fx, param);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_FormatParamValue(MediaItem_Take* take, int fx, int param, double val, char* buf, int buf_sz) {
  return TakeFX_FormatParamValue(take, fx, param, val, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_FormatParamValueNormalized(MediaItem_Take* take, int fx, int param, double value, char* buf, int buf_sz) {
  return TakeFX_FormatParamValueNormalized(take, fx, param, value, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _TakeFX_GetChainVisible(MediaItem_Take* take) {
  return TakeFX_GetChainVisible(take);
}

REAPER_PLUGIN_DLL_EXPORT int _TakeFX_GetCount(MediaItem_Take* take) {
  return TakeFX_GetCount(take);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_GetEnabled(MediaItem_Take* take, int fx) {
  return TakeFX_GetEnabled(take, fx);
}

REAPER_PLUGIN_DLL_EXPORT TrackEnvelope* _TakeFX_GetEnvelope(MediaItem_Take* take, int fxindex, int parameterindex, bool create) {
  return TakeFX_GetEnvelope(take, fxindex, parameterindex, create);
}

REAPER_PLUGIN_DLL_EXPORT HWND _TakeFX_GetFloatingWindow(MediaItem_Take* take, int index) {
  return TakeFX_GetFloatingWindow(take, index);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_GetFormattedParamValue(MediaItem_Take* take, int fx, int param, char* buf, int buf_sz) {
  return TakeFX_GetFormattedParamValue(take, fx, param, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT GUID* _TakeFX_GetFXGUID(MediaItem_Take* take, int fx) {
  return TakeFX_GetFXGUID(take, fx);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_GetFXName(MediaItem_Take* take, int fx, char* buf, int buf_sz) {
  return TakeFX_GetFXName(take, fx, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _TakeFX_GetIOSize(MediaItem_Take* take, int fx, int* inputPinsOutOptional, int* outputPinsOutOptional) {
  return TakeFX_GetIOSize(take, fx, inputPinsOutOptional, outputPinsOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_GetNamedConfigParm(MediaItem_Take* take, int fx, const char* parmname, char* bufOut, int bufOut_sz) {
  return TakeFX_GetNamedConfigParm(take, fx, parmname, bufOut, bufOut_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _TakeFX_GetNumParams(MediaItem_Take* take, int fx) {
  return TakeFX_GetNumParams(take, fx);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_GetOffline(MediaItem_Take* take, int fx) {
  return TakeFX_GetOffline(take, fx);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_GetOpen(MediaItem_Take* take, int fx) {
  return TakeFX_GetOpen(take, fx);
}

REAPER_PLUGIN_DLL_EXPORT double _TakeFX_GetParam(MediaItem_Take* take, int fx, int param, double* minvalOut, double* maxvalOut) {
  return TakeFX_GetParam(take, fx, param, minvalOut, maxvalOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_GetParameterStepSizes(MediaItem_Take* take, int fx, int param, double* stepOut, double* smallstepOut, double* largestepOut, bool* istoggleOut) {
  return TakeFX_GetParameterStepSizes(take, fx, param, stepOut, smallstepOut, largestepOut, istoggleOut);
}

REAPER_PLUGIN_DLL_EXPORT double _TakeFX_GetParamEx(MediaItem_Take* take, int fx, int param, double* minvalOut, double* maxvalOut, double* midvalOut) {
  return TakeFX_GetParamEx(take, fx, param, minvalOut, maxvalOut, midvalOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_GetParamName(MediaItem_Take* take, int fx, int param, char* buf, int buf_sz) {
  return TakeFX_GetParamName(take, fx, param, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT double _TakeFX_GetParamNormalized(MediaItem_Take* take, int fx, int param) {
  return TakeFX_GetParamNormalized(take, fx, param);
}

REAPER_PLUGIN_DLL_EXPORT int _TakeFX_GetPinMappings(MediaItem_Take* tr, int fx, int isoutput, int pin, int* high32OutOptional) {
  return TakeFX_GetPinMappings(tr, fx, isoutput, pin, high32OutOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_GetPreset(MediaItem_Take* take, int fx, char* presetname, int presetname_sz) {
  return TakeFX_GetPreset(take, fx, presetname, presetname_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _TakeFX_GetPresetIndex(MediaItem_Take* take, int fx, int* numberOfPresetsOut) {
  return TakeFX_GetPresetIndex(take, fx, numberOfPresetsOut);
}

REAPER_PLUGIN_DLL_EXPORT void _TakeFX_GetUserPresetFilename(MediaItem_Take* take, int fx, char* fn, int fn_sz) {
  return TakeFX_GetUserPresetFilename(take, fx, fn, fn_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_NavigatePresets(MediaItem_Take* take, int fx, int presetmove) {
  return TakeFX_NavigatePresets(take, fx, presetmove);
}

REAPER_PLUGIN_DLL_EXPORT void _TakeFX_SetEnabled(MediaItem_Take* take, int fx, bool enabled) {
  return TakeFX_SetEnabled(take, fx, enabled);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_SetNamedConfigParm(MediaItem_Take* take, int fx, const char* parmname, const char* value) {
  return TakeFX_SetNamedConfigParm(take, fx, parmname, value);
}

REAPER_PLUGIN_DLL_EXPORT void _TakeFX_SetOffline(MediaItem_Take* take, int fx, bool offline) {
  return TakeFX_SetOffline(take, fx, offline);
}

REAPER_PLUGIN_DLL_EXPORT void _TakeFX_SetOpen(MediaItem_Take* take, int fx, bool open) {
  return TakeFX_SetOpen(take, fx, open);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_SetParam(MediaItem_Take* take, int fx, int param, double val) {
  return TakeFX_SetParam(take, fx, param, val);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_SetParamNormalized(MediaItem_Take* take, int fx, int param, double value) {
  return TakeFX_SetParamNormalized(take, fx, param, value);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_SetPinMappings(MediaItem_Take* tr, int fx, int isoutput, int pin, int low32bits, int hi32bits) {
  return TakeFX_SetPinMappings(tr, fx, isoutput, pin, low32bits, hi32bits);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_SetPreset(MediaItem_Take* take, int fx, const char* presetname) {
  return TakeFX_SetPreset(take, fx, presetname);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeFX_SetPresetByIndex(MediaItem_Take* take, int fx, int idx) {
  return TakeFX_SetPresetByIndex(take, fx, idx);
}

REAPER_PLUGIN_DLL_EXPORT void _TakeFX_Show(MediaItem_Take* take, int index, int showFlag) {
  return TakeFX_Show(take, index, showFlag);
}

REAPER_PLUGIN_DLL_EXPORT bool _TakeIsMIDI(MediaItem_Take* take) {
  return TakeIsMIDI(take);
}

REAPER_PLUGIN_DLL_EXPORT bool _ThemeLayout_GetLayout(const char* section, int idx, char* nameOut, int nameOut_sz) {
  return ThemeLayout_GetLayout(section, idx, nameOut, nameOut_sz);
}

REAPER_PLUGIN_DLL_EXPORT const char* _ThemeLayout_GetParameter(int wp, const char** descOutOptional, int* valueOutOptional, int* defValueOutOptional, int* minValueOutOptional, int* maxValueOutOptional) {
  return ThemeLayout_GetParameter(wp, descOutOptional, valueOutOptional, defValueOutOptional, minValueOutOptional, maxValueOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT void _ThemeLayout_RefreshAll() {
  return ThemeLayout_RefreshAll();
}

REAPER_PLUGIN_DLL_EXPORT bool _ThemeLayout_SetLayout(const char* section, const char* layout) {
  return ThemeLayout_SetLayout(section, layout);
}

REAPER_PLUGIN_DLL_EXPORT bool _ThemeLayout_SetParameter(int wp, int value, bool persist) {
  return ThemeLayout_SetParameter(wp, value, persist);
}

REAPER_PLUGIN_DLL_EXPORT double _time_precise() {
  return time_precise();
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap2_beatsToTime(ReaProject* proj, double tpos, const int* measuresInOptional) {
  return TimeMap2_beatsToTime(proj, tpos, measuresInOptional);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap2_GetDividedBpmAtTime(ReaProject* proj, double time) {
  return TimeMap2_GetDividedBpmAtTime(proj, time);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap2_GetNextChangeTime(ReaProject* proj, double time) {
  return TimeMap2_GetNextChangeTime(proj, time);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap2_QNToTime(ReaProject* proj, double qn) {
  return TimeMap2_QNToTime(proj, qn);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap2_timeToBeats(ReaProject* proj, double tpos, int* measuresOutOptional, int* cmlOutOptional, double* fullbeatsOutOptional, int* cdenomOutOptional) {
  return TimeMap2_timeToBeats(proj, tpos, measuresOutOptional, cmlOutOptional, fullbeatsOutOptional, cdenomOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap2_timeToQN(ReaProject* proj, double tpos) {
  return TimeMap2_timeToQN(proj, tpos);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap_curFrameRate(ReaProject* proj, bool* dropFrameOutOptional) {
  return TimeMap_curFrameRate(proj, dropFrameOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap_GetDividedBpmAtTime(double time) {
  return TimeMap_GetDividedBpmAtTime(time);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap_GetMeasureInfo(ReaProject* proj, int measure, double* qn_startOut, double* qn_endOut, int* timesig_numOut, int* timesig_denomOut, double* tempoOut) {
  return TimeMap_GetMeasureInfo(proj, measure, qn_startOut, qn_endOut, timesig_numOut, timesig_denomOut, tempoOut);
}

REAPER_PLUGIN_DLL_EXPORT int _TimeMap_GetMetronomePattern(ReaProject* proj, double time, char* pattern, int pattern_sz) {
  return TimeMap_GetMetronomePattern(proj, time, pattern, pattern_sz);
}

REAPER_PLUGIN_DLL_EXPORT void _TimeMap_GetTimeSigAtTime(ReaProject* proj, double time, int* timesig_numOut, int* timesig_denomOut, double* tempoOut) {
  return TimeMap_GetTimeSigAtTime(proj, time, timesig_numOut, timesig_denomOut, tempoOut);
}

REAPER_PLUGIN_DLL_EXPORT int _TimeMap_QNToMeasures(ReaProject* proj, double qn, double* qnMeasureStartOutOptional, double* qnMeasureEndOutOptional) {
  return TimeMap_QNToMeasures(proj, qn, qnMeasureStartOutOptional, qnMeasureEndOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap_QNToTime(double qn) {
  return TimeMap_QNToTime(qn);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap_QNToTime_abs(ReaProject* proj, double qn) {
  return TimeMap_QNToTime_abs(proj, qn);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap_timeToQN(double tpos) {
  return TimeMap_timeToQN(tpos);
}

REAPER_PLUGIN_DLL_EXPORT double _TimeMap_timeToQN_abs(ReaProject* proj, double tpos) {
  return TimeMap_timeToQN_abs(proj, tpos);
}

REAPER_PLUGIN_DLL_EXPORT bool _ToggleTrackSendUIMute(MediaTrack* track, int send_idx) {
  return ToggleTrackSendUIMute(track, send_idx);
}

REAPER_PLUGIN_DLL_EXPORT double _Track_GetPeakHoldDB(MediaTrack* track, int channel, bool clear) {
  return Track_GetPeakHoldDB(track, channel, clear);
}

REAPER_PLUGIN_DLL_EXPORT double _Track_GetPeakInfo(MediaTrack* track, int channel) {
  return Track_GetPeakInfo(track, channel);
}

REAPER_PLUGIN_DLL_EXPORT void _TrackCtl_SetToolTip(const char* fmt, int xpos, int ypos, bool topmost) {
  return TrackCtl_SetToolTip(fmt, xpos, ypos, topmost);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_AddByName(MediaTrack* track, const char* fxname, bool recFX, int instantiate) {
  return TrackFX_AddByName(track, fxname, recFX, instantiate);
}

REAPER_PLUGIN_DLL_EXPORT void _TrackFX_CopyToTake(MediaTrack* src_track, int src_fx, MediaItem_Take* dest_take, int dest_fx, bool is_move) {
  return TrackFX_CopyToTake(src_track, src_fx, dest_take, dest_fx, is_move);
}

REAPER_PLUGIN_DLL_EXPORT void _TrackFX_CopyToTrack(MediaTrack* src_track, int src_fx, MediaTrack* dest_track, int dest_fx, bool is_move) {
  return TrackFX_CopyToTrack(src_track, src_fx, dest_track, dest_fx, is_move);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_Delete(MediaTrack* track, int fx) {
  return TrackFX_Delete(track, fx);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_EndParamEdit(MediaTrack* track, int fx, int param) {
  return TrackFX_EndParamEdit(track, fx, param);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_FormatParamValue(MediaTrack* track, int fx, int param, double val, char* buf, int buf_sz) {
  return TrackFX_FormatParamValue(track, fx, param, val, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_FormatParamValueNormalized(MediaTrack* track, int fx, int param, double value, char* buf, int buf_sz) {
  return TrackFX_FormatParamValueNormalized(track, fx, param, value, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_GetByName(MediaTrack* track, const char* fxname, bool instantiate) {
  return TrackFX_GetByName(track, fxname, instantiate);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_GetChainVisible(MediaTrack* track) {
  return TrackFX_GetChainVisible(track);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_GetCount(MediaTrack* track) {
  return TrackFX_GetCount(track);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_GetEnabled(MediaTrack* track, int fx) {
  return TrackFX_GetEnabled(track, fx);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_GetEQ(MediaTrack* track, bool instantiate) {
  return TrackFX_GetEQ(track, instantiate);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_GetEQBandEnabled(MediaTrack* track, int fxidx, int bandtype, int bandidx) {
  return TrackFX_GetEQBandEnabled(track, fxidx, bandtype, bandidx);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_GetEQParam(MediaTrack* track, int fxidx, int paramidx, int* bandtypeOut, int* bandidxOut, int* paramtypeOut, double* normvalOut) {
  return TrackFX_GetEQParam(track, fxidx, paramidx, bandtypeOut, bandidxOut, paramtypeOut, normvalOut);
}

REAPER_PLUGIN_DLL_EXPORT HWND _TrackFX_GetFloatingWindow(MediaTrack* track, int index) {
  return TrackFX_GetFloatingWindow(track, index);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_GetFormattedParamValue(MediaTrack* track, int fx, int param, char* buf, int buf_sz) {
  return TrackFX_GetFormattedParamValue(track, fx, param, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT GUID* _TrackFX_GetFXGUID(MediaTrack* track, int fx) {
  return TrackFX_GetFXGUID(track, fx);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_GetFXName(MediaTrack* track, int fx, char* buf, int buf_sz) {
  return TrackFX_GetFXName(track, fx, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_GetInstrument(MediaTrack* track) {
  return TrackFX_GetInstrument(track);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_GetIOSize(MediaTrack* track, int fx, int* inputPinsOutOptional, int* outputPinsOutOptional) {
  return TrackFX_GetIOSize(track, fx, inputPinsOutOptional, outputPinsOutOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_GetNamedConfigParm(MediaTrack* track, int fx, const char* parmname, char* bufOut, int bufOut_sz) {
  return TrackFX_GetNamedConfigParm(track, fx, parmname, bufOut, bufOut_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_GetNumParams(MediaTrack* track, int fx) {
  return TrackFX_GetNumParams(track, fx);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_GetOffline(MediaTrack* track, int fx) {
  return TrackFX_GetOffline(track, fx);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_GetOpen(MediaTrack* track, int fx) {
  return TrackFX_GetOpen(track, fx);
}

REAPER_PLUGIN_DLL_EXPORT double _TrackFX_GetParam(MediaTrack* track, int fx, int param, double* minvalOut, double* maxvalOut) {
  return TrackFX_GetParam(track, fx, param, minvalOut, maxvalOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_GetParameterStepSizes(MediaTrack* track, int fx, int param, double* stepOut, double* smallstepOut, double* largestepOut, bool* istoggleOut) {
  return TrackFX_GetParameterStepSizes(track, fx, param, stepOut, smallstepOut, largestepOut, istoggleOut);
}

REAPER_PLUGIN_DLL_EXPORT double _TrackFX_GetParamEx(MediaTrack* track, int fx, int param, double* minvalOut, double* maxvalOut, double* midvalOut) {
  return TrackFX_GetParamEx(track, fx, param, minvalOut, maxvalOut, midvalOut);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_GetParamName(MediaTrack* track, int fx, int param, char* buf, int buf_sz) {
  return TrackFX_GetParamName(track, fx, param, buf, buf_sz);
}

REAPER_PLUGIN_DLL_EXPORT double _TrackFX_GetParamNormalized(MediaTrack* track, int fx, int param) {
  return TrackFX_GetParamNormalized(track, fx, param);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_GetPinMappings(MediaTrack* tr, int fx, int isoutput, int pin, int* high32OutOptional) {
  return TrackFX_GetPinMappings(tr, fx, isoutput, pin, high32OutOptional);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_GetPreset(MediaTrack* track, int fx, char* presetname, int presetname_sz) {
  return TrackFX_GetPreset(track, fx, presetname, presetname_sz);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_GetPresetIndex(MediaTrack* track, int fx, int* numberOfPresetsOut) {
  return TrackFX_GetPresetIndex(track, fx, numberOfPresetsOut);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_GetRecChainVisible(MediaTrack* track) {
  return TrackFX_GetRecChainVisible(track);
}

REAPER_PLUGIN_DLL_EXPORT int _TrackFX_GetRecCount(MediaTrack* track) {
  return TrackFX_GetRecCount(track);
}

REAPER_PLUGIN_DLL_EXPORT void _TrackFX_GetUserPresetFilename(MediaTrack* track, int fx, char* fn, int fn_sz) {
  return TrackFX_GetUserPresetFilename(track, fx, fn, fn_sz);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_NavigatePresets(MediaTrack* track, int fx, int presetmove) {
  return TrackFX_NavigatePresets(track, fx, presetmove);
}

REAPER_PLUGIN_DLL_EXPORT void _TrackFX_SetEnabled(MediaTrack* track, int fx, bool enabled) {
  return TrackFX_SetEnabled(track, fx, enabled);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_SetEQBandEnabled(MediaTrack* track, int fxidx, int bandtype, int bandidx, bool enable) {
  return TrackFX_SetEQBandEnabled(track, fxidx, bandtype, bandidx, enable);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_SetEQParam(MediaTrack* track, int fxidx, int bandtype, int bandidx, int paramtype, double val, bool isnorm) {
  return TrackFX_SetEQParam(track, fxidx, bandtype, bandidx, paramtype, val, isnorm);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_SetNamedConfigParm(MediaTrack* track, int fx, const char* parmname, const char* value) {
  return TrackFX_SetNamedConfigParm(track, fx, parmname, value);
}

REAPER_PLUGIN_DLL_EXPORT void _TrackFX_SetOffline(MediaTrack* track, int fx, bool offline) {
  return TrackFX_SetOffline(track, fx, offline);
}

REAPER_PLUGIN_DLL_EXPORT void _TrackFX_SetOpen(MediaTrack* track, int fx, bool open) {
  return TrackFX_SetOpen(track, fx, open);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_SetParam(MediaTrack* track, int fx, int param, double val) {
  return TrackFX_SetParam(track, fx, param, val);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_SetParamNormalized(MediaTrack* track, int fx, int param, double value) {
  return TrackFX_SetParamNormalized(track, fx, param, value);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_SetPinMappings(MediaTrack* tr, int fx, int isoutput, int pin, int low32bits, int hi32bits) {
  return TrackFX_SetPinMappings(tr, fx, isoutput, pin, low32bits, hi32bits);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_SetPreset(MediaTrack* track, int fx, const char* presetname) {
  return TrackFX_SetPreset(track, fx, presetname);
}

REAPER_PLUGIN_DLL_EXPORT bool _TrackFX_SetPresetByIndex(MediaTrack* track, int fx, int idx) {
  return TrackFX_SetPresetByIndex(track, fx, idx);
}

REAPER_PLUGIN_DLL_EXPORT void _TrackFX_Show(MediaTrack* track, int index, int showFlag) {
  return TrackFX_Show(track, index, showFlag);
}

REAPER_PLUGIN_DLL_EXPORT void _TrackList_AdjustWindows(bool isMinor) {
  return TrackList_AdjustWindows(isMinor);
}

REAPER_PLUGIN_DLL_EXPORT void _TrackList_UpdateAllExternalSurfaces() {
  return TrackList_UpdateAllExternalSurfaces();
}

REAPER_PLUGIN_DLL_EXPORT void _Undo_BeginBlock() {
  return Undo_BeginBlock();
}

REAPER_PLUGIN_DLL_EXPORT void _Undo_BeginBlock2(ReaProject* proj) {
  return Undo_BeginBlock2(proj);
}

REAPER_PLUGIN_DLL_EXPORT const char* _Undo_CanRedo2(ReaProject* proj) {
  return Undo_CanRedo2(proj);
}

REAPER_PLUGIN_DLL_EXPORT const char* _Undo_CanUndo2(ReaProject* proj) {
  return Undo_CanUndo2(proj);
}

REAPER_PLUGIN_DLL_EXPORT int _Undo_DoRedo2(ReaProject* proj) {
  return Undo_DoRedo2(proj);
}

REAPER_PLUGIN_DLL_EXPORT int _Undo_DoUndo2(ReaProject* proj) {
  return Undo_DoUndo2(proj);
}

REAPER_PLUGIN_DLL_EXPORT void _Undo_EndBlock(const char* descchange, int extraflags) {
  return Undo_EndBlock(descchange, extraflags);
}

REAPER_PLUGIN_DLL_EXPORT void _Undo_EndBlock2(ReaProject* proj, const char* descchange, int extraflags) {
  return Undo_EndBlock2(proj, descchange, extraflags);
}

REAPER_PLUGIN_DLL_EXPORT void _Undo_OnStateChange(const char* descchange) {
  return Undo_OnStateChange(descchange);
}

REAPER_PLUGIN_DLL_EXPORT void _Undo_OnStateChange2(ReaProject* proj, const char* descchange) {
  return Undo_OnStateChange2(proj, descchange);
}

REAPER_PLUGIN_DLL_EXPORT void _Undo_OnStateChange_Item(ReaProject* proj, const char* name, MediaItem* item) {
  return Undo_OnStateChange_Item(proj, name, item);
}

REAPER_PLUGIN_DLL_EXPORT void _Undo_OnStateChangeEx(const char* descchange, int whichStates, int trackparm) {
  return Undo_OnStateChangeEx(descchange, whichStates, trackparm);
}

REAPER_PLUGIN_DLL_EXPORT void _Undo_OnStateChangeEx2(ReaProject* proj, const char* descchange, int whichStates, int trackparm) {
  return Undo_OnStateChangeEx2(proj, descchange, whichStates, trackparm);
}

REAPER_PLUGIN_DLL_EXPORT void _update_disk_counters(int readamt, int writeamt) {
  return update_disk_counters(readamt, writeamt);
}

REAPER_PLUGIN_DLL_EXPORT void _UpdateArrange() {
  return UpdateArrange();
}

REAPER_PLUGIN_DLL_EXPORT void _UpdateItemInProject(MediaItem* item) {
  return UpdateItemInProject(item);
}

REAPER_PLUGIN_DLL_EXPORT void _UpdateTimeline() {
  return UpdateTimeline();
}

REAPER_PLUGIN_DLL_EXPORT bool _ValidatePtr(void* pointer, const char* ctypename) {
  return ValidatePtr(pointer, ctypename);
}

REAPER_PLUGIN_DLL_EXPORT bool _ValidatePtr2(ReaProject* proj, void* pointer, const char* ctypename) {
  return ValidatePtr2(proj, pointer, ctypename);
}

REAPER_PLUGIN_DLL_EXPORT void _ViewPrefs(int page, const char* pageByName) {
  return ViewPrefs(page, pageByName);
}

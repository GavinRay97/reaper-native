
#define REAPERAPI_IMPLEMENT
#include "reaper_plugin_functions.h"

bool AddCustomizableMenuWrapper(const char* menuidstr, const char* menuname, const char* kbdsecname, bool addtomainmenu)
{
    return AddCustomizableMenu(menuidstr, menuname, kbdsecname, addtomainmenu);
}

bool AddExtensionsMainMenuWrapper()
{
    return AddExtensionsMainMenu();
}

MediaItem* AddMediaItemToTrackWrapper(MediaTrack* tr)
{
    return AddMediaItemToTrack(tr);
}

int AddProjectMarkerWrapper(ReaProject* proj, bool isrgn, double pos, double rgnend, const char* name, int wantidx)
{
    return AddProjectMarker(proj, isrgn, pos, rgnend, name, wantidx);
}

int AddProjectMarker2Wrapper(ReaProject* proj, bool isrgn, double pos, double rgnend, const char* name, int wantidx, int color)
{
    return AddProjectMarker2(proj, isrgn, pos, rgnend, name, wantidx, color);
}

int AddRemoveReaScriptWrapper(bool add, int sectionID, const char* scriptfn, bool commit)
{
    return AddRemoveReaScript(add, sectionID, scriptfn, commit);
}

MediaItem_Take* AddTakeToMediaItemWrapper(MediaItem* item)
{
    return AddTakeToMediaItem(item);
}

bool AddTempoTimeSigMarkerWrapper(ReaProject* proj, double timepos, double bpm, int timesig_num, int timesig_denom, bool lineartempochange)
{
    return AddTempoTimeSigMarker(proj, timepos, bpm, timesig_num, timesig_denom, lineartempochange);
}

void adjustZoomWrapper(double amt, int forceset, bool doupd, int centermode)
{
    return adjustZoom(amt, forceset, doupd, centermode);
}

bool AnyTrackSoloWrapper(ReaProject* proj)
{
    return AnyTrackSolo(proj);
}

bool APIExistsWrapper(const char* function_name)
{
    return APIExists(function_name);
}

void APITestWrapper()
{
    return APITest();
}

bool ApplyNudgeWrapper(ReaProject* project, int nudgeflag, int nudgewhat, int nudgeunits, double value, bool reverse, int copies)
{
    return ApplyNudge(project, nudgeflag, nudgewhat, nudgeunits, value, reverse, copies);
}

void ArmCommandWrapper(int cmd, const char* sectionname)
{
    return ArmCommand(cmd, sectionname);
}

void Audio_InitWrapper()
{
    return Audio_Init();
}

int Audio_IsPreBufferWrapper()
{
    return Audio_IsPreBuffer();
}

int Audio_IsRunningWrapper()
{
    return Audio_IsRunning();
}

void Audio_QuitWrapper()
{
    return Audio_Quit();
}

int Audio_RegHardwareHookWrapper(bool isAdd, audio_hook_register_t* reg)
{
    return Audio_RegHardwareHook(isAdd, reg);
}

bool AudioAccessorStateChangedWrapper(AudioAccessor* accessor)
{
    return AudioAccessorStateChanged(accessor);
}

void AudioAccessorUpdateWrapper(AudioAccessor* accessor)
{
    return AudioAccessorUpdate(accessor);
}

bool AudioAccessorValidateStateWrapper(AudioAccessor* accessor)
{
    return AudioAccessorValidateState(accessor);
}

void BypassFxAllTracksWrapper(int bypass)
{
    return BypassFxAllTracks(bypass);
}

int CalculatePeaksWrapper(PCM_source_transfer_t* srcBlock, PCM_source_peaktransfer_t* pksBlock)
{
    return CalculatePeaks(srcBlock, pksBlock);
}

int CalculatePeaksFloatSrcPtrWrapper(PCM_source_transfer_t* srcBlock, PCM_source_peaktransfer_t* pksBlock)
{
    return CalculatePeaksFloatSrcPtr(srcBlock, pksBlock);
}

void ClearAllRecArmedWrapper()
{
    return ClearAllRecArmed();
}

void ClearConsoleWrapper()
{
    return ClearConsole();
}

void ClearPeakCacheWrapper()
{
    return ClearPeakCache();
}

void ColorFromNativeWrapper(int col, int* rOut, int* gOut, int* bOut)
{
    return ColorFromNative(col, rOut, gOut, bOut);
}

int ColorToNativeWrapper(int r, int g, int b)
{
    return ColorToNative(r, g, b);
}

int CountActionShortcutsWrapper(KbdSectionInfo* section, int cmdID)
{
    return CountActionShortcuts(section, cmdID);
}

int CountAutomationItemsWrapper(TrackEnvelope* env)
{
    return CountAutomationItems(env);
}

int CountEnvelopePointsWrapper(TrackEnvelope* envelope)
{
    return CountEnvelopePoints(envelope);
}

int CountEnvelopePointsExWrapper(TrackEnvelope* envelope, int autoitem_idx)
{
    return CountEnvelopePointsEx(envelope, autoitem_idx);
}

int CountMediaItemsWrapper(ReaProject* proj)
{
    return CountMediaItems(proj);
}

int CountProjectMarkersWrapper(ReaProject* proj, int* num_markersOut, int* num_regionsOut)
{
    return CountProjectMarkers(proj, num_markersOut, num_regionsOut);
}

int CountSelectedMediaItemsWrapper(ReaProject* proj)
{
    return CountSelectedMediaItems(proj);
}

int CountSelectedTracksWrapper(ReaProject* proj)
{
    return CountSelectedTracks(proj);
}

int CountSelectedTracks2Wrapper(ReaProject* proj, bool wantmaster)
{
    return CountSelectedTracks2(proj, wantmaster);
}

int CountTakeEnvelopesWrapper(MediaItem_Take* take)
{
    return CountTakeEnvelopes(take);
}

int CountTakesWrapper(MediaItem* item)
{
    return CountTakes(item);
}

int CountTCPFXParmsWrapper(ReaProject* project, MediaTrack* track)
{
    return CountTCPFXParms(project, track);
}

int CountTempoTimeSigMarkersWrapper(ReaProject* proj)
{
    return CountTempoTimeSigMarkers(proj);
}

int CountTrackEnvelopesWrapper(MediaTrack* track)
{
    return CountTrackEnvelopes(track);
}

int CountTrackMediaItemsWrapper(MediaTrack* track)
{
    return CountTrackMediaItems(track);
}

int CountTracksWrapper(ReaProject* projOptional)
{
    return CountTracks(projOptional);
}

void* CreateLocalOscHandlerWrapper(void* obj, void* callback)
{
    return CreateLocalOscHandler(obj, callback);
}

midi_Input* CreateMIDIInputWrapper(int dev)
{
    return CreateMIDIInput(dev);
}

midi_Output* CreateMIDIOutputWrapper(int dev, bool streamMode, int* msoffset100)
{
    return CreateMIDIOutput(dev, streamMode, msoffset100);
}

MediaItem* CreateNewMIDIItemInProjWrapper(MediaTrack* track, double starttime, double endtime, const bool* qnInOptional)
{
    return CreateNewMIDIItemInProj(track, starttime, endtime, qnInOptional);
}

AudioAccessor* CreateTakeAudioAccessorWrapper(MediaItem_Take* take)
{
    return CreateTakeAudioAccessor(take);
}

AudioAccessor* CreateTrackAudioAccessorWrapper(MediaTrack* track)
{
    return CreateTrackAudioAccessor(track);
}

int CreateTrackSendWrapper(MediaTrack* tr, MediaTrack* desttrInOptional)
{
    return CreateTrackSend(tr, desttrInOptional);
}

void CSurf_FlushUndoWrapper(bool force)
{
    return CSurf_FlushUndo(force);
}

bool CSurf_GetTouchStateWrapper(MediaTrack* trackid, int isPan)
{
    return CSurf_GetTouchState(trackid, isPan);
}

void CSurf_GoEndWrapper()
{
    return CSurf_GoEnd();
}

void CSurf_GoStartWrapper()
{
    return CSurf_GoStart();
}

int CSurf_NumTracksWrapper(bool mcpView)
{
    return CSurf_NumTracks(mcpView);
}

void CSurf_OnArrowWrapper(int whichdir, bool wantzoom)
{
    return CSurf_OnArrow(whichdir, wantzoom);
}

void CSurf_OnFwdWrapper(int seekplay)
{
    return CSurf_OnFwd(seekplay);
}

bool CSurf_OnFXChangeWrapper(MediaTrack* trackid, int en)
{
    return CSurf_OnFXChange(trackid, en);
}

int CSurf_OnInputMonitorChangeWrapper(MediaTrack* trackid, int monitor)
{
    return CSurf_OnInputMonitorChange(trackid, monitor);
}

int CSurf_OnInputMonitorChangeExWrapper(MediaTrack* trackid, int monitor, bool allowgang)
{
    return CSurf_OnInputMonitorChangeEx(trackid, monitor, allowgang);
}

bool CSurf_OnMuteChangeWrapper(MediaTrack* trackid, int mute)
{
    return CSurf_OnMuteChange(trackid, mute);
}

bool CSurf_OnMuteChangeExWrapper(MediaTrack* trackid, int mute, bool allowgang)
{
    return CSurf_OnMuteChangeEx(trackid, mute, allowgang);
}

void CSurf_OnOscControlMessageWrapper(const char* msg, const float* arg)
{
    return CSurf_OnOscControlMessage(msg, arg);
}

double CSurf_OnPanChangeWrapper(MediaTrack* trackid, double pan, bool relative)
{
    return CSurf_OnPanChange(trackid, pan, relative);
}

double CSurf_OnPanChangeExWrapper(MediaTrack* trackid, double pan, bool relative, bool allowGang)
{
    return CSurf_OnPanChangeEx(trackid, pan, relative, allowGang);
}

void CSurf_OnPauseWrapper()
{
    return CSurf_OnPause();
}

void CSurf_OnPlayWrapper()
{
    return CSurf_OnPlay();
}

void CSurf_OnPlayRateChangeWrapper(double playrate)
{
    return CSurf_OnPlayRateChange(playrate);
}

bool CSurf_OnRecArmChangeWrapper(MediaTrack* trackid, int recarm)
{
    return CSurf_OnRecArmChange(trackid, recarm);
}

bool CSurf_OnRecArmChangeExWrapper(MediaTrack* trackid, int recarm, bool allowgang)
{
    return CSurf_OnRecArmChangeEx(trackid, recarm, allowgang);
}

void CSurf_OnRecordWrapper()
{
    return CSurf_OnRecord();
}

double CSurf_OnRecvPanChangeWrapper(MediaTrack* trackid, int recv_index, double pan, bool relative)
{
    return CSurf_OnRecvPanChange(trackid, recv_index, pan, relative);
}

double CSurf_OnRecvVolumeChangeWrapper(MediaTrack* trackid, int recv_index, double volume, bool relative)
{
    return CSurf_OnRecvVolumeChange(trackid, recv_index, volume, relative);
}

void CSurf_OnRewWrapper(int seekplay)
{
    return CSurf_OnRew(seekplay);
}

void CSurf_OnRewFwdWrapper(int seekplay, int dir)
{
    return CSurf_OnRewFwd(seekplay, dir);
}

void CSurf_OnScrollWrapper(int xdir, int ydir)
{
    return CSurf_OnScroll(xdir, ydir);
}

bool CSurf_OnSelectedChangeWrapper(MediaTrack* trackid, int selected)
{
    return CSurf_OnSelectedChange(trackid, selected);
}

double CSurf_OnSendPanChangeWrapper(MediaTrack* trackid, int send_index, double pan, bool relative)
{
    return CSurf_OnSendPanChange(trackid, send_index, pan, relative);
}

double CSurf_OnSendVolumeChangeWrapper(MediaTrack* trackid, int send_index, double volume, bool relative)
{
    return CSurf_OnSendVolumeChange(trackid, send_index, volume, relative);
}

bool CSurf_OnSoloChangeWrapper(MediaTrack* trackid, int solo)
{
    return CSurf_OnSoloChange(trackid, solo);
}

bool CSurf_OnSoloChangeExWrapper(MediaTrack* trackid, int solo, bool allowgang)
{
    return CSurf_OnSoloChangeEx(trackid, solo, allowgang);
}

void CSurf_OnStopWrapper()
{
    return CSurf_OnStop();
}

void CSurf_OnTempoChangeWrapper(double bpm)
{
    return CSurf_OnTempoChange(bpm);
}

void CSurf_OnTrackSelectionWrapper(MediaTrack* trackid)
{
    return CSurf_OnTrackSelection(trackid);
}

double CSurf_OnVolumeChangeWrapper(MediaTrack* trackid, double volume, bool relative)
{
    return CSurf_OnVolumeChange(trackid, volume, relative);
}

double CSurf_OnVolumeChangeExWrapper(MediaTrack* trackid, double volume, bool relative, bool allowGang)
{
    return CSurf_OnVolumeChangeEx(trackid, volume, relative, allowGang);
}

double CSurf_OnWidthChangeWrapper(MediaTrack* trackid, double width, bool relative)
{
    return CSurf_OnWidthChange(trackid, width, relative);
}

double CSurf_OnWidthChangeExWrapper(MediaTrack* trackid, double width, bool relative, bool allowGang)
{
    return CSurf_OnWidthChangeEx(trackid, width, relative, allowGang);
}

void CSurf_OnZoomWrapper(int xdir, int ydir)
{
    return CSurf_OnZoom(xdir, ydir);
}

void CSurf_ResetAllCachedVolPanStatesWrapper()
{
    return CSurf_ResetAllCachedVolPanStates();
}

void CSurf_ScrubAmtWrapper(double amt)
{
    return CSurf_ScrubAmt(amt);
}

void CSurf_SetAutoModeWrapper(int mode, IReaperControlSurface* ignoresurf)
{
    return CSurf_SetAutoMode(mode, ignoresurf);
}

void CSurf_SetPlayStateWrapper(bool play, bool pause, bool rec, IReaperControlSurface* ignoresurf)
{
    return CSurf_SetPlayState(play, pause, rec, ignoresurf);
}

void CSurf_SetRepeatStateWrapper(bool rep, IReaperControlSurface* ignoresurf)
{
    return CSurf_SetRepeatState(rep, ignoresurf);
}

void CSurf_SetSurfaceMuteWrapper(MediaTrack* trackid, bool mute, IReaperControlSurface* ignoresurf)
{
    return CSurf_SetSurfaceMute(trackid, mute, ignoresurf);
}

void CSurf_SetSurfacePanWrapper(MediaTrack* trackid, double pan, IReaperControlSurface* ignoresurf)
{
    return CSurf_SetSurfacePan(trackid, pan, ignoresurf);
}

void CSurf_SetSurfaceRecArmWrapper(MediaTrack* trackid, bool recarm, IReaperControlSurface* ignoresurf)
{
    return CSurf_SetSurfaceRecArm(trackid, recarm, ignoresurf);
}

void CSurf_SetSurfaceSelectedWrapper(MediaTrack* trackid, bool selected, IReaperControlSurface* ignoresurf)
{
    return CSurf_SetSurfaceSelected(trackid, selected, ignoresurf);
}

void CSurf_SetSurfaceSoloWrapper(MediaTrack* trackid, bool solo, IReaperControlSurface* ignoresurf)
{
    return CSurf_SetSurfaceSolo(trackid, solo, ignoresurf);
}

void CSurf_SetSurfaceVolumeWrapper(MediaTrack* trackid, double volume, IReaperControlSurface* ignoresurf)
{
    return CSurf_SetSurfaceVolume(trackid, volume, ignoresurf);
}

void CSurf_SetTrackListChangeWrapper()
{
    return CSurf_SetTrackListChange();
}

MediaTrack* CSurf_TrackFromIDWrapper(int idx, bool mcpView)
{
    return CSurf_TrackFromID(idx, mcpView);
}

int CSurf_TrackToIDWrapper(MediaTrack* track, bool mcpView)
{
    return CSurf_TrackToID(track, mcpView);
}

double DB2SLIDERWrapper(double x)
{
    return DB2SLIDER(x);
}

bool DeleteActionShortcutWrapper(KbdSectionInfo* section, int cmdID, int shortcutidx)
{
    return DeleteActionShortcut(section, cmdID, shortcutidx);
}

bool DeleteEnvelopePointExWrapper(TrackEnvelope* envelope, int autoitem_idx, int ptidx)
{
    return DeleteEnvelopePointEx(envelope, autoitem_idx, ptidx);
}

bool DeleteEnvelopePointRangeWrapper(TrackEnvelope* envelope, double time_start, double time_end)
{
    return DeleteEnvelopePointRange(envelope, time_start, time_end);
}

bool DeleteEnvelopePointRangeExWrapper(TrackEnvelope* envelope, int autoitem_idx, double time_start, double time_end)
{
    return DeleteEnvelopePointRangeEx(envelope, autoitem_idx, time_start, time_end);
}

void DeleteExtStateWrapper(const char* section, const char* key, bool persist)
{
    return DeleteExtState(section, key, persist);
}

bool DeleteProjectMarkerWrapper(ReaProject* proj, int markrgnindexnumber, bool isrgn)
{
    return DeleteProjectMarker(proj, markrgnindexnumber, isrgn);
}

bool DeleteProjectMarkerByIndexWrapper(ReaProject* proj, int markrgnidx)
{
    return DeleteProjectMarkerByIndex(proj, markrgnidx);
}

bool DeleteTakeMarkerWrapper(MediaItem_Take* take, int idx)
{
    return DeleteTakeMarker(take, idx);
}

int DeleteTakeStretchMarkersWrapper(MediaItem_Take* take, int idx, const int* countInOptional)
{
    return DeleteTakeStretchMarkers(take, idx, countInOptional);
}

bool DeleteTempoTimeSigMarkerWrapper(ReaProject* project, int markerindex)
{
    return DeleteTempoTimeSigMarker(project, markerindex);
}

void DeleteTrackWrapper(MediaTrack* tr)
{
    return DeleteTrack(tr);
}

bool DeleteTrackMediaItemWrapper(MediaTrack* tr, MediaItem* it)
{
    return DeleteTrackMediaItem(tr, it);
}

void DestroyAudioAccessorWrapper(AudioAccessor* accessor)
{
    return DestroyAudioAccessor(accessor);
}

void DestroyLocalOscHandlerWrapper(void* local_osc_handler)
{
    return DestroyLocalOscHandler(local_osc_handler);
}

bool DoActionShortcutDialogWrapper(HWND hwnd, KbdSectionInfo* section, int cmdID, int shortcutidx)
{
    return DoActionShortcutDialog(hwnd, section, cmdID, shortcutidx);
}

void Dock_UpdateDockIDWrapper(const char* ident_str, int whichDock)
{
    return Dock_UpdateDockID(ident_str, whichDock);
}

int DockGetPositionWrapper(int whichDock)
{
    return DockGetPosition(whichDock);
}

int DockIsChildOfDockWrapper(HWND hwnd, bool* isFloatingDockerOut)
{
    return DockIsChildOfDock(hwnd, isFloatingDockerOut);
}

void DockWindowActivateWrapper(HWND hwnd)
{
    return DockWindowActivate(hwnd);
}

void DockWindowAddWrapper(HWND hwnd, const char* name, int pos, bool allowShow)
{
    return DockWindowAdd(hwnd, name, pos, allowShow);
}

void DockWindowAddExWrapper(HWND hwnd, const char* name, const char* identstr, bool allowShow)
{
    return DockWindowAddEx(hwnd, name, identstr, allowShow);
}

void DockWindowRefreshWrapper()
{
    return DockWindowRefresh();
}

void DockWindowRefreshForHWNDWrapper(HWND hwnd)
{
    return DockWindowRefreshForHWND(hwnd);
}

void DockWindowRemoveWrapper(HWND hwnd)
{
    return DockWindowRemove(hwnd);
}

bool DuplicateCustomizableMenuWrapper(void* srcmenu, void* destmenu)
{
    return DuplicateCustomizableMenu(srcmenu, destmenu);
}

bool EditTempoTimeSigMarkerWrapper(ReaProject* project, int markerindex)
{
    return EditTempoTimeSigMarker(project, markerindex);
}

void EnsureNotCompletelyOffscreenWrapper(RECT* rInOut)
{
    return EnsureNotCompletelyOffscreen(rInOut);
}

const char* EnumerateFilesWrapper(const char* path, int fileindex)
{
    return EnumerateFiles(path, fileindex);
}

const char* EnumerateSubdirectoriesWrapper(const char* path, int subdirindex)
{
    return EnumerateSubdirectories(path, subdirindex);
}

bool EnumPitchShiftModesWrapper(int mode, const char** strOut)
{
    return EnumPitchShiftModes(mode, strOut);
}

const char* EnumPitchShiftSubModesWrapper(int mode, int submode)
{
    return EnumPitchShiftSubModes(mode, submode);
}

int EnumProjectMarkersWrapper(int idx, bool* isrgnOut, double* posOut, double* rgnendOut, const char** nameOut, int* markrgnindexnumberOut)
{
    return EnumProjectMarkers(idx, isrgnOut, posOut, rgnendOut, nameOut, markrgnindexnumberOut);
}

int EnumProjectMarkers2Wrapper(ReaProject* proj, int idx, bool* isrgnOut, double* posOut, double* rgnendOut, const char** nameOut, int* markrgnindexnumberOut)
{
    return EnumProjectMarkers2(proj, idx, isrgnOut, posOut, rgnendOut, nameOut, markrgnindexnumberOut);
}

int EnumProjectMarkers3Wrapper(ReaProject* proj, int idx, bool* isrgnOut, double* posOut, double* rgnendOut, const char** nameOut, int* markrgnindexnumberOut, int* colorOut)
{
    return EnumProjectMarkers3(proj, idx, isrgnOut, posOut, rgnendOut, nameOut, markrgnindexnumberOut, colorOut);
}

ReaProject* EnumProjectsWrapper(int idx, char* projfnOutOptional, int projfnOutOptional_sz)
{
    return EnumProjects(idx, projfnOutOptional, projfnOutOptional_sz);
}

bool EnumProjExtStateWrapper(ReaProject* proj, const char* extname, int idx, char* keyOutOptional, int keyOutOptional_sz, char* valOutOptional, int valOutOptional_sz)
{
    return EnumProjExtState(proj, extname, idx, keyOutOptional, keyOutOptional_sz, valOutOptional, valOutOptional_sz);
}

MediaTrack* EnumRegionRenderMatrixWrapper(ReaProject* proj, int regionindex, int rendertrack)
{
    return EnumRegionRenderMatrix(proj, regionindex, rendertrack);
}

bool EnumTrackMIDIProgramNamesWrapper(int track, int programNumber, char* programName, int programName_sz)
{
    return EnumTrackMIDIProgramNames(track, programNumber, programName, programName_sz);
}

bool EnumTrackMIDIProgramNamesExWrapper(ReaProject* proj, MediaTrack* track, int programNumber, char* programName, int programName_sz)
{
    return EnumTrackMIDIProgramNamesEx(proj, track, programNumber, programName, programName_sz);
}

int Envelope_EvaluateWrapper(TrackEnvelope* envelope, double time, double samplerate, int samplesRequested, double* valueOutOptional, double* dVdSOutOptional, double* ddVdSOutOptional, double* dddVdSOutOptional)
{
    return Envelope_Evaluate(envelope, time, samplerate, samplesRequested, valueOutOptional, dVdSOutOptional, ddVdSOutOptional, dddVdSOutOptional);
}

void Envelope_FormatValueWrapper(TrackEnvelope* env, double value, char* bufOut, int bufOut_sz)
{
    return Envelope_FormatValue(env, value, bufOut, bufOut_sz);
}

MediaItem_Take* Envelope_GetParentTakeWrapper(TrackEnvelope* env, int* indexOutOptional, int* index2OutOptional)
{
    return Envelope_GetParentTake(env, indexOutOptional, index2OutOptional);
}

MediaTrack* Envelope_GetParentTrackWrapper(TrackEnvelope* env, int* indexOutOptional, int* index2OutOptional)
{
    return Envelope_GetParentTrack(env, indexOutOptional, index2OutOptional);
}

bool Envelope_SortPointsWrapper(TrackEnvelope* envelope)
{
    return Envelope_SortPoints(envelope);
}

bool Envelope_SortPointsExWrapper(TrackEnvelope* envelope, int autoitem_idx)
{
    return Envelope_SortPointsEx(envelope, autoitem_idx);
}

const char* ExecProcessWrapper(const char* cmdline, int timeoutmsec)
{
    return ExecProcess(cmdline, timeoutmsec);
}

bool file_existsWrapper(const char* path)
{
    return file_exists(path);
}

int FindTempoTimeSigMarkerWrapper(ReaProject* project, double time)
{
    return FindTempoTimeSigMarker(project, time);
}

void format_timestrWrapper(double tpos, char* buf, int buf_sz)
{
    return format_timestr(tpos, buf, buf_sz);
}

void format_timestr_lenWrapper(double tpos, char* buf, int buf_sz, double offset, int modeoverride)
{
    return format_timestr_len(tpos, buf, buf_sz, offset, modeoverride);
}

void format_timestr_posWrapper(double tpos, char* buf, int buf_sz, int modeoverride)
{
    return format_timestr_pos(tpos, buf, buf_sz, modeoverride);
}

void FreeHeapPtrWrapper(void* ptr)
{
    return FreeHeapPtr(ptr);
}

void genGuidWrapper(GUID* g)
{
    return genGuid(g);
}

void* get_config_varWrapper(const char* name, int* szOut)
{
    return get_config_var(name, szOut);
}

bool get_config_var_stringWrapper(const char* name, char* bufOut, int bufOut_sz)
{
    return get_config_var_string(name, bufOut, bufOut_sz);
}

const char* get_ini_fileWrapper()
{
    return get_ini_file();
}

void* get_midi_config_varWrapper(const char* name, int* szOut)
{
    return get_midi_config_var(name, szOut);
}

bool GetActionShortcutDescWrapper(KbdSectionInfo* section, int cmdID, int shortcutidx, char* desc, int desclen)
{
    return GetActionShortcutDesc(section, cmdID, shortcutidx, desc, desclen);
}

MediaItem_Take* GetActiveTakeWrapper(MediaItem* item)
{
    return GetActiveTake(item);
}

int GetAllProjectPlayStatesWrapper(ReaProject* ignoreProject)
{
    return GetAllProjectPlayStates(ignoreProject);
}

const char* GetAppVersionWrapper()
{
    return GetAppVersion();
}

int GetArmedCommandWrapper(char* secOut, int secOut_sz)
{
    return GetArmedCommand(secOut, secOut_sz);
}

double GetAudioAccessorEndTimeWrapper(AudioAccessor* accessor)
{
    return GetAudioAccessorEndTime(accessor);
}

void GetAudioAccessorHashWrapper(AudioAccessor* accessor, char* hashNeed128)
{
    return GetAudioAccessorHash(accessor, hashNeed128);
}

int GetAudioAccessorSamplesWrapper(AudioAccessor* accessor, int samplerate, int numchannels, double starttime_sec, int numsamplesperchannel, double* samplebuffer)
{
    return GetAudioAccessorSamples(accessor, samplerate, numchannels, starttime_sec, numsamplesperchannel, samplebuffer);
}

double GetAudioAccessorStartTimeWrapper(AudioAccessor* accessor)
{
    return GetAudioAccessorStartTime(accessor);
}

bool GetAudioDeviceInfoWrapper(const char* attribute, char* desc, int desc_sz)
{
    return GetAudioDeviceInfo(attribute, desc, desc_sz);
}

INT_PTR GetColorThemeWrapper(int idx, int defval)
{
    return GetColorTheme(idx, defval);
}

void* GetColorThemeStructWrapper(int* szOut)
{
    return GetColorThemeStruct(szOut);
}

int GetConfigWantsDockWrapper(const char* ident_str)
{
    return GetConfigWantsDock(ident_str);
}

HMENU GetContextMenuWrapper(int idx)
{
    return GetContextMenu(idx);
}

ReaProject* GetCurrentProjectInLoadSaveWrapper()
{
    return GetCurrentProjectInLoadSave();
}

int GetCursorContextWrapper()
{
    return GetCursorContext();
}

int GetCursorContext2Wrapper(bool want_last_valid)
{
    return GetCursorContext2(want_last_valid);
}

double GetCursorPositionWrapper()
{
    return GetCursorPosition();
}

double GetCursorPositionExWrapper(ReaProject* proj)
{
    return GetCursorPositionEx(proj);
}

int GetDisplayedMediaItemColorWrapper(MediaItem* item)
{
    return GetDisplayedMediaItemColor(item);
}

int GetDisplayedMediaItemColor2Wrapper(MediaItem* item, MediaItem_Take* take)
{
    return GetDisplayedMediaItemColor2(item, take);
}

double GetEnvelopeInfo_ValueWrapper(TrackEnvelope* tr, const char* parmname)
{
    return GetEnvelopeInfo_Value(tr, parmname);
}

bool GetEnvelopeNameWrapper(TrackEnvelope* env, char* bufOut, int bufOut_sz)
{
    return GetEnvelopeName(env, bufOut, bufOut_sz);
}

bool GetEnvelopePointWrapper(TrackEnvelope* envelope, int ptidx, double* timeOutOptional, double* valueOutOptional, int* shapeOutOptional, double* tensionOutOptional, bool* selectedOutOptional)
{
    return GetEnvelopePoint(envelope, ptidx, timeOutOptional, valueOutOptional, shapeOutOptional, tensionOutOptional, selectedOutOptional);
}

int GetEnvelopePointByTimeWrapper(TrackEnvelope* envelope, double time)
{
    return GetEnvelopePointByTime(envelope, time);
}

int GetEnvelopePointByTimeExWrapper(TrackEnvelope* envelope, int autoitem_idx, double time)
{
    return GetEnvelopePointByTimeEx(envelope, autoitem_idx, time);
}

bool GetEnvelopePointExWrapper(TrackEnvelope* envelope, int autoitem_idx, int ptidx, double* timeOutOptional, double* valueOutOptional, int* shapeOutOptional, double* tensionOutOptional, bool* selectedOutOptional)
{
    return GetEnvelopePointEx(envelope, autoitem_idx, ptidx, timeOutOptional, valueOutOptional, shapeOutOptional, tensionOutOptional, selectedOutOptional);
}

int GetEnvelopeScalingModeWrapper(TrackEnvelope* env)
{
    return GetEnvelopeScalingMode(env);
}

bool GetEnvelopeStateChunkWrapper(TrackEnvelope* env, char* strNeedBig, int strNeedBig_sz, bool isundoOptional)
{
    return GetEnvelopeStateChunk(env, strNeedBig, strNeedBig_sz, isundoOptional);
}

const char* GetExePathWrapper()
{
    return GetExePath();
}

const char* GetExtStateWrapper(const char* section, const char* key)
{
    return GetExtState(section, key);
}

int GetFocusedFXWrapper(int* tracknumberOut, int* itemnumberOut, int* fxnumberOut)
{
    return GetFocusedFX(tracknumberOut, itemnumberOut, fxnumberOut);
}

int GetFocusedFX2Wrapper(int* tracknumberOut, int* itemnumberOut, int* fxnumberOut)
{
    return GetFocusedFX2(tracknumberOut, itemnumberOut, fxnumberOut);
}

int GetFreeDiskSpaceForRecordPathWrapper(ReaProject* proj, int pathidx)
{
    return GetFreeDiskSpaceForRecordPath(proj, pathidx);
}

TrackEnvelope* GetFXEnvelopeWrapper(MediaTrack* track, int fxindex, int parameterindex, bool create)
{
    return GetFXEnvelope(track, fxindex, parameterindex, create);
}

int GetGlobalAutomationOverrideWrapper()
{
    return GetGlobalAutomationOverride();
}

double GetHZoomLevelWrapper()
{
    return GetHZoomLevel();
}

void* GetIconThemePointerWrapper(const char* name)
{
    return GetIconThemePointer(name);
}

void* GetIconThemePointerForDPIWrapper(const char* name, int dpisc)
{
    return GetIconThemePointerForDPI(name, dpisc);
}

void* GetIconThemeStructWrapper(int* szOut)
{
    return GetIconThemeStruct(szOut);
}

const char* GetInputChannelNameWrapper(int channelIndex)
{
    return GetInputChannelName(channelIndex);
}

void GetInputOutputLatencyWrapper(int* inputlatencyOut, int* outputLatencyOut)
{
    return GetInputOutputLatency(inputlatencyOut, outputLatencyOut);
}

double GetItemEditingTime2Wrapper(PCM_source** which_itemOut, int* flagsOut)
{
    return GetItemEditingTime2(which_itemOut, flagsOut);
}

MediaItem* GetItemFromPointWrapper(int screen_x, int screen_y, bool allow_locked, MediaItem_Take** takeOutOptional)
{
    return GetItemFromPoint(screen_x, screen_y, allow_locked, takeOutOptional);
}

ReaProject* GetItemProjectContextWrapper(MediaItem* item)
{
    return GetItemProjectContext(item);
}

bool GetItemStateChunkWrapper(MediaItem* item, char* strNeedBig, int strNeedBig_sz, bool isundoOptional)
{
    return GetItemStateChunk(item, strNeedBig, strNeedBig_sz, isundoOptional);
}

const char* GetLastColorThemeFileWrapper()
{
    return GetLastColorThemeFile();
}

void GetLastMarkerAndCurRegionWrapper(ReaProject* proj, double time, int* markeridxOut, int* regionidxOut)
{
    return GetLastMarkerAndCurRegion(proj, time, markeridxOut, regionidxOut);
}

bool GetLastTouchedFXWrapper(int* tracknumberOut, int* fxnumberOut, int* paramnumberOut)
{
    return GetLastTouchedFX(tracknumberOut, fxnumberOut, paramnumberOut);
}

MediaTrack* GetLastTouchedTrackWrapper()
{
    return GetLastTouchedTrack();
}

HWND GetMainHwndWrapper()
{
    return GetMainHwnd();
}

int GetMasterMuteSoloFlagsWrapper()
{
    return GetMasterMuteSoloFlags();
}

MediaTrack* GetMasterTrackWrapper(ReaProject* proj)
{
    return GetMasterTrack(proj);
}

int GetMasterTrackVisibilityWrapper()
{
    return GetMasterTrackVisibility();
}

int GetMaxMidiInputsWrapper()
{
    return GetMaxMidiInputs();
}

int GetMaxMidiOutputsWrapper()
{
    return GetMaxMidiOutputs();
}

int GetMediaFileMetadataWrapper(PCM_source* mediaSource, const char* identifier, char* bufOutNeedBig, int bufOutNeedBig_sz)
{
    return GetMediaFileMetadata(mediaSource, identifier, bufOutNeedBig, bufOutNeedBig_sz);
}

MediaItem* GetMediaItemWrapper(ReaProject* proj, int itemidx)
{
    return GetMediaItem(proj, itemidx);
}

MediaTrack* GetMediaItem_TrackWrapper(MediaItem* item)
{
    return GetMediaItem_Track(item);
}

double GetMediaItemInfo_ValueWrapper(MediaItem* item, const char* parmname)
{
    return GetMediaItemInfo_Value(item, parmname);
}

int GetMediaItemNumTakesWrapper(MediaItem* item)
{
    return GetMediaItemNumTakes(item);
}

MediaItem_Take* GetMediaItemTakeWrapper(MediaItem* item, int tk)
{
    return GetMediaItemTake(item, tk);
}

MediaItem* GetMediaItemTake_ItemWrapper(MediaItem_Take* take)
{
    return GetMediaItemTake_Item(take);
}

int GetMediaItemTake_PeaksWrapper(MediaItem_Take* take, double peakrate, double starttime, int numchannels, int numsamplesperchannel, int want_extra_type, double* buf)
{
    return GetMediaItemTake_Peaks(take, peakrate, starttime, numchannels, numsamplesperchannel, want_extra_type, buf);
}

PCM_source* GetMediaItemTake_SourceWrapper(MediaItem_Take* take)
{
    return GetMediaItemTake_Source(take);
}

MediaTrack* GetMediaItemTake_TrackWrapper(MediaItem_Take* take)
{
    return GetMediaItemTake_Track(take);
}

MediaItem_Take* GetMediaItemTakeByGUIDWrapper(ReaProject* project, const GUID* guid)
{
    return GetMediaItemTakeByGUID(project, guid);
}

double GetMediaItemTakeInfo_ValueWrapper(MediaItem_Take* take, const char* parmname)
{
    return GetMediaItemTakeInfo_Value(take, parmname);
}

MediaTrack* GetMediaItemTrackWrapper(MediaItem* item)
{
    return GetMediaItemTrack(item);
}

void GetMediaSourceFileNameWrapper(PCM_source* source, char* filenamebuf, int filenamebuf_sz)
{
    return GetMediaSourceFileName(source, filenamebuf, filenamebuf_sz);
}

double GetMediaSourceLengthWrapper(PCM_source* source, bool* lengthIsQNOut)
{
    return GetMediaSourceLength(source, lengthIsQNOut);
}

int GetMediaSourceNumChannelsWrapper(PCM_source* source)
{
    return GetMediaSourceNumChannels(source);
}

PCM_source* GetMediaSourceParentWrapper(PCM_source* src)
{
    return GetMediaSourceParent(src);
}

int GetMediaSourceSampleRateWrapper(PCM_source* source)
{
    return GetMediaSourceSampleRate(source);
}

void GetMediaSourceTypeWrapper(PCM_source* source, char* typebuf, int typebuf_sz)
{
    return GetMediaSourceType(source, typebuf, typebuf_sz);
}

double GetMediaTrackInfo_ValueWrapper(MediaTrack* tr, const char* parmname)
{
    return GetMediaTrackInfo_Value(tr, parmname);
}

bool GetMIDIInputNameWrapper(int dev, char* nameout, int nameout_sz)
{
    return GetMIDIInputName(dev, nameout, nameout_sz);
}

bool GetMIDIOutputNameWrapper(int dev, char* nameout, int nameout_sz)
{
    return GetMIDIOutputName(dev, nameout, nameout_sz);
}

MediaTrack* GetMixerScrollWrapper()
{
    return GetMixerScroll();
}

void GetMouseModifierWrapper(const char* context, int modifier_flag, char* action, int action_sz)
{
    return GetMouseModifier(context, modifier_flag, action, action_sz);
}

void GetMousePositionWrapper(int* xOut, int* yOut)
{
    return GetMousePosition(xOut, yOut);
}

int GetNumAudioInputsWrapper()
{
    return GetNumAudioInputs();
}

int GetNumAudioOutputsWrapper()
{
    return GetNumAudioOutputs();
}

int GetNumMIDIInputsWrapper()
{
    return GetNumMIDIInputs();
}

int GetNumMIDIOutputsWrapper()
{
    return GetNumMIDIOutputs();
}

int GetNumTakeMarkersWrapper(MediaItem_Take* take)
{
    return GetNumTakeMarkers(take);
}

int GetNumTracksWrapper()
{
    return GetNumTracks();
}

const char* GetOSWrapper()
{
    return GetOS();
}

const char* GetOutputChannelNameWrapper(int channelIndex)
{
    return GetOutputChannelName(channelIndex);
}

double GetOutputLatencyWrapper()
{
    return GetOutputLatency();
}

MediaTrack* GetParentTrackWrapper(MediaTrack* track)
{
    return GetParentTrack(track);
}

void GetPeakFileNameWrapper(const char* fn, char* buf, int buf_sz)
{
    return GetPeakFileName(fn, buf, buf_sz);
}

void GetPeakFileNameExWrapper(const char* fn, char* buf, int buf_sz, bool forWrite)
{
    return GetPeakFileNameEx(fn, buf, buf_sz, forWrite);
}

void GetPeakFileNameEx2Wrapper(const char* fn, char* buf, int buf_sz, bool forWrite, const char* peaksfileextension)
{
    return GetPeakFileNameEx2(fn, buf, buf_sz, forWrite, peaksfileextension);
}

void* GetPeaksBitmapWrapper(PCM_source_peaktransfer_t* pks, double maxamp, int w, int h, LICE_IBitmap* bmp)
{
    return GetPeaksBitmap(pks, maxamp, w, h, bmp);
}

double GetPlayPositionWrapper()
{
    return GetPlayPosition();
}

double GetPlayPosition2Wrapper()
{
    return GetPlayPosition2();
}

double GetPlayPosition2ExWrapper(ReaProject* proj)
{
    return GetPlayPosition2Ex(proj);
}

double GetPlayPositionExWrapper(ReaProject* proj)
{
    return GetPlayPositionEx(proj);
}

int GetPlayStateWrapper()
{
    return GetPlayState();
}

int GetPlayStateExWrapper(ReaProject* proj)
{
    return GetPlayStateEx(proj);
}

void GetPreferredDiskReadModeWrapper(int* mode, int* nb, int* bs)
{
    return GetPreferredDiskReadMode(mode, nb, bs);
}

void GetPreferredDiskReadModePeakWrapper(int* mode, int* nb, int* bs)
{
    return GetPreferredDiskReadModePeak(mode, nb, bs);
}

void GetPreferredDiskWriteModeWrapper(int* mode, int* nb, int* bs)
{
    return GetPreferredDiskWriteMode(mode, nb, bs);
}

double GetProjectLengthWrapper(ReaProject* proj)
{
    return GetProjectLength(proj);
}

void GetProjectNameWrapper(ReaProject* proj, char* buf, int buf_sz)
{
    return GetProjectName(proj, buf, buf_sz);
}

void GetProjectPathWrapper(char* buf, int buf_sz)
{
    return GetProjectPath(buf, buf_sz);
}

void GetProjectPathExWrapper(ReaProject* proj, char* buf, int buf_sz)
{
    return GetProjectPathEx(proj, buf, buf_sz);
}

int GetProjectStateChangeCountWrapper(ReaProject* proj)
{
    return GetProjectStateChangeCount(proj);
}

double GetProjectTimeOffsetWrapper(ReaProject* proj, bool rndframe)
{
    return GetProjectTimeOffset(proj, rndframe);
}

void GetProjectTimeSignatureWrapper(double* bpmOut, double* bpiOut)
{
    return GetProjectTimeSignature(bpmOut, bpiOut);
}

void GetProjectTimeSignature2Wrapper(ReaProject* proj, double* bpmOut, double* bpiOut)
{
    return GetProjectTimeSignature2(proj, bpmOut, bpiOut);
}

int GetProjExtStateWrapper(ReaProject* proj, const char* extname, const char* key, char* valOutNeedBig, int valOutNeedBig_sz)
{
    return GetProjExtState(proj, extname, key, valOutNeedBig, valOutNeedBig_sz);
}

const char* GetResourcePathWrapper()
{
    return GetResourcePath();
}

TrackEnvelope* GetSelectedEnvelopeWrapper(ReaProject* proj)
{
    return GetSelectedEnvelope(proj);
}

MediaItem* GetSelectedMediaItemWrapper(ReaProject* proj, int selitem)
{
    return GetSelectedMediaItem(proj, selitem);
}

MediaTrack* GetSelectedTrackWrapper(ReaProject* proj, int seltrackidx)
{
    return GetSelectedTrack(proj, seltrackidx);
}

MediaTrack* GetSelectedTrack2Wrapper(ReaProject* proj, int seltrackidx, bool wantmaster)
{
    return GetSelectedTrack2(proj, seltrackidx, wantmaster);
}

TrackEnvelope* GetSelectedTrackEnvelopeWrapper(ReaProject* proj)
{
    return GetSelectedTrackEnvelope(proj);
}

void GetSet_ArrangeView2Wrapper(ReaProject* proj, bool isSet, int screen_x_start, int screen_x_end, double* start_timeOut, double* end_timeOut)
{
    return GetSet_ArrangeView2(proj, isSet, screen_x_start, screen_x_end, start_timeOut, end_timeOut);
}

void GetSet_LoopTimeRangeWrapper(bool isSet, bool isLoop, double* startOut, double* endOut, bool allowautoseek)
{
    return GetSet_LoopTimeRange(isSet, isLoop, startOut, endOut, allowautoseek);
}

void GetSet_LoopTimeRange2Wrapper(ReaProject* proj, bool isSet, bool isLoop, double* startOut, double* endOut, bool allowautoseek)
{
    return GetSet_LoopTimeRange2(proj, isSet, isLoop, startOut, endOut, allowautoseek);
}

double GetSetAutomationItemInfoWrapper(TrackEnvelope* env, int autoitem_idx, const char* desc, double value, bool is_set)
{
    return GetSetAutomationItemInfo(env, autoitem_idx, desc, value, is_set);
}

bool GetSetAutomationItemInfo_StringWrapper(TrackEnvelope* env, int autoitem_idx, const char* desc, char* valuestrNeedBig, bool is_set)
{
    return GetSetAutomationItemInfo_String(env, autoitem_idx, desc, valuestrNeedBig, is_set);
}

bool GetSetEnvelopeInfo_StringWrapper(TrackEnvelope* env, const char* parmname, char* stringNeedBig, bool setNewValue)
{
    return GetSetEnvelopeInfo_String(env, parmname, stringNeedBig, setNewValue);
}

bool GetSetEnvelopeStateWrapper(TrackEnvelope* env, char* str, int str_sz)
{
    return GetSetEnvelopeState(env, str, str_sz);
}

bool GetSetEnvelopeState2Wrapper(TrackEnvelope* env, char* str, int str_sz, bool isundo)
{
    return GetSetEnvelopeState2(env, str, str_sz, isundo);
}

bool GetSetItemStateWrapper(MediaItem* item, char* str, int str_sz)
{
    return GetSetItemState(item, str, str_sz);
}

bool GetSetItemState2Wrapper(MediaItem* item, char* str, int str_sz, bool isundo)
{
    return GetSetItemState2(item, str, str_sz, isundo);
}

void* GetSetMediaItemInfoWrapper(MediaItem* item, const char* parmname, void* setNewValue)
{
    return GetSetMediaItemInfo(item, parmname, setNewValue);
}

bool GetSetMediaItemInfo_StringWrapper(MediaItem* item, const char* parmname, char* stringNeedBig, bool setNewValue)
{
    return GetSetMediaItemInfo_String(item, parmname, stringNeedBig, setNewValue);
}

void* GetSetMediaItemTakeInfoWrapper(MediaItem_Take* tk, const char* parmname, void* setNewValue)
{
    return GetSetMediaItemTakeInfo(tk, parmname, setNewValue);
}

bool GetSetMediaItemTakeInfo_StringWrapper(MediaItem_Take* tk, const char* parmname, char* stringNeedBig, bool setNewValue)
{
    return GetSetMediaItemTakeInfo_String(tk, parmname, stringNeedBig, setNewValue);
}

void* GetSetMediaTrackInfoWrapper(MediaTrack* tr, const char* parmname, void* setNewValue)
{
    return GetSetMediaTrackInfo(tr, parmname, setNewValue);
}

bool GetSetMediaTrackInfo_StringWrapper(MediaTrack* tr, const char* parmname, char* stringNeedBig, bool setNewValue)
{
    return GetSetMediaTrackInfo_String(tr, parmname, stringNeedBig, setNewValue);
}

char* GetSetObjectStateWrapper(void* obj, const char* str)
{
    return GetSetObjectState(obj, str);
}

char* GetSetObjectState2Wrapper(void* obj, const char* str, bool isundo)
{
    return GetSetObjectState2(obj, str, isundo);
}

void GetSetProjectAuthorWrapper(ReaProject* proj, bool set, char* author, int author_sz)
{
    return GetSetProjectAuthor(proj, set, author, author_sz);
}

int GetSetProjectGridWrapper(ReaProject* project, bool set, double* divisionInOutOptional, int* swingmodeInOutOptional, double* swingamtInOutOptional)
{
    return GetSetProjectGrid(project, set, divisionInOutOptional, swingmodeInOutOptional, swingamtInOutOptional);
}

double GetSetProjectInfoWrapper(ReaProject* project, const char* desc, double value, bool is_set)
{
    return GetSetProjectInfo(project, desc, value, is_set);
}

bool GetSetProjectInfo_StringWrapper(ReaProject* project, const char* desc, char* valuestrNeedBig, bool is_set)
{
    return GetSetProjectInfo_String(project, desc, valuestrNeedBig, is_set);
}

void GetSetProjectNotesWrapper(ReaProject* proj, bool set, char* notesNeedBig, int notesNeedBig_sz)
{
    return GetSetProjectNotes(proj, set, notesNeedBig, notesNeedBig_sz);
}

int GetSetRepeatWrapper(int val)
{
    return GetSetRepeat(val);
}

int GetSetRepeatExWrapper(ReaProject* proj, int val)
{
    return GetSetRepeatEx(proj, val);
}

unsigned int GetSetTrackGroupMembershipWrapper(MediaTrack* tr, const char* groupname, unsigned int setmask, unsigned int setvalue)
{
    return GetSetTrackGroupMembership(tr, groupname, setmask, setvalue);
}

unsigned int GetSetTrackGroupMembershipHighWrapper(MediaTrack* tr, const char* groupname, unsigned int setmask, unsigned int setvalue)
{
    return GetSetTrackGroupMembershipHigh(tr, groupname, setmask, setvalue);
}

const char* GetSetTrackMIDISupportFileWrapper(ReaProject* proj, MediaTrack* track, int which, const char* filename)
{
    return GetSetTrackMIDISupportFile(proj, track, which, filename);
}

void* GetSetTrackSendInfoWrapper(MediaTrack* tr, int category, int sendidx, const char* parmname, void* setNewValue)
{
    return GetSetTrackSendInfo(tr, category, sendidx, parmname, setNewValue);
}

bool GetSetTrackSendInfo_StringWrapper(MediaTrack* tr, int category, int sendidx, const char* parmname, char* stringNeedBig, bool setNewValue)
{
    return GetSetTrackSendInfo_String(tr, category, sendidx, parmname, stringNeedBig, setNewValue);
}

bool GetSetTrackStateWrapper(MediaTrack* track, char* str, int str_sz)
{
    return GetSetTrackState(track, str, str_sz);
}

bool GetSetTrackState2Wrapper(MediaTrack* track, char* str, int str_sz, bool isundo)
{
    return GetSetTrackState2(track, str, str_sz, isundo);
}

ReaProject* GetSubProjectFromSourceWrapper(PCM_source* src)
{
    return GetSubProjectFromSource(src);
}

MediaItem_Take* GetTakeWrapper(MediaItem* item, int takeidx)
{
    return GetTake(item, takeidx);
}

TrackEnvelope* GetTakeEnvelopeWrapper(MediaItem_Take* take, int envidx)
{
    return GetTakeEnvelope(take, envidx);
}

TrackEnvelope* GetTakeEnvelopeByNameWrapper(MediaItem_Take* take, const char* envname)
{
    return GetTakeEnvelopeByName(take, envname);
}

double GetTakeMarkerWrapper(MediaItem_Take* take, int idx, char* nameOut, int nameOut_sz, int* colorOutOptional)
{
    return GetTakeMarker(take, idx, nameOut, nameOut_sz, colorOutOptional);
}

const char* GetTakeNameWrapper(MediaItem_Take* take)
{
    return GetTakeName(take);
}

int GetTakeNumStretchMarkersWrapper(MediaItem_Take* take)
{
    return GetTakeNumStretchMarkers(take);
}

int GetTakeStretchMarkerWrapper(MediaItem_Take* take, int idx, double* posOut, double* srcposOutOptional)
{
    return GetTakeStretchMarker(take, idx, posOut, srcposOutOptional);
}

double GetTakeStretchMarkerSlopeWrapper(MediaItem_Take* take, int idx)
{
    return GetTakeStretchMarkerSlope(take, idx);
}

bool GetTCPFXParmWrapper(ReaProject* project, MediaTrack* track, int index, int* fxindexOut, int* parmidxOut)
{
    return GetTCPFXParm(project, track, index, fxindexOut, parmidxOut);
}

bool GetTempoMatchPlayRateWrapper(PCM_source* source, double srcscale, double position, double mult, double* rateOut, double* targetlenOut)
{
    return GetTempoMatchPlayRate(source, srcscale, position, mult, rateOut, targetlenOut);
}

bool GetTempoTimeSigMarkerWrapper(ReaProject* proj, int ptidx, double* timeposOut, int* measureposOut, double* beatposOut, double* bpmOut, int* timesig_numOut, int* timesig_denomOut, bool* lineartempoOut)
{
    return GetTempoTimeSigMarker(proj, ptidx, timeposOut, measureposOut, beatposOut, bpmOut, timesig_numOut, timesig_denomOut, lineartempoOut);
}

int GetThemeColorWrapper(const char* ini_key, int flagsOptional)
{
    return GetThemeColor(ini_key, flagsOptional);
}

int GetToggleCommandStateWrapper(int command_id)
{
    return GetToggleCommandState(command_id);
}

int GetToggleCommandState2Wrapper(KbdSectionInfo* section, int command_id)
{
    return GetToggleCommandState2(section, command_id);
}

int GetToggleCommandStateExWrapper(int section_id, int command_id)
{
    return GetToggleCommandStateEx(section_id, command_id);
}

int GetToggleCommandStateThroughHooksWrapper(KbdSectionInfo* section, int command_id)
{
    return GetToggleCommandStateThroughHooks(section, command_id);
}

HWND GetTooltipWindowWrapper()
{
    return GetTooltipWindow();
}

MediaTrack* GetTrackWrapper(ReaProject* proj, int trackidx)
{
    return GetTrack(proj, trackidx);
}

int GetTrackAutomationModeWrapper(MediaTrack* tr)
{
    return GetTrackAutomationMode(tr);
}

int GetTrackColorWrapper(MediaTrack* track)
{
    return GetTrackColor(track);
}

int GetTrackDepthWrapper(MediaTrack* track)
{
    return GetTrackDepth(track);
}

TrackEnvelope* GetTrackEnvelopeWrapper(MediaTrack* track, int envidx)
{
    return GetTrackEnvelope(track, envidx);
}

TrackEnvelope* GetTrackEnvelopeByChunkNameWrapper(MediaTrack* tr, const char* cfgchunkname)
{
    return GetTrackEnvelopeByChunkName(tr, cfgchunkname);
}

TrackEnvelope* GetTrackEnvelopeByNameWrapper(MediaTrack* track, const char* envname)
{
    return GetTrackEnvelopeByName(track, envname);
}

MediaTrack* GetTrackFromPointWrapper(int screen_x, int screen_y, int* infoOutOptional)
{
    return GetTrackFromPoint(screen_x, screen_y, infoOutOptional);
}

GUID* GetTrackGUIDWrapper(MediaTrack* tr)
{
    return GetTrackGUID(tr);
}

const char* GetTrackInfoWrapper(INT_PTR track, int* flags)
{
    return GetTrackInfo(track, flags);
}

MediaItem* GetTrackMediaItemWrapper(MediaTrack* tr, int itemidx)
{
    return GetTrackMediaItem(tr, itemidx);
}

bool GetTrackMIDILyricsWrapper(MediaTrack* track, int flag, char* bufWantNeedBig, int* bufWantNeedBig_sz)
{
    return GetTrackMIDILyrics(track, flag, bufWantNeedBig, bufWantNeedBig_sz);
}

const char* GetTrackMIDINoteNameWrapper(int track, int pitch, int chan)
{
    return GetTrackMIDINoteName(track, pitch, chan);
}

const char* GetTrackMIDINoteNameExWrapper(ReaProject* proj, MediaTrack* track, int pitch, int chan)
{
    return GetTrackMIDINoteNameEx(proj, track, pitch, chan);
}

void GetTrackMIDINoteRangeWrapper(ReaProject* proj, MediaTrack* track, int* note_loOut, int* note_hiOut)
{
    return GetTrackMIDINoteRange(proj, track, note_loOut, note_hiOut);
}

bool GetTrackNameWrapper(MediaTrack* track, char* bufOut, int bufOut_sz)
{
    return GetTrackName(track, bufOut, bufOut_sz);
}

int GetTrackNumMediaItemsWrapper(MediaTrack* tr)
{
    return GetTrackNumMediaItems(tr);
}

int GetTrackNumSendsWrapper(MediaTrack* tr, int category)
{
    return GetTrackNumSends(tr, category);
}

bool GetTrackReceiveNameWrapper(MediaTrack* track, int recv_index, char* buf, int buf_sz)
{
    return GetTrackReceiveName(track, recv_index, buf, buf_sz);
}

bool GetTrackReceiveUIMuteWrapper(MediaTrack* track, int recv_index, bool* muteOut)
{
    return GetTrackReceiveUIMute(track, recv_index, muteOut);
}

bool GetTrackReceiveUIVolPanWrapper(MediaTrack* track, int recv_index, double* volumeOut, double* panOut)
{
    return GetTrackReceiveUIVolPan(track, recv_index, volumeOut, panOut);
}

double GetTrackSendInfo_ValueWrapper(MediaTrack* tr, int category, int sendidx, const char* parmname)
{
    return GetTrackSendInfo_Value(tr, category, sendidx, parmname);
}

bool GetTrackSendNameWrapper(MediaTrack* track, int send_index, char* buf, int buf_sz)
{
    return GetTrackSendName(track, send_index, buf, buf_sz);
}

bool GetTrackSendUIMuteWrapper(MediaTrack* track, int send_index, bool* muteOut)
{
    return GetTrackSendUIMute(track, send_index, muteOut);
}

bool GetTrackSendUIVolPanWrapper(MediaTrack* track, int send_index, double* volumeOut, double* panOut)
{
    return GetTrackSendUIVolPan(track, send_index, volumeOut, panOut);
}

const char* GetTrackStateWrapper(MediaTrack* track, int* flagsOut)
{
    return GetTrackState(track, flagsOut);
}

bool GetTrackStateChunkWrapper(MediaTrack* track, char* strNeedBig, int strNeedBig_sz, bool isundoOptional)
{
    return GetTrackStateChunk(track, strNeedBig, strNeedBig_sz, isundoOptional);
}

bool GetTrackUIMuteWrapper(MediaTrack* track, bool* muteOut)
{
    return GetTrackUIMute(track, muteOut);
}

bool GetTrackUIPanWrapper(MediaTrack* track, double* pan1Out, double* pan2Out, int* panmodeOut)
{
    return GetTrackUIPan(track, pan1Out, pan2Out, panmodeOut);
}

bool GetTrackUIVolPanWrapper(MediaTrack* track, double* volumeOut, double* panOut)
{
    return GetTrackUIVolPan(track, volumeOut, panOut);
}

void GetUnderrunTimeWrapper(unsigned int* audio_xrunOutOptional, unsigned int* media_xrunOutOptional, unsigned int* curtimeOutOptional)
{
    return GetUnderrunTime(audio_xrunOutOptional, media_xrunOutOptional, curtimeOutOptional);
}

bool GetUserFileNameForReadWrapper(char* filenameNeed4096, const char* title, const char* defext)
{
    return GetUserFileNameForRead(filenameNeed4096, title, defext);
}

bool GetUserInputsWrapper(const char* title, int num_inputs, const char* captions_csv, char* retvals_csv, int retvals_csv_sz)
{
    return GetUserInputs(title, num_inputs, captions_csv, retvals_csv, retvals_csv_sz);
}

void GoToMarkerWrapper(ReaProject* proj, int marker_index, bool use_timeline_order)
{
    return GoToMarker(proj, marker_index, use_timeline_order);
}

void GoToRegionWrapper(ReaProject* proj, int region_index, bool use_timeline_order)
{
    return GoToRegion(proj, region_index, use_timeline_order);
}

int GR_SelectColorWrapper(HWND hwnd, int* colorOut)
{
    return GR_SelectColor(hwnd, colorOut);
}

int GSC_mainwndWrapper(int t)
{
    return GSC_mainwnd(t);
}

void guidToStringWrapper(const GUID* g, char* destNeed64)
{
    return guidToString(g, destNeed64);
}

bool HasExtStateWrapper(const char* section, const char* key)
{
    return HasExtState(section, key);
}

const char* HasTrackMIDIProgramsWrapper(int track)
{
    return HasTrackMIDIPrograms(track);
}

const char* HasTrackMIDIProgramsExWrapper(ReaProject* proj, MediaTrack* track)
{
    return HasTrackMIDIProgramsEx(proj, track);
}

void Help_SetWrapper(const char* helpstring, bool is_temporary_help)
{
    return Help_Set(helpstring, is_temporary_help);
}

void HiresPeaksFromSourceWrapper(PCM_source* src, PCM_source_peaktransfer_t* block)
{
    return HiresPeaksFromSource(src, block);
}

void image_resolve_fnWrapper(const char* in, char* out, int out_sz)
{
    return image_resolve_fn(in, out, out_sz);
}

int InsertAutomationItemWrapper(TrackEnvelope* env, int pool_id, double position, double length)
{
    return InsertAutomationItem(env, pool_id, position, length);
}

bool InsertEnvelopePointWrapper(TrackEnvelope* envelope, double time, double value, int shape, double tension, bool selected, bool* noSortInOptional)
{
    return InsertEnvelopePoint(envelope, time, value, shape, tension, selected, noSortInOptional);
}

bool InsertEnvelopePointExWrapper(TrackEnvelope* envelope, int autoitem_idx, double time, double value, int shape, double tension, bool selected, bool* noSortInOptional)
{
    return InsertEnvelopePointEx(envelope, autoitem_idx, time, value, shape, tension, selected, noSortInOptional);
}

int InsertMediaWrapper(const char* file, int mode)
{
    return InsertMedia(file, mode);
}

int InsertMediaSectionWrapper(const char* file, int mode, double startpct, double endpct, double pitchshift)
{
    return InsertMediaSection(file, mode, startpct, endpct, pitchshift);
}

void InsertTrackAtIndexWrapper(int idx, bool wantDefaults)
{
    return InsertTrackAtIndex(idx, wantDefaults);
}

int IsInRealTimeAudioWrapper()
{
    return IsInRealTimeAudio();
}

bool IsItemTakeActiveForPlaybackWrapper(MediaItem* item, MediaItem_Take* take)
{
    return IsItemTakeActiveForPlayback(item, take);
}

bool IsMediaExtensionWrapper(const char* ext, bool wantOthers)
{
    return IsMediaExtension(ext, wantOthers);
}

bool IsMediaItemSelectedWrapper(MediaItem* item)
{
    return IsMediaItemSelected(item);
}

int IsProjectDirtyWrapper(ReaProject* proj)
{
    return IsProjectDirty(proj);
}

bool IsREAPERWrapper()
{
    return IsREAPER();
}

bool IsTrackSelectedWrapper(MediaTrack* track)
{
    return IsTrackSelected(track);
}

bool IsTrackVisibleWrapper(MediaTrack* track, bool mixer)
{
    return IsTrackVisible(track, mixer);
}

joystick_device* joystick_createWrapper(const GUID* guid)
{
    return joystick_create(guid);
}

void joystick_destroyWrapper(joystick_device* device)
{
    return joystick_destroy(device);
}

const char* joystick_enumWrapper(int index, const char** namestrOutOptional)
{
    return joystick_enum(index, namestrOutOptional);
}

double joystick_getaxisWrapper(joystick_device* dev, int axis)
{
    return joystick_getaxis(dev, axis);
}

unsigned int joystick_getbuttonmaskWrapper(joystick_device* dev)
{
    return joystick_getbuttonmask(dev);
}

int joystick_getinfoWrapper(joystick_device* dev, int* axesOutOptional, int* povsOutOptional)
{
    return joystick_getinfo(dev, axesOutOptional, povsOutOptional);
}

double joystick_getpovWrapper(joystick_device* dev, int pov)
{
    return joystick_getpov(dev, pov);
}

bool joystick_updateWrapper(joystick_device* dev)
{
    return joystick_update(dev);
}

int kbd_enumerateActionsWrapper(KbdSectionInfo* section, int idx, const char** nameOut)
{
    return kbd_enumerateActions(section, idx, nameOut);
}

void kbd_formatKeyNameWrapper(ACCEL* ac, char* s)
{
    return kbd_formatKeyName(ac, s);
}

void kbd_getCommandNameWrapper(int cmd, char* s, KbdSectionInfo* section)
{
    return kbd_getCommandName(cmd, s, section);
}

const char* kbd_getTextFromCmdWrapper(DWORD cmd, KbdSectionInfo* section)
{
    return kbd_getTextFromCmd(cmd, section);
}

int KBD_OnMainActionExWrapper(int cmd, int val, int valhw, int relmode, HWND hwnd, ReaProject* proj)
{
    return KBD_OnMainActionEx(cmd, val, valhw, relmode, hwnd, proj);
}

void kbd_OnMidiEventWrapper(MIDI_event_t* evt, int dev_index)
{
    return kbd_OnMidiEvent(evt, dev_index);
}

void kbd_OnMidiListWrapper(MIDI_eventlist* list, int dev_index)
{
    return kbd_OnMidiList(list, dev_index);
}

void kbd_ProcessActionsMenuWrapper(HMENU menu, KbdSectionInfo* section)
{
    return kbd_ProcessActionsMenu(menu, section);
}

bool kbd_processMidiEventActionExWrapper(MIDI_event_t* evt, KbdSectionInfo* section, HWND hwndCtx)
{
    return kbd_processMidiEventActionEx(evt, section, hwndCtx);
}

void kbd_reprocessMenuWrapper(HMENU menu, KbdSectionInfo* section)
{
    return kbd_reprocessMenu(menu, section);
}

bool kbd_RunCommandThroughHooksWrapper(KbdSectionInfo* section, int* actionCommandID, int* val, int* valhw, int* relmode, HWND hwnd)
{
    return kbd_RunCommandThroughHooks(section, actionCommandID, val, valhw, relmode, hwnd);
}

int kbd_translateAcceleratorWrapper(HWND hwnd, MSG* msg, KbdSectionInfo* section)
{
    return kbd_translateAccelerator(hwnd, msg, section);
}

bool kbd_translateMouseWrapper(void* winmsg, unsigned char* midimsg)
{
    return kbd_translateMouse(winmsg, midimsg);
}

void LICE__DestroyWrapper(LICE_IBitmap* bm)
{
    return LICE__Destroy(bm);
}

void LICE__DestroyFontWrapper(LICE_IFont* font)
{
    return LICE__DestroyFont(font);
}

int LICE__DrawTextWrapper(LICE_IFont* font, LICE_IBitmap* bm, const char* str, int strcnt, RECT* rect, UINT dtFlags)
{
    return LICE__DrawText(font, bm, str, strcnt, rect, dtFlags);
}

void* LICE__GetBitsWrapper(LICE_IBitmap* bm)
{
    return LICE__GetBits(bm);
}

HDC LICE__GetDCWrapper(LICE_IBitmap* bm)
{
    return LICE__GetDC(bm);
}

int LICE__GetHeightWrapper(LICE_IBitmap* bm)
{
    return LICE__GetHeight(bm);
}

int LICE__GetRowSpanWrapper(LICE_IBitmap* bm)
{
    return LICE__GetRowSpan(bm);
}

int LICE__GetWidthWrapper(LICE_IBitmap* bm)
{
    return LICE__GetWidth(bm);
}

bool LICE__IsFlippedWrapper(LICE_IBitmap* bm)
{
    return LICE__IsFlipped(bm);
}

bool LICE__resizeWrapper(LICE_IBitmap* bm, int w, int h)
{
    return LICE__resize(bm, w, h);
}

LICE_pixel LICE__SetBkColorWrapper(LICE_IFont* font, LICE_pixel color)
{
    return LICE__SetBkColor(font, color);
}

void LICE__SetFromHFontWrapper(LICE_IFont* font, HFONT hfont, int flags)
{
    return LICE__SetFromHFont(font, hfont, flags);
}

LICE_pixel LICE__SetTextColorWrapper(LICE_IFont* font, LICE_pixel color)
{
    return LICE__SetTextColor(font, color);
}

void LICE__SetTextCombineModeWrapper(LICE_IFont* ifont, int mode, float alpha)
{
    return LICE__SetTextCombineMode(ifont, mode, alpha);
}

void LICE_ArcWrapper(LICE_IBitmap* dest, float cx, float cy, float r, float minAngle, float maxAngle, LICE_pixel color, float alpha, int mode, bool aa)
{
    return LICE_Arc(dest, cx, cy, r, minAngle, maxAngle, color, alpha, mode, aa);
}

void LICE_BlitWrapper(LICE_IBitmap* dest, LICE_IBitmap* src, int dstx, int dsty, int srcx, int srcy, int srcw, int srch, float alpha, int mode)
{
    return LICE_Blit(dest, src, dstx, dsty, srcx, srcy, srcw, srch, alpha, mode);
}

void LICE_BlurWrapper(LICE_IBitmap* dest, LICE_IBitmap* src, int dstx, int dsty, int srcx, int srcy, int srcw, int srch)
{
    return LICE_Blur(dest, src, dstx, dsty, srcx, srcy, srcw, srch);
}

void LICE_BorderedRectWrapper(LICE_IBitmap* dest, int x, int y, int w, int h, LICE_pixel bgcolor, LICE_pixel fgcolor, float alpha, int mode)
{
    return LICE_BorderedRect(dest, x, y, w, h, bgcolor, fgcolor, alpha, mode);
}

void LICE_CircleWrapper(LICE_IBitmap* dest, float cx, float cy, float r, LICE_pixel color, float alpha, int mode, bool aa)
{
    return LICE_Circle(dest, cx, cy, r, color, alpha, mode, aa);
}

void LICE_ClearWrapper(LICE_IBitmap* dest, LICE_pixel color)
{
    return LICE_Clear(dest, color);
}

void LICE_ClearRectWrapper(LICE_IBitmap* dest, int x, int y, int w, int h, LICE_pixel mask, LICE_pixel orbits)
{
    return LICE_ClearRect(dest, x, y, w, h, mask, orbits);
}

bool LICE_ClipLineWrapper(int* pX1Out, int* pY1Out, int* pX2Out, int* pY2Out, int xLo, int yLo, int xHi, int yHi)
{
    return LICE_ClipLine(pX1Out, pY1Out, pX2Out, pY2Out, xLo, yLo, xHi, yHi);
}

void LICE_CopyWrapper(LICE_IBitmap* dest, LICE_IBitmap* src)
{
    return LICE_Copy(dest, src);
}

LICE_IBitmap* LICE_CreateBitmapWrapper(int mode, int w, int h)
{
    return LICE_CreateBitmap(mode, w, h);
}

LICE_IFont* LICE_CreateFontWrapper()
{
    return LICE_CreateFont();
}

void LICE_DrawCBezierWrapper(LICE_IBitmap* dest, double xstart, double ystart, double xctl1, double yctl1, double xctl2, double yctl2, double xend, double yend, LICE_pixel color, float alpha, int mode, bool aa, double tol)
{
    return LICE_DrawCBezier(dest, xstart, ystart, xctl1, yctl1, xctl2, yctl2, xend, yend, color, alpha, mode, aa, tol);
}

void LICE_DrawCharWrapper(LICE_IBitmap* bm, int x, int y, char c, LICE_pixel color, float alpha, int mode)
{
    return LICE_DrawChar(bm, x, y, c, color, alpha, mode);
}

void LICE_DrawGlyphWrapper(LICE_IBitmap* dest, int x, int y, LICE_pixel color, LICE_pixel_chan* alphas, int glyph_w, int glyph_h, float alpha, int mode)
{
    return LICE_DrawGlyph(dest, x, y, color, alphas, glyph_w, glyph_h, alpha, mode);
}

void LICE_DrawRectWrapper(LICE_IBitmap* dest, int x, int y, int w, int h, LICE_pixel color, float alpha, int mode)
{
    return LICE_DrawRect(dest, x, y, w, h, color, alpha, mode);
}

void LICE_DrawTextWrapper(LICE_IBitmap* bm, int x, int y, const char* string, LICE_pixel color, float alpha, int mode)
{
    return LICE_DrawText(bm, x, y, string, color, alpha, mode);
}

void LICE_FillCBezierWrapper(LICE_IBitmap* dest, double xstart, double ystart, double xctl1, double yctl1, double xctl2, double yctl2, double xend, double yend, int yfill, LICE_pixel color, float alpha, int mode, bool aa, double tol)
{
    return LICE_FillCBezier(dest, xstart, ystart, xctl1, yctl1, xctl2, yctl2, xend, yend, yfill, color, alpha, mode, aa, tol);
}

void LICE_FillCircleWrapper(LICE_IBitmap* dest, float cx, float cy, float r, LICE_pixel color, float alpha, int mode, bool aa)
{
    return LICE_FillCircle(dest, cx, cy, r, color, alpha, mode, aa);
}

void LICE_FillConvexPolygonWrapper(LICE_IBitmap* dest, int* x, int* y, int npoints, LICE_pixel color, float alpha, int mode)
{
    return LICE_FillConvexPolygon(dest, x, y, npoints, color, alpha, mode);
}

void LICE_FillRectWrapper(LICE_IBitmap* dest, int x, int y, int w, int h, LICE_pixel color, float alpha, int mode)
{
    return LICE_FillRect(dest, x, y, w, h, color, alpha, mode);
}

void LICE_FillTrapezoidWrapper(LICE_IBitmap* dest, int x1a, int x1b, int y1, int x2a, int x2b, int y2, LICE_pixel color, float alpha, int mode)
{
    return LICE_FillTrapezoid(dest, x1a, x1b, y1, x2a, x2b, y2, color, alpha, mode);
}

void LICE_FillTriangleWrapper(LICE_IBitmap* dest, int x1, int y1, int x2, int y2, int x3, int y3, LICE_pixel color, float alpha, int mode)
{
    return LICE_FillTriangle(dest, x1, y1, x2, y2, x3, y3, color, alpha, mode);
}

LICE_pixel LICE_GetPixelWrapper(LICE_IBitmap* bm, int x, int y)
{
    return LICE_GetPixel(bm, x, y);
}

void LICE_GradRectWrapper(LICE_IBitmap* dest, int dstx, int dsty, int dstw, int dsth, float ir, float ig, float ib, float ia, float drdx, float dgdx, float dbdx, float dadx, float drdy, float dgdy, float dbdy, float dady, int mode)
{
    return LICE_GradRect(dest, dstx, dsty, dstw, dsth, ir, ig, ib, ia, drdx, dgdx, dbdx, dadx, drdy, dgdy, dbdy, dady, mode);
}

void LICE_LineWrapper(LICE_IBitmap* dest, float x1, float y1, float x2, float y2, LICE_pixel color, float alpha, int mode, bool aa)
{
    return LICE_Line(dest, x1, y1, x2, y2, color, alpha, mode, aa);
}

void LICE_LineIntWrapper(LICE_IBitmap* dest, int x1, int y1, int x2, int y2, LICE_pixel color, float alpha, int mode, bool aa)
{
    return LICE_LineInt(dest, x1, y1, x2, y2, color, alpha, mode, aa);
}

LICE_IBitmap* LICE_LoadPNGWrapper(const char* filename, LICE_IBitmap* bmp)
{
    return LICE_LoadPNG(filename, bmp);
}

LICE_IBitmap* LICE_LoadPNGFromResourceWrapper(HINSTANCE hInst, const char* resid, LICE_IBitmap* bmp)
{
    return LICE_LoadPNGFromResource(hInst, resid, bmp);
}

void LICE_MeasureTextWrapper(const char* string, int* w, int* h)
{
    return LICE_MeasureText(string, w, h);
}

void LICE_MultiplyAddRectWrapper(LICE_IBitmap* dest, int x, int y, int w, int h, float rsc, float gsc, float bsc, float asc, float radd, float gadd, float badd, float aadd)
{
    return LICE_MultiplyAddRect(dest, x, y, w, h, rsc, gsc, bsc, asc, radd, gadd, badd, aadd);
}

void LICE_PutPixelWrapper(LICE_IBitmap* bm, int x, int y, LICE_pixel color, float alpha, int mode)
{
    return LICE_PutPixel(bm, x, y, color, alpha, mode);
}

void LICE_RotatedBlitWrapper(LICE_IBitmap* dest, LICE_IBitmap* src, int dstx, int dsty, int dstw, int dsth, float srcx, float srcy, float srcw, float srch, float angle, bool cliptosourcerect, float alpha, int mode, float rotxcent, float rotycent)
{
    return LICE_RotatedBlit(dest, src, dstx, dsty, dstw, dsth, srcx, srcy, srcw, srch, angle, cliptosourcerect, alpha, mode, rotxcent, rotycent);
}

void LICE_RoundRectWrapper(LICE_IBitmap* drawbm, float xpos, float ypos, float w, float h, int cornerradius, LICE_pixel col, float alpha, int mode, bool aa)
{
    return LICE_RoundRect(drawbm, xpos, ypos, w, h, cornerradius, col, alpha, mode, aa);
}

void LICE_ScaledBlitWrapper(LICE_IBitmap* dest, LICE_IBitmap* src, int dstx, int dsty, int dstw, int dsth, float srcx, float srcy, float srcw, float srch, float alpha, int mode)
{
    return LICE_ScaledBlit(dest, src, dstx, dsty, dstw, dsth, srcx, srcy, srcw, srch, alpha, mode);
}

void LICE_SimpleFillWrapper(LICE_IBitmap* dest, int x, int y, LICE_pixel newcolor, LICE_pixel comparemask, LICE_pixel keepmask)
{
    return LICE_SimpleFill(dest, x, y, newcolor, comparemask, keepmask);
}

const char* LocalizeStringWrapper(const char* src_string, const char* section, int flagsOptional)
{
    return LocalizeString(src_string, section, flagsOptional);
}

bool Loop_OnArrowWrapper(ReaProject* project, int direction)
{
    return Loop_OnArrow(project, direction);
}

void Main_OnCommandWrapper(int command, int flag)
{
    return Main_OnCommand(command, flag);
}

void Main_OnCommandExWrapper(int command, int flag, ReaProject* proj)
{
    return Main_OnCommandEx(command, flag, proj);
}

void Main_openProjectWrapper(const char* name)
{
    return Main_openProject(name);
}

void Main_SaveProjectWrapper(ReaProject* proj, bool forceSaveAsInOptional)
{
    return Main_SaveProject(proj, forceSaveAsInOptional);
}

void Main_UpdateLoopInfoWrapper(int ignoremask)
{
    return Main_UpdateLoopInfo(ignoremask);
}

void MarkProjectDirtyWrapper(ReaProject* proj)
{
    return MarkProjectDirty(proj);
}

void MarkTrackItemsDirtyWrapper(MediaTrack* track, MediaItem* item)
{
    return MarkTrackItemsDirty(track, item);
}

double Master_GetPlayRateWrapper(ReaProject* project)
{
    return Master_GetPlayRate(project);
}

double Master_GetPlayRateAtTimeWrapper(double time_s, ReaProject* proj)
{
    return Master_GetPlayRateAtTime(time_s, proj);
}

double Master_GetTempoWrapper()
{
    return Master_GetTempo();
}

double Master_NormalizePlayRateWrapper(double playrate, bool isnormalized)
{
    return Master_NormalizePlayRate(playrate, isnormalized);
}

double Master_NormalizeTempoWrapper(double bpm, bool isnormalized)
{
    return Master_NormalizeTempo(bpm, isnormalized);
}

int MBWrapper(const char* msg, const char* title, int type)
{
    return MB(msg, title, type);
}

int MediaItemDescendsFromTrackWrapper(MediaItem* item, MediaTrack* track)
{
    return MediaItemDescendsFromTrack(item, track);
}

int MIDI_CountEvtsWrapper(MediaItem_Take* take, int* notecntOut, int* ccevtcntOut, int* textsyxevtcntOut)
{
    return MIDI_CountEvts(take, notecntOut, ccevtcntOut, textsyxevtcntOut);
}

bool MIDI_DeleteCCWrapper(MediaItem_Take* take, int ccidx)
{
    return MIDI_DeleteCC(take, ccidx);
}

bool MIDI_DeleteEvtWrapper(MediaItem_Take* take, int evtidx)
{
    return MIDI_DeleteEvt(take, evtidx);
}

bool MIDI_DeleteNoteWrapper(MediaItem_Take* take, int noteidx)
{
    return MIDI_DeleteNote(take, noteidx);
}

bool MIDI_DeleteTextSysexEvtWrapper(MediaItem_Take* take, int textsyxevtidx)
{
    return MIDI_DeleteTextSysexEvt(take, textsyxevtidx);
}

void MIDI_DisableSortWrapper(MediaItem_Take* take)
{
    return MIDI_DisableSort(take);
}

int MIDI_EnumSelCCWrapper(MediaItem_Take* take, int ccidx)
{
    return MIDI_EnumSelCC(take, ccidx);
}

int MIDI_EnumSelEvtsWrapper(MediaItem_Take* take, int evtidx)
{
    return MIDI_EnumSelEvts(take, evtidx);
}

int MIDI_EnumSelNotesWrapper(MediaItem_Take* take, int noteidx)
{
    return MIDI_EnumSelNotes(take, noteidx);
}

int MIDI_EnumSelTextSysexEvtsWrapper(MediaItem_Take* take, int textsyxidx)
{
    return MIDI_EnumSelTextSysexEvts(take, textsyxidx);
}

MIDI_eventlist* MIDI_eventlist_CreateWrapper()
{
    return MIDI_eventlist_Create();
}

void MIDI_eventlist_DestroyWrapper(MIDI_eventlist* evtlist)
{
    return MIDI_eventlist_Destroy(evtlist);
}

bool MIDI_GetAllEvtsWrapper(MediaItem_Take* take, char* bufNeedBig, int* bufNeedBig_sz)
{
    return MIDI_GetAllEvts(take, bufNeedBig, bufNeedBig_sz);
}

bool MIDI_GetCCWrapper(MediaItem_Take* take, int ccidx, bool* selectedOut, bool* mutedOut, double* ppqposOut, int* chanmsgOut, int* chanOut, int* msg2Out, int* msg3Out)
{
    return MIDI_GetCC(take, ccidx, selectedOut, mutedOut, ppqposOut, chanmsgOut, chanOut, msg2Out, msg3Out);
}

bool MIDI_GetCCShapeWrapper(MediaItem_Take* take, int ccidx, int* shapeOut, double* beztensionOut)
{
    return MIDI_GetCCShape(take, ccidx, shapeOut, beztensionOut);
}

bool MIDI_GetEvtWrapper(MediaItem_Take* take, int evtidx, bool* selectedOut, bool* mutedOut, double* ppqposOut, char* msg, int* msg_sz)
{
    return MIDI_GetEvt(take, evtidx, selectedOut, mutedOut, ppqposOut, msg, msg_sz);
}

double MIDI_GetGridWrapper(MediaItem_Take* take, double* swingOutOptional, double* noteLenOutOptional)
{
    return MIDI_GetGrid(take, swingOutOptional, noteLenOutOptional);
}

bool MIDI_GetHashWrapper(MediaItem_Take* take, bool notesonly, char* hash, int hash_sz)
{
    return MIDI_GetHash(take, notesonly, hash, hash_sz);
}

bool MIDI_GetNoteWrapper(MediaItem_Take* take, int noteidx, bool* selectedOut, bool* mutedOut, double* startppqposOut, double* endppqposOut, int* chanOut, int* pitchOut, int* velOut)
{
    return MIDI_GetNote(take, noteidx, selectedOut, mutedOut, startppqposOut, endppqposOut, chanOut, pitchOut, velOut);
}

double MIDI_GetPPQPos_EndOfMeasureWrapper(MediaItem_Take* take, double ppqpos)
{
    return MIDI_GetPPQPos_EndOfMeasure(take, ppqpos);
}

double MIDI_GetPPQPos_StartOfMeasureWrapper(MediaItem_Take* take, double ppqpos)
{
    return MIDI_GetPPQPos_StartOfMeasure(take, ppqpos);
}

double MIDI_GetPPQPosFromProjQNWrapper(MediaItem_Take* take, double projqn)
{
    return MIDI_GetPPQPosFromProjQN(take, projqn);
}

double MIDI_GetPPQPosFromProjTimeWrapper(MediaItem_Take* take, double projtime)
{
    return MIDI_GetPPQPosFromProjTime(take, projtime);
}

double MIDI_GetProjQNFromPPQPosWrapper(MediaItem_Take* take, double ppqpos)
{
    return MIDI_GetProjQNFromPPQPos(take, ppqpos);
}

double MIDI_GetProjTimeFromPPQPosWrapper(MediaItem_Take* take, double ppqpos)
{
    return MIDI_GetProjTimeFromPPQPos(take, ppqpos);
}

bool MIDI_GetScaleWrapper(MediaItem_Take* take, int* rootOut, int* scaleOut, char* name, int name_sz)
{
    return MIDI_GetScale(take, rootOut, scaleOut, name, name_sz);
}

bool MIDI_GetTextSysexEvtWrapper(MediaItem_Take* take, int textsyxevtidx, bool* selectedOutOptional, bool* mutedOutOptional, double* ppqposOutOptional, int* typeOutOptional, char* msgOptional, int* msgOptional_sz)
{
    return MIDI_GetTextSysexEvt(take, textsyxevtidx, selectedOutOptional, mutedOutOptional, ppqposOutOptional, typeOutOptional, msgOptional, msgOptional_sz);
}

bool MIDI_GetTrackHashWrapper(MediaTrack* track, bool notesonly, char* hash, int hash_sz)
{
    return MIDI_GetTrackHash(track, notesonly, hash, hash_sz);
}

bool MIDI_InsertCCWrapper(MediaItem_Take* take, bool selected, bool muted, double ppqpos, int chanmsg, int chan, int msg2, int msg3)
{
    return MIDI_InsertCC(take, selected, muted, ppqpos, chanmsg, chan, msg2, msg3);
}

bool MIDI_InsertEvtWrapper(MediaItem_Take* take, bool selected, bool muted, double ppqpos, const char* bytestr, int bytestr_sz)
{
    return MIDI_InsertEvt(take, selected, muted, ppqpos, bytestr, bytestr_sz);
}

bool MIDI_InsertNoteWrapper(MediaItem_Take* take, bool selected, bool muted, double startppqpos, double endppqpos, int chan, int pitch, int vel, const bool* noSortInOptional)
{
    return MIDI_InsertNote(take, selected, muted, startppqpos, endppqpos, chan, pitch, vel, noSortInOptional);
}

bool MIDI_InsertTextSysexEvtWrapper(MediaItem_Take* take, bool selected, bool muted, double ppqpos, int type, const char* bytestr, int bytestr_sz)
{
    return MIDI_InsertTextSysexEvt(take, selected, muted, ppqpos, type, bytestr, bytestr_sz);
}

void midi_reinitWrapper()
{
    return midi_reinit();
}

void MIDI_SelectAllWrapper(MediaItem_Take* take, bool select)
{
    return MIDI_SelectAll(take, select);
}

bool MIDI_SetAllEvtsWrapper(MediaItem_Take* take, const char* buf, int buf_sz)
{
    return MIDI_SetAllEvts(take, buf, buf_sz);
}

bool MIDI_SetCCWrapper(MediaItem_Take* take, int ccidx, const bool* selectedInOptional, const bool* mutedInOptional, const double* ppqposInOptional, const int* chanmsgInOptional, const int* chanInOptional, const int* msg2InOptional, const int* msg3InOptional, const bool* noSortInOptional)
{
    return MIDI_SetCC(take, ccidx, selectedInOptional, mutedInOptional, ppqposInOptional, chanmsgInOptional, chanInOptional, msg2InOptional, msg3InOptional, noSortInOptional);
}

bool MIDI_SetCCShapeWrapper(MediaItem_Take* take, int ccidx, int shape, double beztension, const bool* noSortInOptional)
{
    return MIDI_SetCCShape(take, ccidx, shape, beztension, noSortInOptional);
}

bool MIDI_SetEvtWrapper(MediaItem_Take* take, int evtidx, const bool* selectedInOptional, const bool* mutedInOptional, const double* ppqposInOptional, const char* msgOptional, int msgOptional_sz, const bool* noSortInOptional)
{
    return MIDI_SetEvt(take, evtidx, selectedInOptional, mutedInOptional, ppqposInOptional, msgOptional, msgOptional_sz, noSortInOptional);
}

bool MIDI_SetItemExtentsWrapper(MediaItem* item, double startQN, double endQN)
{
    return MIDI_SetItemExtents(item, startQN, endQN);
}

bool MIDI_SetNoteWrapper(MediaItem_Take* take, int noteidx, const bool* selectedInOptional, const bool* mutedInOptional, const double* startppqposInOptional, const double* endppqposInOptional, const int* chanInOptional, const int* pitchInOptional, const int* velInOptional, const bool* noSortInOptional)
{
    return MIDI_SetNote(take, noteidx, selectedInOptional, mutedInOptional, startppqposInOptional, endppqposInOptional, chanInOptional, pitchInOptional, velInOptional, noSortInOptional);
}

bool MIDI_SetTextSysexEvtWrapper(MediaItem_Take* take, int textsyxevtidx, const bool* selectedInOptional, const bool* mutedInOptional, const double* ppqposInOptional, const int* typeInOptional, const char* msgOptional, int msgOptional_sz, const bool* noSortInOptional)
{
    return MIDI_SetTextSysexEvt(take, textsyxevtidx, selectedInOptional, mutedInOptional, ppqposInOptional, typeInOptional, msgOptional, msgOptional_sz, noSortInOptional);
}

void MIDI_SortWrapper(MediaItem_Take* take)
{
    return MIDI_Sort(take);
}

HWND MIDIEditor_GetActiveWrapper()
{
    return MIDIEditor_GetActive();
}

int MIDIEditor_GetModeWrapper(HWND midieditor)
{
    return MIDIEditor_GetMode(midieditor);
}

int MIDIEditor_GetSetting_intWrapper(HWND midieditor, const char* setting_desc)
{
    return MIDIEditor_GetSetting_int(midieditor, setting_desc);
}

bool MIDIEditor_GetSetting_strWrapper(HWND midieditor, const char* setting_desc, char* buf, int buf_sz)
{
    return MIDIEditor_GetSetting_str(midieditor, setting_desc, buf, buf_sz);
}

MediaItem_Take* MIDIEditor_GetTakeWrapper(HWND midieditor)
{
    return MIDIEditor_GetTake(midieditor);
}

bool MIDIEditor_LastFocused_OnCommandWrapper(int command_id, bool islistviewcommand)
{
    return MIDIEditor_LastFocused_OnCommand(command_id, islistviewcommand);
}

bool MIDIEditor_OnCommandWrapper(HWND midieditor, int command_id)
{
    return MIDIEditor_OnCommand(midieditor, command_id);
}

bool MIDIEditor_SetSetting_intWrapper(HWND midieditor, const char* setting_desc, int setting)
{
    return MIDIEditor_SetSetting_int(midieditor, setting_desc, setting);
}

void mkpanstrWrapper(char* strNeed64, double pan)
{
    return mkpanstr(strNeed64, pan);
}

void mkvolpanstrWrapper(char* strNeed64, double vol, double pan)
{
    return mkvolpanstr(strNeed64, vol, pan);
}

void mkvolstrWrapper(char* strNeed64, double vol)
{
    return mkvolstr(strNeed64, vol);
}

void MoveEditCursorWrapper(double adjamt, bool dosel)
{
    return MoveEditCursor(adjamt, dosel);
}

bool MoveMediaItemToTrackWrapper(MediaItem* item, MediaTrack* desttr)
{
    return MoveMediaItemToTrack(item, desttr);
}

void MuteAllTracksWrapper(bool mute)
{
    return MuteAllTracks(mute);
}

void my_getViewportWrapper(RECT* r, const RECT* sr, bool wantWorkArea)
{
    return my_getViewport(r, sr, wantWorkArea);
}

int NamedCommandLookupWrapper(const char* command_name)
{
    return NamedCommandLookup(command_name);
}

void OnPauseButtonWrapper()
{
    return OnPauseButton();
}

void OnPauseButtonExWrapper(ReaProject* proj)
{
    return OnPauseButtonEx(proj);
}

void OnPlayButtonWrapper()
{
    return OnPlayButton();
}

void OnPlayButtonExWrapper(ReaProject* proj)
{
    return OnPlayButtonEx(proj);
}

void OnStopButtonWrapper()
{
    return OnStopButton();
}

void OnStopButtonExWrapper(ReaProject* proj)
{
    return OnStopButtonEx(proj);
}

bool OpenColorThemeFileWrapper(const char* fn)
{
    return OpenColorThemeFile(fn);
}

HWND OpenMediaExplorerWrapper(const char* mediafn, bool play)
{
    return OpenMediaExplorer(mediafn, play);
}

void OscLocalMessageToHostWrapper(const char* message, const double* valueInOptional)
{
    return OscLocalMessageToHost(message, valueInOptional);
}

double parse_timestrWrapper(const char* buf)
{
    return parse_timestr(buf);
}

double parse_timestr_lenWrapper(const char* buf, double offset, int modeoverride)
{
    return parse_timestr_len(buf, offset, modeoverride);
}

double parse_timestr_posWrapper(const char* buf, int modeoverride)
{
    return parse_timestr_pos(buf, modeoverride);
}

double parsepanstrWrapper(const char* str)
{
    return parsepanstr(str);
}

PCM_sink* PCM_Sink_CreateWrapper(const char* filename, const char* cfg, int cfg_sz, int nch, int srate, bool buildpeaks)
{
    return PCM_Sink_Create(filename, cfg, cfg_sz, nch, srate, buildpeaks);
}

PCM_sink* PCM_Sink_CreateExWrapper(ReaProject* proj, const char* filename, const char* cfg, int cfg_sz, int nch, int srate, bool buildpeaks)
{
    return PCM_Sink_CreateEx(proj, filename, cfg, cfg_sz, nch, srate, buildpeaks);
}

PCM_sink* PCM_Sink_CreateMIDIFileWrapper(const char* filename, const char* cfg, int cfg_sz, double bpm, int div)
{
    return PCM_Sink_CreateMIDIFile(filename, cfg, cfg_sz, bpm, div);
}

PCM_sink* PCM_Sink_CreateMIDIFileExWrapper(ReaProject* proj, const char* filename, const char* cfg, int cfg_sz, double bpm, int div)
{
    return PCM_Sink_CreateMIDIFileEx(proj, filename, cfg, cfg_sz, bpm, div);
}

unsigned int PCM_Sink_EnumWrapper(int idx, const char** descstrOut)
{
    return PCM_Sink_Enum(idx, descstrOut);
}

const char* PCM_Sink_GetExtensionWrapper(const char* data, int data_sz)
{
    return PCM_Sink_GetExtension(data, data_sz);
}

HWND PCM_Sink_ShowConfigWrapper(const char* cfg, int cfg_sz, HWND hwndParent)
{
    return PCM_Sink_ShowConfig(cfg, cfg_sz, hwndParent);
}

PCM_source* PCM_Source_CreateFromFileWrapper(const char* filename)
{
    return PCM_Source_CreateFromFile(filename);
}

PCM_source* PCM_Source_CreateFromFileExWrapper(const char* filename, bool forcenoMidiImp)
{
    return PCM_Source_CreateFromFileEx(filename, forcenoMidiImp);
}

PCM_source* PCM_Source_CreateFromSimpleWrapper(ISimpleMediaDecoder* dec, const char* fn)
{
    return PCM_Source_CreateFromSimple(dec, fn);
}

PCM_source* PCM_Source_CreateFromTypeWrapper(const char* sourcetype)
{
    return PCM_Source_CreateFromType(sourcetype);
}

void PCM_Source_DestroyWrapper(PCM_source* src)
{
    return PCM_Source_Destroy(src);
}

int PCM_Source_GetPeaksWrapper(PCM_source* src, double peakrate, double starttime, int numchannels, int numsamplesperchannel, int want_extra_type, double* buf)
{
    return PCM_Source_GetPeaks(src, peakrate, starttime, numchannels, numsamplesperchannel, want_extra_type, buf);
}

bool PCM_Source_GetSectionInfoWrapper(PCM_source* src, double* offsOut, double* lenOut, bool* revOut)
{
    return PCM_Source_GetSectionInfo(src, offsOut, lenOut, revOut);
}

REAPER_PeakBuild_Interface* PeakBuild_CreateWrapper(PCM_source* src, const char* fn, int srate, int nch)
{
    return PeakBuild_Create(src, fn, srate, nch);
}

REAPER_PeakBuild_Interface* PeakBuild_CreateExWrapper(PCM_source* src, const char* fn, int srate, int nch, int flags)
{
    return PeakBuild_CreateEx(src, fn, srate, nch, flags);
}

REAPER_PeakGet_Interface* PeakGet_CreateWrapper(const char* fn, int srate, int nch)
{
    return PeakGet_Create(fn, srate, nch);
}

int PitchShiftSubModeMenuWrapper(HWND hwnd, int x, int y, int mode, int submode_sel)
{
    return PitchShiftSubModeMenu(hwnd, x, y, mode, submode_sel);
}

int PlayPreviewWrapper(preview_register_t* preview)
{
    return PlayPreview(preview);
}

int PlayPreviewExWrapper(preview_register_t* preview, int bufflags, double measure_align)
{
    return PlayPreviewEx(preview, bufflags, measure_align);
}

int PlayTrackPreviewWrapper(preview_register_t* preview)
{
    return PlayTrackPreview(preview);
}

int PlayTrackPreview2Wrapper(ReaProject* proj, preview_register_t* preview)
{
    return PlayTrackPreview2(proj, preview);
}

int PlayTrackPreview2ExWrapper(ReaProject* proj, preview_register_t* preview, int flags, double measure_align)
{
    return PlayTrackPreview2Ex(proj, preview, flags, measure_align);
}

void* plugin_getapiWrapper(const char* name)
{
    return plugin_getapi(name);
}

const char* plugin_getFilterListWrapper()
{
    return plugin_getFilterList();
}

const char* plugin_getImportableProjectFilterListWrapper()
{
    return plugin_getImportableProjectFilterList();
}

int plugin_registerWrapper(const char* name, void* infostruct)
{
    return plugin_register(name, infostruct);
}

void PluginWantsAlwaysRunFxWrapper(int amt)
{
    return PluginWantsAlwaysRunFx(amt);
}

void PreventUIRefreshWrapper(int prevent_count)
{
    return PreventUIRefresh(prevent_count);
}

void* projectconfig_var_addrWrapper(ReaProject* proj, int idx)
{
    return projectconfig_var_addr(proj, idx);
}

int projectconfig_var_getoffsWrapper(const char* name, int* szOut)
{
    return projectconfig_var_getoffs(name, szOut);
}

int PromptForActionWrapper(int session_mode, int init_id, int section_id)
{
    return PromptForAction(session_mode, init_id, section_id);
}

bool realloc_cmd_ptrWrapper(char** ptr, int* ptr_size, int new_size)
{
    return realloc_cmd_ptr(ptr, ptr_size, new_size);
}

IReaperPitchShift* ReaperGetPitchShiftAPIWrapper(int version)
{
    return ReaperGetPitchShiftAPI(version);
}

void ReaScriptErrorWrapper(const char* errmsg)
{
    return ReaScriptError(errmsg);
}

int RecursiveCreateDirectoryWrapper(const char* path, size_t ignored)
{
    return RecursiveCreateDirectory(path, ignored);
}

int reduce_open_filesWrapper(int flags)
{
    return reduce_open_files(flags);
}

void RefreshToolbarWrapper(int command_id)
{
    return RefreshToolbar(command_id);
}

void RefreshToolbar2Wrapper(int section_id, int command_id)
{
    return RefreshToolbar2(section_id, command_id);
}

void relative_fnWrapper(const char* in, char* out, int out_sz)
{
    return relative_fn(in, out, out_sz);
}

bool RemoveTrackSendWrapper(MediaTrack* tr, int category, int sendidx)
{
    return RemoveTrackSend(tr, category, sendidx);
}

bool RenderFileSectionWrapper(const char* source_filename, const char* target_filename, double start_percent, double end_percent, double playrate)
{
    return RenderFileSection(source_filename, target_filename, start_percent, end_percent, playrate);
}

bool ReorderSelectedTracksWrapper(int beforeTrackIdx, int makePrevFolder)
{
    return ReorderSelectedTracks(beforeTrackIdx, makePrevFolder);
}

const char* Resample_EnumModesWrapper(int mode)
{
    return Resample_EnumModes(mode);
}

REAPER_Resample_Interface* Resampler_CreateWrapper()
{
    return Resampler_Create();
}

void resolve_fnWrapper(const char* in, char* out, int out_sz)
{
    return resolve_fn(in, out, out_sz);
}

void resolve_fn2Wrapper(const char* in, char* out, int out_sz, const char* checkSubDirOptional)
{
    return resolve_fn2(in, out, out_sz, checkSubDirOptional);
}

const char* ReverseNamedCommandLookupWrapper(int command_id)
{
    return ReverseNamedCommandLookup(command_id);
}

double ScaleFromEnvelopeModeWrapper(int scaling_mode, double val)
{
    return ScaleFromEnvelopeMode(scaling_mode, val);
}

double ScaleToEnvelopeModeWrapper(int scaling_mode, double val)
{
    return ScaleToEnvelopeMode(scaling_mode, val);
}

void screenset_registerWrapper(char* id, void* callbackFunc, void* param)
{
    return screenset_register(id, callbackFunc, param);
}

void screenset_registerNewWrapper(char* id, screensetNewCallbackFunc callbackFunc, void* param)
{
    return screenset_registerNew(id, callbackFunc, param);
}

void screenset_unregisterWrapper(char* id)
{
    return screenset_unregister(id);
}

void screenset_unregisterByParamWrapper(void* param)
{
    return screenset_unregisterByParam(param);
}

void screenset_updateLastFocusWrapper(HWND prevWin)
{
    return screenset_updateLastFocus(prevWin);
}

KbdSectionInfo* SectionFromUniqueIDWrapper(int uniqueID)
{
    return SectionFromUniqueID(uniqueID);
}

void SelectAllMediaItemsWrapper(ReaProject* proj, bool selected)
{
    return SelectAllMediaItems(proj, selected);
}

void SelectProjectInstanceWrapper(ReaProject* proj)
{
    return SelectProjectInstance(proj);
}

void SendLocalOscMessageWrapper(void* local_osc_handler, const char* msg, int msglen)
{
    return SendLocalOscMessage(local_osc_handler, msg, msglen);
}

void SetActiveTakeWrapper(MediaItem_Take* take)
{
    return SetActiveTake(take);
}

void SetAutomationModeWrapper(int mode, bool onlySel)
{
    return SetAutomationMode(mode, onlySel);
}

void SetCurrentBPMWrapper(ReaProject* __proj, double bpm, bool wantUndo)
{
    return SetCurrentBPM(__proj, bpm, wantUndo);
}

void SetCursorContextWrapper(int mode, TrackEnvelope* envInOptional)
{
    return SetCursorContext(mode, envInOptional);
}

void SetEditCurPosWrapper(double time, bool moveview, bool seekplay)
{
    return SetEditCurPos(time, moveview, seekplay);
}

void SetEditCurPos2Wrapper(ReaProject* proj, double time, bool moveview, bool seekplay)
{
    return SetEditCurPos2(proj, time, moveview, seekplay);
}

bool SetEnvelopePointWrapper(TrackEnvelope* envelope, int ptidx, double* timeInOptional, double* valueInOptional, int* shapeInOptional, double* tensionInOptional, bool* selectedInOptional, bool* noSortInOptional)
{
    return SetEnvelopePoint(envelope, ptidx, timeInOptional, valueInOptional, shapeInOptional, tensionInOptional, selectedInOptional, noSortInOptional);
}

bool SetEnvelopePointExWrapper(TrackEnvelope* envelope, int autoitem_idx, int ptidx, double* timeInOptional, double* valueInOptional, int* shapeInOptional, double* tensionInOptional, bool* selectedInOptional, bool* noSortInOptional)
{
    return SetEnvelopePointEx(envelope, autoitem_idx, ptidx, timeInOptional, valueInOptional, shapeInOptional, tensionInOptional, selectedInOptional, noSortInOptional);
}

bool SetEnvelopeStateChunkWrapper(TrackEnvelope* env, const char* str, bool isundoOptional)
{
    return SetEnvelopeStateChunk(env, str, isundoOptional);
}

void SetExtStateWrapper(const char* section, const char* key, const char* value, bool persist)
{
    return SetExtState(section, key, value, persist);
}

void SetGlobalAutomationOverrideWrapper(int mode)
{
    return SetGlobalAutomationOverride(mode);
}

bool SetItemStateChunkWrapper(MediaItem* item, const char* str, bool isundoOptional)
{
    return SetItemStateChunk(item, str, isundoOptional);
}

int SetMasterTrackVisibilityWrapper(int flag)
{
    return SetMasterTrackVisibility(flag);
}

bool SetMediaItemInfo_ValueWrapper(MediaItem* item, const char* parmname, double newvalue)
{
    return SetMediaItemInfo_Value(item, parmname, newvalue);
}

bool SetMediaItemLengthWrapper(MediaItem* item, double length, bool refreshUI)
{
    return SetMediaItemLength(item, length, refreshUI);
}

bool SetMediaItemPositionWrapper(MediaItem* item, double position, bool refreshUI)
{
    return SetMediaItemPosition(item, position, refreshUI);
}

void SetMediaItemSelectedWrapper(MediaItem* item, bool selected)
{
    return SetMediaItemSelected(item, selected);
}

bool SetMediaItemTake_SourceWrapper(MediaItem_Take* take, PCM_source* source)
{
    return SetMediaItemTake_Source(take, source);
}

bool SetMediaItemTakeInfo_ValueWrapper(MediaItem_Take* take, const char* parmname, double newvalue)
{
    return SetMediaItemTakeInfo_Value(take, parmname, newvalue);
}

bool SetMediaTrackInfo_ValueWrapper(MediaTrack* tr, const char* parmname, double newvalue)
{
    return SetMediaTrackInfo_Value(tr, parmname, newvalue);
}

void SetMIDIEditorGridWrapper(ReaProject* project, double division)
{
    return SetMIDIEditorGrid(project, division);
}

MediaTrack* SetMixerScrollWrapper(MediaTrack* leftmosttrack)
{
    return SetMixerScroll(leftmosttrack);
}

void SetMouseModifierWrapper(const char* context, int modifier_flag, const char* action)
{
    return SetMouseModifier(context, modifier_flag, action);
}

void SetOnlyTrackSelectedWrapper(MediaTrack* track)
{
    return SetOnlyTrackSelected(track);
}

void SetProjectGridWrapper(ReaProject* project, double division)
{
    return SetProjectGrid(project, division);
}

bool SetProjectMarkerWrapper(int markrgnindexnumber, bool isrgn, double pos, double rgnend, const char* name)
{
    return SetProjectMarker(markrgnindexnumber, isrgn, pos, rgnend, name);
}

bool SetProjectMarker2Wrapper(ReaProject* proj, int markrgnindexnumber, bool isrgn, double pos, double rgnend, const char* name)
{
    return SetProjectMarker2(proj, markrgnindexnumber, isrgn, pos, rgnend, name);
}

bool SetProjectMarker3Wrapper(ReaProject* proj, int markrgnindexnumber, bool isrgn, double pos, double rgnend, const char* name, int color)
{
    return SetProjectMarker3(proj, markrgnindexnumber, isrgn, pos, rgnend, name, color);
}

bool SetProjectMarker4Wrapper(ReaProject* proj, int markrgnindexnumber, bool isrgn, double pos, double rgnend, const char* name, int color, int flags)
{
    return SetProjectMarker4(proj, markrgnindexnumber, isrgn, pos, rgnend, name, color, flags);
}

bool SetProjectMarkerByIndexWrapper(ReaProject* proj, int markrgnidx, bool isrgn, double pos, double rgnend, int IDnumber, const char* name, int color)
{
    return SetProjectMarkerByIndex(proj, markrgnidx, isrgn, pos, rgnend, IDnumber, name, color);
}

bool SetProjectMarkerByIndex2Wrapper(ReaProject* proj, int markrgnidx, bool isrgn, double pos, double rgnend, int IDnumber, const char* name, int color, int flags)
{
    return SetProjectMarkerByIndex2(proj, markrgnidx, isrgn, pos, rgnend, IDnumber, name, color, flags);
}

int SetProjExtStateWrapper(ReaProject* proj, const char* extname, const char* key, const char* value)
{
    return SetProjExtState(proj, extname, key, value);
}

void SetRegionRenderMatrixWrapper(ReaProject* proj, int regionindex, MediaTrack* track, int addorremove)
{
    return SetRegionRenderMatrix(proj, regionindex, track, addorremove);
}

void SetRenderLastErrorWrapper(const char* errorstr)
{
    return SetRenderLastError(errorstr);
}

int SetTakeMarkerWrapper(MediaItem_Take* take, int idx, const char* nameIn, double* srcposInOptional, int* colorInOptional)
{
    return SetTakeMarker(take, idx, nameIn, srcposInOptional, colorInOptional);
}

int SetTakeStretchMarkerWrapper(MediaItem_Take* take, int idx, double pos, const double* srcposInOptional)
{
    return SetTakeStretchMarker(take, idx, pos, srcposInOptional);
}

bool SetTakeStretchMarkerSlopeWrapper(MediaItem_Take* take, int idx, double slope)
{
    return SetTakeStretchMarkerSlope(take, idx, slope);
}

bool SetTempoTimeSigMarkerWrapper(ReaProject* proj, int ptidx, double timepos, int measurepos, double beatpos, double bpm, int timesig_num, int timesig_denom, bool lineartempo)
{
    return SetTempoTimeSigMarker(proj, ptidx, timepos, measurepos, beatpos, bpm, timesig_num, timesig_denom, lineartempo);
}

int SetThemeColorWrapper(const char* ini_key, int color, int flagsOptional)
{
    return SetThemeColor(ini_key, color, flagsOptional);
}

bool SetToggleCommandStateWrapper(int section_id, int command_id, int state)
{
    return SetToggleCommandState(section_id, command_id, state);
}

void SetTrackAutomationModeWrapper(MediaTrack* tr, int mode)
{
    return SetTrackAutomationMode(tr, mode);
}

void SetTrackColorWrapper(MediaTrack* track, int color)
{
    return SetTrackColor(track, color);
}

bool SetTrackMIDILyricsWrapper(MediaTrack* track, int flag, const char* str)
{
    return SetTrackMIDILyrics(track, flag, str);
}

bool SetTrackMIDINoteNameWrapper(int track, int pitch, int chan, const char* name)
{
    return SetTrackMIDINoteName(track, pitch, chan, name);
}

bool SetTrackMIDINoteNameExWrapper(ReaProject* proj, MediaTrack* track, int pitch, int chan, const char* name)
{
    return SetTrackMIDINoteNameEx(proj, track, pitch, chan, name);
}

void SetTrackSelectedWrapper(MediaTrack* track, bool selected)
{
    return SetTrackSelected(track, selected);
}

bool SetTrackSendInfo_ValueWrapper(MediaTrack* tr, int category, int sendidx, const char* parmname, double newvalue)
{
    return SetTrackSendInfo_Value(tr, category, sendidx, parmname, newvalue);
}

bool SetTrackSendUIPanWrapper(MediaTrack* track, int send_idx, double pan, int isend)
{
    return SetTrackSendUIPan(track, send_idx, pan, isend);
}

bool SetTrackSendUIVolWrapper(MediaTrack* track, int send_idx, double vol, int isend)
{
    return SetTrackSendUIVol(track, send_idx, vol, isend);
}

bool SetTrackStateChunkWrapper(MediaTrack* track, const char* str, bool isundoOptional)
{
    return SetTrackStateChunk(track, str, isundoOptional);
}

void ShowActionListWrapper(KbdSectionInfo* caller, HWND callerWnd)
{
    return ShowActionList(caller, callerWnd);
}

void ShowConsoleMsgWrapper(const char* msg)
{
    return ShowConsoleMsg(msg);
}

int ShowMessageBoxWrapper(const char* msg, const char* title, int type)
{
    return ShowMessageBox(msg, title, type);
}

void ShowPopupMenuWrapper(const char* name, int x, int y, HWND hwndParentOptional, void* ctxOptional, int ctx2Optional, int ctx3Optional)
{
    return ShowPopupMenu(name, x, y, hwndParentOptional, ctxOptional, ctx2Optional, ctx3Optional);
}

double SLIDER2DBWrapper(double y)
{
    return SLIDER2DB(y);
}

double SnapToGridWrapper(ReaProject* project, double time_pos)
{
    return SnapToGrid(project, time_pos);
}

void SoloAllTracksWrapper(int solo)
{
    return SoloAllTracks(solo);
}

HWND Splash_GetWndWrapper()
{
    return Splash_GetWnd();
}

MediaItem* SplitMediaItemWrapper(MediaItem* item, double position)
{
    return SplitMediaItem(item, position);
}

int StopPreviewWrapper(preview_register_t* preview)
{
    return StopPreview(preview);
}

int StopTrackPreviewWrapper(preview_register_t* preview)
{
    return StopTrackPreview(preview);
}

int StopTrackPreview2Wrapper(void* proj, preview_register_t* preview)
{
    return StopTrackPreview2(proj, preview);
}

void stringToGuidWrapper(const char* str, GUID* g)
{
    return stringToGuid(str, g);
}

void StuffMIDIMessageWrapper(int mode, int msg1, int msg2, int msg3)
{
    return StuffMIDIMessage(mode, msg1, msg2, msg3);
}

int TakeFX_AddByNameWrapper(MediaItem_Take* take, const char* fxname, int instantiate)
{
    return TakeFX_AddByName(take, fxname, instantiate);
}

void TakeFX_CopyToTakeWrapper(MediaItem_Take* src_take, int src_fx, MediaItem_Take* dest_take, int dest_fx, bool is_move)
{
    return TakeFX_CopyToTake(src_take, src_fx, dest_take, dest_fx, is_move);
}

void TakeFX_CopyToTrackWrapper(MediaItem_Take* src_take, int src_fx, MediaTrack* dest_track, int dest_fx, bool is_move)
{
    return TakeFX_CopyToTrack(src_take, src_fx, dest_track, dest_fx, is_move);
}

bool TakeFX_DeleteWrapper(MediaItem_Take* take, int fx)
{
    return TakeFX_Delete(take, fx);
}

bool TakeFX_EndParamEditWrapper(MediaItem_Take* take, int fx, int param)
{
    return TakeFX_EndParamEdit(take, fx, param);
}

bool TakeFX_FormatParamValueWrapper(MediaItem_Take* take, int fx, int param, double val, char* buf, int buf_sz)
{
    return TakeFX_FormatParamValue(take, fx, param, val, buf, buf_sz);
}

bool TakeFX_FormatParamValueNormalizedWrapper(MediaItem_Take* take, int fx, int param, double value, char* buf, int buf_sz)
{
    return TakeFX_FormatParamValueNormalized(take, fx, param, value, buf, buf_sz);
}

int TakeFX_GetChainVisibleWrapper(MediaItem_Take* take)
{
    return TakeFX_GetChainVisible(take);
}

int TakeFX_GetCountWrapper(MediaItem_Take* take)
{
    return TakeFX_GetCount(take);
}

bool TakeFX_GetEnabledWrapper(MediaItem_Take* take, int fx)
{
    return TakeFX_GetEnabled(take, fx);
}

TrackEnvelope* TakeFX_GetEnvelopeWrapper(MediaItem_Take* take, int fxindex, int parameterindex, bool create)
{
    return TakeFX_GetEnvelope(take, fxindex, parameterindex, create);
}

HWND TakeFX_GetFloatingWindowWrapper(MediaItem_Take* take, int index)
{
    return TakeFX_GetFloatingWindow(take, index);
}

bool TakeFX_GetFormattedParamValueWrapper(MediaItem_Take* take, int fx, int param, char* buf, int buf_sz)
{
    return TakeFX_GetFormattedParamValue(take, fx, param, buf, buf_sz);
}

GUID* TakeFX_GetFXGUIDWrapper(MediaItem_Take* take, int fx)
{
    return TakeFX_GetFXGUID(take, fx);
}

bool TakeFX_GetFXNameWrapper(MediaItem_Take* take, int fx, char* buf, int buf_sz)
{
    return TakeFX_GetFXName(take, fx, buf, buf_sz);
}

int TakeFX_GetIOSizeWrapper(MediaItem_Take* take, int fx, int* inputPinsOutOptional, int* outputPinsOutOptional)
{
    return TakeFX_GetIOSize(take, fx, inputPinsOutOptional, outputPinsOutOptional);
}

bool TakeFX_GetNamedConfigParmWrapper(MediaItem_Take* take, int fx, const char* parmname, char* bufOut, int bufOut_sz)
{
    return TakeFX_GetNamedConfigParm(take, fx, parmname, bufOut, bufOut_sz);
}

int TakeFX_GetNumParamsWrapper(MediaItem_Take* take, int fx)
{
    return TakeFX_GetNumParams(take, fx);
}

bool TakeFX_GetOfflineWrapper(MediaItem_Take* take, int fx)
{
    return TakeFX_GetOffline(take, fx);
}

bool TakeFX_GetOpenWrapper(MediaItem_Take* take, int fx)
{
    return TakeFX_GetOpen(take, fx);
}

double TakeFX_GetParamWrapper(MediaItem_Take* take, int fx, int param, double* minvalOut, double* maxvalOut)
{
    return TakeFX_GetParam(take, fx, param, minvalOut, maxvalOut);
}

bool TakeFX_GetParameterStepSizesWrapper(MediaItem_Take* take, int fx, int param, double* stepOut, double* smallstepOut, double* largestepOut, bool* istoggleOut)
{
    return TakeFX_GetParameterStepSizes(take, fx, param, stepOut, smallstepOut, largestepOut, istoggleOut);
}

double TakeFX_GetParamExWrapper(MediaItem_Take* take, int fx, int param, double* minvalOut, double* maxvalOut, double* midvalOut)
{
    return TakeFX_GetParamEx(take, fx, param, minvalOut, maxvalOut, midvalOut);
}

bool TakeFX_GetParamNameWrapper(MediaItem_Take* take, int fx, int param, char* buf, int buf_sz)
{
    return TakeFX_GetParamName(take, fx, param, buf, buf_sz);
}

double TakeFX_GetParamNormalizedWrapper(MediaItem_Take* take, int fx, int param)
{
    return TakeFX_GetParamNormalized(take, fx, param);
}

int TakeFX_GetPinMappingsWrapper(MediaItem_Take* tr, int fx, int isoutput, int pin, int* high32OutOptional)
{
    return TakeFX_GetPinMappings(tr, fx, isoutput, pin, high32OutOptional);
}

bool TakeFX_GetPresetWrapper(MediaItem_Take* take, int fx, char* presetname, int presetname_sz)
{
    return TakeFX_GetPreset(take, fx, presetname, presetname_sz);
}

int TakeFX_GetPresetIndexWrapper(MediaItem_Take* take, int fx, int* numberOfPresetsOut)
{
    return TakeFX_GetPresetIndex(take, fx, numberOfPresetsOut);
}

void TakeFX_GetUserPresetFilenameWrapper(MediaItem_Take* take, int fx, char* fn, int fn_sz)
{
    return TakeFX_GetUserPresetFilename(take, fx, fn, fn_sz);
}

bool TakeFX_NavigatePresetsWrapper(MediaItem_Take* take, int fx, int presetmove)
{
    return TakeFX_NavigatePresets(take, fx, presetmove);
}

void TakeFX_SetEnabledWrapper(MediaItem_Take* take, int fx, bool enabled)
{
    return TakeFX_SetEnabled(take, fx, enabled);
}

bool TakeFX_SetNamedConfigParmWrapper(MediaItem_Take* take, int fx, const char* parmname, const char* value)
{
    return TakeFX_SetNamedConfigParm(take, fx, parmname, value);
}

void TakeFX_SetOfflineWrapper(MediaItem_Take* take, int fx, bool offline)
{
    return TakeFX_SetOffline(take, fx, offline);
}

void TakeFX_SetOpenWrapper(MediaItem_Take* take, int fx, bool open)
{
    return TakeFX_SetOpen(take, fx, open);
}

bool TakeFX_SetParamWrapper(MediaItem_Take* take, int fx, int param, double val)
{
    return TakeFX_SetParam(take, fx, param, val);
}

bool TakeFX_SetParamNormalizedWrapper(MediaItem_Take* take, int fx, int param, double value)
{
    return TakeFX_SetParamNormalized(take, fx, param, value);
}

bool TakeFX_SetPinMappingsWrapper(MediaItem_Take* tr, int fx, int isoutput, int pin, int low32bits, int hi32bits)
{
    return TakeFX_SetPinMappings(tr, fx, isoutput, pin, low32bits, hi32bits);
}

bool TakeFX_SetPresetWrapper(MediaItem_Take* take, int fx, const char* presetname)
{
    return TakeFX_SetPreset(take, fx, presetname);
}

bool TakeFX_SetPresetByIndexWrapper(MediaItem_Take* take, int fx, int idx)
{
    return TakeFX_SetPresetByIndex(take, fx, idx);
}

void TakeFX_ShowWrapper(MediaItem_Take* take, int index, int showFlag)
{
    return TakeFX_Show(take, index, showFlag);
}

bool TakeIsMIDIWrapper(MediaItem_Take* take)
{
    return TakeIsMIDI(take);
}

bool ThemeLayout_GetLayoutWrapper(const char* section, int idx, char* nameOut, int nameOut_sz)
{
    return ThemeLayout_GetLayout(section, idx, nameOut, nameOut_sz);
}

const char* ThemeLayout_GetParameterWrapper(int wp, const char** descOutOptional, int* valueOutOptional, int* defValueOutOptional, int* minValueOutOptional, int* maxValueOutOptional)
{
    return ThemeLayout_GetParameter(wp, descOutOptional, valueOutOptional, defValueOutOptional, minValueOutOptional, maxValueOutOptional);
}

void ThemeLayout_RefreshAllWrapper()
{
    return ThemeLayout_RefreshAll();
}

bool ThemeLayout_SetLayoutWrapper(const char* section, const char* layout)
{
    return ThemeLayout_SetLayout(section, layout);
}

bool ThemeLayout_SetParameterWrapper(int wp, int value, bool persist)
{
    return ThemeLayout_SetParameter(wp, value, persist);
}

double time_preciseWrapper()
{
    return time_precise();
}

double TimeMap2_beatsToTimeWrapper(ReaProject* proj, double tpos, const int* measuresInOptional)
{
    return TimeMap2_beatsToTime(proj, tpos, measuresInOptional);
}

double TimeMap2_GetDividedBpmAtTimeWrapper(ReaProject* proj, double time)
{
    return TimeMap2_GetDividedBpmAtTime(proj, time);
}

double TimeMap2_GetNextChangeTimeWrapper(ReaProject* proj, double time)
{
    return TimeMap2_GetNextChangeTime(proj, time);
}

double TimeMap2_QNToTimeWrapper(ReaProject* proj, double qn)
{
    return TimeMap2_QNToTime(proj, qn);
}

double TimeMap2_timeToBeatsWrapper(ReaProject* proj, double tpos, int* measuresOutOptional, int* cmlOutOptional, double* fullbeatsOutOptional, int* cdenomOutOptional)
{
    return TimeMap2_timeToBeats(proj, tpos, measuresOutOptional, cmlOutOptional, fullbeatsOutOptional, cdenomOutOptional);
}

double TimeMap2_timeToQNWrapper(ReaProject* proj, double tpos)
{
    return TimeMap2_timeToQN(proj, tpos);
}

double TimeMap_curFrameRateWrapper(ReaProject* proj, bool* dropFrameOutOptional)
{
    return TimeMap_curFrameRate(proj, dropFrameOutOptional);
}

double TimeMap_GetDividedBpmAtTimeWrapper(double time)
{
    return TimeMap_GetDividedBpmAtTime(time);
}

double TimeMap_GetMeasureInfoWrapper(ReaProject* proj, int measure, double* qn_startOut, double* qn_endOut, int* timesig_numOut, int* timesig_denomOut, double* tempoOut)
{
    return TimeMap_GetMeasureInfo(proj, measure, qn_startOut, qn_endOut, timesig_numOut, timesig_denomOut, tempoOut);
}

int TimeMap_GetMetronomePatternWrapper(ReaProject* proj, double time, char* pattern, int pattern_sz)
{
    return TimeMap_GetMetronomePattern(proj, time, pattern, pattern_sz);
}

void TimeMap_GetTimeSigAtTimeWrapper(ReaProject* proj, double time, int* timesig_numOut, int* timesig_denomOut, double* tempoOut)
{
    return TimeMap_GetTimeSigAtTime(proj, time, timesig_numOut, timesig_denomOut, tempoOut);
}

int TimeMap_QNToMeasuresWrapper(ReaProject* proj, double qn, double* qnMeasureStartOutOptional, double* qnMeasureEndOutOptional)
{
    return TimeMap_QNToMeasures(proj, qn, qnMeasureStartOutOptional, qnMeasureEndOutOptional);
}

double TimeMap_QNToTimeWrapper(double qn)
{
    return TimeMap_QNToTime(qn);
}

double TimeMap_QNToTime_absWrapper(ReaProject* proj, double qn)
{
    return TimeMap_QNToTime_abs(proj, qn);
}

double TimeMap_timeToQNWrapper(double tpos)
{
    return TimeMap_timeToQN(tpos);
}

double TimeMap_timeToQN_absWrapper(ReaProject* proj, double tpos)
{
    return TimeMap_timeToQN_abs(proj, tpos);
}

bool ToggleTrackSendUIMuteWrapper(MediaTrack* track, int send_idx)
{
    return ToggleTrackSendUIMute(track, send_idx);
}

double Track_GetPeakHoldDBWrapper(MediaTrack* track, int channel, bool clear)
{
    return Track_GetPeakHoldDB(track, channel, clear);
}

double Track_GetPeakInfoWrapper(MediaTrack* track, int channel)
{
    return Track_GetPeakInfo(track, channel);
}

void TrackCtl_SetToolTipWrapper(const char* fmt, int xpos, int ypos, bool topmost)
{
    return TrackCtl_SetToolTip(fmt, xpos, ypos, topmost);
}

int TrackFX_AddByNameWrapper(MediaTrack* track, const char* fxname, bool recFX, int instantiate)
{
    return TrackFX_AddByName(track, fxname, recFX, instantiate);
}

void TrackFX_CopyToTakeWrapper(MediaTrack* src_track, int src_fx, MediaItem_Take* dest_take, int dest_fx, bool is_move)
{
    return TrackFX_CopyToTake(src_track, src_fx, dest_take, dest_fx, is_move);
}

void TrackFX_CopyToTrackWrapper(MediaTrack* src_track, int src_fx, MediaTrack* dest_track, int dest_fx, bool is_move)
{
    return TrackFX_CopyToTrack(src_track, src_fx, dest_track, dest_fx, is_move);
}

bool TrackFX_DeleteWrapper(MediaTrack* track, int fx)
{
    return TrackFX_Delete(track, fx);
}

bool TrackFX_EndParamEditWrapper(MediaTrack* track, int fx, int param)
{
    return TrackFX_EndParamEdit(track, fx, param);
}

bool TrackFX_FormatParamValueWrapper(MediaTrack* track, int fx, int param, double val, char* buf, int buf_sz)
{
    return TrackFX_FormatParamValue(track, fx, param, val, buf, buf_sz);
}

bool TrackFX_FormatParamValueNormalizedWrapper(MediaTrack* track, int fx, int param, double value, char* buf, int buf_sz)
{
    return TrackFX_FormatParamValueNormalized(track, fx, param, value, buf, buf_sz);
}

int TrackFX_GetByNameWrapper(MediaTrack* track, const char* fxname, bool instantiate)
{
    return TrackFX_GetByName(track, fxname, instantiate);
}

int TrackFX_GetChainVisibleWrapper(MediaTrack* track)
{
    return TrackFX_GetChainVisible(track);
}

int TrackFX_GetCountWrapper(MediaTrack* track)
{
    return TrackFX_GetCount(track);
}

bool TrackFX_GetEnabledWrapper(MediaTrack* track, int fx)
{
    return TrackFX_GetEnabled(track, fx);
}

int TrackFX_GetEQWrapper(MediaTrack* track, bool instantiate)
{
    return TrackFX_GetEQ(track, instantiate);
}

bool TrackFX_GetEQBandEnabledWrapper(MediaTrack* track, int fxidx, int bandtype, int bandidx)
{
    return TrackFX_GetEQBandEnabled(track, fxidx, bandtype, bandidx);
}

bool TrackFX_GetEQParamWrapper(MediaTrack* track, int fxidx, int paramidx, int* bandtypeOut, int* bandidxOut, int* paramtypeOut, double* normvalOut)
{
    return TrackFX_GetEQParam(track, fxidx, paramidx, bandtypeOut, bandidxOut, paramtypeOut, normvalOut);
}

HWND TrackFX_GetFloatingWindowWrapper(MediaTrack* track, int index)
{
    return TrackFX_GetFloatingWindow(track, index);
}

bool TrackFX_GetFormattedParamValueWrapper(MediaTrack* track, int fx, int param, char* buf, int buf_sz)
{
    return TrackFX_GetFormattedParamValue(track, fx, param, buf, buf_sz);
}

GUID* TrackFX_GetFXGUIDWrapper(MediaTrack* track, int fx)
{
    return TrackFX_GetFXGUID(track, fx);
}

bool TrackFX_GetFXNameWrapper(MediaTrack* track, int fx, char* buf, int buf_sz)
{
    return TrackFX_GetFXName(track, fx, buf, buf_sz);
}

int TrackFX_GetInstrumentWrapper(MediaTrack* track)
{
    return TrackFX_GetInstrument(track);
}

int TrackFX_GetIOSizeWrapper(MediaTrack* track, int fx, int* inputPinsOutOptional, int* outputPinsOutOptional)
{
    return TrackFX_GetIOSize(track, fx, inputPinsOutOptional, outputPinsOutOptional);
}

bool TrackFX_GetNamedConfigParmWrapper(MediaTrack* track, int fx, const char* parmname, char* bufOut, int bufOut_sz)
{
    return TrackFX_GetNamedConfigParm(track, fx, parmname, bufOut, bufOut_sz);
}

int TrackFX_GetNumParamsWrapper(MediaTrack* track, int fx)
{
    return TrackFX_GetNumParams(track, fx);
}

bool TrackFX_GetOfflineWrapper(MediaTrack* track, int fx)
{
    return TrackFX_GetOffline(track, fx);
}

bool TrackFX_GetOpenWrapper(MediaTrack* track, int fx)
{
    return TrackFX_GetOpen(track, fx);
}

double TrackFX_GetParamWrapper(MediaTrack* track, int fx, int param, double* minvalOut, double* maxvalOut)
{
    return TrackFX_GetParam(track, fx, param, minvalOut, maxvalOut);
}

bool TrackFX_GetParameterStepSizesWrapper(MediaTrack* track, int fx, int param, double* stepOut, double* smallstepOut, double* largestepOut, bool* istoggleOut)
{
    return TrackFX_GetParameterStepSizes(track, fx, param, stepOut, smallstepOut, largestepOut, istoggleOut);
}

double TrackFX_GetParamExWrapper(MediaTrack* track, int fx, int param, double* minvalOut, double* maxvalOut, double* midvalOut)
{
    return TrackFX_GetParamEx(track, fx, param, minvalOut, maxvalOut, midvalOut);
}

bool TrackFX_GetParamNameWrapper(MediaTrack* track, int fx, int param, char* buf, int buf_sz)
{
    return TrackFX_GetParamName(track, fx, param, buf, buf_sz);
}

double TrackFX_GetParamNormalizedWrapper(MediaTrack* track, int fx, int param)
{
    return TrackFX_GetParamNormalized(track, fx, param);
}

int TrackFX_GetPinMappingsWrapper(MediaTrack* tr, int fx, int isoutput, int pin, int* high32OutOptional)
{
    return TrackFX_GetPinMappings(tr, fx, isoutput, pin, high32OutOptional);
}

bool TrackFX_GetPresetWrapper(MediaTrack* track, int fx, char* presetname, int presetname_sz)
{
    return TrackFX_GetPreset(track, fx, presetname, presetname_sz);
}

int TrackFX_GetPresetIndexWrapper(MediaTrack* track, int fx, int* numberOfPresetsOut)
{
    return TrackFX_GetPresetIndex(track, fx, numberOfPresetsOut);
}

int TrackFX_GetRecChainVisibleWrapper(MediaTrack* track)
{
    return TrackFX_GetRecChainVisible(track);
}

int TrackFX_GetRecCountWrapper(MediaTrack* track)
{
    return TrackFX_GetRecCount(track);
}

void TrackFX_GetUserPresetFilenameWrapper(MediaTrack* track, int fx, char* fn, int fn_sz)
{
    return TrackFX_GetUserPresetFilename(track, fx, fn, fn_sz);
}

bool TrackFX_NavigatePresetsWrapper(MediaTrack* track, int fx, int presetmove)
{
    return TrackFX_NavigatePresets(track, fx, presetmove);
}

void TrackFX_SetEnabledWrapper(MediaTrack* track, int fx, bool enabled)
{
    return TrackFX_SetEnabled(track, fx, enabled);
}

bool TrackFX_SetEQBandEnabledWrapper(MediaTrack* track, int fxidx, int bandtype, int bandidx, bool enable)
{
    return TrackFX_SetEQBandEnabled(track, fxidx, bandtype, bandidx, enable);
}

bool TrackFX_SetEQParamWrapper(MediaTrack* track, int fxidx, int bandtype, int bandidx, int paramtype, double val, bool isnorm)
{
    return TrackFX_SetEQParam(track, fxidx, bandtype, bandidx, paramtype, val, isnorm);
}

bool TrackFX_SetNamedConfigParmWrapper(MediaTrack* track, int fx, const char* parmname, const char* value)
{
    return TrackFX_SetNamedConfigParm(track, fx, parmname, value);
}

void TrackFX_SetOfflineWrapper(MediaTrack* track, int fx, bool offline)
{
    return TrackFX_SetOffline(track, fx, offline);
}

void TrackFX_SetOpenWrapper(MediaTrack* track, int fx, bool open)
{
    return TrackFX_SetOpen(track, fx, open);
}

bool TrackFX_SetParamWrapper(MediaTrack* track, int fx, int param, double val)
{
    return TrackFX_SetParam(track, fx, param, val);
}

bool TrackFX_SetParamNormalizedWrapper(MediaTrack* track, int fx, int param, double value)
{
    return TrackFX_SetParamNormalized(track, fx, param, value);
}

bool TrackFX_SetPinMappingsWrapper(MediaTrack* tr, int fx, int isoutput, int pin, int low32bits, int hi32bits)
{
    return TrackFX_SetPinMappings(tr, fx, isoutput, pin, low32bits, hi32bits);
}

bool TrackFX_SetPresetWrapper(MediaTrack* track, int fx, const char* presetname)
{
    return TrackFX_SetPreset(track, fx, presetname);
}

bool TrackFX_SetPresetByIndexWrapper(MediaTrack* track, int fx, int idx)
{
    return TrackFX_SetPresetByIndex(track, fx, idx);
}

void TrackFX_ShowWrapper(MediaTrack* track, int index, int showFlag)
{
    return TrackFX_Show(track, index, showFlag);
}

void TrackList_AdjustWindowsWrapper(bool isMinor)
{
    return TrackList_AdjustWindows(isMinor);
}

void TrackList_UpdateAllExternalSurfacesWrapper()
{
    return TrackList_UpdateAllExternalSurfaces();
}

void Undo_BeginBlockWrapper()
{
    return Undo_BeginBlock();
}

void Undo_BeginBlock2Wrapper(ReaProject* proj)
{
    return Undo_BeginBlock2(proj);
}

const char* Undo_CanRedo2Wrapper(ReaProject* proj)
{
    return Undo_CanRedo2(proj);
}

const char* Undo_CanUndo2Wrapper(ReaProject* proj)
{
    return Undo_CanUndo2(proj);
}

int Undo_DoRedo2Wrapper(ReaProject* proj)
{
    return Undo_DoRedo2(proj);
}

int Undo_DoUndo2Wrapper(ReaProject* proj)
{
    return Undo_DoUndo2(proj);
}

void Undo_EndBlockWrapper(const char* descchange, int extraflags)
{
    return Undo_EndBlock(descchange, extraflags);
}

void Undo_EndBlock2Wrapper(ReaProject* proj, const char* descchange, int extraflags)
{
    return Undo_EndBlock2(proj, descchange, extraflags);
}

void Undo_OnStateChangeWrapper(const char* descchange)
{
    return Undo_OnStateChange(descchange);
}

void Undo_OnStateChange2Wrapper(ReaProject* proj, const char* descchange)
{
    return Undo_OnStateChange2(proj, descchange);
}

void Undo_OnStateChange_ItemWrapper(ReaProject* proj, const char* name, MediaItem* item)
{
    return Undo_OnStateChange_Item(proj, name, item);
}

void Undo_OnStateChangeExWrapper(const char* descchange, int whichStates, int trackparm)
{
    return Undo_OnStateChangeEx(descchange, whichStates, trackparm);
}

void Undo_OnStateChangeEx2Wrapper(ReaProject* proj, const char* descchange, int whichStates, int trackparm)
{
    return Undo_OnStateChangeEx2(proj, descchange, whichStates, trackparm);
}

void update_disk_countersWrapper(int readamt, int writeamt)
{
    return update_disk_counters(readamt, writeamt);
}

void UpdateArrangeWrapper()
{
    return UpdateArrange();
}

void UpdateItemInProjectWrapper(MediaItem* item)
{
    return UpdateItemInProject(item);
}

void UpdateTimelineWrapper()
{
    return UpdateTimeline();
}

bool ValidatePtrWrapper(void* pointer, const char* ctypename)
{
    return ValidatePtr(pointer, ctypename);
}

bool ValidatePtr2Wrapper(ReaProject* proj, void* pointer, const char* ctypename)
{
    return ValidatePtr2(proj, pointer, ctypename);
}

void ViewPrefsWrapper(int page, const char* pageByName)
{
    return ViewPrefs(page, pageByName);
}

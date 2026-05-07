/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FR_APPCALLS_H
#define FR_APPCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_APPEXPT_H
#include "fr_appExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fr_appImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fr_appTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fr_appImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fr_appTempl.h"

//----------_V1----------
//*****************************
/* Tool HFT functions */
//*****************************

#define FRToolNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolNewSELPROTO)FRCOREROUTINE(FRToolSEL,FRToolNewSEL, _gPID)))

#define FRToolRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolReleaseSELPROTO)FRCOREROUTINE(FRToolSEL,FRToolReleaseSEL, _gPID)))

#define FRToolGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolGetNameSELPROTO)FRCOREROUTINE(FRToolSEL,FRToolGetNameSEL, _gPID)))

//*****************************
/* App HFT functions */
//*****************************

#define FRAppGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetNameSEL, _gPID)))

#define FRAppGetVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetVersionSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetVersionSEL, _gPID)))

#define FRAppGetAppTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetAppTitleSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetAppTitleSEL, _gPID)))

#define FRAppGetAppDataPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetAppDataPathSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetAppDataPathSEL, _gPID)))

#define FRAppRegisterTool (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterToolSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterToolSEL, _gPID)))

#define FRAppGetToolByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetToolByNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetToolByNameSEL, _gPID)))

#define FRAppCountTools (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCountToolsSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCountToolsSEL, _gPID)))

#define FRAppGetToolByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetToolByIndexSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetToolByIndexSEL, _gPID)))

#define FRAppSetActiveTool (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetActiveToolSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetActiveToolSEL, _gPID)))

#define FRAppGetActiveTool (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetActiveToolSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetActiveToolSEL, _gPID)))

#define FRAppRegisterPreferencePageHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterPreferencePageHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterPreferencePageHandlerSEL, _gPID)))

#define FRAppAddPreferencePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddPreferencePageSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddPreferencePageSEL, _gPID)))

#define FRAppRegisterDocPropertyPageHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterDocPropertyPageHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterDocPropertyPageHandlerSEL, _gPID)))

#define FRAppAddDocPropertyPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddDocPropertyPageSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddDocPropertyPageSEL, _gPID)))

#define FRAppRegisterAppEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterAppEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterAppEventHandlerSEL, _gPID)))

#define FRAppCountDocsOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCountDocsOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCountDocsOfPDDocSEL, _gPID)))

#define FRAppGetDocOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetDocOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetDocOfPDDocSEL, _gPID)))

#define FRAppGetActiveDocOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetActiveDocOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetActiveDocOfPDDocSEL, _gPID)))

#define FRAppSetActiveDocOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetActiveDocOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetActiveDocOfPDDocSEL, _gPID)))

#define FRAppRegisterDocHandlerOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterDocHandlerOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterDocHandlerOfPDDocSEL, _gPID)))

#define FRAppIsFullScreen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsFullScreenSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsFullScreenSEL, _gPID)))

#define FRAppShowFullScreen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppShowFullScreenSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppShowFullScreenSEL, _gPID)))

#define FRAppEndFullScreen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppEndFullScreenSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppEndFullScreenSEL, _gPID)))

#define FRAppGetMousePos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetMousePosSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetMousePosSEL, _gPID)))

#define FRAppModalWindowIsOpen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppModalWindowIsOpenSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppModalWindowIsOpenSEL, _gPID)))

#define FRAppRegisterSecurityHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterSecurityHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterSecurityHandlerSEL, _gPID)))

#define FRAppUnRegisterSecurityHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterSecurityHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterSecurityHandlerSEL, _gPID)))

#define FRAppRegisterContentProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterContentProviderSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterContentProviderSEL, _gPID)))

#define FRAppGetMainFrameWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetMainFrameWndSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetMainFrameWndSEL, _gPID)))

#define FRAppRegisterPageHandlerOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterPageHandlerOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterPageHandlerOfPDDocSEL, _gPID)))

#define FRAppRegisterForContextMenuAddition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterForContextMenuAdditionSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterForContextMenuAdditionSEL, _gPID)))

#define FRAppRegisterSelectionHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterSelectionHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterSelectionHandlerSEL, _gPID)))

#define FRAppUnRegisterSelectionHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterSelectionHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterSelectionHandlerSEL, _gPID)))

#define FRAppRegistryGetProfilePath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetProfilePathSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetProfilePathSEL, _gPID)))

#define FRAppRegistryWriteInt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryWriteIntSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryWriteIntSEL, _gPID)))

#define FRAppRegistryWriteBinary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryWriteBinarySELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryWriteBinarySEL, _gPID)))

#define FRAppRegistryWriteString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryWriteStringSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryWriteStringSEL, _gPID)))

#define FRAppRegistryGetInt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetIntSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetIntSEL, _gPID)))

#define FRAppRegistryGetBinary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetBinarySELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetBinarySEL, _gPID)))

#define FRAppRegistryGetString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetStringSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetStringSEL, _gPID)))

#define FRAppRegistryGetEntryCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetEntryCountSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetEntryCountSEL, _gPID)))

#define FRAppRegistryGetEntryName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetEntryNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetEntryNameSEL, _gPID)))

#define FRAppRegistryRemoveSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryRemoveSectionSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryRemoveSectionSEL, _gPID)))

#define FRAppRegistryRemoveEntry (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryRemoveEntrySELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryRemoveEntrySEL, _gPID)))

#define FRAppCreateAnEmptyFrameWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCreateAnEmptyFrameWndSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCreateAnEmptyFrameWndSEL, _gPID)))

#define FRAppRegisterExtraPrintInfoProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterExtraPrintInfoProviderSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterExtraPrintInfoProviderSEL, _gPID)))

#define FRAppRegisterTaskPaneView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterTaskPaneViewSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterTaskPaneViewSEL, _gPID)))

#define FRAppShowTaskPane (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppShowTaskPaneSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppShowTaskPaneSEL, _gPID)))

#define FRAppGetTaskPaneWndHandleByDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetTaskPaneWndHandleByDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetTaskPaneWndHandleByDocSEL, _gPID)))

#define FRAppCommandLineHasSwitch (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCommandLineHasSwitchSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCommandLineHasSwitchSEL, _gPID)))

#define FRAppCommandLineGetSafeArgument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCommandLineGetSafeArgumentSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCommandLineGetSafeArgumentSEL, _gPID)))

#define FRAppCommandLineGetArgument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCommandLineGetArgumentSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCommandLineGetArgumentSEL, _gPID)))

#define FRAppCommandLineGetArgumentCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCommandLineGetArgumentCountSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCommandLineGetArgumentCountSEL, _gPID)))

#define FRAppGetRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRecentFileListSEL, _gPID)))

#define FRAppAddFileToRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddFileToRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddFileToRecentFileListSEL, _gPID)))

#define FRAppClearRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppClearRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppClearRecentFileListSEL, _gPID)))

#define FRAppRegisterSecurityMethod (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterSecurityMethodSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterSecurityMethodSEL, _gPID)))

#define FRAppPopDocPropertyPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppPopDocPropertyPageSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppPopDocPropertyPageSEL, _gPID)))

#define FRAppCountDocPropertyPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCountDocPropertyPagesSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCountDocPropertyPagesSEL, _gPID)))

#define FRAppRegistryGetKeyCounts (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetKeyCountsSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetKeyCountsSEL, _gPID)))

#define FRAppRegistryGetKeyName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetKeyNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetKeyNameSEL, _gPID)))

#define FRAppGetRibbonBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonBarSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonBarSEL, _gPID)))

#define FRAppGetRibbonBarBackGroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonBarBackGroundColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonBarBackGroundColorSEL, _gPID)))

#define FRAppLoadLibrary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppLoadLibrarySELPROTO)FRCOREROUTINE(FRAppSEL,FRAppLoadLibrarySEL, _gPID)))

#define FRAppRemoveFileFromRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRemoveFileFromRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRemoveFileFromRecentFileListSEL, _gPID)))

#define FRAppIsLicenseValidOrInTrial (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsLicenseValidOrInTrialSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsLicenseValidOrInTrialSEL, _gPID)))

#define FRAppShowPreferenceDlg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppShowPreferenceDlgSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppShowPreferenceDlgSEL, _gPID)))

#define FRAppGetRecentFileListSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRecentFileListSizeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRecentFileListSizeSEL, _gPID)))

#define FRAppGetModuleFileName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetModuleFileNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetModuleFileNameSEL, _gPID)))

#define FRAppRegisterCmdMsgEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterCmdMsgEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterCmdMsgEventHandlerSEL, _gPID)))

#define FRAppUnRegisterCmdMsgEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterCmdMsgEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterCmdMsgEventHandlerSEL, _gPID)))

#define FRAppRemoveTaskPanelByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRemoveTaskPanelByNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRemoveTaskPanelByNameSEL, _gPID)))

#define FRAppDisableAllPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppDisableAllPanelSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppDisableAllPanelSEL, _gPID)))

#define FRAppIsDisableAllPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsDisableAllPanelSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsDisableAllPanelSEL, _gPID)))

#define FRAppGetPageContextMenuPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetPageContextMenuPosSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetPageContextMenuPosSEL, _gPID)))

#define FRAppRedrawRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRedrawRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRedrawRecentFileListSEL, _gPID)))

#define FRAppIsRTLLanguage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsRTLLanguageSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsRTLLanguageSEL, _gPID)))

#define FRAppRegisterPOEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterPOEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterPOEventHandlerSEL, _gPID)))

#define FRAppCreateBlankDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCreateBlankDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCreateBlankDocSEL, _gPID)))

#define FRAppGetLocalFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetLocalFontNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetLocalFontNameSEL, _gPID)))

#define FRAppGetNavPanelViewByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetNavPanelViewByNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetNavPanelViewByNameSEL, _gPID)))

#define FRAppGetNavPanelNameByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetNavPanelNameByIndexSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetNavPanelNameByIndexSEL, _gPID)))

#define FRAppGetNavPanelCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetNavPanelCountSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetNavPanelCountSEL, _gPID)))

#define FRAppGetStatusBarBkGroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetStatusBarBkGroundColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetStatusBarBkGroundColorSEL, _gPID)))

#define FRAppCountAllTypesVisibleDocuments (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCountAllTypesVisibleDocumentsSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCountAllTypesVisibleDocumentsSEL, _gPID)))

#define FRAppGetKeyfileStartAndExpireDate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetKeyfileStartAndExpireDateSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetKeyfileStartAndExpireDateSEL, _gPID)))

#define FRAppGetRibbonCategoryColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonCategoryColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonCategoryColorSEL, _gPID)))

#define FRAppGetRibbonElementColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonElementColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonElementColorSEL, _gPID)))

#define FRAppGetRibbonBaseBorderColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonBaseBorderColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonBaseBorderColorSEL, _gPID)))

#define FRAppGetRecentFolderListSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRecentFolderListSizeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRecentFolderListSizeSEL, _gPID)))

#define FRAppIsReadMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsReadModeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsReadModeSEL, _gPID)))

#define FRAppExitReadMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppExitReadModeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppExitReadModeSEL, _gPID)))

#define FRAppGetCurrentChildFrm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetCurrentChildFrmSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetCurrentChildFrmSEL, _gPID)))

#define FRAppActiveChildFrame (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppActiveChildFrameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppActiveChildFrameSEL, _gPID)))

#define FRAppSetMainframeShow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetMainframeShowSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetMainframeShowSEL, _gPID)))

#define FRAppGetMainframeShow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetMainframeShowSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetMainframeShowSEL, _gPID)))

#define FRAppGetRibbonTooltipBorderColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonTooltipBorderColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonTooltipBorderColorSEL, _gPID)))

#define FRAppGetRecentFileIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRecentFileIndexSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRecentFileIndexSEL, _gPID)))

#define FRAppFZipUnzip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppFZipUnzipSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppFZipUnzipSEL, _gPID)))

#define FRAppIsJSEnabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsJSEnabledSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsJSEnabledSEL, _gPID)))

#define FRAppSetEnableJS (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetEnableJSSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetEnableJSSEL, _gPID)))

#define FRAppAddNavPanelView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddNavPanelViewSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddNavPanelViewSEL, _gPID)))

#define FRAppReleaseNavPanelView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppReleaseNavPanelViewSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppReleaseNavPanelViewSEL, _gPID)))

#define FRAppAddFileAttachment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddFileAttachmentSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddFileAttachmentSEL, _gPID)))

#define FRAppOpenFileAttachment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppOpenFileAttachmentSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppOpenFileAttachmentSEL, _gPID)))

#define FRAppIsPDF2Doc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsPDF2DocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsPDF2DocSEL, _gPID)))

#define FRAppConvertToPDF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppConvertToPDFSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppConvertToPDFSEL, _gPID)))

#define FRAppConvertToPDFA (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppConvertToPDFASELPROTO)FRCOREROUTINE(FRAppSEL,FRAppConvertToPDFASEL, _gPID)))

#define FRAppGetRibbonBar2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonBar2SELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonBar2SEL, _gPID)))

#define FRAppGetConvertPDFErrMsg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetConvertPDFErrMsgSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetConvertPDFErrMsgSEL, _gPID)))

#define FRAppDeleteAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppDeleteAnnotSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppDeleteAnnotSEL, _gPID)))

#define FRAppGetSystemDefaultFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetSystemDefaultFontSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetSystemDefaultFontSEL, _gPID)))

#define FRAppUnRegisterDocHandlerOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterDocHandlerOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterDocHandlerOfPDDocSEL, _gPID)))

#define FRAppCountTaskPaneName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCountTaskPaneNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCountTaskPaneNameSEL, _gPID)))

#define FRAppGetTaskPaneNameByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetTaskPaneNameByIndexSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetTaskPaneNameByIndexSEL, _gPID)))

#define FRAppGetDocUnit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetDocUnitSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetDocUnitSEL, _gPID)))

#define FRAppChangeUnits (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppChangeUnitsSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppChangeUnitsSEL, _gPID)))

#define FRAppGetMetaDataOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetMetaDataOptionSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetMetaDataOptionSEL, _gPID)))

#define FRAppGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetDocumentSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetDocumentSEL, _gPID)))

#define FRAppAddShareMessageBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddShareMessageBarSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddShareMessageBarSEL, _gPID)))

#define FRAppShowShareMessageBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppShowShareMessageBarSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppShowShareMessageBarSEL, _gPID)))

#define FRAppGetAppPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetAppPathSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetAppPathSEL, _gPID)))

#define FRAppRegisterPanelToolHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterPanelToolHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterPanelToolHandlerSEL, _gPID)))

#define FRAppIsTaskPaneShow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsTaskPaneShowSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsTaskPaneShowSEL, _gPID)))

#define FRAppRegisterPluginEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterPluginEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterPluginEventHandlerSEL, _gPID)))

#define FRAppUnregisterPluginEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnregisterPluginEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnregisterPluginEventHandlerSEL, _gPID)))

#define FRAppUnRegisterSecurityHandler2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterSecurityHandler2SELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterSecurityHandler2SEL, _gPID)))

#define FRAppToDecryptFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppToDecryptFileSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppToDecryptFileSEL, _gPID)))

#define FRAppDeleteDecryptFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppDeleteDecryptFileSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppDeleteDecryptFileSEL, _gPID)))

#define FRAppUnRegisterPOEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterPOEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterPOEventHandlerSEL, _gPID)))

#define FRAppUnRegisterTool (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterToolSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterToolSEL, _gPID)))

#define FRAppRegisterDRMEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterDRMEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterDRMEventHandlerSEL, _gPID)))

#define FRAppUnRegisterDRMEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterDRMEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterDRMEventHandlerSEL, _gPID)))

#define FRAppShowTaskPane2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppShowTaskPane2SELPROTO)FRCOREROUTINE(FRAppSEL,FRAppShowTaskPane2SEL, _gPID)))

#define FRAppRegisterStartPageEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterStartPageEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterStartPageEventHandlerSEL, _gPID)))

#define FRAppUnRegisterStartPageEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterStartPageEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterStartPageEventHandlerSEL, _gPID)))

#define FRAppRegisterUndoEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterUndoEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterUndoEventHandlerSEL, _gPID)))

#define FRAppUnRegisterUndoEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterUndoEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterUndoEventHandlerSEL, _gPID)))

#define FRAppAddFileAttachment2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddFileAttachment2SELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddFileAttachment2SEL, _gPID)))

//*****************************
/* Language HFT functions */
//*****************************

#define FRLanguageCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageCreateSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageCreateSEL, _gPID)))

#define FRLanguageRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageReleaseSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageReleaseSEL, _gPID)))

#define FRLanguageChange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageChangeSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageChangeSEL, _gPID)))

#define FRLanguageGetCurrentID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageGetCurrentIDSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageGetCurrentIDSEL, _gPID)))

#define FRLanguageTranslateMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageTranslateMenuSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageTranslateMenuSEL, _gPID)))

#define FRLanguageTranslateDialog (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageTranslateDialogSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageTranslateDialogSEL, _gPID)))

#define FRLanguageLoadString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageLoadStringSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageLoadStringSEL, _gPID)))

#define FRLanguageLoadVersionRes (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageLoadVersionResSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageLoadVersionResSEL, _gPID)))

#define FRLanguageGetLocalLangName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageGetLocalLangNameSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageGetLocalLangNameSEL, _gPID)))

#define FRLanguageTranslateDialog2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageTranslateDialog2SELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageTranslateDialog2SEL, _gPID)))

#define FRLanguageModifyLogFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageModifyLogFontSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageModifyLogFontSEL, _gPID)))

#define FRLanguageFormatEx (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageFormatExSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageFormatExSEL, _gPID)))

#define FRLanguageJSPluginGetMessage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageJSPluginGetMessageSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageJSPluginGetMessageSEL, _gPID)))

#define FRLanguageReleaseDialogUIFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageReleaseDialogUIFontSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageReleaseDialogUIFontSEL, _gPID)))

//*****************************
/* UIProgress HFT functions */
//*****************************

#define FRUIProgressCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressCreateSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressCreateSEL, _gPID)))

#define FRUIProgressSetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressSetTextSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressSetTextSEL, _gPID)))

#define FRUIProgressSetRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressSetRangeSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressSetRangeSEL, _gPID)))

#define FRUIProgressSetCurrValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressSetCurrValueSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressSetCurrValueSEL, _gPID)))

#define FRUIProgressPeekAndPump (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressPeekAndPumpSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressPeekAndPumpSEL, _gPID)))

#define FRUIProgressIsCancelled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressIsCancelledSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressIsCancelledSEL, _gPID)))

#define FRUIProgressGetCurrentValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressGetCurrentValueSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressGetCurrentValueSEL, _gPID)))

#define FRUIProgressDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressDestroySELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressDestroySEL, _gPID)))

#define FRUIProgressDoCancel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressDoCancelSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressDoCancelSEL, _gPID)))

#define FRUIProgressCreate2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressCreate2SELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressCreate2SEL, _gPID)))

#define FRUIProgressCreate3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressCreate3SELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressCreate3SEL, _gPID)))

#define FRUIProgressGetHwnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressGetHwndSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressGetHwndSEL, _gPID)))

#define FRUIProgressSetSecondLineText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressSetSecondLineTextSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressSetSecondLineTextSEL, _gPID)))

#define FRUIProgressGetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressGetTextSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressGetTextSEL, _gPID)))

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* Internal HFT functions */
//*****************************

//*****************************
/* SpellCheck HFT functions */
//*****************************

#define FRSpellCheckNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSpellCheckNewSELPROTO)FRCOREROUTINE(FRSpellCheckSEL,FRSpellCheckNewSEL, _gPID)))

#define FRSpellCheckIgnore (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSpellCheckIgnoreSELPROTO)FRCOREROUTINE(FRSpellCheckSEL,FRSpellCheckIgnoreSEL, _gPID)))

#define FRSpellCheckCheckString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSpellCheckCheckStringSELPROTO)FRCOREROUTINE(FRSpellCheckSEL,FRSpellCheckCheckStringSEL, _gPID)))

#define FRSpellCheckAddDic (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSpellCheckAddDicSELPROTO)FRCOREROUTINE(FRSpellCheckSEL,FRSpellCheckAddDicSEL, _gPID)))

//----------_V6----------
//----------_V7----------
//*****************************
/* HTMLMgr HFT functions */
//*****************************

//*****************************
/* PanelMgr HFT functions */
//*****************************

//----------_V8----------
//----------_V9----------
//*****************************
/* CloudLoginProvider HFT functions */
//*****************************

//----------_V10----------
//----------_V11----------
//----------_V12----------
//*****************************
/* AssistantMgr HFT functions */
//*****************************

//----------_V13----------
//*****************************
/* IReader HFT functions */
//*****************************

//*****************************
/* IFX HFT functions */
//*****************************

//*****************************
/* InputMethodHandler HFT functions */
//*****************************

//----------_V14----------
//*****************************
/* MarkAnnotHandler HFT functions */
//*****************************

//*****************************
/* ReaderUserMessageHandler HFT functions */
//*****************************

//*****************************
/* IFieldMulCopiesNotify HFT functions */
//*****************************

//*****************************
/* IActionWizardData HFT functions */
//*****************************

//*****************************
/* CMapItemNameToData HFT functions */
//*****************************

//*****************************
/* ReaderUIMgr HFT functions */
//*****************************

//*****************************
/* ReaderTheme HFT functions */
//*****************************

//*****************************
/* PluginsMamager HFT functions */
//*****************************

#define FRPluginsMamagerIsLoadedPlugin (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPluginsMamagerIsLoadedPluginSELPROTO)FRCOREROUTINE(FRPluginsMamagerSEL,FRPluginsMamagerIsLoadedPluginSEL, _gPID)))

#define FRPluginsMamagerIsDisabledPlugin (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPluginsMamagerIsDisabledPluginSELPROTO)FRCOREROUTINE(FRPluginsMamagerSEL,FRPluginsMamagerIsDisabledPluginSEL, _gPID)))

//*****************************
/* IReplaceAllNotify HFT functions */
//*****************************

//*****************************
/* IFindReplaceMgr HFT functions */
//*****************************

//*****************************
/* PDFBitmap HFT functions */
//*****************************

//*****************************
/* Accessibility HFT functions */
//*****************************

#define FRAccessibilityIsScreenReaderRunning (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAccessibilityIsScreenReaderRunningSELPROTO)FRCOREROUTINE(FRAccessibilitySEL,FRAccessibilityIsScreenReaderRunningSEL, _gPID)))

#define FRAccessibilityIsATSupportEnabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAccessibilityIsATSupportEnabledSELPROTO)FRCOREROUTINE(FRAccessibilitySEL,FRAccessibilityIsATSupportEnabledSEL, _gPID)))

//*****************************
/* AppUIStyle HFT functions */
//*****************************

//----------_V15----------
//----------_V16----------
//*****************************
/* UIMgr HFT functions */
//*****************************

//*****************************
/* ContainerFrmMgrHandler HFT functions */
//*****************************

#define FRContainerFrmMgrHandlerNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRContainerFrmMgrHandlerNewSELPROTO)FRCOREROUTINE(FRContainerFrmMgrHandlerSEL,FRContainerFrmMgrHandlerNewSEL, _gPID)))

#define FRContainerFrmMgrHandlerDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRContainerFrmMgrHandlerDestroySELPROTO)FRCOREROUTINE(FRContainerFrmMgrHandlerSEL,FRContainerFrmMgrHandlerDestroySEL, _gPID)))

//*****************************
/* ContainerFrmMgr HFT functions */
//*****************************

#define FRContainerFrmMgrGetContainerFrmMgr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRContainerFrmMgrGetContainerFrmMgrSELPROTO)FRCOREROUTINE(FRContainerFrmMgrSEL,FRContainerFrmMgrGetContainerFrmMgrSEL, _gPID)))

#define FRContainerFrmMgrCreateContainerFrame (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRContainerFrmMgrCreateContainerFrameSELPROTO)FRCOREROUTINE(FRContainerFrmMgrSEL,FRContainerFrmMgrCreateContainerFrameSEL, _gPID)))

#define FRContainerFrmMgrGetContainerFrame (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRContainerFrmMgrGetContainerFrameSELPROTO)FRCOREROUTINE(FRContainerFrmMgrSEL,FRContainerFrmMgrGetContainerFrameSEL, _gPID)))

#define FRContainerFrmMgrOpenDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRContainerFrmMgrOpenDocumentSELPROTO)FRCOREROUTINE(FRContainerFrmMgrSEL,FRContainerFrmMgrOpenDocumentSEL, _gPID)))

#define FRContainerFrmMgrRegisterContainerFrmEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRContainerFrmMgrRegisterContainerFrmEventHandlerSELPROTO)FRCOREROUTINE(FRContainerFrmMgrSEL,FRContainerFrmMgrRegisterContainerFrmEventHandlerSEL, _gPID)))

#define FRContainerFrmMgrUnRegisterContainerFrmEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRContainerFrmMgrUnRegisterContainerFrmEventHandlerSELPROTO)FRCOREROUTINE(FRContainerFrmMgrSEL,FRContainerFrmMgrUnRegisterContainerFrmEventHandlerSEL, _gPID)))

#define FRContainerFrmMgrOnContainerFrmCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRContainerFrmMgrOnContainerFrmCreateSELPROTO)FRCOREROUTINE(FRContainerFrmMgrSEL,FRContainerFrmMgrOnContainerFrmCreateSEL, _gPID)))

#define FRContainerFrmMgrOnContainerFrmLoadFinish (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRContainerFrmMgrOnContainerFrmLoadFinishSELPROTO)FRCOREROUTINE(FRContainerFrmMgrSEL,FRContainerFrmMgrOnContainerFrmLoadFinishSEL, _gPID)))

#define FRContainerFrmMgrOnContainerFrmDestory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRContainerFrmMgrOnContainerFrmDestorySELPROTO)FRCOREROUTINE(FRContainerFrmMgrSEL,FRContainerFrmMgrOnContainerFrmDestorySEL, _gPID)))

//*****************************
/* PrintProvider HFT functions */
//*****************************

#define FRPrintProviderGetPrintProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintProviderGetPrintProviderSELPROTO)FRCOREROUTINE(FRPrintProviderSEL,FRPrintProviderGetPrintProviderSEL, _gPID)))

#define FRPrintProviderGetPrintDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintProviderGetPrintDocSELPROTO)FRCOREROUTINE(FRPrintProviderSEL,FRPrintProviderGetPrintDocSEL, _gPID)))

#define FRPrintProviderGetDefaultPrinterName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintProviderGetDefaultPrinterNameSELPROTO)FRCOREROUTINE(FRPrintProviderSEL,FRPrintProviderGetDefaultPrinterNameSEL, _gPID)))

#define FRPrintProviderIsSnapShot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintProviderIsSnapShotSELPROTO)FRCOREROUTINE(FRPrintProviderSEL,FRPrintProviderIsSnapShotSEL, _gPID)))

#define FRPrintProviderGetDispMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintProviderGetDispModeSELPROTO)FRCOREROUTINE(FRPrintProviderSEL,FRPrintProviderGetDispModeSEL, _gPID)))

#define FRPrintProviderGetDefaultPrinterDevMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintProviderGetDefaultPrinterDevModeSELPROTO)FRCOREROUTINE(FRPrintProviderSEL,FRPrintProviderGetDefaultPrinterDevModeSEL, _gPID)))

#define FRPrintProviderSetDefaultPrinterDevMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintProviderSetDefaultPrinterDevModeSELPROTO)FRCOREROUTINE(FRPrintProviderSEL,FRPrintProviderSetDefaultPrinterDevModeSEL, _gPID)))

#define FRPrintProviderAnnotsSortByOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintProviderAnnotsSortByOrderSELPROTO)FRCOREROUTINE(FRPrintProviderSEL,FRPrintProviderAnnotsSortByOrderSEL, _gPID)))

#define FRPrintProviderGetPrintParentHwnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintProviderGetPrintParentHwndSELPROTO)FRCOREROUTINE(FRPrintProviderSEL,FRPrintProviderGetPrintParentHwndSEL, _gPID)))

#define FRPrintProviderReleasePrintProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintProviderReleasePrintProviderSELPROTO)FRCOREROUTINE(FRPrintProviderSEL,FRPrintProviderReleasePrintProviderSEL, _gPID)))

//*****************************
/* WndProvider HFT functions */
//*****************************

#define FRWndProviderGetCurrentWndProvide (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWndProviderGetCurrentWndProvideSELPROTO)FRCOREROUTINE(FRWndProviderSEL,FRWndProviderGetCurrentWndProvideSEL, _gPID)))

#define FRWndProviderGetProviderName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWndProviderGetProviderNameSELPROTO)FRCOREROUTINE(FRWndProviderSEL,FRWndProviderGetProviderNameSEL, _gPID)))

//*****************************
/* GlobalData HFT functions */
//*****************************

//*****************************
/* HandlerDataType HFT functions */
//*****************************

//*****************************
/* MuCopyData HFT functions */
//*****************************

//----------_V17----------
//*****************************
/* PrintMgr HFT functions */
//*****************************

#define FRPrintMgrCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrCreateSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrCreateSEL, _gPID)))

#define FRPrintMgrDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrDeleteSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrDeleteSEL, _gPID)))

#define FRPrintMgrSetPrintRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintRangeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintRangeSEL, _gPID)))

#define FRPrintMgrGetPrintRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintRangeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintRangeSEL, _gPID)))

#define FRPrintMgrSetPrintSubset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintSubsetSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintSubsetSEL, _gPID)))

#define FRPrintMgrGetPrintSubset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintSubsetSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintSubsetSEL, _gPID)))

#define FRPrintMgrSetPrintRotate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintRotateSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintRotateSEL, _gPID)))

#define FRPrintMgrGetPrintRotate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintRotateSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintRotateSEL, _gPID)))

#define FRPrintMgrSetPrintScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintScaleSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintScaleSEL, _gPID)))

#define FRPrintMgrGetPrintScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintScaleSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintScaleSEL, _gPID)))

#define FRPrintMgrSetPrintArrange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintArrangeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintArrangeSEL, _gPID)))

#define FRPrintMgrGetPrintArrange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintArrangeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintArrangeSEL, _gPID)))

#define FRPrintMgrSetPrintCopies (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintCopiesSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintCopiesSEL, _gPID)))

#define FRPrintMgrGetPrintCopies (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintCopiesSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintCopiesSEL, _gPID)))

#define FRPrintMgrSetPrintAutoCenter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintAutoCenterSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintAutoCenterSEL, _gPID)))

#define FRPrintMgrGetPrintAutoCenter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintAutoCenterSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintAutoCenterSEL, _gPID)))

#define FRPrintMgrSetPrintAutoRotate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintAutoRotateSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintAutoRotateSEL, _gPID)))

#define FRPrintMgrGetPrintAutoRotate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintAutoRotateSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintAutoRotateSEL, _gPID)))

#define FRPrintMgrSetPrintGray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintGraySELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintGraySEL, _gPID)))

#define FRPrintMgrGetPrintGray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintGraySELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintGraySEL, _gPID)))

#define FRPrintMgrSetPrintCollate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintCollateSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintCollateSEL, _gPID)))

#define FRPrintMgrGetPrintCollate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintCollateSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintCollateSEL, _gPID)))

#define FRPrintMgrSetPrintPageOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintPageOrderSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintPageOrderSEL, _gPID)))

#define FRPrintMgrSetPrintPageBorder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintPageBorderSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintPageBorderSEL, _gPID)))

#define FRPrintMgrGetPrintPageBorder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintPageBorderSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintPageBorderSEL, _gPID)))

#define FRPrintMgrSetPrintPrintWhat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintPrintWhatSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintPrintWhatSEL, _gPID)))

#define FRPrintMgrSetPrintOrientation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintOrientationSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintOrientationSEL, _gPID)))

#define FRPrintMgrSetPrintPagesPerSheet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintPagesPerSheetSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintPagesPerSheetSEL, _gPID)))

#define FRPrintMgrGetPrintPagesPerSheet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintPagesPerSheetSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintPagesPerSheetSEL, _gPID)))

#define FRPrintMgrSetPrintPaperSizeByPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintPaperSizeByPageSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintPaperSizeByPageSEL, _gPID)))

#define FRPrintMgrSetPrintReverse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintReverseSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintReverseSEL, _gPID)))

#define FRPrintMgrGetPrintReverse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintReverseSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintReverseSEL, _gPID)))

#define FRPrintMgrSetPrintMargins (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintMarginsSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintMarginsSEL, _gPID)))

#define FRPrintMgrSetPrintAsImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintAsImageSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintAsImageSEL, _gPID)))

#define FRPrintMgrSetSimulateOverprinting (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetSimulateOverprintingSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetSimulateOverprintingSEL, _gPID)))

#define FRPrintMgrSetPrintIgnoreAdvancedSetting (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintIgnoreAdvancedSettingSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintIgnoreAdvancedSettingSEL, _gPID)))

#define FRPrintMgrSetProgressDisplay (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetProgressDisplaySELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetProgressDisplaySEL, _gPID)))

#define FRPrintMgrSetPaperSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPaperSizeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPaperSizeSEL, _gPID)))

#define FRPrintMgrSetPrintPageArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintPageArraySELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintPageArraySEL, _gPID)))

#define FRPrintMgrGetPrintPageArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintPageArraySELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintPageArraySEL, _gPID)))

#define FRPrintMgrGetDefaultPrint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetDefaultPrintSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetDefaultPrintSEL, _gPID)))

#define FRPrintMgrSetDefaultPrint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetDefaultPrintSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetDefaultPrintSEL, _gPID)))

#define FRPrintMgrSetPrintOutputFileName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintOutputFileNameSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintOutputFileNameSEL, _gPID)))

#define FRPrintMgrDoModal (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrDoModalSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrDoModalSEL, _gPID)))

#define FRPrintMgrSetPrintDevMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintDevModeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintDevModeSEL, _gPID)))

#define FRPrintMgrSetPrintPreview (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintPreviewSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintPreviewSEL, _gPID)))

#define FRPrintMgrEnablePrintAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrEnablePrintAnnotSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrEnablePrintAnnotSEL, _gPID)))

#define FRPrintMgrSetRangeMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetRangeModeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetRangeModeSEL, _gPID)))

#define FRPrintMgrGetRangeMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetRangeModeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetRangeModeSEL, _gPID)))

#define FRPrintMgrSetPrintBookletBinding (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintBookletBindingSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintBookletBindingSEL, _gPID)))

#define FRPrintMgrSetPrintBookletSubSet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintBookletSubSetSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintBookletSubSetSEL, _gPID)))

#define FRPrintMgrSetPrintCutMarks (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintCutMarksSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintCutMarksSEL, _gPID)))

#define FRPrintMgrSetPrintLabels (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintLabelsSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintLabelsSEL, _gPID)))

#define FRPrintMgrSetPrintPageScaleType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintPageScaleTypeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintPageScaleTypeSEL, _gPID)))

#define FRPrintMgrEnumPrinterName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrEnumPrinterNameSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrEnumPrinterNameSEL, _gPID)))

#define FRPrintMgrSetPrintDuplexType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintDuplexTypeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintDuplexTypeSEL, _gPID)))

#define FRPrintMgrSetPrintOverlap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintOverlapSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintOverlapSEL, _gPID)))

#define FRPrintMgrSetPrintHandlingType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrSetPrintHandlingTypeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrSetPrintHandlingTypeSEL, _gPID)))

#define FRPrintMgrGetPrintHandlingType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPrintMgrGetPrintHandlingTypeSELPROTO)FRCOREROUTINE(FRPrintMgrSEL,FRPrintMgrGetPrintHandlingTypeSEL, _gPID)))

//*****************************
/* EncryptedDocMgr HFT functions */
//*****************************

//*****************************
/* PDFBitmapMgr HFT functions */
//*****************************

//----------_V18----------
//----------_V19----------
//*****************************
/* StartPageEventHandler HFT functions */
//*****************************

#define FRStartPageEventHandlerNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStartPageEventHandlerNewSELPROTO)FRCOREROUTINE(FRStartPageEventHandlerSEL,FRStartPageEventHandlerNewSEL, _gPID)))

#define FRStartPageEventHandlerDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStartPageEventHandlerDeleteSELPROTO)FRCOREROUTINE(FRStartPageEventHandlerSEL,FRStartPageEventHandlerDeleteSEL, _gPID)))

//*****************************
/* UndoEventHandler HFT functions */
//*****************************

#define FRUndoEventHandlerNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUndoEventHandlerNewSELPROTO)FRCOREROUTINE(FRUndoEventHandlerSEL,FRUndoEventHandlerNewSEL, _gPID)))

#define FRUndoEventHandlerDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUndoEventHandlerDeleteSELPROTO)FRCOREROUTINE(FRUndoEventHandlerSEL,FRUndoEventHandlerDeleteSEL, _gPID)))

//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
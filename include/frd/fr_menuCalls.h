/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FR_MENUCALLS_H
#define FR_MENUCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_MENUEXPT_H
#include "fr_menuExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fr_menuImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fr_menuTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fr_menuImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fr_menuTempl.h"

//----------_V1----------
//*****************************
/* MenuBar HFT functions */
//*****************************

#define FRMenuBarGetMenuCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuBarGetMenuCountSELPROTO)FRCOREROUTINE(FRMenuBarSEL,FRMenuBarGetMenuCountSEL, _gPID)))

#define FRMenuBarGetMenuByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuBarGetMenuByIndexSELPROTO)FRCOREROUTINE(FRMenuBarSEL,FRMenuBarGetMenuByIndexSEL, _gPID)))

#define FRMenuBarGetMenuByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuBarGetMenuByNameSELPROTO)FRCOREROUTINE(FRMenuBarSEL,FRMenuBarGetMenuByNameSEL, _gPID)))

#define FRMenuBarAddMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuBarAddMenuSELPROTO)FRCOREROUTINE(FRMenuBarSEL,FRMenuBarAddMenuSEL, _gPID)))

#define FRMenuBarGetMenuIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuBarGetMenuIndexSELPROTO)FRCOREROUTINE(FRMenuBarSEL,FRMenuBarGetMenuIndexSEL, _gPID)))

#define FRMenuBarDeleteMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuBarDeleteMenuSELPROTO)FRCOREROUTINE(FRMenuBarSEL,FRMenuBarDeleteMenuSEL, _gPID)))

//*****************************
/* Menu HFT functions */
//*****************************

#define FRMenuNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuNewSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuNewSEL, _gPID)))

#define FRMenuRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuReleaseSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuReleaseSEL, _gPID)))

#define FRMenuGetParentMenuItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuGetParentMenuItemSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuGetParentMenuItemSEL, _gPID)))

#define FRMenuGetMenuItemByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuGetMenuItemByIndexSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuGetMenuItemByIndexSEL, _gPID)))

#define FRMenuGetMenuItemByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuGetMenuItemByNameSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuGetMenuItemByNameSEL, _gPID)))

#define FRMenuGetMenuItemCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuGetMenuItemCountSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuGetMenuItemCountSEL, _gPID)))

#define FRMenuAddMenuItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuAddMenuItemSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuAddMenuItemSEL, _gPID)))

#define FRMenuDeleteMenuItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuDeleteMenuItemSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuDeleteMenuItemSEL, _gPID)))

#define FRMenuGetMenuItemIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuGetMenuItemIndexSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuGetMenuItemIndexSEL, _gPID)))

#define FRMenuDeleteOwnerDrawHandle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuDeleteOwnerDrawHandleSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuDeleteOwnerDrawHandleSEL, _gPID)))

#define FRMenuRegisterOwnerDrawHandle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuRegisterOwnerDrawHandleSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuRegisterOwnerDrawHandleSEL, _gPID)))

#define FRMenuTrackPopup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuTrackPopupSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuTrackPopupSEL, _gPID)))

#define FRMenuSetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuSetVisibleSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuSetVisibleSEL, _gPID)))

#define FRMenuGetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuGetVisibleSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuGetVisibleSEL, _gPID)))

#define FRMenuSetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuSetTitleSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuSetTitleSEL, _gPID)))

#define FRMenuNewII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuNewIISELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuNewIISEL, _gPID)))

#define FRMenuTrackPopupMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuTrackPopupMenuSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuTrackPopupMenuSEL, _gPID)))

#define FRMenuCloseActivePopupMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuCloseActivePopupMenuSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuCloseActivePopupMenuSEL, _gPID)))

#define FRMenuNew3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuNew3SELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuNew3SEL, _gPID)))

#define FRMenuDoPopupMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuDoPopupMenuSELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuDoPopupMenuSEL, _gPID)))

#define FRMenuTrackPopupMenu2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuTrackPopupMenu2SELPROTO)FRCOREROUTINE(FRMenuSEL,FRMenuTrackPopupMenu2SEL, _gPID)))

//*****************************
/* MenuItem HFT functions */
//*****************************

#define FRMenuItemNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemNewSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemNewSEL, _gPID)))

#define FRMenuItemRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemReleaseSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemReleaseSEL, _gPID)))

#define FRMenuItemGetSubMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemGetSubMenuSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemGetSubMenuSEL, _gPID)))

#define FRMenuItemSetSubMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetSubMenuSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetSubMenuSEL, _gPID)))

#define FRMenuItemGetParentMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemGetParentMenuSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemGetParentMenuSEL, _gPID)))

#define FRMenuItemGetIcon (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemGetIconSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemGetIconSEL, _gPID)))

#define FRMenuItemSetIcon (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetIconSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetIconSEL, _gPID)))

#define FRMenuItemGetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemGetTitleSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemGetTitleSEL, _gPID)))

#define FRMenuItemSetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetTitleSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetTitleSEL, _gPID)))

#define FRMenuItemGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemGetNameSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemGetNameSEL, _gPID)))

#define FRMenuItemSetToolTip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetToolTipSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetToolTipSEL, _gPID)))

#define FRMenuItemSetDescribeText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetDescribeTextSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetDescribeTextSEL, _gPID)))

#define FRMenuItemIsSeparator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemIsSeparatorSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemIsSeparatorSEL, _gPID)))

#define FRMenuItemSetExecuteProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetExecuteProcSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetExecuteProcSEL, _gPID)))

#define FRMenuItemSetComputeEnabledProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetComputeEnabledProcSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetComputeEnabledProcSEL, _gPID)))

#define FRMenuItemSetComputeMarkedProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetComputeMarkedProcSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetComputeMarkedProcSEL, _gPID)))

#define FRMenuItemDoExecuteProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemDoExecuteProcSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemDoExecuteProcSEL, _gPID)))

#define FRMenuItemIsEnabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemIsEnabledSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemIsEnabledSEL, _gPID)))

#define FRMenuItemIsMarked (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemIsMarkedSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemIsMarkedSEL, _gPID)))

#define FRMenuItemGetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemGetClientDataSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemGetClientDataSEL, _gPID)))

#define FRMenuItemSetAccelKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetAccelKeySELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetAccelKeySEL, _gPID)))

#define FRMenuItemGetCmdID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemGetCmdIDSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemGetCmdIDSEL, _gPID)))

#define FRMenuItemSetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetClientDataSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetClientDataSEL, _gPID)))

#define FRMenuItemSetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetVisibleSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetVisibleSEL, _gPID)))

#define FRMenuItemGetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemGetVisibleSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemGetVisibleSEL, _gPID)))

#define FRMenuItemSetBitmapIconWithIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetBitmapIconWithIndexSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetBitmapIconWithIndexSEL, _gPID)))

#define FRMenuItemSetPDFBitmapName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMenuItemSetPDFBitmapNameSELPROTO)FRCOREROUTINE(FRMenuItemSEL,FRMenuItemSetPDFBitmapNameSEL, _gPID)))

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
//----------_V11----------
//----------_V12----------
//----------_V13----------
//----------_V14----------
//----------_V15----------
//----------_V16----------
//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
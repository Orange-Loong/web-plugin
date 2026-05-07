/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FR_SYSCALLS_H
#define FR_SYSCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_SYSEXPT_H
#include "fr_sysExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fr_sysImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fr_sysTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fr_sysImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fr_sysTempl.h"

//----------_V1----------
//*****************************
/* Sys HFT functions */
//*****************************

#define FRSysLoadStandarCursor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysLoadStandarCursorSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysLoadStandarCursorSEL, _gPID)))

#define FRSysGetCursor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysGetCursorSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysGetCursorSEL, _gPID)))

#define FRSysSetCursor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysSetCursorSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysSetCursorSEL, _gPID)))

#define FRSysShowMessageBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysShowMessageBoxSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysShowMessageBoxSEL, _gPID)))

#define FRSysInstallDialogSkinTheme (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysInstallDialogSkinThemeSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysInstallDialogSkinThemeSEL, _gPID)))

#define FRSysInstallDialogScrollBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysInstallDialogScrollBarSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysInstallDialogScrollBarSEL, _gPID)))

#define FRSysGetSkinCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysGetSkinCountSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysGetSkinCountSEL, _gPID)))

#define FRSysGetSkinNameByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysGetSkinNameByIndexSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysGetSkinNameByIndexSEL, _gPID)))

#define FRSysSetActiveSkinByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysSetActiveSkinByIndexSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysSetActiveSkinByIndexSEL, _gPID)))

#define FRSysSetActiveSkinByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysSetActiveSkinByNameSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysSetActiveSkinByNameSEL, _gPID)))

#define FRSysShowStopLaunchDlg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysShowStopLaunchDlgSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysShowStopLaunchDlgSEL, _gPID)))

#define FRSysShowMessageBox2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysShowMessageBox2SELPROTO)FRCOREROUTINE(FRSysSEL,FRSysShowMessageBox2SEL, _gPID)))

#define FRSysShowMessageBox3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysShowMessageBox3SELPROTO)FRCOREROUTINE(FRSysSEL,FRSysShowMessageBox3SEL, _gPID)))

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* WindowsDIB HFT functions */
//*****************************

#define FRWindowsDIBNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBNewSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBNewSEL, _gPID)))

#define FRWindowsDIBDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBDestroySELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBDestroySEL, _gPID)))

#define FRWindowsDIBGetBitmapInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBGetBitmapInfoSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBGetBitmapInfoSEL, _gPID)))

#define FRWindowsDIBLoadFromBuf (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadFromBufSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadFromBufSEL, _gPID)))

#define FRWindowsDIBGetDDBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBGetDDBitmapSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBGetDDBitmapSEL, _gPID)))

#define FRWindowsDIBLoadFromDDB (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadFromDDBSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadFromDDBSEL, _gPID)))

#define FRWindowsDIBLoadFromFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadFromFileSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadFromFileSEL, _gPID)))

#define FRWindowsDIBLoadFromFileII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadFromFileIISELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadFromFileIISEL, _gPID)))

#define FRWindowsDIBLoadDIBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadDIBitmapSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadDIBitmapSEL, _gPID)))

#define FRWindowsDIBGetDC (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBGetDCSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBGetDCSEL, _gPID)))

#define FRWindowsDIBGetWindowsBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBGetWindowsBitmapSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBGetWindowsBitmapSEL, _gPID)))

#define FRWindowsDIBLoadFromDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadFromDeviceSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadFromDeviceSEL, _gPID)))

#define FRWindowsDIBSetToDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBSetToDeviceSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBSetToDeviceSEL, _gPID)))

//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
//----------_V11----------
//----------_V12----------
//----------_V13----------
//----------_V14----------
//*****************************
/* SystemHandler HFT functions */
//*****************************

#define FRSystemHandlerIsStandardFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSystemHandlerIsStandardFontSELPROTO)FRCOREROUTINE(FRSystemHandlerSEL,FRSystemHandlerIsStandardFontSEL, _gPID)))

#define FRSystemHandlerGetDefaultFontNameByCharset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSystemHandlerGetDefaultFontNameByCharsetSELPROTO)FRCOREROUTINE(FRSystemHandlerSEL,FRSystemHandlerGetDefaultFontNameByCharsetSEL, _gPID)))

#define FRSystemHandlerSetCursor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSystemHandlerSetCursorSELPROTO)FRCOREROUTINE(FRSystemHandlerSEL,FRSystemHandlerSetCursorSEL, _gPID)))

//*****************************
/* CTBLogFonts HFT functions */
//*****************************

#define FRCTBLogFontsNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCTBLogFontsNewSELPROTO)FRCOREROUTINE(FRCTBLogFontsSEL,FRCTBLogFontsNewSEL, _gPID)))

#define FRCTBLogFontsDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCTBLogFontsDestroySELPROTO)FRCOREROUTINE(FRCTBLogFontsSEL,FRCTBLogFontsDestroySEL, _gPID)))

#define FRCTBLogFontsGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCTBLogFontsGetSizeSELPROTO)FRCOREROUTINE(FRCTBLogFontsSEL,FRCTBLogFontsGetSizeSEL, _gPID)))

#define FRCTBLogFontsGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCTBLogFontsGetAtSELPROTO)FRCOREROUTINE(FRCTBLogFontsSEL,FRCTBLogFontsGetAtSEL, _gPID)))

#define FRCTBLogFontsAdd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCTBLogFontsAddSELPROTO)FRCOREROUTINE(FRCTBLogFontsSEL,FRCTBLogFontsAddSEL, _gPID)))

//*****************************
/* TBSYSFONTDATA HFT functions */
//*****************************

#define FRTBSYSFONTDATACreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATACreateSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATACreateSEL, _gPID)))

#define FRTBSYSFONTDATADestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATADestroySELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATADestroySEL, _gPID)))

#define FRTBSYSFONTDATASetFaceName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATASetFaceNameSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATASetFaceNameSEL, _gPID)))

#define FRTBSYSFONTDATAGetFaceName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATAGetFaceNameSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATAGetFaceNameSEL, _gPID)))

#define FRTBSYSFONTDATASetScriptName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATASetScriptNameSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATASetScriptNameSEL, _gPID)))

#define FRTBSYSFONTDATAGetScriptName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATAGetScriptNameSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATAGetScriptNameSEL, _gPID)))

#define FRTBSYSFONTDATASetTagName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATASetTagNameSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATASetTagNameSEL, _gPID)))

#define FRTBSYSFONTDATAGetTagName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATAGetTagNameSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATAGetTagNameSEL, _gPID)))

#define FRTBSYSFONTDATASetFullName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATASetFullNameSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATASetFullNameSEL, _gPID)))

#define FRTBSYSFONTDATAGetFullName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATAGetFullNameSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATAGetFullNameSEL, _gPID)))

#define FRTBSYSFONTDATASetPSName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATASetPSNameSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATASetPSNameSEL, _gPID)))

#define FRTBSYSFONTDATAGetPSName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATAGetPSNameSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATAGetPSNameSEL, _gPID)))

#define FRTBSYSFONTDATASetNamesArr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATASetNamesArrSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATASetNamesArrSEL, _gPID)))

#define FRTBSYSFONTDATAGetNamesArr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTBSYSFONTDATAGetNamesArrSELPROTO)FRCOREROUTINE(FRTBSYSFONTDATASEL,FRTBSYSFONTDATAGetNamesArrSEL, _gPID)))

//*****************************
/* ITBSysFont HFT functions */
//*****************************

#define FRITBSysFontGetSysFontObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetSysFontObjectSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetSysFontObjectSEL, _gPID)))

#define FRITBSysFontLoadLogFonts (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontLoadLogFontsSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontLoadLogFontsSEL, _gPID)))

#define FRITBSysFontGetSysFontFaceName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetSysFontFaceNameSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetSysFontFaceNameSEL, _gPID)))

#define FRITBSysFontGetAllFormatFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetAllFormatFontSizeSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetAllFormatFontSizeSEL, _gPID)))

#define FRITBSysFontGetAtAllFormatFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetAtAllFormatFontSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetAtAllFormatFontSEL, _gPID)))

#define FRITBSysFontGetFontFaceNameBoldItalic (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetFontFaceNameBoldItalicSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetFontFaceNameBoldItalicSEL, _gPID)))

#define FRITBSysFontGetStdFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetStdFontSizeSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetStdFontSizeSEL, _gPID)))

#define FRITBSysFontGetAtStdFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetAtStdFontSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetAtStdFontSEL, _gPID)))

#define FRITBSysFontGetAtStdFont2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetAtStdFont2SELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetAtStdFont2SEL, _gPID)))

#define FRITBSysFontIsStandardFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontIsStandardFontSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontIsStandardFontSEL, _gPID)))

#define FRITBSysFontGetScriptName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetScriptNameSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetScriptNameSEL, _gPID)))

#define FRITBSysFontFontNamePDF2Name (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontFontNamePDF2NameSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontFontNamePDF2NameSEL, _gPID)))

#define FRITBSysFontGetCharsetByFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetCharsetByFontNameSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetCharsetByFontNameSEL, _gPID)))

#define FRITBSysFontGetBaseFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetBaseFontNameSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetBaseFontNameSEL, _gPID)))

#define FRITBSysFontGetFullName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRITBSysFontGetFullNameSELPROTO)FRCOREROUTINE(FRITBSysFontSEL,FRITBSysFontGetFullNameSEL, _gPID)))

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
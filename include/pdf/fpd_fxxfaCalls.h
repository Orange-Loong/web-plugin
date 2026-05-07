/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_FXXFACALLS_H
#define FPD_FXXFACALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_FXXFAEXPT_H
#include "fpd_fxxfaExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_fxxfaImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_fxxfaTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_fxxfaImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_fxxfaTempl.h"

//----------_V1----------
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
//*****************************
/* XFARenderOptions HFT functions */
//*****************************

#define FPDXFARenderOptionsCreateXFARenderOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsCreateXFARenderOptionsSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsCreateXFARenderOptionsSEL, _gPID)))

#define FPDXFARenderOptionsDeleteXFARenderOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsDeleteXFARenderOptionsSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsDeleteXFARenderOptionsSEL, _gPID)))

#define FPDXFARenderOptionsGetIsPrint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsGetIsPrintSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsGetIsPrintSEL, _gPID)))

#define FPDXFARenderOptionsSetIsPrint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsSetIsPrintSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsSetIsPrintSEL, _gPID)))

#define FPDXFARenderOptionsGetIsHighlight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsGetIsHighlightSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsGetIsHighlightSEL, _gPID)))

#define FPDXFARenderOptionsSetIsHighlight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsSetIsHighlightSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsSetIsHighlightSEL, _gPID)))

#define FPDXFARenderOptionsGetIsConverPdf (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsGetIsConverPdfSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsGetIsConverPdfSEL, _gPID)))

#define FPDXFARenderOptionsSetIsConverPdf (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsSetIsConverPdfSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsSetIsConverPdfSEL, _gPID)))

#define FPDXFARenderOptionsGetColorMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsGetColorModeSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsGetColorModeSEL, _gPID)))

#define FPDXFARenderOptionsSetColorMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsSetColorModeSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsSetColorModeSEL, _gPID)))

#define FPDXFARenderOptionsGetDocTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsGetDocTextColorSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsGetDocTextColorSEL, _gPID)))

#define FPDXFARenderOptionsSetDocTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsSetDocTextColorSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsSetDocTextColorSEL, _gPID)))

#define FPDXFARenderOptionsSetCustomColorMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsSetCustomColorModeSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsSetCustomColorModeSEL, _gPID)))

#define FPDXFARenderOptionsGetCustomColorMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderOptionsGetCustomColorModeSELPROTO)FRCOREROUTINE(FPDXFARenderOptionsSEL,FPDXFARenderOptionsGetCustomColorModeSEL, _gPID)))

//*****************************
/* XFARenderContext HFT functions */
//*****************************

#define FPDXFARenderContextCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderContextCreateSELPROTO)FRCOREROUTINE(FPDXFARenderContextSEL,FPDXFARenderContextCreateSEL, _gPID)))

#define FPDXFARenderContextRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderContextReleaseSELPROTO)FRCOREROUTINE(FPDXFARenderContextSEL,FPDXFARenderContextReleaseSEL, _gPID)))

#define FPDXFARenderContextStartRender (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderContextStartRenderSELPROTO)FRCOREROUTINE(FPDXFARenderContextSEL,FPDXFARenderContextStartRenderSEL, _gPID)))

#define FPDXFARenderContextDoRender (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderContextDoRenderSELPROTO)FRCOREROUTINE(FPDXFARenderContextSEL,FPDXFARenderContextDoRenderSEL, _gPID)))

#define FPDXFARenderContextStopRender (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFARenderContextStopRenderSELPROTO)FRCOREROUTINE(FPDXFARenderContextSEL,FPDXFARenderContextStopRenderSEL, _gPID)))

//*****************************
/* XFAConverter HFT functions */
//*****************************

#define FPDXFAConverterCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFAConverterCreateSELPROTO)FRCOREROUTINE(FPDXFAConverterSEL,FPDXFAConverterCreateSEL, _gPID)))

#define FPDXFAConverterRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFAConverterReleaseSELPROTO)FRCOREROUTINE(FPDXFAConverterSEL,FPDXFAConverterReleaseSEL, _gPID)))

#define FPDXFAConverterStartConvert (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFAConverterStartConvertSELPROTO)FRCOREROUTINE(FPDXFAConverterSEL,FPDXFAConverterStartConvertSEL, _gPID)))

#define FPDXFAConverterStartConvert2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFAConverterStartConvert2SELPROTO)FRCOREROUTINE(FPDXFAConverterSEL,FPDXFAConverterStartConvert2SEL, _gPID)))

#define FPDXFAConverterStartConvert3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFAConverterStartConvert3SELPROTO)FRCOREROUTINE(FPDXFAConverterSEL,FPDXFAConverterStartConvert3SEL, _gPID)))

#define FPDXFAConverterStartConvert4 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFAConverterStartConvert4SELPROTO)FRCOREROUTINE(FPDXFAConverterSEL,FPDXFAConverterStartConvert4SEL, _gPID)))

#define FPDXFAConverterDoConvert (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDXFAConverterDoConvertSELPROTO)FRCOREROUTINE(FPDXFAConverterSEL,FPDXFAConverterDoConvertSEL, _gPID)))

//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
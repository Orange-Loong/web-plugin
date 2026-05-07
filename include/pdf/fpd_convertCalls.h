/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_CONVERTCALLS_H
#define FPD_CONVERTCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_CONVERTEXPT_H
#include "fpd_convertExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_convertImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_convertTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_convertImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_convertTempl.h"

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
/* ConvertTaggedPDFHandler HFT functions */
//*****************************

#define FPDConvertTaggedPDFHandlerNewHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConvertTaggedPDFHandlerNewHandlerSELPROTO)FRCOREROUTINE(FPDConvertTaggedPDFHandlerSEL,FPDConvertTaggedPDFHandlerNewHandlerSEL, _gPID)))

#define FPDConvertTaggedPDFHandlerDestroyHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConvertTaggedPDFHandlerDestroyHandlerSELPROTO)FRCOREROUTINE(FPDConvertTaggedPDFHandlerSEL,FPDConvertTaggedPDFHandlerDestroyHandlerSEL, _gPID)))

//*****************************
/* DestructObject HFT functions */
//*****************************

#define FPDDestructObjectFormRecognitionCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectFormRecognitionCreateSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectFormRecognitionCreateSEL, _gPID)))

#define FPDDestructObjectRecognitionCreateFrom (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectRecognitionCreateFromSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectRecognitionCreateFromSEL, _gPID)))

#define FPDDestructObjectFormRecognitionCreate2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectFormRecognitionCreate2SELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectFormRecognitionCreate2SEL, _gPID)))

#define FPDDestructObjectCreateFormRecHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectCreateFormRecHandlerSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectCreateFormRecHandlerSEL, _gPID)))

#define FPDDestructObjectDeleteFormRecHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectDeleteFormRecHandlerSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectDeleteFormRecHandlerSEL, _gPID)))

#define FPDDestructObjectCreateFormRecOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectCreateFormRecOptionSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectCreateFormRecOptionSEL, _gPID)))

#define FPDDestructObjectDeleteFormRecOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectDeleteFormRecOptionSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectDeleteFormRecOptionSEL, _gPID)))

#define FPDDestructObjectGetRecCallback (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectGetRecCallbackSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectGetRecCallbackSEL, _gPID)))

#define FPDDestructObjectSetRecCallback (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectSetRecCallbackSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectSetRecCallbackSEL, _gPID)))

#define FPDDestructObjectGetOutputPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectGetOutputPathSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectGetOutputPathSEL, _gPID)))

#define FPDDestructObjectSetOutputPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectSetOutputPathSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectSetOutputPathSEL, _gPID)))

#define FPDDestructObjectGetFileStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectGetFileStreamSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectGetFileStreamSEL, _gPID)))

#define FPDDestructObjectSetFileStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestructObjectSetFileStreamSELPROTO)FRCOREROUTINE(FPDDestructObjectSEL,FPDDestructObjectSetFileStreamSEL, _gPID)))

//*****************************
/* ConverterOptions HFT functions */
//*****************************

#define FPDConverterOptionsNewConverterOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterOptionsNewConverterOptionsSELPROTO)FRCOREROUTINE(FPDConverterOptionsSEL,FPDConverterOptionsNewConverterOptionsSEL, _gPID)))

#define FPDConverterOptionsDestroyConverterOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterOptionsDestroyConverterOptionsSELPROTO)FRCOREROUTINE(FPDConverterOptionsSEL,FPDConverterOptionsDestroyConverterOptionsSEL, _gPID)))

#define FPDConverterOptionsGetImageDPP (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterOptionsGetImageDPPSELPROTO)FRCOREROUTINE(FPDConverterOptionsSEL,FPDConverterOptionsGetImageDPPSEL, _gPID)))

#define FPDConverterOptionsSetImageDPP (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterOptionsSetImageDPPSELPROTO)FRCOREROUTINE(FPDConverterOptionsSEL,FPDConverterOptionsSetImageDPPSEL, _gPID)))

#define FPDConverterOptionsGetStopWhenTimeout (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterOptionsGetStopWhenTimeoutSELPROTO)FRCOREROUTINE(FPDConverterOptionsSEL,FPDConverterOptionsGetStopWhenTimeoutSEL, _gPID)))

#define FPDConverterOptionsSetStopWhenTimeout (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterOptionsSetStopWhenTimeoutSELPROTO)FRCOREROUTINE(FPDConverterOptionsSEL,FPDConverterOptionsSetStopWhenTimeoutSEL, _gPID)))

#define FPDConverterOptionsGetOCContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterOptionsGetOCContextSELPROTO)FRCOREROUTINE(FPDConverterOptionsSEL,FPDConverterOptionsGetOCContextSEL, _gPID)))

#define FPDConverterOptionsSetOCContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterOptionsSetOCContextSELPROTO)FRCOREROUTINE(FPDConverterOptionsSEL,FPDConverterOptionsSetOCContextSEL, _gPID)))

#define FPDConverterOptionsGetLRVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterOptionsGetLRVersionSELPROTO)FRCOREROUTINE(FPDConverterOptionsSEL,FPDConverterOptionsGetLRVersionSEL, _gPID)))

#define FPDConverterOptionsSetLRVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterOptionsSetLRVersionSELPROTO)FRCOREROUTINE(FPDConverterOptionsSEL,FPDConverterOptionsSetLRVersionSEL, _gPID)))

//*****************************
/* ConverterHandler HFT functions */
//*****************************

#define FPDConverterHandlerNewConvertHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterHandlerNewConvertHandlerSELPROTO)FRCOREROUTINE(FPDConverterHandlerSEL,FPDConverterHandlerNewConvertHandlerSEL, _gPID)))

#define FPDConverterHandlerDestroyConvertHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterHandlerDestroyConvertHandlerSELPROTO)FRCOREROUTINE(FPDConverterHandlerSEL,FPDConverterHandlerDestroyConvertHandlerSEL, _gPID)))

#define FPDConverterHandlerNeedToPauseNow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterHandlerNeedToPauseNowSELPROTO)FRCOREROUTINE(FPDConverterHandlerSEL,FPDConverterHandlerNeedToPauseNowSEL, _gPID)))

#define FPDConverterHandlerPreparePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterHandlerPreparePageSELPROTO)FRCOREROUTINE(FPDConverterHandlerSEL,FPDConverterHandlerPreparePageSEL, _gPID)))

#define FPDConverterHandlerConfigureAnalysisOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterHandlerConfigureAnalysisOptionsSELPROTO)FRCOREROUTINE(FPDConverterHandlerSEL,FPDConverterHandlerConfigureAnalysisOptionsSEL, _gPID)))

#define FPDConverterHandlerUpdateProgress (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterHandlerUpdateProgressSELPROTO)FRCOREROUTINE(FPDConverterHandlerSEL,FPDConverterHandlerUpdateProgressSEL, _gPID)))

//*****************************
/* Converter HFT functions */
//*****************************

#define FPDConverterCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterCreateSELPROTO)FRCOREROUTINE(FPDConverterSEL,FPDConverterCreateSEL, _gPID)))

#define FPDConverterDestroyConverter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterDestroyConverterSELPROTO)FRCOREROUTINE(FPDConverterSEL,FPDConverterDestroyConverterSEL, _gPID)))

#define FPDConverterStart (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterStartSELPROTO)FRCOREROUTINE(FPDConverterSEL,FPDConverterStartSEL, _gPID)))

#define FPDConverterStart2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterStart2SELPROTO)FRCOREROUTINE(FPDConverterSEL,FPDConverterStart2SEL, _gPID)))

#define FPDConverterStart3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterStart3SELPROTO)FRCOREROUTINE(FPDConverterSEL,FPDConverterStart3SEL, _gPID)))

#define FPDConverterContinue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConverterContinueSELPROTO)FRCOREROUTINE(FPDConverterSEL,FPDConverterContinueSEL, _gPID)))

//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
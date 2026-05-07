/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_RENDERCALLS_H
#define FPD_RENDERCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_RENDEREXPT_H
#include "fpd_renderExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_renderImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_renderTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_renderImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_renderTempl.h"

//----------_V1----------
//*****************************
/* RenderOptions HFT functions */
//*****************************

#define FPDRenderOptionsNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsNewSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsNewSEL, _gPID)))

#define FPDRenderOptionsDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsDestroySELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsDestroySEL, _gPID)))

#define FPDRenderOptionsGetColorMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsGetColorModeSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsGetColorModeSEL, _gPID)))

#define FPDRenderOptionsSetColorMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsSetColorModeSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsSetColorModeSEL, _gPID)))

#define FPDRenderOptionsGetBackColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsGetBackColorSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsGetBackColorSEL, _gPID)))

#define FPDRenderOptionsSetBackColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsSetBackColorSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsSetBackColorSEL, _gPID)))

#define FPDRenderOptionsGetForeColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsGetForeColorSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsGetForeColorSEL, _gPID)))

#define FPDRenderOptionsSetForeColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsSetForeColorSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsSetForeColorSEL, _gPID)))

#define FPDRenderOptionsGetRenderFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsGetRenderFlagSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsGetRenderFlagSEL, _gPID)))

#define FPDRenderOptionsSetRenderFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsSetRenderFlagSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsSetRenderFlagSEL, _gPID)))

#define FPDRenderOptionsGetAddtionalFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsGetAddtionalFlagSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsGetAddtionalFlagSEL, _gPID)))

#define FPDRenderOptionsSetAddtionalFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsSetAddtionalFlagSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsSetAddtionalFlagSEL, _gPID)))

#define FPDRenderOptionsSetOCCHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsSetOCCHandlerSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsSetOCCHandlerSEL, _gPID)))

#define FPDRenderOptionsTranslateColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsTranslateColorSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsTranslateColorSEL, _gPID)))

#define FPDRenderOptionsCreateOCContextHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsCreateOCContextHandlerSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsCreateOCContextHandlerSEL, _gPID)))

#define FPDRenderOptionsDeleteOCContextHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsDeleteOCContextHandlerSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsDeleteOCContextHandlerSEL, _gPID)))

#define FPDRenderOptionsSetDocTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsSetDocTextColorSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsSetDocTextColorSEL, _gPID)))

#define FPDRenderOptionsGetDocTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsGetDocTextColorSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsGetDocTextColorSEL, _gPID)))

#define FPDRenderOptionsSetCustomColorMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsSetCustomColorModeSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsSetCustomColorModeSEL, _gPID)))

#define FPDRenderOptionsGetCustomColorMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsGetCustomColorModeSELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsGetCustomColorModeSEL, _gPID)))

#define FPDRenderOptionsTranslateColor2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderOptionsTranslateColor2SELPROTO)FRCOREROUTINE(FPDRenderOptionsSEL,FPDRenderOptionsTranslateColor2SEL, _gPID)))

//*****************************
/* RenderContext HFT functions */
//*****************************

#define FPDRenderContextNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextNewSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextNewSEL, _gPID)))

#define FPDRenderContextNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextNew2SELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextNew2SEL, _gPID)))

#define FPDRenderContextDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextDestroySELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextDestroySEL, _gPID)))

#define FPDRenderContextDrawStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextDrawStreamSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextDrawStreamSEL, _gPID)))

#define FPDRenderContextAppendPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextAppendPageSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextAppendPageSEL, _gPID)))

#define FPDRenderContextAppendForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextAppendFormSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextAppendFormSEL, _gPID)))

#define FPDRenderContextSetBackground (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextSetBackgroundSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextSetBackgroundSEL, _gPID)))

#define FPDRenderContextCreateBackgroundDrawHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextCreateBackgroundDrawHandlerSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextCreateBackgroundDrawHandlerSEL, _gPID)))

#define FPDRenderContextDeleteBackgroundDrawHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextDeleteBackgroundDrawHandlerSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextDeleteBackgroundDrawHandlerSEL, _gPID)))

#define FPDRenderContextRender (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextRenderSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextRenderSEL, _gPID)))

#define FPDRenderContextDrawPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextDrawPageSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextDrawPageSEL, _gPID)))

#define FPDRenderContextDrawForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextDrawFormSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextDrawFormSEL, _gPID)))

#define FPDRenderContextQuickDraw (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextQuickDrawSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextQuickDrawSEL, _gPID)))

#define FPDRenderContextGetBackground (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextGetBackgroundSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextGetBackgroundSEL, _gPID)))

#define FPDRenderContextGetPageCache (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderContextGetPageCacheSELPROTO)FRCOREROUTINE(FPDRenderContextSEL,FPDRenderContextGetPageCacheSEL, _gPID)))

//*****************************
/* ProgressiveRender HFT functions */
//*****************************

#define FPDProgressiveRenderNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveRenderNewSELPROTO)FRCOREROUTINE(FPDProgressiveRenderSEL,FPDProgressiveRenderNewSEL, _gPID)))

#define FPDProgressiveRenderDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveRenderDestroySELPROTO)FRCOREROUTINE(FPDProgressiveRenderSEL,FPDProgressiveRenderDestroySEL, _gPID)))

#define FPDProgressiveRenderStart (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveRenderStartSELPROTO)FRCOREROUTINE(FPDProgressiveRenderSEL,FPDProgressiveRenderStartSEL, _gPID)))

#define FPDProgressiveRenderContinue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveRenderContinueSELPROTO)FRCOREROUTINE(FPDProgressiveRenderSEL,FPDProgressiveRenderContinueSEL, _gPID)))

#define FPDProgressiveRenderEstimateProgress (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveRenderEstimateProgressSELPROTO)FRCOREROUTINE(FPDProgressiveRenderSEL,FPDProgressiveRenderEstimateProgressSEL, _gPID)))

#define FPDProgressiveRenderClear (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveRenderClearSELPROTO)FRCOREROUTINE(FPDProgressiveRenderSEL,FPDProgressiveRenderClearSEL, _gPID)))

#define FPDProgressiveRenderGetStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveRenderGetStatusSELPROTO)FRCOREROUTINE(FPDProgressiveRenderSEL,FPDProgressiveRenderGetStatusSEL, _gPID)))

//*****************************
/* RenderDevice HFT functions */
//*****************************

#define FPDRenderDeviceNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceNewSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceNewSEL, _gPID)))

#define FPDRenderDeviceDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceDestroySELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceDestroySEL, _gPID)))

#define FPDRenderDeviceStartRendering (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceStartRenderingSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceStartRenderingSEL, _gPID)))

#define FPDRenderDeviceEndRendering (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceEndRenderingSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceEndRenderingSEL, _gPID)))

#define FPDRenderDeviceSaveState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceSaveStateSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceSaveStateSEL, _gPID)))

#define FPDRenderDeviceRestoreState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceRestoreStateSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceRestoreStateSEL, _gPID)))

#define FPDRenderDeviceGetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceGetWidthSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceGetWidthSEL, _gPID)))

#define FPDRenderDeviceGetHeight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceGetHeightSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceGetHeightSEL, _gPID)))

#define FPDRenderDeviceGetBPP (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceGetBPPSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceGetBPPSEL, _gPID)))

#define FPDRenderDeviceGetRenderCaps (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceGetRenderCapsSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceGetRenderCapsSEL, _gPID)))

#define FPDRenderDeviceGetDeviceCapsXY (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceGetDeviceCapsXYSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceGetDeviceCapsXYSEL, _gPID)))

#define FPDRenderDeviceGetBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceGetBitmapSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceGetBitmapSEL, _gPID)))

#define FPDRenderDeviceSetBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceSetBitmapSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceSetBitmapSEL, _gPID)))

#define FPDRenderDeviceSetPixel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceSetPixelSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceSetPixelSEL, _gPID)))

#define FPDRenderDeviceSetClip_Rect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceSetClip_RectSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceSetClip_RectSEL, _gPID)))

#define FPDRenderDeviceCreateCompatibleBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceCreateCompatibleBitmapSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceCreateCompatibleBitmapSEL, _gPID)))

#define FPDRenderDeviceFillRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceFillRectSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceFillRectSEL, _gPID)))

#define FPDRenderDeviceDrawCosmeticLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceDrawCosmeticLineSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceDrawCosmeticLineSEL, _gPID)))

#define FPDRenderDeviceGetDIBits (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceGetDIBitsSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceGetDIBitsSEL, _gPID)))

#define FPDRenderDeviceSetDIBits (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceSetDIBitsSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceSetDIBitsSEL, _gPID)))

#define FPDRenderDeviceStretchDIBits (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceStretchDIBitsSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceStretchDIBitsSEL, _gPID)))

#define FPDRenderDeviceSetBitMask (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceSetBitMaskSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceSetBitMaskSEL, _gPID)))

#define FPDRenderDeviceStretchBitMask (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceStretchBitMaskSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceStretchBitMaskSEL, _gPID)))

#define FPDRenderDeviceGetDitherBits (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceGetDitherBitsSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceGetDitherBitsSEL, _gPID)))

#define FPDRenderDeviceDrawTextString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceDrawTextStringSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceDrawTextStringSEL, _gPID)))

#define FPDRenderDeviceDrawTextString2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceDrawTextString2SELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceDrawTextString2SEL, _gPID)))

#define FPDRenderDeviceDrawTextPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceDrawTextPathSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceDrawTextPathSEL, _gPID)))

#define FPDRenderDeviceDrawNormalText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceDrawNormalTextSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceDrawNormalTextSEL, _gPID)))

#define FPDRenderDeviceDrawType3Text (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceDrawType3TextSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceDrawType3TextSEL, _gPID)))

#define FPDRenderDeviceDrawPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceDrawPathSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceDrawPathSEL, _gPID)))

#define FPDRenderDeviceSetClip_PathFill (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceSetClip_PathFillSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceSetClip_PathFillSEL, _gPID)))

#define FPDRenderDeviceSetClip_PathFill2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceSetClip_PathFill2SELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceSetClip_PathFill2SEL, _gPID)))

#define FPDRenderDeviceGetMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenderDeviceGetMatrixSELPROTO)FRCOREROUTINE(FPDRenderDeviceSEL,FPDRenderDeviceGetMatrixSEL, _gPID)))

//*****************************
/* FxgeDevice HFT functions */
//*****************************

#define FPDFxgeDeviceNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFxgeDeviceNewSELPROTO)FRCOREROUTINE(FPDFxgeDeviceSEL,FPDFxgeDeviceNewSEL, _gPID)))

#define FPDFxgeDeviceCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFxgeDeviceCreateSELPROTO)FRCOREROUTINE(FPDFxgeDeviceSEL,FPDFxgeDeviceCreateSEL, _gPID)))

#define FPDFxgeDeviceDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFxgeDeviceDestroySELPROTO)FRCOREROUTINE(FPDFxgeDeviceSEL,FPDFxgeDeviceDestroySEL, _gPID)))

#define FPDFxgeDeviceAttach (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFxgeDeviceAttachSELPROTO)FRCOREROUTINE(FPDFxgeDeviceSEL,FPDFxgeDeviceAttachSEL, _gPID)))

//*****************************
/* WindowsDevice HFT functions */
//*****************************

#define FPDWindowsDeviceNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWindowsDeviceNewSELPROTO)FRCOREROUTINE(FPDWindowsDeviceSEL,FPDWindowsDeviceNewSEL, _gPID)))

#define FPDWindowsDeviceDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWindowsDeviceDestroySELPROTO)FRCOREROUTINE(FPDWindowsDeviceSEL,FPDWindowsDeviceDestroySEL, _gPID)))

#define FPDWindowsDeviceGetDC (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWindowsDeviceGetDCSELPROTO)FRCOREROUTINE(FPDWindowsDeviceSEL,FPDWindowsDeviceGetDCSEL, _gPID)))

//*****************************
/* PageRenderCache HFT functions */
//*****************************

#define FPDPageRenderCacheNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageRenderCacheNewSELPROTO)FRCOREROUTINE(FPDPageRenderCacheSEL,FPDPageRenderCacheNewSEL, _gPID)))

#define FPDPageRenderCacheDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageRenderCacheDestroySELPROTO)FRCOREROUTINE(FPDPageRenderCacheSEL,FPDPageRenderCacheDestroySEL, _gPID)))

#define FPDPageRenderCacheClearAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageRenderCacheClearAllSELPROTO)FRCOREROUTINE(FPDPageRenderCacheSEL,FPDPageRenderCacheClearAllSEL, _gPID)))

#define FPDPageRenderCacheClearImageData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageRenderCacheClearImageDataSELPROTO)FRCOREROUTINE(FPDPageRenderCacheSEL,FPDPageRenderCacheClearImageDataSEL, _gPID)))

#define FPDPageRenderCacheEstimateSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageRenderCacheEstimateSizeSELPROTO)FRCOREROUTINE(FPDPageRenderCacheSEL,FPDPageRenderCacheEstimateSizeSEL, _gPID)))

#define FPDPageRenderCacheGetCachedBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageRenderCacheGetCachedBitmapSELPROTO)FRCOREROUTINE(FPDPageRenderCacheSEL,FPDPageRenderCacheGetCachedBitmapSEL, _gPID)))

#define FPDPageRenderCacheResetBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageRenderCacheResetBitmapSELPROTO)FRCOREROUTINE(FPDPageRenderCacheSEL,FPDPageRenderCacheResetBitmapSEL, _gPID)))

#define FPDPageRenderCacheCalcBitmapMargin (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageRenderCacheCalcBitmapMarginSELPROTO)FRCOREROUTINE(FPDPageRenderCacheSEL,FPDPageRenderCacheCalcBitmapMarginSEL, _gPID)))

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
//*****************************
/* WinBitmapDevice HFT functions */
//*****************************

#define FPDWinBitmapDeviceNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWinBitmapDeviceNewSELPROTO)FRCOREROUTINE(FPDWinBitmapDeviceSEL,FPDWinBitmapDeviceNewSEL, _gPID)))

#define FPDWinBitmapDeviceDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWinBitmapDeviceDestroySELPROTO)FRCOREROUTINE(FPDWinBitmapDeviceSEL,FPDWinBitmapDeviceDestroySEL, _gPID)))

#define FPDWinBitmapDeviceGetDC (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWinBitmapDeviceGetDCSELPROTO)FRCOREROUTINE(FPDWinBitmapDeviceSEL,FPDWinBitmapDeviceGetDCSEL, _gPID)))

#define FPDWinBitmapDeviceCastToRenderDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWinBitmapDeviceCastToRenderDeviceSELPROTO)FRCOREROUTINE(FPDWinBitmapDeviceSEL,FPDWinBitmapDeviceCastToRenderDeviceSEL, _gPID)))

//*****************************
/* CPWLImage HFT functions */
//*****************************

//*****************************
/* CPWLLabel HFT functions */
//*****************************

//*****************************
/* CPWLTimerHandler HFT functions */
//*****************************

//*****************************
/* CPWLFocusHandler HFT functions */
//*****************************

//*****************************
/* CPWLProviderHandler HFT functions */
//*****************************

//*****************************
/* CPWLWnd HFT functions */
//*****************************

//*****************************
/* CPWLUtils HFT functions */
//*****************************

//*****************************
/* ColorF HFT functions */
//*****************************

//----------_V15----------
//*****************************
/* SystemHanler HFT functions */
//*****************************

//----------_V16----------
//*****************************
/* Graphics HFT functions */
//*****************************

#define FPDGraphicsCreateGraphics (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphicsCreateGraphicsSELPROTO)FRCOREROUTINE(FPDGraphicsSEL,FPDGraphicsCreateGraphicsSEL, _gPID)))

#define FPDGraphicsDeleteGraphics (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphicsDeleteGraphicsSELPROTO)FRCOREROUTINE(FPDGraphicsSEL,FPDGraphicsDeleteGraphicsSEL, _gPID)))

#define FPDGraphicsCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphicsCreateSELPROTO)FRCOREROUTINE(FPDGraphicsSEL,FPDGraphicsCreateSEL, _gPID)))

//----------_V17----------
//*****************************
/* CustomCursorHandler HFT functions */
//*****************************

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
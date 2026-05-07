/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_PSICALLS_H
#define FPD_PSICALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PSIEXPT_H
#include "fpd_psiExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_psiImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_psiTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_psiImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_psiTempl.h"

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
//----------_V17----------
//*****************************
/* FXGInkPath HFT functions */
//*****************************

#define FPDFXGInkPathAddPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGInkPathAddPointSELPROTO)FRCOREROUTINE(FPDFXGInkPathSEL,FPDFXGInkPathAddPointSEL, _gPID)))

#define FPDFXGInkPathGeneratePSI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGInkPathGeneratePSISELPROTO)FRCOREROUTINE(FPDFXGInkPathSEL,FPDFXGInkPathGeneratePSISEL, _gPID)))

//*****************************
/* FXGPaintModuleMgr HFT functions */
//*****************************

#define FPDFXGPaintModuleMgrCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintModuleMgrCreateSELPROTO)FRCOREROUTINE(FPDFXGPaintModuleMgrSEL,FPDFXGPaintModuleMgrCreateSEL, _gPID)))

#define FPDFXGPaintModuleMgrDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintModuleMgrDestroySELPROTO)FRCOREROUTINE(FPDFXGPaintModuleMgrSEL,FPDFXGPaintModuleMgrDestroySEL, _gPID)))

#define FPDFXGPaintModuleMgrGetCanvas (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintModuleMgrGetCanvasSELPROTO)FRCOREROUTINE(FPDFXGPaintModuleMgrSEL,FPDFXGPaintModuleMgrGetCanvasSEL, _gPID)))

#define FPDFXGPaintModuleMgrGetPaint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintModuleMgrGetPaintSELPROTO)FRCOREROUTINE(FPDFXGPaintModuleMgrSEL,FPDFXGPaintModuleMgrGetPaintSEL, _gPID)))

#define FPDFXGPaintModuleMgrSetCacheLimit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintModuleMgrSetCacheLimitSELPROTO)FRCOREROUTINE(FPDFXGPaintModuleMgrSEL,FPDFXGPaintModuleMgrSetCacheLimitSEL, _gPID)))

#define FPDFXGPaintModuleMgrCreatePaintNib (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintModuleMgrCreatePaintNibSELPROTO)FRCOREROUTINE(FPDFXGPaintModuleMgrSEL,FPDFXGPaintModuleMgrCreatePaintNibSEL, _gPID)))

#define FPDFXGPaintModuleMgrDestroyPaintNib (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintModuleMgrDestroyPaintNibSELPROTO)FRCOREROUTINE(FPDFXGPaintModuleMgrSEL,FPDFXGPaintModuleMgrDestroyPaintNibSEL, _gPID)))

#define FPDFXGPaintModuleMgrLoadPaintNib (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintModuleMgrLoadPaintNibSELPROTO)FRCOREROUTINE(FPDFXGPaintModuleMgrSEL,FPDFXGPaintModuleMgrLoadPaintNibSEL, _gPID)))

#define FPDFXGPaintModuleMgrSavePaintNib (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintModuleMgrSavePaintNibSELPROTO)FRCOREROUTINE(FPDFXGPaintModuleMgrSEL,FPDFXGPaintModuleMgrSavePaintNibSEL, _gPID)))

#define FPDFXGPaintModuleMgrListAllPaintNib (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintModuleMgrListAllPaintNibSELPROTO)FRCOREROUTINE(FPDFXGPaintModuleMgrSEL,FPDFXGPaintModuleMgrListAllPaintNibSEL, _gPID)))

//*****************************
/* FXGNIBParams HFT functions */
//*****************************

#define FPDFXGNIBParamsSetbFlipX (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsSetbFlipXSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsSetbFlipXSEL, _gPID)))

#define FPDFXGNIBParamsSetbFlipY (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsSetbFlipYSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsSetbFlipYSEL, _gPID)))

#define FPDFXGNIBParamsCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsCreateSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsCreateSEL, _gPID)))

#define FPDFXGNIBParamsDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsDeleteSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsDeleteSEL, _gPID)))

#define FPDFXGNIBParamsGetDiameter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsGetDiameterSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsGetDiameterSEL, _gPID)))

#define FPDFXGNIBParamsSetDiameter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsSetDiameterSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsSetDiameterSEL, _gPID)))

#define FPDFXGNIBParamsGetbFlipX (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsGetbFlipXSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsGetbFlipXSEL, _gPID)))

#define FPDFXGNIBParamsGetbFlipY (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsGetbFlipYSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsGetbFlipYSEL, _gPID)))

#define FPDFXGNIBParamsGetAngle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsGetAngleSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsGetAngleSEL, _gPID)))

#define FPDFXGNIBParamsSetAngle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsSetAngleSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsSetAngleSEL, _gPID)))

#define FPDFXGNIBParamsGetRoundness (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsGetRoundnessSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsGetRoundnessSEL, _gPID)))

#define FPDFXGNIBParamsSetRoundness (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsSetRoundnessSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsSetRoundnessSEL, _gPID)))

#define FPDFXGNIBParamsGetDashScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsGetDashScaleSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsGetDashScaleSEL, _gPID)))

#define FPDFXGNIBParamsSetDashScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsSetDashScaleSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsSetDashScaleSEL, _gPID)))

#define FPDFXGNIBParamsGetHardness (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsGetHardnessSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsGetHardnessSEL, _gPID)))

#define FPDFXGNIBParamsSetHardness (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsSetHardnessSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsSetHardnessSEL, _gPID)))

#define FPDFXGNIBParamsGetPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsGetPathSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsGetPathSEL, _gPID)))

#define FPDFXGNIBParamsSetPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsSetPathSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsSetPathSEL, _gPID)))

#define FPDFXGNIBParamsGetPattern (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsGetPatternSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsGetPatternSEL, _gPID)))

#define FPDFXGNIBParamsSetPattern (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGNIBParamsSetPatternSELPROTO)FRCOREROUTINE(FPDFXGNIBParamsSEL,FPDFXGNIBParamsSetPatternSEL, _gPID)))

//*****************************
/* FXGCanvas HFT functions */
//*****************************

#define FPDFXGCanvasCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasCreateSELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasCreateSEL, _gPID)))

#define FPDFXGCanvasDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasDestroySELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasDestroySEL, _gPID)))

#define FPDFXGCanvasSetFilterNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasSetFilterNotifySELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasSetFilterNotifySEL, _gPID)))

#define FPDFXGCanvasAttachLayer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasAttachLayerSELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasAttachLayerSEL, _gPID)))

#define FPDFXGCanvasCreateLayer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasCreateLayerSELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasCreateLayerSEL, _gPID)))

#define FPDFXGCanvasSetFGColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasSetFGColorSELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasSetFGColorSEL, _gPID)))

#define FPDFXGCanvasSetBGColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasSetBGColorSELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasSetBGColorSEL, _gPID)))

#define FPDFXGCanvasSetActiveChannel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasSetActiveChannelSELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasSetActiveChannelSEL, _gPID)))

#define FPDFXGCanvasGetFilterNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasGetFilterNotifySELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasGetFilterNotifySEL, _gPID)))

#define FPDFXGCanvasGetLayer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasGetLayerSELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasGetLayerSEL, _gPID)))

#define FPDFXGCanvasGetFGColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasGetFGColorSELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasGetFGColorSEL, _gPID)))

#define FPDFXGCanvasGetBGColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasGetBGColorSELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasGetBGColorSEL, _gPID)))

#define FPDFXGCanvasGetActiveChannel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasGetActiveChannelSELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasGetActiveChannelSEL, _gPID)))

#define FPDFXGCanvasCreateFilterNofity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasCreateFilterNofitySELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasCreateFilterNofitySEL, _gPID)))

#define FPDFXGCanvasDeleteFilterNofity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGCanvasDeleteFilterNofitySELPROTO)FRCOREROUTINE(FPDFXGCanvasSEL,FPDFXGCanvasDeleteFilterNofitySEL, _gPID)))

//*****************************
/* FXGPaintNib HFT functions */
//*****************************

#define FPDFXGPaintNibGetType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintNibGetTypeSELPROTO)FRCOREROUTINE(FPDFXGPaintNibSEL,FPDFXGPaintNibGetTypeSEL, _gPID)))

#define FPDFXGPaintNibGetNib (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintNibGetNibSELPROTO)FRCOREROUTINE(FPDFXGPaintNibSEL,FPDFXGPaintNibGetNibSEL, _gPID)))

#define FPDFXGPaintNibGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintNibGetNameSELPROTO)FRCOREROUTINE(FPDFXGPaintNibSEL,FPDFXGPaintNibGetNameSEL, _gPID)))

#define FPDFXGPaintNibGetParams (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintNibGetParamsSELPROTO)FRCOREROUTINE(FPDFXGPaintNibSEL,FPDFXGPaintNibGetParamsSEL, _gPID)))

//*****************************
/* FXGPaintRenderOption HFT functions */
//*****************************

#define FPDFXGPaintRenderOptionCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintRenderOptionCreateSELPROTO)FRCOREROUTINE(FPDFXGPaintRenderOptionSEL,FPDFXGPaintRenderOptionCreateSEL, _gPID)))

#define FPDFXGPaintRenderOptionDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintRenderOptionDestroySELPROTO)FRCOREROUTINE(FPDFXGPaintRenderOptionSEL,FPDFXGPaintRenderOptionDestroySEL, _gPID)))

#define FPDFXGPaintRenderOptionGetBlendMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintRenderOptionGetBlendModeSELPROTO)FRCOREROUTINE(FPDFXGPaintRenderOptionSEL,FPDFXGPaintRenderOptionGetBlendModeSEL, _gPID)))

#define FPDFXGPaintRenderOptionGetOpacity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintRenderOptionGetOpacitySELPROTO)FRCOREROUTINE(FPDFXGPaintRenderOptionSEL,FPDFXGPaintRenderOptionGetOpacitySEL, _gPID)))

#define FPDFXGPaintRenderOptionGetFlow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintRenderOptionGetFlowSELPROTO)FRCOREROUTINE(FPDFXGPaintRenderOptionSEL,FPDFXGPaintRenderOptionGetFlowSEL, _gPID)))

#define FPDFXGPaintRenderOptionGetAutoErase (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintRenderOptionGetAutoEraseSELPROTO)FRCOREROUTINE(FPDFXGPaintRenderOptionSEL,FPDFXGPaintRenderOptionGetAutoEraseSEL, _gPID)))

//*****************************
/* FXGPaint HFT functions */
//*****************************

#define FPDFXGPaintGetPaintType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintGetPaintTypeSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintGetPaintTypeSEL, _gPID)))

#define FPDFXGPaintGetInkPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintGetInkPathSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintGetInkPathSEL, _gPID)))

#define FPDFXGPaintAddPathFilter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintAddPathFilterSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintAddPathFilterSEL, _gPID)))

#define FPDFXGPaintRemovePathFilter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintRemovePathFilterSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintRemovePathFilterSEL, _gPID)))

#define FPDFXGPaintGetPaintNib (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintGetPaintNibSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintGetPaintNibSEL, _gPID)))

#define FPDFXGPaintSetPaintNib (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintSetPaintNibSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintSetPaintNibSEL, _gPID)))

#define FPDFXGPaintSetRenderOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintSetRenderOptionSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintSetRenderOptionSEL, _gPID)))

#define FPDFXGPaintGetFilterType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintGetFilterTypeSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintGetFilterTypeSEL, _gPID)))

#define FPDFXGPaintSetCanvas (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintSetCanvasSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintSetCanvasSEL, _gPID)))

#define FPDFXGPaintGetCanvas (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintGetCanvasSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintGetCanvasSEL, _gPID)))

#define FPDFXGPaintPrepare (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintPrepareSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintPrepareSEL, _gPID)))

#define FPDFXGPaintRender (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXGPaintRenderSELPROTO)FRCOREROUTINE(FPDFXGPaintSEL,FPDFXGPaintRenderSEL, _gPID)))

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_PAGEOBJCALLS_H
#define FPD_PAGEOBJCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PAGEOBJEXPT_H
#include "fpd_pageobjExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_pageobjImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_pageobjTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_pageobjImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_pageobjTempl.h"

//----------_V1----------
//*****************************
/* Path HFT functions */
//*****************************

#define FPDPathNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathNewSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathNewSEL, _gPID)))

#define FPDPathDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDestroySELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathDestroySEL, _gPID)))

#define FPDPathGetPointCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathGetPointCountSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathGetPointCountSEL, _gPID)))

#define FPDPathGetFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathGetFlagSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathGetFlagSEL, _gPID)))

#define FPDPathGetPointX (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathGetPointXSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathGetPointXSEL, _gPID)))

#define FPDPathGetPointY (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathGetPointYSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathGetPointYSEL, _gPID)))

#define FPDPathGetPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathGetPointSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathGetPointSEL, _gPID)))

#define FPDPathGetBoundingBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathGetBoundingBoxSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathGetBoundingBoxSEL, _gPID)))

#define FPDPathGetBoundingBox2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathGetBoundingBox2SELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathGetBoundingBox2SEL, _gPID)))

#define FPDPathTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathTransformSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathTransformSEL, _gPID)))

#define FPDPathAppend (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathAppendSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathAppendSEL, _gPID)))

#define FPDPathAppendRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathAppendRectSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathAppendRectSEL, _gPID)))

#define FPDPathIsRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathIsRectSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathIsRectSEL, _gPID)))

#define FPDPathSetPointCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathSetPointCountSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathSetPointCountSEL, _gPID)))

#define FPDPathSetPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathSetPointSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathSetPointSEL, _gPID)))

#define FPDPathGetModify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathGetModifySELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathGetModifySEL, _gPID)))

#define FPDPathTrimPoints (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathTrimPointsSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathTrimPointsSEL, _gPID)))

#define FPDPathTransformPathData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathTransformPathDataSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathTransformPathDataSEL, _gPID)))

#define FPDPathCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathCopySELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathCopySEL, _gPID)))

#define FPDPathAddPointCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathAddPointCountSELPROTO)FRCOREROUTINE(FPDPathSEL,FPDPathAddPointCountSEL, _gPID)))

//*****************************
/* ClipPath HFT functions */
//*****************************

#define FPDClipPathNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathNewSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathNewSEL, _gPID)))

#define FPDClipPathDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathDestroySELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathDestroySEL, _gPID)))

#define FPDClipPathAppendPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathAppendPathSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathAppendPathSEL, _gPID)))

#define FPDClipPathDeletePath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathDeletePathSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathDeletePathSEL, _gPID)))

#define FPDClipPathGetPathCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathGetPathCountSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathGetPathCountSEL, _gPID)))

#define FPDClipPathTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathTransformSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathTransformSEL, _gPID)))

#define FPDClipPathGetPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathGetPathSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathGetPathSEL, _gPID)))

#define FPDClipPathGetClipType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathGetClipTypeSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathGetClipTypeSEL, _gPID)))

#define FPDClipPathGetTextCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathGetTextCountSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathGetTextCountSEL, _gPID)))

#define FPDClipPathGetClipBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathGetClipBoxSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathGetClipBoxSEL, _gPID)))

#define FPDClipPathGetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathGetTextSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathGetTextSEL, _gPID)))

#define FPDClipPathAppendTexts (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathAppendTextsSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathAppendTextsSEL, _gPID)))

#define FPDClipPathSetCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathSetCountSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathSetCountSEL, _gPID)))

#define FPDClipPathIsNull (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathIsNullSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathIsNullSEL, _gPID)))

#define FPDClipPathGetModify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathGetModifySELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathGetModifySEL, _gPID)))

#define FPDClipPathGetPathPointer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathGetPathPointerSELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathGetPathPointerSEL, _gPID)))

#define FPDClipPathCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDClipPathCopySELPROTO)FRCOREROUTINE(FPDClipPathSEL,FPDClipPathCopySEL, _gPID)))

//*****************************
/* ColorState HFT functions */
//*****************************

#define FPDColorStateNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateNewSELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateNewSEL, _gPID)))

#define FPDColorStateDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateDestroySELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateDestroySEL, _gPID)))

#define FPDColorStateGetFillColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateGetFillColorSELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateGetFillColorSEL, _gPID)))

#define FPDColorStateGetStrokeColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateGetStrokeColorSELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateGetStrokeColorSEL, _gPID)))

#define FPDColorStateSetFillColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateSetFillColorSELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateSetFillColorSEL, _gPID)))

#define FPDColorStateSetStrokeColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateSetStrokeColorSELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateSetStrokeColorSEL, _gPID)))

#define FPDColorStateSetFillPatternColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateSetFillPatternColorSELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateSetFillPatternColorSEL, _gPID)))

#define FPDColorStateSetStrokePatternColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateSetStrokePatternColorSELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateSetStrokePatternColorSEL, _gPID)))

#define FPDColorStateIsNull (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateIsNullSELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateIsNullSEL, _gPID)))

#define FPDColorStateGetModify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateGetModifySELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateGetModifySEL, _gPID)))

#define FPDColorStateNotUseFillColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateNotUseFillColorSELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateNotUseFillColorSEL, _gPID)))

#define FPDColorStateCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorStateCopySELPROTO)FRCOREROUTINE(FPDColorStateSEL,FPDColorStateCopySEL, _gPID)))

//*****************************
/* TextState HFT functions */
//*****************************

#define FPDTextStateNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateNewSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateNewSEL, _gPID)))

#define FPDTextStateDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateDestroySELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateDestroySEL, _gPID)))

#define FPDTextStateGetFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetFontSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetFontSEL, _gPID)))

#define FPDTextStateSetFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateSetFontSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateSetFontSEL, _gPID)))

#define FPDTextStateGetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetFontSizeSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetFontSizeSEL, _gPID)))

#define FPDTextStateGetMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetMatrixSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetMatrixSEL, _gPID)))

#define FPDTextStateGetFontSizeV (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetFontSizeVSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetFontSizeVSEL, _gPID)))

#define FPDTextStateGetFontSizeH (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetFontSizeHSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetFontSizeHSEL, _gPID)))

#define FPDTextStateGetBaselineAngle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetBaselineAngleSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetBaselineAngleSEL, _gPID)))

#define FPDTextStateGetShearAngle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetShearAngleSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetShearAngleSEL, _gPID)))

#define FPDTextStateSetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateSetFontSizeSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateSetFontSizeSEL, _gPID)))

#define FPDTextStateSetCharSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateSetCharSpaceSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateSetCharSpaceSEL, _gPID)))

#define FPDTextStateSetWordSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateSetWordSpaceSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateSetWordSpaceSEL, _gPID)))

#define FPDTextStateSetMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateSetMatrixSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateSetMatrixSEL, _gPID)))

#define FPDTextStateSetTextMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateSetTextModeSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateSetTextModeSEL, _gPID)))

#define FPDTextStateSetTextCTM (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateSetTextCTMSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateSetTextCTMSEL, _gPID)))

#define FPDTextStateGetTextMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetTextModeSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetTextModeSEL, _gPID)))

#define FPDTextStateGetTextCTM (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetTextCTMSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetTextCTMSEL, _gPID)))

#define FPDTextStateGetCharSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetCharSpaceSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetCharSpaceSEL, _gPID)))

#define FPDTextStateGetWordSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetWordSpaceSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetWordSpaceSEL, _gPID)))

#define FPDTextStateIsNull (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateIsNullSELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateIsNullSEL, _gPID)))

#define FPDTextStateGetModify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextStateGetModifySELPROTO)FRCOREROUTINE(FPDTextStateSEL,FPDTextStateGetModifySEL, _gPID)))

//*****************************
/* GeneralState HFT functions */
//*****************************

#define FPDGeneralStateNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateNewSELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateNewSEL, _gPID)))

#define FPDGeneralStateDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateDestroySELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateDestroySEL, _gPID)))

#define FPDGeneralStateSetRenderIntent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateSetRenderIntentSELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateSetRenderIntentSEL, _gPID)))

#define FPDGeneralStateGetBlendType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateGetBlendTypeSELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateGetBlendTypeSEL, _gPID)))

#define FPDGeneralStateGetAlpha (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateGetAlphaSELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateGetAlphaSEL, _gPID)))

#define FPDGeneralStateSetBlendMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateSetBlendModeSELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateSetBlendModeSEL, _gPID)))

#define FPDGeneralStateSetBlendType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateSetBlendTypeSELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateSetBlendTypeSEL, _gPID)))

#define FPDGeneralStateSetSoftMask (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateSetSoftMaskSELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateSetSoftMaskSEL, _gPID)))

#define FPDGeneralStateSetSoftMaskMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateSetSoftMaskMatrixSELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateSetSoftMaskMatrixSEL, _gPID)))

#define FPDGeneralStateSetStrokeAlpha (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateSetStrokeAlphaSELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateSetStrokeAlphaSEL, _gPID)))

#define FPDGeneralStateSetFillAlpha (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateSetFillAlphaSELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateSetFillAlphaSEL, _gPID)))

#define FPDGeneralStateIsNull (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateIsNullSELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateIsNullSEL, _gPID)))

#define FPDGeneralStateGetModify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGeneralStateGetModifySELPROTO)FRCOREROUTINE(FPDGeneralStateSEL,FPDGeneralStateGetModifySEL, _gPID)))

//*****************************
/* GraphState HFT functions */
//*****************************

#define FPDGraphStateNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateNewSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateNewSEL, _gPID)))

#define FPDGraphStateDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateDestroySELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateDestroySEL, _gPID)))

#define FPDGraphStateSetDashCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateSetDashCountSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateSetDashCountSEL, _gPID)))

#define FPDGraphStateGetDashCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateGetDashCountSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateGetDashCountSEL, _gPID)))

#define FPDGraphStateGetDashArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateGetDashArraySELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateGetDashArraySEL, _gPID)))

#define FPDGraphStateGetDashPhase (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateGetDashPhaseSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateGetDashPhaseSEL, _gPID)))

#define FPDGraphStateSetDashPhase (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateSetDashPhaseSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateSetDashPhaseSEL, _gPID)))

#define FPDGraphStateGetLineCap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateGetLineCapSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateGetLineCapSEL, _gPID)))

#define FPDGraphStateSetLineCap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateSetLineCapSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateSetLineCapSEL, _gPID)))

#define FPDGraphStateGetLineJoin (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateGetLineJoinSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateGetLineJoinSEL, _gPID)))

#define FPDGraphStateSetLineJoin (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateSetLineJoinSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateSetLineJoinSEL, _gPID)))

#define FPDGraphStateGetMiterLimit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateGetMiterLimitSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateGetMiterLimitSEL, _gPID)))

#define FPDGraphStateSetMiterLimit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateSetMiterLimitSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateSetMiterLimitSEL, _gPID)))

#define FPDGraphStateGetLineWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateGetLineWidthSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateGetLineWidthSEL, _gPID)))

#define FPDGraphStateSetLineWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateSetLineWidthSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateSetLineWidthSEL, _gPID)))

#define FPDGraphStateIsNull (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateIsNullSELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateIsNullSEL, _gPID)))

#define FPDGraphStateGetModify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateGetModifySELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateGetModifySEL, _gPID)))

#define FPDGraphStateSetDashArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDGraphStateSetDashArraySELPROTO)FRCOREROUTINE(FPDGraphStateSEL,FPDGraphStateSetDashArraySEL, _gPID)))

//*****************************
/* PageObject HFT functions */
//*****************************

#define FPDPageObjectNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectNewSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectNewSEL, _gPID)))

#define FPDPageObjectDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectDestroySELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectDestroySEL, _gPID)))

#define FPDPageObjectClone (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectCloneSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectCloneSEL, _gPID)))

#define FPDPageObjectCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectCopySELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectCopySEL, _gPID)))

#define FPDPageObjectRemoveClipPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectRemoveClipPathSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectRemoveClipPathSEL, _gPID)))

#define FPDPageObjectAppendClipPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectAppendClipPathSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectAppendClipPathSEL, _gPID)))

#define FPDPageObjectCopyClipPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectCopyClipPathSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectCopyClipPathSEL, _gPID)))

#define FPDPageObjectTransformClipPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectTransformClipPathSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectTransformClipPathSEL, _gPID)))

#define FPDPageObjectSetColorState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectSetColorStateSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectSetColorStateSEL, _gPID)))

#define FPDPageObjectGetBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetBBoxSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetBBoxSEL, _gPID)))

#define FPDPageObjectGetOriginalBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetOriginalBBoxSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetOriginalBBoxSEL, _gPID)))

#define FPDPageObjectGetType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetTypeSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetTypeSEL, _gPID)))

#define FPDPageObjectGetClipPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetClipPathSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetClipPathSEL, _gPID)))

#define FPDPageObjectGetGraphState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetGraphStateSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetGraphStateSEL, _gPID)))

#define FPDPageObjectGetColorState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetColorStateSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetColorStateSEL, _gPID)))

#define FPDPageObjectGetTextState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetTextStateSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetTextStateSEL, _gPID)))

#define FPDPageObjectGetGeneralState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetGeneralStateSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetGeneralStateSEL, _gPID)))

#define FPDPageObjectGetContentMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetContentMarkSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetContentMarkSEL, _gPID)))

#define FPDPageObjectDefaultStates (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectDefaultStatesSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectDefaultStatesSEL, _gPID)))

#define FPDPageObjectCopyStates (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectCopyStatesSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectCopyStatesSEL, _gPID)))

#define FPDPageObjectSetGraphState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectSetGraphStateSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectSetGraphStateSEL, _gPID)))

#define FPDPageObjectSetTextState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectSetTextStateSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectSetTextStateSEL, _gPID)))

#define FPDPageObjectSetGeneralState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectSetGeneralStateSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectSetGeneralStateSEL, _gPID)))

#define FPDPageObjectHasClipPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectHasClipPathSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectHasClipPathSEL, _gPID)))

#define FPDPageObjectGetContentMark2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetContentMark2SELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetContentMark2SEL, _gPID)))

#define FPDPageObjectTransformGeneralState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectTransformGeneralStateSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectTransformGeneralStateSEL, _gPID)))

#define FPDPageObjectTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectTransformSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectTransformSEL, _gPID)))

#define FPDPageObjectCastToFormObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectCastToFormObjectSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectCastToFormObjectSEL, _gPID)))

#define FPDPageObjectSetContentMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectSetContentMarkSELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectSetContentMarkSEL, _gPID)))

#define FPDPageObjectGetClipPath2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetClipPath2SELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetClipPath2SEL, _gPID)))

#define FPDPageObjectGetColorState2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectGetColorState2SELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectGetColorState2SEL, _gPID)))

#define FPDPageObjectClone2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageObjectClone2SELPROTO)FRCOREROUTINE(FPDPageObjectSEL,FPDPageObjectClone2SEL, _gPID)))

//*****************************
/* TextObject HFT functions */
//*****************************

#define FPDTextObjectNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectNewSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectNewSEL, _gPID)))

#define FPDTextObjectDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectDestroySELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectDestroySEL, _gPID)))

#define FPDTextObjectCountItems (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectCountItemsSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectCountItemsSEL, _gPID)))

#define FPDTextObjectGetItemInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetItemInfoSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetItemInfoSEL, _gPID)))

#define FPDTextObjectCountChars (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectCountCharsSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectCountCharsSEL, _gPID)))

#define FPDTextObjectGetCharInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetCharInfoSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetCharInfoSEL, _gPID)))

#define FPDTextObjectGetPosX (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetPosXSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetPosXSEL, _gPID)))

#define FPDTextObjectGetPosY (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetPosYSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetPosYSEL, _gPID)))

#define FPDTextObjectGetTextMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetTextMatrixSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetTextMatrixSEL, _gPID)))

#define FPDTextObjectGetFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetFontSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetFontSEL, _gPID)))

#define FPDTextObjectGetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetFontSizeSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetFontSizeSEL, _gPID)))

#define FPDTextObjectSetEmpty (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectSetEmptySELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectSetEmptySEL, _gPID)))

#define FPDTextObjectSetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectSetTextSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectSetTextSEL, _gPID)))

#define FPDTextObjectSetText2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectSetText2SELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectSetText2SEL, _gPID)))

#define FPDTextObjectSetText3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectSetText3SELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectSetText3SEL, _gPID)))

#define FPDTextObjectSetPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectSetPositionSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectSetPositionSEL, _gPID)))

#define FPDTextObjectSetTextState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectSetTextStateSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectSetTextStateSEL, _gPID)))

#define FPDTextObjectTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectTransformSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectTransformSEL, _gPID)))

#define FPDTextObjectCalcCharPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectCalcCharPosSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectCalcCharPosSEL, _gPID)))

#define FPDTextObjectSetData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectSetDataSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectSetDataSEL, _gPID)))

#define FPDTextObjectGetData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetDataSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetDataSEL, _gPID)))

#define FPDTextObjectRecalcPositionData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectRecalcPositionDataSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectRecalcPositionDataSEL, _gPID)))

#define FPDTextObjectGetCharRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetCharRectSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetCharRectSEL, _gPID)))

#define FPDTextObjectGetSpaceCharWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetSpaceCharWidthSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetSpaceCharWidthSEL, _gPID)))

#define FPDTextObjectGetCharInfo2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetCharInfo2SELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetCharInfo2SEL, _gPID)))

#define FPDTextObjectGetIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectGetIndexSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectGetIndexSEL, _gPID)))

#define FPDTextObjectSetIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextObjectSetIndexSELPROTO)FRCOREROUTINE(FPDTextObjectSEL,FPDTextObjectSetIndexSEL, _gPID)))

//*****************************
/* PathObject HFT functions */
//*****************************

#define FPDPathObjectNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectNewSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectNewSEL, _gPID)))

#define FPDPathObjectDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectDestroySELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectDestroySEL, _gPID)))

#define FPDPathObjectTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectTransformSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectTransformSEL, _gPID)))

#define FPDPathObjectSetGraphState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectSetGraphStateSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectSetGraphStateSEL, _gPID)))

#define FPDPathObjectCalcBoundingBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectCalcBoundingBoxSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectCalcBoundingBoxSEL, _gPID)))

#define FPDPathObjectGetTransformMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectGetTransformMatrixSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectGetTransformMatrixSEL, _gPID)))

#define FPDPathObjectSetTransformMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectSetTransformMatrixSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectSetTransformMatrixSEL, _gPID)))

#define FPDPathObjectGetPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectGetPathSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectGetPathSEL, _gPID)))

#define FPDPathObjectIsStrokeMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectIsStrokeModeSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectIsStrokeModeSEL, _gPID)))

#define FPDPathObjectSetStrokeMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectSetStrokeModeSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectSetStrokeModeSEL, _gPID)))

#define FPDPathObjectGetFillMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectGetFillModeSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectGetFillModeSEL, _gPID)))

#define FPDPathObjectSetFillMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectSetFillModeSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectSetFillModeSEL, _gPID)))

#define FPDPathObjectGetPath2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectGetPath2SELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectGetPath2SEL, _gPID)))

#define FPDPathObjectSetPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathObjectSetPathSELPROTO)FRCOREROUTINE(FPDPathObjectSEL,FPDPathObjectSetPathSEL, _gPID)))

//*****************************
/* ImageObject HFT functions */
//*****************************

#define FPDImageObjectNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageObjectNewSELPROTO)FRCOREROUTINE(FPDImageObjectSEL,FPDImageObjectNewSEL, _gPID)))

#define FPDImageObjectDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageObjectDestroySELPROTO)FRCOREROUTINE(FPDImageObjectSEL,FPDImageObjectDestroySEL, _gPID)))

#define FPDImageObjectTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageObjectTransformSELPROTO)FRCOREROUTINE(FPDImageObjectSEL,FPDImageObjectTransformSEL, _gPID)))

#define FPDImageObjectCalcBoundingBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageObjectCalcBoundingBoxSELPROTO)FRCOREROUTINE(FPDImageObjectSEL,FPDImageObjectCalcBoundingBoxSEL, _gPID)))

#define FPDImageObjectGetTransformMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageObjectGetTransformMatrixSELPROTO)FRCOREROUTINE(FPDImageObjectSEL,FPDImageObjectGetTransformMatrixSEL, _gPID)))

#define FPDImageObjectSetTransformMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageObjectSetTransformMatrixSELPROTO)FRCOREROUTINE(FPDImageObjectSEL,FPDImageObjectSetTransformMatrixSEL, _gPID)))

#define FPDImageObjectGetImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageObjectGetImageSELPROTO)FRCOREROUTINE(FPDImageObjectSEL,FPDImageObjectGetImageSEL, _gPID)))

#define FPDImageObjectSetImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageObjectSetImageSELPROTO)FRCOREROUTINE(FPDImageObjectSEL,FPDImageObjectSetImageSEL, _gPID)))

//*****************************
/* ShadingObject HFT functions */
//*****************************

#define FPDShadingObjectNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingObjectNewSELPROTO)FRCOREROUTINE(FPDShadingObjectSEL,FPDShadingObjectNewSEL, _gPID)))

#define FPDShadingObjectDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingObjectDestroySELPROTO)FRCOREROUTINE(FPDShadingObjectSEL,FPDShadingObjectDestroySEL, _gPID)))

#define FPDShadingObjectTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingObjectTransformSELPROTO)FRCOREROUTINE(FPDShadingObjectSEL,FPDShadingObjectTransformSEL, _gPID)))

#define FPDShadingObjectCalcBoundingBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingObjectCalcBoundingBoxSELPROTO)FRCOREROUTINE(FPDShadingObjectSEL,FPDShadingObjectCalcBoundingBoxSEL, _gPID)))

#define FPDShadingObjectGetTransformMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingObjectGetTransformMatrixSELPROTO)FRCOREROUTINE(FPDShadingObjectSEL,FPDShadingObjectGetTransformMatrixSEL, _gPID)))

#define FPDShadingObjectSetTransformMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingObjectSetTransformMatrixSELPROTO)FRCOREROUTINE(FPDShadingObjectSEL,FPDShadingObjectSetTransformMatrixSEL, _gPID)))

#define FPDShadingObjectGetPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingObjectGetPageSELPROTO)FRCOREROUTINE(FPDShadingObjectSEL,FPDShadingObjectGetPageSEL, _gPID)))

#define FPDShadingObjectSetPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingObjectSetPageSELPROTO)FRCOREROUTINE(FPDShadingObjectSEL,FPDShadingObjectSetPageSEL, _gPID)))

#define FPDShadingObjectGetShadingPattern (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingObjectGetShadingPatternSELPROTO)FRCOREROUTINE(FPDShadingObjectSEL,FPDShadingObjectGetShadingPatternSEL, _gPID)))

#define FPDShadingObjectSetShadingPattern (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingObjectSetShadingPatternSELPROTO)FRCOREROUTINE(FPDShadingObjectSEL,FPDShadingObjectSetShadingPatternSEL, _gPID)))

//*****************************
/* FormObject HFT functions */
//*****************************

#define FPDFormObjectNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormObjectNewSELPROTO)FRCOREROUTINE(FPDFormObjectSEL,FPDFormObjectNewSEL, _gPID)))

#define FPDFormObjectDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormObjectDestroySELPROTO)FRCOREROUTINE(FPDFormObjectSEL,FPDFormObjectDestroySEL, _gPID)))

#define FPDFormObjectTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormObjectTransformSELPROTO)FRCOREROUTINE(FPDFormObjectSEL,FPDFormObjectTransformSEL, _gPID)))

#define FPDFormObjectCalcBoundingBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormObjectCalcBoundingBoxSELPROTO)FRCOREROUTINE(FPDFormObjectSEL,FPDFormObjectCalcBoundingBoxSEL, _gPID)))

#define FPDFormObjectGetTransformMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormObjectGetTransformMatrixSELPROTO)FRCOREROUTINE(FPDFormObjectSEL,FPDFormObjectGetTransformMatrixSEL, _gPID)))

#define FPDFormObjectSetTransformMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormObjectSetTransformMatrixSELPROTO)FRCOREROUTINE(FPDFormObjectSEL,FPDFormObjectSetTransformMatrixSEL, _gPID)))

#define FPDFormObjectGetForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormObjectGetFormSELPROTO)FRCOREROUTINE(FPDFormObjectSEL,FPDFormObjectGetFormSEL, _gPID)))

#define FPDFormObjectSetForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormObjectSetFormSELPROTO)FRCOREROUTINE(FPDFormObjectSEL,FPDFormObjectSetFormSEL, _gPID)))

//*****************************
/* InlineImages HFT functions */
//*****************************

#define FPDInlineImagesNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInlineImagesNewSELPROTO)FRCOREROUTINE(FPDInlineImagesSEL,FPDInlineImagesNewSEL, _gPID)))

#define FPDInlineImagesDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInlineImagesDestroySELPROTO)FRCOREROUTINE(FPDInlineImagesSEL,FPDInlineImagesDestroySEL, _gPID)))

#define FPDInlineImagesAddMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInlineImagesAddMatrixSELPROTO)FRCOREROUTINE(FPDInlineImagesSEL,FPDInlineImagesAddMatrixSEL, _gPID)))

#define FPDInlineImagesCountMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInlineImagesCountMatrixSELPROTO)FRCOREROUTINE(FPDInlineImagesSEL,FPDInlineImagesCountMatrixSEL, _gPID)))

#define FPDInlineImagesGetMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInlineImagesGetMatrixSELPROTO)FRCOREROUTINE(FPDInlineImagesSEL,FPDInlineImagesGetMatrixSEL, _gPID)))

#define FPDInlineImagesGetStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInlineImagesGetStreamSELPROTO)FRCOREROUTINE(FPDInlineImagesSEL,FPDInlineImagesGetStreamSEL, _gPID)))

#define FPDInlineImagesSetStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInlineImagesSetStreamSELPROTO)FRCOREROUTINE(FPDInlineImagesSEL,FPDInlineImagesSetStreamSEL, _gPID)))

#define FPDInlineImagesGetDIBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInlineImagesGetDIBitmapSELPROTO)FRCOREROUTINE(FPDInlineImagesSEL,FPDInlineImagesGetDIBitmapSEL, _gPID)))

//*****************************
/* ContentMarkItem HFT functions */
//*****************************

#define FPDContentMarkItemNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemNewSELPROTO)FRCOREROUTINE(FPDContentMarkItemSEL,FPDContentMarkItemNewSEL, _gPID)))

#define FPDContentMarkItemDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemDestroySELPROTO)FRCOREROUTINE(FPDContentMarkItemSEL,FPDContentMarkItemDestroySEL, _gPID)))

#define FPDContentMarkItemGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemGetNameSELPROTO)FRCOREROUTINE(FPDContentMarkItemSEL,FPDContentMarkItemGetNameSEL, _gPID)))

#define FPDContentMarkItemGetParamType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemGetParamTypeSELPROTO)FRCOREROUTINE(FPDContentMarkItemSEL,FPDContentMarkItemGetParamTypeSEL, _gPID)))

#define FPDContentMarkItemGetParam (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemGetParamSELPROTO)FRCOREROUTINE(FPDContentMarkItemSEL,FPDContentMarkItemGetParamSEL, _gPID)))

#define FPDContentMarkItemSetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemSetNameSELPROTO)FRCOREROUTINE(FPDContentMarkItemSEL,FPDContentMarkItemSetNameSEL, _gPID)))

#define FPDContentMarkItemSetParam (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemSetParamSELPROTO)FRCOREROUTINE(FPDContentMarkItemSEL,FPDContentMarkItemSetParamSEL, _gPID)))

#define FPDContentMarkItemHasMCID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemHasMCIDSELPROTO)FRCOREROUTINE(FPDContentMarkItemSEL,FPDContentMarkItemHasMCIDSEL, _gPID)))

//*****************************
/* ContentMark HFT functions */
//*****************************

#define FPDContentMarkNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkNewSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkNewSEL, _gPID)))

#define FPDContentMarkDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkDestroySELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkDestroySEL, _gPID)))

#define FPDContentMarkGetMCID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkGetMCIDSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkGetMCIDSEL, _gPID)))

#define FPDContentMarkHasMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkHasMarkSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkHasMarkSEL, _gPID)))

#define FPDContentMarkLookupMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkLookupMarkSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkLookupMarkSEL, _gPID)))

#define FPDContentMarkCountItems (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkCountItemsSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkCountItemsSEL, _gPID)))

#define FPDContentMarkGetItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkGetItemSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkGetItemSEL, _gPID)))

#define FPDContentMarkAddMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkAddMarkSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkAddMarkSEL, _gPID)))

#define FPDContentMarkDeleteMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkDeleteMarkSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkDeleteMarkSEL, _gPID)))

#define FPDContentMarkDeleteLastMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkDeleteLastMarkSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkDeleteLastMarkSEL, _gPID)))

#define FPDContentMarkIsNull (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkIsNullSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkIsNullSEL, _gPID)))

#define FPDContentMarkCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkCopySELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkCopySEL, _gPID)))

#define FPDContentMarkGetContentMarkDataMCID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkGetContentMarkDataMCIDSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkGetContentMarkDataMCIDSEL, _gPID)))

#define FPDContentMarkCheckContentMarkDataIsNULL (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkCheckContentMarkDataIsNULLSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkCheckContentMarkDataIsNULLSEL, _gPID)))

#define FPDContentMarkGetItem2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkGetItem2SELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkGetItem2SEL, _gPID)))

#define FPDContentMarkAddMark2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkAddMark2SELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkAddMark2SEL, _gPID)))

#define FPDContentMarkGetItems (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkGetItemsSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkGetItemsSEL, _gPID)))

#define FPDContentMarkGetModify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkGetModifySELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkGetModifySEL, _gPID)))

#define FPDContentMarkDoObjectNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkDoObjectNewSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkDoObjectNewSEL, _gPID)))

#define FPDContentMarkIsEqual (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkIsEqualSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkIsEqualSEL, _gPID)))

#define FPDContentMarkCopy2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkCopy2SELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkCopy2SEL, _gPID)))

#define FPDContentMarkGetItem3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkGetItem3SELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkGetItem3SEL, _gPID)))

#define FPDContentMarkRemoveItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkRemoveItemSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkRemoveItemSEL, _gPID)))

#define FPDContentMarkRemoveAllItems (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkRemoveAllItemsSELPROTO)FRCOREROUTINE(FPDContentMarkSEL,FPDContentMarkRemoveAllItemsSEL, _gPID)))

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
/* ContentMarkItemRef HFT functions */
//*****************************

#define FPDContentMarkItemRefGetContentMarkItemObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemRefGetContentMarkItemObjectSELPROTO)FRCOREROUTINE(FPDContentMarkItemRefSEL,FPDContentMarkItemRefGetContentMarkItemObjectSEL, _gPID)))

#define FPDContentMarkItemRefNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemRefNewSELPROTO)FRCOREROUTINE(FPDContentMarkItemRefSEL,FPDContentMarkItemRefNewSEL, _gPID)))

#define FPDContentMarkItemRefGetModify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemRefGetModifySELPROTO)FRCOREROUTINE(FPDContentMarkItemRefSEL,FPDContentMarkItemRefGetModifySEL, _gPID)))

#define FPDContentMarkItemRefCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemRefCreateSELPROTO)FRCOREROUTINE(FPDContentMarkItemRefSEL,FPDContentMarkItemRefCreateSEL, _gPID)))

#define FPDContentMarkItemRefDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemRefDeleteSELPROTO)FRCOREROUTINE(FPDContentMarkItemRefSEL,FPDContentMarkItemRefDeleteSEL, _gPID)))

#define FPDContentMarkItemRefCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDContentMarkItemRefCopySELPROTO)FRCOREROUTINE(FPDContentMarkItemRefSEL,FPDContentMarkItemRefCopySEL, _gPID)))

//----------_V17----------
//*****************************
/* PathData HFT functions */
//*****************************

#define FPDPathDataNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataNewSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataNewSEL, _gPID)))

#define FPDPathDataNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataNew2SELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataNew2SEL, _gPID)))

#define FPDPathDataDestroty (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataDestrotySELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataDestrotySEL, _gPID)))

#define FPDPathDataGetPointCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataGetPointCountSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataGetPointCountSEL, _gPID)))

#define FPDPathDataGetFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataGetFlagSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataGetFlagSEL, _gPID)))

#define FPDPathDataGetPointX (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataGetPointXSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataGetPointXSEL, _gPID)))

#define FPDPathDataGetPointY (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataGetPointYSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataGetPointYSEL, _gPID)))

#define FPDPathDataGetPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataGetPointSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataGetPointSEL, _gPID)))

#define FPDPathDataSetPointCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataSetPointCountSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataSetPointCountSEL, _gPID)))

#define FPDPathDataAllocPointCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataAllocPointCountSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataAllocPointCountSEL, _gPID)))

#define FPDPathDataAddPointCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataAddPointCountSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataAddPointCountSEL, _gPID)))

#define FPDPathDataGetBoundingBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataGetBoundingBoxSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataGetBoundingBoxSEL, _gPID)))

#define FPDPathDataGetBoundingBox2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataGetBoundingBox2SELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataGetBoundingBox2SEL, _gPID)))

#define FPDPathDataTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataTransformSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataTransformSEL, _gPID)))

#define FPDPathDataAppend (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataAppendSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataAppendSEL, _gPID)))

#define FPDPathDataAppendRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataAppendRectSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataAppendRectSEL, _gPID)))

#define FPDPathDataSetPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataSetPointSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataSetPointSEL, _gPID)))

#define FPDPathDataTrimPoints (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataTrimPointsSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataTrimPointsSEL, _gPID)))

#define FPDPathDataCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataCopySELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataCopySEL, _gPID)))

#define FPDPathDataIsRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPathDataIsRectSELPROTO)FRCOREROUTINE(FPDPathDataSEL,FPDPathDataIsRectSEL, _gPID)))

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
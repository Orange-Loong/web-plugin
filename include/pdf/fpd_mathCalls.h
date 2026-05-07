/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_MATHCALLS_H
#define FPD_MATHCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_MATHEXPT_H
#include "fpd_mathExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_mathImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_mathTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_mathImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_mathTempl.h"

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
/* LongImageEncoder HFT functions */
//*****************************

#define FPDLongImageEncoderCreateLongImageEncoder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLongImageEncoderCreateLongImageEncoderSELPROTO)FRCOREROUTINE(FPDLongImageEncoderSEL,FPDLongImageEncoderCreateLongImageEncoderSEL, _gPID)))

#define FPDLongImageEncoderDeleteLongImageEncoder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLongImageEncoderDeleteLongImageEncoderSELPROTO)FRCOREROUTINE(FPDLongImageEncoderSEL,FPDLongImageEncoderDeleteLongImageEncoderSEL, _gPID)))

//*****************************
/* LongImage HFT functions */
//*****************************

#define FPDLongImageCreateLongImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLongImageCreateLongImageSELPROTO)FRCOREROUTINE(FPDLongImageSEL,FPDLongImageCreateLongImageSEL, _gPID)))

#define FPDLongImageDeleteLongImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLongImageDeleteLongImageSELPROTO)FRCOREROUTINE(FPDLongImageSEL,FPDLongImageDeleteLongImageSEL, _gPID)))

#define FPDLongImageAddPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLongImageAddPageSELPROTO)FRCOREROUTINE(FPDLongImageSEL,FPDLongImageAddPageSEL, _gPID)))

#define FPDLongImageAddPage2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLongImageAddPage2SELPROTO)FRCOREROUTINE(FPDLongImageSEL,FPDLongImageAddPage2SEL, _gPID)))

#define FPDLongImageOutput (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLongImageOutputSELPROTO)FRCOREROUTINE(FPDLongImageSEL,FPDLongImageOutputSEL, _gPID)))

#define FPDLongImageOutput2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLongImageOutput2SELPROTO)FRCOREROUTINE(FPDLongImageSEL,FPDLongImageOutput2SEL, _gPID)))

//----------_V17----------
//*****************************
/* MathGraphics HFT functions */
//*****************************

#define FPDMathGraphicsGetGraphics (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMathGraphicsGetGraphicsSELPROTO)FRCOREROUTINE(FPDMathGraphicsSEL,FPDMathGraphicsGetGraphicsSEL, _gPID)))

#define FPDMathGraphicsDifference (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMathGraphicsDifferenceSELPROTO)FRCOREROUTINE(FPDMathGraphicsSEL,FPDMathGraphicsDifferenceSEL, _gPID)))

#define FPDMathGraphicsIntersection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMathGraphicsIntersectionSELPROTO)FRCOREROUTINE(FPDMathGraphicsSEL,FPDMathGraphicsIntersectionSEL, _gPID)))

//----------_V18----------
//*****************************
/* MonoscaleBitmap HFT functions */
//*****************************

#define FPDMonoscaleBitmapGet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMonoscaleBitmapGetSELPROTO)FRCOREROUTINE(FPDMonoscaleBitmapSEL,FPDMonoscaleBitmapGetSEL, _gPID)))

#define FPDMonoscaleBitmapNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMonoscaleBitmapNewSELPROTO)FRCOREROUTINE(FPDMonoscaleBitmapSEL,FPDMonoscaleBitmapNewSEL, _gPID)))

#define FPDMonoscaleBitmapRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMonoscaleBitmapReleaseSELPROTO)FRCOREROUTINE(FPDMonoscaleBitmapSEL,FPDMonoscaleBitmapReleaseSEL, _gPID)))

#define FPDMonoscaleBitmapCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMonoscaleBitmapCreateSELPROTO)FRCOREROUTINE(FPDMonoscaleBitmapSEL,FPDMonoscaleBitmapCreateSEL, _gPID)))

//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
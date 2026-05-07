/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_3DCALLS_H
#define FPD_3DCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_3DEXPT_H
#include "fpd_3DExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_3DImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_3DTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_3DImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_3DTempl.h"

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
//*****************************
/* 3dContext HFT functions */
//*****************************

//*****************************
/* 3dAnnotData HFT functions */
//*****************************

//*****************************
/* 3dAnnotData3dArtwork HFT functions */
//*****************************

//*****************************
/* 3dScene HFT functions */
//*****************************

//*****************************
/* 3deAsset HFT functions */
//*****************************

//*****************************
/* 3deRuntime HFT functions */
//*****************************

//*****************************
/* 3deCanvas HFT functions */
//*****************************

//*****************************
/* 3deView HFT functions */
//*****************************

//*****************************
/* 3deViewRenderMode HFT functions */
//*****************************

//*****************************
/* 3deViewLightingScheme HFT functions */
//*****************************

//*****************************
/* 3deCanvasControllerTool HFT functions */
//*****************************

//*****************************
/* 3dVendor HFT functions */
//*****************************

//*****************************
/* 3deViewBackground HFT functions */
//*****************************

//*****************************
/* 3deViewCameraParam HFT functions */
//*****************************

//*****************************
/* 3deViewCrossSection HFT functions */
//*****************************

//*****************************
/* 3deViewNode HFT functions */
//*****************************

//*****************************
/* 3deMeasure HFT functions */
//*****************************

//*****************************
/* 3deViewMiscOptions HFT functions */
//*****************************

//*****************************
/* 3deTextProvider HFT functions */
//*****************************

//*****************************
/* ScriptHostHostProvider HFT functions */
//*****************************

//*****************************
/* Script3DEngine HFT functions */
//*****************************

//*****************************
/* 3DI18NProviderHandler HFT functions */
//*****************************

//----------_V13----------
//----------_V14----------
//*****************************
/* 3DCompositionProvider HFT functions */
//*****************************

//*****************************
/* BoundingBox HFT functions */
//*****************************

//----------_V15----------
//*****************************
/* 3DFRMConfiguration HFT functions */
//*****************************

//*****************************
/* 3DFRMInstance HFT functions */
//*****************************

//*****************************
/* 3DInstance HFT functions */
//*****************************

//*****************************
/* 3dAnnotDataRichMedia HFT functions */
//*****************************

//*****************************
/* 3deAnimationStyle HFT functions */
//*****************************

//*****************************
/* 3DFRMWindowDimen HFT functions */
//*****************************

//*****************************
/* 3DFRMWindowPos HFT functions */
//*****************************

//*****************************
/* 3DFRMWindow HFT functions */
//*****************************

//*****************************
/* 3DFRMPresentation HFT functions */
//*****************************

//*****************************
/* 3DFRMActivation HFT functions */
//*****************************

//*****************************
/* 3DFRMActivation2 HFT functions */
//*****************************

//*****************************
/* 3DFRMDeactivation HFT functions */
//*****************************

//*****************************
/* 3dCustomMenuItemData HFT functions */
//*****************************

//*****************************
/* 3deSpriteData HFT functions */
//*****************************

//----------_V16----------
//*****************************
/* 3DBuiltin HFT functions */
//*****************************

//----------_V17----------
//*****************************
/* 3DMatrix4x4 HFT functions */
//*****************************

//*****************************
/* 3dCustomToolButtonData HFT functions */
//*****************************

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FDRM_DESCCALLS_H
#define FDRM_DESCCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FDRM_DESCEXPT_H
#include "fdrm_descExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fdrm_descImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fdrm_descTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fdrm_descImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fdrm_descTempl.h"

//----------_V1----------
//----------_V2----------
//*****************************
/* CategoryRead HFT functions */
//*****************************

#define FDRMCategoryReadCountSubCategories (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadCountSubCategoriesSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadCountSubCategoriesSEL, _gPID)))

#define FDRMCategoryReadGetSubCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetSubCategorySELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetSubCategorySEL, _gPID)))

#define FDRMCategoryReadFindSubCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadFindSubCategorySELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadFindSubCategorySEL, _gPID)))

#define FDRMCategoryReadGetParentCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetParentCategorySELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetParentCategorySEL, _gPID)))

#define FDRMCategoryReadGetCategoryName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetCategoryNameSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetCategoryNameSEL, _gPID)))

#define FDRMCategoryReadCountAttributes (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadCountAttributesSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadCountAttributesSEL, _gPID)))

#define FDRMCategoryReadGetAttribute (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetAttributeSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetAttributeSEL, _gPID)))

#define FDRMCategoryReadGetAttributeValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetAttributeValueSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetAttributeValueSEL, _gPID)))

#define FDRMCategoryReadGetCategoryData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetCategoryDataSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetCategoryDataSEL, _gPID)))

#define FDRMCategoryReadDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadDestroySELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadDestroySEL, _gPID)))

//*****************************
/* CategoryWrite HFT functions */
//*****************************

//*****************************
/* DescData HFT functions */
//*****************************

//*****************************
/* ScriptData HFT functions */
//*****************************

//*****************************
/* PresentationData HFT functions */
//*****************************

//*****************************
/* SignatureData HFT functions */
//*****************************

//*****************************
/* DescRead HFT functions */
//*****************************

//*****************************
/* DescWrite HFT functions */
//*****************************

//*****************************
/* FoacRead HFT functions */
//*****************************

//*****************************
/* FoacWrite HFT functions */
//*****************************

//*****************************
/* EnvelopeRead HFT functions */
//*****************************

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
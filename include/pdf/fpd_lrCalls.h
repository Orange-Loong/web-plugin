/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_LRCALLS_H
#define FPD_LRCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_LREXPT_H
#include "fpd_lrExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_lrImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_lrTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_lrImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_lrTempl.h"

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
/* LRContext HFT functions */
//*****************************

#define FPDLRContextCreatePageContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContextCreatePageContextSELPROTO)FRCOREROUTINE(FPDLRContextSEL,FPDLRContextCreatePageContextSEL, _gPID)))

#define FPDLRContextContinue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContextContinueSELPROTO)FRCOREROUTINE(FPDLRContextSEL,FPDLRContextContinueSEL, _gPID)))

#define FPDLRContextRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContextReleaseSELPROTO)FRCOREROUTINE(FPDLRContextSEL,FPDLRContextReleaseSEL, _gPID)))

#define FPDLRContextGetRootElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContextGetRootElementSELPROTO)FRCOREROUTINE(FPDLRContextSEL,FPDLRContextGetRootElementSEL, _gPID)))

#define FPDLRContextReleaseStructureTree (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContextReleaseStructureTreeSELPROTO)FRCOREROUTINE(FPDLRContextSEL,FPDLRContextReleaseStructureTreeSEL, _gPID)))

#define FPDLRContextStart (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContextStartSELPROTO)FRCOREROUTINE(FPDLRContextSEL,FPDLRContextStartSEL, _gPID)))

#define FPDLRContextReleaseStructureTree2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContextReleaseStructureTree2SELPROTO)FRCOREROUTINE(FPDLRContextSEL,FPDLRContextReleaseStructureTree2SEL, _gPID)))

#define FPDLRContextAnalysisOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContextAnalysisOptionsSELPROTO)FRCOREROUTINE(FPDLRContextSEL,FPDLRContextAnalysisOptionsSEL, _gPID)))

//*****************************
/* LRStructureElementRef HFT functions */
//*****************************

#define FPDLRStructureElementRefCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefCreateSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefCreateSEL, _gPID)))

#define FPDLRStructureElementRefDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefDestroySELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefDestroySEL, _gPID)))

#define FPDLRStructureElementRefGetChildren (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefGetChildrenSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefGetChildrenSEL, _gPID)))

#define FPDLRStructureElementRefGetStdStructureType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefGetStdStructureTypeSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefGetStdStructureTypeSEL, _gPID)))

#define FPDLRStructureElementRefIsNull (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefIsNullSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefIsNullSEL, _gPID)))

#define FPDLRStructureElementRefGetStdAttrValueFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefGetStdAttrValueFloatSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefGetStdAttrValueFloatSEL, _gPID)))

#define FPDLRStructureElementRefGetElementType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefGetElementTypeSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefGetElementTypeSEL, _gPID)))

#define FPDLRStructureElementRefGetParentElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefGetParentElementSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefGetParentElementSEL, _gPID)))

#define FPDLRStructureElementRefAsStructureElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefAsStructureElementSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefAsStructureElementSEL, _gPID)))

#define FPDLRStructureElementRefGetBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefGetBBoxSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefGetBBoxSEL, _gPID)))

#define FPDLRStructureElementRefIsEqual (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefIsEqualSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefIsEqualSEL, _gPID)))

#define FPDLRStructureElementRefGetStdAttrType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefGetStdAttrTypeSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefGetStdAttrTypeSEL, _gPID)))

#define FPDLRStructureElementRefGetStdAttrValueEnum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefGetStdAttrValueEnumSELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefGetStdAttrValueEnumSEL, _gPID)))

#define FPDLRStructureElementRefGetStdAttrValueInt32 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRStructureElementRefGetStdAttrValueInt32SELPROTO)FRCOREROUTINE(FPDLRStructureElementRefSEL,FPDLRStructureElementRefGetStdAttrValueInt32SEL, _gPID)))

//*****************************
/* LRElementListRef HFT functions */
//*****************************

#define FPDLRElementListRefCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementListRefCreateSELPROTO)FRCOREROUTINE(FPDLRElementListRefSEL,FPDLRElementListRefCreateSEL, _gPID)))

#define FPDLRElementListRefDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementListRefDestroySELPROTO)FRCOREROUTINE(FPDLRElementListRefSEL,FPDLRElementListRefDestroySEL, _gPID)))

#define FPDLRElementListRefGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementListRefGetSizeSELPROTO)FRCOREROUTINE(FPDLRElementListRefSEL,FPDLRElementListRefGetSizeSEL, _gPID)))

#define FPDLRElementListRefGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementListRefGetAtSELPROTO)FRCOREROUTINE(FPDLRElementListRefSEL,FPDLRElementListRefGetAtSEL, _gPID)))

//*****************************
/* LRElementRef HFT functions */
//*****************************

#define FPDLRElementRefCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementRefCreateSELPROTO)FRCOREROUTINE(FPDLRElementRefSEL,FPDLRElementRefCreateSEL, _gPID)))

#define FPDLRElementRefDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementRefDestroySELPROTO)FRCOREROUTINE(FPDLRElementRefSEL,FPDLRElementRefDestroySEL, _gPID)))

#define FPDLRElementRefAsStructureElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementRefAsStructureElementSELPROTO)FRCOREROUTINE(FPDLRElementRefSEL,FPDLRElementRefAsStructureElementSEL, _gPID)))

#define FPDLRElementRefGetElementType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementRefGetElementTypeSELPROTO)FRCOREROUTINE(FPDLRElementRefSEL,FPDLRElementRefGetElementTypeSEL, _gPID)))

#define FPDLRElementRefAsContentElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementRefAsContentElementSELPROTO)FRCOREROUTINE(FPDLRElementRefSEL,FPDLRElementRefAsContentElementSEL, _gPID)))

#define FPDLRElementRefLR_ISCONTENTTYPE (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementRefLR_ISCONTENTTYPESELPROTO)FRCOREROUTINE(FPDLRElementRefSEL,FPDLRElementRefLR_ISCONTENTTYPESEL, _gPID)))

#define FPDLRElementRefLR_IS_PAGEOBJTYPE (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementRefLR_IS_PAGEOBJTYPESELPROTO)FRCOREROUTINE(FPDLRElementRefSEL,FPDLRElementRefLR_IS_PAGEOBJTYPESEL, _gPID)))

#define FPDLRElementRefLR_IS_STRUCTURETYPE (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRElementRefLR_IS_STRUCTURETYPESELPROTO)FRCOREROUTINE(FPDLRElementRefSEL,FPDLRElementRefLR_IS_STRUCTURETYPESEL, _gPID)))

//*****************************
/* LRContentElementRef HFT functions */
//*****************************

#define FPDLRContentElementRefCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContentElementRefCreateSELPROTO)FRCOREROUTINE(FPDLRContentElementRefSEL,FPDLRContentElementRefCreateSEL, _gPID)))

#define FPDLRContentElementRefDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContentElementRefDestroySELPROTO)FRCOREROUTINE(FPDLRContentElementRefSEL,FPDLRContentElementRefDestroySEL, _gPID)))

#define FPDLRContentElementRefGetPageObjectElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContentElementRefGetPageObjectElementSELPROTO)FRCOREROUTINE(FPDLRContentElementRefSEL,FPDLRContentElementRefGetPageObjectElementSEL, _gPID)))

#define FPDLRContentElementRefGetPageObjectRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContentElementRefGetPageObjectRangeSELPROTO)FRCOREROUTINE(FPDLRContentElementRefSEL,FPDLRContentElementRefGetPageObjectRangeSEL, _gPID)))

#define FPDLRContentElementRefGetBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContentElementRefGetBBoxSELPROTO)FRCOREROUTINE(FPDLRContentElementRefSEL,FPDLRContentElementRefGetBBoxSEL, _gPID)))

#define FPDLRContentElementRefGetElementType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRContentElementRefGetElementTypeSELPROTO)FRCOREROUTINE(FPDLRContentElementRefSEL,FPDLRContentElementRefGetElementTypeSEL, _gPID)))

//*****************************
/* LRPageObjectElementRef HFT functions */
//*****************************

#define FPDLRPageObjectElementRefCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRPageObjectElementRefCreateSELPROTO)FRCOREROUTINE(FPDLRPageObjectElementRefSEL,FPDLRPageObjectElementRefCreateSEL, _gPID)))

#define FPDLRPageObjectElementRefDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRPageObjectElementRefDestroySELPROTO)FRCOREROUTINE(FPDLRPageObjectElementRefSEL,FPDLRPageObjectElementRefDestroySEL, _gPID)))

#define FPDLRPageObjectElementRefGetBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRPageObjectElementRefGetBBoxSELPROTO)FRCOREROUTINE(FPDLRPageObjectElementRefSEL,FPDLRPageObjectElementRefGetBBoxSEL, _gPID)))

#define FPDLRPageObjectElementRefGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRPageObjectElementRefGetDictSELPROTO)FRCOREROUTINE(FPDLRPageObjectElementRefSEL,FPDLRPageObjectElementRefGetDictSEL, _gPID)))

#define FPDLRPageObjectElementRefGetPageObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRPageObjectElementRefGetPageObjectSELPROTO)FRCOREROUTINE(FPDLRPageObjectElementRefSEL,FPDLRPageObjectElementRefGetPageObjectSEL, _gPID)))

#define FPDLRPageObjectElementRefGetElementType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRPageObjectElementRefGetElementTypeSELPROTO)FRCOREROUTINE(FPDLRPageObjectElementRefSEL,FPDLRPageObjectElementRefGetElementTypeSEL, _gPID)))

#define FPDLRPageObjectElementRefGetParentPageObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRPageObjectElementRefGetParentPageObjectSELPROTO)FRCOREROUTINE(FPDLRPageObjectElementRefSEL,FPDLRPageObjectElementRefGetParentPageObjectSEL, _gPID)))

//*****************************
/* LRParseOptions HFT functions */
//*****************************

#define FPDLRParseOptionsCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsCreateSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsCreateSEL, _gPID)))

#define FPDLRParseOptionsDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsDeleteSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsDeleteSEL, _gPID)))

#define FPDLRParseOptionsGetRecognizeDivision (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetRecognizeDivisionSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetRecognizeDivisionSEL, _gPID)))

#define FPDLRParseOptionsSetRecognizeDivision (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetRecognizeDivisionSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetRecognizeDivisionSEL, _gPID)))

#define FPDLRParseOptionsGetLRVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetLRVersionSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetLRVersionSEL, _gPID)))

#define FPDLRParseOptionsSetLRVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetLRVersionSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetLRVersionSEL, _gPID)))

#define FPDLRParseOptionsGetProfile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetProfileSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetProfileSEL, _gPID)))

#define FPDLRParseOptionsSetProfile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetProfileSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetProfileSEL, _gPID)))

#define FPDLRParseOptionsGetUsePageMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetUsePageMatrixSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetUsePageMatrixSEL, _gPID)))

#define FPDLRParseOptionsSetUsePageMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetUsePageMatrixSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetUsePageMatrixSEL, _gPID)))

#define FPDLRParseOptionsGetOCContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetOCContextSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetOCContextSEL, _gPID)))

#define FPDLRParseOptionsSetOCContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetOCContextSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetOCContextSEL, _gPID)))

#define FPDLRParseOptionsGetSelectionRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetSelectionRectSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetSelectionRectSEL, _gPID)))

#define FPDLRParseOptionsSetSelectionRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetSelectionRectSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetSelectionRectSEL, _gPID)))

#define FPDLRParseOptionsGetRecognizeFontConservatively (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetRecognizeFontConservativelySELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetRecognizeFontConservativelySEL, _gPID)))

#define FPDLRParseOptionsSetRecognizeFontConservatively (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetRecognizeFontConservativelySELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetRecognizeFontConservativelySEL, _gPID)))

#define FPDLRParseOptionsGetEnableLayoutAnalyze (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetEnableLayoutAnalyzeSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetEnableLayoutAnalyzeSEL, _gPID)))

#define FPDLRParseOptionsSetEnableLayoutAnalyze (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetEnableLayoutAnalyzeSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetEnableLayoutAnalyzeSEL, _gPID)))

#define FPDLRParseOptionsGetEnableTableContainsFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetEnableTableContainsFloatSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetEnableTableContainsFloatSEL, _gPID)))

#define FPDLRParseOptionsSetEnableTableContainsFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetEnableTableContainsFloatSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetEnableTableContainsFloatSEL, _gPID)))

#define FPDLRParseOptionsGetKeepContainerConsistency (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetKeepContainerConsistencySELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetKeepContainerConsistencySEL, _gPID)))

#define FPDLRParseOptionsSetKeepContainerConsistency (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetKeepContainerConsistencySELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetKeepContainerConsistencySEL, _gPID)))

#define FPDLRParseOptionsGetNNCfgName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetNNCfgNameSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetNNCfgNameSEL, _gPID)))

#define FPDLRParseOptionsSetNNCfgName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetNNCfgNameSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetNNCfgNameSEL, _gPID)))

#define FPDLRParseOptionsGetNNWeightsName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetNNWeightsNameSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetNNWeightsNameSEL, _gPID)))

#define FPDLRParseOptionsSetNNWeightsName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetNNWeightsNameSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetNNWeightsNameSEL, _gPID)))

#define FPDLRParseOptionsGetNNConfidenceLevel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsGetNNConfidenceLevelSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsGetNNConfidenceLevelSEL, _gPID)))

#define FPDLRParseOptionsSetNNConfidenceLevel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRParseOptionsSetNNConfidenceLevelSELPROTO)FRCOREROUTINE(FPDLRParseOptionsSEL,FPDLRParseOptionsSetNNConfidenceLevelSEL, _gPID)))

//----------_V17----------
//*****************************
/* LRAnalysisOptions HFT functions */
//*****************************

#define FPDLRAnalysisOptionsSetOptionString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRAnalysisOptionsSetOptionStringSELPROTO)FRCOREROUTINE(FPDLRAnalysisOptionsSEL,FPDLRAnalysisOptionsSetOptionStringSEL, _gPID)))

#define FPDLRAnalysisOptionsGetSupportedOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRAnalysisOptionsGetSupportedOptionsSELPROTO)FRCOREROUTINE(FPDLRAnalysisOptionsSEL,FPDLRAnalysisOptionsGetSupportedOptionsSEL, _gPID)))

#define FPDLRAnalysisOptionsSetOptionInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRAnalysisOptionsSetOptionIntegerSELPROTO)FRCOREROUTINE(FPDLRAnalysisOptionsSEL,FPDLRAnalysisOptionsSetOptionIntegerSEL, _gPID)))

#define FPDLRAnalysisOptionsSetOptionFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRAnalysisOptionsSetOptionFloatSELPROTO)FRCOREROUTINE(FPDLRAnalysisOptionsSEL,FPDLRAnalysisOptionsSetOptionFloatSEL, _gPID)))

#define FPDLRAnalysisOptionsSetOptionBoolean (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRAnalysisOptionsSetOptionBooleanSELPROTO)FRCOREROUTINE(FPDLRAnalysisOptionsSEL,FPDLRAnalysisOptionsSetOptionBooleanSEL, _gPID)))

#define FPDLRAnalysisOptionsSetOptionFloatRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRAnalysisOptionsSetOptionFloatRectSELPROTO)FRCOREROUTINE(FPDLRAnalysisOptionsSEL,FPDLRAnalysisOptionsSetOptionFloatRectSEL, _gPID)))

#define FPDLRAnalysisOptionsSetOptionOCContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLRAnalysisOptionsSetOptionOCContextSELPROTO)FRCOREROUTINE(FPDLRAnalysisOptionsSEL,FPDLRAnalysisOptionsSetOptionOCContextSEL, _gPID)))

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
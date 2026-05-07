/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_VALIDATECALLS_H
#define FPD_VALIDATECALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_VALIDATEEXPT_H
#include "fpd_validateExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_validateImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_validateTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_validateImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_validateTempl.h"

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
/* ProgressHandler HFT functions */
//*****************************

#define FPDProgressHandlerNewValidatorHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressHandlerNewValidatorHandlerSELPROTO)FRCOREROUTINE(FPDProgressHandlerSEL,FPDProgressHandlerNewValidatorHandlerSEL, _gPID)))

#define FPDProgressHandlerDestroyValidatorHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressHandlerDestroyValidatorHandlerSELPROTO)FRCOREROUTINE(FPDProgressHandlerSEL,FPDProgressHandlerDestroyValidatorHandlerSEL, _gPID)))

//*****************************
/* RuleSet HFT functions */
//*****************************

#define FPDRuleSetCreateAccessiblityRuleSet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRuleSetCreateAccessiblityRuleSetSELPROTO)FRCOREROUTINE(FPDRuleSetSEL,FPDRuleSetCreateAccessiblityRuleSetSEL, _gPID)))

#define FPDRuleSetDestroyAccessiblityRuleSet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRuleSetDestroyAccessiblityRuleSetSELPROTO)FRCOREROUTINE(FPDRuleSetSEL,FPDRuleSetDestroyAccessiblityRuleSetSEL, _gPID)))

#define FPDRuleSetEnableAllRules (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRuleSetEnableAllRulesSELPROTO)FRCOREROUTINE(FPDRuleSetSEL,FPDRuleSetEnableAllRulesSEL, _gPID)))

#define FPDRuleSetEnableRule (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRuleSetEnableRuleSELPROTO)FRCOREROUTINE(FPDRuleSetSEL,FPDRuleSetEnableRuleSEL, _gPID)))

#define FPDRuleSetCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRuleSetCreateSELPROTO)FRCOREROUTINE(FPDRuleSetSEL,FPDRuleSetCreateSEL, _gPID)))

#define FPDRuleSetCreatePDFUARuleSet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRuleSetCreatePDFUARuleSetSELPROTO)FRCOREROUTINE(FPDRuleSetSEL,FPDRuleSetCreatePDFUARuleSetSEL, _gPID)))

#define FPDRuleSetCreatePDFUAFixRuleSet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRuleSetCreatePDFUAFixRuleSetSELPROTO)FRCOREROUTINE(FPDRuleSetSEL,FPDRuleSetCreatePDFUAFixRuleSetSEL, _gPID)))

//*****************************
/* ValidatorFeedbackItem HFT functions */
//*****************************

#define FPDValidatorFeedbackItemCreateValidatorFeedbackItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemCreateValidatorFeedbackItemSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemCreateValidatorFeedbackItemSEL, _gPID)))

#define FPDValidatorFeedbackItemDestroyValidatorFeedbackItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemDestroyValidatorFeedbackItemSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemDestroyValidatorFeedbackItemSEL, _gPID)))

#define FPDValidatorFeedbackItemGetFeedbackItemClass (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemGetFeedbackItemClassSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemGetFeedbackItemClassSEL, _gPID)))

#define FPDValidatorFeedbackItemSetFeedbackItemClass (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemSetFeedbackItemClassSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemSetFeedbackItemClassSEL, _gPID)))

#define FPDValidatorFeedbackItemGetFeedbackItemType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemGetFeedbackItemTypeSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemGetFeedbackItemTypeSEL, _gPID)))

#define FPDValidatorFeedbackItemSetFeedbackItemType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemSetFeedbackItemTypeSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemSetFeedbackItemTypeSEL, _gPID)))

#define FPDValidatorFeedbackItemGetRuleID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemGetRuleIDSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemGetRuleIDSEL, _gPID)))

#define FPDValidatorFeedbackItemSetRuleID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemSetRuleIDSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemSetRuleIDSEL, _gPID)))

#define FPDValidatorFeedbackItemGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemGetDocumentSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemGetDocumentSEL, _gPID)))

#define FPDValidatorFeedbackItemSetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemSetDocumentSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemSetDocumentSEL, _gPID)))

#define FPDValidatorFeedbackItemCastToFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemCastToFontSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemCastToFontSEL, _gPID)))

#define FPDValidatorFeedbackItemCastToAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemCastToAnnotSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemCastToAnnotSEL, _gPID)))

#define FPDValidatorFeedbackItemCastToPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemCastToPageSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemCastToPageSEL, _gPID)))

#define FPDValidatorFeedbackItemCastToPageContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemCastToPageContentSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemCastToPageContentSEL, _gPID)))

#define FPDValidatorFeedbackItemCastToStructElem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemCastToStructElemSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemCastToStructElemSEL, _gPID)))

#define FPDValidatorFeedbackItemCastToField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemCastToFieldSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemSEL,FPDValidatorFeedbackItemCastToFieldSEL, _gPID)))

//*****************************
/* ValidatorFeedbackItemFont HFT functions */
//*****************************

#define FPDValidatorFeedbackItemFontCreateValidatorFeedbackItemFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemFontCreateValidatorFeedbackItemFontSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemFontSEL,FPDValidatorFeedbackItemFontCreateValidatorFeedbackItemFontSEL, _gPID)))

#define FPDValidatorFeedbackItemFontDestroyValidatorFeedbackItemFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemFontDestroyValidatorFeedbackItemFontSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemFontSEL,FPDValidatorFeedbackItemFontDestroyValidatorFeedbackItemFontSEL, _gPID)))

#define FPDValidatorFeedbackItemFontGetFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemFontGetFontSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemFontSEL,FPDValidatorFeedbackItemFontGetFontSEL, _gPID)))

#define FPDValidatorFeedbackItemFontSetFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemFontSetFontSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemFontSEL,FPDValidatorFeedbackItemFontSetFontSEL, _gPID)))

#define FPDValidatorFeedbackItemFontCastToValidatorFeedbackItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemFontCastToValidatorFeedbackItemSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemFontSEL,FPDValidatorFeedbackItemFontCastToValidatorFeedbackItemSEL, _gPID)))

//*****************************
/* ValidatorFeedbackItemAnnot HFT functions */
//*****************************

#define FPDValidatorFeedbackItemAnnotCreateValidatorFeedbackItemAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemAnnotCreateValidatorFeedbackItemAnnotSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemAnnotSEL,FPDValidatorFeedbackItemAnnotCreateValidatorFeedbackItemAnnotSEL, _gPID)))

#define FPDValidatorFeedbackItemAnnotDestroyValidatorFeedbackItemAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemAnnotDestroyValidatorFeedbackItemAnnotSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemAnnotSEL,FPDValidatorFeedbackItemAnnotDestroyValidatorFeedbackItemAnnotSEL, _gPID)))

#define FPDValidatorFeedbackItemAnnotGetAnnotDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemAnnotGetAnnotDictSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemAnnotSEL,FPDValidatorFeedbackItemAnnotGetAnnotDictSEL, _gPID)))

#define FPDValidatorFeedbackItemAnnotSetAnnotDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemAnnotSetAnnotDictSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemAnnotSEL,FPDValidatorFeedbackItemAnnotSetAnnotDictSEL, _gPID)))

#define FPDValidatorFeedbackItemAnnotCastToValidatorFeedbackItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemAnnotCastToValidatorFeedbackItemSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemAnnotSEL,FPDValidatorFeedbackItemAnnotCastToValidatorFeedbackItemSEL, _gPID)))

//*****************************
/* ValidatorFeedbackItemPage HFT functions */
//*****************************

#define FPDValidatorFeedbackItemPageCreateValidatorFeedbackItemPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageCreateValidatorFeedbackItemPageSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageSEL,FPDValidatorFeedbackItemPageCreateValidatorFeedbackItemPageSEL, _gPID)))

#define FPDValidatorFeedbackItemPageDestroyValidatorFeedbackItemPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageDestroyValidatorFeedbackItemPageSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageSEL,FPDValidatorFeedbackItemPageDestroyValidatorFeedbackItemPageSEL, _gPID)))

#define FPDValidatorFeedbackItemPageGetPageDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageGetPageDictSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageSEL,FPDValidatorFeedbackItemPageGetPageDictSEL, _gPID)))

#define FPDValidatorFeedbackItemPageSetPageDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageSetPageDictSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageSEL,FPDValidatorFeedbackItemPageSetPageDictSEL, _gPID)))

#define FPDValidatorFeedbackItemPageGetPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageGetPageIndexSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageSEL,FPDValidatorFeedbackItemPageGetPageIndexSEL, _gPID)))

#define FPDValidatorFeedbackItemPageSetPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageSetPageIndexSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageSEL,FPDValidatorFeedbackItemPageSetPageIndexSEL, _gPID)))

#define FPDValidatorFeedbackItemPageCastToValidatorFeedbackItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageCastToValidatorFeedbackItemSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageSEL,FPDValidatorFeedbackItemPageCastToValidatorFeedbackItemSEL, _gPID)))

//*****************************
/* ValidatorFeedbackItemPageContent HFT functions */
//*****************************

#define FPDValidatorFeedbackItemPageContentCreateValidatorFeedbackItemPageContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageContentCreateValidatorFeedbackItemPageContentSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageContentSEL,FPDValidatorFeedbackItemPageContentCreateValidatorFeedbackItemPageContentSEL, _gPID)))

#define FPDValidatorFeedbackItemPageContentDestroyValidatorFeedbackItemPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageContentDestroyValidatorFeedbackItemPageSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageContentSEL,FPDValidatorFeedbackItemPageContentDestroyValidatorFeedbackItemPageSEL, _gPID)))

#define FPDValidatorFeedbackItemPageContentGetPageDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageContentGetPageDictSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageContentSEL,FPDValidatorFeedbackItemPageContentGetPageDictSEL, _gPID)))

#define FPDValidatorFeedbackItemPageContentSetPageDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageContentSetPageDictSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageContentSEL,FPDValidatorFeedbackItemPageContentSetPageDictSEL, _gPID)))

#define FPDValidatorFeedbackItemPageContentGetPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageContentGetPageIndexSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageContentSEL,FPDValidatorFeedbackItemPageContentGetPageIndexSEL, _gPID)))

#define FPDValidatorFeedbackItemPageContentSetPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageContentSetPageIndexSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageContentSEL,FPDValidatorFeedbackItemPageContentSetPageIndexSEL, _gPID)))

#define FPDValidatorFeedbackItemPageContentGetContentIndexs (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageContentGetContentIndexsSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageContentSEL,FPDValidatorFeedbackItemPageContentGetContentIndexsSEL, _gPID)))

#define FPDValidatorFeedbackItemPageContentSetContentIndexs (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageContentSetContentIndexsSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageContentSEL,FPDValidatorFeedbackItemPageContentSetContentIndexsSEL, _gPID)))

#define FPDValidatorFeedbackItemPageContentGetPageContentRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageContentGetPageContentRectSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageContentSEL,FPDValidatorFeedbackItemPageContentGetPageContentRectSEL, _gPID)))

#define FPDValidatorFeedbackItemPageContentSetPageContentRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageContentSetPageContentRectSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageContentSEL,FPDValidatorFeedbackItemPageContentSetPageContentRectSEL, _gPID)))

#define FPDValidatorFeedbackItemPageContentCastToValidatorFeedbackItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemPageContentCastToValidatorFeedbackItemSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemPageContentSEL,FPDValidatorFeedbackItemPageContentCastToValidatorFeedbackItemSEL, _gPID)))

//*****************************
/* ValidatorFeedbackItemStructElem HFT functions */
//*****************************

#define FPDValidatorFeedbackItemStructElemCreateValidatorFeedbackItemStructElem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemStructElemCreateValidatorFeedbackItemStructElemSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemStructElemSEL,FPDValidatorFeedbackItemStructElemCreateValidatorFeedbackItemStructElemSEL, _gPID)))

#define FPDValidatorFeedbackItemStructElemDestroyValidatorFeedbackItemStructElem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemStructElemDestroyValidatorFeedbackItemStructElemSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemStructElemSEL,FPDValidatorFeedbackItemStructElemDestroyValidatorFeedbackItemStructElemSEL, _gPID)))

#define FPDValidatorFeedbackItemStructElemGetStructElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemStructElemGetStructElementSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemStructElemSEL,FPDValidatorFeedbackItemStructElemGetStructElementSEL, _gPID)))

#define FPDValidatorFeedbackItemStructElemSetStructElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemStructElemSetStructElementSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemStructElemSEL,FPDValidatorFeedbackItemStructElemSetStructElementSEL, _gPID)))

#define FPDValidatorFeedbackItemStructElemCastToValidatorFeedbackItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemStructElemCastToValidatorFeedbackItemSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemStructElemSEL,FPDValidatorFeedbackItemStructElemCastToValidatorFeedbackItemSEL, _gPID)))

//*****************************
/* ValidatorFeedbackItemField HFT functions */
//*****************************

#define FPDValidatorFeedbackItemFieldCreateValidatorFeedbackItemField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemFieldCreateValidatorFeedbackItemFieldSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemFieldSEL,FPDValidatorFeedbackItemFieldCreateValidatorFeedbackItemFieldSEL, _gPID)))

#define FPDValidatorFeedbackItemFieldDestroyValidatorFeedbackItemField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemFieldDestroyValidatorFeedbackItemFieldSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemFieldSEL,FPDValidatorFeedbackItemFieldDestroyValidatorFeedbackItemFieldSEL, _gPID)))

#define FPDValidatorFeedbackItemFieldGetFieldDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemFieldGetFieldDictSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemFieldSEL,FPDValidatorFeedbackItemFieldGetFieldDictSEL, _gPID)))

#define FPDValidatorFeedbackItemFieldSetFieldDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemFieldSetFieldDictSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemFieldSEL,FPDValidatorFeedbackItemFieldSetFieldDictSEL, _gPID)))

#define FPDValidatorFeedbackItemFieldCastToValidatorFeedbackItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorFeedbackItemFieldCastToValidatorFeedbackItemSELPROTO)FRCOREROUTINE(FPDValidatorFeedbackItemFieldSEL,FPDValidatorFeedbackItemFieldCastToValidatorFeedbackItemSEL, _gPID)))

//*****************************
/* Validator HFT functions */
//*****************************

#define FPDValidatorCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorCreateSELPROTO)FRCOREROUTINE(FPDValidatorSEL,FPDValidatorCreateSEL, _gPID)))

#define FPDValidatorDestroyValidator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorDestroyValidatorSELPROTO)FRCOREROUTINE(FPDValidatorSEL,FPDValidatorDestroyValidatorSEL, _gPID)))

#define FPDValidatorEnableAllPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorEnableAllPagesSELPROTO)FRCOREROUTINE(FPDValidatorSEL,FPDValidatorEnableAllPagesSEL, _gPID)))

#define FPDValidatorEnablePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorEnablePageSELPROTO)FRCOREROUTINE(FPDValidatorSEL,FPDValidatorEnablePageSEL, _gPID)))

#define FPDValidatorStart (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorStartSELPROTO)FRCOREROUTINE(FPDValidatorSEL,FPDValidatorStartSEL, _gPID)))

#define FPDValidatorContinue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorContinueSELPROTO)FRCOREROUTINE(FPDValidatorSEL,FPDValidatorContinueSEL, _gPID)))

#define FPDValidatorNextFeedbackItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDValidatorNextFeedbackItemSELPROTO)FRCOREROUTINE(FPDValidatorSEL,FPDValidatorNextFeedbackItemSEL, _gPID)))

//----------_V17----------
//*****************************
/* OprCallback HFT functions */
//*****************************

//*****************************
/* Fix HFT functions */
//*****************************

//*****************************
/* ValidatorFeedbackItemRoleMap HFT functions */
//*****************************

//*****************************
/* ValidatorFeedbackItemMarkInfo HFT functions */
//*****************************

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
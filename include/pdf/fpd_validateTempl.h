/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

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

BEGINENUM
INTERFACE(FPD_ProgressHandler, FPDProgressHandlerNewValidatorHandler, (FPD_ProgressCallbacks callbacks))

INTERFACE(void, FPDProgressHandlerDestroyValidatorHandler, (FPD_ProgressHandler handler))

NumOfSelector(FPDProgressHandler)
ENDENUM

//*****************************
/* RuleSet HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDRuleSetCreateAccessiblityRuleSet
 * @details Create FPD_ValidatorRuleSet.
 * @param[in]  bSelectAll Whether select all rules.
 * @return   FPD_ValidatorRuleSet
 * @note Need to use FPDRuleSetDestroyAccessiblityRuleSet to release.
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_RuleSet, FPDRuleSetCreateAccessiblityRuleSet, (FS_BOOLEAN bSelectAll))

/**
 * @brief FPDRuleSetDestroyAccessiblityRuleSet
 * @details Destroy FPD_ValidatorRuleSet.
 * @param[in]  ruleSet The input FPD_ValidatorRuleSet.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDRuleSetDestroyAccessiblityRuleSet, (FPD_RuleSet ruleSet))

/**
 * @brief FPDRuleSetEnableAllRules
 * @details Enable all rules.
 * @param[in]  ruleSet The input FPD_ValidatorRuleSet.
 * @param[in]  bEnabled Whether enable all rules.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDRuleSetEnableAllRules, (FPD_RuleSet ruleSet,  FS_BOOLEAN bEnabled))

/**
 * @brief FPDRuleSetEnableRule
 * @details Enable specified rule.
 * @param[in]  ruleSet The input FPD_ValidatorRuleSet.
 * @param[in]  dwRuleID The input rule ID.
 * @param[in]  bEnabled Whether enable.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDRuleSetEnableRule, (FPD_RuleSet ruleSet,  FS_DWORD dwRuleID,  FS_BOOLEAN bEnabled))

/**
 * @brief FPDRuleSetCreate
 * @details Create FPD_RuleSet.
 * @param[in]  callbacks The input FPD_RuleSetCallbacks.
 * @return   FPD_RuleSet
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 */
INTERFACE(FPD_RuleSet, FPDRuleSetCreate, (FPD_RuleSetCallbacks callbacks))

/**
 * @brief FPDRuleSetCreatePDFUARuleSet
 * @details Create FPD_ValidatorRuleSet.
 * @param[in]  bSelectAll Whether select all rules.
 * @return   FPD_ValidatorRuleSet
 * @note Need to use FPDRuleSetDestroyAccessiblityRuleSet to release.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 */
INTERFACE(FPD_RuleSet, FPDRuleSetCreatePDFUARuleSet, (FS_BOOLEAN bSelectAll))

/**
 * @brief FPDRuleSetCreatePDFUAFixRuleSet
 * @details Create FPD_ValidatorRuleSet.
 * @param[in]  bSelectAll Whether select all rules.
 * @return   FPD_ValidatorRuleSet
 * @note Need to use FPDRuleSetDestroyAccessiblityRuleSet to release.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 */
INTERFACE(FPD_RuleSet, FPDRuleSetCreatePDFUAFixRuleSet, (FS_BOOLEAN bSelectAll))

NumOfSelector(FPDRuleSet)
ENDENUM

//*****************************
/* ValidatorFeedbackItem HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDValidatorFeedbackItemCreateValidatorFeedbackItem
 * @details Enable specified rule.
 * @return   FPD_ValidatorFeedbackItem
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem, FPDValidatorFeedbackItemCreateValidatorFeedbackItem, ())

/**
 * @brief FPDValidatorFeedbackItemDestroyValidatorFeedbackItem
 * @details Destory FPD_ValidatorFeedbackItem.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemDestroyValidatorFeedbackItem, (FPD_ValidatorFeedbackItem item))

/**
 * @brief FPDValidatorFeedbackItemGetFeedbackItemClass
 * @details Get FPD_ValidatorFeedbackItemClass.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @return   FPD_ValidatorFeedbackItemClass
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItemClass, FPDValidatorFeedbackItemGetFeedbackItemClass, (FPD_ValidatorFeedbackItem item))

/**
 * @brief FPDValidatorFeedbackItemSetFeedbackItemClass
 * @details Set FPD_ValidatorFeedbackItemClass.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @param[in]  itemClass The input FPD_ValidatorFeedbackItemClass.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemSetFeedbackItemClass, (FPD_ValidatorFeedbackItem item,  FPD_ValidatorFeedbackItemClass itemClass))

/**
 * @brief FPDValidatorFeedbackItemGetFeedbackItemType
 * @details Set FPD_ValidatorFeedbackItemType.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @return   FPD_ValidatorFeedbackItemType
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItemType, FPDValidatorFeedbackItemGetFeedbackItemType, (FPD_ValidatorFeedbackItem item))

/**
 * @brief FPDValidatorFeedbackItemSetFeedbackItemType
 * @details Set FPD_ValidatorFeedbackItemType.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @param[in]  item The input FPD_ValidatorFeedbackItemType.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemSetFeedbackItemType, (FPD_ValidatorFeedbackItem item,  FPD_ValidatorFeedbackItemType type))

/**
 * @brief FPDValidatorFeedbackItemGetRuleID
 * @details Get rule ID.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @return   FS_DWORD  Get rule ID.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_DWORD, FPDValidatorFeedbackItemGetRuleID, (FPD_ValidatorFeedbackItem item))

/**
 * @brief FPDValidatorFeedbackItemSetRuleID
 * @details Set rule ID.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @param[in]  ruleID The input rule id.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemSetRuleID, (FPD_ValidatorFeedbackItem item,  FS_DWORD ruleID))

/**
 * @brief FPDValidatorFeedbackItemGetDocument
 * @details Get the document.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @return   FPD_Document
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Document, FPDValidatorFeedbackItemGetDocument, (FPD_ValidatorFeedbackItem item))

/**
 * @brief FPDValidatorFeedbackItemSetDocument
 * @details Set document.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @param[in]  doc The input FPD_Document.
 * @return   FPD_Document
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemSetDocument, (FPD_ValidatorFeedbackItem item,  FPD_Document doc))

/**
 * @brief FPDValidatorFeedbackItemCastToFont
 * @details Convert to its child class of FPD_ValidatorFeedbackItem_Font object.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @return   FPD_ValidatorFeedbackItem_Font
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_Font, FPDValidatorFeedbackItemCastToFont, (FPD_ValidatorFeedbackItem item))

/**
 * @brief FPDValidatorFeedbackItemCastToAnnot
 * @details Convert to its child class of FPD_ValidatorFeedbackItem_Annot object.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @return   FPD_ValidatorFeedbackItem_Annot
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_Annot, FPDValidatorFeedbackItemCastToAnnot, (FPD_ValidatorFeedbackItem item))

/**
 * @brief FPDValidatorFeedbackItemCastToPage
 * @details Convert to its child class of FPD_ValidatorFeedbackItem_Page object.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @return   FPD_ValidatorFeedbackItem_Page
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_Page, FPDValidatorFeedbackItemCastToPage, (FPD_ValidatorFeedbackItem item))

/**
 * @brief FPDValidatorFeedbackItemCastToPageContent
 * @details Convert to its child class of FPD_ValidatorFeedbackItem_PageContent object.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @return   FPD_ValidatorFeedbackItem_PageContent
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_PageContent, FPDValidatorFeedbackItemCastToPageContent, (FPD_ValidatorFeedbackItem item))

/**
 * @brief FPDValidatorFeedbackItemCastToStructElem
 * @details Convert to its child class of FPD_ValidatorFeedbackItem_StructElem object.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @return   FPD_ValidatorFeedbackItem_StructElem
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_StructElem, FPDValidatorFeedbackItemCastToStructElem, (FPD_ValidatorFeedbackItem item))

/**
 * @brief FPDValidatorFeedbackItemCastToField
 * @details Convert to its child class of FPD_ValidatorFeedbackItem_Field object.
 * @param[in]  item The input FPD_ValidatorFeedbackItem.
 * @return   FPD_ValidatorFeedbackItem_Field
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_Field, FPDValidatorFeedbackItemCastToField, (FPD_ValidatorFeedbackItem item))

NumOfSelector(FPDValidatorFeedbackItem)
ENDENUM

//*****************************
/* ValidatorFeedbackItemFont HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDValidatorFeedbackItemFontCreateValidatorFeedbackItemFont
 * @details Create FPD_ValidatorFeedbackItem_Font.
 * @return   FPD_ValidatorFeedbackItem_Font
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_Font, FPDValidatorFeedbackItemFontCreateValidatorFeedbackItemFont, ())

/**
 * @brief FPDValidatorFeedbackItemFontDestroyValidatorFeedbackItemFont
 * @details Destroy FPD_ValidatorFeedbackItem_Font.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Font.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemFontDestroyValidatorFeedbackItemFont, (FPD_ValidatorFeedbackItem_Font item))

/**
 * @brief FPDValidatorFeedbackItemFontGetFont
 * @details Get font of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Font.
 * @return   FPD_Font
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Font, FPDValidatorFeedbackItemFontGetFont, (FPD_ValidatorFeedbackItem_Font item))

/**
 * @brief FPDValidatorFeedbackItemFontSetFont
 * @details Set font of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Font.
 * @param[in]  font The input FPD_Font.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemFontSetFont, (FPD_ValidatorFeedbackItem_Font item,  FPD_Font font))

/**
 * @brief FPDValidatorFeedbackItemFontCastToValidatorFeedbackItem
 * @details Cast FPD_ValidatorFeedbackItem_Font to FPD_ValidatorFeedbackItem.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Font.
 * @return   FPD_ValidatorFeedbackItem
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem, FPDValidatorFeedbackItemFontCastToValidatorFeedbackItem, (FPD_ValidatorFeedbackItem_Font item))

NumOfSelector(FPDValidatorFeedbackItemFont)
ENDENUM

//*****************************
/* ValidatorFeedbackItemAnnot HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDValidatorFeedbackItemAnnotCreateValidatorFeedbackItemAnnot
 * @details Create FPD_ValidatorFeedbackItem_Annot.
 * @return   FPD_ValidatorFeedbackItem_Annot
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_Annot, FPDValidatorFeedbackItemAnnotCreateValidatorFeedbackItemAnnot, ())

/**
 * @brief FPDValidatorFeedbackItemAnnotDestroyValidatorFeedbackItemAnnot
 * @details Destroy FPD_ValidatorFeedbackItem_Annot.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Annot.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemAnnotDestroyValidatorFeedbackItemAnnot, (FPD_ValidatorFeedbackItem_Annot item))

/**
 * @brief FPDValidatorFeedbackItemAnnotGetAnnotDict
 * @details Get annot dictionary of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Annot.
 * @return   FPD_Object  Get annot dictionary of the item.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Object, FPDValidatorFeedbackItemAnnotGetAnnotDict, (FPD_ValidatorFeedbackItem_Annot item))

/**
 * @brief FPDValidatorFeedbackItemAnnotSetAnnotDict
 * @details Set annot dictionary of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Annot.
 * @param[in]  item The input annot dictionary.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemAnnotSetAnnotDict, (FPD_ValidatorFeedbackItem_Annot item,  FPD_Object dic))

/**
 * @brief FPDValidatorFeedbackItemAnnotCastToValidatorFeedbackItem
 * @details Cast FPD_ValidatorFeedbackItem_Annot to FPD_ValidatorFeedbackItem.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Annot.
 * @return   FPD_ValidatorFeedbackItem
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem, FPDValidatorFeedbackItemAnnotCastToValidatorFeedbackItem, (FPD_ValidatorFeedbackItem_Annot item))

NumOfSelector(FPDValidatorFeedbackItemAnnot)
ENDENUM

//*****************************
/* ValidatorFeedbackItemPage HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDValidatorFeedbackItemPageCreateValidatorFeedbackItemPage
 * @details Create FPD_ValidatorFeedbackItem_Page.
 * @return   FPD_ValidatorFeedbackItem_Page
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_Page, FPDValidatorFeedbackItemPageCreateValidatorFeedbackItemPage, ())

/**
 * @brief FPDValidatorFeedbackItemPageDestroyValidatorFeedbackItemPage
 * @details Destroy FPD_ValidatorFeedbackItem_Page.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Page.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemPageDestroyValidatorFeedbackItemPage, (FPD_ValidatorFeedbackItem_Page item))

/**
 * @brief FPDValidatorFeedbackItemPageGetPageDict
 * @details Get page dictionary of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Page.
 * @return   FPD_Object  Get page dictionary of the item.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Object, FPDValidatorFeedbackItemPageGetPageDict, (FPD_ValidatorFeedbackItem_Page item))

/**
 * @brief FPDValidatorFeedbackItemPageSetPageDict
 * @details Set page dictionary of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Page.
 * @param[in]  dic The input page dictionary.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemPageSetPageDict, (FPD_ValidatorFeedbackItem_Page item,  FPD_Object dic))

/**
 * @brief FPDValidatorFeedbackItemPageGetPageIndex
 * @details Get page index of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Page.
 * @return   FS_INT32.    Get page index of the item.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_INT32, FPDValidatorFeedbackItemPageGetPageIndex, (FPD_ValidatorFeedbackItem_Page item))

/**
 * @brief FPDValidatorFeedbackItemPageSetPageIndex
 * @details Set page index of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Page.
 * @param[in]  pageIndex The input page index.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemPageSetPageIndex, (FPD_ValidatorFeedbackItem_Page item,  FS_INT32 pageIndex))

/**
 * @brief FPDValidatorFeedbackItemPageCastToValidatorFeedbackItem
 * @details Cast FPD_ValidatorFeedbackItem_Page to FPD_ValidatorFeedbackItem.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Page.
 * @return   FPD_ValidatorFeedbackItem
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem, FPDValidatorFeedbackItemPageCastToValidatorFeedbackItem, (FPD_ValidatorFeedbackItem_Page item))

NumOfSelector(FPDValidatorFeedbackItemPage)
ENDENUM

//*****************************
/* ValidatorFeedbackItemPageContent HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDValidatorFeedbackItemPageContentCreateValidatorFeedbackItemPageContent
 * @details Create FPD_ValidatorFeedbackItem_PageContent.
 * @return   FPD_ValidatorFeedbackItem_PageContent
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_PageContent, FPDValidatorFeedbackItemPageContentCreateValidatorFeedbackItemPageContent, ())

/**
 * @brief FPDValidatorFeedbackItemPageContentDestroyValidatorFeedbackItemPage
 * @details Destroy FPD_ValidatorFeedbackItem_PageContent.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_PageContent.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemPageContentDestroyValidatorFeedbackItemPage, (FPD_ValidatorFeedbackItem_PageContent item))

/**
 * @brief FPDValidatorFeedbackItemPageContentGetPageDict
 * @details Get the page dictionary of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_PageContent.
 * @return   FPD_Object
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Object, FPDValidatorFeedbackItemPageContentGetPageDict, (FPD_ValidatorFeedbackItem_PageContent item))

/**
 * @brief FPDValidatorFeedbackItemPageContentSetPageDict
 * @details Set the page dictionary of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_PageContent.
 * @param[in]  dic The input page dictionary.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemPageContentSetPageDict, (FPD_ValidatorFeedbackItem_PageContent item,  FPD_Object dic))

/**
 * @brief FPDValidatorFeedbackItemPageContentGetPageIndex
 * @details Get the page index of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_PageContent.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_INT32, FPDValidatorFeedbackItemPageContentGetPageIndex, (FPD_ValidatorFeedbackItem_PageContent item))

/**
 * @brief FPDValidatorFeedbackItemPageContentSetPageIndex
 * @details Set the page index of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_PageContent.
 * @param[in]  pageIndex The input page index.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemPageContentSetPageIndex, (FPD_ValidatorFeedbackItem_PageContent item,  FS_INT32 pageIndex))

/**
 * @brief FPDValidatorFeedbackItemPageContentGetContentIndexs
 * @details Get the content indexes of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_PageContent.
 * @param[out]  contentIndexArr Get the content indexes.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemPageContentGetContentIndexs, (FPD_ValidatorFeedbackItem_PageContent item,  FS_Int32Array* contentIndexArr))

/**
 * @brief FPDValidatorFeedbackItemPageContentSetContentIndexs
 * @details Set the content indexes of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_PageContent.
 * @param[in]  contentIndexArr The input content indexes.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemPageContentSetContentIndexs, (FPD_ValidatorFeedbackItem_PageContent item,  FS_Int32Array contentIndexArr))

/**
 * @brief FPDValidatorFeedbackItemPageContentGetPageContentRect
 * @details Get the content rect of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_PageContent.
 * @param[out]  outRect Get the content rect of the item.
 * @return   FS_BOOL               TRUE: Get the page content rect success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_BOOL, FPDValidatorFeedbackItemPageContentGetPageContentRect, (FPD_ValidatorFeedbackItem_PageContent item,  FS_FloatRect* outRect))

/**
 * @brief FPDValidatorFeedbackItemPageContentSetPageContentRect
 * @details Set the content rect of the item.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_PageContent.
 * @param[in]  rect The input content rect.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemPageContentSetPageContentRect, (FPD_ValidatorFeedbackItem_PageContent item,  FS_FloatRect rect))

/**
 * @brief FPDValidatorFeedbackItemPageContentCastToValidatorFeedbackItem
 * @details Cast FPD_ValidatorFeedbackItem_PageContent to FPD_ValidatorFeedbackItem.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_PageContent.
 * @return   FPD_ValidatorFeedbackItem
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem, FPDValidatorFeedbackItemPageContentCastToValidatorFeedbackItem, (FPD_ValidatorFeedbackItem_PageContent item))

NumOfSelector(FPDValidatorFeedbackItemPageContent)
ENDENUM

//*****************************
/* ValidatorFeedbackItemStructElem HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDValidatorFeedbackItemStructElemCreateValidatorFeedbackItemStructElem
 * @details Create FPD_ValidatorFeedbackItem_StructElem.
 * @return   FPD_ValidatorFeedbackItem_StructElem
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_StructElem, FPDValidatorFeedbackItemStructElemCreateValidatorFeedbackItemStructElem, ())

/**
 * @brief FPDValidatorFeedbackItemStructElemDestroyValidatorFeedbackItemStructElem
 * @details Destroy FPD_ValidatorFeedbackItem_StructElem.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_StructElem.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemStructElemDestroyValidatorFeedbackItemStructElem, (FPD_ValidatorFeedbackItem_StructElem item))

/**
 * @brief FPDValidatorFeedbackItemStructElemGetStructElement
 * @details Get FPD_StructElement of the FPD_ValidatorFeedbackItem_StructElem.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_StructElem.
 * @return   FPD_StructElement
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_StructElement, FPDValidatorFeedbackItemStructElemGetStructElement, (FPD_ValidatorFeedbackItem_StructElem item))

/**
 * @brief FPDValidatorFeedbackItemStructElemSetStructElement
 * @details Set FPD_StructElement of the FPD_ValidatorFeedbackItem_StructElem.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_StructElem.
 * @param[in]  element The input FPD_StructElement.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemStructElemSetStructElement, (FPD_ValidatorFeedbackItem_StructElem item,  FPD_StructElement element))

/**
 * @brief FPDValidatorFeedbackItemStructElemCastToValidatorFeedbackItem
 * @details Cast FPD_ValidatorFeedbackItem_StructElem to FPD_ValidatorFeedbackItem.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_StructElem.
 * @return   FPD_ValidatorFeedbackItem
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem, FPDValidatorFeedbackItemStructElemCastToValidatorFeedbackItem, (FPD_ValidatorFeedbackItem_StructElem item))

NumOfSelector(FPDValidatorFeedbackItemStructElem)
ENDENUM

//*****************************
/* ValidatorFeedbackItemField HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDValidatorFeedbackItemFieldCreateValidatorFeedbackItemField
 * @details Create FPD_ValidatorFeedbackItem_Field.
 * @return   FPD_ValidatorFeedbackItem_Field
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem_Field, FPDValidatorFeedbackItemFieldCreateValidatorFeedbackItemField, ())

/**
 * @brief FPDValidatorFeedbackItemFieldDestroyValidatorFeedbackItemField
 * @details Destroy FPD_ValidatorFeedbackItem_Field.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Field.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemFieldDestroyValidatorFeedbackItemField, (FPD_ValidatorFeedbackItem_Field item))

/**
 * @brief FPDValidatorFeedbackItemFieldGetFieldDict
 * @details Get field dictionary of the FPD_ValidatorFeedbackItem_Field.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Field.
 * @return   FPD_Object
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Object, FPDValidatorFeedbackItemFieldGetFieldDict, (FPD_ValidatorFeedbackItem_Field item))

/**
 * @brief FPDValidatorFeedbackItemFieldSetFieldDict
 * @details Set field dictionary of the FPD_ValidatorFeedbackItem_Field.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Field.
 * @param[in]  dic The input field dictionary.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorFeedbackItemFieldSetFieldDict, (FPD_ValidatorFeedbackItem_Field item,  FPD_Object dic))

/**
 * @brief FPDValidatorFeedbackItemFieldCastToValidatorFeedbackItem
 * @details Cast FPD_ValidatorFeedbackItem_Field to FPD_ValidatorFeedbackItem.
 * @param[in]  item The input FPD_ValidatorFeedbackItem_Field.
 * @return   FPD_ValidatorFeedbackItem
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ValidatorFeedbackItem, FPDValidatorFeedbackItemFieldCastToValidatorFeedbackItem, (FPD_ValidatorFeedbackItem_Field item))

NumOfSelector(FPDValidatorFeedbackItemField)
ENDENUM

//*****************************
/* Validator HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDValidatorCreate
 * @details Create FPD_Validator to validate document.
 * @param[in]  pDocument The input FPD_Document.
 * @param[in]  pRuleSet The input FPD_ValidatorRuleSet.
 * @return   FPD_Validator
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Validator, FPDValidatorCreate, (FPD_Document pDocument,  FPD_RuleSet pRuleSet))

/**
 * @brief FPDValidatorDestroyValidator
 * @details Destroy FPD_Validator.
 * @param[in]  validator The input FPD_Validator.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorDestroyValidator, (FPD_Validator validator))

/**
 * @brief FPDValidatorEnableAllPages
 * @details Enable all pages to validate.
 * @param[in]  validator The input FPD_Validator.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorEnableAllPages, (FPD_Validator validator))

/**
 * @brief FPDValidatorEnablePage
 * @details Enable specified page to validate.
 * @param[in]  validator The input FPD_Validator.
 * @param[in]  pPageDict The input page dictionary.
 * @param[in]  pPreParsed The input page object to parse.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorEnablePage, (FPD_Validator validator,  FPD_Object pPageDict,  FPD_Page pPreParsed))

/**
 * @brief FPDValidatorStart
 * @details Start to validate with options.
 * @param[in]  validator The input FPD_Validator.
 * @param[in]  options The input FPD_ValidatorOptions.
 * @return   FPD_ProgressiveStatus  The validate result.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ProgressiveStatus, FPDValidatorStart, (FPD_Validator validator,  FPD_ValidatorOptions options))

/**
 * @brief FPDValidatorContinue
 * @details Continue to validate with options.
 * @param[in]  validator The input FPD_Validator.
 * @param[in]  pCallback The input FPD_ValidatorHandler.
 * @return   FPD_ProgressiveStatus  The validate result.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ProgressiveStatus, FPDValidatorContinue, (FPD_Validator validator,  FPD_ProgressHandler pCallback))

/**
 * @brief FPDValidatorNextFeedbackItem
 * @details Get the next feed back item.
 * @param[in]  validator The input FPD_Validator.
 * @param[out]  item Get the next feed back item.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDValidatorNextFeedbackItem, (FPD_Validator validator,  FPD_ValidatorFeedbackItem* item))

NumOfSelector(FPDValidator)
ENDENUM

//----------_V17----------
//*****************************
/* OprCallback HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_OprCallback, FPDOprCallbackCreate, (FPD_OprerateCallbacks callbacks))

INTERFACE(void, FPDOprCallbackDestroy, (FPD_OprCallback opr))

NumOfSelector(FPDOprCallback)
ENDENUM

//*****************************
/* Fix HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_Fix, FPDFixCreate, (FPD_Document pDocument,  FPD_RuleSet pFixRSet))

INTERFACE(void, FPDFixDestroy, (FPD_Fix fix))

INTERFACE(void, FPDFixEnableAllPages, (FPD_Fix fix))

INTERFACE(void, FPDFixEnablePage, (FPD_Fix fix,  FPD_Object pPageDict,  FPD_Page pPreParsed))

INTERFACE(FPD_ProgressiveStatus, FPDFixStart, (FPD_Fix fix,  FPD_OprCallback pResutCallback))

INTERFACE(FPD_ProgressiveStatus, FPDFixContinue, (FPD_Fix fix,  FPD_ProgressHandler pCallback))

INTERFACE(FPD_ValidatorFeedbackItem, FPDFixNextFeedbackItem, (FPD_Fix fix))

NumOfSelector(FPDFix)
ENDENUM

//*****************************
/* ValidatorFeedbackItemRoleMap HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_ValidatorFeedbackItem_RoleMap, FPDValidatorFeedbackItemRoleMapCreate, ())

INTERFACE(void, FPDValidatorFeedbackItemRoleMapDestroy, (FPD_ValidatorFeedbackItem_RoleMap roleMap))

INTERFACE(void, FPDValidatorFeedbackItemRoleMapGetRoles, (FPD_ValidatorFeedbackItem_RoleMap roleMap,  FS_ByteStringArray* outArray))

INTERFACE(void, FPDValidatorFeedbackItemRoleMapSetRoles, (FPD_ValidatorFeedbackItem_RoleMap roleMap,  FS_ByteStringArray roleArray))

INTERFACE(FPD_ValidatorFeedbackItem, FPDValidatorFeedbackItemRoleMapCastToValidatorFeedbackItem, (FPD_ValidatorFeedbackItem_RoleMap roleMap))

NumOfSelector(FPDValidatorFeedbackItemRoleMap)
ENDENUM

//*****************************
/* ValidatorFeedbackItemMarkInfo HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_ValidatorFeedbackItem_MarkInfo, FPDValidatorFeedbackItemMarkInfoCreate, ())

INTERFACE(void, FPDValidatorFeedbackItemMarkInfoDestroy, (FPD_ValidatorFeedbackItem_MarkInfo info))

INTERFACE(void, FPDValidatorFeedbackItemMarkInfoGetRoles, (FPD_ValidatorFeedbackItem_MarkInfo info,  FS_ByteString* key))

INTERFACE(void, FPDValidatorFeedbackItemMarkInfoSetRoles, (FPD_ValidatorFeedbackItem_MarkInfo info,  FS_LPCSTR key))

INTERFACE(FPD_ValidatorFeedbackItem, FPDValidatorFeedbackItemMarkInfoCastToValidatorFeedbackItem, (FPD_ValidatorFeedbackItem_MarkInfo info))

NumOfSelector(FPDValidatorFeedbackItemMarkInfo)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

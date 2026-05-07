#ifndef FPD_VALIDATEIMPL_H
#define FPD_VALIDATEIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../fpd_parserExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "../fpd_pageExpT.h"
#endif

#ifndef FPD_VALIDATEEXPT_H
#include "../fpd_validateExpT.h"
#endif

#include "../../../ExternalModule/FXCORE/include/fpdfpreflight/fpdfpreflight.h"

#ifdef __cplusplus
extern "C" {
#endif

	class CFPD_ProgressHandler_V16
	{
	public:
		//************************************
		// Function:  NewConvertHandler
		// Param[in]: callbacks		The input FPD_ValidateCallbacks.
		// Return:    FPD_ValidateHandler
		// Remarks:   Create FPD_ValidateHandler.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ProgressHandler NewValidatorHandler(FPD_ProgressCallbacks callbacks);

		//************************************
		// Function:  DestroyConvertHandler
		// Param[in]: handler		The input FPD_ValidateHandler.
		// Return:    void
		// Remarks:   Destroy FPD_ValidateHandler.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void DestroyValidatorHandler(FPD_ProgressHandler handler);
	};

	class CFPD_RuleSetHandler : public IPDF_RuleSet
	{
	public:
		CFPD_RuleSetHandler(FPD_RuleSetCallbacks callbacks);
		virtual ~CFPD_RuleSetHandler();
		virtual void EnableAllRules(FX_BOOL bEnabled);
		virtual void EnableRule(FX_DWORD dwRuleID, FX_BOOL bEnabled);

		FPD_RuleSetCallbacksRec m_callbacks;
	};

	class CFPD_RuleSet_V16
	{
	public:
		//************************************
		// Function:  CreateAccessiblityRuleSet
		// Param[in]: bSelectAll		Whether select all rules.
		// Return:    FPD_ValidatorRuleSet
		// Remarks:   Create FPD_ValidatorRuleSet.
		// Notes: Need to use FPDRuleSetDestroyAccessiblityRuleSet to release.
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_RuleSet CreateAccessiblityRuleSet(FS_BOOLEAN bSelectAll);

		//************************************
		// Function:  DestroyAccessiblityRuleSet
		// Param[in]: ruleSet		The input FPD_ValidatorRuleSet.
		// Return:    void
		// Remarks:   Destroy FPD_ValidatorRuleSet.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void DestroyAccessiblityRuleSet(FPD_RuleSet ruleSet);

		//************************************
		// Function:  EnableAllRules
		// Param[in]: ruleSet		The input FPD_ValidatorRuleSet.
		// Param[in]: bEnabled		Whether enable all rules.
		// Return:    void
		// Remarks:   Enable all rules.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void EnableAllRules(FPD_RuleSet ruleSet, FS_BOOLEAN bEnabled);

		//************************************
		// Function:  EnableRule
		// Param[in]: ruleSet		The input FPD_ValidatorRuleSet.
		// Param[in]: dwRuleID		The input rule ID.
		// Param[in]: bEnabled		Whether enable.
		// Return:    void
		// Remarks:  Enable specified rule.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void EnableRule(FPD_RuleSet ruleSet, FS_DWORD dwRuleID, FS_BOOLEAN bEnabled);

		//************************************
		// Function:  Create
		// Param[in]: callbacks		The input FPD_RuleSetCallbacks.	
		// Return:    FPD_RuleSet
		// Remarks:  Create FPD_RuleSet.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
		//************************************
		static FPD_RuleSet Create(FPD_RuleSetCallbacks callbacks);

		//************************************
		// Function:  CreatePDFUARuleSet
		// Param[in]: bSelectAll		Whether select all rules.
		// Return:    FPD_ValidatorRuleSet
		// Remarks:   Create FPD_ValidatorRuleSet.
		// Notes: Need to use FPDRuleSetDestroyAccessiblityRuleSet to release.
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
		//************************************
		static FPD_RuleSet CreatePDFUARuleSet(FS_BOOLEAN bSelectAll);

		//************************************
		// Function:  CreatePDFUAFixRuleSet
		// Param[in]: bSelectAll		Whether select all rules.
		// Return:    FPD_ValidatorRuleSet
		// Remarks:   Create FPD_ValidatorRuleSet.
		// Notes: Need to use FPDRuleSetDestroyAccessiblityRuleSet to release.
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
		//************************************
		static FPD_RuleSet CreatePDFUAFixRuleSet(FS_BOOLEAN bSelectAll);
	};

	class CFPD_ValidatorFeedbackItem_V16
	{
	public:
		//************************************
		// Function:  CreateValidatorFeedbackItem	
		// Return:    FPD_ValidatorFeedbackItem
		// Remarks:  Enable specified rule.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem CreateValidatorFeedbackItem();

		//************************************
		// Function:  DestroyValidatorFeedbackItem
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.
		// Return:    void
		// Remarks:  Destory FPD_ValidatorFeedbackItem.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void DestroyValidatorFeedbackItem(FPD_ValidatorFeedbackItem item);

		//************************************
		// Function:  GetFeedbackItemClass
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.
		// Return:    FPD_ValidatorFeedbackItemClass
		// Remarks:  Get FPD_ValidatorFeedbackItemClass.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItemClass GetFeedbackItemClass(FPD_ValidatorFeedbackItem item);

		//************************************
		// Function:  SetFeedbackItemClass
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.
		// Param[in]: itemClass	The input FPD_ValidatorFeedbackItemClass.
		// Return:    void
		// Remarks:  Set FPD_ValidatorFeedbackItemClass.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetFeedbackItemClass(FPD_ValidatorFeedbackItem item, FPD_ValidatorFeedbackItemClass itemClass);

		//************************************
		// Function:  GetFeedbackItemType
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.	
		// Return:    FPD_ValidatorFeedbackItemType
		// Remarks:  Set FPD_ValidatorFeedbackItemType.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItemType GetFeedbackItemType(FPD_ValidatorFeedbackItem item);

		//************************************
		// Function:  SetFeedbackItemType
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.	
		// Param[in]: item		The input FPD_ValidatorFeedbackItemType.	
		// Return:    void
		// Remarks:  Set FPD_ValidatorFeedbackItemType.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetFeedbackItemType(FPD_ValidatorFeedbackItem item, FPD_ValidatorFeedbackItemType type);

		//************************************
		// Function:  GetRuleID
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.	
		// Return:    FS_DWORD  Get rule ID.
		// Remarks:  Get rule ID.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FS_DWORD GetRuleID(FPD_ValidatorFeedbackItem item);

		//************************************
		// Function:  SetRuleID
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.	
		// Param[in]: ruleID	The input rule id.	
		// Return:    void
		// Remarks:  Set rule ID.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetRuleID(FPD_ValidatorFeedbackItem item, FS_DWORD ruleID);

		//************************************
		// Function:  GetDocument
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.	
		// Return:    FPD_Document
		// Remarks:  Get the document.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_Document GetDocument(FPD_ValidatorFeedbackItem item);

		//************************************
		// Function:  SetDocument
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.	
		// Param[in]: doc		The input FPD_Document.	
		// Return:    FPD_Document
		// Remarks:  Set document.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetDocument(FPD_ValidatorFeedbackItem item, FPD_Document doc);

		//************************************
		// Function:  CastToFont
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.
		// Return:    FPD_ValidatorFeedbackItem_Font
		// Remarks:  Convert to its child class of FPD_ValidatorFeedbackItem_Font object.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_Font CastToFont(FPD_ValidatorFeedbackItem item);

		//************************************
		// Function:  CastToAnnot
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.
		// Return:    FPD_ValidatorFeedbackItem_Annot
		// Remarks:  Convert to its child class of FPD_ValidatorFeedbackItem_Annot object.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_Annot CastToAnnot(FPD_ValidatorFeedbackItem item);

		//************************************
		// Function:  CastToPage
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.
		// Return:    FPD_ValidatorFeedbackItem_Page
		// Remarks:  Convert to its child class of FPD_ValidatorFeedbackItem_Page object.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_Page CastToPage(FPD_ValidatorFeedbackItem item);

		//************************************
		// Function:  CastToPageContent
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.
		// Return:    FPD_ValidatorFeedbackItem_PageContent
		// Remarks:  Convert to its child class of FPD_ValidatorFeedbackItem_PageContent object.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_PageContent CastToPageContent(FPD_ValidatorFeedbackItem item);

		//************************************
		// Function:  CastToStructElem
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.
		// Return:    FPD_ValidatorFeedbackItem_StructElem
		// Remarks:  Convert to its child class of FPD_ValidatorFeedbackItem_StructElem object.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_StructElem CastToStructElem(FPD_ValidatorFeedbackItem item);

		//************************************
		// Function:  CastToField
		// Param[in]: item		The input FPD_ValidatorFeedbackItem.
		// Return:    FPD_ValidatorFeedbackItem_Field
		// Remarks:  Convert to its child class of FPD_ValidatorFeedbackItem_Field object.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_Field CastToField(FPD_ValidatorFeedbackItem item);
	};

	class CFPD_ValidatorFeedbackItemFont_V16
	{
	public:
		//************************************
		// Function:  CreateValidatorFeedbackItemFont	
		// Return:    FPD_ValidatorFeedbackItem_Font
		// Remarks:  Create FPD_ValidatorFeedbackItem_Font.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_Font CreateValidatorFeedbackItemFont();

		//************************************
		// Function:  DestroyValidatorFeedbackItemFont	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Font.	
		// Return:    void
		// Remarks:  Destroy FPD_ValidatorFeedbackItem_Font.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void DestroyValidatorFeedbackItemFont(FPD_ValidatorFeedbackItem_Font item);

		//************************************
		// Function:  GetFont	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Font.	
		// Return:    FPD_Font
		// Remarks:  Get font of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_Font GetFont(FPD_ValidatorFeedbackItem_Font item);

		//************************************
		// Function:  SetFont	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Font.	
		// Param[in]: font		The input FPD_Font.	
		// Return:    void
		// Remarks:  Set font of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetFont(FPD_ValidatorFeedbackItem_Font item, FPD_Font font);

		//************************************
		// Function:  CastToValidatorFeedbackItem	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Font.	
		// Return:    FPD_ValidatorFeedbackItem
		// Remarks:  Cast FPD_ValidatorFeedbackItem_Font to FPD_ValidatorFeedbackItem.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem CastToValidatorFeedbackItem(FPD_ValidatorFeedbackItem_Font item);
	};

	class CFPD_ValidatorFeedbackItemAnnot_V16
	{
	public:
		//************************************
		// Function:  CreateValidatorFeedbackItemAnnot		
		// Return:    FPD_ValidatorFeedbackItem_Annot
		// Remarks:  Create FPD_ValidatorFeedbackItem_Annot.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_Annot CreateValidatorFeedbackItemAnnot();

		//************************************
		// Function:  DestroyValidatorFeedbackItemAnnot	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Annot.	
		// Return:    void
		// Remarks:  Destroy FPD_ValidatorFeedbackItem_Annot.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void DestroyValidatorFeedbackItemAnnot(FPD_ValidatorFeedbackItem_Annot item);

		//************************************
		// Function:  GetAnnotDict	
		// Param[in]: item		  The input FPD_ValidatorFeedbackItem_Annot.	
		// Return:    FPD_Object  Get annot dictionary of the item.
		// Remarks:  Get annot dictionary of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_Object GetAnnotDict(FPD_ValidatorFeedbackItem_Annot item);

		//************************************
		// Function:  SetAnnotDict	
		// Param[in]: item		  The input FPD_ValidatorFeedbackItem_Annot.
		// Param[in]: item		  The input annot dictionary.	
		// Return:   void
		// Remarks:  Set annot dictionary of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetAnnotDict(FPD_ValidatorFeedbackItem_Annot item, FPD_Object dic);

		//************************************
		// Function:  CastToValidatorFeedbackItem	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Annot.	
		// Return:    FPD_ValidatorFeedbackItem
		// Remarks:  Cast FPD_ValidatorFeedbackItem_Annot to FPD_ValidatorFeedbackItem.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem CastToValidatorFeedbackItem(FPD_ValidatorFeedbackItem_Annot item);
	};

	class CFPD_ValidatorFeedbackItemPage_V16
	{
	public:
		//************************************
		// Function:  CreateValidatorFeedbackItemPage		
		// Return:    FPD_ValidatorFeedbackItem_Page
		// Remarks:  Create FPD_ValidatorFeedbackItem_Page.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_Page CreateValidatorFeedbackItemPage();

		//************************************
		// Function:  DestroyValidatorFeedbackItemPage	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Page.	
		// Return:    void
		// Remarks:  Destroy FPD_ValidatorFeedbackItem_Page.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void DestroyValidatorFeedbackItemPage(FPD_ValidatorFeedbackItem_Page item);

		//************************************
		// Function:  GetPageDict	
		// Param[in]: item		  The input FPD_ValidatorFeedbackItem_Page.	
		// Return:    FPD_Object  Get page dictionary of the item.
		// Remarks:  Get page dictionary of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_Object GetPageDict(FPD_ValidatorFeedbackItem_Page item);

		//************************************
		// Function:  SetPageDict	
		// Param[in]: item		  The input FPD_ValidatorFeedbackItem_Page.	
		// Param[in]: dic		  The input page dictionary.
		// Return:   void.
		// Remarks:  Set page dictionary of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetPageDict(FPD_ValidatorFeedbackItem_Page item, FPD_Object dic);

		//************************************
		// Function:  GetPageIndex	
		// Param[in]: item		  The input FPD_ValidatorFeedbackItem_Page.	
		// Return:   FS_INT32.    Get page index of the item.
		// Remarks:  Get page index of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FS_INT32 GetPageIndex(FPD_ValidatorFeedbackItem_Page item);

		//************************************
		// Function:  SetPageIndex	
		// Param[in]: item		  The input FPD_ValidatorFeedbackItem_Page.	
		// Param[in]: pageIndex	  The input page index.
		// Return:   void.
		// Remarks:  Set page index of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetPageIndex(FPD_ValidatorFeedbackItem_Page item, FS_INT32 pageIndex);

		//************************************
		// Function:  CastToValidatorFeedbackItem	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Page.	
		// Return:    FPD_ValidatorFeedbackItem
		// Remarks:  Cast FPD_ValidatorFeedbackItem_Page to FPD_ValidatorFeedbackItem.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem CastToValidatorFeedbackItem(FPD_ValidatorFeedbackItem_Page item);
	};

	class CFPD_ValidatorFeedbackItemPageContent_V16
	{
	public:
		//************************************
		// Function:  CreateValidatorFeedbackItemPageContent		
		// Return:    FPD_ValidatorFeedbackItem_PageContent
		// Remarks:  Create FPD_ValidatorFeedbackItem_PageContent.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_PageContent CreateValidatorFeedbackItemPageContent();

		//************************************
		// Function:  DestroyValidatorFeedbackItemPage	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_PageContent.	
		// Return:    void
		// Remarks:  Destroy FPD_ValidatorFeedbackItem_PageContent.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void DestroyValidatorFeedbackItemPage(FPD_ValidatorFeedbackItem_PageContent item);

		//************************************
		// Function:  GetPageDict	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_PageContent.	
		// Return:    FPD_Object
		// Remarks:  Get the page dictionary of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_Object GetPageDict(FPD_ValidatorFeedbackItem_PageContent item);

		//************************************
		// Function:  SetPageDict	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_PageContent.
		// Param[in]: dic		The input page dictionary.	
		// Return:    void
		// Remarks:  Set the page dictionary of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetPageDict(FPD_ValidatorFeedbackItem_PageContent item, FPD_Object dic);

		//************************************
		// Function:  GetPageIndex	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_PageContent.	
		// Return:    FS_INT32
		// Remarks:  Get the page index of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FS_INT32 GetPageIndex(FPD_ValidatorFeedbackItem_PageContent item);

		//************************************
		// Function:  SetPageIndex	
		// Param[in]: item		    The input FPD_ValidatorFeedbackItem_PageContent.	
		// Param[in]: pageIndex		The input page index.	
		// Return:    void
		// Remarks:  Set the page index of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetPageIndex(FPD_ValidatorFeedbackItem_PageContent item, FS_INT32 pageIndex);

		//************************************
		// Function:  GetContentIndexs	
		// Param[in]: item		            The input FPD_ValidatorFeedbackItem_PageContent.	
		// Param[out]: contentIndexArr		Get the content indexes.	
		// Return:    void
		// Remarks:  Get the content indexes of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void GetContentIndexs(FPD_ValidatorFeedbackItem_PageContent item, FS_Int32Array* contentIndexArr);

		//************************************
		// Function:  SetContentIndexs	
		// Param[in]: item		            The input FPD_ValidatorFeedbackItem_PageContent.	
		// Param[in]: contentIndexArr		The input content indexes.	
		// Return:    void
		// Remarks:  Set the content indexes of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetContentIndexs(FPD_ValidatorFeedbackItem_PageContent item, FS_Int32Array contentIndexArr);

		//************************************
		// Function:  GetPageContentRect	
		// Param[in]: item		            The input FPD_ValidatorFeedbackItem_PageContent.
		// Param[out]: outRect		        Get the content rect of the item.
		// Return:    FS_BOOL               TRUE: Get the page content rect success.
		// Remarks:  Get the content rect of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FS_BOOL GetPageContentRect(FPD_ValidatorFeedbackItem_PageContent item, FS_FloatRect* outRect);

		//************************************
		// Function:  SetPageContentRect	
		// Param[in]: item		            The input FPD_ValidatorFeedbackItem_PageContent.
		// Param[in]: rect		            The input content rect.
		// Return:    void
		// Remarks:  Set the content rect of the item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetPageContentRect(FPD_ValidatorFeedbackItem_PageContent item, FS_FloatRect rect);

		//************************************
		// Function:  CastToValidatorFeedbackItem	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_PageContent.	
		// Return:    FPD_ValidatorFeedbackItem
		// Remarks:  Cast FPD_ValidatorFeedbackItem_PageContent to FPD_ValidatorFeedbackItem.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem CastToValidatorFeedbackItem(FPD_ValidatorFeedbackItem_PageContent item);
	};

	class CFPD_ValidatorFeedbackItemStructElem_V16
	{
	public:
		//************************************
		// Function:  CreateValidatorFeedbackItemStructElem		
		// Return:    FPD_ValidatorFeedbackItem_StructElem
		// Remarks:  Create FPD_ValidatorFeedbackItem_StructElem.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_StructElem CreateValidatorFeedbackItemStructElem();

		//************************************
		// Function:  DestroyValidatorFeedbackItemStructElem	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_StructElem.	
		// Return:    void
		// Remarks:  Destroy FPD_ValidatorFeedbackItem_StructElem.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void DestroyValidatorFeedbackItemStructElem(FPD_ValidatorFeedbackItem_StructElem item);

		//************************************
		// Function:  GetStructElement	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_StructElem.	
		// Return:    FPD_StructElement
		// Remarks:  Get FPD_StructElement of the FPD_ValidatorFeedbackItem_StructElem.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_StructElement GetStructElement(FPD_ValidatorFeedbackItem_StructElem item);

		//************************************
		// Function:  SetStructElement	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_StructElem.	
		// Param[in]: element	The input FPD_StructElement.	
		// Return:    void
		// Remarks:  Set FPD_StructElement of the FPD_ValidatorFeedbackItem_StructElem.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetStructElement(FPD_ValidatorFeedbackItem_StructElem item, FPD_StructElement element);

		//************************************
		// Function:  CastToValidatorFeedbackItem	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_StructElem.	
		// Return:    FPD_ValidatorFeedbackItem
		// Remarks:  Cast FPD_ValidatorFeedbackItem_StructElem to FPD_ValidatorFeedbackItem.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem CastToValidatorFeedbackItem(FPD_ValidatorFeedbackItem_StructElem item);
	};

	class CFPD_ValidatorFeedbackItemField_V16
	{
	public:
		//************************************
		// Function:  CreateValidatorFeedbackItemField		
		// Return:    FPD_ValidatorFeedbackItem_Field
		// Remarks:  Create FPD_ValidatorFeedbackItem_Field.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem_Field CreateValidatorFeedbackItemField();

		//************************************
		// Function:  DestroyValidatorFeedbackItemField	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Field.	
		// Return:    void
		// Remarks:  Destroy FPD_ValidatorFeedbackItem_Field.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void DestroyValidatorFeedbackItemField(FPD_ValidatorFeedbackItem_Field item);

		//************************************
		// Function:  GetFieldDict	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Field.	
		// Return:    FPD_Object
		// Remarks:  Get field dictionary of the FPD_ValidatorFeedbackItem_Field.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_Object GetFieldDict(FPD_ValidatorFeedbackItem_Field item);

		//************************************
		// Function:  SetFieldDict	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Field.	
		// Param[in]: dic		The input field dictionary.	
		// Return:    void
		// Remarks:  Set field dictionary of the FPD_ValidatorFeedbackItem_Field.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void SetFieldDict(FPD_ValidatorFeedbackItem_Field item, FPD_Object dic);

		//************************************
		// Function:  CastToValidatorFeedbackItem	
		// Param[in]: item		The input FPD_ValidatorFeedbackItem_Field.	
		// Return:    FPD_ValidatorFeedbackItem
		// Remarks:  Cast FPD_ValidatorFeedbackItem_Field to FPD_ValidatorFeedbackItem.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ValidatorFeedbackItem CastToValidatorFeedbackItem(FPD_ValidatorFeedbackItem_Field item);
	};

	class CFPD_Validator_V16
	{
	public:
		//************************************
		// Function:  Create	
		// Param[in]: pDocument		The input FPD_Document.	
		// Param[in]: pRuleSet		The input FPD_ValidatorRuleSet.
		// Return:    FPD_Validator
		// Remarks:  Create FPD_Validator to validate document.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_Validator Create(FPD_Document pDocument, FPD_RuleSet pRuleSet);

		//************************************
		// Function:  DestroyValidator	
		// Param[in]: validator		The input FPD_Validator.
		// Return:    void
		// Remarks:  Destroy FPD_Validator.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void DestroyValidator(FPD_Validator validator);

		//************************************
		// Function:  EnableAllPages	
		// Param[in]: validator		The input FPD_Validator.
		// Return:    void
		// Remarks:  Enable all pages to validate.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void	 EnableAllPages(FPD_Validator validator);

		//************************************
		// Function:  EnablePage	
		// Param[in]: validator		The input FPD_Validator.
		// Param[in]: pPageDict		The input page dictionary.
		// Param[in]: pPreParsed	The input page object to parse.
		// Return:    void
		// Remarks:  Enable specified page to validate.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void	 EnablePage(FPD_Validator validator, FPD_Object pPageDict, FPD_Page pPreParsed);

		//************************************
		// Function:  Start	
		// Param[in]: validator		The input FPD_Validator.
		// Param[in]: options		The input FPD_ValidatorOptions.
		// Return:    FPD_ProgressiveStatus  The validate result.
		// Remarks:  Start to validate with options.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ProgressiveStatus Start(FPD_Validator validator, FPD_ValidatorOptions options);

		//************************************
		// Function:  Continue	
		// Param[in]: validator		The input FPD_Validator.
		// Param[in]: pCallback		The input FPD_ValidatorHandler.
		// Return:    FPD_ProgressiveStatus  The validate result.
		// Remarks:  Continue to validate with options.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static FPD_ProgressiveStatus Continue(FPD_Validator validator, FPD_ProgressHandler pCallback);

		//************************************
		// Function:  NextFeedbackItem	
		// Param[in]: validator		The input FPD_Validator.
		// Param[out]: item		    Get the next feed back item.
		// Return:    void.
		// Remarks:  Get the next feed back item.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
		//************************************
		static void NextFeedbackItem(FPD_Validator validator, FPD_ValidatorFeedbackItem* item);
	};

	class CFPD_OprHandler : public IPDF_OprCallback
	{
	public:
		CFPD_OprHandler(FPD_OprerateCallbacks callbacks);
		virtual FX_BOOL ReloadPage(FX_INT32 nPageIndex);
		virtual FX_BOOL RebuildStructTree(CPDF_StructTree* pStructTree);

		FPD_OprerateCallbacksRec m_callbacks;
	};

	class CFPD_OprCallback_V17
	{
	public:
		static FPD_OprCallback Create(FPD_OprerateCallbacks callbacks);
		static void Destroy(FPD_OprCallback opr);
	};

	class CFPD_Fix_V17
	{
	public:
		static FPD_Fix Create(FPD_Document pDocument, FPD_RuleSet pFixRSet);
		static void Destroy(FPD_Fix fix);
		static void	EnableAllPages(FPD_Fix fix);
		static void	EnablePage(FPD_Fix fix, FPD_Object pPageDict, FPD_Page pPreParsed);
		static FPD_ProgressiveStatus Start(FPD_Fix fix, FPD_OprCallback pResutCallback);
		static FPD_ProgressiveStatus Continue(FPD_Fix fix, FPD_ProgressHandler pCallback);
		static FPD_ValidatorFeedbackItem  NextFeedbackItem(FPD_Fix fix);
	};

	class CFPD_ValidatorFeedbackItemRoleMap_V17
	{
	public:
		static FPD_ValidatorFeedbackItem_RoleMap Create();
		static void Destroy(FPD_ValidatorFeedbackItem_RoleMap roleMap);
		static void GetRoles(FPD_ValidatorFeedbackItem_RoleMap roleMap, FS_ByteStringArray* outArray);
		static void SetRoles(FPD_ValidatorFeedbackItem_RoleMap roleMap, FS_ByteStringArray roleArray);
		static FPD_ValidatorFeedbackItem CastToValidatorFeedbackItem(FPD_ValidatorFeedbackItem_RoleMap roleMap);
	};

	class CFPD_ValidatorFeedbackItemMarkInfo_V17
	{
	public:
		static FPD_ValidatorFeedbackItem_MarkInfo Create();
		static void Destroy(FPD_ValidatorFeedbackItem_MarkInfo info);
		static void GetRoles(FPD_ValidatorFeedbackItem_MarkInfo info, FS_ByteString* key);
		static void SetRoles(FPD_ValidatorFeedbackItem_MarkInfo info, FS_LPCSTR key);
		static FPD_ValidatorFeedbackItem CastToValidatorFeedbackItem(FPD_ValidatorFeedbackItem_MarkInfo info);
	};


#ifdef __cplusplus
};
#endif

#endif
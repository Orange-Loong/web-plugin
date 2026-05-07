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
/* LRContext HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLRContextCreatePageContext
 * @details Create page context.
 * @param[in]  pPage The input FPD_Page object.
 * @return   FPD_LR_Context    Create page context.
 * @note 
 */
INTERFACE(FPD_LR_Context, FPDLRContextCreatePageContext, (FPD_Page pPage))

/**
 * @brief FPDLRContextContinue
 * @details Start processing elements.
 * @param[in]  context The input FPD_LR_Context object.
 * @param[in]  pPause Simple pause interface.
 * @return   void
 * @note 
 */
INTERFACE(FPD_ProgressiveStatus, FPDLRContextContinue, (FPD_LR_Context context,  FS_PauseHandler pPause))

/**
 * @brief FPDLRContextRelease
 * @details Destroy this context.
 * @param[in]  context The input FPD_LR_Context object.
 * @return   void
 * @note The structure tree should be retrieved by GetRootElement()
	* and destroyed separately by ReleaseStructureTree().
 */
INTERFACE(void, FPDLRContextRelease, (FPD_LR_Context context))

/**
 * @brief FPDLRContextGetRootElement
 * @details Retrieve pointer to the root element of the structure tree when successful.
 * @param[in]  context The input FPD_LR_Context object.
 * @param[out]  eleRef Get The root element.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRContextGetRootElement, (FPD_LR_Context context,  FPD_LR_StructureElementRef* eleRef))

/**
 * @brief FPDLRContextReleaseStructureTree
 * @details To release structure tree we constructed.
 * @param[in]  pRoot The root element.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRContextReleaseStructureTree, (FPD_LR_ElementRef pRoot))

/**
 * @brief FPDLRContextStart
 * @details Start initializing Context.
 * @param[in]  context The input FPD_LR_Context object.
 * @return   FPD_ProgressiveStatus   Enum value ,like done,fail,ready.
 * @note It need set FPD_LR_AnalysisOptions first. FPD_LR_AnalysisOptions get from FPDLRContextAnalysisOptions.
 */
INTERFACE(FPD_ProgressiveStatus, FPDLRContextStart, (FPD_LR_Context context))

/**
 * @brief FPDLRContextReleaseStructureTree2
 * @details To release struct element.
 * @param[in]  pRoot The input struct element.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRContextReleaseStructureTree2, (FPD_LR_StructureElementRef structEleRef))

/**
 * @brief FPDLRContextAnalysisOptions
 * @details Retrieve pointer of current page context's analysis option.
 * @param[in]  context The input FPD_LR_Context object.
 * @return   FPD_LR_AnalysisOptions
 * @note 
 */
INTERFACE(FPD_LR_AnalysisOptions, FPDLRContextAnalysisOptions, (FPD_LR_Context context))

NumOfSelector(FPDLRContext)
ENDENUM

//*****************************
/* LRStructureElementRef HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLRStructureElementRefCreate
 * @details Create struct element.
 * @return   FPD_LR_StructureElementRef    Create struct element.
 * @note 
 */
INTERFACE(FPD_LR_StructureElementRef, FPDLRStructureElementRefCreate, ())

/**
 * @brief FPDLRStructureElementRefDestroy
 * @details Release struct element.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRStructureElementRefDestroy, (FPD_LR_StructureElementRef structEleRef))

/**
 * @brief FPDLRStructureElementRefGetChildren
 * @details A function to get the child Elements of this structure element.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @param[out]  pListRef Get the child Elements of this structure element.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRStructureElementRefGetChildren, (FPD_LR_StructureElementRef structEleRef,  FPD_LR_ElementListRef* pListRef))

/**
 * @brief FPDLRStructureElementRefGetStdStructureType
 * @details A function to the get the type of structure element.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @return   FPD_LRStdStructElemType  The sequence number of type in FPDFLR_StdStructElemType.
 * @note 
 * @see FPDLRContextGetRootElement
 */
INTERFACE(FPD_LRStdStructElemType, FPDLRStructureElementRefGetStdStructureType, (FPD_LR_StructureElementRef structEleRef))

/**
 * @brief FPDLRStructureElementRefIsNull
 * @details Check element is null.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @return   FS_BOOL  The sequence number of type in FPDFLR_StdStructElemType.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FPDLRStructureElementRefIsNull, (FPD_LR_StructureElementRef structEleRef))

/**
 * @brief FPDLRStructureElementRefGetStdAttrValueFloat
 * @details To the get the value of Float type.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @param[in]  attr The attr Layout attribute type.
 * @param[in]  defvalue Default value of Layout attribute Float.
 * @param[in]  index The sequence number in array if it's a array.
 * @return   FS_BOOL  The value of Float.
 * @note 
 * @see 
 */
INTERFACE(FS_FLOAT, FPDLRStructureElementRefGetStdAttrValueFloat, (FPD_LR_StructureElementRef structEleRef,  FPDLR_StdAttr attr,  FS_FLOAT defvalue,  FS_INT32 index))

/**
 * @brief FPDLRStructureElementRefGetElementType
 * @details This is a function to get the type of element,like it's a pageobj
	 * element, structure element or TextObj element and so on.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @return   FS_DWORD  The type of element.
 * @note 
 * @see 
 */
INTERFACE(FS_DWORD, FPDLRStructureElementRefGetElementType, (FPD_LR_StructureElementRef structEleRef))

/**
 * @brief FPDLRStructureElementRefGetParentElement
 * @details To the get the parent Element of this structure element.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @param[out]  parentRef Get the parent Element of this structure element.
 * @return   FS_BOOL   TRUE: Get the parent element success.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FPDLRStructureElementRefGetParentElement, (FPD_LR_StructureElementRef structEleRef,  FPD_LR_StructureElementRef* parentRef))

/**
 * @brief FPDLRStructureElementRefAsStructureElement
 * @details Get the structure element.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @param[out]  elementRef Get the struct element.
 * @return   FS_BOOL   TRUE: Get struct element success.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FPDLRStructureElementRefAsStructureElement, (FPD_LR_StructureElementRef structEleRef,  FPD_LR_StructureElementRef* elementRef))

/**
 * @brief FPDLRStructureElementRefGetBBox
 * @details To get the bounding box of this structure element.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @param[in]  iBBoxIndex To indicate which the block used,when the page object passed many pages(eg.table).
 * @return   FS_FloatRect            Get the bounding box.
 * @note 
 * @see 
 */
INTERFACE(FS_FloatRect, FPDLRStructureElementRefGetBBox, (FPD_LR_StructureElementRef structEleRef,  FS_INT32 iBBoxIndex))

/**
 * @brief FPDLRStructureElementRefIsEqual
 * @details Compare two FPD_LR_StructureElementRef object.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @param[in]  structEleRef2 The input structEleRef2 need to compare.
 * @return   FS_BOOLEAN
 * @note 
 * @see 
 */
INTERFACE(FS_BOOLEAN, FPDLRStructureElementRefIsEqual, (FPD_LR_StructureElementRef structEleRef,  FPD_LR_StructureElementRef structEleRef2))

/**
 * @brief FPDLRStructureElementRefGetStdAttrType
 * @details To get the type of structure element.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @param[in]  attr The input layout attribute type.
 * @param[in]  length The length of an array.
 * @return   FPDLR_StdAttrValueType   The sequence number of attribute value type.
 * @note 
 * @see 
 */
INTERFACE(FPDLR_StdAttrValueType, FPDLRStructureElementRefGetStdAttrType, (FPD_LR_StructureElementRef structEleRef,  FPDLR_StdAttr attr,  FS_INT32* length))

/**
 * @brief FPDLRStructureElementRefGetStdAttrValueEnum
 * @details To get the value of Enum type.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @param[in]  attr The input layout attribute type.
 * @param[in]  defvalue Default value of Layout attribute enum.
 * @param[in]  index The sequence number in array if it's a array .
 * @return   FPDLR_StdAttrValueEnum   The layout attribute value in enumeration values.
 * @note 
 * @see 
 */
INTERFACE(FPDLR_StdAttrValueEnum, FPDLRStructureElementRefGetStdAttrValueEnum, (FPD_LR_StructureElementRef structEleRef,  FPDLR_StdAttr attr,  FPDLR_StdAttrValueEnum defvalue,  FS_INT32 index))

/**
 * @brief FPDLRStructureElementRefGetStdAttrValueInt32
 * @details To get the value of Int32 type.
 * @param[in]  structEleRef The input FPD_LR_StructureElementRef object.
 * @param[in]  attr The input layout attribute type.
 * @param[in]  defvalue Default value of Layout attribute Int32.
 * @param[in]  index The sequence number in array if it's a array .
 * @return   FS_INT32   The value of Int32.
 * @note 
 * @see 
 */
INTERFACE(FS_INT32, FPDLRStructureElementRefGetStdAttrValueInt32, (FPD_LR_StructureElementRef structEleRef,  FPDLR_StdAttr attr,  FS_INT32 defvalue,  FS_INT32 index))

NumOfSelector(FPDLRStructureElementRef)
ENDENUM

//*****************************
/* LRElementListRef HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLRElementListRefCreate
 * @details Create element of the list.
 * @return   FPD_LR_ElementListRef    Create element of the list.
 * @note 
 */
INTERFACE(FPD_LR_ElementListRef, FPDLRElementListRefCreate, ())

/**
 * @brief FPDLRElementListRefDestroy
 * @details Release element of the list.
 * @param[in]  structEleRef The input FPD_LR_ElementListRef object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRElementListRefDestroy, (FPD_LR_ElementListRef elementListRef))

/**
 * @brief FPDLRElementListRefGetSize
 * @details Get size of the element list.
 * @param[in]  elementListRef The input FPD_LR_ElementListRef object.
 * @return   FS_INT32                   The size of the list.
 * @note 
 * @see FPDLRContextGetRootElement
 */
INTERFACE(FS_INT32, FPDLRElementListRefGetSize, (FPD_LR_ElementListRef elementListRef))

/**
 * @brief FPDLRElementListRefGetAt
 * @details Get element of the list.
 * @param[in]  elementListRef The input FPD_LR_ElementListRef object.
 * @param[in]  nIndex The index of the list.
 * @param[out]  pRef Get element of the list.
 * @return   void
 * @note 
 * @see FPDLRContextGetRootElement
 */
INTERFACE(void, FPDLRElementListRefGetAt, (FPD_LR_ElementListRef elementListRef,  FS_INT32 nIndex,  FPD_LR_ElementRef* pRef))

NumOfSelector(FPDLRElementListRef)
ENDENUM

//*****************************
/* LRElementRef HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLRElementRefCreate
 * @details Create element.
 * @return   FPD_LR_ElementRef    Create element.
 * @note 
 */
INTERFACE(FPD_LR_ElementRef, FPDLRElementRefCreate, ())

/**
 * @brief FPDLRElementRefDestroy
 * @details Release element.
 * @param[in]  elementRef The input FPD_LR_ElementRef object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRElementRefDestroy, (FPD_LR_ElementRef elementRef))

/**
 * @brief FPDLRElementRefAsStructureElement
 * @details Get the structureElement.
 * @param[in]  elementRef The input FPD_LR_ElementRef object.
 * @param[out]  structref Get the structureElement.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRElementRefAsStructureElement, (FPD_LR_ElementRef elementRef,  FPD_LR_StructureElementRef* structref))

/**
 * @brief FPDLRElementRefGetElementType
 * @details This is a function to get the type of element,like it's a pageobj
	* element, structure element or TextObj element and so on.
 * @param[in]  elementRef The input FPD_LR_ElementRef object.
 * @return   FS_DWORD               Get the type of element.
 * @note 
 */
INTERFACE(FS_DWORD, FPDLRElementRefGetElementType, (FPD_LR_ElementRef elementRef))

/**
 * @brief FPDLRElementRefAsContentElement
 * @details A function to the get the ContentElement.
 * @param[in]  elementRef The input FPD_LR_ElementRef object.
 * @param[out]  contentref Get the contentElement.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRElementRefAsContentElement, (FPD_LR_ElementRef elementRef,  FPD_LR_ContentElementRef* contentref))

/**
 * @brief FPDLRElementRefLR_ISCONTENTTYPE
 * @details Check is content type.
 * @param[in]  elementType The input element type.
 * @return   FS_BOOL
 * @note 
 */
INTERFACE(FS_BOOL, FPDLRElementRefLR_ISCONTENTTYPE, (FS_DWORD elementType))

/**
 * @brief FPDLRElementRefLR_IS_PAGEOBJTYPE
 * @details Check is pageobject type.
 * @param[in]  elementType The input element type.
 * @return   FS_BOOL
 * @note 
 */
INTERFACE(FS_BOOL, FPDLRElementRefLR_IS_PAGEOBJTYPE, (FS_DWORD elemType))

/**
 * @brief FPDLRElementRefLR_IS_STRUCTURETYPE
 * @details Check is structure type.
 * @param[in]  elementType The input element type.
 * @return   FS_BOOL
 * @note 
 */
INTERFACE(FS_BOOL, FPDLRElementRefLR_IS_STRUCTURETYPE, (FS_DWORD elemType))

NumOfSelector(FPDLRElementRef)
ENDENUM

//*****************************
/* LRContentElementRef HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLRContentElementRefCreate
 * @details Create struct element.
 * @return   FPD_LR_ContentElementRef    Create content element.
 * @note 
 */
INTERFACE(FPD_LR_ContentElementRef, FPDLRContentElementRefCreate, ())

/**
 * @brief FPDLRContentElementRefDestroy
 * @details Release content element.
 * @param[in]  contentEleRef The input FPD_LR_ContentElementRef object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRContentElementRefDestroy, (FPD_LR_ContentElementRef contentEleRef))

/**
 * @brief FPDLRContentElementRefGetPageObjectElement
 * @details The function to the get the page object Element of this Content element.
 * @param[in]  contentEleRef The input FPD_LR_ContentElementRef object.
 * @param[out]  pageobjEleObj Get the page object Element of this Content element.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRContentElementRefGetPageObjectElement, (FPD_LR_ContentElementRef contentEleRef,  FPD_LR_PageObjectElementRef* pageobjEleObj))

/**
 * @brief FPDLRContentElementRefGetPageObjectRange
 * @details The function to get the range of page object.
 * @param[in]  contentEleRef The input FPD_LR_ContentElementRef object.
 * @param[out]  nStartPos Get start position of this content element in this page object.
 * @param[out]  nLength Get the size of page object we need.
 * @return   FS_BOOLEAN                  Whether this function get the range of page object.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRContentElementRefGetPageObjectRange, (FPD_LR_ContentElementRef contentEleRef,  FS_INT32* nStartPos,  FS_INT32* nLength))

/**
 * @brief FPDLRContentElementRefGetBBox
 * @details The function to get the bounding box of this Content element.
 * @param[in]  contentEleRef The input FPD_LR_ContentElementRef object.
 * @param[out]  rcBBox Get the bounding box.
 * @param[in]  bTransformed Whether need switch to the page's coordinate.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRContentElementRefGetBBox, (FPD_LR_ContentElementRef contentEleRef,  FS_FloatRect* rcBBox,  FS_BOOLEAN bTransformed))

/**
 * @brief FPDLRContentElementRefGetElementType
 * @details This is a function to get the type of element,like it's a pageobj
	* element, structure element or TextObj element and so on.
 * @param[in]  contentEleRef The input FPD_LR_ContentElementRef object.
 * @return   FS_DWORD   return the type of element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0
 */
INTERFACE(FS_DWORD, FPDLRContentElementRefGetElementType, (FPD_LR_ContentElementRef contentEleRef))

NumOfSelector(FPDLRContentElementRef)
ENDENUM

//*****************************
/* LRPageObjectElementRef HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLRPageObjectElementRefCreate
 * @details Create Page Object element.
 * @return   FPD_LR_PageObjectElementRef    Create Page Object element.
 * @note 
 */
INTERFACE(FPD_LR_PageObjectElementRef, FPDLRPageObjectElementRefCreate, ())

/**
 * @brief FPDLRPageObjectElementRefDestroy
 * @details Release Page Object element.
 * @param[in]  pageobjectEleRef The input FPD_LR_PageObjectElementRef object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRPageObjectElementRefDestroy, (FPD_LR_PageObjectElementRef pageobjectEleRef))

/**
 * @brief FPDLRPageObjectElementRefGetBBox
 * @details The function to get the bounding box of this Page Object element.
 * @param[in]  pageobjectEleRef The input FPD_LR_PageObjectElementRef object.
 * @param[out]  rcBBox Get the bounding box.
 * @param[in]  bTransformed Whether need switch to the page's coordinate.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRPageObjectElementRefGetBBox, (FPD_LR_PageObjectElementRef pageobjectEleRef,  FS_FloatRect* rcBBox,  FS_BOOLEAN bTransformed))

/**
 * @brief FPDLRPageObjectElementRefGetDict
 * @details The function to the get the annot or xobject dictionary of this page object.
 * @param[in]  pageobjectEleRef The input FPD_LR_PageObjectElementRef object.
 * @return   FPD_Object                  Get the dictionary or dictionary of stream.
 * @note 
 */
INTERFACE(FPD_Object, FPDLRPageObjectElementRefGetDict, (FPD_LR_PageObjectElementRef pageobjectEleRef))

/**
 * @brief FPDLRPageObjectElementRefGetPageObject
 * @details The function to to the get the page object of this Page Object element.
 * @param[in]  pageobjectEleRef The input FPD_LR_PageObjectElementRef object.
 * @return   FPD_PageObject              Get the Page Object of this Page Object element.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDLRPageObjectElementRefGetPageObject, (FPD_LR_PageObjectElementRef pageobjectEleRef))

/**
 * @brief FPDLRPageObjectElementRefGetElementType
 * @details This is a function to get the type of element,like it's a pageobj
	* element, structure element or TextObj element and so on.
 * @param[in]  pageobjectEleRef The input FPD_LR_PageObjectElementRef object.
 * @return   FS_DWORD              return the type of element. Like FPDLR_ET_TextObject.
 * @note 
 */
INTERFACE(FS_DWORD, FPDLRPageObjectElementRefGetElementType, (FPD_LR_PageObjectElementRef pageobjectEleRef))

/**
 * @brief FPDLRPageObjectElementRefGetParentPageObject
 * @details Get the parent Element of this Page Object element.
 * @param[in]  pageobjectEleRef The input FPD_LR_PageObjectElementRef object.
 * @param[out]  outParentPageObj Get the parent Element of this Page Object element.
 * @return   FS_BOOL     TRUE: Get the parent page object success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0
 */
INTERFACE(FS_BOOL, FPDLRPageObjectElementRefGetParentPageObject, (FPD_LR_PageObjectElementRef pageobjectEleRef,  FPD_LR_PageObjectElementRef* outParentPageObj))

NumOfSelector(FPDLRPageObjectElementRef)
ENDENUM

//*****************************
/* LRParseOptions HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLRParseOptionsCreate
 * @details Create FPD_LR_ParseOptions.
 * @return   FPD_LR_ParseOptions    Create FPD_LR_ParseOptions.
 * @note 
 */
INTERFACE(FPD_LR_ParseOptions, FPDLRParseOptionsCreate, ())

/**
 * @brief FPDLRParseOptionsDelete
 * @details Delete FPD_LR_ParseOptions.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsDelete, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsGetRecognizeDivision
 * @details To indicate whether use division.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_BOOLEAN
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRParseOptionsGetRecognizeDivision, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetRecognizeDivision
 * @details To indicate whether use division.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  bRecognize Whether use division.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetRecognizeDivision, (FPD_LR_ParseOptions option,  FS_BOOLEAN bRecognize))

/**
 * @brief FPDLRParseOptionsGetLRVersion
 * @details To indicate the LR version used.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_INT32
 * @note 
 */
INTERFACE(FS_INT32, FPDLRParseOptionsGetLRVersion, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetLRVersion
 * @details To indicate the LR version used.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  version The input LR version.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetLRVersion, (FPD_LR_ParseOptions option,  FS_INT32 version))

/**
 * @brief FPDLRParseOptionsGetProfile
 * @details To select the LR analysis method.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_DWORD
 * @note 
 */
INTERFACE(FS_DWORD, FPDLRParseOptionsGetProfile, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetProfile
 * @details To select the LR analysis method.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  profile The input LR analysis method.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetProfile, (FPD_LR_ParseOptions option,  FS_DWORD profile))

/**
 * @brief FPDLRParseOptionsGetUsePageMatrix
 * @details To indicate whether use PageMatrix.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_BOOLEAN
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRParseOptionsGetUsePageMatrix, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetUsePageMatrix
 * @details To indicate whether use PageMatrix.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  bUsePageMatrix The input if use PageMatrix.
 * @return   FS_BOOLEAN
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetUsePageMatrix, (FPD_LR_ParseOptions option,  FS_BOOLEAN bUsePageMatrix))

/**
 * @brief FPDLRParseOptionsGetOCContext
 * @details To indicate OC context.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FPD_OCContext
 * @note 
 */
INTERFACE(FPD_OCContext, FPDLRParseOptionsGetOCContext, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetOCContext
 * @details To indicate OC context.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  pOCContext The input OC context.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetOCContext, (FPD_LR_ParseOptions option,  FPD_OCContext pOCContext))

/**
 * @brief FPDLRParseOptionsGetSelectionRect
 * @details To indicate the selection rect.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_FloatRect
 * @note 
 */
INTERFACE(FS_FloatRect, FPDLRParseOptionsGetSelectionRect, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetSelectionRect
 * @details To indicate the selection rect.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  rect The input selection rect.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetSelectionRect, (FPD_LR_ParseOptions option,  FS_FloatRect rect))

/**
 * @brief FPDLRParseOptionsGetRecognizeFontConservatively
 * @details To indicate whether recognize font conservatively.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_BOOLEAN
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRParseOptionsGetRecognizeFontConservatively, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetRecognizeFontConservatively
 * @details To indicate whether recognize font conservatively.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  bRecognize The input whether recognize font conservatively.
 * @return   FS_BOOLEAN
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetRecognizeFontConservatively, (FPD_LR_ParseOptions option,  FS_BOOLEAN bRecognize))

/**
 * @brief FPDLRParseOptionsGetEnableLayoutAnalyze
 * @details To indicate whether enable layout analyze.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_BOOLEAN
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRParseOptionsGetEnableLayoutAnalyze, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetEnableLayoutAnalyze
 * @details To indicate whether enable layout analyze.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  bEnableLayout The input whether recognize font conservatively.
 * @return   FS_BOOLEAN
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetEnableLayoutAnalyze, (FPD_LR_ParseOptions option,  FS_BOOLEAN bEnableLayout))

/**
 * @brief FPDLRParseOptionsGetEnableTableContainsFloat
 * @details To indicate whether enable table contains float.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_BOOLEAN
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRParseOptionsGetEnableTableContainsFloat, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetEnableTableContainsFloat
 * @details To indicate whether enable table contains float.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  bEnable The input whether enable table contains float.
 * @return   FS_BOOLEAN
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetEnableTableContainsFloat, (FPD_LR_ParseOptions option,  FS_BOOLEAN bEnable))

/**
 * @brief FPDLRParseOptionsGetKeepContainerConsistency
 * @details To indicate whether keep container consistency.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_BOOLEAN
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRParseOptionsGetKeepContainerConsistency, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetKeepContainerConsistency
 * @details To indicate whether keep container consistency.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  bKeep The input  whether keep container consistency.
 * @return   FS_BOOLEAN
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetKeepContainerConsistency, (FPD_LR_ParseOptions option,  FS_BOOLEAN bKeep))

/**
 * @brief FPDLRParseOptionsGetNNCfgName
 * @details To indicate NNC name.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_LPCSTR
 * @note 
 */
INTERFACE(FS_LPCSTR, FPDLRParseOptionsGetNNCfgName, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetNNCfgName
 * @details To indicate NNC name.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  name The input  NNC name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetNNCfgName, (FPD_LR_ParseOptions option,  FS_LPCSTR name))

/**
 * @brief FPDLRParseOptionsGetNNWeightsName
 * @details To indicate NNC weight name.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_LPCSTR
 * @note 
 */
INTERFACE(FS_LPCSTR, FPDLRParseOptionsGetNNWeightsName, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetNNWeightsName
 * @details To indicate NNC weight name.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  name The input NNC weight name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetNNWeightsName, (FPD_LR_ParseOptions option,  FS_LPCSTR name))

/**
 * @brief FPDLRParseOptionsGetNNConfidenceLevel
 * @details To indicate confidence level.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @return   FS_FLOAT
 * @note 
 */
INTERFACE(FS_FLOAT, FPDLRParseOptionsGetNNConfidenceLevel, (FPD_LR_ParseOptions option))

/**
 * @brief FPDLRParseOptionsSetNNConfidenceLevel
 * @details To indicate confidence level.
 * @param[in]  option The input FPD_LR_ParseOptions object.
 * @param[in]  level The input confidence level.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLRParseOptionsSetNNConfidenceLevel, (FPD_LR_ParseOptions option,  FS_FLOAT level))

NumOfSelector(FPDLRParseOptions)
ENDENUM

//----------_V17----------
//*****************************
/* LRAnalysisOptions HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLRAnalysisOptionsSetOptionString
 * @details Set option string.
 * @param[in]  option The input FPD_LR_AnalysisOptions.
 * @param[in]  sName The input setting name.
 * @param[in]  sInput The input setting value.
 * @return   FS_BOOLEAN    true: set success.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRAnalysisOptionsSetOptionString, (FPD_LR_AnalysisOptions option,  FS_LPCSTR sName,  FS_LPCSTR sInput))

/**
 * @brief FPDLRAnalysisOptionsGetSupportedOptions
 * @details Get supperted options.
 * @param[in]  option The input FPD_LR_AnalysisOptions.
 * @param[in\out]  rgOptions Get supperted options.
 * @return   FS_INT32    The count of supperted options.
 * @note 
 */
INTERFACE(FS_INT32, FPDLRAnalysisOptionsGetSupportedOptions, (FPD_LR_AnalysisOptions option,  FS_ByteStringArray* rgOptions))

/**
 * @brief FPDLRAnalysisOptionsSetOptionInteger
 * @details Set option integer value.
 * @param[in]  option The input FPD_LR_AnalysisOptions.
 * @param[in]  sName The input setting name.
 * @param[in]  sInput The input setting value.
 * @return   FS_BOOLEAN    true: set success.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRAnalysisOptionsSetOptionInteger, (FPD_LR_AnalysisOptions option,  FS_LPCSTR sName,  FS_INT32 nInput))

/**
 * @brief FPDLRAnalysisOptionsSetOptionFloat
 * @details Set option float value.
 * @param[in]  option The input FPD_LR_AnalysisOptions.
 * @param[in]  sName The input setting name.
 * @param[in]  fInput The input setting value.
 * @return   FS_BOOLEAN    true: set success.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRAnalysisOptionsSetOptionFloat, (FPD_LR_AnalysisOptions option,  FS_LPCSTR sName,  FS_FLOAT fInput))

/**
 * @brief FPDLRAnalysisOptionsSetOptionBoolean
 * @details Set option boolean value.
 * @param[in]  option The input FPD_LR_AnalysisOptions.
 * @param[in]  sName The input setting name.
 * @param[in]  bInput The input setting value.
 * @return   FS_BOOLEAN    true: set success.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRAnalysisOptionsSetOptionBoolean, (FPD_LR_AnalysisOptions option,  FS_LPCSTR sName,  FS_BOOLEAN bInput))

/**
 * @brief FPDLRAnalysisOptionsSetOptionFloatRect
 * @details Set option rect value.
 * @param[in]  option The input FPD_LR_AnalysisOptions.
 * @param[in]  sName The input setting name.
 * @param[in]  rcInput The input setting value.
 * @return   FS_BOOLEAN    true: set success.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRAnalysisOptionsSetOptionFloatRect, (FPD_LR_AnalysisOptions option,  FS_LPCSTR sName,  FS_FloatRect rcInput))

/**
 * @brief FPDLRAnalysisOptionsSetOptionOCContext
 * @details Set option OC context value.
 * @param[in]  option The input FPD_LR_AnalysisOptions.
 * @param[in]  sName The input setting name.
 * @param[in]  pInput The input setting value.
 * @return   FS_BOOLEAN    true: set success.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDLRAnalysisOptionsSetOptionOCContext, (FPD_LR_AnalysisOptions option,  FS_LPCSTR sName,  FPD_OCContext pInput))

NumOfSelector(FPDLRAnalysisOptions)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

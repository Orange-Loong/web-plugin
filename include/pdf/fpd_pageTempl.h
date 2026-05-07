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
//*****************************
/* Page HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDPageNew
 * @details Creates a new empty PDF page.
 * @param[in]  void 
 * @return   A new empty PDF page.
 * @note 
 */
INTERFACE(FPD_Page, FPDPageNew, (void))

/**
 * @brief FPDPageDestroy
 * @details Destroys the PDF page.
 * @param[in]  page The input PDF page.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageDestroy, (FPD_Page page))

/**
 * @brief FPDPageContinueParse
 * @details Continue parsing.
 * @param[in]  page The input PDF page.
 * @param[in]  pauseHandler The user-supplied pause handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageContinueParse, (FPD_Page page,  FS_PauseHandler pauseHandler))

/**
 * @brief FPDPageGetParseState
 * @details Gets the current parsing state.
 * @param[in]  page The input PDF page.
 * @return   The current parsing state:
	*            <ul><li>FPD_CONTENT_NOT_PARSED</li>
    *            <li>FPD_CONTENT_PARSING</li>
    *            <li>FPD_CONTENT_PARSED</li></ul>
 * @note 
 */
INTERFACE(FS_INT32, FPDPageGetParseState, (FPD_Page page))

/**
 * @brief FPDPageIsParsed
 * @details Checks whether the content has been parsed into page objects.
 * @param[in]  page The input PDF page.
 * @return   <a>TRUE</a> if the content has been parsed into page objects, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDPageIsParsed, (FPD_Page page))

/**
 * @brief FPDPageEstimateParseProgress
 * @details Estimates the percentage of parse progress.
 * @param[in]  page The input PDF page.
 * @return   The percentage of parse progress.
 * @note 
 */
INTERFACE(FS_INT32, FPDPageEstimateParseProgress, (FPD_Page page))

/**
 * @brief FPDPageGetFirstObjectPosition
 * @details Gets the position of the first page object.
 * @param[in]  page The input PDF page.
 * @return   The position of the first page object.
 * @note 
 */
INTERFACE(FS_POSITION, FPDPageGetFirstObjectPosition, (FPD_Page page))

/**
 * @brief FPDPageGetLastObjectPosition
 * @details Gets the position of the last page object
 * @param[in]  page The input PDF page.
 * @return   The position of the last page object
 * @note 
 */
INTERFACE(FS_POSITION, FPDPageGetLastObjectPosition, (FPD_Page page))

/**
 * @brief FPDPageGetNextObject
 * @details Gets the current object and moves to next position.
 * @param[in]  page The input PDF page.
 * @param[in,out]  inOutPos The input current position, and receives the next position.
 * @return   A page object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDPageGetNextObject, (FPD_Page page,  FS_POSITION* inOutPos))

/**
 * @brief FPDPageGetPrevObject
 * @details Gets the current object and moves to previous position
 * @param[in]  page The input PDF page.
 * @param[in,out]  inOutPos The input current position, and receives the previous position.
 * @return   A page object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDPageGetPrevObject, (FPD_Page page,  FS_POSITION* inOutPos))

/**
 * @brief FPDPageGetObjectAt
 * @details Gets an object at specified position.
 * @param[in]  page The input PDF page.
 * @param[in]  pos Specifies the position of the page object.
 * @return   A page object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDPageGetObjectAt, (FPD_Page page,  FS_POSITION pos))

/**
 * @brief FPDPageCountObjects
 * @details Gets the count of page objects in the collection.
 * @param[in]  page The input PDF page.
 * @return   The count of page objects in the collection.
 * @note 
 */
INTERFACE(FS_DWORD, FPDPageCountObjects, (FPD_Page page))

/**
 * @brief FPDPageGetObjectIndex
 * @details Gets the zero-based page object index in the object array.
 * @param[in]  page The input PDF page.
 * @param[in]  obj The input page object.
 * @return   The zero-based index of the page object.
 * @note 
 */
INTERFACE(FS_INT32, FPDPageGetObjectIndex, (FPD_Page page,  FPD_PageObject obj))

/**
 * @brief FPDPageGetObjectByIndex
 * @details Gets an object by a zero-based page object index.
 * @param[in]  page The input PDF page.
 * @param[in]  index Specifies the zero-based index of the page object.
 * @return   A page object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDPageGetObjectByIndex, (FPD_Page page,  FS_INT32 index))

/**
 * @brief FPDPageReplaceObject
 * @details Replaces a page object with a new page object.
 * @param[in]  page The input PDF page.
 * @param[in]  pos Specifies the position of the page object to be replaced.
 * @param[in]  newObj The input new page object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageReplaceObject, (FPD_Page page,  FS_POSITION pos,  FPD_PageObject newObj))

/**
 * @brief FPDPageInsertObject
 * @details Inserts a page object. To insert before all objects, use NULL for <param>posInsertAfter</param>.
 * @param[in]  page The input PDF page.
 * @param[in]  posInsertAfter Specifies the position to insert after.
 * @param[in]  newObj The input new page object.
 * @return   The position of inserted page object
 * @note 
 */
INTERFACE(FS_POSITION, FPDPageInsertObject, (FPD_Page page,  FS_POSITION posInsertAfter,  FPD_PageObject newObj))

/**
 * @brief FPDPageRemoveObject
 * @details Removes a page object.
 * @param[in]  page The input PDF page.
 * @param[in]  pos Specifies the position of the page object to be removed.
 * @return   
 * @note 
 */
INTERFACE(void, FPDPageRemoveObject, (FPD_Page page,  FS_POSITION pos))

/**
 * @brief FPDPageMoveObject
 * @details Moves a page object from a position to another position.
 * @param[in]  page The input PDF page.
 * @param[in]  pos The original position of the page object.
 * @param[in]  newPosAfter The new position to move after.
 * @return   The new position of the page object.
 * @note 
 */
INTERFACE(FS_POSITION, FPDPageMoveObject, (FPD_Page page,  FS_POSITION pos,  FS_POSITION newPosAfter))

/**
 * @brief FPDPageDebugOutput
 * @details Outputs debug information. For debug only: list all page objects.
 * @param[in]  page The input PDF page.
 * @param[in]  szFileName The input file name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageDebugOutput, (FPD_Page page,  FS_LPSTR szFileName))

/**
 * @brief FPDPageTransform
 * @details Transforms all objects.
 * @param[in]  page The input PDF page.
 * @param[in]  matrix The input transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageTransform, (FPD_Page page,  FS_AffineMatrix matrix))

/**
 * @brief FPDPageBackgroundAlphaNeeded
 * @details Checks whether this object list needs background alpha channel to render.
 * @param[in]  page The input PDF page.
 * @return   <a>TRUE</a> for this object list needing background alpha channel to render.
 * @note If it's TRUE, then the application should better use ARGB device to render it,
	*           otherwise the objects may need more time to render.
	*           Please call this function after the page has been parsed.
 */
INTERFACE(FS_BOOL, FPDPageBackgroundAlphaNeeded, (FPD_Page page))

/**
 * @brief FPDPageCalcBoundingBox
 * @details Calculates the bounding box of all page objects in the collection.
 * @param[in]  page The input PDF page.
 * @return   The bounding box of all page objects in the collection.
 * @note 
 */
INTERFACE(FS_FloatRect, FPDPageCalcBoundingBox, (FPD_Page page))

/**
 * @brief FPDPageGetDict
 * @details Gets the page dictionary.
 * @param[in]  page The input PDF page.
 * @return   The page dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDPageGetDict, (FPD_Page page))

/**
 * @brief FPDPageGetDocument
 * @details Gets the PDF document.
 * @param[in]  page The input PDF page.
 * @return   The PDF document.
 * @note 
 */
INTERFACE(FPD_Document, FPDPageGetDocument, (FPD_Page page))

/**
 * @brief FPDPageRealizeResource
 * @details Adds a resource to current object list. Returns the resource name.
 * @param[in]  page The input PDF page.
 * @param[in]  pageResObj The input resource object
 * @param[in]  objMapping The input object mapping from object number to object pointer.
 * @param[in]  szType The resource type name.
 * @param[out]  outResObj It receives the result resource object.
 * @param[out]  outResName It receives the resource name.
 * @return   void
 * @note Will try to use an existing resource first, if available.
	*            Caller should not release the result resource object, which may be same as the input object.
	*            The input object can be an external object (which comes from another document, or archive),
	*            in this case, the object mapping should be specified.
 */
INTERFACE(void, FPDPageRealizeResource, (FPD_Page page,  FPD_Object pageResObj,  FS_MapPtrToPtr objMapping,  FS_LPSTR szType,  FPD_Object* outResObj,  FS_ByteString* outResName))

/**
 * @brief FPDPageFindCSName
 * @details Finds a resource name of specified color space.
 * @param[in]  page The input PDF page.
 * @param[in]  cs The input color space.
 * @param[out]  outResName It receive the resource name of the color space.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageFindCSName, (FPD_Page page,  FPD_ColorSpace cs,  FS_ByteString* outResName))

/**
 * @brief FPDPageFindFontName
 * @details Finds a resource name of specified font.
 * @param[in]  page The input PDF page.
 * @param[in]  font The input font.
 * @param[out]  outResName It receive the resource name of the font.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageFindFontName, (FPD_Page page,  FPD_Font font,  FS_ByteString* outResName))

/**
 * @brief FPDPageLoad
 * @details Constructs a page. For saving memory, the page caching feature can be disabled, then
	*           images and masks used in page rendering won't be cached. Of course this will affect the speed.
 * @param[in]  page The input PDF page.
 * @param[in]  doc The PDF document
 * @param[in]  pageDict The page dictionary.
 * @param[in]  bPageCache Whether images and masks used in page rendering will be cached or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageLoad, (FPD_Page page,  FPD_Document doc,  FPD_Object pageDict,  FS_BOOL bPageCache))

/**
 * @brief FPDPageStartParse
 * @details Start parsing the page. If pausing is enabled, application should check current parsing state
	*           after this function returns. If parsing not finished, ContinueParse() should be called.
 * @param[in]  page The input PDF page.
 * @param[in]  options The parser options.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageStartParse, (FPD_Page page,  FPD_ParseOptions options))

/**
 * @brief FPDPageParseContent
 * @details Parses all contents.
 * @param[in]  page The input PDF page.
 * @param[in]  options The parser options.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageParseContent, (FPD_Page page,  FPD_ParseOptions options))

/**
 * @brief FPDPageGetDisplayMatrix
 * @details Builds a matrix from PDF user space to targeted device space, according to metrics info
	*           (top-left position and widht-height size) provided in device space.
 * @param[in]  page The input PDF page.
 * @param[in]  xPos The x-coordinate of the top-left position in the device space.
 * @param[in]  yPos The y-coordinate of the top-left position in the device space.
 * @param[in]  xSize The x-direction size in the device space.
 * @param[in]  ySize The y-direction size in the device space.
 * @param[in]  iRotate The rotation degrees.
 * @return   The transformation matrix from PDF user space to targeted device space.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FPDPageGetDisplayMatrix, (FPD_Page page,  FS_INT32 xPos,  FS_INT32 yPos,  FS_INT32 xSize,  FS_INT32 ySize,  FS_INT32 iRotate))

/**
 * @brief FPDPageGetPageWidth
 * @details Gets the page width in user space.
 * @param[in]  page The input PDF page.
 * @return   The page width in user space.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDPageGetPageWidth, (FPD_Page page))

/**
 * @brief FPDPageGetPageHeight
 * @details Gets the page height in user space.
 * @param[in]  page The input PDF page.
 * @return   The page height in user space.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDPageGetPageHeight, (FPD_Page page))

/**
 * @brief FPDPageGetPageBBox
 * @details Gets the page bounding box in user space.
 * @param[in]  page The input PDF page.
 * @return   The page bounding box in user space.
 * @note 
 */
INTERFACE(FS_FloatRect, FPDPageGetPageBBox, (FPD_Page page))

/**
 * @brief FPDPageGetPageMatrix
 * @details Gets the page matrix.
 * @param[in]  page The input PDF page.
 * @return   The page matrix.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FPDPageGetPageMatrix, (FPD_Page page))

/**
 * @brief FPDPageGetPageAttr
 * @details Gets an inheritable attribute value.
 * @param[in]  page The input PDF page.
 * @param[in]  szName The attribute(entry) name
 * @return   The attribute value
 * @note 
 */
INTERFACE(FPD_Object, FPDPageGetPageAttr, (FPD_Page page,  FS_LPSTR szName))

/**
 * @brief FPDPageGetRenderCache
 * @details Gets render cache. for RENDER module.
 * @param[in]  page The input PDF page.
 * @return   The render cache. for RENDER module.
 * @note 
 */
INTERFACE(FPD_PageRenderCache, FPDPageGetRenderCache, (FPD_Page page))

/**
 * @brief FPDPageClearRenderCache
 * @details Clears render cache.
 * @param[in]  page The input PDF page.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageClearRenderCache, (FPD_Page page))

/**
 * @brief FPDPageGenerateContent
 * @details Replaces the page content stream.
 * @param[in]  page The input PDF page.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageGenerateContent, (FPD_Page page))

/**
 * @brief FPDPageGetPageText
 * @details Extracts pure text from a page, in appearance order.
 * @param[out]  outLines It receives the text lines.
 * @param[in]  doc The input PDF document.
 * @param[in]  pageDic The input PDF page.
 * @param[in]  iMinWidth The input minimum width of the text.
 * @param[in]  flags The input OS text extracting flags.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageGetPageText, (FS_ByteStringArray* outLines,  FPD_Document doc,  FPD_Object pageDic,  FS_INT32 iMinWidth,  FS_DWORD flags))

/**
 * @brief FPDPageGetPageText_Unicode
 * @details Extracts Unicode pure text from a page, in appearance order.
 * @param[out]  outLines It receives the text lines.
 * @param[in]  doc The input PDF document.
 * @param[in]  pageDic The input PDF page.
 * @param[in]  iMinWidth The input minimum width of the text.
 * @param[in]  flags The input OS text extracting flags.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageGetPageText_Unicode, (FS_WideStringArray* outLines,  FPD_Document doc,  FPD_Object pageDic,  FS_INT32 iMinWidth,  FS_DWORD flags))

/**
 * @brief FPDPageNewContentGenerator
 * @details Creates the PDF page content generator.
 * @param[in]  page The input PDF page.
 * @return   The PDF page content generator.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FPDPageDestroyContentGenerator
 */
INTERFACE(FPD_ContentGenerator, FPDPageNewContentGenerator, (FPD_Page page))

/**
 * @brief FPDPageDestroyContentGenerator
 * @details Destroys the PDF page content generator.
 * @param[in]  generator The input PDF content generator.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDPageDestroyContentGenerator, (FPD_ContentGenerator generator))

/**
 * @brief FPDPageStartGenerateContent
 * @details Starts to generate the PDF content progressively.
 * @param[in]  generator The input PDF content generator.
 * @param[in]  fileStream The input file stream object. Sets it NULL as default.
 * @return   TRUE for success, otherwise not.
 * @note It has been deprecated. Suggest use FPDPageContinueGenerateContent2.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FPDPageContinueGenerateContent
 */
INTERFACE(FS_BOOL, FPDPageStartGenerateContent, (FPD_ContentGenerator generator,  FS_FileStream fileStream))

/**
 * @brief FPDPageContinueGenerateContent
 * @details Continues to generate the PDF content progressively.
 * @param[in]  generator The input PDF content generator.
 * @param[in]  pause The input pause handler. Creates the pause handler by <a>FSPauseHandlerCreate</a>. Sets it NULL as default.
 * @return   The status of generating PDF page content progressively.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FPD_ProgressiveStatus, FPDPageContinueGenerateContent, (FPD_ContentGenerator generator,  FS_PauseHandler pause))

/**
 * @brief FPDPageGetResourcesDictionary
 * @details Gets the PDF page resources dictionary.
 * @param[in]  page The input PDF page.
 * @return   The PDF page resources dictionary.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FPD_Object, FPDPageGetResourcesDictionary, (FPD_Page page))

/**
 * @brief FPDPageSetResourcesDictionary
 * @details Sets the PDF page resources dictionary.
 * @param[in]  page The input PDF page.
 * @param[in]  resourcesDict The input PDF page resources dictionary.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FPDPageSetResourcesDictionary, (FPD_Page page,  FPD_Object resourcesDict))

/**
 * @brief FPDPageStartGenerateContent2
 * @details Starts to generate the PDF content progressively.
 * @param[in]  generator The input PDF content generator.
 * @return   TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FPDPageContinueGenerateContent
 */
INTERFACE(FS_BOOL, FPDPageStartGenerateContent2, (FPD_ContentGenerator generator))

/**
 * @brief FPDPageGetPageRotation
 * @details Get rotation of the page.
 * @param[in]  page The input PDF page.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_INT32, FPDPageGetPageRotation, (FPD_Page page))

/**
 * @brief FPDPageGetPageResources
 * @details Get PageResource of the page.
 * @param[in]  page The input PDF page.
 * @return   FPD_Object.The page resources dictionaries inheritable
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FPD_Object, FPDPageGetPageResources, (FPD_Page page))

/**
 * @brief FPDPageGetPageBleedBox
 * @details Get the page bounding box in user space.
 * @param[in]  page The input PDF page.
 * @return   FS_FloatRect. Get the page bounding box in user space.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_FloatRect, FPDPageGetPageBleedBox, (FPD_Page page))

/**
 * @brief FPDPageNew2
 * @details Construct an empty collection of graphics objects.
 * @param[in]  bReleaseMembers Whether the collection takes charge of releasing of graphics objects.
 * @return   FPD_Page     Construct an empty collection of graphics objects.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 * @see 
 */
INTERFACE(FPD_Page, FPDPageNew2, (FS_BOOL bReleaseMembers))

/**
 * @brief FPDPageSetFormStream
 * @details Set the form stream. For form only.
 * @param[in]  page The input PDF page object.
 * @param[in]  stream The input form stream.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDPageSetFormStream, (FPD_Page page,  FPD_Object stream))

/**
 * @brief FPDPageSetFormDict
 * @details Set the form dictionary. For form only.
 * @param[in]  page The input PDF page object.
 * @param[in]  dict The input form dictionary.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDPageSetFormDict, (FPD_Page page,  FPD_Object dict))

/**
 * @brief FPDPageCastToFPDGraphicsObjects
 * @details Convert to its parent object of FPD_GraphicsObjects.
 * @param[in]  page The input PDF form data object.
 * @return   FPD_GraphicsObjects     Convert to its parent object of FPD_GraphicsObjects.
 * @note 
 */
INTERFACE(FPD_GraphicsObjects, FPDPageCastToFPDGraphicsObjects, (FPD_Page page))

/**
 * @brief FPDPageGenerateContent2
 * @details Replaces the page content stream.
 * @param[in]  page The input PDF page.
 * @param[out]  bsContent It receives the content stream.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageGenerateContent2, (FPD_Page page,  FS_ByteString* bsContent))

NumOfSelector(FPDPage)
ENDENUM

//*****************************
/* ParseOptions HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDParseOptionsNew
 * @details Creates a new empty page parsing options object.
 * @param[in]  bTextOnly Whether only text object is parsed into object list or not.
 * @param[in]  bMarkedContent Whether load marked content (including foxit tag) information or not.
 * @param[in]  bSeparateForm Whether Generate FPD_FormObject for form or not.
 * @param[in]  bDecodeInlineImg Whether decode inline image for better performance.
	*                              This should be disabled for PDF Editor, to keep the result file size smaller.
 * @return   A new empty page parsing options object.
 * @note 
 */
INTERFACE(FPD_ParseOptions, FPDParseOptionsNew, (FS_BOOL bTextOnly,  FS_BOOL bMarkedContent,  FS_BOOL bSeparateForm,  FS_BOOL bDecodeInlineImg))

/**
 * @brief FPDParseOptionsDestroy
 * @details Destroys the page parsing options object.
 * @param[in]  opt The input page parsing options object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParseOptionsDestroy, (FPD_ParseOptions opt))

/**
 * @brief FPDParseOptionsSetTextFlag
 * @details Sets whether only text object is parsed into object list or not.
 * @param[in]  opt The input page parsing options object.
 * @param[in]  bParseTextOnly Whether only text object is parsed into object list or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParseOptionsSetTextFlag, (FPD_ParseOptions opt,  FS_BOOL bParseTextOnly))

/**
 * @brief FPDParseOptionsSetMarkedContentLoadFlag
 * @details Sets whether load marked content (including foxit tag) information or not.
 * @param[in]  opt The input page parsing options object.
 * @param[in]  bLoad Whether load marked content (including foxit tag) information or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParseOptionsSetMarkedContentLoadFlag, (FPD_ParseOptions opt,  FS_BOOL bLoad))

/**
 * @brief FPDParseOptionsSetFormGenerateFlag
 * @details Sets whether Generate FPD_FormObject for form or not.
 * @param[in]  opt The input page parsing options object.
 * @param[in]  bGernerateForm Whether Generate FPD_FormObject for form or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParseOptionsSetFormGenerateFlag, (FPD_ParseOptions opt,  FS_BOOL bGernerateForm))

/**
 * @brief FPDParseOptionsSetInlineImageDecodeFlag
 * @details Sets whether decode inline image for better performance,
	*           This should be disabled for PDF Editor, to keep the result file size smaller.
 * @param[in]  opt The input page parsing options object.
 * @param[in]  bDecodeInlineImg Whether decode inline image for better performance.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParseOptionsSetInlineImageDecodeFlag, (FPD_ParseOptions opt,  FS_BOOL bDecodeInlineImg))

NumOfSelector(FPDParseOptions)
ENDENUM

//*****************************
/* Form HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFormNew
 * @details Creates a new empty PDF form object.
 * @param[in]  doc The PDF document.
 * @param[in]  pageResources The page resources.
 * @param[in]  formStream The form stream.
 * @return   A new empty PDF form data object.
 * @note 
 */
INTERFACE(FPD_Form, FPDFormNew, (FPD_Document doc,  FPD_Object pageResources,  FPD_Object formStream))

/**
 * @brief FPDFormDestroy
 * @details Destroys the PDF form data object. If it is added into the page, it is taken over by page and don't destroy it.
 * @param[in]  form The input PDF form data object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormDestroy, (FPD_Form form))

/**
 * @brief FPDFormContinueParse
 * @details Continues parsing.
 * @param[in]  form The input PDF form data object.
 * @param[in]  pauseHandler The user-supplied pause handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormContinueParse, (FPD_Form form,  FS_PauseHandler pauseHandler))

/**
 * @brief FPDFormGetParseState
 * @details Gets the current parsing state.
 * @param[in]  form The input PDF form data object.
 * @return   The current parsing state:
	*            <ul><li>FPD_CONTENT_NOT_PARSED</li>
	*            <li>FPD_CONTENT_PARSING</li>
	*            <li>FPD_CONTENT_PARSED</li></ul>
 * @note 
 */
INTERFACE(FS_INT32, FPDFormGetParseState, (FPD_Form form))

/**
 * @brief FPDFormIsParsed
 * @details Checks whether the content has been parsed into form objects.
 * @param[in]  form The input PDF form data object.
 * @return   <a>TRUE</a> if the content has been parsed into form objects, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormIsParsed, (FPD_Form form))

/**
 * @brief FPDFormEstimateParseProgress
 * @details Estimates the percentage of parse progress.
 * @param[in]  form The input PDF form data object.
 * @return   The percentage of parse progress.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormEstimateParseProgress, (FPD_Form form))

/**
 * @brief FPDFormGetFirstObjectPosition
 * @details Gets the position of the first form object.
 * @param[in]  form The input PDF form data object.
 * @return   The position of the first form object.
 * @note 
 */
INTERFACE(FS_POSITION, FPDFormGetFirstObjectPosition, (FPD_Form form))

/**
 * @brief FPDFormGetLastObjectPosition
 * @details Gets the position of the last form object
 * @param[in]  form The input PDF form data object.
 * @return   The position of the last form object
 * @note 
 */
INTERFACE(FS_POSITION, FPDFormGetLastObjectPosition, (FPD_Form form))

/**
 * @brief FPDFormGetNextObject
 * @details Gets the current object and moves to next position.
 * @param[in]  form The input PDF form data object.
 * @param[in,out]  inOutPos The input current position, and receives the next position.
 * @return   A form object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDFormGetNextObject, (FPD_Form form,  FS_POSITION* inOutPos))

/**
 * @brief FPDFormGetPrevObject
 * @details Gets the current object and move to previous position
 * @param[in]  form The input PDF form data object.
 * @param[in,out]  inOutPos It input the current position, and receives the previous position.
 * @return   A form object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDFormGetPrevObject, (FPD_Form form,  FS_POSITION* inOutPos))

/**
 * @brief FPDFormGetObjectAt
 * @details Gets an object at specified position.
 * @param[in]  form The input PDF form data object.
 * @param[in]  pos Specifies the position of the form object.
 * @return   A form object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDFormGetObjectAt, (FPD_Form form,  FS_POSITION pos))

/**
 * @brief FPDFormCountObjects
 * @details Gets the count of form objects in the collection.
 * @param[in]  form The input PDF form data object.
 * @return   The count of form objects in the collection.
 * @note 
 */
INTERFACE(FS_DWORD, FPDFormCountObjects, (FPD_Form form))

/**
 * @brief FPDFormGetObjectIndex
 * @details Gets the zero-based form object index in the object array.
 * @param[in]  form The input PDF form data object.
 * @param[in]  obj The form object pointer.
 * @return   The zero-based index of the form object.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormGetObjectIndex, (FPD_Form form,  FPD_PageObject obj))

/**
 * @brief FPDFormGetObjectByIndex
 * @details Gets an object by a zero-based form object index.
 * @param[in]  form The input PDF form data object.
 * @param[in]  index Specifies the zero-based index of the form object.
 * @return   A form object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDFormGetObjectByIndex, (FPD_Form form,  FS_INT32 index))

/**
 * @brief FPDFormReplaceObject
 * @details Replaces a form object with a new form object.
 * @param[in]  form The input PDF form data object.
 * @param[in]  pos Specifies the position of the form object to be replaced.
 * @param[in]  newObj The input new form object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormReplaceObject, (FPD_Form form,  FS_POSITION pos,  FPD_PageObject newObj))

/**
 * @brief FPDFormInsertObject
 * @details Inserts a form object. To insert before all objects, use NULL for posInsertAfter.
 * @param[in]  form The input PDF form data object.
 * @param[in]  posInsertAfter Specifies the position to insert after.
 * @param[in]  newObj The input new form object.
 * @return   The position of inserted form object
 * @note 
 */
INTERFACE(FS_POSITION, FPDFormInsertObject, (FPD_Form form,  FS_POSITION posInsertAfter,  FPD_PageObject newObj))

/**
 * @brief FPDFormRemoveObject
 * @details Removes a form object.
 * @param[in]  form The input PDF form data object.
 * @param[in]  pos Specifies the position of the form object to be removed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormRemoveObject, (FPD_Form form,  FS_POSITION pos))

/**
 * @brief FPDFormMoveObject
 * @details Moves a form object from a position to another position.
 * @param[in]  form The input PDF form data object.
 * @param[in]  pos The original position of the form object.
 * @param[in]  newPosAfter The new position to move after.
 * @return   The new position of the form object.
 * @note 
 */
INTERFACE(FS_POSITION, FPDFormMoveObject, (FPD_Form form,  FS_POSITION pos,  FS_POSITION newPosAfter))

/**
 * @brief FPDFormDebugOutput
 * @details Outputs debug information. For debug only: list all form objects.
 * @param[in]  form The input PDF form data object.
 * @param[in]  szFileName Input file name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormDebugOutput, (FPD_Form form,  FS_LPSTR szFileName))

/**
 * @brief FPDFormTransform
 * @details Transforms all objects.
 * @param[in]  form The input PDF form data object.
 * @param[in]  matrix The input transform matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormTransform, (FPD_Form form,  FS_AffineMatrix matrix))

/**
 * @brief FPDFormBackgroundAlphaNeeded
 * @details Checks whether this object list needs background alpha channel to render.
 * @param[in]  form The input PDF form data object.
 * @return   <a>TRUE</a> for this object list needing background alpha channel to render, otherwise not.
 * @note If it's <a>TRUE</a>, then the application should better use ARGB device to render it,
	*           otherwise the objects may need more time to render.
	*           Please call this function after the form has been parsed.
 */
INTERFACE(FS_BOOL, FPDFormBackgroundAlphaNeeded, (FPD_Form form))

/**
 * @brief FPDFormCalcBoundingBox
 * @details Calculates the bounding box of all form objects in the collection.
 * @param[in]  form The input PDF form data object.
 * @return   The bounding box of all form objects in the collection.
 * @note 
 */
INTERFACE(FS_FloatRect, FPDFormCalcBoundingBox, (FPD_Form form))

/**
 * @brief FPDFormGetDict
 * @details Gets the form stream dictionary.
 * @param[in]  form The input PDF form data object.
 * @return   The form stream dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDFormGetDict, (FPD_Form form))

/**
 * @brief FPDFormGetDocument
 * @details Gets the PDF document.
 * @param[in]  form The input PDF form data object.
 * @return   The PDF document.
 * @note 
 */
INTERFACE(FPD_Document, FPDFormGetDocument, (FPD_Form form))

/**
 * @brief FPDFormRealizeResource
 * @details Adds a resource to current object list. Return the resource name.
 * @param[in]  form The input PDF form data object.
 * @param[in]  pageResObj The input resource object
 * @param[in]  objMapping The input object mapping from object number to object pointer.
 * @param[in]  szType The resource type name.
 * @param[out]  outResObj It receives the result resource object.
 * @param[out]  outResName It receives the resource name.
 * @return   The resource name.
 * @note Will try to use an existing resource first, if available.
	*            Caller should not release the result resource object, which may be same as the input object.
	*            The input object can be an external object (which comes from another document, or archive),
	*            in this case, the object mapping should be specified.
 */
INTERFACE(void, FPDFormRealizeResource, (FPD_Form form,  FPD_Object pageResObj,  FS_MapPtrToPtr objMapping,  FS_LPSTR szType,  FPD_Object* outResObj,  FS_ByteString* outResName))

/**
 * @brief FPDFormFindCSName
 * @details Finds a resource name of specified color space.
 * @param[in]  form The input PDF form data object.
 * @param[in]  cs The input color space.
 * @param[out]  outResName It receives the resource name of the color space.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFindCSName, (FPD_Form form,  FPD_ColorSpace cs,  FS_ByteString* outResName))

/**
 * @brief FPDFormFindFontName
 * @details Finds a resource name of specified font.
 * @param[in]  form The input PDF form data object.
 * @param[in]  font The input font.
 * @param[out]  outResName It receives the resource name of the font.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFindFontName, (FPD_Form form,  FPD_Font font,  FS_ByteString* outResName))

/**
 * @brief FPDFormGetFormStream
 * @details Gets the form stream. For form only.
 * @param[in]  form The input PDF form data object.
 * @return   The form stream.
 * @note 
 */
INTERFACE(FPD_Object, FPDFormGetFormStream, (FPD_Form form))

/**
 * @brief FPDFormStartParse
 * @details Start parsing
 * @param[in]  form The input PDF form data object.
 * @param[in]  graphicStates The current graphics states. Set to NULL for current version.
 * @param[in]  pParentMatrix Matrix from form object to parent page/form. Optional.
 * @param[in]  Type3Char Used only when parsing Type3 character forms.
 * @param[in]  opts Parsing options.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormStartParse, (FPD_Form form,  FPD_AllStates graphicStates,  FS_AffineMatrix* pParentMatrix,  FPD_Type3Char Type3Char,  FPD_ParseOptions opts))

/**
 * @brief FPDFormParseContent
 * @details Parses all contents.
 * @param[in]  form The input PDF form data object.
 * @param[in]  graphicStates The current graphics states. Set to NULL for current version.
 * @param[in]  pParentMatrix Matrix from form object to parent page/form. Optional.
 * @param[in]  Type3Char Used only when parsing Type3 character forms.
 * @param[in]  opts Parsing options.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormParseContent, (FPD_Form form,  FPD_AllStates graphicStates,  FS_AffineMatrix* pParentMatrix,  FPD_Type3Char Type3Char,  FPD_ParseOptions opts))

/**
 * @brief FPDFormClone
 * @details Clones a form.
 * @param[in]  form The input PDF form data object.
 * @return   A form cloned from <param>form</param>.
 * @note 
 */
INTERFACE(FPD_Form, FPDFormClone, (FPD_Form form))

/**
 * @brief FPDFormGenerateContent
 * @details Replaces the form content stream.
 * @param[in]  form The input PDF form data object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormGenerateContent, (FPD_Form form))

/**
 * @brief FPDFormNewContentGenerator
 * @details Creates the PDF form content generator.
 * @param[in]  form The input PDF form data object.
 * @return   The PDF form content generator.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FPDFormDestroyContentGenerator
 */
INTERFACE(FPD_ContentGenerator, FPDFormNewContentGenerator, (FPD_Form form))

/**
 * @brief FPDFormDestroyContentGenerator
 * @details Destroys the PDF form content generator.
 * @param[in]  generator The input PDF form content generator.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDFormDestroyContentGenerator, (FPD_ContentGenerator generator))

/**
 * @brief FPDFormStartGenerateContent
 * @details Starts to generate the PDF content progressively.
 * @param[in]  generator The input PDF content generator.
 * @param[in]  fileStream The param has been deprecated.
 * @return   TRUE for success, otherwise not.
 * @note It has been deprecated. Suggest use FPDPageContinueGenerateContent2.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FPDFormContinueGenerateContent
 */
INTERFACE(FS_BOOL, FPDFormStartGenerateContent, (FPD_ContentGenerator generator,  FS_FileStream fileStream))

/**
 * @brief FPDFormContinueGenerateContent
 * @details Continues to generate the PDF content progressively.
 * @param[in]  generator The input PDF content generator.
 * @param[in]  pause The input pause handler. Creates the pause handler by <a>FSPauseHandlerCreate</a>. Sets it NULL as default.
 * @return   The status of generating PDF form content progressively.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FPD_ProgressiveStatus, FPDFormContinueGenerateContent, (FPD_ContentGenerator generator,  FS_PauseHandler pause))

/**
 * @brief FPDFormGetResourcesDictionary
 * @details Gets the PDF form resources dictionary.
 * @param[in]  form The input PDF form data object.
 * @return   The PDF form resources dictionary.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FPD_Object, FPDFormGetResourcesDictionary, (FPD_Form form))

/**
 * @brief FPDFormSetResourcesDictionary
 * @details Sets the PDF form resources dictionary.
 * @param[in]  form The input PDF form data object.
 * @param[in]  resourcesDict The input PDF form resources dictionary.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FPDFormSetResourcesDictionary, (FPD_Form form,  FPD_Object resourcesDict))

/**
 * @brief FPDFormSetFormStream
 * @details Set the form stream. For form only.
 * @param[in]  form The input PDF form data object.
 * @param[in]  stream The input form stream.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDFormSetFormStream, (FPD_Form form,  FPD_Object stream))

/**
 * @brief FPDFormSetFormDict
 * @details Set the form dictionary. For form only.
 * @param[in]  form The input PDF form data object.
 * @param[in]  dict The input form dictionary.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDFormSetFormDict, (FPD_Form form,  FPD_Object dict))

/**
 * @brief FPDFormCastToFPDGraphicsObjects
 * @details Convert to its parent object of FPD_GraphicsObjects.
 * @param[in]  form The input PDF form data object.
 * @return   FPD_GraphicsObjects     Convert to its parent object of FPD_GraphicsObjects.
 * @note 
 */
INTERFACE(FPD_GraphicsObjects, FPDFormCastToFPDGraphicsObjects, (FPD_Form form))

/**
 * @brief FPDFormStartGenerateContent2
 * @details Starts to generate the PDF content progressively.
 * @param[in]  generator The input PDF content generator.
 * @return   TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FPDFormContinueGenerateContent
 */
INTERFACE(FS_BOOL, FPDFormStartGenerateContent2, (FPD_ContentGenerator generator))

/**
 * @brief FPDFormGenerateContent2
 * @details Replaces the form content stream.
 * @param[in]  form The input PDF form data object.
 * @param[out]  bsContent It receives the content stream.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormGenerateContent2, (FPD_Form form,  FS_ByteString* bsContent))

NumOfSelector(FPDForm)
ENDENUM

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
//*****************************
/* ColorSeparator HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDColorSeparatorNew
 * @details Creates a new color separator object.
 * @param[in]  pDoc The input PDF document.
 * @return   A new color separator object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(FPD_ColorSeparator, FPDColorSeparatorNew, (FPD_Document pDoc))

/**
 * @brief FPDColorSeparatorDestroy
 * @details Destroys the color separator object.
 * @param[in]  colorSeparator The input color separator object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(void, FPDColorSeparatorDestroy, (FPD_ColorSeparator colorSeparator))

/**
 * @brief FPDColorSeparatorCountColorants
 * @details Gets the count of colorants.
 * @param[in]  colorSeparator The input color separator object.
 * @param[in]  pInputPage The input pdf page.
 * @param[in]  bReCount Sets it <a>FALSE</a> as default.
 * @return   The count of colorants.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(FS_INT32, FPDColorSeparatorCountColorants, (FPD_ColorSeparator colorSeparator,  FPD_Page pInputPage,  FS_BOOL bReCount))

/**
 * @brief FPDColorSeparatorGetColorantName
 * @details Gets the name of specified colorant.
 * @param[in]  colorSeparator The input color separator object.
 * @param[in]  index The specified index.
 * @param[out]  outColorantName It receives the colorant name.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(FS_BOOL, FPDColorSeparatorGetColorantName, (FPD_ColorSeparator colorSeparator,  FS_INT32 index,  FS_ByteString outColorantName))

/**
 * @brief FPDColorSeparatorSeparateColorant
 * @details Starts to separate colorant.
 * @param[in]  colorSeparator The input color separator object.
 * @param[in]  ColorantName The input colorant name.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(FS_BOOL, FPDColorSeparatorSeparateColorant, (FPD_ColorSeparator colorSeparator,  const FS_ByteString ColorantName))

/**
 * @brief FPDColorSeparatorGetResultDoc
 * @details Gets the result document.
 * @param[in]  colorSeparator The input color separator object.
 * @return   The result document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(FPD_Document, FPDColorSeparatorGetResultDoc, (FPD_ColorSeparator colorSeparator))

/**
 * @brief FPDColorSeparatorSetColorConverter
 * @details Sets the color converter.
 * @param[in]  colorSeparator The input color separator object.
 * @param[in]  colorConverter The input color converter object.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(FS_BOOL, FPDColorSeparatorSetColorConverter, (FPD_ColorSeparator colorSeparator,  FPD_ColorConvertor colorConverter))

NumOfSelector(FPDColorSeparator)
ENDENUM

//----------_V12----------
//----------_V13----------
//----------_V14----------
//----------_V15----------
//----------_V16----------
//*****************************
/* GraphicObjects HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDGraphicObjectsCastToFPDPage
 * @details Convert FPD_GraphicsObjects to FPD_Page.
 * @param[in]  object The input FPD_GraphicsObjects.
 * @return   FPD_Page   Convert FPD_GraphicsObjects to FPD_Page.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Page, FPDGraphicObjectsCastToFPDPage, (FPD_GraphicsObjects object))

/**
 * @brief FPDGraphicObjectsCastToFPDForm
 * @details Convert FPD_GraphicsObjects to FPD_Form.
 * @param[in]  object The input FPD_GraphicsObjects.
 * @return   FPD_Form   Convert FPD_GraphicsObjects to FPD_Form.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Form, FPDGraphicObjectsCastToFPDForm, (FPD_GraphicsObjects object))

/**
 * @brief FPDGraphicObjectsGetType
 * @details Get the type of FPD_GraphicsObjects,
 * @param[in]  object The input FPD_GraphicsObjects.
 * @return   FS_INT32   Get the type of FPD_GraphicsObjects,
	* like FPDPAGEOBJECTS_PAGE,FPDPAGEOBJECTS_FORMX.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_INT32, FPDGraphicObjectsGetType, (FPD_GraphicsObjects object))

NumOfSelector(FPDGraphicObjects)
ENDENUM

//*****************************
/* PDFObjectExtracter HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDPDFObjectExtracterCreate
 * @details Create FPD_PDFObjectExtracter object.
	* The object is used extractor some page object and product a new document.
 * @param[in]  pDoc The input FPD_Document.
 * @return   FPD_PDFObjectExtracter    Create FPD_PDFObjectExtracter object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_PDFObjectExtracter, FPDPDFObjectExtracterCreate, (FPD_Document pDoc))

/**
 * @brief FPDPDFObjectExtracterDestroy
 * @details Destroy FPD_PDFObjectExtracter object.
 * @param[in]  extracter The input FPD_PDFObjectExtracter.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDPDFObjectExtracterDestroy, (FPD_PDFObjectExtracter extracter))

/**
 * @brief FPDPDFObjectExtracterCreateNewPageFromOrigal
 * @details Create new page.
 * @param[in]  extracter The input FPD_PDFObjectExtracter.
 * @param[in]  pOriPage The input orgin page object.
 * @param[in]  index The input page index.
 * @return   FPD_Page  Create new page.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Page, FPDPDFObjectExtracterCreateNewPageFromOrigal, (FPD_PDFObjectExtracter extracter,  FPD_Page pOriPage,  FS_INT32 index))

/**
 * @brief FPDPDFObjectExtracterAddGraphicsObject
 * @details Add graphis object.
 * @param[in]  extracter The input FPD_PDFObjectExtracter.
 * @param[in]  pNewPage The input new page object.
 * @param[in]  pOrgFormParent The input original form objects.
 * @param[in]  pOrgPageObject The input original object.
 * @return   FS_BOOLEAN     true means add success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDPDFObjectExtracterAddGraphicsObject, (FPD_PDFObjectExtracter extracter,  FPD_GraphicsObjects pNewPage,  FS_PtrArray pOrgFormParent,  FPD_PageObject pOrgPageObject))

/**
 * @brief FPDPDFObjectExtracterCloseNewPage
 * @details Close new page.
 * @param[in]  extracter The input FPD_PDFObjectExtracter.
 * @param[in]  pNewPage The input new page object.
 * @return   FS_BOOLEAN     true means close success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDPDFObjectExtracterCloseNewPage, (FPD_PDFObjectExtracter extracter,  FPD_Page pNewPage))

/**
 * @brief FPDPDFObjectExtracterUpdateStructTree
 * @details Update the struct tree for the extracter PDF Document.
 * @param[in]  extracter The input FPD_PDFObjectExtracter.
 * @return   FS_BOOLEAN              true means success, otherwise not.
 * @note It must be called befor save the PDF document.
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDPDFObjectExtracterUpdateStructTree, (FPD_PDFObjectExtracter extracter))

/**
 * @brief FPDPDFObjectExtracterGetExtracterPDFDoc
 * @details Get extract pdf document.
 * @param[in]  extracter The input FPD_PDFObjectExtracter.
 * @return   FPD_Document            Get extract pdf document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Document, FPDPDFObjectExtracterGetExtracterPDFDoc, (FPD_PDFObjectExtracter extracter))

NumOfSelector(FPDPDFObjectExtracter)
ENDENUM

//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------

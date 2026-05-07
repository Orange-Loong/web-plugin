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
/* ProgressiveSearch HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDProgressiveSearchNew
 * @details Creates a progressive searching object.
 * @return   A progressive searching object.
 * @note 
 */
INTERFACE(FPD_ProgressiveSearch, FPDProgressiveSearchNew, ())

/**
 * @brief FPDProgressiveSearchDestroy
 * @details Destroys the progressive searching object.
 * @param[in]  sch The input progressive searching object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveSearchDestroy, (FPD_ProgressiveSearch sch))

/**
 * @brief FPDProgressiveSearchGetStatus
 * @details Gets the current status.
 * @param[in]  sch The input progressive searching object.
 * @return   The current status.
 * @note 
 */
INTERFACE(FS_INT32, FPDProgressiveSearchGetStatus, (FPD_ProgressiveSearch sch))

/**
 * @brief FPDProgressiveSearchFindFrom
 * @details Find the first match with specified search flags, optionally with a start position.
	*            The page object may have parsed content objects,
	*            or may not have those objects parsed. In later case, the search engine will do a text-only
	*            parsing in order to search for the pattern. 
	*            This function can be paused by a pause object.
 * @param[in]  sch The input progressive searching object.
 * @param[in]  page A PDF page handle.
 * @param[in]  pattern What do you want to find?
 * @param[in]  pos The starting position.
 * @param[in]  flags See <a>FPDSearchFlags</a>.
 * @param[in]  pauseHandler The user-supplied pause handler that can pause the finding process. Can be NULL if no pausing is needed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveSearchFindFrom, (FPD_ProgressiveSearch sch,  FPD_Page page,  FS_LPCWSTR pattern,  FS_INT32 pos,  FS_DWORD flags,  FS_PauseHandler pauseHandler))

/**
 * @brief FPDProgressiveSearchContinue
 * @details Continues the searching.
 * @param[in]  sch The input progressive searching object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveSearchContinue, (FPD_ProgressiveSearch sch))

/**
 * @brief FPDProgressiveSearchFindNext
 * @details Searchs for next match within the same page, from last match position.
 * @param[in]  sch The input progressive searching object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveSearchFindNext, (FPD_ProgressiveSearch sch))

/**
 * @brief FPDProgressiveSearchFindPrev
 * @details Searchs for previous match within the same page, from last match position.
 * @param[in]  sch The input progressive searching object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveSearchFindPrev, (FPD_ProgressiveSearch sch))

/**
 * @brief FPDProgressiveSearchCountRects
 * @details Gets the count of rectangles for current found matches.
 * @param[in]  sch The input progressive searching object.
 * @return   The count of rectangles for current found matches.
 * @note Before called, the page must be parsed.
 */
INTERFACE(FS_DWORD, FPDProgressiveSearchCountRects, (FPD_ProgressiveSearch sch))

/**
 * @brief FPDProgressiveSearchGetRect
 * @details Gets the specified rectangle for current found matches.
 * @param[in]  sch The input progressive searching object.
 * @param[in]  index The index of the current found matches.
 * @return   The specified rectangle for current found matches.
 * @note Before called, the page must be parsed.
 */
INTERFACE(FS_FloatRect, FPDProgressiveSearchGetRect, (FPD_ProgressiveSearch sch,  FS_INT32 index))

/**
 * @brief FPDProgressiveSearchGetPos
 * @details Gets the current position.
 * @param[in]  sch The input progressive searching object.
 * @return   The current position.
 * @note 
 */
INTERFACE(FS_INT32, FPDProgressiveSearchGetPos, (FPD_ProgressiveSearch sch))

NumOfSelector(FPDProgressiveSearch)
ENDENUM

//*****************************
/* TextPage HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDTextPageNew
 * @details Creates a new text page for PDF text processing.
 * @param[in]  page The input PDF page.
 * @param[in]  flags See <a>FPDTextPageFlags</a>.
 * @return   A new text page for PDF text processing.
 * @note 
 */
INTERFACE(FPD_TextPage, FPDTextPageNew, (FPD_Page page,  FS_INT32 flags))

/**
 * @brief FPDTextPageDestroy
 * @details Destroys the text page.
 * @param[in]  page The input text page.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextPageDestroy, (FPD_TextPage page))

/**
 * @brief FPDTextPageParseTextPage
 * @details Parses the pdf page. The page object may have parsed content objects.
 * @param[in]  page The input text page.
 * @return   <a>TRUE</a> means success, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDTextPageParseTextPage, (FPD_TextPage page))

/**
 * @brief FPDTextPageIsParsered
 * @details Check whether the text page has been parsed.
 * @param[in]  page The input text page.
 * @return   <a>TRUE</a> for the text page having been parsed, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDTextPageIsParsered, (FPD_TextPage page))

/**
 * @brief FPDTextPageCountChars
 * @details Gets the count of character in the text page.
 * @param[in]  page The input text page.
 * @return   The count of character in the text page.
 * @note 
 */
INTERFACE(FS_INT32, FPDTextPageCountChars, (FPD_TextPage page))

/**
 * @brief FPDTextPageGetCharInfo
 * @details Gets the specified character information.
 * @param[in]  page The input text page.
 * @param[in]  index The index of the character.
 * @param[out]  outInfo It receives the information of the character.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextPageGetCharInfo, (FPD_TextPage page,  FS_INT32 index,  FPD_CHAR_INFO* outInfo))

/**
 * @brief FPDTextPageGetRectArray
 * @details Gets the rectangle array for character index interzone. [start, start+count)
 * @param[in]  page The input text page.
 * @param[in]  start The starting char index.
 * @param[in]  nCount Number of chars ( end char index - start char index).
 * @param[out]  outRectArray It receives the rectangle array for character index interzone. [start, start+count).
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextPageGetRectArray, (FPD_TextPage page,  FS_INT32 start,  FS_INT32 nCount,  FS_FloatRectArray* outRectArray))

/**
 * @brief FPDTextPageGetIndexAtPos
 * @details If there are no character in this point, the return value <0.
	*            Recommended value for <param>xTorelance</param> or <param>yTorelance</param> is between 0 and 30.
 * @param[in]  page The input text page.
 * @param[in]  x The x coordinate of the point.
 * @param[in]  y The y coordinate of the point.
 * @param[in]  xTorelance X direction recommended value.
 * @param[in]  yTorelance Y direction recommended value.
 * @return   The index of specified char.
 * @note 
 */
INTERFACE(FS_INT32, FPDTextPageGetIndexAtPos, (FPD_TextPage page,  FS_FLOAT x,  FS_FLOAT y,  FS_FLOAT xTorelance,  FS_FLOAT yTorelance))

/**
 * @brief FPDTextPageGetOrderByDirection
 * @details Gets the character index by specific direction. if the return value is -1 means previous page,-2 for next page.
 * @param[in]  page The input text page.
 * @param[in]  order The character index.
 * @param[in]  direction See directions type.
 * @return   The character with specified relationship of current character
 * @note 
 */
INTERFACE(FS_INT32, FPDTextPageGetOrderByDirection, (FPD_TextPage page,  FS_INT32 order,  FS_INT32 direction))

/**
 * @brief FPDTextPageGetTextByRect
 * @details Gets the text in specified rectangle.
 * @param[in]  page The input text page.
 * @param[in]  rect The specified rectangle.
 * @param[out]  outText It receives the text in specified rectangle.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextPageGetTextByRect, (FPD_TextPage page,  FS_FloatRect rect,  FS_WideString* outText))

/**
 * @brief FPDTextPageGetRectsArrayByRect
 * @details Gets the text rectangle array by a rectangle.
 * @param[in]  page The input text page.
 * @param[in]  rect The specified rectangle.
 * @param[out]  outRectArray It receives the text rectangle array by a rectangle.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextPageGetRectsArrayByRect, (FPD_TextPage page,  FS_FloatRect rect,  FS_FloatRectArray* outRectArray))

/**
 * @brief FPDTextPageCountRects
 * @details Gets the count of text rectangle in the text page.
 * @param[in]  page The input text page.
 * @param[in]  start The index of the starting character.
 * @param[in]  nCount The character's count.
 * @return   The count of text rectangle.
 * @note 
 */
INTERFACE(FS_INT32, FPDTextPageCountRects, (FPD_TextPage page,  FS_INT32 start,  FS_INT32 nCount))

/**
 * @brief FPDTextPageGetRect
 * @details Gets the specified text rectangle in the text page.
 * @param[in]  page The input text page.
 * @param[in]  rectIndex The specified rectangle index.
 * @return   The specified text rectangle in the text page.
 * @note 
 */
INTERFACE(FS_FloatRect, FPDTextPageGetRect, (FPD_TextPage page,  FS_INT32 rectIndex))

/**
 * @brief FPDTextPageCountBoundedSegments
 * @details Gets the count of segment in specified rectangle.
 * @param[in]  page The input text page.
 * @param[in]  left Left position of the text coordinate.
 * @param[in]  top Top position of the text coordinate.
 * @param[in]  right Right position of the text coordinate.
 * @param[in]  bottom Bottom position of the text coordinate.
 * @return   The count of segment in specified rectangle.
 * @note 
 */
INTERFACE(FS_INT32, FPDTextPageCountBoundedSegments, (FPD_TextPage page,  FS_FLOAT left,  FS_FLOAT top,  FS_FLOAT right,  FS_FLOAT bottom))

/**
 * @brief FPDTextPageGetBoundedSegment
 * @details Gets the specified bounded segment.
 * @param[in]  page The input text page.
 * @param[in]  index The specified index of bounded segment.
 * @param[in,out]  outstart The index of starting character.
 * @param[in,out]  outcount The count of characters.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextPageGetBoundedSegment, (FPD_TextPage page,  FS_INT32 index,  FS_INT32* outstart,  FS_INT32* outcount))

/**
 * @brief FPDTextPageGetWordBreak
 * @details Not support now.
 * @param[in]  page The input text page.
 * @param[in]  index The specified index.
 * @param[in]  direction The input direction.
 * @return   The word break.
 * @note 
 */
INTERFACE(FS_INT32, FPDTextPageGetWordBreak, (FPD_TextPage page,  FS_INT32 index,  FS_INT32 direction))

/**
 * @brief FPDTextPageGetPageText
 * @details Gets the text of a page.
 * @param[in]  page The input text page.
 * @param[in]  start The start of the page text.
 * @param[in]  nCount The count of page text to get, -1 for the end of the page.
 * @param[out]  outText It receives the text got.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextPageGetPageText, (FPD_TextPage page,  FS_INT32 start,  FS_INT32 nCount,  FS_WideString* outText))

/**
 * @brief FPDTextPageGetUnicodeProperties
 * @details Retrieve unicode properties list
 * @param[in]  wch The input text page.
 * @return   void
 * @note 
 */
INTERFACE(FS_DWORD, FPDTextPageGetUnicodeProperties, (FS_WCHAR wch))

/**
 * @brief FPDTextPageNew2
 * @details Creates a new text page for PDF text processing.
 * @param[in]  page The pdf objects list.
 * @param[in]  flags See <a>FPDTextPageFlags</a>.
 * @return   A new text page for PDF text processing.
 * @note 
 */
INTERFACE(FPD_TextPage, FPDTextPageNew2, (FS_LPVOID pObjs,  FS_INT32 flags))

/**
 * @brief FPDTextPageNew3
 * @details Creates a new text page for PDF text processing.
 * @param[in]  page The input PDF page.
 * @param[in]  option Text parse options.
 * @return   A new text page for PDF text processing.
 * @note 
 */
INTERFACE(FPD_TextPage, FPDTextPageNew3, (FPD_Page page,  FPD_Text_ParseOption option))

INTERFACE(void, FPDTextPageGetRectArray2, (FPD_TextPage page,  FS_INT32 start,  FS_INT32 nCount,  FS_FloatRectArray* outRectArray,  FS_BOOLEAN bDisplayArea))

/**
 * @brief FPDTextPageCharIndexFromTextIndex
 * @details Get character index from text index.
 * @param[in]  page The input text page.
 * @param[in]  textIndex The input text index form page text.
 * @return   FS_INT32   return character index, -1 is non-existent.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDTextPageCharIndexFromTextIndex, (FPD_TextPage page,  FS_INT32 textIndex))

/**
 * @brief FPDTextPageTextIndexFromCharIndex
 * @details Get text index from character index.
 * @param[in]  page The input text page.
 * @param[in]  CharIndex The input character index form character list.
 * @return   FS_INT32   return text index, -1 is non-existent.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDTextPageTextIndexFromCharIndex, (FPD_TextPage page,  FS_INT32 CharIndex))

/**
 * @brief FPDTextPageGetRectArrayPathData
 * @details Get the path data.
 * @param[in]  page The input text page.
 * @param[in]  start The input start position.
 * @param[in]  nCount The input text count.
 * @param[in/out]  Paths Get the path datas.
 * @param[in]  bDisplayArea Whether need to didplay.
 * @return   void
 * @note Rember use FPDTextPageFindReleasePathData to release data.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 */
INTERFACE(void, FPDTextPageGetRectArrayPathData, (FPD_TextPage page,  FS_INT32 start,  FS_INT32 nCount,  FS_PtrArray* Paths,  FS_BOOLEAN bDisplayArea))

NumOfSelector(FPDTextPage)
ENDENUM

//*****************************
/* TextPageFind HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDTextPageFindNew
 * @details Creates text searching object from a text page.
 * @param[in]  textpage The input text page object.
 * @return   The text searching object.
 * @note 
 */
INTERFACE(FPD_TextPageFind, FPDTextPageFindNew, (const FPD_TextPage textpage))

/**
 * @brief FPDTextPageFindDestroy
 * @details Destroys the text searching object.
 * @param[in]  find The input text searching object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextPageFindDestroy, (FPD_TextPageFind find))

/**
 * @brief FPDTextPageFindFindFirst
 * @details Finds the first match with specified search flags, optionally with a start position.
 * @param[in]  find The input text searching object.
 * @param[in]  findwhat What you want to find.
 * @param[in]  flags The search flags.
 * @param[in]  startPos The start position.
 * @return   <a>TRUE</a> means the first match is found, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDTextPageFindFindFirst, (FPD_TextPageFind find,  FS_LPWSTR findwhat,  FS_INT32 flags,  FS_INT32 startPos))

/**
 * @brief FPDTextPageFindFindNext
 * @details Finds the next match.
 * @param[in]  find The input text searching object.
 * @return   <a>TRUE</a> means the next match is found, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDTextPageFindFindNext, (FPD_TextPageFind find))

/**
 * @brief FPDTextPageFindFindPrev
 * @details Finds the previous match.
 * @param[in]  find The input text searching object.
 * @return   <a>TRUE</a> means the previous match is found, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDTextPageFindFindPrev, (FPD_TextPageFind find))

/**
 * @brief FPDTextPageFindGetRectArray
 * @details Gets the matched rectangle array.
 * @param[in]  find The input text searching object.
 * @param[out]  outRects It receives the matched rectangle array.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextPageFindGetRectArray, (FPD_TextPageFind find,  FS_FloatRectArray* outRects))

/**
 * @brief FPDTextPageFindGetCurOrder
 * @details Gets the current order.
 * @param[in]  find The input text searching object.
 * @return   The current order.
 * @note 
 */
INTERFACE(FS_INT32, FPDTextPageFindGetCurOrder, (FPD_TextPageFind find))

/**
 * @brief FPDTextPageFindGetMatchedCount
 * @details Gets the count of current matches.
 * @param[in]  find The input text searching object.
 * @return   The count of current matches.
 * @note 
 */
INTERFACE(FS_INT32, FPDTextPageFindGetMatchedCount, (FPD_TextPageFind find))

/**
 * @brief FPDTextPageFindGetRectPathData
 * @details Get matched rectangle array.
 * @param[in]  find The input text searching object.
 * @param[in/out]  Paths Get the rect path array.
 * @return   void
 * @note Rember use FPDTextPageFindReleasePathData to release data.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2
 */
INTERFACE(void, FPDTextPageFindGetRectPathData, (FPD_TextPageFind find,  FS_PtrArray* Paths))

/**
 * @brief FPDTextPageFindReleasePathData
 * @details Release path data.
 * @param[in]  pathArr The input path array.
 * @return   void
 * @note Rember use FPDTextPageFindReleasePathData to release data.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2
 */
INTERFACE(void, FPDTextPageFindReleasePathData, (FS_PtrArray pathArr))

NumOfSelector(FPDTextPageFind)
ENDENUM

//*****************************
/* LinkExtract HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLinkExtractNew
 * @details Creates an empty link extracting object.
 * @return   An empty link extracting object.
 * @note 
 */
INTERFACE(FPD_LinkExtract, FPDLinkExtractNew, ())

/**
 * @brief FPDLinkExtractDestroy
 * @details Destroys the link extracting object.
 * @param[in]  extr The input link extracting object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLinkExtractDestroy, (FPD_LinkExtract extr))

/**
 * @brief FPDLinkExtractExtractLinks
 * @details Extracts links for a text page.
 * @param[in]  extr The input link extracting object.
 * @param[in]  textpage The input text page.
 * @return   <a>TRUE</a> means success, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDLinkExtractExtractLinks, (FPD_LinkExtract extr,  const FPD_TextPage textpage))

/**
 * @brief FPDLinkExtractCountLinks
 * @details Gets the count of links in the text page.
 * @param[in]  extr The input link extracting object.
 * @return   The count of links in the text page. Returns -1 for error.
 * @note 
 */
INTERFACE(FS_INT32, FPDLinkExtractCountLinks, (FPD_LinkExtract extr))

/**
 * @brief FPDLinkExtractGetURL
 * @details Gets the linked URL for specified link.
 * @param[in]  extr The input link extracting object.
 * @param[in]  index The specified index.
 * @param[out]  outURL It receives the linked URL for specified link.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLinkExtractGetURL, (FPD_LinkExtract extr,  FS_INT32 index,  FS_WideString* outURL))

/**
 * @brief FPDLinkExtractGetRects
 * @details Gets the rectangle array for specified link.
 * @param[in]  extr The input link extracting object.
 * @param[in]  index The specified index.
 * @param[out]  outRects It receives the rectangle array for specified link.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLinkExtractGetRects, (FPD_LinkExtract extr,  FS_INT32 index,  FS_FloatRectArray* outRects))

NumOfSelector(FPDLinkExtract)
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
//----------_V12----------
//----------_V13----------
//----------_V14----------
//----------_V15----------
//----------_V16----------
//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------

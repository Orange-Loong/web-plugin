#ifndef FPD_TEXTIMPL_H
#define FPD_TEXTIMPL_H


#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_TEXTEXPT_H
#include "../fpd_textExpT.h"
#endif
#ifndef FPD_RENDEREXPT_H
#include "../fpd_renderExpT.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "../fpd_pageExpT.h"
#endif


#ifdef __cplusplus
extern "C"{
#endif

class CFPD_ProgressiveSearch_V1
{
public:
	//************************************
	// Function:  New
	// Return:    A progressive searching object.
	// Remarks:   Creates a progressive searching object.
	// Notes:
	//************************************
	static	FPD_ProgressiveSearch New();

	//************************************
	// Function:  Destroy
	// Param[in]: sch		The input progressive searching object.
	// Return:    void
	// Remarks:   Destroys the progressive searching object.
	// Notes:
	//************************************
	static	void Destroy(FPD_ProgressiveSearch sch);

	//************************************
	// Function:  GetStatus
	// Param[in]: sch		The input progressive searching object.
	// Return:    The current status.
	// Remarks:   Gets the current status.
	// Notes:
	//************************************
	static	FS_INT32 GetStatus(FPD_ProgressiveSearch sch);

	//************************************
	// Function:  FindFrom
	// Param[in]: sch			The input progressive searching object.
	// Param[in]: page			A PDF page handle.
	// Param[in]: pattern		What do you want to find?
	// Param[in]: pos			The starting position.
	// Param[in]: flags			See <a>FPDSearchFlags</a>.
	// Param[in]: pauseHandler	The user-supplied pause handler that can pause the finding process. Can be NULL if no pausing is needed.
	// Return:    void
	// Remarks:   Find the first match with specified search flags, optionally with a start position.
	//            The page object may have parsed content objects,
	//            or may not have those objects parsed. In later case, the search engine will do a text-only
	//            parsing in order to search for the pattern. 
	//            This function can be paused by a pause object.
	// Notes:
	//************************************
	static	void FindFrom(
		FPD_ProgressiveSearch sch, 
		FPD_Page page, 
		FS_LPCWSTR pattern, 
		FS_INT32 pos, 
		FS_DWORD flags, 
		FS_PauseHandler pauseHandler
		);
	
	//************************************
	// Function:  Continue
	// Param[in]: sch		The input progressive searching object.
	// Return:    void
	// Remarks:   Continues the searching.
	// Notes:
	//************************************
	static	void Continue(FPD_ProgressiveSearch sch);


	//************************************
	// Function:  FindNext
	// Param[in]: sch		The input progressive searching object.
	// Return:    void
	// Remarks:   Searchs for next match within the same page, from last match position.
	// Notes:
	//************************************
	static	void FindNext(FPD_ProgressiveSearch sch);

	//************************************
	// Function:  FindPrev
	// Param[in]: sch		The input progressive searching object.
	// Return:    void
	// Remarks:   Searchs for previous match within the same page, from last match position.
	// Notes:
	//************************************
	static	void FindPrev(FPD_ProgressiveSearch sch);


	//************************************
	// Function:  CountRects
	// Param[in]: sch		The input progressive searching object.
	// Return:    The count of rectangles for current found matches.
	// Remarks:   Gets the count of rectangles for current found matches.
	// Notes:     Before called, the page must be parsed.
	//************************************
	static	FS_DWORD CountRects(FPD_ProgressiveSearch sch);

	//************************************
	// Function:  GetRect
	// Param[in]: sch		The input progressive searching object.
	// Param[in]: index		The index of the current found matches.
	// Return:    The specified rectangle for current found matches.
	// Remarks:   Gets the specified rectangle for current found matches.
	// Notes:     Before called, the page must be parsed.
	//************************************
	static	FS_FloatRect GetRect(FPD_ProgressiveSearch sch, FS_INT32 index);

	//************************************
	// Function:  GetPos
	// Param[in]: sch		The input progressive searching object.
	// Return:    The current position.
	// Remarks:   Gets the current position.
	// Notes:
	//************************************
	static	FS_INT32	GetPos(FPD_ProgressiveSearch sch);	
};



class CFPD_TextPage_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: page		The input PDF page.
	// Param[in]: flags		See <a>FPDTextPageFlags</a>.
	// Return:    A new text page for PDF text processing.
	// Remarks:   Creates a new text page for PDF text processing.
	// Notes:
	//************************************
	static	FPD_TextPage New(FPD_Page page, FS_INT32 flags);

	//************************************
	// Function:  Destroy
	// Param[in]: page The input text page.
	// Return:    void
	// Remarks:   Destroys the text page.
	// Notes:
	//************************************
	static	void Destroy(FPD_TextPage page);

	//************************************
	// Function:  ParseTextPage
	// Param[in]: page	The input text page.
	// Return:    <a>TRUE</a> means success, otherwise <a>FALSE</a>.
	// Remarks:   Parses the pdf page. The page object may have parsed content objects.
	// Notes:
	//************************************
	static	FS_BOOL	ParseTextPage(FPD_TextPage page);

	//************************************
	// Function:  IsParsered
	// Param[in]: page	The input text page.
	// Return:    <a>TRUE</a> for the text page having been parsed, otherwise <a>FALSE</a>.
	// Remarks:   Check whether the text page has been parsed.
	// Notes:
	//************************************
	static	FS_BOOL	IsParsered(FPD_TextPage page);

	//************************************
	// Function:  CountChars
	// Param[in]: page	The input text page.
	// Return:    The count of character in the text page.
	// Remarks:   Gets the count of character in the text page.
	// Notes:
	//************************************
	static	FS_INT32 CountChars(FPD_TextPage page);

	//************************************
	// Function:  GetCharInfo
	// Param[in]: page		The input text page.
	// Param[in]: index		The index of the character.
	// Param[out]:outInfo   It receives the information of the character.
	// Return:    void
	// Remarks:   Gets the specified character information.
	// Notes:
	//************************************
	static	void GetCharInfo(FPD_TextPage page, FS_INT32 index, FPD_CHAR_INFO* outInfo);

	//************************************
	// Function:  GetRectArray
	// Param[in]: page		The input text page.
	// Param[in]: start		The starting char index.
	// Param[in]: nCount	Number of chars ( end char index - start char index).
	// Param[out]:outRectArray It receives the rectangle array for character index interzone. [start, start+count).
	// Return:    void
	// Remarks:   Gets the rectangle array for character index interzone. [start, start+count)
	// Notes:
	//************************************
	static	void GetRectArray(FPD_TextPage page, FS_INT32 start, FS_INT32 nCount, FS_FloatRectArray* outRectArray);

	//************************************
	// Function:  GetIndexAtPos
	// Param[in]: page			The input text page.
	// Param[in]: x				The x coordinate of the point.
	// Param[in]: y				The y coordinate of the point.
	// Param[in]: xTorelance	X direction recommended value.
	// Param[in]: yTorelance	Y direction recommended value.
	// Return:    The index of specified char.
	// Remarks:   If there are no character in this point, the return value <0.
	//            Recommended value for <param>xTorelance</param> or <param>yTorelance</param> is between 0 and 30.
	// Notes:
	//************************************
	static	FS_INT32 GetIndexAtPos(FPD_TextPage page, FS_FLOAT x, FS_FLOAT y, FS_FLOAT xTorelance, FS_FLOAT yTorelance);

	//************************************
	// Function:  GetOrderByDirection
	// Param[in]: page		The input text page.
	// Param[in]: order		The character index.
	// Param[in]: direction	See directions type.
	// Return:    The character with specified relationship of current character
	// Remarks:   Gets the character index by specific direction. if the return value is -1 means previous page,-2 for next page.
	// Notes:
	//************************************
	static	FS_INT32 GetOrderByDirection(FPD_TextPage page, FS_INT32 order, FS_INT32 direction);

	//************************************
	// Function:  GetTextByRect
	// Param[in]: page		The input text page.
	// Param[in]: rect		The specified rectangle.
	// Param[out]:outText	It receives the text in specified rectangle.
	// Return:    void
	// Remarks:   Gets the text in specified rectangle.
	// Notes:
	//************************************
	static	void GetTextByRect(FPD_TextPage page, FS_FloatRect rect, FS_WideString* outText);

	//************************************
	// Function:  GetRectsArrayByRect
	// Param[in]: page			The input text page.
	// Param[in]: rect			The specified rectangle.
	// Param[out]:outRectArray	It receives the text rectangle array by a rectangle.
	// Return:    void
	// Remarks:   Gets the text rectangle array by a rectangle.
	// Notes:
	//************************************
	static	void GetRectsArrayByRect(FPD_TextPage page, FS_FloatRect rect, FS_FloatRectArray* outRectArray);

	//************************************
	// Function:  CountRects
	// Param[in]: page		The input text page.
	// Param[in]: start		The index of the starting character.
	// Param[in]: nCount	The character's count.
	// Return:	  The count of text rectangle.
	// Remarks:   Gets the count of text rectangle in the text page.
	// Notes:
	//************************************
	static	FS_INT32 CountRects(FPD_TextPage page, FS_INT32 start, FS_INT32 nCount);

	//************************************
	// Function:  GetRect
	// Param[in]: page		The input text page.
	// Param[in]: rectIndex The specified rectangle index.
	// Return:    The specified text rectangle in the text page.
	// Remarks:   Gets the specified text rectangle in the text page.
	// Notes:
	//************************************
	static	FS_FloatRect GetRect(FPD_TextPage page, FS_INT32 rectIndex);

	//************************************
	// Function:  CountBoundedSegments
	// Param[in]: page		The input text page.
	// Param[in]: left		Left position of the text coordinate.
	// Param[in]: top		Top position of the text coordinate.
	// Param[in]: right		Right position of the text coordinate.
	// Param[in]: bottom	Bottom position of the text coordinate.
	// Return:    The count of segment in specified rectangle.
	// Remarks:   Gets the count of segment in specified rectangle.
	// Notes:
	//************************************
	static	FS_INT32 CountBoundedSegments(FPD_TextPage page, FS_FLOAT left, FS_FLOAT top, FS_FLOAT right, FS_FLOAT bottom);

	//************************************
	// Function:  GetBoundedSegment
	// Param[in]: page		The input text page.
	// Param[in]: index		The specified index of bounded segment.
	// Param[in,out]:outstart	The index of starting character.
	// Param[in,out]:outcount  The count of characters.
	// Return:    void
	// Remarks:   Gets the specified bounded segment.
	// Notes: 
	//************************************
	static	void GetBoundedSegment(FPD_TextPage page, FS_INT32 index, FS_INT32* outstart, FS_INT32* outcount);

	//************************************
	// Function:  GetWordBreak
	// Param[in]: page			The input text page.
	// Param[in]: index			The specified index.
	// Param[in]: direction		The input direction.
	// Return:    The word break.
	// Remarks:   Not support now.
	// Notes:
	//************************************
	static	FS_INT32 GetWordBreak(FPD_TextPage page, FS_INT32 index, FS_INT32 direction);

	//************************************
	// Function:  GetPageText
	// Param[in]: page		The input text page.
	// Param[in]: start		The start of the page text.
	// Param[in]: nCount	The count of page text to get, -1 for the end of the page.
	// Param[out]:outText   It receives the text got.
	// Return:    void
	// Remarks:   Gets the text of a page.
	// Notes:
	//************************************
	static	void GetPageText(FPD_TextPage page, FS_INT32 start, FS_INT32 nCount, FS_WideString* outText);
	
	//************************************
	// Function:  GetUnicodeProperties
	// Param[in]: wch		The input text page.	
	// Return:    void
	// Remarks:   Retrieve unicode properties list
	// Notes:
	//************************************
	static FS_DWORD GetUnicodeProperties(FS_WCHAR wch);

	//************************************
	// Function:  New2
	// Param[in]: page		The pdf objects list.
	// Param[in]: flags		See <a>FPDTextPageFlags</a>.
	// Return:    A new text page for PDF text processing.
	// Remarks:   Creates a new text page for PDF text processing.
	// Notes:
	//************************************
	static	FPD_TextPage New2(FS_LPVOID pObjs, FS_INT32 flags);

	//************************************
	// Function:  New3
	// Param[in]: page		The input PDF page.
	// Param[in]: option	Text parse options.
	// Return:    A new text page for PDF text processing.
	// Remarks:   Creates a new text page for PDF text processing.
	// Notes:
	//************************************
	static	FPD_TextPage New3(FPD_Page page, FPD_Text_ParseOption option);

	//************************************
	// Function:  GetRectArray
	// Param[in]: page		        The input text page.
	// Param[in]: start		        The starting char index.
	// Param[in]: nCount	        Number of chars ( end char index - start char index).
	// Param[out]:outRectArray      It receives the rectangle array for character index interzone. [start, start+count).
	// Param[bDisplayArea]:bDisplayArea  true: Need display the area of text.
	// Return:    void
	// Remarks:   Gets the rectangle array for character index interzone. [start, start+count)
	// Notes:
	//************************************
	static	void GetRectArray2(FPD_TextPage page, FS_INT32 start, FS_INT32 nCount, FS_FloatRectArray* outRectArray, FS_BOOLEAN bDisplayArea);
	
	//************************************
	// Function:  CharIndexFromTextIndex
	// Param[in]: page		        The input text page.
	// Param[in]: textIndex		The input text index form page text.
	// Return:    FS_INT32   return character index, -1 is non-existent.
	// Remarks:   Get character index from text index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_INT32 CharIndexFromTextIndex(FPD_TextPage page, FS_INT32 textIndex);
	
	 //************************************
	 // Function:  TextIndexFromCharIndex
	 // Param[in]: page		        The input text page.
	 // Param[in]: CharIndex		The input character index form character list.
	 // Return:    FS_INT32   return text index, -1 is non-existent.
	 // Remarks:  Get text index from character index.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	 //************************************
	static FS_INT32 TextIndexFromCharIndex(FPD_TextPage page, FS_INT32 CharIndex);

	//************************************
	// Function:  GetRectArrayPathData
	// Param[in]: page		The input text page.
	// Param[in]: start		The input start position.
	// Param[in]: nCount	The input text count.
	// Param[in/out]: Paths	Get the path datas.
	// Param[in]: bDisplayArea		Whether need to didplay.
	// Return:   void
	// Remarks:   Get the path data.
	// Notes: Rember use FPDTextPageFindReleasePathData to release data.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static void GetRectArrayPathData(FPD_TextPage page, FS_INT32 start, FS_INT32 nCount, FS_PtrArray* Paths, FS_BOOLEAN bDisplayArea);
};



class CFPD_TextPageFind_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: textpage The input text page object.
	// Return:    The text searching object.
	// Remarks:   Creates text searching object from a text page.
	// Notes:
	//************************************
	static FPD_TextPageFind New(const FPD_TextPage textpage);

	//************************************
	// Function:  Destroy
	// Param[in]: find The input text searching object.
	// Return:    void
	// Remarks:   Destroys the text searching object.
	// Notes:
	//************************************
	static void	Destroy(FPD_TextPageFind find);

	//************************************
	// Function:  FindFirst
	// Param[in]: find		The input text searching object.
	// Param[in]: findwhat  What you want to find.
	// Param[in]: flags		The search flags.
	// Param[in]: startPos  The start position.
	// Return:    <a>TRUE</a> means the first match is found, otherwise <a>FALSE</a>.
	// Remarks:   Finds the first match with specified search flags, optionally with a start position.
	// Notes:
	//************************************
	static FS_BOOL FindFirst(FPD_TextPageFind find, FS_LPWSTR findwhat, FS_INT32 flags, FS_INT32 startPos);

	//************************************
	// Function:  FindNext
	// Param[in]: find	The input text searching object.
	// Return:    <a>TRUE</a> means the next match is found, otherwise not.
	// Remarks:   Finds the next match. 
	// Notes:
	//************************************
	static FS_BOOL FindNext(FPD_TextPageFind find);

	//************************************
	// Function:  FindPrev
	// Param[in]: find	The input text searching object.
	// Return:    <a>TRUE</a> means the previous match is found, otherwise not.
	// Remarks:   Finds the previous match.
	// Notes:
	//************************************
	static FS_BOOL FindPrev(FPD_TextPageFind find);

	//************************************
	// Function:  GetRectArray
	// Param[in]: find		The input text searching object.
	// Param[out]:outRects  It receives the matched rectangle array.
	// Return:    void
	// Remarks:   Gets the matched rectangle array.
	// Notes:
	//************************************
	static void	GetRectArray(FPD_TextPageFind find, FS_FloatRectArray* outRects);

	//************************************
	// Function:  GetCurOrder
	// Param[in]: find	The input text searching object.
	// Return:    The current order.
	// Remarks:   Gets the current order.
	// Notes:
	//************************************
	static FS_INT32 GetCurOrder(FPD_TextPageFind find);

	//************************************
	// Function:  GetMatchedCount
	// Param[in]: find	The input text searching object.
	// Return:    The count of current matches.
	// Remarks:   Gets the count of current matches.
	// Notes:
	//************************************
	static FS_INT32 GetMatchedCount(FPD_TextPageFind find);

	//************************************
	// Function:  GetRectPathData
	// Param[in]: find	    The input text searching object.
	// Param[in/out]: Paths	Get the rect path array.
	// Return:    void
	// Remarks:   Get matched rectangle array.
	// Notes: Rember use FPDTextPageFindReleasePathData to release data.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	//************************************
	static void GetRectPathData(FPD_TextPageFind find, FS_PtrArray* Paths);

	//************************************
	// Function:  ReleasePathData
	// Param[in]: pathArr	    The input path array.
	// Return:    void
	// Remarks:   Release path data.
	// Notes: Rember use FPDTextPageFindReleasePathData to release data.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	//************************************
	static void ReleasePathData(FS_PtrArray pathArr);
};



class CFPD_LinkExtract_V1
{
public:
	//************************************
	// Function:  New
	// Return:    An empty link extracting object.
	// Remarks:   Creates an empty link extracting object.
	// Notes:
	//************************************
	static FPD_LinkExtract New();

	//************************************
	// Function:  Destroy
	// Param[in]: extr		The input link extracting object.
	// Return:    void
	// Remarks:   Destroys the link extracting object.
	// Notes:
	//************************************
	static void	Destroy(FPD_LinkExtract extr);

	//************************************
	// Function:  ExtractLinks
	// Param[in]: extr		The input link extracting object.
	// Param[in]: textpage  The input text page.
	// Return:    <a>TRUE</a> means success, otherwise not.
	// Remarks:   Extracts links for a text page.
	// Notes:
	//************************************
	static FS_BOOL ExtractLinks(FPD_LinkExtract extr, const FPD_TextPage textpage);

	//************************************
	// Function:  CountLinks
	// Param[in]: extr		The input link extracting object.
	// Return:    The count of links in the text page. Returns -1 for error.
	// Remarks:   Gets the count of links in the text page.
	// Notes:
	//************************************
	static FS_INT32 CountLinks(FPD_LinkExtract extr);

	//************************************
	// Function:  GetURL
	// Param[in]: extr		The input link extracting object.
	// Param[in]: index		The specified index.
	// Param[out]:outURL	It receives the linked URL for specified link.
	// Return:    void
	// Remarks:   Gets the linked URL for specified link.
	// Notes:
	//************************************
	static void	GetURL(FPD_LinkExtract extr, FS_INT32 index, FS_WideString* outURL);

	//************************************
	// Function:  GetRects
	// Param[in]: extr		The input link extracting object.
	// Param[in]: index		The specified index.
	// Param[out]:outRects  It receives the rectangle array for specified link.
	// Return:    void
	// Remarks:   Gets the rectangle array for specified link.
	// Notes:
	//************************************
	static void	GetRects(FPD_LinkExtract extr, FS_INT32 index, FS_FloatRectArray* outRects);
};


#ifdef __cplusplus
};
#endif

#endif

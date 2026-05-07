

#ifndef FPD_EPUBIMPL_H
#define FPD_EPUBIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_EPUBEXPT_H
#include "../fpd_epubExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

class CFPD_EPUB_V9
{
public:

	// Epub Document 相关操作 

	static FPD_FDE_Document			Open(
		FPD_FDE_Mgr			mgr,
		FS_LPCWSTR			wszFilePath,
		FS_FLOAT			fPageWidth,
		FS_FLOAT			fPageHeight,
		FS_FLOAT			fFontSize,
		FPD_FDE_Parser*		parser,
		FPD_FDE_EPUBParseParams*	parseParams,
		FPD_FDE_EPUBStdPackage*		stdPackage);

	static void						ReleaseDocument(FPD_FDE_Parser parser, FPD_FDE_EPUBParseParams parseParams, FPD_FDE_EPUBStdPackage stdPackage);

	static FS_RESULT				Close(FPD_FDE_Document doc);

	static FS_BOOL					UnLoadDocPage(FPD_FDE_Document doc,FPD_FDE_Page pPage);

	static FS_BOOL					LoadPage(FPD_FDE_Document doc,FPD_FDE_Page pPage);

	static FS_BOOL					UnloadPage(FPD_FDE_Document doc,FPD_FDE_Page pPage);

	static FS_BOOL					LoadSection(FPD_FDE_Document doc, FPD_FDE_HSection  Section);

	static FS_BOOL					UnloadSection(FPD_FDE_Document doc, FPD_FDE_HSection  Section);

	static FPD_FDE_Parser			GetParser(FPD_FDE_Document doc);

	static FPD_FDE_Page				GetPage(FPD_FDE_Document doc, FPD_FDE_HSection hSection, FS_INT32 iPage);

	static FPD_FDE_HSection			GetDocumentSection(FPD_FDE_Document doc, FS_INT32 index);

	static FS_INT32					CountSections(FPD_FDE_Document doc);

	static FS_INT32					GetSectionIndex(FPD_FDE_Document doc, FPD_FDE_HSection hSection);

	static FS_INT32					CountPages(FPD_FDE_Document doc, FPD_FDE_HSection hSection);

	static FPD_FDE_Bookmark			GetBookmark(FPD_FDE_Document doc);

	static FS_INT32					GetNamedDest(FPD_FDE_Document doc, FS_WideString pszNamedString, FPD_FDE_HSection* hSection, FS_INT32* iPage);

	static FS_BOOL					ReParse(FPD_FDE_EPUBParseParams	parseParams, FPD_FDE_Parser pParser, FS_FLOAT fPageWidth, FS_FLOAT fPageHeight);

	// Epub Page 相关操作

	static FPD_FDE_HSection			GetPageSection(FPD_FDE_Page page);
	static void						GetPageRect(FPD_FDE_Page page, FS_FloatRect* rect);


	// Epub Bookmark 相关操作

	//Retrieve parent bookmark item
	static FPD_FDE_HBookmark	GetParentBookmark(FPD_FDE_Bookmark bookmark, FPD_FDE_HBookmark hBookmark);

	//Count all sub bookmark items. If hBookmark is NULL, it returns all root bookmarks
	static FS_INT32				CountSubBookmarks(FPD_FDE_Bookmark bookmark, FPD_FDE_HBookmark hBookmark);
 
	//Retrieve a sub bookmark item
	static FPD_FDE_HBookmark	GetSubBookmark(FPD_FDE_Bookmark bookmark, FPD_FDE_HBookmark hBookmark, FS_INT32 index);

	//Retrieve the styles of bookmark
	static FS_DWORD				GetBookmarkStyles(FPD_FDE_Bookmark bookmark, FPD_FDE_HBookmark hBookmark);
 
	//Retrieve the title of bookmark
	static void					GetBookmarkTitle(FPD_FDE_Bookmark bookmark, FPD_FDE_HBookmark hBookmark, FS_WideString wsTitle);
 
	//Retrieve the external document name, if it is an external bookmark
	static FS_BOOL				GetBookmarkExternalDocName(FPD_FDE_Bookmark bookmark, FPD_FDE_HBookmark hBookmark, FS_WideString wsTitle);
 
	//Retrieve URI string, if it is a URI bookmark
	static FS_BOOL				GetBookmarkURI(FPD_FDE_Bookmark bookmark, FPD_FDE_HBookmark hBookmark, FS_ByteString csURI);
 
	//Retreve name string, if it is a named bookmark
	static FS_BOOL				GetBookmarkNamedString(FPD_FDE_Bookmark bookmark, FPD_FDE_HBookmark hBookmark, FS_WideString wsNamedString);
 
	//Determine whether the current bookmark is opened, valid only if it contains sub bookmarks
	static FS_BOOL				IsBookmarkOpened(FPD_FDE_Bookmark bookmark, FPD_FDE_HBookmark hBookmark);



	// Epub TextSelection 相关操作

	static FPD_FDE_TextSelection	CreateTextSelection();

	//Release current object
	static void						ReleaseTextSelection(FPD_FDE_TextSelection pTextSelection);

	//Attach a page to operate
	static FS_BOOL					TextSelectionAttachPage(FPD_FDE_TextSelection pTextSelection, FPD_FDE_Page pPage);

	//Reset current state and move from start position again
	static void						TextSelectionReset(FPD_FDE_TextSelection pTextSelection);

	//Set start position, return TRUE if there is a character.
	static FS_BOOL					SetSelectStartPos(FPD_FDE_TextSelection	pTextSelection, const FS_FloatPoint* startPos);

	//Get actual position of start character
	static FS_FloatPoint			GetSelectStartPos(FPD_FDE_TextSelection	pTextSelection);

	//Get position of current character
	static FS_FloatPoint			GetSelectCurPos(FPD_FDE_TextSelection pTextSelection);

	//Select a whole word at start position
	static FS_BOOL					SelectWord(FPD_FDE_TextSelection pTextSelection);

	//Select text in the range of given rect
	static FS_BOOL					SelectRectangleText(FPD_FDE_TextSelection pTextSelection, const FS_FloatPoint* endPos, FS_BOOL bOnlyIncluded);
	
	//Select text in the range of paragraph
	static FS_BOOL					SelectParagraphText(FPD_FDE_TextSelection pTextSelection, const FS_FloatPoint* endPos, FS_BOOL bOnlyIncluded);

	//Move to next/prev character, and select it
	static FS_BOOL					SelectNextChar(FPD_FDE_TextSelection pTextSelection);
	static FS_BOOL					SelectPrevChar(FPD_FDE_TextSelection pTextSelection);

	//Move to next/prev word, and select it
	static FS_BOOL					SelectNextWord(FPD_FDE_TextSelection pTextSelection);
	static FS_BOOL					SelectPrevWord(FPD_FDE_TextSelection pTextSelection);

	//Move to next/prev line, and select it
	static FS_BOOL					SelectNextLine(FPD_FDE_TextSelection pTextSelection);
	static FS_BOOL					SelectPrevLine(FPD_FDE_TextSelection pTextSelection);

	//Get number of selected rect
	static FS_INT32					CountSelectRects(FPD_FDE_TextSelection pTextSelection);
	
	//Get selected rect by index
	static FS_BOOL					GetSelectRect(FPD_FDE_TextSelection	pTextSelection, FS_INT32 index, FS_FloatRect* rect);

	static FS_BOOL					CopySelectText(FPD_FDE_TextSelection pTextSelection, FS_WideString wsStr);



	// Epub TextSearch 相关操作

	static FPD_FDE_TextSearch		CreateTextSearch();

	//Release current object
	static void						ReleaseTextSearch(FPD_FDE_TextSearch pTextSearch);

	//Attach a page to operate
	static FS_BOOL					TextSearchAttachPage(FPD_FDE_TextSearch pTextSearch, FPD_FDE_Page pPage) ;

	//Find the first match from startPos(0 for from beginning of page, -1 for from end of page)
	static FPD_FDE_SEARCHRESULT		FindFirst(FPD_FDE_TextSearch pTextSearch, FS_LPCWSTR lpszFindWhat, FS_DWORD flags, FS_INT32 startPos);

	//Find the next match, pass pNextPage if you want to search 
	static FPD_FDE_SEARCHRESULT		FindNext(FPD_FDE_TextSearch pTextSearch);

	//Find the previous match, pass pNextPage if needed
	static FPD_FDE_SEARCHRESULT		FindPrev(FPD_FDE_TextSearch pTextSearch);

	//Get current search position
	static FS_INT32					GetSearchPos(FPD_FDE_TextSearch pTextSearch);

	//Get number of matched rect
	static FS_INT32					CountSearchRects(FPD_FDE_TextSearch pTextSearch);

	//Get matched rect by index, return value is page index
	static FS_INT32					GetSearchRect(FPD_FDE_TextSearch pTextSearch, FS_INT32 index, FS_FloatRect* rect);

	//设备坐标与文档坐标转换 相关操作 

	static void						Transfer2DocPoint(FPD_FDE_Page pPage, FS_Rect devicePageRect,const FS_FloatPoint* devPt, FS_FloatPoint* docPt);

	static void						Transfer2DocPointRect(FPD_FDE_Page pPage, FS_Rect devicePageRect, FS_FloatRect* rect);

	static void						FDEGetPageMatrix(FS_AffineMatrix* pageMatrix, const FS_FloatRect* docPageRect, const FS_Rect* devicePageRect, FS_INT32 iRotate);

	//IFDE_Render   相关操作

	static	FPD_FDE_RenderDevice	CreateRenderDevice(FS_DIBitmap bitmap);
	static	void					ReleaseRenderDevice(FPD_FDE_RenderDevice device);
	static	FS_BOOL					RenderDeviceSetClipRect(FPD_FDE_RenderDevice device, FS_FloatRect* rtClip);

	static	FPD_FDE_RenderContext	CreateRenderContext();
	static	void					ReleaseRenderContext(FPD_FDE_RenderContext pRenderContext);
	static	FS_DIBitmap				RenderContextRendering(FPD_FDE_RenderContext pRenderContext,FPD_FDE_Page pPage, FS_INT32 iRotate,FS_Rect rendingRect,FS_Rect devicePageRect);
	static	void					DoRender(FPD_FDE_RenderContext context, FPD_FDE_RenderDevice device, FPD_FDE_Page page, FS_AffineMatrix* matrix);

	// Epub View 相关操作

	static	FS_ARGB					EpubArgbEncode(FS_INT32 a, FS_COLORREF rgb);
	static	FPD_FDE_Mgr				InitFDEMgr();
	static	void					ReleaseFDEMgr(FPD_FDE_Mgr mgr);
};


#ifdef __cplusplus
};
#endif

#endif//FPD_EPUBIMPL_H

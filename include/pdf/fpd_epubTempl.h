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
//*****************************
/* EPUB HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_FDE_Document, FPDEPUBOpen, (FPD_FDE_Mgr			mgr,  FS_LPCWSTR			wszFilePath,  FS_FLOAT			fPageWidth,  FS_FLOAT			fPageHeight,  FS_FLOAT			fFontSize,  FPD_FDE_Parser*		parser,  FPD_FDE_EPUBParseParams*	parseParams,  FPD_FDE_EPUBStdPackage*		stdPackage))

INTERFACE(void, FPDEPUBReleaseDocument, (FPD_FDE_Parser parser,  FPD_FDE_EPUBParseParams parseParams,  FPD_FDE_EPUBStdPackage stdPackage))

INTERFACE(FS_RESULT, FPDEPUBClose, (FPD_FDE_Document doc))

INTERFACE(FS_BOOL, FPDEPUBUnLoadDocPage, (FPD_FDE_Document doc,  FPD_FDE_Page pPage))

INTERFACE(FS_BOOL, FPDEPUBLoadPage, (FPD_FDE_Document doc,  FPD_FDE_Page pPage))

INTERFACE(FS_BOOL, FPDEPUBUnloadPage, (FPD_FDE_Document doc,  FPD_FDE_Page pPage))

INTERFACE(FS_BOOL, FPDEPUBLoadSection, (FPD_FDE_Document doc,  FPD_FDE_HSection  Section))

INTERFACE(FS_BOOL, FPDEPUBUnloadSection, (FPD_FDE_Document doc,  FPD_FDE_HSection  Section))

INTERFACE(FPD_FDE_Parser, FPDEPUBGetParser, (FPD_FDE_Document doc))

INTERFACE(FPD_FDE_Page, FPDEPUBGetPage, (FPD_FDE_Document doc,  FPD_FDE_HSection hSection,  FS_INT32 iPage))

INTERFACE(FPD_FDE_HSection, FPDEPUBGetDocumentSection, (FPD_FDE_Document doc,  FS_INT32 index))

INTERFACE(FS_INT32, FPDEPUBCountSections, (FPD_FDE_Document doc))

INTERFACE(FS_INT32, FPDEPUBGetSectionIndex, (FPD_FDE_Document doc,  FPD_FDE_HSection hSection))

INTERFACE(FS_INT32, FPDEPUBCountPages, (FPD_FDE_Document doc,  FPD_FDE_HSection hSection))

INTERFACE(FPD_FDE_Bookmark, FPDEPUBGetBookmark, (FPD_FDE_Document doc))

INTERFACE(FS_INT32, FPDEPUBGetNamedDest, (FPD_FDE_Document doc,  FS_WideString pszNamedString,  FPD_FDE_HSection* hSection,  FS_INT32* iPage))

INTERFACE(FS_BOOL, FPDEPUBReParse, (FPD_FDE_EPUBParseParams	parseParams,  FPD_FDE_Parser pParser,  FS_FLOAT fPageWidth,  FS_FLOAT fPageHeight))

INTERFACE(FPD_FDE_HSection, FPDEPUBGetPageSection, (FPD_FDE_Page page))

INTERFACE(void, FPDEPUBGetPageRect, (FPD_FDE_Page page,  FS_FloatRect* rect))

INTERFACE(FPD_FDE_HBookmark, FPDEPUBGetParentBookmark, (FPD_FDE_Bookmark bookmark,  FPD_FDE_HBookmark hBookmark))

INTERFACE(FS_INT32, FPDEPUBCountSubBookmarks, (FPD_FDE_Bookmark bookmark,  FPD_FDE_HBookmark hBookmark))

INTERFACE(FPD_FDE_HBookmark, FPDEPUBGetSubBookmark, (FPD_FDE_Bookmark bookmark,  FPD_FDE_HBookmark hBookmark,  FS_INT32 index))

INTERFACE(FS_DWORD, FPDEPUBGetBookmarkStyles, (FPD_FDE_Bookmark bookmark,  FPD_FDE_HBookmark hBookmark))

INTERFACE(void, FPDEPUBGetBookmarkTitle, (FPD_FDE_Bookmark bookmark,  FPD_FDE_HBookmark hBookmark,  FS_WideString wsTitle))

INTERFACE(FS_BOOL, FPDEPUBGetBookmarkExternalDocName, (FPD_FDE_Bookmark bookmark,  FPD_FDE_HBookmark hBookmark,  FS_WideString wsTitle))

INTERFACE(FS_BOOL, FPDEPUBGetBookmarkURI, (FPD_FDE_Bookmark bookmark,  FPD_FDE_HBookmark hBookmark,  FS_ByteString csURI))

INTERFACE(FS_BOOL, FPDEPUBGetBookmarkNamedString, (FPD_FDE_Bookmark bookmark,  FPD_FDE_HBookmark hBookmark,  FS_WideString wsNamedString))

INTERFACE(FS_BOOL, FPDEPUBIsBookmarkOpened, (FPD_FDE_Bookmark bookmark,  FPD_FDE_HBookmark hBookmark))

INTERFACE(FPD_FDE_TextSelection, FPDEPUBCreateTextSelection, ())

INTERFACE(void, FPDEPUBReleaseTextSelection, (FPD_FDE_TextSelection pTextSelection))

INTERFACE(FS_BOOL, FPDEPUBTextSelectionAttachPage, (FPD_FDE_TextSelection pTextSelection,  FPD_FDE_Page pPage))

INTERFACE(void, FPDEPUBTextSelectionReset, (FPD_FDE_TextSelection pTextSelection))

INTERFACE(FS_BOOL, FPDEPUBSetSelectStartPos, (FPD_FDE_TextSelection	pTextSelection,  const FS_FloatPoint* startPos))

INTERFACE(FS_FloatPoint, FPDEPUBGetSelectStartPos, (FPD_FDE_TextSelection	pTextSelection))

INTERFACE(FS_FloatPoint, FPDEPUBGetSelectCurPos, (FPD_FDE_TextSelection pTextSelection))

INTERFACE(FS_BOOL, FPDEPUBSelectWord, (FPD_FDE_TextSelection pTextSelection))

INTERFACE(FS_BOOL, FPDEPUBSelectRectangleText, (FPD_FDE_TextSelection pTextSelection,  const FS_FloatPoint* endPos,  FS_BOOL bOnlyIncluded))

INTERFACE(FS_BOOL, FPDEPUBSelectParagraphText, (FPD_FDE_TextSelection pTextSelection,  const FS_FloatPoint* endPos,  FS_BOOL bOnlyIncluded))

INTERFACE(FS_BOOL, FPDEPUBSelectNextChar, (FPD_FDE_TextSelection pTextSelection))

INTERFACE(FS_BOOL, FPDEPUBSelectPrevChar, (FPD_FDE_TextSelection pTextSelection))

INTERFACE(FS_BOOL, FPDEPUBSelectNextWord, (FPD_FDE_TextSelection pTextSelection))

INTERFACE(FS_BOOL, FPDEPUBSelectPrevWord, (FPD_FDE_TextSelection pTextSelection))

INTERFACE(FS_BOOL, FPDEPUBSelectNextLine, (FPD_FDE_TextSelection pTextSelection))

INTERFACE(FS_BOOL, FPDEPUBSelectPrevLine, (FPD_FDE_TextSelection pTextSelection))

INTERFACE(FS_INT32, FPDEPUBCountSelectRects, (FPD_FDE_TextSelection pTextSelection))

INTERFACE(FS_BOOL, FPDEPUBGetSelectRect, (FPD_FDE_TextSelection	pTextSelection,  FS_INT32 index,  FS_FloatRect* rect))

INTERFACE(FS_BOOL, FPDEPUBCopySelectText, (FPD_FDE_TextSelection pTextSelection,  FS_WideString wsStr))

INTERFACE(FPD_FDE_TextSearch, FPDEPUBCreateTextSearch, ())

INTERFACE(void, FPDEPUBReleaseTextSearch, (FPD_FDE_TextSearch pTextSearch))

INTERFACE(FS_BOOL, FPDEPUBTextSearchAttachPage, (FPD_FDE_TextSearch pTextSearch,  FPD_FDE_Page pPage))

INTERFACE(FPD_FDE_SEARCHRESULT, FPDEPUBFindFirst, (FPD_FDE_TextSearch pTextSearch,  FS_LPCWSTR lpszFindWhat,  FS_DWORD flags,  FS_INT32 startPos))

INTERFACE(FPD_FDE_SEARCHRESULT, FPDEPUBFindNext, (FPD_FDE_TextSearch pTextSearch))

INTERFACE(FPD_FDE_SEARCHRESULT, FPDEPUBFindPrev, (FPD_FDE_TextSearch pTextSearch))

INTERFACE(FS_INT32, FPDEPUBGetSearchPos, (FPD_FDE_TextSearch pTextSearch))

INTERFACE(FS_INT32, FPDEPUBCountSearchRects, (FPD_FDE_TextSearch pTextSearch))

INTERFACE(FS_INT32, FPDEPUBGetSearchRect, (FPD_FDE_TextSearch pTextSearch,  FS_INT32 index,  FS_FloatRect* rect))

INTERFACE(void, FPDEPUBTransfer2DocPoint, (FPD_FDE_Page pPage,  FS_Rect devicePageRect,  const FS_FloatPoint* devPt,  FS_FloatPoint* docPt))

INTERFACE(void, FPDEPUBTransfer2DocPointRect, (FPD_FDE_Page pPage,  FS_Rect devicePageRect,  FS_FloatRect* rect))

INTERFACE(void, FPDEPUBFDEGetPageMatrix, (FS_AffineMatrix* pageMatrix,  const FS_FloatRect* docPageRect,  const FS_Rect* devicePageRect,  FS_INT32 iRotate))

INTERFACE(FPD_FDE_RenderDevice, FPDEPUBCreateRenderDevice, (FS_DIBitmap bitmap))

INTERFACE(void, FPDEPUBReleaseRenderDevice, (FPD_FDE_RenderDevice device))

INTERFACE(FS_BOOL, FPDEPUBRenderDeviceSetClipRect, (FPD_FDE_RenderDevice device,  FS_FloatRect* rtClip))

INTERFACE(FPD_FDE_RenderContext, FPDEPUBCreateRenderContext, ())

INTERFACE(void, FPDEPUBReleaseRenderContext, (FPD_FDE_RenderContext pRenderContext))

INTERFACE(FS_DIBitmap, FPDEPUBRenderContextRendering, (FPD_FDE_RenderContext pRenderContext,  FPD_FDE_Page pPage,  FS_INT32 iRotate,  FS_Rect rendingRect,  FS_Rect devicePageRect))

INTERFACE(void, FPDEPUBDoRender, (FPD_FDE_RenderContext context,  FPD_FDE_RenderDevice device,  FPD_FDE_Page page,  FS_AffineMatrix* matrix))

INTERFACE(FS_ARGB, FPDEPUBEpubArgbEncode, (FS_INT32 a,  FS_COLORREF rgb))

INTERFACE(FPD_FDE_Mgr, FPDEPUBInitFDEMgr, ())

INTERFACE(void, FPDEPUBReleaseFDEMgr, (FPD_FDE_Mgr mgr))

NumOfSelector(FPDEPUB)
ENDENUM

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

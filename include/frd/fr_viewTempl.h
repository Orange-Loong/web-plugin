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
/* DocView HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRDocViewGetDocument
 * @details Gets the <a>FR_Document</a> associated with specifed document view..
 * @param[in]  docView The document view whose <a>FR_Document</a>is obtained.
 * @return   The <a>FR_Document</a> associated with the document view.
 * @note 
 * @see FRDocGetDocView
 * @see FRDocGetCurrentDocView
 * @see FRDocViewGetPageView
 * @see FRPageViewGetDocument
 */
INTERFACE(FR_Document, FRDocViewGetDocument, (FR_DocView docView))

/**
 * @brief FRDocViewCountPageViews
 * @details Gets the number of page views for the specified document view.
 * @param[in]  docView The document view whose page view count is obtained.
 * @return   The number of <a>FR_PageView</a> object associated with the document view.
 * @note 
 * @see FRDocViewGetPageView
 * @see FRDocViewCountVisiblePageViews
 */
INTERFACE(FS_INT32, FRDocViewCountPageViews, (FR_DocView docView))

/**
 * @brief FRDocViewGetPageView
 * @details Gets the specified <a>FR_PageView</a> for specified document view.
 * @param[in]  docView The document view whose <a>FR_PageView</a> is obtained.
 * @param[in]  iPage The index of page view to obtain. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
 * @return   The specified <a>FR_PageView</a> of the document view.
 * @note 
 * @see FRDocViewCountPageViews
 * @see FRDocViewGetVisiblePageView
 * @see FRDocViewGetPageViewAtPoint
 * @see FRDocViewGetCurrentPageView
 */
INTERFACE(FR_PageView, FRDocViewGetPageView, (FR_DocView docView,  FS_INT32 iPage))

/**
 * @brief FRDocViewGetPageViewAtPoint
 * @details Gets a specified <a>FR_PageView</a> with a point which is underlying to the area of page view.
 * @param[in]  docView The document view whose <a>FR_PageView</a> is obtained.
 * @param[in]  point The point of screen coordinate system to obtain a page view.
 * @return   The specified <a>FR_PageView</a> of the document view if the point is in the area of the page view, otherwise 
    * <a>NULL</a>.
 * @note 
 * @see FRDocViewGetPageView
 * @see FRDocViewGetVisiblePageView
 * @see FRDocViewGetCurrentPageView
 */
INTERFACE(FR_PageView, FRDocViewGetPageViewAtPoint, (FR_DocView docView,  FS_DevicePoint point))

/**
 * @brief FRDocViewCountVisiblePageViews
 * @details Gets the number of visible page views for specified document view.
 * @param[in]  docView The document view whose page view count is obtained.
 * @return   The number of visible page views.
 * @note 
 * @see FRDocViewCountPageViews
 */
INTERFACE(FS_INT32, FRDocViewCountVisiblePageViews, (FR_DocView docView))

/**
 * @brief FRDocViewGetVisiblePageView
 * @details Gets the specified visible page.
 * @param[in]  docView The document view whose page view is obtained.
 * @param[in]  iPage The index of the visible page. The index range is 0 to (<a>FRDocViewCountVisiblePageViews</a>()-1).
 * @return   The specified <a>FR_PageView</a>	of the document view.
 * @note 
 * @see FRDocViewGetPageView
 * @see FRDocViewGetPageViewAtPoint
 * @see FRDocViewGetCurrentPageView
 */
INTERFACE(FR_PageView, FRDocViewGetVisiblePageView, (FR_DocView docView,  FS_INT32 iPage))

/**
 * @brief FRDocViewGotoPageView
 * @details Goes to specified page, retaining the current display mode. It invalidates the display, but not
    * always perform an immediately redraw.
 * @param[in]  docView The document view whose page view to go to.
 * @param[in]  iPage The specified page index. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
 * @return   void
 * @note 
 * @see FRDocViewGotoPageViewByPoint
 * @see FRDocViewGotoPageViewByRect
 */
INTERFACE(void, FRDocViewGotoPageView, (FR_DocView docView,  FS_INT32 iPage))

/**
 * @brief FRDocViewGotoPageViewByPoint
 * @details Goes to specified page and scroll page view to the location specified by <param>left</param> and <param>top</param>, retaining the 
    * current display mode. It invalidates the display, but not always perform an immediately redraw.
 * @param[in]  docView The document view whose page view to go to.
 * @param[in]  iPage The specified page index. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
 * @param[in]  left The x-coordinate to scroll to. Specified in PDF space coordinates.
 * @param[in]  top The y-coordinate to scroll to. Specified in PDF space coordinates.
 * @return   void
 * @note 
 * @see FRDocViewGotoPageView
 * @see FRDocViewGotoPageViewByRect
 */
INTERFACE(void, FRDocViewGotoPageViewByPoint, (FR_DocView docView,  FS_INT32 iPage,  FS_FLOAT left,  FS_FLOAT top))

/**
 * @brief FRDocViewGotoPageViewByRect
 * @details Goes to specified page view and scroll to center of the rectangle. It always change the zoom level if necessary.
 * @param[in]  docView The document view whose page view to go to.
 * @param[in]  iPage The index of the visible page. The index range is 0 to (<a>FRDocViewCountVisiblePageViews</a>()-1).
 * @param[in]  rect The rectangle that is completely visible, that is, the visible area of the document view will change the zoom of the view according to the size of the area.
 * @return   void
 * @note It need use FRDocViewGotoPageView to go to specified page.
 * @see FRDocViewGotoPageView
 * @see FRDocViewGotoPageViewByPoint
 */
INTERFACE(void, FRDocViewGotoPageViewByRect, (FR_DocView docView,  FS_INT32 iPage,  FS_FloatRect rect))

/**
 * @brief FRDocViewGetCurrentPageView
 * @details Gets current page view that is visible in screen.
 * @param[in]  docView The document.
 * @return   Current <a>FR_PageView</a> that is visible in screen.
 * @note If more than one page may be visible. use FRDocViewCountVisiblePageViews() and FRDocViewGetVisiblePageView() instead.
 * @see FRDocViewGetPageView
 * @see FRDocViewGetPageViewAtPoint
 * @see FRDocViewGetGetVisiblePageView
 */
INTERFACE(FR_PageView, FRDocViewGetCurrentPageView, (FR_DocView docView))

/**
 * @brief FRDocViewGetRotation
 * @details Gets the rotation factor.
 * @param[in]  docView The document view to obtain rotation factor.
 * @return   A integer described in group <a>FR_RotationFlags</a>(for example: FR_ROTATE_POS_TOP).
 * @note 
 * @see 
 */
INTERFACE(FS_INT32, FRDocViewGetRotation, (FR_DocView docView))

/**
 * @brief FRDocViewSetRotation
 * @details Sets the rotation factor.
 * @param[in]  docView The document view to obtain rotation factor.
 * @param[in]  nFlag A integer described in group <a>FR_RotationFlags</a>(for example: FR_ROTATE_POS_TOP).
 * @return   void
 * @note 
 * @see 
 */
INTERFACE(void, FRDocViewSetRotation, (FR_DocView docView,  FS_INT32 nFlag))

/**
 * @brief FRDocViewGetLayoutMode
 * @details Gets the page layout mode.
 * @param[in]  docView The document view whose layout mode is obtained.
 * @return   The current page layout mode, a <a>FRDOC_LAYOUTMODE</a> enumeration value.
 * @note 
 */
INTERFACE(FRDOCVIEW_LAYOUTMODE, FRDocViewGetLayoutMode, (FR_DocView docView))

/**
 * @brief FRDocViewSetLayoutMode
 * @details Sets the page layout mode for a document view.
 * @param[in]  docView The document view whose layout mode is set.
 * @param[in]  mode The new layout mode for document view.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocViewSetLayoutMode, (FR_DocView docView,  FRDOCVIEW_LAYOUTMODE mode))

/**
 * @brief FRDocViewGetZoom
 * @details Gets the current zoom for page view. The zoom factor is point-to-point, not point-to-pixel.
 * @param[in]  docView The document view.
 * @return   The current zoom for page view.
 * @note Current zoom, as a fixed number measured in units in which 1.0 is 100% zoom.
 * @see FRDocViewGetZoomType
 * @see FRDocViewZoomTo
 */
INTERFACE(FS_FLOAT, FRDocViewGetZoom, (FR_DocView docView))

/**
 * @brief FRDocViewGetZoomType
 * @details Gets the current zoom type.
 * @param[in]  docView The document view.
 * @return   Current zoom type.
 * @note 
 * @see FRDocViewGetZoom
 * @see FRDocViewZoomTo
 */
INTERFACE(FRDOCVIEW_ZOOMTYPE, FRDocViewGetZoomType, (FR_DocView docView))

/**
 * @brief FRDocViewZoomTo
 * @details Sets the zoom factor and zoom type to specified page view.
 * @param[in]  docView The document view.
 * @param[in]  mode The zoom mode to set.
 * @param[in]  scale The zoom factor, specified as a magnification factor(for example,
    * 1.0 displays the document at actual size). This is ignore unless <param>mode</param> is
    * <a>FR_ZOOM_MODE_ACTUAL_SCALE</a> or <a>FR_ZOOM_MODE_AUTOMATIC</a>.
 * @return   void
 * @note 
 * @see FRDocViewGetZoom
 * @see FRDocViewGetZoomType
 */
INTERFACE(void, FRDocViewZoomTo, (FR_DocView docView,  FRDOCVIEW_ZOOMTYPE mode,  FS_FLOAT scale))

/**
 * @brief FRDocViewGoBack
 * @details Goes to the previous view on the view stack, if a previous view exist.
 * @param[in]  docView The document view.
 * @return   void
 * @note 
 * @see FRDocViewGoForward
 */
INTERFACE(void, FRDocViewGoBack, (FR_DocView docView))

/**
 * @brief FRDocViewGoForward
 * @details Goes to the next view on the view stack, if a next view exist.
 * @param[in]  docView The document view.
 * @return   void
 * @note 
 * @see FRDocViewGoBack
 */
INTERFACE(void, FRDocViewGoForward, (FR_DocView docView))

/**
 * @brief FRDocViewShowAnnots
 * @details If <param>bShow</param> is set <a>TRUE</a>, the annotations will be shown. Otherwise not. This interface is not available in version 1.0.
 * @param[in]  docView The document view.
 * @param[in]  annots The array of annotations to be shown.
 * @param[in]  bShow Whether to show or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocViewShowAnnots, (FR_DocView docView,  FS_PtrArray* annots,  FS_BOOL bShow))

/**
 * @brief FRDocViewProcAction
 * @details Performs a specified action.
 * @param[in]  docView The document view.
 * @param[in]  action A <a>FPD_Action</a> object to be performed.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocViewProcAction, (FR_DocView docView,  FPD_Action action))

/**
 * @brief FRDocViewScrollTo
 * @details Scrolls the specified document view by <param>x</param> and <param>y</param> the specified distance.
 * @param[in]  docView The document view to scroll.
 * @param[in]  x The x-axis distance to scroll, specified in the device space coordinates.
 * @param[in]  y The y-axis distance to scroll, specified in the device space coordinates.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocViewScrollTo, (FR_DocView docView,  FS_INT32 x,  FS_INT32 y))

/**
 * @brief FRDocViewGetMaxScrollingSize
 * @details Gets the maximum scrolling size of the document view.
 * @param[in]  docView The input document view.
 * @param[out]  outWidth It receives the horizontal maximum scrolling size.
 * @param[out]  outHeight It receives the vertical maximum scrolling size.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocViewGetMaxScrollingSize, (FR_DocView docView,  FS_INT32* outWidth,  FS_INT32* outHeight))

/**
 * @brief FRDocViewDrawNow
 * @details Forces specified document view to redraw.
 * @param[in]  docView The document view to redraw.
 * @return   void
 * @note 
 * @see FRDocViewInvalidateRect
 */
INTERFACE(void, FRDocViewDrawNow, (FR_DocView docView))

/**
 * @brief FRDocViewInvalidateRect
 * @details Redraws the specified area of document view immediately.
 * @param[in]  docView The document view in which a region is invalidated.
 * @param[in]  rect The rectangle to invalidate, specified in device space coordinates.
 * @return   void
 * @note 
 * @see FRDocViewDrawNow
 */
INTERFACE(void, FRDocViewInvalidateRect, (FR_DocView docView,  FS_Rect rect))

/**
 * @brief FRDocViewDrawRect
 * @details Draws rectangle in the doc view.
 * @param[in]  docView The input doc view.
 * @param[in]  rect The input rectangle.
 * @param[in]  fill_argb The color to fill.
 * @param[in]  bCompose Whether to compose or not.
 * @return   void
 * @note The function can only be used for Windows.
 */
INTERFACE(void, FRDocViewDrawRect, (FR_DocView docView,  FS_Rect rect,  FS_ARGB fill_argb,  FS_BOOL bCompose))

/**
 * @brief FRDocViewDoPopUpMenu
 * @details Displays the given menu as a pop-up menu anchored at <param>xHi</param>t and <param>yHit</param>, which are in device
    * space coordinates relative to <param>docView</param>.
 * @param[in]  docView The document view in which the menu appears.
 * @param[in]  menu The displayed menu.
 * @param[in]  xHit The x-coordinate of the upper left corner of the menu.
 * @param[in]  yHit The y-coordinate of the upper left corner of the menu.
 * @return   The menu item clicked by user.
 * @note The function can only be used for Windows.
 * @see FRMenuTrackPopup
 */
INTERFACE(FR_MenuItem, FRDocViewDoPopUpMenu, (FR_DocView docView,  FR_Menu menu,  FS_INT32 xHit,  FS_INT32 yHit))

/**
 * @brief FRDocViewGetMachinePort
 * @details Gets the platform-specific object needed to draw into page view using a platform's native 
    * graphic calls. It is a <a>FR_WinPort</a> object which contain the <Italic>FS_HWND</Italic> handler and
    * the device context. When done, release it using <a>FRDocViewReleaseMachinePort</a>().
 * @param[in]  docView The document view whose <Italic>FS_HWND</Italic> handler and device context are obtained.
 * @return   The <a>FR_WinPort</a> object.
 * @note The function can only be used for Windows.
 * @see FRDocViewReleaseMachinePort
 */
INTERFACE(FR_WinPort, FRDocViewGetMachinePort, (FR_DocView docView))

/**
 * @brief FRDocViewReleaseMachinePort
 * @details Releases a <a>FR_WinPort</a> that acquired form page view using <a>FRDocViewGetMachinePort</a>().
 * @param[in]  docView The document view whose <Italic>FS_HWND</Italic> handler and device context are released.
 * @param[in]  port The platform-dependent object to release.
 * @return   <a>TRUE</a> means release machine port successful, otherwise not.
 * @note The function can only be used for Windows.
 * @see FRDocViewGetMachinePort
 */
INTERFACE(FS_BOOL, FRDocViewReleaseMachinePort, (FR_DocView docView,  FR_WinPort port))

/**
 * @brief FRDocViewGetOCContext
 * @details Gets the <Italic>OCG</Italic> context of Reader doc view.
 * @param[in]  docView The document view whose ocg context are obtained.
 * @return   The <Italic>OCG</Italic> context of Reader doc view.
 * @note 
 */
INTERFACE(FPD_OCContext, FRDocViewGetOCContext, (FR_DocView docView))

/**
 * @brief FRDocViewGetCurrentSnapshot
 * @details Gets current snapshot image that generated by using snapshot tool.
 * @param[in]  docView The document view whose snapshot image are obtained.
 * @return   A <a>FS_DIBitmap</a> object indicates current snapshot image. This <a>FS_DIBitmap</a> object must be destroied by calling
    * <a>FSDIBitmapDestroy</a>().
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRDocViewGetCurrentSnapshot, (FR_DocView docView))

/**
 * @brief FRDocViewGetThumbnailView
 * @details Gets the thumbnail view related to the input document view.
 * @param[in]  docView The input document view.
 * @return   A <a>FR_ThumbnailView</a> object related to the input document view.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FR_ThumbnailView, FRDocViewGetThumbnailView, (FR_DocView docView))

/**
 * @brief FRDocViewGotoPageViewByState
 * @details Goes to the page view by state.
 * @param[in]  docView The document view whose page view to go to.
 * @param[in]  iPage The specified page index. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
 * @param[in]  iFitType The input fit type.
 * @param[in]  destArray The input destination array.
 * @param[in]  destArrayCount The count of the destination array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRDocViewGotoPageViewByPoint
 * @see FRDocViewGotoPageViewByRect
    
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocViewGotoPageViewByState, (FR_DocView docView,  FS_INT32 iPage,  FS_INT32 iFitType,  FS_FLOAT* destArray,  FS_INT32 destArrayCount))

/**
 * @brief FRDocViewMovePage
 * @details Moves the page, the target point to which the original point of the page is moved.
 * @param[in]  docView The document view.
 * @param[in]  ptDest The dest point.
 * @param[in]  ptSrc The source point.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(void, FRDocViewMovePage, (FR_DocView docView,  FS_DevicePoint ptDest,  FS_DevicePoint ptSrc))

/**
 * @brief FRDocViewIsValidPageView
 * @details Checks whether the page view is valid or not.
 * @param[in]  docView The document view.
 * @param[in]  pPageView The page view.
 * @return   <a>TRUE</a> if the page view is valid, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_BOOL, FRDocViewIsValidPageView, (FR_DocView docView,  FR_PageView pPageView))

/**
 * @brief FRDocViewGetTagDocViewText
 * @details Get the text content of all tags in the page under the input index, the text order is in accordance with the tag order.
 * @param[in]  docView The document view.
 * @param[out]  outText It receives the text got.
 * @param[in]  nCount The index of the page view, -1 for the current page view.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(void, FRDocViewGetTagDocViewText, (FR_DocView docView,  FS_WideString* outText,  FS_INT32 nCount))

/**
 * @brief FRDocViewGetLRDocViewText
 * @details Get all the text content in the page under the input index, the text order is in accordance with the creation order of the text object.
 * @param[in]  docView The document view.
 * @param[out]  outText It receives the text got.
 * @param[in]  nCount The index of the page view, -1 for the current page view.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(void, FRDocViewGetLRDocViewText, (FR_DocView docView,  FS_WideString* outText,  FS_INT32 nCount))

/**
 * @brief FRDocViewGetWnd
 * @details Gets docview hwnd.
 * @param[in]  docView The document view.
 * @return   FS_HWND
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(FS_HWND, FRDocViewGetWnd, (FR_DocView docView))

/**
 * @brief FRDocViewScrollToCenterPoint
 * @details Scroll the center point to the specified point of the input page index,
 * @param[in]  docView The document view.
 * @param[in]  index The page index.
 * @param[in]  pdfPoint The point to scroll.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(void, FRDocViewScrollToCenterPoint, (FR_DocView docView,  FS_INT32 index,  FS_FloatPoint pdfPoint))

/**
 * @brief FRDocViewSetRenderDataChange
 * @details Set render data change in the document view.
 * @param[in]  docView The document view.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(void, FRDocViewSetRenderDataChange, (FR_DocView docView))

/**
 * @brief FRDocViewGotoPageViewByAnnot
 * @details Go to the page where annot is located.
 * @param[in]  docView The document view.
 * @param[in]  pAnnot The annot object, it will go to the pageview contains the annot.
 * @return   <a>TRUE</a> If go to pageview success. otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0
 */
INTERFACE(FS_BOOLEAN, FRDocViewGotoPageViewByAnnot, (FR_DocView docView,  FR_Annot pAnnot))

/**
 * @brief FRDocViewGotoPageByDest
 * @details Go the dest position of the document.
 * @param[in]  docView The document view.
 * @param[in]  dest The dest postion of the document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0
 */
INTERFACE(void, FRDocViewGotoPageByDest, (FR_DocView docView,  FPD_Dest dest))

/**
 * @brief FRDocViewGetHwnd
 * @details Gets docview hwnd.
 * @param[in]  docView The document view.
 * @return   FS_HWND
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(FS_HWND, FRDocViewGetHwnd, (FR_DocView docView))

/**
 * @brief FRDocViewGetRBDPageView
 * @details Gets the page view which right click on.
 * @param[in]  docView The document view.
 * @return   FR_PageView
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 * @Deprecated    Internal use.
 */
INTERFACE(FR_PageView, FRDocViewGetRBDPageView, (FR_DocView docView))

/**
 * @brief FRDocViewUpdateStatusBarPagesInfo
 * @details Update page info in the status bar.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocViewUpdateStatusBarPagesInfo, (FR_DocView docView))

/**
 * @brief FRDocViewGotoPageViewByRect2
 * @details Goes to specified page view and scroll to center of the rectangle. It always change the zoom level if necessary.
 * @param[in]  docView The document view whose page view to go to.
 * @param[in]  iPage The index of the visible page. The index range is 0 to (<a>FRDocViewCountVisiblePageViews</a>()-1).
 * @param[in]  rect The rectangle that is completely visible, that is, the visible area of the document view will change the zoom of the view according to the size of the area.
 * @param[in]  isTopUp Whether rect needs to be at the top of the view, default is false.
 * @param[in]  dbMaxScale The input max scale, default is 64, and need set bellow to 64.
 * @return   void
 * @note It need ensure the FR_PageView exists, if not it need call FRDocViewGotoPageView to go to specified page first.
 * @see FRDocViewGotoPageView
 * @see FRDocViewGotoPageViewByPoint
 */
INTERFACE(FS_BOOLEAN, FRDocViewGotoPageViewByRect2, (FR_DocView docView,  FS_INT32 index,  FS_FloatRect rect,  FS_BOOLEAN isTopUp,  FS_FLOAT dbMaxScale))

/**
 * @brief FRDocViewUpdateAllViews
 * @details Update all page views.
 * @param[in]  docView The document view.
 * @param[in]  doc The input doc.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocViewUpdateAllViews, (FR_DocView docView,  FR_Document doc))

/**
 * @brief FRDocViewUpdateAllNotes
 * @details Update all notes.
 * @param[in]  doc The input doc.
 * @param[in]  csType The input annot type.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocViewUpdateAllNotes, (FR_Document doc,  FS_LPCSTR csType))

/**
 * @brief FRDocViewIsAutoScrolling
 * @details Check the current doc view is auto scrolling.
 * @param[in]  docView The input FR_DocView.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRDocGetDocView
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocViewIsAutoScrolling, (FR_DocView docView))

/**
 * @brief FRDocViewScrollTo2
 * @details Scrolls the specified document view by <param>x</param> and <param>y</param> the specified distance.
 * @param[in]  docView The document view to scroll.
 * @param[in]  x The x-axis distance to scroll, specified in the device space coordinates.
 * @param[in]  y The y-axis distance to scroll, specified in the device space coordinates.
 * @return   FS_DevicePoint      Get the position after scroll.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_DevicePoint, FRDocViewScrollTo2, (FR_DocView docView,  FS_INT32 x,  FS_INT32 y))

NumOfSelector(FRDocView)
ENDENUM

//*****************************
/* PageView HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPageViewGetDocument
 * @details Gets the <a>FR_Document</a> for the document currently displayed in specified pageview.
 * @param[in]  pv The page view whose <a>FR_Document</a> is obtained.
 * @return   The <a>FR_Document</a> for <param>pv</param>.
 * @note 
 * @see FRDocViewGetDocument
 * @see FRPageViewGetDocView
 */
INTERFACE(FR_Document, FRPageViewGetDocument, (FR_PageView pv))

/**
 * @brief FRPageViewGetDocView
 * @details Gets the <a>FR_DocView</a> for specified pageview.
 * @param[in]  pv The page view whose <a>FR_DocView</a> is obtained.
 * @return   The <a>FR_DocView</a> for <param>pv</param>.
 * @note 
 * @see FRDocGetDocView
 * @see FRDocGetCurrentDocView
 * @see FRDocViewGetPageView
 */
INTERFACE(FR_DocView, FRPageViewGetDocView, (FR_PageView pv))

/**
 * @brief FRPageViewGetPDPage
 * @details Gets a <a>FPD_Page</a> currently displayed in the specified page view. This do not new a
    * <a>FPD_Page</a> object. Do not use this result across methods that might change the current page.
    * To obtain a value that can be used across such calls, use <a>FPD_PageNew</a> instead.
 * @param[in]  pv The page view whose <a>FPD_Page</a> is obtained.
 * @return   <a>FPD_Page</a> displayed in <param>pv</param>, return<a>NULL</a> if no valid <a>FPD_Page</a>
    * associated with <param>pv</param>.
 * @note 
 * @see FRDocGetPDDoc
 */
INTERFACE(FPD_Page, FRPageViewGetPDPage, (FR_PageView pv))

/**
 * @brief FRPageViewGetPageIndex
 * @details Gets the current page number.
 * @param[in]  pv The page view whose current page number is obtained.
 * @return   The current page number, The first page number of a document is page 0.
 * @note 
 */
INTERFACE(FS_INT32, FRPageViewGetPageIndex, (FR_PageView pv))

/**
 * @brief FRPageViewCountAnnot
 * @details Gets the number of annotations associated with specified page view. This interface is not available in version 1.0.
 * @param[in]  pv The page view object.
 * @return   The number of annotations associated with <param>pv</param>.
 * @note 
 */
INTERFACE(FS_INT32, FRPageViewCountAnnot, (FR_PageView pv))

/**
 * @brief FRPageViewGetCurrentMatrix
 * @details Gets the current matrix of the page view.
 * @param[in]  pv The page view object.
 * @return   Current matrix of <param>pv</param>.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FRPageViewGetCurrentMatrix, (FR_PageView pv))

/**
 * @brief FRPageViewDevicePointToPage
 * @details Transforms a point's coordinate from device space to user space.
 * @param[in]  pv The page view for which the point's coordinates are transformed from device space to user space.
 * @param[in]  window_x The x-coordinate of the point to transform, specified in device space coordinates.
 * @param[in]  window_y The y-coordinate of the point to transform, specified in device space coordinates.
 * @param[out]  outPt (Filled by this method) A pointer to a point whose user space coordinates corresponding
    * <param>window_x</param> and <param>window_y</param>.
 * @return   void
 * @note 
 * @see FRPageViewDeviceRectToPage
 * @see FRPageViewPointToDevice
 * @see FRPageViewRectToDevice
 */
INTERFACE(void, FRPageViewDevicePointToPage, (FR_PageView pv,  FS_INT32 window_x,  FS_INT32 window_y,  FS_FloatPoint* outPt))

/**
 * @brief FRPageViewDeviceRectToPage
 * @details Transforms a rectangle from device space to user space.
 * @param[in]  pv The page view for which the rectangle is transformed from device space to user space.
 * @param[in]  rect A pointer to device space rectangle whose coordinates are transformed to user space.
 * @param[out]  outRect (Filled by this method) A pointer to a user space rectangle corresponding <param>rect</param>.
 * @return   void
 * @note 
 * @see DevicePointToPage
 * @see FRPageViewPointToDevice
 * @see FRPageViewRectToDevice
 */
INTERFACE(void, FRPageViewDeviceRectToPage, (FR_PageView pv,  const FS_Rect* rect,  FS_FloatRect* outRect))

/**
 * @brief FRPageViewPointToDevice
 * @details Transforms a point from user space to device space.
 * @param[in]  pv The page view for which the point's coordinates are transformed from user space to device space.
 * @param[in]  pt A pointer to a <a>FS_FloatPoint</a> whose coordinates, specified in device space coordinates, are transformed.
 * @param[out]  out_window_x (Filled by the method) The x-coordinate of the device space point corresponding to <param>pt</param>.
 * @param[out]  out_window_y (Filled by the method) The y-coordinate of the device space point corresponding to <param>pt</param>.
 * @return   void
 * @note 
 * @see DevicePointToPage
 * @see DeviceRectToPage
 * @see FRPageViewRectToDevice
 */
INTERFACE(void, FRPageViewPointToDevice, (FR_PageView pv,  const FS_FloatPoint* pt,  FS_INT32* out_window_x,  FS_INT32* out_window_y))

/**
 * @brief FRPageViewRectToDevice
 * @details Transforms a rectangle from user space to device space.
 * @param[in]  pv The page view for which the rectangle is transformed from user space to device space.
 * @param[in]  rect A pointer to user space rectangle whose coordinates are transformed to device space.
 * @param[out]  outRect (Filled by this method) A pointer to a device space rectangle corresponding <param>rect</param>.
 * @return   void
 * @note 
 * @see DevicePointToPage
 * @see DeviceRectToPage
 * @see FRPageViewPointToDevice
 */
INTERFACE(void, FRPageViewRectToDevice, (FR_PageView pv,  const FS_FloatRect* rect,  FS_Rect* outRect))

/**
 * @brief FRPageViewIsVisible
 * @details Gets a flag that indicate whether a page view is visible.
 * @param[in]  pv The page view to adjust whether it is visible.
 * @return   <a>TRUE</a> if the page view object is visible. otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRPageViewIsVisible, (FR_PageView pv))

/**
 * @brief FRPageViewGetPageRect
 * @details Gets the current bounding-box of specified page view.
 * @param[in]  pv The page view whose bounding-box to obtained.
 * @return   The current bounding-box for <param>pv</param>.
 * @note The page bounding-box specified in device space coordinates.
 * @see FRPageViewGetPageVisibleRect
 */
INTERFACE(FS_Rect, FRPageViewGetPageRect, (FR_PageView pv))

/**
 * @brief FRPageViewGetPageVisibleRect
 * @details Gets the current visible region of specified page view.
 * @param[in]  pv The page view whose visible rectangle to obtained.
 * @return   A rectangle specified in user space, instead of the current visible region of <param>pv</param>.
 * @note If the specified page view is invisible, the returned rectangle is empty.
 * @see FRPageViewGetPageRect
 */
INTERFACE(FS_FloatRect, FRPageViewGetPageVisibleRect, (FR_PageView pv))

/**
 * @brief FRPageViewDidContentChanged
 * @details The content of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins.
 * @param[in]  pv The page view whose <a>FPD_Page</a> has been modified.
 * @param[in]  bReLoadPage A flag to force reader to reload the page data. If <a>TRUE</a>, Foxit Reader will reload the page data and reparse the page.
    * The flag must be <a>TRUE</a> and call <a>FPDPageGenerateContent</a>() befor calling this method if the <a>FPD_Page</a> whose content is modified is not using <a>FRPageViewGetPDPage</a>() to obtain.
 * @return   void
 * @note 
 * @see 
 */
INTERFACE(void, FRPageViewDidContentChanged, (FR_PageView pv,  FS_BOOL bReLoadPage))

/**
 * @brief FRPageViewGetHWnd
 * @details Gets the FS_HWND handler in which a page view is displaying.
 * @param[in]  pv The page view which FS_HWND will be obtained.
 * @return   The FS_HWND handler of <param>pv</param>.
 * @note 
 * @see 
 */
INTERFACE(FS_HWND, FRPageViewGetHWnd, (FR_PageView pv))

/**
 * @brief FRPageViewDidTextObjectChanged
 * @details The text objects of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins.
 * @param[in]  pv The page view whose text objects of <a>FPD_Page</a> has been modified.
 * @return   void
 * @note 
 * @see 
 */
INTERFACE(void, FRPageViewDidTextObjectChanged, (FR_PageView pv))

/**
 * @brief FRPageViewGetAnnotByIndex
 * @details Gets the annotation by index.
 * @param[in]  pv The input page view object.
 * @param[in]  index The specified index of the annotations.
 * @return   The specified annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see 
 */
INTERFACE(FR_Annot, FRPageViewGetAnnotByIndex, (FR_PageView pv,  FS_INT32 index))

/**
 * @brief FRPageViewGetPageState
 * @details Gets the page state. Sets <param>outDestArray</param> NULL to get the count of the destination array first.
    * FR_PDFZOOM_XYZ       type will be the <a>left</a>,<a>top</a>,<a>zoom</a> information of the page to the sequential record <param>outDestArray</param>.
    * FR_PDFZOOM_FITRECT   type will be the <a>left</a>,<a>bottom</a>,<a>right</a>,<a>top</a> information of the page to the sequential record <param>outDestArray</param>.
    * FR_PDFZOOM_FITHORZ   type will be the <a>top</a> information of the page to the sequential record <param>outDestArray</param>.
    * FR_PDFZOOM_FITVERT   type will be the <a>left</a> information of the page to the sequential record <param>outDestArray</param>.
    * FR_PDFZOOM_FITBHORZ  type will be the <a>top</a> information of the page to the sequential record <param>outDestArray</param>.
    * No data record for other types.
 * @param[in]  pv The input page view object.
 * @param[out]  outFitType It receives the fit type, described in group <a>FR_PDFZOOMTYPE</a>(for example: FR_PDFZOOM_XYZ).
 * @param[out]  outDestArray It receives the target array, which is used to record the relevant page data corresponding to the FitType.
 * @param[out]  outDestArrayCount It receives the count of the destination array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRPageViewGetPageState, (FR_PageView pv,  FS_INT32* outFitType,  FS_FLOAT* outDestArray,  FS_INT32* outDestArrayCount))

/**
 * @brief FRPageViewDeleteAnnot
 * @details Deletes the specified annotation from the input page view object.
 * @param[in]  pv The input page view object.
 * @param[in]  frAnnot The input annotation to be deleted.
 * @return   <a>TRUE</a> delete annot success. otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FS_BOOL, FRPageViewDeleteAnnot, (FR_PageView pv,  FR_Annot frAnnot))

/**
 * @brief FRPageViewGetFocusAnnot
 * @details Gets the focus annotation in the the input page view object.
 * @param[in]  pv The input page view object.
 * @return   The focus annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageViewGetFocusAnnot, (FR_PageView pv))

/**
 * @brief FRPageViewGetPageScale
 * @details Gets the page scale.
 * @param[in]  pv The input page view object.
 * @return   The page scale.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see 
 */
INTERFACE(FS_FLOAT, FRPageViewGetPageScale, (FR_PageView pv))

/**
 * @brief FRPageViewGetAnnotAtPoint
 * @details Gets the annotation at the specified point.
 * @param[in]  pv The input page view object.
 * @param[in]  point The input point where to get the annotation.
 * @param[in]  pszSubType Specifies the sub type of the annotation you want to get. You can set it NULL as default.
 * @return   The specified annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(FR_Annot, FRPageViewGetAnnotAtPoint, (FR_PageView pv,  FS_DevicePoint point,  FS_LPCSTR pszSubType))

/**
 * @brief FRPageViewUpdateAllViews
 * @details Updates all the page views where the annotation is shown.
 * @param[in]  pv The input page view object.
 * @param[in]  frAnnot The input annotation you want to update.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(void, FRPageViewUpdateAllViews, (FR_PageView pv,  FR_Annot frAnnot))

/**
 * @brief FRPageViewAddAnnot
 * @details Adds the annotation to the input page view object.
 * @param[in]  pv The input page view object.
 * @param[in]  annotDict The input annotation dictionary you want to add.
 * @param[in]  nIndex The index where you want to add the annotation. Sets it -1 as default.
 * @return   The UI layer annotation object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(FR_Annot, FRPageViewAddAnnot, (FR_PageView pv,  FPD_Object annotDict,  FS_INT32 nIndex))

/**
 * @brief FRPageViewGetRenderOptions
 * @details Gets the rendering options from the input page view object.
 * @param[in]  pv The input page view object.
 * @return   The rendering options.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see 
 */
INTERFACE(FPD_RenderOptions, FRPageViewGetRenderOptions, (FR_PageView pv))

/**
 * @brief FRPageViewDidContentChanged2
 * @details The content of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins.
 * @param[in]  pv The page view whose <a>FPD_Page</a> has been modified.
 * @param[in]  bReLoadPage A flag to force reader to reload the page data. If <a>TRUE</a>,
    * Foxit Reader will reload the page data and reparse the page. The flag must be <a>TRUE</a> and call <a>FPDPageGenerateContent</a>()
    * befor calling this method if the <a>FPD_Page</a> whose content is modified is not using <a>FRPageViewGetPDPage</a>() to obtain.
 * @param[in]  bResizePageNotify Checks whether to broadcast the notification of page resizing.
 * @param[in]  pChangeData It indicates what data is changed. This parameter is temporarily not used.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 * @see 
 */
INTERFACE(void, FRPageViewDidContentChanged2, (FR_PageView pv,  FS_BOOL bReLoadPage,  FS_BOOL bResizePageNotify,  void* pChangeData))

/**
 * @brief FRPageViewDidContentChanged3
 * @details The content of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins.
 * @param[in]  pv The page view whose <a>FPD_Page</a> has been modified.
 * @param[in]  bReLoadPage A flag to force reader to reload the page data. If <a>TRUE</a>, Foxit Reader will reload the page data and reparse the page.
    * The flag must be <a>TRUE</a> and call <a>FPDPageGenerateContent</a>() befor calling this method if the <a>FPD_Page</a> whose content is modified is not using <a>FRPageViewGetPDPage</a>() to obtain.
 * @param[in]  bResizePageNotify Checks whether to broadcast the notification of page resizing.
 * @param[in]  objArray It indicates what data is changed. The value type in the array is <a>FR_STRUCTCONTENT_OBJECT</a>.
 * @param[in]  changeType The content change type.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @see 
 */
INTERFACE(void, FRPageViewDidContentChanged3, (FR_PageView pv,  FS_BOOL bReLoadPage,  FS_BOOL bResizePageNotify,  FS_PtrArray objArray,  FR_ContentChangeType changeType))

/**
 * @brief FRPageViewSetContentModification
 * @details Sets the modified page content.
 * @param[in]  pv The page view whose <a>FPD_Page</a> content is modified.
 * @param[in]  modifiedContent An array to store the modified <a>FPD_Page</a> or <a>FPD_Form</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 4.1.2
 */
INTERFACE(void, FRPageViewSetContentModification, (FR_PageView pv,  FS_PtrArray modifiedContent))

/**
 * @brief FRPageViewGenerateContent
 * @details Generates the page content.
 * @param[in]  pv The page view whose <a>FPD_Page</a> needs to generate content.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.1
 */
INTERFACE(void, FRPageViewGenerateContent, (FR_PageView pv))

/**
 * @brief FRPageViewUpdateAllViewsRect
 * @details 
 * @param[in]  pv The page view object.
 * @param[in]  rectarray The point array of update area in user space.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.1
 */
INTERFACE(void, FRPageViewUpdateAllViewsRect, (FR_PageView pv,  FS_FloatRectArray rectarray))

/**
 * @brief FRPageViewCountViews
 * @details Gets the total number of views in the current view page.
 * @param[in]  pv The page view object.
 * @return   The total number of views in the current view page.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.1
 */
INTERFACE(FS_INT32, FRPageViewCountViews, (FR_PageView pv))

/**
 * @brief FRPageViewIsValidAnnot
 * @details Check that the input annotation object of the page view object is valid.
 * @param[in]  pv The page view object.
 * @param[in]  annot The input FR_Annot object.
 * @return   <a>TRUE</a> if the annot of the page view is valid. otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.1
 */
INTERFACE(FS_BOOL, FRPageViewIsValidAnnot, (FR_PageView pv,  FS_LPVOID annot))

/**
 * @brief FRPageViewAnnot_OnDraw
 * @details Draw annotation's appearance, using default appearance rules.
 * @param[in]  pPageView The page view object.
 * @param[in]  hDC The device context of <param>pageView</param>.
 * @param[in]  pAnnot The specified annotation to be drawn.
 * @param[in]  pDevice The memory device used to render the annotation.
 * @param[in]  pUser2Device The transformation matrix from user space to device space.
 * @param[in]  rcWindow The rectangle of <param>pageView</param>.
 * @param[in]  dwFlags The reserve flag, will be ignore.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 4.1.2
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageViewAnnot_OnDraw, (FR_PageView pPageView,  FS_HDC hDC,  FR_Annot pAnnot,  FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device,  const FS_FloatRect& rcWindow,  FS_DWORD dwFlags))

/**
 * @brief FRPageViewAnnot_OnHitTest
 * @details Determine whether the hit point is included in the annotation of the selected page view
 * @param[in]  pPageView The page view whose needs to hit test.
 * @param[in]  pAnnot The annotation whose needs to hit test.
 * @param[in]  point The hit point by device space.
 * @return   <a>TRUE</a> The hit point is included in the annotation of the selected page view. otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.1
 */
INTERFACE(FS_BOOL, FRPageViewAnnot_OnHitTest, (FR_PageView pPageView,  FR_Annot pAnnot,  const FS_FloatPoint point))

/**
 * @brief FRPageViewGetReaderPage
 * @details Get the document page object which containt the page view object.
 * @param[in]  pPageView The page view object.
 * @return   The document page object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.1
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Page, FRPageViewGetReaderPage, (FR_PageView pPageView))

/**
 * @brief FRPageViewPostFormFilerMessageText
 * @details Post form file message text to the input document.
 * @param[in]  pPageView The page view object.
 * @param[in]  data The array of message text to post.
 * @param[in]  pRDDoc The document object to post.
 * @return   void.
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.1
 */
INTERFACE(void, FRPageViewPostFormFilerMessageText, (FR_PageView pPageView,  FS_WideStringArray data,  FR_Document pRDDoc))

/**
 * @brief FRPageViewSetIsFindHighlight
 * @details Set if find highlight.
 * @param[in]  pPageView The page view object.
 * @param[in]  bFindHighlight Set if find highlight.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageViewSetIsFindHighlight, (FR_PageView pPageView,  FS_BOOL bFindHighlight))

/**
 * @brief FRPageViewIsFindHighlight
 * @details Get if find highlight.
 * @param[in]  pPageView The page view object.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPageViewIsFindHighlight, (FR_PageView pPageView))

/**
 * @brief FRPageViewSetAdvancedFindHighlight
 * @details Set if advanced find highlight.
 * @param[in]  pPageView The page view object.
 * @param[in]  bFindHighlight Set if advanced find highlight.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageViewSetAdvancedFindHighlight, (FR_PageView pPageView,  FS_BOOL bAdvancedFindHighlight))

/**
 * @brief FRPageViewIsAdvancedFindHighlight
 * @details Get if advanced find highlight.
 * @param[in]  pPageView The page view object.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPageViewIsAdvancedFindHighlight, (FR_PageView pPageView))

/**
 * @brief FRPageViewGetPageStateByFitType
 * @details Get page state by fit type of FR_PAGESTATE.
 * @param[in]  pPageView The page view object.
 * @param[out]  state Get page state, it need to use FSFloatArrayNew to init dest property.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageViewGetPageStateByFitType, (FR_PageView pPageView,  FR_PAGESTATE* state))

/**
 * @brief FRPageViewGetPageRectIncludeMargin
 * @details Get page rect include margin.
 * @param[in]  pPageView The page view object.
 * @return   FS_Rect
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_Rect, FRPageViewGetPageRectIncludeMargin, (FR_PageView pPageView))

NumOfSelector(FRPageView)
ENDENUM

//*****************************
/* TextSelectTool HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRTextSelectToolCreate
 * @details Creates the text select tool which is used to process the operation of text selecting in the doc view.
 * @param[in]  doc The input doc where the operation of text selecting occurs.
 * @return   The text select tool.
 * @note 
 * @see 
 */
INTERFACE(FR_TextSelectTool, FRTextSelectToolCreate, (FR_Document doc))

/**
 * @brief FRTextSelectToolDestroyTextSelectTool
 * @details Destroys the text select tool created from <a>FRTextSelectToolCreate</a>.
 * @param[in]  textSelectTool The input text select tool.
 * @return   void.
 * @note Current function has been deprecated , so not recommend to use current function any more.
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolDestroyTextSelectTool, (FR_TextSelectTool textSelectTool))

/**
 * @brief FRTextSelectToolGetSelectedText
 * @details Gets the selected text form the input text select tool.
 * @param[in]  textSelectTool The input text select tool.
 * @param[out]  outText It receives the text selected.
 * @return   <a>TRUE</a> Get the selected text form the input text select tool successful, otherwise not.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FRTextSelectToolGetSelectedText, (FR_TextSelectTool textSelectTool,  FS_WideString* outText))

/**
 * @brief FRTextSelectToolDrawSelection
 * @details Draws the area where the text is selected in black color.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  docView The input doc view where do the operation of text selecting.
 * @param[in]  winPort The platform-depend things.
 * @return   void.
 * @note The function can only be used for Windows.
 * @see 
 */
INTERFACE(void, FRTextSelectToolDrawSelection, (FR_TextSelectTool textSelectTool,  FR_DocView docView,  FR_WinPort winPort))

/**
 * @brief FRTextSelectToolClearSelection
 * @details Clears the area where the text is selected.
 * @param[in]  textSelectTool The input text select tool.
 * @return   void.
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolClearSelection, (FR_TextSelectTool textSelectTool))

/**
 * @brief FRTextSelectToolDoLButtonUp
 * @details Does the mouse left button up operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse left button up operation.
 * @return   void.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolDoLButtonUp, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolDoLButtonDown
 * @details Does the mouse left button down operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse operation.
 * @return   void.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolDoLButtonDown, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolDoLButtonDblClk
 * @details Does the mouse left button double-click operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse operation.
 * @return   void.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolDoLButtonDblClk, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolDoRButtonUp
 * @details Does the mouse right button up operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse operation.
 * @return   void.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolDoRButtonUp, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolDoMouseMove
 * @details Does the mouse move operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse operation.
 * @return   void.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolDoMouseMove, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolDoMouseWheel
 * @details Perform mouse wheel operation to specified position.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse operation.
 * @return   <a>TRUE</a> if perform mouse wheel operation to specified position is success, otherwise not.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRTextSelectToolDoMouseWheel, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolIsSelecting
 * @details Checks whether the mouse is selecting text.
 * @param[in]  textSelectTool The input text select tool.
 * @return   <a>TRUE</a> if the mouse is selecting text, otherwise not.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRTextSelectToolIsSelecting, (FR_TextSelectTool textSelectTool))

/**
 * @brief FRTextSelectToolEnumTextObjectRect
 * @details Enumerates text object rectangles. The function of this interface needs to be called twice.
    * The first time we call this interface, we can get the count of rectangles by setting <param> outRectArray </param> to <a> NULL </a>.
    * Then call the interface again to assign data to the rectangular array.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageIndex The input page index.
 * @param[out]  outRectArray It receives the rectangle array of text object.
 * @param[out]  nCount It receives the count of the rectangle array.
 * @return   <a>TRUE</a> If enumerates the text object rectangles is successful, otherwise not.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FRTextSelectToolEnumTextObjectRect, (FR_TextSelectTool textSelectTool,  FS_INT32 pageIndex,  FS_FloatRect** outRectArray,  FS_INT32* nCount))

/**
 * @brief FRTextSelectToolAddSelect
 * @details Get the selected rectangular area according to the input parameters.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pPageView The page view object.
 * @param[in]  nStartIndex The start index of the text to be selected.
 * @param[in]  nEndIndex The end index of the text to be selected.
 * @param[in]  bShowLayer Update document OCG and refresh layer panel view.
 * @param[in]  bTextIndex Whether the input index is a text index.
 * @return   void.
 * @note The input index is divided into ordinary character index and text index. The text index is the index that matches the file obtained in FPDTextPageGetPageText.
 * @see FPDTextPageGetPageText
 */
INTERFACE(void, FRTextSelectToolAddSelect, (FR_TextSelectTool textSelectTool,  FR_PageView pPageView,  FS_INT32 nStartIndex,  FS_INT32 nEndIndex,  FS_BOOL bShowLayer,  FS_BOOL bTextIndex))

/**
 * @brief FRTextSelectToolSelect_GetPageRange
 * @details Get the index range of the selected page.
 * @param[in]  textSelectTool The input text select tool.
 * @param[out]  nStartPage The start index of the selected page
 * @param[out]  nEndPage The end index of the selected page
 * @return   void
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolSelect_GetPageRange, (FR_TextSelectTool textSelectTool,  FS_INT32 &nStartPage,  FS_INT32 &nEndPage))

/**
 * @brief FRTextSelectToolGetSelectedText2
 * @details Gets the selected text form the input text select tool, allow line breaks between pages.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  bLineBreakBetweenPages The flag of line break between pages.
 * @param[out]  outText The received text of selected.
 * @return   <a>TRUE</a> Get the selected text from the input text select tool successful, otherwise not.
 * @note The function can only be used for Windows.
 * @see 
 */
INTERFACE(FS_BOOL, FRTextSelectToolGetSelectedText2, (FR_TextSelectTool textSelectTool,  FS_BOOL bLineBreakBetweenPages,  FS_WideString* outText))

INTERFACE(FS_BOOL, FRTextSelectToolGetSelectedTextInfo, (FR_TextSelectTool textSelectTool,  FS_PtrArray* outTextInfo))

/**
 * @brief FRTextSelectToolReleaseSelectedInfo
 * @details Release the selected text info point array.
 * @param[in]  outTextInfo The selected text info point array
 * @return   void.
 * @note 
 * @see FRTextSelectToolGetSelectedTextInfo
 * @see FRTextSelectToolGetSelectedData
 */
INTERFACE(void, FRTextSelectToolReleaseSelectedInfo, (FS_PtrArray outTextInfo))

/**
 * @brief FRTextSelectToolIsSelected
 * @details Checks whether the input text select tool has selected text currently.
 * @param[in]  textSelectTool The input text select tool.
 * @return   <a>TRUE</a> If there has selected text currently from the input text select tool, otherwise not.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FRTextSelectToolIsSelected, (FR_TextSelectTool textSelectTool))

/**
 * @brief FRTextSelectToolIsPageSelectAll
 * @details Checks whether the input text select tool has selected all text currently in the input page index,.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  nPageIndex The input page index.
 * @return   <a>TRUE</a> If all text is selected by the input text select tool in the input page index, otherwise not.
 * @note The function can only be used for Windows.
 * @see 
 */
INTERFACE(FS_BOOL, FRTextSelectToolIsPageSelectAll, (FR_TextSelectTool textSelectTool,  FS_INT32 nPageIndex))

/**
 * @brief FRTextSelectToolGetSelectedData
 * @details Get the selected data of all the page by the input text select tool.
 * @param[in]  textSelectTool The input text select tool.
 * @param[out]  selectedData The the selected data info array recive from all the pages.
 * @return   <a>TRUE</a> If get the selected data of all the page by the input text select tool is success, otherwise not.
 * @note That need to call ReleaseSelectedInfo to release <a>selectedData</a>.
 * @see 
 */
INTERFACE(FS_BOOL, FRTextSelectToolGetSelectedData, (FR_TextSelectTool textSelectTool,  FR_TextSelectedData* selectedData))

/**
 * @brief FRTextSelectToolAddSelect2
 * @details Select according to the incoming page view and rectangular area.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pPageView The page view object.
 * @param[in]  arFormRects The select rect array.
 * @return   void.
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolAddSelect2, (FR_TextSelectTool textSelectTool,  FR_PageView pPageView,  FS_FloatRectArray arFormRects))

/**
 * @brief FRTextSelectToolAddSelectTextRects
 * @details Select the text rectangle area according to the input parameters.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pPageView The page view object.
 * @param[in]  arTextRects The select rect array.
 * @param[in]  bContains Is segment contains allowed.
 * @return   void.
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolAddSelectTextRects, (FR_TextSelectTool textSelectTool,  FR_PageView pPageView,  FS_FloatRectArray arTextRects,  FS_BOOLEAN bContains))

/**
 * @brief FRTextSelectToolGetSelectPDFRect
 * @details Get the currently selected rectangular area according to the input parameters.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pPageView The page view object.
 * @param[out]  rect_array The select rect array.
 * @param[in]  bNeedPageViewVisible Whether the page view is required to be visible.
 * @return   void.
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolGetSelectPDFRect, (FR_TextSelectTool textSelectTool,  FR_PageView pPageView,  FS_FloatRectArray* rect_array,  FS_BOOL bNeedPageViewVisible))

/**
 * @brief FRTextSelectToolDeselectAll
 * @details Deselect all seletion area.
 * @param[in]  textSelectTool The input text select tool.
 * @return   void.
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolDeselectAll, (FR_TextSelectTool textSelectTool))

/**
 * @brief FRTextSelectToolAddSelectTextRectsWithPages
 * @details According to the incoming page number and regional position key to select the operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  mapselectRects The Map which is include page idnex and selected array.
 * @return   void.
 * @note The structure of <a>mapselectRects</a> is std::map<int*, FS_SelectPos*>
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolAddSelectTextRectsWithPages, (FR_TextSelectTool textSelectTool,  FS_MapPtrToPtr mapselectRects))

INTERFACE(FS_LPVOID, FRTextSelectToolGetExportSelectionPageRects, (FR_TextSelectTool textSelectTool,  FS_INT32* nPageCount,  FRSelectTextProgressProc pFun,  FS_LPVOID pUIProgress))

/**
 * @brief FRTextSelectToolCopyToClipBoard
 * @details Copy content to clip board.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageIndexArra The input page array.
 * @param[in]  rectsArray The rect array match to each page.	It need contains FS_FloatRectArray.
 * @param[in]  bIncXMLSpreadsheet Whether need to format xml type.
 * @return   void.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolCopyToClipBoard, (FR_TextSelectTool textSelectTool,  FS_Int32Array pageIndexArra,  FS_PtrArray rectsArray,  FS_BOOL bIncXMLSpreadsheet))

/**
 * @brief FRTextSelectToolSelectEnumTextObjectPathPoint
 * @details Get the select text points.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  page_index The input page index.
 * @param[out]  result Get the path points.
 * @return   FS_BOOL.  TRUE: Select the text success.
 * @note If return TRUE, need call FRTextSelectToolReleaseTextObjectPathPoints to release the points obj.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRTextSelectToolSelectEnumTextObjectPathPoint, (FR_TextSelectTool textSelectTool,  FS_INT32 page_index,  FS_PtrArray* result))

/**
 * @brief FRTextSelectToolReleaseTextObjectPathPoints
 * @details Release the select text points.
 * @param[in]  points The input path points need to release.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolReleaseTextObjectPathPoints, (FS_PtrArray points))

/**
 * @brief FRTextSelectToolSelectInitSelection
 * @details Init page selection.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  page_index The input page index.
 * @return   FS_BOOL.  TRUE: Init success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolSelectInitSelection, (FR_TextSelectTool textSelectTool,  FS_INT32 page_index))

/**
 * @brief FRTextSelectToolSelectOnKeyDown
 * @details On key down.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  nKeyCode The input key code.
 * @param[in]  nFlags The input flag.
 * @param[in]  bShowCaret If show caret.
 * @return   FS_BOOLEAN.  TRUE: Init success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRTextSelectToolSelectOnKeyDown, (FR_TextSelectTool textSelectTool,  FS_UINT nKeyCode,  FS_UINT nFlags,  FS_BOOL bShowCaret))

/**
 * @brief FRTextSelectToolDoLButtonDown2
 * @details Does the mouse left button down operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse operation.
 * @param[in]  bUsedByHandTool If uses by hand tool.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolDoLButtonDown2, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point,  FS_BOOL bUsedByHandTool))

/**
 * @brief FRTextSelectToolGetSelectedTextObject
 * @details Get the selected text object.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  nPageIdx The input page index.
 * @param[out]  textObjArr Get the selected FR_STRUCTCONTENT_OBJECT array.
 * @return   FS_BOOL.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRTextSelectToolGetSelectedTextObject, (FR_TextSelectTool textSelectTool,  FS_INT32 nPageIdx,  FS_PtrArray* textObjArr))

/**
 * @brief FRTextSelectToolDoCopy
 * @details Get the selected text object.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  bFormat Whether format copy.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolDoCopy, (FR_TextSelectTool textSelectTool,  FS_BOOL bFormat))

/**
 * @brief FRTextSelectToolToolDraw
 * @details Draw the caret.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  hDC The input HDC.
 * @param[in]  pDevice The input FPD_RenderDevice .
 * @param[in]  dwFlags The input flag, default is 0.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolToolDraw, (FR_TextSelectTool textSelectTool,  FS_HDC hDC,  FPD_RenderDevice pDevice,  FS_DWORD dwFlags))

/**
 * @brief FRTextSelectToolSetFloatyShowState
 * @details Set if show property floaty.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  bShow Set if show property floaty.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolSetFloatyShowState, (FR_TextSelectTool textSelectTool,  FS_BOOL bShow))

/**
 * @brief FRTextSelectToolGetFloatyShowState
 * @details Get if show property floaty.
 * @param[in]  textSelectTool The input text select tool.
 * @return   FS_BOOL.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRTextSelectToolGetFloatyShowState, (FR_TextSelectTool textSelectTool))

/**
 * @brief FRTextSelectToolAddHighlightSelect
 * @details Add highlight select text.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  posArr The input FR_HighLightPageTextPos array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolAddHighlightSelect, (FR_TextSelectTool textSelectTool,  FS_PtrArray posArr))

/**
 * @brief FRTextSelectToolGetHltSelPagesTextPos
 * @details Gets an array of page selection text positions.
 * @param[in]  textSelectTool The input text select tool.
 * @param[out]  textPosArr Gets an array of page selection text positions, it contains PFR_HighLightPageTextPos obj.
 * @return   FS_BOOL
 * @note It need call FRTextSelectToolRelHltSelPagesTextPos to release FR_HighLightPageTextPos data.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see FRTextSelectToolReleaseHltSelPagesTextPos
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRTextSelectToolGetHltSelPagesTextPos, (FR_TextSelectTool textSelectTool,  FS_PtrArray* textPosArr))

/**
 * @brief FRTextSelectToolRelHltSelPagesTextPos
 * @details Release select texts pos info.
 * @param[in]  textPosArr The input select text pos. It get from 	FRTextSelectToolGetHltSelPagesTextPos.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolRelHltSelPagesTextPos, (FS_PtrArray textPosArr))

/**
 * @brief FRTextSelectToolAddHighlightAdvSelect
 * @details Add advanced highlight select text, it for advanced search.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  posArr The input FR_HighLightPageTextPos array.
 * @param[in]  bIndexSearch If search for char index.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolAddHighlightAdvSelect, (FR_TextSelectTool textSelectTool,  FS_PtrArray posArr,  FS_BOOL bIndexSearch))

/**
 * @brief FRTextSelectToolGetHltAdvSelPagesTextPos
 * @details Get advanced highlight select text.
 * @param[in]  textSelectTool The input text select tool.
 * @param[out]  textPosArr Gets an array of page advanced selection text positions, it contains PFR_HighLightPageTextPos obj.
 * @return   FS_BOOL
 * @note It need call FRTextSelectToolRelHltSelPagesTextPos to release FR_HighLightPageTextPos data.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see FRTextSelectToolReleaseHltSelPagesTextPos
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRTextSelectToolGetHltAdvSelPagesTextPos, (FR_TextSelectTool textSelectTool,  FS_PtrArray* textPosArr))

/**
 * @brief FRTextSelectToolInvalidateHltSelect
 * @details Invalidates the entire current page view.
 * @param[in]  textSelectTool The input text select tool.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolInvalidateHltSelect, (FR_TextSelectTool textSelectTool))

/**
 * @brief FRTextSelectToolClearHltAdvSelect
 * @details Clear advanced highlight select text.
 * @param[in]  textSelectTool The input text select tool.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextSelectToolClearHltAdvSelect, (FR_TextSelectTool textSelectTool))

NumOfSelector(FRTextSelectTool)
ENDENUM

//----------_V2----------
//----------_V3----------
//*****************************
/* ThumbnailView HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRThumbnailViewCountPage
 * @details Gets the count of page displayed in the thumbnail view.
 * @param[in]  tv The input thumbnail view.
 * @return   The count of page displayed in the thumbnail view.
 * @note 
 * @see FRDocViewGetThumbnailView
 */
INTERFACE(FS_INT32, FRThumbnailViewCountPage, (FR_ThumbnailView tv))

/**
 * @brief FRThumbnailViewCountVisiblePage
 * @details Gets the count of visible page displayed in the thumbnail view.
 * @param[in]  tv The input thumbnail view.
 * @return   The count of visible page displayed in the thumbnail view.
 * @note 
 * @see FRDocViewGetThumbnailView
 */
INTERFACE(FS_INT32, FRThumbnailViewCountVisiblePage, (FR_ThumbnailView tv))

/**
 * @brief FRThumbnailViewGetPageRect
 * @details Gets the rectangle of specified visible page.
 * @param[in]  tv The input thumbnail view.
 * @param[in]  nPage The index of visible pages.
 * @return   The rectangle of specified visible page.
 * @note 
 * @see FRDocViewGetThumbnailView
 */
INTERFACE(FS_Rect, FRThumbnailViewGetPageRect, (FR_ThumbnailView tv,  FS_INT32 nPage))

/**
 * @brief FRThumbnailViewGetVisiblePageRange
 * @details Gets the index of visible page range.
 * @param[in]  tv The input thumbnail view.
 * @param[out]  nFrom It receives the starting index of visible pages.
 * @param[out]  nTo It receives the ending index of visible pages.
 * @return   void
 * @note 
 * @see FRDocViewGetThumbnailView
 */
INTERFACE(void, FRThumbnailViewGetVisiblePageRange, (FR_ThumbnailView tv,  FS_INT32* nFrom,  FS_INT32* nTo))

/**
 * @brief FRThumbnailViewGetPDPage
 * @details Gets a <a>FPD_Page</a> object according to the input page index and the input thumbnail view.
 * @param[in]  tv The input thumbnail view.
 * @param[in]  nPage The index of page.
 * @return   The <a>FPD_Page</a> object.
 * @note 
 * @see FRDocViewGetThumbnailView
 */
INTERFACE(FPD_Page, FRThumbnailViewGetPDPage, (FR_ThumbnailView tv,  FS_INT32 nPage))

NumOfSelector(FRThumbnailView)
ENDENUM

//----------_V4----------
//----------_V5----------
//*****************************
/* Annot HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRAnnotGetPDFAnnot
 * @details Gets the data layer PDF annotation of the input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @return   The data layer PDF annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FPD_Annot, FRAnnotGetPDFAnnot, (FR_Annot frAnnot))

/**
 * @brief FRAnnotGetType
 * @details Gets the type of the input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[out]  outType It receives the type of the annotation.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAnnotGetType, (FR_Annot frAnnot,  FS_ByteString* outType))

/**
 * @brief FRAnnotGetSubType
 * @details Gets the sub type of the input UI layer annotation object.
    * Like widget annot subtype: Signature,PushButton,CheckBox,RadioButton,TextField,ListBox,ComboBox,BarCode.
    * text annot subtype: TypeWriter,TextBox,CallOut.
    * screen annot subtype: Image,Movie.
    * Other annot will return empty.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[out]  outSubType It receives the sub type of the annotation.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAnnotGetSubType, (FR_Annot frAnnot,  FS_ByteString* outSubType))

/**
 * @brief FRAnnotSetVisible
 * @details Sets the input UI layer annotation object to be visible or not.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[in]  bShow It indicates whether the annotation is visible.
 * @return   void
 * @note You must call this interface in <a>FRPageViewOnWillParsePage</a> callback.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 */
INTERFACE(void, FRAnnotSetVisible, (FR_Annot frAnnot,  FS_BOOL bShow))

/**
 * @brief FRAnnotGetPageVew
 * @details Gets the associated page view of the input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[in]  nIndex The specified page view index.
 * @return   The associated page view.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(FR_PageView, FRAnnotGetPageVew, (FR_Annot frAnnot,  FS_INT32 nIndex))

/**
 * @brief FRAnnotGetTabOrder
 * @details Get the tab order of the input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @return   The tab order of the input UI layer annotation object.
 * @note Currently only annot of Widget type supports taborder.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(FS_INT32, FRAnnotGetTabOrder, (FR_Annot frAnnot))

/**
 * @brief FRAnnotSetFlags
 * @details Set a integer of number object for the flag of the specified annotation.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[in]  dwFlags The integer of number flag to set.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(void, FRAnnotSetFlags, (FR_Annot frAnnot,  FS_DWORD dwFlags))

/**
 * @brief FRAnnotDrawAppearance
 * @details Draw annotation's appearance, using default appearance rules.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[in]  pDevice The device to draw on.
 * @param[in]  pUser2Device The transformation matrix from user space to device space.
 * @param[in]  mode The input appearance mode.
 * @param[in]  pOptions The render options.
 * @return   <a>TRUE</a> If the appearance successfully found and drawn.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAnnotDrawAppearance, (FR_Annot frAnnot,  FPD_RenderDevice pDevice,  const FS_AffineMatrix pUser2Device,  FPD_AnnotAppearanceMode mode,  const FPD_RenderOptions pOptions))

/**
 * @brief FRAnnotIsSelected
 * @details Checks whether the input UI layer annotation object is selected.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @return   <a>TRUE</a> If the input UI layer annotation object is selected, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(FS_BOOL, FRAnnotIsSelected, (FR_Annot frAnnot))

/**
 * @brief FRAnnotSetAuthor
 * @details Set string for the author of the specified annotation.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[in]  cwAuthor The string of author to set.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(void, FRAnnotSetAuthor, (FR_Annot frAnnot,  const FS_WideString cwAuthor))

/**
 * @brief FRAnnotGetFRDocByAnnot
 * @details Gets the <a>FR_Document</a> object of The input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @return   The <a>FR_Document</a> object of The input UI layer annotation object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(FR_Document, FRAnnotGetFRDocByAnnot, (FR_Annot frAnnot))

/**
 * @brief FRAnnotGetPage
 * @details Gets the <a>FR_Page</a> object of The input UI layer annotation object.
    * Remarks:
 * @param[in]  frAnnot The input UI layer annotation object.
 * @return   The <a>FR_Page</a> object of The input UI layer annotation object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Page, FRAnnotGetPage, (FR_Annot frAnnot))

/**
 * @brief FRAnnotGetXFAWidget
 * @details Gets the <a>PFPDXFA_HWIDGET</a> object of The input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @return   The <a>PFPDXFA_HWIDGET</a> object of The input UI layer annotation object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(PFPDXFA_HWIDGET, FRAnnotGetXFAWidget, (FR_Annot frAnnot))

/**
 * @brief FRAnnotGetCBFWidget
 * @details Gets the <a>FR_CBF_Widget</a> object of The input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @return   The <a>FR_CBF_Widget</a> object of The input UI layer annotation object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(FR_CBF_Widget, FRAnnotGetCBFWidget, (FR_Annot frAnnot))

/**
 * @brief FRAnnotGetBorderWidth
 * @details Get the border width of the input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[out]  outWidth The border width value.
 * @return   <a>TRUE</a> If get the border width of the input UI layer annotation object successfully, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRAnnotGetBorderWidth, (FR_Annot frAnnot,  FS_INT32* outWidth))

/**
 * @brief FRAnnotGetBorderStyle
 * @details Get the border style of the input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[out]  outStyle The border style. Like FRBBS_SOLID.
 * @return   <a>TRUE</a> If get the border style of the input UI layer annotation object successfully, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRAnnotGetBorderStyle, (FR_Annot frAnnot,  FS_INT32* outStyle))

/**
 * @brief FRAnnotSetBorderWidth
 * @details Set the border width of the input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[in]  nWidth The border width value.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRAnnotSetBorderWidth, (FR_Annot frAnnot,  FS_INT32 nWidth))

/**
 * @brief FRAnnotSetBorderStyle
 * @details Set the border style of the input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[in]  nStyle The border style value.	Like FRBBS_SOLID.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRAnnotSetBorderStyle, (FR_Annot frAnnot,  FS_INT32 nStyle))

/**
 * @brief FRAnnotGetLayoutOrder
 * @details Get layout order of the input UI layer annotation object.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @return   The layout order(0 = TopMost, 1 = Screen, 2 = Link,  3 = Widget,  4 = < Other).
 * @note It used for annot taborder, redaction will return 0, markupannot will return 5, Widget will return 3, Screen will return 1.
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRAnnotGetLayoutOrder, (FR_Annot frAnnot))

/**
 * @brief FRAnnotIsSameTabOrder
 * @details Check whether the two annotations of the input are the same group. the two annotations subtype must be RadioButton.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[in]  pAnnot Another annot to compare.
 * @return   <a>TRUE</a> If the two annotations of the input are the same group, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRAnnotIsSameTabOrder, (FR_Annot frAnnot,  FR_Annot pAnnot))

/**
 * @brief FRAnnotNew
 * @details Construct FR_Annot in FRNewAnnot of FRD_BAAnnotHandlerCallbacksRec.
 * @param[in]  callback The input FR_AnnotCallbacks.
 * @param[in]  pAnnot The input FPD_Annot.
 * @param[in]  page The input FR_Page.
 * @return   FR_Annot
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FR_Annot, FRAnnotNew, (FR_AnnotCallbacks callback,  FPD_Annot pAnnot,  FR_Page page))

/**
 * @brief FRAnnotDelete
 * @details Release FR_Annot.
 * @param[in]  frAnnot The input FR_Annot.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRAnnotDelete, (FR_Annot frAnnot))

/**
 * @brief FRAnnotIsEnabled
 * @details Get if enable the annot.
 * @param[in]  frAnnot The input FR_Annot.
 * @param[in]  bIgnoreCReview If ignore CReview.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOLEAN, FRAnnotIsEnabled, (FR_Annot frAnnot,  FS_BOOLEAN bIgnoreCReview))

/**
 * @brief FRAnnotSetEnabled
 * @details Set enable the FR_Annot.
 * @param[in]  frAnnot The input FR_Annot.
 * @param[in]  bEnable Set enable flag of the FR_Annot.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @Deprecated    Internal use
 */
INTERFACE(void, FRAnnotSetEnabled, (FR_Annot frAnnot,  FS_BOOLEAN bEnable))

/**
 * @brief FRAnnotSelectAnnot
 * @details Select annot.
 * @param[in]  frAnnot The input FR_Annot.
 * @param[in]  pDocument The input FR_Document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 * @Deprecated    Internal use
 */
INTERFACE(void, FRAnnotSelectAnnot, (FR_Annot frAnnot,  FR_Document pDocument))

NumOfSelector(FRAnnot)
ENDENUM

//*****************************
/* ResourcePropertyBox HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRResourcePropertyBoxGet
 * @details Gets the property box. The Foxit Reader creates the property box so that many types of objects can reuse the same property box
    * to edit the properties. For example, the objects can be annotations, pages and so on.
 * @return   The property box. It is used to edit the properties of objects, such as the annotations, the pages and so on.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FR_ResourcePropertyBox, FRResourcePropertyBoxGet, ())

/**
 * @brief FRResourcePropertyBoxRegisterPropertyPage
 * @details Registers the callbacks used to add the new property page to the property box.
 * @param[in]  rpBox The input property box object.
 * @param[in]  pPage The input callbacks used to add the new property page to the property box.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRResourcePropertyBoxRegisterPropertyPage, (FR_ResourcePropertyBox rpBox,  FR_ResourcePropertyPageCallbacks pPage))

/**
 * @brief FRResourcePropertyBoxRegisterSourceType
 * @details Registers the source type.
 * @param[in]  rpBox The input property box object.
 * @param[in]  nSource The input source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @param[in]  bLockButton Indicates whether to show the check box used to lock the source.
 * @param[in]  pSourceFunc The input callbacks used to deal with the source of the property box.
 * @param[in]  pNotifyFunc The input callbacks that will be called when events occur.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRResourcePropertyBoxRegisterSourceType, (FR_ResourcePropertyBox rpBox,  FS_INT32 nSource,  FS_BOOL bLockButton,  FR_ResourcePropertySourceCallbacks pSourceFunc,  FR_ResourcePropertyNotifyCallbacks pNotifyFunc))

/**
 * @brief FRResourcePropertyBoxGetSourceType
 * @details Gets the source type of the property box.
 * @param[in]  rpBox The input property box object.
 * @return   The source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FS_INT32, FRResourcePropertyBoxGetSourceType, (FR_ResourcePropertyBox rpBox))

/**
 * @brief FRResourcePropertyBoxGetSourceFunc
 * @details Gets the specified property source.
 * @param[in]  rpBox The input property box object.
 * @param[in]  nSource The specified source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @return   The property source.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FR_ResourcePropertySource, FRResourcePropertyBoxGetSourceFunc, (FR_ResourcePropertyBox rpBox,  FS_INT32 nSource))

/**
 * @brief FRResourcePropertyBoxUpdatePropertyBox
 * @details Updates the property box.
 * @param[in]  rpBox The input property box object.
 * @param[in]  nSource The specified source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRResourcePropertyBoxUpdatePropertyBox, (FR_ResourcePropertyBox rpBox,  FS_INT32 nSource))

/**
 * @brief FRResourcePropertyBoxOpenPropertyBox
 * @details Opens the property box.
 * @param[in]  rpBox The input property box object.
 * @param[in]  nSource The specified source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRResourcePropertyBoxOpenPropertyBox, (FR_ResourcePropertyBox rpBox,  FS_INT32 nSource))

/**
 * @brief FRResourcePropertyBoxClosePropertyBox
 * @details Closes the property box.
 * @param[in]  rpBox The input property box object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRResourcePropertyBoxClosePropertyBox, (FR_ResourcePropertyBox rpBox))

/**
 * @brief FRResourcePropertyBoxIsPropertyBoxVisible
 * @details Checks whether the property box is visible or not.
 * @param[in]  rpBox The input property box object.
 * @return   <a>TRUE</a> if the property box is visible, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOL, FRResourcePropertyBoxIsPropertyBoxVisible, (FR_ResourcePropertyBox rpBox))

/**
 * @brief FRResourcePropertyBoxGetWnd
 * @details Gets the window handle of the property box.
 * @param[in]  rpBox The input property box object.
 * @return   The window handle of the property box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FS_HWND, FRResourcePropertyBoxGetWnd, (FR_ResourcePropertyBox rpBox))

/**
 * @brief FRResourcePropertyBoxGetPropertyPage
 * @details Gets the property page by name.
 * @param[in]  rpBox The input property box object.
 * @param[in]  lpwsName The specified name of the property page.
 * @return   The property page.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FR_ResourcePropertyPage, FRResourcePropertyBoxGetPropertyPage, (FR_ResourcePropertyBox rpBox,  FS_LPCWSTR lpwsName))

/**
 * @brief FRResourcePropertyBoxSetCurrentPropertyPage
 * @details Sets the current property page of the input property box object.
 * @param[in]  rpBox The input property box object.
 * @param[in]  pPage The input property page.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRResourcePropertyBoxSetCurrentPropertyPage, (FR_ResourcePropertyBox rpBox,  FR_ResourcePropertyPage pPage))

/**
 * @brief FRResourcePropertyBoxRegisterPropertyPage2
 * @details Registers the callbacks used to add the new property page to the property box.
 * @param[in]  rpBox The input property box object.
 * @param[in]  pPage The input callbacks used to add the new property page to the property box.
 * @return   The page object that needs to be destroyed by <a>FRResourcePropertyBoxDestroyPage</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see FRResourcePropertyBoxDestroyPage
	
 * @Deprecated    Internal use
 */
INTERFACE(void*, FRResourcePropertyBoxRegisterPropertyPage2, (FR_ResourcePropertyBox rpBox,  FR_ResourcePropertyPageCallbacks pPage))

/**
 * @brief FRResourcePropertyBoxDestroyPage
 * @details Destroys the page object returned by <a>FRResourcePropertyBoxRegisterPropertyPage2</a>.
 * @param[in]  pPage The page object returned by <a>FRResourcePropertyBoxRegisterPropertyPage2</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see FRResourcePropertyBoxRegisterPropertyPage2
	
 * @Deprecated    Internal use
 */
INTERFACE(void, FRResourcePropertyBoxDestroyPage, (void* pPage))

/**
 * @brief FRResourcePropertyBoxRegisterSourceType2
 * @details Registers the source type.
 * @param[in]  rpBox The input property box object.
 * @param[in]  nSource The input source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @param[in]  bLockButton Indicates whether to show the check box used to lock the source.
 * @param[in]  pSourceFunc The input callbacks used to deal with the source of the property box.
 * @param[in]  pNotifyFunc The input callbacks that will be called when events occur.
 * @return   The source object that needs to be destroyed by <a>FRResourcePropertyBoxDestroySource</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRResourcePropertyBoxDestroySource
	
 * @Deprecated    Internal use
 */
INTERFACE(void*, FRResourcePropertyBoxRegisterSourceType2, (FR_ResourcePropertyBox rpBox,  FS_INT32 nSource,  FS_BOOL bLockButton,  FR_ResourcePropertySourceCallbacks pSourceFunc,  FR_ResourcePropertyNotifyCallbacks pNotifyFunc))

/**
 * @brief FRResourcePropertyBoxDestroySource
 * @details Destroys the source object returned by <a>FRResourcePropertyBoxRegisterSourceType2</a>.
 * @param[in]  pPage The source object returned by <a>FRResourcePropertyBoxRegisterSourceType2</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see FRResourcePropertyBoxRegisterSourceType2
	
 * @Deprecated    Internal use
 */
INTERFACE(void, FRResourcePropertyBoxDestroySource, (void* pSource))

/**
 * @brief FRResourcePropertyBoxAddPropertyNotify
 * @details Add new notify to the specified pSource.
 * @param[in]  rpBox The input property box object.
 * @param[in]  pSourceFunc The input FR_ResourcePropertySource, it get from FRResourcePropertyBoxGetSourceFunc.
 * @param[in]  pNotifyFunc The input callbacks that will be called when events occur.
 * @return   The source object that needs to be destroyed by <a>FRResourcePropertyBoxDestroySource</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.1.0
 * @see FRResourcePropertyBoxDestroySource
	
 * @Deprecated    Internal use
 */
INTERFACE(void*, FRResourcePropertyBoxAddPropertyNotify, (FR_ResourcePropertyBox rpBox,  FR_ResourcePropertySource pSource,  FR_ResourcePropertyNotifyCallbacks pNotifyFunc))

NumOfSelector(FRResourcePropertyBox)
ENDENUM

//----------_V6----------
//*****************************
/* ScrollBarThumbnailView HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRScrollBarThumbnailViewGetCurPageIndex
 * @details Gets the index of page currently displayed in the scroll bar thumbnail view.
 * @param[in]  tv The input scrollbar thumbnail view.
 * @return   The index of page currently displayed in the scroll bar thumbnail view.
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRScrollBarThumbnailViewGetCurPageIndex, (FR_ScrollBarThumbnailView tv))

/**
 * @brief FRScrollBarThumbnailViewGetPageRect
 * @details Gets the rectangle of specified visible page in the scroll bar thumbnail view.
 * @param[in]  tv The input scrollbar thumbnail view.
 * @return   The rectangle of specified visible page in the scroll bar thumbnail view.
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FS_Rect, FRScrollBarThumbnailViewGetPageRect, (FR_ScrollBarThumbnailView tv))

/**
 * @brief FRScrollBarThumbnailViewGetPDPage
 * @details Gets a <a>FPD_Page</a> object of the input scrollbar thumbnail view.
 * @param[in]  tv The input scrollbar thumbnail view.
 * @return   The <a>FPD_Page</a> object.
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FPD_Page, FRScrollBarThumbnailViewGetPDPage, (FR_ScrollBarThumbnailView tv))

NumOfSelector(FRScrollBarThumbnailView)
ENDENUM

//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
//----------_V11----------
//----------_V12----------
//----------_V13----------
//----------_V14----------
//*****************************
/* Redaction HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRedactionApplyDoc
 * @details Apply redaction in the document: remove the text or graphics under marked areas permanently.
 * @param[in]  frDocument The opened pdf document
 * @param[in]  bSlient if it sets FALSE, the redaction explain dialog will display before redacting.
 * @return   <a>TRUE</a> If apply redaction in the document successfully, otherwise not.
 * @note Once this functions is called, all the marked page content(text object, image object, and path object) in the document will be removed permanently.
 */
INTERFACE(FS_BOOL, FRRedactionApplyDoc, (FR_Document frDocument,  FS_BOOL bSlient))

/**
 * @brief FRRedactionApply
 * @details Apply redaction in marked areas: remove the text or graphics under marked areas permanently.
 * @param[in]  frDocument The opened pdf document
 * @param[in]  annots The array of <a>FR_Annot</a> is prepared to apply
 * @param[in]  bSlient if it sets FALSE, the redaction explain dialog will display before redacting.
 * @return   <a>TRUE</a> If apply redaction in the document successfully, otherwise not.
 * @note Once this functions is called, the content(text object, image object, and path object) in the annots array will be removed permanently.
 */
INTERFACE(FS_BOOL, FRRedactionApply, (FR_Document frDocument,  FS_PtrArray annots,  FS_BOOL bSlient))

/**
 * @brief FRRedactionApplyDoc2
 * @details Apply redaction in the document: remove the text or graphics under marked areas permanently.
 * @param[in]  frDocument The opened pdf document
 * @param[in]  bSlient if it sets FALSE, the redaction explain dialog will display before redacting.
 * @param[in]  option Set the redact options.
 * @return   <a>TRUE</a> If apply redaction in the document successfully, otherwise not.
 * @note Once this functions is called, all the marked page content(text object, image object, and path object) in the document will be removed permanently.
 */
INTERFACE(FS_BOOL, FRRedactionApplyDoc2, (FR_Document frDocument,  FS_BOOL bSlient,  FR_RedactOption option))

NumOfSelector(FRRedaction)
ENDENUM

//*****************************
/* Reader HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRReaderCreateDispViewer
 * @details Create an <a>FR_IReader_DispViewer</a> object based on the input document view and set the callback handle.
 * @param[in]  pDocView The document view object.
 * @param[in]  pHandler Callback handle from <a>FRIReaderDispViewerHandlerNew</a>
 * @return   The <a>FR_IReader_DispViewer</a> object.
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FR_IReader_DispViewer, FRReaderCreateDispViewer, (FR_DocView pDocView,  FR_IReader_DispViewerHandler  pHandler))

/**
 * @brief FRReaderGetDocView
 * @details Get the document view object of the input reader dispViewer object.
 * @param[in]  DispViewer The reader dispViewer object.
 * @return   The <a>FR_DocView</a> object.
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FR_DocView, FRReaderGetDocView, (FR_IReader_DispViewer DispViewer))

/**
 * @brief FRReaderSetSize
 * @details Set the size of the reader dispViewer object according to the input parameters.
 * @param[in]  DispViewer The reader dispViewer object.
 * @param[in]  nSizeX The width of the reader dispViewer object size to set.
 * @param[in]  nSizeY The height of the reader dispViewer object size to set.
 * @return   void.
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRReaderSetSize, (FR_IReader_DispViewer DispViewer,  FS_INT32 nSizeX,  FS_INT32 nSizeY))

/**
 * @brief FRReaderGetRenderData
 * @details Gets the rendering data of the input reader dispViewer object.
 * @param[in]  DispViewer The reader dispViewer object.
 * @return   A <a>FS_DIBitmap</a> object of the reader dispViewer object.. This <a>FS_DIBitmap</a> object must be destroied by calling
    * <a>FSDIBitmapDestroy</a>().
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FS_DIBitmap, FRReaderGetRenderData, (FR_IReader_DispViewer DispViewer))

INTERFACE(void, FRReaderContinueRendering, (FR_IReader_DispViewer DispViewer))

/**
 * @brief FRReaderSetCenterPos
 * @details Set the center position of the reader dispViewer object according to the input parameters
 * @param[in]  DispViewer The reader dispViewer object.
 * @param[in]  nPage The index of the pdf viewer page.
 * @param[in]  dbZoom The zoom factor, specified as a magnification factor(for example, 1.0 displays the document at actual size).
 * @param[in]  pt The center point to set.
 * @return   void.
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRReaderSetCenterPos, (FR_IReader_DispViewer DispViewer,  FS_INT32 nPage,  double dbZoom,  FS_FloatPoint pt))

/**
 * @brief FRReaderDocToWindow
 * @details Transforms a point from user space to device space.
 * @param[in]  DispViewer The reader dispViewer object.
 * @param[in]  nPage The index of the pdf viewer page.
 * @param[in]  doc_x The x-coordinate of the point to transform, specified in user space coordinates.
 * @param[in]  doc_y The y-coordinate of the point to transform, specified in user space coordinates.
 * @param[in]  window_x The Y coordinate of the converted point is specified by the equipment space coordinate.
 * @param[in]  window_y The Y coordinate of the converted point is specified by the equipment space coordinate.
 * @return   void.
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRReaderDocToWindow, (FR_IReader_DispViewer DispViewer,  FS_INT32 nPage,  FS_FLOAT doc_x,  FS_FLOAT doc_y,  FS_INT64& window_x,  FS_INT64& window_y))

/**
 * @brief FRReaderGetCurrentMatrix
 * @details Get a matrix from PDF/XFA user space to targeted device space,
    * according to metrics info(top-left position and widht-height size) provided in the pdf viewer page.
 * @param[in]  DispViewer The Reader DispViewer Object.
 * @param[in]  nPage The index of the pdf viewer page.
 * @param[in]  matrix It receives the transform matrix from PDF/XFA user space to targeted device space.
 * @return   <a>TRUE</a> If get a matrix from PDF/XFA user space to targeted device space successfully, otherwise not.
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOL, FRReaderGetCurrentMatrix, (FR_IReader_DispViewer DispViewer,  FS_INT32 nPage,  FS_AffineMatrix& matrix))

/**
 * @brief FRReaderGetSize
 * @details Get the size of the reader dispViewer object.
 * @param[in]  DispViewer The Reader DispViewer Object.
 * @param[in]  nSizeX The width of the reader dispViewer object size.
 * @param[in]  nSizeY The height of the reader dispViewer object size.
 * @return   void.
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRReaderGetSize, (FR_IReader_DispViewer DispViewer,  FS_INT32 &nSizeX,  FS_INT32 &nSizeY))

/**
 * @brief FRReaderDestroyDispViewer
 * @details Destroy display view.
 * @param[in]  DispViewer The Reader DispViewer Object.
 * @return   void.
 * @note * See:
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 * @Deprecated    Internal use
 */
INTERFACE(void, FRReaderDestroyDispViewer, (FR_IReader_DispViewer DispViewer))

NumOfSelector(FRReader)
ENDENUM

//*****************************
/* IReaderDispViewerHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRIReaderDispViewerHandlerNew
 * @details Creates a reader dispViewer callback handle based on the incoming callback parameter pointer.
 * @param[in]  callbacks The callback parameter pointer.
 * @return   The <a>FR_IReader_DispViewerHandler</a> object.
 * @note The callback handle that needs to be destroyed by <a>FRIReaderDispViewerHandlerDestroy</a>.
 * @see FRIReaderDispViewerHandlerDestroy
    
 * @Deprecated    Internal use.
 */
INTERFACE(FR_IReader_DispViewerHandler, FRIReaderDispViewerHandlerNew, (FR_IReader_DispViewerHandlerCallbacksRec* callbacks))

/**
 * @brief FRIReaderDispViewerHandlerDestroy
 * @details Destroys the input callback handle
 * @param[in]  handler The reader dispViewer callback handle.
 * @return   void.
 * @note The callback handle that needs to be created by <a>FRIReaderDispViewerHandlerNew</a>.
 * @see FRIReaderDispViewerHandlerNew
    
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRIReaderDispViewerHandlerDestroy, (FR_IReader_DispViewerHandler handler))

NumOfSelector(FRIReaderDispViewerHandler)
ENDENUM

//*****************************
/* IPDFViewerEventHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRIPDFViewerEventHandlerNew
 * @details Creates a pdf viewer event callback handle based on the incoming callback parameter pointer.
 * @param[in]  callbacks The callback parameter pointer.
 * @return   The <a>FR_IPDFViewerEventHandler</a> object.
 * @note The callback handle that needs to be destroyed by <a>FRIPDFViewerEventHandlerDestroy</a>.
 * @see FRIPDFViewerEventHandlerDestroy
    
 * @Deprecated    Internal use.
 */
INTERFACE(FR_IPDFViewerEventHandler, FRIPDFViewerEventHandlerNew, (FPD_IPDFViewerEventHandlerCallbacksRec* callbacks))

/**
 * @brief FRIPDFViewerEventHandlerDestroy
 * @details Destroys the input callback handle
 * @param[in]  handler The pdf viewer event callback handle.
 * @return   void.
 * @note The callback handle that needs to be created by <a>FRIPDFViewerEventHandlerNew</a>.
 * @see FRIPDFViewerEventHandlerNew
    
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRIPDFViewerEventHandlerDestroy, (FR_IPDFViewerEventHandler handler))

NumOfSelector(FRIPDFViewerEventHandler)
ENDENUM

//*****************************
/* ToolFormatMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRToolFormatMgrGet
 * @details Gets the FS_HWND of of ToolFormatMgr.
 * @param[in]  hFrame The  main application 's mainFrame, it can be set Null.
 * @return   The FS_HWND of ToolFormatMgr.
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
 * @see 
 */
INTERFACE(FR_ToolFormatMgr, FRToolFormatMgrGet, (FS_HWND hFrame))

/**
 * @brief FRToolFormatMgrRegistFormatEvent
 * @details Register the ToolFormatMgr callback.
 * @param[in]  toolFormatMgr The ToolFormatMgr Object.
 * @param[in]  formatEventCallbacks The callback set. Reader will call a corresponding callback when the ToolFormatMgr event occurs.
 * @return   The Address of FormatEventHandler.
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
 * @see 
 */
INTERFACE(FS_LPVOID, FRToolFormatMgrRegistFormatEvent, (FR_ToolFormatMgr toolFormatMgr,  FR_FormatEventCallbacks formatEventCallbacks))

/**
 * @brief FRToolFormatMgrUnregisterFormatEvent
 * @details Unregisters the ToolFormatMgr handler and releases the memory.
 * @param[in]  toolFormatMgr The ToolFormatMgr Object.
 * @param[in]  pFormatToolEvent The Address of FormatEventHandler.
 * @return   <a>TRUE</a> If unregisters the ToolFormatMgr handler and releases the memory successfully, otherwise not.
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRToolFormatMgrUnregisterFormatEvent, (FR_ToolFormatMgr toolFormatMgr,  FS_LPVOID pFormatToolEvent))

/**
 * @brief FRToolFormatMgrAddGroup
 * @details Add a group for the whole mainframe
 * @param[in]  toolFormatMgr The ToolFormatMgr Object.
 * @param[in]  bsGroupName The unique identify of Group.
 * @param[in]  wsTitle The Group Title.
 * @param[in]  hWnd It is used to display the sub window in the group. It is recommended to use the dialog box
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
 * @see 
 */
INTERFACE(void, FRToolFormatMgrAddGroup, (FR_ToolFormatMgr toolFormatMgr,  FS_ByteString bsGroupName,  FS_WideString wsTitle,  FS_HWND hWnd))

/**
 * @brief FRToolFormatMgrAddGroupToFormat
 * @details Add group to format. Format is for the entire mainframe
 * @param[in]  toolFormatMgr The ToolFormatMgr Object.
 * @param[in]  bsFormatName Format unique identity.
 * @param[in]  bsGroupName The groupname contained in the format.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
 * @see 
 */
INTERFACE(void, FRToolFormatMgrAddGroupToFormat, (FR_ToolFormatMgr toolFormatMgr,  FS_ByteString bsFormatName,  FS_ByteString bsGroupName))

/**
 * @brief FRToolFormatMgrShowToolFormat
 * @details This functioin is used to show the format.In addition,only one user-defined format can be showed at the time.
 * @param[in]  toolFormatMgr The ToolFormatMgr Object.
 * @param[in]  bsFormatName Format unique identity.
 * @param[in]  wsFormatTitle The Title of ToolFormatMgr.
 * @return   NULL
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
 * @see 
 */
INTERFACE(void, FRToolFormatMgrShowToolFormat, (FR_ToolFormatMgr toolFormatMgr,  FS_ByteString bsFormatName,  FS_WideString wsFormatTitle))

/**
 * @brief FRToolFormatMgrIsToolFormatExist
 * @details determine whether the format Exist.
 * @param[in]  toolFormatMgr The ToolFormatMgr Object.
 * @param[in]  bsFormatName This agument is't used now and  reserved for future's extentions.Morever,the current tile is format by default;
 * @return   <a>TRUE</a> If the format Exist, otherwise not.
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
 * @see 
 */
INTERFACE(bool, FRToolFormatMgrIsToolFormatExist, (FR_ToolFormatMgr toolFormatMgr,  FS_ByteString bsFormatName))

/**
 * @brief FRToolFormatMgrGetFormatGroups
 * @details Get the format's name and group names.
 * @param[in]  toolFormatMgr The ToolFormatMgr Object.
 * @param[in]  bsFormatName The name of format.
 * @param[out]  bsGroupNames The group names of format.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
 * @see 
 */
INTERFACE(void, FRToolFormatMgrGetFormatGroups, (FR_ToolFormatMgr toolFormatMgr,  FS_ByteString bsFormatName,  FS_ByteStringArray bsGroupNames))

/**
 * @brief FRToolFormatMgrChangeFormatSize
 * @details The recalculated size according to the current window size of the format group and the layout of the displayed controls
 * @param[in]  toolFormatMgr The ToolFormatMgr Object.
 * @param[in]  bsFormatName The name of format.
 * @param[in]  wsGroupName The group name of format.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRToolFormatMgrChangeFormatSize, (FR_ToolFormatMgr toolFormatMgr,  FS_ByteString bsFormatName,  FS_ByteString bsGroupName))

/**
 * @brief FRToolFormatMgrUpdateFormatStatus
 * @details Update the format status on the right panel
 * @param[in]  toolFormatMgr The ToolFormatMgr Object.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
 * @see 
 */
INTERFACE(void, FRToolFormatMgrUpdateFormatStatus, (FR_ToolFormatMgr toolFormatMgr))

/**
 * @brief FRToolFormatMgrShowToolFormat2
 * @details Update the format status on the right panel
 * @param[in]  toolFormatMgr The ToolFormatMgr Object.
 * @param[in]  bsFormatName The	format unique identifier.
 * @param[in]  wsFormatTitle The title of used for display
 * @param[in]  nFormatType Format type.
 * @param[in]  bAlwaysActivationFormat Whether need always activate format.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 * @see 
 */
INTERFACE(void, FRToolFormatMgrShowToolFormat2, (FR_ToolFormatMgr toolFormatMgr,  FS_LPCSTR bsFormatName,  FS_LPCWSTR wsFormatTitle,  FR_FormatType nFormatType,  FS_BOOLEAN bAlwaysActivationFormat))

/**
 * @brief FRToolFormatMgrGetLastToolFormatName
 * @details Get the lat format tool name.
 * @param[in]  toolFormatMgr The ToolFormatMgr Object.
 * @param[in]  pDoc The input FR_Document object.
 * @param[in\out]  outName Get the format name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRToolFormatMgrGetLastToolFormatName, (FR_ToolFormatMgr toolFormatMgr,  FR_Document pDoc,  FS_ByteString* outName))

NumOfSelector(FRToolFormatMgr)
ENDENUM

//*****************************
/* TextSelectedData HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRTextSelectedDataNew
 * @details Create <a>FR_TextSelectedData</a> object.
 * @return   The <a>FR_TextSelectedData</a> object.
 * @note The object that needs to be destroyed by <a>FRTextSelectedDataDestroy</a>.
 * @see FRTextSelectedDataDestroy
 */
INTERFACE(FR_TextSelectedData, FRTextSelectedDataNew, ())

/**
 * @brief FRTextSelectedDataDestroy
 * @details Destroy <a>FR_TextSelectedData</a> object.
 * @param[in]  data The input FR_TextSelectedData object.
 * @return   void.
 * @note The object that needs to be created by <a>FRTextSelectedDataNew</a>.
 * @see FRTextSelectedDataNew
 */
INTERFACE(void, FRTextSelectedDataDestroy, (FR_TextSelectedData data))

/**
 * @brief FRTextSelectedDataGetSelectedPages
 * @details Get all the pages with selected text.
 * @param[in]  data The input FR_TextSelectedData object.
 * @param[out]  outindexArr Get selected text of the pages.
 * @return   void.
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectedDataGetSelectedPages, (FR_TextSelectedData data,  FS_Int32Array* outindexArr))

/**
 * @brief FRTextSelectedDataGetSelectedDataCountByPageIndex
 * @details Get the count of selected datas of the pageindex.
 * @param[in]  data The input FR_TextSelectedData object.
 * @param[in]  index The index of page.
 * @return   The count of selected datas of the pageindex.
 * @note 
 * @see 
 */
INTERFACE(FS_INT32, FRTextSelectedDataGetSelectedDataCountByPageIndex, (FR_TextSelectedData data,  FS_INT32 index))

/**
 * @brief FRTextSelectedDataGetSelectedDatas
 * @details Get the selected msg of the page index in the vector.
 * @param[in]  data The input FR_TextSelectedData object.
 * @param[in]  index The index of page.
 * @param[in]  vecIndex The index of the selected datas.
 * @return   The <a>FR_SELECTMSG</a> object.
 * @note 
 * @see 
 */
INTERFACE(FR_SELECTMSG, FRTextSelectedDataGetSelectedDatas, (FR_TextSelectedData data,  FS_INT32 index,  FS_INT32 vecIndex))

NumOfSelector(FRTextSelectedData)
ENDENUM

//*****************************
/* IRPPropertySource HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRIRPPropertySourceGetSelectObjectType
 * @details Get the count of the selected object.
 * @param[in]  source The input FR_ResourcePropertySource object.
 * @param[out]  array The select object array.
 * @return   The count of the selected object..
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FS_INT32, FRIRPPropertySourceGetSelectObjectType, (FR_ResourcePropertySource source,  FS_ByteStringArray* outarray))

/**
 * @brief FRIRPPropertySourceCountSelectObjects
 * @details Get the count of the selected object.
 * @param[in]  source The input FR_ResourcePropertySource object.
 * @return   The count of the selected object..
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FS_INT32, FRIRPPropertySourceCountSelectObjects, (FR_ResourcePropertySource source))

/**
 * @brief FRIRPPropertySourceGetSelectObject
 * @details Get the object at the index.
 * @param[in]  source The input FR_ResourcePropertySource object.
 * @param[in]  index The index of the object to return.
 * @return   The count of the selected object..
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void*, FRIRPPropertySourceGetSelectObject, (FR_ResourcePropertySource source,  FS_INT32 nObjIndex))

/**
 * @brief FRIRPPropertySourceSetPropertySourceCallback
 * @details Set the property source callback, to enable plugin change title.
 * @param[in]  source The input FR_ResourcePropertySource object.
 * @param[in]  pcallback The input property source callback.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRIRPPropertySourceSetPropertySourceCallback, (FR_ResourcePropertySource source,  FR_PropertySourceCallbacksRec pcallback))

NumOfSelector(FRIRPPropertySource)
ENDENUM

//*****************************
/* LayerOperation HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRLayerOperationCreate
 * @details Creates layer opearation tool which is used to process the operation of layer object.
 * @param[in]  doc The input doc where the operation of layer.
 * @param[in]  nSourcePageIndex The index of source page.
 * @param[in]  wsDocName The name of doc.
 * @return   The <a>FR_LayerOperation</a> object.
 * @note The object that needs to be destroyed by <a>FRLayerOperationDestroy</a>.
 * @see FRLayerOperationDestroy
    
 * @Deprecated    Internal use.
 */
INTERFACE(FR_LayerOperation, FRLayerOperationCreate, (FPD_Document doc,  FS_INT32 nSourcePageIndex,  FS_LPCWSTR wsDocName))

/**
 * @brief FRLayerOperationDestroyLayerOperation
 * @details Destroys the layer operation tool object.
 * @param[in]  layerOperationTool The input layer operation tool object.
 * @return   void
 * @note The object that needs to be created by <a>FRLayerOperationCreate</a>.
 * @see FRLayerOperationCreate
    
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRLayerOperationDestroyLayerOperation, (FR_LayerOperation layerOperationTool))

/**
 * @brief FRLayerOperationImportLayer
 * @details Import a layer to the selected page of the source document
 * @param[in]  layerOperationTool The input layer operation tool.
 * @param[in]  pImportDoc The import document.
 * @param[in]  nImportPageIndex The selected page index of the import document.
 * @param[in]  wsImportDocName The name of the import document .
 * @param[in]  importFormBox Import form box rect.
 * @param[in]  sourceRectPreview Source document preview rect.
 * @param[in]  importRectPreview Import document preview rect.
 * @param[in]  nImportOpacity the opacity of imported layers.
 * @param[in]  IsImportBehindSource Is import behind the source.
 * @param[in]  wsOCGName Layer's name.
 * @param[in]  type Import type.
 * @param[in]  importToImportFormKey The old Form XObject object group in the source file needs a one-to-one correspondence with <param>importToImportFormValue</param>.
 * @param[in]  importToImportFormValue The new Form XObject object group to be imported in the import file needs to have a one-to-one correspondence with <param>importToImportFormKey</param>.
 * @param[in]  addToGroupName If type is "IMPORT_CREATE", it is the OCGGroup name of source document.
 * @return   <a>TRUE</a> If import a layer to the selected page of the source document successfully, otherwise not.
 * @note <param>importToImportFormKey</param> <param>importToImportFormValue</param> purpose: when importing the layer information related to the import page to the source document,
    * you can update the indirect reference places of these page objects according to this map.
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRLayerOperationImportLayer, (FR_LayerOperation layerOperationTool,  FPD_Document pImportDoc,  FS_INT32 nImportPageIndex,  FS_LPCWSTR wsImportDocName,  FS_FloatRect importFormBox,  FS_Rect sourceRectPreview,  FS_Rect importRectPreview,  FS_INT32 nImportOpacity,  FS_BOOL IsImportBehindSource,  FS_LPCWSTR wsOCGName,  FR_ImportType type,  FS_DWordArray importToImportFormKey,  FS_DWordArray importToImportFormValue,  FS_LPCWSTR addToGroupName))

/**
 * @brief FRLayerOperationIsChildOCG
 * @details Judge whether one OCG exists in the input layer operation tool.
 * @param[in]  layerOperationTool The input layer operation tool.
 * @param[in]  ocgSet The OCGroupSet to judge
 * @param[in]  parent The parent OCGroup
 * @param[in]  target The target OCGroup
 * @return   <a>TRUE</a> If one OCG exists in the input layer operation tool, otherwise not.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRLayerOperationIsChildOCG, (FR_LayerOperation layerOperationTool,  FPD_OCGroupSet ocgSet,  FPD_OCGroup parent,  FPD_OCGroup target))

/**
 * @brief FRLayerOperationDeleteOCG
 * @details Delete one OCG from the input layer operation tool.
 * @param[in]  layerOperationTool The input layer operation tool.
 * @param[in]  ocgSet The OCGroupSet to delete
 * @param[in]  ocgGroup The parent OCGroup
 * @return   <a>TRUE</a> If delete one OCG from the input layer operation tool successfully, otherwise not.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRLayerOperationDeleteOCG, (FR_LayerOperation layerOperationTool,  FPD_OCGroupSet ocgSet,  FPD_OCGroup ocgGroup))

/**
 * @brief FRLayerOperationReplaceOCG
 * @details Replace one OCG to the input layer operation tool.
 * @param[in]  layerOperationTool The input layer operation tool.
 * @param[in]  pDoc The document
 * @param[in]  ocgSet The OCGroupSet to be repalced
 * @param[in]  toBeReplaced The parent OCGroup
 * @param[in]  target The target OCGroup
 * @return   <a>TRUE</a> If replace one OCG to the input layer operation tool successfully, otherwise not.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRLayerOperationReplaceOCG, (FR_LayerOperation layerOperationTool,  FPD_Document pDoc,  FPD_OCGroupSet ocgSet,  FPD_OCGroup toBeReplaced,  FPD_OCGroup target))

/**
 * @brief FRLayerOperationReplaceOCGContentHandler
 * @details Replace one OCG content to the input layer operation tool.
 * @param[in]  layerOperationTool The input layer operation tool.
 * @param[in]  pDoc The document
 * @param[in]  pDict The object rect
 * @param[in]  toBeReplaced The parent OCGroup
 * @param[in]  target The target OCGroup
 * @return   <a>TRUE</a> If replace one OCG content to the input layer operation tool successfully, otherwise not.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRLayerOperationReplaceOCGContentHandler, (FR_LayerOperation layerOperationTool,  FPD_Document pDoc,  FPD_Object pDict,  FPD_OCGroup toBeReplaced,  FPD_OCGroup target))

/**
 * @brief FRLayerOperationInsertChildOCG
 * @details Insert one OCG to the input layer operation tool.
 * @param[in]  layerOperationTool The input layer operation tool.
 * @param[in]  pDoc The document
 * @param[in]  ocgSet The OCGroupSet to be inserted
 * @param[in]  target The target OCGroup
 * @param[in]  arr The layer data point array
 * @return   <a>TRUE</a> If insert one OCG to the input layer operation tool successfully, otherwise not.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRLayerOperationInsertChildOCG, (FR_LayerOperation layerOperationTool,  FPD_Document pDoc,  FPD_OCGroupSet ocgSet,  FPD_OCGroup target,  FS_PtrArray arr))

/**
 * @brief FRLayerOperationDeleteObjectByVisible
 * @details delete OCG by visible
 * @param[in]  layerOperationTool The input layer operation tool.
 * @param[in]  containe The object to be deleted is a type in <a>FPD_Page</a> or <a>FPD_Form</a>.
 * @param[in]  pContext The input optional content context.
 * @param[in]  isPage Used to determine the type of parameter <a>containe</a>, <a>TRUE</a> is <a>FPD_Page</a> and <a>FALSE</a> is <a>FPD_Form</a>.
 * @return   void.
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRLayerOperationDeleteObjectByVisible, (FR_LayerOperation layerOperationTool,  FS_LPVOID container,  FPD_OCContext pContext,  FS_BOOL isPage))

NumOfSelector(FRLayerOperation)
ENDENUM

//----------_V15----------
//*****************************
/* FormTextFind HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRFormTextFindCreateFormTextFind
 * @details Create FR_FormTextFind.
 * @param[in]  pDoc The input FPD_Document.
 * @param[in]  pPage The input FPD_Page.
 * @return   void.
 * @note 
 * @see 
 */
INTERFACE(FR_FormTextFind, FRFormTextFindCreateFormTextFind, (FPD_Document pDoc,  FPD_Page pPage))

/**
 * @brief FRFormTextFindDeleteFormTextFind
 * @details Delete FR_FormTextFind.
 * @param[in]  formTextFind The input FR_FormTextFind.
 * @return   void.
 * @note 
 * @see 
 */
INTERFACE(void, FRFormTextFindDeleteFormTextFind, (FR_FormTextFind formTextFind))

/**
 * @brief FRFormTextFindFindFirst
 * @details Before find, need to set some information.
 * @param[in]  formTextFind The input FR_FormTextFind.
 * @param[in]  findwhat The input find content.
 * @param[in]  flags The input FR_FormTextFind. Like FPD_TEXT_MATCHCASE.
 * @return   FS_BOOL.           TRUE : Initialize success.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FRFormTextFindFindFirst, (FR_FormTextFind formTextFind,  FS_LPCWSTR findwhat,  FS_INT32 flags))

/**
 * @brief FRFormTextFindFindNext
 * @details Find next form text.
 * @param[in]  formTextFind The input FR_FormTextFind.
 * @return   FS_BOOL            TRUE : Find success.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FRFormTextFindFindNext, (FR_FormTextFind formTextFind))

/**
 * @brief FRFormTextFindFindPrev
 * @details Find pre form text.
 * @param[in]  formTextFind The input FR_FormTextFind.
 * @return   FS_BOOL            TRUE : Find success.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FRFormTextFindFindPrev, (FR_FormTextFind formTextFind))

/**
 * @brief FRFormTextFindGetRectArray
 * @details Get the rect array of the find text.
 * @param[in]  formTextFind The input FR_FormTextFind.
 * @param[out]  rects Get the rect array of the find text.
 * @return   FS_BOOL            TRUE : Find success.
 * @note 
 * @see 
 */
INTERFACE(void, FRFormTextFindGetRectArray, (FR_FormTextFind formTextFind,  FS_FloatRectArray* rects))

NumOfSelector(FRFormTextFind)
ENDENUM

//----------_V16----------
//*****************************
/* PDFVerwerContentProviderEx HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPDFVerwerContentProviderExCreatePDFVerwerContentProviderEx
 * @details Create FR_PDFVerwerContentProviderEx.
 * @param[in]  callback The input FR_PDFVerwerContentProviderCallbacks.
 * @return   FR_PDFVerwerContentProviderEx
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_PDFVerwerContentProviderEx, FRPDFVerwerContentProviderExCreatePDFVerwerContentProviderEx, (FR_PDFVerwerContentProviderCallbacks callback))

/**
 * @brief FRPDFVerwerContentProviderExDeletePDFVerwerContentProviderEx
 * @details Delete FR_PDFVerwerContentProviderEx.
 * @param[in]  provider The input FR_PDFVerwerContentProviderEx.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFVerwerContentProviderExDeletePDFVerwerContentProviderEx, (FR_PDFVerwerContentProviderEx provider))

NumOfSelector(FRPDFVerwerContentProviderEx)
ENDENUM

//*****************************
/* PDFViewer HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPDFViewerCreatePDFViewer
 * @details Create FR_PDFViewer .
 * @param[in]  provider The input FR_PDFVerwerContentProviderEx.
 * @param[in]  nLayout The input layout mode, like FRD_LAYOUT_PREVIEW.
 * @param[in]  bPreCalcPages Whether need to calculate pages before.
 * @param[in]  nPreCalcPagesLimit The max of page count.
 * @param[in]  dbScale The viewer scale.
 * @return   FR_PDFViewer
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_PDFViewer, FRPDFViewerCreatePDFViewer, (FR_PDFVerwerContentProviderEx provider,  FS_INT32 nLayout,  FS_BOOLEAN bPreCalcPages,  FS_INT32 nPreCalcPagesLimit,  FS_FLOAT dbScale))

/**
 * @brief FRPDFViewerGetPageCount
 * @details Get the page count of viewer.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @return   FS_INT32
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPDFViewerGetPageCount, (FR_PDFViewer pdfviewer))

/**
 * @brief FRPDFViewerGetPage
 * @details Get the FR_PDFViewerPage.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  nIndex The input page index.
 * @return   FR_PDFViewerPage
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_PDFViewerPage, FRPDFViewerGetPage, (FR_PDFViewer pdfviewer,  FS_INT32 nIndex))

/**
 * @brief FRPDFViewerGetCurrentPageIndex
 * @details Get the current page index of viewer.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @return   FS_INT32
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPDFViewerGetCurrentPageIndex, (FR_PDFViewer pdfviewer))

/**
 * @brief FRPDFViewerGotoPage
 * @details Go to the specified page.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  iPage The page index need go to.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerGotoPage, (FR_PDFViewer pdfviewer,  FS_INT32 iPage))

/**
 * @brief FRPDFViewerGotoPage2
 * @details Go to the specified destination.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  dest The dest position need go to.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerGotoPage2, (FR_PDFViewer pdfviewer,  FPD_Dest dest))

/**
 * @brief FRPDFViewerGotoPage3
 * @details Go to the specified destination.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  iPage The specified page index.
 * @param[in]  fLeft Set the left margin of page viewer.
 * @param[in]  fTop Set the top margin of page viewer.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerGotoPage3, (FR_PDFViewer pdfviewer,  FS_INT32 iPage,  FS_FLOAT fLeft,  FS_FLOAT fTop))

/**
 * @brief FRPDFViewerGetZoomScale
 * @details Get the zoom scale.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @return   FS_FLOAT
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_FLOAT, FRPDFViewerGetZoomScale, (FR_PDFViewer pdfviewer))

/**
 * @brief FRPDFViewerZoomtoPage
 * @details Zoom with specified property.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  iZoomMode The input zoom mode, like FRD_ZMODE_FIT_WIDTH.
 * @param[in]  dbScale The input scale.
 * @param[in]  iFitW The fit width value.
 * @param[in]  iFitH The fit height value.
 * @param[in]  bCalcScaleFromMode Whether need calculate scale from mode.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerZoomtoPage, (FR_PDFViewer pdfviewer,  FS_INT32 iZoomMode,  FS_FLOAT dbScale,  FS_INT32 iFitW,  FS_INT32 iFitH,  FS_BOOLEAN bCalcScaleFromMode))

/**
 * @brief FRPDFViewerSetPageRotate
 * @details Set page rotate.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  iRotate The the page rotate.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerSetPageRotate, (FR_PDFViewer pdfviewer,  FS_INT32 iRotate))

/**
 * @brief FRPDFViewerGetPageRotate
 * @details Get page rotate.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @return   FS_INT32
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPDFViewerGetPageRotate, (FR_PDFViewer pdfviewer))

/**
 * @brief FRPDFViewerSetSize
 * @details Set the size of the viewer.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  cx Set the width of the viewer.
 * @param[in]  cy Set the height of the viewer.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerSetSize, (FR_PDFViewer pdfviewer,  FS_INT32 cx,  FS_INT32 cy))

/**
 * @brief FRPDFViewerGetSize
 * @details Get the size of the viewer.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[out]  cx Get the width of the viewer.
 * @param[out]  cy Get the height of the viewer.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerGetSize, (FR_PDFViewer pdfviewer,  FS_INT32* cx,  FS_INT32* cy))

/**
 * @brief FRPDFViewerGetRenderData
 * @details Get the rendering bitmap.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  bProgressiveRender Get the width of the viewer.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_DIBitmap, FRPDFViewerGetRenderData, (FR_PDFViewer pdfviewer,  FS_BOOLEAN bProgressiveRender))

/**
 * @brief FRPDFViewerSetDisplayAnnot
 * @details Set if show annots.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  bShow Whether show annot.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerSetDisplayAnnot, (FR_PDFViewer pdfviewer,  FS_BOOL bShow))

/**
 * @brief FRPDFViewerGetCanvasWidth
 * @details Get the width of the current display.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @return   FS_INT32
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPDFViewerGetCanvasWidth, (FR_PDFViewer pdfviewer))

/**
 * @brief FRPDFViewerGetCanvasHeight
 * @details Get the height of the current display.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @return   FS_INT32
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPDFViewerGetCanvasHeight, (FR_PDFViewer pdfviewer))

/**
 * @brief FRPDFViewerGetScrollPosX
 * @details Get the scroll x position.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @return   FS_INT32
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPDFViewerGetScrollPosX, (FR_PDFViewer pdfviewer))

/**
 * @brief FRPDFViewerGetScrollPosY
 * @details Get the scroll y position.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @return   FS_INT32
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPDFViewerGetScrollPosY, (FR_PDFViewer pdfviewer))

/**
 * @brief FRPDFViewerScroll
 * @details Scroll to specified position.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  offsetX The offset of x axis.
 * @param[in]  offsetY The offset of y axis.
 * @param[in]  bOnlyInCurRow If show in a row.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerScroll, (FR_PDFViewer pdfviewer,  FS_INT32 offsetX,  FS_INT32 offsetY,  FS_BOOLEAN bOnlyInCurRow))

/**
 * @brief FRPDFViewerGetBrowserMode
 * @details Get the browser mode.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @return   FS_INT32
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPDFViewerGetBrowserMode, (FR_PDFViewer pdfviewer))

/**
 * @brief FRPDFViewerScrollToPosX
 * @details Get the browser mode.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  posX The input FR_PDFViewer.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerScrollToPosX, (FR_PDFViewer pdfviewer,  FS_INT32 posX))

/**
 * @brief FRPDFViewerScrollToPosY
 * @details Scroll to specified y position.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  posX The input scroll position y.
 * @param[in]  bNeedAdjust If need adjust.
 * @param[in]  bOnlyInCurRow If show in a row.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerScrollToPosY, (FR_PDFViewer pdfviewer,  FS_INT32 posY,  FS_BOOLEAN bNeedAdjust,  FS_BOOLEAN bOnlyInCurRow))

/**
 * @brief FRPDFViewerContinueRendering
 * @details If continue render.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @return   FS_BOOLEAN
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRPDFViewerContinueRendering, (FR_PDFViewer pdfviewer))

/**
 * @brief FRPDFViewerAddRecord
 * @details Add record info.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerAddRecord, (FR_PDFViewer pdfviewer))

/**
 * @brief FRPDFViewerSetViewEventHandler
 * @details Set view event handler to display the view.
 * @param[in]  pdfviewer The input FR_PDFViewer.
 * @param[in]  handler The input FR_IPDFViewerEventHandler.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerSetViewEventHandler, (FR_PDFViewer pdfviewer,  FR_IPDFViewerEventHandler handler))

/**
 * @brief FRPDFViewerDeletePDFViewer
 * @details Release pdf viewer.
 * @param[in]  viewer The input FR_PDFViewer.
 * @return   void
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFViewerDeletePDFViewer, (FR_PDFViewer pdfviewer))

NumOfSelector(FRPDFViewer)
ENDENUM

//*****************************
/* PDFViewerPage HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPDFViewerPageGetPageRect
 * @details Get the page rect.
 * @param[in]  viewerPage The input FR_PDFViewerPage.
 * @param[in]  bRecalc If need recalculate.
 * @return   FS_Rect
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_Rect, FRPDFViewerPageGetPageRect, (FR_PDFViewerPage viewerPage,  FS_BOOLEAN bRecalc))

/**
 * @brief FRPDFViewerPageIsVisible
 * @details Get if the viewer page is visible.
 * @param[in]  viewerPage The input FR_PDFViewerPage.
 * @return   FS_BOOLEAN
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRPDFViewerPageIsVisible, (FR_PDFViewerPage viewerPage))

/**
 * @brief FRPDFViewerPageGetPageIndex
 * @details Get the page index of the viewer page.
 * @param[in]  viewerPage The input FR_PDFViewerPage.
 * @return   FS_INT32
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPDFViewerPageGetPageIndex, (FR_PDFViewerPage viewerPage))

/**
 * @brief FRPDFViewerPageGetPageFullRect
 * @details Get the page full rect.
 * @param[in]  viewerPage The input FR_PDFViewerPage.
 * @return   FS_Rect
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_Rect, FRPDFViewerPageGetPageFullRect, (FR_PDFViewerPage viewerPage))

NumOfSelector(FRPDFViewerPage)
ENDENUM

//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------

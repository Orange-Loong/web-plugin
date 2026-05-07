/** @file fr_viewImpl.h.
 * 
 *  @brief FR views including DocView,PageView,NavgitionPanel .
 */

#ifndef FR_VIEWIMPL_H
#define FR_VIEWIMPL_H

#ifndef FR_VIEWEXPT_H
#include "../fr_viewExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../../pdf/fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../../pdf/fpd_objsExpT.h"
#endif

#ifndef FPD_RENDEREXPT_H
#include "../../pdf/fpd_renderExpT.h"
#endif

#ifndef FR_DOCEXPT_H
#include "../fr_docExpT.h"
#endif


#ifdef __cplusplus
extern "C"{
#endif

class CFR_DocView_V1
{
public:
    //************************************
    // Function:  GetDocument
    // Param[in]: docView			The document view whose <a>FR_Document</a>is obtained.
    // Return: The <a>FR_Document</a> associated with the document view.	
    // Remarks:	Gets the <a>FR_Document</a> associated with specifed document view..  	
    // Notes:
    // See: FRDocGetDocView
    // See: FRDocGetCurrentDocView
    // See: FRDocViewGetPageView
    // See: FRPageViewGetDocument
    //************************************
    static FR_Document			GetDocument(FR_DocView docView);

    //************************************
    // Function:  CountPageViews
    // Param[in]: docView			The document view whose page view count is obtained.
    // Return: The number of <a>FR_PageView</a> object associated with the document view.	
    // Remarks:	Gets the number of page views for the specified document view.  	
    // Notes:
    // See: FRDocViewGetPageView
    // See: FRDocViewCountVisiblePageViews
    //************************************
    static FS_INT32			CountPageViews(FR_DocView docView);

    //************************************
    // Function:  GetPageView
    // Param[in]: docView       The document view whose <a>FR_PageView</a> is obtained.
    // Param[in]: iPage			The index of page view to obtain. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
    // Return:	The specified <a>FR_PageView</a> of the document view.
    // Remarks: Gets the specified <a>FR_PageView</a> for specified document view. 
    // Notes:
    // See: FRDocViewCountPageViews
    // See: FRDocViewGetVisiblePageView
    // See: FRDocViewGetPageViewAtPoint
    // See: FRDocViewGetCurrentPageView
    //************************************
    static FR_PageView	GetPageView(FR_DocView docView, FS_INT32 iPage);

    //************************************
    // Function:  GetPageViewAtPoint
    // Param[in]: docView       The document view whose <a>FR_PageView</a> is obtained.
    // Param[in]: point			The point of screen coordinate system to obtain a page view.
    // Return: The specified <a>FR_PageView</a> of the document view if the point is in the area of the page view, otherwise 
    // <a>NULL</a>.
    // Remarks: Gets a specified <a>FR_PageView</a> with a point which is underlying to the area of page view.    
    // Notes:	
    // See: FRDocViewGetPageView
    // See: FRDocViewGetVisiblePageView
    // See: FRDocViewGetCurrentPageView
    //************************************
    static FR_PageView	GetPageViewAtPoint(FR_DocView docView, FS_DevicePoint point);

    //************************************
    // Function:  CountVisiblePageViews
    // Param[in]: docView			The document view whose page view count is obtained.
    // Return: The number of visible page views.	  
    // Remarks: Gets the number of visible page views for specified document view.   
    // Notes:	
    // See: FRDocViewCountPageViews
    //************************************
    static FS_INT32		CountVisiblePageViews(FR_DocView docView);

    //************************************
    // Function:  GetVisiblePageView
    // Param[in]: docView		The document view whose page view is obtained.
    // Param[in]: iPage			The index of the visible page. The index range is 0 to (<a>FRDocViewCountVisiblePageViews</a>()-1).
    // Return: The specified <a>FR_PageView</a>	of the document view.  
    // Remarks: Gets the specified visible page.  
    // Notes:	
    // See: FRDocViewGetPageView
    // See: FRDocViewGetPageViewAtPoint
    // See: FRDocViewGetCurrentPageView
    //************************************
    static FR_PageView	GetVisiblePageView(FR_DocView docView, FS_INT32 iPage);

    //************************************
    // Function:  GotoPageView
    // Param[in]: docView		The document view whose page view to go to.
    // Param[in]: iPage			The specified page index. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
    // Return: void
    // Remarks: Goes to specified page, retaining the current display mode. It invalidates the display, but not
    // always perform an immediately redraw. 
    // Notes:
    // See: FRDocViewGotoPageViewByPoint
    // See: FRDocViewGotoPageViewByRect
    //************************************
    static void			GotoPageView(FR_DocView docView, FS_INT32 iPage);

    //************************************
    // Function:  GotoPageViewByPoint
    // Param[in]: docView		The document view whose page view to go to.
    // Param[in]: iPage			The specified page index. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
    // Param[in]: left			The x-coordinate to scroll to. Specified in PDF space coordinates.
    // Param[in]: top			The y-coordinate to scroll to. Specified in PDF space coordinates.
    // Return: void
    // Remarks: Goes to specified page and scroll page view to the location specified by <param>left</param> and <param>top</param>, retaining the 
    // current display mode. It invalidates the display, but not always perform an immediately redraw. 
    // Notes:	
    // See: FRDocViewGotoPageView
    // See: FRDocViewGotoPageViewByRect
    //************************************
    static void			GotoPageViewByPoint(FR_DocView docView, FS_INT32 iPage, FS_FLOAT left, FS_FLOAT top);

    //************************************
    // Function: GotoPageViewByRect
    // Param[in]: docView		The document view whose page view to go to.
    // Param[in]: iPage			The index of the visible page. The index range is 0 to (<a>FRDocViewCountVisiblePageViews</a>()-1).
    // Param[in]: rect			The rectangle that is completely visible, that is, the visible area of the document view will change the zoom of the view according to the size of the area.
    // Return: void 
    // Remarks: Goes to specified page view and scroll to center of the rectangle. It always change the zoom level if necessary.     
    // Notes:	It need use FRDocViewGotoPageView to go to specified page.
    // See: FRDocViewGotoPageView
    // See: FRDocViewGotoPageViewByPoint
    //************************************
    static void			GotoPageViewByRect(FR_DocView docView, FS_INT32 iPage, FS_FloatRect rect);

    //************************************
    // Function:  GetCurrentPageView
    // Param[in]: docView			The document.
    // Return:	Current <a>FR_PageView</a> that is visible in screen.
    // Remarks:	Gets current page view that is visible in screen. 
    // Notes: If more than one page may be visible. use FRDocViewCountVisiblePageViews() and FRDocViewGetVisiblePageView() instead.
    // See: FRDocViewGetPageView
    // See: FRDocViewGetPageViewAtPoint
    // See: FRDocViewGetGetVisiblePageView
    //************************************
    static FR_PageView		GetCurrentPageView(FR_DocView docView);

    //************************************
    // Function:  GetRotation
    // Param[in]: docView			The document view to obtain rotation factor.
	// Return: A integer described in group <a>FR_RotationFlags</a>(for example: FR_ROTATE_POS_TOP).	  
    // Remarks: Gets the rotation factor.   
    // Notes:
    // See: 
    //************************************
    static FS_INT32			GetRotation(FR_DocView docView);

    //************************************
    // Function:  SetRotation
    // Param[in]: docView			The document view to obtain rotation factor.
	// Param[in]: nFlag				A integer described in group <a>FR_RotationFlags</a>(for example: FR_ROTATE_POS_TOP).
    // Return: void  
    // Remarks: Sets the rotation factor.   
    // Notes:
    // See: 
    //************************************
    static void			SetRotation(FR_DocView docView, FS_INT32 nFlag);

    //************************************
    // Function:  GetLayoutMode
    // Param[in]: docView			The document view whose layout mode is obtained.		
    // Return: 	The current page layout mode, a <a>FRDOC_LAYOUTMODE</a> enumeration value.
    // Remarks:	Gets the page layout mode.  	
    // Notes:
    //************************************
    static FRDOCVIEW_LAYOUTMODE	GetLayoutMode(FR_DocView docView);

    //************************************
    // Function:  SetLayoutMode
    // Param[in]: docView			The document view whose layout mode is set.	
    // Param[in]: mode				The new layout mode for document view.
    // Return: 	void
    // Remarks:	Sets the page layout mode for a document view.  	
    // Notes:
    //************************************
    static void SetLayoutMode(FR_DocView docView, FRDOCVIEW_LAYOUTMODE mode);

    //************************************
    // Function:  GetZoom
    // Param[in]: docView			The document view.
    // Return:	The current zoom for page view.
    // Remarks:	Gets the current zoom for page view. The zoom factor is point-to-point, not point-to-pixel.	
    // Notes: Current zoom, as a fixed number measured in units in which 1.0 is 100% zoom.
    // See: FRDocViewGetZoomType
    // See: FRDocViewZoomTo
    //************************************
    static FS_FLOAT			GetZoom(FR_DocView docView);

    //************************************
    // Function:  GetZoomType
    // Param[in]: docView			The document view.
    // Return: Current zoom type.	
    // Remarks: Gets the current zoom type.	  	
    // Notes:
    // See: FRDocViewGetZoom
    // See: FRDocViewZoomTo
    //************************************
    static FRDOCVIEW_ZOOMTYPE			GetZoomType(FR_DocView docView);

    //************************************
    // Function: ZoomTo 
    // Param[in]: docView		The document view.
    // Param[in]: mode			The zoom mode to set.
    // Param[in]: scale			The zoom factor, specified as a magnification factor(for example,
    // 1.0 displays the document at actual size). This is ignore unless <param>mode</param> is
    // <a>FR_ZOOM_MODE_ACTUAL_SCALE</a> or <a>FR_ZOOM_MODE_AUTOMATIC</a>.
    // Return:	void  
    // Remarks: Sets the zoom factor and zoom type to specified page view.
    // Notes:	
    // See: FRDocViewGetZoom
    // See: FRDocViewGetZoomType
    //************************************
    static void					ZoomTo(FR_DocView docView, FRDOCVIEW_ZOOMTYPE mode, FS_FLOAT scale);

    //************************************
    // Function:  GoBack
    // Param[in]: docView			The document view.
    // Return:	void
    // Remarks: Goes to the previous view on the view stack, if a previous view exist.	  	
    // Notes:
    // See: FRDocViewGoForward
    //************************************
    static void				GoBack(FR_DocView docView);

    //************************************
    // Function:  GoForward
    // Param[in]: docView			The document view.
    // Return:	void
    // Remarks:	Goes to the next view on the view stack, if a next view exist.  	
    // Notes:
    // See: FRDocViewGoBack
    //************************************
    static void				GoForward(FR_DocView docView);

    //************************************
    // Function:  ShowAnnots
    // Param[in]: docView	The document view.
    // Param[in]: annots	The array of annotations to be shown.
    // Param[in]: bShow		Whether to show or not.
    // Return:	void
    // Remarks:	 If <param>bShow</param> is set <a>TRUE</a>, the annotations will be shown. Otherwise not. This interface is not available in version 1.0.
    // Notes:
    //************************************
    static void				ShowAnnots(FR_DocView docView, FS_PtrArray* annots, FS_BOOL bShow);

    //************************************
    // Function:  ProcAction
    // Param[in]: docView       The document view.
    // Param[in]: action		A <a>FPD_Action</a> object to be performed.
    // Return:	void
    // Remarks:	Performs a specified action.  	
    // Notes:
    //************************************
    static void				ProcAction(FR_DocView docView, FPD_Action action);

    //************************************
    // Function:  ScrollTo
    // Param[in]: docView			The document view to scroll.
    // Param[in]: x					The x-axis distance to scroll, specified in the device space coordinates.
    // Param[in]: y					The y-axis distance to scroll, specified in the device space coordinates.
    // Return:	void
    // Remarks:	Scrolls the specified document view by <param>x</param> and <param>y</param> the specified distance.
    // Notes:
    //************************************
    static void				ScrollTo(FR_DocView docView, FS_INT32 x, FS_INT32 y);

    //************************************
    // Function:  GetMaxScrollingSize
    // Param[in]: docView			The input document view.
    // Param[out]: outWidth			It receives the horizontal maximum scrolling size.
    // Param[out]: outHeight		It receives the vertical maximum scrolling size.
    // Return:	void
    // Remarks:	Gets the maximum scrolling size of the document view.  	
    // Notes:
    //************************************
    static void				GetMaxScrollingSize(FR_DocView docView, FS_INT32* outWidth, FS_INT32* outHeight);

    //************************************
    // Function:  DrawNow
    // Param[in]: docView			The document view to redraw.
    // Return: void  
    // Remarks: Forces specified document view to redraw.   
    // Notes:	
    // See: FRDocViewInvalidateRect
    //************************************
    static void			DrawNow(FR_DocView docView);

    //************************************
    // Function:  InvalidateRect
    // Param[in]: docView		The document view in which a region is invalidated.
    // Param[in]: rect			The rectangle to invalidate, specified in device space coordinates.
    // Return:	void  
    // Remarks: Redraws the specified area of document view immediately.  
    // Notes:	
    // See: FRDocViewDrawNow
    //************************************
    static void			InvalidateRect(FR_DocView docView, FS_Rect rect);

    //************************************
    // Function: DrawRect 
    // Param[in]: docView		The input doc view.
    // Param[in]: rect			The input rectangle.
    // Param[in]: fill_argb		The color to fill.
    // Param[in]: bCompose		Whether to compose or not.
    // Return: void  
    // Remarks:   Draws rectangle in the doc view.
    // Notes: The function can only be used for Windows.
    //************************************
    static void			DrawRect(FR_DocView docView, FS_Rect rect, FS_ARGB fill_argb, FS_BOOL bCompose);

    //************************************
    // Function:  DoPopUpMenu
    // Param[in]: docView		The document view in which the menu appears.
    // Param[in]: menu			The displayed menu.
    // Param[in]: xHit			The x-coordinate of the upper left corner of the menu.	
    // Param[in]: yHit			The y-coordinate of the upper left corner of the menu.
    // Return: The menu item clicked by user.	  
    // Remarks: Displays the given menu as a pop-up menu anchored at <param>xHi</param>t and <param>yHit</param>, which are in device
    // space coordinates relative to <param>docView</param>.
    // Notes: The function can only be used for Windows.
    // See: FRMenuTrackPopup
    //************************************
    static FR_MenuItem	DoPopUpMenu(FR_DocView docView, FR_Menu menu, FS_INT32 xHit, FS_INT32 yHit);

    //************************************
    // Function:  GetMachinePort
    // Param[in]: docView			The document view whose <Italic>FS_HWND</Italic> handler and device context are obtained.
    // Return: The <a>FR_WinPort</a> object.
    // Remarks: Gets the platform-specific object needed to draw into page view using a platform's native 
    // graphic calls. It is a <a>FR_WinPort</a> object which contain the <Italic>FS_HWND</Italic> handler and
    // the device context. When done, release it using <a>FRDocViewReleaseMachinePort</a>().
    // Notes: The function can only be used for Windows.
    // See: FRDocViewReleaseMachinePort
    //************************************
    static FR_WinPort   GetMachinePort(FR_DocView docView);

    //************************************
    // Function:  ReleaseMachinePort
    // Param[in]: docView	The document view whose <Italic>FS_HWND</Italic> handler and device context are released.
    // Param[in]: port		The platform-dependent object to release.
    // Return:	<a>TRUE</a> means release machine port successful, otherwise not.
    // Remarks: Releases a <a>FR_WinPort</a> that acquired form page view using <a>FRDocViewGetMachinePort</a>().
    // Notes: The function can only be used for Windows.
    // See: FRDocViewGetMachinePort
    //************************************
    static FS_BOOL			ReleaseMachinePort(FR_DocView docView, FR_WinPort port);

    //************************************
    // Function:  GetOCContext
    // Param[in]: docView		The document view whose ocg context are obtained.
    // Return:	The <Italic>OCG</Italic> context of Reader doc view.  
    // Remarks: Gets the <Italic>OCG</Italic> context of Reader doc view. 
    // Notes:
    //************************************
    static FPD_OCContext		GetOCContext(FR_DocView docView);

    //************************************
    // Function:  GetCurrentSnapshot
    // Param[in]: docView		The document view whose snapshot image are obtained.
    // Return: A <a>FS_DIBitmap</a> object indicates current snapshot image. This <a>FS_DIBitmap</a> object must be destroied by calling
    // <a>FSDIBitmapDestroy</a>().
    // Remarks: Gets current snapshot image that generated by using snapshot tool.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
    //************************************
    static FS_DIBitmap			GetCurrentSnapshot(FR_DocView docView);

    //************************************
    // Function:  GetThumbnailView
    // Param[in]: docView		The input document view.
    // Return: A <a>FR_ThumbnailView</a> object related to the input document view.
    // Remarks: Gets the thumbnail view related to the input document view.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
    //************************************
    static FR_ThumbnailView     GetThumbnailView(FR_DocView docView);

    //************************************
    // Function:  GotoPageViewByState
    // Param[in]: docView			The document view whose page view to go to.
    // Param[in]: iPage				The specified page index. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
    // Param[in]: iFitType			The input fit type.
    // Param[in]: destArray			The input destination array.
    // Param[in]: destArrayCount	The count of the destination array.
    // Return: void
    // Remarks: Goes to the page view by state.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See: FRDocViewGotoPageViewByPoint
    // See: FRDocViewGotoPageViewByRect
    // Deprecated: Internal use.
    //************************************
    static void     GotoPageViewByState(FR_DocView docView, FS_INT32 iPage, FS_INT32 iFitType, FS_FLOAT* destArray, FS_INT32 destArrayCount);

    //************************************
    // Function:  MovePage
    // Param[in]: docView	The document view.
    // Param[in]: ptDest	The dest point.
    // Param[in]: ptSrc		The source point.
    // Return: void
    // Remarks: Moves the page, the target point to which the original point of the page is moved.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
    //************************************
    static void     MovePage(FR_DocView docView, FS_DevicePoint ptDest, FS_DevicePoint ptSrc);

    //************************************
    // Function:  IsValidPageView
    // Param[in]: docView	The document view.
    // Param[in]: pPageView	The page view.
    // Return: <a>TRUE</a> if the page view is valid, otherwise not.
    // Remarks: Checks whether the page view is valid or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
    //************************************
    static FS_BOOL  IsValidPageView(FR_DocView docView, FR_PageView pPageView);

    //************************************
    // Function:  GetTagDocViewText
    // Param[in]: docView	The document view.
    // Param[out]:outText   It receives the text got.
    // Param[in]: nCount	The index of the page view, -1 for the current page view.
    // Return:    void
    // Remarks:   Get the text content of all tags in the page under the input index, the text order is in accordance with the tag order.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2	
    //************************************
    static void     GetTagDocViewText(FR_DocView docView, FS_WideString* outText, FS_INT32 nCount);

    //************************************
    // Function:  GetLRDocViewText
    // Param[in]: docView	The document view.
    // Param[out]:outText   It receives the text got.
    // Param[in]: nCount	The index of the page view, -1 for the current page view.
    // Return:    void
    // Remarks:   Get all the text content in the page under the input index, the text order is in accordance with the creation order of the text object.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
    //************************************
    static void     GetLRDocViewText(FR_DocView docView, FS_WideString* outText, FS_INT32 nCount);

	//************************************
	// Function:  GetWnd
    // Param[in]: docView	The document view.
	// Return:    FS_HWND
	// Remarks:   Gets docview hwnd.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
	//************************************
    static FS_HWND  GetWnd(FR_DocView docView);

	//************************************
	// Function:  ScrollToCenterPoint
    // Param[in]: docView	The document view.
    // Param[in]: index	    The page index.
    // Param[in]: pdfPoint	The point to scroll.
	// Return:    void
    // Remarks:  Scroll the center point to the specified point of the input page index,
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
	//************************************
	static void		ScrollToCenterPoint(FR_DocView docView, FS_INT32 index, FS_FloatPoint pdfPoint);

	//************************************
	// Function:  SetRenderDataChange
    // Param[in]: docView	The document view.
	// Return:    void
    // Remarks:  Set render data change in the document view.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
	//************************************
	static void		SetRenderDataChange(FR_DocView docView);

	//************************************
	// Function:  GotoPageViewByAnnot
	// Param[in]: docView	The document view.	
	// Param[in]: pAnnot	The annot object, it will go to the pageview contains the annot.		
    // Return:   <a>TRUE</a> If go to pageview success. otherwise not.
	// Remarks:  Go to the page where annot is located.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0
	//************************************
	static FS_BOOLEAN	GotoPageViewByAnnot(FR_DocView docView, FR_Annot pAnnot);

	//************************************
	// Function:  GotoPageByDest
	// Param[in]: docView	The document view.	
	// Param[in]: dest	    The dest postion of the document.		
	// Return:    void
    // Remarks:  Go the dest position of the document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0
	//************************************
	static void			 GotoPageByDest(FR_DocView docView, FPD_Dest dest);

	//************************************
	// Function:  GetHwnd
	// Param[in]: docView	The document view.
	// Return:    FS_HWND
	// Remarks:   Gets docview hwnd.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
	//************************************
	static FS_HWND  GetHwnd(FR_DocView docView);

	//************************************
	// Function:  GetRBDPageView
	// Param[in]: docView	The document view.
	// Return:    FR_PageView
	// Remarks:   Gets the page view which right click on.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
	// Deprecated: Internal use.
	//************************************
	static FR_PageView	GetRBDPageView(FR_DocView docView);

	//************************************
	// Function:  UpdateStatusBarPagesInfo	
	// Return:	void.
	// Remarks: Update page info in the status bar.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void     UpdateStatusBarPagesInfo(FR_DocView docView);

	//************************************
	// Function: GotoPageViewByRect2
	// Param[in]: docView		The document view whose page view to go to.
	// Param[in]: iPage			The index of the visible page. The index range is 0 to (<a>FRDocViewCountVisiblePageViews</a>()-1).
	// Param[in]: rect			The rectangle that is completely visible, that is, the visible area of the document view will change the zoom of the view according to the size of the area.
	// Param[in]: isTopUp       Whether rect needs to be at the top of the view, default is false.
	// Param[in]: dbMaxScale    The input max scale, default is 64, and need set bellow to 64.
	// Return: void 
	// Remarks: Goes to specified page view and scroll to center of the rectangle. It always change the zoom level if necessary.     
	// Notes: It need ensure the FR_PageView exists, if not it need call FRDocViewGotoPageView to go to specified page first.
	// See: FRDocViewGotoPageView
	// See: FRDocViewGotoPageViewByPoint
	//************************************
	static FS_BOOLEAN GotoPageViewByRect2(FR_DocView docView, FS_INT32 index, FS_FloatRect rect, FS_BOOLEAN isTopUp, FS_FLOAT dbMaxScale);

	//************************************
	// Function:  UpdateAllViews
	// Param[in]: docView	The document view.
	// Param[in]: doc	    The input doc.
	// Return:    void
	// Remarks:   Update all page views.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// Deprecated: Internal use.
	//************************************
	static void	UpdateAllViews(FR_DocView docView, FR_Document doc);

	//************************************
	// Function:  UpdateAllNotes
	// Param[in]: doc	        The input doc.
	// Param[in]: csType	    The input annot type.
	// Return:    void
	// Remarks:   Update all notes.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// Deprecated: Internal use.
	//************************************
	static void	UpdateAllNotes(FR_Document doc, FS_LPCSTR csType);

	//************************************
	// Function:  IsAutoScrolling
	// Param[in]: docView	        The input FR_DocView.	
	// Return:    FS_BOOL
	// Remarks:   Check the current doc view is auto scrolling.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRDocGetDocView
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsAutoScrolling(FR_DocView docView);

	//************************************
	// Function:  ScrollTo2
	// Param[in]: docView			The document view to scroll.
	// Param[in]: x					The x-axis distance to scroll, specified in the device space coordinates.
	// Param[in]: y					The y-axis distance to scroll, specified in the device space coordinates.
	// Return:	FS_DevicePoint      Get the position after scroll.
	// Remarks:	Scrolls the specified document view by <param>x</param> and <param>y</param> the specified distance.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// Deprecated: Internal use.
	//************************************
	static FS_DevicePoint	ScrollTo2(FR_DocView docView, FS_INT32 x, FS_INT32 y);
};

class CFR_PageView_V1
{
public:

    //************************************
    // Function:  GetDocument
    // Param[in]: pv			The page view whose <a>FR_Document</a> is obtained.
    // Return: The <a>FR_Document</a> for <param>pv</param>.	
    // Remarks:	Gets the <a>FR_Document</a> for the document currently displayed in specified pageview.   	
    // Notes:
    // See: FRDocViewGetDocument
    // See: FRPageViewGetDocView
    //************************************
    static FR_Document		GetDocument(FR_PageView pv);

    //************************************
    // Function:  GetDocView
    // Param[in]: pv			The page view whose <a>FR_DocView</a> is obtained.
    // Return: The <a>FR_DocView</a> for <param>pv</param>.
    // Remarks:	Gets the <a>FR_DocView</a> for specified pageview.   	
    // Notes:
    // See: FRDocGetDocView
    // See: FRDocGetCurrentDocView
    // See: FRDocViewGetPageView
    //************************************
    static FR_DocView		GetDocView(FR_PageView pv);

    //************************************
    // Function:  GetPDPage
    // Param[in]: pv			The page view whose <a>FPD_Page</a> is obtained.
    // Return: <a>FPD_Page</a> displayed in <param>pv</param>, return<a>NULL</a> if no valid <a>FPD_Page</a>
    // associated with <param>pv</param>.
    // Remarks:	Gets a <a>FPD_Page</a> currently displayed in the specified page view. This do not new a
    // <a>FPD_Page</a> object. Do not use this result across methods that might change the current page.
    // To obtain a value that can be used across such calls, use <a>FPD_PageNew</a> instead.
    // Notes:
    // See: FRDocGetPDDoc
    //************************************
    static FPD_Page			GetPDPage(FR_PageView pv);

    //************************************
    // Function:  GetPageIndex
    // Param[in]: pv			The page view whose current page number is obtained.
    // Return: The current page number, The first page number of a document is page 0.
    // Remarks:	Gets the current page number.  	
    // Notes:
    //************************************
    static FS_INT32			GetPageIndex(FR_PageView pv);

    //************************************
    // Function:  CountAnnot
    // Param[in]: pv			The page view object.
    // Return: The number of annotations associated with <param>pv</param>.	
    // Remarks: Gets the number of annotations associated with specified page view. This interface is not available in version 1.0.
    // Notes:
    //************************************
    static FS_INT32			CountAnnot(FR_PageView pv);

    //************************************
    // Function:  GetCurrentMatrix
    // Param[in]: pv			The page view object.
    // Return: Current matrix of <param>pv</param>.
    // Remarks: Gets the current matrix of the page view.
    // Notes:	
    //************************************
    static FS_AffineMatrix		GetCurrentMatrix(FR_PageView pv);

    //************************************
    // Function:  DevicePointToPage
    // Param[in]: pv				The page view for which the point's coordinates are transformed from device space to user space.
    // Param[in]: window_x			The x-coordinate of the point to transform, specified in device space coordinates.		
    // Param[in]: window_y			The y-coordinate of the point to transform, specified in device space coordinates.
    // Param[out]: outPt			(Filled by this method) A pointer to a point whose user space coordinates corresponding
    // <param>window_x</param> and <param>window_y</param>.
    // Return:	 void 
    // Remarks: Transforms a point's coordinate from device space to user space.
    // Notes:	
    // See: FRPageViewDeviceRectToPage
    // See: FRPageViewPointToDevice
    // See: FRPageViewRectToDevice
    //************************************
    static void					DevicePointToPage(FR_PageView pv, FS_INT32 window_x, FS_INT32 window_y, FS_FloatPoint* outPt);

    //************************************
    // Function:  DeviceRectToPage
    // Param[in]: pv				The page view for which the rectangle is transformed from device space to user space.
    // Param[in]: rect				A pointer to device space rectangle whose coordinates are transformed to user space.
    // Param[out]: outRect			(Filled by this method) A pointer to a user space rectangle corresponding <param>rect</param>.
    // Return:	 void 
    // Remarks: Transforms a rectangle from device space to user space.
    // Notes:
    // See: DevicePointToPage
    // See: FRPageViewPointToDevice
    // See: FRPageViewRectToDevice
    //************************************
    static void					DeviceRectToPage(FR_PageView pv, const FS_Rect* rect, FS_FloatRect* outRect);

    //************************************
    // Function:  PointToDevice
    // Param[in]: pv				The page view for which the point's coordinates are transformed from user space to device space.
    // Param[in]: pt				A pointer to a <a>FS_FloatPoint</a> whose coordinates, specified in device space coordinates, are transformed.
    // Param[out]: out_window_x		(Filled by the method) The x-coordinate of the device space point corresponding to <param>pt</param>.
    // Param[out]: out_window_y		(Filled by the method) The y-coordinate of the device space point corresponding to <param>pt</param>. 
    // Return: void	   
    // Remarks:  Transforms a point from user space to device space.
    // Notes:	
    // See: DevicePointToPage
    // See: DeviceRectToPage
    // See: FRPageViewRectToDevice
    //************************************
    static void					PointToDevice(FR_PageView pv, const FS_FloatPoint* pt, FS_INT32* out_window_x, FS_INT32* out_window_y);

    //************************************
    // Function:  RectToDevice
    // Param[in]: pv				The page view for which the rectangle is transformed from user space to device space.
    // Param[in]: rect				A pointer to user space rectangle whose coordinates are transformed to device space.
    // Param[out]: outRect			(Filled by this method) A pointer to a device space rectangle corresponding <param>rect</param>.
    // Return:	 void 
    // Remarks: Transforms a rectangle from user space to device space.
    // Notes:	
    // See: DevicePointToPage
    // See: DeviceRectToPage
    // See: FRPageViewPointToDevice
    //************************************
    static void					RectToDevice(FR_PageView pv, const FS_FloatRect* rect, FS_Rect* outRect);

    //************************************
    // Function:  IsVisible
    // Param[in]: pv			The page view to adjust whether it is visible.
    // Return: <a>TRUE</a> if the page view object is visible. otherwise not.
    // Remarks: Gets a flag that indicate whether a page view is visible.
    // Notes:	
    //************************************
    static FS_BOOL				IsVisible(FR_PageView pv);

    //************************************
    // Function:  GetPageRect
    // Param[in]: pv			The page view whose bounding-box to obtained.
    // Return: The current bounding-box for <param>pv</param>.
    // Remarks: Gets the current bounding-box of specified page view.
    // Notes: The page bounding-box specified in device space coordinates.
    // See: FRPageViewGetPageVisibleRect
    //************************************
    static FS_Rect				GetPageRect(FR_PageView pv);

    //************************************
    // Function:  GetPageVisibleRect
    // Param[in]: pv			The page view whose visible rectangle to obtained.
    // Return: A rectangle specified in user space, instead of the current visible region of <param>pv</param>.	  
    // Remarks: Gets the current visible region of specified page view.  
    // Notes: If the specified page view is invisible, the returned rectangle is empty.	
    // See: FRPageViewGetPageRect
    //************************************
    static FS_FloatRect			GetPageVisibleRect(FR_PageView pv);

    //************************************
    // Function:  DidContentChanged
    // Param[in]: pv			The page view whose <a>FPD_Page</a> has been modified.
    // Param[in]: bReLoadPage	A flag to force reader to reload the page data. If <a>TRUE</a>, Foxit Reader will reload the page data and reparse the page.
    // The flag must be <a>TRUE</a> and call <a>FPDPageGenerateContent</a>() befor calling this method if the <a>FPD_Page</a> whose content is modified is not using <a>FRPageViewGetPDPage</a>() to obtain.
    // Return: void	  
    // Remarks: The content of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins. 
    // Notes: 	
    // See: 
    //************************************
    static void		DidContentChanged(FR_PageView pv, FS_BOOL bReLoadPage);

    //************************************
    // Function:  GetHWnd
    // Param[in]: pv			The page view which FS_HWND will be obtained.
    // Return: The FS_HWND handler of <param>pv</param>.
    // Remarks: Gets the FS_HWND handler in which a page view is displaying.
    // Notes: 	
    // See: 
    //************************************
    static FS_HWND		GetHWnd(FR_PageView pv);

    //************************************
    // Function:  DidTextObjectChanged
    // Param[in]: pv			The page view whose text objects of <a>FPD_Page</a> has been modified.
    // Return: void	  
    // Remarks: The text objects of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins. 
    // Notes: 	
    // See: 
    //************************************
    static void		DidTextObjectChanged(FR_PageView pv);

    //************************************
    // Function:  GetAnnotByIndex
    // Param[in]: pv	The input page view object.
    // Param[in]: index The specified index of the annotations.
    // Return: The specified annotation.
    // Remarks: Gets the annotation by index.
    // Notes: 	
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
    // See: 
    //************************************
    static FR_Annot GetAnnotByIndex(FR_PageView pv, FS_INT32 index);

    //************************************
    // Function:  GetPageState
    // Param[in]: pv					The input page view object.
    // Param[out]: outFitType			It receives the fit type, described in group <a>FR_PDFZOOMTYPE</a>(for example: FR_PDFZOOM_XYZ).
    // Param[out]: outDestArray			It receives the target array, which is used to record the relevant page data corresponding to the FitType.
    // Param[out]: outDestArrayCount	It receives the count of the destination array.
    // Return: void
    // Remarks: Gets the page state. Sets <param>outDestArray</param> NULL to get the count of the destination array first.
    // FR_PDFZOOM_XYZ       type will be the <a>left</a>,<a>top</a>,<a>zoom</a> information of the page to the sequential record <param>outDestArray</param>.
    // FR_PDFZOOM_FITRECT   type will be the <a>left</a>,<a>bottom</a>,<a>right</a>,<a>top</a> information of the page to the sequential record <param>outDestArray</param>.
    // FR_PDFZOOM_FITHORZ   type will be the <a>top</a> information of the page to the sequential record <param>outDestArray</param>.
    // FR_PDFZOOM_FITVERT   type will be the <a>left</a> information of the page to the sequential record <param>outDestArray</param>.
    // FR_PDFZOOM_FITBHORZ  type will be the <a>top</a> information of the page to the sequential record <param>outDestArray</param>.
    // No data record for other types.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See: 
    //************************************
    static void GetPageState(FR_PageView pv, FS_INT32* outFitType, FS_FLOAT* outDestArray, FS_INT32* outDestArrayCount);

    //************************************
    // Function:  DeleteAnnot
    // Param[in]: pv		The input page view object.
    // Param[in]: frAnnot	The input annotation to be deleted.	
    // Return: <a>TRUE</a> delete annot success. otherwise not.
    // Remarks: Deletes the specified annotation from the input page view object.
    // Notes: 	
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    // See: 
    //************************************
    static FS_BOOL DeleteAnnot(FR_PageView pv, FR_Annot frAnnot);

    //************************************
    // Function:  GetFocusAnnot
    // Param[in]: pv		The input page view object.
    // Return: The focus annotation.
    // Remarks: Gets the focus annotation in the the input page view object.
    // Notes: 	
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
    // See: 
	// Deprecated: Internal use.
    //************************************
    static FR_Annot GetFocusAnnot(FR_PageView pv);

    //************************************
    // Function:  GetPageScale
    // Param[in]: pv		The input page view object.
    // Return: The page scale.
    // Remarks: Gets the page scale.
    // Notes: 	
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
    // See: 
    //************************************
    static FS_FLOAT GetPageScale(FR_PageView pv);

    //************************************
    // Function:  GetAnnotAtPoint
    // Param[in]: pv			The input page view object.
    // Param[in]: point			The input point where to get the annotation.
    // Param[in]: pszSubType	Specifies the sub type of the annotation you want to get. You can set it NULL as default.
    // Return: The specified annotation.
    // Remarks: Gets the annotation at the specified point.
    // Notes: 	
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
    // See: 
    //************************************
    static FR_Annot GetAnnotAtPoint(FR_PageView pv, FS_DevicePoint point, FS_LPCSTR pszSubType);

    //************************************
    // Function:  UpdateAllViews
    // Param[in]: pv			The input page view object.
    // Param[in]: frAnnot		The input annotation you want to update.
    // Return: void.
    // Remarks: Updates all the page views where the annotation is shown.
    // Notes: 	
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
    // See: 
    //************************************
    static void UpdateAllViews(FR_PageView pv, FR_Annot frAnnot);

    //************************************
    // Function:  AddAnnot
    // Param[in]: pv			The input page view object.
    // Param[in]: annotDict		The input annotation dictionary you want to add.
    // Param[in]: nIndex		The index where you want to add the annotation. Sets it -1 as default.
    // Return: The UI layer annotation object.
    // Remarks: Adds the annotation to the input page view object.
    // Notes: 	
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    // See: 
    //************************************
    static FR_Annot AddAnnot(FR_PageView pv, FPD_Object annotDict, FS_INT32 nIndex);

    //************************************
    // Function:  GetRenderOptions
    // Param[in]: pv			The input page view object.
    // Return: The rendering options.
    // Remarks: Gets the rendering options from the input page view object.
    // Notes: 	
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.2.1
    // See: 
    //************************************
    static FPD_RenderOptions GetRenderOptions(FR_PageView pv);

    //************************************
    // Function:  DidContentChanged2
    // Param[in]: pv                    The page view whose <a>FPD_Page</a> has been modified.
    // Param[in]: bReLoadPage           A flag to force reader to reload the page data. If <a>TRUE</a>,
    // Foxit Reader will reload the page data and reparse the page. The flag must be <a>TRUE</a> and call <a>FPDPageGenerateContent</a>()
    // befor calling this method if the <a>FPD_Page</a> whose content is modified is not using <a>FRPageViewGetPDPage</a>() to obtain.
    // Param[in]: bResizePageNotify     Checks whether to broadcast the notification of page resizing.
    // Param[in]: pChangeData           It indicates what data is changed. This parameter is temporarily not used.
    // Return: void	  
    // Remarks: The content of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins. 
    // Notes: 	
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
    // See: 
    //************************************
    static void DidContentChanged2(FR_PageView pv, FS_BOOL bReLoadPage, FS_BOOL bResizePageNotify, void* pChangeData);

    //************************************
    // Function:  DidContentChanged3
    // Param[in]: pv                    The page view whose <a>FPD_Page</a> has been modified.
    // Param[in]: bReLoadPage           A flag to force reader to reload the page data. If <a>TRUE</a>, Foxit Reader will reload the page data and reparse the page.
    // The flag must be <a>TRUE</a> and call <a>FPDPageGenerateContent</a>() befor calling this method if the <a>FPD_Page</a> whose content is modified is not using <a>FRPageViewGetPDPage</a>() to obtain.
    // Param[in]: bResizePageNotify     Checks whether to broadcast the notification of page resizing.
    // Param[in]: objArray              It indicates what data is changed. The value type in the array is <a>FR_STRUCTCONTENT_OBJECT</a>.
    // Param[in]: changeType            The content change type.
    // Return: void	  
    // Remarks: The content of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins. 
    // Notes: 	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
    // See: 
    //************************************
    static void DidContentChanged3(FR_PageView pv, FS_BOOL bReLoadPage, FS_BOOL bResizePageNotify, FS_PtrArray objArray, FR_ContentChangeType changeType);

    //************************************
    // Function:  SetContentModification
    // Param[in]: pv				The page view whose <a>FPD_Page</a> content is modified.
    // Param[in]: modifiedContent	An array to store the modified <a>FPD_Page</a> or <a>FPD_Form</a>.
    // Return:	void.
    // Remarks: Sets the modified page content.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 4.1.2
    //************************************
    static void SetContentModification(FR_PageView pv, FS_PtrArray modifiedContent);

    //************************************
    // Function:  GenerateContent
    // Param[in]: pv	The page view whose <a>FPD_Page</a> needs to generate content.
    // Return:	void.
    // Remarks: Generates the page content.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1	
    //************************************
    static void	GenerateContent(FR_PageView pv);

    //************************************
    // Function:  UpdateAllViewsRect
    // Param[in]: pv            The page view object.
    // Param[in]: rectarray     The point array of update area in user space.
    // Return:	void.
    // Remarks:
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1	
    //************************************
    static void UpdateAllViewsRect(FR_PageView pv, FS_FloatRectArray rectarray);

    //************************************
    // Function:  CountViews
    // Param[in]: pv	The page view object.
    // Return:	The total number of views in the current view page.
    // Remarks: Gets the total number of views in the current view page.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1	
    //************************************
    static FS_INT32 CountViews(FR_PageView pv);

    //************************************
    // Function:  IsValidAnnot
    // Param[in]: pv	The page view object.
    // Param[in]: annot	The input FR_Annot object.
    // Return:	<a>TRUE</a> if the annot of the page view is valid. otherwise not.
    // Remarks: Check that the input annotation object of the page view object is valid.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1	
    //************************************
    static FS_BOOL	IsValidAnnot(FR_PageView pv, FS_LPVOID annot);

    //************************************
    // Function:  Annot_OnDraw
    // Param[in]: pPageView     The page view object.
    // Param[in]: hDC           The device context of <param>pageView</param>.
    // Param[in]: pAnnot        The specified annotation to be drawn.
    // Param[in]: pDevice       The memory device used to render the annotation.
    // Param[in]: pUser2Device	The transformation matrix from user space to device space.
    // Param[in]: rcWindow      The rectangle of <param>pageView</param>.
    // Param[in]: dwFlags       The reserve flag, will be ignore.
    // Return:	void.
    // Remarks: Draw annotation's appearance, using default appearance rules.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 4.1.2
    // Deprecated: Internal use.
    //************************************
    static void Annot_OnDraw(FR_PageView pPageView, FS_HDC hDC, FR_Annot pAnnot, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device, const FS_FloatRect& rcWindow, FS_DWORD dwFlags);

    //************************************
    // Function:  Annot_OnHitTest
    // Param[in]: pPageView	The page view whose needs to hit test.
    // Param[in]: pAnnot	The annotation whose needs to hit test.
    // Param[in]: point	    The hit point by device space.
    // Return:	<a>TRUE</a> The hit point is included in the annotation of the selected page view. otherwise not.
    // Remarks: Determine whether the hit point is included in the annotation of the selected page view
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1	
    //************************************
    static FS_BOOL Annot_OnHitTest(FR_PageView pPageView, FR_Annot pAnnot, const FS_FloatPoint point);

	//************************************
	// Function:  GetReaderPage
    // Param[in]: pPageView     The page view object.
    // Return:	The document page object.
    // Remarks: Get the document page object which containt the page view object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1	
	// Deprecated: Internal use.
	//************************************
	static FR_Page	GetReaderPage(FR_PageView pPageView);

	//************************************
	// Function:  PostFormFilerMessageText
    // Param[in]: pPageView     The page view object.
    // Param[in]: data          The array of message text to post.
    // Param[in]: pRDDoc        The document object to post.
    // Return:	void.
    // Remarks: Post form file message text to the input document.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1	
	//************************************
	static void		PostFormFilerMessageText(FR_PageView pPageView, FS_WideStringArray data, FR_Document pRDDoc);

	//************************************
	// Function:  SetIsFindHighlight
	// Param[in]: pPageView          The page view object.
	// Param[in]: bFindHighlight     Set if find highlight.
	// Return:	void.
	// Remarks: Set if find highlight.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// Deprecated: Internal use.
	//************************************
	static void		SetIsFindHighlight(FR_PageView pPageView, FS_BOOL bFindHighlight);

	//************************************
	// Function:  IsFindHighlight
	// Param[in]: pPageView          The page view object.
	// Return:	FS_BOOL
	// Remarks: Get if find highlight.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	IsFindHighlight(FR_PageView pPageView);
	
	//************************************
	// Function:  SetAdvancedFindHighlight
	// Param[in]: pPageView          The page view object.
	// Param[in]: bFindHighlight     Set if advanced find highlight.
	// Return:	void.
	// Remarks: Set if advanced find highlight.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// Deprecated: Internal use.
	//************************************
	static void		SetAdvancedFindHighlight(FR_PageView pPageView, FS_BOOL bAdvancedFindHighlight);

	//************************************
	// Function:  IsAdvancedFindHighlight
	// Param[in]: pPageView          The page view object.
	// Return:	FS_BOOL
	// Remarks: Get if advanced find highlight.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	IsAdvancedFindHighlight(FR_PageView pPageView);

	//************************************
	// Function:  GetPageStateByFitType
	// Param[in]: pPageView          The page view object.
	// Param[out]: state             Get page state, it need to use FSFloatArrayNew to init dest property.
	// Return:	void
	// Remarks: Get page state by fit type of FR_PAGESTATE.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// Deprecated: Internal use.
	//************************************
	static void	GetPageStateByFitType(FR_PageView pPageView, FR_PAGESTATE* state);

	//************************************
	// Function:  GetPageRectIncludeMargin
	// Param[in]: pPageView          The page view object.	
	// Return:	FS_Rect
	// Remarks: Get page rect include margin.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// Deprecated: Internal use.
	//************************************
	static FS_Rect	GetPageRectIncludeMargin(FR_PageView pPageView);
};

class CFR_TextSelectTool_V1
{
public:
    //************************************
    // Function:  Create
    // Param[in]: doc	The input doc where the operation of text selecting occurs.
    // Return: The text select tool.
    // Remarks: Creates the text select tool which is used to process the operation of text selecting in the doc view.
    // Notes:
    // See:
    //************************************
    static FR_TextSelectTool Create(FR_Document doc);

    //************************************
    // Function:  DestroyTextSelectTool
    // Param[in]: textSelectTool The input text select tool.
    // Return: void.
    // Remarks: Destroys the text select tool created from <a>FRTextSelectToolCreate</a>.
    // Notes:Current function has been deprecated , so not recommend to use current function any more.
    // See:
    // Deprecated: Internal use.
    //************************************
    static void DestroyTextSelectTool(FR_TextSelectTool textSelectTool);

    //************************************
    // Function:  GetSelectedText
    // Param[in]: textSelectTool	The input text select tool.
    // Param[out]: outText			It receives the text selected.
    // Return:  <a>TRUE</a> Get the selected text form the input text select tool successful, otherwise not.
    // Remarks: Gets the selected text form the input text select tool.
    // Notes:
    // See:
    //************************************
    static FS_BOOL GetSelectedText(FR_TextSelectTool textSelectTool, FS_WideString* outText);

    //************************************
    // Function:  DrawSelection
    // Param[in]: textSelectTool	The input text select tool.
    // Param[in]: docView			The input doc view where do the operation of text selecting.
    // Param[in]: winPort			The platform-depend things.
    // Return: void.
    // Remarks:	 Draws the area where the text is selected in black color.
    // Notes: The function can only be used for Windows.
    // See: 
    //************************************
    static void DrawSelection(FR_TextSelectTool textSelectTool, FR_DocView docView, FR_WinPort winPort);

    //************************************
    // Function:  ClearSelection
    // Param[in]: textSelectTool	The input text select tool.
    // Return: void.
    // Remarks:   Clears the area where the text is selected.
    // Notes:
    // See:
    //************************************
    static void ClearSelection(FR_TextSelectTool textSelectTool);

    //************************************
    // Function:  DoLButtonUp
    // Param[in]: textSelectTool	The input text select tool.
    // Param[in]: pageView			The input page view where do the operation of text selecting.
    // Param[in]: point				The input point where do the mouse left button up operation.
    // Return: void.
    // Remarks:   Does the mouse left button up operation.
    // Notes:
    // See:
	// Deprecated: Internal use.
    //************************************
    static void	DoLButtonUp(FR_TextSelectTool textSelectTool, FR_PageView pageView, FS_DevicePoint point);

    //************************************
    // Function:  DoLButtonDown
    // Param[in]: textSelectTool	The input text select tool.
    // Param[in]: pageView			The input page view where do the operation of text selecting.
    // Param[in]: point				The input point where do the mouse operation.
    // Return: void.
    // Remarks:	  Does the mouse left button down operation.
    // Notes:
    // See:
	// Deprecated: Internal use.
    //************************************
    static void	DoLButtonDown(FR_TextSelectTool textSelectTool, FR_PageView pageView, FS_DevicePoint point);

    //************************************
    // Function:  DoLButtonDblClk
    // Param[in]: textSelectTool	The input text select tool.
    // Param[in]: pageView			The input page view where do the operation of text selecting.
    // Param[in]: point				The input point where do the mouse operation.
    // Return: void.
    // Remarks:   Does the mouse left button double-click operation.
    // Notes:
    // See:
	// Deprecated: Internal use.
    //************************************
    static void	DoLButtonDblClk(FR_TextSelectTool textSelectTool, FR_PageView pageView, FS_DevicePoint point);

    //************************************
    // Function:  DoRButtonUp
    // Param[in]: textSelectTool	The input text select tool.
    // Param[in]: pageView			The input page view where do the operation of text selecting.
    // Param[in]: point				The input point where do the mouse operation.
    // Return: void.
    // Remarks:   Does the mouse right button up operation.
    // Notes:
    // See:
	// Deprecated: Internal use.
    //************************************
    static void	DoRButtonUp(FR_TextSelectTool textSelectTool, FR_PageView pageView, FS_DevicePoint point);

    //************************************
    // Function:  DoMouseMove
    // Param[in]: textSelectTool	The input text select tool.
    // Param[in]: pageView			The input page view where do the operation of text selecting.
    // Param[in]: point				The input point where do the mouse operation.
    // Return: void.
    // Remarks:   Does the mouse move operation.
    // Notes:
    // See:
	// Deprecated: Internal use.
    //************************************
    static void	DoMouseMove(FR_TextSelectTool textSelectTool, FR_PageView pageView, FS_DevicePoint point);

    //************************************
    // Function:  DoMouseWheel
    // Param[in]: textSelectTool	The input text select tool.
    // Param[in]: pageView			The input page view where do the operation of text selecting.
    // Param[in]: point				The input point where do the mouse operation.
    // Return: <a>TRUE</a> if perform mouse wheel operation to specified position is success, otherwise not.
    // Remarks:   Perform mouse wheel operation to specified position.
    // Notes:
    // See:
	// Deprecated: Internal use.
    //************************************
    static FS_BOOL DoMouseWheel(FR_TextSelectTool textSelectTool, FR_PageView pageView, FS_DevicePoint point);

    //************************************
    // Function:  IsSelecting
    // Param[in]: textSelectTool	The input text select tool.
    // Return:	  <a>TRUE</a> if the mouse is selecting text, otherwise not.
    // Remarks:   Checks whether the mouse is selecting text.
    // Notes:
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL IsSelecting(FR_TextSelectTool textSelectTool);

    //************************************
    // Function:  EnumTextObjectRect
    // Param[in]: textSelectTool	The input text select tool.
    // Param[in]: pageIndex			The input page index.
    // Param[out]: outRectArray		It receives the rectangle array of text object.
    // Param[out]: nCount			It receives the count of the rectangle array.
    // Return:  <a>TRUE</a> If enumerates the text object rectangles is successful, otherwise not.
    // Remarks: Enumerates text object rectangles. The function of this interface needs to be called twice.
    // The first time we call this interface, we can get the count of rectangles by setting <param> outRectArray </param> to <a> NULL </a>.
    // Then call the interface again to assign data to the rectangular array.
    // Notes:
    // See:
    //************************************
    static FS_BOOL EnumTextObjectRect(FR_TextSelectTool textSelectTool, FS_INT32 pageIndex, FS_FloatRect** outRectArray, FS_INT32* nCount);

    //************************************
    // Function:  AddSelect
    // Param[in]: textSelectTool	The input text select tool.
    // Param[in]: pPageView         The page view object.
    // Param[in]: nStartIndex       The start index of the text to be selected.
    // Param[in]: nEndIndex         The end index of the text to be selected.
    // Param[in]: bShowLayer        Update document OCG and refresh layer panel view.
    // Param[in]: bTextIndex        Whether the input index is a text index.
    // Return:	  void.
    // Remarks: Get the selected rectangular area according to the input parameters.
    // Notes:The input index is divided into ordinary character index and text index. The text index is the index that matches the file obtained in FPDTextPageGetPageText.
    // See:FPDTextPageGetPageText
    //************************************
    static void AddSelect(FR_TextSelectTool textSelectTool, FR_PageView pPageView, FS_INT32 nStartIndex, FS_INT32 nEndIndex, FS_BOOL bShowLayer, FS_BOOL bTextIndex);

    //************************************
    // Function:  Select_GetPageRange
    // Param[in]: textSelectTool	The input text select tool.
    // Param[out]: nStartPage        The start index of the selected page
    // Param[out]: nEndPage          The end index of the selected page
    // Return:	  void
    // Remarks: Get the index range of the selected page.
    // Notes:
    // See:
    //************************************
    static void Select_GetPageRange(FR_TextSelectTool textSelectTool, FS_INT32 &nStartPage, FS_INT32 &nEndPage);
    //************************************
    // Function:  GetSelectedText2
    // Param[in]: textSelectTool            The input text select tool.
    // Param[in]: bLineBreakBetweenPages    The flag of line break between pages.
    // Param[out]: outText                  The received text of selected.
    // Return:  <a>TRUE</a> Get the selected text from the input text select tool successful, otherwise not.
    // Remarks: Gets the selected text form the input text select tool, allow line breaks between pages.
    // Notes: The function can only be used for Windows.
    // See:
    //************************************
    static FS_BOOL GetSelectedText2(FR_TextSelectTool textSelectTool, FS_BOOL bLineBreakBetweenPages, FS_WideString* outText);

    //************************************
    // Function:  GetSelectedTestInfo
    // Param[in]: textSelectTool	The input text select tool.
    // Param[out]: outText			It receives the text selected.
    // Return:  <a>TRUE</a> If get the selected text info point array form the input text select tool is successful, otherwise not.
    // Remarks: Get the selected text info form the input text select tool outText, the point array is <a>FS_SELECTEDTEXT_INFO</a> array.
    // Notes: 	That need to call ReleaseSelectedInfo to release <a>outTextInfo</a>.
    // See: FRTextSelectToolReleaseSelectedInfo
    //************************************
    static FS_BOOL GetSelectedTextInfo(FR_TextSelectTool textSelectTool, FS_PtrArray* outTextInfo);

	//************************************
	// Function:  ReleaseSelectedInfo
    // Param[in]: outTextInfo	The selected text info point array
	// Return:  void.
    // Remarks: Release the selected text info point array.
	// Notes: 	
    // See: FRTextSelectToolGetSelectedTextInfo
    // See: FRTextSelectToolGetSelectedData
	//************************************
	static void ReleaseSelectedInfo(FS_PtrArray outTextInfo);

	//************************************
	// Function:  IsSelected
	// Param[in]: textSelectTool	The input text select tool.	
    // Return:  <a>TRUE</a> If there has selected text currently from the input text select tool, otherwise not.
    // Remarks: Checks whether the input text select tool has selected text currently.
    // Notes:
	// See: 
	//************************************
	static FS_BOOL		IsSelected(FR_TextSelectTool textSelectTool);

	//************************************
    // Function:  IsPageSelectAll
	// Param[in]: textSelectTool	The input text select tool.	
	// Param[in]: nPageIndex	    The input page index.	
    // Return:  <a>TRUE</a> If all text is selected by the input text select tool in the input page index, otherwise not.
    // Remarks: Checks whether the input text select tool has selected all text currently in the input page index,.
    // Notes: The function can only be used for Windows.
	// See: 
	//************************************
	static FS_BOOL		IsPageSelectAll(FR_TextSelectTool textSelectTool, FS_INT32 nPageIndex);

	//************************************
	// Function:  GetSelectedData
	// Param[in]: textSelectTool	The input text select tool.	
    // Param[out]: selectedData	    The the selected data info array recive from all the pages.
    // Return:  <a>TRUE</a> If get the selected data of all the page by the input text select tool is success, otherwise not.
    // Remarks: Get the selected data of all the page by the input text select tool.
    // Notes: 	That need to call ReleaseSelectedInfo to release <a>selectedData</a>.
	// See: 
	//************************************
	static FS_BOOL     GetSelectedData(FR_TextSelectTool textSelectTool, FR_TextSelectedData* selectedData);

	//************************************
	// Function:  AddSelect2
	// Param[in]: textSelectTool	The input text select tool.	
    // Param[in]: pPageView	        The page view object.
	// Param[in]: arFormRects		The select rect array.
	// Return:  void.
    // Remarks: Select according to the incoming page view and rectangular area.
    // Notes:
	// See: 
	//************************************
	static void  AddSelect2(FR_TextSelectTool textSelectTool, FR_PageView pPageView, FS_FloatRectArray arFormRects);

	//************************************
	// Function:  AddSelectTextRects
	// Param[in]: textSelectTool	The input text select tool.	
    // Param[in]: pPageView	        The page view object.
	// Param[in]: arTextRects		The select rect array.
    // Param[in]: bContains		    Is segment contains allowed.
	// Return:  void.
    // Remarks: Select the text rectangle area according to the input parameters.
    // Notes:
	// See: 
	//************************************
	static void	AddSelectTextRects(FR_TextSelectTool textSelectTool, FR_PageView pPageView, FS_FloatRectArray arTextRects, FS_BOOLEAN bContains);

	//************************************
	// Function:  GetSelectPDFRect
    // Param[in]: textSelectTool        The input text select tool.
    // Param[in]: pPageView             The page view object.
    // Param[out]: rect_array           The select rect array.
    // Param[in]: bNeedPageViewVisible	Whether the page view is required to be visible.
	// Return:  void.
    // Remarks: Get the currently selected rectangular area according to the input parameters.
    // Notes:
	// See: 
	//************************************
	static void	GetSelectPDFRect(FR_TextSelectTool textSelectTool, FR_PageView pPageView, FS_FloatRectArray* rect_array, FS_BOOL bNeedPageViewVisible);

    //************************************
    // Function:  DeselectAll
    // Param[in]: textSelectTool	The input text select tool.	
    // Return:  void.
    // Remarks: Deselect all seletion area.
    // Notes:
    // See: 
    //************************************
    static void	DeselectAll(FR_TextSelectTool textSelectTool);

    //************************************
    // Function: AddSelectTextRectsWithPages
    // Param[in]: textSelectTool    The input text select tool.
    // Param[in]: mapselectRects    The Map which is include page idnex and selected array.
    // Return: void.
    // Remarks:According to the incoming page number and regional position key to select the operation.
    // Notes: The structure of <a>mapselectRects</a> is std::map<int*, FS_SelectPos*>
    // See:
    // Deprecated: Internal use.
    //************************************
    static void AddSelectTextRectsWithPages(FR_TextSelectTool textSelectTool, FS_MapPtrToPtr mapselectRects);

	//************************************
	// Function: GetExportSelectionPageCount
	// Param[in]: textSelectTool    The input text select tool.
	// Param[out]: nPageCount       Select the page count.
	// Param[in]: pFun              The ui progress callback.
	// Param[in]: pUIProgress       The client data of the UI progress.
	// Return: FS_BOOL.
	// Remarks: Get the export select page count.
	// Notes:
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID GetExportSelectionPageRects(FR_TextSelectTool textSelectTool, FS_INT32* nPageCount, FRSelectTextProgressProc pFun, FS_LPVOID pUIProgress);

	//************************************
	// Function: CopyToClipBoard
	// Param[in]: textSelectTool    The input text select tool.
	// Param[in]: pageIndexArra     The input page array.
	// Param[in]: rectsArray        The rect array match to each page.	It need contains FS_FloatRectArray.
	// Param[in]: bIncXMLSpreadsheet Whether need to format xml type.	
	// Return: void.
	// Remarks: Copy content to clip board.
	// Notes:
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	 CopyToClipBoard(FR_TextSelectTool textSelectTool, FS_Int32Array pageIndexArra, FS_PtrArray rectsArray, FS_BOOL bIncXMLSpreadsheet);

	//************************************
	// Function: SelectEnumTextObjectPathPoint
	// Param[in]: textSelectTool    The input text select tool.
	// Param[in]: page_index        The input page index.
	// Param[out]: result           Get the path points.	
	// Return: FS_BOOL.  TRUE: Select the text success.
	// Remarks: Get the select text points.
	// Notes: If return TRUE, need call FRTextSelectToolReleaseTextObjectPathPoints to release the points obj.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	SelectEnumTextObjectPathPoint(FR_TextSelectTool textSelectTool, FS_INT32 page_index, FS_PtrArray* result);

	//************************************
	// Function: ReleaseTextObjectPathPoints
	// Param[in]: points    The input path points need to release.	
	// Return: void
	// Remarks: Release the select text points.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void ReleaseTextObjectPathPoints(FS_PtrArray points);

	//************************************
	// Function: SelectInitSelection
	// Param[in]: textSelectTool    The input text select tool.
	// Param[in]: page_index        The input page index.		
	// Return: FS_BOOL.  TRUE: Init success.
	// Remarks: Init page selection.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SelectInitSelection(FR_TextSelectTool textSelectTool, FS_INT32 page_index);

	//************************************
	// Function: SelectOnKeyDown
	// Param[in]: textSelectTool    The input text select tool.
	// Param[in]: nKeyCode          The input key code.
	// Param[in]: nFlags            The input flag.
	// Param[in]: bShowCaret        If show caret.
	// Return: FS_BOOLEAN.  TRUE: Init success.
	// Remarks: On key down.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	SelectOnKeyDown(FR_TextSelectTool textSelectTool, FS_UINT nKeyCode, FS_UINT nFlags, FS_BOOL bShowCaret);

	//************************************
	// Function:  DoLButtonDown2
	// Param[in]: textSelectTool	The input text select tool.
	// Param[in]: pageView			The input page view where do the operation of text selecting.
	// Param[in]: point				The input point where do the mouse operation.
	// Param[in]: bUsedByHandTool	If uses by hand tool.
	// Return: void.
	// Remarks:	  Does the mouse left button down operation.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	DoLButtonDown2(FR_TextSelectTool textSelectTool, FR_PageView pageView, FS_DevicePoint point, FS_BOOL bUsedByHandTool);

	//************************************
	// Function:  GetSelectedTextObject
	// Param[in]: textSelectTool	The input text select tool.
	// Param[in]: nPageIdx			The input page index.
	// Param[out]: textObjArr		Get the selected FR_STRUCTCONTENT_OBJECT array.	
	// Return: FS_BOOL.
	// Remarks:	  Get the selected text object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	GetSelectedTextObject(FR_TextSelectTool textSelectTool, FS_INT32 nPageIdx, FS_PtrArray* textObjArr);

	//************************************
	// Function:  DoCopy
	// Param[in]: textSelectTool	The input text select tool.
	// Param[in]: bFormat			Whether format copy.	
	// Return: void.
	// Remarks:	  Get the selected text object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void		DoCopy(FR_TextSelectTool textSelectTool, FS_BOOL bFormat);

	//************************************
	// Function:  ToolDraw
	// Param[in]: textSelectTool	The input text select tool.
	// Param[in]: hDC			    The input HDC.
	// Param[in]: pDevice			The input FPD_RenderDevice .	
	// Param[in]: dwFlags			The input flag, default is 0.	
	// Return: void.
	// Remarks:	 Draw the caret.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	    ToolDraw(FR_TextSelectTool textSelectTool, FS_HDC hDC, FPD_RenderDevice pDevice, FS_DWORD dwFlags);

	//************************************
	// Function:  SetFloatyShowState
	// Param[in]: textSelectTool	The input text select tool.
	// Param[in]: bShow			    Set if show property floaty.	
	// Return: void.
	// Remarks:	 Set if show property floaty.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void		SetFloatyShowState(FR_TextSelectTool textSelectTool, FS_BOOL bShow);

	//************************************
	// Function:  GetFloatyShowState
	// Param[in]: textSelectTool	The input text select tool.	
	// Return: FS_BOOL.
	// Remarks:	 Get if show property floaty.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	GetFloatyShowState(FR_TextSelectTool textSelectTool);

	//************************************
	// Function:  AddHighlightSelect
	// Param[in]: textSelectTool	The input text select tool.	
	// Param[in]: posArr	        The input FR_HighLightPageTextPos array.	
	// Return: void
	// Remarks:	 Add highlight select text.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	AddHighlightSelect(FR_TextSelectTool textSelectTool, FS_PtrArray posArr);

	//************************************
	// Function:  GetHltSelPagesTextPos
	// Param[in]: textSelectTool	The input text select tool.	
	// Param[out]: textPosArr	    Gets an array of page selection text positions, it contains PFR_HighLightPageTextPos obj.
	// Return: FS_BOOL
	// Remarks:	 Gets an array of page selection text positions.
	// Notes: It need call FRTextSelectToolRelHltSelPagesTextPos to release FR_HighLightPageTextPos data.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See: FRTextSelectToolReleaseHltSelPagesTextPos
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	GetHltSelPagesTextPos(FR_TextSelectTool textSelectTool, FS_PtrArray* textPosArr);

	//************************************
	// Function:  RelHltSelPagesTextPos	
	// Param[in]: textPosArr	    The input select text pos. It get from 	FRTextSelectToolGetHltSelPagesTextPos.
	// Return: void
	// Remarks:	 Release select texts pos info.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	RelHltSelPagesTextPos(FS_PtrArray textPosArr);

	//************************************
	// Function:  AddHighlightAdvSelect
	// Param[in]: textSelectTool	The input text select tool.	
	// Param[in]: posArr	        The input FR_HighLightPageTextPos array.
	// Param[in]: bIndexSearch	    If search for char index.	
	// Return: void
	// Remarks:	 Add advanced highlight select text, it for advanced search.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	AddHighlightAdvSelect(FR_TextSelectTool textSelectTool, FS_PtrArray posArr, FS_BOOL bIndexSearch);
	
	//************************************
	// Function:  GetHltAdvSelPagesTextPos
	// Param[in]: textSelectTool	The input text select tool.	
	// Param[out]: textPosArr	    Gets an array of page advanced selection text positions, it contains PFR_HighLightPageTextPos obj.
	// Return: FS_BOOL
	// Remarks:	 Get advanced highlight select text.	
	// Notes: It need call FRTextSelectToolRelHltSelPagesTextPos to release FR_HighLightPageTextPos data.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See: FRTextSelectToolReleaseHltSelPagesTextPos
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	GetHltAdvSelPagesTextPos(FR_TextSelectTool textSelectTool, FS_PtrArray* textPosArr);

	//************************************
	// Function:  InvalidateHltSelect
	// Param[in]: textSelectTool	The input text select tool.		
	// Return: void
	// Remarks:	 Invalidates the entire current page view.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void InvalidateHltSelect(FR_TextSelectTool textSelectTool);

	//************************************
	// Function:  ClearHltAdvSelect
	// Param[in]: textSelectTool	The input text select tool.		
	// Return: void
	// Remarks:	Clear advanced highlight select text.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void ClearHltAdvSelect(FR_TextSelectTool textSelectTool);
};

class CFR_ThumbnailView_V3
{
public:

    //************************************
    // Function:  CountPage
    // Param[in]: tv			The input thumbnail view.
    // Return: The count of page displayed in the thumbnail view.
    // Remarks:	Gets the count of page displayed in the thumbnail view.
    // Notes:
    // See: FRDocViewGetThumbnailView
    //************************************
    static FS_INT32 CountPage(FR_ThumbnailView tv);

    //************************************
    // Function:  CountVisiblePage
    // Param[in]: tv			The input thumbnail view.
    // Return: The count of visible page displayed in the thumbnail view.
    // Remarks:	Gets the count of visible page displayed in the thumbnail view.
    // Notes:
    // See: FRDocViewGetThumbnailView
    //************************************
    static FS_INT32 CountVisiblePage(FR_ThumbnailView tv);

    //************************************
    // Function:  GetPageRect
    // Param[in]: tv			The input thumbnail view.
    // Param[in]: nPage			The index of visible pages.
    // Return: The rectangle of specified visible page.
    // Remarks:	Gets the rectangle of specified visible page.
    // Notes:
    // See: FRDocViewGetThumbnailView
    //************************************
    static FS_Rect GetPageRect(FR_ThumbnailView tv, FS_INT32 nPage);

    //************************************
    // Function:  GetVisiblePageRange
    // Param[in]: tv			The input thumbnail view.
    // Param[out]: nFrom		It receives the starting index of visible pages.
    // Param[out]: nTo			It receives the ending index of visible pages.
    // Return: void
    // Remarks:	Gets the index of visible page range.
    // Notes:
    // See: FRDocViewGetThumbnailView
    //************************************
    static void GetVisiblePageRange(FR_ThumbnailView tv, FS_INT32* nFrom, FS_INT32* nTo);

    //************************************
    // Function:  GetPDPage
    // Param[in]: tv		The input thumbnail view.
    // Param[in]: nPage		The index of page.
    // Return: The <a>FPD_Page</a> object.
    // Remarks:	Gets a <a>FPD_Page</a> object according to the input page index and the input thumbnail view.
    // Notes:
    // See: FRDocViewGetThumbnailView
    //************************************
    static FPD_Page GetPDPage(FR_ThumbnailView tv, FS_INT32 nPage);
};

class CPlugin_Annot : public CBA_Annot
{
public:
	CPlugin_Annot(FR_AnnotCallbacksRec*  callback, FPD_Annot pAnnot, FR_Page pPage);
	virtual ~CPlugin_Annot();

	virtual CFX_ByteString				GetDataType();	
	virtual	CFX_ByteString				GetType() const;
	virtual CFX_ByteString				GetSubType() const;
	virtual FX_BOOL						IsSameTabOrder(IReader_Annot* pAnnot);
	virtual int							GetLayoutOrder();
	virtual void						SetLayoutOrder(int nOrder);	
	virtual void						SetAuthor(const CFX_WideString cwAuthor);
	virtual FX_BOOL						DrawAppearance(CFX_RenderDevice* pDevice, const CPDF_Matrix* pUser2Device,
		CPDF_Annot::AppearanceMode mode, const CPDF_RenderOptions* pOptions);

	FR_AnnotCallbacksRec m_callback;
};


class CFR_Annot_V5
{
public:
    //************************************
    // Function:  GetPDFAnnot
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Return: The data layer PDF annotation.
    // Remarks:	Gets the data layer PDF annotation of the input UI layer annotation object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
    //************************************
    static FPD_Annot GetPDFAnnot(FR_Annot frAnnot);

    //************************************
    // Function:  GetType
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Param[out]: outType	It receives the type of the annotation.
    // Return: void
    // Remarks: Gets the type of the input UI layer annotation object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
    //************************************
    static void GetType(FR_Annot frAnnot, FS_ByteString* outType);

    //************************************
    // Function:  GetSubType
    // Param[in]: frAnnot		The input UI layer annotation object.
    // Param[out]: outSubType	It receives the sub type of the annotation.
    // Return: void
    // Remarks:	Gets the sub type of the input UI layer annotation object.
    // Like widget annot subtype: Signature,PushButton,CheckBox,RadioButton,TextField,ListBox,ComboBox,BarCode.
    // text annot subtype: TypeWriter,TextBox,CallOut.
    // screen annot subtype: Image,Movie.
    // Other annot will return empty.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
    //************************************
    static void GetSubType(FR_Annot frAnnot, FS_ByteString* outSubType);

    //************************************
    // Function:  SetVisible
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Param[in]: bShow		It indicates whether the annotation is visible.
    // Return: void
    // Remarks:	Sets the input UI layer annotation object to be visible or not.
    // Notes: You must call this interface in <a>FRPageViewOnWillParsePage</a> callback.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1
    //************************************
    static void SetVisible(FR_Annot frAnnot, FS_BOOL bShow);

    //************************************
    // Function:  GetPageVew
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Param[in]: nIndex	The specified page view index.
    // Return: The associated page view.
    // Remarks:	Gets the associated page view of the input UI layer annotation object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
    //************************************
    static FR_PageView GetPageVew(FR_Annot frAnnot, FS_INT32 nIndex);

    //************************************
    // Function:  GetTabOrder
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Return: The tab order of the input UI layer annotation object.
    // Remarks: Get the tab order of the input UI layer annotation object.
    // Notes:Currently only annot of Widget type supports taborder.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
    //************************************
    static FS_INT32 GetTabOrder(FR_Annot frAnnot);

    //************************************
    // Function:  SetFlags
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Param[in]: dwFlags   The integer of number flag to set.
    // Return: void
    // Remarks:Set a integer of number object for the flag of the specified annotation.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
    //************************************
    static void SetFlags(FR_Annot frAnnot, FS_DWORD dwFlags);

    //************************************
    // Function:  DrawAppearance
    // Param[in]: frAnnot       The input UI layer annotation object.
    // Param[in]: pDevice       The device to draw on.
    // Param[in]: pUser2Device  The transformation matrix from user space to device space.
    // Param[in]: mode          The input appearance mode.
    // Param[in]: pOptions      The render options.
    // Return: <a>TRUE</a> If the appearance successfully found and drawn.
    // Remarks: Draw annotation's appearance, using default appearance rules.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL DrawAppearance(FR_Annot frAnnot, FPD_RenderDevice pDevice, const FS_AffineMatrix pUser2Device, FPD_AnnotAppearanceMode mode, const FPD_RenderOptions pOptions);

    //************************************
    // Function:  IsSelected
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Return: <a>TRUE</a> If the input UI layer annotation object is selected, otherwise not.
    // Remarks:Checks whether the input UI layer annotation object is selected.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
    //************************************
    static FS_BOOL IsSelected(FR_Annot frAnnot);

    //************************************
    // Function:  SetAuthor
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Param[in]: cwAuthor  The string of author to set.
    // Return: void
    // Remarks:Set string for the author of the specified annotation.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
    //************************************
    static void SetAuthor(FR_Annot frAnnot, const FS_WideString cwAuthor);

    //************************************
    // Function:  GetFRDocByAnnot
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Return: The <a>FR_Document</a> object of The input UI layer annotation object.
    // Remarks:	Gets the <a>FR_Document</a> object of The input UI layer annotation object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
    //************************************
    static FR_Document GetFRDocByAnnot(FR_Annot frAnnot);

    //************************************
    // Function:  GetPage
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Return: The <a>FR_Page</a> object of The input UI layer annotation object.
    // Remarks:	Gets the <a>FR_Page</a> object of The input UI layer annotation object.
    // Remarks:
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
	// Deprecated: Internal use.
    //************************************
    static FR_Page	GetPage(FR_Annot frAnnot);

    //************************************
    // Function:  GetXFAWidget
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Return: The <a>PFPDXFA_HWIDGET</a> object of The input UI layer annotation object.
    // Remarks:	Gets the <a>PFPDXFA_HWIDGET</a> object of The input UI layer annotation object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
    //************************************
    static PFPDXFA_HWIDGET GetXFAWidget(FR_Annot frAnnot);

    //************************************
    // Function:  GetCBFWidget
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Return: The <a>FR_CBF_Widget</a> object of The input UI layer annotation object.
    // Remarks:	Gets the <a>FR_CBF_Widget</a> object of The input UI layer annotation object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
    //************************************
    static FR_CBF_Widget GetCBFWidget(FR_Annot frAnnot);

    //************************************
    // Function:  GetBorderWidth
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Param[out]: outWidth	The border width value.
    // Return: <a>TRUE</a> If get the border width of the input UI layer annotation object successfully, otherwise not.
    // Remarks: Get the border width of the input UI layer annotation object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    //************************************
    static FS_BOOL			GetBorderWidth(FR_Annot frAnnot, FS_INT32* outWidth);

    //************************************
    // Function:  GetBorderStyle
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Param[out]: outStyle	The border style. Like FRBBS_SOLID.
    // Return: <a>TRUE</a> If get the border style of the input UI layer annotation object successfully, otherwise not.
    // Remarks: Get the border style of the input UI layer annotation object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    //************************************
    static FS_BOOL			GetBorderStyle(FR_Annot frAnnot, FS_INT32* outStyle);

    //************************************
    // Function:  SetBorderWidth
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Param[in]: nWidth	The border width value.
    // Return: void.
    // Remarks:	Set the border width of the input UI layer annotation object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    //************************************
    static void			   SetBorderWidth(FR_Annot frAnnot, FS_INT32 nWidth);

    //************************************
    // Function:  SetBorderStyle
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Param[in]: nStyle	The border style value.	Like FRBBS_SOLID.
    // Return: void.
    // Remarks:	Set the border style of the input UI layer annotation object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    //************************************
    static void				SetBorderStyle(FR_Annot frAnnot, FS_INT32 nStyle);

    //************************************
    // Function:  GetLayoutOrder
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Return: The layout order(0 = TopMost, 1 = Screen, 2 = Link,  3 = Widget,  4 = < Other).
    // Remarks:	Get layout order of the input UI layer annotation object.
    // Notes:It used for annot taborder, redaction will return 0, markupannot will return 5, Widget will return 3, Screen will return 1.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // Deprecated: Internal use.
    //************************************
    static FS_INT32  	GetLayoutOrder(FR_Annot frAnnot);

    //************************************
    // Function:  IsSameTabOrder
    // Param[in]: frAnnot	The input UI layer annotation object.
    // Param[in]: pAnnot	Another annot to compare.
    // Return: <a>TRUE</a> If the two annotations of the input are the same group, otherwise not.
    // Remarks: Check whether the two annotations of the input are the same group. the two annotations subtype must be RadioButton.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    //************************************
    static FS_BOOL		IsSameTabOrder(FR_Annot frAnnot, FR_Annot pAnnot);

	//************************************
	// Function:  New
	// Param[in]: callback	The input FR_AnnotCallbacks.
	// Param[in]: pAnnot	The input FPD_Annot.
	// Param[in]: page	    The input FR_Page.
	// Return: FR_Annot   
	// Remarks: Construct FR_Annot in FRNewAnnot of FRD_BAAnnotHandlerCallbacksRec.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FR_Annot		New(FR_AnnotCallbacks callback, FPD_Annot pAnnot, FR_Page page);

	//************************************
	// Function:  Delete	
	// Param[in]: frAnnot	The input FR_Annot.
	// Return: void
	// Remarks: Release FR_Annot.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void		Delete(FR_Annot frAnnot);

	//************************************
	// Function:  IsEnabled	
	// Param[in]: frAnnot	        The input FR_Annot.
	// Param[in]: bIgnoreCReview	If ignore CReview.
	// Return: FS_BOOLEAN
	// Remarks: Get if enable the annot.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// Deprecated: Internal use
	//************************************
	static FS_BOOLEAN	IsEnabled(FR_Annot frAnnot, FS_BOOLEAN bIgnoreCReview);

	//************************************
	// Function:  SetEnabled	
	// Param[in]: frAnnot	The input FR_Annot.
	// Param[in]: bEnable	Set enable flag of the FR_Annot.
	// Return: void
	// Remarks: Set enable the FR_Annot.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// Deprecated: Internal use
	//************************************
	static void	 SetEnabled(FR_Annot frAnnot, FS_BOOLEAN bEnable);

	//************************************
	// Function:  SelectAnnot	
	// Param[in]: frAnnot	The input FR_Annot.
	// Param[in]: pDocument	The input FR_Document.
	// Return: void
	// Remarks: Select annot.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	// Deprecated: Internal use
	//************************************
	static void	SelectAnnot(FR_Annot frAnnot, FR_Document pDocument);
};

class CFR_Redaction_V14
{
public:
    //************************************
    // Function:  ApplyDoc
    // Param[in]: frDocument	The opened pdf document
    // Param[in]: bSlient       if it sets FALSE, the redaction explain dialog will display before redacting.
    // Return: <a>TRUE</a> If apply redaction in the document successfully, otherwise not.
    // Remarks:	Apply redaction in the document: remove the text or graphics under marked areas permanently.
    // Notes: Once this functions is called, all the marked page content(text object, image object, and path object) in the document will be removed permanently.
    //************************************
    static FS_BOOL ApplyDoc(FR_Document frDocument,FS_BOOL bSlient);

    //************************************
    // Function:  Apply
    // Param[in]: frDocument	The opened pdf document
    // Param[in]: annots        The array of <a>FR_Annot</a> is prepared to apply
    // Param[in]: bSlient       if it sets FALSE, the redaction explain dialog will display before redacting.
    // Return: <a>TRUE</a> If apply redaction in the document successfully, otherwise not.
    // Remarks:	Apply redaction in marked areas: remove the text or graphics under marked areas permanently.
    // Notes: Once this functions is called, the content(text object, image object, and path object) in the annots array will be removed permanently.
    //************************************
    static FS_BOOL Apply(FR_Document frDocument, FS_PtrArray annots,FS_BOOL bSlient);

	//************************************
	// Function:  ApplyDoc2
	// Param[in]: frDocument	The opened pdf document
	// Param[in]: bSlient       if it sets FALSE, the redaction explain dialog will display before redacting.
	// Param[in]: option        Set the redact options.
	// Return: <a>TRUE</a> If apply redaction in the document successfully, otherwise not.
	// Remarks:	Apply redaction in the document: remove the text or graphics under marked areas permanently.
	// Notes: Once this functions is called, all the marked page content(text object, image object, and path object) in the document will be removed permanently.
	//************************************
	static FS_BOOL ApplyDoc2(FR_Document frDocument, FS_BOOL bSlient, FR_RedactOption option);
};

class CFR_ResourcePropertyBox_V5	//Internal use
{
public:
    //************************************
    // Function:  Get
    // Return: The property box. It is used to edit the properties of objects, such as the annotations, the pages and so on.
    // Remarks: Gets the property box. The Foxit Reader creates the property box so that many types of objects can reuse the same property box
    // to edit the properties. For example, the objects can be annotations, pages and so on.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static FR_ResourcePropertyBox Get();

    //************************************
    // Function:  RegisterPropertyPage
    // Param[in]: rpBox	The input property box object.
    // Param[in]: pPage	The input callbacks used to add the new property page to the property box.
    // Return: void
    // Remarks: Registers the callbacks used to add the new property page to the property box.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static void	RegisterPropertyPage(FR_ResourcePropertyBox rpBox, FR_ResourcePropertyPageCallbacks pPage);

    //************************************
    // Function:  RegisterSourceType
    // Param[in]: rpBox			The input property box object.
    // Param[in]: nSource		The input source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
    // Param[in]: bLockButton	Indicates whether to show the check box used to lock the source.
    // Param[in]: pSourceFunc	The input callbacks used to deal with the source of the property box.
    // Param[in]: pNotifyFunc	The input callbacks that will be called when events occur.
    // Return: void
    // Remarks: Registers the source type.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static void	RegisterSourceType(FR_ResourcePropertyBox rpBox, FS_INT32 nSource, FS_BOOL bLockButton, FR_ResourcePropertySourceCallbacks pSourceFunc, FR_ResourcePropertyNotifyCallbacks pNotifyFunc);

    //************************************
    // Function:  GetSourceType
    // Param[in]: rpBox	The input property box object.
    // Return: The source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
    // Remarks: Gets the source type of the property box.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static FS_INT32 GetSourceType(FR_ResourcePropertyBox rpBox);

    //************************************
    // Function:  GetSourceFunc
    // Param[in]: rpBox		The input property box object.
    // Param[in]: nSource	The specified source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
    // Return: The property source.
    // Remarks: Gets the specified property source.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static FR_ResourcePropertySource GetSourceFunc(FR_ResourcePropertyBox rpBox, FS_INT32 nSource);

    //************************************
    // Function:  UpdatePropertyBox
    // Param[in]: rpBox		The input property box object.
    // Param[in]: nSource	The specified source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
    // Return: void
    // Remarks: Updates the property box.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static void	UpdatePropertyBox(FR_ResourcePropertyBox rpBox, FS_INT32 nSource);

    //************************************
    // Function:  OpenPropertyBox
    // Param[in]: rpBox		The input property box object.
    // Param[in]: nSource	The specified source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
    // Return: void
    // Remarks: Opens the property box.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static void	OpenPropertyBox(FR_ResourcePropertyBox rpBox, FS_INT32 nSource);

    //************************************
    // Function:  ClosePropertyBox
    // Param[in]: rpBox	The input property box object.
    // Return: void
    // Remarks: Closes the property box.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static void	ClosePropertyBox(FR_ResourcePropertyBox rpBox);

    //************************************
    // Function:  IsPropertyBoxVisible
    // Param[in]: rpBox	The input property box object.
    // Return: <a>TRUE</a> if the property box is visible, otherwise not.
    // Remarks: Checks whether the property box is visible or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static FS_BOOL IsPropertyBoxVisible(FR_ResourcePropertyBox rpBox);

    //************************************
    // Function:  GetWnd
    // Param[in]: rpBox	The input property box object.
    // Return: The window handle of the property box.
    // Remarks: Gets the window handle of the property box.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static FS_HWND GetWnd(FR_ResourcePropertyBox rpBox);

    //************************************
    // Function:  GetPropertyPage
    // Param[in]: rpBox		The input property box object.
    // Param[in]: lpwsName	The specified name of the property page.
    // Return: The property page.
    // Remarks: Gets the property page by name.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static FR_ResourcePropertyPage GetPropertyPage(FR_ResourcePropertyBox rpBox, FS_LPCWSTR lpwsName);

    //************************************
    // Function:  SetCurrentPropertyPage
    // Param[in]: rpBox     The input property box object.
    // Param[in]: pPage     The input property page.
    // Return: void
    // Remarks: Sets the current property page of the input property box object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
	// Deprecated: Internal use
    //************************************
    static void	SetCurrentPropertyPage(FR_ResourcePropertyBox rpBox, FR_ResourcePropertyPage pPage);

    //************************************
    // Function:  RegisterPropertyPage2
    // Param[in]: rpBox	The input property box object.
    // Param[in]: pPage	The input callbacks used to add the new property page to the property box.
    // Return: The page object that needs to be destroyed by <a>FRResourcePropertyBoxDestroyPage</a>.
    // Remarks: Registers the callbacks used to add the new property page to the property box.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
    // See: FRResourcePropertyBoxDestroyPage
	// Deprecated: Internal use
    //************************************
    static void* RegisterPropertyPage2(FR_ResourcePropertyBox rpBox, FR_ResourcePropertyPageCallbacks pPage);

    //************************************
    // Function:  DestroyPage
    // Param[in]: pPage	The page object returned by <a>FRResourcePropertyBoxRegisterPropertyPage2</a>.
    // Return: void.
    // Remarks: Destroys the page object returned by <a>FRResourcePropertyBoxRegisterPropertyPage2</a>.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
    // See: FRResourcePropertyBoxRegisterPropertyPage2
	// Deprecated: Internal use
    //************************************
    static void DestroyPage(void* pPage);

    //************************************
    // Function:  RegisterSourceType2
    // Param[in]: rpBox			The input property box object.
    // Param[in]: nSource		The input source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
    // Param[in]: bLockButton	Indicates whether to show the check box used to lock the source.
    // Param[in]: pSourceFunc	The input callbacks used to deal with the source of the property box.
    // Param[in]: pNotifyFunc	The input callbacks that will be called when events occur.
    // Return: The source object that needs to be destroyed by <a>FRResourcePropertyBoxDestroySource</a>.
    // Remarks: Registers the source type.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See: FRResourcePropertyBoxDestroySource
	// Deprecated: Internal use
    //************************************
    static void* RegisterSourceType2(FR_ResourcePropertyBox rpBox, FS_INT32 nSource, FS_BOOL bLockButton, FR_ResourcePropertySourceCallbacks pSourceFunc, FR_ResourcePropertyNotifyCallbacks pNotifyFunc);

    //************************************
    // Function:  DestroySource
    // Param[in]: pPage	The source object returned by <a>FRResourcePropertyBoxRegisterSourceType2</a>.
    // Return: void.
    // Remarks: Destroys the source object returned by <a>FRResourcePropertyBoxRegisterSourceType2</a>.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
    // See: FRResourcePropertyBoxRegisterSourceType2
	// Deprecated: Internal use
    //************************************
    static void DestroySource(void* pSource);

	//************************************
	// Function:  AddPropertyNotify
	// Param[in]: rpBox			The input property box object.	
	// Param[in]: pSourceFunc	The input FR_ResourcePropertySource, it get from FRResourcePropertyBoxGetSourceFunc.
	// Param[in]: pNotifyFunc	The input callbacks that will be called when events occur.
	// Return: The source object that needs to be destroyed by <a>FRResourcePropertyBoxDestroySource</a>.
	// Remarks: Add new notify to the specified pSource.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.1.0
	// See: FRResourcePropertyBoxDestroySource
	// Deprecated: Internal use
	//************************************
	static void* AddPropertyNotify(FR_ResourcePropertyBox rpBox, FR_ResourcePropertySource pSource, FR_ResourcePropertyNotifyCallbacks pNotifyFunc);
};

class CFR_ScrollBarThumbnailView_V6     //Internal use.
{
public:

    //************************************
    // Function:  GetCurPageIndex
    // Param[in]: tv			The input scrollbar thumbnail view.
    // Return: The index of page currently displayed in the scroll bar thumbnail view.
    // Remarks:	Gets the index of page currently displayed in the scroll bar thumbnail view.
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_INT32 GetCurPageIndex(FR_ScrollBarThumbnailView tv);

    //************************************
    // Function:  GetPageRect
    // Param[in]: tv			The input scrollbar thumbnail view.
    // Return: The rectangle of specified visible page in the scroll bar thumbnail view.
    // Remarks:	Gets the rectangle of specified visible page in the scroll bar thumbnail view.
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    // See:
	// Deprecated: Internal use
    //************************************
    static FS_Rect GetPageRect(FR_ScrollBarThumbnailView tv);

    //************************************
    // Function:  GetPDPage
    // Param[in]: tv		The input scrollbar thumbnail view.
    // Return: The <a>FPD_Page</a> object.
    // Remarks:	Gets a <a>FPD_Page</a> object of the input scrollbar thumbnail view.
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    // See:
	// Deprecated: Internal use
    //************************************
    static FPD_Page GetPDPage(FR_ScrollBarThumbnailView tv);
};

class CFR_Reader_DispViewerEx_V14 //Internal use.
{
public:
    //************************************
    // Function:  CreateDispViewer
    // Param[in]:  pDocView         The document view object.
    // Param[in]:  pHandler         Callback handle from <a>FRIReaderDispViewerHandlerNew</a>
    // Return: The <a>FR_IReader_DispViewer</a> object.
    // Remarks:	 Create an <a>FR_IReader_DispViewer</a> object based on the input document view and set the callback handle.
    // Notes:
    // See:
	// Deprecated: Internal use
    //************************************
    static FR_IReader_DispViewer	CreateDispViewer(FR_DocView pDocView, FR_IReader_DispViewerHandler  pHandler);

    //************************************
    // Function:  GetDocView
    // Param[in]:  DispViewer       The reader dispViewer object.
    // Return: The <a>FR_DocView</a> object.
    // Remarks:	 Get the document view object of the input reader dispViewer object.
    // Notes:
    // See:
	// Deprecated: Internal use
    //************************************
    static FR_DocView               GetDocView(FR_IReader_DispViewer DispViewer);

    //************************************
    // Function:  SetSize
    // Param[in]:  DispViewer       The reader dispViewer object.
    // Param[in]:  nSizeX           The width of the reader dispViewer object size to set.
    // Param[in]:  nSizeY           The height of the reader dispViewer object size to set.
    // Return: void.
    // Remarks:	 Set the size of the reader dispViewer object according to the input parameters.
    // Notes:
    // See:
	// Deprecated: Internal use
    //************************************
    static void                     SetSize(FR_IReader_DispViewer DispViewer, FS_INT32 nSizeX, FS_INT32 nSizeY);

    //************************************
    // Function:  GetRenderData
    // Param[in]:  DispViewer       The reader dispViewer object.
    // Return: A <a>FS_DIBitmap</a> object of the reader dispViewer object.. This <a>FS_DIBitmap</a> object must be destroied by calling
    // <a>FSDIBitmapDestroy</a>().
    // Remarks:	 Gets the rendering data of the input reader dispViewer object.
    // Notes:
    // See:
	// Deprecated: Internal use
    //************************************
    static FS_DIBitmap             GetRenderData(FR_IReader_DispViewer DispViewer);

    //************************************
    // Function:  CreateDispViewer
    // Param[in]:  DispViewer       The reader dispViewer object.
    // Return: void.
    // Remarks:	 Do continue rendering for the reader dispViewer object.
    // Notes:
    // See:
	// Deprecated: Internal use
    //************************************
    static void                    ContinueRendering(FR_IReader_DispViewer DispViewer);

    //************************************
    // Function:  SetCenterPos
    // Param[in]:  DispViewer       The reader dispViewer object.
    // Param[in]:  nPage            The index of the pdf viewer page.
    // Param[in]:  dbZoom           The zoom factor, specified as a magnification factor(for example, 1.0 displays the document at actual size).
    // Param[in]:  pt               The center point to set.
    // Return: void.
    // Remarks:	 Set the center position of the reader dispViewer object according to the input parameters
    // Notes:
    // See:
	// Deprecated: Internal use
    //************************************
    static void                    SetCenterPos(FR_IReader_DispViewer DispViewer, FS_INT32 nPage, double dbZoom, FS_FloatPoint pt);

    //************************************
    // Function:  DocToWindow
    // Param[in]:  DispViewer       The reader dispViewer object.
    // Param[in]:  nPage            The index of the pdf viewer page.
    // Param[in]:  doc_x            The x-coordinate of the point to transform, specified in user space coordinates.
    // Param[in]:  doc_y            The y-coordinate of the point to transform, specified in user space coordinates.
    // Param[in]:  window_x         The Y coordinate of the converted point is specified by the equipment space coordinate.
    // Param[in]:  window_y         The Y coordinate of the converted point is specified by the equipment space coordinate.
    // Return: void.
    // Remarks:	 Transforms a point from user space to device space.
    // Notes:
    // See:
	// Deprecated: Internal use
    //************************************
    static void                     DocToWindow(FR_IReader_DispViewer DispViewer, FS_INT32 nPage, FS_FLOAT doc_x, FS_FLOAT doc_y, FS_INT64& window_x, FS_INT64& window_y);

    //************************************
    // Function:  GetCurrentMatrix
    // Param[in]:  DispViewer       The Reader DispViewer Object.
    // Param[in]:  nPage			The index of the pdf viewer page.
    // Param[in]:  matrix			It receives the transform matrix from PDF/XFA user space to targeted device space.
    // Return: 	<a>TRUE</a> If get a matrix from PDF/XFA user space to targeted device space successfully, otherwise not.
    // Remarks:	 Get a matrix from PDF/XFA user space to targeted device space,
    // according to metrics info(top-left position and widht-height size) provided in the pdf viewer page.
    // Notes:
    // See:
	// Deprecated: Internal use
    //************************************
    static FS_BOOL                  GetCurrentMatrix(FR_IReader_DispViewer DispViewer, FS_INT32 nPage, FS_AffineMatrix& matrix);

    //************************************
    // Function:  GetSize
    // Param[in]:  DispViewer       The Reader DispViewer Object.
    // Param[in]:  nSizeX           The width of the reader dispViewer object size.
    // Param[in]:  nSizeY           The height of the reader dispViewer object size.
    // Return: void.
    // Remarks:	 Get the size of the reader dispViewer object.
    // Notes:
    // See:
	// Deprecated: Internal use
    //************************************
    static void                     GetSize(FR_IReader_DispViewer DispViewer, FS_INT32 &nSizeX, FS_INT32 &nSizeY);

	//************************************
	// Function:  DestroyDispViewer
	// Param[in]:  DispViewer       The Reader DispViewer Object.	
	// Return: void.
	// Remarks:	 Destroy display view.
	// Notes:
	// See:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	// Deprecated: Internal use
	//************************************
	static void                     DestroyDispViewer(FR_IReader_DispViewer DispViewer);
};

class CIPDFViewerEventHandler : IPDFViewerEventHandler
{
public:
    CIPDFViewerEventHandler(FPD_IPDFViewerEventHandlerCallbacksRec* pcallbacks)
	{
        memset(&m_callbacks, 0, sizeof(FPD_IPDFViewerEventHandlerCallbacksRec));
        memcpy(&m_callbacks, pcallbacks, pcallbacks->lStructSize);
        if (pcallbacks->lStructSize < sizeof(FPD_IPDFViewerEventHandlerCallbacksRec))
        {
            FS_BYTE* pAddress = (FS_BYTE*)&m_callbacks;
            memset(pAddress + pcallbacks->lStructSize, 0, sizeof(FPD_IPDFViewerEventHandlerCallbacksRec) - pcallbacks->lStructSize);
        }
    }
    virtual		void			OnBeforeDraw(CFX_DIBitmap * pBitmap);

    virtual		void			OnAfterDraw(CFX_DIBitmap * pBitmap);

    virtual		void			OnDrawBkgnd(CFX_DIBitmap * pBitmap);

    virtual		void			OnDrawPageShawdow(CFX_DIBitmap * pBitmap, IPDFViewerPage * pPage);

	virtual		void			OnPageVisible(IPDFViewerPage * pPage, BOOL	bVisble);

    virtual		void			OnPageIndexChange(IPDFViewerPage * pPage);

    virtual		void			OnBeginRender();

    virtual		void			OnFinishRender();

    virtual		void			OnRenderDataChange();

    virtual		void			OnZoomPage(FX_INT32 nPage);

    virtual		void			OnGotoPage(FX_INT32 nPage);

    virtual		void			OnBeforePageDraw(IPDFViewerPage * pPage, CFX_DIBitmap * pBitmap);

    virtual		void			OnAfterPageDraw(IPDFViewerPage * pPage, CFX_DIBitmap * pBitmap);

	virtual		BOOL			IsFullScreenLoopPage();
public:
    FPD_IPDFViewerEventHandlerCallbacksRec m_callbacks;
    void* GetClientData() { return m_callbacks.clientData; }
};

class CFR_IReader_DispViewerHandler : public IReader_DispViewerHandler
{
public:
    CFR_IReader_DispViewerHandler(FR_IReader_DispViewerHandlerCallbacksRec* pcallbacks) {
        memset(&m_callbacks, 0, sizeof(FR_IReader_DispViewerHandlerCallbacksRec));
        memcpy(&m_callbacks, pcallbacks, pcallbacks->lStructSize);
        if (pcallbacks->lStructSize < sizeof(FR_IReader_DispViewerHandlerCallbacksRec))
        {
            FS_BYTE* pAddress = (FS_BYTE*)&m_callbacks;
            memset(pAddress + pcallbacks->lStructSize, 0, sizeof(FR_IReader_DispViewerHandlerCallbacksRec) - pcallbacks->lStructSize);
        }
    }
    virtual	void OnBeginRender(IPDFViewerEventHandler* pHandler);

    virtual	void OnFinishRender(IPDFViewerEventHandler* pHandler);
public:
    FR_IReader_DispViewerHandlerCallbacksRec m_callbacks;
    void* GetClientData() { return m_callbacks.clientData; }
};

class CFR_IReaderDispViewerHandler_V14 //Internal use.
{
public:
    //************************************
    // Function:  New
    // Param[in]:  callbacks       The callback parameter pointer.
    // Return: The <a>FR_IReader_DispViewerHandler</a> object.
    // Remarks:	 Creates a reader dispViewer callback handle based on the incoming callback parameter pointer.
    // Notes: The callback handle that needs to be destroyed by <a>FRIReaderDispViewerHandlerDestroy</a>.
    // See:FRIReaderDispViewerHandlerDestroy
    // Deprecated: Internal use.
    //************************************
    static FR_IReader_DispViewerHandler New(FR_IReader_DispViewerHandlerCallbacksRec* callbacks);

    //************************************
    // Function:  Destroy
    // Param[in]:  handler       The reader dispViewer callback handle.
    // Return: void.
    // Remarks:	 Destroys the input callback handle
    // Notes: The callback handle that needs to be created by <a>FRIReaderDispViewerHandlerNew</a>.
    // See: FRIReaderDispViewerHandlerNew
    // Deprecated: Internal use.
    //************************************
    static void Destroy(FR_IReader_DispViewerHandler handler);
};

class CFR_IPDFViewerEventHandler_V14     //Internal use.
{
public:
    //************************************
    // Function:  New
    // Param[in]:  callbacks       The callback parameter pointer.
    // Return: The <a>FR_IPDFViewerEventHandler</a> object.
    // Remarks:	 Creates a pdf viewer event callback handle based on the incoming callback parameter pointer.
    // Notes: The callback handle that needs to be destroyed by <a>FRIPDFViewerEventHandlerDestroy</a>.
    // See:FRIPDFViewerEventHandlerDestroy
    // Deprecated: Internal use.
    //************************************
    static FR_IPDFViewerEventHandler New(FPD_IPDFViewerEventHandlerCallbacksRec* callbacks);

    //************************************
    // Function:  Destroy
    // Param[in]:  handler       The pdf viewer event callback handle.
    // Return: void.
    // Remarks:	 Destroys the input callback handle
    // Notes: The callback handle that needs to be created by <a>FRIPDFViewerEventHandlerNew</a>.
    // See: FRIPDFViewerEventHandlerNew
    // Deprecated: Internal use.
    //************************************
    static void Destroy(FR_IPDFViewerEventHandler handler);
};

class CFR_ToolFormatMgr_V14 
{
public:
    //************************************
    // Function:  Get
    // Param[in]: hFrame			The  main application 's mainFrame, it can be set Null.
    // Return: The FS_HWND of ToolFormatMgr.
    // Remarks:	Gets the FS_HWND of of ToolFormatMgr.
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
    // See:
    //************************************
    static FR_ToolFormatMgr Get(FS_HWND hFrame);

    //************************************
    // Function:  RegistFormatEvent
    // Param[in]: toolFormatMgr             The ToolFormatMgr Object.
    // Param[in]: formatEventCallbacks      The callback set. Reader will call a corresponding callback when the ToolFormatMgr event occurs.
    // Return: The Address of FormatEventHandler.
    // Remarks:	Register the ToolFormatMgr callback.
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
    // See:
    //************************************
    static FS_LPVOID RegistFormatEvent(FR_ToolFormatMgr toolFormatMgr, FR_FormatEventCallbacks formatEventCallbacks);

    //************************************
    // Function:  UnregisterFormatEvent
    // Param[in]:  toolFormatMgr			The ToolFormatMgr Object.
    // Param[in]:  pFormatToolEvent			The Address of FormatEventHandler.
    // Return: 	<a>TRUE</a> If unregisters the ToolFormatMgr handler and releases the memory successfully, otherwise not.
    // Remarks:	 Unregisters the ToolFormatMgr handler and releases the memory.
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
    // See:
    //************************************
    static FS_BOOL UnregisterFormatEvent(FR_ToolFormatMgr toolFormatMgr, FS_LPVOID pFormatToolEvent);

    //************************************
    // Function:  AddGroup
    // Param[in]:  toolFormatMgr        The ToolFormatMgr Object.
    // Param[in]:  bsGroupName          The unique identify of Group.
    // Param[in]:  wsTitle              The Group Title.
    // Param[in]:  hWnd                 It is used to display the sub window in the group. It is recommended to use the dialog box
    // Return: 	void
    // Remarks: Add a group for the whole mainframe
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
    // See:
    //************************************
    static void AddGroup(FR_ToolFormatMgr toolFormatMgr, FS_ByteString bsGroupName, FS_WideString wsTitle, FS_HWND hWnd);

    //************************************
    // Function: AddGroupToFormat
    // Param[in]:  toolFormatMgr        The ToolFormatMgr Object.
    // Param[in]:  bsFormatName         Format unique identity.
    // Param[in]:  bsGroupName          The groupname contained in the format.
    // Return: 	void
    // Remarks:	Add group to format. Format is for the entire mainframe
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
    // See:
    //************************************
    static void AddGroupToFormat(FR_ToolFormatMgr toolFormatMgr, FS_ByteString bsFormatName, FS_ByteString bsGroupName);

    //************************************
    // Function:  ShowToolFormat
    // Param[in]: toolFormatMgr			The ToolFormatMgr Object.
    // Param[in]: bsFormatName			Format unique identity.
    // Param[in]: wsFormatTitle			The Title of ToolFormatMgr.
    // Return: 	NULL
    // Remarks:	This functioin is used to show the format.In addition,only one user-defined format can be showed at the time.
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
    // See:
    //************************************
    static void ShowToolFormat(FR_ToolFormatMgr toolFormatMgr, FS_ByteString bsFormatName, FS_WideString wsFormatTitle);

    //************************************
    // Function:  IsToolFormatExist
    // Param[in]: toolFormatMgr			The ToolFormatMgr Object.
    // Param[in]: bsFormatName			This agument is't used now and  reserved for future's extentions.Morever,the current tile is format by default;
    // Return:  <a>TRUE</a> If the format Exist, otherwise not.
    // Remarks:	determine whether the format Exist.
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
    // See:
    //************************************
    static bool IsToolFormatExist(FR_ToolFormatMgr toolFormatMgr, FS_ByteString bsFormatName);

    //************************************
    // Function: GetFormatGroups
    // Param[in]: toolFormatMgr			The ToolFormatMgr Object.
    // Param[in]: bsFormatName			The name of format.
    // Param[out]: bsGroupNames			The group names of format.
    // Return: 	void
    // Remarks:	Get the format's name and group names.
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
    // See:
    //************************************
    static void GetFormatGroups(FR_ToolFormatMgr toolFormatMgr, FS_ByteString bsFormatName, FS_ByteStringArray bsGroupNames);

    //************************************
    // Function:  ChangeFormatSize
    // Param[in]: toolFormatMgr			The ToolFormatMgr Object.
    // Param[in]: bsFormatName			The name of format.
    // Param[in]: wsGroupName			The group name of format.
    // Return: 	void
    // Remarks:	The recalculated size according to the current window size of the format group and the layout of the displayed controls
    // Notes: The function can only be used for Windows.
    // Since: <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
    // See:
	// Deprecated: Internal use
    //************************************
    static void ChangeFormatSize(FR_ToolFormatMgr toolFormatMgr, FS_ByteString bsFormatName, FS_ByteString bsGroupName);

    //************************************
   // Function:  UpdateFormatStatus
   // Param[in]: toolFormatMgr			The ToolFormatMgr Object.
   // Return: 	void
   // Remarks:	Update the format status on the right panel
   // Notes: The function can only be used for Windows.
   // Since: <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
   // See:
   //************************************
    static void UpdateFormatStatus(FR_ToolFormatMgr toolFormatMgr);

	//************************************
	// Function:  ShowToolFormat2
	// Param[in]: toolFormatMgr			The ToolFormatMgr Object.
	// Param[in]: bsFormatName			The	format unique identifier.
	// Param[in]: wsFormatTitle			The title of used for display
	// Param[in]: nFormatType			Format type.
	// Param[in]: bAlwaysActivationFormat	Whether need always activate format.
	// Return: 	void
	// Remarks:	Update the format status on the right panel
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	// See:	
	//************************************
	static void ShowToolFormat2(FR_ToolFormatMgr toolFormatMgr, FS_LPCSTR bsFormatName, FS_LPCWSTR wsFormatTitle, FR_FormatType nFormatType, FS_BOOLEAN bAlwaysActivationFormat);

	//************************************
    // Function:  GetLastToolFormatName
	// Param[in]: toolFormatMgr			The ToolFormatMgr Object.
    // Param[in]: pDoc			The input FR_Document object.
	// Param[in\out]: outName	Get the format name.
    // Return: 	void
    // Remarks:	Get the lat format tool name.
    // Notes: 
    // Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
    // See:
	// Deprecated: Internal use.
    //************************************
	static void GetLastToolFormatName(FR_ToolFormatMgr toolFormatMgr, FR_Document pDoc, FS_ByteString* outName);
};

class CFR_TextSelectedData_V14
{
public:
    //************************************
    // Function:  New
    // Return: The <a>FR_TextSelectedData</a> object.
    // Remarks: Create <a>FR_TextSelectedData</a> object.
    // Notes: The object that needs to be destroyed by <a>FRTextSelectedDataDestroy</a>.
    // See: FRTextSelectedDataDestroy
    //************************************
    static FR_TextSelectedData New();

    //************************************
    // Function:  Destroy
    // Param[in]: data	            The input FR_TextSelectedData object.
    // Return:  void.
    // Remarks: Destroy <a>FR_TextSelectedData</a> object.
    // Notes: The object that needs to be created by <a>FRTextSelectedDataNew</a>.
    // See: FRTextSelectedDataNew
    //************************************
    static void Destroy(FR_TextSelectedData data);

    //************************************
    // Function:  GetSelectedPages
    // Param[in]: data	            The input FR_TextSelectedData object.
    // Param[out]: outindexArr	    Get selected text of the pages.
    // Return:  void.
    // Remarks: Get all the pages with selected text.
    // Notes:
    // See:
    //************************************
    static void GetSelectedPages(FR_TextSelectedData data, FS_Int32Array* outindexArr);

    //************************************
    // Function:  GetSelectedDataCountByPageIndex
    // Param[in]: data	            The input FR_TextSelectedData object.
    // Param[in]: index	            The index of page.
    // Return:  The count of selected datas of the pageindex.
    // Remarks: Get the count of selected datas of the pageindex.
    // Notes:
    // See:
    //************************************
    static FS_INT32 GetSelectedDataCountByPageIndex(FR_TextSelectedData data, FS_INT32 index);

    //************************************
    // Function:  GetSelectedDatas
    // Param[in]: data	            The input FR_TextSelectedData object.
    // Param[in]: index	            The index of page.
    // Param[in]: vecIndex	        The index of the selected datas.
    // Return:  The <a>FR_SELECTMSG</a> object.
    // Remarks: Get the selected msg of the page index in the vector.
    // Notes:
    // See:
    //************************************
    static FR_SELECTMSG GetSelectedDatas(FR_TextSelectedData data, FS_INT32 index, FS_INT32 vecIndex);
};


class CFR_IRPPropertySource_V14  //Internal use
{
public:
    //************************************
    // Function:  GetSelectObjectType
    // Param[in]: source            The input FR_ResourcePropertySource object.
    // Param[out]: array            The select object array.
    // Return:  The count of the selected object..
	// Remarks: Get the count of the selected object.
	// Notes: 	
	// See: 
	// Deprecated: Internal use
	//************************************
	static FS_INT32		GetSelectObjectType(FR_ResourcePropertySource source, FS_ByteStringArray* outarray);
	//************************************
	// Function:  CountSelectObjects
	// Param[in]: source            The input FR_ResourcePropertySource object.
	// Return:  The count of the selected object..
	// Remarks: Get the count of the selected object.
	// Notes: 	
	// See: 
	// Deprecated: Internal use
	//************************************
	static FS_INT32 CountSelectObjects(FR_ResourcePropertySource source);
	//************************************
	// Function:  GetSelectObject
	// Param[in]: source            The input FR_ResourcePropertySource object.
	// Param[in]: index            The index of the object to return.
	// Return:  The count of the selected object..
	// Remarks: Get the object at the index.
	// Notes: 	
	// See: 
	// Deprecated: Internal use
	//************************************
	static void* GetSelectObject(FR_ResourcePropertySource source, FS_INT32 nObjIndex);

	//************************************
	// Function:  SetPropertySourceCallback
	// Param[in]: source            The input FR_ResourcePropertySource object.
	// Param[in]: pcallback         The input property source callback.
	// Return:  void
	// Remarks: Set the property source callback, to enable plugin change title.
	// Notes: 	
	// See: 
	// Deprecated: Internal use
	//************************************
	static void	SetPropertySourceCallback(FR_ResourcePropertySource source, FR_PropertySourceCallbacksRec pcallback);
};



class CFR_LayerOperation_V14 //Internal use.
{
public:
    //************************************
    // Function:  Create
    // Param[in]: doc                   The input doc where the operation of layer.
    // Param[in]: nSourcePageIndex      The index of source page.
    // Param[in]: wsDocName             The name of doc.
    // Return: The <a>FR_LayerOperation</a> object.
    // Remarks: Creates layer opearation tool which is used to process the operation of layer object.
    // Notes:The object that needs to be destroyed by <a>FRLayerOperationDestroy</a>.
    // See:FRLayerOperationDestroy
    // Deprecated: Internal use.
    //************************************
    static FR_LayerOperation Create(FPD_Document doc, FS_INT32 nSourcePageIndex, FS_LPCWSTR wsDocName);

    //************************************
    // Function:  DestroyLayerOperation
    // Param[in]: layerOperationTool    The input layer operation tool object.
    // Return: void
    // Remarks: Destroys the layer operation tool object.
    // Notes: The object that needs to be created by <a>FRLayerOperationCreate</a>.
    // See: FRLayerOperationCreate
    // Deprecated: Internal use.
    //************************************
    static void         DestroyLayerOperation(FR_LayerOperation layerOperationTool);

    //************************************
    // Function:  ImportLayer
    // Param[in]: layerOperationTool        The input layer operation tool.
    // Param[in]: pImportDoc                The import document.
    // Param[in]: nImportPageIndex			The selected page index of the import document.
    // Param[in]: wsImportDocName           The name of the import document .
    // Param[in]: importFormBox             Import form box rect.
    // Param[in]: sourceRectPreview         Source document preview rect.
    // Param[in]: importRectPreview			Import document preview rect.
    // Param[in]: nImportOpacity            the opacity of imported layers.
    // Param[in]: IsImportBehindSource      Is import behind the source.
    // Param[in]: wsOCGName                 Layer's name.
    // Param[in]: type                      Import type.
    // Param[in]: importToImportFormKey     The old Form XObject object group in the source file needs a one-to-one correspondence with <param>importToImportFormValue</param>.
    // Param[in]: importToImportFormValue	The new Form XObject object group to be imported in the import file needs to have a one-to-one correspondence with <param>importToImportFormKey</param>.
    // Param[in]: addToGroupName            If type is "IMPORT_CREATE", it is the OCGGroup name of source document.
    // Return:  <a>TRUE</a> If import a layer to the selected page of the source document successfully, otherwise not.
    // Remarks: Import a layer to the selected page of the source document
    // Notes:<param>importToImportFormKey</param> <param>importToImportFormValue</param> purpose: when importing the layer information related to the import page to the source document,
    // you can update the indirect reference places of these page objects according to this map.
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL      ImportLayer(FR_LayerOperation layerOperationTool, FPD_Document pImportDoc, FS_INT32 nImportPageIndex, FS_LPCWSTR wsImportDocName,
                               FS_FloatRect importFormBox, FS_Rect sourceRectPreview, FS_Rect importRectPreview, FS_INT32 nImportOpacity, FS_BOOL IsImportBehindSource,
                               FS_LPCWSTR wsOCGName, FR_ImportType type, FS_DWordArray importToImportFormKey, FS_DWordArray importToImportFormValue, FS_LPCWSTR addToGroupName);

    //************************************
    // Function:  IsChildOCG
    // Param[in]: layerOperationTool	The input layer operation tool.
    // Param[in]: ocgSet                The OCGroupSet to judge
    // Param[in]: parent				The parent OCGroup
    // Param[in]: target                The target OCGroup
    // Return:  <a>TRUE</a> If one OCG exists in the input layer operation tool, otherwise not.
    // Remarks: Judge whether one OCG exists in the input layer operation tool.
    // Notes:
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL      IsChildOCG(FR_LayerOperation layerOperationTool, FPD_OCGroupSet ocgSet, FPD_OCGroup parent, FPD_OCGroup target);

    //************************************
    // Function:  DeleteOCG
    // Param[in]: layerOperationTool	The input layer operation tool.
    // Param[in]: ocgSet                The OCGroupSet to delete
    // Param[in]: ocgGroup				The parent OCGroup
    // Return:  <a>TRUE</a> If delete one OCG from the input layer operation tool successfully, otherwise not.
    // Remarks: Delete one OCG from the input layer operation tool.
    // Notes:
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL      DeleteOCG(FR_LayerOperation layerOperationTool, FPD_OCGroupSet ocgSet, FPD_OCGroup ocgGroup);

    //************************************
    // Function:  ReplaceOCG
    // Param[in]: layerOperationTool	The input layer operation tool.
    // Param[in]: pDoc                  The document
    // Param[in]: ocgSet				The OCGroupSet to be repalced
    // Param[in]: toBeReplaced          The parent OCGroup
    // Param[in]: target                The target OCGroup
    // Return:  <a>TRUE</a> If replace one OCG to the input layer operation tool successfully, otherwise not.
    // Remarks: Replace one OCG to the input layer operation tool.
    // Notes:
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL      ReplaceOCG(FR_LayerOperation layerOperationTool, FPD_Document pDoc, FPD_OCGroupSet ocgSet, FPD_OCGroup toBeReplaced, FPD_OCGroup target);

    //************************************
    // Function:  ReplaceOCGContentHandler
    // Param[in]: layerOperationTool	The input layer operation tool.
    // Param[in]: pDoc                  The document
    // Param[in]: pDict                 The object rect
    // Param[in]: toBeReplaced          The parent OCGroup
    // Param[in]: target                The target OCGroup
    // Return:  <a>TRUE</a> If replace one OCG content to the input layer operation tool successfully, otherwise not.
    // Remarks: Replace one OCG content to the input layer operation tool.
    // Notes:
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL      ReplaceOCGContentHandler(FR_LayerOperation layerOperationTool, FPD_Document pDoc, FPD_Object pDict, FPD_OCGroup toBeReplaced, FPD_OCGroup target);

    //************************************
    // Function:  InsertChildOCG
    // Param[in]: layerOperationTool	The input layer operation tool.
    // Param[in]: pDoc                  The document
    // Param[in]: ocgSet                The OCGroupSet to be inserted
    // Param[in]: target                The target OCGroup
    // Param[in]: arr                   The layer data point array
    // Return:  <a>TRUE</a> If insert one OCG to the input layer operation tool successfully, otherwise not.
    // Remarks: Insert one OCG to the input layer operation tool.
    // Notes:
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL      InsertChildOCG(FR_LayerOperation layerOperationTool, FPD_Document pDoc, FPD_OCGroupSet ocgSet, FPD_OCGroup target, FS_PtrArray arr);

    //************************************
    // Function:  DeleteObjectByVisible
    // Param[in]: layerOperationTool	The input layer operation tool.
    // Param[in]: containe              The object to be deleted is a type in <a>FPD_Page</a> or <a>FPD_Form</a>.
    // Param[in]: pContext              The input optional content context.
    // Param[in]: isPage                Used to determine the type of parameter <a>containe</a>, <a>TRUE</a> is <a>FPD_Page</a> and <a>FALSE</a> is <a>FPD_Form</a>.
    // Return: void.
    // Remarks:   delete OCG by visible
    // Notes:
    // See:
    // Deprecated: Internal use.
    //************************************
    static void         DeleteObjectByVisible(FR_LayerOperation layerOperationTool, FS_LPVOID container, FPD_OCContext pContext, FS_BOOL isPage);
};

class CFR_FormTextFind_V15
{
public:
	//************************************
	// Function:  CreateFormTextFind
	// Param[in]: pDoc	  The input FPD_Document.
	// Param[in]: pPage   The input FPD_Page.
	// Return: void.
	// Remarks:   Create FR_FormTextFind.
	// Notes:
	// See:
	//************************************
	static FR_FormTextFind CreateFormTextFind(FPD_Document pDoc, FPD_Page pPage);

	//************************************
	// Function:  DeleteFormTextFind
	// Param[in]: formTextFind	  The input FR_FormTextFind.
	// Return: void.
	// Remarks:   Delete FR_FormTextFind.
	// Notes:
	// See:
	//************************************
	static void DeleteFormTextFind(FR_FormTextFind formTextFind);

	//************************************
	// Function:  FindFirst
	// Param[in]: formTextFind	  The input FR_FormTextFind.
	// Param[in]: findwhat	      The input find content.
	// Param[in]: flags	          The input FR_FormTextFind. Like FPD_TEXT_MATCHCASE.
	// Return: FS_BOOL.           TRUE : Initialize success.	
	// Remarks:   Before find, need to set some information.
	// Notes:
	// See:
	//************************************
	static FS_BOOL  FindFirst(FR_FormTextFind formTextFind, FS_LPCWSTR findwhat, FS_INT32 flags);

	//************************************
	// Function:  FindNext
	// Param[in]: formTextFind	  The input FR_FormTextFind.
	// Return: FS_BOOL            TRUE : Find success.	
	// Remarks:   Find next form text.
	// Notes:
	// See:
	//************************************
	static FS_BOOL  FindNext(FR_FormTextFind formTextFind);

	//************************************
	// Function:  FindPrev
	// Param[in]: formTextFind	  The input FR_FormTextFind.
	// Return: FS_BOOL            TRUE : Find success.	
	// Remarks:   Find pre form text.
	// Notes:
	// See:
	//************************************
	static FS_BOOL FindPrev(FR_FormTextFind formTextFind);

	//************************************
	// Function:  GetRectArray
	// Param[in]: formTextFind	  The input FR_FormTextFind.
	// Param[out]: rects	      Get the rect array of the find text.
	// Return: FS_BOOL            TRUE : Find success.	
	// Remarks:   Get the rect array of the find text.
	// Notes:
	// See:
	//************************************
	static void  GetRectArray(FR_FormTextFind formTextFind, FS_FloatRectArray* rects);
};

class CFR_PDFVerwerContentProviderEx_V16 // Internal use
{
public:
	//************************************
	// Function:  CreatePDFVerwerContentProviderEx
	// Param[in]: callback	The input FR_PDFVerwerContentProviderCallbacks.	
	// Return: FR_PDFVerwerContentProviderEx
	// Remarks:  Create FR_PDFVerwerContentProviderEx.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static FR_PDFVerwerContentProviderEx CreatePDFVerwerContentProviderEx(FR_PDFVerwerContentProviderCallbacks callback);

	//************************************
	// Function:  DeletePDFVerwerContentProviderEx
	// Param[in]: provider	The input FR_PDFVerwerContentProviderEx.	
	// Return: void
	// Remarks:  Delete FR_PDFVerwerContentProviderEx.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void DeletePDFVerwerContentProviderEx(FR_PDFVerwerContentProviderEx provider);
};

class CFR_PDFViewer_V16 //Internal use
{
public:
	//************************************
	// Function:  CreatePDFViewer
	// Param[in]: provider	    The input FR_PDFVerwerContentProviderEx.
	// Param[in]: nLayout	    The input layout mode, like FRD_LAYOUT_PREVIEW.	
	// Param[in]: bPreCalcPages	Whether need to calculate pages before.	
	// Param[in]: nPreCalcPagesLimit	The max of page count.	
	// Param[in]: dbScale	    The viewer scale.	
	// Return: FR_PDFViewer
	// Remarks:  Create FR_PDFViewer .
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static FR_PDFViewer CreatePDFViewer(FR_PDFVerwerContentProviderEx provider, FS_INT32 nLayout, FS_BOOLEAN bPreCalcPages, FS_INT32 nPreCalcPagesLimit, FS_FLOAT dbScale);
	
	//************************************
	// Function:  GetPageCount
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Return: FS_INT32
	// Remarks:  Get the page count of viewer.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static FS_INT32		GetPageCount(FR_PDFViewer pdfviewer);

	//************************************
	// Function:  GetPage
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: nIndex	    The input page index.
	// Return: FR_PDFViewerPage
	// Remarks:  Get the FR_PDFViewerPage.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static FR_PDFViewerPage GetPage(FR_PDFViewer pdfviewer, FS_INT32 nIndex);

	//************************************
	// Function:  GetCurrentPageIndex
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Return: FS_INT32
	// Remarks:  Get the current page index of viewer.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static FS_INT32		GetCurrentPageIndex(FR_PDFViewer pdfviewer);

	//************************************
	// Function:  GotoPage
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: iPage	        The page index need go to.
	// Return: void
	// Remarks:  Go to the specified page.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void			GotoPage(FR_PDFViewer pdfviewer, FS_INT32 iPage);

	//************************************
	// Function:  GotoPage2
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: dest	        The dest position need go to.
	// Return: void
	// Remarks:  Go to the specified destination.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void		    GotoPage2(FR_PDFViewer pdfviewer, FPD_Dest dest);

	//************************************
	// Function:  GotoPage3
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: iPage	        The specified page index.
	// Param[in]: fLeft	        Set the left margin of page viewer.
	// Param[in]: fTop          Set the top margin of page viewer.
	// Return: void
	// Remarks:  Go to the specified destination.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void			GotoPage3(FR_PDFViewer pdfviewer, FS_INT32 iPage, FS_FLOAT fLeft, FS_FLOAT fTop);

	//************************************
	// Function:  GetZoomScale
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Return: FS_FLOAT
	// Remarks:  Get the zoom scale.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static FS_FLOAT 	GetZoomScale(FR_PDFViewer pdfviewer);

	//************************************
	// Function:  ZoomtoPage
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: iZoomMode	    The input zoom mode, like FRD_ZMODE_FIT_WIDTH.
	// Param[in]: dbScale	    The input scale.
	// Param[in]: iFitW	        The fit width value.
	// Param[in]: iFitH	        The fit height value.
	// Param[in]: bCalcScaleFromMode	Whether need calculate scale from mode.
	// Return: void
	// Remarks: Zoom with specified property.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void			ZoomtoPage(FR_PDFViewer pdfviewer, FS_INT32 iZoomMode, FS_FLOAT dbScale, FS_INT32 iFitW, FS_INT32 iFitH, FS_BOOLEAN bCalcScaleFromMode);

	//************************************
	// Function:  SetPageRotate
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: iRotate	    The the page rotate.
	// Return: void
	// Remarks: Set page rotate.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void	        SetPageRotate(FR_PDFViewer pdfviewer, FS_INT32 iRotate);

	//************************************
	// Function:  GetPageRotate
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Return: FS_INT32
	// Remarks: Get page rotate.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static FS_INT32	    GetPageRotate(FR_PDFViewer pdfviewer);

	//************************************
	// Function:  SetSize
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: cx	        Set the width of the viewer.
	// Param[in]: cy	        Set the height of the viewer.
	// Return: void
	// Remarks: Set the size of the viewer.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void	SetSize(FR_PDFViewer pdfviewer, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  GetSize
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[out]: cx	        Get the width of the viewer.
	// Param[out]: cy	        Get the height of the viewer.
	// Return: void
	// Remarks: Get the size of the viewer.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void	GetSize(FR_PDFViewer pdfviewer, FS_INT32* cx, FS_INT32* cy);

	//************************************
	// Function:  GetRenderData
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: bProgressiveRender	        Get the width of the viewer.
	// Return: void
	// Remarks: Get the rendering bitmap.
	// Notes:
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_DIBitmap	GetRenderData(FR_PDFViewer pdfviewer, FS_BOOLEAN bProgressiveRender);

	//************************************
	// Function:  SetDisplayAnnot
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: bShow	        Whether show annot.
	// Return: void
	// Remarks: Set if show annots.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void			SetDisplayAnnot(FR_PDFViewer pdfviewer, FS_BOOL bShow);

	//************************************
	// Function:  GetCanvasWidth
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Return: FS_INT32
	// Remarks: Get the width of the current display.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static FS_INT32		GetCanvasWidth(FR_PDFViewer pdfviewer);

	//************************************
	// Function:  GetCanvasHeight
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Return: FS_INT32
	// Remarks: Get the height of the current display.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static FS_INT32		GetCanvasHeight(FR_PDFViewer pdfviewer);

	//************************************
	// Function:  GetScrollPosX
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Return: FS_INT32
	// Remarks: Get the scroll x position.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static	FS_INT32		GetScrollPosX(FR_PDFViewer pdfviewer);

	//************************************
	// Function:  GetScrollPosY
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Return: FS_INT32
	// Remarks: Get the scroll y position.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static	FS_INT32		GetScrollPosY(FR_PDFViewer pdfviewer);

	//************************************
	// Function:  Scroll
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: offsetX	    The offset of x axis.
	// Param[in]: offsetY	    The offset of y axis.
	// Param[in]: bOnlyInCurRow	If show in a row.
	// Return: void
	// Remarks: Scroll to specified position.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void	Scroll(FR_PDFViewer pdfviewer, FS_INT32 offsetX, FS_INT32 offsetY, FS_BOOLEAN bOnlyInCurRow);

	//************************************
	// Function:  GetBrowserMode
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Return: FS_INT32
	// Remarks: Get the browser mode.
	// Notes:
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32		GetBrowserMode(FR_PDFViewer pdfviewer);
	
	//************************************
	// Function:  ScrollToPosX
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: posX	        The input FR_PDFViewer.
	// Return: void
	// Remarks: Get the browser mode.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static	void			ScrollToPosX(FR_PDFViewer pdfviewer, FS_INT32 posX);

	//************************************
	// Function:  ScrollToPosY
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: posX	        The input scroll position y.
	// Param[in]: bNeedAdjust	If need adjust.
	// Param[in]: bOnlyInCurRow	If show in a row.
	// Return: void
	// Remarks: Scroll to specified y position.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static	void	ScrollToPosY(FR_PDFViewer pdfviewer, FS_INT32 posY, FS_BOOLEAN bNeedAdjust, FS_BOOLEAN bOnlyInCurRow);

	//************************************
	// Function:  ContinueRendering
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Return: FS_BOOLEAN
	// Remarks: If continue render.
	// Notes:
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN			ContinueRendering(FR_PDFViewer pdfviewer);

	//************************************
	// Function:  AddRecord
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Return: void
	// Remarks: Add record info.
	// Notes:
	// See:
	// Deprecated: Internal use.
	//************************************
	static void			AddRecord(FR_PDFViewer pdfviewer);

	//************************************
	// Function:  SetViewEventHandler
	// Param[in]: pdfviewer	    The input FR_PDFViewer.
	// Param[in]: handler	    The input FR_IPDFViewerEventHandler.
	// Return: void
	// Remarks: Set view event handler to display the view.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void  SetViewEventHandler(FR_PDFViewer pdfviewer, FR_IPDFViewerEventHandler handler);

	//************************************
	// Function:  DeletePDFViewer
	// Param[in]: viewer	    The input FR_PDFViewer.
	// Return: void
	// Remarks: Release pdf viewer.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static void  DeletePDFViewer(FR_PDFViewer pdfviewer);
};

class CFR_PDFViewerPage_V16 //Internal use.
{
public:
	//************************************
	// Function:  GetPageRect
	// Param[in]: viewerPage	The input FR_PDFViewerPage.
	// Param[in]: bRecalc	    If need recalculate.	
	// Return: FS_Rect
	// Remarks:  Get the page rect.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static	FS_Rect	GetPageRect(FR_PDFViewerPage viewerPage ,FS_BOOLEAN bRecalc);

	//************************************
	// Function:  IsVisible
	// Param[in]: viewerPage	The input FR_PDFViewerPage.
	// Return: FS_BOOLEAN
	// Remarks:  Get if the viewer page is visible.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static	FS_BOOLEAN	IsVisible(FR_PDFViewerPage viewerPage);

	//************************************
	// Function:  GetPageIndex
	// Param[in]: viewerPage	The input FR_PDFViewerPage.
	// Return: FS_INT32
	// Remarks:  Get the page index of the viewer page.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static	FS_INT32	GetPageIndex(FR_PDFViewerPage viewerPage);

	//************************************
	// Function:  GetPageFullRect
	// Param[in]: viewerPage	The input FR_PDFViewerPage.
	// Return: FS_Rect
	// Remarks:  Get the page full rect.
	// Notes:
	// See:
	// Deprecated: Internal use. 
	//************************************
	static	FS_Rect		GetPageFullRect(FR_PDFViewerPage viewerPage);
};

#ifdef __cplusplus
};
#endif
#endif//FR_VIEWIMPL_H

/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FR_VIEWCALLS_H
#define FR_VIEWCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_VIEWEXPT_H
#include "fr_viewExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fr_viewImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fr_viewTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fr_viewImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fr_viewTempl.h"

//----------_V1----------
//*****************************
/* DocView HFT functions */
//*****************************

#define FRDocViewGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetDocumentSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetDocumentSEL, _gPID)))

#define FRDocViewCountPageViews (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewCountPageViewsSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewCountPageViewsSEL, _gPID)))

#define FRDocViewGetPageView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetPageViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetPageViewSEL, _gPID)))

#define FRDocViewGetPageViewAtPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetPageViewAtPointSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetPageViewAtPointSEL, _gPID)))

#define FRDocViewCountVisiblePageViews (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewCountVisiblePageViewsSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewCountVisiblePageViewsSEL, _gPID)))

#define FRDocViewGetVisiblePageView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetVisiblePageViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetVisiblePageViewSEL, _gPID)))

#define FRDocViewGotoPageView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGotoPageViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGotoPageViewSEL, _gPID)))

#define FRDocViewGotoPageViewByPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGotoPageViewByPointSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGotoPageViewByPointSEL, _gPID)))

#define FRDocViewGotoPageViewByRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGotoPageViewByRectSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGotoPageViewByRectSEL, _gPID)))

#define FRDocViewGetCurrentPageView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetCurrentPageViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetCurrentPageViewSEL, _gPID)))

#define FRDocViewGetRotation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetRotationSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetRotationSEL, _gPID)))

#define FRDocViewSetRotation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewSetRotationSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewSetRotationSEL, _gPID)))

#define FRDocViewGetLayoutMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetLayoutModeSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetLayoutModeSEL, _gPID)))

#define FRDocViewSetLayoutMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewSetLayoutModeSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewSetLayoutModeSEL, _gPID)))

#define FRDocViewGetZoom (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetZoomSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetZoomSEL, _gPID)))

#define FRDocViewGetZoomType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetZoomTypeSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetZoomTypeSEL, _gPID)))

#define FRDocViewZoomTo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewZoomToSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewZoomToSEL, _gPID)))

#define FRDocViewGoBack (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGoBackSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGoBackSEL, _gPID)))

#define FRDocViewGoForward (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGoForwardSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGoForwardSEL, _gPID)))

#define FRDocViewShowAnnots (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewShowAnnotsSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewShowAnnotsSEL, _gPID)))

#define FRDocViewProcAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewProcActionSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewProcActionSEL, _gPID)))

#define FRDocViewScrollTo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewScrollToSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewScrollToSEL, _gPID)))

#define FRDocViewGetMaxScrollingSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetMaxScrollingSizeSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetMaxScrollingSizeSEL, _gPID)))

#define FRDocViewDrawNow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewDrawNowSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewDrawNowSEL, _gPID)))

#define FRDocViewInvalidateRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewInvalidateRectSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewInvalidateRectSEL, _gPID)))

#define FRDocViewDrawRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewDrawRectSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewDrawRectSEL, _gPID)))

#define FRDocViewDoPopUpMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewDoPopUpMenuSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewDoPopUpMenuSEL, _gPID)))

#define FRDocViewGetMachinePort (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetMachinePortSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetMachinePortSEL, _gPID)))

#define FRDocViewReleaseMachinePort (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewReleaseMachinePortSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewReleaseMachinePortSEL, _gPID)))

#define FRDocViewGetOCContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetOCContextSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetOCContextSEL, _gPID)))

#define FRDocViewGetCurrentSnapshot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetCurrentSnapshotSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetCurrentSnapshotSEL, _gPID)))

#define FRDocViewGetThumbnailView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetThumbnailViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetThumbnailViewSEL, _gPID)))

#define FRDocViewMovePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewMovePageSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewMovePageSEL, _gPID)))

#define FRDocViewIsValidPageView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewIsValidPageViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewIsValidPageViewSEL, _gPID)))

#define FRDocViewGetTagDocViewText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetTagDocViewTextSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetTagDocViewTextSEL, _gPID)))

#define FRDocViewGetLRDocViewText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetLRDocViewTextSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetLRDocViewTextSEL, _gPID)))

#define FRDocViewGetWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetWndSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetWndSEL, _gPID)))

#define FRDocViewScrollToCenterPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewScrollToCenterPointSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewScrollToCenterPointSEL, _gPID)))

#define FRDocViewSetRenderDataChange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewSetRenderDataChangeSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewSetRenderDataChangeSEL, _gPID)))

#define FRDocViewGotoPageViewByAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGotoPageViewByAnnotSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGotoPageViewByAnnotSEL, _gPID)))

#define FRDocViewGotoPageByDest (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGotoPageByDestSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGotoPageByDestSEL, _gPID)))

#define FRDocViewGetHwnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetHwndSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetHwndSEL, _gPID)))

#define FRDocViewGotoPageViewByRect2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGotoPageViewByRect2SELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGotoPageViewByRect2SEL, _gPID)))

//*****************************
/* PageView HFT functions */
//*****************************

#define FRPageViewGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetDocumentSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetDocumentSEL, _gPID)))

#define FRPageViewGetDocView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetDocViewSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetDocViewSEL, _gPID)))

#define FRPageViewGetPDPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPDPageSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPDPageSEL, _gPID)))

#define FRPageViewGetPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPageIndexSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPageIndexSEL, _gPID)))

#define FRPageViewCountAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewCountAnnotSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewCountAnnotSEL, _gPID)))

#define FRPageViewGetCurrentMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetCurrentMatrixSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetCurrentMatrixSEL, _gPID)))

#define FRPageViewDevicePointToPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDevicePointToPageSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDevicePointToPageSEL, _gPID)))

#define FRPageViewDeviceRectToPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDeviceRectToPageSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDeviceRectToPageSEL, _gPID)))

#define FRPageViewPointToDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewPointToDeviceSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewPointToDeviceSEL, _gPID)))

#define FRPageViewRectToDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewRectToDeviceSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewRectToDeviceSEL, _gPID)))

#define FRPageViewIsVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewIsVisibleSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewIsVisibleSEL, _gPID)))

#define FRPageViewGetPageRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPageRectSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPageRectSEL, _gPID)))

#define FRPageViewGetPageVisibleRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPageVisibleRectSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPageVisibleRectSEL, _gPID)))

#define FRPageViewDidContentChanged (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDidContentChangedSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDidContentChangedSEL, _gPID)))

#define FRPageViewGetHWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetHWndSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetHWndSEL, _gPID)))

#define FRPageViewDidTextObjectChanged (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDidTextObjectChangedSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDidTextObjectChangedSEL, _gPID)))

#define FRPageViewGetAnnotByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetAnnotByIndexSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetAnnotByIndexSEL, _gPID)))

#define FRPageViewGetPageState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPageStateSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPageStateSEL, _gPID)))

#define FRPageViewDeleteAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDeleteAnnotSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDeleteAnnotSEL, _gPID)))

#define FRPageViewGetPageScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPageScaleSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPageScaleSEL, _gPID)))

#define FRPageViewGetAnnotAtPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetAnnotAtPointSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetAnnotAtPointSEL, _gPID)))

#define FRPageViewUpdateAllViews (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewUpdateAllViewsSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewUpdateAllViewsSEL, _gPID)))

#define FRPageViewAddAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewAddAnnotSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewAddAnnotSEL, _gPID)))

#define FRPageViewGetRenderOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetRenderOptionsSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetRenderOptionsSEL, _gPID)))

#define FRPageViewDidContentChanged2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDidContentChanged2SELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDidContentChanged2SEL, _gPID)))

#define FRPageViewDidContentChanged3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDidContentChanged3SELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDidContentChanged3SEL, _gPID)))

#define FRPageViewSetContentModification (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewSetContentModificationSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewSetContentModificationSEL, _gPID)))

#define FRPageViewGenerateContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGenerateContentSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGenerateContentSEL, _gPID)))

#define FRPageViewUpdateAllViewsRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewUpdateAllViewsRectSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewUpdateAllViewsRectSEL, _gPID)))

#define FRPageViewCountViews (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewCountViewsSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewCountViewsSEL, _gPID)))

#define FRPageViewIsValidAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewIsValidAnnotSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewIsValidAnnotSEL, _gPID)))

#define FRPageViewAnnot_OnHitTest (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewAnnot_OnHitTestSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewAnnot_OnHitTestSEL, _gPID)))

#define FRPageViewPostFormFilerMessageText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewPostFormFilerMessageTextSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewPostFormFilerMessageTextSEL, _gPID)))

//*****************************
/* TextSelectTool HFT functions */
//*****************************

#define FRTextSelectToolCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolCreateSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolCreateSEL, _gPID)))

#define FRTextSelectToolGetSelectedText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolGetSelectedTextSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolGetSelectedTextSEL, _gPID)))

#define FRTextSelectToolDrawSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolDrawSelectionSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolDrawSelectionSEL, _gPID)))

#define FRTextSelectToolClearSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolClearSelectionSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolClearSelectionSEL, _gPID)))

#define FRTextSelectToolEnumTextObjectRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolEnumTextObjectRectSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolEnumTextObjectRectSEL, _gPID)))

#define FRTextSelectToolAddSelect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolAddSelectSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolAddSelectSEL, _gPID)))

#define FRTextSelectToolSelect_GetPageRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolSelect_GetPageRangeSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolSelect_GetPageRangeSEL, _gPID)))

#define FRTextSelectToolGetSelectedText2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolGetSelectedText2SELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolGetSelectedText2SEL, _gPID)))

#define FRTextSelectToolGetSelectedTextInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolGetSelectedTextInfoSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolGetSelectedTextInfoSEL, _gPID)))

#define FRTextSelectToolReleaseSelectedInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolReleaseSelectedInfoSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolReleaseSelectedInfoSEL, _gPID)))

#define FRTextSelectToolIsSelected (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolIsSelectedSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolIsSelectedSEL, _gPID)))

#define FRTextSelectToolIsPageSelectAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolIsPageSelectAllSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolIsPageSelectAllSEL, _gPID)))

#define FRTextSelectToolGetSelectedData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolGetSelectedDataSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolGetSelectedDataSEL, _gPID)))

#define FRTextSelectToolAddSelect2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolAddSelect2SELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolAddSelect2SEL, _gPID)))

#define FRTextSelectToolAddSelectTextRects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolAddSelectTextRectsSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolAddSelectTextRectsSEL, _gPID)))

#define FRTextSelectToolGetSelectPDFRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolGetSelectPDFRectSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolGetSelectPDFRectSEL, _gPID)))

#define FRTextSelectToolDeselectAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolDeselectAllSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolDeselectAllSEL, _gPID)))

//----------_V2----------
//----------_V3----------
//*****************************
/* ThumbnailView HFT functions */
//*****************************

#define FRThumbnailViewCountPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRThumbnailViewCountPageSELPROTO)FRCOREROUTINE(FRThumbnailViewSEL,FRThumbnailViewCountPageSEL, _gPID)))

#define FRThumbnailViewCountVisiblePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRThumbnailViewCountVisiblePageSELPROTO)FRCOREROUTINE(FRThumbnailViewSEL,FRThumbnailViewCountVisiblePageSEL, _gPID)))

#define FRThumbnailViewGetPageRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRThumbnailViewGetPageRectSELPROTO)FRCOREROUTINE(FRThumbnailViewSEL,FRThumbnailViewGetPageRectSEL, _gPID)))

#define FRThumbnailViewGetVisiblePageRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRThumbnailViewGetVisiblePageRangeSELPROTO)FRCOREROUTINE(FRThumbnailViewSEL,FRThumbnailViewGetVisiblePageRangeSEL, _gPID)))

#define FRThumbnailViewGetPDPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRThumbnailViewGetPDPageSELPROTO)FRCOREROUTINE(FRThumbnailViewSEL,FRThumbnailViewGetPDPageSEL, _gPID)))

//----------_V4----------
//----------_V5----------
//*****************************
/* Annot HFT functions */
//*****************************

#define FRAnnotGetPDFAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetPDFAnnotSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetPDFAnnotSEL, _gPID)))

#define FRAnnotGetType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetTypeSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetTypeSEL, _gPID)))

#define FRAnnotGetSubType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetSubTypeSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetSubTypeSEL, _gPID)))

#define FRAnnotSetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotSetVisibleSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotSetVisibleSEL, _gPID)))

#define FRAnnotGetPageVew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetPageVewSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetPageVewSEL, _gPID)))

#define FRAnnotGetTabOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetTabOrderSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetTabOrderSEL, _gPID)))

#define FRAnnotSetFlags (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotSetFlagsSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotSetFlagsSEL, _gPID)))

#define FRAnnotIsSelected (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotIsSelectedSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotIsSelectedSEL, _gPID)))

#define FRAnnotSetAuthor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotSetAuthorSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotSetAuthorSEL, _gPID)))

#define FRAnnotGetFRDocByAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetFRDocByAnnotSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetFRDocByAnnotSEL, _gPID)))

#define FRAnnotGetXFAWidget (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetXFAWidgetSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetXFAWidgetSEL, _gPID)))

#define FRAnnotGetCBFWidget (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetCBFWidgetSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetCBFWidgetSEL, _gPID)))

#define FRAnnotGetBorderWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetBorderWidthSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetBorderWidthSEL, _gPID)))

#define FRAnnotGetBorderStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetBorderStyleSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetBorderStyleSEL, _gPID)))

#define FRAnnotSetBorderWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotSetBorderWidthSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotSetBorderWidthSEL, _gPID)))

#define FRAnnotSetBorderStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotSetBorderStyleSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotSetBorderStyleSEL, _gPID)))

#define FRAnnotIsSameTabOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotIsSameTabOrderSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotIsSameTabOrderSEL, _gPID)))

#define FRAnnotNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotNewSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotNewSEL, _gPID)))

#define FRAnnotDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotDeleteSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotDeleteSEL, _gPID)))

//*****************************
/* ResourcePropertyBox HFT functions */
//*****************************

//----------_V6----------
//*****************************
/* ScrollBarThumbnailView HFT functions */
//*****************************

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

#define FRRedactionApplyDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRedactionApplyDocSELPROTO)FRCOREROUTINE(FRRedactionSEL,FRRedactionApplyDocSEL, _gPID)))

#define FRRedactionApply (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRedactionApplySELPROTO)FRCOREROUTINE(FRRedactionSEL,FRRedactionApplySEL, _gPID)))

#define FRRedactionApplyDoc2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRedactionApplyDoc2SELPROTO)FRCOREROUTINE(FRRedactionSEL,FRRedactionApplyDoc2SEL, _gPID)))

//*****************************
/* Reader HFT functions */
//*****************************

//*****************************
/* IReaderDispViewerHandler HFT functions */
//*****************************

//*****************************
/* IPDFViewerEventHandler HFT functions */
//*****************************

//*****************************
/* ToolFormatMgr HFT functions */
//*****************************

#define FRToolFormatMgrGet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolFormatMgrGetSELPROTO)FRCOREROUTINE(FRToolFormatMgrSEL,FRToolFormatMgrGetSEL, _gPID)))

#define FRToolFormatMgrRegistFormatEvent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolFormatMgrRegistFormatEventSELPROTO)FRCOREROUTINE(FRToolFormatMgrSEL,FRToolFormatMgrRegistFormatEventSEL, _gPID)))

#define FRToolFormatMgrUnregisterFormatEvent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolFormatMgrUnregisterFormatEventSELPROTO)FRCOREROUTINE(FRToolFormatMgrSEL,FRToolFormatMgrUnregisterFormatEventSEL, _gPID)))

#define FRToolFormatMgrAddGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolFormatMgrAddGroupSELPROTO)FRCOREROUTINE(FRToolFormatMgrSEL,FRToolFormatMgrAddGroupSEL, _gPID)))

#define FRToolFormatMgrAddGroupToFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolFormatMgrAddGroupToFormatSELPROTO)FRCOREROUTINE(FRToolFormatMgrSEL,FRToolFormatMgrAddGroupToFormatSEL, _gPID)))

#define FRToolFormatMgrShowToolFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolFormatMgrShowToolFormatSELPROTO)FRCOREROUTINE(FRToolFormatMgrSEL,FRToolFormatMgrShowToolFormatSEL, _gPID)))

#define FRToolFormatMgrIsToolFormatExist (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolFormatMgrIsToolFormatExistSELPROTO)FRCOREROUTINE(FRToolFormatMgrSEL,FRToolFormatMgrIsToolFormatExistSEL, _gPID)))

#define FRToolFormatMgrGetFormatGroups (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolFormatMgrGetFormatGroupsSELPROTO)FRCOREROUTINE(FRToolFormatMgrSEL,FRToolFormatMgrGetFormatGroupsSEL, _gPID)))

#define FRToolFormatMgrUpdateFormatStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolFormatMgrUpdateFormatStatusSELPROTO)FRCOREROUTINE(FRToolFormatMgrSEL,FRToolFormatMgrUpdateFormatStatusSEL, _gPID)))

#define FRToolFormatMgrShowToolFormat2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolFormatMgrShowToolFormat2SELPROTO)FRCOREROUTINE(FRToolFormatMgrSEL,FRToolFormatMgrShowToolFormat2SEL, _gPID)))

//*****************************
/* TextSelectedData HFT functions */
//*****************************

#define FRTextSelectedDataNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectedDataNewSELPROTO)FRCOREROUTINE(FRTextSelectedDataSEL,FRTextSelectedDataNewSEL, _gPID)))

#define FRTextSelectedDataDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectedDataDestroySELPROTO)FRCOREROUTINE(FRTextSelectedDataSEL,FRTextSelectedDataDestroySEL, _gPID)))

#define FRTextSelectedDataGetSelectedPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectedDataGetSelectedPagesSELPROTO)FRCOREROUTINE(FRTextSelectedDataSEL,FRTextSelectedDataGetSelectedPagesSEL, _gPID)))

#define FRTextSelectedDataGetSelectedDataCountByPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectedDataGetSelectedDataCountByPageIndexSELPROTO)FRCOREROUTINE(FRTextSelectedDataSEL,FRTextSelectedDataGetSelectedDataCountByPageIndexSEL, _gPID)))

#define FRTextSelectedDataGetSelectedDatas (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectedDataGetSelectedDatasSELPROTO)FRCOREROUTINE(FRTextSelectedDataSEL,FRTextSelectedDataGetSelectedDatasSEL, _gPID)))

//*****************************
/* IRPPropertySource HFT functions */
//*****************************

//*****************************
/* LayerOperation HFT functions */
//*****************************

//----------_V15----------
//*****************************
/* FormTextFind HFT functions */
//*****************************

#define FRFormTextFindCreateFormTextFind (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormTextFindCreateFormTextFindSELPROTO)FRCOREROUTINE(FRFormTextFindSEL,FRFormTextFindCreateFormTextFindSEL, _gPID)))

#define FRFormTextFindDeleteFormTextFind (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormTextFindDeleteFormTextFindSELPROTO)FRCOREROUTINE(FRFormTextFindSEL,FRFormTextFindDeleteFormTextFindSEL, _gPID)))

#define FRFormTextFindFindFirst (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormTextFindFindFirstSELPROTO)FRCOREROUTINE(FRFormTextFindSEL,FRFormTextFindFindFirstSEL, _gPID)))

#define FRFormTextFindFindNext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormTextFindFindNextSELPROTO)FRCOREROUTINE(FRFormTextFindSEL,FRFormTextFindFindNextSEL, _gPID)))

#define FRFormTextFindFindPrev (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormTextFindFindPrevSELPROTO)FRCOREROUTINE(FRFormTextFindSEL,FRFormTextFindFindPrevSEL, _gPID)))

#define FRFormTextFindGetRectArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormTextFindGetRectArraySELPROTO)FRCOREROUTINE(FRFormTextFindSEL,FRFormTextFindGetRectArraySEL, _gPID)))

//----------_V16----------
//*****************************
/* PDFVerwerContentProviderEx HFT functions */
//*****************************

//*****************************
/* PDFViewer HFT functions */
//*****************************

//*****************************
/* PDFViewerPage HFT functions */
//*****************************

//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
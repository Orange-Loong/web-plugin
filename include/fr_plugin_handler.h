#ifndef FRD_PLUGINEVENTHANDLER_H
#define FRD_PLUGINEVENTHANDLER_H
#include "InternalSDK/include/fr_sdk.h"
#include "PluginSDK/include/frd/fr_appExpT.h"
#include "fr_plugin_tools.h"
//////////////////////////////////////////////////////////////////////////
class IFR_PanelPage;
class CFR_PanelPage;
class CFR_PanelPageMgr;

class IPlugin_EventHandler
{
public:
	virtual ~IPlugin_EventHandler() {}
public:
	virtual void PluginWillUnLoaded(LPCWSTR lpszPluginName) {}
};


class CPlugin_PanelView : public IReader_PanelView {
public:
  CPlugin_PanelView(HWND hWnd, IFR_PanelPage *pPage);
  ~CPlugin_PanelView() {}

public:
  BOOL AddItem() override; // Like Add Bookmark.

  // Quickly page locate
  FX_BOOL SetPos(int nPage) override;

  // Accurately destination locate
  FX_BOOL SetPos(int nPage, PAGESTATE PageState) override;

  HWND GetHwnd() override;

  void OnPanelActive() override;

  BOOL GetBDockBottom();

  virtual void RotateView(int nRotate) override;

protected:
  IFR_PanelPage *m_pPanelPage;
  HWND m_hWnd;
};

//////////////////////////////////////////////////////////////////////////
class IFR_PanelPage {
public:
  virtual ~IFR_PanelPage(){};
  virtual CFX_ByteString GetName() = 0;
  virtual CFX_WideString GetTitle() = 0;
  virtual IReader_PanelView *InitNewView(CPDF_Document *pPDFDoc, HWND hParent) = 0;
  virtual HWND OnPanelActive() = 0;
  virtual void OnActive(CPDF_Document *pDocument, HWND hOwner) = 0;
  virtual void OnRotate(CPDF_Document *pPDFDoc, int nRotate) = 0;
  virtual void OnDestroyWnd(IReader_Document *pDoc) = 0;
  virtual FX_BOOL IsDockToBottom() = 0;
  virtual CFX_WideString GetButtonTip() = 0;
  virtual CFX_WideString GetButtonDscr() = 0;
  virtual CFX_DIBitmap *GetButtonIcon() = 0;
  virtual FX_BOOL SetPos(CPDF_Document *pPDFDoc, int nPage) = 0;
};

//////////////////////////////////////////////////////////////////////////
class CPlugin_PanelPage : public IFR_PanelPage {
public:
  CPlugin_PanelPage(FR_PanelViewCallbacks view);
  virtual ~CPlugin_PanelPage();

  CFX_ByteString GetName() override;
  CFX_WideString GetTitle() override;
  IReader_PanelView *InitNewView(CPDF_Document *pPDFDoc, HWND hParent) override;
  HWND OnPanelActive() override;
  void OnActive(CPDF_Document *pDocument, HWND hOwner) override;
  void OnRotate(CPDF_Document *pPDFDoc, int nRotate) override;
  void OnDestroyWnd(IReader_Document *pDoc) override;
  FX_BOOL IsDockToBottom() override;
  CFX_WideString GetButtonTip() override;
  CFX_WideString GetButtonDscr() override;
  CFX_DIBitmap *GetButtonIcon() override;
  FX_BOOL SetPos(CPDF_Document *pPDFDoc, int nPage) override;

private:
  FR_PanelViewCallbacks m_pPage;
  CFX_DIBitmap *m_pBtnBitmap;
  CPDF_Document *m_pDoc;
  HWND m_hOwner;
  std::unique_ptr<CPlugin_PanelView> m_pPanelView;
};

//////////////////////////////////////////////////////////////////////////
class CFR_PanelPageMgr {
public:
  CFR_PanelPageMgr() {}
  virtual ~CFR_PanelPageMgr() {}

  int CountPage() { return m_lsPage.size(); }
  IFR_PanelPage *GetPanelPage(int index) { return m_lsPage.at(index).get(); }
  void AddPanelPage(std::unique_ptr<IFR_PanelPage>&& pPage) { m_lsPage.push_back(std::move(pPage)); }

protected:
	std::vector<std::unique_ptr<IFR_PanelPage> > m_lsPage;
};

// for FRAppAddNavPanelView
class CFR_CustomPanelToolHandler;
class CFR_CustomerPanelView2 : public IReader_PanelView {
public:
  CFR_CustomerPanelView2(CFR_CustomPanelToolHandler *pPanelToolHandler);
  ~CFR_CustomerPanelView2();

public:
  virtual BOOL AddItem() { return FALSE; } // Like Add Bookmark.

  // Quickly page locate
  virtual FX_BOOL SetPos(int nPage);
  // Accurately destination locate
  virtual FX_BOOL SetPos(int nPage, PAGESTATE PageState);

  virtual HWND GetHwnd();

  virtual void OnPanelActive();
  virtual void OnPanelDeactive();
  virtual void OnShowPanel(BOOL bShow) {}
  virtual void OnChangeInpoutMode(BOOL bTouchMode) {}
  virtual FX_BOOL OnDropFiles(HDROP hDropInfo) { return FALSE; }

  virtual BOOL IsInitialDockBottom();
  virtual BOOL IsInitialShow();
  virtual void RotateView(int nRotate);
  virtual void SetReadDirection(CPDF_Document *pDoc, FX_INT32 nReadDirection) {}
  virtual void GetSelectPage(CFX_DWordArray &SelPageArray) {}

  virtual void  RefreshView();
  virtual void  getLayerPanelViewStatus2(CFX_PtrArray &ocgArr1, CFX_PtrArray &ocgArr2);
  virtual void  SetLayerPanelViewState(CPDF_Document* pDocument, CPDF_Dictionary* pDic);
  virtual bool  CheckLayerVisible(CPDF_Document* pDocument, CPDF_Dictionary* pDicn, bool &bFind);

  virtual BOOL  OnPanelTabKeyDown(BOOL bShift);
  virtual void	OnPanelEnterKeyDown();

  //////////////////////////////////////////////////////////////////////////
  void Init(HWND hParent, IReader_App *pApp);
  CPDF_Document *GetPDFDoc();
  void SetPDFDoc(CPDF_Document *pPDF) { m_pDoc = pPDF; };
  HWND GetParentHwnd();

public:
  IReader_App *m_pApp;
  CPDF_Document *m_pDoc;
  HWND m_hOwner;
  HWND m_hPanelView;
  CFR_CustomPanelToolHandler *m_pPanelToolHandler;
};

// for FRAppAddNavPanelView
class CFR_CustomPanelToolHandler : public IReader_PanelToolHandler {
public:
  CFR_CustomPanelToolHandler(IReader_App *pApp, FR_PanelViewCallbacks callback);
  ~CFR_CustomPanelToolHandler();

  virtual void Tool_OnInit(IReader_App *pApp);
  // Destory
  virtual void Tool_Destroy();

  // Get tool basic info. Note: all strings should be in host encoding
  virtual CFX_ByteString Tool_GetName();
  virtual CFX_WideString Tool_GetLabel();
  virtual CFX_WideString Tool_GetMenuItemLabel();
  virtual CFX_WideString Tool_GetToolTip();

  virtual BOOL Tool_IsShowInMenu();

  // View operation
  virtual IReader_PanelView *Tool_InitNewView(CPDF_Document *pDocument, HWND hOwner);
  virtual IReader_PanelView *Tool_GetView(CPDF_Document *pDocument, HWND hOwner);
  virtual void Tool_CloseView(CPDF_Document *pDocument, HWND hOwner);

  virtual void Tool_SetActiveView(CPDF_Document *pDocument, HWND hOwner);
  virtual IReader_PanelView *Tool_GetActiveView(CPDF_Document *pDocument);

  virtual void *Tool_GetPrivateData();

  // Get tool Icon
  virtual CFX_DIBitmap *Tool_GetIcon32();
  virtual CFX_DIBitmap *Tool_GetIcon();
  virtual CFX_DIBitmap *Tool_GetIcon16();
  virtual CFX_WideString Tool_GetPDFBitmapName();
  virtual CFX_WideString Tool_GetPDFBitmapName32();
  virtual CFX_WideString Tool_GetPDFBitmapName16();
  virtual CFX_WideString Tool_GetActivePDFBitmapName();

public:
  CPtrArray m_PanelViewArray;
  CFX_MapPtrToPtr m_FrmToActivePanelView;

  IReader_App *m_pApp;

  CFX_ByteString m_csName;
  CFX_WideString m_csTitle;
  CFX_WideString m_csTooltip;
  CFX_DIBitmap *m_oBitmap16;
  CFX_DIBitmap *m_oBitmap24;
  CFX_DIBitmap *m_oBitmap36;
  CFX_DIBitmap *m_oBitmap32;
  CFX_DIBitmap *m_oBitmap48;

  FR_PanelViewCallbacksRec *m_pCallbacks;
};

//////////////////////////////////////////////////////////////////////////
class CPlugin_ToolHandler : public IReader_ToolHandler {
public:
  CPlugin_ToolHandler(FR_ToolCallbacks pTool);
  virtual ~CPlugin_ToolHandler() {}

  void Tool_OnInit(IReader_App *pApp) override;
  void Tool_Destroy() override;
  CFX_ByteString Tool_GetName() override { return m_csName; }
  void Tool_OnActivate(FX_BOOL bPersistent) override;
  void Tool_OnDeactivate() override;
  FX_BOOL Tool_OnKeyDown(UINT nKeyCode, UINT nFlags) override;
  FX_BOOL Tool_OnKeyUp(UINT nKeyCode, UINT nFlags) override;
  FX_BOOL Tool_OnChar(UINT nKeyCode, UINT nFlags) override;
  void Tool_OnLeavePage(IReader_PageView *pPageView) override;
  FX_BOOL Tool_IsEnabled() override;
  FX_BOOL Tool_IsProcessing() override;
  FX_BOOL Tool_OnLButtonDown(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL Tool_OnLButtonUp(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL Tool_OnLButtonDblClk(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL Tool_OnMouseMove(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL Tool_OnRButtonDown(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL Tool_OnRButtonUp(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL Tool_OnRButtonDblClk(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL Tool_OnMouseWheel(IReader_PageView *pPageView, UINT nFlags, short zDelta, const CPoint &point) override;
  FX_BOOL Tool_OnMouseHover(IReader_PageView *pPageView, const CPoint &point) override;
  FX_BOOL Tool_OnDraw(IReader_DocView *pDocView, HDC hDC, CFX_RenderDevice *pDevice, DWORD dwFlags) override;
  IReader_SelectionHandler *Tool_GetSelectionHandler() override;
  IReader_MousePtHandler *Tool_GetMousePtHandler() override;
  FX_BOOL Tool_IsWndCaptureing() override;
  void    Tool_OnEscape();
  FX_BOOL Tool_OnInkPressure(IReader_PageView* pPageView, CPoint point, int pressure, int nFlag, BOOL bErase) override;
  FX_BOOL Tool_OnInkNoPressure(IReader_PageView* pPageView, UINT nFlags, const CPoint& point, BOOL bErase, int btnState) override;
  void	  Tool_CursorInRange(BOOL bErase = FALSE) override;
  void	  Tool_CursorOutOfRange() override;
  FX_BOOL Tool_IsPSIProcessing() override;
  FX_BOOL Tool_IsNeedPSIMessage() override;

  void SetName(const CFX_ByteString &csName) { m_csName = csName; }
  void SetAssociatedMousePtHandlerType(const CFX_ByteString &csType) { m_csMousePtHandlerType = csType; }
  void SetAssociatedSelectionHandlerType(const CFX_ByteString &csType) { m_csSelectionHandlerType = csType; }

  void *GetClientData() { return m_Tool.clientData; }

private:
  FR_ToolCallbacksRec m_Tool = {};
  CFX_ByteString m_csName;
  CFX_ByteString m_csMousePtHandlerType;
  CFX_ByteString m_csSelectionHandlerType;
};

//////////////////////////////////////////////////////////////////////////
class CPlugin_SelectionHandler : public IReader_SelectionHandler {
public:
  CPlugin_SelectionHandler(FR_SelectionCallbacks callbacks);

  CFX_ByteString GetType() override;

  FX_BOOL CanSelectAll(IReader_Document *pDocument, void *curSelectData) override;
  void DoSelectAll(IReader_Document *pDocument, void *curSelectData) override;

  FX_BOOL CanDelete(IReader_Document *pDocument, void *curSelectData) override;
  void DoDelete(IReader_Document *pDocument, void *curSelectData) override;
  FX_BOOL CanCopy(IReader_Document *pDocument, void *curSelectData) override;
  void DoCopy(IReader_Document *pDocument, void *curSelectData) override;

  FX_BOOL CanCut(IReader_Document *pDocument, void *curSelectData) override;
  void DoCut(IReader_Document *pDocument, void *curSelectData) override;

  FX_BOOL CanPaste(IReader_Document *pDocument) override;
  void DoPaste(IReader_Document *pDocument) override;
  /************************************************************************/
  /*   可以在这两个函数中作高亮和非高亮的操作                             */
  /************************************************************************/

  void LosingSelection(IReader_Document *pDocument, void *curSelectData, FX_BOOL bSave) override;
  void GettingSeletion(IReader_Document *pDocument, void *curSelectData) override;

  void *RemovedFromSelection(IReader_Document *pDocument, void *curSelectData, void *RemData) override;
  void *AddedToSelection(IReader_Document *pDocument, void *curSelectData, void *AddmData) override;

  void ShowSelection(IReader_Document *pDocument, void *curSelectData) override;

  FX_BOOL KeyDown(IReader_Document *pDocument, void *curSelectData, UINT nKeyCode, UINT nFlags) override;

  FX_BOOL KeyUp(IReader_Document *pDocument, void *curSelectData, UINT nKeyCode, UINT nFlags) override;

  FX_BOOL KeyChar(IReader_Document *pDocument, void *curSelectData, UINT nChar, UINT nFlags) override;

  FX_BOOL MouseWheel(IReader_PageView *pPageView, void *curSelectData, UINT nFlags, const CPoint &point) override;

  FX_BOOL CanDeselectAll(IReader_Document *pDocument, void *curSelectData) override;
  void    DoDeselectAll(IReader_Document *pDocument, void *curSelectData) override;
  FX_BOOL CanOtherPaste(IReader_Document* pDocument) override;
  void	  TwAonntLosingEdit(IReader_Document* pDocument, IReader_Annot* pAnnot) override;
  void	  DoPasteInPlace(IReader_Document* pDocument) override;
  FX_BOOL CanPasteInPlace(IReader_Document* pDocument) override;
  FX_BOOL CanOtherPasteInPlace(IReader_Document* pDocument) override;
  FX_BOOL PreKeyDown(IReader_Document* pDocument, void* curSelectData, UINT nVriKey) override;

private:
  void *GetClientData() { return m_callbacks.clientData; }
  FR_SelectionCallbacksRec m_callbacks = {};
};

//////////////////////////////////////////////////////////////////////////
class CPlugin_CaptureHandler : public IReader_CaptureHandler {
public:
  CPlugin_CaptureHandler(FR_CaptureCallbacks callbacks);
  ~CPlugin_CaptureHandler() {}
  /************************************************************************/
  /*  type 可以为   Annotation  Touchup等      */
  /************************************************************************/

  CFX_ByteString GetType() override;
  void LosingCapture(IReader_Document *pDocument, void *curCaptureData) override;
  void GettingCapture(IReader_Document *pDocument, void *curCaptureData) override;
  FX_BOOL LButtonDown(IReader_PageView *pPageView, void *curCaptureData, UINT nFlags, const CPoint &point) override;
  FX_BOOL LButtonUp(IReader_PageView *pPageView, void *curCaptureData, UINT nFlags, const CPoint &point) override;
  FX_BOOL LButtonDblClk(IReader_PageView *pPageView, void *curCaptureData, UINT nFlags, const CPoint &point) override;
  FX_BOOL MouseMove(IReader_PageView *pPageView, void *curCaptureData, UINT nFlags, const CPoint &point) override;
  FX_BOOL RButtonDown(IReader_PageView *pPageView, void *curCaptureData, UINT nFlags, const CPoint &point) override;
  FX_BOOL RButtonUp(IReader_PageView *pPageView, void *curCaptureData, UINT nFlags, const CPoint &point) override;
  FX_BOOL RButtonDblClk(IReader_PageView *pPageView, void *curCaptureData, UINT nFlags, const CPoint &point) override;
  FX_BOOL CaptureContextMenu(IReader_PageView *pPageView, const CPoint &point);

private:
  void *GetClientData() { return m_callbacks.clientData; }
  FR_CaptureCallbacksRec m_callbacks = {};
};

class CReader_CustomerMousePtHandler : public IReader_MousePtHandler {
public:
  CReader_CustomerMousePtHandler(FR_MousePtCallbacks callbacks);
  ~CReader_CustomerMousePtHandler() {}

  /************************************************************************/
  /* 可以是多种MousePtHandler的容器                                                                          */
  /************************************************************************/
  CFX_ByteString GetType() override;

  void *GetObjectAtPoint(IReader_PageView *pPageView, CPoint point,
                         CycleThroughContext *pCycleThroughContext = nullptr) override;

  FX_BOOL LButtonDown(IReader_PageView *pPageView, void *curData, UINT nFlags, const CPoint &point) override;

  FX_BOOL LButtonUp(IReader_PageView *pPageView, void *curData, UINT nFlags, const CPoint &point) override;

  FX_BOOL LButtonDblClk(IReader_PageView *pPageView, void *curData, UINT nFlags, const CPoint &point) override;

  FX_BOOL MouseMove(IReader_PageView *pPageView, void *curData, UINT nFlags, const CPoint &point) override;

  FX_BOOL RButtonDown(IReader_PageView *pPageView, void *curData, UINT nFlags, const CPoint &point) override;

  FX_BOOL RButtonUp(IReader_PageView *pPageView, void *curData, UINT nFlags, const CPoint &point) override;

  FX_BOOL RButtonDblClk(IReader_PageView *pPageView, void *curData, UINT nFlags, const CPoint &point) override;

  FX_BOOL MouseWheel(IReader_PageView *pPageView, void *curData, UINT nFlags, short zDelta,
                     const CPoint &point) override;

  void OnMouseEnter(IReader_PageView *pPageView, void *curData) override;

  void OnMouseExit(IReader_PageView *pPageView, void *curData) override;

private:
  void *GetClientData() { return m_callbacks.clientData; }
  FR_MousePtCallbacksRec m_callbacks = {};
};

class CPlugin_WndProvider : public IReader_WndProvider {
public:
  CPlugin_WndProvider(FR_WndProviderCallbacks callbacks);
  ~CPlugin_WndProvider();
  virtual void CreateViewWnd(IReader_Document *pDocment, HWND hParent);
  virtual CFX_ByteString GetProviderName() const;
  void OnHScroll(IReader_Document *pDocment, UINT nSBCode, UINT nPos, CScrollBar *pScrollBar);
  void OnVScroll(IReader_Document *pDocment, UINT nSBCode, UINT nPos, CScrollBar *pScrollBar);
  BOOL OnCmdMsg(IReader_Document *pDocment, UINT nID, int nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo);
  void MoveWindow(IReader_Document *pDocment, int x, int y, int nWidth, int nHeight, BOOL bRepaint = TRUE);
  BOOL OnSetCursor(IReader_Document *pDocment, CWnd *pWnd, UINT nHitTest, UINT message);
  void ZoomToPage(IReader_Document *pDocment, double dbScale, BOOL bUpdate = TRUE);
  void GotoPage(IReader_Document *pDocment, int nPageIndex);
  void ShowWindow(IReader_Document *pDocment, BOOL bShow);
  void ReInitScrollBar(IReader_Document *pDocment);
  int GetPageIndex(IReader_Document *pDocment);
  void InitScrollBar(IReader_Document *pDocment, CScrollBar *pHScroll, CScrollBar *pVScroll);
  void OnSetFocus(IReader_Document *pDocment, CWnd *pOldWnd);
  BOOL OnMouseWheel(IReader_Document *pDocment, UINT nFlags, short zDelta, CPoint pt);

protected:
  FR_WndProviderCallbacksRec m_Callbacks = {};
};

class CReader_CustomPluginActionHandler : public IReader_PluginActionHandler {
public:
  CReader_CustomPluginActionHandler(FR_ActionHandlerCallbacks callbacks);
  virtual ~CReader_CustomPluginActionHandler();

public:
  virtual FX_BOOL DoAction_DocOpen(const CPDF_Action &action, IReader_Document *pDocument, IReader_DocView *pDocView,
                                   FX_BOOL bDisableGoto = FALSE);

  virtual FX_BOOL DoAction_JavaScript(const CPDF_Action &JsAction, CFX_WideString csJSName, IReader_Document *pDocument,
                                      IReader_DocView *pDocView);

  virtual FX_BOOL DoAction_Page(const CPDF_Action &action, CPDF_AAction::AActionType type, IReader_Document *pDocument,
                                IReader_DocView *pDocView);

  virtual FX_BOOL DoAction_Link(const CPDF_Action &action, IReader_Document *pDocument, IReader_DocView *pDocView);

protected:
  FR_ActionHandlerCallbacksRec m_Callbacks = {};
};

class CPlugin_POEventHandler : public IReader_POEventHandler // Page organize Event
{
public:
  CPlugin_POEventHandler(FR_POEventCallbacks callbacks);
  virtual ~CPlugin_POEventHandler();

public:
  void OnBeforeInsertPages(IReader_Document *pDoc, int nInsertAt, int nCount) override;

  void OnDoInsertPagesDictFinish(CPDF_Document *pDestDoc, int nInsertAt, CPDF_Document *pSrcDoc,
                                 const CFX_WordArray &arrSrcPages, FX_BOOL bEntireDoc = FALSE) override;

  void OnAfterInsertPages(IReader_Document *pDoc, int nInsertAt, int nCount) override;

  void OnBeforeDeletePages(IReader_Document *pDoc, const CFX_WordArray &arrDelPages) override;

  void OnAfterDeletePages(IReader_Document *pDoc, const CFX_WordArray &arrDelPages) override;

  void OnBeforeReplacePages(IReader_Document *pDoc, int nStart, const CPDF_Document *pSrcDoc,
                            const CFX_WordArray &arrSrcPages) override;

  void OnAfterReplacePages(IReader_Document *pDoc, int nStart, const CPDF_Document *pSrcDoc,
                           const CFX_WordArray &arrSrcPages) override;

  void OnBeforeSwapTwoPage(IReader_Document *pDoc, int iPage1, int iPage2) override;

  void OnAfterSwapTwoPage(IReader_Document *pDoc, int iPage1, int iPage2) override;

  void OnBeforeRotatePage(IReader_Document *pDoc, int iPage, int nRotate) override;

  void OnAfterRotatePage(IReader_Document *pDoc, int iPage, int nRotate) override;

  void OnBeforeResizePage(IReader_Document *pDoc, int iPage, const CPDF_Rect *pMediaBox,
                          const CPDF_Rect *pCropBox) override;

  void OnAfterResizePage(IReader_Document *pDoc, int iPage, const CPDF_Rect *pMediaBox,
                         const CPDF_Rect *pCropBox) override;

  void OnBeforeExtractPage(IReader_Document *pDoc, const CFX_WordArray &arrSrcPages, CPDF_Document *pDstDoc) override;

  void OnAfterExtractPage(IReader_Document *pDoc, const CFX_WordArray &arrSrcPages, CPDF_Document *pDstDoc) override;

  void OnAfterExtractPagesEx(IReader_Document *pDoc, const CFX_WordArray &arrSrcPages, const CFX_WideString &wsDestfilepath) override;

  void OnBeforeModifyPageAttr(IReader_Document *pDoc, int nStart, int nCount) override;

  void OnAfterModifyPageAttr(IReader_Document *pDoc, int nStart, int nCount) override;

  void OnBeforeMovePages(IReader_Document *pDoc, int nMoveTo, const CFX_WordArray *pArrToMove) override;

  void OnAfterMovePages(IReader_Document *pDoc, int nMoveTo, const CFX_WordArray *pArrToMove) override;

  void Release();

  void	OnBeforeReversePages(IReader_Document *pDoc, const CFX_ArrayTemplate<ReversePageOrder>& pageOrder) override;
  void	OnAfterReversePages(IReader_Document *pDoc, const CFX_ArrayTemplate<ReversePageOrder>& pageOrder) override;

  void	OnBeforeRotatePages(IReader_Document *pDoc, const CFX_WordArray &arrDelPages, int nRotate) override;
  void	OnAfterRotatePages(IReader_Document *pDoc, const CFX_WordArray &arrDelPages, int nRotate) override;

protected:
  FR_POEventCallbacksRec m_Callbacks = {};
};

class CPlugin_PageEventHandler : public IReader_PageEventHandler {
  callback::Manager<FR_PageEventCallbacksRec> mgr_;

public:
  bool Register(FR_PageEventCallbacks callback);
  void OnPageOpen(IReader_PageView *pPageView) override;

  void OnPageClose(IReader_PageView *pPageView) override;

  void OnPageVisible(IReader_PageView *pPageView) override;

  void OnPageInvisible(IReader_PageView *pPageView) override;

  void OnPageContentChanged(IReader_PageView *pPageView, Array_ContentObj *pAryObj = NULL,
                            OperatorType::ContentObjOperatorType eOperatorType = OperatorType::None) override;

  void OnPageBeforeParse(IReader_Page *pReaderPage, FX_BOOL bPageVisable) override;

  //不要处理框架UI相关操作，绝对不能导致主视图重绘。
  void OnPageParseComplete(IReader_Page *pReaderPage, FX_BOOL bPageVisable) override;

  void Release() override { delete this; }

  void  OnPageAnnotWillLoad(IReader_Page *pReaderPage) override;
  void  OnPageAnnotDidLoad(IReader_Page *pReaderPage) override;
};

class CPlugin_DocProteryHandler : public IReader_DocPropertyHandler {
  FR_DocPropertypageCallbacksRec m_Callbacks = {};
public:
  CPlugin_DocProteryHandler(const FR_DocPropertypageCallbacksRec& callback);
  void OnDlgDocPropertyCreate(HWND hParent) override;
  void OnDlgDocPropertyDestroy() override;
  void OnDlgDocPropertySaveData() override;
};

class CPlugin_PreferenceHandler : public IReader_PreferenceHandler {
	FR_PreferPageCallbacksRec m_Callbacks = {};
public:
  CPlugin_PreferenceHandler(const FR_PreferPageCallbacksRec& callback);
  void OnDlgPreferGetTitle(CFX_WideString &wsTitle) override;
  void OnDlgPreferCreate(HWND hParent) override;
  void OnDlgPreferDestroy() override;
  void OnDlgPreferSaveData() override;
};

#if 0

class CPlugin_DocEventHandler : public IReader_DocEventHandler, IReader_DocViewEventHandler, IReader_POEventHandler {
  callback::Manager<FR_DocEventCallbacksRec> mgr_;

public:
  bool Register(FR_DocEventCallbacksRec *callback);

  // IReader_DocEventHandler
  void OnDocWillOpen(IReader_Document *pDoc, FX_LPCWSTR lpszPathName) override;
  void OnDocDidOpen(IReader_Document *pDoc) override;
  void OnDelayDocDidOpen(IReader_Document *pDoc) override;
  BOOL OnDocCanBeClose(IReader_Document *pDoc) override;
  void OnDocWillClose(IReader_Document *pDoc) override;
  void OnDocDidClose(IReader_Document *pDoc) override;
  // 暂时不实现这两个接口，转而放在CPlugin_Module中实现OnDocDidSave
  // void OnDocDidSave(IReader_Document *pDoc) override;
  // void OnDocDidSave2(IReader_Document *pDoc, FX_LPCWSTR lpwsFilePath)
  // override;
  BOOL OnDocPromptToSave(IReader_Document *pDoc, FX_BOOL &bCancel) override;
  void OnDocWillReOpen(IReader_Document *pDoc, FX_BOOL bMemDoc = FALSE) override;
  void OnDocReOpenFailed(FX_LPCWSTR lpwsFilePath) override;
  void OnDocDidReOpen(IReader_Document *pDoc, FX_BOOL bMemDoc = FALSE) override;
  void OnDocWillDeactivate(IReader_Document *pDoc) override;
  void OnDocWillActivate(IReader_Document *pDoc) override;
  void OnDocActivate(IReader_Document *pDoc, BOOL bMainfrmActivating) override;
  void OnDocDeactivate(IReader_Document *pDoc, BOOL bMainfrmActivating) override;
  void OnDocCollectActionData(IReader_Document *pDoc, FX_LPCWSTR wsOperatorType, FX_LPCWSTR wsOperator,
                              CFX_MapPtrToPtr *valueMap) override;
  void OnOtherDocActivate(CWnd *pActivateWnd, BOOL bMainfrmActivating) override;
  void OnOtherDocDeactivate() override;
  void OnOtherDocClose() override;
  void OnDidCopy(IReader_Document *pDoc) override;
  void OnWillPrint(IReader_Document *pDoc) override;
  void OnDidPrint(IReader_Document *pDoc) override;
  void OnDocChange(IReader_Document *pDoc) override;
  void OnDocPermChange(IReader_Document *pDoc) override;
  void OnDocOptimizerFinish(IReader_Document *pDoc) override;
  void OnDocWillDraw(IReader_DocView *pDocView, HDC hdc) override;
  void OnDocDidDraw(IReader_DocView *pDocView, HDC hdc) override;
  void OnDocFinishRender(IReader_DocView *pDocView) override;
  void OnDocViewCreate(IReader_DocView *pDocView) override;
  void OnDocViewDestroy(IReader_DocView *pDocView) override;
  void OnDocFrameDestroy(IReader_Document *pDoc, HWND hFrameWnd) override;
  void OnDocFrameSize(IReader_Document *pDoc, HWND hFrameWnd, CRect rtClient) override;
  void OnAutoScrollBegin(IReader_DocView *pDocView) override;
  void OnAutoScrollEnd(IReader_DocView *pDocView) override;
  void OnAnnotSelectionChanged() override;
  void OnAnnotSetFocusEnd(IReader_Document *pDoc, IReader_Annot *pFocusAnnot) override;

  // IReader_DocViewEventHandler
  FX_BOOL OnKeyDown(IReader_DocView *pDocView, UINT nKeyCode, UINT nFlags) override;
  FX_BOOL OnKeyUp(IReader_DocView *pDocView, UINT nKeyCode, UINT nFlags) override;
  FX_BOOL OnChar(IReader_DocView *pDocView, UINT nKeyCode, UINT nFlags) override;
  FX_BOOL OnLButtonDown(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL OnLButtonUp(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL OnLButtonDblClk(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL OnMouseMove(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL OnRButtonDown(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL OnRButtonUp(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL OnRButtonDblClk(IReader_PageView *pPageView, UINT nFlags, const CPoint &point) override;
  FX_BOOL OnMouseWheel(IReader_PageView *pPageView, UINT nFlags, short zDelta, const CPoint &point) override;

  // IReader_POEventHandler
  void OnBeforeInsertPages(IReader_Document *pDoc, int nInsertAt, int nCount) override;
  void OnAfterInsertPages(IReader_Document *pDoc, int nInsertAt, int nCount) override;
  void OnBeforeDeletePages(IReader_Document *pDoc, const CFX_WordArray &arrDelPages) override;
  void OnAfterDeletePages(IReader_Document *pDoc, const CFX_WordArray &arrDelPages) override;
  void OnBeforeRotatePage(IReader_Document *pDoc, int iPage, int nRotate) override;
  void OnAfterRotatePage(IReader_Document *pDoc, int iPage, int nRotate) override;
  void OnBeforeResizePage(IReader_Document *pDoc, int iPage, const CPDF_Rect *pMediaBox,
                          const CPDF_Rect *pCropBox) override;
  void OnAfterResizePage(IReader_Document *pDoc, int iPage, const CPDF_Rect *pMediaBox,
                         const CPDF_Rect *pCropBox) override;

  // others
  void OnDocDidSave(IReader_Document *pDoc, FX_BOOL bSaveAs, BOOL bPromptToSave, FX_LPCWSTR lpwsFilePath);
  void OnMouseClickOnText(IReader_Document *pDoc, FX_LPCWSTR wsText, CRect rtClient);
  void OnDrawAnnot(IReader_PageView *pPageView, HDC hDC, IReader_Annot *pAnnot, CFX_RenderDevice *pDevice,
                   CPDF_Matrix *pUser2Device, const CRect &rcWindow, DWORD dwFlags);
  void OnThumbnailWillDraw(IReader_ThumbnailView *pThumbnailView, HDC dc);
  void OnThumbnailDidDraw(IReader_ThumbnailView *pThumbnailView, HDC dc);
  void OnPageViewerWillDraw(CReader_PageViewer *pPageViewer, HDC dc);
  BOOL OnDocCanPaste();
  BOOL OnDocSaveAsBeforeReopen(FS_LPCWSTR wszFilePath);
  BOOL CanDocBeSaved(IReader_Document *pDoc);
  void OnDocDidFileClose(FS_LPCWSTR lpwsFilePath);
};
#endif

#endif
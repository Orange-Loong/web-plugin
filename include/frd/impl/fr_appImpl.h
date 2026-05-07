/** @file fr_appImpl.h.
 * 
 *  @brief defined all interface associate with Foxit Reader user interface .
 */

#ifndef FR_APPIMPL_H
#define FR_APPIMPL_H

#ifndef FR_APPEXPT_H
#include "../fr_appExpT.h"
#endif

class IReader_Document;
class IReader_App;
#include "../../../../ExternalModule/Preflight/FoxitTypes.h"
#include "../../../../BaseAnnot/include/IBaseAnnot.h"
#include "../../../../MarkupAnnot/Include/IMarkupAnnot.h"
#include "../../../../InternalSDK/include/observable.h"
//#include "../../../../../PluginSDK/include/plugin_layer/security/fr_securityExpT.h"

class CFR_CustomerSecurityHandler : public CPDF_SecurityHandler
{
	friend class CFR_CustomerCryptoHandler;
public:
	CFR_CustomerSecurityHandler(FR_SecurityCallbacks securityCalls);

	virtual ~CFR_CustomerSecurityHandler();

public:
	//************************************
	// Function:  OnInit
	// Param[in]: pParser
	// Param[in]: pEncryptDict
	// Return:
	// Remarks:
	// Notes:
	//************************************
	FX_BOOL		OnInit(CPDF_Parser* pParser, CPDF_Dictionary* pEncryptDict);

	//************************************
	// Function:  IsProcessErrMsg
	// Return:
	// Remarks:
	// Notes:
	//************************************
	FX_BOOL		IsProcessErrMsg();

	//************************************
	// Function:  GetPermissions
	// Return:
	// Remarks:
	// Notes:
	//************************************
	FX_DWORD	GetPermissions();

	//************************************
	// Function:  IsOwner
	// Return:
	// Remarks:
	// Notes:
	//************************************
	FX_BOOL		IsOwner();

	//************************************
	// Function:  GetCryptInfo
	// Param[in]: cipher
	// Param[in]: buffer
	// Param[in]: keylen
	// Return:
	// Remarks:
	// Notes:
	//************************************
	FX_BOOL		GetCryptInfo(FS_INT32& cipher, FX_LPCBYTE& buffer, FS_INT32& keylen);

	virtual FX_BOOL IsMetadataEncrypted();

	//************************************
	// Function:  CreateCryptoHandler
	// Return:
	// Remarks:
	// Notes:
	//************************************
	CPDF_CryptoHandler*	CreateCryptoHandler();

protected:
	FR_SecurityCallbacksRec m_Callbacks;

	FX_LPVOID	m_pClientHandler;
	CPDF_CryptoHandler *m_pCryptHd;
	CPDF_Dictionary *m_pDic;
	CPDF_Parser *m_pParser;
};

class CFR_CustomerCryptoHandler : public CPDF_CryptoHandler
{
public:
	CFR_CustomerCryptoHandler(FR_CryptoCallbacks pCallbacks, FX_LPVOID pClientHandler);
	virtual ~CFR_CustomerCryptoHandler();

public:
	virtual FX_BOOL		Init(CPDF_Dictionary* pEncryptDict, CPDF_SecurityHandler* pSecurityHandler);

	virtual FX_DWORD	DecryptGetSize(FX_DWORD src_size);

	virtual FX_LPVOID	DecryptStart(FX_DWORD objnum, FX_DWORD gennum);

	virtual FX_BOOL		DecryptStream(FX_LPVOID context, FX_LPCBYTE src_buf, FX_DWORD src_size, CFX_BinaryBuf& dest_buf);

	virtual FX_BOOL		DecryptFinish(FX_LPVOID context, CFX_BinaryBuf& dest_buf);

	virtual FX_DWORD	EncryptGetSize(FX_DWORD objnum, FX_DWORD version, FX_LPCBYTE src_buf, FX_DWORD src_size);

	virtual FX_BOOL		EncryptContent(FX_DWORD objnum, FX_DWORD version, FX_LPCBYTE src_buf, FX_DWORD src_size,
										FX_LPBYTE dest_buf, FX_DWORD& dest_size);

	virtual FX_BOOL		ProgressiveEncryptStart(FX_DWORD objnum, FX_DWORD version, FX_DWORD raw_size, FX_BOOL bFlateEncode);

	virtual FX_BOOL     ProgressiveEncryptContent(FX_INT32 objnum, FX_DWORD version, FX_LPCBYTE src_buf, FX_DWORD src_size, CFX_BinaryBuf& dest_buf);

	virtual FX_BOOL     ProgressiveEncryptFinish(CFX_BinaryBuf& dest_buf);
protected:
	FR_CryptoCallbacksRec m_Callbacks;

	FX_LPVOID	m_pClientHandler;
	FX_LPVOID	m_pClientContext;
};


class CFR_IPDFAPluginHandler : public IPDFAPluginHandler
{
public:
	CFR_IPDFAPluginHandler(FR_PDFAPluginHandlerCallbacks callbacks);
	virtual ~CFR_IPDFAPluginHandler();

	virtual BOOL SaveAsPDFA(IReader_Document* pRDoc, const FRPDFA_PDFVersion pVersion, CFX_WideString wsPathSuffix);

	BOOL SaveAsPDFA(IReader_Document* pRDoc, const std::string& pkeyVersion, CFX_WideString wsPathSuffix);

private:
	FR_PDFAPluginHandlerCallbacksRec m_CallbacksRec;
};

#ifdef __cplusplus
extern "C"{
#endif

class CFR_Tool_V1
{
public:

    //************************************
    // Function:  New
    // Param[in]: name			The tool name. It may not be <a>NULL</a>.
    // Param[in]: callbacks		The event callbacks associate with a tool. When a event occurs, Reader will
    // call a corresponding callback function.
    // Return:	The new tool object or <a>NULL</a> if the tool with the <param>name</param> is exist.
    // Remarks:	 Creates a tool object.
    // Notes: If the tool name has been used, <a>NULL</a> will return.
    // See: FRToolRelease
    // See: FRAppRegisterTool
    //************************************
    static FR_Tool	New(FS_LPCSTR name, FR_ToolCallbacks callbacks);

    //************************************
    // Function:  Release
    // Param[in]: tool			The tool to release.
    // Return:	void
    // Remarks:	Releases the specified tool.
    // Notes:
    //************************************
    static void		Release(FR_Tool tool);

    //************************************
    // Function:  GetName
    // Param[in]: tool			The tool object.
    // Param[out]: outName		The tool name buffer,filled by Reader.
    // Return:	void
    // Remarks:	Gets the name of specified tool.
    // Notes:
    //************************************
    static void		GetName(FR_Tool tool, FS_ByteString* outName);

    //************************************
	// Function:  SetAssociatedMousePtHandlerType
	// Param[in]: tool			The tool object.
	// Param[in]: lpsType		The type of associated mouse point handler.
	// Return:	void
	// Remarks:	Sets the type of associated mouse point handler.
	// Notes:
	// See: FRAppRegisterMousePtHandler
	// Deprecated: Internal use
	//************************************
    static void		SetAssociatedMousePtHandlerType(FR_Tool tool, FS_LPCSTR lpsType);

    //************************************
	// Function:  SetAssociatedSelectionHandlerType
	// Param[in]: tool			The tool object.
	// Param[in]: lpsType		The type of associated selection handler.
	// Return:	void
	// Remarks:	Sets the type of associated selection handler.
	// Notes:
	// Deprecated: Internal use
	//************************************
    static void		SetAssociatedSelectionHandlerType(FR_Tool tool, FS_LPCSTR lpsType);

	//************************************
	// Function:  Tool_GetBeginPoint
	// Param[in]: tool			The tool object.
	// Param[out]: point		The <a>FS_DevicePoint</a> specified in screen coordinates.
	// Return:	FS_BOOL TRUE is to success. FLASE is to failure.
	// Remarks:	Get the first point of pressing mouse when using special tool.
	// Notes:
	// Deprecated: Internal use
	//************************************
	static FS_BOOL Tool_GetBeginPoint(FR_Tool tool, FS_DevicePoint& point);
};

class CFR_App_V1
{
public:
    //************************************
    // Function:  GetName
    // Param[out]: outName			The string buffer used to receive the name of application. It
    // will be filled by reader.
    // Return:	void
    // Remarks: Gets the <a>FS_ByteString</a> corresponding to the application's name, which is the name
    // of the file containing the Foxit Reader application.
	// Notes: The application name will be "Foxit PhantomPDF" or "Foxit Reader".
    // See: FRAppGetTitle
    //************************************
    static void GetName(FS_ByteString* outName);

    //************************************
    // Function:  GetVersion
    // Param[out]: outVersion		The string buffer used to receive the version information of application.
    // It will be filled by reader.
    // Return:	void
    // Remarks: Gets the <a>FS_WideString</a> corresponding to the application's version. The Format of version
    // information is XX.XX.XX.XX(major number.minor number.maintainence number.build number).
    // Notes:
    //************************************
    static void GetVersion(FS_WideString* outVersion);

    //************************************
    // Function:  GetAppTitle
    // Param[out]: outTitle			The string buffer used to receive the title of application.
    // It will be filled by reader.
    // Return:	<a>TRUE</a> for success, otherwise not.
    // Remarks: Gets the <a>FS_WideString</a> corresponding to the application's title.
    // Notes:The user might have changed this, so do not use it to determine what the application is.
    // Use FRAppGetName instead.
    // See: FRAppGetName
    //************************************
    static FS_BOOL GetAppTitle(FS_WideString* outTitle);

    //************************************
    // Function:  GetAppDataPath
    // Param[out]: outAppPath		The string buffer used to receive the path which Foxit Reader used to
    // store some application's data. It will be filled automaticly by reader.
    // Return:	<a>TRUE</a> for success, otherwise not.
    // Remarks:	 Gets the execution file path of current running reader.
    // Notes:
    //************************************
    static FS_BOOL		GetAppDataPath(FS_WideString* outAppPath);

	//************************************
	// Function:  CanQuit
	// Return: <a>TRUE</a> if foxit reader can quit, <a>FALSE</a> if cannot. The default version of the routine
	// always returns <a>TRUE</a>.
	// Remarks:	 Gets the permission to decide whether you can quit.  	
	// Notes:
	// Deprecated: Internal use. This function is deprecated.
	//************************************
	static FS_BOOL		CanQuit(void);

	//************************************
	// Function:  CountToolbars
	// Return:	The number of toolbar.
	// Remarks:	Gets the number of toolbars, including the flyout toolbars.
	// Notes:
	// See: FRAppGetToolBar
	// Deprecated: Internal use. This function is deprecated.
	//************************************
	static FS_INT32			CountToolbars(void);

	
	//************************************
	// Function:  GetToolBar
	// Param[in]: index			The index of toolbar to obtain. The index range is 0 to (<a>FRAppCountToolbars</a>()-1).
	// Param[in]: pParentWnd	A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	// You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	// Return:	The <a>FR_ToolBar</a> object.
	// Remarks:	  Gets the specified toolbar.	
	// Notes:
	// See: FRAppCountToolbars
	// See: FRAppGetToolBarByName
	// Deprecated: Internal use. This function is deprecated.
	//************************************
	static FR_ToolBar	GetToolBar(FS_INT32 index, void* pParentWnd);

	//************************************
	// Function:  GetToolBarByName
	// Param[in]: csName		The name of the toolbar.
	// Param[in]: pParentWnd	A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	// You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	// Return:	The <a>FR_ToolBar</a>, or <a>NULL</a> if no <a>FR_ToolBar</a> was found with the specified name.
	// Remarks:	Gets toolbar created with the specified name, All toolbars(including flyout toolbar) can be obtained by the method.   	
	// Notes:
	// See: FRToolBarSetName
	// Deprecated: Internal use. This function is deprecated.
	//************************************
	static FR_ToolBar	GetToolBarByName(FS_LPCSTR csName, void* pParentWnd);

	//************************************
	// Function:  GetMenuBar
	// Return:	The menu bar.
	// Remarks:	Gets Foxit Reader's menu bar.  	
	// Notes:
	// Deprecated: Internal use. This function is deprecated.
	//************************************
	static FR_MenuBar	GetMenuBar(void);

	//************************************
	// Function:  ShowMenuBar
	// Param[in]: bShow			If <a>TRUE</a>, the menu bar will be show, <a>FALSE</a> to hide.
	// Return:	void
	// Remarks: Shows/Hides menu bar.	  	
	// Notes:
	// Deprecated: Internal use. This function is deprecated.
	//************************************
	static void			ShowMenuBar(FS_BOOL bShow);

	//************************************
	// Function:  RegisterTool
	// Param[in]: tool		The <a>FR_Tool</a> object containing the tool's callbacks. This object
	// must not be freed after calling <a>FRAppRegisterTool</a>(), but must be remained.
	// Return:	
	// Remarks: Registers a tool into the Foxit Reader.
	// Notes:
	// See: FRToolNew
	// See: FRAppSetActiveTool
	//************************************
	static void		RegisterTool(FR_Tool tool);

	//************************************
	// Function:  GetToolByName
	// Param[in]: csName		The tool name.
	// Return:	The tool that was registered under name, or <a>NULL</a> if no match was found.
	// Remarks:	Gets the <a>FR_Tool</a> object that was registered under specified name. 	
	// Notes:
	// See: FRAppGetToolByIndex
	//************************************
	static FR_Tool		GetToolByName(FS_LPCSTR csName);

	//************************************
	// Function:  CountTools
	// Return: The number of tools.(Including built-in tools)	
	// Remarks:	Gets the number of registered <a>FR_Tool</a> object.
	// Notes:
	// See: FRAppGetToolByIndex
	//************************************
	static FS_INT32		CountTools(void);

	//************************************
	// Function:  GetToolByIndex
	// Param[in]: index			The index of tool to obtain. The index range is 0 to (<a>FRAppCountTools</a>()-1).
	// Return: The specified tool.	
	// Remarks:	Gets the specified tool.  	
	// Notes:
	// See: FRAppGetToolByName
	// See: FRAppCountTools
	//************************************
	static FR_Tool		GetToolByIndex(FS_INT32 index);

	//************************************
	// Function:  SetActiveTool
	// Param[in]: tool			The tool to set as the active tool.
	// Param[in]: persistent	A flag that indicates a preference as to whether the tool stays active after
	// it is used. <a>TRUE</a> is a hint that the tool should.if possible, stay active for an arbitrary number 
	// of operations (whatever that happens to be) rather than doing a one shot operation and restoring the 
	// prior active tool.
	//
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Sets the active tool. It does nothing if the specified tool is not currently enabled, The
	// <a>FRToolIsEnabled</a>() callback in <a>FR_ToolCallbacksRec</a> structure determines whether a tool is
	// enabled. If this callback is <a>NULL</a>, the tool is always enabled.
	// Notes:
	// See: FRAppRegisterTool
	// See: FRAppGetActiveTool
	//************************************
	static FS_BOOL			SetActiveTool(FR_Tool tool, FS_BOOL persistent);

	//************************************
	// Function:  GetActiveTool
	// Return:	The active tool.
	// Remarks: Gets the active tool from the application.	
	// Notes:
	// See: FRAppSetActiveTool
	// See: FRAppRegisterTool
	//************************************
	static FR_Tool		GetActiveTool(void);

	//************************************
	// Function:  RegisterPreferencePageHandler
	// Param[in]: preferPageCallbacks		The callback set. Reader will call a corresponding callback when the 
	// preference dialog is to be show or to be destroy.
	// Return:	<a>TRUE</a> for success, otherwise failure.
	// Remarks:	 Registers the event notification to preference dialog.
	// Notes: You must also call <a>FRAppAddPreferencePage</a>() in the <a>FRPrefPageOnCreate</a>() callback to
	// add a preference page to Reader preference dialog.
	//  
	// See: FRAppAddPreferencePage
	// See: FRAppShowPreferenceDlg
	//************************************
	static FS_BOOL					RegisterPreferencePageHandler(FR_PreferPageCallbacks preferPageCallbacks);

	//************************************
	// Function:  AddPreferencePage
	// Param[in]: parent			The parent window.
	// Param[in]: preferPage		A platform-specific object.	In windows, it is a HWND handler.	
	// Param[in]: title				The title of the preference page. It will be displayed on the list box in
	// the left of preference dialog.
	// Return:	<a>TRUE</a> for success, or <a>FALSE</a> if the preference page has existed or the title of the page
	// has been used.
	// Remarks:	Adds a preference page into Reader preference dialog.  	
	// Notes: You should call this method in the implementation of <a>FRPrefPageOnCreate</a>() callback.
	// See: FRAppRegisterPreferencePageHandler
	//************************************
	static FS_BOOL				AddPreferencePage(HWND parent, HWND preferPage, FS_LPCWSTR title);

	//************************************
	// Function:  RegisterDocPropertyPageHandler
	// Param[in]: docProperPageCallbacks		The callback set. Reader will call a corresponding callback when the 
	// document properties dialog is to be show or to be destroy.
	// Return:	<a>TRUE</a> for success, otherwise <a>FALSE</a>.
	// Remarks:	 Registers the event notification to document properties dialog. 	
	// Notes: You must also call <a>FRAppAddDocPropertyPage</a>() in the <a>FRDocPropertyPageOnCreate</a>() callback to
	// add a property page to Reader document properties dialog.
	// The interface has been deprecated.
	// See: FRAppAddDocPropertyPage
	//************************************
	static FS_BOOL					RegisterDocPropertyPageHandler(FR_DocPropertypageCallbacks docProperPageCallbacks);

	//************************************
	// Function:  AddDocPropertyPage
	// Param[in]: parent			The parent window.
	// Param[in]: propertyPage			A platform-specific object.	In windows, it is a <Italic>HWND</Italic> handler.
	// Param[in]: title					The title of the document property page. It will be displayed on the 
	// tabsheet in the top of document properties dialog.
	// Return: <a>TRUE</a> for success, or <a>FALSE</a> if the property page has existed or the title of the page
	// has been used.	
	// Remarks:	 Adds a document property page into Reader document properties dialog. 	
	// Notes: You should call this method in the implementation of <a>FRDocPropertyPageOnCreate</a>() callback.
	// See: FRAppRegisterDocPropertyPageHandler
	//************************************
	static FS_BOOL				AddDocPropertyPage(HWND parent, HWND propertyPage, FS_LPCWSTR title);

	//************************************
	// Function:  RegisterNavPanelView
	// Param[in]: panelViewCallbacks	A panel page callback set. When the navigation panel occurs a event, reader will
	// call a corresponding callback to respond.
	// Return:    <a>TRUE</a> for success, otherwise not.
	// Remarks: Registers a navigation panel view into the Foxit Reader.
	// Notes:
	// Deprecated: Internal used. Repalce by <a>FRAppRegisterPanelToolHandler</a>
	//************************************

	static FS_BOOL			RegisterNavPanelView(FR_PanelViewCallbacks panelViewCallbacks);

	//************************************
	// Function:  RegisterAppEventHandler
	// Param[in]: appEventCallbacks		The callback set. Reader will call a corresponding callback when the app event occurs.
	// Return:	<a>TRUE</a> for success, otherwise not.
	// Remarks: Registers a user-supplied procedure set to call when some application level event occurs.
	// Notes:
	//************************************
	static FS_BOOL			RegisterAppEventHandler(FR_AppEventCallbacks appEventCallbacks);


	//************************************
	// Function:  CountDocsOfPDDoc
	// Return: The number of document views that is used to display PDF file type.
	// Remarks:	Gets the number of document views. This method just only count the document view that for 
	// displaying PDF file type, does not count other document view for displaying other format file.
	// Notes:
	// See: FRAppGetDocOfPDDoc
	//************************************
	static FS_INT32			CountDocsOfPDDoc(void);

	//************************************
	// Function:  GetDocOfPDDoc
	// Param[in]: index			The index of specified document view with a <a>FPD_Document</a> object.
	// The range is 0 to (CountDocsOfPDDoc()-1);
	// Return:	A document window.
	// Remarks:	Gets the document view by specified index.
	// Notes: This method just return the document window which for displaying PDF file type, ignore other 
	// format file window.
	// See: FRAppCountDocsOfPDDoc
	// See: FRAppGetActiveDocOfPDDoc
	//************************************
	static FR_Document	GetDocOfPDDoc(FS_INT32 index);

	//************************************
	// Function:  GetActiveDocOfPDDoc
	// Return: The top-most document window which is used for displaying PDF file type, or <a>NULL</a> if
	// no documents are open. <a>NULL</a> is also returned while the top-most document window is not displaying
	// PDF file type and while a document is being opened.
	// Remarks: Gets the top-most document window which for displaying PDF file type.	  	
	// Notes:
	// See: FRAppGetDocOfPDDoc
	// See: FRAppSetActiveDocOfPDDoc
	//************************************
	static FR_Document	GetActiveDocOfPDDoc();

	//************************************
	// Function:  SetActiveDocOfPDDoc
	// Param[in]: doc			The <a>FR_Document</a> object.
	// Return: <a>TRUE</a> means successful, otherwise not.
	// Remarks:	Sets a document view to top-most.  	
	// Notes:
	// See: FRAppGetActiveDocOfPDDoc
	// See: FRAppCountDocsOfPDDoc
	// See: FRAppGetDocOfPDDoc
	//************************************
	static FS_BOOL		SetActiveDocOfPDDoc(FR_Document doc);

	
	//************************************
	// Function:  RegisterDocHandlerOfPDDoc
	// Param[in]: docEventCallbacks		The callback set. Reader will call a corresponding callback when the doc event occurs.
	// Return:	 <a>TRUE</a> means successful, otherwise not.
	// Remarks:	 Registers a user-supplied event handler to document window. 	
	// Notes: The callbacks of FR Doc Event Handler just be called while the document window is displaying
	// PDF file type.
	//************************************
	static FS_BOOL		RegisterDocHandlerOfPDDoc(FR_DocEventCallbacks docEventCallbacks);

	//************************************
	// Function:  IsFullScreen
	// Return:	<a>TRUE</a> if the application is currently in full-screen mode, otherwise not.
	// Remarks: Tests whether the application is running in full-screen mode.	  	
	// Notes:
	// See: FRAppShowFullScreen
	// See: FRAppEndFullScreen
	//************************************
	static FS_BOOL		IsFullScreen(void);

	//************************************
	// Function:  ShowFullScreen
	// Return:	<a>TRUE</a> if the application enters full-screen mode; <a>FALSE</a> if it is already in 
	// full-screen mode or the user clicks the cancel button from dialog box describing how to exit the
	// full-screen mode.
	// Remarks:	Begins full-screen mode. In full-screen mode, all window borders, the menu bar, and the 
	// toolbar are hidden. All regions of the screen outside of the page view boundary are painted by specified
	// color.
	// <a>FRAppShowFullScreen</a>() is ignored if the application is already in full-screen mode, or if there are no
	// currently open documents.
	// Notes:
	// See: FRAppEndFullScreen
	//************************************
	static FS_BOOL			ShowFullScreen(void);

	//************************************
	// Function:  EndFullScreen
	// Return:	<a>TRUE</a> if the application exit full-screen mode, otherwise not.
	// Remarks:	Ends full-screen mode. It does nothing if the the application is not running in full-screen mode.  	
	// Notes:
	// See: FRAppShowFullScreen
	//************************************
	static FS_BOOL			EndFullScreen(void);

	//************************************
	// Function:  GetMousePos
	// Return:	The <a>FS_DevicePoint</a> specified in screen coordinates.
	// Remarks:	Gets the mouse position. The mouse position is specified in screen coordinates.  	
	// Notes:
	//************************************
	static FS_DevicePoint	GetMousePos(void);

	//************************************
	// Function:  ModalWindowIsOpen
	// Return:	<a>TRUE</a> if a modal window is open, otherwise not.
	// Remarks:	A client should use this method to determine whether a modal window is open. 
	// There is a large (and ill-defined) group of actions that are illegal while a modal window is open, although 
	// these actions are not programmatically prevented by the Foxit Reader Viewer. While a modal dialog box is  
	// open, a client must not open documents, change pages, change views, close documents, change tools, or do 
	// anything that might disrupt the user or Foxit Reader viewer. 	
	// Notes:
	//************************************
	static FS_BOOL		ModalWindowIsOpen(void);

	
	//************************************
	// Function:  RegisterSecurityHandler
	// Param[in]: name		The name of the security handler.
	// Param[in]: callbacks The structure containing the security handler callback functions.
	// Return:	void
	// Remarks: Registers a security handler. Invoked this interface to process the PDF documents that 
	// are encrypted by customer security handler.
	// Notes:
	// See: FRAppUnRegisterSecurityHandler
	//************************************
	static void			RegisterSecurityHandler(FS_LPCSTR name, FR_SecurityCallbacks callbacks);

	//************************************
	// Function:  UnRegisterSecurityHandler
	// Param[in]: name	The name of the security handler.
	// Return:	void
	// Remarks: Unregisters a security handler.
	// Notes:
	// See: FRAppRegisterSecurityHandler
	//************************************
	static void			UnRegisterSecurityHandler(FS_LPCSTR name);

	//************************************
	// Function:  GetPassPhrase
	// Param[in]: pstrEncryptedText	An encrypted random string of 128 byte.
	// Param[out]: ppstrPlainText	It receives the plain text from Foxit Reader.
	// Return:	void
	// Remarks:	This interface is invoked by the plug-in to confirm that the host environment is Foxit Reader and is legal.
	//          The following steps show the procedure:<br>
	//			<ul>
	//			<li>1. Plug-in generates a random string of 128 byte length and encrypts it using the public key. </li>
	//			<li>2. Plug-in allocates one buffer of 128 bytes and calls <a>FRAppGetPassPhrase</a>() and passes the encrypted string.</li>
	//			<li>3. Foxit reader will decrypt the encrypted text using the private key and copy it to the buffer <param>pstrPlainText</param>.</li>
	//			<li>4. Plug-in matches the plain text against what it had generated. </li>
	//			</ul>
	// Notes: This function is deprecated.
	// Deprecated: Internal use.
	//************************************
	static void GetPassphrase(FS_LPCSTR pstrEncryptedText, FS_LPSTR* ppstrPlainText);

	//************************************
	// Function:  RegisterContentProvider
	// Param[in]: contentProviderCallbacks	The content provider callbacks.
	// Return:	void
	// Remarks:	Registers a content provider so that the plug-in can process the protected document and provide decrypted
	// document data.
	// Notes:
	//************************************
	static void			RegisterContentProvider(FR_ContentProviderCallbacks contentProviderCallbacks);

	//************************************
	// Function:  GetMainFrameWnd
	// Return:	A <Italic>HWND</Italic> object for windows.
	// Remarks:	Gets the main frame window of Foxit Reader.
	// Notes:
	//************************************
	static HWND			GetMainFrameWnd(void);

	//************************************
	// Function:  AddUndoRedoItem
	// Param[in]: lpwDescr		The input description of the undo-redo item.
	// Param[in]: frDoc			The specified document.
	// Param[in]: bEdit			Whether the current operation is editing, for example, you add a typewriter and enter characters.
	// Param[in]: callbacks		The user-supplied callbacks for implementing undo-redo.
	// Return:	void
	// Remarks:	Adds a undo-redo item to the specified document.
	// Notes:
	// See: FRAppUndoRedoIsEditing
	// See: FRAppUndoRedoBeginEdit
	// See: FRAppUndoRedoEndEdit
	// Deprecated: Internal use.
	//************************************
	static void	AddUndoRedoItem(FS_LPCWSTR lpwDescr, FR_Document frDoc, FS_BOOL bEdit, FR_UndoRedoCallbacks callbacks);

	//************************************
	// Function:  RegisterPageHandlerOfPDDoc
	// Param[in]: callbacks		The callback set. Reader will call a corresponding callback when the page event occurs.
	// Return:	void
	// Remarks:	Registers a page-level event callback set.
	// Notes:
	//************************************
	static void			RegisterPageHandlerOfPDDoc(FR_PageEventCallbacks callbacks);

	//************************************
	// Function:  RegisterForContextMenuAddition
	// Param[in]: menuName		The name of the context menu to modify. Its names can be one of the 
	// following:<br>
	// <ul><li>Name - Description</li>
	// <li>Page - The standard context menu for an FR_PageView.</li>
	// <li>Select - The context menu for selected text.</li>
	// <li>Snapshot - The context menu for snapshot of FR_PageView.</li>
	// Param[in]: proc			The user-supplied procedure to call.
	// Param[in]: clientData	A pointer to user-supplied data to pass to the procedure each time it 
	// is called.
	// Return:		<a>TRUE</a> means successful, otherwise not.
	// Remarks:		Registers a user-supplied procedure to call after a context menu has been created but before it is shown to 
	// the user. The callback can add menu items to or remove menu items from the menu.
	// Notes: It only available in Windows.
	//************************************
	static FS_BOOL			RegisterForContextMenuAddition(FS_LPCSTR csName, FRContextMenuPopUpProc proc, void* pClientData);

	//************************************
	// Function:  RegisterSelectionHandler
	// Param[in]: callbacks		A structure containing the selection handler's callback functions. This structure 
    // must not be freed after calling <a>FRAppRegisterSelectionHandler</a>().
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Registers a new selection handler. Selection handlers allow the selection of items 
	// other than those that can be selected in the as-shipped Foxit viewer. For example, a selection handler 
	// could allow a user to select a sampled image.
    // This method can be used to replace an existing selection handler that handles the same selection type.
	// Notes: Call FRAppUnRegisterSelectionHandler to unregister the selection handler and release the memory.
	//************************************
	static FS_BOOL RegisterSelectionHandler(FR_SelectionCallbacks callbacks);

	//************************************
	// Function:  UnRegisterSelectionHandler
	// Param[in]: callbacks		A structure containing the selection handler's callback functions.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Unregisters the selection handler and releases the memory.
	// Notes:
	//************************************
	static FS_BOOL UnRegisterSelectionHandler(FR_SelectionCallbacks callbacks);

	//************************************
	// Function:  RegisterCaptureHandler
	// Param[in]: callbacks		A structure containing the capture handler's callback functions.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Registers the capture handler.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL RegisterCaptureHandler(FR_CaptureCallbacks callbacks);

	//************************************
	// Function:  UnRegisterCaptureHandler
	// Param[in]: callbacks		A structure containing the capture handler's callback functions.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Unregisters the capture handler and releases the memory.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL UnRegisterCaptureHandler(FR_CaptureCallbacks callbacks);

	//************************************
	// Function:  RegistryGetProfilePath
	// Param[out]: outProfilePath It receives the registry's profile path of the Foxit Reader.
	// Return:	void
	// Remarks:	Gets the registry's profile path of the Foxit Reader.
	// Notes:
	//************************************
	static void RegistryGetProfilePath(FS_WideString* outProfilePath);

	//************************************
	// Function:  RegistryWriteInt
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[in]: nValue		The input int value.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Write int value to the specified registry. If you want to set the value in registry like 
	// <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	// <param>lpszSection</param> can be set as <Italic>"Create Link"</Italic>.
	// If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	// <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
	// Notes:
	//************************************
	static FS_BOOL RegistryWriteInt(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry, FS_INT32 nValue);

	//************************************
	// Function:  RegistryWriteBinary
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[in]: pData			The input binary data.
	// Param[in]: nValue		The size of the binary data.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Write binary value to the specified registry. If you want to set the value in registry like 
	// <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	// <param>lpszSection</param> can be set as <Italic>"Create Link"</Italic>.
	// If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	// <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
	// Notes:
	//************************************
	static FS_BOOL RegistryWriteBinary(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry, FS_LPBYTE pData, unsigned int nBytes);

	//************************************
	// Function:  RegistryWriteString
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[in]: lpszValue		The input string.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Write string to the specified registry. If you want to set the value in registry like 
	// <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	// <param>lpszSectio</param>n can be set as <Italic>"Create Link"</Italic>.
	// If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	// <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
	// Notes:
	//************************************
	static FS_BOOL RegistryWriteString(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry, FS_LPCWSTR lpszValue);

	//************************************
	// Function:  RegistryGetInt
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Return:	The int value in the specified section.
	// Remarks:	Gets the int value in the specified section.
	// Notes:
	//************************************
	static UINT RegistryGetInt(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry);

	//************************************
	// Function:  RegistryGetBinary
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[out]: ppData		It receives the binary data.
	// Param[out]: pBytes		It receives the size of the binary data.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Gets the binary value in the specified section.
	// Notes:
	//************************************
	static FS_BOOL RegistryGetBinary(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry, unsigned char** ppData, unsigned int* pBytes);

	//************************************
	// Function:  RegistryGetString
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[out]: outString	It receives the string.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Gets the string value in the specified section.
	// Notes:
	//************************************
	static FS_BOOL RegistryGetString(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry, FS_WideString* outString);

	//************************************
	// Function:  RegistryGetEntryCount
	// Param[in]: lpszSection	The input registry section.
	// Return:	The entry count in the specified section.
	// Remarks:	Gets the entry count in the specified section.
	// Notes:
	//************************************
	static FS_INT32 RegistryGetEntryCount(FS_LPCWSTR lpszSection);

	//************************************
	// Function:  RegistryGetEntryName
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: nIndex		The specified index.
	// Param[out]: outName		It receives the entry name.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Gets the entry name in the specified section.
	// Notes:
	//************************************
	static FS_BOOL RegistryGetEntryName(FS_LPCWSTR lpszSection, FS_INT32 nIndex, FS_WideString* outName);

	//************************************
	// Function:  RegistryRemoveSection
	// Param[in]: lpszSection	The input registry section.
	// Return:	void
	// Remarks:	Removes the specified section.
	// Notes:
	//************************************
	static void RegistryRemoveSection(FS_LPCWSTR lpszSection);

	//************************************
	// Function:  RegistryRemoveEntry
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Return:	void
	// Remarks:	Removes the specified entry.
	// Notes:
	//************************************
	static void RegistryRemoveEntry(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry);

	//************************************
	// Function:  GetGEModule
	// Return:	The app GE module.
	// Remarks:	Gets the app GE module.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void*   GetGEModule(void);

	//************************************
	// Function:  GetModuleMgr
	// Return:	The app module manager.
	// Remarks:	Gets the app module manager.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void*  GetModuleMgr(void);

	//************************************
	// Function:  CreateAnEmptyFrameWnd
	// Param[in]: title				The title of the frame which will be created.
	// Param[in]: bMakeVisible		A flag indicate whether to show the frame.
	// Param[in]: notify			The notifies for new window.
	// Return:	  The handler of the newly created frame.
	// Remarks:   Creates a new frame window.
	// Notes: 
	//************************************
	static HWND CreateAnEmptyFrameWnd(FS_WideString title, FS_BOOL bMakeVisible, FR_EmptyFramWndNotifies notify);

	//************************************
	// Function:  IsRunEmbedded
	// Return:	  <a>TRUE</a> for running embedded, otherwise <a>FALSE</a>.
	// Remarks:   Tests whether the Foxit Reader is running embedded or not.
	// Notes:  Only available in Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsRunEmbedded(void);	

	//************************************
	// Function:  RegisterExtraPrintInfoProvider
	// Param[in]: callbacks				The callbacks which will be broadcast.
	// Return:	  void.
	// Remarks:   Register the printing notifies.
	// Notes: 
	//************************************
	static void		RegisterExtraPrintInfoProvider(FR_ExtraPrintInfoProviderCallbacks callbacks);


	//************************************
	// Function:  IsRibbonMode
	// Return:	  <a>TRUE</a> if current toolbar mode is tabbed mode, otherwise <a>FALSE</a>.
	// Remarks:   Tests whether current toolbar mode is tabbed mode.
	// Notes: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	IsRibbonMode(void);

	//************************************
	// Function:  GetStartMenuOfTabbedToobarMode
	// Return:	  A <a>FR_Menu</a> object indicates the start menu of tabbed toolbar mode. <a>NULL</a> if
	//				current toolbar mode is not tabbed mode.
	// Remarks:   Gets the start menu which is in tabbed toolbar mode.
	// Notes: If a <a>FR_Menu</a> is added into a exist menu in commonent toolbar mode, and need add into the start menu,
	//		call <a>FRAppIsRibbonMode</a>() first, then call <a>FRAppGetStartMenuOfTabbedToobarMode</a>() to get the start
	//		menu and add the menu item to start menu again.
	// Deprecated: Internal use.
	//************************************
	static FR_Menu	GetStartMenuOfTabbedToobarMode(void);

	//************************************
	// Function:  RegisterTaskPaneView
	// Param[in]: callbacks			The callback set for a task pane view.
	// Return:	  <a>TRUE</a> for success, otherwise <a>FALSE</a>.
	// Remarks:   Registers callback set for a task pane view.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppShowTaskPane
	//************************************
	static FS_BOOL RegisterTaskPaneView(FR_TaskPaneViewCallbacks paneView);

	//************************************
	// Function:  ShowTaskPane
	// Param[in]: nameOfPaneView	The name of the pane view which would be shown or hidden.
	// Param[in]: bShow				A flag indicates whether the pane view specified by <param>nameOfPaneView</param> should be
	// shown or hidden.
	// Return:	  void
	// Remarks:   Shows or hidden a task panel view.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterTaskPaneView
	//************************************
	static void ShowTaskPane(FS_LPSTR nameOfPaneView, FS_BOOL bShow);

	//************************************
	// Function:  GetTaskPaneWndHandleByDoc
	// Param[in]: frDoc	The document associated with the task pane.
	// Return:	  The window handle of the task pane.
	// Remarks:   Gets the window handle of the task pane.
	// Notes:  Only available in Windows
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: FRAppRegisterTaskPaneView
	//************************************
    static FS_HWND GetTaskPaneWndHandleByDoc(FR_Document frDoc);

	//************************************
	// Function:  CommandLineHasSwitch
	// Param[in]: pwszSwitch The switch name to be checked.
	// Return:	  <a>TRUE</a> if the switch exists, otherwise <a>FALSE</a>
	// Remarks:   Checks whether the <param>pwszSwitch</param> exists.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppOnRunCommandLine
	//************************************
	static FS_BOOL CommandLineHasSwitch(FS_LPCWSTR pwszSwitch);

	//************************************
	// Function:  CommandLineGetSafeArgument
	// Param[in]: pwszSwitch The switch name to which the argument belongs.
	// Param[in]: iIndex The index of the arguments.
	// Param[in]: pwszDefault The default value of argument. If the specified argument is not existing, the default value will be returned.
	// Param[out]: outArgument It receives the argument.
	// Return:	  void
	// Remarks:   Gets the specified argument. If the specified argument is not existing, the default value will be returned.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void CommandLineGetSafeArgument(FS_LPCWSTR pwszSwitch, FS_INT32 iIndex, FS_LPCWSTR pwszDefault, FS_WideString* outArgument);

	//************************************
	// Function:  CommandLineGetArgument
	// Param[in]: pwszSwitch The switch name to which the argument belongs.
	// Param[in]: iIndex The index of the arguments.
	// Param[out]: outArgument It receives the argument.
	// Return:	  void
	// Remarks:   Gets the specified argument.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void CommandLineGetArgument(FS_LPCWSTR pwszSwitch, FS_INT32 iIndex, FS_WideString* outArgument);

	//************************************
	// Function:  CommandLineGetArgumentCount
	// Param[in]: pwszSwitch The switch name to which the argument belongs.
	// Return:	  The count of the argument.
	// Remarks:   Gets the count of the argument.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_INT32 CommandLineGetArgumentCount(FS_LPCWSTR pwszSwitch);

	//************************************
	// Function:  RegisterWinMSGHandler
	// Param[in]: callbacks			The callback set for a windows MSG handler.
	// Return:	  <a>TRUE</a> for success, otherwise <a>FALSE</a>.
	// Remarks:   Registers callback set for a windows MSG handler.
	// Notes: Only available in Windows. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:Internal use.
	//************************************
	static FS_BOOL RegisterWinMSGHandler(FR_WinMSGCallbacks callbacks);

	//************************************
	// Function:  GetRecentFileList
	// Param[out]: pArrFileList	It receives the recent opened file list.
	// Return:	  void.
	// Remarks:   Gets the recent opened file list.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void GetRecentFileList(FS_WideStringArray* pArrFileList);

	//************************************
	// Function:  AddFileToRecentFileList
	// Param[in]: lpszPathName	The recent opened file path.
	// Return:	  void.
	// Remarks:   Adds the recent opened file path to the list.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void AddFileToRecentFileList(FS_LPCWSTR lpszPathName);

	//************************************
	// Function:  ClearRecentFileList
	// Return:	  void.
	// Remarks:   Clears the recent opened file list.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void ClearRecentFileList();

	//************************************
	// Function:  RegisterSecurityMethod
	// Param[in]: cllbcks The callback set for security method.
	// Return:	  <a>TRUE</a> for success, otherwise failure.
	// Remarks:   Registers the security method that you can manage your security method.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Notes: It has been deprecated, suggest use FRInternalSecurityHandlerRegisterSecurityMethod from security plugin.
	//************************************
    static FS_BOOL RegisterSecurityMethod(FR_SecurityMethodCallbacks cllbcks);

	//************************************
	// Function:  PopDocPropertyPage
	// Param[in]: PageShowName	The property page you want to display.
	// Return: void
	// Remarks: Pops up the doc property pages.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterDocPropertyPageHandler
	//************************************
	static void PopDocPropertyPage(FS_LPCWSTR PageShowName);

	//************************************
	// Function:  CountDocPropertyPages
	// Param[in]: hParent	The parent window.
	// Return: The count of doc property pages.
	// Remarks: Counts the doc property pages.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterDocPropertyPageHandler
	//************************************
	static FS_INT32 CountDocPropertyPages(HWND hParent);

	//************************************
	// Function:  CheckModuleLicense
	// Param[in]: lpwszModuleName	The input module name.
	// Return: Returns <a>TRUE</a> if you have license to the module.
	// Remarks: Checks whether you have license to the module.
	// Notes: This is an internal interface.
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL CheckModuleLicense(FS_LPCWSTR lpwszModuleName);

	//************************************
	// Function:  RegisterOwnerFileType
	// Param[in]: callbacks			The callback set for the owner file type handler.
	// Return:	  <a>TRUE</a> for success, otherwise failure.
	// Remarks:   Adds a file type to Foxit Reader. You can control the process of owner file type, 
	// such as opening, saving, sending email and so on.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL RegisterOwnerFileType(FR_OwnerFileTypeHandlerCallbacks callbacks);

	//************************************
	// Function:  RegistryGetKeyCounts
	// Param[in]: lpszSection	The input registry section.
	// Return:	The counts of key for the specified section.
	// Remarks:	Gets the counts of key for the specified section.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegistryGetProfilePath
	//************************************
	static FS_INT32 RegistryGetKeyCounts(FS_LPCWSTR lpszSection);

	//************************************
	// Function:  RegistryGetKeyName
	// Param[in]: lpszSection	The input registry section.	
	// Param[in]: nIndex		The specified index.
	// Param[out]: outName		It receives the key name.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Gets the key name in the specified section.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegistryGetProfilePath
	//************************************
	static FS_BOOL RegistryGetKeyName(FS_LPCWSTR lpszSection, FS_INT32 nIndex, FS_WideString* outName);

	//************************************
	// Function:  GetRibbonBar
	// Param[in]: pParentWnd	A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	// You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	// Return:	The ribbon bar.
	// Remarks:	Gets Foxit Reader's ribbon bar.  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Repalce by FRAppGetRibbonBar2
	//************************************
	static FR_RibbonBar	GetRibbonBar(void* pParentWnd);

	//************************************
	// Function:  GetRibbonBarBackGroundColor
	// Return:	The back ground color of ribbon bar.
	// Remarks:	Gets the back ground color of ribbon bar.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_COLORREF GetRibbonBarBackGroundColor(void);

	//************************************
	// Function:  GetRibbonBarBtnBackGroundColor
	// Param[in]: bIsHighlighted	Whether the button is highlighted.	
	// Param[in]: bIsPressed		Whether the button is pressed.	
	// Return:	The back ground color of ribbon bar button.
	// Remarks:	Gets the back ground color of ribbon bar button.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use.
	//************************************
	static FS_COLORREF GetRibbonBarBtnBackGroundColor(FS_BOOL bIsHighlighted, FS_BOOL bIsPressed);

	//************************************
	// Function:  LoadLibrary
	// Param[in]: lpwsFileName		Specifies the file name of library.	
	// Param[in]: nDirectoryType	The directory type.	
	// Return:	The library handle.
	// Remarks:	Load the library.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void* LoadLibrary(FS_LPCWSTR lpwsFileName, FRDirectoryType nDirectoryType);

	//************************************
	// Function:  IsCurDocShowInBrowser
	// Return:	  <a>TRUE</a> for running in browser, otherwise <a>FALSE</a>.
	// Remarks:   Tests whether the current document is opened in browser or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsCurDocShowInBrowser();

	//************************************
	// Function:  RemoveFileFromRecentFileList
	// Param[in]: nIndex	The index of recent opened file path to be removed.
	// Return:	  void.
	// Remarks:   Removes the recent opened file path from the list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppGetRecentFileList
	// See: FRAppAddFileToRecentFileList
	// See: FRAppClearRecentFileList
	//************************************
	static void RemoveFileFromRecentFileList(FS_INT32 nIndex);

	//************************************
	// Function:  CreateCustomRecentFileList
	// Param[in]: lpsRecentFileListName	The input custom recent file list name.
	// Param[in]: lpwsFileExt The extension of files that will be added to the recent file list.
	// Param[in]: pItemBitmap The icon that will be displayed in front of the recent file list label.
	// Param[in]: lpwsLabel The input label of recent file list.
	// Param[in]: nMaxSize The input max size of recent file list item.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Creates a custom recent file list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL CreateCustomRecentFileList(FS_LPCSTR lpsRecentFileListName, FS_LPCWSTR lpwsFileExt, FS_DIBitmap pItemBitmap, FS_LPCWSTR lpwsLabel, FS_INT32 nMaxSize);
	
	//************************************
	// Function:  RemoveFileFromCustomRecentFileList
	// Param[in]: lpsRecentFileListName The name that specifies the custom recent file list from which the recent file path will be removed.
	// Param[in]: lpwsFilePath			The recent file path that will be removed.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Removes the recent file path from the specified recent file list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppCreateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL RemoveFileFromCustomRecentFileList(FS_LPCSTR lpsRecentFileListName, FS_LPCWSTR lpwsFilePath);

	//************************************
	// Function:  AddFileToCustomRecentFileList
	// Param[in]: lpsRecentFileListName	The name that specifies the custom recent file list which the recent file path will be added to.
	// Param[in]: lpwsFilePath			The recent file path that will be added.
	// Param[in]: lpwsFileTitle			Instead of the file path, the title will be displayed in the recent file list.
	// Param[in]: lpwsFileTooltip		The tooltip of the recent file.
	// Param[in]: exeProc				When the recent file item is clicked, the callback will be invoked, unless you set it as NULL.
	// Param[in]: clientData			The client data that will be passed to the callback.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Adds the recent file to the custom recent file list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppCreateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL AddFileToCustomRecentFileList(FS_LPCSTR lpsRecentFileListName, FS_LPCWSTR lpwsFilePath, FS_LPCWSTR lpwsFileTitle, FS_LPCWSTR lpwsFileTooltip, FRAppCustomRecentFileExecuteProc exeProc, void* clientData);
	
	//************************************
	// Function:  ClearCustomRecentFileList
	// Param[in]: csRecentListName	The name that specifies the custom recent file list whose recent files will be cleared.
	// Return: void
	// Remarks: Clears the recent files from the recent file list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppCreateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static void ClearCustomRecentFileList(FS_LPCSTR lpsRecentFileListName);

	//************************************
	// Function:  RegisterMousePtHandler
	// Param[in]: callbacks		A structure containing the mouse point handler's callback functions.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Registers the mouse point handler.
	// Notes:
	// See: FRToolSetAssociatedMousePtHandlerType
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL RegisterMousePtHandler(FR_MousePtCallbacks callbacks);

	//************************************
	// Function:  UnRegisterMousePtHandler
	// Param[in]: callbacks		A structure containing the mouse point handler's callback functions.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Unregisters the mouse point handler and releases the memory.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL UnRegisterMousePtHandler(FR_MousePtCallbacks callbacks);

	//************************************
	// Function:  IsLicenseValidOrInTrial
	// Return:	  Checks whether the license is valid or is in trial.
	// Remarks:   Checks whether the license is valid or is in trial.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL IsLicenseValidOrInTrial();

	//************************************
	// Function:  ShowPreferenceDlg
	// Param[in]: lpwsTabTitle
	// Return:	  The result when user clicks ok button or cancel button.
	// Remarks:   Shows the preference dialog.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterPreferencePageHandler
	//************************************
	static FS_INT32 ShowPreferenceDlg(FS_LPCWSTR lpwsTabTitle);

	//************************************
	// Function:  UndoRedoIsEditing
	// Param[in]: frDoc	The specified document.
	// Return: <a>TRUE</a> means the document is being edited, otherwise not.
	// Remarks: Checks whether the document is being edited.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppAddUndoRedoItem
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL UndoRedoIsEditing(FR_Document frDoc);
	
	//************************************
	// Function:  UndoRedoBeginEdit
	// Param[in]: frDoc				The specified document.
	// Param[in]: pExitEditProc		The callback will be invoked when you exit the editing mode. Then you can release the data.
	// Param[in]: clientData		The client data passed to the exiting callback.
	// Return: void
	// Remarks: When you begin to edit detail content, such as text, and you don't want to save all the editing operation to save memory, 
	// you can invoke this interface. We call it the editing mode undo-redo control.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppAddUndoRedoItem
	// See: FRAppUndoRedoEndEdit
	// Deprecated: Internal use.
	//************************************
	static void UndoRedoBeginEdit(FR_Document frDoc, FRAppUndoRedoExitEditProc pExitEditProc, void* clientData);

	//************************************
	// Function:  UndoRedoEndEdit
	// Param[in]: frDoc	The specified document.
	// Return: void
	// Remarks: When you exit the editing mode, invoke this interface to exit the editing mode undo-redo control.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppAddUndoRedoItem
	// See: FRAppUndoRedoBeginEdit
	// Deprecated: Internal use.
	//************************************
	static void UndoRedoEndEdit(FR_Document frDoc);

	//************************************
	// Function:  RegisterWndProvider
	// Param[in]: callbacks	The input callbacks used to control the window, it tells you when to create the window handle, when to show the window, when to scroll the window, and so on.
	// Return: The returned value is reserved.
	// Remarks: Registers a window provider to create a window above the document view. 
	// There are already some windows above the document view, such as PDF view, text view, ruler view.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRDocSetCurrentWndProvider
	// See: FRDocGetCurrentWndProvider
	// See: FRAppUnRegisterWndProvider
	// Deprecated: Internal use.
	//************************************
	static void* RegisterWndProvider(FR_WndProviderCallbacks callbacks);

	//************************************
	// Function:  UnRegisterWndProvider
	// Param[in]: name	The input name of the window provider.
	// Return: <a>TRUE</a> means success, otherwise failure.
	// Remarks: Unregisters the window provider by name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterWndProvider
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL UnRegisterWndProvider(FS_LPCSTR name);

	//************************************
	// Function:  GetEditionType
	// Param[out]: outType	It receives the type value.
	// Return: void
	// Remarks: Gets the edition type. There are five types, Business, Standard, Express, Enterprise and Free.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use.
	//************************************
	static void	GetEditionType(FS_ByteString* outType);

	//************************************
	// Function:  GetRecentFileListSize
	// Return:	 The recent file list size. 
	// Remarks:  Gets the recent file list size.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRAppGetRecentFileList
	//************************************
	static FS_INT32 GetRecentFileListSize(void);

	//************************************
	// Function:  GetModuleFileName
	// Param[out]: outModuleFileName	The string buffer used to receive the module file name of application.
	// Return:	void
	// Remarks: Gets the module file name of application.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	//************************************
	static void GetModuleFileName(FS_WideString* outModuleFileName);

	//************************************
	// Function:  GetToolbarLocked
	// Return: <a>TRUE</a> means the toolbar is locked.
	// Remarks: Checks whether the toolbar is locked.
	// Notes: this functions is deprecated.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRAppSetToolbarLocked
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetToolbarLocked(void);

	//************************************
	// Function:  SetToolbarLocked
	// Param[in]: bLock			<a>TRUE</a> means the toolbar will be locked, otherwise not.
	// Param[in]: bRecalcLayout	<a>TRUE</a> means the layout of toolbar will be recalced, otherwise not. Sets it <a>TRUE</a> as default.
	// Return:	void
	// Remarks: Sets the toolbar to be locked or not.
	// Notes: this functions is deprecated.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRAppSetToolbarLocked
	// Deprecated: Internal use.
	//************************************
	static void SetToolbarLocked(FS_BOOL bLock, FS_BOOL bRecalcLayout);

	//************************************
	// Function:  RegisterCmdMsgEventHandler
	// Param[in]: callbacks	The input callbacks.
	// Return:	The cmd msg event handler can be used to unregister by <a>FRAppUnRegisterCmdMsgEventHandler</a>.
	// Remarks: Registers a callbacks called by the Foxit Reader to route and dispatch command messages and to handle the update of command user-interface objects, such as menu, toolbar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRAppUnRegisterCmdMsgEventHandler
	//************************************
	static void* RegisterCmdMsgEventHandler(FR_CmdMsgEventCallbacks callbacks);

	//************************************
	// Function:  UnRegisterCmdMsgEventHandler
	// Param[in]: cmdMsgEventHandler	The input cmd msg event handler returned by <a>FRAppRegisterCmdMsgEventHandler</a>.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Unregisters the input cmd msg event.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRAppRegisterCmdMsgEventHandler
	//************************************
	static FS_BOOL UnRegisterCmdMsgEventHandler(void* cmdMsgEventHandler);

	//************************************
	// Function:  RemoveTaskPanelByName
	// Param[in]: nameOfPaneView	The input name of task panel to be removed.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Removes the specified task panel.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRAppRegisterTaskPaneView
	// See: FRAppShowTaskPane
	// See: FRAppRemoveTaskPanelByName
	//************************************
	static FS_BOOL RemoveTaskPanelByName(FS_LPSTR nameOfPaneView);

	//************************************
	// Function:  DisableAllPanel
	// Param[in]: bDisable	<a>TRUE</a> means all the navigation panels will be disabled, otherwise not.
	// Param[in]: hFrameWnd	The child frame window. Set it as NULL to use the current child frame window.
	// Return: void
	// Remarks: Disables all the navigation panels or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	//************************************
	static void DisableAllPanel(FS_BOOL bDisable, HWND hFrameWnd);

	//************************************
	// Function:  IsDisableAllPanel
	// Param[in]: hFrameWnd	The child frame window. Set it as NULL to use the current child frame window.
	// Return: <a>TRUE</a> means all the panels are disabled, otherwise not.
	// Remarks: Checks whether all the panels are disabled.
	// Notes:
	// See: FRAppDisableAllPanel	
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	//************************************
	static FS_BOOL IsDisableAllPanel(HWND hFrameWnd);

	//************************************
	// Function:  GetPageContextMenuPos
	// Param[out]: outPoint	It receives the position.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: Gets the position of context menu on the page view.
	// Notes: It is only available in Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRAppRegisterForContextMenuAddition
	//************************************
	static FS_BOOL GetPageContextMenuPos(FS_DevicePoint* outPoint);

	//************************************
	// Function:  OnCmdMsgByName
	// Param[in]: lpsName		The name of menu or toolbar whose command messages need to be routed and dispatched.
	// Param[in]: nCode			References to <Italic>MFC CCmdTarget::OnCmdMsg</Italic>.
	// Param[in]: pExtra		References to <Italic>MFC CCmdTarget::OnCmdMsg</Italic>.
	// Param[in]: pHandlerInfo	It represents the <Italic>MFC</Italic> struct <Italic>AFX_CMDHANDLERINFO</Italic>.
	// Return: Nonzero if the message is handled; otherwise 0.
	// Remarks: Routes and dispatches command messages from plug-ins to plug-ins
	// Notes: This function is deprecated.
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL OnCmdMsgByName(FS_LPCSTR lpsName, FS_INT32 nCode, void* pExtra, void* pHandlerInfo);

	//************************************
	// Function:  SetOwnUndoMode
	// Param[in]: frDoc			The input document.
	// Param[in]: bOwnUndoMode	<a>TRUE</a> if you want to sets the own undo mode, otherwise not.
	// Return: void
	// Remarks: Sets the own undo mode.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRAppAddUndoRedoItem
	// See: FRAppUndoRedoIsEditing
	// See: FRAppUndoRedoBeginEdit
	// See: FRAppUndoRedoEndEdit
	// Deprecated: Internal use.
	//************************************
	static void	SetOwnUndoMode(FR_Document frDoc, FS_BOOL bOwnUndoMode);

	//************************************
	// Function:  ExitOwnUndoMode
	// Param[in]: frDoc	The input document.
	// Return: void	  
	// Remarks: Exits the own undo mode.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRAppAddUndoRedoItem
	// See: FRAppUndoRedoIsEditing
	// See: FRAppUndoRedoBeginEdit
	// See: FRAppUndoRedoEndEdit
	// Deprecated: Internal use.
	//************************************
	static void	ExitOwnUndoMode(FR_Document frDoc);

	//************************************
	// Function:  RegisterActionHandler
	// Param[in]: callbacks		The callbacks for action handler.
	// Return:	 <a>TRUE</a> means successful, otherwise not.
	// Remarks:	 Registers an action handler. The callbacks are called by Foxit Reader when the Foxit Reader will do the actions. You 
	// can implement your own process to customize the action process.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL RegisterActionHandler(FR_ActionHandlerCallbacks callbacks);

	//************************************
	// Function:  RedrawRecentFileList
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Redraws the recent file list in Ribbon mode.
	// Notes: This interface has been deprecated. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See: FRAppGetRecentFileList
	// See: FRAppAddFileToRecentFileList
	// See: FRAppClearRecentFileList
	//************************************
	static FS_BOOL RedrawRecentFileList(void);

	//************************************
	// Function:  SetCustomRecentFileListLabel
	// Param[in]: lpsRecentFileListName		The input custom recent file list name.
	// Param[in]: lpwsLabel					The input label of recent file list.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Sets the label of the custom recent file list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See: FRAppCreateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL SetCustomRecentFileListLabel(FS_LPCSTR lpsRecentFileListName, FS_LPCWSTR lpwsLabel);

	//************************************
	// Function:  SetCustomRecentFileListItemBitmap
	// Param[in]: lpsRecentFileListName		The input custom recent file list name.
	// Param[in]: pItemBitmap				The icon that will be displayed in front of the recent file list label.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Sets the icon that will be displayed in front of the recent file list label.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See: FRAppCreateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL SetCustomRecentFileListItemBitmap(FS_LPCSTR lpsRecentFileListName,  FS_DIBitmap pItemBitmap);

	//************************************
	// Function:  SetCustomRecentFileListMaxSize
	// Param[in]: lpsRecentFileListName		The input custom recent file list name.
	// Param[in]: nMaxSize					The input max size of recent file list item.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Sets the max size of recent file list item.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See: FRAppCreateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL SetCustomRecentFileListMaxSize(FS_LPCSTR lpsRecentFileListName,  FS_INT32 nMaxSize);

	//************************************
	// Function:  SetCustomRecentFileListItemTitle
	// Param[in]: lpsRecentFileListName		The input custom recent file list name.
	// Param[in]: nIndex					The index of the recent file list item.
	// Param[in]: lpwsFileTitle				The title of the recent file list item.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Sets the title of the recent file list item.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See: FRAppCreateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL SetCustomRecentFileListItemTitle(FS_LPCSTR lpsRecentFileListName,  FS_INT32 nIndex, FS_LPCWSTR lpwsFileTitle);

	//************************************
	// Function:  SetCustomRecentFileListItemTooltip
	// Param[in]: lpsRecentFileListName		The input custom recent file list name.
	// Param[in]: nIndex					The index of the recent file list item.
	// Param[in]: lpwsFileTooltip			The tooltip of the recent file.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Sets the tooltip of the recent file.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See: FRAppCreateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL SetCustomRecentFileListItemTooltip(FS_LPCSTR lpsRecentFileListName,  FS_INT32 nIndex, FS_LPCWSTR lpwsFileTooltip);
	
	//************************************
	// Function:  GetCustomRecentFileListItemCount
	// Param[in]: lpsRecentFileListName		The input custom recent file list name.
	// Return: The item count of the custom recent file list.
	// Remarks: Gets the item count of the custom recent file list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See: FRAppCreateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 GetCustomRecentFileListItemCount(FS_LPCSTR lpsRecentFileListName);

	//************************************
	// Function:  IsRTLLanguage
	// Return: TRUE if the current language of app is right-to-left, otherwise FALSE.
	// Remarks: Checks whether the current language of app is right-to-left or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_BOOL IsRTLLanguage(void);

	//************************************
	// Function:  GetOEMVersion
	// Param[out]: outOEMVersion	It receives the OEM version name. See <a>FROEMVersion</a>.
	// Return: void
	// Remarks: Gets the OEM version name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// Deprecated: internal use.
	//************************************
	static void GetOEMVersion(FS_ByteString* outOEMVersion);

	//************************************
	// Function:  RegisterDataCollectionHadler
	// Param[in]: callbacks	The callbacks for data collection handler.
	// Return: void
	// Remarks: Registers the data collection handler to collect the data as you need.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: FRAppCollectNormalData
	// Deprecated: Internal use.
	//************************************
	static void RegisterDataCollectionHadler(FR_DataCollectionHandlerCallbacks callbacks);

	//************************************
	// Function:  GetUIParentWndByTaskPane
	// Param[in]: taskPaneHwnd	The window handle of the task pane.
	// Return:	  The UI parent window handle.
	// Remarks:   Gets the UI parent window handle.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: FRAppRegisterTaskPaneView
	// Deprecated: Internal use.
	//************************************
	static FS_HWND GetUIParentWndByTaskPane(FS_HWND taskPaneHwnd);

	//************************************
	// Function:  AdvWndSetCustomize
	// Param[in]: bCustomize Whether to customize the advertisement.
	// Return:	  void.
	// Remarks:   Sets whether to customize the advertisement.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void AdvWndSetCustomize(FS_BOOL bCustomize);

	//************************************
	// Function:  GetAdvWnd
	// Return:	  The window handle to show the advertisement.
	// Remarks:   Gets the window handle to show the advertisement.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: 
	// Deprecated: Internal use.
	//************************************
	static HWND GetAdvWnd();

	//************************************
	// Function:  ShowAdvWnd
	// Param[in]: nAdvWidth	The width of the advertisement window. Sets it as 0 to hide the advertisement window.
	// Return:	  TRUE for success, otherwise failure.
	// Remarks:   Shows the advertisement window or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL ShowAdvWnd(FS_INT32 nAdvWidth);

	//************************************
	// Function:  RegisterPOEventHandler
	// Param[in]: callbacks	The input callbacks.
	// Return:	FS_LPVOID   Return the event handler.
	// Remarks: Registers a callbacks called by the Foxit Reader to do the page organizing, such as adding pages, deleting pages, replacing pages and so on.
	// Notes: Need to call FRAppUnRegisterPOEventHandler when after used.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: FRAppUnRegisterPOEventHandler
	//************************************
	static FS_LPVOID RegisterPOEventHandler(FR_POEventCallbacks callbacks);

	//************************************
	// Function:  CreateBlankDoc
	// Param[in]: fWidth	The width of the page in the blank document.
	// Param[in]: fHeight	The height of the page in the blank document.
	// Return:	The blank document.
	// Remarks: Creates a blank document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See: 
	//************************************
	static FR_Document CreateBlankDoc(FS_FLOAT fWidth, FS_FLOAT fHeight);

	//************************************
	// Function:  GetLocalFontName
	// Param[out]: outFontName	It receives the local font name.
	// Return:	The local font name.
	// Remarks: Gets the local font name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See: 
	//************************************
	static void GetLocalFontName(FS_WideString* outFontName);

	//************************************
	// Function:  ReLoadStartPage
	// Param[in]: lpwsPath	The input path of the start page.
	// Return:	void.
	// Remarks: Reloads the start page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void ReLoadStartPage(FS_LPCWSTR lpwsPath);

	//************************************
	// Function:  SetRecentFileListImageByExt
	// Param[in]: lpwsFileExt	The input file extension name, of which you want to change the image in the recent file list.
	// Param[in]: fileImage		The input image.
	// Return:	  True for success, otherwise failure.
	// Remarks:   Sets the image of the file in the recent file list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL SetRecentFileListImageByExt(FS_LPCWSTR lpwsFileExt, FS_DIBitmap fileImage);

	//************************************
	// Function:  GetCurMeasurementUnits
	// Return: The current measurement unites.
	// Remarks:	 Gets the current measurement unites. Related to <a>FR_MesasureUnit</a>
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 GetCurMeasurementUnits(void);

	//************************************
	// Function:  GetNavPanelViewByName
	// Param[in]: hChildfrm	The child frame the navigation panel belongs to. You can invoke <a>FRDocGetDocFrameHandler</a> to get the child frame.
	// Param[in]: lpsName	The input name of the navigation panel.
	// Return: The window handle of the navigation panel view.
	// Remarks: Gets the window handle of the navigation panel view.
	// Notes: This interface has been deprecated.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// See: FRAppAddNavPanelView
	// See: FRAppDisableAllPanel
	//************************************
	static HWND GetNavPanelViewByName(HWND hChildfrm, FS_LPCSTR lpsName);

	//************************************
	// Function:  GetNavPanelNameByIndex
	// Param[in]: nIndex	The input index of the navigation panel.
	// Param[out]: outName	It receives the name of the navigation panel.
	// Return: void.
	// Remarks: Gets the name of the navigation panel.
	// Notes: Only available in Windows
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// See: FRAppAddNavPanelView
	// See: FRAppDisableAllPanel
	//************************************
	static void GetNavPanelNameByIndex(FS_INT32 nIndex, FS_ByteString* outName);

	//************************************
	// Function:  GetNavPanelCount
	// Return: The count of the navigation panel.
	// Remarks: Gets the count of the navigation panel.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// See: FRAppaDDNavPanelView
	// See: FRAppDisableAllPanel
	//************************************
	static FS_INT32 GetNavPanelCount();

	//************************************
	// Function:  GetStartAppMode
	// Return: The app starting mode, 0 for not open any documents, and 1 for opening some documents at the same time.
	// Remarks: Gets the app starting mode, 0 for not open any documents, and 1 for opening some documents at the same time.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 GetStartAppMode();

	//************************************
	// Function:  RestartProcess
	// Param[in]: bReOpenFile	Whether to reopen the files or not.
	// Param[in]: bDelay		Whether to delay the request or not.
	// Return: void.
	// Remarks: Restarts the process of Foxit Reader or Foxit PhantomPDF.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// Deprecated: Internal use.
	//************************************
	static void RestartProcess(FS_BOOL bReOpenFile, FS_BOOL bDelay);

	//************************************
	// Function:  GetStatusBarBkGroundColor
	// Return: The back ground color of status bar.
	// Remarks: Gets the back ground color of status bar in ribbon mode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	//************************************
	static FS_COLORREF GetStatusBarBkGroundColor();

	//************************************
	// Function:  GetStatusBarBkGroundPath
	// Param[out]: outPath	It receives the path of the back ground color picture of the status bar in classic mode.
	// Return: void.
	// Remarks: Gets the path of the back ground color picture of the status bar in classic mode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// Deprecated: Internal use.
	//************************************
	static void GetStatusBarBkGroundPath(FS_WideString* outPath);

	//************************************
	// Function:  CountAllTypesVisibleDocuments
	// Return: The count of the visible documents of all types, including the start page.
	// Remarks: Gets the count of the visible documents of all types, including the start page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	//************************************
	static FS_INT32 CountAllTypesVisibleDocuments();

	//************************************
	// Function:  AddFileToCustomRecentFileList2
	// Param[in]: lpsRecentFileListName	The name that specifies the custom recent file list which the recent file path will be added to.
	// Param[in]: lpwsFilePath			The recent file path that will be added.
	// Param[in]: lpwsFileTitle			Instead of the file path, the title will be displayed in the recent file list.
	// Param[in]: lpwsFileTooltip		The tooltip of the recent file.
	// Param[in]: exeProc				When the recent file item is clicked, the callback will be invoked, unless you set it as NULL.
	// Param[in]: bEnableRemoveItem		Whether the item can be removed or not.
	// Param[in]: nPinned				The status of the pin, 0 for not pinned, 1 for pinned, 2 for not display the pin button.
	// Param[in]: clientData			The client data that will be passed to the callback.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Adds the recent file to the custom recent file list. Registers the Ribbon recent file event handler to catch the pinning and removing event, 
	// so that the plug-in can update the data layer.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: FRAppCreateCustomRecentFileList
	// See: FRAppRegisterRibbonRecentFileEventHandler
	// Deprecated: internal use.
	//************************************
	static FS_BOOL AddFileToCustomRecentFileList2(FS_LPCSTR lpsRecentFileListName, FS_LPCWSTR lpwsFilePath, FS_LPCWSTR lpwsFileTitle, FS_LPCWSTR lpwsFileTooltip, FRAppCustomRecentFileExecuteProc exeProc, FS_BOOL bEnableRemoveItem, FS_INT32 nPinned, void* clientData);

	//************************************
	// Function:  RegisterRibbonRecentFileEventHandler
	// Param[in]: callbacks	The input callbacks for Ribbon recent file list event handler.
	// Return:	The pointer to Ribbon recent file list event handler can be destroyed by <a>FRAppDestroyRibbonRecentFileEventHandler</a>.
	// Remarks: Registers a callbacks set for Ribbon recent file list event handler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: FRAppDestroyRibbonRecentFileEventHandler
	// Deprecated: internal use.
	//************************************
	static void* RegisterRibbonRecentFileEventHandler(FR_RibbonRecentFileEventCallbacks callbacks);

	//************************************
	// Function:  DestroyRibbonRecentFileEventHandler
	// Param[in]: eventHandler	The pointer to Ribbon recent file list event handler returned by <a>FRAppRegisterRibbonRecentFileEventHandler</a>.
	// Return:	void.
	// Remarks: Destroys the Ribbon recent file list event handler returned by <a>FRAppRegisterRibbonRecentFileEventHandler</a>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: FRAppRegisterRibbonRecentFileEventHandler
	// Deprecated: internal use.
	//************************************
	static void DestroyRibbonRecentFileEventHandler(void* eventHandler);

	//************************************
	// Function:  SetMetadataOption
	// Param[in]: bCompress	The input option value, true: compress, false: uncompress.
	// Return:	void.
	// Remarks: Sets the option to the document to control whether the metadata is to be compressed or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetMetadataOption(FS_BOOL bCompress);

	//************************************
	// Function:  SetSubscriptionProvider
	// Param[in]: callbacks	The input callbacks for subscription provider.
	// Return:	The pointer to subscription provider can be destroyed by <a>FRAppDestroySubscriptionProvider</a>.
	// Remarks: Registers a callbacks set for subscription provider.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: FRAppDestroySubscriptionProvider
	// Deprecated: Internal use.
	//************************************
	static void* SetSubscriptionProvider(FR_SubscriptionProviderCallbacks callbacks);

	//************************************
	// Function:  DestroySubscriptionProvider
	// Param[in]: subscriptionProvider	The pointer to subscription provider returned by <a>FRAppSetSubscriptionProvider</a>.
	// Return:	void.
	// Remarks: Destroys the subscription provider returned by <a>FRAppSetSubscriptionProvider</a>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: FRAppSetSubscriptionProvider
	// Deprecated: Internal use.
	//************************************
	static void DestroySubscriptionProvider(void* subscriptionProvider);

	//************************************
	// Function:  GetKeyfileStartAndExpireDate
	// Param[out]: outStartDate		It receives the start date.
	// Param[out]: outExpireDate	It receives the expire date.
	// Param[out]: outExpire		Whether the key file expired or not.
	// Return: TRUE for success, otherwise the key file does not exist or is invalid.
	// Remarks: Gets the start date and the expire date of the key file.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: 
	//************************************
	static FS_BOOL GetKeyfileStartAndExpireDate(FS_WideString* outStartDate, FS_WideString* outExpireDate, FS_BOOL* outExpire);

	//************************************
	// Function:  GetRibbonCategoryColor
	// Return:	The back ground color of ribbon category.
	// Remarks:	Gets the back ground color of ribbon category.	
	// Notes: Only available in Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	//************************************
	static FS_COLORREF GetRibbonCategoryColor(void);

	//************************************
	// Function:  GetRibbonElementColor
	// Param[out]: clrCheckButton		The color when the button is selected.
	// Param[out]: clrCheckHighlight	The color when the mouse is over the selected button.
	// Param[out]: clrHightButton		The color when the mouse is over the none-selected button.
	// Param[out]: clrPressButton		The color when the button is being clicked.
	// Return:	TRUE for success, otherwise failure.
	// Remarks:	Gets the back ground color of ribbon element.	
	// Notes: Only available in Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	//************************************
	static FS_BOOL GetRibbonElementColor(FS_COLORREF* clrCheckButton, FS_COLORREF* clrCheckHighlight, FS_COLORREF* clrHightButton, FS_COLORREF* clrPressButton);

	//************************************
	// Function:  GetRibbonBaseBorderColor
	// Return:	The back ground color of ribbon base border.
	// Remarks:	Gets the back ground color of ribbon base border.	
	// Notes: Only available in Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	//************************************
	static FS_COLORREF GetRibbonBaseBorderColor(void);

	//************************************
	// Function:  GetRecentFolderListSize
	// Return:	 The recent folder list size. 
	// Remarks:  Gets the recent folder list size.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	// See: FRAppGetRecentFileList
	//************************************
	static FS_INT32 GetRecentFolderListSize(void);

	//************************************
	// Function:  CreateEmptyFrameViewEventHandler
	// Param[in]: callbacks		The callbacks for the event handler of the empty frame window view.
	// Return:	The <a>FR_EmptyFrameWndViewEventHandler</a> object.
	// Remarks:	Creates the empty frame view event handler. Registers it through <a>FRAppCreateAnEmptyFrameWnd2</a>.Destroys it through <a>FRAppDestroyEmptyFrameViewEventHandler</a>;	
	// Notes: Only available in Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	// See: FRAppCreateAnEmptyFrameWnd2
	// See: FRAppDestroyEmptyFrameViewEventHandler
	// Deprecated: Internal use.
	//************************************
	static FR_EmptyFrameWndViewEventHandler CreateEmptyFrameViewEventHandler(FR_EmptyFrameWndViewEventHandlerCallbacks callbacks);

	//************************************
	// Function:  DestroyEmptyFrameViewEventHandler
	// Param[in]: eventHandler		The input event handler of the empty frame window view.
	// Return:	void.
	// Remarks:	Destroys the event handler of the empty frame window view
	// Notes: Only available in Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	// See: FRAppCreateAnEmptyFrameWnd2
	// See: FRAppCreateEmptyFrameViewEventHandler
	//Deprecated: Internal use.
	//************************************
	static void DestroyEmptyFrameViewEventHandler(FR_EmptyFrameWndViewEventHandler eventHandler);

	//************************************
	// Function:  CreateAnEmptyFrameWnd2
	// Param[in]: lpwsTitle			The title of the frame which will be created.
	// Param[in]: lpwsPathName		The input document path associated with the view.
	// Param[in]: eventHandler		The input empty frame window view event handler.
	// Param[in]: bCreatePanel		Whether to create the associated navigation panel or not. Sets it FALSE as default.
	// Param[in]: bMakeVisible		A flag indicate whether to show the frame.
	// Param[in]: bAddToMRU			Determines whether the file name is added to the most recently used (MRU) file list. Sets it FALSE as default.
	// Return:	  The handler of the newly created frame.
	// Remarks:   Creates a new frame window.
	// Notes:  Only available in Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	// See: FRAppCreateEmptyFrameViewEventHandler
	// See: FRAppDestroyEmptyFrameViewEventHandler
	// Deprecated: Internal use.
	//************************************
	static HWND CreateAnEmptyFrameWnd2(FS_LPCWSTR lpwsTitle,  FS_LPCWSTR lpwsPathName, FR_EmptyFrameWndViewEventHandler eventHandler, FS_BOOL bCreatePanel, FS_BOOL bMakeVisible, FS_BOOL bAddToMRU);

	//************************************
	// Function:  IsReadMode
	// Return: <a>TRUE</a> if Foxit Reader is in reading mode, otherwise not.
	// Remarks: Checks whether Foxit Reader is in reading mode or not.
	// Notes:  It only avaiable in Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRAppExitReadMode
	//************************************
	static FS_BOOL IsReadMode();

	//************************************
	// Function:  ExitReadMode
	// Return: void.
	// Remarks: Exits the reading mode.
	// Notes:  It only avaiable in Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRAppIsReadMode
	//************************************
	static void ExitReadMode();

	//************************************
	// Function:  GetCurrentChildFrm
	// Return: The current child frame handle.
	// Remarks: Gets the current child frame handle.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: 
	//************************************
	static HWND GetCurrentChildFrm();

	//************************************
	// Function:  CollectDocActionData
	// Param[in]: frDoc				The specified<a>FR_Document</a>.	
	// Param[in]: lpwsOperatorType	The specified operator type.
	// Param[in]: lpwsOperator		The operator value.
	// Param[in]: valueMap			The operator value map.
	// Return: void.
	// Remarks: The plug-in can invoke this interface to notify the other module to collect the action data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRDocOnDocCollectActionData
	// Deprecated: Internal use.
	//************************************
	static void CollectDocActionData(FR_Document frDoc, FS_LPCWSTR lpwsOperatorType, FS_LPCWSTR lpwsOperator, FS_MapPtrToPtr valueMap);

	//************************************
	// Function:  ActiveChildFrame
	// Param[in]: hChildFrame	The input child frame handle to be activated.	
	// Return: void.
	// Remarks: Activates the specified child frame.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: 
	//************************************
	static void ActiveChildFrame(HWND hChildFrame);

	//************************************
	// Function:  CollectNormalData
	// Param[in]: lpwsFunction		The function to be collected.
	// Param[in]: lpwsAction		The function to be collected.
	// Param[in]: lpwsContent		The content to be collected.
	// Return: void.
	// Remarks: Notifies the other modules to collect some normal data.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRAppRegisterDataCollectionHadler
	// Deprecated: Internal use.
	//************************************
	static void CollectNormalData(FS_LPCWSTR lpwsFunction, FS_LPCWSTR lpwsAction, FS_LPCWSTR lpwsContent);

	//************************************
	// Function:  SetMainframeShow
	// Param[in]: bShow		Whether the main frame will be shown or not when Foxit Reader starts up.
	// Return: void.
	// Remarks: Sets whether the main frame will be shown or not when Foxit Reader starts up.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: 
	//************************************
	static void SetMainframeShow(FS_BOOL bShow);

	//************************************
	// Function:  GetMainframeShow
	// Return: Whether the main frame will be shown or not when Foxit Reader starts up.
	// Remarks: Checks whether the main frame will be shown or not when Foxit Reader starts up.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: 
	//************************************
	static FS_BOOL GetMainframeShow();

	//************************************
	// Function:  GetRibbonTooltipBorderColor
	// Return:	The border color of the ribbon tooltip.
	// Remarks:	Gets the border color of the ribbon tooltip.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0.2
	//************************************
	static FS_COLORREF GetRibbonTooltipBorderColor(void);

	//************************************
	// Function:  GetRecentFileIndex
	// Param[in]: lpszPathName	The recent opened file path.
	// Param[in]: bFolder		Whether the path is a file or a folder.
	// Return:	  The index of the specified recent file.
	// Remarks:   Gets the index of the specified recent file.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
	// See: FRAppGetRecentFileList
	// See: FRAppAddFileToRecentFileList
	// See: FRAppClearRecentFileList
	// See: FRAppRemoveFileFromRecentFileList
	//************************************
	static FS_INT32 GetRecentFileIndex(FS_LPCWSTR lpszPathName, FS_BOOL bFolder);

	//************************************
	// Function:  FZipUnzip
	// Param[in]: lpszFZipPath	The input .fzip file path.
	// Param[in]: lpszDestPath	The dest path.
	// Return:	  TRUE for success, otherwise failure.
	// Remarks:   Unzips the .fzip file to the specified dest path.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
	//************************************
	static FS_BOOL FZipUnzip(FS_LPCWSTR lpszFZipPath, FS_LPCWSTR lpszDestPath);

	//************************************
	// Function:  IsJSEnabled
	// Return:	  TRUE if the javascript is enabled, otherwise FALSE.
	// Remarks:   Checks whether the javascript is enabled or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
	//************************************
	static FS_BOOL IsJSEnabled();

	//************************************
	// Function:  SetEnableJS
	// Param[in]: bEnable	Sets the javascript to be enabled or not.
	// Return:	  void.
	// Remarks:   Sets the javascript to be enabled or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
	//************************************
	static void SetEnableJS(FS_BOOL bEnable);

	//************************************
	// Function:  CollectNormalData2
	// Param[in]: lpwsFunction		The function to be collected.
	// Param[in]: lpwsAction		The function to be collected.
	// Param[in]: lpwsContent		The content to be collected.
	// Param[in]: nLevel			The detail level of the data.
	// Return: void.
	// Remarks: Notifies the other modules to collect some normal data.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.2.1
	// See: FRAppRegisterDataCollectionHadler
	// Deprecated: Internal use.
	//************************************
	static void CollectNormalData2(FS_LPCWSTR lpwsFunction, FS_LPCWSTR lpwsAction, FS_LPCWSTR lpwsContent, FS_INT32 nLevel);

	//************************************
	// Function:  CollectBitmapData
	// Param[in]: lpwsFunction		The function to be collected.
	// Param[in]: lpwsAction		The function to be collected.
	// Param[in]: pBitmap			The bitmap to be collected.
	// Param[in]: nLevel			The detail level of the data.
	// Return: void.
	// Remarks: Notifies the other modules to collect some bitmap data.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.2.1
	// See: FRAppRegisterDataCollectionHadler
	// Deprecated: Internal use.
	//************************************
	static void CollectBitmapData(FS_LPCWSTR lpwsFunction, FS_LPCWSTR lpwsAction, FS_DIBitmap pBitmap, FS_INT32 nLevel);

	//************************************
	// Function:  IsNeedCollectData
	// Return: TRUE if the cPDF data is need collected.
	// Remarks: Whether the cPDF data is need collected or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.2.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsNeedCollectData();

	//************************************
	// Function:  IsFipsMode
	// Return: TRUE if the system is in Federal Information Processing Standard environment.
	// Remarks: Whether the system is in Federal Information Processing Standard environment or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsFipsMode();

	//************************************
	// Function:  AddNavPanelView
	// Param[in]: panelViewCallbacks	A panel view callback set invoked by reader to add a panel view to navigation panel.
	// Param[in]: nPos				The position in the menu of navigation panel.
	// Return:    The returned value should be released by <a>FRAppReleaseNavPanelView</a>.
	// Remarks: Adds a navigation panel view into the Foxit Reader.
	// The navigation panel view can be added after reader has started up.
	// It usually used for dynamic add panel, like click some button to add panel view.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
	//************************************
	static void* AddNavPanelView(FR_PanelViewCallbacks panelViewCallbacks, FS_INT32 nPos);

	//************************************
	// Function:  ReleaseNavPanelView
	// Param[in]: pNavPanelView	Returned by <a>FRAppAddNavPanelView</a>.
	// Return:    void.
	// Remarks: Releases the navigation panel view returned by <a>FRAppAddNavPanelView</a>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
	//************************************
	static void ReleaseNavPanelView(void* pNavPanelView);

	//************************************
	// Function:  AddFileAttachment
	// Param[in]: frDoc	The specified document.
	// param[in]: lpwsAttachFilePath		The file path for add.
	// Return:    Non-zero means succeed, otherwise failure.
	// Remarks: Add a embed file to current document with The file path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	//************************************
	static FS_BOOL AddFileAttachment(FR_Document frDoc, FS_LPCWSTR lpwsAttachFilePath);
	//************************************
	// Function:  OpenFileAttachment
	// Param[in]: pDict	The FileAttachment dictionary.
	// param[in]: nPage		The Page index.
	// param[in]: bAnnot	Is FileAttachment Annot.
	// Return:    Non-zero means succeed, otherwise failure.
	// Remarks: open a embed file.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.5
	//************************************
	static FS_BOOL OpenFileAttachment(FPD_Object pDict, FS_INT32 nPage, FS_BOOL bAnnot, FS_LPCWSTR wsFileName);

	//************************************
	// Function:  IsPDF2Doc
	// Param[in]: pSourDoc	The specified document.
	// Return:    TRUE: the encrypt revision is greater than or equal to 5.
	// Remarks:   Check the revision of the standard security handler is greater than or equal to 5.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	//************************************
	static FS_BOOL IsPDF2Doc(FPD_Document pSourDoc);

	//************************************
	// Function:  ConvertToPDF
	// Param[in]: lpwsFile	The Original File.
	// Param[in]: lpwsDest	The Dest File.
	// Param[in]: hWnd		The hWnd,default NULL.
	// Param[in]: bShowProgressBar	If show the progress bar.
	// Param[in]: bConvertToCPDF	If need convert to CPDF File.
	// Param[in]: bDelDestFile	If need delete the Dest File when convert failed.
	// Return:    zero means successful, otherwise failed.
	// Remarks:   convert file to Pdf file.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// See: FRAppConvertToPDFA
	//************************************
	static FS_INT32 ConvertToPDF(FS_LPCWSTR lpwsFile, 
		FS_LPCWSTR lpwsDest,
		HWND hWnd, 
		FS_BOOL bShowProgressBar, 
		FS_BOOL bConvertToCPDF,
		FS_BOOL bDelDestFile);

	//************************************
	// Function:  RegisterPDFAPluginHandler
	// Param[in]: pdfaPluginHandlerCallbacks The callback set. Reader will call a corresponding callback when save to pdfa occurs.
	// Return:	 <a>TRUE</a> means successful, otherwise not.
	// Remarks: The callbacks of pdfa Handler just be called while the document was saved to pdfa.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL RegisterPDFAPluginHandler(FR_PDFAPluginHandlerCallbacks pdfaPluginHandlerCallbacks);

	//************************************
	// Function:  ConvertToPDFA
	// Param[in]: frDoc The specified document.
	// Param[in]: fswsSaveAsFileName The dest document path to be saved.
	// Param[in]: pVersion The PDFA version to be converted.
	// Return:	 Zero means successful, otherwise failed.
	// Remarks: Converts file to PDFA file.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// See: FRAppConvertToPDF
	//************************************
	static FS_INT32 ConvertToPDFA(FR_Document frDoc, const FS_WideString fswsSaveAsFileName, const FRPDFA_PDFVersion pVersion);

	//************************************
	// Function:  AddLog
	// Param[in]: nLevel	The specified log level.
	// Param[in]: wsMsg		The input log message.
	// Param[in]: file		The file where the log is added. Use __FILE__ as default.
	// Param[in]: nLine		The code line where the log is added. Use __LINE__ as default.
	// Param[in]: function	The function where the log is added. use __FUNCTION__ as default.
	// Return:    void.
	// Remarks: Outputs log information.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// Deprecated: Internal use.
	//************************************
	static void AddLog(FR_LOG_LEVEL nLevel, FS_WideString wsMsg, const FS_CHAR* file, FS_INT32 nLine, const FS_CHAR* function);

	//************************************
	// Function:  IsReaderOnlyMode
	// Param[in]: hWnd
	// Return:
	// Remarks:
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsReaderOnlyMode(HWND hWnd);

	//************************************
	// Function:  GetMainFrameWndCount
	// Return:
	// Remarks:
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 GetMainFrameWndCount();

	//************************************
	// Function:  GetMainFrameWndByIndex
	// Param[in]: nIndex
	// Return:
	// Remarks: Get MainFrameWnd by index
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// See: FRAppGetMainFrameWndByIndex
	// Deprecated: Internal use.
	//************************************
	static void* GetMainFrameWndByIndex(FS_INT32 nIndex);

	//************************************
	// Function:  GetModelessParentWnd
	// Return:
	// Remarks: Get modeless parent HWnd
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// Deprecated: Internal use.
	//************************************
	static HWND	GetModelessParentWnd();

	//************************************
	// Function:  IsMainfrmActivating
	// Param[in]: hWnd
	// Return:
	// Remarks: Check mainframe is activating
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// Deprecated: Internal use.
	//************************************
	static BOOL IsMainfrmActivating(HWND hWnd);

	//************************************
	// Function:  GetRibbonBar2
	// Param[in]: hWnd	A handle to the parent window. It represents the <Italic>MFC HWND</Italic>. Sets it to NULL as default.
	// You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	// Return:	The ribbon bar.
	// Remarks:	Gets Foxit Reader's ribbon bar.  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	//************************************
	static FR_RibbonBar	GetRibbonBar2(HWND hWnd);

	//************************************
	// Function:  RefreshLayerPanelView
	// Param[in]: pCpdfDoc
	// Return:
	// Remarks: Refresh Layer Panel
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// Deprecated: Internal use.
	//************************************
	static void RefreshLayerPanelView(FPD_Document pCpdfDoc);

	//************************************
	// Function:  DeprecatedRegisterDRMSecurityHandler
	// Param[in]: name		The name of the security handler.
	// Param[in]: callbacks The structure containing the security handler callback functions.
	// Return:	void
	// Remarks: Registers a security handler. Invoked this interface to process the PDF documents that 
	// are encrypted by customer security handler.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.5
	// Notes:
	// See: FRAppUnRegisterSecurityHandler
	// Deprecated: Internal use.
	//************************************
	static void			DeprecatedRegisterDRMSecurityHandler(FS_LPCSTR name, FS_LPVOID callbacks);

	//************************************
	// Function:  AddECMFileDialog
	// Param[in]: lpwsPluginName		The plugin name.
	// Param[in]: lpwsPluginHftName		The plugin HFT name.
	// Param[in]: lpwsTitle		Plugin title displayed on filedialog.
	// Param[in]: openproc		If filedailog is open style, callback when selecting ECM menu item.
	// Param[in]: saveproc		If filedailog is save style, callback when selecting ECM menu item.
	// Param[in]: clientdata	A pointer to user-supplied data. Used in <a>FRAppFileDialogECMOpenProc, FRAppFileDialogECMSaveProc</a>.
	// Return:	void
	// Remarks: Add an ECM plugin that needs to be displayed in fileDialog.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppAddECMFileDialog
	// Deprecated: Internal use.
	//************************************
	static void			AddECMFileDialog(FS_LPCWSTR lpwPluginName, 
										FS_LPCWSTR lpwPluginHftName, 
										FS_LPCWSTR lpwTitle, 
										FRAppFileDialogECMOpenProc openproc, 
										FRAppFileDialogECMSaveProc saveproc,
										void* clientdata);

	//************************************
	// Function:  ECMFileDialogAddMenuItem
	// Param[in]: pFileDialog		adds ECM menu, menu item depends on <a>FRAppAddECMFileDialog</a>.
	// Param[in]: type		FileDialog style attribute, see the value of <a>FRCCDFileDialogType</a>.
	// Return:	void
	// Remarks: FileDialog adds ECM menu, menu item depends on <a>FRAppAddECMFileDialog</a>.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppECMFileDialogAddMenuItem
	// Deprecated: Internal use.
	//************************************
	static void			ECMFileDialogAddMenuItem(void* pFileDialog, FRDECMFileDialogType type);

	//************************************
	// Function:  ECMFileDialogItemSelected
	// Param[in]: wsSrcFilePath		Source file path. Used when FRDECMFileDialogType is Save style.
	// Param[in]: pFileDialog		CFileDialog pointer.
	// Param[in]: pIFileDialog		IFileDialog pointer.
	// Param[in]: dwIDCtl		The ID of the container control.
	// Param[in]: dwIDItem		The ID of the item.
	// Param[in]: type			FileDialog style attribute, see the value of <a>FRCCDFileDialogType</a>.
	// Param[out]: bViewExportResult	<a>TRUE</a>Open the export result. Only for the case where <FRDECMFileDialogType> is FR_ECMFileDialog_Save_Export.
	// Return:	void
	// Remarks: Select the ECM menu, you need to call in CFileDialog::OnItemSelected.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppECMFileDialogItemSelected
	// Deprecated: Internal use.
	//************************************
	static void			ECMFileDialogItemSelected(FS_LPCWSTR wsSrcFilePath,
									void* pFileDialog, 
									void* pIFileDialog, 
									DWORD dwIDCtl, DWORD dwIDItem, 
									FRDECMFileDialogType type,
									FS_BOOL bViewExportResult);

	//************************************
	// Function:  GetECMFileDialog
	// Param[in]: type FileDialog style attribute, see the value of <a>FRCCDFileDialogType</a>.
	// Param[in]: lpszSrcFilePath  Source file path. Used when FRDECMFileDialogType is Save style.
	// Param[in]: bOpenFileDialog Refer to the <a>CFileDialog</a> constructor.
	// Param[in]: lpszDefExt Refer to the <a>CFileDialog</a> constructor.
	// Param[in]: lpszFileName Refer to the <a>CFileDialog</a> constructor.
	// Param[in]: dwFlags Refer to the <a>CFileDialog</a> constructor.
	// Param[in]: lpszFilter Refer to the <a>CFileDialog</a> constructor.
	// Param[in]: pParentWnd Refer to the <a>CFileDialog</a> constructor.
	// Param[in]: dwSize Refer to the <a>CFileDialog</a> constructor.
	// Param[in]: bVistaStyle Refer to the <a>CFileDialog</a> constructor.
	// Return:	void
	// Remarks:  Get the CFileDialog containing the ECM menu.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppGetECMFileDialog
	// Deprecated: Internal use. 
	//************************************
	static void*		GetECMFileDialog(FRDECMFileDialogType type, FS_LPCWSTR wsSrcFilePath, 
										BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
										FS_LPCWSTR lpszDefExt,
										FS_LPCWSTR lpszFileName,
										DWORD dwFlags,
										FS_LPCWSTR lpszFilter,
										void* pParentWnd,
										DWORD dwSize,
										BOOL bVistaStyle);
	//************************************
	// Function: GetSelectedECMPluginName
	// Param[in]: pFileDialog CFileDialog pointer.
	// Param[out]: outPluginName PluginName.
	// Return: void
	// Remarks: Get the selected ECM plugin name.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppGetSelectedECMPluginName
	// Deprecated: Internal use.
	//************************************
	static void GetSelectedECMPluginName(void* pFileDialog, FS_WideString* outPluginName);

	//************************************
	// Function:  GetMainClientAreaWnd
	// Param[in]: hMainframe	the main frame window of Foxit Reader.
	// Return:	A <Italic>HWND</Italic> object for windows client area.
	// Remarks:	Gets the main frame window client area of Foxit Reader.
	//Since: <a>SDK_LATEEST_VERSION< / a> > 10.0
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static HWND	GetMainClientAreaWnd(HWND hMainframe);

	//************************************
	// Function:  RegisterPortfolioEventHandler
	// Param[in]: portfolioDocEventCallbacks	The callback set. Reader will call a corresponding callback when the doc event occurs.
	// Return:	 <a>TRUE</a> means successful, otherwise not.
	// Remarks:	 Registers a user-supplied event handler to document window. 	
	// Notes: The callbacks of FR Doc Event Handler just be called while the document window is displaying PDF file type.
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL		RegisterPortfolioEventHandler(FR_PortfolioEventCallbacks portfolioDocEventCallbacks);

	//************************************
	// Function:  AddECMUploadProc
	// Param[in]: lpwsPluginName		The plugin name.
	// Param[in]: lpwsPluginHftName		The plugin HFT name.
	// Param[in]: lpwsTitle		Plugin title displayed on filedialog.
	// Param[in]: uploadproc	callback is called when ECM plugin needs to upload.
	// Param[in]: clientdata	A pointer to user-supplied data. Used in <a>FRAppFileDialogECMUploadProc</a>.
	// Return:	void
	// Remarks: an ECM plugin needs to upload file.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppAddECMFileDialog
	// Deprecated: Internal use.
	//************************************
	static void AddECMUploadProc(FS_LPCWSTR lpwPluginName,
		FS_LPCWSTR lpwPluginHftName,
		FS_LPCWSTR lpwTitle,
		FRAppFileDialogECMUploadProc uploadproc,
		void* clientdata);

	//************************************
	// Function:  GetConvertPDFErrMsg
	// Param[in]: nerror nerror The error code from <a>FRAppConvertToPDF</a>
	// Param[out]: outErrorMsg error msg.
	// Remarks:   get convert file err msg.
	// Return:	void
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// See: FRAppConvertToPDF
	//************************************
	static void GetConvertPDFErrMsg(FS_INT32 nerror, FS_WideString* outErrorMsg);

	//************************************
	// Function:  ECMFileDialogUploadProc
	// @param[in] wsSrcFilePath	The source file path.
	// @param[in] wsNewFilePath	The new file path.
	// @param[in] type			The specified file dialog type.
	// @param[in] bUpload		<a>TRUE< / a> upload file to ECM, otherwise not.
	// Remarks:   notify plugin to do upload proc.
	// Return:	void
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// See: FRAppECMFileDialogUploadProc
	// Deprecated: Internal use.
	//************************************
	static void ECMFileDialogUploadProc(FS_LPCWSTR wsSrcFilePath, FS_LPCWSTR wsNewFilePath, FRDECMFileDialogType type, FS_BOOL bUpload);

	//************************************
	// Function:  ECMFileDialogRemoveMenuItem
	// Param[in]: pFileDialog		rempve ECM menu, menu item depends on <a>FRAppAddECMFileDialog</a>.
	// Param[in]: wsPluginName		The plugin name.
	// Return:	void
	// Remarks: FileDialog Remove ECM menu, menu item depends on <a>FRAppAddECMFileDialog</a>.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppECMFileDialogRemoveMenuItem
	// Deprecated: Internal use.
	//************************************
	static void ECMFileDialogRemoveMenuItem(void* pFileDialog, FS_LPCWSTR wsPluginName);

	//************************************
	// Function:  CollectSensorData
	// Param[in]: sensorData	the Data of Sensor that depends on <a>FR_SensorData</a>.
	// Return:	void
	// Remarks: .
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppCollectSensorData
	// Deprecated: Internal use.
	//************************************
	static void CollectSensorData(FR_SensorData sensorData);

	//************************************
	// Function:  GetSystemHandler	
	// Return:	FR_SystemHandler, the actual type is CSH_SystemHandler*
	// Remarks: Get window::IFX_SystemHandler obj from phantom<a>FRAppGetSystemHandler</a>.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppGetSystemHandler
	// Deprecated: Internal use.
	//************************************
	static FR_SystemHandler GetSystemHandler();

	//************************************
	// Function:  CreateAndRegisterFormDesignerToolHandler	
	// Param[in]: eFieldType	Esign filed type.
	// Param[in]: lpToolName	Esign tool name.
	// Param[in]: lpToolLabel	Esign tool label.
	// Param[in]: lpReg	        The reg data of esign.
	// Param[in]: dwFieldFlags	The flags of field.
	// Return:	void
	// Remarks: RegisterToolHandler of formfield,that's for esgin.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppCreateAndRegisterFormDesignerToolHandler
	// Deprecated: Internal use.
	//************************************
	static void  CreateAndRegisterFormDesignerToolHandler(FS_INT32 eFieldType, FS_LPCSTR lpToolName, FS_LPCWSTR lpToolLabel, FS_LPCWSTR lpReg, FS_DWORD dwFieldFlags);

	//************************************
	// Function:  ShowModuleNoLicenseDlg	
	// Param[in]: csModule       module name.	
	// Return:	void
	// Remarks: FRAppShowModuleNoLicenseDlg shows module no license dialog.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppShowModuleNoLicenseDlg
	// Deprecated: Internal use.
	//************************************
	static void	ShowModuleNoLicenseDlg(FS_WideString csModule);

	//************************************
	// Function:  DeleteAnnot	
	// Param[in]: pAnnot       the annot need to delete.	
	// Return:	void
	// Remarks: FRAppDeleteAnnot used to delete annot from IReader_AnnotHandlerMgr .
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppDeleteAnnot
	//************************************
	static void DeleteAnnot(FR_Annot pAnnot);

	//************************************
	// Function:  DoModulePreferDlg	
	// Param[in]: csTabTitle     The tab tile of the preferdlg.	
	// Param[in]: pParent        The pParent of the preferdlg.	
	// Return:	FS_INT32
	// Remarks: FRAppDoModulePreferDlg used to show module prefer dialog.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppDoModulePreferDlg
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 DoModulePreferDlg(FS_WideString csTabTitle, FS_LPVOID pParent);	

	//************************************
	// Function:  RegisterAnnotHandler	
	// Param[in]: annotHandler     annot callback register to IBaseAnnot.	
	// Return:	void
	// Remarks: FRAppRegisterAnnotHandler used to register annothanlder to IBaseAnnot.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppRegisterAnnotHandler
	// Deprecated: Internal use.
	//************************************
	static void  RegisterAnnotHandler(FR_BAAnnotHandler annotHandler);

	//************************************
	// Function:  AddUndoItemCRSA	
	// Param[in]: doc        The current document.	
	// Param[in]: pageview    The current page view, that is IReader_PageViewer.	
	// Param[in]: annot     The annot need to add undo item oprea.	
	// Param[in]: dtOld     The old datetime.	
	// Param[in]: dtNew     The new datetime.
	// Param[in]: rcOld     The old rect.
	// Param[in]: rcNew     The new rect.	
	// Return:	void
	// Remarks: FRAppAddUndoItemCRSA used to add undo item of CRSA.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppAddUndoItemCRSA
	// Deprecated: Internal use.
	//************************************
	static void  AddUndoItemCRSA(FR_Document doc, FR_PageView pageview, FR_Annot annot,FS_ReaderDateTime dtOld, FS_ReaderDateTime dtNew,FS_FloatRect rcOld, FS_FloatRect rcNew);
	
	//************************************
	// Function:  BaseAnnotLoadCursor	
	// Param[in]: nCursorType        The cursor type of the annot.
	// Return:	void
	// Remarks: FRAppBaseAnnotLoadCursor used to load cursor of the annot.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppBaseAnnotLoadCursor
	// Deprecated: Internal use.
	//************************************
	static FR_Cursor BaseAnnotLoadCursor(FS_INT32 nCursorType);

	//************************************
	// Function:  AddDragPoint	
	// Param[in]: pPageView    The current page view.
	// Param[in]: point        The location of drag point.
	// Param[in]: nFlag        The flag of drag point.
	// Param[in]: nDrawMode    The drawmode of drag point.
	// Return:	void
	// Remarks: FRAppAddDragPoint used to add drag point.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppAddDragPoint
	// Deprecated: Internal use.
	//************************************
	static void AddDragPoint(FR_PageView pPageView, const FS_DevicePoint& point, FS_INT32 nFlag, FS_INT32 nDrawMode);

	//************************************
	// Function:  GetSystemDefaultFont	
	// Param[in]: lf    The system default font	.
	// Return:	void
	// Remarks: FRAppGetSystemDefaultFont used to get system default font.
	// Notes:
	// See:  FRAppGetSystemDefaultFont
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static void GetSystemDefaultFont(LOGFONT* lf);

	//************************************
	// Function:  GetRSAAnnotElement	
	// Param[in]: pPDFDoc    The document in which the annotation is located.	
	// Param[in]: pAnnot     The RSA annot obj
	// Return:	FS_XMLElement
	// Remarks: FRAppGetRSAAnnotElement used to get RSAAnnot element.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppGetRSAAnnotElement
	// Deprecated: Internal use.
	//************************************
	static FS_XMLElement GetRSAAnnotElement(FPD_Document pPDFDoc, FR_Annot pAnnot);

	//************************************
	// Function:  GetPopupElement	
	// Param[in]: pPDFDoc    The document in which the annotation is located.	
	// Param[in]: pAnnot     The RSA annot obj
	// Return:	FS_XMLElement
	// Remarks: FRAppGetPopupElement used to get popup element.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppGetPopupElement
	// Deprecated: Internal use.
	//************************************
	static FS_XMLElement GetPopupElement(FPD_Document pPDFDoc, FR_Annot pAnnot);

	//************************************
	// Function:  GetJSEngineHRuntime	
	// Return:	FSJSE_HRUNTIME
	// Remarks: FRAppGetJSEngineHRuntime used to get JS engin.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppGetJSEngineHRuntime
	// Deprecated: Internal use.
	//************************************
	static FSJSE_HRUNTIME GetJSEngineHRuntime();

	//************************************
	// Function:  UnRegisterDocHandlerOfPDDoc	
	// Param[in]: docEventCallbacks    The document event callback.	
	// Return:	FS_BOOL
	// Remarks:  Unregisters a user-supplied event handler to document window.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppRegisterDocHandlerOfPDDoc
	//************************************
	static FS_BOOL	UnRegisterDocHandlerOfPDDoc(FR_DocEventCallbacks docEventCallbacks);

	//************************************
	// Function:  GetOperatorPermission		
	// Return:	FS_BOOL
	// Remarks: FRAppGetOperatorPermission used to get operation permission.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppGetOperatorPermission
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetOperatorPermission();	

	//************************************
	// Function:  GetHContext	
	// Param[in]: frDoc    The current document.	
	// Return:	FSJSE_HCONTEXT
	// Remarks: FRAppGetHContext used to get JS HCONTEXT.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppGetHContext
	// Deprecated: Internal use.
	//************************************
	static FSJSE_HCONTEXT GetHContext(FR_Document frDoc);

	//************************************
	// Function:  JSGetGlobalObject	
	// Param[in]: hContext    The JS HCONTEXT.	
	// Return:	FSJSE_HVALUE
	// Remarks: FRAppJSGetGlobalObject used to get global object.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppJSGetGlobalObject
	// Deprecated: Internal use.
	//************************************
	static FSJSE_HVALUE JSGetGlobalObject(FSJSE_HCONTEXT hContext);

	//************************************
	// Function:  JSSetUndefined	
	// Param[in]: hValue    The JS HVALUE.	
	// Return:	void
	// Remarks: FRAppJSSetUndefined is to call  FXJSE_Value_SetUndefined.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppJSSetUndefined
	// Deprecated: Internal use.
	//************************************
	static void JSSetUndefined(FSJSE_HVALUE hValue);

	//************************************
	// Function:  JSSetUndefined	
	// Param[in]: hValue    The JS HVALUE.	
	// Param[in]: hOriginalValue    The origin JS HVALUE.	
	// Return:	void
	// Remarks: FRAppJSValueSet is to call FXJSE_Value_Set.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppJSValueSet
	// Deprecated: Internal use.
	//************************************
	static void JSValueSet(FSJSE_HVALUE hValue, FSJSE_HVALUE hOriginalValue);

	//************************************
	// Function:  JSValueRelease	
	// Param[in]: hValue    The JS HVALUE.	
	// Return:	void
	// Remarks: FRAppJSValueRelease is to call FXJSE_Value_Release.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppJSValueRelease
	// Deprecated: Internal use.
	//************************************
	static void JSValueRelease(FSJSE_HVALUE hValue);

	//************************************
	// Function:  RegisterTransitionHandler	
	// Param[in]: callbacks    The transition handler.	
	// Return:	FS_BOOL
	// Remarks: callbacks is derived on CReader_TransHandler.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL RegisterTransitionHandler(FR_TransitionCallbacks callbacks);

	//************************************
	// Function:  GetPreferenceIdentity	
	// Param[in]: doc    The current document.	
	// Param[in]: info   The identify info of the document.
	// Return:	void
	// Remarks: get document's Preference Identity info
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppGetPreferenceIdentity
	// Deprecated: Internal use.
	//************************************
	static void GetPreferenceIdentity(FR_Document doc, FR_IdentityInfo &info);

	//************************************
	// Function:  JSRuntimeNewContext	
	// Param[in]: doc    The current document.	
	// Return:	FS_LPVOID
	// Remarks: return value is IJS_Context type
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppJSRuntimeNewContext
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID JSRuntimeNewContext(FR_Document doc);

	//************************************
	// Function:  JSRuntimeReleaseContext	
	// Param[in]: doc    The current document.	
	// Return:	void
	// Remarks: Release JS Runtime context
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppJSRuntimeReleaseContext
	// Deprecated: Internal use.
	//************************************
	static void JSRuntimeReleaseContext(FR_Document doc);

	//************************************
	// Function:  IsRunIPFrame		
	// Return:	FS_BOOL
	// Remarks: Get is run IP frame 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes: The function can only be used for Windows.
	// See:  FRAppIsRunIPFrame
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	IsRunIPFrame();

	//************************************
	// Function:  OwnerFileTypeHandlerDoEmail	
	// Param[in]: csFDFFile    the cpdf file path.	
	// Return:	FS_BOOL
	// Remarks: OwnerFileTypeHandler send email.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppOwnerFileTypeHandlerDoEmail
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL OwnerFileTypeHandlerDoEmail(FS_WideString csFDFFile);

	//************************************
	// Function:  GetEmailTabDocInfo	
	// Param[in]: readerDocEx    the current document	
	// Param[out]: wsPath    the doc path.	
	// Param[out]: wsName    the doc name.	
	// Return:	FS_BOOL
	// Remarks: Get Email doc Info
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppGetEmailTabDocInfo
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetEmailTabDocInfo(FR_Document readerDocEx, FS_WideString* wsPath, FS_WideString* wsName);

	//************************************
	// Function:  GetAULIBCurrentLanguage	
	// Param[out]: wsLan    the current AUI language
	// Return:	void
	// Remarks: Get current AUI language.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See:  FRAppGetAULIBCurrentLanguage
	// Deprecated: Internal use.
	//************************************
	static void GetAULIBCurrentLanguage(FS_WideString* wsLan);

	//************************************
	// Function:  GetIsEmailChoosePageRange	
	// Return:	FS_BOOL
	// Remarks: Whether the select page dialog box will pop up when sending the current mail.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes: The function can only be used for Windows.
	// See:  FRAppGetIsEmailChoosePageRange
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetIsEmailChoosePageRange();

	//************************************
	// Function:  AddECMFileDialog2
	// Param[in]: lpwsPluginName		The plugin name.
	// Param[in]: lpwsPluginHftName		The plugin HFT name.
	// Param[in]: lpwsTitle		Plugin title displayed on filedialog.
	// Param[in]: openproc		If filedailog is open style, callback when selecting ECM menu item.
	// Param[in]: saveproc		If filedailog is save style, callback when selecting ECM menu item.
	// Param[in]: clientdata	A pointer to user-supplied data. Used in <a>FRAppFileDialogECMOpenProc, FRAppFileDialogECMSaveProc</a>.
	// Return:	void
	// Remarks: Add an ECM plugin that needs to be displayed in fileDialog.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes: The function can only be used for Windows.
	// See: FRAppAddECMFileDialog2
	// Deprecated: Internal use.
	//************************************
	static void AddECMFileDialog2(FS_LPCWSTR lpwPluginName, FS_LPCWSTR lpwPluginHftName, FS_LPCWSTR lpwTitle,
		FRAppFileDialogECMOpenProc2 openproc,
		FRAppFileDialogECMSaveProc saveproc, void* clientdata);

	//************************************
	// Function:  IsEditingUseHindiDigits	
	// Return:	FS_BOOL
	// Remarks: Is Editing Use Hindi Digits mode.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes: The function can only be used for Windows.
	// See: FRAppIsEditingUseHindiDigits
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL   IsEditingUseHindiDigits();

	//************************************
	// Function:  CountTaskPaneName	
	// Return:	FS_INT32
	// Remarks: Get the count of the right task panel.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppGetTaskPaneNameByIndex
	//************************************
	static  FS_INT32 CountTaskPaneName();

	//************************************
	// Function:  GetTaskPaneNameByIndex	
	// Param[in]: nIndex		    The index of FRAppCountTaskPaneName.
	// Param[out]: outPanelName		Get the right panel name by the specified index.
	// Return:	void
	// Remarks: Get name of the right task panel by index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static  void  GetTaskPaneNameByIndex(FS_INT32 nIndex,FS_ByteString* outPanelName);

	//************************************
	// Function:  GetDocUnit	
	// Return:	FS_INT32
	// Remarks: Get unit of doc.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppGetDocUnit
	//************************************
	static FS_INT32    GetDocUnit();

	//************************************
	// Function:  ChangeUnits	
	// Param[in]: fSrc		    The origin unit.
	// Param[in]: nSrcType		The source type.
	// Param[in]: nDestType		The dest type.
	// Return:	FS_FLOAT
	// Remarks: Change unit of doc.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppChangeUnits
	//************************************
	static FS_FLOAT    ChangeUnits(FS_FLOAT fSrc, FS_INT32 nSrcType, FS_INT32 nDestType);

	//************************************
	// Function:  GetSelectedECMPluginAccount	
	// Param[in]: pFileDialog		    the CFileDialog containing the ECM menu, menu item depends on <a>FRAppAddECMFileDialog</a>.
	// Param[in]: outPluginAccount		The ecm accout info.
	// Return:	void
	// Remarks: Get selected ECM Plugin Account
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppGetSelectedECMPluginAccount
	// Deprecated: Internal use.
	//************************************
	static void GetSelectedECMPluginAccount(void* pFileDialog, FS_WideString* outPluginAccount);

	//************************************
	// Function:  AddECMFileDialog3
	// Param[in]: lpwsPluginName		The plugin name.
	// Param[in]: lpwsPluginHftName		The plugin HFT name.
	// Param[in]: lpwsTitle		Plugin title displayed on filedialog.
	// Param[in]: openproc		If filedailog is open style, callback when selecting ECM menu item.
	// Param[in]: saveproc		If filedailog is save style, callback when selecting ECM menu item.
	// Param[in]: clientdata	A pointer to user-supplied data. Used in <a>FRAppFileDialogECMOpenProc, FRAppFileDialogECMSaveProc</a>.
	// Return:	void
	// Remarks: Add an ECM plugin that needs to be displayed in fileDialog.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppAddECMFileDialog3
	// Deprecated: Internal use.
	//************************************
	static void AddECMFileDialog3(FS_LPCWSTR lpwPluginName, FS_LPCWSTR lpwPluginHftName, FS_LPCWSTR lpwTitle,
		FRAppFileDialogECMOpenProc3 openproc,
		FRAppFileDialogECMSaveProc saveproc, void* clientdata);

	//************************************
	// Function:  RegisterUserMessageHanler	
	// Param[in]: handler		CFR_ReaderUserMessageHandler that is inherit from IReader_UserMessagehandler.	
	// Return:	FS_BOOL
	// Remarks: If registered successfully.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppRegisterUserMessageHanler
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL  RegisterUserMessageHanler(FR_ReaderUserMessageHandler handler);

	//************************************
	// Function:  UnRegisterUserMessageHanler	
	// Param[in]: handler		CFR_ReaderUserMessageHandler that is inherit from IReader_UserMessagehandler.	
	// Return:	FS_BOOL
	// Remarks: If unregistered successfully.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppUnRegisterUserMessageHanler
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL  UnRegisterUserMessageHanler(FR_ReaderUserMessageHandler handler);

	//************************************
	// Function:  SetSGBaseHandler	
	// Param[in]: handler		CFR_SGBaseHandler that is inherit from ISG_BaseHandler.	
	// Return:	void
	// Remarks: Set signature handler
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes:
	// See: FRAppSetSGBaseHandler
	// Deprecated: Internal use.
	//************************************
	static void  	SetSGBaseHandler(void* pSGBaseHandler);

	//************************************
	// Function:  DestoryRibbonFloaty	
	// Param[in]: pFloaty		Floaty MiniFrameWnd
	// Return:	void
	// Remarks: destroy ribbon Floaty MiniFrameWnd
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Notes: The function can only be used for Windows.
	// See: FRAppDestoryRibbonFloaty
	// Deprecated: Internal use.
	//************************************
	static void     DestoryRibbonFloaty(FS_LPVOID pFloaty);

	//************************************
	// Function:  SetActiveTool
	// Param[in]: tool			The tool to set as the active tool.
	// Param[in]: persistent	A flag that indicates a preference as to whether the tool stays active after
	// Param[in]: bDelay	    Whether to delay setting the tool handler
	// it is used. <a>TRUE</a> is a hint that the tool should.if possible, stay active for an arbitrary number 
	// of operations (whatever that happens to be) rather than doing a one shot operation and restoring the 
	// prior active tool.
	//
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Sets the active tool. It does nothing if the specified tool is not currently enabled, The
	// <a>FRToolIsEnabled</a>() callback in <a>FR_ToolCallbacksRec</a> structure determines whether a tool is
	// enabled. If this callback is <a>NULL</a>, the tool is always enabled.
	// Notes:
	// See: FRAppRegisterTool
	// See: FRAppGetActiveTool
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL			SetActiveTool2(FR_Tool tool, FS_BOOL persistent, FS_BOOL bDelay);

	//************************************
	// Function:  GetRedirectURL
	// Param[in]: csTitle			The tool to set as the active tool.
	// Param[in]: nButtonID	        A flag that indicates a preference as to whether the tool stays active after
	// Param[out]: outURL	        Get the redirect url.
	// Return:	void
	// Remarks:	If it's not OEM package, nButtonID will not be used.
	// Notes:
	// See: FRAppGetRedirectURL
	// Deprecated: Internal use.
	//************************************
	static	void  		   GetRedirectURL(FS_WideString csTitle, FS_INT32 nButtonID, FS_WideString* outURL);

	//************************************
	// Function:  IsPortfolioSubDoc
	// Param[in]: pReaderDoc		The current document obj.
	// Return:	FS_BOOLEAN
	// Remarks:	Check if the document is protfolio sub doc.
	// Notes:
	// See: FRAppIsPortfolioSubDoc
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN      IsPortfolioSubDoc(FR_Document pReaderDoc);

	//************************************
	// Function:  IsCurDocViewShowInContainerFrm	
	// Return:	FS_BOOLEAN
	// Remarks:	Check if the current docview is show in the portfolio review window.
	// Notes: The function can only be used for Windows.
	// See: FRAppIsCurDocViewShowInContainerFrm
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN IsCurDocViewShowInContainerFrm();

	//************************************
	// Function:  CheckTrustySites	
	// Param[in]: csUrl		The site address.
	// Param[in]: bNeedRemember		Set true will be remember.
	// Param[in]: cwFilePath		The file need to be check if it's trusted.
	// Param[in]: pParent		    The CWnd* obj,that use to show warning dialog.
	// Param[in]: bCheckFilePath	Set true will need to check file path.
	// Return:	FS_BOOLEAN
	// Remarks:	Check if the site or the file is trusted.
	// Notes:
	// See: FRAppCheckTrustySites
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	CheckTrustySites(FS_LPCWSTR csUrl, FS_BOOL bNeedRemember, FS_LPCWSTR cwFilePath, FS_LPVOID pParent, FS_BOOL bCheckFilePath);

	//************************************
	// Function:  IsLinearizeSaveAs	
	// Return:	FS_BOOL
	// Remarks:	Check if need to linearize save.
	// Notes:
	// See: FRAppIsLinearizeSaveAs
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL		IsLinearizeSaveAs();

	//************************************
	// Function:  GetMetaDataOption	
	// Return:	FS_BOOLEAN   <a>TRUE</a> Need compress, <a>FALSE</a> not need compress.
	// Remarks:	 Check if compress the metaData when saving
	// Notes:
	// See: FRAppGetMetaDataOption
	//************************************
	static FS_BOOLEAN	GetMetaDataOption();

	//************************************
	// Function:  IsECMDocument	
	// Param[in]: pReaderDoc		The input doc.
	// Param[in]: wsFilePath		The filepath of the doc.
	// Param[out]: bsECMPluginName	Return the ECM plugin name.
	// Return:	FS_BOOL   
	// Remarks:	Get if the current document is opened from ECM,if return true then will return the ECM name.
	// Notes:
	// See: FRAppGetMetaDataOption
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL    IsECMDocument(FR_Document pReaderDoc, FS_WideString wsFilePath, FS_ByteString* bsECMPluginName);

	//************************************
	// Function:  GetDocument	
	// Param[in]: wsFilePath		The filepath of the doc.	
	// Return:	FR_Document   
	// Remarks:	Get the document of the filepath. Just support for absolute path.
	// Notes:
	// See: FRAppGetMetaDataOption
	//************************************
	static FR_Document	GetDocument(FS_WideString wsFilePath);

	//************************************
	// Function:  RunFieldFormat	
	// Param[in]: pReaderDoc		The filepath of the doc.	
	// Param[in]: commitKey		    The commit key type.	
	// Param[in]: targetName		The form fileld name.	
	// Param[out]: value		    The filepath of the doc.
	// Param[in]: script		    The result after run javascript.	
	// Param[in]: willCommit		Set true will commit.	
	// Return:	FR_JSActionReturn   
	// Remarks: Run javascript with the form field.
	// Notes:
	// See: FRAppRunFieldFormat
	// Deprecated: Internal use.
	//************************************
	static FR_JSActionReturn RunFieldFormat(FR_Document pReaderDoc,
		FS_INT32 commitKey,
		FS_LPCWSTR targetName,
		FS_WideString* value,
		FS_WideString script,
		FS_BOOLEAN willCommit);


	//************************************
	// Function:  RemoveMapFormat2Doc	
	// Param[in]: pReaderDoc		The input doc.	
	// Return:	void
	// Remarks: Remove the right panel data of the corresponding document
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes: The function can only be used for Windows.
	// See: FRAppRemoveMapFormat2Doc
	// Deprecated: Internal use.
	//************************************
	static void RemoveMapFormat2Doc(FR_Document pReaderDoc);

	//************************************
	// Function:  DownLoadAddon	
	// Param[in]: strAddonName		The Add on name.	
	// Param[in]: pClientData		The client data.	
	// Param[in]: pFunc		        The callback when download finish.	
	// Return:	void
	// Remarks: Download the required components.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes:
	// See: RemoveMapFormat2Doc
	// Deprecated: Internal use.
	//************************************
	static void	DownLoadAddon(FS_ByteString strAddonName, FS_LPVOID pClientData, FRDownloadFinishCallbackProc pFunc);

	//************************************
	// Function:  GetDocProducer	
	// Param[out]: bsProducer		The producer info.	
	// Return:	void
	// Remarks: Get producer of the application.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes:
	// See: FRAppGetDocProducer
	// Deprecated: Internal use.
	//************************************
	static void	  GetDocProducer(FS_ByteString* bsProducer);

	//************************************
	// Function:  SetSignatureCheck
	// Param[in]: pSignatureCheck		The input FR_ISignatureCheck object.	
	// Return:    void
	// Remarks:   Set siganture check handler to app,that used to check document signature by app.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use. This function is deprecated. It proceed in signature plugin.
	//************************************
	static void		SetSignatureCheck(void* pSignatureCheck);

	//************************************
	// Function:  DocRunOCRFinish
	// Param[in]: doc		The input FR_Document object.	
	// Return:    void
	// Remarks:   Notify TVPreview that the page object has changed.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void     DocRunOCRFinish(FR_Document doc);

	//************************************
	// Function:  AddShareMessageBar
	// Param[in]: hFrame		To add a childFrame handle to the message bar.
	// Param[in]: bsName		The title of message bar.
	// Param[in]: createProc	The callback of create child window.
	// Param[in]: destoryProc	The callback of destroy child window.
	// Param[in]: data		    The client data of child windows in plugin.
	// Return:    void
	// Remarks:   Add the information window above the document - Share window.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void    AddShareMessageBar(FS_HWND hFrame, FS_ByteString bsName, FRShareMessageBarCreateProc createProc, FRShareMessageBarDestoryProc destoryProc, FS_LPVOID data);

	//************************************
	// Function:  ShowShareMessageBar
	// Param[in]: hFrame		To add a childFrame handle to the message bar.
	// Param[in]: bsName		The title of message bar.
	// Param[in]: bShow	        TRUE: show message bar, FALSE: hide message bar.
	// Return:    FS_BOOL       TRUE: Show message bar success.
	// Remarks:   Show the tile of information windows above the document.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL  ShowShareMessageBar(FS_HWND hFrame, FS_ByteString bsName, FS_BOOL bShow);

	//************************************
	// Function:  SetCurrentStartPageTab
	// Param[in]: tabType		Tab type of the start page.	
	// Return:    void
	// Remarks:   Set current tab of start page, only activate state page tab the effect will be presented.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void SetCurrentStartPageTab(FR_STARTPAGETABTYPE tabType);

	//************************************
	// Function:  GetAppPath
	// Param[out]: outAppPath		The string buffer used to receive the app path.
	// Return:	<a>TRUE</a> for success, otherwise not.
	// Remarks:	 Gets the execution file path of current running reader.
	// Notes:
	//************************************
	static FS_BOOL GetAppPath(FS_WideString* outAppPath);

	//************************************
	// Function:  AddTrialDayDlgToCategory
	// Param[in]: bsCategoryName		The input category name.
	// Return:	void.
	// Remarks:	Add trialday dialog to the name of RibbonCategory.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void  AddTrialDayDlgToCategory(FS_ByteString bsCategoryName);

	//************************************
	// Function:  RegisterPanelToolHandler
	// Param[in]: panelViewCallbacks	A panel page callback set. When the navigation panel occurs a event, reader will
	// call a corresponding callback to respond.
	// Return: FS_LPVOID   The returned value should be released by <a>FRAppReleaseNavPanelView</a>.
	// Remarks: Adds a navigation panel view into the Foxit Reader. 
	// The navigation panel view can be added after reader has started up.
	// Notes:	
	//************************************
	static FS_LPVOID	RegisterPanelToolHandler(FR_PanelViewCallbacks panelViewCallbacks);

	//************************************
	// Function:  IsTaskPaneShow
	// Param[in]: csName	
	// Return: FS_BOOLEAN   true means the specified task pane is show.
	// Remarks: Check the specified right panel is show.
	// Notes:	
	//************************************
	static FS_BOOLEAN   IsTaskPaneShow(FS_LPCSTR csName);

	//************************************
	// Function:  GetCurrentDocumentByFrame
	// Param[in]: frameWnd	The input frame of the doc.
	// Return: FR_Document.
	// Remarks: Get current document by input frame.
	// Notes:	
	// Deprecated: Internal use.
	//************************************
	static FR_Document   GetCurrentDocumentByFrame(FS_LPVOID frameWnd);

	//************************************
	// Function:  SendUserDataMessageToApp
	// Param[in]: pUserData		The client data.
    // Param[in]: pHander		The input message handler.
	// Return:	FS_INT32.
	// Remarks:	Send user data message to framework.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32	SendUserDataMessageToApp(FS_LPVOID pUserData, FR_ReaderUserMessageHandler pHander);

	//************************************
	// Function:  ShowReadMode
	// Return:	void.
	// Remarks:	Switch to read mode.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void ShowReadMode();

	//************************************
	// Function:  LoadUnitString
	// Param[in]: nUnitType		The input unit type.
	// Param[out]: unitStr		Get the multi language string.
	// Return:	void.
	// Remarks:	Get the multi language string.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void LoadUnitString(FS_INT32 nUnitType, FS_WideString* unitStr);

	//************************************
	// Function:  SetECMFileDialogSensorDataType
	// Param[in]: ecmDidalog		    The input ECM dialog.
	// Param[in]: wsSensorDataType		The input sensor data type.
	// Return:	void.
	// Remarks:	Set the sensor datat type, it used to collect information.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void SetECMFileDialogSensorDataType(FS_LPVOID ecmDidalog, FS_LPCWSTR wsSensorDataType);

	//************************************
	// Function:  GetReplaceColors
	// Param[out]: clrDocFore		Get the text color.
	// Param[out]: clrDocBack		Get background color.
	// Return:	void.
	// Remarks: Get the replace document color.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void GetReplaceColors(FS_COLORREF* clrDocFore, FS_COLORREF* clrDocBack);

	//************************************
	// Function:  GetOwnerFileHandlerCanSupportOpen
	// Param[in]: filePath		    The input ECM dialog.
	// Return:	FS_BOOL.
	// Remarks:	Get file type can support open.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetFileTypeCanSupportOpen(FS_LPCWSTR filePath);

	//************************************
	// Function:  OnDocPageLabelChange
	// Param[in]: pDoc		    The input FR_Document.
	// Return:	void.
	// Remarks:	Notify after page label changed.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void OnDocPageLabelChange(FR_Document pDoc);

	//************************************
	// Function:  SetCurrentToolByName
	// Param[in]: csToolname		    The input tool name.
	// Param[in]: bPersistent		    Whether need to use the tool persistent.
	// Return:	void.
	// Remarks:	Set the current tool by name.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void  SetCurrentToolByName(FS_LPCSTR csToolname, FS_BOOL bPersistent);

	//************************************
	// Function:  WillSignatureDoc
	// Param[in]: pDocument		    The input FR_Document.
	// Param[in]: outPath		    The out path when after signature doc.
	// Return:	void.
	// Remarks:	Nofity app will signature doc.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void	 WillSignatureDoc(FR_Document pDocument, FS_LPCWSTR outPath);

	//************************************
	// Function:  DidSignatureDoc
	// Param[in]: outPath		    The out path when after signature doc.
	// Return:	void.
	// Remarks:	Nofity app signature doc has finished.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void	 DidSignatureDoc(FS_LPCWSTR outPath);
	
	//************************************
	// Function:  DeleteUnusedFont
	// Param[in]: doc		        The input FPD_Document.
	// Param[in]: pFontDict		    The input font dict.
	// Return:	void.
	// Remarks:	When deleting useless font, notify fontmap to delete the corresponding font cache.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void	 DeleteUnusedFont(FPD_Document doc, FPD_Object pFontDict);

	//************************************
	// Function:  GetIsEditorApp
	// Return:	FS_BOOL   true: Current is editor, otherwise is reader.
	// Remarks:	Check currently is editor.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetIsEditorApp();

	//************************************
	// Function:  OpenNewDocViewFrame
	// Param[in]: doc		        The input FPD_Document.
	// Param[in]: bMarkVisible		The input FPD_Document.
	// Return:	FS_LPVOID          It returns window hand of CFrameWnd.
	// Remarks:	Create a view in tab window.
	// Notes:
	// Deprecated: Internal use, it only for windows.
	//************************************
	static FS_LPVOID OpenNewDocViewFrame(FR_Document doc, FS_BOOL bMarkVisible);

	//************************************
	// Function:  SetActiveTabByHWND
	// Param[in]: hTabWnd		        The input tab hwnd need to be activated.
	// Return:	FS_BOOLEAN.
	// Remarks:	Set activate tab.
	// Notes:
	// Deprecated: Internal use
	//************************************
	static FS_BOOLEAN SetActiveTabByHWND(FS_HWND hTabWnd);

	//************************************
	// Function:  PopDocPropertyPage2
	// Param[in]: pageShowName	The property page you want to display.
	// Param[in]: type       	The input property type.
	// Return: void
	// Remarks: Pops up the doc property pages.
	// Notes: It used for Cross-platform interface.
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterDocPropertyPageHandler
	// Deprecated: Internal use.
	//************************************
	static void PopDocPropertyPage2(FS_LPCWSTR pageShowName, FS_LPCWSTR type);

	//************************************
	// Function:  RegisterPluginEventHandler
	// Param[in]: callback	    The input FR_PluginEventCallbacks.
	// Return: FS_LPVOID        Return the plugin event handler.
	// Remarks: Regist the handler of plugin event, like plugin unload.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: FRAppRegisterPluginEventHandler
	//************************************
	static FS_LPVOID RegisterPluginEventHandler(FR_PluginEventCallbacks callback);

	//************************************
	// Function:  UnregisterPluginEventHandler
	// Param[in]: handler	    The input plugin event handler.
	// Return: void
	// Remarks: Unregist the plugin event handler.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: FRAppUnregisterPluginEventHandler
	//************************************
	static void UnregisterPluginEventHandler(FS_LPVOID handler);

	//************************************
	// Function:  SetDocCanSaveSession
	// Param[in]: doc	                    The input FR_Document.
	// Param[in]: bDocCanSaveSession	    TRUE: Need to save doc session.
	// Return: void
	// Remarks: Set whether need to save doc session, like scale, zoom.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void   SetDocCanSaveSession(FR_Document doc, FS_BOOL bDocCanSaveSession);

	//************************************
	// Function:  GetBitmapFromClipboard
	// Param[in]: hwnd	                    The input FR_Document.
	// Param[out]: pBitamp	                Get the bitmap.
	// Return: FS_DIBitmap    
	// Remarks: Get bitmap form clipboard.
	// Notes: It only used in windows. And need to call FSDIBitmapDestroy to release the FS_DIBitmap.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_DIBitmap  GetBitmapFromClipboard(FS_HWND hwnd);

	//************************************
	// Function:  UnRegisterSecurityHandler2
	// Param[in]: name	    The name of the security handler.
	// Param[in]: callbacks	The input callbacks need to unregiste.
	// Return:	void
	// Remarks: Unregisters a security handler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	// See: FRAppRegisterSecurityHandler
	//************************************
	static void	UnRegisterSecurityHandler2(FS_LPCSTR name, FR_SecurityCallbacks callbacks);

	//************************************
	// Function:  ToDecryptFile
	// Param[in]: pszInPath	        The input DRM file path.
	// Param[out]: pszOutPath	    Get the temp decrypted file path.
	// Return:	FS_BOOL    TRUE: Decrypt success.
	// Remarks: Decrypt DRM file.
	// Notes: It has been deprecated. User can use FREncryptedDocMgrToDecFile function instead.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	// See: FRAppToDecryptFile	
	//************************************
	static FS_BOOL	ToDecryptFile(FS_LPCWSTR pszInPath, FS_WideString* pszOutPath);

	//************************************
	// Function:  DeleteDecryptFile
	// Param[in]: pszPath	    The input decrypted file path need to delete.
	// Return:	FS_BOOL
	// Remarks: Delete the decrypted file path.
	// Notes: It has been deprecated. User can use FREncryptedDocMgrToDelDecFile function instead.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	// See: FRAppDeleteDecryptFile
	//************************************
	static FS_BOOL	DeleteDecryptFile(FS_LPCWSTR pszPath);

	//************************************
	// Function:  UnRegisterPOEventHandler
	// Param[in]: handler	The input handler, it get from FRAppRegisterPOEventHandler.
	// Return:FS_BOOLEAN	TRUE for success, otherwise not.
	// Remarks: UnRegister a hanlder called by the Foxit Reader to do the page organizing, such as adding pages, deleting pages, replacing pages and so on.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// See: FRAppUnRegisterPOEventHandler
	//************************************
	static FS_BOOLEAN UnRegisterPOEventHandler(FS_LPVOID handler);

	//************************************
	// Function:  UnRegisterTool
	// Param[in]: tool		The <a>FR_Tool</a> object containing the tool's callbacks. This object
	// must not be freed after calling <a>FRAppRegisterTool</a>(), but must be remained.
	// Return:	
	// Remarks: UnRegisters a tool into the Foxit Reader.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See: FRAppRegisterTool
	//************************************
	static void		UnRegisterTool(FR_Tool tool);

	//************************************
	// Function:  IsHideWndTask	
	// Return: FS_BOOL    
	// Remarks: Get whether the right panel is hidden.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static	FS_BOOL	IsHideWndTask();

	//************************************
	// Function:  SetHideWndTask
	// Param[in]: bHideWndTask	        Set whether the right panel is hidden.
	// Return: void    
	// Remarks: Set whether the right panel is hidden.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void	SetHideWndTask(FS_BOOL bHideWndTask);	

	//************************************
	// Function:  RegisterDRMEventHandler
	// Param[in]: callbacks	        The input FR_DRMEventCallbacks.
	// Return: FR_DRMEventHandler    
	// Remarks: Registers the event notification to operate DRM file.
	// When operate DRM file, Editor will notify plugin to encrypt or decrypt.
	// Notes: Call FRAppUnRegisterDRMEventHandler to unregister the DRM event handler and release the memory.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See: FRAppUnRegisterDRMEventHandler
	//************************************
	static FR_DRMEventHandler RegisterDRMEventHandler(FR_DRMEventCallbacks callbacks);

	//************************************
	// Function:  UnRegisterDRMEventHandler
	// Param[in]: handler	        The input FR_DRMEventHandler.
	// Return: void    
	// Remarks: Unregister the DRM event handler and release the memory.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See: FRAppRegisterDRMEventHandler
	//************************************
	static void UnRegisterDRMEventHandler(FR_DRMEventHandler handler);

	//************************************
	// Function:  AddTrialDayDlgToCategory2
	// Param[in]: bsCategoryName		The input category name.
	// Param[in]: hMainFrm		        The input main frame.
	// Return:	void.
	// Remarks:	Add trialday dialog to the name of RibbonCategory.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// Deprecated: Internal use.
	//************************************
	static void  AddTrialDayDlgToCategory2(FS_LPCSTR bsCategoryName, FS_HWND hMainFrm);

	//************************************
	// Function:  CheckIsContinue
	// Return:	FS_BOOL.
	// Remarks: Check current is continue or classic version.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL CheckIsContinue();

	//************************************
	// Function:  CheckIsOldSubProcess
	// Return:	FS_BOOL.
	// Remarks: Check the OldSubProcess flag in registry.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL CheckIsOldSubProcess();

	//************************************
	// Function:  GetAppDataRootPath
	// Param[out]: outRootAppPath		The string buffer used to receive the root path which Foxit Reader used to
	// store some application's data. It will be filled automaticly by reader.
	// Return:	<a>TRUE</a> for success, otherwise not.
	// Remarks:	 Gets the execution file path of current running reader.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetAppDataRootPath(FS_WideString* outRootAppPath);

	//************************************
	// Function:  GetActiveTaskName
	// Param[out]: taskName		Get the name of the currently active right panel.
	// Return:	void
	// Remarks:	 Get the name of the currently active right panel.
	// Notes: It only for windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// Deprecated: Internal use.
	//************************************
	static void GetActiveTaskName(FS_ByteString* taskName);

	//************************************
	// Function:  ShowTaskPane2
	// Param[in]: info      	    The input FR_ShowTaskPanelInfo.
	// Return:	  void
	// Remarks:   Shows or hidden a task panel view.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// See: FRAppShowTaskPane2
	//************************************
	static void ShowTaskPane2(FR_ShowTaskPanelInfo info);

	//************************************
	// Function:  IsDocRedactSaveToSaveAs	
	// Return:	  FS_BOOL
	// Remarks:   Check the doc is save to  saveas.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// See: FRAppIsDocRedactSaveToSaveAs
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	IsDocRedactSaveToSaveAs();

	//************************************
	// Function:  UpdateCustomRecentFileList	
	// Return:	  void
	// Remarks:   Update custom recent file list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// See: FRAppUpdateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static void UpdateCustomRecentFileList(FS_LPCSTR csRecentListName);

	//************************************
	// Function:  CreateColorDialog	
	// Return:	  void
	// Remarks:   Update custom recent file list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// See: FRAppUpdateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static FR_CGWColorDialog CreateColorDialog(FS_BOOLEAN bOnlyFillClr, FS_LPVOID wnd);

	//************************************
	// Function:  SetNotify	
	// Return:	  void
	// Remarks:   Update custom recent file list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// See: FRAppUpdateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID SetNotify(FR_CGWColorDialog dialog, FR_CGWColorNotifyCallbacks callbacks);

	//************************************
	// Function:  ShowColorDialog	
	// Return:	  void
	// Remarks:   Update custom recent file list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// See: FRAppUpdateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static void ShowColorDialog(FR_CGWColorDialog dialog);

	//************************************
	// Function:  IsTaskPaneInTab	
	// Param[in]: csName		Check if the task panel is on the right tab.
	// Return:	  FS_BOOLEAN   true means is on the tab, otherwise is not.
	// Remarks:   Check if the task panel is on the right tab.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppUpdateCustomRecentFileList
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	IsTaskPaneInTab(FS_LPCSTR csName);

	//************************************
	// Function:  IsRunOfficeEmbeded		
	// Return:	  FS_BOOLEAN   Check if it's run office embeded.
	// Remarks:   Check if it's run office embeded.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppIsRunOfficeEmbeded
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN  IsRunOfficeEmbeded();

	//************************************
	// Function:  IsStartPageClosed		
	// Return:	  FS_BOOL   Check if startpage has been closed.
	// Remarks:   Check if startpage has been closed.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppIsStartPageClosed
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsStartPageClosed();

	//************************************
	// Function:  ShowAboutPlugins	
	// Remarks:   Check if startpage has been closed.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppShowAboutPlugins
	// Deprecated: Internal use.
	//************************************
	static void ShowAboutPlugins();

	//************************************
	// Function:  SetFindResultHighlightColor	
	// Remarks:   Set the highlight color of find result.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppSetFindResultHighlightColor
	// Deprecated: Internal use.
	//************************************
	static void		SetFindResultHighlightColor(FS_COLORREF clrHighlight);

	//************************************
	// Function:  GetFindResultHighlightColor	
	// Remarks:   Get the highlight color of find result.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppGetFindResultHighlightColor
	// Deprecated: Internal use.
	//************************************
	static FS_COLORREF	GetFindResultHighlightColor();

	//************************************
	// Function:  SetFindResultHighlightOpacity	
	// Remarks:   Set the highlight opacity of find result.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppSetFindResultHighlightOpacity
	// Deprecated: Internal use.
	//************************************
	static void		SetFindResultHighlightOpacity(FS_INT32 nOpacity);

	//************************************
	// Function:  GetFindResultHighlightOpacity	
	// Remarks:   Get the highlight opacity of find result.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppGetFindResultHighlightOpacity
	// Deprecated: Internal use.
	//************************************
	static FS_INT32		GetFindResultHighlightOpacity();
	
	//************************************
	// Function:  RegisterStartPageEventHandler
	// Param[in]: handler	The input FR_StartPageEventHandler.	
	// Return:	  FS_BOOL
	// Remarks:   Register start page event handler.
	//            When start page active or deactive, it will notify plugins.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppUnRegisterStartPageEventHandler
	//************************************
	static FS_BOOL RegisterStartPageEventHandler(FR_StartPageEventHandler handler);

	//************************************
	// Function:  UnRegisterStartPageEventHandler
	// Param[in]: handler	The input FR_StartPageEventHandler.	
	// Return:	  FS_BOOL
	// Remarks:   Unregister start page event handler.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppRegisterStartPageEventHandler
	//************************************
	static FS_BOOL UnRegisterStartPageEventHandler(FR_StartPageEventHandler handler);

	//************************************
	// Function:  RegisterUndoEventHandler
	// Param[in]: handler	The input FR_UndoEventHandler.	
	// Return:	  void
	// Remarks:   Register undo/redo event handler.
	//            When editor operate undo or redo, it will notify plugins.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppRegisterUndoEventHandler
	//************************************
	static void RegisterUndoEventHandler(FR_UndoEventHandler handler);

	//************************************
	// Function:  UnRegisterUndoEventHandler
	// Param[in]: handler	The input FR_UndoEventHandler.	
	// Return:	  void
	// Remarks:   UnRegister undo/redo event handler.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppRegisterUndoEventHandler
	//************************************
	static void UnRegisterUndoEventHandler(FR_UndoEventHandler handler);

	//************************************
	// Function:  GetPDFAViewMode	
	// Return:	  FS_INT32
	// Remarks:   Get PDFA view mode.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppGetPDFAViewMode
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 	GetPDFAViewMode();

	//************************************
	// Function:  IsProtectedModeByPath
	// Param[in]: csFilePath	The input file path.
	// Return:	  FS_BOOLEAN
	// Remarks:   Get PDFA view mode.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppIsProtectedModeByPath
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	IsProtectedModeByPath(FS_LPCWSTR csFilePath);

	//************************************
	// Function:  AddFileAttachment2
	// Param[in]: pDoc	        The input FR_Document obj.
	// Param[in]: info	        The input attachment info.
	// Return:	  FS_BOOLEAN
	// Remarks:   Add file attachment to doc.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppAddFileAttachment2	
	//************************************
	static FS_BOOLEAN	AddFileAttachment2(FR_Document pDoc, FR_FileAttachmentInfo info);

	//************************************
	// Function:  InitAESV4CryptoHandler	
	// Return:	  void
	// Remarks:   Init AESV4 crypto handler.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppInitAESV4CryptoHandler
	// Deprecated: Internal use.
	//************************************
	static void InitAESV4CryptoHandler();

	//************************************
	// Function:  CombinePDF
	// Param[in]: frCombineData	        The input FR_CombineData obj.
	// Return:	  FS_INT32
	// Remarks:   Combine specified files to PDF.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppCombinePDF
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 CombinePDF(FR_CombineData* frCombineData);

	//************************************
	// Function:  Launch
	// Param[in]: csFileName	        The input file name.
	// Param[in]: csParameters	        The input paramter.
	// Param[in]: csDefaultPath	        The input default path.
	// Param[in]: bOpenOrPrint	        Need open or print.
	// Return:	  FS_BOOLEAN
	// Remarks:   Launch specified file.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRAppLaunch
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN Launch(FS_LPCWSTR csFileName, FS_LPCWSTR csParameters, FS_LPCWSTR csDefaultPath, FS_BOOLEAN bOpenOrPrint);
};

class CFR_Language_V1
{
public:
	//************************************
	// Function:  Create
	// Param[in]: hInstance	The input plug-in instance handle.		
	// Return:	  The <a>FR_Language</a> object created.
	// Remarks:   Creates a new <a>FR_Language</a> object.
	// Notes:
	//************************************
	static FR_Language Create(HINSTANCE hInstance);

	//************************************
	// Function:  Release
	// Param[in]: language The input <a>FR_Language</a> object to be released.
	// Return:	  void
	// Remarks:   Releases the <a>FR_Language</a> object created by <a>FRLanguageCreate</a>().
	// Notes: 
	// See: FRLanguageCreate
	//************************************
	static void Release(FR_Language language);

	//************************************
	// Function:  Change
	// Param[in]: language	The input <a>FR_Language</a> object.
	// Param[in]: nID		The input language ID.
	// Return:	  void
	// Remarks:   Changes the language of plug-in according to the input language ID. 
	// Plug-in can change the language when the <a>FRAppOnLangUIChange</a>() app event occurs.
	// You can get the current Foxit Reader language ID by <a>FRLanguageGetCurrentID</a>(), 
	// so that the language of plug-in can be the same as the Foxit Reader.
	// Notes: 
	// See:       FRLanguageGetCurrentID
	//************************************
	static void Change(FR_Language language, FS_INT32 nID);

	//************************************
	// Function:  GetCurrentID
	// Return:	  The current language ID of Foxit Reader. Like FR_LANGUAGE_NAME_DEFAULT.
	// Remarks:   Gets the current language ID of Foxit Reader.
	// Notes: 
	// See:       FRLanguageChange
	//************************************
	static FS_INT32 GetCurrentID();

	//************************************
	// Function:  TranslateMenu
	// Param[in]: language	The input <a>FR_Language</a> object.
	// Param[in]: hMenu		The input menu handle to be translated.
	// Param[in]: pzResName	The input name of menu resource. The <Italic>MAKEINTRESOURCE</Italic> macro can be used to create this value. 
	// Return:	  void
	// Remarks:   Translates the language of menu to another through <param>language</param>.
	// Notes: 
	//************************************
	static void TranslateMenu(FR_Language language, HMENU hMenu, FS_LPCWSTR pzResName);

	//************************************
	// Function:  TranslateDialog
	// Param[in]: language	The input <a>FR_Language</a> object.
	// Param[in]: hWnd		The input dialog handle to be translated.
	// Param[in]: pzResName	The input name of dialog resource. The <Italic>MAKEINTRESOURCE</Italic> macro can be used to create this value. 
	// Return:	  void
	// Remarks:   Translates the language of dialog to another through <param>language</param>.
	// Notes: 
	//************************************
	static void	TranslateDialog(FR_Language language, HWND hWnd, FS_LPCWSTR pzResName);

	//************************************
	// Function:  LoadString
	// Param[in]: language	The input <a>FR_Language</a> object.
	// Param[in]: nId		Specifies the integer identifier of the string to be loaded.
	// Param[out]:buffer	It receives the string loaded.
	// Param[in]: len		Specifies the length of the <param>buffer</param> in bytes.
	// Return:	  The length of the string in bytes.
	// Remarks:   Loads the specified string. Set the <param>buffer</param> <a>NULL</a> to get the length of the string.
	// Notes: 
	//************************************
	static FS_INT32 LoadString(FR_Language language, FS_INT32 nId, void* buffer, FS_INT32 len);	

	//************************************
	// Function:  LoadVersionRes
	// Param[in]: language			The input <a>FR_Language</a> object.
	// Param[out]:outFileDes		It receives the file description.
	// Param[out]:outLegalCopyright	It receives the legal copyright.
	// Return: void
	// Remarks: Loads the file description and the legal copyright of the plug-in.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void LoadVersionRes(FR_Language language, FS_WideString* outFileDes, FS_WideString* outLegalCopyright);

	//************************************
	// Function:  GetLocalLangName
	// Param[out]:outName		It receives the local language name.
	// Return: void
	// Remarks: Gets the local language name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void GetLocalLangName(FS_WideString* outName);

	//************************************
	// Function:  TranslateDialog2
	// Param[in]: language	The input <a>FR_Language</a> object.
	// Param[in]: hWnd		The input dialog handle to be translated.
	// Param[in]: pzResName	The input name of dialog resource. The <Italic>MAKEINTRESOURCE</Italic> macro can be used to create this value. 
	// Param[in]: bAutoAdpt Whether to adapt to the DPI setting or not.
	// Return:	  void
	// Remarks:   Translates the language of dialog to another through <param>language</param>.
	// Notes: 
	//************************************
	static void	TranslateDialog2(FR_Language language, HWND hWnd, FS_LPCWSTR pzResName, FS_BOOL bAutoAdpt);

	//************************************
	// Function:  ModifyLogFont
	// Param[in,out]: lf	The input attributes of a font to be modified.
	// Return: void.
	// Remarks: Modifies the attributes of a font to match the system language when the application language matches the system language, 
	// otherwise the font name will be set Tahoma as default.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	//************************************
	static void ModifyLogFont(LOGFONT* lf);

	//************************************
	// Function:  FormatEx
	// Param[out]: outFormat	It receives the format string.
	// Param[in]: lpszFormat	Specifies a format-control string.
	// Param[in]: ...			arguments list.
	// Return:    void
	// Remarks:   Formats a translated string so that the arguments list can match the format.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	//************************************
	static void FormatEx(FS_WideString* outFormat, FS_LPCWSTR lpszFormat, ...);

	//************************************
	// Function:  JSPluginGetMessage
	// Param[in]: lpsModuleName		The input javascript plug-in module name.
	// Param[in]: lpsMessageName	The input message name.
	// Param[out]: outMessage		It receives the message string.
	// Return:    void
	// Remarks:   Gets the message string for javascript plug-in.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
	//************************************
	static void JSPluginGetMessage(FS_LPCSTR lpsModuleName, FS_LPCSTR lpsMessageName, FS_WideString* outMessage);

	//************************************
	// Function:  ReleaseDialogUIFont
	// Param[in]: hWnd		The input HWND of the dialog.
	// Return:    void
	// Remarks:   When the window is released, the interface needs to be called for GDI recycling.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void ReleaseDialogUIFont(FS_HWND hWnd);	
};

class CFR_UIProgress_V1
{
public:
	//************************************
	// Function:  Create
	// Param[in]: hParent				The parent window handle of the progress bar.
	// Param[in]: bShowCancelButton		Whether to show the cancel button on the progress bar.
	// Return:	  The <a>FR_UIProgress</a> object created.
	// Remarks:   Creates a new <a>FR_UIProgress</a> object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FR_UIProgress Create(HWND hParent, FS_BOOL bShowCancelButton);

	//************************************
	// Function:  SetText
	// Param[in]: UIProgress	The input progress bar.
	// Param[in]: lpText		The text shown in the progress bar.		
	// Return:	  void.
	// Remarks:   Set the text shown in the progress bar.
	// Notes:
	//************************************
	static  void SetText(FR_UIProgress UIProgress, FS_LPCWSTR lpText);

	//************************************
	// Function:  SetRange
	// Param[in]: UIProgress	The input progress bar.
	// Param[in]: nLower	The minimize value of the range.	
	// Param[in]: nUpper	The maximize value of the range.
	// Return:	  void.
	// Remarks:   Set the range of the progress bar.
	// Notes:
	//************************************
	static	void SetRange(FR_UIProgress UIProgress, FS_INT32 nLower, FS_INT32 nUpper);

	//************************************
	// Function:  SetCurrValue
	// Param[in]: UIProgress	The input progress bar.
	// Param[in]: nPos	The current value of the progress bar.	
	// Return:	  void.
	// Remarks:   Set the current value of the progress bar.
	// Notes:
	//************************************
	static	void SetCurrValue(FR_UIProgress UIProgress, FS_INT32 nPos);

	//************************************
	// Function:  PeekAndPump
	// Param[in]: UIProgress	The input progress bar.
	// Return:	  void.
	// Remarks:   Peek and pump.
	// Notes:
	//************************************
	static  void PeekAndPump(FR_UIProgress UIProgress);

	//************************************
	// Function:  IsCancelled
	// Param[in]: UIProgress	The input progress bar.
	// Return:	  Whether the progress bar is cancelled or not.
	// Remarks:   Whether the progress bar is cancelled or not.
	// Notes:
	//************************************
	static  FS_BOOL IsCancelled(FR_UIProgress UIProgress);

	//************************************
	// Function:  GetCurrentValue
	// Param[in]: UIProgress	The input progress bar.
	// Return:	  Get the current value of the progress bar.
	// Remarks:   The current value of the progress bar.
	// Notes:
	//************************************
	static	FS_INT32 GetCurrentValue(FR_UIProgress UIProgress);

	//************************************
	// Function:  Destroy
	// Param[in]: UIProgress	The input progress bar.	
	// Return:	  void.
	// Remarks:   Destroy the progress bar.
	// Notes:
	//************************************
	static void Destroy(FR_UIProgress UIProgress);

	//************************************
	// Function:  DoCancel
	// Param[in]: UIProgress	The input progress bar.
	// Param[in]: bKill			Whether to kill the progress bar.
	// Return:	  <a>TRUE</a> means success, otherwise failure.
	// Remarks:   To cancel the progress bar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL DoCancel(FR_UIProgress UIProgress, FS_BOOL bKill);

	//************************************
	// Function:  Create2
	// Param[in]: hParent				The parent window handle of the progress bar.
	// Param[in]: bShowCancelButton		Whether to show the cancel button on the progress bar.
	// Param[in]: bRevertFocus			Whether to revert the focus to the original focused window.
	// Return:	  The <a>FR_UIProgress</a> object created.
	// Remarks:   Creates a new <a>FR_UIProgress</a> object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FR_UIProgress Create2(HWND hParent, FS_BOOL bShowCancelButton, FS_BOOL bRevertFocus);

	//************************************
	// Function:  Create3
	// Param[in]: hParent		The parent window handle of the progress bar.
	// Param[in]: option		Set some progress option when create UIProgress.	
	// Return:	  The <a>FR_UIProgress</a> object created.
	// Remarks:   Creates a new <a>FR_UIProgress</a> object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_UIProgress Create3(HWND hParent, FR_UIProgressOption option);

	//************************************
	// Function:  GetHwnd
	// Param[in]: UIProgress	The input progress bar.
	// Return:	FS_HWND      
	// Remarks:  Get the HWND of the UIProgress.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_HWND  GetHwnd(FR_UIProgress UIProgress);

	//************************************
	// Function:  SetSecondLineText
	// Param[in]: UIProgress	The input progress bar.
	// Param[in]: lpText	    The line text to set.
	// Return:	void      
	// Remarks:  Set second line text.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void SetSecondLineText(FR_UIProgress UIProgress, FS_LPCWSTR lpText);

	//************************************
	// Function:  GetText
	// Param[in]: UIProgress	The input progress bar.	
	// Param[out]: bsText	    Get the text of input progress bar.	
	// Return:	void      
	// Remarks:  Get text of the progress.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void  GetText(FR_UIProgress UIProgress, FS_WideString* bsText);
};

class CFR_Internal_V5
{
public:	
	//print
	static FS_BOOL DoPrintCommentSummary(FR_Document doc,FS_LPCWSTR lpFilePath);

	//optimizer
	static FS_BOOL OptimizerModuleFlatDocument(FPD_Document pSourDoc, FS_INT32* pPageAry, FS_INT32 pageSize, void* xUserData);

	//GlobalWnd
	static FS_BOOL GlobalWndOpenPassWord(FS_WideString wsFileName, FS_BOOL bOwnerPass, FS_WideString* wsPassWord, FS_LPCWSTR wsDescription, FS_LPVOID pParent);
	static FS_BOOL GlobalWndCheckFileSize(FPD_Document pDoc, FS_WideString wsFilePath, FS_BOOL bShowMsgBox, FS_INT32* nChoice, FS_BOOL bShowCheckBox, FS_BOOL* bChecked, FS_INT32 nPageLimit, FS_INT32 nFileSizeLimit);
	static FS_BOOL OpenCertifiedPDF(FPD_Parser parser, FS_LPCWSTR lpwsPDFPath);

	static void* PWLWndCreationParamNew();
	static void PWLWndCreationParamSetFontMap(void* pCreationParam, FR_Edit_FontMap fontMap);
	static void PWLWndCreationParamSetFontIndex(void* pCreationParam, FS_INT32 nFontIndex);
	static void PWLWndCreationParamSetFlag(void* pCreationParam, FS_DWORD dwFlags);
	static void PWLWndCreationParamSetFontSize(void* pCreationParam, FS_FLOAT fFontSize);
	static void PWLWndCreationParamSetTextColor(void* pCreationParam, FS_INT32 r, FS_INT32 g, FS_INT32 b);
	static void PWLWndCreationParamSetTextColorII(void* pCreationParam, FS_INT32 type, FS_FLOAT color1, FS_FLOAT color2, FS_FLOAT color3, FS_FLOAT color4);
	static void PWLWndCreationParamSetRect(void* pCreationParam, FS_FloatRect rect);
	static void PWLWndCreationParamDestroy(void* pCreationParam);
	static void* PWLWndEditNew(void* pCreationParam);
	static void PWLWndEditSetTextColor(void* pEdit, FS_INT32 r, FS_INT32 g, FS_INT32 b);
	static void PWLWndEditSetTextColorII(void* pEdit, FS_INT32 type, FS_FLOAT color1, FS_FLOAT color2, FS_FLOAT color3, FS_FLOAT color4);
	static void PWLWndEditSetText(void* pEdit, FS_LPCWSTR csText);
	static void PWLWndEditGetContentRect(void* pEdit, FS_FloatRect* pRect);
	static void PWLWndEditGeneratePageObjects(void* pEdit, void* pPageObjects, FS_FLOAT xx, FS_FLOAT yy, FS_PtrArray* outObjArray);
	static void PWLWndEditGeneratePageObjectsII(void* pEdit, void* pPageObjects, FS_FLOAT xx, FS_FLOAT yy);
	static void PWLWndEditDestroy(void* pEdit);

	static void SetReviewJS(FR_Document frDoc, FS_LPCWSTR lpwsScriptName, FS_LPCWSTR lpwsScript);
	static void GetReviewJS(FR_Document frDoc, FS_WideString* cwScriptName, FS_WideString* cwScript);
	static FS_BOOL RemoveReviewJS(FR_Document frDoc, FS_LPCWSTR lpwsScriptName);

	static FS_BOOL ExportAnnotToXFDF(void* pAnnot, FS_XMLElement xmlElement);
	static void* ImprotAnnotFromXFDF(FR_Document frDoc, FS_XMLElement xmlAnnot, FS_BOOL bSendAnnotChangeToNotify);

	static void EnableAnnot(void* pAnnot, FS_BOOL bEnable);
	static FS_BOOL DeleteAnnot(FR_Document frDoc, FS_INT32 nPageIndex, FS_LPCWSTR lpwsAnnotName, FS_BOOL bSendAnnotChangeToNotify);
	static FS_BOOL UpdateAnnotAuthor(FR_Document frDoc, FS_LPCWSTR lpwsAuthorName);
	static FS_BOOL UpdateAnnotAuthor2(FR_Annot frAnnot, FS_LPCWSTR lpwsAuthorName);
	static void* SetIcommentsAnnotNotify(FR_CommentsAnnotOprtNotifyCallbacks callbacks);
	static FS_BOOL RemoveIcommentsAnnotNotify(void* pNotify);

	static void ShowChildScrollBar(FS_BOOL bShow, HWND hParentWnd);

	static void	ChangeZoomScaleInfo(double dbScale, FS_BOOL bReDraw);

	static FS_BOOL AdvEditing(FS_INT32 iPage, FS_FloatRect pdfRect);

	static FS_BOOL ToolbarModuleGetSysFontFaceName(FS_LPCWSTR lpwsScriptName, FS_WideString* outName);

	//internal interface from ifxet_vt.h

	//CFVT_WordPlace
	static FR_VTWordPlace WordPlaceNew(FS_INT32 nSecIndex, FS_INT32 nLineIndex, FS_INT32 nWordIndex);
	static void WordPlaceDestroy(FR_VTWordPlace wordPlace);
	static void WordPlaceSetDefault(FR_VTWordPlace wordPlace);
	static FS_BOOL WordPlaceEqual(FR_VTWordPlace wordPlace, FR_VTWordPlace destWordPlace);
	static FS_INT32 WordPlaceWordCmp(FR_VTWordPlace wordPlace, FR_VTWordPlace destWordPlace);
	static FS_INT32 WordPlaceLineCmp(FR_VTWordPlace wordPlace, FR_VTWordPlace destWordPlace);
	static FS_INT32 WordPlaceSecCmp(FR_VTWordPlace wordPlace, FR_VTWordPlace destWordPlace);
	static void WordPlaceSetSectionIndex(FR_VTWordPlace wordPlace, FS_INT32 nSecIndex);
	static FS_INT32 WordPlaceGetSectionIndex(FR_VTWordPlace wordPlace);
	static void WordPlaceSetLineIndex(FR_VTWordPlace wordPlace, FS_INT32 nLineIndex);
	static FS_INT32 WordPlaceGetLineIndex(FR_VTWordPlace wordPlace);
	static void WordPlaceSetWordIndex(FR_VTWordPlace wordPlace, FS_INT32 nWordIndex);
	static FS_INT32 WordPlaceGetWordIndex(FR_VTWordPlace wordPlace);

	//CFVT_WordRange
	static FR_VTWordRange WordRangeNew();
	static void WordRangeDestroy(FR_VTWordRange wordRange);
	static void WordRangeSetDefault(FR_VTWordRange wordRange);
	static void WordRangeSet(FR_VTWordRange wordRange, FR_VTWordPlace begin, FR_VTWordPlace end);
	static void WordRangeSetBeginPos(FR_VTWordRange wordRange, FR_VTWordPlace begin);	
	static void WordRangeSetEndPos(FR_VTWordRange wordRange, FR_VTWordPlace end);
	static FS_BOOL WordRangeIsExist(FR_VTWordRange wordRange);	
	static FS_BOOL WordRangeEqual(FR_VTWordRange wordRange, FR_VTWordRange destWordRange);
	static void WordRangeSwapWordPlace(FR_VTWordRange wordRange);
	static FR_VTWordPlace WordRangeGetBeginPos(FR_VTWordRange wordRange);
	static FR_VTWordPlace WordRangeGetEndPos(FR_VTWordRange wordRange);

	//CFVT_SecProps
	static FR_VTSecProps SecPropsNew(FS_FLOAT lineLeading, FS_FLOAT lineIndent, FS_INT32 alignment, FS_BOOL softreturn, FS_BOOL bRTL);
	static FR_VTSecProps SecPropsNewII(FR_VTSecProps otherSecProps);
	static void SecPropsDestroy(FR_VTSecProps secProps);
	static void SecPropsSetLineLeading(FR_VTSecProps secProps, FS_FLOAT lineLeading);
	static FS_FLOAT SecPropsGetLineLeading(FR_VTSecProps secProps);
	static void SecPropsSetLineIndent(FR_VTSecProps secProps, FS_FLOAT lineIndent);
	static FS_FLOAT SecPropsGetLineIndent(FR_VTSecProps secProps);
	static void SecPropsSetAlignment(FR_VTSecProps secProps, FS_INT32 alignment);
	static FS_INT32 SecPropsGetAlignment(FR_VTSecProps secProps);
	static void SecPropsSetSoftReturn(FR_VTSecProps secProps, FS_BOOL softreturn);
	static FS_BOOL SecPropsGetSoftReturn(FR_VTSecProps secProps);
	static void SecPropsSetRTL(FR_VTSecProps secProps, FS_BOOL bRTL);
	static FS_BOOL SecPropsGetRTL(FR_VTSecProps secProps);

	//CFVT_WordProps
	static FR_VTWordProps WordPropsNew(FS_INT32	fontIndex, FS_FLOAT fontSize, FS_COLORREF wordColor, FS_INT32 scriptType, FS_INT32 wordStyle, FS_FLOAT charSpace, FS_FLOAT horzScale, FS_FLOAT xOffset, FS_FLOAT yOffset, FS_COLORREF strokeColor, FS_INT32 renderingMode, FS_FLOAT lineWidth, FS_FLOAT wordspace, FS_DWORD dwCharCode, short nAlphal);
	static FR_VTWordProps WordPropsNewII(FR_VTWordProps otherWordProps);
	static void WordPropsDestroy(FR_VTWordProps wordProps);
	static void WordPropsSetFontIndex(FR_VTWordProps wordProps, FS_INT32 fontIndex);
	static FS_INT32 WordPropsGetFontIndex(FR_VTWordProps wordProps);
	static void WordPropsSetFontSize(FR_VTWordProps wordProps, FS_FLOAT fontSize);
	static FS_FLOAT WordPropsGetFontSize(FR_VTWordProps wordProps);
	static void WordPropsSetWordColor(FR_VTWordProps wordProps, FS_COLORREF wordColor);
	static FS_COLORREF WordPropsGetWordColor(FR_VTWordProps wordProps);
	static void WordPropsSetStrokeColor(FR_VTWordProps wordProps, FS_COLORREF dwStrokeColor);
	static FS_COLORREF WordPropsGetStrokeColor(FR_VTWordProps wordProps);
	static void WordPropsSetScriptType(FR_VTWordProps wordProps, FS_INT32 nScriptType);
	static FS_INT32 WordPropsGetScriptType(FR_VTWordProps wordProps);
	static void WordPropsSetWordStyle(FR_VTWordProps wordProps, FS_INT32 nWordStyle);
	static FS_INT32 WordPropsGetWordStyle(FR_VTWordProps wordProps);
	static void WordPropsSetCharSpace(FR_VTWordProps wordProps, FS_FLOAT fCharSpace);
	static FS_FLOAT WordPropsGetCharSpace(FR_VTWordProps wordProps);
	static void WordPropsSetHorzScale(FR_VTWordProps wordProps, FS_FLOAT fHorzScale);
	static FS_FLOAT WordPropsGetHorzScale(FR_VTWordProps wordProps);
	static void WordPropsSetXOffset(FR_VTWordProps wordProps, FS_FLOAT fXOffset);
	static FS_FLOAT WordPropsGetXOffset(FR_VTWordProps wordProps);
	static void WordPropsSetYOffset(FR_VTWordProps wordProps, FS_FLOAT fYOffset);
	static FS_FLOAT WordPropsGetYOffset(FR_VTWordProps wordProps);
	static void WordPropsSetRenderingMode(FR_VTWordProps wordProps, FS_INT32 nRenderingMode);
	static FS_INT32 WordPropsGetRenderingMode(FR_VTWordProps wordProps);
	static void WordPropsSetClientData(FR_VTWordProps wordProps, void* pClientData);
	static void* WordPropsGetClientData(FR_VTWordProps wordProps);
	static void WordPropsSetLineWidth(FR_VTWordProps wordProps, FS_FLOAT fLineWidth);
	static FS_FLOAT WordPropsGetLineWidth(FR_VTWordProps wordProps);
	static void WordPropsSetWordSpace(FR_VTWordProps wordProps, FS_FLOAT fWordSpace);
	static FS_FLOAT WordPropsGetWordSpace(FR_VTWordProps wordProps);
	static void WordPropsSetCharCode(FR_VTWordProps wordProps, FS_DWORD dwCharCode);
	static FS_DWORD WordPropsGetCharCode(FR_VTWordProps wordProps);
	static void WordPropsSetAlpha(FR_VTWordProps wordProps, short nAlpha);
	static short WordPropsGetAlpha(FR_VTWordProps wordProps);

	//CFVT_Word
	static FR_VTWord WordNew();
	static void WordDestroy(FR_VTWord word);
	static void WordSetWord(FR_VTWord VTWord, FS_WORD word);
	static FS_WORD WordGetWord(FR_VTWord word);
	static void WordSetWordDisplay(FR_VTWord word, FS_WORD WordDisplay);
	static FS_WORD WordGetWordDisplay(FR_VTWord word);
	static void WordSetBidiOrder(FR_VTWord word, short nBidiOrder);
	static short WordGetBidiOrder(FR_VTWord word);
	static void WordSetCharset(FR_VTWord word, FS_INT32 nCharset);
	static FS_INT32 WordGetCharset(FR_VTWord word);
	static void WordSetWordPlace(FR_VTWord word, FR_VTWordPlace WordPlace);
	static FR_VTWordPlace WordGetWordPlace(FR_VTWord word);
	static void WordSetWordPoint(FR_VTWord word, FS_FLOAT x, FS_FLOAT y);
	static void WordGetWordPoint(FR_VTWord word, FS_FLOAT* x, FS_FLOAT* y);
	static void WordSetAscent(FR_VTWord word, FS_FLOAT fAscent);
	static FS_FLOAT WordGetAscent(FR_VTWord word);
	static void WordSetDescent(FR_VTWord word, FS_FLOAT fDescent);
	static FS_FLOAT WordGetDescent(FR_VTWord word);
	static void WordSetWidth(FR_VTWord word, FS_FLOAT fWidth);
	static FS_FLOAT WordGetWidth(FR_VTWord word);
	static void WordSetFontIndex(FR_VTWord word, FS_INT32 nFontIndex);
	static FS_INT32 WordGetFontIndex(FR_VTWord word);
	static void WordSetFontSize(FR_VTWord word, FS_FLOAT fFontSize);
	static FS_FLOAT WordGetFontSize(FR_VTWord word);
	static void WordSetWordProps(FR_VTWord word, FR_VTWordProps wordProps);
	static FR_VTWordProps WordGetWordProps(FR_VTWord word);

	//CFVT_Line
	static FR_VTLine LineNew();
	static void LineDestroy(FR_VTLine line);
	static void  LineSetStartWordPlace(FR_VTLine line, FR_VTWordPlace lineplace);
	static FR_VTWordPlace  LineGetStartWordPlace(FR_VTLine line);
	static void  LineSetEndWordPlace(FR_VTLine line, FR_VTWordPlace lineEnd);
	static FR_VTWordPlace  LineGetEndWordPlace(FR_VTLine line);
	static void  LineSetOriginalPosition(FR_VTLine line, FS_FLOAT x, FS_FLOAT y);
	static void  LineGetOriginalPosition(FR_VTLine line, FS_FLOAT* x, FS_FLOAT* y);
	static void  LineSetWidth(FR_VTLine line, FS_FLOAT fLineWidth);
	static FS_FLOAT  LineGetWidth(FR_VTLine line);
	static void  LineSetAscent(FR_VTLine line, FS_FLOAT fLineAscent);
	static FS_FLOAT  LineGetAscent(FR_VTLine line);
	static void  LineSetDescent(FR_VTLine line, FS_FLOAT fLineDescent);
	static FS_FLOAT  LineGetDescent(FR_VTLine line);

	//CFVT_Section
	static FR_VTSection SectionNew();
	static void SectionDestroy(FR_VTSection section);
	static void SectionSetStartWordPlace(FR_VTSection section, FR_VTWordPlace secplace);
	static FR_VTWordPlace SectionGetStartWordPlace(FR_VTSection section);
	static void SectionSetRect(FR_VTSection section, FS_FloatRect rect);
	static FS_FloatRect SectionGetRect(FR_VTSection section);
	static void SectionSetSectionProperties(FR_VTSection section, FR_VTSecProps SecProps);
	static FR_VTSecProps SectionGetSectionProperties(FR_VTSection section);
	static void SectionSetWordProperties(FR_VTSection section, FR_VTWordProps WordProps);
	static FR_VTWordProps SectionGetWordProperties(FR_VTSection section);

	//IFX_VariableText_Iterator
	static FS_BOOL VTIteratorNextWord(FR_VariableText_Iterator iterator);
	static FS_BOOL VTIteratorPrevWord(FR_VariableText_Iterator iterator);
	static FS_BOOL VTIteratorNextLine(FR_VariableText_Iterator iterator);
	static FS_BOOL VTIteratorPrevLine(FR_VariableText_Iterator iterator);
	static FS_BOOL VTIteratorNextSection(FR_VariableText_Iterator iterator);
	static FS_BOOL VTIteratorPrevSection(FR_VariableText_Iterator iterator);
	static FS_BOOL VTIteratorGetWord(FR_VariableText_Iterator iterator, FR_VTWord* outWord);
	static FS_BOOL VTIteratorSetWord(FR_VariableText_Iterator iterator, FR_VTWord word);
	static FS_BOOL VTIteratorGetLine(FR_VariableText_Iterator iterator, FR_VTLine* outLine);
	static FS_BOOL VTIteratorGetSection(FR_VariableText_Iterator iterator, FR_VTSection* outSection);
	static FS_BOOL VTIteratorSetSection(FR_VariableText_Iterator iterator, FR_VTSection section);
	static void VTIteratorSetAt(FR_VariableText_Iterator iterator, FS_INT32 nWordIndex);
	static void VTIteratorSetAtII(FR_VariableText_Iterator iterator, FR_VTWordPlace place);
	static void VTIteratorGetAt(FR_VariableText_Iterator iterator, FR_VTWordPlace* outWordPlace);
	static FS_BOOL VTIteratorGetDisplayWord(FR_VariableText_Iterator iterator, FR_VTWord* outWord);

	//IFX_VariableText	
	static FR_VariableText VariableTextNew();	
	static void	VariableTextDestroy(FR_VariableText variableText);
	static FR_VariableText_Provider  VariableTextProviderNew(FR_VariableTextProviderCallbacks callbacks);
	static void VariableTextProviderDestroy(FR_VariableText_Provider provider);
	static FR_VariableText_Provider VariableTextSetProvider(FR_VariableText variableText, FR_VariableText_Provider provider);
	static FR_VariableText_Iterator VariableTextGetIterator(FR_VariableText variableText);
	static void VariableTextSetPlateRect(FR_VariableText variableText, FS_FloatRect rect, FS_BOOL bVerticalWriting);
	static FS_BOOL VariableTextIsVerticalWriting(FR_VariableText variableText);
	static void VariableTextSetAlignment(FR_VariableText variableText, FS_INT32 nFormat);
	static void VariableTextSetPasswordChar(FR_VariableText variableText, FS_WORD wSubWord);
	static void VariableTextSetLimitChar(FR_VariableText variableText, FS_INT32 nLimitChar);
	static void VariableTextSetCharArray(FR_VariableText variableText, FS_INT32 nCharArray);
	static void VariableTextSetCharSpace(FR_VariableText variableText, FS_FLOAT fCharSpace);
	static void VariableTextSetWordSpace(FR_VariableText variableText, FS_FLOAT fWordSpace);
	static void VariableTextSetHorzScale(FR_VariableText variableText, FS_FLOAT fHorzScale);
	static void VariableTextSetMultiLine(FR_VariableText variableText, FS_BOOL bMultiLine);
	static void VariableTextSetAutoReturn(FR_VariableText variableText, FS_BOOL bAuto);
	static void VariableTextSetAutoFontSize(FR_VariableText variableText, FS_BOOL bAuto);
	static void VariableTextSetFontSize(FR_VariableText variableText, FS_FLOAT fFontSize);
	static void VariableTextSetLineLeading(FR_VariableText variableText, FS_FLOAT fLineLeading);
	static void VariableTextSetRichText(FR_VariableText variableText, FS_BOOL bRichText);
	static void VariableTextSetDirectionRTL(FR_VariableText variableText, FS_BOOL bRTL, FR_VTWordRange PlaceRange);
	static void VariableTextInitialize(FR_VariableText variableText);
	static FS_BOOL VariableTextIsValid(FR_VariableText variableText);
	static FS_BOOL VariableTextIsRichText(FR_VariableText variableText);
	static void VariableTextRearrangeAll(FR_VariableText variableText);
	static void VariableTextRearrangePart(FR_VariableText variableText, FR_VTWordRange PlaceRange);
	static void VariableTextResetAll(FR_VariableText variableText);
	static void VariableTextSetText(FR_VariableText variableText, FS_LPCWSTR text, FS_INT32 charset, FR_VTSecProps pSecProps, FR_VTWordProps pWordProps);
	static void VariableTextInsertWord(FR_VariableText variableText, FR_VTWordPlace place, FS_WORD word, FS_INT32 charset, FR_VTWordProps pWordProps, FS_BOOL bNeedTransform, FR_VTWordPlace* outPlace);
	static void VariableTextInsertSection(FR_VariableText variableText, FR_VTWordPlace place, FR_VTSecProps pSecProps, FR_VTWordProps pWordProps, FR_VTWordPlace* outPlace);
	static void VariableTextInsertText(FR_VariableText variableText, FR_VTWordPlace place, FS_LPCWSTR text, FS_INT32 charset, FR_VTSecProps pSecProps, FR_VTWordProps pWordProps, FR_VTWordPlace* outPlace);
	static void VariableTextDeleteWords(FR_VariableText variableText, FR_VTWordRange PlaceRange, FR_VTWordPlace* outPlace);
	static void VariableTextDeleteWord(FR_VariableText variableText, FR_VTWordPlace place, FR_VTWordPlace* outPlace);
	static void VariableTextBackSpaceWord(FR_VariableText variableText, FR_VTWordPlace place, FR_VTWordPlace* outPlace);
	static FS_FloatRect VariableTextGetPlateRect(FR_VariableText variableText);
	static FS_FloatRect VariableTextGetContentRect(FR_VariableText variableText);
	static FS_INT32 VariableTextGetTotalWords(FR_VariableText variableText);
	static FS_FLOAT VariableTextGetFontSize(FR_VariableText variableText);
	static FS_INT32 VariableTextGetAlignment(FR_VariableText variableText);
	static FS_FLOAT VariableTextGetWordSpace(FR_VariableText variableText);
	static FS_WORD VariableTextGetPasswordChar(FR_VariableText variableText);
	static FS_INT32 VariableTextGetCharArray(FR_VariableText variableText);
	static FS_INT32 VariableTextGetLimitChar(FR_VariableText variableText);
	static FS_BOOL VariableTextIsMultiLine(FR_VariableText variableText);
	static FS_BOOL VariableTextIsAutoReturn(FR_VariableText variableText);
	static FS_FLOAT VariableTextGetHorzScale(FR_VariableText variableText);
	static FS_FLOAT VariableTextGetCharSpace(FR_VariableText variableText);
	static void VariableTextGetBeginWordPlace(FR_VariableText variableText, FR_VTWordPlace* outPlace);
	static void VariableTextGetEndWordPlace(FR_VariableText variableText, FR_VTWordPlace* outPlace);	
	static void VariableTextGetPrevWordPlace(FR_VariableText variableText, FR_VTWordPlace place, FR_VTWordPlace* outPlace);
	static void VariableTextGetNextWordPlace(FR_VariableText variableText, FR_VTWordPlace place, FR_VTWordPlace* outPlace);
	static void VariableTextSearchWordPlace(FR_VariableText variableText, FS_FLOAT x, FS_FLOAT y, FR_VTWordPlace* outPlace);
	static void VariableTextGetUpWordPlace(FR_VariableText variableText, FR_VTWordPlace place, FS_FLOAT x, FS_FLOAT y, FR_VTWordPlace* outPlace);
	static void VariableTextGetDownWordPlace(FR_VariableText variableText, FR_VTWordPlace place, FS_FLOAT x, FS_FLOAT y, FR_VTWordPlace* outPlace);
	static void VariableTextGetLineBeginPlace(FR_VariableText variableText, FR_VTWordPlace place, FR_VTWordPlace* outPlace);
	static void VariableTextGetLineEndPlace(FR_VariableText variableText, FR_VTWordPlace place, FR_VTWordPlace* outPlace);
	static void VariableTextGetSectionBeginPlace(FR_VariableText variableText, FR_VTWordPlace place, FR_VTWordPlace* outPlace);
	static void VariableTextGetSectionEndPlace(FR_VariableText variableText, FR_VTWordPlace place, FR_VTWordPlace* outPlace);
	static void VariableTextUpdateWordPlace(FR_VariableText variableText, FR_VTWordPlace place);
	static void VariableTextAjustLineHeader(FR_VariableText variableText, FR_VTWordPlace place,FS_BOOL bPrevOrNext, FR_VTWordPlace* outPlace);
	static FS_INT32 VariableTextWordPlaceToWordIndex(FR_VariableText variableText, FR_VTWordPlace place);
	static void VariableTextWordIndexToWordPlace(FR_VariableText variableText, FS_INT32 index, FR_VTWordPlace* outPlace);
	static FS_BOOL VariableTextIsSectionComplexScript(FR_VariableText variableText, FR_VTWordPlace place);
	static FS_BOOL VariableTextIsVerticalFont(FR_VariableText variableText, FS_INT32 nFontindex);
	static FPD_VTBulletIterator GetBulletIterator(FR_VariableText variableText);
	//internal interface from fx_edit.h

	//IFX_Edit_FontMap & IPWL_FontMap
	static FR_Edit_FontMap EditFontMapGetDocFontMap(FPD_Document fpdDoc);
	static void EditFontMapEncodeFontAlias(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex, FS_ByteString* outAlias);
	static void EditFontMapGetFontName(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex, FS_ByteString* outName);
	static FS_INT32 EditFontMapGetCharset(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex);
	static void* EditFontMapGetFXFont(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex);
	static FPD_Font EditFontMapGetPDFFont(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex, FS_DWordArray unicodeArray, FS_BOOL bEmbedFont);
	static FS_INT32	EditFontMapGetCharWidthF(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex, FS_DWORD charcode, FS_INT32 level);
	static FS_INT32 EditFontMapCharCodeFromUnicode(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex, FS_WORD word);
	static FS_DWORD EditFontMapGlyphFromCharCode(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex, FS_DWORD charcode);
	static FS_INT32 EditFontMapCharSetFromUnicode(FR_Edit_FontMap editFontMap, FS_WORD word, FS_INT32 nOldCharset);
	static FS_INT32 EditFontMapGetFontIndexByUnicode(FR_Edit_FontMap editFontMap, FS_WCHAR wUnicode, FS_LPCSTR lpsDefaultFontName, FS_DWORD dwFontStyle, FS_INT32 nCharSet, FS_BOOL bNeedEmbed, FS_BOOL bVertical);
	static FS_INT32 EditFontMapGetFontIndex(FR_Edit_FontMap editFontMap, FS_LPCSTR lpsFontName, FS_INT32 nCharset, FS_DWORD dwFontStyle, FS_BOOL bAdd, FS_BOOL bNeedEmbed, FS_BOOL bVertical);
	static FS_BOOL IsEmbedded(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex);
	static FS_BOOL SetFXFMEditFont(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex);
	static FS_BOOL GlyphFromCharCode2(FR_Edit_FontMap editFontMap, FS_WCHAR* wcUnicodes, FS_INT32 nUnicodeCount, FS_DWordArray* outGlyphs, FS_DWordArray* outGlyhCounts);
	static FS_INT32 EditFontMapAddFXFont(FR_Edit_FontMap editFontMap, void* pFXFont, FS_LPCSTR lpsFontName, FS_INT32 nCharset);
	static FS_INT32 EditFontMapAddPDFFont(FR_Edit_FontMap editFontMap, FPD_Font fpdFont, FS_LPCSTR lpsFontName, FS_INT32 nCharset);
	static FPD_Document EditFontMapGetDocument(FR_Edit_FontMap editFontMap);
	static FS_INT32 EditFontMapLoadAllFontByDict(FR_Edit_FontMap editFontMap, FR_PageView frPageView, FPD_Object annotDict, FS_LPCSTR lpsApType);
	static FS_BOOL EditFontMapCheckCharacterIsSupported(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex, FS_DWORD dwUnicode);
	static FS_BOOL EditFontMapGetStandardFont(FR_Edit_FontMap editFontMap, FS_LPCSTR lpsFontName, FS_ByteString* outStandardFont);
	static FS_BOOL EditFontMapIsExternalEmbedFont(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex);

	//IFX_Edit_Iterator
	static FS_BOOL EditIteratorNextWord(FR_Edit_Iterator editIterator);
	static FS_BOOL EditIteratorNextLine(FR_Edit_Iterator editIterator);
	static FS_BOOL EditIteratorNextSection(FR_Edit_Iterator editIterator);
	static FS_BOOL EditIteratorPrevWord(FR_Edit_Iterator editIterator);
	static FS_BOOL EditIteratorPrevLine(FR_Edit_Iterator editIterator);
	static FS_BOOL EditIteratorPrevSection(FR_Edit_Iterator editIterator);
	static FS_BOOL EditIteratorGetWord(FR_Edit_Iterator editIterator, FR_VTWord* outWord);
	static FS_BOOL EditIteratorGetDisplayWord(FR_Edit_Iterator editIterator, FR_VTWord* outWord);
	static FS_BOOL EditIteratorGetLine(FR_Edit_Iterator editIterator, FR_VTLine* outLine);
	static FS_BOOL EditIteratorGetSection(FR_Edit_Iterator editIterator, FR_VTSection* outSection);
	static void EditIteratorSetAt(FR_Edit_Iterator editIterator, FS_INT32 nWordIndex);
	static void EditIteratorSetAtII(FR_Edit_Iterator editIterator, FR_VTWordPlace place);
	static void EditIteratorGetAt(FR_Edit_Iterator editIterator, FR_VTWordPlace* outWordPlace);
	static FR_Edit EditIteratorGetEdit(FR_Edit_Iterator editIterator);

	//IFX_Edit	
	static FR_Edit EditNew();
	static void	EditDel(FR_Edit edit);
	static void EditSetFontMap(FR_Edit edit, FR_Edit_FontMap fontMap, FS_INT32 nDefaultFontIndex);	
	static void EditSetVTProvider(FR_Edit edit, FR_VariableText_Provider provider);	
	static void* EditSetNotify(FR_Edit edit, FR_EditNotifyCallbacks callbacks);
	static void* EditSetOprNotify(FR_Edit edit, FR_EditOprNotifyCallbacks callbacks);
	static FR_Edit_Iterator EditGetIterator(FR_Edit edit);
	static FR_VariableText EditGetVariableText(FR_Edit edit);
	static FR_Edit_FontMap EditGetFontMap(FR_Edit edit);
	static void EditInitialize(FR_Edit edit);
	static void EditSetPlateRect(FR_Edit edit, FS_FloatRect rect, FS_BOOL bPaint, FS_BOOL bVerticalWriting);
	static void EditSetScrollPos(FR_Edit edit, FS_FLOAT x, FS_FLOAT y);
	static FS_BOOL EditIsVerticalWriting(FR_Edit edit);
	static void EditSetAlignmentH(FR_Edit edit, FS_INT32 nFormat, FS_BOOL bPaint);
	static void EditSetAlignmentV(FR_Edit edit, FS_INT32 nFormat, FS_BOOL bPaint);
	static void EditSetPasswordChar(FR_Edit edit, FS_WORD wSubWord, FS_BOOL bPaint);
	static void EditSetLimitChar(FR_Edit edit, FS_INT32 nLimitChar, FS_BOOL bPaint);
	static void EditSetCharArray(FR_Edit edit, FS_INT32 nCharArray, FS_BOOL bPaint);
	static void EditSetCharSpace(FR_Edit edit, FS_FLOAT fCharSpace, FS_BOOL bPaint);
	static void EditSetWordSpace(FR_Edit edit, FS_FLOAT fWordSpace, FS_BOOL bPaint);
	static void EditSetHorzScale(FR_Edit edit, FS_FLOAT fHorzScale, FS_BOOL bPaint);
	static void EditSetLineLeading(FR_Edit edit, FS_FLOAT fLineLeading, FS_BOOL bPaint);
	static void EditSetMultiLine(FR_Edit edit, FS_BOOL bMultiLine, FS_BOOL bPaint);
	static void EditSetAutoReturn(FR_Edit edit, FS_BOOL bAuto, FS_BOOL bPaint);
	static void EditSetAutoFontSize(FR_Edit edit, FS_BOOL bAuto, FS_BOOL bPaint);
	static void EditSetAutoScroll(FR_Edit edit, FS_BOOL bAuto, FS_BOOL bPaint);
	static void EditSetFontSize(FR_Edit edit, FS_FLOAT fFontSize, FS_BOOL bPaint);
	static void EditSetTextOverflow(FR_Edit edit, FS_BOOL bAllowed, FS_BOOL bPaint);
	static void SetDirectionRTL(FR_Edit edit, FS_BOOL bRTL, FS_BOOL bApplyAllSection, FS_BOOL bPaint);
	static FS_BOOL EditIsRichText(FR_Edit edit);
	static void EditSetRichText(FR_Edit edit, FS_BOOL bRichText, FS_BOOL bPaint);
	static FS_BOOL EditSetRichTextFont(FR_Edit edit, FS_LPCSTR lpsFontName, FS_INT32 nFontIndex);
	static FS_BOOL SetRichTextIsBold(FR_Edit edit, FS_BOOL bBold, FS_BOOL bNeedToReaderingMode);
	static FS_BOOL SetRichTextIsItalic(FR_Edit edit, FS_BOOL bItalic);

	static FS_BOOL EditSetRichFontSize(FR_Edit edit, FS_FLOAT fFontSize);
	static FS_BOOL EditSetRichTextColor(FR_Edit edit, FS_COLORREF dwColor);
	static FS_BOOL EditSetRichTextStrokeColor(FR_Edit edit, FS_COLORREF dwColor);
	static FS_BOOL EditSetRichRenderingMode(FR_Edit edit, FS_INT32 nRenderingMode);
	static FS_BOOL EditSetRichTextScript(FR_Edit edit, FS_INT32 nScriptType);
	static FS_BOOL EditSetRichTextUnderline(FR_Edit edit, FS_BOOL bUnderline);
	static FS_BOOL EditSetRichTextCrossout(FR_Edit edit, FS_BOOL bCrossout);
	static FS_BOOL EditSetRichTextCharSpace(FR_Edit edit, FS_FLOAT fCharSpace);
	static FS_BOOL EditSetRichTextWordSpace(FR_Edit edit, FS_FLOAT fWordSpace);
	static FS_BOOL EditSetRichTextHorzScale(FR_Edit edit, FS_FLOAT fHorzScale);
	static FS_BOOL EditSetRichTextLineLeading(FR_Edit edit, FS_FLOAT fLineLeading);
	static FS_BOOL EditSetRichTextLineIndent(FR_Edit edit, FS_FLOAT fLineIndent);
	static FS_BOOL EditSetRichTextAlignment(FR_Edit edit, FS_INT32 nAlignment);
	static FS_BOOL EditSetRichTextSoftReturn(FR_Edit edit, FS_BOOL bEnable);
	static void EditSetSel(FR_Edit edit, FS_INT32 nStartChar,FS_INT32 nEndChar);
	static void EditGetSel(FR_Edit edit, FS_INT32* nStartChar, FS_INT32* nEndChar);
	static void EditSelectAll(FR_Edit edit);
	static void EditSelectNone(FR_Edit edit);
	static FS_INT32 EditGetCaret(FR_Edit edit);
	static void EditGetCaretWordPlace(FR_Edit edit, FR_VTWordPlace* outWordPlace);
	static void EditGetSelText(FR_Edit edit, FS_WideString* outText);
	static void EditGetText(FR_Edit edit, FS_WideString* outText);
	static void EditGetRichTextXML(FR_Edit edit, FS_LPCWSTR ds, FS_BOOL bSaveLineFeed, FS_WideString* outXML);
	static FS_BOOL EditIsSelected(FR_Edit edit);	
	static void EditGetScrollPos(FR_Edit edit, FS_FLOAT* x, FS_FLOAT* y);
	static FS_FloatRect EditGetPlateRect(FR_Edit edit);
	static FS_FloatRect EditGetContentRect(FR_Edit edit);
	static void EditGetVisibleWordRange(FR_Edit edit, FR_VTWordRange* outWordRange);
	static void EditGetWholeWordRange(FR_Edit edit, FR_VTWordRange* outWordRange);
	static void EditGetSelectWordRange(FR_Edit edit, FR_VTWordRange* outWordRange);
	static void EditOnMouseDown(FR_Edit edit, FS_FLOAT x, FS_FLOAT y, FS_BOOL bShift, FS_BOOL bCtrl);
	static void	EditOnMouseMove(FR_Edit edit, FS_FLOAT x, FS_FLOAT y, FS_BOOL bShift, FS_BOOL bCtrl);
	static void EditOnVK_UP(FR_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
	static void EditOnVK_DOWN(FR_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
	static void EditOnVK_LEFT(FR_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
	static void	EditOnVK_RIGHT(FR_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
	static void EditOnVK_HOME(FR_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
	static void EditOnVK_END(FR_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
	static void EditSetText(FR_Edit edit, FS_LPCWSTR text, FS_INT32 charset, FR_VTSecProps secProps, FR_VTWordProps pWordProps);
	static void EditSetRichTextByXML(FR_Edit edit, FS_LPCWSTR xml, FS_LPCWSTR ds, FS_INT32 charset);
	static FS_BOOL EditInsertWord(FR_Edit edit, FS_WORD word, FS_INT32 charset, FR_VTWordProps pWordProps, FS_BOOL bPaint, FS_BOOL bNeedTransform);
	static FS_BOOL EditInsertReturn(FR_Edit edit, FR_VTSecProps secProps, FR_VTWordProps pWordProps, FS_BOOL bPaint);	
	static FS_BOOL EditInsertText(FR_Edit edit, FS_LPCWSTR text, FS_INT32 charset, FR_VTSecProps secProps, FR_VTWordProps pWordProps, FS_BOOL bPaint, FS_BOOL bNeedTransform);
	static FS_BOOL EditBackspace(FR_Edit edit);
	static FS_BOOL EditDelete(FR_Edit edit, FS_BOOL bCtrl);
	static FS_BOOL EditClear(FR_Edit edit);
	static FS_BOOL EditRedo(FR_Edit edit);
	static FS_BOOL EditUndo(FR_Edit edit);
	static void EditSetCaret(FR_Edit edit, FS_INT32 nPos);
	static void EditPaint(FR_Edit edit);
	static void EditEnableRefresh(FR_Edit edit, FS_BOOL bRefresh);
	static void EditRefreshWordRange(FR_Edit edit, FR_VTWordRange wordRange);
	static void EditEnableUndo(FR_Edit edit, FS_BOOL bUndo);
	static void	EditEnableNotify(FR_Edit edit, FS_BOOL bNotify);
	static void EditEnableOprNotify(FR_Edit edit, FS_BOOL bNotify);
	static FS_INT32 EditWordPlaceToWordIndex(FR_Edit edit, FR_VTWordPlace wordPlace);
	static void EditWordIndexToWordPlace(FR_Edit edit, FS_INT32 index, FR_VTWordPlace* outWordPlace);
	static void EditGetLineBeginPlace(FR_Edit edit, FR_VTWordPlace wordPlace, FR_VTWordPlace* outWordPlace);
	static void EditGetLineEndPlace(FR_Edit edit, FR_VTWordPlace wordPlace, FR_VTWordPlace* outWordPlace);
	static void EditGetSectionBeginPlace(FR_Edit edit, FR_VTWordPlace wordPlace, FR_VTWordPlace* outWordPlace);
	static void EditGetSectionEndPlace(FR_Edit edit, FR_VTWordPlace wordPlace, FR_VTWordPlace* outWordPlace);
	static void EditSearchWordPlace(FR_Edit edit, FS_FLOAT x, FS_FLOAT y, FR_VTWordPlace* outWordPlace);
	static FS_FLOAT EditGetFontSize(FR_Edit edit);
	static FS_WORD EditGetPasswordChar(FR_Edit edit);
	static FS_INT32 EditGetCharArray(FR_Edit edit);
	static FS_FLOAT EditGetHorzScale(FR_Edit edit);
	static FS_FLOAT EditGetCharSpace(FR_Edit edit);
	static void EditGetRangeText(FR_Edit edit, FR_VTWordRange wordRange, FS_WideString* outText);
	static FS_BOOL EditIsTextFull(FR_Edit edit);
	static FS_BOOL EditCanUndo(FR_Edit edit);
	static FS_BOOL EditCanRedo(FR_Edit edit);
	static void EditResetUndo(FR_Edit edit);
	static FS_BOOL EditIsModified(FR_Edit edit);
	static FS_INT32 EditGetTotalWords(FR_Edit edit);
	static void* EditAddUndoItem(FR_Edit edit, FR_EditUndoItemCallbacks callbacks);
	static void BeginGroupUndo(FR_Edit edit, FS_LPCWSTR lpwsTitle);
	static void EndGroupUndo(FR_Edit edit);
	static void EditSaveLineOffset(FR_Edit edit);
	static void EditGetEditAppearanceStream(FR_Edit edit, FS_FLOAT x, FS_FLOAT y, FR_VTWordRange wordRange, FS_BOOL bContinuous, FS_WORD SubWord, FR_EDIT_FontData* outFontDataArray, FS_INT32* outFontDataArrayCount, FS_ByteString* outStream);
	static void EditGetRichEditAppearanceStream(FR_Edit edit, FS_FLOAT x, FS_FLOAT y, FR_VTWordRange wordRange, FS_BOOL bContinuous, FS_WORD SubWord, FR_EDIT_FontData* outFontDataArray, FS_INT32* outFontDataArrayCount, FS_ByteString* outStream, FS_ByteString pPathStream);
	static void EditGetSelectAppearanceStream(FR_Edit edit, FS_FLOAT x, FS_FLOAT y, FR_VTWordRange wordRange, FS_ByteString* outStream);
	static void EditDrawEdit(FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device, FR_Edit edit, FS_ARGB crTextFill, FS_COLORREF crTextStroke, FS_FloatRect rcClip, FS_FLOAT x, FS_FLOAT y, FR_VTWordRange wordRange);
	static void EditDrawUnderline(FPD_RenderDevice pDevice, FS_AffineMatrix user2Device, FR_Edit edit, FS_COLORREF color, FS_FloatRect rcClip, FS_FLOAT x, FS_FLOAT y, FR_VTWordRange wordRange);
	static void EditDrawRichEdit(FPD_RenderDevice pDevice, FS_AffineMatrix user2Device, FR_Edit edit,  FS_FloatRect rcClip, FS_FLOAT x, FS_FLOAT y, FR_VTWordRange wordRange, FS_AffineMatrix text2Uer);
	static void EditGeneratePageObjects(void* pPageObjects, FR_Edit edit, FS_FLOAT x, FS_FLOAT y, FR_VTWordRange wordRange, FS_COLORREF crText, FS_PtrArray* outTextObjectArray);
	static void EditGenerateRichPageObjects(void* pPageObjects, FR_Edit edit, FS_FLOAT x, FS_FLOAT y, FR_VTWordRange wordRange, FS_PtrArray* outTextObjectArray, FS_POSITION* outPos, FS_PtrArray* outPathObjectArray);
	static void EditGenerateUnderlineObjects(void* pPageObjects, FR_Edit edit, FS_FLOAT x, FS_FLOAT y, FR_VTWordRange wordRange, FS_COLORREF color);
	static void EditGetRichTextPlainText(FS_LPCWSTR xml, FS_WideString* outText);

	//internal interface from ITouchup.h
	//ITouchup
	static FR_Touchup GetTouchup();
	static void BeginEditTextObject(FR_Touchup touchup, FR_Document frDoc, FR_PageView frPageView, FR_Text_Object_OP* objList, FS_INT32 nObjListCount, FR_Text_Object_OP_Result* pOutResult);
	static void EndEditTextObject(FR_Touchup touchup, FR_Document frDoc, FR_PageView frPageView, FR_Text_Object_OP* objList, FS_INT32 nObjListCount, FR_Text_Object_OP_Result* pOutResult);
    
    //Email
    static void EmailUtilSendMailUseConfig(FS_LPCWSTR toRecipientList, FS_LPCWSTR ccRecipientList, FS_LPCWSTR bccRecipientList, FS_LPCWSTR subject, FS_LPCWSTR message, FS_LPCWSTR attachmentPath, FS_LPCWSTR attachmentName,HWND hWndParent,FS_BOOL asyncMode, FS_BOOL showUI, FR_EmailUtilSendMailCallbacks eventHandler, FS_INT32 *errorCode, FS_INT32 *specificErrorCode, FS_WideString *localizedErrorMessage);
    static void EmailUtilShowAddressBook(FS_WideStringArray *toRecipients, FS_WideStringArray *ccRecipients, FS_WideStringArray *bccRecipients, HWND hWndParent, FS_INT32 editFields, FS_INT32 *errorCode, FS_INT32 *specificErrorCode, FS_WideString *localizedErrorMessage);

	//ILicenceManager
	static FS_BOOL IsKeyAndTrialValid();
	static FS_BOOL CheckLicense();

	//ifxet_vt.h
	static FS_BOOL EditIsPunctuation(FS_DWORD word);
	static FS_BOOL EditIsCJK(FS_DWORD word);
	static FS_BOOL EditIsLatin(FS_DWORD word);
	static FS_BOOL EditIsNeedToConvertSpace(FS_DWORD word);

	static void GetCustomString(FS_LPCSTR lpsKey, FS_WideString* outValue);

	//IFX_Edit 7.0.5 
	static void EditDestroyNotify(void* editNotify);
	static void EditDestroyOprNotify(void* editOprNotify);
	//for sharereview
	static void SetDocReviewIdentity(FR_Document frDoc, FS_LPCWSTR lpwsIdName, FS_LPCWSTR lpwsIdEmailAddr);
	static void GetDocReviewIdentityName(FR_Document frDoc, FS_WideString* outIdName);
	static void GetDocReviewIdentityEmail(FR_Document frDoc, FS_WideString* outIdEmailAddr);

	//internal interface from ITouchup.h
	//ITouchup sdk 7.1.0.0
	static FS_BOOL HasVisibleTextObj(FR_Touchup touchup, FR_Document frDoc, FR_PageView pageView, FS_BOOL bPopDlg);

	//IReader_ProfStoreManager sdk 7.1.0.0
	static FR_ProfStore GetProfStoreManager();
	static FS_BOOL ProfStoreGetString(FR_ProfStore profStore, FS_LPCWSTR lpRegSection, FS_LPCWSTR lpRegKey, FS_LPCWSTR lpXmlSection, FS_LPCWSTR lpXmlKey, FS_LPCSTR lpAttrib, FS_WideString* outValue, FS_BOOL bUseDefValue);
	static FS_BOOL ProfStoreGetInt(FR_ProfStore profStore, FS_LPCWSTR lpRegSection, FS_LPCWSTR lpRegKey, FS_LPCWSTR lpXmlSection, FS_LPCWSTR lpXmlKey, FS_LPCSTR lpAttrib, DWORD* outValue, FS_BOOL bUseDefValue);
	static FS_BOOL ProfStoreGetBoolean(FR_ProfStore profStore, FS_LPCWSTR lpRegSection, FS_LPCWSTR lpRegKey, FS_LPCWSTR lpXmlSection, FS_LPCWSTR lpXmlKey, FS_LPCSTR lpAttrib, FS_BOOL* outValue, FS_BOOL bUseDefValue);
	static FS_BOOL ProfStoreEnumAllKeyName(FR_ProfStore profStore, FS_LPCWSTR lpRegSection, FS_LPCWSTR lpXmlSection, FS_LPCWSTR lpXmlKey, FS_LPCSTR lpAttrib, FS_WideStringArray* outArrKeyName);
	static FS_BOOL ProfStoreEnumKeyName(FR_ProfStore profStore, FS_LPCWSTR lpRegSection, FS_LPCWSTR lpXmlSection, FS_LPCWSTR lpXmlKey, FS_LPCSTR lpAttrib, FS_WideStringArray* outArrKeyName);
	static FS_BOOL ProfStoreEnumKeyValueName(FR_ProfStore profStore, FS_LPCWSTR lpRegSection, FS_LPCWSTR lpXmlSection, FS_LPCWSTR lpXmlKey, FS_LPCSTR lpAttrib, FS_WideStringArray* outArrKeyValueName);
	static FS_BOOL ProfStoreEnumKeyValue(FR_ProfStore profStore, FS_LPCWSTR lpRegSection, FS_LPCWSTR lpXmlSection, FS_LPCWSTR lpXmlKey, FS_LPCSTR lpAttrib, FS_WideStringArray* outArrKeyValue);

	//CGW_L10NHelper sdk 7.1.0.0
	static void	GWL10NHelperAutoResizeDropWidth(void* pComboBox);
	static void GWL10NHelperResetItemDropWidth(void* pCWnd);

	//sdk 7.2.0.0
	static HWND GetActivePopupMenuMessageWnd();

	static void GetPhoneNumber(FS_WideString* wsSales, FS_WideString* wsSupport);
	static void GetEditionTitle(FS_WideString* wsExpress, FS_WideString* wsStandard, FS_WideString* wsBusiness);
	static void GetEmail(FS_WideString* wsSales, FS_WideString* wsSupport);

	//ifxet_vt.h
	static FS_BOOL EditGetWordLatinSmallLigature(FS_DWORD* src, FS_INT32 nSrcCount, FS_DWORD* outDest, int* outDstCount);

	//sdk 8.0.0.0
	//Common\include\helper_function.h
	static FPD_Document GetClonedDoc(FPD_Document pSrcDoc);

	//IFX_Edit_FontMap & IPWL_FontMap
	static void EditFontMapReleaseDocFontMap(FPD_Document fpdDoc);

	//fr_IActionWizard.h
	static void* CreateActionWizardHandlerMgr(FR_ActionWizardHandlerMgrCallbacks callbacks);
	static void DestroyActionWizardHandlerMgr(void* actionWizardHandlerMgr);
	static void SetActionWizardHandlerMgr(void* pActionWizardHandlerMgr);
	static void* GetActionWizardHandlerMgr();

	static FR_ActionWizardHandler CreateActionWizardHandler(FR_ActionWizardHandlerCallbacks callbacks);
	static void DestroyActionWizardHandler(FR_ActionWizardHandler actionWizardHandler);
	static FS_BOOL RegisterActionWizardHandler(FR_ActionWizardHandler actionWizardHandler);
	static FS_BOOL UnRegisterActionWizardHandler(FR_ActionWizardHandler actionWizardHandler);
	static void ActionWizardHandlerGetName(FR_ActionWizardHandler actionWizardHandler, FS_ByteString outName);
	static void ActionWizardHandlerGetCommandName(FR_ActionWizardHandler actionWizardHandler, FS_ByteString outCommandName);
	static FS_INT32 ActionWizardHandlerGetPresetFlag(FR_ActionWizardHandler actionWizardHandler,FS_XMLElement pXML);
	static FS_BOOL ActionWizardHandlerSetting(FR_ActionWizardHandler actionWizardHandler, FS_XMLElement pXML, HWND hWnd);
	static FS_BOOL ActionWizardHandlerExecute(FR_ActionWizardHandler actionWizardHandler, FS_XMLElement pXML, FS_BOOL bpromptUser, FRActionWizardExcuteStatus* outStatus);
	static FS_BOOL ActionWizardHandlerGetTitle(FR_ActionWizardHandler actionWizardHandler, FS_LPCSTR lpsName, FS_WideString outTitle, FS_XMLElement pXML);
	static FS_BOOL ActionWizardHandlerNeedReopen(FR_ActionWizardHandler actionWizardHandler);
	static FS_BOOL ActionWizardHandlerNeedChangeExecuteDoc(FR_ActionWizardHandler actionWizardHandler);
	//sdk 8.0
	static FS_BOOL ExportAnnotToXFDF2(void* pAnnot, FS_XMLElement xmlElement,FS_BOOL bShareReview);
	static void* ImprotAnnotFromXFDF2(FR_Document frDoc, FS_XMLElement xmlAnnot, FS_BOOL bSendAnnotChangeToNotify, FS_BOOL bShareReview, FS_ByteString bsUserId, FS_BOOL* pbEditing);

	//ISubscriptionProvider 
	static FS_BOOL SubscribeShowRibbonUI(FRSubscriptionFlowName subWorkflowName);
	static FS_BOOL SubscribeStartWorkflow(FRSubscriptionFlowName subWorkflowName, FS_WideString outReturnValue);
	static FS_BOOL SubscribeIsLicenseRevoked();
	static FS_BOOL SubscribeShowFlash();

	//IReader_CPDFPluginProvider
	static FR_CPDFPluginProvider CPDFPluginProviderSet(FR_CPDFPluginProviderCallbacks callbacks);
	static void CPDFPluginProviderDestroy(FR_CPDFPluginProvider loginProvider);
	static FR_CPDFPluginProvider CPDFPluginProviderGet();
	static FS_BOOL CPDFPluginProviderShowConnectedPDFAdDialog(FR_CPDFPluginProvider loginProvider);

	//ILicenceManager
	static FS_INT32 GetRemainDays();

	//ICommentsAnnot.h
	static FS_DWORD CommentsAnnotSetUpdateServerTime(FR_Document frDoc, FS_XMLElement pAnnot);

	//ILicenceManager
	static void GetLicenseSN(FS_WideString* outSN);
	static FS_INT32 GetKeyfileType();

	//sdk version 802
	static void GetFormatSymbolString(FS_LPCWSTR str, FS_BOOL bInput, FS_BOOL bSeperate, FS_WideString* outResult);

	//sdk version 8.1
	static void GetLocalFormatTimeString(SYSTEMTIME* sys, FS_WideString* outFormat);

	//IConvertToPDF
	static FS_INT32 ConvertToPDFGetFileType(FS_LPCWSTR lpwsFile);
	static void GetFileFilter(unsigned long uFilter, FS_WideString* outFilter);

	//Ϊ���޸�ActionWizard��Bug 0082244����Ϊqiuling����޷��������̣���Ӵ˽ӿ���ʱ������Ժ�ɾ����
	static FS_BOOL RegisterDocHandlerOfPDDocForActionWizard(FR_DocEventForActionWizardCallbacks docEventCallbacks);

	//sdk version 8.2
	//ICommentsAnnot.h
	// PHANTOM-6906
	static void CommentsAnnotSetIconState(FR_Document frDoc, FS_INT32 nPageIndex, FS_LPCWSTR lpwsAnnotName, FRCommentsAnnotIconState nIconState);

	//PHANTOM-7084
	static void GetAnnotInputFontName(FS_WideString* outFontName);

	//sdk version 9.0

	//enterprisecustom.h
	static FS_BOOL IsDisableCPDF();

	//js plugin
	static FS_BOOL RunJSPluginByFlag(FS_DWORD dwFlag);
	static FS_BOOL RunJSPluginByName(FS_LPCSTR lpsName);
	static FS_BOOL IsJSPanelActivated(FS_LPCSTR lpsName);
	static void ExpandJSPanel(FS_LPCSTR lpsName, FS_BOOL bExpand);

	//IFX_Edit
	static void* EditSetDrawNotify(FR_Edit edit, FR_EditDrawNotifyCallbacks callbacks);
	static void EditDestroyDrawNotify(void* editDrawNotify);

	//email
	static void EmailUtilRegisterPreSendMailHandler(FR_EmailUtilPreSendMailCallbacks eventHandler);

	static void GetCurEditonTitle(FS_WideString* outTitle);

	static FS_BOOL IsDisableInternet(FS_BOOL bShowDisableMessageBox);	
	static FS_BOOL IsUseSystemSelectionColor();

	//IFX_Edit
	static void EditSetSelBkColor(FR_Edit edit, FS_ARGB color);
	static void EditDrawRichEdit2(FPD_RenderDevice pDevice, FS_AffineMatrix user2Device, FR_Edit edit,  FS_FloatRect rcClip, 
		FS_FLOAT x, FS_FLOAT y, FR_VTWordRange wordRange, FS_AffineMatrix text2Uer, FS_COLORREF cShowColor);

	//js plugin
	static FS_BOOL IsJSPluginDisabled(FS_LPCSTR lpsName);

	//Reading Order
	static FS_INT32 GetAccReadingOrderMode();
	static FS_BOOL IsAccOverrideReadingOrder();
	static FS_INT32 GetDocAccReadingOrder(FR_Document frDoc);
	static FS_INT32 GetDocAccReadingMode(FR_Document frDoc);
	static void SetReadActivateStatus(FS_BOOL bActivateRead);
	static FS_BOOL GetReadActivateStatus();

	//IReader_WIPPluginProvider
	static FR_WIPPluginProvider WIPPluginProviderSet(FR_WIPPluginProviderCallbacks callbacks);
	static void WIPPluginProviderDestroy(FR_WIPPluginProvider loginProvider);
	static FR_WIPPluginProvider WIPPluginProviderGet();
	static FS_BOOL WIPPluginProviderAllowedPaste();

	//PHANTOM-8714 HCMT = HighContrastModeTheme
	static FS_BOOL ThemeCheckHCMT();
	static void ThemeGetTextColor(FS_COLORREF* clrText);
	static void ThemeGetDisableTextColor(FS_COLORREF* clrDisableTextColor);
	static void ThemeGetHyperlinkTextColor(FS_COLORREF* clrText);
	static void ThemeGetSelectedTextColor(FS_COLORREF* clrTextColor, FS_COLORREF* clrBackgroundColor);
	static void ThemeGetButtonTextColor(FS_COLORREF* clrBtnTextColor, FS_COLORREF* clrBackgroundColor);
	static void ThemeGetTooltipColor(FS_COLORREF* clrTextColor, FS_COLORREF* clrBackgroundColor);
	static void ThemeGetBackgroundColor(FS_COLORREF* clrBkColor);

	//email
	static void EmailUtilRegisterAttachmentNameModifier(FR_EmailUtilAttachmentNameModifier modifier);

	//sdk version 9.1
	static void GetAppSaveAsLocation(FS_WideString wsFullPath);
	static void LoadJSPlugin(FS_BOOL bSlient);
	//fr_IActionWizard.h
	static FS_BOOL ActionWizardHandlerIsEnableExecute(FR_ActionWizardHandler actionWizardHandler);
	static void ActionWizardHandlerExecuteDone(FR_ActionWizardHandler actionWizardHandler);
	//sdk version 9.4
	//IFX_Edit_FontMap & IPWL_FontMap
	static FS_INT32 EditFontMapGetFontIndexByUnicode2(FR_Edit_FontMap editFontMap, FS_WCHAR wUnicode, FS_LPCSTR lpsDefaultFontName, FS_DWORD dwFontStyle, FS_INT32 nCharSet, FRFMTribool bNeedEmbed, FS_BOOL bVertical);
	static FS_INT32 EditFontMapGetFontIndex2(FR_Edit_FontMap editFontMap, FS_LPCSTR lpsFontName, FS_INT32 nCharset, FS_DWORD dwFontStyle, FS_BOOL bAdd, FRFMTribool bNeedEmbed, FS_BOOL bVertical);
	
	static FR_Compare_Results* CompareGetDifInfos(FPD_Page pageOld, FPD_Page pageNew, FS_INT32 nOpt);
	static void CompareReleaseDifInfos(FR_Compare_Results* pCompareResults);
	static void CompareDrawNoteAP(FPD_Document pDocument, FPD_Object pAnnotDic, COLORREF color, int nLineWidth, int nOpacity, FS_INT32 nNoteType, FS_FLOAT x, FS_FLOAT y);
	static void GetCreationDate(FPD_Document pDocument,FS_WideString outCreationDate);

	//Read Status
	static void SetReadStatus(FS_BOOL bActivateRead);
	static FS_BOOL GetReadStatus();

	//sdk version 9.6
	//ILicenceManager
	static FS_BOOL CheckActualLicense();

	//sdk version 10.0
	static FR_Document OpenCreatedPDFDoc(const FS_WideString csFilePath, const FS_WideString csTitle);
	//ILicenceManager
	static FS_BOOL	GetIsPheeMode();

	//IFX_Edit
	static void EditSetEastenArabicNumeralMode(FR_Edit edit, FS_BOOL bEastenArabic);

	// ILogger
	static FR_ActionWizardLogger ActionWizardLogCreate();
	static void ActionWizardLogWriteDetailInfo(FR_ActionWizardLogger logger, const FS_WideString wsType, const FS_WideString wsValue);
	static void ActionWizardLogWriteCurrentTime(FR_ActionWizardLogger logger, const FS_WideString wsInfo);
	static void ActionWizardLogWriteBoundaryInfo(FR_ActionWizardLogger logger, FS_BOOL bBoundary);
	static void ActionWizardLogGenerate(FR_ActionWizardLogger logger, const FS_WideString wsFileFolder, FS_WideString* wsName);
	static void ActionWizardLogClose(FR_ActionWizardLogger logger);
	static void ActionWizardLogWrite(FR_ActionWizardLogger logger, FRActionWizardLogType nType, FS_WideString* wsTip);
	static FS_BOOL ActionWizardLogGetState(FR_ActionWizardLogger logger);
	static void ActionWizardLogGetLastFilePath(FR_ActionWizardLogger logger, FS_WideString* filePath);
	static void ActionWizardLogSetCurFilePath(FR_ActionWizardLogger logger, const FS_WideString wsFilePath);
	static void ActionWizardLogSetExcuteFileStatus(FR_ActionWizardLogger logger, FS_BOOL bSuccess);

	//ILicenceManager
	static FS_BOOL GetUpgExpDate(FS_WideString* wsUpgExpDate);
	static FS_BOOL IsUsedAnotherPerpetualLicense();

	//IBaseAnnot
	static FS_BOOL BaseAnnoteIsSnap2GridEnabled();
	static FS_BOOL BaseAnnoteGetGridLine(FR_PageView pPageView, FS_DWordArray XArray, FS_DWordArray YArray);
	static FS_BOOL BaseAnnoteGetGridMainLine(FR_PageView pPageView, FS_DWordArray XArray, FS_DWordArray YArray);

	static void AddDocToPrivilegedList(FR_Document frDoc, FS_BOOL bCkeckURL);
	static FS_BOOL	IsPrivilegedFile(FR_Document frDoc);

	//sdk version > 9.7.1
	static FS_BOOL IsDisableInternet2(FS_LPCWSTR wsPluginName, FS_BOOL bShowDisableMessageBox);

	static FS_BOOL IsSimpleChineseVersion();
	static void GetLicensee(FS_WideString* outLicensee);

	//sdk version > 10.1
	//IFX_Edit_FontMap & IPWL_FontMap
	static FS_INT32 EditFontMapGetFontIndexByUnicode3(FR_Edit_FontMap editFontMap, FS_WCHAR wUnicode, FS_LPCWSTR lpsDefaultFontName, FS_DWORD dwFontStyle, FS_INT32 nCharSet, FRFMTribool bNeedEmbed, FS_BOOL bVertical);
	static FS_INT32 EditFontMapGetFontIndex3(FR_Edit_FontMap editFontMap, FS_LPCWSTR lpsFontName, FS_INT32 nCharset, FS_DWORD dwFontStyle, FS_BOOL bAdd, FRFMTribool bNeedEmbed, FS_BOOL bVertical);
	static FS_INT32 EditFontMapAddFXFont2(FR_Edit_FontMap editFontMap, void* pFXFont, FS_LPCWSTR lpsFontName, FS_INT32 nCharset);
	static FS_INT32 EditFontMapAddPDFFont2(FR_Edit_FontMap editFontMap, FPD_Font fpdFont, FS_LPCWSTR lpsFontName, FS_INT32 nCharset);
	static FS_BOOL EditSetRichTextFont2(FR_Edit edit, FS_LPCWSTR lpsFontName, FS_INT32 nFontIndex);
	static void EditFontMapGetFontName2(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex, FS_WideString* outName);
	static void ClearDragRects();

	//IBA_AnnotHandler
	static void OnMovedByPoint(FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 nMovingType, const FS_FloatPoint& ptOrigin, const FS_FloatPoint& ptNew);
	static void OnMovedByRect(FR_PageView pPageView, FR_Annot pAnnot, const FS_Rect& rcOrigin, const FS_Rect& rcNew);

	static void SaveKeepToolSelectedToRegistry(FS_WideString csRegPath);
	static void EnableKeepToolSelected(FS_BOOL bEnable);
	static FS_BOOL ChangeKeepToolSelectedStateFromRegistry(FS_WideString csRegPath, FS_BOOL bDefault);
	static void AddDragRect(FR_PageView pPageView, const FS_Rect rcDrag);

	//IUndo
	static void Reset(FR_Document pDocument);
	static void RunPageFlat(FPD_Document pPDFDoc, FPD_Object pPageDict, FS_PtrArray vecAnnotDict);

	static void GetCurrentUserName(FS_WideString csEmail, FS_WideString* wsName);	

	//IReader_AttachmentPanelMgr
	static FS_BOOL  EncryptAttachment(FR_Document pDocument, FS_BOOL bEncrypt);
	//ITB_SysFont
	static FS_INT32 GetAllFormatFontSize();
	static void GetAtAllFormatFont(FS_INT32 index, FS_WideString* sFaceName);
	static void GetFontFaceNameBoldItalic(const FS_WideString& sFontName, FS_WideString* sFaceName, FS_BOOL& bBold, FS_BOOL& bItalic);

	//IFX_Edit_FontMap
	static FS_BOOL GetFontStyle(FR_Edit_FontMap editFontMap,FS_INT32 nFontIndex, FS_DWORD* dwFontStyle, FS_INT32* nCharset);

	//IFX_VariableText
	static void EditSetEnableMLAutoFullFontSize(FR_Edit edit, FS_BOOL bEnable);

	//IReader_DocProcessMgr
	static FS_BOOL	FlattenDynamicXFADoc(FR_Document pDoc, const FS_WideString& cwNewFilePath, FR_UIProgress pProgress);

	//IEnterpriseCustom
	static FS_BOOL IsSelfSignCertGen(FS_BOOL &bSelfSignCertGen);

	//CGW_CertCommon
	static FS_BOOL GetIsCheckPrivateKeyCert();

	//IReader_EmailUtil
	static void ParseMailtoURI(const FS_WideString &wsMailtoURI,FS_WideString &wsTo,FS_WideString &wsCc,FS_WideString &wsBcc,FS_WideString &wsSubject,FS_WideString &wsBody);
	static FS_BOOL IsMailtoURI(const FS_WideString &wsString);

	//ITagPDF
	static void AsyncUpdateCheckerInfo(FR_Document pRDDoc, const FS_DWORD dwRule, const FR_PDFAccessibilityCheckerState state);

	//CSG_ToolHandler
	static FS_BOOL IsCurrentTool();
	static void SetToolMode(FR_SGToolMode  tm);
	static FR_SGToolMode GetToolMode();
	static void SetPreToolHandler(FR_Tool pPreToolHandler);

	static void EmailUtilSendMailUseConfig2(FS_LPCWSTR toRecipientList,
		FS_LPCWSTR ccRecipientList, FS_LPCWSTR bccRecipientList,
		FS_LPCWSTR subject, FS_LPCWSTR message, FS_WideStringArray attachmentPathArr, FS_WideStringArray attachmentNameArr,
		HWND hWndParent, FS_BOOL asyncMode, FS_BOOL showUI, FR_EmailUtilSendMailCallbacks eventHandler,
		FS_INT32 *errorCode, FS_INT32 *specificErrorCode, FS_WideString *localizedErrorMessage);	

	//CGW_BitmapDealWith	
	static void	 DIBSourceToBmp(FS_DIBitmap pBitmap, FS_INT32& nLen, FS_ByteArray& byteArray);

	//ITB_Bullet
	static void					BeginBulletEditing(FR_PageView pageview, FS_LPVOID pEdit);
	static void					BeginBulletEditing2(FR_Document pDoc, FS_LPVOID pEditCombtn);
	static FS_LPVOID			SetNotify(FR_BulletNotifyCallbacks pNotify);
	static void					OnCharTab(FS_FLOAT fIndentValue);

	static void                 GetLicenseEditon(FS_WideString* outEditon);

	//CFVT_SecProps
	static FS_FLOAT             GetPropsSecSpace(FR_VTSecProps secProps);

	//IUndo
	static FS_BOOL				IsUndoRedoing(FR_Document document);
	static FS_LPVOID            BeginGroup(FR_Document document, const FS_WideString sDesc, FS_BOOL bGroupSingle);
	static void                 EndGroup(FR_Document document, FS_BOOL bEdit);
	static void                 GetUndoDescription(FR_Document document, FS_WideString* wsDescription);
	static void                 GetRedoDescription(FR_Document document, FS_WideString* wsDescription);

	//IBaseAnnot
	static void                 LoadPopupMenuString(FR_Document document, FS_INT32 nIndex, FS_WideString* wsMenustr);

	//ITB_Bullet
	static void                 ReleaseBulletNotify(FS_LPVOID pBulletNotify);
	static void					EndBulletEditing();
	static FS_BOOL				IsSupportSymbol(FS_WCHAR ch);

	//IOCRMgr
	static FS_BOOL				RunOCR(FPD_Page pPDFPage, FS_BOOL bEditMode);
	static void                 GetLocalAbyLan(FS_WideString* wsLan);
	static void                 bExistFX_Abbyy_Ocr_dll(FS_WideString* wsLan);
	static FS_BOOL              GetOCREngineSupportLan(FS_WideStringArray* aLanguage, FS_WideStringArray* wsAbbyLanName, FS_WideStringArray* wsAryEngineLanName);

	//IBaseAnnot
	static FS_LPVOID            LoadAnnotIcon(FS_INT32 nIconType);

	//ISubscriptionProvider 	
	static FS_BOOL SubscribeIsEducation();
	
	static FR_RibbonElement      AddFloatyBarBtn(FR_Ribbon_Element_Type nElementType, const FS_CHAR* name, FS_LPCWSTR lpwsTitle);
	static void                  AddRibbonBtnsToFloaty(FS_ByteStringArray pAryBeShowBtnName);
	static FS_LPVOID             CreateRibbonFloaty(FS_FloatPoint point);

	//IUndo
	static void					Undo(FR_Document pDocument);
	static void					Redo(FR_Document pDocument);

	//PWL_CREATEPARAM
	static void            PWLWndCreationParamSetSystemHandler(void* pCreationParam, FS_LPVOID handler);
	static void            PWLWndCreationParamSetProvider(void* pCreationParam, FPD_CPWL_Provider handler);
	static void            PWLWndCreationParamSetFocusHandler(void* pCreationParam, FPD_CPWL_FocusHandler handler);
	static void            PWLWndCreationParamSetBackgroundColor(void* pCreationParam, FS_INT32 type, FS_FLOAT color1, FS_FLOAT color2, FS_FLOAT color3, FS_FLOAT color4);
	static void            PWLWndCreationParamSetAttachedWnd(void* pCreationParam, FS_LPVOID wnd);
	static void			   PWLWndCreationParamSetSpellCheck(void* pCreationParam, FPD_SpellCheck spellcheck);
	static void			   PWLWndCreationParamSetBorderStyle(void* pCreationParam, FS_INT32 borderStyle);
	static void			   PWLWndCreationParamSetBorderWidth(void* pCreationParam, FS_INT32 borderWidth);
	static void			   PWLWndCreationParamSetBorderColor(void* pCreationParam, FS_INT32 type, FS_FLOAT color1, FS_FLOAT color2, FS_FLOAT color3, FS_FLOAT color4);
	static void			   PWLWndCreationParamSetTextStrokeColor(void* pCreationParam, FS_INT32 type, FS_FLOAT color1, FS_FLOAT color2, FS_FLOAT color3, FS_FLOAT color4);
	static void            PWLWndCreationParamSetTransparency(void* pCreationParam, FS_INT32 transparency);
	static void            PWLWndCreationParamSetUseFXFontDeAscent(void* pCreationParam, FS_BOOL bUse);
	static void            PWLWndCreationParamSetDash(void* pCreationParam, FPDCPWL_Dash dash);
	static void            PWLWndCreationParamSetAttachedData(void* pCreationParam, FS_LPVOID data);
	static void            PWLWndCreationParamSetParentWnd(void* pCreationParam, FPD_CPWL_Wnd wnd);
	static void            PWLWndCreationParamSetCursorType(void* pCreationParam, FS_INT32 type);
	static void            PWLWndCreationParamSetMtChild(void* pCreationParam, FS_AffineMatrix mt);
	static void            PWLWndCreationParamSetShowFontSizeDPI(void* pCreationParam, FS_FLOAT dpi);
	static void            PWLWndCreationParamSetNeedEmbed(void* pCreationParam, FS_BOOL bEmbed);

	//GlobalWnd
	static FS_BOOL		   OpenCertifiedPDF2(FPD_Parser parser, FS_WideString cwPDFPath, FS_BOOL bShowPassDlg, FS_BOOL *pbCancel);
	static FS_BOOL		   FieldsMutiCopy(FS_LPVOID pParent, FR_IFieldMulCopiesNotify pNotify, FS_PtrArray MSource, FS_FloatRect rcView, FS_BOOL bEnableSameName, FS_INT32 nRotate);
	static FS_LPVOID	   CreateDigitalID(FS_LPVOID pParent, FS_WideString* cwFileName, FS_WideString* cwPassWord);
	static FS_BOOL		   OpenDigitalIDsManager(FS_LPVOID pParent);
	//CGW_CertCommon
	static void            SetIsCheckPrivateKeyCert(FS_BOOLEAN bCheck);

	static void*           PWLWndCreationParamNew2(FS_LPVOID  curCreationparam);

	//IFX_Edit_FontMap
	static void            ArabicResetWord(FR_Edit_FontMap editFontMap, FS_UINT nFontIndex, FS_LPCWSTR wsArabic, FS_WideString* outWord);
	//GlobalWnd
	static void			   OnDestroyDocView(FR_DocView pDocView);

	static void           EditSetText2(FR_Edit edit, FS_LPCWSTR text, FS_INT32 charset, FR_VTSecProps secProps, FR_VTWordProps pWordProps, FS_BOOLEAN bNeedEmbed);
	//IReader_WIPPluginProvider EDP插件
	static FS_BOOL        WipPluginEncryptFile(FS_LPCWSTR wszFilePath);
	//IReader_PrintMgr,后续会从print插件中导出
	static FR_PrintMgr    CreatePrintMgr(FR_Document doc, FS_BOOL bQuietMode, FS_LPCWSTR wsSummarizeComments);
	static void SetPrintRange(FR_PrintMgr printMgr, FS_INT32 nRangeMode, FS_INT32 nFrom , FS_INT32 nTo);
	static void SetPrintRotate(FR_PrintMgr printMgr, FS_INT32 nRotateMode);
	static void SetPrintScale(FR_PrintMgr printMgr, FS_INT32 nZoomToMode, FS_FLOAT flScale);
	static void SetPrintAutoCenter(FR_PrintMgr printMgr, FS_BOOLEAN bAutoCenter);
	static void SetPrintAutoRotate(FR_PrintMgr printMgr, FS_BOOLEAN bAutoRotate);
	static void SetPrintGray(FR_PrintMgr printMgr, FS_BOOLEAN bGray);
	static void SetPrintCollate(FR_PrintMgr printMgr, FS_BOOLEAN bCollate);
	static void SetPrintPageOrder(FR_PrintMgr printMgr, FS_INT32 nOrderMode);
	static void SetPrintPrintWhat(FR_PrintMgr printMgr, FS_INT32 nPrintWhatMode);
	static void SetPrintOrientation(FR_PrintMgr printMgr, FR_PrintOrientationType nPrintOriType);
	static void SetPrintPagesPerSheet(FR_PrintMgr printMgr, FS_INT32 nPerSheetMode, FS_INT32 nHorzs, FS_INT32 nVerts);
	static void SetPrintPaperSizeByPage(FR_PrintMgr printMgr, FS_BOOLEAN bPaperSizeByPage);
	static void SetPrintReverse(FR_PrintMgr printMgr, FS_BOOLEAN bReverse);
	static void SetPrintMargins(FR_PrintMgr printMgr, FS_FLOAT flMargins);
	static void SetPrintAsImage(FR_PrintMgr printMgr, FS_BOOLEAN bPrintAsImage);
	static void SetSimulateOverprinting(FR_PrintMgr printMgr, FS_BOOLEAN bSimulateOverprintint);
	static void SetPrintIgnoreAdvancedSetting(FR_PrintMgr printMgr, FS_BOOL bIgnoreAdvanced);
	static void SetProgressDisplay(FR_PrintMgr printMgr, FS_BOOL bShow);
	static void SetPaperSize(FR_PrintMgr printMgr, FS_INT32 papersize);
	static void SetPrintPageArray(FR_PrintMgr printMgr, FS_WordArray PageArray);
	static FS_LPCWSTR GetDefaultPrint(FR_PrintMgr printMgr);
	static void SetDefaultPrint(FR_PrintMgr printMgr, FS_LPCWSTR  strPrinterName);
	static void SetPrintOutputFileName(FR_PrintMgr printMgr, FS_LPCWSTR wsOutputFileName);
	static FS_INT32  DoModal(FR_PrintMgr printMgr, FS_HWND hParentHwnd);
	static void   DeletePrintMg(FR_PrintMgr printMgr);
	//search插件,后续从search插件中导出
	static FS_BOOL IsSearchingText(FR_Document doc);
	//creator插件
	static FS_BOOLEAN WaitingFileClosed(FS_LPCWSTR filePath, FS_INT32 tryTimes, FS_INT32 perSleepTime);
	static FS_BOOLEAN	ConvertPdfFromWeb(FS_HWND hParentWnd, FS_LPCWSTR csWindowTitle, FS_WideString* csOutputFilepath, FS_WideString* wsOutputUrl);
	static FS_BOOL GetFromClipboard(FS_LPWSTR pszDest);
	//scanner 插件
	static FR_SNTwainDriver CreateTwainDriver(FS_LPVOID pParentWnd);
	static void DeleteTwainDriver(FR_SNTwainDriver driver);
	static void GetMenuItem(FR_SNTwainDriver driver, FS_WideString* m_wsPresetName);
	static void EnableInsertPosition(FR_SNTwainDriver driver, FS_BOOL bEnable);
	static void SetCurType(FR_SNTwainDriver driver, FR_ScanType scanType);
	static FS_BOOL ShowDialog(FR_SNTwainDriver driver, FR_ScanShowDialogType nType, FS_WideString pScanname);
	static void SetInsertPosition(FR_SNTwainDriver driver, FS_DWORD nInitPosition);
	static void	SetAppendFileInsertPos(FR_SNTwainDriver driver, FS_INT32 npos);
	static FR_SNRecordOper GetRecordOper();
	static FS_INT32 GetDataCount(FR_SNRecordOper recordOper);
	static void GetPresetNameAt(FR_SNRecordOper recordOper, FS_INT32 index, FS_WideString* wsName);	
	static void StartScan(FS_LPVOID pDriver);
	//form 插件
	static FS_BOOLEAN SameNameFieldExist(FPD_Document doc1, FPD_Document doc2);
	static FS_INT32 ShowRenameMsg(FS_HWND hwnd);
	//creator插件
	static void	ConvertPdfFromWeb2(FS_WideStringArray vecWsURL, FS_BOOL bAppendLinkOnDoc, FS_BOOL bViewWebLinks, FSConvertPdfFromWebCallback callback, FS_INT32 nCurrentPageIndex);
	//// IBasicForm
	static void	CopyFields(FPD_InterForm pDstInterForm, FS_INT32 nDstPageStart, FPD_Document pSrcDoc, FS_INT32 nSrcPageStart,
		FS_INT32 nPageCount, FSCopyFieldsDictNotify pNotify, FS_LPVOID pClientData, FS_BOOL bCopySame);

	//IStamp
	static void        AddCRSAUndoItem(FR_Page pPage, FR_Annot pAnnot, FRRSA_UNDO_DATA undoData);
	static void       AddStampAP(FR_Annot pAnnot, FS_LPCWSTR wsStampName);

	//IBaseAnnot
	static FPD_Object GetDestination(FPD_Document pDocument, FPD_Annot pAnnot);	
	static void	DoAction_URI(FPD_Document pDocument, FS_LPCWSTR wsDocPath, const FPD_Action action, FS_BOOLEAN bOpenInNewTab);
	static void	DoAction_Launch(FS_LPCWSTR wsDocPath, const FPD_Action action, FS_LPCWSTR wsSpeFilePath);
	static void	DoAction_GoToR(FPD_Document pPDFDoc, FS_LPCWSTR wsDocPath, const FPD_Action action);
	static void	DoAction_GoToE(FPD_Document pPDFDoc, FS_LPCWSTR wsDocPath, const FPD_Action action);

	//fileattachmentannot
	static FS_BOOLEAN IsAttachDenied(FS_LPCWSTR wsFileExt);
	static FS_BOOLEAN IsAttachDenied2(FS_LPCWSTR wsFilePath, FS_WideStringArray* wsFailedArray);
	static void ShowAttachFailedDlg(FS_WideStringArray wsFailedArray);

	//creator
	static FR_ConvertMediaErrorType ConvertMediaToPDF(FS_LPCWSTR csMediaPath, FS_LPCWSTR csPdfPath, FS_INT32 width, FS_INT32 height, FS_BOOL bShowSelectMediaDlg, FS_LPVOID pParentWnd);

	//javascript
	static FS_BOOLEAN RunProcJavaScript(FR_Document pReaderDoc, FS_WideString script, FR_JSProcType procType);
	static FS_BOOL CheckDocTrustOneTime(FR_Document pReaderDoc);
	static void AddDocTrustOneTime(FR_Document pReaderDoc);

	//IBookmarkPanel
	static void	ReBuildTreeView(FR_Document pReaderDoc, FS_BOOLEAN bRepair);

	static FS_BOOL AddAccessibility(FR_Document  pReaderDoc, FS_HWND pParent );
	static FS_BOOL	CanDoAddAccessibility(FR_Document  pReaderDoc);

	//creator
	static FS_BOOL CheckIsDownloadStatus();

	//FormDesigner
	static void SetFormRecognitionProc(FRFormRecognitionProc proc);

	//docprocess
	static FS_INT32	GetContainedCountInPages(FPD_Document pDoc, FS_WideString csInput, FS_BOOL bUseDigit);
	static FS_BOOL  GetPrompPages(FPD_Document pDoc, FS_LPCWSTR csName, FS_INT32* count, FS_PtrArray* outlistPromp);

	//Optimizer
	static FS_BOOLEAN ReduceFileSize(FS_LPCWSTR wsFilePath, FS_BOOLEAN bNoUI, FR_UIProgress pProgressUI);
	static FS_BOOLEAN ShowReduceSizeDlg(FR_Document pReaderDoc);
	static void LoadAuiModuleString(FS_WideString moduleName, const FS_WideString  stringId, bool bPlugin, FS_WideString* outdata);	

	//fileattachmentannot
	static FS_BOOLEAN	IsNameExist(FS_LPCSTR csObjectName);
	static FS_BOOLEAN	AddFileAttachment(FS_LPCWSTR wsAttachFilePath, FS_LPCWSTR wsObjectName, FS_BOOLEAN bShowOverWriteTips);	

	//Redact
	static FS_BOOL    RedactText(FPD_Page pPage, FS_POSITION pos, FPD_PageObject pPageObject, const FS_FloatRect rect, FS_PtrArray mts, FS_PtrArray* Objects, FPD_Form *pForm);

	//scan
	static void       ExecScanDocTofile(FS_WideString* csOutputFilepath, FREndScanFun fun, FS_LPVOID clientData);

	//fileattachmentannot
	static FS_BOOLEAN IsFileAttachSubDoc(FR_Document pDoc);
	static FS_BOOLEAN IsParentDocAllowModify(FR_Document pDoc);
	
	static FS_BOOL	SetActiveTool(FR_Tool tool, FS_BOOL persistent);
	static FS_BOOLEAN DoAction_DocOpen(const FPD_Action action, FR_Document pDocument, FS_BOOLEAN bDisableGoto);

	static FS_BOOLEAN ActionWizardHandlerNeedSaveDoc(FR_ActionWizardHandler actionWizardHandler);
	static FR_PACKAGELANG GetPackageLanguage();

	//javascript
	static FS_BOOLEAN ShowSafeModeDialog(FR_Document pDoc);
	static void ReShowSafeModeDialog(FR_Document pDoc);

	//portfolio
	static void SetDocRenderFinishOneTime(FR_Document pDoc , FS_BOOL bReaderOneTime);
	static void SetPageVisibleEventFinish(FR_Document pDoc, FS_BOOL bDocPageVisibleEvent);
	static void ExecuteOnPortfolioFinishRender(FR_Document pDoc);

	static void SetRecipientSeed(FS_ByteString cwPDFPath);
	static void	ConstructorInterform(FR_Document pDoc);
	static FS_DWORD ParserOpenPassword(FPD_Parser pParser, FS_LPCWSTR password, FS_LPVOID pClientData, FRStartParserProc proc);
	static FS_DWORD CheckOwerPassword(FPD_Parser pParser, const FS_LPCWSTR password, FS_ByteString* csPassword);
	static void		SetTrialDay(FS_INT32 days);
	static void		SetTotalTrialDay(FS_INT32 totalTrialDay);
	static void     SetAgainCheckLisense();

	static void FindAllBMNode(FR_Document pDoc, FS_PtrArray* BMDictArray, FPD_Bookmark pBookMark);
	
	//accessbility
	static FS_BOOLEAN FixRules(FR_AccessibilityFix fixObj, FPD_Document pPDFDoc, const FS_DWORD &FixRule, FS_LPVOID pFixData);
	static void SetCallBackProcess(FR_AccessibilityFix fixObj, FS_LPVOID pClientData, FRInternalAccessibilityFixProc proc);
	static FR_AccessibilityFix  CreateAccessbilityFix();
	static void  ReleaseAccessbilityFix(FR_AccessibilityFix fixObj);

	//annot
	static void	SetActionGoto(FR_Document pDocument, FPD_Object pHostDict, FPD_Object* pDestArray,
		FPD_AActionType eType, FPD_Object pActionDict,
		FPD_Object* pRetDict, FPD_Object* pPrevDict, FS_WideString* cwNamedDes, FS_LPCSTR csKey);
	static void	SetActionURL(FR_Document pDocument, FPD_Object pHostDict, const FS_LPCWSTR sURL,
		FPD_AActionType eType, FPD_Object pActionDict,
		FPD_Object* pRetDict, FPD_Object* pPrevDict);
	static void	SetActionLaunch(FR_Document pDocument, FPD_Object pHostDict, const FS_LPCWSTR sFilePath,
		FPD_AActionType eType, FPD_Object pActionDict,
		FPD_Object* pRetDict, FPD_Object* pPrevDict);
	static void	SetActionNamed(FR_Document pDocument, FPD_Object pHostDict, const FS_LPCSTR sMenuName,
		FPD_AActionType eType, FPD_Object pActionDict,
		FPD_Object* pRetDict, FPD_Object* pPrevDict);
	static void	SetActionImportData(FR_Document pDocument, FPD_Object pHostDict, const FS_LPCWSTR sFilePath,
		FPD_AActionType eType, FPD_Object pActionDict,
		FPD_Object* pRetDict, FPD_Object* pPrevDict);
	static void	SetActionJavaScript(FR_Document pDocument, FPD_Object pHostDict, const FS_LPCWSTR sJavaScript,
		FPD_AActionType eType, FPD_Object pActionDict,
		FPD_Object* pRetDict, FPD_Object* pPrevDict);

	//undo
	static  FS_BOOLEAN   CanUndo(FR_Document pDocument);
	static  FS_BOOLEAN   CanRedo(FR_Document pDocument);

	//IBaseAnnot
	static void GridWindow2Doc(FR_PageView pPageView, FS_Rect rcWin, FS_FloatRect* rcDoc);
	static void GridWindow2Doc2(FR_PageView pPageView, FS_INT32 x, FS_INT32 y, FS_FLOAT* fx, FS_FLOAT* fy);

	//search
	static void SetSearchingTextFlag(FR_Document doc, FS_BOOL bIsSearchingText);
	static FS_INT32 GetTrialDays();
	static FS_BOOL IsBlankPage(FPD_Page page);

	//FileAttachment
	static FS_BOOLEAN AddAttachFile(FR_Annot annot, FS_WideString wsAttachFilePath);
	static FS_BOOLEAN GetAttachFile(FR_Annot annot, FS_WideString wsAttachFilePath);

	static FS_BOOL  CheckIsFpeKey();
	static void		SetAgainCheckTrial();
	static FR_TextMarkupAnnot Get();
	static FS_BOOLEAN TextMarkupCreateAnnot(FR_TextMarkupAnnot annot, FR_Document pDoc, FS_LPCSTR bsAnnotType, FS_PtrArray highlightPos,
		FR_TextMarkupPROGRESSCBK pFun, FS_LPVOID pProgressCtrl);
	static FS_BOOLEAN TextMarkupResetAnnot(FR_TextMarkupAnnot annot, FR_Document pDoc, FS_INT32 iPageIndex, FPD_Object pAnnotDic, FPD_Object pNewArrQuad,
		FS_BOOLEAN bAddUndo, FS_AffineMatrix* pMatrix);
	static FS_BOOLEAN TextMarkupDeleteAnnot(FR_TextMarkupAnnot annot, FR_Document pDoc, FS_INT32 iPageIndex, FPD_Object pAnnotDic, FS_BOOLEAN bAddUndo);
	static FS_BOOLEAN TextMarkupCloneAnnot(FR_TextMarkupAnnot annot, FR_Document pDoc,
		FS_INT32 iSrcPageIndex,
		FS_INT32 iDestPageIndex,
		FPD_Object pAnnotDic,
		FS_BOOLEAN bAddUndo,
		FS_PtrArray* OutDicAnnots);
	static void TextMarkupBeginModify(FR_TextMarkupAnnot annot, FR_Document pDoc, FS_PtrArray annotDicts);
	static void TextMarkupEndModify(FR_TextMarkupAnnot annot, FR_Document pDoc, FS_PtrArray annotDicts, FS_BOOLEAN  bEndDirectly);

	//FileAttachment
	static FPD_Object FAAItemObjectGetDic(FR_FAAItemObject obj);
	static void FAAItemObjectSetDic(FR_FAAItemObject obj, FPD_Object pDict);
	static FS_INT32 FAAItemObjectGetPageIndex(FR_FAAItemObject obj);
	static void FAAItemObjectSetPageIndex(FR_FAAItemObject obj, FS_INT32 nPage);
	static void FAAItemObjectSetbAnnot(FR_FAAItemObject obj, FS_BOOLEAN bAnnot);
	static FS_BOOLEAN FAAItemObjectGetbAnnot(FR_FAAItemObject obj);
	static void FAAItemObjectSetUFileName(FR_FAAItemObject obj, FS_LPCWSTR uName);
	static void FAAItemObjectGetUFileName(FR_FAAItemObject obj, FS_WideString* uName);
	static void FAAItemObjectSetFileName(FR_FAAItemObject obj, FS_LPCWSTR uName);
	static void FAAItemObjectGetFileName(FR_FAAItemObject obj, FS_WideString* uName);

	static void	GetFileAttachmentObjects(FPD_Document pPDFDoc, FS_PtrArray* vecFAAItemObject);
	static void	ReleaseFileAttachmentObjects(FS_PtrArray vecFAAItemObject);
	static  FR_Document OpenFileAttachment(FR_Document pRDDoc, FPD_Object pFSDict);
	static  FR_Document OpenFileAttachment2(FR_Document pDoc, FS_LPCWSTR wsAttachPath);

	static FS_BOOLEAN	IsTextMark(FPD_Document pPDFDoc, FS_INT32 nPageIndex, const FS_PtrArray rectPointArray);
	static void		DoSearchAndRedact(FR_Document pDoc, FS_INT32 nPageIndex,
		const FS_PtrArray rectPointArray,
		FS_BOOLEAN bApply, FS_BOOLEAN bOpen,
		FS_BOOL bAutoSize,
		FS_LPCWSTR wsOverlayText);	
	static int	ApplyRedact(FR_Document pDoc, FS_BOOLEAN bOpen);
	static FS_BOOLEAN   IsDisableAdvertise();
	static void GetSelectLoginMethods(FS_WideString* outMethods);	
	static FS_LPCWSTR  GetPackageLanguageName();
	static FS_LPCWSTR GetPackageAgentName();
	static FS_LPCWSTR GetServiceDomain(FS_LPCWSTR wsServiceName);
	static void AddToLog(FS_LPCWSTR wsURL, FS_LPCWSTR wsFeature);
	static FS_BOOLEAN   IsAttachCanOpen(FS_LPCWSTR wsFileExt);
	static FS_BOOLEAN	CheckSecurity(FS_LPCWSTR wsFilePath);
	static FS_BOOLEAN	ShowAndCheckAttachFaileDlg(const FS_WideStringArray arrSrcFiles, FS_WideStringArray* arrValidFile, FS_BOOLEAN bExtractFile);
	static FS_BOOL  IsDisableDefaultLaunchAttachmentPerms(FS_BOOL* bDisableDefaultLaunchAttachmentPerms);
	static FS_BOOL	GetSubExpierDate(FS_WideString* subExpierDate);
	static void	ShowRibbonFilePage();
	static FS_BOOLEAN	RemoveFileAttachmentObject(FS_LPCSTR csObjectName);
	static void SetReplaceColors(const FS_COLORREF clrDocFore, const FS_COLORREF clrDocBack);
	static void BFExportForm(FS_LPCWSTR type);
	static void FrameRemoveAllGroup();
	static void FrameNewVertGroup();
	static FS_BOOL GetLoginDomain(FS_BOOL* bWhiteList, FS_WideStringArray* wsLoginDomain);
	static void   ExportComments(FR_EXPORT_COMMENTS_TYPE type);
};

class CFR_SpellCheck_V5
{
public:
	//************************************
	// Function:  New
	// Param[in]: lpwsModuleName The input module name.
	// Return: A new <a>FR_SpellCheck</a> object.
	// Remarks: Creates a <a>FR_SpellCheck</a> object used to check spelling.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0	
	//************************************
	static FPD_SpellCheck New(FS_LPCWSTR lpwsModuleName);


	//************************************
	// Function:  Ignore
	// Param[in]: spellCheck	The input <a>FPD_SpellCheck</a> object.
	// Param[in]: sWord			The input words to be ignored.
	// Return: void
	// Remarks: Ignores the input words that will not be checked.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void Ignore(FPD_SpellCheck spellCheck, FS_LPCWSTR sWord);


	//************************************
	// Function:  CheckString
	// Param[in]: spellCheck	The input <a>FPD_SpellCheck</a> object.
	// Param[in]: sString		The input byte string that will be checked.
	// Param[out]: outErrBufArr	It receives the errors.
	// Return: void
	// Remarks: Checks the spelling of the input byte string and receives the errors.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRSpellCheckCheckWord
	//************************************
	static void CheckString(FPD_SpellCheck spellCheck, FS_WideString sString, FS_WideStringArray* outErrBufArr);

	//************************************
	// Function:  AddDic
	// Param[in]: spellCheck	The input <a>FPD_SpellCheck</a> object.
	// Param[in]: sWord			The input new words.
	// Return: void
	// Remarks: Adds the new words to the dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRSpellCheckNew
	//************************************
	static void	AddDic(FPD_SpellCheck spellCheck, FS_LPCWSTR sWord);	
};

class CFR_HTMLMgr_V7  //Internal use
{
public:
	//************************************
	// Function:  Get
	// Return: The <a>FR_HTMLMgr</a> object is used to manage the HTML windows in <Italic>Foxit Reader</Italic>.
	// Remarks: Gets the <a>FR_HTMLMgr</a> object is used to manage the HTML windows in <Italic>Foxit Reader</Italic>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use
	//************************************
	static FR_HTMLMgr Get(void);

	//************************************
	// Function:  RegisterHTMLEventHandler
	// Param[in]: mgr			The input HTML manager object.
	// Param[in]: callbacks		The callback set for HTML window event handler.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Registers the HTML event handler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use
	//************************************
	static FS_BOOL RegisterHTMLEventHandler(FR_HTMLMgr mgr, FR_HTMLEventCallbacks callbacks);

	//************************************
	// Function:  OpenHTMLFromNewTab
	// Param[in]: mgr			The input HTML manager object.
	// Param[in]: lpURL			The input URL to be opened in the HTML window.
	// Param[in]: lpTitle		The title of the frame which will be created.
	// Param[in]: bCreatePanel	Whether to create the navigation panel or not.
	// Param[in]: bMakeVisible	Determines whether to make the HTML window visible or not.
	// Param[in]: bAddToMRU		Determines whether the filename is added to the most recently used (MRU) file list.
	// Return: The handle of the HTML window. 
	// Remarks: Opens a new HTML window. Foxit Reader will create a new tab for the new HTML window.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use
	//************************************
	static HWND OpenHTMLFromNewTab(FR_HTMLMgr mgr, FS_LPCWSTR lpURL, FS_LPCWSTR lpTitle, FS_BOOL bCreatePanel, FS_BOOL bMakeVisible, FS_BOOL bAddToMRU);
	
	//************************************
	// Function:  OpenHTMLDocument
	// Param[in]: mgr			The input HTML manager object.
	// Param[in]: lpURL			The input URL to be opened in the HTML window.
	// Param[in]: lpTitle		The title of the frame which will be created.
	// Param[in]: hParentWnd	The parent window of the HTML window.
	// Return: The handle of the HTML window.
	// Remarks: Opens a new HTML window on the specified parent window.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use
	//************************************
	static HWND OpenHTMLDocument(FR_HTMLMgr mgr, FS_LPCWSTR lpURL, FS_LPCWSTR lpTitle, HWND hParentWnd);

	//************************************
	// Function:  GetActiveHtmlView
	// Param[in]: mgr			The input HTML manager object.
	// Return: The pointer to <Italic>MFC CHtmlView</Italic>.
	// Remarks: Opens a new HTML window on the specified parent window.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use
	//************************************
	static void* GetActiveHtmlView(FR_HTMLMgr mgr);

	//************************************
	// Function:  RegisterFoxitBrowserEventHandler
	// Param[in]: mgr			The input HTML manager object.
	// Param[in]: callbacks		The callback set for Foxit browser event handler.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Registers the Foxit browser event handler to receive the event notifications.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2
	// See: 
	// Deprecated: Internal use
	//************************************
	static FS_BOOL RegisterFoxitBrowserEventHandler(FR_HTMLMgr mgr, FR_FoxitBrowserEventCallbacks callbacks);

	//************************************
	// Function:  SetFoxitBrowserHome
	// Param[in]: mgr			The input HTML manager object.
	// Param[in]: lpURL			The input URL.
	// Return: void.
	// Remarks: Sets the home URL of the Foxit browser.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2
	// See: 
	// Deprecated: Internal use
	//************************************
	static void SetFoxitBrowserHome(FR_HTMLMgr mgr, FS_LPCWSTR lpURL);

	//************************************
	// Function:  SetFavoritesLink
	// Param[in]: mgr			The input HTML manager object.
	// Param[in]: lpName		The displaying name of the favorite link.
	// Param[in]: lpURL			The input URL of the favorite link.
	// Param[in]: lpUrlIcon		The URL of the displaying icon.
	// Param[in]: bAdd			Whether to add the favorite link or to delete it.
	// Return: void.
	// Remarks: Sets the favorite link to Foxit favorite bar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2
	// See: 
	// Deprecated: Internal use
	//************************************
	static void SetFavoritesLink(FR_HTMLMgr mgr, FS_LPCWSTR lpName, FS_LPCWSTR lpUrl, FS_LPCWSTR lpUrlIcon, FS_BOOL bAdd);

	//************************************
	// Function:  GetHtmlViewFromHandle
	// Param[in]: mgr			The input HTML manager object.
	// Param[in]: hWnd			The input HTML view handle.
	// Return: The pointer to <Italic>MFC CHtmlView</Italic>.
	// Remarks: Gets a new HTML window from the window handle.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: 
	// Deprecated: Internal use
	//************************************
	static void* GetHtmlViewFromHandle(FR_HTMLMgr mgr, HWND hWnd);

	//************************************
	// Function:  OpenHTMLFromNewTab2
	// Param[in]: mgr			The input HTML manager object.
	// Param[in]: lpURL			The input URL to be opened in the HTML window.
	// Param[in]: lpTitle		The title of the frame which will be created.
	// Param[in]: bCreatePanel	Whether to create the navigation panel or not.
	// Param[in]: bMakeVisible	Determines whether to make the HTML window visible or not.
	// Param[in]: bAddToMRU		Determines whether the filename is added to the most recently used (MRU) file list.
	// Param[in]: hIcon			The icon added to the tab band.
	// Param[in]: bHideURL		Whether to hide the URL or not.
	// Return: The handle of the HTML window. 
	// Remarks: Opens a new HTML window. Foxit Reader will create a new tab for the new HTML window.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	// See: 
	// Deprecated: Internal use
	//************************************
	static HWND OpenHTMLFromNewTab2(FR_HTMLMgr mgr, FS_LPCWSTR lpURL, FS_LPCWSTR lpTitle, FS_BOOL bCreatePanel, 
		FS_BOOL bMakeVisible, FS_BOOL bAddToMRU, HICON hIcon, FS_BOOL bHideURL);
	
	//************************************
	// Function:  OpenHTMLDocument2
	// Param[in]: mgr			The input HTML manager object.
	// Param[in]: lpURL			The input URL to be opened in the HTML window.
	// Param[in]: lpTitle		The title of the frame which will be created.
	// Param[in]: hParentWnd	The parent window of the HTML window.
	// Param[in]: bHideURL		Whether to hide the URL or not.
	// Return: The handle of the HTML window.
	// Remarks: Opens a new HTML window on the specified parent window.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	// See: 
	// Deprecated: Internal use
	//************************************
	static HWND OpenHTMLDocument2(FR_HTMLMgr mgr, FS_LPCWSTR lpURL, FS_LPCWSTR lpTitle, HWND hParentWnd, FS_BOOL bHideURL);
};

class CFR_PanelMgr_V7	//Internal use
{
public:

	//************************************
	// Function:  GetPanelMgrFromChildFrm
	// Param[in]: hChildFrm			The specified child frame window which display the document. You can get it from <a>FRAppGetCurrentChildFrm</a>
	// Return: The specified panel manager by childframe windows handler.
	// Remarks: Gets the specified panel manager.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FR_PanelMgr GetPanelMgrFromChildFrm(FS_HWND hChildFrm);

	//************************************
	// Function:  NewPanelMgr
	// Param[in]: hChildFrm     The specified child frame window which display the document.You can get it from <a>FRAppGetCurrentChildFrm</a>
	// Return: The new panel manager.
	// Remarks: Creates an instance of the panel manager. 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: FRPanelMgrCreate
	// Deprecated: Internal use.
	//************************************
	static FR_PanelMgr NewPanelMgr(FS_HWND hChildFrm);

	//************************************
	// Function:  DeletePanelMgr
	// Param[in]: panelMgr	The input panel manager.
	// Return: void.
	// Remarks: Deletes the panel manager.
	// Notes: It only used in windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void DeletePanelMgr(FR_PanelMgr panelMgr);

	//************************************
	// Function:  CreatePanelEventHandler
	// Param[in]: callbacks	A callback set for the panel event handler.
	// Return: The pointer to the panel event handler.
	// Remarks: Creates the pointer to the panel event handler.
	// Notes: It only used in windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: FRPanelMgrCreate
	// Deprecated: Internal use.
	//************************************
	static void* CreatePanelEventHandler(FR_PanelEventCallbacks callbacks);

	//************************************
	// Function:  DestroyPanelEventHandler
	// Param[in]: panelEventHandler	The pointer to the panel event handler.
	// Return: void.
	// Remarks: Destroys the panel event handler.
	// Notes: It only used in windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: FRPanelMgrCreate
	// Deprecated: Internal use.
	//************************************
	static void DestroyPanelEventHandler(void* panelEventHandler);

	//************************************
	// Function:  Create
	// Param[in]: panelMgr				The input panel manager.
	// Param[in]: pParentWnd			The input parent window.
	// Param[in]: nTablocation			Specifies the tab location. Related to <a>FRPanelLocation</a>
	// Param[in]: dwEnabledAlignment	Specifies the enabled alignment. References to MFC ControlBar styles.
	// Param[in]: panelEventHandler		(Only used in Windows)The input panel event handler to receive the event occurred.
	// Return: True for success, otherwise failure.
	// Remarks: Creates the panel manager after <a>FRPanelMgrNewPanelMgr</a>.
	// Notes:  It only used in windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: FRPanelMgrNewPanelMgr
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL Create(FR_PanelMgr panelMgr, void* pParentWnd, FS_INT32 nTablocation, FS_DWORD dwEnabledAlignment, void* panelEventHandler);

	//************************************
	// Function:  DockToFrameWindow
	// Param[in]: panelMgr		The input panel manager.
	// Param[in]: dwAlignment	Specifies the alignment. References to MFC ControlBar styles.
	// Return: True for success, otherwise failure.
	// Remarks: Docks the panel to the frame window.
	// Notes: It only used in Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL DockToFrameWindow(FR_PanelMgr panelMgr, FS_DWORD dwAlignment);

	//************************************
	// Function:  AddPanel
	// Param[in]: panelMgr		The input panel manager.
	// Param[in]: csToolTip		The tool tip of the panel.
	// Param[in]: csText		The display text of the panel.
	// Param[in]: csName		The name of the panel.
	// Param[in]: pBitmap		The icon of the panel.
	// Param[in]: bInitialShow	Whether to show the panel at the first time.
	// Param[in]: bDockBottom	Whether the panel is docked to the bottom or not.
	// Return: The handle to the panel.
	// Remarks: Adds a panel.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_HWND AddPanel(FR_PanelMgr panelMgr, FS_LPCWSTR csToolTip, FS_LPCWSTR csText, FS_LPCSTR csName, FS_DIBitmap pBitmap, FS_BOOL bInitialShow, FS_BOOL bDockBottom);

	//************************************
	// Function:  ShowAllPanel
	// Param[in]: panelMgr		The input panel manager.
	// Param[in]: bShow			Shows all the panels or not.
	// Return: void.
	// Remarks: Shows all the panels or not.
	// Notes:  It only used in Widnows
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void ShowAllPanel(FR_PanelMgr panelMgr, FS_BOOL bShow);

	//************************************
	// Function:  ShowPanelByName
	// Param[in]: panelMgr		The input panel manager.
	// Param[in]: csName		Specifies the name of the panel.
	// Param[in]: bShow			Shows the panel or not.
	// Return: void.
	// Remarks: Shows the specified panel or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void ShowPanelByName(FR_PanelMgr panelMgr, FS_LPCSTR csName, FS_BOOL bShow);

	//************************************
	// Function:  ResetAllPanels
	// Param[in]: panelMgr		The input panel manager.
	// Return: void.
	// Remarks: Resets all the panels.
	// Notes: It only used in Widnows
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void ResetAllPanels(FR_PanelMgr panelMgr);

	//************************************
	// Function:  GetPanelHwndByName
	// Param[in]: panelMgr		The input panel manager.
	// Param[in]: csName		Specifies the name of the panel.
	// Return: The window handle of the panel.
	// Remarks: Gets the window handle to the panel by name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_HWND GetPanelHwndByName(FR_PanelMgr panelMgr, FS_LPCSTR csName);

	//************************************
	// Function:  IsAllPanelHide
	// Param[in]: panelMgr		The input panel manager.
	// Return: TRUE if all the panels are hidden, otherwise not.
	// Remarks: Checks whether all the panels are hidden or not.
	// Notes:  It only used in Widnows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsAllPanelHide(FR_PanelMgr panelMgr);

	//************************************
	// Function:  HasPanelFloating
	// Param[in]: panelMgr		The input panel manager.
	// Return: TRUE if any panel is floating, otherwise not.
	// Remarks: Checks whether any panel is floating or not.
	// Notes:  It only used in Widnows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL HasPanelFloating(FR_PanelMgr panelMgr);

	//************************************
	// Function:  IsPanelHide
	// Param[in]: panelMgr	The input panel manager.
	// Param[in]: csName	Specifies the name of the panel.
	// Return: TRUE if the specified panel is hidden, otherwise not.
	// Remarks: Checks whether the specified panel is hidden or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsPanelHide(FR_PanelMgr panelMgr, FS_LPCSTR csName);

	//************************************
	// Function:  GetParentFrame
	// Param[in]: panelMgr	The input panel manager.
	// Return: The parent window handle.
	// Remarks: Gets the parent window handle.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_HWND GetParentFrame(FR_PanelMgr panelMgr);

	//************************************
	// Function:  GetEnabledAlignment
	// Param[in]: panelMgr	The input panel manager.
	// Return: The enabled alignment. References to MFC ControlBar styles.
	// Remarks: Gets the enabled alignment. References to MFC ControlBar styles.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_DWORD GetEnabledAlignment(FR_PanelMgr panelMgr);

	//************************************
	// Function:  GetPanelViewByName
	// Param[in]: panelMgr	The input panel manager.
	// Param[in]: csName	Specifies the name of the panel.
	// Return: The specified panel view handle.
	// Remarks: Gets the specified panel view handle.
	// Notes:  It only used in Widnows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_HWND GetPanelViewByName(FR_PanelMgr panelMgr, FS_LPCSTR csName);

	//************************************
	// Function:  GetPanelNameByIndex
	// Param[in]: panelMgr	The input panel manager.
	// Param[in]: nIndex	Specifies the index of the panel.
	// Return: The specified panel name.
	// Remarks: Gets the specified panel name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_LPCSTR GetPanelNameByIndex(FR_PanelMgr panelMgr, FS_INT32 nIndex);

	//************************************
	// Function:  GetPanelCount
	// Param[in]: panelMgr	The input panel manager.
	// Return: The panel count.
	// Remarks: Gets the panel count.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_INT32	GetPanelCount(FR_PanelMgr panelMgr);

	//************************************
	// Function:  GetPanelTabRectByPt
	// Param[in]: panelMgr	The input panel manager.
	// Param[in]: x			The horizon position.
	// Param[in]: y			The vertical position.
	// Param[out]: outRtTab	It receives the rectangle of the panel tab.
	// Return: void.
	// Remarks: Gets the rectangle of the panel tab by point.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void GetPanelTabRectByPt(FR_PanelMgr panelMgr, FS_INT32 x, FS_INT32 y, FS_Rect* outRtTab);

	//************************************
	// Function:  GetPanelTabNameByPt
	// Param[in]: panelMgr	The input panel manager.
	// Param[in]: x			The horizon position.
	// Param[in]: y			The vertical position.
	// Return: The panel name.
	// Remarks: Gets the panel name by point.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_LPCSTR GetPanelTabNameByPt(FR_PanelMgr panelMgr, FS_INT32 x, FS_INT32 y);

	//************************************
	// Function:  GetPanelTabRectByName
	// Param[in]: panelMgr	The input panel manager.
	// Param[in]: csName	The input panel name.
	// Param[out]: outRtTab	It receives the rectangle of the panel tab.
	// Return: void.
	// Remarks: Gets the rectangle of the panel tab by name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void GetPanelTabRectByName(FR_PanelMgr panelMgr, FS_LPCSTR csName, FS_Rect* outRtTab);

	//************************************
	// Function:  HidePanelTabByName
	// Param[in]: panelMgr	The input panel manager.
	// Param[in]: csName	The input panel name.
	// Return: void.
	// Remarks: Hides the specified panel by name when init view.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void HidePanelTabByName(FR_PanelMgr panelMgr, FS_LPCSTR csName);

	//************************************
	// Function:  HasHistory
	// Param[in]: panelMgr	The input panel manager.
	// Return: TRUE if the customer has configured the panel, otherwise not.
	// Remarks: Checks whether the customer has configured the panel or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL HasHistory(FR_PanelMgr panelMgr);

	//************************************
	// Function:  LockAllPanel
	// Param[in]: panelMgr	The input panel manager.
	// Return: void.
	// Remarks: Locks all the panels.
	// Notes:  It only used in Widnows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void LockAllPanel(FR_PanelMgr panelMgr);

	//************************************
	// Function:  ShowPanelByName2
	// Param[in]: panelMgr		The input panel manager.
	// Param[in]: csName		Specifies the name of the panel.
	// Param[in]: bShow			Shows the panel or not.
	// Param[in]: bActive		Activates the panel or not.
	// Return: void.
	// Remarks: Shows the specified panel or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.2.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void ShowPanelByName2(FR_PanelMgr panelMgr, FS_LPCSTR csName, FS_BOOL bShow, FS_BOOL bActive);

	//************************************
	// Function:  IsPanelSpreadOut
	// Param[in]: panelMgr		The input panel manager.
	// Param[in]: csName		Specifies the name of the panel.
	// Return: TRUE if the panel is spread out.
	// Remarks: Checks whether the panel is spread out or not.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.2.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsPanelSpreadOut(FR_PanelMgr panelMgr, FS_LPCSTR csName);

	//************************************
	// Function:  AddPanel2
	// Param[in]: panelMgr      The input panel manager.
	// Param[in]: csToolTip	    The tool tip of the panel.
	// Param[in]: csText        The display text of the panel.
	// Param[in]: csName		    The name of the panel.
	// Param[in]: pBitmap		    The icon of the panel.
	// Param[in]: bInitialShow	Whether to show the panel at the first time.
	// Param[in]: bDockBottom	  Whether the panel is docked to the bottom or not.
	// Param[in]: nPos          The position where the panel will be added.
	// Return: The handle to the panel.
	// Remarks: Adds a panel.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.0.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_HWND AddPanel2(FR_PanelMgr panelMgr, FS_LPCWSTR csToolTip, FS_LPCWSTR csText, FS_LPCSTR csName, FS_DIBitmap pBitmap, FS_BOOL bInitialShow, FS_BOOL bDockBottom, FS_INT32 nPos);

	//************************************
	// Function:  RedockAllFloatToInitial
	// Param[in]: panelMgr		The input panel manager.
	// Return: void.
	// Remarks: All floating panel is restored to the left side.
	// Notes:   It only used in Widnows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void RedockAllFloatToInitial(FR_PanelMgr panelMgr);

	//************************************
	// Function:  IsPanelFloating
	// Param[in]: panelMgr		The input panel manager.
	// Param[in]: csName		Specifies the name of the panel.
	// Return: TRUE if the panel is floating.
	// Remarks: Checks whether the panel is floating or not.
	// Notes:  It only used in Widnows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsPanelFloating(FR_PanelMgr panelMgr, FS_LPCSTR csName);

	//************************************
	// Function:  ShrinkPanelByName
	// Param[in]: panelMgr	The input panel manager.
	// Param[in]: csName	The input panel name.
	// Return: void.
	// Remarks: Shrink the specified panel by name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void ShrinkPanelByName(FR_PanelMgr panelMgr, FS_LPCSTR csName);

	//************************************
	// Function:  ShowOnlyTabBar
	// Param[in]: panelMgr	The input panel manager.
	// Return: void.
	// Remarks: Hide current left panel, just show tab bar.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void ShowOnlyTabBar(FR_PanelMgr panelMgr);
};

class CFR_CloudLoginProvider_V9 //Internal use
{ 
public : 
	//************************************
	// Function:  Set
	// Param[in]: callbacks	The callback set for the service provider of cloud login.
	// Return: The <a>* FR_CloudLoginProvider</a> object represents the service provider of cloud login. Destroys it by invoking <a>FRCloudLoginProviderDestroy</a>.
	// Remarks: Sets the service provider of cloud login.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRCloudLoginProviderDestroy
	// Deprecated: Internal use
	//************************************
	static FR_CloudLoginProvider Set(FR_CloudLoginProviderCallbacks callbacks);

	//************************************
	// Function:  Destroy
	// Param[in]: loginProvider	The input service provider of cloud login.
	// Return: void
	// Remarks: Destroys the service provider of cloud login.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRCloudLoginProviderSet
	// Deprecated: Internal use
	//************************************
	static void Destroy(FR_CloudLoginProvider loginProvider);

	//************************************
	// Function:  Get
	// Return: The service provider of cloud login.
	// Remarks: Gets the service provider of cloud login.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRCloudLoginProviderSet
	// Deprecated: Internal use
	//************************************
	static FR_CloudLoginProvider Get();

	//************************************
	// Function:  IsLogIn
	// Param[in]: loginProvider	The input service provider of cloud login.
	// Return: TRUE indicates that the user has logged in, otherwise not.
	// Remarks: Checks whether the user has logged in or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRCloudLoginProviderSet
	// Deprecated: Internal use
	//************************************
	static FS_BOOL IsLogIn(FR_CloudLoginProvider loginProvider);

	//************************************
	// Function:  SignIn
	// Param[in]: loginProvider	The input service provider of cloud login.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Signs into the cloud.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRCloudLoginProviderSet
	// Deprecated: Internal use
	//************************************
	static FS_BOOL SignIn(FR_CloudLoginProvider loginProvider);

	//************************************
	// Function:  SignOut
	// Param[in]: loginProvider	The input service provider of cloud login.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Signs out the cloud.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRCloudLoginProviderSet
	// Deprecated: Internal use
	//************************************
	static FS_BOOL SignOut(FR_CloudLoginProvider loginProvider);

	//************************************
	// Function:  GetUserInfo
	// Param[in]: loginProvider	The input service provider of cloud login.
	// Param[out]: pUserInfo	It receives the user information.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Gets the user information.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRCloudLoginProviderSet
	// Deprecated: Internal use
	//************************************
	static FS_BOOL GetUserInfo(FR_CloudLoginProvider loginProvider, FR_Login_UserInfo* pUserInfo);

};

class CFR_AssistantMgr_V12  //Internal use
{
public:
	//************************************
	// Function:  Get
	// Return: The <a>FR_AssistantMgr</a> object is used to manage the Assistant windows in <Italic>Foxit Reader</Italic>.
	// Remarks: Gets the <a>FR_AssistantMgr</a> object is used to manage the Assistant windows in <Italic>Foxit Reader</Italic>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 10.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FR_AssistantMgr Get(void);
    
	//************************************
	// Function:  SetCurAsstTrackWnd
	// Param[in]: mgr			The input Assistant manager object.
	// Param[in]: hTrackWnd		A handler to the window.
	// Return: The <a>FR_AssistantMgr</a> object is used to manage the Assistant windows in <Italic>Foxit Reader</Italic>.
	// Remarks: void.
	// Notes: Set current track window on AsstBall follow  
	// Since: <a>SDK_LATEEST_VERSION</a> > 10.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void		SetCurAsstTrackWnd(FR_AssistantMgr mgr, HWND hTrackWnd);

	//************************************
	// Function:  UpdateAssistantHandler
	// Param[in]: mgr			The input Assistant manager object.
	// Param[in]: callbacks		The event callbacks associate with a Assistant. When a event occurs, Reader will
	// call a corresponding callback function.
	// Return: void.
	// Remarks: update assistant button data
	// Notes:   
	// Since: <a>SDK_LATEEST_VERSION</a> > 10.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void		UpdateAssistantHandler(FR_AssistantMgr mgr, FR_AssistantCallbacks callbacks) ;

	//************************************
	// Function:  Notification
	// Param[in]: mgr			The input Assistant manager object.
	// Param[in]: nModuleID		The input moudle identity number
	// Param[in]: asstNotify	The input notification message..
	// Return: void.
	// Remarks: notification/toast.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 10.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void     Notification(FR_AssistantMgr mgr, UINT nModuleID, FR_ASST_NOTIFY asstNotify);

	//************************************
	// Function:  ClearNotification
	// Param[in]: mgr			The input Assistant manager object.
	// Param[in]: nModuleID		The input moudle identity number
	// Param[in]: nNotifyID		The input notify/msg identity number
	// Return: void.
	// Remarks: notification/toast.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 10.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void     ClearNotification(FR_AssistantMgr mgr, UINT nModuleID, UINT nNotifyID);

	//************************************
	// Function:  RegisterAsstUIHandler
	// Param[in]: mgr			The input Assistant manager object.
	// Param[in]: callbacks		The event callbacks associate with Assistant UI. When a event occurs, Reader will
	// call a corresponding callback function.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks: Registers the Assistant UI handler.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 10.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	RegisterAsstUIHandler(FR_AssistantMgr mgr, FR_AsstUICallbacks callbacks);

	//************************************
	// Function:  UnRegisterAsstUIHandler
	// Param[in]: mgr			The input Assistant manager object.
	// Param[in]: callbacks		The event callbacks associate with Assistant UI. When a event occurs, Reader will
	// call a corresponding callback function.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks: Unregisters the Assistant UI handler and releases the memory.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 10.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL  UnRegisterAsstUIHandler(FR_AssistantMgr mgr, FR_AsstUICallbacks callbacks);

	//************************************
	// Function:  RegisterAssistantHandler
	// Param[in]: mgr			The input Assistant manager object.
	// Param[in]: callbacks		The event callbacks associate with a assistant. When a event occurs, Reader will
	// call a corresponding callback function.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks: Registers the assistant handler.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 10.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	RegisterAssistantHandler(FR_AssistantMgr mgr, FR_AssistantCallbacks callbacks);

	//************************************
	// Function:  UnRegisterAssistantHandler
	// Param[in]: mgr			The input Assistant manager object.
	// Param[in]: callbacks		The event callbacks associate with a assistant. When a event occurs, Reader will
	// call a corresponding callback function.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks: Unregisters the assistant handler and releases the memory.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 10.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL  UnRegisterAssistantHandler(FR_AssistantMgr mgr, FR_AssistantCallbacks callbacks);

	//************************************
	// Function:  ResetAssistantDlg
	// Param[in]: mgr			The input Assistant manager object.	
	// Return:	void
	// Remarks: Reset assistant dialog.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void	ResetAssistantDlg(FR_AssistantMgr mgr);
};


class CFR_IReader_PageView_V13 //Internal use
{
public:
	static FR_IFX_InputMethod GetInputMethod(FR_PageView pageview);
};

class CFR_IFX_InputMethod_V13 //Internal use
{
public:
	static FS_INT64 OnWindowProc(FR_IFX_InputMethod inputMethod, FS_UINT message, FS_UINT wParam, FS_INT64 lParam);

	static void RegisterInputHandler(FR_IFX_InputMethod inputMethod, FR_IFX_InputMethodHandler pInterface);

	static void UnRegisterInputHandler(FR_IFX_InputMethod inputMethod);

	static void EnterInputStatus(FR_IFX_InputMethod inputMethod);

	static void ExitInputStatus(FR_IFX_InputMethod inputMethod);


};

class CFR_InputMethodHandler : public IFX_InputMethodHandler  //Internal use
{
public:
	CFR_InputMethodHandler(FR_IFX_InputMethodCallbacks callbacks) {
		memset(&m_callbacks, 0, sizeof(FR_IFX_InputMethodCallbacksRec));
		this->m_callbacks = *callbacks;
		if (callbacks->lStructSize < sizeof(FR_IFX_InputMethodCallbacksRec))
		{
			FS_BYTE * pAttress = (FS_BYTE *)&m_callbacks;
			memset(pAttress + callbacks->lStructSize, 0, sizeof(FR_IFX_InputMethodCallbacksRec) - callbacks->lStructSize); //set new create method to 0.
		}
	}

	void	OnCharsetChanged(BYTE charset, UINT codepage);
	void	OnUnicodeChar(LPWSTR	lpstr, int	cchstr);
	void	OnGetFont(LOGFONT &lf);
	void	OnGetPosition(POINT& position);

public:
	FR_IFX_InputMethodCallbacksRec m_callbacks;
	void* GetClientData() { return m_callbacks.clientData; }
};

class CFR_InputMethodHandler_V13  //Internal use
{
public:
	static FR_IFX_InputMethodHandler New(FR_IFX_InputMethodCallbacks callbacks);

	static void Destroy(FR_IFX_InputMethodHandler handler);

};


class CFR_MarkupAnnotHandler : public CMarkup_AnnotHandler
{
public:
	CFR_MarkupAnnotHandler(FRD_MarkupAnnotHandlerCallbacksRec*  callback);

	virtual FX_BOOL				CanAnswer(IReader_Annot* pAnnot) const;
	virtual FX_BOOL				IsDesigner(const CFX_ByteString& sSubType) const;
	virtual FX_BOOL				CanReSize(const CFX_ByteString& sSubType) const;
	virtual FX_BOOL				CanMove(const CFX_ByteString& sSubType) const;
	virtual CFX_ByteString		GetType();
	virtual CFX_ByteString		GetName();
	virtual std::unique_ptr<IReader_Annot>		NewAnnot(CPDF_Annot* pAnnot, IReader_Page* pPage);
	virtual std::unique_ptr<IReader_Annot>		NewAnnot(XFA_HWIDGET pWidget, IReader_Page* pPage);
	virtual void				DeleteAnnot(IReader_Annot* pAnnot);
	virtual CRect				GetViewBBox(IReader_PageView *pPageView, IReader_Annot* pAnnot);
	virtual FX_BOOL				HitTest(IReader_PageView *pPageView, IReader_Annot* pAnnot, const CPoint& point);
	virtual void				OnDraw(IReader_PageView *pPageView, HDC hDC, IReader_Annot* pAnnot,
		CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device,
		const CRect& rcWindow, DWORD dwFlags);
	virtual void				OnDrawSleep(IReader_PageView *pPageView, HDC hDC, IReader_Annot* pAnnot,
		CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device,
		const CRect& rcWindow, DWORD dwFlags);
	virtual void				OnCreate(IReader_Annot* pAnnot);
	virtual void				OnLoad(IReader_Annot* pAnnot);
	virtual void				OnDelete(IReader_Annot* pAnnot);
	virtual void				OnRelease(IReader_Annot* pAnnot);
	virtual void				OnMouseEnter(IReader_PageView *pPageView, IReader_Annot* pAnnot);
	virtual void				OnMouseExit(IReader_PageView *pPageView, IReader_Annot* pAnnot);
	virtual FX_BOOL				OnLButtonDown(IReader_PageView *pPageView, IReader_Annot* pAnnot, UINT nFlags, const CPoint& point);
	virtual FX_BOOL				OnLButtonUp(IReader_PageView *pPageView, IReader_Annot* pAnnot, UINT nFlags, const CPoint& point);
	virtual FX_BOOL				OnLButtonDblClk(IReader_PageView *pPageView, IReader_Annot* pAnnot, UINT nFlags, const CPoint& point);
	virtual FX_BOOL				OnMouseMove(IReader_PageView *pPageView, IReader_Annot* pAnnot, UINT nFlags, const CPoint& point);
	virtual FX_BOOL				OnMouseWheel(IReader_PageView *pPageView, IReader_Annot* pAnnot, UINT nFlags, short zDelta, const CPoint& point);
	virtual FX_BOOL				OnRButtonDown(IReader_PageView *pPageView, IReader_Annot* pAnnot, UINT nFlags, const CPoint& point);
	virtual FX_BOOL				OnRButtonUp(IReader_PageView *pPageView, IReader_Annot* pAnnot, UINT nFlags, const CPoint& point);
	virtual FX_BOOL				OnRButtonDblClk(IReader_PageView *pPageView, IReader_Annot* pAnnot, UINT nFlags, const CPoint& point);
	virtual FX_BOOL				OnContextMenu(IReader_PageView *pPageView, IReader_Annot* pAnnot, const CPoint& point);
	virtual	void				OnDeSelected(IReader_Annot* pAnnot);
	virtual	void				OnSelected(IReader_Annot* pAnnot);
	virtual FX_BOOL				OnSetFocus(IReader_Annot* pAnnot);
	virtual FX_BOOL				OnKillFocus(IReader_Annot* pAnnot);
	virtual FX_BOOL				OnXFAChangedFocus(IReader_Annot* pOldAnnot, IReader_Annot* pNewAnnot);
	virtual void				OnPageVisible(IReader_PageView* pPageView, IReader_Annot* pAnnot);
	virtual void				OnPageInvisible(IReader_PageView* pPageView, IReader_Annot* pAnnot);
	virtual	IAccessible*		OnGetAccessible(IReader_PageView* pPageView, IReader_Annot* pAnnot);

	virtual int					GetMoveType(IReader_PageView *pPageView, IReader_Annot* pAnnot, const CPoint& point);

	virtual void				OnMoving(IReader_PageView *pPageView, IReader_Annot* pAnnot, int nMovingType,
		const CPoint& ptOrigin, const CPoint& ptOld, const CPoint& ptNew, FX_BOOL bFirst);
	virtual void				OnMoved(IReader_PageView *pPageView, IReader_Annot* pAnnot, int nMovingType,
		const CPoint& ptOrigin, const CPoint& ptNew);
	virtual void				CancelMoving(IReader_PageView *pPageView, IReader_Annot* pAnnot, int nMovingType,
		const CPoint& ptOrigin, const CPoint& ptNew);

	virtual FX_BOOL				OnMoving(IReader_PageView *pPageView, IReader_Annot* pAnnot,
		const CRect& rcOld, const CRect& rcNew, FX_BOOL bFirst);
	virtual void				OnMoved(IReader_PageView *pPageView, IReader_Annot* pAnnot,
		const CRect& rcOrigin, const CRect& rcNew);
	virtual void				OnMovedOutPage(IReader_PageView *pSrcPageView, IReader_PageView *pDestPageView, IReader_Annot* pAnnot,
		const CRect& rcOrigin, const CRect& rcNew, int nIndex = -1);
	virtual void				CancelMoving(IReader_PageView *pPageView, IReader_Annot* pAnnot,
		const CRect& rcOrigin, const CRect& rcNew);

	virtual void				OnSetPosition(IReader_PageView* pPageView, IReader_Annot* pAnnot,
		const CPDF_Rect& rect, int nSrcType);

	virtual FX_BOOL				IsMenuItemSupported(const CFX_ByteString& sSubType, int nMenuItem);
	virtual std::pair<HMENU, int>				OnPopupMenu(const CFX_ByteString& sSubType, FX_INT32 &nIDAfter);
	virtual void				OnPopupMenuItem(IReader_PageView* pPageView, const CFX_ByteString& sSubType, int nMenuItemID);

	virtual FX_BOOL				CanCopy(const CFX_ByteString& sSubType);
	virtual FX_BOOL				CanCut(const CFX_ByteString& sSubType);
	virtual FX_BOOL				CanPaste(const CFX_ByteString& sSubType);
	virtual std::unique_ptr<CXML_Element> OnCopy(IReader_Annot* pAnnot);
	virtual IReader_Annot*		OnPaste(CXML_Element* pElement, IReader_Page* pPage, const CPDF_Rect& rcAnnot);

	virtual FX_BOOL				IsPermissionAllowed(IReader_Document* pDocument, const CFX_ByteString& sSubType);
	virtual CFX_WideString		GetPropertyBoxTitle(const CFX_ByteString& sSubType);

	virtual	FX_BOOL				OnReturn(IReader_PageView *pPageView, IReader_Annot* pAnnot);
	virtual FX_BOOL				CanDelete(IReader_Annot* pAnnot);
	virtual void				Annot_OnRelease(IReader_Annot* pAnnot);
	virtual void                TimerProc();
	virtual window::IFX_SystemHandler*  GetSystemHandler() const;
	virtual std::unique_ptr<CXML_Element>   CopyReply(IReader_Annot* pAnnot);

	FRD_MarkupAnnotHandlerCallbacksRec m_callback;
};

class CFR_MarkAnnotHandler_V14 //Internal use
{
public:
    static void		BeginTimer(FR_MarkupAnnotHandler handler, FS_INT32 nElapse);
    static void		EndTimer(FR_MarkupAnnotHandler handler);
    static void		OnMoveOutPage(FR_MarkupAnnotHandler handler, FR_PageView pSrcPageView, FR_PageView pDestPageView, FR_Annot pAnnot, const FS_Rect rcOrigin, const FS_Rect rcNew, FS_INT32 nIndex);
    static FS_XMLElement  CopyReply(FR_MarkupAnnotHandler handler, FR_Annot pAnnot);	
	static void DeleteAnnot(FR_MarkupAnnotHandler handler, FR_Annot pAnnot);
	static FS_BOOLEAN IsDesigner(FR_MarkupAnnotHandler handler, const FS_LPCSTR sSubType);
	static FS_BOOLEAN CanReSize(FR_MarkupAnnotHandler handler, const FS_LPCSTR sSubType);
	static FS_BOOLEAN CanMove(FR_MarkupAnnotHandler handler, const FS_LPCSTR sSubType);
	static FS_BOOLEAN CanAnswer(FR_MarkupAnnotHandler handler, FR_Annot pAnnot);
	static void OnLoad(FR_MarkupAnnotHandler handler, FR_Annot pAnnot);
	static FS_Rect GetViewBBox(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot);
	static void OnDraw(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_WinPort winPort, FR_Annot pAnnot, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device, const FS_Rect rcWindow, FS_DWORD dwFlags);
	static FS_BOOLEAN OnLButtonDown(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	static FS_BOOLEAN OnLButtonUp(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	static FS_BOOLEAN OnMouseMove(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	static FS_BOOLEAN OnLButtonDblClk(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	static void OnDeSelected(FR_MarkupAnnotHandler handler, FR_Annot pAnnot);
	static void OnSelected(FR_MarkupAnnotHandler handler, FR_Annot pAnnot);
	static void OnPopupMenu(FR_MarkupAnnotHandler handler, const FS_ByteString sSubType, FS_INT32 nIDAfter, HMENU menu, FS_INT32* ret);
	static void OnPopupMenuItem(FR_MarkupAnnotHandler handler, FR_PageView pPageView, const FS_ByteString sSubType, FS_INT32 nMenuItemID);
	static FS_BOOLEAN IsMenuItemSupported(FR_MarkupAnnotHandler handler, const FS_ByteString sSubType, FS_INT32 nMenuItem);
	static FS_INT32 GetMoveType(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, const FS_DevicePoint point);
	static void OnMoving(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 nMovingType, const FS_DevicePoint ptOrigin, const FS_DevicePoint ptOld, const FS_DevicePoint ptNew, FS_BOOL bFirst);
	static void OnMoved(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 nMovingType, const FS_DevicePoint ptOrigin, const FS_DevicePoint ptNew);
	static void CancelMoving(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 nMovingType, const FS_DevicePoint ptOrigin, const FS_DevicePoint ptNew);
	static void OnMovedOutPage(FR_MarkupAnnotHandler handler, FR_PageView pSrcPageView, FR_PageView pDestPageView, FR_Annot pAnnot, const FS_Rect rcOrigin, const FS_Rect rcNew, FS_INT32 nIndex);
	static void OnSetPosition(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, const FS_FloatRect rect, FS_INT32 nSrcType);
	static FS_BOOLEAN OnMoving2(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, const FS_Rect rcOld, const FS_Rect rcNew, FS_BOOL bFirst);
	static void OnMoved2(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, const FS_Rect rcOrigin, const FS_Rect rcNew);
	static FS_BOOLEAN OnResizing(FR_MarkupAnnotHandler handler, FR_PageView pPageView, FR_Annot pAnnot, const FS_Rect rcOld, const FS_Rect rcNew, FS_BOOL bFirst);
	static FS_XMLElement OnCopy(FR_MarkupAnnotHandler handler, FR_Annot pAnnot);
	static FS_BOOLEAN OnSetFocus(FR_MarkupAnnotHandler handler, FR_Annot pAnnot);
	static FS_BOOLEAN OnKillFocus(FR_MarkupAnnotHandler handler, FR_Annot pAnnot);	
	static void DeleteMarkupHandler(FR_MarkupAnnotHandler handler);
	static FR_MarkupAnnotHandler CreateMarkupHandler(FRD_MarkupAnnotHandlerCallbacks callback);
	static FR_BAAnnotHandler CastToBAAnnotHandler(FR_MarkupAnnotHandler handler);
	static void  TimerProc(FR_MarkupAnnotHandler handler);
	static FS_LPVOID  GetSystemHandler(FR_MarkupAnnotHandler handler);
	static FR_Annot	 OnPaste(FR_MarkupAnnotHandler handler, FS_XMLElement pElement, FR_Page pPage, const FS_FloatRect rcAnnot);
};

class CFR_ReaderUserMessageHandler_V14 //Internal use
{
public:
	static FR_ReaderUserMessageHandler New(FR_ReaderUserMessageHandlerCallbacks callbacks);
	static void Destroy(FR_ReaderUserMessageHandler handler);
};


class CFR_IFieldMulCopiesNotify_V14 //Internal use
{
public:
	static FR_IFieldMulCopiesNotify New(FR_IFieldMulCopiesNotifyCallbacks callbacks);
	static void Destroy(FR_IFieldMulCopiesNotify handler);
};


class CFR_IActionWizardData_V14 //Internal use
{
public:
	static FR_ActionWizardData  CreateIActionWizardData();
	static void			        SetRootXMLEle(FR_ActionWizardData data, FS_XMLElement pRootXMLEle);
	static FS_BOOLEAN				SaveItemsDataToXML(FR_ActionWizardData data, const FS_WideStringArray csItems) ;
	static FR_CMapItemNameToData	GetItemsDataFromXML(FR_ActionWizardData data, const FS_WideStringArray csItems);
	static FS_XMLElement		GetItems(FR_ActionWizardData data, const FS_WideStringArray csItems);
	static FS_INT32				GetItemDataFromXMLINT(FR_ActionWizardData data, FS_XMLElement pxmlItems, const FS_ByteString bsItemName, const FS_INT32 nDefaultValue);
	static FS_FLOAT				GetItemDataFromXMLFLOAT(FR_ActionWizardData data, FS_XMLElement pxmlItems, const FS_ByteString bsItemName, const FS_FLOAT fDefaultValue);
	static FS_BOOLEAN			GetItemDataFromXMLBOOL(FR_ActionWizardData data, FS_XMLElement pxmlItems, const FS_ByteString bsItemName, const FS_BOOLEAN bDefaultValue);
	static void		            GetItemDataFromXMLString(FR_ActionWizardData data, FS_XMLElement pxmlItems, const FS_ByteString bsItemName, const FS_LPWSTR wsDefaultValue, FS_WideString* outData);
	static void				    SaveItemDataToXMLBOOL(FR_ActionWizardData data, FS_XMLElement pxmlItems, const FS_ByteString bsItemName, const FS_BOOLEAN bSrc);
	static void				    SaveItemDataToXMLINT(FR_ActionWizardData data, FS_XMLElement pxmlItems, const FS_ByteString bsItemName, const FS_INT32 nSrc);
	static void				    SaveItemDataToXMLFLOAT(FR_ActionWizardData data, FS_XMLElement pxmlItems, const FS_ByteString bsItemName, const FS_FLOAT fSrc);
	static void				    SaveItemDataToXMLWCHAR(FR_ActionWizardData data, FS_XMLElement pxmlItems, const FS_ByteString bsItemName, const FS_LPWSTR strSrc, const FR_ActionWizardItmeDataType dataType);
	static void				    SaveItemDataToXMLSTRING(FR_ActionWizardData data, FS_XMLElement pxmlItems, const FS_ByteString bsItemName, const FS_WideString wsSrc, const FR_ActionWizardItmeDataType dataType);
	static void                 DestroyIActionWizardData(FR_ActionWizardData data);
	static FS_DWORD             GetItemsChidrenCount(FR_ActionWizardData data, const FS_WideStringArray csItems);
};


class CFR_CMapItemNameToData_V14 //Internal use
{
public:	
	static	void	SetItemDataBOOL(FR_CMapItemNameToData data, const FS_ByteString bsItemName, FS_BOOLEAN bSrc);
	static	void	SetItemDataINT(FR_CMapItemNameToData data, const FS_ByteString bsItemName, FS_INT32 nSrc);
	static	void	SetItemDataFLOAT(FR_CMapItemNameToData data, const FS_ByteString bsItemName, FS_FLOAT fSrc);
	static	void	SetItemDataWCHAR(FR_CMapItemNameToData data, const FS_ByteString bsItemName, const FS_LPWSTR wcSrc, const FR_ActionWizardItmeDataType dataType);
	static	void	SetItemDataSTRING(FR_CMapItemNameToData data, const FS_ByteString bsItemName, const FS_WideString wsSrc, const FR_ActionWizardItmeDataType dataType);
	static  FS_INT32	GetItemDataINT(FR_CMapItemNameToData data, const FS_ByteString bsItemName, const FS_INT32 nDefaultValue);
	static  FS_FLOAT	GetItemDataFLOAT(FR_CMapItemNameToData data, const FS_ByteString bsItemName, const FS_FLOAT fDefaultlValue);
	static  FS_BOOLEAN	GetItemDataBOOL(FR_CMapItemNameToData data, const FS_ByteString bsItemName, const FS_BOOLEAN bDefaultValue);
	static  void	GetItemDataSTRING(FR_CMapItemNameToData data, const FS_ByteString bsItemName, const FS_LPWSTR wsDefaultValue,FS_WideString* outdata);
	static  FS_BOOLEAN	CheckKeyExist(FR_CMapItemNameToData data, const FS_LPCSTR bsItemName);
	static  FS_BOOLEAN	IsEmpty(FR_CMapItemNameToData data);
	static  FS_INT32			GetCount(FR_CMapItemNameToData data);
	static void		    RemoveAt(FR_CMapItemNameToData data, const FS_LPCSTR bsItemName);
	static void		    RemovAll(FR_CMapItemNameToData data);
};


class CFR_ReaderUIMgr_V14  //Internal use
{
public:	
	//************************************
	// Function:  ShowFilePasswordDlg
	// Param[in]: filPath				The path of the open document.
	// Param[out]: password		        The password of the user to input in the password dialog.
	// Param[hParent]: hParent			A platform-specific object.	In windows, it is a HWND handler.	
	// Param[in]: bPDF2					If need to support PDF2.0.
	// Return:	  FS_INT32.				Return 0 means false.
	// Remarks:   The dialog support PDF2.0, support unicode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL		ShowFilePasswordDlg(FS_LPCWSTR filPath, FS_WideString* password, HWND hParent, FS_BOOLEAN bPDF2);

	//************************************
	// Function:  GetReaderThemeObject	
	// Return:	  FR_ReaderTheme.				.
	// Remarks:   Get the ReaderTheme object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FR_ReaderTheme		GetReaderThemeObject();
};


class CFR_ReaderTheme_V14 //Internal use
{
public:	
	//************************************
	// Function:  GetBkGroundColor
	// Param[in]: theme				The input theme object.
	// Param[in]: pWnd		        The HWND of the control or window.
	// Return:	  FS_COLORREF.		Return backgroud color.
	// Remarks:   Return the current skin color.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_COLORREF GetBkGroundColor(FR_ReaderTheme theme, FS_HWND pWnd);

	//************************************
	// Function:  InstallSkinTheme
	// Param[in]: theme				The input theme object.
	// Param[in]: pWnd		        The HWND of the control or window.
	// Return:	  FS_BOOL.		    Return TRUE is install skin success.
	// Remarks:   Install skin theme, used to change skin.
	// Notes: It can't support change to dark skin.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static	FS_BOOL   	 InstallSkinTheme(FR_ReaderTheme theme, FS_HWND pWnd);

	//************************************
	// Function:  InstallSkinTheme2
	// Param[in]: theme				The input theme object.
	// Param[in]: pWnd		        The HWND of the control or window.
	// Return:	  FS_BOOL.		    Return TRUE is install skin success.
	// Remarks:   Install skin theme, used to change skin.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static	FS_BOOL   	 InstallSkinTheme2(FR_ReaderTheme theme, FS_HWND pWnd);

	//************************************
	// Function:  RegistSkinChangeProc
	// Param[in]: theme				The input theme object.
	// Param[in]: hWnd		        The HWND of the control or window.
	// Param[in]: proc		        The skin changed proc.
	// Param[in]: pClientData		The client data.
	// Return:	  FS_BOOL.		    Return TRUE is register callback success.
	// Remarks:   Register skin change callback.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static	FS_BOOL   	 RegistSkinChangeProc(FR_ReaderTheme theme, FS_HWND hWnd, FRSkinChangeProc proc, FS_LPVOID pClientData);

	//************************************
	// Function:  UnRegistSkinChangeProc
	// Param[in]: theme				The input theme object.
	// Param[in]: pWnd		        The HWND of the control or window.
	// Return:	  FS_BOOL.		    Return TRUE is unregister skin change callback.
	// Remarks:   Unregister skin change callback.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static	FS_BOOL   	 UnRegistSkinChangeProc(FR_ReaderTheme theme, FS_HWND hWnd);

	//************************************
	// Function:  GetSkinStyle
	// Param[in]: theme				The input theme object.
	// Return:	  FR_SKINSTYLE		Return skin style.
	// Remarks:   Install skin theme, used to change skin.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static  FR_SKINSTYLE    GetSkinStyle(FR_ReaderTheme theme);

	//************************************
	// Function:  GetWindowColor
	// Param[in]: theme				The input theme object.
	// Return:	  FS_COLORREF		Return the color of window.
	// Remarks:   Get the color of window.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_COLORREF GetWindowColor(FR_ReaderTheme theme);

	//************************************
	// Function:  GetWindowTextColor
	// Param[in]: theme				The input theme object.
	// Return:	  FS_COLORREF		Return text color in window.
	// Remarks:   Get the text color in window.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_COLORREF GetWindowTextColor(FR_ReaderTheme theme);

	//************************************
	// Function:  GetAppColor
	// Param[in]: theme				The input theme object.
	// Return:	  FS_COLORREF		Return the current color of app.
	// Remarks:   Get the current color of app.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_COLORREF GetAppColor(FR_ReaderTheme theme);

	//************************************
	// Function:  GetLeftPanelSeparatorColor
	// Param[in]: theme				The input theme object.
	// Return:	  FS_COLORREF		Return the spearator color of left panel.
	// Remarks:   Get the spearator color of left panel.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
    static FS_COLORREF GetLeftPanelSeparatorColor(FR_ReaderTheme theme);

	//************************************
	// Function:  GetWindow2Color
	// Param[in]: theme				The input theme object.
	// Return:	  FS_COLORREF		Return window color.
	// Remarks:   Get the spearator color of left panel.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_COLORREF GetWindow2Color(FR_ReaderTheme theme);

	//************************************
	// Function:  SetBkGroundColor
	// Param[in]: theme				The input theme object.
	// Param[in]: pWnd				The input CWnd* object.
	// Param[in]: clrBkGround		The input background color.
	// Param[in]: bRedraw			TRUE: need redraw.
	// Return:	  void
	// Remarks:   Set background color.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void SetBkGroundColor(FR_ReaderTheme theme, FS_LPVOID pWnd, FS_COLORREF clrBkGround, FS_BOOL bRedraw);

	//************************************
	// Function:  EnableWindowRoundedCorners
	// Param[in]: theme				The input theme object.
	// Param[in]: pWnd				The input HWND object.
	// Param[in]: type		        The input windows corner type.	
	// Return:	  FS_BOOL
	// Remarks:   Enable windows rounded corners.
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	EnableWindowRoundedCorners(FR_ReaderTheme theme, FS_HWND hwnd, FR_WINDOW_CORNER_TYPE type);

	//************************************
	// Function:  GetColor
	// Param[in]: theme				The input theme object.
	// Param[in]: name				The input color name, it can get from starship\lib\Skins\Ribbon\Black\Black.xml.
	// Param[in]: bLight		    If need to do the skin switch.	
	// Return:	  FS_COLORREF
	// Remarks:   Get color by color name.
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// Deprecated: Internal use.
	//************************************
	static FS_COLORREF GetColor(FR_ReaderTheme theme, FS_LPCWSTR name, FS_BOOL bLight);
	
	//************************************
	// Function:  GetColorMap
	// Param[in]: theme				The input theme object.
	// Param[in]: mapColor				It should be set the pointer of std::map<CString, COLORREF>& mapColor.
	// Param[in]: bLightDefault			If bLightDefault is TRUE, it returns m_mpDefaultEntitiesColor. If it's FALSE, it returns m_mpEntitiesColor.  	
	// Return:	  FS_BOOL
	// Remarks:   Retrieves the color mapping of the current skin based on the bLightDefault parameter.  
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetColorMap(FR_ReaderTheme theme, void* mapColor, FS_BOOL bLightDefault);
};

class CFR_PluginsMamager_V14 
{
public:
	//************************************
	// Function:  LoadPlugin
	// Param[in]: PlugName			The input pluginName.
	// Return:	  FS_BOOL
	// Remarks:   Load the plugin by name
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL LoadPlugin(FS_LPCWSTR pluginName);

	//************************************
	// Function:  IsLoadedPlugin
	// Param[in]: pluginName	The input plugin name need to check if it has been loaded.	
	// Return:	FS_BOOL      
	// Remarks:  Check the plugin if it has been loaded.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL IsLoadedPlugin(FS_LPCSTR pluginName);

	//************************************
	// Function:  IsDisabledPlugin
	// Param[in]: pluginName	The input plugin name need to check if it has been loaded.	
	// Return:	FS_BOOL      
	// Remarks:  Check the plugin if it has been disabled.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL IsDisabledPlugin(FS_LPCWSTR pluginName);

	//************************************
	// Function:  IsPluginNeedLoadByGPO
	// Param[in]: pluginName	The input plugin name need to check if it has been loaded.
	// Return:	FS_BOOL
	// Remarks:  Check the plugin if it need be load by GPO setting.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsPluginNeedLoadByGPO(FS_LPCWSTR pluginName);
};

class CFR_IReplaceAllNotify_V14 //Internal use
{
public:	
	static FS_BOOL ReplaceAllProc(FR_IReplaceAllNotify notify, FR_ReplaceAllNotifyData data);
};



class CFR_FindReplaceMgr : public ITouchupMgr //Internal use
{
public:
    CFR_FindReplaceMgr(FR_FindReplaceMgrCallbacksRec* pcallbacks);
	BOOL		StartReplace() override;
	BOOL		EndReplace() override;
	BOOL		FindText(const std::wstring& wstrText, FX_INT32 nPageIdx, const FIND_OPTION& findOpt) override;
	BOOL		FTReplaceText(const std::wstring& wstrText) override;
	bool		ReplaceAll(IReader_Document* pReaderDoc, ReplaceAllOption& opt) override;
	void		ClearCache(FX_INT32 nPageIdx) override;
	bool		IsProcessInterrupt(IReader_Document* pDoc) override;
	void		SetHighlightColor(FX_ARGB color) override;
	BOOL        FindText(const std::wstring& wstrText, FX_INT32 nPageIdx, const FIND_OPTION& findOpt, const std::vector<FR_CONTENT_OBJECT>& specifyObject) override;

	void* GetClientData() { return m_callbacks.clientData; }

public:
	FR_FindReplaceMgrCallbacksRec m_callbacks;
};

class CFR_IFindReplaceMgr_V14 //Internal use
{
public:
	static FR_FindReplaceMgr New(FR_FindReplaceMgrCallbacks callbacks);
	static void Destroy(FR_FindReplaceMgr mgr);
	static void SetToMgr(FR_FindReplaceMgr mgr);
};

class CFR_PDFBitmap_V14 //Internal use.
{
public:
	//************************************
	// Function:  Draw
	// Param[in]: hDC				Render device 
	// Param[in]: iconRect			the rect of PDFBitmap need to render
	// Param[in]: wsPDFBitmapName	the name of the PDFBitmap, which is from the bookmark of \res\ribbon\ribbonimage.pdf
	// Param[in]: bDisable			<a>TRUE</a> means drawing PDFBitmap as disable mode, otherwise not.
	// Param[in]: clrBack			background color
	// Param[in]: clrReplace		replaced color
	// Param[in]: bAlpha			<a>TRUE</a> means drawing PDFBitmap as transparency.if it is TRUE, clrBack param will be ignore.
	// Return:	  <a>TRUE</a> means successful, otherwise not.
	// Remarks:   Draw PDFBitmap
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL Draw(FS_HDC hDC, FS_FloatRect iconRect, FS_LPCWSTR wsPDFBitmapName, FS_BOOL bDisable , FS_COLORREF clrBack , FS_COLORREF clrReplace , FS_BOOL bAlpha );

	//************************************
	// Function:  GetBitmap
	// Param[in]: wsImageName	It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf. 
	// Param[in]: cx			Set the width of the image.
	// Param[in]: cy	        Set the height of the image.
	// Param[in]: clrReplace	Set fill color of the image.	
	// Return:	 HBITMAP
	// Remarks:  Get HBITMAP of specified image name from ribbonimage-phantom.pdf.
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static HBITMAP GetBitmap(FS_WideString wsImageName, FS_INT32 cx, FS_INT32 cy, FS_COLORREF clrReplace);

	//************************************
	// Function:  GetBitmapFromPDFIcon
	// Param[in]: wsImageName	It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf. 
	// Param[in]: cx			Set the width of the image.
	// Param[in]: cy	        Set the height of the image.
	// Param[in]: clrReplace	Set fill color of the image.	
	// Return:	 FS_DIBitmap
	// Remarks:  Get FS_DIBitmap of specified image name from ribbonimage-phantom.pdf.
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_DIBitmap GetBitmapFromPDFIcon(FS_LPCWSTR wsImageName, FS_INT32 cx, FS_INT32 cy, FS_COLORREF clrReplace);

	//************************************
	// Function:  FillRoundedRectangle
	// Param[in]: pDC	        The input CDC object.
	// Param[in]: rect			The input rounded rect.
	// Param[in]: clrFill	    The input fill color.
	// Param[in]: ptRoundRadius	The input point of round radius.	
	// Return:	 void
	// Remarks:  Fill round rectangle of specified property.
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void FillRoundedRectangle(FS_LPVOID pDC, FS_Rect rect, FS_COLORREF clrFill, FS_DevicePoint ptRoundRadius);

	//************************************
	// Function:  DrawRoundedRectangle
	// Param[in]: pDC	        The input CDC object.
	// Param[in]: rect			The input rounded rect.
	// Param[in]: clrFill	    The input fill color.
	// Param[in]: ptRoundRadius	The input point of round radius.	
	// Return:	 void
	// Remarks:  Draw round rectangle of specified property.
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void DrawRoundedRectangle(FS_LPVOID pDC, FS_Rect rect, FS_COLORREF clrLine, FS_DevicePoint ptRoundRadius, FS_INT32 nLineWidth, FS_INT32 nPenStyle);

	//************************************
	// Function:  Draw2
	// Param[in]: hDC				Render device 
	// Param[in]: iconRect			the rect of PDFBitmap need to render
	// Param[in]: wsPDFBitmapName	the name of the PDFBitmap, which is from the bookmark of \res\ribbon\ribbonimage.pdf
	// Param[in]: bDisable			<a>TRUE</a> means drawing PDFBitmap as disable mode, otherwise not.
	// Param[in]: clrBack			background color
	// Param[in]: clrReplace		replaced color
	// Param[in]: bAlpha			<a>TRUE</a> means drawing PDFBitmap as transparency.if it is TRUE, clrBack param will be ignore.
	// Param[in]: style			    The input skin style.
	// Return:	  <a>TRUE</a> means successful, otherwise not.
	// Remarks:   Draw PDFBitmap
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL Draw2(FS_HDC hDC, FS_FloatRect iconRect, FS_LPCWSTR wsPDFBitmapName, FS_BOOL bDisable, FS_COLORREF clrBack, FS_COLORREF clrReplace, FS_BOOL bAlpha, FR_SKINSTYLE style);

	//************************************
	// Function:  GetBitmap2
	// Param[in]: wsImageName	It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf. 
	// Param[in]: cx			Set the width of the image.
	// Param[in]: cy	        Set the height of the image.
	// Param[in]: clrReplace	Set fill color of the image.	
	// Param[in]: style			    The input skin style.
	// Return:	 HBITMAP
	// Remarks:  Get HBITMAP of specified image name from ribbonimage-phantom.pdf.
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static HBITMAP GetBitmap2(FS_LPCWSTR wsImageName, FS_INT32 cx, FS_INT32 cy, FS_COLORREF clrReplace, FR_SKINSTYLE style);

	//************************************
	// Function:  GetFXBitmap
	// Param[in]: wsImageName	It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf. 
	// Param[in]: cx			Set the width of the image.
	// Param[in]: cy	        Set the height of the image.
	// Param[in]: clrReplace	Set fill color of the image.	
	// Param[in]: dwSytle			    The input skin style.
	// Return:	 FS_DIBitmap
	// Remarks:  Get FS_DIBitmap of specified image name from ribbonimage-phantom.pdf.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_DIBitmap GetFXBitmap(FS_LPCWSTR wsImageName, FS_INT32 cx, FS_INT32 cy,FS_COLORREF clrReplace,FR_SKINSTYLE dwSytle);	
};

class CFR_Accessibility_V14 //Internal use
{
public:

	//************************************
	// Function:  IsScreenReaderRunning	
	// Return:	FS_BOOL
	// Remarks:	Check screen reader is running.(for jaws library).
	// Notes:
	// See: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL IsScreenReaderRunning();

	//************************************
	// Function:  IsATSupportEnabled	
	// Return:	FS_BOOL
	// Remarks:	Check Assistive Technology Support is enabled.
	// Notes:
	// See: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL		IsATSupportEnabled();
};

class CFR_AppUIStyle_V14 //Internal use
{
public:
	//************************************
	// Function:  GetAppColor
	// Param[out]: clrColor		The color when the control focused.
	// Return:    void
	// Remarks:   Get color when the control focused.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetAppColor(FS_COLORREF* clrColor);

	//************************************
	// Function:  GetRibbonImageScale
	// Return:    FS_FLOAT
	// Remarks:   Get scale of ribbion image.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_FLOAT GetRibbonImageScale();
};


class CFR_UIMgr_V16
{
public:
	//************************************
	// Function:  SplitChildFrameColumn
	// Param[in]: hChildFrame		The frame need to split.
	// Param[in]: cxBefore		    The width of the left view.
	// Param[in]: pCreateProc		The create window proc.
	// Return:    FS_BOOL
	// Remarks:  Split frame in vertical orientation.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL				SplitChildFrameColumn(FS_HWND hChildFrame, FS_INT32 cxBefore, FRCreateSplitWndProc pCreateProc);

	//************************************
	// Function:  SplitChildFrameRow
	// Param[in]: hChildFrame		The frame need to split.
	// Param[in]: cyBefore		    The height of the top view.
	// Param[in]: pCreateProc		The create window proc.
	// Return:    FS_BOOL
	// Remarks:  Split frame in horizontal orientation.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL				SplitChildFrameRow(FS_HWND hChildFrame, FS_INT32 cyBefore, FRCreateSplitWndProc pCreateProc);

	//************************************
	// Function:  DeleteSplitNewWnd
	// Param[in]: hChildFrame		The split frame need to delete.
	// Return:    FS_BOOL
	// Remarks: Delete split frame.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL				DeleteSplitNewWnd(FS_HWND hChildFrame);

	//************************************
	// Function:  SetFloatyTransparency
	// Param[in]: hChildFrame		The CMiniFrameWnd pointer of the floaty window .
	// Param[in]: nTransparency		The transparence value.
	// Return:    void
	// Remarks: Set transparene of the floaty window.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static void					SetFloatyTransparency(FS_LPVOID pFloaty, FS_BYTE nTransparency);

	//************************************
	// Function:  AddFloatyBarBtn
	// Param[in]: ribbonInfo		        The CMiniFrameWnd pointer of the floaty window .
	// Param[in]: bSyncOriginalCkeck		The transparence value.
	// Param[in]: bLargeBtn		            The transparence value.
	// Return:    FR_RibbonElement
	// Remarks: Add floaty bar button.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static FR_RibbonElement     AddFloatyBarBtn(FR_RIBBONBUTTONINFO ribbonInfo, FS_BOOL bSyncOriginalCkeck , FS_BOOL bLargeBtn);
	
	//************************************
	// Function:  CreateRibbonFloaty
	// Param[in]: point		          The positon of the floaty.
	// Param[in]: nRows		          The input rows.
	// Param[in]: bTransparent		  The transparence value.
	// Return:    FS_LPVOID
	// Remarks: Return floating layer menu pointer CMiniFrameWnd - can be used to do moves etc.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID            CreateRibbonFloaty(FS_DevicePoint point, FS_INT32 nRows, FS_BOOL bTransparent);

	//************************************
	// Function:  InsertRibbonBtnsAfterFloatyCreate
	// Param[in]: vecBtnName		          The arry of button names.
	// Param[in]: nPos		                  The insert position.	
	// Return:    void
	// Remarks: Insert buttons to floaty.
	// Notes:  It only for windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static void				InsertRibbonBtnsAfterFloatyCreate(FS_ByteStringArray vecBtnName, FS_INT32 nPos);

	//************************************
	// Function:  RemoveFloatyRibbonBtns
	// Param[in]: vecBtnName		          The arry of button names.
	// Return:    void
	// Remarks: Remove button from floaty bar.
	// Notes:  It only for windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static void				RemoveFloatyRibbonBtns(FS_ByteStringArray vecBtnName);

	//************************************
	// Function:  GetDocTabIcon
	// Param[in]: hChildFrame		          The current child frame.
	// Return:    FS_ICON
	// Remarks: Get the tab icon.
	// Notes:  It only for windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_ICON  GetDocTabIcon(FS_HWND hChildFrame);

	//************************************
	// Function:  GetPDFChildFrmSplitWndRect	
	// Return:    FS_Rect
	// Remarks: Get the child frame rect.
	// Notes:  It only for windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_Rect  GetPDFChildFrmSplitWndRect();

	//************************************
	// Function:  ChangeUIRTL
	// Param[in]: pWnd		          The input CWnd* object.
	// Param[in]: bNoLoopOverPopup	  Whether need no loop over popup.
	// Return:    void
	// Remarks: Change UI RTL.
	// Notes:  It only for windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	// Deprecated: Internal use.
	//************************************
	static void ChangeUIRTL(FS_LPVOID pWnd, FS_BOOL bNoLoopOverPopup);
};

class CFR_ContainerFrmMgrHandler_V16 
{
public:
	//************************************
	// Function:  New
	// Param[in]: callbacks		The ContainerFrmEventCallbacks.
	// Return:    FR_ContainerFrmMgrHandler
	// Remarks: Create FR_ContainerFrmMgrHandler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_ContainerFrmMgrHandler New(FR_ContainerFrmEventCallbacks callbacks);

	//************************************
	// Function:  Destroy
	// Param[in]: handler		The FR_ContainerFrmMgrHandler.
	// Return:    void
	// Remarks: Delete FR_ContainerFrmMgrHandler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void Destroy(FR_ContainerFrmMgrHandler handler);
};

class CFR_ContainerFrmMgr_V16
{
public:
	//************************************
	// Function:  GetContainerFrmMgr
	// Return:    FR_ContainerFrmMgr
	// Remarks: Get FR_ContainerFrmMgr.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_ContainerFrmMgr GetContainerFrmMgr();

	//************************************
	// Function:  CreateContainerFrame
	// Param[in]: containerMgr		The FR_ContainerFrmMgr.
	// Param[in]: pParent		    The parent frame Cwnd.
	// Return:    void
	// Remarks: Create container frame of parent wnd.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_HWND        CreateContainerFrame(FR_ContainerFrmMgr containerMgr, FS_LPVOID pParent);

	//************************************
	// Function:  GetContainerFrame
	// Param[in]: containerMgr		The FR_ContainerFrmMgr.
	// Param[in]: pRDDoc		    The current document.
	// Return:    FS_HWND
	// Remarks: Get the hwnd of the container.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_HWND        GetContainerFrame(FR_ContainerFrmMgr containerMgr, FR_Document pRDDoc);

	//************************************
	// Function:  OpenDocument
	// Param[in]: containerMgr		The FR_ContainerFrmMgr.
	// Param[in]: hMainFrm		    The container frame.
	// Param[in]: csFilePath		The open file path.
	// Return:    FR_Document
	// Remarks: Get the document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_Document	  OpenDocument(FR_ContainerFrmMgr containerMgr,FS_HWND hMainFrm, FS_WideString csFilePath);

	//************************************
	// Function:  RegisterContainerFrmEventHandler
	// Param[in]: containerMgr		The FR_ContainerFrmMgr.
	// Param[in]: pFrmEvent		    The input handler.
	// Return:    FS_BOOLEAN
	// Remarks: true means register handler success.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static	FS_BOOLEAN	  RegisterContainerFrmEventHandler(FR_ContainerFrmMgr containerMgr, FR_ContainerFrmMgrHandler pFrmEvent);

	//************************************
	// Function:  UnRegisterContainerFrmEventHandler
	// Param[in]: containerMgr		The FR_ContainerFrmMgr.
	// Param[in]: pFrmEvent		    The input handler.
	// Return:    FS_BOOLEAN
	// Remarks: true means unregister handler success.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOLEAN	  UnRegisterContainerFrmEventHandler(FR_ContainerFrmMgr containerMgr, FR_ContainerFrmMgrHandler pFrmEvent);

	//************************************
	// Function:  OnContainerFrmCreate
	// Param[in]: containerMgr		The FR_ContainerFrmMgr.
	// Param[in]: hFrmWnd		    The input handler.
	// Return:    void
	// Remarks: Trigger the create container frame.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void			  OnContainerFrmCreate(FR_ContainerFrmMgr containerMgr, FS_HWND hFrmWnd);

	//************************************
	// Function:  OnContainerFrmLoadFinish
	// Param[in]: containerMgr		The FR_ContainerFrmMgr.
	// Param[in]: hFrmWnd		    The input handler.
	// Return:    void
	// Remarks: Trigger the container frame load finish.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void			  OnContainerFrmLoadFinish(FR_ContainerFrmMgr containerMgr, FS_HWND hFrmWnd);

	//************************************
	// Function:  OnContainerFrmDestory
	// Param[in]: containerMgr		The FR_ContainerFrmMgr.
	// Param[in]: hFrmWnd		    The input handler.
	// Return:    void
	// Remarks: Trigger destroy container frame.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void			  OnContainerFrmDestory(FR_ContainerFrmMgr containerMgr, FS_HWND hFrmWnd);
};

class CFR_PrintProvider_V16 // Internal use
{
public:
	//************************************
	// Function:  GetPrintProvider
	// Param[in]: doc		The input FR_Document.
	// Return:    FR_PrintProvider
	// Remarks: Get print provider.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_PrintProvider GetPrintProvider(FR_Document doc);

	//************************************
	// Function:  GetPrintDoc
	// Param[in]: provider		The input FR_PrintProvider.
	// Return:    FR_Document
	// Remarks: Get document need to print.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_Document GetPrintDoc(FR_PrintProvider provider);

	//************************************
	// Function:  GetDefaultPrinterName
	// Param[out]: printName		Get default printer name.
	// Return:    void
	// Remarks: Get default printer name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void        GetDefaultPrinterName(FS_WideString* printName);

	//************************************
	// Function:  IsSnapShot
	// Param[in]: provider		The input FR_PrintProvider.
	// Return:    FS_BOOL
	// Remarks: Whether is snap shot.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL     IsSnapShot(FR_PrintProvider provider);

	//************************************
	// Function:  GetDispMode
	// Param[in]: provider		The input FR_PrintProvider.
	// Return:    FS_INT32      Get display mode, like FR_LAYOUTMODE_SINGLE.
	// Remarks: Get display mode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_INT32    GetDispMode(FR_PrintProvider provider);

	//************************************
	// Function:  GetDefaultPrinterDevMode	
	// Return:    FS_LPVOID     Get print device mode.
	// Remarks: Get print device mode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_LPVOID   GetDefaultPrinterDevMode();

	//************************************
	// Function:  SetDefaultPrinterDevMode	
	// Param[in]: hDevNames		The input device HANDLE.
	// Param[in]: hDevMode		The input device mode HANDLE.
	// Return:    void     Get print device mode.
	// Remarks: Set print device mode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void		   SetDefaultPrinterDevMode(FS_LPVOID hDevNames, FS_LPVOID hDevMode);

	//************************************
	// Function:  AnnotsSortByOrder	
	// Param[in]: provider		    The input FR_PrintProvider.
	// Param[in]: pDoc		        The input FPD_Document.
	// Param[in]: nPageIndex		The input page index.
	// Param[in]: pAnnotsList		The input annot list.
	// Param[out]: outAnnotList		Get the annot list after sort by order.
	// Return:    void
	// Remarks: Sort annot by order.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void        AnnotsSortByOrder(FR_PrintProvider provider, FPD_Document pDoc, FS_INT32 nPageIndex, FPD_AnnotList pAnnotsList,  FS_PtrArray*  outAnnotList);
	
	//************************************
	// Function:  GetPrintParentHwnd	
	// Return:    FS_HWND
	// Remarks: Get print parent HAND.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_HWND     GetPrintParentHwnd();

	//************************************
	// Function:  ReleasePrintProvider	
	// Param[in]: provider		    The input FR_PrintProvider.
	// Return:    void
	// Remarks: Release print provider.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void        ReleasePrintProvider(FR_PrintProvider provider);
};

class CFR_WndProvider_V16
{
public:
	//************************************
	// Function:  GetCurrentWndProvide	
	// Param[in]: doc		     The input FR_Document.
	// Return:    FR_WndProvider Get the current wnd provider of the document.
	// Remarks: Get the current wnd provider of the document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_WndProvider GetCurrentWndProvide(FR_Document doc);

	//************************************
	// Function:  GetProviderName	
	// Param[in]: wndProvider		     The input FR_WndProvider.
	// Return:    FS_LPCSTR              Get the current provider name.
	// Remarks: Get the current provider name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_LPCSTR GetProviderName(FR_WndProvider wndProvider);
};

class CFR_GlobalData_V16 //Internal use
{
public:
	//************************************
	// Function:  IsForbiddenActionChangeZoom		
	// Return:    FS_BOOL    TRUE is forbidden change zoom.
	// Remarks: Check whether forbidden change zoom in preference setting.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	IsForbiddenActionChangeZoom();

	//************************************
	// Function:  IsReplaceDocumentColors		
	// Return:    FS_BOOL    TRUE is replace document color.
	// Remarks: Check whether replace document color in preference of accessbility tab setting.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL  IsReplaceDocumentColors();

	//************************************
	// Function:  IsOnlyChangeColorBlackText		
	// Return:    FS_BOOL    TRUE is only change color to black text.
	// Remarks: Check whether change color to black text in preference of accessbility tab setting.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL  IsOnlyChangeColorBlackText();

	//************************************
	// Function:  IsChangeColorTextOrBlackLineArt		
	// Return:    FS_BOOL    TRUE is change color text or black line art.
	// Remarks: Check whether change color text or black line art in preference of accessbility tab setting.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL  IsChangeColorTextOrBlackLineArt();

	//************************************
	// Function:  IsEnableAssistiveTechnologySupport		
	// Return:    FS_BOOL    TRUE is enable assistive technology support.
	// Remarks: Check whether enable assistive technology support in preference of reading tab setting.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL  IsEnableAssistiveTechnologySupport();

	//************************************
	// Function:  IsEmbedContentTextFont		
	// Return:    FS_BOOLEAN    true embed font for content text.
	// Remarks: Check whether enable embed font for content text.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN  IsEmbedContentTextFont();

	//************************************
	// Function:  IsUseLogicalPage		
	// Return:    FS_BOOLEAN    true It used logical page.
	// Remarks: Check whether use logical page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN  IsUseLogicalPage();

	//************************************
	// Function:  GetEidtDirection		
	// Return:    FS_INT32    0: left to right, 1: right to left.
	// Remarks: Get edit direction.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_INT32  GetEidtDirection();

	//************************************
    // Function:  GetInitialOpenDir
	// Param[in/out]: outDir		     Get initial open path.
	// Return:   void
	// Remarks:  Get initial open path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void  GetInitialOpenDir(FS_WideString* outDir);
};

class CFR_HandlerDataType_V16 //Internal use
{
public:
	//************************************
	// Function:  CreateDataType	
	// Param[in]: callbacks		     The input FR_HandlerDataTypeCallbacks.
	// Return:    FR_HandlerDataType    Create FR_HandlerDataType object.
	// Remarks: Create datatype object to tell the frame 
	// the type of the object being operated on.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FR_HandlerDataType	CreateDataType(FR_HandlerDataTypeCallbacks callbacks);

	//************************************
	// Function:  DeleteDataType	
	// Param[in]: dataType		     The input FR_HandlerDataType.
	// Return:   void
	// Remarks: Delete data type.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void DeleteDataType(FR_HandlerDataType dataType);
};

class CFR_MuCopyData_V16 //Internal use
{
public:
	//************************************
	// Function:  Create		
	// Return:   FR_MuCopyData
	// Remarks: Create FR_MuCopyData.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FR_MuCopyData Create();

	//************************************
	// Function:  Destroy
	// Param[in]: data		     The input FR_MuCopyData.
	// Return:   void
	// Remarks: Destroy FR_MuCopyData.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void Destroy(FR_MuCopyData data);

	//************************************
	// Function:  GetClientData
	// Param[in]: data		     The input FR_MuCopyData.
	// Return:   FS_LPVOID
	// Remarks: Get client data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID GetClientData(FR_MuCopyData data);

	//************************************
	// Function:  GetRectArray
	// Param[in]: data		     The input FR_MuCopyData.
	// Return:   FS_FloatRectArray
	// Remarks: Get rect array.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_FloatRectArray GetRectArray(FR_MuCopyData data);

	//************************************
	// Function:  GetRowCount
	// Param[in]: data		     The input FR_MuCopyData.
	// Return:   FS_INT32
	// Remarks: Get row count.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 GetRowCount(FR_MuCopyData data);

	//************************************
	// Function:  SetClientData
	// Param[in]: data		     The input FR_MuCopyData.
	// Param[in]: clientData	 The input client data.
	// Return:   void
	// Remarks: Set client data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void SetClientData(FR_MuCopyData data, FS_LPVOID clientData);

	//************************************
	// Function:  SetRectArray
	// Param[in]: data		     The input FR_MuCopyData.
	// Param[in]: array		     The input rect array.
	// Return:   void
	// Remarks: Set rect array.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void SetRectArray(FR_MuCopyData data, FS_FloatRectArray rectArray);

	//************************************
	// Function:  SetRowCount
	// Param[in]: data		     The input FR_MuCopyData.
	// Param[in]: rowCount		 The input row count.
	// Return:   void
	// Remarks: Set row count.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void SetRowCount(FR_MuCopyData data, FS_INT32 rowCount);

	//************************************
	// Function:  CopyData
	// Param[in]: srcData		 The input source FR_MuCopyData.
	// Param[in\out]: destData	 The input dest FR_MuCopyData.
	// Return:   void
	// Remarks: Copy data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void CopyData(FR_MuCopyData srcData, FR_MuCopyData* destData);
};

class CFR_PrintMgr_V17
{
public:
	//************************************
	// Function:  Create
	// Param[in]: doc		             The input FR_Document that need to print.
	// Param[in]: bQuietMode	         Set if it's quite mode.
	// Param[in]: wsFilePath	         The input file path.
	// Return:   FR_PrintMgr
	// Remarks: Create FR_PrintMgr obj.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FR_PrintMgr  Create(FR_Document doc, FS_BOOL bQuietMode, FS_LPCWSTR wsFilePath);

	//************************************
	// Function:  Delete
	// Param[in]: printMgr		         The input FR_PrintMgr.	
	// Return:   void
	// Remarks: Delete FR_PrintMgr obj.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void   Delete(FR_PrintMgr printMgr);

	//************************************
	// Function:  SetPrintRange
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[in]: nRangeMode		 The input range mode, like FR_PRINT_RANG_xxx.	
	// Param[in]: nFrom		         The input start page, it set when range mode is FR_PRINT_RANGE_PAGES.	
	// Param[in]: nTo		         The input end page, it set when range mode is FR_PRINT_RANGE_PAGES.	
	// Return:   void
	// Remarks: Set the page range.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintRange(FR_PrintMgr printMgr, FS_INT32 nRangeMode, FS_INT32 nFrom, FS_INT32 nTo);

	//************************************
	// Function:  GetPrintRange
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[out]: nRangeMode		 Get input range mode, like FR_PRINT_RANG_xxx.	
	// Param[out]: nFrom		     Ghe input start page, it get success when range mode is FR_PRINT_RANGE_PAGES.	
	// Param[out]: nTo		         Ghe input end page, it get success when range mode is FR_PRINT_RANGE_PAGES.	
	// Return:   void
	// Remarks: Get the page range.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void GetPrintRange(FR_PrintMgr printMgr, FS_INT32* nRangeMode, FS_INT32* nFrom, FS_INT32* nTo);

	//************************************
	// Function:  SetPrintSubset
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[in]: nSubsetMode		 Get input range mode, like FR_PRINT_SUBSET_xxx.
	// Return:   void
	// Remarks: Set print subset.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintSubset(FR_PrintMgr printMgr, FS_INT32 nSubsetMode);

	//************************************
	// Function:  GetPrintSubset
	// Param[in]: printMgr		     The input FR_PrintMgr.		
	// Return:   FS_INT32    Like FR_PRINT_SUBSET_xxx.
	// Remarks: Get print subset.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_INT32  GetPrintSubset(FR_PrintMgr printMgr);	

	//************************************
	// Function:  SetPrintRotate
	// Param[in]: printMgr		     The input FR_PrintMgr.		
	// Param[in]: nRotateMode		 The input rotate mode, like FR_PRINT_ROTATE_MODE_xxx.		
	// Return:   void
	// Remarks: Set print rotate.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintRotate(FR_PrintMgr printMgr, FS_INT32 nRotateMode);

	//************************************
	// Function:  GetPrintRotate
	// Param[in]: printMgr		     The input FR_PrintMgr.		
	// Return:   FS_INT32            Get the print rotate,like FR_PRINT_ROTATE_MODE_xxx.		
	// Remarks: Get print rotate.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_INT32	 GetPrintRotate(FR_PrintMgr printMgr);

	//************************************
	// Function:  SetPrintScale
	// Param[in]: printMgr		     The input FR_PrintMgr.		
	// Param[in]: nZoomToMode		 The input zoom mode, like FR_PRINT_ZOOM_MODE_xxx.	
	// Param[in]: flScale		     The input scale value.	
	// Return:   void               
	// Remarks: Set print scale.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintScale(FR_PrintMgr printMgr, FS_INT32 nZoomToMode, FS_FLOAT flScale);

	//************************************
	// Function:  GetPrintScale
	// Param[in]: printMgr		     The input FR_PrintMgr.		
	// Param[out]: nZoomToMode		 Get zoom mode, like FR_PRINT_ZOOM_MODE_xxx.	
	// Param[out]: flScale		     Get scale value.	
	// Return:   void               
	// Remarks: Get print scale.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void GetPrintScale(FR_PrintMgr printMgr, FS_INT32* nZoomToMode, FS_FLOAT* flScale);

	//************************************
	// Function:  SetPrintArrange
	// Param[in]: printMgr		     The input FR_PrintMgr.		
	// Param[in]: nArrangeMode		 Get zoom mode, like FR_PRINT_ZOOM_MODE_xxx.	
	// Return:   void               
	// Remarks: Set print arrange.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintArrange(FR_PrintMgr printMgr, FS_INT32 nArrangeMode);

	//************************************
	// Function:  GetPrintArrange
	// Param[in]: printMgr		     The input FR_PrintMgr.		
	// Return:   FS_INT32               
	// Remarks: Get print arrange.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_INT32  GetPrintArrange(FR_PrintMgr printMgr);

	//************************************
	// Function:  SetPrintCopies
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[in]: nCopies		     The input print copies.
	// Return:   void               
	// Remarks: Set print copies.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintCopies(FR_PrintMgr printMgr, FS_UINT nCopies);

	//************************************
	// Function:  GetPrintCopies
	// Param[in]: printMgr		     The input FR_PrintMgr.
	// Return:   FS_UINT               
	// Remarks: Get print copies.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_UINT GetPrintCopies(FR_PrintMgr printMgr);

	//************************************
	// Function:  SetPrintAutoCenter
	// Param[in]: printMgr		     The input FR_PrintMgr.
	// Param[in]: bAutoCenter		 Set if enable auto center.
	// Return:   void               
	// Remarks: Set print auto center.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintAutoCenter(FR_PrintMgr printMgr, FS_BOOLEAN bAutoCenter);

	//************************************
	// Function:  GetPrintAutoCenter
	// Param[in]: printMgr		     The input FR_PrintMgr.
	// Return:   FS_BOOLEAN               
	// Remarks: Get if enable print auto center.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_BOOLEAN	GetPrintAutoCenter(FR_PrintMgr printMgr);

	//************************************
	// Function:  SetPrintAutoRotate
	// Param[in]: printMgr		     The input FR_PrintMgr.
	// Param[in]: bAutoRotate		 Set if enable auto rotate
	// Return:   void               
	// Remarks: Set print auto rotate.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintAutoRotate(FR_PrintMgr printMgr, FS_BOOLEAN bAutoRotate);

	//************************************
	// Function:  GetPrintAutoRotate
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Return:   FS_BOOLEAN               
	// Remarks: Get if enable print auto rotate.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_BOOLEAN	GetPrintAutoRotate(FR_PrintMgr printMgr);

	//************************************
	// Function:  SetPrintGray
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[in]: bGray		         Set if print gray.	
	// Return:   void               
	// Remarks: Set print gray.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintGray(FR_PrintMgr printMgr, FS_BOOLEAN bGray);

	//************************************
	// Function:  GetPrintGray
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Return:   FS_BOOLEAN               
	// Remarks: Get print gray.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_BOOLEAN GetPrintGray(FR_PrintMgr printMgr);

	//************************************
	// Function:  SetPrintCollate
	// Param[in]: printMgr		     The input FR_PrintMgr.
	// Param[in]: bCollate		     Set if need collate.	
	// Return:   void               
	// Remarks: Set print collate.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintCollate(FR_PrintMgr printMgr, FS_BOOLEAN bCollate);

	//************************************
	// Function:  GetPrintCollate
	// Param[in]: printMgr		     The input FR_PrintMgr.
	// Return:   FS_BOOLEAN               
	// Remarks: Get print collate.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_BOOLEAN GetPrintCollate(FR_PrintMgr printMgr);

	//************************************
	// Function:  SetPrintPageOrder
	// Param[in]: printMgr		     The input FR_PrintMgr.
	// Param[in]: nOrderMode		 The input page order, like FR_PRINT_ORDER_xxx.
	// Return:   void               
	// Remarks: Set print page order
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintPageOrder(FR_PrintMgr printMgr, FS_INT32 nOrderMode);

	//************************************
	// Function:  SetPrintPageBorder
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[in]: bBorder		     Set if print page border when set multi page per sheet handle.	
	// Return:   void               
	// Remarks: Set if need print page border.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintPageBorder(FR_PrintMgr printMgr, FS_BOOLEAN bBorder);

	//************************************
	// Function:  GetPrintPageBorder
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Return:   FS_BOOLEAN               
	// Remarks: Set print page order
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_BOOLEAN GetPrintPageBorder(FR_PrintMgr printMgr);

	//************************************
	// Function:  SetPrintPrintWhat
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[in]: nPrintWhatMode	 The input print what mode, like  FR_PRINT_WHAT_xxx.	
	// Return:   void               
	// Remarks: Set print what mode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintPrintWhat(FR_PrintMgr printMgr, FS_INT32 nPrintWhatMode);

	//************************************
	// Function:  SetPrintOrientation
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[in]: nPrintOriType	     The input print orientation type.	
	// Return:   void               
	// Remarks: Set print orientation.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintOrientation(FR_PrintMgr printMgr, FR_PrintOrientationType nPrintOriType);

	//************************************
	// Function:  SetPrintPagesPerSheet
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[in]: nPerSheetMode	     The input page sheet mode, like FR_PRINT_FACING_xxx.	
	// Param[in]: nHorzs	         The input pages that each row shows.
	// Param[in]: nVerts	         The input pages that each column shows.
	// Return:   void               
	// Remarks: Set print pages per sheet.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintPagesPerSheet(FR_PrintMgr printMgr, FS_INT32 nPerSheetMode, FS_INT32 nHorzs, FS_INT32 nVerts);

	//************************************
	// Function:  GetPrintPagesPerSheet
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[out]: nHorzs	         Get page numbers that each row shows.
	// Param[out]: nVerts	         Get page numbers that each column shows.
	// Return:   void               
	// Remarks: Get print pages per sheet.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void GetPrintPagesPerSheet(FR_PrintMgr printMgr, FS_INT32* nHorzs, FS_INT32* nVerts);

	//************************************
	// Function:  SetPrintPaperSizeByPage
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[in]: bPaperSizeByPage	 Set if choose papper source by page size.	
	// Return:   void               
	// Remarks: Set if choose papper source by page size.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintPaperSizeByPage(FR_PrintMgr printMgr, FS_BOOLEAN bPaperSizeByPage);

	//************************************
	// Function:  SetPrintReverse
	// Param[in]: printMgr		     The input FR_PrintMgr.	
	// Param[in]: bReverse	         Set if need print reverse page.	
	// Return:   void               
	// Remarks: Set if need print reverse page.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintReverse(FR_PrintMgr printMgr, FS_BOOLEAN bReverse);

	//************************************
	// Function:  GetPrintReverse
	// Param[in]: printMgr		     The input FR_PrintMgr.		
	// Return:   FS_BOOLEAN               
	// Remarks: Get if need print reverse page.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_BOOLEAN GetPrintReverse(FR_PrintMgr printMgr);

	//************************************
	// Function:  SetPrintMargins
	// Param[in]: printMgr		     The input FR_PrintMgr.		
	// Param[in]: flMargins		     The input print margins.	
	// Return:   void               
	// Remarks: Set print margins.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintMargins(FR_PrintMgr printMgr, FS_FLOAT flMargins);

	//************************************
	// Function:  SetPrintAsImage
	// Param[in]: printMgr		     The input FR_PrintMgr.		
	// Param[in]: bPrintAsImage		 Set if print as image.	
	// Return:   void               
	// Remarks: Set print as image.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintAsImage(FR_PrintMgr printMgr, FS_BOOLEAN bPrintAsImage);

	//************************************
	// Function:  SetSimulateOverprinting
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: bSimulateOverprintint		 Set if need simulate over print.	
	// Return:   void               
	// Remarks: Set if need simulate over print.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetSimulateOverprinting(FR_PrintMgr printMgr, FS_BOOLEAN bSimulateOverprintint);

	//************************************
	// Function:  SetPrintIgnoreAdvancedSetting
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: bIgnoreAdvanced		     Set if ignore advance settings.	
	// Return:   void               
	// Remarks: Set if ignore advance settings.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintIgnoreAdvancedSetting(FR_PrintMgr printMgr, FS_BOOL bIgnoreAdvanced);

	//************************************
	// Function:  SetProgressDisplay
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: bShow		                 Set if show progress.	
	// Return:   void               
	// Remarks: Set if show progress.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetProgressDisplay(FR_PrintMgr printMgr, FS_BOOL bShow);

	//************************************
	// Function:  SetPaperSize
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: papersize		             Set page size.	
	// Return:   void               
	// Remarks: Set page size.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPaperSize(FR_PrintMgr printMgr, FS_INT32 papersize);

	//************************************
	// Function:  SetPrintPageArray
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: PageArray		             Set page array need to print.	
	// Return:   void               
	// Remarks: Set print page array.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintPageArray(FR_PrintMgr printMgr, FS_WordArray PageArray);

	//************************************
	// Function:  GetPrintPageArray
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[out]: PageArray		         Get page array need to print.	
	// Return:   void               
	// Remarks: Get print page array.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void GetPrintPageArray(FR_PrintMgr printMgr, FS_WordArray* PageArray);

	//************************************
	// Function:  GetDefaultPrint
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[out]: wsPrintName		         Get default printer.	
	// Return:   void               
	// Remarks: Get default printer.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void GetDefaultPrint(FR_PrintMgr printMgr, FS_WideString* wsPrintName);

	//************************************
	// Function:  SetDefaultPrint
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: strPrinterName		     Set default printer.	
	// Return:   void               
	// Remarks: Get default printer.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetDefaultPrint(FR_PrintMgr printMgr, FS_LPCWSTR  strPrinterName);

	//************************************
	// Function:  SetPrintOutputFileName
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: wsOutputFileName		     Set print output file name.	
	// Return:   void               
	// Remarks:  Set print output file name.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintOutputFileName(FR_PrintMgr printMgr, FS_LPCWSTR wsOutputFileName);

	//************************************
	// Function:  DoModal
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: hParentHwnd		         The dialog parent hwnd.	
	// Return:   FS_INT32               
	// Remarks:  Show print dialog.	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_INT32  DoModal(FR_PrintMgr printMgr, FS_HWND hParentHwnd);	

	//************************************
	// Function:  SetPrintDevMode
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: strPrinterName		     The input printer name.	
	// Param[in]: devMode		             The input DEVMODE in windows, mac platform ignore it.
	// Return:   void               
	// Remarks:  Set print device mode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintDevMode(FR_PrintMgr printMgr, FS_LPCSTR strPrinterName, FS_LPVOID devMode);

	//************************************
	// Function:  SetPrintPreview
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: bPreview		             Set if need show preview.
	// Return:   void               
	// Remarks:  Set if need show preview.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintPreview(FR_PrintMgr printMgr, FS_BOOLEAN bPreview);

	//************************************
	// Function:  EnablePrintAnnot
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: bEnable		             Set if need enable print annot.
	// Return:   void               
	// Remarks:  Set if need enable print annot.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void EnablePrintAnnot(FR_PrintMgr printMgr, FS_BOOLEAN bEnable);

	//************************************
	// Function:  SetRangeMode
	// Param[in]: printMgr		             The input FR_PrintMgr.		
	// Param[in]: nRangeMode		         Set print range mode, like FR_PRINT_RANGE_xxx.
	// Return:   void               
	// Remarks:  Set print range mode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetRangeMode(FR_PrintMgr printMgr, FS_INT32 nRangeMode);

	//************************************
	// Function:  GetRangeMode
	// Param[in]: printMgr		             The input FR_PrintMgr.	
	// Return:   FS_INT32               
	// Remarks:  Get print range mode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_INT32 GetRangeMode(FR_PrintMgr printMgr);

	//************************************
	// Function:  SetPrintBookletBinding
	// Param[in]: printMgr		             The input FR_PrintMgr.	
	// Param[in]: nBinding		             The input booklet binding direction, like FR_PRINT_BOOKLET_BINDING_xxx.	
	// Return:   void               
	// Remarks:  Set print booklet binding.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintBookletBinding(FR_PrintMgr printMgr, FS_INT32 nBinding);

	//************************************
	// Function:  SetPrintBookletSubSet
	// Param[in]: printMgr		             The input FR_PrintMgr.	
	// Param[in]: nSubset		             The input booklet subset, like FR_PRINT_BOOKLET_SUBSET_xxx.	
	// Return:   void               
	// Remarks:  Set print booklet binding.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintBookletSubSet(FR_PrintMgr printMgr, FS_INT32 nSubset);

	//************************************
	// Function:  SetPrintCutMarks
	// Param[in]: printMgr		             The input FR_PrintMgr.	
	// Param[in]: bCutMarks		             Set if need cut marks.
	// Return:   void               
	// Remarks:  Set print cut marks.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintCutMarks(FR_PrintMgr printMgr, FS_BOOLEAN bCutMarks);

	//************************************
	// Function:  SetPrintLabels
	// Param[in]: printMgr		             The input FR_PrintMgr.	
	// Param[in]: bLabels		             Set if need print labels.
	// Return:   void               
	// Remarks:  Set print lebels.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintLabels(FR_PrintMgr printMgr, FS_BOOLEAN bLabels);

	//************************************
	// Function:  SetPrintPageScaleType
	// Param[in]: printMgr		             The input FR_PrintMgr.	
	// Param[in]: nPageScale		         Set page scale, like FR_PRINT_ZOOM_MODE_xxx.
	// Return:   void               
	// Remarks:  Set print page scale type.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintPageScaleType(FR_PrintMgr printMgr, FS_INT32 nPageScale);

	//************************************
	// Function:  EnumPrinterName
	// Param[in]: printMgr		             The input FR_PrintMgr.	
	// Param[out]: arrPrintName		         Get printer names.
	// Return:   void               
	// Remarks:  Get printer names.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void EnumPrinterName(FR_PrintMgr printMgr, FS_WideStringArray* arrPrintName);

	//************************************
	// Function:  SetPrintDuplexType
	// Param[in]: printMgr		             The input FR_PrintMgr.	
	// Param[in]: bDuplex		             Set if need duplex print.
	// Return:   void               
	// Remarks:  Set if need duplex print.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintDuplexType(FR_PrintMgr printMgr, FS_BOOLEAN bDuplex);

	//************************************
	// Function:  SetPrintOverlap
	// Param[in]: printMgr		             The input FR_PrintMgr.	
	// Param[in]: dOverlap		             Set if need overlap.
	// Return:   void               
	// Remarks:  Set if need print over lap.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintOverlap(FR_PrintMgr printMgr, FS_BOOLEAN dOverlap);

	//************************************
	// Function:  SetPrintHandlingType
	// Param[in]: printMgr		             The input FR_PrintMgr.	
	// Param[in]: nPrintHandlingType		 Set print handle type, like FR_PRINT_HANDLING_xxx.
	// Return:   void               
	// Remarks:  Set print handle type.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetPrintHandlingType(FR_PrintMgr printMgr, FS_INT32 nPrintHandlingType);

	//************************************
	// Function:  GetPrintHandlingType
	// Param[in]: printMgr		             The input FR_PrintMgr.	
	// Return:   FS_INT32               
	// Remarks:  Get print handle type.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_INT32  GetPrintHandlingType(FR_PrintMgr printMgr);
};

class CFR_DRMEventHandler : public IReader_DRMEventHandler
{
public:
	CFR_DRMEventHandler(FR_DRMEventCallbacks callbacks);
	virtual ~CFR_DRMEventHandler();
	virtual void    Release() {}
	
	virtual BOOL DecryptFile(LPCWSTR pszInPath, CFX_WideString& pszOutPath, OtherToPDF operation);
	virtual BOOL DeleteDecryptFile(LPCWSTR pszPath, OtherToPDF operation);
	virtual BOOL EncryptionDocument(IReader_Document* pDocument, LPCWSTR pszInPath, CFX_WideString& pszOutPath, PDFToOther operation);
	virtual BOOL DeleteEncryptionFile(IReader_Document* pDocument, LPCWSTR pszPath, PDFToOther operation);
protected:
	FR_DRMEventCallbacksRec m_Callbacks;
};

class CFR_EncryptedDocMgr_V17
{
public:
	//************************************
	// Function:  ToDecFile
	// Param[in]: pszInPath	        The input DRM file path.
	// Param[out]: pszOutPath	    Get the temp decrypted file path.
	// Param[in]: operation	        The operate type need to decrypt file.
	// Return:	FS_BOOL    TRUE: Decrypt success.
	// Remarks: Obtain the file path after decrypt, such as DRM.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// See: FREncryptedDocMgrToDecFile
	// Deprecated: Internal use.
	//************************************
	static  FS_BOOL ToDecFile(FS_LPCWSTR pszInPath, FS_WideString* pszOutPath, FR_OtherToPDF operation);
	
	//************************************
	// Function:  ToDelDecFile
	// Param[in]: pszPath	    The input decrypted file path need to delete.
	// Param[in]: operation	    The operate type need to decrypt file.
	// Return:	FS_BOOL
	// Remarks: Delete the temp decrypted file.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// See: FREncryptedDocMgrToDelDecFile
	// Deprecated: Internal use.
	//************************************
	static  FS_BOOL ToDelDecFile(FS_LPCWSTR pszPath, FR_OtherToPDF operation);
	
	//************************************
	// Function:  ToEncFile
	// Param[in]: pDocument	     The input FR_Document.
	// When split or extract pages with it, plugin need to check if it's an encrypted file.
	// Param[in]: pszPath	     The input file path need to encrypt.
	// Param[out]: pszOutPath	 Get the temp encrypted file path.
	// Param[in]: operation	     The operate type need to encrypt file.
	// Return:	FS_BOOL   
	// Remarks: Obtain the file path after encrypt, such as DRM.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// See: FREncryptedDocMgrToEncFile
	// Deprecated: Internal use.
	//************************************
	static  FS_BOOL ToEncFile(FR_Document pDocument, FS_LPCWSTR pszInPath, FS_WideString* pszOutPath, FR_PDFToOther operation);

	//************************************
	// Function:  ToDelEncFile
	// Param[in]: pDocument	     The input FR_Document.
	// When split or extract pages with it, plugin need to check if it's an encrypted file.
	// Param[in]: pszPath	     The input temp encrypted file need to delete.	
	// Param[in]: operation	     The operate type need to encrypt file.
	// Return:	FS_BOOL
	// Remarks: Delete the temp encrypted file.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// See: FREncryptedDocMgrToDelEncFile
	// Deprecated: Internal use.
	//************************************
	static  FS_BOOL ToDelEncFile(FR_Document pDocument, FS_LPCWSTR pszPath, FR_PDFToOther operation);
};

class CFR_PDFBitmapMgr_V17
{
public:
	//************************************
	// Function:  Create
	// Param[in]: bsName	       The input bitmap mgr name.
	// Param[in]: wsLightPath	   The input light path.
	// Param[in]: wsDarkPath	   The input dark path.
	// Return:	 FR_PDFBitmapMgr
	// Remarks:  Create FR_PDFBitmapMgr object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static FR_PDFBitmapMgr Create(FS_LPCSTR bsName, FS_LPCWSTR wsLightPath, FS_LPCWSTR wsDarkPath);

	//************************************
	// Function:  GetByName
	// Param[in]: bsName	       The input bitmap mgr name.	
	// Return:	 FR_PDFBitmapMgr
	// Remarks:  Get FR_PDFBitmapMgr object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static FR_PDFBitmapMgr GetByName(FS_LPCSTR bsName);

	//************************************
	// Function:  GetBitmap
	// Param[in]: mgr			The input FR_PDFBitmapMgr object.
	// Param[in]: wsImageName	It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf. 
	// Param[in]: cx			Set the width of the image.
	// Param[in]: cy	        Set the height of the image.
	// Param[in]: clrReplace	Set fill color of the image.	
	// Param[in]: style			    The input skin style.
	// Return:	 HBITMAP
	// Remarks:  Get HBITMAP of specified image name from ribbonimage-phantom.pdf.
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static HBITMAP GetBitmap(FR_PDFBitmapMgr mgr, FS_LPCWSTR wsImageName, FS_INT32 cx, FS_INT32 cy, FS_COLORREF clrReplace, FR_SKINSTYLE style);


	//************************************
	// Function:  GetFXBitmap
	// Param[in]: mgr			The input FR_PDFBitmapMgr object.
	// Param[in]: wsImageName	It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf. 
	// Param[in]: cx			Set the width of the image.
	// Param[in]: cy	        Set the height of the image.
	// Param[in]: clrReplace	Set fill color of the image.	
	// Param[in]: dwSytle			    The input skin style.
	// Return:	 FS_DIBitmap
	// Remarks:  Get FS_DIBitmap of specified image name from ribbonimage-phantom.pdf.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_DIBitmap GetFXBitmap(FR_PDFBitmapMgr mgr, FS_LPCWSTR wsImageName, FS_INT32 cx, FS_INT32 cy, FS_COLORREF clrReplace, FR_SKINSTYLE dwSytle);

	//************************************
	// Function:  Draw
	// Param[in]: mgr			    The input FR_PDFBitmapMgr object.
	// Param[in]: hDC				Render device 
	// Param[in]: iconRect			the rect of PDFBitmap need to render
	// Param[in]: wsPDFBitmapName	the name of the PDFBitmap, which is from the bookmark of \res\ribbon\ribbonimage.pdf
	// Param[in]: bDisable			<a>TRUE</a> means drawing PDFBitmap as disable mode, otherwise not.
	// Param[in]: clrBack			background color
	// Param[in]: clrReplace		replaced color
	// Param[in]: bAlpha			<a>TRUE</a> means drawing PDFBitmap as transparency.if it is TRUE, clrBack param will be ignore.
	// Param[in]: style			    The input skin style.
	// Return:	  <a>TRUE</a> means successful, otherwise not.
	// Remarks:   Draw PDFBitmap
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL Draw(FR_PDFBitmapMgr mgr, FS_HDC hDC, FS_FloatRect iconRect, FS_LPCWSTR wsPDFBitmapName, FS_BOOL bDisable, FS_COLORREF clrBack, FS_COLORREF clrReplace, FS_BOOL bAlpha, FR_SKINSTYLE style);


	//************************************
	// Function:  FillRoundedRectangle
	// Param[in]: mgr			The input FR_PDFBitmapMgr object.
	// Param[in]: pDC	        The input CDC object.
	// Param[in]: rect			The input rounded rect.
	// Param[in]: clrFill	    The input fill color.
	// Param[in]: ptRoundRadius	The input point of round radius.	
	// Return:	 void
	// Remarks:  Fill round rectangle of specified property.
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static void FillRoundedRectangle(FR_PDFBitmapMgr mgr, FS_LPVOID pDC, FS_Rect rect, FS_COLORREF clrFill, FS_DevicePoint ptRoundRadius);

	//************************************
	// Function:  DrawRoundedRectangle
	// Param[in]: mgr			The input FR_PDFBitmapMgr object.
	// Param[in]: pDC	        The input CDC object.
	// Param[in]: rect			The input rounded rect.
	// Param[in]: clrFill	    The input fill color.
	// Param[in]: ptRoundRadius	The input point of round radius.	
	// Return:	 void
	// Remarks:  Draw round rectangle of specified property.
	// Notes: It only used on Windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use.
	//************************************
	static void DrawRoundedRectangle(FR_PDFBitmapMgr mgr, FS_LPVOID pDC, FS_Rect rect, FS_COLORREF clrLine, FS_DevicePoint ptRoundRadius, FS_INT32 nLineWidth, FS_INT32 nPenStyle);
};

class CFR_StartPageEventHandler : public IReader_StartPageEventHandler
{
public:
	CFR_StartPageEventHandler(FR_StartPageEventCallbacks callbacks);
	~CFR_StartPageEventHandler();

	virtual void    OnStartPageActivate();
	virtual void    OnStartPageDeactivate();

protected:
	FR_StartPageEventCallbacksRec m_Callbacks;
};

class CFR_StartPageEventHandler_V19
{
public:
	//************************************
	// Function:  New
	// Param[in]: callback			The input FR_StartPageEventCallbacks object.		
	// Return:	 FR_StartPageEventHandler
	// Remarks:  Construct FR_StartPageEventHandler object by FR_StartPageEventCallbacks.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0	
	//************************************
	static FR_StartPageEventHandler New(FR_StartPageEventCallbacks callback);

	//************************************
	// Function:  Delete
	// Param[in]: handler			The input FR_StartPageEventHandler object.		
	// Return:	 void
	// Remarks:  Release FR_StartPageEventHandler object.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0	
	//************************************
	static void Delete(FR_StartPageEventHandler handler);
};

class CFR_UndoEventHandler : public IUndo_EventHandler
{
public:
	CFR_UndoEventHandler(FR_UndoEventCallbacks callbacks);
	~CFR_UndoEventHandler();

	virtual void					BeforeUndo(IReader_Document* pDocument);
	virtual void					BeforeRedo(IReader_Document* pDocument);
	virtual void					AfterUndo(IReader_Document* pDocument);
	virtual void					AfterRedo(IReader_Document* pDocument);

protected:
	FR_UndoEventCallbacksRec m_Callbacks;
};

class CFR_UndoEventHandler_V19
{
public:
	//************************************
	// Function:  New
	// Param[in]: callback			The input FR_UndoEventCallbacks object.		
	// Return:	 FR_UndoEventHandler
	// Remarks:  Construct FR_UndoEventHandler object by FR_UndoEventCallbacks.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0	
	//************************************
	static FR_UndoEventHandler New(FR_UndoEventCallbacks callback);

	//************************************
	// Function:  Delete
	// Param[in]: handler			The input FR_UndoEventHandler object.		
	// Return:	 void
	// Remarks:  Release FR_UndoEventHandler object.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0	
	//************************************
	static void Delete(FR_UndoEventHandler handler);
};

class CFR_SelectionHandler_V21
{
public:
	//************************************
	// Function:  GetFromType
	// Param[in]: type	     The input selection type.	
	// Return:	FR_SelectionHandler   
	// Remarks: Get the selection handler by specified type.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FR_SelectionHandler GetFromType(FS_LPCSTR type);

	//************************************
	// Function:  KeyDown
	// Param[in]: handler	     The input selection type.	
	// Param[in]: pDocument	     The input FR_Document object.	
	// Param[in]: curSelectData	 The input selection data.	
	// Param[in]: nKeyCode	     The input key code.	
	// Param[in]: nFlags	     The input flags.
	// Return:	FS_BOOLEAN   
	// Remarks: Trigger the keydown event.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	KeyDown(FR_SelectionHandler handler, FR_Document pDocument, FS_LPVOID curSelectData, FS_UINT nKeyCode, FS_UINT nFlags);

	//************************************
	// Function:  KeyUp
	// Param[in]: handler	     The input selection type.	
	// Param[in]: pDocument	     The input FR_Document object.	
	// Param[in]: curSelectData	 The input selection data.	
	// Param[in]: nKeyCode	     The input key code.	
	// Param[in]: nFlags	     The input flags.
	// Return:	FS_BOOLEAN   
	// Remarks: Trigger the keyup event.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	KeyUp(FR_SelectionHandler handler, FR_Document pDocument, FS_LPVOID curSelectData, FS_UINT nKeyCode, FS_UINT nFlags);
};
#ifdef __cplusplus
};
#endif

#endif

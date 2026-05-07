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
/* Tool HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRToolNew
 * @details Creates a tool object.
 * @param[in]  name The tool name. It may not be <a>NULL</a>.
 * @param[in]  callbacks The event callbacks associate with a tool. When a event occurs, Reader will
    * call a corresponding callback function.
 * @return   The new tool object or <a>NULL</a> if the tool with the <param>name</param> is exist.
 * @note If the tool name has been used, <a>NULL</a> will return.
 * @see FRToolRelease
 * @see FRAppRegisterTool
 */
INTERFACE(FR_Tool, FRToolNew, (FS_LPCSTR name,  FR_ToolCallbacks callbacks))

/**
 * @brief FRToolRelease
 * @details Releases the specified tool.
 * @param[in]  tool The tool to release.
 * @return   void
 * @note 
 */
INTERFACE(void, FRToolRelease, (FR_Tool tool))

/**
 * @brief FRToolGetName
 * @details Gets the name of specified tool.
 * @param[in]  tool The tool object.
 * @param[out]  outName The tool name buffer,filled by Reader.
 * @return   void
 * @note 
 */
INTERFACE(void, FRToolGetName, (FR_Tool tool,  FS_ByteString* outName))

/**
 * @brief FRToolSetAssociatedMousePtHandlerType
 * @details Sets the type of associated mouse point handler.
 * @param[in]  tool The tool object.
 * @param[in]  lpsType The type of associated mouse point handler.
 * @return   void
 * @note 
 * @see FRAppRegisterMousePtHandler
	
 * @Deprecated    Internal use
 */
INTERFACE(void, FRToolSetAssociatedMousePtHandlerType, (FR_Tool tool,  FS_LPCSTR lpsType))

/**
 * @brief FRToolSetAssociatedSelectionHandlerType
 * @details Sets the type of associated selection handler.
 * @param[in]  tool The tool object.
 * @param[in]  lpsType The type of associated selection handler.
 * @return   void
 * @note 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRToolSetAssociatedSelectionHandlerType, (FR_Tool tool,  FS_LPCSTR lpsType))

/**
 * @brief FRToolTool_GetBeginPoint
 * @details Get the first point of pressing mouse when using special tool.
 * @param[in]  tool The tool object.
 * @param[out]  point The <a>FS_DevicePoint</a> specified in screen coordinates.
 * @return   FS_BOOL TRUE is to success. FLASE is to failure.
 * @note 
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOL, FRToolTool_GetBeginPoint, (FR_Tool tool,  FS_DevicePoint& point))

NumOfSelector(FRTool)
ENDENUM

//*****************************
/* App HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRAppGetName
 * @details Gets the <a>FS_ByteString</a> corresponding to the application's name, which is the name
    * of the file containing the Foxit Reader application.
 * @param[out]  outName The string buffer used to receive the name of application. It
    * will be filled by reader.
 * @return   void
 * @note The application name will be "Foxit PhantomPDF" or "Foxit Reader".
 * @see FRAppGetTitle
 */
INTERFACE(void, FRAppGetName, (FS_ByteString* outName))

/**
 * @brief FRAppGetVersion
 * @details Gets the <a>FS_WideString</a> corresponding to the application's version. The Format of version
    * information is XX.XX.XX.XX(major number.minor number.maintainence number.build number).
 * @param[out]  outVersion The string buffer used to receive the version information of application.
    * It will be filled by reader.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppGetVersion, (FS_WideString* outVersion))

/**
 * @brief FRAppGetAppTitle
 * @details Gets the <a>FS_WideString</a> corresponding to the application's title.
 * @param[out]  outTitle The string buffer used to receive the title of application.
    * It will be filled by reader.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note The user might have changed this, so do not use it to determine what the application is.
    * Use FRAppGetName instead.
 * @see FRAppGetName
 */
INTERFACE(FS_BOOL, FRAppGetAppTitle, (FS_WideString* outTitle))

/**
 * @brief FRAppGetAppDataPath
 * @details Gets the execution file path of current running reader.
 * @param[out]  outAppPath The string buffer used to receive the path which Foxit Reader used to
    * store some application's data. It will be filled automaticly by reader.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppGetAppDataPath, (FS_WideString* outAppPath))

/**
 * @brief FRAppCanQuit
 * @details Gets the permission to decide whether you can quit.
 * @return   <a>TRUE</a> if foxit reader can quit, <a>FALSE</a> if cannot. The default version of the routine
	* always returns <a>TRUE</a>.
 * @note 
 * @Deprecated    Internal use. This function is deprecated.
 */
INTERFACE(FS_BOOL, FRAppCanQuit, (void))

/**
 * @brief FRAppCountToolbars
 * @details Gets the number of toolbars, including the flyout toolbars.
 * @return   The number of toolbar.
 * @note 
 * @see FRAppGetToolBar
	
 * @Deprecated    Internal use. This function is deprecated.
 */
INTERFACE(FS_INT32, FRAppCountToolbars, (void))

/**
 * @brief FRAppGetToolBar
 * @details Gets the specified toolbar.
 * @param[in]  index The index of toolbar to obtain. The index range is 0 to (<a>FRAppCountToolbars</a>()-1).
 * @param[in]  pParentWnd A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   The <a>FR_ToolBar</a> object.
 * @note 
 * @see FRAppCountToolbars
 * @see FRAppGetToolBarByName
	
 * @Deprecated    Internal use. This function is deprecated.
 */
INTERFACE(FR_ToolBar, FRAppGetToolBar, (FS_INT32 index,  void* pParentWnd))

/**
 * @brief FRAppGetToolBarByName
 * @details Gets toolbar created with the specified name, All toolbars(including flyout toolbar) can be obtained by the method.
 * @param[in]  csName The name of the toolbar.
 * @param[in]  pParentWnd A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   The <a>FR_ToolBar</a>, or <a>NULL</a> if no <a>FR_ToolBar</a> was found with the specified name.
 * @note 
 * @see FRToolBarSetName
	
 * @Deprecated    Internal use. This function is deprecated.
 */
INTERFACE(FR_ToolBar, FRAppGetToolBarByName, (FS_LPCSTR csName,  void* pParentWnd))

/**
 * @brief FRAppGetMenuBar
 * @details Gets Foxit Reader's menu bar.
 * @return   The menu bar.
 * @note 
 * @Deprecated    Internal use. This function is deprecated.
 */
INTERFACE(FR_MenuBar, FRAppGetMenuBar, (void))

/**
 * @brief FRAppShowMenuBar
 * @details Shows/Hides menu bar.
 * @param[in]  bShow If <a>TRUE</a>, the menu bar will be show, <a>FALSE</a> to hide.
 * @return   void
 * @note 
 * @Deprecated    Internal use. This function is deprecated.
 */
INTERFACE(void, FRAppShowMenuBar, (FS_BOOL bShow))

/**
 * @brief FRAppRegisterTool
 * @details Registers a tool into the Foxit Reader.
 * @param[in]  tool The <a>FR_Tool</a> object containing the tool's callbacks. This object
	* must not be freed after calling <a>FRAppRegisterTool</a>(), but must be remained.
 * @return   
 * @note 
 * @see FRToolNew
 * @see FRAppSetActiveTool
 */
INTERFACE(void, FRAppRegisterTool, (FR_Tool tool))

/**
 * @brief FRAppGetToolByName
 * @details Gets the <a>FR_Tool</a> object that was registered under specified name.
 * @param[in]  csName The tool name.
 * @return   The tool that was registered under name, or <a>NULL</a> if no match was found.
 * @note 
 * @see FRAppGetToolByIndex
 */
INTERFACE(FR_Tool, FRAppGetToolByName, (FS_LPCSTR csName))

/**
 * @brief FRAppCountTools
 * @details Gets the number of registered <a>FR_Tool</a> object.
 * @return   The number of tools.(Including built-in tools)
 * @note 
 * @see FRAppGetToolByIndex
 */
INTERFACE(FS_INT32, FRAppCountTools, (void))

/**
 * @brief FRAppGetToolByIndex
 * @details Gets the specified tool.
 * @param[in]  index The index of tool to obtain. The index range is 0 to (<a>FRAppCountTools</a>()-1).
 * @return   The specified tool.
 * @note 
 * @see FRAppGetToolByName
 * @see FRAppCountTools
 */
INTERFACE(FR_Tool, FRAppGetToolByIndex, (FS_INT32 index))

/**
 * @brief FRAppSetActiveTool
 * @details Sets the active tool. It does nothing if the specified tool is not currently enabled, The
	* <a>FRToolIsEnabled</a>() callback in <a>FR_ToolCallbacksRec</a> structure determines whether a tool is
	* enabled. If this callback is <a>NULL</a>, the tool is always enabled.
 * @param[in]  tool The tool to set as the active tool.
 * @param[in]  persistent A flag that indicates a preference as to whether the tool stays active after
	* it is used. <a>TRUE</a> is a hint that the tool should.if possible, stay active for an arbitrary number 
	* of operations (whatever that happens to be) rather than doing a one shot operation and restoring the 
	* prior active tool.
	*
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRAppRegisterTool
 * @see FRAppGetActiveTool
 */
INTERFACE(FS_BOOL, FRAppSetActiveTool, (FR_Tool tool,  FS_BOOL persistent))

/**
 * @brief FRAppGetActiveTool
 * @details Gets the active tool from the application.
 * @return   The active tool.
 * @note 
 * @see FRAppSetActiveTool
 * @see FRAppRegisterTool
 */
INTERFACE(FR_Tool, FRAppGetActiveTool, (void))

/**
 * @brief FRAppRegisterPreferencePageHandler
 * @details Registers the event notification to preference dialog.
 * @param[in]  preferPageCallbacks The callback set. Reader will call a corresponding callback when the 
	* preference dialog is to be show or to be destroy.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note You must also call <a>FRAppAddPreferencePage</a>() in the <a>FRPrefPageOnCreate</a>() callback to
	* add a preference page to Reader preference dialog.
	*
 * @see FRAppAddPreferencePage
 * @see FRAppShowPreferenceDlg
 */
INTERFACE(FS_BOOL, FRAppRegisterPreferencePageHandler, (FR_PreferPageCallbacks preferPageCallbacks))

/**
 * @brief FRAppAddPreferencePage
 * @details Adds a preference page into Reader preference dialog.
 * @param[in]  parent The parent window.
 * @param[in]  preferPage A platform-specific object.	In windows, it is a HWND handler.
 * @param[in]  title The title of the preference page. It will be displayed on the list box in
	* the left of preference dialog.
 * @return   <a>TRUE</a> for success, or <a>FALSE</a> if the preference page has existed or the title of the page
	* has been used.
 * @note You should call this method in the implementation of <a>FRPrefPageOnCreate</a>() callback.
 * @see FRAppRegisterPreferencePageHandler
 */
INTERFACE(FS_BOOL, FRAppAddPreferencePage, (HWND parent,  HWND preferPage,  FS_LPCWSTR title))

/**
 * @brief FRAppRegisterDocPropertyPageHandler
 * @details Registers the event notification to document properties dialog.
 * @param[in]  docProperPageCallbacks The callback set. Reader will call a corresponding callback when the 
	* document properties dialog is to be show or to be destroy.
 * @return   <a>TRUE</a> for success, otherwise <a>FALSE</a>.
 * @note You must also call <a>FRAppAddDocPropertyPage</a>() in the <a>FRDocPropertyPageOnCreate</a>() callback to
	* add a property page to Reader document properties dialog.
	* The interface has been deprecated.
 * @see FRAppAddDocPropertyPage
 */
INTERFACE(FS_BOOL, FRAppRegisterDocPropertyPageHandler, (FR_DocPropertypageCallbacks docProperPageCallbacks))

/**
 * @brief FRAppAddDocPropertyPage
 * @details Adds a document property page into Reader document properties dialog.
 * @param[in]  parent The parent window.
 * @param[in]  propertyPage A platform-specific object.	In windows, it is a <Italic>HWND</Italic> handler.
 * @param[in]  title The title of the document property page. It will be displayed on the 
	* tabsheet in the top of document properties dialog.
 * @return   <a>TRUE</a> for success, or <a>FALSE</a> if the property page has existed or the title of the page
	* has been used.
 * @note You should call this method in the implementation of <a>FRDocPropertyPageOnCreate</a>() callback.
 * @see FRAppRegisterDocPropertyPageHandler
 */
INTERFACE(FS_BOOL, FRAppAddDocPropertyPage, (HWND parent,  HWND propertyPage,  FS_LPCWSTR title))

/**
 * @brief FRAppRegisterNavPanelView
 * @details Registers a navigation panel view into the Foxit Reader.
 * @param[in]  panelViewCallbacks A panel page callback set. When the navigation panel occurs a event, reader will
	* call a corresponding callback to respond.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @Deprecated    Internal used. Repalce by <a>FRAppRegisterPanelToolHandler</a>
 */
INTERFACE(FS_BOOL, FRAppRegisterNavPanelView, (FR_PanelViewCallbacks panelViewCallbacks))

/**
 * @brief FRAppRegisterAppEventHandler
 * @details Registers a user-supplied procedure set to call when some application level event occurs.
 * @param[in]  appEventCallbacks The callback set. Reader will call a corresponding callback when the app event occurs.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegisterAppEventHandler, (FR_AppEventCallbacks appEventCallbacks))

/**
 * @brief FRAppCountDocsOfPDDoc
 * @details Gets the number of document views. This method just only count the document view that for 
	* displaying PDF file type, does not count other document view for displaying other format file.
 * @return   The number of document views that is used to display PDF file type.
 * @note 
 * @see FRAppGetDocOfPDDoc
 */
INTERFACE(FS_INT32, FRAppCountDocsOfPDDoc, (void))

/**
 * @brief FRAppGetDocOfPDDoc
 * @details Gets the document view by specified index.
 * @param[in]  index The index of specified document view with a <a>FPD_Document</a> object.
	* The range is 0 to (CountDocsOfPDDoc()-1);
 * @return   A document window.
 * @note This method just return the document window which for displaying PDF file type, ignore other 
	* format file window.
 * @see FRAppCountDocsOfPDDoc
 * @see FRAppGetActiveDocOfPDDoc
 */
INTERFACE(FR_Document, FRAppGetDocOfPDDoc, (FS_INT32 index))

/**
 * @brief FRAppGetActiveDocOfPDDoc
 * @details Gets the top-most document window which for displaying PDF file type.
 * @return   The top-most document window which is used for displaying PDF file type, or <a>NULL</a> if
	* no documents are open. <a>NULL</a> is also returned while the top-most document window is not displaying
	* PDF file type and while a document is being opened.
 * @note 
 * @see FRAppGetDocOfPDDoc
 * @see FRAppSetActiveDocOfPDDoc
 */
INTERFACE(FR_Document, FRAppGetActiveDocOfPDDoc, ())

/**
 * @brief FRAppSetActiveDocOfPDDoc
 * @details Sets a document view to top-most.
 * @param[in]  doc The <a>FR_Document</a> object.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRAppGetActiveDocOfPDDoc
 * @see FRAppCountDocsOfPDDoc
 * @see FRAppGetDocOfPDDoc
 */
INTERFACE(FS_BOOL, FRAppSetActiveDocOfPDDoc, (FR_Document doc))

/**
 * @brief FRAppRegisterDocHandlerOfPDDoc
 * @details Registers a user-supplied event handler to document window.
 * @param[in]  docEventCallbacks The callback set. Reader will call a corresponding callback when the doc event occurs.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note The callbacks of FR Doc Event Handler just be called while the document window is displaying
	* PDF file type.
 */
INTERFACE(FS_BOOL, FRAppRegisterDocHandlerOfPDDoc, (FR_DocEventCallbacks docEventCallbacks))

/**
 * @brief FRAppIsFullScreen
 * @details Tests whether the application is running in full-screen mode.
 * @return   <a>TRUE</a> if the application is currently in full-screen mode, otherwise not.
 * @note 
 * @see FRAppShowFullScreen
 * @see FRAppEndFullScreen
 */
INTERFACE(FS_BOOL, FRAppIsFullScreen, (void))

/**
 * @brief FRAppShowFullScreen
 * @details Begins full-screen mode. In full-screen mode, all window borders, the menu bar, and the 
	* toolbar are hidden. All regions of the screen outside of the page view boundary are painted by specified
	* color.
	* <a>FRAppShowFullScreen</a>() is ignored if the application is already in full-screen mode, or if there are no
	* currently open documents.
 * @return   <a>TRUE</a> if the application enters full-screen mode; <a>FALSE</a> if it is already in 
	* full-screen mode or the user clicks the cancel button from dialog box describing how to exit the
	* full-screen mode.
 * @note 
 * @see FRAppEndFullScreen
 */
INTERFACE(FS_BOOL, FRAppShowFullScreen, (void))

/**
 * @brief FRAppEndFullScreen
 * @details Ends full-screen mode. It does nothing if the the application is not running in full-screen mode.
 * @return   <a>TRUE</a> if the application exit full-screen mode, otherwise not.
 * @note 
 * @see FRAppShowFullScreen
 */
INTERFACE(FS_BOOL, FRAppEndFullScreen, (void))

/**
 * @brief FRAppGetMousePos
 * @details Gets the mouse position. The mouse position is specified in screen coordinates.
 * @return   The <a>FS_DevicePoint</a> specified in screen coordinates.
 * @note 
 */
INTERFACE(FS_DevicePoint, FRAppGetMousePos, (void))

/**
 * @brief FRAppModalWindowIsOpen
 * @details A client should use this method to determine whether a modal window is open. 
	* There is a large (and ill-defined) group of actions that are illegal while a modal window is open, although 
	* these actions are not programmatically prevented by the Foxit Reader Viewer. While a modal dialog box is  
	* open, a client must not open documents, change pages, change views, close documents, change tools, or do 
	* anything that might disrupt the user or Foxit Reader viewer.
 * @return   <a>TRUE</a> if a modal window is open, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppModalWindowIsOpen, (void))

/**
 * @brief FRAppRegisterSecurityHandler
 * @details Registers a security handler. Invoked this interface to process the PDF documents that 
	* are encrypted by customer security handler.
 * @param[in]  name The name of the security handler.
 * @param[in]  callbacks The structure containing the security handler callback functions.
 * @return   void
 * @note 
 * @see FRAppUnRegisterSecurityHandler
 */
INTERFACE(void, FRAppRegisterSecurityHandler, (FS_LPCSTR name,  FR_SecurityCallbacks callbacks))

/**
 * @brief FRAppUnRegisterSecurityHandler
 * @details Unregisters a security handler.
 * @param[in]  name The name of the security handler.
 * @return   void
 * @note 
 * @see FRAppRegisterSecurityHandler
 */
INTERFACE(void, FRAppUnRegisterSecurityHandler, (FS_LPCSTR name))

/**
 * @brief FRAppGetPassPhrase
 * @details This interface is invoked by the plug-in to confirm that the host environment is Foxit Reader and is legal.
	*          The following steps show the procedure:<br>
	*			<ul>
	*			<li>1. Plug-in generates a random string of 128 byte length and encrypts it using the public key. </li>
	*			<li>2. Plug-in allocates one buffer of 128 bytes and calls <a>FRAppGetPassPhrase</a>() and passes the encrypted string.</li>
	*			<li>3. Foxit reader will decrypt the encrypted text using the private key and copy it to the buffer <param>pstrPlainText</param>.</li>
	*			<li>4. Plug-in matches the plain text against what it had generated. </li>
	*			</ul>
 * @param[in]  pstrEncryptedText An encrypted random string of 128 byte.
 * @param[out]  ppstrPlainText It receives the plain text from Foxit Reader.
 * @return   void
 * @note This function is deprecated.
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppGetPassphrase, (FS_LPCSTR pstrEncryptedText,  FS_LPSTR* ppstrPlainText))

/**
 * @brief FRAppRegisterContentProvider
 * @details Registers a content provider so that the plug-in can process the protected document and provide decrypted
	* document data.
 * @param[in]  contentProviderCallbacks The content provider callbacks.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppRegisterContentProvider, (FR_ContentProviderCallbacks contentProviderCallbacks))

/**
 * @brief FRAppGetMainFrameWnd
 * @details Gets the main frame window of Foxit Reader.
 * @return   A <Italic>HWND</Italic> object for windows.
 * @note 
 */
INTERFACE(HWND, FRAppGetMainFrameWnd, (void))

/**
 * @brief FRAppAddUndoRedoItem
 * @details Adds a undo-redo item to the specified document.
 * @param[in]  lpwDescr The input description of the undo-redo item.
 * @param[in]  frDoc The specified document.
 * @param[in]  bEdit Whether the current operation is editing, for example, you add a typewriter and enter characters.
 * @param[in]  callbacks The user-supplied callbacks for implementing undo-redo.
 * @return   void
 * @note 
 * @see FRAppUndoRedoIsEditing
 * @see FRAppUndoRedoBeginEdit
 * @see FRAppUndoRedoEndEdit
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppAddUndoRedoItem, (FS_LPCWSTR lpwDescr,  FR_Document frDoc,  FS_BOOL bEdit,  FR_UndoRedoCallbacks callbacks))

/**
 * @brief FRAppRegisterPageHandlerOfPDDoc
 * @details Registers a page-level event callback set.
 * @param[in]  callbacks The callback set. Reader will call a corresponding callback when the page event occurs.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppRegisterPageHandlerOfPDDoc, (FR_PageEventCallbacks callbacks))

/**
 * @brief FRAppRegisterForContextMenuAddition
 * @details Registers a user-supplied procedure to call after a context menu has been created but before it is shown to 
	* the user. The callback can add menu items to or remove menu items from the menu.
 * @param[in]  menuName The name of the context menu to modify. Its names can be one of the 
	* following:<br>
	* <ul><li>Name - Description</li>
	* <li>Page - The standard context menu for an FR_PageView.</li>
	* <li>Select - The context menu for selected text.</li>
	* <li>Snapshot - The context menu for snapshot of FR_PageView.</li>
 * @param[in]  proc The user-supplied procedure to call.
 * @param[in]  clientData A pointer to user-supplied data to pass to the procedure each time it 
	* is called.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note It only available in Windows.
 */
INTERFACE(FS_BOOL, FRAppRegisterForContextMenuAddition, (FS_LPCSTR csName,  FRContextMenuPopUpProc proc,  void* pClientData))

/**
 * @brief FRAppRegisterSelectionHandler
 * @details Registers a new selection handler. Selection handlers allow the selection of items 
	* other than those that can be selected in the as-shipped Foxit viewer. For example, a selection handler 
	* could allow a user to select a sampled image.
    * This method can be used to replace an existing selection handler that handles the same selection type.
 * @param[in]  callbacks A structure containing the selection handler's callback functions. This structure 
    * must not be freed after calling <a>FRAppRegisterSelectionHandler</a>().
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note Call FRAppUnRegisterSelectionHandler to unregister the selection handler and release the memory.
 */
INTERFACE(FS_BOOL, FRAppRegisterSelectionHandler, (FR_SelectionCallbacks callbacks))

/**
 * @brief FRAppUnRegisterSelectionHandler
 * @details Unregisters the selection handler and releases the memory.
 * @param[in]  callbacks A structure containing the selection handler's callback functions.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppUnRegisterSelectionHandler, (FR_SelectionCallbacks callbacks))

/**
 * @brief FRAppRegisterCaptureHandler
 * @details Registers the capture handler.
 * @param[in]  callbacks A structure containing the capture handler's callback functions.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppRegisterCaptureHandler, (FR_CaptureCallbacks callbacks))

/**
 * @brief FRAppUnRegisterCaptureHandler
 * @details Unregisters the capture handler and releases the memory.
 * @param[in]  callbacks A structure containing the capture handler's callback functions.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppUnRegisterCaptureHandler, (FR_CaptureCallbacks callbacks))

/**
 * @brief FRAppRegistryGetProfilePath
 * @details Gets the registry's profile path of the Foxit Reader.
 * @param[out]  outProfilePath It receives the registry's profile path of the Foxit Reader.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppRegistryGetProfilePath, (FS_WideString* outProfilePath))

/**
 * @brief FRAppRegistryWriteInt
 * @details Write int value to the specified registry. If you want to set the value in registry like 
	* <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	* <param>lpszSection</param> can be set as <Italic>"Create Link"</Italic>.
	* If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	* <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @param[in]  nValue The input int value.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryWriteInt, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry,  FS_INT32 nValue))

/**
 * @brief FRAppRegistryWriteBinary
 * @details Write binary value to the specified registry. If you want to set the value in registry like 
	* <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	* <param>lpszSection</param> can be set as <Italic>"Create Link"</Italic>.
	* If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	* <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @param[in]  pData The input binary data.
 * @param[in]  nValue The size of the binary data.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryWriteBinary, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry,  FS_LPBYTE pData,  unsigned int nBytes))

/**
 * @brief FRAppRegistryWriteString
 * @details Write string to the specified registry. If you want to set the value in registry like 
	* <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	* <param>lpszSectio</param>n can be set as <Italic>"Create Link"</Italic>.
	* If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	* <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @param[in]  lpszValue The input string.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryWriteString, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry,  FS_LPCWSTR lpszValue))

/**
 * @brief FRAppRegistryGetInt
 * @details Gets the int value in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @return   The int value in the specified section.
 * @note 
 */
INTERFACE(UINT, FRAppRegistryGetInt, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry))

/**
 * @brief FRAppRegistryGetBinary
 * @details Gets the binary value in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @param[out]  ppData It receives the binary data.
 * @param[out]  pBytes It receives the size of the binary data.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryGetBinary, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry,  unsigned char** ppData,  unsigned int* pBytes))

/**
 * @brief FRAppRegistryGetString
 * @details Gets the string value in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @param[out]  outString It receives the string.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryGetString, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry,  FS_WideString* outString))

/**
 * @brief FRAppRegistryGetEntryCount
 * @details Gets the entry count in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @return   The entry count in the specified section.
 * @note 
 */
INTERFACE(FS_INT32, FRAppRegistryGetEntryCount, (FS_LPCWSTR lpszSection))

/**
 * @brief FRAppRegistryGetEntryName
 * @details Gets the entry name in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  nIndex The specified index.
 * @param[out]  outName It receives the entry name.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryGetEntryName, (FS_LPCWSTR lpszSection,  FS_INT32 nIndex,  FS_WideString* outName))

/**
 * @brief FRAppRegistryRemoveSection
 * @details Removes the specified section.
 * @param[in]  lpszSection The input registry section.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppRegistryRemoveSection, (FS_LPCWSTR lpszSection))

/**
 * @brief FRAppRegistryRemoveEntry
 * @details Removes the specified entry.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppRegistryRemoveEntry, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry))

/**
 * @brief FRAppGetGEModule
 * @details Gets the app GE module.
 * @return   The app GE module.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void*, FRAppGetGEModule, (void))

/**
 * @brief FRAppGetModuleMgr
 * @details Gets the app module manager.
 * @return   The app module manager.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void*, FRAppGetModuleMgr, (void))

/**
 * @brief FRAppCreateAnEmptyFrameWnd
 * @details Creates a new frame window.
 * @param[in]  title The title of the frame which will be created.
 * @param[in]  bMakeVisible A flag indicate whether to show the frame.
 * @param[in]  notify The notifies for new window.
 * @return   The handler of the newly created frame.
 * @note 
 */
INTERFACE(HWND, FRAppCreateAnEmptyFrameWnd, (FS_WideString title,  FS_BOOL bMakeVisible,  FR_EmptyFramWndNotifies notify))

/**
 * @brief FRAppIsRunEmbedded
 * @details Tests whether the Foxit Reader is running embedded or not.
 * @return   <a>TRUE</a> for running embedded, otherwise <a>FALSE</a>.
 * @note Only available in Windows.
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsRunEmbedded, (void))

/**
 * @brief FRAppRegisterExtraPrintInfoProvider
 * @details Register the printing notifies.
 * @param[in]  callbacks The callbacks which will be broadcast.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRAppRegisterExtraPrintInfoProvider, (FR_ExtraPrintInfoProviderCallbacks callbacks))

/**
 * @brief FRAppIsRibbonMode
 * @details Tests whether current toolbar mode is tabbed mode.
 * @return   <a>TRUE</a> if current toolbar mode is tabbed mode, otherwise <a>FALSE</a>.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsRibbonMode, (void))

/**
 * @brief FRAppGetStartMenuOfTabbedToobarMode
 * @details Gets the start menu which is in tabbed toolbar mode.
 * @return   A <a>FR_Menu</a> object indicates the start menu of tabbed toolbar mode. <a>NULL</a> if
	*				current toolbar mode is not tabbed mode.
 * @note If a <a>FR_Menu</a> is added into a exist menu in commonent toolbar mode, and need add into the start menu,
	*		call <a>FRAppIsRibbonMode</a>() first, then call <a>FRAppGetStartMenuOfTabbedToobarMode</a>() to get the start
	*		menu and add the menu item to start menu again.
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Menu, FRAppGetStartMenuOfTabbedToobarMode, (void))

/**
 * @brief FRAppRegisterTaskPaneView
 * @details Registers callback set for a task pane view.
 * @param[in]  callbacks The callback set for a task pane view.
 * @return   <a>TRUE</a> for success, otherwise <a>FALSE</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppShowTaskPane
 */
INTERFACE(FS_BOOL, FRAppRegisterTaskPaneView, (FR_TaskPaneViewCallbacks paneView))

/**
 * @brief FRAppShowTaskPane
 * @details Shows or hidden a task panel view.
 * @param[in]  nameOfPaneView The name of the pane view which would be shown or hidden.
 * @param[in]  bShow A flag indicates whether the pane view specified by <param>nameOfPaneView</param> should be
	* shown or hidden.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterTaskPaneView
 */
INTERFACE(void, FRAppShowTaskPane, (FS_LPSTR nameOfPaneView,  FS_BOOL bShow))

/**
 * @brief FRAppGetTaskPaneWndHandleByDoc
 * @details Gets the window handle of the task pane.
 * @param[in]  frDoc The document associated with the task pane.
 * @return   The window handle of the task pane.
 * @note Only available in Windows
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRAppRegisterTaskPaneView
 */
INTERFACE(FS_HWND, FRAppGetTaskPaneWndHandleByDoc, (FR_Document frDoc))

/**
 * @brief FRAppCommandLineHasSwitch
 * @details Checks whether the <param>pwszSwitch</param> exists.
 * @param[in]  pwszSwitch The switch name to be checked.
 * @return   <a>TRUE</a> if the switch exists, otherwise <a>FALSE</a>
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppOnRunCommandLine
 */
INTERFACE(FS_BOOL, FRAppCommandLineHasSwitch, (FS_LPCWSTR pwszSwitch))

/**
 * @brief FRAppCommandLineGetSafeArgument
 * @details Gets the specified argument. If the specified argument is not existing, the default value will be returned.
 * @param[in]  pwszSwitch The switch name to which the argument belongs.
 * @param[in]  iIndex The index of the arguments.
 * @param[in]  pwszDefault The default value of argument. If the specified argument is not existing, the default value will be returned.
 * @param[out]  outArgument It receives the argument.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAppCommandLineGetSafeArgument, (FS_LPCWSTR pwszSwitch,  FS_INT32 iIndex,  FS_LPCWSTR pwszDefault,  FS_WideString* outArgument))

/**
 * @brief FRAppCommandLineGetArgument
 * @details Gets the specified argument.
 * @param[in]  pwszSwitch The switch name to which the argument belongs.
 * @param[in]  iIndex The index of the arguments.
 * @param[out]  outArgument It receives the argument.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAppCommandLineGetArgument, (FS_LPCWSTR pwszSwitch,  FS_INT32 iIndex,  FS_WideString* outArgument))

/**
 * @brief FRAppCommandLineGetArgumentCount
 * @details Gets the count of the argument.
 * @param[in]  pwszSwitch The switch name to which the argument belongs.
 * @return   The count of the argument.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_INT32, FRAppCommandLineGetArgumentCount, (FS_LPCWSTR pwszSwitch))

/**
 * @brief FRAppRegisterWinMSGHandler
 * @details Registers callback set for a windows MSG handler.
 * @param[in]  callbacks The callback set for a windows MSG handler.
 * @return   <a>TRUE</a> for success, otherwise <a>FALSE</a>.
 * @note Only available in Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppRegisterWinMSGHandler, (FR_WinMSGCallbacks callbacks))

/**
 * @brief FRAppGetRecentFileList
 * @details Gets the recent opened file list.
 * @param[out]  pArrFileList It receives the recent opened file list.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAppGetRecentFileList, (FS_WideStringArray* pArrFileList))

/**
 * @brief FRAppAddFileToRecentFileList
 * @details Adds the recent opened file path to the list.
 * @param[in]  lpszPathName The recent opened file path.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAppAddFileToRecentFileList, (FS_LPCWSTR lpszPathName))

/**
 * @brief FRAppClearRecentFileList
 * @details Clears the recent opened file list.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAppClearRecentFileList, ())

/**
 * @brief FRAppRegisterSecurityMethod
 * @details Registers the security method that you can manage your security method.
 * @param[in]  cllbcks The callback set for security method.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
	* Notes: It has been deprecated, suggest use FRInternalSecurityHandlerRegisterSecurityMethod from security plugin.
 */
INTERFACE(FS_BOOL, FRAppRegisterSecurityMethod, (FR_SecurityMethodCallbacks cllbcks))

/**
 * @brief FRAppPopDocPropertyPage
 * @details Pops up the doc property pages.
 * @param[in]  PageShowName The property page you want to display.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterDocPropertyPageHandler
 */
INTERFACE(void, FRAppPopDocPropertyPage, (FS_LPCWSTR PageShowName))

/**
 * @brief FRAppCountDocPropertyPages
 * @details Counts the doc property pages.
 * @param[in]  hParent The parent window.
 * @return   The count of doc property pages.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterDocPropertyPageHandler
 */
INTERFACE(FS_INT32, FRAppCountDocPropertyPages, (HWND hParent))

/**
 * @brief FRAppCheckModuleLicense
 * @details Checks whether you have license to the module.
 * @param[in]  lpwszModuleName The input module name.
 * @return   Returns <a>TRUE</a> if you have license to the module.
 * @note This is an internal interface.
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppCheckModuleLicense, (FS_LPCWSTR lpwszModuleName))

/**
 * @brief FRAppRegisterOwnerFileType
 * @details Adds a file type to Foxit Reader. You can control the process of owner file type, 
	* such as opening, saving, sending email and so on.
 * @param[in]  callbacks The callback set for the owner file type handler.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppRegisterOwnerFileType, (FR_OwnerFileTypeHandlerCallbacks callbacks))

/**
 * @brief FRAppRegistryGetKeyCounts
 * @details Gets the counts of key for the specified section.
 * @param[in]  lpszSection The input registry section.
 * @return   The counts of key for the specified section.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegistryGetProfilePath
 */
INTERFACE(FS_INT32, FRAppRegistryGetKeyCounts, (FS_LPCWSTR lpszSection))

/**
 * @brief FRAppRegistryGetKeyName
 * @details Gets the key name in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  nIndex The specified index.
 * @param[out]  outName It receives the key name.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegistryGetProfilePath
 */
INTERFACE(FS_BOOL, FRAppRegistryGetKeyName, (FS_LPCWSTR lpszSection,  FS_INT32 nIndex,  FS_WideString* outName))

/**
 * @brief FRAppGetRibbonBar
 * @details Gets Foxit Reader's ribbon bar.
 * @param[in]  pParentWnd A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   The ribbon bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Repalce by FRAppGetRibbonBar2
 */
INTERFACE(FR_RibbonBar, FRAppGetRibbonBar, (void* pParentWnd))

/**
 * @brief FRAppGetRibbonBarBackGroundColor
 * @details Gets the back ground color of ribbon bar.
 * @return   The back ground color of ribbon bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_COLORREF, FRAppGetRibbonBarBackGroundColor, (void))

/**
 * @brief FRAppGetRibbonBarBtnBackGroundColor
 * @details Gets the back ground color of ribbon bar button.
 * @param[in]  bIsHighlighted Whether the button is highlighted.
 * @param[in]  bIsPressed Whether the button is pressed.
 * @return   The back ground color of ribbon bar button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_COLORREF, FRAppGetRibbonBarBtnBackGroundColor, (FS_BOOL bIsHighlighted,  FS_BOOL bIsPressed))

/**
 * @brief FRAppLoadLibrary
 * @details Load the library.
 * @param[in]  lpwsFileName Specifies the file name of library.
 * @param[in]  nDirectoryType The directory type.
 * @return   The library handle.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void*, FRAppLoadLibrary, (FS_LPCWSTR lpwsFileName,  FRDirectoryType nDirectoryType))

/**
 * @brief FRAppIsCurDocShowInBrowser
 * @details Tests whether the current document is opened in browser or not.
 * @return   <a>TRUE</a> for running in browser, otherwise <a>FALSE</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsCurDocShowInBrowser, ())

/**
 * @brief FRAppRemoveFileFromRecentFileList
 * @details Removes the recent opened file path from the list.
 * @param[in]  nIndex The index of recent opened file path to be removed.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppGetRecentFileList
 * @see FRAppAddFileToRecentFileList
 * @see FRAppClearRecentFileList
 */
INTERFACE(void, FRAppRemoveFileFromRecentFileList, (FS_INT32 nIndex))

/**
 * @brief FRAppCreateCustomRecentFileList
 * @details Creates a custom recent file list.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  lpwsFileExt The extension of files that will be added to the recent file list.
 * @param[in]  pItemBitmap The icon that will be displayed in front of the recent file list label.
 * @param[in]  lpwsLabel The input label of recent file list.
 * @param[in]  nMaxSize The input max size of recent file list item.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppCreateCustomRecentFileList, (FS_LPCSTR lpsRecentFileListName,  FS_LPCWSTR lpwsFileExt,  FS_DIBitmap pItemBitmap,  FS_LPCWSTR lpwsLabel,  FS_INT32 nMaxSize))

/**
 * @brief FRAppRemoveFileFromCustomRecentFileList
 * @details Removes the recent file path from the specified recent file list.
 * @param[in]  lpsRecentFileListName The name that specifies the custom recent file list from which the recent file path will be removed.
 * @param[in]  lpwsFilePath The recent file path that will be removed.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppCreateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppRemoveFileFromCustomRecentFileList, (FS_LPCSTR lpsRecentFileListName,  FS_LPCWSTR lpwsFilePath))

/**
 * @brief FRAppAddFileToCustomRecentFileList
 * @details Adds the recent file to the custom recent file list.
 * @param[in]  lpsRecentFileListName The name that specifies the custom recent file list which the recent file path will be added to.
 * @param[in]  lpwsFilePath The recent file path that will be added.
 * @param[in]  lpwsFileTitle Instead of the file path, the title will be displayed in the recent file list.
 * @param[in]  lpwsFileTooltip The tooltip of the recent file.
 * @param[in]  exeProc When the recent file item is clicked, the callback will be invoked, unless you set it as NULL.
 * @param[in]  clientData The client data that will be passed to the callback.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppCreateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppAddFileToCustomRecentFileList, (FS_LPCSTR lpsRecentFileListName,  FS_LPCWSTR lpwsFilePath,  FS_LPCWSTR lpwsFileTitle,  FS_LPCWSTR lpwsFileTooltip,  FRAppCustomRecentFileExecuteProc exeProc,  void* clientData))

/**
 * @brief FRAppClearCustomRecentFileList
 * @details Clears the recent files from the recent file list.
 * @param[in]  csRecentListName The name that specifies the custom recent file list whose recent files will be cleared.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppCreateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppClearCustomRecentFileList, (FS_LPCSTR lpsRecentFileListName))

/**
 * @brief FRAppRegisterMousePtHandler
 * @details Registers the mouse point handler.
 * @param[in]  callbacks A structure containing the mouse point handler's callback functions.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRToolSetAssociatedMousePtHandlerType
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppRegisterMousePtHandler, (FR_MousePtCallbacks callbacks))

/**
 * @brief FRAppUnRegisterMousePtHandler
 * @details Unregisters the mouse point handler and releases the memory.
 * @param[in]  callbacks A structure containing the mouse point handler's callback functions.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppUnRegisterMousePtHandler, (FR_MousePtCallbacks callbacks))

/**
 * @brief FRAppIsLicenseValidOrInTrial
 * @details Checks whether the license is valid or is in trial.
 * @return   Checks whether the license is valid or is in trial.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRAppIsLicenseValidOrInTrial, ())

/**
 * @brief FRAppShowPreferenceDlg
 * @details Shows the preference dialog.
 * @param[in]  lpwsTabTitle 
 * @return   The result when user clicks ok button or cancel button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterPreferencePageHandler
 */
INTERFACE(FS_INT32, FRAppShowPreferenceDlg, (FS_LPCWSTR lpwsTabTitle))

/**
 * @brief FRAppUndoRedoIsEditing
 * @details Checks whether the document is being edited.
 * @param[in]  frDoc The specified document.
 * @return   <a>TRUE</a> means the document is being edited, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppAddUndoRedoItem
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppUndoRedoIsEditing, (FR_Document frDoc))

/**
 * @brief FRAppUndoRedoBeginEdit
 * @details When you begin to edit detail content, such as text, and you don't want to save all the editing operation to save memory, 
	* you can invoke this interface. We call it the editing mode undo-redo control.
 * @param[in]  frDoc The specified document.
 * @param[in]  pExitEditProc The callback will be invoked when you exit the editing mode. Then you can release the data.
 * @param[in]  clientData The client data passed to the exiting callback.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppAddUndoRedoItem
 * @see FRAppUndoRedoEndEdit
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppUndoRedoBeginEdit, (FR_Document frDoc,  FRAppUndoRedoExitEditProc pExitEditProc,  void* clientData))

/**
 * @brief FRAppUndoRedoEndEdit
 * @details When you exit the editing mode, invoke this interface to exit the editing mode undo-redo control.
 * @param[in]  frDoc The specified document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppAddUndoRedoItem
 * @see FRAppUndoRedoBeginEdit
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppUndoRedoEndEdit, (FR_Document frDoc))

/**
 * @brief FRAppRegisterWndProvider
 * @details Registers a window provider to create a window above the document view. 
	* There are already some windows above the document view, such as PDF view, text view, ruler view.
 * @param[in]  callbacks The input callbacks used to control the window, it tells you when to create the window handle, when to show the window, when to scroll the window, and so on.
 * @return   The returned value is reserved.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRDocSetCurrentWndProvider
 * @see FRDocGetCurrentWndProvider
 * @see FRAppUnRegisterWndProvider
	
 * @Deprecated    Internal use.
 */
INTERFACE(void*, FRAppRegisterWndProvider, (FR_WndProviderCallbacks callbacks))

/**
 * @brief FRAppUnRegisterWndProvider
 * @details Unregisters the window provider by name.
 * @param[in]  name The input name of the window provider.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterWndProvider
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppUnRegisterWndProvider, (FS_LPCSTR name))

/**
 * @brief FRAppGetEditionType
 * @details Gets the edition type. There are five types, Business, Standard, Express, Enterprise and Free.
 * @param[out]  outType It receives the type value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppGetEditionType, (FS_ByteString* outType))

/**
 * @brief FRAppGetRecentFileListSize
 * @details Gets the recent file list size.
 * @return   The recent file list size.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppGetRecentFileList
 */
INTERFACE(FS_INT32, FRAppGetRecentFileListSize, (void))

/**
 * @brief FRAppGetModuleFileName
 * @details Gets the module file name of application.
 * @param[out]  outModuleFileName The string buffer used to receive the module file name of application.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(void, FRAppGetModuleFileName, (FS_WideString* outModuleFileName))

/**
 * @brief FRAppGetToolbarLocked
 * @details Checks whether the toolbar is locked.
 * @return   <a>TRUE</a> means the toolbar is locked.
 * @note this functions is deprecated.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppSetToolbarLocked
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppGetToolbarLocked, (void))

/**
 * @brief FRAppSetToolbarLocked
 * @details Sets the toolbar to be locked or not.
 * @param[in]  bLock <a>TRUE</a> means the toolbar will be locked, otherwise not.
 * @param[in]  bRecalcLayout <a>TRUE</a> means the layout of toolbar will be recalced, otherwise not. Sets it <a>TRUE</a> as default.
 * @return   void
 * @note this functions is deprecated.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppSetToolbarLocked
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppSetToolbarLocked, (FS_BOOL bLock,  FS_BOOL bRecalcLayout))

/**
 * @brief FRAppRegisterCmdMsgEventHandler
 * @details Registers a callbacks called by the Foxit Reader to route and dispatch command messages and to handle the update of command user-interface objects, such as menu, toolbar.
 * @param[in]  callbacks The input callbacks.
 * @return   The cmd msg event handler can be used to unregister by <a>FRAppUnRegisterCmdMsgEventHandler</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppUnRegisterCmdMsgEventHandler
 */
INTERFACE(void*, FRAppRegisterCmdMsgEventHandler, (FR_CmdMsgEventCallbacks callbacks))

/**
 * @brief FRAppUnRegisterCmdMsgEventHandler
 * @details Unregisters the input cmd msg event.
 * @param[in]  cmdMsgEventHandler The input cmd msg event handler returned by <a>FRAppRegisterCmdMsgEventHandler</a>.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppRegisterCmdMsgEventHandler
 */
INTERFACE(FS_BOOL, FRAppUnRegisterCmdMsgEventHandler, (void* cmdMsgEventHandler))

/**
 * @brief FRAppRemoveTaskPanelByName
 * @details Removes the specified task panel.
 * @param[in]  nameOfPaneView The input name of task panel to be removed.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppRegisterTaskPaneView
 * @see FRAppShowTaskPane
 * @see FRAppRemoveTaskPanelByName
 */
INTERFACE(FS_BOOL, FRAppRemoveTaskPanelByName, (FS_LPSTR nameOfPaneView))

/**
 * @brief FRAppDisableAllPanel
 * @details Disables all the navigation panels or not.
 * @param[in]  bDisable <a>TRUE</a> means all the navigation panels will be disabled, otherwise not.
 * @param[in]  hFrameWnd The child frame window. Set it as NULL to use the current child frame window.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(void, FRAppDisableAllPanel, (FS_BOOL bDisable,  HWND hFrameWnd))

/**
 * @brief FRAppIsDisableAllPanel
 * @details Checks whether all the panels are disabled.
 * @param[in]  hFrameWnd The child frame window. Set it as NULL to use the current child frame window.
 * @return   <a>TRUE</a> means all the panels are disabled, otherwise not.
 * @note * See: FRAppDisableAllPanel
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(FS_BOOL, FRAppIsDisableAllPanel, (HWND hFrameWnd))

/**
 * @brief FRAppGetPageContextMenuPos
 * @details Gets the position of context menu on the page view.
 * @param[out]  outPoint It receives the position.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note It is only available in Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppRegisterForContextMenuAddition
 */
INTERFACE(FS_BOOL, FRAppGetPageContextMenuPos, (FS_DevicePoint* outPoint))

/**
 * @brief FRAppOnCmdMsgByName
 * @details Routes and dispatches command messages from plug-ins to plug-ins
 * @param[in]  lpsName The name of menu or toolbar whose command messages need to be routed and dispatched.
 * @param[in]  nCode References to <Italic>MFC CCmdTarget::OnCmdMsg</Italic>.
 * @param[in]  pExtra References to <Italic>MFC CCmdTarget::OnCmdMsg</Italic>.
 * @param[in]  pHandlerInfo It represents the <Italic>MFC</Italic> struct <Italic>AFX_CMDHANDLERINFO</Italic>.
 * @return   Nonzero if the message is handled; otherwise 0.
 * @note This function is deprecated.
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppOnCmdMsgByName, (FS_LPCSTR lpsName,  FS_INT32 nCode,  void* pExtra,  void* pHandlerInfo))

/**
 * @brief FRAppSetOwnUndoMode
 * @details Sets the own undo mode.
 * @param[in]  frDoc The input document.
 * @param[in]  bOwnUndoMode <a>TRUE</a> if you want to sets the own undo mode, otherwise not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppAddUndoRedoItem
 * @see FRAppUndoRedoIsEditing
 * @see FRAppUndoRedoBeginEdit
 * @see FRAppUndoRedoEndEdit
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppSetOwnUndoMode, (FR_Document frDoc,  FS_BOOL bOwnUndoMode))

/**
 * @brief FRAppExitOwnUndoMode
 * @details Exits the own undo mode.
 * @param[in]  frDoc The input document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppAddUndoRedoItem
 * @see FRAppUndoRedoIsEditing
 * @see FRAppUndoRedoBeginEdit
 * @see FRAppUndoRedoEndEdit
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppExitOwnUndoMode, (FR_Document frDoc))

/**
 * @brief FRAppRegisterActionHandler
 * @details Registers an action handler. The callbacks are called by Foxit Reader when the Foxit Reader will do the actions. You 
	* can implement your own process to customize the action process.
 * @param[in]  callbacks The callbacks for action handler.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppRegisterActionHandler, (FR_ActionHandlerCallbacks callbacks))

/**
 * @brief FRAppRedrawRecentFileList
 * @details Redraws the recent file list in Ribbon mode.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note This interface has been deprecated.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppGetRecentFileList
 * @see FRAppAddFileToRecentFileList
 * @see FRAppClearRecentFileList
 */
INTERFACE(FS_BOOL, FRAppRedrawRecentFileList, (void))

/**
 * @brief FRAppSetCustomRecentFileListLabel
 * @details Sets the label of the custom recent file list.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  lpwsLabel The input label of recent file list.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppSetCustomRecentFileListLabel, (FS_LPCSTR lpsRecentFileListName,  FS_LPCWSTR lpwsLabel))

/**
 * @brief FRAppSetCustomRecentFileListItemBitmap
 * @details Sets the icon that will be displayed in front of the recent file list label.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  pItemBitmap The icon that will be displayed in front of the recent file list label.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppSetCustomRecentFileListItemBitmap, (FS_LPCSTR lpsRecentFileListName,  FS_DIBitmap pItemBitmap))

/**
 * @brief FRAppSetCustomRecentFileListMaxSize
 * @details Sets the max size of recent file list item.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  nMaxSize The input max size of recent file list item.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppSetCustomRecentFileListMaxSize, (FS_LPCSTR lpsRecentFileListName,  FS_INT32 nMaxSize))

/**
 * @brief FRAppSetCustomRecentFileListItemTitle
 * @details Sets the title of the recent file list item.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  nIndex The index of the recent file list item.
 * @param[in]  lpwsFileTitle The title of the recent file list item.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppSetCustomRecentFileListItemTitle, (FS_LPCSTR lpsRecentFileListName,  FS_INT32 nIndex,  FS_LPCWSTR lpwsFileTitle))

/**
 * @brief FRAppSetCustomRecentFileListItemTooltip
 * @details Sets the tooltip of the recent file.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  nIndex The index of the recent file list item.
 * @param[in]  lpwsFileTooltip The tooltip of the recent file.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppSetCustomRecentFileListItemTooltip, (FS_LPCSTR lpsRecentFileListName,  FS_INT32 nIndex,  FS_LPCWSTR lpwsFileTooltip))

/**
 * @brief FRAppGetCustomRecentFileListItemCount
 * @details Gets the item count of the custom recent file list.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @return   The item count of the custom recent file list.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRAppGetCustomRecentFileListItemCount, (FS_LPCSTR lpsRecentFileListName))

/**
 * @brief FRAppIsRTLLanguage
 * @details Checks whether the current language of app is right-to-left or not.
 * @return   TRUE if the current language of app is right-to-left, otherwise FALSE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FRAppIsRTLLanguage, (void))

/**
 * @brief FRAppGetOEMVersion
 * @details Gets the OEM version name.
 * @param[out]  outOEMVersion It receives the OEM version name. See <a>FROEMVersion</a>.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @Deprecated    internal use.
 */
INTERFACE(void, FRAppGetOEMVersion, (FS_ByteString* outOEMVersion))

/**
 * @brief FRAppRegisterDataCollectionHadler
 * @details Registers the data collection handler to collect the data as you need.
 * @param[in]  callbacks The callbacks for data collection handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRAppCollectNormalData
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppRegisterDataCollectionHadler, (FR_DataCollectionHandlerCallbacks callbacks))

/**
 * @brief FRAppGetUIParentWndByTaskPane
 * @details Gets the UI parent window handle.
 * @param[in]  taskPaneHwnd The window handle of the task pane.
 * @return   The UI parent window handle.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRAppRegisterTaskPaneView
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_HWND, FRAppGetUIParentWndByTaskPane, (FS_HWND taskPaneHwnd))

/**
 * @brief FRAppAdvWndSetCustomize
 * @details Sets whether to customize the advertisement.
 * @param[in]  bCustomize Whether to customize the advertisement.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppAdvWndSetCustomize, (FS_BOOL bCustomize))

/**
 * @brief FRAppGetAdvWnd
 * @details Gets the window handle to show the advertisement.
 * @return   The window handle to show the advertisement.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(HWND, FRAppGetAdvWnd, ())

/**
 * @brief FRAppShowAdvWnd
 * @details Shows the advertisement window or not.
 * @param[in]  nAdvWidth The width of the advertisement window. Sets it as 0 to hide the advertisement window.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppShowAdvWnd, (FS_INT32 nAdvWidth))

/**
 * @brief FRAppRegisterPOEventHandler
 * @details Registers a callbacks called by the Foxit Reader to do the page organizing, such as adding pages, deleting pages, replacing pages and so on.
 * @param[in]  callbacks The input callbacks.
 * @return   FS_LPVOID   Return the event handler.
 * @note Need to call FRAppUnRegisterPOEventHandler when after used.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRAppUnRegisterPOEventHandler
 */
INTERFACE(FS_LPVOID, FRAppRegisterPOEventHandler, (FR_POEventCallbacks callbacks))

/**
 * @brief FRAppCreateBlankDoc
 * @details Creates a blank document.
 * @param[in]  fWidth The width of the page in the blank document.
 * @param[in]  fHeight The height of the page in the blank document.
 * @return   The blank document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(FR_Document, FRAppCreateBlankDoc, (FS_FLOAT fWidth,  FS_FLOAT fHeight))

/**
 * @brief FRAppGetLocalFontName
 * @details Gets the local font name.
 * @param[out]  outFontName It receives the local font name.
 * @return   The local font name.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(void, FRAppGetLocalFontName, (FS_WideString* outFontName))

/**
 * @brief FRAppReLoadStartPage
 * @details Reloads the start page.
 * @param[in]  lpwsPath The input path of the start page.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppReLoadStartPage, (FS_LPCWSTR lpwsPath))

/**
 * @brief FRAppSetRecentFileListImageByExt
 * @details Sets the image of the file in the recent file list.
 * @param[in]  lpwsFileExt The input file extension name, of which you want to change the image in the recent file list.
 * @param[in]  fileImage The input image.
 * @return   True for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppSetRecentFileListImageByExt, (FS_LPCWSTR lpwsFileExt,  FS_DIBitmap fileImage))

/**
 * @brief FRAppGetCurMeasurementUnits
 * @details Gets the current measurement unites. Related to <a>FR_MesasureUnit</a>
 * @return   The current measurement unites.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRAppGetCurMeasurementUnits, (void))

/**
 * @brief FRAppGetNavPanelViewByName
 * @details Gets the window handle of the navigation panel view.
 * @param[in]  hChildfrm The child frame the navigation panel belongs to. You can invoke <a>FRDocGetDocFrameHandler</a> to get the child frame.
 * @param[in]  lpsName The input name of the navigation panel.
 * @return   The window handle of the navigation panel view.
 * @note This interface has been deprecated.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see FRAppAddNavPanelView
 * @see FRAppDisableAllPanel
 */
INTERFACE(HWND, FRAppGetNavPanelViewByName, (HWND hChildfrm,  FS_LPCSTR lpsName))

/**
 * @brief FRAppGetNavPanelNameByIndex
 * @details Gets the name of the navigation panel.
 * @param[in]  nIndex The input index of the navigation panel.
 * @param[out]  outName It receives the name of the navigation panel.
 * @return   void.
 * @note Only available in Windows
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see FRAppAddNavPanelView
 * @see FRAppDisableAllPanel
 */
INTERFACE(void, FRAppGetNavPanelNameByIndex, (FS_INT32 nIndex,  FS_ByteString* outName))

/**
 * @brief FRAppGetNavPanelCount
 * @details Gets the count of the navigation panel.
 * @return   The count of the navigation panel.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see FRAppaDDNavPanelView
 * @see FRAppDisableAllPanel
 */
INTERFACE(FS_INT32, FRAppGetNavPanelCount, ())

/**
 * @brief FRAppGetStartAppMode
 * @details Gets the app starting mode, 0 for not open any documents, and 1 for opening some documents at the same time.
 * @return   The app starting mode, 0 for not open any documents, and 1 for opening some documents at the same time.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRAppGetStartAppMode, ())

/**
 * @brief FRAppRestartProcess
 * @details Restarts the process of Foxit Reader or Foxit PhantomPDF.
 * @param[in]  bReOpenFile Whether to reopen the files or not.
 * @param[in]  bDelay Whether to delay the request or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppRestartProcess, (FS_BOOL bReOpenFile,  FS_BOOL bDelay))

/**
 * @brief FRAppGetStatusBarBkGroundColor
 * @details Gets the back ground color of status bar in ribbon mode.
 * @return   The back ground color of status bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_COLORREF, FRAppGetStatusBarBkGroundColor, ())

/**
 * @brief FRAppGetStatusBarBkGroundPath
 * @details Gets the path of the back ground color picture of the status bar in classic mode.
 * @param[out]  outPath It receives the path of the back ground color picture of the status bar in classic mode.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppGetStatusBarBkGroundPath, (FS_WideString* outPath))

/**
 * @brief FRAppCountAllTypesVisibleDocuments
 * @details Gets the count of the visible documents of all types, including the start page.
 * @return   The count of the visible documents of all types, including the start page.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_INT32, FRAppCountAllTypesVisibleDocuments, ())

/**
 * @brief FRAppAddFileToCustomRecentFileList2
 * @details Adds the recent file to the custom recent file list. Registers the Ribbon recent file event handler to catch the pinning and removing event, 
	* so that the plug-in can update the data layer.
 * @param[in]  lpsRecentFileListName The name that specifies the custom recent file list which the recent file path will be added to.
 * @param[in]  lpwsFilePath The recent file path that will be added.
 * @param[in]  lpwsFileTitle Instead of the file path, the title will be displayed in the recent file list.
 * @param[in]  lpwsFileTooltip The tooltip of the recent file.
 * @param[in]  exeProc When the recent file item is clicked, the callback will be invoked, unless you set it as NULL.
 * @param[in]  bEnableRemoveItem Whether the item can be removed or not.
 * @param[in]  nPinned The status of the pin, 0 for not pinned, 1 for pinned, 2 for not display the pin button.
 * @param[in]  clientData The client data that will be passed to the callback.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRAppCreateCustomRecentFileList
 * @see FRAppRegisterRibbonRecentFileEventHandler
	
 * @Deprecated    internal use.
 */
INTERFACE(FS_BOOL, FRAppAddFileToCustomRecentFileList2, (FS_LPCSTR lpsRecentFileListName,  FS_LPCWSTR lpwsFilePath,  FS_LPCWSTR lpwsFileTitle,  FS_LPCWSTR lpwsFileTooltip,  FRAppCustomRecentFileExecuteProc exeProc,  FS_BOOL bEnableRemoveItem,  FS_INT32 nPinned,  void* clientData))

/**
 * @brief FRAppRegisterRibbonRecentFileEventHandler
 * @details Registers a callbacks set for Ribbon recent file list event handler.
 * @param[in]  callbacks The input callbacks for Ribbon recent file list event handler.
 * @return   The pointer to Ribbon recent file list event handler can be destroyed by <a>FRAppDestroyRibbonRecentFileEventHandler</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRAppDestroyRibbonRecentFileEventHandler
	
 * @Deprecated    internal use.
 */
INTERFACE(void*, FRAppRegisterRibbonRecentFileEventHandler, (FR_RibbonRecentFileEventCallbacks callbacks))

/**
 * @brief FRAppDestroyRibbonRecentFileEventHandler
 * @details Destroys the Ribbon recent file list event handler returned by <a>FRAppRegisterRibbonRecentFileEventHandler</a>.
 * @param[in]  eventHandler The pointer to Ribbon recent file list event handler returned by <a>FRAppRegisterRibbonRecentFileEventHandler</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRAppRegisterRibbonRecentFileEventHandler
	
 * @Deprecated    internal use.
 */
INTERFACE(void, FRAppDestroyRibbonRecentFileEventHandler, (void* eventHandler))

/**
 * @brief FRAppSetMetadataOption
 * @details Sets the option to the document to control whether the metadata is to be compressed or not.
 * @param[in]  bCompress The input option value, true: compress, false: uncompress.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppSetMetadataOption, (FS_BOOL bCompress))

/**
 * @brief FRAppSetSubscriptionProvider
 * @details Registers a callbacks set for subscription provider.
 * @param[in]  callbacks The input callbacks for subscription provider.
 * @return   The pointer to subscription provider can be destroyed by <a>FRAppDestroySubscriptionProvider</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRAppDestroySubscriptionProvider
	
 * @Deprecated    Internal use.
 */
INTERFACE(void*, FRAppSetSubscriptionProvider, (FR_SubscriptionProviderCallbacks callbacks))

/**
 * @brief FRAppDestroySubscriptionProvider
 * @details Destroys the subscription provider returned by <a>FRAppSetSubscriptionProvider</a>.
 * @param[in]  subscriptionProvider The pointer to subscription provider returned by <a>FRAppSetSubscriptionProvider</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRAppSetSubscriptionProvider
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppDestroySubscriptionProvider, (void* subscriptionProvider))

/**
 * @brief FRAppGetKeyfileStartAndExpireDate
 * @details Gets the start date and the expire date of the key file.
 * @param[out]  outStartDate It receives the start date.
 * @param[out]  outExpireDate It receives the expire date.
 * @param[out]  outExpire Whether the key file expired or not.
 * @return   TRUE for success, otherwise the key file does not exist or is invalid.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_BOOL, FRAppGetKeyfileStartAndExpireDate, (FS_WideString* outStartDate,  FS_WideString* outExpireDate,  FS_BOOL* outExpire))

/**
 * @brief FRAppGetRibbonCategoryColor
 * @details Gets the back ground color of ribbon category.
 * @return   The back ground color of ribbon category.
 * @note Only available in Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_COLORREF, FRAppGetRibbonCategoryColor, (void))

/**
 * @brief FRAppGetRibbonElementColor
 * @details Gets the back ground color of ribbon element.
 * @param[out]  clrCheckButton The color when the button is selected.
 * @param[out]  clrCheckHighlight The color when the mouse is over the selected button.
 * @param[out]  clrHightButton The color when the mouse is over the none-selected button.
 * @param[out]  clrPressButton The color when the button is being clicked.
 * @return   TRUE for success, otherwise failure.
 * @note Only available in Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_BOOL, FRAppGetRibbonElementColor, (FS_COLORREF* clrCheckButton,  FS_COLORREF* clrCheckHighlight,  FS_COLORREF* clrHightButton,  FS_COLORREF* clrPressButton))

/**
 * @brief FRAppGetRibbonBaseBorderColor
 * @details Gets the back ground color of ribbon base border.
 * @return   The back ground color of ribbon base border.
 * @note Only available in Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_COLORREF, FRAppGetRibbonBaseBorderColor, (void))

/**
 * @brief FRAppGetRecentFolderListSize
 * @details Gets the recent folder list size.
 * @return   The recent folder list size.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see FRAppGetRecentFileList
 */
INTERFACE(FS_INT32, FRAppGetRecentFolderListSize, (void))

/**
 * @brief FRAppCreateEmptyFrameViewEventHandler
 * @details Creates the empty frame view event handler. Registers it through <a>FRAppCreateAnEmptyFrameWnd2</a>.Destroys it through <a>FRAppDestroyEmptyFrameViewEventHandler</a>;
 * @param[in]  callbacks The callbacks for the event handler of the empty frame window view.
 * @return   The <a>FR_EmptyFrameWndViewEventHandler</a> object.
 * @note Only available in Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see FRAppCreateAnEmptyFrameWnd2
 * @see FRAppDestroyEmptyFrameViewEventHandler
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_EmptyFrameWndViewEventHandler, FRAppCreateEmptyFrameViewEventHandler, (FR_EmptyFrameWndViewEventHandlerCallbacks callbacks))

/**
 * @brief FRAppDestroyEmptyFrameViewEventHandler
 * @details Destroys the event handler of the empty frame window view
 * @param[in]  eventHandler The input event handler of the empty frame window view.
 * @return   void.
 * @note Only available in Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see FRAppCreateAnEmptyFrameWnd2
 * @see FRAppCreateEmptyFrameViewEventHandler
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppDestroyEmptyFrameViewEventHandler, (FR_EmptyFrameWndViewEventHandler eventHandler))

/**
 * @brief FRAppCreateAnEmptyFrameWnd2
 * @details Creates a new frame window.
 * @param[in]  lpwsTitle The title of the frame which will be created.
 * @param[in]  lpwsPathName The input document path associated with the view.
 * @param[in]  eventHandler The input empty frame window view event handler.
 * @param[in]  bCreatePanel Whether to create the associated navigation panel or not. Sets it FALSE as default.
 * @param[in]  bMakeVisible A flag indicate whether to show the frame.
 * @param[in]  bAddToMRU Determines whether the file name is added to the most recently used (MRU) file list. Sets it FALSE as default.
 * @return   The handler of the newly created frame.
 * @note Only available in Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see FRAppCreateEmptyFrameViewEventHandler
 * @see FRAppDestroyEmptyFrameViewEventHandler
	
 * @Deprecated    Internal use.
 */
INTERFACE(HWND, FRAppCreateAnEmptyFrameWnd2, (FS_LPCWSTR lpwsTitle,  FS_LPCWSTR lpwsPathName,  FR_EmptyFrameWndViewEventHandler eventHandler,  FS_BOOL bCreatePanel,  FS_BOOL bMakeVisible,  FS_BOOL bAddToMRU))

/**
 * @brief FRAppIsReadMode
 * @details Checks whether Foxit Reader is in reading mode or not.
 * @return   <a>TRUE</a> if Foxit Reader is in reading mode, otherwise not.
 * @note It only avaiable in Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRAppExitReadMode
 */
INTERFACE(FS_BOOL, FRAppIsReadMode, ())

/**
 * @brief FRAppExitReadMode
 * @details Exits the reading mode.
 * @return   void.
 * @note It only avaiable in Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRAppIsReadMode
 */
INTERFACE(void, FRAppExitReadMode, ())

/**
 * @brief FRAppGetCurrentChildFrm
 * @details Gets the current child frame handle.
 * @return   The current child frame handle.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(HWND, FRAppGetCurrentChildFrm, ())

/**
 * @brief FRAppCollectDocActionData
 * @details The plug-in can invoke this interface to notify the other module to collect the action data.
 * @param[in]  frDoc The specified<a>FR_Document</a>.
 * @param[in]  lpwsOperatorType The specified operator type.
 * @param[in]  lpwsOperator The operator value.
 * @param[in]  valueMap The operator value map.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRDocOnDocCollectActionData
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppCollectDocActionData, (FR_Document frDoc,  FS_LPCWSTR lpwsOperatorType,  FS_LPCWSTR lpwsOperator,  FS_MapPtrToPtr valueMap))

/**
 * @brief FRAppActiveChildFrame
 * @details Activates the specified child frame.
 * @param[in]  hChildFrame The input child frame handle to be activated.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(void, FRAppActiveChildFrame, (HWND hChildFrame))

/**
 * @brief FRAppCollectNormalData
 * @details Notifies the other modules to collect some normal data.
 * @param[in]  lpwsFunction The function to be collected.
 * @param[in]  lpwsAction The function to be collected.
 * @param[in]  lpwsContent The content to be collected.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRAppRegisterDataCollectionHadler
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppCollectNormalData, (FS_LPCWSTR lpwsFunction,  FS_LPCWSTR lpwsAction,  FS_LPCWSTR lpwsContent))

/**
 * @brief FRAppSetMainframeShow
 * @details Sets whether the main frame will be shown or not when Foxit Reader starts up.
 * @param[in]  bShow Whether the main frame will be shown or not when Foxit Reader starts up.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(void, FRAppSetMainframeShow, (FS_BOOL bShow))

/**
 * @brief FRAppGetMainframeShow
 * @details Checks whether the main frame will be shown or not when Foxit Reader starts up.
 * @return   Whether the main frame will be shown or not when Foxit Reader starts up.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(FS_BOOL, FRAppGetMainframeShow, ())

/**
 * @brief FRAppGetRibbonTooltipBorderColor
 * @details Gets the border color of the ribbon tooltip.
 * @return   The border color of the ribbon tooltip.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.2
 */
INTERFACE(FS_COLORREF, FRAppGetRibbonTooltipBorderColor, (void))

/**
 * @brief FRAppGetRecentFileIndex
 * @details Gets the index of the specified recent file.
 * @param[in]  lpszPathName The recent opened file path.
 * @param[in]  bFolder Whether the path is a file or a folder.
 * @return   The index of the specified recent file.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 * @see FRAppGetRecentFileList
 * @see FRAppAddFileToRecentFileList
 * @see FRAppClearRecentFileList
 * @see FRAppRemoveFileFromRecentFileList
 */
INTERFACE(FS_INT32, FRAppGetRecentFileIndex, (FS_LPCWSTR lpszPathName,  FS_BOOL bFolder))

/**
 * @brief FRAppFZipUnzip
 * @details Unzips the .fzip file to the specified dest path.
 * @param[in]  lpszFZipPath The input .fzip file path.
 * @param[in]  lpszDestPath The dest path.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(FS_BOOL, FRAppFZipUnzip, (FS_LPCWSTR lpszFZipPath,  FS_LPCWSTR lpszDestPath))

/**
 * @brief FRAppIsJSEnabled
 * @details Checks whether the javascript is enabled or not.
 * @return   TRUE if the javascript is enabled, otherwise FALSE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(FS_BOOL, FRAppIsJSEnabled, ())

/**
 * @brief FRAppSetEnableJS
 * @details Sets the javascript to be enabled or not.
 * @param[in]  bEnable Sets the javascript to be enabled or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(void, FRAppSetEnableJS, (FS_BOOL bEnable))

/**
 * @brief FRAppCollectNormalData2
 * @details Notifies the other modules to collect some normal data.
 * @param[in]  lpwsFunction The function to be collected.
 * @param[in]  lpwsAction The function to be collected.
 * @param[in]  lpwsContent The content to be collected.
 * @param[in]  nLevel The detail level of the data.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see FRAppRegisterDataCollectionHadler
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppCollectNormalData2, (FS_LPCWSTR lpwsFunction,  FS_LPCWSTR lpwsAction,  FS_LPCWSTR lpwsContent,  FS_INT32 nLevel))

/**
 * @brief FRAppCollectBitmapData
 * @details Notifies the other modules to collect some bitmap data.
 * @param[in]  lpwsFunction The function to be collected.
 * @param[in]  lpwsAction The function to be collected.
 * @param[in]  pBitmap The bitmap to be collected.
 * @param[in]  nLevel The detail level of the data.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see FRAppRegisterDataCollectionHadler
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppCollectBitmapData, (FS_LPCWSTR lpwsFunction,  FS_LPCWSTR lpwsAction,  FS_DIBitmap pBitmap,  FS_INT32 nLevel))

/**
 * @brief FRAppIsNeedCollectData
 * @details Whether the cPDF data is need collected or not.
 * @return   TRUE if the cPDF data is need collected.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsNeedCollectData, ())

/**
 * @brief FRAppIsFipsMode
 * @details Whether the system is in Federal Information Processing Standard environment or not.
 * @return   TRUE if the system is in Federal Information Processing Standard environment.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsFipsMode, ())

/**
 * @brief FRAppAddNavPanelView
 * @details Adds a navigation panel view into the Foxit Reader.
	* The navigation panel view can be added after reader has started up.
	* It usually used for dynamic add panel, like click some button to add panel view.
 * @param[in]  panelViewCallbacks A panel view callback set invoked by reader to add a panel view to navigation panel.
 * @param[in]  nPos The position in the menu of navigation panel.
 * @return   The returned value should be released by <a>FRAppReleaseNavPanelView</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(void*, FRAppAddNavPanelView, (FR_PanelViewCallbacks panelViewCallbacks,  FS_INT32 nPos))

/**
 * @brief FRAppReleaseNavPanelView
 * @details Releases the navigation panel view returned by <a>FRAppAddNavPanelView</a>.
 * @param[in]  pNavPanelView Returned by <a>FRAppAddNavPanelView</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(void, FRAppReleaseNavPanelView, (void* pNavPanelView))

/**
 * @brief FRAppAddFileAttachment
 * @details Add a embed file to current document with The file path.
 * @param[in]  frDoc The specified document.
	* param[in]: lpwsAttachFilePath		The file path for add.
 * @return   Non-zero means succeed, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(FS_BOOL, FRAppAddFileAttachment, (FR_Document frDoc,  FS_LPCWSTR lpwsAttachFilePath))

/**
 * @brief FRAppOpenFileAttachment
 * @details open a embed file.
 * @param[in]  pDict The FileAttachment dictionary.
	* param[in]: nPage		The Page index.
	* param[in]: bAnnot	Is FileAttachment Annot.
 * @return   Non-zero means succeed, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.5
 */
INTERFACE(FS_BOOL, FRAppOpenFileAttachment, (FPD_Object pDict,  FS_INT32 nPage,  FS_BOOL bAnnot,  FS_LPCWSTR wsFileName))

/**
 * @brief FRAppIsPDF2Doc
 * @details Check the revision of the standard security handler is greater than or equal to 5.
 * @param[in]  pSourDoc The specified document.
 * @return   TRUE: the encrypt revision is greater than or equal to 5.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(FS_BOOL, FRAppIsPDF2Doc, (FPD_Document pSourDoc))

/**
 * @brief FRAppConvertToPDF
 * @details convert file to Pdf file.
 * @param[in]  lpwsFile The Original File.
 * @param[in]  lpwsDest The Dest File.
 * @param[in]  hWnd The hWnd,default NULL.
 * @param[in]  bShowProgressBar If show the progress bar.
 * @param[in]  bConvertToCPDF If need convert to CPDF File.
 * @param[in]  bDelDestFile If need delete the Dest File when convert failed.
 * @return   zero means successful, otherwise failed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @see FRAppConvertToPDFA
 */
INTERFACE(FS_INT32, FRAppConvertToPDF, (FS_LPCWSTR lpwsFile,  FS_LPCWSTR lpwsDest,  HWND hWnd,  FS_BOOL bShowProgressBar,  FS_BOOL bConvertToCPDF,  FS_BOOL bDelDestFile))

/**
 * @brief FRAppRegisterPDFAPluginHandler
 * @details The callbacks of pdfa Handler just be called while the document was saved to pdfa.
 * @param[in]  pdfaPluginHandlerCallbacks The callback set. Reader will call a corresponding callback when save to pdfa occurs.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppRegisterPDFAPluginHandler, (FR_PDFAPluginHandlerCallbacks pdfaPluginHandlerCallbacks))

/**
 * @brief FRAppConvertToPDFA
 * @details Converts file to PDFA file.
 * @param[in]  frDoc The specified document.
 * @param[in]  fswsSaveAsFileName The dest document path to be saved.
 * @param[in]  pVersion The PDFA version to be converted.
 * @return   Zero means successful, otherwise failed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @see FRAppConvertToPDF
 */
INTERFACE(FS_INT32, FRAppConvertToPDFA, (FR_Document frDoc,  const FS_WideString fswsSaveAsFileName,  const FRPDFA_PDFVersion pVersion))

/**
 * @brief FRAppAddLog
 * @details Outputs log information.
 * @param[in]  nLevel The specified log level.
 * @param[in]  wsMsg The input log message.
 * @param[in]  file The file where the log is added. Use __FILE__ as default.
 * @param[in]  nLine The code line where the log is added. Use __LINE__ as default.
 * @param[in]  function The function where the log is added. use __FUNCTION__ as default.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppAddLog, (FR_LOG_LEVEL nLevel,  FS_WideString wsMsg,  const FS_CHAR* file,  FS_INT32 nLine,  const FS_CHAR* function))

/**
 * @brief FRAppIsReaderOnlyMode
 * @details 
 * @param[in]  hWnd 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsReaderOnlyMode, (HWND hWnd))

/**
 * @brief FRAppGetMainFrameWndCount
 * @details 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRAppGetMainFrameWndCount, ())

/**
 * @brief FRAppGetMainFrameWndByIndex
 * @details Get MainFrameWnd by index
 * @param[in]  nIndex 
 * @return   
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @see FRAppGetMainFrameWndByIndex
	
 * @Deprecated    Internal use.
 */
INTERFACE(void*, FRAppGetMainFrameWndByIndex, (FS_INT32 nIndex))

/**
 * @brief FRAppGetModelessParentWnd
 * @details Get modeless parent HWnd
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @Deprecated    Internal use.
 */
INTERFACE(HWND, FRAppGetModelessParentWnd, ())

/**
 * @brief FRAppIsMainfrmActivating
 * @details Check mainframe is activating
 * @param[in]  hWnd 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @Deprecated    Internal use.
 */
INTERFACE(BOOL, FRAppIsMainfrmActivating, (HWND hWnd))

/**
 * @brief FRAppGetRibbonBar2
 * @details Gets Foxit Reader's ribbon bar.
 * @param[in]  hWnd A handle to the parent window. It represents the <Italic>MFC HWND</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   The ribbon bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(FR_RibbonBar, FRAppGetRibbonBar2, (HWND hWnd))

/**
 * @brief FRAppRefreshLayerPanelView
 * @details Refresh Layer Panel
 * @param[in]  pCpdfDoc 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppRefreshLayerPanelView, (FPD_Document pCpdfDoc))

/**
 * @brief FRAppDeprecatedRegisterDRMSecurityHandler
 * @details Registers a security handler. Invoked this interface to process the PDF documents that 
	* are encrypted by customer security handler.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.5
 * @param[in]  name The name of the security handler.
 * @param[in]  callbacks The structure containing the security handler callback functions.
 * @return   void
 * @note 
 * @see FRAppUnRegisterSecurityHandler
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppDeprecatedRegisterDRMSecurityHandler, (FS_LPCSTR name,  FS_LPVOID callbacks))

/**
 * @brief FRAppAddECMFileDialog
 * @details Add an ECM plugin that needs to be displayed in fileDialog.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  lpwsPluginName The plugin name.
 * @param[in]  lpwsPluginHftName The plugin HFT name.
 * @param[in]  lpwsTitle Plugin title displayed on filedialog.
 * @param[in]  openproc If filedailog is open style, callback when selecting ECM menu item.
 * @param[in]  saveproc If filedailog is save style, callback when selecting ECM menu item.
 * @param[in]  clientdata A pointer to user-supplied data. Used in <a>FRAppFileDialogECMOpenProc, FRAppFileDialogECMSaveProc</a>.
 * @return   void
 * @note 
 * @see FRAppAddECMFileDialog
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppAddECMFileDialog, (FS_LPCWSTR lpwPluginName,  FS_LPCWSTR lpwPluginHftName,  FS_LPCWSTR lpwTitle,  FRAppFileDialogECMOpenProc openproc,  FRAppFileDialogECMSaveProc saveproc,  void* clientdata))

/**
 * @brief FRAppECMFileDialogAddMenuItem
 * @details FileDialog adds ECM menu, menu item depends on <a>FRAppAddECMFileDialog</a>.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  pFileDialog adds ECM menu, menu item depends on <a>FRAppAddECMFileDialog</a>.
 * @param[in]  type FileDialog style attribute, see the value of <a>FRCCDFileDialogType</a>.
 * @return   void
 * @note 
 * @see FRAppECMFileDialogAddMenuItem
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppECMFileDialogAddMenuItem, (void* pFileDialog,  FRDECMFileDialogType type))

/**
 * @brief FRAppECMFileDialogItemSelected
 * @details Select the ECM menu, you need to call in CFileDialog::OnItemSelected.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  wsSrcFilePath Source file path. Used when FRDECMFileDialogType is Save style.
 * @param[in]  pFileDialog CFileDialog pointer.
 * @param[in]  pIFileDialog IFileDialog pointer.
 * @param[in]  dwIDCtl The ID of the container control.
 * @param[in]  dwIDItem The ID of the item.
 * @param[in]  type FileDialog style attribute, see the value of <a>FRCCDFileDialogType</a>.
 * @param[out]  bViewExportResult <a>TRUE</a>Open the export result. Only for the case where <FRDECMFileDialogType> is FR_ECMFileDialog_Save_Export.
 * @return   void
 * @note 
 * @see FRAppECMFileDialogItemSelected
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppECMFileDialogItemSelected, (FS_LPCWSTR wsSrcFilePath,  void* pFileDialog,  void* pIFileDialog,  DWORD dwIDCtl,  DWORD dwIDItem,  FRDECMFileDialogType type,  FS_BOOL bViewExportResult))

/**
 * @brief FRAppGetECMFileDialog
 * @details Get the CFileDialog containing the ECM menu.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  type FileDialog style attribute, see the value of <a>FRCCDFileDialogType</a>.
 * @param[in]  lpszSrcFilePath Source file path. Used when FRDECMFileDialogType is Save style.
 * @param[in]  bOpenFileDialog Refer to the <a>CFileDialog</a> constructor.
 * @param[in]  lpszDefExt Refer to the <a>CFileDialog</a> constructor.
 * @param[in]  lpszFileName Refer to the <a>CFileDialog</a> constructor.
 * @param[in]  dwFlags Refer to the <a>CFileDialog</a> constructor.
 * @param[in]  lpszFilter Refer to the <a>CFileDialog</a> constructor.
 * @param[in]  pParentWnd Refer to the <a>CFileDialog</a> constructor.
 * @param[in]  dwSize Refer to the <a>CFileDialog</a> constructor.
 * @param[in]  bVistaStyle Refer to the <a>CFileDialog</a> constructor.
 * @return   void
 * @note 
 * @see FRAppGetECMFileDialog
	
 * @Deprecated    Internal use.
 */
INTERFACE(void*, FRAppGetECMFileDialog, (FRDECMFileDialogType type,  FS_LPCWSTR wsSrcFilePath,  BOOL bOpenFileDialog,  // TRUE for FileOpen,  FALSE for FileSaveAs
										FS_LPCWSTR lpszDefExt,  FS_LPCWSTR lpszFileName,  DWORD dwFlags,  FS_LPCWSTR lpszFilter,  void* pParentWnd,  DWORD dwSize,  BOOL bVistaStyle))

/**
 * @brief FRAppGetSelectedECMPluginName
 * @details Get the selected ECM plugin name.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  pFileDialog CFileDialog pointer.
 * @param[out]  outPluginName PluginName.
 * @return   void
 * @note 
 * @see FRAppGetSelectedECMPluginName
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppGetSelectedECMPluginName, (void* pFileDialog,  FS_WideString* outPluginName))

/**
 * @brief FRAppGetMainClientAreaWnd
 * @details Gets the main frame window client area of Foxit Reader.
	*Since: <a>SDK_LATEEST_VERSION< / a> > 10.0
 * @param[in]  hMainframe the main frame window of Foxit Reader.
 * @return   A <Italic>HWND</Italic> object for windows client area.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(HWND, FRAppGetMainClientAreaWnd, (HWND hMainframe))

/**
 * @brief FRAppRegisterPortfolioEventHandler
 * @details Registers a user-supplied event handler to document window.
 * @param[in]  portfolioDocEventCallbacks The callback set. Reader will call a corresponding callback when the doc event occurs.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note The callbacks of FR Doc Event Handler just be called while the document window is displaying PDF file type.
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppRegisterPortfolioEventHandler, (FR_PortfolioEventCallbacks portfolioDocEventCallbacks))

/**
 * @brief FRAppAddECMUploadProc
 * @details an ECM plugin needs to upload file.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  lpwsPluginName The plugin name.
 * @param[in]  lpwsPluginHftName The plugin HFT name.
 * @param[in]  lpwsTitle Plugin title displayed on filedialog.
 * @param[in]  uploadproc callback is called when ECM plugin needs to upload.
 * @param[in]  clientdata A pointer to user-supplied data. Used in <a>FRAppFileDialogECMUploadProc</a>.
 * @return   void
 * @note 
 * @see FRAppAddECMFileDialog
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppAddECMUploadProc, (FS_LPCWSTR lpwPluginName,  FS_LPCWSTR lpwPluginHftName,  FS_LPCWSTR lpwTitle,  FRAppFileDialogECMUploadProc uploadproc,  void* clientdata))

/**
 * @brief FRAppGetConvertPDFErrMsg
 * @details 
 * @param[in]  nerror nerror The error code from <a>FRAppConvertToPDF</a>
 * @param[out]  outErrorMsg error msg.
	* Remarks:   get convert file err msg.
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 * @see FRAppConvertToPDF
 */
INTERFACE(void, FRAppGetConvertPDFErrMsg, (FS_INT32 nerror,  FS_WideString* outErrorMsg))

/**
 * @brief FRAppECMFileDialogUploadProc
 * @details 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 * @see FRAppECMFileDialogUploadProc
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppECMFileDialogUploadProc, (FS_LPCWSTR wsSrcFilePath,  FS_LPCWSTR wsNewFilePath,  FRDECMFileDialogType type,  FS_BOOL bUpload))

/**
 * @brief FRAppECMFileDialogRemoveMenuItem
 * @details FileDialog Remove ECM menu, menu item depends on <a>FRAppAddECMFileDialog</a>.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  pFileDialog rempve ECM menu, menu item depends on <a>FRAppAddECMFileDialog</a>.
 * @param[in]  wsPluginName The plugin name.
 * @return   void
 * @note 
 * @see FRAppECMFileDialogRemoveMenuItem
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppECMFileDialogRemoveMenuItem, (void* pFileDialog,  FS_LPCWSTR wsPluginName))

/**
 * @brief FRAppCollectSensorData
 * @details .
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  sensorData the Data of Sensor that depends on <a>FR_SensorData</a>.
 * @return   void
 * @note 
 * @see FRAppCollectSensorData
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppCollectSensorData, (FR_SensorData sensorData))

/**
 * @brief FRAppGetSystemHandler
 * @details Get window::IFX_SystemHandler obj from phantom<a>FRAppGetSystemHandler</a>.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @return   FR_SystemHandler, the actual type is CSH_SystemHandler*
 * @note 
 * @see FRAppGetSystemHandler
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_SystemHandler, FRAppGetSystemHandler, ())

/**
 * @brief FRAppCreateAndRegisterFormDesignerToolHandler
 * @details RegisterToolHandler of formfield,that's for esgin.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  eFieldType Esign filed type.
 * @param[in]  lpToolName Esign tool name.
 * @param[in]  lpToolLabel Esign tool label.
 * @param[in]  lpReg The reg data of esign.
 * @param[in]  dwFieldFlags The flags of field.
 * @return   void
 * @note 
 * @see FRAppCreateAndRegisterFormDesignerToolHandler
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppCreateAndRegisterFormDesignerToolHandler, (FS_INT32 eFieldType,  FS_LPCSTR lpToolName,  FS_LPCWSTR lpToolLabel,  FS_LPCWSTR lpReg,  FS_DWORD dwFieldFlags))

/**
 * @brief FRAppShowModuleNoLicenseDlg
 * @details FRAppShowModuleNoLicenseDlg shows module no license dialog.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  csModule module name.
 * @return   void
 * @note 
 * @see FRAppShowModuleNoLicenseDlg
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppShowModuleNoLicenseDlg, (FS_WideString csModule))

/**
 * @brief FRAppDeleteAnnot
 * @details FRAppDeleteAnnot used to delete annot from IReader_AnnotHandlerMgr .
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  pAnnot the annot need to delete.
 * @return   void
 * @note 
 * @see FRAppDeleteAnnot
 */
INTERFACE(void, FRAppDeleteAnnot, (FR_Annot pAnnot))

/**
 * @brief FRAppDoModulePreferDlg
 * @details FRAppDoModulePreferDlg used to show module prefer dialog.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  csTabTitle The tab tile of the preferdlg.
 * @param[in]  pParent The pParent of the preferdlg.
 * @return   FS_INT32
 * @note 
 * @see FRAppDoModulePreferDlg
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRAppDoModulePreferDlg, (FS_WideString csTabTitle,  FS_LPVOID pParent))

/**
 * @brief FRAppRegisterAnnotHandler
 * @details FRAppRegisterAnnotHandler used to register annothanlder to IBaseAnnot.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  annotHandler annot callback register to IBaseAnnot.
 * @return   void
 * @note 
 * @see FRAppRegisterAnnotHandler
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppRegisterAnnotHandler, (FR_BAAnnotHandler annotHandler))

/**
 * @brief FRAppAddUndoItemCRSA
 * @details FRAppAddUndoItemCRSA used to add undo item of CRSA.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  doc The current document.
 * @param[in]  pageview The current page view, that is IReader_PageViewer.
 * @param[in]  annot The annot need to add undo item oprea.
 * @param[in]  dtOld The old datetime.
 * @param[in]  dtNew The new datetime.
 * @param[in]  rcOld The old rect.
 * @param[in]  rcNew The new rect.
 * @return   void
 * @note 
 * @see FRAppAddUndoItemCRSA
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppAddUndoItemCRSA, (FR_Document doc,  FR_PageView pageview,  FR_Annot annot,  FS_ReaderDateTime dtOld,  FS_ReaderDateTime dtNew,  FS_FloatRect rcOld,  FS_FloatRect rcNew))

/**
 * @brief FRAppBaseAnnotLoadCursor
 * @details FRAppBaseAnnotLoadCursor used to load cursor of the annot.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  nCursorType The cursor type of the annot.
 * @return   void
 * @note 
 * @see FRAppBaseAnnotLoadCursor
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Cursor, FRAppBaseAnnotLoadCursor, (FS_INT32 nCursorType))

/**
 * @brief FRAppAddDragPoint
 * @details FRAppAddDragPoint used to add drag point.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  pPageView The current page view.
 * @param[in]  point The location of drag point.
 * @param[in]  nFlag The flag of drag point.
 * @param[in]  nDrawMode The drawmode of drag point.
 * @return   void
 * @note 
 * @see FRAppAddDragPoint
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppAddDragPoint, (FR_PageView pPageView,  const FS_DevicePoint& point,  FS_INT32 nFlag,  FS_INT32 nDrawMode))

/**
 * @brief FRAppGetSystemDefaultFont
 * @details FRAppGetSystemDefaultFont used to get system default font.
 * @param[in]  lf The system default font	.
 * @return   void
 * @note * See:  FRAppGetSystemDefaultFont
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 */
INTERFACE(void, FRAppGetSystemDefaultFont, (LOGFONT* lf))

/**
 * @brief FRAppGetRSAAnnotElement
 * @details FRAppGetRSAAnnotElement used to get RSAAnnot element.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  pPDFDoc The document in which the annotation is located.
 * @param[in]  pAnnot The RSA annot obj
 * @return   FS_XMLElement
 * @note 
 * @see FRAppGetRSAAnnotElement
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_XMLElement, FRAppGetRSAAnnotElement, (FPD_Document pPDFDoc,  FR_Annot pAnnot))

/**
 * @brief FRAppGetPopupElement
 * @details FRAppGetPopupElement used to get popup element.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  pPDFDoc The document in which the annotation is located.
 * @param[in]  pAnnot The RSA annot obj
 * @return   FS_XMLElement
 * @note 
 * @see FRAppGetPopupElement
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_XMLElement, FRAppGetPopupElement, (FPD_Document pPDFDoc,  FR_Annot pAnnot))

/**
 * @brief FRAppGetJSEngineHRuntime
 * @details FRAppGetJSEngineHRuntime used to get JS engin.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @return   FSJSE_HRUNTIME
 * @note 
 * @see FRAppGetJSEngineHRuntime
	
 * @Deprecated    Internal use.
 */
INTERFACE(FSJSE_HRUNTIME, FRAppGetJSEngineHRuntime, ())

/**
 * @brief FRAppUnRegisterDocHandlerOfPDDoc
 * @details Unregisters a user-supplied event handler to document window.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  docEventCallbacks The document event callback.
 * @return   FS_BOOL
 * @note 
 * @see FRAppRegisterDocHandlerOfPDDoc
 */
INTERFACE(FS_BOOL, FRAppUnRegisterDocHandlerOfPDDoc, (FR_DocEventCallbacks docEventCallbacks))

/**
 * @brief FRAppGetOperatorPermission
 * @details FRAppGetOperatorPermission used to get operation permission.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @return   FS_BOOL
 * @note 
 * @see FRAppGetOperatorPermission
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppGetOperatorPermission, ())

/**
 * @brief FRAppGetHContext
 * @details FRAppGetHContext used to get JS HCONTEXT.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  frDoc The current document.
 * @return   FSJSE_HCONTEXT
 * @note 
 * @see FRAppGetHContext
	
 * @Deprecated    Internal use.
 */
INTERFACE(FSJSE_HCONTEXT, FRAppGetHContext, (FR_Document frDoc))

/**
 * @brief FRAppJSGetGlobalObject
 * @details FRAppJSGetGlobalObject used to get global object.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  hContext The JS HCONTEXT.
 * @return   FSJSE_HVALUE
 * @note 
 * @see FRAppJSGetGlobalObject
	
 * @Deprecated    Internal use.
 */
INTERFACE(FSJSE_HVALUE, FRAppJSGetGlobalObject, (FSJSE_HCONTEXT hContext))

/**
 * @brief FRAppJSSetUndefined
 * @details FRAppJSSetUndefined is to call  FXJSE_Value_SetUndefined.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  hValue The JS HVALUE.
 * @return   void
 * @note 
 * @see FRAppJSSetUndefined
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppJSSetUndefined, (FSJSE_HVALUE hValue))

INTERFACE(void, FRAppJSValueSet, (FSJSE_HVALUE hValue,  FSJSE_HVALUE hOriginalValue))

/**
 * @brief FRAppJSValueRelease
 * @details FRAppJSValueRelease is to call FXJSE_Value_Release.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  hValue The JS HVALUE.
 * @return   void
 * @note 
 * @see FRAppJSValueRelease
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppJSValueRelease, (FSJSE_HVALUE hValue))

/**
 * @brief FRAppRegisterTransitionHandler
 * @details callbacks is derived on CReader_TransHandler.
 * @param[in]  callbacks The transition handler.
 * @return   FS_BOOL
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppRegisterTransitionHandler, (FR_TransitionCallbacks callbacks))

/**
 * @brief FRAppGetPreferenceIdentity
 * @details get document's Preference Identity info
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  doc The current document.
 * @param[in]  info The identify info of the document.
 * @return   void
 * @note 
 * @see FRAppGetPreferenceIdentity
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppGetPreferenceIdentity, (FR_Document doc,  FR_IdentityInfo &info))

/**
 * @brief FRAppJSRuntimeNewContext
 * @details return value is IJS_Context type
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  doc The current document.
 * @return   FS_LPVOID
 * @note 
 * @see FRAppJSRuntimeNewContext
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_LPVOID, FRAppJSRuntimeNewContext, (FR_Document doc))

/**
 * @brief FRAppJSRuntimeReleaseContext
 * @details Release JS Runtime context
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  doc The current document.
 * @return   void
 * @note 
 * @see FRAppJSRuntimeReleaseContext
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppJSRuntimeReleaseContext, (FR_Document doc))

/**
 * @brief FRAppIsRunIPFrame
 * @details Get is run IP frame 
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @return   FS_BOOL
 * @note The function can only be used for Windows.
 * @see FRAppIsRunIPFrame
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsRunIPFrame, ())

/**
 * @brief FRAppOwnerFileTypeHandlerDoEmail
 * @details OwnerFileTypeHandler send email.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  csFDFFile the cpdf file path.
 * @return   FS_BOOL
 * @note 
 * @see FRAppOwnerFileTypeHandlerDoEmail
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppOwnerFileTypeHandlerDoEmail, (FS_WideString csFDFFile))

/**
 * @brief FRAppGetEmailTabDocInfo
 * @details Get Email doc Info
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  readerDocEx the current document
 * @param[out]  wsPath the doc path.
 * @param[out]  wsName the doc name.
 * @return   FS_BOOL
 * @note 
 * @see FRAppGetEmailTabDocInfo
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppGetEmailTabDocInfo, (FR_Document readerDocEx,  FS_WideString* wsPath,  FS_WideString* wsName))

/**
 * @brief FRAppGetAULIBCurrentLanguage
 * @details Get current AUI language.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[out]  wsLan the current AUI language
 * @return   void
 * @note 
 * @see FRAppGetAULIBCurrentLanguage
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppGetAULIBCurrentLanguage, (FS_WideString* wsLan))

/**
 * @brief FRAppGetIsEmailChoosePageRange
 * @details Whether the select page dialog box will pop up when sending the current mail.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @return   FS_BOOL
 * @note The function can only be used for Windows.
 * @see FRAppGetIsEmailChoosePageRange
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppGetIsEmailChoosePageRange, ())

/**
 * @brief FRAppAddECMFileDialog2
 * @details Add an ECM plugin that needs to be displayed in fileDialog.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  lpwsPluginName The plugin name.
 * @param[in]  lpwsPluginHftName The plugin HFT name.
 * @param[in]  lpwsTitle Plugin title displayed on filedialog.
 * @param[in]  openproc If filedailog is open style, callback when selecting ECM menu item.
 * @param[in]  saveproc If filedailog is save style, callback when selecting ECM menu item.
 * @param[in]  clientdata A pointer to user-supplied data. Used in <a>FRAppFileDialogECMOpenProc, FRAppFileDialogECMSaveProc</a>.
 * @return   void
 * @note The function can only be used for Windows.
 * @see FRAppAddECMFileDialog2
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppAddECMFileDialog2, (FS_LPCWSTR lpwPluginName,  FS_LPCWSTR lpwPluginHftName,  FS_LPCWSTR lpwTitle,  FRAppFileDialogECMOpenProc2 openproc,  FRAppFileDialogECMSaveProc saveproc,  void* clientdata))

/**
 * @brief FRAppIsEditingUseHindiDigits
 * @details Is Editing Use Hindi Digits mode.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @return   FS_BOOL
 * @note The function can only be used for Windows.
 * @see FRAppIsEditingUseHindiDigits
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsEditingUseHindiDigits, ())

/**
 * @brief FRAppCountTaskPaneName
 * @details Get the count of the right task panel.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @return   FS_INT32
 * @note 
 * @see FRAppGetTaskPaneNameByIndex
 */
INTERFACE(FS_INT32, FRAppCountTaskPaneName, ())

/**
 * @brief FRAppGetTaskPaneNameByIndex
 * @details Get name of the right task panel by index.
 * @param[in]  nIndex The index of FRAppCountTaskPaneName.
 * @param[out]  outPanelName Get the right panel name by the specified index.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 */
INTERFACE(void, FRAppGetTaskPaneNameByIndex, (FS_INT32 nIndex,  FS_ByteString* outPanelName))

/**
 * @brief FRAppGetDocUnit
 * @details Get unit of doc.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @return   FS_INT32
 * @note 
 * @see FRAppGetDocUnit
 */
INTERFACE(FS_INT32, FRAppGetDocUnit, ())

/**
 * @brief FRAppChangeUnits
 * @details Change unit of doc.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  fSrc The origin unit.
 * @param[in]  nSrcType The source type.
 * @param[in]  nDestType The dest type.
 * @return   FS_FLOAT
 * @note 
 * @see FRAppChangeUnits
 */
INTERFACE(FS_FLOAT, FRAppChangeUnits, (FS_FLOAT fSrc,  FS_INT32 nSrcType,  FS_INT32 nDestType))

/**
 * @brief FRAppGetSelectedECMPluginAccount
 * @details Get selected ECM Plugin Account
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  pFileDialog the CFileDialog containing the ECM menu, menu item depends on <a>FRAppAddECMFileDialog</a>.
 * @param[in]  outPluginAccount The ecm accout info.
 * @return   void
 * @note 
 * @see FRAppGetSelectedECMPluginAccount
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppGetSelectedECMPluginAccount, (void* pFileDialog,  FS_WideString* outPluginAccount))

/**
 * @brief FRAppAddECMFileDialog3
 * @details Add an ECM plugin that needs to be displayed in fileDialog.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  lpwsPluginName The plugin name.
 * @param[in]  lpwsPluginHftName The plugin HFT name.
 * @param[in]  lpwsTitle Plugin title displayed on filedialog.
 * @param[in]  openproc If filedailog is open style, callback when selecting ECM menu item.
 * @param[in]  saveproc If filedailog is save style, callback when selecting ECM menu item.
 * @param[in]  clientdata A pointer to user-supplied data. Used in <a>FRAppFileDialogECMOpenProc, FRAppFileDialogECMSaveProc</a>.
 * @return   void
 * @note 
 * @see FRAppAddECMFileDialog3
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppAddECMFileDialog3, (FS_LPCWSTR lpwPluginName,  FS_LPCWSTR lpwPluginHftName,  FS_LPCWSTR lpwTitle,  FRAppFileDialogECMOpenProc3 openproc,  FRAppFileDialogECMSaveProc saveproc,  void* clientdata))

/**
 * @brief FRAppRegisterUserMessageHanler
 * @details If registered successfully.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  handler CFR_ReaderUserMessageHandler that is inherit from IReader_UserMessagehandler.
 * @return   FS_BOOL
 * @note 
 * @see FRAppRegisterUserMessageHanler
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppRegisterUserMessageHanler, (FR_ReaderUserMessageHandler handler))

/**
 * @brief FRAppUnRegisterUserMessageHanler
 * @details If unregistered successfully.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  handler CFR_ReaderUserMessageHandler that is inherit from IReader_UserMessagehandler.
 * @return   FS_BOOL
 * @note 
 * @see FRAppUnRegisterUserMessageHanler
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppUnRegisterUserMessageHanler, (FR_ReaderUserMessageHandler handler))

/**
 * @brief FRAppSetSGBaseHandler
 * @details Set signature handler
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  handler CFR_SGBaseHandler that is inherit from ISG_BaseHandler.
 * @return   void
 * @note 
 * @see FRAppSetSGBaseHandler
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppSetSGBaseHandler, (void* pSGBaseHandler))

/**
 * @brief FRAppDestoryRibbonFloaty
 * @details destroy ribbon Floaty MiniFrameWnd
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.7
 * @param[in]  pFloaty Floaty MiniFrameWnd
 * @return   void
 * @note The function can only be used for Windows.
 * @see FRAppDestoryRibbonFloaty
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppDestoryRibbonFloaty, (FS_LPVOID pFloaty))

INTERFACE(FS_BOOL, FRAppSetActiveTool2, (FR_Tool tool,  FS_BOOL persistent,  FS_BOOL bDelay))

/**
 * @brief FRAppGetRedirectURL
 * @details If it's not OEM package, nButtonID will not be used.
 * @param[in]  csTitle The tool to set as the active tool.
 * @param[in]  nButtonID A flag that indicates a preference as to whether the tool stays active after
 * @param[out]  outURL Get the redirect url.
 * @return   void
 * @note 
 * @see FRAppGetRedirectURL
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppGetRedirectURL, (FS_WideString csTitle,  FS_INT32 nButtonID,  FS_WideString* outURL))

/**
 * @brief FRAppIsPortfolioSubDoc
 * @details Check if the document is protfolio sub doc.
 * @param[in]  pReaderDoc The current document obj.
 * @return   FS_BOOLEAN
 * @note 
 * @see FRAppIsPortfolioSubDoc
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRAppIsPortfolioSubDoc, (FR_Document pReaderDoc))

/**
 * @brief FRAppIsCurDocViewShowInContainerFrm
 * @details Check if the current docview is show in the portfolio review window.
 * @return   FS_BOOLEAN
 * @note The function can only be used for Windows.
 * @see FRAppIsCurDocViewShowInContainerFrm
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRAppIsCurDocViewShowInContainerFrm, ())

/**
 * @brief FRAppCheckTrustySites
 * @details Check if the site or the file is trusted.
 * @param[in]  csUrl The site address.
 * @param[in]  bNeedRemember Set true will be remember.
 * @param[in]  cwFilePath The file need to be check if it's trusted.
 * @param[in]  pParent The CWnd* obj,that use to show warning dialog.
 * @param[in]  bCheckFilePath Set true will need to check file path.
 * @return   FS_BOOLEAN
 * @note 
 * @see FRAppCheckTrustySites
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRAppCheckTrustySites, (FS_LPCWSTR csUrl,  FS_BOOL bNeedRemember,  FS_LPCWSTR cwFilePath,  FS_LPVOID pParent,  FS_BOOL bCheckFilePath))

/**
 * @brief FRAppIsLinearizeSaveAs
 * @details Check if need to linearize save.
 * @return   FS_BOOL
 * @note 
 * @see FRAppIsLinearizeSaveAs
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsLinearizeSaveAs, ())

/**
 * @brief FRAppGetMetaDataOption
 * @details Check if compress the metaData when saving
 * @return   FS_BOOLEAN   <a>TRUE</a> Need compress, <a>FALSE</a> not need compress.
 * @note 
 * @see FRAppGetMetaDataOption
 */
INTERFACE(FS_BOOLEAN, FRAppGetMetaDataOption, ())

/**
 * @brief FRAppIsECMDocument
 * @details Get if the current document is opened from ECM,if return true then will return the ECM name.
 * @param[in]  pReaderDoc The input doc.
 * @param[in]  wsFilePath The filepath of the doc.
 * @param[out]  bsECMPluginName Return the ECM plugin name.
 * @return   FS_BOOL
 * @note 
 * @see FRAppGetMetaDataOption
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsECMDocument, (FR_Document pReaderDoc,  FS_WideString wsFilePath,  FS_ByteString* bsECMPluginName))

/**
 * @brief FRAppGetDocument
 * @details Get the document of the filepath. Just support for absolute path.
 * @param[in]  wsFilePath The filepath of the doc.
 * @return   FR_Document
 * @note 
 * @see FRAppGetMetaDataOption
 */
INTERFACE(FR_Document, FRAppGetDocument, (FS_WideString wsFilePath))

/**
 * @brief FRAppRunFieldFormat
 * @details Run javascript with the form field.
 * @param[in]  pReaderDoc The filepath of the doc.
 * @param[in]  commitKey The commit key type.
 * @param[in]  targetName The form fileld name.
 * @param[out]  value The filepath of the doc.
 * @param[in]  script The result after run javascript.
 * @param[in]  willCommit Set true will commit.
 * @return   FR_JSActionReturn
 * @note 
 * @see FRAppRunFieldFormat
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_JSActionReturn, FRAppRunFieldFormat, (FR_Document pReaderDoc,  FS_INT32 commitKey,  FS_LPCWSTR targetName,  FS_WideString* value,  FS_WideString script,  FS_BOOLEAN willCommit))

/**
 * @brief FRAppRemoveMapFormat2Doc
 * @details Remove the right panel data of the corresponding document
	* Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @param[in]  pReaderDoc The input doc.
 * @return   void
 * @note The function can only be used for Windows.
 * @see FRAppRemoveMapFormat2Doc
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppRemoveMapFormat2Doc, (FR_Document pReaderDoc))

/**
 * @brief FRAppDownLoadAddon
 * @details Download the required components.
	* Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @param[in]  strAddonName The Add on name.
 * @param[in]  pClientData The client data.
 * @param[in]  pFunc The callback when download finish.
 * @return   void
 * @note 
 * @see RemoveMapFormat2Doc
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppDownLoadAddon, (FS_ByteString strAddonName,  FS_LPVOID pClientData,  FRDownloadFinishCallbackProc pFunc))

/**
 * @brief FRAppGetDocProducer
 * @details Get producer of the application.
	* Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @param[out]  bsProducer The producer info.
 * @return   void
 * @note 
 * @see FRAppGetDocProducer
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppGetDocProducer, (FS_ByteString* bsProducer))

/**
 * @brief FRAppSetSignatureCheck
 * @details Set siganture check handler to app,that used to check document signature by app.
 * @param[in]  pSignatureCheck The input FR_ISignatureCheck object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use. This function is deprecated. It proceed in signature plugin.
 */
INTERFACE(void, FRAppSetSignatureCheck, (void* pSignatureCheck))

/**
 * @brief FRAppDocRunOCRFinish
 * @details Notify TVPreview that the page object has changed.
 * @param[in]  doc The input FR_Document object.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppDocRunOCRFinish, (FR_Document doc))

/**
 * @brief FRAppAddShareMessageBar
 * @details Add the information window above the document - Share window.
 * @param[in]  hFrame To add a childFrame handle to the message bar.
 * @param[in]  bsName The title of message bar.
 * @param[in]  createProc The callback of create child window.
 * @param[in]  destoryProc The callback of destroy child window.
 * @param[in]  data The client data of child windows in plugin.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRAppAddShareMessageBar, (FS_HWND hFrame,  FS_ByteString bsName,  FRShareMessageBarCreateProc createProc,  FRShareMessageBarDestoryProc destoryProc,  FS_LPVOID data))

/**
 * @brief FRAppShowShareMessageBar
 * @details Show the tile of information windows above the document.
 * @param[in]  hFrame To add a childFrame handle to the message bar.
 * @param[in]  bsName The title of message bar.
 * @param[in]  bShow TRUE: show message bar, FALSE: hide message bar.
 * @return   FS_BOOL       TRUE: Show message bar success.
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRAppShowShareMessageBar, (FS_HWND hFrame,  FS_ByteString bsName,  FS_BOOL bShow))

/**
 * @brief FRAppSetCurrentStartPageTab
 * @details Set current tab of start page, only activate state page tab the effect will be presented.
 * @param[in]  tabType Tab type of the start page.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppSetCurrentStartPageTab, (FR_STARTPAGETABTYPE tabType))

/**
 * @brief FRAppGetAppPath
 * @details Gets the execution file path of current running reader.
 * @param[out]  outAppPath The string buffer used to receive the app path.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppGetAppPath, (FS_WideString* outAppPath))

/**
 * @brief FRAppAddTrialDayDlgToCategory
 * @details Add trialday dialog to the name of RibbonCategory.
 * @param[in]  bsCategoryName The input category name.
 * @return   void.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppAddTrialDayDlgToCategory, (FS_ByteString bsCategoryName))

/**
 * @brief FRAppRegisterPanelToolHandler
 * @details Adds a navigation panel view into the Foxit Reader. 
	* The navigation panel view can be added after reader has started up.
 * @param[in]  panelViewCallbacks A panel page callback set. When the navigation panel occurs a event, reader will
	* call a corresponding callback to respond.
 * @return   FS_LPVOID   The returned value should be released by <a>FRAppReleaseNavPanelView</a>.
 * @note 
 */
INTERFACE(FS_LPVOID, FRAppRegisterPanelToolHandler, (FR_PanelViewCallbacks panelViewCallbacks))

/**
 * @brief FRAppIsTaskPaneShow
 * @details Check the specified right panel is show.
 * @param[in]  csName 
 * @return   FS_BOOLEAN   true means the specified task pane is show.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FRAppIsTaskPaneShow, (FS_LPCSTR csName))

/**
 * @brief FRAppGetCurrentDocumentByFrame
 * @details Get current document by input frame.
 * @param[in]  frameWnd The input frame of the doc.
 * @return   FR_Document.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Document, FRAppGetCurrentDocumentByFrame, (FS_LPVOID frameWnd))

/**
 * @brief FRAppSendUserDataMessageToApp
 * @details Send user data message to framework.
 * @param[in]  pUserData The client data.
 * @param[in]  pHander The input message handler.
 * @return   FS_INT32.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRAppSendUserDataMessageToApp, (FS_LPVOID pUserData,  FR_ReaderUserMessageHandler pHander))

/**
 * @brief FRAppShowReadMode
 * @details Switch to read mode.
 * @return   void.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppShowReadMode, ())

/**
 * @brief FRAppLoadUnitString
 * @details Get the multi language string.
 * @param[in]  nUnitType The input unit type.
 * @param[out]  unitStr Get the multi language string.
 * @return   void.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppLoadUnitString, (FS_INT32 nUnitType,  FS_WideString* unitStr))

/**
 * @brief FRAppSetECMFileDialogSensorDataType
 * @details Set the sensor datat type, it used to collect information.
 * @param[in]  ecmDidalog The input ECM dialog.
 * @param[in]  wsSensorDataType The input sensor data type.
 * @return   void.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppSetECMFileDialogSensorDataType, (FS_LPVOID ecmDidalog,  FS_LPCWSTR wsSensorDataType))

/**
 * @brief FRAppGetReplaceColors
 * @details Get the replace document color.
 * @param[out]  clrDocFore Get the text color.
 * @param[out]  clrDocBack Get background color.
 * @return   void.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppGetReplaceColors, (FS_COLORREF* clrDocFore,  FS_COLORREF* clrDocBack))

INTERFACE(FS_BOOL, FRAppGetFileTypeCanSupportOpen, (FS_LPCWSTR filePath))

/**
 * @brief FRAppOnDocPageLabelChange
 * @details Notify after page label changed.
 * @param[in]  pDoc The input FR_Document.
 * @return   void.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppOnDocPageLabelChange, (FR_Document pDoc))

/**
 * @brief FRAppSetCurrentToolByName
 * @details Set the current tool by name.
 * @param[in]  csToolname The input tool name.
 * @param[in]  bPersistent Whether need to use the tool persistent.
 * @return   void.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppSetCurrentToolByName, (FS_LPCSTR csToolname,  FS_BOOL bPersistent))

/**
 * @brief FRAppWillSignatureDoc
 * @details Nofity app will signature doc.
 * @param[in]  pDocument The input FR_Document.
 * @param[in]  outPath The out path when after signature doc.
 * @return   void.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppWillSignatureDoc, (FR_Document pDocument,  FS_LPCWSTR outPath))

/**
 * @brief FRAppDidSignatureDoc
 * @details Nofity app signature doc has finished.
 * @param[in]  outPath The out path when after signature doc.
 * @return   void.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppDidSignatureDoc, (FS_LPCWSTR outPath))

/**
 * @brief FRAppDeleteUnusedFont
 * @details When deleting useless font, notify fontmap to delete the corresponding font cache.
 * @param[in]  doc The input FPD_Document.
 * @param[in]  pFontDict The input font dict.
 * @return   void.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppDeleteUnusedFont, (FPD_Document doc,  FPD_Object pFontDict))

/**
 * @brief FRAppGetIsEditorApp
 * @details Check currently is editor.
 * @return   FS_BOOL   true: Current is editor, otherwise is reader.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppGetIsEditorApp, ())

/**
 * @brief FRAppOpenNewDocViewFrame
 * @details Create a view in tab window.
 * @param[in]  doc The input FPD_Document.
 * @param[in]  bMarkVisible The input FPD_Document.
 * @return   FS_LPVOID          It returns window hand of CFrameWnd.
 * @note 
 * @Deprecated    Internal use, it only for windows.
 */
INTERFACE(FS_LPVOID, FRAppOpenNewDocViewFrame, (FR_Document doc,  FS_BOOL bMarkVisible))

/**
 * @brief FRAppSetActiveTabByHWND
 * @details Set activate tab.
 * @param[in]  hTabWnd The input tab hwnd need to be activated.
 * @return   FS_BOOLEAN.
 * @note 
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOLEAN, FRAppSetActiveTabByHWND, (FS_HWND hTabWnd))

/**
 * @brief FRAppPopDocPropertyPage2
 * @details Pops up the doc property pages.
 * @param[in]  pageShowName The property page you want to display.
 * @param[in]  type The input property type.
 * @return   void
 * @note It used for Cross-platform interface.
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterDocPropertyPageHandler
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppPopDocPropertyPage2, (FS_LPCWSTR pageShowName,  FS_LPCWSTR type))

/**
 * @brief FRAppRegisterPluginEventHandler
 * @details Regist the handler of plugin event, like plugin unload.
 * @param[in]  callback The input FR_PluginEventCallbacks.
 * @return   FS_LPVOID        Return the plugin event handler.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0
 * @see FRAppRegisterPluginEventHandler
 */
INTERFACE(FS_LPVOID, FRAppRegisterPluginEventHandler, (FR_PluginEventCallbacks callback))

/**
 * @brief FRAppUnregisterPluginEventHandler
 * @details Unregist the plugin event handler.
 * @param[in]  handler The input plugin event handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0
 * @see FRAppUnregisterPluginEventHandler
 */
INTERFACE(void, FRAppUnregisterPluginEventHandler, (FS_LPVOID handler))

/**
 * @brief FRAppSetDocCanSaveSession
 * @details Set whether need to save doc session, like scale, zoom.
 * @param[in]  doc The input FR_Document.
 * @param[in]  bDocCanSaveSession TRUE: Need to save doc session.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppSetDocCanSaveSession, (FR_Document doc,  FS_BOOL bDocCanSaveSession))

/**
 * @brief FRAppGetBitmapFromClipboard
 * @details Get bitmap form clipboard.
 * @param[in]  hwnd The input FR_Document.
 * @param[out]  pBitamp Get the bitmap.
 * @return   FS_DIBitmap
 * @note It only used in windows. And need to call FSDIBitmapDestroy to release the FS_DIBitmap.
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_DIBitmap, FRAppGetBitmapFromClipboard, (FS_HWND hwnd))

/**
 * @brief FRAppUnRegisterSecurityHandler2
 * @details Unregisters a security handler.
 * @param[in]  name The name of the security handler.
 * @param[in]  callbacks The input callbacks need to unregiste.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 * @see FRAppRegisterSecurityHandler
 */
INTERFACE(void, FRAppUnRegisterSecurityHandler2, (FS_LPCSTR name,  FR_SecurityCallbacks callbacks))

/**
 * @brief FRAppToDecryptFile
 * @details Decrypt DRM file.
 * @param[in]  pszInPath The input DRM file path.
 * @param[out]  pszOutPath Get the temp decrypted file path.
 * @return   FS_BOOL    TRUE: Decrypt success.
 * @note It has been deprecated. User can use FREncryptedDocMgrToDecFile function instead.
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 * @see FRAppToDecryptFile
 */
INTERFACE(FS_BOOL, FRAppToDecryptFile, (FS_LPCWSTR pszInPath,  FS_WideString* pszOutPath))

/**
 * @brief FRAppDeleteDecryptFile
 * @details Delete the decrypted file path.
 * @param[in]  pszPath The input decrypted file path need to delete.
 * @return   FS_BOOL
 * @note It has been deprecated. User can use FREncryptedDocMgrToDelDecFile function instead.
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 * @see FRAppDeleteDecryptFile
 */
INTERFACE(FS_BOOL, FRAppDeleteDecryptFile, (FS_LPCWSTR pszPath))

/**
 * @brief FRAppUnRegisterPOEventHandler
 * @details UnRegister a hanlder called by the Foxit Reader to do the page organizing, such as adding pages, deleting pages, replacing pages and so on.
 * @param[in]  handler The input handler, it get from FRAppRegisterPOEventHandler.
 * @return   FS_BOOLEAN	TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @see FRAppUnRegisterPOEventHandler
 */
INTERFACE(FS_BOOLEAN, FRAppUnRegisterPOEventHandler, (FS_LPVOID handler))

/**
 * @brief FRAppUnRegisterTool
 * @details UnRegisters a tool into the Foxit Reader.
 * @param[in]  tool The <a>FR_Tool</a> object containing the tool's callbacks. This object
	* must not be freed after calling <a>FRAppRegisterTool</a>(), but must be remained.
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see FRAppRegisterTool
 */
INTERFACE(void, FRAppUnRegisterTool, (FR_Tool tool))

/**
 * @brief FRAppIsHideWndTask
 * @details Get whether the right panel is hidden.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsHideWndTask, ())

/**
 * @brief FRAppSetHideWndTask
 * @details Set whether the right panel is hidden.
 * @param[in]  bHideWndTask Set whether the right panel is hidden.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppSetHideWndTask, (FS_BOOL bHideWndTask))

/**
 * @brief FRAppRegisterDRMEventHandler
 * @details Registers the event notification to operate DRM file.
	* When operate DRM file, Editor will notify plugin to encrypt or decrypt.
 * @param[in]  callbacks The input FR_DRMEventCallbacks.
 * @return   FR_DRMEventHandler
 * @note Call FRAppUnRegisterDRMEventHandler to unregister the DRM event handler and release the memory.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see FRAppUnRegisterDRMEventHandler
 */
INTERFACE(FR_DRMEventHandler, FRAppRegisterDRMEventHandler, (FR_DRMEventCallbacks callbacks))

/**
 * @brief FRAppUnRegisterDRMEventHandler
 * @details Unregister the DRM event handler and release the memory.
 * @param[in]  handler The input FR_DRMEventHandler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see FRAppRegisterDRMEventHandler
 */
INTERFACE(void, FRAppUnRegisterDRMEventHandler, (FR_DRMEventHandler handler))

/**
 * @brief FRAppAddTrialDayDlgToCategory2
 * @details Add trialday dialog to the name of RibbonCategory.
 * @param[in]  bsCategoryName The input category name.
 * @param[in]  hMainFrm The input main frame.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppAddTrialDayDlgToCategory2, (FS_LPCSTR bsCategoryName,  FS_HWND hMainFrm))

/**
 * @brief FRAppCheckIsContinue
 * @details 
 * @return   FS_BOOL.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppCheckIsContinue, ())

/**
 * @brief FRAppCheckIsOldSubProcess
 * @details 
 * @return   FS_BOOL.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppCheckIsOldSubProcess, ())

/**
 * @brief FRAppGetAppDataRootPath
 * @details Gets the execution file path of current running reader.
 * @param[out]  outRootAppPath The string buffer used to receive the root path which Foxit Reader used to
	* store some application's data. It will be filled automaticly by reader.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppGetAppDataRootPath, (FS_WideString* outRootAppPath))

/**
 * @brief FRAppGetActiveTaskName
 * @details Get the name of the currently active right panel.
 * @param[out]  taskName Get the name of the currently active right panel.
 * @return   void
 * @note It only for windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppGetActiveTaskName, (FS_ByteString* taskName))

/**
 * @brief FRAppShowTaskPane2
 * @details Shows or hidden a task panel view.
 * @param[in]  info The input FR_ShowTaskPanelInfo.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @see FRAppShowTaskPane2
 */
INTERFACE(void, FRAppShowTaskPane2, (FR_ShowTaskPanelInfo info))

/**
 * @brief FRAppIsDocRedactSaveToSaveAs
 * @details Check the doc is save to  saveas.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @see FRAppIsDocRedactSaveToSaveAs
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsDocRedactSaveToSaveAs, ())

/**
 * @brief FRAppUpdateCustomRecentFileList
 * @details Update custom recent file list.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @see FRAppUpdateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppUpdateCustomRecentFileList, (FS_LPCSTR csRecentListName))

/**
 * @brief FRAppCreateColorDialog
 * @details Update custom recent file list.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @see FRAppUpdateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_CGWColorDialog, FRAppCreateColorDialog, (FS_BOOLEAN bOnlyFillClr,  FS_LPVOID wnd))

/**
 * @brief FRAppSetNotify
 * @details Update custom recent file list.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @see FRAppUpdateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_LPVOID, FRAppSetNotify, (FR_CGWColorDialog dialog,  FR_CGWColorNotifyCallbacks callbacks))

/**
 * @brief FRAppShowColorDialog
 * @details Update custom recent file list.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @see FRAppUpdateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppShowColorDialog, (FR_CGWColorDialog dialog))

/**
 * @brief FRAppIsTaskPaneInTab
 * @details Check if the task panel is on the right tab.
 * @param[in]  csName Check if the task panel is on the right tab.
 * @return   FS_BOOLEAN   true means is on the tab, otherwise is not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppUpdateCustomRecentFileList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRAppIsTaskPaneInTab, (FS_LPCSTR csName))

/**
 * @brief FRAppIsRunOfficeEmbeded
 * @details Check if it's run office embeded.
 * @return   FS_BOOLEAN   Check if it's run office embeded.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppIsRunOfficeEmbeded
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRAppIsRunOfficeEmbeded, ())

/**
 * @brief FRAppIsStartPageClosed
 * @details Check if startpage has been closed.
 * @return   FS_BOOL   Check if startpage has been closed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppIsStartPageClosed
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppIsStartPageClosed, ())

/**
 * @brief FRAppShowAboutPlugins
 * @details Check if startpage has been closed.
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppShowAboutPlugins
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppShowAboutPlugins, ())

/**
 * @brief FRAppSetFindResultHighlightColor
 * @details Set the highlight color of find result.
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppSetFindResultHighlightColor
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppSetFindResultHighlightColor, (FS_COLORREF clrHighlight))

/**
 * @brief FRAppGetFindResultHighlightColor
 * @details Get the highlight color of find result.
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppGetFindResultHighlightColor
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_COLORREF, FRAppGetFindResultHighlightColor, ())

/**
 * @brief FRAppSetFindResultHighlightOpacity
 * @details Set the highlight opacity of find result.
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppSetFindResultHighlightOpacity
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppSetFindResultHighlightOpacity, (FS_INT32 nOpacity))

/**
 * @brief FRAppGetFindResultHighlightOpacity
 * @details Get the highlight opacity of find result.
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppGetFindResultHighlightOpacity
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRAppGetFindResultHighlightOpacity, ())

/**
 * @brief FRAppRegisterStartPageEventHandler
 * @details Register start page event handler.
	*            When start page active or deactive, it will notify plugins.
 * @param[in]  handler The input FR_StartPageEventHandler.
 * @return   FS_BOOL
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppUnRegisterStartPageEventHandler
 */
INTERFACE(FS_BOOL, FRAppRegisterStartPageEventHandler, (FR_StartPageEventHandler handler))

/**
 * @brief FRAppUnRegisterStartPageEventHandler
 * @details Unregister start page event handler.
 * @param[in]  handler The input FR_StartPageEventHandler.
 * @return   FS_BOOL
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppRegisterStartPageEventHandler
 */
INTERFACE(FS_BOOL, FRAppUnRegisterStartPageEventHandler, (FR_StartPageEventHandler handler))

/**
 * @brief FRAppRegisterUndoEventHandler
 * @details Register undo/redo event handler.
	*            When editor operate undo or redo, it will notify plugins.
 * @param[in]  handler The input FR_UndoEventHandler.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppRegisterUndoEventHandler
 */
INTERFACE(void, FRAppRegisterUndoEventHandler, (FR_UndoEventHandler handler))

/**
 * @brief FRAppUnRegisterUndoEventHandler
 * @details UnRegister undo/redo event handler.
 * @param[in]  handler The input FR_UndoEventHandler.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppRegisterUndoEventHandler
 */
INTERFACE(void, FRAppUnRegisterUndoEventHandler, (FR_UndoEventHandler handler))

/**
 * @brief FRAppGetPDFAViewMode
 * @details Get PDFA view mode.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppGetPDFAViewMode
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRAppGetPDFAViewMode, ())

/**
 * @brief FRAppIsProtectedModeByPath
 * @details Get PDFA view mode.
 * @param[in]  csFilePath The input file path.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppIsProtectedModeByPath
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRAppIsProtectedModeByPath, (FS_LPCWSTR csFilePath))

/**
 * @brief FRAppAddFileAttachment2
 * @details Add file attachment to doc.
 * @param[in]  pDoc The input FR_Document obj.
 * @param[in]  info The input attachment info.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppAddFileAttachment2
 */
INTERFACE(FS_BOOLEAN, FRAppAddFileAttachment2, (FR_Document pDoc,  FR_FileAttachmentInfo info))

/**
 * @brief FRAppInitAESV4CryptoHandler
 * @details Init AESV4 crypto handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppInitAESV4CryptoHandler
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAppInitAESV4CryptoHandler, ())

/**
 * @brief FRAppCombinePDF
 * @details Combine specified files to PDF.
 * @param[in]  frCombineData The input FR_CombineData obj.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppCombinePDF
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRAppCombinePDF, (FR_CombineData* frCombineData))

/**
 * @brief FRAppLaunch
 * @details Launch specified file.
 * @param[in]  csFileName The input file name.
 * @param[in]  csParameters The input paramter.
 * @param[in]  csDefaultPath The input default path.
 * @param[in]  bOpenOrPrint Need open or print.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRAppLaunch
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRAppLaunch, (FS_LPCWSTR csFileName,  FS_LPCWSTR csParameters,  FS_LPCWSTR csDefaultPath,  FS_BOOLEAN bOpenOrPrint))

NumOfSelector(FRApp)
ENDENUM

//*****************************
/* Language HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRLanguageCreate
 * @details Creates a new <a>FR_Language</a> object.
 * @param[in]  hInstance The input plug-in instance handle.
 * @return   The <a>FR_Language</a> object created.
 * @note 
 */
INTERFACE(FR_Language, FRLanguageCreate, (HINSTANCE hInstance))

/**
 * @brief FRLanguageRelease
 * @details Releases the <a>FR_Language</a> object created by <a>FRLanguageCreate</a>().
 * @param[in]  language The input <a>FR_Language</a> object to be released.
 * @return   void
 * @note 
 * @see FRLanguageCreate
 */
INTERFACE(void, FRLanguageRelease, (FR_Language language))

/**
 * @brief FRLanguageChange
 * @details Changes the language of plug-in according to the input language ID. 
	* Plug-in can change the language when the <a>FRAppOnLangUIChange</a>() app event occurs.
	* You can get the current Foxit Reader language ID by <a>FRLanguageGetCurrentID</a>(), 
	* so that the language of plug-in can be the same as the Foxit Reader.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[in]  nID The input language ID.
 * @return   void
 * @note 
 * @see FRLanguageGetCurrentID
 */
INTERFACE(void, FRLanguageChange, (FR_Language language,  FS_INT32 nID))

/**
 * @brief FRLanguageGetCurrentID
 * @details Gets the current language ID of Foxit Reader.
 * @return   The current language ID of Foxit Reader. Like FR_LANGUAGE_NAME_DEFAULT.
 * @note 
 * @see FRLanguageChange
 */
INTERFACE(FS_INT32, FRLanguageGetCurrentID, ())

/**
 * @brief FRLanguageTranslateMenu
 * @details Translates the language of menu to another through <param>language</param>.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[in]  hMenu The input menu handle to be translated.
 * @param[in]  pzResName The input name of menu resource. The <Italic>MAKEINTRESOURCE</Italic> macro can be used to create this value.
 * @return   void
 * @note 
 */
INTERFACE(void, FRLanguageTranslateMenu, (FR_Language language,  HMENU hMenu,  FS_LPCWSTR pzResName))

/**
 * @brief FRLanguageTranslateDialog
 * @details Translates the language of dialog to another through <param>language</param>.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[in]  hWnd The input dialog handle to be translated.
 * @param[in]  pzResName The input name of dialog resource. The <Italic>MAKEINTRESOURCE</Italic> macro can be used to create this value.
 * @return   void
 * @note 
 */
INTERFACE(void, FRLanguageTranslateDialog, (FR_Language language,  HWND hWnd,  FS_LPCWSTR pzResName))

/**
 * @brief FRLanguageLoadString
 * @details Loads the specified string. Set the <param>buffer</param> <a>NULL</a> to get the length of the string.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[in]  nId Specifies the integer identifier of the string to be loaded.
 * @param[out]  buffer It receives the string loaded.
 * @param[in]  len Specifies the length of the <param>buffer</param> in bytes.
 * @return   The length of the string in bytes.
 * @note 
 */
INTERFACE(FS_INT32, FRLanguageLoadString, (FR_Language language,  FS_INT32 nId,  void* buffer,  FS_INT32 len))

/**
 * @brief FRLanguageLoadVersionRes
 * @details Loads the file description and the legal copyright of the plug-in.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[out]  outFileDes It receives the file description.
 * @param[out]  outLegalCopyright It receives the legal copyright.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FRLanguageLoadVersionRes, (FR_Language language,  FS_WideString* outFileDes,  FS_WideString* outLegalCopyright))

/**
 * @brief FRLanguageGetLocalLangName
 * @details Gets the local language name.
 * @param[out]  outName It receives the local language name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FRLanguageGetLocalLangName, (FS_WideString* outName))

/**
 * @brief FRLanguageTranslateDialog2
 * @details Translates the language of dialog to another through <param>language</param>.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[in]  hWnd The input dialog handle to be translated.
 * @param[in]  pzResName The input name of dialog resource. The <Italic>MAKEINTRESOURCE</Italic> macro can be used to create this value.
 * @param[in]  bAutoAdpt Whether to adapt to the DPI setting or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FRLanguageTranslateDialog2, (FR_Language language,  HWND hWnd,  FS_LPCWSTR pzResName,  FS_BOOL bAutoAdpt))

/**
 * @brief FRLanguageModifyLogFont
 * @details Modifies the attributes of a font to match the system language when the application language matches the system language, 
	* otherwise the font name will be set Tahoma as default.
 * @param[in,out]  lf The input attributes of a font to be modified.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(void, FRLanguageModifyLogFont, (LOGFONT* lf))

/**
 * @brief FRLanguageFormatEx
 * @details Formats a translated string so that the arguments list can match the format.
 * @param[out]  outFormat It receives the format string.
 * @param[in]  lpszFormat Specifies a format-control string.
 * @param[in]  ... arguments list.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(void, FRLanguageFormatEx, (FS_WideString* outFormat,  FS_LPCWSTR lpszFormat,  ...))

/**
 * @brief FRLanguageJSPluginGetMessage
 * @details Gets the message string for javascript plug-in.
 * @param[in]  lpsModuleName The input javascript plug-in module name.
 * @param[in]  lpsMessageName The input message name.
 * @param[out]  outMessage It receives the message string.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(void, FRLanguageJSPluginGetMessage, (FS_LPCSTR lpsModuleName,  FS_LPCSTR lpsMessageName,  FS_WideString* outMessage))

/**
 * @brief FRLanguageReleaseDialogUIFont
 * @details When the window is released, the interface needs to be called for GDI recycling.
 * @param[in]  hWnd The input HWND of the dialog.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRLanguageReleaseDialogUIFont, (FS_HWND hWnd))

NumOfSelector(FRLanguage)
ENDENUM

//*****************************
/* UIProgress HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRUIProgressCreate
 * @details Creates a new <a>FR_UIProgress</a> object.
 * @param[in]  hParent The parent window handle of the progress bar.
 * @param[in]  bShowCancelButton Whether to show the cancel button on the progress bar.
 * @return   The <a>FR_UIProgress</a> object created.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FR_UIProgress, FRUIProgressCreate, (HWND hParent,  FS_BOOL bShowCancelButton))

/**
 * @brief FRUIProgressSetText
 * @details Set the text shown in the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @param[in]  lpText The text shown in the progress bar.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRUIProgressSetText, (FR_UIProgress UIProgress,  FS_LPCWSTR lpText))

/**
 * @brief FRUIProgressSetRange
 * @details Set the range of the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @param[in]  nLower The minimize value of the range.
 * @param[in]  nUpper The maximize value of the range.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRUIProgressSetRange, (FR_UIProgress UIProgress,  FS_INT32 nLower,  FS_INT32 nUpper))

/**
 * @brief FRUIProgressSetCurrValue
 * @details Set the current value of the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @param[in]  nPos The current value of the progress bar.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRUIProgressSetCurrValue, (FR_UIProgress UIProgress,  FS_INT32 nPos))

/**
 * @brief FRUIProgressPeekAndPump
 * @details Peek and pump.
 * @param[in]  UIProgress The input progress bar.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRUIProgressPeekAndPump, (FR_UIProgress UIProgress))

/**
 * @brief FRUIProgressIsCancelled
 * @details Whether the progress bar is cancelled or not.
 * @param[in]  UIProgress The input progress bar.
 * @return   Whether the progress bar is cancelled or not.
 * @note 
 */
INTERFACE(FS_BOOL, FRUIProgressIsCancelled, (FR_UIProgress UIProgress))

/**
 * @brief FRUIProgressGetCurrentValue
 * @details The current value of the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @return   Get the current value of the progress bar.
 * @note 
 */
INTERFACE(FS_INT32, FRUIProgressGetCurrentValue, (FR_UIProgress UIProgress))

/**
 * @brief FRUIProgressDestroy
 * @details Destroy the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRUIProgressDestroy, (FR_UIProgress UIProgress))

/**
 * @brief FRUIProgressDoCancel
 * @details To cancel the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @param[in]  bKill Whether to kill the progress bar.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRUIProgressDoCancel, (FR_UIProgress UIProgress,  FS_BOOL bKill))

/**
 * @brief FRUIProgressCreate2
 * @details Creates a new <a>FR_UIProgress</a> object.
 * @param[in]  hParent The parent window handle of the progress bar.
 * @param[in]  bShowCancelButton Whether to show the cancel button on the progress bar.
 * @param[in]  bRevertFocus Whether to revert the focus to the original focused window.
 * @return   The <a>FR_UIProgress</a> object created.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FR_UIProgress, FRUIProgressCreate2, (HWND hParent,  FS_BOOL bShowCancelButton,  FS_BOOL bRevertFocus))

/**
 * @brief FRUIProgressCreate3
 * @details Creates a new <a>FR_UIProgress</a> object.
 * @param[in]  hParent The parent window handle of the progress bar.
 * @param[in]  option Set some progress option when create UIProgress.
 * @return   The <a>FR_UIProgress</a> object created.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_UIProgress, FRUIProgressCreate3, (HWND hParent,  FR_UIProgressOption option))

/**
 * @brief FRUIProgressGetHwnd
 * @details Get the HWND of the UIProgress.
 * @param[in]  UIProgress The input progress bar.
 * @return   FS_HWND
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_HWND, FRUIProgressGetHwnd, (FR_UIProgress UIProgress))

/**
 * @brief FRUIProgressSetSecondLineText
 * @details Set second line text.
 * @param[in]  UIProgress The input progress bar.
 * @param[in]  lpText The line text to set.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRUIProgressSetSecondLineText, (FR_UIProgress UIProgress,  FS_LPCWSTR lpText))

/**
 * @brief FRUIProgressGetText
 * @details Get text of the progress.
 * @param[in]  UIProgress The input progress bar.
 * @param[out]  bsText Get the text of input progress bar.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRUIProgressGetText, (FR_UIProgress UIProgress,  FS_WideString* bsText))

NumOfSelector(FRUIProgress)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* Internal HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOL, FRInternalDoPrintCommentSummary, (FR_Document doc,  FS_LPCWSTR lpFilePath))

INTERFACE(FS_BOOL, FRInternalOptimizerModuleFlatDocument, (FPD_Document pSourDoc,  FS_INT32* pPageAry,  FS_INT32 pageSize,  void* xUserData))

INTERFACE(FS_BOOL, FRInternalGlobalWndOpenPassWord, (FS_WideString wsFileName,  FS_BOOL bOwnerPass,  FS_WideString* wsPassWord,  FS_LPCWSTR wsDescription,  FS_LPVOID pParent))

INTERFACE(FS_BOOL, FRInternalGlobalWndCheckFileSize, (FPD_Document pDoc,  FS_WideString wsFilePath,  FS_BOOL bShowMsgBox,  FS_INT32* nChoice,  FS_BOOL bShowCheckBox,  FS_BOOL* bChecked,  FS_INT32 nPageLimit,  FS_INT32 nFileSizeLimit))

INTERFACE(FS_BOOL, FRInternalOpenCertifiedPDF, (FPD_Parser parser,  FS_LPCWSTR lpwsPDFPath))

INTERFACE(void*, FRInternalPWLWndCreationParamNew, ())

INTERFACE(void, FRInternalPWLWndCreationParamSetFontMap, (void* pCreationParam,  FR_Edit_FontMap fontMap))

INTERFACE(void, FRInternalPWLWndCreationParamSetFontIndex, (void* pCreationParam,  FS_INT32 nFontIndex))

INTERFACE(void, FRInternalPWLWndCreationParamSetFlag, (void* pCreationParam,  FS_DWORD dwFlags))

INTERFACE(void, FRInternalPWLWndCreationParamSetFontSize, (void* pCreationParam,  FS_FLOAT fFontSize))

INTERFACE(void, FRInternalPWLWndCreationParamSetTextColor, (void* pCreationParam,  FS_INT32 r,  FS_INT32 g,  FS_INT32 b))

INTERFACE(void, FRInternalPWLWndCreationParamSetTextColorII, (void* pCreationParam,  FS_INT32 type,  FS_FLOAT color1,  FS_FLOAT color2,  FS_FLOAT color3,  FS_FLOAT color4))

INTERFACE(void, FRInternalPWLWndCreationParamSetRect, (void* pCreationParam,  FS_FloatRect rect))

INTERFACE(void, FRInternalPWLWndCreationParamDestroy, (void* pCreationParam))

INTERFACE(void*, FRInternalPWLWndEditNew, (void* pCreationParam))

INTERFACE(void, FRInternalPWLWndEditSetTextColor, (void* pEdit,  FS_INT32 r,  FS_INT32 g,  FS_INT32 b))

INTERFACE(void, FRInternalPWLWndEditSetTextColorII, (void* pEdit,  FS_INT32 type,  FS_FLOAT color1,  FS_FLOAT color2,  FS_FLOAT color3,  FS_FLOAT color4))

INTERFACE(void, FRInternalPWLWndEditSetText, (void* pEdit,  FS_LPCWSTR csText))

INTERFACE(void, FRInternalPWLWndEditGetContentRect, (void* pEdit,  FS_FloatRect* pRect))

INTERFACE(void, FRInternalPWLWndEditGeneratePageObjects, (void* pEdit,  void* pPageObjects,  FS_FLOAT xx,  FS_FLOAT yy,  FS_PtrArray* outObjArray))

INTERFACE(void, FRInternalPWLWndEditGeneratePageObjectsII, (void* pEdit,  void* pPageObjects,  FS_FLOAT xx,  FS_FLOAT yy))

INTERFACE(void, FRInternalPWLWndEditDestroy, (void* pEdit))

INTERFACE(void, FRInternalSetReviewJS, (FR_Document frDoc,  FS_LPCWSTR lpwsScriptName,  FS_LPCWSTR lpwsScript))

INTERFACE(void, FRInternalGetReviewJS, (FR_Document frDoc,  FS_WideString* cwScriptName,  FS_WideString* cwScript))

INTERFACE(FS_BOOL, FRInternalRemoveReviewJS, (FR_Document frDoc,  FS_LPCWSTR lpwsScriptName))

INTERFACE(FS_BOOL, FRInternalExportAnnotToXFDF, (void* pAnnot,  FS_XMLElement xmlElement))

INTERFACE(void*, FRInternalImprotAnnotFromXFDF, (FR_Document frDoc,  FS_XMLElement xmlAnnot,  FS_BOOL bSendAnnotChangeToNotify))

INTERFACE(void, FRInternalEnableAnnot, (void* pAnnot,  FS_BOOL bEnable))

INTERFACE(FS_BOOL, FRInternalDeleteAnnot, (FR_Document frDoc,  FS_INT32 nPageIndex,  FS_LPCWSTR lpwsAnnotName,  FS_BOOL bSendAnnotChangeToNotify))

INTERFACE(FS_BOOL, FRInternalUpdateAnnotAuthor, (FR_Document frDoc,  FS_LPCWSTR lpwsAuthorName))

INTERFACE(FS_BOOL, FRInternalUpdateAnnotAuthor2, (FR_Annot frAnnot,  FS_LPCWSTR lpwsAuthorName))

INTERFACE(void*, FRInternalSetIcommentsAnnotNotify, (FR_CommentsAnnotOprtNotifyCallbacks callbacks))

INTERFACE(FS_BOOL, FRInternalRemoveIcommentsAnnotNotify, (void* pNotify))

INTERFACE(void, FRInternalShowChildScrollBar, (FS_BOOL bShow,  HWND hParentWnd))

INTERFACE(void, FRInternalChangeZoomScaleInfo, (double dbScale,  FS_BOOL bReDraw))

INTERFACE(FS_BOOL, FRInternalAdvEditing, (FS_INT32 iPage,  FS_FloatRect pdfRect))

INTERFACE(FS_BOOL, FRInternalToolbarModuleGetSysFontFaceName, (FS_LPCWSTR lpwsScriptName,  FS_WideString* outName))

INTERFACE(FR_VTWordPlace, FRInternalWordPlaceNew, (FS_INT32 nSecIndex,  FS_INT32 nLineIndex,  FS_INT32 nWordIndex))

INTERFACE(void, FRInternalWordPlaceDestroy, (FR_VTWordPlace wordPlace))

INTERFACE(void, FRInternalWordPlaceSetDefault, (FR_VTWordPlace wordPlace))

INTERFACE(FS_BOOL, FRInternalWordPlaceEqual, (FR_VTWordPlace wordPlace,  FR_VTWordPlace destWordPlace))

INTERFACE(FS_INT32, FRInternalWordPlaceWordCmp, (FR_VTWordPlace wordPlace,  FR_VTWordPlace destWordPlace))

INTERFACE(FS_INT32, FRInternalWordPlaceLineCmp, (FR_VTWordPlace wordPlace,  FR_VTWordPlace destWordPlace))

INTERFACE(FS_INT32, FRInternalWordPlaceSecCmp, (FR_VTWordPlace wordPlace,  FR_VTWordPlace destWordPlace))

INTERFACE(void, FRInternalWordPlaceSetSectionIndex, (FR_VTWordPlace wordPlace,  FS_INT32 nSecIndex))

INTERFACE(FS_INT32, FRInternalWordPlaceGetSectionIndex, (FR_VTWordPlace wordPlace))

INTERFACE(void, FRInternalWordPlaceSetLineIndex, (FR_VTWordPlace wordPlace,  FS_INT32 nLineIndex))

INTERFACE(FS_INT32, FRInternalWordPlaceGetLineIndex, (FR_VTWordPlace wordPlace))

INTERFACE(void, FRInternalWordPlaceSetWordIndex, (FR_VTWordPlace wordPlace,  FS_INT32 nWordIndex))

INTERFACE(FS_INT32, FRInternalWordPlaceGetWordIndex, (FR_VTWordPlace wordPlace))

INTERFACE(FR_VTWordRange, FRInternalWordRangeNew, ())

INTERFACE(void, FRInternalWordRangeDestroy, (FR_VTWordRange wordRange))

INTERFACE(void, FRInternalWordRangeSetDefault, (FR_VTWordRange wordRange))

INTERFACE(void, FRInternalWordRangeSet, (FR_VTWordRange wordRange,  FR_VTWordPlace begin,  FR_VTWordPlace end))

INTERFACE(void, FRInternalWordRangeSetBeginPos, (FR_VTWordRange wordRange,  FR_VTWordPlace begin))

INTERFACE(void, FRInternalWordRangeSetEndPos, (FR_VTWordRange wordRange,  FR_VTWordPlace end))

INTERFACE(FS_BOOL, FRInternalWordRangeIsExist, (FR_VTWordRange wordRange))

INTERFACE(FS_BOOL, FRInternalWordRangeEqual, (FR_VTWordRange wordRange,  FR_VTWordRange destWordRange))

INTERFACE(void, FRInternalWordRangeSwapWordPlace, (FR_VTWordRange wordRange))

INTERFACE(FR_VTWordPlace, FRInternalWordRangeGetBeginPos, (FR_VTWordRange wordRange))

INTERFACE(FR_VTWordPlace, FRInternalWordRangeGetEndPos, (FR_VTWordRange wordRange))

INTERFACE(FR_VTSecProps, FRInternalSecPropsNew, (FS_FLOAT lineLeading,  FS_FLOAT lineIndent,  FS_INT32 alignment,  FS_BOOL softreturn,  FS_BOOL bRTL))

INTERFACE(FR_VTSecProps, FRInternalSecPropsNewII, (FR_VTSecProps otherSecProps))

INTERFACE(void, FRInternalSecPropsDestroy, (FR_VTSecProps secProps))

INTERFACE(void, FRInternalSecPropsSetLineLeading, (FR_VTSecProps secProps,  FS_FLOAT lineLeading))

INTERFACE(FS_FLOAT, FRInternalSecPropsGetLineLeading, (FR_VTSecProps secProps))

INTERFACE(void, FRInternalSecPropsSetLineIndent, (FR_VTSecProps secProps,  FS_FLOAT lineIndent))

INTERFACE(FS_FLOAT, FRInternalSecPropsGetLineIndent, (FR_VTSecProps secProps))

INTERFACE(void, FRInternalSecPropsSetAlignment, (FR_VTSecProps secProps,  FS_INT32 alignment))

INTERFACE(FS_INT32, FRInternalSecPropsGetAlignment, (FR_VTSecProps secProps))

INTERFACE(void, FRInternalSecPropsSetSoftReturn, (FR_VTSecProps secProps,  FS_BOOL softreturn))

INTERFACE(FS_BOOL, FRInternalSecPropsGetSoftReturn, (FR_VTSecProps secProps))

INTERFACE(void, FRInternalSecPropsSetRTL, (FR_VTSecProps secProps,  FS_BOOL bRTL))

INTERFACE(FS_BOOL, FRInternalSecPropsGetRTL, (FR_VTSecProps secProps))

INTERFACE(FR_VTWordProps, FRInternalWordPropsNew, (FS_INT32	fontIndex,  FS_FLOAT fontSize,  FS_COLORREF wordColor,  FS_INT32 scriptType,  FS_INT32 wordStyle,  FS_FLOAT charSpace,  FS_FLOAT horzScale,  FS_FLOAT xOffset,  FS_FLOAT yOffset,  FS_COLORREF strokeColor,  FS_INT32 renderingMode,  FS_FLOAT lineWidth,  FS_FLOAT wordspace,  FS_DWORD dwCharCode,  short nAlphal))

INTERFACE(FR_VTWordProps, FRInternalWordPropsNewII, (FR_VTWordProps otherWordProps))

INTERFACE(void, FRInternalWordPropsDestroy, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetFontIndex, (FR_VTWordProps wordProps,  FS_INT32 fontIndex))

INTERFACE(FS_INT32, FRInternalWordPropsGetFontIndex, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetFontSize, (FR_VTWordProps wordProps,  FS_FLOAT fontSize))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetFontSize, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetWordColor, (FR_VTWordProps wordProps,  FS_COLORREF wordColor))

INTERFACE(FS_COLORREF, FRInternalWordPropsGetWordColor, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetStrokeColor, (FR_VTWordProps wordProps,  FS_COLORREF dwStrokeColor))

INTERFACE(FS_COLORREF, FRInternalWordPropsGetStrokeColor, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetScriptType, (FR_VTWordProps wordProps,  FS_INT32 nScriptType))

INTERFACE(FS_INT32, FRInternalWordPropsGetScriptType, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetWordStyle, (FR_VTWordProps wordProps,  FS_INT32 nWordStyle))

INTERFACE(FS_INT32, FRInternalWordPropsGetWordStyle, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetCharSpace, (FR_VTWordProps wordProps,  FS_FLOAT fCharSpace))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetCharSpace, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetHorzScale, (FR_VTWordProps wordProps,  FS_FLOAT fHorzScale))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetHorzScale, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetXOffset, (FR_VTWordProps wordProps,  FS_FLOAT fXOffset))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetXOffset, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetYOffset, (FR_VTWordProps wordProps,  FS_FLOAT fYOffset))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetYOffset, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetRenderingMode, (FR_VTWordProps wordProps,  FS_INT32 nRenderingMode))

INTERFACE(FS_INT32, FRInternalWordPropsGetRenderingMode, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetClientData, (FR_VTWordProps wordProps,  void* pClientData))

INTERFACE(void*, FRInternalWordPropsGetClientData, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetLineWidth, (FR_VTWordProps wordProps,  FS_FLOAT fLineWidth))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetLineWidth, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetWordSpace, (FR_VTWordProps wordProps,  FS_FLOAT fWordSpace))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetWordSpace, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetCharCode, (FR_VTWordProps wordProps,  FS_DWORD dwCharCode))

INTERFACE(FS_DWORD, FRInternalWordPropsGetCharCode, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetAlpha, (FR_VTWordProps wordProps,  short nAlpha))

INTERFACE(short, FRInternalWordPropsGetAlpha, (FR_VTWordProps wordProps))

INTERFACE(FR_VTWord, FRInternalWordNew, ())

INTERFACE(void, FRInternalWordDestroy, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWord, (FR_VTWord VTWord,  FS_WORD word))

INTERFACE(FS_WORD, FRInternalWordGetWord, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWordDisplay, (FR_VTWord word,  FS_WORD WordDisplay))

INTERFACE(FS_WORD, FRInternalWordGetWordDisplay, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetBidiOrder, (FR_VTWord word,  short nBidiOrder))

INTERFACE(short, FRInternalWordGetBidiOrder, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetCharset, (FR_VTWord word,  FS_INT32 nCharset))

INTERFACE(FS_INT32, FRInternalWordGetCharset, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWordPlace, (FR_VTWord word,  FR_VTWordPlace WordPlace))

INTERFACE(FR_VTWordPlace, FRInternalWordGetWordPlace, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWordPoint, (FR_VTWord word,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(void, FRInternalWordGetWordPoint, (FR_VTWord word,  FS_FLOAT* x,  FS_FLOAT* y))

INTERFACE(void, FRInternalWordSetAscent, (FR_VTWord word,  FS_FLOAT fAscent))

INTERFACE(FS_FLOAT, FRInternalWordGetAscent, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetDescent, (FR_VTWord word,  FS_FLOAT fDescent))

INTERFACE(FS_FLOAT, FRInternalWordGetDescent, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWidth, (FR_VTWord word,  FS_FLOAT fWidth))

INTERFACE(FS_FLOAT, FRInternalWordGetWidth, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetFontIndex, (FR_VTWord word,  FS_INT32 nFontIndex))

INTERFACE(FS_INT32, FRInternalWordGetFontIndex, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetFontSize, (FR_VTWord word,  FS_FLOAT fFontSize))

INTERFACE(FS_FLOAT, FRInternalWordGetFontSize, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWordProps, (FR_VTWord word,  FR_VTWordProps wordProps))

INTERFACE(FR_VTWordProps, FRInternalWordGetWordProps, (FR_VTWord word))

INTERFACE(FR_VTLine, FRInternalLineNew, ())

INTERFACE(void, FRInternalLineDestroy, (FR_VTLine line))

INTERFACE(void, FRInternalLineSetStartWordPlace, (FR_VTLine line,  FR_VTWordPlace lineplace))

INTERFACE(FR_VTWordPlace, FRInternalLineGetStartWordPlace, (FR_VTLine line))

INTERFACE(void, FRInternalLineSetEndWordPlace, (FR_VTLine line,  FR_VTWordPlace lineEnd))

INTERFACE(FR_VTWordPlace, FRInternalLineGetEndWordPlace, (FR_VTLine line))

INTERFACE(void, FRInternalLineSetOriginalPosition, (FR_VTLine line,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(void, FRInternalLineGetOriginalPosition, (FR_VTLine line,  FS_FLOAT* x,  FS_FLOAT* y))

INTERFACE(void, FRInternalLineSetWidth, (FR_VTLine line,  FS_FLOAT fLineWidth))

INTERFACE(FS_FLOAT, FRInternalLineGetWidth, (FR_VTLine line))

INTERFACE(void, FRInternalLineSetAscent, (FR_VTLine line,  FS_FLOAT fLineAscent))

INTERFACE(FS_FLOAT, FRInternalLineGetAscent, (FR_VTLine line))

INTERFACE(void, FRInternalLineSetDescent, (FR_VTLine line,  FS_FLOAT fLineDescent))

INTERFACE(FS_FLOAT, FRInternalLineGetDescent, (FR_VTLine line))

INTERFACE(FR_VTSection, FRInternalSectionNew, ())

INTERFACE(void, FRInternalSectionDestroy, (FR_VTSection section))

INTERFACE(void, FRInternalSectionSetStartWordPlace, (FR_VTSection section,  FR_VTWordPlace secplace))

INTERFACE(FR_VTWordPlace, FRInternalSectionGetStartWordPlace, (FR_VTSection section))

INTERFACE(void, FRInternalSectionSetRect, (FR_VTSection section,  FS_FloatRect rect))

INTERFACE(FS_FloatRect, FRInternalSectionGetRect, (FR_VTSection section))

INTERFACE(void, FRInternalSectionSetSectionProperties, (FR_VTSection section,  FR_VTSecProps SecProps))

INTERFACE(FR_VTSecProps, FRInternalSectionGetSectionProperties, (FR_VTSection section))

INTERFACE(void, FRInternalSectionSetWordProperties, (FR_VTSection section,  FR_VTWordProps WordProps))

INTERFACE(FR_VTWordProps, FRInternalSectionGetWordProperties, (FR_VTSection section))

INTERFACE(FS_BOOL, FRInternalVTIteratorNextWord, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorPrevWord, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorNextLine, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorPrevLine, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorNextSection, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorPrevSection, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorGetWord, (FR_VariableText_Iterator iterator,  FR_VTWord* outWord))

INTERFACE(FS_BOOL, FRInternalVTIteratorSetWord, (FR_VariableText_Iterator iterator,  FR_VTWord word))

INTERFACE(FS_BOOL, FRInternalVTIteratorGetLine, (FR_VariableText_Iterator iterator,  FR_VTLine* outLine))

INTERFACE(FS_BOOL, FRInternalVTIteratorGetSection, (FR_VariableText_Iterator iterator,  FR_VTSection* outSection))

INTERFACE(FS_BOOL, FRInternalVTIteratorSetSection, (FR_VariableText_Iterator iterator,  FR_VTSection section))

INTERFACE(void, FRInternalVTIteratorSetAt, (FR_VariableText_Iterator iterator,  FS_INT32 nWordIndex))

INTERFACE(void, FRInternalVTIteratorSetAtII, (FR_VariableText_Iterator iterator,  FR_VTWordPlace place))

INTERFACE(void, FRInternalVTIteratorGetAt, (FR_VariableText_Iterator iterator,  FR_VTWordPlace* outWordPlace))

INTERFACE(FS_BOOL, FRInternalVTIteratorGetDisplayWord, (FR_VariableText_Iterator iterator,  FR_VTWord* outWord))

INTERFACE(FR_VariableText, FRInternalVariableTextNew, ())

INTERFACE(void, FRInternalVariableTextDestroy, (FR_VariableText variableText))

INTERFACE(FR_VariableText_Provider, FRInternalVariableTextProviderNew, (FR_VariableTextProviderCallbacks callbacks))

INTERFACE(void, FRInternalVariableTextProviderDestroy, (FR_VariableText_Provider provider))

INTERFACE(FR_VariableText_Provider, FRInternalVariableTextSetProvider, (FR_VariableText variableText,  FR_VariableText_Provider provider))

INTERFACE(FR_VariableText_Iterator, FRInternalVariableTextGetIterator, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextSetPlateRect, (FR_VariableText variableText,  FS_FloatRect rect,  FS_BOOL bVerticalWriting))

INTERFACE(FS_BOOL, FRInternalVariableTextIsVerticalWriting, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextSetAlignment, (FR_VariableText variableText,  FS_INT32 nFormat))

INTERFACE(void, FRInternalVariableTextSetPasswordChar, (FR_VariableText variableText,  FS_WORD wSubWord))

INTERFACE(void, FRInternalVariableTextSetLimitChar, (FR_VariableText variableText,  FS_INT32 nLimitChar))

INTERFACE(void, FRInternalVariableTextSetCharArray, (FR_VariableText variableText,  FS_INT32 nCharArray))

INTERFACE(void, FRInternalVariableTextSetCharSpace, (FR_VariableText variableText,  FS_FLOAT fCharSpace))

INTERFACE(void, FRInternalVariableTextSetWordSpace, (FR_VariableText variableText,  FS_FLOAT fWordSpace))

INTERFACE(void, FRInternalVariableTextSetHorzScale, (FR_VariableText variableText,  FS_FLOAT fHorzScale))

INTERFACE(void, FRInternalVariableTextSetMultiLine, (FR_VariableText variableText,  FS_BOOL bMultiLine))

INTERFACE(void, FRInternalVariableTextSetAutoReturn, (FR_VariableText variableText,  FS_BOOL bAuto))

INTERFACE(void, FRInternalVariableTextSetAutoFontSize, (FR_VariableText variableText,  FS_BOOL bAuto))

INTERFACE(void, FRInternalVariableTextSetFontSize, (FR_VariableText variableText,  FS_FLOAT fFontSize))

INTERFACE(void, FRInternalVariableTextSetLineLeading, (FR_VariableText variableText,  FS_FLOAT fLineLeading))

INTERFACE(void, FRInternalVariableTextSetRichText, (FR_VariableText variableText,  FS_BOOL bRichText))

INTERFACE(void, FRInternalVariableTextSetDirectionRTL, (FR_VariableText variableText,  FS_BOOL bRTL,  FR_VTWordRange PlaceRange))

INTERFACE(void, FRInternalVariableTextInitialize, (FR_VariableText variableText))

INTERFACE(FS_BOOL, FRInternalVariableTextIsValid, (FR_VariableText variableText))

INTERFACE(FS_BOOL, FRInternalVariableTextIsRichText, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextRearrangeAll, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextRearrangePart, (FR_VariableText variableText,  FR_VTWordRange PlaceRange))

INTERFACE(void, FRInternalVariableTextResetAll, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextSetText, (FR_VariableText variableText,  FS_LPCWSTR text,  FS_INT32 charset,  FR_VTSecProps pSecProps,  FR_VTWordProps pWordProps))

INTERFACE(void, FRInternalVariableTextInsertWord, (FR_VariableText variableText,  FR_VTWordPlace place,  FS_WORD word,  FS_INT32 charset,  FR_VTWordProps pWordProps,  FS_BOOL bNeedTransform,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextInsertSection, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTSecProps pSecProps,  FR_VTWordProps pWordProps,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextInsertText, (FR_VariableText variableText,  FR_VTWordPlace place,  FS_LPCWSTR text,  FS_INT32 charset,  FR_VTSecProps pSecProps,  FR_VTWordProps pWordProps,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextDeleteWords, (FR_VariableText variableText,  FR_VTWordRange PlaceRange,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextDeleteWord, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextBackSpaceWord, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(FS_FloatRect, FRInternalVariableTextGetPlateRect, (FR_VariableText variableText))

INTERFACE(FS_FloatRect, FRInternalVariableTextGetContentRect, (FR_VariableText variableText))

INTERFACE(FS_INT32, FRInternalVariableTextGetTotalWords, (FR_VariableText variableText))

INTERFACE(FS_FLOAT, FRInternalVariableTextGetFontSize, (FR_VariableText variableText))

INTERFACE(FS_INT32, FRInternalVariableTextGetAlignment, (FR_VariableText variableText))

INTERFACE(FS_FLOAT, FRInternalVariableTextGetWordSpace, (FR_VariableText variableText))

INTERFACE(FS_WORD, FRInternalVariableTextGetPasswordChar, (FR_VariableText variableText))

INTERFACE(FS_INT32, FRInternalVariableTextGetCharArray, (FR_VariableText variableText))

INTERFACE(FS_INT32, FRInternalVariableTextGetLimitChar, (FR_VariableText variableText))

INTERFACE(FS_BOOL, FRInternalVariableTextIsMultiLine, (FR_VariableText variableText))

INTERFACE(FS_BOOL, FRInternalVariableTextIsAutoReturn, (FR_VariableText variableText))

INTERFACE(FS_FLOAT, FRInternalVariableTextGetHorzScale, (FR_VariableText variableText))

INTERFACE(FS_FLOAT, FRInternalVariableTextGetCharSpace, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextGetBeginWordPlace, (FR_VariableText variableText,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetEndWordPlace, (FR_VariableText variableText,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetPrevWordPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetNextWordPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextSearchWordPlace, (FR_VariableText variableText,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetUpWordPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetDownWordPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetLineBeginPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetLineEndPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetSectionBeginPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetSectionEndPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextUpdateWordPlace, (FR_VariableText variableText,  FR_VTWordPlace place))

INTERFACE(void, FRInternalVariableTextAjustLineHeader, (FR_VariableText variableText,  FR_VTWordPlace place,  FS_BOOL bPrevOrNext,  FR_VTWordPlace* outPlace))

INTERFACE(FS_INT32, FRInternalVariableTextWordPlaceToWordIndex, (FR_VariableText variableText,  FR_VTWordPlace place))

INTERFACE(void, FRInternalVariableTextWordIndexToWordPlace, (FR_VariableText variableText,  FS_INT32 index,  FR_VTWordPlace* outPlace))

INTERFACE(FS_BOOL, FRInternalVariableTextIsSectionComplexScript, (FR_VariableText variableText,  FR_VTWordPlace place))

INTERFACE(FS_BOOL, FRInternalVariableTextIsVerticalFont, (FR_VariableText variableText,  FS_INT32 nFontindex))

INTERFACE(FPD_VTBulletIterator, FRInternalGetBulletIterator, (FR_VariableText variableText))

INTERFACE(FR_Edit_FontMap, FRInternalEditFontMapGetDocFontMap, (FPD_Document fpdDoc))

INTERFACE(void, FRInternalEditFontMapEncodeFontAlias, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_ByteString* outAlias))

INTERFACE(void, FRInternalEditFontMapGetFontName, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_ByteString* outName))

INTERFACE(FS_INT32, FRInternalEditFontMapGetCharset, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(void*, FRInternalEditFontMapGetFXFont, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(FPD_Font, FRInternalEditFontMapGetPDFFont, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_DWordArray unicodeArray,  FS_BOOL bEmbedFont))

INTERFACE(FS_INT32, FRInternalEditFontMapGetCharWidthF, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_DWORD charcode,  FS_INT32 level))

INTERFACE(FS_INT32, FRInternalEditFontMapCharCodeFromUnicode, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_WORD word))

INTERFACE(FS_DWORD, FRInternalEditFontMapGlyphFromCharCode, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_DWORD charcode))

INTERFACE(FS_INT32, FRInternalEditFontMapCharSetFromUnicode, (FR_Edit_FontMap editFontMap,  FS_WORD word,  FS_INT32 nOldCharset))

INTERFACE(FS_INT32, FRInternalEditFontMapGetFontIndexByUnicode, (FR_Edit_FontMap editFontMap,  FS_WCHAR wUnicode,  FS_LPCSTR lpsDefaultFontName,  FS_DWORD dwFontStyle,  FS_INT32 nCharSet,  FS_BOOL bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FS_INT32, FRInternalEditFontMapGetFontIndex, (FR_Edit_FontMap editFontMap,  FS_LPCSTR lpsFontName,  FS_INT32 nCharset,  FS_DWORD dwFontStyle,  FS_BOOL bAdd,  FS_BOOL bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FS_BOOL, FRInternalIsEmbedded, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(FS_BOOL, FRInternalSetFXFMEditFont, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(FS_BOOL, FRInternalGlyphFromCharCode2, (FR_Edit_FontMap editFontMap,  FS_WCHAR* wcUnicodes,  FS_INT32 nUnicodeCount,  FS_DWordArray* outGlyphs,  FS_DWordArray* outGlyhCounts))

INTERFACE(FS_INT32, FRInternalEditFontMapAddFXFont, (FR_Edit_FontMap editFontMap,  void* pFXFont,  FS_LPCSTR lpsFontName,  FS_INT32 nCharset))

INTERFACE(FS_INT32, FRInternalEditFontMapAddPDFFont, (FR_Edit_FontMap editFontMap,  FPD_Font fpdFont,  FS_LPCSTR lpsFontName,  FS_INT32 nCharset))

INTERFACE(FPD_Document, FRInternalEditFontMapGetDocument, (FR_Edit_FontMap editFontMap))

INTERFACE(FS_INT32, FRInternalEditFontMapLoadAllFontByDict, (FR_Edit_FontMap editFontMap,  FR_PageView frPageView,  FPD_Object annotDict,  FS_LPCSTR lpsApType))

INTERFACE(FS_BOOL, FRInternalEditFontMapCheckCharacterIsSupported, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_DWORD dwUnicode))

INTERFACE(FS_BOOL, FRInternalEditFontMapGetStandardFont, (FR_Edit_FontMap editFontMap,  FS_LPCSTR lpsFontName,  FS_ByteString* outStandardFont))

INTERFACE(FS_BOOL, FRInternalEditFontMapIsExternalEmbedFont, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(FS_BOOL, FRInternalEditIteratorNextWord, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorNextLine, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorNextSection, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorPrevWord, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorPrevLine, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorPrevSection, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorGetWord, (FR_Edit_Iterator editIterator,  FR_VTWord* outWord))

INTERFACE(FS_BOOL, FRInternalEditIteratorGetDisplayWord, (FR_Edit_Iterator editIterator,  FR_VTWord* outWord))

INTERFACE(FS_BOOL, FRInternalEditIteratorGetLine, (FR_Edit_Iterator editIterator,  FR_VTLine* outLine))

INTERFACE(FS_BOOL, FRInternalEditIteratorGetSection, (FR_Edit_Iterator editIterator,  FR_VTSection* outSection))

INTERFACE(void, FRInternalEditIteratorSetAt, (FR_Edit_Iterator editIterator,  FS_INT32 nWordIndex))

INTERFACE(void, FRInternalEditIteratorSetAtII, (FR_Edit_Iterator editIterator,  FR_VTWordPlace place))

INTERFACE(void, FRInternalEditIteratorGetAt, (FR_Edit_Iterator editIterator,  FR_VTWordPlace* outWordPlace))

INTERFACE(FR_Edit, FRInternalEditIteratorGetEdit, (FR_Edit_Iterator editIterator))

INTERFACE(FR_Edit, FRInternalEditNew, ())

INTERFACE(void, FRInternalEditDel, (FR_Edit edit))

INTERFACE(void, FRInternalEditSetFontMap, (FR_Edit edit,  FR_Edit_FontMap fontMap,  FS_INT32 nDefaultFontIndex))

INTERFACE(void, FRInternalEditSetVTProvider, (FR_Edit edit,  FR_VariableText_Provider provider))

INTERFACE(void*, FRInternalEditSetNotify, (FR_Edit edit,  FR_EditNotifyCallbacks callbacks))

INTERFACE(void*, FRInternalEditSetOprNotify, (FR_Edit edit,  FR_EditOprNotifyCallbacks callbacks))

INTERFACE(FR_Edit_Iterator, FRInternalEditGetIterator, (FR_Edit edit))

INTERFACE(FR_VariableText, FRInternalEditGetVariableText, (FR_Edit edit))

INTERFACE(FR_Edit_FontMap, FRInternalEditGetFontMap, (FR_Edit edit))

INTERFACE(void, FRInternalEditInitialize, (FR_Edit edit))

INTERFACE(void, FRInternalEditSetPlateRect, (FR_Edit edit,  FS_FloatRect rect,  FS_BOOL bPaint,  FS_BOOL bVerticalWriting))

INTERFACE(void, FRInternalEditSetScrollPos, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(FS_BOOL, FRInternalEditIsVerticalWriting, (FR_Edit edit))

INTERFACE(void, FRInternalEditSetAlignmentH, (FR_Edit edit,  FS_INT32 nFormat,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetAlignmentV, (FR_Edit edit,  FS_INT32 nFormat,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetPasswordChar, (FR_Edit edit,  FS_WORD wSubWord,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetLimitChar, (FR_Edit edit,  FS_INT32 nLimitChar,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetCharArray, (FR_Edit edit,  FS_INT32 nCharArray,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetCharSpace, (FR_Edit edit,  FS_FLOAT fCharSpace,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetWordSpace, (FR_Edit edit,  FS_FLOAT fWordSpace,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetHorzScale, (FR_Edit edit,  FS_FLOAT fHorzScale,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetLineLeading, (FR_Edit edit,  FS_FLOAT fLineLeading,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetMultiLine, (FR_Edit edit,  FS_BOOL bMultiLine,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetAutoReturn, (FR_Edit edit,  FS_BOOL bAuto,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetAutoFontSize, (FR_Edit edit,  FS_BOOL bAuto,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetAutoScroll, (FR_Edit edit,  FS_BOOL bAuto,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetFontSize, (FR_Edit edit,  FS_FLOAT fFontSize,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetTextOverflow, (FR_Edit edit,  FS_BOOL bAllowed,  FS_BOOL bPaint))

INTERFACE(void, FRInternalSetDirectionRTL, (FR_Edit edit,  FS_BOOL bRTL,  FS_BOOL bApplyAllSection,  FS_BOOL bPaint))

INTERFACE(FS_BOOL, FRInternalEditIsRichText, (FR_Edit edit))

INTERFACE(void, FRInternalEditSetRichText, (FR_Edit edit,  FS_BOOL bRichText,  FS_BOOL bPaint))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextFont, (FR_Edit edit,  FS_LPCSTR lpsFontName,  FS_INT32 nFontIndex))

INTERFACE(FS_BOOL, FRInternalSetRichTextIsBold, (FR_Edit edit,  FS_BOOL bBold,  FS_BOOL bNeedToReaderingMode))

INTERFACE(FS_BOOL, FRInternalSetRichTextIsItalic, (FR_Edit edit,  FS_BOOL bItalic))

INTERFACE(FS_BOOL, FRInternalEditSetRichFontSize, (FR_Edit edit,  FS_FLOAT fFontSize))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextColor, (FR_Edit edit,  FS_COLORREF dwColor))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextStrokeColor, (FR_Edit edit,  FS_COLORREF dwColor))

INTERFACE(FS_BOOL, FRInternalEditSetRichRenderingMode, (FR_Edit edit,  FS_INT32 nRenderingMode))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextScript, (FR_Edit edit,  FS_INT32 nScriptType))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextUnderline, (FR_Edit edit,  FS_BOOL bUnderline))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextCrossout, (FR_Edit edit,  FS_BOOL bCrossout))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextCharSpace, (FR_Edit edit,  FS_FLOAT fCharSpace))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextWordSpace, (FR_Edit edit,  FS_FLOAT fWordSpace))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextHorzScale, (FR_Edit edit,  FS_FLOAT fHorzScale))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextLineLeading, (FR_Edit edit,  FS_FLOAT fLineLeading))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextLineIndent, (FR_Edit edit,  FS_FLOAT fLineIndent))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextAlignment, (FR_Edit edit,  FS_INT32 nAlignment))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextSoftReturn, (FR_Edit edit,  FS_BOOL bEnable))

INTERFACE(void, FRInternalEditSetSel, (FR_Edit edit,  FS_INT32 nStartChar,  FS_INT32 nEndChar))

INTERFACE(void, FRInternalEditGetSel, (FR_Edit edit,  FS_INT32* nStartChar,  FS_INT32* nEndChar))

INTERFACE(void, FRInternalEditSelectAll, (FR_Edit edit))

INTERFACE(void, FRInternalEditSelectNone, (FR_Edit edit))

INTERFACE(FS_INT32, FRInternalEditGetCaret, (FR_Edit edit))

INTERFACE(void, FRInternalEditGetCaretWordPlace, (FR_Edit edit,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditGetSelText, (FR_Edit edit,  FS_WideString* outText))

INTERFACE(void, FRInternalEditGetText, (FR_Edit edit,  FS_WideString* outText))

INTERFACE(void, FRInternalEditGetRichTextXML, (FR_Edit edit,  FS_LPCWSTR ds,  FS_BOOL bSaveLineFeed,  FS_WideString* outXML))

INTERFACE(FS_BOOL, FRInternalEditIsSelected, (FR_Edit edit))

INTERFACE(void, FRInternalEditGetScrollPos, (FR_Edit edit,  FS_FLOAT* x,  FS_FLOAT* y))

INTERFACE(FS_FloatRect, FRInternalEditGetPlateRect, (FR_Edit edit))

INTERFACE(FS_FloatRect, FRInternalEditGetContentRect, (FR_Edit edit))

INTERFACE(void, FRInternalEditGetVisibleWordRange, (FR_Edit edit,  FR_VTWordRange* outWordRange))

INTERFACE(void, FRInternalEditGetWholeWordRange, (FR_Edit edit,  FR_VTWordRange* outWordRange))

INTERFACE(void, FRInternalEditGetSelectWordRange, (FR_Edit edit,  FR_VTWordRange* outWordRange))

INTERFACE(void, FRInternalEditOnMouseDown, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnMouseMove, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_UP, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_DOWN, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_LEFT, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_RIGHT, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_HOME, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_END, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditSetText, (FR_Edit edit,  FS_LPCWSTR text,  FS_INT32 charset,  FR_VTSecProps secProps,  FR_VTWordProps pWordProps))

INTERFACE(void, FRInternalEditSetRichTextByXML, (FR_Edit edit,  FS_LPCWSTR xml,  FS_LPCWSTR ds,  FS_INT32 charset))

INTERFACE(FS_BOOL, FRInternalEditInsertWord, (FR_Edit edit,  FS_WORD word,  FS_INT32 charset,  FR_VTWordProps pWordProps,  FS_BOOL bPaint,  FS_BOOL bNeedTransform))

INTERFACE(FS_BOOL, FRInternalEditInsertReturn, (FR_Edit edit,  FR_VTSecProps secProps,  FR_VTWordProps pWordProps,  FS_BOOL bPaint))

INTERFACE(FS_BOOL, FRInternalEditInsertText, (FR_Edit edit,  FS_LPCWSTR text,  FS_INT32 charset,  FR_VTSecProps secProps,  FR_VTWordProps pWordProps,  FS_BOOL bPaint,  FS_BOOL bNeedTransform))

INTERFACE(FS_BOOL, FRInternalEditBackspace, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditDelete, (FR_Edit edit,  FS_BOOL bCtrl))

INTERFACE(FS_BOOL, FRInternalEditClear, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditRedo, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditUndo, (FR_Edit edit))

INTERFACE(void, FRInternalEditSetCaret, (FR_Edit edit,  FS_INT32 nPos))

INTERFACE(void, FRInternalEditPaint, (FR_Edit edit))

INTERFACE(void, FRInternalEditEnableRefresh, (FR_Edit edit,  FS_BOOL bRefresh))

INTERFACE(void, FRInternalEditRefreshWordRange, (FR_Edit edit,  FR_VTWordRange wordRange))

INTERFACE(void, FRInternalEditEnableUndo, (FR_Edit edit,  FS_BOOL bUndo))

INTERFACE(void, FRInternalEditEnableNotify, (FR_Edit edit,  FS_BOOL bNotify))

INTERFACE(void, FRInternalEditEnableOprNotify, (FR_Edit edit,  FS_BOOL bNotify))

INTERFACE(FS_INT32, FRInternalEditWordPlaceToWordIndex, (FR_Edit edit,  FR_VTWordPlace wordPlace))

INTERFACE(void, FRInternalEditWordIndexToWordPlace, (FR_Edit edit,  FS_INT32 index,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditGetLineBeginPlace, (FR_Edit edit,  FR_VTWordPlace wordPlace,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditGetLineEndPlace, (FR_Edit edit,  FR_VTWordPlace wordPlace,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditGetSectionBeginPlace, (FR_Edit edit,  FR_VTWordPlace wordPlace,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditGetSectionEndPlace, (FR_Edit edit,  FR_VTWordPlace wordPlace,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditSearchWordPlace, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordPlace* outWordPlace))

INTERFACE(FS_FLOAT, FRInternalEditGetFontSize, (FR_Edit edit))

INTERFACE(FS_WORD, FRInternalEditGetPasswordChar, (FR_Edit edit))

INTERFACE(FS_INT32, FRInternalEditGetCharArray, (FR_Edit edit))

INTERFACE(FS_FLOAT, FRInternalEditGetHorzScale, (FR_Edit edit))

INTERFACE(FS_FLOAT, FRInternalEditGetCharSpace, (FR_Edit edit))

INTERFACE(void, FRInternalEditGetRangeText, (FR_Edit edit,  FR_VTWordRange wordRange,  FS_WideString* outText))

INTERFACE(FS_BOOL, FRInternalEditIsTextFull, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditCanUndo, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditCanRedo, (FR_Edit edit))

INTERFACE(void, FRInternalEditResetUndo, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditIsModified, (FR_Edit edit))

INTERFACE(FS_INT32, FRInternalEditGetTotalWords, (FR_Edit edit))

INTERFACE(void*, FRInternalEditAddUndoItem, (FR_Edit edit,  FR_EditUndoItemCallbacks callbacks))

INTERFACE(void, FRInternalBeginGroupUndo, (FR_Edit edit,  FS_LPCWSTR lpwsTitle))

INTERFACE(void, FRInternalEndGroupUndo, (FR_Edit edit))

INTERFACE(void, FRInternalEditSaveLineOffset, (FR_Edit edit))

INTERFACE(void, FRInternalEditGetEditAppearanceStream, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_BOOL bContinuous,  FS_WORD SubWord,  FR_EDIT_FontData* outFontDataArray,  FS_INT32* outFontDataArrayCount,  FS_ByteString* outStream))

INTERFACE(void, FRInternalEditGetRichEditAppearanceStream, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_BOOL bContinuous,  FS_WORD SubWord,  FR_EDIT_FontData* outFontDataArray,  FS_INT32* outFontDataArrayCount,  FS_ByteString* outStream,  FS_ByteString pPathStream))

INTERFACE(void, FRInternalEditGetSelectAppearanceStream, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_ByteString* outStream))

INTERFACE(void, FRInternalEditDrawEdit, (FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device,  FR_Edit edit,  FS_ARGB crTextFill,  FS_COLORREF crTextStroke,  FS_FloatRect rcClip,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange))

INTERFACE(void, FRInternalEditDrawUnderline, (FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device,  FR_Edit edit,  FS_COLORREF color,  FS_FloatRect rcClip,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange))

INTERFACE(void, FRInternalEditDrawRichEdit, (FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device,  FR_Edit edit,  FS_FloatRect rcClip,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_AffineMatrix text2Uer))

INTERFACE(void, FRInternalEditGeneratePageObjects, (void* pPageObjects,  FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_COLORREF crText,  FS_PtrArray* outTextObjectArray))

INTERFACE(void, FRInternalEditGenerateRichPageObjects, (void* pPageObjects,  FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_PtrArray* outTextObjectArray,  FS_POSITION* outPos,  FS_PtrArray* outPathObjectArray))

INTERFACE(void, FRInternalEditGenerateUnderlineObjects, (void* pPageObjects,  FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_COLORREF color))

INTERFACE(void, FRInternalEditGetRichTextPlainText, (FS_LPCWSTR xml,  FS_WideString* outText))

INTERFACE(FR_Touchup, FRInternalGetTouchup, ())

INTERFACE(void, FRInternalBeginEditTextObject, (FR_Touchup touchup,  FR_Document frDoc,  FR_PageView frPageView,  FR_Text_Object_OP* objList,  FS_INT32 nObjListCount,  FR_Text_Object_OP_Result* pOutResult))

INTERFACE(void, FRInternalEndEditTextObject, (FR_Touchup touchup,  FR_Document frDoc,  FR_PageView frPageView,  FR_Text_Object_OP* objList,  FS_INT32 nObjListCount,  FR_Text_Object_OP_Result* pOutResult))

INTERFACE(void, FRInternalEmailUtilSendMailUseConfig, (FS_LPCWSTR toRecipientList,  FS_LPCWSTR ccRecipientList,  FS_LPCWSTR bccRecipientList,  FS_LPCWSTR subject,  FS_LPCWSTR message,  FS_LPCWSTR attachmentPath,  FS_LPCWSTR attachmentName,  HWND hWndParent,  FS_BOOL asyncMode,  FS_BOOL showUI,  FR_EmailUtilSendMailCallbacks eventHandler,  FS_INT32 *errorCode,  FS_INT32 *specificErrorCode,  FS_WideString *localizedErrorMessage))

INTERFACE(void, FRInternalEmailUtilShowAddressBook, (FS_WideStringArray *toRecipients,  FS_WideStringArray *ccRecipients,  FS_WideStringArray *bccRecipients,  HWND hWndParent,  FS_INT32 editFields,  FS_INT32 *errorCode,  FS_INT32 *specificErrorCode,  FS_WideString *localizedErrorMessage))

INTERFACE(FS_BOOL, FRInternalIsKeyAndTrialValid, ())

INTERFACE(FS_BOOL, FRInternalCheckLicense, ())

INTERFACE(FS_BOOL, FRInternalEditIsPunctuation, (FS_DWORD word))

INTERFACE(FS_BOOL, FRInternalEditIsCJK, (FS_DWORD word))

INTERFACE(FS_BOOL, FRInternalEditIsLatin, (FS_DWORD word))

INTERFACE(FS_BOOL, FRInternalEditIsNeedToConvertSpace, (FS_DWORD word))

INTERFACE(void, FRInternalGetCustomString, (FS_LPCSTR lpsKey,  FS_WideString* outValue))

INTERFACE(void, FRInternalEditDestroyNotify, (void* editNotify))

INTERFACE(void, FRInternalEditDestroyOprNotify, (void* editOprNotify))

INTERFACE(void, FRInternalSetDocReviewIdentity, (FR_Document frDoc,  FS_LPCWSTR lpwsIdName,  FS_LPCWSTR lpwsIdEmailAddr))

INTERFACE(void, FRInternalGetDocReviewIdentityName, (FR_Document frDoc,  FS_WideString* outIdName))

INTERFACE(void, FRInternalGetDocReviewIdentityEmail, (FR_Document frDoc,  FS_WideString* outIdEmailAddr))

INTERFACE(FS_BOOL, FRInternalHasVisibleTextObj, (FR_Touchup touchup,  FR_Document frDoc,  FR_PageView pageView,  FS_BOOL bPopDlg))

INTERFACE(FR_ProfStore, FRInternalGetProfStoreManager, ())

INTERFACE(FS_BOOL, FRInternalProfStoreGetString, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpRegKey,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_WideString* outValue,  FS_BOOL bUseDefValue))

INTERFACE(FS_BOOL, FRInternalProfStoreGetInt, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpRegKey,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  DWORD* outValue,  FS_BOOL bUseDefValue))

INTERFACE(FS_BOOL, FRInternalProfStoreGetBoolean, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpRegKey,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_BOOL* outValue,  FS_BOOL bUseDefValue))

INTERFACE(FS_BOOL, FRInternalProfStoreEnumAllKeyName, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_WideStringArray* outArrKeyName))

INTERFACE(FS_BOOL, FRInternalProfStoreEnumKeyName, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_WideStringArray* outArrKeyName))

INTERFACE(FS_BOOL, FRInternalProfStoreEnumKeyValueName, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_WideStringArray* outArrKeyValueName))

INTERFACE(FS_BOOL, FRInternalProfStoreEnumKeyValue, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_WideStringArray* outArrKeyValue))

INTERFACE(void, FRInternalGWL10NHelperAutoResizeDropWidth, (void* pComboBox))

INTERFACE(void, FRInternalGWL10NHelperResetItemDropWidth, (void* pCWnd))

INTERFACE(HWND, FRInternalGetActivePopupMenuMessageWnd, ())

INTERFACE(void, FRInternalGetPhoneNumber, (FS_WideString* wsSales,  FS_WideString* wsSupport))

INTERFACE(void, FRInternalGetEditionTitle, (FS_WideString* wsExpress,  FS_WideString* wsStandard,  FS_WideString* wsBusiness))

INTERFACE(void, FRInternalGetEmail, (FS_WideString* wsSales,  FS_WideString* wsSupport))

INTERFACE(FS_BOOL, FRInternalEditGetWordLatinSmallLigature, (FS_DWORD* src,  FS_INT32 nSrcCount,  FS_DWORD* outDest,  int* outDstCount))

INTERFACE(FPD_Document, FRInternalGetClonedDoc, (FPD_Document pSrcDoc))

INTERFACE(void, FRInternalEditFontMapReleaseDocFontMap, (FPD_Document fpdDoc))

INTERFACE(void*, FRInternalCreateActionWizardHandlerMgr, (FR_ActionWizardHandlerMgrCallbacks callbacks))

INTERFACE(void, FRInternalDestroyActionWizardHandlerMgr, (void* actionWizardHandlerMgr))

INTERFACE(void, FRInternalSetActionWizardHandlerMgr, (void* pActionWizardHandlerMgr))

INTERFACE(void*, FRInternalGetActionWizardHandlerMgr, ())

INTERFACE(FR_ActionWizardHandler, FRInternalCreateActionWizardHandler, (FR_ActionWizardHandlerCallbacks callbacks))

INTERFACE(void, FRInternalDestroyActionWizardHandler, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FS_BOOL, FRInternalRegisterActionWizardHandler, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FS_BOOL, FRInternalUnRegisterActionWizardHandler, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(void, FRInternalActionWizardHandlerGetName, (FR_ActionWizardHandler actionWizardHandler,  FS_ByteString outName))

INTERFACE(void, FRInternalActionWizardHandlerGetCommandName, (FR_ActionWizardHandler actionWizardHandler,  FS_ByteString outCommandName))

INTERFACE(FS_INT32, FRInternalActionWizardHandlerGetPresetFlag, (FR_ActionWizardHandler actionWizardHandler,  FS_XMLElement pXML))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerSetting, (FR_ActionWizardHandler actionWizardHandler,  FS_XMLElement pXML,  HWND hWnd))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerExecute, (FR_ActionWizardHandler actionWizardHandler,  FS_XMLElement pXML,  FS_BOOL bpromptUser,  FRActionWizardExcuteStatus* outStatus))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerGetTitle, (FR_ActionWizardHandler actionWizardHandler,  FS_LPCSTR lpsName,  FS_WideString outTitle,  FS_XMLElement pXML))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerNeedReopen, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerNeedChangeExecuteDoc, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FS_BOOL, FRInternalExportAnnotToXFDF2, (void* pAnnot,  FS_XMLElement xmlElement,  FS_BOOL bShareReview))

INTERFACE(void*, FRInternalImprotAnnotFromXFDF2, (FR_Document frDoc,  FS_XMLElement xmlAnnot,  FS_BOOL bSendAnnotChangeToNotify,  FS_BOOL bShareReview,  FS_ByteString bsUserId,  FS_BOOL* pbEditing))

INTERFACE(FS_BOOL, FRInternalSubscribeShowRibbonUI, (FRSubscriptionFlowName subWorkflowName))

INTERFACE(FS_BOOL, FRInternalSubscribeStartWorkflow, (FRSubscriptionFlowName subWorkflowName,  FS_WideString outReturnValue))

INTERFACE(FS_BOOL, FRInternalSubscribeIsLicenseRevoked, ())

INTERFACE(FS_BOOL, FRInternalSubscribeShowFlash, ())

INTERFACE(FR_CPDFPluginProvider, FRInternalCPDFPluginProviderSet, (FR_CPDFPluginProviderCallbacks callbacks))

INTERFACE(void, FRInternalCPDFPluginProviderDestroy, (FR_CPDFPluginProvider loginProvider))

INTERFACE(FR_CPDFPluginProvider, FRInternalCPDFPluginProviderGet, ())

INTERFACE(FS_BOOL, FRInternalCPDFPluginProviderShowConnectedPDFAdDialog, (FR_CPDFPluginProvider loginProvider))

INTERFACE(FS_INT32, FRInternalGetRemainDays, ())

INTERFACE(FS_DWORD, FRInternalCommentsAnnotSetUpdateServerTime, (FR_Document frDoc,  FS_XMLElement pAnnot))

INTERFACE(void, FRInternalGetLicenseSN, (FS_WideString* outSN))

INTERFACE(FS_INT32, FRInternalGetKeyfileType, ())

INTERFACE(void, FRInternalGetFormatSymbolString, (FS_LPCWSTR str,  FS_BOOL bInput,  FS_BOOL bSeperate,  FS_WideString* outResult))

INTERFACE(void, FRInternalGetLocalFormatTimeString, (SYSTEMTIME* sys,  FS_WideString* outFormat))

INTERFACE(FS_INT32, FRInternalConvertToPDFGetFileType, (FS_LPCWSTR lpwsFile))

INTERFACE(void, FRInternalGetFileFilter, (unsigned long uFilter,  FS_WideString* outFilter))

INTERFACE(FS_BOOL, FRInternalRegisterDocHandlerOfPDDocForActionWizard, (FR_DocEventForActionWizardCallbacks docEventCallbacks))

INTERFACE(void, FRInternalCommentsAnnotSetIconState, (FR_Document frDoc,  FS_INT32 nPageIndex,  FS_LPCWSTR lpwsAnnotName,  FRCommentsAnnotIconState nIconState))

INTERFACE(void, FRInternalGetAnnotInputFontName, (FS_WideString* outFontName))

INTERFACE(FS_BOOL, FRInternalIsDisableCPDF, ())

INTERFACE(FS_BOOL, FRInternalRunJSPluginByFlag, (FS_DWORD dwFlag))

INTERFACE(FS_BOOL, FRInternalRunJSPluginByName, (FS_LPCSTR lpsName))

INTERFACE(FS_BOOL, FRInternalIsJSPanelActivated, (FS_LPCSTR lpsName))

INTERFACE(void, FRInternalExpandJSPanel, (FS_LPCSTR lpsName,  FS_BOOL bExpand))

INTERFACE(void*, FRInternalEditSetDrawNotify, (FR_Edit edit,  FR_EditDrawNotifyCallbacks callbacks))

INTERFACE(void, FRInternalEditDestroyDrawNotify, (void* editDrawNotify))

INTERFACE(void, FRInternalEmailUtilRegisterPreSendMailHandler, (FR_EmailUtilPreSendMailCallbacks eventHandler))

INTERFACE(void, FRInternalGetCurEditonTitle, (FS_WideString* outTitle))

INTERFACE(FS_BOOL, FRInternalIsDisableInternet, (FS_BOOL bShowDisableMessageBox))

INTERFACE(FS_BOOL, FRInternalIsUseSystemSelectionColor, ())

INTERFACE(void, FRInternalEditSetSelBkColor, (FR_Edit edit,  FS_ARGB color))

INTERFACE(void, FRInternalEditDrawRichEdit2, (FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device,  FR_Edit edit,  FS_FloatRect rcClip,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_AffineMatrix text2Uer,  FS_COLORREF cShowColor))

INTERFACE(FS_BOOL, FRInternalIsJSPluginDisabled, (FS_LPCSTR lpsName))

INTERFACE(FS_INT32, FRInternalGetAccReadingOrderMode, ())

INTERFACE(FS_BOOL, FRInternalIsAccOverrideReadingOrder, ())

INTERFACE(FS_INT32, FRInternalGetDocAccReadingOrder, (FR_Document frDoc))

INTERFACE(FS_INT32, FRInternalGetDocAccReadingMode, (FR_Document frDoc))

INTERFACE(void, FRInternalSetReadActivateStatus, (FS_BOOL bActivateRead))

INTERFACE(FS_BOOL, FRInternalGetReadActivateStatus, ())

INTERFACE(FR_WIPPluginProvider, FRInternalWIPPluginProviderSet, (FR_WIPPluginProviderCallbacks callbacks))

INTERFACE(void, FRInternalWIPPluginProviderDestroy, (FR_WIPPluginProvider loginProvider))

INTERFACE(FR_WIPPluginProvider, FRInternalWIPPluginProviderGet, ())

INTERFACE(FS_BOOL, FRInternalWIPPluginProviderAllowedPaste, ())

INTERFACE(FS_BOOL, FRInternalThemeCheckHCMT, ())

INTERFACE(void, FRInternalThemeGetTextColor, (FS_COLORREF* clrText))

INTERFACE(void, FRInternalThemeGetDisableTextColor, (FS_COLORREF* clrDisableTextColor))

INTERFACE(void, FRInternalThemeGetHyperlinkTextColor, (FS_COLORREF* clrText))

INTERFACE(void, FRInternalThemeGetSelectedTextColor, (FS_COLORREF* clrTextColor,  FS_COLORREF* clrBackgroundColor))

INTERFACE(void, FRInternalThemeGetButtonTextColor, (FS_COLORREF* clrBtnTextColor,  FS_COLORREF* clrBackgroundColor))

INTERFACE(void, FRInternalThemeGetTooltipColor, (FS_COLORREF* clrTextColor,  FS_COLORREF* clrBackgroundColor))

INTERFACE(void, FRInternalThemeGetBackgroundColor, (FS_COLORREF* clrBkColor))

INTERFACE(void, FRInternalEmailUtilRegisterAttachmentNameModifier, (FR_EmailUtilAttachmentNameModifier modifier))

INTERFACE(void, FRInternalGetAppSaveAsLocation, (FS_WideString wsFullPath))

INTERFACE(void, FRInternalLoadJSPlugin, (FS_BOOL bSlient))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerIsEnableExecute, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(void, FRInternalActionWizardHandlerExecuteDone, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FS_INT32, FRInternalEditFontMapGetFontIndexByUnicode2, (FR_Edit_FontMap editFontMap,  FS_WCHAR wUnicode,  FS_LPCSTR lpsDefaultFontName,  FS_DWORD dwFontStyle,  FS_INT32 nCharSet,  FRFMTribool bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FS_INT32, FRInternalEditFontMapGetFontIndex2, (FR_Edit_FontMap editFontMap,  FS_LPCSTR lpsFontName,  FS_INT32 nCharset,  FS_DWORD dwFontStyle,  FS_BOOL bAdd,  FRFMTribool bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FR_Compare_Results*, FRInternalCompareGetDifInfos, (FPD_Page pageOld,  FPD_Page pageNew,  FS_INT32 nOpt))

INTERFACE(void, FRInternalCompareReleaseDifInfos, (FR_Compare_Results* pCompareResults))

INTERFACE(void, FRInternalCompareDrawNoteAP, (FPD_Document pDocument,  FPD_Object pAnnotDic,  COLORREF color,  int nLineWidth,  int nOpacity,  FS_INT32 nNoteType,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(void, FRInternalGetCreationDate, (FPD_Document pDocument,  FS_WideString outCreationDate))

INTERFACE(void, FRInternalSetReadStatus, (FS_BOOL bActivateRead))

INTERFACE(FS_BOOL, FRInternalGetReadStatus, ())

INTERFACE(FS_BOOL, FRInternalCheckActualLicense, ())

INTERFACE(FR_Document, FRInternalOpenCreatedPDFDoc, (const FS_WideString csFilePath,  const FS_WideString csTitle))

INTERFACE(FS_BOOL, FRInternalGetIsPheeMode, ())

INTERFACE(void, FRInternalEditSetEastenArabicNumeralMode, (FR_Edit edit,  FS_BOOL bEastenArabic))

INTERFACE(FR_ActionWizardLogger, FRInternalActionWizardLogCreate, ())

INTERFACE(void, FRInternalActionWizardLogWriteDetailInfo, (FR_ActionWizardLogger logger,  const FS_WideString wsType,  const FS_WideString wsValue))

INTERFACE(void, FRInternalActionWizardLogWriteCurrentTime, (FR_ActionWizardLogger logger,  const FS_WideString wsInfo))

INTERFACE(void, FRInternalActionWizardLogWriteBoundaryInfo, (FR_ActionWizardLogger logger,  FS_BOOL bBoundary))

INTERFACE(void, FRInternalActionWizardLogGenerate, (FR_ActionWizardLogger logger,  const FS_WideString wsFileFolder,  FS_WideString* wsName))

INTERFACE(void, FRInternalActionWizardLogClose, (FR_ActionWizardLogger logger))

INTERFACE(void, FRInternalActionWizardLogWrite, (FR_ActionWizardLogger logger,  FRActionWizardLogType nType,  FS_WideString* wsTip))

INTERFACE(FS_BOOL, FRInternalActionWizardLogGetState, (FR_ActionWizardLogger logger))

INTERFACE(void, FRInternalActionWizardLogGetLastFilePath, (FR_ActionWizardLogger logger,  FS_WideString* filePath))

INTERFACE(void, FRInternalActionWizardLogSetCurFilePath, (FR_ActionWizardLogger logger,  const FS_WideString wsFilePath))

INTERFACE(void, FRInternalActionWizardLogSetExcuteFileStatus, (FR_ActionWizardLogger logger,  FS_BOOL bSuccess))

INTERFACE(FS_BOOL, FRInternalGetUpgExpDate, (FS_WideString* wsUpgExpDate))

INTERFACE(FS_BOOL, FRInternalIsUsedAnotherPerpetualLicense, ())

INTERFACE(FS_BOOL, FRInternalBaseAnnoteIsSnap2GridEnabled, ())

INTERFACE(FS_BOOL, FRInternalBaseAnnoteGetGridLine, (FR_PageView pPageView,  FS_DWordArray XArray,  FS_DWordArray YArray))

INTERFACE(FS_BOOL, FRInternalBaseAnnoteGetGridMainLine, (FR_PageView pPageView,  FS_DWordArray XArray,  FS_DWordArray YArray))

INTERFACE(void, FRInternalAddDocToPrivilegedList, (FR_Document frDoc,  FS_BOOL bCkeckURL))

INTERFACE(FS_BOOL, FRInternalIsPrivilegedFile, (FR_Document frDoc))

INTERFACE(FS_BOOL, FRInternalIsDisableInternet2, (FS_LPCWSTR wsPluginName,  FS_BOOL bShowDisableMessageBox))

INTERFACE(FS_BOOL, FRInternalIsSimpleChineseVersion, ())

INTERFACE(void, FRInternalGetLicensee, (FS_WideString* outLicensee))

INTERFACE(FS_INT32, FRInternalEditFontMapGetFontIndexByUnicode3, (FR_Edit_FontMap editFontMap,  FS_WCHAR wUnicode,  FS_LPCWSTR lpsDefaultFontName,  FS_DWORD dwFontStyle,  FS_INT32 nCharSet,  FRFMTribool bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FS_INT32, FRInternalEditFontMapGetFontIndex3, (FR_Edit_FontMap editFontMap,  FS_LPCWSTR lpsFontName,  FS_INT32 nCharset,  FS_DWORD dwFontStyle,  FS_BOOL bAdd,  FRFMTribool bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FS_INT32, FRInternalEditFontMapAddFXFont2, (FR_Edit_FontMap editFontMap,  void* pFXFont,  FS_LPCWSTR lpsFontName,  FS_INT32 nCharset))

INTERFACE(FS_INT32, FRInternalEditFontMapAddPDFFont2, (FR_Edit_FontMap editFontMap,  FPD_Font fpdFont,  FS_LPCWSTR lpsFontName,  FS_INT32 nCharset))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextFont2, (FR_Edit edit,  FS_LPCWSTR lpsFontName,  FS_INT32 nFontIndex))

INTERFACE(void, FRInternalEditFontMapGetFontName2, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_WideString* outName))

INTERFACE(void, FRInternalClearDragRects, ())

INTERFACE(void, FRInternalOnMovedByPoint, (FR_PageView pPageView,  FR_Annot pAnnot,  FS_INT32 nMovingType,  const FS_FloatPoint& ptOrigin,  const FS_FloatPoint& ptNew))

INTERFACE(void, FRInternalOnMovedByRect, (FR_PageView pPageView,  FR_Annot pAnnot,  const FS_Rect& rcOrigin,  const FS_Rect& rcNew))

INTERFACE(void, FRInternalSaveKeepToolSelectedToRegistry, (FS_WideString csRegPath))

INTERFACE(void, FRInternalEnableKeepToolSelected, (FS_BOOL bEnable))

INTERFACE(FS_BOOL, FRInternalChangeKeepToolSelectedStateFromRegistry, (FS_WideString csRegPath,  FS_BOOL bDefault))

INTERFACE(void, FRInternalAddDragRect, (FR_PageView pPageView,  const FS_Rect rcDrag))

INTERFACE(void, FRInternalReset, (FR_Document pDocument))

INTERFACE(void, FRInternalRunPageFlat, (FPD_Document pPDFDoc,  FPD_Object pPageDict,  FS_PtrArray vecAnnotDict))

INTERFACE(void, FRInternalGetCurrentUserName, (FS_WideString csEmail,  FS_WideString* wsName))

INTERFACE(FS_BOOL, FRInternalEncryptAttachment, (FR_Document pDocument,  FS_BOOL bEncrypt))

INTERFACE(FS_INT32, FRInternalGetAllFormatFontSize, ())

INTERFACE(void, FRInternalGetAtAllFormatFont, (FS_INT32 index,  FS_WideString* sFaceName))

INTERFACE(void, FRInternalGetFontFaceNameBoldItalic, (const FS_WideString& sFontName,  FS_WideString* sFaceName,  FS_BOOL& bBold,  FS_BOOL& bItalic))

INTERFACE(FS_BOOL, FRInternalGetFontStyle, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_DWORD* dwFontStyle,  FS_INT32* nCharset))

INTERFACE(void, FRInternalEditSetEnableMLAutoFullFontSize, (FR_Edit edit,  FS_BOOL bEnable))

INTERFACE(FS_BOOL, FRInternalFlattenDynamicXFADoc, (FR_Document pDoc,  const FS_WideString& cwNewFilePath,  FR_UIProgress pProgress))

INTERFACE(FS_BOOL, FRInternalIsSelfSignCertGen, (FS_BOOL &bSelfSignCertGen))

INTERFACE(FS_BOOL, FRInternalGetIsCheckPrivateKeyCert, ())

INTERFACE(void, FRInternalParseMailtoURI, (const FS_WideString &wsMailtoURI,  FS_WideString &wsTo,  FS_WideString &wsCc,  FS_WideString &wsBcc,  FS_WideString &wsSubject,  FS_WideString &wsBody))

INTERFACE(FS_BOOL, FRInternalIsMailtoURI, (const FS_WideString &wsString))

INTERFACE(void, FRInternalAsyncUpdateCheckerInfo, (FR_Document pRDDoc,  const FS_DWORD dwRule,  const FR_PDFAccessibilityCheckerState state))

INTERFACE(FS_BOOL, FRInternalIsCurrentTool, ())

INTERFACE(void, FRInternalSetToolMode, (FR_SGToolMode  tm))

INTERFACE(FR_SGToolMode, FRInternalGetToolMode, ())

INTERFACE(void, FRInternalSetPreToolHandler, (FR_Tool pPreToolHandler))

INTERFACE(void, FRInternalEmailUtilSendMailUseConfig2, (FS_LPCWSTR toRecipientList,  FS_LPCWSTR ccRecipientList,  FS_LPCWSTR bccRecipientList,  FS_LPCWSTR subject,  FS_LPCWSTR message,  FS_WideStringArray attachmentPathArr,  FS_WideStringArray attachmentNameArr,  HWND hWndParent,  FS_BOOL asyncMode,  FS_BOOL showUI,  FR_EmailUtilSendMailCallbacks eventHandler,  FS_INT32 *errorCode,  FS_INT32 *specificErrorCode,  FS_WideString *localizedErrorMessage))

INTERFACE(void, FRInternalDIBSourceToBmp, (FS_DIBitmap pBitmap,  FS_INT32& nLen,  FS_ByteArray& byteArray))

INTERFACE(void, FRInternalBeginBulletEditing, (FR_PageView pageview,  FS_LPVOID pEdit))

INTERFACE(void, FRInternalBeginBulletEditing2, (FR_Document pDoc,  FS_LPVOID pEditCombtn))

INTERFACE(FS_LPVOID, FRInternalSetNotify, (FR_BulletNotifyCallbacks pNotify))

INTERFACE(void, FRInternalOnCharTab, (FS_FLOAT fIndentValue))

INTERFACE(void, FRInternalGetLicenseEditon, (FS_WideString* outEditon))

INTERFACE(FS_FLOAT, FRInternalGetPropsSecSpace, (FR_VTSecProps secProps))

INTERFACE(FS_BOOL, FRInternalIsUndoRedoing, (FR_Document document))

INTERFACE(FS_LPVOID, FRInternalBeginGroup, (FR_Document document,  const FS_WideString sDesc,  FS_BOOL bGroupSingle))

INTERFACE(void, FRInternalEndGroup, (FR_Document document,  FS_BOOL bEdit))

INTERFACE(void, FRInternalGetUndoDescription, (FR_Document document,  FS_WideString* wsDescription))

INTERFACE(void, FRInternalGetRedoDescription, (FR_Document document,  FS_WideString* wsDescription))

INTERFACE(void, FRInternalLoadPopupMenuString, (FR_Document document,  FS_INT32 nIndex,  FS_WideString* wsMenustr))

INTERFACE(void, FRInternalReleaseBulletNotify, (FS_LPVOID pBulletNotify))

INTERFACE(void, FRInternalEndBulletEditing, ())

INTERFACE(FS_BOOL, FRInternalIsSupportSymbol, (FS_WCHAR ch))

INTERFACE(FS_BOOL, FRInternalRunOCR, (FPD_Page pPDFPage,  FS_BOOL bEditMode))

INTERFACE(void, FRInternalGetLocalAbyLan, (FS_WideString* wsLan))

INTERFACE(void, FRInternalbExistFX_Abbyy_Ocr_dll, (FS_WideString* wsLan))

INTERFACE(FS_BOOL, FRInternalGetOCREngineSupportLan, (FS_WideStringArray* aLanguage,  FS_WideStringArray* wsAbbyLanName,  FS_WideStringArray* wsAryEngineLanName))

INTERFACE(FS_LPVOID, FRInternalLoadAnnotIcon, (FS_INT32 nIconType))

INTERFACE(FS_BOOL, FRInternalSubscribeIsEducation, ())

INTERFACE(FR_RibbonElement, FRInternalAddFloatyBarBtn, (FR_Ribbon_Element_Type nElementType,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle))

INTERFACE(void, FRInternalAddRibbonBtnsToFloaty, (FS_ByteStringArray pAryBeShowBtnName))

INTERFACE(FS_LPVOID, FRInternalCreateRibbonFloaty, (FS_FloatPoint point))

INTERFACE(void, FRInternalUndo, (FR_Document pDocument))

INTERFACE(void, FRInternalRedo, (FR_Document pDocument))

INTERFACE(void, FRInternalPWLWndCreationParamSetSystemHandler, (void* pCreationParam,  FS_LPVOID handler))

INTERFACE(void, FRInternalPWLWndCreationParamSetProvider, (void* pCreationParam,  FPD_CPWL_Provider handler))

INTERFACE(void, FRInternalPWLWndCreationParamSetFocusHandler, (void* pCreationParam,  FPD_CPWL_FocusHandler handler))

INTERFACE(void, FRInternalPWLWndCreationParamSetBackgroundColor, (void* pCreationParam,  FS_INT32 type,  FS_FLOAT color1,  FS_FLOAT color2,  FS_FLOAT color3,  FS_FLOAT color4))

INTERFACE(void, FRInternalPWLWndCreationParamSetAttachedWnd, (void* pCreationParam,  FS_LPVOID wnd))

INTERFACE(void, FRInternalPWLWndCreationParamSetSpellCheck, (void* pCreationParam,  FPD_SpellCheck spellcheck))

INTERFACE(void, FRInternalPWLWndCreationParamSetBorderStyle, (void* pCreationParam,  FS_INT32 borderStyle))

INTERFACE(void, FRInternalPWLWndCreationParamSetBorderWidth, (void* pCreationParam,  FS_INT32 borderWidth))

INTERFACE(void, FRInternalPWLWndCreationParamSetBorderColor, (void* pCreationParam,  FS_INT32 type,  FS_FLOAT color1,  FS_FLOAT color2,  FS_FLOAT color3,  FS_FLOAT color4))

INTERFACE(void, FRInternalPWLWndCreationParamSetTextStrokeColor, (void* pCreationParam,  FS_INT32 type,  FS_FLOAT color1,  FS_FLOAT color2,  FS_FLOAT color3,  FS_FLOAT color4))

INTERFACE(void, FRInternalPWLWndCreationParamSetTransparency, (void* pCreationParam,  FS_INT32 transparency))

INTERFACE(void, FRInternalPWLWndCreationParamSetUseFXFontDeAscent, (void* pCreationParam,  FS_BOOL bUse))

INTERFACE(void, FRInternalPWLWndCreationParamSetDash, (void* pCreationParam,  FPDCPWL_Dash dash))

INTERFACE(void, FRInternalPWLWndCreationParamSetAttachedData, (void* pCreationParam,  FS_LPVOID data))

INTERFACE(void, FRInternalPWLWndCreationParamSetParentWnd, (void* pCreationParam,  FPD_CPWL_Wnd wnd))

INTERFACE(void, FRInternalPWLWndCreationParamSetCursorType, (void* pCreationParam,  FS_INT32 type))

INTERFACE(void, FRInternalPWLWndCreationParamSetMtChild, (void* pCreationParam,  FS_AffineMatrix mt))

INTERFACE(void, FRInternalPWLWndCreationParamSetShowFontSizeDPI, (void* pCreationParam,  FS_FLOAT dpi))

INTERFACE(void, FRInternalPWLWndCreationParamSetNeedEmbed, (void* pCreationParam,  FS_BOOL bEmbed))

INTERFACE(FS_BOOL, FRInternalOpenCertifiedPDF2, (FPD_Parser parser,  FS_WideString cwPDFPath,  FS_BOOL bShowPassDlg,  FS_BOOL *pbCancel))

INTERFACE(FS_BOOL, FRInternalFieldsMutiCopy, (FS_LPVOID pParent,  FR_IFieldMulCopiesNotify pNotify,  FS_PtrArray MSource,  FS_FloatRect rcView,  FS_BOOL bEnableSameName,  FS_INT32 nRotate))

INTERFACE(FS_LPVOID, FRInternalCreateDigitalID, (FS_LPVOID pParent,  FS_WideString* cwFileName,  FS_WideString* cwPassWord))

INTERFACE(FS_BOOL, FRInternalOpenDigitalIDsManager, (FS_LPVOID pParent))

INTERFACE(void, FRInternalSetIsCheckPrivateKeyCert, (FS_BOOLEAN bCheck))

INTERFACE(void*, FRInternalPWLWndCreationParamNew2, (FS_LPVOID  curCreationparam))

INTERFACE(void, FRInternalArabicResetWord, (FR_Edit_FontMap editFontMap,  FS_UINT nFontIndex,  FS_LPCWSTR wsArabic,  FS_WideString* outWord))

INTERFACE(void, FRInternalOnDestroyDocView, (FR_DocView pDocView))

INTERFACE(void, FRInternalEditSetText2, (FR_Edit edit,  FS_LPCWSTR text,  FS_INT32 charset,  FR_VTSecProps secProps,  FR_VTWordProps pWordProps,  FS_BOOLEAN bNeedEmbed))

INTERFACE(FS_BOOL, FRInternalWipPluginEncryptFile, (FS_LPCWSTR wszFilePath))

INTERFACE(FR_PrintMgr, FRInternalCreatePrintMgr, (FR_Document doc,  FS_BOOL bQuietMode,  FS_LPCWSTR wsSummarizeComments))

INTERFACE(void, FRInternalSetPrintRange, (FR_PrintMgr printMgr,  FS_INT32 nRangeMode,  FS_INT32 nFrom,  FS_INT32 nTo))

INTERFACE(void, FRInternalSetPrintRotate, (FR_PrintMgr printMgr,  FS_INT32 nRotateMode))

INTERFACE(void, FRInternalSetPrintScale, (FR_PrintMgr printMgr,  FS_INT32 nZoomToMode,  FS_FLOAT flScale))

INTERFACE(void, FRInternalSetPrintAutoCenter, (FR_PrintMgr printMgr,  FS_BOOLEAN bAutoCenter))

INTERFACE(void, FRInternalSetPrintAutoRotate, (FR_PrintMgr printMgr,  FS_BOOLEAN bAutoRotate))

INTERFACE(void, FRInternalSetPrintGray, (FR_PrintMgr printMgr,  FS_BOOLEAN bGray))

INTERFACE(void, FRInternalSetPrintCollate, (FR_PrintMgr printMgr,  FS_BOOLEAN bCollate))

INTERFACE(void, FRInternalSetPrintPageOrder, (FR_PrintMgr printMgr,  FS_INT32 nOrderMode))

INTERFACE(void, FRInternalSetPrintPrintWhat, (FR_PrintMgr printMgr,  FS_INT32 nPrintWhatMode))

INTERFACE(void, FRInternalSetPrintOrientation, (FR_PrintMgr printMgr,  FR_PrintOrientationType nPrintOriType))

INTERFACE(void, FRInternalSetPrintPagesPerSheet, (FR_PrintMgr printMgr,  FS_INT32 nPerSheetMode,  FS_INT32 nHorzs,  FS_INT32 nVerts))

INTERFACE(void, FRInternalSetPrintPaperSizeByPage, (FR_PrintMgr printMgr,  FS_BOOLEAN bPaperSizeByPage))

INTERFACE(void, FRInternalSetPrintReverse, (FR_PrintMgr printMgr,  FS_BOOLEAN bReverse))

INTERFACE(void, FRInternalSetPrintMargins, (FR_PrintMgr printMgr,  FS_FLOAT flMargins))

INTERFACE(void, FRInternalSetPrintAsImage, (FR_PrintMgr printMgr,  FS_BOOLEAN bPrintAsImage))

INTERFACE(void, FRInternalSetSimulateOverprinting, (FR_PrintMgr printMgr,  FS_BOOLEAN bSimulateOverprintint))

INTERFACE(void, FRInternalSetPrintIgnoreAdvancedSetting, (FR_PrintMgr printMgr,  FS_BOOL bIgnoreAdvanced))

INTERFACE(void, FRInternalSetProgressDisplay, (FR_PrintMgr printMgr,  FS_BOOL bShow))

INTERFACE(void, FRInternalSetPaperSize, (FR_PrintMgr printMgr,  FS_INT32 papersize))

INTERFACE(void, FRInternalSetPrintPageArray, (FR_PrintMgr printMgr,  FS_WordArray PageArray))

INTERFACE(FS_LPCWSTR, FRInternalGetDefaultPrint, (FR_PrintMgr printMgr))

INTERFACE(void, FRInternalSetDefaultPrint, (FR_PrintMgr printMgr,  FS_LPCWSTR  strPrinterName))

INTERFACE(void, FRInternalSetPrintOutputFileName, (FR_PrintMgr printMgr,  FS_LPCWSTR wsOutputFileName))

INTERFACE(FS_INT32, FRInternalDoModal, (FR_PrintMgr printMgr,  FS_HWND hParentHwnd))

INTERFACE(void, FRInternalDeletePrintMg, (FR_PrintMgr printMgr))

INTERFACE(FS_BOOL, FRInternalIsSearchingText, (FR_Document doc))

INTERFACE(FS_BOOLEAN, FRInternalWaitingFileClosed, (FS_LPCWSTR filePath,  FS_INT32 tryTimes,  FS_INT32 perSleepTime))

INTERFACE(FS_BOOLEAN, FRInternalConvertPdfFromWeb, (FS_HWND hParentWnd,  FS_LPCWSTR csWindowTitle,  FS_WideString* csOutputFilepath,  FS_WideString* wsOutputUrl))

INTERFACE(FS_BOOL, FRInternalGetFromClipboard, (FS_LPWSTR pszDest))

INTERFACE(FR_SNTwainDriver, FRInternalCreateTwainDriver, (FS_LPVOID pParentWnd))

INTERFACE(void, FRInternalDeleteTwainDriver, (FR_SNTwainDriver driver))

INTERFACE(void, FRInternalGetMenuItem, (FR_SNTwainDriver driver,  FS_WideString* m_wsPresetName))

INTERFACE(void, FRInternalEnableInsertPosition, (FR_SNTwainDriver driver,  FS_BOOL bEnable))

INTERFACE(void, FRInternalSetCurType, (FR_SNTwainDriver driver,  FR_ScanType scanType))

INTERFACE(FS_BOOL, FRInternalShowDialog, (FR_SNTwainDriver driver,  FR_ScanShowDialogType nType,  FS_WideString pScanname))

INTERFACE(void, FRInternalSetInsertPosition, (FR_SNTwainDriver driver,  FS_DWORD nInitPosition))

INTERFACE(void, FRInternalSetAppendFileInsertPos, (FR_SNTwainDriver driver,  FS_INT32 npos))

INTERFACE(FR_SNRecordOper, FRInternalGetRecordOper, ())

INTERFACE(FS_INT32, FRInternalGetDataCount, (FR_SNRecordOper recordOper))

INTERFACE(void, FRInternalGetPresetNameAt, (FR_SNRecordOper recordOper,  FS_INT32 index,  FS_WideString* wsName))

INTERFACE(void, FRInternalStartScan, (FS_LPVOID pDriver))

INTERFACE(FS_BOOLEAN, FRInternalSameNameFieldExist, (FPD_Document doc1,  FPD_Document doc2))

INTERFACE(FS_INT32, FRInternalShowRenameMsg, (FS_HWND hwnd))

INTERFACE(void, FRInternalConvertPdfFromWeb2, (FS_WideStringArray vecWsURL,  FS_BOOL bAppendLinkOnDoc,  FS_BOOL bViewWebLinks,  FSConvertPdfFromWebCallback callback,  FS_INT32 nCurrentPageIndex))

INTERFACE(void, FRInternalCopyFields, (FPD_InterForm pDstInterForm,  FS_INT32 nDstPageStart,  FPD_Document pSrcDoc,  FS_INT32 nSrcPageStart,  FS_INT32 nPageCount,  FSCopyFieldsDictNotify pNotify,  FS_LPVOID pClientData,  FS_BOOL bCopySame))

INTERFACE(void, FRInternalAddCRSAUndoItem, (FR_Page pPage,  FR_Annot pAnnot,  FRRSA_UNDO_DATA undoData))

INTERFACE(void, FRInternalAddStampAP, (FR_Annot pAnnot,  FS_LPCWSTR wsStampName))

INTERFACE(FPD_Object, FRInternalGetDestination, (FPD_Document pDocument,  FPD_Annot pAnnot))

INTERFACE(void, FRInternalDoAction_URI, (FPD_Document pDocument,  FS_LPCWSTR wsDocPath,  const FPD_Action action,  FS_BOOLEAN bOpenInNewTab))

INTERFACE(void, FRInternalDoAction_Launch, (FS_LPCWSTR wsDocPath,  const FPD_Action action,  FS_LPCWSTR wsSpeFilePath))

INTERFACE(void, FRInternalDoAction_GoToR, (FPD_Document pPDFDoc,  FS_LPCWSTR wsDocPath,  const FPD_Action action))

INTERFACE(void, FRInternalDoAction_GoToE, (FPD_Document pPDFDoc,  FS_LPCWSTR wsDocPath,  const FPD_Action action))

INTERFACE(FS_BOOLEAN, FRInternalIsAttachDenied, (FS_LPCWSTR wsFileExt))

INTERFACE(FS_BOOLEAN, FRInternalIsAttachDenied2, (FS_LPCWSTR wsFilePath,  FS_WideStringArray* wsFailedArray))

INTERFACE(void, FRInternalShowAttachFailedDlg, (FS_WideStringArray wsFailedArray))

INTERFACE(FR_ConvertMediaErrorType, FRInternalConvertMediaToPDF, (FS_LPCWSTR csMediaPath,  FS_LPCWSTR csPdfPath,  FS_INT32 width,  FS_INT32 height,  FS_BOOL bShowSelectMediaDlg,  FS_LPVOID pParentWnd))

INTERFACE(FS_BOOLEAN, FRInternalRunProcJavaScript, (FR_Document pReaderDoc,  FS_WideString script,  FR_JSProcType procType))

INTERFACE(FS_BOOL, FRInternalCheckDocTrustOneTime, (FR_Document pReaderDoc))

INTERFACE(void, FRInternalAddDocTrustOneTime, (FR_Document pReaderDoc))

INTERFACE(void, FRInternalReBuildTreeView, (FR_Document pReaderDoc,  FS_BOOLEAN bRepair))

INTERFACE(FS_BOOL, FRInternalAddAccessibility, (FR_Document  pReaderDoc,  FS_HWND pParent))

INTERFACE(FS_BOOL, FRInternalCanDoAddAccessibility, (FR_Document  pReaderDoc))

INTERFACE(FS_BOOL, FRInternalCheckIsDownloadStatus, ())

INTERFACE(void, FRInternalSetFormRecognitionProc, (FRFormRecognitionProc proc))

INTERFACE(FS_INT32, FRInternalGetContainedCountInPages, (FPD_Document pDoc,  FS_WideString csInput,  FS_BOOL bUseDigit))

INTERFACE(FS_BOOL, FRInternalGetPrompPages, (FPD_Document pDoc,  FS_LPCWSTR csName,  FS_INT32* count,  FS_PtrArray* outlistPromp))

INTERFACE(FS_BOOLEAN, FRInternalReduceFileSize, (FS_LPCWSTR wsFilePath,  FS_BOOLEAN bNoUI,  FR_UIProgress pProgressUI))

INTERFACE(FS_BOOLEAN, FRInternalShowReduceSizeDlg, (FR_Document pReaderDoc))

INTERFACE(void, FRInternalLoadAuiModuleString, (FS_WideString moduleName,  const FS_WideString  stringId,  bool bPlugin,  FS_WideString* outdata))

INTERFACE(FS_BOOLEAN, FRInternalIsNameExist, (FS_LPCSTR csObjectName))

INTERFACE(FS_BOOLEAN, FRInternalAddFileAttachment, (FS_LPCWSTR wsAttachFilePath,  FS_LPCWSTR wsObjectName,  FS_BOOLEAN bShowOverWriteTips))

INTERFACE(FS_BOOL, FRInternalRedactText, (FPD_Page pPage,  FS_POSITION pos,  FPD_PageObject pPageObject,  const FS_FloatRect rect,  FS_PtrArray mts,  FS_PtrArray* Objects,  FPD_Form *pForm))

INTERFACE(void, FRInternalExecScanDocTofile, (FS_WideString* csOutputFilepath,  FREndScanFun fun,  FS_LPVOID clientData))

INTERFACE(FS_BOOLEAN, FRInternalIsFileAttachSubDoc, (FR_Document pDoc))

INTERFACE(FS_BOOLEAN, FRInternalIsParentDocAllowModify, (FR_Document pDoc))

INTERFACE(FS_BOOL, FRInternalSetActiveTool, (FR_Tool tool,  FS_BOOL persistent))

INTERFACE(FS_BOOLEAN, FRInternalDoAction_DocOpen, (const FPD_Action action,  FR_Document pDocument,  FS_BOOLEAN bDisableGoto))

INTERFACE(FS_BOOLEAN, FRInternalActionWizardHandlerNeedSaveDoc, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FR_PACKAGELANG, FRInternalGetPackageLanguage, ())

INTERFACE(FS_BOOLEAN, FRInternalShowSafeModeDialog, (FR_Document pDoc))

INTERFACE(void, FRInternalReShowSafeModeDialog, (FR_Document pDoc))

INTERFACE(void, FRInternalSetDocRenderFinishOneTime, (FR_Document pDoc,  FS_BOOL bReaderOneTime))

INTERFACE(void, FRInternalSetPageVisibleEventFinish, (FR_Document pDoc,  FS_BOOL bDocPageVisibleEvent))

INTERFACE(void, FRInternalExecuteOnPortfolioFinishRender, (FR_Document pDoc))

INTERFACE(void, FRInternalSetRecipientSeed, (FS_ByteString cwPDFPath))

INTERFACE(void, FRInternalConstructorInterform, (FR_Document pDoc))

INTERFACE(FS_DWORD, FRInternalParserOpenPassword, (FPD_Parser pParser,  FS_LPCWSTR password,  FS_LPVOID pClientData,  FRStartParserProc proc))

INTERFACE(FS_DWORD, FRInternalCheckOwerPassword, (FPD_Parser pParser,  const FS_LPCWSTR password,  FS_ByteString* csPassword))

INTERFACE(void, FRInternalSetTrialDay, (FS_INT32 days))

INTERFACE(void, FRInternalSetTotalTrialDay, (FS_INT32 totalTrialDay))

INTERFACE(void, FRInternalSetAgainCheckLisense, ())

INTERFACE(void, FRInternalFindAllBMNode, (FR_Document pDoc,  FS_PtrArray* BMDictArray,  FPD_Bookmark pBookMark))

INTERFACE(FS_BOOLEAN, FRInternalFixRules, (FR_AccessibilityFix fixObj,  FPD_Document pPDFDoc,  const FS_DWORD &FixRule,  FS_LPVOID pFixData))

INTERFACE(void, FRInternalSetCallBackProcess, (FR_AccessibilityFix fixObj,  FS_LPVOID pClientData,  FRInternalAccessibilityFixProc proc))

INTERFACE(FR_AccessibilityFix, FRInternalCreateAccessbilityFix, ())

INTERFACE(void, FRInternalReleaseAccessbilityFix, (FR_AccessibilityFix fixObj))

INTERFACE(void, FRInternalSetActionGoto, (FR_Document pDocument,  FPD_Object pHostDict,  FPD_Object* pDestArray,  FPD_AActionType eType,  FPD_Object pActionDict,  FPD_Object* pRetDict,  FPD_Object* pPrevDict,  FS_WideString* cwNamedDes,  FS_LPCSTR csKey))

INTERFACE(void, FRInternalSetActionURL, (FR_Document pDocument,  FPD_Object pHostDict,  const FS_LPCWSTR sURL,  FPD_AActionType eType,  FPD_Object pActionDict,  FPD_Object* pRetDict,  FPD_Object* pPrevDict))

INTERFACE(void, FRInternalSetActionLaunch, (FR_Document pDocument,  FPD_Object pHostDict,  const FS_LPCWSTR sFilePath,  FPD_AActionType eType,  FPD_Object pActionDict,  FPD_Object* pRetDict,  FPD_Object* pPrevDict))

INTERFACE(void, FRInternalSetActionNamed, (FR_Document pDocument,  FPD_Object pHostDict,  const FS_LPCSTR sMenuName,  FPD_AActionType eType,  FPD_Object pActionDict,  FPD_Object* pRetDict,  FPD_Object* pPrevDict))

INTERFACE(void, FRInternalSetActionImportData, (FR_Document pDocument,  FPD_Object pHostDict,  const FS_LPCWSTR sFilePath,  FPD_AActionType eType,  FPD_Object pActionDict,  FPD_Object* pRetDict,  FPD_Object* pPrevDict))

INTERFACE(void, FRInternalSetActionJavaScript, (FR_Document pDocument,  FPD_Object pHostDict,  const FS_LPCWSTR sJavaScript,  FPD_AActionType eType,  FPD_Object pActionDict,  FPD_Object* pRetDict,  FPD_Object* pPrevDict))

INTERFACE(FS_BOOLEAN, FRInternalCanUndo, (FR_Document pDocument))

INTERFACE(FS_BOOLEAN, FRInternalCanRedo, (FR_Document pDocument))

INTERFACE(void, FRInternalGridWindow2Doc, (FR_PageView pPageView,  FS_Rect rcWin,  FS_FloatRect* rcDoc))

INTERFACE(void, FRInternalGridWindow2Doc2, (FR_PageView pPageView,  FS_INT32 x,  FS_INT32 y,  FS_FLOAT* fx,  FS_FLOAT* fy))

INTERFACE(void, FRInternalSetSearchingTextFlag, (FR_Document doc,  FS_BOOL bIsSearchingText))

INTERFACE(FS_INT32, FRInternalGetTrialDays, ())

INTERFACE(FS_BOOL, FRInternalIsBlankPage, (FPD_Page page))

INTERFACE(FS_BOOLEAN, FRInternalAddAttachFile, (FR_Annot annot,  FS_WideString wsAttachFilePath))

INTERFACE(FS_BOOLEAN, FRInternalGetAttachFile, (FR_Annot annot,  FS_WideString wsAttachFilePath))

INTERFACE(FS_BOOL, FRInternalCheckIsFpeKey, ())

INTERFACE(void, FRInternalSetAgainCheckTrial, ())

INTERFACE(FR_TextMarkupAnnot, FRInternalGet, ())

INTERFACE(FS_BOOLEAN, FRInternalTextMarkupCreateAnnot, (FR_TextMarkupAnnot annot,  FR_Document pDoc,  FS_LPCSTR bsAnnotType,  FS_PtrArray highlightPos,  FR_TextMarkupPROGRESSCBK pFun,  FS_LPVOID pProgressCtrl))

INTERFACE(FS_BOOLEAN, FRInternalTextMarkupResetAnnot, (FR_TextMarkupAnnot annot,  FR_Document pDoc,  FS_INT32 iPageIndex,  FPD_Object pAnnotDic,  FPD_Object pNewArrQuad,  FS_BOOLEAN bAddUndo,  FS_AffineMatrix* pMatrix))

INTERFACE(FS_BOOLEAN, FRInternalTextMarkupDeleteAnnot, (FR_TextMarkupAnnot annot,  FR_Document pDoc,  FS_INT32 iPageIndex,  FPD_Object pAnnotDic,  FS_BOOLEAN bAddUndo))

INTERFACE(FS_BOOLEAN, FRInternalTextMarkupCloneAnnot, (FR_TextMarkupAnnot annot,  FR_Document pDoc,  FS_INT32 iSrcPageIndex,  FS_INT32 iDestPageIndex,  FPD_Object pAnnotDic,  FS_BOOLEAN bAddUndo,  FS_PtrArray* OutDicAnnots))

INTERFACE(void, FRInternalTextMarkupBeginModify, (FR_TextMarkupAnnot annot,  FR_Document pDoc,  FS_PtrArray annotDicts))

INTERFACE(void, FRInternalTextMarkupEndModify, (FR_TextMarkupAnnot annot,  FR_Document pDoc,  FS_PtrArray annotDicts,  FS_BOOLEAN  bEndDirectly))

INTERFACE(FPD_Object, FRInternalFAAItemObjectGetDic, (FR_FAAItemObject obj))

INTERFACE(void, FRInternalFAAItemObjectSetDic, (FR_FAAItemObject obj,  FPD_Object pDict))

INTERFACE(FS_INT32, FRInternalFAAItemObjectGetPageIndex, (FR_FAAItemObject obj))

INTERFACE(void, FRInternalFAAItemObjectSetPageIndex, (FR_FAAItemObject obj,  FS_INT32 nPage))

INTERFACE(void, FRInternalFAAItemObjectSetbAnnot, (FR_FAAItemObject obj,  FS_BOOLEAN bAnnot))

INTERFACE(FS_BOOLEAN, FRInternalFAAItemObjectGetbAnnot, (FR_FAAItemObject obj))

INTERFACE(void, FRInternalFAAItemObjectSetUFileName, (FR_FAAItemObject obj,  FS_LPCWSTR uName))

INTERFACE(void, FRInternalFAAItemObjectGetUFileName, (FR_FAAItemObject obj,  FS_WideString* uName))

INTERFACE(void, FRInternalFAAItemObjectSetFileName, (FR_FAAItemObject obj,  FS_LPCWSTR uName))

INTERFACE(void, FRInternalFAAItemObjectGetFileName, (FR_FAAItemObject obj,  FS_WideString* uName))

INTERFACE(void, FRInternalGetFileAttachmentObjects, (FPD_Document pPDFDoc,  FS_PtrArray* vecFAAItemObject))

INTERFACE(void, FRInternalReleaseFileAttachmentObjects, (FS_PtrArray vecFAAItemObject))

INTERFACE(FR_Document, FRInternalOpenFileAttachment, (FR_Document pRDDoc,  FPD_Object pFSDict))

INTERFACE(FR_Document, FRInternalOpenFileAttachment2, (FR_Document pDoc,  FS_LPCWSTR wsAttachPath))

INTERFACE(FS_BOOLEAN, FRInternalIsTextMark, (FPD_Document pPDFDoc,  FS_INT32 nPageIndex,  const FS_PtrArray rectPointArray))

INTERFACE(void, FRInternalDoSearchAndRedact, (FR_Document pDoc,  FS_INT32 nPageIndex,  const FS_PtrArray rectPointArray,  FS_BOOLEAN bApply,  FS_BOOLEAN bOpen,  FS_BOOL bAutoSize,  FS_LPCWSTR wsOverlayText))

INTERFACE(int, FRInternalApplyRedact, (FR_Document pDoc,  FS_BOOLEAN bOpen))

INTERFACE(FS_BOOLEAN, FRInternalIsDisableAdvertise, ())

INTERFACE(void, FRInternalGetSelectLoginMethods, (FS_WideString* outMethods))

INTERFACE(FS_LPCWSTR, FRInternalGetPackageLanguageName, ())

INTERFACE(FS_LPCWSTR, FRInternalGetPackageAgentName, ())

INTERFACE(FS_LPCWSTR, FRInternalGetServiceDomain, (FS_LPCWSTR wsServiceName))

INTERFACE(void, FRInternalAddToLog, (FS_LPCWSTR wsURL,  FS_LPCWSTR wsFeature))

INTERFACE(FS_BOOLEAN, FRInternalIsAttachCanOpen, (FS_LPCWSTR wsFileExt))

INTERFACE(FS_BOOLEAN, FRInternalCheckSecurity, (FS_LPCWSTR wsFilePath))

INTERFACE(FS_BOOLEAN, FRInternalShowAndCheckAttachFaileDlg, (const FS_WideStringArray arrSrcFiles,  FS_WideStringArray* arrValidFile,  FS_BOOLEAN bExtractFile))

INTERFACE(FS_BOOL, FRInternalIsDisableDefaultLaunchAttachmentPerms, (FS_BOOL* bDisableDefaultLaunchAttachmentPerms))

INTERFACE(FS_BOOL, FRInternalGetSubExpierDate, (FS_WideString* subExpierDate))

INTERFACE(void, FRInternalShowRibbonFilePage, ())

INTERFACE(FS_BOOLEAN, FRInternalRemoveFileAttachmentObject, (FS_LPCSTR csObjectName))

INTERFACE(void, FRInternalSetReplaceColors, (const FS_COLORREF clrDocFore,  const FS_COLORREF clrDocBack))

INTERFACE(void, FRInternalBFExportForm, (FS_LPCWSTR type))

INTERFACE(void, FRInternalFrameRemoveAllGroup, ())

INTERFACE(void, FRInternalFrameNewVertGroup, ())

INTERFACE(FS_BOOL, FRInternalGetLoginDomain, (FS_BOOL* bWhiteList,  FS_WideStringArray* wsLoginDomain))

INTERFACE(void, FRInternalExportComments, (FR_EXPORT_COMMENTS_TYPE type))

NumOfSelector(FRInternal)
ENDENUM

//*****************************
/* SpellCheck HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRSpellCheckNew
 * @details Creates a <a>FR_SpellCheck</a> object used to check spelling.
 * @param[in]  lpwsModuleName The input module name.
 * @return   A new <a>FR_SpellCheck</a> object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(FPD_SpellCheck, FRSpellCheckNew, (FS_LPCWSTR lpwsModuleName))

/**
 * @brief FRSpellCheckIgnore
 * @details Ignores the input words that will not be checked.
 * @param[in]  spellCheck The input <a>FPD_SpellCheck</a> object.
 * @param[in]  sWord The input words to be ignored.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRSpellCheckIgnore, (FPD_SpellCheck spellCheck,  FS_LPCWSTR sWord))

/**
 * @brief FRSpellCheckCheckString
 * @details Checks the spelling of the input byte string and receives the errors.
 * @param[in]  spellCheck The input <a>FPD_SpellCheck</a> object.
 * @param[in]  sString The input byte string that will be checked.
 * @param[out]  outErrBufArr It receives the errors.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRSpellCheckCheckWord
 */
INTERFACE(void, FRSpellCheckCheckString, (FPD_SpellCheck spellCheck,  FS_WideString sString,  FS_WideStringArray* outErrBufArr))

/**
 * @brief FRSpellCheckAddDic
 * @details Adds the new words to the dictionary.
 * @param[in]  spellCheck The input <a>FPD_SpellCheck</a> object.
 * @param[in]  sWord The input new words.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRSpellCheckNew
 */
INTERFACE(void, FRSpellCheckAddDic, (FPD_SpellCheck spellCheck,  FS_LPCWSTR sWord))

NumOfSelector(FRSpellCheck)
ENDENUM

//----------_V6----------
//----------_V7----------
//*****************************
/* HTMLMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRHTMLMgrGet
 * @details Gets the <a>FR_HTMLMgr</a> object is used to manage the HTML windows in <Italic>Foxit Reader</Italic>.
 * @return   The <a>FR_HTMLMgr</a> object is used to manage the HTML windows in <Italic>Foxit Reader</Italic>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FR_HTMLMgr, FRHTMLMgrGet, (void))

/**
 * @brief FRHTMLMgrRegisterHTMLEventHandler
 * @details Registers the HTML event handler.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  callbacks The callback set for HTML window event handler.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOL, FRHTMLMgrRegisterHTMLEventHandler, (FR_HTMLMgr mgr,  FR_HTMLEventCallbacks callbacks))

/**
 * @brief FRHTMLMgrOpenHTMLFromNewTab
 * @details Opens a new HTML window. Foxit Reader will create a new tab for the new HTML window.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpURL The input URL to be opened in the HTML window.
 * @param[in]  lpTitle The title of the frame which will be created.
 * @param[in]  bCreatePanel Whether to create the navigation panel or not.
 * @param[in]  bMakeVisible Determines whether to make the HTML window visible or not.
 * @param[in]  bAddToMRU Determines whether the filename is added to the most recently used (MRU) file list.
 * @return   The handle of the HTML window.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(HWND, FRHTMLMgrOpenHTMLFromNewTab, (FR_HTMLMgr mgr,  FS_LPCWSTR lpURL,  FS_LPCWSTR lpTitle,  FS_BOOL bCreatePanel,  FS_BOOL bMakeVisible,  FS_BOOL bAddToMRU))

/**
 * @brief FRHTMLMgrOpenHTMLDocument
 * @details Opens a new HTML window on the specified parent window.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpURL The input URL to be opened in the HTML window.
 * @param[in]  lpTitle The title of the frame which will be created.
 * @param[in]  hParentWnd The parent window of the HTML window.
 * @return   The handle of the HTML window.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(HWND, FRHTMLMgrOpenHTMLDocument, (FR_HTMLMgr mgr,  FS_LPCWSTR lpURL,  FS_LPCWSTR lpTitle,  HWND hParentWnd))

/**
 * @brief FRHTMLMgrGetActiveHtmlView
 * @details Opens a new HTML window on the specified parent window.
 * @param[in]  mgr The input HTML manager object.
 * @return   The pointer to <Italic>MFC CHtmlView</Italic>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void*, FRHTMLMgrGetActiveHtmlView, (FR_HTMLMgr mgr))

/**
 * @brief FRHTMLMgrRegisterFoxitBrowserEventHandler
 * @details Registers the Foxit browser event handler to receive the event notifications.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  callbacks The callback set for Foxit browser event handler.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOL, FRHTMLMgrRegisterFoxitBrowserEventHandler, (FR_HTMLMgr mgr,  FR_FoxitBrowserEventCallbacks callbacks))

/**
 * @brief FRHTMLMgrSetFoxitBrowserHome
 * @details Sets the home URL of the Foxit browser.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpURL The input URL.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRHTMLMgrSetFoxitBrowserHome, (FR_HTMLMgr mgr,  FS_LPCWSTR lpURL))

/**
 * @brief FRHTMLMgrSetFavoritesLink
 * @details Sets the favorite link to Foxit favorite bar.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpName The displaying name of the favorite link.
 * @param[in]  lpURL The input URL of the favorite link.
 * @param[in]  lpUrlIcon The URL of the displaying icon.
 * @param[in]  bAdd Whether to add the favorite link or to delete it.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRHTMLMgrSetFavoritesLink, (FR_HTMLMgr mgr,  FS_LPCWSTR lpName,  FS_LPCWSTR lpUrl,  FS_LPCWSTR lpUrlIcon,  FS_BOOL bAdd))

/**
 * @brief FRHTMLMgrGetHtmlViewFromHandle
 * @details Gets a new HTML window from the window handle.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  hWnd The input HTML view handle.
 * @return   The pointer to <Italic>MFC CHtmlView</Italic>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void*, FRHTMLMgrGetHtmlViewFromHandle, (FR_HTMLMgr mgr,  HWND hWnd))

/**
 * @brief FRHTMLMgrOpenHTMLFromNewTab2
 * @details Opens a new HTML window. Foxit Reader will create a new tab for the new HTML window.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpURL The input URL to be opened in the HTML window.
 * @param[in]  lpTitle The title of the frame which will be created.
 * @param[in]  bCreatePanel Whether to create the navigation panel or not.
 * @param[in]  bMakeVisible Determines whether to make the HTML window visible or not.
 * @param[in]  bAddToMRU Determines whether the filename is added to the most recently used (MRU) file list.
 * @param[in]  hIcon The icon added to the tab band.
 * @param[in]  bHideURL Whether to hide the URL or not.
 * @return   The handle of the HTML window.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(HWND, FRHTMLMgrOpenHTMLFromNewTab2, (FR_HTMLMgr mgr,  FS_LPCWSTR lpURL,  FS_LPCWSTR lpTitle,  FS_BOOL bCreatePanel,  FS_BOOL bMakeVisible,  FS_BOOL bAddToMRU,  HICON hIcon,  FS_BOOL bHideURL))

/**
 * @brief FRHTMLMgrOpenHTMLDocument2
 * @details Opens a new HTML window on the specified parent window.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpURL The input URL to be opened in the HTML window.
 * @param[in]  lpTitle The title of the frame which will be created.
 * @param[in]  hParentWnd The parent window of the HTML window.
 * @param[in]  bHideURL Whether to hide the URL or not.
 * @return   The handle of the HTML window.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(HWND, FRHTMLMgrOpenHTMLDocument2, (FR_HTMLMgr mgr,  FS_LPCWSTR lpURL,  FS_LPCWSTR lpTitle,  HWND hParentWnd,  FS_BOOL bHideURL))

NumOfSelector(FRHTMLMgr)
ENDENUM

//*****************************
/* PanelMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPanelMgrGetPanelMgrFromChildFrm
 * @details Gets the specified panel manager.
 * @param[in]  hChildFrm The specified child frame window which display the document. You can get it from <a>FRAppGetCurrentChildFrm</a>
 * @return   The specified panel manager by childframe windows handler.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_PanelMgr, FRPanelMgrGetPanelMgrFromChildFrm, (FS_HWND hChildFrm))

/**
 * @brief FRPanelMgrNewPanelMgr
 * @details Creates an instance of the panel manager.
 * @param[in]  hChildFrm The specified child frame window which display the document.You can get it from <a>FRAppGetCurrentChildFrm</a>
 * @return   The new panel manager.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRPanelMgrCreate
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_PanelMgr, FRPanelMgrNewPanelMgr, (FS_HWND hChildFrm))

/**
 * @brief FRPanelMgrDeletePanelMgr
 * @details Deletes the panel manager.
 * @param[in]  panelMgr The input panel manager.
 * @return   void.
 * @note It only used in windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrDeletePanelMgr, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrCreatePanelEventHandler
 * @details Creates the pointer to the panel event handler.
 * @param[in]  callbacks A callback set for the panel event handler.
 * @return   The pointer to the panel event handler.
 * @note It only used in windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRPanelMgrCreate
	
 * @Deprecated    Internal use.
 */
INTERFACE(void*, FRPanelMgrCreatePanelEventHandler, (FR_PanelEventCallbacks callbacks))

/**
 * @brief FRPanelMgrDestroyPanelEventHandler
 * @details Destroys the panel event handler.
 * @param[in]  panelEventHandler The pointer to the panel event handler.
 * @return   void.
 * @note It only used in windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRPanelMgrCreate
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrDestroyPanelEventHandler, (void* panelEventHandler))

/**
 * @brief FRPanelMgrCreate
 * @details Creates the panel manager after <a>FRPanelMgrNewPanelMgr</a>.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  pParentWnd The input parent window.
 * @param[in]  nTablocation Specifies the tab location. Related to <a>FRPanelLocation</a>
 * @param[in]  dwEnabledAlignment Specifies the enabled alignment. References to MFC ControlBar styles.
 * @param[in]  panelEventHandler (Only used in Windows)The input panel event handler to receive the event occurred.
 * @return   True for success, otherwise failure.
 * @note It only used in windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRPanelMgrNewPanelMgr
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPanelMgrCreate, (FR_PanelMgr panelMgr,  void* pParentWnd,  FS_INT32 nTablocation,  FS_DWORD dwEnabledAlignment,  void* panelEventHandler))

/**
 * @brief FRPanelMgrDockToFrameWindow
 * @details Docks the panel to the frame window.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  dwAlignment Specifies the alignment. References to MFC ControlBar styles.
 * @return   True for success, otherwise failure.
 * @note It only used in Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPanelMgrDockToFrameWindow, (FR_PanelMgr panelMgr,  FS_DWORD dwAlignment))

/**
 * @brief FRPanelMgrAddPanel
 * @details Adds a panel.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csToolTip The tool tip of the panel.
 * @param[in]  csText The display text of the panel.
 * @param[in]  csName The name of the panel.
 * @param[in]  pBitmap The icon of the panel.
 * @param[in]  bInitialShow Whether to show the panel at the first time.
 * @param[in]  bDockBottom Whether the panel is docked to the bottom or not.
 * @return   The handle to the panel.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_HWND, FRPanelMgrAddPanel, (FR_PanelMgr panelMgr,  FS_LPCWSTR csToolTip,  FS_LPCWSTR csText,  FS_LPCSTR csName,  FS_DIBitmap pBitmap,  FS_BOOL bInitialShow,  FS_BOOL bDockBottom))

/**
 * @brief FRPanelMgrShowAllPanel
 * @details Shows all the panels or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  bShow Shows all the panels or not.
 * @return   void.
 * @note It only used in Widnows
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrShowAllPanel, (FR_PanelMgr panelMgr,  FS_BOOL bShow))

/**
 * @brief FRPanelMgrShowPanelByName
 * @details Shows the specified panel or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @param[in]  bShow Shows the panel or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrShowPanelByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName,  FS_BOOL bShow))

/**
 * @brief FRPanelMgrResetAllPanels
 * @details Resets all the panels.
 * @param[in]  panelMgr The input panel manager.
 * @return   void.
 * @note It only used in Widnows
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrResetAllPanels, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrGetPanelHwndByName
 * @details Gets the window handle to the panel by name.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @return   The window handle of the panel.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_HWND, FRPanelMgrGetPanelHwndByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrIsAllPanelHide
 * @details Checks whether all the panels are hidden or not.
 * @param[in]  panelMgr The input panel manager.
 * @return   TRUE if all the panels are hidden, otherwise not.
 * @note It only used in Widnows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPanelMgrIsAllPanelHide, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrHasPanelFloating
 * @details Checks whether any panel is floating or not.
 * @param[in]  panelMgr The input panel manager.
 * @return   TRUE if any panel is floating, otherwise not.
 * @note It only used in Widnows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPanelMgrHasPanelFloating, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrIsPanelHide
 * @details Checks whether the specified panel is hidden or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @return   TRUE if the specified panel is hidden, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPanelMgrIsPanelHide, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrGetParentFrame
 * @details Gets the parent window handle.
 * @param[in]  panelMgr The input panel manager.
 * @return   The parent window handle.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_HWND, FRPanelMgrGetParentFrame, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrGetEnabledAlignment
 * @details Gets the enabled alignment. References to MFC ControlBar styles.
 * @param[in]  panelMgr The input panel manager.
 * @return   The enabled alignment. References to MFC ControlBar styles.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_DWORD, FRPanelMgrGetEnabledAlignment, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrGetPanelViewByName
 * @details Gets the specified panel view handle.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @return   The specified panel view handle.
 * @note It only used in Widnows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_HWND, FRPanelMgrGetPanelViewByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrGetPanelNameByIndex
 * @details Gets the specified panel name.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  nIndex Specifies the index of the panel.
 * @return   The specified panel name.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_LPCSTR, FRPanelMgrGetPanelNameByIndex, (FR_PanelMgr panelMgr,  FS_INT32 nIndex))

/**
 * @brief FRPanelMgrGetPanelCount
 * @details Gets the panel count.
 * @param[in]  panelMgr The input panel manager.
 * @return   The panel count.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPanelMgrGetPanelCount, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrGetPanelTabRectByPt
 * @details Gets the rectangle of the panel tab by point.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  x The horizon position.
 * @param[in]  y The vertical position.
 * @param[out]  outRtTab It receives the rectangle of the panel tab.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrGetPanelTabRectByPt, (FR_PanelMgr panelMgr,  FS_INT32 x,  FS_INT32 y,  FS_Rect* outRtTab))

/**
 * @brief FRPanelMgrGetPanelTabNameByPt
 * @details Gets the panel name by point.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  x The horizon position.
 * @param[in]  y The vertical position.
 * @return   The panel name.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_LPCSTR, FRPanelMgrGetPanelTabNameByPt, (FR_PanelMgr panelMgr,  FS_INT32 x,  FS_INT32 y))

/**
 * @brief FRPanelMgrGetPanelTabRectByName
 * @details Gets the rectangle of the panel tab by name.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName The input panel name.
 * @param[out]  outRtTab It receives the rectangle of the panel tab.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrGetPanelTabRectByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName,  FS_Rect* outRtTab))

/**
 * @brief FRPanelMgrHidePanelTabByName
 * @details Hides the specified panel by name when init view.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName The input panel name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrHidePanelTabByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrHasHistory
 * @details Checks whether the customer has configured the panel or not.
 * @param[in]  panelMgr The input panel manager.
 * @return   TRUE if the customer has configured the panel, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPanelMgrHasHistory, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrLockAllPanel
 * @details Locks all the panels.
 * @param[in]  panelMgr The input panel manager.
 * @return   void.
 * @note It only used in Widnows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrLockAllPanel, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrShowPanelByName2
 * @details Shows the specified panel or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @param[in]  bShow Shows the panel or not.
 * @param[in]  bActive Activates the panel or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrShowPanelByName2, (FR_PanelMgr panelMgr,  FS_LPCSTR csName,  FS_BOOL bShow,  FS_BOOL bActive))

/**
 * @brief FRPanelMgrIsPanelSpreadOut
 * @details Checks whether the panel is spread out or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @return   TRUE if the panel is spread out.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPanelMgrIsPanelSpreadOut, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrAddPanel2
 * @details Adds a panel.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csToolTip The tool tip of the panel.
 * @param[in]  csText The display text of the panel.
 * @param[in]  csName The name of the panel.
 * @param[in]  pBitmap The icon of the panel.
 * @param[in]  bInitialShow Whether to show the panel at the first time.
 * @param[in]  bDockBottom Whether the panel is docked to the bottom or not.
 * @param[in]  nPos The position where the panel will be added.
 * @return   The handle to the panel.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.0.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_HWND, FRPanelMgrAddPanel2, (FR_PanelMgr panelMgr,  FS_LPCWSTR csToolTip,  FS_LPCWSTR csText,  FS_LPCSTR csName,  FS_DIBitmap pBitmap,  FS_BOOL bInitialShow,  FS_BOOL bDockBottom,  FS_INT32 nPos))

/**
 * @brief FRPanelMgrRedockAllFloatToInitial
 * @details All floating panel is restored to the left side.
 * @param[in]  panelMgr The input panel manager.
 * @return   void.
 * @note It only used in Widnows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrRedockAllFloatToInitial, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrIsPanelFloating
 * @details Checks whether the panel is floating or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @return   TRUE if the panel is floating.
 * @note It only used in Widnows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPanelMgrIsPanelFloating, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrShrinkPanelByName
 * @details Shrink the specified panel by name.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName The input panel name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrShrinkPanelByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrShowOnlyTabBar
 * @details Hide current left panel, just show tab bar.
 * @param[in]  panelMgr The input panel manager.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPanelMgrShowOnlyTabBar, (FR_PanelMgr panelMgr))

NumOfSelector(FRPanelMgr)
ENDENUM

//----------_V8----------
//----------_V9----------
//*****************************
/* CloudLoginProvider HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRCloudLoginProviderSet
 * @details Sets the service provider of cloud login.
 * @param[in]  callbacks The callback set for the service provider of cloud login.
 * @return   The <a>* FR_CloudLoginProvider</a> object represents the service provider of cloud login. Destroys it by invoking <a>FRCloudLoginProviderDestroy</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderDestroy
	
 * @Deprecated    Internal use
 */
INTERFACE(FR_CloudLoginProvider, FRCloudLoginProviderSet, (FR_CloudLoginProviderCallbacks callbacks))

/**
 * @brief FRCloudLoginProviderDestroy
 * @details Destroys the service provider of cloud login.
 * @param[in]  loginProvider The input service provider of cloud login.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
	
 * @Deprecated    Internal use
 */
INTERFACE(void, FRCloudLoginProviderDestroy, (FR_CloudLoginProvider loginProvider))

/**
 * @brief FRCloudLoginProviderGet
 * @details Gets the service provider of cloud login.
 * @return   The service provider of cloud login.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
	
 * @Deprecated    Internal use
 */
INTERFACE(FR_CloudLoginProvider, FRCloudLoginProviderGet, ())

/**
 * @brief FRCloudLoginProviderIsLogIn
 * @details Checks whether the user has logged in or not.
 * @param[in]  loginProvider The input service provider of cloud login.
 * @return   TRUE indicates that the user has logged in, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
	
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOL, FRCloudLoginProviderIsLogIn, (FR_CloudLoginProvider loginProvider))

/**
 * @brief FRCloudLoginProviderSignIn
 * @details Signs into the cloud.
 * @param[in]  loginProvider The input service provider of cloud login.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
	
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOL, FRCloudLoginProviderSignIn, (FR_CloudLoginProvider loginProvider))

/**
 * @brief FRCloudLoginProviderSignOut
 * @details Signs out the cloud.
 * @param[in]  loginProvider The input service provider of cloud login.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
	
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOL, FRCloudLoginProviderSignOut, (FR_CloudLoginProvider loginProvider))

/**
 * @brief FRCloudLoginProviderGetUserInfo
 * @details Gets the user information.
 * @param[in]  loginProvider The input service provider of cloud login.
 * @param[out]  pUserInfo It receives the user information.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
	
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOL, FRCloudLoginProviderGetUserInfo, (FR_CloudLoginProvider loginProvider,  FR_Login_UserInfo* pUserInfo))

NumOfSelector(FRCloudLoginProvider)
ENDENUM

//----------_V10----------
//----------_V11----------
//----------_V12----------
//*****************************
/* AssistantMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRAssistantMgrGet
 * @details Gets the <a>FR_AssistantMgr</a> object is used to manage the Assistant windows in <Italic>Foxit Reader</Italic>.
 * @return   The <a>FR_AssistantMgr</a> object is used to manage the Assistant windows in <Italic>Foxit Reader</Italic>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_AssistantMgr, FRAssistantMgrGet, (void))

/**
 * @brief FRAssistantMgrSetCurAsstTrackWnd
 * @details void.
 * @param[in]  mgr The input Assistant manager object.
 * @param[in]  hTrackWnd A handler to the window.
 * @return   The <a>FR_AssistantMgr</a> object is used to manage the Assistant windows in <Italic>Foxit Reader</Italic>.
 * @note Set current track window on AsstBall follow
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAssistantMgrSetCurAsstTrackWnd, (FR_AssistantMgr mgr,  HWND hTrackWnd))

/**
 * @brief FRAssistantMgrUpdateAssistantHandler
 * @details update assistant button data
 * @param[in]  mgr The input Assistant manager object.
 * @param[in]  callbacks The event callbacks associate with a Assistant. When a event occurs, Reader will
	* call a corresponding callback function.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAssistantMgrUpdateAssistantHandler, (FR_AssistantMgr mgr,  FR_AssistantCallbacks callbacks))

/**
 * @brief FRAssistantMgrNotification
 * @details notification/toast.
 * @param[in]  mgr The input Assistant manager object.
 * @param[in]  nModuleID The input moudle identity number
 * @param[in]  asstNotify The input notification message..
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAssistantMgrNotification, (FR_AssistantMgr mgr,  UINT nModuleID,  FR_ASST_NOTIFY asstNotify))

/**
 * @brief FRAssistantMgrClearNotification
 * @details notification/toast.
 * @param[in]  mgr The input Assistant manager object.
 * @param[in]  nModuleID The input moudle identity number
 * @param[in]  nNotifyID The input notify/msg identity number
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAssistantMgrClearNotification, (FR_AssistantMgr mgr,  UINT nModuleID,  UINT nNotifyID))

/**
 * @brief FRAssistantMgrRegisterAsstUIHandler
 * @details Registers the Assistant UI handler.
 * @param[in]  mgr The input Assistant manager object.
 * @param[in]  callbacks The event callbacks associate with Assistant UI. When a event occurs, Reader will
	* call a corresponding callback function.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAssistantMgrRegisterAsstUIHandler, (FR_AssistantMgr mgr,  FR_AsstUICallbacks callbacks))

/**
 * @brief FRAssistantMgrUnRegisterAsstUIHandler
 * @details Unregisters the Assistant UI handler and releases the memory.
 * @param[in]  mgr The input Assistant manager object.
 * @param[in]  callbacks The event callbacks associate with Assistant UI. When a event occurs, Reader will
	* call a corresponding callback function.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAssistantMgrUnRegisterAsstUIHandler, (FR_AssistantMgr mgr,  FR_AsstUICallbacks callbacks))

/**
 * @brief FRAssistantMgrRegisterAssistantHandler
 * @details Registers the assistant handler.
 * @param[in]  mgr The input Assistant manager object.
 * @param[in]  callbacks The event callbacks associate with a assistant. When a event occurs, Reader will
	* call a corresponding callback function.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAssistantMgrRegisterAssistantHandler, (FR_AssistantMgr mgr,  FR_AssistantCallbacks callbacks))

/**
 * @brief FRAssistantMgrUnRegisterAssistantHandler
 * @details Unregisters the assistant handler and releases the memory.
 * @param[in]  mgr The input Assistant manager object.
 * @param[in]  callbacks The event callbacks associate with a assistant. When a event occurs, Reader will
	* call a corresponding callback function.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAssistantMgrUnRegisterAssistantHandler, (FR_AssistantMgr mgr,  FR_AssistantCallbacks callbacks))

/**
 * @brief FRAssistantMgrResetAssistantDlg
 * @details Reset assistant dialog.
 * @param[in]  mgr The input Assistant manager object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRAssistantMgrResetAssistantDlg, (FR_AssistantMgr mgr))

NumOfSelector(FRAssistantMgr)
ENDENUM

//----------_V13----------
//*****************************
/* IReader HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_IFX_InputMethod, FRIReaderGetInputMethod, (FR_PageView pageview))

NumOfSelector(FRIReader)
ENDENUM

//*****************************
/* IFX HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_INT64, FRIFXOnWindowProc, (FR_IFX_InputMethod inputMethod,  FS_UINT message,  FS_UINT wParam,  FS_INT64 lParam))

INTERFACE(void, FRIFXRegisterInputHandler, (FR_IFX_InputMethod inputMethod,  FR_IFX_InputMethodHandler pInterface))

INTERFACE(void, FRIFXUnRegisterInputHandler, (FR_IFX_InputMethod inputMethod))

INTERFACE(void, FRIFXEnterInputStatus, (FR_IFX_InputMethod inputMethod))

INTERFACE(void, FRIFXExitInputStatus, (FR_IFX_InputMethod inputMethod))

NumOfSelector(FRIFX)
ENDENUM

//*****************************
/* InputMethodHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_IFX_InputMethodHandler, FRInputMethodHandlerNew, (FR_IFX_InputMethodCallbacks callbacks))

INTERFACE(void, FRInputMethodHandlerDestroy, (FR_IFX_InputMethodHandler handler))

NumOfSelector(FRInputMethodHandler)
ENDENUM

//----------_V14----------
//*****************************
/* MarkAnnotHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FRMarkAnnotHandlerBeginTimer, (FR_MarkupAnnotHandler handler,  FS_INT32 nElapse))

INTERFACE(void, FRMarkAnnotHandlerEndTimer, (FR_MarkupAnnotHandler handler))

INTERFACE(void, FRMarkAnnotHandlerOnMoveOutPage, (FR_MarkupAnnotHandler handler,  FR_PageView pSrcPageView,  FR_PageView pDestPageView,  FR_Annot pAnnot,  const FS_Rect rcOrigin,  const FS_Rect rcNew,  FS_INT32 nIndex))

INTERFACE(FS_XMLElement, FRMarkAnnotHandlerCopyReply, (FR_MarkupAnnotHandler handler,  FR_Annot pAnnot))

INTERFACE(void, FRMarkAnnotHandlerDeleteAnnot, (FR_MarkupAnnotHandler handler,  FR_Annot pAnnot))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerIsDesigner, (FR_MarkupAnnotHandler handler,  const FS_LPCSTR sSubType))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerCanReSize, (FR_MarkupAnnotHandler handler,  const FS_LPCSTR sSubType))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerCanMove, (FR_MarkupAnnotHandler handler,  const FS_LPCSTR sSubType))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerCanAnswer, (FR_MarkupAnnotHandler handler,  FR_Annot pAnnot))

INTERFACE(void, FRMarkAnnotHandlerOnLoad, (FR_MarkupAnnotHandler handler,  FR_Annot pAnnot))

INTERFACE(FS_Rect, FRMarkAnnotHandlerGetViewBBox, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot))

INTERFACE(void, FRMarkAnnotHandlerOnDraw, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_WinPort winPort,  FR_Annot pAnnot,  FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device,  const FS_Rect rcWindow,  FS_DWORD dwFlags))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerOnLButtonDown, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  FS_UINT nFlags,  const FS_DevicePoint point))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerOnLButtonUp, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  FS_UINT nFlags,  const FS_DevicePoint point))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerOnMouseMove, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  FS_UINT nFlags,  const FS_DevicePoint point))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerOnLButtonDblClk, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  FS_UINT nFlags,  const FS_DevicePoint point))

INTERFACE(void, FRMarkAnnotHandlerOnDeSelected, (FR_MarkupAnnotHandler handler,  FR_Annot pAnnot))

INTERFACE(void, FRMarkAnnotHandlerOnSelected, (FR_MarkupAnnotHandler handler,  FR_Annot pAnnot))

INTERFACE(void, FRMarkAnnotHandlerOnPopupMenu, (FR_MarkupAnnotHandler handler,  const FS_ByteString sSubType,  FS_INT32 nIDAfter,  HMENU menu,  FS_INT32* ret))

INTERFACE(void, FRMarkAnnotHandlerOnPopupMenuItem, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  const FS_ByteString sSubType,  FS_INT32 nMenuItemID))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerIsMenuItemSupported, (FR_MarkupAnnotHandler handler,  const FS_ByteString sSubType,  FS_INT32 nMenuItem))

INTERFACE(FS_INT32, FRMarkAnnotHandlerGetMoveType, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  const FS_DevicePoint point))

INTERFACE(void, FRMarkAnnotHandlerOnMoving, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  FS_INT32 nMovingType,  const FS_DevicePoint ptOrigin,  const FS_DevicePoint ptOld,  const FS_DevicePoint ptNew,  FS_BOOL bFirst))

INTERFACE(void, FRMarkAnnotHandlerOnMoved, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  FS_INT32 nMovingType,  const FS_DevicePoint ptOrigin,  const FS_DevicePoint ptNew))

INTERFACE(void, FRMarkAnnotHandlerCancelMoving, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  FS_INT32 nMovingType,  const FS_DevicePoint ptOrigin,  const FS_DevicePoint ptNew))

INTERFACE(void, FRMarkAnnotHandlerOnMovedOutPage, (FR_MarkupAnnotHandler handler,  FR_PageView pSrcPageView,  FR_PageView pDestPageView,  FR_Annot pAnnot,  const FS_Rect rcOrigin,  const FS_Rect rcNew,  FS_INT32 nIndex))

INTERFACE(void, FRMarkAnnotHandlerOnSetPosition, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  const FS_FloatRect rect,  FS_INT32 nSrcType))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerOnMoving2, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  const FS_Rect rcOld,  const FS_Rect rcNew,  FS_BOOL bFirst))

INTERFACE(void, FRMarkAnnotHandlerOnMoved2, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  const FS_Rect rcOrigin,  const FS_Rect rcNew))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerOnResizing, (FR_MarkupAnnotHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  const FS_Rect rcOld,  const FS_Rect rcNew,  FS_BOOL bFirst))

INTERFACE(FS_XMLElement, FRMarkAnnotHandlerOnCopy, (FR_MarkupAnnotHandler handler,  FR_Annot pAnnot))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerOnSetFocus, (FR_MarkupAnnotHandler handler,  FR_Annot pAnnot))

INTERFACE(FS_BOOLEAN, FRMarkAnnotHandlerOnKillFocus, (FR_MarkupAnnotHandler handler,  FR_Annot pAnnot))

INTERFACE(void, FRMarkAnnotHandlerDeleteMarkupHandler, (FR_MarkupAnnotHandler handler))

INTERFACE(FR_MarkupAnnotHandler, FRMarkAnnotHandlerCreateMarkupHandler, (FRD_MarkupAnnotHandlerCallbacks callback))

INTERFACE(FR_BAAnnotHandler, FRMarkAnnotHandlerCastToBAAnnotHandler, (FR_MarkupAnnotHandler handler))

INTERFACE(void, FRMarkAnnotHandlerTimerProc, (FR_MarkupAnnotHandler handler))

INTERFACE(FS_LPVOID, FRMarkAnnotHandlerGetSystemHandler, (FR_MarkupAnnotHandler handler))

INTERFACE(FR_Annot, FRMarkAnnotHandlerOnPaste, (FR_MarkupAnnotHandler handler,  FS_XMLElement pElement,  FR_Page pPage,  const FS_FloatRect rcAnnot))

NumOfSelector(FRMarkAnnotHandler)
ENDENUM

//*****************************
/* ReaderUserMessageHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_ReaderUserMessageHandler, FRReaderUserMessageHandlerNew, (FR_ReaderUserMessageHandlerCallbacks callbacks))

INTERFACE(void, FRReaderUserMessageHandlerDestroy, (FR_ReaderUserMessageHandler handler))

NumOfSelector(FRReaderUserMessageHandler)
ENDENUM

//*****************************
/* IFieldMulCopiesNotify HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_IFieldMulCopiesNotify, FRIFieldMulCopiesNotifyNew, (FR_IFieldMulCopiesNotifyCallbacks callbacks))

INTERFACE(void, FRIFieldMulCopiesNotifyDestroy, (FR_IFieldMulCopiesNotify handler))

NumOfSelector(FRIFieldMulCopiesNotify)
ENDENUM

//*****************************
/* IActionWizardData HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_ActionWizardData, FRIActionWizardDataCreateIActionWizardData, ())

INTERFACE(void, FRIActionWizardDataSetRootXMLEle, (FR_ActionWizardData data,  FS_XMLElement pRootXMLEle))

INTERFACE(FS_BOOLEAN, FRIActionWizardDataSaveItemsDataToXML, (FR_ActionWizardData data,  const FS_WideStringArray csItems))

INTERFACE(FR_CMapItemNameToData, FRIActionWizardDataGetItemsDataFromXML, (FR_ActionWizardData data,  const FS_WideStringArray csItems))

INTERFACE(FS_XMLElement, FRIActionWizardDataGetItems, (FR_ActionWizardData data,  const FS_WideStringArray csItems))

INTERFACE(FS_INT32, FRIActionWizardDataGetItemDataFromXMLINT, (FR_ActionWizardData data,  FS_XMLElement pxmlItems,  const FS_ByteString bsItemName,  const FS_INT32 nDefaultValue))

INTERFACE(FS_FLOAT, FRIActionWizardDataGetItemDataFromXMLFLOAT, (FR_ActionWizardData data,  FS_XMLElement pxmlItems,  const FS_ByteString bsItemName,  const FS_FLOAT fDefaultValue))

INTERFACE(FS_BOOLEAN, FRIActionWizardDataGetItemDataFromXMLBOOL, (FR_ActionWizardData data,  FS_XMLElement pxmlItems,  const FS_ByteString bsItemName,  const FS_BOOLEAN bDefaultValue))

INTERFACE(void, FRIActionWizardDataGetItemDataFromXMLString, (FR_ActionWizardData data,  FS_XMLElement pxmlItems,  const FS_ByteString bsItemName,  const FS_LPWSTR wsDefaultValue,  FS_WideString* outData))

INTERFACE(void, FRIActionWizardDataSaveItemDataToXMLBOOL, (FR_ActionWizardData data,  FS_XMLElement pxmlItems,  const FS_ByteString bsItemName,  const FS_BOOLEAN bSrc))

INTERFACE(void, FRIActionWizardDataSaveItemDataToXMLINT, (FR_ActionWizardData data,  FS_XMLElement pxmlItems,  const FS_ByteString bsItemName,  const FS_INT32 nSrc))

INTERFACE(void, FRIActionWizardDataSaveItemDataToXMLFLOAT, (FR_ActionWizardData data,  FS_XMLElement pxmlItems,  const FS_ByteString bsItemName,  const FS_FLOAT fSrc))

INTERFACE(void, FRIActionWizardDataSaveItemDataToXMLWCHAR, (FR_ActionWizardData data,  FS_XMLElement pxmlItems,  const FS_ByteString bsItemName,  const FS_LPWSTR strSrc,  const FR_ActionWizardItmeDataType dataType))

INTERFACE(void, FRIActionWizardDataSaveItemDataToXMLSTRING, (FR_ActionWizardData data,  FS_XMLElement pxmlItems,  const FS_ByteString bsItemName,  const FS_WideString wsSrc,  const FR_ActionWizardItmeDataType dataType))

INTERFACE(void, FRIActionWizardDataDestroyIActionWizardData, (FR_ActionWizardData data))

INTERFACE(FS_DWORD, FRIActionWizardDataGetItemsChidrenCount, (FR_ActionWizardData data,  const FS_WideStringArray csItems))

NumOfSelector(FRIActionWizardData)
ENDENUM

//*****************************
/* CMapItemNameToData HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FRCMapItemNameToDataSetItemDataBOOL, (FR_CMapItemNameToData data,  const FS_ByteString bsItemName,  FS_BOOLEAN bSrc))

INTERFACE(void, FRCMapItemNameToDataSetItemDataINT, (FR_CMapItemNameToData data,  const FS_ByteString bsItemName,  FS_INT32 nSrc))

INTERFACE(void, FRCMapItemNameToDataSetItemDataFLOAT, (FR_CMapItemNameToData data,  const FS_ByteString bsItemName,  FS_FLOAT fSrc))

INTERFACE(void, FRCMapItemNameToDataSetItemDataWCHAR, (FR_CMapItemNameToData data,  const FS_ByteString bsItemName,  const FS_LPWSTR wcSrc,  const FR_ActionWizardItmeDataType dataType))

INTERFACE(void, FRCMapItemNameToDataSetItemDataSTRING, (FR_CMapItemNameToData data,  const FS_ByteString bsItemName,  const FS_WideString wsSrc,  const FR_ActionWizardItmeDataType dataType))

INTERFACE(FS_INT32, FRCMapItemNameToDataGetItemDataINT, (FR_CMapItemNameToData data,  const FS_ByteString bsItemName,  const FS_INT32 nDefaultValue))

INTERFACE(FS_FLOAT, FRCMapItemNameToDataGetItemDataFLOAT, (FR_CMapItemNameToData data,  const FS_ByteString bsItemName,  const FS_FLOAT fDefaultlValue))

INTERFACE(FS_BOOLEAN, FRCMapItemNameToDataGetItemDataBOOL, (FR_CMapItemNameToData data,  const FS_ByteString bsItemName,  const FS_BOOLEAN bDefaultValue))

INTERFACE(void, FRCMapItemNameToDataGetItemDataSTRING, (FR_CMapItemNameToData data,  const FS_ByteString bsItemName,  const FS_LPWSTR wsDefaultValue,  FS_WideString* outdata))

INTERFACE(FS_BOOLEAN, FRCMapItemNameToDataCheckKeyExist, (FR_CMapItemNameToData data,  const FS_LPCSTR bsItemName))

INTERFACE(FS_BOOLEAN, FRCMapItemNameToDataIsEmpty, (FR_CMapItemNameToData data))

INTERFACE(FS_INT32, FRCMapItemNameToDataGetCount, (FR_CMapItemNameToData data))

INTERFACE(void, FRCMapItemNameToDataRemoveAt, (FR_CMapItemNameToData data,  const FS_LPCSTR bsItemName))

INTERFACE(void, FRCMapItemNameToDataRemovAll, (FR_CMapItemNameToData data))

NumOfSelector(FRCMapItemNameToData)
ENDENUM

//*****************************
/* ReaderUIMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRReaderUIMgrShowFilePasswordDlg
 * @details The dialog support PDF2.0, support unicode.
 * @param[in]  filPath The path of the open document.
 * @param[out]  password The password of the user to input in the password dialog.
 * @param[hParent]  hParent A platform-specific object.	In windows, it is a HWND handler.
 * @param[in]  bPDF2 If need to support PDF2.0.
 * @return   FS_INT32.				Return 0 means false.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRReaderUIMgrShowFilePasswordDlg, (FS_LPCWSTR filPath,  FS_WideString* password,  HWND hParent,  FS_BOOLEAN bPDF2))

/**
 * @brief FRReaderUIMgrGetReaderThemeObject
 * @details Get the ReaderTheme object.
 * @return   FR_ReaderTheme.				.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_ReaderTheme, FRReaderUIMgrGetReaderThemeObject, ())

NumOfSelector(FRReaderUIMgr)
ENDENUM

//*****************************
/* ReaderTheme HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRReaderThemeGetBkGroundColor
 * @details Return the current skin color.
 * @param[in]  theme The input theme object.
 * @param[in]  pWnd The HWND of the control or window.
 * @return   FS_COLORREF.		Return backgroud color.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_COLORREF, FRReaderThemeGetBkGroundColor, (FR_ReaderTheme theme,  FS_HWND pWnd))

/**
 * @brief FRReaderThemeInstallSkinTheme
 * @details Install skin theme, used to change skin.
 * @param[in]  theme The input theme object.
 * @param[in]  pWnd The HWND of the control or window.
 * @return   FS_BOOL.		    Return TRUE is install skin success.
 * @note It can't support change to dark skin.
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRReaderThemeInstallSkinTheme, (FR_ReaderTheme theme,  FS_HWND pWnd))

/**
 * @brief FRReaderThemeInstallSkinTheme2
 * @details Install skin theme, used to change skin.
 * @param[in]  theme The input theme object.
 * @param[in]  pWnd The HWND of the control or window.
 * @return   FS_BOOL.		    Return TRUE is install skin success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRReaderThemeInstallSkinTheme2, (FR_ReaderTheme theme,  FS_HWND pWnd))

/**
 * @brief FRReaderThemeRegistSkinChangeProc
 * @details Register skin change callback.
 * @param[in]  theme The input theme object.
 * @param[in]  hWnd The HWND of the control or window.
 * @param[in]  proc The skin changed proc.
 * @param[in]  pClientData The client data.
 * @return   FS_BOOL.		    Return TRUE is register callback success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRReaderThemeRegistSkinChangeProc, (FR_ReaderTheme theme,  FS_HWND hWnd,  FRSkinChangeProc proc,  FS_LPVOID pClientData))

/**
 * @brief FRReaderThemeUnRegistSkinChangeProc
 * @details Unregister skin change callback.
 * @param[in]  theme The input theme object.
 * @param[in]  pWnd The HWND of the control or window.
 * @return   FS_BOOL.		    Return TRUE is unregister skin change callback.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRReaderThemeUnRegistSkinChangeProc, (FR_ReaderTheme theme,  FS_HWND hWnd))

/**
 * @brief FRReaderThemeGetSkinStyle
 * @details Install skin theme, used to change skin.
 * @param[in]  theme The input theme object.
 * @return   FR_SKINSTYLE		Return skin style.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_SKINSTYLE, FRReaderThemeGetSkinStyle, (FR_ReaderTheme theme))

/**
 * @brief FRReaderThemeGetWindowColor
 * @details Get the color of window.
 * @param[in]  theme The input theme object.
 * @return   FS_COLORREF		Return the color of window.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_COLORREF, FRReaderThemeGetWindowColor, (FR_ReaderTheme theme))

/**
 * @brief FRReaderThemeGetWindowTextColor
 * @details Get the text color in window.
 * @param[in]  theme The input theme object.
 * @return   FS_COLORREF		Return text color in window.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_COLORREF, FRReaderThemeGetWindowTextColor, (FR_ReaderTheme theme))

/**
 * @brief FRReaderThemeGetAppColor
 * @details Get the current color of app.
 * @param[in]  theme The input theme object.
 * @return   FS_COLORREF		Return the current color of app.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_COLORREF, FRReaderThemeGetAppColor, (FR_ReaderTheme theme))

/**
 * @brief FRReaderThemeGetLeftPanelSeparatorColor
 * @details Get the spearator color of left panel.
 * @param[in]  theme The input theme object.
 * @return   FS_COLORREF		Return the spearator color of left panel.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_COLORREF, FRReaderThemeGetLeftPanelSeparatorColor, (FR_ReaderTheme theme))

/**
 * @brief FRReaderThemeGetWindow2Color
 * @details Get the spearator color of left panel.
 * @param[in]  theme The input theme object.
 * @return   FS_COLORREF		Return window color.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_COLORREF, FRReaderThemeGetWindow2Color, (FR_ReaderTheme theme))

/**
 * @brief FRReaderThemeSetBkGroundColor
 * @details Set background color.
 * @param[in]  theme The input theme object.
 * @param[in]  pWnd The input CWnd* object.
 * @param[in]  clrBkGround The input background color.
 * @param[in]  bRedraw TRUE: need redraw.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRReaderThemeSetBkGroundColor, (FR_ReaderTheme theme,  FS_LPVOID pWnd,  FS_COLORREF clrBkGround,  FS_BOOL bRedraw))

/**
 * @brief FRReaderThemeEnableWindowRoundedCorners
 * @details Enable windows rounded corners.
 * @param[in]  theme The input theme object.
 * @param[in]  pWnd The input HWND object.
 * @param[in]  type The input windows corner type.
 * @return   FS_BOOL
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRReaderThemeEnableWindowRoundedCorners, (FR_ReaderTheme theme,  FS_HWND hwnd,  FR_WINDOW_CORNER_TYPE type))

/**
 * @brief FRReaderThemeGetColor
 * @details Get color by color name.
 * @param[in]  theme The input theme object.
 * @param[in]  name The input color name, it can get from starship\lib\Skins\Ribbon\Black\Black.xml.
 * @param[in]  bLight If need to do the skin switch.
 * @return   FS_COLORREF
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_COLORREF, FRReaderThemeGetColor, (FR_ReaderTheme theme,  FS_LPCWSTR name,  FS_BOOL bLight))

/**
 * @brief FRReaderThemeGetColorMap
 * @details Retrieves the color mapping of the current skin based on the bLightDefault parameter.
 * @param[in]  theme The input theme object.
 * @param[in]  mapColor It should be set the pointer of std::map<CString, COLORREF>& mapColor.
 * @param[in]  bLightDefault If bLightDefault is TRUE, it returns m_mpDefaultEntitiesColor. If it's FALSE, it returns m_mpEntitiesColor.
 * @return   FS_BOOL
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRReaderThemeGetColorMap, (FR_ReaderTheme theme,  void* mapColor,  FS_BOOL bLightDefault))

NumOfSelector(FRReaderTheme)
ENDENUM

//*****************************
/* PluginsMamager HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPluginsMamagerLoadPlugin
 * @details Load the plugin by name
 * @param[in]  PlugName The input pluginName.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPluginsMamagerLoadPlugin, (FS_LPCWSTR pluginName))

/**
 * @brief FRPluginsMamagerIsLoadedPlugin
 * @details Check the plugin if it has been loaded.
 * @param[in]  pluginName The input plugin name need to check if it has been loaded.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRPluginsMamagerIsLoadedPlugin, (FS_LPCSTR pluginName))

/**
 * @brief FRPluginsMamagerIsDisabledPlugin
 * @details Check the plugin if it has been disabled.
 * @param[in]  pluginName The input plugin name need to check if it has been loaded.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRPluginsMamagerIsDisabledPlugin, (FS_LPCWSTR pluginName))

/**
 * @brief FRPluginsMamagerIsPluginNeedLoadByGPO
 * @details Check the plugin if it need be load by GPO setting.
 * @param[in]  pluginName The input plugin name need to check if it has been loaded.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPluginsMamagerIsPluginNeedLoadByGPO, (FS_LPCWSTR pluginName))

NumOfSelector(FRPluginsMamager)
ENDENUM

//*****************************
/* IReplaceAllNotify HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOL, FRIReplaceAllNotifyReplaceAllProc, (FR_IReplaceAllNotify notify,  FR_ReplaceAllNotifyData data))

NumOfSelector(FRIReplaceAllNotify)
ENDENUM

//*****************************
/* IFindReplaceMgr HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_FindReplaceMgr, FRIFindReplaceMgrNew, (FR_FindReplaceMgrCallbacks callbacks))

INTERFACE(void, FRIFindReplaceMgrDestroy, (FR_FindReplaceMgr mgr))

INTERFACE(void, FRIFindReplaceMgrSetToMgr, (FR_FindReplaceMgr mgr))

NumOfSelector(FRIFindReplaceMgr)
ENDENUM

//*****************************
/* PDFBitmap HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPDFBitmapDraw
 * @details Draw PDFBitmap
 * @param[in]  hDC Render device
 * @param[in]  iconRect the rect of PDFBitmap need to render
 * @param[in]  wsPDFBitmapName the name of the PDFBitmap, which is from the bookmark of \res\ribbon\ribbonimage.pdf
 * @param[in]  bDisable <a>TRUE</a> means drawing PDFBitmap as disable mode, otherwise not.
 * @param[in]  clrBack background color
 * @param[in]  clrReplace replaced color
 * @param[in]  bAlpha <a>TRUE</a> means drawing PDFBitmap as transparency.if it is TRUE, clrBack param will be ignore.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPDFBitmapDraw, (FS_HDC hDC,  FS_FloatRect iconRect,  FS_LPCWSTR wsPDFBitmapName,  FS_BOOL bDisable,  FS_COLORREF clrBack,  FS_COLORREF clrReplace,  FS_BOOL bAlpha))

/**
 * @brief FRPDFBitmapGetBitmap
 * @details Get HBITMAP of specified image name from ribbonimage-phantom.pdf.
 * @param[in]  wsImageName It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf.
 * @param[in]  cx Set the width of the image.
 * @param[in]  cy Set the height of the image.
 * @param[in]  clrReplace Set fill color of the image.
 * @return   HBITMAP
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(HBITMAP, FRPDFBitmapGetBitmap, (FS_WideString wsImageName,  FS_INT32 cx,  FS_INT32 cy,  FS_COLORREF clrReplace))

/**
 * @brief FRPDFBitmapGetBitmapFromPDFIcon
 * @details Get FS_DIBitmap of specified image name from ribbonimage-phantom.pdf.
 * @param[in]  wsImageName It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf.
 * @param[in]  cx Set the width of the image.
 * @param[in]  cy Set the height of the image.
 * @param[in]  clrReplace Set fill color of the image.
 * @return   FS_DIBitmap
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_DIBitmap, FRPDFBitmapGetBitmapFromPDFIcon, (FS_LPCWSTR wsImageName,  FS_INT32 cx,  FS_INT32 cy,  FS_COLORREF clrReplace))

/**
 * @brief FRPDFBitmapFillRoundedRectangle
 * @details Fill round rectangle of specified property.
 * @param[in]  pDC The input CDC object.
 * @param[in]  rect The input rounded rect.
 * @param[in]  clrFill The input fill color.
 * @param[in]  ptRoundRadius The input point of round radius.
 * @return   void
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFBitmapFillRoundedRectangle, (FS_LPVOID pDC,  FS_Rect rect,  FS_COLORREF clrFill,  FS_DevicePoint ptRoundRadius))

/**
 * @brief FRPDFBitmapDrawRoundedRectangle
 * @details Draw round rectangle of specified property.
 * @param[in]  pDC The input CDC object.
 * @param[in]  rect The input rounded rect.
 * @param[in]  clrFill The input fill color.
 * @param[in]  ptRoundRadius The input point of round radius.
 * @return   void
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFBitmapDrawRoundedRectangle, (FS_LPVOID pDC,  FS_Rect rect,  FS_COLORREF clrLine,  FS_DevicePoint ptRoundRadius,  FS_INT32 nLineWidth,  FS_INT32 nPenStyle))

/**
 * @brief FRPDFBitmapDraw2
 * @details Draw PDFBitmap
 * @param[in]  hDC Render device
 * @param[in]  iconRect the rect of PDFBitmap need to render
 * @param[in]  wsPDFBitmapName the name of the PDFBitmap, which is from the bookmark of \res\ribbon\ribbonimage.pdf
 * @param[in]  bDisable <a>TRUE</a> means drawing PDFBitmap as disable mode, otherwise not.
 * @param[in]  clrBack background color
 * @param[in]  clrReplace replaced color
 * @param[in]  bAlpha <a>TRUE</a> means drawing PDFBitmap as transparency.if it is TRUE, clrBack param will be ignore.
 * @param[in]  style The input skin style.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPDFBitmapDraw2, (FS_HDC hDC,  FS_FloatRect iconRect,  FS_LPCWSTR wsPDFBitmapName,  FS_BOOL bDisable,  FS_COLORREF clrBack,  FS_COLORREF clrReplace,  FS_BOOL bAlpha,  FR_SKINSTYLE style))

/**
 * @brief FRPDFBitmapGetBitmap2
 * @details Get HBITMAP of specified image name from ribbonimage-phantom.pdf.
 * @param[in]  wsImageName It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf.
 * @param[in]  cx Set the width of the image.
 * @param[in]  cy Set the height of the image.
 * @param[in]  clrReplace Set fill color of the image.
 * @param[in]  style The input skin style.
 * @return   HBITMAP
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(HBITMAP, FRPDFBitmapGetBitmap2, (FS_LPCWSTR wsImageName,  FS_INT32 cx,  FS_INT32 cy,  FS_COLORREF clrReplace,  FR_SKINSTYLE style))

/**
 * @brief FRPDFBitmapGetFXBitmap
 * @details Get FS_DIBitmap of specified image name from ribbonimage-phantom.pdf.
 * @param[in]  wsImageName It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf.
 * @param[in]  cx Set the width of the image.
 * @param[in]  cy Set the height of the image.
 * @param[in]  clrReplace Set fill color of the image.
 * @param[in]  dwSytle The input skin style.
 * @return   FS_DIBitmap
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_DIBitmap, FRPDFBitmapGetFXBitmap, (FS_LPCWSTR wsImageName,  FS_INT32 cx,  FS_INT32 cy,  FS_COLORREF clrReplace,  FR_SKINSTYLE dwSytle))

NumOfSelector(FRPDFBitmap)
ENDENUM

//*****************************
/* Accessibility HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRAccessibilityIsScreenReaderRunning
 * @details Check screen reader is running.(for jaws library).
 * @return   FS_BOOL
 * @note 
 * @see <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRAccessibilityIsScreenReaderRunning, ())

/**
 * @brief FRAccessibilityIsATSupportEnabled
 * @details Check Assistive Technology Support is enabled.
 * @return   FS_BOOL
 * @note 
 * @see <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRAccessibilityIsATSupportEnabled, ())

NumOfSelector(FRAccessibility)
ENDENUM

//*****************************
/* AppUIStyle HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRAppUIStyleGetAppColor
 * @details Get color when the control focused.
 * @param[out]  clrColor The color when the control focused.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRAppUIStyleGetAppColor, (FS_COLORREF* clrColor))

/**
 * @brief FRAppUIStyleGetRibbonImageScale
 * @details Get scale of ribbion image.
 * @return   FS_FLOAT
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_FLOAT, FRAppUIStyleGetRibbonImageScale, ())

NumOfSelector(FRAppUIStyle)
ENDENUM

//----------_V15----------
//----------_V16----------
//*****************************
/* UIMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRUIMgrSplitChildFrameColumn
 * @details Split frame in vertical orientation.
 * @param[in]  hChildFrame The frame need to split.
 * @param[in]  cxBefore The width of the left view.
 * @param[in]  pCreateProc The create window proc.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRUIMgrSplitChildFrameColumn, (FS_HWND hChildFrame,  FS_INT32 cxBefore,  FRCreateSplitWndProc pCreateProc))

/**
 * @brief FRUIMgrSplitChildFrameRow
 * @details Split frame in horizontal orientation.
 * @param[in]  hChildFrame The frame need to split.
 * @param[in]  cyBefore The height of the top view.
 * @param[in]  pCreateProc The create window proc.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRUIMgrSplitChildFrameRow, (FS_HWND hChildFrame,  FS_INT32 cyBefore,  FRCreateSplitWndProc pCreateProc))

/**
 * @brief FRUIMgrDeleteSplitNewWnd
 * @details Delete split frame.
 * @param[in]  hChildFrame The split frame need to delete.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRUIMgrDeleteSplitNewWnd, (FS_HWND hChildFrame))

/**
 * @brief FRUIMgrSetFloatyTransparency
 * @details Set transparene of the floaty window.
 * @param[in]  hChildFrame The CMiniFrameWnd pointer of the floaty window .
 * @param[in]  nTransparency The transparence value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRUIMgrSetFloatyTransparency, (FS_LPVOID pFloaty,  FS_BYTE nTransparency))

/**
 * @brief FRUIMgrAddFloatyBarBtn
 * @details Add floaty bar button.
 * @param[in]  ribbonInfo The CMiniFrameWnd pointer of the floaty window .
 * @param[in]  bSyncOriginalCkeck The transparence value.
 * @param[in]  bLargeBtn The transparence value.
 * @return   FR_RibbonElement
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_RibbonElement, FRUIMgrAddFloatyBarBtn, (FR_RIBBONBUTTONINFO ribbonInfo,  FS_BOOL bSyncOriginalCkeck,  FS_BOOL bLargeBtn))

/**
 * @brief FRUIMgrCreateRibbonFloaty
 * @details Return floating layer menu pointer CMiniFrameWnd - can be used to do moves etc.
 * @param[in]  point The positon of the floaty.
 * @param[in]  nRows The input rows.
 * @param[in]  bTransparent The transparence value.
 * @return   FS_LPVOID
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_LPVOID, FRUIMgrCreateRibbonFloaty, (FS_DevicePoint point,  FS_INT32 nRows,  FS_BOOL bTransparent))

/**
 * @brief FRUIMgrInsertRibbonBtnsAfterFloatyCreate
 * @details Insert buttons to floaty.
 * @param[in]  vecBtnName The arry of button names.
 * @param[in]  nPos The insert position.
 * @return   void
 * @note It only for windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRUIMgrInsertRibbonBtnsAfterFloatyCreate, (FS_ByteStringArray vecBtnName,  FS_INT32 nPos))

/**
 * @brief FRUIMgrRemoveFloatyRibbonBtns
 * @details Remove button from floaty bar.
 * @param[in]  vecBtnName The arry of button names.
 * @return   void
 * @note It only for windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRUIMgrRemoveFloatyRibbonBtns, (FS_ByteStringArray vecBtnName))

/**
 * @brief FRUIMgrGetDocTabIcon
 * @details Get the tab icon.
 * @param[in]  hChildFrame The current child frame.
 * @return   FS_ICON
 * @note It only for windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_ICON, FRUIMgrGetDocTabIcon, (FS_HWND hChildFrame))

/**
 * @brief FRUIMgrGetPDFChildFrmSplitWndRect
 * @details Get the child frame rect.
 * @return   FS_Rect
 * @note It only for windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_Rect, FRUIMgrGetPDFChildFrmSplitWndRect, ())

/**
 * @brief FRUIMgrChangeUIRTL
 * @details Change UI RTL.
 * @param[in]  pWnd The input CWnd* object.
 * @param[in]  bNoLoopOverPopup Whether need no loop over popup.
 * @return   void
 * @note It only for windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRUIMgrChangeUIRTL, (FS_LPVOID pWnd,  FS_BOOL bNoLoopOverPopup))

NumOfSelector(FRUIMgr)
ENDENUM

//*****************************
/* ContainerFrmMgrHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRContainerFrmMgrHandlerNew
 * @details Create FR_ContainerFrmMgrHandler.
 * @param[in]  callbacks The ContainerFrmEventCallbacks.
 * @return   FR_ContainerFrmMgrHandler
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_ContainerFrmMgrHandler, FRContainerFrmMgrHandlerNew, (FR_ContainerFrmEventCallbacks callbacks))

/**
 * @brief FRContainerFrmMgrHandlerDestroy
 * @details Delete FR_ContainerFrmMgrHandler.
 * @param[in]  handler The FR_ContainerFrmMgrHandler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRContainerFrmMgrHandlerDestroy, (FR_ContainerFrmMgrHandler handler))

NumOfSelector(FRContainerFrmMgrHandler)
ENDENUM

//*****************************
/* ContainerFrmMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRContainerFrmMgrGetContainerFrmMgr
 * @details Get FR_ContainerFrmMgr.
 * @return   FR_ContainerFrmMgr
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_ContainerFrmMgr, FRContainerFrmMgrGetContainerFrmMgr, ())

/**
 * @brief FRContainerFrmMgrCreateContainerFrame
 * @details Create container frame of parent wnd.
 * @param[in]  containerMgr The FR_ContainerFrmMgr.
 * @param[in]  pParent The parent frame Cwnd.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_HWND, FRContainerFrmMgrCreateContainerFrame, (FR_ContainerFrmMgr containerMgr,  FS_LPVOID pParent))

/**
 * @brief FRContainerFrmMgrGetContainerFrame
 * @details Get the hwnd of the container.
 * @param[in]  containerMgr The FR_ContainerFrmMgr.
 * @param[in]  pRDDoc The current document.
 * @return   FS_HWND
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_HWND, FRContainerFrmMgrGetContainerFrame, (FR_ContainerFrmMgr containerMgr,  FR_Document pRDDoc))

/**
 * @brief FRContainerFrmMgrOpenDocument
 * @details Get the document.
 * @param[in]  containerMgr The FR_ContainerFrmMgr.
 * @param[in]  hMainFrm The container frame.
 * @param[in]  csFilePath The open file path.
 * @return   FR_Document
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_Document, FRContainerFrmMgrOpenDocument, (FR_ContainerFrmMgr containerMgr,  FS_HWND hMainFrm,  FS_WideString csFilePath))

/**
 * @brief FRContainerFrmMgrRegisterContainerFrmEventHandler
 * @details true means register handler success.
 * @param[in]  containerMgr The FR_ContainerFrmMgr.
 * @param[in]  pFrmEvent The input handler.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRContainerFrmMgrRegisterContainerFrmEventHandler, (FR_ContainerFrmMgr containerMgr,  FR_ContainerFrmMgrHandler pFrmEvent))

/**
 * @brief FRContainerFrmMgrUnRegisterContainerFrmEventHandler
 * @details true means unregister handler success.
 * @param[in]  containerMgr The FR_ContainerFrmMgr.
 * @param[in]  pFrmEvent The input handler.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRContainerFrmMgrUnRegisterContainerFrmEventHandler, (FR_ContainerFrmMgr containerMgr,  FR_ContainerFrmMgrHandler pFrmEvent))

/**
 * @brief FRContainerFrmMgrOnContainerFrmCreate
 * @details Trigger the create container frame.
 * @param[in]  containerMgr The FR_ContainerFrmMgr.
 * @param[in]  hFrmWnd The input handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRContainerFrmMgrOnContainerFrmCreate, (FR_ContainerFrmMgr containerMgr,  FS_HWND hFrmWnd))

/**
 * @brief FRContainerFrmMgrOnContainerFrmLoadFinish
 * @details Trigger the container frame load finish.
 * @param[in]  containerMgr The FR_ContainerFrmMgr.
 * @param[in]  hFrmWnd The input handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRContainerFrmMgrOnContainerFrmLoadFinish, (FR_ContainerFrmMgr containerMgr,  FS_HWND hFrmWnd))

/**
 * @brief FRContainerFrmMgrOnContainerFrmDestory
 * @details Trigger destroy container frame.
 * @param[in]  containerMgr The FR_ContainerFrmMgr.
 * @param[in]  hFrmWnd The input handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRContainerFrmMgrOnContainerFrmDestory, (FR_ContainerFrmMgr containerMgr,  FS_HWND hFrmWnd))

NumOfSelector(FRContainerFrmMgr)
ENDENUM

//*****************************
/* PrintProvider HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPrintProviderGetPrintProvider
 * @details Get print provider.
 * @param[in]  doc The input FR_Document.
 * @return   FR_PrintProvider
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_PrintProvider, FRPrintProviderGetPrintProvider, (FR_Document doc))

/**
 * @brief FRPrintProviderGetPrintDoc
 * @details Get document need to print.
 * @param[in]  provider The input FR_PrintProvider.
 * @return   FR_Document
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_Document, FRPrintProviderGetPrintDoc, (FR_PrintProvider provider))

/**
 * @brief FRPrintProviderGetDefaultPrinterName
 * @details Get default printer name.
 * @param[out]  printName Get default printer name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRPrintProviderGetDefaultPrinterName, (FS_WideString* printName))

/**
 * @brief FRPrintProviderIsSnapShot
 * @details Whether is snap shot.
 * @param[in]  provider The input FR_PrintProvider.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRPrintProviderIsSnapShot, (FR_PrintProvider provider))

/**
 * @brief FRPrintProviderGetDispMode
 * @details Get display mode.
 * @param[in]  provider The input FR_PrintProvider.
 * @return   FS_INT32      Get display mode, like FR_LAYOUTMODE_SINGLE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_INT32, FRPrintProviderGetDispMode, (FR_PrintProvider provider))

/**
 * @brief FRPrintProviderGetDefaultPrinterDevMode
 * @details Get print device mode.
 * @return   FS_LPVOID     Get print device mode.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_LPVOID, FRPrintProviderGetDefaultPrinterDevMode, ())

/**
 * @brief FRPrintProviderSetDefaultPrinterDevMode
 * @details Set print device mode.
 * @param[in]  hDevNames The input device HANDLE.
 * @param[in]  hDevMode The input device mode HANDLE.
 * @return   void     Get print device mode.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRPrintProviderSetDefaultPrinterDevMode, (FS_LPVOID hDevNames,  FS_LPVOID hDevMode))

/**
 * @brief FRPrintProviderAnnotsSortByOrder
 * @details Sort annot by order.
 * @param[in]  provider The input FR_PrintProvider.
 * @param[in]  pDoc The input FPD_Document.
 * @param[in]  nPageIndex The input page index.
 * @param[in]  pAnnotsList The input annot list.
 * @param[out]  outAnnotList Get the annot list after sort by order.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRPrintProviderAnnotsSortByOrder, (FR_PrintProvider provider,  FPD_Document pDoc,  FS_INT32 nPageIndex,  FPD_AnnotList pAnnotsList,  FS_PtrArray*  outAnnotList))

/**
 * @brief FRPrintProviderGetPrintParentHwnd
 * @details Get print parent HAND.
 * @return   FS_HWND
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_HWND, FRPrintProviderGetPrintParentHwnd, ())

/**
 * @brief FRPrintProviderReleasePrintProvider
 * @details Release print provider.
 * @param[in]  provider The input FR_PrintProvider.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRPrintProviderReleasePrintProvider, (FR_PrintProvider provider))

NumOfSelector(FRPrintProvider)
ENDENUM

//*****************************
/* WndProvider HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRWndProviderGetCurrentWndProvide
 * @details Get the current wnd provider of the document.
 * @param[in]  doc The input FR_Document.
 * @return   FR_WndProvider Get the current wnd provider of the document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_WndProvider, FRWndProviderGetCurrentWndProvide, (FR_Document doc))

/**
 * @brief FRWndProviderGetProviderName
 * @details Get the current provider name.
 * @param[in]  wndProvider The input FR_WndProvider.
 * @return   FS_LPCSTR              Get the current provider name.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_LPCSTR, FRWndProviderGetProviderName, (FR_WndProvider wndProvider))

NumOfSelector(FRWndProvider)
ENDENUM

//*****************************
/* GlobalData HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRGlobalDataIsForbiddenActionChangeZoom
 * @details Check whether forbidden change zoom in preference setting.
 * @return   FS_BOOL    TRUE is forbidden change zoom.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRGlobalDataIsForbiddenActionChangeZoom, ())

/**
 * @brief FRGlobalDataIsReplaceDocumentColors
 * @details Check whether replace document color in preference of accessbility tab setting.
 * @return   FS_BOOL    TRUE is replace document color.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRGlobalDataIsReplaceDocumentColors, ())

/**
 * @brief FRGlobalDataIsOnlyChangeColorBlackText
 * @details Check whether change color to black text in preference of accessbility tab setting.
 * @return   FS_BOOL    TRUE is only change color to black text.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRGlobalDataIsOnlyChangeColorBlackText, ())

/**
 * @brief FRGlobalDataIsChangeColorTextOrBlackLineArt
 * @details Check whether change color text or black line art in preference of accessbility tab setting.
 * @return   FS_BOOL    TRUE is change color text or black line art.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRGlobalDataIsChangeColorTextOrBlackLineArt, ())

/**
 * @brief FRGlobalDataIsEnableAssistiveTechnologySupport
 * @details Check whether enable assistive technology support in preference of reading tab setting.
 * @return   FS_BOOL    TRUE is enable assistive technology support.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRGlobalDataIsEnableAssistiveTechnologySupport, ())

/**
 * @brief FRGlobalDataIsEmbedContentTextFont
 * @details Check whether enable embed font for content text.
 * @return   FS_BOOLEAN    true embed font for content text.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRGlobalDataIsEmbedContentTextFont, ())

/**
 * @brief FRGlobalDataIsUseLogicalPage
 * @details Check whether use logical page.
 * @return   FS_BOOLEAN    true It used logical page.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRGlobalDataIsUseLogicalPage, ())

/**
 * @brief FRGlobalDataGetEidtDirection
 * @details Get edit direction.
 * @return   FS_INT32    0: left to right, 1: right to left.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRGlobalDataGetEidtDirection, ())

/**
 * @brief FRGlobalDataGetInitialOpenDir
 * @details Get initial open path.
 * @param[in/out]  outDir Get initial open path.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRGlobalDataGetInitialOpenDir, (FS_WideString* outDir))

NumOfSelector(FRGlobalData)
ENDENUM

//*****************************
/* HandlerDataType HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRHandlerDataTypeCreateDataType
 * @details Create datatype object to tell the frame 
	* the type of the object being operated on.
 * @param[in]  callbacks The input FR_HandlerDataTypeCallbacks.
 * @return   FR_HandlerDataType    Create FR_HandlerDataType object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_HandlerDataType, FRHandlerDataTypeCreateDataType, (FR_HandlerDataTypeCallbacks callbacks))

/**
 * @brief FRHandlerDataTypeDeleteDataType
 * @details Delete data type.
 * @param[in]  dataType The input FR_HandlerDataType.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRHandlerDataTypeDeleteDataType, (FR_HandlerDataType dataType))

NumOfSelector(FRHandlerDataType)
ENDENUM

//*****************************
/* MuCopyData HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRMuCopyDataCreate
 * @details Create FR_MuCopyData.
 * @return   FR_MuCopyData
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_MuCopyData, FRMuCopyDataCreate, ())

/**
 * @brief FRMuCopyDataDestroy
 * @details Destroy FR_MuCopyData.
 * @param[in]  data The input FR_MuCopyData.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRMuCopyDataDestroy, (FR_MuCopyData data))

/**
 * @brief FRMuCopyDataGetClientData
 * @details Get client data.
 * @param[in]  data The input FR_MuCopyData.
 * @return   FS_LPVOID
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_LPVOID, FRMuCopyDataGetClientData, (FR_MuCopyData data))

/**
 * @brief FRMuCopyDataGetRectArray
 * @details Get rect array.
 * @param[in]  data The input FR_MuCopyData.
 * @return   FS_FloatRectArray
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_FloatRectArray, FRMuCopyDataGetRectArray, (FR_MuCopyData data))

/**
 * @brief FRMuCopyDataGetRowCount
 * @details Get row count.
 * @param[in]  data The input FR_MuCopyData.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRMuCopyDataGetRowCount, (FR_MuCopyData data))

/**
 * @brief FRMuCopyDataSetClientData
 * @details Set client data.
 * @param[in]  data The input FR_MuCopyData.
 * @param[in]  clientData The input client data.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRMuCopyDataSetClientData, (FR_MuCopyData data,  FS_LPVOID clientData))

/**
 * @brief FRMuCopyDataSetRectArray
 * @details Set rect array.
 * @param[in]  data The input FR_MuCopyData.
 * @param[in]  array The input rect array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRMuCopyDataSetRectArray, (FR_MuCopyData data,  FS_FloatRectArray rectArray))

/**
 * @brief FRMuCopyDataSetRowCount
 * @details Set row count.
 * @param[in]  data The input FR_MuCopyData.
 * @param[in]  rowCount The input row count.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRMuCopyDataSetRowCount, (FR_MuCopyData data,  FS_INT32 rowCount))

/**
 * @brief FRMuCopyDataCopyData
 * @details Copy data.
 * @param[in]  srcData The input source FR_MuCopyData.
 * @param[in\out]  destData The input dest FR_MuCopyData.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRMuCopyDataCopyData, (FR_MuCopyData srcData,  FR_MuCopyData* destData))

NumOfSelector(FRMuCopyData)
ENDENUM

//----------_V17----------
//*****************************
/* PrintMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPrintMgrCreate
 * @details Create FR_PrintMgr obj.
 * @param[in]  doc The input FR_Document that need to print.
 * @param[in]  bQuietMode Set if it's quite mode.
 * @param[in]  wsFilePath The input file path.
 * @return   FR_PrintMgr
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FR_PrintMgr, FRPrintMgrCreate, (FR_Document doc,  FS_BOOL bQuietMode,  FS_LPCWSTR wsFilePath))

/**
 * @brief FRPrintMgrDelete
 * @details Delete FR_PrintMgr obj.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrDelete, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintRange
 * @details Set the page range.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nRangeMode The input range mode, like FR_PRINT_RANG_xxx.
 * @param[in]  nFrom The input start page, it set when range mode is FR_PRINT_RANGE_PAGES.
 * @param[in]  nTo The input end page, it set when range mode is FR_PRINT_RANGE_PAGES.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintRange, (FR_PrintMgr printMgr,  FS_INT32 nRangeMode,  FS_INT32 nFrom,  FS_INT32 nTo))

/**
 * @brief FRPrintMgrGetPrintRange
 * @details Get the page range.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[out]  nRangeMode Get input range mode, like FR_PRINT_RANG_xxx.
 * @param[out]  nFrom Ghe input start page, it get success when range mode is FR_PRINT_RANGE_PAGES.
 * @param[out]  nTo Ghe input end page, it get success when range mode is FR_PRINT_RANGE_PAGES.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrGetPrintRange, (FR_PrintMgr printMgr,  FS_INT32* nRangeMode,  FS_INT32* nFrom,  FS_INT32* nTo))

/**
 * @brief FRPrintMgrSetPrintSubset
 * @details Set print subset.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nSubsetMode Get input range mode, like FR_PRINT_SUBSET_xxx.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintSubset, (FR_PrintMgr printMgr,  FS_INT32 nSubsetMode))

/**
 * @brief FRPrintMgrGetPrintSubset
 * @details Get print subset.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_INT32    Like FR_PRINT_SUBSET_xxx.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FRPrintMgrGetPrintSubset, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintRotate
 * @details Set print rotate.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nRotateMode The input rotate mode, like FR_PRINT_ROTATE_MODE_xxx.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintRotate, (FR_PrintMgr printMgr,  FS_INT32 nRotateMode))

/**
 * @brief FRPrintMgrGetPrintRotate
 * @details Get print rotate.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_INT32            Get the print rotate,like FR_PRINT_ROTATE_MODE_xxx.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FRPrintMgrGetPrintRotate, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintScale
 * @details Set print scale.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nZoomToMode The input zoom mode, like FR_PRINT_ZOOM_MODE_xxx.
 * @param[in]  flScale The input scale value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintScale, (FR_PrintMgr printMgr,  FS_INT32 nZoomToMode,  FS_FLOAT flScale))

/**
 * @brief FRPrintMgrGetPrintScale
 * @details Get print scale.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[out]  nZoomToMode Get zoom mode, like FR_PRINT_ZOOM_MODE_xxx.
 * @param[out]  flScale Get scale value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrGetPrintScale, (FR_PrintMgr printMgr,  FS_INT32* nZoomToMode,  FS_FLOAT* flScale))

/**
 * @brief FRPrintMgrSetPrintArrange
 * @details Set print arrange.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nArrangeMode Get zoom mode, like FR_PRINT_ZOOM_MODE_xxx.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintArrange, (FR_PrintMgr printMgr,  FS_INT32 nArrangeMode))

/**
 * @brief FRPrintMgrGetPrintArrange
 * @details Get print arrange.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FRPrintMgrGetPrintArrange, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintCopies
 * @details Set print copies.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nCopies The input print copies.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintCopies, (FR_PrintMgr printMgr,  FS_UINT nCopies))

/**
 * @brief FRPrintMgrGetPrintCopies
 * @details Get print copies.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_UINT
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_UINT, FRPrintMgrGetPrintCopies, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintAutoCenter
 * @details Set print auto center.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bAutoCenter Set if enable auto center.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintAutoCenter, (FR_PrintMgr printMgr,  FS_BOOLEAN bAutoCenter))

/**
 * @brief FRPrintMgrGetPrintAutoCenter
 * @details Get if enable print auto center.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRPrintMgrGetPrintAutoCenter, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintAutoRotate
 * @details Set print auto rotate.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bAutoRotate Set if enable auto rotate
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintAutoRotate, (FR_PrintMgr printMgr,  FS_BOOLEAN bAutoRotate))

/**
 * @brief FRPrintMgrGetPrintAutoRotate
 * @details Get if enable print auto rotate.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRPrintMgrGetPrintAutoRotate, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintGray
 * @details Set print gray.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bGray Set if print gray.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintGray, (FR_PrintMgr printMgr,  FS_BOOLEAN bGray))

/**
 * @brief FRPrintMgrGetPrintGray
 * @details Get print gray.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRPrintMgrGetPrintGray, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintCollate
 * @details Set print collate.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bCollate Set if need collate.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintCollate, (FR_PrintMgr printMgr,  FS_BOOLEAN bCollate))

/**
 * @brief FRPrintMgrGetPrintCollate
 * @details Get print collate.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRPrintMgrGetPrintCollate, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintPageOrder
 * @details Set print page order
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nOrderMode The input page order, like FR_PRINT_ORDER_xxx.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintPageOrder, (FR_PrintMgr printMgr,  FS_INT32 nOrderMode))

/**
 * @brief FRPrintMgrSetPrintPageBorder
 * @details Set if need print page border.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bBorder Set if print page border when set multi page per sheet handle.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintPageBorder, (FR_PrintMgr printMgr,  FS_BOOLEAN bBorder))

/**
 * @brief FRPrintMgrGetPrintPageBorder
 * @details Set print page order
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRPrintMgrGetPrintPageBorder, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintPrintWhat
 * @details Set print what mode.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nPrintWhatMode The input print what mode, like  FR_PRINT_WHAT_xxx.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintPrintWhat, (FR_PrintMgr printMgr,  FS_INT32 nPrintWhatMode))

/**
 * @brief FRPrintMgrSetPrintOrientation
 * @details Set print orientation.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nPrintOriType The input print orientation type.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintOrientation, (FR_PrintMgr printMgr,  FR_PrintOrientationType nPrintOriType))

/**
 * @brief FRPrintMgrSetPrintPagesPerSheet
 * @details Set print pages per sheet.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nPerSheetMode The input page sheet mode, like FR_PRINT_FACING_xxx.
 * @param[in]  nHorzs The input pages that each row shows.
 * @param[in]  nVerts The input pages that each column shows.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintPagesPerSheet, (FR_PrintMgr printMgr,  FS_INT32 nPerSheetMode,  FS_INT32 nHorzs,  FS_INT32 nVerts))

/**
 * @brief FRPrintMgrGetPrintPagesPerSheet
 * @details Get print pages per sheet.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[out]  nHorzs Get page numbers that each row shows.
 * @param[out]  nVerts Get page numbers that each column shows.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrGetPrintPagesPerSheet, (FR_PrintMgr printMgr,  FS_INT32* nHorzs,  FS_INT32* nVerts))

/**
 * @brief FRPrintMgrSetPrintPaperSizeByPage
 * @details Set if choose papper source by page size.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bPaperSizeByPage Set if choose papper source by page size.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintPaperSizeByPage, (FR_PrintMgr printMgr,  FS_BOOLEAN bPaperSizeByPage))

/**
 * @brief FRPrintMgrSetPrintReverse
 * @details Set if need print reverse page.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bReverse Set if need print reverse page.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintReverse, (FR_PrintMgr printMgr,  FS_BOOLEAN bReverse))

/**
 * @brief FRPrintMgrGetPrintReverse
 * @details Get if need print reverse page.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRPrintMgrGetPrintReverse, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintMargins
 * @details Set print margins.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  flMargins The input print margins.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintMargins, (FR_PrintMgr printMgr,  FS_FLOAT flMargins))

/**
 * @brief FRPrintMgrSetPrintAsImage
 * @details Set print as image.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bPrintAsImage Set if print as image.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintAsImage, (FR_PrintMgr printMgr,  FS_BOOLEAN bPrintAsImage))

/**
 * @brief FRPrintMgrSetSimulateOverprinting
 * @details Set if need simulate over print.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bSimulateOverprintint Set if need simulate over print.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetSimulateOverprinting, (FR_PrintMgr printMgr,  FS_BOOLEAN bSimulateOverprintint))

/**
 * @brief FRPrintMgrSetPrintIgnoreAdvancedSetting
 * @details Set if ignore advance settings.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bIgnoreAdvanced Set if ignore advance settings.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintIgnoreAdvancedSetting, (FR_PrintMgr printMgr,  FS_BOOL bIgnoreAdvanced))

/**
 * @brief FRPrintMgrSetProgressDisplay
 * @details Set if show progress.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bShow Set if show progress.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetProgressDisplay, (FR_PrintMgr printMgr,  FS_BOOL bShow))

/**
 * @brief FRPrintMgrSetPaperSize
 * @details Set page size.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  papersize Set page size.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPaperSize, (FR_PrintMgr printMgr,  FS_INT32 papersize))

/**
 * @brief FRPrintMgrSetPrintPageArray
 * @details Set print page array.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  PageArray Set page array need to print.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintPageArray, (FR_PrintMgr printMgr,  FS_WordArray PageArray))

/**
 * @brief FRPrintMgrGetPrintPageArray
 * @details Get print page array.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[out]  PageArray Get page array need to print.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrGetPrintPageArray, (FR_PrintMgr printMgr,  FS_WordArray* PageArray))

/**
 * @brief FRPrintMgrGetDefaultPrint
 * @details Get default printer.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[out]  wsPrintName Get default printer.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrGetDefaultPrint, (FR_PrintMgr printMgr,  FS_WideString* wsPrintName))

/**
 * @brief FRPrintMgrSetDefaultPrint
 * @details Get default printer.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  strPrinterName Set default printer.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetDefaultPrint, (FR_PrintMgr printMgr,  FS_LPCWSTR  strPrinterName))

/**
 * @brief FRPrintMgrSetPrintOutputFileName
 * @details Set print output file name.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  wsOutputFileName Set print output file name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintOutputFileName, (FR_PrintMgr printMgr,  FS_LPCWSTR wsOutputFileName))

/**
 * @brief FRPrintMgrDoModal
 * @details Show print dialog.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  hParentHwnd The dialog parent hwnd.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FRPrintMgrDoModal, (FR_PrintMgr printMgr,  FS_HWND hParentHwnd))

/**
 * @brief FRPrintMgrSetPrintDevMode
 * @details Set print device mode.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  strPrinterName The input printer name.
 * @param[in]  devMode The input DEVMODE in windows, mac platform ignore it.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintDevMode, (FR_PrintMgr printMgr,  FS_LPCSTR strPrinterName,  FS_LPVOID devMode))

/**
 * @brief FRPrintMgrSetPrintPreview
 * @details Set if need show preview.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bPreview Set if need show preview.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintPreview, (FR_PrintMgr printMgr,  FS_BOOLEAN bPreview))

/**
 * @brief FRPrintMgrEnablePrintAnnot
 * @details Set if need enable print annot.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bEnable Set if need enable print annot.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrEnablePrintAnnot, (FR_PrintMgr printMgr,  FS_BOOLEAN bEnable))

/**
 * @brief FRPrintMgrSetRangeMode
 * @details Set print range mode.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nRangeMode Set print range mode, like FR_PRINT_RANGE_xxx.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetRangeMode, (FR_PrintMgr printMgr,  FS_INT32 nRangeMode))

/**
 * @brief FRPrintMgrGetRangeMode
 * @details Get print range mode.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FRPrintMgrGetRangeMode, (FR_PrintMgr printMgr))

/**
 * @brief FRPrintMgrSetPrintBookletBinding
 * @details Set print booklet binding.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nBinding The input booklet binding direction, like FR_PRINT_BOOKLET_BINDING_xxx.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintBookletBinding, (FR_PrintMgr printMgr,  FS_INT32 nBinding))

/**
 * @brief FRPrintMgrSetPrintBookletSubSet
 * @details Set print booklet binding.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nSubset The input booklet subset, like FR_PRINT_BOOKLET_SUBSET_xxx.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintBookletSubSet, (FR_PrintMgr printMgr,  FS_INT32 nSubset))

/**
 * @brief FRPrintMgrSetPrintCutMarks
 * @details Set print cut marks.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bCutMarks Set if need cut marks.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintCutMarks, (FR_PrintMgr printMgr,  FS_BOOLEAN bCutMarks))

/**
 * @brief FRPrintMgrSetPrintLabels
 * @details Set print lebels.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bLabels Set if need print labels.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintLabels, (FR_PrintMgr printMgr,  FS_BOOLEAN bLabels))

/**
 * @brief FRPrintMgrSetPrintPageScaleType
 * @details Set print page scale type.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nPageScale Set page scale, like FR_PRINT_ZOOM_MODE_xxx.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintPageScaleType, (FR_PrintMgr printMgr,  FS_INT32 nPageScale))

/**
 * @brief FRPrintMgrEnumPrinterName
 * @details Get printer names.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[out]  arrPrintName Get printer names.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrEnumPrinterName, (FR_PrintMgr printMgr,  FS_WideStringArray* arrPrintName))

/**
 * @brief FRPrintMgrSetPrintDuplexType
 * @details Set if need duplex print.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  bDuplex Set if need duplex print.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintDuplexType, (FR_PrintMgr printMgr,  FS_BOOLEAN bDuplex))

/**
 * @brief FRPrintMgrSetPrintOverlap
 * @details Set if need print over lap.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  dOverlap Set if need overlap.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintOverlap, (FR_PrintMgr printMgr,  FS_BOOLEAN dOverlap))

/**
 * @brief FRPrintMgrSetPrintHandlingType
 * @details Set print handle type.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @param[in]  nPrintHandlingType Set print handle type, like FR_PRINT_HANDLING_xxx.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FRPrintMgrSetPrintHandlingType, (FR_PrintMgr printMgr,  FS_INT32 nPrintHandlingType))

/**
 * @brief FRPrintMgrGetPrintHandlingType
 * @details Get print handle type.
 * @param[in]  printMgr The input FR_PrintMgr.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FRPrintMgrGetPrintHandlingType, (FR_PrintMgr printMgr))

NumOfSelector(FRPrintMgr)
ENDENUM

//*****************************
/* EncryptedDocMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FREncryptedDocMgrToDecFile
 * @details Obtain the file path after decrypt, such as DRM.
 * @param[in]  pszInPath The input DRM file path.
 * @param[out]  pszOutPath Get the temp decrypted file path.
 * @param[in]  operation The operate type need to decrypt file.
 * @return   FS_BOOL    TRUE: Decrypt success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @see FREncryptedDocMgrToDecFile
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FREncryptedDocMgrToDecFile, (FS_LPCWSTR pszInPath,  FS_WideString* pszOutPath,  FR_OtherToPDF operation))

/**
 * @brief FREncryptedDocMgrToDelDecFile
 * @details Delete the temp decrypted file.
 * @param[in]  pszPath The input decrypted file path need to delete.
 * @param[in]  operation The operate type need to decrypt file.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @see FREncryptedDocMgrToDelDecFile
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FREncryptedDocMgrToDelDecFile, (FS_LPCWSTR pszPath,  FR_OtherToPDF operation))

/**
 * @brief FREncryptedDocMgrToEncFile
 * @details Obtain the file path after encrypt, such as DRM.
 * @param[in]  pDocument The input FR_Document.
	* When split or extract pages with it, plugin need to check if it's an encrypted file.
 * @param[in]  pszPath The input file path need to encrypt.
 * @param[out]  pszOutPath Get the temp encrypted file path.
 * @param[in]  operation The operate type need to encrypt file.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @see FREncryptedDocMgrToEncFile
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FREncryptedDocMgrToEncFile, (FR_Document pDocument,  FS_LPCWSTR pszInPath,  FS_WideString* pszOutPath,  FR_PDFToOther operation))

/**
 * @brief FREncryptedDocMgrToDelEncFile
 * @details Delete the temp encrypted file.
 * @param[in]  pDocument The input FR_Document.
	* When split or extract pages with it, plugin need to check if it's an encrypted file.
 * @param[in]  pszPath The input temp encrypted file need to delete.
 * @param[in]  operation The operate type need to encrypt file.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 * @see FREncryptedDocMgrToDelEncFile
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FREncryptedDocMgrToDelEncFile, (FR_Document pDocument,  FS_LPCWSTR pszPath,  FR_PDFToOther operation))

NumOfSelector(FREncryptedDocMgr)
ENDENUM

//*****************************
/* PDFBitmapMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPDFBitmapMgrCreate
 * @details Create FR_PDFBitmapMgr object.
 * @param[in]  bsName The input bitmap mgr name.
 * @param[in]  wsLightPath The input light path.
 * @param[in]  wsDarkPath The input dark path.
 * @return   FR_PDFBitmapMgr
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_PDFBitmapMgr, FRPDFBitmapMgrCreate, (FS_LPCSTR bsName,  FS_LPCWSTR wsLightPath,  FS_LPCWSTR wsDarkPath))

/**
 * @brief FRPDFBitmapMgrGetByName
 * @details Get FR_PDFBitmapMgr object.
 * @param[in]  bsName The input bitmap mgr name.
 * @return   FR_PDFBitmapMgr
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_PDFBitmapMgr, FRPDFBitmapMgrGetByName, (FS_LPCSTR bsName))

/**
 * @brief FRPDFBitmapMgrGetBitmap
 * @details Get HBITMAP of specified image name from ribbonimage-phantom.pdf.
 * @param[in]  mgr The input FR_PDFBitmapMgr object.
 * @param[in]  wsImageName It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf.
 * @param[in]  cx Set the width of the image.
 * @param[in]  cy Set the height of the image.
 * @param[in]  clrReplace Set fill color of the image.
 * @param[in]  style The input skin style.
 * @return   HBITMAP
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(HBITMAP, FRPDFBitmapMgrGetBitmap, (FR_PDFBitmapMgr mgr,  FS_LPCWSTR wsImageName,  FS_INT32 cx,  FS_INT32 cy,  FS_COLORREF clrReplace,  FR_SKINSTYLE style))

/**
 * @brief FRPDFBitmapMgrGetFXBitmap
 * @details Get FS_DIBitmap of specified image name from ribbonimage-phantom.pdf.
 * @param[in]  mgr The input FR_PDFBitmapMgr object.
 * @param[in]  wsImageName It need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf.
 * @param[in]  cx Set the width of the image.
 * @param[in]  cy Set the height of the image.
 * @param[in]  clrReplace Set fill color of the image.
 * @param[in]  dwSytle The input skin style.
 * @return   FS_DIBitmap
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_DIBitmap, FRPDFBitmapMgrGetFXBitmap, (FR_PDFBitmapMgr mgr,  FS_LPCWSTR wsImageName,  FS_INT32 cx,  FS_INT32 cy,  FS_COLORREF clrReplace,  FR_SKINSTYLE dwSytle))

/**
 * @brief FRPDFBitmapMgrDraw
 * @details Draw PDFBitmap
 * @param[in]  mgr The input FR_PDFBitmapMgr object.
 * @param[in]  hDC Render device
 * @param[in]  iconRect the rect of PDFBitmap need to render
 * @param[in]  wsPDFBitmapName the name of the PDFBitmap, which is from the bookmark of \res\ribbon\ribbonimage.pdf
 * @param[in]  bDisable <a>TRUE</a> means drawing PDFBitmap as disable mode, otherwise not.
 * @param[in]  clrBack background color
 * @param[in]  clrReplace replaced color
 * @param[in]  bAlpha <a>TRUE</a> means drawing PDFBitmap as transparency.if it is TRUE, clrBack param will be ignore.
 * @param[in]  style The input skin style.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPDFBitmapMgrDraw, (FR_PDFBitmapMgr mgr,  FS_HDC hDC,  FS_FloatRect iconRect,  FS_LPCWSTR wsPDFBitmapName,  FS_BOOL bDisable,  FS_COLORREF clrBack,  FS_COLORREF clrReplace,  FS_BOOL bAlpha,  FR_SKINSTYLE style))

/**
 * @brief FRPDFBitmapMgrFillRoundedRectangle
 * @details Fill round rectangle of specified property.
 * @param[in]  mgr The input FR_PDFBitmapMgr object.
 * @param[in]  pDC The input CDC object.
 * @param[in]  rect The input rounded rect.
 * @param[in]  clrFill The input fill color.
 * @param[in]  ptRoundRadius The input point of round radius.
 * @return   void
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFBitmapMgrFillRoundedRectangle, (FR_PDFBitmapMgr mgr,  FS_LPVOID pDC,  FS_Rect rect,  FS_COLORREF clrFill,  FS_DevicePoint ptRoundRadius))

/**
 * @brief FRPDFBitmapMgrDrawRoundedRectangle
 * @details Draw round rectangle of specified property.
 * @param[in]  mgr The input FR_PDFBitmapMgr object.
 * @param[in]  pDC The input CDC object.
 * @param[in]  rect The input rounded rect.
 * @param[in]  clrFill The input fill color.
 * @param[in]  ptRoundRadius The input point of round radius.
 * @return   void
 * @note It only used on Windows platform.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPDFBitmapMgrDrawRoundedRectangle, (FR_PDFBitmapMgr mgr,  FS_LPVOID pDC,  FS_Rect rect,  FS_COLORREF clrLine,  FS_DevicePoint ptRoundRadius,  FS_INT32 nLineWidth,  FS_INT32 nPenStyle))

NumOfSelector(FRPDFBitmapMgr)
ENDENUM

//----------_V18----------
//----------_V19----------
//*****************************
/* StartPageEventHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRStartPageEventHandlerNew
 * @details Construct FR_StartPageEventHandler object by FR_StartPageEventCallbacks.
 * @param[in]  callback The input FR_StartPageEventCallbacks object.
 * @return   FR_StartPageEventHandler
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 */
INTERFACE(FR_StartPageEventHandler, FRStartPageEventHandlerNew, (FR_StartPageEventCallbacks callback))

/**
 * @brief FRStartPageEventHandlerDelete
 * @details Release FR_StartPageEventHandler object.
 * @param[in]  handler The input FR_StartPageEventHandler object.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 */
INTERFACE(void, FRStartPageEventHandlerDelete, (FR_StartPageEventHandler handler))

NumOfSelector(FRStartPageEventHandler)
ENDENUM

//*****************************
/* UndoEventHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRUndoEventHandlerNew
 * @details Construct FR_UndoEventHandler object by FR_UndoEventCallbacks.
 * @param[in]  callback The input FR_UndoEventCallbacks object.
 * @return   FR_UndoEventHandler
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 */
INTERFACE(FR_UndoEventHandler, FRUndoEventHandlerNew, (FR_UndoEventCallbacks callback))

/**
 * @brief FRUndoEventHandlerDelete
 * @details Release FR_UndoEventHandler object.
 * @param[in]  handler The input FR_UndoEventHandler object.
 * @return   void
 * @note The function can only be used for Windows.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 */
INTERFACE(void, FRUndoEventHandlerDelete, (FR_UndoEventHandler handler))

NumOfSelector(FRUndoEventHandler)
ENDENUM

//----------_V20----------

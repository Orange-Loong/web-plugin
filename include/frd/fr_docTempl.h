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
/* Doc HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRDocOpenFromFile
 * @details Opens and displays a document form a file.
 * @param[in]  wszFile The file path.
 * @param[in]  szPassword The password with the file. It could be <a>NULL</a> if no password to pass.
 * @param[in]  bMakeVisible Whether the document will be made visible.
 * @param[in]  bAddToMRU Whether add the file path to the recent file list.
 * @return   The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
 * @note Do not open and then immediately close a FR_Document without letting least once event loop complete.
	* If you need to set more open options, suggest use FRDocOpenDocument, it suppports more option for openfile.
 * @see FRDocClose
 * @see FRDocOpenFromPDDoc
 * @see FRDocFromPDDoc
	
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more. User can use FRDocOpenDocument function instead.
 */
INTERFACE(FR_Document, FRDocOpenFromFile, (FS_LPCWSTR wszFile,  FS_LPCSTR szPassword,  FS_BOOL bMakeVisible,  FS_BOOL bAddToMRU))

/**
 * @brief FRDocOpenFromPDDoc
 * @details Opens and returns a <a>FR_Document</a> view of <a>PD_Document</a>.
 * @param[in]  pddoc The <a>FPD_Document</a> object to open.
 * @param[in]  lpwsTitle It is used as window's title.
 * @return   The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
 * @note Do not open and then immediately close a FR_Document without letting least once event loop complete.
	* If you need to set more open options, suggest use FRDocOpenDocument, it suppports more option for openfile.
	* <a>FRDocClose</a>() should be used in place of <a>FPDDocClose</a>() after FRDocOpenFromPDDoc() is called.
	* <a>FRDocClose</a>() will decrement the FPDDoc appropriately and free document-related resources.
 * @see FRDocClose
 * @see FRDocOpenFromFile
 * @see FRDocFromPDDoc
 */
INTERFACE(FR_Document, FRDocOpenFromPDDoc, (FPD_Document pddoc,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRDocFromPDDoc
 * @details Gets the  <a>FR_Docuemnt</a> associated with a <a>FPD_Document</a>.
 * @param[in]  pddoc The <a>FR_Docuemnt</a> whose <a>FR_Document</a> is to be returned.
 * @return   The <a>FR_Docuemnt</a> if a  <a>FR_Docuemnt</a> is already opened for this <a>FPD_Document</a>, otherwise <a>NULL</a>.
 * @note 
 * @see FRDocOpenFromFile
 * @see FRDocOpenFromPDDoc
 * @see FRDocGetPDDoc
 */
INTERFACE(FR_Document, FRDocFromPDDoc, (FPD_Document pddoc))

/**
 * @brief FRDocClose
 * @details Closes the document window.
 * @param[in]  doc The document to close.
 * @param[in]  bPromptToSave If <a>FALSE</a>, the document closed without prompting the user and without saving,
	* even if the document has been modified. If <a>TRUE</a>, it prompt the user to save the document if it has
	* been modified.
 * @param[in]  bDelay Delay closing the document or not.
 * @param[in]  bShowCancel If <a>FALSE</a>, it will not show cancle button when prompt to save.
 * @return   <a>TRUE</a> if the document colsed, <a>FALSE</a> if it did not. The document will always close if 
	* <param>bPromptToSave</param> is <a>FALSE</a>.
 * @note 
 * @see FRDocOpenFromFile
 * @see FRDocOpenFromPDDoc
 */
INTERFACE(FS_BOOL, FRDocClose, (FR_Document doc,  FS_BOOL bPromptToSave,  FS_BOOL bDelay,  FS_BOOL bShowCancel))

/**
 * @brief FRDocGetPDDoc
 * @details Gets the <a>FPD_Document</a> to associated with the specified <a>FR_Document</a>.
 * @param[in]  doc The document whose <a>FPD_Document</a> is obtained.
 * @return   The <a>FPD_Document</a> associated with <a>FR_Document</a>.
 * @note 
 * @see FRDocFromPDDoc
 * @see FRDocOpenFromPDDoc
 * @see FRPageViewGetPDPage
 */
INTERFACE(FPD_Document, FRDocGetPDDoc, (FR_Document doc))

/**
 * @brief FRDocSetCustomSecurity
 * @details Sets security using custom security handler and custom encryption.
	* Application should provide a full encryption dictionary (application can destroy it after this call),
	* and a custom encryption handler.
 * @param[in]  doc The input document.
 * @param[in]  encryptDict The Encrypt dictionary.
 * @param[in]  cryptoHandler The callbacks for crypto handler.
 * @param[in]  bEncryptMetadata Whether to encrypt the metadata.
 * @param[in]  clientHandler The user-supplied data.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetCustomSecurity, (FR_Document doc,  FPD_Object encryptDict,  FR_CryptoCallbacks cryptoHandler,  FS_BOOL bEncryptMetadata,  FS_LPVOID clientHandler))

/**
 * @brief FRDocDoSave
 * @details Save the document.
 * @param[in]  doc The document to be saved.
 * @param[in]  proc Callback function.
 * @param[in]  pProcData The client data. It will be passed to the save callback function.
 * @param[in]  bShowProgressBar Whether to show the progress bar or not.
 * @return   FS_BOOL             TRUE: save success.
 * @note 
 * @see FRDocDoSaveAs
 * @see FRDocSetChangeMark
 */
INTERFACE(FS_BOOL, FRDocDoSave, (FR_Document doc,  FR_DocSaveProc proc,  void* pProcData,  FS_BOOL bShowProgressBar))

/**
 * @brief FRDocDoSaveAs
 * @details Displays a file save as dialog which can be used to save the document as a new name.
 * @param[in]  doc The document.
 * @return   void
 * @note 
 * @see FRDocDoSave
 */
INTERFACE(void, FRDocDoSaveAs, (FR_Document doc))

/**
 * @brief FRDocSetChangeMark
 * @details Sets the modify flag. Reader has a built-in flag that indicate whether a document has been modified,
	* if the value of the flag is valid, the Save button on File toolbar is enable, otherwise the Save button is 
	* disable.
 * @param[in]  doc The document.
 * @return   void
 * @note 
 * @see FRDocGetChangeMark
 * @see FRDocClearChangeMark
 */
INTERFACE(void, FRDocSetChangeMark, (FR_Document doc))

/**
 * @brief FRDocGetChangeMark
 * @details Checks whether the document is modified.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> if the document has been modified, <a>FALSE</a> if no change.
 * @note 
 * @see FRDocSetChangeMark
 * @see FRDocClearChangeMark
 */
INTERFACE(FS_BOOL, FRDocGetChangeMark, (FR_Document doc))

/**
 * @brief FRDocClearChangeMark
 * @details Invalidates all modification.
 * @param[in]  doc The document.
 * @return   void
 * @note 
 * @see FRDocGetChangeMark
 * @see FRDocSetChangeMark
 */
INTERFACE(void, FRDocClearChangeMark, (FR_Document doc))

/**
 * @brief FRDocWillInsertPages
 * @details The document will be inserted some pages. This notification will be broadcast to
   	* all plug-ins.
 * @param[in]  doc The document to be inserted pages into.
 * @param[in]  iInserAt The page index for first inserted page.
 * @param[in]  nCount The page count for all inserted page.
 * @return   void
 * @note You can call this method before you start to insert some page into a FPD_Document object.<br>
	* The callback WillInsertPages() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocWillInsertPages, (FR_Document doc,  FS_INT32 iInserAt,  FS_INT32 nCount))

/**
 * @brief FRDocDidInsertPages
 * @details The document was inserted some pages. This notification will be broadcast to
   	* all plug-ins.
 * @param[in]  doc The document to be inserted pages into.
 * @param[in]  iInserAt The page index for first inserted page.
 * @param[in]  nCount The page count for all inserted page.
 * @return   void
 * @note You can call this method after you inserted some page into a FPD_Document object.<br>
	* The callback DidInsertPages() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocDidInsertPages, (FR_Document doc,  FS_INT32 iInserAt,  FS_INT32 nCount))

/**
 * @brief FRDocWillDeletePages
 * @details The document will delete any pages. This notification will be broadcast to
   	* all plug-ins.
 * @param[in]  doc The document whose page was deleted.
 * @param[in]  arrDelPage The index of the pages that has been deleted.
 * @return   void
 * @note You can call this method before you delete some page from a FPD_Document object.<br>
	* The callback WillDeletePages() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.  	
	* Notes:
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocWillDeletePages, (FR_Document doc,  FS_WordArray arrDelPage))

/**
 * @brief FRDocDidDeletePages
 * @details The document was deleted any pages. This notification will be broadcast to
   	* all plug-ins.
 * @param[in]  doc The document whose page was deleted.
 * @param[in]  arrDelPage The index of the pages that has been deleted.
 * @return   void
 * @note You can call this method after you deleted some page from a FPD_Document object.<br>
	* The callback DidDeletePages() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.  	
	* Notes:
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocDidDeletePages, (FR_Document doc,  FS_WordArray arrDelPage))

/**
 * @brief FRDocWillRotatePage
 * @details The pages of <a>FR_Document</a> whose rotation attribute will be modified.
 * @param[in]  doc The document whose page's rotation attribute was modified.
 * @param[in]  iPage The page index.
 * @return   void
 * @note You can call this method before you want to change some page's rotation attribute.<br>
	* The callback WillModifyPageAttribute() descripted in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocWillRotatePage, (FR_Document doc,  FS_INT32 iPage))

/**
 * @brief FRDocDidRotatePage
 * @details The page of <a>FR_Document</a> whose rotation attribute was modified.
 * @param[in]  doc The document whose page's rotation attribute was modified.
 * @param[in]  iPage The page index.
 * @return   void
 * @note You can call this method after you changed some page's rotation attribute.<br>
	* The callback DidModifyPageAttribute() descripted in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocDidRotatePage, (FR_Document doc,  FS_INT32 iPage))

/**
 * @brief FRDocWillResizePage
 * @details The pages of <a>FR_Document</a> whose attribute will be modified.
 * @param[in]  doc The document whose page's attribute was modified.
 * @param[in]  iPage The page index.
 * @return   void
 * @note You can call this method before you want to change some page's rotation attribute.<br>
	* The callback WillModifyPageAttribute() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocWillResizePage, (FR_Document doc,  FS_INT32 iPage))

/**
 * @brief FRDocDidResizePage
 * @details The page of <a>FR_Document</a> whose attribute was modified.
 * @param[in]  doc The document whose page's attribute was modified.
 * @param[in]  iPage The page index.
 * @return   void
 * @note You can call this method after you changed some page's rotation attribute.<br>
	* The callback DidModifyPageAttribute() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocDidResizePage, (FR_Document doc,  FS_INT32 iPage))

/**
 * @brief FRDocDoPrint
 * @details Performs the print operation, including user dialog box.
 * @param[in]  doc The document to print.
 * @return   void
 * @note 
 * @see FRDocPrintPages
 * @see FRDocDoPrintSilently
 * @see FRDocPrintSetup
 */
INTERFACE(void, FRDocDoPrint, (FR_Document doc))

/**
 * @brief FRDocPrintPages
 * @details Sets the first page and the last page to be printed.
 * @param[in]  doc The input document.
 * @param[in]  firstPage The index of first page to be printed.
 * @param[in]  lastPage The index of last page to be printed.
 * @return   void
 * @note 
 * @see FRDocDoPrint
 * @see FRDocDoPrintSilently
 */
INTERFACE(void, FRDocPrintPages, (FR_Document doc,  FS_INT32 firstPage,  FS_INT32 lastPage))

/**
 * @brief FRDocPrintSetup
 * @details Sets up the print, it will show system print dialog.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 * @see FRDocDoPrint
 * @see FRDocDoPrintSilently
 * @see FRDocPrintPages
	// Notes: The function can only be used for Windows.
 */
INTERFACE(void, FRDocPrintSetup, (FR_Document doc))

/**
 * @brief FRDocCountDocViews
 * @details Gets the number of <a>FR_DocView</a> for specified document.
 * @param[in]  doc The document whose view count is obtained.
 * @return   The number of <a>FR_DocView</a> for specified document.
 * @note 
 * @see FRDocGetDocView
 */
INTERFACE(FS_INT32, FRDocCountDocViews, (FR_Document doc))

/**
 * @brief FRDocGetDocView
 * @details Gets the specified <a>FR_DocView</a> for specified document.
 * @param[in]  doc The document whose document view is obtained.
 * @param[in]  iView The index of a document view. The index range is 0 to (<a>FRDocCountDocViews</a>()-1).
 * @return   The specified <a>FR_DocView</a>.
 * @note 
 * @see FRDocGetCurrentDocView
 * @see FRDocCountDocViews
 */
INTERFACE(FR_DocView, FRDocGetDocView, (FR_Document doc,  FS_INT32 iView))

/**
 * @brief FRDocGetCurrentDocView
 * @details Gets the current showing <a>FR_DocView</a> for specified document.
 * @param[in]  doc The document whose document view is obtained.
 * @return   The current showing <a>FR_DocView</a>.
 * @note 
 * @see FRDocGetDocView
 */
INTERFACE(FR_DocView, FRDocGetCurrentDocView, (FR_Document doc))

/**
 * @brief FRDocGetPermissions
 * @details Gets permissions of a document.
 * @param[in]  doc The document whose user permission is obtained.
 * @return   The document permissions. Result like FR_PERM_PRINT、FR_PERM_EXTRACT_COPY、FR_PERM_EXTRACT_ACCESS, etc.
 * @note 
 * @see FRDocSetPermissions
 */
INTERFACE(FS_DWORD, FRDocGetPermissions, (FR_Document doc))

/**
 * @brief FRDocSetPermissions
 * @details Sets permissions to a document. That used for encrypt plugin to set the Permission of a document to frDoc,
	* and the permission will be saved in encrypt plugin.
 * @param[in]  doc The document whose user permission is set.
 * @param[in]  dwPermission The new permission to set to the document, like FR_PERM_PRINT、FR_PERM_EXTRACT_COPY、FR_PERM_EXTRACT_ACCESS, etc.
 * @return   void
 * @note 
 * @see FRDocGetPermissions
 */
INTERFACE(void, FRDocSetPermissions, (FR_Document doc,  FS_DWORD dwPermission))

/**
 * @brief FRDocGetFilePath
 * @details Gets the file path of a document opened by Foxit Reader.
 * @param[in]  doc The document whose file path is set.
 * @param[in/out]  path A wide string object to receive the file path.
 * @return   void
 * @note 
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more. User can use GetOpenFilePath functions instead.
 */
INTERFACE(void, FRDocGetFilePath, (FR_Document doc,  FS_WideString* path))

/**
 * @brief FRDocSetCurSelection
 * @details Sets the current selection handler by type. 
	* To set selection data, used to copy、cut、delete the object.
 * @param[in]  doc The input document.
 * @param[in]  type The input type of the selection handler. The type name you can define in your plugin, it presents the object type.
 * @param[in]  pSelectData The selection data.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRDocSetCurSelection, (FR_Document doc,  FS_LPSTR type,  void* pSelectData))

/**
 * @brief FRDocAddToCurrentSelection
 * @details Adds the new data to the current selection data and returns the updated one.
 * @param[in]  doc The input document.
 * @param[in]  pCurData The current selection data.
 * @param[in]  pAddData The data to be added to the current selection handler.
 * @return   The updated selection data. It is <a>NULL</a> if failed.
 * @note 
 * @Deprecated    Current function has been deprecated, it not be implemented.
 */
INTERFACE(void*, FRDocAddToCurrentSelection, (FR_Document doc,  void* pCurData,  void* pAddData))

/**
 * @brief FRDocRemoveFromSelection
 * @details Removes some data from the current selection data and returns the updated one.
 * @param[in]  doc The input document.
 * @param[in]  pCurData The current selection data.
 * @param[in]  pRemData The data to be removed from the current selection data.
 * @return   The updated selection data. It is <a>NULL</a> if failed.
 * @note 
 * @Deprecated    Current function has been deprecated, it not be implemented.
 */
INTERFACE(void*, FRDocRemoveFromSelection, (FR_Document doc,  void* pCurData,  void* pRemData))

/**
 * @brief FRDocGetCurSelection
 * @details Gets the current selection data.
 * @param[in]  doc The input document.
 * @return   The current selection data.
 * @note 
 */
INTERFACE(void*, FRDocGetCurSelection, (FR_Document doc))

/**
 * @brief FRDocGetCurSelectionType
 * @details Gets the type of the current selection data.
 * @param[in]  doc The input document.
 * @return   The type of the current selection data.
 * @note 
 */
INTERFACE(FS_LPCSTR, FRDocGetCurSelectionType, (FR_Document doc))

/**
 * @brief FRDocShowSelection
 * @details Displays the current selection by calling the selection handler's <a>FRSelectionShowSelection</a>() 
	* callback. It does nothing if the document has no selection, or the current selection's handler has no 
	* <a>FRSelectionShowSelection</a>()  callback.
	* It only raises those exceptions raised by the selection handler's <a>FRSelectionShowSelection</a>() callback.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocShowSelection, (FR_Document doc))

/**
 * @brief FRDocClearSelection
 * @details Clears the current selection object by the current selection handler.
    * <a>FRSelectionLosingSelection</a>().
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocClearSelection, (FR_Document doc))

/**
 * @brief FRDocDeleteSelection
 * @details Deletes the specified document's current selection object, if possible. The selection is deleted if changing the 
	* selection is currently permitted, the selection handler has an <a>FRSelectionDoDelete</a>() callback, and the 
	* selection server's <a>FRSelectionCanDelete</a>() callback returns <a>TRUE</a>. If the selection handler does not 
	* have a <a>FRSelectionCanDelete</a>() callback, a default value of <a>TRUE</a> is used.
	* The selection is deleted by calling the selection handler's <a>FRSelectionDoDelete</a>() callback. 
	* It only raises those exceptions raised by the selection handler's <a>FRSelectionDoDelete</a>() and 
    * <a>FRSelectionCanDelete</a>() callbacks.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocDeleteSelection, (FR_Document doc))

/**
 * @brief FRDocCopySelection
 * @details Copies the current selection to the clipboard, if possible. The selection is copied if the selection handler has 
	* a <a>FRSelectionDoCopy</a>() callback, and the selection handler's <a>FRSelectionCanCopy</a>() callback 
	* returns <a>TRUE</a>. If the selection server does not have a <a>FRSelectionCanCopy</a>() method, a default 
	* value of <a>TRUE</a> is used.
	* The selection is copied by calling the selection handler's <a>FRSelectionDoCopy</a>() callback. 
	* It only raises those exceptions raised by the selection handler's <a>FRSelectionDoCopy</a>() and 
    * <a>FRSelectionCanCopy</a>() callbacks.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocCopySelection, (FR_Document doc))

/**
 * @brief FRDocSetCurCapture
 * @details Set the current capture handler by type.
	* Set the capture data, use to move、resize、show menu of the data.
 * @param[in]  doc The input document.
 * @param[in]  type The type of the capture handler.
 * @param[in]  pCapData The capture data.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRDocSetCurCapture, (FR_Document doc,  FS_LPSTR type,  void* pCapData))

/**
 * @brief FRDocGetCurCapture
 * @details Gets the current capture data.
 * @param[in]  doc The input document.
 * @return   The current capture data.
 * @note 
 */
INTERFACE(void*, FRDocGetCurCapture, (FR_Document doc))

/**
 * @brief FRDocGetCurCaptureType
 * @details Gets the type of the current capture handler.
 * @param[in]  doc The input document.
 * @return   The type of the current capture handler.
 * @note 
 */
INTERFACE(FS_LPCSTR, FRDocGetCurCaptureType, (FR_Document doc))

/**
 * @brief FRDocReleaseCurCapture
 * @details Releases the current capture.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocReleaseCurCapture, (FR_Document doc))

/**
 * @brief FRDocSetMenuEnableByName
 * @details Set the menu enable or not. Like FR_MENU_ENABLE_SAVEAS.
	* It used for some permisson document, you can control some menu if can be enable by this api.
 * @param[in]  doc The input document.
 * @param[in]  csName The menu you want to control.
 * @param[in]  bEnable Whether the menu is enable or not.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetMenuEnableByName, (FR_Document doc,  FS_LPCSTR csName,  FS_BOOL bEnable))

/**
 * @brief FRDocGetParser
 * @details Gets the PDF file parser which is parsing current document.
 * @param[in]  doc The input document.
 * @return   A PDF file parser associated with current document.
 * @note 
 */
INTERFACE(FPD_Parser, FRDocGetParser, (FR_Document doc))

/**
 * @brief FRDocGetPDFCreator
 * @details Gets the PDF creator associated with current document.
 * @param[in]  doc The input document.
 * @return   A PDF creator associated with current document.
 * @note 
 */
INTERFACE(FPD_Creator, FRDocGetPDFCreator, (FR_Document doc))

/**
 * @brief FRDocDoPrintSilently
 * @details Performs the print operation, not including user dialog box.
 * @param[in]  doc The document to print.
 * @return   void
 * @note 
 * @see FRDocPrintPages
 * @see FRDocPrintSetup
 */
INTERFACE(void, FRDocDoPrintSilently, (FR_Document doc))

/**
 * @brief FRDocGetTextSelectTool
 * @details Gets the current text select tool for specified document. It same with FRTextSelectToolCreate.
 * @param[in]  doc The document object.
 * @return   The <a>FR_TextSelectTool</a> object of the <param>doc</param>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FR_TextSelectTool, FRDocGetTextSelectTool, (FR_Document doc))

/**
 * @brief FRDocGetDocumentType
 * @details Get the type of the document.
 * @param[in]  doc The document to get the type.
 * @return   The type of the document. Like FR_DOCTYPE_PDF, FR_DOCTYPE_DYNIMIC_XFA, FR_DOCTYPE_STATIC_XFA.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRDocTypes
 */
INTERFACE(FS_INT32, FRDocGetDocumentType, (FR_Document doc))

/**
 * @brief FRDocCanSecurityMethodBeModified
 * @details Whether the security applied to the document can be modified or not.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterSecurityMethod
 */
INTERFACE(FS_BOOL, FRDocCanSecurityMethodBeModified, (FR_Document doc))

/**
 * @brief FRDocUpdateSecurityMethod
 * @details Remove the security of the document. When this interface is invoked, the <a>FRSecurityMethodRemoveSecurityInfo</a> will be invoked if the document is encrypted.
	* It used for non-standard document, like RMS、AIP、Fasoo DRM security.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterSecurityMethod
 */
INTERFACE(FS_BOOL, FRDocUpdateSecurityMethod, (FR_Document doc))

/**
 * @brief FRDocIsEncrypted
 * @details Check if the document is encrypted. When this interface is invoked, the <a>FRSecurityMethodIsMyMethod</a> will be invoked.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> for the document being encrypted, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterSecurityMethod
 */
INTERFACE(FS_BOOL, FRDocIsEncrypted, (FR_Document doc))

/**
 * @brief FRDocRemoveSecurityMethod
 * @details Remove the security of the document. When this interface is invoked, the <a>FRSecurityMethodRemoveSecurityInfo</a> will be invoked.
	* It used for standard document.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> for the security method of the document being removed, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterSecurityMethod
 */
INTERFACE(FS_BOOL, FRDocRemoveSecurityMethod, (FR_Document doc))

/**
 * @brief FRDocEnableRunScript
 * @details Whether the document can run script.
 * @param[in]  doc The document.
 * @param[in]  bIsEnable Whether the document can run script.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocEnableRunScript, (FR_Document doc,  FS_BOOL bIsEnable))

/**
 * @brief FRDocIsEnableRunScript
 * @details Whether the document can run script.
 * @param[in]  doc The document.
 * @return   Whether the document can run script.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocIsEnableRunScript, (FR_Document doc))

/**
 * @brief FRDocChangeDocShowTitle
 * @details Sets the main frame title and the document tab title.
 * @param[in]  doc The document.
 * @param[in]  lpwsShowTitle This value will be shown as the main frame title and the document tab title.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocChangeDocShowTitle, (FR_Document doc,  FS_LPCWSTR lpwsShowTitle))

/**
 * @brief FRDocIsMemoryDoc
 * @details Whether the document is a memory document or not. 
	* Memory doc like from createPDF、open from word、extract pages to doc.
 * @param[in]  doc The document.
 * @return   Whether the document is a memory document or not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRDocIsMemoryDoc, (FR_Document doc))

/**
 * @brief FRDocGetCurrentSecurityMethodName
 * @details Gets the name of current security method.
 * @param[in]  doc The document.
 * @param[out]  outName It receives the name of current security method.
 * @return   The name of current security method. Like "password encrytion"
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRDocGetCurrentSecurityMethodName, (FR_Document doc,  FS_WideString* outName))

/**
 * @brief FRDocGetCurrentWndProvider
 * @details Gets the current window provider. Like portfolio, textview window provider.
 * @param[in]  doc The document.
 * @return   The pointer to the current window provider.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterWndProvider
	
 * @Deprecated    Internal use.
 */
INTERFACE(void*, FRDocGetCurrentWndProvider, (FR_Document doc))

/**
 * @brief FRDocSetCurrentWndProvider
 * @details Sets the window provider. It used for show own windows in your plugin.
 * @param[in]  doc The document.
 * @param[in]  pProvider The input window provider.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterWndProvider
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetCurrentWndProvider, (FR_Document doc,  void* pProvider))

/**
 * @brief FRDocGetWndProviderByName
 * @details Gets the window provider by name.
 * @param[in]  doc The document.
 * @param[in]  lpsName The Specified name of the window provider.
 * @return   The window provider.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterWndProvider
	
 * @Deprecated    Internal use.
 */
INTERFACE(void*, FRDocGetWndProviderByName, (FR_Document doc,  FS_LPCSTR lpsName))

/**
 * @brief FRDocGetReviewType
 * @details Gets the review type. 0: normal, 1:share/cloud, 2:email,5: review.
 * @param[in]  doc The document.
 * @return   The review type.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use
 */
INTERFACE(FS_INT32, FRDocGetReviewType, (FR_Document doc))

/**
 * @brief FRDocSetReviewType
 * @details Sets the review type.
 * @param[in]  doc The document.
 * @param[in]  nType The input review type.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @Deprecated    Internal use
 */
INTERFACE(void, FRDocSetReviewType, (FR_Document doc,  FS_INT32 nType))

/**
 * @brief FRDocSetAppPermissions
 * @details Sets the application permission.
 * @param[in]  doc The document whose user permission is obtained.
 * @param[in]  dwPermission The input application permission. like FR_PERM_MODIFY_CONTENT.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRDocSetAppPermissions, (FR_Document doc,  FS_DWORD dwPermission))

/**
 * @brief FRDocGetAppPermissions
 * @details Checks whether the user has the specified application permission or not.
 * @param[in]  doc The document whose user permission is obtained.
 * @param[in]  iPermission The specified permission.
 * @return   <a>TRUE</a> if the user has the specified application permission.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRDocGetAppPermissions, (FR_Document doc,  FS_INT32 iPermission))

/**
 * @brief FRDocGetAppPermissionsII
 * @details Gets the application permissions.
 * @param[in]  doc The document whose user permission is obtained.
 * @return   The application permissions. Like FR_PERM_MODIFY_CONTENT.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DWORD, FRDocGetAppPermissionsII, (FR_Document doc))

/**
 * @brief FRDocGetPermissionsII
 * @details Checks whether the document has the permission.
 * @param[in]  doc The document whose user permission is obtained.
 * @param[in]  iPermission The input permission to check.
 * @return   <a>TRUE</a> means the document has the permission, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRDocGetPermissionsII, (FR_Document doc,  FS_INT32 iPermission))

/**
 * @brief FRDocGetMergedPermissions
 * @details Checks whether the document has the permission. It will check doc permisson and app permisson together.
 * @param[in]  doc The document whose user permission is obtained.
 * @param[in]  iPermission The specified permission.
 * @return   <a>TRUE</a> means the document has the permission, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRDocGetMergedPermissions, (FR_Document doc,  FS_INT32 iPermission))

/**
 * @brief FRDocKillFocusAnnot
 * @details Kills the focus annot, set current focus annot with null.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRDocKillFocusAnnot, (FR_Document doc))

/**
 * @brief FRDocSetPropertiesPDFVersion
 * @details Sets the PDF version that will be shown in the properties dialog, that will not be write to PDF.
 * @param[in]  doc The document.
 * @param[in]  lpwsPDFVersion The input PDF version that will be shown in the properties dialog.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetPropertiesPDFVersion, (FR_Document doc,  FS_LPCWSTR lpwsPDFVersion))

/**
 * @brief FRDocSetPropertiesFilePath
 * @details Sets the file path that will be shown in the properties dialog.
 * @param[in]  doc The document.
 * @param[in]  lpwsFilePath The input file path that will be shown in the properties dialog.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetPropertiesFilePath, (FR_Document doc,  FS_LPCWSTR lpwsFilePath))

/**
 * @brief FRDocDoSaveAs2
 * @details Displays a file dialog box which can be used to save the document as a new name.
 * @param[in]  doc The document.
 * @param[in]  pwszFilePath The path where the document to be saved as.
 * @param[in]  proc Callback function.
 * @param[in]  pProcData The client data. It will be passed to the save-as callback function.
 * @param[in]  bSaveAsTempFile Sets it FALSE as default.
 * @param[in]  bShowProgressBar Whether to show the progress bar or not.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 * @see FR_DocSaveAsProc
	
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more. User can use FRDocDoSaveAs3 function.
 */
INTERFACE(FS_BOOL, FRDocDoSaveAs2, (FR_Document doc,  FS_LPCWSTR pwszFilePath,  FR_DocSaveAsProc proc,  void* pProcData,  FS_BOOL bSaveAsTempFile,  FS_BOOL bShowProgressBar))

/**
 * @brief FRDocShowSaveProgressCancelButton
 * @details Sets to show the save progress cancel button or not.
 * @param[in]  doc The document.
 * @param[in]  bShow Whether to show the save progress cancel button.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 */
INTERFACE(void, FRDocShowSaveProgressCancelButton, (FR_Document doc,  FS_BOOL bShow))

/**
 * @brief FRDocSetInputPasswordProc
 * @details Sets the prototype of callback function invoked by <Italic>Foxit Reader</Italic> to receive the password.	
	* Usually SetInputPasswordProc in FRConProviderOnFileOpen.
 * @param[in]  doc The input document.
 * @param[in]  proc Prototype of callback function invoked by <Italic>Foxit Reader</Italic> to receive the password.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.2
 * @see FRConProviderOnFileOpen
 */
INTERFACE(void, FRDocSetInputPasswordProc, (FR_Document doc,  FRInputPasswordProc proc))

/**
 * @brief FRDocCheckInDocumentOLE
 * @details Checks whether the document is opened by OLE. For example, the document is embedded	in <Italic>MS Office Word</Italic>.
 * @param[in]  doc The input document.
 * @return   True means the document is opened by OLE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocCheckInDocumentOLE, (FR_Document doc))

/**
 * @brief FRDocIsShowInBrowser
 * @details Checks whether the document is opened in browser.
 * @param[in]  doc The input document.
 * @return   True means the document is opened in browser.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocIsShowInBrowser, (FR_Document doc))

/**
 * @brief FRDocGetUIParentWnd
 * @details Gets the UI parent window.
 * @param[in]  doc The input document.
 * @return   A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void*, FRDocGetUIParentWnd, (FR_Document doc))

/**
 * @brief FRDocGetDocFrameHandler
 * @details Gets the frame handler associated with the document.
 * @param[in]  doc The input document.
 * @return   The frame handler associated with the document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(HWND, FRDocGetDocFrameHandler, (FR_Document doc))

/**
 * @brief FRDocCreateNewViewByWndProvider
 * @details Creates the new view by <a>FR_WndProviderCallbacksRec</a>.
 * @param[in]  doc The input document.
 * @param[in]  lpsName The Specified name of the window provider.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRAppRegisterWndProvider
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocCreateNewViewByWndProvider, (FR_Document doc,  FS_LPCSTR lpsName))

/**
 * @brief FRDocLoadAnnots
 * @details Loads annotation(s) for an opening PDF document.
 * @param[in]  doc The input document.
 * @param[in]  arrAnnotDict The pointer array holding the annotation dictionaries to be loaded.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocLoadAnnots, (FR_Document doc,  FS_PtrArray arrAnnotDict))

/**
 * @brief FRDocGetDocShowTitle
 * @details Gets the title shown as the main frame title and the document tab title.
 * @param[in]  doc The document.
 * @param[out]  outTitle It receives the title shown as the main frame title and the document tab title.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more. User can use FRDocGetTabTitle function instead.
 */
INTERFACE(void, FRDocGetDocShowTitle, (FR_Document doc,  FS_WideString* outTitle))

/**
 * @brief FRDocDoSave2
 * @details Saves a file, handling any user interface(for example, a Save File dialog box) if need.
 * @param[in]  doc The document to be saved.
 * @param[in]  proc Callback function.
 * @param[in]  pProcData The client data. It will be passed to the save callback function.
 * @param[in]  bShowProgressBar Whether to show the progress bar or not.
 * @param[in]  bDoPDFOptimize Whether to optimize the PDF or not.
 * @return   True for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see FRDocDoSave
 * @see FRDocDoSaveAs
 * @see FRDocSetChangeMark
 */
INTERFACE(FS_BOOL, FRDocDoSave2, (FR_Document doc,  FR_DocSaveProc proc,  void* pProcData,  FS_BOOL bShowProgressBar,  FS_BOOL bDoPDFOptimize))

/**
 * @brief FRDocResetDocTitleColor
 * @details Resets the document title color in the document tab.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see FRDocSetDocTitleColor
 */
INTERFACE(void, FRDocResetDocTitleColor, (FR_Document doc))

/**
 * @brief FRDocSetDocTitleColor
 * @details Sets the document title color in the document tab.
 * @param[in]  doc The input document.
 * @param[in]  clrDocTitle The input color value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see FRDocResetDocTitleColor
 */
INTERFACE(void, FRDocSetDocTitleColor, (FR_Document doc,  FS_COLORREF clrDocTitle))

/**
 * @brief FRDocGetOriginalType
 * @details Gets the original type of the document. The real format of the opened document is PDF, but its wrapper format may be PPDF.
 * @param[in]  doc The input document.
 * @return   The original type of the document. The real format of the opened document is PDF, but its wrapper format may be PPDF.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see FRDocSetOriginalType
 */
INTERFACE(FROriginalDocType, FRDocGetOriginalType, (FR_Document doc))

/**
 * @brief FRDocSetOriginalType
 * @details Sets the original type of the document. The real format of the opened document is PDF, but its wrapper format may be PPDF.
 * @param[in]  doc The input document.
 * @param[in]  oriDocType The input original type of the document.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see FRDocGetOriginalType
 */
INTERFACE(void, FRDocSetOriginalType, (FR_Document doc,  FROriginalDocType oriDocType))

/**
 * @brief FRDocSetFocusAnnot
 * @details Sets the focus annotation.
 * @param[in]  doc The input document.
 * @param[in]  pFocusAnnot The input annotation.
 * @param[in]  bDelay Whether to delay the setting or not. The default value is FALSE.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_BOOL, FRDocSetFocusAnnot, (FR_Document doc,  FR_Annot pFocusAnnot,  FS_BOOL bDelay))

/**
 * @brief FRDocGenerateUR3Permission
 * @details Generates the UR3 signature. Usage rights signatures are used to enable additional interactive features that are not available by
	* default in a particular viewer application (such as Adobe Reader). See PDF reference for more details.
 * @param[in]  doc The input document.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @Deprecated    Internal use. It's not implement.
 */
INTERFACE(FS_BOOL, FRDocGenerateUR3Permission, (FR_Document doc))

/**
 * @brief FRDocHasRedactAnnot
 * @details Checks whether the document has redact annot.
 * @param[in]  doc The input document.
 * @return   TRUE: The document has redact annot.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_BOOL, FRDocHasRedactAnnot, (FR_Document doc))

/**
 * @brief FRDocGenerateRedactions
 * @details Generates a redacted document and it will be saved to <param>wsFilePath</param>.
 * @param[in]  doc The input document.
 * @param[out]  wsFilePath It receives the path of the document redacted, it is temp file path, you can copy or delete it.
 * @return   TRUE for success, otherwise for failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_BOOL, FRDocGenerateRedactions, (FR_Document doc,  FS_WideString* wsFilePath))

/**
 * @brief FRDocReloadPage
 * @details Reloads the specified page, used to refresh page view.
 * @param[in]  doc The input document.
 * @param[in]  iPage The specified page index.
 * @param[in]  bDisableGoto Whether to prevent going to the specified page view. Sets it FALSE as default.
 * @return   TRUE for success, otherwise for failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_BOOL, FRDocReloadPage, (FR_Document doc,  FS_INT32 iPage,  FS_BOOL bDisableGoto))

/**
 * @brief FRDocForbidChangeMark
 * @details Forbid setting the modify flag. Reader has a built-in flag that indicate whether a document has been modified,
	* if the value of the flag is valid, the Save button is enable, otherwise the Save button is 
	* disable.
 * @param[in]  doc The document.
 * @param[in]  bForbid Whether to forbid setting the modify flag or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.0.0
 * @see FRDocSetChangeMark
 * @see FRDocGetChangeMark
 * @see FRDocClearChangeMark
 */
INTERFACE(void, FRDocForbidChangeMark, (FR_Document doc,  FS_BOOL bForbid))

/**
 * @brief FRDocOpenFromPDDoc2
 * @details Opens and returns a <a>FR_Document</a> view of <a>PD_Document</a>.
 * @param[in]  pddoc The <a>FPD_Document</a> object to open.
 * @param[in]  lpwsTitle It is used as window's title.
 * @param[in]  bDelPDFDoc Whether the framework must delete the <a>FPD_Document</a> object or not. If the plug-in 
	* deletes the <a>FPD_Document</a> object through <a>FPDParserDestroy</a>(), sets it FALSE.
 * @return   The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
 * @note Do not open and then immediately close a FR_Document without letting least once event loop complete.
	* <a>FRDocClose</a>() should be used in place of <a>FPDDocClose</a>() after FRDocOpenFromPDDoc() is called.
	* <a>FRDocClose</a>() will decrement the FPDDoc appropriately and free document-related resources.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 * @see FRDocClose
 * @see FRDocOpenFromFile
 * @see FRDocFromPDDoc
 */
INTERFACE(FR_Document, FRDocOpenFromPDDoc2, (FPD_Document pddoc,  FS_LPCWSTR lpwsTitle,  FS_BOOL bDelPDFDoc))

/**
 * @brief FRDocGetCreateDocSource
 * @details Gets the source type of the document. Like from Multiple Files、SCANNER 、From Scanner.
 * @param[in]  doc The document.
 * @return   The source type of the document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 * @Deprecated    Internal use.
 */
INTERFACE(FRCreateDocSource, FRDocGetCreateDocSource, (FR_Document doc))

/**
 * @brief FRDocSetCreateDocSource
 * @details Sets the source type of the document.It used to named pdf in Scanner.
 * @param[in]  doc The document.
 * @param[in]  sourceType The input source type of the document.
 * @param[in]  lpwsSourceFileName The input source file name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetCreateDocSource, (FR_Document doc,  FRCreateDocSource sourceType,  FS_LPCWSTR lpwsSourceFileName))

/**
 * @brief FRDocGetCreateDocSourceFileName
 * @details Gets the create source file name.
 * @param[in]  doc The document.
 * @param[out]  outSourceFileName It receives the source file name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocGetCreateDocSourceFileName, (FR_Document doc,  FS_WideString* outSourceFileName))

/**
 * @brief FRDocParsePage
 * @details Parses the specified page.
 * @param[in]  doc The document.
 * @param[in]  nPageIndex The specified page index.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(FS_BOOL, FRDocParsePage, (FR_Document doc,  FS_INT32 nPageIndex))

/**
 * @brief FRDocIsValidAnnot
 * @details Checks whether the annotation is valid or not. Actually check the annot if in the document.
 * @param[in]  doc The document.
 * @param[in]  frAnnot The input annotation to be checked.
 * @return   TRUE if the annotation is valid.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(FS_BOOL, FRDocIsValidAnnot, (FR_Document doc,  FR_Annot frAnnot))

/**
 * @brief FRDocIsWillReopen
 * @details Checks whether the document is to be reopened after it is closed.
 * @param[in]  doc The document.
 * @return   TRUE if the document is to be reopened.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.2
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocIsWillReopen, (FR_Document doc))

/**
 * @brief FRDocOpenFromFile2
 * @details Opens and displays a document form a file.
 * @param[in]  wszFile The file path.
 * @param[in]  szPassword The password with the file. It could be <a>NULL</a> if no password to pass.
 * @param[in]  bMakeVisible Whether the document will be made visible.
 * @param[in]  bAddToMRU Whether add the file path to the recent file list.
 * @param[in]  bCheckCertPassword Whether prompt a password input dialog to check the password of the certificate used to encrypt the document.
 * @return   The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
 * @note Do not open and then immediately close a FR_Document without letting least once event loop complete.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 * @see FRDocClose
 * @see FRDocOpenFromPDDoc
 * @see FRDocFromPDDoc
	
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more. User can use FRDocOpenDocument function instead.
 */
INTERFACE(FR_Document, FRDocOpenFromFile2, (FS_LPCWSTR wszFile,  FS_LPCSTR szPassword,  FS_BOOL bMakeVisible,  FS_BOOL bAddToMRU,  FS_BOOL bCheckCertPassword))

/**
 * @brief FRDocGetSignaturePermissions
 * @details Gets the signature permissions of a document.
 * @param[in]  doc The document whose user permission is obtained.
 * @param[out]  pdwPermissions The document permissions.
 * @return   <a>TRUE</a> if the document is signed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 */
INTERFACE(FS_BOOL, FRDocGetSignaturePermissions, (FR_Document doc,  FS_DWORD *pdwPermissions))

/**
 * @brief FRDocConvertPdfToOtherFormat
 * @details Convert Pdf document to other format document.
 * @param[in]  wsSrcPath The source file which need to be converted. The souce file must be opened by editor.
 * @param[in]  wsDesPath The destination file path.
 * @param[in]  pageAry The pages need to be converted. if it is NULL ,will convert the whole document.
 * @param[in]  wsFileExt The format need to be convert. Support: docx, doc, xlsx, xls, html, pptx, rtf.
 * @param[in]  wsPwd The password of encrypt the document. if it is empty, will not encrypt the document.
 * @param[in]  bShowProgress Whether or not show the convert progress bar.
 * @return   <a>TRUE</a> converted sucessful.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FS_BOOL, FRDocConvertPdfToOtherFormat, (FS_LPCWSTR wsSrcPath,  FS_LPCWSTR wsDesPath,  FS_DWordArray pageAry,  FS_LPCWSTR wsFileExt,  FS_LPCWSTR wsPwd,  FS_BOOL bShowProgress))

/**
 * @brief FRDocDoPassWordEncrypt
 * @details Set the document password through the password input dialog.
 * @param[in]  frDoc The document to protected.
 * @param[in]  proc Prototype of callback function invoked by <Italic>Foxit Reader</Italic> to receive the protecting status.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(void, FRDocDoPassWordEncrypt, (FR_Document frDoc,  FRPasswordEncryptProc proc))

/**
 * @brief FRDocIsInProtectedViewMode
 * @details Check if the document is in protected view mode. It gets from preferences in security tab of "protected view".
 * @param[in]  frDoc The document to protected.
 * @return   <a>TRUE</a> means in the protected view mode.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(FS_BOOL, FRDocIsInProtectedViewMode, (FR_Document frDoc))

/**
 * @brief FRDocGetCreateDocSourceFilePath
 * @details Gets the source file path.
 * @param[in]  doc The document.
 * @param[out]  outSourceFilePath It receives the source file path.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocGetCreateDocSourceFilePath, (FR_Document doc,  FS_WideString* outSourceFilePath))

/**
 * @brief FRDocIsImageBasedDocument
 * @details Check if the document is Image Based Document.
 * @param[in]  frDoc The document.
 * @return   <a>TRUE</a> means all objects is PDFPAGE_IMAGE or PDFPAGE_PATH type.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.2
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocIsImageBasedDocument, (FR_Document frDoc))

/**
 * @brief FRDocSetDocEncrypted
 * @details Indicates whether the document is encrypted or not.
 * @param[in]  frDoc The document.
 * @param[in]  bEncrypted Indicates whether the document is encrypted or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.2
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetDocEncrypted, (FR_Document frDoc,  FS_BOOL bEncrypted))

/**
 * @brief FRDocIsVisible
 * @details Checks whether the opened document is visible or not.
 * @param[in]  frDoc The document.
 * @return   Whether the opened document is visible or not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.3
 */
INTERFACE(FS_BOOL, FRDocIsVisible, (FR_Document frDoc))

/**
 * @brief FRDocDeprecatedSetDRMSecurity
 * @details Sets security using custom security handler and custom encryption.
	* Application should provide a full encryption dictionary (application can destroy it after this call),
	* and a custom encryption handler.
 * @param[in]  doc The input document.
 * @param[in]  encryptDict The Encrypt dictionary.
 * @param[in]  cryptoHandler The callbacks for crypto handler.
 * @param[in]  bEncryptMetadata Whether to encrypt the metadata.
 * @param[in]  clientHandler The user-supplied data.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.5
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocDeprecatedSetDRMSecurity, (FR_Document doc,  FPD_Object encryptDict,  FS_LPVOID cryptoHandler,  FS_BOOL bEncryptMetadata,  FS_LPVOID clientHandler))

/**
 * @brief FRDocConvertPdfToOtherFormat2
 * @details Convert Pdf document to other format document.
 * @param[in]  wsDesPath The destination file path.
 * @param[in]  wsFileExt The format need to be convert. Support: docx, doc, xlsx, xls, html, pptx, rtf...
	*								Format example: Word Document(.docx) | .docx
 * @return   <a>TRUE</a> converted sucessful.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more. User can use FRDocConvertPdfToOtherFormat3 functions  instead.
 */
INTERFACE(FS_BOOL, FRDocConvertPdfToOtherFormat2, (FS_LPCWSTR wsDesPath,  FS_LPCSTR szFileExt))

/**
 * @brief FRDocAddWatermark
 * @details Add watermark to document, it will not update document view.
 * @param[in]  doc The input document.
 * @param[in]  pWatermarkInfo The watermark setting information.
 * @return   <a>0</a> add watermark sucessful.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 */
INTERFACE(FS_INT32, FRDocAddWatermark, (FR_Document doc,  FR_WatemarkElementInfo *pWatermarkInfo))

/**
 * @brief FRDocAddAndUpdateWatermark
 * @details Add watermark to document and update the document view.
 * @param[in]  doc The input document.
 * @param[in]  pWatermarkInfo The watermark setting information.
 * @return   <a>0</a> add watermark fail.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 */
INTERFACE(FS_INT32, FRDocAddAndUpdateWatermark, (FR_Document doc,  FR_WatemarkElementInfo *pWatermarkInfo))

/**
 * @brief FRDocRemoveWatermark
 * @details Remove watermark of document, it will not update document view.
 * @param[in]  doc The input document.
 * @param[in]  szSpecifyDicValue Remove the specify watermark that add with <a>FR_PWatemarkElementInfo</a> lpbSpecifyWatermarkDicValue,
	*								can be pass null means remove all watermark.
 * @return   <a>0</a> remove watermark fail.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 */
INTERFACE(FS_INT32, FRDocRemoveWatermark, (FR_Document doc,  FS_LPCSTR szSpecifyDicValue))

/**
 * @brief FRDocRemoveAndUpdateWatermark
 * @details Remove watermark to document and update the document view.
 * @param[in]  doc The input document.
 * @param[in]  szSpecifyDicValue Remove the specify watermark that add with <a>FR_PWatemarkElementInfo</a> lpbSpecifyWatermarkDicValue,
	*								can be pass null means remove all watermark.
 * @return   <a>0</a> remove watermark fail.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 */
INTERFACE(FS_INT32, FRDocRemoveAndUpdateWatermark, (FR_Document doc,  FS_LPCSTR szSpecifyDicValue))

/**
 * @brief FRDocAddHeaderFooter
 * @details Add header and footer to document, it will not update document view.
 * @param[in]  doc The input document.
 * @param[in]  pHeaderFooterInfo The header and footer setting information.
 * @return   <a>0</a> add header and footer fail.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 */
INTERFACE(FS_INT32, FRDocAddHeaderFooter, (FR_Document doc,  FR_HeaderFooterElementInfo *pHeaderFooterInfo))

/**
 * @brief FRDocAddAndUpdateHeaderFooter
 * @details Add header and footer to document and update the document view.
 * @param[in]  doc The input document.
 * @param[in]  pHeaderFooterInfo The header and footer setting information.
 * @return   <a>0</a> add header and footer fail.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 */
INTERFACE(FS_INT32, FRDocAddAndUpdateHeaderFooter, (FR_Document doc,  FR_HeaderFooterElementInfo *pHeaderFooterInfo))

/**
 * @brief FRDocRemoveHeaderFooter
 * @details Remove header and footer to document, it will not update document view.
 * @param[in]  doc The input document.
 * @param[in]  szSpecifyDicValue remove the specify header and footer that add with <a>FR_PHeaderFooterElementInfo</a>				
	*								lpbSpecifyHeaderFooterDicValue, can be pass null means remove all header and footer.
 * @return   <a>0</a> remove header and footer fail.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 */
INTERFACE(FS_INT32, FRDocRemoveHeaderFooter, (FR_Document doc,  FS_LPCSTR szSpecifyDicValue))

/**
 * @brief FRDocRemoveAndUpdateHeaderFooter
 * @details Remove header and footer to document and update the document view.
 * @param[in]  doc The input document.
 * @param[in]  szSpecifyDicValue remove the specify header and footer that add with <a>FR_PHeaderFooterElementInfo</a>				
	*								lpbSpecifyHeaderFooterDicValue, can be pass null means remove all header and footer.
 * @return   <a>0</a> remove header and footer fail.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7
 */
INTERFACE(FS_INT32, FRDocRemoveAndUpdateHeaderFooter, (FR_Document doc,  FS_LPCSTR szSpecifyDicValue))

/**
 * @brief FRDocIsReadSafeMode
 * @details Return true if the doc is Read Safe Mode. It gets from "Trust Manager" in prefrences.
 * @param[in]  doc The input document.
 * @return   Return true if the doc is Read Safe Mode.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.1
 */
INTERFACE(FS_BOOL, FRDocIsReadSafeMode, (FR_Document doc))

/**
 * @brief FRDocGetInterForm
 * @details FR_ReaderInterform used to process form appearance.
 * @param[in]  frDoc The input document.
 * @return   FR_ReaderInterform
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FR_ReaderInterform, FRDocGetInterForm, (FR_Document frDoc))

/**
 * @brief FRDocReplaceTextToSelectedText
 * @details 
 * @param[in]  frDoc The input document.
 * @param[in]  nPageIndex The page index.
 * @param[in]  nIndex The page end index.
 * @param[in]  replaceText The replace text.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocReplaceTextToSelectedText, (FR_Document doc,  FS_INT32 nPageIndex,  FS_INT32 nIndex,  FS_LPCWSTR replaceText))

/**
 * @brief FRDocGeneratePageContent
 * @details Generates all page content after change content.
 * @param[in]  doc The input document.
 * @param[in]  bProgress Indicates whether to show the progress bar or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.1
 */
INTERFACE(void, FRDocGeneratePageContent, (FR_Document doc,  FS_BOOL bProgress))

/**
 * @brief FRDocGetFocusAnnot
 * @details Gets the focus annotation including form control.
 * @param[in]  frDoc The input document.
 * @return   The focus annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FR_Annot, FRDocGetFocusAnnot, (FR_Document frDoc))

/**
 * @brief FRDocGetMenuEnableByName
 * @details Check menu is enabled. About permisson document, some menu will be set Disabled.
 * @param[in]  frDoc The input document.
 * @param[in]  csName The menu name.
 * @return   FS_BOOL   <a>TRUE</a> The menu is enabled.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FRDocSetMenuEnableByName
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocGetMenuEnableByName, (FR_Document frDoc,  FS_LPCSTR csName))

/**
 * @brief FRDocClearAllSelection
 * @details Clear all selection of annot.
 * @param[in]  frDoc The input document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use. User can use FRDocClearSelection function instead.
 */
INTERFACE(void, FRDocClearAllSelection, (FR_Document frDoc))

/**
 * @brief FRDocAddSelection
 * @details Set the annot to be selected.
 * @param[in]  frDoc The input document.
 * @param[in]  annot The annot need to select.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(void, FRDocAddSelection, (FR_Document frDoc,  FR_Annot annot))

/**
 * @brief FRDocGetPageFirstAnnot
 * @details Get the type of the annot in page.
 * @param[in]  frDoc The input document.
 * @param[in]  nPageIndex The page index.
 * @param[in]  csType The annot type. It's the Subtype info of annot dictionary.
 * @return   FR_Annot
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FR_Annot, FRDocGetPageFirstAnnot, (FR_Document frDoc,  FS_INT32 nPageIndex,  FS_LPCSTR csType))

/**
 * @brief FRDocCreateFormControl
 * @details Create form contol, use FRDocReloadPage after create.
 * @param[in]  frDoc The input document.
 * @param[in]  nPageIndex The page index.
 * @param[in]  rect The rect of the form.
 * @param[in]  nType The form type ,like FPD_FORM_FIELDTYPE_PUSHBUTTON.
 * @param[in]  iRotate The form rotate.
 * @param[in]  sName The form name after create.
 * @param[in]  bUseSuggestName Whether use suggest name.
 * @return   FR_Annot  Create the form annot.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FRDocReloadPage
 */
INTERFACE(FR_Annot, FRDocCreateFormControl, (FR_Document frDoc,  FS_INT32 nPageIndex,  FS_FloatRect rect,  FS_INT32 nType,  FS_INT32 iRotate,  FS_WideString sName,  FS_BOOLEAN bUseSuggestName))

/**
 * @brief FRDocReCalTabOrder
 * @details Reset tab order by the key "Tabs" of page dictionary.
 * @param[in]  frDoc The input document.
 * @param[in]  nPageIndex The page index.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocReCalTabOrder, (FR_Document frDoc,  FS_INT32 nPageIndex))

/**
 * @brief FRDocNotifyAddWidget
 * @details Notify add widget annot.
 * @param[in]  annot The input annot.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Current function has been deprecated, it moved to FRAnnotAdd in FR_DocEventCallback.
 */
INTERFACE(void, FRDocNotifyAddWidget, (FR_Annot annot))

/**
 * @brief FRDocUpdateAllViews
 * @details Refresh the area where the annotation is located of all pageviews expect the input pageview.
 * @param[in]  pageview The pageview.
 * @param[in]  pAnnot The input annot.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(void, FRDocUpdateAllViews, (FR_PageView pageview,  FR_Annot pAnnot))

/**
 * @brief FRDocGetAnnotByDict
 * @details Get FR_Annot object by dictionary.
 * @param[in]  frDoc The input document.
 * @param[in]  nPageIndex The page index.
 * @param[in]  pDict The annot dic.
 * @return   FR_Annot
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Current function has been deprecated .User can use FRPageGetAnnotByDict instead.
 */
INTERFACE(FR_Annot, FRDocGetAnnotByDict, (FR_Document frDoc,  FS_INT32 nPageIndex,  FPD_Object pDict))

/**
 * @brief FRDocAddAnnot
 * @details Add annot of specified property to page index.
 * @param[in]  frDoc The input document.
 * @param[in]  nPageIndex Add annot to the specified page index .
 * @param[in]  lpSubType The annot subtype.
 * @param[in]  rect The annot rect.
 * @return   FR_Annot
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FR_Annot, FRDocAddAnnot, (FR_Document frDoc,  FS_INT32 nPageIndex,  FS_LPCSTR lpSubType,  const FS_FloatRect rect))

/**
 * @brief FRDocAddAnnot2
 * @details Add annot of specified property to page index.
 * @param[in]  frDoc The input document.
 * @param[in]  nPageIndex The page index.
 * @param[in]  pDict The annot dictionary.
 * @param[in]  nIndex The annot index.
 * @return   FR_Annot
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FR_Annot, FRDocAddAnnot2, (FR_Document frDoc,  FS_INT32 nPageIndex,  FPD_Object pDict,  FS_INT32 nIndex))

/**
 * @brief FRDocReplacePages
 * @details Replaces the pages in the specified file.
 * @param[in]  frDoc The input document.
 * @param[in]  nStart The start page index of the currentdoc.
 * @param[in]  pSrcDoc The source doc.
 * @param[in]  arrSrcPages The pageindexs of the src doc.
 * @return   FS_BOOL  <a>FALSE</a> The srcDoc is NULL.
 * @note Annots in origin document will not be replace.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_BOOL, FRDocReplacePages, (FR_Document frDoc,  FS_INT32 nStart,  const FPD_Document pSrcDoc,  const FS_WordArray &arrSrcPages))

/**
 * @brief FRDocInsertPages
 * @details Insert the pages from the specified file.
 * @param[in]  frDoc The input document.
 * @param[in]  nInsertAt The insert index.
 * @param[in]  pSrcDoc The source doc.
 * @param[in]  arrSrcPages The pageindexs of the src doc.
 * @param[in]  bRenameForm If need to rename form.
 * @param[in]  bShowRenameFormDlg If show rename form dialog.
 * @param[in]  bEntireDoc If insert the whole doc.
 * @param[in]  srcDocTitle The title of source doc.
 * @param[in]  bRetainBookmark If retain bookmark.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_BOOL, FRDocInsertPages, (FR_Document frDoc,  FS_INT32 nInsertAt,  const FPD_Document pSrcDoc,  const FS_WordArray &arrSrcPages,  FS_BOOL bRenameForm,  FS_BOOL bShowRenameFormDlg,  FS_BOOL bEntireDoc,  FS_WideString srcDocTitle,  FS_BOOL bRetainBookmark))

/**
 * @brief FRDocExtractPages
 * @details Extract pages to dest document.
 * @param[in]  frDoc The input document.
 * @param[in]  arrExtraPages The extract index.
 * @param[in]  pDstDoc The dest doc after extract pages. Use FPDDocNew create memory doc and save it after extract.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_BOOL, FRDocExtractPages, (FR_Document frDoc,  const FS_WordArray &arrExtraPages,  FPD_Document pDstDoc))

/**
 * @brief FRDocGetDocSecurityCanBeModified
 * @details Get if the doc can be modified.
 * @param[in]  frDoc The input document.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocGetDocSecurityCanBeModified, (FR_Document frDoc))

/**
 * @brief FRDocGetDocument
 * @details The IReader_Document of the readerpage.
 * @param[in]  pReaderPage The IReader_Page obj.
 * @return   FR_Document
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Document, FRDocGetDocument, (FS_LPVOID pReaderPage))

/**
 * @brief FRDocGetAnnotByDict2
 * @details Get the annot by readerpage and annot dict.
 * @param[in]  pReaderPage The IReader_Page obj.
 * @param[in]  pDict The annot dic.
 * @return   FR_Annot
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRDocGetAnnotByDict2, (FS_LPVOID pReaderPage,  FPD_Object pDict))

/**
 * @brief FRDocGetPageIndex
 * @details Get page index of IReader_Page.
 * @param[in]  pReaderPage The IReader_Page obj.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRDocGetPageIndex, (FS_LPVOID pReaderPage))

/**
 * @brief FRDocRemoveSecurityInfo
 * @details Remove the securityInfo of the doc. Some password、certificate、DRM or other security will be remove.
 * @param[in]  frDoc The input document.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_BOOL, FRDocRemoveSecurityInfo, (FR_Document frDoc))

/**
 * @brief FRDocUpdateDocAllViews
 * @details Update all docviews except input docview.
 * @param[in]  frDoc The input document.
 * @param[in]  sender The doc view.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(void, FRDocUpdateDocAllViews, (FR_Document frDoc,  FR_DocView sender))

/**
 * @brief FRDocSendAsAttachment
 * @details Send the doc as attachment. It need to use outlook as default client sender.
 * @param[in]  frDoc The input document.
 * @param[in]  wsTo The email to info.
 * @param[in]  wsCc The email cc address.
 * @param[in]  wsBcc The email bcc address.
 * @param[in]  wsSubject The email subject.
 * @param[in]  wsMsg The email message.
 * @param[in]  bUI If show email UI.
 * @param[in]  bDocReopened If the doc need to reopened.
 * @param[in]  wsErrorMessage The error message after send email.
 * @return   FR_MailtoResult
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FR_MailtoResult, FRDocSendAsAttachment, (FR_Document frDoc,  const FS_WideString& wsTo,  const FS_WideString& wsCc,  const FS_WideString& wsBcc,  const FS_WideString& wsSubject,  const FS_WideString& wsMsg,  FS_BOOL bUI,  FS_BOOL& bDocReopened,  FS_WideString* wsErrorMessage))

/**
 * @brief FRDocOnBeforeNotifySumbit
 * @details xfa submit event, before notify sumbit.
 * @param[in]  frDoc The input document.
 * @param[in]  pSubmit The CXFA_Submit.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocOnBeforeNotifySumbit, (FR_Document frDoc,  FS_LPVOID pSubmit))

/**
 * @brief FRDocOnAfterNotifySumbit
 * @details xfa submit event, after notify sumbit.
 * @param[in]  frDoc The input document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocOnAfterNotifySumbit, (FR_Document frDoc))

/**
 * @brief FRDocConvertPdfToOtherFormat3
 * @details Convert Pdf document to other format document.
 * @param[in]  wsDesPath The destination file path.
 * @param[in]  wsFileExt The format need to be convert. Support: docx, doc, xlsx, xls, html, pptx, rtf...
	*								Format example: Word Document(.docx) | .docx	
	*                              Word 97 - 2003 (*.doc) | *.doc
	*                              HTML(*.htm, *.html) | *.htm; *.html
	*                              Rich Text Format(*.rtf) | *.rtf
	*                              TXT Files(*.txt) | *.txt
	*                              XML Spreadsheet 2003 (*.xml) | *.xml
	*                              Excel(*.xlsx) | *.xlsx
	*                              PowerPoint(*.pptx) | *.pptx
	*                              PNG(*.png) | *.png
	*                              JPEG(*.jpg, *.jpeg, *.jpe, *.jif) | *.jpg; *.jpeg; *.jpe; *.jif
	*                              TIFF(*.tiff, *.tif) | *.tiff; *.tif
	*                              BMP(*.bmp, *.dib, *.rle) | *.bmp; *.dib; *.rle
	*                              JPEG2000(*.jpf, *.jpx, *.jp2, *.j2k, *.jpc) | *.jpf; *.jpx; *.jp2; *.j2k; *.jpc
	*                              XPS Document(*.xps, *.oxps) | *.xps; *.oxps
 * @param[out]  pnRetType The convert result.
 * @param[in]  bShowTip If show tip.
 * @return   <a>TRUE</a> converted sucessful.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_BOOL, FRDocConvertPdfToOtherFormat3, (FS_LPCWSTR wsDesPath,  FS_LPCSTR szFileExt,  FS_INT32* pnReType,  FS_BOOL bShowTip))

/**
 * @brief FRDocGetPage
 * @details Gets the specified <a>FR_Page</a> for specified document.
 * @param[in]  frDoc The input document.
 * @param[in]  page_index The page index.
 * @return   The specified <a>FR_Page</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Page, FRDocGetPage, (FR_Document frDoc,  FS_INT32 page_index))

/**
 * @brief FRDocSetNotify
 * @details Set the handler to IFormDesigner. When widget form has changed, it will be called.
 * @param[in]  notify The CFR_IFormDesignerNotifyHandler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FRD_FormDesignNotifyCallbacks
 */
INTERFACE(void, FRDocSetNotify, (FR_IFormDesignerNotify notify))

/**
 * @brief FRDocSetTabOrder
 * @details Set tab order of widgets in all pages.
 * @param[in]  pDoc The input document.
 * @param[in]  eOrder The tabOrder.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocSetTabOrder, (FR_Document pDoc,  FR_TabOrder eOrder))

INTERFACE(FS_BOOL, FRDocSetTabOrder2, (FR_Page pPage,  FR_TabOrder eOrder))

/**
 * @brief FRDocIsKeepSelectedChecked
 * @details Check the "Keep tool select" is select, if TRUE, it can create the type of widget continuously.
 * @return   FS_BOOL   TRUE: Continuously to create the type of widget.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocIsKeepSelectedChecked, ())

/**
 * @brief FRDocReConStructAcroform
 * @details ReConstruct a form from a document.
	* ReConstruct a form in order to regenerate appearance streams for the fields.
 * @param[in]  frDoc The input document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(void, FRDocReConStructAcroform, (FR_Document frDoc))

/**
 * @brief FRDocGetOCProperties
 * @details Get Optional Content Properties from FR_Document.
 * @param[in]  frDoc The input document.
 * @return   FPD_OCProperties Get the OCProperties of the doc.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_OCProperties, FRDocGetOCProperties, (FR_Document frDoc))

/**
 * @brief FRDocResetOCProperties
 * @details Reset FPD_OCProperties from FR_Document.
 * @param[in]  frDoc The input document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocResetOCProperties, (FR_Document frDoc))

/**
 * @brief FRDocSetCertifyDocument
 * @details Set whether the document is certified, if set TRUE, it will not to set tabOrder to WidgetAnnotList.
 * @param[in]  frDoc The input document.
 * @param[in]  bDocCertified If the doc certified.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetCertifyDocument, (FR_Document frDoc,  FS_BOOL bDocCertified))

/**
 * @brief FRDocIsCertifyDocument
 * @details Get whether the document is certified.
 * @param[in]  frDoc The input document.
 * @return   FS_BOOL   TRUE: the document is certified.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocIsCertifyDocument, (FR_Document frDoc))

/**
 * @brief FRDocSetSignaturePermissions
 * @details Set signature permisson to FR_Document.
 * @param[in]  doc The input document.
 * @param[in]  pdwPermissions The permisson of the doc.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetSignaturePermissions, (FR_Document doc,  FS_DWORD pdwPermissions))

/**
 * @brief FRDocSetSaveMode
 * @details Set the mode of save document.
 * @param[in]  frDoc The input document.
 * @param[in]  SaveModeFlag The save mode, like FPD_SAVE_INCREMENTAL.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FPD_SAVE_INCREMENTAL
 * @see FPD_SAVE_NO_ORIGINAL
 */
INTERFACE(void, FRDocSetSaveMode, (FR_Document doc,  FS_DWORD SaveModeFlag))

/**
 * @brief FRDocGetSaveMode
 * @details Get the save mode of the doc.
 * @param[in]  frDoc The input document.
 * @return   FS_DWORD
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FPD_SAVE_INCREMENTAL
 * @see FPD_SAVE_NO_ORIGINAL
 */
INTERFACE(FS_DWORD, FRDocGetSaveMode, (FR_Document doc))

/**
 * @brief FRDocSetDocumentTrustBySignature
 * @details Set the document if signatured by trust certificate.
 * @param[in]  frDoc The input document.
 * @param[in]  bTrust TRUE: the document is signatured by trust certificate.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetDocumentTrustBySignature, (FR_Document frDoc,  FS_BOOL bTrust))

/**
 * @brief FRDocGetXFADocView
 * @details Get FPD_XFADocView of the document.
 * @param[in]  frDoc The input document.
 * @return   FPD_XFADocView
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_XFADocView, FRDocGetXFADocView, (FR_Document frDoc))

/**
 * @brief FRDocGetReaderDocument
 * @details Get FR_Document of FPD_Document.
 * @param[in]  pdfdoc The input  pdf document.
 * @return   FR_Document          Get the FR_Document of the FPD_Document
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FR_Document, FRDocGetReaderDocument, (FPD_Document pdfdoc))

/**
 * @brief FRDocIsRunningJSAction
 * @details Get if running javascript action now.
 * @param[in]  frDoc The input document.
 * @return   FS_BOOLEAN       TRUE: Running javascript action now.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRDocIsRunningJSAction, (FR_Document frDoc))

/**
 * @brief FRDocCountSelection
 * @details Get the count of selected annot.
 * @param[in]  frDoc The input document.
 * @return   FS_DWORD
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_DWORD, FRDocCountSelection, (FR_Document frDoc))

/**
 * @brief FRDocGetSelection
 * @details Get the index annot of selected annots.
 * @param[in]  frDoc The input document.
 * @param[in]  index The index of selected annots.
 * @return   FR_Annot         Get the index annot of selected annots.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FR_Annot, FRDocGetSelection, (FR_Document frDoc,  FS_DWORD index))

/**
 * @brief FRDocGetTopPageState
 * @details Gets the state of the first page of the current visible pages when the multiple pages visible.
 * @param[in]  frDoc The input document.
 * @param[out]  nPage The page index.
 * @param[out]  state The page state.	The dest of state need to call FSFloatArrayNew first.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_BOOL, FRDocGetTopPageState, (FR_Document frDoc,  FS_INT32* nPage,  FR_PAGESTATE* state))

/**
 * @brief FRDocSetValidationStatus
 * @details Set the certificate state of document.
 * @param[in]  frDoc The input document.
 * @param[in]  Flag The certificate flag. 1:available,2: unavailable,3: unknow
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetValidationStatus, (FR_Document doc,  FS_DWORD Flag))

/**
 * @brief FRDocSetMemDocCanReopen
 * @details For memory doc, if set false, it will not be reopen after save.
 * @param[in]  frDoc The input document.
 * @param[in]  bCanReopen If the doc can be reopen
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(void, FRDocSetMemDocCanReopen, (FR_Document doc,  FS_BOOLEAN bCanReopen))

/**
 * @brief FRDocAppendUnCompressObjects
 * @details Set uncomproess object when save the file.
 * @param[in]  frDoc The input document.
 * @param[in]  aryObjNum Append uncompress objnum to temp variable.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FPDCreatorAttachUncompressObjects
 */
INTERFACE(void, FRDocAppendUnCompressObjects, (FR_Document doc,  FS_DWordArray aryObjNum))

/**
 * @brief FRDocDoSaveAs3
 * @details Save the current document.
 * @param[in]  doc The document.
 * @param[in]  pwszFilePath The path where the document to be saved as.
 * @param[in]  proc Callback function.
 * @param[in]  pProcData The client data. It will be passed to the save-as callback function.
 * @param[in]  option Save file option.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FR_DocSaveAsProc
 */
INTERFACE(FS_BOOL, FRDocDoSaveAs3, (FR_Document doc,  FS_LPCWSTR pwszFilePath,  FR_DocSaveAsProc proc,  void* pProcData,  FR_SaveDocOption option))

/**
 * @brief FRDocSaveAsOleProc
 * @details Save the Embedded document, like the document open from the office, after save the document, phantom will be closed.
 * @param[in]  doc The document.
 * @param[in]  proc Callback function.
 * @param[in]  pProcData The client data. It will be passed to the save-as callback function.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FR_DocSaveAsProc
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocSaveAsOleProc, (FR_Document doc,  FRDocOleSaveProc proc,  FS_LPVOID pProcData))

/**
 * @brief FRDocGetUnCompressObjects
 * @details Get objects that not need to be comproessed.
 * @param[in]  frDoc The input document.
 * @param[out]  aryObjNum Get uncompress objnum in temp variable.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocGetUnCompressObjects, (FR_Document doc,  FS_DWordArray* aryObjNum))

/**
 * @brief FRDocIsReflowViewMode
 * @details Get the document if in reflow view mode now.
 * @param[in]  frDoc The input document.
 * @return   FS_BOOLEAN       true: It's showing in reflow view mode.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRDocIsReflowViewMode, (FR_Document doc))

/**
 * @brief FRDocGetOpenFilePath
 * @details Get the path of the current document.
 * @param[in]  frDoc The input document.
 * @param[in]  openOption The open option of the file.
 * @param[out]  path Get the file path.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRDocGetOpenFilePath, (FR_Document doc,  FR_OpenFileOption openOption,  FS_WideString* path))

/**
 * @brief FRDocGetTabTitle
 * @details Get the title of the tab.
 * @param[in]  frDoc The input document.
 * @param[out]  wsTitle Return the title of the tab.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRDocGetTabTitle, (FR_Document doc,  FS_WideString* wsTitle))

/**
 * @brief FRDocGetTextPage
 * @details Get FPD_TextPage object from document.
 * @param[in]  frDoc The input document.
 * @param[in]  iPage The page index.
 * @param[in]  bCreate Default is TRUE, if true will create TextPage.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FPD_TextPage, FRDocGetTextPage, (FR_Document doc,  FS_INT32 iPage,  FS_BOOL bCreate))

/**
 * @brief FRDocCloseFileHandler
 * @details Close file stream handler of the filepath.
 * @param[in]  frDoc The input document.
 * @param[in]  csFilepath The input file path.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocCloseFileHandler, (FR_Document doc,  FS_LPCWSTR csFilepath))

/**
 * @brief FRDocResetFileHandler
 * @details Reset the file stream handler of the filepath.
 * @param[in]  frDoc The input document.
 * @param[in]  csFilepath The input file path.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocResetFileHandler, (FR_Document doc,  FS_LPCWSTR csFilepath))

/**
 * @brief FRDocGetDocPages
 * @details Get the count of pages for specified document.
 * @param[in]  doc The input document.
 * @return   The number of pages for specified document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_INT32, FRDocGetDocPages, (FR_Document doc))

/**
 * @brief FRDocOpenDocument
 * @details Opens and displays a document form a file.
 * @param[in]  wszFile The file path.
 * @param[in]  option The open file option.
 * @return   FR_Document 	The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
 * @note Do not open and then immediately close a FR_Document without letting least once event loop complete.
	* See: FRDocClose
	* See: FRDocOpenFromPDDoc
	* See: FRDocFromPDDoc
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_Document, FRDocOpenDocument, (FS_LPCWSTR wszFile,  FR_OpenFileOption option))

/**
 * @brief FRDocGetFileName
 * @details 
 * @param[in]  doc The input document.
 * @param[out]  wsName The filename of the doc.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRDocGetFileName, (FR_Document doc,  FS_WideString* wsName))

/**
 * @brief FRDocClearMousePtHandleData
 * @details 
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocClearMousePtHandleData, (FR_Document doc))

/**
 * @brief FRDocResizePage
 * @details 
 * @param[in]  doc The input document.
 * @param[in]  iPage The page index.
 * @param[in]  pMediaBox The rect of MediaBox.
 * @param[in]  pCropBox The rect of CropBox.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRDocResizePage, (FR_Document doc,  FS_INT32 iPage,  const FS_FloatRect pMediaBox,  const FS_FloatRect pCropBox))

/**
 * @brief FRDocGetPageLabel
 * @details 
 * @param[in]  doc The input document.
 * @param[in]  pageIndex The page index.
 * @param[out]  outLabel Get the page label.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRDocGetPageLabel, (FR_Document doc,  FS_INT32 pageIndex,  FS_WideString* outLabel))

/**
 * @brief FRDocRequestDocPermPDDoc
 * @details 
 * @param[in]  doc The document whose permissions are being requested.
 * @param[in]  reqObj The target object of the permissions request.
 * @param[in]  reqOpr The target operation of the permissions.
 * @param[in]  authData A pointer to an authorization data structure.
 * @return   FRPermReqStatus 	 The request status constant, <code>0</code> if the requested operation
	* is allowed, a non - zero status code otherwise.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FRPermReqStatus, FRDocRequestDocPermPDDoc, (FR_Document pReaderDoc,  FRPermReqObj reqObj,  FRPermReqOpr reqOpr,  FS_LPVOID authData))

INTERFACE(FS_BOOL, FRDocGetSelectPageFromPagePanel, (FR_Document pReaderDoc,  FS_DWordArray* arraySelPage))

/**
 * @brief FRDocGetDocOpenJSFinish
 * @details 
 * @param[in]  doc The input document.
 * @return   FS_BOOL 	  TRUE: Get select page success.	
	* Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocGetDocOpenJSFinish, (FR_Document pReaderDoc))

/**
 * @brief FRDocGetDocRenderFinish
 * @details 
 * @param[in]  doc The input document.
 * @return   FS_BOOL 	  TRUE: Render finished.	
	* Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocGetDocRenderFinish, (FR_Document pReaderDoc))

/**
 * @brief FRDocReversePages
 * @details 
 * @param[in]  pReaderDoc The input document.
 * @param[in]  arrPages The pages need to be reverse.
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRDocReversePages, (FR_Document pReaderDoc,  const FS_DWordArray arrPages))

/**
 * @brief FRDocIsDynamicXFADocument
 * @details 
 * @param[in]  pdfDoc The input FPD_Document.
 * @return   FS_BOOL 	  Whether is XFA document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRDocIsDynamicXFADocument, (FPD_Document pdfDoc))

/**
 * @brief FRDocIsUseLogicalLabel
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @return   FS_BOOL 	  Whether the document use logical label.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use. This function is deprecated. Suggest use FRDocProcessIsUsedLogicalPage from docprocess plugin.
 */
INTERFACE(FS_BOOL, FRDocIsUseLogicalLabel, (FR_Document pReaderDoc))

/**
 * @brief FRDocDeletePages
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  arrDelPages The page array need to delete.
 * @return   FS_BOOL 	      TRUE delete pages success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRDocDeletePages, (FR_Document pReaderDoc,  FS_WordArray arrDelPages))

/**
 * @brief FRDocExtractPages2
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  pFile Extract pages to temp file.
 * @param[in]  arrExtraPages The page array need to extract.
 * @return   FS_BOOL 	      TRUE extract pages success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 */
INTERFACE(FS_BOOL, FRDocExtractPages2, (FR_Document pReaderDoc,  FS_FileWriteHandler pFile,  FS_WordArray arrExtraPages))

/**
 * @brief FRDocOnAfterExtractPagesEx
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  arrSrcPages Extract page array.
 * @param[in]  wsDestfilepath The temp file path to extract.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocOnAfterExtractPagesEx, (FR_Document pReaderDoc,  FS_WordArray arrSrcPages,  FS_WideString wsDestfilepath))

/**
 * @brief FRDocSwapTwoPage
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  indexPage1 The page index 1 need to swap.
 * @param[in]  indexPage2 The page index 2 need to swap.
 * @return   FS_BOOL   TRUE swap success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 */
INTERFACE(FS_BOOL, FRDocSwapTwoPage, (FR_Document pReaderDoc,  FS_INT32 indexPage1,  FS_INT32 indexPage2))

/**
 * @brief FRDocMovePages
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  nMoveAt The dest index of moved to.
 * @param[in]  arrMovePages The pageindex array need to move.
 * @return   FS_BOOL   TRUE move success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 */
INTERFACE(FS_BOOL, FRDocMovePages, (FR_Document pReaderDoc,  FS_INT32 nMoveAt,  FS_WordArray arrMovePages))

/**
 * @brief FRDocGetSnapShotInfo
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[out]  rcRect Get the shot rect.
 * @param[out]  nPageIndex Get the shot page index.
 * @return   FS_BOOL   TRUE get shot info success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocGetSnapShotInfo, (FR_Document pReaderDoc,  FS_FloatRect* rcRect,  FS_INT32* nPageIndex))

/**
 * @brief FRDocGetPageIndexByLabel
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  csPageLabel The input page label string.
 * @return   FS_INT32   Get the page index.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 */
INTERFACE(FS_INT32, FRDocGetPageIndexByLabel, (FR_Document pReaderDoc,  FS_WideString csPageLabel))

/**
 * @brief FRDocRotatePage
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  iPage The page index need to rotate.
 * @param[in]  nRotate The page rotate.
 * @return   FS_BOOL   TRUE rotate page success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 */
INTERFACE(FS_BOOL, FRDocRotatePage, (FR_Document pReaderDoc,  FS_INT32 iPage,  FS_INT32 nRotate))

/**
 * @brief FRDocHasOwnerPermission
 * @details Check if the document is set with an owner password.
	* Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @param[in]  pReaderDoc The input FR_Document.
 * @return   FS_BOOLEAN   TRUE has owner permisson.
 * @note It has been deprecated, suggest use FRInternalSecurityHandlerHasOwnerPermission from security plugin.
 */
INTERFACE(FS_BOOLEAN, FRDocHasOwnerPermission, (FR_Document pReaderDoc))

/**
 * @brief FRDocSetSaveParam
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  bUseObjStreamCreator Use object stream creator
 * @param[in]  fileVersion It should be from 10 to 17.
 * @return   FS_BOOL                     true: set save param success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocSetSaveParam, (FR_Document pReaderDoc,  FS_BOOL bUseObjStreamCreator,  FS_INT32 fileVersion))

/**
 * @brief FRDocCheckModuleLicense
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @return   FS_BOOLEAN                  true: It has module license.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRDocCheckModuleLicense, (FR_Document pReaderDoc))

/**
 * @brief FRDocGetDocFromContainerDoc
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  pContainerDoc The container document.
 * @return   FR_Document                 Get the doc from container document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Document, FRDocGetDocFromContainerDoc, (FR_Document pReaderDoc,  FR_Document pContainerDoc))

/**
 * @brief FRDocIsDocClosing
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @return   FS_BOOL                     Check if the doc has been closed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocIsDocClosing, (FR_Document pReaderDoc))

/**
 * @brief FRDocGetHitImageObj
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[out]  pHitPageView Get the hit page view.
 * @return   FR_SelectedImageInfo        Get current selected image object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FR_SelectedImageInfo, FRDocGetHitImageObj, (FR_Document pReaderDoc,  FR_PageView* pHitPageView))

/**
 * @brief FRDocClearHitImageObj
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FRDocClearHitImageObj, (FR_Document pReaderDoc))

/**
 * @brief FRDocPromptToDetectFileHandle
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRDocPromptToDetectFileHandle, (FR_Document pReaderDoc))

/**
 * @brief FRDocAddIgnoreObjects
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  Objs Object nums that need to ignore when save.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocAddIgnoreObjects, (FR_Document pReaderDoc,  FS_DWordArray Objs))

/**
 * @brief FRDocInsertPageByDict
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  nInsertAt The index of the new page.
 * @param[in]  cwTemplateName The page template name.
 * @param[in]  pSrcDict The input page dictionary.
 * @param[in]  bRenameForm TRUE: need rename form.
 * @return   FS_BOOL    TRUE: Insert success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocInsertPageByDict, (FR_Document pReaderDoc,  FS_INT32 nInsertAt,  FS_LPCWSTR cwTemplateName,  const FPD_Object pSrcDict,  FS_BOOL bRenameForm))

/**
 * @brief FRDocSaveToXFADoc
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSaveToXFADoc, (FR_Document pReaderDoc))

/**
 * @brief FRDocGetDeletePageUndoItem
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @return   FR_DeletePageUndoItem
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_DeletePageUndoItem, FRDocGetDeletePageUndoItem, (FR_Document pReaderDoc))

/**
 * @brief FRDocReleaseDeletePageUndoItem
 * @details 
 * @param[in]  pItem The input FR_DeletePageUndoItem.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocReleaseDeletePageUndoItem, (FR_DeletePageUndoItem pItem))

/**
 * @brief FRDocDeletePagesUndo
 * @details 
 * @param[in]  pItem The input FR_DeletePageUndoItem.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocDeletePagesUndo, (FR_DeletePageUndoItem pItem))

/**
 * @brief FRDocDeletePagesRedo
 * @details 
 * @param[in]  pItem The input FR_DeletePageUndoItem.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocDeletePagesRedo, (FR_DeletePageUndoItem pItem))

/**
 * @brief FRDocMergeTwoDoc
 * @details 
 * @param[in]  info1 The input document info.
 * @param[in]  info2 The input document info.
 * @param[in]  destFilePath The input file path after merge.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_BOOL, FRDocMergeTwoDoc, (FR_MERGRINFO info1,  FR_MERGRINFO info2,  FS_LPCWSTR destFilePath))

/**
 * @brief FRDocGetCurrentTool
 * @details Get current tool of the FR_Document.
 * @param[in]  pDoc The input FR_Document.
 * @return   FR_Tool  Get current tool of the FR_Document.
 * @note 
 */
INTERFACE(FR_Tool, FRDocGetCurrentTool, (FR_Document pDoc))

/**
 * @brief FRDocIsDocumentShowLineWeights
 * @details Get if user check the line weight in view setting.
 * @param[in]  pDoc The input FR_Document.
 * @return   FS_BOOLEAN      true: User check the line weight in view setting.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRDocIsDocumentShowLineWeights, (FR_Document pDoc))

/**
 * @brief FRDocIsCurDocViewShowInContainerFrm
 * @details Get if the current doc view show in container.
 * @param[in]  pDoc The input FR_Document.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocIsCurDocViewShowInContainerFrm, (FR_Document pDoc))

/**
 * @brief FRDocMovePages2
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  nMoveAt The dest index of moved to.
 * @param[in]  arrMovePages The pageindex array need to move.
 * @param[in]  progress The input FR_UIProgress.
 * @return   FS_BOOL   TRUE move success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 */
INTERFACE(FS_BOOL, FRDocMovePages2, (FR_Document pReaderDoc,  FS_INT32 nMoveAt,  FS_WordArray arrMovePages,  FR_UIProgress progress))

/**
 * @brief FRDocRemoveAnnotSelection
 * @details Remove the annot selection.
 * @param[in]  pDoc The input FR_Document.
 * @param[in]  annot The input annot.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocRemoveAnnotSelection, (FR_Document pDoc,  FR_Annot annot))

/**
 * @brief FRDocDoSaveAsWithDefaultPath
 * @details Displays a file save as dialog with default path which can be used to save the document as a new name.
 * @param[in]  doc The FR_Document need to save as.
 * @param[in]  saveAsPath The default save path.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see FRDocDoSaveAsWithDefaultPath
 */
INTERFACE(void, FRDocDoSaveAsWithDefaultPath, (FR_Document doc,  FS_LPCWSTR saveAsPath))

/**
 * @brief FRDocSplitPageByRects
 * @details Split page by specified rect array.
 * @param[in]  doc The input FR_Document obj.
 * @param[in]  nPageIndex The input page index.
 * @param[in]  rects Split the page according to the specified rect array.
 * @param[in]  postion The insert page position after split the page.
 * @return   FS_BOOLEAN     true: split success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1
 */
INTERFACE(FS_BOOLEAN, FRDocSplitPageByRects, (FR_Document doc,  FS_INT32 nPageIndex,  FS_FloatRectArray rects,  FS_INT32 postion))

/**
 * @brief FRDocIsEmbeded
 * @details Check if the input FR_Document is embeded.
 * @param[in]  doc The current FR_Document obj.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @see FRDocIsEmbeded
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocIsEmbeded, (FR_Document doc))

/**
 * @brief FRDocGetSaveSaveAsNotify
 * @details Get FR_Save_SaveAsNotify obj.
 * @param[in]  doc The current FR_Document obj.
 * @return   FR_Save_SaveAsNotify
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @see FRDocGetSaveSaveAsNotify
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Save_SaveAsNotify, FRDocGetSaveSaveAsNotify, (FR_Document doc))

/**
 * @brief FRDocSetSaveSaveAsNotify
 * @details Set FR_Save_SaveAsNotify obj.
 * @param[in]  doc The current FR_Document obj.
 * @param[in]  notify The current FR_Save_SaveAsNotify obj.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0
 * @see FRDocSetSaveSaveAsNotify
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocSetSaveSaveAsNotify, (FR_Document doc,  FR_Save_SaveAsNotify notify))

/**
 * @brief FRDocGetCanReopen
 * @details Check if the doc can reopen.
 * @param[in]  doc The current FR_Document obj.
 * @return   FS_BOOL   TRUE means can reopen, otherwise can't.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see FRDocGetCanReopen
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocGetCanReopen, (FR_Document doc))

/**
 * @brief FRDocSetTopmostAnnot
 * @details Set top most annot.
 * @param[in]  doc The current FR_Document obj.
 * @param[in]  pAnnot The input FR_Annot.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRDocSetTopmostAnnot, (FR_Document doc,  FR_Annot pAnnot))

/**
 * @brief FRDocOnAfterRotatePages
 * @details Notify after rotate pages.
 * @param[in]  pDoc The current FR_Document obj.
 * @param[in]  arrPages The input pages.
 * @param[in]  nRotate The input rotate value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocOnAfterRotatePages, (FR_Document pDoc,  const FS_WordArray arrPages,  FS_INT32 nRotate))

/**
 * @brief FRDocSetPageLabel
 * @details Set page label.
 * @param[in]  pDoc The current FR_Document obj.
 * @param[in]  option The input FR_PageLabelOption.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see 
 */
INTERFACE(void, FRDocSetPageLabel, (FR_Document pDoc,  FR_PageLabelOption option))

/**
 * @brief FRDocRunOCR
 * @details Execute OCR operations on current actived document.
 * @param[in]  pParent The specified parent HWND. If OCR is not executed in the specified window, it can be FRAppGetMainFrameWnd.
 * @param[in]  settingInfo The specified settings, like ocr language, mode.
	*                              If set to null, OCR will be performed according to the default settings of the current editor.
 * @param[in]  bShowProgress If need show progress bar.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRDocRunOCR, (FS_HWND pParent,  const FR_OCRSettingInfo* settingInfo,  FS_BOOLEAN  bShowProgress))

/**
 * @brief FRDocRunPageOCR
 * @details Execute OCR operations on specified page.
 * @param[in]  pPDFPage The specified page that need to execute OCR.
 * @param[in]  settingInfo The specified settings, like ocr language, mode.
	*                              If set to null, OCR will be performed according to the default settings of the current editor.
 * @param[in]  bShowProgress If need show progress bar.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 * @see 
 */
INTERFACE(FS_BOOLEAN, FRDocRunPageOCR, (FPD_Page pPDFPage,  const FR_OCRSettingInfo* settingInfo,  FS_BOOLEAN  bShowProgress))

/**
 * @brief FRDocCreateOrganizeNotify
 * @details 
 * @param[in]  callback The input FR_OrganizeNotifyCallbacks.
 * @return   FR_OrganizeNotify
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_OrganizeNotify, FRDocCreateOrganizeNotify, (FR_OrganizeNotifyCallbacks callback))

/**
 * @brief FRDocDestroyOrganizeNotify
 * @details 
 * @param[in]  notify The input FR_OrganizeNotify object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRDocDestroyOrganizeNotify, (FR_OrganizeNotify notify))

/**
 * @brief FRDocExtractPages3
 * @details 
 * @param[in]  pReaderDoc The input FR_Document.
 * @param[in]  pFile Extract pages to temp file.
 * @param[in]  arrExtraPages The page array need to extract.
 * @param[in]  notify The input FR_OrganizeNotify object.
 * @return   FS_BOOL 	      TRUE extract pages success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRDocExtractPages3, (FR_Document pReaderDoc,  FS_FileWriteHandler pFile,  FS_WordArray arrExtraPages,  FR_OrganizeNotify notify))

NumOfSelector(FRDoc)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//*****************************
/* CustomSignature HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRCustomSignatureGenerateSignInfo
 * @details Signs a PDF document with the <a>FR_SignatureInfo</a> and <a>FR_SignaturePosInfo</a>. You have to register the signature
	* handler by <a>FRCustomSignatureRegisterSignatureHandler</a>to sign the data, otherwise the data will be signed with the default standard method.
 * @param[in]  pSgInfo To fill the signature info.
 * @param[in]  pSgPosInfo To fill the signature position info.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_BOOL, FRCustomSignatureGenerateSignInfo, (FR_SignatureInfo* pSgInfo,  FR_SignaturePosInfo* pSgPosInfo))

/**
 * @brief FRCustomSignatureGetDefaultServer
 * @details Gets the default timestamp server.
 * @param[out]  pSgTMServer It receives the default timestamp server.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_BOOL, FRCustomSignatureGetDefaultServer, (FR_SignatureTimestampServer* pSgTMServer))

/**
 * @brief FRCustomSignatureCreateSignatureHandler
 * @details Creates the signature handler. Registers it by <a>FRCustomSignatureRegisterSignatureHandler</a>. Destroys it by <a>FRCustomSignatureDestroySignatureHandler</a>.
 * @param[in]  callbacks The callback set for signature handler.
 * @return   The pointer to the signature handler.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(void*, FRCustomSignatureCreateSignatureHandler, (FR_SignatureHandlerCallbacks callbacks))

/**
 * @brief FRCustomSignatureRegisterSignatureHandler
 * @details Registers the signature handler. You can customize the process signing the data and the process verifying the digital signature.
 * @param[in]  pSignatureHandler The input pointer to signature handler.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_BOOL, FRCustomSignatureRegisterSignatureHandler, (void* pSignatureHandler))

/**
 * @brief FRCustomSignatureDestroySignatureHandler
 * @details Destroys the signature handler returned by <a>FRCustomSignatureCreateSignatureHandler</a>.
 * @param[in]  pSignatureHandler The input pointer to signature handler.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(void, FRCustomSignatureDestroySignatureHandler, (void* pSignatureHandler))

/**
 * @brief FRCustomSignatureSetSignatureVerify
 * @details Verifies whether the document was signed with the specified signature.
 * @param[in]  frDoc The input document.
 * @param[in]  pSignedData The signed data.
 * @param[in]  ulSignedDataLen The length of the signed data.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 */
INTERFACE(FS_BOOL, FRCustomSignatureSetSignatureVerify, (FR_Document frDoc,  const unsigned char* pSignedData,  unsigned long ulSignedDataLen))

/**
 * @brief FRCustomSignatureGetDocSigatureCount
 * @details Gets the signature count.
 * @param[in]  frDoc The input document.
 * @return   The signature count.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_INT32, FRCustomSignatureGetDocSigatureCount, (FR_Document frDoc))

/**
 * @brief FRCustomSignatureGetSignatureBaseInfo
 * @details Gets the specified base info of the signature.
 * @param[in]  frDoc The input document.
 * @param[in]  nIndex The index of the signature.
 * @param[out]  pInfo It receives the base info of the signature.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_BOOL, FRCustomSignatureGetSignatureBaseInfo, (FR_Document frDoc,  FS_INT32 nIndex,  FR_SignatureBaseInfo* pInfo))

/**
 * @brief FRCustomSignatureClearSignature
 * @details Clears the specified index signature.
 * @param[in]  frDoc The input document.
 * @param[in]  nIndex The index of the signature.
 * @return   TRUE for success, otherwise failure.
 * @note If the current user is not the issuer of the certificate, it can't be clear.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_BOOL, FRCustomSignatureClearSignature, (FR_Document frDoc,  FS_INT32 nIndex))

/**
 * @brief FRCustomSignatureFoxitSignInScope
 * @details Check dictionary of sign in scope.
 * @param[in]  frDoc The input document.
 * @param[in]  pAnnotDict The sign dictionary.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Current function has been deprecated, it not be implemented.
 */
INTERFACE(FS_BOOL, FRCustomSignatureFoxitSignInScope, (FR_Document frDoc,  FPD_Object pAnnotDict))

/**
 * @brief FRCustomSignatureFoixtCreateSignatureF
 * @details The dictionary object of the signature field.
 * @param[in]  frDoc The input document.
 * @param[in]  bSetSignS If set sign.
 * @return   FPD_Object      The dictionary object of the signature field.
 * @note It used for SetPosition to set position of the signature.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FRCustomSignatureSetPosition.
 */
INTERFACE(FPD_Object, FRCustomSignatureFoixtCreateSignatureF, (FR_Document frDoc,  FS_BOOL bSetSignS))

/**
 * @brief FRCustomSignatureSetPosition
 * @details The dictionary object of the signature field.
 * @param[in]  pageViewer The input document.
 * @param[in]  objDict The sign dictionary.
 * @param[in]  rcSig The sign rect.
 * @return   FPD_Object      The dictionary object of the signature field.
 * @note It used for SetPosition to set position of the signature.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FRCustomSignatureSetPosition.
 */
INTERFACE(void, FRCustomSignatureSetPosition, (FR_PageView pageViewer,  FPD_Object objDict,  const FS_FloatRect rcSig))

/**
 * @brief FRCustomSignatureGenerateSignInfo2
 * @details Signs a PDF document with the <a>FR_SignatureInfo</a> and <a>FR_SignaturePosInfo</a>. You have to register the signature
	* handler by <a>FRCustomSignatureRegisterSignatureHandler</a>to sign the data, otherwise the data will be signed with the default standard method.
 * @param[in]  pSgInfo To fill the signature info.
 * @param[in]  pSgPosInfo To fill the signature position info.
 * @param[in]  bopenSignDoc If need open the doc after sign.
 * @param[in]  pExinfo To fill the signature info.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
 */
INTERFACE(FS_BOOL, FRCustomSignatureGenerateSignInfo2, (FR_SignatureInfo* pSgInfo,  FR_SignaturePosInfo* pSgPosInfo,  FS_BOOLEAN bopenSignDoc,  FR_SignatureExtendInfo* pExinfo))

/**
 * @brief FRCustomSignaturePrepareSign
 * @details It used to backup original file.
 * @param[in]  doc The input document that need to sign.
 * @return   void
 * @note It has to be called before multiple signatures are created consecutively.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @see FRCustomSignaturePrepareSign.
 */
INTERFACE(void, FRCustomSignaturePrepareSign, (FR_Document doc))

NumOfSelector(FRCustomSignature)
ENDENUM

//----------_V9----------
//----------_V10----------
//----------_V11----------
//----------_V12----------
//----------_V13----------
//*****************************
/* ReaderInterform HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_InterForm, FRReaderInterformGetInterForm, (FR_ReaderInterform frInerForm))

/**
 * @brief FRReaderInterformLoadImageFromFile
 * @details Create CPDF_Stream of image to document.
 * @param[in]  frInerForm The input FR_ReaderInterform.
 * @param[in]  sFile The image file path.
 * @param[in]  nWidth The image width.
 * @param[in]  nHeight The image height.
 * @return   FPD_Object
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FRReaderInterformGetInterForm.
	
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_Object, FRReaderInterformLoadImageFromFile, (FR_ReaderInterform frInerForm,  const FS_WideString sFile,  FS_INT32 nWidth,  FS_INT32 nHeight))

/**
 * @brief FRReaderInterformResetFieldAppearance
 * @details Reset field appearance with format value.
 * @param[in]  frInerForm The input FR_ReaderInterform.
 * @param[in]  pFormField The input form field.
 * @param[in]  sValue The field value.
 * @param[in]  bValueChanged If need to change the field value.
 * @param[in]  bNeedFormat If need format field value.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FRReaderInterformResetFieldAppearance.
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRReaderInterformResetFieldAppearance, (FR_ReaderInterform frInerForm,  FPD_FormField pFormField,  FS_LPCWSTR sValue,  FS_BOOL bValueChanged,  FS_BOOL bNeedFormat))

/**
 * @brief FRReaderInterformOnCalculate
 * @details Calculate form field.
 * @param[in]  frInerForm The input FR_ReaderInterform.
 * @param[in]  pFormField The input form field.
 * @param[in]  nPage The pageindex.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FRReaderInterformOnCalculate.
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRReaderInterformOnCalculate, (FR_ReaderInterform frInerForm,  FPD_FormField pFormField,  FS_INT32 nPage))

/**
 * @brief FRReaderInterformOnCalculate2
 * @details Calculate form field in page index.
 * @param[in]  frInerForm The input FR_ReaderInterform.
 * @param[in]  nPage The pageindex.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FRReaderInterformOnCalculate2.
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRReaderInterformOnCalculate2, (FR_ReaderInterform frInerForm,  FS_INT32 nPage))

/**
 * @brief FRReaderInterformIsFormFieldInPage
 * @details Check if the form field in input page.
 * @param[in]  frInerForm The input FR_ReaderInterform.
 * @param[in]  pFormField The input form field.
 * @param[in]  nPage The pageindex.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FRReaderInterformIsFormFieldInPage.
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRReaderInterformIsFormFieldInPage, (FR_ReaderInterform frInerForm,  FPD_FormField pFormField,  FS_INT32 nPage))

/**
 * @brief FRReaderInterformGetBFinterform
 * @details Get FR_CBFInterForm from frInerForm.
 * @param[in]  frInerForm The input FR_ReaderInterform.
 * @param[in]  nPage The pageindex.
 * @return   FR_CBFInterForm
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @see FRReaderInterformGetBFinterform.
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_CBFInterForm, FRReaderInterformGetBFinterform, (FR_ReaderInterform frInerForm))

/**
 * @brief FRReaderInterformIsHighLight
 * @details Check if the form is hightlight.
 * @param[in]  frInerForm The input FR_ReaderInterform.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRReaderInterformIsHighLight, (FR_ReaderInterform frInerForm))

/**
 * @brief FRReaderInterformGetBarCodeRenderBitmap
 * @details Get the bitmap of bar code render.
 * @param[in]  frInerForm The input FR_ReaderInterform.
 * @param[in]  pControl The input FPD_FormControl.
 * @param[out]  mtTmp Get the matrix of render bar code.
 * @return   FS_DIBitmap
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_DIBitmap, FRReaderInterformGetBarCodeRenderBitmap, (FR_ReaderInterform frInerForm,  FPD_FormControl pControl,  FS_AffineMatrix* mtTmp))

/**
 * @brief FRReaderInterformDeleteInterForm
 * @details Delete inter form.
 * @param[in]  frInerForm The input FR_ReaderInterform.
 * @param[in]  pRDDoc The input FR_Document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRReaderInterformDeleteInterForm, (FR_ReaderInterform frInerForm,  FR_Document pRDDoc))

NumOfSelector(FRReaderInterform)
ENDENUM

//----------_V14----------
//*****************************
/* UndoItemCreateWidget HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_UndoCreateWidget, FRUndoItemCreateWidgetCreateUndoWidget, (FR_Document frDoc,  FS_INT32 nPageIndex,  FPD_Object pFieldDict,  FPD_Object pAnnotDict,  const FS_INT32 nTabOrder))

INTERFACE(void, FRUndoItemCreateWidgetUndo, (FR_UndoCreateWidget undoWidget))

INTERFACE(void, FRUndoItemCreateWidgetRedo, (FR_UndoCreateWidget undoWidget))

INTERFACE(void, FRUndoItemCreateWidgetGetDescr, (FR_UndoCreateWidget undoWidget,  FS_WideString* outDesc))

NumOfSelector(FRUndoItemCreateWidget)
ENDENUM

//*****************************
/* CRSAStamp HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_CRSAStamp, FRCRSAStampNew, ())

INTERFACE(void, FRCRSAStampDestroy, (FR_CRSAStamp rStamp))

INTERFACE(FS_INT32, FRCRSAStampGetLeftValue, (FR_CRSAStamp rStamp))

INTERFACE(FS_INT32, FRCRSAStampGetTopValue, (FR_CRSAStamp rStamp))

INTERFACE(FS_INT32, FRCRSAStampGetDefaultCropWValue, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampSetDefaultCropWValue, (FR_CRSAStamp rStamp,  FS_INT32 width))

INTERFACE(FS_INT32, FRCRSAStampGetDefaultCropHValue, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampSetDefaultCropHValue, (FR_CRSAStamp rStamp,  FS_INT32 height))

INTERFACE(FS_INT32, FRCRSAStampGetDefaultWValue, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampSetDefaultWValue, (FR_CRSAStamp rStamp,  FS_INT32 width))

INTERFACE(FS_INT32, FRCRSAStampGetDefaultHValue, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampSetDefaultHValue, (FR_CRSAStamp rStamp,  FS_INT32 height))

INTERFACE(FS_FLOAT, FRCRSAStampGetWidthValue, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampSetWidthValue, (FR_CRSAStamp rStamp,  FS_FLOAT width))

INTERFACE(FS_FLOAT, FRCRSAStampGetHeightValue, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampSetHeightValue, (FR_CRSAStamp rStamp,  FS_FLOAT height))

INTERFACE(FS_BOOL, FRCRSAStampIsPath, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampSetPath, (FR_CRSAStamp rStamp,  FS_BOOL bPath))

INTERFACE(FS_DIBitmap, FRCRSAStampGetDIBitmap, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampSetDIBitmap, (FR_CRSAStamp rStamp,  FS_DIBitmap pDIB))

INTERFACE(FS_BOOL, FRCRSAStampIsPDFSignStamp, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampGetPDFPath, (FR_CRSAStamp rStamp,  FS_WideString* wsPath))

INTERFACE(FS_BOOL, FRCRSAStampIsDynamic, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampGetEncode, (FR_CRSAStamp rStamp,  FS_ByteString* bsEncode))

INTERFACE(FS_INT32, FRCRSAStampGetStampType, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampSetPageIdx, (FR_CRSAStamp rStamp,  FS_INT32 nPage))

INTERFACE(FS_INT32, FRCRSAStampGetPageIdx, (FR_CRSAStamp rStamp))

INTERFACE(FS_BOOL, FRCRSAStampPreViewArtBoxFile, (FR_CRSAStamp rStamp,  FPD_Document pPDFDoc,  FS_INT32 nIndex,  FS_DIBitmap pDIBitmap))

INTERFACE(void, FRCRSAStampGetStampName, (FR_CRSAStamp rStamp,  FS_WideString* wsName))

INTERFACE(FS_BOOL, FRCRSAStampIsFavorite, (FR_CRSAStamp rStamp))

INTERFACE(FS_BOOL, FRCRSAStampSetPagePieceInfo, (FR_CRSAStamp rStamp,  FR_PIECE_INFO_KEY nType))

INTERFACE(FS_BOOL, FRCRSAStampSetPagePieceInfoByDoc, (FR_CRSAStamp rStamp,  FPD_Document pPDFDoc,  FR_PIECE_INFO_KEY nType))

INTERFACE(FS_BOOL, FRCRSAStampGetIsRotate, (FR_CRSAStamp rStamp))

INTERFACE(FS_INT32, FRCRSAStampRemovePage, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampCopy, (FR_CRSAStamp dStamp,  FR_CRSAStamp rStamp))

INTERFACE(FS_INT32, FRCRSAStampGetPageFromName, (FPD_Document pPDFDoc,  const FS_WideString wStrPageName))

INTERFACE(void, FRCRSAStampSetStampName, (FR_CRSAStamp rStamp,  const FS_WideString& cwStampName))

INTERFACE(void, FRCRSAStampSetPDFPath, (FR_CRSAStamp rStamp,  const FS_WideString& cwPDFPath))

INTERFACE(void, FRCRSAStampSetAppCloseDelete, (FR_CRSAStamp rStamp,  FS_BOOL bDelete))

INTERFACE(void, FRCRSAStampSetType, (FR_CRSAStamp rStamp,  const FS_ByteString& byteType))

INTERFACE(void, FRCRSAStampSetEncode, (FR_CRSAStamp rStamp,  const FS_LPCSTR& strEncode))

INTERFACE(void, FRCRSAStampSetSignListIdx, (FR_CRSAStamp rStamp,  FS_INT32 nIdx))

INTERFACE(FS_BOOL, FRCRSAStampGetPDFStamp, (FR_CRSAStamp rStamp))

INTERFACE(FS_BOOL, FRCRSAStampSaveStampToPage, (FR_CRSAStamp pStamp))

INTERFACE(FPD_Object, FRCRSAStampGetSampInfoDic, (FPD_Object pPageDic,  FPD_Document pPDFDoc,  FS_BOOL bAdd))

INTERFACE(void, FRCRSAStampAddPageName, (FPD_Document pPDFDoc,  FS_INT32 nPageIdx,  FS_WideString* strPageName,  FS_BOOL bPageNamePrefix))

INTERFACE(void, FRCRSAStampSetLeftValue, (FR_CRSAStamp rStamp,  FS_FLOAT left))

INTERFACE(void, FRCRSAStampSetTopValue, (FR_CRSAStamp rStamp,  FS_FLOAT top))

INTERFACE(void, FRCRSAStampSetDynamic, (FR_CRSAStamp rStamp,  FS_BOOL bDynamic))

INTERFACE(void, FRCRSAStampSetFavorite, (FR_CRSAStamp rStamp,  FS_BOOL bFav))

INTERFACE(void, FRCRSAStampGetType, (FR_CRSAStamp rStamp,  FS_ByteString* type))

INTERFACE(void, FRCRSAStampSetIsRotate, (FR_CRSAStamp rStamp,  FS_BOOL bRotate))

INTERFACE(FRRS_PASSWORD, FRCRSAStampCheckPDFPermission, (FR_CRSAStamp rStamp,  FS_WideString cwFileName,  FS_WideString* wsRemoveSecPath,  FPD_Parser parser,  FS_BOOLEAN bPretect))

INTERFACE(FS_BOOL, FRCRSAStampFSFadeOutImageBackground, (const FS_DIBitmap pDib,  FS_DIBitmap* pDib_with_mask,  FREnhancementAlogrithms enhAlgo,  FS_LPVOID enhParams,  FRThreshAlogrithm threshAlgo,  FS_LPVOID threshParams))

INTERFACE(void, FRCRSAStampSetTip, (FR_CRSAStamp rStamp,  const FS_WideString cwTip))

INTERFACE(void, FRCRSAStampSetTemplateName, (FR_CRSAStamp rStamp,  const FS_WideString csTemplateName))

INTERFACE(void, FRCRSAStampSetThumbNail, (FR_CRSAStamp rStamp,  const FS_WideString cwThumbnail))

INTERFACE(void, FRCRSAStampSetCanParser, (FR_CRSAStamp rStamp,  FS_BOOL bCanParser))

INTERFACE(void, FRCRSAStampSetImage, (FR_CRSAStamp rStamp,  FS_BOOL bImage))

INTERFACE(void, FRCRSAStampSetOpacity, (FR_CRSAStamp rStamp,  FS_INT32 nOpacity))

INTERFACE(void, FRCRSAStampGetSignFilePwd, (const FS_WideString wStrSignPassword,  FS_WideStringArray* fileArray,  FS_ByteStringArray* pwdArray))

INTERFACE(void, FRCRSAStampGetStampFormPage, (FR_CRSAStamp rStamp,  FPD_Page pPage))

INTERFACE(void, FRCRSAStampSaveStampToPage2, (FPD_Document pPDFDoc,  FR_CRSAStamp pRStamp))

INTERFACE(FS_INT32, FRCRSAStampGetSignListIdx, (FR_CRSAStamp rStamp))

INTERFACE(void, FRCRSAStampSetStampGuid, (FR_CRSAStamp rStamp,  const FS_WideString cwStampGuid))

INTERFACE(void, FRCRSAStampGetStampGuid, (FR_CRSAStamp rStamp,  FS_WideString* wsGuid))

NumOfSelector(FRCRSAStamp)
ENDENUM

//*****************************
/* MarkupAnnot HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_MarkupAnnot, FRMarkupAnnotCreate, (FPD_Annot pAnnot,  FR_PageView pPageView))

INTERFACE(void, FRMarkupAnnotDestroy, (FR_MarkupAnnot annot))

INTERFACE(FS_BOOL, FRMarkupAnnotIsGroup, (FR_MarkupAnnot annot))

INTERFACE(FS_BOOL, FRMarkupAnnotIsHeader, (FR_MarkupAnnot annot))

INTERFACE(FR_MarkupPopup, FRMarkupAnnotGetPopup, (FR_MarkupAnnot annot,  FS_BOOL bCreate))

INTERFACE(void, FRMarkupAnnotResetAppearance, (FR_MarkupAnnot annot))

INTERFACE(void, FRMarkupAnnotSetModifiedDateTime, (FR_MarkupAnnot annot,  FS_ReaderDateTime dt))

INTERFACE(FS_BOOL, FRMarkupAnnotGetModifiedDateTime, (FR_MarkupAnnot annot,  FS_ReaderDateTime* dt))

INTERFACE(FS_FloatPoint, FRMarkupAnnotGetHotPoint, (FR_MarkupAnnot annot))

INTERFACE(FS_BOOL, FRMarkupAnnotGetColor, (FR_MarkupAnnot annot,  FS_COLORREF* color))

INTERFACE(void, FRMarkupAnnotMovedOutPage, (FR_MarkupAnnot annot,  FR_Page pSrcPage,  FR_Page pDestPage))

NumOfSelector(FRMarkupAnnot)
ENDENUM

//*****************************
/* MarkupPopup HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FRMarkupPopupUpdateDataTime, (FR_MarkupPopup popup,  FR_PageView pPageView))

INTERFACE(void, FRMarkupPopupSetNoteAnchor, (FR_MarkupPopup popup,  FS_FloatPoint cpPoint,  FR_PageView pPageView))

INTERFACE(void, FRMarkupPopupShowRope, (FR_MarkupPopup popup,  FS_BOOL bShow,  FR_PageView pPageView))

INTERFACE(FS_BOOL, FRMarkupPopupIsNoteVisible, (FR_MarkupPopup popup,  FR_PageView pPageView))

INTERFACE(void, FRMarkupPopupUpdateNote, (FR_MarkupPopup popup,  FR_PageView pPageView,  FS_BOOL bCreateIfPageInvisible))

INTERFACE(void, FRMarkupPopupResetNotePosition, (FR_MarkupPopup popup,  FR_PageView pPageView))

INTERFACE(FR_Annot, FRMarkupPopupGetPopupAnnot, (FR_MarkupPopup popup))

INTERFACE(FS_FloatRect, FRMarkupPopupGetRect, (FR_MarkupPopup popup))

INTERFACE(FS_BOOL, FRMarkupPopupSetState, (FR_MarkupPopup popup,  FS_BOOL bOpen))

INTERFACE(void, FRMarkupPopupShowNote, (FR_MarkupPopup popup,  FS_BOOL bShow,  FR_PageView pageView))

INTERFACE(void, FRMarkupPopupSetNoteFocus, (FR_MarkupPopup popup,  FS_BOOL bSet,  FR_PageView pageView))

INTERFACE(void, FRMarkupPopupAddReply, (FR_MarkupPopup popup,  FR_PageView pageView))

NumOfSelector(FRMarkupPopup)
ENDENUM

//*****************************
/* MarkupPanel HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRMarkupPanelGetMarkupPanel
 * @details When add,delete,change markup annot, you can use FR_MarkupPanel to refresh comments panel.
 * @return   FR_MarkupPanel	   The object of comments panel, it show all markupannots in page.
 * @note 
 * @see FRMarkupPanelGetMarkupPanel
 */
INTERFACE(FR_MarkupPanel, FRMarkupPanelGetMarkupPanel, ())

/**
 * @brief FRMarkupPanelRefreshAnnot
 * @details When change markup annot, you need to refresh annots in comments panel.
 * @param[in]  panel The <a>FR_MarkupPanel</a> object.
 * @param[in]  pAnnot The annot need to refresh.
 * @param[in]  bRedrawPanel Whether to redraw panel.
 * @return   FS_BOOL	            TRUE for refresh annot success, otherwise failure.
 * @note 
 * @see FRMarkupPanelRefreshAnnot
 */
INTERFACE(FS_BOOL, FRMarkupPanelRefreshAnnot, (FR_MarkupPanel panel,  FR_Annot pAnnot,  FS_BOOL bRedrawPanel))

/**
 * @brief FRMarkupPanelReloadAnnots
 * @details When delete markup annot, you need to reload annots in comments panel.
 * @param[in]  panel The <a>FR_MarkupPanel</a> object.
 * @param[in]  pDoc The current document.
 * @return   FS_BOOL	            TRUE for reload annot success, otherwise failure.
 * @note 
 * @see FRMarkupPanelReloadAnnots
 */
INTERFACE(FS_BOOL, FRMarkupPanelReloadAnnots, (FR_MarkupPanel panel,  FR_Document pDoc))

/**
 * @brief FRMarkupPanelAddAnnot
 * @details When create markup annot, you need to annot annot to comments panel.
 * @param[in]  panel The <a>FR_MarkupPanel</a> object.
 * @param[in]  pDoc The current document.
 * @param[in]  bRedrawPanel Whether to redraw panel.
 * @param[in]  bShow Whether show the annot.
 * @return   FS_BOOL	            TRUE for add annot success, otherwise failure.
 * @note 
 * @see FRMarkupPanelAddAnnot
 */
INTERFACE(FS_BOOL, FRMarkupPanelAddAnnot, (FR_MarkupPanel panel,  FR_Annot pAnnot,  FS_BOOL bRedrawPanel,  FS_BOOL bShow))

/**
 * @brief FRMarkupPanelSetFocus
 * @details When create markup annot, you need to annot annot to comments panel.
 * @param[in]  panel The <a>FR_MarkupPanel</a> object.
 * @param[in]  pAnnot The annot need to be focus.
 * @return   FS_BOOL	            TRUE for set annot focus success, otherwise failure.
 * @note 
 * @see FRMarkupPanelSetFocus
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRMarkupPanelSetFocus, (FR_MarkupPanel panel,  FR_Annot pAnnot))

/**
 * @brief FRMarkupPanelUpdatePropertyBox
 * @details Update property box.
 * @return   void
 * @note 
 * @see FRMarkupPanelUpdatePropertyBox
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRMarkupPanelUpdatePropertyBox, ())

/**
 * @brief FRMarkupPanelAddToCreateList
 * @details Add annot to create list.
 * @param[in]  pAnnot The current annot.
 * @return   void
 * @note 
 * @see FRMarkupPanelAddToCreateList
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRMarkupPanelAddToCreateList, (FR_Annot pAnnot))

/**
 * @brief FRMarkupPanelHideHint
 * @details Hide hint of annot.
 * @return   void
 * @note 
 * @see FRMarkupPanelHideHint
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRMarkupPanelHideHint, ())

/**
 * @brief FRMarkupPanelRemoveAnnot
 * @details Remove annot from comments panel.
 * @param[in]  panel The <a>FR_MarkupPanel</a> object.
 * @param[in]  pAnnot The annot need to remove.
 * @param[in]  bRedrawPanel Whether need to redraw comments panel.
 * @return   FS_BOOL	        TRUE for set annot focus success, otherwise failure.
 * @note 
 * @see FRMarkupPanelRemoveAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRMarkupPanelRemoveAnnot, (FR_MarkupPanel panel,  FR_Annot pAnnot,  FS_BOOL bRedrawPanel))

/**
 * @brief FRMarkupPanelShowAnnot
 * @details Show annot from comments panel.
 * @param[in]  panel The <a>FR_MarkupPanel</a> object.
 * @param[in]  pAnnot The annot need to remove.
 * @param[in]  bShow If show the annot.
 * @param[in]  bRedrawPanel Whether need to redraw comments panel.
 * @return   FS_BOOL	        TRUE for show the annot.
 * @note 
 * @see FRMarkupPanelShowAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRMarkupPanelShowAnnot, (FR_MarkupPanel panel,  FR_Annot pAnnot,  FS_BOOL bShow,  FS_BOOL bRedrawPanel))

NumOfSelector(FRMarkupPanel)
ENDENUM

//*****************************
/* CRSASStampAnnot HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_CRSASStampAnnot, FRCRSASStampAnnotNew, (FPD_Annot pAnnot,  FR_Page pPage))

INTERFACE(void, FRCRSASStampAnnotDestroy, (FR_CRSASStampAnnot stampAnnot))

INTERFACE(void, FRCRSASStampAnnotSetStamp, (FR_CRSASStampAnnot stampAnnot,  FR_CRSAStamp srcStamp))

INTERFACE(void, FRCRSASStampAnnotAfterMovePages, (FR_CRSASStampAnnot stampAnnot,  FS_INT32 nSrcRotate,  FS_INT32 nDesRotate))

INTERFACE(void, FRCRSASStampAnnotResetAppearance, (FR_CRSASStampAnnot stampAnnot))

INTERFACE(void, FRCRSASStampAnnotSetColor, (FR_CRSASStampAnnot stampAnnot,  FS_COLORREF color,  FS_BOOL bTransparent))

INTERFACE(void, FRCRSASStampAnnotSetOpacity, (FR_CRSASStampAnnot stampAnnot,  FS_INT32 nOpacity))

INTERFACE(void, FRCRSASStampAnnotSetCreationDateTime, (FR_CRSASStampAnnot stampAnnot,  FS_ReaderDateTime dt))

INTERFACE(FS_BOOL, FRCRSASStampAnnotGetModifiedDateTime, (FR_CRSASStampAnnot stampAnnot,  FS_ReaderDateTime* dt))

INTERFACE(FR_MarkupPopup, FRCRSASStampAnnotGetPopup, (FR_CRSASStampAnnot stampAnnot,  FS_BOOL bCreate))

INTERFACE(FS_FloatPoint, FRCRSASStampAnnotGetHotPoint, (FR_CRSASStampAnnot stampAnnot))

INTERFACE(void, FRCRSASStampAnnotGetType, (FR_CRSASStampAnnot stampAnnot,  FS_ByteString* bsType))

INTERFACE(FS_BOOL, FRCRSASStampAnnotIsGroup, (FR_CRSASStampAnnot stampAnnot))

INTERFACE(FS_BOOL, FRCRSASStampAnnotIsHeader, (FR_CRSASStampAnnot stampAnnot))

INTERFACE(void, FRCRSASStampAnnotSetModifiedDateTime, (FR_CRSASStampAnnot stampAnnot,  FS_ReaderDateTime  dt))

INTERFACE(FS_BOOL, FRCRSASStampAnnotGetColor, (FR_CRSASStampAnnot stampAnnot,  FS_COLORREF* color))

INTERFACE(FR_Page, FRCRSASStampAnnotGetReaderPage, (FR_CRSASStampAnnot stampAnnot))

NumOfSelector(FRCRSASStampAnnot)
ENDENUM

//*****************************
/* EncryptPermisson HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_EncryptPermisson, FREncryptPermissonCreateEncryptPermisson, ())

INTERFACE(FS_DWORD, FREncryptPermissonSetEncryptPermisson, (FR_EncryptPermisson permission,  const FR_ENPermission enpermisson))

INTERFACE(void, FREncryptPermissonGetEncryptPermisson, (FR_EncryptPermisson permission,  const FS_DWORD &dwPermisson,  FR_ENPermission& enpermisson))

INTERFACE(FS_BOOL, FREncryptPermissonGetPropertyPermisson, (FR_EncryptPermisson permission,  const FS_DWORD& dwPermisson,  const FRPROPERTITY_PERMISSON properisson))

INTERFACE(FS_DWORD, FREncryptPermissonGetAllPermission, (FR_EncryptPermisson permission))

INTERFACE(void, FREncryptPermissonDeleteEncryptPermission, (FR_EncryptPermisson permission))

NumOfSelector(FREncryptPermisson)
ENDENUM

//*****************************
/* CSGCertFileManage HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_CSGCertFileManage, FRCSGCertFileManageCreateCertFileManage, ())

INTERFACE(void, FRCSGCertFileManageDestroy, (FR_CSGCertFileManage filemanage))

INTERFACE(void, FRCSGCertFileManageGetCertFileStorePath, (FR_CSGCertFileManage filemanage,  FS_WideString* filePath))

INTERFACE(FS_BOOL, FRCSGCertFileManageNewCertData, (FR_CSGCertFileManage filemanage,  FS_WideString ws1,  FS_WideString ws2,  FS_LPVOID store))

INTERFACE(FS_LPVOID, FRCSGCertFileManageLoadStore, (FR_CSGCertFileManage filemanage))

INTERFACE(FS_BOOL, FRCSGCertFileManageGetPathAndPassword, (FR_CSGCertFileManage filemanage,  FS_LPVOID pCertContext,  FS_WideString& cwFilePath,  FS_WideString& cwPassWord))

INTERFACE(FS_BOOL, FRCSGCertFileManageUpdateFile, (FR_CSGCertFileManage filemanage,  FS_BOOL bReloadCertFile))

INTERFACE(void, FRCSGCertFileManageBase64ToString, (FR_CSGCertFileManage filemanage,  FS_WideString str,  FS_WideString* outBaseStr))

INTERFACE(void, FRCSGCertFileManageStringToBase64, (FR_CSGCertFileManage filemanage,  FS_WideString str,  FS_WideString* outBaseStr))

INTERFACE(FS_BOOL, FRCSGCertFileManageReloadAllFile, (FR_CSGCertFileManage filemanage,  FS_LPVOID hStore,  const FS_PtrArray& datas))

NumOfSelector(FRCSGCertFileManage)
ENDENUM

//*****************************
/* CSG HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_CSGCreateCert, FRCSGCreate, (FR_SGDataStruct pData))

INTERFACE(void, FRCSGDestroy, (FR_CSGCreateCert cert,  FR_SGDataStruct pData))

INTERFACE(FS_LPVOID, FRCSGCreateCert, (FR_CSGCreateCert cert))

INTERFACE(void, FRCSGGetTmpName, (FR_CSGCreateCert cert,  FS_ByteString& csName))

INTERFACE(FS_LPVOID, FRCSGOpenPFXStore, (FR_CSGCreateCert cert))

INTERFACE(FS_LPVOID, FRCSGCreateOpenSSLCert, (FR_CSGCreateCert cert))

NumOfSelector(FRCSG)
ENDENUM

//*****************************
/* Page HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPageGetDocument
 * @details Gets the <a>FR_Document</a> for the document currently displayed in specified pageview.
 * @param[in]  page The page whose <a>FR_Document</a> is obtained. It gets form FRDocGetPage.
 * @return   The <a>FR_Document</a> for <param>page</param>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRDocGetDocument
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Document, FRPageGetDocument, (FR_Page page))

/**
 * @brief FRPageGetPage
 * @details Gets a <a>FPD_Page</a> currently displayed in the specified page. This do not new a
	* <a>FPD_Page</a> object. Do not use this result across methods that might change the current page.
	* To obtain a value that can be used across such calls, use <a>FPD_PageNew</a> instead.
 * @param[in]  page The page whose <a>FPD_Page</a> is obtained.
 * @return   <a>FPD_Page</a> displayed in <param>page</param>,or <a>NULL</a> if no valid <a>FPD_Page</a>
	* associated with <param>page</param>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRDocGetPage
	
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_Page, FRPageGetPage, (FR_Page page))

/**
 * @brief FRPageParsePage
 * @details Parses the specified page.
 * @param[in]  page The page to Parses.
 * @return   FS_BOOL 	TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRDocParsePage
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPageParsePage, (FR_Page page))

/**
 * @brief FRPageGetDynPDFPage
 * @details If it is XFA document, it will get a <a>FPD_Page</a> currently displayed in the specified page.
 * @param[in]  page The page whose <a>FPD_Page</a> is obtained.
 * @return   <a>FPD_Page</a> displayed in <param>page</param>, or <a>NULL</a> if no valid <a>FPD_Page</a>
	* associated with <param>page</param>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRDocGetDynPDFPage
	
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_Page, FRPageGetDynPDFPage, (FR_Page page))

/**
 * @brief FRPageGetPageIndex
 * @details Gets the current page index.
 * @param[in]  page The page whose current page number is obtained.
 * @return   FS_INT32 The current page number, or <a>NULL</a> if <param>page</param> is invalid. The first page number of a document
	* is page 0.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageGetPageIndex
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPageGetPageIndex, (FR_Page page))

/**
 * @brief FRPageIsPDFPageLoaded
 * @details Check whether the page PDF is loaded.
 * @param[in]  page The page to determine whether the page PDF is loaded.
 * @return   FS_BOOL   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageIsPDFPageLoaded
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPageIsPDFPageLoaded, (FR_Page page))

/**
 * @brief FRPageAddAnnot
 * @details Adds the annotation to the page.
 * @param[in]  page The input page object.
 * @param[in]  lpSubType The input annotation subtype you want to add. Like "Line","Circle".
 * @param[in]  rect The input annotation rect you want to add.
 * @return   FR_Annot    The UI layer annotation object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageAddAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageAddAnnot, (FR_Page page,  FS_LPCSTR lpSubType,  const FS_FloatRect rect))

/**
 * @brief FRPageAddAnnot2
 * @details Adds the annotation to the page.
 * @param[in]  page The input page object.
 * @param[in]  annotDict The input annotation dictionary you want to add.
 * @param[in]  nIndex The index where you want to add the annotation. Sets it -1 as default.
 * @return   FR_Annot         The UI layer annotation object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageAddAnnot2
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageAddAnnot2, (FR_Page page,  FPD_Object annotDict,  FS_INT32 nIndex))

/**
 * @brief FRPageAddAnnot3
 * @details Adds the annotation to the page.
 * @param[in]  page The input page object.
 * @param[in]  annot The input FPD_Annot object.
 * @param[in]  nIndex The index where you want to add the annotation. Sets it -1 as default.
 * @return   FR_Annot         The UI layer annotation object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageAddAnnot3
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageAddAnnot3, (FR_Page page,  FPD_Annot annot,  FS_INT32 nIndex))

/**
 * @brief FRPageAddDynXFAPDFAnnot
 * @details Adds the dynamic XFA PDF annotation to the page.
 * @param[in]  page The input page object.
 * @param[in]  annotDict The input annotation dictionary you want to add.
 * @return   FR_Annot         The UI layer annotation object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageAddDynXFAPDFAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageAddDynXFAPDFAnnot, (FR_Page page,  FPD_Object annotDict))

/**
 * @brief FRPageDeleteAnnot
 * @details Deletes the specified annotation on the page.
 * @param[in]  page The input page object.
 * @param[in]  frAnnot The input annotation to be deleted.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageDeleteAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageDeleteAnnot, (FR_Page page,  FR_Annot frAnnot))

/**
 * @brief FRPageMoveAnnot
 * @details Move the specified annotation.
 * @param[in]  page The input page object.
 * @param[in]  pageDest The target page of moving annotation.
 * @param[in]  frAnnot The input annotation to be moved.
 * @param[in]  index The annot index.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageMoveAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageMoveAnnot, (FR_Page page,  FR_Page pageDest,  FR_Annot frAnnot,  FS_INT32 index))

/**
 * @brief FRPageCountAnnots
 * @details Gets the number of annotations associated with specified page.
 * @param[in]  page The page whose annotation count is obtained.
 * @return   FS_INT32         The number of annotations associated with <param>page</param>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageCountAnnots
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPageCountAnnots, (FR_Page page))

/**
 * @brief FRPageGetAnnot
 * @details Gets the annotation by index.
 * @param[in]  page The input page object.
 * @param[in]  index The specified index of the annotations.
 * @return   FR_Annot The specified annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageGetAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageGetAnnot, (FR_Page page,  FS_INT32 index))

/**
 * @brief FRPageGetAnnotByDict
 * @details Gets the annotation by dictionary.
 * @param[in]  page The input page object.
 * @param[in]  pDict The specified dictionary of the annotations.
 * @return   FR_Annot     The specified annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageGetAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageGetAnnotByDict, (FR_Page page,  FPD_Object pDict))

/**
 * @brief FRPageIsValidAnnot
 * @details Checks whether the point is valid or not.
 * @param[in]  page The input page object.
 * @param[in]  annot The input FR_Annot object.
 * @return   TRUE if the point is valid.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageIsValidAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPageIsValidAnnot, (FR_Page page,  FS_LPVOID annot))

/**
 * @brief FRPageGetAnnotDataList
 * @details Get annotation data list.
 * @param[in]  page The input page object.
 * @return   FPD_AnnotList	a annotation data list.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageGetAnnotDataList
	
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_AnnotList, FRPageGetAnnotDataList, (FR_Page page))

/**
 * @brief FRPageGetAnnotList
 * @details Get annotation list.
 * @param[in]  page The input page object.
 * @param[out]  outObjArray The output annotation list.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageGetAnnotList
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageGetAnnotList, (FR_Page page,  FS_PtrArray* outObjArray))

/**
 * @brief FRPageGetFocusAnnot
 * @details Gets the focus annotation.
 * @param[in]  page The input page object.
 * @return   FR_Annot     The focus annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageGetFocusAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageGetFocusAnnot, (FR_Page page))

/**
 * @brief FRPageSetFocusAnnot
 * @details Sets the focus annotation.
 * @param[in]  page The input page object.
 * @param[in]  pFocusAnnot The input annotation.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageSetFocusAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageSetFocusAnnot, (FR_Page page,  FR_Annot pFocusAnnot))

/**
 * @brief FRPageGetPageFirstAnnot
 * @details Gets the first annotation that matches the type in the page
 * @param[in]  frDoc The input document.
 * @param[in]  csType The input annotation subtype you want to get.
 * @return   FR_Annot     The specified annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageGetPageFirstAnnot
	
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageGetPageFirstAnnot, (FR_Page page,  FS_LPCSTR csType))

/**
 * @brief FRPageGetPageLastAnnot
 * @details Gets the last annotation that matches the type in the page
 * @param[in]  frDoc The input document.
 * @param[in]  csType The input annotation subtype you want to get.
 * @return   The specified annotation.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageGetPageLastAnnot, (FR_Page page,  FS_LPCSTR csType))

/**
 * @brief FRPageGetPagePriorAnnot
 * @details Gets the type matching annotation before the input annotation in the page
 * @param[in]  frDoc The input document.
 * @param[in]  pAnnot The input annotation.
 * @param[in]  csType The input annotation subtype you want to get.
 * @return   The specified annotation.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageGetPagePriorAnnot, (FR_Page page,  FR_Annot pAnnot,  FS_LPCSTR csType))

/**
 * @brief FRPageGetPageNextAnnot
 * @details Gets the type matching annotation after the input annotation in the page
 * @param[in]  frDoc The input document.
 * @param[in]  pAnnot The input annotation.
 * @param[in]  csType The input annotation subtype you want to get.
 * @return   The specified annotation.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageGetPageNextAnnot, (FR_Page page,  FR_Annot pAnnot,  FS_LPCSTR csType))

/**
 * @brief FRPageCountViews
 * @details Get the number of page views
 * @param[in]  page The input page object.
 * @return   the number of page views
 * @note 
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPageCountViews, (FR_Page page))

/**
 * @brief FRPageGetView
 * @details Gets the <a>FR_PageView</a> for specified page
 * @param[in]  page The page whose <a>FR_PageView</a> is obtained.
 * @param[in]  index The index of <a>FR_PageView</a>.
 * @return   The <a>FR_PageView</a> for <param>page</param>.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_PageView, FRPageGetView, (FR_Page page,  FS_INT32 index))

/**
 * @brief FRPageIsValidView
 * @details Checks whether the view is valid or not.
 * @param[in]  page The input page object.
 * @param[in]  view The input page view object.
 * @return   TRUE if the view is valid.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPageIsValidView, (FR_Page page,  FR_PageView view))

/**
 * @brief FRPageGetView2
 * @details Gets the <a>FR_PageView</a> for specified page of docView
 * @param[in]  page The input page object.
 * @param[in]  docView The input doc view object.
 * @return   The <a>FR_PageView</a> for <param>page</param> and <param>docView</param>.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_PageView, FRPageGetView2, (FR_Page page,  FR_DocView docView))

/**
 * @brief FRPageUpdateAllViews
 * @details Updates all views of page in the entered rect range
 * @param[in]  page The page whose <a>FPD_Page</a> needs to generate content.
 * @param[in]  view The input page view object.
 * @param[in]  rectarray 
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.1
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageUpdateAllViews, (FR_Page page,  FR_PageView view,  FS_FloatRectArray rectarray))

/**
 * @brief FRPageUpdateView
 * @details 
 * @param[in]  page The page whose <a>FPD_Page</a> needs to generate content.
 * @param[in]  view The input page view object.
 * @param[in]  rectarray The rect range to update
 * @return   Updates the view of page in the entered rect range.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageUpdateView, (FR_Page page,  FR_PageView view,  FS_FloatRectArray rectarray))

/**
 * @brief FRPageUpdateAllViews2
 * @details Updates all the pages where the annotation is shown.
 * @param[in]  page The input page object.
 * @param[in]  view The input page view object.
 * @param[in]  frAnnot The input annotation you want to update.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageUpdateAllViews2, (FR_Page page,  FR_PageView view,  FR_Annot frAnnot))

/**
 * @brief FRPageLockPage
 * @details lock page
 * @param[in]  page The input page object.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageLockPage, (FR_Page page))

/**
 * @brief FRPageUnLockPage
 * @details unlock page
 * @param[in]  page The input page object.
 * @return   
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageUnLockPage, (FR_Page page))

/**
 * @brief FRPageIsLocked
 * @details Get whether the page is locked or not
 * @param[in]  page The input page object.
 * @return   TRUE if the view is locked.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPageIsLocked, (FR_Page page))

/**
 * @brief FRPageIsParsed
 * @details Get whether the page is parsed or not
 * @param[in]  page The input page object.
 * @return   TRUE if the view is parsed.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRPageIsParsed, (FR_Page page))

/**
 * @brief FRPageGetPageTabOrder
 * @details Get the tab order of annotation.
 * @param[in]  page The input page object.
 * @param[in]  frAnnot The input annotation you want to get the tab order.
 * @return   the tab order of annotation.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRPageGetPageTabOrder, (FR_Page page,  FR_Annot frAnnot))

INTERFACE(FS_INT32, FRPageSetPageTabOrder, (FR_Page page,  FR_Annot frAnnot,  FS_INT32 iOrder))

INTERFACE(void, FRPageInsertWidgetTabOrder, (FR_Page page,  FR_Annot frAnnot,  FS_INT32 iOrder))

/**
 * @brief FRPageSetContentModification
 * @details Sets the modified page content.
 * @param[in]  page The page whose <a>FR_Page</a> content is modified.
 * @param[in]  modifiedContent An array to store the modified <a>FPD_Page</a>.
 * @return   void.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRPageSetContentModification, (FR_Page page,  FS_PtrArray modifiedContent))

INTERFACE(void, FRPageGenerateContent, (FR_Page page))

/**
 * @brief FRPageGetXFAPage
 * @details 
 * @param[in]  page The input page object.
 * @return   FPD_XFAPageView
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_XFAPageView, FRPageGetXFAPage, (FR_Page page))

/**
 * @brief FRPageGetAnnotByXFAWidget
 * @details return widget annot object.  If the type of opened document is Static XFA document, this function will return NULL.
 * @param[in]  page The input page object.
 * @param[in]  hWidget The XFA_HWIDGET object.
 * @return   FR_Annot
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_Annot, FRPageGetAnnotByXFAWidget, (FR_Page page,  PFPDXFA_HWIDGET hWidget))

INTERFACE(void, FRPageRefreshXFAPageView, (FR_Page page,  FR_Document doc,  FS_FloatRect rect,  FS_DWORD dwFlag))

INTERFACE(void, FRPageSetMergeTextFlag, (FR_Page page,  FS_BOOLEAN bMergeText))

INTERFACE(void, FRPageClearContentModification, (FR_Page page,  FS_PtrArray objects))

INTERFACE(FS_BOOLEAN, FRPageResetPageAnnots, (FR_Page page))

NumOfSelector(FRPage)
ENDENUM

//*****************************
/* IBAAnnotFiller HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_BAAnnotFiller, FRIBAAnnotFillerNew, (FRD_BAAnnotFillerCallbacks callbacks))

INTERFACE(void, FRIBAAnnotFillerDestroy, (FR_BAAnnotFiller handler))

NumOfSelector(FRIBAAnnotFiller)
ENDENUM

//*****************************
/* IBAAnnotDesigner HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_BAAnnotDesigner, FRIBAAnnotDesignerNew, (FRD_BAAnnotDesignerCallbacks callbacks))

INTERFACE(void, FRIBAAnnotDesignerDestroy, (FR_BAAnnotDesigner handler))

NumOfSelector(FRIBAAnnotDesigner)
ENDENUM

//*****************************
/* CBFInterForm HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_Document, FRCBFInterFormGetDocument, (FR_CBFInterForm form))

INTERFACE(FR_CBF_Widget, FRCBFInterFormGetWidget, (FR_CBFInterForm form,  FPD_FormControl control,  FS_BOOL bAddToPage))

INTERFACE(void, FRCBFInterFormRemoveMap, (FR_CBFInterForm form,  FPD_FormControl control))

INTERFACE(FR_ReaderInterform, FRCBFInterFormGetReaderInterForm, (FR_CBFInterForm form))

NumOfSelector(FRCBFInterForm)
ENDENUM

//*****************************
/* BFFormNotify HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_IBFFormNotify, FRBFFormNotifyNew, (FRD_BFFormNotifyCallbacks callbacks))

INTERFACE(void, FRBFFormNotifyDestroy, (FR_IBFFormNotify handler))

NumOfSelector(FRBFFormNotify)
ENDENUM

//*****************************
/* BFAnnotHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_BAAnnotHandler, FRBFAnnotHandlerNew, (FRD_BAAnnotHandlerCallbacks callbacks))

INTERFACE(void, FRBFAnnotHandlerDestroy, (FR_BAAnnotHandler handler))

NumOfSelector(FRBFAnnotHandler)
ENDENUM

//*****************************
/* BaseForm HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRBaseFormGetBaseForm
 * @details Get IBaseForm object.
 * @return   FR_BaseForm
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FR_BaseForm, FRBaseFormGetBaseForm, ())

/**
 * @brief FRBaseFormBeginTabOrderDesign
 * @details Begin tab order of the pageview.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pPageView The input pageview object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormBeginTabOrderDesign, (FR_BaseForm form,  FR_PageView pPageView))

/**
 * @brief FRBaseFormEndTabOrderDesign
 * @details End tab order of the pageview.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pPageView The input pageview object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormEndTabOrderDesign, (FR_BaseForm form,  FR_PageView pPageView))

/**
 * @brief FRBaseFormShowTabOrder
 * @details Set if show tab order.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  bShow Set true will show tab order.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormShowTabOrder, (FR_BaseForm form,  FS_BOOL bShow))

/**
 * @brief FRBaseFormSetFormFiller
 * @details Set annot handler.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pFiller The input annot filler handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormSetFormFiller, (FR_BaseForm form,  FR_BAAnnotFiller pFiller))

/**
 * @brief FRBaseFormSetSignatureFiller
 * @details Set annot handler.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pFiller The input signature type filler handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormSetSignatureFiller, (FR_BaseForm form,  FR_BAAnnotFiller pFiller))

/**
 * @brief FRBaseFormGetFillerByAnnot
 * @details Get filler handler by annot.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pAnnot The input annot type.
 * @return   FR_BAAnnotFiller
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FR_BAAnnotFiller, FRBaseFormGetFillerByAnnot, (FR_BaseForm form,  FR_Annot pAnnot))

/**
 * @brief FRBaseFormSetFormDesigner
 * @details Set form design handler.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pDesigner The input annot designer handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormSetFormDesigner, (FR_BaseForm form,  FR_BAAnnotDesigner pDesigner))

/**
 * @brief FRBaseFormSetSignatureHandler
 * @details Set signature handler.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pHandler The input annot handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormSetSignatureHandler, (FR_BaseForm form,  FR_BAAnnotHandler pHandler))

/**
 * @brief FRBaseFormSetXFASignatureHandler
 * @details Set XFA signature handler.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pHandler The input annot handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormSetXFASignatureHandler, (FR_BaseForm form,  FR_BAAnnotHandler pHandler))

/**
 * @brief FRBaseFormGetXFASignatureHandler
 * @details Get XFA signature handler.
 * @param[in]  form The input FR_BaseForm.
 * @return   FR_BAAnnotHandler
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FR_BAAnnotHandler, FRBaseFormGetXFASignatureHandler, (FR_BaseForm form))

/**
 * @brief FRBaseFormIsHighLight
 * @details Check the baseform is highlight.
 * @param[in]  form The input FR_BaseForm.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRBaseFormIsHighLight, (FR_BaseForm form))

/**
 * @brief FRBaseFormSetHighLight
 * @details Sets whether the Form is highlight.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  bHighLight Sets true this baseform is highlight.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormSetHighLight, (FR_BaseForm form,  FS_BOOL bHighLight))

/**
 * @brief FRBaseFormSetHighLightColor
 * @details Sets highlight color of the baseform.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  color Sets highlight color of the baseform.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormSetHighLightColor, (FR_BaseForm form,  FS_COLORREF color))

/**
 * @brief FRBaseFormGetHighLightColor
 * @details Get highlight color of the baseform.
 * @param[in]  form The input FR_BaseForm.
 * @return   FS_COLORREF
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_COLORREF, FRBaseFormGetHighLightColor, (FR_BaseForm form))

/**
 * @brief FRBaseFormGetRequiredColor
 * @details Get required highlight color of the baseform.
 * @param[in]  form The input FR_BaseForm.
 * @return   FS_COLORREF
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_COLORREF, FRBaseFormGetRequiredColor, (FR_BaseForm form))

/**
 * @brief FRBaseFormIsFormDesignerAssistEnabled
 * @details Get form designer assist is enable.
 * @param[in]  form The input FR_BaseForm.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRBaseFormIsFormDesignerAssistEnabled, (FR_BaseForm form))

/**
 * @brief FRBaseFormSetFormDesignerAssistEnabled
 * @details Set form designer assist is enable.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  bEnable Set true form designer assist will enable.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormSetFormDesignerAssistEnabled, (FR_BaseForm form,  FS_BOOL bEnable))

/**
 * @brief FRBaseFormGetAutoCompleteChoice
 * @details Get the choice of auto complete, like FRAUTOCOMPLETEOFF.
 * @param[in]  form The input FR_BaseForm.
 * @return   FS_INT32     FR_AUTOCOMPLETECHOICE type.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_INT32, FRBaseFormGetAutoCompleteChoice, (FR_BaseForm form))

/**
 * @brief FRBaseFormIsOpenPropertyAfterCreate
 * @details Check if open property when after create.
 * @param[in]  form The input FR_BaseForm.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRBaseFormIsOpenPropertyAfterCreate, (FR_BaseForm form))

/**
 * @brief FRBaseFormShowFocusRect
 * @details Check if show focus rect of the preferences dialog .
 * @param[in]  form The input FR_BaseForm.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRBaseFormShowFocusRect, (FR_BaseForm form))

/**
 * @brief FRBaseFormShowOverflowIndicator
 * @details Check if show over flow indicator of the preferences dialog .
 * @param[in]  form The input FR_BaseForm.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRBaseFormShowOverflowIndicator, (FR_BaseForm form))

/**
 * @brief FRBaseFormIsNumericalDataEnable
 * @details Get if check the rember numeric data of the preferences dialog .
 * @param[in]  form The input FR_BaseForm.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRBaseFormIsNumericalDataEnable, (FR_BaseForm form))

/**
 * @brief FRBaseFormSetFormNotify
 * @details Set form notify, when form changed that will get the notify.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pNotify The input form notify handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormSetFormNotify, (FR_BaseForm form,  FR_IBFFormNotify pNotify))

/**
 * @brief FRBaseFormCollectAPStreamRefCount
 * @details Collect AP stream.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pDoc The input FPD_Document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormCollectAPStreamRefCount, (FR_BaseForm form,  FPD_Document pDoc))

/**
 * @brief FRBaseFormClearAPStreamRefCount
 * @details Clear AP stream.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pDoc The input FPD_Document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormClearAPStreamRefCount, (FR_BaseForm form,  FPD_Document pDoc))

/**
 * @brief FRBaseFormGetAPStreamRefCount
 * @details Get AP stream ref count of the document.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pDoc The input FPD_Document.
 * @param[in]  dwStreamObjNum The input stream obj num.
 * @param[out]  dwCount Get the stream ref count.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRBaseFormGetAPStreamRefCount, (FR_BaseForm form,  FPD_Document pDoc,  FS_DWORD dwStreamObjNum,  FS_DWORD* dwCount))

/**
 * @brief FRBaseFormShow
 * @details Show widget annot of the pageviewer.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pPageView The input pageviewer object.
 * @param[in]  pSigAnnot The input widget object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRBaseFormShow, (FR_BaseForm form,  FR_PageView pPageView,  FR_CBF_Widget pSigAnnot))

/**
 * @brief FRBaseFormSetWidgetMsgHook
 * @details Show widget annot of the pageviewer.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pPageView The input pageviewer object.
 * @param[in]  pSigAnnot The input widget object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRBaseFormSetWidgetMsgHook, (FR_BaseForm form,  FR_WidgetAnnotHandler pHook))

/**
 * @brief FRBaseFormGetWidgetMsgHook
 * @details Show widget annot of the pageviewer.
 * @param[in]  form The input FR_BaseForm.
 * @param[in]  pPageView The input pageviewer object.
 * @param[in]  pSigAnnot The input widget object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_WidgetAnnotHandler, FRBaseFormGetWidgetMsgHook, (FR_BaseForm form))

NumOfSelector(FRBaseForm)
ENDENUM

//*****************************
/* IFormDesignerNotify HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRIFormDesignerNotifyNew
 * @details Create FR_IFormDesignerNotify object.
 * @param[in]  callbacks The FRD_FormDesignNotifyCallbacks callback.
 * @return   FR_IFormDesignerNotify
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRDocSetNotify
 * @see FRIFormDesignerNotifyNew
 */
INTERFACE(FR_IFormDesignerNotify, FRIFormDesignerNotifyNew, (FRD_FormDesignNotifyCallbacks callbacks))

/**
 * @brief FRIFormDesignerNotifyDestroy
 * @details Release FR_IFormDesignerNotify object.
 * @param[in]  handler The FR_IFormDesignerNotify object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRIFormDesignerNotifyDestroy
 */
INTERFACE(void, FRIFormDesignerNotifyDestroy, (FR_IFormDesignerNotify handler))

NumOfSelector(FRIFormDesignerNotify)
ENDENUM

//*****************************
/* CBFWidget HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRCBFWidgetResetAppearance
 * @details 
 * @param[in]  widget The input widget object. Get it from FRAnnotGetCBFWidget,
	* it can create by FRPageViewAddAnnot,or get FR_Annot by FRPageViewGetAnnotByIndex.
 * @param[in]  bValueChanged Whether change value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRPageViewAddAnnot
 * @see FRPageAddAnnot2
 * @see FRAnnotGetCBFWidget
 */
INTERFACE(void, FRCBFWidgetResetAppearance, (FR_CBF_Widget widget,  FS_BOOL bValueChanged))

/**
 * @brief FRCBFWidgetIsAppearanceValid
 * @details 
 * @param[in]  widget The input widget object.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRCBFWidgetIsAppearanceValid, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetGetFieldType
 * @details 
 * @param[in]  widget The input widget object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_INT32, FRCBFWidgetGetFieldType, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetGetFieldFlags
 * @details 
 * @param[in]  widget The input widget object.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRCBFWidgetGetFieldFlags, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetGetRotate
 * @details 
 * @param[in]  widget The input widget object.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_INT32, FRCBFWidgetGetRotate, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetGetTextColor
 * @details 
 * @param[in]  widget The input widget object.
 * @param[out]  color The color of the widget.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRCBFWidgetGetTextColor, (FR_CBF_Widget widget,  FS_COLORREF* color))

/**
 * @brief FRCBFWidgetGetFont
 * @details 
 * @param[in]  widget The input widget object.
 * @param[out]  bsFont The font of the widget.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRCBFWidgetGetFont, (FR_CBF_Widget widget,  FS_ByteString* bsFont))

/**
 * @brief FRCBFWidgetGetBaseFont
 * @details 
 * @param[in]  widget The input widget object.
 * @param[out]  bsBaseFont The base font name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRCBFWidgetGetBaseFont, (FR_CBF_Widget widget,  FS_ByteString* bsBaseFont))

/**
 * @brief FRCBFWidgetIsReadOnly
 * @details 
 * @param[in]  widget The input widget object.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRCBFWidgetIsReadOnly, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetIsVisible
 * @details 
 * @param[in]  widget The input widget object.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRCBFWidgetIsVisible, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetSetRect
 * @details 
 * @param[in]  widget The input widget object.
 * @param[in]  rect Set the rect of the widget.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRCBFWidgetSetRect, (FR_CBF_Widget widget,  const FS_FloatRect rect))

/**
 * @brief FRCBFWidgetGetRect
 * @details 
 * @param[in]  widget The input widget object.
 * @return   FS_FloatRect
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_FloatRect, FRCBFWidgetGetRect, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetClearCachedAP
 * @details 
 * @param[in]  widget The input widget object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRCBFWidgetClearCachedAP, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetDrawAppearance
 * @details 
 * @param[in]  widget The input widget object.
 * @param[in]  pDevice The render device.
 * @param[in]  pUser2Device The matrix of the userdevice.
 * @param[in]  mode The Appearance mode enumeration of annotation.
 * @param[in]  pOptions The render options.
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRCBFWidgetDrawAppearance, (FR_CBF_Widget widget,  FPD_RenderDevice pDevice,  const FS_AffineMatrix pUser2Device,  FPD_AnnotAppearanceMode mode,  const FPD_RenderOptions pOptions))

/**
 * @brief FRCBFWidgetResetAppearance2
 * @details 
 * @param[in]  widget The input widget object.
 * @param[in]  sValue Reset the value of filed control.
 * @param[in]  bValueChanged If the value changed.
 * @param[in]  bResetRV If need to reset "RV" dictionary.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRCBFWidgetResetAppearance2, (FR_CBF_Widget widget,  FS_LPCWSTR sValue,  FS_BOOL bValueChanged,  FS_BOOL bResetRV))

/**
 * @brief FRCBFWidgetHideHint
 * @details 
 * @param[in]  widget The input widget object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRCBFWidgetHideHint, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetShowHint
 * @details 
 * @param[in]  widget The input widget object.
 * @param[in]  hParent The HWND of the hint window.
 * @param[in]  point The position of the hint windows.
 * @param[in]  sTooltip The msg of hint.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRCBFWidgetShowHint, (FR_CBF_Widget widget,  FS_LPVOID hParent,  const FS_FloatPoint point,  const FS_WideString sTooltip))

/**
 * @brief FRCBFWidgetGetFormControl
 * @details 
 * @param[in]  widget The input widget object.
 * @return   FPD_FormControl
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FPD_FormControl, FRCBFWidgetGetFormControl, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetOnFormat
 * @details 
 * @param[in]  widget The input widget object.
 * @param[in]  nCommitKey The key of the commit.
 * @param[out]  bFormated Get the reslut if be formated.
 * @param[out]  out The reslut with run JS filed format.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRCBFWidgetOnFormat, (FR_CBF_Widget widget,  FS_INT32 nCommitKey,  FS_BOOL* bFormated,  FS_WideString* out))

/**
 * @brief FRCBFWidgetGetInterForm
 * @details 
 * @param[in]  widget The input widget object.
 * @return   FR_CBFInterForm
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_CBFInterForm, FRCBFWidgetGetInterForm, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetGetAnnotDict
 * @details 
 * @param[in]  widget The input widget object.
 * @return   FPD_Object
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FPD_Object, FRCBFWidgetGetAnnotDict, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetGetName
 * @details 
 * @param[in]  widget The input widget object.
 * @param[out]  name The full name of the field.
 * @return   FPD_Object
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRCBFWidgetGetName, (FR_CBF_Widget widget,  FS_WideString* name))

/**
 * @brief FRCBFWidgetSetRotate
 * @details 
 * @param[in]  widget The input widget object.
 * @param[int]  nRotate Set the rotate of the widget.
 * @return   FPD_Object
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRCBFWidgetSetRotate, (FR_CBF_Widget widget,  FS_INT32 nRotate))

/**
 * @brief FRCBFWidgetGetIReaderAnnot
 * @details 
 * @param[in]  widget The input widget object.
 * @return   FR_Annot
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_Annot, FRCBFWidgetGetIReaderAnnot, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetSetName
 * @details 
 * @param[in]  widget The input widget object.
 * @param[in]  sName The input new field name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRCBFWidgetSetName, (FR_CBF_Widget widget,  const FS_WideString sName))

/**
 * @brief FRCBFWidgetHasAAction
 * @details 
 * @param[in]  widget The input widget object.
 * @param[in]  eAAT The input AActionType.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRCBFWidgetHasAAction, (FR_CBF_Widget widget,  FPD_AActionType eAAT))

/**
 * @brief FRCBFWidgetOnAAction
 * @details 
 * @param[in]  widget The input widget object.
 * @param[in]  type The input AActionType.
 * @param[out]  data The out filed action data.
 * @param[in]  pPageView The input FR_PageView object.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRCBFWidgetOnAAction, (FR_CBF_Widget widget,  FPD_AActionType type,  FR_BAFieldAction* data,  FR_PageView pPageView))

/**
 * @brief FRCBFWidgetDrawShadow
 * @details 
 * @param[in]  widget The input widget object.
 * @param[in]  pDevice The input RenderDevice object.
 * @param[in]  winPort The input HWND.
 * @param[in]  pPageView The input FR_PageView object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRCBFWidgetDrawShadow, (FR_CBF_Widget widget,  FPD_RenderDevice pDevice,  FR_WinPort winPort,  FR_PageView pPageView))

/**
 * @brief FRCBFWidgetGetMixXFAWidget
 * @details 
 * @param[in]  widget The input widget object.
 * @return   PFPDXFA_HWIDGET
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(PFPDXFA_HWIDGET, FRCBFWidgetGetMixXFAWidget, (FR_CBF_Widget widget))

/**
 * @brief FRCBFWidgetDrawCustomShadow
 * @details 
 * @param[in]  widget The input widget object.
 * @param[in]  pDevice The input RenderDevice object.
 * @param[in]  color The input color.
 * @param[in]  hDC The input DC object.
 * @param[in]  pPageView The input FR_PageView.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRCBFWidgetDrawCustomShadow, (FR_CBF_Widget widget,  FPD_RenderDevice pDevice,  FS_COLORREF color,  FS_HDC hDC,  FR_PageView pPageView))

NumOfSelector(FRCBFWidget)
ENDENUM

//*****************************
/* IBFSimpleFromProperties HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOL, FRIBFSimpleFromPropertiesIsVisible, (FR_BFSimpleFromProperties properties))

INTERFACE(void, FRIBFSimpleFromPropertiesShow, (FR_BFSimpleFromProperties properties,  FR_PageView pPageView,  FR_CBF_Widget pWidget))

INTERFACE(void, FRIBFSimpleFromPropertiesHide, (FR_BFSimpleFromProperties properties))

NumOfSelector(FRIBFSimpleFromProperties)
ENDENUM

//*****************************
/* SGRDN HFT functions */
//*****************************

BEGINENUM
INTERFACE(FRSG_RDN, FRSGRDNCreate, ())

INTERFACE(void, FRSGRDNDestroy, (FRSG_RDN rdn))

INTERFACE(void, FRSGRDNSetcwC, (FRSG_RDN rdn,  FS_WideString value))

INTERFACE(void, FRSGRDNGetcwC, (FRSG_RDN rdn,  FS_WideString* outvalue))

INTERFACE(void, FRSGRDNSetcwCN, (FRSG_RDN rdn,  FS_WideString value))

INTERFACE(void, FRSGRDNGetcwCN, (FRSG_RDN rdn,  FS_WideString* outvalue))

INTERFACE(void, FRSGRDNSetcwE, (FRSG_RDN rdn,  FS_WideString value))

INTERFACE(void, FRSGRDNGetcwE, (FRSG_RDN rdn,  FS_WideString* outvalue))

INTERFACE(void, FRSGRDNSetcwL, (FRSG_RDN rdn,  FS_WideString value))

INTERFACE(void, FRSGRDNGetcwL, (FRSG_RDN rdn,  FS_WideString* outvalue))

INTERFACE(void, FRSGRDNSetcwO, (FRSG_RDN rdn,  FS_WideString value))

INTERFACE(void, FRSGRDNGetcwO, (FRSG_RDN rdn,  FS_WideString* outvalue))

INTERFACE(void, FRSGRDNSetcwOU, (FRSG_RDN rdn,  FS_WideString value))

INTERFACE(void, FRSGRDNGetcwOU, (FRSG_RDN rdn,  FS_WideString* outvalue))

INTERFACE(void, FRSGRDNSetcwST, (FRSG_RDN rdn,  FS_WideString value))

INTERFACE(void, FRSGRDNGetcwST, (FRSG_RDN rdn,  FS_WideString* outvalue))

NumOfSelector(FRSGRDN)
ENDENUM

//*****************************
/* SGCERTIFICATE HFT functions */
//*****************************

BEGINENUM
INTERFACE(FRSG_CERTIFICATE_INFO, FRSGCERTIFICATECreate, ())

INTERFACE(void, FRSGCERTIFICATEDestroy, (FRSG_CERTIFICATE_INFO info))

INTERFACE(void, FRSGCERTIFICATESetFlags, (FRSG_CERTIFICATE_INFO info,  FS_INT32 nFlags))

INTERFACE(FS_INT32, FRSGCERTIFICATEGetFlags, (FRSG_CERTIFICATE_INFO info))

INTERFACE(void, FRSGCERTIFICATESetIssuersArr, (FRSG_CERTIFICATE_INFO info,  FS_ByteStringArray issueArr))

INTERFACE(void, FRSGCERTIFICATEGetIssuersArr, (FRSG_CERTIFICATE_INFO info,  FS_ByteStringArray* outissueArr))

INTERFACE(void, FRSGCERTIFICATESetKeyUsageArr, (FRSG_CERTIFICATE_INFO info,  FS_ByteStringArray keyUsageArr))

INTERFACE(void, FRSGCERTIFICATEGetKeyUsageArr, (FRSG_CERTIFICATE_INFO info,  FS_ByteStringArray* outkeyUsageArr))

INTERFACE(void, FRSGCERTIFICATESetOidArr, (FRSG_CERTIFICATE_INFO info,  FS_ByteStringArray oidArr))

INTERFACE(void, FRSGCERTIFICATEGetOidArr, (FRSG_CERTIFICATE_INFO info,  FS_ByteStringArray* outoidArr))

INTERFACE(void, FRSGCERTIFICATESetSubjectDNArr, (FRSG_CERTIFICATE_INFO info,  FRSG_RDN nFlags[],  FS_INT32 size))

INTERFACE(void, FRSGCERTIFICATEGetSubjectDNArr, (FRSG_CERTIFICATE_INFO info,  FRSG_RDN outrdnArr[],  FS_INT32* outSize))

INTERFACE(void, FRSGCERTIFICATESetUrl, (FRSG_CERTIFICATE_INFO info,  FS_ByteString url))

INTERFACE(void, FRSGCERTIFICATEGetUrl, (FRSG_CERTIFICATE_INFO info,  FS_ByteString* outUrl))

INTERFACE(void, FRSGCERTIFICATESetUrlType, (FRSG_CERTIFICATE_INFO info,  FS_ByteString urlType))

INTERFACE(void, FRSGCERTIFICATEGetUrlType, (FRSG_CERTIFICATE_INFO info,  FS_ByteString* outUrlType))

INTERFACE(void, FRSGCERTIFICATESetSubjectArr, (FRSG_CERTIFICATE_INFO info,  FS_ByteStringArray subjectArr))

INTERFACE(void, FRSGCERTIFICATEGetSubjectArr, (FRSG_CERTIFICATE_INFO info,  FS_ByteStringArray* outsubjectArr))

NumOfSelector(FRSGCERTIFICATE)
ENDENUM

//*****************************
/* SGSEEDVALUE HFT functions */
//*****************************

BEGINENUM
INTERFACE(FRSG_SEEDVALUE_INFO, FRSGSEEDVALUECreate, ())

INTERFACE(void, FRSGSEEDVALUEDestroy, (FRSG_SEEDVALUE_INFO info))

INTERFACE(FRSG_CERTIFICATE_INFO, FRSGSEEDVALUEGetCertInfo, (FRSG_SEEDVALUE_INFO info))

INTERFACE(void, FRSGSEEDVALUESetDigestMethodArr, (FRSG_SEEDVALUE_INFO info,  FS_ByteStringArray methodArr))

INTERFACE(void, FRSGSEEDVALUEGetDigestMethodArr, (FRSG_SEEDVALUE_INFO info,  FS_ByteStringArray* outmethodArr))

INTERFACE(void, FRSGSEEDVALUESetFilter, (FRSG_SEEDVALUE_INFO info,  FS_WideString filter))

INTERFACE(void, FRSGSEEDVALUEGetFilter, (FRSG_SEEDVALUE_INFO info,  FS_WideString* outFilter))

INTERFACE(void, FRSGSEEDVALUESetFlags, (FRSG_SEEDVALUE_INFO info,  FS_INT32 flags))

INTERFACE(FS_INT32, FRSGSEEDVALUEGetFlags, (FRSG_SEEDVALUE_INFO info))

INTERFACE(void, FRSGSEEDVALUESetlegalAttestationsArr, (FRSG_SEEDVALUE_INFO info,  FS_WideStringArray legalArr))

INTERFACE(void, FRSGSEEDVALUEGetlegalAttestationsArr, (FRSG_SEEDVALUE_INFO info,  FS_WideStringArray* outlegalArr))

INTERFACE(void, FRSGSEEDVALUESetmdp, (FRSG_SEEDVALUE_INFO info,  FS_ByteString mdp))

INTERFACE(void, FRSGSEEDVALUEGetmdp, (FRSG_SEEDVALUE_INFO info,  FS_ByteString* outMdp))

INTERFACE(void, FRSGSEEDVALUESetReasonArr, (FRSG_SEEDVALUE_INFO info,  FS_WideStringArray reasonArr))

INTERFACE(void, FRSGSEEDVALUEGetReasonArr, (FRSG_SEEDVALUE_INFO info,  FS_WideStringArray* outreasonArr))

INTERFACE(void, FRSGSEEDVALUESetbAddRevInfo, (FRSG_SEEDVALUE_INFO info,  FS_INT32 bRevInfo))

INTERFACE(FS_INT32, FRSGSEEDVALUEGetbAddRevInfo, (FRSG_SEEDVALUE_INFO info))

INTERFACE(void, FRSGSEEDVALUESetSubFilterArr, (FRSG_SEEDVALUE_INFO info,  FS_WideStringArray subFilterArr))

INTERFACE(void, FRSGSEEDVALUEGetSubFilterArr, (FRSG_SEEDVALUE_INFO info,  FS_WideStringArray* outsubFilterArrArr))

INTERFACE(void, FRSGSEEDVALUESetVersion, (FRSG_SEEDVALUE_INFO info,  FS_INT32 version))

INTERFACE(FS_INT32, FRSGSEEDVALUEGetVersion, (FRSG_SEEDVALUE_INFO info))

INTERFACE(void, FRSGSEEDVALUESettimeStampspec, (FRSG_SEEDVALUE_INFO info,  FR_SignatureTimestampServer stampSpec))

INTERFACE(FR_SignatureTimestampServer, FRSGSEEDVALUEGettimeStampspec, (FRSG_SEEDVALUE_INFO info))

NumOfSelector(FRSGSEEDVALUE)
ENDENUM

//*****************************
/* SGBaseHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(void*, FRSGBaseHandlerNew, (FRD_SGBaseHandlerCallbacks callbacks))

INTERFACE(void, FRSGBaseHandlerDestroy, (void* handler))

NumOfSelector(FRSGBaseHandler)
ENDENUM

//*****************************
/* IClipBoard HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_ClipBoard, FRIClipBoardGetClipboard, ())

INTERFACE(FS_BOOLEAN, FRIClipBoardRemoveElement, (FR_ClipBoard clipboard,  FS_XMLElement element))

INTERFACE(FS_BOOLEAN, FRIClipBoardInitial, (FR_ClipBoard clipboard,  FS_BOOLEAN bSave))

INTERFACE(void, FRIClipBoardRelease, (FR_ClipBoard clipboard))

INTERFACE(FS_DWORD, FRIClipBoardGetElementCounts, (FR_ClipBoard clipboard))

INTERFACE(FS_XMLElement, FRIClipBoardGetElement, (FR_ClipBoard clipboard,  FS_DWORD dwIndex))

INTERFACE(void, FRIClipBoardAddElement, (FR_ClipBoard clipboard,  FS_XMLElement pElement))

INTERFACE(void, FRIClipBoardGetMD5, (FR_ClipBoard clipboard,  FS_ByteString* bsMD5))

INTERFACE(void, FRIClipBoardGetType, (FS_XMLElement pElement,  FS_ByteString* outType))

INTERFACE(void, FRIClipBoardGetSubtype, (FS_XMLElement pElement,  FS_ByteString* outType))

INTERFACE(FS_FloatRect, FRIClipBoardGetRect, (FS_XMLElement pElement))

INTERFACE(FS_BOOL, FRIClipBoardExportToXML, (FR_Annot pAnnot,  FR_CCBAnnotation pClipAnnot,  FS_XMLElement pElement))

INTERFACE(FS_BOOL, FRIClipBoardImportFromXML, (FS_XMLElement pElement,  FR_CCBAnnotation pClipAnnot,  FR_Annot pAnnot))

NumOfSelector(FRIClipBoard)
ENDENUM

//*****************************
/* CCBAnnotation HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FRCCBAnnotationDelete, (FR_CCBAnnotation annot))

INTERFACE(FS_BOOLEAN, FRCCBAnnotationParseToXML, (FR_CCBAnnotation annot,  FPD_Object pAnnotDict,  FS_XMLElement pElement,  FS_BOOLEAN bBaseFun))

INTERFACE(FS_BOOLEAN, FRCCBAnnotationParseToDict, (FR_CCBAnnotation annot,  FS_XMLElement pElement,  FPD_Object pAnnotDict,  FS_BOOLEAN bBaseFun))

INTERFACE(FS_BOOLEAN, FRCCBAnnotationIsKeyNeeded_ToXML, (FR_CCBAnnotation annot,  FS_ByteString csKeyName,  FS_INT32 nObjType,  FS_BOOLEAN bBaseFun))

INTERFACE(FS_BOOLEAN, FRCCBAnnotationIsKeyNeeded_ToDict, (FR_CCBAnnotation annot,  FS_ByteString csKeyName,  FS_INT32 nObjType,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FRCCBAnnotationAddNecessaryKeyToList_ToXML, (FR_CCBAnnotation annot,  FS_ByteString csKeyName,  FS_BOOLEAN bBaseFun))

INTERFACE(FR_CCBAnnotation, FRCCBAnnotationNew, (FR_CCBAnnotationCallbacks callbacks,  FPD_Document doc))

NumOfSelector(FRCCBAnnotation)
ENDENUM

//*****************************
/* ISpellCheck HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FRISpellCheck)
ENDENUM

//*****************************
/* CJavaScriptEditer HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOLEAN, FRCJavaScriptEditerIsUseExternalJSEditor, ())

INTERFACE(FS_BOOLEAN, FRCJavaScriptEditerEditWithGlobalWnd, (FS_LPVOID pParent,  FS_WideString* script))

INTERFACE(FS_BOOLEAN, FRCJavaScriptEditerEditWithExternalJSEditor, (FS_WideString* script))

NumOfSelector(FRCJavaScriptEditer)
ENDENUM

//*****************************
/* IBAImageSource HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRIBAImageSourceNewIBAImageSource
 * @details Create FR_IBAImageSource that used to call the SetColorSource interface of FR_CBAFigureRecognition.
 * @param[in]  callbacks The FR_IBAImageSourceHandlerCallbacks object.
 * @return   FR_IBAImageSource.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FR_IBAImageSource, FRIBAImageSourceNewIBAImageSource, (FR_IBAImageSourceHandlerCallbacks callbacks))

/**
 * @brief FRIBAImageSourceDestroyImageSource
 * @details 
 * @param[in]  source The FR_IBAImageSource object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRIBAImageSourceDestroyImageSource, (FR_IBAImageSource source))

NumOfSelector(FRIBAImageSource)
ENDENUM

//*****************************
/* CBAFigureRecognition HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRCBAFigureRecognitionNewCBAFigureRecognition
 * @details Create FR_CBAFigureRecognition obj of the CBA_FigureRecognition, this used to form area identification.
 * @return   FR_CBAFigureRecognition.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FR_CBAFigureRecognition, FRCBAFigureRecognitionNewCBAFigureRecognition, ())

/**
 * @brief FRCBAFigureRecognitionDestroyCBA_FigureRecognition
 * @details Destroy FR_CBAFigureRecognition obj.
 * @param[in]  recogntion The FR_CBAFigureRecognition object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRCBAFigureRecognitionDestroyCBA_FigureRecognition, (FR_CBAFigureRecognition recogntion))

/**
 * @brief FRCBAFigureRecognitionSetColorSource
 * @details Set the ImageSource to FR_CBAFigureRecognition, if the imagesource is invalid, FRCBAFigureRecognitionFindRectBy4Point will be crash.
 * @param[in]  recogntion The FR_CBAFigureRecognition object.
 * @param[in]  source The FR_IBAImageSource object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRCBAFigureRecognitionSetColorSource, (FR_CBAFigureRecognition recogntion,  FR_IBAImageSource source))

/**
 * @brief FRCBAFigureRecognitionFindRectBy4Point
 * @details Find rect by point to create form area. It must be call FRCBAFigureRecognitionSetColorSource first.
 * @param[in]  recogntion The FR_CBAFigureRecognition object.
 * @param[in]  ptx The x of the point.
 * @param[in]  pty The y of the point.
 * @param[out]  rect The rect contains the point.
 * @return   FS_BOOL.            <a>TRUE</a> find the rect successful, <a>FALSE</a>  find the rect fail.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRCBAFigureRecognitionFindRectBy4Point, (FR_CBAFigureRecognition recogntion,  FS_INT32 ptx,  FS_INT32 pty,  FS_Rect* rect))

NumOfSelector(FRCBAFigureRecognition)
ENDENUM

//*****************************
/* AnnotObserver HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRAnnotObserverCreateAnnotObserver
 * @details Encapsulat the IReader_Annot::Observer to listen the object in plugin.
 * @param[in]  annot The FR_Annot object.
 * @return   FR_AnnotObserver.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FR_AnnotObserver, FRAnnotObserverCreateAnnotObserver, (FR_Annot annot))

/**
 * @brief FRAnnotObserverDestroyAnnotObserver
 * @details Destroy FR_AnnotObserver object.
 * @param[in]  observer The FR_AnnotObserver object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRAnnotObserverDestroyAnnotObserver, (FR_AnnotObserver observer))

/**
 * @brief FRAnnotObserverIsValid
 * @details Check is the FR_Annot is valid.
 * @param[in]  observer The FR_AnnotObserver object.
 * @return   FS_BOOLEAN.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOLEAN, FRAnnotObserverIsValid, (FR_AnnotObserver observer))

/**
 * @brief FRAnnotObserverGetAnnotObj
 * @details Get the FR_Annot object of the observer.
 * @param[in]  observer The FR_AnnotObserver object.
 * @return   FR_Annot.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FR_Annot, FRAnnotObserverGetAnnotObj, (FR_AnnotObserver observer))

NumOfSelector(FRAnnotObserver)
ENDENUM

//*****************************
/* DocumentObserver HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRDocumentObserverCreateDocumentObserver
 * @details Encapsulat the CReader_Document::Observer to listen the object in plugin.
 * @param[in]  doc The FR_Document object.
 * @return   FR_DocumentObserver.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FR_DocumentObserver, FRDocumentObserverCreateDocumentObserver, (FR_Document doc))

/**
 * @brief FRDocumentObserverDestroyDocumentObserver
 * @details Destroy FR_DocumentObserver object.
 * @param[in]  observer The FR_DocumentObserver object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRDocumentObserverDestroyDocumentObserver, (FR_DocumentObserver observer))

/**
 * @brief FRDocumentObserverIsValid
 * @details Check is the FR_Document is valid.
 * @param[in]  observer The FR_DocumentObserver object.
 * @return   FS_BOOLEAN.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOLEAN, FRDocumentObserverIsValid, (FR_DocumentObserver observer))

/**
 * @brief FRDocumentObserverGetDocumentObj
 * @details Get the FR_Document object of the observer.
 * @param[in]  observer The FR_DocumentObserver object.
 * @return   FR_Document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FR_Document, FRDocumentObserverGetDocumentObj, (FR_DocumentObserver observer))

NumOfSelector(FRDocumentObserver)
ENDENUM

//*****************************
/* InnerContentProvider HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRInnerContentProviderGetInnerContentProvider
 * @details FR_InnerContentProvider is allow user to add the process of their own when parsing pdf Doucment.
 * @param[in]  doc The current document object.
 * @return   FR_InnerContentProvider.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FR_InnerContentProvider, FRInnerContentProviderGetInnerContentProvider, (FR_Document doc))

/**
 * @brief FRInnerContentProviderOnGetContentSize
 * @details 
 * @param[in]  provider The content provider.
 * @param[in]  pReaderDoc The current document object.
 * @param[out]  pTotalSize Get the size of the content.
 * @return   FS_BOOLEAN.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOLEAN, FRInnerContentProviderOnGetContentSize, (FR_InnerContentProvider provider,  FR_Document pReaderDoc,  FS_LPDWORD pTotalSize))

/**
 * @brief FRInnerContentProviderOnReadContent
 * @details 
 * @param[in]  provider The content provider.
 * @param[in]  pReaderDoc The current document object.
 * @param[in]  dwPos Set the read position, default is 0.
 * @param[out]  pBuf Read the content buffer.
 * @param[in]  size The value is get from OnGetContentSize.
 * @return   FS_BOOLEAN.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOLEAN, FRInnerContentProviderOnReadContent, (FR_InnerContentProvider provider,  FR_Document pReaderDoc,  FS_DWORD dwPos,  FS_LPBYTE pBuf,  FS_DWORD size))

/**
 * @brief FRInnerContentProvideronBackFillContent
 * @details 
 * @param[in]  provider The content provider.
 * @param[in]  pReaderDoc The current document object.
 * @param[in]  pBuf Fill Content buffer.
 * @param[in]  size Fill content size.
 * @param[in]  lpSaveFilePath File path to save.
 * @return   FS_BOOLEAN.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOLEAN, FRInnerContentProviderOnBackFillContent, (FR_InnerContentProvider provider,  FR_Document pReaderDoc,  FS_LPBYTE pBuf,  FS_DWORD size,  FS_LPCWSTR lpSaveFilePath))

/**
 * @brief FRInnerContentProviderOnGetAppPermissions
 * @details 
 * @param[in]  provider The content provider.
 * @param[in]  pReaderDoc The current document object.
 * @param[in]  docappselfPermissions the permissions defined by application
 * @return   FS_DWORD.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_DWORD, FRInnerContentProviderOnGetAppPermissions, (FR_InnerContentProvider provider,  FR_Document pReaderDoc,  FS_DWORD  docappselfPermissions))

/**
 * @brief FRInnerContentProviderOnGetAttachmentSize
 * @details Get the attachment size.
 * @param[in]  provider The content provider.
 * @param[in]  pReaderDoc The current document object.
 * @param[out]  pTotalSize Get size of the attachment.
 * @param[in]  lpAttchmntPath The attachment path.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @see 
 */
INTERFACE(FS_INT32, FRInnerContentProviderOnGetAttachmentSize, (FR_InnerContentProvider provider,  FR_Document pReaderDoc,  FS_DWORD* pTotalSize,  FS_LPCWSTR lpAttchmntPath))

/**
 * @brief FRInnerContentProviderOnReadAttachmentContent
 * @details Get the attachment size.
 * @param[in]  provider The content provider.
 * @param[in]  pReaderDoc The current document object.
 * @param[out]  pBuf Get the buffer of attachment.
 * @param[in]  size The attachment size.
 * @param[in]  lpAttchmntPath The attachment path.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @see 
 */
INTERFACE(FS_INT32, FRInnerContentProviderOnReadAttachmentContent, (FR_InnerContentProvider provider,  FR_Document pReaderDoc,  FS_LPBYTE pBuf,  FS_DWORD size,  FS_LPCWSTR lpAttchmntPath))

NumOfSelector(FRInnerContentProvider)
ENDENUM

//*****************************
/* IFXPDFAInterface HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRIFXPDFAInterfaceGetIFXPDFAInterface
 * @details Get IFXPDFAInterface object.
 * @return   FR_IFXPDFAInterface.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FR_IFXPDFAInterface, FRIFXPDFAInterfaceGetIFXPDFAInterface, ())

/**
 * @brief FRIFXPDFAInterfaceSimplePDFACheck
 * @details Verify that it is a PDFA document
 * @param[in]  pdfainterface The input IFXPDFAInterface	object.
 * @param[in]  pPDFDoc The CPDF_Document object.
 * @param[in]  peV The peV string.
 * @return   FS_BOOL.   Return TRUE is PDFA document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRIFXPDFAInterfaceSimplePDFACheck, (FR_IFXPDFAInterface pdfainterface,  FPD_Document pPDFDoc,  FS_ByteString peV))

/**
 * @brief FRIFXPDFAInterfacePDFACheckIsClickEditing
 * @details Check the PDFA document has been editeded.
 * @param[in]  pdfainterface The input IFXPDFAInterface	object.
 * @param[in]  pRDDoc The reader_document object.
 * @return   FS_BOOL.   Return TRUE is edited.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRIFXPDFAInterfacePDFACheckIsClickEditing, (FR_IFXPDFAInterface pdfainterface,  FR_Document pRDDoc))

/**
 * @brief FRIFXPDFAInterfaceShowPreflightWnd
 * @details Show preflight dialog.
 * @param[in]  pdfainterface The input IFXPDFAInterface	object.
 * @param[in]  bShow Set true is show preflight dialog.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(void, FRIFXPDFAInterfaceShowPreflightWnd, (FR_IFXPDFAInterface pdfainterface,  FS_BOOLEAN bShow))

/**
 * @brief FRIFXPDFAInterfaceGetPreflightWndShow
 * @details Get if preflight dialog is show.
 * @param[in]  pdfainterface The input IFXPDFAInterface	object.
 * @return   FS_BOOLEAN.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 */
INTERFACE(FS_BOOLEAN, FRIFXPDFAInterfaceGetPreflightWndShow, (FR_IFXPDFAInterface pdfainterface))

NumOfSelector(FRIFXPDFAInterface)
ENDENUM

//*****************************
/* IConvertToPDF HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRIConvertToPDFGetFileType
 * @details Get the source file type.
 * @param[in]  lpwsFile The source file path.
 * @return   FR_SUPPORT_FILE_TYPE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_SUPPORT_FILE_TYPE, FRIConvertToPDFGetFileType, (FS_LPCWSTR lpwsFile))

/**
 * @brief FRIConvertToPDFGetFileFilter
 * @details Get file filter.
 * @param[in]  uFilter The content provider.
 * @param[out]  outFilter The current document object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRIConvertToPDFGetFileFilter, (FS_DWORD uFilter,  FS_WideString* outFilter))

/**
 * @brief FRIConvertToPDFConvertToPDF
 * @details Convert file to PDF.
 * @param[in]  lpwsFile The source file path.
 * @param[in]  lpwsDest The dest file path.
 * @param[in]  hWnd The app mainframe, it get from <a>FRAppGetMainFrameWnd</a>.
 * @param[in]  bShowProgressBar Set true will show progress bar.
 * @param[in]  bConvertToCPD Whether to convert to CPD.
 * @param[in]  pmba Error message box when convert fail.
 * @param[in]  bDelDestFile Whether need to delete dest file when convert fail.
 * @param[in]  pDocInfo Convert document info.
 * @return   FS_INT32.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRIConvertToPDFConvertToPDF, (FS_LPWSTR lpwsFile,  FS_LPWSTR lpwsDest,  FS_HWND hWnd,  FS_BOOL bShowProgressBar,  FS_BOOL bConvertToCPD,  FR_PMSGBOX_ATTRIBUTE pmba,  FS_BOOL bDelDestFile,  FR_PDocumentInfo pDocInfo))

NumOfSelector(FRIConvertToPDF)
ENDENUM

//*****************************
/* ITagePDF HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRITagePDFClearAllData
 * @details When the streaming edit exits, the tree needs to be rebuilt and the data needs to be cleared
 * @param[in]  pRDoc The current document.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRITagePDFClearAllData, (FR_Document pRDoc))

/**
 * @brief FRITagePDFTryRebuildPanel
 * @details Rebuild tag panel
 * @param[in]  panelType The panel type.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRITagePDFTryRebuildPanel, (FR_TagPDF_PanelType panelType))

/**
 * @brief FRITagePDFAsyncUpdateCheckerInfo
 * @details Asynchronous operation that actively notifies the Checker Panel to update its status
 * @param[in]  pRDDoc The current document.
 * @param[in]  dwRule The panel type.
 * @param[in]  state Accessibility checker state.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRITagePDFAsyncUpdateCheckerInfo, (FR_Document pRDDoc,  const FS_DWORD dwRule,  const FR_PDFAccessibilityCheckerState state))

NumOfSelector(FRITagePDF)
ENDENUM

//*****************************
/* TextPage HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_TextPage, FRTextPageGetReaderTextPage, (FR_Document doc,  FS_INT32 iPage,  FS_BOOL bCreate))

INTERFACE(void, FRTextPageReParseTextPage, (FR_TextPage textPage))

INTERFACE(FR_TextPage, FRTextPageCreateFRTextPage, (FPD_Page page,  FS_INT32 pageIndex))

NumOfSelector(FRTextPage)
ENDENUM

//*****************************
/* ISignatureCheck HFT functions */
//*****************************

BEGINENUM
INTERFACE(void*, FRISignatureCheckNew, (void* callbacks))

INTERFACE(void, FRISignatureCheckDestroy, (void* handler))

NumOfSelector(FRISignatureCheck)
ENDENUM

//----------_V15----------
//----------_V16----------
//*****************************
/* TextLinkInfo HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRTextLinkInfoCreateTextLinkInfo
 * @details Initial a FR_TextLinkInfo object.
 * @return   FR_TextLinkInfo
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_TextLinkInfo, FRTextLinkInfoCreateTextLinkInfo, ())

/**
 * @brief FRTextLinkInfoDeleteTextLinkInfo
 * @details 
 * @param[in]  info The input FR_TextLinkInfo object.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextLinkInfoDeleteTextLinkInfo, (FR_TextLinkInfo info))

/**
 * @brief FRTextLinkInfoGetPageIndex
 * @details 
 * @param[in]  info The input FR_TextLinkInfo object.
 * @return   FS_INT32
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRTextLinkInfoGetPageIndex, (FR_TextLinkInfo info))

/**
 * @brief FRTextLinkInfoGetLinkUrl
 * @details 
 * @param[in]  info The input FR_TextLinkInfo object.
 * @param[out]  wsUrl Get the link url.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextLinkInfoGetLinkUrl, (FR_TextLinkInfo info,  FS_WideString* wsUrl))

/**
 * @brief FRTextLinkInfoGetRectArray
 * @details 
 * @param[in]  info The input FR_TextLinkInfo object.
 * @param[out]  rectArr Get the rect of text link.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRTextLinkInfoGetRectArray, (FR_TextLinkInfo info,  FS_FloatRectArray* rectArr))

/**
 * @brief FRTextLinkInfoGetModifyDate
 * @details 
 * @param[in]  info The input FR_TextLinkInfo object.
 * @return   FS_DWORD
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_DWORD, FRTextLinkInfoGetModifyDate, (FR_TextLinkInfo info))

NumOfSelector(FRTextLinkInfo)
ENDENUM

//*****************************
/* TextLinkMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRTextLinkMgrIsEmailAddress
 * @details Check is email address.
 * @param[in]  csUrl The input url.
 * @return   FS_BOOL
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRTextLinkMgrIsEmailAddress, (FS_LPCWSTR csUrl))

/**
 * @brief FRTextLinkMgrGetLinkList
 * @details Get the list of links.
 * @param[in]  textPage The input FR_TextPage.
 * @param[out]  linkArr Get the link list.
 * @return   FS_BOOL    TRUE: Get the link success.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRTextLinkMgrGetLinkList, (FR_TextPage textPage,  FS_PtrArray* linkArr))

/**
 * @brief FRTextLinkMgrExecuteTextLink
 * @details Open the url of the link.
 * @param[in]  pLinkExt The input FR_TextLinkInfo.
 * @return   FS_BOOL
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRTextLinkMgrExecuteTextLink, (FR_TextLinkInfo pLinkExt))

NumOfSelector(FRTextLinkMgr)
ENDENUM

//*****************************
/* SelectedImageInfo HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRSelectedImageInfoGetImagePDFRect
 * @details Get pdf rect of the selected image.
 * @param[in]  imageInfo The input FR_SelectedImageInfo.
 * @return   FS_FloatRect
 * @note 
 */
INTERFACE(FS_FloatRect, FRSelectedImageInfoGetImagePDFRect, (FR_SelectedImageInfo imageInfo))

/**
 * @brief FRSelectedImageInfoGetParentForm
 * @details Get the parent form.
 * @param[in]  imageInfo The input FR_SelectedImageInfo.
 * @return   FPD_Form            Get the parent form.
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_Form, FRSelectedImageInfoGetParentForm, (FR_SelectedImageInfo imageInfo))

/**
 * @brief FRSelectedImageInfoGetObj
 * @details Open the url of the link.
 * @param[in]  imageInfo The input FR_SelectedImageInfo.
 * @param[in]  page The input FPD_Page.
 * @return   FS_BOOL
 * @note 
 */
INTERFACE(FPD_PageObject, FRSelectedImageInfoGetObj, (FR_SelectedImageInfo imageInfo,  FPD_Page page))

NumOfSelector(FRSelectedImageInfo)
ENDENUM

//*****************************
/* ContentObject HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRContentObjectCreateContentObject
 * @details Create FR_STRUCTCONTENT_OBJECT.
 * @return   FR_STRUCTCONTENT_OBJECT
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_STRUCTCONTENT_OBJECT, FRContentObjectCreateContentObject, ())

/**
 * @brief FRContentObjectDeleteContentObject
 * @details Release FR_STRUCTCONTENT_OBJECT.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRContentObjectDeleteContentObject, (FR_STRUCTCONTENT_OBJECT object))

/**
 * @brief FRContentObjectGetDocView
 * @details Get the docview.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @return   FR_DocView
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FR_DocView, FRContentObjectGetDocView, (FR_STRUCTCONTENT_OBJECT object))

/**
 * @brief FRContentObjectGetPageIndex
 * @details Get the page index.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @return   FS_INT32
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRContentObjectGetPageIndex, (FR_STRUCTCONTENT_OBJECT object))

/**
 * @brief FRContentObjectGetPos
 * @details Get the position of the object.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @return   FS_POSITION
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_POSITION, FRContentObjectGetPos, (FR_STRUCTCONTENT_OBJECT object))

/**
 * @brief FRContentObjectGetIsInFormXObject
 * @details Check whether it is a form object.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @return   FS_BOOL
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOL, FRContentObjectGetIsInFormXObject, (FR_STRUCTCONTENT_OBJECT object))

/**
 * @brief FRContentObjectGetFormLayer
 * @details Get the index arry of the graphic objects.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @param[out]  layerArr Get the index arry of the graphic objects.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRContentObjectGetFormLayer, (FR_STRUCTCONTENT_OBJECT object,  FS_Int32Array* layerArr))

/**
 * @brief FRContentObjectGetObj
 * @details Get the FPD_PageObject.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @return   FPD_PageObject
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_PageObject, FRContentObjectGetObj, (FR_STRUCTCONTENT_OBJECT object))

/**
 * @brief FRContentObjectGetObj2
 * @details Get the FPD_PageObject by FPD_Page.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @param[in]  pPDFPage The input FPD_Page.
 * @return   FPD_PageObject
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_PageObject, FRContentObjectGetObj2, (FR_STRUCTCONTENT_OBJECT object,  FPD_Page pPDFPage))

/**
 * @brief FRContentObjectGetContainer
 * @details Get the container of the object.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @return   FPD_GraphicsObjects
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_GraphicsObjects, FRContentObjectGetContainer, (FR_STRUCTCONTENT_OBJECT object))

/**
 * @brief FRContentObjectGetFormMatrix
 * @details Get the matrix of the object.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @param[in]  pPDFPage The input FPD_Page.
 * @return   FS_AffineMatrix
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FS_AffineMatrix, FRContentObjectGetFormMatrix, (FR_STRUCTCONTENT_OBJECT object,  FPD_Page pPDFPage))

/**
 * @brief FRContentObjectGetObjContainer
 * @details Get the object container.
 * @param[in]  pPage The input FPD_Page.
 * @param[in]  vecFormLayer The input index arry of the graphic objects.
 * @return   FPD_GraphicsObjects
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(FPD_GraphicsObjects, FRContentObjectGetObjContainer, (FPD_Page pPage,  FS_Int32Array vecFormLayer))

/**
 * @brief FRContentObjectSetDocView
 * @details Set the docview.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @param[in]  docview The input FR_DocView.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRContentObjectSetDocView, (FR_STRUCTCONTENT_OBJECT object,  FR_DocView docview))

/**
 * @brief FRContentObjectSetPageIndex
 * @details Get the page index.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @param[in]  nPageIndex The input page index.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRContentObjectSetPageIndex, (FR_STRUCTCONTENT_OBJECT object,  FS_INT32 nPageIndex))

/**
 * @brief FRContentObjectSetPos
 * @details Get the position of the object.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @param[in]  pos The input the position of the object.
 * @return   FS_POSITION
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRContentObjectSetPos, (FR_STRUCTCONTENT_OBJECT object,  FS_POSITION pos))

/**
 * @brief FRContentObjectSetIsInFormXObject
 * @details Set whether it is a form object.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @param[in]  bIsInFormXObject The input set whether it is a form object.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRContentObjectSetIsInFormXObject, (FR_STRUCTCONTENT_OBJECT object,  FS_BOOL bIsInFormXObject))

/**
 * @brief FRContentObjectSetFormLayer
 * @details Set the index arry of the graphic objects.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @param[in]  layerArr Set the index arry of the graphic objects.
 * @return   void
 * @note 
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRContentObjectSetFormLayer, (FR_STRUCTCONTENT_OBJECT object,  FS_Int32Array layerArr))

/**
 * @brief FRContentObjectSetTextRange
 * @details Set the text range arry of the graphic objects.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @param[in]  textRangeArr Set the text range arry of the graphic objects.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRContentObjectSetTextRange, (FR_STRUCTCONTENT_OBJECT object,  FS_PtrArray textRangeArr))

/**
 * @brief FRContentObjectGetTextRangeSize
 * @details Get the size of text range arry of the graphic objects.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRContentObjectGetTextRangeSize, (FR_STRUCTCONTENT_OBJECT object))

/**
 * @brief FRContentObjectGetTextRangeByIndex
 * @details Get the specified index of text range arry of the graphic objects.
 * @param[in]  object The input FR_STRUCTCONTENT_OBJECT.
 * @param[in]  index The input range index need to get.
 * @return   FR_TEXTRANGE
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 * @Deprecated    Internal use.
 */
INTERFACE(FR_TEXTRANGE, FRContentObjectGetTextRangeByIndex, (FR_STRUCTCONTENT_OBJECT object,  FS_INT32 index))

NumOfSelector(FRContentObject)
ENDENUM

//----------_V17----------
//*****************************
/* Accessible HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_Accessible, FRAccessibleNew, (FR_Annot pAnnot,  FR_PageView pPageView,  FR_AccessibleCallbacks callback))

INTERFACE(void, FRAccessibleDelete, (FR_Accessible  accessbile))

NumOfSelector(FRAccessible)
ENDENUM

//*****************************
/* PageObserver HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPageObserverCreatePageObserver
 * @details Encapsulat the IReader_Page::Observer to listen the object in plugin.
 * @param[in]  page The FR_Page object.
 * @return   FR_PageObserver.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FR_PageObserver, FRPageObserverCreatePageObserver, (FR_Page page))

/**
 * @brief FRPageObserverDestroyPageObserver
 * @details Destroy FR_PageObserver object.
 * @param[in]  observer The FR_PageObserver object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(void, FRPageObserverDestroyPageObserver, (FR_PageObserver observer))

/**
 * @brief FRPageObserverIsValid
 * @details Check is the FR_Page is valid.
 * @param[in]  observer The FR_PageObserver object.
 * @return   FS_BOOLEAN.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FS_BOOLEAN, FRPageObserverIsValid, (FR_PageObserver observer))

/**
 * @brief FRPageObserverGetPageObj
 * @details Get the FR_Page object of the observer.
 * @param[in]  observer The FR_PageObserver object.
 * @return   FR_Page.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @see 
 * @Deprecated    Internal use
 */
INTERFACE(FR_Page, FRPageObserverGetPageObj, (FR_PageObserver observer))

NumOfSelector(FRPageObserver)
ENDENUM

//*****************************
/* AnnotHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_AnnotHandler, FRAnnotHandlerGetAnnotHandlerByType, (FS_LPCSTR sType))

INTERFACE(FR_AnnotHandler, FRAnnotHandlerGetAnnotHandlerByAnnot, (FR_Annot pAnnot))

INTERFACE(FS_BOOLEAN, FRAnnotHandlerIsPermissionAllowed, (FR_AnnotHandler annotHandler,  FR_Document pDocument,  FS_LPCSTR sSubType))

INTERFACE(void, FRAnnotHandlerGetPropertyBoxTitle, (FR_AnnotHandler annotHandler,  FS_LPCSTR sSubType,  FS_WideString* outTitle))

INTERFACE(void, FRAnnotHandlerGetType, (FR_AnnotHandler annotHandler,  FS_ByteString* outType))

INTERFACE(void, FRAnnotHandlerGetName, (FR_AnnotHandler annotHandler,  FS_ByteString* outName))

NumOfSelector(FRAnnotHandler)
ENDENUM

//*****************************
/* WidgetAnnotHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_WidgetAnnotHandler, FRWidgetAnnotHandlerCreate, (FR_WidgetAnnotHandlerCallbacks callbacks))

INTERFACE(void, FRWidgetAnnotHandlerDelete, (FR_WidgetAnnotHandler handler))

INTERFACE(FS_BOOLEAN, FRWidgetAnnotHandlerOnGetCustomHightColor, (FR_WidgetAnnotHandler handler,  FR_Annot pAnnot,  FS_DWORD* fillcolorW))

INTERFACE(FS_BOOLEAN, FRWidgetAnnotHandlerOnIsShowQuickAccPropery, (FR_WidgetAnnotHandler handler,  FR_Annot pAnnot))

INTERFACE(FS_BOOLEAN, FRWidgetAnnotHandlerOnGetSignatureAuditTrail, (FR_WidgetAnnotHandler handler,  FPD_Object pAnnotDict,  FS_WideString* text))

INTERFACE(FS_BOOLEAN, FRWidgetAnnotHandlerOnGetSignatureHashInfo, (FR_WidgetAnnotHandler handler,  FPD_Object pAnnotDict,  FS_WideString* lastHash,  FS_WideString* currentHash))

INTERFACE(FS_BOOLEAN, FRWidgetAnnotHandlerOnIsShowSignaturePanelMenu, (FR_WidgetAnnotHandler handler,  FPD_Object pAnnotDict,  FS_INT32* nExData))

NumOfSelector(FRWidgetAnnotHandler)
ENDENUM

//*****************************
/* AnnotOperateHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_AnnotOperateHandler, FRAnnotOperateHandlerCreate, (FR_AnnotOperateHandlerCallbacks callbacks))

INTERFACE(void, FRAnnotOperateHandlerDelete, (FR_AnnotOperateHandler handler))

INTERFACE(FS_BOOLEAN, FRAnnotOperateHandlerOnMouseMsg, (FR_AnnotOperateHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  FR_AnnotMsgType emsgtype))

INTERFACE(FS_BOOLEAN, FRAnnotOperateHandlerOnCanMove, (FR_AnnotOperateHandler handler,  FR_PageView pPageView,  FR_Annot pAnnot,  FS_INT32 movetype,  FS_BOOLEAN* bCanMove))

INTERFACE(FS_BOOLEAN, FRAnnotOperateHandlerOnCanAnswer, (FR_AnnotOperateHandler handler,  FR_Annot pAnnot))

INTERFACE(FS_BOOLEAN, FRAnnotOperateHandlerCanCopy, (FR_AnnotOperateHandler handler,  FR_Annot pAnnot,  FS_INT32 pageIndex))

INTERFACE(FS_BOOLEAN, FRAnnotOperateHandlerOnLock, (FR_AnnotOperateHandler handler,  FR_Annot pAnnot,  FS_BOOLEAN bLock))

NumOfSelector(FRAnnotOperateHandler)
ENDENUM

//*****************************
/* BaseAnnot HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FRBaseAnnotSetAnnotMsgHook, (FR_AnnotOperateHandler pHandler))

INTERFACE(FR_AnnotOperateHandler, FRBaseAnnotGetAnnotMsgHookHandler, (FS_INT32 index))

INTERFACE(void, FRBaseAnnotRemoveAnnotMsgHook, (FR_AnnotOperateHandler hookHandler))

INTERFACE(FS_INT32, FRBaseAnnotGetAnnotMsgHookCount, ())

NumOfSelector(FRBaseAnnot)
ENDENUM

//*****************************
/* SaveAsNotify HFT functions */
//*****************************

BEGINENUM
INTERFACE(FR_Save_SaveAsNotify, FRSaveAsNotifyNew, (FR_SaveAsCallbacks callbacks))

INTERFACE(void, FRSaveAsNotifyDelete, (FR_Save_SaveAsNotify notify))

INTERFACE(FS_BOOLEAN, FRSaveAsNotifyIsSaveAsSaveTo, (FR_Save_SaveAsNotify notify,  FR_Document pRDoc))

INTERFACE(void, FRSaveAsNotifyGetSaveToDefaultName, (FR_Save_SaveAsNotify notify,  FR_Document pRDoc,  FS_WideString* saveName))

INTERFACE(FS_BOOLEAN, FRSaveAsNotifyIsNeedShowSaveDlg, (FR_Save_SaveAsNotify notify))

NumOfSelector(FRSaveAsNotify)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

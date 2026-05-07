/** @file fr_docImpl.h.
 * 
 *  @brief defined all interface associate with Foxit Reader document .
 */

#ifndef FR_DOCIMPL_H
#define FR_DOCIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../include/basic/fs_internalInc.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../../pdf/fpd_parserExpT.h"
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

#ifndef FR_APPEXPT_H
#include "../fr_appExpT.h"
#endif

#ifndef FPD_SERIALEXPT_H
#include "../../pdf/fpd_serialExpT.h"
#endif

#ifndef FPD_TEXTEXPT_H
#include "../../pdf/fpd_textExpT.h"
#endif


#include "../../../../BaseForm/include/IBaseForm.h"
#include "../../../BaseAnnot/include/BA_Accessible.h"

#ifdef __cplusplus
extern "C"{
#endif
	
class CFR_Doc_V1
{
public:
	//************************************
	// Function:  OpenFromFile
	// Param[in]: wszFile			The file path.
	// Param[in]: szPassword		The password with the file. It could be <a>NULL</a> if no password to pass.
	// Param[in]: bMakeVisible		Whether the document will be made visible.
	// Param[in]: bAddToMRU			Whether add the file path to the recent file list.
	// Return:	The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
	// Remarks: Opens and displays a document form a file.	  	
	// Notes: Do not open and then immediately close a FR_Document without letting least once event loop complete.
	// If you need to set more open options, suggest use FRDocOpenDocument, it suppports more option for openfile.
	// See: FRDocClose
	// See: FRDocOpenFromPDDoc
	// See: FRDocFromPDDoc
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use FRDocOpenDocument function instead.
	//************************************
	static FR_Document	OpenFromFile(FS_LPCWSTR wszFile, FS_LPCSTR szPassword, FS_BOOL bMakeVisible, FS_BOOL bAddToMRU);

	//************************************
	// Function:  OpenFromPDDoc
	// Param[in]: pddoc				The <a>FPD_Document</a> object to open.
	// Param[in]: lpwsTitle			It is used as window's title.
	// Return: The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
	// Remarks:	Opens and returns a <a>FR_Document</a> view of <a>PD_Document</a>.  	
	// Notes: Do not open and then immediately close a FR_Document without letting least once event loop complete.
	// If you need to set more open options, suggest use FRDocOpenDocument, it suppports more option for openfile.
	// <a>FRDocClose</a>() should be used in place of <a>FPDDocClose</a>() after FRDocOpenFromPDDoc() is called.
	// <a>FRDocClose</a>() will decrement the FPDDoc appropriately and free document-related resources.
	// See: FRDocClose
	// See: FRDocOpenFromFile
	// See: FRDocFromPDDoc
	//************************************
	static FR_Document	OpenFromPDDoc(FPD_Document pddoc, FS_LPCWSTR lpwsTitle);

	//************************************
	// Function:  FromPDDoc
	// Param[in]: pddoc				The <a>FR_Docuemnt</a> whose <a>FR_Document</a> is to be returned.
	// Return: The <a>FR_Docuemnt</a> if a  <a>FR_Docuemnt</a> is already opened for this <a>FPD_Document</a>, otherwise <a>NULL</a>.	
	// Remarks: Gets the  <a>FR_Docuemnt</a> associated with a <a>FPD_Document</a>.	  	
	// Notes:
	// See: FRDocOpenFromFile
	// See: FRDocOpenFromPDDoc
	// See: FRDocGetPDDoc
	//************************************
	static FR_Document	FromPDDoc(FPD_Document pddoc);

	//************************************
	// Function:  Close
	// Param[in]: doc				The document to close.
	// Param[in]: bPromptToSave		If <a>FALSE</a>, the document closed without prompting the user and without saving,
	// even if the document has been modified. If <a>TRUE</a>, it prompt the user to save the document if it has
	// been modified.
	// Param[in]: bDelay			Delay closing the document or not.
	// Param[in]: bShowCancel		If <a>FALSE</a>, it will not show cancle button when prompt to save.
	// Return:	<a>TRUE</a> if the document colsed, <a>FALSE</a> if it did not. The document will always close if 
	// <param>bPromptToSave</param> is <a>FALSE</a>.
	// Remarks: Closes the document window.  	
	// Notes:
	// See: FRDocOpenFromFile
	// See: FRDocOpenFromPDDoc
	//************************************
	static FS_BOOL		Close(FR_Document doc, FS_BOOL bPromptToSave, FS_BOOL bDelay, FS_BOOL bShowCancel);

	//************************************
	// Function:  GetPDDoc
	// Param[in]: doc			The document whose <a>FPD_Document</a> is obtained.
	// Return: The <a>FPD_Document</a> associated with <a>FR_Document</a>.
	// Remarks:	Gets the <a>FPD_Document</a> to associated with the specified <a>FR_Document</a>. 	
	// Notes:
	// See: FRDocFromPDDoc
	// See: FRDocOpenFromPDDoc
	// See: FRPageViewGetPDPage
	//************************************
	static FPD_Document	GetPDDoc(FR_Document doc);
	
	//************************************
	// Function:  SetCustomSecurity
	// Param[in]: doc				The input document.
	// Param[in]: encryptDict		The Encrypt dictionary.
	// Param[in]: cryptoHandler		The callbacks for crypto handler.
	// Param[in]: bEncryptMetadata	Whether to encrypt the metadata.
	// Param[in]: clientHandler		The user-supplied data.
	// Return:	void
	// Remarks:	 Sets security using custom security handler and custom encryption.
	// Application should provide a full encryption dictionary (application can destroy it after this call),
	// and a custom encryption handler. 	
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void				SetCustomSecurity(
								FR_Document doc, 
								FPD_Object encryptDict, 
								FR_CryptoCallbacks cryptoHandler, 
								FS_BOOL bEncryptMetadata,
								FS_LPVOID clientHandler);

	//************************************
	// Function:  DoSave
	// Param[in]: doc				The document to be saved.
	// Param[in]: proc				Callback function.
	// Param[in]: pProcData			The client data. It will be passed to the save callback function.
	// Param[in]: bShowProgressBar	Whether to show the progress bar or not.
	// Return: FS_BOOL             TRUE: save success.
	// Remarks:	Save the document.  	
	// Notes:
	// See: FRDocDoSaveAs
	// See: FRDocSetChangeMark
	//************************************
	static FS_BOOL			DoSave(FR_Document doc, FR_DocSaveProc proc, void* pProcData, FS_BOOL bShowProgressBar);

	//************************************
	// Function:  DoSaveAs
	// Param[in]: doc			The document.
	// Return:	void
	// Remarks: Displays a file save as dialog which can be used to save the document as a new name.	  	
	// Notes:
	// See: FRDocDoSave
	//************************************
	static void			DoSaveAs(FR_Document doc);
 
	//************************************
	// Function:  SetChangeMark
	// Param[in]: doc			The document.
	// Return:	void
	// Remarks: Sets the modify flag. Reader has a built-in flag that indicate whether a document has been modified,
	// if the value of the flag is valid, the Save button on File toolbar is enable, otherwise the Save button is 
	// disable.
	// Notes:
	// See: FRDocGetChangeMark
	// See: FRDocClearChangeMark
	//************************************
	static void				SetChangeMark(FR_Document doc);

	//************************************
	// Function:  GetChangeMark
	// Param[in]: doc		The document.
	// Return: <a>TRUE</a> if the document has been modified, <a>FALSE</a> if no change.
	// Remarks: Checks whether the document is modified.
	// Notes:
	// See: FRDocSetChangeMark
	// See: FRDocClearChangeMark
	//************************************
	static FS_BOOL			GetChangeMark(FR_Document doc);

	//************************************
	// Function:  ClearChangeMark
	// Param[in]: doc			The document.
	// Return:	void
	// Remarks:	Invalidates all modification.  	
	// Notes:
	// See: FRDocGetChangeMark
	// See: FRDocSetChangeMark
	//************************************
	static void				ClearChangeMark(FR_Document doc);

	//************************************
	// Function:  WillInsertPages
	// Param[in]: doc			The document to be inserted pages into.
	// Param[in]: iInserAt		The page index for first inserted page.
	// Param[in]: nCount		The page count for all inserted page.
	// Return:	void
	// Remarks:	The document will be inserted some pages. This notification will be broadcast to
   	// all plug-ins.
	// Notes: You can call this method before you start to insert some page into a FPD_Document object.<br>
	// The callback WillInsertPages() descriped in struct FR_DocEventCallbacksRec
	// will be called by Reader.
	// Deprecated: Internal use.
	//************************************
	static void				WillInsertPages(FR_Document doc, FS_INT32 iInserAt, FS_INT32 nCount);

	//************************************
	// Function:  DidInsertPages
	// Param[in]: doc			The document to be inserted pages into.
	// Param[in]: iInserAt		The page index for first inserted page.
	// Param[in]: nCount		The page count for all inserted page.
	// Return:	void
	// Remarks:	The document was inserted some pages. This notification will be broadcast to
   	// all plug-ins.
	// Notes: You can call this method after you inserted some page into a FPD_Document object.<br>
	// The callback DidInsertPages() descriped in struct FR_DocEventCallbacksRec
	// will be called by Reader.
	// Deprecated: Internal use.
	//************************************
	static void				DidInsertPages(FR_Document doc, FS_INT32 iInserAt, FS_INT32 nCount);

	//************************************
	// Function:  WillDeletePages
	// Param[in]: doc				The document whose page was deleted.
	// Param[in]: arrDelPage		The index of the pages that has been deleted.	
	// Return:	void
	// Remarks:	The document will delete any pages. This notification will be broadcast to
   	// all plug-ins.
	// Notes: You can call this method before you delete some page from a FPD_Document object.<br>
	// The callback WillDeletePages() descriped in struct FR_DocEventCallbacksRec
	// will be called by Reader.  	
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void				WillDeletePages(FR_Document doc, FS_WordArray arrDelPage);

	//************************************
	// Function:  DidDeletePages
	// Param[in]: doc				The document whose page was deleted.
	// Param[in]: arrDelPage		The index of the pages that has been deleted.
	// Return:	void
	// Remarks:	The document was deleted any pages. This notification will be broadcast to
   	// all plug-ins.
	// Notes: You can call this method after you deleted some page from a FPD_Document object.<br>
	// The callback DidDeletePages() descriped in struct FR_DocEventCallbacksRec
	// will be called by Reader.  	
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void				DidDeletePages(FR_Document doc, FS_WordArray arrDelPage);

	//************************************
	// Function:  WillRotatePage
	// Param[in]: doc				The document whose page's rotation attribute was modified.
	// Param[in]: iPage				The page index. 
	// Return:	void
	// Remarks:	The pages of <a>FR_Document</a> whose rotation attribute will be modified.  	
	// Notes: You can call this method before you want to change some page's rotation attribute.<br>
	// The callback WillModifyPageAttribute() descripted in struct FR_DocEventCallbacksRec
	// will be called by Reader. 
	// Deprecated: Internal use.
	//************************************
	static void			WillRotatePage(FR_Document doc, FS_INT32 iPage);

	//************************************
	// Function:  DidRotatePage
	// Param[in]: doc				The document whose page's rotation attribute was modified.
	// Param[in]: iPage				The page index. 
	// Return:	void
	// Remarks:	The page of <a>FR_Document</a> whose rotation attribute was modified.  	
	// Notes: You can call this method after you changed some page's rotation attribute.<br>
	// The callback DidModifyPageAttribute() descripted in struct FR_DocEventCallbacksRec
	// will be called by Reader. 
	// Deprecated: Internal use.
	//************************************
	static void				DidRotatePage(FR_Document doc, FS_INT32 iPage);

	//************************************
	// Function:  WillResizePage
	// Param[in]: doc				The document whose page's attribute was modified.
	// Param[in]: iPage				The page index.			
	// Return:	void
	// Remarks:	 The pages of <a>FR_Document</a> whose attribute will be modified.   	
	// Notes: You can call this method before you want to change some page's rotation attribute.<br>
	// The callback WillModifyPageAttribute() descriped in struct FR_DocEventCallbacksRec
	// will be called by Reader. 
	// Deprecated: Internal use.
	//************************************
	static void				WillResizePage(FR_Document doc, FS_INT32 iPage);

	//************************************
	// Function:  DidResizePage
	// Param[in]: doc				The document whose page's attribute was modified.
	// Param[in]: iPage				The page index.			
	// Return:	void
	// Remarks:	 The page of <a>FR_Document</a> whose attribute was modified.   	
	// Notes: You can call this method after you changed some page's rotation attribute.<br>
	// The callback DidModifyPageAttribute() descriped in struct FR_DocEventCallbacksRec
	// will be called by Reader. 
	// Deprecated: Internal use.
	//************************************
	static void				DidResizePage(FR_Document doc, FS_INT32 iPage);	 

	//************************************
	// Function:  DoPrint
	// Param[in]: doc			The document to print.
	// Return:	void  
	// Remarks: Performs the print operation, including user dialog box.  
	// Notes:	
	// See: FRDocPrintPages
	// See: FRDocDoPrintSilently
	// See: FRDocPrintSetup
	//************************************
	static void			DoPrint(FR_Document doc);

	//************************************
	// Function:  PrintPages
	// Param[in]: doc			The input document.
	// Param[in]: firstPage		The index of first page to be printed.
	// Param[in]: lastPage		The index of last page to be printed.
	// Return:	void  
	// Remarks:  Sets the first page and the last page to be printed.
	// Notes:	
	// See: FRDocDoPrint
	// See: FRDocDoPrintSilently
	//************************************
	static void			PrintPages(FR_Document doc, FS_INT32 firstPage, FS_INT32 lastPage);

	//************************************
	// Function:  PrintSetup
	// Param[in]: doc	The input document.
	// Return: void
	// Remarks: Sets up the print, it will show system print dialog.
	// Notes:	
	// See: FRDocDoPrint
	// See: FRDocDoPrintSilently
	// See: FRDocPrintPages
	// Notes: The function can only be used for Windows.
	//************************************
	static void			PrintSetup(FR_Document doc);

	//************************************
	// Function:  CountDocViews
	// Param[in]: doc			The document whose view count is obtained.
	// Return:  The number of <a>FR_DocView</a> for specified document.  
	// Remarks: Gets the number of <a>FR_DocView</a> for specified document.  
	// Notes:
	// See: FRDocGetDocView
	//************************************
	static FS_INT32		CountDocViews(FR_Document doc);

	//************************************
	// Function:  GetDocView
	// Param[in]: doc			The document whose document view is obtained.
	// Param[in]: iView			The index of a document view. The index range is 0 to (<a>FRDocCountDocViews</a>()-1).			
	// Return:  The specified <a>FR_DocView</a>.  
	// Remarks: Gets the specified <a>FR_DocView</a> for specified document.  
	// Notes:	
	// See: FRDocGetCurrentDocView
	// See: FRDocCountDocViews
	//************************************
	static FR_DocView	GetDocView(FR_Document doc, FS_INT32 iView);

	//************************************
	// Function:  GetCurrentDocView
	// Param[in]: doc			The document whose document view is obtained.			
	// Return:  The current showing <a>FR_DocView</a>.  
	// Remarks: Gets the current showing <a>FR_DocView</a> for specified document.  
	// Notes:	
	// See: FRDocGetDocView
	//************************************
	static FR_DocView	GetCurrentDocView(FR_Document doc);

	//************************************
	// Function:  GetPermissions
	// Param[in]: doc			The document whose user permission is obtained.
	// Return:  The document permissions. Result like FR_PERM_PRINT、FR_PERM_EXTRACT_COPY、FR_PERM_EXTRACT_ACCESS, etc.
	// Remarks: Gets permissions of a document.  
	// Notes:	
	// See: FRDocSetPermissions
	//************************************
	static FS_DWORD	GetPermissions(FR_Document doc);

	//************************************
	// Function:  SetPermissions
	// Param[in]: doc			The document whose user permission is set.
	// Param[in]: dwPermission	The new permission to set to the document, like FR_PERM_PRINT、FR_PERM_EXTRACT_COPY、FR_PERM_EXTRACT_ACCESS, etc.
	// Return:  void  
	// Remarks: Sets permissions to a document. That used for encrypt plugin to set the Permission of a document to frDoc,
	// and the permission will be saved in encrypt plugin.
	// Notes:	
	// See: FRDocGetPermissions
	//************************************
	static void	SetPermissions(FR_Document doc, FS_DWORD dwPermission);

	//************************************
	// Function:  GetFilePath
	// Param[in]: doc			The document whose file path is set.
	// Param[in/out]: path		A wide string object to receive the file path.
	// Return:  void  
	// Remarks: Gets the file path of a document opened by Foxit Reader.  
	// Notes:	
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use GetOpenFilePath functions instead.
	//************************************
	static void GetFilePath(FR_Document doc, FS_WideString* path);

	//************************************
	// Function:  SetCurSelection
	// Param[in]: doc			The input document.
	// Param[in]: type			The input type of the selection handler. The type name you can define in your plugin, it presents the object type.
	// Param[in]: pSelectData	The selection data.
	// Return:    <a>TRUE</a> means successful, otherwise not.
	// Remarks: Sets the current selection handler by type. 
	// To set selection data, used to copy、cut、delete the object.
	// Notes:	
	//************************************
	static FS_BOOL SetCurSelection(FR_Document doc, FS_LPSTR type, void* pSelectData);

	//************************************
	// Function:  AddToCurrentSelection
	// Param[in]: doc		The input document.
	// Param[in]: pCurData	The current selection data.
	// Param[in]: pAddData  The data to be added to the current selection handler.
	// Return:    The updated selection data. It is <a>NULL</a> if failed.
	// Remarks:   Adds the new data to the current selection data and returns the updated one.
	// Notes:	
    // Deprecated:  Current function has been deprecated, it not be implemented.
	//************************************
	static void* AddToCurrentSelection(FR_Document doc, void* pCurData, void* pAddData);

	//************************************
	// Function:  RemoveFromSelection
	// Param[in]: doc		The input document.
	// Param[in]: pCurData	The current selection data.
	// Param[in]: pRemData	The data to be removed from the current selection data.
	// Return:    The updated selection data. It is <a>NULL</a> if failed.
	// Remarks:	  Removes some data from the current selection data and returns the updated one.
	// Notes:	
	 //Deprecated:  Current function has been deprecated, it not be implemented.
	//************************************
	static void* RemoveFromSelection(FR_Document doc, void* pCurData, void* pRemData);

	//************************************
	// Function:  GetCurSelection
	// Param[in]: doc	The input document.
	// Return:    The current selection data.
	// Remarks:	  Gets the current selection data.
	// Notes:	
	//************************************
	static void* GetCurSelection(FR_Document doc);

	//************************************
	// Function:  GetCurSelectionType
	// Param[in]: doc	The input document.
	// Return:    The type of the current selection data.
	// Remarks:   Gets the type of the current selection data.
	// Notes:	
	//************************************
	static FS_LPCSTR GetCurSelectionType(FR_Document doc);

	//************************************
	// Function:  ShowSelection
	// Param[in]: doc	The input document.
	// Return:  void  
	// Remarks:	Displays the current selection by calling the selection handler's <a>FRSelectionShowSelection</a>() 
	// callback. It does nothing if the document has no selection, or the current selection's handler has no 
	// <a>FRSelectionShowSelection</a>()  callback.
	// It only raises those exceptions raised by the selection handler's <a>FRSelectionShowSelection</a>() callback.
	// Notes:	
	//************************************
	static void ShowSelection(FR_Document doc);

	//************************************
	// Function:  ClearSelection
	// Param[in]: doc	The input document.
	// Return:  void  
	// Remarks: Clears the current selection object by the current selection handler.
    // <a>FRSelectionLosingSelection</a>().
	// Notes:	
	//************************************
	static void ClearSelection(FR_Document doc);

	//************************************
	// Function:  DeleteSelection
	// Param[in]: doc	The input document.
	// Return:  void  
	// Remarks: Deletes the specified document's current selection object, if possible. The selection is deleted if changing the 
	// selection is currently permitted, the selection handler has an <a>FRSelectionDoDelete</a>() callback, and the 
	// selection server's <a>FRSelectionCanDelete</a>() callback returns <a>TRUE</a>. If the selection handler does not 
	// have a <a>FRSelectionCanDelete</a>() callback, a default value of <a>TRUE</a> is used.
	// The selection is deleted by calling the selection handler's <a>FRSelectionDoDelete</a>() callback. 
	// It only raises those exceptions raised by the selection handler's <a>FRSelectionDoDelete</a>() and 
    // <a>FRSelectionCanDelete</a>() callbacks.
	// Notes:	
	//************************************
	static void DeleteSelection(FR_Document doc);

	//************************************
	// Function:  CopySelection
	// Param[in]: doc	The input document.
	// Return:  void  
	// Remarks: Copies the current selection to the clipboard, if possible. The selection is copied if the selection handler has 
	// a <a>FRSelectionDoCopy</a>() callback, and the selection handler's <a>FRSelectionCanCopy</a>() callback 
	// returns <a>TRUE</a>. If the selection server does not have a <a>FRSelectionCanCopy</a>() method, a default 
	// value of <a>TRUE</a> is used.
	// The selection is copied by calling the selection handler's <a>FRSelectionDoCopy</a>() callback. 
	// It only raises those exceptions raised by the selection handler's <a>FRSelectionDoCopy</a>() and 
    // <a>FRSelectionCanCopy</a>() callbacks.
	// Notes:	
	//************************************
	static void CopySelection(FR_Document doc);
	
	//************************************
	// Function:  SetCurCapture
	// Param[in]: doc		The input document.
	// Param[in]: type		The type of the capture handler.
	// Param[in]: pCapData	The capture data.
	// Return:    <a>TRUE</a> means successful, otherwise not.
	// Remarks: Set the current capture handler by type.
	// Set the capture data, use to move、resize、show menu of the data.
	// Notes:	
	//************************************
	static FS_BOOL SetCurCapture(FR_Document doc, FS_LPSTR type, void* pCapData);

	//************************************
	// Function:  GetCurCapture
	// Param[in]: doc	The input document.
	// Return:    The current capture data.
	// Remarks:   Gets the current capture data.
	// Notes:	
	//************************************
	static void* GetCurCapture(FR_Document doc);

	//************************************
	// Function:  GetCurCaptureType
	// Param[in]: doc	The input document.
	// Return:    The type of the current capture handler.
	// Remarks:   Gets the type of the current capture handler.
	// Notes:	
	//************************************
	static FS_LPCSTR GetCurCaptureType(FR_Document doc);

	//************************************
	// Function:  ReleaseCurCapture
	// Param[in]: doc	The input document.
	// Return:  void  
	// Remarks:	Releases the current capture.
	// Notes:	
	//************************************
	static void ReleaseCurCapture(FR_Document doc);	

	//************************************
	// Function:  SetMenuEnableByName
	// Param[in]: doc		The input document.
	// Param[in]: csName	The menu you want to control.
	// Param[in]: bEnable	Whether the menu is enable or not.
	// Return:  void  
	// Remarks:	Set the menu enable or not. Like FR_MENU_ENABLE_SAVEAS.
	// It used for some permisson document, you can control some menu if can be enable by this api.
	// Notes:	
	// Deprecated: Internal use.
	//************************************
	static void SetMenuEnableByName(FR_Document doc, FS_LPCSTR csName, FS_BOOL bEnable);	

	//************************************
	// Function:  GetParser
	// Param[in]: doc		The input document.
	// Return:  A PDF file parser associated with current document.  
	// Remarks:	Gets the PDF file parser which is parsing current document.
	// Notes:	
	//************************************
	static FPD_Parser GetParser(FR_Document doc);

	//************************************
	// Function:  GetPDFCreator
	// Param[in]: doc		The input document.
	// Return:  A PDF creator associated with current document.  
	// Remarks:	Gets the PDF creator associated with current document.
	// Notes:	
	//************************************
	static FPD_Creator GetPDFCreator(FR_Document doc);

	//************************************
	// Function:  DoPrintSilently
	// Param[in]: doc			The document to print.
	// Return:	void  
	// Remarks: Performs the print operation, not including user dialog box.  
	// Notes:	
	// See: FRDocPrintPages
	// See: FRDocPrintSetup
	//************************************
	static void			DoPrintSilently(FR_Document doc);

	//************************************
	// Function:  GetTextSelectTool
	// Param[in]: doc			The document object.
	// Return:	The <a>FR_TextSelectTool</a> object of the <param>doc</param>.
	// Remarks: Gets the current text select tool for specified document. It same with FRTextSelectToolCreate.  
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FR_TextSelectTool GetTextSelectTool(FR_Document doc);

	//************************************
	// Function:  GetDocumentType
	// Param[in]: doc The document to get the type.
	// Return:	The type of the document. Like FR_DOCTYPE_PDF, FR_DOCTYPE_DYNIMIC_XFA, FR_DOCTYPE_STATIC_XFA.
	// Remarks: Get the type of the document.  
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRDocTypes
	//************************************
	static FS_INT32 GetDocumentType(FR_Document doc);

	//************************************
	// Function:  CanSecurityMethodBeModified
	// Param[in]: doc			The document.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Whether the security applied to the document can be modified or not.	  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterSecurityMethod
	//************************************
	static FS_BOOL CanSecurityMethodBeModified(FR_Document doc);

	//************************************
	// Function:  UpdateSecurityMethod
	// Param[in]: doc			The document.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Remove the security of the document. When this interface is invoked, the <a>FRSecurityMethodRemoveSecurityInfo</a> will be invoked if the document is encrypted.
	// It used for non-standard document, like RMS、AIP、Fasoo DRM security.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterSecurityMethod
	//************************************
	static FS_BOOL UpdateSecurityMethod(FR_Document doc);

	//************************************
	// Function:  IsEncrypted
	// Param[in]: doc			The document.
	// Return: <a>TRUE</a> for the document being encrypted, otherwise not.
	// Remarks: Check if the document is encrypted. When this interface is invoked, the <a>FRSecurityMethodIsMyMethod</a> will be invoked.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterSecurityMethod
	//************************************
	static FS_BOOL IsEncrypted(FR_Document doc);

	//************************************
	// Function:  RemoveSecurityMethod
	// Param[in]: doc			The document.
	// Return: <a>TRUE</a> for the security method of the document being removed, otherwise not.
	// Remarks: Remove the security of the document. When this interface is invoked, the <a>FRSecurityMethodRemoveSecurityInfo</a> will be invoked.
	// It used for standard document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterSecurityMethod
	//************************************
	static FS_BOOL RemoveSecurityMethod(FR_Document doc);

	//************************************
	// Function:  EnableRunScript
	// Param[in]: doc			The document.
	// Param[in]: bIsEnable		Whether the document can run script.
	// Return: void.
	// Remarks: Whether the document can run script.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use.
	//************************************
	static void EnableRunScript(FR_Document doc, FS_BOOL bIsEnable);

	//************************************
	// Function:  IsEnableRunScript
	// Param[in]: doc			The document.
	// Return: Whether the document can run script.
	// Remarks: Whether the document can run script.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsEnableRunScript(FR_Document doc);

	//************************************
	// Function:  ChangeDocShowTitle
	// Param[in]: doc				The document.
	// Param[in]: lpwsShowTitle		This value will be shown as the main frame title and the document tab title.
	// Return: void.
	// Remarks: Sets the main frame title and the document tab title.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use.
	//************************************
	static void ChangeDocShowTitle(FR_Document doc, FS_LPCWSTR lpwsShowTitle);

	//************************************
	// Function:  IsMemoryDoc
	// Param[in]: doc				The document.
	// Return: Whether the document is a memory document or not.
	// Remarks: Whether the document is a memory document or not. 
	// Memory doc like from createPDF、open from word、extract pages to doc.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL IsMemoryDoc(FR_Document doc);

	//************************************
	// Function:  GetCurrentSecurityMethodName
	// Param[in]: doc				The document.
	// Param[out]: outName			It receives the name of current security method.
	// Return: The name of current security method. Like "password encrytion"
	// Remarks: Gets the name of current security method. 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void GetCurrentSecurityMethodName(FR_Document doc, FS_WideString* outName);

	//************************************
	// Function:  GetCurrentWndProvider
	// Param[in]: doc				The document.
	// Return: The pointer to the current window provider.
	// Remarks: Gets the current window provider. Like portfolio, textview window provider.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterWndProvider
	// Deprecated: Internal use.
	//************************************
	static void* GetCurrentWndProvider(FR_Document doc);

	//************************************
	// Function:  SetCurrentWndProvider
	// Param[in]: doc			The document.
	// Param[in]: pProvider		The input window provider.
	// Return: void
	// Remarks: Sets the window provider. It used for show own windows in your plugin.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterWndProvider
	// Deprecated: Internal use.
	//************************************
	static void SetCurrentWndProvider(FR_Document doc, void* pProvider);

	//************************************
	// Function:  GetWndProviderByName
	// Param[in]: doc				The document.
	// Param[in]: lpsName			The Specified name of the window provider.
	// Return: The window provider.
	// Remarks: Gets the window provider by name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegisterWndProvider
	// Deprecated: Internal use.
	//************************************
	static void* GetWndProviderByName(FR_Document doc, FS_LPCSTR lpsName);

	//************************************
	// Function:  GetReviewType
	// Param[in]: doc				The document.
	// Return: The review type.
	// Remarks: Gets the review type. 0: normal, 1:share/cloud, 2:email,5: review.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use
	//************************************
	static FS_INT32 GetReviewType(FR_Document doc);

	//************************************
	// Function:  SetReviewType
	// Param[in]: doc				The document.
	// Param[in]: nType				The input review type.
	// Return: void.
	// Remarks: Sets the review type.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use
	//************************************
	static void SetReviewType(FR_Document doc, FS_INT32 nType);

	//************************************
	// Function:  SetAppPermissions
	// Param[in]: doc			The document whose user permission is obtained.
	// Param[in]: dwPermission	The input application permission. like FR_PERM_MODIFY_CONTENT.
	// Return: void
	// Remarks: Sets the application permission.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void SetAppPermissions(FR_Document doc, FS_DWORD dwPermission);

	//************************************
	// Function:  GetAppPermissions
	// Param[in]: doc			The document whose user permission is obtained.
	// Param[in]: iPermission	The specified permission.
	// Return: <a>TRUE</a> if the user has the specified application permission.
	// Remarks: Checks whether the user has the specified application permission or not.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL GetAppPermissions(FR_Document doc, FS_INT32 iPermission);

	//************************************
	// Function:  GetAppPermissionsII
	// Param[in]: doc			The document whose user permission is obtained.
	// Return: The application permissions. Like FR_PERM_MODIFY_CONTENT.
	// Remarks: Gets the application permissions.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_DWORD GetAppPermissionsII(FR_Document doc);

	//************************************
	// Function:  GetPermissionsII
	// Param[in]: doc			The document whose user permission is obtained.
	// Param[in]: iPermission	The input permission to check.
	// Return:  <a>TRUE</a> means the document has the permission, otherwise not. 
	// Remarks: Checks whether the document has the permission.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL GetPermissionsII(FR_Document doc, FS_INT32 iPermission);

	//************************************
	// Function:  GetMergedPermissions
	// Param[in]: doc			The document whose user permission is obtained.
	// Param[in]: iPermission	The specified permission.
	// Return: <a>TRUE</a> means the document has the permission, otherwise not.
	// Remarks: Checks whether the document has the permission. It will check doc permisson and app permisson together.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL GetMergedPermissions(FR_Document doc, FS_INT32 iPermission);

	//************************************
	// Function:  KillFocusAnnot
	// Param[in]: doc			The document.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Kills the focus annot, set current focus annot with null.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL KillFocusAnnot(FR_Document doc);

	//************************************
	// Function:  SetPropertiesPDFVersion
	// Param[in]: doc				The document.
	// Param[in]: lpwsPDFVersion	The input PDF version that will be shown in the properties dialog.
	// Return: void
	// Remarks: Sets the PDF version that will be shown in the properties dialog, that will not be write to PDF.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// Deprecated: Internal use.
	//************************************
	static void SetPropertiesPDFVersion(FR_Document doc, FS_LPCWSTR lpwsPDFVersion);

	//************************************
	// Function:  SetPropertiesFilePath
	// Param[in]: doc			The document.
	// Param[in]: lpwsFilePath	The input file path that will be shown in the properties dialog.
	// Return: void
	// Remarks: Sets the file path that will be shown in the properties dialog.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// Deprecated: Internal use.
	//************************************
	static void SetPropertiesFilePath(FR_Document doc, FS_LPCWSTR lpwsFilePath);

	//************************************
	// Function:  DoSaveAs2
	// Param[in]: doc				The document.
	// Param[in]: pwszFilePath		The path where the document to be saved as.
	// Param[in]: proc				Callback function.
	// Param[in]: pProcData			The client data. It will be passed to the save-as callback function.
	// Param[in]: bSaveAsTempFile	Sets it FALSE as default.
	// Param[in]: bShowProgressBar	Whether to show the progress bar or not.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Displays a file dialog box which can be used to save the document as a new name.	  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1
	// See: FR_DocSaveAsProc
	// Deprecated: Current function has been deprecated , so not recommend to use current function any more. User can use FRDocDoSaveAs3 function. 
	//************************************
	static FS_BOOL	DoSaveAs2(FR_Document doc, FS_LPCWSTR pwszFilePath, FR_DocSaveAsProc proc, void* pProcData, FS_BOOL bSaveAsTempFile, FS_BOOL bShowProgressBar);

	//************************************
	// Function:  ShowSaveProgressCancelButton
	// Param[in]: doc				The document.
	// Param[in]: bShow				Whether to show the save progress cancel button.	
	// Return: void.
	// Remarks: Sets to show the save progress cancel button or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1
	//************************************
	static void ShowSaveProgressCancelButton(FR_Document doc, FS_BOOL bShow);

	//************************************
	// Function:  SetInputPasswordProc
	// Param[in]: doc		The input document.
	// Param[in]: proc		Prototype of callback function invoked by <Italic>Foxit Reader</Italic> to receive the password.
	// Return: void.
	// Remarks: Sets the prototype of callback function invoked by <Italic>Foxit Reader</Italic> to receive the password.	
	// Usually SetInputPasswordProc in FRConProviderOnFileOpen.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.2
	// See: FRConProviderOnFileOpen
	//************************************
	static void SetInputPasswordProc(FR_Document doc, FRInputPasswordProc proc);

	//************************************
	// Function:  CheckInDocumentOLE
	// Param[in]: doc		The input document.
	// Return: True means the document is opened by OLE.
	// Remarks: Checks whether the document is opened by OLE. For example, the document is embedded	in <Italic>MS Office Word</Italic>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL CheckInDocumentOLE(FR_Document doc);

	//************************************
	// Function:  IsShowInBrowser
	// Param[in]: doc		The input document.
	// Return: True means the document is opened in browser.
	// Remarks: Checks whether the document is opened in browser.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsShowInBrowser(FR_Document doc);

	//************************************
	// Function:  GetUIParentWnd
	// Param[in]: doc		The input document.
	// Return: A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>.
	// Remarks: Gets the UI parent window.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void* GetUIParentWnd(FR_Document doc);

	//************************************
	// Function:  GetDocFrameHandler
	// Param[in]: doc		The input document.
	// Return: The frame handler associated with the document.
	// Remarks: Gets the frame handler associated with the document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static HWND GetDocFrameHandler(FR_Document doc);

	//************************************
	// Function:  CreateNewViewByWndProvider
	// Param[in]: doc		The input document.
	// Param[in]: lpsName	The Specified name of the window provider.
	// Return: void.
	// Remarks: Creates the new view by <a>FR_WndProviderCallbacksRec</a>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: FRAppRegisterWndProvider
	// Deprecated: Internal use.
	//************************************
	static void CreateNewViewByWndProvider(FR_Document doc, FS_LPCSTR lpsName);

	//************************************
	// Function:  LoadAnnots
	// Param[in]: doc			The input document.
	// Param[in]: arrAnnotDict	The pointer array holding the annotation dictionaries to be loaded.
	// Return: Non-zero means success, otherwise failure.
	// Remarks: Loads annotation(s) for an opening PDF document. 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL LoadAnnots(FR_Document doc, FS_PtrArray arrAnnotDict);

	//************************************
	// Function:  GetDocShowTitle
	// Param[in]: doc				The document.
	// Param[out]: outTitle			It receives the title shown as the main frame title and the document tab title.
	// Return: void.
	// Remarks: Gets the title shown as the main frame title and the document tab title.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use FRDocGetTabTitle function instead.
	//************************************
	static void GetDocShowTitle(FR_Document doc, FS_WideString* outTitle);

	//************************************
	// Function:  DoSave2
	// Param[in]: doc				The document to be saved.
	// Param[in]: proc				Callback function.
	// Param[in]: pProcData			The client data. It will be passed to the save callback function.
	// Param[in]: bShowProgressBar	Whether to show the progress bar or not.
	// Param[in]: bDoPDFOptimize	Whether to optimize the PDF or not.
	// Return: True for success, otherwise failure.
	// Remarks:	Saves a file, handling any user interface(for example, a Save File dialog box) if need.  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
	// See: FRDocDoSave
	// See: FRDocDoSaveAs
	// See: FRDocSetChangeMark
	//************************************
	static FS_BOOL DoSave2(FR_Document doc, FR_DocSaveProc proc, void* pProcData, FS_BOOL bShowProgressBar, FS_BOOL bDoPDFOptimize);

	//************************************
	// Function:  ResetDocTitleColor
	// Param[in]: doc				The input document.
	// Return: void
	// Remarks:	Resets the document title color in the document tab.  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
	// See: FRDocSetDocTitleColor
	//************************************
	static void ResetDocTitleColor(FR_Document doc);

	//************************************
	// Function:  SetDocTitleColor
	// Param[in]: doc				The input document.
	// Param[in]: clrDocTitle		The input color value.
	// Return: void
	// Remarks:	Sets the document title color in the document tab.  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
	// See: FRDocResetDocTitleColor
	//************************************
	static void SetDocTitleColor(FR_Document doc, FS_COLORREF clrDocTitle);

	//************************************
	// Function:  GetOriginalType
	// Param[in]: doc				The input document.
	// Return: The original type of the document. The real format of the opened document is PDF, but its wrapper format may be PPDF.
	// Remarks:	Gets the original type of the document. The real format of the opened document is PDF, but its wrapper format may be PPDF.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
	// See: FRDocSetOriginalType
	//************************************
	static FROriginalDocType GetOriginalType(FR_Document doc);

	//************************************
	// Function:  SetOriginalType
	// Param[in]: doc			The input document.
	// Param[in]: oriDocType	The input original type of the document.
	// Return: void.
	// Remarks:	Sets the original type of the document. The real format of the opened document is PDF, but its wrapper format may be PPDF.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
	// See: FRDocGetOriginalType
	//************************************
	static void SetOriginalType(FR_Document doc, FROriginalDocType oriDocType);

	//************************************
	// Function:  SetFocusAnnot
	// Param[in]: doc				The input document.
	// Param[in]: pFocusAnnot		The input annotation.
	// Param[in]: bDelay			Whether to delay the setting or not. The default value is FALSE.
	// Return: void
	// Remarks:	Sets the focus annotation.  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	//************************************
	static FS_BOOL SetFocusAnnot(FR_Document doc, FR_Annot pFocusAnnot, FS_BOOL bDelay);

	//************************************
	// Function:  GenerateUR3Permission
	// Param[in]: doc				The input document.
	// Return: TRUE for success, otherwise failure.
	// Remarks:	Generates the UR3 signature. Usage rights signatures are used to enable additional interactive features that are not available by
	// default in a particular viewer application (such as Adobe Reader). See PDF reference for more details.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// Deprecated: Internal use. It's not implement.
	//************************************
	static FS_BOOL	GenerateUR3Permission(FR_Document doc);

	//************************************
	// Function:  HasRedactAnnot
	// Param[in]: doc		The input document.
	// Return: TRUE: The document has redact annot.
	// Remarks:	Checks whether the document has redact annot.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	//************************************
	static FS_BOOL HasRedactAnnot(FR_Document doc);

	//************************************
	// Function:  GenerateRedactions
	// Param[in]: doc			The input document.
	// Param[out]: wsFilePath	It receives the path of the document redacted, it is temp file path, you can copy or delete it.	
	// Return: TRUE for success, otherwise for failure.
	// Remarks: Generates a redacted document and it will be saved to <param>wsFilePath</param>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	//************************************
	static FS_BOOL GenerateRedactions(FR_Document doc, FS_WideString* wsFilePath);

	//************************************
	// Function:  ReloadPage
	// Param[in]: doc			The input document.
	// Param[in]: iPage			The specified page index.
	// Param[in]: bDisableGoto	Whether to prevent going to the specified page view. Sets it FALSE as default.
	// Return: TRUE for success, otherwise for failure.
	// Remarks: Reloads the specified page, used to refresh page view.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	//************************************
	static FS_BOOL ReloadPage(FR_Document doc, FS_INT32 iPage, FS_BOOL bDisableGoto);

	//************************************
	// Function:  ForbidChangeMark
	// Param[in]: doc			The document.
	// Param[in]: bForbid		Whether to forbid setting the modify flag or not.
	// Return:	void
	// Remarks: Forbid setting the modify flag. Reader has a built-in flag that indicate whether a document has been modified,
	// if the value of the flag is valid, the Save button is enable, otherwise the Save button is 
	// disable.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.0.0
	// See: FRDocSetChangeMark
	// See: FRDocGetChangeMark
	// See: FRDocClearChangeMark
	//************************************
	static void ForbidChangeMark(FR_Document doc, FS_BOOL bForbid);

	//************************************
	// Function:  OpenFromPDDoc2
	// Param[in]: pddoc				The <a>FPD_Document</a> object to open.
	// Param[in]: lpwsTitle			It is used as window's title.
	// Param[in]: bDelPDFDoc		Whether the framework must delete the <a>FPD_Document</a> object or not. If the plug-in 
	// deletes the <a>FPD_Document</a> object through <a>FPDParserDestroy</a>(), sets it FALSE.
	// Return: The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
	// Remarks:	Opens and returns a <a>FR_Document</a> view of <a>PD_Document</a>.  	
	// Notes: Do not open and then immediately close a FR_Document without letting least once event loop complete.
	// <a>FRDocClose</a>() should be used in place of <a>FPDDocClose</a>() after FRDocOpenFromPDDoc() is called.
	// <a>FRDocClose</a>() will decrement the FPDDoc appropriately and free document-related resources.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	// See: FRDocClose
	// See: FRDocOpenFromFile
	// See: FRDocFromPDDoc
	//************************************
	static FR_Document	OpenFromPDDoc2(FPD_Document pddoc, FS_LPCWSTR lpwsTitle, FS_BOOL bDelPDFDoc);

	//************************************
	// Function:  GetCreateDocSource
	// Param[in]: doc			The document.
	// Return:	The source type of the document.
	// Remarks: Gets the source type of the document. Like from Multiple Files、SCANNER 、From Scanner.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	// Deprecated: Internal use.
	//************************************
	static FRCreateDocSource GetCreateDocSource(FR_Document doc);

	//************************************
	// Function:  SetCreateDocSource
	// Param[in]: doc					The document.
	// Param[in]: sourceType			The input source type of the document.
	// Param[in]: lpwsSourceFileName	The input source file name.	
	// Return:	void.
	// Remarks: Sets the source type of the document.It used to named pdf in Scanner.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	// Deprecated: Internal use.
	//************************************
	static void SetCreateDocSource(FR_Document doc, FRCreateDocSource sourceType, FS_LPCWSTR lpwsSourceFileName);

	//************************************
	// Function:  GetCreateDocSourceFileName
	// Param[in]: doc					The document.
	// Param[out]: outSourceFileName	It receives the source file name.
	// Return:	void.
	// Remarks: Gets the create source file name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	// Deprecated: Internal use.
	//************************************
	static void GetCreateDocSourceFileName(FR_Document doc, FS_WideString* outSourceFileName);

	//************************************
	// Function:  ParsePage
	// Param[in]: doc			The document.
	// Param[in]: nPageIndex	The specified page index.
	// Return:	TRUE for success, otherwise failure.
	// Remarks: Parses the specified page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	//************************************
	static FS_BOOL ParsePage(FR_Document doc, FS_INT32 nPageIndex);

	//************************************
	// Function:  IsValidAnnot
	// Param[in]: doc			The document.
	// Param[in]: frAnnot		The input annotation to be checked.
	// Return:	TRUE if the annotation is valid.
	// Remarks: Checks whether the annotation is valid or not. Actually check the annot if in the document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	//************************************
	static FS_BOOL IsValidAnnot(FR_Document doc, FR_Annot frAnnot);

	//************************************
	// Function:  IsWillReopen
	// Param[in]: doc			The document.
	// Return:	TRUE if the document is to be reopened.
	// Remarks: Checks whether the document is to be reopened after it is closed.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0.2
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsWillReopen(FR_Document doc);

	//************************************
	// Function:  OpenFromFile2
	// Param[in]: wszFile				The file path.
	// Param[in]: szPassword			The password with the file. It could be <a>NULL</a> if no password to pass.
	// Param[in]: bMakeVisible			Whether the document will be made visible.
	// Param[in]: bAddToMRU				Whether add the file path to the recent file list.
	// Param[in]: bCheckCertPassword	Whether prompt a password input dialog to check the password of the certificate used to encrypt the document.
	// Return:	The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
	// Remarks: Opens and displays a document form a file.	  	
	// Notes: Do not open and then immediately close a FR_Document without letting least once event loop complete.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
	// See: FRDocClose
	// See: FRDocOpenFromPDDoc
	// See: FRDocFromPDDoc
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use FRDocOpenDocument function instead.
	//************************************
	static FR_Document OpenFromFile2(FS_LPCWSTR wszFile, FS_LPCSTR szPassword, FS_BOOL bMakeVisible, FS_BOOL bAddToMRU, FS_BOOL bCheckCertPassword);

	//************************************
	// Function:  GetSignaturePermissions
	// Param[in]: doc				The document whose user permission is obtained.
	// Param[out]: pdwPermissions	The document permissions.  
	// Return:  <a>TRUE</a> if the document is signed.
	// Remarks: Gets the signature permissions of a document.  
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.2.1
	//************************************
	static FS_BOOL	GetSignaturePermissions(FR_Document doc, FS_DWORD *pdwPermissions);

	//************************************
	// Function:  ConvertPdfToOtherFormat
	// Param[in]: wsSrcPath			The source file which need to be converted. The souce file must be opened by editor.
	// Param[in]: wsDesPath			The destination file path.
	// Param[in]: pageAry			The pages need to be converted. if it is NULL ,will convert the whole document. 
	// Param[in]: wsFileExt			The format need to be convert. Support: docx, doc, xlsx, xls, html, pptx, rtf.
	// Param[in]: wsPwd				The password of encrypt the document. if it is empty, will not encrypt the document.
	// Param[in]: bShowProgress		Whether or not show the convert progress bar.
	// Return:  <a>TRUE</a> converted sucessful.
	// Remarks: Convert Pdf document to other format document.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static FS_BOOL	ConvertPdfToOtherFormat(FS_LPCWSTR wsSrcPath, FS_LPCWSTR wsDesPath, FS_DWordArray pageAry, FS_LPCWSTR wsFileExt, FS_LPCWSTR wsPwd, FS_BOOL bShowProgress);

	//************************************
	// Function:  DoPassWordEncrypt
	// Param[in]: frDoc			The document to protected.
	// Param[in]: proc			Prototype of callback function invoked by <Italic>Foxit Reader</Italic> to receive the protecting status.
	// Return:  void.
	// Remarks: Set the document password through the password input dialog.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	//************************************
	static void DoPassWordEncrypt(FR_Document frDoc, FRPasswordEncryptProc proc);

	//************************************
	// Function:  IsInProtectedViewMode
	// Param[in]: frDoc			The document to protected.
	// Return:  <a>TRUE</a> means in the protected view mode.
	// Remarks: Check if the document is in protected view mode. It gets from preferences in security tab of "protected view".
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	//************************************
	static FS_BOOL IsInProtectedViewMode(FR_Document frDoc);

	//************************************
	// Function:  GetCreateDocSourceFilePath
	// Param[in]: doc					The document.
	// Param[out]: outSourceFilePath	It receives the source file path.
	// Return:	void.
	// Remarks: Gets the source file path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// Deprecated: Internal use.
	//************************************
	static void GetCreateDocSourceFilePath(FR_Document doc, FS_WideString* outSourceFilePath);

	//************************************
	// Function:  IsImageBasedDocument
	// Param[in]: frDoc			The document.
	// Return:  <a>TRUE</a> means all objects is PDFPAGE_IMAGE or PDFPAGE_PATH type.
	// Remarks: Check if the document is Image Based Document.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.2
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsImageBasedDocument(FR_Document frDoc);

	//************************************
	// Function:  SetDocEncrypted
	// Param[in]: frDoc			The document.
	// Param[in]: bEncrypted	Indicates whether the document is encrypted or not.
	// Return:  void.
	// Remarks: Indicates whether the document is encrypted or not.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.2
	// Deprecated: Internal use.
	//************************************
	static void SetDocEncrypted(FR_Document frDoc, FS_BOOL bEncrypted);

	//************************************
	// Function:  IsVisible
	// Param[in]: frDoc			The document.
	// Return:  Whether the opened document is visible or not.
	// Remarks: Checks whether the opened document is visible or not.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.3
	//************************************
	static FS_BOOL IsVisible(FR_Document frDoc);

	//************************************
	// Function:  DeprecatedSetDRMSecurity
	// Param[in]: doc				The input document.
	// Param[in]: encryptDict		The Encrypt dictionary.
	// Param[in]: cryptoHandler		The callbacks for crypto handler.
	// Param[in]: bEncryptMetadata	Whether to encrypt the metadata.
	// Param[in]: clientHandler		The user-supplied data.
	// Return:	void
	// Remarks:	 Sets security using custom security handler and custom encryption.
	// Application should provide a full encryption dictionary (application can destroy it after this call),
	// and a custom encryption handler. 	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.5
	// Deprecated: Internal use.
	//************************************
	static void				DeprecatedSetDRMSecurity(
											FR_Document doc,
											FPD_Object encryptDict,
											FS_LPVOID cryptoHandler,
											FS_BOOL bEncryptMetadata,
											FS_LPVOID clientHandler);

	//************************************
	// Function:  ConvertPdfToOtherFormat2
	// Param[in]: wsDesPath			The destination file path.
	// Param[in]: wsFileExt			The format need to be convert. Support: docx, doc, xlsx, xls, html, pptx, rtf...
	//								Format example: Word Document(.docx) | .docx
	// Return:  <a>TRUE</a> converted sucessful.
	// Remarks: Convert Pdf document to other format document.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use FRDocConvertPdfToOtherFormat3 functions  instead.
	//************************************
	static FS_BOOL	ConvertPdfToOtherFormat2(FS_LPCWSTR wsDesPath, FS_LPCSTR szFileExt);

	//************************************
	// Function:  AddWatermark
	// Param[in]: doc				The input document.
	// Param[in]: pWatermarkInfo	The watermark setting information.
	// Return:  <a>0</a> add watermark sucessful.
	// Remarks: Add watermark to document, it will not update document view.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_INT32 AddWatermark(FR_Document doc, FR_WatemarkElementInfo *pWatermarkInfo);

	//************************************
	// Function:  AddAndUpdateWatermark
	// Param[in]: doc				The input document.
	// Param[in]: pWatermarkInfo	The watermark setting information.
	// Return:  <a>0</a> add watermark fail.
	// Remarks: Add watermark to document and update the document view.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_INT32 AddAndUpdateWatermark(FR_Document doc, FR_WatemarkElementInfo *pWatermarkInfo);

	//************************************
	// Function:  RemoveWatermark
	// Param[in]: doc				The input document.
	// Param[in]: szSpecifyDicValue	Remove the specify watermark that add with <a>FR_PWatemarkElementInfo</a> lpbSpecifyWatermarkDicValue,
	//								can be pass null means remove all watermark.
	// Return:  <a>0</a> remove watermark fail.
	// Remarks: Remove watermark of document, it will not update document view.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_INT32 RemoveWatermark(FR_Document doc, FS_LPCSTR szSpecifyDicValue);

	//************************************
	// Function:  RemoveAndUpdateWatermark
	// Param[in]: doc				The input document.
	// Param[in]: szSpecifyDicValue	Remove the specify watermark that add with <a>FR_PWatemarkElementInfo</a> lpbSpecifyWatermarkDicValue,
	//								can be pass null means remove all watermark.
	// Return:  <a>0</a> remove watermark fail.
	// Remarks: Remove watermark to document and update the document view.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_INT32 RemoveAndUpdateWatermark(FR_Document doc, FS_LPCSTR szSpecifyDicValue);

	//************************************
	// Function:  AddHeaderFooter
	// Param[in]: doc				The input document.
	// Param[in]: pHeaderFooterInfo	The header and footer setting information.
	// Return:  <a>0</a> add header and footer fail.
	// Remarks: Add header and footer to document, it will not update document view.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_INT32 AddHeaderFooter(FR_Document doc, FR_HeaderFooterElementInfo *pHeaderFooterInfo);

	//************************************
	// Function:  AddAndUpdateHeaderFooter
	// Param[in]: doc				The input document.
	// Param[in]: pHeaderFooterInfo	The header and footer setting information.
	// Return:  <a>0</a> add header and footer fail.
	// Remarks: Add header and footer to document and update the document view.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_INT32 AddAndUpdateHeaderFooter(FR_Document doc, FR_HeaderFooterElementInfo *pHeaderFooterInfo);

	//************************************
	// Function:  RemoveHeaderFooter
	// Param[in]: doc				The input document.
	// Param[in]: szSpecifyDicValue	remove the specify header and footer that add with <a>FR_PHeaderFooterElementInfo</a>				
	//								lpbSpecifyHeaderFooterDicValue, can be pass null means remove all header and footer.
	// Return:  <a>0</a> remove header and footer fail.
	// Remarks: Remove header and footer to document, it will not update document view.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_INT32 RemoveHeaderFooter(FR_Document doc, FS_LPCSTR szSpecifyDicValue);

	//************************************
	// Function:  RemoveAndUpdateHeaderFooter
	// Param[in]: doc				The input document.
	// Param[in]: szSpecifyDicValue	remove the specify header and footer that add with <a>FR_PHeaderFooterElementInfo</a>				
	//								lpbSpecifyHeaderFooterDicValue, can be pass null means remove all header and footer.
	// Return:  <a>0</a> remove header and footer fail.
	// Remarks: Remove header and footer to document and update the document view.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_INT32 RemoveAndUpdateHeaderFooter(FR_Document doc, FS_LPCSTR szSpecifyDicValue);

    //************************************
    // Function:  IsReadSafeMode
    // Param[in]: doc				The input document.
    // Return:	Return true if the doc is Read Safe Mode.
    // Remarks: Return true if the doc is Read Safe Mode. It gets from "Trust Manager" in prefrences.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1	
    //************************************
    static FS_BOOL IsReadSafeMode(FR_Document doc);

    //************************************
	// Function:  GetInterForm
	// Param[in]: frDoc		    The input document.		
	// Return: FR_ReaderInterform
	// Remarks: FR_ReaderInterform used to process form appearance.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FR_ReaderInterform  GetInterForm(FR_Document frDoc);

	//************************************
	// Function:  ReplaceTextToSelectedText
	// Param[in]: frDoc		    The input document.			
	// Param[in]: nPageIndex	The page index.
	// Param[in]: nIndex		 The page end index.
	// Param[in]: replaceText	The replace text.
	// Return: void
	// Remarks: 
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static void ReplaceTextToSelectedText(FR_Document doc, FS_INT32 nPageIndex, FS_INT32 nIndex, FS_LPCWSTR replaceText);

	//************************************
    // Function:  GeneratePageContent
    // Param[in]: doc			The input document.
    // Param[in]: bProgress		Indicates whether to show the progress bar or not.
    // Return:	void.
    // Remarks: Generates all page content after change content.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1	
    //************************************
    static void	GeneratePageContent(FR_Document doc, FS_BOOL bProgress);

    //************************************
    // Function:  GetFocusAnnot
    // Param[in]: frDoc		The input document.
    // Return: The focus annotation.
    // Remarks: Gets the focus annotation including form control.
    // Notes: 
    // Since: <a>SDK_LATEEST_VERSION</a> > 8.0
    //************************************
    static FR_Annot GetFocusAnnot(FR_Document frDoc);

	//************************************
	// Function:  GetMenuEnableByName
	// Param[in]: frDoc		The input document.
	// Param[in]: csName	The menu name.
	// Return: FS_BOOL   <a>TRUE</a> The menu is enabled.
	// Remarks: Check menu is enabled. About permisson document, some menu will be set Disabled.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See: FRDocSetMenuEnableByName
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetMenuEnableByName(FR_Document frDoc, FS_LPCSTR csName);

	//************************************
	// Function:  ClearAllSelection
	// Param[in]: frDoc		The input document.	
	// Return: void  
	// Remarks: Clear all selection of annot.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use. User can use FRDocClearSelection function instead.
	//************************************
	static void ClearAllSelection(FR_Document frDoc);

	//************************************
	// Function:  AddSelection
	// Param[in]: frDoc		The input document.	
	// Param[in]: annot		The annot need to select.	
	// Return: void  
	// Remarks: Set the annot to be selected.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static void AddSelection(FR_Document frDoc, FR_Annot annot);

	//************************************
	// Function:  GetPageFirstAnnot
	// Param[in]: frDoc		The input document.	
	// Param[in]: nPageIndex	The page index.	
	// Param[in]: csType		The annot type. It's the Subtype info of annot dictionary.
	// Return: FR_Annot  
	// Remarks: Get the type of the annot in page.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FR_Annot GetPageFirstAnnot(FR_Document frDoc, FS_INT32 nPageIndex, FS_LPCSTR csType);

	//************************************
	// Function:  CreateFormControl
	// Param[in]: frDoc		    The input document.	
	// Param[in]: nPageIndex	The page index.	
	// Param[in]: rect		    The rect of the form.
	// Param[in]: nType		    The form type ,like FPD_FORM_FIELDTYPE_PUSHBUTTON.
	// Param[in]: iRotate		The form rotate.
	// Param[in]: sName		    The form name after create.
	// Param[in]: bUseSuggestName	Whether use suggest name.
	// Return: FR_Annot  Create the form annot.
	// Remarks: Create form contol, use FRDocReloadPage after create.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See: FRDocReloadPage
	//************************************
	static FR_Annot CreateFormControl(FR_Document frDoc, FS_INT32 nPageIndex, FS_FloatRect rect, FS_INT32 nType, FS_INT32 iRotate, FS_WideString sName, FS_BOOLEAN bUseSuggestName);

	//************************************
	// Function:  ReCalTabOrder
	// Param[in]: frDoc		    The input document.	
	// Param[in]: nPageIndex	The page index.	
	// Return: void
	// Remarks: Reset tab order by the key "Tabs" of page dictionary.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
    //************************************
    static void ReCalTabOrder(FR_Document frDoc, FS_INT32 nPageIndex);


	//************************************
	// Function:  NotifyAddWidget
	// Param[in]: annot		    The input annot.		
	// Return: void
	// Remarks: Notify add widget annot.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
    // Deprecated: Current function has been deprecated, it moved to FRAnnotAdd in FR_DocEventCallback.
	//************************************
	static void NotifyAddWidget(FR_Annot annot);

	//************************************
	// Function:  UpdateAllViews
	// Param[in]: pageview		    The pageview.		
	// Param[in]: pAnnot		    The input annot.
	// Return: void
	// Remarks: Refresh the area where the annotation is located of all pageviews expect the input pageview.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static void UpdateAllViews(FR_PageView pageview, FR_Annot pAnnot);

	//************************************
	// Function:  GetAnnotByDict
	// Param[in]: frDoc		    The input document.			
	// Param[in]: nPageIndex	The page index.
	// Param[in]: pDict		    The annot dic.
	// Return: FR_Annot
	// Remarks: Get FR_Annot object by dictionary.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Current function has been deprecated .User can use FRPageGetAnnotByDict instead.
	//************************************
	static FR_Annot GetAnnotByDict(FR_Document frDoc, FS_INT32 nPageIndex, FPD_Object pDict);

	//************************************
	// Function:  AddAnnot
	// Param[in]: frDoc		    The input document.			
	// Param[in]: nPageIndex	Add annot to the specified page index .
	// Param[in]: lpSubType		The annot subtype.
	// Param[in]: rect		    The annot rect.
	// Return: FR_Annot
	// Remarks: Add annot of specified property to page index.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0	
	//************************************
	static FR_Annot AddAnnot(FR_Document frDoc, FS_INT32 nPageIndex, FS_LPCSTR lpSubType, const FS_FloatRect rect);

	//************************************
	// Function:  AddAnnot2
	// Param[in]: frDoc		    The input document.			
	// Param[in]: nPageIndex	The page index.
	// Param[in]: pDict		    The annot dictionary.
	// Param[in]: nIndex		The annot index.
	// Return: FR_Annot
	// Remarks: Add annot of specified property to page index.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0	
	//************************************
	static FR_Annot AddAnnot2(FR_Document frDoc, FS_INT32 nPageIndex, FPD_Object pDict, FS_INT32 nIndex);	

    //************************************
	// Function:  ReplacePages
	// Param[in]: frDoc		    The input document.			
	// Param[in]: nStart	    The start page index of the currentdoc.
	// Param[in]: pSrcDoc		The source doc.
	// Param[in]: arrSrcPages	The pageindexs of the src doc.
	// Return: FS_BOOL  <a>FALSE</a> The srcDoc is NULL.
	// Remarks: Replaces the pages in the specified file.
	// Notes: Annots in origin document will not be replace.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FS_BOOL ReplacePages(FR_Document frDoc, FS_INT32 nStart, const FPD_Document pSrcDoc, const FS_WordArray &arrSrcPages);
	
	//************************************
	// Function:  InsertPages
	// Param[in]: frDoc		    The input document.			
	// Param[in]: nInsertAt	    The insert index.
	// Param[in]: pSrcDoc		The source doc.
	// Param[in]: arrSrcPages	The pageindexs of the src doc.
	// Param[in]: bRenameForm	If need to rename form.
	// Param[in]: bShowRenameFormDlg	If show rename form dialog.
	// Param[in]: bEntireDoc	If insert the whole doc.
	// Param[in]: srcDocTitle	The title of source doc.
	// Param[in]: bRetainBookmark	If retain bookmark.	
	// Return: FS_BOOL
	// Remarks: Insert the pages from the specified file.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FS_BOOL InsertPages(FR_Document frDoc, FS_INT32 nInsertAt, const FPD_Document pSrcDoc, const FS_WordArray &arrSrcPages, FS_BOOL bRenameForm, FS_BOOL bShowRenameFormDlg, FS_BOOL bEntireDoc, FS_WideString srcDocTitle , FS_BOOL bRetainBookmark);
	
	//************************************
	// Function:  ExtractPages
	// Param[in]: frDoc		    The input document.			
	// Param[in]: arrExtraPages	The extract index.
	// Param[in]: pDstDoc		The dest doc after extract pages. Use FPDDocNew create memory doc and save it after extract.
	// Return: FS_BOOL
	// Remarks: Extract pages to dest document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FS_BOOL ExtractPages(FR_Document frDoc, const FS_WordArray &arrExtraPages, FPD_Document pDstDoc);

	//************************************
	// Function:  GetDocSecurityCanBeModified
	// Param[in]: frDoc		    The input document.	
	// Return: FS_BOOL
	// Remarks: Get if the doc can be modified.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetDocSecurityCanBeModified(FR_Document frDoc);
	
	//************************************
	// Function:  GetDocument
	// Param[in]: pReaderPage		   The IReader_Page obj.	
	// Return: FR_Document
	// Remarks: The IReader_Document of the readerpage.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FR_Document GetDocument(FS_LPVOID pReaderPage);

	//************************************
	// Function:  GetAnnotByDict2
	// Param[in]: pReaderPage		   The IReader_Page obj.	
	// Param[in]: pDict		           The annot dic.	
	// Return: FR_Annot
	// Remarks: Get the annot by readerpage and annot dict.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FR_Annot GetAnnotByDict2(FS_LPVOID pReaderPage, FPD_Object pDict);

	//************************************
	// Function:  GetPageIndex
	// Param[in]: pReaderPage		   The IReader_Page obj.		
	// Return: FS_INT32
	// Remarks: Get page index of IReader_Page.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FS_INT32	GetPageIndex(FS_LPVOID pReaderPage);

	//************************************
	// Function:  RemoveSecurityInfo
	// Param[in]: frDoc		   The input document.		
	// Return: FS_BOOL
	// Remarks: Remove the securityInfo of the doc. Some password、certificate、DRM or other security will be remove.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FS_BOOL RemoveSecurityInfo(FR_Document frDoc);

	//************************************
	// Function:  UpdateDocAllViews
	// Param[in]: frDoc		   The input document.			
	// Param[in]: sender	   The doc view.		
	// Return: void
	// Remarks: Update all docviews except input docview.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static void  UpdateDocAllViews(FR_Document frDoc, FR_DocView sender);

	//************************************
	// Function:  SendAsAttachment
	// Param[in]: frDoc		   The input document.		
	// Param[in]: wsTo	       The email to info.
	// Param[in]: wsCc		   The email cc address.		
	// Param[in]: wsBcc	       The email bcc address.		
	// Param[in]: wsSubject	   The email subject.		
	// Param[in]: wsMsg	       The email message.		
	// Param[in]: bUI		   If show email UI.		
	// Param[in]: bDocReopened	   If the doc need to reopened.		
	// Param[in]: wsErrorMessage   The error message after send email.	
	// Return: FR_MailtoResult
	// Remarks: Send the doc as attachment. It need to use outlook as default client sender.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FR_MailtoResult SendAsAttachment(FR_Document frDoc, const FS_WideString& wsTo, const FS_WideString& wsCc, const FS_WideString& wsBcc,
		const FS_WideString& wsSubject, const FS_WideString& wsMsg,
		FS_BOOL bUI, FS_BOOL& bDocReopened, FS_WideString* wsErrorMessage);
	
	//************************************
	// Function:  OnBeforeNotifySumbit
	// Param[in]: frDoc		   The input document.		
	// Param[in]: pSubmit	   The CXFA_Submit.
	// Return: FS_BOOL
	// Remarks: xfa submit event, before notify sumbit.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL OnBeforeNotifySumbit(FR_Document frDoc, FS_LPVOID pSubmit);

	//************************************
	// Function:  OnAfterNotifySumbit
	// Param[in]: frDoc		   The input document.		
	// Return: void
	// Remarks: xfa submit event, after notify sumbit.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static void OnAfterNotifySumbit(FR_Document frDoc);

	//************************************
	// Function:  ConvertPdfToOtherFormat3
	// Param[in]: wsDesPath			The destination file path.
	// Param[in]: wsFileExt			The format need to be convert. Support: docx, doc, xlsx, xls, html, pptx, rtf...
	//								Format example: Word Document(.docx) | .docx	
	//                              Word 97 - 2003 (*.doc) | *.doc
	//                              HTML(*.htm, *.html) | *.htm; *.html
	//                              Rich Text Format(*.rtf) | *.rtf
	//                              TXT Files(*.txt) | *.txt
	//                              XML Spreadsheet 2003 (*.xml) | *.xml
	//                              Excel(*.xlsx) | *.xlsx
	//                              PowerPoint(*.pptx) | *.pptx
	//                              PNG(*.png) | *.png
	//                              JPEG(*.jpg, *.jpeg, *.jpe, *.jif) | *.jpg; *.jpeg; *.jpe; *.jif
	//                              TIFF(*.tiff, *.tif) | *.tiff; *.tif
	//                              BMP(*.bmp, *.dib, *.rle) | *.bmp; *.dib; *.rle
	//                              JPEG2000(*.jpf, *.jpx, *.jp2, *.j2k, *.jpc) | *.jpf; *.jpx; *.jp2; *.j2k; *.jpc
	//                              XPS Document(*.xps, *.oxps) | *.xps; *.oxps
	// Param[out]: pnRetType		The convert result.	
	// Param[in]: bShowTip		    If show tip.	
	// Return:  <a>TRUE</a> converted sucessful.
	// Remarks: Convert Pdf document to other format document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FS_BOOL ConvertPdfToOtherFormat3(FS_LPCWSTR wsDesPath, FS_LPCSTR szFileExt, FS_INT32* pnReType, FS_BOOL bShowTip);

    //************************************
    // Function:  GetPage
	// Param[in]: frDoc		   The input document.		
	// Param[in]: page_index   The page index.
    // Return:  The specified <a>FR_Page</a>.
    // Remarks: Gets the specified <a>FR_Page</a> for specified document.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
    //************************************
	static FR_Page	GetPage(FR_Document frDoc, FS_INT32 page_index);

	//************************************
	// Function:  SetNotify
	// Param[in]: notify		  The CFR_IFormDesignerNotifyHandler.		
	// Return: void
	// Remarks: Set the handler to IFormDesigner. When widget form has changed, it will be called.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See: FRD_FormDesignNotifyCallbacks
	//************************************
	static void	SetNotify(FR_IFormDesignerNotify notify);

	//************************************
	// Function:  SetTabOrder
	// Param[in]: pDoc		  The input document.		
	// Param[in]: eOrder	  The tabOrder.	
	// Return: FS_BOOL
	// Remarks: Set tab order of widgets in all pages.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL SetTabOrder(FR_Document pDoc, FR_TabOrder eOrder);

	//************************************
	// Function:  SetTabOrder
	// Param[in]: pPage		  The input FR_Page.		
	// Param[in]: eOrder	  The tabOrder.	
	// Return: FS_BOOL
	// Remarks: Set tab order of widgets in the page.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL SetTabOrder2(FR_Page pPage, FR_TabOrder eOrder);

	//************************************
	// Function:  IsKeepSelectedChecked
	// Return: FS_BOOL   TRUE: Continuously to create the type of widget.
	// Remarks: Check the "Keep tool select" is select, if TRUE, it can create the type of widget continuously.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL  IsKeepSelectedChecked();	

	//************************************
	// Function:  ReConStructAcroform
	// Param[in]: frDoc		  The input document.			
	// Return: void
	// Remarks: ReConstruct a form from a document.
	// ReConstruct a form in order to regenerate appearance streams for the fields.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static void ReConStructAcroform(FR_Document frDoc);	

	//************************************
	// Function:  GetOCProperties
	// Param[in]: frDoc		  The input document.			
	// Return: FPD_OCProperties Get the OCProperties of the doc.
	// Remarks: Get Optional Content Properties from FR_Document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FPD_OCProperties GetOCProperties(FR_Document frDoc);

	//************************************
	// Function:  ResetOCProperties
	// Param[in]: frDoc		  The input document.			
	// Return: void 
	// Remarks: Reset FPD_OCProperties from FR_Document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static void ResetOCProperties(FR_Document frDoc);	

	//************************************
	// Function:  SetCertifyDocument
	// Param[in]: frDoc		  The input document.		
	// Param[in]: bDocCertified	 If the doc certified.	
	// Return: void   
	// Remarks: Set whether the document is certified, if set TRUE, it will not to set tabOrder to WidgetAnnotList.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static void		SetCertifyDocument(FR_Document frDoc, FS_BOOL bDocCertified);

	//************************************
	// Function:  IsCertifyDocument
	// Param[in]: frDoc		  The input document.
	// Return: FS_BOOL   TRUE: the document is certified.
	// Remarks: Get whether the document is certified.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	IsCertifyDocument(FR_Document frDoc);

	//************************************
	// Function:  SetSignaturePermissions
	// Param[in]: doc		    The input document.
	// Param[in]: pdwPermissions   The permisson of the doc.
	// Return: void
	// Remarks: Set signature permisson to FR_Document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static void		SetSignaturePermissions(FR_Document doc, FS_DWORD pdwPermissions);

	//************************************
	// Function:  SetSaveMode
	// Param[in]: frDoc		    The input document.
	// Param[in]: SaveModeFlag   The save mode, like FPD_SAVE_INCREMENTAL.
	// Return: void
	// Remarks: Set the mode of save document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See: FPD_SAVE_INCREMENTAL
	// See: FPD_SAVE_NO_ORIGINAL
	//************************************
	static void			SetSaveMode(FR_Document doc, FS_DWORD SaveModeFlag);

	//************************************
	// Function:  GetSaveMode
	// Param[in]: frDoc		    The input document.	
	// Return: FS_DWORD
	// Remarks: Get the save mode of the doc.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See: FPD_SAVE_INCREMENTAL
	// See: FPD_SAVE_NO_ORIGINAL
	//************************************
	static FS_DWORD		GetSaveMode(FR_Document doc);

	//************************************
	// Function:  SetDocumentTrustBySignature
	// Param[in]: frDoc		    The input document.	
	// Param[in]: bTrust		TRUE: the document is signatured by trust certificate.	
	// Return: void
	// Remarks: Set the document if signatured by trust certificate.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static void			SetDocumentTrustBySignature(FR_Document frDoc, FS_BOOL bTrust);

	//************************************
	// Function:  GetXFADocView
	// Param[in]: frDoc		    The input document.		
	// Return: FPD_XFADocView
	// Remarks: Get FPD_XFADocView of the document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FPD_XFADocView GetXFADocView(FR_Document frDoc);

	//************************************
	// Function:  GetReaderDocument
	// Param[in]: pdfdoc		    The input  pdf document.		
	// Return: FR_Document          Get the FR_Document of the FPD_Document
	// Remarks: Get FR_Document of FPD_Document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FR_Document GetReaderDocument(FPD_Document pdfdoc);

	//************************************
	// Function:  IsRunningJSAction
	// Param[in]: frDoc		    The input document.		
	// Return: FS_BOOLEAN       TRUE: Running javascript action now.
	// Remarks: Get if running javascript action now.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN IsRunningJSAction(FR_Document frDoc);

	//************************************
	// Function:  CountSelection
	// Param[in]: frDoc		    The input document.		
	// Return: FS_DWORD
	// Remarks: Get the count of selected annot.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FS_DWORD	 CountSelection(FR_Document frDoc);

	//************************************
	// Function:  GetSelection
	// Param[in]: frDoc		    The input document.		
	// Param[in]: index		    The index of selected annots.		
	// Return: FR_Annot         Get the index annot of selected annots.
	// Remarks: Get the index annot of selected annots.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FR_Annot		 GetSelection(FR_Document frDoc, FS_DWORD index);

	//************************************
	// Function:  GetTopPageState
	// Param[in]: frDoc		    The input document.		
	// Param[out]: nPage		The page index.		
	// Param[out]:state		    The page state.	The dest of state need to call FSFloatArrayNew first.
	// Return: FS_BOOL
	// Remarks: Gets the state of the first page of the current visible pages when the multiple pages visible. 
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FS_BOOL		GetTopPageState(FR_Document frDoc, FS_INT32* nPage, FR_PAGESTATE* state);

	//************************************
	// Function:  SetValidationStatus
	// Param[in]: frDoc		    The input document.		
	// Param[in]: Flag		    The certificate flag. 1:available,2: unavailable,3: unknow
	// Return: void
	// Remarks: Set the certificate state of document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static void			SetValidationStatus(FR_Document doc, FS_DWORD Flag);

	//************************************
	// Function:  SetMemDocCanReopen
	// Param[in]: frDoc		    The input document.		
	// Param[in]: bCanReopen	If the doc can be reopen		
	// Return: void
	// Remarks:  For memory doc, if set false, it will not be reopen after save.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static void	        SetMemDocCanReopen(FR_Document doc, FS_BOOLEAN bCanReopen);

	//************************************
	// Function:  AppendUnCompressObjects
	// Param[in]: frDoc		    The input document.		
	// Param[in]: aryObjNum	    Append uncompress objnum to temp variable.	
	// Return: void
	// Remarks:  Set uncomproess object when save the file. 
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FPDCreatorAttachUncompressObjects
	//************************************
	static void	AppendUnCompressObjects(FR_Document doc, FS_DWordArray aryObjNum);

	//************************************
	// Function:  DoSaveAs3
	// Param[in]: doc				The document.
	// Param[in]: pwszFilePath		The path where the document to be saved as.
	// Param[in]: proc				Callback function.
	// Param[in]: pProcData			The client data. It will be passed to the save-as callback function.
	// Param[in]: option	        Save file option.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Save the current document.	  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FR_DocSaveAsProc
	//************************************
	static FS_BOOL	DoSaveAs3(FR_Document doc, FS_LPCWSTR pwszFilePath, FR_DocSaveAsProc proc, void* pProcData, FR_SaveDocOption option);

	//************************************
	// Function:  SaveAsOleProc
	// Param[in]: doc				The document.	
	// Param[in]: proc				Callback function.
	// Param[in]: pProcData			The client data. It will be passed to the save-as callback function.	
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Save the Embedded document, like the document open from the office, after save the document, phantom will be closed.  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FR_DocSaveAsProc
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	SaveAsOleProc(FR_Document doc, FRDocOleSaveProc proc, FS_LPVOID pProcData);

	//************************************
	// Function:  GetUnCompressObjects
	// Param[in]: frDoc		    The input document.		
	// Param[out]: aryObjNum	Get uncompress objnum in temp variable.	
	// Return: void
	// Remarks:  Get objects that not need to be comproessed.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void GetUnCompressObjects(FR_Document doc, FS_DWordArray* aryObjNum);

	//************************************
	// Function:  IsReflowViewMode
	// Param[in]: frDoc		    The input document.		
	// Return: FS_BOOLEAN       true: It's showing in reflow view mode.
	// Remarks:  Get the document if in reflow view mode now.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOLEAN	IsReflowViewMode(FR_Document doc);

	//************************************
	// Function:  GetOpenFilePath
	// Param[in]: frDoc		    The input document.		
	// Param[in]: openOption	The open option of the file.	
	// Param[out]: path		    Get the file path.	
	// Return: void
	// Remarks:  Get the path of the current document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void	GetOpenFilePath(FR_Document doc, FR_OpenFileOption openOption, FS_WideString* path);

	//************************************
	// Function:  GetTabTitle
	// Param[in]: frDoc		    The input document.		
	// Param[out]: wsTitle	    Return the title of the tab.
	// Return: void
	// Remarks:  Get the title of the tab.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void	GetTabTitle(FR_Document doc, FS_WideString* wsTitle);

	//************************************
	// Function:  GetTextPage
	// Param[in]: frDoc		    The input document.		
	// Param[in]: iPage	        The page index.
	// Param[in]: bCreate		Default is TRUE, if true will create TextPage.	
	// Return: void
	// Remarks: Get FPD_TextPage object from document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FPD_TextPage GetTextPage(FR_Document doc, FS_INT32 iPage, FS_BOOL bCreate);

	//************************************
	// Function:  CloseFileHandler
	// Param[in]: frDoc		    The input document.		
	// Param[in]: csFilepath	The input file path.
	// Return: void
	// Remarks: Close file stream handler of the filepath.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void		CloseFileHandler(FR_Document doc, FS_LPCWSTR csFilepath);

	//************************************
	// Function:  ResetFileHandler
	// Param[in]: frDoc		    The input document.		
	// Param[in]: csFilepath	The input file path.
	// Return: void
	// Remarks: Reset the file stream handler of the filepath.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void		ResetFileHandler(FR_Document doc, FS_LPCWSTR csFilepath);

	//************************************
	// Function:  GetDocPages
	// Param[in]: doc			The input document.		
	// Return:  The number of pages for specified document.
	// Remarks: Get the count of pages for specified document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_INT32		GetDocPages(FR_Document doc);

	//************************************
	// Function:  OpenDocument
	// Param[in]: wszFile			The file path.
	// Param[in]: option	        The open file option.
	// Return:FR_Document 	The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
	// Remarks: Opens and displays a document form a file.	  	
	// Notes: Do not open and then immediately close a FR_Document without letting least once event loop complete.
	// See: FRDocClose
	// See: FRDocOpenFromPDDoc
	// See: FRDocFromPDDoc
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_Document	OpenDocument(FS_LPCWSTR wszFile, FR_OpenFileOption option);

	//************************************
	// Function:  GetFileName
	// Param[in]: doc			The input document.		
	// Param[out]: wsName	    The filename of the doc.
	// Return: void 	
	// Remarks: * Get the file name part of the document.
	// If the current document does not have a corresponding file name, return "Untitle.pdf" (localized).
	// See: FRDocClose
	// See: FRDocOpenFromPDDoc
	// See: FRDocFromPDDoc
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void 	 GetFileName(FR_Document doc, FS_WideString* wsName);

	//************************************
	// Function:  ClearMousePtHandleData
	// Param[in]: doc			The input document.
	// Return: void 	
	// Remarks: The plugin calls deletePin to delete the old obj left in m_pMousePtHandleDate->pDate, causing the Crash.Pin type to not record m_pMousePtHandleDate yet.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void      ClearMousePtHandleData(FR_Document doc);

	//************************************	
	// Function:  ResizePage
	// Param[in]: doc			The input document.
	// Param[in]: iPage			The page index.
	// Param[in]: pMediaBox		The rect of MediaBox.
	// Param[in]: pCropBox		The rect of CropBox.
	// Return: void 	
	// Remarks: Resize the page size by MediaBox and CropBox.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL	ResizePage(FR_Document doc, FS_INT32 iPage, const FS_FloatRect pMediaBox, const FS_FloatRect pCropBox);

	//************************************
	// Function:  GetPageLabel
	// Param[in]: doc			The input document.
	// Param[in]: pageIndex		The page index.	
	// Param[out]: outLabel		Get the page label.
	// Return: void 	
	// Remarks: If page use logical, that will get logical label, otherwise will get normal label like 1、2、3.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void GetPageLabel(FR_Document doc, FS_INT32 pageIndex, FS_WideString* outLabel);

	//************************************
	// Function:  RequestDocPermPDDoc
	// Param[in]: doc			The document whose permissions are being requested.
	// Param[in]: reqObj		The target object of the permissions request.	
	// Param[in]: reqOpr		The target operation of the permissions.
	// Param[in]: authData		A pointer to an authorization data structure.
	// Return: FRPermReqStatus 	 The request status constant, <code>0</code> if the requested operation
	// is allowed, a non - zero status code otherwise.
	// Remarks: Checks the permissions associated with the specified
	// document using the latest permissions format, and determines
	// whether the requested operation is allowed for the specified
	// object in the document.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FRPermReqStatus	RequestDocPermPDDoc(FR_Document pReaderDoc, FRPermReqObj reqObj, FRPermReqOpr reqOpr, FS_LPVOID authData);

	//************************************
	// Function:  GetPagePanelSelectRange
	// Param[in]: doc			    The input document.
	// Param[out]: arraySelPage		Get select page of the page panel.	
	// Return: FS_BOOL 	  TRUE: Get select page success.
	// Remarks: Get selected page index from page panel.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL GetSelectPageFromPagePanel(FR_Document pReaderDoc, FS_DWordArray* arraySelPage);

	//************************************
	// Function:  GetDocOpenJSFinish
	// Param[in]: doc			    The input document.
	// Return: FS_BOOL 	  TRUE: Get select page success.	
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Remarks: Check whether doc open js finished.
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetDocOpenJSFinish(FR_Document pReaderDoc);

	//************************************
	// Function:  GetDocRenderFinish
	// Param[in]: doc			    The input document.
	// Return: FS_BOOL 	  TRUE: Render finished.	
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Remarks: Check whether doc render finished.
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetDocRenderFinish(FR_Document pReaderDoc);
	//************************************
	// Function:  ReversePages
	// Param[in]: pReaderDoc			    The input document.
	// Param[in]: arrPages			        The pages need to be reverse.	
	// Return: FS_BOOL 	  Whether reverse pages success.	
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL	ReversePages(FR_Document pReaderDoc, const FS_DWordArray arrPages);

	//************************************
	// Function:  IsDynamicXFADocument
	// Param[in]: pdfDoc  The input FPD_Document.	
	// Return: FS_BOOL 	  Whether is XFA document.	
	// Remarks: Check the document is XFA document.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL	IsDynamicXFADocument(FPD_Document pdfDoc);

	//************************************
	// Function:  IsUseLogicalLabel
	// Param[in]: pReaderDoc  The input FR_Document.	
	// Return: FS_BOOL 	  Whether the document use logical label.	
	// Remarks: Check the document whether use logical label.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use. This function is deprecated. Suggest use FRDocProcessIsUsedLogicalPage from docprocess plugin.
	//************************************
	static FS_BOOL	IsUseLogicalLabel(FR_Document pReaderDoc);

	//************************************
	// Function:  DeletePages
	// Param[in]: pReaderDoc  The input FR_Document.	
	// Param[in]: arrDelPages The page array need to delete.
	// Return: FS_BOOL 	      TRUE delete pages success.
	// Remarks: Delete specified pages.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL	DeletePages(FR_Document pReaderDoc, FS_WordArray arrDelPages);

	//************************************
	// Function:  ExtractPages2
	// Param[in]: pReaderDoc    The input FR_Document.	
	// Param[in]: pFile         Extract pages to temp file.
	// Param[in]: arrExtraPages The page array need to extract.
	// Return: FS_BOOL 	      TRUE extract pages success.
	// Remarks: Extract pages to temp file.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FS_BOOL ExtractPages2(FR_Document pReaderDoc, FS_FileWriteHandler pFile, FS_WordArray arrExtraPages);

	//************************************
	// Function:  OnAfterExtractPagesEx
	// Param[in]: pReaderDoc     The input FR_Document.	
	// Param[in]: arrSrcPages    Extract page array.
	// Param[in]: wsDestfilepath The temp file path to extract.
	// Return: void
	// Remarks: After extract pages, it need to notify frame to do someghting.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	// Deprecated: Internal use.
	//************************************
	static void OnAfterExtractPagesEx(FR_Document pReaderDoc, FS_WordArray arrSrcPages, FS_WideString wsDestfilepath);

	//************************************
	// Function:  SwapTwoPage
	// Param[in]: pReaderDoc     The input FR_Document.	
	// Param[in]: indexPage1     The page index 1 need to swap.
	// Param[in]: indexPage2     The page index 2 need to swap.
	// Return: FS_BOOL   TRUE swap success.
	// Remarks: Swap two pages in the document.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FS_BOOL SwapTwoPage(FR_Document pReaderDoc, FS_INT32 indexPage1, FS_INT32 indexPage2);

	//************************************
	// Function:  MovePages
	// Param[in]: pReaderDoc     The input FR_Document.	
	// Param[in]: nMoveAt        The dest index of moved to.
	// Param[in]: arrMovePages   The pageindex array need to move.
	// Return: FS_BOOL   TRUE move success.
	// Remarks: Move specified pages.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FS_BOOL	MovePages(FR_Document pReaderDoc, FS_INT32 nMoveAt, FS_WordArray arrMovePages);

	//************************************
	// Function:  GetSnapShotInfo
	// Param[in]: pReaderDoc     The input FR_Document.	
	// Param[out]: rcRect        Get the shot rect.
	// Param[out]: nPageIndex    Get the shot page index.
	// Return: FS_BOOL   TRUE get shot info success.
	// Remarks: Get snap shot info.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetSnapShotInfo(FR_Document pReaderDoc, FS_FloatRect* rcRect, FS_INT32* nPageIndex);

	//************************************
	// Function:  GetPageIndexByLabel
	// Param[in]: pReaderDoc     The input FR_Document.	
	// Param[in]: csPageLabel    The input page label string.
	// Return: FS_INT32   Get the page index.
	// Remarks: Get the page index.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FS_INT32 GetPageIndexByLabel(FR_Document pReaderDoc, FS_WideString csPageLabel);

	//************************************
	// Function:  RotatePage
	// Param[in]: pReaderDoc     The input FR_Document.	
	// Param[in]: iPage			 The page index need to rotate.
	// Param[in]: nRotate        The page rotate.
	// Return: FS_BOOL   TRUE rotate page success.
	// Remarks: Rotate the specified page.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FS_BOOL	RotatePage(FR_Document pReaderDoc, FS_INT32 iPage, FS_INT32 nRotate);

	//************************************
	// Function:  HasOwnerPermission
	// Param[in]: pReaderDoc     The input FR_Document.		
	// Return: FS_BOOLEAN   TRUE has owner permisson.
	// Remarks: Check if the document is set with an owner password.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Notes: It has been deprecated, suggest use FRInternalSecurityHandlerHasOwnerPermission from security plugin.
	//************************************
	static FS_BOOLEAN HasOwnerPermission(FR_Document pReaderDoc);
	
	//************************************
	// Function:  SetSaveParam
	// Param[in]: pReaderDoc               The input FR_Document.		
	// Param[in]: bUseObjStreamCreator     Use object stream creator
	// Param[in]: fileVersion              It should be from 10 to 17.
	// Return: FS_BOOL                     true: set save param success.
	// Remarks: Set save param.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL SetSaveParam(FR_Document pReaderDoc, FS_BOOL bUseObjStreamCreator, FS_INT32 fileVersion);

	//************************************
	// Function:  CheckModuleLicense
	// Param[in]: pReaderDoc               The input FR_Document.
	// Return: FS_BOOLEAN                  true: It has module license.
	// Remarks: Check module license.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN CheckModuleLicense(FR_Document pReaderDoc);

	//************************************
	// Function:  GetDocFromContainerDoc
	// Param[in]: pReaderDoc               The input FR_Document.
	// Param[in]: pContainerDoc            The container document.
	// Return: FR_Document                 Get the doc from container document.
	// Remarks: Get the doc from container document.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static  FR_Document GetDocFromContainerDoc(FR_Document pReaderDoc, FR_Document pContainerDoc);

	//************************************
	// Function:  IsDocClosing
	// Param[in]: pReaderDoc               The input FR_Document.
	// Return: FS_BOOL                     Check if the doc has been closed.      
	// Remarks: Check if the doc has been closed.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsDocClosing(FR_Document pReaderDoc);

	//************************************
	// Function:  GetHitImageObj
	// Param[in]: pReaderDoc               The input FR_Document.
	// Param[out]: pHitPageView            Get the hit page view.
	// Return: FR_SelectedImageInfo        Get current selected image object.      
	// Remarks: Get current selected image object.      
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FR_SelectedImageInfo	GetHitImageObj(FR_Document pReaderDoc, FR_PageView* pHitPageView);

	//************************************
	// Function:  ClearHitImageObj
	// Param[in]: pReaderDoc               The input FR_Document.
	// Return: void     
	// Remarks: Clear selected image object.  
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void		ClearHitImageObj(FR_Document pReaderDoc);

	//************************************
	// Function:  PromptToDetectFileHandle
	// Param[in]: pReaderDoc               The input FR_Document.
	// Return: FS_BOOLEAN     
	// Remarks: Check the current file stream.  
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	PromptToDetectFileHandle(FR_Document pReaderDoc);

	//************************************
	// Function:  AddIgnoreObjects
	// Param[in]: pReaderDoc               The input FR_Document.
	// Param[in]: Objs                     Object nums that need to ignore when save.
	// Return: void     
	// Remarks: Set ignore objects num.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void		AddIgnoreObjects(FR_Document pReaderDoc, FS_DWordArray Objs);

	//************************************
	// Function:  InsertPageByDict
	// Param[in]: pReaderDoc               The input FR_Document.
	// Param[in]: nInsertAt                The index of the new page.
	// Param[in]: cwTemplateName           The page template name.
	// Param[in]: pSrcDict                 The input page dictionary.
	// Param[in]: bRenameForm              TRUE: need rename form.
	// Return: FS_BOOL    TRUE: Insert success.     
	// Remarks: Insert new page by dictionary.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL InsertPageByDict(FR_Document pReaderDoc, FS_INT32 nInsertAt, FS_LPCWSTR cwTemplateName, const FPD_Object pSrcDict, FS_BOOL bRenameForm);

	//************************************
	// Function:  SaveToXFADoc
	// Param[in]: pReaderDoc               The input FR_Document.
	// Return: void     
	// Remarks: Save XFA data.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void SaveToXFADoc(FR_Document pReaderDoc);

	//************************************
	// Function:  GetDeletePageUndoItem
	// Param[in]: pReaderDoc               The input FR_Document.
	// Return: FR_DeletePageUndoItem     
	// Remarks: Get DeletePageUndoItem.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FR_DeletePageUndoItem	GetDeletePageUndoItem(FR_Document pReaderDoc);

	//************************************
	// Function:  ReleaseDeletePageUndoItem
	// Param[in]: pItem               The input FR_DeletePageUndoItem.
	// Return: void     
	// Remarks: Release DeletePageUndoItem.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void		ReleaseDeletePageUndoItem(FR_DeletePageUndoItem pItem);

	//************************************
	// Function:  DeletePagesUndo
	// Param[in]: pItem               The input FR_DeletePageUndoItem.
	// Return: void     
	// Remarks: Undo delete pages.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void DeletePagesUndo(FR_DeletePageUndoItem pItem);

	//************************************
	// Function:  DeletePagesRedo
	// Param[in]: pItem               The input FR_DeletePageUndoItem.
	// Return: void     
	// Remarks: Redo delete pages.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void DeletePagesRedo(FR_DeletePageUndoItem pItem);

	//************************************
	// Function:  MergeTwoDoc
	// Param[in]: info1               The input document info.
	// Param[in]: info2               The input document info.
	// Param[in]: destFilePath        The input file path after merge.
	// Return: FS_BOOL     
	// Remarks: Merge two documents.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FS_BOOL MergeTwoDoc(FR_MERGRINFO info1, FR_MERGRINFO info2, FS_LPCWSTR destFilePath);

   //************************************
   // Function:  GetCurrentTool
   // Param[in]: pDoc			The input FR_Document.	
   // Return:	FR_Tool  Get current tool of the FR_Document.
   // Remarks: Get current tool of the FR_Document.
   // Notes:	
   //************************************
	static FR_Tool GetCurrentTool(FR_Document pDoc);

   //************************************
   // Function:  IsDocumentShowLineWeights
   // Param[in]: pDoc			The input FR_Document.	
   // Return:	FS_BOOLEAN      true: User check the line weight in view setting.
   // Remarks: Get if user check the line weight in view setting.
   // Notes:	
   // Deprecated: Internal use.
   //************************************
	static FS_BOOLEAN	IsDocumentShowLineWeights(FR_Document pDoc);

	//************************************
	// Function:  IsCurDocViewShowInContainerFrm
	// Param[in]: pDoc			The input FR_Document.	
	// Return:	FS_BOOL     
	// Remarks: Get if the current doc view show in container.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL		IsCurDocViewShowInContainerFrm(FR_Document pDoc);

	//************************************
	// Function:  MovePages2
	// Param[in]: pReaderDoc     The input FR_Document.	
	// Param[in]: nMoveAt        The dest index of moved to.
	// Param[in]: arrMovePages   The pageindex array need to move.
	// Param[in]: progress       The input FR_UIProgress.
	// Return: FS_BOOL   TRUE move success.
	// Remarks: Move specified pages.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	//************************************
	static FS_BOOL	MovePages2(FR_Document pReaderDoc, FS_INT32 nMoveAt, FS_WordArray arrMovePages, FR_UIProgress progress);

	//************************************
	// Function:  RemoveAnnotSelection
	// Param[in]: pDoc			The input FR_Document.	
	// Param[in]: annot			The input annot.	
	// Return:	void     
	// Remarks: Remove the annot selection.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// Deprecated: Internal use.
	//************************************
	static void RemoveAnnotSelection(FR_Document pDoc, FR_Annot annot);

	//************************************
	// Function:  DoSaveAsWithDefaultPath
	// Param[in]: doc			The FR_Document need to save as.
	// Param[in]: saveAsPath	The default save path.
	// Return:	void
	// Remarks: Displays a file save as dialog with default path which can be used to save the document as a new name.	  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See: FRDocDoSaveAsWithDefaultPath
	//************************************
	static void	 DoSaveAsWithDefaultPath(FR_Document doc, FS_LPCWSTR saveAsPath);

	//************************************
	// Function: SplitPageByRects
	// Param[in]: doc			The input FR_Document obj.
	// Param[in]: nPageIndex	The input page index.
	// Param[in]: rects	        Split the page according to the specified rect array.
	// Param[in]: postion	    The insert page position after split the page.	
	// Return:   FS_BOOLEAN     true: split success.
	// Remarks:  Split page by specified rect array.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	//************************************
	static FS_BOOLEAN SplitPageByRects(FR_Document doc, FS_INT32 nPageIndex, FS_FloatRectArray rects, FS_INT32 postion);

	//************************************
	// Function:  IsEmbeded
	// Param[in]: doc			The current FR_Document obj.
	// Return:	FS_BOOL
	// Remarks: Check if the input FR_Document is embeded.	  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// See: FRDocIsEmbeded
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsEmbeded(FR_Document doc);

	//************************************
	// Function:  GetSaveSaveAsNotify
	// Param[in]: doc			The current FR_Document obj.
	// Return:	FR_Save_SaveAsNotify
	// Remarks: Get FR_Save_SaveAsNotify obj.	  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// See: FRDocGetSaveSaveAsNotify
	// Deprecated: Internal use.
	//************************************
	static FR_Save_SaveAsNotify GetSaveSaveAsNotify(FR_Document doc);

	//************************************
	// Function:  SetSaveSaveAsNotify
	// Param[in]: doc			The current FR_Document obj.
	// Param[in]: notify		The current FR_Save_SaveAsNotify obj.
	// Return:	void
	// Remarks: Set FR_Save_SaveAsNotify obj.	  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	// See: FRDocSetSaveSaveAsNotify
	// Deprecated: Internal use.
	//************************************
	static void SetSaveSaveAsNotify(FR_Document doc, FR_Save_SaveAsNotify notify);

	//************************************
	// Function:  GetCanReopen
	// Param[in]: doc			The current FR_Document obj.	
	// Return:	FS_BOOL   TRUE means can reopen, otherwise can't.
	// Remarks: Check if the doc can reopen. 	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: FRDocGetCanReopen
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	GetCanReopen(FR_Document doc);

	//************************************
	// Function:  SetTopmostAnnot
	// Param[in]: doc			The current FR_Document obj.
	// Param[in]: pAnnot		The input FR_Annot.
	// Return:	FS_BOOLEAN
	// Remarks: Set top most annot.	  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN SetTopmostAnnot(FR_Document doc, FR_Annot pAnnot);

	//************************************
	// Function:  OnAfterRotatePages
	// Param[in]: pDoc			The current FR_Document obj.
	// Param[in]: arrPages		The input pages.
	// Param[in]: nRotate		The input rotate value.
	// Return:	void
	// Remarks: Notify after rotate pages.	  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void	OnAfterRotatePages(FR_Document pDoc, const FS_WordArray arrPages, FS_INT32 nRotate);

	//************************************
	// Function:  SetPageLabel
	// Param[in]: pDoc			The current FR_Document obj.
	// Param[in]: option		The input FR_PageLabelOption.
	// Return:	void
	// Remarks: Set page label.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See:
	//************************************
	static void SetPageLabel(FR_Document pDoc, FR_PageLabelOption option);

	//************************************
	// Function:  RunOCR
	// Param[in]: pParent			The specified parent HWND. If OCR is not executed in the specified window, it can be FRAppGetMainFrameWnd.
	// Param[in]: settingInfo		The specified settings, like ocr language, mode.
	//                              If set to null, OCR will be performed according to the default settings of the current editor.
	// Param[in]: bShowProgress		If need show progress bar.
	// Return:	FS_BOOLEAN
	// Remarks: Execute OCR operations on current actived document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN RunOCR(FS_HWND pParent, const FR_OCRSettingInfo* settingInfo, FS_BOOLEAN  bShowProgress);

	//************************************
	// Function:  RunPageOCR
	// Param[in]: pPDFPage			The specified page that need to execute OCR.
	// Param[in]: settingInfo		The specified settings, like ocr language, mode.
	//                              If set to null, OCR will be performed according to the default settings of the current editor.
	// Param[in]: bShowProgress		If need show progress bar.
	// Return:	FS_BOOLEAN
	// Remarks: Execute OCR operations on specified page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	// See:
	//************************************
	static FS_BOOLEAN RunPageOCR(FPD_Page pPDFPage, const FR_OCRSettingInfo* settingInfo, FS_BOOLEAN  bShowProgress);

	//************************************
	// Function:  CreateOrganizeNotify
	// Param[in]: callback    The input FR_OrganizeNotifyCallbacks.
	// Return: FR_OrganizeNotify 	      
	// Remarks: Construct FR_OrganizeNotify object.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	// Deprecated: Internal use.
	//************************************
	static FR_OrganizeNotify CreateOrganizeNotify(FR_OrganizeNotifyCallbacks callback);

	//************************************
	// Function:  DestroyOrganizeNotify
	// Param[in]: notify    The input FR_OrganizeNotify object.	
	// Return: void
	// Remarks: Destory FR_OrganizeNotify object.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	// Deprecated: Internal use.
	//************************************
	static void DestroyOrganizeNotify(FR_OrganizeNotify notify);

	//************************************
	// Function:  ExtractPages3
	// Param[in]: pReaderDoc    The input FR_Document.	
	// Param[in]: pFile         Extract pages to temp file.
	// Param[in]: arrExtraPages The page array need to extract.
	// Param[in]: notify        The input FR_OrganizeNotify object.
	// Return: FS_BOOL 	      TRUE extract pages success.
	// Remarks: Extract pages to temp file.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL ExtractPages3(FR_Document pReaderDoc, FS_FileWriteHandler pFile, FS_WordArray arrExtraPages, FR_OrganizeNotify notify);
};

class CFR_CustomSignature_V8
{
public:
	//************************************
	// Function:  GenerateSignInfo
	// Param[in]: pSgInfo		To fill the signature info.
	// Param[in]: pSgPosInfo	To fill the signature position info.
	// Return:	TRUE for success, otherwise failure.
	// Remarks: Signs a PDF document with the <a>FR_SignatureInfo</a> and <a>FR_SignaturePosInfo</a>. You have to register the signature
	// handler by <a>FRCustomSignatureRegisterSignatureHandler</a>to sign the data, otherwise the data will be signed with the default standard method.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2	
	//************************************	
	static FS_BOOL GenerateSignInfo(FR_SignatureInfo* pSgInfo, FR_SignaturePosInfo* pSgPosInfo);

	//************************************
	// Function:  GetDefaultServer
	// Param[out]: pSgTMServer	It receives the default timestamp server.
	// Return:	TRUE for success, otherwise failure.
	// Remarks: Gets the default timestamp server.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2	
	//************************************	
	static FS_BOOL GetDefaultServer(FR_SignatureTimestampServer* pSgTMServer);

	//************************************
	// Function:  CreateSignatureHandler
	// Param[in]: callbacks	The callback set for signature handler. 
	// Return:	The pointer to the signature handler.
	// Remarks: Creates the signature handler. Registers it by <a>FRCustomSignatureRegisterSignatureHandler</a>. Destroys it by <a>FRCustomSignatureDestroySignatureHandler</a>.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2	
	//************************************
	static void* CreateSignatureHandler(FR_SignatureHandlerCallbacks callbacks);

	//************************************
	// Function:  RegisterSignatureHandler
	// Param[in]: pSignatureHandler	The input pointer to signature handler.
	// Return:	TRUE for success, otherwise failure.
	// Remarks: Registers the signature handler. You can customize the process signing the data and the process verifying the digital signature.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2	
	//************************************
	static FS_BOOL RegisterSignatureHandler(void* pSignatureHandler);

	//************************************
	// Function:  DestroySignatureHandler
	// Param[in]: pSignatureHandler	The input pointer to signature handler. 
	// Return:	void.
	// Remarks: Destroys the signature handler returned by <a>FRCustomSignatureCreateSignatureHandler</a>.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2	
	//************************************
	static void DestroySignatureHandler(void* pSignatureHandler);

	//************************************
	// Function:  SetSignatureVerify
	// Param[in]: frDoc				The input document.		
	// Param[in]: pSignedData		The signed data.
	// Param[in]: ulSignedDataLen	The length of the signed data.
	// Return:	TRUE for success, otherwise failure.
	// Remarks: Verifies whether the document was signed with the specified signature.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3	
	//************************************
	static FS_BOOL SetSignatureVerify(FR_Document frDoc, const unsigned char* pSignedData, unsigned long ulSignedDataLen);

	//************************************
	// Function:  GetDocSigatureCount
	// Param[in]: frDoc	The input document.
	// Return:	The signature count.
	// Remarks: Gets the signature count.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FS_INT32 GetDocSigatureCount(FR_Document frDoc);

	//************************************
	// Function:  GetSignatureBaseInfo
	// Param[in]: frDoc		The input document.
	// Param[in]: nIndex	The index of the signature.
	// Param[out]: pInfo	It receives the base info of the signature.
	// Return:	TRUE for success, otherwise failure.
	// Remarks: Gets the specified base info of the signature.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FS_BOOL GetSignatureBaseInfo(FR_Document frDoc, FS_INT32 nIndex, FR_SignatureBaseInfo* pInfo);

	//************************************
	// Function:  ClearSignature
	// Param[in]: frDoc		The input document.
	// Param[in]: nIndex	The index of the signature.
	// Return:	TRUE for success, otherwise failure.
	// Remarks: Clears the specified index signature.
	// Notes: If the current user is not the issuer of the certificate, it can't be clear.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	//************************************
	static FS_BOOL ClearSignature(FR_Document frDoc, FS_INT32 nIndex);

	//************************************
	// Function:  FoxitSignInScope
	// Param[in]: frDoc		The input document.
	// Param[in]: pAnnotDict The sign dictionary.
	// Return:	TRUE for success, otherwise failure.
	// Remarks:  Check dictionary of sign in scope.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated:  Current function has been deprecated, it not be implemented.
	//************************************
	static FS_BOOL FoxitSignInScope(FR_Document frDoc, FPD_Object pAnnotDict);

	//************************************
	// Function:  FoixtCreateSignatureF
	// Param[in]: frDoc		    The input document.
	// Param[in]: bSetSignS  	If set sign.
	// Return:	FPD_Object      The dictionary object of the signature field.
	// Remarks: The dictionary object of the signature field.
	// Notes: It used for SetPosition to set position of the signature.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See:  FRCustomSignatureSetPosition.	
	//************************************
	static FPD_Object FoixtCreateSignatureF(FR_Document frDoc, FS_BOOL bSetSignS);

	//************************************
	// Function:  SetPosition
	// Param[in]: pageViewer		    The input document.
	// Param[in]: objDict  	            The sign dictionary.
	// Param[in]: rcSig  	            The sign rect.
	// Return:	FPD_Object      The dictionary object of the signature field.
	// Remarks: The dictionary object of the signature field.
	// Notes: It used for SetPosition to set position of the signature.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See:  FRCustomSignatureSetPosition.	
	//************************************
	static void SetPosition(FR_PageView pageViewer, FPD_Object objDict, const FS_FloatRect rcSig);

	//************************************
	// Function:  GenerateSignInfo2
	// Param[in]: pSgInfo		To fill the signature info.
	// Param[in]: pSgPosInfo	To fill the signature position info.
	// Param[in]: bopenSignDoc	If need open the doc after sign.
	// Param[in]: pExinfo	    To fill the signature info.
	// Return:	TRUE for success, otherwise failure.
	// Remarks: Signs a PDF document with the <a>FR_SignatureInfo</a> and <a>FR_SignaturePosInfo</a>. You have to register the signature
	// handler by <a>FRCustomSignatureRegisterSignatureHandler</a>to sign the data, otherwise the data will be signed with the default standard method.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0	
	//************************************	
	static FS_BOOL GenerateSignInfo2(FR_SignatureInfo* pSgInfo, FR_SignaturePosInfo* pSgPosInfo, FS_BOOLEAN bopenSignDoc, FR_SignatureExtendInfo* pExinfo);

	//************************************
	// Function:  PrepareSign
	// Param[in]: doc		            The input document that need to sign.	
	// Return:	void
	// Remarks: It used to backup original file.
	// Notes: It has to be called before multiple signatures are created consecutively.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:  FRCustomSignaturePrepareSign.	
	//************************************
	static void PrepareSign(FR_Document doc);
};

class CFR_ReaderInterform_V13
{
public:
	//************************************
	// Function:  SetPosition
	// Param[in]: frInerForm	   The input FR_ReaderInterform. It get from FRDocGetInterForm.
	// Return:	FPD_InterForm      FPD_InterForm
	// Remarks: Get FPD_InterForm from FRDoc, when chaged form field, that will resetAppearance, not need to call ResetAppearance.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See:  FRReaderInterformGetInterForm.
	//************************************
	static  FPD_InterForm	GetInterForm(FR_ReaderInterform frInerForm);

	//************************************
	// Function:  LoadImageFromFile
	// Param[in]: frInerForm	   The input FR_ReaderInterform.
	// Param[in]: sFile	           The image file path.
	// Param[in]: nWidth	       The image width.
	// Param[in]: nHeight	       The image height.
	// Return:	FPD_Object    
	// Remarks: Create CPDF_Stream of image to document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See:  FRReaderInterformGetInterForm.
	// Deprecated: Internal use.
	//************************************
	static  FPD_Object		LoadImageFromFile(FR_ReaderInterform frInerForm, const FS_WideString sFile, FS_INT32 nWidth, FS_INT32 nHeight);
	
	//************************************
	// Function:  ResetFieldAppearance
	// Param[in]: frInerForm	   The input FR_ReaderInterform.
	// Param[in]: pFormField	   The input form field.
	// Param[in]: sValue	       The field value.
	// Param[in]: bValueChanged	   If need to change the field value.
	// Param[in]: bNeedFormat	   If need format field value.
	// Return:	FS_INT32    
	// Remarks: Reset field appearance with format value.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See:  FRReaderInterformResetFieldAppearance.
	// Deprecated: Internal use.
	//************************************
	static  FS_INT32		ResetFieldAppearance(FR_ReaderInterform frInerForm, FPD_FormField pFormField, FS_LPCWSTR sValue, FS_BOOL bValueChanged, FS_BOOL bNeedFormat);
	
	//************************************
	// Function:  OnCalculate
	// Param[in]: frInerForm	   The input FR_ReaderInterform.
	// Param[in]: pFormField	   The input form field.
	// Param[in]: nPage	           The pageindex.	
	// Return:	FS_INT32    
	// Remarks: Calculate form field.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See:  FRReaderInterformOnCalculate.
	// Deprecated: Internal use.
	//************************************
	static  FS_INT32		OnCalculate(FR_ReaderInterform frInerForm,FPD_FormField pFormField, FS_INT32 nPage);

	//************************************
	// Function:  OnCalculate2
	// Param[in]: frInerForm	   The input FR_ReaderInterform.
	// Param[in]: nPage	           The pageindex.	
	// Return:	FS_INT32    
	// Remarks: Calculate form field in page index.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See:  FRReaderInterformOnCalculate2.
	// Deprecated: Internal use.
	//************************************
	static  FS_INT32		OnCalculate2(FR_ReaderInterform frInerForm, FS_INT32 nPage);

	//************************************
	// Function:  IsFormFieldInPage
	// Param[in]: frInerForm	   The input FR_ReaderInterform.
	// Param[in]: pFormField	   The input form field.	
	// Param[in]: nPage	           The pageindex.	
	// Return:	FS_BOOL    
	// Remarks: Check if the form field in input page.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See:  FRReaderInterformIsFormFieldInPage.
	// Deprecated: Internal use.
	//************************************
	static  FS_BOOL			IsFormFieldInPage(FR_ReaderInterform frInerForm, FPD_FormField pFormField, FS_INT32 nPage);

	//************************************
	// Function:  GetBFinterform
	// Param[in]: frInerForm	   The input FR_ReaderInterform.		
	// Param[in]: nPage	           The pageindex.	
	// Return:	FR_CBFInterForm    
	// Remarks: Get FR_CBFInterForm from frInerForm.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// See:  FRReaderInterformGetBFinterform.
	// Deprecated: Internal use.
	//************************************
	static  FR_CBFInterForm GetBFinterform(FR_ReaderInterform frInerForm);

	//************************************
	// Function:  IsHighLight
	// Param[in]: frInerForm	   The input FR_ReaderInterform.	
	// Return:	FS_BOOLEAN    
	// Remarks: Check if the form is hightlight.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	IsHighLight(FR_ReaderInterform frInerForm);

	//************************************
	// Function:  GetBarCodeRenderBitmap
	// Param[in]: frInerForm	   The input FR_ReaderInterform.
	// Param[in]: pControl	       The input FPD_FormControl.	
	// Param[out]: mtTmp	       Get the matrix of render bar code.	
	// Return:	FS_DIBitmap    
	// Remarks: Get the bitmap of bar code render.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_DIBitmap	GetBarCodeRenderBitmap(FR_ReaderInterform frInerForm, FPD_FormControl pControl, FS_AffineMatrix* mtTmp);

	//************************************
	// Function:  DeleteInterForm
	// Param[in]: frInerForm	   The input FR_ReaderInterform.
	// Param[in]: pRDDoc	       The input FR_Document.	
	// Return:	void    
	// Remarks: Delete inter form.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void				DeleteInterForm(FR_ReaderInterform frInerForm, FR_Document pRDDoc);
};

class CFR_UndoItemCreateWidget_V14 //Internal use
{
public:
	static FR_UndoCreateWidget          CreateUndoWidget(FR_Document frDoc, FS_INT32 nPageIndex, FPD_Object pFieldDict, FPD_Object pAnnotDict, const FS_INT32 nTabOrder);
	static void							Undo(FR_UndoCreateWidget undoWidget);
	static void							Redo(FR_UndoCreateWidget undoWidget);
	static void    				        GetDescr(FR_UndoCreateWidget undoWidget, FS_WideString* outDesc);
	
};

class CFR_CRSAStamp_V14 //Internal use
{
public:
	static FR_CRSAStamp New();
	static void Destroy(FR_CRSAStamp rStamp);
	static FS_INT32 GetLeftValue(FR_CRSAStamp rStamp);
	static FS_INT32 GetTopValue(FR_CRSAStamp rStamp);
	static FS_INT32 GetDefaultCropWValue(FR_CRSAStamp rStamp);	
	static void SetDefaultCropWValue(FR_CRSAStamp rStamp, FS_INT32 width);
	static FS_INT32 GetDefaultCropHValue(FR_CRSAStamp rStamp);
	static void SetDefaultCropHValue(FR_CRSAStamp rStamp, FS_INT32 height);
	static FS_INT32 GetDefaultWValue(FR_CRSAStamp rStamp);
	static void SetDefaultWValue(FR_CRSAStamp rStamp, FS_INT32 width);
	static FS_INT32 GetDefaultHValue(FR_CRSAStamp rStamp);
	static void SetDefaultHValue(FR_CRSAStamp rStamp, FS_INT32 height);
	static FS_FLOAT GetWidthValue(FR_CRSAStamp rStamp);
	static void SetWidthValue(FR_CRSAStamp rStamp, FS_FLOAT width);
	static FS_FLOAT GetHeightValue(FR_CRSAStamp rStamp);
	static void SetHeightValue(FR_CRSAStamp rStamp, FS_FLOAT height);
	static FS_BOOL IsPath(FR_CRSAStamp rStamp);
	static void SetPath(FR_CRSAStamp rStamp,FS_BOOL bPath);
	static FS_DIBitmap GetDIBitmap(FR_CRSAStamp rStamp);
	static void SetDIBitmap(FR_CRSAStamp rStamp, FS_DIBitmap pDIB);
	static FS_BOOL IsPDFSignStamp(FR_CRSAStamp rStamp);
	static void GetPDFPath(FR_CRSAStamp rStamp, FS_WideString* wsPath);
	static FS_BOOL IsDynamic(FR_CRSAStamp rStamp);
	static void GetEncode(FR_CRSAStamp rStamp, FS_ByteString* bsEncode);
	static FS_INT32 GetStampType(FR_CRSAStamp rStamp);
	static void SetPageIdx(FR_CRSAStamp rStamp,FS_INT32 nPage);
	static FS_INT32 GetPageIdx(FR_CRSAStamp rStamp);
	static FS_BOOL PreViewArtBoxFile(FR_CRSAStamp rStamp,FPD_Document pPDFDoc, FS_INT32 nIndex, FS_DIBitmap pDIBitmap);
	static void GetStampName(FR_CRSAStamp rStamp, FS_WideString* wsName);
	static FS_BOOL IsFavorite(FR_CRSAStamp rStamp);
	static FS_BOOL SetPagePieceInfo(FR_CRSAStamp rStamp, FR_PIECE_INFO_KEY nType);
	static FS_BOOL SetPagePieceInfoByDoc(FR_CRSAStamp rStamp, FPD_Document pPDFDoc, FR_PIECE_INFO_KEY nType);
	static FS_BOOL GetIsRotate(FR_CRSAStamp rStamp);
	static FS_INT32  RemovePage(FR_CRSAStamp rStamp);
	static void  Copy(FR_CRSAStamp dStamp, FR_CRSAStamp rStamp);
	static FS_INT32	GetPageFromName(FPD_Document pPDFDoc, const FS_WideString wStrPageName);
	static void		SetStampName(FR_CRSAStamp rStamp, const FS_WideString& cwStampName);
	static void SetPDFPath(FR_CRSAStamp rStamp, const FS_WideString& cwPDFPath);
	static void SetAppCloseDelete(FR_CRSAStamp rStamp, FS_BOOL bDelete);
	static void SetType(FR_CRSAStamp rStamp, const FS_ByteString& byteType);	
	static void SetEncode(FR_CRSAStamp rStamp, const FS_LPCSTR& strEncode);
	static void SetSignListIdx(FR_CRSAStamp rStamp, FS_INT32 nIdx);
	static FS_BOOL GetPDFStamp(FR_CRSAStamp rStamp);
	static FS_BOOL SaveStampToPage(FR_CRSAStamp pStamp);
	static FPD_Object GetSampInfoDic(FPD_Object pPageDic, FPD_Document pPDFDoc, FS_BOOL bAdd);
	static void AddPageName(FPD_Document pPDFDoc, FS_INT32 nPageIdx, FS_WideString* strPageName, FS_BOOL bPageNamePrefix);
	static void SetLeftValue(FR_CRSAStamp rStamp, FS_FLOAT left);
	static void SetTopValue(FR_CRSAStamp rStamp, FS_FLOAT top);	
	static void SetDynamic(FR_CRSAStamp rStamp, FS_BOOL bDynamic);
	static void SetFavorite(FR_CRSAStamp rStamp, FS_BOOL bFav);
	static void GetType(FR_CRSAStamp rStamp, FS_ByteString* type);
	static void SetIsRotate(FR_CRSAStamp rStamp, FS_BOOL bRotate);
	static FRRS_PASSWORD CheckPDFPermission(FR_CRSAStamp rStamp, FS_WideString cwFileName, FS_WideString* wsRemoveSecPath, FPD_Parser parser, FS_BOOLEAN bPretect);
	static FS_BOOL FSFadeOutImageBackground(const FS_DIBitmap pDib,FS_DIBitmap* pDib_with_mask,FREnhancementAlogrithms enhAlgo,	FS_LPVOID enhParams,FRThreshAlogrithm threshAlgo, FS_LPVOID threshParams);	
	static void SetTip(FR_CRSAStamp rStamp, const FS_WideString cwTip);
	static void SetTemplateName(FR_CRSAStamp rStamp, const FS_WideString csTemplateName);
	static void SetThumbNail(FR_CRSAStamp rStamp, const FS_WideString cwThumbnail);
	static void SetCanParser(FR_CRSAStamp rStamp, FS_BOOL bCanParser);
	static void SetImage(FR_CRSAStamp rStamp, FS_BOOL bImage);
	static void SetOpacity(FR_CRSAStamp rStamp, FS_INT32 nOpacity);
	static void GetSignFilePwd(const FS_WideString wStrSignPassword, FS_WideStringArray* fileArray, FS_ByteStringArray* pwdArray);
	static void GetStampFormPage(FR_CRSAStamp rStamp, FPD_Page pPage);
	static void SaveStampToPage2(FPD_Document pPDFDoc, FR_CRSAStamp pRStamp);
	static FS_INT32 GetSignListIdx(FR_CRSAStamp rStamp);
	static void SetStampGuid(FR_CRSAStamp rStamp, const FS_WideString cwStampGuid);
	static void GetStampGuid(FR_CRSAStamp rStamp, FS_WideString* wsGuid);
};

class CFR_MarkupAnnot_V14 //Internal use
{
public:
	static FR_MarkupAnnot Create(FPD_Annot pAnnot, FR_PageView pPageView);
	static void Destroy(FR_MarkupAnnot annot);
	static FS_BOOL IsGroup(FR_MarkupAnnot annot);
	static FS_BOOL IsHeader(FR_MarkupAnnot annot);
	static FR_MarkupPopup GetPopup(FR_MarkupAnnot annot,FS_BOOL bCreate);
	static void ResetAppearance(FR_MarkupAnnot annot);
	static void SetModifiedDateTime(FR_MarkupAnnot annot, FS_ReaderDateTime dt);
	static FS_BOOL GetModifiedDateTime(FR_MarkupAnnot annot, FS_ReaderDateTime* dt);
	static FS_FloatPoint  GetHotPoint(FR_MarkupAnnot annot);
	static FS_BOOL GetColor(FR_MarkupAnnot annot, FS_COLORREF* color);
	static void MovedOutPage(FR_MarkupAnnot annot, FR_Page pSrcPage, FR_Page pDestPage);
};

class CFR_MarkupPopup_V14 //Internal use
{
public:
	static void UpdateDataTime(FR_MarkupPopup popup, FR_PageView pPageView);
	static void SetNoteAnchor(FR_MarkupPopup popup, FS_FloatPoint cpPoint, FR_PageView pPageView);
	static void ShowRope(FR_MarkupPopup popup, FS_BOOL bShow, FR_PageView pPageView);
	static FS_BOOL IsNoteVisible(FR_MarkupPopup popup, FR_PageView pPageView);
	static void   UpdateNote(FR_MarkupPopup popup, FR_PageView pPageView, FS_BOOL bCreateIfPageInvisible);
	static void ResetNotePosition(FR_MarkupPopup popup, FR_PageView pPageView);
	static FR_Annot      GetPopupAnnot(FR_MarkupPopup popup);	
	static FS_FloatRect GetRect(FR_MarkupPopup popup);	
	static FS_BOOL SetState(FR_MarkupPopup popup, FS_BOOL bOpen);
	static void  ShowNote(FR_MarkupPopup popup, FS_BOOL bShow, FR_PageView pageView);	
	static void SetNoteFocus(FR_MarkupPopup popup, FS_BOOL bSet, FR_PageView pageView);
	static void AddReply(FR_MarkupPopup popup, FR_PageView pageView);	
};

class CFR_MarkupPanel_V14
{
public:
	//************************************
	// Function:  GetMarkupPanel	
	// Return: FR_MarkupPanel	   The object of comments panel, it show all markupannots in page.
	// Remarks: When add,delete,change markup annot, you can use FR_MarkupPanel to refresh comments panel. 	
	// Notes: 	
	// See: FRMarkupPanelGetMarkupPanel
	//************************************
	static FR_MarkupPanel GetMarkupPanel();

	//************************************
	// Function:  RefreshAnnot	
	// Param[in]: panel				The <a>FR_MarkupPanel</a> object.
	// Param[in]: pAnnot			The annot need to refresh.
	// Param[in]: bRedrawPanel		Whether to redraw panel.
	// Return: FS_BOOL	            TRUE for refresh annot success, otherwise failure.
	// Remarks: When change markup annot, you need to refresh annots in comments panel. 	
	// Notes: 	
	// See: FRMarkupPanelRefreshAnnot
	//************************************
	static FS_BOOL RefreshAnnot(FR_MarkupPanel panel, FR_Annot pAnnot, FS_BOOL bRedrawPanel);

	//************************************
	// Function:  ReloadAnnots	
	// Param[in]: panel				The <a>FR_MarkupPanel</a> object.
	// Param[in]: pDoc			    The current document.
	// Return: FS_BOOL	            TRUE for reload annot success, otherwise failure.
	// Remarks: When delete markup annot, you need to reload annots in comments panel. 	
	// Notes: 	
	// See: FRMarkupPanelReloadAnnots
	//************************************
	static FS_BOOL ReloadAnnots(FR_MarkupPanel panel,FR_Document pDoc);

	//************************************
	// Function:  AddAnnot	
	// Param[in]: panel				The <a>FR_MarkupPanel</a> object.
	// Param[in]: pDoc			    The current document.
	// Param[in]: bRedrawPanel		Whether to redraw panel.
	// Param[in]: bShow			    Whether show the annot.
	// Return: FS_BOOL	            TRUE for add annot success, otherwise failure.
	// Remarks: When create markup annot, you need to annot annot to comments panel. 	
	// Notes: 	
	// See: FRMarkupPanelAddAnnot
	//************************************
	static FS_BOOL AddAnnot(FR_MarkupPanel panel, FR_Annot pAnnot, FS_BOOL bRedrawPanel, FS_BOOL bShow);

	//************************************
	// Function:  SetFocus	
	// Param[in]: panel				The <a>FR_MarkupPanel</a> object.
	// Param[in]: pAnnot			The annot need to be focus.	
	// Return: FS_BOOL	            TRUE for set annot focus success, otherwise failure.
	// Remarks: When create markup annot, you need to annot annot to comments panel. 	
	// Notes: 	
	// See: FRMarkupPanelSetFocus
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL SetFocus(FR_MarkupPanel panel, FR_Annot pAnnot);

	//************************************
	// Function:  UpdatePropertyBox		
	// Return: void	         
	// Remarks: Update property box. 	
	// Notes: 	
	// See: FRMarkupPanelUpdatePropertyBox
	// Deprecated: Internal use.
	//************************************
	static void UpdatePropertyBox();

	//************************************
	// Function:  AddToCreateList		
	// Param[in]: pAnnot			The current annot.	
	// Return: void	           
	// Remarks: Add annot to create list. 	
	// Notes: 	
	// See: FRMarkupPanelAddToCreateList
	// Deprecated: Internal use.
	//************************************
	static void AddToCreateList(FR_Annot pAnnot);

	//************************************
	// Function:  HideHint			
	// Return: void	           
	// Remarks: Hide hint of annot. 	
	// Notes: 	
	// See: FRMarkupPanelHideHint
	// Deprecated: Internal use.
	//************************************
	static void HideHint();

	//************************************
	// Function:  RemoveAnnot		
	// Param[in]: panel			The <a>FR_MarkupPanel</a> object.
	// Param[in]: pAnnot		The annot need to remove.
	// Param[in]: bRedrawPanel	Whether need to redraw comments panel.
	// Return: FS_BOOL	        TRUE for set annot focus success, otherwise failure.        
	// Remarks: Remove annot from comments panel. 	
	// Notes: 	
	// See: FRMarkupPanelRemoveAnnot
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	RemoveAnnot(FR_MarkupPanel panel, FR_Annot pAnnot, FS_BOOL bRedrawPanel);

	//************************************
	// Function:  ShowAnnot		
	// Param[in]: panel			The <a>FR_MarkupPanel</a> object.
	// Param[in]: pAnnot		The annot need to remove.
	// Param[in]: bShow		    If show the annot.
	// Param[in]: bRedrawPanel	Whether need to redraw comments panel.
	// Return: FS_BOOL	        TRUE for show the annot.      
	// Remarks: Show annot from comments panel. 	
	// Notes: 	
	// See: FRMarkupPanelShowAnnot
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	ShowAnnot(FR_MarkupPanel panel, FR_Annot pAnnot, FS_BOOL bShow, FS_BOOL bRedrawPanel);
};

class CFR_CRSASStampAnnot_V14 //Internal use
{
public:
	static FR_CRSASStampAnnot New(FPD_Annot pAnnot, FR_Page pPage);
	static void Destroy(FR_CRSASStampAnnot stampAnnot);
	static void SetStamp(FR_CRSASStampAnnot stampAnnot, FR_CRSAStamp srcStamp);
	static void AfterMovePages(FR_CRSASStampAnnot stampAnnot, FS_INT32 nSrcRotate, FS_INT32 nDesRotate);
	static void	ResetAppearance(FR_CRSASStampAnnot stampAnnot);
	static void SetColor(FR_CRSASStampAnnot stampAnnot, FS_COLORREF color, FS_BOOL bTransparent);
	static void SetOpacity(FR_CRSASStampAnnot stampAnnot, FS_INT32 nOpacity);
	static void SetCreationDateTime(FR_CRSASStampAnnot stampAnnot, FS_ReaderDateTime dt);
	static FS_BOOL GetModifiedDateTime(FR_CRSASStampAnnot stampAnnot, FS_ReaderDateTime* dt);
	static FR_MarkupPopup GetPopup(FR_CRSASStampAnnot stampAnnot, FS_BOOL bCreate);
	static FS_FloatPoint GetHotPoint(FR_CRSASStampAnnot stampAnnot);
	static void GetType(FR_CRSASStampAnnot stampAnnot, FS_ByteString* bsType);
	static FS_BOOL IsGroup(FR_CRSASStampAnnot stampAnnot);
	static FS_BOOL IsHeader(FR_CRSASStampAnnot stampAnnot);
	static void SetModifiedDateTime(FR_CRSASStampAnnot stampAnnot, FS_ReaderDateTime  dt);
	static FS_BOOL   GetColor(FR_CRSASStampAnnot stampAnnot, FS_COLORREF* color);
	static FR_Page GetReaderPage(FR_CRSASStampAnnot stampAnnot);
};

class CFR_EncryptPermisson_V14 //Internal use
{
public:
	static FR_EncryptPermisson CreateEncryptPermisson();
	static FS_DWORD		SetEncryptPermisson(FR_EncryptPermisson permission, const FR_ENPermission enpermisson);
	static void			GetEncryptPermisson(FR_EncryptPermisson permission, const FS_DWORD &dwPermisson, FR_ENPermission& enpermisson);
	static FS_BOOL		GetPropertyPermisson(FR_EncryptPermisson permission, const FS_DWORD& dwPermisson, const FRPROPERTITY_PERMISSON properisson);
	static FS_DWORD		GetAllPermission(FR_EncryptPermisson permission);
	static void		    DeleteEncryptPermission(FR_EncryptPermisson permission);
};


class CFR_CSGCertFileManage_V14 //Internal use
{
public:
	static FR_CSGCertFileManage CreateCertFileManage();
	static void Destroy(FR_CSGCertFileManage filemanage);
	static void  GetCertFileStorePath(FR_CSGCertFileManage filemanage, FS_WideString* filePath);
	static FS_BOOL	NewCertData(FR_CSGCertFileManage filemanage, FS_WideString ws1, FS_WideString ws2, FS_LPVOID store);
	static FS_LPVOID		LoadStore(FR_CSGCertFileManage filemanage);
	static FS_BOOL			GetPathAndPassword(FR_CSGCertFileManage filemanage, FS_LPVOID pCertContext, FS_WideString& cwFilePath, FS_WideString& cwPassWord);
	static FS_BOOL			UpdateFile(FR_CSGCertFileManage filemanage, FS_BOOL bReloadCertFile);
	static void	Base64ToString(FR_CSGCertFileManage filemanage, FS_WideString str, FS_WideString* outBaseStr);
	static void	StringToBase64(FR_CSGCertFileManage filemanage, FS_WideString str, FS_WideString* outBaseStr);
	static FS_BOOL			ReloadAllFile(FR_CSGCertFileManage filemanage, FS_LPVOID hStore, const FS_PtrArray& datas);
};


class CFR_CSG_CreateCert_V14 //Internal use
{
public:
	static FR_CSGCreateCert Create(FR_SGDataStruct pData);
	static void Destroy(FR_CSGCreateCert cert, FR_SGDataStruct pData);
	static FS_LPVOID		CreateCert(FR_CSGCreateCert cert);
	static void	GetTmpName(FR_CSGCreateCert cert, FS_ByteString& csName);
	static FS_LPVOID OpenPFXStore(FR_CSGCreateCert cert);
	static FS_LPVOID	 CreateOpenSSLCert(FR_CSGCreateCert cert);
};

class CFR_Page_V14 //Internal use
{
public:
	//************************************
	// Function:  GetDocument
	// Param[in]: page			The page whose <a>FR_Document</a> is obtained. It gets form FRDocGetPage.
	// Return: The <a>FR_Document</a> for <param>page</param>.
	// Remarks:	Gets the <a>FR_Document</a> for the document currently displayed in specified pageview.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRDocGetDocument
	// Deprecated: Internal use.
	//************************************
	static FR_Document		GetDocument(FR_Page page);

	//************************************
	// Function:  GetPage
	// Param[in]: page			The page whose <a>FPD_Page</a> is obtained.
	// Return: <a>FPD_Page</a> displayed in <param>page</param>,or <a>NULL</a> if no valid <a>FPD_Page</a>
	// associated with <param>page</param>.
	// Remarks:	Gets a <a>FPD_Page</a> currently displayed in the specified page. This do not new a
	// <a>FPD_Page</a> object. Do not use this result across methods that might change the current page.
	// To obtain a value that can be used across such calls, use <a>FPD_PageNew</a> instead.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRDocGetPage
	// Deprecated: Internal use.
	//************************************
	static FPD_Page			GetPage(FR_Page page);

	//************************************
	// Function:  ParsePage
	// Param[in]: page			The page to Parses.
	// Return: FS_BOOL 	TRUE for success, otherwise failure.
	// Remarks: Parses the specified page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRDocParsePage
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL ParsePage(FR_Page page);

	//************************************
	// Function:  GetDynPDFPage
	// Param[in]: page			The page whose <a>FPD_Page</a> is obtained.
	// Return: <a>FPD_Page</a> displayed in <param>page</param>, or <a>NULL</a> if no valid <a>FPD_Page</a>
	// associated with <param>page</param>.
	// Remarks:	If it is XFA document, it will get a <a>FPD_Page</a> currently displayed in the specified page. 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRDocGetDynPDFPage
	// Deprecated: Internal use.
	//************************************
	static FPD_Page			GetDynPDFPage(FR_Page page);

	//************************************
	// Function:  GetPageIndex
	// Param[in]: page			The page whose current page number is obtained.
	// Return: FS_INT32 The current page number, or <a>NULL</a> if <param>page</param> is invalid. The first page number of a document
	// is page 0.
	// Remarks:	Gets the current page index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageGetPageIndex
	// Deprecated: Internal use.
	//************************************
	static FS_INT32			GetPageIndex(FR_Page page);

	//************************************
	// Function:  IsPDFPageLoaded
	// Param[in]: page			The page to determine whether the page PDF is loaded.
	// Return:	FS_BOOL   TRUE for success, otherwise failure.
	// Remarks: Check whether the page PDF is loaded.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageIsPDFPageLoaded
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsPDFPageLoaded(FR_Page page);

	//************************************
	// Function:  AddAnnot
	// Param[in]: page		The input page object.
	// Param[in]: lpSubType The input annotation subtype you want to add. Like "Line","Circle".
	// Param[in]: rect      The input annotation rect you want to add.
	// Return:  FR_Annot    The UI layer annotation object.
	// Remarks:Adds the annotation to the page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageAddAnnot
	// Deprecated: Internal use.
	//************************************
	static FR_Annot AddAnnot(FR_Page page, FS_LPCSTR lpSubType, const FS_FloatRect rect);

	//************************************
	// Function:  AddAnnot2
	// Param[in]: page			The input page object.
	// Param[in]: annotDict		The input annotation dictionary you want to add.
	// Param[in]: nIndex		The index where you want to add the annotation. Sets it -1 as default.
	// Return: FR_Annot         The UI layer annotation object.
	// Remarks: Adds the annotation to the page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageAddAnnot2
	// Deprecated: Internal use.
	//************************************
	static FR_Annot AddAnnot2(FR_Page page, FPD_Object annotDict, FS_INT32 nIndex);

	//************************************
	// Function:  AddAnnot3
	// Param[in]: page			The input page object.
	// Param[in]: annot         The input FPD_Annot object.
	// Param[in]: nIndex		The index where you want to add the annotation. Sets it -1 as default.
	// Return: FR_Annot         The UI layer annotation object.
	// Remarks: Adds the annotation to the page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageAddAnnot3
	// Deprecated: Internal use.
	//************************************
	static FR_Annot AddAnnot3(FR_Page page, FPD_Annot annot, FS_INT32 nIndex);

	//************************************
	// Function:  AddDynXFAPDFAnnot
	// Param[in]: page          The input page object.
	// Param[in]: annotDict     The input annotation dictionary you want to add.
	// Return: FR_Annot         The UI layer annotation object.
	// Remarks: Adds the dynamic XFA PDF annotation to the page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageAddDynXFAPDFAnnot
	// Deprecated: Internal use.
	//************************************
	static FR_Annot AddDynXFAPDFAnnot(FR_Page page, FPD_Object annotDict);

	//************************************
	// Function:  DeleteAnnot
	// Param[in]: page		The input page object.
	// Param[in]: frAnnot	The input annotation to be deleted.
	// Return: void
	// Remarks: Deletes the specified annotation on the page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageDeleteAnnot
	// Deprecated: Internal use.
	//************************************
	static void DeleteAnnot(FR_Page page, FR_Annot frAnnot);

	//************************************
	// Function:  MoveAnnot
	// Param[in]: page		The input page object.
	// Param[in]: pageDest	The target page of moving annotation.
	// Param[in]: frAnnot	The input annotation to be moved.
	// Param[in]: index   	The annot index.
	// Return: void
	// Remarks: Move the specified annotation.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageMoveAnnot
	// Deprecated: Internal use.
	//************************************
	static void MoveAnnot(FR_Page page, FR_Page pageDest, FR_Annot frAnnot, FS_INT32 index);

	//************************************
	// Function:  CountAnnots
	// Param[in]: page			The page whose annotation count is obtained.
	// Return: FS_INT32         The number of annotations associated with <param>page</param>.
	// Remarks: Gets the number of annotations associated with specified page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageCountAnnots
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 CountAnnots(FR_Page page);

	//************************************
	// Function:  GetAnnot
	// Param[in]: page	The input page object.
	// Param[in]: index The specified index of the annotations.
	// Return: FR_Annot The specified annotation.
	// Remarks: Gets the annotation by index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageGetAnnot
	// Deprecated: Internal use.
	//************************************
	static FR_Annot GetAnnot(FR_Page page, FS_INT32 index);

	//************************************
	// Function:  GetAnnotByDict
	// Param[in]: page		The input page object.
	// Param[in]: pDict     The specified dictionary of the annotations.
	// Return: FR_Annot     The specified annotation.
	// Remarks: Gets the annotation by dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageGetAnnot
	// Deprecated: Internal use.
	//************************************
	static FR_Annot GetAnnotByDict(FR_Page page, FPD_Object pDict);

	//************************************
	// Function:  IsValidAnnot
	// Param[in]: page			The input page object.
	// Param[in]: annot         The input FR_Annot object.
	// Return:	TRUE if the point is valid.
	// Remarks: Checks whether the point is valid or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageIsValidAnnot
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsValidAnnot(FR_Page page, FS_LPVOID annot);

	//************************************
	// Function:  GetAnnotDataList
	// Param[in]: page			The input page object.
	// Return: FPD_AnnotList	a annotation data list.
	// Remarks: Get annotation data list.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageGetAnnotDataList
	// Deprecated: Internal use.
	//************************************
	static FPD_AnnotList GetAnnotDataList(FR_Page page);

	//************************************
	// Function:  GetAnnotList
	// Param[in]: page			The input page object.
	// Param[out]: outObjArray  The output annotation list.
	// Return: void
	// Remarks: Get annotation list.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageGetAnnotList
	// Deprecated: Internal use.
	//************************************
	static void GetAnnotList(FR_Page page, FS_PtrArray* outObjArray);

	//************************************
	// Function:  GetFocusAnnot
	// Param[in]: page		The input page object.
	// Return: FR_Annot     The focus annotation.
	// Remarks: Gets the focus annotation.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageGetFocusAnnot
	// Deprecated: Internal use.
	//************************************
	static FR_Annot GetFocusAnnot(FR_Page page);

	//************************************
	// Function:  SetFocusAnnot
	// Param[in]: page				The input page object.
	// Param[in]: pFocusAnnot		The input annotation.
	// Return: void
	// Remarks:	Sets the focus annotation.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageSetFocusAnnot
	// Deprecated: Internal use.
	//************************************
	static void SetFocusAnnot(FR_Page page, FR_Annot pFocusAnnot);

	//************************************
	// Function:  GetPageFirstAnnot
	// Param[in]: frDoc		The input document.
	// Param[in]: csType    The input annotation subtype you want to get.
	// Return: FR_Annot     The specified annotation.
	// Remarks: Gets the first annotation that matches the type in the page
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageGetPageFirstAnnot
	// Deprecated: Internal use.
	//************************************
	static FR_Annot GetPageFirstAnnot(FR_Page page, FS_LPCSTR csType);

	//************************************
	// Function:  GetPageLastAnnot
	// Param[in]: frDoc		The input document.
	// Param[in]: csType    The input annotation subtype you want to get.
	// Return: The specified annotation.
	// Remarks: Gets the last annotation that matches the type in the page
	// Notes:
	// Since:
	// Deprecated: Internal use.
	//************************************
	// Deprecated: Internal use.
	static FR_Annot GetPageLastAnnot(FR_Page page, FS_LPCSTR csType);

	//************************************
	// Function:  GetPagePriorAnnot
	// Param[in]: frDoc		The input document.
	// Param[in]: pAnnot    The input annotation.
	// Param[in]: csType    The input annotation subtype you want to get.
	// Return: The specified annotation.
	// Remarks: Gets the type matching annotation before the input annotation in the page
	// Notes:
	// Since:
	// Deprecated: Internal use.
	//************************************
	static FR_Annot GetPagePriorAnnot(FR_Page page, FR_Annot pAnnot, FS_LPCSTR csType);

	//************************************
	// Function:  GetPageNextAnnot
	// Param[in]: frDoc		The input document.
	// Param[in]: pAnnot    The input annotation.
	// Param[in]: csType    The input annotation subtype you want to get.
	// Return: The specified annotation.
	// Remarks: Gets the type matching annotation after the input annotation in the page
	// Notes:
	// Since:
	// Deprecated: Internal use.
	//************************************
	static FR_Annot GetPageNextAnnot(FR_Page page, FR_Annot pAnnot, FS_LPCSTR csType);

	//************************************
	// Function:  CountViews
	// Param[in]: page		The input page object.
	// Return: the number of page views
	// Remarks: Get the number of page views
	// Notes:
	// Since:
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 CountViews(FR_Page page);

	//************************************
	// Function:  GetView
	// Param[in]: page			The page whose <a>FR_PageView</a> is obtained.
	// Param[in]: index			The index of <a>FR_PageView</a>.
	// Return: The <a>FR_PageView</a> for <param>page</param>.
	// Remarks:	Gets the <a>FR_PageView</a> for specified page
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FR_PageView		GetView(FR_Page page, FS_INT32 index);

	//************************************
	// Function:  IsValidView
	// Param[in]: page		The input page object.
	// Param[in]: view		The input page view object.
	// Return: TRUE if the view is valid.
	// Remarks: Checks whether the view is valid or not.
	// Notes:
	// Since:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsValidView(FR_Page page, FR_PageView view);

	//************************************
	// Function:  GetView2
	// Param[in]: page			The input page object.
	// Param[in]: docView		The input doc view object.
	// Return: The <a>FR_PageView</a> for <param>page</param> and <param>docView</param>.
	// Remarks:	Gets the <a>FR_PageView</a> for specified page of docView
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FR_PageView		GetView2(FR_Page page, FR_DocView docView);

	//************************************
	// Function:  UpdateAllViews
	// Param[in]: page      The page whose <a>FPD_Page</a> needs to generate content.
	// Param[in]: view		The input page view object.
	// Param[in]: rectarray
	// Return:	void.
	// Remarks: Updates all views of page in the entered rect range
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1
	// Deprecated: Internal use.
	//************************************
	static void UpdateAllViews(FR_Page page, FR_PageView view, FS_FloatRectArray rectarray);

	//************************************
	// Function:  UpdateView
	// Param[in]: page      The page whose <a>FPD_Page</a> needs to generate content.
	// Param[in]: view		The input page view object.
	// Param[in]: rectarray The rect range to update
	// Return:	Updates the view of page in the entered rect range.
	// Remarks:
	// Notes:
	// Since:
	// Deprecated: Internal use.
	//************************************
	static void UpdateView(FR_Page page, FR_PageView view, FS_FloatRectArray rectarray);

	//************************************
	// Function:  UpdateAllViews2
	// Param[in]: page			The input page object.
	// Param[in]: view          The input page view object.
	// Param[in]: frAnnot		The input annotation you want to update.
	// Return: void.
	// Remarks: Updates all the pages where the annotation is shown.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	// See:
	// Deprecated: Internal use.
	//************************************
	static void UpdateAllViews2(FR_Page page, FR_PageView view, FR_Annot frAnnot);

	//************************************
	// Function:  LockPage
	// Param[in]: page			The input page object.
	// Return: void
	// Remarks: lock page
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void		LockPage(FR_Page page);

	//************************************
	// Function:  UnLockPage
	// Param[in]: page			The input page object.
	// Return:
	// Remarks: unlock page
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void		UnLockPage(FR_Page page);

	//************************************
	// Function:  IsLocked
	// Param[in]: page			The input page object.
	// Return: TRUE if the view is locked.
	// Remarks: Get whether the page is locked or not
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL		IsLocked(FR_Page page);

	//************************************
	// Function:  IsParsed
	// Param[in]: page			The input page object.
	// Return: TRUE if the view is parsed.
	// Remarks: Get whether the page is parsed or not
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL		IsParsed(FR_Page page);

    //************************************
    // Function:  GetPageTabOrder
    // Param[in]: page			The input page object.
    // Param[in]: frAnnot       The input annotation you want to get the tab order.
    // Return: the tab order of annotation.
    // Remarks: Get the tab order of annotation.
    // Notes:
	// Deprecated: Internal use.
    //************************************
    static FS_INT32		GetPageTabOrder(FR_Page page, FR_Annot frAnnot);

    //************************************
    // Function:  GetPageTabOrder
    // Param[in]: page			The input page object.
    // Param[in]: frAnnot       The input annotation you want to set the tab order.
    // Param[in]: iOrder        The tab order you want to set.
    // Return: the tab order of annotation.
    // Remarks: Set the tab order of annotation.
    // Notes:
	// Deprecated: Internal use.
    //************************************
    static FS_INT32		SetPageTabOrder(FR_Page page, FR_Annot frAnnot, FS_INT32 iOrder);

    //************************************
    // Function:  GetPageTabOrder
    // Param[in]: page			The input page object.
    // Param[in]: frAnnot       The input annotation you want to insert the tab order.
    // Param[in]: iOrder        The tab order you want to insert.
    // Return:
    // Remarks: Insert the tab order of annotation.
    // Notes:
	// Deprecated: Internal use.
    //************************************
    static void		InsertWidgetTabOrder(FR_Page page, FR_Annot frAnnot, FS_INT32 iOrder);

    //************************************
    // Function:  SetContentModification
    // Param[in]: page				The page whose <a>FR_Page</a> content is modified.
    // Param[in]: modifiedContent	An array to store the modified <a>FPD_Page</a>.
    // Return:	void.
    // Remarks: Sets the modified page content.
    // Notes:
    // Since:
	// Deprecated: Internal use.
    //************************************
    static void SetContentModification(FR_Page page, FS_PtrArray modifiedContent);

	//************************************
	// Function:  IsParsed
	// Param[in]: page			The input page object.
	// Return:
	// Remarks: Generate content of the page
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void GenerateContent(FR_Page page);

	//************************************
	// Function:  GetXFAPage
	// Param[in]: page			The input page object.
	// Return: FPD_XFAPageView
	// Remarks: 
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FPD_XFAPageView	GetXFAPage(FR_Page page);

	//************************************
	// Function:  GetAnnotByXFAWidget
	// Param[in]: page			The input page object.
	// Param[in]: hWidget		The XFA_HWIDGET object.
	// Return: FR_Annot
	// Remarks: return widget annot object.  If the type of opened document is Static XFA document, this function will return NULL.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FR_Annot		GetAnnotByXFAWidget(FR_Page page, PFPDXFA_HWIDGET hWidget);

	//************************************
	// Function:  RefreshXFAPageView.
	// Param[in]: page			The input page object.
	// Param[in]: doc		    The current doc object.
	// Param[in]: rect		    The rect of to invalidate.
	// Param[in]: dwFlag		The data flags. Such as FPDXFA_INVALIDATE_AllPages or FPDXFA_INVALIDATE_CurrentPage
	// Return: void
	// Remarks: Refresh display of XFA page.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void          RefreshXFAPageView(FR_Page page, FR_Document doc, FS_FloatRect rect, FS_DWORD dwFlag);

	//************************************
	// Function:  SetMergeTextFlag.
	// Param[in]: page			The input page object.
	// Param[in]: bMergeText	Set merge text flag, if true, it will not merge text when save the doc.
	// Return: void
	// Remarks: Set split text flag, if true, it will not merge text when save the doc.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void          SetMergeTextFlag(FR_Page page, FS_BOOLEAN bMergeText);

	//************************************
	// Function:  ClearContentModification.
	// Param[in]: page			The input page object.
	// Param[in]: objects	    The specified FPD_GraphicsObjects objects need to remove.
	// Return: void
	// Remarks: Clear content modification in frame.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void          ClearContentModification(FR_Page page, FS_PtrArray objects);

	//************************************
	// Function:  ResetPageAnnots.
	// Param[in]: page			The input page object.
	// Return: FS_BOOLEAN       true: reset page annots success.
	// Remarks: Reset page annots.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	ResetPageAnnots(FR_Page page);
};

class CFR_BaseAnnotFillerHandler : public IBA_AnnotFiller
{
public:
    CFR_BaseAnnotFillerHandler(FRD_BAAnnotFillerCallbacksRec*  callback);

	virtual CRect				GetViewBBox(IReader_PageView *pPageView, IReader_Annot* pAnnot);
	virtual void				OnDraw(IReader_PageView *pPageView, HDC hDC, IReader_Annot* pAnnot,
		CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device,
		const CRect& rcWindow, DWORD dwFlags);
	virtual void				Annot_OnVisible(IReader_PageView *pPageView, IReader_Annot* pAnnot);
	virtual void				OnCreate(IReader_Annot* pAnnot);
	virtual void				OnLoad(IReader_Annot* pAnnot);
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
	virtual	void				OnDeSelected(IReader_Annot* pAnnot);
	virtual	void				OnSelected(IReader_Annot* pAnnot);

	virtual FX_BOOL				OnSetFocus(IReader_Annot* pAnnot);
	virtual FX_BOOL				OnKillFocus(IReader_Annot* pAnnot);
	virtual FX_BOOL				OnReturn(IReader_PageView *pPageView, IReader_Annot* pAnnot);
	virtual FX_BOOL				OnESC(IReader_Annot* pAnnot);
	virtual FX_BOOL				IsFilling(IReader_Annot *pAnnot);
	virtual void				OnTabd(IReader_Annot *pAnnot);

    FRD_BAAnnotFillerCallbacksRec m_callback;
};

class CFR_IBAAnnotFiller_V14 //Internal use
{
public:
    static FR_BAAnnotFiller New(FRD_BAAnnotFillerCallbacks callbacks);
    static void Destroy(FR_BAAnnotFiller handler);
};

class CFR_BaseAnnotDesignerHandler : public IBA_AnnotDesigner
{
public:
    CFR_BaseAnnotDesignerHandler(FRD_BAAnnotDesignerCallbacksRec*  callback);

	virtual CRect				GetViewBBox(IReader_PageView *pPageView, IReader_Annot* pAnnot);
	virtual void				OnDraw(IReader_PageView *pPageView, HDC hDC, IReader_Annot* pAnnot,
		CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device,
		const CRect& rcWindow, DWORD dwFlags);
	virtual void				Annot_OnVisible(IReader_PageView *pPageView, IReader_Annot* pAnnot);
	virtual void				OnCreate(IReader_Annot* pAnnot);
	virtual void				OnLoad(IReader_Annot* pAnnot);
	virtual void				OnDelete(IReader_Annot* pAnnot);
	virtual void				OnRelease(IReader_Annot* pAnnot);
	virtual void				DeleteAnnot(IReader_Annot* pAnnot);
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
	virtual	void				OnDeSelected(IReader_Annot* pAnnot);
	virtual	void				OnSelected(IReader_Annot* pAnnot);
	virtual FX_BOOL				OnSetFocus(IReader_Annot* pAnnot);
	virtual FX_BOOL				OnKillFocus(IReader_Annot* pAnnot);
    virtual FX_BOOL				CanReSize() const;
    virtual FX_BOOL				CanMove() const;
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
		const CRect& rcOrigin, const CRect& rcNew, int nIndex);
	virtual void				CancelMoving(IReader_PageView *pPageView, IReader_Annot* pAnnot,
		const CRect& rcOrigin, const CRect& rcNew);
	virtual void				OnSetPosition(IReader_PageView* pPageView, IReader_Annot* pAnnot,
        const CPDF_Rect& rect, int nSrcType);
    virtual FX_BOOL				IsMenuItemSupported(int nMenuItem);
	virtual std::pair<HMENU, int>			OnPopupMenu();
	virtual void				OnPopupMenuItem(IReader_PageView* pPageView, int nMenuItemID);
	virtual FX_BOOL				CanAnswer(IReader_Annot* pAnnot) const;
	virtual FX_BOOL				CanCopy(const CFX_ByteString& sSubType);
	virtual FX_BOOL				CanCut(const CFX_ByteString& sSubType);
	virtual FX_BOOL				CanPaste(const CFX_ByteString& sSubType);
	virtual std::unique_ptr<CXML_Element>		OnCopy(IReader_Annot* pAnnot);
	virtual IReader_Annot*		OnPaste(CXML_Element* pElement, IReader_Page* pPage, const CPDF_Rect& rcAnnot);
	virtual FX_BOOL				CanDelete(IReader_Annot* pAnnot) const;
	virtual FX_BOOL				IsPermissionAllowed(IReader_Document* pDocument, const CFX_ByteString& sSubType);
	virtual CFX_WideString		GetPropertyBoxTitle(const CFX_ByteString& sSubType);
	virtual FX_BOOL				OnReturn(IReader_PageView *pPageView, IReader_Annot* pAnnot);
	virtual FX_BOOL				OnESC(IReader_Annot* pAnnot);
	virtual void				OnTabd(IReader_Annot *pAnnot);
	virtual FX_BOOL				IsVisible(IReader_Annot* pAnnot);


    FRD_BAAnnotDesignerCallbacksRec m_callback;
};

class CFR_IBAAnnotDesigner_V14 //Internal use
{
public:
    static FR_BAAnnotDesigner New(FRD_BAAnnotDesignerCallbacks callbacks);
    static void Destroy(FR_BAAnnotDesigner handler);
};

class CFR_CBFInterForm_V14 //Internal use
{
public:
    static FR_Document GetDocument(FR_CBFInterForm form);
	static FR_CBF_Widget GetWidget(FR_CBFInterForm form, FPD_FormControl control, FS_BOOL bAddToPage);
    static void RemoveMap(FR_CBFInterForm form, FPD_FormControl control);
	static FR_ReaderInterform GetReaderInterForm(FR_CBFInterForm form);
};

class CFR_BFFormNotifyHandler : public IBF_FormNotify
{
public:
    CFR_BFFormNotifyHandler(FRD_BFFormNotifyCallbacksRec*  callback);

    virtual void					BeforeFormReset(CBF_InterForm* pInterForm);
    virtual void					AfterFormReset(CBF_InterForm* pInterForm);
    virtual int						BeforeValueChange(const CPDF_FormField* pField, CFX_WideString& csValue);

    FRD_BFFormNotifyCallbacksRec m_callback;
};

class CFR_BFFormNotify_V14 //Internal use
{
public:
    static FR_IBFFormNotify New(FRD_BFFormNotifyCallbacks callbacks);
    static void Destroy(FR_IBFFormNotify handler);
};

class CFR_BAAnnotHandler : public IBA_AnnotHandler
{
public:
	CFR_BAAnnotHandler(FRD_BAAnnotHandlerCallbacksRec*  callback);
	~CFR_BAAnnotHandler();

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
	virtual bool				ReleasePopupMenu(HMENU pMenu);
	IAccessible*                SetAccessible(IReader_Annot* pAnnot, IReader_PageView *pPageView, IAccessible *pAccessble);
	IAccessible*                FindAccessible(IReader_Annot* pAnnot, IReader_PageView *pPageView);

protected:
	std::map<IReader_Annot*, std::map<IReader_PageView*, IAccessible*>> m_Accessible;
    FRD_BAAnnotHandlerCallbacksRec m_callback;
};

class CFR_BFAnnotHandler_V14 //Internal use
{
public:
    static FR_BAAnnotHandler New(FRD_BAAnnotHandlerCallbacks callbacks);
    static void Destroy(FR_BAAnnotHandler handler);
};

class CFR_BaseForm_V14 //Internal use
{
public:
    //************************************
    // Function:  GetBaseForm
    // Return: FR_BaseForm
    // Remarks: Get IBaseForm object.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FR_BaseForm GetBaseForm();

    //************************************
    // Function:  BeginTabOrderDesign
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pPageView		The input pageview object.
    // Return: void
    // Remarks: Begin tab order of the pageview.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void		   BeginTabOrderDesign(FR_BaseForm form, FR_PageView pPageView);

    //************************************
    // Function:  EndTabOrderDesign
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pPageView		The input pageview object.
    // Return: void
    // Remarks: End tab order of the pageview.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void		   EndTabOrderDesign(FR_BaseForm form, FR_PageView pPageView);

    //************************************
    // Function:  ShowTabOrder
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: bShow		    Set true will show tab order.
    // Return: void
    // Remarks: Set if show tab order.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void		   ShowTabOrder(FR_BaseForm form, FS_BOOL bShow);

    //************************************
    // Function:  SetFormFiller
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pFiller		The input annot filler handler.
    // Return: void
    // Remarks: Set annot handler.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void		   SetFormFiller(FR_BaseForm form, FR_BAAnnotFiller pFiller);

    //************************************
    // Function:  SetSignatureFiller
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pFiller		The input signature type filler handler.
    // Return: void
    // Remarks: Set annot handler.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void		   SetSignatureFiller(FR_BaseForm form, FR_BAAnnotFiller pFiller);

    //************************************
    // Function:  GetFillerByAnnot
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pAnnot		The input annot type.
    // Return: FR_BAAnnotFiller
    // Remarks: Get filler handler by annot.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FR_BAAnnotFiller		GetFillerByAnnot(FR_BaseForm form, FR_Annot pAnnot);

    //************************************
    // Function:  SetFormDesigner
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pDesigner		The input annot designer handler.
    // Return: void
    // Remarks: Set form design handler.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void			SetFormDesigner(FR_BaseForm form, FR_BAAnnotDesigner pDesigner);

    //************************************
    // Function:  SetSignatureHandler
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pHandler		The input annot handler.
    // Return: void
    // Remarks: Set signature handler.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void			SetSignatureHandler(FR_BaseForm form, FR_BAAnnotHandler pHandler);

    //************************************
    // Function:  SetXFASignatureHandler
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pHandler		The input annot handler.
    // Return: void
    // Remarks: Set XFA signature handler.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void			SetXFASignatureHandler(FR_BaseForm form, FR_BAAnnotHandler pHandler);

    //************************************
    // Function:  GetXFASignatureHandler
    // Param[in]: form		    The input FR_BaseForm.
    // Return: FR_BAAnnotHandler
    // Remarks: Get XFA signature handler.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FR_BAAnnotHandler	GetXFASignatureHandler(FR_BaseForm form);

    //************************************
    // Function:  IsHighLight
    // Param[in]: form		    The input FR_BaseForm.
    // Return: FS_BOOL
    // Remarks: Check the baseform is highlight.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FS_BOOL		IsHighLight(FR_BaseForm form);

    //************************************
    // Function:  SetHighLight
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: bHighLight	Sets true this baseform is highlight.
    // Return: void
    // Remarks: Sets whether the Form is highlight.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void			SetHighLight(FR_BaseForm form, FS_BOOL bHighLight);

    //************************************
    // Function:  SetHighLightColor
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: color     	Sets highlight color of the baseform.
    // Return: void
    // Remarks: Sets highlight color of the baseform.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void			SetHighLightColor(FR_BaseForm form, FS_COLORREF color);

    //************************************
    // Function:  GetHighLightColor
    // Param[in]: form		    The input FR_BaseForm.
    // Return: FS_COLORREF
    // Remarks: Get highlight color of the baseform.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FS_COLORREF		GetHighLightColor(FR_BaseForm form);

    //************************************
    // Function:  GetRequiredColor
    // Param[in]: form		    The input FR_BaseForm.
    // Return: FS_COLORREF
    // Remarks: Get required highlight color of the baseform.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FS_COLORREF		GetRequiredColor(FR_BaseForm form);

    //************************************
    // Function:  IsFormDesignerAssistEnabled
    // Param[in]: form		    The input FR_BaseForm.
    // Return: FS_BOOL
    // Remarks: Get form designer assist is enable.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FS_BOOL			IsFormDesignerAssistEnabled(FR_BaseForm form);

    //************************************
    // Function:  SetFormDesignerAssistEnabled
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: bEnable		Set true form designer assist will enable.
    // Return: FS_BOOL
    // Remarks: Set form designer assist is enable.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void             SetFormDesignerAssistEnabled(FR_BaseForm form, FS_BOOL bEnable);

    //************************************
    // Function:  GetAutoCompleteChoice
    // Param[in]: form		    The input FR_BaseForm.
    // Return: FS_INT32     FR_AUTOCOMPLETECHOICE type.
    // Remarks: Get the choice of auto complete, like FRAUTOCOMPLETEOFF.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FS_INT32			GetAutoCompleteChoice(FR_BaseForm form);

    //************************************
    // Function:  IsOpenPropertyAfterCreate
    // Param[in]: form		    The input FR_BaseForm.
    // Return: FS_BOOL
    // Remarks: Check if open property when after create.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FS_BOOL			IsOpenPropertyAfterCreate(FR_BaseForm form);

    //************************************
    // Function:  ShowFocusRect
    // Param[in]: form		    The input FR_BaseForm.
    // Return: FS_BOOL
    // Remarks: Check if show focus rect of the preferences dialog .
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FS_BOOL			ShowFocusRect(FR_BaseForm form);

    //************************************
    // Function:  ShowOverflowIndicator
    // Param[in]: form		    The input FR_BaseForm.
    // Return: FS_BOOL
    // Remarks: Check if show over flow indicator of the preferences dialog .
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FS_BOOL			ShowOverflowIndicator(FR_BaseForm form);

    //************************************
    // Function:  IsNumericalDataEnable
    // Param[in]: form		    The input FR_BaseForm.
    // Return: FS_BOOL
    // Remarks: Get if check the rember numeric data of the preferences dialog .
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FS_BOOL			IsNumericalDataEnable(FR_BaseForm form);

    //************************************
    // Function:  SetFormNotify
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pNotify		The input form notify handler.
    // Return: void
    // Remarks: Set form notify, when form changed that will get the notify.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void				SetFormNotify(FR_BaseForm form, FR_IBFFormNotify pNotify);

    //************************************
    // Function:  CollectAPStreamRefCount
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pDoc		    The input FPD_Document.
    // Return: void
    // Remarks: Collect AP stream.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void				CollectAPStreamRefCount(FR_BaseForm form, FPD_Document pDoc);

    //************************************
    // Function:  ClearAPStreamRefCount
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pDoc		    The input FPD_Document.
    // Return: void
    // Remarks: Clear AP stream.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void				ClearAPStreamRefCount(FR_BaseForm form, FPD_Document pDoc);

    //************************************
    // Function:  GetAPStreamRefCount
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pDoc		    The input FPD_Document.
    // Param[in]: dwStreamObjNum	The input stream obj num.
    // Param[out]: dwCount		    Get the stream ref count.
    // Return: void
    // Remarks: Get AP stream ref count of the document.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FS_BOOL			GetAPStreamRefCount(FR_BaseForm form, FPD_Document pDoc, FS_DWORD dwStreamObjNum, FS_DWORD* dwCount);

    //************************************
    // Function:  Show
    // Param[in]: form		    The input FR_BaseForm.
    // Param[in]: pPageView		The input pageviewer object.
    // Param[in]: pSigAnnot	    The input widget object.
    // Return: void
    // Remarks: Show widget annot of the pageviewer.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void             Show(FR_BaseForm form, FR_PageView pPageView, FR_CBF_Widget pSigAnnot);

	//************************************
	// Function:  SetWidgetMsgHook
	// Param[in]: form		    The input FR_BaseForm.
	// Param[in]: pPageView		The input pageviewer object.
	// Param[in]: pSigAnnot	    The input widget object.
	// Return: void
	// Remarks: Show widget annot of the pageviewer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void  SetWidgetMsgHook(FR_BaseForm form, FR_WidgetAnnotHandler pHook);

	//************************************
	// Function:  GetWidgetMsgHook
	// Param[in]: form		    The input FR_BaseForm.
	// Param[in]: pPageView		The input pageviewer object.
	// Param[in]: pSigAnnot	    The input widget object.
	// Return: void
	// Remarks: Show widget annot of the pageviewer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FR_WidgetAnnotHandler  GetWidgetMsgHook(FR_BaseForm form);
};

class CFR_IFormDesignerNotifyHandler : public IFormDesignerNotify
{
public:
    CFR_IFormDesignerNotifyHandler(FRD_FormDesignNotifyCallbacksRec*  callback);
	
	virtual void	OnTabOrderChanged(IReader_Page* pPage);
	virtual void	OnWidgetChanged(IReader_Annot* pAnnot);
	virtual void	OnSetAsDefaultSetting(IReader_PageView* pPageView);
	virtual void	OnMltiplyCopies(IReader_PageView* pPageView);
	virtual void	OnAddWidgetFinish(IReader_Annot* pAnnot);

    FRD_FormDesignNotifyCallbacksRec m_callback;
};

class CFR_IFormDesignerNotify_V14
{
public:
	//************************************
	// Function:  New
	// Param[in]: callbacks   	The FRD_FormDesignNotifyCallbacks callback.		
	// Return: FR_IFormDesignerNotify
	// Remarks: Create FR_IFormDesignerNotify object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRDocSetNotify
	// See: FRIFormDesignerNotifyNew
	//************************************
	static FR_IFormDesignerNotify New(FRD_FormDesignNotifyCallbacks callbacks);

	//************************************
	// Function:  Destroy
	// Param[in]: handler   	The FR_IFormDesignerNotify object.		
	// Return: void
	// Remarks: Release FR_IFormDesignerNotify object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRIFormDesignerNotifyDestroy
	//************************************
    static void Destroy(FR_IFormDesignerNotify handler);
};

class CFR_CBFWidget_V14
{
public:
	//************************************
	// Function:  ResetAppearance
	// Param[in]: widget			The input widget object. Get it from FRAnnotGetCBFWidget,
	// it can create by FRPageViewAddAnnot,or get FR_Annot by FRPageViewGetAnnotByIndex.
	// Param[in]: bValueChanged		Whether change value.	
	// Return: void 	
	// Remarks: Reset widget appearance.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRPageViewAddAnnot
	// See: FRPageAddAnnot2
	// See: FRAnnotGetCBFWidget
	//************************************
    static void				ResetAppearance(FR_CBF_Widget widget, FS_BOOL bValueChanged);

	//************************************
	// Function:  IsAppearanceValid
	// Param[in]: widget			The input widget object.	
	// Return: FS_BOOL 	
	// Remarks: Check the "AP" dictionary is valid.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
    static FS_BOOL			IsAppearanceValid(FR_CBF_Widget widget);

	//************************************
	// Function:  GetFieldType
	// Param[in]: widget			The input widget object.	
	// Return: void 	
	// Remarks: Get formfield type, like FPD_FORM_FIELDTYPE_UNKNOWN.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
    static FS_INT32			GetFieldType(FR_CBF_Widget widget);

	//************************************
	// Function:  GetFieldFlags
	// Param[in]: widget			The input widget object.	
	// Return: FS_INT32 	
	// Remarks: "Ff" entry in field dictionary. Get the field flags. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
    static FS_INT32			GetFieldFlags(FR_CBF_Widget widget);

	//************************************
	// Function:  GetRotate
	// Param[in]: widget			The input widget object.	
	// Return: FS_INT32 	
	// Remarks: Get the rotate of widget. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
    static FS_INT32			GetRotate(FR_CBF_Widget widget);

	//************************************
	// Function:  GetTextColor
	// Param[in]: widget			The input widget object.	
	// Param[out]: color			The color of the widget.	
	// Return: FS_BOOL 	
	// Remarks: Get color of the widget. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
    static FS_BOOL			GetTextColor(FR_CBF_Widget widget, FS_COLORREF* color);

	//************************************
	// Function:  GetFont
	// Param[in]: widget			The input widget object.	
	// Param[out]: bsFont			The font of the widget.	
	// Return: void 	
	// Remarks: Get font of the widget. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
    static void	            GetFont(FR_CBF_Widget widget, FS_ByteString* bsFont);

	//************************************
	// Function:  GetBaseFont
	// Param[in]: widget			The input widget object.	
	// Param[out]: bsBaseFont		The base font name.	
	// Return: void 	
	// Remarks: Get the base font name of the widget font. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
    static void	            GetBaseFont(FR_CBF_Widget widget, FS_ByteString* bsBaseFont);

	//************************************
	// Function:  IsReadOnly
	// Param[in]: widget			The input widget object.	
	// Return: FS_BOOL 	
	// Remarks: Check the FieldFlags is FIELDFLAG_READONLY. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
    static FS_BOOL			IsReadOnly(FR_CBF_Widget widget);

	//************************************
	// Function:  IsVisible
	// Param[in]: widget			The input widget object.	
	// Return: FS_BOOL 	
	// Remarks: Check the widget is visible. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
    static FS_BOOL			IsVisible(FR_CBF_Widget widget);

	//************************************
	// Function:  SetRect
	// Param[in]: widget			The input widget object.	
	// Param[in]: rect			    Set the rect of the widget.	
	// Return: void 	
	// Remarks: Set the rect of the widget. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
    static void				SetRect(FR_CBF_Widget widget, const FS_FloatRect rect);

	//************************************
	// Function:  GetRect
	// Param[in]: widget			The input widget object.		
	// Return: FS_FloatRect 	
	// Remarks: Get the rect of the widget. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
    static FS_FloatRect		GetRect(FR_CBF_Widget widget);

	//************************************
	// Function:  ClearCachedAP
	// Param[in]: widget			The input widget object.		
	// Return: void 	
	// Remarks:  Clear all cached appearance, when the application changed any appearance settings. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
    static void				ClearCachedAP(FR_CBF_Widget widget);

	//************************************
	// Function:  DrawAppearance
	// Param[in]: widget			The input widget object.	
	// Param[in]: pDevice			The render device.
	// Param[in]: pUser2Device		The matrix of the userdevice.
	// Param[in]: mode			    The Appearance mode enumeration of annotation.
	// Param[in]: pOptions			The render options.
	// Return: FS_BOOL 	
	// Remarks:  Draw annot. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
    static FS_BOOL			DrawAppearance(FR_CBF_Widget widget, FPD_RenderDevice pDevice, const FS_AffineMatrix pUser2Device,
        FPD_AnnotAppearanceMode mode, const FPD_RenderOptions pOptions);

	//************************************
	// Function:  ResetAppearance2
	// Param[in]: widget			The input widget object.	
	// Param[in]: sValue			Reset the value of filed control.
	// Param[in]: bValueChanged		If the value changed.
	// Param[in]: bResetRV			If need to reset "RV" dictionary.	
	// Return: void 	
	// Remarks:  Reset form filed control appearance, and  Clear all cached appearance. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
    static void				ResetAppearance2(FR_CBF_Widget widget, FS_LPCWSTR sValue, FS_BOOL bValueChanged, FS_BOOL bResetRV);
	
	//************************************
	// Function:  HideHint
	// Param[in]: widget			The input widget object.
	// Return: void 	
	// Remarks:  Hide hint of the widget. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
    static void				HideHint(FR_CBF_Widget widget);

	//************************************
	// Function:  ShowHint
	// Param[in]: widget			The input widget object.
	// Param[in]: hParent			The HWND of the hint window.
	// Param[in]: point			    The position of the hint windows.
	// Param[in]: sTooltip			The msg of hint.
	// Return: void 	
	// Remarks: Show hint of the widget. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
    static void				ShowHint(FR_CBF_Widget widget, FS_LPVOID hParent, const FS_FloatPoint point, const FS_WideString sTooltip);
	
	//************************************
	// Function:  GetFormControl
	// Param[in]: widget			The input widget object.
	// Return: FPD_FormControl 	
	// Remarks: Get the form control of CPDF_FormControl. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
    static FPD_FormControl  GetFormControl(FR_CBF_Widget widget);

	//************************************
	// Function:  OnFormat
	// Param[in]: widget			The input widget object.
	// Param[in]: nCommitKey		The key of the commit.
	// Param[out]: bFormated		Get the reslut if be formated.
	// Param[out]: out			    The reslut with run JS filed format.
	// Return: FS_INT32 	
	// Remarks: Run field format of the widget. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
    static FS_INT32 	    OnFormat(FR_CBF_Widget widget, FS_INT32 nCommitKey, FS_BOOL* bFormated, FS_WideString* out);
	
	//************************************
	// Function:  GetInterForm
	// Param[in]: widget			The input widget object.
	// Return: FR_CBFInterForm 	
	// Remarks: Get the CBF_InterForm of the widget. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
    static FR_CBFInterForm	GetInterForm(FR_CBF_Widget widget);

	//************************************
	// Function:  GetAnnotDict
	// Param[in]: widget			The input widget object.
	// Return: FPD_Object 	
	// Remarks: Get the annot dictionary. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
    static FPD_Object		GetAnnotDict(FR_CBF_Widget widget);

	//************************************
	// Function:  GetName
	// Param[in]: widget			The input widget object.
	// Param[out]: name		    	The full name of the field.
	// Return: FPD_Object 	
	// Remarks: Get the full name of the field. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
    static void         	GetName(FR_CBF_Widget widget, FS_WideString* name);

	//************************************
	// Function:  SetRotate
	// Param[in]: widget			The input widget object.
	// Param[int]: nRotate		    Set the rotate of the widget.
	// Return: FPD_Object 	
	// Remarks: Set the rotate of the widget. It support degrees of 0,90,180,270, 
	// and support all fieldtype except FPD_FORM_FIELDTYPE_PUSHBUTTON and FPD_FORM_FIELDTYPE_RADIOBUTTON.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void				SetRotate(FR_CBF_Widget widget, FS_INT32 nRotate);

	//************************************
	// Function:  GetIReaderAnnot
	// Param[in]: widget			The input widget object.	
	// Return: FR_Annot 	
	// Remarks: Get IReader_Annot of the widget.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_Annot         GetIReaderAnnot(FR_CBF_Widget widget);

	//************************************
	// Function:  SetName
	// Param[in]: widget			The input widget object.	
	// Param[in]: sName			    The input new field name.
	// Return: void 	
	// Remarks: Rename a field's full name. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void				SetName(FR_CBF_Widget widget, const FS_WideString sName);	

	//************************************
	// Function:  HasAAction
	// Param[in]: widget			The input widget object.	
	// Param[in]: eAAT			    The input AActionType.
	// Return: FS_BOOLEAN 	
	// Remarks: Get an action from the additional-action with specified additional-action type. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOLEAN		HasAAction(FR_CBF_Widget widget, FPD_AActionType eAAT);

	//************************************
	// Function:  OnAAction
	// Param[in]: widget			The input widget object.	
	// Param[in]: type			    The input AActionType.
	// Param[out]: data			    The out filed action data.	
	// Param[in]: pPageView			The input FR_PageView object.
	// Return: FS_BOOLEAN 	
	// Remarks: Do action_Field. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN		OnAAction(FR_CBF_Widget widget, FPD_AActionType type, FR_BAFieldAction* data,FR_PageView pPageView);

	//************************************
	// Function:  DrawShadow
	// Param[in]: widget			The input widget object.	
	// Param[in]: pDevice			The input RenderDevice object.
	// Param[in]: winPort			The input HWND.	
	// Param[in]: pPageView			The input FR_PageView object.
	// Return: void 	
	// Remarks: Draw shadow of the widget. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void				DrawShadow(FR_CBF_Widget widget, FPD_RenderDevice pDevice, FR_WinPort winPort, FR_PageView pPageView);

	//************************************
	// Function:  GetMixXFAWidget
	// Param[in]: widget			The input widget object.	
	// Return: PFPDXFA_HWIDGET 	
	// Remarks: Get XFA widget handler.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static PFPDXFA_HWIDGET	GetMixXFAWidget(FR_CBF_Widget widget);

	//************************************
	// Function:  DrawCustomShadow
	// Param[in]: widget			The input widget object.	
	// Param[in]: pDevice			The input RenderDevice object.
	// Param[in]: color			    The input color.
	// Param[in]: hDC			    The input DC object.
	// Param[in]: pPageView			The input FR_PageView.
	// Return: void 	
	// Remarks: Draw custom shadow.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void	DrawCustomShadow(FR_CBF_Widget widget, FPD_RenderDevice pDevice, FS_COLORREF color, FS_HDC hDC, FR_PageView pPageView);
};

class CFR_IBFSimpleFromProperties_V14 //Internal use
{
public:
    static FS_BOOL				IsVisible(FR_BFSimpleFromProperties properties);
    static void					Show(FR_BFSimpleFromProperties properties, FR_PageView pPageView, FR_CBF_Widget pWidget); //Only show one properties box at on time.
    static void					Hide(FR_BFSimpleFromProperties properties);
};

class CFR_SGRDN_V14  //Internal use
{
public:
    static FRSG_RDN Create();
    static void Destroy(FRSG_RDN rdn);
    static void SetcwC(FRSG_RDN rdn, FS_WideString value);
    static void GetcwC(FRSG_RDN rdn, FS_WideString* outvalue);
    static void SetcwCN(FRSG_RDN rdn, FS_WideString value);
    static void GetcwCN(FRSG_RDN rdn, FS_WideString* outvalue);
    static void SetcwE(FRSG_RDN rdn, FS_WideString value);
    static void GetcwE(FRSG_RDN rdn, FS_WideString* outvalue);
    static void SetcwL(FRSG_RDN rdn, FS_WideString value);
    static void GetcwL(FRSG_RDN rdn, FS_WideString* outvalue);
    static void SetcwO(FRSG_RDN rdn, FS_WideString value);
    static void GetcwO(FRSG_RDN rdn, FS_WideString* outvalue);
    static void SetcwOU(FRSG_RDN rdn, FS_WideString value);
    static void GetcwOU(FRSG_RDN rdn, FS_WideString* outvalue);
    static void SetcwST(FRSG_RDN rdn, FS_WideString value);
    static void GetcwST(FRSG_RDN rdn, FS_WideString* outvalue);
};

class CFR_SGCERTIFICATE_INFO_V14 //Internal use
{
public:
    static FRSG_CERTIFICATE_INFO Create();
    static void Destroy(FRSG_CERTIFICATE_INFO info);
    static void SetFlags(FRSG_CERTIFICATE_INFO info, FS_INT32 nFlags);
    static FS_INT32 GetFlags(FRSG_CERTIFICATE_INFO info);
    static void SetIssuersArr(FRSG_CERTIFICATE_INFO info, FS_ByteStringArray issueArr);
    static void GetIssuersArr(FRSG_CERTIFICATE_INFO info, FS_ByteStringArray* outissueArr);
    static void SetKeyUsageArr(FRSG_CERTIFICATE_INFO info, FS_ByteStringArray keyUsageArr);
    static void GetKeyUsageArr(FRSG_CERTIFICATE_INFO info, FS_ByteStringArray* outkeyUsageArr);
    static void SetOidArr(FRSG_CERTIFICATE_INFO info, FS_ByteStringArray oidArr);
    static void GetOidArr(FRSG_CERTIFICATE_INFO info, FS_ByteStringArray* outoidArr);
    static void SetSubjectDNArr(FRSG_CERTIFICATE_INFO info, FRSG_RDN nFlags[], FS_INT32 size);
    static void GetSubjectDNArr(FRSG_CERTIFICATE_INFO info, FRSG_RDN outrdnArr[], FS_INT32* outSize);
    static void SetUrl(FRSG_CERTIFICATE_INFO info, FS_ByteString url);
    static void GetUrl(FRSG_CERTIFICATE_INFO info, FS_ByteString* outUrl);
    static void SetUrlType(FRSG_CERTIFICATE_INFO info, FS_ByteString urlType);
    static void GetUrlType(FRSG_CERTIFICATE_INFO info, FS_ByteString* outUrlType);
    static void SetSubjectArr(FRSG_CERTIFICATE_INFO info, FS_ByteStringArray subjectArr);
    static void GetSubjectArr(FRSG_CERTIFICATE_INFO info, FS_ByteStringArray* outsubjectArr);
};

class CFR_SGSEEDVALUE_INFO_V14 //Internal use
{
public:
    static FRSG_SEEDVALUE_INFO Create();
    static void Destroy(FRSG_SEEDVALUE_INFO info);
    static FRSG_CERTIFICATE_INFO GetCertInfo(FRSG_SEEDVALUE_INFO info);
    static void SetDigestMethodArr(FRSG_SEEDVALUE_INFO info, FS_ByteStringArray methodArr);
    static void GetDigestMethodArr(FRSG_SEEDVALUE_INFO info, FS_ByteStringArray* outmethodArr);
    static void SetFilter(FRSG_SEEDVALUE_INFO info, FS_WideString filter);
    static void GetFilter(FRSG_SEEDVALUE_INFO info, FS_WideString* outFilter);
    static void SetFlags(FRSG_SEEDVALUE_INFO info, FS_INT32 flags);
    static FS_INT32 GetFlags(FRSG_SEEDVALUE_INFO info);
    static void SetlegalAttestationsArr(FRSG_SEEDVALUE_INFO info, FS_WideStringArray legalArr);
    static void GetlegalAttestationsArr(FRSG_SEEDVALUE_INFO info, FS_WideStringArray* outlegalArr);
    static void Setmdp(FRSG_SEEDVALUE_INFO info, FS_ByteString mdp);
    static void Getmdp(FRSG_SEEDVALUE_INFO info, FS_ByteString* outMdp);
    static void SetReasonArr(FRSG_SEEDVALUE_INFO info, FS_WideStringArray reasonArr);
    static void GetReasonArr(FRSG_SEEDVALUE_INFO info, FS_WideStringArray* outreasonArr);
    static void SetbAddRevInfo(FRSG_SEEDVALUE_INFO info, FS_INT32 bRevInfo);
    static FS_INT32 GetbAddRevInfo(FRSG_SEEDVALUE_INFO info);
    static void SetSubFilterArr(FRSG_SEEDVALUE_INFO info, FS_WideStringArray subFilterArr);
    static void GetSubFilterArr(FRSG_SEEDVALUE_INFO info, FS_WideStringArray* outsubFilterArrArr);
    static void SetVersion(FRSG_SEEDVALUE_INFO info, FS_INT32 version);
    static FS_INT32 GetVersion(FRSG_SEEDVALUE_INFO info);
    static void SettimeStampspec(FRSG_SEEDVALUE_INFO info, FR_SignatureTimestampServer stampSpec);
    static FR_SignatureTimestampServer GettimeStampspec(FRSG_SEEDVALUE_INFO info);
};

class CFR_SGBaseHandler_V14 //Internal use
{
public:
	static void* New(FRD_SGBaseHandlerCallbacks callbacks);
	static void Destroy(void* handler);
};

class CFR_IClipBoard_V14//Internal use
{
public:
	static FR_ClipBoard     GetClipboard();
	static FS_BOOLEAN		RemoveElement(FR_ClipBoard clipboard, FS_XMLElement element);
	static FS_BOOLEAN       Initial(FR_ClipBoard clipboard, FS_BOOLEAN bSave);
	static void             Release(FR_ClipBoard clipboard);
	static FS_DWORD         GetElementCounts(FR_ClipBoard clipboard);
	static FS_XMLElement    GetElement(FR_ClipBoard clipboard, FS_DWORD dwIndex);
	static void             AddElement(FR_ClipBoard clipboard, FS_XMLElement pElement);
	static void             GetMD5(FR_ClipBoard clipboard, FS_ByteString* bsMD5);
	static void             GetType(FS_XMLElement pElement, FS_ByteString* outType);
	static void             GetSubtype(FS_XMLElement pElement, FS_ByteString* outType);
	static FS_FloatRect     GetRect(FS_XMLElement pElement);
	static FS_BOOL          ExportToXML(FR_Annot pAnnot, FR_CCBAnnotation pClipAnnot, FS_XMLElement pElement);
	static FS_BOOL          ImportFromXML(FS_XMLElement pElement, FR_CCBAnnotation pClipAnnot, FR_Annot pAnnot);
};

class CFR_CCBAnnotation_V14//Internal use
{
public:
    static void Delete(FR_CCBAnnotation annot);
    static FS_BOOLEAN  ParseToXML(FR_CCBAnnotation annot, FPD_Object pAnnotDict, FS_XMLElement pElement,FS_BOOLEAN bBaseFun);
    static FS_BOOLEAN  ParseToDict(FR_CCBAnnotation annot, FS_XMLElement pElement, FPD_Object pAnnotDict, FS_BOOLEAN bBaseFun);
    static FS_BOOLEAN  IsKeyNeeded_ToXML(FR_CCBAnnotation annot, FS_ByteString csKeyName, FS_INT32 nObjType, FS_BOOLEAN bBaseFun);
    static FS_BOOLEAN  IsKeyNeeded_ToDict(FR_CCBAnnotation annot, FS_ByteString csKeyName, FS_INT32 nObjType, FS_BOOLEAN bBaseFun);
    static void  AddNecessaryKeyToList_ToXML(FR_CCBAnnotation annot, FS_ByteString csKeyName, FS_BOOLEAN bBaseFun);
    static FR_CCBAnnotation New(FR_CCBAnnotationCallbacks callbacks,FPD_Document doc);
};

class CFR_ISpellCheck_V14//Internal use
{
public:
	
};


class CFR_CJavaScriptEditer_V14//Internal use
{
public:
	static FS_BOOLEAN IsUseExternalJSEditor();
	static FS_BOOLEAN EditWithGlobalWnd(FS_LPVOID pParent, FS_WideString* script);
	static FS_BOOLEAN EditWithExternalJSEditor(FS_WideString* script);
};

class CFR_IBAImageSource_V14//Internal use
{
public:
	//************************************
	// Function:  NewIBAImageSource
	// Param[in]: callbacks		The FR_IBAImageSourceHandlerCallbacks object.	
	// Return:  FR_IBAImageSource.
	// Remarks: Create FR_IBAImageSource that used to call the SetColorSource interface of FR_CBAFigureRecognition.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FR_IBAImageSource NewIBAImageSource(FR_IBAImageSourceHandlerCallbacks callbacks);

	//************************************
	// Function:  DestroyImageSource
	// Param[in]: source		The FR_IBAImageSource object.	
	// Return:  void.
	// Remarks: 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static void DestroyImageSource(FR_IBAImageSource source);
};

class CFR_CBAFigureRecognition_V14//Internal use
{
public:
	//************************************
	// Function:  NewCBAFigureRecognition	
	// Return:  FR_CBAFigureRecognition.
    // Remarks: Create FR_CBAFigureRecognition obj of the CBA_FigureRecognition, this used to form area identification.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FR_CBAFigureRecognition NewCBAFigureRecognition();

	//************************************
	// Function:  DestroyCBA_FigureRecognition	
	// Param[in]: recogntion		The FR_CBAFigureRecognition object.	
	// Return:  void.
	// Remarks: Destroy FR_CBAFigureRecognition obj.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static void  DestroyCBA_FigureRecognition(FR_CBAFigureRecognition recogntion);

	//************************************
	// Function:  SetColorSource	
	// Param[in]: recogntion		The FR_CBAFigureRecognition object.	
	// Param[in]: source		    The FR_IBAImageSource object.	
	// Return:  void.
    // Remarks: Set the ImageSource to FR_CBAFigureRecognition, if the imagesource is invalid, FRCBAFigureRecognitionFindRectBy4Point will be crash.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static void	 SetColorSource(FR_CBAFigureRecognition recogntion, FR_IBAImageSource source);

	//************************************
	// Function:  FindRectBy4Point	
	// Param[in]: recogntion		The FR_CBAFigureRecognition object.	
	// Param[in]: ptx		        The x of the point.
	// Param[in]: pty		        The y of the point.	
	// Param[out]: rect		        The rect contains the point.	
    // Return:  FS_BOOL.            <a>TRUE</a> find the rect successful, <a>FALSE</a>  find the rect fail.
    // Remarks:Find rect by point to create form area. It must be call FRCBAFigureRecognitionSetColorSource first.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FS_BOOL	FindRectBy4Point(FR_CBAFigureRecognition recogntion, FS_INT32 ptx, FS_INT32 pty, FS_Rect* rect);
};


class CFR_AnnotObserver_V14//Internal use
{
public:
	//************************************
	// Function:  CreateAnnotObserver	
	// Param[in]: annot		The FR_Annot object.			
	// Return:  FR_AnnotObserver.
	// Remarks: Encapsulat the IReader_Annot::Observer to listen the object in plugin.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FR_AnnotObserver CreateAnnotObserver(FR_Annot annot);

	//************************************
	// Function:  DestroyAnnotObserver	
	// Param[in]: observer		The FR_AnnotObserver object.			
	// Return:  void.
    // Remarks: Destroy FR_AnnotObserver object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static void DestroyAnnotObserver(FR_AnnotObserver observer);

	//************************************
	// Function:  IsValid	
	// Param[in]: observer		The FR_AnnotObserver object.			
	// Return:  FS_BOOLEAN.
	// Remarks: Check is the FR_Annot is valid.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FS_BOOLEAN IsValid(FR_AnnotObserver observer);

	//************************************
	// Function:  GetAnnotObj	
	// Param[in]: observer		The FR_AnnotObserver object.			
	// Return:  FR_Annot.
	// Remarks: Get the FR_Annot object of the observer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FR_Annot GetAnnotObj(FR_AnnotObserver observer);
};


class CFR_DocumentObserver_V14 //Internal use
{
public:
	//************************************
	// Function:  CreateDocumentObserver	
	// Param[in]: doc		The FR_Document object.			
	// Return:  FR_DocumentObserver.
    // Remarks: Encapsulat the CReader_Document::Observer to listen the object in plugin.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FR_DocumentObserver CreateDocumentObserver(FR_Document doc);

	//************************************
	// Function:  DestroyDocumentObserver	
	// Param[in]: observer		The FR_DocumentObserver object.			
	// Return:  void.
    // Remarks: Destroy FR_DocumentObserver object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static void DestroyDocumentObserver(FR_DocumentObserver observer);

	//************************************
	// Function:  IsValid	
	// Param[in]: observer		The FR_DocumentObserver object.			
	// Return:  FS_BOOLEAN.
	// Remarks: Check is the FR_Document is valid.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FS_BOOLEAN IsValid(FR_DocumentObserver observer);

	//************************************
	// Function:  GetDocumentObj	
	// Param[in]: observer		The FR_DocumentObserver object.			
	// Return:  FR_Document.
	// Remarks: Get the FR_Document object of the observer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FR_Document GetDocumentObj(FR_DocumentObserver observer);
};


class CFR_InnerContentProvider_V14//Internal use
{
public:
	//************************************
	// Function:  GetInnerContentProvider	
	// Param[in]: doc		The current document object.			
	// Return:  FR_InnerContentProvider.
	// Remarks: FR_InnerContentProvider is allow user to add the process of their own when parsing pdf Doucment.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FR_InnerContentProvider GetInnerContentProvider(FR_Document doc);

	//************************************
	// Function:  OnGetContentSize	
	// Param[in]: provider	The content provider.
	// Param[in]: pReaderDoc	The current document object.	
	// Param[out]: pTotalSize	Get the size of the content.
	// Return:  FS_BOOLEAN.
	// Remarks: 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static	FS_BOOLEAN	OnGetContentSize(FR_InnerContentProvider provider, FR_Document pReaderDoc, FS_LPDWORD pTotalSize);

	//************************************
	// Function:  OnReadContent	
	// Param[in]: provider	 The content provider.
	// Param[in]: pReaderDoc The current document object.	
	// Param[in]: dwPos	     Set the read position, default is 0.
	// Param[out]: pBuf		 Read the content buffer.	
	// Param[in]: size	     The value is get from OnGetContentSize.
	// Return:  FS_BOOLEAN.
	// Remarks: 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static	FS_BOOLEAN	OnReadContent(FR_InnerContentProvider provider, FR_Document pReaderDoc, FS_DWORD dwPos, FS_LPBYTE pBuf, FS_DWORD size);

	//************************************
	// Function:  onBackFillContent	
	// Param[in]: provider	 The content provider.
	// Param[in]: pReaderDoc The current document object.	
	// Param[in]: pBuf	     Fill Content buffer.
	// Param[in]: size		 Fill content size.	
	// Param[in]: lpSaveFilePath	 File path to save.
	// Return:  FS_BOOLEAN.
	// Remarks: 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static  FS_BOOLEAN	OnBackFillContent(FR_InnerContentProvider provider, FR_Document pReaderDoc, FS_LPBYTE pBuf, FS_DWORD size, FS_LPCWSTR lpSaveFilePath);

    //************************************
    // Function:  OnGetAppPermissions
    // Param[in]: provider	 The content provider.
    // Param[in]: pReaderDoc The current document object.
    // Param[in]: docappselfPermissions	    the permissions defined by application
    // Return:  FS_DWORD.
    // Remarks:
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static	FS_DWORD	OnGetAppPermissions(FR_InnerContentProvider provider, FR_Document pReaderDoc, FS_DWORD  docappselfPermissions);

	//************************************
	// Function:  OnGetAttachmentSize
	// Param[in]: provider	      The content provider.
	// Param[in]: pReaderDoc      The current document object.
	// Param[out]: pTotalSize     Get size of the attachment.
	// Param[in]: lpAttchmntPath  The attachment path.
	// Return:  FS_INT32
	// Remarks: Get the attachment size.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// See:
	//************************************
	static	FS_INT32	OnGetAttachmentSize(FR_InnerContentProvider provider, FR_Document pReaderDoc, FS_DWORD* pTotalSize, FS_LPCWSTR lpAttchmntPath);

	//************************************
	// Function:  OnReadAttachmentContent
	// Param[in]: provider	      The content provider.
	// Param[in]: pReaderDoc      The current document object.
	// Param[out]: pBuf           Get the buffer of attachment.
	// Param[in]: size            The attachment size.
	// Param[in]: lpAttchmntPath  The attachment path.
	// Return:  FS_INT32
	// Remarks: Get the attachment size.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// See:
	//************************************
	static	FS_INT32	OnReadAttachmentContent(FR_InnerContentProvider provider, FR_Document pReaderDoc, FS_LPBYTE pBuf, FS_DWORD size, FS_LPCWSTR lpAttchmntPath);
};

class CFR_IFXPDFAInterface_V14//Internal use
{
public:
	//************************************
	// Function:  GetIFXPDFAInterface		
	// Return:  FR_IFXPDFAInterface.
	// Remarks: Get IFXPDFAInterface object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FR_IFXPDFAInterface GetIFXPDFAInterface();

	//************************************
	// Function:  SimplePDFACheck	
	// Param[in]: pdfainterface	 The input IFXPDFAInterface	object.
	// Param[in]: pPDFDoc        The CPDF_Document object.	
	// Param[in]: peV	         The peV string.
	// Return:  FS_BOOL.   Return TRUE is PDFA document.
	// Remarks: Verify that it is a PDFA document
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FS_BOOL SimplePDFACheck(FR_IFXPDFAInterface pdfainterface, FPD_Document pPDFDoc, FS_ByteString peV);

	//************************************
	// Function:  PDFACheckIsClickEditing	
	// Param[in]: pdfainterface	 The input IFXPDFAInterface	object.
	// Param[in]: pRDDoc         The reader_document object.		
	// Return:  FS_BOOL.   Return TRUE is edited.
	// Remarks: Check the PDFA document has been editeded.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FS_BOOL PDFACheckIsClickEditing(FR_IFXPDFAInterface pdfainterface, FR_Document pRDDoc);

	//************************************
	// Function:  ShowPreflightWnd	
	// Param[in]: pdfainterface	 The input IFXPDFAInterface	object.
	// Param[in]: bShow          Set true is show preflight dialog.		
	// Return:  void.   
	// Remarks: Show preflight dialog.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static void ShowPreflightWnd(FR_IFXPDFAInterface pdfainterface, FS_BOOLEAN bShow);

	//************************************
	// Function:  GetPreflightWndShow	
	// Param[in]: pdfainterface	 The input IFXPDFAInterface	object.	
	// Return:  FS_BOOLEAN.   
	// Remarks: Get if preflight dialog is show.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
	static FS_BOOLEAN GetPreflightWndShow(FR_IFXPDFAInterface pdfainterface);
};


class CFR_IConvertToPDF_V14	//Internal use
{
public:
	//************************************
	// Function:  GetFileType	
	// Param[in]: lpwsFile	 The source file path.	
	// Return:  FR_SUPPORT_FILE_TYPE.
	// Remarks: Get the source file type.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FR_SUPPORT_FILE_TYPE GetFileType(FS_LPCWSTR lpwsFile);

	//************************************
	// Function:  GetFileFilter	
	// Param[in]: uFilter	 The content provider.
	// Param[out]: outFilter The current document object.
	// Return:  void.
	// Remarks: Get file filter.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void GetFileFilter(FS_DWORD uFilter, FS_WideString* outFilter);

	//************************************
	// Function:  ConvertToPDF	
	// Param[in]: lpwsFile	 The source file path.
	// Param[in]: lpwsDest   The dest file path.	
	// Param[in]: hWnd	     The app mainframe, it get from <a>FRAppGetMainFrameWnd</a>.
	// Param[in]: bShowProgressBar		 Set true will show progress bar.	
	// Param[in]: bConvertToCPD	 Whether to convert to CPD.
	// Param[in]: pmba	     Error message box when convert fail.
	// Param[in]: bDelDestFile	Whether need to delete dest file when convert fail.	
	// Param[in]: pDocInfo	 Convert document info.
	// Return:  FS_INT32.
	// Remarks: Convert file to PDF.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
 	// Deprecated: Internal use.
	//************************************
	static FS_INT32 ConvertToPDF(FS_LPWSTR lpwsFile, FS_LPWSTR lpwsDest, FS_HWND hWnd, FS_BOOL bShowProgressBar, FS_BOOL bConvertToCPD, FR_PMSGBOX_ATTRIBUTE pmba, FS_BOOL bDelDestFile, FR_PDocumentInfo pDocInfo);
};


class CFR_ITagePDF_V14//Internal use
{
public:	
	//************************************
	// Function:  ClearAllData	
	// Param[in]: pRDoc	     The current document.
	// Return:  void.
	// Remarks: When the streaming edit exits, the tree needs to be rebuilt and the data needs to be cleared
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void ClearAllData(FR_Document pRDoc);

	//************************************
	// Function:  TryRebuildPanel	
	// Param[in]: panelType	     The panel type.
	// Return:  void.
	// Remarks: Rebuild tag panel
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 TryRebuildPanel(FR_TagPDF_PanelType panelType);

	//************************************
	// Function:  AsyncUpdateCheckerInfo	
	// Param[in]: pRDDoc	     The current document.
	// Param[in]: dwRule	     The panel type.
	// Param[in]: state	         Accessibility checker state.
	// Return:  void.
	// Remarks: Asynchronous operation that actively notifies the Checker Panel to update its status
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void AsyncUpdateCheckerInfo(FR_Document pRDDoc, const FS_DWORD dwRule, const FR_PDFAccessibilityCheckerState state);
};

class CFR_TextPage_V14		//Internal use
{
public:
	static FR_TextPage GetReaderTextPage(FR_Document doc, FS_INT32 iPage, FS_BOOL bCreate);
	static void  ReParseTextPage(FR_TextPage textPage);
	static FR_TextPage  CreateFRTextPage(FPD_Page page, FS_INT32 pageIndex);
};

class CFR_CCBAnnotationHandler : public CCB_Annotation
{
public:
    CFR_CCBAnnotationHandler(FR_CCBAnnotationCallbacksRec*  callback, CPDF_Document* doc);

	virtual FX_BOOL  ParseToXML(CPDF_Dictionary* pAnnotDict, CXML_Element* pElement);
	virtual FX_BOOL  ParseToDict(CXML_Element* pElement, CPDF_Dictionary* pAnnotDict);
	virtual FX_BOOL  IsKeyNeeded_ToXML(CFX_ByteString csKeyName, FX_INT32 nObjType);
	virtual FX_BOOL  IsKeyNeeded_ToDict(CFX_ByteString csKeyName, FX_INT32 nObjType);
	virtual void  AddNecessaryKeyToList_ToXML(CFX_ByteString csKeyName);

    FX_BOOL  ParseToXMLInteranal(CPDF_Dictionary* pAnnotDict, CXML_Element* pElement, FX_BOOL bBaseFun);
    FX_BOOL  ParseToDictInteranal(CXML_Element* pElement, CPDF_Dictionary* pAnnotDict, FX_BOOL bBaseFun);
    FX_BOOL  IsKeyNeeded_ToXMLInteranal(CFX_ByteString csKeyName, FX_INT32 nObjType, FX_BOOL bBaseFun);
    FX_BOOL  IsKeyNeeded_ToDictInteranal(CFX_ByteString csKeyName, FX_INT32 nObjType, FX_BOOL bBaseFun);
    void  AddNecessaryKeyToList_ToXMLInteranal(CFX_ByteString csKeyName, FX_BOOL bBaseFun);

	FR_CCBAnnotationCallbacksRec m_callback;
};

class CFR_ISignatureCheck_V14		//Internal use
{
public:
	static void* New(void* callbacks);
	static void Destroy(void* handler);
};

class CFR_TextLinkInfo_V16 //Internal use.
{
public:
	//************************************
	// Function:  CreateTextLinkInfo
	// Return:	FR_TextLinkInfo
	// Remarks:	Initial a FR_TextLinkInfo object.
	// Notes: 
	// Deprecated: Internal use.
	//************************************
	static FR_TextLinkInfo CreateTextLinkInfo();

	//************************************
	// Function:  DeleteTextLinkInfo
	// Param[in]: info			The input FR_TextLinkInfo object.
	// Return:	void
	// Remarks:	Adds a preference page into Reader preference dialog. 
	// Deprecated: Internal use.
	//************************************
	static void DeleteTextLinkInfo(FR_TextLinkInfo info);
	
	//************************************
	// Function:  GetPageIndex
	// Param[in]: info			The input FR_TextLinkInfo object.
	// Return:	FS_INT32
	// Remarks:	Get the page index where the text link belongs.
	// Deprecated: Internal use.
	//************************************
	static FS_INT32	GetPageIndex(FR_TextLinkInfo info);
	
	//************************************
	// Function:  GetLinkUrl
	// Param[in]: info			The input FR_TextLinkInfo object.
	// Param[out]: wsUrl		Get the link url.	
	// Return:	void
	// Remarks:	Get the link url.
	// Deprecated: Internal use.
	//************************************
	static void	GetLinkUrl(FR_TextLinkInfo info, FS_WideString* wsUrl);

	//************************************
	// Function:  GetRectArray
	// Param[in]: info			The input FR_TextLinkInfo object.
	// Param[out]: rectArr		Get the rect of text link.	
	// Return:	void
	// Remarks:	Get the rect of text link.
	// Deprecated: Internal use.
	//************************************
	static void	GetRectArray(FR_TextLinkInfo info, FS_FloatRectArray* rectArr);

	//************************************
	// Function:  GetModifyDate
	// Param[in]: info			The input FR_TextLinkInfo object.
	// Return:	FS_DWORD
	// Remarks:	Get the modify date of text link.
	// Deprecated: Internal use.
	//************************************
	static FS_DWORD	GetModifyDate(FR_TextLinkInfo info);
};

class CFR_TextLinkMgr_V16 // Internal use.
{
public:
	//************************************
	// Function:  IsEmailAddress
	// Param[in]: csUrl			The input url.
	// Return:	FS_BOOL
	// Remarks:	Check is email address.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	IsEmailAddress(FS_LPCWSTR csUrl);

	//************************************
	// Function:  GetLinkList
	// Param[in]: textPage			The input FR_TextPage.
	// Param[out]: linkArr			Get the link list.
	// Return:	FS_BOOL    TRUE: Get the link success.
	// Remarks:	Get the list of links.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetLinkList(FR_TextPage textPage, FS_PtrArray* linkArr);	

	//************************************
	// Function:  ExecuteTextLink
	// Param[in]: pLinkExt			The input FR_TextLinkInfo.
	// Return:	FS_BOOL
	// Remarks:	Open the url of the link.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL ExecuteTextLink(FR_TextLinkInfo pLinkExt);
};

class CFR_SelectedImageInfo_V16
{
public:
	//************************************
	// Function:  GetImagePDFRect
	// Param[in]: imageInfo			The input FR_SelectedImageInfo.
	// Return:	FS_FloatRect
	// Remarks:	Get pdf rect of the selected image.
	// Notes:
	//************************************
	static FS_FloatRect	GetImagePDFRect(FR_SelectedImageInfo imageInfo);

	//************************************
	// Function:  GetParentForm
	// Param[in]: imageInfo			The input FR_SelectedImageInfo.
	// Return:	FPD_Form            Get the parent form.
	// Remarks:	Get the parent form.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FPD_Form	GetParentForm(FR_SelectedImageInfo imageInfo);

	//************************************
	// Function:  GetObj
	// Param[in]: imageInfo			The input FR_SelectedImageInfo.
	// Param[in]: page			    The input FPD_Page.
	// Return:	FS_BOOL
	// Remarks:	Open the url of the link.
	// Notes:
	//************************************
	static FPD_PageObject GetObj(FR_SelectedImageInfo imageInfo, FPD_Page page);
};

class CFR_ContentObject_V16 //Internal use.
{
public:
	//************************************
	// Function:  CreateContentObject	
	// Return:	FR_STRUCTCONTENT_OBJECT
	// Remarks:	Create FR_STRUCTCONTENT_OBJECT.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FR_STRUCTCONTENT_OBJECT CreateContentObject();

	//************************************
	// Function:  DeleteContentObject
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Return:	void
	// Remarks:	Release FR_STRUCTCONTENT_OBJECT.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void DeleteContentObject(FR_STRUCTCONTENT_OBJECT object);

	//************************************
	// Function:  GetDocView
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Return:	FR_DocView
	// Remarks:	Get the docview.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FR_DocView GetDocView(FR_STRUCTCONTENT_OBJECT object);

	//************************************
	// Function:  GetPageIndex
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Return:	FS_INT32
	// Remarks:	Get the page index.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32	GetPageIndex(FR_STRUCTCONTENT_OBJECT object);

	//************************************
	// Function:  GetPos
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Return:	FS_POSITION
	// Remarks:	Get the position of the object.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_POSITION GetPos(FR_STRUCTCONTENT_OBJECT object);

	//************************************
	// Function:  GetIsInFormXObject
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Return:	FS_BOOL
	// Remarks:	Check whether it is a form object.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	GetIsInFormXObject(FR_STRUCTCONTENT_OBJECT object);

	//************************************
	// Function:  GetFormLayer
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Param[out]: layerArr			Get the index arry of the graphic objects.
	// Return:	void
	// Remarks: Get the index arry of the graphic objects.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void	GetFormLayer(FR_STRUCTCONTENT_OBJECT object, FS_Int32Array* layerArr);

	//************************************
	// Function:  GetObj
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Return:	FPD_PageObject
	// Remarks: Get the FPD_PageObject.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FPD_PageObject	GetObj(FR_STRUCTCONTENT_OBJECT object);

	//************************************
	// Function:  GetObj2
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Param[in]: pPDFPage			The input FPD_Page.
	// Return:	FPD_PageObject
	// Remarks: Get the FPD_PageObject by FPD_Page.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FPD_PageObject	GetObj2(FR_STRUCTCONTENT_OBJECT object, FPD_Page pPDFPage);

	//************************************
	// Function:  GetContainer
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Return:	FPD_GraphicsObjects
	// Remarks: Get the container of the object.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FPD_GraphicsObjects	GetContainer(FR_STRUCTCONTENT_OBJECT object);

	//************************************
	// Function:  GetFormMatrix
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Param[in]: pPDFPage			The input FPD_Page.
	// Return:	FS_AffineMatrix
	// Remarks: Get the matrix of the object.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FS_AffineMatrix	GetFormMatrix(FR_STRUCTCONTENT_OBJECT object, FPD_Page pPDFPage);

	//************************************
	// Function:  GetObjContainer
	// Param[in]: pPage			    The input FPD_Page.
	// Param[in]: vecFormLayer		The input index arry of the graphic objects.
	// Return:	FPD_GraphicsObjects
	// Remarks: Get the object container.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static FPD_GraphicsObjects GetObjContainer(FPD_Page pPage, FS_Int32Array vecFormLayer);

	//************************************
	// Function:  SetDocView
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Param[in]: docview			The input FR_DocView.
	// Return:	void
	// Remarks:	Set the docview.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void SetDocView(FR_STRUCTCONTENT_OBJECT object, FR_DocView docview);

	//************************************
	// Function:  SetPageIndex
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Param[in]: nPageIndex		The input page index.
	// Return:	void
	// Remarks:	Get the page index.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void	SetPageIndex(FR_STRUCTCONTENT_OBJECT object, FS_INT32 nPageIndex);

	//************************************
	// Function:  SetPos
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Param[in]: pos			    The input the position of the object.
	// Return:	FS_POSITION
	// Remarks:	Get the position of the object.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void SetPos(FR_STRUCTCONTENT_OBJECT object, FS_POSITION pos);

	//************************************
	// Function:  SetIsInFormXObject
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Param[in]: bIsInFormXObject	The input set whether it is a form object.
	// Return:	void
	// Remarks:	Set whether it is a form object.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void	SetIsInFormXObject(FR_STRUCTCONTENT_OBJECT object, FS_BOOL bIsInFormXObject);

	//************************************
	// Function: SetFormLayer
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Param[in]: layerArr			Set the index arry of the graphic objects.
	// Return:	void
	// Remarks: Set the index arry of the graphic objects.
	// Notes:
	// Deprecated: Internal use.
	//************************************
	static void	SetFormLayer(FR_STRUCTCONTENT_OBJECT object, FS_Int32Array layerArr);

	//************************************
	// Function: SetTextRange
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.
	// Param[in]: textRangeArr		Set the text range arry of the graphic objects.
	// Return:	void
	// Remarks: Set the text range arry of the graphic objects.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// Deprecated: Internal use.
	//************************************
	static void	SetTextRange(FR_STRUCTCONTENT_OBJECT object, FS_PtrArray textRangeArr);
	
	//************************************
	// Function: GetTextRangeSize
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.	
	// Return:	FS_INT32
	// Remarks: Get the size of text range arry of the graphic objects.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// Deprecated: Internal use.
	//************************************
	static FS_INT32	GetTextRangeSize(FR_STRUCTCONTENT_OBJECT object);

	//************************************
	// Function: GetTextRangeByIndex
	// Param[in]: object			The input FR_STRUCTCONTENT_OBJECT.	
	// Param[in]: index			    The input range index need to get.
	// Return:	FR_TEXTRANGE
	// Remarks: Get the specified index of text range arry of the graphic objects.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// Deprecated: Internal use.
	//************************************
	static FR_TEXTRANGE GetTextRangeByIndex(FR_STRUCTCONTENT_OBJECT object, FS_INT32 index);
};

class CFR_PluginAccessible : public CBA_AccessibleImpl
{
public:
	CFR_PluginAccessible(IReader_Annot *pAnnot, IReader_PageView *pPageView, FR_AccessibleCallbacks callbacks);
	virtual ~CFR_PluginAccessible();	

	virtual  FX_BOOL GetChildCount(long *pcountChildren);
	virtual  FX_BOOL GetRect(CRect& rect);
	virtual FX_BOOL HasChild(long index);
	virtual FX_BOOL getName(std::wstring &name);
	virtual FX_BOOL getValue(std::wstring &value);
	virtual FX_BOOL getDescription(std::wstring &Description);
	virtual FX_BOOL getRole(int &etype);
	virtual FX_BOOL getState(int &etype);
	virtual FX_BOOL getSelection(int &index);
	virtual FX_INT32 getAction(std::wstring &action);
	virtual FX_BOOL DoDefaultAction();
	virtual FX_BOOL SetValue(std::wstring &name);
	virtual FX_BOOL getState(FX_INT32 index, int &etype);
	virtual FX_BOOL getOptionLabel(FX_INT32 nindex, std::wstring &value);
	virtual FX_BOOL getOptionValue(FX_INT32 nindex, std::wstring &value);
	virtual FX_INT32 getAction(FX_INT32 nindex, std::wstring &value);
	//seledttype 1  select 0 remove select 2  reselect
	virtual FX_BOOL SetSelection(FX_INT32 nindex, FX_INT32 seledttype);
	virtual FX_BOOL DoDefaultAction(FX_INT32 tindex);
	virtual FX_BOOL GetSelectCount(FX_INT32 &nCount);
	virtual FX_BOOL GetCurIndexSelectindex(FX_INT32& nindex, FX_INT32 curselectindex);

protected:
	FR_AccessibleCallbacksRec m_callbacks;
};

class CFR_Accessible_V17 
{
public:
	static FR_Accessible  New(FR_Annot pAnnot, FR_PageView pPageView, FR_AccessibleCallbacks callback);
	static void  Delete(FR_Accessible  accessbile);
};

class CFR_PageObserver_V17 //Internal use
{
public:
	//************************************
	// Function:  CreatePageObserver	
	// Param[in]: page		The FR_Page object.			
	// Return:  FR_PageObserver.
	// Remarks: Encapsulat the IReader_Page::Observer to listen the object in plugin.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// See:
	// Deprecated: Internal use
	//************************************
	static FR_PageObserver CreatePageObserver(FR_Page page);

	//************************************
	// Function:  DestroyPageObserver	
	// Param[in]: observer		The FR_PageObserver object.			
	// Return:  void.
	// Remarks: Destroy FR_PageObserver object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// See:
	// Deprecated: Internal use
	//************************************
	static void DestroyPageObserver(FR_PageObserver observer);

	//************************************
	// Function:  IsValid	
	// Param[in]: observer		The FR_PageObserver object.			
	// Return:  FS_BOOLEAN.
	// Remarks: Check is the FR_Page is valid.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// See:
	// Deprecated: Internal use
	//************************************
	static FS_BOOLEAN IsValid(FR_PageObserver observer);

	//************************************
	// Function:  GetPageObj	
	// Param[in]: observer		The FR_PageObserver object.			
	// Return:  FR_Page.
	// Remarks: Get the FR_Page object of the observer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// See:
	// Deprecated: Internal use
	//************************************
	static FR_Page GetPageObj(FR_PageObserver observer);
};

class CFR_AnnotHandler_V17
{
public:
	static FR_AnnotHandler GetAnnotHandlerByType(FS_LPCSTR sType);
	static FR_AnnotHandler GetAnnotHandlerByAnnot(FR_Annot pAnnot);
	static FS_BOOLEAN IsPermissionAllowed(FR_AnnotHandler annotHandler, FR_Document pDocument, FS_LPCSTR sSubType);
	static void GetPropertyBoxTitle(FR_AnnotHandler annotHandler, FS_LPCSTR sSubType, FS_WideString* outTitle);
	static void GetType(FR_AnnotHandler annotHandler, FS_ByteString* outType);
	static void GetName(FR_AnnotHandler annotHandler, FS_ByteString* outName);
};

class CFR_IWidgetAnnotHandlerCustomOperate : public IWidgetAnnotHandler_CustomOperate
{
public:
	CFR_IWidgetAnnotHandlerCustomOperate(FR_WidgetAnnotHandlerCallbacks callbacks);
	~CFR_IWidgetAnnotHandlerCustomOperate();
	virtual FX_BOOL GetCustomHightColor(IReader_Annot *pAnnot, COLORREF &fillcolorW);
	virtual FX_BOOL IsShowQuickAccPropery(IReader_Annot *pAnnot);
	virtual FX_BOOL GetSignatureAuditTrail(CPDF_Dictionary *pAnnotDict, CFX_WideString& text);
	virtual FX_BOOL GetSignatureHashInfo(CPDF_Dictionary *pAnnotDict, CFX_WideString& lastHash, CFX_WideString& currentHash);
	virtual FX_BOOL IsShowSignaturePanelMenu(CPDF_Dictionary *pAnnotDict, FX_INT32& nExData);

protected:
	FR_WidgetAnnotHandlerCallbacksRec m_Callbacks;
};

class CFR_WidgetAnnotHandler_V17
{
public:
	static FR_WidgetAnnotHandler  Create(FR_WidgetAnnotHandlerCallbacks callbacks);
	static void Delete(FR_WidgetAnnotHandler handler);
	static FS_BOOLEAN OnGetCustomHightColor(FR_WidgetAnnotHandler handler, FR_Annot pAnnot, FS_DWORD* fillcolorW);
	static FS_BOOLEAN OnIsShowQuickAccPropery(FR_WidgetAnnotHandler handler, FR_Annot pAnnot);
	static FS_BOOLEAN OnGetSignatureAuditTrail(FR_WidgetAnnotHandler handler, FPD_Object pAnnotDict, FS_WideString* text);
	static FS_BOOLEAN OnGetSignatureHashInfo(FR_WidgetAnnotHandler handler, FPD_Object pAnnotDict, FS_WideString* lastHash, FS_WideString* currentHash);
	static FS_BOOLEAN OnIsShowSignaturePanelMenu(FR_WidgetAnnotHandler handler, FPD_Object pAnnotDict, FS_INT32* nExData);
};

class CFR_IAnnotHandlerCustomOperate : public IAnnotHandler_CustomOperate
{
public:
	CFR_IAnnotHandlerCustomOperate(FR_AnnotOperateHandlerCallbacks callbacks);
	~CFR_IAnnotHandlerCustomOperate();

	virtual FX_BOOL OnMouseMsg(IReader_PageView *pPageView, IReader_Annot *pAnnot, msgType emsgtype);
	virtual FX_BOOL CanMove(IReader_PageView *pPageView, IReader_Annot *pAnnot, int  movetype, FX_BOOL& bCanMove);
	virtual FX_BOOL CanAnswer(IReader_Annot* pAnnot);
	virtual FX_BOOL CanCopy(IReader_Annot* pAnnot, int ndestpagindex);
	virtual FX_BOOL OnLockAnnot(IReader_Annot* pAnnot, FX_BOOL bLock);

protected:
	FR_AnnotOperateHandlerCallbacksRec m_Callbacks;
};

class CFR_AnnotOperateHandler_V17
{
public:
	static FR_AnnotOperateHandler  Create(FR_AnnotOperateHandlerCallbacks callbacks);
	static void Delete(FR_AnnotOperateHandler handler);
	static FS_BOOLEAN OnMouseMsg(FR_AnnotOperateHandler handler, FR_PageView pPageView, FR_Annot pAnnot, FR_AnnotMsgType emsgtype);
	static FS_BOOLEAN OnCanMove(FR_AnnotOperateHandler handler, FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 movetype, FS_BOOLEAN* bCanMove);
	static FS_BOOLEAN OnCanAnswer(FR_AnnotOperateHandler handler, FR_Annot pAnnot);
	static FS_BOOLEAN CanCopy(FR_AnnotOperateHandler handler, FR_Annot pAnnot, FS_INT32 pageIndex);
	static FS_BOOLEAN OnLock(FR_AnnotOperateHandler handler, FR_Annot pAnnot, FS_BOOLEAN bLock);
};

class CFR_BaseAnnot_V17
{
public:
	static void	SetAnnotMsgHook(FR_AnnotOperateHandler pHandler);
	static FR_AnnotOperateHandler GetAnnotMsgHookHandler(FS_INT32 index);
	static void	RemoveAnnotMsgHook(FR_AnnotOperateHandler hookHandler);
	static FS_INT32	GetAnnotMsgHookCount();
};

class CFR_SaveAsNotify : public IReader_Save_SaveAsNotify
{
public:
	CFR_SaveAsNotify(FR_SaveAsCallbacks callbacks);
	~CFR_SaveAsNotify();

	virtual bool			IsSaveAsSaveTo(IReader_Document* pRDoc);
	virtual CFX_WideString	GetSaveToDefaultName(IReader_Document* pRDoc);
	virtual bool			IsNeedShowSaveDlg();

protected:
	FR_SaveAsNotifyCallbacksRec m_Callbacks;
};

class CFR_SaveAsNotify_V17
{
public:
	static FR_Save_SaveAsNotify New(FR_SaveAsCallbacks callbacks);
	static void Delete(FR_Save_SaveAsNotify notify);	
	static FS_BOOLEAN IsSaveAsSaveTo(FR_Save_SaveAsNotify notify, FR_Document pRDoc);
	static void GetSaveToDefaultName(FR_Save_SaveAsNotify notify, FR_Document pRDoc, FS_WideString* saveName);
	static FS_BOOLEAN IsNeedShowSaveDlg(FR_Save_SaveAsNotify notify);
};

#ifdef __cplusplus
};
#endif

#endif

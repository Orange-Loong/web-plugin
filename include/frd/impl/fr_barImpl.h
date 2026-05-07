/** @file fr_barImpl.h.
 * 
 *  @brief FR bars including statusbar,toolbar.
 */
 
#ifndef FR_BARIMPL_H
#define FR_BARIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../include/basic/fs_internalInc.h"
#endif

#ifndef FR_BAREXPT_H
#include "../fr_barExpT.h"
#endif


#ifdef __cplusplus
extern "C"{
#endif

class CFR_ToolButton_V1 //Internal use
{
public:
	//************************************
	// Function:  New
	// Param[in]: name			The button's name.
	// Param[in]: bSeparate		A flag indicate whether a button or a separator is to be created.
	// Param[in]: pParentWnd	A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	// You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	// If <a>TRUE</a>, the new button is a separator used to leave space between groups of related buttons.
	// If <a>FALSE</a>, the button is a normal button.
	// Return: The newly toolbar button.	
	// Remarks:Creates a toolbar button or a separator with the specified name. 	
	// Notes: 
	// See: FRToolButtonRelease
	// See: FRToolButtonSetExcuteProc
	// See: FRToolButtonSetEnableProc
	// See: FRToolButtonSetMarkedProc
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FR_ToolButton	New(const FS_CHAR* name, FS_BOOL bSeparate, void* pParentWnd);

	//************************************
	// Function:  Release
	// Param[in]: btn			The button to release.
	// Param[in]: pParentWnd	A pointer to the parent window that you must specify. It represents the <Italic>MFC CWnd*</Italic>.
	// You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	// Return:	void
	// Remarks: Removes a specified toolbar button and releases it. Call <a>FRToolButtonUpdateButtonStates</a>()
	// after removing a button to update the toolbar.
	// Notes:
	// See: FRToolButtonNew
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static void				Release(FR_ToolButton btn, void* pParentWnd);
	
	//************************************
	// Function:  GetName
	// Param[in]: btn			The button whose name is obtained.
	// Param[out]: outName		(Filled by the method) A string buffer to receive the name.	
	// Return: <a>TRUE</a> if the <param>outName</param> is filled successfully, otherwise not.
	// Remarks:	Gets the name of the specified button.
	// Notes:
	// See: FRToolBarGetButtonByName
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FS_BOOL			GetName(FR_ToolButton btn, FS_ByteString* outName);

	//************************************
	// Function:  GetLabelText
	// Param[in]: btn				The button whose label is obtained.
	// Param[out]: outLableText		(Filled by the method) A Unicode string buffer to receive
	// the button's label text.
	// Return: <a>TRUE</a> if the <param>outLableText</param> is filled successfully, otherwise not.
	// Remarks:	Gets the label text of specified button.
	// Notes:
	// See: FRToolButtonSetLableText
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.

	//************************************
	static FS_BOOL			GetLabelText(FR_ToolButton btn, FS_WideString* outLableText);

	//************************************
	// Function:  SetLabelText
	// Param[in]: btn			The button whose label text is set.
	// Param[in]: labelText		A pointer to a wide string buffer. The string buffer is read-only.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Sets the label text of the specified button.  	
	// Notes:
	// See: FRToolButtonGetLabelText
	// See: FRToolButtonSetHelpText
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FS_BOOL				SetLabelText(FR_ToolButton btn, FS_LPCWSTR labelText);


	//************************************
	// Function:  SetHelpText
	// Param[in]: btn			The button to which a tooltip is added.
	// Param[in]: helpText		The text to show.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Sets the help text of the specified button.  	
	// Notes:
	// See: FRToolButtonSetLabelText
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FS_BOOL				SetHelpText(FR_ToolButton btn, FS_LPCWSTR helpText);

	//************************************
	// Function:  SetIcon
	// Param[in]: btn			The button whose icon is set.
	// Param[in]: bitmap		The icon to set.
	// Param[in]: flyToolbar	If this button is used for fly toolbar, input the fly toolbar. Otherwise, set it to NULL.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks: Sets a new bitmap for a toolbar button.	The size of bitmap which to be set to a button is different between
	//			common toolbar mode and tabbed toolbar mode, with common mode, the size of bitmap is 24 * 24, but 32 * 32 with
	//			tabbed mode.
	// Notes: The bitmap to set for a toolbar button will be maintained and released by the toolbar.
	// So client can not release it.
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************	
	static FS_BOOL				SetIcon(FR_ToolButton btn, FS_DIBitmap bitmap, FR_ToolBar flyToolbar);

	//************************************
	// Function:  IsSeparator
	// Param[in]: btn			The button to test.
	// Return: <a>TRUE</a> if a button is a separator, otherwise not.
	// Remarks: Tests whether a toolbar button is a separator or a normal button.	  	
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FS_BOOL			IsSeparator(FR_ToolButton btn);

	//************************************
	// Function:  IsVisible
	// Param[in]: btn			The button to test.
	// Return: <a>TRUE</a> if a button is visible, otherwise not.
	// Remarks: Tests whether a toolbar button is visible.	  	
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FS_BOOL			IsVisible(FR_ToolButton btn);
	
	
	//************************************
	// Function:  SetExecuteProc
	// Param[in]: btn			The button whose intended function is set.
	// Param[in]: proc			The user-supplied procedure to call when <param>btn</param> is clicked.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks: Sets the user-supplied procedure to call to perform the button's intended function.
	// Notes: The user-supplied data to pass to FRExecuteProc() must be set if the callback 
	// FRExecuteProc() needs. Using FRToolButtonSetClientDate() to set it.
	// See: FRToolButtonNew
	// See: FRToolButtonSetEnableProc
	// See: FRToolButtonSetMarkedProc
	// See: FRToolButtonSetClientData
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FS_BOOL			SetExecuteProc(FR_ToolButton btn, FRExecuteProc proc);

	//************************************
	// Function:  SetEnableProc
	// Param[in]: btn			The button whose <a>FRBtnEnableProc</a>() is set.
	// Param[in]: proc			A user-supplied procedure to call whenever Reader needs to know whether
	// a button should be enabled.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks: Sets a <a>FRBtnEnableProc</a>() associated with a button. This rountine determines whether
	// a toolbar button can be selected.
	// Notes: The user-supplied data to pass to FRBtnEnableProc() must be set if the callback 
	// FRBtnEnableProc() need. Using FRToolButtonSetClientDate() to set it.
	// See: FRToolButtonNew
	// See: FRToolButtonSetExecuteProc
	// See: FRToolButtonSetMarkedProc
	// See: FRToolButtonSetClientData
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FS_BOOL			SetEnableProc(FR_ToolButton btn, FRComputeEnabledProc proc);

	//************************************
	// Function: SetMarkedProc 
	// Param[in]: btn			The button whose <a>FRBtnCheckProc</a>() is set.
	// Param[in]: proc			A user-supplied procedure to call whenever Reader needs to know whether
	// the specified button should be marked.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks: Sets a <a>FRBtnCheckProc</a>() associated with a button. 
	// Notes: The user-supplied data passed to FRBtnCheckProc() must be set if the callback 
	// FRBtnCheckProc() need. Using FRToolButtonSetClientDate() to set it.
	// See: FRToolButtonNew
	// See: FRToolButtonSetExecuteProc
	// See: FRToolButtonSetEnableProc
	// See: FRToolButtonSetClientData
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FS_BOOL			SetMarkedProc(FR_ToolButton btn, FRComputeMarkedProc proc);

	//************************************
	// Function:  SetDropDownProc
	// Param[in]: btn			The button whose <a>FRBtnDropDownProc</a>() is set.
	// Param[in]: proc			A user-supplied procedure to call when user click the drop-down arrow 
	// displayed next to the button image or text.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks: Sets a <a>FRBtnDropDownProc</a>() associated with a button. 
	// Notes: The user-supplied data passed to FRBtnDropDownProc() must be set if the callback 
	// FRBtnDropDownProc() need. Using FRToolButtonSetClientDate() to set it.
	// See: FRToolButtonSetClientData
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************	
	static FS_BOOL				SetDropDownProc(FR_ToolButton btn, FRBtnDropDownProc proc);

	//************************************
	// Function:  GetClientData
	// Param[in]: btn			The button whose client-data is got.
	// Return: A pointer to a user-supplied data structure. It returns <a>NULL</a>
	// if no client data to be set.
	// Remarks:	Gets the user-supplied data structure set to tool button using <a>FRToolButtonSetClientData</a>().  	
	// Notes:
	// See: FRToolButtonSetClientData
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static void*		 GetClientData(FR_ToolButton btn);

	//************************************
	// Function:  ExecuteProc
	// Param[in]: btn			The button whose execute proc is executed.
	// Return:	void
	// Remarks:	Executes the <a>FRExecuteProc</a>() associated with button. It does nothing if 
	// <a>FRBtnEnableProc</a>() returns <a>FALSE</a>.
	// Notes:
	// See: FRToolButtonSetExecuteProc
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static void			ExecuteProc(FR_ToolButton btn);


	//************************************
	// Function:  SetFlyoutToolBar
	// Param[in]: btn				The button to which the flyout toolbar is appended.
	// Param[in]: flyout			The flyout toolbar which to be appended to the <param>btn</param>.				
	// Return: <a>TRUE</a> means successful, otherwise not.
	// Remarks: Sets the fly-out toolbar to a specified button.
	// Notes:
	// See: FRToolBarNewFlyout
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FS_BOOL		SetFlyoutToolBar(FR_ToolButton btn,  FR_ToolBar flyout);

	//************************************
	// Function:  GetMapId
	// Param[in]: btn				The input button.	
	// Return: The map id of the button.
	// Remarks: Gets the map id of the button.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRWndProviderOnCmdMsg
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FS_DWORD GetMapId(FR_ToolButton btn);

	//************************************
	// Function:  SetClientData
	// Param[in]: btn			The button whose client-data is set.
	// Param[in]: clientData	A pointer to user-supplied data to pass to <a>FRExecuteProc</a>(),
	// <a>FRBtnEnableProc</a>(), <a>FRBtnCheckProc</a>(), or <a>FRBtnDropDownProc</a>(). The data type 
	// may be a class or a struct that contain each client data to pass to each user-supplied procedure.
	// Param[in]: callback		It will be called when the tool button is to be destroyed.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks: Sets the user-supplied data for each  user-supplied procedure.	  	
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonElement and relevant functions  instead.
	//************************************
	static FS_BOOL SetClientData(FR_ToolButton btn, void* clientData, FRFreeDataProc callback);
};


class CFR_ToolBar_V1 //Internal use
{
public:
	//************************************
	// Function:  New
	// Param[in]: name			The name of the toolbar. It may not be <a>NULL</a>.
	// Param[in]: title			The title of the toolbar. It may not be <a>NULL</a>.
	// Param[in]: pParentWnd	A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	// You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	// Return: The new <a>FR_ToolBar</a> object.
	// Remarks: Creates a new named toolbar, or <a>NULL</a> if a toolbar with the <param>name</param> exists.
	// Notes:
	// See: FRToolBarRelease
	// See: FRToolButtonNew
	// See: FRToolBarCountButtons
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions  instead.
	//************************************
	static FR_ToolBar		New(const FS_CHAR* name, FS_LPCWSTR title, void* pParentWnd);

	//************************************
	// Function:  NewFlyout
	// Param[in]: name			The name of the flyout toolbar. It may not be <a>NULL</a>.
	// Param[in]: title			The title of the flyout toolbar. It may not be <a>NULL</a>.
	// Param[in]: pParentWnd	A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	// You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	// Return: The newly created fly-out toolbar.
	// Remarks: Creates a new named flyout toolbar, or <a>NULL</a> if a toolbar with the <param>name</param> exists. 
	// A fly-out toolbar is used to append to a toolbar's button with the drop-down style.
	// Notes:
	// See: FRToolBarRelease
	// See: FRToolButtonNew
	// See: FRToolBarCountButtons
	// See: FRToolButtonSetFlyoutToolBar
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FR_ToolBar		NewFlyout(const FS_CHAR* name, FS_LPCWSTR title, void* pParentWnd);

	//************************************
	// Function: Release 
	// Param[in]: toolbar		The toolbar to be released.
	// Param[in]: pParentWnd	A pointer to the parent window that you must specify. It represents the <Italic>MFC CWnd*</Italic>.
	// You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	// Return:	void
	// Remarks: Removes a specified toolbar and releases it.
	// Notes:
	// See: FRToolBarNew
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static void				Release(FR_ToolBar toolbar, void* pParentWnd);
	
	//************************************
	// Function:  GetName
	// Param[in]: toolbar			The toolbar whose name is obtained.
	// Param[out]: outName			(Filled by this method) The string buffer to receive the 
	// toolbar's name.
	// Return: <a>TRUE</a> if the <param>outName</param> is filled successfully, otherwise not.
	// Remarks:	Gets the toolbar's name.  	
	// Notes:
	// See: FRAppGetToolBarByName
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FS_BOOL			GetName(FR_ToolBar toolbar, FS_ByteString* outName);

	//************************************
	// Function:  CountButtons
	// Param[in]: toolbar			The toolbar whose button count is obtained.
	// Return: The button number of the specified toolbar.	
	// Remarks: Counts the button number of the a toolbar.
	// Notes:
	// See: FRToolBarGetButton
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FS_INT32				CountButtons(FR_ToolBar toolbar);

	//************************************
	// Function:  GetButton
	// Param[in]: toolbar			The toolbar whose button is obtained.
	// Param[in]: index				The index of the button. The index range is 0 to (<a>FRToolBarCountButton</a>()-1).
	// Return: The specified button.
	// Remarks: Gets the specified button.
	// Notes:
	// See: FRToolBarCountButtons
	// See: FRToolBarGetButtonByName
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FR_ToolButton	GetButton(FR_ToolBar toolbar, FS_INT32 index);


	//************************************
	// Function:  GetTitle
	// Param[in]: toolbar			The toolbar whose title is obtained.
	// Param[out]: outTitle			(Filled by this method) A wide string buffer to receive the toolbar's title.
	// Return: <a>TRUE</a> if the <param>outTitle</param> is filled successfully, otherwise not.
	// Remarks: Gets the title of the specified toolbar.
	// Notes:
	// See: FRToolBarSetTitle
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************	
	static FS_BOOL			GetTitle(FR_ToolBar toolbar, FS_WideString* outTitle);

	//************************************
	// Function:  SetTitle
	// Param[in]: toolbar			The toolbar whose title is set.
	// Param[in]: title				The title to set.
	// Return:	void
	// Remarks: Sets the title of specified toolbar.
	// Notes:
	// See: FRToolBarGetTitle
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static void				SetTitle(FR_ToolBar toolbar, FS_LPCWSTR title);
	

	//************************************
	// Function:  GetButtonByName
	// Param[in]: toolbar			The input toolbar.
	// Param[in]: name				The name for the button to get.
	// Return: The button with the specified name, if the name is not found, the return value
	// is <a>NULL</a>.
	// Remarks: Gets the toolbar button that has the specified name.	  	
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FR_ToolButton	GetButtonByName(FR_ToolBar toolbar, const FS_CHAR* name);
	

	//************************************
	// Function:  AddButton
	// Param[in]: toolbar			The toolbar into which a button is added.
	// Param[in]: btn				The button to add to the toolbar.
	// Return: <a>TRUE</a> if success, otherwise not.
	// Remarks: Adds a button to the end of the toolbar. Using <a>FRToolBarAddButton</a>()
	// to insert a button into the toolbar.
	// Notes:
	// See: FRToolBarInsertButton
	// See: FRToolBarRemoveButton
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FS_BOOL			AddButton(FR_ToolBar toolbar, FR_ToolButton btn);

	//************************************
	// Function:  InsertButton
	// Param[in]: toolbar			The toolbar into which a button is inserted.
	// Param[in]: btn				The button to insert into the toolbar.
	// Param[in]: iInsertAt			The specified index for inserting.
	// Return: <a>TRUE</a> if success, otherwise <a>FALSE</a>.
	// Remarks:	Inserts a button into a toolbar.  	
	// Notes:
	// See: FTToolBarAddButton
	// See: FRToolBarRemoveButton
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FS_BOOL			InsertButton(FR_ToolBar toolbar, FR_ToolButton btn, FS_INT32 iInsertAt);

	//************************************
	// Function:  ShowToolBar
	// Param[in]: toolbar			The toolbar to show.
	// Return:	void
	// Remarks: Shows a toolbar. 	
	// Notes:
	// See: FTToolBarHideToolBar
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static void				ShowToolBar(FR_ToolBar toolbar);

	//************************************
	// Function:  HideToolBar
	// Param[in]: toolbar			The toolbar to hide.
	// Return:	void
	// Remarks: Hides a toolbar.
	// Notes:
	// See: FTToolBarShowToolBar
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static void				HideToolBar(FR_ToolBar toolbar);

	//************************************
	// Function:  ShowToolButton
	// Param[in]: toolbar			The toolbar whose button is showed.
	// Param[in]: btn				The button to show.
	// Return:	void
	// Remarks:	Shows a existing toolbar button. 	
	// Notes:
	// See: FRToolBarHideToolButton
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static void				ShowToolButton(FR_ToolBar toolbar, FR_ToolButton btn);

	//************************************
	// Function:  HideToolButton		
	// Param[in]: toolbar			The toolbar whose button is hided.
	// Param[in]: btn				The button to hide.
	// Return:	void
	// Remarks: Hides a existing toolbar button.
	// Notes:
	// See: FRToolBarShowToolButton
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static void				HideToolButton(FR_ToolBar toolbar, FR_ToolButton btn);

	//************************************
	// Function:  RemoveButton
	// Param[in]: toolbar			The toolbar whose button is removed.
	// Param[in]: btn				The button to remove.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Removes the specified button from the toolbar, but does not destroy the button. Call 
	// <a>FRToolBarUpdateButtonStates</a>() after removing a button to update the toolbar.	
	// Notes:
	// See: FRToolBarUpdateButtonStates
	// See: FRToolBarAddButton
	// See: FRToolBarInsertButton
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FS_BOOL				RemoveButton(FR_ToolBar toolbar, FR_ToolButton btn);

	//************************************
	// Function:  UpdateButtonStates
	// Param[in]: toolbar	The input toolbar.
	// Return:	void
	// Remarks:	Updates the states of buttons when the toolbar is modified.
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static void				UpdateButtonStates(FR_ToolBar toolbar);


	//************************************
	// Function:  IsFlyOutToolbar
	// Param[in]: toolbar	The input toolbar.
	// Return:	  <a>TRUE</a> means that the toolbar is a fly-out toolbar, otherwise not.
	// Remarks:	  Whether the toolbar is a fly-out toolbar or not.
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FS_BOOL			IsFlyOutToolbar(FR_ToolBar toolbar);

	//************************************
	// Function:  SetMenuTitle
	// Param[in]: toolbar	The input toolbar.
	// Param[in]: menutitle	The input menu title.
	// Return:	  void.
	// Remarks:	  Sets the menu title.
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static void			SetMenuTitle(FR_ToolBar toolbar, FS_LPCWSTR menutitle);

	//************************************
	// Function:  SetDefaultToolbar
	// Param[in]: toolbar	The input toolbar.
	// Return:	  void.
	// Remarks:	  Sets the toolbar as a default toolbar that will be shown when application starts up.
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static void			SetDefaultToolbar(FR_ToolBar toolbar);

	//************************************
	// Function:  HideButtonInBrowser
	// Param[in]: toolbar	The input toolbar.
	// Param[in]: csName	The specified button name.
	// Param[in]: bHide		Sets it TRUE if you want to hide the button in browser mode, otherwise FALSE.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Hides the specified button in browser mode or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FS_BOOL		HideButtonInBrowser(FR_ToolBar toolbar, FS_LPCSTR csName, FS_BOOL bHide);

	//************************************
	// Function:  IsVisible
	// Param[in]: toolbar	The input toolbar.
	// Return: <a>TRUE</a> if the toolbar is visible, otherwise not.
	// Remarks: Checks whether the toolbar is visible or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FS_BOOL IsVisible(FR_ToolBar toolbar);

	//************************************
	// Function:  IsDisable
	// Param[in]: toolbar	The input toolbar.
	// Return: <a>TRUE</a> if the toolbar is disabled, otherwise not.
	// Remarks: Checks whether the toolbar is disabled or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static FS_BOOL IsDisable(FR_ToolBar toolbar);

	//************************************
	// Function:  SetDisable
	// Param[in]: toolbar	The input toolbar.
	// Return: void.
	// Remarks: Disables the toolbar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static void	SetDisable(FR_ToolBar toolbar);

	//************************************
	// Function:  Dock
	// Param[in]: toolbar	The input toolbar.
	// Return: void.
	// Remarks: Docks the toolbar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_RibbonBar and relevant functions instead.
	//************************************
	static void Dock(FR_ToolBar toolbar);
};

class CFR_MessageBar_V1 //Internal use
{
public:
	//************************************
	// Function:  Create
	// Param[in]: bShowCloseBtn Whether to show the <Italic>"Close"</Italic> button on the message bar or not.
	// Param[in]: hFrameWnd		The input parent frame window.
	// Param[in]  eType			The icon type.
	// Return: The new <a>FR_MessageBar</a> object.
	// Remarks: Creates a new message bar, or <a>NULL</a> if fails. Plug-in can create a message bar in the 
	// <a>FRDocOnFrameCreate</a>() callback.
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FR_MessageBar Create(FS_BOOL bShowCloseBtn, HWND hFrameWnd, FRMessageBarIconType eType);

	//************************************
	// Function:  Destroy
	// Param[in]: msgBar The input message bar to be destroyed.
	// Return: void
	// Remarks: Destroys the message bar. Plug-in can destroy a message bar in the <a>FRDocOnFrameDestroy</a>() callback.
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static void Destroy(FR_MessageBar msgBar);

	//************************************
	// Function:  Show
	// Param[in]: msgBar	The input message bar.
	// Param[in]: bShow		Whether to show the message bar or not.
	// Return: <a>TRUE</a> means successful, otherwise not.
	// Remarks: Shows the message bar or hides it.
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_BOOL Show(FR_MessageBar msgBar, FS_BOOL bShow);
	
	//************************************
	// Function:  IsVisible
	// Param[in]: msgBar The input message bar.
	// Return: <a>TRUE</a> means the message bar is visible, otherwise not.
	// Remarks: Checks whether the message bar is visible or not.
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_BOOL IsVisible(FR_MessageBar msgBar);
	
	//************************************
	// Function:  SetText
	// Param[in]: msgBar		The input message bar.
	// Param[in]: wsText		The input text to be set to the message bar.
	// Param[in]: textAlignment	The input text alignment type.
	// Return: void
	// Remarks: Sets text to the message bar.
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static void SetText(FR_MessageBar msgBar, FS_WideString wsText, FRMessageBarElementAlignment textAlignment);
	
	//************************************
	// Function:  SetBitmap
	// Param[in]: msgBar			The input message bar.
	// Param[in]: bitmap			The input bitmap to be set to the message bar.
	// Param[in]: bStretch			Whether to stretch the bitmap or not.
	// Param[in]: bmpAlignment		The input bitmap alignment type.
	// Return: void
	// Remarks: Sets bitmap to the message bar.
	// Notes:
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static void SetBitmap(FR_MessageBar msgBar, FS_DIBitmap bitmap, FS_BOOL bStretch, FRMessageBarElementAlignment bmpAlignment);
	
	//************************************
	// Function:  AddButton
	// Param[in]: msgBar			The input message bar.
	// Param[in]: lpsName			The input name of the button.
	// Param[in]: lpwsText			The input text displayed on the button.
	// Param[in]: btnBitmap			The input bitmap showed on the button.
	// Param[in]: bHasDropDownArrow	Whether the button has the dropped down arrow or not.
	// Param[in]: bNeedLayout		Whether the button need to be laid out.
	// Return: void
	// Remarks: Adds a new button to the message bar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static void AddButton(FR_MessageBar msgBar, FS_LPCSTR lpsName, FS_LPCWSTR lpwsText, FS_DIBitmap btnBitmap, FS_BOOL bHasDropDownArrow, FS_BOOL bNeedLayout);

	//************************************
	// Function:  SetButtonAlignment
	// Param[in]: msgBar			The input message bar.
	// Param[in]: bmpAlignment		The input alignment type.
	// Return: void
	// Remarks: Sets the alignment type of the buttons.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static void SetButtonAlignment(FR_MessageBar msgBar, FRMessageBarElementAlignment bmpAlignment);

	//************************************
	// Function:  SetButtonDropDownProc
	// Param[in]: msgBar	The input message bar.
	// Param[in]: lpsName	Specifies the button name.
	// Param[in]: proc		The input drop-down callback function.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Sets the drop-down callback function.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_BOOL SetButtonDropDownProc(FR_MessageBar msgBar, FS_LPCSTR lpsName, FRBtnDropDownProc proc);

	//************************************
	// Function:  SetButtonExecuteProc
	// Param[in]: msgBar	The input message bar.
	// Param[in]: lpsName	The button you want to set.
	// Param[in]: proc		The user-supplied procedure to call when the button on the message bar is clicked.
	// Return:	  <a>TRUE</a> means success, otherwise failure.
	// Remarks: Sets the user-supplied procedure to call to perform the button's intended function.
	// Notes: The user-supplied data to pass to FRExecuteProc() must be set if the callback 
	// FRExecuteProc() needs. Using FRMessageBarSetClientData() to set it.
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_BOOL SetButtonExecuteProc(FR_MessageBar msgBar,  FS_LPCSTR lpsName, FRExecuteProc proc);
	
	//************************************
	// Function:  SetButtonHelpText
	// Param[in]: msgBar		The input message bar.
	// Param[in]: lpsName	The button you want to set.
	// Param[in]: wsHelpText	The input help text to be set to the message bar.	
	// Return:	  <a>TRUE</a> means success, otherwise failure.
	// Remarks: Sets the help text to the message bar.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_BOOL SetButtonHelpText(FR_MessageBar msgBar, FS_LPCSTR lpsName, FS_WideString wsHelpText);
	
	//************************************
	// Function:  EnableButton
	// Param[in]: msgBar	The input message bar.
	// Param[in]: lpsName	The button you want to set.
	// Param[in]: bEnable	Whether the button is enable or not.	
	// Return:	  <a>TRUE</a> means success, otherwise failure.
	// Remarks: If the <param>bEnable</param> is <a>TRUE</a>, the button is enabled. Otherwise not.
	// Notes:  Using FRMessageBarIsButtonEnable() to get it.
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_BOOL EnableButton(FR_MessageBar msgBar, FS_LPCSTR lpsName, FS_BOOL bEnable);
	
	//************************************
	// Function:  SetButtonPressed
	// Param[in]: msgBar	The input message bar.
	// Param[in]: lpsName	The button you want to set.
	// Param[in]: bPressed	Whether the button has the pressed type.	
	// Return:	  <a>TRUE</a> means success, otherwise failure.
	// Remarks: Sets the pressed type to the button.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_BOOL SetButtonPressed(FR_MessageBar msgBar, FS_LPCSTR lpsName, FS_BOOL bPressed);
	
	//************************************
	// Function:  SetClientData
	// Param[in]: msgBar		The input message bar.
	// Param[in]: lpsName	The button you want to set.
	// Param[in]: clientData	A pointer to user-supplied data to pass to <a>FRExecuteProc</a>(),
	// The data type may be a class or a struct that contain each client data to pass to each user-supplied procedure.
	// Return:	  <a>TRUE</a> means success, otherwise failure.
	// Remarks: Sets the user-supplied data for each  user-supplied procedure.	  	
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_BOOL SetClientData(FR_MessageBar msgBar, FS_LPCSTR lpsName, void* clientData);

	//************************************
	// Function:  AddButtonImage
	// Param[in]: msgBar		The input message bar.
	// Param[in]: pBtnBitmap	Adds a bitmap to the button image list.
	// Return:	  The bitmap index in the button image list.
	// Remarks: Adds a bitmap to the button image list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_INT32 AddButtonImage(FR_MessageBar msgBar, FS_DIBitmap pBtnBitmap);

	//************************************
	// Function:  GetButtonImage
	// Param[in]: msgBar		The input message bar.
	// Param[in]: lpsName		The input specified button name.
	// Return:	  The bitmap index in the button image list.
	// Remarks: Gets the image index.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_INT32 GetButtonImage(FR_MessageBar msgBar, FS_LPCSTR lpsName);

	//************************************
	// Function:  ChangeButton
	// Param[in]: msgBar		The input message bar.
	// Param[in]: lpsName		The input specified button name.
	// Param[in]: lpwsText		The text you want to change to.
	// Param[in]: nImageIndex	The image index you want to change to.
	// Return:	  void.
	// Remarks: Changes the button information.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static void ChangeButton(FR_MessageBar msgBar, FS_LPCSTR lpsName, FS_LPCWSTR lpwsText, FS_INT32 nImageIndex);

	//************************************
	// Function:  IsButtonEnable
	// Param[in]: msgBar		The input message bar.
	// Param[in]: lpsName	The input specified button name.
	// Return:	   <a>TRUE</a> means button is enable , otherwise not.
	// Remarks: Whether the button is enable or not.
	// Notes: Using FRMessageBarEnableButon() to set it.
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_BOOL IsButtonEnable(FR_MessageBar msgBar, FS_LPCSTR lpsName);

	//************************************
	// Function:  CountVisibleMessageBars
	// Return: The count of visible message bars.
	// Remarks: Gets the count of visible message bars.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_INT32 CountVisibleMessageBars();

	//************************************
	// Function:  GetVisibleMessageBar
	// Param[in]: nIndex	Specifies the index of the visible message bars.
	// Return: The specified visible message bar.
	// Remarks: Gets the specified visible message bar by index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static	FR_MessageBar GetVisibleMessageBar(FS_INT32 nIndex);


	//************************************
	// Function:  SetBitmap2
	// Param[in]: msgBar			The input message bar.
	// Param[in]: bitmap			The input bitmap to be set to the message bar.
	// Param[in]: bStretch			Whether to stretch the bitmap or not.
	// Param[in]: bmpAlignment		The input bitmap alignment type.
	// Param[in]: bNeedLayout		Whether to lay out the message bar when setting bitmap.
	// Param[in]: cx				The width of the bitmap when the DPI is 100%. The default value is -1.
	// Param[in]: cy				The height of the bitmap when the DPI is 100%. The default value is -1.
	// Return: void
	// Remarks: Sets bitmap to the message bar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static void SetBitmap2(FR_MessageBar msgBar, FS_DIBitmap bitmap, FS_BOOL bStretch, FRMessageBarElementAlignment bmpAlignment, FS_BOOL bNeedLayout, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  AddButton2
	// Param[in]: msgBar			The input message bar.
	// Param[in]: lpsName			The input name of the button.
	// Param[in]: lpwsText			The input text displayed on the button.
	// Param[in]: btnBitmap			The input bitmap showed on the button.
	// Param[in]: bHasDropDownArrow	Whether the button has the dropped down arrow or not.
	// Param[in]: bNeedLayout		Whether the button need to be laid out.
	// Param[in]: cx				The width of the bitmap when the DPI is 100%. The default value is -1.
	// Param[in]: cy				The height of the bitmap when the DPI is 100%. The default value is -1.
	// Return: void
	// Remarks: Adds a new button to the message bar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static void AddButton2(FR_MessageBar msgBar, FS_LPCSTR lpsName, FS_LPCWSTR lpwsText, FS_DIBitmap btnBitmap, FS_BOOL bHasDropDownArrow, FS_BOOL bNeedLayout, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  AddButtonImage2
	// Param[in]: msgBar		The input message bar.
	// Param[in]: pBtnBitmap	Adds a bitmap to the button image list.
	// Param[in]: cx			The width of the bitmap when the DPI is 100%. The default value is -1.
	// Param[in]: cy			The height of the bitmap when the DPI is 100%. The default value is -1.
	// Return:	  The bitmap index in the button image list.
	// Remarks: Adds a bitmap to the button image list.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use CFR_BulbMsgCenter  and relevant functions instead.
	//************************************
	static FS_INT32 AddButtonImage2(FR_MessageBar msgBar, FS_DIBitmap pBtnBitmap, FS_INT32 cx, FS_INT32 cy);
};

class CFR_TabBand_V4
{
public:
	//************************************
	// Function:  Get
    // Return: The tab band object.
    // Remarks: Gets the tab band object. The tab band is used to place and manage the document tabs. A tab is associated with a window.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FR_TabBand Get();

	//************************************
	// Function:  GetTabWnd
    // Param[in]: tabBand	The input tab band object.
    // Param[in]: iTab		The specified index of the document tabs witch you want get.
    // Return: The window handle associated with the document tab.
    // Remarks: Gets the window handle associated with the document tab.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRTabBandGetActiveTabWnd
	//************************************
	static FS_HWND GetTabWnd(FR_TabBand tabBand, FS_INT32 iTab);

	//************************************
	// Function:  GetActiveTabWnd
    // Param[in]: tabBand	The input tab band object.
    // Return: The window handle associated with the active document tab.
    // Remarks: Gets the window handle associated with the active document tab.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
    static FS_HWND GetActiveTabWnd(FR_TabBand tabBand);

	//************************************
	// Function:  GetTabsNum
    // Param[in]: tabBand	The input tab band object.
    // Return: The numbers of the document tabs.
    // Remarks: Gets the numbers of the document tabs.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetTabsNum(FR_TabBand tabBand);

	//************************************
	// Function:  CloseTabWnd
    // Param[in]: tabBand	The input tab band object.
    // Param[in]: hTabWnd	The specified window handle.
	// Return: void
	// Remarks: Closes the specified tab window.
    // Notes: You can get the window handle in <a>FRTabBandGetTabWnd</a> or <a>FRTabBandGetActiveTabWnd</a>
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:FRTabBandGetTabWnd
    // See:FRTabBandGetActiveTabWnd
	//************************************
    static void CloseTabWnd(FR_TabBand tabBand, FS_HWND hTabWnd);

	//************************************
	// Function:  GetActiveTab
    // Param[in]: tabBand	The input tab band object.
	// Return: The index of the active tab window.
	// Remarks: Gets the index of the active tab window.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetActiveTab(FR_TabBand tabBand);

	//************************************
	// Function:  SetActiveTab
    // Param[in]: tabBand	The input tab band object.
	// Param[in]: hTabWnd	The specified tab window.
	// Return: <a>TRUE</a> if success, otherwise failure.
	// Remarks: Sets the active tab window.
    // Notes: You can get the window handle in <a>FRTabBandGetTabWnd</a>
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See: FRTabBandGetTabWnd
	//************************************
    static FS_BOOL SetActiveTab(FR_TabBand tabBand, FS_HWND hTabWnd);

	//************************************
	// Function:  RegisterAddBtnHandler
	// Param[in]: callbacks	The input callbacks for adding button to the tab band.
	// Return: <a>TRUE</a> if success, otherwise failure.
	// Remarks: Registers the callbacks for adding button to the tab band.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	//************************************
	static FS_BOOL RegisterAddBtnHandler(FR_TabBandAddBtnCallbacks callbacks);

	//************************************
	// Function:  SetTabTitle
	// Param[in]: hChildHwnd	The input child frame window associated with the tab.
	// Param[in]: lpwsTitle		The input title.
	// Return: <a>TRUE</a> if success, otherwise failure.
	// Remarks: Sets the specified tab title.
	// Notes: It can't set title of startpage.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	//************************************
    static FS_BOOL SetTabTitle(FS_HWND hChildHwnd, FS_LPCWSTR lpwsTitle);

	//************************************
	// Function:  SetTabIcon
	// Param[in]: hChildFrame	The input child frame window associated with the tab.
	// Param[in]: hIcon			The input icon set to the tab.
	// Return: void.
	// Remarks: Sets the specified tab icon.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	//************************************
	static void SetTabIcon(FS_HWND hChildFrame, FS_ICON hIcon);

	//************************************
	// Function:  Get2
	// Param[in]: hParent	The input mainframe window associated with the tab.
	// Return: The tab band.	
	// Remarks: Gets the tab band. The tab band is used to place and manage the document tabs. A tab is associated with a window.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FR_TabBand Get2(FS_HWND hParent);
};

class CFR_RibbonBar_V5
{
public:
	//************************************
	// Function:  AddCategory
	// Param[in]: ribbonBar	The input ribbon bar.
	// Param[in]: name		The input name of the category.
	// Param[in]: lpwsTitle The input title of the category.
	// Return: The category added to the ribbon bar.	
	// Remarks:	Adds a new category to the ribbon bar. A category object can be used to manage the operation categories.
	// For example, all the commenting tools are included in the COMMENT category.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppGetRibbonBar
	//************************************
    static FR_RibbonCategory AddCategory(FR_RibbonBar ribbonBar, const FS_CHAR* name, FS_LPCWSTR lpwsTitle);

	//************************************
	// Function:  AddRibbonContextCategory
	// Param[in]: ribbonBar			The input ribbon bar.
	// Param[in]: uiContextID		The context category ID.
	// Param[in]: categoryName		The name of the category.
	// Param[in]: lpwsCategoryTitle	The title of the category.
	// Param[in]: lpwsContextTitle	The title of the context category.
	// Param[in]: lpwsShorcutKey	The shortcut key of the context category.
	// Return: The context category added to the ribbon bar.
	// Remarks: Adds a new context category to the ribbon bar.
	// Notes: The function can only be used for Windows
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonBarAddCategory
	// See: FRRibbonBarActivateContextCategory
	// Deprecated: Internal use.
	//************************************
	static FR_RibbonCategory AddRibbonContextCategory(FR_RibbonBar ribbonBar, unsigned int uiContextID, const FS_CHAR* categoryName, FS_LPCWSTR lpwsCategoryTitle, FS_LPCWSTR lpwsContextTitle, FS_LPCWSTR lpwsShorcutKey);


	//************************************
	// Function:  ActivateContextCategory
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: uiContextID	The specified ID of context category.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Activates the specified context category.
	// Notes: The function can only be used for Windows
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonBarShowContextCategories
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL ActivateContextCategory(FR_RibbonBar ribbonBar, unsigned int uiContextID);


	//************************************
	// Function:  ShowContextCategories
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: uiContextID	The specified ID of context category.
	// Param[in]: bShow			Whether to show or hide the context category.
	// Return: void
	// Remarks: Shows or hides the specified context category.
	// Notes: The function can only be used for Windows
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonBarAddCategory
	// Deprecated: Internal use.
	//************************************
	static void	ShowContextCategories(FR_RibbonBar ribbonBar, unsigned int uiContextID, FS_BOOL bShow);


	//************************************
	// Function:  GetCategoryCount
    // Param[in]: ribbonBar     The input ribbon bar.
	// Return: The count of categories.
	// Remarks: Gets the count of categories.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetCategoryCount(FR_RibbonBar ribbonBar);

	//************************************
	// Function:  GetCategoryByIndex
    // Param[in]: ribbonBar     The input ribbon bar.
    // Param[in]: nIndex        The specified index.
	// Return: The specified ribbon category object.
	// Remarks: Gets the specified ribbon category object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonCategory GetCategoryByIndex(FR_RibbonBar ribbonBar, FS_INT32 nIndex);

	//************************************
	// Function:  GetCategoryByName
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: categoryName	The specified name of the the category.
	// Return: The specified ribbon category object.
	// Remarks: Gets the specified ribbon category object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
    static FR_RibbonCategory GetCategoryByName(FR_RibbonBar ribbonBar, const FS_CHAR* categoryName);

	
	//************************************
	// Function:  AddAsQAT
	// Param[in]: ribbonBar	The input ribbon bar.
	// Param[in]: uiBtnID	The specified ID of ribbon button.
	// Param[in]: bVisible	Whether the ribbon button on the quick access toolbar is visible or not.
	// Return: void
	// Remarks: Adds the specified ribbon button to the quick access toolbar. The quick access toolbar is located at the left-top corner.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void AddAsQAT(FR_RibbonBar ribbonBar, unsigned int uiBtnID, BOOL bVisible);


	//************************************
	// Function:  AddToTabs
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: nElementType	The input type of the ribbon button.
	// Param[in]: name			The input name of the ribbon button.
	// Param[in]: lpwsTitle		The input title of the ribbon button.
	// Param[in]: nPos			The input position of the ribbon button.
	// Return: A new ribbon button.
	// Remarks: Adds a new ribbon button. The ribbon button will be added to the right-top corner of the ribbon bar.
	// Notes: The function can only be used for Windows. It support FR_RIBBON_SEPARATOR,FR_RIBBON_BUTTON,FR_RIBBON_EDIT,FR_RIBBON_COMBOBOX,FR_RIBBON_FONTCOMBOBOX,FR_RIBBON_COLORBUTTON.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void* AddToTabs(FR_RibbonBar ribbonBar, FR_Ribbon_Element_Type nElementType, const FS_CHAR* name, FS_LPCWSTR lpwsTitle, FS_INT32 nPos);


	//************************************
	// Function:  AddHidden
	// Param[in]: ribbonBar	The input ribbon bar.
	// Param[in]: name		The input name of the ribbon button.
	// Param[in]: lpwsTitle	The input title of the ribbon button.
	// Return: The new ribbon button.
	// Remarks: Adds a hidden ribbon button. It can be added to QAT by <a>FRRibbonBarAddAsQAT</a>.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonButton AddHidden(FR_RibbonBar ribbonBar, const FS_CHAR* name, FS_LPCWSTR lpwsTitle);


	//************************************
	// Function:  AddBackStageViewItem
    // Param[in]: ribbonBar     The input ribbon bar.
    // Param[in]: name          The input name of the back stage view item.
    // Param[in]: lpwsTitle     The input title of the back stage view item.
    // Param[in]: nPos          The input position of the back stage view item.
	// Return: The new back stage view item object.
	// Remarks: Adds a new back stage view item under FILE category. The back stage view item is associated with a view.
	// You can add your own dialog or property sheet page on the view.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	//************************************
	static FR_RibbonBackStageViewItem AddBackStageViewItem(FR_RibbonBar ribbonBar, const FS_CHAR* name, FS_LPCWSTR lpwsTitle, FS_INT32 nPos);


	//************************************
	// Function:  GetBackStageViewItem
	// Param[in]: ribbonBar	The input ribbon bar.
	// Param[in]: name		The specified name of back stage view item.
	// Return: The specified back stage view item object.
	// Remarks: Gets the specified back stage view item object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonBarAddBackStageViewItem
	//************************************
	static FR_RibbonBackStageViewItem GetBackStageViewItem(FR_RibbonBar ribbonBar, const FS_CHAR* name);

	
	//************************************
	// Function:  SelectBackStageViewItem
	// Param[in]: ribbonBar	The input ribbon bar.
	// Param[in]: name		The specified name of back stage view item.
	// Return: void
	// Remarks: Selects the specified back stage view item object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonBarAddBackStageViewItem
	// See: FRRibbonBarGetBackStageViewItem
	// See: FRRibbonBarIsBackStageViewActive
	//************************************
	static void SelectBackStageViewItem(FR_RibbonBar ribbonBar, const FS_CHAR* name);


	//************************************
	// Function:  AddButtonToAddPlace
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: name			The name of the button.
	// Param[in]: lpwsTitle		The title of the button.
	// Param[in]: proc			This callback will be called when the user clicks the button.
	// Param[in]: pImage		The input bitmap of the button
	// Param[in]: bToSaveAsItem	Whether the button need to be added to <Italic>Save As</Italic> item under FILE category.
	// Param[in]: pClientData	The user-supplied data.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: There are two back stage view items under FILE category, <Italic>Open</Italic> and <Italic>Save As</Italic>. You can add a
	// place under these two back stage view items. So the user can open file from other places such as the file server.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL AddButtonToAddPlace(FR_RibbonBar ribbonBar, const FS_CHAR* name, FS_LPCWSTR lpwsTitle, FRExecuteProc proc, FS_DIBitmap pImage, FS_BOOL bToSaveAsItem, void* pClientData);


	//************************************
	// Function:  CloseFilePage
	// Param[in]: ribbonBar	The input ribbon bar.
	// Return: void
	// Remarks: Closes the page that is shown by clicking the FILE category.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void CloseFilePage(FR_RibbonBar ribbonBar);


	//************************************
	// Function:  FindElementByName
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: categoryName	The specified name of the category.
	// Param[in]: panelName		The specified name of the panel.
	// Param[in]: btnName		The specified name of the element.
	// Return: The specified element.
	// Remarks: Gets the specified element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement	FindElementByName(FR_RibbonBar ribbonBar, const FS_CHAR* categoryName, const FS_CHAR* panelName, const FS_CHAR* btnName);				


	//************************************
	// Function:  IsBackStageViewActive
	// Param[in]: ribbonBar	The input ribbon bar.
	// Return: <a>TRUE</a> if the back view is active, otherwise not.
	// Remarks: Checks whether the back view is active or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonBarSelectBackStageViewItem
	//************************************
	static FS_BOOL IsBackStageViewActive(FR_RibbonBar ribbonBar);


	//************************************
	// Function:  RecalcLayout
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: bRecalcPanels Whether to recalc the layout of the panels.
	// Return: void
	// Remarks: Whether to recalc the layout of the panels or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void RecalcLayout(FR_RibbonBar ribbonBar, FS_BOOL bRecalcPanels);


	//************************************
	// Function:  GetActiveCategory
	// Param[in]: ribbonBar	The input ribbon bar.
	// Return: The active category object.
	// Remarks: Gets the active category object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonBarAddCategory
	// See: FRRibbonBarSetActiveCategory
	//************************************
	static FR_RibbonCategory GetActiveCategory(FR_RibbonBar ribbonBar);


	//************************************
	// Function:  SetActiveCategory
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: categoryName	The specified name of the category.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Sets the active category.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonBarAddCategory
	// See: FRRibbonBarGetActiveCategory
	// See: FRRibbonBarSetActiveCategory2
	//************************************
	static FS_BOOL SetActiveCategory(FR_RibbonBar ribbonBar, const FS_CHAR* categoryName);


	//************************************
	// Function:  SetActiveCategory2
	// Param[in]: ribbonBar			The input ribbon bar.
	// Param[in]: ribbonCategory	The specified category object.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Sets the active category.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonBarSetActiveCategory
	//************************************
	static FS_BOOL SetActiveCategory2(FR_RibbonBar ribbonBar, FR_RibbonCategory ribbonCategory);

	//************************************
	// Function:  IsMinimize
	// Param[in]: ribbonBar			The input ribbon bar.
	// Return: <a>TRUE</a> means the ribbon bar is minimized, otherwise not.
	// Remarks: Checks whether the ribbon bar is minimized or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: 
	//************************************
	static FS_BOOL IsMinimize(FR_RibbonBar ribbonBar);

	//************************************
	// Function:  AddCaptionButton
	// Param[in]: ribbonBar			The input ribbon bar.
	// Param[in]: name				The input name of the button.
	// Param[in]: lpwsTitle			The input title of the button.
	// Param[in]: nIndex			The input position of the button. Sets it -1 as default.
	// Return: The ribbon button added to the caption bar on the right.
	// Remarks: Adds a ribbon button to the caption bar on the right.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FR_RibbonButton AddCaptionButton(FR_RibbonBar ribbonBar, const FS_CHAR* name, FS_LPCWSTR lpwsTitle, FS_INT32 nIndex);

	//************************************
	// Function:  RegisterFilePageEventHandler
	// Param[in]: callbacks	The input callbacks for ribbon file page event handler.
	// Return:	The pointer to ribbon file page event handler can be destroyed by <a>FRRibbonBarDestroyFilePageEventHandler</a>.
	// Remarks: Registers a callbacks set for ribbon file page event handler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: FRRibbonBarDestroyFilePageEventHandler
	// Deprecated: Internal use.
	//************************************
	static void* RegisterFilePageEventHandler(FR_RibbonFilePageEventCallbacks callbacks);

	//************************************
	// Function:  DestroyFilePageEventHandler
	// Param[in]: eventHandler	The pointer to ribbon file page event handler returned by <a>FRRibbonBarRegisterFilePageEventHandler</a>.
	// Return:	void.
	// Remarks: Destroys the ribbon file page event handler returned by <a>FRRibbonBarRegisterFilePageEventHandler</a>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: FRRibbonBarRegisterFilePageEventHandler
	// Deprecated: Internal use.
	//************************************
	static void DestroyFilePageEventHandler(void* eventHandler);

	//************************************
	// Function:  AddCategory2
	// Param[in]: ribbonBar	The input ribbon bar.
	// Param[in]: name		The input name of the category.
	// Param[in]: lpwsTitle The input title of the category.
	// Param[in]: nPos		The position of the category in the ribbon bar.
	// Return: The category added to the ribbon bar.	
	// Remarks:	Adds a new category to the ribbon bar. A category object can be used to manage the operation categories.
	// For example, all the commenting tools are included in the COMMENT category.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRAppGetRibbonBar
	//************************************
	static FR_RibbonCategory AddCategory2(FR_RibbonBar ribbonBar, const FS_CHAR* name, FS_LPCWSTR lpwsTitle, FS_INT32 nPos);

	//************************************
	// Function:  ShowButtonInAddPlace
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: name			The name of the button.
	// Param[in]: bShow		T	Whether to show the button or not.
	// Param[in]: bToSaveAsItem	Whether the button is under <Italic>Save As</Italic> item under FILE category.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: There are two back stage view items under FILE category, <Italic>Open</Italic> and <Italic>Save As</Italic>. You can add a
	// place under these two back stage view items. So the user can open file from other places such as the file server. You can show or hide
	// the buttons in the Add-a-Place.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1
	// See: FRRibbonBarAddButtonToAddPlace
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL ShowButtonInAddPlace(FR_RibbonBar ribbonBar, const FS_CHAR* name, FS_BOOL bShow, FS_BOOL bToSaveAsItem);

	//************************************
	// Function:  UpdateCmdUI
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: name			The name of the button.
	// Return: void.
	// Remarks: Updates the UI state of ribbon button.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	// Deprecated: Internal use.
	//************************************
	static void UpdateCmdUI(FR_RibbonBar ribbonBar, const FS_CHAR* name);


	//************************************
	// Function:  AddButtonToAddPlace2
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: name			The name of the button.
	// Param[in]: lpwsTitle		The title of the button.
	// Param[in]: proc			This callback will be called when the user clicks the button.
	// Param[in]: wsPDFBitmapName	The input bitmap name. For loading PDF images, the name is retrieved from the BOOKMARK of the PDF file：FoxitReader\res\ribbon\ribbonimage.pdf.
	// Param[in]: bToSaveAsItem  Whether the button need to be added to <Italic>Save As</Italic> item under FILE category.
	//                           FALSE will add to Open item under FILE category,TRUE will add to Save As item under FILE category.
	// Param[in]: pClientData	The user-supplied data.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: There are two back stage view items under FILE category, <Italic>Open</Italic> and <Italic>Save As</Italic>. You can add a
	// place under these two back stage view items. So the user can open file from other places such as the file server.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL AddButtonToAddPlace2(FR_RibbonBar ribbonBar, const FS_CHAR* name, FS_LPCWSTR lpwsTitle, FRExecuteProc proc, FS_LPCWSTR wsPDFBitmapName, FS_BOOL bToSaveAsItem, void* pClientData);

	//************************************
	// Function:  AddToTabs2
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: info     	    The input FR_RIBBONBUTTONINFO.
	// Param[in]: nWidth		The input width. Just for RIBBON_EDIT, RIBBON_FONTCOMBOBOX and RIBBON_COMBOBOX.
	// Param[in]: nPos			The input position of the ribbon button.
	// Return: A new ribbon button.
	// Remarks: Adds a new ribbon button. The ribbon button will be added to the right-top corner of the ribbon bar.
	// Notes: The function can only be used for Windows. It support FR_RIBBON_SEPARATOR,FR_RIBBON_BUTTON,FR_RIBBON_EDIT,FR_RIBBON_COMBOBOX,FR_RIBBON_FONTCOMBOBOX,FR_RIBBON_COLORBUTTON.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void* AddToTabs2(FR_RibbonBar ribbonBar, FR_RIBBONBUTTONINFO ribbonInfo, FS_INT32 nWidth, FS_INT32 nPos);

	//************************************
	// Function:  FindHiddenFloaty
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: csBtnName		The name of the button.
	// Return: FR_RibbonButton.
	// Remarks: Find the button in hidden floaty.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// Deprecated: Internal use.
	//************************************
	static FR_RibbonButton FindHiddenFloaty(FR_RibbonBar ribbonBar, FS_LPCSTR csBtnName);

	//************************************
	// Function:  AddOnlyForAccelButton
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: ribbonInfo	The input ribbon info.
	// Param[in]: csAccelCategoryName	The input category name.
	// Param[in]: bAddToAccelDlg	Whether need add to accel dialog.
	// Return: FR_RibbonButton.
	// Remarks: Add button only for accelerate.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// Deprecated: Internal use.
	//************************************
	static FR_RibbonButton	AddOnlyForAccelButton(FR_RibbonBar ribbonBar, FR_RIBBONBUTTONINFO ribbonInfo, const FS_LPCWSTR csAccelCategoryName, FS_BOOL bAddToAccelDlg);

	//************************************
	// Function:  AddHidden2
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: ribbonInfo	The input ribbon info.
	// Return: FR_RibbonButton.
	// Remarks: Add ribbon button.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// Deprecated: Internal use.
	//************************************
	static FR_RibbonButton  AddHidden2(FR_RibbonBar ribbonBar, FR_RIBBONBUTTONINFO ribbonInfo);

	//************************************
	// Function:  AddToTabRight
	// Param[in]: ribbonBar		The input ribbon bar.
	// Param[in]: ribbonInfo	The input ribbon info.
	// Param[in]: nPos	        The input button position.
	// Return: FS_LPVOID   It can convert to a specific ribbon by nRibbonType of ribbonInfo.
	//                     Like if nRibbonType is FR_RIBBON_BUTTON, it can convert to FR_RibbonButton.
	// Remarks: Add ribbon button to the right of category.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2	
	//************************************
	static FS_LPVOID  AddToTabRight(FR_RibbonBar ribbonBar, FR_RIBBONBUTTONINFO ribbonInfo, FS_INT32 nPos);
};

class CFR_RibbonCategory_V5
{
public:
	//************************************
	// Function:  SetTitle
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: lpwsTitle			The input title of the ribbon category.
	// Return: void
	// Remarks: Sets the title of the ribbon category.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonBarAddCategory
	//************************************
	static void SetTitle(FR_RibbonCategory ribbonCategory, FS_LPCWSTR lpwsTitle);


	//************************************
	// Function:  GetTitle
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[out]: wsTitle			It receives the title of the ribbon category.
	// Return: void
	// Remarks: Gets the title of the ribbon category.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetTitle(FR_RibbonCategory ribbonCategory, FS_WideString* wsTitle);


	//************************************
	// Function:  SetContextTitle
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: lpwsTitle			The input title of the ribbon context category.
	// Return: void
	// Remarks: Sets the title of the ribbon context category.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:	
	//************************************
	static void SetContextTitle(FR_RibbonCategory ribbonCategory, FS_LPCWSTR lpwsTitle);


	//************************************
	// Function:  GetContextTitle
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[out]: wsTitle			It receives the title of the ribbon context category.
	// Return: void
	// Remarks: Gets the title of the ribbon context category.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:	
	//************************************
	static void GetContextTitle(FR_RibbonCategory ribbonCategory, FS_WideString* wsTitle);


	//************************************
	// Function:  SetKey
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: lpwsShorcutKey	The input shortcut key of the ribbon category.
	// Return: void
	// Remarks: Sets the shortcut key of the ribbon category.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:	
	//************************************
	static void SetKey(FR_RibbonCategory ribbonCategory, FS_LPCWSTR lpwsShorcutKey);


	//************************************
	// Function:  GetKey
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[out]: wsKey			It receives the shortcut key of the ribbon category.
	// Return: void
	// Remarks: Gets the shortcut key of the ribbon category.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:	
	//************************************
	static void GetKey(FR_RibbonCategory ribbonCategory, FS_WideString* wsKey);


	//************************************
	// Function:  SetVisible
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: bVisible			<a>TRUE</a> if the ribbon category is visible, otherwise is invisible.
	// Return: void
	// Remarks: Sets the ribbon category to visible or invisible.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetVisible(FR_RibbonCategory ribbonCategory, FS_BOOL bVisible);


	//************************************
	// Function:  GetVisible
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Return: <a>TRUE</a> if the ribbon category is visible, otherwise invisible.
	// Remarks: Checks whether the ribbon category is visible or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL GetVisible(FR_RibbonCategory ribbonCategory);

	
	//************************************
	// Function:  AddPanel
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: name				The input name of the ribbon panel.
	// Param[in]: lpwsTitle			The input title of the ribbon panel.
	// Param[in]: defBtnBitmap		The default icon of the ribbon panel.	
	// Return: The new ribbon panel added to the ribbon category.
	// Remarks: Adds a new ribbon panel to the ribbon category. A ribbon category may contain several ribbon panels.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonCategoryGetPanelCount
	// See: FRRibbonCategoryGetPanelByIndex
	//************************************
	static FR_RibbonPanel AddPanel(FR_RibbonCategory ribbonCategory, const FS_CHAR* name, FS_LPCWSTR lpwsTitle, FS_DIBitmap defBtnBitmap);

	//************************************
	// Function:  GetPanelCount
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Return: The count of ribbon panels
	// Remarks: Gets the count of ribbon panels.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetPanelCount(FR_RibbonCategory ribbonCategory);


	//************************************
	// Function:  GetPanelByIndex
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: nIndex			The specified index.
	// Return: The specified ribbon panel.
	// Remarks: Gets the ribbon panel by index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonCategoryGetPanelByName
	//************************************
	static FR_RibbonPanel GetPanelByIndex(FR_RibbonCategory ribbonCategory, FS_INT32 nIndex);


	//************************************
	// Function:  GetPanelByName
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: panelName			The specified name.
	// Return: The specified ribbon panel.
	// Remarks: Gets the ribbon panel by name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonCategoryGetPanelByIndex
	//************************************
	static FR_RibbonPanel GetPanelByName(FR_RibbonCategory ribbonCategory, const FS_CHAR* panelName);


	//************************************
	// Function:  GetName
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[out]: bsName			It receives the name of the ribbon category.
	// Return: void
	// Remarks: Gets the name of the ribbon category.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetName(FR_RibbonCategory ribbonCategory, FS_ByteString* bsName);

	//************************************
	// Function:  ShowInQATCustomizeToolsDlg
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: bShow				It indicates whether the category can be shown in the QAT customize tools dialog.
	// Return: void
	// Remarks: Sets whether the category can be shown in the QAT customize tools dialog.
	// Notes:The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See:
	// Deprecated: Internal use.
	//************************************
	static void ShowInQATCustomizeToolsDlg(FR_RibbonCategory ribbonCategory, FS_BOOL bShow);

	//************************************
	// Function:  CopyPanel
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: ribbonPanel		The specified ribbon panel object to be copied.
	// Return: A copy of the specified ribbon panel object.
	// Remarks: Gets a copy of the specified ribbon panel object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:
	//************************************
	static FR_RibbonPanel CopyPanel(FR_RibbonCategory ribbonCategory, FR_RibbonPanel ribbonPanel);

	//************************************
	// Function:  RecalcLayout
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: bRecalcPanels		Whether to recalc the layout of the panels.
	// Return: void
	// Remarks: Whether to recalc the layout of the panels or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:
	//************************************
	static void RecalcLayout(FR_RibbonCategory ribbonCategory, FS_BOOL bRecalcPanels);

	//************************************
	// Function:  AddPanel2
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: name				The input name of the ribbon panel.
	// Param[in]: lpwsTitle			The input title of the ribbon panel.
	// Param[in]: defBtnBitmap		The default icon of the ribbon panel.	
	// Param[in]: nPos				The position of the ribbon panel.
	// Return: The new ribbon panel added to the ribbon category.
	// Remarks: Adds a new ribbon panel to the ribbon category. A ribbon category may contain several ribbon panels.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
	// See: FRRibbonCategoryGetPanelCount
	// See: FRRibbonCategoryGetPanelByIndex
	// See: FRRibbonCategoryAddPanel
	//************************************
	static FR_RibbonPanel AddPanel2(FR_RibbonCategory ribbonCategory, const FS_CHAR* name, FS_LPCWSTR lpwsTitle, FS_DIBitmap defBtnBitmap, FS_INT32 nPos);

	//************************************
	// Function:  AddDialog
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: createProc	The callback function is called to notify the plug-in to create the dialog attached to the category.
	// Param[in]: destroyProc	The callback function is called to notify the plug-in to destroy the dialog attached to the category.
	// Param[in]: pDialog		The input pointer to a <Italic>MFC CDialog</Italic> attached to the category. It will be passed to the <param>createProc</param> and <param>destroyProc</param>.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: You can create your own dialog under the category. You have to invoke <a>FRRibbonCategoryPreTranslateMessage</a> in the dialog's 
	// <Italic>PreTranslateMessage</Italic> function to dispatch the message.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL AddDialog(FR_RibbonCategory ribbonCategory, FRCategoryDlgCreateProc createProc, FRCategoryDlgDestoryProc destroyProc, void* pDialog);
	
	//************************************
	// Function:  PreTranslateMessage
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: pMsg				Pointer to a <Italic>MFC MSG</Italic> structure that contains the message to process.
	// Return: <a>TRUE</a> if the message was fully processed and should not be processed further. <a>FALSE</a> if the message should be processed in the normal way.
	// Remarks: When you create a dialog under the category, you have to invoke <a>FRRibbonCategoryPreTranslateMessage</a> in the dialog's 
	// <Italic>PreTranslateMessage</Italic> function to dispatch the message.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: FRRibbonCategoryAddDialog
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL PreTranslateMessage(FR_RibbonCategory ribbonCategory, void* pMsg);

	//************************************
	// Function:  AddDialogToRight
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: createProc	The callback function is called to notify the plug-in to create the dialog attached to the category.
	// Param[in]: destroyProc	The callback function is called to notify the plug-in to destroy the dialog attached to the category.
	// Param[in]: pDialog		The input pointer to a <Italic>MFC CDialog</Italic> attached to the category. It will be passed to the <param>createProc</param> and <param>destroyProc</param>.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: You can create your own dialog under the category on the right. You have to invoke <a>FRRibbonCategoryPreTranslateMessage</a> in the dialog's 
	// <Italic>PreTranslateMessage</Italic> function to dispatch the message.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRRibbonCategoryAddDialog
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL AddDialogToRight(FR_RibbonCategory ribbonCategory, FRCategoryDlgCreateProc createProc, FRCategoryDlgDestoryProc destroyProc, void* pDialog);

	//************************************
	// Function:  GetPos
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Return: The position of the ribbon category in the ribbon bar.
	// Remarks: Gets the position of the ribbon category in the ribbon bar.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: 
	//************************************
	static FS_INT32 GetPos(FR_RibbonCategory ribbonCategory);
	
	//************************************
	// Function:  SetPos
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: nPos				The position of the ribbon category in the ribbon bar.
	// Return: void.
	// Remarks: Sets the position of the ribbon category when create in the ribbon bar.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: 
	//************************************
	static void SetPos(FR_RibbonCategory ribbonCategory, FS_INT32 nPos);

	//************************************
	// Function:  SetHighlight
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Param[in]: color				The color when the category is highlight.
	// Param[in]: bOnceOnly			If TRUE, the highlight will disappear when the category is activated.
	// Return: void.
	// Remarks: Sets the category to be highlight. Invokes <a>FRRibbonCategoryRecalcLayout</a> to take it effect.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRRibbonCategoryGetHighlightColor
	// Deprecated: Internal use.
	//************************************
	static void SetHighlight(FR_RibbonCategory ribbonCategory, FS_COLORREF color, FS_BOOL bOnceOnly);
	
	//************************************
	// Function:  GetHighlightColor
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Return: The color when the category is highlight.
	// Remarks: Gets the color when the category is highlight.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See: FRRibbonCategorySetHighlight
	// Deprecated: Internal use.
	//************************************
	static FS_COLORREF GetHighlightColor(FR_RibbonCategory ribbonCategory);

	//************************************
	// Function:  GetTabRect
	// Param[in]: ribbonCategory	The input ribbon category object.
	// Return: FS_Rect    Get the rect range of the category.
	// Remarks: Get the rect range of the category..
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// See: 	
	//************************************
	static FS_Rect GetTabRect(FR_RibbonCategory ribbonCategory);
};

class CFR_RibbonPanel_V5
{
public:

	//************************************
	// Function:  AddElement
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: nElementType	The specified type of the element to be added.
	// Param[in]: name			The specified name of the element to be added.
	// Param[in]: lpwsTitle		The specified title of the element to be added.
	// Param[in]: nPos			The specified position of the element to be added.
	// Return: The new ribbon element. For example, if sets <param>nElementType</param> as <a>FR_RIBBON_BUTTON</a>,
	// the returned value can be converted to <a>FR_RibbonButton</a>.
	// Remarks: Adds a new ribbon element to the ribbon panel
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void* AddElement(FR_RibbonPanel ribbonPanel, FR_Ribbon_Element_Type nElementType, const FS_CHAR* name, FS_LPCWSTR lpwsTitle, FS_INT32 nPos);


	//************************************
	// Function:  ChangeElementType
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: name			The specified name of the ribbon element.
	// Param[in]: nElementType	The specified type you want to change to.
	// Return: The ribbon element with new type.
	// Remarks: Changes the specified element to other types.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void* ChangeElementType(FR_RibbonPanel ribbonPanel, const FS_CHAR* name, FR_Ribbon_Element_Type nElementType);

	
	//************************************
	// Function:  AddElementToGroup
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: groupName		The specified group name.
	// Param[in]: nElementType	The type of ribbon element added to the group.
	// Param[in]: elementName	The input name of the ribbon element.
	// Param[in]: lpwsTitle		The input title of the ribbon element.
	// Return: The new ribbon element added to the specified group. For example, if sets <param>elementName</param> as <a>FR_RIBBON_BUTTON</a>,
	// the returned value can be converted to <a>FR_RibbonButton</a>. The element belongs to the group will not display the title.
	// Remarks: Adds a new ribbon element to the  specified group.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void* AddElementToGroup(FR_RibbonPanel ribbonPanel, const FS_CHAR* groupName, FR_Ribbon_Element_Type nElementType, const FS_CHAR* elementName, FS_LPCWSTR lpwsTitle);

	
	//************************************
	// Function:  SetLaunchButton
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: name			The input name of the launch button.
	// Param[in]: lpwsTitle		The input title of the launch button.
	// Return: The launch button.
	// Remarks: Sets the launch button.
	// Notes: This interface is reserved. The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FR_RibbonButton SetLaunchButton(FR_RibbonPanel ribbonPanel, const FS_CHAR* name, FS_LPCWSTR lpwsTitle);

	
	//************************************
	// Function:  CopyElementToPanel
	// Param[in]: ribbonPanel		The input ribbon panel object.
	// Param[in]: pSrcRibbonElement	The existing ribbon element.
	// Return: The corresponding ribbon button. For example, if the type is <a>FR_RIBBON_BUTTON</a>,
	// the returned value can be converted to <a>FR_RibbonButton</a>.
	// Remarks: Copies an existing ribbon element to the panel.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void* CopyElementToPanel(FR_RibbonPanel ribbonPanel, FR_RibbonElement pSrcRibbonElement);


	//************************************
	// Function:  SetTitle
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: lpwsTitle		The input title of the ribbon panel.
	// Return: void
	// Remarks: Sets the title of the ribbon panel.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetTitle(FR_RibbonPanel ribbonPanel, FS_LPCWSTR lpwsTitle);

	//************************************
	// Function:  GetTitle
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[out]: wsTitle		It receives the title of the ribbon panel.
	// Return: void
	// Remarks: Gets the title of the ribbon panel.
    // Notes:·
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetTitle(FR_RibbonPanel ribbonPanel, FS_WideString* wsTitle);

    //************************************
    // Function:  SetVisible
    // Param[in]: ribbonPanel	The input ribbon panel object.
    // Param[in]: bVisible		<a>TRUE</a> if sets the ribbon panel to visible.
    // Return: void
    // Remarks: Sets the ribbon panel to visible or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static void SetVisible(FR_RibbonPanel ribbonPanel, FS_BOOL bVisible);

    //************************************
    // Function:  GetVisible
    // Param[in]: ribbonPanel	The input ribbon panel object.
    // Return: <a>TRUE</a> if the ribbon panel is visible, otherwise <a>FALSE</a>.
    // Remarks: CHecks whether the ribbon panel is visible or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static FS_BOOL GetVisible(FR_RibbonPanel ribbonPanel);

    //************************************
	// Function:  GetElementByName
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: elementName	The specified name of the ribbon element.
	// Return: The specified ribbon element.
	// Remarks: Gets the The specified ribbon element by name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElementByName(FR_RibbonPanel ribbonPanel, const FS_CHAR* elementName);


	//************************************
    // Function:  GetElementCount
    // Param[in]: ribbonPanel	The input ribbon panel object.
    // Return: The count of the ribbon element.
    // Remarks: Get the count of the ribbon element.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static FS_INT32 GetElementCount(FR_RibbonPanel ribbonPanel);

	
	//************************************
	// Function:  GetElementByIndex
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: nIndex		The specified index.
	// Return: The specified ribbon element.
	// Remarks: Gets the the specified ribbon element by index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElementByIndex(FR_RibbonPanel ribbonPanel, FS_INT32 nIndex);


	//************************************
	// Function:  SetPanelImage
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: pSmallBitmap	The input bitmap when the ribbon panel is narrowed.
	// Return: void
	// Remarks: Sets the bitmap when the ribbon panel is narrowed.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetPanelImage(FR_RibbonPanel ribbonPanel, FS_DIBitmap pSmallBitmap);

	//************************************
	// Function:  GetName
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[out]: bsName		It receives the name of the ribbon panel.
	// Return: void
	// Remarks: Gets the name of the ribbon panel.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
    static void	GetName(FR_RibbonPanel ribbonPanel, FS_ByteString* bsName);

    //************************************
	// Function:  ShowInQATCustomizeToolsDlg
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: bShow			It indicates whether the panel can be shown in the QAT customize tools dialog.
	// Return: void
	// Remarks: Sets whether the panel can be shown in the QAT customize tools dialog.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See:
	// Deprecated: Internal use.
	//************************************
	static void ShowInQATCustomizeToolsDlg(FR_RibbonPanel ribbonPanel, FS_BOOL bShow);

	//************************************
	// Function:  SetImageInitProc
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: proc			The callback invoked by Foxit Reader to init the visible image.
	// Return: void
	// Remarks: Sets the callback invoked by Foxit Reader to init the visible image.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetImageInitProc(FR_RibbonPanel ribbonPanel, FRRibbonPanelImageInitProc proc);

	//************************************
	// Function:  SetKey
	// Param[in]: ribbonPanel		The input ribbon panel object.
	// Param[in]: lpwsShorcutKey	The input shortcut key.
	// Return: void
	// Remarks: Sets the shortcut key of the ribbon panel
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetKey(FR_RibbonPanel ribbonPanel, FS_LPCWSTR lpwsShorcutKey);

	//************************************
	// Function:  AddDialog
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: createProc	The callback function is called to notify the plug-in to create the dialog attached to the panel.
	// Param[in]: destroyProc	The callback function is called to notify the plug-in to destroy the dialog attached to the panel.
	// Param[in]: pDialog		The input pointer to a <Italic>MFC CDialog</Italic> attached to the panel. It will be passed to the <param>createProc</param> and <param>destroyProc</param>.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: You can create your own dialog under the panel. You have to invoke <a>FRRibbonPanelPreTranslateMessage</a> in the dialog's 
	// <Italic>PreTranslateMessage</Italic> function to dispatch the message.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL AddDialog(FR_RibbonPanel ribbonPanel, FRPanelDlgCreateProc createProc, FRPanelDlgDestoryProc destroyProc, void* pDialog);
	
	//************************************
	// Function:  PreTranslateMessage
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: pMsg				Pointer to a <Italic>MFC MSG</Italic> structure that contains the message to process.
	// Return: <a>TRUE</a> if the message was fully processed and should not be processed further. <a>FALSE</a> if the message should be processed in the normal way.
	// Remarks: When you create a dialog under the panel, you have to invoke <a>FRRibbonPanelPreTranslateMessage</a> in the dialog's 
	// <Italic>PreTranslateMessage</Italic> function to dispatch the message.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See: FRRibbonPanelAddDialog
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL PreTranslateMessage(FR_RibbonPanel ribbonPanel, void* pMsg);

	//************************************
	// Function:  EnableAddToCustomizeDlg
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: bEnable		Whether the panel can be added to the custom setting dialog or not.
	// Return: void
	// Remarks: Sets whether the panel can be added to the custom setting dialog or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// Deprecated: Internal use.
	//************************************
	static void EnableAddToCustomizeDlg(FR_RibbonPanel ribbonPanel, FS_BOOL bEnable);
	
	//************************************
	// Function:  SetShowDefaultButtonAtLast
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: bLast			Whether the panel will show the default button at last or not.
	// Return: void
	// Remarks: Sets whether the panel will show the default button at last or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// Deprecated: Internal use.
	//************************************
	static void SetShowDefaultButtonAtLast(FR_RibbonPanel ribbonPanel, FS_BOOL bLast);

	//************************************
	// Function:  CopyElementToPanel
	// Param[in]: ribbonPanel		The input ribbon panel object.
	// Param[in]: pSrcRibbonElement	The existing ribbon element.
	// Param[in]: nPos	The position of the panel.
	// Param[in]: bEnableGroupStyle	If enable the group style.
	// Return: The corresponding ribbon button. For example, if the type is <a>FR_RIBBON_BUTTON</a>,
	// the returned value can be converted to <a>FR_RibbonButton</a>.
	// Remarks: Copies an existing ribbon element to the panel.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void* CopyElementToPanel2(FR_RibbonPanel ribbonPanel, FR_RibbonElement pSrcRibbonElement, FS_INT32 nPos, FS_BOOL bEnableGroupStyle);

	//************************************
    // Function:  AddControl
    // Param[in]: ribbonPanel	The input ribbon panel object.
    // Param[in]: nControlType	The specified type of the control to be added.
    // Param[in]: controlName   The specified name of the control to be added.
    // Param[in]: lpwsTitle		The specified title of the control to be added.
    // Return: The new ribbon control
    // Remarks: Adds a new ribbon control to the ribbon panel
	// Notes: The function can  be used for Windows & MacOS
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FR_CommonControl AddControl(FR_RibbonPanel ribbonPanel, FR_Common_Control_Type nControlType, const FS_CHAR* controlName, FS_LPCWSTR lpwsTitle);

    //************************************
    // Function:  GetControlByName
    // Param[in]: ribbonPanel	The input ribbon panel object.
    // Param[in]: controlName	The specified name of the ribbon control.
    // Return: The specified ribbon control.
    // Remarks: Gets the The specified ribbon control by name.
	// Notes: The function can  be used for Windows & MacOS
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FR_CommonControl GetControlByName(FR_RibbonPanel ribbonPanel, const FS_CHAR* controlName);

    //************************************
    // Function:  GetControlByIndex
    // Param[in]: ribbonPanel	The input ribbon panel object.
    // Param[in]: nIndex		The specified index.
    // Return: The specified ribbon control.
    // Remarks: Gets the the specified ribbon control by index.
	// Notes: The function can  be used for Windows & MacOS
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FR_CommonControl GetControlByIndex(FR_RibbonPanel ribbonPanel, FS_INT32 nIndex);

	//************************************
	// Function:  AddElement2
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: ribbonInfo	The input ribbon button info.
	// Param[in]: nPos			The specified position of the element to be added.
	// Return: The new ribbon element. For example, if sets <param>nElementType</param> as <a>FR_RIBBON_BUTTON</a>,
	// the returned value can be converted to <a>FR_RibbonButton</a>.
	// Remarks: Adds a new ribbon element to the ribbon panel
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_LPVOID AddElement2(FR_RibbonPanel ribbonPanel, FR_RIBBONBUTTONINFO ribbonInfo, FS_INT32 nPos);

	//************************************
	// Function:  AddElementToGroup2
	// Param[in]: ribbonPanel	The input ribbon panel object.
	// Param[in]: groupName		The specified group name.
	// Param[in]: nElementType	The type of ribbon element added to the group.
	// Param[in]: elementName	The input name of the ribbon element.
	// Param[in]: lpwsTitle		The input title of the ribbon element.
	// Param[in]: nPos		    The input position need to add.
	// Return: The new ribbon element added to the specified group. For example, if sets <param>elementName</param> as <a>FR_RIBBON_BUTTON</a>,
	// the returned value can be converted to <a>FR_RibbonButton</a>. The element belongs to the group will not display the title.
	// Remarks: Adds a new ribbon element to the  specified group.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void* AddElementToGroup2(FR_RibbonPanel ribbonPanel, const FS_CHAR* groupName, FR_Ribbon_Element_Type nElementType, const FS_CHAR* elementName, FS_LPCWSTR lpwsTitle, FS_INT32 nPos);

	//************************************
	// Function:  SetPDFImageParentName
	// Param[in]: ribbonPanel	    The input ribbon panel object.
	// Param[in]: bsPDFPathName		The input PDF name.	
	// Return: 
	// Remarks: Adds a new ribbon element to the  specified group.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetPDFImageParentName(FR_RibbonPanel ribbonPanel, FS_LPCSTR bsPDFPathName);
};

class CFR_RibbonElement_V5
{
public:
	//************************************
	// Function:  AddSubItem
	// Param[in]: ribbonElement	The input ribbon element object,it get from FRRibbonPanelAddElement.
	// Param[in]: nElementType	The input type of ribbon element.
	// Param[in]: name			The input name of ribbon element.
	// Param[in]: lpwsTitle		The input title of ribbon element.
	// Param[in]: nPos			The input position of ribbon element.
	// Param[in]: bOnTop		Whether the added sub item is on the top or not.
	// Param[in]: bChangeFun	When the user clicks the sub item, whether the parent's function should be change to the sub item's. Sets it FALSE as default.
	// Param[in]: bChangeImage	When the user clicks the sub item, whether the parent's icon should be change to the sub item's. Sets it FALSE as default.
	// Return: The new sub item of the ribbon element. For example, if sets <param>nElementType</param> as <a>FR_RIBBON_BUTTON</a>,
	// the returned value can be converted to <a>FR_RibbonButton</a>.
	// Remarks: Add a new sub item to the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonPanelAddElement
	//************************************
	static void* AddSubItem(FR_RibbonElement ribbonElement, FR_Ribbon_Element_Type nElementType, const FS_CHAR* name, FS_LPCWSTR lpwsTitle, FS_INT32 nPos, FS_BOOL bOnTop, FS_BOOL bChangeFun, FS_BOOL bChangeImage);

	
	//************************************
	// Function:  SetExecuteProc
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: proc			Set the new execute proc, it will be called when the user clicks the ribbon element.
	// Return: FRExecuteProc    Return the current execute proc before set the new proc.
	// Remarks: Sets the callback function that will be called when the user clicks the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FRExecuteProc SetExecuteProc(FR_RibbonElement ribbonElement, FRExecuteProc proc);

	
	//************************************
	// Function:  SetComputeEnabledProc
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: proc			The callback will be called to determine whether the ribbon element is enabled or not.
	// Return: void
	// Remarks: Sets the callback function that will be called to determine whether the ribbon element is enabled or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetComputeEnabledProc(FR_RibbonElement ribbonElement, FRComputeEnabledProc proc);

	
	//************************************
	// Function:  SetComputeMarkedProc
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: proc			The callback will be called to determine whether the ribbon element is marked or not.
	// Return: void
	// Remarks: Sets the callback function that will be called to determine whether the ribbon element is marked or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetComputeMarkedProc(FR_RibbonElement ribbonElement, FRComputeMarkedProc proc);


	//************************************
	// Function:  DoExecuteProc
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: void
	// Remarks: Executes the <a>FRExecuteProc</a>() associated with the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void DoExecuteProc(FR_RibbonElement ribbonElement);

	
	//************************************
	// Function:  IsEnabled
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: <a>TRUE</a> if the ribbon element is enabled, otherwise <a>FALSE</a>.
	// Remarks: Checks whether the ribbon element is enabled or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL IsEnabled(FR_RibbonElement ribbonElement);

	
	//************************************
	// Function:  IsMarked
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: <a>TRUE</a> if the ribbon element is marked, otherwise <a>FALSE</a>.
	// Remarks: Checks whether the ribbon element is marked or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL IsMarked(FR_RibbonElement ribbonElement);

	
	//************************************
	// Function:  SetClientData
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: clientData	The input client data.
	// Param[in]: callback		The callback function will be called when the ribbon element is to be released.
	// Return: void
	// Remarks: Sets the client data to the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static	void SetClientData(FR_RibbonElement ribbonElement, void* clientData, FRFreeDataProc callback);


	//************************************
	// Function:  GetClientData
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: The client data.
	// Remarks: Gets the client data.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static	void* GetClientData(FR_RibbonElement ribbonElement);


	//************************************
	// Function:  SetAccel
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: bAlt			Whether the <Italic>Alt</Italic> key is pressed down or not.
	// Param[in]: bShift		Whether the <Italic>Shift</Italic> key is pressed down or not.
	// Param[in]: bCtrl			Whether the <Italic>Ctrl</Italic> key is pressed down or not.
	// Param[in]: key			The input accelerator key.
	// Return: void
	// Remarks: Sets the accelerator key of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetAccel(FR_RibbonElement ribbonElement, FS_BOOL bAlt, FS_BOOL bShift, FS_BOOL bCtrl, FS_CHAR key);


	//************************************
	// Function:  GetAccel
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[out]: bAlt			It receives <a>TRUE</a> if the <Italic>Alt</Italic> key is pressed down.
	// Param[out]: bShift		It receives <a>TRUE</a> if the <Italic>Shift</Italic> key is pressed down.
	// Param[out]: bCtrl		It receives <a>TRUE</a> if the <Italic>Ctrl</Italic> key is pressed down.
	// Param[out]: key			It receives the accelerator key
	// Return: void
	// Remarks: Gets the accelerator key of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetAccel(FR_RibbonElement ribbonElement, FS_BOOL* bAlt, FS_BOOL* bShift, FS_BOOL* bCtrl, FS_CHAR* key);


	//************************************
	// Function:  SetKey
	// Param[in]: ribbonElement		The input ribbon element object.
	// Param[in]: lpwsShorcutKey	The input shortcut key.
	// Return: void
	// Remarks: Sets the shortcut key of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetKey(FR_RibbonElement ribbonElement, FS_LPCWSTR lpwsShorcutKey);


	//************************************
	// Function:  GetKey
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[out]: wsKey		It receives the shortcut key of the ribbon element.
	// Return: void
	// Remarks: Gets the shortcut key of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetKey(FR_RibbonElement ribbonElement, FS_WideString* wsKey);

	
	//************************************
	// Function:  SetTooltip
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: lpwsTooltip	The input tooltip of the ribbon element.
	// Return: void
	// Remarks: Sets the tooltip of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetTooltip(FR_RibbonElement ribbonElement, FS_LPCWSTR lpwsTooltip);


	//************************************
	// Function:  GetTooltip
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[out]: wsTooltip	It receives the tooltip of the ribbon element.
	// Return: void
	// Remarks: Gets the tooltip of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetTooltip(FR_RibbonElement ribbonElement, FS_WideString* wsTooltip);

	
	//************************************
	// Function:  SetDescription
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: lpwsDes		The input description of the ribbon element.
	// Return: void
	// Remarks: Sets the description of the ribbon element..
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetDescription(FR_RibbonElement ribbonElement, FS_LPCWSTR lpwsDes);


	//************************************
	// Function:  GetDescription
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[out]: wsDes		It receives the description of the ribbon element.
	// Return: void
	// Remarks: Gets the description of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetDescription(FR_RibbonElement ribbonElement, FS_WideString* wsDes);

	
	//************************************
	// Function:  SetTitle
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: lpwsTitle		The input title of the ribbon element.
	// Return: void
	// Remarks: Sets the title of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetTitle(FR_RibbonElement ribbonElement, FS_LPCWSTR lpwsTitle);

	
	//************************************
	// Function:  GetTitle
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[out]: wsTitle		It receives the title of the ribbon element.
	// Return: void
	// Remarks: Gets the title of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetTitle(FR_RibbonElement ribbonElement, FS_WideString* wsTitle);


	//************************************
	// Function:  SetImage
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: largeBitmap	The input 32*32 bitmap.
	// Param[in]: smallBitmap	The input 16*16 bitmap.
	// Return: void
	// Remarks: Sets the icon of the ribbon element. The ribbon element contains a large icon and a small icon.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetImage(FR_RibbonElement ribbonElement, FS_DIBitmap largeBitmap, FS_DIBitmap smallBitmap);


	//************************************
	// Function:  AddChangeImage
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: largeBitmap	The input 32*32 bitmap list.
	// Param[in]: smallBitmap	The input 16*16 bitmap list.
	// Param[out]: nLargeIndex	It receives the index of large bitmap added to the bitmap list.
	// Param[out]: nSmallIndex	It receives the index of small bitmap added to the bitmap list.
	// Return: void
	// Remarks: Adds the 32*32 bitmap and the 16*16 bitmap to the bitmap list that can be used to change the icon of the ribbon element.
	// This interface is only applicable for <a>FR_RIBBON_BUTTON</a>, <a>FR_RIBBON_EDIT</a>, <a>FR_RIBBON_LISTBUTTON</a>, 
	// <a>FR_RIBBON_COLORBUTTON</a>, and <a>FR_RIBBON_PALETTEBUTTON</a>.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonElementChangeImage
	//************************************
	static void AddChangeImage(FR_RibbonElement ribbonElement, FS_DIBitmap largeBitmap, FS_DIBitmap smallBitmap, FS_INT32* nLargeIndex, FS_INT32* nSmallIndex);


	//************************************
	// Function:  ChangeImage
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: bUseDefault	<a>TRUE</a> if uses the original icon, otherwise uses the icon of specified index.
	// Param[in]: nLargeIndex	The specified index of the large icon.
	// Param[in]: nSmallIndex	The specified index of the small icon.
	// Return: void
	// Remarks: Changes the icon of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonElementAddChangeImage
	//************************************
	static void	ChangeImage(FR_RibbonElement ribbonElement, FS_BOOL bUseDefault, FS_INT32 nLargeIndex, FS_INT32 nSmallIndex);


	//************************************
	// Function:  SetTooltipImage
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: bitmap		The input icon of the tooltip.
	// Return: void
	// Remarks: Sets the icon of the tooltip of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonElementSetTooltipImageII
	//************************************
	static void SetTooltipImage(FR_RibbonElement ribbonElement, FS_DIBitmap bitmap);

	
	//************************************
	// Function:  SetTooltipImageII
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: hInstance		The instance handle of the plug-in.
	// Param[in]: nImageID		The resource ID of the bitmap.
	// Return: void
	// Remarks: Sets the icon of the tooltip of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonElementSetTooltipImage
	//************************************
	static void	SetTooltipImageII(FR_RibbonElement ribbonElement, FS_HINSTANCE hInstance, FS_UINT nImageID);

	
	//************************************
	// Function:  SetVisible
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: bVisible		<a>TRUE</a> if the ribbon element is visible, otherwise <a>FALSE</a>.
	// Return: void
	// Remarks: Sets the ribbon element to be visible or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetVisible(FR_RibbonElement ribbonElement, FS_BOOL bVisible);

	
	//************************************
	// Function:  GetVisible
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: <a>TRUE</a> if the ribbon element is visible, otherwise <a>FALSE</a>.
	// Remarks: Checks whether the ribbon element is visible or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL GetVisible(FR_RibbonElement ribbonElement);

	
	//************************************
	// Function:  Remove
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks:  Removes the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL Remove(FR_RibbonElement ribbonElement);

	
	//************************************
	// Function:  GetType
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: The type of the ribbon element.
	// Remarks: Gets the type of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_Ribbon_Element_Type GetType(FR_RibbonElement ribbonElement);


	//************************************
	// Function:  GetOriginalID
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: The original ID of the ribbon element.
	// Remarks: Gets the original ID of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_DWORD GetOriginalID(FR_RibbonElement ribbonElement);


	//************************************
	// Function:  GetName
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[out]: outName		It receives the name of the ribbon element.
	// Return: void
	// Remarks: Gets the name of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetName(FR_RibbonElement ribbonElement, FS_ByteString* outName);


	//************************************
	// Function:  GetSubItemCount
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: The count of the sub items.
	// Remarks: Gets the count of the sub items.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32	GetSubItemCount(FR_RibbonElement ribbonElement);

	
	//************************************
	// Function:  FindSubElementByIndex
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: nIndex		The specified index.
	// Return: The found ribbon element.
	// Remarks: Gets the ribbon element by index.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement FindSubElementByIndex(FR_RibbonElement ribbonElement, FS_INT32 nIndex);

	
	//************************************
	// Function:  GetSubElementByName
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: name			The specified name.
	// Return: The found ribbon element.
	// Remarks: Gets the ribbon element by name.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetSubElementByName(FR_RibbonElement ribbonElement, const FS_CHAR* name);

	
	//************************************
	// Function:  CopyElementAsSubItem
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: srcElement	The input ribbon element to be copied.
	// Param[in]: bChangeFun	When the user clicks the sub item, whether the parent's function should be change to the sub item's. Sets it FALSE as default.
	// Param[in]: bChangeImage	When the user clicks the sub item, whether the parent's icon should be change to the sub item's. Sets it FALSE as default.
	// Param[in]: bAlwaysSmall	Sets it as <a>TRUE</a> if the sub item is always shown as small.
	// Return: The sub item of the ribbon element. If the type is <a>FR_RIBBON_BUTTON</a>, the returned value can be converted to <a>FR_RibbonButton</a>.
	// Remarks: Copies an existing ribbon element as the sub item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void* CopyElementAsSubItem(FR_RibbonElement ribbonElement, FR_RibbonElement srcElement, FS_BOOL bChangeFun , FS_BOOL bChangeImage, FS_BOOL bAlwaysSmall);

	
	//************************************
	// Function:  GetCorrespondingButton
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: The ribbon button. If the type is <a>FR_RIBBON_BUTTON</a>, the returned value can be converted to <a>FR_RibbonButton</a>.
	// Remarks: Gets the corresponding button according to the type.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:	
	//************************************
	static void* GetCorrespondingButton(FR_RibbonElement ribbonElement);


	//************************************
	// Function:  SetAsSubElement
	// Param[in]: ribbonElement		The input ribbon element object.
	// Param[in]: subElementName	The specified name.
	// Param[in]: bChangeImage		Whether the parent's icon should be change to the sub item's.
	// Return: void
	// Remarks: Sets that the ribbon element uses the specified sub item's response function.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetAsSubElement(FR_RibbonElement ribbonElement, const FS_CHAR* subElementName, FS_BOOL bChangeImage);

	
	//************************************
	// Function:  SetImplicitLargeBitmap
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: largeBitmap	The input implicit large icon.
	// Return: void
	// Remarks: Sets the implicit large icon. It is the default large icon, when the icon needs to be changed by 
	// <a>FRRibbonElementSetAsSubElement</a>. If the ribbon element already has the large icon, this interface is ignored.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetImplicitLargeBitmap(FR_RibbonElement ribbonElement, FS_DIBitmap largeBitmap);

	
	//************************************
	// Function:  SetShowMode
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: bLarge		<a>TRUE</a> if the ribbon element is shown using the large icon.
	// Return: void
	// Remarks: Sets the showing mode.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetShowMode(FR_RibbonElement ribbonElement, FS_BOOL bLarge);


	//************************************
	// Function:  SetDropdownProc
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: proc			The callback function is called when the user clicks the ribbon element drop-down arrow.
	// Return: void
	// Remarks: Sets the drop-down callback function.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetDropdownProc(FR_RibbonElement ribbonElement, FRDropDownProc proc);

	//************************************
	// Function:  GetClientRect
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[out]: rcClient		It receives the client rectangle.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Gets the client rectangle of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See: FRRibbonElementGetWindowRect
	//************************************
	static FS_BOOL GetClientRect(FR_RibbonElement ribbonElement, FS_Rect* rcClient);
	
	//************************************
	// Function:  GetWindowRect
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[out]: rcScreen		It receives the window rectangle.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Gets the window rectangle of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See: FRRibbonElementGetClientRect
	//************************************
	static FS_BOOL GetWindowRect(FR_RibbonElement ribbonElement, FS_Rect* rcScreen);

	//************************************
	// Function:  ShowInQATCustomizeToolsDlg
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: bShow			It indicates whether the ribbon element can be shown in the QAT customize tools dialog.
	// Return: void
	// Remarks: Sets whether the ribbon element can be shown in the QAT customize tools dialog.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See:
	// Deprecated: Internal use.
	//************************************
	static void ShowInQATCustomizeToolsDlg(FR_RibbonElement ribbonElement, FS_BOOL bShow);

	//************************************
	// Function:  SetImageInitProc
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: proc			The callback invoked by Foxit Reader to init the visible image.
	// Return: void
	// Remarks: Sets the callback invoked by Foxit Reader to init the visible image.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:
	//************************************
	static void SetImageInitProc(FR_RibbonElement ribbonElement, FRRibbonElementImageInitProc proc);

	//************************************
	// Function:  GetButtonMapId
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: The map ID.
	// Remarks: Gets the map ID.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static DWORD GetButtonMapId(FR_RibbonElement ribbonElement);

	//************************************
	// Function:  SetBackstageViewTabElementKeepState
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: bKeepState	Whether keeps the state of element when the back stage view is open.
	// Return: void
	// Remarks: Sets to keep the state of element when the back stage view is open.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
	// See:
	//************************************
	static void SetBackstageViewTabElementKeepState(FR_RibbonElement ribbonElement, FS_BOOL bKeepState);

	//************************************
	// Function:  IsBackstageViewTabElementKeepState
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: Whether to keep the state of element when the back stage view is open.
	// Remarks: Checks whether to keep the state of element when the back stage view is open.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
	// See:
	//************************************
	static FS_BOOL IsBackstageViewTabElementKeepState(FR_RibbonElement ribbonElement);

	//************************************
	// Function:  SetSelectOnly
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: bSelectOnly	Whether the element is just only for selecting or not.
	// Return: void.
	// Remarks: Sets whether the element is just only for selecting or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	//************************************
	static void SetSelectOnly(FR_RibbonElement ribbonElement, FS_BOOL bSelectOnly);

	//************************************
	// Function:  GetCategoryName
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[out]: outName		(Filled by the method) A string buffer to receive the name.	
	// Return: void.
	// Remarks:	Gets the category name of the specified element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	// See: 
	//************************************
	static void GetCategoryName(FR_RibbonElement ribbonElement, FS_ByteString* outName);

	//************************************
	// Function:  GetPanelName
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[out]: outName		(Filled by the method) A string buffer to receive the name.	
	// Return: void.
	// Remarks:	Gets the panel name of the specified element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	// See: 
	//************************************
	static void GetPanelName(FR_RibbonElement ribbonElement, FS_ByteString* outName);

	//************************************
	// Function:  SetHighlight
	// Param[in]: ribbonElement	The input ribbon element object.
	// Return: void.
	// Remarks:	Set the element highlight.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	// See: 
	//************************************
	static void SetHighlight(FR_RibbonElement ribbonElement);

	//************************************
	// Function:  SetPDFImage
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: wsLargePDFBitmapName	The input 32*32 bitmap name. That need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf.
	// Param[in]: wsSmallPDFBitmapName	The input 16*16 bitmap name. That need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf.
	// Return: void
	// Remarks: Sets the icon of the ribbon element. The ribbon element contains a large icon and a small icon.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetPDFImage(FR_RibbonElement ribbonElement, FS_LPCWSTR wsLargePDFBitmapName, FS_LPCWSTR wsSmallPDFBitmapName);


	//************************************
	// Function:  AddChangePDFImage
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: wsLargePDFBitmapName	The input 32*32 bitmap name. That need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf.
	// Param[in]: wsSmallPDFBitmapName	The input 16*16 bitmap name. That need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage-phantom.pdf.
	// Param[out]: nLargeIndex	It receives the index of large PDF bitmap name.
	// Param[out]: nSmallIndex	It receives the index of small PDF bitmap name.
	// Return: void
	// Remarks: Adds the 32*32 PDF bitmap name  and the 16*16 PDF bitmap name that can be used to change the icon of the ribbon element.
	// This interface is only applicable for <a>FR_RIBBON_BUTTON</a>, <a>FR_RIBBON_EDIT</a>, <a>FR_RIBBON_LISTBUTTON</a>, 
	// <a>FR_RIBBON_COLORBUTTON</a>, and <a>FR_RIBBON_PALETTEBUTTON</a>.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0
	// See: FRRibbonElementChangePDFImage
	// Deprecated: Internal use.
	//************************************
	static void AddChangePDFImage(FR_RibbonElement ribbonElement, FS_LPCWSTR wsLargePDFBitmapName, FS_LPCWSTR wsSmallPDFBitmapName, FS_INT32* nLargeIndex, FS_INT32* nSmallIndex);
	
	//************************************
	// Function:  ChangeImage
	// Param[in]: ribbonElement	The input ribbon element object.
	// Param[in]: bUseDefault	<a>TRUE</a> if uses the original icon, otherwise uses the icon of specified index.
	// Param[in]: nLargeIndex	The specified index of the PDF large image.
	// Param[in]: nSmallIndex	The specified index of the PDF small image.
	// Return: void
	// Remarks: Changes the icon of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0
	// See: FRRibbonElementAddChangePDFImage
	// Deprecated: Internal use.
	//************************************
	static void	ChangePDFImage(FR_RibbonElement ribbonElement, FS_BOOL bUseDefault, FS_INT32 nLargeIndex, FS_INT32 nSmallIndex);

	//************************************
	// Function:  SetDropDownAddElementProc
	// Param[in]: ribbonElement	  The input ribbon element object.
	// Param[in]: proc	          The proc to add elelment when drop down the ribbon element.
	// Return: void
	// Remarks: Add elelment when drop down the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void SetDropDownAddElementProc(FR_RibbonElement ribbonElement, FRRibbonElementDropDownAddElementProc proc);

	//************************************
	// Function:  AddSubItem2
	// Param[in]: ribbonElement	The input ribbon element object,it get from FRRibbonPanelAddElement.
	// Param[in]: ribbonInfo	The input ribbon button info.	
	// Param[in]: nPos			The input position of ribbon element.
	// Param[in]: bOnTop		Whether the added sub item is on the top or not.
	// Param[in]: bChangeFun	When the user clicks the sub item, whether the parent's function should be change to the sub item's. Sets it FALSE as default.
	// Param[in]: bChangeImage	When the user clicks the sub item, whether the parent's icon should be change to the sub item's. Sets it FALSE as default.
	// Return: The new sub item of the ribbon element. For example, if sets <param>nElementType</param> as <a>FR_RIBBON_BUTTON</a>,
	// the returned value can be converted to <a>FR_RibbonButton</a>.
	// Remarks: Add a new sub item to the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonPanelAddElement
	//************************************
	static FS_LPVOID AddSubItem2(FR_RibbonElement ribbonElement, FR_RIBBONBUTTONINFO ribbonInfo, FS_INT32 nPos, FS_BOOL bOnTop, FS_BOOL bChangeFun, FS_BOOL bChangeImage);

	//************************************
	// Function:  GetFullTitle
	// Param[in]: ribbonElement	  The input ribbon element object.
	// Param[out]: wsTitle        Get the full title.
	// Return: void
	// Remarks: Get the full title of the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void GetFullTitle(FR_RibbonElement ribbonElement, FS_WideString* wsTitle);

	//************************************
	// Function:  SetTooltipHasHelp
	// Param[in]: ribbonElement	  The input ribbon element object.
	// Param[in]: bshowHelpLink	  TRUE: show help link.
	// Return: void
	// Remarks: Set if need show help link.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void SetTooltipHasHelp(FR_RibbonElement ribbonElement, FS_BOOL bshowHelpLink);
	
	//************************************
	// Function:  SetEditChangeProc
	// Param[in]: ribbonElement	  The input ribbon element object.
	// Param[in]: proc	          The input FRRibbonElementEditChangeProc.
	// Return: void
	// Remarks: Sets the callback function that will be called the edit ribbon element changed.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static void SetEditChangeProc(FR_RibbonElement ribbonElement, FRRibbonElementEditChangeProc proc);

	//************************************
	// Function:  AddHighlightImage
	// Param[in]: ribbonElement	      The input ribbon element object.
	// Param[in]: wsLargeBitmapName	  The input large bitmap name.
	// Param[in]: wsSmallBitmapName	  The input small bitmap name.
	// Return: void
	// Remarks: Set the hightlight pdf image name.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	// Deprecated: Internal use.
	//************************************
	static void AddHighlightImage(FR_RibbonElement ribbonElement, FS_LPCWSTR wsLargeBitmapName, FS_LPCWSTR wsSmallBitmapName);
	
	//************************************
	// Function:  SetImageReplaceColor
	// Param[in]: ribbonElement	      The input ribbon element object.
	// Param[in]: clrText			  The input text color.
	// Param[in]: clrStroke			  The input stroke color.
	// Param[in]: clrFill	          The input fill color.
	// Param[in]: bReplaceBoth	      If need replace when both have stroke and fill color. Default is false.
	// Param[in]: bRedraw	          If need redraw.
	// Param[in]: bReplaceOnlyHover	  If need replace when only on hover state.
	// Return: void
	// Remarks: Set the hightlight pdf image name.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0	
	// Deprecated: Internal use.
	//************************************
	static	void SetImageReplaceColor(FR_RibbonElement ribbonElement, FS_COLORREF clrText, FS_COLORREF clrStroke, FS_COLORREF clrFill, FS_BOOL bReplaceBoth, FS_BOOL bRedraw, FS_BOOL bReplaceOnlyHover);

	//************************************
	// Function:  SetPDFImageParentName
	// Param[in]: ribbonElement	    The input ribbon element object.
	// Param[in]: bsPDFPathName		The input PDF name.	
	// Return: 
	// Remarks: Adds a new ribbon element to the  specified group.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetPDFImageParentName(FR_RibbonElement ribbonElement, FS_LPCSTR bsPDFPathName);

	//************************************
	// Function:  FindElementByNameFloaty
	// Param[in]: csButtonName	    The input button name.
	// Return: FR_RibbonElement
	// Remarks: Find FR_RibbonElement by name in floaty .
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static FR_RibbonElement  FindElementByNameFloaty(FS_LPCSTR csButtonName);

	//************************************
	// Function:  SetClosePopupMenuProc
	// Param[in]: ribbonElement	    The input ribbon element object.
	// Param[in]: proc	            The input FRRibbonElementClosePopupMenuProc.
	// Return: void
	// Remarks: Set close popup menu proc.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	 SetClosePopupMenuProc(FR_RibbonElement ribbonElement, FRRibbonElementClosePopupMenuProc proc);

	//************************************
	// Function:  AddButtonToRight
	// Param[in]: ribbonElement	        The input ribbon element object.
	// Param[in]: wsRightBtnImage	    The pdf button image name.
	// Param[in]: wsRightBtnHighlightImage	    The pdf button highlight image.
	// Param[in]: proc	                The input FRExecuteProc.
	// Return: void
	// Remarks: Add button to right.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	AddButtonToRight(FR_RibbonElement ribbonElement, FS_LPCWSTR wsRightBtnImage, FS_LPCWSTR wsRightBtnHighlightImage, FRExecuteProc proc);

	//************************************
	// Function:  SetRightButtonPDFBitmap
	// Param[in]: ribbonElement	                The input ribbon element object.
	// Param[in]: wsRightBtnImage	            The pdf button image name.
	// Param[in]: wsRightBtnHighlightImage	    The pdf button highlight image.
	// Return: void
	// Remarks: Add button to right.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetRightButtonPDFBitmap(FR_RibbonElement ribbonElement, FS_LPCWSTR wsRightBtnImage, FS_LPCWSTR wsRightBtnHighlightImage);

	//************************************
	// Function:  SetRighButtonAutoHide
	// Param[in]: ribbonElement	                The input ribbon element object.
	// Param[in]: bAutoHide	                    Whether set auto hide. Default is TRUE.
	// Return: void
	// Remarks: Automatically hidden and only displayed when the button is highlight.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetRighButtonAutoHide(FR_RibbonElement ribbonElement, FS_BOOL bAutoHide);

	//************************************
	// Function:  DisableHighContrastThemeImage
	// Param[in]: ribbonElement	                The input ribbon element object.
	// Return: void
	// Remarks: In high contrast mode, whether to change the icon to a high contrast color.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	DisableHighContrastThemeImage(FR_RibbonElement ribbonElement);
};

class CFR_RibbonButton_V5
{
public:
	//************************************
	// Function:  GetElement
	// Param[in]: ribbonButton	The input ribbon button object.
	// Return: The ribbon element associated with the ribbon button.
	// Remarks: Gets the ribbon element associated with the ribbon button. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonButton ribbonButton);


	//************************************
	// Function:  SetDefaultCommand
	// Param[in]: ribbonButton	The input ribbon button object.
	// Param[in]: bSet			When the button has the drop-down style, sets it as <a>TRUE</a> if you wan to both click 
	// the button to execute and drop down the button, sets it as <a>FALSE</a> if you just want to drop down the button.
	// Return: void
	// Remarks: When the button has the drop-down style, sets <param>bSet</param> as <a>TRUE</a> if you wan to both click the button 
	// to execute and drop down the button, sets <param>bSet</param> as <a>FALSE</a> if you just want to drop down the button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetDefaultCommand(FR_RibbonButton ribbonButton, FS_BOOL bSet);

	
	//************************************
	// Function:  SetAlwaysShowDescription
	// Param[in]: ribbonButton				The input ribbon button object.
	// Param[in]: bAlwaysShowDescription	<a>TRUE</a> if you want to show the description always like the title.
	// Return: void
	// Remarks: Whether to show the description always like the title or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetAlwaysShowDescription(FR_RibbonButton ribbonButton, FS_BOOL bAlwaysShowDescription);


	//************************************
	// Function:  SetButtonPopupWnd
	// Param[in]: ribbonButton	The input ribbon button object.
	// Param[in]: hWnd			The window handle.
	// Return: void
	// Remarks: If a ribbon button has the drop-down style, you can pop up a window when it is dropped down. Sets <param>hWnd</param> as
	// NULL to make the ribbon button has the drop-down arrow. When the <a>FRDropDownProc</a> callback is invoked, calls this interface 
	// in the callback function to pass the window handle to the ribbon button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetButtonPopupWnd(FR_RibbonButton ribbonButton, HWND hWnd);


	//************************************
	// Function:  CloseButtonPopupWnd
	// Param[in]: ribbonButton	The input ribbon button object.
	// Return: void
	// Remarks: Closes the pop-up window created by <a>FRRibbonButtonSetButtonPopupWnd</a>
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void CloseButtonPopupWnd(FR_RibbonButton ribbonButton);
	
	//************************************
	// Function:  SetMenu
	// Param[in]: ribbonButton	    The input ribbon button object.
	// Param[in]: hMenu	            The input child menu.
	// Param[in]: pRibbonHandler	The input FR_RibbonHandler.
	// Param[in]: bIsDefaultCommand	Whether it is default command, defalut is false.
	// Param[in]: bRightAlign	    Whether it show right align, defalut is false.
	// Return: void
	// Remarks: Add the menu resource to the button as a child button, the information of the child button is set in FR_RibbonHandler.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetMenu(FR_RibbonButton ribbonButton, FS_LPVOID hMenu, FR_RibbonHandler pRibbonHandler,
		FS_BOOL bIsDefaultCommand, FS_BOOL bRightAlign);

	//************************************
	// Function:  SetButtonArrow
	// Param[in]: ribbonButton	The input ribbon button object.
	// Param[in]: bHasArrow	    If has arrow.
	// Return: void
	// Remarks: Set the button has arrow.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	 SetButtonArrow(FR_RibbonButton ribbonButton, FS_BOOL bHasArrow);
};

class CFR_RibbonEdit_V5
{
public:
	//************************************
	// Function:  GetElement
	// Param[in]: ribbonEdit	The input ribbon edit object.
	// Return: The ribbon element associated with the ribbon edit.
	// Remarks: Gets the ribbon element associated with the ribbon edit. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonEdit ribbonEdit);

	
	//************************************
	// Function:  GetText
	// Param[in]: ribbonEdit	The input ribbon edit object.
	// Param[out]: wsText		It receives the text of the ribbon edit.
	// Return: void
	// Remarks: Gets the text of the ribbon edit.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetText(FR_RibbonEdit ribbonEdit, FS_WideString* wsText);

	
	//************************************
	// Function:  SetText
	// Param[in]: ribbonEdit	The input ribbon edit object.
	// Param[in]: lpwsText		The input text.
	// Return: void
	// Remarks: Sets the text of the ribbon edit.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetText(FR_RibbonEdit ribbonEdit, FS_LPCWSTR lpwsText);

	
	//************************************
	// Function:  EnableSpinButtons
	// Param[in]: ribbonEdit	The input ribbon edit object.
	// Param[in]: nMin			The minimum value of the spin button.
	// Param[in]: nMax			The maximum value of the spin button.
	// Return: void
	// Remarks: Enables the spin buttons of the ribbon edit.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	EnableSpinButtons(FR_RibbonEdit ribbonEdit, FS_INT32 nMin, FS_INT32 nMax);

	
	//************************************
	// Function:  SetSearchMode
	// Param[in]: ribbonEdit	The input ribbon edit object.
	// Param[in]: lpwsPrompt	Then text displayed in the ribbon edit.
	// Param[in]: bEnable		<a>TRUE</a> to enable the search mode.
	// Return: void
	// Remarks: Whether to enable the search mode of the ribbon edit.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetSearchMode(FR_RibbonEdit ribbonEdit, FS_LPCWSTR lpwsPrompt, FS_BOOL bEnable);

	
	//************************************
	// Function:  SetWidth
	// Param[in]: ribbonEdit	The input ribbon edit object.
	// Param[in]: nWidth		The input width of the ribbon edit.
	// Return: void
	// Remarks: Sets the width of the ribbon edit.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetWidth(FR_RibbonEdit ribbonEdit, FS_INT32 nWidth);

	//************************************
	// Function:  GetHWnd
	// Param[in]: ribbonEdit	The input ribbon edit object.
	// Return: The window handle of the ribbon edit object.
	// Remarks: Gets the window handle of the ribbon edit object.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See:
	//************************************
	static HWND	GetHWnd(FR_RibbonEdit ribbonEdit);

	//************************************
	// Function:  SetTextFlag
	// Param[in]: ribbonEdit	The input ribbon edit object.
	// Param[in]: nTextFlag		The type you can input into the ribbon edit. 0 for no restriction, 1 for integer or float.
	// Return: void.
	// Remarks: Sets the type you can input into the ribbon edit. 0 for no restriction, 1 for integer or float.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// See:
	//************************************
	static void SetTextFlag(FR_RibbonEdit ribbonEdit, FS_DWORD nTextFlag);

	//************************************
	// Function:  SetFocus
	// Param[in]: ribbonEdit	The input ribbon edit object.
	// Param[in]: bFocus		Inputs TRUE to set the focus to the ribbon edit.
	// Return: void.
	// Remarks: Sets the focus to the ribbon edit or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	// See:
	//************************************
	static void SetFocus(FR_RibbonEdit ribbonEdit, FS_BOOL bFocus);

	//************************************
	// Function:  AddButtonToRight
	// Param[in]: ribbonEdit	The input ribbon edit object.
	// Param[in]: ribbonInfo	The input ribbon info.
	// Return: void.
	// Remarks: Add button to the right.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID AddButtonToRight(FR_RibbonEdit ribbonEdit, FR_RIBBONBUTTONINFO ribbonInfo);
}; 

class CFR_RibbonLabel_V5
{
public:
	//************************************
	// Function:  GetElement
	// Param[in]: ribbonLabel	The input ribbon label object.
	// Return: The ribbon element associated with the ribbon label.
	// Remarks: Gets the ribbon element associated with the ribbon label. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonLabel ribbonLabel);

};

class CFR_RibbonCheckBox_V5
{
public:
	//************************************
	// Function:  GetElement
	// Param[in]: ribbonCheckBox	The input ribbon check box object.
	// Return: The ribbon element associated with the ribbon check box.
	// Remarks: Gets the ribbon element associated with the ribbon check box. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonCheckBox ribbonCheckBox);


	//************************************
	// Function:  IsChecked
	// Param[in]: ribbonCheckBox	The input ribbon check box object.
	// Return: <a>TRUE</a> if the ribbon check box is checked, otherwise not.
	// Remarks: Checks whether the ribbon check box is checked or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL IsChecked(FR_RibbonCheckBox ribbonCheckBox);


	//************************************
	// Function:  SetCheck
	// Param[in]: ribbonCheckBox	The input ribbon check box object.
	// Param[in]: bCheck			<a>TRUE</a> if you want to set the ribbon check box to be checked.
	// Return: void
	// Remarks: Whether to set the ribbon check box to be checked or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetCheck(FR_RibbonCheckBox ribbonCheckBox, FS_BOOL bCheck);

};

class CFR_RibbonRadioButton_V5
{
public:
	//************************************
	// Function:  GetElement
	// Param[in]: ribbonRadioButton	The input ribbon radio button object.
	// Return: The ribbon element associated with the ribbon radio button.
	// Remarks: Gets the ribbon element associated with the ribbon radio button. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonRadioButton ribbonRadioButton);

	
	//************************************
	// Function:  IsChecked
	// Param[in]: ribbonRadioButton	The input ribbon radio button object.
	// Return: <a>TRUE</a> if the ribbon radio button is checked, otherwise not.
	// Remarks: Checks whether the ribbon radio button is checked or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL IsChecked(FR_RibbonRadioButton ribbonRadioButton);

	
	//************************************
	// Function:  SetCheck
	// Param[in]: ribbonRadioButton	The input ribbon radio button object.
	// Param[in]: bCheck			<a>TRUE</a> if you want to set the ribbon radio button to be checked.
	// Return: void
	// Remarks: Whether to set the ribbon radio button to be checked or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetCheck(FR_RibbonRadioButton ribbonRadioButton, FS_BOOL bCheck);

};

class CFR_RibbonComboBox_V5
{
public:
	//************************************
	// Function:  GetElement
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Return: The ribbon element associated with the ribbon combo box.
	// Remarks: Gets the ribbon element associated with the ribbon combo box. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonComboBox ribbonComboBox);

	
	//************************************
	// Function:  AddItem
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: lpwsItemText		The input text of the new item.
	// Return: The index of the new item.
	// Remarks: Adds a new item to the ribbon combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 AddItem(FR_RibbonComboBox ribbonComboBox, FS_LPCWSTR lpwsItemText);

	
	//************************************
	// Function:  InsertItem
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: nPos				The specified position.
	// Param[in]: lpwsItemText		The input text of the new item.
	// Return: The index of the new item.
	// Remarks: Inserts a new item to the ribbon combo box by position.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 InsertItem(FR_RibbonComboBox ribbonComboBox, FS_INT32 nPos, FS_LPCWSTR lpwsItemText);

	
	//************************************
	// Function:  GetItemCount
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Return: The item count.
	// Remarks: Gets the item count of the ribbon combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetItemCount(FR_RibbonComboBox ribbonComboBox);

	
	//************************************
	// Function:  GetItem
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: nIndex			The specified index.
	// Param[out]: wsText			It receives the text of the ribbon combo box.
	// Return: void
	// Remarks: Gets the text of the ribbon combo box by index.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetItem(FR_RibbonComboBox ribbonComboBox, FS_INT32 nIndex, FS_WideString* wsText);

	
	//************************************
	// Function:  GetCurSel
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Return: The currently selected item index.
	// Remarks: Gets the currently selected item index.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetCurSel(FR_RibbonComboBox ribbonComboBox);

	
	//************************************
	// Function:  RemoveAllItems
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Return: void
	// Remarks: Removes all the items.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void RemoveAllItems(FR_RibbonComboBox ribbonComboBox);

	
	//************************************
	// Function:  SelectItem
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: nItemIndex		The specified index.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Selects the specified items by index.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL SelectItem(FR_RibbonComboBox ribbonComboBox, FS_INT32 nItemIndex);

	
	//************************************
	// Function:  DeleteItem
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: nItemIndex		The specified index.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Deletes the specified item by index.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL DeleteItem(FR_RibbonComboBox ribbonComboBox, FS_INT32 nItemIndex);

	
	//************************************
	// Function:  FindItem
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: lpwsItemText		The specified text.
	// Return: The index of found item.
	// Remarks: Finds the item by text.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 FindItem(FR_RibbonComboBox ribbonComboBox, FS_LPCWSTR lpwsItemText);

	
	//************************************
	// Function:  SetWidth
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: nWidth			The input width of the ribbon combo box.
	// Return: void
	// Remarks: Sets the width of the ribbon combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetWidth(FR_RibbonComboBox ribbonComboBox, FS_INT32 nWidth);

	
	//************************************
	// Function:  SetEditBox
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: bHasEditBox		<a>TRUE</a> if the combo box has the edit box.
	// Return: void
	// Remarks: Sets whether the ribbon combo box has the edit box or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetEditBox(FR_RibbonComboBox ribbonComboBox, FS_BOOL bHasEditBox);

	
	//************************************
	// Function:  GetEditText
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[out]: wsText			It receives the text of the edit.
	// Return: void
	// Remarks: Gets the text of the edit text.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetEditText(FR_RibbonComboBox ribbonComboBox, FS_WideString* wsText);

	
	//************************************
	// Function:  SetEditText
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: lpwsText			The input text.
	// Return: void
	// Remarks: Sets the edit text of the ribbon combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetEditText(FR_RibbonComboBox ribbonComboBox, FS_LPCWSTR lpwsText);

	
	//************************************
	// Function:  EnableDropDownListResize
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: bEnable			<a>TRUE</a> if the dropped down list can be resized.
	// Return: void
	// Remarks: Sets whether the dropped down list can be resized or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void EnableDropDownListResize(FR_RibbonComboBox ribbonComboBox, FS_BOOL bEnable);

	//************************************
	// Function:  GetHWnd
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Return: The window handle of the ribbon combo box.
	// Remarks: Gets the window handle of the ribbon combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See:
	//************************************
	static HWND	GetHWnd(FR_RibbonComboBox ribbonComboBox);

	//************************************
	// Function:  SetTextFlag
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: nTextFlag			The type you can input into the combo box. 0 for no restriction, 1 for float, 2 for integer.
	// Return: void.
	// Remarks: Sets the type you can input into the combo box. 0 for no restriction, 1 for float, 2 for integer.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// See:
	//************************************
	static void SetTextFlag(FR_RibbonComboBox ribbonComboBox, FS_DWORD nTextFlag);

	//************************************
	// Function:  SetFocus
	// Param[in]: ribbonComboBox	The input ribbon combo box.
	// Param[in]: bFocus			Inputs TRUE to set the focus to the ribbon combo box.
	// Return: void.
	// Remarks: Sets the focus to the ribbon combo box or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	// See:
	//************************************
	static void SetFocus(FR_RibbonComboBox ribbonComboBox, FS_BOOL bFocus);
};

class CFR_RibbonFontComboBox_V5
{
public:
	//************************************
	// Function:  GetElement
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Return: The ribbon element associated with the ribbon font combo box.
	// Remarks: Gets the ribbon element associated with the ribbon font combo box. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonFontComboBox ribbonFontComboBox);


	//************************************
	// Function:  GetItem
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: nIndex				The specified index.
	// Param[out]: wsText				It receives the text of the item.
	// Return: void
	// Remarks: Gets the text of the item by index.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetItem(FR_RibbonFontComboBox ribbonFontComboBox, FS_INT32 nIndex, FS_WideString* wsText);

		
	//************************************
	// Function:  GetCurSel
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Return: The index of the currently selected item.
	// Remarks: Gets the index of the currently selected item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetCurSel(FR_RibbonFontComboBox ribbonFontComboBox);

	
	//************************************
	// Function:  SelectItem
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: nItemIndex			The specified index.
	// Return: void
	// Remarks: Selects the specified item by index.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SelectItem(FR_RibbonFontComboBox ribbonFontComboBox, FS_INT32 nItemIndex);

	
	//************************************
	// Function:  SetWidth
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: nWidth				The input width of the ribbon font combo box.
	// Return:void
	// Remarks: Sets the width of the ribbon font combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetWidth(FR_RibbonFontComboBox ribbonFontComboBox, FS_INT32 nWidth);


	//************************************
	// Function:  SetEditBox
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: bHasEditBox			TRUE if you want to set the font combo box to have edit box.
	// Return: void
	// Remarks: Sets whether the font combo box to have edit box or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetEditBox(FR_RibbonFontComboBox ribbonFontComboBox, FS_BOOL bHasEditBox);

	
	//************************************
	// Function:  GetEditText
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[out]: wsText				It receives the edit text.
	// Return: void
	// Remarks: Gets the edit text of the ribbon font combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetEditText(FR_RibbonFontComboBox ribbonFontComboBox, FS_WideString* wsText);


	//************************************
	// Function:  SetEditText
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: lpwsText				The input edit text.
	// Return: void
	// Remarks: Sets the edit text of the ribbon font combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetEditText(FR_RibbonFontComboBox ribbonFontComboBox, FS_LPCWSTR lpwsText);

	
	//************************************
	// Function:  EnableDropDownListResize
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: bEnable				<a>TRUE</a> if the dropped down list can be resized.
	// Return: void
	// Remarks: Sets whether the dropped down list can be resized or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void EnableDropDownListResize(FR_RibbonFontComboBox ribbonFontComboBox, FS_BOOL bEnable);

	//************************************
	// Function:  GetHWnd
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Return: The window handle of the ribbon font combo box.
	// Remarks: Gets the window handle of the ribbon font combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See:
	//************************************
	static HWND	GetHWnd(FR_RibbonFontComboBox ribbonFontComboBox);

	//************************************
	// Function:  AddFont
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: lpwsFaceName			The input font face name.
	// Param[in]: bSort					Whether to sort the font name or not.
	// Param[in]: nCharSet				The input charset. Sets it DEFAULT_CHARSET as default.
	// Return: The index of the font added into the ribbon font combo box.
	// Remarks: Adds a font into the ribbon font combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	//************************************
	static FS_INT32 AddFont(FR_RibbonFontComboBox ribbonFontComboBox, FS_LPCWSTR lpwsFaceName, FS_BOOL bSort, FS_BYTE nCharSet);

	//************************************
	// Function:  InsertFont
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: lpwsFaceName			The input font face name.
	// Param[in]: nIndex				The position where the font will be inserted.
	// Param[in]: nCharSet				The input charset. Sets it DEFAULT_CHARSET as default.
	// Return: The index of the font inserted into the ribbon font combo box.
	// Remarks: Inserts a font into the ribbon font combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	//************************************
	static FS_INT32 InsertFont(FR_RibbonFontComboBox ribbonFontComboBox, FS_LPCWSTR lpwsFaceName, FS_INT32 nIndex, FS_BYTE nCharSet);

	//************************************
	// Function:  GetFontIndex
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: lpwsFaceName			The input font face name.
	// Return: The index of the font.
	// Remarks: Gets the index of the font.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	//************************************
	static	FS_INT32 GetFontIndex(FR_RibbonFontComboBox ribbonFontComboBox, FS_LPCWSTR lpwsFaceName);

	//************************************
	// Function:  GetFontName
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: nIndex				The input font index.
	// Param[out]: outName				It receives the font name.
	// Return: void.
	// Remarks: Gets the font name.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	//************************************
	static void GetFontName(FR_RibbonFontComboBox ribbonFontComboBox, FS_INT32 nIndex, FS_WideString* outName);

	//************************************
	// Function:  GetScriptName
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: nIndex				The input font index.
	// Param[out]: outName				It receives the font script name.
	// Return: void.
	// Remarks: Gets the font script name.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	//************************************
	static void GetScriptName(FR_RibbonFontComboBox ribbonFontComboBox, FS_INT32 nIndex, FS_WideString* outName);

	//************************************
	// Function:  SelectItem2
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: lpwsFaceName			The input font face name.
	// Return: TRUE for success, otherwise not.
	// Remarks: Selects the item by font name.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	//************************************
	static FS_BOOL SelectItem2(FR_RibbonFontComboBox ribbonFontComboBox, FS_LPCWSTR lpwsFaceName);

	//************************************
	// Function:  RemoveFont
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: lpwsFaceName			The input font face name.
	// Return: TRUE for success, otherwise not.
	// Remarks: Remove the font by font name.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	//************************************
	static FS_BOOL RemoveFont(FR_RibbonFontComboBox ribbonFontComboBox, FS_LPCWSTR lpwsFaceName);

	//************************************
	// Function:  RemoveFont2
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: nIndex				The input font index.
	// Return: TRUE for success, otherwise not.
	// Remarks: Remove the font by font index.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	//************************************
	static FS_BOOL RemoveFont2(FR_RibbonFontComboBox ribbonFontComboBox, FS_INT32 nIndex);

	//************************************
	// Function:  GetFontCount
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Return: The font count of the ribbon font combo box.
	// Remarks: Gets the font count of the ribbon font combo box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	//************************************
	static FS_INT32 GetFontCount(FR_RibbonFontComboBox ribbonFontComboBox);

	//************************************
	// Function:  SetFocus
	// Param[in]: ribbonFontComboBox	The input ribbon font combo box.
	// Param[in]: bFocus				Inputs TRUE to set the focus to the ribbon font combo box.
	// Return: void.
	// Remarks: Sets the focus to the ribbon font combo box or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	// See:
	//************************************
	static void SetFocus(FR_RibbonFontComboBox ribbonFontComboBox, FS_BOOL bFocus);
};

class CFR_RibbonPaletteButton_V5
{
public:
	//************************************
	// Function:  GetElement
	// Param[in]: ribbonPaletteButton
	// Return: The ribbon element associated with the ribbon palette button.
	// Remarks: Gets the ribbon element associated with the ribbon palette button. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonPaletteButton ribbonPaletteButton);

	
	//************************************
	// Function:  AddGroup
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: name					The input name of the group.
	// Param[in]: lpwsGroupTitle		The input title of the group.
	// Param[in]: paletteImages			The input bitmap that include all items bitmap, it will be split by the wide of each image.
	// Param[in]: nWidthForEachImage	The width of each bitmap.
	// Return: void
	// Remarks: Adds a new group of  ribbon palette button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void AddGroup(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* name, FS_LPCWSTR lpwsGroupTitle, FS_DIBitmap paletteImages, FS_INT32 nWidthForEachImage);


	//************************************
	// Function:  SetGroupTitle
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: name					The input name of the group.
	// Param[in]: lpwsGroupTitle		The input title of the group.
	// Return: void
	// Remarks: Sets the title of the group.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetGroupTitle(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* name, FS_LPCWSTR lpwsGroupTitle);

	
	//************************************
	// Function:  SetItemToolTip
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: name					The input name of the group.
	// Param[in]: nItemIndex			The specified index of the item.
	// Param[in]: lpwsToolTip			The input tooltip of the item.
	// Return: void
	// Remarks: Sets the tooltip of the item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetItemToolTip(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* name, FS_INT32 nItemIndex, FS_LPCWSTR lpwsToolTip);


	//************************************
	// Function:  SetScrollButtonTooltip
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: lpwsTooltip			The input tooltip of the scroll button.
	// Return: void
	// Remarks: Sets the tooltip of the scroll button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetScrollButtonTooltip(FR_RibbonPaletteButton ribbonPaletteButton, FS_LPCWSTR lpwsTooltip);

	
	//************************************
	// Function:  SetMenuButtonTooltip
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: lpwsTooltip			The input tooltip of the drop-down button on the palette.
	// Return: void
	// Remarks: Sets the tooltip of the drop-down button on the palette.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetMenuButtonTooltip(FR_RibbonPaletteButton ribbonPaletteButton, FS_LPCWSTR lpwsTooltip);


	//************************************
	// Function:  GetGroupTitle
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: groupName				The input name of the group.
	// Param[out]: wsTitle				It receives the title of the group.
	// Return: void
	// Remarks: Gets the title of the group.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetGroupTitle(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* groupName, FS_WideString* wsTitle);


	//************************************
	// Function:  GetItemToolTip
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: groupName				The input name of the group.
	// Param[in]: nItemIndex			The specified index of the item.
	// Param[out]: wsTooltip			It receives the tooltip of the item.
	// Return: void
	// Remarks: Gets the tooltip of the item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetItemToolTip(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* groupName, FS_INT32 nItemIndex, FS_WideString* wsTooltip);


	//************************************
	// Function:  GetScrollButtonTooltip
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[out]: wsTooltip			It receives the tooltip of the scroll button.
	// Return: void
	// Remarks: Gets the tooltip of the scroll button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetScrollButtonTooltip(FR_RibbonPaletteButton ribbonPaletteButton, FS_WideString* wsTooltip);


	//************************************
	// Function:  GetMenuButtonTooltip
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[out]: wsTooltip			It receives the tooltip of the drop-down button on the palette.
	// Return: void
	// Remarks: Gets the tooltip of the drop-down button on the palette.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetMenuButtonTooltip(FR_RibbonPaletteButton ribbonPaletteButton, FS_WideString* wsTooltip);

	
	//************************************
	// Function:  GetGroupItemCount
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: groupName				The input name of the group.
	// Return: The item count of the group.
	// Remarks: Gets the item count of the group.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetGroupItemCount(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* groupName);

	
	//************************************
	// Function:  GetGroupCount
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Return:	The group count.
	// Remarks: Gets the group count.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetGroupCount(FR_RibbonPaletteButton ribbonPaletteButton);


	//************************************
	// Function:  IsGroupNameExist
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: groupName				The input name of the group.
	// Return: <a>TRUE</a> if the name of the group exists, otherwise not.
	// Remarks: Checks whether the name of the group exists or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL IsGroupNameExist(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* groupName);

	
	//************************************
	// Function:  SetButtonMode
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: bDropDown				TRUE if you want to set the drop-down button mode.
	// Return: void
	// Remarks: Whether to set the drop-down button mode or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetButtonMode(FR_RibbonPaletteButton ribbonPaletteButton, FS_BOOL bDropDown);

	
	//************************************
	// Function:  SetIconsInRow
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: nIconsInRow			The input count of icons in a row.
	// Return: void
	// Remarks: Sets the count of icons in a row.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetIconsInRow(FR_RibbonPaletteButton ribbonPaletteButton, FS_INT32 nIconsInRow);

	
	//************************************
	// Function:  EnableResize
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: bEnable				TRUE if the palette button can be enable.
	// Param[in]: bVertcalOnly			TRUE if the palette button can be resized.
	// Return: void
	// Remarks: Sets whether the palette button can be resized or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void EnableResize(FR_RibbonPaletteButton ribbonPaletteButton, FS_BOOL bEnable, FS_BOOL bVertcalOnly);

	
	//************************************
	// Function:  GetSelectedItem
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[out]: outGroupName			It receives the group name of the selected item.
	// Param[out]: nItemIndex			It receives the index of the selected item.
	// Return: void
	// Remarks: Gets the info of the selected item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetSelectedItem(FR_RibbonPaletteButton ribbonPaletteButton, FS_ByteString* outGroupName, FS_INT32* nItemIndex);


	//************************************
	// Function:  InsertItemToGroupLast
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: groupName				The specified group name.
	// Param[in]: lpwsGroupTitle		The input group title if the group name does not exist.
	// Param[in]: pBitmap				The input bitmap that include all items bitmap, it will be split by the wide of each image.
	// Param[in]: cxPaletteImage		The width of each bitmap.
	// Return: void
	// Remarks: Inserts a new item to the existing group. If the group does not exist, it will be created.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	InsertItemToGroupLast(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* groupName,  FS_LPCWSTR lpwsGroupTitle, FS_DIBitmap pBitmap, FS_INT32 cxPaletteImage);

	
	//************************************
	// Function:  SetDefaultGroup
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: pBitmap				The input bitmap that include all items bitmap, it will be split by the wide of each image.
	// Param[in]: cxPaletteImage		The width of each bitmap.
	// Return: void
	// Remarks: Sets the default group.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetDefaultGroup(FR_RibbonPaletteButton ribbonPaletteButton, FS_DIBitmap pBitmap, FS_INT32 cxPaletteImage);


	//************************************
	// Function:  RemoveGroup
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: groupName				The specified name.
	// Return: void
	// Remarks: Removes the specified group.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	RemoveGroup(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* groupName);


	//************************************
	// Function:  RemoveItemFromGroup
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: groupName				The specified group name.
	// Param[in]: nIndex				The specified index of the item.
	// Return: void
	// Remarks: Removes the specified item from the group.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	RemoveItemFromGroup(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* groupName, FS_INT32 nIndex);


	//************************************
	// Function:  SetItemData
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: groupName				The specified group name.
	// Param[in]: nIndex				The specified index of the item.
	// Param[in]: dwData				The input item data.
	// Return: void
	// Remarks: Sets the item data.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetItemData(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* groupName, FS_INT32 nIndex, FS_DWORD_PTR dwData);

	
	//************************************
	// Function:  GetItemData
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: groupName				The specified group name.
	// Param[in]: nIndex				The specified index of the item.
	// Return: The item data.
	// Remarks: Gets the item data.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_DWORD_PTR	GetItemData(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* groupName, FS_INT32 nIndex);


	//************************************
	// Function:  SetGroupItemEnable
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: groupName				The specified group name.
	// Param[in]: nIndex				The specified index of the item.
	// Param[in]: bEnable				Sets TRUE to enable the item, otherwise FALSE.
	// Return: void
	// Remarks: Enables the item or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetGroupItemEnable(FR_RibbonPaletteButton ribbonPaletteButton,const FS_CHAR* groupName, FS_INT32 nIndex, FS_BOOL bEnable);


	//************************************
	// Function:  SetSelectedItem
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: csGroupName			The specified group name.
	// Param[in]: nItemIndex			The specified index of the item.
	// Return: void
	// Remarks: Sets the selected item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetSelectedItem(FR_RibbonPaletteButton ribbonPaletteButton, const FS_CHAR* csGroupName, FS_INT32 nItemIndex);

	//************************************
	// Function:  SetRows
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: nRows					The input rows.
	// Return: void
	// Remarks: Sets the rows.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:
	//************************************
	static void SetRows(FR_RibbonPaletteButton ribbonPaletteButton, FS_INT32 nRows);

	//************************************
	// Function:  RemoveAllGroup
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Return: void
	// Remarks: Removes all the groups.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:
	//************************************
	static void RemoveAllGroup(FR_RibbonPaletteButton ribbonPaletteButton);

	//************************************
	// Function:  SetInitSize
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: cx					The width in x-coordinate.
	// Param[in]: cy					The height in y-coordinate.
	// Return: void
	// Remarks: Sets the init size.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:
	//************************************
	static void SetInitSize(FR_RibbonPaletteButton ribbonPaletteButton, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  GetItemInfo
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: nIndex				The input index of the the item.
	// Param[out]: outGroupName			It receives the name of the group that the item belongs to.
	// Param[out]: outItemIndex			It receives the index in the group that the item belongs to.
	// Return: void
	// Remarks: Gets the item info in the group.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// See:
	//************************************
	static void GetItemInfo(FR_RibbonPaletteButton ribbonPaletteButton, FS_INT32 nIndex, FS_ByteString* outGroupName, FS_INT32* outItemIndex);

	//************************************
	// Function:  SetHighlightItemProc
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: proc					The callback invoked when the item is highlight.
	// Return: void
	// Remarks: Sets the callback invoked when the item is highlight.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// See:
	//************************************
	static void SetHighlightItemProc(FR_RibbonPaletteButton ribbonPaletteButton, FRRibbonPaletteButtonHighlightItemProc proc);

	//************************************
	// Function:  SetItemAccNameTitle
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: bsGroupName			The name of the group that the item belongs to.
	// Param[in]: nIndex				The index in the group that the item belongs to.
	// Param[in]: wsAccName				The name provided to the Third party reading tool
	// Return: void
	// Remarks: Sets the callback invoked when the item is highlight.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1.0.0
	// See:
	//************************************
	static void	SetItemAccNameTitle(FR_RibbonPaletteButton ribbonPaletteButton, FS_ByteString bsGroupName, FS_INT32 nIndex, FS_WideString wsAccName);

	//************************************
	// Function:  AddGroupPtr
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: bsGroupName			The name of the group that the item belongs to.
	// Param[in]: csGroupTitle			The index in the group that the item belongs to.
	// Param[in]: arBitmap				The input bitmap list of the group.		
	// Param[in]: cxPaletteImage		Image width per image
	// Return: void
	// Remarks:  Add a new group to the ribbon list button..
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 10.1.0.0
	// See:
	//************************************
	static void AddGroupPtr(FR_RibbonPaletteButton ribbonPaletteButton, FS_ByteString csGroupName, FS_WideString csGroupTitle, FS_PtrArray arBitmap, FS_INT32 cxPaletteImage);
	
	//************************************
	// Function:  AddPDFBitmapToGroup
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: lpsGroupName			The name of the group that the item belongs to.
	// Param[in]: lpwsGroupTitle		The index in the group that the item belongs to.
	// Param[in]: arBitmapName			The input pdf bitmap name list of the group.		
	// Param[in]: cxImage				Image width per image
	// Param[in]: cyImage				Image height per image	
	// Return: void
	// Remarks:  Add a new group to the ribbon list button..
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void AddPDFBitmapToGroup(FR_RibbonPaletteButton ribbonPaletteButton, FS_LPCSTR lpsGroupName, FS_LPCWSTR lpwsGroupTitle, FS_WideStringArray arBitmapName, FS_INT32 cxImage, FS_INT32 cyImage);

	//************************************
	// Function:  SetMargin
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: itemMarginX			The width of the item margin.
	// Param[in]: itemMarginY		    The height of the item margin.
	// Param[in]: buttonMarginX			The width of the button margin.		
	// Param[in]: buttonMarginY			The height of the button margin.
	// Return: void
	// Remarks:  Set the margin of the palette button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetMargin(FR_RibbonPaletteButton ribbonPaletteButton, FS_INT32 itemMarginX, FS_INT32 itemMarginY, FS_INT32 buttonMarginX, FS_INT32 buttomMarginY);

	//************************************
	// Function:  SetDrawItemBorder
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.	
	// Return: void
	// Remarks:  Set the palette button if need to draw border.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetDrawItemBorder(FR_RibbonPaletteButton ribbonPaletteButton);

	//************************************
	// Function:  SetItemTitle
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.	
	// Param[in]: csGroupName	        The input group name.	
	// Param[in]: nItemIndex	        The input item index.	
	// Param[in]: csTitle	            The input title.	
	// Param[in]: bRedaw	            If need redraw.	
	// Return: void
	// Remarks:  Set the item title of palette button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetItemTitle(FR_RibbonPaletteButton ribbonPaletteButton, FS_LPCSTR csGroupName, FS_INT32 nItemIndex, FS_LPCWSTR csTitle, FS_BOOL bRedaw);

	//************************************
	// Function:  EnableShowTitle
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.	
	// Param[in]: bShow	                Whether show item title.	
	// Param[in]: bRecalcButton	        Whether recalculate button.	
	// Return: void
	// Remarks:  Enable show the item title.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	EnableShowTitle(FR_RibbonPaletteButton ribbonPaletteButton, FS_BOOL bShow, FS_BOOL bRecalcButton);
	
	//************************************
	// Function:  GetLine
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Return: FS_INT32
	// Remarks:  Get the current display line.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32	 GetLine(FR_RibbonPaletteButton ribbonPaletteButton);
	
	//************************************
	// Function:  SetLine
	// Param[in]: ribbonPaletteButton	The input ribbon palette button object.
	// Param[in]: nLine	                The input display line.
	// Param[in]: bRedraw	            If need be redraw.
	// Return: void
	// Remarks:  Set the current display line.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	 SetLine(FR_RibbonPaletteButton ribbonPaletteButton, FS_INT32 nLine, FS_BOOL bRedraw);
};

class CFR_RibbonColorButton_V5
{
public:
	//************************************
	// Function:  GetElement
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Return: The ribbon element associated with the ribbon color button.
	// Remarks: Gets the ribbon element associated with the ribbon color button. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonColorButton ribbonColorButton);

	
	//************************************
	// Function:  EnableAutomaticButton
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: lpwsLabel			The input label of the automatic button.
	// Param[in]: colorAutomatic	The input automatic color.
	// Param[in]: bEnable			Sets TRUE to enable the automatic button.
	// Param[in]: lpwsToolTip		The input tooltip of the automatic button.
	// Param[in]: bOnTop			Sets TRUE to set the automatic button on the top.
	// Param[in]: bDrawBorder		Sets TRUE to draw the border.
	// Return: void
	// Remarks: Enables the automatic button or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	EnableAutomaticButton(FR_RibbonColorButton ribbonColorButton, FS_LPCWSTR lpwsLabel, FS_COLORREF colorAutomatic, FS_BOOL bEnable, FS_LPCWSTR lpwsToolTip, FS_BOOL bOnTop, FS_BOOL bDrawBorder);

	
	//************************************
	// Function:  SetAutomaticButtonLabel
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: lpwsLabel			The input label of the automatic button.
	// Return: void
	// Remarks: Sets the label of the automatic button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetAutomaticButtonLabel(FR_RibbonColorButton ribbonColorButton, FS_LPCWSTR lpwsLabel);


	//************************************
	// Function:  SetAutomaticButtonToolTip
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: lpwsToolTip		The input tooltip of the automatic button.
	// Return: void
	// Remarks: Sets the tooltip of the automatic button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetAutomaticButtonToolTip(FR_RibbonColorButton ribbonColorButton, FS_LPCWSTR lpwsToolTip);


	//************************************
	// Function:  EnableOtherButton
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: lpwsLabel			The input label.
	// Param[in]: lpwsToolTip		The input tooltip.
	// Return: void
	// Remarks: Enables the button to select other color.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	EnableOtherButton(FR_RibbonColorButton ribbonColorButton, FS_LPCWSTR lpwsLabel, FS_LPCWSTR lpwsToolTip);

	
	//************************************
	// Function:  SetOtherButtonLabel
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: lpwsLabel			The input label.
	// Return: void
	// Remarks: Sets the label of the button used to select other color.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetOtherButtonLabel(FR_RibbonColorButton ribbonColorButton, FS_LPCWSTR lpwsLabel);

	
	//************************************
	// Function:  SetOtherButtonToolTip
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: lpwsToolTip		The input tooltip.
	// Return: void
	// Remarks: Sets the tooltip of the button used to select other color.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetOtherButtonToolTip(FR_RibbonColorButton ribbonColorButton, FS_LPCWSTR lpwsToolTip);


	//************************************
	// Function:  GetAutomaticButtonLabel
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[out]: wsLabel			It receives the label of the automatic button.
	// Return: void
	// Remarks: Gets the label of the automatic button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetAutomaticButtonLabel(FR_RibbonColorButton ribbonColorButton, FS_WideString* wsLabel);


	//************************************
	// Function:  GetAutomaticButtonToolTip
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[out]: wsTooltip			It receives the tooltip of the automatic button.
	// Return: void
	// Remarks: Gets the tooltip of the automatic button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetAutomaticButtonToolTip(FR_RibbonColorButton ribbonColorButton, FS_WideString* wsTooltip);


	//************************************
	// Function:  GetOtherButtonLabel
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[out]: wsLabel			It receives the label of the button.
	// Return: void
	// Remarks: Gets the label of the button use to select other color.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetOtherButtonLabel(FR_RibbonColorButton ribbonColorButton, FS_WideString* wsLabel);


	//************************************
	// Function:  GetOtherButtonToolTip
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[out]: wsTooltip		It receives the tooltip of the button.
	// Return: void
	// Remarks:  Gets the tooltip of the button use to select other color.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetOtherButtonToolTip(FR_RibbonColorButton ribbonColorButton, FS_WideString* wsTooltip);


	//************************************
	// Function:  AddColorsGroup
	// Param[in]: ribbonColorButton		The input ribbon color button object.
	// Param[in]: name					The name of the group.
	// Param[in]: lpwsLabel				The label of the group.
	// Param[in]: colors				The specified colors of the group.
	// Param[in]: nColorCount			The count of the colors.
	// Param[in]: bContiguousColumns	Sets TRUE if the columns are continuous.
	// Return: void
	// Remarks: Adds a new group of colors.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	AddColorsGroup(FR_RibbonColorButton ribbonColorButton, const FS_CHAR* name, FS_LPCWSTR lpwsLabel, FS_COLORREF* colors, FS_INT32 nColorCount, FS_BOOL bContiguousColumns);

	
	//************************************
	// Function:  AddStandardColor
	// Param[in]: ribbonColorButton		The input ribbon color button object.
	// Param[in]: name					The name of the group.
	// Param[in]: lpwsLabel				The label of the group.
	// Param[in]: bContiguousColumns	Sets TRUE if the columns are continuous.
	// Return: void
	// Remarks: Adds the group of the standard colors.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	AddStandardColor(FR_RibbonColorButton ribbonColorButton, const FS_CHAR* name, FS_LPCWSTR lpwsLabel, FS_BOOL bContiguousColumns);

	
	//************************************
	// Function:  AddAdditionalColor
	// Param[in]: ribbonColorButton		The input ribbon color button object.
	// Param[in]: name					The name of the group.
	// Param[in]: lpwsLabel				The label of the group.
	// Param[in]: bContiguousColumns	Sets TRUE if the columns are continuous.
	// Return: void
	// Remarks: Adds the group of the additional colors.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	AddAdditionalColor(FR_RibbonColorButton ribbonColorButton, const FS_CHAR* name, FS_LPCWSTR lpwsLabel, FS_BOOL bContiguousColumns);

	
	//************************************
	// Function:  AddMainColor
	// Param[in]: ribbonColorButton		The input ribbon color button object.
	// Param[in]: name					The name of the group. 
	// Param[in]: lpwsLabel				The label of the group.
	// Param[in]: bContiguousColumns	Sets TRUE if the columns are continuous.
	// Return: void
	// Remarks: Adds the group of the main colors.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	AddMainColor(FR_RibbonColorButton ribbonColorButton, const FS_CHAR* name, FS_LPCWSTR lpwsLabel, FS_BOOL bContiguousColumns);

	
	//************************************
	// Function:  SetGroupLabel
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: name				The name of the group.
	// Param[in]: lpwsLabel			The input label of the group.
	// Return: void
	// Remarks: Sets the group label.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetGroupLabel(FR_RibbonColorButton ribbonColorButton, const FS_CHAR* name, FS_LPCWSTR lpwsLabel);


	//************************************
	// Function:  GetGroupLabel
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: name				The name of the group.
	// Param[out]: wsLabel			It receives the label of the group.
	// Return: void
	// Remarks: Gets the label of the group.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetGroupLabel(FR_RibbonColorButton ribbonColorButton, const FS_CHAR* name, FS_WideString* wsLabel);

	
	//************************************
	// Function:  SetColor
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: color				The input color.
	// Return: void
	// Remarks: Sets the selected color of the ribbon color button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetColor(FR_RibbonColorButton ribbonColorButton, FS_COLORREF color);

	
	//************************************
	// Function:  GetColor
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Return: The color.
	// Remarks: Gets the selected color of the ribbon color button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_COLORREF GetColor(FR_RibbonColorButton ribbonColorButton);

	
	//************************************
	// Function:  SetColumns
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: nColumns			The input column numbers.
	// Return: void
	// Remarks: Sets the column numbers.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetColumns(FR_RibbonColorButton ribbonColorButton, FS_INT32 nColumns);

	
	//************************************
	// Function:  SetColorBoxSize
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: nWidth			The input width. The default value is 22.
	// Param[in]: nHeight			The input height. The default value is 22.
	// Return: void
	// Remarks: Sets the size of the color box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetColorBoxSize(FR_RibbonColorButton ribbonColorButton, FS_INT32 nWidth, FS_INT32 nHeight);


	//************************************
	// Function:  SetDefaultCommand
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Param[in]: bDefaultCommand	When the button has the drop-down style, sets it as <a>TRUE</a> if you wan to both click 
	// the button to execute and drop down the button, sets it as <a>FALSE</a> if you just want to drop down the button.
	// Return: void
	// Remarks: When the button has the drop-down style, sets <param>bDefaultCommand</param> as <a>TRUE</a> if you wan to both click the button 
	// to execute and drop down the button, sets <param>bDefaultCommand</param> as <a>FALSE</a> if you just want to drop down the button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetDefaultCommand(FR_RibbonColorButton ribbonColorButton, FS_BOOL bDefaultCommand);


	//************************************
	// Function:  IsAutomaticButtonClick
	// Param[in]: ribbonColorButton	The input ribbon color button object.
	// Return: <a>TRUE</a> if the automatic button is clicked, otherwise not.
	// Remarks: Checks whether the automatic button is clicked or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL IsAutomaticButtonClick(FR_RibbonColorButton ribbonColorButton);
};

class CFR_RibbonSlider_V5
{
public:
	//************************************
	// Function:  GetElement
	// Param[in]: ribbonSlider	The input ribbon slider object.
	// Return: The ribbon element associated with the ribbon slider.
	// Remarks: Gets the ribbon element associated with the ribbon slider. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonSlider ribbonSlider);
	
	//************************************
	// Function:  SetZoomButtons
	// Param[in]: ribbonSlider	The input ribbon slider object.
	// Param[in]: bSet			Sets TRUE to add the zoom buttons.
	// Return: void
	// Remarks: Sets whether to add the zoom buttons or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetZoomButtons(FR_RibbonSlider ribbonSlider, FS_BOOL bSet);
	
	//************************************
	// Function:  SetRange
	// Param[in]: ribbonSlider	The input ribbon slider object.
	// Param[in]: nMin			The minimum value of the range.
	// Param[in]: nMax			The maximum value of the range.
	// Return: void
	// Remarks: Sets the range of the slider.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetRange(FR_RibbonSlider ribbonSlider, FS_INT32 nMin, FS_INT32 nMax);
	
	//************************************
	// Function:  GetRangeMin
	// Param[in]: ribbonSlider	The input ribbon slider object.
	// Return: The minimum value of the range.
	// Remarks:  Gets the minimum value of the range.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetRangeMin(FR_RibbonSlider ribbonSlider);
	
	//************************************
	// Function:  GetRangeMax
	// Param[in]: ribbonSlider	The input ribbon slider object.
	// Return: The maximum value of the range.
	// Remarks: Gets the maximum value of the range.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetRangeMax(FR_RibbonSlider ribbonSlider);
	
	//************************************
	// Function:  SetPos
	// Param[in]: ribbonSlider	The input ribbon slider object.
	// Param[in]: nPos			The input position.
	// Param[in]: bRedraw		Sets TRUE to redraw the slider, otherwise not.
	// Return: void
	// Remarks: Sets the position of the slider.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetPos(FR_RibbonSlider ribbonSlider, FS_INT32 nPos, FS_BOOL bRedraw);
	
	//************************************
	// Function:  GetPos
	// Param[in]: ribbonSlider	The input ribbon slider object.
	// Return: The position of the slider.
	// Remarks: Gets the position of the slider.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetPos(FR_RibbonSlider ribbonSlider);

	//************************************
	// Function:  SetWidth
	// Param[in]: ribbonSlider	The input ribbon slider object.
	// Param[in]: nWidth		The input width of the ribbon slider.
	// Return: void
	// Remarks: Sets the width of the ribbon slider.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetWidth(FR_RibbonSlider ribbonSlider, FS_INT32 nWidth);

	//************************************
	// Function:  SetStyle
	// Param[in]: ribbonSlider	The input ribbon slider object.
	// Param[in]: dwStyle		The input style of the ribbon slider. References to <Italic>MFC CSliderCtrl</Italic>.
	// Return: void
	// Remarks: Sets the style of the ribbon slider.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetStyle(FR_RibbonSlider ribbonSlider, FS_DWORD dwStyle);

	//************************************
	// Function:  GetMouseStatus
	// Param[in]: ribbonSlider	The input ribbon slider object.
	// Return: The mouse status. -1 - none, 0 - LButtonDown, 1 - LButtonUp, 2 - LButtonDown & MouseMove.
	// Remarks: Gets the mouse status. -1 - none, 0 - LButtonDown, 1 - LButtonUp, 2 - LButtonDown & MouseMove.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetMouseStatus(FR_RibbonSlider ribbonSlider);
};

class CFR_RibbonListButton_V5 //Internal use
{
public:
	//************************************
	// Function:  GetElement
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Return: The ribbon element associated with the ribbon list button.
	// Remarks: Gets the ribbon element associated with the ribbon list button. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonListButton ribbonListButton);

	
	//************************************
	// Function:  AddGroup
	// Param[in]: ribbonListButton		The input ribbon list button object.
	// Param[in]: name					The input group name.
	// Param[in]: lpwsGroupTitle		The input group title.
	// Param[in]: paletteImages			The input bitmap that include all items bitmap, it will be split by the wide of each image.
	// Param[in]: nWidthForEachImage	The width of each bitmap.
	// Param[in]: arrLabels				It contains labels of all the items.
	// Return: void
	// Remarks: Add a new group to the ribbon list button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void AddGroup(FR_RibbonListButton ribbonListButton, const FS_CHAR* name, FS_LPCWSTR lpwsGroupTitle,	FS_DIBitmap paletteImages, FS_INT32 nWidthForEachImage, FS_WideStringArray arrLabels);


	//************************************
	// Function:  GetGroupCount
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Return: The group count of the ribbon list button.
	// Remarks: Gets the group count of the ribbon list button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetGroupCount(FR_RibbonListButton ribbonListButton);

	//************************************
	// Function:  IsGroupNameExist
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: name				The name of the group.
	// Return: <a>TRUE</a> if the group name exists, otherwise not.
	// Remarks: Checks whether the group name exists or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL IsGroupNameExist(FR_RibbonListButton ribbonListButton, const FS_CHAR* name);

	
	//************************************
	// Function:  EnableResize
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: bEnable			TRUE if the ribbon list button can be resized.
	// Param[in]: bVertcalOnly		TRUE if the ribbon list button can be resized in vertical direction only.
	// Return: void
	// Remarks: Sets whether the ribbon list button can be resized or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void EnableResize(FR_RibbonListButton ribbonListButton, FS_BOOL bEnable, FS_BOOL bVertcalOnly);

	
	//************************************
	// Function:  SetGroupTitle
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: name				The name of the group.
	// Param[out]: lpwsGroupTitle	It receives the title of the group.
	// Return: void
	// Remarks: Sets the title of the group.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetGroupTitle(FR_RibbonListButton ribbonListButton, const FS_CHAR* name, FS_LPCWSTR lpwsGroupTitle);

	
	//************************************
	// Function:  SetItemToolTip
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: name				The name of the group.
	// Param[in]: nItemIndex		The specified index.
	// Param[in]: lpwsToolTip		The input tooltip of the item.
	// Return: void
	// Remarks: Sets the tooltip of the item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetItemToolTip(FR_RibbonListButton ribbonListButton, const FS_CHAR* name, FS_INT32 nItemIndex, FS_LPCWSTR lpwsToolTip);


	//************************************
	// Function:  SetItemTitle
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: name				The name of the group.
	// Param[in]: nItemIndex		The specified index.
	// Param[in]: lpwsItemTitle		The input title of the item.
	// Return: void
	// Remarks: Sets the title of the item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetItemTitle(FR_RibbonListButton ribbonListButton, const FS_CHAR* name, FS_INT32 nItemIndex, FS_LPCWSTR lpwsItemTitle);


	//************************************
	// Function:  GetGroupTitle
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: groupName			The name of the group.
	// Param[out]: wsTitle			It receives the title of the group.
	// Return: void
	// Remarks: Gets the title of the group.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetGroupTitle(FR_RibbonListButton ribbonListButton, const FS_CHAR* groupName, FS_WideString* wsTitle);


	//************************************
	// Function:  GetItemToolTip
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: groupName			The name of the group.
	// Param[in]: nItemIndex		The specified index of the item.
	// Param[out]: wsTooltip		It receives the tooltip of the item.
	// Return: void
	// Remarks: Gets the tooltip of the item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetItemToolTip(FR_RibbonListButton ribbonListButton, const FS_CHAR* groupName, FS_INT32 nItemIndex, FS_WideString* wsTooltip);


	//************************************
	// Function:  GetItemTitle
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: groupName			The name of the group.
	// Param[in]: nItemIndex		The specified index of the item.
	// Param[out]: wsTitle			It receives the title of the item.
	// Return: void
	// Remarks: Gets the title of the item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	GetItemTitle(FR_RibbonListButton ribbonListButton, const FS_CHAR* groupName, FS_INT32 nItemIndex, FS_WideString* wsTitle);

	
	//************************************
	// Function:  GetItemCount
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: groupName			The name of the group.
	// Return: The item count.
	// Remarks: Get the item count.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_INT32 GetItemCount(FR_RibbonListButton ribbonListButton, const FS_CHAR* groupName);

	
	//************************************
	// Function:  GetSelectedItem
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[out]: outGroupName		It receives the name of the group.
	// Param[out]: nItemIndex		It receives the index of the selected item.
	// Return: void
	// Remarks: Gets the info of the selected item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void GetSelectedItem(FR_RibbonListButton ribbonListButton, FS_ByteString* outGroupName, FS_INT32* nItemIndex);

	
	//************************************
	// Function:  SetAlignedSide
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: nAlignedSide		The alignment type.
	// Return: void
	// Remarks: Sets the alignment type.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetAlignedSide(FR_RibbonListButton ribbonListButton, FR_RIBBON_LISTBUTTON_ALIGNEDSIDE nAlignedSide);

	
	//************************************
	// Function:  SetIconsInRow
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: nIconsInRow		The input count of icons in a row.
	// Return: void
	// Remarks: Sets the count of icons in a row.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetIconsInRow(FR_RibbonListButton ribbonListButton, FS_INT32 nIconsInRow);

	
	//************************************
	// Function:  SetSelectedItem
	// Param[in]: ribbonListButton	The input ribbon list button object.
	// Param[in]: csGroupName		The name of the group.
	// Param[in]: nItemIndex		The specified index.
	// Return: void
	// Remarks: Sets the selected item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void SetSelectedItem(FR_RibbonListButton ribbonListButton,const FS_CHAR* csGroupName, FS_INT32 nItemIndex);
};

class CFR_RibbonBackStageViewItem_V5
{
public:	
	//************************************
    // Function:  SetTitle
    // Param[in]: item		The input back stage view item object.
    // Param[in]: lpwsTitle	The input title of the back stage view item.
    // Return: void
    // Remarks: Sets the title of the back stage view item.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See: FRRibbonBarAddBackStageViewItem
    // See: FRRibbonBarGetBackStageViewItem
    //************************************
	static void	SetTitle(FR_RibbonBackStageViewItem item, FS_LPCWSTR lpwsTitle);

    //************************************
	// Function:  AddDialog
	// Param[in]: item			The input back stage view item object.
	// Param[in]: createProc	The callback function is called to notify the plug-in to create the dialog when the back stage view is shown.
	// Param[in]: destroyProc	The callback function is called to notify the plug-in to destroy the dialog when the back stage view is closed.
	// Param[in]: pClientData	The user-supplied data passed to the callback function.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: You can create your own dialog on the back stage view when it is shown. You can either add a dialog or a property sheet on 
	// the back stage view.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:	
	//************************************
	static FS_BOOL AddDialog(FR_RibbonBackStageViewItem item, FRRibbonBackstageCreateProc createProc, FRRibbonBackstageDestoryProc destroyProc, void* pClientData);

	//************************************
	// Function:  AddPropertySheetPage
	// Param[in]: item			The input back stage view item object.
	// Param[in]: lpsName		The input name of the property sheet page.
	// Param[in]: lpwsPageTitle	The input title of the property sheet page.
	// Param[in]: pBitmap		The input bitmap of the property sheet page.
	// Param[in]: nPos			The input position of the property sheet page.
	// Param[in]: createProc	The callback function is called to notify the plug-in to create the dialog when the back stage view is shown.
	// Param[in]: destroyProc	The callback function is called to notify the plug-in to destroy the dialog when the back stage view is closed.
	// Param[in]: pClientData	The user-supplied data passed to the callback function.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: You can create your own property sheet page on the back stage view when it is shown. You can either add a dialog or a property sheet on 
	// the back stage view.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Current function has been deprecated , so not recommend to use current function any more. User can use  FRRibbonBackStageViewItemAddPropertySheetPage2 function instead.
	//************************************
	static FS_BOOL	AddPropertySheetPage(FR_RibbonBackStageViewItem item, FS_LPCSTR lpsName, FS_LPCWSTR lpwsPageTitle, FS_DIBitmap pBitmap, FS_INT32 nPos, FRRibbonBackstageCreateProc createProc, FRRibbonBackstageDestoryProc destroyProc, void* pClientData);

	
	//************************************
	// Function:  RemovePropertySheetPage
	// Param[in]: item		The input back stage view item object.
	// Param[in]: lpsName	The specified name of the property sheet page.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: Removes the specified property sheet page.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL RemovePropertySheetPage(FR_RibbonBackStageViewItem item, FS_LPCSTR lpsName);


	//************************************
	// Function:  AddPropertySheetGroup
	// Param[in]: item				The input back stage view item object.
	// Param[in]: lpsName			The input name of the property sheet group.
	// Param[in]: lpwsGroupTitle	The input title of the property sheet group.
	// Param[in]: nPos				The input position of the property sheet group.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: Adds a new property sheet group.
	// Notes: The function can only be used for Windows. It ususally support add one group.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL	AddPropertySheetGroup(FR_RibbonBackStageViewItem item, FS_LPCSTR lpsName, FS_LPCWSTR lpwsGroupTitle, FS_INT32 nPos);


	//************************************
	// Function:  SetGroupTitle
	// Param[in]: item				The input back stage view item object.
	// Param[in]: lpwsGroupTitle	The input title of the property sheet group.
	// Param[in]: nGroupIndex		The specified index.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: Sets the title of the property sheet group.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL	SetGroupTitle(FR_RibbonBackStageViewItem item, FS_LPCWSTR lpwsGroupTitle, int nGroupIndex);


	//************************************
    // Function:  SetVisible
    // Param[in]: item		The input back stage view item object.
    // Param[in]: bVisible	<a>TRUE</a> if the back stage view item is visible, otherwise not.
    // Return: void
    // Remarks: Sets the back stage view item to be visible or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static void	SetVisible(FR_RibbonBackStageViewItem item, FS_BOOL bVisible);

    //************************************
    // Function:  SetDisable
    // Param[in]: item		The input back stage view item object.
    // Param[in]: bDisable	<a>TRUE</a> if the back stage view item is disabled, otherwise not.
    // Return: void
    // Remarks: Sets the back stage view item to be disabled or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static void	SetDisable(FR_RibbonBackStageViewItem item, FS_BOOL bDisable);

    //************************************
	// Function:  AddAnchor
	// Param[in]: hParentWnd	The parent window handle of the dialog.
	// Param[in]: hWnd			The window handle of the dialog.
	// Param[in]: typeMove		The input movement type.
	// Param[in]: typeSize		The input size type.
	// Param[in]: percMove		Sets it 100,100 as default.
	// Param[in]: percSize		Sets it 100,100 as default.
	// Param[in]: pParentWnd	A pointer to the main frame UI parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	// You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: This interface is used to adjust the control position of the dialog added on the back stage view.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL AddAnchor(HWND hParentWnd, HWND hWnd, FRRibbonBackStageViewItemXMoveType typeMove, FRRibbonBackStageViewItemXSizeType typeSize, FS_DevicePoint percMove, FS_DevicePoint percSize, void* pParentWnd);


	//************************************
	// Function:  ModifiedToRibbonStyleButton
	// Param[in]: pWnd			The pointer to the MFC control.
	// Param[in]: nID			The control ID.
	// Param[in]: typeButton	The specified ribbon style type.
	// Param[in]: pParentWnd	A pointer to the main frame UI parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	// You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	// Return:  The ribbon style button. For example, if sets <param>typeButton</param> as <a>FR_RibbonStyle_Button</a>, the returned value
	// can be converted to <a>FR_RibbonStyleButton</a>.
	// Remarks: Modifies the MFC controls to ribbon style button.
	// Notes: The api is used to all dialog, not just filepage UI. The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void* ModifiedToRibbonStyleButton(void* pWnd, unsigned int nID, FRRibbonStyleButtonType typeButton, void* pParentWnd);


	//************************************
	// Function:  SetPropertyActivePage
	// Param[in]: item			The input back stage view item object.
	// Param[in]: lpsPageName	The specified name of the property sheet page.
	// Return: void
	// Remarks: Sets the active property sheet page.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SetPropertyActivePage(FR_RibbonBackStageViewItem item, FS_LPCSTR lpsPageName);

	//************************************
	// Function:  SetPageTitle
	// Param[in]: item			The input back stage view item object.
	// Param[in]: lpsPageName	The specified name of the property sheet page.
	// Param[in]: lpwsTitle		The input title you want to set.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: Sets the title of the property sheet page.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.1
	// See: FRRibbonBackStageViewItemAddPropertySheetPage
	//************************************
	static FS_BOOL SetPageTitle(FR_RibbonBackStageViewItem item, FS_LPCSTR lpsPageName, FS_LPCWSTR lpwsTitle);

	//************************************
	// Function:  IsPropertySheetPageExist
	// Param[in]: item			The input back stage view item object.
	// Param[in]: lpsPageName	The specified name of the property sheet page.
	// Return: <a>TRUE</a> means the property sheet page exists, otherwise not.
	// Remarks: Checks whether the property sheet page exists or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: FRRibbonBackStageViewItemAddPropertySheetPage
	//************************************
	static FS_BOOL IsPropertySheetPageExist(FR_RibbonBackStageViewItem item, FS_LPCSTR lpsPageName);

	//************************************
	// Function:  IsDialogExist
	// Param[in]: item			The input back stage view item object.
	// Return: <a>TRUE</a> means the dialog exists, otherwise not.
	// Remarks: Checks whether the dialog exists or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: 
	//************************************
	static FS_BOOL IsDialogExist(FR_RibbonBackStageViewItem item);

	//************************************
	// Function:  GetElement
	// Param[in]: item	The input back stage view item object.
	// Return: The ribbon element associated with the back stage view item.
	// Remarks: Gets the ribbon element associated with the back stage view item. All types of buttons associate with a ribbon element.
	// The ribbon element manipulates the common properties of all types of buttons.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:
	//************************************
	static FR_RibbonElement GetElement(FR_RibbonBackStageViewItem item);

	//************************************
	// Function:  EnablePropertyPageRemove
	// Param[in]: item		The input back stage view item object.
	// Param[in]: lpsName	The specified name of the property sheet page.
	// Param[in]: bEnable	Whether the property page can be removed or not.
	// Return: void.
	// Remarks: Sets whether the property page can be removed or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void EnablePropertyPageRemove(FR_RibbonBackStageViewItem item, FS_LPCSTR lpsName, FS_BOOL bEnable);

	//************************************
	// Function:  RedrawPropertySheet
	// Param[in]: item		The input back stage view item object.
	// Return: void.
	// Remarks: Redraws the property sheet.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	//************************************
	static void RedrawPropertySheet(FR_RibbonBackStageViewItem item);

	//************************************
	// Function:  SetDlgItemMaxSize
	// Param[in]: hParentWnd		The parent window of the dialog item.
	// Param[in]: hWnd				The window handle of the dialog item.
	// Param[in]: cx				The horizon size.
	// Param[in]: cy				The vertical size.
	// Return: void.
	// Remarks: Sets the max size of the dialog item in the back stage view. 
	// Notes: The function can only be used for Windows. It usually used in FRRibbonBackstageCreateProc.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetDlgItemMaxSize(HWND hParentWnd, HWND hWnd, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  SetPageSelectProc
	// Param[in]: item				The input back stage view item object.
	// Param[in]: lpsPageName		The specified property page of the back stage view item.
	// Param[in]: selectPageProc	The callback function is called to notify the plug-in that the specified property page is selected.
	// Return: void.
	// Remarks: Sets the callback function called to notify the plug-in that the specified property page is selected.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See:
	//************************************
	static void SetPageSelectProc(FR_RibbonBackStageViewItem item, FS_LPCSTR lpsPageName, FRRibbonBackstageSelectPageProc selectPageProc);

	//************************************
	// Function:  BCGPreTranslateMessage
	// Param[in]: pWnd				The CWnd of the dialog.
	// Param[in]: pMsg		        The msg.
	// Return: FS_BOOL.
	// Remarks: Sets the callback function called to notify the plug-in that the specified property page is selected.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL BCGPreTranslateMessage(void* pWnd, void* pMsg);
	
	//************************************
	// Function:  AddPropertySheetPage2
	// Param[in]: item				The input back stage view item object.
	// Param[in]: csPageName		The input name of the property sheet page.
	// Param[in]: CreateProc		The callback function is called to notify the plug-in to create the dialog when the back stage view is shown.
	// Param[in]: DestoryProc		The callback function is called to notify the plug-in to destroy the dialog when the back stage view is closed.
	// Param[in]: pClientData		The user-supplied data passed to the callback function.
	// Param[in]: csPageTitle		The input title of the property sheet page.
	// Param[in]: wsPDFBitmapName	The input bitmap name. That need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage.pdf.
	// Param[in]: nPos		        The position of the page.
	// Return: FS_BOOL.
	// Remarks: You can create your own property sheet page on the back stage view when it is shown. You can either add a dialog or a property sheet on 
	// the back stage view.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See:
	//************************************
	static FS_BOOL	 AddPropertySheetPage2(FR_RibbonBackStageViewItem item, FS_LPCSTR csPageName, FRRibbonBackstageCreateProc createProc, FRRibbonBackstageDestoryProc destoryProc, FS_LPVOID pClientData,
		FS_LPCWSTR csPageTitle, FS_LPCWSTR wsPDFBitmapName, FS_INT32 nPos);
	
	//************************************
	// Function:  EnableChangeHighLightImageColor
	// Param[in]: item				The input back stage view item object.
	// Param[in]: csPageName		The input name of the property sheet page.
	// Param[in]: bEnable		    If set true, that will enable the color of the icon is the same as the text color.
	// Return: void.
	// Remarks: The color of the icon is the same as the text color when the Item is selected or highlighted.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See:
	//************************************
	static void		EnableChangeHighLightImageColor(FR_RibbonBackStageViewItem item, FS_LPCSTR csPageName, FS_BOOL bEnable);

	//************************************
	// Function:  AddPropertySheetPage
	// Param[in]: item			The input back stage view item object.
	// Param[in]: lpsName		The input name of the property sheet page.
	// Param[in]: lpwsPageTitle	The input title of the property sheet page.
	// Param[in]: pBitmap		The input bitmap of the property sheet page.
	// Param[in]: nPos			The input position of the property sheet page.
	// Param[in]: createProc	The callback function is called to notify the plug-in to create the dialog when the back stage view is shown.
	// Param[in]: destroyProc	The callback function is called to notify the plug-in to destroy the dialog when the back stage view is closed.
	// Param[in]: pClientData	The user-supplied data passed to the callback function.
	// Param[in]: bChangeSkin	Whether need change skin.
	// Return: <a>TRUE</a> for success, otherwise not.
	// Remarks: You can create your own property sheet page on the back stage view when it is shown. You can either add a dialog or a property sheet on 
	// the back stage view.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Current function has been deprecated , so not recommend to use current function any more. User can use  FRRibbonBackStageViewItemAddPropertySheetPage2 function instead.
	//************************************
	static FS_BOOL	AddPropertySheetPage3(FR_RibbonBackStageViewItem item, FS_LPCSTR lpsName, FS_LPCWSTR lpwsPageTitle, FS_DIBitmap pBitmap, FS_INT32 nPos, FRRibbonBackstageCreateProc createProc, FRRibbonBackstageDestoryProc destroyProc, void* pClientData, FS_BOOL bChangeSkin);

	//************************************
	// Function:  AddPropertySheetPage4
	// Param[in]: item				The input back stage view item object.
	// Param[in]: csPageName		The input name of the property sheet page.
	// Param[in]: CreateProc		The callback function is called to notify the plug-in to create the dialog when the back stage view is shown.
	// Param[in]: DestoryProc		The callback function is called to notify the plug-in to destroy the dialog when the back stage view is closed.
	// Param[in]: pClientData		The user-supplied data passed to the callback function.
	// Param[in]: csPageTitle		The input title of the property sheet page.
	// Param[in]: wsPDFBitmapName	The input bitmap name. That need to match the bookmark item title of the file in FoxitReader\res\ribbon\ribbonimage.pdf.
	// Param[in]: nPos		        The position of the page.
	// Param[in]: bChangeSkin	    Whether need change skin.
	// Return: FS_BOOL.
	// Remarks: You can create your own property sheet page on the back stage view when it is shown. You can either add a dialog or a property sheet on 
	// the back stage view.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	// See:
	//************************************
	static FS_BOOL	 AddPropertySheetPage4(FR_RibbonBackStageViewItem item, FS_LPCSTR csPageName, FRRibbonBackstageCreateProc createProc, FRRibbonBackstageDestoryProc destoryProc, FS_LPVOID pClientData,
		FS_LPCWSTR csPageTitle, FS_LPCWSTR wsPDFBitmapName, FS_INT32 nPos, FS_BOOL bChangeSkin);

   //************************************
   // Function:  AddDialog2
   // Param[in]: item			The input back stage view item object.
   // Param[in]: createProc	The callback function is called to notify the plug-in to create the dialog when the back stage view is shown.
   // Param[in]: destroyProc	The callback function is called to notify the plug-in to destroy the dialog when the back stage view is closed.
   // Param[in]: pClientData	The user-supplied data passed to the callback function.
   // Param[in]: bChangeSkin	    Whether need change skin.
   // Return: <a>TRUE</a> for success, otherwise not.
   // Remarks: You can create your own dialog on the back stage view when it is shown. You can either add a dialog or a property sheet on 
   // the back stage view.
   // Notes: The function can only be used for Windows.
   // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
   // See:	
   //************************************
	static FS_BOOL AddDialog2(FR_RibbonBackStageViewItem item, FRRibbonBackstageCreateProc createProc, FRRibbonBackstageDestoryProc destroyProc, void* pClientData, FS_BOOL bChangeSkin);

   //************************************
   // Function:  SetPropertyPageShow
   // Param[in]: item			The input back stage view item object.
   // Param[in]: csPageName	    The input name of the page.
   // Param[in]: bShow	        TRUE: show the page.
   // Return: void
   // Remarks: Sets whether property page is displayed.
   // Notes: The function can only be used for Windows.
   // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
   // See:	
   //************************************
	static void SetPropertyPageShow(FR_RibbonBackStageViewItem item, FS_LPCSTR csPageName, FS_BOOL bShow);
};

class CFR_RibbonStyleButton_V5 //Internal use
{		
public:
	//************************************
	// Function:  SetImage
	// Param[in]: button	The input ribbon style button object.
	// Param[in]: pBitmap	The input icon of the ribbon style button.
	// Return: void
	// Remarks: Sets the icon of the ribbon style button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetImage(FR_RibbonStyleButton button, FS_DIBitmap pBitmap);


	//************************************
	// Function:  SetAlignStyle
	// Param[in]: button		The input ribbon style button object.
	// Param[in]: nAlignType	The input alignment type of the ribbon style button.
	// Return: void
	// Remarks: Sets the alignment type of the ribbon style button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetAlignStyle(FR_RibbonStyleButton button, FRRibbonStyleTextAlignType nAlignType);


	//************************************
	// Function:  SetImageSide
	// Param[in]: button		The input ribbon style button object.
	// Param[in]: nImageSide	The input icon side of the ribbon style button.
	// Return: void
	// Remarks: Sets the icon side of the ribbon style button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetImageSide(FR_RibbonStyleButton button, FRRibbonStyleImageSide nImageSide);

	
	//************************************
	// Function:  SetFlatStyle
	// Param[in]: button		The input ribbon style button object.
	// Param[in]: nFlatStyle	The input flat style of the ribbon style button.
	// Return: void
	// Remarks: Sets the flat style of the ribbon style button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetFlatStyle(FR_RibbonStyleButton button, FRRibbonStyleFlatType nFlatStyle);

	
	//************************************
	// Function:  SetVertMargin
	// Param[in]: button		The input ribbon style button object.
	// Param[in]: nVerMargin	The input margin in the vertical direction.
	// Return: void
	// Remarks: Sets the margin in the vertical direction.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetVertMargin(FR_RibbonStyleButton button, FS_INT32 nVerMargin);


	//************************************
	// Function:  GetMFCButton
	// Param[in]: button	The input ribbon style button object.
	// Return: The pointer to the MFC class.
	// Remarks: Gets the pointer of mfc control by FRRibbonBackStageViewItemModifiedToRibbonStyleButton to attach.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FRRibbonBackStageViewItemModifiedToRibbonStyleButton
	// Deprecated: Internal use.
	//************************************
	static void* GetMFCButton(FR_RibbonStyleButton button);


	//************************************
	// Function:  Release
	// Param[in]: button	The input ribbon style button object.
	// Return: void
	// Remarks: Releases the ribbon style button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void Release(FR_RibbonStyleButton button);

	//************************************
	// Function:  SetImage2
	// Param[in]: button	The input ribbon style button object.
	// Param[in]: pBitmap	The input icon of the ribbon style button.
	// Param[in]: cx		The width of the bitmap when the DPI is 100%. The default value is 32.
	// Param[in]: cy		The height of the bitmap when the DPI is 100%. The default value is 32.
	// Return: void
	// Remarks: Sets the icon of the ribbon style button.It only support size of 24*24 or 32*32.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetImage2(FR_RibbonStyleButton button, FS_DIBitmap pBitmap, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  SetImage2
	// Param[in]: button	The input ribbon style button object.
	// Param[in]: wsBitmapName	 For loading PDF images, the name is retrieved from the BOOKMARK of the PDF file：FoxitReader\res\ribbon\ribbonimage.pdf
	// Param[in]: cx		The width of the bitmap when the DPI is 100%. The default value is 32.
	// Param[in]: cy		The height of the bitmap when the DPI is 100%. The default value is 32.
	// Return: void
	// Remarks: Sets the icon of the ribbon style static box.It only support size of 24*24 or 32*32.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetImage3(FR_RibbonStyleButton button, FS_WideString wsBitmapName, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  SetToolTip
	// Param[in]: button		The input ribbon style button object.
	// Param[in]: wsTooltip	    The input tooltip of the style button.
	// Return: void.
	// Remarks: Sets the tooltip of the function button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetTooltip(FR_RibbonStyleButton button, FS_WideString wsTooltip);
	
	//************************************
	// Function:  SetMarkStatus
	// Param[in]: button		The input ribbon style button object.
	// Param[in]: bStatus	    TRUE: selected
	// Return: void.
	// Remarks: Set whether the button is selected
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetMarkStatus(FR_RibbonStyleButton button, FS_BOOL bStatus);

	//************************************
	// Function:  SetDescription
	// Param[in]: button		    The input ribbon style button object.
	// Param[in]: wsDescription	    The description of the ribbon button.
	// Return: void.
	// Remarks: Set description of the function button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetDescription(FR_RibbonStyleButton button, FS_WideString wsDescription);
	
	//************************************
	// Function:  EnableHelpLink
	// Param[in]: button		    The input ribbon style button object.
	// Param[in]: bEnable	        If the button can be enable.
	// Param[in]: bsButtonName	    Set the tooltip info.
	// Return: void.
	// Remarks: Set Tell Me More in Tooltip. BSButtonName can be used with the button name of the Ribbon
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void EnableHelpLink(FR_RibbonStyleButton button, FS_BOOL bEnable, FS_ByteString bsButtonName);

	//************************************
	// Function:  SetFontStyle
	// Param[in]: button		    The input ribbon style button object.
	// Param[in]: nFontSize			The input font size of the ribbon style static box.
	// Param[in]: bBold				TRUE if the ribbon style static box uses the bold, otherwise not.
	// Param[in]: bItalic			TRUE if the ribbon style static box uses the italic, otherwise not.
	// Param[in]: bUnderlined		TRUE if the ribbon style static box is underlined, otherwise not.
	// Param[in]: bStrikethrough	TRUE if the ribbon style static box is stricken through, otherwise not.
	// Return: void
	// Remarks: Sets the font and the style of the ribbon style button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetFontStyle(FR_RibbonStyleButton button, FS_INT32 nFontSize, FS_BOOL bBold, FS_BOOL bItalic, FS_BOOL bUnderlined, FS_BOOL bStrikethrough);

	//************************************
	// Function:  SetBorderColor
	// Param[in]: button		    The input ribbon style button object.
	// Param[in]: clrDefault	    Set the default color.
	// Param[in]: clrHighlight	    Set the highlight color.
	// Param[in]: clrPressed	    Set the pressed color.
	// Return: void.
	// Remarks: Set border color of the button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetBorderColor(FR_RibbonStyleButton button, FS_COLORREF clrDefault, FS_COLORREF clrHighlight, FS_COLORREF clrPressed);

	//************************************
	// Function:  SetBackgroundColor
	// Param[in]: button		    The input ribbon style button object.
	// Param[in]: clrDefault	    Set the default background color.
	// Param[in]: clrHighlight	    Set the highlight color.
	// Param[in]: clrPressed	    Set the pressed color.
	// Param[in]: clrDisable	    Set the disable color.
	// Return: void.
	// Remarks: Set background color of the button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetBackgroundColor(FR_RibbonStyleButton button, FS_COLORREF clrDefault, FS_COLORREF clrHighlight, FS_COLORREF clrPressed, FS_COLORREF clrDisable);

	//************************************
	// Function:  SetTextColor
	// Param[in]: button		    The input ribbon style button object.
	// Param[in]: clrDefault	    Set the default background color.
	// Param[in]: clrHighlight	    Set the highlight color.
	// Return: void.
	// Remarks: Set text color of the button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetTextColor(FR_RibbonStyleButton button, FS_COLORREF clrDefault, FS_COLORREF clrHighlight);

	//************************************
	// Function:  SetRoundRadius
	// Param[in]: button		    The input ribbon style button object.
	// Param[in]: ptRoundRadius	    Set the round radius.
	// Return: void.
	// Remarks: Set round radius of the button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetRoundRadius(FR_RibbonStyleButton button, FS_DevicePoint ptRoundRadius);

	//************************************
	// Function:  SetTransparent
	// Param[in]: button		    The input ribbon style button object.
	// Param[in]: bTransparent	    TRUE: Need to set transparent.
	// Return: void.
	// Remarks: Set transparent of the button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetTransparent(FR_RibbonStyleButton button, FS_BOOL bTransparent);

	//************************************
	// Function:  SetFocusColor
	// Param[in]: button		    The input ribbon style button object.
	// Param[in]: clrFocus			Set the focus color.
	// Return: void.
	// Remarks: Set focus color of the button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetFocusColor(FR_RibbonStyleButton button, FS_COLORREF clrFocus);

	//************************************
	// Function:  SetImageReplaceColor
	// Param[in]: ribbonElement	      The input ribbon element object.
	// Param[in]: clrStroke			  The input stroke color.
	// Param[in]: clrFill	          The input fill color.
	// Param[in]: bReplaceBoth	      If need replace when both have stroke and fill color. Default is false.
	// Param[in]: bRedraw	          If need redraw.	
	// Return: void
	// Remarks: Replace the pdf image name.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0	
	// Deprecated: Internal use.
	//************************************
	static	void SetImageReplaceColor(FR_RibbonStyleButton button, FS_COLORREF clrStroke, FS_COLORREF clrFill, FS_BOOL bReplaceBoth, FS_BOOL bRedraw);

	//************************************
	// Function:  SetDefaultStyle
	// Param[in]: button		    The input ribbon style button object.
	// Param[in]: option			The input button style option.
	// Return: void.
	// Remarks: Set the default style.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static  void SetDefaultStyle(FR_RibbonStyleButton button, FR_ButtonStyleOption option);

	//************************************
	// Function:  DisableHighContrastThemeImage
	// Param[in]: button		    The input ribbon style button object.
	// Return: void
	// Remarks: In high contrast mode, whether to change the icon to a high contrast color.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	DisableHighContrastThemeImage(FR_RibbonStyleButton button);
};

class CFR_RibbonStyleListBox_V5 //Internal use
{
public:
	//************************************
	// Function:  AddImage
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: bitmap	The input 16*16 icon list of the ribbon style list box.
	// Return: The count of the icons.
	// Remarks: Adds a 16*16 icon list to the ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 AddImage(FR_RibbonStyleListBox listBox, FS_DIBitmap bitmap);


	//************************************
	// Function:  AddString
	// Param[in]: listBox		The input ribbon style list box object.
	// Param[in]: lpwsItem		The input string separated by '\n'. For example1, "Foxit Reader\nThe Best PDF Reader\nOne of the most popular PDF reader",
	// the string item will show two lines and the tooltip will be "One of the most popular PDF reader".For example2, "Foxit Reader"the string item will 
	// show one lines and the tooltip will be "Foxit Reader".	
	// Param[in]: nImageIndex	The specified index of the icon list.
	// Return: The index of the string item.
	// Remarks: Adds a new string item to the ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 AddString(FR_RibbonStyleListBox listBox, FS_LPCWSTR lpwsItem, FS_INT32 nImageIndex);


	//************************************
	// Function:  AddCaption
	// Param[in]: listBox		The input ribbon style list box object.
	// Param[in]: lpwsCaption	The input caption of the ribbon style list box.
	// Return: void
	// Remarks: Adds the  caption of the ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	AddCaption(FR_RibbonStyleListBox listBox, FS_LPCWSTR lpwsCaption);


	//************************************
	// Function:  DeleteString
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: nIndex	The specified index.
	// Return: The index of the currently selected item.
	// Remarks: Deletes the string item by index.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 DeleteString(FR_RibbonStyleListBox listBox, FS_UINT nIndex);


	//************************************
	// Function:  InsertString
	// Param[in]: listBox		The input ribbon style list box object.
	// Param[in]: nIndex		Specifies the zero-based index of the position to insert the string. If this parameter is �C1, the string is added to the end of the list.
	// Param[in]: lpwsItem		The input string separated by '\n'. For example, "Foxit Reader\nThe Best PDF Reader\nOne of the most popular PDF reader",
	// the string item will show two lines and the tooltip will be "One of the most popular PDF reader".
	// Param[in]: nImageIndex	The specified index of the icon list.
	// Return: The zero-based index of the position at which the string was inserted. 
	// Remarks: Inserts a string into the ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 InsertString(FR_RibbonStyleListBox listBox, FS_INT32 nIndex, FS_LPCWSTR lpwsItem, FS_INT32 nImageIndex);


	//************************************
	// Function:  GetItemData
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: nIndex	The specified index.
	// Return: The item data of the  ribbon style list box.
	// Remarks: Gets the item data of the  ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_DWORD_PTR	GetItemData(FR_RibbonStyleListBox listBox, FS_INT32 nIndex);


	//************************************
	// Function:  SetItemData
	// Param[in]: listBox		The input ribbon style list box object.
	// Param[in]: nIndex		The specified index.
	// Param[in]: dwItemData	The input item data.
	// Return: LB_ERR if an error occurs.
	// Remarks: Sets a 32-bit value associated with the specified item in a ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 SetItemData(FR_RibbonStyleListBox listBox, FS_INT32 nIndex, FS_DWORD_PTR dwItemData);


	//************************************
	// Function:  GetMFCListBox
	// Param[in]: listBox	The input ribbon style list box object.
	// Return: The pointer to the MFC class.
	// Remarks: Gets the pointer to the MFC class.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void* GetMFCListBox(FR_RibbonStyleListBox listBox);


	//************************************
	// Function:  Release
	// Param[in]: listBox	The input ribbon style list box object.
	// Return: void
	// Remarks: Releases the ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void Release(FR_RibbonStyleListBox listBox);

	//************************************
	// Function:  AddImage2
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: bitmap	The input 16*16 icon list of the ribbon style list box.
	// Param[in]: cx		The width of the bitmap when the DPI is 100%. The default value is 32.
	// Param[in]: cy		The height of the bitmap when the DPI is 100%. The default value is 32.
	// Return: The count of the icons.
	// Remarks: Adds a 16*16 icon list to the ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 AddImage2(FR_RibbonStyleListBox listBox, FS_DIBitmap bitmap, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  EnablePins
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: bEnable	TRUE means enable the pin buttons, otherwise not.
	// Return: void.
	// Remarks: Whether to enable the pin buttons or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void EnablePins(FR_RibbonStyleListBox listBox, FS_BOOL bEnable);

	//************************************
	// Function:  HasPins
	// Param[in]: listBox	The input ribbon style list box object.
	// Return: TRUE means the ribbon style list box has pins, otherwise not.
	// Remarks: Whether the ribbon style list box has pins or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL HasPins(FR_RibbonStyleListBox listBox);

	//************************************
	// Function:  SetItemPinned
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: nIndex	The specified index of the item.
	// Param[in]: nPin		The status of the pin, 0 for not pinned, 1 for pinned, 2 for not display the pin button.
	// Param[in]: bRedraw	Whether to redraw the list box or not.
	// Return: void.
	// Remarks: Sets the status of the pin of the specified item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetItemPinned(FR_RibbonStyleListBox listBox, FS_INT32 nIndex, FS_INT32 nPin, FS_BOOL bRedraw);

	//************************************
	// Function:  GetItemPinnedState
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: nIndex	The specified index of the item.
	// Return: The status of the pin, 0 for not pinned, 1 for pinned, 2 for not display the pin button.
	// Remarks: Gets the status of the pin of the specified item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 GetItemPinnedState(FR_RibbonStyleListBox listBox, FS_INT32 nIndex);

	//************************************
	// Function:  IsSeparatorItem
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: nIndex	The specified index of the item.
	// Return: TRUE if the item is a separator, otherwise not.
	// Remarks: Checks whether the item is a caption or not.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsSeparatorItem(FR_RibbonStyleListBox listBox, FS_INT32 nIndex);

	//************************************
	// Function:  RedrawList
	// Param[in]: listBox	The input ribbon style list box object.
	// Return: void.
	// Remarks: Redraws the ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void RedrawList(FR_RibbonStyleListBox listBox);

	//************************************
	// Function:  SetClickItemProc
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: proc		A callback for Ribbon style list box.
	// Return: void.
	// Remarks: Sets the callback which is called when the item of the Ribbon style list box is clicked.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetClickItemProc(FR_RibbonStyleListBox listBox, FRClickItemProc proc);

	//************************************
	// Function:  SetClickPinProc
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: proc		A callback for Ribbon style list box.
	// Return: void.
	// Remarks: Sets the callback which is called when the item pin button of the Ribbon style list box is clicked.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetClickPinProc(FR_RibbonStyleListBox listBox, FRClickPinProc proc);

	//************************************
	// Function:  SetClientData
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: pData		The input client data.
	// Param[in]: callback	The callback will be invoked to free the client data.
	// Return: void.
	// Remarks: Sets the callback to free data.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetClientData(FR_RibbonStyleListBox listBox, void* pData, FRFreeDataProc callback);

	//************************************
	// Function:  Clear
	// Param[in]: listBox	The input ribbon style list box object.
	// Return: void.
	// Remarks: Clears all items of ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void Clear(FR_RibbonStyleListBox listBox);

	//************************************
	// Function:  AddImage3
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: bitmapName The input bitmap name. It is retrieved from the BOOKMARK of the PDF file：FoxitReader\res\ribbon\ribbonimage.pdf
	// Param[in]: cx		The width of the bitmap when the DPI is 100%. The default value is 32.
	// Param[in]: cy		The height of the bitmap when the DPI is 100%. The default value is 32.
	// Return: The count of the icons.
	// Remarks: Adds a 16*16 icon list to the ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 AddImage3(FR_RibbonStyleListBox listBox, FS_LPCWSTR bitmapName, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  Enable
	// Param[in]: listBox	The input ribbon style list box object.
	// Param[in]: nIndex    The specified index of the item.
	// Param[in]: bEnabled	If enable the item.
	// Param[in]: bRedraw	If need redraw the item.
	// Return: The count of the icons.
	// Remarks: Adds a 16*16 icon list to the ribbon style list box.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	Enable(FR_RibbonStyleListBox listBox, FS_INT32 nIndex, FS_BOOL bEnabled, FS_BOOL bRedraw);

	//************************************
	// Function:  DisableHighContrastThemeImage
	// Param[in]: listBox	The input ribbon style list box object.
	// Return: void
	// Remarks: In high contrast mode, whether to change the icon to a high contrast color.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	DisableHighContrastThemeImage(FR_RibbonStyleListBox listBox);
};

class CFR_RibbonStyleStatic_V5 //Internal use
{
public:
	//************************************
	// Function:  SetImage
	// Param[in]: stcObj	The input ribbon style static text.
	// Param[in]: pBitmap	The input icon of the ribbon style static text.
	// Return: void
	// Remarks: Sets the icon of the ribbon style static control.It only support size of 24*24 or 32*32.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetImage(FR_RibbonStyleStatic stcObj, FS_DIBitmap pBitmap);


	//************************************
	// Function:  GetMFCStatic
	// Param[in]: stcObj	The input ribbon style static control object., it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.	
	// Return: The pointer to the corresponding MFC class.
	// Remarks: Gets the pointer to the corresponding MFC class.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void* GetMFCStatic(FR_RibbonStyleStatic stcObj);


	//************************************
	// Function:  SetFontStyle
	// Param[in]: stcObj			The input ribbon style static text.
	// Param[in]: nFontSize			The input font size of the ribbon style static text.
	// Param[in]: bBold				TRUE if the ribbon style static box uses the bold, otherwise not.
	// Param[in]: bItalic			TRUE if the ribbon style static box uses the italic, otherwise not.
	// Param[in]: bUnderlined		TRUE if the ribbon style static box is underlined, otherwise not.
	// Param[in]: bStrikethrough	TRUE if the ribbon style static box is stricken through, otherwise not.
	// Return: void
	// Remarks: Sets the font and the style of the ribbon style static text.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetFontStyle(FR_RibbonStyleStatic stcObj, FS_INT32 nFontSize, FS_BOOL bBold, FS_BOOL bItalic, FS_BOOL bUnderlined, FS_BOOL bStrikethrough);


	//************************************
	// Function:  SetTextColor
	// Param[in]: stcObj		The input ribbon style static text.
	// Param[in]: dwTextColor	The input color value.
	// Return: void
	// Remarks: Sets the color of the ribbon style static text.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetTextColor(FR_RibbonStyleStatic stcObj, FS_DWORD dwTextColor);


	//************************************
	// Function:  SetBackgroundColor
	// Param[in]: stcObj	The input ribbon style static text.
	// Param[in]: dwBgColor	The input background color value.
	// Return: void
	// Remarks: Sets the background color of the ribbon style static text.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetBackgroundColor(FR_RibbonStyleStatic stcObj, FS_DWORD dwBgColor);


	//************************************
	// Function:  SetTextDrawFormat
	// Param[in]: stcObj	The input ribbon style static text.
	// Param[in]: nFormat	The input format. References to MFC description such as DT_BOTTOM.
	// Return: void
	// Remarks: Sets the text format of the ribbon style static text.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetTextDrawFormat(FR_RibbonStyleStatic stcObj, FS_UINT nFormat);


	//************************************
	// Function:  Release
	// Param[in]: stcObj	The input ribbon style static text.
	// Return: void
	// Remarks: Releases the ribbon style static text.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	Release(FR_RibbonStyleStatic stcObj);

	//************************************
	// Function:  SetImage2
	// Param[in]: stcObj	The input ribbon style static text.
	// Param[in]: pBitmap	The input icon of the ribbon style static text.
	// Param[in]: cx		The width of the bitmap when the DPI is 100%. The default value is 32.
	// Param[in]: cy		The height of the bitmap when the DPI is 100%. The default value is 32.
	// Return: void
	// Remarks: Sets the icon of the ribbon style static text. It only support size of 24*24 or 32*32.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetImage2(FR_RibbonStyleStatic stcObj, FS_DIBitmap pBitmap, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  SetImage3
	// Param[in]: stcObj	The input ribbon style static text.
	// Param[in]: wsBitmapName	 For loading PDF images, the name is retrieved from the BOOKMARK of the PDF file：FoxitReader\res\ribbon\ribbonimage.pdf
	// Param[in]: cx		The width of the bitmap when the DPI is 100%. The default value is 32.
	// Param[in]: cy		The height of the bitmap when the DPI is 100%. The default value is 32.
	// Return: void
	// Remarks: Sets the icon of the ribbon style static text.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 3.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetImage3(FR_RibbonStyleStatic stcObj, FS_WideString wsBitmapName, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  SetDescription
	// Param[in]: stcObj		    The input ribbon style static text.
	// Param[in]: wsDescription	    The description of the static text.
	// Return: void.
	// Remarks: Set description of the static control.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetDescription(FR_RibbonStyleStatic stcObj, FS_LPCWSTR wsDescription);

	//************************************
	// Function:  EnableHelpLink
	// Param[in]: stcObj		    The input ribbon style static text.
	// Param[in]: bEnable	        If the static box can be enable.
	// Param[in]: bsButtonName	    Set the tooltip info.
	// Return: void.
	// Remarks: Set Tell Me More in Tooltip. BSButtonName can be used with the button name of the Ribbon.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void EnableHelpLink(FR_RibbonStyleStatic stcObj, FS_BOOL bEnable, FS_LPCSTR bsButtonName);

	//************************************
	// Function:  SetTooltip
	// Param[in]: stcObj		    The input ribbon style static text.
	// Param[in]: wsTooltip	        Set the tooltip info.	
	// Return: void.
	// Remarks: Set tooltip of the style static text.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void		SetTooltip(FR_RibbonStyleStatic stcObj, FS_LPCWSTR wsTooltip);

	//************************************
	// Function:  SetTextColorName
	// Param[in]: stcObj		    The input ribbon style static text.
	// Param[in]: wsColorName	    The input color name, it can get from starship\lib\Skins\Ribbon\Black\Black.xml.	
	// Return: void.
	// Remarks: Set text color name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void	 SetTextColorName(FR_RibbonStyleStatic stcObj, FS_LPCWSTR wsColorName);

	//************************************
	// Function:  DisableHighContrastThemeImage
	// Param[in]: stcObj	The input ribbon style static text.
	// Return: void
	// Remarks: In high contrast mode, whether to change the icon to a high contrast color.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	DisableHighContrastThemeImage(FR_RibbonStyleStatic stcObj);
};

class CFR_FormatTools_V5 
{
public:
    //************************************
    // Function:  Get
    // Return: The format tool object.
    // Remarks: Gets the format tool object. The format tool is used to set the format of the PDF object and text.
    // Notes: You can see it on the right panel and do somethings like font name, font size, color and so on in it.
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // Deprecated: Internal use.
    //************************************
    static FR_FormatTools Get();

    //************************************
    // Function:  SetEvent
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: callbacks		The callback functions. They are called by Foxit Reader when the format tools events occur.
    // Return: The handle of  the format tools event. Releases it by <a>FRFormatToolsReleaseEvent</a>.
    // Remarks: Sets the callback functions that are called by Foxit Reader when the format tools events occur.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:FRFormatToolsReleaseEvent
    // Deprecated: Internal use.
    //************************************
    static FS_LPVOID SetEvent(FR_FormatTools formatTools, FR_FormatToolCallbacks callbacks);

    //************************************
    // Function:  SetFontName
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: lpwsFontName	The input font name.
    // Return: void
    // Remarks: Sets the font name of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetFontName(FR_FormatTools formatTools, FS_LPCWSTR lpwsFontName);

    //************************************
    // Function:  SetFontNameFirst
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: bFirst		Indicates whether you set the font name the first time.
    // Return: void
    // Remarks: Sets whether you set the font name the first time or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // Deprecated: Internal use.
    //************************************
    static void SetFontNameFirst(FR_FormatTools formatTools, FS_BOOL bFirst);

    //************************************
    // Function:  SetFontSize
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: flFontSize	The input font size.
    // Return: void
    // Remarks: Sets the font size of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetFontSize(FR_FormatTools formatTools, FS_FLOAT flFontSize);

    //************************************
    // Function:  SetFontSizeFirst
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: bFirst		Indicates whether you set the font size the first time.
    // Return: void
    // Remarks: Sets whether you set the font size the first time or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // Deprecated: Internal use.
    //************************************
    static void SetFontSizeFirst(FR_FormatTools formatTools, FS_BOOL bFirst);

    //************************************
    // Function:  SetTextColor
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: textColor		The input color value of the text.
    // Return: void
    // Remarks: Sets the text color of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetTextColor(FR_FormatTools formatTools, FS_COLORREF textColor);

    //************************************
    // Function:  SetLineColor
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: lineColor		The input line color.
    // Param[in]: bTransparent	Indicates whether the line is transparent.
    // Return: void
    // Remarks: Sets the line color of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetLineColor(FR_FormatTools formatTools, FS_COLORREF lineColor, FS_BOOL bTransparent);

    //************************************
    // Function:  SetFillColor
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: fillColor		The input fill color.
    // Param[in]: bTransparent	Indicates whether the line is transparent.
    // Return: void
    // Remarks: Sets the fill color of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetFillColor(FR_FormatTools formatTools, FS_COLORREF fillColor, FS_BOOL bTransparent);

    //************************************
    // Function:  SetBold
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: bBold			Indicates whether uses the bold.
    // Param[in]: bEnabled		Indicates whether the bold setting button is enabled or not.
    // Return:    void
    // Remarks: Sets whether uses the bold and whether the bold setting button is enabled.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetBold(FR_FormatTools formatTools, FS_BOOL bBold, FS_BOOL bEnabled);

    //************************************
    // Function:  SetItalic
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: bItalic		Indicates whether uses the italic.
    // Param[in]: bEnabled		Indicates whether the italic setting button is enabled or not.
    // Return: void
    // Remarks: Sets whether uses the italic and whether the italic setting button is enabled.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetItalic(FR_FormatTools formatTools, FS_BOOL bItalic, FS_BOOL bEnabled);

    //************************************
    // Function:  SetAlign
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: dwAlign		The input alignment. see in <a>FRFORMAT_ALIGN</a>.
    // Return: void
    // Remarks: Sets the alignment of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetAlign(FR_FormatTools formatTools, FS_DWORD dwAlign);

    //************************************
    // Function:  SetCharSpace
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: flSpace		The input character space.
    // Return: void
    // Remarks: Sets the character space of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetCharSpace(FR_FormatTools formatTools, FS_FLOAT flSpace);

    //************************************
    // Function:  SetCharHorzScale
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: nScale		The input character horizon scale (for example:100 is 100%).
    // Return: void
    // Remarks: Sets the character horizon scale of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetCharHorzScale(FR_FormatTools formatTools, FS_INT32 nScale);

    //************************************
    // Function:  SetLineLeading
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: flLineLeading Indicates whether uses the leading line setting.
    // Return: void
    // Remarks: Sets whether uses the leading line setting.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetLineLeading(FR_FormatTools formatTools, FS_FLOAT flLineLeading);

    //************************************
    // Function:  SetSuperScript
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: bSuperScript	Indicates whether uses the superscript setting.
    // Return: void
    // Remarks: Sets whether uses the superscript setting.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetSuperScript(FR_FormatTools formatTools, FS_BOOL bSuperScript);

    //************************************
    // Function:  SetSubScript
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: bSubScript	Indicates whether uses the subscript setting.
    // Return: void
    // Remarks: Sets whether uses the subscript setting.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetSubScript(FR_FormatTools formatTools, FS_BOOL bSubScript);

    //************************************
    // Function:  SetUnderline
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: bUnderline	Indicates whether uses the underline setting.
    // Return: void
    // Remarks: Sets whether uses the underline setting.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetUnderline(FR_FormatTools formatTools, FS_BOOL bUnderline);

    //************************************
    // Function:  SetCross
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: bCross		Indicates whether uses the cross setting.
    // Return: void
    // Remarks: Sets whether uses the cross setting.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetCross(FR_FormatTools formatTools, FS_BOOL bCross);

    //************************************
    // Function:  SetWordSpace
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: fWordSpace	Indicates whether uses the word space setting.
    // Return: void
    // Remarks: Sets the word space of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetWordSpace(FR_FormatTools formatTools, FS_FLOAT fWordSpace);

    //************************************
    // Function:  GetFontName
    // Param[in]: formatTools	The input format tools object.
    // Param[out]: outFontName	It receives the font name.
    // Return: void
    // Remarks: Gets the font name of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void GetFontName(FR_FormatTools formatTools, FS_WideString* outFontName);

    //************************************
    // Function:  GetFontSize
    // Param[in]: formatTools	The input format tools object.
    // Return: The font size.
    // Remarks: Gets the font size of the format fools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_FLOAT GetFontSize(FR_FormatTools formatTools);

    //************************************
    // Function:  GetTextColor
    // Param[in]: formatTools	The input format tools object.
    // Param[out]: outTextColor	It receives the text color.
    // Return: <a>TRUE</a> for success, otherwise not.
    // Remarks: Gets the text color of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL GetTextColor(FR_FormatTools formatTools, FS_COLORREF* outTextColor);

    //************************************
    // Function:  GetLineColor
    // Param[in]: formatTools	The input format tools object.
    // Param[out]: outLineColor	It receives the line color.
    // Return: <a>TRUE</a> for success, otherwise not.
    // Remarks: Gets the line color of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL GetLineColor(FR_FormatTools formatTools, FS_COLORREF* outLineColor);

    //************************************
    // Function:  GetFillColor
    // Param[in]: formatTools	The input format tools object.
    // Param[out]: outFillColor	It receives the fill color.
    // Return: <a>TRUE</a> for success, otherwise not.
    // Remarks: Gets fill color of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL GetFillColor(FR_FormatTools formatTools, FS_COLORREF* outFillColor);

    //************************************
    // Function:  GetAlign
    // Param[in]: formatTools	The input format tools object.
    // Return: The alignment of the format tools.
    // Remarks: Gets the alignment of the format tools,see in <a>FRFORMAT_ALIGN</a>.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_DWORD GetAlign(FR_FormatTools formatTools);

    //************************************
    // Function:  GetCharSpace
    // Param[in]: formatTools	The input format tools object.
    // Return: The character space of the format tools.
    // Remarks: Gets the character space of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_FLOAT GetCharSpace(FR_FormatTools formatTools);

    //************************************
    // Function:  GetCharHorzScale
    // Param[in]: formatTools	The input format tools object.
    // Return: The character horizon scale of the format tools.
    // Remarks: Gets the character horizon scale of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_INT32 GetCharHorzScale(FR_FormatTools formatTools);

    //************************************
    // Function:  GetLineLeading
    // Param[in]: formatTools	The input format tools object.
    // Return: <a>TRUE</a> if uses the leading line setting, otherwise not.
    // Remarks: Checks whether uses the leading line setting or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_FLOAT GetLineLeading(FR_FormatTools formatTools);

    //************************************
    // Function:  GetUnderline
    // Param[in]: formatTools	The input format tools object.
    // Return: <a>TRUE</a> if uses the underline setting, otherwise not.
    // Remarks: Checks whether uses the underline line setting or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL GetUnderline(FR_FormatTools formatTools);

    //************************************
    // Function:  GetCross
    // Param[in]: formatTools	The input format tools object.
    // Return:  <a>TRUE</a> if uses the cross setting, otherwise not.
    // Remarks: Checks whether uses the cross setting or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL GetCross(FR_FormatTools formatTools);

    //************************************
    // Function:  GetSuperScript
    // Param[in]: formatTools	The input format tools object.
    // Return: <a>TRUE</a> if uses the superscript setting, otherwise not.
    // Remarks: Checks whether uses the superscript setting or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL GetSuperScript(FR_FormatTools formatTools);

    //************************************
    // Function:  GetSubScript
    // Param[in]: formatTools	The input format tools object.
    // Return: <a>TRUE</a> if uses the subscript setting, otherwise not.
    // Remarks: Checks whether uses the subscript setting or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL GetSubScript(FR_FormatTools formatTools);

    //************************************
    // Function:  IsBold
    // Param[in]: formatTools	The input format tools object.
    // Return: <a>TRUE</a> if uses the bold setting, otherwise not.
    // Remarks: Checks whether uses the bold setting or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL IsBold(FR_FormatTools formatTools);

    //************************************
    // Function:  IsItalic
    // Param[in]: formatTools	The input format tools object.
    // Return: <a>TRUE</a> if uses the italic setting, otherwise not.
    // Remarks: Checks whether uses the italic setting or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL IsItalic(FR_FormatTools formatTools);

    //************************************
    // Function:  GetWordSpace
    // Param[in]: formatTools	The input format tools object.
    // Return: The word space.
    // Remarks: Gets the word space of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_FLOAT	GetWordSpace(FR_FormatTools formatTools);


    //************************************
    // Function:  IsVisibled
    // Param[in]: formatTools	The input format tools object.
    // Return: <a>TRUE</a> if the format tools are visible, otherwise not.
    // Remarks: Checks whether the format tools are visible or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL IsVisibled(FR_FormatTools formatTools);

    //************************************
    // Function:  Show
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: bShow			Sets TRUE to show the format tools and sets FALSE to hide it.
    // Param[in]: eCateType		Sets the type of format to be operated.
    // Return: void
    // Remarks: Sets to show or hide the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void Show(FR_FormatTools formatTools, FS_BOOL bShow, FRFormatToolContextCategoryType eCateType);

    //************************************
    // Function:  IsEnabled
    // Param[in]: formatTools	The input format tools object.
    // Return: <a>TRUE</a> if the format tools is enabled, otherwise not.
    // Remarks: Checks whether the format tools is enabled or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL IsEnabled(FR_FormatTools formatTools);

    //************************************
    // Function:  Enable
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: bEnable		Sets TRUE to enable the format tools, otherwise not.
    // Return: void
    // Remarks: Sets to enable the format tools or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void Enable(FR_FormatTools formatTools, FS_BOOL bEnable);

    //************************************
    // Function:  IsButtonVisibled
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: nID			The specified ID.
    // Return: <a>TRUE</a> if the button is visible, otherwise not.
    // Remarks: Checks whether the specified button is visible or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL IsButtonVisibled(FR_FormatTools formatTools, FS_INT32 nID);

    //************************************
    // Function:  HideButton
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: nID			The specified ID.
    // Param[in]: bHide			Sets TRUE to hide the specified ID, otherwise not.
    // Return: void
    // Remarks: Sets to hide the specified ID or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void HideButton(FR_FormatTools formatTools, FS_INT32 nID, FS_BOOL bHide);

    //************************************
    // Function:  IsButtonEnabled
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: nID			The specified ID.
    // Return: <a>TRUE</a> if the button is enabled, otherwise not.
    // Remarks: Checks whether the specified button is enabled or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL IsButtonEnabled(FR_FormatTools formatTools,  FS_INT32 nID);

    //************************************
    // Function:  EnableButton
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: nID			The specified ID.
    // Param[in]: bEnabled		Sets TRUE to enable the button, otherwise not.
    // Return: void
    // Remarks: Sets to enable the specified button or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void EnableButton(FR_FormatTools formatTools, FS_INT32 nID, FS_BOOL bEnabled);

    //************************************
    // Function:  SetOwnerFontNameArr
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: array			The input font name array.
    // Return: void
    // Remarks: Sets the owner font names except for the system font name.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetOwnerFontNameArr(FR_FormatTools formatTools, FS_WideStringArray array);

    //************************************
    // Function:  CleanOwnerFontNameArr
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: array			The input font name array.
    // Return: void
    // Remarks: Cleans the owner font names.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See: FRFormatToolsSetOwnerFontNameArr
    // Deprecated: Internal use.
    //************************************
    static void CleanOwnerFontNameArr(FR_FormatTools formatTools, FS_WideStringArray array);

    //************************************
    // Function:  FindFontName
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: lpwsFontName	The specified font name.
    // Return: The index of the font name.
    // Remarks: Get the index of the specified font name.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_INT32 FindFontName(FR_FormatTools formatTools, FS_LPCWSTR lpwsFontName);

    //************************************
    // Function:  CountFontList
    // Param[in]: formatTools	The input format tools object.
    // Return: The count of the font.
    // Remarks: Gets the count of the font.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_INT32	CountFontList(FR_FormatTools formatTools);

    //************************************
    // Function:  GetFontListItem
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: nIndex		The specified index.
    // Param[out]: outItemName	It receives the font name.
    // Return: void
    // Remarks: Gets the font name by index.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void GetFontListItem(FR_FormatTools formatTools, FS_INT32 nIndex, FS_WideString* outItemName);


    //************************************
    // Function:  SetFormatContextTitle
    // Param[in]: formatTools		The input format tools object.
    // Param[in]: lpwsContextTitle	The input title of the format context category.
    // Param[in]: eCateType			Sets the type of format to be operated.
    // Return: void
    // Remarks: Sets the title of the format context category. This interface is valid in ribbon mode.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetFormatContextTitle(FR_FormatTools formatTools, FS_LPCWSTR lpwsContextTitle, FRFormatToolContextCategoryType eCateType);

    //************************************
    // Function:  ActivateFormatCategory
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: eCateType		Sets the type of format to be operated.
    // Return: void
    // Remarks: Activates the format context category.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    // Deprecated: Internal use.
    //************************************
    static void ActivateFormatCategory(FR_FormatTools formatTools, FRFormatToolContextCategoryType eCateType);

    //************************************
    // Function:  SetWritingDirection
    // Param[in]: formatTools	The input format tools object.
    // Param[in]: eDir			The input writing direction.
    // Return: void
    // Remarks: Sets the writing direction on the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetWritingDirection(FR_FormatTools formatTools, FRFormatToolWritingDirection eDir);

    //************************************
    // Function:  GetWritingDirection
    // Param[in]: formatTools	The input format tools object.
    // Param[out]: outDir		It receives the writing direction.
    // Return: True for success, otherwise for failure.
    // Remarks: Gets the writing direction on the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    // See:
    // Deprecated: Internal use.
    //************************************
    static FS_BOOL GetWritingDirection(FR_FormatTools formatTools, FRFormatToolWritingDirection* outDir);

    //************************************
    // Function:  GetFontFaceName
    // Param[in]: formatTools		The input format tools object.
    // Param[in]: lpwsScriptName	The input font script name.
    // Param[out]: outFontFaceName	It receives the font face name.
    // Return: void
    // Remarks: Gets the font face name of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    // See:
    // Deprecated: Internal use.
    //************************************
    static void GetFontFaceName(FR_FormatTools formatTools, FS_LPCWSTR lpwsScriptName, FS_WideString* outFontFaceName);

    //************************************
    // Function:  ReleaseEvent
    // Param[in]: eventHandle	The input event handle returned by <a>FRFormatToolsSetEvent</a>.
    // Return: void.
    // Remarks: Releases the event handle returned by <a>FRFormatToolsSetEvent</a>.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
    // See: FRFormatToolsSetEvent
    // Deprecated: Internal use.
    //************************************
    static void ReleaseEvent(FS_LPVOID eventHandle);

    //************************************
    // Function:  SetParagraphSpacing
    // Param[in]: formatTools		The input format tools object.
    // Param[in]: flLineLeading     The paragraph space.
    // Return: void
    // Remarks: Set paragraph space of the format tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    // See:
    // Deprecated: Internal use.
    //************************************
    static void SetParagraphSpacing(FR_FormatTools formatTools, FS_FLOAT flLineLeading);

	//************************************
	// Function:  SetNumberedListStyle
	// Param[in]: formatTools		The input format tools object.
	// Param[in]: style     list style
	// Return: void
	// Remarks: Set the style of numbered list.
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetNumberedListStyle(FR_FormatTools formatTools, FS_FXEDIT_ListStyleDescriptor style);

	//************************************
	// Function:  SetBulletedListStyle
	// Param[in]: formatTools		The input format tools object.
	// Param[in]: nBullet     bullet symbol
	// Return: void
	// Remarks: Set the style of numbered list.
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetBulletedListStyle(FR_FormatTools formatTools, FS_DWORD nBullet);

	//************************************
	// Function:  SetFormatCapture
	// Param[in]: formatTools		The input format tools object.	
	// Return: void
	// Remarks: Set format capture.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetFormatCapture(FR_FormatTools formatTools);

	//************************************
	// Function:  ReleaseFormatCapture
	// Param[in]: formatTools		The input format tools object.	
	// Return: void
	// Remarks: Release format capture.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	ReleaseFormatCapture(FR_FormatTools formatTools);

	//************************************
	// Function:  EnableButton2
	// Param[in]: formatTools	The input format tools object.
	// Param[in]: nID			The specified ID.
	// Param[in]: bEnabled		Sets TRUE to enable the button, otherwise not.
	// Param[in]: bUpdateFormat	Sets TRUE will update format, otherwise not.
	// Return: void
	// Remarks: Sets to enable the specified button or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void EnableButton2(FR_FormatTools formatTools, FS_INT32 nID, FS_BOOL bEnabled, FS_BOOLEAN bUpdateFormat);
};

class CFR_PropertyTools_V5
{
public :
    //************************************
    // Function:  Get
    // Return: The property tools object.
    // Remarks: Gets the property tools. The property tools is used to set line color and opacity of the PDF object in classic mode.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static FR_PropertyTools Get();

    //************************************
    // Function:  SetEvent
    // Param[in]: propertyTools     The input property tools object.
    // Param[in]: callbacks         The callback functions. They are called by Foxit Reader when the events occur.
    // Return: The returned value is reserved.
    // Remarks: Sets the callback functions that are called by Foxit Reader when the events occur.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static FS_LPVOID SetEvent(FR_PropertyTools propertyTools, FR_PropertyToolCallbacks callbacks);

    //************************************
    // Function:  SetColor
    // Param[in]: propertyTools     The input property tools object.
    // Param[in]: color             The input color of the property tools.
    // Return: void
    // Remarks: Sets the color of the property tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static void SetColor(FR_PropertyTools propertyTools, FS_COLORREF color);

    //************************************
    // Function:  SetOpacity
    // Param[in]: propertyTools     The input property tools object.
    // Param[in]: nOpacity          The input opacity of the property tools.
    // Return: void
    // Remarks: Sets the opacity of the property tools.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static void SetOpacity(FR_PropertyTools propertyTools, FS_INT32 nOpacity);

    //************************************
    // Function:  IsVisibled
    // Param[in]: propertyTools     The input property tools object.
    // Return: <a>TRUE</a> if the property tools are visible, otherwise not.
    // Remarks: Checks whether the property tools are visible or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static FS_BOOL IsVisibled(FR_PropertyTools propertyTools);

    //************************************
    // Function:  Show
    // Param[in]: propertyTools     The input property tools object.
    // Param[in]: bShow             Indicates whether shows the property tools or not.
    // Return: void
    // Remarks: Sets to show the property tools or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static void Show(FR_PropertyTools propertyTools, FS_BOOL bShow);

    //************************************
    // Function:  IsEnabled
    // Param[in]: propertyTools     The input property tools object.
    // Return: <a>TRUE</a> if the property tools are enabled.
    // Remarks: Checks whether the property tools are enabled or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static FS_BOOL IsEnabled(FR_PropertyTools propertyTools);

    //************************************
    // Function:  Enable
    // Param[in]: propertyTools	The input property tools object.
    // Param[in]: bEnable		Sets TRUE to enable the property tools, otherwise not.
    // Return: void
    // Remarks: Sets to enable the property tools or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static void Enable(FR_PropertyTools propertyTools, FS_BOOL bEnable);

    //************************************
    // Function:  ReleaseEvent
    // Param[in]: eventHandle	The input event handle returned by <a>FRPropertyToolsSetEvent</a>.
    // Return: void.
    // Remarks: Releases the event handle returned by <a>FRPropertyToolsSetEvent</a>.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
    // See: FRPropertyToolsSetEvent
    //************************************
    static void ReleaseEvent(void* eventHandle);
};

class CFR_FuncBtn_V7 //Internal use
{ 
public : 
	//************************************
	// Function:  Create
	// Param[in]: pParentWnd	The parent window passed from <a>PILoadStatusBarUI</a>.
	// Param[in]: lpsName		Specifies the name of the function button.
	// Param[in]: lpwsToolTip	Specifies the tooltip of the function button.
	// Param[in]: pBitmap		Specifies the icon of the function button.
	// Return: A function button object.
	// Remarks: Creates a function button object. Then invoke <a>FRFuncBtnAddToPanel</a> to show the function button.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: FRFuncBtnAddToPanel
	//************************************
	static FR_FuncBtn Create(void* pParentWnd, FS_LPCSTR lpsName, FS_LPCWSTR lpwsToolTip, FS_DIBitmap pBitmap);

	//************************************
	// Function:  AddToPanel
	// Param[in]: pFuncBtn		The input function button object.
	// Param[in]: bShowBottom	Shows the function button to the bottom or not.
	// Return: void.
	// Remarks: Adds the function button to the left navigation panel bar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: FRFuncBtnCreate
	//************************************
	static void AddToPanel(FR_FuncBtn pFuncBtn, FS_BOOL bShowBottom);

	//************************************
	// Function:  GetClientData
	// Param[in]: pFuncBtn		The input function button object.
	// Return: Pointer to the client data.
	// Remarks: Gets the pointer to the client data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: 
	//************************************
	static void* GetClientData(FR_FuncBtn pFuncBtn);

	//************************************
	// Function:  SetClientData
	// Param[in]: pFuncBtn		The input function button object.
	// Param[in]: pData			The input client data.
	// Param[in]: callback		The callback will be invoked to free the client data.
	// Return: void.
	// Remarks: Sets the client data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: 
	//************************************
	static void SetClientData(FR_FuncBtn pFuncBtn, void* pData, FRFreeDataProc callback);

	//************************************
	// Function:  GetToolTip
	// Param[in]: pFuncBtn		The input function button object.
	// Param[out]: outTooltip	It receives the tooltip of the function button.
	// Return: void.
	// Remarks: Gets the tooltip of the function button.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: 
	//************************************
	static void GetToolTip(FR_FuncBtn pFuncBtn, FS_WideString* outTooltip);

	//************************************
	// Function:  SetToolTip
	// Param[in]: pFuncBtn		The input function button object.
	// Param[in]: lpwsToolTip	The input tooltip of the function button.
	// Return: void.
	// Remarks: Sets the tooltip of the function button.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: 
	//************************************
	static void SetToolTip(FR_FuncBtn pFuncBtn, FS_LPCWSTR lpwsToolTip);

	//************************************
	// Function:  SetName
	// Param[in]: pFuncBtn		The input function button object.
	// Param[in]: lpsButtonName	The input name of the function button.
	// Return: void.
	// Remarks: Sets the name of the function button.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: 
	//************************************
	static void SetName(FR_FuncBtn pFuncBtn, FS_LPCSTR lpsButtonName);

	//************************************
	// Function:  GetName
	// Param[in]: pFuncBtn		The input function button object.
	// Param[out]: outName		It receives the name of the function button.
	// Return: void.
	// Remarks: Gets the name of the function button.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: 
	//************************************
	static void GetName(FR_FuncBtn pFuncBtn, FS_ByteString* outName);

	//************************************
	// Function:  SetExecuteProc
	// Param[in]: pFuncBtn		The input function button object.
	// Param[in]: proc			It callback will be invoked when the button is clicked.
	// Return: void.
	// Remarks: Sets the callback that will be invoked when the button is clicked.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: 
	//************************************
	static void SetExecuteProc(FR_FuncBtn pFuncBtn, FRExecuteProc proc);

	//************************************
	// Function:  SetComputeEnabledProc
	// Param[in]: pFuncBtn		The input function button object.
	// Param[in]: proc			A user-supplied procedure to call whenever Reader needs to know whether
	// a button should be enabled.
	// Return:	void.
	// Remarks: Sets a <a>FRComputeEnabledProc</a>() associated with the function button. This rountine determines whether
	// a function button can be selected.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: 
	//************************************
	static void SetComputeEnabledProc(FR_FuncBtn pFuncBtn, FRComputeEnabledProc proc);

	//************************************
	// Function:  SetComputeMarkedProc
	// Param[in]: pFuncBtn		The input function button object.
	// Param[in]: proc			A user-supplied procedure to call whenever Reader needs to know whether
	// a button should be marked.
	// Return:	void.
	// Remarks: Sets a <a>FRComputeMarkedProc</a>() associated with the function button. This rountine determines whether
	// a function button can be marked.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: 
	//************************************
	static void SetComputeMarkedProc(FR_FuncBtn pFuncBtn, FRComputeMarkedProc proc);

	//************************************
	// Function:  UpdateImage
	// Param[in]: pFuncBtn		The input function button object.
	// Param[in]: pBitmap		The input bitmap you want to update.
	// Return:	void.
	// Remarks: Updates the icon of the function button.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: 
	//************************************
	static void UpdateImage(FR_FuncBtn pFuncBtn, FS_DIBitmap pBitmap);

	//************************************
	// Function:  GetRect
	// Param[in]: pFuncBtn		The input function button object.
	// Param[out]: outRt		It receives the rectangle of the function button.
	// Return:	void.
	// Remarks: Gets the rectangle of the function button.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: 
	//************************************
	static void GetRect(FR_FuncBtn pFuncBtn, FS_Rect* outRt);

	//************************************
	// Function:  AddToTabBand
	// Param[in]: pFuncBtn		The input function button object.
	// Param[in]: bLeft			Shows the function button to the left or not.
	// Return: void.
	// Remarks: Adds the function button to the tab band.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	// See: FRFuncBtnCreate
	//************************************
	static void AddToTabBand(FR_FuncBtn pFuncBtn, FS_BOOL bLeft);
};

class CFR_StatusBar_V7
{
public :
    //************************************
    // Function:  AddWndEx
    // Param[in]: pParentWnd	The parent window passed from <a>PILoadStatusBarUI</a>.
    // Param[in]: callbacks		The callback used to create the status bar window.
    // Param[in]: nLocation		Specifies the location in the status bar.
    // Return: void.
    // Remarks: Adds a windows to the status bar.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
    // See:
    //************************************
    static void AddWndEx(void* pParentWnd, FR_StatusBarWndExCallbacks callbacks, FRStatusBarLocation nLocation);

    //************************************
    // Function:  Reset
    // Return: void.
    // Remarks: Resets the status bar.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static void Reset();

    //************************************
    // Function:  SetZoomSliderRange
    // Param[in]: nMin	The minimum value of the zoom slider range.
    // Param[in]: nMax	The maximum value of the zoom slider range.
    // Return: void.
    // Remarks: Sets the zoom slider range.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static void SetZoomSliderRange(FS_INT32 nMin, FS_INT32 nMax);

    //************************************
    // Function:  SetZoomSliderPos
    // Param[in]: nPos	The position of the zoom slider. The value must be in range of 100~20000.
    // Return: void.
    // Remarks: Sets the position of the zoom slider.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static void	SetZoomSliderPos(FS_INT32 nPos);

    //************************************
    // Function:  GetZoomSliderPos
    // Return: The position of the zoom slider.
    // Remarks: Gets the position of the zoom slider.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static FS_INT32 GetZoomSliderPos();

    //************************************
    // Function:  SetZoomPaneText
    // Param[in]: lpwsZoomPaneText	The text of the zoom pane.
    // Return: void.
    // Remarks: Sets the text of the zoom pane.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static void SetZoomPaneText(FS_LPCWSTR lpwsZoomPaneText);

    //************************************
    // Function:  SetComboBoxPageCount
    // Param[in]: nCount	The page count of the page combo box.
    // Return: void.
    // Remarks: Sets the page count of the page combo box.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static void SetComboBoxPageCount(FS_INT32 nCount);

    //************************************
    // Function:  SelectComboBoxItem
    // Param[in]: nIndex	The index of the page combo box item.
    // Return: void.
    // Remarks: Selects the specified page combo box item.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static void SelectComboBoxItem(FS_INT32 nIndex);

    //************************************
    // Function:  GetComboBoxPageIndex
    // Return: The page index of the page combo box.
    // Remarks: Gets the page index of the page combo box.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static FS_INT32 GetComboBoxPageIndex();

    //************************************
    // Function:  GetComboBoxPageText
    // Param[out]: outText	It receives the text of the page combo box.
    // Return: void.
    // Remarks: Gets the text of the page combo box.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static void GetComboBoxPageText(FS_WideString* outText);

    //************************************
    // Function:  GetBkGroundColor
    // Return: The back ground color of status bar.
    // Remarks: Gets the back ground color of status bar in ribbon mode.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static FS_COLORREF GetBkGroundColor();

    //************************************
    // Function:  GetBkGroundPath
    // Param[out]: outPath	It receives the path of the back ground color picture of the status bar in classic mode.
    // Return: void.
    // Remarks: Gets the path of the back ground color picture of the status bar in classic mode.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static void GetBkGroundPath(FS_WideString* outPath);

    //************************************
    // Function:  RecalcLayout
    // Return: void.
    // Remarks: Recalculates the layout of the status bar.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.1.0.0
    //************************************
    static void RecalcLayout();

    //************************************
    // Function:  SetComboBoxPageCount2
    // Param[in]: nCount	The page count of the page combo box.
    // Param[in]: hMainframeWnd	The current mainframe handle.
    // Return: void.
    // Remarks: Sets the page count of the page combo box.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.4.0
    //************************************
    static void SetComboBoxPageCount2(FS_INT32 nCount, FS_HWND hMainframeWnd);

    //************************************
    // Function:  SelectComboBoxItem2
    // Param[in]: nIndex	The index of the page combo box item.
    // Param[in]: hMainframeWnd	The current mainframe handle.
    // Return: void.
    // Remarks: Selects the specified page combo box item.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.4.0
    //************************************
    static void SelectComboBoxItem2(FS_INT32 nIndex, FS_HWND hMainframeWnd);
};

class CFR_BulbMsgCenter_V9
{
public :
    //************************************
    // Function:  AddMessage
    // Param[in]: frDoc			The associated document of the bulb message.
    // Param[in]: pMsgInfo		The input bulb message information.
    // Return: TRUE for success, otherwise not.
    // Remarks: Adds a bulb message to the bulb message center.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
    // See:
    //************************************
    static FS_BOOL AddMessage(FR_Document frDoc, FRBULBMESSAGEINFO msgInfo);

    //************************************
    // Function:  ShowMessage
    // Param[in]: frDoc			The associated document of the bulb message.
    // Param[in]: lpsMsgName	The specified name of the bulb message.
    // Param[in]: bShow			Whether to show the bulb message or not.
    // Return: void.
    // Remarks: Shows the specified bulb message or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
    // See:
    //************************************
    static void ShowMessage(FR_Document frDoc, FS_LPCSTR lpsMsgName, FS_BOOL bShow);

    //************************************
    // Function:  SetCheck
    // Param[in]: frDoc			The associated document of the bulb message.
    // Param[in]: lpsMsgName	The specified name of the bulb message.
    // Param[in]: bCheck		Whether to check the check box or not.
    // Return: void.
    // Remarks: Whether to check the check box or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
    // See:
    //************************************
    static void SetCheck(FR_Document frDoc, FS_LPCSTR lpsMsgName, FS_BOOL bCheck);

    //************************************
    // Function:  SetOpBtnEnable
    // Param[in]: frDoc			The associated document of the bulb message.
    // Param[in]: lpsMsgName	The specified name of the bulb message.
    // Param[in]: opBtnName		The specified name of the operation button.
    // Param[in]: bEnable		Whether to enable the specified operation button or not.
    // Return: void.
    // Remarks: Whether to enable the specified operation button or not.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
    // See:
    //************************************
    static void	SetOpBtnEnable(FR_Document frDoc, FS_LPCSTR lpsMsgName, FS_LPCSTR opBtnName, FS_BOOL bEnable);

    //************************************
    // Function:  IsMessageExist
    // Param[in]: frDoc			The associated document of the bulb message.
    // Param[in]: lpsMsgName	The specified name of the bulb message.
    // Return: TRUE if the bulb message exists, otherwise FALSE.
    // Remarks: Checks whether the bulb message exists or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
    // See:
    //************************************
    static FS_BOOL IsMessageExist(FR_Document frDoc, FS_LPCSTR lpsMsgName);

    //************************************
    // Function:  IsOpBtnEnable
    // Param[in]: frDoc			The associated document of the bulb message.
    // Param[in]: lpsMsgName	The specified name of the bulb message.
    // Param[in]: opBtnName		The specified name of the operation button.
    // Return: TRUE if the operation button is enabled, otherwise FALSE.
    // Remarks: Checks whether the operation button is enabled or not.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
    // See:
    //************************************
    static FS_BOOL IsOpBtnEnable(FR_Document frDoc, FS_LPCSTR lpsMsgName, FS_LPCSTR opBtnName);

    //************************************
    // Function:  SetOpBtnTitle
    // Param[in]: frDoc			The associated document of the bulb message.
    // Param[in]: lpsMsgName	The specified name of the bulb message.
    // Param[in]: opBtnName		The specified name of the operation button.
    // Param[in]: opBtnTitle	The input title of the operation button.
    // Return: void.
    // Remarks: Sets the title of the operation button.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    // See:
    //************************************
    static void SetOpBtnTitle(FR_Document frDoc, FS_LPCSTR lpsMsgName, FS_LPCSTR opBtnName, FS_LPCWSTR opBtnTitle);

    //************************************
    // Function:  SetMessageContent
    // Param[in]: frDoc				The associated document of the bulb message.
    // Param[in]: lpsMsgName		The specified name of the bulb message.
    // Param[in]: lpwsMsgContent	The input content of the bulb message.
    // Return: void.
    // Remarks: Sets the content of the bulb message.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    // See:
    //************************************
    static void SetMessageContent(FR_Document frDoc, FS_LPCSTR lpsMsgName, FS_LPCWSTR lpwsMsgContent);

    //************************************
    // Function:  GetButtonRect
    // Param[in]: frDoc			The associated document of the bulb message.
    // Param[in]: lpsMsgName	The specified name of the bulb message.
    // Param[in]: opBtnName		The specified name of the operation button.
    // Param[out]: outRect	It receives the rectangle of the specified operation button.
    // Return: void.
    // Remarks: Gets the rectangle of the specified operation button.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    // See:
    //************************************
    static void GetButtonRect(FR_Document frDoc, FS_LPCSTR lpsMsgName, FS_LPCSTR opBtnName, FS_Rect* outRect);

    //************************************
    // Function:  AddMessage2
    // Param[in]: hView			The associated window of the bulb message. It get from FRDocGetDocFrameHandler.
    // Param[in]: pMsgInfo		The input bulb message information.
    // Return: TRUE for success, otherwise not.
    // Remarks: Adds a bulb message to the bulb message center.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    // See:
    //************************************
    static FS_BOOL AddMessage2(FS_HWND hView, FRBULBMESSAGEINFO msgInfo);

    //************************************
    // Function:  ShowMessage2
    // Param[in]: hView			The associated window of the bulb message.
    // Param[in]: lpsMsgName	The specified name of the bulb message.
    // Param[in]: bShow			Whether to show the bulb message or not.
    // Return: void.
    // Remarks: Shows the specified bulb message or not.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    // See:
    //************************************
    static void ShowMessage2(FS_HWND  hView, FS_LPCSTR lpsMsgName, FS_BOOL bShow);

    //************************************
    // Function:  AddMessage3
    // Param[in]: frDoc			The associated document of the bulb message.
    // Param[in]: msgInfo2		The input bulb message information.
    // Return: TRUE for success, otherwise not.
    // Remarks: Adds a bulb message to the bulb message center.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0.2
    // See:
    //************************************
    static FS_BOOL AddMessage3(FR_Document frDoc, FRBULBMESSAGEINFO2 msgInfo2);

    //************************************
    // Function:  AddMessage4
    // Param[in]: hView			The associated window of the bulb message.It get from FRDocGetDocFrameHandler.
    // Param[in]: msgInfo2		The input bulb message information.
    // Return: TRUE for success, otherwise not.
    // Remarks: Adds a bulb message to the bulb message center.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0.2
    // See:
    //************************************
    static FS_BOOL AddMessage4(FS_HWND hView, FRBULBMESSAGEINFO2 msgInfo2);

    //************************************
    // Function:  AddMessage5
    // Param[in]: frDoc			The associated document of the bulb message.
    // Param[in]: msgInfo2		The input bulb message information.
    // Return: TRUE for success, otherwise not.
    // Remarks: Adds a bulb message to the bulb message center. If the message center exist, new one will replace it.
    // Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
    // See:
    //************************************
    static FS_BOOL AddMessage5(FR_Document frDoc, FRBULBMESSAGEINFO2 msgInfo2);

    //************************************
    // Function:  IsMessageVisible
    // Param[in]: frDoc			The associated document of the bulb message.
    // Param[in]: strMsgName	The message name of the bulb message.
    // Return: TRUE is visible, otherwise not.
    // Remarks: Checks whether the msaage is visible or not.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
    // See:
    //************************************
    static FS_BOOL 	IsMessageVisible(FR_Document frDoc, FS_ByteString strMsgName);

	//************************************
	// Function:  AddAndShowMessage
	// Param[in]: frDoc			The associated document of the bulb message.
	// Param[in]: msgInfo		The input bulb message information.
	// Return: TRUE for success, otherwise not.
	// Remarks: Adds and show a bulb message to the bulb message center.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL AddAndShowMessage(FR_Document frDoc, FRBULBMESSAGEINFO msgInfo);
};


class CFR_RibbonStyleRadioBox_V14 //Internal use
{
public:
	//************************************
	// Function:  GetMFCButton
	// Param[in]: button	The input FR_RibbonStyleRadioBox object, it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.	
	// Return: The pointer to CButton object.
	// Remarks: Gets the the Radio-Button obj of the FR_RibbonStyleRadioBox.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID GetMFCButton(FR_RibbonStyleRadioBox button);

	//************************************
	// Function:  Release
	// Param[in]: button	The input FR_RibbonStyleRadioBox object.
	// Return: void
	// Remarks: Releases the ribbon style button.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void Release(FR_RibbonStyleRadioBox button);

	//************************************
	// Function:  SetDefaultStyle
	// Param[in]: button		   The input FR_RibbonStyleRadioBox object.
	// Param[in]: option	       The input button style.	
	// Return: void.
	// Remarks: Set button style of the FR_RibbonStyleRadioBox.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetDefaultStyle(FR_RibbonStyleRadioBox button, FR_ButtonStyleOption option);
};

class CFR_RibbonStyleCheckBox_V14 //Internal use
{
public:	
	//************************************
	// Function:  IsChecked
	// Param[in]: button     The input FR_BCGStyleCheckBox object.
	// Return: FS_BOOL       TRUE: It checked.
	// Remarks: Check the stylecheckbox is checked
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsChecked(FR_RibbonStyleCheckBox button);

	//************************************
	// Function:  GetCheckState
	// Param[in]: button     The input FR_BCGStyleCheckBox object.
	// Return:    FS_INT32   Get check state, if the button is BS_AUTO3STATE style, it may be return 2.
	// Remarks: Get check state of the FR_BCGStyleCheckBox.
	// Notes: The function can only be used for Windows. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 GetCheckState(FR_RibbonStyleCheckBox button);

	//************************************
	// Function:  SetCheckBox3State
	// Param[in]: button      The input FR_BCGStyleCheckBox object.
	// Return: void.
	// Remarks: Set the FR_BCGStyleCheckBox support BS_AUTO3STATE style.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetCheckBox3State(FR_RibbonStyleCheckBox button);

	//************************************
	// Function:  GetMFCButton
	// Param[in]: button     The input ribbon style CheckBox object, it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.	
	// Return: void.
	// Remarks: Gets the pointer to the MFC class.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID GetMFCButton(FR_RibbonStyleCheckBox button);

	//************************************
	// Function:  Release
	// Param[in]: button  The input FR_BCGStyleCheckBox object.
	// Return: void.
	// Remarks: Release stylecheckbox
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void Release(FR_RibbonStyleCheckBox button);

	//************************************
	// Function:  SetDefaultStyle
	// Param[in]: button		   The input FR_RibbonStyleCheckBox object.
	// Param[in]: option	       The input button style.	
	// Return: void.
	// Remarks: Set button style of the FR_RibbonStyleCheckBox.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetDefaultStyle(FR_RibbonStyleCheckBox button, FR_ButtonStyleOption option);
};

class CFR_RibbonStyleEdit_V14 //Internal use
{
public:
	//************************************
	// Function:  GetEditButton
	// Param[in]: button     The input FR_RibbonStyleEdit object, it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.	
	// Return: void.
	// Remarks: Get CEdit pointer of attached with button.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID GetEditButton(FR_RibbonStyleEdit button);

	//************************************
	// Function:  Release
	// Param[in]: button    The input FR_RibbonStyleEdit object.
	// Return: void.
	// Remarks: Release FR_RibbonStyleEdit button.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	Release(FR_RibbonStyleEdit button);

	//************************************
	// Function:  SetPromptText
	// Param[in]: button              The input FR_BCGStyleEdit object.
	// Param[in]: wsPromptText        The prompt text of FR_BCGStyleEdit.
	// Param[in]: bEnableSearchMode   Whether FR_RibbonStyleEdit support search.
	// Return: void.
	// Remarks: Set prompt text of the FR_RibbonStyleEdit.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetPromptText(FR_RibbonStyleEdit button, FS_WideString wsPromptText, FS_BOOL bEnableSearchMode);

	//************************************
	// Function:  SetBorderColor
	// Param[in]: button              The input FR_BCGStyleEdit object.
	// Param[in]: clrDefault          The default control clor, default color: RGB(217, 217, 217).
	// Param[in]: clrHighlight        The hight color, default color: RGB(146, 48, 148).
	// Param[in]: clrFocus            The focus color, default color: RGB(146, 48, 148).
	// Param[in]: clrDisable          The disable color, default color: RGB(221, 221, 221).
	// Return: void.
	// Remarks: Set border color of the FR_RibbonStyleEdit.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetBorderColor(FR_RibbonStyleEdit button, FS_COLORREF clrDefault,
		FS_COLORREF clrHighlight,
		FS_COLORREF clrFocus,
		FS_COLORREF clrDisable);

	//************************************
	// Function:  SetRoundRadius
	// Param[in]: button              The input FR_BCGStyleEdit object.
	// Param[in]: ptRoundRadius       The point of the round radius, default is (4,4).
	// Return: void.
	// Remarks: Set round radius of the FR_RibbonStyleEdit.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetRoundRadius(FR_RibbonStyleEdit button, FS_DevicePoint ptRoundRadius);

	//************************************
	// Function:  SetDefaultStyle
	// Param[in]: button		   The input FR_BCGStyleEdit object.
	// Param[in]: option	       The input button style.	
	// Return: void.
	// Remarks: Set button style of the FR_RibbonStyleEdit.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetDefaultStyle(FR_RibbonStyleEdit button, FR_ButtonStyleOption option);
};

class CFR_RibbonStyleLinkButton_V14 //Internal use
{
public:	
	//************************************
	// Function:  SetAlwaysUnderLineText
	// Param[in]: button             The input FR_RibbonStyleLinkButton object.
	// Param[in]: bUnderLine         The input ribbon style underline.
	// Return: void.
	// Remarks: Set text need always to UnderLine.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetAlwaysUnderLineText(FR_RibbonStyleLinkButton button, FS_BOOL bUnderLine);

	//************************************
	// Function:  SetMultilineText
	// Param[in]: button              The input FR_RibbonStyleLinkButton object.
	// Param[in]: bMultiLineText      Set whether support multiline.
	// Return: void.
	// Remarks: Set whether support multiline.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetMultilineText(FR_RibbonStyleLinkButton button, FS_BOOL bMultiLineText);

	//************************************
	// Function:  SetAlignStyle
	// Param[in]: button              The input FR_RibbonStyleLinkButton object.
	// Param[in]: nAlignType          The input aligntype.
	// Return: void.
	// Remarks: Set align style of the link button.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetAlignStyle(FR_RibbonStyleLinkButton button, FRRibbonStyleTextAlignType nAlignType);

	//************************************
	// Function:  GetMFCButton
	// Param[in]: button              The input ribbon style linkButton object, it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.	
	// Return: void.
	// Remarks: Get CButton pointer of attached with the button.
	// Notes: The function can only be used for Windows. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID GetMFCButton(FR_RibbonStyleLinkButton button);

	//************************************
	// Function:  Release
	// Param[in]: button              The input FR_RibbonStyleLinkButton object.
	// Return: void.
	// Remarks: Release linkButton
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void Release(FR_RibbonStyleLinkButton button);
};

class CFR_RibbonStyleSliderCtrl_V14 //Internal use
{
public:
	//************************************
	// Function:  GetSliderButton
	// Param[in]: button              The input FR_RibbonStyleSliderCtrl object, it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.	
	// Return: FS_LPVOID.
	// Remarks: Get CSliderCtrl object with attached the button
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID GetSliderButton(FR_RibbonStyleSliderCtrl button);

	//************************************
	// Function:  Release
	// Param[in]: button              The input ribbon style SliderCtrl object.
	// Return: void.
	// Remarks: Release FR_RibbonStyleSliderCtrl object.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void Release(FR_RibbonStyleSliderCtrl button);
};


class CFR_RibbonStyleColorButton_V14 //Internal use
{
public:
	//************************************
	// Function:  GetButton
	// Param[in]: button			The FR_RibbonStyleColorButton whose button is obtained, it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.	
	// Return: FS_LPVOID            The specified button with CButton type.
	// Remarks: Gets the specified button.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID	GetButton(FR_RibbonStyleColorButton button);

	//************************************
	// Function:  Release
	// Param[in]: button              The input ribbon style FR_RibbonStyleColorButton object.	
	// Return: void.
	// Remarks: Release style ColorButton.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void		Release(FR_RibbonStyleColorButton button);

	//************************************
	// Function:  SetColor
	// Param[in]: button   	The input ribbon style FR_RibbonStyleColorButton object.
	// Param[in]: color		The input color.
	// Return: void
	// Remarks: Sets the selected color of the ribbon color button.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void		SetColor(FR_RibbonStyleColorButton button,FS_COLORREF color);

	//************************************
	// Function:  GetColor
	// Param[in]: button	The input ribbon style FR_RibbonStyleColorButton object.
	// Return: The color.
	// Remarks: Gets the selected color of the ribbon color button.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_COLORREF	GetColor(FR_RibbonStyleColorButton button);

	//************************************
	// Function:  SetColumnsNumber
	// Param[in]: button	The input ribbon style FR_RibbonStyleColorButton object.
	// Param[in]: nColumns	The number of columns of FR_RibbonStyleColorButton object.
	// Return: void.
	// Remarks: Sets the colums number of the ribbon color button.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void		SetColumnsNumber(FR_RibbonStyleColorButton button, FS_INT32 nColumns);

	//************************************
	// Function:  SetImage
	// Param[in]: button	The input ribbon style FR_RibbonStyleColorButton object.
	// Param[in]: pBitmap	The bitmap of FR_RibbonStyleColorButton object.
	// Param[in]: cx	The image cx of FR_RibbonStyleColorButton object.
	// Param[in]: cy	The image cy of FR_RibbonStyleColorButton object.
	// Return: void.
	// Remarks: Sets the icon of the ribbon element. The ribbon element contains a large icon and a small icon.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void		SetImage(FR_RibbonStyleColorButton button, FS_DIBitmap pBitmap, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  SetAppearance
	// Param[in]: button	    The input ribbon style FR_RibbonStyleColorButton object.
	// Param[in]: bHasBorder	If the FR_RibbonStyleColorButton object has border.
	// Param[in]: bHasArrow	    If the FR_RibbonStyleColorButton object has arrow.
	// Return: void.
	// Remarks: Set appearance of the ribbon color button.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void		SetAppearance(FR_RibbonStyleColorButton button, FS_BOOL bHasBorder, FS_BOOL bHasArrow);

	//************************************
	// Function:  EnableAutomaticButton
	// Param[in]: button	The input ribbon style FR_RibbonStyleColorButton object.
	// Param[in]: wsLabel	The label of the button.
	// Param[in]: clrAutomatic	The color of the automatic button.
	// Param[in]: bEnable	If the button is enabled.
	// Return: void.
	// Remarks:  Enables the automatic button or not.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void		EnableAutomaticButton(FR_RibbonStyleColorButton button, FS_WideString wsLabel, FS_COLORREF clrAutomatic, FS_BOOL bEnable);

	//************************************
	// Function:  EnableOtherButton
	// Param[in]: button	The input ribbon style FR_RibbonStyleColorButton object.
	// Param[in]: wsLabel	The input label.
	// Param[in]: bAltColorDlg	If the FR_RibbonStyleColorButton object colordlg.
	// Param[in]: bEnable	If the color button is enabled.
	// Return: void.
	// Remarks: Enables the button to select other color.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void		EnableOtherButton(FR_RibbonStyleColorButton button, FS_WideString wsLabel, FS_BOOL bAltColorDlg, FS_BOOL bEnable);

	//************************************
	// Function:  SetImage2
	// Param[in]: button	The input ribbon style FR_RibbonStyleColorButton object.
	// Param[in]: wsBitmapName	 For loading PDF images, the name is retrieved from the BOOKMARK of the PDF file：FoxitReader\res\ribbon\ribbonimage.pdf
	// Param[in]: cx		The width of the bitmap when the DPI is 100%. The default value is 32.
	// Param[in]: cy		The height of the bitmap when the DPI is 100%. The default value is 32.
	// Return: void
	// Remarks: Sets the icon of the ribbon style static box.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetImage2(FR_RibbonStyleColorButton button, FS_WideString wsBitmapName, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  SetTooltip
	// Param[in]: button	The input ribbon style FR_RibbonStyleColorButton object.
	// Param[in]: wsTooltip  	The input tooltip of the color button.
	// Return: void
	// Remarks: Sets the tooltip of the colorbutton.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	 SetTooltip(FR_RibbonStyleColorButton button, FS_WideString wsTooltip);

	//************************************
	// Function:  SetDescription
	// Param[in]: button		    The input ribbon style FR_RibbonStyleColorButton object.
	// Param[in]: wsDescription	    The description of the ribbon button.
	// Return: void.
	// Remarks: Set description of the button.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetDescription(FR_RibbonStyleColorButton button, FS_WideString wsDescription);

	//************************************
	// Function:  EnableHelpLink
	// Param[in]: button		    The input ribbon style FR_RibbonStyleColorButton object.
	// Param[in]: bEnable	        If the ribbon button can be enable.
	// Param[in]: bsButtonName	    Set the button name to use for tooltip info .
	// Return: void.
	// Remarks: Set Tell Me More in Tooltip. bsButtonName can be used with the button name.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void EnableHelpLink(FR_RibbonStyleColorButton button, FS_BOOL bEnable, FS_ByteString bsButtonName);
};


class CFR_RibbonStyleComboBox_V14 //Internal use
{
public:
	//************************************
	// Function:  GetButton
	// Param[in]: combox			The FR_RibbonStyleCombox whose button is obtained, it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.		
	// Return: FS_LPVOID            Get CComboBox object attached with combox.
	// Remarks: Gets the pointer of CComboBox.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID	GetButton(FR_RibbonStyleCombox combox);

	//************************************
	// Function:  SetPrompt
	// Param[in]: combox			The input FR_RibbonStyleCombox.
	// Param[in]: lpszPrompt		The prompt of the combox.	
	// Return: void
	// Remarks: Set prompt info of the ComboBox.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void	SetPrompt(FR_RibbonStyleCombox combox,FS_LPCWSTR lpszPrompt);

	//************************************
	// Function:  Release
	// Param[in]: combox			The input FR_RibbonStyleCombox.
	// Return: void
	// Remarks: Release the combox.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void	Release(FR_RibbonStyleCombox combox);

	//************************************
	// Function:  SetInputType
	// Param[in]: combox			The input FR_RibbonStyleCombox.
	// Param[in]: iType			    0 is unlimited, 1 is a number, the default is 0.
	// Return: void
	// Remarks: Set input data type of ComboBox.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void    SetInputType(FR_RibbonStyleCombox combox, FS_INT32 iType);
	
	//************************************
	// Function:  SetLimitDecimalNum
	// Param[in]: combox			The input FR_RibbonStyleCombox.
	// Param[in]: iLimitNum	        Decimal places.
	// Return: void
	// Remarks: Set the number of decimal places of ComboBox.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void    SetLimitDecimalNum(FR_RibbonStyleCombox combox, FS_INT32 iLimitNum);

	//************************************
	// Function:  SetMaxAndMinValue
	// Param[in]: combox			The input FR_RibbonStyleCombox.
	// Param[in]: dMinValue	        The min value.
	// Param[in]: dMaxValue	        The max value.
	// Return: void
	// Remarks: Set max and min value of ComboBox.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void    SetMaxAndMinValue(FR_RibbonStyleCombox combox, FS_FLOAT dMinValue, FS_FLOAT dMaxValue);

	//************************************
	// Function:  SetDescription
	// Param[in]: combox		    The input FR_RibbonStyleCombox.
	// Param[in]: wsDescription	    The description of the ComboBox.
	// Return: void.
	// Remarks: Set description of the ComboBox.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetDescription(FR_RibbonStyleCombox combox, FS_LPCWSTR wsDescription);

	//************************************
	// Function:  EnableHelpLink
	// Param[in]: combox		    The FR_RibbonStyleCombox whose button is obtained.	
	// Param[in]: bEnable	        If the comboBox can be enable.
	// Param[in]: bsButtonName	    Set the tooltip info.
	// Return: void.
	// Remarks: Set Tell Me More in Tooltip. bsButtonName can be used with the button name.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void EnableHelpLink(FR_RibbonStyleCombox combox, FS_BOOL bEnable, FS_LPCSTR bsButtonName);

	//************************************
	// Function:  SetTooltip
	// Param[in]: combox		    The FR_RibbonStyleCombox whose button is obtained.	
	// Param[in]: wsTooltip	        The tooltip of the control.
	// Return: void.
	// Remarks: Set tooltip of the Combox.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetTooltip(FR_RibbonStyleCombox combox, FS_LPCWSTR wsTooltip);

	//************************************
	// Function:  SetRoundRadius
	// Param[in]: button		   The FR_RibbonStyleCombox whose button is obtained.	
	// Param[in]: ptRoundRadius	   The input round radius.	
	// Return: void.
	// Remarks: Set round radius of the combox.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetRoundRadius(FR_RibbonStyleCombox combox, FS_DevicePoint ptRoundRadius);

	//************************************
	// Function:  SetDefaultStyle
	// Param[in]: button		   The FR_RibbonStyleCombox whose button is obtained.	
	// Param[in]: ptRoundRadius	   The input button style.	
	// Return: void.
	// Remarks: Set button style of the combox.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetDefaultStyle(FR_RibbonStyleCombox combox, FR_ButtonStyleOption option);
};


class CFR_RibbonStyleFontComboBox_V14 //Internal use
{
public:
	//************************************
	// Function:  GetButton
	// Param[in]: combox			The FR_RibbonStyleFontCombox whose button is obtained, it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.	
	// Return: FS_LPVOID            Get CComboBox object attached with combox.
	// Remarks: Gets the specified control of combox.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID	GetButton(FR_RibbonStyleFontCombox combox);

	//************************************
	// Function:  Release
	// Param[in]: combox			The input FR_RibbonStyleFontCombox.		
	// Return: void.
	// Remarks: Release the specified control of FR_RibbonStyleFontCombox.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void	Release(FR_RibbonStyleFontCombox combox);

	//************************************
	// Function:  SelectFont
	// Param[in]: combox			The FR_RibbonStyleFontCombox whose button is obtained.	
	// Param[in]: lpszName			The font name of the FR_RibbonStyleFontCombox font.	
	// Param[in]: nCharSet			The input charset. Sets it DEFAULT_CHARSET as default.
	// Return: FS_BOOL.     TRUE is select font success, FALSE is select fail.
	// Remarks: Select font with the combox.
	// Notes: The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL            SelectFont(FR_RibbonStyleFontCombox combox, FS_LPCWSTR lpszName, FS_BYTE nCharSet);
	
	//************************************
	// Function:  InsertFont
	// Param[in]: combox			The FR_RibbonStyleFontCombox whose button is obtained.	
	// Param[in]: wsFaceName		The input font face name.
	// Param[in]: nIndex			The position where the font will be inserted.
	// Param[in]: nCharSet			The input charset. Sets it DEFAULT_CHARSET as default.
	// Return: FS_INT32.            Return the item index of Combox after insert font.
	// Remarks: Insert font to the combox.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_INT32				InsertFont(FR_RibbonStyleFontCombox combox, FS_WideString wsFaceName, FS_INT32 nIndex, FS_BYTE nCharSet);

	//************************************
	// Function:  AddFont
	// Param[in]: combox			The FR_RibbonStyleFontCombox whose button is obtained.	
	// Param[in]: wsFaceName		The input font face name.
	// Param[in]: nCharSet			The input charset. Sets it DEFAULT_CHARSET as default.
	// Return: FS_INT32             Return the item index of Combox after add font.
	// Remarks: Add font to the combox.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_INT32				AddFont(FR_RibbonStyleFontCombox combox, FS_WideString wsFaceName, FS_BYTE nCharSet);

	//************************************
	// Function:  SetDescription
	// Param[in]: combox			The FR_RibbonStyleFontCombox whose button is obtained.	
	// Param[in]: wsDescription	    The description of the font combox.
	// Return: void.
	// Remarks:  Set description of the font combox.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetDescription(FR_RibbonStyleFontCombox combox, FS_LPCWSTR wsDescription);

	//************************************
	// Function:  EnableHelpLink
	// Param[in]: combox			The FR_RibbonStyleFontCombox whose button is obtained.	
	// Param[in]: bEnable	        If the font combox can be enable.
	// Param[in]: bsButtonName	    Set the tooltip info.
	// Return: void.
	// Remarks: Set Tell Me More in Tooltip. bsButtonName can be used with the button name.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void EnableHelpLink(FR_RibbonStyleFontCombox combox, FS_BOOL bEnable, FS_LPCSTR bsButtonName);

	//************************************
	// Function:  SetTooltip
	// Param[in]: combox			The FR_RibbonStyleFontCombox whose button is obtained.	
	// Param[in]: wsTooltip	        The  tooltip of the control.
	// Return: void.
	// Remarks: Set tool tip of the combox.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetTooltip(FR_RibbonStyleFontCombox combox, FS_LPCWSTR wsTooltip);
};


class CFR_StyleGalleryCtrl_V14 //Internal use
{
public:
	//************************************
	// Function:  GetWnd
	// Param[in]: galleryCtrl			The FR_StyleGalleryCtrl whose control is obtained, it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.		
	// Return: The CWnd* of the FR_StyleGalleryCtrl.
	// Remarks: Gets CWnd obj of the FR_StyleGalleryCtrl.
	// Notes: The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID GetWnd(FR_StyleGalleryCtrl galleryCtrl);
	
	//************************************
	// Function:  Release
	// Param[in]: galleryCtrl			The FR_BCGStyleGalleryCtrl whose control is obtained.		
	// Return: void
	// Remarks: Release FR_BCGStyleGalleryCtrl
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void Release(FR_StyleGalleryCtrl galleryCtrl);

	//************************************
	// Function:  AddGroup
	// Param[in]: galleryCtrl			The FR_BCGStyleGalleryCtrl whose control is obtained.
	// Param[in]: csGroupTitle	        Group Label Title
	// Param[in]: arBitmapName	        For loading PDF images, the name is retrieved from the BOOKMARK of the PDF file：FoxitReader\res\ribbon\ribbonimage.pdf
	// Param[in]: arLabels		        The Label of to the picture must correspond one to one and can be empty.
	// Param[in]: nImgWidth		        The xSize of image.
	// Param[in]: nImgHeight		    The ySize of image.
	// Param[in]: nItemWidth		    The xSize of Item.
	// Param[in]: nItemHeight		    The ySize of Item.
	// Param[in]: bRecalcLayout	        If need recalclayout.
	// Return: void
	// Remarks: Add item group to FR_BCGStyleGalleryCtrl.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void AddGroup(FR_StyleGalleryCtrl galleryCtrl, FS_WideString csGroupTitle, FS_WideStringArray arBitmapName,
		FS_WideStringArray arLabels, FS_INT32 nImgWidth, FS_INT32 nImgHeight, FS_INT32 nItemWidth, FS_INT32 nItemHeight, FS_BOOL bRecalcLayout);

	//************************************
	// Function:  AddGroup1
	// Param[in]: galleryCtrl			The FR_BCGStyleGalleryCtrl whose control is obtained.
	// Param[in]: csGroupTitle	        Group Label Title
	// Param[in]: imagesPaletteAll	    A set of images, such as 32x32 images placed on a PNG
	// Param[in]: cxPaletteImage		Image width per image
	// Param[in]: arLabels		        The Label of to the picture must correspond one to one and can be empty	
	// Param[in]: nItemWidth		    The xSize of Item
	// Param[in]: nItemHeight		    The ySize of Item
	// Param[in]: bRecalcLayout	        If need recalclayout
	// Return: void
	// Remarks:  Add item group to FR_BCGStyleGalleryCtrl.
	// Notes: The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void AddGroup1(FR_StyleGalleryCtrl galleryCtrl, FS_WideString csGroupTitle, FS_LPVOID imagesPaletteAll, FS_INT32 cxPaletteImage,
		FS_WideStringArray arLabels, FS_INT32 nItemWidth, FS_INT32 nItemHeight, FS_BOOL bRecalcLayout);

	//************************************
	// Function:  SelectItem
	// Param[in]: galleryCtrl			The FR_BCGStyleGalleryCtrl whose control is obtained.
	// Param[in]: nItemIndex	        Set item index to be select.
	// Return: void
	// Remarks: Set item index to be select.
	// Notes: The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void SelectItem(FR_StyleGalleryCtrl galleryCtrl, FS_INT32 nItemIndex);

	//************************************
	// Function:  GetSelectedItem
	// Param[in]: galleryCtrl			The FR_BCGStyleGalleryCtrl whose control is obtained.
	// Return: FS_INT32                 Return selected item index.
	// Remarks: Get index of selected item.
	// Notes: 
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 GetSelectedItem(FR_StyleGalleryCtrl galleryCtrl);

	//************************************
	// Function:  SetItemSize
	// Param[in]: galleryCtrl			The FR_StyleGalleryCtrl whose control is obtained.
	// Param[in]: nItemWidth		    The xSize of Item.
	// Param[in]: nItemHeight		    The ySize of Item.
	// Param[in]: bRecalcLayout	        If need recalclayout.
	// Return: void
	// Remarks: Set the Item size when szItem value is DPI = 100%, used after FRStyleGalleryCtrlAddGroup.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void SetItemSize(FR_StyleGalleryCtrl galleryCtrl, FS_INT32 nItemWidth, FS_INT32 nItemHeight, FS_BOOL bRecalcLayout);
	
	//************************************
	// Function:  SetImageMargin
	// Param[in]: galleryCtrl			The FR_StyleGalleryCtrl whose control is obtained.
	// Param[in]: nImgMarginWidth		The image margin xSize of Item.
	// Param[in]: nImgMarginHeight		The image margin ySize Item.
	// Param[in]: nItemMarginWidth		The X distance between two items.
	// Param[in]: nItemMarginHeight		The Y distance between two items.
	// Return: void
	// Remarks: Set the image margin
	// Notes:  The function can only be used for Windows.
	// It needs to set after FRStyleGalleryCtrlAddGroup or FRStyleGalleryCtrlAddGroup1.
	// See: FRStyleGalleryCtrlAddGroup
	// See: FRStyleGalleryCtrlAddGroup1
	// Deprecated: Internal use.
	//************************************
	static void SetImageMargin(FR_StyleGalleryCtrl galleryCtrl, FS_INT32 nImgMarginWidth, FS_INT32 nImgMarginHeight, FS_INT32 nItemMarginWidth, FS_INT32 nItemMarginHeight);

	//************************************
	// Function:  SetAppearance
	// Param[in]: galleryCtrl			The FR_StyleGalleryCtrl whose control is obtained.
	// Param[in]: bHasBorder		    If need show border.
	// Param[in]: bHasScrollbar		    If need scrollbar.
	// Return: void
	// Remarks: Set appearacne
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void SetAppearance(FR_StyleGalleryCtrl galleryCtrl, FS_BOOL bHasBorder, FS_BOOL bHasScrollbar);

	//************************************
	// Function:  SetAlignedSide
	// Param[in]: galleryCtrl			The FR_StyleGalleryCtrl whose control is obtained.
	// Param[in]: nAlignStyle		    The align stype of the control.
	// Return: void
	// Remarks: Set text align side.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void SetAlignedSide(FR_StyleGalleryCtrl galleryCtrl, FRRibbonStyleTextAlignType nAlignStyle);

	//************************************
	// Function:  AddItemButton
	// Param[in]: galleryCtrl			The FR_StyleGalleryCtrl whose control is obtained.
	// Param[in]: nItem		            The item index.
	// Param[in]: nID		            The item id.
	// Param[in]: wsBitmapName		    For loading PDF images, the name is retrieved from the BOOKMARK of the PDF file：FoxitReader\res\ribbon\ribbonimage.pdf.
	// Param[in]: nImgWidth		        The image width.
	// Param[in]: nImgHeight		    The image height.
	// Param[in]: pClientData		    The client data.
	// Param[in]: proc		            It called when click button.
	// Param[in]: freeproc		        It called when release button.
	// Return: void
	// Remarks: Add item button.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void AddItemButton(FR_StyleGalleryCtrl galleryCtrl, FS_INT32 nItem, FS_INT32 nID, FS_LPCWSTR wsBitmapName, FS_INT32 nImgWidth, FS_INT32 nImgHeight, FS_LPVOID pClientData, FRClickButtonProc proc, FRFreeDataProc freeproc);

	//************************************
	// Function:  SetItemToolTip
	// Param[in]: galleryCtrl	   The FR_StyleGalleryCtrl whose control is obtained.
	// Param[in]: nItemIndex	   The item index.
	// Param[in]: wsToolTip		   The input tooltip of the item.
	// Return: void
	// Remarks: Sets the tooltip of the item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetItemToolTip(FR_StyleGalleryCtrl galleryCtrl, FS_INT32 nItemIndex, FS_LPCWSTR wsToolTip);

	//************************************
	// Function:  SetItemAccName
	// Param[in]: galleryCtrl	   The FR_StyleGalleryCtrl whose control is obtained.
	// Param[in]: nItemIndex	   The item index.
	// Param[in]: wsAccName		   The input accelerate name.
	// Return: void
	// Remarks: Sets the acc name the item.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetItemAccName(FR_StyleGalleryCtrl galleryCtrl, FS_INT32 nItemIndex, FS_LPCWSTR wsAccName);
	
    //************************************
	// Function:  DisableHighContrastThemeImage
	// Param[in]: galleryCtrl	   The FR_StyleGalleryCtrl whose control is obtained.
	// Return: void
	// Remarks: In high contrast mode, whether to change the icon to a high contrast color.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	DisableHighContrastThemeImage(FR_StyleGalleryCtrl galleryCtrl);
};

class CFR_StyleSpinBtnCtrl_V14 //Internal use
{
public:
	//************************************
	// Function:  GetButton
	// Param[in]: btnCtrl			The FR_StyleSpinBtnCtrl whose button is obtained.	
	// Return: The specified button with CSpinButtonCtrl type.
	// Remarks: Gets the specified button.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID	        GetButton(FR_StyleSpinBtnCtrl btnCtrl);

	//************************************
	// Function:  Release
	// Param[in]: btnCtrl			The FR_StyleSpinBtnCtrl whose button is obtained.		
	// Return: The specified button with CSpinButtonCtrl type.
	// Remarks: Gets the specified button.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void	                Release(FR_StyleSpinBtnCtrl btnCtrl);
};

class CFR_StyleComboGalleryCtrl_V14 //Internal use
{
public:
	//************************************
	// Function:  GetWnd
	// Param[in]: comboctrl			The FR_StyleComboGalleryCtrl whose control is obtained, it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.			
	// Return: The CWnd* of the FR_StyleComboGalleryCtrl object.
	// Remarks: Gets CWnd obj of the FR_StyleComboGalleryCtrl.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID	GetWnd(FR_StyleComboGalleryCtrl comboctrl);

	//************************************
	// Function:  Release
	// Param[in]: comboctrl			The FR_StyleComboGalleryCtrl whose control is obtained.		
	// Return: void
	// Remarks: Release FR_StyleComboGalleryCtrl.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void	Release(FR_StyleComboGalleryCtrl comboctrl);

	//************************************
	// Function:  AddGroup	
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.		
	// Param[in]: csGroupTitle	        Group Label Title.
	// Param[in]: arBitmapName	        For loading PDF images, the names are retrieved from the BOOKMARK of the PDF file：FoxitReader\res\ribbon\ribbonimage.pdf.
	// Param[in]: arLabels		        The Label of to the picture must correspond one to one and can be empty.
	// Param[in]: nImgWidth		        The xSize of image.
	// Param[in]: nImgHeight		    The ySize of image.
	// Return: void
	// Remarks: Add a set of PDF images.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes: Can not be mixed with the other two AddGroup. The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void AddGroup(FR_StyleComboGalleryCtrl comboctrl,FS_WideString csGroupTitle, FS_WideStringArray arBitmapName, FS_WideStringArray* arLabels, FS_INT32 nImgWidth, FS_INT32 nImgHeight);
	
	//************************************
	// Function:  AddGroup1
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: csGroupTitle	        Group Label Title.
	// Param[in]: imagesPaletteAll	    A set of images, such as all 32x32 images placed on one picture.
	// Param[in]: cxPaletteImage		Image width of per image.
	// Param[in]: arLabels		        The Label of to the picture must correspond one to one and can be empty	.
	// Return: void
	// Remarks: Add a set of PDF images, all images set to one PNG in imagesPaletteAll.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void	AddGroup1(FR_StyleComboGalleryCtrl comboctrl,FS_WideString csGroupTitle, FS_LPVOID imagesPaletteAll, FS_INT32 cxPaletteImage, FS_WideStringArray* arLabels);
	
	//************************************
	// Function:  RemoveAllGroup
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Return: void
	// Remarks: Remove all groups.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void	RemoveAllGroup(FR_StyleComboGalleryCtrl comboctrl);

	//************************************
	// Function:  GetCount
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Return: FS_INT32                 Get count of items.
	// Remarks: Get count of items.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes: The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_INT32		GetCount(FR_StyleComboGalleryCtrl comboctrl);

	//************************************
	// Function:  GetSelectedItem
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Return: FS_INT32                 Get the currently selected item index.
	// Remarks: Get the currently selected item index.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes: The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_INT32		GetSelectedItem(FR_StyleComboGalleryCtrl comboctrl);

	//************************************
	// Function:  SelectItem
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: nItemIndex	        The item index.	
	// Return: FS_INT32                 Set the current item index as selected.
	// Remarks: Set the current item index as selected.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_INT32		SelectItem(FR_StyleComboGalleryCtrl comboctrl,FS_INT32 nItemIndex);

	//************************************
	// Function:  GetItemText
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: nItemIndex	        The item index.	
	// Param[out]: wsText	            The index item of the text.	
	// Return: FS_BOOL                  TRUE get the text of the item successfully.
	// Remarks: Get the text of the item.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL	GetItemText(FR_StyleComboGalleryCtrl comboctrl, FS_INT32 nIndex, FS_WideString* wsText);

	//************************************
	// Function:  SetAppearance	
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: bHasBorder	        TRUE: show border.
	// Param[in]: bLargeArrow	        TRUE: show large arrow.
	// Param[in]: bRightArrow	        TRUE: show right arrow.
	// Return: void
	// Remarks: Set button appearance property.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes: The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void SetAppearance(FR_StyleComboGalleryCtrl comboctrl,FS_BOOL bHasBorder, FS_BOOL bLargeArrow, FS_BOOL bRightArrow);

	//************************************
	// Function:  SetIconsInRow
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: nIconsInRow	        One line shows the number of items.
	// Return: void
	// Remarks: Set the number of items displayed in a row, if it is greater than 1, the title is not displayed.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes: The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void SetIconsInRow(FR_StyleComboGalleryCtrl comboctrl,FS_INT32 nIconsInRow);

	//************************************
	// Function:  SetComboMode
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: bComboMode	        TRUE: The image and title of the drop-down button can be displayed on the button.
	// Return:  void
	// Remarks: Set button display mode.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Notes: The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void SetComboMode(FR_StyleComboGalleryCtrl comboctrl, FS_BOOL bComboMod);

	//************************************
	// Function:  SetImage
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: pBitmap	            Set button image.
	// Param[in]: nImgWidth	            The image width.
	// Param[in]: nImgHeight	        The image height.
	// Notes: It's invalid when SetComboMode FALSE.  The function can only be used for Windows.
	// Return: void
	// Remarks: Set button image.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void SetImage(FR_StyleComboGalleryCtrl comboctrl,FS_DIBitmap pBitmap, FS_INT32 nImgWidth, FS_INT32 nImgHeight);

	//************************************
	// Function:  SetAlignStyle
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: nAlignStyle	        The text alignment.
	// Notes: It's invalid when SetComboMode FALSE.  The function can only be used for Windows.
	// Return: void
	// Remarks: Set text alignment.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void SetAlignStyle(FR_StyleComboGalleryCtrl comboctrl, FRRibbonStyleTextAlignType nAlignStyle);

	//************************************
	// Function:  SetImageSide
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: nImageSide	        The image alignment.
	// Notes: It's invalid when SetComboMode FALSE.  The function can only be used for Windows.
	// Return: void
	// Remarks: Set image alignment.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void SetImageSide(FR_StyleComboGalleryCtrl comboctrl, FRRibbonStyleImageSide nImageSide);

	//************************************
	// Function:  SetVertMargin
	// Param[in]: comboctrl	            The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: nVerMargin            The value of vertical margin.
	// Notes: It's invalid when SetComboMode FALSE.  The function can only be used for Windows.
	// Return: void
	// Remarks: Set image margin
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void SetVertMargin(FR_StyleComboGalleryCtrl comboctrl, FS_INT32 nVerMargin);

	//************************************
	// Function:  SetImage3
	// Param[in]: comboctrl	The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: wsBitmapName	 For loading PDF images, the name is retrieved from the BOOKMARK of the PDF file：FoxitReader\res\ribbon\ribbonimage.pdf
	// Param[in]: cx		The width of the bitmap when the DPI is 100%. The default value is 32.
	// Param[in]: cy		The height of the bitmap when the DPI is 100%. The default value is 32.
	// Return: void
	// Remarks: Sets the icon of the ribbon style.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	SetImage3(FR_StyleComboGalleryCtrl comboctrl, FS_WideString wsBitmapName, FS_INT32 cx, FS_INT32 cy);

	//************************************
	// Function:  SetDescription
	// Param[in]: comboctrl		    The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: wsDescription	    The description of the control.
	// Return: void.
	// Remarks: Set the description of the control.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetDescription(FR_StyleComboGalleryCtrl comboctrl, FS_LPCWSTR wsDescription);

	//************************************
	// Function:  EnableHelpLink
	// Param[in]: comboctrl		    The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: bEnable	        If the control can be enable.
	// Param[in]: bsButtonName	    Set the tooltip info.
	// Return: void.
	// Remarks: Set Tell Me More in Tooltip. bsButtonName can be used with the button name.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void EnableHelpLink(FR_StyleComboGalleryCtrl comboctrl, FS_BOOL bEnable, FS_LPCSTR bsButtonName);

	//************************************
	// Function:  SetTooltip
	// Param[in]: comboctrl		    The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Param[in]: wsTooltip	         The  tooltip of the control.
	// Return: void.
	// Remarks: Set the tooltip of the control.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetTooltip(FR_StyleComboGalleryCtrl comboctrl, FS_LPCWSTR wsTooltip);

	//************************************
	// Function:  DisableHighContrastThemeImage
	// Param[in]: comboctrl		    The FR_StyleComboGalleryCtrl whose control is obtained.	
	// Return: void
	// Remarks: In high contrast mode, whether to change the icon to a high contrast color.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	DisableHighContrastThemeImage(FR_StyleComboGalleryCtrl comboctrl);
};


class CFR_StyleMenuButton_V14 //Internal use
{
public:
	//************************************
	// Function:  GetButton
	// Param[in]: button			The FR_StyleMenuButton whose button is obtained, it get from FRRibbonBackStageViewItemModifiedToRibbonStyleButton.	
	// Return: The specified button like CButton with FR_StyleMenuButton type.
	// Remarks: Gets the specified button.
	// Notes: The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID GetButton(FR_StyleMenuButton button);

	//************************************
	// Function:  Release
	// Param[in]: button			The FR_StyleMenuButton whose button is obtained.			
	// Return: void.
	// Remarks: Release the specified button.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void Release(FR_StyleMenuButton button);
	
	//************************************
	// Function:  SetMenu
	// Param[in]: button			The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: hMenu			    A handle to the attached Windows menu.	
	// Param[in]: menuIDArray		The ID of the MenuItem array.	
	// Param[in]: menuBitmapArray	The bitmap of the MenuItem array,the size can only be 16*16.	
	// Return: void.
	// Remarks: menuIDArray is pair with menuBitmapArray
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void SetMenu(FR_StyleMenuButton button, FS_LPVOID hMenu, FS_DWordArray menuIDArray, FS_PtrArray menuBitmapArray);

	//************************************
	// Function:  SetDefaultClick
	// Param[in]: button			The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: bDefaultClick		Set TRUE is allow default (on button text/image) processing.
	// Return: void.
	// Remarks: Allow default (on button text/image) processing.
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void SetDefaultClick(FR_StyleMenuButton button, FS_BOOL bDefaultClick);

	//************************************
	// Function:  GetMenuResult
	// Param[in]: button			The FR_StyleMenuButton whose button is obtained.		
	// Return: FS_INT32.			-1 some error occurs, other result is from TrackPopupMenu api.
	// Remarks: The value of this member variable is zero if the user cancels the menu without making a selection or if an error occurs.
	// Notes:An identifier that indicates which item the user selected from the pop-up menu. The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 GetMenuResult(FR_StyleMenuButton button);

	//************************************
	// Function:  SetImage
	// Param[in]: button	            The FR_StyleMenuButton whose button is obtained.		
	// Param[in]: pBitmap	            Set button image.
	// Param[in]: nImgWidth	            The image width.
	// Param[in]: nImgHeight	        The image height.
	// Notes:  The function can only be used for Windows.
	// Return: void
	// Remarks: Set the image icon of button.	
	// Deprecated: Internal use.
	//************************************
	static void SetImage(FR_StyleMenuButton button, FS_DIBitmap pBitmap, FS_INT32 nImgWidth, FS_INT32 nImgHeight);

	//************************************
	// Function:  SetImage2	
	// Param[in]: button	     The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: wsBitmapName	 For loading PDF images, the name is retrieved from the BOOKMARK of the PDF file：FoxitReader\res\ribbon\ribbonimage.pdf.
	// Param[in]: nImgWidth	    The image width
	// Param[in]: nImgHeight	The image height
	// Notes:  The function can only be used for Windows.
	// Return: void
	// Remarks:  Set the image icon of button.	
	// Deprecated: Internal use.
	//************************************
	static void SetImage2(FR_StyleMenuButton button, FS_WideString wsBitmapName, FS_INT32 nImgWidth, FS_INT32 nImgHeight);

	//************************************
	// Function:  SetAlignStyle
	// Param[in]: button	     The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: nAlignStyle	 The align style.
	// Notes:  The function can only be used for Windows.
	// Return: void
	// Remarks: Set AlignStyle of the button.
	// Deprecated: Internal use.
	//************************************
	static void SetAlignStyle(FR_StyleMenuButton button, FRRibbonStyleTextAlignType nAlignStyle);

	//************************************
	// Function:  SetImageSide
	// Param[in]: button	     The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: nImageSide	 The image slide type.
	// Notes: The function can only be used for Windows. 
	// Return: void
	// Remarks: Set the image location of the menu.
	// Deprecated: Internal use.
	//************************************
	static void SetImageSide(FR_StyleMenuButton button, FRRibbonStyleImageSide nImageSide);

	//************************************
	// Function:  SetFlatStyle
	// Param[in]: button	     The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: nFlatStyle	 The flat slide.
	// Notes: The function can only be used for Windows. 
	// Return: void
	// Remarks: Set flat style of the button
	// Deprecated: Internal use.
	//************************************
	static void SetFlatStyle(FR_StyleMenuButton button, FRRibbonStyleFlatType nFlatStyle);
	
	//************************************
	// Function:  SetVertMargin
	// Param[in]: button	     The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: nVerMargin	 The vertical margin.
	// Notes:  The function can only be used for Windows.
	// Return: void
	// Remarks: Set the margin in the vertical direction of the Button
	// Deprecated: Internal use.
	//************************************
	static void SetVertMargin(FR_StyleMenuButton button, FS_INT32 nVerMargin);

	//************************************
	// Function:  EnablePopupWnd	
	// Param[in]: button	            The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: PopupCreateProc		Create dialog callback.
	// Param[in]: PopupDestoryProc		Destroy dialog box callback.
	// Param[in]: pClientData			The client data associated with button. 
	// Notes:  The function can only be used for Windows.
	// Return: void
	// Remarks: Click the drop-down button to display the dialog box
	// Deprecated: Internal use.
	//************************************
	static void EnablePopupWnd(FR_StyleMenuButton button, FRPopupCreateProc CreateProc, FRPopupDestoryProc DestoryProc, FS_LPVOID pClientData);

	//************************************
	// Function:  SetDropdownProc	
	// Param[in]: button	     The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: proc		     Drop-down menu callback.
	// Param[in]: pClientData	 The client data associated with button. 
	// Notes:  The function can only be used for Windows.
	// Return: void
	// Remarks: Set drop-down menu callback.
	// Deprecated: Internal use.
	//************************************
	static void SetDropdownProc(FR_StyleMenuButton button, FRDropDownProc proc, FS_LPVOID pClientData);

	//************************************
	// Function:  SetAppearance	
	// Param[in]: button		 The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: bLargeArrow	 If the FR_StyleMenuButton object is large arrow.
	// Param[in]: bRightArrow	 If the FR_StyleMenuButton object is right arrow.
	// Notes: The function can only be used for Windows.
	// Return: void
	// Remarks: Set appearance of the button.
	// Deprecated: Internal use.
	//************************************
	static void SetAppearance(FR_StyleMenuButton button, FS_BOOL bLargeArrow, FS_BOOL bRightArrow);

	//************************************
	// Function:  SetTooltip
	// Param[in]: button		The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: wsTooltip  	The input tooltip of the menu button.
	// Return: void
	// Remarks: Sets the tooltip of the button.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// Deprecated: Internal use.
	// See:
	//************************************
	static void SetTooltip(FR_StyleMenuButton button, FS_WideString wsTooltip);

	//************************************
	// Function:  SetDescription
	// Param[in]: button		    The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: wsDescription	    The description of the button.
	// Return: void.
	// Remarks: Set the description of the button.
	// Notes:  The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// Deprecated: Internal use.
	// See: 
	//************************************
	static void SetDescription(FR_StyleMenuButton button, FS_WideString wsDescription);

	//************************************
	// Function:  EnableHelpLink
	// Param[in]: button		   The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: bEnable	       If the menu button can be enable.
	// Param[in]: bsButtonName	   Set the tooltip info.
	// Return: void.
	// Remarks: Set Tell Me More in Tooltip. bsButtonName can be used with the button name.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void EnableHelpLink(FR_StyleMenuButton button, FS_BOOL bEnable, FS_ByteString bsButtonName);

	//************************************
	// Function:  SetMenu2
	// Param[in]: button			    The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: hMenu			        A handle to the attached Windows menu.	
	// Param[in]: menuIDArray		    The ID of the MenuItem array.	
	// Param[in]: menuBitmapNameArray	The bitmap name of the MenuItem array.	
	// Return: void.
	// Remarks: menuIDArray is pair with menuBitmapArray
	// Notes:  The function can only be used for Windows.
	// Deprecated: Internal use.
	//************************************
	static void SetMenu2(FR_StyleMenuButton button, FS_LPVOID hMenu, FS_DWordArray menuIDArray, FS_WideStringArray menuBitmapNameArray);

	//************************************
	// Function:  SetRoundRadius
	// Param[in]: button		   The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: ptRoundRadius	   The input round radius.	
	// Return: void.
	// Remarks: Set round radius of the menubutton.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetRoundRadius(FR_StyleMenuButton button, FS_DevicePoint ptRoundRadius);

	//************************************
	// Function:  SetDefaultStyle
	// Param[in]: button		   The FR_StyleMenuButton whose button is obtained.	
	// Param[in]: option	   The input button style.	
	// Return: void.
	// Remarks: Set button style of the menubutton.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void SetDefaultStyle(FR_StyleMenuButton button, FR_ButtonStyleOption option);

	//************************************
	// Function:  DisableHighContrastThemeImage
	// Param[in]: button		   The FR_StyleMenuButton whose button is obtained.	
	// Return: void
	// Remarks: In high contrast mode, whether to change the icon to a high contrast color.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	// See:
	// Deprecated: Internal use.
	//************************************
	static void	DisableHighContrastThemeImage(FR_StyleMenuButton button);
};

class CFR_CommonControl_V14
{
public:
	//************************************
    // Function:  AddMenuItem
    // Param[in]: commonControl	The input ribbon control object.
    // Param[in]: nControlType	The input type of ribbon control.
    // Param[in]: name			The input name of ribbon control.
    // Param[in]: lpwsTitle		The input title of ribbon control.
    // Param[in]: nPos			The input position of ribbon control.
    // Param[in]: bChangeFun	When the user clicks the sub item, whether the parent's function should be change to the sub item's. Sets it FALSE as default.
	// Param[in]: bChangeImage	When the user clicks the sub item, whether the parent's icon should be change to the sub item's. Sets it FALSE as default.
    // Return: The new sub menu item of the ribbon control.
    // Remarks: Add a new sub menu item to the ribbon control. Support type like BUTTON,DROPDOWNBUTTON,DROPDOWNACTION,CHECKBOX.
	// Notes: The api is for cross-platfrom. FRRibbonElementAddSubItem is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static FR_CommonControl AddMenuItem(FR_CommonControl commonControl, FR_Common_Control_Type nControlType, const FS_CHAR* name, FS_LPCWSTR lpwsTitle, FS_INT32 nPos, FS_BOOLEAN bChangeFun, FS_BOOLEAN bChangeImage);

	//************************************
	// Function:  SetExecuteProc
    // Param[in]: commonControl	The input ribbon control object.
    // Param[in]: proc			The callback will be called when the user clicks the ribbon control.
	// Return: void
    // Remarks: Sets the callback function that will be called when the user clicks the ribbon control.
	// Notes: The api is for cross-platfrom. FRRibbonElementSetExecuteProc is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void SetExecuteProc(FR_CommonControl commonControl, FRExecuteProc proc);

	//************************************
	// Function:  SetComputeEnabledProc
    // Param[in]: commonControl	The input ribbon control object.
    // Param[in]: proc			The callback will be called to determine whether the ribbon control is enabled or not.
	// Return: void
    // Remarks: Sets the callback function that will be called to determine whether the ribbon control is enabled or not.
	// Notes: The api is for cross-platfrom. FRRibbonElementSetComputeEnabledProc is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void SetComputeEnabledProc(FR_CommonControl commonControl, FRComputeEnabledProc proc);
	
    //************************************
    // Function:  SetAppearanceSettingProc
    // Param[in]: commonControl	The input ribbon control object.
    // Param[in]: proc			The callback will be called to set the ribbon control lightmode and darkmode.
    // Return: void
    // Remarks: Sets the callback function that will be called to set the ribbon control lightmode and darkmode.
    // Notes:Only for Mac
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void SetAppearanceSettingProc(FR_CommonControl commonControl, FRAppearanceSettingProc proc);

	//************************************
	// Function:  DoExecuteProc
    // Param[in]: commonControl	The input ribbon control object.
	// Return: void
    // Remarks: Executes the <a>FRExecuteProc</a>() associated with the ribbon control.
	// Notes: The api is for cross-platfrom. FRRibbonElementDoExecuteProc is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void DoExecuteProc(FR_CommonControl commonControl);

	//************************************
	// Function:  IsEnabled
    // Param[in]: commonControl	The input ribbon control object.
    // Return: <a>TRUE</a> if the ribbon control is enabled, otherwise <a>FALSE</a>.
    // Remarks: Checks whether the ribbon control is enabled or not.
	// Notes: The api is for cross-platfrom. FRRibbonElementIsEnabled is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static FS_BOOLEAN IsEnabled(FR_CommonControl commonControl);

	//************************************
	// Function:  SetAccel
    // Param[in]: commonControl	The input ribbon control object.
	// Param[in]: bAlt			Whether the <Italic>Alt</Italic> key is pressed down or not.
	// Param[in]: bShift		Whether the <Italic>Shift</Italic> key is pressed down or not.
	// Param[in]: bCtrl			Whether the <Italic>Ctrl</Italic> key is pressed down or not.
	// Param[in]: key			The input accelerator key.
	// Return: void
    // Remarks: Sets the accelerator key of the ribbon control.
	// Notes: The api is for cross-platfrom. FRRibbonElementSetAccel is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void SetAccel(FR_CommonControl commonControl, FS_BOOLEAN bAlt, FS_BOOLEAN bShift, FS_BOOLEAN bCtrl, FS_CHAR key);

	//************************************
	// Function:  GetAccel
    // Param[in]: commonControl	The input ribbon control object.
	// Param[out]: bAlt			It receives <a>TRUE</a> if the <Italic>Alt</Italic> key is pressed down.
	// Param[out]: bShift		It receives <a>TRUE</a> if the <Italic>Shift</Italic> key is pressed down.
	// Param[out]: bCtrl		It receives <a>TRUE</a> if the <Italic>Ctrl</Italic> key is pressed down.
	// Param[out]: key			It receives the accelerator key
	// Return: void
    // Remarks: Gets the accelerator key of the ribbon control.
	// Notes: The api is for cross-platfrom. FRRibbonElementGetAccel is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void GetAccel(FR_CommonControl commonControl, FS_BOOLEAN* bAlt, FS_BOOLEAN* bShift, FS_BOOLEAN* bCtrl, FS_CHAR* key);

	//************************************
	// Function:  SetTooltip
    // Param[in]: commonControl	The input ribbon control object.
    // Param[in]: lpwsTooltip	The input tooltip of the ribbon control.
	// Return: void
    // Remarks: Sets the tooltip of the ribbon control.
	// Notes: The api is for cross-platfrom. FRRibbonElementSetTooltip is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void SetTooltip(FR_CommonControl commonControl, FS_LPCWSTR lpwsTooltip);

	//************************************
	// Function:  GetTooltip
    // Param[in]: commonControl	The input ribbon control object.
    // Param[out]: wsTooltip	It receives the tooltip of the ribbon control.
	// Return: void
    // Remarks: Gets the tooltip of the ribbon control.
	// Notes: The api is for cross-platfrom. FRRibbonElementGetTooltip is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void GetTooltip(FR_CommonControl commonControl, FS_WideString* wsTooltip);

	//************************************
	// Function:  SetTitle
    // Param[in]: commonControl	The input ribbon control object.
    // Param[in]: lpwsTitle		The input title of the ribbon control.
	// Return: void
    // Remarks: Sets the title of the ribbon control.
	// Notes: The api is for cross-platfrom. FRRibbonElementSetTitle is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void SetTitle(FR_CommonControl commonControl, FS_LPCWSTR lpwsTitle);

	//************************************
	// Function:  GetTitle
    // Param[in]: commonControl	The input ribbon control object.
    // Param[out]: wsTitle		It receives the title of the ribbon control.
	// Return: void
    // Remarks: Gets the title of the ribbon control.
	// Notes: The api is for cross-platfrom. FRRibbonElementGetTitle is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void GetTitle(FR_CommonControl commonControl, FS_WideString* wsTitle);

	//************************************
	// Function:  SetImage
    // Param[in]: commonControl	The input ribbon control object.
	// Param[in]: largeBitmap	The input 32*32 bitmap.
	// Param[in]: smallBitmap	The input 16*16 bitmap.
	// Return: void
    // Remarks: Sets the icon of the ribbon control. The ribbon control contains a large icon and a small icon.
	// Notes: Only use large icon under mac. The api is for cross-platfrom. FRRibbonElementSetImage is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void SetImage(FR_CommonControl commonControl, FS_DIBitmap largeBitmap, FS_DIBitmap smallBitmap);

	//************************************
	// Function:  SetVisible
    // Param[in]: commonControl	The input ribbon control object.
    // Param[in]: bVisible		<a>TRUE</a> if the ribbon control is visible, otherwise <a>FALSE</a>.
	// Return: void
    // Remarks: Sets the ribbon control to be visible or not.
	// Notes: The api is for cross-platfrom. FRRibbonElementSetVisible is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void	SetVisible(FR_CommonControl commonControl, FS_BOOLEAN bVisible);
	
	//************************************
	// Function:  GetVisible
    // Param[in]: commonControl	The input ribbon control object.
    // Return: <a>TRUE</a> if the ribbon control is visible, otherwise <a>FALSE</a>.
    // Remarks: Checks whether the ribbon control is visible or not.
	// Notes: The api is for cross-platfrom. FRRibbonElementGetVisible is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static FS_BOOLEAN GetVisible(FR_CommonControl commonControl);

	//************************************
	// Function:  GetType
    // Param[in]: commonControl     The input ribbon control object.
    // Return: The type of the ribbon control.
    // Remarks: Gets the type of the ribbon control.
	// Notes: The api is for cross-platfrom. FRRibbonElementGetType is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static FR_Common_Control_Type GetType(FR_CommonControl commonControl);

	//************************************
	// Function:  GetName
    // Param[in]: commonControl	The input ribbon control object.
    // Param[out]: outName		It receives the name of the ribbon control.
	// Return: void
    // Remarks: Gets the name of the ribbon control.
	// Notes: The api is for cross-platfrom. FRRibbonElementGetName is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static void GetName(FR_CommonControl commonControl, FS_ByteString* outName);

	//************************************
    // Function:  GetMenuItemCount
    // Param[in]: commonControl	The input ribbon control object.
    // Return: The count of the sub menu items.
    // Remarks: Gets the count of the sub menu items.
	// Notes: The api is for cross-platfrom. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static FS_INT32	GetMenuItemCount(FR_CommonControl commonControl);

	//************************************
    // Function:  FindMenuItemByIndex
    // Param[in]: commonControl	The input ribbon control object.
	// Param[in]: nIndex		The specified index.
    // Return: The found ribbon control.
    // Remarks: Gets the ribbon control by index.
	// Notes: The api is for cross-platfrom. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static FR_CommonControl FindMenuItemByIndex(FR_CommonControl commonControl, FS_INT32 nIndex);

	//************************************
    // Function:  GetMenuItemByName
    // Param[in]: commonControl	The input ribbon control object.
	// Param[in]: name			The specified name.
    // Return: The found ribbon control.
    // Remarks: Gets the ribbon control by name.
	// Notes: The api is for cross-platfrom. 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See:
	//************************************
    static FR_CommonControl GetMenuItemByName(FR_CommonControl commonControl, const FS_CHAR* name);

	//************************************
	// Function:  GetCategoryName
    // Param[in]: commonControl	The input ribbon control object.
	// Param[out]: outName		(Filled by the method) A string buffer to receive the name.	
	// Return: void.
    // Remarks:	Gets the category name of the specified control.
	// Notes:  The api is for cross-platfrom. FRRibbonElementGetCategoryName is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: 
	//************************************
    static void GetCategoryName(FR_CommonControl commonControl, FS_ByteString* outName);

	//************************************
	// Function:  GetPanelName
    // Param[in]: commonControl	The input ribbon control object.
	// Param[out]: outName		(Filled by the method) A string buffer to receive the name.	
	// Return: void.
    // Remarks:	Gets the panel name of the specified control.
	// Notes: The api is for cross-platfrom. FRRibbonElementGetPanelName is only for windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: 
	//************************************
    static void GetPanelName(FR_CommonControl commonControl, FS_ByteString* outName);

    //************************************
    // Function:  IsChecked
    // Param[in]: commonControl     The input ribbon control object.
    // Return: <a>TRUE</a> if the ribbon control as check box is checked, otherwise not.
    // Remarks: Checks whether the ribbon control as check box is checked or not.
    // Notes: This interface only supports <a>FR_CommonControl_CHECKBOX</a> type, others return false.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static FS_BOOLEAN IsChecked(FR_CommonControl commonControl);

    //************************************
    // Function:  SetCheck
    // Param[in]: commonControl     The input ribbon control object.
    // Param[in]: bCheck			<a>TRUE</a> if you want to set the ribbon check box to be checked.
    // Return: void
    // Remarks: Whether to set the ribbon check box to be checked or not.
    // Notes: This interface only supports <a>FR_CommonControl_CHECKBOX</a> type.
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
    // See:
    //************************************
    static void SetCheck(FR_CommonControl commonControl, FS_BOOLEAN bCheck);

	//************************************
	// Function:  SetClientData
	// Param[in]: commonControl     The input ribbon control object.
	// Param[in]: pClientData       The data pointer stored in client.
	// Return: void
	// Remarks: Saved data pointer to the CommonControl object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 4.1.2
	// See:
	//************************************
	static void SetClientData(FR_CommonControl commonControl, FS_LPVOID pClientData);

	//************************************
	// Function:  SetDropDownAddElementProc
	// Param[in]: ribbonElement	  The input ribbon element object.
	// Param[in]: proc	          The proc to add elelment when drop down the ribbon element.
	// Return: void
	// Remarks: Add elelment when drop down the ribbon element.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void SetDropDownAddElementProc(FR_CommonControl commonControl, FRRibbonElementDropDownAddElementProc proc);

	//************************************
	// Function:  SetTooltipHasHelp
	// Param[in]: ribbonElement	  The input ribbon element object.
	// Param[in]: bshowHelpLink	  TRUE: show help link.
	// Return: void
	// Remarks: Set if need show help link.
	// Notes: The function can only be used for Windows.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void	SetTooltipHasHelp(FR_CommonControl commonControl, FS_BOOL bshowHelpLink);
};

class CFR_RibbonHandler : public CReader_RibbonHandler
{
public:
	CFR_RibbonHandler(FR_RibbonHandlerCallbacks callbacks);
	virtual ~CFR_RibbonHandler();

public:
	virtual	FX_BOOL						Ribbon_OnGetName(UINT nCmdId, CFX_ByteString& csName) override;
	virtual	FX_BOOL						Ribbon_OnGetTitle(UINT nCmdId, CFX_WideString& csTitle) override;
	virtual	FX_BOOL						Ribbon_OnGetTooltip(UINT nCmdId, CFX_WideString& csTooltip) override;
	virtual	FX_BOOL						Ribbon_OnGetDescription(UINT nCmdId, CFX_WideString& csDescription) override;
	virtual FX_BOOL						Ribbon_OnGetIconList(HBITMAP& hSmallImageList) override;
	virtual FX_BOOL						Ribbon_OnGetIcon(UINT nCmdId, CFX_DIBitmap& pLargeImage, CFX_DIBitmap& pSmallImage) override;
	virtual FX_BOOL						Ribbon_OnCommand(UINT nCmdId) override;
	virtual FX_BOOL						Ribbon_OnUpdateCmdUI(UINT nCmdId, CCmdUI* pCmdUI) override;
	virtual void						Ribbon_OnChangeLanguage() override;
	virtual void						Ribbon_OnRelease() override;

protected:
	FR_RibbonHandlerCallbacksRec m_callbacks;
};

class CFR_RibbonHandler_V17
{
public:
	static FR_RibbonHandler Create(FR_RibbonHandlerCallbacks callback);
	static void Delete(FR_RibbonHandler handler);
};

class CFR_CustomContro_V17
{
public:
	//************************************
	// Function:  ShowColorDialog
	// Param[in]: curFillColor		    The current fill color.	
	// Param[in]: curBorderColor	    The current border color.
	// Param[in]: bOnlyFillColor	    If only fill color.
	// Param[in]: func	                The input callback fun.
	// Param[in]: clientData	        The input client data.
	// Param[in]: parentWnd	            The parent HWND.
	// Param[in]: pt	                The input show position of the palette.
	// Return: FS_BOOLEAN.
	// Remarks: Show custom color dialog.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN ShowColorPalette(const FS_ARGB curFillColor, const FS_ARGB curBorderColor,
		FS_BOOLEAN bOnlyFillColor, FRFuncOnColorChange func, FS_LPVOID clientData, FS_HWND parentWnd, FS_DevicePoint pt);	

	//************************************
	// Function:  GetCustomColors
	// Param[in/out]: colorArr		    Get the color array with only fill color.
	// Return: FS_BOOL.   Get success.
	// Remarks: Gets the color array with only fill color.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetCustomColors(FS_DWordArray* colorArr);

	//************************************
	// Function:  GetCustomColors2
	// Param[in/out]: colorArr		    Get the color array with fill color and stroke color.
	// Return: FS_BOOL.   Get success.
	// Remarks: Gets the color array with only fill color and stroke color.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL GetCustomColors2(FS_DWordArray* colorArr);

	//************************************
	// Function:  HideColorPalette
	// Return: void.
	// Remarks: Hide color palette.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void HideColorPalette();

	//************************************
	// Function:  IsColorPaletteShow	
	// Return: FS_BOOL.
	// Remarks: Check if the color palette is show.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOL IsColorPaletteShow();

	//************************************
	// Function:  ShowColorDialog
	// Param[in]: curFillColor		    The current fill color.	
	// Param[in]: curBorderColor	    The current border color.
	// Param[in]: bOnlyFillColor	    If only fill color.
	// Param[in]: func	                The input callback fun.
	// Param[in]: clientData	        The input client data.
	// Param[in]: parentWnd	            The parent HWND.	
	// Return: FS_BOOLEAN.
	// Remarks: Show custom color dialog.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN ShowColorDialog(const FS_ARGB curFillColor, const FS_ARGB curBorderColor,
		FS_BOOLEAN bOnlyFillColor, FRFuncOnColorChange func, FS_LPVOID clientData, FS_HWND parentWnd);

	//************************************
	// Function:  ShowColorDialog
	// Param[in]: curFillColor		    The current fill color.	
	// Param[in]: curBorderColor	    The current border color.
	// Param[in]: bOnlyFillColor	    If only fill color.
	// Param[in]: func	                The input callback fun.
	// Param[in]: clientData	        The input client data.
	// Param[in]: parentWnd	            The parent HWND.
	// Param[in]: pt	                The input show position of the palette.
	// Param[in]: bTransparent	        Requires support for gradual transparency after the mouse moves away.
	// Param[in]: bShowAccelKey	        Requeres show acc key.
	// Return: FS_BOOLEAN.
	// Remarks: Show custom color dialog.
	// Notes:  It only for windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN ShowColorPalette2(const FS_ARGB curFillColor, const FS_ARGB curBorderColor,
		FS_BOOLEAN bOnlyFillColor, FRFuncOnColorChange func, FS_LPVOID clientData, FS_HWND parentWnd, FS_DevicePoint pt, FS_BOOLEAN bTransparent, FS_BOOLEAN bShowAccelKey);

	//************************************
	// Function:  SetTransparent	
	// Param[in]: bTransparency		    Set whether to display transparently.
	// Return: void.
	// Remarks: Set whether to display transparently.
	// Notes:  It only for windows platform.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetTransparent(FS_BOOL bTransparency);
};

class CFR_FloatBarManager_V17
{
public:	
	//************************************
	// Function:  CreateFloatyBar
	// Param[in]: point		            The position of the floaty bar.
	// Param[in]: floatyBtnArray	    The FR_RIBBONBUTTONINFO array.
	// Param[in]: func					The floaty button fun.
	// Param[in]: nRows	                The rows that button shows.
	// Param[in]: bSyncOriginalCheck	If sync the origin check.
	// Return: void.
	// Remarks: Create floaty bar.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See: 
	// Deprecated: Internal use.
	//************************************
	static void CreateFloatyBar(FS_DevicePoint point, FS_PtrArray floatyBtnArray, FR_FloatyBtnFunc func, FS_INT32 nRows, FS_BOOL bSyncOriginalCheck);

	//************************************
	// Function:  DestoryRibbonFloaty
	// Return: void.
	// Remarks: Destory ribbon floaty window.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void DestoryRibbonFloaty();

	//************************************
	// Function:  SetFloatyTransparency
	// Param[in]: nTransparency	    The input transparency.
	// Return: void.
	// Remarks: Set floaty transparency.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetFloatyTransparency(FS_BYTE nTransparency);

	//************************************
	// Function:  GetFloatyWnd	
	// Return: FS_HWND.
	// Remarks: Get floaty HWND.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_HWND GetFloatyWnd();	
	
	//************************************
	// Function:  ShowArrangeFloatyBar	
	// Param[in]: point       The position of the floaty bar showing.	
	// Param[in]：parentWnd   The HWND of parent.
	// Return: void.
	// Remarks: Show arrange float bar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void ShowArrangeFloatyBar(FS_DevicePoint point,  FS_HWND parentWnd);

	//************************************
	// Function:  HideArrangeFloatyBar	
	// Return: void.
	// Remarks: Hide Arrange FloatyBar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void HideArrangeFloatyBar();

	//************************************
	// Function:  GetButtonPos	
	// Param[in]: csBtnName     The input button name.
	// Return: FS_INT32.
	// Remarks: Get the button position.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_INT32 GetButtonPos(FS_LPCSTR csBtnName);

	//************************************
	// Function:  SetReferenceRects	
	// Param[in]: rcAnnot     The rect of annot.
	// Param[in]: rcDocview   The rect of floatbar view.
	// Param[in]: eSide       The location of the floatbar.
	// Return: void.
	// Remarks: Set the rect of floatbar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetReferenceRects(FS_Rect rcAnnot, FS_Rect rcDocview, FR_FLOATBAR_SIDE eSide);

	//************************************
	// Function:  SetMarkButton	
	// Param[in]: nCrlBtnType The button type, one color or two-color.
	// Param[in]: nIndex      The input color index.
	// Param[in]: nCrlBtnType The input color type.
	// Return: void.
	// Remarks: Set the current selected button for the ColorPalette.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetMarkButton(FS_INT32 nIndex, FS_INT32 nCrlBtnType);

	//************************************
	// Function:  SetTransparent
	// Param[in]: bTransparency  Set if it is transparent.
	// Return: void.
	// Remarks: Set if it's support transparent.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static void SetTransparent(FS_BOOL bTransparency);
	
	//************************************
	// Function:  IsTransparent	
	// Return: FS_BOOLEAN.
	// Remarks: Get if it's support transparent.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	// See:
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN IsTransparent();
};

#ifdef __cplusplus
};
#endif
#endif

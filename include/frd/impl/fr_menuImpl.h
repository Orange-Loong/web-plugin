/** @file fr_menuImpl.h.
 * 
 *  @brief Foxit Reader Plugin SDK menu head file.
 */
 
#ifndef FR_MEMUIMPL_H
#define FR_MENUIMPL_H

#ifndef FR_MENUEXPT_H
#include "../fr_menuExpT.h"
#endif

#include "../../../InternalSDK/include/fr_sdk/fr_IMenu.h"


#ifdef __cplusplus
extern "C"{
#endif

class CFR_CustomerOwnerDrawMenuHandle : public CReader_OwnerDrawMenuHandle
{
public:
    CFR_CustomerOwnerDrawMenuHandle(FR_MenuOwnerDrawCallbacksRec callbacks);
    virtual ~CFR_CustomerOwnerDrawMenuHandle();
public:
    //************************************
    // Function:  OnMeasureItem
    // Param[in]: pMenuItem    The input menu item.
    // Return:	The size of menuItem after calculate.
    // Remarks:
    // Notes:
    //************************************
	virtual SIZE OnMeasureItem(CReader_MenuItem* pMenuItem);

    //************************************
    // Function:  OnDrawItem
    // Param[in]: pMenuItem  The input menu item.
    // Param[in]: pDC        The CDC object.
    // Param[in]: rect       The rect area of the menu item.
    // Return:
    // Remarks:	Draw the menu item in plugin.
    // Notes:
    //************************************
	virtual FX_BOOL OnDrawItem(CReader_MenuItem* pMenuItem, CDC* pDC, const CRect& rect);

    //************************************
    // Function:  OnInitMenuPopup
    // Param[in]: pMenu
    // Return:	void
    // Remarks:	Init menu
    // Notes:
    //************************************
    virtual void OnInitMenuPopup(CReader_Menu* pMenu);
protected:
    FR_MenuOwnerDrawCallbacksRec m_menuCallbacks;
};

class CFR_MenuBar_V1
{
public:
	//************************************
	// Function:  GetMenuCount
	// Param[in]: menuBar			The menu bar for which the number of menus is obtained.
	// Return: The number of menus in the menu bar, not including submenus. Return 0 if <param>menuBar</param> is <a>NULL</a>.
	// Remarks: Gets the number of menus in menu bar.
	// Notes:	
	// See: FRMenuBarGetMenuByIndex
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	//************************************
	static FS_INT32	GetMenuCount(FR_MenuBar menuBar);

	//************************************
	// Function:  GetMenuByIndex
	// Param[in]: menuBar			The menu bar for which the menu is located.
	// Param[in]: iIndex			The index of the menu to obtained.The range of <param>iIndex</param> is 0 to (<Italic>GetMenuCount()</Italic>);
	// Return:	The menu with the specified index. It returns <a>NULL</a> if there is no such menu or if <param>menuBar</param> 
	// is <a>NULL</a>.
	// Remarks: Gets the menu with the specified index.
	// Notes:	
	// See: FRMenuBarGetMenuByIndex	
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	//************************************
	static FR_Menu  GetMenuByIndex(FR_MenuBar menuBar, FS_INT32 iIndex);

	//************************************
	// Function:  GetMenuByName
	// Param[in]: menuBar			The menu bar for which the menu is located.
	// Param[in]: szName			The menu name.
	// Return:	The menu with the specified name. It returns <a>NULL</a> if there is no such menu or if <param>menuBar</param> 
	// is <a>NULL</a>.
	// Remarks: Gets the menu with the specified name. 		
	// See: FRMenuBarGetMenuByIndex
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	//************************************
	static FR_Menu  GetMenuByName(FR_MenuBar menuBar, FS_LPCSTR szName);

	//************************************
	// Function:  AddMenu
	// Param[in]: menuBar			The menu bar into which the menu is added.
	// Param[in]: menu				The menu to add.
	// Param[in]: szItemTitle		The title of the menu to display on menu bar.
	// Param[in]: szItemName		The name  to indicate the menu.
	// Param[in]: iIndex			The inserted location. The range of <param>iIndex</param> is 0 to <a>FRMenuBarGetMenuCount</a>().
	// Return: <a>TRUE</a> for success. It returns <a>FALSE</a> if <param>menu</param> is <a>NULL</a> or the <param>szItemName</param> 
	// has existed.
	// Remarks: Inserts a menu into a menu bar. It does nothing if the <param>menuBar</param> or <param>menu</param> is <a>NULL</a>.
	// Notes: It is strongly encouraged that you begin your menu names with the plug-in name 
	// (separated by a colon) to avoid name collisions when more than one plug-in is present. For example, if my 
	// plug-in is named <Italic>myPlug</Italic>, it might add a menu whose name is <Italic>myPlug:Options</Italic>.	
	// See: FRMenuBarDeleteMenu
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	//************************************
	static FS_BOOL	AddMenu(FR_MenuBar menuBar, FR_Menu menu, FS_LPCWSTR szItemTitle, FS_LPCSTR szItemName, FS_INT32 iIndex);

	//************************************
	// Function: GetMenuIndex 
	// Param[in]: menuBar			The menu bar whose menu's index is obtained.
	// Param[in]: menu				The menu whose index is obtained.
	// Return: The index of specified menu. The range of the return value is 0 to (<a>FRMenuBarGetMenuCount</a>-1).
	// Remarks: Gets the index of specified menu bar.
	// Notes:	
	// See: FRMenuBarGetMenuByIndex
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	//************************************
	static FS_INT32	GetMenuIndex(FR_MenuBar menuBar, FR_Menu menu);

	//************************************
	// Function:  DeleteMenu
	// Param[in]: menuBar			The menu bar whose menu is deleted.
	// Param[in]: menu				The menu to delete.
	// Return: <a>TRUE</a> for success, <a>FALSE</a> if <param>menuBar</param> or <param>menu</param> is <a>NULL</a>.
	// Remarks: Removes the menu from menu bar, then destroy the menu.
	// Notes: This method will destroy the specified menu, don't call FRMenuRelease to destroy the menu again.	
	// See: FRMenuBarAddMenu
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
	//************************************
	static FS_BOOL	DeleteMenu(FR_MenuBar menuBar, FR_Menu menu);
};

class CFR_Menu_V1
{
public:
    //************************************
    // Function:  New
    // Return: The newly created menu.
    // Remarks: Creates a new menu.
    // Notes:
    // See: FRMenuRelease
    // See: FRMenuBarGetMenuByName
    // See: FRMenuBarAddMenu
    // See: FRMenuBarDeleteMenu
    //************************************
    static FR_Menu		New();

    //************************************
    // Function:  Release
    // Param[in]: menu				The menu to be released.
    // Return:
    // Remarks: Removes the specified menu and releases it.
    // Notes:
    //************************************
    static void		Release(FR_Menu menu);

    //************************************
    // Function:  GetParentMenuItem
    // Param[in]: menu				The menu whose parent menu item is obtained.
    // Return: The parent menu item for which the specified menu is a submenu. <a>NULL</a> if the specified menu
    // is not a submenu.
    // Remarks: Gets the parent menu item for the specified menu.
    // Notes:
    // See: FRMenuGetMenuItemByIndex
    // See: FRMenuGetMenuItemByName
    //************************************
    static FR_MenuItem	GetParentMenuItem(FR_Menu menu);

    //************************************
    // Function:  GetMenuItemByIndex
    // Param[in]: menu				The menu whose item is obtained.
    // Param[in]: iIndex			The index of the menu item in <param>menu</param> to obtained. The index range
    // is 0 to (<a>FRMenuGetMenuItemCount</a>-1).
    // Return: The specified menu item. It returns <a>NULL</a> if <param>menu</param> is <a>NULL</a>, if the index
    // is less than zero, or the index is greater than the number of menu items in the menu.
    // Remarks:	Gets the menu item at the specified location in the specified menu.
    // Notes:
    // See: FRMenuGetParentMenuItem
    // See: FRMenuGetMenuItemByName
    // See: FRMenuGetMenuItemCount
    //************************************
    static FR_MenuItem	GetMenuItemByIndex(FR_Menu menu, FS_INT32 iIndex);

    //************************************
    // Function:  GetMenuItemByName
    // Param[in]: menu				The menu whose item is obtained.
    // Param[in]: csItemName		The menu item name.
    // Return: The specified menu item. It returns <a>NULL</a> if <param>menu</param> is <a>NULL</a>, if the
    // named menu item is not exist.
    // Remarks: Gets the menu item by the specified name in the specified menu.
    // Notes:
    // See: FRMenuGetParentMenuItem
    // See: FRMenuGetMenuItemByIndex
    //************************************
    static FR_MenuItem  GetMenuItemByName(FR_Menu menu, FS_LPCSTR csItemName);

    //************************************
    // Function:  GetMenuItemCount
    // Param[in]: menu				The menu whose number of items is obtained.
    // Return: The number of items in the specified menu.
    // Remarks: Gets the number of item in the specified menu.
    // Notes:
    // See: FRMenuGetMenuItemByIndex
    //************************************
    static FS_INT32		GetMenuItemCount(FR_Menu menu);

    //************************************
    // Function:  AddMenuItem
    // Param[in]: menu				The menu into which the menu item is added.
    // Param[in]: menuitem			Then menu item to add.
    // Param[in]: iIndex			The inserted location.
    // Return:	Return <a>TRUE</a> means successful, otherwise not.
    // Remarks: Inserts a menu item to the specified menu at the specified location. If <param>iIndex</param>
    // is -1 or is greater than (<a>FRMenuGetMenuItemCount</a>()-1), the <param>menuitem</param> will be appended to the menu.
    // Notes:
    // See: FRMenuDeleteMenuItem
    //************************************
    static FS_BOOL			AddMenuItem(FR_Menu menu, FR_MenuItem menuitem, FS_INT32 iIndex);

    //************************************
    // Function:  DeleteMenuItem
    // Param[in]: menu				The menu for which the menu item is deleted.
    // Param[in]: menuitem			The menu item to delete.
    // Return:	<a>TRUE</a> means successful, otherwise not.
    // Remarks: Removes a menu item from specified menu, then destroys the menu item.
    // Notes:
    // See: FRMenuAddMenuItem
    //************************************
    static FS_BOOL			DeleteMenuItem(FR_Menu menu, FR_MenuItem menuitem);

    //************************************
    // Function:  GetMenuItemIndex
    // Param[in]: menu				The menu in which <param>menuitem</param> is located.
    // Param[in]: menuitem			The menu item whose index is obtained.
    // Return:	The index of menu item. Or -1 if <param>menuitem</param> is invalid.
    // Remarks: Gets the index of the specified menu item in the specified menu.
    // Notes:
    // See: FRMenuGetMenuItemByIndex
    //************************************
    static FS_INT32		GetMenuItemIndex(FR_Menu menu, FR_MenuItem menuitem);

    //************************************
    // Function:  DeleteOwnerDrawHandle
    // Param[in]: menuHandle The menu owner-draw handler.
    // Return:	void
    // Remarks:	 Releases the menu owner-draw handler from <a>FRMenuRegisterOwnerDrawHandle</a>.
    // Notes:
    // See: FRMenuRegisterOwnerDrawHandle
    //************************************
    static void			DeleteOwnerDrawHandle(FR_MenuOwnerDrawHandler menuHandle);

    //************************************
    // Function:  RegisterOwnerDrawHandle
    // Param[in]: menu		The input menu.
    // Param[in]: callbacks The callback set for menu owner-draw handler.
    // Return:	  The menu owner-draw handler.
    // Remarks:	  Registers a menu owner-draw handler. It is proper for a sub-menu.
    // Notes: The function can only be used for Windows.
    // See: FRMenuDeleteOwnerDrawHandle
    //************************************
    static FR_MenuOwnerDrawHandler RegisterOwnerDrawHandle(FR_Menu menu, FR_MenuOwnerDrawCallbacksRec callbacks);

    //************************************
    // Function:  TrackPopup
    // Param[in]: menu				The menu to be displayed.
    // Param[in]: x					The x-coordinate of the upper-left corner of the menu.
    // Param[in]: y					The y-coordinate of the upper-left corner of the menu.
    // Return: The menu item you selected in the pop-up menu.
    // Remarks:	Displays a floating pop-up menu at the specified location and tracks the
    // selection of items on the pop-up menu. You can call <a>FRMenuItemDoExecuteProc</a>() to make
    // the <a>FRExecuteProc</a>() callback invoked.
    // Notes: The function can only be used for Windows.
    // See: FRDocViewDoPopUpMenu
	// Deprecated:  It has been deprecated , recommend to use FRMenuDoPopupMenu.
    //************************************
    static FR_MenuItem		TrackPopup(FR_Menu menu, FS_INT32 x, FS_INT32 y);

    //************************************
    // Function:  SetVisible
    // Param[in]: menu	The input menu object.
    // Param[in]: bShow	Indicates whether sets the menu visible or not.
    // Return: void
    // Remarks: Sets the menu visible or not.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static void SetVisible(FR_Menu menu, FS_BOOL bShow);


    //************************************
    // Function:  GetVisible
    // Param[in]: menu	The input menu object.
    // Return: <a>TRUE</a> if the menu is visible, otherwise not.
    // Remarks: Checks whether the menu is visible or not.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static FS_BOOL GetVisible(FR_Menu menu);


    //************************************
    // Function:  SetTitle
    // Param[in]: menu			The input menu object.
    // Param[in]: lpwsTitle		The title of the menu.
    // Return: void
    // Remarks: Sets the title of the menu.
    // Notes:
    // Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static void SetTitle(FR_Menu menu, FS_LPCWSTR lpwsTitle);


    //************************************
    // Function:  NewII
    // Param[in]: hMenu		The input menu handle.
    // Return: The newly created menu.
    // Remarks: Creates a new menu from a menu handle.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    //************************************
    static FR_Menu		NewII(FS_MENU hMenu);

    //************************************
    // Function:  TrackPopupMenu
    // Param[in]: hMenu			The input menu handle.
    // Param[in]: x				The x pos.
    // Param[in]: y				The y pos.
    // Param[in]: bReturnCmdID	Whether to return the command ID or not.
    // Param[in]: hOwner		The parent window.
    // Param[in]: pFunProc		The input callback function to receive the tooltip.
    // Param[in]: bRightAlign	Whether to align to right or not.
    // Return: Pops up a menu.
    // Remarks: The returned command ID.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 7.2
    //************************************
	static FS_UINT TrackPopupMenu(FS_MENU hMenu, FS_INT32 x, FS_INT32 y, FS_BOOL bReturnCmdID, HWND hOwner, FRGetMessageStringProc pFunProc, FS_BOOL bRightAlign);

    //************************************
    // Function:  CloseActivePopupMenu
    // Return: TRUE for success, otherwise failure.
    // Remarks: Closes the active pop-up menu.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
    //************************************
    static FS_BOOL CloseActivePopupMenu();

	//************************************
	// Function:  New3
	// Param[in]: hMenu		     The input menu handle.
	// Param[in]: hMenuSource	 The input menu source handle.
	// Return: The newly created menu.	
	// Remarks: Creates a new menu from a menu handle. 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FR_Menu		New3(FS_MENU hMenu, FS_MENU hMenuSource);

	//************************************
	// Function:  DoPopupMenu
	// Param[in]: menu				The menu to be displayed.
	// Param[in]: pWndParent		The parent CWnd object.
	// Param[in]: x					The x-coordinate of the upper-left corner of the menu.
	// Param[in]: y					The y-coordinate of the upper-left corner of the menu.
	// Return: The menu item you selected in the pop-up menu.
	// Remarks:	Displays a floating pop-up menu at the specified location and tracks the 
	// selection of items on the pop-up menu. You can call <a>FRMenuItemDoExecuteProc</a>() to make 
	// the <a>FRExecuteProc</a>() callback invoked.	
	//************************************
	static FR_MenuItem	DoPopupMenu(FR_Menu hMenu, FS_LPVOID pWndParent, FS_INT32 x, FS_INT32 y);

	//************************************
	// Function:  TrackPopupMenu2
	// Param[in]: hMenu			The input menu handle.
	// Param[in]: x				The x pos.
	// Param[in]: y				The y pos.
	// Param[in]: bReturnCmdID	Whether to return the command ID or not.
	// Param[in]: hOwner		The parent window.
	// Param[in]: pFunProc		The input callback function to receive the tooltip.
	// Param[in]: bRightAlign	Whether to align to right or not.
	// Param[in]: bChangeSkin	Whether menu styles change with skin.
	// Return: Pops up a menu.
	// Remarks: The returned command ID.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0
	//************************************
	static FS_UINT TrackPopupMenu2(FS_MENU hMenu, FS_INT32 x, FS_INT32 y, FS_BOOL bReturnCmdID, HWND hOwner, FRGetMessageStringProc pFunProc, FS_BOOL bRightAlign, FS_BOOL bChangeSkin);
};

class CFR_MenuItem_V1
{
public:
    //************************************
    // Function:  New
    // Param[in]: szName				The name of the menu item to create.
    // Param[in]: wszTitle				The title to display for this menu item.
    // Param[in]: bmp					The icon to show in the menu item. or <a>NULL</a> if no icon is shown. The size of
    // icon is 24 * 24 sample bitmap.
    // Param[in]: bSeparator			A flag that indicate whether the menu item is a separator. If <a>TRUE</a>, the new
    // menu item is a separator used to leave space between groups of related menu items. If <a>FALSE</a>, the menu item
    // is a normal item. The <param>szName</param> and <param>wszTitle</param> are both ignored when a menu item is a
    // separator.
    // Param[in]: submenu				A submenu (if any) for which this menu item is parent. It can be <a>NULL</a> if
    // this menu item does not have a sub-menu.
    // Return: The newly created menu item.
    // Remarks: Creates a new menu item.
    // Notes:
    // See: FRMenuItemRelease
    // See: FRMenuAddMenuItem
    //************************************
    static FR_MenuItem		New(FS_LPCSTR szName, FS_LPCWSTR wszTitle, FS_DIBitmap bmp,	FS_BOOL bSeparator, FR_Menu submenu);

    //************************************
    // Function:  Release
    // Param[in]: menuitem				The menu item to release.
    // Return: void
    // Remarks: Removes the specified menu item and releases it.
    // Notes:
    // See: FRMenuItemNew
    //************************************
    static void			Release(FR_MenuItem menuitem);

    //************************************
    // Function:  GetSubMenu
    // Param[in]: menuitem				The menu item whose submenu is obtained.
    // Return: The submenu or <a>NULL</a> if the <param>menuitem</param> does not have a sub-menu.
    // Remarks: Gets the submenu of a menu item.
    // Notes:
    // See: FRMenuItemSetSubMenu
    //************************************
    static FR_Menu			GetSubMenu(FR_MenuItem menuitem);

    //************************************
    // Function:  SetSubMenu
    // Param[in]: menuitem				The menu item for which a submenu is attached.
    // Param[in]: submenu				The sub-menu to be attached.
    // Return: <a>TRUE</a> if success, otherwise <a>FALSE</a>.
    // Remarks: Attaches a sub-menu to a menu item.
    // Notes:
    // See: FRMenuItemGetSubMenu
    //************************************
    static FS_BOOL			SetSubMenu(FR_MenuItem menuitem, FR_Menu submenu);

    //************************************
    // Function:  GetParentMenu
    // Param[in]: menuitem				The menu item whose parent menu is obtained.
    // Return: The menu in which the specified menu item appears. It returns <a>NULL</a> if this menu
    // item is not in a menu.
    // Remarks: Gets the menu in which the specified menu item appears.
    // Notes:
    //************************************
    static FR_Menu			GetParentMenu(FR_MenuItem menuitem);

    //************************************
    // Function:  GetIcon
    // Param[in]: menuitem				The menu item whose icon is obtained.
    // Return: The <a>FS_DIBitmap</a> object that coorespond a menu item icon, or <a>NULL</a> if the menu item does not have a icon.
    // Remarks: Gets the icon of the <param>menuitem</param>.
    // Notes:
    // See: FRMenuItemSetIcon
    //************************************
    static FS_DIBitmap		GetIcon(FR_MenuItem menuitem);

    //************************************
    // Function:  SetIcon
    // Param[in]: menuitem			The menu to which the icon is attached.
    // Param[in]: bitmap			The icon to attach.
    // Return:    FS_INT32          Get the image index after set icon.
    // Remarks:	  Sets the icon of the menu item.
    // Notes:
    // See: FRMenuItemGetIcon
    //************************************
    static FS_INT32			SetIcon(FR_MenuItem menuitem, FS_DIBitmap bitmap);

    //************************************
    // Function:  GetTitle
    // Param[in]: menuitem			The menu item whose title is obtained.
    // Param[out]: outTitle			(Filled by this method) A unicode string buffer to receive the menu item's title.
    // Return: <a>TRUE</a> if <param>outTitle</param> is filled success, <a>FALSE</a> otherwise.
    // Remarks: Gets a menu item's title, which is the string that displayed in user interface.
    // Notes:
    // See: FRMenuItemSetTitle
    //************************************
    static FS_BOOL			GetTitle(FR_MenuItem menuitem, FS_WideString* outTitle);

    //************************************
    // Function:  SetTitle
    // Param[in]: menuitem			The menu item whose title is set.
    // Param[in]: wszTitle			The new menu title. It must be a <a>NULL</a> terminated string.
    // Return:	<a>TRUE</a> means successful, otherwise not.
    // Remarks: Sets a menu item's title.
    // Notes:
    // See: FRMenuItemGetTitle
    //************************************
    static FS_BOOL				SetTitle(FR_MenuItem menuitem, FS_LPCWSTR wszTitle);

    //************************************
    // Function:  GetName
    // Param[in]: menuitem				The menu item whose name is obtained.
    // Param[out]: outName				(Filled by this method) The char buffer to receive the menu item's name.
    // Return: <a>TRUE</a> if <param>outName</param> is filled success, <a>FALSE</a> otherwise.
    // Remarks:	Gets the name of the specified menu item.
    // Notes:
    // See: FRMenuGetMenuItemByName
    //************************************
    static FS_BOOL			GetName(FR_MenuItem menuitem, FS_ByteString* outName);

    //************************************
    // Function:  SetToolTip
    // Param[in]: menuitem				The menu item whose tooltip is set.
    // Param[in]: wszTip				The new tool tip.  It must be a <a>NULL</a> terminated string.
    // Return: <a>TRUE</a> means successful, otherwise not.
    // Remarks:	Sets the tool tip that appears when the mouse over the item area.
    // Notes:
    // See: FRMenuItemSetDescribeText
    //************************************
    static FS_BOOL			SetToolTip(FR_MenuItem menuitem, FS_LPCWSTR wszTip);

    //************************************
    // Function:  SetDescribeText
    // Param[in]: menuitem				The menu item whose describe text is set.
    // Param[in]: wszText				The describe text.
    // Return:	void
    // Remarks: Sets the describe text to a menu item. The description text is shown in the right of the status bar
    // while the mouse over the specified menu item.
    // Notes:
    // See: FRMenuItemSetToolTip
    //************************************
    static void				SetDescribeText(FR_MenuItem menuitem, FS_LPCWSTR wszText);

    //************************************
    // Function:  IsSeparator
    // Param[in]: menuitem				The menu item to test.
    // Return: <a>TRUE</a> if a menu item is a separator, <a>FALSE</a> otherwise.
    // Remarks: Tests whether the specified menu item is a separator or a normal menu item.
    // Notes:
    //************************************
    static FS_BOOL			IsSeparator(FR_MenuItem menuitem);

    //************************************
    // Function:  SetExecuteProc
    // Param[in]: menuitem			The menu item whose procedure is set.
    // Param[in]: proc				A user-supplied callback to call whenever <param>menuitem</param> is selected.
    // Return:	<a>TRUE</a> means successful, otherwise not.
    // Remarks:	Sets the user-supplied procedure to execute whenever the menu item is chosen.
    // Client must not set the procedure of the Foxit Reader's build-in menu items.
    // Notes: If a user-supplied data need to pass to <param>proc</param>, using FRMenuItemSetClientData() to
    // set the user-supplied data first.
    // See: FRMenuItemSetClientData
    // See: FRMenuItemSetComputeEnabledProc
    // See: FRMenuItemSetComputeMarkedProc
    // See: FRMenuItemDoExecuteProc
    //************************************
    static FS_BOOL				SetExecuteProc(FR_MenuItem menuitem, FRExecuteProc proc);

    //************************************
    // Function:  SetComputeEnabledProc
    // Param[in]: menuitem			The menu item whose <a>FRComputeEnabledProc</a> is set.
    // Param[in]: proc				A user-supplied callback to call whenever the Foxit Reader needs to know whether
    // <param>menuitem</param> should be enabled.
    // Return:	<a>TRUE</a> means successful, otherwise not.
    // Remarks:	 Sets the user-supplied procedure to call to determine whether the menu item is enabled.
    // Notes: If a user-supplied data need to pass to <param>proc</param>, using FRMenuItemSetClientData() to
    // set the user-supplied data first.
    // See: FRMenuItemIsEnabled
    // See: FRMenuItemSetClientData
    // See: FRMenuItemSetExecuteProc
    // See: FRMenuItemSetComputeMarkedProc
    //************************************
    static FS_BOOL				SetComputeEnabledProc(FR_MenuItem menuitem, FRComputeEnabledProc proc);

    //************************************
    // Function:  SetComputeMarkedProc
    // Param[in]: menuitem			The menu item whose <a>FRComputeMarkedProc</a> is set.
    // Param[in]: proc				A user-supplied callback to call whenever the Foxit Reader needs to know whether
    // <param>menuitem</param> should be marked.
    // Return:	<a>TRUE</a> means successful, otherwise not.
    // Remarks:	Sets the user-supplied procedure to call to determine whether the menu item is marked.
    // Notes: If a user-supplied data need to pass to <param>proc</param>, using FRMenuItemSetClientData() to
    // set the user-supplied data first.
    // See: FRMenuItemIsMarked
    // See: FRMenuItemSetClientData
    // See: FRMenuItemSetExecuteProc
    // See: FRMenuItemSetComputeEnabledProc
    //************************************
    static FS_BOOL				SetComputeMarkedProc(FR_MenuItem menuitem, FRComputeMarkedProc proc);


    //************************************
    // Function:  DoExecuteProc
    // Param[in]: menuitem			The menu item to execute.
    // Return:	void
    // Remarks:	Executes a menu item's <a>FRExecuteProc</a>().
    // Notes: You cannot execute a menu item that has a sub-menu.
    // See: FRMenuItemSetExecuteProc
    //************************************
    static void		     DoExecuteProc(FR_MenuItem menuitem);

    //************************************
    // Function:  IsEnabled
    // Param[in]: menuitem			The menu item whose enabled flag is obtained.
    // Return: <a>TRUE</a> if <param>menuitem</param> is enabled, if <param>menuitem</param> is <a>NULL</a>,
    // or if  <param>menuitem</param> has no <a>FRComputeEnabledProc</a>(). It returns <a>FALSE</a> if the menu
    // item is disabled or its <a>FRComputeEnabledProc</a>() raise an exception.
    // Remarks:	 Tests whether the specified menu item is enabled.
    // Notes:
    // See: FRMenuItemSetComputeEnabledProc
    //************************************
    static FS_BOOL		     IsEnabled(FR_MenuItem menuitem);

    //************************************
    // Function:  IsMarked
    // Param[in]: menuitem			The menu item whose mark flag is obtained.
    // Return: <a>TRUE</a> if <param>menuitem</param> is marked. It returns <a>FALSE</a> if <param>menuitem</param>
    // is <a>NULL</a>. if the menu item dose not have a <a>FRComputeMarkedProc</a>() or if it raise an exception.
    // Remarks:	 Tests whether the specified menu item is marked.
    // Notes:
    // See: FRMenuItemSetComputeMarkedProc
    //************************************
    static FS_BOOL		     IsMarked(FR_MenuItem menuitem);


    //************************************
    // Function:  GetClientData
    // Param[in]: menuitem			The menu item whose user-supplied data is obtained.
    // Return: A pointer to a user-supplied data structure. The data structure should contain three types user-supplied
    // data for <a>FRExecuteProc</a>(), <a>FRComputeEnabledProc</a>(), <a>FRComputeMarkedProc</a>(). It returns <a>NULL</a>
    // if no client data to be set.
    // Remarks:	Gets the user-supplied data structure that set to menu item using <a>FRMenuItemSetClientData</a>().
    // Notes:
    // See: FRMenuItemSetClientData
    //************************************
    static void*		 GetClientData(FR_MenuItem menuitem);

    //************************************
    // Function:  SetAccelKey
    // Param[in]: menuitem		The menu item whose hot key will be set.
    // Param[in]: bAlt			A flag indicate the Alt key.
    // Param[in]: bShift		A flag indicate the Shift key.
    // Param[in]: bCtrl			A flag indicate the Ctrl key.
    // Param[in]: key			The hot key.
    // Return:	<a>TRUE</a> means successful, otherwise not.
    // Remarks:	Sets the hot key to a exist menu item.
    // Notes:
    // See:
    //************************************
    static FS_BOOL			SetAccelKey(FR_MenuItem menuitem, FS_BOOL bAlt, FS_BOOL bShift, FS_BOOL bCtrl, FS_CHAR key);

    //************************************
    // Function:  GetCmdID
    // Param[in]: menuitem		The input menu item.
    // Return:	The cmd ID of the menu item.
    // Remarks:	Gets the ACCEL cmd ID of the menu item.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static FS_INT32 GetCmdID(FR_MenuItem menuitem);

    //************************************
    // Function:  SetClientData
    // Param[in]: menuitem			The menu item whose user-supplied data is set.
    // Param[in]: pClientData		A pointer to a user-supplied data structure. The data structure should contain three
    // types user-supplied data for <a>FRExecuteProc</a>(), <a>FRComputeEnabledProc</a>(), <a>FRComputeMarkedProc</a>().
    // Param[in]: callback			It is called when Foxit Reader will free objects such as the menu item.
    // Return:	<a>TRUE</a> means successful, otherwise not.
    // Remarks:	Sets the user-supplied data structure which is passed to <a>FRExecuteProc</a>, <a>FRComputeEnabledProc</a>,
    // <a>FRComputeMarkedProc</a>, <a>FRFreeDataProc</a>.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See: FRMenuItemSetExecuteProc
    // See: FRMenuItemSetComputeEnabledProc
    // See: FRMenuItemSetComputeMarkedProc
    //************************************
    static FS_BOOL SetClientData(FR_MenuItem menuitem, void* pClientData, FRFreeDataProc callback);

    //************************************
    // Function:  SetVisible
    // Param[in]: menuitem		The input menu item.
    // Param[in]: bShow			Indicates whether sets the menu item visible or not.
    // Return: void
    // Remarks: Whether sets the menu item visible or not.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static void SetVisible(FR_MenuItem menuitem, FS_BOOL bShow);

    //************************************
    // Function:  GetVisible
    // Param[in]: menuitem		The input menu item.
    // Return: <a>TRUE</a> if the menu item is visible, otherwise not.
    // Remarks:	Checks whether the menu item is visible or not.
    // Notes:
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.0
    // See:
    //************************************
    static FS_BOOL GetVisible(FR_MenuItem menuitem);

	//************************************
	// Function:  SetBitmapIconWithIndex
	// Param[in]: menuitem			The menu to which the icon is attached.
	// Param[in]: nImagePos			The icon index after FRMenuItemSetIcon.
	// Return:    FS_INT32          Get the image index after set icon.
	// Remarks:	  Sets the icon of the menu item.
	// Notes:
	// See: FRMenuItemGetIcon
	//************************************
	static FS_BOOL	SetBitmapIconWithIndex(FR_MenuItem menuitem, FS_INT32 nImagePos);	

	//************************************
	// Function:  SetPDFBitmapName
	// Param[in]: hMenu			    The menu to which the icon is attached.
	// Param[in]: wsPDFBitmapName	The input pdf bitmap name.
	// Return:    void
	// Remarks:	  Sets the pdf bitmap name.
	// Notes:
	// See: FRMenuSetPDFBitmapName
	//************************************
	static void SetPDFBitmapName(FR_MenuItem menuitem, FS_LPCWSTR wsPDFBitmapName);
};

#ifdef __cplusplus
};
#endif

#endif

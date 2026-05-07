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
/* MenuBar HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRMenuBarGetMenuCount
 * @details Gets the number of menus in menu bar.
 * @param[in]  menuBar The menu bar for which the number of menus is obtained.
 * @return   The number of menus in the menu bar, not including submenus. Return 0 if <param>menuBar</param> is <a>NULL</a>.
 * @note 
 * @see FRMenuBarGetMenuByIndex
	
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more.
 */
INTERFACE(FS_INT32, FRMenuBarGetMenuCount, (FR_MenuBar menuBar))

/**
 * @brief FRMenuBarGetMenuByIndex
 * @details Gets the menu with the specified index.
 * @param[in]  menuBar The menu bar for which the menu is located.
 * @param[in]  iIndex The index of the menu to obtained.The range of <param>iIndex</param> is 0 to (<Italic>GetMenuCount()</Italic>);
 * @return   The menu with the specified index. It returns <a>NULL</a> if there is no such menu or if <param>menuBar</param> 
	* is <a>NULL</a>.
 * @note 
 * @see FRMenuBarGetMenuByIndex	
	
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more.
 */
INTERFACE(FR_Menu, FRMenuBarGetMenuByIndex, (FR_MenuBar menuBar,  FS_INT32 iIndex))

/**
 * @brief FRMenuBarGetMenuByName
 * @details 
 * @param[in]  menuBar The menu bar for which the menu is located.
 * @param[in]  szName The menu name.
 * @return   The menu with the specified name. It returns <a>NULL</a> if there is no such menu or if <param>menuBar</param> 
	* is <a>NULL</a>.
 * @note 
 * @see FRMenuBarGetMenuByIndex
	
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more.
 */
INTERFACE(FR_Menu, FRMenuBarGetMenuByName, (FR_MenuBar menuBar,  FS_LPCSTR szName))

/**
 * @brief FRMenuBarAddMenu
 * @details Inserts a menu into a menu bar. It does nothing if the <param>menuBar</param> or <param>menu</param> is <a>NULL</a>.
 * @param[in]  menuBar The menu bar into which the menu is added.
 * @param[in]  menu The menu to add.
 * @param[in]  szItemTitle The title of the menu to display on menu bar.
 * @param[in]  szItemName The name  to indicate the menu.
 * @param[in]  iIndex The inserted location. The range of <param>iIndex</param> is 0 to <a>FRMenuBarGetMenuCount</a>().
 * @return   <a>TRUE</a> for success. It returns <a>FALSE</a> if <param>menu</param> is <a>NULL</a> or the <param>szItemName</param> 
	* has existed.
 * @note It is strongly encouraged that you begin your menu names with the plug-in name 
	* (separated by a colon) to avoid name collisions when more than one plug-in is present. For example, if my 
	* plug-in is named <Italic>myPlug</Italic>, it might add a menu whose name is <Italic>myPlug:Options</Italic>.
 * @see FRMenuBarDeleteMenu
	
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more.
 */
INTERFACE(FS_BOOL, FRMenuBarAddMenu, (FR_MenuBar menuBar,  FR_Menu menu,  FS_LPCWSTR szItemTitle,  FS_LPCSTR szItemName,  FS_INT32 iIndex))

/**
 * @brief FRMenuBarGetMenuIndex
 * @details Gets the index of specified menu bar.
 * @param[in]  menuBar The menu bar whose menu's index is obtained.
 * @param[in]  menu The menu whose index is obtained.
 * @return   The index of specified menu. The range of the return value is 0 to (<a>FRMenuBarGetMenuCount</a>-1).
 * @note 
 * @see FRMenuBarGetMenuByIndex
	
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more.
 */
INTERFACE(FS_INT32, FRMenuBarGetMenuIndex, (FR_MenuBar menuBar,  FR_Menu menu))

/**
 * @brief FRMenuBarDeleteMenu
 * @details Removes the menu from menu bar, then destroy the menu.
 * @param[in]  menuBar The menu bar whose menu is deleted.
 * @param[in]  menu The menu to delete.
 * @return   <a>TRUE</a> for success, <a>FALSE</a> if <param>menuBar</param> or <param>menu</param> is <a>NULL</a>.
 * @note This method will destroy the specified menu, don't call FRMenuRelease to destroy the menu again.
 * @see FRMenuBarAddMenu
	
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more.
 */
INTERFACE(FS_BOOL, FRMenuBarDeleteMenu, (FR_MenuBar menuBar,  FR_Menu menu))

NumOfSelector(FRMenuBar)
ENDENUM

//*****************************
/* Menu HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRMenuNew
 * @details Creates a new menu.
 * @return   The newly created menu.
 * @note 
 * @see FRMenuRelease
 * @see FRMenuBarGetMenuByName
 * @see FRMenuBarAddMenu
 * @see FRMenuBarDeleteMenu
 */
INTERFACE(FR_Menu, FRMenuNew, ())

/**
 * @brief FRMenuRelease
 * @details Removes the specified menu and releases it.
 * @param[in]  menu The menu to be released.
 * @return   
 * @note 
 */
INTERFACE(void, FRMenuRelease, (FR_Menu menu))

/**
 * @brief FRMenuGetParentMenuItem
 * @details Gets the parent menu item for the specified menu.
 * @param[in]  menu The menu whose parent menu item is obtained.
 * @return   The parent menu item for which the specified menu is a submenu. <a>NULL</a> if the specified menu
    * is not a submenu.
 * @note 
 * @see FRMenuGetMenuItemByIndex
 * @see FRMenuGetMenuItemByName
 */
INTERFACE(FR_MenuItem, FRMenuGetParentMenuItem, (FR_Menu menu))

/**
 * @brief FRMenuGetMenuItemByIndex
 * @details Gets the menu item at the specified location in the specified menu.
 * @param[in]  menu The menu whose item is obtained.
 * @param[in]  iIndex The index of the menu item in <param>menu</param> to obtained. The index range
    * is 0 to (<a>FRMenuGetMenuItemCount</a>-1).
 * @return   The specified menu item. It returns <a>NULL</a> if <param>menu</param> is <a>NULL</a>, if the index
    * is less than zero, or the index is greater than the number of menu items in the menu.
 * @note 
 * @see FRMenuGetParentMenuItem
 * @see FRMenuGetMenuItemByName
 * @see FRMenuGetMenuItemCount
 */
INTERFACE(FR_MenuItem, FRMenuGetMenuItemByIndex, (FR_Menu menu,  FS_INT32 iIndex))

/**
 * @brief FRMenuGetMenuItemByName
 * @details Gets the menu item by the specified name in the specified menu.
 * @param[in]  menu The menu whose item is obtained.
 * @param[in]  csItemName The menu item name.
 * @return   The specified menu item. It returns <a>NULL</a> if <param>menu</param> is <a>NULL</a>, if the
    * named menu item is not exist.
 * @note 
 * @see FRMenuGetParentMenuItem
 * @see FRMenuGetMenuItemByIndex
 */
INTERFACE(FR_MenuItem, FRMenuGetMenuItemByName, (FR_Menu menu,  FS_LPCSTR csItemName))

/**
 * @brief FRMenuGetMenuItemCount
 * @details Gets the number of item in the specified menu.
 * @param[in]  menu The menu whose number of items is obtained.
 * @return   The number of items in the specified menu.
 * @note 
 * @see FRMenuGetMenuItemByIndex
 */
INTERFACE(FS_INT32, FRMenuGetMenuItemCount, (FR_Menu menu))

/**
 * @brief FRMenuAddMenuItem
 * @details Inserts a menu item to the specified menu at the specified location. If <param>iIndex</param>
    * is -1 or is greater than (<a>FRMenuGetMenuItemCount</a>()-1), the <param>menuitem</param> will be appended to the menu.
 * @param[in]  menu The menu into which the menu item is added.
 * @param[in]  menuitem Then menu item to add.
 * @param[in]  iIndex The inserted location.
 * @return   Return <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRMenuDeleteMenuItem
 */
INTERFACE(FS_BOOL, FRMenuAddMenuItem, (FR_Menu menu,  FR_MenuItem menuitem,  FS_INT32 iIndex))

/**
 * @brief FRMenuDeleteMenuItem
 * @details Removes a menu item from specified menu, then destroys the menu item.
 * @param[in]  menu The menu for which the menu item is deleted.
 * @param[in]  menuitem The menu item to delete.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRMenuAddMenuItem
 */
INTERFACE(FS_BOOL, FRMenuDeleteMenuItem, (FR_Menu menu,  FR_MenuItem menuitem))

/**
 * @brief FRMenuGetMenuItemIndex
 * @details Gets the index of the specified menu item in the specified menu.
 * @param[in]  menu The menu in which <param>menuitem</param> is located.
 * @param[in]  menuitem The menu item whose index is obtained.
 * @return   The index of menu item. Or -1 if <param>menuitem</param> is invalid.
 * @note 
 * @see FRMenuGetMenuItemByIndex
 */
INTERFACE(FS_INT32, FRMenuGetMenuItemIndex, (FR_Menu menu,  FR_MenuItem menuitem))

/**
 * @brief FRMenuDeleteOwnerDrawHandle
 * @details Releases the menu owner-draw handler from <a>FRMenuRegisterOwnerDrawHandle</a>.
 * @param[in]  menuHandle The menu owner-draw handler.
 * @return   void
 * @note 
 * @see FRMenuRegisterOwnerDrawHandle
 */
INTERFACE(void, FRMenuDeleteOwnerDrawHandle, (FR_MenuOwnerDrawHandler menuHandle))

/**
 * @brief FRMenuRegisterOwnerDrawHandle
 * @details Registers a menu owner-draw handler. It is proper for a sub-menu.
 * @param[in]  menu The input menu.
 * @param[in]  callbacks The callback set for menu owner-draw handler.
 * @return   The menu owner-draw handler.
 * @note The function can only be used for Windows.
 * @see FRMenuDeleteOwnerDrawHandle
 */
INTERFACE(FR_MenuOwnerDrawHandler, FRMenuRegisterOwnerDrawHandle, (FR_Menu menu,  FR_MenuOwnerDrawCallbacksRec callbacks))

/**
 * @brief FRMenuTrackPopup
 * @details Displays a floating pop-up menu at the specified location and tracks the
    * selection of items on the pop-up menu. You can call <a>FRMenuItemDoExecuteProc</a>() to make
    * the <a>FRExecuteProc</a>() callback invoked.
 * @param[in]  menu The menu to be displayed.
 * @param[in]  x The x-coordinate of the upper-left corner of the menu.
 * @param[in]  y The y-coordinate of the upper-left corner of the menu.
 * @return   The menu item you selected in the pop-up menu.
 * @note The function can only be used for Windows.
 * @see FRDocViewDoPopUpMenu
	
 * @Deprecated    It has been deprecated , recommend to use FRMenuDoPopupMenu.
 */
INTERFACE(FR_MenuItem, FRMenuTrackPopup, (FR_Menu menu,  FS_INT32 x,  FS_INT32 y))

/**
 * @brief FRMenuSetVisible
 * @details Sets the menu visible or not.
 * @param[in]  menu The input menu object.
 * @param[in]  bShow Indicates whether sets the menu visible or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRMenuSetVisible, (FR_Menu menu,  FS_BOOL bShow))

/**
 * @brief FRMenuGetVisible
 * @details Checks whether the menu is visible or not.
 * @param[in]  menu The input menu object.
 * @return   <a>TRUE</a> if the menu is visible, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRMenuGetVisible, (FR_Menu menu))

/**
 * @brief FRMenuSetTitle
 * @details Sets the title of the menu.
 * @param[in]  menu The input menu object.
 * @param[in]  lpwsTitle The title of the menu.
 * @return   void
 * @note * Deprecated:  Current function has been deprecated , so not recommend to use current function any more.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRMenuSetTitle, (FR_Menu menu,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRMenuNewII
 * @details Creates a new menu from a menu handle.
 * @param[in]  hMenu The input menu handle.
 * @return   The newly created menu.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(FR_Menu, FRMenuNewII, (FS_MENU hMenu))

/**
 * @brief FRMenuTrackPopupMenu
 * @details The returned command ID.
 * @param[in]  hMenu The input menu handle.
 * @param[in]  x The x pos.
 * @param[in]  y The y pos.
 * @param[in]  bReturnCmdID Whether to return the command ID or not.
 * @param[in]  hOwner The parent window.
 * @param[in]  pFunProc The input callback function to receive the tooltip.
 * @param[in]  bRightAlign Whether to align to right or not.
 * @return   Pops up a menu.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2
 */
INTERFACE(FS_UINT, FRMenuTrackPopupMenu, (FS_MENU hMenu,  FS_INT32 x,  FS_INT32 y,  FS_BOOL bReturnCmdID,  HWND hOwner,  FRGetMessageStringProc pFunProc,  FS_BOOL bRightAlign))

/**
 * @brief FRMenuCloseActivePopupMenu
 * @details Closes the active pop-up menu.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_BOOL, FRMenuCloseActivePopupMenu, ())

/**
 * @brief FRMenuNew3
 * @details Creates a new menu from a menu handle.
 * @param[in]  hMenu The input menu handle.
 * @param[in]  hMenuSource The input menu source handle.
 * @return   The newly created menu.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 */
INTERFACE(FR_Menu, FRMenuNew3, (FS_MENU hMenu,  FS_MENU hMenuSource))

/**
 * @brief FRMenuDoPopupMenu
 * @details 
 * @param[in]  menu The menu to be displayed.
 * @param[in]  pWndParent The parent CWnd object.
 * @param[in]  x The x-coordinate of the upper-left corner of the menu.
 * @param[in]  y The y-coordinate of the upper-left corner of the menu.
 * @return   The menu item you selected in the pop-up menu.
 * @note 
 */
INTERFACE(FR_MenuItem, FRMenuDoPopupMenu, (FR_Menu hMenu,  FS_LPVOID pWndParent,  FS_INT32 x,  FS_INT32 y))

/**
 * @brief FRMenuTrackPopupMenu2
 * @details The returned command ID.
 * @param[in]  hMenu The input menu handle.
 * @param[in]  x The x pos.
 * @param[in]  y The y pos.
 * @param[in]  bReturnCmdID Whether to return the command ID or not.
 * @param[in]  hOwner The parent window.
 * @param[in]  pFunProc The input callback function to receive the tooltip.
 * @param[in]  bRightAlign Whether to align to right or not.
 * @param[in]  bChangeSkin Whether menu styles change with skin.
 * @return   Pops up a menu.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0
 */
INTERFACE(FS_UINT, FRMenuTrackPopupMenu2, (FS_MENU hMenu,  FS_INT32 x,  FS_INT32 y,  FS_BOOL bReturnCmdID,  HWND hOwner,  FRGetMessageStringProc pFunProc,  FS_BOOL bRightAlign,  FS_BOOL bChangeSkin))

NumOfSelector(FRMenu)
ENDENUM

//*****************************
/* MenuItem HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRMenuItemNew
 * @details Creates a new menu item.
 * @param[in]  szName The name of the menu item to create.
 * @param[in]  wszTitle The title to display for this menu item.
 * @param[in]  bmp The icon to show in the menu item. or <a>NULL</a> if no icon is shown. The size of
    * icon is 24 * 24 sample bitmap.
 * @param[in]  bSeparator A flag that indicate whether the menu item is a separator. If <a>TRUE</a>, the new
    * menu item is a separator used to leave space between groups of related menu items. If <a>FALSE</a>, the menu item
    * is a normal item. The <param>szName</param> and <param>wszTitle</param> are both ignored when a menu item is a
    * separator.
 * @param[in]  submenu A submenu (if any) for which this menu item is parent. It can be <a>NULL</a> if
    * this menu item does not have a sub-menu.
 * @return   The newly created menu item.
 * @note 
 * @see FRMenuItemRelease
 * @see FRMenuAddMenuItem
 */
INTERFACE(FR_MenuItem, FRMenuItemNew, (FS_LPCSTR szName,  FS_LPCWSTR wszTitle,  FS_DIBitmap bmp,  FS_BOOL bSeparator,  FR_Menu submenu))

/**
 * @brief FRMenuItemRelease
 * @details Removes the specified menu item and releases it.
 * @param[in]  menuitem The menu item to release.
 * @return   void
 * @note 
 * @see FRMenuItemNew
 */
INTERFACE(void, FRMenuItemRelease, (FR_MenuItem menuitem))

/**
 * @brief FRMenuItemGetSubMenu
 * @details Gets the submenu of a menu item.
 * @param[in]  menuitem The menu item whose submenu is obtained.
 * @return   The submenu or <a>NULL</a> if the <param>menuitem</param> does not have a sub-menu.
 * @note 
 * @see FRMenuItemSetSubMenu
 */
INTERFACE(FR_Menu, FRMenuItemGetSubMenu, (FR_MenuItem menuitem))

/**
 * @brief FRMenuItemSetSubMenu
 * @details Attaches a sub-menu to a menu item.
 * @param[in]  menuitem The menu item for which a submenu is attached.
 * @param[in]  submenu The sub-menu to be attached.
 * @return   <a>TRUE</a> if success, otherwise <a>FALSE</a>.
 * @note 
 * @see FRMenuItemGetSubMenu
 */
INTERFACE(FS_BOOL, FRMenuItemSetSubMenu, (FR_MenuItem menuitem,  FR_Menu submenu))

/**
 * @brief FRMenuItemGetParentMenu
 * @details Gets the menu in which the specified menu item appears.
 * @param[in]  menuitem The menu item whose parent menu is obtained.
 * @return   The menu in which the specified menu item appears. It returns <a>NULL</a> if this menu
    * item is not in a menu.
 * @note 
 */
INTERFACE(FR_Menu, FRMenuItemGetParentMenu, (FR_MenuItem menuitem))

/**
 * @brief FRMenuItemGetIcon
 * @details Gets the icon of the <param>menuitem</param>.
 * @param[in]  menuitem The menu item whose icon is obtained.
 * @return   The <a>FS_DIBitmap</a> object that coorespond a menu item icon, or <a>NULL</a> if the menu item does not have a icon.
 * @note 
 * @see FRMenuItemSetIcon
 */
INTERFACE(FS_DIBitmap, FRMenuItemGetIcon, (FR_MenuItem menuitem))

/**
 * @brief FRMenuItemSetIcon
 * @details Sets the icon of the menu item.
 * @param[in]  menuitem The menu to which the icon is attached.
 * @param[in]  bitmap The icon to attach.
 * @return   FS_INT32          Get the image index after set icon.
 * @note 
 * @see FRMenuItemGetIcon
 */
INTERFACE(FS_INT32, FRMenuItemSetIcon, (FR_MenuItem menuitem,  FS_DIBitmap bitmap))

/**
 * @brief FRMenuItemGetTitle
 * @details Gets a menu item's title, which is the string that displayed in user interface.
 * @param[in]  menuitem The menu item whose title is obtained.
 * @param[out]  outTitle (Filled by this method) A unicode string buffer to receive the menu item's title.
 * @return   <a>TRUE</a> if <param>outTitle</param> is filled success, <a>FALSE</a> otherwise.
 * @note 
 * @see FRMenuItemSetTitle
 */
INTERFACE(FS_BOOL, FRMenuItemGetTitle, (FR_MenuItem menuitem,  FS_WideString* outTitle))

/**
 * @brief FRMenuItemSetTitle
 * @details Sets a menu item's title.
 * @param[in]  menuitem The menu item whose title is set.
 * @param[in]  wszTitle The new menu title. It must be a <a>NULL</a> terminated string.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRMenuItemGetTitle
 */
INTERFACE(FS_BOOL, FRMenuItemSetTitle, (FR_MenuItem menuitem,  FS_LPCWSTR wszTitle))

/**
 * @brief FRMenuItemGetName
 * @details Gets the name of the specified menu item.
 * @param[in]  menuitem The menu item whose name is obtained.
 * @param[out]  outName (Filled by this method) The char buffer to receive the menu item's name.
 * @return   <a>TRUE</a> if <param>outName</param> is filled success, <a>FALSE</a> otherwise.
 * @note 
 * @see FRMenuGetMenuItemByName
 */
INTERFACE(FS_BOOL, FRMenuItemGetName, (FR_MenuItem menuitem,  FS_ByteString* outName))

/**
 * @brief FRMenuItemSetToolTip
 * @details Sets the tool tip that appears when the mouse over the item area.
 * @param[in]  menuitem The menu item whose tooltip is set.
 * @param[in]  wszTip The new tool tip.  It must be a <a>NULL</a> terminated string.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRMenuItemSetDescribeText
 */
INTERFACE(FS_BOOL, FRMenuItemSetToolTip, (FR_MenuItem menuitem,  FS_LPCWSTR wszTip))

/**
 * @brief FRMenuItemSetDescribeText
 * @details Sets the describe text to a menu item. The description text is shown in the right of the status bar
    * while the mouse over the specified menu item.
 * @param[in]  menuitem The menu item whose describe text is set.
 * @param[in]  wszText The describe text.
 * @return   void
 * @note 
 * @see FRMenuItemSetToolTip
 */
INTERFACE(void, FRMenuItemSetDescribeText, (FR_MenuItem menuitem,  FS_LPCWSTR wszText))

/**
 * @brief FRMenuItemIsSeparator
 * @details Tests whether the specified menu item is a separator or a normal menu item.
 * @param[in]  menuitem The menu item to test.
 * @return   <a>TRUE</a> if a menu item is a separator, <a>FALSE</a> otherwise.
 * @note 
 */
INTERFACE(FS_BOOL, FRMenuItemIsSeparator, (FR_MenuItem menuitem))

/**
 * @brief FRMenuItemSetExecuteProc
 * @details Sets the user-supplied procedure to execute whenever the menu item is chosen.
    * Client must not set the procedure of the Foxit Reader's build-in menu items.
 * @param[in]  menuitem The menu item whose procedure is set.
 * @param[in]  proc A user-supplied callback to call whenever <param>menuitem</param> is selected.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note If a user-supplied data need to pass to <param>proc</param>, using FRMenuItemSetClientData() to
    * set the user-supplied data first.
 * @see FRMenuItemSetClientData
 * @see FRMenuItemSetComputeEnabledProc
 * @see FRMenuItemSetComputeMarkedProc
 * @see FRMenuItemDoExecuteProc
 */
INTERFACE(FS_BOOL, FRMenuItemSetExecuteProc, (FR_MenuItem menuitem,  FRExecuteProc proc))

/**
 * @brief FRMenuItemSetComputeEnabledProc
 * @details Sets the user-supplied procedure to call to determine whether the menu item is enabled.
 * @param[in]  menuitem The menu item whose <a>FRComputeEnabledProc</a> is set.
 * @param[in]  proc A user-supplied callback to call whenever the Foxit Reader needs to know whether
    * <param>menuitem</param> should be enabled.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note If a user-supplied data need to pass to <param>proc</param>, using FRMenuItemSetClientData() to
    * set the user-supplied data first.
 * @see FRMenuItemIsEnabled
 * @see FRMenuItemSetClientData
 * @see FRMenuItemSetExecuteProc
 * @see FRMenuItemSetComputeMarkedProc
 */
INTERFACE(FS_BOOL, FRMenuItemSetComputeEnabledProc, (FR_MenuItem menuitem,  FRComputeEnabledProc proc))

/**
 * @brief FRMenuItemSetComputeMarkedProc
 * @details Sets the user-supplied procedure to call to determine whether the menu item is marked.
 * @param[in]  menuitem The menu item whose <a>FRComputeMarkedProc</a> is set.
 * @param[in]  proc A user-supplied callback to call whenever the Foxit Reader needs to know whether
    * <param>menuitem</param> should be marked.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note If a user-supplied data need to pass to <param>proc</param>, using FRMenuItemSetClientData() to
    * set the user-supplied data first.
 * @see FRMenuItemIsMarked
 * @see FRMenuItemSetClientData
 * @see FRMenuItemSetExecuteProc
 * @see FRMenuItemSetComputeEnabledProc
 */
INTERFACE(FS_BOOL, FRMenuItemSetComputeMarkedProc, (FR_MenuItem menuitem,  FRComputeMarkedProc proc))

/**
 * @brief FRMenuItemDoExecuteProc
 * @details Executes a menu item's <a>FRExecuteProc</a>().
 * @param[in]  menuitem The menu item to execute.
 * @return   void
 * @note You cannot execute a menu item that has a sub-menu.
 * @see FRMenuItemSetExecuteProc
 */
INTERFACE(void, FRMenuItemDoExecuteProc, (FR_MenuItem menuitem))

/**
 * @brief FRMenuItemIsEnabled
 * @details Tests whether the specified menu item is enabled.
 * @param[in]  menuitem The menu item whose enabled flag is obtained.
 * @return   <a>TRUE</a> if <param>menuitem</param> is enabled, if <param>menuitem</param> is <a>NULL</a>,
    * or if  <param>menuitem</param> has no <a>FRComputeEnabledProc</a>(). It returns <a>FALSE</a> if the menu
    * item is disabled or its <a>FRComputeEnabledProc</a>() raise an exception.
 * @note 
 * @see FRMenuItemSetComputeEnabledProc
 */
INTERFACE(FS_BOOL, FRMenuItemIsEnabled, (FR_MenuItem menuitem))

/**
 * @brief FRMenuItemIsMarked
 * @details Tests whether the specified menu item is marked.
 * @param[in]  menuitem The menu item whose mark flag is obtained.
 * @return   <a>TRUE</a> if <param>menuitem</param> is marked. It returns <a>FALSE</a> if <param>menuitem</param>
    * is <a>NULL</a>. if the menu item dose not have a <a>FRComputeMarkedProc</a>() or if it raise an exception.
 * @note 
 * @see FRMenuItemSetComputeMarkedProc
 */
INTERFACE(FS_BOOL, FRMenuItemIsMarked, (FR_MenuItem menuitem))

/**
 * @brief FRMenuItemGetClientData
 * @details Gets the user-supplied data structure that set to menu item using <a>FRMenuItemSetClientData</a>().
 * @param[in]  menuitem The menu item whose user-supplied data is obtained.
 * @return   A pointer to a user-supplied data structure. The data structure should contain three types user-supplied
    * data for <a>FRExecuteProc</a>(), <a>FRComputeEnabledProc</a>(), <a>FRComputeMarkedProc</a>(). It returns <a>NULL</a>
    * if no client data to be set.
 * @note 
 * @see FRMenuItemSetClientData
 */
INTERFACE(void*, FRMenuItemGetClientData, (FR_MenuItem menuitem))

/**
 * @brief FRMenuItemSetAccelKey
 * @details Sets the hot key to a exist menu item.
 * @param[in]  menuitem The menu item whose hot key will be set.
 * @param[in]  bAlt A flag indicate the Alt key.
 * @param[in]  bShift A flag indicate the Shift key.
 * @param[in]  bCtrl A flag indicate the Ctrl key.
 * @param[in]  key The hot key.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FRMenuItemSetAccelKey, (FR_MenuItem menuitem,  FS_BOOL bAlt,  FS_BOOL bShift,  FS_BOOL bCtrl,  FS_CHAR key))

/**
 * @brief FRMenuItemGetCmdID
 * @details Gets the ACCEL cmd ID of the menu item.
 * @param[in]  menuitem The input menu item.
 * @return   The cmd ID of the menu item.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRMenuItemGetCmdID, (FR_MenuItem menuitem))

/**
 * @brief FRMenuItemSetClientData
 * @details Sets the user-supplied data structure which is passed to <a>FRExecuteProc</a>, <a>FRComputeEnabledProc</a>,
    * <a>FRComputeMarkedProc</a>, <a>FRFreeDataProc</a>.
 * @param[in]  menuitem The menu item whose user-supplied data is set.
 * @param[in]  pClientData A pointer to a user-supplied data structure. The data structure should contain three
    * types user-supplied data for <a>FRExecuteProc</a>(), <a>FRComputeEnabledProc</a>(), <a>FRComputeMarkedProc</a>().
 * @param[in]  callback It is called when Foxit Reader will free objects such as the menu item.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRMenuItemSetExecuteProc
 * @see FRMenuItemSetComputeEnabledProc
 * @see FRMenuItemSetComputeMarkedProc
 */
INTERFACE(FS_BOOL, FRMenuItemSetClientData, (FR_MenuItem menuitem,  void* pClientData,  FRFreeDataProc callback))

/**
 * @brief FRMenuItemSetVisible
 * @details Whether sets the menu item visible or not.
 * @param[in]  menuitem The input menu item.
 * @param[in]  bShow Indicates whether sets the menu item visible or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRMenuItemSetVisible, (FR_MenuItem menuitem,  FS_BOOL bShow))

/**
 * @brief FRMenuItemGetVisible
 * @details Checks whether the menu item is visible or not.
 * @param[in]  menuitem The input menu item.
 * @return   <a>TRUE</a> if the menu item is visible, otherwise not.
 * @note * Notes:
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRMenuItemGetVisible, (FR_MenuItem menuitem))

/**
 * @brief FRMenuItemSetBitmapIconWithIndex
 * @details Sets the icon of the menu item.
 * @param[in]  menuitem The menu to which the icon is attached.
 * @param[in]  nImagePos The icon index after FRMenuItemSetIcon.
 * @return   FS_INT32          Get the image index after set icon.
 * @note 
 * @see FRMenuItemGetIcon
 */
INTERFACE(FS_BOOL, FRMenuItemSetBitmapIconWithIndex, (FR_MenuItem menuitem,  FS_INT32 nImagePos))

/**
 * @brief FRMenuItemSetPDFBitmapName
 * @details Sets the pdf bitmap name.
 * @param[in]  hMenu The menu to which the icon is attached.
 * @param[in]  wsPDFBitmapName The input pdf bitmap name.
 * @return   void
 * @note 
 * @see FRMenuSetPDFBitmapName
 */
INTERFACE(void, FRMenuItemSetPDFBitmapName, (FR_MenuItem menuitem,  FS_LPCWSTR wsPDFBitmapName))

NumOfSelector(FRMenuItem)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
//----------_V11----------
//----------_V12----------
//----------_V13----------
//----------_V14----------
//----------_V15----------
//----------_V16----------
//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------

/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.	

*********************************************************************/


/**
 * @defgroup FRLayer Foxit Reader Layer
 */

/*@{*/

/** @file fr_menuExpT.h.
 * 
 *  @brief .
 */

/**
 * @addtogroup FRMENU
 * @{
 */

#ifndef FR_MENUEXPT_H
#define FR_MENUEXPT_H

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/* @COMMONSTART */
/* @CALLBACKSTART FRExecuteProc */
/**
 * @brief A callback that is called whenever a menu item, toolbar button or ribbon element is executed. It implements whatever the
 * menu item, toolbar button or ribbon element does.
 * @param[in] clientData		User-supplied data that was passed when <a>FRToolButtonSetClientData</a>,
 * <a>FRMenuItemSetClientData</a> or <a>FRRibbonBarAddButtonToAddPlace</a>  was called.
 * @return void
 * @note
 */
typedef void (*FRExecuteProc)(void *clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRComputeEnabledProc */
/**
 * @brief	A callback for setting whether to enable menu items and toolbar buttons.
 *
 * This procedure is called every time the menu or toolbar button is displayed, so it should not do
 * compute-time-intensive processing. It is called before the menu item or toolbar button is displayed. If it
 * returns <a>FALSE</a>, the menu item, or toolbar button will be disable; otherwise it will be enable.
 * If this callback is <a>NULL</a>, the menu item or toolbar button is always enabled.
 *
 * @param[in] clientData  User-supplied data that was passed when <a>FRToolButtonSetClientData</a>() or
 * <a>FRMenuItemSetClientData</a>() was called.
 * @return	<a>TRUE</a> if the menu item, or toolbar button is enabled, <a>FALSE</a> otherwise.
 * @note Each menu item, toolbar button can have its own FRComputeEnabledProc(), or they can be shared.
 */
typedef FS_BOOL (*FRComputeEnabledProc)(void *clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRAppearanceSettingProc */
/**
 * @brief	A callback that is used to Set the ribbon control lightmode and darkmode.
 *
 * @param[in] clientData  User-supplied data that was passed when <a>FRToolButtonSetClientData</a>() or
 * <a>FRMenuItemSetClientData</a>() was called.
 * @return	void.
 * @note Only for Mac.
 */
typedef void (*FRAppearanceSettingProc)(void *clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRComputeMarkedProc */
/**
 * @brief  A callback that is used to determine whether a menu item or toolbar button is marked (a marked menu
 * item has a check mark next to it, and a marked toolbar button appears selected).
 *
 * It is called before the menu item or toolbar button is displayed. If it returns <a>FALSE</a>, the menu
 * item of toolbar button is not marked; otherwise it is marked.
 *
 * @param[in] clientData  User-supplied data that was passed when <a>FRToolButtonSetClientData</a>() or
 * <a>FRMenuItemSetClientData</a>() was called.
 * @return	<a>TRUE</a> if the menu item, or toolbar button is enabled, <a>FALSE</a> otherwise.
 * @note Each menu item, toolbar button can have its own FRComputeMarkedProc(), or they can be shared.
 */
typedef FS_BOOL (*FRComputeMarkedProc)(void *clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRFreeDataProc */
/**
 * @brief  A callback that is used to free data.
 *
 * It is called when Foxit Reader will free objects such as ribbon element.
 *
 * @param[in] clientData  User-supplied data.
 * @return	void
 * @note
 */
typedef void (*FRFreeDataProc)(void *clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRDropDownProc */
/**
 * @brief The callback is invoked by Foxit Reader when user clicks the ribbon element drop-down arrow
 *
 * @param[in] clientData  User-supplied data.
 * @return	void
 * @note
 */
typedef void (*FRDropDownProc)(void *clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRGetMessageStringProc */
/**
 * @brief A callback that is called whenever a menu is popped up to receive the tooltip.
 * @param[in] nID			The specified ID of the pop-up menu item.
 * @param[out] outMessage	It receives the message.
 * @return TRUE for success, otherwise failure.
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2
 */
typedef FS_BOOL (*FRGetMessageStringProc)(FS_UINT nID, FS_WideString outMessage);
/* @CALLBACKEND */
/* @COMMONEND */

/* @OBJSTART FR_MenuBar */
#ifndef FR_MENUBAR
#define FR_MENUBAR
/**
 * @brief The <a>FR_MenuBar</a> is the Foxit Reader menu bar and contains a list of all menus.
 *
 * There is only one menu bar within Foxit Reader.  Plug-ins can add new menus to, or remove any menu from, the menu bar.
 * The menu bar can be hidden from the user's view.
 */
typedef struct _t_FR_MenuBar* FR_MenuBar;
#endif
/* @OBJEND */

/* @OBJSTART FR_Menu */
#ifndef FR_MENU
#define FR_MENU
/**
 * @brief A <a>FR_Menu</a> is a menu in the Foxit Reader's menu bar. 
 * Plug-ins can create new menus, add menu items at any location in any menu, and remove menu items. 
 * Deleting an <a>FR_Menu</a> removes it from the menu bar (if it was attached) and deletes all the menu items it contains.
 * A <a>FR_Menu</a> have a name when it is added to menu bar, plug-ins can access a menu by using <a>FRMenuBarGetMenuByName</a>()
 * or <a>FRMenuBarGetMenuByIndex</a>().<br>
 * Submenus (also called pullright menus) are <a>FR_Menu</a> objects that are attached to an <a>FR_MenuItem</a> instead 
 * of the menu bar. Your plug-in cannot directly remove a submenu. Instead, it must remove the <a>FR_MenuItem</a> to which the 
 * submenu is attached.
 */
typedef struct _t_FR_Menu* FR_Menu;
#endif

/* @DEFGROUPSTART FRMenuNames */
/**
 * @brief The macro definitions for the name of built-in menu in the menu bar. See <a>FRMenuBarGetMenuByName</a>.
 */
/*@{*/
/** @brief <Italic>File</Italic> menu in the menu bar*/
#define  FR_MENU_NAME_FILE		 "File"

/** @brief <Italic>Edit</Italic> menu in the menu bar*/
#define  FR_MENU_NAME_EDIT		 "Edit"

/** @brief <Italic>View</Italic> menu in the menu bar*/
#define  FR_MENU_NAME_VIEW		 "View"

/** @brief <Italic>Tools</Italic> menu in the menu bar*/
#define  FR_MENU_NAME_TOOLS		 "Tools"

/** @brief <Italic>Help</Italic> menu in the menu bar*/
#define  FR_MENU_NAME_HELP		 "Help"
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FR_MenuItem */
#ifndef FR_MENUITEM
#define FR_MENUITEM
/**
 * @brief A <a>FR_MenuItem</a> is a menu item in a menu. It has attributes, including the following:
 * <ul>
 * <li>A name that indicates the menu item.</li>
 * <li>A title that displayed on screen.</li>
 * <li>A procedure to execute when the menu item is selected.</li>
 * <li>A procedure to compute whether the menu item is enabled.</li>
 * <li>A procedure to compute whether the menu item is checkmarked, and whether it has a sub-menu.</li>
 * </ul>
 * 
 * A plug-in can simulate a user selecting a menu item by calling <a>FRMenuDoExecuteProc</a>(). If the menu item is 
 * disabled, <a>FRMenuDoExecuteProc</a>() returns without doing anything. <a>FRMenuDoExecuteProc</a>() works even when 
 * the menu item is not displayed (for example, if it has not been added to a menu, its menu is not displayed, 
 * or the menu bar is not visible). Plug-ins can set all attributes of menu items they create, but must not set 
 * the Execute procedure of the Foxit Reader built-in menu items.<br>
 * You are strongly encouraged to begin your plug-in's menu item names with your plug-in's name (separated by a colon) 
 * to avoid name collisions when more than one plug-in is present. For example, if your plug-in is named <Italic>myPlugin</Italic>, it 
 * might add menu items whose names are <Italic>myPlugin:Close</Italic> and <Italic>myPlugin:Save</Italic>.
 */
typedef struct _t_FR_MenuItem* FR_MenuItem;
#endif
/* @OBJEND */

/* @OBJSTART FR_MenuOwnerDrawHandler */
#ifndef FR_MENU_OWNERDRAW_HANDLER
#define FR_MENU_OWNERDRAW_HANDLER
/**
 * @brief FR MenuOwnerDraw Handler.
 */
typedef struct _t_FR_MenuOwnerDrawHandler* FR_MenuOwnerDrawHandler;
#endif

/* @CALLBACKGROUPSTART FR_MenuOwnerDrawCallbacks */
/**
 * @brief A callback set. It is called by foxit reader when it is drawing the menu. See <a>FRMenuRegisterOwnerDrawHandle</a>
 */
typedef struct _fr_menu_callbacks_ 
{

	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_MenuOwnerDrawCallbacksRec</a>).  */
	unsigned long lStructSize;

    /* @CALLBACKSTART FRMenuItemOnMeasureItem */
	/**
     * @brief	It is called by foxit reader to measure the menu item.
     * @param[in]	  menuItem	The menu item.
	 * @param[in,out] width		The width of the menu item.
	 * @param[in,out] height	The height of the menu item.
     * @return <a>TRUE</a> means it is handled successfully, otherwise not.
     * @note
     */
	FS_BOOL (*FRMenuItemOnMeasureItem)(FR_MenuItem menuItem, FS_INT32 *width, FS_INT32 *height);
	/* @CALLBACKEND */

    /* @CALLBACKSTART FRMenuItemOnDrawItem */
	/**
     * @brief	It is called by foxit reader when a visual aspect of the menu has changed.
     * @param[in] menuItem	The menu item.
	 * @param[in] hDC		Identifies a device context. 
	 * This device context must be used when performing drawing operations on the control.
	 * @param[in] rect		The rectangle of the menu item.
     * @return	<a>TRUE</a> means it is handled successfully, otherwise not.
     * @note
     */
    FS_BOOL (*FRMenuItemOnDrawItem)(FR_MenuItem menuItem, FS_HDC hDC, const FS_Rect rect);
	/* @CALLBACKEND */

    /* @CALLBACKSTART FRMenuItemOnInitMenuPopup */
	/**
	* @brief The Foxit Reader calls this member function when a pop-up menu is about to become active. 
	* This allows a plug-in to modify the pop-up menu before it is displayed without changing the entire menu.
    * @param[in] menu The menu to become active.
    * @return void
    * @note
    */
	void	 (*FRMenuItemOnInitMenuPopup)(FR_Menu menu);
	/* @CALLBACKEND */
}FR_MenuOwnerDrawCallbacksRec, *FR_MenuOwnerDrawCallbacks;
/* @CALLBACKGROUPEND */

/* @OBJEND */

#ifdef __cplusplus
};
#endif


#endif
/*@}*/ 

/*@}*/ 
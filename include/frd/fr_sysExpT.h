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

/** @file fr_sysExpT.h.
 * 
 *  @brief .
 */

/**
 * @addtogroup FRSYS
 * @{
 */

#ifndef FR_SYSEXPT_H
#define FR_SYSEXPT_H

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

/* @STRUCTSTART FR_MSGBOX_CHECKBOXPARAMS*/
#ifndef _FR_MSGBOX_CHECKBOXPARAMS
#define _FR_MSGBOX_CHECKBOXPARAMS
/**
* @brief A data structure representing the params of the check box on the message box.
*
*/
typedef struct __fr_msgbox_checkboxparams__
{
	/** Whether show the check box or not. */
	FS_BOOL bShowCheckBox;
	/** The text of the check box. */
	FS_LPCWSTR wszCheckBoxText;
	/** Whether the check box is checked or not. */
	FS_BOOL bIsChecked;
}FR_MSGBOX_CHECKBOXPARAMS, *PFR_MSGBOX_CHECKBOXPARAMS;
#endif
/* @STRUCTEND */

/* @STRUCTSTART FR_MSGBOX_CHECKBOXPARAMS*/
#ifndef _FR_MSGBOX_CHECKBOXPARAMS2
#define _FR_MSGBOX_CHECKBOXPARAMS2
/**
* @brief A data structure representing the params of the check box on the message box.
*This is same to the FR_MSGBOX_CHECKBOXPARAMS,it's in order to cross platfrom with mac in FRSysShowMessageBox3.
*/
typedef struct __fr_msgbox_checkboxparams2__
{
	/** Whether show the check box or not. */
	FS_BOOL bShowCheckBox;
	/** The text of the check box. */
	FS_LPCWSTR wszCheckBoxText;
	/** Whether the check box is checked or not. */
	FS_BOOL bIsChecked;
}FR_MSGBOX_CHECKBOXPARAMS2, *PFR_MSGBOX_CHECKBOXPARAMS2;
#endif
/* @STRUCTEND */

/* @STRUCTSTART FR_WINDIB_Open_Args_ */
/** @brief A structure used to indicate how to open a new image file or stream. */
typedef struct _FR_WINDIB_Open_Args_
{
	/**A set of bit flags indicating how to use the structure.*/
    FS_INT32         flags;
    /** The first byte of the file in memory.*/
    const FS_BYTE*  memory_base;
	/** The size in bytes of the file in memory.*/
    FS_DWORD    memory_size;
    /** A pointer to an 16-bit file pathname. */
    FS_LPCWSTR  path_name;	
}FR_WINDIB_Open_Args;
/* @STRUCTEND */

/* @ENUMSTART */
/**
* @brief The type of messagebox button type.
*/
enum FR_MsgBtnType
{
	FR_MBOK,
	FR_MBOKCANCEL,
	FR_MBABORTRETRYIGNORE,
	FR_MBYESNOCANCEL,
	FR_MBYESNO,
	FR_MBRETRYCANCEL
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief The type of messagebox type.
*/
enum FR_MsgType
{
	FR_MBICONWARNING,
	FR_MBICONERROR,
	FR_MBICONQUESTION,
	FR_MBICONINFORMATION
};
/* @ENUMEND */

/* @COMMONEND */

/* @OBJSTART FR_Sys*/
/**
 * @brief It is used to manage the APIs of system-dependent. See <a>FRSysLoadStandarCursor</a>, <a>FRSysGetCursor</a>, <a>FRSysSetCursor</a>.
 */
typedef struct _t_FR_Sys* FR_Sys;
/* @OBJEND */

/* @OBJSTART FR_Cursor */
#ifndef FR_CURSOR
#define FR_CURSOR
/**
 * @brief A data structure representing the cursor.
 */
typedef struct _t_FR_Cursor* FR_Cursor;
#endif

/* @DEFGROUPSTART FRCursorTypeFlags */
/*@{*/
/**  
 * @brief Standard arrow cursor  See <a>FRSysLoadStandarCursor</a>.
 */
#define FR_CURSOR_TYPE_ARROW		0

/**  @brief Cross-hair cursor for selection  */
#define FR_CURSOR_TYPE_CROSS		1

/**  @brief Help cursor */
#define FR_CURSOR_TYPE_HELP			2

/**  @brief A four-pointed arrow. The cursor to use to resize a window.  */
#define FR_CURSOR_TYPE_SIZEALL		3

/**  @brief Two-headed arrow with ends at upper right and lower left. */
#define FR_CURSOR_TYPE_SIZENESW		4

/**  @brief Vertical two-headed arrow. */
#define FR_CURSOR_TYPE_SIZENS		5

/**  @brief Two-headed arrow with ends at upper left and lower right.  */
#define FR_CURSOR_TYPE_SIZENWSE		6
	
/**  @brief Horizontal two-headed arrow. */
#define FR_CURSOR_TYPE_SIZEWE		7
	
/**  @brief Arrow that points straight up. */
#define FR_CURSOR_TYPE_UPARROW		8

/**  @brief Hourglass cursor used when Windows performs a time-consuming task.  */
#define FR_CURSOR_TYPE_WAIT			9
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FR_SYSTEMHANDLER*/
/**
 * @brief It is used to manage the system handler
 */
typedef struct _t_FR_SystemHandler* FR_SystemHandler;

/* @ENUMSTART */
/**
* @brief cursor style.
*/
enum FR_CURSORSTYLE
{
	FR_FXCT_ARROW = 0,
	FR_FXCT_NESW = 1,
	FR_FXCT_NWSE = 2,
	FR_FXCT_VBEAM = 3,
	FR_FXCT_HBEAM = 4,
	FR_FXCT_HAND = 5,
	FR_FXCT_SIZEALL = 6,
	FR_FXCT_WE = 7,
	FR_FXCT_NS = 8
};
/* @ENUMEND */
/* @OBJEND */

/* @OBJSTART FR_CTBLOGFONTS*/
/**
 * @brief It is used to manage system font
 */
typedef struct _t_FR_CTBLogFonts* FR_CTBLogFonts;
/* @OBJEND */

/* @OBJSTART FR_ITBSYSYSFONT*/
/**
 * @brief It is used to manage system font
 */
typedef struct _t_FR_ITBSysFont* FR_ITBSysFont;
/* @OBJEND */

/* @OBJSTART FR_TB_SYSFONTDATA*/
/**
 * @brief It is used to manage system font
 */
typedef struct _t_FR_TB_SYSFONTDATA* FR_TB_SYSFONTDATA;
/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
/*@}*/ 

/*@}*/ 
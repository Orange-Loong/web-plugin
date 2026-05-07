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

/** @file fr_barExpT.h.
 * 
 *  @brief .
 */

/**
 * @addtogroup FRBAR
 * @{
 */

#ifndef FR_BAREXPT_H
#define	FR_BAREXPT_H

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
/* @ENUMSTART FRRibbonStyleButtonType*/
/** @brief The ribbon style control types. */
enum FRRibbonStyleButtonType
{
	FR_RibbonStyle_Button = 0,			/** The ribbon style button. */
	FR_RibbonStyle_Edit,				/** The ribbon style edit box. */
	FR_RibbonStyle_CheckBox,			/** The ribbon style check box. */
	FR_RibbonStyle_RadioBox,			/** The ribbon style radio box. */
	FR_RibbonStyle_MenuButton,		    /** The ribbon style menu button. */
	FR_RibbonStyle_SliderCtrl,			/** The ribbon style slider. */
	FR_RibbonStyle_LinkButton,			/** The ribbon style link button. */
	FR_RibbonStyle_ComboGalleryCtrl,	/** The ribbon style combo gallery. */
	FR_RibbonStyle_GalleryCtrl,			/** The ribbon style gallery. */
	FR_RibbonStyle_Static,				/** The ribbon style static. */
	FR_RibbonStyle_ListBox,			    /** The ribbon style list box. */
	FR_RibbonStyle_ColorButton,         /** The ribbon style color button. */
	FR_RibbonStyle_ComboBox,		    /** The ribbon style comboBox. */
	FR_RibbonStyle_FontComboBox,	    /** The ribbon style font comboBox. */
	FR_RibbonStyle_SpinBtn              /** The ribbon style spin button. */
};
/* @ENUMEND */

/* @ENUMSTART FRRibbonStyleImageSide*/
/** @brief The image side.*/
enum FRRibbonStyleImageSide
{
	FR_RibbonStyle_LeftImage = 0,	/** Left side. */
	FR_RibbonStyle_RightImage,		/** Right side. */
	FR_RibbonStyle_TopImage,		/** Top side. */
};
/* @ENUMEND */

/* @ENUMSTART FRRibbonStyleFlatType*/
/** @brief The flat type. */
enum FRRibbonStyleFlatType
{
	FR_RibbonStyle_FlatType_3D,			/** The 3D flat type. */
	FR_RibbonStyle_FlatType_Flat,		/** The normal flat type. */
	FR_RibbonStyle_FlatType_NoBorders	/** The flat type with no borders. */
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief The plug-in can add a window to the status bar in the specified location.
 */
enum FRStatusBarLocation
{
    FR_STATUSBAR_LOCATION_LEFT = 0,	/** The left location. */
    FR_STATUSBAR_LOCATION_CENTER,	/** The center location. */
    FR_STATUSBAR_LOCATION_RIGHT		/** The right location. */
};
/* @ENUMEND */

/* @CALLBACKGROUPSTART FR_StatusBarWndExCallbacks */
/**
* @brief The plug-in can add a window to the status bar in the specified location. The callback set is used to create the status bar window.
 */
typedef struct _fr_statusbarwndex_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_StatusBarWndExCallbacksRec</a>). */
    unsigned long	lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRStatusBarWndExOnGetTooltip */
    /**
     * @brief A callback for adding a window to the status bar.
     *
     * The callback is invoked by Foxit Reader to receive the tooltip of the status bar window.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[out] outTooltip	It receives the tooltip.
     * @return	void
     * @note
     */
    void (*FRStatusBarWndExOnGetTooltip)(FS_LPVOID clientData, FS_WideString outTooltip);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRStatusBarWndExOnCreateWnd */
    /**
     * @brief A callback for adding a window to the status bar.
     *
     * The callback is invoked by Foxit Reader to notify the plug-in to create the window.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pParent		The parent window. It represents the <Italic>MFC CWnd</Italic>.
     * @return	The status bar window created.
     * @note
     */
    FS_HWND (*FRStatusBarWndExOnCreateWnd)(FS_LPVOID clientData, void* pParent);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRStatusBarWndExGetSize */
    /**
     * @brief A callback for adding a window to the status bar.
     *
     * The callback is invoked by Foxit Reader to receive the size of the status bar window.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[out] cx			It receives the horizon size.
     * @param[out] cy			It receives the vertical size.
     * @return	void
     * @note
     */
    void (*FRStatusBarWndExGetSize)(FS_LPVOID clientData, FS_INT32* cx, FS_INT32* cy);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRStatusBarWndExOnSize */
    /**
     * @brief A callback for adding a window to the status bar.
     *
     * The callback is invoked by Foxit Reader when the size is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] cx			It indicates the horizon size.
     * @param[in] cy			It indicates the vertical size.
     * @return	void
     * @note
     */
    void (*FRStatusBarWndExOnSize)(FS_LPVOID clientData, FS_INT32 cx, FS_INT32 cy);
    /* @CALLBACKEND */

}FR_StatusBarWndExCallbacksRec, *FR_StatusBarWndExCallbacks;
/* @CALLBACKGROUPEND */

/* @ENUMSTART */
/** @brief The align type of the format tools.
 */
enum FRFORMAT_ALIGN
{
    FRFORMAT_ALIGN_LEFT = 0,        /**< The align type is left.*/
    FRFORMAT_ALIGN_CENTER = 1,      /**< The align type is center.*/
    FRFORMAT_ALIGN_RIGHT = 2,       /**< The align type is right.*/
    FRFORMAT_ALIGN_JUSTIFY = 3      /**< The align type is justify.*/
};
/* @ENUMEND */

/* @DEFGROUPSTART FRFormatToolsButtonIDDefs */
/**
 * @brief The definitions for format tool button ID.
 */
/*@{*/
/** @brief The ID of the color setting button. */
#define FR_FMT_TEXT_COLOR    1
/** @brief The ID of the font name setting button. */
#define FR_FMT_FONT_NAME     2
/** @brief The ID of the font size setting button. */
#define FR_FMT_FONT_SIZE     3
/** @brief The ID of the border color setting button. */
#define FR_FMT_BORDER_COLOR  4
/** @brief The ID of the fill color setting button. */
#define FR_FMT_FILL_COLOR    5
/** @brief The ID of the bold setting button. */
#define FR_FMT_BOLD          6
/** @brief The ID of the italic setting button. */
#define FR_FMT_ITALIC        7
/** @brief The ID of the left alignment setting button. */
#define FR_FMT_ALIGN_LEFT    8
/** @brief The ID of the center alignment setting button. */
#define FR_FMT_ALIGN_CENTER  9
/** @brief The ID of the right alignment setting button. */
#define FR_FMT_ALIGN_RIGHT   10
/** @brief The ID of the character space setting button. */
#define FR_FMT_CHAR_SPACE    11
/** @brief The ID of the horizon scale setting button. */
#define FR_FMT_HORZ_SCALE    12
/** @brief The ID of the line leading setting button. */
#define FR_FMT_LINE_LEADING  13
/** @brief The ID of the underline setting button. */
#define FR_FMT_UNDERLINE     14
/** @brief The ID of the cross setting button. */
#define FR_FMT_CROSS		 15
/** @brief The ID of the superscript setting button. */
#define FR_FMT_SUPERSCRIPT   16
/** @brief The ID of the subscript setting button. */
#define FR_FMT_SUBSCRIPT	 17
/** @brief The ID of the indent setting button. */
#define FR_FMT_INDENT		 18
/** @brief The ID of the dedent setting button. */
#define FR_FMT_DEDENT		 19
/** @brief The ID of the italic setting button. */
#define FR_FMT_WORDSPACE	 20
/** @brief The ID of the line color setting button. */
#define FR_FMT_LINECOLOR	 4
/** @brief The ID of the writing direction setting button. */
#define FR_FMT_WRITING_DIR	 21
/** @brief The ID of the opacity setting button. */
#define FR_FMT_OPACITY		 22
/** @brief The ID of the bullet symbol setting button. */
#define FR_FMT_BULLET_SYMBOL 23
/** @brief The ID of the align justfify setting button. */
#define FR_FMT_ALIGN_JUSTIFY 24
/** @brief The ID of the paragraph spacing setting button. */
#define FR_FMT_PARAGRAPH_SPACING 25
/** @brief The ID of mode button. Only be used for Windows Now.*/
#define FR_FMT_MODE          28
/*@}*/
/* @DEFGROUPEND */

/* @ENUMSTART FRFormatToolArrangeInfo*/
/** @brief The arrange info for selected annotations or form fields.*/
enum FRFormatToolArrangeInfo
{
    FRFormatToolArrangeInfo_ALIGN = 0,	/** The arrange info of alignment. */
    FRFormatToolArrangeInfo_CENTER ,	/** The arrange info of page centering. */
    FRFormatToolArrangeInfo_DISTRIBUTE	/** The arrange info of distribution. */
};
/* @ENUMEND */

/* @ENUMSTART FRFormatToolArrangeAlignInfo*/
/** @brief The alignment type of arrange info.*/
enum FRFormatToolArrangeAlignInfo
{
    FRFormatToolArrangeAlignInfo_LEFT = 0,	/** Left alignment. */
    FRFormatToolArrangeAlignInfo_RIGHT,		/** Right alignment. */
    FRFormatToolArrangeAlignInfo_TOP,		/** Top alignment. */
    FRFormatToolArrangeAlignInfo_BOTTOM,	/** Bottom alignment. */
    FRFormatToolArrangeAlignInfo_VER,		/** Vertical alignment. */
    FRFormatToolArrangeAlignInfo_HOR		/** Horizon alignment. */
};
/* @ENUMEND */

/* @ENUMSTART FRFormatToolArrangeCenterInfo*/
/** @brief The page centering type of arrange info.*/
enum FRFormatToolArrangeCenterInfo
{
    FRFormatToolArrangeCenterInfo_VER = 0,	/** Vertical page centering. */
    FRFormatToolArrangeCenterInfo_HOR,		/** Horizon page centering. */
    FRFormatToolArrangeCenterInfo_BOTH,		/** Both vertical and horizon page centering. */
};
/* @ENUMEND */

/* @ENUMSTART FRFormatToolArrangeDistributeInfo*/
/** @brief The distribution type of arrange info.*/
enum FRFormatToolArrangeDistributeInfo
{
    FRFormatToolArrangeDistributeInfo_VER = 0,	/** @brief Vertical distribution. */
    FRFormatToolArrangeDistributeInfo_HOR		/** @brief Horizon distribution. */
};
/* @ENUMEND */

#ifndef FRFORMATTOOLWRITINGDIRECTION
#define FRFORMATTOOLWRITINGDIRECTION

/* @ENUMSTART FRFormatToolWritingDirection*/
/** @brief The writing direction.*/
enum FRFormatToolWritingDirection
{
	FR_LEFT_TO_RIGHT = 0,	/** @brief The writing direction of left-to-right. */
	FR_RIGHT_TO_LEFT		/** @brief The writing direction of right-to-left. */
};
/* @ENUMEND */
#endif

/* @ENUMSTART FRFormatToolContextCategoryType*/
/** @brief The format category type.*/
enum FRFormatToolContextCategoryType
{
    FR_CATOGRY_COMMENT_FORMAT = 0, /** @brief The Comment format category type*/
    FR_CATOGRY_OBJECT_FORMAT,		/** @brief The object format category type*/
    FR_CATOGRY_ARRANGE_FORMAT,		/** @brief The arrange format category type*/
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief The importance type of the bulb message.
 */
enum FRMSGIMPORTANCE
{
    FR_IMPO_LOW,	/**< The importance is low.*/
    FR_IMPO_HIGH	/**< The importance is high.*/
};
/* @ENUMEND */

/* @CALLBACKSTART FRBulbMsgOperationCallback */
/**
 *@brief The callback is invoked by Foxit Reader when user clicks the operation button of the bulb message.
 * @param[in] clientData	The user-supplied data.
 * @return void.
 * @note
 * @see FRBulbMsgCenterAddMessage
 */
typedef void (*FRBulbMsgOperationCallback)(void *clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRBulbMsgCheckCallback */
/**
 *@brief The callback is invoked by Foxit Reader when user clicks the check box of the bulb message. The check box is
 * used to check that whether to not show the bulb message again.
 * @param[in] bCheck		Indicates that whether to not show the bulb message again.
 * @param[in] clientData	The user-supplied data.
 * @return void.
 * @note
 * @see FRBulbMsgCenterAddMessage
 */
typedef void (*FRBulbMsgCheckCallback)(FS_BOOL bCheck, void* clientData);
/* @CALLBACKEND */

/* @STRUCTSTART FRBULBMESSAGEINFO*/
#ifndef FR_FRBULBMESSAGEINFO
#define FR_FRBULBMESSAGEINFO
/**
* @brief A data structure representing a bulb message information.
*
*/
typedef struct __FRBULBMESSAGEINFO__
{
    /** The user-supplied data. */
    void*						pClientData;

    /** The unique name of the bulb message. Required. */
    FS_LPCSTR					lpsMsgName;

    /** The message content. Required. */
    FS_LPCWSTR					lpwsMessage;

    /** The importance type of the bulb message. The default value is <a>FR_IMPO_LOW</a>. */
    FRMSGIMPORTANCE				importance;

    /** Deprecated.Whether to show the check box of "Don't show again.".*/
    FS_BOOL						bShowCheckBox;

    /** Whether to check the check box of "Don't show again." */
    FS_BOOL						bCheck;

    /** Deprecated.The title of the check box." */
    FS_LPCWSTR					lpwsCheckBoxTitle;

    /** Deprecated. The callback is invoked by Foxit Reader when user clicks the check box of the bulb message. */
    FRBulbMsgCheckCallback		ckCallbackFunc;

    /** The count of the operation buttons. */
    FS_INT32					opBtnCount;

    /** The byte string array of operation button names. The array size must be equal to opBtnCount. */
    FS_ByteStringArray			opBtnNames;

    /** The wide string array of operation button titles. The array size must be equal to opBtnCount. */
    FS_WideStringArray			opBtnTitles;

    /** The callbacks are invoked by Foxit Reader when user clicks the operation buttons of the bulb message. */
    FRBulbMsgOperationCallback*	opCallbackFuncList;

    /** Deprecated.Indicates whether the bulb message can be cleared. */
    FS_BOOL						bCanBeCleared;

    /** Indicates whether the Don't show again button can be show, and it has been deprecated after version 9.2 */
    FS_BOOL						bShowDoNotAgainBtn;

    /** When it is TRUE, it is mandatory to set bCanBeCleared to FALSE, and it has been deprecated after version 9.2 */
    FS_BOOL						bSpecial;

    __FRBULBMESSAGEINFO__()
    {
        pClientData = NULL;
        lpsMsgName = "";
        lpwsMessage = (FS_LPCWSTR)L"";
        lpwsCheckBoxTitle = (FS_LPCWSTR)L"";
        importance = FR_IMPO_LOW;
        bShowCheckBox = FALSE;
        bCheck = FALSE;
        ckCallbackFunc = NULL;
        opBtnCount = 0;
        opBtnNames = NULL;
        opBtnTitles = NULL;
        opCallbackFuncList = NULL;
        bCanBeCleared = TRUE;
        bShowDoNotAgainBtn = FALSE;
        bSpecial = FALSE;
    }
}FRBULBMESSAGEINFO;
#endif
/* @STRUCTEND */

/* @STRUCTSTART FRBULBMESSAGEINFO2*/
#ifndef FR_FRBULBMESSAGEINFO2
#define FR_FRBULBMESSAGEINFO2
/**
* @brief A data structure of second version representing a bulb message information. A new property of message title is added
* to the data structure. See <a>FRBulbMsgCenterAddMessage3</a> and <a>FRBulbMsgCenterAddMessage4</a>.
*
*/
typedef struct __FRBULBMESSAGEINFO2__
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FRBULBMESSAGEINFO2</a>). */
    unsigned long	lStructSize;

    /** The user-supplied data. */
    void*			pClientData;

    /** A data structure representing a bulb message information. */
    FRBULBMESSAGEINFO bulbMsgInfoV1;

    /** The message title. */
    FS_LPCWSTR		lpwsTitle;

    __FRBULBMESSAGEINFO2__()
    {
        pClientData = NULL;
        lpwsTitle = (FS_LPCWSTR)L"";
    }
}FRBULBMESSAGEINFO2;
#endif
/* @STRUCTEND */

/* @ENUMSTART FRRibbonStyleTextAlignType*/
/** @brief The alignment type of the text. */
enum FRRibbonStyleTextAlignType
{
	FR_RibbonStyle_Align_Left = 0,	/** Left alignment. */
	FR_RibbonStyle_Align_Right,		/** Right alignment. */
	FR_RibbonStyle_Align_Center		/** Center alignment. */
};
/* @ENUMEND */

/* @COMMONEND */

/* @OBJSTART FR_ToolButton */
#ifndef FR_TOOLBUTTON
#define FR_TOOLBUTTON
/**
 * @brief An <a>FR_ToolButton</a> is a button in the Foxit Reader's toolbar. Like menu items, 
 * the procedure that executes when the button is clicked can be set by a plug-in. 
 * Although not required, there generally is a menu item corresponding to each button, 
 * allowing users to select a function using either the button or the menu item.<br>
 *
 * A plug-in can invoke a button as if a user clicked it. Buttons can be enabled (selectable) or disabled (grayed out), 
 * and can be marked (selected). Each button also has an icon that appears in the toolbar. 
 * <a>FR_ToolButton</a> objects frequently, but not always, change the active tool. 
 * For example, the button that selects the snapshot tool changes the active tool.
 */
typedef struct _t_FR_ToolButton* FR_ToolButton;
#endif

/* @CALLBACKSTART FRBtnDropDownProc */
/**
* @brief The callback is invoked by Foxit Reader when user clicks the drop-down arrow 
 * displayed next to the button image or text.
 * @param[in] clientData	The user-supplied data. Plug-ins can set the data by invoking <a>FRToolButtonSetClientData</a>();
 * @param[in] rect			The rectangle of the drop-down button.
 * @return <a>TRUE</a> means it is handled successfully, otherwise not.
 * @note
 */
typedef FS_BOOL	(*FRBtnDropDownProc)(void *clientData, FS_Rect rect);
/* @CALLBACKEND */
/* @OBJEND */

/* @OBJSTART FR_ToolBar */
#ifndef FR_TOOLBAR
#define FR_TOOLBAR
/**
 * @brief <a>FR_ToolBar</a> is the Foxit Reader toolbar. A plug-in can also create fly-out toolbars that contain
 * additional buttons and attach the fly-out toolbars to existing button.<br>
 *
 * Plug-ins can add tool buttons to a toolbar or remove buttons form a toolbar. It can also show or hide a toolbar, and create new toolbars.<br>
 * Buttons can be organized into groups which have same functions, with a separator between the groups. It is possible to implement a group in which only one button
 * can be selected at a time. The logic of doing this is the plug-in's responsibility; the plug-in API does not provide any means to automatically relate one
 * button's state to another button's state.<br>
 * A plug-in adds buttons to a toolbar by specifying the relative position of the button (before or after) to an existing button.
 */
typedef struct _t_FR_ToolBar *FR_ToolBar;
#endif

/* @DEFGROUPSTART FRToolbarNames */
/**
 * @brief The macro definitions for the name of built-in toolbar. See <a>FRAppGetToolBarByName</a>.
 */
/*@{*/
/** @brief Basic Tools*/
#define  FR_TOOLBAR_NAME_BASIC_TOOLS		 "Basic Tools"

/** @brief File*/
#define  FR_TOOLBAR_NAME_FILE_TOOLS		 "File"

/** @brief Navigation*/
#define  FR_TOOLBAR_NAME_NAVIGATION_TOOLS	 "Navigation"

/** @brief Zoom*/
#define  FR_TOOLBAR_NAME_ZOOM_TOOLS		 "Zoom"

/** @brief Rotate View*/
#define  FR_TOOLBAR_NAME_ROTATEVIEW_TOOLS	 "Rotate View"

/** @brief Full Screen*/
#define  FR_TOOLBAR_NAME_FULLSCREEN_TOOLS	 "Full Screen"

/** @brief Text Viwer*/
#define  FR_TOOLBAR_NAME_TEXTVIEWER_TOOLS	 "Text Viwer"

/** @brief Zoom Flyout*/
#define  FR_TOOLBAR_NAME_FLYOUTZOOM_TOOLS	 "Zoom Flyout"

/** @brief Favorite Tools*/
#define  FR_TOOLBAR_NAME_FAVORITE_TOOLS	 "Favorite Tools"

/** @brief Commenting Tools*/
#define  FR_TOOLBAR_NAME_MARKUP_TOOLS		"Commenting Tools"

/** @brief Form Tools*/
#define  FR_TOOLBAR_NAME_FORM_TOOLS		"Form Tools"

/** @brief Drawing Markup Tools*/
#define  FR_TOOLBAR_NAME_DRAWING_TOOLS		"Drawing Markup Tools"

/** @brief Smart Text Tools*/
#define  FR_TOOLBAR_NAME_TEXT_TOOLS		"Smart Text Tools"

/** @brief Link Tools*/
#define  FR_TOOLBAR_NAME_LINK_TOOLS        "Link Tools"

/** @brief Measure Tools*/
#define  FR_TOOLBAR_NAME_MEAS_TOOLS        "Measure Tools"

/** @brief Multimedia Tools*/
#define	 FR_TOOLBAR_NAME_MMEDIA_TOOLS		"Multimedia Tools"

/** @brief Advanced Tools*/
#define  FR_TOOLBAR_NAME_ADVANCED_TOOLS		"Advanced Editing"

/** @brief FileAttachment Tools*/
#define	 FR_TOOLBAR_NAME_FATACH_TOOLS		"FileAttachment Tools"

/** @brief Markup Tools*/
#define	 FR_TOOLBAR_NAME_MARKUPS_TOOS		"Markup Tools"

/** @brief Drawing*/
#define	 FR_TOOLBAR_NAME_DRAWING2_TOOLS	"Drawing"

/** @brief Stamp Tools*/
#define	 FR_TOOLBAR_NAME_STAMP_TOOLS	    "Stamp Tools"

/** @brief Format Tools*/
#define  FR_TOOLBAR_NAME_FORMAT_TOOLS		"Format Tools"

/** @brief Typewriter Tools*/
#define	 FR_TOOLBAR_NAME_FREETEXT_TOOLS	"Typewriter Tools"

/** @brief Find ToolBar*/
#define  FR_TOOLBAR_NAME_FIND_TOOLS		"Find ToolBar"

/** @brief Security Editing Tools*/
#define  FR_TOOLBAR_NAME_SECURITY_TOOLS	"Security Editing Tools"

/** @brief Property Tools*/
#define  FR_TOOLBAR_NAME_PROPERTY_TOOLS	"Property Tools"

/** @brief Digital Signature Tools*/
#define	 FR_TOOLBAR_NAME_DIGITAL_TOOLS     "Digital Signature Tools"
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FR_MessageBar */
#ifndef FR_MESSAGEBAR
#define FR_MESSAGEBAR
/**
 * @brief The <a>FR_MessageBar</a> object is used to show some customer message. Plug-in can add some element to the 
 * message bar, such as bitmap, text, button and so on.
 */
typedef struct _t_FR_MessageBar* FR_MessageBar;
#endif

/* @ENUMSTART */
/** @brief Message bar element alignment type enumeration. 
 */
enum FRMessageBarElementAlignment
{
	FR_ALIGN_LEFT = 1,	/**< Align to left.*/
	FR_ALIGN_RIGHT	/**< Align to right. */
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief Icon type enumeration of the message bar. */
enum FRMessageBarIconType
{
	FR_MessageBar_ICON_USER=0,		/**< No icon.*/
    FR_MessageBar_ICON_WARNING,		/**< Warning icon.*/
    FR_MessageBar_ICON_OK,			/**< OK icon.*/
    FR_MessageBar_ICON_ERROR		/**< Error icon.*/
};
/* @ENUMEND */

/* @OBJEND */

/* @OBJSTART FR_TabBand */
#ifndef FR_TABBAND
#define FR_TABBAND
/**
 * @brief A <a>FR_TabBand</a> is a band where documents' tabs are shown. A tab is associated with a window.
 */
typedef struct _t_FR_TabBand* FR_TabBand;
#endif

/* @CALLBACKGROUPSTART FR_TabBandAddBtnCallbacks */
/**
 * @brief A callback set for adding button to the tab band.
 *
 */
typedef struct _fr_tabbandaddbtn_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_TabBandAddBtnCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRTabBandOnClickBtn */
	/**
     * @brief A callback for adding button to the tab band.
	 *
	 * It is invoked when the user clicks the button.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @return void
     * @note
	 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
     */
	void (*FRTabBandOnClickBtn)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTabBandGetTooltip */
	/**
     * @brief A callback for adding button to the tab band.
	 *
	 * It is invoked by Foxit Reader to receive the tooltip.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[out] outTooltip	It receives the tooltip.
	 * @return void
     * @note
	 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
     */
	void (*FRTabBandGetTooltip)(FS_LPVOID clientData, FS_WideString outTooltip);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTabBandTopPriority */
	/**
     * @brief A callback for adding button to the tab band.
	 *
	 * It is invoked by Foxit Reader to determine whether this callback set is the most top priority, because only one such 
	 * button can be added to the tab band.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @return TRUE to make the callback set as the most top priority, otherwise not.
     * @note
	 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
     */
	FS_BOOL (*FRTabBandTopPriority)(FS_LPVOID clientData);
	/* @CALLBACKEND */

}FR_TabBandAddBtnCallbacksRec, *FR_TabBandAddBtnCallbacks;
/* @CALLBACKGROUPEND */
/* @OBJEND */

/* @OBJSTART FR_RibbonBar */
#ifndef FR_RIBBONBAR
#define FR_RIBBONBAR
/**
 * @brief The Foxit Reader has a ribbon bar in ribbon mode. The ribbon contains several categories. You can get the ribbon bar object by
 * calling <a>FRAppGetRibbonBar</a>.
 */
typedef struct _t_FR_RibbonBar* FR_RibbonBar;
#endif

/* @CALLBACKGROUPSTART FR_RibbonFilePageEventCallbacks */
/**
 * @brief A callback set for ribbon file page event handler. See <a>FRRibbonBarRegisterFilePageEventHandler</a>.
 *
 */
typedef struct _fr_ribbonfilepageevent_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_RibbonFilePageEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FROnRemovePropertyPage */
	/**
     * @brief A callback for ribbon file page event handler.
	 *
	 * It is called whenever a property page is removed.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @param[in] lpsName		The specified property page name.
     * @note
	 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
     */
	void    (*FROnRemovePropertyPage)(FS_LPVOID clientData, FS_LPCSTR lpsName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnClickAddPlacePageButton */
	/**
     * @brief A callback for ribbon file page event handler.
	 *
	 * It is called whenever a button on a add-a-place property page is clicked.
	 *
	 * @param[in] clientData		The user-supplied data.
     * @param[in] lpsButtonName		The specified button name.
	 * @param[in] bSaveAsItemPage	Indicates whether the property page is under save as item or not.
     * @note
	 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.2
     */
	void    (*FROnClickAddPlacePageButton)(FS_LPVOID clientData, FS_LPCSTR lpsButtonName, FS_BOOL bSaveAsItemPage);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnSelectPropertyPage */
	/**
     * @brief A callback for ribbon file page event handler.
	 *
	 * It is called whenever a property page is selected.
	 *
	 * @param[in] clientData		The user-supplied data.
     * @param[in] lpsElementName	The specified ribbon element name.
	 * @param[in] lpsPageName		The specified ribbon property page name.
     * @note
	 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.2
     */
	void    (*FROnSelectPropertyPage)(FS_LPVOID clientData, FS_LPCSTR lpsElementName, FS_LPCSTR lpsPageName);
	/* @CALLBACKEND */

}FR_RibbonFilePageEventCallbacksRec, *FR_RibbonFilePageEventCallbacks;
/* @CALLBACKGROUPEND */

/* @OBJEND */

/* @OBJSTART FR_RibbonPanel */
#ifndef FR_RIBBONPANEL
#define FR_RIBBONPANEL
/**
 * @brief The ribbon panel can be used to classify the operation. You can put the ribbon element on the ribbon panel. The ribbon panel object
 * is managed by the ribbon category. You can add a ribbon panel through <a>FRRibbonCategoryAddPanel</a>.
 */
typedef struct _t_FR_RibbonPanel* FR_RibbonPanel;
#endif

/* @CALLBACKSTART FRPanelDlgCreateProc */
/**
* @brief The callback function is called to notify the plug-in to create the dialog attached to the panel.
 * @param[in] hParentWnd	The parent window handle.
 * @param[in] pDialog		The pointer to a <Italic>MFC CDialog</Italic> attached to the panel. It is passed from <a>FRRibbonPanelAddDialog</a>.
 * @return The dialog handle created.
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRRibbonPanelAddDialog
 */
typedef HWND (*FRPanelDlgCreateProc)(HWND hParentWnd, void* pDialog);
/* @CALLBACKEND */

/* @CALLBACKSTART FRPanelDlgDestoryProc */
/**
* @brief The callback function is called to notify the plug-in to destroy the dialog attached to the panel.
 * @param[in] pDialog		The dialog handle to be destroyed. It is passed from <a>FRRibbonPanelAddDialog</a>.
 * @return void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRRibbonPanelAddDialog
 */
typedef void (*FRPanelDlgDestoryProc)(void* pDialog);
/* @CALLBACKEND */

/* @CALLBACKSTART FRRibbonPanelImageInitProc */
/**
* @brief The callback is invoked by Foxit Reader when the ribbon object is to init the image.
*
* @param[in] ribbonPanel	The ribbon panel is to init the image.
* @param[in] reserved		It is reserved.
* @return	void
* @note
* @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
*/
typedef void(*FRRibbonPanelImageInitProc)(FR_RibbonPanel ribbonPanel, void* reserved);
/* @CALLBACKEND */
/* @OBJEND */

/* @OBJSTART FR_RibbonCategory */
#ifndef FR_RIBBONCATEGORY
#define FR_RIBBONCATEGORY
/**
* @brief A <a>FR_RibbonCategory</a> object can be used to manage the operation categories. For example, all the commenting tools
* are included in the COMMENT category. For further classification, you have to add ribbon panels to the ribbon categories.
 */
typedef struct _t_FR_RibbonCategory* FR_RibbonCategory;
#endif

/* @CALLBACKSTART FRCategoryDlgCreateProc */
/**
* @brief The callback function is called to notify the plug-in to create the dialog attached to the category.
 * @param[in] hParentWnd	The parent window handle.
 * @param[in] pDialog		The pointer to a <Italic>MFC CDialog</Italic> attached to the category. It is passed from <a>FRRibbonCategoryAddDialog</a>.
 * @return The dialog handle created.
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRRibbonCategoryAddDialog
 */
typedef HWND (*FRCategoryDlgCreateProc)(HWND hParentWnd, void* pDialog);
/* @CALLBACKEND */

/* @CALLBACKSTART FRCategoryDlgDestoryProc */
/**
* @brief The callback function is called to notify the plug-in to destroy the dialog attached to the category.
 * @param[in] pDialog		The dialog handle to be destroyed. It is passed from <a>FRRibbonCategoryAddDialog</a>.
 * @return void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRRibbonCategoryAddDialog
 */
typedef void (*FRCategoryDlgDestoryProc)(void* pDialog);
/* @CALLBACKEND */
/* @OBJEND */

/* @OBJSTART FR_RibbonElement */
#ifndef FR_RIBBONELEMENT
#define FR_RIBBONELEMENT
/**
 * @brief The ribbon element object is a basic object. It manipulates the common properties of all types of ribbon element.
 *
 * The ribbon element object is a basic object. It manipulates the common properties of all types of ribbon element, such as the title,
 * the description, the icon and so on. A specified type of ribbon element is associated with a ribbon element object. About the type of
 * ribbon element, you can reference to <a>FR_Ribbon_Element_Type</a>. You can add a new ribbon element to the ribbon panel through <a>FRRibbonPanelAddElement</a>.
 */
typedef struct _t_FR_RibbonElement* FR_RibbonElement;
#endif

/* @ENUMSTART */
/**
 * @brief The type of ribbon element.
 */
enum FR_Ribbon_Element_Type
{
    FR_RIBBON_NULL = -1,		/** Unknown type. */
    FR_RIBBON_BUTTON,			/** The type is button. */
    FR_RIBBON_LABEL,			/** The type is label. */
    FR_RIBBON_EDIT,				/** The type is edit. */
    FR_RIBBON_CHECKBOX,			/** The type is check box. */
    FR_RIBBON_RADIOBUTTON,		/** The type is radio button. */
    FR_RIBBON_COMBOBOX,			/** The type is combo box. */
    FR_RIBBON_FONTCOMBOBOX,		/** The type is font combo box. */
    FR_RIBBON_PALETTEBUTTON,	/** The type is palette button. */
    FR_RIBBON_LISTBUTTON,		/** The type is list button. */
    FR_RIBBON_COLORBUTTON,		/** The type is color button. */
    FR_RIBBON_SLIDER,			/** The type is slider. */
    FR_RIBBON_SEPARATOR	,		/** The type is separator. */
	FR_RIBBON_BACKSTAGEITEM,    /** The type is backstageitem. */
	FR_RIBBON_HYPERLINK,		/** The type is hyperlink. */
	FR_RIBBON_CAPTIONBUTTON     /** The type is CaptionButton. */
};
/* @ENUMEND */

/* @CALLBACKSTART FRRibbonElementImageInitProc */
/**
 * @brief The callback is invoked by Foxit Reader when the ribbon object is to init the image.
 *
 * @param[in] ribbonElement	The ribbon element is to init the image.
 * @param[in] clientData	The client data associated with the ribbon element.
 * @return	void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
typedef void(*FRRibbonElementImageInitProc)(FR_RibbonElement ribbonElement, void* clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRRibbonElementDropDownAddElementProc */
/**
 * @brief The callback is invoked by Foxit Reader when the ribbon object drop down to add element.
 *
 * @param[in] clientData	The client data associated with the ribbon element.
 * @return	void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
typedef void(*FRRibbonElementDropDownAddElementProc)(FS_LPVOID pClientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRRibbonElementEditChangeProc */
/**
 * @brief The callback is invoked by Foxit Reader when the edit ribbon element changed.
 *
 * @param[in] clientData	The client data associated with the ribbon element.
 * @return	void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
typedef void(*FRRibbonElementEditChangeProc)(FS_LPVOID pClientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRRibbonElementClosePopupMenuProc */
/**
 * @brief The callback is invoked by Foxit Reader when the edit ribbon element close popup menu.
 *
 * @param[in] clientData	The client data associated with the ribbon element.
 * @return	void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
typedef void(*FRRibbonElementClosePopupMenuProc)(FS_LPVOID pClientData);
/* @CALLBACKEND */

/* @STRUCTSTART FR_RIBBONBUTTONINFO*/
typedef struct _fr_ribbonbuttoninfo_
{
	_fr_ribbonbuttoninfo_()
	{
		nRibbonType = FR_Ribbon_Element_Type::FR_RIBBON_BUTTON;
		csCategoryName = "";
		csPanelName = "";
		nID = -1;
		nOriginID = -1;
		csButtonTitle = L"";
		csButtonName = "";
		csToolTip = L"";
		csDescription = L"";
		pLargeBitmap = NULL;
		pSmallBitmap = NULL;
		pImpLargeBitmap = NULL;
		nWidth = 90;
		bIsHoriz = FALSE;
		bTooltipHasHelp = FALSE;
		wsLargeBitmapName = L"";
		wsSmallBitmapName = L"";
		wsImpLargeBitmapName = L"";
	}

	/** Specifies the map ID of the Button. */
	FS_UINT nID;
	/** Specifies the origin ID. */
	FS_UINT nOriginID;
	/** Category name, unique identifier, default to the current category. */
	FS_LPCSTR csCategoryName;
	/** Panel name, unique identifier, default use of the current Panel. */
	FS_LPCSTR csPanelName;
	/** Button title. */
	FS_LPCWSTR csButtonTitle;
	/** Button name, unique identifier, not repeated. */
	FS_LPCSTR csButtonName;
	/** The first line of the prompt. */
	FS_LPCWSTR csToolTip;
	/** The second line of the prompt. */
	FS_LPCWSTR csDescription;
	/** Large icon, no need to release manually, the program will be closed after processing. */
	FS_DIBitmap pLargeBitmap;
	/** Small icon, no need to release manually, the program will be closed after processing. */
	FS_DIBitmap pSmallBitmap;
	/** Implicitly large icon, plargeBitmap has a value, use plargeBitmap, for small icon to large icon, custom function. */
	FS_DIBitmap pImpLargeBitmap;
	/** The large bitmap name. */
	FS_LPCWSTR				wsLargeBitmapName;
	/** The small bitmap name. */
	FS_LPCWSTR				wsSmallBitmapName;
	/** The imp bitmap name. */
	FS_LPCWSTR				wsImpLargeBitmapName;
	/** The width of the bitmap. */
	FS_INT32			   nWidth;
	/** Whether shows in horizontal. */
	FS_BOOL		   bIsHoriz;
	/** Shows whether the tooltip has the help link. */
	FS_BOOL		   bTooltipHasHelp;
	/** The ribbon type. */
	FR_Ribbon_Element_Type nRibbonType;
}FR_RIBBONBUTTONINFO, *PFR_RIBBONBUTTONINFO;
/* @STRUCTEND */

/* @OBJEND */

/* @OBJSTART FR_CommonControl */
#ifndef FR_COMMONCONTROL
#define FR_COMMONCONTROL
/**
* @brief The ribbon control object is a basic object. It manipulates the common properties of all types of ribbon control.
*
* The ribbon control object is a basic object. It manipulates the common properties of all types of ribbon control, such as the title,
* the description, the icon and so on. A specified type of ribbon control is associated with a ribbon control object. About the type of
* ribbon control, you can reference to <a>FR_Common_Control_Type</a>.
*/
typedef struct _t_FR_CommonControl* FR_CommonControl;
#endif

/* @ENUMSTART */
/**
 * @brief The type of ribbon element.
 */
enum FR_Common_Control_Type
{
    FR_CommonControl_UNKNOWN = -1,		/** Unknown type. */
    FR_CommonControl_BUTTON = 0,		/** The type is button. */
    FR_CommonControl_DROPDOWNBUTTON,    /** The type is button can be drop down with a menu. */
    FR_CommonControl_DROPDOWNACTION,    /** The type is action can be drop down with a menu. */
    FR_CommonControl_CHECKBOX,          /** The type is check box. */
};
/* @ENUMEND */

/* @OBJEND */

/* @OBJSTART FR_RibbonButton */
#ifndef FR_RIBBONBUTTON
#define FR_RIBBONBUTTON
/**
 * @brief The ribbon button is a type of ribbon element.
 */
typedef struct _t_FR_RibbonButton* FR_RibbonButton;
#endif
/* @OBJEND */

/* @OBJSTART FR_RibbonEdit */
#ifndef FR_RIBBONEDIT
#define FR_RIBBONEDIT
/**
 * @brief The ribbon edit is a type of ribbon element.
 */
typedef struct _t_FR_RibbonEdit* FR_RibbonEdit;
#endif
/* @OBJEND */

/* @OBJSTART FR_RibbonLabel */
#ifndef FR_RIBBONLABEL
#define FR_RIBBONLABEL
/**
 * @brief The ribbon label is a type of ribbon element.
 */
typedef struct _t_FR_RibbonLabel* FR_RibbonLabel;
#endif
/* @OBJEND */

/* @OBJSTART FR_RibbonCheckBox */
#ifndef FR_RIBBONCHECKBOX
#define FR_RIBBONCHECKBOX
/**
 * @brief The ribbon check box is a type of ribbon element.
 */
typedef struct _t_FR_RibbonCheckBox* FR_RibbonCheckBox;
#endif
/* @OBJEND */

/* @OBJSTART FR_RibbonRadioButton */
#ifndef FR_RIBBONRADIOBUTTON
#define FR_RIBBONRADIOBUTTON
/**
 * @brief The ribbon radio button is a type of ribbon element.
 */
typedef struct _t_FR_RibbonRadioButton* FR_RibbonRadioButton;
#endif
/* @OBJEND */

/* @OBJSTART FR_RibbonComboBox */
#ifndef FR_RIBBONCOMBOBOX
#define FR_RIBBONCOMBOBOX
/**
 * @brief The ribbon combo box is a type of ribbon element.
 */
typedef struct _t_FR_RibbonComboBox* FR_RibbonComboBox;
#endif
/* @OBJEND */

/* @OBJSTART FR_RibbonFontComboBox */
#ifndef FR_RIBBONFONTCOMBOBOX
#define FR_RIBBONFONTCOMBOBOX
/**
 * @brief The ribbon font combo box is a type of ribbon element.
 */
typedef struct _t_FR_RibbonFontComboBox* FR_RibbonFontComboBox;
#endif
/* @OBJEND */

/* @OBJSTART FR_RibbonPaletteButton */
#ifndef FR_RIBBONPALETTEBUTTON
#define FR_RIBBONPALETTEBUTTON
/**
 * @brief The ribbon palette button is a type of ribbon element.
 */
typedef struct _t_FR_RibbonPaletteButton* FR_RibbonPaletteButton;
#endif

/* @CALLBACKSTART FRRibbonPaletteButtonHighlightItemProc */
/**
 * @brief The callback is invoked by Foxit Reader when the mouse is over ribbon palette object.
 *
 * @param[in] pClientData	The client data associated with the ribbon palette object.
 * @param[in] nItemIndex	The index of the item.
 * @param[in] bHighlight	Whether the item is highlight or not.
 * @return	void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
typedef void(*FRRibbonPaletteButtonHighlightItemProc)(void* pClientData, FS_INT32 nItemIndex, FS_BOOL bHighlight);
/* @CALLBACKEND */
/* @OBJEND */

/* @OBJSTART FR_RibbonColorButton */
#ifndef FR_RIBBONCOLORBUTTON
#define FR_RIBBONCOLORBUTTON
/**
 * @brief The ribbon color button is a type of ribbon element.
 */
typedef struct _t_FR_RibbonColorButton* FR_RibbonColorButton;
#endif
/* @OBJEND */

/* @OBJSTART FR_RibbonSlider */
#ifndef FR_RIBBONSLIDER
#define FR_RIBBONSLIDER
/**
 * @brief The ribbon slider is a type of ribbon element.
 */
typedef struct _t_FR_RibbonSlider* FR_RibbonSlider;
#endif
/* @OBJEND */

/* FR_RibbonListButton */
#ifndef FR_RIBBONLISTBUTTON
#define FR_RIBBONLISTBUTTON
/**
 * @brief The ribbon list button is a type of ribbon element.
 * @deprecated: Internal use.
 */
typedef struct _t_FR_RibbonListButton* FR_RibbonListButton;
#endif

/* @ENUMSTART */
/** 
	* @brief The alignment type of ribbon list button.
	*/
enum FR_RIBBON_LISTBUTTON_ALIGNEDSIDE
{
	FR_BUTTON_ALIGN_RIGHT = 0,	/** Right alignment. */
	FR_BUTTON_ALIGN_UP,			/** Up alignment. */
	FR_BUTTON_ALIGN_DOWN		/** Down alignment. */
};
/* @ENUMEND */
/*  FR_RibbonListButton */

/* @OBJSTART FR_RibbonBackStageViewItem */
#ifndef FR_RIBBONBACKSTAGEVIEWITEM
#define FR_RIBBONBACKSTAGEVIEWITEM
/**
* @brief The <a>FR_RibbonBackStageViewItem</a> object can be added under FILE category. The back stage view item is associated with a view.
* You can add your own dialog or property sheet page on the view. See <a>FRRibbonBackStageViewItemAddDialog</a> 
* and <a>FRRibbonBackStageViewItemAddPropertySheetPage</a>.
 */
typedef struct _t_FR_RibbonBackStageViewItem* FR_RibbonBackStageViewItem;
#endif

/* @CALLBACKSTART FRRibbonBackstageCreateProc */
/**
* @brief The callback function is called to notify the plug-in to create the dialog when the back stage view is shown.
 * @param[in] hParentWnd	The parent window handle.
 * @param[in] clientData	The client data.
 * @return The dialog handle created.
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBackStageViewItemAddDialog
 * @see FRRibbonBackStageViewItemAddPropertySheetPage
 */
typedef HWND (*FRRibbonBackstageCreateProc)(FS_HWND hParentWnd, void* clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRRibbonBackstageDestoryProc */
/**
* @brief The callback function is called to notify the plug-in to destroy the dialog when the back stage view is closed.
 * @param[in] pDialog		The dialog handle to be destroyed.
 * @param[in] clientData	The client data.
 * @return void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBackStageViewItemAddDialog
 * @see FRRibbonBackStageViewItemAddPropertySheetPage
 */
typedef void (*FRRibbonBackstageDestoryProc)(FS_HWND hWnd, void* clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRRibbonBackstageSelectPageProc */
/**
* @brief The callback function is called to notify the plug-in that the specified property page is selected.
 * @param[in] lpsPageName	The specified property page of the back stage view item.
 * @param[in] hWnd			The window handle of the specified property page of the back stage view item.
 * @return void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRRibbonBackStageViewItemSetPageSelectProc
 */
typedef void (*FRRibbonBackstageSelectPageProc)(FS_LPCSTR lpsPageName, HWND hWnd);
/* @CALLBACKEND */

/* @ENUMSTART */
/** @brief The move type of the back stage view item. */
enum FRRibbonBackStageViewItemXMoveType
{
	FRRIBBONBACKSTAGEVIEWITEM_MOVETYPE_NONE = 0,	/** Unknown type. */
	FRRIBBONBACKSTAGEVIEWITEM_MOVETYPE_HORZ ,		/** Moves in horizon direction. */
	FRRIBBONBACKSTAGEVIEWITEM_MOVETYPE_VERT,		/** Moves in vertical direction. */
	FRRIBBONBACKSTAGEVIEWITEM_MOVETYPE_BOTH			/** Moves in both horizon and vertical direction. */
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief The size type of the back stage view item. */
enum  FRRibbonBackStageViewItemXSizeType
{
	FRRIBBONBACKSTAGEVIEWITEM_SIZETYPE_NONE = 0,	/** Unknown type. */
	FRRIBBONBACKSTAGEVIEWITEM_SIZETYPE_HORZ,		/** The size in horizon direction. */
	FRRIBBONBACKSTAGEVIEWITEM_SIZETYPE_VERT,		/** The size in vertical direction. */
	FRRIBBONBACKSTAGEVIEWITEM_SIZETYPE_BOTH			/** The size in both horizon and vertical direction. */
};
/* @ENUMEND */

/* @OBJEND */

/* FR_RibbonStyleButton */
#ifndef FR_RIBBONSTYLEBUTTON
#define FR_RIBBONSTYLEBUTTON
/**
 * @brief The ribbon style button. You can modify the MFC button to the ribbon style button.
 * @Deprecated: Internal use.
 */
typedef struct _t_FR_RibbonStyleButton* FR_RibbonStyleButton;
#endif

enum FR_ButtonStyleSkinMode 
{
	FR_skin_Default = 0,	//跟随皮肤变化
	FR_skin_Light,			//Light样式效果
};

typedef struct __FR_ButtonStyleOption__
{
	__FR_ButtonStyleOption__()
	{
		m_bAccent = TRUE;
		m_skinMode = FR_skin_Default;
		m_bRoundCorner = TRUE;
	}
	
	FS_BOOL m_bAccent;	
	FR_ButtonStyleSkinMode m_skinMode;
	FS_BOOL m_bRoundCorner;	
}FR_ButtonStyleOption;

/* FR_RibbonStyleButton */

/* FR_RibbonStyleListBox */
#ifndef FR_RIBBONSTYLELISTBOX
#define FR_RIBBONSTYLELISTBOX
/**
 * @brief The ribbon style list box. You can modify the MFC list box to the ribbon style list box.
 * @Deprecated: Internal use.
 */
typedef struct _t_FR_RibbonStyleListBox* FR_RibbonStyleListBox;
#endif

/* @CALLBACKSTART FRClickItemProc */
/**
 * @brief  A callback for Ribbon style list box.
 *
 * It is called when the item of the Ribbon style list box is clicked.
 *
 * @param[in] nIndex		The item index of the Ribbon style list.
 * @param[in] clientData	User-supplied data.
 * @return	void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRRibbonStyleListBoxSetClickItemProc
 */
typedef void (*FRClickItemProc)(FS_INT32 nIndex, void *clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRClickPinProc */
/**
 * @brief  A callback for Ribbon style list box.
 *
 * It is called when the item pin button of the Ribbon style list box is clicked.
 *
 * @param[in] nIndex		The item index of the Ribbon style list.
 * @param[in] clientData  User-supplied data.
 * @return	void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRRibbonStyleListBoxSetClickPinProc
 */
typedef void (*FRClickPinProc)(FS_INT32 nIndex, void *clientData);
/* @CALLBACKEND */
/* FR_RibbonStyleListBox */

/* FR_RibbonStyleStatic */
#ifndef FR_RIBBONSTYLESTATIC
#define FR_RIBBONSTYLESTATIC
/**
 * @brief The ribbon style static box. You can modify the MFC static box to the ribbon style static box.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_RibbonStyleStatic* FR_RibbonStyleStatic;
#endif
/* FR_RibbonStyleStatic */

/* FR_RibbonStyleCheckBox */
#ifndef FR_RIBBONSTYLECHECKBOX
#define FR_RIBBONSTYLECHECKBOX
/**
 * @brief The ribbon style check box. You can modify the MFC CheckBox to the ribbon style check box. 
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_RibbonStyleCheckBox* FR_RibbonStyleCheckBox;
#endif
/* FR_RibbonStyleCheckBox */

/* FR_RibbonStyleRadioBox */
#ifndef FR_RIBBONSTYLECHERADIOBOX
#define FR_RIBBONSTYLECHERADIOBOX
/**
 * @brief The ribbon style radio box. You can modify the MFC CheckBox to the ribbon style radio box.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_RibbonStyleRadioBox* FR_RibbonStyleRadioBox;
#endif
/* FR_RibbonStyleRadioBox */

/* FR_RibbonStyleEdit */
#ifndef FR_RIBBONSTYLEEDIT
#define FR_RIBBONSTYLEEDIT
/**
 * @brief The ribbon style edit. You can modify the MFC Edit to the ribbon style edit.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_RibbonStyleEdit* FR_RibbonStyleEdit;
#endif
/* FR_RibbonStyleEdit */

/* FR_RibbonStyleLinkButton */
#ifndef FR_RIBBONSTYLELINKBUTTON
#define FR_RIBBONSTYLELINKBUTTON
/**
 * @brief The ribbon style link button. You can modify the MFC link button to the ribbon style link button.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_RibbonStyleLinkButton* FR_RibbonStyleLinkButton;
#endif
/* FR_RibbonStyleLinkButton */

/* FR_RibbonStyleSliderCtrl */
#ifndef FR_RIBBONSTYLESLIDERCTRL
#define FR_RIBBONSTYLESLIDERCTRL
/**
 * @brief The ribbon style sliderctrl. You can modify the MFC sliderctrl to the ribbon style sliderctrl.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_RibbonStyleSliderCtrl* FR_RibbonStyleSliderCtrl;
#endif
/* FR_RibbonStyleSliderCtrl */

/* FR_RibbonIFXBCGPCombox */
#ifndef FR_RIBBONIFXBCGPCOMBOX
#define FR_RIBBONIFXBCGPCOMBOX
/**
 * @brief The ribbon IFXBCGPComboBox. You can modify the BCGCombox to the ribbon IFXBCGPComboBox.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_RibbonStyleCombox* FR_RibbonStyleCombox;
#endif
/* FR_RibbonIFXBCGPCombox */

/* FR_RibbonIFXBCGPFontCombox */
#ifndef FR_RIBBONIFXBCGPFONTCOMBOX
#define FR_RIBBONIFXBCGPFONTCOMBOX
/**
 * @brief The ribbon IFXBCGPFontCombox. You can modify the BCGCombox to the ribbon IFXBCGPFontCombox.
 * @Deprecated: Internal use.
 */
typedef struct _t_FR_RibbonStyleFontCombox* FR_RibbonStyleFontCombox;
#endif
/* FR_RibbonIFXBCGPFontCombox */

/* FR_RibbonStyleColorButton */
#ifndef FR_RIBBONSTYLECOLORBUTTON
#define FR_RIBBONSTYLECOLORBUTTON
/**
 * @brief The ribbon style sliderctrl. You can modify the MFC sliderctrl to the ribbon style sliderctrl.
 * @Deprecated: Internal use.
 */
typedef struct _t_FR_RibbonStyleColorButton* FR_RibbonStyleColorButton;
#endif
/* FR_RibbonStyleColorButton */

/* FR_CFXBCGStyleGalleryCtrl */
#ifndef FR_CFXBCGSTYPEGALLERYCTRL
#define FR_CFXBCGSTYPEGALLERYCTRL
/**
 * @brief The ribbon style sliderctrl. You can modify the MFC sliderctrl to the ribbon style sliderctrl.
 * @Deprecated: Internal use.
 */
typedef struct _t_FR_StyleGalleryCtrl* FR_StyleGalleryCtrl;
#endif

typedef void(*FRClickButtonProc)(FS_INT32 nIndex, FS_INT32 nID, FS_LPVOID pClientData);
typedef void(*FRFreeDataProc)(FS_LPVOID clientData);
/* FR_CFXBCGStyleGalleryCtrl */

/* FR_IFXBCGPSpinBtnCtrl */
#ifndef FR_IFXBCGPSPINBTNCTRL
#define FR_IFXBCGPSPINBTNCTRL
/**
 * @brief The ribbon style sliderctrl. You can modify the MFC sliderctrl to the ribbon style sliderctrl.
 * @Deprecated: Internal use.
 */
typedef struct _t_FR_StyleSpinBtnCtrl* FR_StyleSpinBtnCtrl;
#endif
/* FR_IFXBCGPSpinBtnCtrl */

/* FR_IFXBCGStyleComboGalleryCtrl */
#ifndef FR_IFXBCGSTYPECOMBOGALLERYCTRL
#define FR_IFXBCGSTYPECOMBOGALLERYCTRL
/**
 * @brief The ribbon style sliderctrl. You can modify the MFC sliderctrl to the ribbon style sliderctrl.
 * @Deprecated: Internal use.
 */
typedef struct _t_FR_StyleComboGalleryCtrl* FR_StyleComboGalleryCtrl;
#endif
/* FR_IFXBCGStyleComboGalleryCtrl */

/* FR_StyleMenuButton */
#ifndef FR_STYLEMENUBUTTON
#define FR_STYLEMENUBUTTON
/**
 * @brief The ribbon style sliderctrl. You can modify the MFC sliderctrl to the ribbon style sliderctrl.
 * @Deprecated: Internal use.
 */
typedef struct _t_FR_StyleMenuButton* FR_StyleMenuButton;
#endif

/* @CALLBACKSTART FRPopupCreateProc */
/**
 * @brief  A callback for Ribbon style menu button.
 *
 * It is called when show menu dialog.
 *
 * @param[in] hParentWnd		The parent HWND of menu window.
 * @param[in] pClientData       User-supplied data.
 * @return	void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRStyleMenuButtonEnablePopupWnd
 */
typedef FS_HWND(*FRPopupCreateProc)(FS_HWND hParentWnd, FS_LPVOID pClientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRPopupDestoryProc */
/**
 * @brief  A callback for Ribbon style menu button.
 *
 * It is called when close menu dialog.
 *
 * @param[in] hWnd		        The HWND of menu window.
 * @param[in] pClientData       User-supplied data.
 * @return	void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRStyleMenuButtonEnablePopupWnd
 */
typedef void(*FRPopupDestoryProc)(FS_HWND hWnd, FS_LPVOID pClientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRDropDownProc */
/**
 * @brief  A callback for Ribbon style menu button.
 *
 * It is called when click drop-down menu.
 *
 * @param[in] pClientData       User-supplied data.
 * @return	void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRStyleMenuButtonSetDropdownProc
 */
typedef void(*FRDropDownProc)(FS_LPVOID pClientData);
/* @CALLBACKEND */
/* FR_StyleMenuButton */

/* FR_FormatTools */
#ifndef FR_FORMATTOOLS
#define FR_FORMATTOOLS
/**
* @brief The format tool is used to set the format of the PDF object and text. You can set the format
* like font name, font size, color and so on.
 */
typedef struct _t_FR_FormatTools* FR_FormatTools;
#endif


/* @CALLBACKGROUPSTART FR_FormatToolCallbacks */
/**
 * @brief The callback set for format tool. The callbacks are called by Foxit Reader when the events occur. You can set the callback set
 * to format tool through <a>FRFormatToolsSetEvent</a>.
 */
/** @deprecated Internal use.*/
typedef struct _fr_formattool_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_FormatToolCallbacksRec</a>). */
    unsigned long	lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRFormatToolOnFontNameChanged */
    /**
     * @brief It is called by Foxit Reader when the font name is changed.
     *
     * @param[in] clientData		The user-supplied data.
     * @param[in] lpwsFontName		The font name.
     * @param[in] lpwsScriptName	The script name.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnFontNameChanged)(FS_LPVOID clientData, FS_LPCWSTR lpwsFontName, FS_LPCWSTR lpwsScriptName);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnFontSizeChanged */
    /**
     * @brief It is called by Foxit Reader when the font size is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] flFontSize	The font size.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnFontSizeChanged)(FS_LPVOID clientData, FS_FLOAT flFontSize );
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnTextColorChanged */
    /**
     * @brief It is called by Foxit Reader when the text color is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] textColor		The text color.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnTextColorChanged)(FS_LPVOID clientData, FS_COLORREF textColor );
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnLineColorChanged */
    /**
     * @brief It is called by Foxit Reader when the line color is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] lineColor		The text color.
     * @param[in] bTransparent	Indicates whether the line is transparent.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnLineColorChanged)(FS_LPVOID clientData, FS_COLORREF lineColor, FS_FLOAT bTransparent);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnFillColorChanged */
    /**
     * @brief It is called by Foxit Reader when the filling color is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] FillColor		The text color.
     * @param[in] bTransparent	Indicates whether the line is transparent.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnFillColorChanged)(FS_LPVOID clientData, FS_COLORREF FillColor, FS_FLOAT bTransparent);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnBoldChanged */
    /**
     * @brief It is called by Foxit Reader when the bold setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] bBold			Indicates whether uses the bold.
     * @param[in] bEnabled		Indicates whether the bold setting button is enabled or not.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnBoldChanged)(FS_LPVOID clientData, FS_FLOAT bBold, FS_FLOAT bEnabled);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnItalicChanged */
    /**
     * @brief It is called by Foxit Reader when the italic setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] bItalic		Indicates whether uses the italic.
     * @param[in] bEnabled		Indicates whether the italic setting button is enabled or not.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnItalicChanged)(FS_LPVOID clientData, FS_FLOAT bItalic, FS_FLOAT bEnabled);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnAlignChanged */
    /**
     * @brief It is called by Foxit Reader when the alignment setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] dwAlign		The alignment type.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnAlignChanged)(FS_LPVOID clientData, FS_DWORD dwAlign);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnCharSpaceChanged */
    /**
     * @brief It is called by Foxit Reader when the character space setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] flSpace		The character space.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnCharSpaceChanged)(FS_LPVOID clientData, FS_FLOAT flSpace );
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnCharHorzScaleChanged */
    /**
     * @brief It is called by Foxit Reader when the character horizon scale setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nScale		The character horizon scale.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnCharHorzScaleChanged)(FS_LPVOID clientData, FS_INT32 nScale);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnLineLeadingChanged */
    /**
     * @brief It is called by Foxit Reader when the line leading setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] flLineLeading	Indicates whether uses the leading line setting.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnLineLeadingChanged)(FS_LPVOID clientData, FS_FLOAT flLineLeading);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnUnderlineChanged */
    /**
     * @brief It is called by Foxit Reader when the underline setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] bUnderline	Indicates whether uses the underline setting.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnUnderlineChanged)(FS_LPVOID clientData, FS_FLOAT bUnderline);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnCrossChanged */
    /**
     * @brief It is called by Foxit Reader when the cross setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] bCross		Indicates whether uses the cross setting.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnCrossChanged)(FS_LPVOID clientData, FS_FLOAT bCross);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnSuperScriptChanged */
    /**
     * @brief It is called by Foxit Reader when the superscript setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] bSuperSet		Indicates whether uses the superscript setting.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnSuperScriptChanged)(FS_LPVOID clientData, FS_FLOAT bSuperSet);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnSubScriptChanged */
    /**
     * @brief It is called by Foxit Reader when the subscript setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] bSubSet		Indicates whether uses the subscript setting.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnSubScriptChanged)(FS_LPVOID clientData, FS_FLOAT bSubSet);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnInDentChanged */
    /**
     * @brief It is called by Foxit Reader when the indent setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnInDentChanged)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnDeDentChanged */
    /**
     * @brief It is called by Foxit Reader when the dedent setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnDeDentChanged)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnWordSpaceChanged */
    /**
     * @brief It is called by Foxit Reader when the word space setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] fWordSpace	Indicates whether uses the word space setting.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnWordSpaceChanged)(FS_LPVOID clientData, FS_FLOAT fWordSpace);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnArrangeAlign */
    /**
     * @brief It is called by Foxit Reader when the alignment of the arrange info is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nAlign		The alignment of the arrange info.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnArrangeAlign)(FS_LPVOID clientData, FRFormatToolArrangeAlignInfo nAlign);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnArrangeCenter */
    /**
     * @brief It is called by Foxit Reader when the page centering of the arrange info is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nCenter		The page centering of the arrange info.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnArrangeCenter)(FS_LPVOID clientData, FRFormatToolArrangeCenterInfo nCenter);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnArrangeDistribute */
    /**
     * @brief It is called by Foxit Reader when the distribution of the arrange info is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nDistribute	The distribution of the arrange info.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolOnArrangeDistribute)(FS_LPVOID clientData, FRFormatToolArrangeDistributeInfo nDistribute);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolGetArrangeEnable */
    /**
     * @brief It is called by Foxit Reader to determine whether the arrange setting is enabled or not.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nInfo			The type of the arrange info.
     * @param[out] outEnable	It receives TRUE if the arrange setting is enabled.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolGetArrangeEnable)(FS_LPVOID clientData, FRFormatToolArrangeInfo nInfo, FS_BOOL* outEnable);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolGetLineColorEnableNoColor */
    /**
     * @brief It is called by Foxit Reader to determine whether the line color setting is enabled or not.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[out] outEnable	It receives TRUE if the line color setting is enabled.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolGetLineColorEnableNoColor)(FS_LPVOID clientData, FS_BOOL* outEnable);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolGetFillColorEnableNoColor */
    /**
     * @brief It is called by Foxit Reader to determine whether the filling color setting is enabled or not.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[out] outEnable	It receives TRUE if the filling color setting is enabled.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRFormatToolGetFillColorEnableNoColor)(FS_LPVOID clientData, FS_BOOL* outEnable);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnWritingDirChanged */
    /**
     * @brief It is called by Foxit Reader when the writing direction is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] eDir			It the writing direction.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRFormatToolOnWritingDirChanged)(FS_LPVOID clientData, FRFormatToolWritingDirection eDir);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnOpacityChanged */
    /**
     * @brief It is called by Foxit Reader when the opacity setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nOpacity		The opacity value.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRFormatToolOnOpacityChanged)(FS_LPVOID clientData, FS_INT32 nOpacity);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRFormatToolOnOpacityScroll */
    /**
     * @brief It is called by Foxit Reader when the opacity setting is scrolling.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nOpacity		The opacity value.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRFormatToolOnOpacityScroll)(FS_LPVOID clientData, FS_INT32 nOpacity);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRParagraphSpacingChanged */
	/**
	* @brief It is called by Foxit Reader when the space changed.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] fParaSpacing	The paragraph space.
	* @return void
	* @note
	* @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	*/
	void (*FRParagraphSpacingChanged)(FS_LPVOID clientData, FS_FLOAT fParaSpacing);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRCreateRotateZorderDlg */
	/**
	* @brief It is called by Foxit Reader when Create RotateZorder Dialog.
	*
	* @param[in] clientData	The user-supplied data.	
	* @return FS_LPVOID  CDialog
	* @note
	* @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	*/
    FS_LPVOID(*FRCreateRotateZorderDlg)(FS_LPVOID clientData, HWND hParent, FS_Rect rc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRReleaseRotateZorderDlg */
	/**
	* @brief It is called by Foxit Reader when release the dialog.
	*
	* @param[in] clientData	The user-supplied data.
	* @return void
	* @note
	* @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	*/
	void(*FRReleaseRotateZorderDlg)(FS_LPVOID clientData);
	/* @CALLBACKEND */
	
	/* @CALLBACKSTART FRRefreshRotateZorderDlg */
	/**
	* @brief It is called by Foxit Reader when refresh the dialog.
	*
	* @param[in] clientData	The user-supplied data.
	* @return void
	* @note
	* @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	*/
    void(*FRRefreshRotateZorderDlg)(FS_LPVOID clientData);
	/* @CALLBACKEND */	

	/* @CALLBACKSTART FRRefreshRotateZorderDlg */
	/**
	* @brief It is called by Foxit Reader when refresh the dialog.
	*
	* @param[in] clientData	The user-supplied data.
	* @return void
	* @note
	*/
	void(*FRNumberedList)(FS_LPVOID clientData, FS_FXEDIT_ListStyleDescriptor style);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRRefreshRotateZorderDlg */
	/**
	* @brief It is called by Foxit Reader when refresh the dialog.
	*
	* @param[in] clientData	The user-supplied data.
	* @return void
	* @note
	*/
	void(*FRBulletedList)(FS_LPVOID clientData, FS_DWORD nBullet);
	/* @CALLBACKEND */
}FR_FormatToolCallbacksRec, *FR_FormatToolCallbacks;
/* @CALLBACKGROUPEND */
/* @OBJEND */

/* @OBJSTART FR_PropertyTools */
#ifndef FR_PROPERTYTOOLS
#define FR_PROPERTYTOOLS
/**
 * @brief The property tools is used to set line color and opacity of the PDF object in classic mode.
 */
typedef struct _t_FR_PropertyTools* FR_PropertyTools;
#endif

/* @CALLBACKGROUPSTART FR_PropertyToolCallbacks */
/**
* @brief The callback set for property tool.
 */
/** @deprecated Internal use.*/
typedef struct _fr_propertytool_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_PropertyToolCallbacksRec</a>). */
    unsigned long	lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRPropertyToolOnColorChanged */
    /**
     * @brief It is called by Foxit Reader when the color setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] color			The color value.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRPropertyToolOnColorChanged)(FS_LPVOID clientData, FS_COLORREF color);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPropertyToolOnOpacityChanged */
    /**
     * @brief It is called by Foxit Reader when the opacity setting is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nOpacity		The opacity value.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRPropertyToolOnOpacityChanged)(FS_LPVOID clientData, FS_INT32 nOpacity);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPropertyToolOnBeginScroll */
    /**
     * @brief It is called by Foxit Reader when beginning scrolling.
     *
     * @param[in] clientData	The user-supplied data.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRPropertyToolOnBeginScroll)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPropertyToolOnEndScroll */
    /**
     * @brief It is called by Foxit Reader when ending scrolling.
     *
     * @param[in] clientData	The user-supplied data.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRPropertyToolOnEndScroll)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPropertyToolOnOpacityScroll */
    /**
     * @brief It is called by Foxit Reader when the opacity setting is scrolling.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nOpacity		The opacity value.
     * @return void
     * @note
     * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPropertyToolOnOpacityScroll)(FS_LPVOID clientData, FS_INT32 nOpacity);
    /* @CALLBACKEND */

}FR_PropertyToolCallbacksRec, *FR_PropertyToolCallbacks;
/* @CALLBACKGROUPEND */
/* @OBJEND */

/* @OBJSTART FR_FuncBtn */
#ifndef FR_FUNCBTN
#define FR_FUNCBTN
/**
 * @brief The plug-in can add a button to the left navigation panel bar.
 */
typedef struct _t_FR_FuncBtn* FR_FuncBtn;
#endif
/* @OBJEND */

/* @OBJSTART FR_RibbonHandler */
#ifndef FR_RIBBONHANDLER
#define FR_RIBBONHANDLER
/**
 * @brief The ribbon handler.
 */
typedef struct _t_FR_RibbonHandler* FR_RibbonHandler;
#endif

/* @CALLBACKGROUPSTART FR_RibbonHandlerCallbacks */
/** @brief */
/* @Deprecated: Internal use.*/
typedef struct _fr_RibbonHandler_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_ConvertTaggedPDFCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOLEAN(*FRRibbonOnGetName)(FS_LPVOID clientData, FS_UINT nCmdId, FS_ByteString* csName);
	//通过ID获取Button的Title
	FS_BOOLEAN(*FRRibbonOnGetTitle)(FS_LPVOID clientData, FS_UINT nCmdId, FS_ByteString* csTitle);
	//通过ID获取Button的Tooltip
	FS_BOOLEAN(*FRRibbonOnGetTooltip)(FS_LPVOID clientData, FS_UINT nCmdId, FS_WideString* csTooltip);
	//通过ID获取Button的Description
	FS_BOOLEAN(*FRRibbonOnGetDescription)(FS_LPVOID clientData, FS_UINT nCmdId, FS_WideString* csDescription);
	//通过ID获取图像列表，Button可以从图像列表中获取对应的图标
	FS_BOOLEAN(*FRRibbonOnGetIconList)(FS_LPVOID clientData, HBITMAP& hSmallImageList);
	//通过ID获取Button的图标
	FS_BOOLEAN(*FRRibbonOnGetIcon)(FS_LPVOID clientData, FS_UINT nCmdId, FS_DIBitmap* pLargeImage, FS_DIBitmap* pSmallImage);
	//通过ID响应对应的Button执行ON_COMMAND
	FS_BOOLEAN(*FRRibbonOnCommand)(FS_LPVOID clientData, FS_UINT nCmdId);
	//通过ID响应
	FS_BOOLEAN(*FRRibbonOnUpdateCmdUI)(FS_LPVOID clientData, FS_UINT nCmdId, FS_LPVOID pCmdUI);
	//多语言处理，将Button根据条件设置多语言
	void(*FRRibbonOnChangeLanguage)(FS_LPVOID clientData);
	//释放Handler
	void(*FRRibbonOnRelease)(FS_LPVOID clientData);
}FR_RibbonHandlerCallbacksRec, *FR_RibbonHandlerCallbacks;
/* @CALLBACKGROUPEND */
/* @OBJEND */

typedef void(*FRFuncOnColorChange)(FS_ARGB fillColor, FS_ARGB borderColor, FS_LPVOID clientData);
typedef void(*FRFuncOnColorChange2)(FS_ARGB fillColor, FS_ARGB borderColor, FS_INT32 nIndex, FS_LPVOID clientData);

typedef void(*FRFuncOnFloatBtnClicked)(FS_LPCSTR sBtnName, FS_LPVOID clientData);
typedef void(*FRFuncDestroyClientData)(FS_LPVOID clientData);

typedef struct _fr_FloatyBtnFunc_
{
	void* clientData = nullptr;
	FRFuncOnFloatBtnClicked funcClicked = nullptr;
	FRFuncDestroyClientData funcDestroy = nullptr;
}FR_FloatyBtnFunc;

enum FR_FLOATBAR_SIDE
{
	FR_FLOATBAR_SIDE_NONE = 0,
	FR_FLOATBAR_SIDE_LEFT,
	FR_FLOATBAR_SIDE_RIGHT
};

#ifdef __cplusplus
};
#endif


#endif
/*@}*/ 


/*@}*/ 

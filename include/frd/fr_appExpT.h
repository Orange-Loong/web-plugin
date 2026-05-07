/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.	

*********************************************************************/


#ifndef FR_APPEXPT_H
#define FR_APPEXPT_H

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif



#ifndef FR_DOCEXPT_H
#include "fr_docExpT.h"
#endif

#ifndef FR_VIEWEXPT_H
#include "fr_viewExpT.h"
#endif

#ifndef FR_BAREXPT_H
#include "fr_barExpT.h"
#endif

#ifndef FR_MENUEXPT_H
#include "fr_menuExpT.h"
#endif


#ifndef FPD_DOCEXPT_H
#include "../pdf/fpd_docExpT.h"
#endif

#ifndef FPD_RENDEREXPT_H
#include "../pdf/fpd_renderExpT.h"
#endif

#ifndef FR_SYSEXPT_H
#include "../frd/fr_sysExpT.h"
#endif

#ifndef FPD_FEDITEXPT_H
#include "../pdf/fpd_editExpt.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/* @OBJSTART FR_Tool */
#ifndef FR_TOOL
#define FR_TOOL
	/**
	* @brief A <a>FR_Tool</a> is an object that can handle key presses and mouse events in the region of a document view.
	*
	* Tools do not handle mouse events in other parts of Foxit Reader window, such as navigation pane. At any time,
	* there is only one active tool, which a plug-in can set using <a>FRAppSetActiveTool</a>(). <br>
	* Reader has some built-in tools, such as Hand tool, Zoom tool, Link tool. You can get other built-in tools using
	* <a>FRAppGetToolByName</a>() with the tool's name defined in the <a>BuildInToolName</a> group.<br>
	* Use <a>FRAppRegisterTool</a>() to add a new tool to Foxit Reader.
	*/

	typedef struct _t_FR_Tool* FR_Tool;
#endif

	struct FS_ACCEL
	{
		FS_BOOL		   m_bCtrl;
		FS_BOOL		   m_bShift;
		FS_BOOL		   m_bAlt;
		FS_CHAR		   m_cAccelKey;
	};

/* @ENUMSTART */
/** @brief Annot event type. See <a>FRDocOnAnnotRelease</a>.*/
enum FRAnnotEventType
{
	FR_DocClose_TYPE,
	FR_DocOpen_TYPE,
	FR_OPER_TYPE
};
/* @ENUMEND */

/* @CALLBACKGROUPSTART FR_ToolCallbacks */
/**
 * @brief A callback set for <a>FR_Tool</a>. You can use the callback set to control a tool. It can also receive the message of event,
 * such as <a>FRToolOnKeyDown</a>, <a>FRToolOnLButtonDown</a> and so on. See <a>FRToolNew</a>.
 */
typedef struct _fr_tool_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ToolCallbacksRec</a>). */
    unsigned long	lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRToolOnInit */
    /**
     * @brief The initialization for <a>FR_Tool</a>.
     *
     * It is called when a tool starts to creat.
     *
     * @param[in] clientData	The user-supplied data.
     * @return  If <a>TRUE</a>, the tool will be created, if <a>FALSE</a>, the tool will be unloaded.
     * @note
     */
    FS_BOOL			(*FRToolOnInit)(FS_LPVOID clientData);
    /* @CALLBACKEND */


    /* @CALLBACKSTART FRToolDestroy */
    /**
     * @brief		A callback for  <a>FR_Tool</a>.
     *
     * It is called at shutdown time to allow the tool to free dynamic memory.
     *
     * @param[in] clientData	The user-supplied data.
     * @return		<a>TRUE</a> for success, otherwise <a>FALSE</a>.
     * @note
     */
    FS_BOOL         (*FRToolDestroy)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnActivate */
    /**
     * @brief					A callback for  <a>FR_Tool</a>.
     *
     * It is called when a tool has become the active tool.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] bPersistent	A flag indicates whether the tool should remain active.
     * @note
     */
    void			(*FRToolOnActivate)(FS_LPVOID clientData, FS_BOOL bPersistent);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnDeactivate */
    /**
     * @brief					A callback for  <a>FR_Tool</a>.
     *
     * It is called when the tool no longer to be active tool.
     *
     * @param[in] clientData	The user-supplied data.
     * @note
     */
    void			(*FRToolOnDeactivate)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnKeyDown */
    /**
     * @brief				A callback for <a>FR_Tool</a>.
     *
     * It is called when user presses a non-system key.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nKeyCode	Specifies the virtual-key code of the given key.
     * @param[in] nFlags	Specifies the scan code, key-transition code, previous key state, and context code.
     * @return				<a>TRUE</a> to halt further processing, or <a>FALSE</a> to continue.
     * @note
     */
    FS_BOOL			(*FRToolOnKeyDown)(FS_LPVOID clientData, FS_UINT nKeyCode, FS_UINT nFlags);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnKeyUp */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It is called when user releases a non-system key.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nKeyCode	Specifies the virtual-key code of the given key.
     * @param[in] nFlags	Specifies the scan code, key-transition code, previous key state, and context code.
     * @return				<a>TRUE</a> to halt further processing, or <a>FALSE</a> to continue.
     * @note
     */
    FS_BOOL			(*FRToolOnKeyUp)(FS_LPVOID clientData, FS_UINT nKeyCode, FS_UINT nFlags);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnChar */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It is called when a keystroke translates to a non-system character. This method is
     * called before the <a>FRToolOnKeyUp</a> method and after the <a>FRToolOnKeyDown</a> method are called.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nChar		Specifies the char code of the given key.
     * @param[in] nFlags	Specifies the scan code, key-transition code, previous key state, and context code.
     * @return				<a>TRUE</a> to halt further processing, or <a>FALSE</a> to continue.
     * @note
     */
    FS_BOOL			(*FRToolOnChar)(FS_LPVOID clientData, FS_UINT nChar, FS_UINT nFlags);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnLeavePage */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It called when a tool leave a page view.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageview	The page view.
     * @return void
     * @note
     */
    void				(*FRToolOnLeavePage)(FS_LPVOID clientData, FR_PageView pageview);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolIsEnabled */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * Tests whether a tool is enable.
     *
     * @param[in] clientData	The user-supplied data.
     * @return				<a>TRUE</a> means the tool is enable, otherwise not.
     * @note
     */
    FS_BOOL				(*FRToolIsEnabled)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnLButtonDown */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It is called when user presses left mouse button.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageview	The page view.
     * @param[in] nFlags	Indicates whether various virtual keys are down. This parameter can be any combination of the following values:
     *
     * <ul>
     * <li>-MK_CONTROL   Set if the <Italic>CTRL</Italic> key is down.</li>
     * <li>-MK_LBUTTON   Set if the left mouse button is down. </li>
     * <li>-MK_MBUTTON   Set if the middle mouse button is down. </li>
     * <li>-MK_RBUTTON   Set if the right mouse button is down. </li>
     * <li>-MK_SHIFT	 Set if the <Italic>SHIFT</Italic> key is down. </li>
     * </ul>
     *
     * @param[in] point		Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return				<a>TRUE</a> to halt further processing, or <a>FALSE</a> to continue.
     * @note
     */
    FS_BOOL				(*FRToolOnLButtonDown)(FS_LPVOID clientData, FR_PageView pageview, FS_UINT nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnLButtonUp */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It is called when user releases left mouse button.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageview	The page view.
     * @param[in] nFlags	See <a>FRToolOnLButtonDown</a>().
     * @param[in] point		See <a>FRToolOnLButtonDown</a>().
     * @return				<a>TRUE</a> to halt further processing, or <a>FALSE</a> to continue.
     * @note
     */
    FS_BOOL				(*FRToolOnLButtonUp)(FS_LPVOID clientData, FR_PageView pageview, FS_UINT nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnLButtonDblClk */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It is called when user double-clicks the left mouse button.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageview	The page view.
     * @param[in] nFlags	See <a>FRToolOnLButtonDown</a>().
     * @param[in] point		See <a>FRToolOnLButtonDown</a>().
     * @return				<a>TRUE</a> to halt further processing, or <a>FALSE</a> to continue.
     * @note
     */
    FS_BOOL				(*FRToolOnLButtonDblClk)(FS_LPVOID clientData, FR_PageView pageview, FS_UINT nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnMouseMove */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It is called when the mouse cursor or stylus moves.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageview	The page view.
     * @param[in] nFlags	See <a>FRToolOnLButtonDown</a>().
     * @param[in] point		See <a>FRToolOnLButtonDown</a>().
     * @return				<a>TRUE</a> to halt further processing, or <a>FALSE</a> to continue.
     * @note
     */
    FS_BOOL				(*FRToolOnMouseMove)(FS_LPVOID clientData, FR_PageView pageview, FS_UINT nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnRButtonDown */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It is called when user presses right mouse button.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageview	The page view.
     * @param[in] nFlags	See <a>FRToolOnLButtonDown</a>().
     * @param[in] point		See <a>FRToolOnLButtonDown</a>().
     * @return				<a>TRUE</a> to halt further processing, or <a>FALSE</a> to continue.
     * @note
     */
    FS_BOOL				(*FRToolOnRButtonDown)(FS_LPVOID clientData, FR_PageView pageview, FS_UINT nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnRButtonUp */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It is called when user releases right mouse button.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageview	The page view.
     * @param[in] nFlags	See <a>FRToolOnLButtonDown</a>().
     * @param[in] point		See <a>FRToolOnLButtonDown</a>().
     * @return				<a>TRUE</a> to halt further processing, or <a>FALSE</a> to continue.
     * @note
     */
    FS_BOOL				(*FRToolOnRButtonUp)(FS_LPVOID clientData, FR_PageView pageview, FS_UINT nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnRButtonDblClk */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It is called when user double-clicks the right mouse button.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageview	The page view.
     * @param[in] nFlags	See <a>FRToolOnLButtonDown</a>().
     * @param[in] point		See <a>FRToolOnLButtonDown</a>().
     * @return				<a>TRUE</a> to halt further processing, or <a>FALSE</a> to continue.
     * @note This callback function is deprecated.
	 * @deprecated: Internal use.
     */
    FS_BOOL				(*FRToolOnRButtonDblClk)(FS_LPVOID clientData, FR_PageView pageview, FS_UINT nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnMouseWheel */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It is called when a user rotates the mouse wheel and encounters the wheel's next notch.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageview	The page view.
     * @param[in] nFlags	See <a>FRToolOnLButtonDown</a>().
     * @param[in] zDelta	Indicates distance rotated.
     * @param[in] point		See <a>FRToolOnLButtonDown</a>().
     * @return				<a>TRUE</a> if mouse wheel scrolling is enabled; otherwise <a>FALSE</a>.
     * @note
     */
    FS_BOOL				(*FRToolOnMouseWheel)(FS_LPVOID clientData, FR_PageView pageview, FS_UINT nFlags, FS_SHORT zDelta, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnDraw */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It's called when the page view is drew. Plug-in can draw its own content at this time.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] winPort		The platform-depend things.
     * @param[in] dwFlags		The reserve flag, will be ignore.
     * @return    <a>TRUE</a> means successful, otherwise not.
     * @note If <a>FRToolOnDraw</a> return FALSE, it will invoke FRToolOnDraw1

     */
    FS_BOOL				(*FRToolOnDraw)(FS_LPVOID clientData, FR_WinPort winPort, FS_DWORD dwFlags);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolIsProcessing */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * Tests whether a tool is processing.
     *
     * @param[in] clientData	The user-supplied.
     * @return				<a>TRUE</a> means the tool is processing, otherwise not.
     * @note
     */
    FS_BOOL				(*FRToolIsProcessing)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolOnMouseHover */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It is called when the cursor of the tool hovers over the client area of the window for the period of time.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageview	The page view.
     * @param[in] point		See <a>FRToolOnLButtonDown</a>().
     * @return <a>TRUE</a> if you process this event successfully, otherwise not.
     * @note It is invoked when current tool is Hand Tool
     * @deprecated Internal use.
     */
    FS_BOOL				(*FRToolOnMouseHover)(FS_LPVOID clientData, FR_PageView pageview, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRToolIsWndCapturing */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * Determines whether continue to set the mouse capture to the PDF preview window after ButtonUp.
     *
     * @param[in] clientData	The user-supplied.
     * @return <a>TRUE</a> if you need continue to set the mouse capture to the PDF preview window after ButtonUp.
     * @note
     */
    FS_BOOL				(*FRToolIsWndCapturing)(FS_LPVOID clientData);
    /* @CALLBACKEND */
	
	/* @CALLBACKSTART FRToolOnDraw1 */
    /**
     * @brief				A callback for  <a>FR_Tool</a>.
     *
     * It's called when the page view is drew. Plug-in can draw its own content at this time.
     *
    * @param[in] clientData	The user-supplied data.
    * @param[in] docview		The document view.
    * @param[in] winPort		The platform-depend things.
    * @param[in] device 		Render device.
    * @param[in] dwFlags		The reserve flag, will be ignore.
    * @return    <a>TRUE</a> means successful, otherwise not.
    * @note If <a>FRToolOnDraw</a> return TRUE, it will not invoke FRToolOnDraw1
    */
    FS_BOOL(*FRToolOnDraw1)(FS_LPVOID clientData, FR_DocView docview, FR_WinPort winPort, FPD_RenderDevice device, FS_DWORD dwFlags);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRToolOnEscape */
	/**
	 * @brief				A callback for  <a>FR_Tool</a>.
	 *
	 * It's called when press esc key.
	 *
	* @param[in] clientData	The user-supplied data.	
	* @return   void
	* @note 
	*/
    void(*FRToolOnEscape)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRToolOnInkPressure */
	/**
	 * @brief				A callback for  <a>FR_Tool</a>.
	 * @Deprecated: Internal use. 
	 *
	 * It's called when the page view on ink pressure.
	 *
	* @param[in] clientData	The user-supplied data.
	* @param[in] pageView	The page view.
	* @param[in] point		The point of ink pressure.
	* @param[in] pressure 	The pressure of INKEVENTPACKET parm.
	* @param[in] nFlag		The flag of INKEVENTPACKET parm.
	* @param[in] bErase		The erase flag of INKEVENTPACKET parm.
	* @return    <a>TRUE</a> means successful, otherwise not.
	* @note 
	*/
	FS_BOOLEAN(*FRToolOnInkPressure)(FS_LPVOID clientData, FR_PageView pageView, FS_DevicePoint point, FS_INT32 pressure, FS_INT32 nFlag, FS_BOOL bErase);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRToolOnInkNoPressure */
	/**
	 * @brief				A callback for  <a>FR_Tool</a>.
	 * @Deprecated: Internal use.
	 *
	 * It's called when the page view no ink pressure.
	 *
	* @param[in] clientData	The user-supplied data.
	* @param[in] pageView	The page view.
	* @param[in] nFlags	    The flag of INKEVENTPACKET parm.
	* @param[in] point		The point of ink pressure.	
	* @param[in] bErase		The erase flag of INKEVENTPACKET parm.
	* @param[in] btnState   The btn state.
	* @return    <a>TRUE</a> means successful, otherwise not.
	* @note
	*/
	FS_BOOLEAN(*FRToolOnInkNoPressure)(FS_LPVOID clientData, FR_PageView pPageView, FS_UINT nFlags, const FS_DevicePoint point, FS_BOOL bErase, FS_INT32 btnState);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRToolOnCursorInRange */
	/**
	 * @brief				A callback for  <a>FR_Tool</a>.
	 * @Deprecated: Internal use.
	 *
	 * It's called when cursor in range.
	 *
	* @param[in] clientData	The user-supplied data.	
	* @param[in] bErase		The erase flag of INKEVENTPACKET parm.
	* @return    void
	* @note
	*/
	void(*FRToolOnCursorInRange)(FS_LPVOID clientData, FS_BOOL bErase);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRToolOnCursorOutOfRange */
	/**
	 * @brief				A callback for  <a>FR_Tool</a>.
	 * @Deprecated: Internal use.
	 *
	 * It's called when cursor out of range.
	 *
	* @param[in] clientData	The user-supplied data.
	* @return    void
	* @note
	*/
	void(*FRToolOnCursorOutOfRange)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRToolOnIsPSIProcessing */
	/**
	 * @brief				A callback for  <a>FR_Tool</a>.
	 * @Deprecated: Internal use.
	 *
	 * It's called when cursor in range.
	 *
	* @param[in] clientData	The user-supplied data.
	* @return    FS_BOOLEAN
	* @note
	*/
	FS_BOOLEAN(*FRToolOnIsPSIProcessing)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRToolOnIsNeedPSIMessage */
	/**
	 * @brief				A callback for  <a>FR_Tool</a>.
	 * @Deprecated: Internal use.
	 *
	 * It's called when cursor in range.
	 *
	* @param[in] clientData	The user-supplied data.
	* @return    FS_BOOLEAN
	* @note
	*/
	FS_BOOLEAN(*FRToolOnIsNeedPSIMessage)(FS_LPVOID clientData);
	/* @CALLBACKEND */

}FR_ToolCallbacksRec, *FR_ToolCallbacks;
/* @CALLBACKGROUPEND */

/* @DEFGROUPSTART BuildInToolName */
/**
* @brief Definitions for tool name.
*/

/*@{*/
/** @brief Hand Tool*/
#define FR_NAME_HAND						"Hand"	

/** @brief The name of Select Text Tool */
#define FR_NAME_SELECTTEXT					"Select Text"  

/** @brief The name of Find Text Tool */
#define FR_NAME_FINDTEXT					"Find Text Tool"  

/** @brief The name of Snapshot Tool */ 
#define FR_NAME_SNAPSHOT					"Snapshot Tool"  

/** @brief The name of Annot Tool */
#define FR_NAME_ANNOT						"Annot"  

/** @brief The name of Rectangle Link Tool */   
#define FR_NAME_RECTANGLELINK				"Rectangle Link Tool"

/** @brief The name of Quadrilateral Link Tool */ 
#define FR_NAME_QUADRILATERALLINK			"Quadrilateral Link Tool"

/** @brief The name of Arrow Tool */
#define FR_NAME_ARROW						"Arrow" 

/** @brief The name of Line Tool */
#define FR_NAME_LINE						"Line"  

/** @brief The name of Dimension Tool */
#define FR_NAME_DIMENSION					"Dimension Tool"  
  
/** @brief The name of Square Tool */     
#define FR_NAME_SQUARE						"Square Tool"  

/** @brief The name of Rectangle Tool */
#define FR_NAME_RECTANGLE					"Rectangle"  

/** @brief The name of Circle Tool */  
#define FR_NAME_CIRCLE						"Circle Tool"  

/** @brief The name of Ellipse Tool */
#define FR_NAME_ELLIPSE					"Ellipse"  

/** @brief The name of Polygon Tool */
#define FR_NAME_POLYGON					"Polygon"

/** @brief The name of Cloudy Tool */
#define FR_NAME_CLOUDY						"Cloudy"  

/** @brief The name of Polyline Tool */  
#define FR_NAME_POLYLINE					"Polyline Tool"   

/** @brief The name of Pencil Tool */
#define FR_NAME_PENCIL						"Pencil" 

/** @brief The name of Rubber Tool */
#define FR_NAME_RUBBER						"Rubber Tool"

/** @brief The name of Edit Selected Text */  
#define FR_NAME_EDITSELECT					"Edit Selected Text" 

/** @brief The name of Highlight Tool */  
#define FR_NAME_HIGHLIGHT					"Highlight Tool"

/** @brief The name of Underline Tool */  
#define FR_NAME_UNDERLINE					"Underline Tool" 

/** @brief The name of Strikeout Tool */     
#define FR_NAME_STRIKEOUT					"Strikeout Tool" 

/** @brief The name of Squiggly Tool */      
#define FR_NAME_SQUIGGLY					"Squiggly Tool"

/** @brief The name of Replace Tool */    
#define FR_NAME_REPLACE					"Replace Tool"

/** @brief The name of Insert Text Tool */ 
#define FR_NAME_CARET						"Insert Text Tool"

/** @brief The name of Note Tool */ 
#define FR_NAME_NOTE						"Note Tool" 
 
/** @brief The name of Push Button Tool */ 
#define FR_NAME_PUSHBUTTON					"Push Button Tool"

/** @brief The name of Check Box Tool */ 
#define FR_NAME_CHECKBOX					"Check Box Tool" 
  
/** @brief The name of Radio Button Tool */ 
#define FR_NAME_RADIOBUTTON				"Radio Button Tool" 

/** @brief The name of Combo Box Tool */     
#define FR_NAME_COMBOBOX					"Combo Box Tool"

/** @brief The name of List Box Tool */  
#define FR_NAME_LISTBOX					"List Box Tool" 

/** @brief The name of Text Field Tool */  
#define FR_NAME_TEXTFIELD					"Text Field Tool"  

/** @brief The name of Distance Tool */ 
#define FR_NAME_DISTANCE					"Distance Tool" 

/** @brief The name of Perimeter Tool */      
#define FR_NAME_PERIMETER					"Perimeter Tool"

/** @brief The name of Area Tool */  
#define FR_NAME_AREA						"Area Tool"    

/** @brief The name of Image Tool */ 
#define FR_NAME_SCREEN						"Image Tool"  

/** @brief The name of FileAttachment Tool */ 
#define FR_NAME_FAA_TOOLNAME				"FileAttachment Tool"

/** @brief The name of Attach a file */ 
#define FR_NAME_DFA_TOOLNAME				"Attach a file"

/** @brief The name of Loupe Tool */ 
#define FR_NAME_LOUPETOOL					"Loupe Tool"

/** @brief The name of Magnifier */ 
#define FR_NAME_MANGIFIER					"Magnifier"

/** @brief The name of Typewriter */ 
#define FR_NAME_TYPEWRITER					"Typewriter"

/** @brief The name of Textbox */ 		
#define FR_NAME_TEXTBOX					"Textbox"  

/** @brief The name of Callout */ 
#define FR_NAME_CALLOUT					"Callout" 
 
/** @brief The name of Sound Tool */ 
#define FR_NAME_SOUND						"Sound Tool"

/** @brief The name of Movie Tool */ 
#define FR_NAME_MOVIE						"Movie Tool"

/** @brief The name of advance search tool */ 
#define FR_NAME_ADVANCEDSEARCHPAGE		"Search"

/** @brief The name of stamp tool */ 
#define FR_NAME_STAMP						"Stamp"

/** @brief The name of add dot */
#define FR_NAME_TYPEDOT				    "Add Dot"  

/** @brief The name of add check mark */
#define FR_NAME_TYPECHECK				"Add Check Mark"

/** @brief The name of add X */
#define FR_NAME_TYPEX 					"Add X"

/** @brief The name of add line */
#define FR_NAME_TYPELINE				"Add Line"

/** @brief The name of add rounded rectangle */
#define FR_NAME_TYPERECT				"Add Rounded Rectangle"

/** @brief The name of add text */
#define FR_NAME_ADDTEXT				    "Add Text"  

/*@}*/
/* @DEFGROUPEND */
/* @OBJEND */


/* @OBJSTART FR_App */
/**
 * @brief <a>FR_App</a> represents the Foxit Reader application itself. 
 *
 * From the application layer, you can control the appearance of Foxit Reader, whether Reader appears, and the size of the application window. 
 * Your application has access to the menu bar and the toolbar through this object. The application layer also provides access to the visual 
 * representation of a PDF file on the screen (an <a>FR_Document</a>).
 *
 */

/* @ENUMSTART */
/** @brief ECM Save type. See <a>FRAppFileDialogECMSaveProc</a>.*/
/** @deprecated Internal use.*/
enum FRDECMFileDialogType
{
	FR_ECMFileDialog_Open_Default = 0, 		/** Default Open */
	FR_ECMFileDialog_Open_GetFileOnly,		/** Open and Only Get File */
	FR_ECMFileDialog_Save_Default,			/** Default Save */
	FR_ECMFileDialog_Save_Export,			/** Export */
	FR_ECMFileDialog_Open_Save				/** Open and Save */
};
/* @ENUMEND */

/* @STRUCTSTART */
/** @brief ECM open info type. See <a>FRAppFileDialogECMOpenProc</a>.*/
/** @deprecated Internal use.*/
struct FRDECMFileDialogFileData
{
	FS_WideString wsFileList = NULL;
	FS_WideString accountName = NULL;
};
/* @STRUCTEND */

/* @CALLBACKSTART FRAppUndoRedoExitEditProc */
/**
 * @brief The callback will be invoked when you exit the editing mode. Then you can release the data.
 * @param[in] clientData	The client data passed through <a>FRAppUndoRedoBeginEdit</a>
 * @return void
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppUndoRedoBeginEdit
 */
typedef void (*FRAppUndoRedoExitEditProc)(void *clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRAppCustomRecentFileExecuteProc */
/**
* @brief When the custom recent file item is clicked, the callback will be invoked. If it is not set, the default open process will be invoked. 
 * @param[in] lpwsFile		The file path of the custom recent file item.
 * @param[in] clientData	The client data passed through <a>FRAppAddFileToCustomRecentFileList</a>
 * @return <a>TRUE</a> if you handle the open process successfully in the callback, otherwise not.
 * @note
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppAddFileToCustomRecentFileList
 * @deprecated Internal use.
 */
typedef FS_BOOL (*FRAppCustomRecentFileExecuteProc)(FS_LPCWSTR lpwsFile, void *clientData);
/* @CALLBACKEND */


/* @CALLBACKSTART FRAppFileDialogECMOpenProc */
/**
* @brief When the filedialog ECM item selected, the callback will be invoked.
* @param[in] type				The specified file dialog type.
* @param[in] bAllowMultiSelect	Check if allaw muli-selected in file dialog.
* @param[in] lpwsPluginName		The plugin name.
* @param[in] lpwsPluginHftName	The plugin HFT name.
* @param[in] lpwsFilter			A buffer containing pairs of null-terminated filter strings.
* @param[in] nFilterIndex		The index of the currently selected filter in the File Types control.
* @param[in] clientData			The client data passed through <a>FRAppAddECMFileDialog</a>
* @param[out] lpwsFilePaths		The files selected by the ECM plugin, with "|" as the boundary between the files.
* @return <a>TRUE</a> if you handle the filedialog process successfully in the callback, otherwise not.
* @note
* @since   
* @see FRAppAddECMFileDialog
* @deprecated Internal use.
*/
typedef FS_BOOL(*FRAppFileDialogECMOpenProc)(FRDECMFileDialogType type, FS_BOOL bAllowMultiSelect, FS_LPCWSTR lpwsPluginName, FS_LPCWSTR lpwsPluginHftName, FS_LPCWSTR lpwsFilter, FS_INT32 nFilterIndex, void* clientData, FS_LPCWSTR& lpwsFilePaths);
/* @CALLBACKEND */

/* @CALLBACKSTART FRAppFileDialogECMSaveProc */
/**
* @brief When the filedialog ECM item selected, the callback will be invoked.
* @param[in] lpwsSrcFilePath	The source file path.
* @param[in] lpwsPluginName	The plugin name
* @param[in] lpwsPluginHftName	The plugin HFT name
* @param[in] type				The specified file dialog type.
* @param[in] lpwsFilter			A buffer containing pairs of null-terminated filter strings.
* @param[in] nFilterIndex		The index of the currently selected filter in the File Types control.
* @param[in] bViewExportResult	<a>TRUE</a>Open the export result. Only for the case where <FRDECMFileDialogType> is FR_ECMFileDialog_Save_Export.
* @param[in] clientData	The client data passed through <a>FRAppAddECMFileDialog</a>
* @return <a>TRUE</a> if you handle the filedialog process successfully in the callback, otherwise not.
* @note
* @since
* @see FRAppAddECMFileDialog
* @deprecated Internal use.
*/
typedef FS_BOOL(*FRAppFileDialogECMSaveProc)(FS_LPCWSTR lpwsSrcFilePath, FS_LPCWSTR lpwsPluginName, FS_LPCWSTR lpwsPluginHftName, FRDECMFileDialogType type, FS_LPCWSTR lpwsFilter, FS_INT32 nFilterIndex, FS_BOOL bViewExportResult, void* clientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRAppFileDialogECMUploadProc */
/**
* @brief When the ECM item can upload, the callback will be invoked. It must be delete wsSrcFilePath file.
* @param[in] wsSrcFilePath	The source file path.
* @param[in] wsNewFilePath	The new file path.
* @param[in] wsPluginName	The plugin name
* @param[in] wsPluginHftName	The plugin HFT name
* @param[in] type			The specified file dialog type.
* @param[in] bUpload		<a>TRUE</a> upload file to ECM, otherwise not.
* @param[in] pClientData	The client data passed through <a>FRAppAddECMFileDialog</a>
* @return <a>TRUE</a> if you handle the filedialog process successfully in the callback, otherwise not.
* @note
* @since
* @see FRAppAddECMFileDialog
* @deprecated Internal use.
*/
typedef FS_BOOL(*FRAppFileDialogECMUploadProc)(FS_LPCWSTR wsSrcFilePath, FS_LPCWSTR wsNewFilePath, FS_LPCWSTR wsPluginName, FS_LPCWSTR wsPluginHftName, FRDECMFileDialogType type, FS_BOOL bUpload, void* pClientData);
/* @CALLBACKEND */


/* @CALLBACKSTART FRAppFileDialogECMOpenProc2 */
/**
* @brief When the filedialog ECM item selected, the callback will be invoked.
* @param[in] type				The specified file dialog type.
* @param[in] bAllowMultiSelect	Check if allow mulit-selection.
* @param[in] lpwsPluginName		The plugin name.
* @param[in] lpwsPluginHftName	The plugin HFT name.
* @param[in] lpwsFilter			A buffer containing pairs of null-terminated filter strings.
* @param[in] nFilterIndex		The index of the currently selected filter in the File Types control.
* @param[in] clientData			The client data passed through <a>FRAppAddECMFileDialog</a>
* @param[out] lpwsFilePaths		The files selected by the ECM plugin, with "|" as the boundary between the files.
* @return <a>TRUE</a> if you handle the filedialog process successfully in the callback, otherwise not.
* @note
* @since
* @see FRAppAddECMFileDialog
* @deprecated Internal use.
*/
typedef FS_BOOL(*FRAppFileDialogECMOpenProc2)(FRDECMFileDialogType type, FS_BOOL bAllowMultiSelect, FS_LPCWSTR lpwsPluginName, FS_LPCWSTR lpwsPluginHftName, FS_LPCWSTR lpwsFilter, FS_INT32 nFilterIndex, void* clientData, FS_WideString* lpwsFilePaths);
/* @CALLBACKEND */


/* @CALLBACKSTART FRAppFileDialogECMOpenProc3 */
/**
* @brief When the filedialog ECM item selected, the callback will be invoked.
* @param[in] type				The specified file dialog type.
* @param[in] bAllowMultiSelect	Check if allow mulit-selection.
* @param[in] lpwsPluginName		The plugin name.
* @param[in] lpwsPluginHftName	The plugin HFT name.
* @param[in] lpwsFilter			A buffer containing pairs of null-terminated filter strings.
* @param[in] nFilterIndex		The index of the currently selected filter in the File Types control.
* @param[in] clientData			The client data passed through <a>FRAppAddECMFileDialog</a>
* @param[out] fileData		The files selected by the ECM plugin, with "|" as the boundary between the files.
* @return <a>TRUE</a> if you handle the filedialog process successfully in the callback, otherwise not.
* @note
* @since
* @see FRAppAddECMFileDialog
* @deprecated Internal use.
*/
typedef FS_BOOL(*FRAppFileDialogECMOpenProc3)(FRDECMFileDialogType type, FS_BOOL bAllowMultiSelect, FS_LPCWSTR lpwsPluginName, FS_LPCWSTR lpwsPluginHftName, FS_LPCWSTR lpwsFilter, FS_INT32 nFilterIndex, void* clientData, FRDECMFileDialogFileData* fileData);
/* @CALLBACKEND */

/* @CALLBACKGROUPSTART FR_CmdMsgEventCallbacks */

/**
 * @brief A callback set for application-level event handler. It is called by the <Italic>Foxit Reader</Italic> to 
 * route and dispatch command messages and to handle the update of command user-interface objects, such as menu, toolbar.
 * See <a>FRAppRegisterCmdMsgEventHandler</a>.
 */
typedef struct _fr_cmdmsgevent_callbacks_
{
    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_CmdMsgEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRCmdMsgOnCmdMsgByName */
	/**
     * @brief				A callback for application level event handler.
	 *
	 * It is called by the <Italic>Foxit Reader</Italic> to route and dispatch command messages and to handle the update of command user-interface objects, such as menu, toolbar.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] lpsName		The name of menu or toolbar whose command messages need to be routed and dispatched.
	 * @param[in] nCode			References to <Italic>MFC CCmdTarget::OnCmdMsg</Italic>.
	 * @param[in] pExtra		References to <Italic>MFC CCmdTarget::OnCmdMsg</Italic>.
	 * @param[in] pHandlerInfo	It represents the <Italic>MFC</Italic> struct <Italic>AFX_CMDHANDLERINFO</Italic>.
	 * @return Nonzero if the message is handled; otherwise 0.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRCmdMsgOnCmdMsgByName)(FS_LPVOID clientData, FS_LPCSTR lpsName, FS_INT32 nCode, void* pExtra, void* pHandlerInfo);
	/* @CALLBACKEND */

}FR_CmdMsgEventCallbacksRec, *FR_CmdMsgEventCallbacks;

/* @CALLBACKGROUPEND */


/* @CALLBACKGROUPSTART FR_AppEventCallbacks */

/**
 * @brief A callback set for application-level event handler. See <a>FRAppRegisterAppEventHandler</a>.
 */
typedef struct _fr_appevent_callbacks_
{
    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_AppEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	/* @CALLBACKSTART FRAppOnLangUIChange */
	/**
     * @brief				A callback for application level event handler.
	 *
	 * It is called whenever the user change the language.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @note This callback function is deprecated.
	 * @deprecated: Internal use.
     */
    void (*FRAppOnLangUIChange)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnActivate */
    /**
     * @brief					A callback for application level event handler.
     *
     * It is called whenever the application is to being activated or deactivated.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] bActive		Specifies whether the application is being activated or deactivated.
     * <a>TRUE</a> means the application is being activated. <a>FALSE</a> means the application is being deactivated.
     * @note It is only available in Windows
     */
    void (*FRAppOnActivate)(FS_LPVOID clientData, FS_BOOL bActive);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppWillQuit */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called at the shutdown time.
     *
     * @param[in] clientData	The user-supplied data.
     * @note
     */
    void (*FRAppWillQuit)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppWillQuit */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called when Foxit Reader needs to download the updated module.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] lpModuleName  The module name.
     * @note
     */
    void (*FRAppOnDownload)(FS_LPVOID clientData, FS_LPCSTR lpModuleName);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnToolChanged */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called when current active tool has been changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] deactiveTool  The deactivate tool.
     * @param[in] activeTool	The current active tool.
     * @note
     */
    void (*FRAppOnToolChanged)(FS_LPVOID clientData, FR_Tool deactiveTool, FR_Tool activeTool);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnSkinChange */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called when Foxit Reader changed the UI skin.
     *
     * @param[in] clientData	The user-supplied data.
     * @note This callback function is deprecated.
	 * @deprecated: Internal use.
     */
    void (*FRAppOnSkinChange)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnShowFullScreen */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called when Foxit Reader starts to show fullscreen mode.
     *
     * @param[in] clientData	The user-supplied data.
     * @note
     */
    void (*FRAppOnShowFullScreen)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnHideFullScreen */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called when Foxit Reader ends the fullscreen mode.
     *
     * @param[in] clientData	The user-supplied data.
     * @note
     */
    void (*FRAppOnHideFullScreen)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnResetToolbars */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called when Foxit Reader re-layout all toolbars.
     *
     * @param[in] clientData	The user-supplied data.
     * @note This callback function is deprecated.
	 * @deprecated: Internal use.
     */
    void (*FRAppOnResetToolbars)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnRunCommandLine */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called when Foxit Reader startups in command-line mode.
     *
     * @param[in] clientData	The user-supplied data.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     * @deprecated: Internal use.
     */
    void (*FRAppOnRunCommandLine)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnDrop */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called when the user drag a file to Foxit Reader and drop.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] lpszPath		The path of the file that is dragged.
     * @note It only available in Windows
     * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    void (*FRAppOnDrop)(FS_LPVOID clientData, FS_LPCWSTR lpszPath);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnTextViewChange */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called when Foxit Reader changes view mode.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] nViewType		The current display mode: 0 for preview 1 for text.
     * @note This callback function is deprecated. 
	 * @deprecated: Internal use.
     */
    void (*FRAppOnTextViewChange)(FS_LPVOID clientData, FS_INT32 nViewType);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnRecentFileListChange */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called by Foxit Reader when the recent file list changes.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] arrFileList	The recent file list.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRAppOnRecentFileListChange)(FS_LPVOID clientData, FS_WideStringArray arrFileList);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnShowRibbonFilePage */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called by Foxit Reader when the ribbon file page shows.
     *
     * @param[in] clientData	The user-supplied data.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRAppOnShowRibbonFilePage)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnCloseRibbonFilePage */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called by Foxit Reader when the ribbon file page is closed.
     *
     * @param[in] clientData	The user-supplied data.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRAppOnCloseRibbonFilePage)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnRibbonElementsLoadFinish */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called by Foxit Reader when the ribbon elements finish loading.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pParentWnd	A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRAppOnRibbonElementsLoadFinish)(FS_LPVOID clientData, void* pParentWnd);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnOpenDocument */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called by Foxit Reader when Foxit Reader is going to open a document. Returning TRUE means the plug-in will take over the process,
     * and the Foxit Reader will terminate the process, otherwise the Foxit Reader will continue the opening process.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] lpszFilePath	The file path to be opened.
     * @return TRUE means the plug-in will take over the process,
     * and the Foxit Reader will terminate the process, otherwise the Foxit Reader will continue the opening process.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    FS_BOOL (*FRAppOnOpenDocument)(FS_LPVOID clientData, FS_LPCWSTR lpszFilePath);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnRibbonCategoryClicked */
    /**
     * @brief	A callback for application level event handler.
     *
     * It is called by Foxit Reader when the ribbon category is clicked.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] bChanged		Whether the ribbon category is changed or not.
     * @return void.
     * @note Only available in Windows
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     * @deprecated: Internal use.
     */
    void (*FRAppOnRibbonCategoryClicked)(FS_LPVOID clientData, FS_BOOL bChanged);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnMainFrmLoadFinish */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called by Foxit Reader when the main frame finishes loading.
     *
     * @param[in] clientData	The user-supplied data.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 3.0
     */
    void (*FRAppOnMainFrmLoadFinish)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnRibbonUILayoutFinish */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called by Foxit Reader when the ribbon elements finish laying out.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pParentWnd	A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
     */
    void (*FRAppOnRibbonUILayoutFinish)(FS_LPVOID clientData, void* pParentWnd);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnShowTaskPane */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called by Foxit Reader when the task pane is being shown.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] bShow			Whether the task pane is to be shown or not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
     */
    void (*FRAppOnShowTaskPane)(FS_LPVOID clientData, FS_BOOL bShow);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnShowPopupMenu */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called by Foxit Reader when the pop-up menu is shown.
     *
     * @param[in] clientData	The user-supplied data.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
     */
    void (*FRAppOnShowPopupMenu)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnDidOpenAllFiles */
    /**
     * @brief				A callback for application level event handler.
     *
     * It is called by Foxit Reader when all the files have been opened.
     *
     * @param[in] clientData	The user-supplied data.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
     * @deprecated: Internal use.
     */
    void (*FRAppOnDidOpenAllFiles)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppOnMainFrameWillClose */
    /**
     * @brief A callback for application level event handler.
     *
     * It is called by Foxit Reader when the main frame is to be closed. Then the plug-in can determine whether the main frame can be closed or not.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[out] bCanClose	Determines whether the main frame can be closed or not.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
     */
    void (*FRAppOnMainFrameWillClose)(FS_LPVOID clientData, FS_BOOL* bCanClose);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRAppMainFrameOnSize */
    /**
     * @brief A callback for application level event handler.
     *
     * It is called by Foxit Reader when the main frame's size is changing.
     *
     * @param[in] clientData	The user-supplied data.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
     */
    void (*FRAppMainFrameOnSize)(FS_LPVOID clientData);
    /* @CALLBACKEND */
	
	/* @CALLBACKSTART FRAppMainFrameOnLoadWinPlacementFinish */
	/**
     * @brief A callback for application level event handler.
	 *
	 * It is called by Foxit Reader when the size and location of a window from the registry is loaded.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] hMainframe	A handle of the frame window.
	 * @return void.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
     */
    void (*FRAppMainFrameOnLoadWinPlacementFinish)(FS_LPVOID clientData, FS_HWND hMainframe);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppPluginOnLoaded */
	/**
     * @brief A callback for application level event handler.
	 *
	 * It is called by Foxit Reader when the plugin is loaded.
	 *
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] lpszPluginName	the plugin name.
	 * @return void.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
     */
	void (*FRAppPluginOnLoaded)(FS_LPVOID clientData, FS_LPCWSTR lpszPluginName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppOnDidCloseRibbonFilePage */
	/**
     * @brief				A callback for application level event handler.
	 *
	 * It is called by Foxit Reader when the ribbon file page had closed.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRAppOnDidCloseRibbonFilePage)(FS_LPVOID clientData);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRAppOnRibbonCategoryChanged */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by Foxit Reader when the ribbon category is changed.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] lpsCategoryName		The actived ribbon category name.
	 * @note Only available in Windows
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     * @deprecated: Internal use.
	 */
	void(*FRAppOnRibbonCategoryChanged)(FS_LPVOID clientData, FS_LPCSTR lpsCategoryName);

    /* @CALLBACKSTART FRAppWillConvertPDFtoOffice */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by ConvertPDFtoOffice is started.	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in]inPath - path to the converted pdf file
     * @param[in]outPath - path to the output file
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     * @deprecated: Internal use. The callback has been deprecated, suggest use FREXPORTSetWillConvertPDF of fxexport plugin.
	 */
	void(*FRAppWillConvertPDF)(FS_LPVOID clientData, FS_LPCWSTR inPath, FS_LPCWSTR outPath);

	/* @CALLBACKSTART FRAppDidConvertPDFtoOffice */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by ConvertPDFtoOffice is End.
	 *
	 * @param[in] clientData	The user-supplied data.
	  * @param[in]inPath - path to the converted pdf file
	 * @param[in]outPath - path to the output file
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     * @deprecated: Internal use. The callback has been deprecated, suggest use FREXPORTSetDidConvertPDF of fxexport plugin.
	 */
	void(*FRAppDidConvertPDF)(FS_LPVOID clientData,FS_LPCWSTR inPath, FS_LPCWSTR outPath);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWillSignatureDoc */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by signature doc is started.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pDocument - The current document
	 * @param[in] outPath - path to the output file
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     * @deprecated: Internal use.
	 */
	void(*FRWillSignatureDoc)(FS_LPVOID clientData, FR_Document pDocument, FS_LPCWSTR outPath);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDidSignatureDoc */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by signature doc is ended.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] outPath - path to the output file
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     * @deprecated: Internal use.
	 */
	void(*FRDidSignatureDoc)(FS_LPVOID clientData, FS_LPCWSTR outPath);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnAppWillCombineMultiFile */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by combine files is started.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] allneedfile - all combine file path
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     * @deprecated: Internal use.
	 */
	void(*FROnAppWillCombineMultiFile)(FS_LPVOID clientData, const FS_WideStringArray allneedfile);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnAppDidCombineMultiFile */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by combine files is ended.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] outfile - out file path after combine
	 * @param[in] usedfile - used file path to combine
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     * @deprecated: Internal use.
	 */
	void(*FROnAppDidCombineMultiFile)(FS_LPVOID clientData, FS_WideString outfile, const FS_WideStringArray usedfile);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnShowReadMode */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called when show read mode.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
	 * @deprecated: Internal use.
	 */
	void(*FROnShowReadMode)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnExitReadMode */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called when exit read mode.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
	 * @deprecated: Internal use.
	 */
	void(*FROnExitReadMode)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnExitReadMode */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called when main frame moved.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pFrame	    The CWnd object.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0	
	 */
	void(*FRMainFrameOnMove)(FS_LPVOID clientData, FS_LPVOID pFrame);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppOnRibbonCategoryBeforeChange */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by Foxit Reader when the ribbon category before change.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] lpsCategoryName		The actived ribbon category name.
	 * @note Only available in Windows
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
	 * @deprecated: Internal use.
	 */
	void(*FRAppOnRibbonCategoryBeforeChange)(FS_LPVOID clientData, FS_LPCSTR lpsCategoryName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPreModalCustomizeRibbonDlg */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called when customize Ribbon dialog showed.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
	 */
	void(*FRAppOnPreModalCustomizeRibbonDlg)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppOnUpdateRibbonByAccel */
	/**
	 * @brief				A callback for update ribbon by accel.
	 *
	 * It is called when update ribbon by accel.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] accel	        The accel info.
	 * @param[in] wsElementName	The element name.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
	 */
	FS_BOOL (*FRAppOnUpdateRibbonByAccel)(FS_LPVOID clientData, FS_ACCEL accel, FS_ByteString wsElementName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppOnUpdateRibbonUI */
	/**
	 * @brief				A callback for update ribbon ui.
	 *
	 * It is called when update ribbon ui.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] bsCategoryName  The input category name.
	  * @param[in] bsPanelName	  The input panel name.
	 * @param[in] bsElementName	  The element name.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
	 */
    FS_BOOL (*FRAppOnUpdateRibbonUI)(FS_LPVOID clientData, FS_LPCSTR bsCategoryName, FS_LPCSTR bsPanelName, FS_LPCSTR bsElementName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppPluginOnWillUnLoaded */
	/**
	* @brief A callback for application level event handler.
	*
	* It is called by Foxit Reader when the plugin is loaded.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] lpszPluginName	the plugin name.
	* @return void.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
	*/
	void(*FRAppPluginOnWillUnLoaded)(FS_LPVOID clientData, FS_LPCWSTR lpszPluginName);
	/* @CALLBACKEND */

	 /* @CALLBACKSTART FRAppOnUpdateActionRibbonUI */
	/**
	* @brief A callback for action event handler.
	*
	* It is called by Foxit Reader when the plugin is loaded.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] bsElementName	The element name.
	* @return void.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
	*/
	FS_BOOL(*FRAppOnUpdateActionRibbonUI)(FS_LPVOID clientData, FS_LPCSTR bsElementName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppDecryptFile */
	/**
	* @brief A callback for action event handler.
	*
	* It is called when add DRM file,it need decrypt the file first.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] pszInPath	    The DRM file path.
	* @param[out] pszOutPath	Get the decrypted file path.
	* @return FS_BOOL.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 12.1.0
	*/
	FS_BOOL(*FRAppOnDecryptFile)(FS_LPVOID clientData, FS_LPCWSTR pszInPath, FS_WideString* pszOutPath);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppDecryptFile */
	/**
	* @brief A callback for action event handler.
	*
	* It is called when need to delete the temp decrypted file path.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] pszPath	    The temp decrypted file path .
	* @return FS_BOOL.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 12.1.0
	*/
	FS_BOOL(*FRAppOnDeleteDecryptFile)(FS_LPVOID clientData, FS_LPCWSTR pszPath);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppOnShowRibbonFilePageFinish */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by Foxit Reader when the ribbon file page shows finish.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.2.0
	 */
	void(*FRAppOnShowRibbonFilePageFinish)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppOnRibbonCustomizeSync */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by Foxit Reader when the ribbon customize.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.2.0
	 */
	void(*FRAppOnRibbonCustomizeSync)(FS_LPVOID clientData, FS_BOOL bCustomXml);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppOnChangedTaskPane */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by Foxit Reader when the task panel was changed.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] bsName	    Changed the name of the task panel.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.2.0
	 */
	void(*FRAppOnChangedTaskPane)(FS_LPVOID clientData, FS_LPCSTR bsName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppOnMainFrameClosing */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by Foxit Reader when the mainfram be closed.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pFrame	    The CWnd* object.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.2.0
	 */
	void(*FRAppOnMainFrameClosing)(FS_LPVOID clientData, FS_LPVOID pFrame);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAppOnMainFrameClientOnSize */
	/**
	 * @brief				A callback for application level event handler.
	 *
	 * It is called by Foxit Reader when the mainfram be closed.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.2.0
	 */
	void(*FRAppOnMainFrameClientOnSize)(FS_LPVOID clientData);
	/* @CALLBACKEND */
}FR_AppEventCallbacksRec, *FR_AppEventCallbacks;

/* @CALLBACKGROUPEND */

/* @ENUMSTART */
/** @brief form operation event type. See <a>FRFormFieldChanged</a>.*/
enum FPD_FORMOPERATYPE
{
	FPDFORMADD,		/** When form added*/
	FPDFORMCHANGE,	/** When form changed*/
	FPDFORMDELETE	/** When form deleted*/
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief start page tab type.*/
enum FR_STARTPAGETABTYPE
{
	FRHOME = 0,			/** HOEM type*/
	FRSHARED,			/** SHARED type*/
	FRVIDEO_TUTORIALS 	/** VIDEO_TUTORIALS type*/
};
/* @ENUMEND */

typedef struct _fr_combine_data_
{
	_fr_combine_data_()
	{
		pathNames = NULL;
		documentNames = NULL;
		results = NULL;		
		outputPath = NULL;
		combineOptions = 0;
	}

	/** path name to files should be combined, the orders in arrays should be consistent */
	FS_WideStringArray pathNames;  

	/** the file name, will be used for bookmark name for the given file */
	FS_WideStringArray documentNames;    

	/** the array will be filled by result codes, 0 - success, or error code */
	FS_WordArray results; 	

	/** the destination file */
	FS_WideString outputPath;

	/** the combine option */
	FS_INT32 combineOptions;
}FR_CombineData;

/* @CALLBACKGROUPSTART FR_DocEventCallbacks */

/**
 * @brief A callback set for document-level event handler. See <a>FRAppRegisterDocHandlerOfPDDoc</a>.
 *
 */
typedef struct _fr_docevent_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DocEventCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;


    /* @CALLBACKSTART FRDocWillOpen */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called whenever a document is opening.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> object that is opening.
     * @note
     */
    void		(*FRDocWillOpen)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocDidOpen */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called whenever a document is opened completely.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> that is opened completely.
     * @note
     */
    void		(*FRDocDidOpen)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnActivate */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called whenever a document is to be active.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	The <a>FR_Document</a> that becomes an active document.
     * @note
     */
    void		(*FRDocOnActivate)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnDeactivate */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called whenever a document is to be deactivate.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	The <a>FR_Document</a> that becomes an deactivate document.
     * @return void
     * @note
     */
    void		(*FRDocOnDeactivate)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocWillSave */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called when user clicked the save button on the save dialog. Client should update some data to document.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> that will be saved.
     * @param[in] bSaveAs		A flag indicates whether user click the "save" button or click the "save as" button.
     * @note 
     */
    void		(*FRDocWillSave)(FS_LPVOID clientData, FR_Document doc, FS_BOOL bSaveAs);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocDidSave */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called when a document is saved completely.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> that is saved completely.
	 * @param[in] bSaveAs		A flag indicates whether user click the "save" button or click the "save as" button.
     * @note
     */
    void		(*FRDocDidSave)(FS_LPVOID clientData, FR_Document doc, FS_BOOL bSaveAs);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocWillClose */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called when user click the close menu item or close button. Client should do some corresponding operation here.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	The <a>FR_Document</a> that will be closed.
     * @note
     */
    void		(*FRDocWillClose)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */


    /* @CALLBACKSTART FRDocDidClose */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called when the document is closed completely.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	The <a>FR_Document</a> that is closed.
     * @note
     */
    void		(*FRDocDidClose)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocDidCopy */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called after some page content has been copied to clipboard.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	The <a>FR_Document</a> which content has been copied to clipboard.
     * @note
     */
    void		(*FRDocDidCopy)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocWillPrint */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called when the printer start to work.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	The <a>FR_Document</a> to be printed.
     * @note
     */
    void		(*FRDocWillPrint)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocDidPrint */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called whenever the printer finished work.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	The <a>FR_Document</a> that is printed completely.
     * @note
     */
    void		(*FRDocDidPrint)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnChange */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called when a document is modified.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	The <a>FR_Document</a> that is modified.
     * @return void
     * @note
     */
    void		(*FRDocOnChange)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnPermissionChange */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called after the permission of a document is changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	The <a>FR_Document</a> whose permission is changed.
     * @note
     */
    void		(*FRDocOnPermissionChange)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocWillDraw */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called at the beginning of the drawing.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] docView	The <a>FR_DocView</a> that will be drawn.
     * @param[in] dc		The device context of <param>docView</param>.
     * @note
     */
    void		(*FRDocWillDraw)(FS_LPVOID clientData, FR_DocView docView, FS_HDC dc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocDidDraw */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called when Reader finished the drawing of a document view.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] docView	The <a>FR_DocView</a> that has been drawn.
     * @param[in] dc		The device context of <param>docView</param>.
     * @note
     */
	void		(*FRDocDidDraw)(FS_LPVOID clientData, FR_DocView docView, FS_HDC dc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnWillInsertPages */
    /**
     * @brief					A callback for document-level event handler.
     *
     * It is called to notify all client that the number of page views will increase. At this time,
     * the number of <a>FPD_Page</a> may be increased, meaning there is some <a>FPD_Page</a> inserted to the <a>FPD_Document</a>
     * before this calling.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> whose page views will be inserted.
     * @param[in] iInsertAt		The insert point where the page will be inserted.
     * @param[in] nPages		The page number of inserted page.
     * @note It only avialable in Windows.
     */
    void		(*FRDocOnWillInsertPages)(FS_LPVOID clientData, FR_Document doc, FS_INT32 iInsertAt, FS_INT32 nPages);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnDidInsertPages */
    /**
     * @brief					A callback for document-level event handler.
     *
     * It is called to notify all client that the page has been inserted into the document.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> whose page views has been inserted.
     * @param[in] iInsertAt		The insert point where the page will be inserted.
     * @param[in] nPages		The page number of inserted page.
     * @note It only avialable in Windows.
     */
    void		(*FRDocOnDidInsertPages)(FS_LPVOID clientData, FR_Document doc, FS_INT32 iInsertAt, FS_INT32 nPages);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnWillDeletePages */
    /**
     * @brief					A callback for document-level event handler.
     *
     * It is called to notify all client that some page views will be deleted from the specified document view.
     * In fact, the <a>FPD_Page</a> is deleted from <a>FPD_Document</a> when this method is calling.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> whose page views will be deleted.
      * @param[in] arrDelPages	The index of the pages that has been deleted.
     * @note It only avialable in Windows.
     */
    void		(*FRDocOnWillDeletePages)(FS_LPVOID clientData, FR_Document doc, FS_WordArray arrDelPages);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnDidDeletePages */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called to notify all client that some page views have been deleted from the specified document view.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc		The <a>FR_Document</a> whose page views have been deleted .
     * @param[in] arrDelPages	The index of the pages that has been deleted.
     * @note It only avialable in Windows.
     */ 
    void		(*FRDocOnDidDeletePages)(FS_LPVOID clientData, FR_Document doc, FS_WordArray arrDelPages);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnWillModifyPageAttribute */
    /**
     * @brief				A callback for document-level event handler.
     *
     *It is called to notify all client a page view should be reload.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc		The <a>FR_Document</a> whose page view's associated <a>FPD_Page</a> will be modified.
     * @param[in] iPage		The index of the page that will be modified.
     * @note
     */
    void		(*FRDocOnWillModifyPageAttribute)(FS_LPVOID clientData, FR_Document doc, FS_INT32 iPage);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnDidModifyPageAttribute */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called to notify all client to reload a page.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc		The <a>FR_Document</a> whose page view's associated <a>FPD_Page</a> has been modified.
     * @param[in] iPage		The index of the page that has been modified.
     * @note
     */
    void		(*FRDocOnDidModifyPageAttribute)(FS_LPVOID clientData, FR_Document doc, FS_INT32 iPage);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnWindowCreate */
    /**
     * @brief A callback for document-level event handler.
     *
     * It is called whenever the doc view is created.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> whose bounding window is being created.
     * @note
     */
    void		(*FRDocOnWindowCreate)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnWindowDestroy */
    /**
     * @brief A callback for document-level event handler.
     *
     * It is called whenever a doc view will be destroyed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> whose bounding window will be destroyed.
     * @note
     */
    void		(*FRDocOnWindowDestroy)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnFrameCreate */
    /**
     * @brief A callback for document-level event handler.
     *
     * It is called whenever a child frame window is created.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> whose parent frame is being created.
     * @param[in] hFrameWnd		The child frame window created.
     * @note
     */
    void (*FRDocOnFrameCreate)(FS_LPVOID clientData, FR_Document doc, FS_HWND hFrameWnd);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnFrameDestroy */
    /**
     * @brief A callback for document-level event handler.
     *
     * It is called whenever a child frame window will be destroyed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> whose parent frame will be destroyed.
     * @param[in] hFrameWnd		The child frame window to be destroyed.
     * @note
     */
    void (*FRDocOnFrameDestroy)(FS_LPVOID clientData, FR_Document doc, FS_HWND hFrameWnd);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnAnnotSelectionChanged */
    /**
     * @brief A callback for document-level event handler.
     *
     * It is called whenever a annotation selection changed.
     *
     * @param[in] clientData	The user-supplied data.
     * @note
     * @deprecated Internal use.
     */
    void (*FRDocOnAnnotSelectionChanged)(FS_LPVOID clientData);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnAutoScrollBegin */
    /**
     * @brief A callback for document-level event handler.
     *
     *It is called when a document view start to scroll automatically.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] docView		The <a>FR_DocView</a> start to scroll automatically.
     * @note
     * @deprecated Internal use.
     */
    void (*FRDocOnAutoScrollBegin)(FS_LPVOID clientData, FR_DocView docView);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnAutoScrollEnd */
    /**
     * @brief A callback for document-level event handler.
     *
     * It is called whenever an automatic scrolling view stop to scroll.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] docView		The <a>FR_DocView</a> which has been end the automatic scrolling.
     * @note
     * @deprecated Internal use.
     */
    void (*FRDocOnAutoScrollEnd)(FS_LPVOID clientData, FR_DocView docView);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnFinishRender */
    /**
     * @brief A callback for document-level event handler.
     * @param[in] clientData	The user-supplied data.
     * @param[in] docView		The <a>FR_DocView</a> which has been rendered to screen completely.
     * @note
     */
    void (*FRDocOnFinishRender)(FS_LPVOID clientData, FR_DocView docView);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocThumbnailWillDraw */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called at the beginning of the drawing.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] thumbnailView	The <a>FR_ThumbnailView</a> that will be drawn.
     * @param[in] dc		The device context of <param>thumbnailView</param>.
     * @note
     * @deprecated Internal use.
     */
    void		(*FRDocThumbnailWillDraw)(FS_LPVOID clientData, FR_ThumbnailView thumbnailView, FS_HDC dc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocThumbnailDidDraw */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called when Reader finished the drawing of a thumbnail view.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] thumbnailView	The <a>FR_ThumbnailView</a> that will be drawn.
     * @param[in] dc		The device context of <param>thumbnailView</param>.
     * @note
     * @deprecated Internal use.
     */
    void		(*FRDocThumbnailDidDraw)(FS_LPVOID clientData, FR_ThumbnailView thumbnailView, FS_HDC dc);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRDocScrollBarThumbnailViewWillDraw */
	/**
     * @brief	(Windows Only)	A callback for document-level event handler.
	 *
	 * It is called when clicking the scroll bar and Reader beginning the drawing of a thumbnail view.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @param[in] thumbnailView	The <a>FR_ScrollBarThumbnailView</a> that will be drawn.
	 * @param[in] dc		The device context of <param>thumbnailView</param>.
     * @note
	 * @deprecated Internal use.
     */
	void		(*FRDocScrollBarThumbnailViewWillDraw)(FS_LPVOID clientData, FR_ScrollBarThumbnailView thumbnailView, HDC dc);
	/* @CALLBACKEND */

    /* @CALLBACKSTART FRDocDidFileClose */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called whenever a file is released completely.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] lpwsFilePath	The file path closed.
     * @note
     * @deprecated Internal use.
     */
    void		(*FRDocDidFileClose)(FS_LPVOID clientData, FS_LPCWSTR lpwsFilePath);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocCanBeSaved */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called when user clicked the save button on the save dialog.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> that will be saved.
     * @note
     * @deprecated Internal use.
     */
	FS_BOOL		(*FRDocCanBeSaved)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART OnDocPromptToSave */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called when the document will be prompted to save.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> that will be prompted to save.
     * @param[out] bCancel		Whether to cancel the save process.
     * @note
     * @deprecated Internal use.
     */
    FS_BOOL		(*OnDocPromptToSave)(FS_LPVOID clientData, FR_Document doc, FS_BOOL* bCancel);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocWillReOpen */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called by Foxit Reader when the document is to be reopened.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> that will be reopened.
     * @param[in] bMemDoc		Indicates whether the document is memory document.
     * @note
     */
    void	(*FRDocWillReOpen)(FS_LPVOID clientData, FR_Document doc, FS_BOOL bMemDoc);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocDidReOpen */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called by Foxit Reader when the document has been reopened.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> that has been reopened.
     * @param[in] bMemDoc		Indicates whether the document is memory document.
     * @note
     */
    void	(*FRDocDidReOpen)(FS_LPVOID clientData, FR_Document doc, FS_BOOL bMemDoc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnFrameSize */
    /**
     * @brief			A callback for document-level event handler.
     *
     * Is is called when the child frame is to be adjusted.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> that is associated with the frame.
     * @param[in] hFrameWnd		The child frame whose size is to be adjusted.
     * @param[in] rcClient		The client area of the child frame.
     * @note
     */
    void (*FRDocOnFrameSize)(FS_LPVOID clientData, FR_Document doc, FS_HWND hFrameWnd, FS_Rect rcClient);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnWillActivate */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called whenever a document is to be activated.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	The <a>FR_Document</a> that will become an active document.
     * @note
     */
    void		(*FRDocOnWillActivate)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnWillDeactivate */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called whenever a document is to be deactivated.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	The <a>FR_Document</a> that will become an deactivated document.
     * @return void
     * @note
     */
    void		(*FRDocOnWillDeactivate)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnOtherDocActivate */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called whenever a non-PDF document is to be deactivated.
     *
     * @param[in] clientData	The user-supplied data.
     * @return void
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.1
     * @deprecated Internal use.
     */
    void (*FRDocOnOtherDocActivate)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnOtherDocDeactivate */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called whenever a non-PDF document is to be deactivated.
     *
     * @param[in] clientData	The user-supplied data.
     * @return void
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.1
     * @deprecated Internal use.
     */
    void (*FRDocOnOtherDocDeactivate)(FS_LPVOID clientData);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnOtherDocClose */
	/**
     * @brief	(Windows Only)	A callback for document-level event handler.
	 *
	 * It is called whenever a non-PDF document is to be closed.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
	 * @deprecated Internal use.
     */
	void (*FRDocOnOtherDocClose)(FS_LPVOID clientData);
	/* @CALLBACKEND */

    /* @CALLBACKSTART FRDocDidSave2 */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called when a document is saved completely.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> that is saved completely.
     * @param[in] bSaveAs		A flag indicates whether user click the "save" button or click the "save as" button.
     * @param[in] bPromptToSave Whether Foxit Reader prompts the note to save or not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
     */
    void		(*FRDocDidSave2)(FS_LPVOID clientData, FR_Document doc, FS_BOOL bSaveAs, FS_BOOL bPromptToSave);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnKeyDown */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called by Foxit Reader to notify the key-down event.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] docView		The input doc view whose key-down occurred.
     * @param[in] nKeyCode		The key that was pressed.
     * @param[in] nFlags		Indicates whether various virtual keys are down.
     * @return	<a>TRUE</a> if the key-down event was handled, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    FS_BOOL (*FRDocOnKeyDown)(FS_LPVOID clientData, FR_DocView docView, unsigned int nKeyCode, unsigned int nFlags) ;
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnKeyUp */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called by Foxit Reader to notify the key-up event.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] docView		The input doc view whose key-up occurred.
     * @param[in] nKeyCode		The key that was pressed.
     * @param[in] nFlags		Indicates whether various virtual keys are down.
     * @return	<a>TRUE</a> if the key-up event was handled, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    FS_BOOL	(*FRDocOnKeyUp)(FS_LPVOID clientData, FR_DocView docView, unsigned int nKeyCode, unsigned int nFlags) ;
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnChar */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called by Foxit Reader to notify the char-click event.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] docView		The input doc view whose char-click occurred.
     * @param[in] nKeyCode		The char that was pressed.
     * @param[in] nFlags		Indicates whether various virtual keys are down.
     * @return	<a>TRUE</a> if the char-click event was handled, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    FS_BOOL	(*FRDocOnChar)(FS_LPVOID clientData, FR_DocView docView, unsigned int nKeyCode, unsigned int nFlags) ;
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnLButtonDown */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called by Foxit Reader to notify the left-button-down event.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageView		The input page view whose left-button-down event occurred.
     * @param[in] nFlags		Indicates whether various virtual keys are down.
     * @param[in] point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the left-button-down event was handled, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    FS_BOOL	(*FRDocOnLButtonDown)(FS_LPVOID clientData, FR_PageView pageView, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnLButtonUp */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called by Foxit Reader to notify the left-button-up event.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageView		The input page view whose left-button-up event occurred.
     * @param[in] nFlags		Indicates whether various virtual keys are down.
     * @param[in] point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the left-button-up event was handled, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    FS_BOOL	(*FRDocOnLButtonUp)(FS_LPVOID clientData, FR_PageView pageView, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnLButtonDblClk */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called by Foxit Reader to notify the left-button-double-click event.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageView		The input page view whose left-button-double-click event occurred.
     * @param[in] nFlags		Indicates whether various virtual keys are down.
     * @param[in] point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the left-button-double-click event was handled, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    FS_BOOL (*FRDocOnLButtonDblClk)(FS_LPVOID clientData, FR_PageView pageView, unsigned int nFlags, FS_DevicePoint point) ;
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnMouseMove */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called by Foxit Reader to notify the mouse-move event.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageView		The input page view whose mouse-move event occurred.
     * @param[in] nFlags		Indicates whether various virtual keys are down.
     * @param[in] point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the mouse-move event was handled, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    FS_BOOL (*FRDocOnMouseMove)(FS_LPVOID clientData, FR_PageView pageView, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnRButtonDown */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called by Foxit Reader to notify the right-button-down event.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageView		The input page view whose right-button-down event occurred.
     * @param[in] nFlags		Indicates whether various virtual keys are down.
     * @param[in] point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the right-button-down event was handled, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    FS_BOOL (*FRDocOnRButtonDown)(FS_LPVOID clientData, FR_PageView pageView, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocOnRButtonUp */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called by Foxit Reader to notify the right-button-up event.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageView		The input page view whose right-button-up event occurred.
     * @param[in] nFlags		Indicates whether various virtual keys are down.
     * @param[in] point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the right-button-up event was handled, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    FS_BOOL (*FRDocOnRButtonUp)(FS_LPVOID clientData, FR_PageView pageView, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnRButtonDblClk */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called by Foxit Reader to notify the right-button-double-click event.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageView		The input page view whose right-button-double-click event occurred.
     * @param[in] nFlags		Indicates whether various virtual keys are down.
     * @param[in] point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the right-button-double-click event was handled, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    FS_BOOL (*FRDocOnRButtonDblClk)(FS_LPVOID clientData, FR_PageView pageView, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnMouseWheel */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called by Foxit Reader to notify the mouse-wheel event.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pageView		The input page view whose mouse-wheel event occurred.
     * @param[in] nFlags		Indicates whether various virtual keys are down.
     * @param[in] zDelta		Indicates distance rotated. Reference to <Italic>CWnd::OnMouseWheel</Italic>.
     * @param[in] point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the mouse-wheel event was handled, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    FS_BOOL (*FRDocOnMouseWheel)(FS_LPVOID clientData, FR_PageView pageView, unsigned int nFlags, short zDelta, FS_DevicePoint point);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnDrawAnnot */
	/**
	 * @brief		(Windows Only) A callback for document-level event handler.
	 *
	 * It is called by Foxit Reader when the specified annotation has been drawn. 
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pageView		The input page view where the specified annotation is drawn.
	 * @param[in] frAnnot		The specified annotation to be drawn.
	 * @param[in] hDC			The device context of <param>pageView</param>.
	 * @param[in] renderDevice	The memory device used to render the annotation.
	 * @param[in] user2Device   The current displaying transformation matrix.
	 * @param[in] rcWindow		The rectangle of <param>pageView</param>.
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.3
	 * @deprecated Internal use.
     */
    void (*FRDocOnDrawAnnot)(FS_LPVOID clientData, FR_PageView pageView, FR_Annot frAnnot, HDC hDC, FPD_RenderDevice renderDevice, FS_AffineMatrix user2Device, FS_Rect rcWindow);
	/* @CALLBACKEND */

    /* @CALLBACKSTART FRDocOnDocCollectActionData */
    /**
     * @brief			A callback for document-level event handler.
     *
     * It is called to notify the plug-in that some actions occur.
     *
     * @param[in] clientData		The user-supplied data.
     * @param[in] doc				The specified<a>FR_Document</a>.
     * @param[in] lpwsOperatorType	The operator type.
     * @param[in] lpwsOperator		The operator.
     * @param[in] valueMap			The count of the content related to the operands.
     * @return void
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
     * @deprecated Internal use.
     */
    void (*FRDocOnDocCollectActionData)(FS_LPVOID clientData, FR_Document doc, FS_LPCWSTR lpwsOperatorType, FS_LPCWSTR lpwsOperator, FS_MapPtrToPtr valueMap);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRDocWillOpen2 */
    /**
     * @brief				A callback for document-level event handler.
     *
     * It is called whenever a document is opening. You can uses this new interface instead of <a>FRDocWillOpen</a>. If <a>FRDocWillOpen</a>
     * has been set, <a>FRDocWillOpen2</a> will be ignored.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> object that is opening.
     * @param[in] lpwsFilePath  The file path to be opened.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    void		(*FRDocWillOpen2)(FS_LPVOID clientData, FR_Document doc, FS_LPCWSTR lpwsFilePath);

	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnOptimizerFinish */
	/**
     * @brief		(Windows Only) A callback for document-level event handler.
	 *
	 * It is called whenever a document has been optimized.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> object that is optimized.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
	 * @deprecated Internal use.
     */
	void		(*FRDocOnOptimizerFinish)(FS_LPVOID clientData, FR_Document doc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocCanBeClose */
	/**
     * @brief	(Windows Only) A callback for document-level event handler.
	 *
	 * It is called whenever a document is to be closed.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> object that is closed.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
	 * @deprecated Internal use.
     */
	FS_BOOL		(*FRDocCanBeClose)(FS_LPVOID clientData, FR_Document doc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnReOpenFailed */
	/**
     * @brief	(Windows Only) A callback for document-level event handler.
	 *
	 * It is called whenever the document cannot be reopened successfully.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] lpwsFilePath	The file path closed.
	 * @deprecated Internal use.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 8.1
     */
	void		(*FRDocOnReOpenFailed)(FS_LPVOID clientData, FS_LPCWSTR lpwsFilePath);
	/* @CALLBACKEND */	

	/* @CALLBACKSTART FRDocWillSave2 */
	/**
     * @brief	(Windows Only) A callback for document-level event handler.
	 *
	 * It is called when user clicked the save button on the save dialog. Client should update some data to document.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FR_Document</a> that will be saved.
	 * @param[in] bSaveAs		A flag indicates whether user click the "save" button or click the "save as" button.
	 * @param[in] lpwsFilePath	The file path of the document that will be saved.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 8.2
	 * @deprecated Internal use.
     */
	void		(*FRDocWillSave2)(FS_LPVOID clientData, FR_Document doc, FS_BOOL bSaveAs, FS_LPCWSTR lpwsFilePath);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocCustomizeSaveAsDlg */
	/**
	* @brief	(Windows Only) A callback for document-level event handler.
	*
	* It is called when user clicked the save button on the save dialog before Show Cfiledialog.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] bCanSupportPDFOnly  SaveAs type only can be choose pdf type
	* @param[out] bChoise  the value of user click ok or cancle button
	* @param[out] pwszFilePath  The SaveAs file path name
	* @param[out] iIndex  The SaveAs type index
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 8.3
	* @deprecated Internal use.
	*/
	FS_BOOL(*FRDocCustomizeSaveAsDlg)(FS_LPVOID clientData, 
										FS_BOOL bCanSupportPDFOnly,
										FS_BOOL *bChoise,
										FS_LPCWSTR* pwszFilePath,
										FS_INT32 *iIndex);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocSaveAsBeforeReopen */
	/**
	* @brief	(Windows Only) A callback for document-level event handler.
	*
	* It is called After SaveAs before Reopen.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] wsFileName	The file path name.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 8.3
	* @deprecated Internal use.
	*/
	FS_BOOL(*FRDocSaveAsBeforeReopen)(FS_LPVOID clientData, FS_LPCWSTR wsFileName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocCanPaste */
	/**
	* @brief	(Windows Only) A callback for document-level event handler.
	*
	* It is called When Paste the data to determine whether the current data can be pasted
	*
	* @param[in] clientData	The user-supplied data.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 8.3
	* @deprecated Internal use.
	*/
	FS_BOOL(*FRDocCanPaste)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART OnMouseClickOnText */
	/**
	* @brief	(Windows Only) A callback for document-level event handler.
	*
	* It is called when the mouse clicks on the text field.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] doc		It identifies the document opened. It can be used as a unique identifier for the document.
	* @param[in] wsText		The text where the mouse clicks on.
	* @param[in] rect		The text rectangle where the mouse clicks on.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 8.3.2
	* @deprecated Internal use.
	*/
	void (*OnMouseClickOnText)(FS_LPVOID clientData, FR_Document doc, FS_LPCWSTR wsText, FS_Rect rect);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOwnerSaveAs */
	/**
	* @brief	(Windows Only)	A callback for document-level event handler.
	*
	* It is called after click the ok of saveAs dialog, before save operation.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] doc			It identifies the document saved. It can be used as a unique identifier for the document.
	* @param[in] wszPathName	The path of the save document.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 9.1
	* @deprecated Internal use.
	*/
	BOOL (*FRDocOwnerSaveAs)(FS_LPVOID clientData, FR_Document doc, FS_LPCWSTR wszPathName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnCanDetache */
	/**
	 * @brief	(Windows Only)	A callback for document-level event handler.
	 *
	 * It is called whenever a document can drap to other frame.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] doc	The <a>FR_Document</a> that will become an active document.
	 * @note
	 * @deprecated Internal use.
	 */
	FS_BOOL (*FRDocOnCanDetach)(FS_LPVOID clientData, FR_Document doc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocDelayDidOpen */
	/**
	 * @brief		(Windows Only)	A callback for document-level event handler.
	 *
	 * It is called whenever a document have opened.
	 *
	 * @param[in] doc			The <a>FR_Document</a> object that is optimized.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
	 * @deprecated Internal use.
	 */
	void(*FRDocDelayDidOpen)(FR_Document doc);
	/* @CALLBACKEND */


	/* @CALLBACKSTART FRDocOnActivate2 */
	/**
	 * @brief	(Windows Only)	A callback for document-level event handler.
	 *
	 * It is called whenever a document is to be active.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] doc	The <a>FR_Document</a> that becomes an active document.
	 * @param[in] bMainfrmActivating	If document activate in function OnActivate or OnActivateTopLevel.
	 * @note
	 * @deprecated Internal use.
	 */
	void(*FRDocOnActivate2)(FS_LPVOID clientData, FR_Document doc, FS_BOOL bMainfrmActivating);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnDeactivate2 */
	/**
	 * @brief	(Windows Only)	A callback for document-level event handler.
	 *
	 * It is called whenever a document is to be deactivate.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] doc	The <a>FR_Document</a> that becomes an deactivate document.
	 * @param[in] bMainfrmActivating	If document deactivate in function OnActivate or OnActivateTopLevel.
	 * @return void
	 * @deprecated Internal use.
	 * @note
	 */
	void(*FRDocOnDeactivate2)(FS_LPVOID clientData, FR_Document doc, FS_BOOL bMainfrmActivating);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnOtherDocActivate2 */
	/**
	 * @brief	(Windows Only)	A callback for document-level event handler.
	 *
	 * It is called whenever a non-PDF document is to be deactivated.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] bMainfrmActivating	If other document activate in function OnActivate or OnActivateTopLevel.
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
	 * @deprecated Internal use.
	 */
	void(*FRDocOnOtherDocActivate2)(FS_LPVOID clientData, FS_BOOL bMainfrmActivating);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnAnnotSetFocusEnd */
	/**
	* @brief			A callback for document-level event handler.
	*
	* It is called whenever a Annotation has been focused.
	*
	* @param[in] clientData	The user-supplied data.
    * @param[in] doc	The <a>FR_Document</a> where the annotation is located.
    * @param[in] focusAnnot 	The <a>FR_Annot</a> focused.
    * @return void
    * @note
    * @since <a>SDK_LATEEST_VERSION</a> > 9.5
    * @deprecated Internal use.
    */
    void(*FRDocOnAnnotSetFocusEnd)(FS_LPVOID clientData, FR_Document doc, FR_Annot focusAnnot);
	 /* @CALLBACKEND */
	 
    /* @CALLBACKSTART FRDocOnAnnotRelease */
    /**
    * @brief			A callback for document-level event handler.
    *
    * It is called whenever a Annotation has been release.
    *
    * @param[in] clientData	The user-supplied data.
    * @param[in] doc	The <a>FR_Document</a> where the annotation is located.
    * @param[in] releasedAnnot 	The <a>FR_Annot</a> released.
    * @param[in] eType 	The <a>FRAnnotEventType</a> .
    * @return void
    * @note
    * @since <a>SDK_LATEEST_VERSION</a> > 9.5
    * @deprecated Internal use.
    */
    void(*FRDocOnAnnotRelease)(FS_LPVOID clientData, FR_Document doc, FR_Annot releasedAnnot, FRAnnotEventType eType);
     /* @CALLBACKEND */
	/* @CALLBACKSTART FRDocIsECMFile */
	/**
	* @brief		(Windows Only)	A callback for document-level event handler.
	*
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] doc	The <a>FR_Document</a> object that is opening.
	* @param[in] wszPathName	The path of the document.
	* @param[out] bsECMPluginName	It receives the ECM plugin-name.
	* @return BOOL 
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 11.0
	* @deprecated Internal use.
	*/
	BOOL(*FRDocIsECMFile)(FS_LPVOID clientData, FR_Document doc, FS_LPCWSTR wszPathName, FS_ByteString bsECMPluginName);

	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocSaveAsFinish */
	/**
	* @brief		(Windows Only)		A callback for document-level event handler.
	*
	* It is called when a document is saveas finished.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] doc			The <a>FR_Document</a> that is saveas finished.
	* @param[in] bWillReopen		A flag indicates whether file will reopen.
	* @note
	* @deprecated Internal use.
	*/
	void(*FRDocSaveAsFinish)(FS_LPVOID clientData, FR_Document doc, FS_BOOL bWillReopen);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRFormFieldChanged */
	/**
	* @brief			A callback for form field changed.
	*
	* It is called when form field changed.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] doc			The <a>FR_Document</a> that is saveas finished.
	* @param[in] formField		The changed form field.
	* @param[in] operatype		Form opera type.
	* @note
	*/
	void(*FRFormFieldChanged)(FS_LPVOID clientData, FR_Document doc, FPD_FormField formField, FPD_FORMOPERATYPE operatype);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAnnotAdd */
	/**
	* @brief		(Windows Only)		A callback when annot add.
	*
	* It is called when annot added.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] doc		The <a>FR_Document</a> that is saveas finished.
	* @param[in] annot		The changed form field.
	* @param[in] eType		Annot event type.
	* @note
	* @deprecated Internal use.
	*/
	void(*FRAnnotAdd)(FS_LPVOID clientData, FR_Document doc, FR_Annot annot, FRAnnotEventType eType);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRNotifyOCContextModify */
	/**
	* @brief			A callback when OCContext modify.
	*
	* It is called when OCContext modify.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] doc		The <a>FR_Document</a> that is saveas finished.
	* @note
    * @deprecated Internal use.
	*/
	void(*FRNotifyOCContextModify)(FS_LPVOID clientData, FR_Document doc);
	/* @CALLBACKEND */

    /* @CALLBACKSTART FROnDocCurrentWndProvideChange */
    /**
    * @brief    		A callback when Current CWnd Provide Change.
    *
    * It is called when change to Portfolio or TextView mode.
    *
    * @param[in] clientData	The user-supplied data.
    * @param[in] pDoc		The <a>FR_Document</a> that is saveas finished.
    * @param[in] csWndProvideName		The wnd provide name.
    * @note
    * @deprecated Internal use.
    */
    void(*FROnDocCurrentWndProvideChange)(FS_LPVOID clientData, FR_Document pDoc, FS_ByteString csWndProvideName);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FROnDocPageLabelChange */
    /**
    * @brief            A callback when format page numbers or set use logical page numbers in preference.
    *
    * It is called when doc page label changed.
    *
    * @param[in] clientData	The user-supplied data.
    * @param[in] pDoc		The <a>FR_Document</a> that is saveas finished.
    * @note
    * @deprecated Internal use.
    */
    void(*FROnDocPageLabelChange)(FS_LPVOID clientData, FR_Document pDoc);
    /* @CALLBACKEND */

	 /* @CALLBACKSTART FROnAnnotMoveToOtherPage */
	/**
	* @brief            A callback when format page numbers or set use logical page numbers in preference.
	*
	* It is called when annot moved to other page.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] pDoc		The <a>FR_Document</a> that annot moved on it.
	* @param[in] pAnnotMove	The <a>FR_Annot</a> that annot moved.
	* @param[in] pSrcPage	The <a>FR_Page</a> that annot on original page.
	* @note
	* @deprecated Internal use.
	*/
	void(*FROnAnnotMoveToOtherPage)(FS_LPVOID clientData, FR_Document pDoc, FR_Annot pAnnotMove, FR_Page pSrcPage);
	/* @CALLBACKEND */

	 /* @CALLBACKSTART FRDocSaveAsWithPlugin */
	/**
	 * @brief    (Windows Only) A callback for document-level event handler.
	 *
	 * It is called when the user clicks the save as shortcut button. Clients can enter the Save As process defined by the plugin.
	 *
	 * @param[in] clientData    The user-supplied data.
	 * @param[in] doc            The <a>FR_Document</a> that will be saved.
	 * @param[in] lpwsPluginName    The currently selected plugin name
	 * @param[out] nOutRet        Output the result of saving as. -1 means that the save as process is not entered.
	 *                            0 means the save was successful. 1 indicates that cancel or other cancel operation was clicked during the saving process.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 12.0
	 * @deprecated Internal use.
	 */
	void(*FRDocSaveAsWithPlugin)(FS_LPVOID clientData, FR_Document doc, FS_LPCWSTR lpwsPluginName, FS_INT32 & nOutRet);
	/* @CALLBACKEND */

	/* @CALLBACKSTART OnMouseClickOnText2 */
	/**
	* @brief	(Windows Only) A callback for document-level event handler.
	*
	* It is called when the mouse clicks on the text field.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] doc		It identifies the document opened. It can be used as a unique identifier for the document.
	* @param[in] wsText		The text where the mouse clicks on.
	* @param[in] rect		The text rectangle where the mouse clicks on.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 8.3.2
	* @deprecated Internal use.
	*/
	void(*OnMouseClickOnText2)(FS_LPVOID clientData, FR_Document doc, FS_LPCWSTR wsText, FS_PtrArray pathArray);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnAnnotKillFocus */
	/**
	* @brief	A callback when annot kill focus.
	*
	* It is called when annot kill focus.
	*
	* @param[in] clientData	 The user-supplied data.
	* @param[in] doc		 It identifies the document opened. It can be used as a unique identifier for the document.
	* @param[in] pFocusAnnot The focus annot.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 13.0.0
	*/
	void(*FRDocOnAnnotKillFocus)(FS_LPVOID clientData, FR_Document pDoc, FR_Annot pFocusAnnot);
	/* @CALLBACKEND */
	
	/* @CALLBACKSTART FRFormFieldChanged2 */
	/**
	* @brief			A callback for form field changed.
	*
	* It is called when form field changed.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] doc			The <a>FR_Document</a> that is saveas finished.
	* @param[in] formField		The changed form field.
	* @param[in] operatype		Form opera type.
	* @param[in] bcontainCommitData		Whether contain commit data.
	* @note
	*/
	void(*FRFormFieldChanged2)(FS_LPVOID clientData, FR_Document doc, FPD_FormField formField, FPD_FORMOPERATYPE operatype, FS_BOOL bcontainCommitData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnAnnotSetFocus */
	/**
	* @brief			A callback for document-level event handler.
	*
	* It is called whenever a Annotation has been focused.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] doc	The <a>FR_Document</a> where the annotation is located.
	* @param[in] focusAnnot 	The <a>FR_Annot</a> focused.
	* @return void
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 13.0.0	
	*/
	void(*FRDocOnAnnotSetFocus)(FS_LPVOID clientData, FR_Document doc, FR_Annot focusAnnot);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnPageVisibleEventFinish */
	/**
	* @brief			A callback for document-level event handler.
	*
	* It is called whenever page view changed.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] doc	The <a>FR_Document</a> where the annotation is located.	
	* @return void
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 13.0.0
	*/
	void(*FRDocOnPageVisibleEventFinish)(FS_LPVOID clientData, FR_Document doc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnWillDShowFloatyBar */
	/**
	* @brief			A callback for document-level event handler.
	*
	* It is called before show float bar, plugin can add button to specified position.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] doc	    The <a>FR_Document</a> where the annotation is located.
	* @param[in] bsCurToolhandleName	The current tool handle name.
	* @param[in\out] pAryBeShowBtnName	The button name that will be showed.
	* @return void
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 13.1.0
	*/
	void(*FRDocOnWillDShowFloatyBar)(FS_LPVOID clientData, FR_Document pDoc, FS_LPCSTR bsCurToolhandleName, FS_ByteStringArray* pAryBeShowBtnName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRFileCanBeSave */
	/**
	 * @brief			A callback for document-level event handler.
	 *
	 * It is called before use save or saveas doc.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] doc			The <a>FR_Document</a> that will be saved.
	 * @note
	 * @deprecated Internal use.
	 */
	FS_BOOL(*FRFileCanBeSave)(FS_LPVOID clientData, FR_Document doc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocWillSaveToOther */
	/**
	 * @brief			A callback for document-level event handler.
	 *
	 * It is called before use save or saveas doc.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] doc			The <a>FR_Document</a> that will be saved.
	 * @param[in] csFilterName	The save filter name.
	 * @param[in] csSaveFile	The save file path.
	 * @note
	 * @deprecated Internal use.
	 */
	void(*FRDocWillSaveToOther)(FS_LPVOID clientData, FR_Document doc, FS_LPCSTR csFilterName, FS_LPCWSTR csSaveFile);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOCGStateChanged */
	/**	
	* @brief			A callback for document-level event handler.
	*
	* It is called after changed a OCG group state.	
	*	
	* @param[in] clientData	The user-supplied data.	
	* @param[in] doc			The <a>FR_Document</a> that will be saved.	 
	* @param[in] affectedPages	Pages affected by OCG group changes.	 
	* @param[in] bVisible		OCG group is visible.	 
	* @note	 * @deprecated Internal use.	
	*/
	void(*FRDocOCGStateChanged)(FS_LPVOID clientData, FR_Document doc, const FS_WordArray affectedPages, FPD_OCGroup pOCGChange, FS_BOOLEAN bVisible);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocOnOtherDocActivate3 */
	/**
	 * @brief	(Windows Only)	A callback for document-level event handler.
	 *
	 * It is called whenever a non-PDF document is to be deactivated.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] bMainfrmActivating	If other document activate in function OnActivate or OnActivateTopLevel.
	 * @param[in] pActivateWnd	        The current CWnd* object.
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
	 * @deprecated Internal use.
	 */
	void(*FRDocOnOtherDocActivate3)(FS_LPVOID clientData, FS_BOOL bMainfrmActivating, FS_LPVOID pActivateWnd);
	/* @CALLBACKEND */
}FR_DocEventCallbacksRec, *FR_DocEventCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_AppEventCallbacks */

/**
* @brief A callback set for application-level event handler. See <a>FRAppRegisterAppEventHandler</a>.
*/
typedef struct _fr_pluginevent_callbacks_
{

	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_AppEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRAppPluginOnWillUnLoaded */
	/**
	* @brief A callback for application level event handler.
	*
	* It is called by Foxit Reader when the plugin is loaded.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] lpszPluginName	the plugin name.
	* @return void.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
	*/
	void(*FRAppPluginOnWillUnLoaded)(FS_LPVOID clientData, FS_LPCWSTR lpszPluginName);
	/* @CALLBACKEND */
}FR_PluginEventCallbacksRec, *FR_PluginEventCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_PageEventCallbacks */
/**
 * @brief A callback set for page-level event handler. See <a>FRAppRegisterPageHandlerOfPDDoc</a>.
 *
 */
 typedef struct _fr_pageevent_callbacks_
 {
     /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_PageEventCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRPageViewOnOpen */
    /**
     * @brief				A callback for page-level event handler.
     *
     * It is called whenever a page of a PDF document will be opened.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pv		The <a>FR_PageView</a> which is to be opened.
     * @note
     */
    void	(*FRPageViewOnOpen)(FS_LPVOID clientData, FR_PageView pv);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPageViewOnClose */
    /**
     * @brief				A callback for page-level event handler.
     *
     * It is called whenever a page of a document will be closed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pv		The <a>FR_PageView</a> which is to be closed.
     * @note
     */
    void	(*FRPageViewOnClose)(FS_LPVOID clientData, FR_PageView pv);
    /* @CALLBACKEND */


    /* @CALLBACKSTART FRPageViewOnVisible */
    /**
     * @brief				A callback for page-level event handler.
     *
     * It is called whenever a page will be visible.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pv		The <a>FR_PageView</a> which will be visible.
     * @note
     */
    void	(*FRPageViewOnVisible)(FS_LPVOID clientData, FR_PageView pv);
    /* @CALLBACKEND */


    /* @CALLBACKSTART FRPageViewInvisible */
    /**
     * @brief				A callback for page-level event handler.
     *
     * It is called whenever a page is going to be invisible.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pv		The <a>FR_PageView</a> which will be invisible.
     * @note
     */
    void	(*FRPageViewInvisible)(FS_LPVOID clientData, FR_PageView pv);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPageViewOnContentChanged */
    /**
     * @brief				A callback for page-level event handler.
     *
     * It is called whenever a page's content is modified.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pv		The <a>FR_PageView</a> whose content stream has been modified.
     * @note
     */
    void	(*FRPageViewOnContentChanged)(FS_LPVOID clientData, FR_PageView pv);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPageViewOnWillParsePage */
    /**
     * @brief A callback for page-level event handler.
     *
     * It is called when a page is going to be parsed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pv			The <a>FR_PageView</a> whose page is going to be parsed.
     * @param[in] bPageVisible	Indicates whether the page is visible
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1
     */
    void	(*FRPageViewOnWillParsePage)(FS_LPVOID clientData, FR_PageView pv, FS_BOOL bPageVisible);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPageViewOnDidParsePage */
    /**
     * @brief A callback for page-level event handler.
     *
     * It is called when a page has been parsed.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pv			The <a>FR_PageView</a> whose page has been parsed.
     * @param[in] bPageVisible	Indicates whether the page is visible
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1
     */
    void	(*FRPageViewOnDidParsePage)(FS_LPVOID clientData, FR_PageView pv, FS_BOOL bPageVisible);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPageViewOnContentChanged2 */
    /**
     * @brief				A callback for page-level event handler.
     *
     * It is called whenever a page's content is modified.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] pv		The <a>FR_PageView</a> whose content stream has been modified.
     * @param[in] objArray	It indicates what data is changed. The value type in the array is <a>FR_STRUCTCONTENT_OBJECT</a>.
     * @param[in] changeType The content change type.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 9.1
     */
	void	(*FRPageViewOnContentChanged2)(FS_LPVOID clientData, FR_PageView pv, FS_PtrArray objArray,  FR_ContentChangeType changeType);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnPageAnnotWillLoad */
	/**
	 * @brief				A callback for page-level event handler.
	 *
	 * It is called before a page's annot load .
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pReaderPage	The reader page obj.	
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.1
	 */
	void    (*FROnPageAnnotWillLoad)(FS_LPVOID clientData, FR_Page pReaderPage);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnPageAnnotDidLoad */
	/**
	 * @brief				A callback for page-level event handler.
	 *
	 * It is called after a page's annot load .
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pReaderPage	The reader page obj.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.1
	 */
	void   (*FROnPageAnnotDidLoad)(FS_LPVOID clientData, FR_Page pReaderPage);
	/* @CALLBACKEND */

 }FR_PageEventCallbacksRec, *FR_PageEventCallbacks;
 
/* @CALLBACKGROUPEND */

/* @DEFGROUPSTART DocPermission */

/*
* @brief Definitions for doc permission. They are the PDF standard permission definitions. You can reference to "PDF Reference - User access permissions".
*/

/*@{*/
/** @brief printing*/
#define FR_PERM_PRINT			    0x0004

/** @brief modifying page contents or form fields*/
#define FR_PERM_MODIFY_CONTENT		0x0008

/** @brief extracting text or image for copying*/
#define FR_PERM_EXTRACT_COPY		0x0010

/** @brief extracting text or image for accessibility*/
#define FR_PERM_EXTRACT_ACCESS		0x0200

/** @brief adding or modifying annotations, filling in forms*/
#define FR_PERM_ANNOTATE			0x0020

/** @brief Filling in existing form*/
#define FR_PERM_FILL_FORM			0x0100
 
/** @brief Assembling the document (page organizing)*/
#define FR_PERM_ASSEMBLE			0x0400

/** @brief printing in high quality*/
#define FR_PERM_PRINT_HIGN         0x0800
/*@}*/
/* @DEFGROUPEND */


/* @DEFGROUPSTART FRCIPHERFlag related to <a>FRSecurityGetCryptInfo</a>*/
/*
* @name The flags for cipher. 
*/

/*@{*/
/** @brief FRCIPHER_NONE*/ 
#define FRCIPHER_NONE	0
/** @brief  FRCIPHER_RC4*/ 
#define FRCIPHER_RC4	1
/** @brief FRCIPHER_AES*/ 
#define FRCIPHER_AES	2
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKGROUPSTART FR_SecurityCallbacks */
/**
 * @brief The structure containing the security handler callback functions. Plug-ins can process the PDF documents
 * that are encrypted by customer security handler through these callbacks. See <a>FRAppRegisterSecurityHandler</a>.
 */
typedef struct _fr_securitycallbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_SecurityCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	/* @CALLBACKSTART FRSecurityOnInit */
	/**
     * @brief	It is invoked to initialize the security handler.
	 *	
     * Plug-ins can initialize the data in this callback. The handler should typically keep the encryption dictionary, 
	 * and process data in the encryption dictionary.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] filePath		The file path of the PDF document.
	 * @param[in] encryptDict	The Encrypt dictionary.
	 * @param[in] doc			The PDF document.
     * @return Non-zero means initializing successfully, otherwise failed. The data returned can be passed through <param>securityHandler</param>.
     * @note
     */
    FS_LPVOID		(*FRSecurityOnInit)(FS_LPVOID clientData, FS_LPCWSTR filePath, FPD_Object encryptDict, FPD_Document doc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSecurityIsProcessErrMsg */
	/**
     * @brief	Checks whether the plug-in processes the error message.
	 * @param[in] clientData	The user-supplied data.
     * @return	whether the plug-in processes the error message.
     * @note
     */	
	FS_BOOL			(*FRSecurityIsProcessErrMsg)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSecurityGetPermissions */
	/**
     * @brief Gets permission settings of the document.
	 * @param[in] clientData		The user-supplied data.
     * @param[in] securityData		The data returned from <a>FRSecurityOnInit</a>();
     * @return The permission settings of the document.
     * @note
     */
	FS_DWORD		(*FRSecurityGetPermissions)(FS_LPVOID clientData, FS_LPVOID securityData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSecurityIsOwner */
	/**
     * @brief	Checks whether the current user is owner of the document.
	 * @param[in] securityData	The data returned from <a>FRSecurityOnInit</a>();
	 * @param[in] clientData	The user-supplied data.
     * @return	Whether the current user is owner of the document.
     * @note
     */	
	FS_BOOL			(*FRSecurityIsOwner)(FS_LPVOID clientData, FS_LPVOID securityData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSecurityGetCryptInfo */
	/**
     * @brief	Get encryption information including standard algorithm and key.
	 * @param[in] clientData		The user-supplied data.
     * @param[in] securityData		The data returned from <a>FRSecurityOnInit</a>();
	 * @param[out] outCipher		Receives cipher identifier (<a>FRCIPHER_NONE</a>, <a>FRCIPHER_RC4</a> or <a>FRCIPHER_AES</a>).
	 * @param[out] outBuffer		Receives a pointer to the key buffer.
	 * @param[out] outKeylen		Receives number of bytes of the key.
     * @return	<a>TRUE</a> if successful. <a>FALSE</a> if no standard key info is provided or failure.
     * @note
     */
	FS_BOOL			(*FRSecurityGetCryptInfo)(FS_LPVOID clientData, FS_LPVOID securityData, FS_INT32* outCipher, FS_LPVOID* outBuffer, FS_INT32* outKeylen);
	/* @CALLBACKEND */


	/* @CALLBACKSTART FRSecurityIsMetadataEncrypted */
	/**
     * @brief	Checks if document metadata needs to be encrypted.
	 * @param[in] securityData		The data returned from <a>FRSecurityOnInit</a>();
	 * @param[in] clientData	The user-supplied data.
     * @return	Whether document metadata needs to be encrypted or not.
     * @note
     */
	FS_BOOL			(*FRSecurityIsMetadataEncrypted)(FS_LPVOID clientData, FS_LPVOID securityData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSecurityFinishHandler */
	/**
     * @brief	Release the security handler.
	 * @param[in] clientData		The user-supplied data.
     * @param[in] securityData	The data returned from <a>FRSecurityOnInit</a>();
     * @return  void
     * @note
     */
	void			(*FRSecurityFinishHandler)(FS_LPVOID clientData, FS_LPVOID securityData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSecurityCreateCryptoHandler */
	/**
	* @brief	Create a crypto handler that can do the real encryption/decryption work.
	 *			After creation, the caller should call <a>FREnryptoCreateHandler</a>() to initialize the crypto handler.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] securityData		The data returned from <a>FRSecurityOnInit</a>();
	 * @param[out] outType			It identifies the type of crypto handler.
     * @return If <param>outType</param> is 0, this callback returns the pointer to structure containing the crypto handler callbacks <a>FR_CryptoCallbacks</a>.
	 * If If <param>outType</param> is 1, this callback returns the pointer to internal crypto handler.
     * @note
     */
	FS_LPVOID		(*FRSecurityCreateCryptoHandler)(FS_LPVOID clientData, FS_LPVOID securityData, FS_INT32* outType);
	/* @CALLBACKEND */
	
}FR_SecurityCallbacksRec, *FR_SecurityCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_CryptoCallbacks */
/**
* @brief The structure containing the crypto handler callback functions. They are for PDF cryptographic operations (encryption and decryption).
 * The crypto handler works with security handler which provides algorithm and key info.
 *
 */
typedef struct _fr_crypto_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_CryptoCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FREnryptoCreateHandler */
	/**
	* @brief	Initializes the crypto handler with the data of security handler, and the encrypt dictionary data.
	 * @param[in] clientData		The user-supplied data.
     * @param[in] encryptDict		The encrypt dictionary
	 * @param[in] securityData		The data returned from <a>FRSecurityOnInit</a>();
     * @return Non-zero means initializing successfully, otherwise failed. The data returned can be passed through <param>cryptoHandler</param>.
     * @note
     */
    FS_LPVOID			    (*FREnryptoCreateHandler)(FS_LPVOID clientData, FPD_Object encryptDict, FS_LPVOID securityData);
	/* @CALLBACKEND */
	
	/* @CALLBACKSTART FREnryptoDecryptGetSize */
	/**
     * @brief	Estimate size of decrypted data, from a source size.
	 * If implementation doesn't want to estimate, it can always return 0.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] cryptoHandler	The data returned from <a>FREnryptoCreateHandler</a>();
	 * @param[in] src_size		The input source size.
     * @return The estimated size. 0 means the implementation doesn't want to estimate.
	 * If implementation doesn't want to estimate, it can always return 0.
     * @note
     */
	FS_DWORD				(*FREnryptoDecryptGetSize)(FS_LPVOID clientData, FS_LPVOID cryptoHandler, FS_DWORD src_size);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FREnryptoDecryptStart */
	/**
     * @brief	Starts a decryption process.
	 *
     * If decryption is for some indirect object, object number and generation
	 * number are provided. Implementation can create a context and return pointer to the context.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] cryptoHandler	The data returned from <a>FREnryptoCreateHandler</a>();
	 * @param[in] objnum		The indirect object number.
	 * @param[in] gennum		The indirect object generation number.
     * @return A decrypt context.
     * @note
     */
	FS_LPVOID				(*FREnryptoDecryptStart)(FS_LPVOID clientData, FS_LPVOID cryptoHandler, FS_DWORD objnum,  FS_DWORD gennum);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FREnryptoDecryptStream */
	/**
     * @brief	Decrypt some source data in a stream.
	 *
	 * The <param>cryptoContext</param> parameter is the same as returned by <a>FREnryptoDecryptStart</a>() function.
	 * Implementation should append the decrypted data (if any) to the <param>dest_buf</param> dynamic array.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] cryptoContext	The decrypt context.
	 * @param[in] src_buf		The encrypted source data.
	 * @param[in] src_size		The size in bytes of the source data.
	 * @param[out] dest_buf		It appends the decrypted data to the end.
     * @return	Non-zero means success, otherwise failure.
     * @note
     */
	FS_BOOL					(*FREnryptoDecryptStream)(FS_LPVOID clientData, FS_LPVOID cryptoContext, FS_LPCBYTE src_buf, FS_DWORD src_size, FS_BinaryBuf dest_buf) ;
	/* @CALLBACKEND */

	/* @CALLBACKSTART FREnryptoDecryptFinish */
	/**
     * @brief	Finish a decryption process.
	 *
	 * If decryption context is used, implementation should destroy it.
	 * If there is any left-over data, they should be added to the destination buffer.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] cryptoContext	The decrypt context.
	 * @param[in] dest_buf		It appends the decrypted data to the end.
     * @return	Non-zero means success, otherwise failure. 
     * @note
     */
	FS_BOOL					(*FREnryptoDecryptFinish)(FS_LPVOID clientData, FS_LPVOID cryptoContext, FS_BinaryBuf dest_buf);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FREnryptoEncryptGetSize */
	/**
     * @brief	Get encrypted data size for a source data block.
	 * The returned size should equal to or be larger than the final encrypted data block.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] cryptoHandler	The data returned from <a>FREnryptoCreateHandler</a>();
	 * @param[in] objnum		The indirect object number.
	 * @param[in] version		The indirect object generation number.
	 * @param[in] src_buf		The source data block.
	 * @param[in] src_size		The size in bytes of the source data.
     * @return	The encrypted data size. It should equal to or be larger than the final encrypted data block.
     * @note
     */
	FS_DWORD				(*FREnryptoEncryptGetSize)(FS_LPVOID clientData, FS_LPVOID cryptoHandler, FS_DWORD objnum, FS_DWORD version, FS_LPCBYTE src_buf, FS_DWORD src_size);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FREnryptoEncryptContent */
	/**
     * @brief	Do the encryption process.
	 * Final encrypted data block should be output in the <param>outDestsize</param> parameter.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] cryptoHandler	The data returned from <a>FREnryptoCreateHandler</a>();
	 * @param[in] objnum		The indirect object number.
	 * @param[in] version		The indirect object generation number.
	 * @param[in] src_buf		The source data block.
	 * @param[in] src_size		The size in bytes of the source data.
	 * @param[out] dest_buf		It receives the encrypted data.
	 * @param[out] outDestsize	It receives the size in bytes of the encrypted data.
     * @return	Non-zero means success, otherwise failure.
     * @note
     */
    FS_BOOL					(*FREnryptoEncryptContent)(FS_LPVOID clientData, FS_LPVOID cryptoHandler, FS_INT32 objnum, FS_DWORD version, FS_LPCBYTE src_buf,
												FS_DWORD src_size, FS_LPBYTE dest_buf, FS_DWORD* outDestsize);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FREnryptoFinishHandler */
	/**
     * @brief	Release the crypto handler.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] cryptoHandler	The data returned from <a>FREnryptoCreateHandler</a>();
     * @return void
	 * @note
     */
	void					(*FREnryptoFinishHandler)(FS_LPVOID clientData, FS_LPVOID cryptoHandler);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FREnryptoProgressiveEncryptStart */
	/**
     * @brief It is invoked by Foxit Reader when encrypting if you set the progressive encrypt handler by <a>FPDCreatorSetProgressiveEncryptHandler</a>.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] cryptoHandler	The data returned from <a>FREnryptoCreateHandler</a>();
	 * @param[in] objnum		The object number.
	 * @param[in] version		The indirect object generation number.
	 * @param[in] raw_size		The raw size of stream.
	 * @param[in] bFlateEncode	Indicates whether the source data need to be encoded.
     * @return TRUE if you want to encrypt the object stream progressively, otherwise not.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
     */
    FS_BOOL (*FREnryptoProgressiveEncryptStart)(FS_LPVOID clientData, FS_LPVOID cryptoHandler, FS_DWORD objnum, FS_DWORD version, FS_DWORD raw_size, FS_BOOL bFlateEncode);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FREnryptoProgressiveEncryptContent */
	/**
     * @brief It is invoked by Foxit Reader over and over when encrypting if you set the progressive encrypt handler by <a>FPDCreatorSetProgressiveEncryptHandler</a>.
	 * Implementation should append the encrypted data (if any) to the <param>dest_buf</param> dynamic array.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] cryptoHandler	The data returned from <a>FREnryptoCreateHandler</a>();
	 * @param[in] objnum		The object number.
	 * @param[in] version		The indirect object generation number.
	 * @param[in] src_buf		The source data to be encrypted.
	 * @param[in] src_size		The size of the source data in bytes.
	 * @param[out] dest_buf		It appends the encrypted data to the end.
     * @return TRUE if you encrypt the content successfully, otherwise not.
	 * @note <a>FREnryptoEncryptContent</a> may also be invoked for some objects.
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
     */
    FS_BOOL (*FREnryptoProgressiveEncryptContent)(FS_LPVOID clientData, FS_LPVOID cryptoHandler, FS_INT32 objnum, FS_DWORD version, FS_LPCBYTE src_buf, FS_DWORD src_size, FS_BinaryBuf dest_buf);
	/* @CALLBACKEND */

    /* @CALLBACKSTART FREnryptoProgressiveEncryptFinish */
	/**
     * @brief It is invoked by Foxit Reader when finish encrypting content progressively if you set the progressive encrypt handler
	 * by <a>FPDCreatorSetProgressiveEncryptHandler</a>. Implementation should append the encrypted data (if any) to the <param>dest_buf</param> dynamic array.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] cryptoHandler	The data returned from <a>FREnryptoCreateHandler</a>();
	 * @param[out] dest_buf		It appends the encrypted data to the end.
     * @return TRUE if you encrypt the content successfully, otherwise not.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
     */
	FS_BOOL (*FREnryptoProgressiveEncryptFinish)(FS_LPVOID clientData, FS_LPVOID cryptoHandler, FS_BinaryBuf dest_buf);
	/* @CALLBACKEND */

}FR_CryptoCallbacksRec, *FR_CryptoCallbacks;

/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_ContentProviderCallbacks */
/**
 * @brief The structure containing  content provider callbacks. Plug-ins invoke these callbacks to provide PDF content to
 * Foxit Reader. These PDF files are usually not in standard structure and may be encrypted by customer algorithm.
 * See <a>FRAppRegisterContentProvider</a>.
 *
 */
typedef struct _fr_content_provider_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ContentProviderCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;
	
    /* @CALLBACKSTART FRConProviderOnFileOpen */
    /**
    * @brief It will be invoked by Foxit Reader when a document is opened. If it returns <a>TRUE</a>,
     * it means the plug-in can process the document and the other callbacks go on. Otherwise not.
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			It identifies the document opened. It can be used as a unique identifier for the document.
     * @param[in] lpszSource	The full path of the document opened.
     * @param[in] bIsAttachment TRUE means the document is a attachment.
     * @return <a>TRUE</a> means the plug-in can process this document and the other callbacks go on. Otherwise not.
     * @note
     */
    FS_BOOL			(*FRConProviderOnFileOpen)(FS_LPVOID clientData, FR_Document doc, FS_LPCWSTR lpszSource, FS_BOOL bIsAttachment);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRConProviderOnGetPermissions */
    /**
     * @brief The plug-in can control the permissions of the document.
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc					It identifies the document opened. It can be used as a unique identifier for the document.
     * @param[in] pdfselfPermissions	The PDF document's permission.
     * @return    The user-defined permissions.
     * @note
     */
    FS_DWORD	(*FRConProviderOnGetPermissions)(FS_LPVOID clientData, FR_Document doc, FS_DWORD  pdfselfPermissions);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRConProviderOnGetContentSize */
    /**
     * @brief It will be invoked by Foxit Reader to receive the size of the document the plug-in provides.
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			It identifies the document opened. It can be used as a unique identifier for the document.
     * @param[out] pTotalSize	It receives the size of the document the plug-in provides.
     * @return    <a>TRUE</a> means successful. Otherwise not.
     * @note
     */
    FS_BOOL			(*FRConProviderOnGetContentSize)(FS_LPVOID clientData, FR_Document doc, FS_DWORD* pTotalSize);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRConProviderOnReadContent */
    /**
    * @brief  It will be invoked by Foxit Reader to receive the the document data the plug-in provides.
     *        This routine occurs times without number and the data is read in blocks.
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	It identifies the document opened. It can be used as a unique identifier for the document.
     * @param[in] pos	It identifies the position of the document data the plug-in provides.
     * @param[out] pBuf It receives the data block the plug-in provides every time.
     * @param[in] size	It identifies the size of the data block that the plug-in should provide every time.
     * @return    <a>TRUE</a> means successful. Otherwise not.
     * @note
     */
    FS_BOOL			(*FRConProviderOnReadContent)(FS_LPVOID clientData, FR_Document doc, FS_DWORD pos, unsigned char* pBuf, FS_DWORD size);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRConProviderOnWriteContent */
    /**
    * @brief It will be invoked by Foxit Reader when the document is modified and is saved. The plug-in must re-encrypt
     *       the document and save the document in some format.
     * @param[in] clientData		The user-supplied data.
     * @param[in] doc				It identifies the document opened. It can be used as a unique identifier for the document.
     * @param[in] pBuf				Foxit Reader passes the document data that is modified to the plug-in.
     * @param[in] size				The buffer size.
     * @param[in] lpSaveFilePath	Foxit Reader passes the file path where the document is saved to the plug-in.
     * @return    <a>TRUE</a> means successful. Otherwise not.
     * @note
     */
    FS_BOOL			(*FRConProviderOnWriteContent)(FS_LPVOID clientData, FR_Document doc, unsigned char* pBuf, FS_DWORD size, FS_LPCWSTR lpSaveFilePath);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRConProviderOnFileClose */
    /**
     * @brief It will be invoked by Foxit Reader when the document is closed.
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc	It identifies the document opened. It can be used as a unique identifier for the document.
     * @return    void
     * @note
     */
    void			(*FRConProviderOnFileClose)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
	
	/* @CALLBACKSTART FRConProviderOnWriteAttachmentContent */
    /**
     * @brief When the attachment is opened, it will be saved to a temp directory first. This interface leaves the choice of protecting
     *        the attachment to the plug-in. You can get the type of the attachment from the file path.
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc				It is the document whose attachment is opened.
     * @param[in] pBuf				The content of the attachment.
     * @param[in] size				The size of the attachment.
     * @param[in] lpAttchmntPath	The path of the attachment.
     * @return    <a>TRUE</a> means successful, otherwise failure.
     * @note
     */
    FS_BOOL			(*FRConProviderOnWriteAttachmentContent)(FS_LPVOID clientData, FR_Document frDoc, unsigned char * pBuf, FS_DWORD size, FS_LPCWSTR lpAttchmntPath);
    /* @CALLBACKEND */
	
	/* @CALLBACKSTART FRConProviderOnGetAttachmentSize */
    /**
     * @brief When the attachment is modified, the Foxit Reader needs to reattach the attachment. This interface is invoked to
     *        get the total size of the attachment modified.
     * @param[in] clientData	The user-supplied data.
     * @param[in]  frDoc			It is the document whose attachment is opened.
     * @param[out] pTotalSize		The total size of the attachment.
     * @param[in]  lpAttchmntPath	The path of the attachment.
     * @return    <a>TRUE</a> means successful, otherwise failure.
     * @note
     */
    FS_BOOL			(*FRConProviderOnGetAttachmentSize)(FS_LPVOID clientData, FR_Document frDoc, FS_DWORD* pTotalSize, FS_LPCWSTR lpAttchmntPath);
    /* @CALLBACKEND */
	
	/* @CALLBACKSTART FRConProviderOnReadAttachmentContent */
	/**
	 * @brief When the attachment is modified, the Foxit Reader needs to reattach the attachment. This interface is invoked to 
	 *        get the content of the attachment modified. Since <a>SDK_LATEEST_VERSION</a> > 3.0, <a>FRConProviderOnReadAttachmentContent</a> 
	 * is replaced with <a>FRConProviderOnReadAttachmentContentInBlocks</a>.
     * @param[in]	clientData	The user-supplied data.
     * @param[in]  frDoc			It is the document whose attachment is opened.
     * @param[out] pBuf				It receives the content of the attachment modified.
     * @param[in]  size				The total size of the attachment.
     * @param[in]  lpAttchmntPath	The path of the attachment.
     * @return    <a>TRUE</a> means successful, otherwise failure.
     * @note
     */
    FS_BOOL			(*FRConProviderOnReadAttachmentContent)(FS_LPVOID clientData, FR_Document frDoc, unsigned char* pBuf, FS_DWORD size, FS_LPCWSTR lpAttchmntPath);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FRConProviderIsPageAvail */
    /**
     * @brief It will be invoked by Foxit Reader when a PDF page will be parsed or rendered. <brief>This callback is useful when the PDF file is placed on a web server and
     * then the PDF page data is downloaded progressively to parse or display. Please ensure the entire PDF page data has been downloaded and is availible before you return
     * <a>TRUE</a>, otherwise crash will occure.
     * @param[in]	clientData	The user-supplied data.
     * @param[in]  frDoc			It is the document whose attachment is opened.
     * @param[in]  iPage			The page index specifies the PDF page to be check.
     * @return    <a>TRUE</a> means page data is availible, otherwise unvailible.
     * @note If the PDF file is a local file and have all content information, this callback will be never invoked.
     */
    FS_BOOL			(*FRConProviderIsPageAvail)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 iPage);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRConProviderGetPageSize */
    /**
    * @brief It will be invoked by Foxit Reader to get each page size. <brief>This callback is useful when the PDF file is placed on a web server and
    * then the PDF page data is downloaded progressively to parse or display. When Foxit Reader start to layout page views, Foxit Reader will call this
    * callback to get the page size to layout page views.
    * @param[in]	clientData	The user-supplied data.
    * @param[in]  frDoc			It is the document whose attachment is opened.
    * @param[in]  iPage			The page index specifies the PDF page to get the page size.
    * @param[out]  outWidth		The page width of specified page by <Italic>iPage</Italic> in PDF coordinate, client must fill the page width to this parameter.
    * @param[out]  outHeight		The page height of specified page by <Italic>iPage</Italic> in PDF coordinate, client must fill the page height to this parameter.
    * @return    <a>TRUE</a> for success, otherwise failure.
    * @note Must return <a>FALSE</a> if the PDF file is a local file and have all content information, and Foxit Reader will get page size by itself.
    */
    FS_BOOL			(*FRConProviderGetPageSize)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 iPage, FS_FLOAT* outWidth, FS_FLOAT* outHeight);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRConProviderDrawOwnerPage */
    /**
    * @brief It will be invoked by Foxit Reader when a PDF page data can not be obtained and the PDF page will be rendered.
    * @param[in]	clientData	The user-supplied data.
    * @param[in]  frDoc			It is the document whose attachment is opened.
    * @param[in]  iPage			The page index specifies the PDF page to be rendered.
    * @param[in]  bitmap			The bitmap passed by Foxit reader, client will be draw owner information to it.
    * @param[in]  start_x			Left pixel position of the drawing area in the device coordination.
    * @param[in]  start_y			Top pixel position of the display area in the device coordination.
    * @param[in]  width			Horizontal size (in pixels) for drawing area.
    * @param[in]  height			Vertical size (in pixels) for drawing area.
    * @return    <a>TRUE</a> for success, otherwise failure.
    * @note Must be return <a>FALSE</a> if client needn't draw owner information to a page view. If return <a>TRUE</a>, Foxit Reader just
    * call this callback to drawing, and the content of PDF page will not be displayed.
    */
    FS_BOOL			(*FRConProviderDrawOwnerPage)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 iPage, FS_DIBitmap bitmap, FS_INT32 start_x, FS_INT32 start_y, FS_INT32 width, FS_INT32 height);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRConProviderNeedReopenDoc */
    /**
    * @brief
    * @param[in] clientData		The user-supplied data.
    * @param[in]  frDoc			It is the document whose attachment is opened.
    * @return    <a>TRUE</a> for needing to reopen the document.
    */
    FS_BOOL			(*FRConProviderNeedReopenDoc)(FS_LPVOID clientData, FR_Document frDoc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRConProviderCanBeSaved */
    /**
    * @brief
    * @param[in] clientData		The user-supplied data.
    * @param[in]  frDoc			It is the document whose attachment is opened.
    * @return    <a>TRUE</a> for the document can be saved.
    */
    FS_BOOL			(*FRConProviderCanBeSaved)(FS_LPVOID clientData, FR_Document frDoc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRContentProviderIsProcessErrMsg */
    /**
     * @brief	Checks whether the plug-in processes the error message.
     * @param[in] clientData	The user-supplied data.
     * @return	whether the plug-in processes the error message.
     * @note
     */
    FS_BOOL			(*FRContentProviderIsProcessErrMsg)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRContentProviderIsSupportPanel */
	/**
     * @brief	Checks Whether the document supports panel.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in]  frDoc		Whether the document supports panel.
	 * @return	Whether the document supports panel.
     * @note
     */	
	FS_BOOL			(*FRContentProviderIsSupportPanel)(FS_LPVOID clientData, FR_Document frDoc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRContentProviderIsSupportViewByScroll */
	/**
     * @brief	Checks whether the document supports viewing by scrolling.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in]  frDoc		Whether the document supports viewing by scrolling.
	 * @return	Whether the document supports viewing by scrolling.
     * @note
     */	
	FS_BOOL			(*FRContentProviderIsSupportViewByScroll)(FS_LPVOID clientData, FR_Document frDoc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRContentProviderIsSupportViewByScroll */
	/**
     * @brief	Determine whether to delete the navigation panel.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in]  lpsName		The name of navigation panel.
	 * @return	Returns <a>TRUE</a> to delete the navigation panel, otherwise not.
     * @note
     */	
	FS_BOOL			(*FROnPanelDelete)(FS_LPVOID clientData, FS_LPCSTR lpsName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnGetPageDictObjectNumber */
	/**
     * @brief This interface is reserved.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in]  frDoc		The document.
	 * @param[in]  nPageIndex	The page index.
	 * @param[out] outObjNumber	It receives the object number of page dictionary.
	 * @return Nonzero if the plug-in gets the number; otherwise 0.
     * @note
     */	
	FS_BOOL (*FROnGetPageDictObjectNumber)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nPageIndex, FS_DWORD* outObjNumber);
	/* @CALLBACKEND */
	
	/* @CALLBACKSTART FRConProviderIsWriteContentProgressive */
	/**
	* @brief It will be invoked by Foxit Reader to check whether write the content progressively or all at once.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] doc				It identifies the document opened. It can be used as a unique identifier for the document.
	 * @param[in] lpSaveFilePath	Foxit Reader passes the file path where the document is saved to the plug-in.
	 * @return    <a>TRUE</a> indicates that write the content progressively, then <a>FRConProviderOnWriteContent</a> will be invoke over and over.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	 */
     FS_BOOL        (*FRConProviderIsWriteContentProgressive)(FS_LPVOID clientData, FR_Document doc, FS_LPCWSTR lpSaveFilePath);
	/* @CALLBACKEND */	
	
    /* @CALLBACKSTART FRConProviderWriteContentProgressiveFinish */
    /**
    * @brief It will be invoked by Foxit Reader to notify that finish writing content progressively.
     * @param[in] clientData		The user-supplied data.
     * @param[in] doc				It identifies the document opened. It can be used as a unique identifier for the document.
     * @param[in] lpSaveFilePath	Foxit Reader passes the file path where the document is saved to the plug-in.
     * @param[in] bResult			It indicates whether the process of writing content is successful.
     * @return    <a>TRUE</a> means successful. Otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
     */
    FS_BOOL (*FRConProviderWriteContentProgressiveFinish)(FS_LPVOID clientData, FR_Document doc, FS_LPCWSTR lpSaveFilePath, FS_BOOL bResult);
    /* @CALLBACKEND */
	
	/* @CALLBACKSTART FRConProviderIsWriteAttachmentContent */
	/**
	 * @brief When the attachment is opened, it will be saved to a temp directory first. This interface will be invoked to determine that whether
	 * the plug-in is to write the attachment content itself or not. If this interface returns TRUE, <a>FRConProviderOnWriteAttachmentContent</a> will 
	 * be invoked several times to write the attachment content in blocks.
	 * 
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc				It is the document whose attachment is opened.
	 * @param[in] lpAttchmntPath	The path of the attachment.
     * @return    <a>TRUE</a> means the plug-in is to write the attachment content itself, otherwise not.
     * @note
	 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
     */
	FS_BOOL (*FRConProviderIsWriteAttachmentContent)(FS_LPVOID clientData, FR_Document frDoc, FS_LPCWSTR lpAttchmntPath);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRConProviderOnWriteAttachmentContentFinish */
	/**
	 * @brief When the attachment is opened, it will be saved to a temp directory first. This interface will be invoked when finishing writing
	 * the attachment content to the temp directory.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc				It is the document whose attachment is opened.
	 * @param[in] lpAttchmntPath	The path of the attachment.
     * @return    <a>TRUE</a> means successful, otherwise failure.
     * @note
	  * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
     */
	FS_BOOL (*FRConProviderOnWriteAttachmentContentFinish)(FS_LPVOID clientData, FR_Document frDoc, FS_LPCWSTR lpAttchmntPath);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRConProviderOnReadAttachmentContentInBlocks */
	/**
	 * @brief When the attachment is modified, the Foxit Reader needs to reattach the attachment. This interface is invoked to 
	 *        get the content of the attachment modified. Firstly, <a>FRConProviderOnGetAttachmentSize</a> will be invoked to obtain the 
	 * size of the attachment content. Since <a>SDK_LATEEST_VERSION</a> > 3.0, <a>FRConProviderOnReadAttachmentContent</a> 
	 * is replaced with <a>FRConProviderOnReadAttachmentContentInBlocks</a>.
	 * @param[in]	clientData	The user-supplied data.
	 * @param[in]  frDoc			It is the document whose attachment is opened.
	 * @param[in]  pos				It identifies the position of the document data.
	 * @param[out] pBuf				It receives the content of the attachment modified.
	 * @param[in]  size				The total size of the attachment.
	 * @param[in]  lpAttchmntPath	The path of the attachment.
     * @return    <a>TRUE</a> means successful, otherwise failure.
     * @note
	  * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
     */
	FS_BOOL (*FRConProviderOnReadAttachmentContentInBlocks)(FS_LPVOID clientData, FR_Document frDoc, FS_DWORD pos, unsigned char* pBuf, unsigned long size, FS_LPCWSTR lpAttchmntPath);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRConProviderOnBackFillContent */
	/**
	* @brief It will be invoked by Foxit Reader when some data need to be backfilled after <a>FRConProviderOnWriteAttachmentContentFinish</a> finishes.
	 * @param[in] clientData		The user-supplied data.
     * @param[in] doc				It identifies the document opened. It can be used as a unique identifier for the document.
	 * @param[in] pBuf				Foxit Reader passes the document data that is modified to the plug-in.
	 * @param[in] size				The buffer size.
	 * @param[in] lpSaveFilePath	Foxit Reader passes the file path where the document is saved to the plug-in.
     * @return    <a>TRUE</a> means successful. Otherwise not.
     * @note
     */
	FS_BOOL			(*FRConProviderOnBackFillContent)(FS_LPVOID clientData, FR_Document doc, unsigned char* pBuf, unsigned long size, FS_LPCWSTR lpSaveFilePath);
	/* @CALLBACKEND */	

	/* @CALLBACKSTART FROnRequestDocPermPDDoc */
	/**
	* @brief  (Windows Only ) Checks the permissions associated with the specified document using the latest permissions format, and determines
	     *whether the requested operation is allowed for the specified object in the document.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] doc				It identifies the document opened. It can be used as a unique identifier for the document.
	 * @param[in] reqObj			The target object of the permissions request.	
	 * @param[in] reqOpr			The target operation of the permissions.
	 * @param[in] authData      	A pointer to an authorization data structure.
	 * @return   The request status constant, <code>0</code> if the requested operation	is allowed, a non - zero status code otherwise.
	 * @note
	 */
	FRPermReqStatus(*FROnRequestDocPermPDDoc)(FS_LPVOID clientData, FR_Document doc, FRPermReqObj reqObj, FRPermReqOpr reqOpr, FS_LPVOID authData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnGetAppPermissions */
	/**
	* @brief (Windows Only)Get the real permission which is combined application setting and  permission of document.
	* @param[in] clientData		The user-supplied data.
	* @param[in] doc				It identifies the document opened. It can be used as a unique identifier for the document.
	* @param[in] docappselfPermissions      the permissions of document
	* @return   the real permission
	* @note
	*/
	FS_DWORD (*FROnGetAppPermissions)(FS_LPVOID clientData, FR_Document doc, FS_DWORD docappselfPermissions);
	/* @CALLBACKEND */

}FR_ContentProviderCallbacksRec, *FR_ContentProviderCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_ExtraPrintInfoProviderCallback */
/**
 * @brief You can use this interface to customize the print process.
 * See <a>FRAppRegisterExtraPrintInfoProvider</a>.
 */
typedef struct _fr_print_extrainfo_provider_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ExtraPrintInfoProviderCallbackRec</a>). */
	unsigned long lStructSize;
	
	/** The user-supplied data. */
	FS_LPVOID		clientData;


	/* @CALLBACKSTART FRToMast */
	/**
     * @brief	Tests whether a document can be controlled to print. 
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document to be printed.
     * @return  If the document can be controlled to print by plug-in, return <a>TRUE</a>, otherwise <a>FALSE</a>.
     * @note
     */
	FS_BOOL			(*FRToMast)(FS_LPVOID clientData, FR_Document frDoc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRCanBePrinted */
	/**
     * @brief	Tests whether a document can be printed.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document to be printed.
	 * @param[in] copies		The number of copies.
	 * @param[in] bTotalPages	A flag indicates whether all pages will be printed.
	 * @param[in] arrPages		A integer array use to store the index of page which to be printed. If <param>bTotalPages</param> is <a>TRUE</a>,
	 *							the array is an empty array.
	 * @param[in] bPostScript	A flag indicates whether the printer is a post-script printer.
	 * @param[in] bLocal		A flag indicates whether the printer is a local printer.
	 * @param[in] bNetWork		A flag indicates whether the printer is a net work printer.
	 * @param[in] bShared		A flag indicates whether the printer is a shared printer.
	 * @param[in] Printer		The name of printer.
	 * @param[in] PrinterModel	The printer model.
	 * @param[in] PrinterDriver	The printer driver name.
	 * @param[in] PrinterData	The printer data.
	 * @param[in] PrinterProt	The print port.
     * @return  If the document can be printed, return <a>TRUE</a>, otherwise <a>FALSE</a>.
     * @note
     */
	FS_BOOL			(*FRCanBePrinted)(FS_LPVOID clientData, 
										FR_Document frDoc, 
										FS_INT32 copies,
										FS_BOOL bTotalPages,
										FS_DWordArray arrPages,
										FS_BOOL bPostScript,
										FS_BOOL bLocal,
										FS_BOOL bNetWork,
										FS_BOOL bShared,
										FS_ByteString Printer,
										FS_ByteString PrinterModel,
										FS_ByteString PrinterDriver,
										FS_ByteString PrinterData,
										FS_ByteString PrinterProt
										);
	/* @CALLBACKEND */


	/* @CALLBACKSTART FRCountOwnerTextPrintInfo */
	/**
     * @brief  Gets the total number of text information which will be printed as a watermark of specified page.
	 * 
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document which to be printed.
	 * @param[in] iPage			The page index indicates the page which will be printed.
	 * @return A integer indicates total number of the text information which will be printed as a watermark in a page.
     * @note
     */
	FS_INT32		(*FRCountOwnerTextPrintInfo)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 iPage);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRCountOwnerImgPrintInfo */
	/**
     * @brief  Gets the total number of image information which will be printed as a watermark of specified page.
	 * 
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document which to be printed.
	 * @param[in] iPage			The page index indicates the page which will be printed.
	 * @return A integer indicates total number of the image information which will be printed as a watermark in a page.
     * @note
     */
	FS_INT32		(*FRCountOwnerImgPrintInfo)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 iPage);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPrintOwnerTextInfo */
	/**
     * @brief  Passes the text information to Foxit Reader to print as a watermark of a page.
	 * 
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document which to be printed.
	 * @param[in] iPage			The page index.
	 * @param[in] nStartX		Left pixel position of the page specified by <param>iPage</param>.
	 * @param[in] nStartY		Top pixel position of the page specified by <param>iPage</param>.
	 * @param[in] nWidth		Horizontal size (in pixels) of the page specified by <param>iPage</param>.
	 * @param[in] nHeight		Vertical size (in pixels) of the page specified by <param>iPage</param>.
	 * @param[in] index			The zero based index of text information.
	 * @param[out] textLeftPos	Left pixel position of the display area in the device coordination.
	 * @param[out] textTopPos	Top pixel position of the display area in the device coordination.
	 * @param[out] textOpacity	The opacity of the information.
	 * @param[out] textColor		The color of the text.
	 * @param[out] textUseFont	The font of the text.
	 * @param[out] textMatrix	The matrix of the text.
     * @return A byte string which storing the text, and the string will be printed as a watermark with a page.
     * @note
     */
	FS_ByteString			(*FRPrintOwnerTextInfo)(FS_LPVOID clientData, 
										FR_Document frDoc, 
										FS_INT32 iPage, 
										FS_INT32 nStartX, 
										FS_INT32 nStartY, 
										FS_INT32 nWidth, 
										FS_INT32 nHeight, 
										FS_INT32 index,
										FS_INT32* textLeftPos,
										FS_INT32* textTopPos,
										FS_FLOAT* textOpacity,
										FS_DWORD* textColor,
										void* textUseFont,
										FS_AffineMatrix* textMatrix
										);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPrintOwnerImgInfo */
	/**
     * @brief  
	 * 
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document which to be printed.
	 * @param[in] iPage			The page index.
	 * @param[in] nStartX		Left pixel position of the page specified by <param>iPage</param>.
	 * @param[in] nStartY		Top pixel position of the page specified by <param>iPage</param>.
	 * @param[in] nWidth		Horizontal size (in pixels) of the page specified by <param>iPage</param>.
	 * @param[in] nHeight		Vertical size (in pixels) of the page specified by <param>iPage</param>.
	 * @param[in] index			The zero based index of text information.
	 * @param[out] imgLeftPos	Left pixel position of the display area in the device coordination.
	 * @param[out] imgTopPos		Top pixel position of the display area in the device coordination.
	 * @param[out] imgOpacity	The opacity used to show image.
	 * @param[out] imgMatrix		The matrix used to show image.
     * @return A bitmap which will be printed as a watermark with a page.
     * @note
     */
	FS_DIBitmap		(*FRPrintOwnerImgInfo)(FS_LPVOID clientData, 
										FR_Document frDoc, 
										FS_INT32 iPage, 
										FS_INT32 nStartX, 
										FS_INT32 nStartY, 
										FS_INT32 nWidth, 
										FS_INT32 nHeight,
										FS_INT32 index,
										FS_INT32* imgLeftPos,
										FS_INT32* imgTopPos,
										FS_FLOAT* imgOpacity,
										FS_AffineMatrix* imgMatrix
										);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPrintOnPreviewDidRender */
	/**
     * @brief  It is invoked by Foxit Reader when the page has been rendered to preview dialog. You can use the 
	 * <param>renderDevice</param> to render extra content to the preview dialog.
	 * 
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document which to be printed.
	 * @param[in] pdfPage		The Page to be rendered.
	 * @param[in] iPage			The page index.
	 * @param[in] matrix		The matrix used to render the page to device.
	 * @param[in] renderDevice	The memory device used to render the page.
     * @note
     */
	void (*FRPrintOnPreviewDidRender)(FS_LPVOID clientData, 
									FR_Document frDoc, 									
									FPD_Page pdfPage, 
									FS_INT32 iPage, 
									FS_AffineMatrix matrix, 
									FPD_RenderDevice renderDevice);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPrintOnDidRender */
	/**
	* @brief  It is invoked by Foxit Reader when the page has been printed to the printer. You can use the 
	* <param>renderDevice</param> to print extra content to the printer.
	 * 
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document which to be printed.
	 * @param[in] pdfPage		The Page to be rendered.
	 * @param[in] iPage			The page index.
	 * @param[in] matrix		The matrix used to render the page to device.
	 * @param[in] renderDevice	The memory device used to render the page.
     * @note
     */
	void (*FRPrintOnDidRender)(FS_LPVOID clientData, 
									FR_Document frDoc, 									
									FPD_Page pdfPage, 
									FS_INT32 iPage, 
									FS_AffineMatrix matrix, 
									FPD_RenderDevice renderDevice);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPrintIsPrintOpacity */
	/**
     * @brief  It is invoked by Foxit Reader before the page is rendered to memory device.
	 * 
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document which to be printed.
	 * @param[in] pdfPage		The Page to be rendered.
	 * @param[in] iPage			The page index.
     * @return Whether to print opacity content.
     * @note
     */
	FS_BOOL (*FRPrintIsPrintOpacity)(FS_LPVOID clientData, 
									FR_Document frDoc, 									
									FPD_Page pdfPage, 
									FS_INT32 iPage);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRCanBePrinted2 */
	/**
     * @brief	Tests whether a document can be printed.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document to be printed.
	 * @param[in] copies		The number of copies.
	 * @param[in] bTotalPages	A flag indicates whether all pages will be printed.
	 * @param[in] arrPages		A integer array use to store the index of page which to be printed. If <param>bTotalPages</param> is <a>TRUE</a>,
	 *							the array is an empty array.
	 * @param[in] bPostScript	A flag indicates whether the printer is a post-script printer.
	 * @param[in] bLocal		A flag indicates whether the printer is a local printer.
	 * @param[in] bNetWork		A flag indicates whether the printer is a net work printer.
	 * @param[in] bShared		A flag indicates whether the printer is a shared printer.
	 * @param[in] Printer		The name of printer.
	 * @param[in] PrinterModel	The printer model.
	 * @param[in] bsSubset		The subset.
	 * @param[in] PrinterDriver	The printer driver name.
	 * @param[in] PrinterData	The printer data.
	 * @param[in] PrinterProt	The print port.
     * @return  If the document can be printed, return <a>TRUE</a>, otherwise <a>FALSE</a>.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
     */
	FS_BOOL			(*FRCanBePrinted2)(FS_LPVOID clientData, 
										FR_Document frDoc, 
										FS_INT32 copies,
										FS_BOOL bTotalPages,
										FS_DWordArray arrPages,
										FS_BOOL bPostScript,
										FS_BOOL bLocal,
										FS_BOOL bNetWork,
										FS_BOOL bShared,
										FS_WideString Printer,
										FS_ByteString PrinterModel,
										FS_ByteString bsSubset,
										FS_ByteString PrinterDriver,
										FS_ByteString PrinterData,
										FS_ByteString PrinterProt
										);
	/* @CALLBACKEND */

}FR_ExtraPrintInfoProviderCallbackRec, *FR_ExtraPrintInfoProviderCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_PanelViewCallbacksRec */

/**
 * @brief A callback set for navigation panel view. A navigation panel is a container that contain the navigation views, such as bookmark view,
 * thumbnail pages view, layers view, comments view, attachments view and so on.
 * See	<a>FRAppRegisterNavPanelView</a>.
 */
typedef struct  _fr_panelview_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_PanelViewCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRPanelViewGetName */
    /**
     * @brief	A callback for navigation panel view. It is called by Foxit Reader to get the panel view's name.
     * @param[in] clientData	The user-supplied data.
     * @return	A null-determined string correspond the name of panel view.
     * @note The return name object needs to be a global object, and local objects will get exceptions due to object release.
	 * @deprecated Internal use. Suggest use FRPanelViewGetName2.
     */
    FS_LPSTR		(*FRPanelViewGetName)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewGetTitle */
    /**
     * @brief A callback for navigation panel view.
     * It is called by Foxit Reader to get the panel view's title which is shown in user interface.
     * @param[in] clientData	The user-supplied data.
     * @return A null-determined string correspond the title of panel view.
     * @note    The return title object needs to be a global object, and local objects will get exceptions due to object release.
	 * @deprecated Internal use. Suggest use FRPanelViewGetTitle2.
     */
    FS_LPCWSTR		(*FRPanelViewGetTitle)(FS_LPVOID clientData);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewIsInitialShow */
	/**
	 * @brief  (Windows Only) A callback for navigation panel view.
	 * It is called by Foxit Reader to initialize the panel button show/hide.
	 * @param[in] clientData    The user-supplied data.
	 * @return  if <a>TRUE</a>, Foxit Reader will Initial Show the icon.
	 */
	FS_BOOL			(*FRPanelViewIsInitialShow)(FS_LPVOID clientData);
	/* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewInitNewView */
    /**
     * @brief A callback for navigation panel view. It is called when a PDF document is open and to be displayed. The plug-in can init the
     * data of the panel view in this callback. Then create the window attached to the panel view in <a>FRPanelViewOnPanelActive</a>.
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FPD_Document</a> associated with the created window.
     * @param[in] window		The parent window.
     * @return void.
     * @note
     */
    void			(*FRPanelViewInitNewView)(FS_LPVOID clientData, FPD_Document doc, FS_HWND window);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewOnPanelActive */
    /**
     * @brief A callback for navigation panel view. It creates a window to attach to navigation panel.
	 * Using the window API function <Italic>CreateWindow</Italic>
	 * or <Italic>CreateWindowEx</Italic> to create a window for returning.
	 * @param[in] clientData	The user-supplied data.
     * @return A new window.
     * @note  That interface has deprecated.
     */
    FS_HWND			(*FRPanelViewOnPanelActive)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewOnActive */
    /**
     * @brief				A callback for navigation panel view. It is called when a panel view becomes a active view.
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The <a>FPD_Document</a> associated with the active view.
     * @param[in] window		The parent window.
     * @return void
     * @note
     */
    void			(*FRPanelViewOnActive)(FS_LPVOID clientData, FPD_Document doc, FS_HWND window);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewOnRotate */
    /**
     * @brief A callback for navigation panel view to rotate.
     * It is called after the page view is rotated. You should do some rotation with the panel view.
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc		The <a>FPD_Document</a> associated with the created window.
	 * @param[in] nRotate	The rotation flag. See <a>FR_RotationFlags</a> group.
     * @return void
     * @note
     */
	void			(*FRPanelViewOnRotate)(FS_LPVOID clientData, FPD_Document doc, FS_INT32 nRotate);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewOnDestroyView */
    /**
     * @brief A callback for navigation panel view.
     * It is called at the shutdown time of panel view to free dynamic memory. The panel view should be destroyed in this method.
     * @param[in] clientData	The user-supplied data.
     * @param[in] window	The panel view to destroy.
     * @param[in] doc		The <a>FPD_Document</a> associated with current document.
     * @return void
     * @note
     */
    void			(*FRPanelViewOnDestroyView)(FS_LPVOID clientData, FS_HWND window, FPD_Document doc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewIsDockToBottom */
    /**
     * @brief A callback for navigation panel view.
     * It is called to tell Foxit Reader whether the panel view need to dock bottom.
     * @param[in] clientData	The user-supplied data.
     * @return	if <a>TRUE</a>, Foxit Reader will dock the panel view at the bottom, otherwise at the left.
     * @note
     */
	FS_BOOL			(*FRPanelViewIsDockToBottom)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewGetButtonTip */
    /**
     * @brief A callback for navigation panel view to pass the tip of panel button.
     * Gets the tip of panel button that displaying on the left bar of panel.
     * @param[in] clientData	The user-supplied data.
     * @param[in] csOutTip	(Passed by reader, filled by this method) The buffer to fill with the tip.
     * @note
     */
    void			(*FRPanelViewGetButtonTip)(FS_LPVOID clientData, FS_WideString* csOutTip);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewGetButtonDescriptText */
    /**
     * @brief A callback for navigation panel view to tell the describe text.
     * Gets the describe text of panel view. The describe text will be displayed on the
     * left corner of status bar when the mouse over the panel button. This interface is not available in version 1.0.
     * @param[in] clientData	The user-supplied data.
     * @param[in] csOutText		(Passed by reader, filled by this method) The buffer to fill with the text.
     * @return
     * @note
     */
	void			(*FRPanelViewGetButtonDescriptText)(FS_LPVOID clientData, FS_WideString* csOutText);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewGetButtonIcon */
    /**
     * @brief A callback for navigation panel view to get the icon of panel button.
     * The bitmap returned by this method will be taken by Reader, client can not release it
     * until user exit Reader.
     * @param[in] clientData	The user-supplied data.
     * @return A <a>FS_DIBitmap</a>. The size of bitmap is 24 * 24.
     * @note
     */
    FS_DIBitmap		(*FRPanelViewGetButtonIcon)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewSetPos */
    /**
     * @brief A callback for navigation panel view to locate the navigation item(such as bookmark item).
     * It is called when user scroll a page view or go to other pages.
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc		The <a>FPD_Document</a> associated with the created window.
     * @param[in] nPage		The index of current page.
     * @return 			
     * @note   The interface has deprecated.
     */
    void			(*FRPanelViewSetPos)(FS_LPVOID clientData, FPD_Document doc, FS_INT32 nPage);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewGetButton16Icon */
    /**
	* @brief A callback for navigation panel view to get the icon of panel button.
    * The bitmap returned by this method will be taken by Reader, client can not release it
    * until user exit Reader.
    * @param[in] clientData	The user-supplied data.
	* @return A <a>FS_DIBitmap</a>. The size of bitmap is 16 * 16.
    * @note
    */
    FS_DIBitmap(*FRPanelViewGetButton16Icon)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewGetButton36Icon */
    /**
	* @brief A callback for navigation panel view to get the icon of panel button.
    * The bitmap returned by this method will be taken by Reader, client can not release it
    * until user exit Reader.
    * @param[in] clientData	The user-supplied data.
	* @return A <a>FS_DIBitmap</a>. The size of bitmap is 36 * 36.
    * @note
    */
    FS_DIBitmap(*FRPanelViewGetButton36Icon)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewGetButton32Icon */
    /**
	* @brief A callback for navigation panel view to get the icon of panel button.
    * The bitmap returned by this method will be taken by Reader, client can not release it
    * until user exit Reader.
    * @param[in] clientData	The user-supplied data.
	* @return A <a>FS_DIBitmap</a>. The size of bitmap is 32 * 32.
    * @note
    */
    FS_DIBitmap(*FRPanelViewGetButton32Icon)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewGetButton48Icon */
    /**
	* @brief A callback for navigation panel view to get the icon of panel button.
    * The bitmap returned by this method will be taken by Reader, client can not release it
    * until user exit Reader.
    * @param[in] clientData	The user-supplied data.
	* @return A <a>FS_DIBitmap</a>. The size of bitmap is 48 * 48.
    * @note
    */
    FS_DIBitmap(*FRPanelViewGetButton48Icon)(FS_LPVOID clientData);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewOnGetHwnd */
	/**
	 * @brief A callback for navigation panel view to get windows.
	 * @param[in] clientData  The user-supplied data.
	 * @param[in] doc    The <a>FPD_Document</a> associated with the created window.
	 * @param[in] parent  The parent window.
	 * @return panel view window.
	 * @note Only available in MacOS
	 */
	FS_HWND(*FRPanelViewOnGetHwnd)(FS_LPVOID clientData, FPD_Document doc, FS_HWND parent);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewRefreshView */
	/**
	 * @brief A callback for navigation panel view to refresh view
	 * @param[in] clientData  The user-supplied data.
	 * @param[in] doc    The <a>FPD_Document</a> associated with the created window.
	 * @param[in] parent  The parent window.
	 * @return
	 * @note
	 */
	void(*FRPanelViewRefreshView)(FS_LPVOID clientData, FPD_Document doc, FS_HWND parent);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewGetLayerPanelViewStatus2 */
	/**
	 * @brief A callback for navigation panel view to get status
	 * @param[in] clientData  The user-supplied data.
	 * @param[in] doc           The <a>FPD_Document</a> associated with the created window.
	 * @param[in] parent        The parent window.
	 * @param[out] ocgArr1      The output status array key.
	 * @param[out] ocgArr2      The output status array value.
	 * @return
	 * @note
	 */
	void(*FRPanelViewGetLayerPanelViewStatus2)(FS_LPVOID clientData, FPD_Document doc, FS_HWND parent, FS_PtrArray ocgArr1, FS_PtrArray ocgArr2);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewSetLayerPanelViewState */
	/**
	 * @brief   A callback for navigation panel view to Set status
	 * @param[in] clientData  The user-supplied data.
	 * @param[in] doc    The <a>FPD_Document</a> associated with the created window.
	 * @param[in] parent  The parent window.
	 * @param[in] pDic      The layer panel view dictionary.
	 * @return
	 * @note
	 */
	void(*FRPanelViewSetLayerPanelViewState)(FS_LPVOID clientData, FPD_Document doc, FS_HWND parent, FPD_Object pDic);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewCheckLayerVisible */
	/**
	 * @brief A callback for navigation panel view to check layer visble.
	 * @param[in] clientData 	The user-supplied data.
	 * @param[in] doc 			The <a>FPD_Document</a> associated with the created window.
	 * @param[in] parent 		The parent window.
	 * @param[in] pDic    		The layer panel view dictionary.
	 * @param[out] bFind    	Is find the layer on the dictionary;
	 * @return FS_BOOL 		Whether to layer is visible.
	 * @note
	 */
	FS_BOOL(*FRPanelViewCheckLayerVisible)(FS_LPVOID clientData, FPD_Document doc, FS_HWND parent, FPD_Object pDic, FS_BOOL& bFind);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewGetButtonIconUnion */
	/**
	* @brief A callback for navigation panel view to get the icon of panel button.
	* The bitmap returned by this method will be taken by Reader, client can not release it
	* until user exit Reader.
	* @param[in] clientData	The user-supplied data.s
	* @param[in] mode	app mode
	* @param[in] state	btn state.
	* @param[in] size	icon size.
	* @return A <a>FS_DIBitmap</a>.
	* @note
	*/
	FS_DIBitmap(*FRPanelViewGetButtonIconUnion)(FS_LPVOID clientData, FS_APPMODE mode, FS_BTNSTATE state, FS_ICONSIZE size);
	/* @CALLBACKEND */


	 /* @CALLBACKSTART FRPanelViewOnPanelActive2 */
	/**
	 * @brief A callback for navigation panel view. It creates a window to attach to navigation panel.
	 * Using the window API function <Italic>CreateWindow</Italic>
	 * or <Italic>CreateWindowEx</Italic> to create a window for returning.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] doc		The <a>FPD_Document</a> associated with the created window.
	 * @param[in] parent	The parent window.
	 * @return  FS_HWND  A new window.
	 * @note
	 */
	FS_HWND(*FRPanelViewOnPanelActive2)(FS_LPVOID clientData, FPD_Document doc, FS_HWND parent);
	/* @CALLBACKEND */

    /* @CALLBACKSTART FRPanelViewSetPos2 */
    /**
    * @brief A callback for navigation panel view to locate the navigation item(such as bookmark item).
    * It is called when user scroll a page view or go to other pages.
    * @param[in] clientData  The user-supplied data.
    * @param[in] doc    The <a>FPD_Document</a> associated with the created window.
    * @param[in] parent  The parent window.
    * @param[in] nPage    The index of current page.
    * @return
    * @note
    */
    void(*FRPanelViewSetPos2)(FS_LPVOID clientData, FPD_Document doc, FS_HWND parent, FS_INT32 nPage);
    /* @CALLBACKEND */


	/* @CALLBACKSTART FRPanelViewGetButtonIconUnion */
	/**
	* @brief (Windows Only)A callback for navigation panel view to get the icon of panel button.
	* The bitmap returned by this method will be taken by Reader, client can not release it
	* until user exit Reader.
	* @param[in] clientData	The user-supplied data.s
	* @param[in] mode	app mode
	* @param[in] state	btn state.
	* @param[in] size	icon size.
	* @return A <a>FS_LPWSTR</a> PDF bitmap name
	* @note
	* @deprecated Internal use. Suggest use FRPanelViewGetButtonPDFIconUnion2.
	*/
	FS_LPWSTR(*FRPanelViewGetButtonPDFIconUnion)(FS_LPVOID clientData, FS_APPMODE mode, FS_BTNSTATE state, FS_ICONSIZE size);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewGetPDFBitmapName */
	/**
	* @brief (Windows Only)A callback for navigation panel view to get the pdf bitmap icon of panel button.
	* The bitmap returned by this method will be taken by Reader, client can not release it
	* @param[in] clientData	The user-supplied data.
	* @param[in] size	icon size.
	* @return A <a>FS_LPWSTR</a> PDF bitmap name
	* @note
	* @deprecated Internal use. Suggest use FRPanelViewGetButtonPDFIconUnion2.
	*/
	FS_LPWSTR(*FRPanelViewGetPDFBitmapName)(FS_LPVOID clientData, FS_ICONSIZE size);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewOnPanelDeActive */
	/**
	 * @brief A callback for navigation panel view. It called when switch to other tab panel.	
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] doc		The <a>FPD_Document</a> associated with the created window.
	 * @param[in] parent	The parent window.
	 * @return void
	 */
	void(*FRPanelViewOnPanelDeActive)(FS_LPVOID clientData, FPD_Document doc, FS_HWND parent);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewGetName2 */
	/**
	 * @brief	A callback for navigation panel view. It is called by Foxit Reader to get the panel view's name.
	 * @param[in] clientData	The user-supplied data.
	 * @param[out] bsName	    Get the panel name.
	 * @return	A null-determined string correspond the name of panel view.
	 * @note The return name object needs to be a global object, and local objects will get exceptions due to object release
	 */
	void(*FRPanelViewGetName2)(FS_LPVOID clientData, FS_ByteString* bsName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewGetTitle2 */
	/**
	 * @brief A callback for navigation panel view.
	 * It is called by Foxit Reader to get the panel view's title which is shown in user interface.
	 * @param[in] clientData	The user-supplied data.
	 * @param[out] clientData	Get the panel title.
	 * @return A null-determined string correspond the title of panel view.
	 * @note    The return title object needs to be a global object, and local objects will get exceptions due to object release
	 */
	void(*FRPanelViewGetTitle2)(FS_LPVOID clientData,FS_WideString* wsTitle);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewGetButtonPDFIconUnion2 */
	/**
	* @brief (Windows Only)A callback for navigation panel view to get the icon of panel button.
	* The bitmap returned by this method will be taken by Reader, client can not release it
	* until user exit Reader.
	* @param[in] clientData	The user-supplied data.s
	* @param[in] mode	app mode
	* @param[in] state	btn state.
	* @param[in] size	icon size.
	* @param[out] wsIconname	get the pdf bitmap name.
	* @return A <a>FS_LPWSTR</a> PDF bitmap name.
	* @note
	*/
	void(*FRPanelViewGetButtonPDFIconUnion2)(FS_LPVOID clientData, FS_APPMODE mode, FS_BTNSTATE state, FS_ICONSIZE size,FS_WideString* wsIconname);
	/* @CALLBACKEND */	

	/* @CALLBACKSTART FRPanelViewGetActivePDFBitmapName */
	/**
	* @brief (Windows Only)A callback for navigation panel view to get the bitmap name when
	* activate the panel.
	* @param[in] clientData	The user-supplied data.	
	* @param[out] wsPDFBitmapName	Get the pdf bitmap name.
	* @return A <a>FS_LPWSTR</a> PDF bitmap name.
	* @note
	*/
	void(*FRPanelViewGetActivePDFBitmapName)(FS_LPVOID clientData, FS_WideString* wsPDFBitmapName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewOnPanelTabKeyDown */
	/**
	* @brief (Windows Only)A callback for navigation panel view click tab down.
	* @param[in] clientData	The user-supplied data.
	* @param[in] bShift  	TRUE: click shift.
	* @return A <a>FS_BOOL</a> .
	* @note
	*/
	FS_BOOL(*FRPanelViewOnPanelTabKeyDown)(FS_LPVOID clientData, FS_BOOL bShift);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewOnPanelEnterKeyDown */
	/**
	* @brief (Windows Only)A callback for navigation panel view click key down.
	* @param[in] clientData	The user-supplied data.
	* @return void
	* @note
	*/
	void(*FRPanelViewOnPanelEnterKeyDown)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelViewOnPanelGetMenuItemLabel */
	/**
	 * @brief A callback for navigation panel view.
	 * It is called by Foxit Reader to get the panel view's menu label.
	 * @param[in] clientData	The user-supplied data.
	 * @param[out] clientData	Get the panel menu label.
	 * @return A null-determined string correspond the menu of panel view, it includes shortcuts.
	 * @note    The return title object needs to be a global object, and local objects will get exceptions due to object release
	 */
	void(*FRPanelViewOnPanelGetMenuItemLabel)(FS_LPVOID clientData, FS_WideString* wsMenuLabel);
	/* @CALLBACKEND */
}FR_PanelViewCallbacksRec, *FR_PanelViewCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_DocPropertypageCallbacks */
/**
 * @brief A callback set for document-level property dialog. Using this callback set, a new property page can be attached to
 * the document-level property dialog, and the event occurred when user click the <Italic>OK</Italic> button is sent to client.
 * See <a>FRAppRegisterDocPropertyPageHandler</a>, <a>FRAppAddDocPropertyPage</a>.
 */
typedef struct _fr_docpropertypage_callbacks_ 
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DocPropertypageCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	/* @CALLBACKSTART FRDocPropertyPageOnCreate */
	/**
     * @brief A callback for document-property-page handler.
	 * It is called after the property dialog is created. Client should create a new property page and
	 * register it using <a>FRAppAddDocPropertyPage</a>() in this method.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] window		The parent dialog.
     * @note
     */
    void	(*FRDocPropertyPageOnCreate)(FS_LPVOID clientData, FS_HWND window);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocPropertyPageOnDestroy */
	/**
     * @brief A callback for document-property-page handler.
	 * It is called when user closes the property dialog. Client should destroy the property page window and
	 * free dynamic memory in this method.
	 * @param[in] clientData	The user-supplied data.
     * @note
     */
	void	(*FRDocPropertyPageOnDestroy)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDocPropertyPageOnSaveData */
	/**
     * @brief A callback for document-property-page handler.
	 * It is called when user click the <Italic>OK</Italic> button on the property dialog.	
	 * @param[in] clientData	The user-supplied data.
     * @note
     */
	void	(*FRDocPropertyPageOnSaveData)(FS_LPVOID clientData);
	/* @CALLBACKEND */

}FR_DocPropertypageCallbacksRec, *FR_DocPropertypageCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_PreferPageCallbacks */
/**
* @brief A callback set for preferences dialog. Using this callback set, a new preference page can be attached to
* the preferences dialog, and the event occurred when user click the <Italic>OK</Italic> button is sent to client.
* See <a>FRAppRegisterPreferencePageHandler</a>, <a>FRAppAddPreferencePage</a>.
*/
typedef struct _fr_preferencepage_callbacks
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_PreferPageCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;


    /* @CALLBACKSTART FRPrefPageOnCreate */
    /**
     * @brief A callback for Reader preference page.
	 * It is called after the preference dialog is created. Client should create a new preference page and
	 * register it using <a>FRAppAddPreferencePage</a>() in this method.
	 * @param[in] clientData	The user-supplied data.
     * @param[in] window		The parent dialog.
     * @note
     */
    void	(*FRPrefPageOnCreate)(FS_LPVOID clientData, FS_HWND window);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPrefPageOnDestroy */
    /**
     * @brief A callback for Reader preference page.
     * It is called when user closes the preference dialog. Client should destroy the preference page window and
     * free dynamic memory in this method.
     * @param[in] clientData	The user-supplied data.
     * @note
     */
    void    (*FRPrefPageOnDestroy)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPrefPageOnSaveData */
    /**
     * @brief A callback for Reader preference page. It is called when user clicks the <Italic>OK</Italic> button on the property dialog.
     * @param[in] clientData	The user-supplied data.
     * @note
     */
    void    (*FRPrefPageOnSaveData)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPrefPageOnGetTabTitle */
    /**
     * @brief It is called by Foxit Reader to get the title of the preference page tab.
     * @param[in] clientData	The user-supplied data.
     * @param[out] wsTitle		The title of tab.
     * @note
     */
    void    (*FRPrefPageOnGetTabTitle)(FS_LPVOID clientData, FS_WideString wsTitle);
    /* @CALLBACKEND */

}FR_PreferPageCallbacksRec, *FR_PreferPageCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKSTART FRPopUpMenuProc */
/**
 * @brief A callback that is called when the context menu is popped up in the doc view.
 *
 * @param[in] pClientData		User-supplied data that was passed when <a>FRToolButtonSetClientData</a>() or
 * <a>FRMenuItemSetClientData</a>() was called.
 * @param[in] popUpMenu			The menu popped up.
 * @return void
 * @note
 */
typedef void (*FRContextMenuPopUpProc)(void *pClientData, FR_Menu popUpMenu);
/* @CALLBACKEND */

/* @DEFGROUPSTART SelectionType */
/*
* @brief Definitions for selection type. See <a>FRSelectionGetType</a>.
* 
*/
/*@{*/
/** @brief The selection type of <Italic>Text</Italic>*/
#define FR_ST_TEXT			"Text"
/** @brief The selection type of <Italic>Bitmap</Italic>*/
#define FR_ST_BITMAP		"Bitmap"
/** @brief The selection type of <Italic>Annotation</Italic>*/
#define FR_ST_ANNOTATION	"Annotation"
/** @brief The selection type of <Italic>Thumbnail</Italic>*/
#define FR_ST_THUMBNAIL		"Thumbnail"
/** @brief The selection type of <Italic>Bookmark</Italic>*/
#define FR_ST_BOOKMARK		"Bookmark"
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKGROUPSTART FR_SelectionCallbacks */
/**
* @brief A callback set for selection handler. The callbacks implement the
* selection handler functions. For example, they can add an item to the selection, remove an item from the
* selection, or copy the current selection to the clipboard. See <a>FRAppRegisterSelectionHandler</a>.
*/
typedef struct _fr_selection_callbacks
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_SelectionCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

	/* @CALLBACKSTART FRSelectionGetType */
	/**
	* @brief	 It returns the selection type (for example, 'Text' or 'Bookmark'). 
	*            This information is used so that the Foxit Reader knows which selection handler to call.
	 * @param[in]	clientData	The user-supplied data.
	 * @return		The selection type. It is set to <a>SelectionType</a>
	 * @note
     */
    FS_LPSTR	(*FRSelectionGetType)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionCanSelectAll */
    /**
    * @brief		 It is used to determine whether the current selection type can perform a select all operation.
    *				 This controls whether the Select All menu item is enabled.
     * @param[in]	clientData		The user-supplied data.
     * @param[in]	document		The document containing the current selection.
     * @param[in]	curSelectData	The current selection's data.
     * @return		<a>TRUE</a> if select all can be performed on the current selection type, <a>FALSE</a> otherwise.
     * @note
     */
    FS_BOOL	(*FRSelectionCanSelectAll)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionDoSelectAll */
    /**
     * @brief It is called to perform the select all operation.
     * @param[in]		clientData		The user-supplied data.
     * @param[in,out]	document		The document in which the <Italic>Select All</Italic> is performed.
     * @param[in,out]	curSelectData	The current selection data in doc.
     * @return
     * @note
     */
    void	(*FRSelectionDoSelectAll)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionCanDelete */
    /**
    * @brief		It is used to determine whether the current selection can be deleted.
     *				This controls, for example, whether the <Italic>Delete</Italic> menu item is enabled.
     * @param[in]	clientData		The user-supplied data.
     * @param[in]	document		The document containing the current selection.
     * @param[in]	curSelectData	The current selection data.
     * @return		<a>TRUE</a> if the current selection can be deleted, <a>FALSE</a> otherwise.
     * @note
     */
    FS_BOOL	(*FRSelectionCanDelete)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionDoDelete */
    /**
     * @brief		It deletes the current selection.
     * @param[in]		clientData		The user-supplied data.
     * @param[in,out]	document		Document whose selection is deleted.
     * @param[in,out]	curSelectData	The current selection in doc.
     * @return
     * @note
     */
    void	(*FRSelectionDoDelete)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionCanCopy */
    /**
    * @brief	It is used to determine whether the current selection can be copied.
     *			This controls, for example, whether the <Italic>Copy</Italic> menu item is enabled.
     * @param[in]		clientData		The user-supplied data.
     * @param[in,out]	document		The document containing the selection.
     * @param[in,out]	curSelectData	The current selection data.
     * @return	<a>TRUE</a> if the current selection can be copied, <a>FALSE</a> otherwise.
     * @note
     */
    FS_BOOL	(*FRSelectionCanCopy)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionDoCopy */
    /**
     * @brief It copies the selected item to the clipboard.
     *
     * The Foxit Reader viewer will
     * have already cleared the clipboard and placed some private data onto it, in order to identify the selection
     * handler that put data on the clipboard. Because of this, a plug-in must not clear the clipboard, and should
     * only add its private data. In addition, if the current selection can be reasonably represented as text,
     * plug-ins are strongly encouraged to place a text representation of the selection onto the clipboard, in
     * addition to their own private format.
     * @param[in]		clientData		The user-supplied data.
     * @param[in,out]	document		The document whose selection is copied.
     * @param[in,out]	curSelectData	The current selection data in doc.
     * @return
     * @note
     */
    void (*FRSelectionDoCopy)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionCanCut */
    /**
    * @brief	 It is used to determine whether the current selection can be cut.
    * This controls, for example, whether the <Italic>Cut</Italic> menu item is enabled.
     * @param[in]	clientData		The user-supplied data.
     * @param[in]	document		The document containing the current selection.
     * @param[in]	curSelectData	The current selection data.
     * @return <a>TRUE</a> if the current selection can be cut, <a>FALSE</a> otherwise.
     * @note
     */
    FS_BOOL (*FRSelectionCanCut)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionDoCut */
    /**
    * @brief	It cuts the current selection. See the discussion under
     * <a>FRSelectionDoCopy</a>() for information on how the selection handler must use the clipboard.
     * @param[in]		clientData		The user-supplied data.
     * @param[in,out]	document		Document whose selection is cut.
     * @param[in,out]	curSelectData	The current selection data in doc.
     * @return
     * @note
     */
    void	(*FRSelectionDoCut)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionCanPaste */
    /**
    * @brief	It is used to determine whether the current selection can be pasted.
     * This controls, for example, whether the <Italic>Paste</Italic> menu item is enabled.
     * @param[in]	clientData		The user-supplied data.
     * @param[in]	document		The document into which the selection is pasted.
     * @return <a>TRUE</a> if the data currently on the clipboard can be pasted, <a>FALSE</a> otherwise.
     * @note
     */
    FS_BOOL	(*FRSelectionCanPaste)(FS_LPVOID clientData, FR_Document document);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionDoPaste */
    /**
     * @brief			It pastes the current selection from the clipboard.
     * @param[in]		clientData		The user-supplied data.
     * @param[in,out]	document		The document into whose selection the clipboard is pasted.
     * @return
     * @note
     */
    void	(*FRSelectionDoPaste)(FS_LPVOID clientData, FR_Document document);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionLosingSelection */
    /**
    * @brief	This method is called by <a>FRSelectionClearSelection</a> (among others), to let the selection handler responsible
     * for the old selection do whatever cleanup it needs.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		document		The document whose selection is cleared.
     * @param[in]		curSelectData	The current selection data in doc.
     * @return
     * @note
     */
    void	(*FRSelectionLosingSelection)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionGettingSeletion */
    /**
    * @brief	 It is called when the selection is set (for example, via FRSelectionSetCurSelection()).
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		document		The document containing the selection.
     * @param[in]		curSelectData	The selection data being added.
     * @return
     * @note
     */
    void	(*FRSelectionGettingSeletion)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionRemovedFromSelection */
    /**
    * @brief	 A callback that de-highlights the old item given in remData, and returns a new
     * <param>curSelectData</param> or <a>NULL</a> if failure occurred.
     * @param[in]			clientData		The user-supplied data.
     * @param[in,out]		document		The document in which an item is removed from the selection.
     * @param[in,out]		curSelectData	The current selection data.
     * @param[in,out]		remData			The item to remove from the selection. The content and format of selData differs
     * for each selection handler, and are decided by the selection handler's implementors.
     * @return The new selection data after the specified item has been removed.
     * @note
     */
    void*	(*FRSelectionRemovedFromSelection)(FS_LPVOID clientData, FR_Document document, void* curSelectData, void* remData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionAddedToSelection */
    /**
    * @brief	 A callback that adds the specified item to the selection, highlights it, and returns
     * the new selection containing the newly-added item.
     * @param[in]			clientData		The user-supplied data.
     * @param[in,out]		document		The document containing the data to add to the selection.
     * @param[in,out]		curSelectData	Data representing the current selection. Its format is specific to the selection handler.
     * @param[in,out]		addData			The item to add to the selection.
     * @return New selection data containing all current selections (that is, the previous selection plus the newly-added
     * selection), or <a>NULL</a> if failure occurred. If the selection handler allows only a single item to be selected at a
     * time, clear the previous selection, highlight the selection specified by <param>addData</param> (if highlight is true),
     * and simply return <param>addData</param>.
     * @note
     */
    void*	(*FRSelectionAddedToSelection)(FS_LPVOID clientData, FR_Document document, void* curSelectData, void* addData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionShowSelection */
    /**
    * @brief	  It changes the view (for example, by scrolling the current page or
     * moving to the appropriate page) so that the current selection is visible.
     * @param[in]			clientData		The user-supplied data.
     * @param[in,out]		document		The document whose selection is displayed.
     * @param[in,out]		curSelectData	The current selection data in doc.
     * @return
     * @note
     */
    void	(*FRSelectionShowSelection)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionKeyDown */
    /**
    * @brief	  It handles a key press. It is needed only if the selection handler processes key presses.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		document		The document in which the click occurred.
     * @param[in]		curSelectData	The current selection data for doc.
     * @param[in]		nKeyCode		The key that was pressed.
     * @param[in]		nFlags			Modifier keys that were pressed with key. It must be an OR of the Modifier Keys values.
     * @return <a>TRUE</a> if it the keypress was handled, <a>FALSE</a> if it was not and therefore needs to be passed to the next
     * procedure in the key handling chain.
     * @note
     */
    FS_BOOL	(*FRSelectionKeyDown)(FS_LPVOID clientData, FR_Document document, void* curSelectData, unsigned int nKeyCode, unsigned int nFlags);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionKeyUp */
    /**
    * @brief	  It handles a key press. It is needed only if the selection handler processes key presses.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		document		The document in which the click occurred.
     * @param[in]		curSelectData	The current selection data for doc.
     * @param[in]		nKeyCode		The key that was pressed.
     * @param[in]		nFlags			Modifier keys that were pressed with key. It must be an OR of the Modifier Keys values.
     * @return <a>TRUE</a> if it the keypress was handled, <a>FALSE</a> if it was not and therefore needs to be passed to the next
     * procedure in the key handling chain.
     * @note
     */
    FS_BOOL	(*FRSelectionKeyUp)(FS_LPVOID clientData, FR_Document document, void* curSelectData, unsigned int nKeyCode, unsigned int nFlags);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionKeyChar */
    /**
    * @brief It handles a key press. It is needed only if the selection handler processes key presses.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		document		The document in which the click occurred.
     * @param[in]		curSelectData	The current selection data for doc.
     * @param[in]		nChar			Contains the character code value of the key.
     * @param[in]		nFlags			Contains the scan code, key-transition code, previous key state, and context code.
     * @return <a>TRUE</a> if it the keypress was handled, <a>FALSE</a> if it was not and therefore needs to be passed to the next
     * procedure in the key handling chain.
     * @note
     */
    FS_BOOL	(*FRSelectionKeyChar)(FS_LPVOID clientData, FR_Document document, void* curSelectData, unsigned int nChar, unsigned int nFlags);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionMouseWheel */
    /**
    * @brief It handles a mouse wheeling. It is needed only if the selection handler processes mouse wheeling.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		pageView		The page view in which the mouse wheeling occurred.
     * @param[in]		curSelectData	The current selection data for doc.
     * @param[in]		nFlags			Indicates whether various virtual keys are down.
     * @param[in]		point			Specifies the x- and y-coordinate of the cursor.
     *                                  These coordinates are always relative to the upper-left corner of the window.
     * @return <a>TRUE</a> if the mouse wheeling was handled, otherwise not.
     * @note
     */
    FS_BOOL	(*FRSelectionMouseWheel)(FS_LPVOID clientData, FR_PageView pageView, void* curSelectData, unsigned int nFlags, const FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionCanDeselectAll */
    /**
    * @brief It is used to determine whether all the current selections can be deselected.
    * This controls, for example, whether the <Italic>Deselect All</Italic> menu item is enabled.
    * @param[in]	clientData		The user-supplied data.
    * @param[in]	document		The document containing the current selection.
    * @param[in]	curSelectData	The current selection data.
    * @return <a>TRUE</a> if all the data currently can be deselected, <a>FALSE</a> otherwise.
    * @note
    */
    FS_BOOL (*FRSelectionCanDeselectAll)(FS_LPVOID clientData, FR_Document document,void* curSelectData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSelectionDoDeselectAll */
    /**
    * @brief It deselects all the items selected.
    * @param[in]	clientData		The user-supplied data.
    * @param[in]	document		The document containing the current selection.
    * @param[in]	curSelectData	The current selection data.
    * @return void.
    * @note
    */
    void	(*FRSelectionDoDeselectAll)(FS_LPVOID clientData, FR_Document document, void* curSelectData);
    /* @CALLBACKEND */


	/* @CALLBACKSTART FRSelectionCanPaste */
	/**
	* @brief	It is used to determine whether the current selection can be pasted.
	 * This controls, for example, whether the <Italic>Paste</Italic> menu item is enabled.
	 * @param[in]	clientData		The user-supplied data.
	 * @param[in]	document		The document into which the selection is pasted.
	 * @return <a>TRUE</a> if the data currently on the clipboard can be pasted, <a>FALSE</a> otherwise.
	 * @note
	 */
	FS_BOOL(*FRCanOtherPaste)(FS_LPVOID clientData, FR_Document document);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTwAonntLosingEdit */
	/**
	* @brief	It is used to exit freetext annot.
	* 
	 * @param[in]	clientData		The user-supplied data.
	 * @param[in]	document		The document into which the selection is pasted.
	 * @param[in]	pAnnot		    The input FR_Annot.
	 * @return void
	 * @note
	 */
	void(*FRTwAonntLosingEdit)(FS_LPVOID clientData, FR_Document document, FR_Annot pAnnot);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSelectionLosingSelection2 */
	/**
	* @brief	This method is called by <a>FRSelectionClearSelection</a> (among others), to let the selection handler responsible
	 * for the old selection do whatever cleanup it needs.
	 * @param[in]		clientData		The user-supplied data.
	 * @param[in]		document		The document whose selection is cleared.
	 * @param[in]		curSelectData	The current selection data in doc.
	 * @param[in]		bSave	        If save the edit.
	 * @return
	 * @note
	 */
	void(*FRSelectionLosingSelection2)(FS_LPVOID clientData, FR_Document document, void* curSelectData, FS_BOOLEAN bSave);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSelectionDoPasteInPlace */
	/**
	* @brief	This method is called by <a>FRSelectionDoPasteInPlace</a> (among others), to let the selection handler responsible
	 * for the old selection do whatever cleanup it needs.
	 * @param[in]		clientData		The user-supplied data.
	 * @param[in]		document		The document whose selection is do paste.	
	 * @return
	 * @note
	 */
	void(*FRSelectionDoPasteInPlace)(FS_LPVOID clientData, FR_Document document);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSelectionCanPasteInPlace */
	/**
	* @brief	This method is called by <a>FRSelectionCanPasteInPlace</a> (among others), to let the selection handler responsible
	 * for the old selection do whatever cleanup it needs.
	 * @param[in]		clientData		The user-supplied data.
	 * @param[in]		document		The document whose selection is do paste.
	 * @return
	 * @note
	 */
	FS_BOOLEAN(*FRSelectionCanPasteInPlace)(FS_LPVOID clientData, FR_Document document);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSelectionCanOtherPasteInPlace */
	/**
	* @brief	This method is called by <a>FRSelectionCanOtherPasteInPlace</a> (among others), to let the selection handler responsible
	 * for the old selection do whatever cleanup it needs.
	 * @param[in]		clientData		The user-supplied data.
	 * @param[in]		document		The document whose selection is do paste.
	 * @return
	 * @note
	 */
	FS_BOOLEAN(*FRSelectionCanOtherPasteInPlace)(FS_LPVOID clientData, FR_Document document);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSelectionPreKeyDown */
	/**
	* @brief	This method is called by <a>FRSelectionPreKeyDown</a> (among others), to let the selection handler responsible
	 * for the old selection do whatever cleanup it needs.
	 * @param[in]clientData		The user-supplied data.
	 * @param[in]document		The document whose selection is do paste.
	 * @param[in]curSelectData	The current select data.
	 * @param[in]nVriKey		The current input key.
	 * @return
	 * @note
	 */
	FS_BOOLEAN(*FRSelectionPreKeyDown)(FS_LPVOID clientData, FR_Document pDocument, FS_LPVOID curSelectData, FS_UINT nVriKey);
	/* @CALLBACKEND */
}FR_SelectionCallbacksRec, *FR_SelectionCallbacks;
/* @CALLBACKGROUPEND */

/* @DEFGROUPSTART CaptureType */
/*
* @brief Definitions for capture type. See <a>FRCaptureGetType</a>.
*/

/*@{*/
/** @brief The capture type of <Italic>Annotation</Italic>.*/
#define FR_CT_ANNOTATION			"Annotation"
/** @brief The capture type of <Italic>Touchup</Italic>.*/
#define FR_CT_TOUCHUP				"Touchup"
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKGROUPSTART FR_CaptureCallbacks */
/**
* @brief A callback set for capture handler. These callbacks implement a capture handler. The callbacks implement the 
* capture handler functions. See <a>FRAppRegisterCaptureHandler</a>.
* @depercated Internal use.
*/
typedef struct _fr_capture_callbacks
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_CaptureCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

	/* @CALLBACKSTART FRCaptureGetType */
	/**
	* @brief It is called to get the capture type. See the group definition <a>CaptureType</a>.
	 * @param[in]		clientData		The user-supplied data.
	 * @return The capture type <a>CaptureType</a>
	 * @note
     */
    FS_LPSTR (*FRCaptureGetType)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCaptureLosingCapture */
    /**
    * @brief It is called by Foxit Reader to notify that the current capture handler is losing capture.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		document		The input document whose capture handler is losing capture.
     * @param[in]		curCaptureData	The current capture data for doc.
     * @return
     * @note
     */
    void (*FRCaptureLosingCapture)(FS_LPVOID clientData, FR_Document document, void* curCaptureData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCaptureGettingCapture */
    /**
    * @brief It is called by Foxit Reader to notify that the current capture handler is getting capture.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		document		The input document whose capture handler is getting capture.
     * @param[in]		curCaptureData	The current capture data for doc.
     * @return
     * @note
     */
    void (*FRCaptureGettingCapture)(FS_LPVOID clientData, FR_Document document, void* curCaptureData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCaptureLButtonDown */
    /**
    * @brief It is called by Foxit Reader to notify the left-button-down event.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		pageView		The input page view whose left-button-down event occurred.
     * @param[in]		curCaptureData	The current capture data for doc.
     * @param[in]		nFlags			Indicates whether various virtual keys are down.
     * @param[in]		point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return <a>TRUE</a> if the left-button-down event was handled, otherwise not.
     * @note
     */
    FS_BOOL (*FRCaptureLButtonDown)(FS_LPVOID clientData, FR_PageView pageView, void* curCaptureData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCaptureLButtonUp */
    /**
    * @brief	It is called by Foxit Reader to notify the left-button-up event.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		pageView		The input page view whose left-button-up event occurred.
     * @param[in]		curCaptureData	The current capture data for doc.
     * @param[in]		nFlags			Indicates whether various virtual keys are down.
     * @param[in]		point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the left-button-up event was handled, otherwise not.
     * @note
     */
    FS_BOOL (*FRCaptureLButtonUp)(FS_LPVOID clientData, FR_PageView pageView, void* curCaptureData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCaptureLButtonDblClk */
    /**
    * @brief	It is called by Foxit Reader to notify the left-button-DblClk event.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		pageView		The input page view whose left-button-DblClk event occurred.
     * @param[in]		curCaptureData	The current capture data for doc.
     * @param[in]		nFlags			Indicates whether various virtual keys are down.
     * @param[in]		point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the left-button-DblClk event was handled, otherwise not.
     * @note
     */
    FS_BOOL (*FRCaptureLButtonDblClk)(FS_LPVOID clientData, FR_PageView pageView, void* curCaptureData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCaptureMouseMove */
    /**
    * @brief	It is called by Foxit Reader to notify the mouse-move event.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		pageView		The input page view whose mouse-move event occurred.
     * @param[in]		curCaptureData	The current capture data for doc.
     * @param[in]		nFlags			Indicates whether various virtual keys are down.
     * @param[in]		point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the left-button-DblClk event was handled, otherwise not.
     * @note
     */
    FS_BOOL (*FRCaptureMouseMove)(FS_LPVOID clientData, FR_PageView pageView, void* curCaptureData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCaptureRButtonDown */
    /**
    * @brief	It is called by Foxit Reader to notify the right-button-down event.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		pageView		The input page view whose right-button-down event occurred.
     * @param[in]		curCaptureData	The current capture data for doc.
     * @param[in]		nFlags			Indicates whether various virtual keys are down.
     * @param[in]		point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the left-button-DblClk event was handled, otherwise not.
     * @note
     */
    FS_BOOL (*FRCaptureRButtonDown)(FS_LPVOID clientData, FR_PageView pageView, void* curCaptureData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCaptureRButtonUp */
    /**
    * @brief	It is called by Foxit Reader to notify the right-button-up event.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		pageView		The input page view whose right-button-up event occurred.
     * @param[in]		curCaptureData	The current capture data for doc.
     * @param[in]		nFlags			Indicates whether various virtual keys are down.
     * @param[in]		point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the left-button-DblClk event was handled, otherwise not.
     * @note
     */
    FS_BOOL (*FRCaptureRButtonUp)(FS_LPVOID clientData, FR_PageView pageView, void* curCaptureData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCaptureRButtonDblClk */
    /**
    * @brief	It is called by Foxit Reader to notify the right-button-DblClk event.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		pageView		The input page view whose right-button-DblClk event occurred.
     * @param[in]		curCaptureData	The current capture data for doc.
     * @param[in]		nFlags			Indicates whether various virtual keys are down.
     * @param[in]		point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return	<a>TRUE</a> if the left-button-DblClk event was handled, otherwise not.
     * @note
     */
    FS_BOOL (*FRCaptureRButtonDblClk)(FS_LPVOID clientData, FR_PageView pageView, void* curCaptureData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRCaptureContextMenu */
	/**
	* @brief	It is called by Foxit Reader to notify the context menu pop-up event.  
	 * @param[in]		clientData		The user-supplied data.
	 * @param[in]		pageView		The input page view whose context menu pop-up event occurred.
	 * @param[in]		point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
	 * @return	<a>TRUE</a> if the context menu pop-up event was handled, otherwise not. 
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 8.3.2
     */
	FS_BOOL (*FRCaptureContextMenu)(FS_LPVOID clientData, FR_PageView pageView, FS_DevicePoint point);
	/* @CALLBACKEND */
}FR_CaptureCallbacksRec, *FR_CaptureCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_MousePtCallbacks */
/**
* @brief A callback set for mouse point handler. It is used to deal with the mouse operations. For example, you can receive mouse events.
* It can be associated to the tool by <a>FRToolSetAssociatedMousePtHandlerType</a>. See <a>FRAppRegisterMousePtHandler</a>.
* @deprecated internal use.
*/
typedef struct _fr_mousept_callbacks
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_MousePtCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRCaptureGetType */
    /**
    * @brief It is called to get the mouse point handler type.
     * @param[in]		clientData		The user-supplied data.
     * @return The type of mouse point handler.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_LPSTR (*FRMousePtGetType)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRMousePtGetObjectAtPoint */
    /**
    * @brief It is called to get the object at the specified point.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		pageView		The input page view whose left-button-down event occurred.
     * @param[in]		point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return The object at the specified point.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void* (*FRMousePtGetObjectAtPoint)(FS_LPVOID clientData, FR_PageView pageView, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRMousePtLButtonDown */
    /**
    * @brief It is called by Foxit Reader to notify the left-button-down event.
     * @param[in]		clientData		The user-supplied data.
     * @param[in]		pageView		The input page view whose left-button-down event occurred.
     * @param[in]		curData			The current data for doc.
     * @param[in]		nFlags			Indicates whether various virtual keys are down.
     * @param[in]		point			Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return <a>TRUE</a> if the left-button-down event was handled, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRMousePtLButtonDown)(FS_LPVOID clientData, FR_PageView pageView, void* curData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRMousePtLButtonUp */
    /**
    * @brief It is called by Foxit Reader to notify the left-button-up event.
     * @param[in]		clientData	The user-supplied data.
     * @param[in]		pageView	The input page view whose left-button-up event occurred.
     * @param[in]		curData		The current data for doc.
     * @param[in]		nFlags		Indicates whether various virtual keys are down. Reference to <Italic>CWnd::OnLButtonUp</Italic>.
     * @param[in]		point		Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return <a>TRUE</a> if the left-button-up event was handled, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRMousePtLButtonUp)(FS_LPVOID clientData, FR_PageView pageView, void* curData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRMousePtLButtonDblClk */
    /**
    * @brief It is called by Foxit Reader to notify the left-button-double-click event.
     * @param[in]		clientData	The user-supplied data.
     * @param[in]		pageView	The input page view whose left-button-double-click event occurred.
     * @param[in]		curData		The current data for doc.
     * @param[in]		nFlags		Indicates whether various virtual keys are down. Reference to <Italic>CWnd::OnLButtonDblClk</Italic>.
     * @param[in]		point		Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return <a>TRUE</a> if the left-button-double-click event was handled, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRMousePtLButtonDblClk)(FS_LPVOID clientData, FR_PageView pageView, void* curData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRMousePtMouseMove */
    /**
    * @brief It is called by Foxit Reader to notify the mouse-move event.
     * @param[in]		clientData	The user-supplied data.
     * @param[in]		pageView	The input page view whose mouse-move event occurred.
     * @param[in]		curData		The current data for doc.
     * @param[in]		nFlags		Indicates whether various virtual keys are down. Reference to <Italic>CWnd::OnMouseMove</Italic>.
     * @param[in]		point		Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return <a>TRUE</a> if the mouse-move event was handled, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRMousePtMouseMove)(FS_LPVOID clientData, FR_PageView pageView, void* curData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRMousePtRButtonDown */
    /**
    * @brief It is called by Foxit Reader to notify the right-button-down event.
     * @param[in]		clientData	The user-supplied data.
     * @param[in]		pageView	The input page view whose right-button-down event occurred.
     * @param[in]		curData		The current data for doc.
     * @param[in]		nFlags		Indicates whether various virtual keys are down. Reference to <Italic>CWnd::OnRButtonDown</Italic>.
     * @param[in]		point		Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return <a>TRUE</a> if the right-button-down event was handled, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRMousePtRButtonDown)(FS_LPVOID clientData, FR_PageView pageView, void* curData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRMousePtRButtonUp */
    /**
    * @brief It is called by Foxit Reader to notify the right-button-up event.
     * @param[in]		clientData	The user-supplied data.
     * @param[in]		pageView	The input page view whose right-button-up event occurred.
     * @param[in]		curData		The current data for doc.
     * @param[in]		nFlags		Indicates whether various virtual keys are down. Reference to <Italic>CWnd::OnRButtonUp</Italic>.
     * @param[in]		point		Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return <a>TRUE</a> if the right-button-up event was handled, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRMousePtRButtonUp)(FS_LPVOID clientData, FR_PageView pageView, void* curData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRMousePtRButtonDblClk */
    /**
    * @brief It is called by Foxit Reader to notify the right-button-double-click event.
     * @param[in]		clientData	The user-supplied data.
     * @param[in]		pageView	The input page view whose right-button-double-click event occurred.
     * @param[in]		curData		The current data for doc.
     * @param[in]		nFlags		Indicates whether various virtual keys are down. Reference to <Italic>CWnd::OnRButtonDblClk</Italic>.
     * @param[in]		point		Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return <a>TRUE</a> if the right-button-double-click event was handled, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRMousePtRButtonDblClk)(FS_LPVOID clientData, FR_PageView pageView, void* curData, unsigned int nFlags, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRMousePtMouseWheel */
    /**
    * @brief It is called by Foxit Reader to notify the mouse-wheel event.
     * @param[in]		clientData	The user-supplied data.
     * @param[in]		pageView	The input page view whose mouse-wheel event occurred.
     * @param[in]		curData		The current data for doc.
     * @param[in]		nFlags		Indicates whether various virtual keys are down. Reference to <Italic>CWnd::OnMouseWheel</Italic>.
     * @param[in]		zDelta		Indicates distance rotated. Reference to <Italic>CWnd::OnMouseWheel</Italic>.
     * @param[in]		point		Specifies the x- and y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the window.
     * @return <a>TRUE</a> if the mouse-wheel event was handled, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRMousePtMouseWheel)(FS_LPVOID clientData, FR_PageView pageView, void* curData, unsigned int nFlags, short zDelta, FS_DevicePoint point);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRMousePtOnMouseEnter */
    /**
    * @brief It is called by Foxit Reader to notify the mouse-enter event.
     * @param[in]		clientData	The user-supplied data.
     * @param[in]		pageView	The input page view whose mouse-enter event occurred.
     * @param[in]		curData		The current data for doc.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRMousePtOnMouseEnter)(FS_LPVOID clientData, FR_PageView pageView, void* curData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRMousePtOnMouseExit */
    /**
    * @brief It is called by Foxit Reader to notify the mouse-exit event.
     * @param[in]		clientData	The user-supplied data.
     * @param[in]		pageView	The input page view whose mouse-exit event occurred.
     * @param[in]		curData		The current data for doc.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRMousePtOnMouseExit)(FS_LPVOID clientData, FR_PageView pageView, void* curData);
    /* @CALLBACKEND */

}FR_MousePtCallbacksRec, *FR_MousePtCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_UndoRedoCallbacks */
/**
* @brief A callback set for undo-redo. The framework manage the undo-redo items for the plug-ins. The framework calls these interface to
* notify the plug-ins when to implement the undo-redo operation, when to release the undo-redo items. See <a>FRAppAddUndoRedoItem</a>.
* @deprecated internal use.
*/
typedef struct _fr_undoredo_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_UndoRedoCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID clientData;

    /* @CALLBACKSTART OnUndo */
    /**
    * @brief It is called to implement the undo operation.
     * @param[in]		clientData		The user-supplied data.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*OnUndo)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnRedo */
    /**
    * @brief It is called to implement the redo operation.
     * @param[in]		clientData		The user-supplied data.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*OnRedo)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnRelease */
    /**
    * @brief It is called when the undo-redo item is to be released by Foxit Reader.
     * @param[in]		clientData		The user-supplied data.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*OnRelease)(FS_LPVOID clientData);
    /* @CALLBACKEND */

}FR_UndoRedoCallbacksRec, *FR_UndoRedoCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_EmptyFramWndNotifies */
/**
* @brief A callback set for an empty frame window which created by <a>FRAppCreateAnEmptyFrameWnd</a>().
* @deprecated Internal use
*/
typedef struct _fr_emptyframwndnotifies_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EmptyFramWndNotifiesRec</a>). */
	unsigned long lStructSize;
	
	/** The user-supplied data. */
	FS_LPVOID clientData;

	/* @CALLBACKSTART FRAppEmptyFramWndCanClose */
	/**
	 * @brief It is called when user click the "close" button to close a frame which created by <a>FRAppCreateAnEmptyFrameWnd</a>().
	 * @param[in]		clientData		The user-supplied data.
	 * @param[in]		wnd				The frame window-self which created by <a>FRAppCreateAnEmptyFrameWnd</a>().
	 * @return <a>TRUE</a> if the empty frame can be closed, otherwise not.
	 * @note
     */
    FS_BOOL (*FRAppEmptyFramWndCanClose)(FS_LPVOID clientData, FS_HWND wnd);
	/* @CALLBACKEND */
}FR_EmptyFramWndNotifiesRec, *FR_EmptyFramWndNotifies;
/* @CALLBACKGROUPEND */

/* @DEFGROUPSTART TaskPaneName */
/*
* @brief Definitions for task pane name. See <a>FRAppShowTaskPane</a>.
*/

/*@{*/
/** @brief The name of advanced search task pane.*/
#define FR_TASKPANE_ADVSEARCH	"AdvSearchTaskPane"
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKGROUPSTART FR_TaskPaneViewCallback */
/**
* @brief A callback set for creating an task pane view.
*
* A task pane is a part of main window of Foxit Reader, it is shown at left area of main window.
* Using <a>FRAppRegisterTaskPaneView</a>() to register a task pane view and then call <a>FRAppShowTaskPane</a>() to show it.
*/
typedef struct _fr_taskpaneview_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_TaskPaneViewCallbackRec</a>). */
	unsigned long lStructSize;
	
	/** The user-supplied data. */
	FS_LPVOID clientData;

	/* @CALLBACKSTART FRTaskPaneViewGetName */
	/**
	 * @brief It is called by Foxit Reader to receive the name of task pane view you want to create.
	 * @param[in]		clientData		The user-supplied data.
	 * @return The name of task pane view.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
	FS_LPSTR (*FRTaskPaneViewGetName)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPaneViewGetTitle */
	/**
	 * @brief It is called by Foxit Reader to receive the title of task pane view you want to create.
	 * @param[in]		clientData		The user-supplied data.
	 * @return The title of task pane view.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
	FS_LPWSTR (*FRTaskPaneViewGetTitle)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPaneViewGetDropMenuItemText */
	/**
	 * @brief It is called by Foxit Reader to receive the text of drop-down menu at the right-up corner.
	 * @param[in]		clientData		The user-supplied data.
	 * @return The text of drop-down menu at the right-up corner.
	 * @note     This interface is used for the old UI, the new UI has been deprecated.
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     * @deprecated Internal use.
     */
	FS_LPWSTR (*FRTaskPaneViewGetDropMenuItemText)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPaneViewGetDropMenuItemTip */
	/**
	 * @brief It is called by Foxit Reader to receive the tooltip of drop-down menu at the right-up corner.
	 * @param[in]		clientData		The user-supplied data.
	 * @return The tooltip of drop-down menu at the right-up corner.
	 * @note    This interface is used for the old UI, the new UI has been deprecated.
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     * @deprecated Internal use.
     */
	FS_LPWSTR (*FRTaskPaneViewGetDropMenuItemTip)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPaneViewCreateHwnd */
	/**
	 * @brief It is called by Foxit Reader to receive the window handle of task pane view. Once the document is opened in browser, 
	 * this callback will be called to create a window of task pane view.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] hOwner		The parent window used to create the task pane view.
	 * @return The window handle of task pane view.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    FS_HWND	(*FRTaskPaneViewCreateHwnd)(FS_LPVOID clientData, FS_HWND hOwner);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPaneViewDestroyHwnd */
	/**
	 * @brief It is called by Foxit Reader to destroy the window handle of task pane view. Once the document is closed in browser, 
	 * this callback will be called to destroy the window of task pane view.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] hOwner		The parent window used to create the task pane view.
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    void	(*FRTaskPaneViewDestroyHwnd)(FS_LPVOID clientData, FS_HWND hOwner);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPaneViewGetBigIcon */
	/**
	 * @brief This interface is reserved.
	 * @param[in] clientData	The user-supplied data.
	 * @return This interface is reserved. You can return NULL.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
	FS_DIBitmap (*FRTaskPaneViewGetBigIcon)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPaneViewGetSmallIcon */
	/**
	 * @brief This interface is reserved.
	 * @param[in] clientData	The user-supplied data.
	 * @return This interface is reserved. You can return NULL.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
	FS_DIBitmap (*FRTaskPaneViewGetSmallIcon)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPaneViewOnActive */
	/**
	 * @brief It is called when the task pane view is to be activated.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] hOwner		The parent window of the task pane view.
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    void	(*FRTaskPaneViewOnActive)(FS_LPVOID clientData, FS_HWND hOwner);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPaneViewOnDestroy */
	/**
	 * @brief It is called when the task pane view is to be destroyed.
	 * @param[in] clientData	The user-supplied data.
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
	void	(*FRTaskPaneViewOnDestroy)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPaneViewOnShowTaskPane */
	/**
	 * @brief It is called when the task pane view is to be shown or to be hidden.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] hOwner		The parent window of the task pane view.
	 * @param[in] bShow			It indicates whether the pane view is to be shown or to be hidden.
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    void	(*FRTaskPaneViewOnShowTaskPane)(FS_LPVOID clientData, FS_HWND hOwner, FS_BOOL bShow);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPaneViewCanClose */
	/**
	 * @brief It is called when the task pane view is to be closed.
	 * @param[in] clientData	The user-supplied data.
	 * @return TRUE if the task pane view can be closed, otherwise not.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
     */
	FS_BOOL (*FRTaskPaneViewCanClose)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRTaskPanelViewIsShowInMenu */
	/**
	 * @brief It is called when the title of the task pane view is to be shown in the right-top dropdown menu.
	 * @param[in] clientData	The user-supplied data.
	 * @return TRUE if the title of the task pane view will be shown in the right-top dropdown menu, otherwise not.
	 * @note   This interface is used for the old UI, the new UI has been deprecated.
	 * @since <a>SDK_LATEEST_VERSION</a> > 8.1
     * @deprecated Internal use.
     */
	FS_BOOL (*FRTaskPanelViewIsShowInMenu)(FS_LPVOID clientData);

}FR_TaskPaneViewCallbackRec, *FR_TaskPaneViewCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_WinMSGCallbacks */

/**
 * @brief A callback set for a windows MSG handler. You can register it by <a>FRAppRegisterWinMSGHandler</a>. It is only available in Windows
 * @deprecated Internal use.
 */
typedef struct _fr_winmsg_callbacks_
{
    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_WinMSGCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRPIPreTranslateMessage */
	/**
     * @brief The callback is invoked by Foxit Reader to dispatch the message to plug-in.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pMsg			Points to a <Italic>MFC MSG</Italic> structure that contains the message to process.
	 * @return <a>TRUE</a> if the message was fully processed in <a>FRPIPreTranslateMessage</a> 
	 * and should not be processed further. <a>FALSE</a> if the message should be processed in the normal way.
     * @note
     */
	FS_BOOL (*FRPIPreTranslateMessage)(FS_LPVOID clientData, void* pMsg);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPIOnIdleMessage */
	/**
	* @brief The callback is invoked by Foxit Reader to dispatch the message to plug-in.
	* @param[in] clientData	The user-supplied data.
	* @return void.
	* @note
	*/
	void(*FRPIOnIdleMessage)(FS_LPVOID clientData);
	/* @CALLBACKEND */

}FR_WinMSGCallbacksRec, *FR_WinMSGCallbacks;
/* @CALLBACKGROUPEND */


/* @CALLBACKGROUPSTART FR_OwnerFileTypeHandlerCallbacks */
/**
 * @brief The structure containing  owner file type handler callbacks. You can control the process of owner file type
 * by implementing the callbacks, such as opening, saving, sending email and so on. You can register it by <a>FRAppRegisterOwnerFileTypeIII</a>.
 * @deprecated Internal use.
 */
typedef struct _fr_ownerfiletype_handler_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_OwnerFileTypeHandlerCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FROwnerFileTypeHandlerDoOpen */
    /**
    * @brief It will be invoked by Foxit Reader when a document is opened. You can implement the callback to control
    * the process of opening.
     * @param[in] clientData		The user-supplied data.
     * @param[in] lpszFilterName	The filter name used in file open dialog.
     * @param[in] lpszPath			The full path of the document opened.
     * @return <a>TRUE</a> if the plug-in takes over the process, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    FS_BOOL (*FROwnerFileTypeHandlerDoOpen)(FS_LPVOID clientData, FS_LPCSTR lpszFilterName, FS_LPCWSTR lpszPath);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FROwnerFileTypeHandlerDoSave */
    /**
    * @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to control
    * the process of saving.
     * @param[in] clientData		The user-supplied data.
     * @param[in] lpszFilterName	The filter name used in file save dialog.
     * @param[in] lpszPath			The full path of the document to be saved.
     * @return <a>TRUE</a> if the plug-in takes over the process.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 1.0
	 * @deprecated  It has deprecated, suggest used to FROwnerFileTypeHandlerDoSave3.
     */
    FS_BOOL (*FROwnerFileTypeHandlerDoSave)(FS_LPVOID clientData, FS_LPCSTR lpszFilterName, FS_LPCWSTR lpszPath);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FROwnerFileTypeHandlerDoEmail */
	/**
	* @brief It will be invoked by Foxit Reader when a document is emailed. You can implement the callback to control 
	* the process of sending email.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] lpszFilterName	The filter name used as the unique identity.
	 * @param[in] lpszPath			The full path of the document to be emailed.
     * @return Return <a>TRUE</a> if the plug-in takes over the process.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    FS_BOOL (*FROwnerFileTypeHandlerDoEmail)(FS_LPVOID clientData, FS_LPCSTR lpszFilterName, FS_LPCWSTR lpszPath);
    /* @CALLBACKEND */
	
	/* @CALLBACKSTART FROwnerFileTypeHandlerCanSetFileAssociation */
	/**
	* @brief It will be invoked by Foxit Reader to judge whether the plug-in need to associate the file type with Foxit Reader.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] lpszFileExt	The extension of the file.
     * @return <a>TRUE</a> if the file type needs to be associated with Foxit Reader as the default application. If the plug-in returns 
	 * <a>FALSE</a>, <a>FROwnerFileTypeHandlerSetFileAssociationInfo</a> will not be invoked.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
	FS_BOOL (*FROwnerFileTypeHandlerCanSetFileAssociation)(FS_LPVOID clientData, FS_LPCWSTR lpszFileExt);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROwnerFileTypeHandlerSetFileAssociationInfo */
	/**
	* @brief It will be invoked by Foxit Reader to set the file association information.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] lpszFileExt		The extension of the file.
	 * @param[out] wsRegClass		It receives the application object name under <Italic>HKEY_CLASSES_ROOT</Italic>. For example, "FoxitPhantomPDF.Document".
	 * @param[out] wsDesc			It receives the description of the application object.
	 * @param[out] wsAppPath		It receives the application path where the icon is stored.
	 * @param[out] nDefaultIcon		The default icon index displayed on the desktop for owner file type. You can set it 1 as default.
	 * Put the icon resource in the RC file of your plug-in and set the ID value to 102.
     * @return <a>TRUE</a> if the plug-in set the file association information correctly, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
	FS_BOOL	(*FROwnerFileTypeHandlerSetFileAssociationInfo)(FS_LPVOID clientData, FS_LPCWSTR lpszFileExt,
		FS_WideString wsRegClass, FS_WideString wsDesc, FS_WideString wsAppPath, FS_INT32* nDefaultIcon);
	/* @CALLBACKEND */	
	
	/* @CALLBACKSTART FROwnerFileTypeHandlerGetSupportFileTypeCount */
    /**
    * @brief It will be invoked by Foxit Reader to get the count of file types that this handler can support.
     * @param[in] clientData		The user-supplied data.
     * @return The count of file types that this handler can support.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    FS_INT32 (*FROwnerFileTypeHandlerGetSupportFileTypeCount)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FROwnerFileTypeHandlerGetFileFilterNameByIndex */
    /**
    * @brief It will be invoked by Foxit Reader to get the filter name of custom file type by index.
     * @param[in] clientData		The user-supplied data.
     * @param[in] nIndex			The index of the custom file type.
     * @param[out] bsName			It receives the filter name of custom file type.
     * @return <a>TRUE</a> if gets the filter name correctly, otherwise not.
     * @note eg: Word 97-2003 Files(*.doc)|*.doc (must not translate).
     * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    FS_BOOL (*FROwnerFileTypeHandlerGetFileFilterNameByIndex)(FS_LPVOID clientData, FS_INT32 nIndex, FS_ByteString bsName);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FROwnerFileTypeHandlerGetFileTypeFilter */
    /**
    * @brief It will be invoked by Foxit Reader to get the filter of the custom file type.
     * @param[in] clientData		The user-supplied data.
     * @param[in] lpszFilterName	The filter name.
     * @param[out] wsName			It receives the filter of the custom file type.
     * @return <a>TRUE</a> if gets the filter correctly, otherwise not.
     * @note eg: Word 97-2003 Files(*.doc)|*.doc (must translate).
     * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    FS_BOOL (*FROwnerFileTypeHandlerGetFileTypeFilter)(FS_LPVOID clientData, FS_LPCSTR lpszFilterName, FS_WideString wsName);
    /* @CALLBACKEND */
	
    /* @CALLBACKSTART FROwnerFileTypeHandlerGetFileExt */
    /**
    * @brief It will be invoked by Foxit Reader to get the extension of the custom file type.
     * @param[in] clientData		The user-supplied data.
     * @param[in] lpszFilterName	The filter name.
     * @param[out] wsFileExt		It receives the extension of the custom file type.
     * @return <a>TRUE</a> if gets the extension correctly, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    FS_BOOL (*FROwnerFileTypeHandlerGetFileExt)(FS_LPVOID clientData, FS_LPCSTR lpszFilterName, FS_WideString wsFileExt);
    /* @CALLBACKEND */
	
	/* @CALLBACKSTART FROwnerFileTypeHandlerIsEnableSaveAsSettingBtn */
	/**
	* @brief It will be invoked by Foxit Reader to determine whether enables the setting button in the Save As dialog.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] lpszFilterName	The filter name.
     * @return <a>TRUE</a> if you want to enable the setting button, otherwise not.
     * @note For Save As Interface
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
	FS_BOOL (*FROwnerFileTypeHandlerIsEnableSaveAsSettingBtn)(FS_LPVOID clientData, FS_LPCSTR lpszFilterName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROwnerFileTypeHandlerExecuteSaveAsSetting */
	/**
	* @brief It will be invoked by Foxit Reader when the user clicks the setting button.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] lpszFilterName	The filter name.
	 * @param[in] hParentWnd		The parent window.
     * @return <a>TRUE</a> if the plug-in takes over the setting process, otherwise not.
     * @note For Save As Interface
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    FS_BOOL (*FROwnerFileTypeHandlerExecuteSaveAsSetting)(FS_LPVOID clientData, FS_LPCSTR lpszFilterName, FS_HWND hParentWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROwnerFileTypeHandlerCanSupportAddToRecentList */
	/**
	* @brief It will be invoked by Foxit Reader to determine whether the file of this type can be added to the recent file list.
	 * @param[in] clientData		The user-supplied data.
     * @return <a>TRUE</a> if the file of this type can be added to the recent file list, otherwise not.
     * @note 
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
	FS_BOOL (*FROwnerFileTypeHandlerCanSupportAddToRecentList)(FS_LPVOID clientData);
	/* @CALLBACKEND */
	
    /* @CALLBACKSTART FROwnerFileTypeHandlerCanSupportSave */
    /**
	* @brief It will be invoked by Foxit Reader to determine whether the filter of the document can support to save.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] wsFilterName		The filter name.
	 * @param[in] frDoc				The document.
     * @return <a>TRUE</a> if support the filter, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
    FS_BOOL (*FROwnerFileTypeHandlerCanSupportSave)(FS_LPVOID clientData, FS_WideString wsFilterName, FR_Document frDoc);
    /* @CALLBACKEND */
	
	/* @CALLBACKSTART FROwnerFileTypeHandlerCanBeSaveAsToOtherExt */
	/**
	* @brief It will be invoked by Foxit Reader to determine whether the filter can be save as to other extensions.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] wsFilterName		The filter name.
     * @return <a>TRUE</a> if support to save as other extensions, otherwise not.
     * @note 
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
     */
	FS_BOOL (*FROwnerFileTypeHandlerCanBeSaveAsToOtherExt)(FS_LPVOID clientData, FS_WideString wsFilterName);
	/* @CALLBACKEND */
	
/* @CALLBACKSTART FROwnerFileTypeHandlerCanSupportOpen */
	/**
	* @brief It will be invoked by Foxit Reader to determine whether the filter of the document can support to open.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] wsFilterName		The filter name.
	 * @param[in] wsPathName		The path of the document to be opened.
     * @return <a>TRUE</a> if support the filter, otherwise not.
     * @note 
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
	FS_BOOL (*FROwnerFileTypeHandlerCanSupportOpen)(FS_LPVOID clientData, FS_WideString wsFilterName, FS_WideString wsPathName);
	/* @CALLBACKEND */
	
	/* @CALLBACKSTART FROwnerFileTypeHandlerDoOpenDir */
	/**
	* @brief It will be invoked by Foxit Reader to open a dir which includes the openning epub document.
	* @param[in] clientData		The user-supplied data.
	* @param[in] csHandler		handler of the window for openning epub document.
	* @return <a>TRUE</a> if operation successed, otherwise not.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 8.2
	*/
    FS_BOOL(*FROwnerFileTypeHandlerDoOpenDir)(FS_LPVOID clientData, FS_HWND csHandler);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROwnerFileTypeHandlerCanSupportOpenDir */
	/**
	* @brief It will be invoked by Foxit Reader to determine whether the filter of the document can support to open dir for this current epub document.
	* @param[in] clientData		The user-supplied data.
	* @param[in] csHandler		handler of the window for openning epub document.
	* @return <a>TRUE</a> if support the filter, otherwise not.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 8.2
	*/
    FS_BOOL(*FROwnerFileTypeHandlerCanSupportOpenDir)(FS_LPVOID clientData, FS_HWND csHandler);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROwnerFileTypeHandlerSaveFilePathToClipBoard */
	/**
	* @brief It will be invoked by Foxit Reader to copy current epub document path to clip board.
	* @param[in] clientData		The user-supplied data.
	* @param[in] csHandler		handler of the window for openning epub document.
	* @return <a>TRUE</a> if operation successed, otherwise not.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 8.2
	*/
    FS_BOOL(*FROwnerFileTypeHandlerSaveFilePathToClipBoard)(FS_LPVOID clientData, FS_HWND csHandler);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROwnerFileTypeHandlerDoSave2 */
	/**
	* @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to control
	* the process of saving.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] lpszFilterName	The filter name used in file save dialog.
	 * @param[in] lpszPath			The full path of the document to be saved.
	 * @param[in] bWipEncrypt		If encrypt file.
	 * @return <a>TRUE</a> if the plug-in takes over the process.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
	 * @deprecated  It has deprecated, suggest used to FROwnerFileTypeHandlerDoSave3.
	 */
	FS_BOOL(*FROwnerFileTypeHandlerDoSave2)(FS_LPVOID clientData, FS_LPCSTR lpszFilterName, FS_LPCWSTR lpszPath, FS_BOOL bWipEncrypt);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRCheckSaveAsViewResult */
	/**
	* @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to control
	* the process of check view result in saveas dialog.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] csFilterName	    The filter name used in file save dialog.
	 * @param[in] bViewResult		The full path of the document to be saved.	 
	 * @return <a>TRUE</a> if the plug-in takes over the process. it is a internal interface.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
	 * @deprecated Internal use.
	 */
	FS_BOOLEAN(*FRCheckSaveAsViewResult)(FS_LPVOID clientData, FS_LPCSTR csFilterName, FS_BOOL bViewResult);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRIsCheckSaveAsViewResult */
	/**
	* @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to 
	check the filter name when check view result in saveas dialog.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] csFilterName	    The filter name used in file save dialog.
	 * @return <a>TRUE</a> if the plug-in takes over the process.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
	 * @deprecated Internal use.
	 */
	FS_BOOLEAN(*FRIsCheckSaveAsViewResult)(FS_LPVOID clientData, FS_LPCSTR csFilterName);
	/* @CALLBACKEND */
	
	/* @CALLBACKSTART FRIsEnableSaveAsViewResult */
	/**
	* @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to control
	* the process of save as the file,it control if enable view result checkbox when save as to other format.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] csFilterName	    The filter name used in file save dialog.
	 * @return <a>TRUE</a> if the plug-in takes over the process.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
	 * @deprecated Internal use.
	 */
	FS_BOOLEAN(*FRIsEnableSaveAsViewResult)(FS_LPVOID clientData, FS_LPCSTR csFilterName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRGetFileExtByFilterIndex */
	/**
	* @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to control
	* when check view result in saveas dialog.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] csFilterName	    The filter name used in file save dialog.
	 * @return FS_LPCWSTR
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
	 * @deprecated Internal use.
	 */
	FS_LPCWSTR(*FRGetFileExtByFilterIndex)(FS_LPVOID clientData, FS_LPCSTR csFilterName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRCanSupportPDFOnly */
	/**
	* @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to control
	* the process of saving.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] pReaderDocument	The current document.
	 * @return <a>TRUE</a> if support PDF only.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
	 */
	FS_BOOLEAN(*FRCanSupportPDFOnly)(FS_LPVOID clientData, FR_Document pReaderDocument);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRExportOtherFormat */
	/**
	* @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to control
	* the process to export other format.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] csFilterName	    The filter name of the file.
	 * @param[in] wsDesPath	        The dest path.
	 * @param[in] bWipEncrypt	    Whether encrypt file.
	 * @param[in] bActionWizard	    Whether action wizard.
	 * @return <a>TRUE</a> if the plug-in takes over the process.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
	 */
	FS_BOOLEAN(*FRExportOtherFormat)(FS_LPVOID clientData, FS_LPCSTR csFilterName, FS_LPCWSTR wsDesPath, FS_BOOL bWipEncrypt, FS_BOOL bActionWizard);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROwnerFileTypeHandlerDoSave3 */
	/**
	* @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to control
	* the process of saving.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] lpszFilterName	The filter name used in file save dialog.
	 * @param[in] lpszPath			The full path of the document to be saved.
	 * @param[in] bWipEncrypt		If encrypt file, it used for windows.
	 * @param[in] pDoc		        The <a>FR_Document</a> which is saved, it used for mac.
	 * @return <a>TRUE</a> if the plug-in takes over the process.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
	 */
	FS_BOOL(*FROwnerFileTypeHandlerDoSave3)(FS_LPVOID clientData, FS_LPCSTR lpszFilterName, FS_LPCWSTR lpszPath, FS_BOOL bWipEncrypt, FR_Document pDoc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRCheckSaveAsOpenFile */
	/**
	* @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to control
	* the process of saving.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] csFilterName  	The filter name used in file save dialog.
	 * @param[in] bOpenFile			If need open file when after save the file.	
	 * @return <a>TRUE</a> if the plug-in takes over the process.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.0
	 */
	FS_BOOLEAN(*FRCheckSaveAsOpenFile)(FS_LPVOID clientData, FS_LPCSTR csFilterName, FS_BOOL bOpenFile);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRIsCheckSaveAsOpenFile */
	/**
	* @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to control
	* the process of saving.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] csFilterName  	The filter name used in file save dialog.	 
	 * @return <a>TRUE</a> if the plug-in takes over the process.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.0
	 */
	FS_BOOLEAN(*FRIsCheckSaveAsOpenFile)(FS_LPVOID clientData, FS_LPCSTR csFilterName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRIsEnableSaveAsOpenFile */
	/**
	* @brief It will be invoked by Foxit Reader when a document is saved. You can implement the callback to control
	* the process of saving.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] csFilterName  	The filter name used in file save dialog.
	 * @return <a>TRUE</a> if the plug-in takes over the process.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.0
	 */
	FS_BOOLEAN(*FRIsEnableSaveAsOpenFile)(FS_LPVOID clientData, FS_LPCSTR csFilterName);
	/* @CALLBACKEND */
}FR_OwnerFileTypeHandlerCallbacksRec, *FR_OwnerFileTypeHandlerCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_SecurityMethodCallbacks */
/**
 * @brief The structure containing security method callbacks. You can manage the security methods of Foxit Reader
 * by implementing the callbacks. You can register it by <a>FRAppRegisterSecurityMethod</a>.
 *
 */
typedef struct _fr_securitymethod_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_SecurityMethodCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRSecurityMethodGetName */
    /**
    * @brief It is called by Foxit Reader to get the name of the security method.
     * @param[in] clientData	The user-supplied data.
     * @return The name of the security method.
     * @note
     */
    FS_LPWSTR		(*FRSecurityMethodGetName)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSecurityMethodGetTitle */
    /**
    * @brief It is called by Foxit Reader to get the title of the security method.
     * @param[in] clientData	The user-supplied data.
     * @return The title of the security method.
     * @note
     */
    FS_LPWSTR		(*FRSecurityMethodGetTitle)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSecurityMethodIsMyMethod */
    /**
    * @brief It is called by Foxit Reader to ask the plug-in whether the security applied for the document can be handled.
     * @param[in] clientData	The user-supplied data.
     * @param[in] doc			The document.
     * @return <a>TRUE</a> if the security applied for the document can be handled, otherwise not.
     * @note
     */
    FS_BOOL			(*FRSecurityMethodIsMyMethod)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSecurityMethodCheckModuleLicense */
    /**
    * @brief It is called by Foxit Reader to check whether the plug-in has the license to modify the security.
    * In general, it is a internal interface.
     * @param[in] clientData	The user-supplied data.
     * @return <a>TRUE</a> if the plug-in has the license to modify the security, otherwise not.
     * @note
     */
    FS_BOOL			(*FRSecurityMethodCheckModuleLicense)(FS_LPVOID clientData);
    /* @CALLBACKEND */


    /* @CALLBACKSTART FRSecurityMethodCanBeModified */
    /**
    * @brief It is called by Foxit Reader to check whether the plug-in has the right to modify the security.
     * @param[in] clientData	The user-supplied data.
     * @return <a>TRUE</a> if the plug-in has the right to modify the security, otherwise not.
     * @note
     */
    FS_BOOL			(*FRSecurityMethodCanBeModified)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSecurityMethodDoSetting */
    /**
    * @brief It is called by Foxit Reader when the user clicks the setting button in the security page of document property dialog. You can
    * implement your own setting process.
     * @param[in] clientData	The user-supplied data.
     * @param[in] hWnd			The parent window used to create the child window.
     * @param[out] bSuc			It receives the result whether the setting is successful.
     * @return void
     * @note
     */
    void			(*FRSecurityMethodDoSetting)(FS_LPVOID clientData, FS_HWND hWnd, FS_BOOL* bSuc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSecurityMethodRemoveSecurityInfo */
    /**
    * @brief It is called by Foxit Reader when the security method is to be removed. Then you can implement your own removing process.
     * @param[in] clientData	The user-supplied data.
     * @return <a>TRUE</a> if you remove the security method correctly, otherwise not.
     * @note
     */
    FS_BOOL			(*FRSecurityMethodRemoveSecurityInfo)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSecurityMethodCreatePermSubDlg */
    /**
    * @brief It is called by Foxit Reader when the security page of document property dialog is to be shown. If the security method
    * is yours, you have to create a child window to show the information of the security method.
     * @param[in] clientData	The user-supplied data.
     * @param[in] hParent		The parent window used to create the child window.
     * @return The handle of the child window used to  show the information of the security method.
     * @note
     */
    FS_HWND			(*FRSecurityMethodCreatePermSubDlg)(FS_LPVOID clientData, FS_HWND hParent);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRSecurityMethodDestroyPermSubDlg */
    /**
    * @brief It is called by Foxit Reader when the security page of document property dialog is to be destroyed.
     * @param[in] clientData	The user-supplied data.
     * @param[in] hWnd			The window handle
     * @return void
     * @note
     */
    void			(*FRSecurityMethodDestroyPermSubDlg)(FS_LPVOID clientData, FS_HWND hWnd);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRSecurityMethodDescription */
	/**
	* @brief It is called by Foxit Reader to get the description of the security method.
	 * @param[in] clientData	The user-supplied data.
	 * @return The Description of the security method.
	 * @note
	 */
	FS_LPWSTR			(*FRSecurityMethodDescription)(FS_LPVOID clientData);

	/* @CALLBACKSTART FRSecurityMethodGetShowIco */
	/**
	* @brief It is called by Foxit Reader to get the icon of the security method.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] dbScale		The scaling value.
	 * @return The icon of the security method.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.7
	 */
	FS_DIBitmap (*FRSecurityMethodGetShowIco)(FS_LPVOID clientData, FS_FLOAT dbScale);
	/* @CALLBACKSTART FRCheckOwner */
	/**
	* @brief It is called by Foxit Reader to obtain permissions.Only applicable to password encryption, 
     * @param[in] clientData	The user-supplied data.
	 * @param[in] pDocument	The specified document.
	 * @param[in] pParent	The parent window.
	 * @param[in] bRequestOwnerPassword		If it is true, the owner password needs to be verified
	 * @return <a>TRUE</a> If the verification passes,otherwise not.
	 * @note 
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.7
	 */
	FS_BOOL (*FRCheckOwner)(FS_LPVOID clientData, FR_Document pDocument, HWND pParent, FS_BOOL bRequestOwnerPassword);
	/* @CALLBACKSTART FRCheckOwnerPermission */
	/**
	* @brief It is called by Foxit Reader to check owner permission.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pDocument	The specified document.
	 * @return <a>TRUE</a> If the check passes,otherwise not.
	 * @note 
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.7
	 */
	FS_BOOL (*FRCheckOwnerPermission)(FS_LPVOID clientData, FR_Document pDocument);
	/* @CALLBACKSTART FRGetCertificateECipher */
	/**
	* @brief It is called by Foxit Reader to check owner permission,
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pDocument	The specified document.
	 * @return <a>FXCIPHER_NONE FRCIPHER_RC4 FXCIPHER_AES</a> cipher type
	 * @note 
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.7
	 */
	int (*FRGetCertificateECipher)(FS_LPVOID clientData, FR_Document pDocument);
	/* @CALLBACKSTART FRShowSecurityDialog */
	/**
	* @brief It is called by Foxit Reader to show encryption settings dialog.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] proc User callback function
	 * @return void
	 * @note 
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.7
	 */
	void (*FRShowSecurityDialog)(FS_LPVOID clientData, FRPasswordEncryptProc proc);
	/* @CALLBACKSTART FRGetDocumentOpenPassword */
	/**
	* @brief It is called by Foxit Reader to get open password.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pDocument	The specified document.
	 * @param[in] pPassword	open password.
	 * @return <a>TRUE</a> success,otherwise not.
	 * @note 
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.7
	 */
	FS_BOOL (*FRGetDocumentOpenPassword)(FS_LPVOID clientData, FR_Document pDocument, FS_WideString pPassword);
}FR_SecurityMethodCallbacksRec, *FR_SecurityMethodCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_WndProviderCallbacks */
/**
 * @brief The callback set is used to create a window above the document view. There are already some windows above 
 * the document view, such as PDF view, text view, ruler view. You can register it by <a>FRAppRegisterWndProvider</a>,
 * and unregister it by <a>FRAppUnRegisterWndProvider</a>.
 * @deprecated Internal use.
 *
 */
typedef struct _fr_wndprovider_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_WndProviderCallbacksRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRWndProviderCreateViewWnd */
	/**
	* @brief It is called by Foxit Reader to notify the plug-in to create the view.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] hParent		The parent window.
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void		(*FRWndProviderCreateViewWnd)(FS_LPVOID clientData, FR_Document frDoc, FS_HWND hParent);
	/* @CALLBACKEND */

	FS_LPCSTR (*FRWndProviderGetName)(FS_LPVOID clientData);

	/* @CALLBACKSTART FRWndProviderOnHScroll */
	/**
	* @brief It is called by Foxit Reader when the user clicks a horizontally-aligned scroll bar, spin button control, or slider control.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] nSBCode		Specifies a scroll-bar code that indicates the user's scrolling request. Reference to <Italic>MFC CWnd::OnHScroll</Italic>.	
	 * @param[in] nPos			Specifies the scroll-box position if the scroll-bar code is <Italic>SB_THUMBPOSITION</Italic> or <Italic>SB_THUMBTRACK</Italic>; 
	 * otherwise, not used. Depending on the initial scroll range, nPos may be negative and should be cast to an int if necessary.		
	 * @param[in] pScrollBar		It represents the MFC type of <Italic>CScrollBar</Italic>.	
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRWndProviderOnHScroll)(FS_LPVOID clientData, FR_Document frDoc, unsigned int nSBCode, unsigned int nPos, void* pScrollBar);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderOnVScroll */
	/**
	* @brief It is called by Foxit Reader when the user clicks a vertically-aligned scroll bar, spin button control, or slider control.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] nSBCode		Specifies a scroll-bar code that indicates the user's scrolling request. Reference to <Italic>MFC CWnd::OnHScroll</Italic>.	
	 * @param[in] nPos			Specifies the scroll-box position if the scroll-bar code is <Italic>SB_THUMBPOSITION</Italic> or <Italic>SB_THUMBTRACK</Italic>; 
	 * otherwise, not used. Depending on the initial scroll range, nPos may be negative and should be cast to an int if necessary.		
	 * @param[in] pScrollBar		It represents the MFC type of <Italic>CScrollBar</Italic>.	
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRWndProviderOnVScroll)(FS_LPVOID clientData, FR_Document frDoc, unsigned int nSBCode, unsigned int nPos, void* pScrollBar);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderOnCmdMsg */
	/**
	* @brief It is called by the <Italic>Foxit Reader</Italic> to route and dispatch command messages and to handle the update of command user-interface objects, such as menu, toolbar.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] nID			Contains the command ID.
	 * @param[in] nCode			References to <Italic>MFC CCmdTarget::OnCmdMsg</Italic>.
	 * @param[in] pExtra		References to <Italic>MFC CCmdTarget::OnCmdMsg</Italic>.
	 * @param[in] pHandlerInfo	It represents the <Italic>MFC</Italic> struct <Italic>AFX_CMDHANDLERINFO</Italic>.
	 * @return Nonzero if the message is handled; otherwise 0.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRWndProviderOnCmdMsg)(FS_LPVOID clientData, FR_Document frDoc, unsigned int nID, FS_INT32 nCode, void* pExtra, void* pHandlerInfo);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderMoveWindow */
	/**
	* @brief It is called by the <Italic>Foxit Reader</Italic> to notify the plug-in to move the window.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] x				Specifies the new position of the left side of the window.
	 * @param[in] y				Specifies the new position of the top of the window.
	 * @param[in] nWidth		Specifies the new width of the window.
	 * @param[in] nHeight		Specifies the new height of the window.
	 * @param[in] bRepaint		Specifies whether window is to be repainted.
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRWndProviderMoveWindow)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 x, FS_INT32 y, FS_INT32 nWidth, FS_INT32 nHeight, FS_BOOL bRepaint);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderOnSetCursor */
	/**
	* @brief It is called by the <Italic>Foxit Reader</Italic> to notify the plug-in to set the cursor.
	* References to <Italic>MFC CWnd::OnSetCursor</Italic> for detailed description.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] pWnd			It represents the <Italic>MFC CWnd*</Italic> and specifies a pointer to the window that contains the cursor. The pointer may be temporary and should not be stored for later use.
	 * @param[in] nHitTest		Specifies the hit-test area code. The hit test determines the location of the cursor.
	 * @param[in] message		Specifies the mouse message number.
	 * @return Nonzero to halt further processing, or 0 to continue.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRWndProviderOnSetCursor)(FS_LPVOID clientData, FR_Document frDoc, void* pWnd, unsigned int nHitTest, unsigned int message);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderZoomToPage */
	/**
	* @brief It is called by the <Italic>Foxit Reader</Italic> to notify the plug-in to zoom the window.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] dbScale		The specified zoom scale.
	 * @param[in] bUpdate		Whether the window needs to update or not.
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRWndProviderZoomToPage)(FS_LPVOID clientData, FR_Document frDoc, double dbScale, FS_BOOL bUpdate);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderGotoPage */
	/**
	* @brief It is called by the <Italic>Foxit Reader</Italic> to notify the plug-in to go to the specified page.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] nPageIndex	The specified page index.
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRWndProviderGotoPage)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nPageIndex);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderShowWindow */
	/**
	* @brief It is called by the <Italic>Foxit Reader</Italic> to notify the plug-in to show the window created.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] bShow			Whether the window is to be shown or to be hidden.
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRWndProviderShowWindow)(FS_LPVOID clientData, FR_Document frDoc, FS_BOOL bShow);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderReInitScrollBar */
	/**
	* @brief This interface is reserved.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRWndProviderReInitScrollBar)(FS_LPVOID clientData, FR_Document frDoc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderGetPageIndex */
	/**
	* @brief This interface is reserved.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_INT32 (*FRWndProviderGetPageIndex)(FS_LPVOID clientData, FR_Document frDoc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderInitScrollBar */
	/**
	* @brief It is called by the <Italic>Foxit Reader</Italic> to notify the plug-in to init the scroll bar.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] pHScroll		The pointer to the horizon scroll bar. It represents the MFC type of <Italic>CScrollBar</Italic>.
	 * @param[in] pVScroll		The pointer to the vertical scroll bar.It represents the MFC type of <Italic>CScrollBar</Italic>.
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRWndProviderInitScrollBar)(FS_LPVOID clientData, FR_Document frDoc, void* pHScroll, void* pVScroll);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderOnSetFocus */
	/**
	* @brief It is called by the <Italic>Foxit Reader</Italic> after the window gains the input focus.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] pOldWnd		Contains the CWnd object that loses the input focus (may be NULL). The pointer may be temporary and should not be stored for later use.
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRWndProviderOnSetFocus)(FS_LPVOID clientData, FR_Document frDoc, void* pOldWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderOnMouseWheel */
	/**
	* @brief It is called by the <Italic>Foxit Reader</Italic> as a user rotates the mouse wheel and encounters the wheel's next notch.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The specified document.
	 * @param[in] nFlags		Indicates whether various virtual keys are down. References to <Italic>MFC CWnd::OnMouseWheel</Italic>.
	 * @param[in] zDelta		Indicates distance rotated. References to <Italic>MFC CWnd::OnMouseWheel</Italic>.
	 * @param[in] x				Specifies the x-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the screen.
	 * @param[in] y				Specifies the y-coordinate of the cursor. These coordinates are always relative to the upper-left corner of the screen.
	 * @return Nonzero if mouse wheel scrolling is enabled; otherwise 0.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRWndProviderOnMouseWheel)(FS_LPVOID clientData, FR_Document frDoc, unsigned int nFlags, short zDelta, FS_INT32 x, FS_INT32 y);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWndProviderOnRelease */
	/**
	* @brief It is called by the <Italic>Foxit Reader</Italic> to notify the plug-in to release the resource.
	 * @param[in] clientData	The user-supplied data.
	 * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRWndProviderOnRelease)(FS_LPVOID clientData);
	/* @CALLBACKEND */

}FR_WndProviderCallbacksRec, *FR_WndProviderCallbacks;
/* @CALLBACKGROUPEND */

/* @ENUMSTART */
/** @brief Directory type enumeration used to load library. See <a>FRAppLoadLibrary</a>.*/
enum FRDirectoryType
{
	FR_DIRECTORY_PATH_SYSTEM = 0,	/**Loads the library from the system path. */
	FR_DIRECTORY_PATH_APPLICATION,	/**Loads the library from the application path. */
	FR_DIRECTORY_PATH_PLUGIN,		/**Loads the library from the plug-in path. */
	FR_DIRECTORY_PATH_USERSPECIFY	/**Loads the library from the path that the user specified. */
};
/* @ENUMEND */

/* @CALLBACKGROUPSTART FR_ActionHandlerCallbacks */
/**
 * @brief  The callbacks for action handler. The callbacks are called by Foxit Reader when the Foxit Reader will do the actions. You 
 * can implement your own process to customize the action process. You can regist this hander by <a>FRAppRegisterActionHandler</a>.
 * @deprecated Internal use.
 */
typedef struct _fr_actionhandler_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ActionHandlerCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRActionHandlerDocOpen */
    /**
    * @brief It is called by Foxit Reader if the document contains an action to be performed when the document is opened.
    *
    * If you do not want to customize the action process, you can set this callback to NULL or you must return FALSE. You
    * can call <a>FPDActionGetType</a> to get the type of the action. You can refer to <a>FPD_ActionType</a>. About the
    * open action, you can refer to <Italic>PDF Reference, Section3.6, Entries In the Catalog Dictionary</Italic>.
     * @param[in] clientData	The user-supplied data.
     * @param[in] action		The action to be performed when the document is opened.
     * @param[in] frDoc			The currently opened document.
     * @param[in] frDocView		The current document view.
     * @param[in] bDisableGoto	It indicates whether the plug-in has to disable the Go-To Actions.
     * @return TRUE if the plug-in customizes the action process successfully. If you do not want to customize the action process, you must return
     * FALSE, so that Foxit Reader can implement the default action process.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1
     */
    FS_BOOL (*FRActionHandlerDocOpen)(FS_LPVOID clientData, FPD_Action action, FR_Document frDoc, FR_DocView frDocView, FS_BOOL bDisableGoto);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRActionHandlerJavaScript */
	/**
	* @brief It is called by Foxit Reader if the document contains a JavaScript action to be performed after opeinnig document.
	* It will be called by the following triggers: Document will close; Document did close; Document will save; Document did save;
	* Document will print; Document didi print;
	* If you do not want to customize the action process, you can set this callback to NULL or you must return FALSE. You 
	* can call <a>FPDActionGetType</a> to get the type of the action. You can refer to <a>FPD_ActionType</a>. About the JavaScript
	* action, you can refer to <Italic>PDF Reference, Section8.6, JavaScript Actions</Italic>.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] action		The JavaScript action to be performed when the document is opened.
	 * @param[in] lpwsJSName	The name of the JavaScript.
	 * @param[in] frDoc			The currently opened document.
	 * @param[in] frDocView		The current document view.
	 * @return TRUE if the plug-in customizes the action process successfully. If you do not want to customize the action process, you must return
	 * FALSE, so that Foxit Reader can implement the default action process.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1
     */
    FS_BOOL	(*FRActionHandlerJavaScript)(FS_LPVOID clientData, FPD_Action action, FS_LPCWSTR lpwsJSName, FR_Document frDoc, FR_DocView frDocView);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRActionHandlerPage */
    /**
    * @brief It is called by Foxit Reader if the page contains an additional-actions dictionary defining actions to be performed
    * when the page is opened or closed.
    *
    * If you do not want to customize the action process, you can set this callback to NULL or you must return FALSE. You
    * can call <a>FPDActionGetType</a> to get the type of the action. You can refer to <a>FPD_ActionType</a>. About the additional
    * action, you can refer to <Italic>PDF Reference, Section8.5, Trigger Events</Italic>.
     * @param[in] clientData	The user-supplied data.
     * @param[in] action		The action to be performed when the page is opened or closed.
     * @param[in] type			The additional action type.
     * @param[in] frDoc			The currently opened document.
     * @param[in] frDocView		The current document view.
     * @return TRUE if the plug-in customizes the action process successfully. If you do not want to customize the action process, you must return
     * FALSE, so that Foxit Reader can implement the default action process.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1
     */
    FS_BOOL (*FRActionHandlerPage)(FS_LPVOID clientData, FPD_Action action, FPD_AActionType type, FR_Document frDoc, FR_DocView frDocView);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRActionHandlerLink */
    /**
    * @brief It is called by Foxit Reader if the link annotation contains an actions to be performed when the annotation is activated.
    *
    * If you do not want to customize the action process, you can set this callback to NULL or you must return FALSE. You
    * can call <a>FPDActionGetType</a> to get the type of the action. You can refer to <a>FPD_ActionType</a>. About the link
    * annotation, you can refer to <Italic>PDF Reference, Section8.4, Link Annotations</Italic>.
     * @param[in] clientData	The user-supplied data.
     * @param[in] action		The action to be performed when the annotation is activated.
     * @param[in] frDoc			The currently opened document.
     * @param[in] frDocView		The current document view.
     * @return TRUE if the plug-in customizes the action process successfully. If you do not want to customize the action process, you must return
     * FALSE, so that Foxit Reader can implement the default action process.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1
     */
    FS_BOOL (*FRActionHandlerLink)(FS_LPVOID clientData, FPD_Action action, FR_Document frDoc, FR_DocView frDocView);
    /* @CALLBACKEND */

}FR_ActionHandlerCallbacksRec, *FR_ActionHandlerCallbacks;
/* @CALLBACKGROUPEND */

/* @DEFGROUPSTART FRDataCollectionFunctionNames */
/*
* @name The definitions of function name for data collection. 
*/

/*@{*/
/** @brief The function name of SelectText for data collection.*/ 
#define FR_FUNCTION_SELECTTEXT			L"SelectText"
/** @brief The function name of Find for data collection.*/ 
#define FR_FUNCTION_FIND				L"Find"
/** @brief The function name of Highlight for data collection.*/ 
#define FR_FUNCTION_HIGHLIGHT			L"Highlight"
/** @brief The function name of SquigglyUnderline for data collection.*/ 
#define FR_FUNCTION_SQUIGGLYUNDERLINE	L"SquigglyUnderline"
/** @brief The function name of Underline for data collection.*/ 
#define FR_FUNCTION_UNDERLINE			L"Underline"
/** @brief The function name of Typewriter for data collection.*/ 
#define FR_FUNCTION_TYPEWRITER			L"Typewriter"
/** @brief The function name of Strikeout for data collection.*/ 
#define FR_FUNCTION_STRIKEOUT			L"Strikeout"
/** @brief The function name of ReplaceText for data collection.*/ 
#define FR_FUNCTION_REPLACETEXT			L"ReplaceText"
/** @brief The function name of InsertText for data collection.*/ 
#define FR_FUNCTION_INSERTTEXT			L"InsertText"
/** @brief The function name of Callout for data collection.*/ 
#define FR_FUNCTION_CALLOUT				L"Callout"
/** @brief The function name of Textbox for data collection.*/ 
#define FR_FUNCTION_TEXTBOX				L"Textbox"
/** @brief The function name of Note for data collection.*/ 
#define FR_FUNCTION_NOTE				L"Note"
/** @brief The function name of SnapShot for data collection.*/ 
#define FR_FUNCTION_SNAPSHOT			L"SnapShot"
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FRDataCollectionActionNames */
/*
* @name The definitions of action name for data collection. 
*/

/*@{*/
/** @brief The action name of Copy for data collection.*/ 
#define ACTION_COPY		L"Copy"
/** @brief The action name of Cut for data collection.*/ 
#define ACTION_CUT		L"Cut"
/** @brief The action name of Find for data collection.*/ 
#define ACTION_FIND		L"Find"
/** @brief The action name of Select for data collection.*/ 
#define ACTION_SELECT	L"Select"
/** @brief The action name of Edit for data collection.*/ 
#define ACTION_EDIT		L"Edit"
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKGROUPSTART FR_DataCollectionHandlerCallbacks */
/**
 * @brief  The callbacks for data collection handler. The callbacks are called by Foxit Reader when some action occurs. Then you
 * can implement the callbacks to collect the data.
 * @deprecated Internal use.
 */
typedef struct _fr_datacollectionhandler_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DataCollectionHandlerCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FROnCollectNormalData */
    /**
    * @brief It is called by Foxit Reader when some action occurs.
    *
    * It is called by Foxit Reader when some action occurs. Then you can implement the callbacks to collect the normal data differs from the bitmap data.
     * @param[in] clientData	The user-supplied data.
     * @param[in] lpwsFunction	The function name whose action occurs. See <a>FRDataCollectionFunctionNames</a>.
     * @param[in] lpwsAction	The action name. See <a>FRDataCollectionActionNames</a>.
     * @param[in] lpwsContent	The normal data you can collect.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FROnCollectNormalData)(FS_LPVOID clientData, FS_LPCWSTR lpwsFunction, FS_LPCWSTR lpwsAction, FS_LPCWSTR lpwsContent);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FROnCollectBitmapData */
    /**
    * @brief It is called by Foxit Reader when some action occurs.
    *
    * It is called by Foxit Reader when some action occurs. Then you can implement the callbacks to collect the bitmap data differs from the normal data.
     * @param[in] clientData	The user-supplied data.
     * @param[in] lpwsFunction	The function name whose action occurs. See <a>FRDataCollectionFunctionNames</a>.
     * @param[in] lpwsAction	The action name. See <a>FRDataCollectionActionNames</a>.
     * @param[in] bitmap		The bitmap data you can collect.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FROnCollectBitmapData)(FS_LPVOID clientData, FS_LPCWSTR lpwsFunction, FS_LPCWSTR lpwsAction, FS_DIBitmap bitmap);
    /* @CALLBACKEND */
	
	/* @CALLBACKSTART FROnCollectNormalData2 */
	/**
	* @brief It is called by Foxit Reader when some action occurs. 
	*
	* It is called by Foxit Reader when some action occurs. Then you can implement the callbacks to collect the normal data differs from the bitmap data.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] lpwsFunction	The function name whose action occurs. See <a>FRDataCollectionFunctionNames</a>.
	 * @param[in] lpwsAction	The action name. See <a>FRDataCollectionActionNames</a>.
	 * @param[in] lpwsContent	The normal data you can collect.
	 * @param[in] nLevel		The detail level of the data.
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 8.2.1
     */
	void (*FROnCollectNormalData2)(FS_LPVOID clientData, FS_LPCWSTR lpwsFunction, FS_LPCWSTR lpwsAction, FS_LPCWSTR lpwsContent, FS_INT32 nLevel);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnCollectBitmapData2 */
	/**
	* @brief It is called by Foxit Reader when some action occurs. 
	*
	* It is called by Foxit Reader when some action occurs. Then you can implement the callbacks to collect the bitmap data differs from the normal data.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] lpwsFunction	The function name whose action occurs. See <a>FRDataCollectionFunctionNames</a>.
	 * @param[in] lpwsAction	The action name. See <a>FRDataCollectionActionNames</a>.
	 * @param[in] bitmap		The bitmap data you can collect.
	 * @param[in] nLevel		The detail level of the data.
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 8.2.1
     */
	void (*FROnCollectBitmapData2)(FS_LPVOID clientData, FS_LPCWSTR lpwsFunction, FS_LPCWSTR lpwsAction, FS_DIBitmap bitmap, FS_INT32 nLevel);
	/* @CALLBACKEND */

}FR_DataCollectionHandlerCallbacksRec, *FR_DataCollectionHandlerCallbacks;
/* @CALLBACKGROUPEND */

/* @DEFGROUPSTART FROEMVersion */
/*
* @name The definitions for OEM version. 
* @deprecated internal use.
*/

/*@{*/
/** @brief The general version for OEM.*/ 
#define FR_OEM_GENERAL "OEM"
/** @brief The OEM version of HP commercial.*/ 
#define FR_OEM_HPCM	"HPCommercial"
/** @brief The OEM version of HP consumer.*/ 
#define FR_OEM_HPCS	"HPConsumer"
/** @brief The OEM version of Asus.*/ 
#define FR_OEM_ASUS	"Asus"
/** @brief The OEM version of HP Lenovo.*/ 
#define FR_OEM_LENOVO	"Lenovo"
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKGROUPSTART FR_POEventCallbacks */

/**
 * @brief A callback set for page organizing event handler. These callbacks will be invoked when Foxit Reader does the page organizing,
 * such as adding pages, deleting pages, replacing pages and so on. See <a>FRAppRegisterPOEventHandler</a>.
 */
typedef struct _fr_poevent_callbacks_
{

    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_POEventCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;


    /* @CALLBACKSTART FRPOOnBeforeInsertPages */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called before the Foxit Reader inserts the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are inserted to.
     * @param[in] nInsertAt		The index where the pdf pages are inserted at.
     * @param[in] nCount		The count the pdf pages are inserted.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnBeforeInsertPages)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nInsertAt, FS_INT32 nCount);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnDoInsertPagesDictFinish */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called when the Foxit Reader finishes to insert the dictionaries to the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] fpdDesDoc		The dest document.
     * @param[in] nInsertAt		The index where the pdf pages are inserted at.
     * @param[in] fpdSrcDoc		The source document.
     * @param[in] arrSrcPages	The array to store the source pages
     * @param[in] bEntireDoc	It indicates whether the operation is on the entire document.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnDoInsertPagesDictFinish)(FS_LPVOID clientData, FPD_Document fpdDesDoc, FS_INT32 nInsertAt, FPD_Document fpdSrcDoc, FS_WordArray arrSrcPages, FS_BOOL bEntireDoc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnAfterInsertPages */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called after the Foxit Reader inserts the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are inserted to.
     * @param[in] nInsertAt		The index where the pdf pages are inserted at.
     * @param[in] nCount		The count the pdf pages are inserted.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnAfterInsertPages)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nInsertAt, FS_INT32 nCount);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnBeforeDeletePages */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called before the Foxit Reader deletes the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are deleted from.
     * @param[in] arrDelPages	The index of the pages that has been deleted.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnBeforeDeletePages)(FS_LPVOID clientData, FR_Document frDoc, FS_WordArray arrDelPages);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnAfterDeletePages */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called after the Foxit Reader deletes the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are deleted from.
     * @param[in] arrDelPages	The index of the pages that has been deleted.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnAfterDeletePages)(FS_LPVOID clientData, FR_Document frDoc, FS_WordArray arrDelPages);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnBeforeReplacePages */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called before the Foxit Reader replaces the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are replaced.
     * @param[in] nStart		The start index where the pdf pages are replaced from.
     * @param[in] fpdSrcDoc		The source document.
     * @param[in] arrSrcPages	The array to store the source pages.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnBeforeReplacePages)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nStart, FPD_Document fpdSrcDoc, FS_WordArray arrSrcPages);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnAfterReplacePages */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called after the Foxit Reader replaces the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are replaced.
     * @param[in] nStart		The start index where the pdf pages are replaced from.
     * @param[in] fpdSrcDoc		The source document.
     * @param[in] arrSrcPages	The array to store the source pages.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnAfterReplacePages)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nStart, FPD_Document fpdSrcDoc, FS_WordArray arrSrcPages);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnBeforeSwapTwoPage */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called before the Foxit Reader swaps two pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are swapped.
     * @param[in] iPage1		The first page index.
     * @param[in] iPage2		The second page index.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnBeforeSwapTwoPage)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 iPage1, FS_INT32 iPage2);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnAfterSwapTwoPage */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called after the Foxit Reader swaps two pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are swapped.
     * @param[in] iPage1		The first page index.
     * @param[in] iPage2		The second page index.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnAfterSwapTwoPage)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 iPage1, FS_INT32 iPage2);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnBeforeRotatePage */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called before the Foxit Reader rotates the pdf page.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf page is rotated.
     * @param[in] iPage			The page index.
     * @param[in] nRotate		The rotation value.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnBeforeRotatePage)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 iPage, FS_INT32 nRotate);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnAfterRotatePage */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called after the Foxit Reader rotates the pdf page.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf page is rotated.
     * @param[in] iPage			The page index.
     * @param[in] nRotate		The rotation value.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnAfterRotatePage)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 iPage, FS_INT32 nRotate);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnBeforeResizePage */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called before the Foxit Reader resizes the pdf page.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf page is resized.
     * @param[in] iPage			The page index.
     * @param[in] MediaBox		The media box.
     * @param[in] CropBox		The crop box.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnBeforeResizePage)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 iPage, FS_FloatRect MediaBox, FS_FloatRect CropBox);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnAfterResizePage */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called after the Foxit Reader resizes the pdf page.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf page is resized.
     * @param[in] iPage			The page index.
     * @param[in] MediaBox		The media box.
     * @param[in] CropBox		The crop box.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnAfterResizePage)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 iPage, FS_FloatRect MediaBox, FS_FloatRect CropBox);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnBeforeExtractPage */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called before the Foxit Reader extracts the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are extracted.
     * @param[in] arrSrcPages	The array to store the source pages.
     * @param[in] fpdDstDoc		The dest document.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnBeforeExtractPage)(FS_LPVOID clientData, FR_Document frDoc, FS_WordArray arrSrcPages, FPD_Document fpdDstDoc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnAfterExtractPage */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called after the Foxit Reader extracts the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are extracted.
     * @param[in] arrSrcPages	The array to store the source pages.
     * @param[in] fpdDstDoc		The dest document.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnAfterExtractPage)(FS_LPVOID clientData, FR_Document frDoc, FS_WordArray arrSrcPages, FPD_Document fpdDstDoc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnBeforeModifyPageAttr */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called before the Foxit Reader modifies the attributes of the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the attributes of the pdf pages are modified.
     * @param[in] nStart		The start index.
     * @param[in] nCount		The page count.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnBeforeModifyPageAttr)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nStart, FS_INT32 nCount);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnAfterModifyPageAttr */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called after the Foxit Reader modifies the attributes of the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the attributes of the pdf pages are modified.
     * @param[in] nStart		The start index.
     * @param[in] nCount		The page count.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnAfterModifyPageAttr)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nStart, FS_INT32 nCount);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnBeforeMovePages */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called before the Foxit Reader moves the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are moved.
     * @param[in] nMoveTo		The index to move.
     * @param[in] ArrToMove		The array to store the pages.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnBeforeMovePages)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nMoveTo, FS_WordArray ArrToMove);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnAfterMovePages */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called after the Foxit Reader moves the pdf pages.
     *
     * @param[in] clientData	The user-supplied data.
     * @param[in] frDoc			The document where the pdf pages are moved.
     * @param[in] nMoveTo		The index to move.
     * @param[in] ArrToMove		The array to store the pages.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnAfterMovePages)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nMoveTo, FS_WordArray ArrToMove);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPOOnRelease */
    /**
     * @brief A callback for page organizing event handler.
     *
     * It is called when the Foxit Reader releases the page organizing event handler.
     *
     * @param[in] clientData	The user-supplied data.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     */
    void (*FRPOOnRelease)(FS_LPVOID clientData);
    /* @CALLBACKEND */
	
	/* @CALLBACKSTART FRPOOnBeforeReversePages */
	/**
	 * @brief A callback for page organizing event handler.
	 *
	 * It is called before the Foxit Reader reverses the pdf pages.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document where the pdf pages are reversed.
	 * @param[in] arrOldPageIdx	The array of old pages.
	 * @param[in] arrNewPageIdx	The array of new pages.
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.6
	 */
	void(*FRPOOnBeforeReversePages)(FS_LPVOID clientData, FR_Document frDoc, FS_DWordArray arrOldPageIdx, FS_DWordArray arrNewPageIdx);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPOOnAfterReversePages */
	/**
	 * @brief A callback for page organizing event handler.
	 *
	 * It is called after the Foxit Reader reverses the pdf pages.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] frDoc			The document where the pdf pages are reversed.
	 * @param[in] arrOldPageIdx	The array of old pages.
	 * @param[in] arrNewPageIdx	The array of new pages.
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.6
	 */
	void(*FRPOOnAfterReversePages)(FS_LPVOID clientData, FR_Document frDoc, FS_DWordArray arrOldPageIdx, FS_DWordArray arrNewPageIdx);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPOOnAfterExtractPageEx */
	/**
	 * @brief A callback for page organizing event handler.
	 *
	 * It is called after the Foxit Reader extracts the pdf pages.
	 *
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] frDoc	            The source file
	 * @param[in] arrSrcPages	    extract pages
	 * @param[in] wsDestfilepath	extract dest filepath
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	 */
	void(*FRPOOnAfterExtractPageEx)(FS_LPVOID clientData, FR_Document frDoc, FS_WordArray arrSrcPages, const FS_WideString& wsDestfilepath);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPOOnBeforeRotatePages */
	/**
	 * @brief A callback for page organizing event handler.
	 *
	 * It is called before the Foxit Reader rotate the pdf pages.
	 *
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] frDoc	            The source file.
	 * @param[in] arrPages	        The rotate pages.
	 * @param[in] nRotate	        The rotate value.
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.2.0
	 */
	void(*FRPOOnBeforeRotatePages)(FS_LPVOID clientData, FR_Document pDoc, FS_WordArray arrPages, FS_INT32 nRotate);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPOOnAfterRotatePages */
	/**
	 * @brief A callback for page organizing event handler.
	 *
	 * It is called after the Foxit Reader rotate the pdf pages.
	 *
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] frDoc	            The source file.
	 * @param[in] arrPages	        The rotate pages.
	 * @param[in] nRotate	        The rotate value.
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.2.0
	 */
	void(*FRPOOnAfterRotatePages)(FS_LPVOID clientData, FR_Document pDoc, FS_WordArray arrPages, FS_INT32 nRotate);
	/* @CALLBACKEND */

}FR_POEventCallbacksRec, *FR_POEventCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_RibbonRecentFileEventCallbacks */

/**
 * @brief A callback set for Ribbon recent file list event handler. These callbacks will be invoked when the item of the recent file
 * list is pinned or removed. See <a>FRAppRegisterRibbonRecentFileEventHandler</a>.
 * @deprecated internal use.
 */
typedef struct _fr_ribbonrecentfileevent_callbacks_
{
    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_RibbonRecentFileEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRRibbonRecentFileChangItemPinned */
	/**
     * @brief A callback for Ribbon recent file list event handler.
	 *
	 * It is called when the item of the recent file list is pinned.
	 *
	 * @param[in] clientData			The user-supplied data.
	 * @param[in] lpcsRecentListName	The recent file list name.
	 * @param[in] nIndex				The item index of the recent file list.
	 * @param[in] lpwsFilePath			The recent file path.
	 * @param[in] nPinned				The status of the pin, 0 for not pinned, 1 for pinned.
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
     */
	void (*FRRibbonRecentFileChangItemPinned)(FS_LPVOID clientData, FS_LPCSTR lpcsRecentListName, FS_INT32 nIndex, FS_LPCWSTR lpwsFilePath, FS_INT32 nPinned);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRRibbonRecentFileRemoveItem */
	/**
     * @brief A callback for Ribbon recent file list event handler.
	 *
	 * It is called when the item of the recent file list is removed.
	 *
	 * @param[in] clientData			The user-supplied data.
	 * @param[in] lpcsRecentListName	The recent file list name.
	 * @param[in] nIndex				The item index of the recent file list.
     * @param[in] lpwsFilePath			The recent file path.
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
     */
	void (*FRRibbonRecentFileRemoveItem)(FS_LPVOID clientData, FS_LPCSTR lpcsRecentListName, FS_INT32 nIndex, FS_LPCWSTR lpwsFilePath);
	/* @CALLBACKEND */
}FR_RibbonRecentFileEventCallbacksRec, *FR_RibbonRecentFileEventCallbacks;
/* @CALLBACKGROUPEND */

/* @ENUMSTART */
/** @brief The name definition of subscription flow.*/
/* @deprecated Internal use.*/
enum FRSubscriptionFlowName
{
    FR_SUBSCRIBE,				/**Subscribe. */
    FR_EXTEND_SUBSCRIBE,		/**Extend the subscription. */
    FR_SUBSCRIB_MANAGE,			/**Manage the subscription. */
    FR_EXTEND_SUBSCRIBE_AUTO,	/**Extend the subscription auto. */
    FR_SUBSCRIB_DEACTIVE
};
/* @ENUMEND */

/* @CALLBACKGROUPSTART FR_SubscriptionProviderCallbacks */
/**
 * @brief A callback set for subscription provider. See <a>FRAppSetSubscriptionProvider</a>.
 * @deprecated internal use.
 */
typedef struct _fr_subscriptionprovider_callbacks_
{

    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_SubscriptionProviderCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRShowSubscribeRibbonUI */
    /**
     * @brief A callback for subscription provider.
	 *
	 * It is called to notify the plug-in to check that whether to show the subscription UI or not.
	 *
	 * @param[in] clientData			The user-supplied data.
	 * @param[in] subWorkflowName		The specified work flow name. Related to <a>FRSubscriptionFlowName</a>
	 * @return TRUE for showing the subscription UI, otherwise not
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
     */
    FS_BOOL (*FRShowSubscribeRibbonUI)(FS_LPVOID clientData, FRSubscriptionFlowName subWorkflowName);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRStartSubscribeWorkflow */
    /**
     * @brief A callback for subscription provider.
	 *
	 * It is called when a subscription work flow starts.
	 *
	 * @param[in] clientData			The user-supplied data.
	 * @param[in] subWorkflowName		The specified work flow name. Related to <a>FRSubscriptionFlowName</a>
	 * @param[out] outReturnValue		It receives the result.
	 * @return TRUE for success, otherwise failure.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
     */
    FS_BOOL (*FRStartSubscribeWorkflow)(FS_LPVOID clientData, FRSubscriptionFlowName subWorkflowName, FS_WideString outReturnValue);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRIsLicenseRevoked */
    /**
     * @brief A callback for subscription provider.
     *
     * It is called to notify the plug-in to check that whether the license is revoked or not.
     *
     * @param[in] clientData			The user-supplied data.
     * @return TRUE means the license is revoked, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
     */
    FS_BOOL (*FRIsLicenseRevoked)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRShowSubscribeFlash */
    /**
     * @brief A callback for subscription provider.
     *
     * It is called to notify the plug-in to show the subscription flash.
     *
     * @param[in] clientData			The user-supplied data.
     * @return TRUE when succeed to show the subscription flash, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
     */
    FS_BOOL (*FRShowSubscribeFlash)(FS_LPVOID clientData);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRIsEducation */
	/**
	* @brief A callback for subscription provider.
	*
	* It is called to notify the plug-in to show the subscription flash.
	*
	* @param[in] clientData			The user-supplied data.
	* @return TRUE the subscribed user is education user.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	FS_BOOL(*FRIsEducation)(FS_LPVOID clientData);
	/* @CALLBACKEND */

}FR_SubscriptionProviderCallbacksRec, *FR_SubscriptionProviderCallbacks;
/* @CALLBACKGROUPEND */

/* @ENUMSTART */
/** @brief the version of PDFA document.*/
enum FRPDFA_PDFVersion {
	FRPDFA_1a_Verify = 1, /** . */
	FRPDFA_1b_Verify, /** . */
	FRPDFA_2a_Verify, /** . */
	FRPDFA_2b_Verify, /** . */
	FRPDFA_2u_Verify, /** . */
	FRPDFA_3a_Verify, /** . */
	FRPDFA_3b_Verify, /** . */
	FRPDFA_3u_Verify, /** . */
	FRPDFA_1a_Convert, /** . */
	FRPDFA_1b_Convert, /** . */
	FRPDFA_2a_Convert, /** . */
	FRPDFA_2b_Convert, /** . */
	FRPDFA_2u_Convert, /** . */
	FRPDFA_3a_Convert, /** . */
	FRPDFA_3b_Convert, /** . */
	FRPDFA_3u_Convert, /** . */
	FRPDFA_Remove, /** . */
	FRPDFE_Verify, /** . */
	FRPDFE_Convert, /** . */
	FRPDFE_Remove, /** . */
	FRPDFVT_Verify, /** . */
	FRPDFX_1a_Verify, /** . */
	FRPDFX_3_Verify, /** . */
	FRPDFX_4_Verify, /** . */
	FRPDFX_4p_Verify, /** . */
	FRPDFX_5g_Verify, /** . */
	FRPDFX_5pg_Verify, /** . */
	FRPDFX_1a_GRACol_2006_Convert, /** . */
	FRPDFX_1a_ISO_V2_ECI_Convert, /** . */
	FRPDFX_1a_JC_2001_Convert, /** . */
	FRPDFX_1a_PSO_Convert, /** . */
	FRPDFX_3_GRACol_2006_Convert, /** . */
	FRPDFX_3_ISO_V2_ECI_Convert, /** . */
	FRPDFX_3_JC_2001_Convert, /** . */
	FRPDFX_3_PSO_Convert, /** . */
	FRPDFX_4_GRACol_2006_Convert, /** . */
	FRPDFX_4_ISO_V2_ECI_Convert, /** . */
	FRPDFX_4_JC_2001_Convert, /** . */
	FRPDFX_4_LayerView_Convert, /** . */
	FRPDFX_4_PSO_Convert,
	FRPDFX_4p_Convert,
	FRPDFX_Remove
};
/* @ENUMEND */

/* @CALLBACKGROUPSTART FR_PDFAPluginHandlerCallbacks */
/**
* @brief 
* @deprecated Internal use.
*/
typedef struct _fr_pdfaPluginHandler_callbacks_
{

	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_PDFAPluginHandlerCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID clientData;

	/* @CALLBACKSTART FRPDFA_SaveAsPDFA */
	/**
	* @brief .
	* @param[in] clientData			The user-supplied data.
	* @param[in] pRDoc              The pdf document
	* @param[in] pVersion  			the version of PDFA document. Related to <a>FRPDFA_PDFVersion</a>
	* @param[in] wsPathSuffix       
	* @return .
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 9.1
	*/
	FS_BOOL (*FRPDFA_SaveAsPDFA)(FS_LPVOID clientData, FR_Document pRDoc, const FRPDFA_PDFVersion pVersion, FS_WideString wsPathSuffix);
	/* @CALLBACKEND */

}FR_PDFAPluginHandlerCallbacksRec, *FR_PDFAPluginHandlerCallbacks;
/* @CALLBACKGROUPEND */

/* @ENUMSTART */
/** @brief The definitions of log levels.*/
enum FR_LOG_LEVEL
{
	FR_INFO = 0,		/** The info level. */
	FR_WARNING = 1,		/** The warning level. */
	FR_ERROR = 2,		/** The error level. */
	FR_FATAL = 3		/** The fatal level. */
};
/* @ENUMEND */

/* @CALLBACKSTART FRShareMessageBarDestoryProc */
/**
* @brief The callback will be invoked when message bar release.
 * @param[in] hWnd			The window of shareMessagebar.
 * @param[in] pClientData	The client data passed through <a>FRAppAddShareMessageBar</a>
 * @return void
 * @note
 * @since  <a>SDK_LATEEST_VERSION</a> > 11.0
 * @see FRAppAddShareMessageBar
 */
typedef void(*FRShareMessageBarDestoryProc)(FS_HWND hWnd, FS_LPVOID pClientData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRShareMessageBarDestoryProc */
/**
 * @brief The callback will be invoked when show message bar.
 * @param[in] pClientData	The client data passed through <a>FRAppAddShareMessageBar</a>
 * @return FS_HWND  The message bar FS_HWND in plugin.
 * @note
 * @since  <a>SDK_LATEEST_VERSION</a> > 11.0
 * @see FRAppAddShareMessageBar
 */
typedef FS_HWND(*FRShareMessageBarCreateProc)(FS_LPVOID pClientData);
/* @CALLBACKEND */

/* FR_EmptyFrameWndViewEventHandler */

#ifndef FR_EMPTYFRAMEWNDVIEWEVENTHANDLER
#define FR_EMPTYFRAMEWNDVIEWEVENTHANDLER
/**
 * @brief  (Windows Only) The <a>FR_EmptyFrameWndViewEventHandler</a> object represents the event handler of the empty frame window view. The plug-in can register
 * the event handler to process the event when the plug-in creates the empty frame window. See <a>FRAppCreateEmptyFrameViewEventHandler</a> and <a>FRAppCreateAnEmptyFrameWnd2</a>.
 * @deprecated Internal use
 */
typedef struct _t_FR_EmptyFrameWndViewEventHandler* FR_EmptyFrameWndViewEventHandler;
#endif

/* @CALLBACKGROUPSTART FR_EmptyFrameWndViewEventHandlerCallbacks */

/**
 * @brief (Windows Only) A callback set for the event handler of the empty frame window view. See <a>FRAppCreateEmptyFrameViewEventHandler</a>.
 * @deprecated Internal use
 */
typedef struct _fr_emptyframewndvieweventhandler_callbacks_
{

    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EmptyFrameWndViewEventHandlerCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FREmptyFrameViewOnActivate */
    /**
     * @brief A callback for the event handler of the empty frame window view.
     *
     * It is called to notify the plug-in when the view is activated.
     *
     * @param[in] clientData			The user-supplied data.
     * @param[in] hView					The empty frame window view.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
	 * @deprecated this callback is replace by <a>FREmptyFrameViewOnActivate2</a>
     */
    void (*FREmptyFrameViewOnActivate)(FS_LPVOID clientData, FS_HWND hView);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FREmptyFrameViewOnDeactivate */
    /**
     * @brief A callback for the event handler of the empty frame window view.
     *
     * It is called to notify the plug-in when the view is deactivated.
     *
     * @param[in] clientData			The user-supplied data.
     * @param[in] hView					The empty frame window view.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
	 * @deprecated this callback is replace by <a>FREmptyFrameViewOnDeactivate2</a>
     */
    void (*FREmptyFrameViewOnDeactivate)(FS_LPVOID clientData, FS_HWND hView);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FREmptyFrameViewOnViewSize */
    /**
     * @brief A callback for the event handler of the empty frame window view.
     *
     * It is called to notify the plug-in when the size of the view is changed.
     *
     * @param[in] clientData			The user-supplied data.
     * @param[in] hView					The empty frame window view.
     * @param[in] rtClient				The rectangle area of the view.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    void (*FREmptyFrameViewOnViewSize)(FS_LPVOID clientData, FS_HWND hView, FS_Rect rtClient);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FREmptyFrameViewOnSetFocus */
    /**
     * @brief A callback for the event handler of the empty frame window view.
     *
     * It is called to notify the plug-in when the view is focused.
     *
     * @param[in] clientData			The user-supplied data.
     * @param[in] hView					The empty frame window view.
     * @param[in] hOldWnd				The view of the old one.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    void (*FREmptyFrameViewOnSetFocus)(FS_LPVOID clientData, FS_HWND hView, FS_HWND hOldWnd);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FREmptyFrameViewOnWillClose */
    /**
     * @brief A callback for the event handler of the empty frame window view.
     *
     * It is called to notify the plug-in when the view will be closed.
     *
     * @param[in] clientData			The user-supplied data.
     * @param[in] hView					The empty frame window view.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    void (*FREmptyFrameViewOnWillClose)(FS_LPVOID clientData, FS_HWND hView);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FREmptyFrameViewOnViewCreate */
    /**
     * @brief A callback for the event handler of the empty frame window view.
     *
     * It is called to notify the plug-in when the view is created.
     *
     * @param[in] clientData			The user-supplied data.
     * @param[in] hView					The empty frame window view.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3
     */
    void (*FREmptyFrameViewOnViewCreate)(FS_LPVOID clientData, FS_HWND hView);
    /* @CALLBACKEND */
    /* @CALLBACKSTART FREmptyFrameViewOnDidClose */
    /**
     * @brief A callback for the event handler of the empty frame window view.
     *
     * It is called to notify the plug-in when the view had been closed.
     *
     * @param[in] clientData			The user-supplied data.
     * @param[in] hFrameWnd				The empty frame window.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 9.0
     */
    void (*FREmptyFrameViewOnDidClose)(FS_LPVOID clientData, FS_HWND hFrameWnd);
    /* @CALLBACKEND */
    /* @CALLBACKSTART FREmptyFrameViewOnWillDetachChildFrame */
    /**
    * @brief A callback for the event handler of the childFrame window detach from mainframe.
    *
    * It is called to notify the plug-in when the view will been detach.
    *
    * @param[in] clientData			The user-supplied data.
    * @param[in] hFrameWnd				The empty frame window.
    * @return void.
    * @note
    * @since <a>SDK_LATEEST_VERSION</a> > 9.4
    */
    void(*FREmptyFrameViewOnWillDetachChildFrame)(FS_LPVOID clientData, FS_HWND hFrameWnd);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FREmptyFrameViewOnActivate2 */
    /**
    * @brief A callback for the event handler of the empty frame window view.
    *
    * It is called to notify the plug-in when the view is activated.
    *
    * @param[in] clientData			The user-supplied data.
    * @param[in] hView					The empty frame window view.
    * @param[in] hMainframe				The empty frame window mainframe.
    * @return void.
    * @note
    * @since <a>SDK_LATEEST_VERSION</a> > 9.4
    */
    void(*FREmptyFrameViewOnActivate2)(FS_LPVOID clientData, FS_HWND hView, FS_HWND hMainframe);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FREmptyFrameViewOnDeactivate2 */
    /**
    * @brief A callback for the event handler of the empty frame window view.
    *
    * It is called to notify the plug-in when the view is deactivated.
    *
    * @param[in] clientData			The user-supplied data.
    * @param[in] hView					The empty frame window view.
    * @param[in] hMainframe				The empty frame window mainframe.
    * @return void.
    * @note
    * @since <a>SDK_LATEEST_VERSION</a> > 9.4
    */
    void(*FREmptyFrameViewOnDeactivate2)(FS_LPVOID clientData, FS_HWND hView, FS_HWND hMainframe);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FREmptyFrameViewGetDisplayViewHWnd */
    /**
    * @brief A callback for the event handler to get display view ptr.
    *
    * It is called to get display view from plug-in.
    *
    * @param[in] clientData			The user-supplied data.
    * @param[in] hPluginView		The window handle of pluginview.
    * @return HWND					The display view handle.
    * @note
    * @since <a>SDK_LATEEST_VERSION</a> > 9.4
    */
    FS_HWND (*FREmptyFrameViewGetDisplayViewHWnd)(FS_LPVOID clientData, FS_HWND hPluginView);
    /* @CALLBACKEND */

}FR_EmptyFrameWndViewEventHandlerCallbacksRec, *FR_EmptyFrameWndViewEventHandlerCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_PortfolioEventCallbacks */

/**
* @brief A callback set for portfolio document event handler. See <a>FRAppRegisterPortfolioEventHandler</a>.
* @deprecated Internal use.
*/
typedef struct _fr_protfolio_doc_event_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_PortfolioEventCallbacksRec</a>). */
	unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;
    /* @CALLBACKSTART FRPortfolioFinishRender */
    /**
    * @brief				A callback for document-level event handler.
    *
    * It is called whenever a portfolio document finished re
    *
    * @param[in] clientData	The user-supplied data.
    * @param[in] doc		The <a>FR_Document</a> that will be rendered.
    * @note
    */
    void(*FRPortfolioFinishRender)(FS_LPVOID clientData, FR_Document doc);
    /* @CALLBACKEND */
}FR_PortfolioEventCallbacksRec, *FR_PortfolioEventCallbacks;
/* @CALLBACKGROUPEND */

/* @STRUCTSTART FR_SensorData*/
/**
* @brief A data structure representing the Sensor. It was used by <a>FRAppCollectSensorData</a>
* @deprecated Internal use.
*/
typedef struct __FR_SensorData__
{
    /** The Name. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsName;
    /** The Feature. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsFeatureName;
    /** The Type. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsFeatureType;
    /** The UI Element. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsCategory;
    /** The UI Element. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsUiElement;
    /** The Description. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsDescription;
    /** The extra Information. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsExtraInformation;
    /** The productName Information. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsProductName;
    /** The productVersion Information. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsProductVersion;
    /** The pruductType Information. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsProductType;
    /** The userID Information. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsUserID;
    /** The duration Information. Invokes <a>FSWideStringNew</a> to initialize. */
    FS_WideString wsDuration;
    __FR_SensorData__()
    {
        wsName = NULL;
        wsFeatureName = NULL;
        wsFeatureType = NULL;
        wsCategory = NULL;
        wsUiElement = NULL;
        wsDescription = NULL;
        wsExtraInformation = NULL;
        wsProductName = NULL;
        wsProductVersion = NULL;
        wsProductType = NULL;
        wsUserID = NULL;
        wsDuration = NULL;
    }
}FR_SensorData;
/* @STRUCTEND */

/* @CALLBACKGROUPSTART FR_TransitionCallbacks */

/**
* @brief A callback set for Transition . These callbacks will be invoked when Transition,  See <a>FRAppRegisterTransitionHandler</a>.
* @deprecated Internal use.
*/
typedef struct _fr_transition_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_TransitionCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void(*FRTransitonRelease)();
	FS_BOOL(*FRTransitonEnum)(FS_LPVOID clientData, FS_LPVOID pClientData);
	FS_ByteString(*FRTransitonGetType)(FS_LPVOID clientData);
	void(*FRTransitonExcute)(FS_LPVOID clientData, FPD_Object pDict,FS_HDC hdc,FS_Rect rect, FS_DIBitmap pDIBitmapCache, FS_DIBitmap pDIBitmapSrc,FS_INT32 duration);
	void(*FRTransitonInitTransDict)(FS_LPVOID clientData, FPD_Object transDict);
	void(*FRTransitonCompleteTransDict)(FS_LPVOID clientData, FS_WideString csUIName, FPD_Object transDict);
	void(*FRTransitonDoProperties)(FS_LPVOID clientData, FS_WideString csUIName, FPD_Object trans);
	FS_ByteString(*FRTransitonGetName)(FS_LPVOID clientData, FPD_Object pDict);
	FS_WideString(*FRTransitonGetTypeUIName)(FS_LPVOID clientData);
	FS_BOOL(*FRTransitonGetBiDirEnable)(FS_LPVOID clientData);
	FS_WideString(*FRTransitonGetButtonText)(FS_LPVOID clientData);
	FS_WideString(*FRTransitonGetInstructions)(FS_LPVOID clientData);
	FS_INT32(*FRTransitonGetItemCount)(FS_LPVOID clientData);
	FS_ByteString(*FRTransitonGetItemName)(FS_LPVOID clientData,FS_INT32 item);
	FS_WideString(*FRTransitonGetItemUIName)(FS_LPVOID clientData, FS_INT32 item);
	FS_BOOL(*FRTransitonGetSmoothActionEnabled)(FS_LPVOID clientData);
	FS_WideString(*FRTransitonGetStringOneText)(FS_LPVOID clientData);
	FS_WideString(*FRTransitonGetStringTwoText)(FS_LPVOID clientData);
}FR_TransitionCallbacksRec, *FR_TransitionCallbacks;
/* @CALLBACKGROUPEND */

/* @STRUCTSTART FR_IdentityInfo*/
/**
 * @brief The infomation of identity. Related to <a>FRAppGetPreferenceIdentity</a>
 */
typedef struct __FR_INDENTIFYINFO__
{
    FS_LPCWSTR csIdentityFirstName; /**First Name*/
    FS_LPCWSTR csIdentityLastName; /** Last Name*/
    FS_LPCWSTR csIdentityTitle;/** Title  */
    FS_LPCWSTR csOrganizationName;/**Organization name */
    FS_LPCWSTR csOrganizationUnit;/**Department name*/
    FS_LPCWSTR csEmailAddress;/** Email */
}FR_IdentityInfo,*FR_PIdentityInfo;
/* @STRUCTEND */

/*@ENUMSTART*/
enum FR_JSActionReturn
{
    FRJSACTION_DOCDESTROY = -1,
    FRJSACTION_FAILED = 0,
    FRJSACTION_SUCCESS = 1
};
/*@ENUMEND*/

/* @STRUCTSTART FR_SignatureInfo*/
typedef struct __FR_FileAttachmentInfo__
{
	__FR_FileAttachmentInfo__()
	{
		wsPath = L"";
		wsName = L"";
		wsDes = L"";
		bShowOverWriteTips = false;
	}

	/** The size of data structure. */
	unsigned long lStructSize;

	/** The file attachment path. */
	FS_LPCWSTR wsPath;
	
	/** The file attachment name. */
	FS_LPCWSTR wsName;
	
	/** The file attachment description. */
	FS_LPCWSTR wsDes;
	
	/** If show overwrite tips when the attachment has already been added. */
	FS_BOOLEAN bShowOverWriteTips;
}FR_FileAttachmentInfo;
/* @STRUCTEND*/

/* @DEFGROUPSTART FR_MesasureUnit */
/**
* @brief The definition of measure unit. Related to <a>FRAppGetCurMeasurementUnits</a>
*/
/*@{*/
/** @brief Point unit.*/
#define FR_UNIT_POINT	0

/** @brief Inch unit.*/
#define FR_UNIT_INCH	1 

/** @brief Centimeter unit.*/
#define FR_UNIT_CM		2

/** @brief Pica unit.*/
#define FR_UNIT_PICA	3

/** @brief Millimeter unit*/
#define FR_UNIT_MM		4
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */


/* @OBJSTART FR_Language */
#ifndef FR_LANGUAGE
#define FR_LANGUAGE
/**
 * @brief The <a>FR_Language</a> object is used to change the language for Foxit Reader plug-in UI. 
 * You can create it by <a>FRLanguageCreate</a>.
 */
typedef struct _t_FR_Language* FR_Language;
#endif

/* @DEFGROUPSTART FRLanguageName */
/**
 * @brief 
 */
 /*@{*/
/** @brief Default language.*/
#define FR_LANGUAGE_NAME_DEFAULT              0 
/** @brief Arabic language. */
#define FR_LANGUAGE_NAME_ARABIC               1
/** @brief Bulgarian language. */
#define FR_LANGUAGE_NAME_BULGARIAN            2
/** @brief Hungarian language. */
#define FR_LANGUAGE_NAME_HUNGARIAN            3
/** @brief Catalan language. */
#define FR_LANGUAGE_NAME_CATALAN              4
/** @brief Czech language. */
#define FR_LANGUAGE_NAME_CZECH                5
/** @brief Chinese-Simplified language. */
#define FR_LANGUAGE_NAME_CHINESE_SIMPLIFIED   6
/** @brief Chinese-Traditional language. */
#define FR_LANGUAGE_NAME_CHINESE_TRADITIONAL  7
/** @brief Danish language. */
#define FR_LANGUAGE_NAME_DANISH               8
/** @brief Dutch language. */
#define FR_LANGUAGE_NAME_DUTCH                9
/** @brief English language. */
#define FR_LANGUAGE_NAME_ENGLISH              10
/** @brief Estonian language. */
#define FR_LANGUAGE_NAME_ESTONIAN             11
/** @brief Finnish language. */
#define FR_LANGUAGE_NAME_FINNISH              12
/** @brief French language. */
#define FR_LANGUAGE_NAME_FRENCH               13
/** @brief Galician language. */
#define FR_LANGUAGE_NAME_GALICIAN             14
/** @brief German language. */
#define FR_LANGUAGE_NAME_GERMAN               15
/** @brief Greek language. */
#define FR_LANGUAGE_NAME_GREEK                16
/** @brief Italian language. */
#define FR_LANGUAGE_NAME_ITALIAN              17
/** @brief Korean language. */
#define FR_LANGUAGE_NAME_KOREAN               18
/** @brief Latvian language. */
#define FR_LANGUAGE_NAME_lATVIAN              19
/** @brief Lithuanian language. */
#define FR_LANGUAGE_NAME_LITHUANIAN           20
/** @brief Norwegian language. */
#define FR_LANGUAGE_NAME_NORWEGIAN            21
/** @brief Polish language. */
#define FR_LANGUAGE_NAME_POLISH               22
/** @brief Portuguese language. */
#define FR_LANGUAGE_NAME_PORTUGUESE           23
/** @brief Portuguese_Brazilian language. */
#define FR_LANGUAGE_NAME_PORTUGUESE_BRAZILIAN 24
/** @brief Romanian language. */
#define FR_LANGUAGE_NAME_ROMANIAN             25
/** @brief Russian language. */
#define FR_LANGUAGE_NAME_RUSSIAN              26
/** @brief Slovenian language. */
#define FR_LANGUAGE_NAME_SLOVENIAN            27
/** @brief Spanish language. */
#define FR_LANGUAGE_NAME_SPANISH              28
/** @brief Swedish language. */
#define FR_LANGUAGE_NAME_SWEDISH              29
/** @brief Turkish language. */
#define FR_LANGUAGE_NAME_TURKISH              30
/** @brief Hebrew language. */
#define FR_LANGUAGE_NAME_HEBREW               31
/** @brief Japanese language. */
#define FR_LANGUAGE_NAME_JAPANESE             32
/** @brief Thai language. */
#define FR_LANGUAGE_NAME_THAI                 33
/** @brief Valencian language. */
#define FR_LANGUAGE_NAME_VALENCIAN            34

/*@}*/
/* @DEFGROUPEND */

/* @STRUCTSTART FR_ShowTaskPanelInfo*/
typedef struct __FR_ShowTaskPanelInfo__
{
	__FR_ShowTaskPanelInfo__()
	{
		mPanelName = NULL;
		bShow = TRUE;		
		bAlwaysActivationFormat = false;
		bHideSlider = false;
	}

	/** The size of data structure. */
	unsigned long lStructSize;	

	/** The name of the taskpanel that needs to be displayed. */
	FS_LPSTR                mPanelName;
	/** Whether need show the panel. */
	FS_BOOL                 bShow;
	/** Whether need always active the panel.*/
	FS_BOOLEAN              bAlwaysActivationFormat;
	/** If true, the arrow will hidden when the right panel has only one tab, and it is the csName specified.*/
	FS_BOOLEAN              bHideSlider;
}FR_ShowTaskPanelInfo;


/* @OBJEND */


/* @OBJSTART FR_UIProgress */
#ifndef FR_UIPROGRESS
#define FR_UIPROGRESS
/**
 * @brief The <a>FR_UIProgress</a> object is referred to a progress bar. See <a>FRUIProgressCreate</a>.
 */
typedef struct _t_FR_UIProgress* FR_UIProgress;
#endif

/* @STRUCTSTART 
/**
 * @brief The <a>FR_UIProgress</a> object is referred to a progress bar. See <a>FRUIProgressCreate</a>.
 */
 typedef struct __FR_UIProgressOption__
{
	__FR_UIProgressOption__()
	{
		bShowCancelButton = TRUE;
		bRevertFocus = TRUE;
		bAutoHide = TRUE;
		bCenter = FALSE;
		Alpha = 100;
	}

	FS_BOOL bShowCancelButton;
	FS_BOOL bRevertFocus;
	FS_BOOL bAutoHide;
	FS_BOOL bCenter;
	FS_INT32 Alpha;
}FR_UIProgressOption;
/* @STRUCTEND */

/* @OBJEND */

/* FR_HTMLMgr */

#ifndef FR_HTMLMGR
#define FR_HTMLMGR
/**
 * @brief The <a>FR_HTMLMgr</a> object is used to manage the HTML windows in <Italic>Foxit Reader</Italic>. See <a>FRHTMLMgrGet</a>.
 * @deprecated Internal use
 */
typedef struct _t_FR_HTMLMgr* FR_HTMLMgr;
#endif

/* @CALLBACKGROUPSTART FR_HTMLEventCallbacks */
/**
* @brief A callback set for HTML window event handler. These callbacks will be invoked when the HTML window is created,
* destroyed and so on. See <a>FRHTMLMgrRegisterHTMLEventHandler</a>.
* @deprecated Internal use
*/
typedef struct _fr_htmlevent_callbacks_
{
    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_HTMLEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	/* @CALLBACKSTART FRHTMLEventRelease */
	/**
	 * @brief A callback for HTML window event handler.
	 *
	 * It is called when the event handler is released.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
     */
	void (*FRHTMLEventRelease)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRHTMLEventOnDocFrameCreate */
	/**
	 * @brief A callback for HTML window event handler.
	 *
	 * It is called when the HTML doc frame is created.
	 *
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] hFrameWnd			The HTML child frame window created.
	 * @param[in] hView				The HTML view created.
	 * @param[in] bNeedCreatePanel	Whether needs to create the navigation panel.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
     */
    void (*FRHTMLEventOnDocFrameCreate)(FS_LPVOID clientData, FS_HWND hFrameWnd, FS_HWND hView, FS_BOOL bNeedCreatePanel);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRHTMLEventOnDocViewBeforeNavigate2 */
	/**
	 * @brief A callback for HTML window event handler.
	 *
	 * It is called by the framework to cause an event to fire before a navigation occurs in the web browser.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] hView			The HTML view.
	 * @param[in] lpURL			Pointer to a string containing the URL to navigate to.
	 * @return TRUE if the plug-in processes the event and the framework will not dispatch the event.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
     */
    FS_BOOL (*FRHTMLEventOnDocViewBeforeNavigate2)(FS_LPVOID clientData, FS_HWND hView, FS_LPCWSTR lpURL);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRHTMLEventOnDocViewBeforeDestory */
	/**
	 * @brief A callback for HTML window event handler.
	 *
	 * It is called when the HTML doc view is to be destroyed.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] hView			The HTML view.
	 * @param[in] lpURL			Pointer to a string containing the URL to navigate to.
	 * @return void.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
     */
    void (*FRHTMLEventOnDocViewBeforeDestory)(FS_LPVOID clientData, FS_HWND hView, FS_LPCWSTR lpURL);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRHTMLEventOnDocViewNewWindow3 */
	/**
	 * @brief A callback for HTML window event handler.
	 *
	 * It is called when a new window is to be created. Go to https://msdn.microsoft.com/en-us/library/aa768288(VS.85).aspx for more information.
	 *
	 * @param[in] clientData		The user-supplied data.
	 * @param[in,out] ppDisp		An interface pointer that, optionally, receives the IDispatch interface pointer of a new WebBrowser object or an InternetExplorer object.
	 * @param[in,out] Cancel		It determines whether the current navigation should be canceled.
	 * @param[in] dwFlags			The flags from the NWMF enumeration that pertain to the new window.
	 * @param[in] bstrUrlContext	The URL of the page that is opening the new window.
	 * @param[in] bstrUrl			The URL that is opened in the new window.
	 * @return TRUE if the plug-in processes the event and the framework will not dispatch the event.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
     */
	FS_BOOL (*FRHTMLEventOnDocViewNewWindow3)(FS_LPVOID clientData, void **ppDisp, FS_BOOL *Cancel, FS_DWORD dwFlags, FS_LPCWSTR bstrUrlContext, FS_LPCWSTR bstrUrl);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRHTMLEventOnWillFrameClose */
	/**
	 * @brief A callback for HTML window event handler.
	 *
	 * It is called when the frame is closed.
	 *
	 * @param[in] clientData		The user-supplied data.
	 * @return TRUE if the frame can be closed, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.2
     */
	FS_BOOL (*FRHTMLEventOnWillFrameClose)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRHTMLEventOnDispatchFun */
	/**
	 * @brief A callback for HTML window event handler.
	 *
	 * It is called when the web browser invokes the JS function to communicate with the plug-in.
	 *
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] hView				The HTML view.
	 * @param[in] lpwsModule		The module name which the JS function is dispatched to.
	 * @param[in] lpwsFunName		The function name which is invoked by the web browser.
	 * @param[in] lpwsParam			The param of the JS function.
	 * @param[out] outRet			It receives the result returned to the web browser.
	 * @return TRUE for success, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
     */
    FS_BOOL (*FRHTMLEventOnDispatchFun)(FS_LPVOID clientData, FS_HWND hView, FS_LPCWSTR lpwsModule, FS_LPCWSTR lpwsFunName, FS_LPCWSTR lpwsParam, FS_WideString outRet);
	/* @CALLBACKEND */

}FR_HTMLEventCallbacksRec, *FR_HTMLEventCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_FoxitBrowserEventCallbacks */

/**
* @brief A callback set for Foxit browser event handler. These callbacks will be invoked when some events of the Foxit browser occurs.
* See <a>FRHTMLMgrRegisterFoxitBrowserEventHandler</a>.
* @deprecated Internal use
*/
typedef struct _fr_foxitbrowserevent_callbacks_
{
    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_FoxitBrowserEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	/* @CALLBACKSTART FRFoxitBrowserEventRelease */
	/**
	 * @brief A callback for Foxit browser event handler.
	 *
	 * It is called when the event handler is released.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.2
     */
	void (*FRFoxitBrowserEventRelease)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRFoxitBrowserEventOnDelFavLinks */
	/**
	 * @brief A callback for Foxit browser event handler.
	 *
	 * It is called when a favorite link is deleted.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] lpwsUrl		The favorite link that is deleted.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.2
     */
	void (*FRFoxitBrowserEventOnDelFavLinks)(FS_LPVOID clientData, FS_LPCWSTR lpwsUrl);
	/* @CALLBACKEND */

}FR_FoxitBrowserEventCallbacksRec, *FR_FoxitBrowserEventCallbacks;

/* @CALLBACKGROUPEND */


/*  FR_CloudLoginProvider */
#ifndef FR_CLOUDLOGINPROVIDER
#define FR_CLOUDLOGINPROVIDER
/**
 * @brief The <a>FR_CloudLoginProvider</a> object represents the service provider of cloud login. It provides the service to sign in, sign 
 * out, get the user info and so on. See <a>FRCloudLoginProviderGet</a>.
 * @deprecated Internal use.
 */
typedef struct _t_FR_CloudLoginProvider* FR_CloudLoginProvider;
#endif

/* @STRUCTSTART FR_Login_UserInfo*/
#ifndef FR_LOGINUSERINFO
#define FR_LOGINUSERINFO
/**
* @brief A data structure representing the user information of cloud login. 
* @deprecated Internal use.
*/
typedef struct __FR_Login_UserInfo__
{
	/** The user ID. Invokes <a>FSWideStringNew</a> to initialize. */
	FS_WideString wsUserID;
	/** The user email. Invokes <a>FSWideStringNew</a> to initialize. */
	FS_WideString wsEmail;
	/** The user token. Invokes <a>FSWideStringNew</a> to initialize. */
	FS_WideString wsToken;
	/** The user first name. Invokes <a>FSWideStringNew</a> to initialize. */
	FS_WideString wsFirstName;
	/** The user last name. Invokes <a>FSWideStringNew</a> to initialize. */
	FS_WideString wsLastName;

	__FR_Login_UserInfo__()
	{
		wsUserID = NULL;
		wsEmail = NULL;
		wsToken = NULL;
		wsFirstName = NULL;
		wsLastName = NULL;
	}
}FR_Login_UserInfo;
#endif
/* @STRUCTEND */

/* @CALLBACKGROUPSTART FR_CloudLoginProviderCallbacks */

/**
 * @brief A callback set for the service provider of cloud login. See <a>FRCloudLoginProviderSet</a>.
 * @deprecated Internal use.
 */
typedef struct _fr_cloudloginprovider_callbacks_
{

    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_CloudLoginProviderCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRCloudLoginProviderOnIsLogIn */
    /**
     * @brief A callback for the service provider of cloud login.
     *
     * It is called to check whether the user has logged in or not.
     *
     * @param[in] fwsHost				The Host url.
     * @param[in] clientData			The user-supplied data.
     * @return TRUE indicates that the user has logged in, otherwise not.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
     */
    FS_BOOL (*FRCloudLoginProviderOnIsLogIn)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCloudLoginProviderOnSignIn */
    /**
     * @brief A callback for the service provider of cloud login.
     *
     * It is called to sign into the cloud.
     *
     * @param[in] fwsHost				The Host url.
     * @param[in] clientData			The user-supplied data.
     * @return TRUE for success, otherwise failure.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
     */
    FS_BOOL (*FRCloudLoginProviderOnSignIn)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCloudLoginProviderOnSignOut */
    /**
     * @brief A callback for the service provider of cloud login.
     *
     * It is called to sign out the cloud.
     *
     * @param[in] fwsDomain				The Domain url.
     * @param[in] clientData			The user-supplied data.
     * @return TRUE for success, otherwise failure.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
     */
    FS_BOOL (*FRCloudLoginProviderOnSignOut)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRCloudLoginProviderOnGetUserInfo */
    /**
     * @brief A callback for the service provider of cloud login.
     *
     * It is called to get the user information.
     *
     * @param[in] fwsDomain				The Domain url.
     * @param[in] clientData	The user-supplied data.
     * @param[out] pUserInfo	It receives the user information.
     * @return TRUE for success, otherwise failure.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 7.3.1
     */
    FS_BOOL (*FRCloudLoginProviderOnGetUserInfo)(FS_LPVOID clientData, FR_Login_UserInfo* pUserInfo);
    /* @CALLBACKEND */

    FS_BOOL (*FRCloudLoginProviderGetWebServiceURL)(FS_LPVOID clientData,FS_ByteString bsType,FS_WideString wsOutUrl);

    FS_BOOL (*FRCloudLoginProviderUploadImage)(FS_LPVOID clientData, FS_ByteString bsUserToken, FS_ByteString bsType,FS_ByteString bsContent,FS_WideString wsOutUrl);

}FR_CloudLoginProviderCallbacksRec, *FR_CloudLoginProviderCallbacks;
/* @CALLBACKGROUPEND */
/* FR_CloudLoginProvider */


/*  FR_ActionWizardData */
#ifndef FR_ACTIONWIZARDDATA
#define FR_ACTIONWIZARDDATA
/**
 * @brief
 * @deprecated Internal use
 */
typedef struct _t_FR_ActionWizardData* FR_ActionWizardData;
#endif
/* FR_ActionWizardData */


/*  FR_AssistantMgr */
#ifndef FR_ASSISTANTMGR
#define FR_ASSISTANTMGR
/**
* @brief The <a>FR_AssistantMgr</a> object is used to manage the Assistant windows in <Italic>Foxit Reader</Italic>. See <a>FRAssistantMgrGet</a>.
* @deprecated Internal use.
*/
typedef struct _t_FR_AssistantMgr* FR_AssistantMgr;
#endif

/* @ENUMSTART */
/** @brief The name definition of AsstBall image type.*/
/** @deprecated Internal use*/
enum FRAsstEmojiType
{
	FR_EMOJI_NORMALE,			/**normal. */
	FR_EMOJI_FIXED,				/**fixed. */
	FR_EMOJI_MESSAGE,			/**message. */
	FR_EMOJI_SLEEP,				/**sleep. */
	FR_EMOJI_ERROR,				/**error. */
	FR_EMOJI_ALERT,				/**alert. */
	FR_EMOJI_GREAT				/**great. */
};
/* @ENUMEND */

/* @CALLBACKGROUPEND */

/* @CALLBACKSTART FRAsstNotifyHyperlinkProcc */
/* * @deprecated Internal use*/
/**
* @brief A callback that is called when click notification hyperlink.
* @deprecated Internal use.
* @param[in] hParent	A handle of the parent window.
* @param[in] wsLink		The input notification message link.
* @return true if you want to hide notificaiton wnd
* @note
*/
typedef bool(*FRAsstNotifyHyperlinkProc)(FS_HWND hParent, FS_LPCWSTR wsLink);
/* @CALLBACKEND */

/* @STRUCTSTART FR_ASST_NOTIFY*/
/**
* @brief A data structure representing the data of the assistant notification.
* @deprecated Internal use.
*/
typedef struct __fr_asst_notify__
{
    /**  @brief ID of a certain type of notification message, interval range[0, UINT_MAX).*/
    FS_UINT nNotifyID = 0;

	/** @brief Message text; support html format.*/
	FS_LPCWSTR wsMsg;

	/** @brief The display duration of the message notification, in milliseconds (ms)..*/
	FS_INT32 nMilliseconds = 5000;

	/** @brief AsstBall emoji icon.*/
	FRAsstEmojiType emojiType = FR_EMOJI_MESSAGE; //

	/**
	 **  @brief if wsMsg contains a hyperlink and the "msg" attribute exists, the callback for the hyperlink.
	 *	e.g. "<<a msg="LiveChat">%d message(s)</a> from live chat!>"
	*/
	FRAsstNotifyHyperlinkProc proc = NULL;
}FR_ASST_NOTIFY, *PFR_ASST_NOTIFY;
/* @STRUCTEND */


/* @CALLBACKGROUPSTART FR_AsstUICallbacks */

/**
* @brief A callback set for Assistant ui event handler. These callbacks will be invoked when some events of the ui occurs.
* See <a>FRAssistantMgrRegisterAsstUIHandler</a>.
* @deprecated Internal use.
*/
typedef struct _fr_asstui_callbacks_
{

	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_AsstUICallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/** The sdk-supplied data. user can not use the data*/
	FS_LPVOID		sdkData;

	/* @CALLBACKSTART FRAsstUIOnLoad */
	/**
	* @brief	 A callback for foxit assistant ui. It is called by Foxit Reader to show assistant ui.
	* @param[in] clientData	The user-supplied data.
	* @return	 void.
	* @note
	*/
	void(*FRAsstUIOnLoad)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAsstUIOnAsstBallClick */
	/**
	* @brief	 A callback for AsstBall. It is called by Foxit Reader to Click the AsstBall.
	* @param[in] clientData	The user-supplied data.
	* @param[in] hWnd	A handle of the AIBall window.
	* @return	 void.
	* @note
	*/
    void(*FRAsstUIOnAsstBallClick)(FS_LPVOID clientData, FS_HWND hWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAsstUIOnAsstStatusBtnClick */
	/**
	* @brief	 A callback for Assistant status btn. It is called by Foxit Reader to Click the asst status btn.
	* @param[in] clientData	The user-supplied data.
	* @return	 void.
	* @note
	*/
	void(*FRAsstUIOnAsstStatusBtnClick)(FS_LPVOID clientData);
	/* @CALLBACKEND */

}FR_AsstUICallbacksRec, *FR_AsstUICallbacks;

/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_AIAssistantCallbacks */

/**
* @brief A callback set for Assistant event handler. These callbacks will be invoked when some events of the Assistant occurs.
* See <a>FRAssistantMgrRegisterAssistantHandler</a>.
* @deprecated Internal use.
*/
typedef struct _fr_assistant_callbacks_
{

	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FRAssistantMgrRegisterAssistantHandler</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	/* @CALLBACKSTART FRAssistantGetName */
	/**
	* @brief	A callback for ai assistant wnd. It is called by Foxit Reader to get the ai assistant name.
	* @param[in] clientData	The user-supplied data.
	* @return	A null-determined string correspond the name of ai assistant wnd.
	* @note
	*/
	FS_LPSTR(*FRAssistantGetName)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAssistantGetTitle */
	/**
	* @brief A callback for assistant wnd.
	* It is called by Foxit Reader to get the assistant wnd's title which is shown in user interface.
	* @param[in] clientData	The user-supplied data.
	* @return A null-determined string correspond the title of assistant wnd.
	* @note
	*/
	FS_LPWSTR(*FRAssistantGetTitle)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAssistantGetToolTip */
	/**
	* @brief A callback for assistant wnd.
	* It is called by Foxit Reader to get the assistant wnd's tooltip which is shown in user interface.
	* @param[in] clientData	The user-supplied data.
	* @return A null-determined string correspond the title of ai assistant wnd.
	* @note
	*/
	FS_LPWSTR(*FRAssistantGetToolTip)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAssistantGetIcon */
	/**
	* @brief A callback for assistant wnd to get the icon of assistant button.
	* The bitmap returned by this method will be taken by Reader, client can not release it
	* until user exit Reader.
	* @param[in] clientData	The user-supplied data.
	* @return A <a>FS_DIBitmap</a>. The size of bitmap is 16 * 16.
	* @note
	*/
	FS_DIBitmap(*FRAssistantGetIcon)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAssistantGetKey */
	/**
	* @brief A callback for assistant wnd.
	* It is called by Foxit Reader to get the assistant wnd's key which is shown in user interface.
	* @param[in] clientData	The user-supplied data.
	* @return A null-determined string correspond the title of ai assistant wnd.
	* @note
	*/
	FS_LPWSTR(*FRAssistantGetKey)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAssistantExecuteProc */
	/**
	* @brief A callback for assistant wnd.
	* It is called by Foxit Reader to click ai assistant button.
	* @param[in] clientData	The user-supplied data.
	* @param[in] hParent	A handle of the parent window.
	* @return void.
	* @note
	*/
    void(*FRAssistantExecuteProc)(FS_LPVOID clientData, FS_HWND hParent);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAssistantGetPDFImage */
	/**
	* @brief A callback for assistant wnd.
	* It is called by Foxit Reader to get the assistant pdf image name.
	* @param[in] clientData	The user-supplied data.
	* @return Get the pdf image name.
	* @note
	*/
	FS_LPWSTR(*FRAssistantGetPDFImage)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAssistantGetPosition */
	/**
	* @brief A callback for assistant wnd.
	* It is called by Foxit Reader to get the assistant pdf image name.
	* @param[in] clientData	The user-supplied data.
	* @return FS_DWORD.
	* @note
	*/
	FS_DWORD(*FRAssistantGetPosition)(FS_LPVOID clientData);
	/* @CALLBACKEND */
}FR_AssistantCallbacksRec, *FR_AssistantCallbacks;

/* FR_AssistantMgr */

/*  FR_Cursor */
#ifndef FR_CURSOR
#define FR_CURSOR
/**
 * @brief A data structure representing the cursor. You can get it from <a>BaseAnnotLoadCursor</a> or <a>FRSysLoadStandarCursor</a>
 * @deprecated Internal use
 */
typedef struct _t_FR_Cursor* FR_Cursor;
#endif
/* FR_Cursor */

/*  FR_MarkupAnnotHandler */
#ifndef FR_MARKUPANNOTHANDLER
#define FR_MARKUPANNOTHANDLER
/**
 * @brief A data structure representing the cursor.
 * @deprecated Internal use
 */
typedef struct _t_FR_MarkupAnnotHandler* FR_MarkupAnnotHandler;
#endif
/*  */
/* FR_MarkupAnnotHandler */

/*  FR_PanelMgr */
#ifndef FR_PANELMGR
#define FR_PANELMGR
/**
 * @brief The <a>FR_PanelMgr</a> object is used to manage the navigation panels. You can get an existing panel manager through <a>FRPanelMgrGetPanelMgrFromChildFrm</a>.
 * And can also create a new one through <a>FRPanelMgrNewPanelMgr</a>.
 * @deprecated Internal use.
 */
typedef struct _t_FR_PanelMgr* FR_PanelMgr;
#endif

/* @DEFGROUPSTART  FRPanelLocation*/
/**
* @brief the location of panel
* @deprecated Internal use.
*/

/*@{*/
/** @brief The panel location is top.*/
#define  FR_PANEL_LOCATION_TOP		 1
/** @brief The panel location is left.*/
#define  FR_PANEL_LOCATION_LEFT		 2
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKGROUPSTART FR_PanelEventCallbacks */

/**
* @brief A callback set for the panel event handler. These callbacks will be invoked when an event occurs like the panel size changing.
* @deprecated Internal use.
*/
typedef struct _fr_panelevent_callbacks_
{
    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_PanelEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRPanelEventOnShowPanelMenu */
	/**
	 * @brief A callback for navigation panel event handler.
	 *
	 * It is called when a context menu is shown on the navigation panel.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] hParent		The parent window of the navigation panel.
	 * @param[in] posX			The horizon position of the context menu.
	 * @param[in] posY			The vertical position of the context menu.
	 * @return TRUE for success, otherwise failure.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
     */
    FS_BOOL (*FRPanelEventOnShowPanelMenu)(FS_LPVOID clientData, FS_HWND hParent, FS_INT32 posX, FS_INT32 posY);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelEventOnPanelActive */
	/**
	 * @brief A callback for navigation panel event handler.
	 *
	 * It is called when a navigation panel is activated.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] lpsName		The name of the navigation panel.
	 * @return void.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
     */
	void (*FRPanelEventOnPanelActive)(FS_LPVOID clientData, FS_LPCSTR lpsName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelEventOnPanelSize */
	/**
	 * @brief A callback for navigation panel event handler.
	 *
	 * It is called when the size of the navigation panel is changing.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] lpsName		The name of the navigation panel.
	 * @param[in] rect			The size of the navigation panel.
	 * @param[in] hChildFrm		The child frame the navigation panel attached to.
	 * @return void.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
     */
    void (*FRPanelEventOnPanelSize)(FS_LPVOID clientData, FS_LPCSTR lpsName, FS_Rect rect, FS_HWND hChildFrm);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRPanelEventOnMouseMove */
	/**
	 * @brief A callback for navigation panel event handler.
	 *
	 * It is called when the mouse is moving on the navigation panel.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] x				The horizon position of the mouse.
	 * @param[in] y				The vertical position of the mouse.
	 * @return void.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 7.1
     */
	void (*FRPanelEventOnMouseMove)(FS_LPVOID clientData, FS_INT32 x, FS_INT32 y);
	/* @CALLBACKEND */

}FR_PanelEventCallbacksRec, *FR_PanelEventCallbacks;

/* @CALLBACKGROUPEND */
/* FR_PanelMgr END */


/*  FR_ReaderUserMessageHandler */
#ifndef FR_READERUSERMESSAGEHANDLER
#define FR_READERUSERMESSAGEHANDLER
/**
* @brief A data structure representing the cursor.
* @deprecated Internal use
*/
typedef struct _t_FR_ReaderUserMessageHandler* FR_ReaderUserMessageHandler;
#endif

/* @CALLBACKGROUPSTART FR_ReaderUserMessageHandlerCallbacks */
/**
* @brief  <a>FRAppRegisterUserMessageHanler</a>.
* @deprecated Internal use
*
*/
typedef struct _fr_ReaderUserMessageHandler_callbacks_
{
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOL(*FROnUserMessageData)(FS_LPVOID clientData, FS_LPVOID pData);
}FR_ReaderUserMessageHandlerCallbacksRec, *FR_ReaderUserMessageHandlerCallbacks;
/* @CALLBACKGROUPEND*/
/* FR_ReaderUserMessageHandler END*/

/*  FR_ReaderTheme */
#ifndef FR_READERTHEME
#define FR_READERTHEME
/**
* @brief <a>FRReaderUIMgrGetReaderThemeObject</a>
* @deprecated Internal use
*/
typedef struct _t_FR_ReaderTheme* FR_ReaderTheme;
#endif

/* @ENUMSTART */
/**
 * @brief The skin style.
 */
enum FR_SKINSTYLE
{
	FRDefault = 0,
	FRLight,
	FRDark
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief The corner type.
*/
enum FR_WINDOW_CORNER_TYPE
{
	FRDWMWCP_DEFAULT = 0,	// Let the system and visual manager decide whether or not to round window corners
	FRDWMWCP_DONOTROUND = 1,	// Never round window corners
	FRDWMWCP_ROUND = 2,		// Round the corners if appropriate
	FRDWMWCP_ROUNDSMALL = 3	// Round the corners if appropriate, with a small radius
};
/* @ENUMEND */

/* @CALLBACKSTART FRSkinChangeProc */
/**
 * @brief The callback when skin change.
 * @param[in] style	        The skin style.
 * @param[in] pClientData	The client data.
 * @return void
 * @note
 * @see 
 */
typedef void(*FRSkinChangeProc)(FR_SKINSTYLE style, FS_LPVOID pClientData);
/* @CALLBACKEND */

/* FR_ReaderTheme END */



/*  FR_IRepalceAllNotify */
#ifndef FR_IREPLACEALLNOTIFY
#define FR_IREPLACEALLNOTIFY
/**
* @brief
* @deprecated Internal use
*/
typedef struct _t_FR_IReplaceAllNotify* FR_IReplaceAllNotify;
#endif
/*  */


/*  FR_FindReplaceMgr */
#ifndef FR_ITOUCHUPMGR
#define FR_ITOUCHUPMGR
/**
* @brief
* @deprecated Internal use
*/
typedef struct _t_FR_FindReplaceMgr* FR_FindReplaceMgr;
#endif


typedef struct __FR_FIND_OPTION__
{
	FS_BOOLEAN				bWholeWD = false;// whole words only 
	FS_BOOLEAN				bCaseSen = false;// case sentive 
	FS_BOOLEAN				bForward = true;//forward/previous	
	FS_BOOLEAN				bSelRes = true;//Select the result found
}FR_FIND_OPTION;


typedef struct __FR_ReplaceAllNotifyData__
{
	FS_INT32 nPageReplaced;
	FS_INT32 nTextReplaced;
}FR_ReplaceAllNotifyData;


typedef struct __FR_ReplaceAllOption__
{
	FS_INT32 nStartPageIdx;
	FS_WideString wstrFindText;
	FS_WideString wstrReplaceText;
	FS_FileStream pFileStream;
	FR_IReplaceAllNotify pReplaceNotify;
	FR_FIND_OPTION findOpt;
}FR_ReplaceAllOption;



typedef struct _fr_IReplaceAllNotify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DocEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOLEAN(*FRReplaceAllProc)(FS_LPVOID clientData, FR_ReplaceAllNotifyData notifyData);
}FR_IReplaceAllNotifyCallbacksRec, *FR_IReplaceAllNotifyCallbacks;


typedef struct _fr_FindReplaceMgr_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DocEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	FS_BOOL(*FRStartReplace)(FS_LPVOID clientData);
	FS_BOOL(*FREndReplace)(FS_LPVOID clientData);
	FS_BOOL(*FRFindText)(FS_LPVOID clientData, FS_WideString wstrText, FS_INT32 nPageIdx, const FR_FIND_OPTION findOpt);
	FS_BOOL(*FRFTReplaceText)(FS_LPVOID clientData, FS_WideString wstrText);
	FS_BOOLEAN(*FRReplaceAll)(FS_LPVOID clientData, FR_Document pReaderDoc, FR_ReplaceAllOption opt);
	void(*FRClearCache)(FS_LPVOID clientData, FS_INT32 nPageIdx);
	FS_BOOLEAN(*FRIsProcessInterrupt)(FS_LPVOID clientData, FR_Document pReaderDoc);
	void(*FRSetHighlightColor)(FS_LPVOID clientData, FS_ARGB argbColore);
	FS_BOOL(*FRFindText2)(FS_LPVOID clientData, FS_WideString wstrText, FS_INT32 nPageIdx, const FR_FIND_OPTION findOpt, FS_PtrArray specifyObjects);
}FR_FindReplaceMgrCallbacksRec, *FR_FindReplaceMgrCallbacks;


typedef void(*FRDownloadFinishCallbackProc)(FS_LPVOID pClientData, FS_LPCSTR module_name);
/*  */

/* @CALLBACKGROUPSTART FR_EmailUtilSendMailCallbacksRec */
/**
 * @brief Callbacks used when sending email.
 * @deprecated Internal use
 */
typedef struct __FR_EmailUtilSendMailCallbacksRec__
{
	__FR_EmailUtilSendMailCallbacksRec__()
		:FREmailUtil_OnSendBegin(0)
		,FREmailUtil_OnSendFinished(0)
		,FREmailUtil_OnSendProgress(0)
		,FREmailUtil_OnSendAborted(0)
		,FREmailUtil_OnSendNotify(0)
	{

	}
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EmailUtilSendMailCallbacksRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/**
	 *	@brief Sending operation begins.
	 */
	void (*FREmailUtil_OnSendBegin)(FS_LPVOID clientData);

	/**
	 *	@brief		Sending operation finished.
	 *	@param[in]	clientData		The user-supplied data.
	 *	@param[in]	errorCode		The generic error code, 0 for succeess, 1 for user cancelled.
	 *				Other value should be treated as error.
	 *	@param[in]	specificErrorCode The sender specific error code.
	 *	@param[in]	localizedErrorMessage The localized error description message.
	 */
	void (*FREmailUtil_OnSendFinished)(FS_LPVOID clientData, FS_INT32 errorCode, FS_INT32 specificErrorCode, FS_LPCWSTR localizedErrorMessage);

	/**
	 *	@brief		Sending progress changed.
	 *	@param[in]	clientData	The user-supplied data.
	 *	@param[in]	progress	A number between 0.0f to 1.0f representing current progress.
	 */
	void (*FREmailUtil_OnSendProgress)(FS_LPVOID clientData, FS_FLOAT progress);

	/**
	 *	@brief		User cancelled the operation.
	 *	@param		clientData The user-supplied data.
	 */
	void (*FREmailUtil_OnSendAborted)(FS_LPVOID clientData);

	/**
	 *	@brief		Notify an event occured in the sending operation.
	 *	@param[in]	clientData	The user-supplied data.
	 *	@param[in]	event		Event name.
	 */
    void (*FREmailUtil_OnSendNotify) (FS_LPVOID clientData, FS_LPCWSTR event);


}FR_EmailUtilSendMailCallbacksRec, *FR_EmailUtilSendMailCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_EmailUtilPreSendMailCallbacksRec */
/**
 * @brief Callbacks used before sending email.
 * @deprecated Internal use
 *
 */
typedef struct __FR_EmailUtilPreSendMailCallbacksRec__
{
	__FR_EmailUtilPreSendMailCallbacksRec__()
		:FREmailUtil_OnPreSendMail(0)
	{

	}
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EmailUtilPreSendMailCallbacksRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	/**
	 *	@brief		Called before email sending.
	 *	@param[in]	clientData		The user-supplied data.
	 *	@param[in]	attachmentPaths		An array of contains attachment path.
	 *	@return		return false will cancel following email sending operation.
	 */
	FS_BOOL (*FREmailUtil_OnPreSendMail)(FS_LPVOID clientData, FS_WideStringArray attachmentPaths);

}FR_EmailUtilPreSendMailCallbacksRec, *FR_EmailUtilPreSendMailCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_EmailUtilAttachmentNameModifierRec */
/**
 * @brief Callbacks used before sending email.
 * @deprecated Internal use
 */
typedef struct __FR_EmailUtilAttachmentNameModifierRec__
{
	__FR_EmailUtilAttachmentNameModifierRec__()
		:FREmailUtil_OnModifyAttachmentName(0)
	{

	}
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EmailUtilAttachmentNameModifierRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/**
	 *	@brief		Called before email sending.
	 *	@param[in]	clientData		The user-supplied data.
	 *	@param[in]	attachmentPaths		An array of contains attachment path.
	 *	@param[in]	attachmentNames		An array of contains attachment Name.
	 */
	void (*FREmailUtil_OnModifyAttachmentName)(FS_LPVOID clientData, FS_WideStringArray attachmentPaths, FS_WideStringArray attachmentNames);

}FR_EmailUtilAttachmentNameModifierRec, *FR_EmailUtilAttachmentNameModifier;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_CommentsAnnotOprtNotifyCallbacksRec */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct __FR_CommentsAnnotOprtNotifyCallbacksRec__
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_CommentsAnnotOprtNotifyCallbacksRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void (*OnDeletedAnnot)(FS_LPVOID clientData, FR_Document frDoc, FR_Annot frAnnot);

	void (*OnSetAnnotChagne)(FS_LPVOID clientData, FR_Document frDoc, FR_Annot frAnnot);

	void(*OnSetAnnotChagne2)(FS_LPVOID clientData, FR_Document frDoc, FR_Annot frAnnot, FS_BOOLEAN bAdd);
}FR_CommentsAnnotOprtNotifyCallbacksRec, *FR_CommentsAnnotOprtNotifyCallbacks;
/* @CALLBACKGROUPEND */

#ifndef FR_EDIT_FONTMAP
#define FR_EDIT_FONTMAP

typedef struct _t_FR_Edit_FontMap* FR_Edit_FontMap;
#endif

#ifndef FRFMTRIBOOL
#define FRFMTRIBOOL
enum FRFMTribool
{
	FR_FMFalse = 0,		
	FR_FMTrue,			
	FR_FMIndeterminate	
};
#endif

#ifndef FR_EDIT_ITERATOR
#define FR_EDIT_ITERATOR

typedef struct _t_FR_Edit_Iterator* FR_Edit_Iterator;
#endif


#ifndef FR_VARIABLETEXT
#define FR_VARIABLETEXT

typedef struct _t_FR_VariableText* FR_VariableText;
#endif


#ifndef FR_VTWORDPLACE
#define FR_VTWORDPLACE

typedef struct _t_FR_VTWordPlace* FR_VTWordPlace;
#endif

#ifndef FR_VTWORDRANGE
#define FR_VTWORDRANGE

typedef struct _t_FR_VTWordRange* FR_VTWordRange;
#endif
	
#ifndef FR_VTSECPROPS
#define FR_VTSECPROPS

typedef struct _t_FR_VTSecProps* FR_VTSecProps;
#endif

#ifndef FR_VTWORDPROPS
#define FR_VTWORDPROPS

typedef struct _t_FR_VTWordProps* FR_VTWordProps;
#endif

#ifndef FR_VTWORD
#define FR_VTWORD

typedef struct _t_FR_VTWord* FR_VTWord;
#endif

#ifndef FR_VTLINE
#define FR_VTLINE

typedef struct _t_FR_VTLine* FR_VTLine;
#endif

#ifndef FR_VTSECTION
#define FR_VTSECTION

typedef struct _t_FR_VTSection* FR_VTSection;
#endif

#ifndef FR_VARIABLETEXT_ITERATOR
#define FR_VARIABLETEXT_ITERATOR

typedef struct _t_FR_VariableText_Iterator* FR_VariableText_Iterator;
#endif

#ifndef FR_VARIABLETEXT_PROVIDER
#define FR_VARIABLETEXT_PROVIDER
typedef struct _t_FR_VariableText_Provider* FR_VariableText_Provider;
#endif

#ifndef FR_EDIT_UNDOITEM
#define FR_EDIT_UNDOITEM

typedef struct _t_FR_Edit_UndoItem* FR_Edit_UndoItem;
#endif

#ifndef FR_EDIT
#define FR_EDIT
typedef struct _t_FR_Edit* FR_Edit;
#endif

/* @DEFGROUPSTART  SpecificChars*/
/**
* @brief
* @deprecated Internal use
*/
/*@{*/
/** @brief */
#define FR_VT_SOFTRETURN			0xFFFE 
/** @brief */
#define FR_VT_SECTION_FLG			0x0D 
/** @brief */
#define FR_VT_TEXT_HIDCHAR			0xFFF8 
/** @brief */
#define FR_VT_TEXT_UNICODEINVALID	0xFFFF 
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART  EmbedCharSet*/
/**
* @brief
* @deprecated Internal use
*/
/*@{*/
/** @brief */
#define FR_EMBED_CHARSET			0x7FFFFFFF
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART  VTWordStyle*/
/**
* @brief
* @deprecated Internal use
*/

/*@{*/
/** @brief */
#define  FR_VT_WORD_STYLE_BOLD		0x40000
#define  FR_VT_WORD_STYLE_ITALIC	0x40
#define  FR_VT_WORD_STYLE_NORMAL     0x0000L
#define  FR_VT_WORD_STYLE_HIGHLIGHT  0x0001L
#define  FR_VT_WORD_STYLE_UNDERLINE  0x0002L
#define  FR_VT_WORD_STYLE_CROSSOUT   0x0004L
#define  FR_VT_WORD_STYLE_SQUIGGLY   0x0008L
#define  FR_VT_WORD_STYLE_DUALCROSSOUT 0x0010L
#define  FR_VT_WORD_STYLE_FORMXOBJECT 0x0020L
#define  FR_VT_WORD_STYLE_LINE_END_TYPESET_SPACE 0x0080L
/*@}*/
/* @DEFGROUPEND */

/*  FR_EDIT_FontData*/
#ifndef FR_EDIT_FONTDATA
#define FR_EDIT_FONTDATA
/**
* @brief 
* @deprecated Internal use
*
*/
typedef struct __FR_EDIT_FontData__
{
	/** */
	FPD_Font fpdFont;

	/** */
	FS_ByteString fontAName;

}FR_EDIT_FontData;
#endif
/*  */

/* @CALLBACKGROUPSTART FR_VariableTextProviderCallbacks */
/**
 * @brief Variable text provider
 * @deprecated Internal use
 *
 */
typedef struct _fr_variabletextprovider_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_VariableTextProviderCallbacksRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_INT32 (*FRVariableTextProviderGetCharWidth)(FS_LPVOID clientData, FS_INT32 nFontIndex, FS_WORD word, FS_INT32 nWordStyle);
	
	FS_INT32 (*FRVariableTextProviderGetCharItalicWidth)(FS_LPVOID clientData, FS_INT32 nFontIndex, FS_WORD word);
	
	FS_INT32 (*FRVariableTextProviderGetTypeAscent)(FS_LPVOID clientData, FS_INT32 nFontIndex);
	
	FS_INT32 (*FRVariableTextProviderGetTypeDescent)(FS_LPVOID clientData, FS_INT32 nFontIndex);
	
	FS_INT32 (*FRVariableTextProviderGetWordFontIndex)(FS_LPVOID clientData, FS_WORD word, FS_INT32 nFontIndex, FS_DWORD fontstyle,FS_DWORD nCharSet, FS_BOOL IsVertical);

	FS_BOOL (*FRVariableTextProviderIsLatinWord)(FS_LPVOID clientData, FS_WORD word);

	FS_INT32 (*FRVariableTextProviderGetDefaultFontIndex)(FS_LPVOID clientData);

    void (*FRVariableTextProviderSetDefaultFontIndex)(FS_LPVOID clientData, FS_INT32 nDefaultIndex);

	FS_BOOL (*FRVariableTextProviderIsVerticalFont)(FS_LPVOID clientData, FS_INT32 nFontindex);

	FR_Edit_FontMap (*FRVariableTextProviderGetFontMap)(FS_LPVOID clientData);

}FR_VariableTextProviderCallbacksRec, *FR_VariableTextProviderCallbacks;
/* @CALLBACKGROUPEND */

#ifndef FR_EDITNOTIFY_CALLBACK
#define FR_EDITNOTIFY_CALLBACK
/* @CALLBACKGROUPSTART FR_EditNotifyCallbacks */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct _fr_editnotify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EditNotifyCallbacksRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void (*FREditNotifyOnSetScrollInfoX)(FS_LPVOID clientData, FS_FLOAT fPlateMin, FS_FLOAT fPlateMax, FS_FLOAT fContentMin, FS_FLOAT fContentMax, 
											FS_FLOAT fSmallStep, FS_FLOAT fBigStep);

	void (*FREditNotifyOnSetScrollInfoY)(FS_LPVOID clientData, FS_FLOAT fPlateMin, FS_FLOAT fPlateMax, FS_FLOAT fContentMin, FS_FLOAT fContentMax, 
											FS_FLOAT fSmallStep, FS_FLOAT fBigStep);

	void (*FREditNotifyOnSetScrollPosX)(FS_LPVOID clientData, FS_FLOAT fx);
	
	void (*FREditNotifyOnSetScrollPosY)(FS_LPVOID clientData, FS_FLOAT fy);
	
	void (*FREditNotifyOnSetCaret)(FS_LPVOID clientData, FS_BOOL bVisible, FS_FLOAT headX, FS_FLOAT headY, 
									FS_FLOAT footX, FS_FLOAT footY, FR_VTWordPlace wordPlace);
	
	void (*FREditNotifyOnCaretChange)(FS_LPVOID clientData, FR_VTSecProps secProps, FR_VTWordProps wordProps);
	
	void (*FREditNotifyOnContentChange)(FS_LPVOID clientData, FS_FloatRect rcContent);
	
	void (*FREditNotifyOnInvalidateRect)(FS_LPVOID clientData, FS_FloatRect rect);

}FR_EditNotifyCallbacksRec, *FR_EditNotifyCallbacks;
/* @CALLBACKGROUPEND */
#endif

#ifndef FR_EDITORPONOTIFY_CALLBACK
#define FR_EDITORPONOTIFY_CALLBACK
/* @CALLBACKGROUPSTART FR_EditOprNotifyCallbacks */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct _fr_editoprnotify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EditOprNotifyCallbacksRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void (*FREditOprNotifyOnInsertWord)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);
	
	void (*FREditOprNotifyOnInsertReturn)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);
	
	void (*FREditOprNotifyOnBackSpace)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);
	
	void (*FREditOprNotifyOnDelete)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);
	
	void (*FREditOprNotifyOnClear)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);
	
	void (*FREditOprNotifyOnInsertText)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);
	
	void (*FREditOprNotifyOnSetText)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);
	
	void (*FREditOprNotifyOnAddUndo)(FS_LPVOID clientData, FR_Edit_UndoItem undoItem);

}FR_EditOprNotifyCallbacksRec, *FR_EditOprNotifyCallbacks;
/* @CALLBACKGROUPEND */
#endif

#ifndef FR_EDITUNDOITEM_CALLBACK
#define FR_EDITUNDOITEM_CALLBACK
/* @CALLBACKGROUPSTART FR_EditUndoItemCallbacks */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct _fr_editundoitem_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EditUndoItemCallbacksRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void (*FREditUndoItemUndo)(FS_LPVOID clientData);

	void (*FREditUndoItemRedo)(FS_LPVOID clientData);

	void (*FREditUndoItemGetUndoTitle)(FS_LPVOID clientData, FS_WideString outTitle);

	void (*FREditUndoItemRefersh)(FS_LPVOID clientData);

	FS_BOOL (*FREditUndoItemIsPaint)(FS_LPVOID clientData);

	void (*FREditUndoItemSetFirst)(FS_LPVOID clientData, FS_BOOL bFirst);

	FS_BOOL (*FREditUndoItemIsFirst)(FS_LPVOID clientData);

	void (*FREditUndoItemSetLast)(FS_LPVOID clientData, FS_BOOL bLast);

	FS_BOOL (*FREditUndoItemIsLast)(FS_LPVOID clientData);

	void (*FREditUndoItemRelease)(FS_LPVOID clientData);

}FR_EditUndoItemCallbacksRec, *FR_EditUndoItemCallbacks;
/* @CALLBACKGROUPEND */
#endif

#ifndef FR_EDITDRAWNOTIFY_CALLBACK
#define FR_EDITDRAWNOTIFY_CALLBACK
/* @CALLBACKGROUPSTART FR_EditDrawNotifyCallbacks */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct _fr_editdrawnotify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EditDrawNotifyCallbacksRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOL (*FREditDrawNotifyGetDrawData)(FS_LPVOID clientData, FPD_RenderContext *pContext, FPD_RenderOptions* pOptions, void* pKey);

}FR_EditDrawNotifyCallbacksRec, *FR_EditDrawNotifyCallbacks;
/* @CALLBACKGROUPEND */
#endif

#ifndef FR_TOUCHUP
#define FR_TOUCHUP

typedef struct _t_FR_Touchup* FR_Touchup;
#endif

/* @DEFGROUPSTART TextOperations */
/**
* @brief
* @deprecated Internal use
*/

/*@{*/
/** @brief */
#define FR_TEXT_OP_NONE				0

/** @brief */
#define FR_TEXT_OP_CREATE			0x1

/** @brief */
#define FR_TEXT_OP_DELETE			0x2

/** @brief */
#define FR_TEXT_OP_EDIT				0x4

/** @brief */
#define FR_TEXT_OP_POSTION_CHANGE	0x8

/** @brief */
#define FR_TEXT_OP_ROTATE			0x10

/** @brief */
#define FR_TEXT_OP_SHEAR			0x20

/** @brief */
#define FR_TEXT_OP_RESIZE			0x40

/** @brief */
#define FR_TEXT_OP_SPLIT			0x80

/** @brief */
#define FR_TEXT_OP_MERGE			0x100

/*@}*/
/* @DEFGROUPEND */

/* @STRUCTSTART FR_Text_Object_OP*/
#ifndef FS_TEXT_OBJECT_OP
#define FS_TEXT_OBJECT_OP
/**
* @brief 
* @deprecated Internal use
*/
typedef struct __FR_Text_Object_OP__
{
	/** */
	FPD_PageObject textObj;

	/** */
	FS_INT32 iOP;

	/** */
	FS_INT32 iIndexInPage;

	/** */
	void* pVoid;
	
	/**.*/
	FS_FloatRect rcBBox;

	/**.*/
	void* pPos;

	/** */
	short iParentOp;

}FR_Text_Object_OP;
#endif
/* @STRUCTEND */

/* @DEFGROUPSTART TextOperationUndoRedoType */
/**
* @brief
* @deprecated Internal use
*/

/*@{*/
/** @brief */
#define FR_TEXT_OP_ON_UNDO		0
/** @brief */
#define FR_TEXT_OP_ON_REDO		1
/** @brief */
#define FR_TEXT_OP_ON_RELEASE	2
/*@}*/
/* @DEFGROUPEND */

/* @STRUCTSTART FR_Text_Object_OP_Result*/
#ifndef FS_TEXT_OBJECT_OP_RESULT
#define FS_TEXT_OBJECT_OP_RESULT
/**
* @brief 
* @deprecated Internal use
*/
typedef struct __FR_Text_Object_OP_Result__
{
	/** */
	FS_INT32 iUUid;

	/** */
	FS_INT32 iStatus;

	/** */
	void* pUndoItem;

	/** */
	void (*OnRedoUndo)(void* pData, FS_INT32 iType);

}FR_Text_Object_OP_Result;
#endif
/* @STRUCTEND */

#ifndef FR_PROFSTORE
#define FR_PROFSTORE

typedef struct _t_FR_ProfStore* FR_ProfStore;
#endif


#ifndef FR_CMAPITEMNAMETODATA
#define FR_CMAPITEMNAMETODATA

typedef struct _t_FR_CMapItemNameToData* FR_CMapItemNameToData;
#endif

#ifndef FR_ACTIONWIZARDLOGGER
#define FR_ACTIONWIZARDLOGGER

typedef struct _t_FR_ActionWizardLogger* FR_ActionWizardLogger;
#endif

/* @ENUMSTART */
/** @brief .*/
/** @deprecated Internal use */
enum FRActionWizardLogType
{
	FR_ActionWizardLog_NoType,		/**. */
	FR_ActionWizardLog_Error,	    /**. */
	FR_ActionWizardLog_Warning,		/**. */
	FR_ActionWizardLog_Skip,		/**. */
	FR_ActionWizardLog_More			/**. */
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief .*/
/* @deprecated Internal use */
enum FRActionWizardExcuteStatus 
{
	FR_EXCUTE_STATUS_DONTSUPPORT = 0, /**. */
	FR_EXCUTE_STATUS_FAILED,	       /**. */
	FR_EXCUTE_STATUS_SUCESS,		   /**. */
	FR_EXCUTE_STATUS_CANCEL,			/**. */
	FR_EXCUTE_STATUS_SHOWPROMPT			/**. */
};
/* @ENUMEND */

#ifndef FR_ACTIONWIZARDDATAHANDLER
#define FR_ACTIONWIZARDDATAHANDLER

typedef struct _t_FR_ActionWizardHandler* FR_ActionWizardHandler;
#endif



/* @DEFGROUPSTART ActionWizardPresetFlag */
/**
* @brief
* @deprecated Internal use 
*/

/*@{*/
/** @brief */
#define FR_ACTIONWIZARD_NOPRESET     0x000
/** @brief */
#define FR_ACTIONWIZARD_PRESET       0x001
/** @brief */
#define FR_ACTIONWIZARD_PROMPTUSER   0x002
/** @brief */
#define FR_ACTIONWIZARD_NOCREATE	 0x004
/*@}*/
/* @DEFGROUPEND */


/* @CALLBACKGROUPSTART FR_ActionWizardHandlerCallbacksRec */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct __FR_ActionWizardHandlerCallbacksRec__
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ActionWizardHandlerCallbacksRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void (*OnGetName)(FS_LPVOID clientData, FS_ByteString outName);

	void (*OnGetCommandName)(FS_LPVOID clientData, FS_ByteString outCmdName);

	FS_INT32 (*OnGetPresetFlag)(FS_LPVOID clientData, FS_XMLElement pXML);

    FS_BOOL (*OnSetting)(FS_LPVOID clientData, FS_XMLElement pXML,FS_HWND hWnd);

	FS_BOOL	(*OnExecute)(FS_LPVOID clientData, FS_XMLElement pXML, FS_BOOL bPromptUser, FRActionWizardExcuteStatus* outStatus);

	FS_BOOL	(*OnGetTitle)(FS_LPVOID clientData, FS_ByteString bsName, FS_WideString outTitle, FS_XMLElement pXML);

	FS_BOOL (*OnNeedReopen)(FS_LPVOID clientData);

	FS_BOOL (*OnNeedChangeExecuteDoc)(FS_LPVOID clientData);

  FS_BOOL (*OnIsEnableExecute)(FS_LPVOID clientData);

  void (*OnExecuteDone)(FS_LPVOID clientData);
  
  FS_BOOL(*OnNeedSaveDoc)(FS_LPVOID clientData);

}FR_ActionWizardHandlerCallbacksRec, *FR_ActionWizardHandlerCallbacks;
/* @CALLBACKGROUPEND */


/* @CALLBACKGROUPSTART FR_ActionWizardHandlerMgrCallbacksRec */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct __FR_ActionWizardHandlerMgrCallbacksRec__
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ActionWizardHandlerMgrCallbacksRec</a>). */
	unsigned long lStructSize;	

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOL (*OnRegisterActionWizardHandler)(FS_LPVOID clientData, FR_ActionWizardHandler actionWizardHandler);
	FS_BOOL	(*OnUnRegisterActionWizardHandler)(FS_LPVOID clientData, FR_ActionWizardHandler actionWizardHandler);
	FR_ActionWizardData (*OnGetActionWizardData)(FS_LPVOID clientData);

}FR_ActionWizardHandlerMgrCallbacksRec, *FR_ActionWizardHandlerMgrCallbacks;
/* @CALLBACKGROUPEND */


#ifndef FR_CPDFPLUGINPROVIDER
#define FR_CPDFPLUGINPROVIDER

typedef struct _t_FR_CPDFPluginProvider* FR_CPDFPluginProvider;
#endif

/* @CALLBACKGROUPSTART FR_CPDFPluginProviderCallbacks */
/** @brief  */
/** @deprecated Internal use.*/
typedef struct _fr_cpdfpluginprovider_callbacks_
{

    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_CPDFPluginProviderCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    FS_BOOL (*OnShowConnectedPDFAdDialog)(FS_LPVOID clientData);

    void (*DoAfterApplySettings)(FS_LPVOID clientData);

    void (*DoConvertTocPDF)(FS_LPVOID clientData, FR_Document frDoc);

    void (*DoConvertTocPDF2)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nOperType);

    void (*OpencPDFWebPage)(FS_LPVOID clientData, FS_ByteString bsURL, FS_ByteString bsTitle);

    void (*GetcPDFID)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nIdType, FS_ByteString bsOutID);

    FS_BOOL (*IsJoinConnectedPDF)(FS_LPVOID clientData);

    void (*GetDocEndpoint)(FS_LPVOID clientData, FR_Document frdoc, FS_ByteString bsOutEndpoint);

    void (*GetPDFDocEndpoint)(FS_LPVOID clientData, FPD_Document pdfdoc, FS_ByteString bsOutEndpoint);

    FS_BOOL (*IsConnectedPDFDoc)(FS_LPVOID clientData, FR_Document frDoc);

    FS_BOOL (*SaveAsNewcPDF)(FS_LPVOID clientData, FR_Document frDoc, FS_WideString wsNewName, FS_WideString outNewPath);

    FS_BOOL (*CheckIfConfigHost)(FS_LPVOID clientData);

    FS_BOOL (*IscPDFServerAvailable)(FS_LPVOID clientData, FS_ByteString bsURL, FS_BOOL bPrompt);
}FR_CPDFPluginProviderCallbacksRec, *FR_CPDFPluginProviderCallbacks;
/* @CALLBACKGROUPEND */

/* @DEFGROUPSTART FRFileFilter */
/**
* @brief
* @deprecated Internal use
*/
/*@{*/
/** @brief *.xls;*.xlt;*.xlsx;*.xltx;*.xlsm;*.xlsb;*.xltm;*.csv */
#define FR_FILTER_EXCEL			0x01
/** @brief *.doc;*.rtf;*.docx;*.dot;*.dotx;*.docm;*.dotm;*.wpd */
#define	FR_FILTER_WORD			0x02
/** @brief *.ppt;*.pptx;*.pot;*.potx;*.pptm;*.ppsx;*.ppsm;*.potm */
#define	FR_FILTER_POWERPOINT	0x04
/** @brief *.txt;*.text */
#define	FR_FILTER_TEXT			0x08
/** @brief *.bmp;*.dib;*.jpg;*.jpeg;*.jpe;*.gif;*.tif;*.tiff;*.png */
#define	FR_FILTER_IMAGE			0x10
/** @brief *.htm;*.html;*.shtml */
#define	FR_FILTER_HTML			0x20
/** @brief *.pdf;*.ppdf */
#define	FR_FILTER_PDF			0x40
/** @brief *.mpp;*.mppx */
#define	FR_FILTER_PROJECT		0x80
/** @brief *.vsd;*.vsdx */
#define	FR_FILTER_VISIO			0x100
/** @brief *.wps */
#define	FR_FILTER_WPS			0x200
/** @brief *.hwp */
#define	FR_FILTER_HWP			0x400
/** @brief *.msg */
#define	FR_FILTER_OUTLOOK		0x800
/** @brief *.xps */
#define	FR_FILTER_XPS		    0x1000
/** @brief *.dwg */
#define	FR_FILTER_CAD		    0x2000
/** @brief *.* */
#define	FR_FILTER_ALLFORMAT		0x4000

/** @brief All. */
#define	FR_FILTER_ALL FR_FILTER_EXCEL | FR_FILTER_WORD | FR_FILTER_POWERPOINT | FR_FILTER_TEXT | FR_FILTER_IMAGE | FR_FILTER_HTML | FR_FILTER_PDF | FR_FILTER_PROJECT | FR_FILTER_VISIO | FR_FILTER_WPS | FR_FILTER_HWP | FR_FILTER_OUTLOOK | FR_FILTER_XPS | FR_FILTER_CAD | FR_FILTER_ALLFORMAT
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKGROUPSTART FR_DocEventForActionWizardCallbacks */

/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct _fr_doceventforactionwizard_callbacks_
{
	unsigned long lStructSize;

	FS_LPVOID		clientData;

	void	(*FRDocDidReOpenForActionWizard)(FS_LPVOID clientData, FR_Document doc, FS_BOOL bMemDoc);

}FR_DocEventForActionWizardCallbacksRec, *FR_DocEventForActionWizardCallbacks;
/* @CALLBACKGROUPEND */

#ifndef FR_WIPPLUGINPROVIDER
#define FR_WIPPLUGINPROVIDER

typedef struct _t_FR_WIPPluginProvider* FR_WIPPluginProvider;
#endif

/* @CALLBACKGROUPSTART FR_WIPPluginProviderCallbacks */

/**
 * @brief 
 * @deprecated Internal use
 */
typedef struct _fr_wippluginprovider_callbacks_
{
    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_WIPPluginProviderCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOL (*WipPluginAllowedPaste)(FS_LPVOID clientData);

	FS_BOOL (*WipPluginShowIFileSaveAsDlg)(FS_LPVOID clientData,
		FS_BOOL bCanSupportPDFOnly,
		FS_BOOL *bChoise, 
		FS_LPCWSTR *pwszFilePath, 
		FS_INT32 *iIndex);

	FS_BOOL	(*WipPluginEncryptFile)(FS_LPVOID clientData,FS_LPCWSTR wszFilePath);

}FR_WIPPluginProviderCallbacksRec, *FR_WIPPluginProviderCallbacks;
/* @CALLBACKGROUPEND */

/* @DEFGROUPSTART FRCompareType */
/**
* @brief
* @deprecated Internal use
*/

/*@{*/
/** @brief .*/
#define COMPARE_NONE		0x000
/** @brief .*/
#define COMPARE_TEXT	    0x001
/** @brief .*/
#define COMPARE_TABLE		0x002

/*@}*/
/* @DEFGROUPEND */

/* @ENUMSTART */
/** @brief .
* @deprecated Internal use
*/
enum FR_RETYPE
{
	FR_COMPARE_NONETYPE = -1,
	FR_COMPARE_DELETE_TEXT,
	FR_COMPARE_INSERT_TEXT,
	FR_COMPARE_REPLACE_TEXT,
	FR_COMPARE_DELETE_IMAGE,
	FR_COMPARE_INSERT_IMAGE,
	FR_COMPARE_REPLACE_IMAGE,
	FR_COMPARE_DELETE_PATH,
	FR_COMPARE_INSERT_PATH,
	FR_COMPARE_REPLACE_PATH,
	FR_COMPARE_DELETE_SHADING,
	FR_COMPARE_INSERT_SHADING,
	FR_COMPARE_REPLACE_SHADING,
	FR_COMPARE_DELETE_ANNOT,
	FR_COMPARE_INSERT_ANNOT,
	FR_COMPARE_REPLACE_ANNOT,
	FR_COMPARE_DELETE_TABLE,
	FR_COMPARE_INSERT_TABLE,
	FR_COMPARE_REPLACE_TABLE,
	FR_COMPARE_MATCH,
	FR_COMPARE_TEXT_ATTRICHANGE,
	FR_COMPARE_INSERT_PAGE,
	FR_COMPARE_DELETE_PAGE,
};
/* @ENUMEND */

/* @DEFGROUPSTART FRCompareTextAttribute */
/**
* @brief Compare Text Attribute
* @deprecated Internal use
*/

/*@{*/
/** @brief .*/
#define COMPARE_TEXT_ATTRI_EQUAL			0
/** @brief .*/
#define COMPARE_TEXT_ATTRI_FONTCHANGE		0x00000001
/** @brief .*/
#define COMPARE_TEXT_ATTRI_FONTSIZECHANGE	0x00000002
/** @brief .*/
#define COMPARE_TEXT_ATTRI_FONTCOLORCHANGE	0x00000004
/** @brief .*/
#define COMPARE_TEXT_ATTRI_LINE             0x00000008
/*@}*/
/* @DEFGROUPEND */

/* @STRUCTSTART FR_WORDPROERITY*/
/**
* @brief .
* @deprecated Internal use
*
*/
typedef struct __FR_WORDPROERITY__
{
	FS_DWORD dwAttriFlag;
	FS_INT32 nFontSize;
	FS_WideString cwFontName;

	__FR_WORDPROERITY__()
	{
		dwAttriFlag = 0;
		nFontSize = 0;
		cwFontName = NULL;
	}
}FR_WORDPROERITY;
/* @STRUCTEND */

/* @STRUCTSTART FR_UIINFO*/
/**
	* @brief .
    * @deprecated Internal use
	*
	*/
typedef struct __FR_UIINFO_
{
	FS_FloatRectArray	rtArray;
	FR_RETYPE			nType;
	FS_WideString		cwDiffContents;
	FS_FLOAT			height;
	FS_AffineMatrix     mt;
	FS_WordArray        arrIndexs;
	FS_BOOL				bFlagOnly;
	FS_INT32			nSect;
	FS_INT32			nLine;
	FS_WordArray		nWordArr;

	FR_WORDPROERITY		*wordAttris;

	__FR_UIINFO_()
	{
		bFlagOnly = FALSE;
		rtArray = NULL;
		nType = FR_RETYPE::FR_COMPARE_NONETYPE;
		cwDiffContents = NULL;
		height = 0;
		arrIndexs = NULL;
		nSect = 0;
		nLine = 0;
		nWordArr = NULL;
		wordAttris = NULL;
	}
} FR_UIINFO;
/* @STRUCTEND */

/* @STRUCTSTART FR_Compare_Results*/
/**
* @brief .
* @deprecated Internal use
*
*/
typedef struct __FR_Compare_Results__
{
	FS_INT32 nInsert;
	FS_INT32 nDelete;
	FS_INT32 nReplace;
	FS_PtrArray arrNewInfo;
	FS_PtrArray arrOldInfo;


	__FR_Compare_Results__()
	{
		nInsert = -1;
		nDelete = -1;
		nReplace = -1;
		arrNewInfo = NULL;
		arrOldInfo = NULL;
	}
}FR_Compare_Results;
/* @STRUCTEND */

#ifndef FR_IFX_INPUTMETHOD
#define FR_IFX_INPUTMETHOD
/**
* @brief A <a>FR_IFX_InputMethod</a> is an reader page view.
* @deprecated Internal use
*/
typedef struct _t_FR_IFX_InputMethod* FR_IFX_InputMethod;

#endif

#ifndef FR_IFX_INPUTMETHODHANDLER
#define FR_IFX_INPUTMETHODHANDLER
/**
* @brief A <a>FR_IFX_InputMethod</a> is an reader page view.
* @deprecated Internal use
*/

typedef struct _t_FR_IFX_InputMethodHandler* FR_IFX_InputMethodHandler;

#endif


/**
* @brief A callback set for Assistant event handler. These callbacks will be invoked when some events of the Assistant occurs.
* See <a>FRAssistantMgrRegisterAssistantHandler</a>.
* @deprecated Internal use
*/
typedef struct _fr_IFX_InputMethod_callbacks_
{

    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FRAssistantMgrRegisterAssistantHandler</a>). */
       unsigned long lStructSize;

       /** The user-supplied data. */
       FS_LPVOID		clientData;


	void(*OnCharsetChanged)(FS_LPVOID clientData, FS_BYTE charset, FS_UINT codepage);
	void(*OnUnicodeChar)   (FS_LPVOID clientData, FS_WideString lpstr);
	void(*OnGetFont)       (FS_LPVOID clientData, LOGFONT &lf);
	void(*OnGetPosition)   (FS_LPVOID clientData, FS_FloatPoint & position);

}FR_IFX_InputMethodCallbacksRec, *FR_IFX_InputMethodCallbacks;

typedef struct __FRRSA_ANNOTDATA__
{
	FR_Annot            	pAnnot;
	FS_Rect					crOriginalRect;
	FS_Rect					crLastMovingRect;
	FS_Rect					crLastRefreshRect;
}FRRSA_ANNOTDATA;

enum FR_PDFAccessibilityCheckerState
{
	FRPDFAccessibility_Checker_None = 0,
	FRPDFAccessibility_Checker_Passed,
	FRPDFAccessibility_Checker_Failed,
	FRPDFAccessibility_Checker_HumanCheck,
	FRPDFAccessibility_Checker_Skipped,
	FRPDFAccessibility_Checker_HumanPassed,
	FRPDFAccessibility_Checker_HumanFailed
};


typedef struct _fr_BulletNotify_callbacks_
{
	//废弃接口，touchpu插件化时添加，现在不用了，考虑接口顺序问题，后面唐晶晶统一删除
}FR_BulletNotifyCallbacksRec, *FR_BulletNotifyCallbacks;


#ifndef FR_FILEMULCOPIESNOTIFY
#define FR_FILEMULCOPIESNOTIFY
/**
 * @brief A data structure representing the cursor.
 * @deprecated Internal use
 */
typedef struct _t_FR_IFieldMulCopiesNotify* FR_IFieldMulCopiesNotify;
#endif


typedef struct _fr_IFieldMulCopiesNotify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DocEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void(*FROnChange)(FS_LPVOID clientData, FS_PtrArray RectInfo, FS_BOOL bPreView, FS_BOOL bSameName);
}FR_IFieldMulCopiesNotifyCallbacksRec, *FR_IFieldMulCopiesNotifyCallbacks;


#ifndef FR_MUCOPYDATA
#define FR_MUCOPYDATA
/**
 * @brief A data of multi copy data.
 * @deprecated Internal use
 */
typedef struct _t_FR_MuCopyData* FR_MuCopyData;
#endif


typedef struct __FR_MuCopySource__
{
	FS_LPVOID pClientData = nullptr;
	FS_FloatRect rect;
}FR_MuCopySource;


#define FRBAC_POINTER			0
#define FRBAC_SELECT			1
#define FRBAC_CROSS			    2
#define FRBAC_HBEAM			    3
#define FRBAC_SIZEALL			4
#define FRBAC_SIZENESW		    5
#define FRBAC_SIZENS			6
#define FRBAC_SIZENWSE		    7
#define FRBAC_SIZEWE			8
#define FRBAC_SELECTCOPY		9
#define FRBAC_SELECTDRAG		10
#define FRBAC_SELECTNODRAG	    11
#define FRBAC_SELECTCAPTION	    12


enum FR_ActionWizardItmeDataType
{
	FRdt_invalid,
	FRdt_boolean,
	FRdt_integer,
	FRdt_double,
	FRdt_atom,
	FRdt_text,
	FRdt_null,
	FRdt_string
};

/* @ENUMSTART */
/** @brief .*/
/** @deprecated Internal use */
enum FRCommentsAnnotIconState
{
	FR_IconState_NONE = -1,        /**. */
	FR_IconState_PUBLISH_SUCCESS,  /**. */
	FR_IconState_PUBLISH_FAILED,   /**. */
	FR_IconState_REVIEW,           /**. */
	FR_IconState_UNREVIEW          /**. */
};
/* @ENUMEND */
/** @OBJEND */

/* @OBJSTART FR_UIMANAGER */
#ifndef FR_UIMANAGER
#define FR_UIMANAGER
/**
* @brief A FR_UIMgr used to manager window.
*/
typedef struct _t_FR_UIMgr* FR_UIMgr;
#endif

/* @CALLBACKSTART FRCreateSplitWndProc */
/**
 * @brief A callback for split window.
* @param[in] m_pReaderDoc			The current document.
* @param[in] hParentWnd		        The hand of parent window.
* @param[in] rtWnd		            The rect of the parent window.
* @return FS_HWND                   Return the hand of split window. 
* @note
* @since <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
*/
typedef FS_HWND(*FRCreateSplitWndProc)(FR_Document m_pReaderDoc, FS_HWND hParentWnd, FS_FloatRect rtWnd);
/* @CALLBACKEND */

/** @OBJEND */

/* @OBJSTART FR_ContainerFrmMgrHandler */
#ifndef FR_CONTAINERFRMMGRHANDLER
#define FR_CONTAINERFRMMGRHANDLER
/**
* @brief A FR_ContainerFrmMgrHandler used to manager container.
*/
typedef struct _t_FR_ContainerFrmMgrHandler* FR_ContainerFrmMgrHandler;
#endif
/** @OBJEND */
/** @OBJEND */


/* @OBJSTART FR_ContainerFrmMgr */
#ifndef FR_CONTAINERFRMMGR
#define FR_CONTAINERFRMMGR
/**
* @brief A FR_ContainerFrmMgr used to manager container.
*/
typedef struct _t_FR_ContainerFrmMgr* FR_ContainerFrmMgr;
#endif

/* @CALLBACKGROUPSTART FR_ContainerFrmEventCallbacksRec */

/**
 * @brief A callback set for application-level event handler. It is called by the <Italic>Foxit Reader</Italic> to
 * route and dispatch command messages and to handle the update of command user-interface objects, such as menu, toolbar.
 * See <a>FRAppRegisterCmdMsgEventHandler</a>.
 */
typedef struct _fr_containerfrmevent_callbacks_
{

	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_CmdMsgEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FROnContainerFrmCreate */
	/**
	 * @brief				A callback for container frame event handler.	
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] hFrmWnd		The container frame.
	 * @return 
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	 */
	void(*FROnContainerFrmCreate)(FS_LPVOID clientData, FS_HWND hFrmWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnContainerFrmLoadFinish */
	/**
	 * @brief				A callback for container frame event handler.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] hFrmWnd		The container frame.
	 * @return
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	 */
	void(*FROnContainerFrmLoadFinish)(FS_LPVOID clientData, FS_HWND hFrmWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnContainerFrmDestory */
	/**
	 * @brief				A callback for container frame event handler.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] hFrmWnd		The container frame.
	 * @return
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	 */
	void(*FROnContainerFrmDestory)(FS_LPVOID clientData, FS_HWND hFrmWnd);
	/* @CALLBACKEND */
}FR_ContainerFrmEventCallbacksRec, *FR_ContainerFrmEventCallbacks;

/* @CALLBACKGROUPEND */
/** @OBJEND */


/* FR_PrintProvider */
#ifndef FR_PRINTPROVIDER
#define FR_PRINTPROVIDER
/**
* @brief A FR_PrintProvider used to private date for print plugin.
* @deprecated Internal use.
*/
typedef struct _t_FR_PrintProvider* FR_PrintProvider;
#endif
/** FR_PrintProvider */


/* FR_WndProvider */
#ifndef FR_WNDPROVIDER
#define FR_WNDPROVIDER
/**
* @brief A FR_WndProvider used to provide current wnd data.
*/
typedef struct _t_FR_WndProvider* FR_WndProvider;
#endif
/** FR_PrintProvider */

/* FR_HandlerDataType */
#ifndef FR_HANDLERDATATYPE
#define FR_HANDLERDATATYPE
/**
* @brief A data type used to tell frame which object is handle.
* @deprecated: Internal use.
*/
typedef struct _t_FR_HandlerDataType* FR_HandlerDataType;
#endif

/* @CALLBACKGROUPSTART FR_HandlerDataTypeCallbacksRec */
/**
 * @brief A callback for frame to check the data type of the current mouse handler object.
 * @deprecated: Internal use.
 */
typedef struct _fr_handlerDataType_callbacks_
{

	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_CmdMsgEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRGetDataType */
	/**
	 * @brief				A callback for frame to check the data type.
	 * @param[in] clientData	The user-supplied data.
	 * @return FS_LPCSTR    Get the data type.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	 */
	FS_LPCSTR (*FRGetDataType)(FS_LPVOID clientData);
	/* @CALLBACKEND */
}FR_HandlerDataTypeCallbacksRec, *FR_HandlerDataTypeCallbacks;
/* @CALLBACKGROUPEND */
/** FR_HandlerDataType */

/* OBJSTART FR_PrintMgr */
#ifndef FR_PRINTMGR
#define FR_PRINTMGR
/**
* @brief A print manager.
*/
typedef struct _t_FR_PrintMgr* FR_PrintMgr;
#endif

/* @ENUMSTART */
/** @brief  Orientation type.*/
enum FR_PrintOrientationType
{
	FRORITYPE_AUTO = 0,
	FRORITYPE_PORTRAIT = 1,
	FRORITYPE_LANDSCAPE = 2
};
/* @ENUMEND */

/* @DEFGROUPSTART FR_PRINT_RANGE */
/**
* @brief SetPrintRange range mode.
*/
/*@{*/
/** @brief .*/
#define FR_PRINT_RANGE_ALL                     0
/** @brief .*/
#define FR_PRINT_RANGE_CURRENT_VIEW            1 
/** @brief .*/
#define FR_PRINT_RANGE_CURRENT_PAGE            2
/** @brief .*/
#define FR_PRINT_RANGE_PAGES                   3
/** @brief .*/
#define FR_PRINT_RANGE_PORTFOLIO_SELECTED      4
/** @brief .*/
#define FR_PRINT_RANGE_PORTFOLIO_ALL           5
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FR_PRINT_SUBSET */
/**
* @brief SetPrintSubset subset mode.
*/
/*@{*/
/** @brief all pages.*/
#define FR_PRINT_SUBSET_ALL                       0  
/** @brief  old pages.*/
#define FR_PRINT_SUBSET_OLD                       1    
/** @brief  even pages.*/
#define FR_PRINT_SUBSET_EVEN                      2     
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FR_PRINT_ROTATE_MODE */
/**
* @brief SetPrintRotate rotate mode 
*/
/*@{*/
/** @brief normal mode.*/
#define FR_PRINT_ROTATE_MODE_NOMAL                  0
/** @brief clockwise mode.*/
#define FR_PRINT_ROTATE_MODE_CLOCKWISE              1
/** @brief counterclockwise.*/
#define FR_PRINT_ROTATE_MODE_COUNTERCLOCKWISE       2
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FR_PRINT_ZOOM_MODE */
/**
* @brief SetPrintScale Scale mode
*/
/*@{*/
/** @brief normal mode.*/
#define FR_PRINT_ZOOM_MODE_NONE                      0 
/** @brief fit page.*/
#define FR_PRINT_ZOOM_MODE_FIT_PAPER                 1
/** @brief reduce page.*/
#define FR_PRINT_ZOOM_MODE_REDUCE_PAPER              2
/** @brief multiple pages.*/
#define FR_PRINT_ZOOM_MODE_MULTIPLE_PAGES            3
/** @brief custom scales.*/
#define FR_PRINT_ZOOM_MODE_CUSTOM_SCALES             4
/** @brief tile large pages.*/
#define	FR_PRINT_ZOOM_MODE_TILE_LARGE_PAGES          5
/** @brief booklet.*/
#define FR_PRINT_ZOOM_MODE_BOOKLET                   6 
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FR_PRINT_DISP_MODE */
/**
* @brief SetPrintArrange nArrangeMode
*/
/*@{*/
/** @brief normal mode.*/
#define FR_PRINT_DISP_MODE_SINGLE_PAGE                  0
/** @brief normal mode.*/
#define FR_PRINT_DISP_MODE_FACING                       1 
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FR_PRINT_ORDER */
/**
* @brief SetPrintPageOrder
*/
/*@{*/
/** @brief HORZ mode.*/
#define FR_PRINT_ORDER_HORZ                                0 
/** @brief HORZ RVERSE mode.*/
#define FR_PRINT_ORDER_HORZ_REVERSED                       1 
/** @brief VER mode.*/
#define FR_PRINT_ORDER_VERT                                2 
/** @brief VER REVERSE mode.*/
#define FR_PRINT_ORDER_VERT_REVERSED                       3
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FR_PRINT_WHAT */
/**
* @brief SetPrintPrintWhat
*/
/*@{*/
/** @brief print document.*/
#define FR_PRINT_WHAT_DOCUMENT                               0
/** @brief print document makeups.*/
#define FR_PRINT_WHAT_DOCUMENT_MAKEUPS                       1 
/** @brief print document stamps.*/
#define FR_PRINT_WHAT_DOCUMENT_STAMPS                        2 
/** @brief print form fields only.*/
#define FR_PRINT_WHAT_FORM_FIELDS_ONLY                       3	
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FR_PRINT_FACING */
/**
* @brief Set print multipe.
*/
/*@{*/
/** @brief print document.*/
#define FR_PRINT_FACING_2                                  0    
/** @brief print document.*/
#define FR_PRINT_FACING_4                                  1
/** @brief print document.*/
#define FR_PRINT_FACING_6                                  2
/** @brief print document.*/
#define FR_PRINT_FACING_9                                  3
/** @brief print document.*/
#define FR_PRINT_FACING_16                                 4
/** @brief print document.*/
#define FR_PRINT_FACING_CUSTOM                             5 
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FR_PRINT_BOOKLET_BINDING_ */
/**
* @brief Set print booklet binding direction.
*/
/*@{*/
/** @brief right direction.*/
#define FR_PRINT_BOOKLET_BINDING_RIGHT                         0
/** @brief left direction.*/
#define FR_PRINT_BOOKLET_BINDING_LEFT                          1
/*@}*/
/* @DEFGROUPEND */


/* @DEFGROUPSTART FR_PRINT_BOOKLET_SUBSET */
/**
* @brief Set print booklet subset.
*/
/*@{*/
/** @brief both.*/
#define FR_PRINT_BOOKLET_SUBSET_BOTH                          0
/** @brief front.*/
#define FR_PRINT_BOOKLET_SUBSET_FRONT                         1
/** @brief back.*/
#define FR_PRINT_BOOKLET_SUBSET_BACK                          2
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FR_PRINT_HANDLING_SUBSET */
/**
* @brief Set printHandling Type
*/
/*@{*/
/** @brief .*/
#define FR_PRINT_HANDLING_NONE                                1
/** @brief .*/
#define FR_PRINT_HANDLING_TILELARGEPAGES                      2
/** @brief .*/
#define FR_PRINT_HANDLING_MULTIPEPAGESPERSHEET                3
/** @brief .*/
#define FR_PRINT_HANDLING_BOOKLET                             4
/*@}*/
/* @DEFGROUPEND */

/** @OBJEND */


/* OBJSTART FR_DRMEventHandler */
#ifndef FR_DRMEVENTHANDLER
#define FR_DRMEVENTHANDLER
/**
* @brief DRM event handler.
*/
typedef struct _t_FR_DRMEventHandler* FR_DRMEventHandler;
#endif

/* @ENUMSTART */
/** @brief funtion type when need decrypt file.*/
enum FR_OtherToPDF
{
	FRConvertToPDF = 0,
	FRInsertImage,
	FRInsertFromFile
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief funtion type when need encryt file.*/
enum FR_PDFToOther
{
	FRExtractPage = 0,
	FRSplitPage,
	FRSaveToImage
};
/* @ENUMEND */

/* @CALLBACKGROUPSTART FR_DRMEventCallbacks */
/**
 * @brief The structure containing DRM event callbacks. Plug-ins invoke these callbacks to provide encrypted and decrypted file.
 * See <a>FRAppRegisterDRMEventHandler</a>.
 *
 */
typedef struct _fr_drm_event_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DRMEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRDRMOnDecryptFile */
	/**
	* @brief It will be invoked when opreate the DRM pdf file.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pszInPath	The file path of DRM pdf file.
	 * @param[out] pszOutPath	The temp file path of decrypted pdf file.
	 * @param[in] operation    The operation type when need to decrypt file.
	 * @return <a>TRUE</a> means the plug-in can decrypt DRM file success. Otherwise not.
	 * @note
	 */
	FS_BOOL(*FRDRMOnDecryptFile)(FS_LPVOID clientData, FS_LPCWSTR pszInPath, FS_WideString* pszOutPath, FR_OtherToPDF operation);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDRMOnDeleteDecryptFile */
	/**
	* @brief It will be invoked when after opreate the DRM pdf file.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pszPath	    The temp file path of decrypted pdf file.
	 * @param[in] operation    The operation type when need to decrypt file.
	 * @return <a>TRUE</a> means the plug-in can delete the temp decrypted file. Otherwise not.
	 * @note
	 */
	FS_BOOL(*FRDRMOnDeleteDecryptFile)(FS_LPVOID clientData, FS_LPCWSTR pszPath, FR_OtherToPDF operation);
	/* @CALLBACKEND */	

	/* @CALLBACKSTART FRDRMOnEncryptDocument */
	/**
	* @brief It will be invoked when need to encrypt pdf file.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pDocument	    The input FR_Document. When split or extract pages with it, plugin need to check if it's an encrypted file.
	 * @param[in] pszInPath	The file path of need to be encrypted.
	 * @param[out] pszOutPath	The temp file path of encrypted pdf file.
	 * @param[in] operation     The operation type when need to encrypt file.
	 * @return <a>TRUE</a> means the plug-in can encrypt DRM file success. Otherwise not.
	 * @note
	 */
	FS_BOOL(*FRDRMOnEncryptFile)(FS_LPVOID clientData, FR_Document pDocument, FS_LPCWSTR pszInPath, FS_WideString* pszOutPath, FR_PDFToOther operation);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRDRMOnDeleteEncryptFile */
	/**
	* @brief It will be invoked when close the encrypt pdf file.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pDocument	    The input FR_Document. When split or extract pages with it, plugin need to check if it's an encrypted file.
	 * @param[in] pszPath	    The input temp file path of encrypted pdf file.
	 * @param[in] operation    The operation type when need to encrypt file.
	 * @return <a>TRUE</a> means the plug-in can encrypt DRM file success. Otherwise not.
	 * @note
	 */
	FS_BOOL(*FRDRMOnDeleteEncryptFile)(FS_LPVOID clientData, FR_Document pDocument, FS_LPCWSTR pszPath, FR_PDFToOther operation);
	/* @CALLBACKEND */

}FR_DRMEventCallbacksRec, *FR_DRMEventCallbacks;
/* @CALLBACKGROUPEND */
/** @OBJEND */

/* OBJSTART FR_PDFBitmapMgr */
#ifndef FR_PDFBITMAPMGR
#define FR_PDFBITMAPMGR
/**
* @brief PDF bitmap mgr.
*/
typedef struct _t_FR_PDFBitmapMgr* FR_PDFBitmapMgr;
#endif
/** @OBJEND */

typedef struct _t_FR_CGWColorDialog* FR_CGWColorDialog;

/* @CALLBACKGROUPSTART FR_CGWColorNotifyCallbacks */
/**
 * @brief 
 *
 */
typedef struct _fr_cgw_color_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DRMEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	void(*FRColorOnColorChange)(FS_LPVOID clientData, FS_COLORREF uFillClr, FS_COLORREF uBorderClr);

}FR_CGWColorNotifyCallbacksRec, *FR_CGWColorNotifyCallbacks;
/* @CALLBACKGROUPEND */

/* OBJSTART FR_StartPageEventHandler */
#ifndef FR_STARTPAGEEVENTHANDLER
#define FR_STARTPAGEEVENTHANDLER
/**
* @brief The start page event handler.
*/
typedef struct _t_FR_StartPageEventHandler* FR_StartPageEventHandler;
#endif

/* @CALLBACKGROUPSTART FR_StartPageEventCallbacks */
/**
 * @brief 
 * See <a>FRAppRegisterStartPageEventHandler</a>.
 *
 */
typedef struct _fr_startpage_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DRMEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FROnStartPageActivate */
	/**
	* @brief It will be invoked when start page activate.
	 * @param[in] clientData	The user-supplied data.
	 * @return void
	 * @note
	 */
	void(*FROnStartPageActivate)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnStartPageDeactivate */
	/**
	* @brief It will be invoked when start page deactivate.
	 * @param[in] clientData	The user-supplied data.
	 * @return void
	 * @note
	 */
	void(*FROnStartPageDeactivate)(FS_LPVOID clientData);
	/* @CALLBACKEND */
}FR_StartPageEventCallbacksRec, *FR_StartPageEventCallbacks;
/* @CALLBACKGROUPEND */
/** @OBJEND */

/* OBJSTART FR_UndoEventHandler */
#ifndef FR_UNDOEVENTHANDLER
#define FR_UNDOEVENTHANDLER
/**
* @brief The undo/redo event handler.
*/
typedef struct _t_FR_UndoEventHandler* FR_UndoEventHandler;
#endif

/* @CALLBACKGROUPSTART FR_UndoEventCallbacks */
/**
 * @brief
 * See <a>FRAppRegisterUndoEventHandler</a>.
 *
 */
typedef struct _fr_undo_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DRMEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FROnBeforeUndo */
	/**
	* @brief It will be invoked when before undo.
	 * @param[in] clientData	The user-supplied data.
	 * @return void
	 * @note
	 */
	void(*FROnBeforeUndo)(FS_LPVOID clientData, FR_Document pDocument);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnBeforeRedo */
	/**
	* @brief It will be invoked when before redo.
	 * @param[in] clientData	The user-supplied data.
	 * @return void
	 * @note
	 */
	void(*FROnBeforeRedo)(FS_LPVOID clientData, FR_Document pDocument);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnAfterUndo */
	/**
	* @brief It will be invoked when after undo.
	 * @param[in] clientData	The user-supplied data.
	 * @return void
	 * @note
	 */
	void(*FROnAfterUndo)(FS_LPVOID clientData, FR_Document pDocument);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FROnAfterRedo */
	/**
	* @brief It will be invoked when after redo.
	 * @param[in] clientData	The user-supplied data.
	 * @return void
	 * @note
	 */
	void(*FROnAfterRedo)(FS_LPVOID clientData, FR_Document pDocument);
	/* @CALLBACKEND */
}FR_UndoEventCallbacksRec, *FR_UndoEventCallbacks;
/* @CALLBACKGROUPEND */
/** @OBJEND */


/* OBJSTART FR_SelectionHandler */
#ifndef FR_SELECTIONHANDLER
#define FR_SELECTIONHANDLER
/**
* @brief selection handler.
*/
typedef struct _t_FR_SelectionHandler* FR_SelectionHandler;
#endif
/** @OBJEND */


//////FR_Internal Start////////
/* FR_SNTwainDriver */
typedef struct _t_FR_SNTwainDriver* FR_SNTwainDriver;
/* FR_SNTwainDriver */

/* FR_AccessibilityFix */
typedef struct _t_FR_AccessibilityFix* FR_AccessibilityFix;
/* FR_Accessibility_Fix */

//scan type
enum FR_ScanType
{
	FR_SCANTYPE_HOMESCAN,	//通过home scan创建
	FR_SCANTYPE_PPO,		//通过PPO insert创建
	FR_SCANTYPE_FORM,		//通过Form创建
	FR_SCANTYPE_COMBINE	//通过Combine创建
};

enum FR_ScanShowDialogType
{
	FR_SHOWNONE = 0,		// custom 界面，所有布局默认
	FR_HIDEPOSTCONFIG = 1,	//custom 界面 ，但是postconfig 等都收缩起来
	FR_MANGERCONFIG,		//显示  managepreset界面
	FR_PPO_SHOWCUSTOM,		//custom界面，通过ppo打开，将output选项置灰，默认选中new pdf document
	FR_FORM_SHOWCUSTOM,		//custom界面，通过form打开，ouput置灰，默认选中new（同ppo)
	FR_COMBINE_SHOWCUSTOM,		//custom界面，通过combine打开，将output选项置灰，默认选中new pdf document
};

typedef void(*FREndScanFun)(FS_INT32 state, FS_LPVOID clientData);
/** FR_SNTwainDriver */

/* FR_SNRecordOper */
typedef struct _t_FR_SNRecordOper* FR_SNRecordOper;
/** FR_SNRecordOper */

typedef void(*FSConvertPdfFromWebCallback)(FS_LPCWSTR wsCurConventUrl, FS_INT32 nInsertPos, FR_Document readerDocument, FS_INT32 nCurrentPage);

typedef void(*FSCopyFieldsDictNotify)(FS_DWORD oldDictnum, FS_DWORD newDictNum, FS_LPVOID pClientData);

enum class FR_ConvertMediaErrorType
{
	SUCCESS,
	FAIL,
	CANCEL
};

enum FR_JSProcType
{
	FR_JSPROCTYPE_Mark = 0,
	FR_JSACTION_Exec,
	FR_JSACTION_Enable
};

typedef void(*FRFormRecognitionProc)(FS_LPVOID pApp, FR_Document pReadDoc, FS_BOOLEAN bShowUI, FS_BOOL bResetAp);

typedef struct _fr_PrompPage_
{	
	FS_LPCWSTR csRealPage;		//真实页名
	FS_LPCWSTR csInputPage;	    //输入页名，添加转义符后的页名
	FS_INT32   nPageNum;		//所在页数 1-base
}FR_PrompPage;

struct FR_PAGECONTENT_OBJECT
{
	FR_STRUCTCONTENT_OBJECT obj; //it needs create by FRInternalCreateContentObject
	FS_FloatRect rcBBox;
};

enum FRRSA_UNDOTYPE
{
	FRRSA_CREATE = 0,
	FRRSA_MOVE,
	FRRSA_MOVETOPAGE,
	FRRSA_ROTATE
};

typedef struct _fr_rsa_undo_data_
{
	FRRSA_UNDOTYPE                  m_eType;
	FS_LPCWSTR					    m_cwDescr;
	FS_FloatRect					m_oldRect;
	FS_FloatRect					m_newRect;
	FS_ReaderDateTime				m_dtModifyOld;
	FS_ReaderDateTime				m_dtModifyNew;
	FS_FloatRect					m_crPopupOld;
	FS_FloatRect					m_crPopupNew;
	FS_INT32						m_nOldRotate;
	FS_INT32						m_nNewRotate;
	FR_Page					        m_pDesPage;
	FPD_Object				        m_pRotateAnnotDict;
	FS_DWORD						m_dwCurAPObjNum;
	FS_DWORD						m_dwOldAPObjNum;
}FRRSA_UNDO_DATA;

/* @CALLBACKGROUPEND */

enum FR_PACKAGELANG
{
	FR_CHINESE_VERSION = 0,
	FR_JAPANESE_VERSION,
	FR_KOKR_VERSION,
	FR_ML_VERSION,
	FR_TW_VERSION,
	FR_EN_VERSION
};

typedef FS_BOOLEAN(*FRInternalAccessibilityFixProc)(FS_INT32 nPercent, FS_INT32 nPageindex, FS_LPVOID pClientData);

typedef FS_DWORD(*FRStartParserProc)(FS_LPVOID pClientData);

/* @OBJSTART FR_TextMarkupAnnot */
#ifndef FR_TEXTMARKUPANNOT
#define FR_TEXTMARKUPANNOT
/**
* @brief  A <a>FR_TextMarkupAnnot</a>
*/
/** @Deprecated: Internal use. */
typedef struct _t_FR_TextMarkupAnnot* FR_TextMarkupAnnot;
#endif

typedef FS_BOOL(*FR_TextMarkupPROGRESSCBK)(FS_LPVOID pProgressCtrl, FS_INT32 nPos);

/* @STRUCTSTART FR_HighLightPageTextPos */
/**
  * @brief .
  */
typedef struct _fr_annotdicts_
{
	FS_INT32  pageIndex;
	FS_PtrArray annotDictArr;

	_fr_annotdicts_()
	{
		pageIndex = -1;
		annotDictArr = NULL;
	}
}FR_AnnotDicts, *PFR_AnnotDicts;
/* @STRUCTEND */

/* OBJEND */

/* @OBJSTART FR_FAAItemObject */
#ifndef FR_FAAITEMOBJECT
#define FR_FAAITEMOBJECT
/**
* @brief  A <a>FR_FAAItemObject</a>
*/
/** @Deprecated: Internal use. */
typedef struct _t_FR_FAAItemObject* FR_FAAItemObject;
#endif
/* OBJEND */

enum FR_EXPORT_COMMENTS_TYPE
{
	FDF,
	XFDF,
	JSON
};

//////FR_Internal End////////

#ifdef __cplusplus
};
#endif

#endif//FR_APPEXPT_H
/*@}*/ 

/*@}*/ 
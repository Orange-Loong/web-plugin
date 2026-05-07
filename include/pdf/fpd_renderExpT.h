/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_renderExpT.h
		
 - Types, macros, structures, etc. required to use the FPDRender HFT.

*********************************************************************/

/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/

/**
* @file
* @brief PDF render functions.
*/

#ifndef FPD_RENDEREXPT_H
#define FPD_RENDEREXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "fpd_objsExpT.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "fpd_pageExpT.h"
#endif

#ifndef FPD_PAGEOBJEXPT_H
#include "fpd_pageobjExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "fpd_docExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/** @addtogroup FPDRENDER */
/*@{*/

/* @OBJSTART FPD_RenderOptions */
/* @DEFGROUPSTART FPDRenderOptColorModeCodes */

/**
  * @name Color mode codes for render options. See <a>FPDRenderOptionsGetColorMode</a>, <a>FPDRenderOptionsSetColorMode</a>.
  */

/*@{*/

/** @brief Normal color mode. */
#define FPD_RENDER_COLOR_NORMAL		0
/** @brief Gray color mode: map colors to background/foreground. */
#define FPD_RENDER_COLOR_GRAY		1
/** @brief Two color mode: map white/black to background/foreground, other unchanged. */
#define FPD_RENDER_COLOR_TWOCOLOR	2
/** @brief Output alpha only, ignore color. */
#define FPD_RENDER_COLOR_ALPHA		3
/** @brief Custom color mode. map colors to foreground. */
#define FPD_RENDER_COLOR_CUSTOM		4

/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDRenderOptBitmasksFlag */
/**
  * @name Flag bitmasks for render option. See <a>FPDRenderOptionsGetRenderFlag</a>, <a>FPDRenderOptionsSetRenderFlag</a>.
  */
/*@{*/

/** @brief Use ClearType-like anti-aliasing. */
#define FPD_RENDER_CLEARTYPE			0x01
/** @brief Always output text as graphics (path or bitmap), don't allow device font substitution. */
#define FPD_RENDER_PRINTGRAPHICTEXT		0x02
/** @brief Always use downsampling for image stretching. */
#define FPD_RENDER_FORCE_DOWNSAMPLE		0x04
/** @brief Print preview mode. */
#define FPD_RENDER_PRINTPREVIEW			0x08
/** @brief For clear type: choose BGR stripe device (most device using RGB). */
#define FPD_RENDER_BGR_STRIPE			0x10
/** @brief Disable native text rendering feature (like GDI+) */
#define FPD_RENDER_NO_NATIVETEXT		0x00000020
/** @brief Always use halftone for image stretching. */
#define FPD_RENDER_FORCE_HALFTONE		0x40
/** @brief Always use anti-aliasing for rectangle drawing. */
#define FPD_RENDER_RECT_AA				0x80
/** @brief Always use aliasing for path drawing. */
#define FPD_RENDER_FILL_FULLCOVER		0x00000100
/** @brief Always output text as bitmap in less than 50 font size case, use for epson stylus printer or other specified printers. */
#define FPD_RENDER_PRINTIMAGETEXT       0x00000200
/** @brief Using overprint to render page. */
#define FPD_RENDER_OVERPRINT            0x00000400
/** @brief Using thin line for path drawing. */
#define FPD_RENDER_THINLINE             0x00000800
/** @brief enhance zero line. */
#define FPD_RENDER_ENHANCEZEROLINE		0x00001000
/** @brief Always use downsampling for huge black/white image stretching. It only works on mini platform */
#define FPD_RENDER_MONO_FORCE_DOWNSAMPLE	0x00002000
/** @brief Do not use anti-aliasing to render text objects, this flag doesn't set in default. */
#define FPD_RENDER_NOTEXTSMOOTH			0x10000000
/** @brief Do not use anti-aliasing to render path objects, this flag doesn't set in default. */
#define FPD_RENDER_NOPATHSMOOTH			0x20000000
/** @brief Do not smooth images when render image objects, this flag doesn't set in default. */
#define FPD_RENDER_NOIMAGESMOOTH		0x40000000
/** @brief Do interpolation when stretch image. This flag is invalid if set RENDER_NOIMAGESMOOTH. */
#define FPD_RENDER_IMAGEINTERPOL		0x80000000
/** @brief Limit image cache size. */
#define FPD_RENDER_LIMITEDIMAGECACHE	0x01000000
/** @brief The text knockout is true. */
//Note: This flag can't be set by application. This is set automatically based on the text knockout property of the text object.
#define FPD_RENDER_TEXTKNOCKOUT			0x00010000
/** @brief The color of text need to be replaced.*/
#define FPD_RENDER_COLORREPLACE_TEXT		0x00000001
/** @brief The color of path need to be replaced.*/
#define FPD_RENDER_COLORREPLACE_PATH		0x00000002
/** @brief The black color of text need to be replaced.*/
#define FPD_RENDER_COLORREPLACE_TEXT_ONLYBLACK	0x00000100
/** @brief The black color of path need to be replaced.*/
#define FPD_RENDER_COLORREPLACE_PATH_ONLYBLACK	0x00000200
	/** @brief To enable downsample the jpx images.*/
#define FPD_RENDER_ENABLE_JPX_DOWNSAMPLE		0x00200000
/*@}*/

/* @DEFGROUPEND */

/**
  * @brief Page rendering options. see CHAPTER 6 in PDF reference. See <a>FPDRenderOptionsNew</a>, <a>FPDRenderOptionsDestroy</a>.
  */
#ifndef FPD_RENDEROPTIONS
#define FPD_RENDEROPTIONS
	typedef struct _t_FPD_RenderOptions* FPD_RenderOptions;
#endif
/* @OBJEND */

/* @OBJSTART FPD_RenderDevice */

/**
  * @brief The base function set for render devices.
  *
  * This set provide all rendering features common to all output devices (including display, printer, and special devices like converters).
  * The render device makes use of Foxit Rendering Device Driver to do the actual output. See <a>FPDRenderDeviceNew</a>, <a>FPDRenderDeviceDestroy</a>.
  */
#ifndef FPD_RENDERDEVICE
#define FPD_RENDERDEVICE
	typedef struct _t_FPD_RenderDevice* FPD_RenderDevice;
#endif
/* @OBJEND */

/* @OBJSTART FPD_FxgeDevice */
/** @brief Foxit own FXGE rendering device, using the Foxit FXGE device driver.
 * Supporting output to following formats:<br>
 * <ul>
 * <li> 8bppMask: the output will be the alpha channel.</li>
 * <li> 8bppRgb without palette: the output will be grayscale.</li>
 * <li> Rgb, Rgb32: normal RGB output.</li>
 * <li> Argb: RGB with alpha channel output. </li>
 * </ul>
 */
/* @OBJEND */

/* @OBJSTART FPD_WindowsDevice */
/** @brief The rendering device based on Windows device driver.
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_RenderContext */
/**
  * @brief Context for rendering a PDF page or a list of page objects.
  *
  * A PDF page can be divided into different layers, including the page content, annotations, and interactive form.
  * It's important to keep information about those layers if backdrop generation is required during transparency
  * rendering for devices not capable of fetching background.
  * 
  * A PDF rendering context also makes use of page caches, additional page resources, and rendering options.
  * See <a>FPDRenderContextNew</a>, <a>FPDRenderContextNew2</a>, <a>FPDRenderContextDestroy</a>.
  */
#ifndef FPD_RENDERCONTEXT
#define FPD_RENDERCONTEXT
	typedef struct _t_FPD_RenderContext* FPD_RenderContext;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ProgressiveRender */
/**
  * @brief The PDF progressive renderer.
  *
  * A progressive renderer that breaks the full rendering process into steps.
  * This class must be overloaded in order to pause a step whenever the application thinks necessary.
  * 
  * Application must first call Start() to start the rendering, then, when it's paused, the application
  * must call Continue() to continue the rendering, until status becomes Done or Failed.
  * 
  * To stop the rendering, simply destruct the renderer.
  * See <a>FPDProgressiveRenderNew</a>, <a>FPDProgressiveRenderDestroy</a>.
  */
#ifndef FPD_PROGRESSIVERENDER
#define FPD_PROGRESSIVERENDER
	typedef struct _t_FPD_ProgressiveRender* FPD_ProgressiveRender;
#endif
/* @OBJEND */


/* @OBJSTART FPD_PageRenderCache */
/** @brief Store all dispensable items used when rendering a page. See <a>FPD_BackgroundDraw</a>
  * Note: Currently we have image cache only.
  */
#ifndef FPD_PAGERENDERCACHE
#define FPD_PAGERENDERCACHE
	typedef struct _t_FPD_PageRenderCache* FPD_PageRenderCache;
#endif
/* @OBJEND */
	
/* @OBJSTART FPD_OCContextHandler */
/** 
  * @brief PDF optional content context interface. Used for holding a  <a>FPD_OCContextCallBack</a>.
  */ 	
#ifndef FPD_OCCONTEXTHANDLER
#define FPD_OCCONTEXTHANDLER
	typedef struct _t_FPD_OCContextHandler* FPD_OCContextHandler;
#endif

	
#ifndef FPD_OCCONTEXTCALLBACK
#define FPD_OCCONTEXTCALLBACK
/* @CALLBACKGROUPSTART FPD_OCContextCallBack */
/** 
  * @brief The PDF optional content context callback struct. See <a>FPD_OCContextHandler</a>.
  */ 
typedef struct __FPD_OCContextCallBack__
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_OCContextCallBack</a>).  */
	unsigned long lStructSize;

	/* @CALLBACKSTART CheckOCGVisible */
	/**
	 * @brief Check whether a option content group is visible.
	 *
	 * @param[in] ocg		The optional content group dictionary.
	 * @return Non-zero means visible, otherwise invisible. 
	 */
	FS_BOOL (*CheckOCGVisible)(FPD_Object ocg);
	/* @CALLBACKEND */

	/* @CALLBACKSTART CheckObjectVisible */
	/** 
	* @brief Check whether an object is visible in this context
	*
	* @param[in] obj			Page object.
	* @return Non-zero means visible, otherwise invisible. 
	*/
	FS_BOOL (*CheckObjectVisible)(FPD_PageObject obj);
	/* @CALLBACKEND */
	
}FPD_OCContextCallBack,*PFPD_OCContextCallBack;
#endif
/* @CALLBACKGROUPEND */
/* @OBJEND */

/* @OBJSTART FPD_BackgroundDrawHandler */
/** @brief PDF background drawing interface. Use for holding a <a>FPD_BackgroundDraw</a>.
  */
#ifndef FPD_BACKGROUNDDRAWHANDLER
#define FPD_BACKGROUNDDRAWHANDLER
	typedef struct _t_FPD_BackgroundDrawHandler* FPD_BackgroundDrawHandler;
#endif

/* @CALLBACKGROUPSTART FPD_BackgroundDraw */
/** 
  * @brief PDF background drawing callback struct. See <a>FPD_BackgroundDrawHandler</a>.
  */
#ifndef FPD_BACKGROUNDDRAW
#define FPD_BACKGROUNDDRAW
typedef struct __FPD_BackgroundDraw__
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_BackgroundDraw</a>).  */
	unsigned long lStructSize;


	/* @CALLBACKSTART OnDrawBackground */
	/**
	*  @brief The callback for drawing background region. 
	*
	* For custom background PDF rendering on a non-display device (like printers), it's often not possible
	* for rendering engine to get a background (for masked operations or transparent operations), therefore
	* the rendering application has to provide a routine to draw the custom background into a bitmap device.
	* In most cases, only portion of the background is needed. 
	* Default implementation fills white color.
	*
	* @param[in] bitmapDevice		The temporary bitmap device. The size of this device an be only portion of the rendering target device.
	* @param[in] original2Bitmap	The matrix from original device space to bitmap device space.
	* @return void
	* @note The bitmap device for rendering background might have different resolution from the original device,
	* for example, in order to reduce spooling size, we use lower resolution for rendering shading areas and
	* transparent images.
	*/
	void (*OnDrawBackground)(FPD_RenderDevice bitmapDevice,FS_AffineMatrix original2Bitmap);
	/* @CALLBACKEND */

}FPD_BackgroundDraw,*PFPD_BackgroundDraw;
#endif
/* @CALLBACKGROUPEND */
/* @OBJEND */

/* @OBJSTART FPD_CPWL_Image */
#ifndef FPD_CPWLIMAGE
#define FPD_CPWLIMAGE
typedef struct _t_FPD_CPWL_Image* FPD_CPWL_Image;
#endif
/* @OBJEND */

/* @OBJSTART FPD_CPWLLABEL */
#ifndef FPD_CPWLLABEL
#define FPD_CPWLLABEL
typedef struct _t_FPD_CPWL_Label* FPD_CPWL_Label;
#endif
/* @OBJEND */

/* @OBJSTART FPD_CPWLLABEL */
#ifndef FPD_CPWLWND
#define FPD_CPWLWND
typedef struct _t_FPD_CPWL_Wnd* FPD_CPWL_Wnd;
#endif
/* @OBJEND */


/* @OBJSTART FPD_CPWLLABEL */
#ifndef FPD_CPWLTIMERHANDLER
#define FPD_CPWLTIMERHANDLER
typedef struct _t_FPD_CPWL_TimerHandler* FPD_CPWL_TimerHandler;
#endif
/* @OBJEND */


/* @OBJSTART FPD_CPWLLABEL */
#ifndef FPD_CPWLFOCUSHANDLER
#define FPD_CPWLFOCUSHANDLER
typedef struct _t_FPD_CPWL_FocusHandler* FPD_CPWL_FocusHandler;
#endif
/* @OBJEND */


/* @OBJSTART FPD_CPWL_Provider */
#ifndef FPD_CPWLPROVIDER
#define FPD_CPWLPROVIDER
typedef struct _t_FPD_CPWL_Provider* FPD_CPWL_Provider;
#endif
/* @OBJEND */

/* @OBJSTART FPD_CPWL_Provider */
#ifndef FPD_CPWLUTILS
#define FPD_CPWLUTILS
typedef struct _t_FPD_CPWL_Utils* FPD_CPWL_Utils;
#endif
/* @OBJEND */

/* @STRUCTSTART FR_EDIT_FontData*/
#ifndef FR_EDIT_FONTDATA
#define FR_EDIT_FONTDATA
/**
* @brief
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
/* @STRUCTEND */


/* @OBJSTART FR_Edit */
#ifndef FR_EDIT
#define FR_EDIT
/**
 * @brief
 */
typedef struct _t_FR_Edit* FR_Edit;
#endif
/* @OBJEND */



/* @CALLBACKGROUPSTART FPD_CPWLTimerHandlerCallback */
#ifndef FPD_CPWLTIMERHANDLERCALLBACK
#define FPD_CPWLTIMERHANDLERCALLBACK
typedef struct
{
    /* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EDITCONTEXT</a>).  */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    void(*FPDTimerProc)(FS_LPVOID clientData);
    FS_LPVOID(*FPDGetSystemHandler)(FS_LPVOID clientData);
}FPD_CPWLTimerHandlerCallbacksRec, *FPD_CPWLTimerHandlerCallback;
#endif
/* @CALLBACKGROUPEND */


/* @CALLBACKGROUPSTART FPD_CPWLFocusHandlerCallback */
#ifndef FPD_CPWLFOCUSHANDLERCALLBACK
#define FPD_CPWLFOCUSHANDLERCALLBACK
typedef struct
{
    /* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EDITCONTEXT</a>).  */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    void(*FPDOnSetFocus)(FS_LPVOID clientData, FPD_CPWL_Wnd pWnd);
    void(*FPDOnKillFocus)(FS_LPVOID clientData, FPD_CPWL_Wnd pWnd);
}FPD_CPWLFoucsHandlerCallbacksRec, *FPD_CPWLFoucsHandlerCallback;
#endif
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FPD_CPWLProvider */
#ifndef FPD_CPWLPROVIDERCALLBACK
#define FPD_CPWLPROVIDERCALLBACK
typedef struct
{
    /* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EDITCONTEXT</a>).  */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    FS_AffineMatrix(*FPDGetWindowMatrix)(FS_LPVOID clientData, void* pAttachedData);
    void(*FPDLoadPopupMenuString)(FS_LPVOID clientData, FS_INT32 nIndex, FS_WideString* wspopup);
    void(*FPDAddSubMenu)(FS_LPVOID clientData, FS_LPVOID pPopup, FS_LPVOID pEdit);
    FS_BOOL(*FPDCanChangeRTL)(FS_LPVOID clientData);
    FS_BOOL(*FPDCanUndo)(FS_LPVOID clientData, FS_LPVOID  pEdit);
    FS_BOOL(*FPDCanRedo)(FS_LPVOID clientData, FS_LPVOID pEdit);
    void(*FPDUndo)(FS_LPVOID clientData, FS_LPVOID pEdit);
    void(*FPDRedo)(FS_LPVOID clientData, FS_LPVOID pEdit);
}FPD_CPWLProviderCallbacksRec, *FPD_CPWLProviderCallback;
#endif
/* @CALLBACKGROUPEND */


typedef struct __FPDCPWL_Dash__
{
    FS_INT32 nDash;
    FS_INT32 nGap;
    FS_INT32 nPhase;
}FPDCPWL_Dash;


/* @CALLBACKGROUPSTART FPD_CPWLProvider */
#ifndef FPD_CPWLWNDCALLBACK
#define FPD_CPWLWNDCALLBACK
typedef struct
{
    /* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EDITCONTEXT</a>).  */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    void(*FPDCreate)(FS_LPVOID clientData, FS_LPVOID cp);
    void(*FPDSetTextColor)(FS_LPVOID clientData, FS_COLORREF color); \
        void(*FPDCreateChildWnd)(FS_LPVOID clientData, FS_LPVOID cp);
    void(*FPDRePosChildWnd)(FS_LPVOID clientData);
    void(*FPDDrawThisAppearance)(FS_LPVOID clientData, FPD_RenderDevice pDevice, FS_AffineMatrix* pUser2Device);
}FPD_CPWLWndCallbacksRec, *FPD_CPWLWndCallback;
#endif
/* @CALLBACKGROUPEND */

typedef struct __FPD_ColorF__ {
    FS_INT32 nColorType;
    FS_FLOAT fColor1;  //R
    FS_FLOAT fColor2;  //G
    FS_FLOAT fColor3;  //B
    FS_FLOAT fColor4;  //A
}FPD_ColorF;

enum  FPDRenderStatus
{
  FPDReady,        /**< Ready. */
  FPDToBeContinued,    /**< To be continued. */
  FPDDone,        /**< Done. */
  FPDFailed        /**< Failed. */
};

#define FPDPWL_ICONTYPE_CHECKMARK 0
#define FPDPWL_ICONTYPE_CIRCLE 1
#define FPDPWL_ICONTYPE_COMMENT 2
#define FPDPWL_ICONTYPE_CROSS 3
#define FPDPWL_ICONTYPE_HELP 4
#define FPDPWL_ICONTYPE_INSERTTEXT 5
#define FPDPWL_ICONTYPE_KEY 6
#define FPDPWL_ICONTYPE_NEWPARAGRAPH 7
#define FPDPWL_ICONTYPE_TEXTNOTE 8
#define FPDPWL_ICONTYPE_PARAGRAPH 9
#define FPDPWL_ICONTYPE_RIGHTARROW 10
#define FPDPWL_ICONTYPE_RIGHTPOINTER 11
#define FPDPWL_ICONTYPE_STAR 12
#define FPDPWL_ICONTYPE_UPARROW 13
#define FPDPWL_ICONTYPE_UPLEFTARROW 14
#define FPDPWL_ICONTYPE_GRAPH 15
#define FPDPWL_ICONTYPE_PAPERCLIP 16
#define FPDPWL_ICONTYPE_ATTACHMENT 17
#define FPDPWL_ICONTYPE_TAG 18
#define FPDPWL_ICONTYPE_FOXIT 19
#define FPDPWL_ICONTYPE_FORBID 20
#define FPDPWL_ICONTYPE_CHECKMARK2 21
#define FPDPWL_ICONTYPE_STICKEX 22
#define FPDPWL_ICONTYPE_CROSSEX 23
#define FPDPWL_ICONTYPE_QUESTION 24
#define FPDPWL_ICONTYPE_EXCLMARK 25
#define FPDPWL_ICONTYPE_DEFERRED 26
#define FPDPWL_ICONTYPE_FUTURE 27
#define FPDPWL_ICONTYPE_UNKNOWN -1



/** @brief Transparent. */
#define FPDCOLORTYPE_TRANSPARENT	0
/** @brief Gray. */
#define FPDCOLORTYPE_GRAY			1
/** @brief RGB. */
#define FPDCOLORTYPE_RGB			2
/** @brief CMYK. */
#define FPDCOLORTYPE_CMYK			3


#define FPDPWS_CHILD      0x80000000L
#define FPDPWS_BORDER     0x40000000L
#define FPDPWS_BACKGROUND 0x20000000L
#define FPDPWS_HSCROLL    0x10000000L
#define FPDPWS_VSCROLL    0x08000000L
#define FPDPWS_VISIBLE    0x04000000L
#define FPDPWS_DISABLE    0x02000000L
#define FPDPWS_READONLY   0x01000000L
#define FPDPWS_AUTOFONTSIZE 0x00800000L
#define FPDPWS_AUTOTRANSPARENT 0x00400000L
#define FPDPWS_NOREFRESHCLIP 0x00200000L
#define FPDPWS_PICKBUTTON 0x00100000L

/** @brief edit and label styles.*/
#define FPDPES_MULTILINE   0x0001L
#define FPDPES_PASSWORD    0x0002L
#define FPDPES_LEFT        0x0004L
#define FPDPES_RIGHT       0x0008L
#define FPDPES_MIDDLE      0x0010L
#define FPDPES_TOP         0x0020L
#define FPDPES_BOTTOM      0x0040L
#define FPDPES_CENTER      0x0080L
#define FPDPES_CHARARRAY   0x0100L
#define FPDPES_AUTOSCROLL  0x0200L
#define FPDPES_AUTORETURN  0x0400L
#define FPDPES_UNDO        0x0800L
#define FPDPES_RICH        0x1000L
#define FPDPES_SPELLCHECK  0x2000L
#define FPDPES_TEXTOVERFLOW 0x4000L
#define FPDPES_NOREAD      0x8000L
#define FPDPES_MULTILINEAUTOSIZE 0x10000L
#define FPDPES_DIRECTION_RTL 0x20000L

/** @brief border style.*/
#define FPDPBS_SOLID      0
#define FPDPBS_DASH       1
#define FPDPBS_BEVELED    2
#define FPDPBS_INSET      3
#define FPDPBS_UNDERLINED 4
#define FPDPBS_SHADOW     5

#ifndef FPD_CPWLIMAGECALLBACK
#define FPD_CPWLIMAGECALLBACK
typedef struct __FPD_CPWLImageCallbacks__
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;
	
	void(*FPDGetImageAppStream)(FS_LPVOID clientData, FS_ByteString* outStream);
	void(*FPDGetScale)(FS_LPVOID clientData, FS_FLOAT* fHScale, FS_FLOAT* fVScale);
	void(*FPDGetImageOffset)(FS_LPVOID clientData, FS_FLOAT* x, FS_FLOAT* y);
	FPD_Object(*FPDGetPDFStream)(FS_LPVOID clientData);
	void(*FPDDrawThisAppearance)(FS_LPVOID clientData, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device);
	void(*FPDDrawChildAppearance)(FS_LPVOID clientData, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device);
	void(*FPDCreate)(FS_LPVOID clientData, FS_LPVOID param);
}FPD_CPWLImageCallbacksRec, *FPD_CPWLImageCallbacks;
#endif

#ifndef FPD_CPWLLABELCALLBACK
#define FPD_CPWLLABELCALLBACK
typedef struct __FPD_CPWLLabelCallbacks__
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void(*FPDGetClassNamePWL)(FS_LPVOID clientData, FS_ByteString* outName);
	void(*FPDSetFontSize)(FS_LPVOID clientData, FS_FLOAT fFontSize);
	FS_FLOAT(*FPDGetFontSize)(FS_LPVOID clientData);
	void(*FPDSetDirectionRTL)(FS_LPVOID clientData,FS_BOOLEAN bRTL, FS_BOOLEAN bApplyAllSection, FS_BOOLEAN bAddUndo);
	void(*FPDOnCreated)(FS_LPVOID clientData);
	void(*FPDRePosChildWnd)(FS_LPVOID clientData);
	void(*FPDDrawThisAppearance)(FS_LPVOID clientData, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device);
	void(*FPDCreate)(FS_LPVOID clientData, FS_LPVOID param);
}FPD_CPWLLabelCallbacksRec, *FPD_CPWLLabelCallbacks;
#endif


#ifndef FPD_SYSTEMTIMER
#define FPD_SYSTEMTIMER
/* @STRUCTSTART FPD_SYSTEMTIME*/
typedef struct __FPD_SYSTEMTIME__
{
    FS_WORD wYear;			//Year
    FS_WORD wMonth;			//Month, 1 - 12
    FS_WORD wDayOfWeek;		//Day of week, Sunday is 0, Monday is 1, ...
    FS_WORD wDay;			//Day of month, start from 1 - 31
    FS_WORD wHour;			//Hour, 0 - 23
    FS_WORD wMinute;		//Minute, 0 - 59
    FS_WORD wSecond;		//Second, 0 - 59
    FS_WORD wMilliseconds;	//Millisecond, 0 - 999
}FPD_SYSTEMTIME, *PFPD_SYSTEMTIME;
/* @STRUCTEND */
#endif

/* @OBJSTART FPD_Graphics */
#ifndef FPD_GRAPHICS
#define	FPD_GRAPHICS
typedef struct _t_FPD_Graphics* FPD_Graphics;
#endif
/* @OBJEND */

/* @OBJSTART FPD_CustomCursorHandler */
#ifndef FPD_CUSTOMCURSORHANDLER
#define	FPD_CUSTOMCURSORHANDLER
typedef struct _t_FPD_CustomCursorHandler* FPD_CustomCursorHandler;
#endif

#ifndef FPD_CUSTOMCURSORHANDLERCALLBACK
#define FPD_CUSTOMCURSORHANDLERCALLBACK
typedef struct __FPD_CustomCursorHandlerCallbacks__
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void(*FPDSetCustomCursor)(FS_LPVOID clientData, FS_INT32 nCursorType, FS_LPVOID hWnd);
}FPD_CustomCursorHandlerCallbacksRec, *FPD_CustomCursorHandlerCallbacks;
#endif

/* @OBJEND */

/* @OBJSTART FPD_SystemHandler */
#ifndef FPD_SYSTEMHANDLER
#define FPD_SYSTEMHANDLER
/**
 * @brief
 */
typedef struct _t_FPD_SystemHandler* FPD_SystemHandler;
#endif

typedef void(*FPDSystemTimerCallback)(FS_INT32 idEvent, FS_INT32 dwiTme);

#ifndef FPD_SYSTEMHANDLERCALLBACK
#define FPD_SYSTEMHANDLERCALLBACK
typedef struct __FPD_SystemHandlerCallbacks__
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;
	void(*FPDRelease)(FS_LPVOID clientData);
	void(*FPDInvalidateRect)(FS_LPVOID clientData, FS_LPVOID hWnd, FS_Rect rect);
	void(*FPDOutputSelectedRect)(FS_LPVOID clientData, FS_LPVOID pFormFiller, FS_FloatRect* rect);
	FS_BOOLEAN(*FPDIsSelectionImplemented)(FS_LPVOID clientData);
	void(*FPDGetClipboardText)(FS_LPVOID clientData, FS_LPVOID hWnd,FS_WideString* outText);
	FS_BOOLEAN(*FPDSetClipboardText)(FS_LPVOID clientData, FS_LPVOID hWnd, FS_WideString string);
	void(*FPDClientToScreen)(FS_LPVOID clientData, FS_LPVOID hWnd, FS_INT32* x, FS_INT32* y);
	void(*FPDScreenToClient)(FS_LPVOID clientData, FS_LPVOID hWnd, FS_INT32* x, FS_INT32* y);
	void(*FPDSetCursor)(FS_LPVOID clientData, FS_INT32 nCursorType, FS_LPVOID hWnd);
	FS_LPVOID(*FPDCreatePopupMenu)(FS_LPVOID clientData, FS_LPVOID hParent);
	FS_LPVOID(*FPDCreatePopupSubMenu)(FS_LPVOID clientData);
	FS_BOOLEAN(*FPDAppendMenuItem)(FS_LPVOID clientData, FS_LPVOID hMenu, FS_INT32 nIDItem, FS_LPCWSTR string);
	FS_BOOLEAN(*FPDAppendSubMenu)(FS_LPVOID clientData, FS_LPVOID hMenu, FS_LPVOID hSubMenu, FS_LPCWSTR string);
	FS_BOOLEAN(*FPDEnableMenuItem)(FS_LPVOID clientData, FS_LPVOID hMenu, FS_INT32 nIDItem, FS_BOOLEAN bEnabled);
	FS_BOOLEAN(*FPDCheckMenuItem)(FS_LPVOID clientData, FS_LPVOID hMenu, FS_INT32 nIDItem, FS_BOOLEAN bEnabled);
	FS_INT32(*FPDTrackPopupMenu)(FS_LPVOID clientData, FS_LPVOID hMenu, FS_INT32 x, FS_INT32 y, FS_LPVOID hParent);
	void(*FPDDestroyMenu)(FS_LPVOID clientData, FS_LPVOID hMenu);
	FS_LPCWSTR(*FPDGetNativeTrueTypeFont)(FS_LPVOID clientData, FS_INT32 nCharset);
	FS_BOOLEAN(*FPDFindNativeTrueTypeFont)(FS_LPVOID clientData, FS_INT32 nCharset,	FS_WideString wsFontFaceName);
	FPD_Font(*FPDAddNativeTrueTypeFontToPDF)(FS_LPVOID clientData, FPD_Document pDoc, FS_WideString wsFontFaceName,
		FS_BYTE nCharset,FS_BOOLEAN bBold, FS_BOOLEAN bItalic);
	FS_INT32(*FPDSetTimer)(FS_LPVOID clientData, FS_INT32 uElapse, FPDSystemTimerCallback lpTimerFunc);
	void(*FPDKillTimer)(FS_LPVOID clientData, FS_INT32 nID);
	FS_BOOLEAN(*FPDIsSHIFTKeyDown)(FS_LPVOID clientData);
	FS_BOOLEAN(*FPDIsCTRLKeyDown)(FS_LPVOID clientData);
	FS_BOOLEAN(*FPDIsALTKeyDown)(FS_LPVOID clientData);
	FS_BOOLEAN(*FPDIsINSERTKeyDown)(FS_LPVOID clientData);
	void(*FPDGetLocalTime)(FS_LPVOID clientData, FPD_SYSTEMTIME* localTime);
	FS_DWORD(*FPDGetMSTickCount)(FS_LPVOID clientData);
	FS_DWORD(*FPDGetMSDoubleClickTime)(FS_LPVOID clientData);
	FS_BOOLEAN(*FPDGetWIPPluginProvider)(FS_LPVOID clientData);
	FS_BOOLEAN(*FPDPasteRTF)(FS_LPVOID clientData);	
	FS_BOOLEAN(*FPDGetDefaultFontNameByCharset)(FS_LPVOID clientData,FS_WideString* csFontname, FS_INT32 nCharSet);	
	FS_BOOLEAN(*FPDGetFontCharset)(FS_LPVOID clientData, FS_WideString cwFontFaceName, FS_INT32* outcharset);	
	FS_BOOLEAN(*FPDAddFontToAnnotDict)(FS_LPVOID clientData, FPD_Object pAnnnotDict,FPD_Document pPDFDoc,
		FPD_Font pFont,	FS_ByteString sAlias, FS_ByteString sAPType);
	FPD_Font(*FPDGetAnnotDefaultFontName)(FS_LPVOID clientData, FPD_Document pDoc, FPD_Object pAnnotDict,FS_WideString* csFontName);
	void(*FPDGetFullName)(FS_LPVOID clientData, FS_ByteString* csFontName, FS_BOOLEAN bBold, FS_BOOLEAN bItalic);
	FS_BOOLEAN(*FPDGetDeviceCapsPixelsXY)(FS_LPVOID clientData, FS_FLOAT* x, FS_FLOAT* y);
	FS_WORD(*FPDGetCurrentAppLanguage)(FS_LPVOID clientData);
	FS_WORD(*FPDGetSystemDefaultLangIDF)(FS_LPVOID clientData);
	FS_BOOLEAN(*FPDGetFaceName)(FS_LPVOID clientData, FS_WideString* swScriptName, FS_BOOLEAN bRemoveSymbol);
	void(*FPDGetSystemDefaultFontName)(FS_LPVOID clientData, FS_WideString* wsFontName);
	void(*FPDGetFontFaceNameBoldItalic)(FS_LPVOID clientData, FS_WideString sFontName,
		FS_WideString* sFaceName, FS_BOOLEAN* bBold, FS_BOOLEAN* bItalic);
	void(*FPDGetSystemFont)(FS_LPVOID clientData, FS_WideStringArray* fonts);
	void(*FPDGetSystemSymbolFont)(FS_LPVOID clientData, FS_WideStringArray* pSymbolfontlist);
	FS_BOOLEAN(*FPDIsFontExistInSystem)(FS_LPVOID clientData, FS_WideString fontName, FS_INT32 nCharset);
	FS_DWORD(*FPDConvertToFWLVitrualKeyCode)(FS_LPVOID clientData, FS_DWORD nChar, FS_BOOLEAN bOnChar);
	void(*FPDSetCustomCursorHandler)(FS_LPVOID clientData, FPD_CustomCursorHandler handler);
}FPD_SystemHandlerCallbacksRec, *FPD_SystemHandlerCallbacks;
#endif
/* @OBJEND */

#ifndef FR_VTWORDPLACE
#define FR_VTWORDPLACE
typedef struct _t_FR_VTWordPlace* FR_VTWordPlace;
#endif

#ifndef FR_VTWORDRANGE
#define FR_VTWORDRANGE
typedef struct _t_FR_VTWordRange* FR_VTWordRange;
#endif

#ifndef FPD_VTWORDPLACE
#define FPD_VTWORDPLACE
typedef FR_VTWordPlace  FPD_VTWordPlace;
#endif

#ifndef FPD_VTWORDRANGE
#define FPD_VTWORDRANGE
typedef FR_VTWordRange  FPD_VTWordRange;
#endif 

#ifndef FPD_EDITFONTDATA
#define FPD_EDITFONTDATA
typedef struct _t_FPD_EDIT_FontData*  FPD_EDIT_FontData;
#endif 

/* @OBJSTART FPD_Edit_FontMap */
#ifndef FPD_EDITFONTMAP
#define FPD_EDITFONTMAP
typedef FR_Edit_FontMap  FPD_Edit_FontMap;
#endif 

#define FPD_ANSI_CHARSET        0
#define FPD_DEFAULT_CHARSET     1
#define FPD_SYMBOL_CHARSET      2
#define FPD_SHIFTJIS_CHARSET    128
#define FPD_HANGEUL_CHARSET     129
#define FPD_HANGUL_CHARSET      129
#define FPD_GB2312_CHARSET      134
#define FPD_CHINESEBIG5_CHARSET 136
#define FPD_OEM_CHARSET         255
#define FPD_JOHAB_CHARSET       130
#define FPD_HEBREW_CHARSET      177
#define FPD_ARABIC_CHARSET      178
#define FPD_GREEK_CHARSET       161
#define FPD_TURKISH_CHARSET     162
#define FPD_VIETNAMESE_CHARSET  163
#define FPD_THAI_CHARSET        222
#define FPD_EASTEUROPE_CHARSET  238
#define FPD_RUSSIAN_CHARSET     204
#define FPD_BALTIC_CHARSET      186

/* @OBJEND */

/* @OBJSTART FPD_EDITFONTArray */
#ifndef FPD_EDITFONTARRAY
#define	FPD_EDITFONTARRAY
typedef struct _t_FPD_EDIT_FONTArray* FPD_EDITFONTArray;
#endif
/* @OBJEND */

/* @OBJSTART FPD_PWLNotify */
#ifndef FPD_PWLNOTIFY
#define	FPD_PWLNOTIFY
typedef struct _t_FPD_PWLNotify* FPD_PWLNotify;
#endif

/* @CALLBACKGROUPSTART FPD_PWLNotifyCallbacks */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct _fpd_pwlnotify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_VariableTextProviderCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOLEAN(*FPDPWLWindowsRectChangeNotify)(FS_LPVOID clientData, const FS_FloatRect crWindows, FS_FloatRect* crClient);
}FPD_PWLNotifyCallbacksRec, *FPD_PWLNotifyCallbacks;
/* @CALLBACKGROUPEND */
/* @OBJEND */


#ifdef __cplusplus
};
#endif

#endif

/*@}*/

/*@}*/
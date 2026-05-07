/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fofd_docExpT.h
		
 - Types, macros, structures, etc.

*********************************************************************/

#ifndef FOFD_RENDEREXPT_H
#define FOFD_RENDEREXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FOFD_BASICEXPT_H
#include "./fofd_basicExpt.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* @DEFGROUPSTART OFD_COLOR_MODE */
/*@{*/
/** @brief Normal color mode. */
#define OFD_COLOR_MODE_NORMAL		0
/** @brief Gray color mode: map colors to background/foreground. */
#define OFD_COLOR_MODE_GRAY		1
/** @brief Two color mode: map white/black to background/foreground, other unchanged. Only be used to render text or path.*/
#define OFD_COLOR_MODE_TWOCOLOR	2
/** @brief Two color mode: map white/black to background/foreground, other unchanged. Only be used to render text or path.*/
#define OFD_COLOR_MODE_ANYCOLOR	3
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART OFD_RENDER_FLAGS */
/**
 * @name Codes for COFD_RenderOptions::m_Flags.
 */
/*@{*/
#define OFD_RENDER_PROGRESSIVE_RENDING	0x100
/** @brief Not Use ClearType-like anti-aliasing. */
#define OFD_RENDER_NOUSE_FXTEXT_CLEARTYPE	0x200
/** @brief Disable cache of the Resources */
#define OFD_RENDER_RESOURCE_NOCACHE		0x20
/** @brief Always output image substitution when printing. */
#define OFD_RENDER_PRINTSUBIMAGE		0x40
/** @brief Always display thumbnail image. */
#define OFD_RENDER_DISPLAYTHUMBNAIL		0x80
//no display background template page
#define OFD_RENDER_NODISPLAY_BACKGROUND_TEMPLATEPAGE 0x10
/** @brief Not use boundary of annot. */
#define OFD_RENDER_ANNOT_NOTUSEBOUND	0x400
/** @brief Not use cropbox of page. */
#define OFD_RENDER_PAGE_NOTUSECROPBOX	0x800
#define OFD_RENDER_PAGE_NOTUSEPAGEAREA	0x1000
/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART OFD_RENDER_LAYER_FLAGS */
/**
 * @name Codes for COFD_RenderOptions::m_LayerFlags.
 */
/*@{*/
#define OFD_RENDER_LAYER_NODISPLAY_FD_LAYER 0x1
#define OFD_RENDER_LAYER_NODISPLAY_FD_TEMPLATE 0x2
#define OFD_RENDER_LAYER_NODISPLAY_BY_LAYER 0x4
#define OFD_RENDER_LAYER_NODISPLAY_BY_TEMPLATE 0x8
#define OFD_RENDER_LAYER_NODISPLAY_BD_LAYER 0x10
#define OFD_RENDER_LAYER_NODISPLAY_BD_TEMPLATE 0x20
/*@}*/

/* @DEFGROUPEND */

/* @OBJSTART FOFD_RenderOptions */
#ifndef FOFD_RENDEROPTIONS
#define	FOFD_RENDEROPTIONS

	/**
	*	
	*/
	typedef struct _t_FOFD_RenderOptions* FOFD_RenderOptions;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_ProgressiveRenderer */
#ifndef FOFD_PROGRESSIVERENDERER
#define	FOFD_PROGRESSIVERENDERER

	/**
	*	
	*/
	typedef struct _t_FOFD_ProgressiveRenderer* FOFD_ProgressiveRenderer;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_RenderContext */
#ifndef FOFD_RENDERCONTEXT
#define	FOFD_RENDERCONTEXT

	/**
	*	
	*/
	typedef struct _t_FOFD_RenderContext* FOFD_RenderContext;
	
#endif

/* @OBJEND */

/* @ENUMSTART */
enum OFD_RENDER_FILLRULE
{
	OFD_RENDER_FILLRULE_Winding = 0,	//Nonzero
	OFD_RENDER_FILLRULE_Alternate,		//Even-odd
};
/* @ENUMEND */

/* @ENUMSTART */
enum OFD_RENDER_RENDERSTATUS
{
	OFD_RENDER_RENDERSTATUS_Begin			,   //begin render
	OFD_RENDER_RENDERSTATUS_Continued		,	//Continued
	OFD_RENDER_RENDERSTATUS_Done			,	//done
	OFD_RENDER_RENDERSTATUS_Failed			,	//error
};
/* @ENUMEND */

/* @OBJSTART FOFD_RenderDevice */
#ifndef FOFD_RENDERDEVICE
#define	FOFD_RENDERDEVICE

	/**
	*	
	*/
	typedef struct _t_FOFD_RenderDevice* FOFD_RenderDevice;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_DriverDevice */
#ifndef FOFD_DRIVERDEVICE
#define	FOFD_DRIVERDEVICE

	/**
	*	
	*/
	typedef struct _t_FOFD_DriverDevice* FOFD_DriverDevice;
	
#endif

/* @OBJEND */
	
#ifdef __cplusplus
};
#endif

#endif
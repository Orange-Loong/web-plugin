/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_pageobjExpT.h
		
 - Types, macros, structures, etc. required to use the FPDPageObj HFT.

*********************************************************************/

/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/

/**
 * @addtogroup FPDPAGEOBJ
 * @{
 */

/**
 * @file
 * @brief FPD Page Object
 */

#ifndef FPD_PAGEOBJEXPT_H
#define FPD_PAGEOBJEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/* @OBJSTART FPD_Path */
#ifndef FPD_PATH
#define FPD_PATH
/** @brief FPD path. 
 * A <a>FPD_Path</a> is a data container for a <a>FPD_PathObject</a> which is a graphic object representing a path in a page description. 
 * See <a>FPDPathNew</a>, <a>FPDPathDestroy</a>.
 */
typedef struct _t_FPD_Path* FPD_Path;
#endif
/* @OBJEND */

/* @OBJSTART FPD_PathData */
#ifndef FPD_PATHDATA
#define FPD_PATHDATA
/** @brief FPD path.
 * A <a>FPD_Path</a> is a data container for a <a>FPD_PathObject</a> which is a graphic object representing a path in a page description.
 * See <a>FPDPathDataNew</a>, <a>FPDPathDataDestroty</a>.
 */
typedef struct _t_FPD_PathData* FPD_PathData;
#endif
/* @OBJEND */

/* @OBJSTART FPD_PathInternal */
#ifndef FPD_PATHINTERNAL
#define FPD_PATHINTERNAL
/** @brief the agent object of FPD path.
 */
typedef struct _t_FPD_Path* FPD_PathInternal;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ClipPath */
#ifndef FPD_CLIPPATH
#define FPD_CLIPPATH
/** @brief A clip path. See <a>FPDClipPathNew</a>, <a>FPDClipPathDestroy</a>.
 */
typedef struct _t_FPD_ClipPath* FPD_ClipPath;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ClipPathInternal */
#ifndef FPD_CLIPPATHINTERNAL
#define FPD_CLIPPATHINTERNAL
/** @brief A clip path. See <a>FPDClipPathInternalNew</a>, <a>FPDClipPathInternalDestroy</a>.
 */
typedef struct _t_FPD_ClipPathInternal* FPD_ClipPathInternal;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ColorState */
#ifndef FPD_COLORSTATE
#define FPD_COLORSTATE
/** @brief The color state for rendering. See <a>FPDColorStateNew</a>, <a>FPDColorStateDestroy</a>.
 */
typedef struct _t_FPD_ColorState* FPD_ColorState;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ColorStateInternal */
#ifndef FPD_COLORSTATEINTERNAL
#define FPD_COLORSTATEINTERNAL
/** @brief The color state for rendering. See <a>FPDColorStateInternalNew</a>, <a>FPDColorStateInternalDestroy</a>.
 */
typedef struct _t_FPD_ColorStateInternal* FPD_ColorStateInternal;
#endif
/* @OBJEND */

/* @OBJSTART FPD_GraphState */
#ifndef FPD_GRAPHSTATE
#define FPD_GRAPHSTATE
/**
 * @brief The graph state for graphic rendering.
 */
typedef struct _t_FPD_GraphState* FPD_GraphState;

/* @ENUMSTART */
/** @brief  Line cap style enumeration.
 */
enum FPD_LineCap
{
	FPD_LineCapButt=0, /**< Butt cap. The stroke is squared off at the endpoint of the path. */
	FPD_LineCapRound=1, /**< Round cap. A semicircular arc with a diameter equal to the line width is drawn around the endpoint and filled in. */ 
	FPD_LineCapSquare=2 /**< Projecting square cap. The stroke continues beyond the endpoint of the path for a distance equal to half the line width and is squared off. */	
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief Line join style enumeration.
 */

enum FPD_LineJoin
{
	FPD_LineJoinMiter=0, /**< Miter join. The outer edges of the strokes for the two segments are extended until they meet at an angle, as in a picture frame. */
	FPD_LineJoinRound=1,/**< Round join. An arc of a circle with a diameter equal to the line width is drawn around the point where the two segments meet, connecting the outer edges of the strokes for the two segments. */
	FPD_LineJoinBevel=2 /**< Bevel join. The two segments are finished with butt caps and the resulting notch beyond the ends of the segments is filled with a triangle. */

};
/* @ENUMEND */

#endif
/* @OBJEND */

/* @OBJSTART FPD_TextState */
#ifndef FPD_TEXTSTATE
#define FPD_TEXTSTATE
/** @brief The text state for page rendering. See <a>FPDTextStateNew</a>, <a>FPDTextStateDestroy</a>.
 */
typedef struct _t_FPD_TextState* FPD_TextState;
#endif
/* @OBJEND */

/* @OBJSTART FPD_GeneralState */
#ifndef FPD_GENERALSTATE
#define FPD_GENERALSTATE
/** @brief The general state for page rendering. See <a>FPDGeneralStateNew</a>, <a>FPDGeneralStateDestroy</a>.
 */
typedef struct _t_FPD_GeneralState* FPD_GeneralState;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ContentMarkItem */
#ifndef FPD_CONTENTMARKITEM
#define FPD_CONTENTMARKITEM
/** @brief The content mark item for tagged pdf. See <a>FPDContentMarkItemNew</a>, <a>FPDContentMarkItemDestroy</a>.
 */
typedef struct _t_FPD_ContentMarkItem* FPD_ContentMarkItem;
#endif

/* @ENUMSTART */
/** @brief Parameter type enumeration of content mark item. See <a>FPDContentMarkItemGetParamType</a>, <a>FPDContentMarkItemSetParam</a>.
 */
enum FPD_MarkItemParamType
{
	NoneItem,			/**< None parameters. */
	PropertiesDict,		/**< The dictionary defined by named resource in the Properties sub-dictionary of the current resource dictionary. */
	PropertiesArray,    /**< The array defined by named resource in the Properties sub-dictionary*/
	DirectDict,			/**< The dictionary may be written inline in the content stream as a direct object. */
	DirectArray,       /**< The array may be written inline in the content stream as a direct object. */
	MCID				/**< The dictionary contains an MCID entry, which is an integer marked-content identifier that uniquely identifies the marked-content sequence within its content stream. */
};
/* @ENUMEND */
/* @OBJEND */

/* @OBJSTART FPD_ContentMarkItemRef */
#ifndef FPD_CONTENTMARKITEMREF
#define FPD_CONTENTMARKITEMREF
/** @brief The accessor of reference counted FPD_ContentMarkItem object.
 */
typedef struct _t_FPD_ContentMarkItemRef* FPD_ContentMarkItemRef;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ContentMark */
#ifndef FPD_CONTENTMARK
#define FPD_CONTENTMARK
/** @brief The content marks for tagged pdf. See <a>FPDContentMarkNew</a>, <a>FPDContentMarkDestroy</a>.
 */
typedef struct _t_FPD_ContentMark* FPD_ContentMark;
#endif
/* @OBJEND */

/* @OBJSTART FPD_PageObject */
#ifndef FPD_PAGEOBJECT
#define FPD_PAGEOBJECT
/** 
 * @brief A <a>FPD_PageObject</a> is the abstract superclass of page objects. 
 *
 * You can find the type of any object 
 * with the <a>FPDPageObjectGetType</a>() method.
 *
 */
typedef struct _t_FPD_PageObject* FPD_PageObject;
#endif

/* @DEFGROUPSTART FPDPathPointFlags */

/**
 * @name Point flags used in FPD_Path.
 */
/*@{*/

/**
 * @brief Specifies that the figure is automatically closed after the <a>FPDPT_LINETO</a> or <a>FPDPT_BEZIERTO</a>
 * for this point is done. A line is drawn from this point to the most recent #FPDPT_MOVETO point.
 */
#define FPDPT_CLOSEFIGURE		0x01
/** @brief Specifies that a line is to be drawn from the current position to this point, which then becomes the new current position. */
#define FPDPT_LINETO				0x02
/** @brief Specifies that this point is a control point or ending point for a Bézier spline. */
#define FPDPT_BEZIERTO			0x04
/** @brief Specifies that this point starts a figure. This point becomes the new current position. */
#define FPDPT_MOVETO				0x06
/** @brief Denotes point type mask. Point types are: #FPDPT_MOVETO/#FPDPT_LINETO/#FPDPT_BEZIERTO. */
#define FPDPT_TYPE				0x06

/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDPageObjectTypes */
/**
* @name The types of page objects.
*/
/*@{*/

/** @brief text object. */
#define FPD_PAGEOBJ_TEXT		1
/** @brief path object. */
#define FPD_PAGEOBJ_PATH		2
/** @brief image object. */
#define FPD_PAGEOBJ_IMAGE		3
/** @brief shading object. */
#define FPD_PAGEOBJ_SHADING		4
/** @brief form object. */
#define FPD_PAGEOBJ_FORM		5
/** @brief inline image object. Inline image section. FOR EMBEDDED SYSTEM ONLY*/
#define FPD_PAGEOBJ_INLINES		6
/** @brief page empty*/
#define FPD_PAGE_EMPTY		    7

/*@}*/
/* @DEFGROUPEND */

/* @STRUCTSTART FPD_TextObjectItem */
/** @brief A data structure for text object item. */
struct FPD_TextObjectItem
{
	/** The character code. -1 (0xffffffff) for spacing. */
	FS_DWORD			m_CharCode;
	/** X origin in text space, or the spacing. */
	FS_FLOAT			m_OriginX;
	/** Y origin in text space. */
	FS_FLOAT			m_OriginY;
};
/* @STRUCTEND */


/* @OBJEND */

/* @OBJSTART FPD_TextObject */
/** @brief A FPD_TextObject is a graphic object (a subclass of FPD_PageObject) representing one or more character 
 * strings on a page. 
 *
 * A text object consists of one or more character strings that identify sequences of 
 * glyphs to be painted. Like a path, text can be stroked, filled, or used as a clipping boundary.
 *
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_PathObject */
/** 
 * @brief A FPD_PathObject is a graphic object (a subclass of FPD_PageObject) representing a path in a page description. 
 *
 * A path object is an arbitrary shape made up of straight lines, rectangles, and cubic Bézier curves. A path may intersect
 * itself and may have disconnected sections  and holes. A path object ends with one or more painting operators that 
 * specify whether the path is stroked, filled, used as a clipping boundary, or some combination of these operations.
 *
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_ImageObject */
/** 
 * @brief A FPD_ImageObject is a sampled image or image mask, and corresponds to a PDF Image resource
 * (see <Italic>Stencil Masking in Section 4.8, Images, in the PDF Reference</Italic>).
 *
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_ShadingObject */
/** 
 * @brief A FPD_PathObject is a graphic object (a subclass of FPD_PageObject) representing a smooth shading in a page 
 * description.
 *
 * FPD_PathObject describes geometric shapes whose color are an arbitrary function of position within the shape. 
 * (A shading can also be treated as a color when painting other graphics objects; it is not considered to be a separate 
 * graphics object in that case.)
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_FormObject */
/** 
 * @brief This object corresponds to a PDF form XObject (<Italic>see Section 4.9, Form XObjects, in the PDF Reference</Italic>).
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_InlineImages */
/** 
 * @brief A FPD_InlineImages is an image whose data is stored in the page description's contents stream instead of being 
 * stored as an image resource (see FPD_ImageObject). FPD_InlineImages is a subclass of FPD_PageObject and corresponds to
 * the PDF inline image operator (<Italic>see Section 4.8.6, In-Line Images, in the PDF Reference</Italic>).<br><br>
 *
 * Inline images generally are used for images with small amounts of data (up to several kilobytes), while image resources
 * are used for large images. 
 *
 */
/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif

/** @} */

/*@}*/
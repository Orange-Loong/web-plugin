/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_pageExpT.h
		
 - Types, macros, structures, etc. required to use the FPDPage HFT.

*********************************************************************/

/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/

/**
 * @addtogroup FPDPAGE
 * @{
 */

/**
 * @file
 * @brief FPD page and form definitions. 
 */

#ifndef FPD_PAGEEXPT_H
#define FPD_PAGEEXPT_H

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

#ifndef FPD_RESOURCEEXPT_H
#include "fpd_resourceExpT.h"
#endif

#ifndef FPD_PAGEOBJEXPT_H
#include "fpd_pageobjExpT.h"
#endif

#ifndef FR_SYSEXPT_H
#include "../frd/fr_sysExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/* @OBJSTART FPD_Page */
#ifndef FPD_PAGE
#define	FPD_PAGE
/** 
 *@brief  A <a>FPD_Page</a> is a page in a document, corresponding to the PDF Page object
 * (see Page Objects in Section 3.6.2, Page Tree, in the PDF Reference).
 *
 * Among other associated objects, a page contains:
 * <ul>
 * <li>A series of objects representing the objects drawn on the page.</li>
 * <li>A list of resources used in drawing the page.</li>
 * <li>Annotations.</li>
 * <li>An optional thumbnail image of the page.</li>
 * <li>Beads used in any articles that occur on the page.</li>
 * </ul>
 * See <a>FPDPageNew</a>, <a>FPDPageDestroy</a>.
*/
typedef struct _t_FPD_Page* FPD_Page;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Form */
#ifndef FPD_FORM
#define	FPD_FORM
/** @brief A <a>FPD_Form</a> is a self-contained set of graphics operators that is used when a particular graphic 
* is drawn more than once in a document. It corresponds to to a PDF XObject <Italic>(see Section 4.9, Form XObjects, 
* in the PDF Reference)</Italic>. See <a>FPDFormNew</a>, <a>FPDFormDestroy</a>.
*/
typedef struct _t_FPD_Form* FPD_Form;
#endif
/* @OBJEND */

/* @OBJSTART FPD_GraphicsObjects */
#ifndef FPD_GRAPHICSOBJECTS
#define	FPD_GRAPHICSOBJECTS
/** @brief A <a>FPD_GraphicsObjects</a> is a self-contained set of graphics operators that is used when a particular graphic
* is drawn more than once in a document.
*/
typedef struct _t_FPD_GraphicsObjects* FPD_GraphicsObjects;
#endif

/* @DEFGROUPSTART FPDGraphicsObjectsTypes */
/**
* @name The types of Graphics Object.
*/
/*@{*/

/** @brief Indicate PDF Page. */
#define FPDPAGEOBJECTS_PAGE		1
/** @brief Indicate Form XObject. */
#define FPDPAGEOBJECTS_FORMX	2

/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_ParseOptions */
#ifndef FPD_PARSEOPTIONS
#define	FPD_PARSEOPTIONS
/** @brief The page parsing options. */
typedef struct _t_FPD_ParseOptions* FPD_ParseOptions;
#endif
/* @OBJEND */

/* @OBJSTART FPD_AllStates */	
#ifndef FPD_ALLSTATES 
#define FPD_ALLSTATES
/** @brief No document exits. */
	typedef struct _t_FPD_AllStates* FPD_AllStates;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ContentGenerator */	
#ifndef FPD_CONTENTGENERATOR 
#define FPD_CONTENTGENERATOR
/** @brief PDF Page or Form content generator. */
	typedef struct _t_FPD_ContentGenerator* FPD_ContentGenerator;
#endif

/* @ENUMSTART */
/** 
  * @brief The status of generating PDF page or Form content progressively.
  */
enum FPD_ProgressiveStatus
{
	FPD_Ready,              /**< Ready. */
	FPD_ToBeContinued,		/**< To be continued. */
	FPD_Found,				/**< Found. */
	FPD_NotFound,           /**< Not found. */
	FPD_Failed,				/**< Failed. */
	FPD_Done                /**< Done. */
};
/* @ENUMEND */

/* @OBJEND */

/* @OBJSTART FPD_ColorSeparator */
#ifndef FPD_COLORSEPARATOR
#define	FPD_COLORSEPARATOR
/**
 *@brief  A <a>FPD_ColorSeparator</a> is used to export PS or EPS format.
 * See <a>FPDColorSeparatorNew</a>, <a>FPDColorSeparatorDestroy</a>.
*/
typedef struct _t_FPD_ColorSeparator* FPD_ColorSeparator;
#endif
/* @OBJEND */


/* @COMMONSTART */
/* @DEFGROUPSTART FPDTransparencyAttrFlags */

/**
 * @name Transparency attribute flags for a page object group (form or page).
 */
/*@{*/

/** @brief Whether a transparency group is present. */
#define FPD_TRANS_GROUP			0x0100
/** @brief Whether a transparency group is isolated. For isolated groups, a separate level device is required. */
#define FPD_TRANS_ISOLATED		0x0200
/** @brief Whether a transparency group is knockout. For non-knockout groups, composition is required for all objects inside. */
#define FPD_TRANS_KNOCKOUT		0x0400

/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDContentParsingState */

/**
 * @name The flags for PDF content-parsing state.
 */
/*@{*/

/** @brief The page is not parsed. */
#define FPD_CONTENT_NOT_PARSED	0
/** @brief The page is parsing. */
#define FPD_CONTENT_PARSING		1
/** @brief The page is parsed. */
#define FPD_CONTENT_PARSED		2

/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDOSTextExtractingFlags */

/**
 * @name The flags for text extracting.
 */
/*@{*/
	
/** @brief Auto rotating. */
#define FPD_2TXT_AUTO_ROTATE		1
/** @brief Auto width. */
#define FPD_2TXT_AUTO_WIDTH			2
/** @brief Keep column. */
#define FPD_2TXT_KEEP_COLUMN		4
/** @brief Whether to use OCR. */
#define FPD_2TXT_USE_OCR			8
/** @brief Whether to include invisible texts. */
#define FPD_2TXT_INCLUDE_INVISIBLE	16

/*@}*/

/* @DEFGROUPEND */

/* @COMMONEND */


/* @OBJSTART FR_Edit_FontMap */
#ifndef FR_EDIT_FONTMAP
#define FR_EDIT_FONTMAP
/**
 * @brief
 */
typedef struct _t_FR_Edit_FontMap* FR_Edit_FontMap;
#endif


/* @OBJSTART FR_VTSecProps */
#ifndef FR_VTSECPROPS
#define FR_VTSECPROPS
/**
 * @brief
 */
typedef struct _t_FR_VTSecProps* FR_VTSecProps;
#endif
/* @OBJEND */


/* @OBJSTART FR_VTWordProps */
#ifndef FR_VTWORDPROPS
#define FR_VTWORDPROPS
/**
 * @brief
 */
typedef struct _t_FR_VTWordProps* FR_VTWordProps;
#endif
/* @OBJEND */

/* @OBJSTART FPD_RenderOptions */
#ifndef FPD_RENDEROPTIONS
#define FPD_RENDEROPTIONS
typedef struct _t_FPD_RenderOptions* FPD_RenderOptions;
#endif

/** @brief Normal color mode. */
#define FPD_RENDERCOLOR_NORMAL		0
/** @brief Gray color mode: map colors to background/foreground. */
#define FPD_RENDERCOLOR_GRAY		1
/** @brief Two color mode: map white/black/grayscale to background/foreground, other unchanged. */
#define FPD_RENDERCOLOR_TWOCOLOR	2
/** @brief Output alpha only, ignore color. */
#define FPD_RENDERCOLOR_ALPHA		3
/** @brief Custom color mode. map colors to foreground. */
#define FPD_RENDERCOLOR_CUSTOM		4

/* @OBJEND */


/* @OBJSTART FPD_RenderDevice */
#ifndef FPD_RENDERDEVICE
#define FPD_RENDERDEVICE
typedef struct _t_FPD_RenderDevice* FPD_RenderDevice;
#endif
/* @OBJEND */

/* @OBJSTART FPD_WinBitmapDevice */
#ifndef FPD_WINBITMAPDEVICE
#define FPD_WINBITMAPDEVICE
typedef struct _t_FPD_WinBitmapDevice* FPD_WinBitmapDevice;
#endif
/* @OBJEND */

/* @OBJSTART FPD_PDFObjectExtracter */
#ifndef FPD_PDFOBJECTEXTRACTER
#define FPD_PDFOBJECTEXTRACTER
/**
 * @brief The <a>FPD_PDFObjectExtracter</a> object is used extractor some page object and product a new document.
 */
typedef struct _t_FPD_PDFObjectExtracter* FPD_PDFObjectExtracter;
#endif
/* @OBJEND */



#ifdef __cplusplus
};
#endif

#endif

/** @} */


/*@}*/
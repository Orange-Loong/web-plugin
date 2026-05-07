/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_epubExpT.h
		
 - Types, macros, structures, etc. required to use the FPDLayer HFT.

*********************************************************************/
/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/


/**
  * @addtogroup FPDEPUB
  * @{
  */


/**
* @file
* @brief data types for PDEPUB layer
*/

#ifndef FPD_EPUBEXPT_H
#define FPD_EPUBEXPT_H

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
extern "C" {
#endif

#ifndef	FPD_FDE_DOCUMENT
#define	FPD_FDE_DOCUMENT

	typedef struct _t_FPD_FDE_Document*			FPD_FDE_Document;

	typedef struct _t_FPD_FDE_EPUBParseParams*	FPD_FDE_EPUBParseParams;

	typedef struct _t_FPD_FDE_EPUBStdPackage*	FPD_FDE_EPUBStdPackage;
#endif

#ifndef	FPD_FDE_PAGE
#define	FPD_FDE_PAGE

	typedef struct _t_FPD_FDE_Page*				FPD_FDE_Page;
#endif

#ifndef	FPD_FDE_HSECTION
#define	FPD_FDE_HSECTION

	typedef struct _t_FPD_FDE_HSection*			FPD_FDE_HSection;
#endif

#ifndef	FPD_FDE_HBOOKMARK
#define	FPD_FDE_HBOOKMARK

	typedef struct _t_FPD_FDE_HBookmark*		FPD_FDE_HBookmark;
#endif

#ifndef	FPD_FDE_BOOKMARK
#define	FPD_FDE_BOOKMARK

	typedef struct _t_FPD_FDE_Bookmark*			FPD_FDE_Bookmark;
#endif

#ifndef	FPD_FDE_TEXTSELECTION
#define	FPD_FDE_TEXTSELECTION

	typedef struct _t_FPD_FDE_TextSelection*	FPD_FDE_TextSelection;
#endif

#ifndef	FPD_FDE_TEXTSEARCH
#define	FPD_FDE_TEXTSEARCH

	typedef struct _t_FPD_FDE_TextSearch*		FPD_FDE_TextSearch;

	//macros for search modes
#define FPD_FDE_TEXTSEARCH_MatchCase		0x00000001//whether to match the character case(upper/lower)
#define FPD_FDE_TEXTSEARCH_MatchWholdWord	0x00000002//whether to match the whole word for the search pattern
#define FPD_FDE_TEXTSEARCH_Consecutive		0x00000004//whether to do consecutive searching
#endif

#ifndef FPD_FDE_RENDERCONTEXT
#define FPD_FDE_RENDERCONTEXT

	typedef struct _t_FPD_FDE_RenderContext*	FPD_FDE_RenderContext;
#endif

#ifndef FPD_FDE_RENDERDEVICE
#define FPD_FDE_RENDERDEVICE

	typedef struct _t_FPD_FDE_RenderDevice*		FPD_FDE_RenderDevice;
#endif

#ifndef FPD_FDE_PARSER
#define FPD_FDE_PARSER

	typedef struct _t_FPD_FDE_Parser*			FPD_FDE_Parser;
#endif

#ifndef FPD_FDE_VIEW
#define FPD_FDE_VIEW

	typedef struct _t_FPD_FDE_View*				FPD_FDE_View;
#endif

#ifndef FPD_FDE_MGR
#define FPD_FDE_MGR

	typedef struct _t_FPD_FDE_Mgr*				FPD_FDE_Mgr;
#endif


	enum FPD_FDE_DESTTYPE
	{
		FPD_FDE_DESTTYPE_FitPage		=  0,	//parameters: none. Fit the whole page
		FPD_FDE_DESTTYPE_FitPageH			,	//parameters: top. Fit the page horizontally
		FPD_FDE_DESTTYPE_FitPageV			,	//parameters: left. Fit the page vertically
		FPD_FDE_DESTTYPE_FitZoom			,	//parameters: left, top, zoom. Fit the page both horizontally and vertically with a special zoom
		FPD_FDE_DESTTYPE_FitRect			,	//parameters: left, top, right, bottom. Fit a page area
		FPD_FDE_DESTTYPE_FitBBox			,	//parameters: none. Fit the bounding box of page
		FPD_FDE_DESTTYPE_FitBBoxH			,	//parameters: top. Fit the bounding box of page and align at a top position
		FPD_FDE_DESTTYPE_FitBBoxV			,	//parameters: left. Fit the bounding box of page and align at a left position
	};

	enum FPD_FDE_SEARCHRESULT
	{
		FPD_FDE_SEARCHRESULT_Found = 0,
		FPD_FDE_SEARCHRESULT_NotFound,
		FPD_FDE_SEARCHRESULT_NextPage//need next page for cross-page-matched words
	};



#ifndef FPD_FDE_TXTLINEALIGNMENT
#define FPD_FDE_TXTLINEALIGNMENT

#define FPD_FDE_TXTLINEALIGNMENT_Left				0			//left or near alignment
#define FPD_FDE_TXTLINEALIGNMENT_Center				1			//center alignment
#define FPD_FDE_TXTLINEALIGNMENT_Right				2			//right or far alignment
#define FPD_FDE_TXTLINEALIGNMENT_Justified			(1 << 2)	//justifying alignment
#define FPD_FDE_TXTLINEALIGNMENT_Distributed			(2 << 2)	//distributed alignment
#define FPD_FDE_TXTLINEALIGNMENT_JustifiedLeft		(FPD_FDE_TXTLINEALIGNMENT_Left | FPD_FDE_TXTLINEALIGNMENT_Justified)
#define FPD_FDE_TXTLINEALIGNMENT_JustifiedCenter		(FPD_FDE_TXTLINEALIGNMENT_Center | FPD_FDE_TXTLINEALIGNMENT_Justified)
#define FPD_FDE_TXTLINEALIGNMENT_JustifiedRight		(FPD_FDE_TXTLINEALIGNMENT_Right | FPD_FDE_TXTLINEALIGNMENT_Justified)
#define FPD_FDE_TXTLINEALIGNMENT_DistributedLeft		(FPD_FDE_TXTLINEALIGNMENT_Left | FPD_FDE_TXTLINEALIGNMENT_Distributed)
#define FPD_FDE_TXTLINEALIGNMENT_DistributedCenter	(FPD_FDE_TXTLINEALIGNMENT_Center | FPD_FDE_TXTLINEALIGNMENT_Distributed)
#define FPD_FDE_TXTLINEALIGNMENT_DistributedRight	(FPD_FDE_TXTLINEALIGNMENT_Right | FPD_FDE_TXTLINEALIGNMENT_Distributed)

#endif


#ifdef __cplusplus
};
#endif

#endif
/*@}*/ 


/*@}*/
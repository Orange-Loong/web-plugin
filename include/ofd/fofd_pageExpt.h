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

#ifndef FOFD_PAGEEXPT_H
#define FOFD_PAGEEXPT_H

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
#include "./fofd_basicExpT.h"
#endif

#ifndef FOFD_DOCEXPT_H
#include "fofd_docExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* @OBJSTART FOFD_PAGE */
#ifndef FOFD_PAGE
#define	FOFD_PAGE

	/**
	* @brief The underlying OFD representation of a page.
	* 
	* you can use this object to read data from the page.
	*/
	typedef struct _t_FOFD_Page* FOFD_Page;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_WRITEPAGE */
#ifndef FOFD_WRITEPAGE
#define	FOFD_WRITEPAGE

	/**
	* @brief The underlying OFD representation of a page.
	*
	* you can use this object to write data to the page.
	*/
	typedef struct _t_FOFD_WritePage* FOFD_WritePage;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_ANNOT */
#ifndef FOFD_ANNOT
#define	FOFD_ANNOT

	/**
	*
	*/
	typedef struct _t_FOFD_Annot* FOFD_Annot;
	
#endif

/* @OBJEND */

/* @ENUMSTART*/
enum OFD_PAGEDEST_TYPE
{
	OFD_PAGEDEST_TYPE_Unknown = 0,
	OFD_PAGEDEST_TYPE_XYZ,		//left, top, zoom
	OFD_PAGEDEST_TYPE_Fit,		//fit page
	OFD_PAGEDEST_TYPE_FitH,		//fit width, top
	OFD_PAGEDEST_TYPE_FitV,		//fit height, left
	OFD_PAGEDEST_TYPE_FitR,		//fit rectangle, left, top, right, bottom
};
/*ENUMEND*/

/* @OBJSTART FOFD_DEST */
#ifndef FOFD_DEST
#define	FOFD_DEST

	/**
	*
	*/
	typedef struct _t_FOFD_Dest* FOFD_Dest;
	
#endif

/* @OBJEND */
	
#ifdef __cplusplus
};
#endif

#endif
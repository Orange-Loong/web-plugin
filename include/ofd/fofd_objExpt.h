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

#ifndef FOFD_OBJEXPT_H
#define FOFD_OBJEXPT_H

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

/* @OBJSTART FOFD_OBJECT */
#ifndef FOFD_CONTENTOBJECT
#define	FOFD_CONTENTOBJECT

	/**
	* @brief The underlying OFD representation of a object.
	* 
	* you can use this object to read data from the object.
	*/
	typedef struct _t_FOFD_ContentObject* FOFD_ContentObject;
	
#endif

/* @OBJEND */

/* @OBJSTART FDF_Document */
#ifndef FOFD_WRITECONTENTOBJECT
#define	FOFD_WRITECONTENTOBJECT

	/**
	* @brief The underlying OFD representation of a object.
	*
	* you can use this object to write data to the object.
	*/
	typedef struct _t_FOFD_WriteContentObject* FOFD_WriteContentObject;
	
#endif

/* @OBJEND */

	
/* @OBJSTART FOFD_Path */
#ifndef FOFD_PATH
#define	FOFD_PATH

	/**
	*
	*/
	typedef struct _t_FOFD_Path* FOFD_Path;
	
#endif

/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
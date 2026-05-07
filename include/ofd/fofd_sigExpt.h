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

#ifndef FOFD_SIGNATUREEXPT_H
#define FOFD_SIGNATUREEXPT_H

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

/* @OBJSTART FOFD_SIGNATURE */
#ifndef FOFD_SIGNATURE
#define	FOFD_SIGNATURE

	/**
	* @brief The underlying OFD representation of a Signature.
	* 
	* you can use this object to read data from the Signature.
	*/
	typedef struct _t_FOFD_Signature* FOFD_Signature;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_WRITESIGNATURE */
#ifndef FOFD_WRITESIGNATURE
#define	FOFD_WRITESIGNATURE

	/**
	* @brief The underlying OFD representation of a Signature.
	*
	* you can use this object to write data to the Signature.
	*/
	typedef struct _t_FOFD_WriteSignature* FOFD_WriteSignature;
	
#endif

/* @OBJEND */

	
#ifdef __cplusplus
};
#endif

#endif
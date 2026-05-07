/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.

 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.

 ---------------------------------------------------------------------

fpd_convertExpT.h

 - Types, macros, structures, etc. required to use the FPDLayer HFT.

*********************************************************************/

#ifndef FPD_JSEXPT_H
#define FPD_JSEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif


/* @OBJSTART FPD_JSEngine */
#ifndef FPD_JSENGINE
#define	FPD_JSENGINE
/**
* @brief
*/
	typedef struct _t_FPD_JSEngine* FPD_JSEngine;
#endif	

	enum FPD_JSActionReturn
	{
		FPD_JSACTION_DOCDESTROY = -1,
		FPD_JSACTION_FAILED = 0,
		FPD_JSACTION_SUCCESS = 1
	};	

	enum  FPD_JSEnv
	{
		FPD_JSOnConsole = 0,
		FPD_JSOnExternal
	};
/* @OBJEND */

/* @OBJSTART FPD_JSAppProvider */
#ifndef FPD_JSAPPPROVIDER
#define	FPD_JSAPPPROVIDER
/**
* @brief
*/
	typedef struct _t_FPD_JSAppProvider* FPD_JSAppProvider;
#endif	

	enum FPD_JSNOTIFY_TRIGGER_TYPE
	{
		FPD_JSNOTIFY_TRIGGER_FORMAT,
		FPD_JSNOTIFY_TRIGGER_CALCULATION,
		FPD_JSNOTIFY_TRIGGER_JSFIELD_SETVALUE,
		FPD_JSNOTIFY_TRIGGER_JSFIELD_SETITEMS
	};

	enum FPD_JSFileFormatType
	{
		// nFormat 0 - FDF 1 - XML 2 - TXT 3 - XFDF 4 - XDP 5 - HTML 6 - PDF
		FPD_JSGW_FILEFORMAT_FDF = 0,
		FPD_JSGW_FILEFORMAT_XML,
		FPD_JSGW_FILEFORMAT_TXT,
		FPD_JSGW_FILEFORMAT_XFDF,
		FPD_JSGW_FILEFORMAT_XDP,
		FPD_JSGW_FILEFORMAT_HTML,
		FPD_JSGW_FILEFORMAT_PDF,
		FPD_JSGW_FILEFORMAT_XFD
	};
/* @OBJEND */

/* @OBJSTART FPD_JSDocumentProvider */
#ifndef FPD_JSDOCUMENTPROVIDER
#define	FPD_JSDOCUMENTPROVIDER
/**
* @brief
*/
	typedef struct _t_FPD_JSDocumentProvider* FPD_JSDocumentProvider;
#endif	
/* @OBJEND */

/* @OBJSTART FPD_JSRuntime */
#ifndef FPD_JSRUNTIME
#define	FPD_JSRUNTIME
/**
* @brief
*/
	typedef struct _t_FPD_JSRuntime* FPD_JSRuntime;
#endif	
/* @OBJEND */

/* @OBJSTART FPD_JSContext */
#ifndef FPD_JSCONTEXT
#define	FPD_JSCONTEXT
/**
* @brief
*/
	typedef struct _t_FPD_JSContext* FPD_JSContext;
#endif	

enum FPD_JSContext_Level
{
	FPD_JSCPDFPlugin_Level,
	FPD_JSFolder_Level,
	FPD_JSDocument_Level
};
/* @OBJEND */

/* @OBJSTART FPD_JSFieldAction */
#ifndef FPD_JSFIELDACTION
#define	FPD_JSFIELDACTION
/**
* @brief
*/
typedef struct _t_FPD_JSFieldAction* FPD_JSFieldAction;
#endif	
/* @OBJEND */

/* @OBJSTART FPD_JSFormProvider */
#ifndef FPD_JSFORMPROVIDER
#define	FPD_JSFORMPROVIDER
/**
* @brief
*/
typedef struct _t_FPD_JSFormProvider* FPD_JSFormProvider;
#endif
/* @OBJEND */


#ifdef __cplusplus
};
#endif

#endif
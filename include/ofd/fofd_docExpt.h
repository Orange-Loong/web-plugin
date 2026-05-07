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

#ifndef FOFD_DOCEXPT_H
#define FOFD_DOCEXPT_H

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

#ifndef FOFD_OBJEXPT_H
#include "fofd_objExpT.h"
#endif

#ifndef FOFD_PAGEEXPT_H
#include "fofd_pageExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* @OBJSTART FOFD_Document */
#ifndef FOFD_DOCUMENT
#define	FOFD_DOCUMENT

	/**
	* @brief The underlying OFD representation of a document.
	* 
	* you can use this object to read data from the document.
	*/
	typedef struct _t_FOFD_Document* FOFD_Document;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_Document */
#ifndef FOFD_WRITEDOCUMENT
#define	FOFD_WRITEDOCUMENT

	/**
	* @brief The underlying OFD representation of a document.
	*
	* you can use this object to write data to the document.
	*/
	typedef struct _t_FOFD_WriteDocument* FOFD_WriteDocument;
	
#endif

/* @OBJEND */

	
/* @OBJSTART FOFD_FILEPACKAGE */
#ifndef FOFD_FILEPACKAGE
#define	FOFD_FILEPACKAGE

	/**
	*
	*/
	typedef struct _t_FOFD_FilePackage* FOFD_FilePackage;
	
#endif
/* @OBJEND */

/* @OBJSTART FOFD_PARSER */
#ifndef FOFD_PARSER
#define	FOFD_PARSER

	/**
	*
	*/
	typedef struct _t_FOFD_Parser* FOFD_Parser;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_CREATOR */
#ifndef FOFD_CREATOR
#define	FOFD_CREATOR

	/**
	*
	*/
	typedef struct _t_FOFD_Creator* FOFD_Creator;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_OUTLINE */
#ifndef FOFD_OUTLINE
#define	FOFD_OUTLINE

	/**
	*
	*/
	typedef struct _t_FOFD_Outline* FOFD_Outline;
	
#endif
/* @OBJEND */

/* @OBJSTART FOFD_Bookmarks */
#ifndef FOFD_BOOKMARKS
#define	FOFD_BOOKMARKS

	/**
	*
	*/
	typedef struct _t_FOFD_Bookmarks* FOFD_Bookmarks;
	
#endif
/* @OBJEND */

/* @OBJSTART FOFD_Bookmark */
#ifndef FOFD_BOOKMARK
#define	FOFD_BOOKMARK

	/**
	*
	*/
	typedef struct _t_FOFD_Bookmark* FOFD_Bookmark;
	
#endif
/* @OBJEND */

/* @ENUMSTART OFD_ACTION_TYPE */
#ifndef _OFD_ACTION_TYPE_
#define	_OFD_ACTION_TYPE_

enum OFD_ACTION_TYPE
{
	OFD_ACTION_TYPE_Unknown = 0,
	OFD_ACTION_TYPE_Goto,
	OFD_ACTION_TYPE_URI,
	OFD_ACTION_TYPE_Sound,
	OFD_ACTION_TYPE_Movie,
	OFD_ACTION_TYPE_GotoA,
};
#endif
/* @ENUMEND*/

/* @OBJSTART FOFD_ACTIONS */
#ifndef FOFD_ACTIONS
#define	FOFD_ACTIONS

	/**
	*
	*/
	typedef struct _t_FOFD_Actions* FOFD_Actions;
	
#endif
/* @OBJEND */

/* @OBJSTART FOFD_ACTION */
#ifndef FOFD_ACTION
#define	FOFD_ACTION

	/**
	*
	*/
	typedef struct _t_FOFD_Action* FOFD_Action;
	
#endif
/* @OBJEND */


/* @OBJSTART FOFD_ActionGoto */
#ifndef FOFD_ACTIONGOTO
#define	FOFD_ACTIONGOTO

	/**
	*
	*/
	typedef struct _t_FOFD_ActionGoto* FOFD_ActionGoto;
	
#endif
/* @OBJEND */

/* @OBJSTART FOFD_ActionGotoA */
#ifndef FOFD_ACTIONGOTOA
#define	FOFD_ACTIONGOTOA

	/**
	*
	*/
	typedef struct _t_FOFD_ActionGotoA* FOFD_ActionGotoA;
	
#endif
/* @OBJEND */

/* @OBJSTART FOFD_ActionGotoA */
#ifndef FOFD_ACTIONURI
#define	FOFD_ACTIONURI

	/**
	*
	*/
	typedef struct _t_FOFD_ActionURI* FOFD_ActionURI;
	
#endif
/* @OBJEND */
	
/* @OBJSTART FOFD_ActionRegion*/
#ifndef FOFD_ACTIONREGION
#define FOFD_ACTIONREGION
	/**
	*
	*/
	typedef struct _t_FOFD_ActionRegion* FOFD_ActionRegion;
#endif
/* @OBJEND */

/* @OBJSTART FOFD_ActionArea*/
#ifndef FOFD_ACTIONAREA
#define FOFD_ACTIONAREA
	/**
	*
	*/
	typedef struct _t_FOFD_ActionArea* FOFD_ActionArea;
#endif
/* @OBJEND */

/* @OBJSTART FOFD_VPREFERENCES */
#ifndef FOFD_VPREFERENCES
#define	FOFD_VPREFERENCES

	/**
	*
	*/
	typedef struct _t_FOFD_VPreferences* FOFD_VPreferences;
	
#endif
/* @OBJEND */

/* @OBJSTART FOFD_PERMISSIONS */
#ifndef FOFD_PERMISSIONS
#define	FOFD_PERMISSIONS

	/**
	*
	*/
	typedef struct _t_FOFD_Permissions* FOFD_Permissions;
	
#endif
	
/* @OBJEND */
	

/* @ENUMSTART */
/** 
  * @brief the type of a signature appearance.
  */
enum E_OFD_SEALTYPE
{
	E_OFD_SEALTYPE_BITMAP,		/**< the seal type is picture. */
	E_OFD_SEALTYPE_OFD			/**< the seal type is ofd. */
};
/* @ENUMEND */


/* @ENUMSTART E_OFD_SIGNVERSION*/
/** 
  * @brief the type of a signature appearance.
  */
enum E_OFD_SIGNVERSION
{
	E_OFD_SIGNVERSION_FIRST = 1,		/**< the seal is signed by first-period oes library. */
	E_OFD_SIGNVERSION_SECOND		/**< the seal is signed by second-period oes library. */
};
/* @ENUMEND */


/* @ENUMSTART E_OFD_OESVERSION*/
/** 
  * @brief the type of a signature appearance.
  */
enum E_OFD_OESVERSION
{
	E_OFD_OESVERSION_FIRST = 1,		/**< the app now loaded first-period oes library. */
	E_OFD_OESVERSION_SECOND		/**< the app now loaded second-period oes library. */
};
/* @ENUMEND */



enum E_OFD_SEALBITMAPTYPE {
	E_OFD_SEALBITMAP_NORMAL = 0,
	E_OFD_SEALBITMAP_PRINT,
	E_OFD_SEALBITMAP_PREVIEW,
	E_OFD_SEALBITMAP_DECRYPT,
	E_OFD_SEALBITMAP_AUTHFAILED
};


/* @CALLBACKGROUPSTART FOFD_docProvider_callbacks_ */

/**
 * @brief A callback set for getting signature appearance in document. See <a>FOFD_CreateParser</a>.
 *
 */
typedef struct _fofd_docProvider_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FOFD_docProvider_callbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;
	
	/* @CALLBACKSTART FOFD_DocProvGetSealBitmap */
	/**
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.0
     */
	FS_DIBitmap (*FOFD_DocProvGetSealBitmap)(FS_LPVOID clientData, FOFD_Document pOFDDoc, FOFD_FileStream pSealFile);
	/* @CALLBACKEND */
	
	/* @CALLBACKSTART FOFD_DocProvGetSealFile */
	/**
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.0
     */
	FOFD_FileStream (*FOFD_DocProvGetSealFile)(FS_LPVOID clientData, FOFD_Document pOFDDoc, FOFD_FileStream pSealFile);
	/* @CALLBACKEND */
	
	/* @CALLBACKSTART FOFD_DocProvGetSealType */
	/**
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.0
     */
	E_OFD_SEALTYPE (*FOFD_DocProvGetSealType)(FS_LPVOID clientData, FOFD_FileStream pSealFile); 
	/* @CALLBACKEND */

	/* @CALLBACKSTART FOFD_DocProvSetSignVersion */
	/**
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.0
     */
	void (*FOFD_DocProvSetSignVersion)(FS_LPVOID clientData, E_OFD_SIGNVERSION eVersion); 
	/* @CALLBACKEND */
	
	/* @CALLBACKSTART FOFD_DocProvGetOesVersion */
	/**
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.0
     */
	E_OFD_OESVERSION (*FOFD_DocProvGetOesVersion)(FS_LPVOID clientData); 
	/* @CALLBACKEND */

	/* @CALLBACKSTART FOFD_DocProvGetOesVersion2 */
	/**
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.0
	 */
	E_OFD_OESVERSION(*FOFD_DocProvGetOesVersion2)(FS_LPVOID clientData,FS_BinaryBuf buf);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FOFD_DocProvGetSealBitmap */
	/**
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.0
	 */
	FS_DIBitmap(*FOFD_DocProvGetSealBitmap2)(FS_LPVOID clientData, FOFD_Document pOFDDoc, FOFD_FileStream pSealFile, E_OFD_SEALBITMAPTYPE type, FS_BinaryBuf buf);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FOFD_DocProvGetSealBitmap */
	/**
	 * @since <a>SDK_LATEEST_VERSION</a> > 9.0
	 */
	FS_DIBitmap(*FOFD_DocProvGetSealBitmap3)(FS_LPVOID clientData, FOFD_Document pOFDDoc, FOFD_FileStream pSealFile, FS_BinaryBuf buf);
	/* @CALLBACKEND */

	
}FOFD_docProvider_callbacksRec, *FOFD_docProvider_callbacks;

/* @CALLBACKGROUPEND */


#ifdef __cplusplus
};
#endif

#endif
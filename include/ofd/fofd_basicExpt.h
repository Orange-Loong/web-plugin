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

#ifndef FOFD_BASICEXPT_H
#define FOFD_BASICEXPT_H

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

/* @STRUCTSTART FOFD_RectF*/
#ifndef FOFD_RECTF
#define FOFD_RECTF
	/**
	* @brief A data structure representing a rectangle (a quadrilateral 
	* having only horizontal and vertical sides) in a window's coordinate space. 
	*
	*/
	typedef struct __FOFD_RECT_F__
	{
		/** The x-coordinate of the upper-left corner of a rectangle. */
		float			left;
		/** The y-coordinate of the upper-left corner of a rectangle. */
		float			top;
		/** The width of a rectangle. */
		float			width;
		/** The height of a rectangle. */
		float			height;
	}FOFD_RectF;
	
#endif
/* @STRUCTEND */

/* @DEFGROUPSTART OFDCIPHER */
/**
 * @name Macro definitions for OFDCIPHER types.
 */
/*@{*/

#define OFD_CIPHER_NONE			0

#define OFD_CIPHER_RC4			1

#define OFD_CIPHER_AES128		2

#define OFD_CIPHER_AES192		3

#define OFD_CIPHER_AES256		4

#define OFD_CIPHER_SM4			5

/*@}*/

/* @DEFGROUPEND */

/* @OBJSTART FOFD_CRYPTODICT */
#ifndef FOFD_CRYPTODICT
#define	FOFD_CRYPTODICT

	/**
	*
	*/
	typedef struct _t_FOFD_CryptoDict* FOFD_CryptoDict;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_SecurityHandler */
#ifndef FOFD_SECURITYHANDLER
#define	FOFD_SECURITYHANDLER

	/**
	*
	*/
	typedef struct _t_FOFD_SecurityHandler* FOFD_SecurityHandler;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_CryptoHandler */
#ifndef FOFD_CRYPTOHANDLER
#define	FOFD_CRYPTOHANDLER

	/**
	*	
	*/
	typedef struct _t_FOFD_CryptoHandler* FOFD_CryptoHandler;
	
#endif

/* @OBJEND */

/* @OBJSTART FOFD_FileStream */
#ifndef FOFD_FILESTREAM
#define FOFD_FILESTREAM

	/**
	*	
	*/
	typedef struct _t_FOFD_FileStream* FOFD_FileStream;
#endif
/* @OBJEND*/

/* @OBJSTART FOFD_PauseHandler*/
#ifndef FOFD_PAUSEHANDLER
#define FOFD_PAUSEHANDLER

	/**
	 * @brief An object preparing a simple pause instance.
	 */
typedef struct _t_FOFD_PauseHandler* FOFD_PauseHandler;
#endif
/* @OBJEND */


/* @ENUMSTART */
enum FOFD_CODEC_RESUNIT
{
	FOFD_CODEC_RESUNIT_NONE = 0,		///< no unit
	FOFD_CODEC_RESUNIT_INCH,			///< unit inch
	FOFD_CODEC_RESUNIT_CENTIMETER,		///< unit centimeter
	FOFD_CODEC_RESUNIT_METER			///< unit meter
};
/* @ENUMEND */

/* @OBJSTART FOFD_DIBAttribute*/
#ifndef FOFD_DIBATTRIBUTE
#define FOFD_DIBATTRIBUTE
	/**
	 * 
	 */
	typedef FS_DIBAttribute FOFD_DIBAttribute;
#endif
/* @OBJEND */

/* @CALLBACKGROUPSTART OFD_Pause */
#ifndef OFD_PAUSE
#define OFD_PAUSE
/**
 * @brief Simple pause interface.
 */
typedef struct
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FS_Pause</a>).  */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID	  clientData;

	/* @CALLBACKSTART NeedToPauseNow */
	/**
	* @brief Prototype of callback function.
	* @param[in]pClientData The user-supplied data
	* @return Non-zero means we need, otherwise we need not.
	* @note
	*/
	FS_BOOL	(*NeedToPauseNow)(FS_LPVOID pClientData);
	/* @CALLBACKEND */
}OFD_Pause,*POFD_Pause;
#endif
/* @CALLBACKGROUPEND */


/* @OBJSTART FOFD_CRYPTODICT */
#ifndef FOFD_FONTMAPPER
#define	FOFD_FONTMAPPER
/**
* @brief An object Fontmapper.
*/
typedef struct _t_FOFD_Fontmapper* FOFD_Fontmapper;
#endif
/* @OBJEND */


#ifdef __cplusplus
};
#endif

#endif
/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_parserExpT.h
		
 - The basic PDF file parser, etc. required to use the FPDLayer HFT.

*********************************************************************/
/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/


/**
  * @addtogroup FPDDOCUMENT
  * @{
  */


/**
* @file
* @brief data types for PDDoc layer
*/


#ifndef FPD_PARSEREXPT_H
#define FPD_PARSEREXPT_H


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

#ifndef FPD_DOCEXPT_H
#include "fpd_docExpT.h"
#endif



#ifdef __cplusplus
extern "C" {
#endif


/* @OBJSTART FPD_Parser */

/* @DEFGROUPSTART FPDParseErrCodes */
/**
 * @name Reasons for PDF parsing failure: returned by <a>FPDParserStartParse</a>() function.. 
 */
 /*@{*/

/** @brief no error. */
#define FPD_PARSE_ERROR_SUCCESS		0
/** @brief file error: not found or could not be opened. */
#define FPD_PARSE_ERROR_FILE		1
/** @brief format error: not a PDF or corrupted. */
#define FPD_PARSE_ERROR_FORMAT		2
/** @brief Invalid password. Please input again. */
#define FPD_PARSE_ERROR_PASSWORD	3
/** @brief This document is encrypted by some unsupported security handler. */
#define FPD_PARSE_ERROR_HANDLER		4
/** @brief This document is encrypted by digital certificate and current user doesn't have correct certificate. */ 
#define FPD_PARSE_ERROR_CERT		5
#ifndef _FXM_FEATURE_LIGHT_
/** @brief To be continued. */
#define FPD_PARSE_ERROR_TOBECONTINUED 6
/** @brief Other error . */
#define FPD_PARSE_ERROR_FAILED		  7
#endif	// _FXM_FEATURE_LIGHT_
/** @brief The data of file is scarcity.*/
#define FPD_PARSE_ERROR_DATA_SCARCITY 8
/*@}*/ 
/* @DEFGROUPEND */


/* @DEFGROUPSTART FPDParseContextFlags */
/**
 * @name Flags for parser context. 
 */
 /*@{*/

/** @brief Type only. */
#define FPD_PARSE_TYPEONLY	1
/** @brief No stream. */
#define FPD_PARSE_NOSTREAM	2

/*@}*/ 
/* @DEFGROUPEND */

/* @STRUCTSTART FPD_PARSE_CONTEXT */

#ifndef FPD_PARSE_CONTEXT_STRUCT
#define FPD_PARSE_CONTEXT_STRUCT
/** @brief Structure for parser context. */
typedef struct _FPD_PARSE_CONTEXT_
{
	/** The flags for parser context. */
	FS_BOOL		flags;
	/** The start position of the dictionary. */
	FS_DWORD	dictStart;
	/** The end position of the dictionary. */
	FS_DWORD	dictEnd;
	/** The start position of the data. */
	FS_DWORD	dataStart;
	/** The end position of the data. */
	FS_DWORD	dataEnd;
}FPD_PARSE_CONTEXT;

#endif


#ifndef FPD_PARSER
#define FPD_PARSER
	/**
	* @brief The PDF file parser to parse a pdf file to get a <a>FPD_Document</a>.
	*
	* Each PDF file need a FPD_Parser to parse the content, call <a>FPDParserStartParse</a> to
	* start to parse a file. See <a>FPDParserNew</a>, <a>FPDParserDestroy</a>.
	*/
	
	typedef struct _t_FPD_Parser* FPD_Parser;
#endif
/* @OBJEND */



#ifndef FPD_SIMPLEPARSER
#define FPD_SIMPLEPARSER
	/**
	* @brief Parsing a fixed buffer. Inside the buffer, there are words separated by delimiters.
    * Typical usage of this class includes searching the appearance stream, or a CMap file.
	*/
	typedef struct _t_FPD_SimpleParser* FPD_SimpleParser;
#endif
	/* @OBJEND */



#ifndef FPD_STANDARDCRYPTOHANDLER
#define FPD_STANDARDCRYPTOHANDLER
	/**
	* @brief The PDF file parser to parse a pdf file to get a <a>FPD_Document</a>.
	*
	* Each PDF file need a FPD_Parser to parse the content, call <a>FPDParserStartParse</a> to
	* start to parse a file. See <a>FPDParserNew</a>, <a>FPDParserDestroy</a>.
	*/

	typedef struct _t_FPD_StandardCryptoHandler* FPD_StandardCryptoHandler;
#endif
	/* @OBJEND */


#ifndef FPD_FIPSSTANDARDCRYPTOHANDLER
#define FPD_FIPSSTANDARDCRYPTOHANDLER
	/**
	* @brief The PDF file parser to parse a pdf file to get a <a>FPD_Document</a>.
	*
	* Each PDF file need a FPD_Parser to parse the content, call <a>FPDParserStartParse</a> to
	* start to parse a file. See <a>FPDParserNew</a>, <a>FPDParserDestroy</a>.
	*/

	typedef struct _t_FPD_FipsStandardCryptoHandler* FPD_FipsStandardCryptoHandler;
#endif
	/* @OBJEND */


/* @OBJSTART FPD_NumberTree */
#ifndef FPD_NUMBERTREE
#define FPD_NUMBERTREE
	/**
	* @brief The dictionary used to store all of the Named Destinations in a PDF file.
	*
	* A name tree is used to map FS ByteString to FPD Objects.You create a FPD_NameTree
	* and locate it where you think is appropriate (perhaps under a page, but most
	* often right under the catalog). See <a>FPDNameTreeNew</a>, <a>FPDNameTreeNew2</a>, <a>FPDNameTreeDestroy</a>.
	*/
	typedef struct _t_FPD_NumberTree* FPD_NumberTree;
#endif
	/* @OBJEND */


/* @OBJSTART FPD_SizeAnalysis */
#ifndef FPD_SIZEANALYSIS
#define FPD_SIZEANALYSIS
	/**
	* @brief 
	*	
	*/
	typedef struct _t_FPD_SizeAnalysis* FPD_SizeAnalysis;
#endif
/* @OBJEND */

/* @OBJSTART FPD_SyntaxParser */
#ifndef FPD_SYNTAXPARSER
#define FPD_SYNTAXPARSER
	/**
	* @brief
	*
	*/
	typedef struct _t_FPD_SyntaxParser* FPD_SyntaxParser;
#endif
/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
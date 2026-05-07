/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_textExpT.h
		
 - Types, macros, structures, etc. 

*********************************************************************/

/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/

/**
* @file
* @brief Text extracting and searching, Link extracting.
*/

/** @addtogroup FPDTEXT*/
/*@{*/
#ifndef FPD_TEXTEXPT_H
#define FPD_TEXTEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PAGEOBJEXPT_H
#include "fpd_pageobjExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/* @OBJSTART FPD_ProgressiveSearch */
/* @DEFGROUPSTART FPDSearchingStatus */
/** 
  * @name Searching status for progressive searching. See <a>FPDProgressiveSearchGetStatus</a>.
  */

/*@{*/

/** @brief Ready. */
#define FPD_SCH_STATUS_READY		 0 
/** @brief To be continued. */
#define FPD_SCH_STATUS_TOBECONTINUED 1 
/** @brief Found. */
#define FPD_SCH_STATUS_FOUND		 2 
/** @brief Not found. */
#define FPD_SCH_STATUS_NOTFOUND		 3 
/** @brief Failed. */
#define FPD_SCH_STATUS_FAILED		 4 
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDSearchFlags */
/**
* @name Search flags. See <a>FPDTextPageFindFindFirst</a>, <a>FPDTextPageFindFindNext</a>, <a>FPDTextPageFindFindPrev</a>.
*/

/*@{*/

/** @brief Whether to match the character case(upper/lower).*/
#define FPD_TEXT_MATCHCASE      0x00000001

/** @brief Whether to match the whole word for the search pattern.*/
#define FPDTEXT_MATCHWHOLEWORD 0x00000002

/** @brief Whether to do consecutive searching. */
#define FPDTEXT_CONSECUTIVE	0x00000004

/** @brief Whether to match Arabic kashida. */
#define FPDTEXT_MATCHKASHIDA	0x00000008

/** @brief Whether to match diacritics and accents. */
#define FPDTEXT_NOT_MATCHACCENTS	0x00000010

/** @brief Whether to match full-width and half-width. */
#define FPDTEXT_NOT_MATCHFULLWIDTH	0x00000020

/** @brief Whether to match alias. */
#define FPDTEXT_MATCHALIAS 0x00000040

/*@}*/
/* @DEFGROUPEND */

/**
  * @brief A progressive search facility for stream-based text searching inside a single page.
  * See <a>FPDProgressiveSeaarchNew</a>, <a>FPDProgressiveSeaarchDestroy</a>.
  */
#ifndef FPD_PROGRESSIVESEARCH
#define FPD_PROGRESSIVESEARCH
typedef struct _t_FPD_ProgressiveSearch* FPD_ProgressiveSearch;
#endif
/* @OBJEND */

/* @OBJSTART FPD_TextPage */
/* @DEFGROUPSTART FPDCharInfoFlag */
/**
  * @name char info flag.
  */

/*@{*/

/** @brief error. */
#define FPD_CHAR_ERROR		   -1	
/** @brief normal. */
#define FPD_CHAR_NORMAL			0	
/** @brief generated. */
#define FPD_CHAR_GENERATED		1
/** @brief ununicode. */
#define FPD_CHAR_UNUNICODE		2	

/*@}*/
/* @DEFGROUPEND */

/* @STRUCTSTART FPD_CHAR_INFO */
/** @brief Character info for TextPage. */
typedef struct _FPD_CHAR_INFO_
{
	_FPD_CHAR_INFO_()
	{
		m_Unicode = NULL;
		m_Charcode = NULL;
		m_Flag = 0;
		m_FontSize = 0;
		m_OriginX = 0;
		m_OriginY = 0;
		m_pTextObj = 0;
		m_nStartItem = -1;
		m_nCountItem = 0;
		m_nLineStartIdx = -1;
		m_nLineEndIdx = -1;
		m_bLineR2L = false;
	}


	/**  Unicode for the character. It need FSDWordArrayNew to initialize. */
	FS_DWordArray		m_Unicode;
	
	/** Character's flag. */
	FS_BOOL				m_Flag;	
	
	/**  The font size. */
	FS_FLOAT			m_FontSize;	
	
	/** The x-coordinate of the origin position. */
	FS_FLOAT			m_OriginX;	
	
	/** The y-coordinate of the origin position. */
	FS_FLOAT			m_OriginY;
	
	/** The character box. int page space. */
	FS_FloatRect		m_CharBox;
	
	/**  Which text object it belongs to. */
	FPD_PageObject		m_pTextObj;	
	
	/**  The matrix. */
	FS_AffineMatrix		m_Matrix;	

	/** The typographic(display and printing) bounding box in page
								 space.  The width is advance width, the height is the sum of the
								 ascent and descent. */
	FS_FloatRect        m_CharOutBox;

	/** First text object item it corresponds to. */
	FS_INT32            m_nStartItem;	
	
	/** Number of text object items it corresponds to. */
	FS_INT32            m_nCountItem;

	FS_INT32            m_nLineStartIdx;

	FS_INT32            m_nLineEndIdx;

	FS_BOOLEAN          m_bLineR2L;

	/** Charcode for the character. */
	FS_DWordArray       m_Charcode;
} FPD_CHAR_INFO;
/* @STRUCTEND */

/* @DEFGROUPSTART FPDTextPageFlags */
/**
  * @name Flags for creating text page. See <a>FPDTextNew</a>.
  */
/*@{*/

/** @brief Stream order. */
#define FPD_TEXT_STREAM_ORDER	0

/** @brief Display(appearance) order. */
#define FPD_TEXT_DISPLAY_ORDER	1

/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDTextDirectionsType */
/**
  * @name Directions type. See <a>FPDTextGetOrderByDirection</a>.
  */
/*@{*/

/** @brief Left direction. */
#define FPD_TEXT_LEFT			-1
/** @brief Right direction. */
#define FPD_TEXT_RIGHT			1
/** @brief Up direction. */
#define FPD_TEXT_UP				-2
/** @brief Down direction. */
#define FPD_TEXT_DOWN			2

/*@}*/
/* @DEFGROUPEND */

/* @OBJSTART FPD_TextPage */
/**
/** 
  * @brief Text page for PDF text processing. See <a>FPDTextNew</a>, <a>FPDTextDestroy</a>.
  */
#ifndef FPD_TEXTPAGE
#define FPD_TEXTPAGE
typedef struct _t_FPD_TextPage* FPD_TextPage;
#endif

/* @STRUCTSTART FPD_Text_ParseOption */
/** @brief Text parseoptions. */
typedef struct __FPD_Text_ParseOption__
{
	__FPD_Text_ParseOption__()
	{
		m_bGetCharCodeOnly = false;
		m_bNormalizeObjs = true;
		m_bOutputHyphen = false;
		m_bNoProcessMarkedContent = true;
		m_bIsGetCharRect = false;
		m_bOutputTrailingSpace = false;
	}

	/** Whether get char code only.*/
	FS_BOOLEAN			m_bGetCharCodeOnly;
	/** Whether normalize objects. */
	FS_BOOLEAN			m_bNormalizeObjs;
	/** Whether output hyphen. */
	FS_BOOLEAN			m_bOutputHyphen;
	/** Whether not to processmark content. */
	FS_BOOLEAN			m_bNoProcessMarkedContent;
	/** Whether get char rect. */
	FS_BOOLEAN			m_bIsGetCharRect;
	/** Whether output trail sapce. */
	FS_BOOLEAN			m_bOutputTrailingSpace;
}FPD_Text_ParseOption;
/* @STRUCTEND */
/* @OBJEND */

/* @OBJSTART FPD_TextPageFind */
/**
  * @brief To find a text in a page. See <a>FPDTextPageFindNew</a>, <a>FPDTextPageFindDestroy</a>.
  */
#ifndef FPD_TEXTPAGEFIND
#define FPD_TEXTPAGEFIND
typedef struct _t_FPD_TextPageFind* FPD_TextPageFind;
#endif
/* @OBJEND */

/* @OBJSTART FPD_LinkExtract */
/** 
  * @brief A link extractor for accessing links. See <a>FPDLinkExtractNew</a>, <a>FPDLinkExtractDestroy</a>.
  */
#ifndef FPD_LINKEXTRACT
#define FPD_LINKEXTRACT
typedef struct _t_FPD_LinkExtract* FPD_LinkExtract;
#endif
/* @OBJEND */


#define FPD_CHARTYPEBITS		11
#define FPD_CHARTYPEBITSMASK	(15 << FPD_CHARTYPEBITS)
enum FPD_CHARTYPE
{
	FPD_CHARTYPE_Unknown = 0,						//unknown character type
	FPD_CHARTYPE_Tab = (1 << FPD_CHARTYPEBITS),	//tab character, '\t'
	FPD_CHARTYPE_Space = (2 << FPD_CHARTYPEBITS),	//space character, ' '
	FPD_CHARTYPE_Control = (3 << FPD_CHARTYPEBITS),	//control character
	FPD_CHARTYPE_Combination = (4 << FPD_CHARTYPEBITS),	//combination character
	FPD_CHARTYPE_Numeric = (5 << FPD_CHARTYPEBITS),	//numeric character, '0' - '9'
	FPD_CHARTYPE_Normal = (6 << FPD_CHARTYPEBITS),	//normal character
	FPD_CHARTYPE_ArabicAlef = (7 << FPD_CHARTYPEBITS),  //arabic alef character
	FPD_CHARTYPE_ArabicSpecial = (8 << FPD_CHARTYPEBITS),  //arabic special character
	FPD_CHARTYPE_ArabicDistortion = (9 << FPD_CHARTYPEBITS),	//arabic distortion character
	FPD_CHARTYPE_ArabicNormal = (10 << FPD_CHARTYPEBITS),	//arabic normal character
	FPD_CHARTYPE_ArabicForm = (11 << FPD_CHARTYPEBITS), //arabic form character
	FPD_CHARTYPE_Arabic = (12 << FPD_CHARTYPEBITS),	//arabic character, internal usage
};



#ifdef __cplusplus
};
#endif

#endif
/*@}*/

/*@}*/

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

#ifndef FPD_FONTMGREXPT_H
#define FPD_FONTMGREXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif


/* @OBJSTART FPD_FMFontMgr */
#ifndef FPD_FMFONTMGR
#define	FPD_FMFONTMGR
/**
* @brief
*/
	typedef struct _t_FPD_FMFontMgr* FPD_FMFontMgr;
#endif	

/* @DEFGROUPSTART FM_CHARSET info */
/**
* @brief Definitions FM_CHARSET info.
*/

/*@{*/
#define FPDFM_CHARSET_ANSI						0	//1252, ANSI
#define FPDFM_CHARSET_Default					1	//0, Default
#define FPDFM_CHARSET_Symbol					2	//42, Symbol
#define FPDFM_CHARSET_MAC_Roman					77	//10000	Mac Roman
#define FPDFM_CHARSET_MAC_ShiftJIS				78	//10001	Mac Shift Jis
#define FPDFM_CHARSET_MAC_Korean				79	//10003	Mac Korean
#define FPDFM_CHARSET_MAC_ChineseSimplified		80	//10008	Mac Chinese Simplified (GBK)
#define FPDFM_CHARSET_MAC_ChineseTraditional    81		// 10002 Mac Chinese Traditional (Big5)
#define FPDFM_CHARSET_MAC_Johab					82	//Mac Johab (old)
#define FPDFM_CHARSET_MAC_Hebrew				83	//10005	Mac Hebrew
#define FPDFM_CHARSET_MAC_Arabic				84	//10004	Mac Arabic
#define FPDFM_CHARSET_MAC_Greek					85	//10006	Mac Greek
#define FPDFM_CHARSET_MAC_Turkish				86	//10081	Mac Turkish
#define FPDFM_CHARSET_MAC_Thai					87	//10021	Mac Thai
#define FPDFM_CHARSET_MAC_EasternEuropean		88	//10029	Mac Eastern European (Latin 2)
#define FPDFM_CHARSET_MAC_Cyrillic				89	//10007	Mac Cyrillic
#define FPDFM_CHARSET_ShiftJIS					128	//932	Shift JIS
#define FPDFM_CHARSET_Korean					129	//949	Korean
#define FPDFM_CHARSET_Johab						130	//1361	Johab
#define FPDFM_CHARSET_ChineseSimplified			134	//936	Chinese Simplified (GBK)
#define FPDFM_CHARSET_ChineseTraditional        136			// 950	Chinese Traditional (Big5)
#define FPDFM_CHARSET_MSWin_Greek				161	//1253	Greek
#define FPDFM_CHARSET_MSWin_Turkish				162	//1254	Turkish
#define FPDFM_CHARSET_MSWin_Vietnamese			163	//1258	Vietnamese
#define FPDFM_CHARSET_MSWin_Hebrew				177	//1255	Hebrew
#define FPDFM_CHARSET_MSWin_Arabic				178	//1256	Arabic 
#define FPDFM_CHARSET_ArabicTraditional			179	//Arabic Traditional (old)
#define FPDFM_CHARSET_ArabicUser				180	//Arabic user (old)
#define FPDFM_CHARSET_HebrewUser				181	//Hebrew user (old)
#define FPDFM_CHARSET_MSWin_Baltic				186	//1257	Baltic
#define FPDFM_CHARSET_MSWin_Cyrillic			204	//1251	Cyrillic
#define FPDFM_CHARSET_Thai						222	//874	Thai
#define FPDFM_CHARSET_MSWin_EasterEuropean		238	//1250	Eastern European
#define FPDFM_CHARSET_US						254	//437	PC 437
#define FPDFM_CHARSET_OEM						255	//850	OEM
/* @DEFGROUPEND */


/* @DEFGROUPSTART FM_LANGUAGE info */
/**
* @brief Definitions FM_LANGUAGE info.
*/
/*@{*/
	//The number is according to Macintosh platform, and it is different from Windows platform.
#define FPDXM_LANGUAGE_English				    0	//default English
#define FPDXM_LANGUAGE_Japanese				    11	//Japanese
#define FPDXM_LANGUAGE_Chinese_Traditional	    19	//Chinese (Traditional)
#define FPDXM_LANGUAGE_Korean					23	//Korean, not support so we use ansi
#define FPDXM_LANGUAGE_Chinese_Simplified		33	//Chinese (Simplified)


/* @DEFGROUPSTART FM_PLATFORM info */
/**
* @brief Definitions FM_PLATFORM info.
*/
/*@{*/
/** @brief Windows OS platformas. */
#define FPDXM_PLATFORM_WINDOWS		1
/** @brief Linux OS platformas. */
#define FPDXM_PLATFORM_LINUX		2
/** @brief Apple OS platformas. */
#define FPDXM_PLATFORM_APPLE	    3
/** @brief Android OS platformas. */
#define FPDXM_PLATFORM_ANDROID		4
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_FMFontDescriptor */
#ifndef FPD_FMFONTDESCRIPTOR
#define	FPD_FMFONTDESCRIPTOR
/**
* @brief
*/
	typedef struct _t_FPD_FMFontDescriptor* FPD_FMFontDescriptor;
#endif	

/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
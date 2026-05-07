/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.	

*********************************************************************/

#ifndef FS_COMMON_H
#define FS_COMMON_H


#ifdef __cplusplus
extern "C"{
#endif
	
/* @COMMONSTART */

/* @DEFGROUPSTART SDKVersion */
/** 
 * @brief The SDK version.
 */

/*@{*/
/** 
 * @brief  The current SDK version is 11.0.0.0. Built in Foxit PDF Reader/FoxitPDFEditor version 11.0.
 */
#define SDK_VERSION ((FS_INT32)((11L<<24) + (0L<<16) + (0L<<8) + 0L))
/*@}*/
/* @DEFGROUPEND */


/* @DEFGROUPSTART SDKVersion */
/**
 * @brief It's used to check the sdk version used by the plug-in.
 */

 /*@{*/
 /**
  * @brief  The current SDK version is 2024.4.0. Built in Foxit PDF Reader/Foxit PDF Editor version continous 2024.4.0.
  */
#define PLUGINSDK_VERSION    "2024.4.0"
  /*@}*/
/* @DEFGROUPEND */


/***/
#define SDK_LATEEST_VERSION SDK_VERSION

/***/
#define SDK_VERSION_1_SELECTED

#ifndef FR_CORE_INTERFACEMGR
#define FR_CORE_INTERFACEMGR


/* @STRUCTSTART FRCoreHFTMgr */
/**
 * @brief Core HFT manager.
 */
typedef struct __FRCoreHFTMgr__
{ 
	/*The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FRCoreHFTMgr</a>)*/
	unsigned long lStructSize;

	/** Query a interface from selected HFT. */
	/**
	* @brief 
	* @param[in] hftSel
	* @param[in] iSel
	* @param[in] gID
	* @return 
	* @note
	*/
	void* (*QueryInterface)(int hftSel, int iSel, void* gID);
	
	/** Replace a interface. */
	/**
	* @brief 
	* @param[in] hftSel
	* @param[in] iSel
	* @param[in] gID
	* @return 
	* @note
	*/
	void (*UpdateInterface)(int hftSel, int iSel, void* gID);
	
	/** Get the version of SDK. */
	/**
	* @brief 
	* @return 
	* @note
	*/
	int (*FRGetSDKVersion)(void);

	/** Get the replaced entry. */
	/**
	* @brief 
	* @param[in] hftSel
	* @param[in] iSel
	* @param[in] oldProc
	* @return 
	* @note
	*/
	void* (*GetReplacedEntry)(int hftSel, int iSel, void* oldProc);

	/** Get the version of SDK. It's used to extend the SDK version. */
	/**
	* @brief
	* @return
	* @note
	*/
	const char*(*FRGetPluginSDKVersion)(void);
	
}FRCoreHFTMgr;
#endif
/* @STRUCTEND */



/* @DEFGROUPSTART AddHFTErrs */
/**
 * @name Flags returned by FSExtensionHFTMgrAddHFT.
 */
/*@{*/

/** @brief Unknown error.*/
#define ERR_ADDHFT_UNKNOWN 0

/** @brief Success. */
#define ERR_ADDHFT_SUCCESS 1

/** @brief Name with the HFT has been used. */
#define ERR_ADDHFT_NAMEEXIST 2

/** @brief The HFT is an empty object. */
#define ERR_ADDHFT_EMPTYLHFT	3

/*@}*/

/* @DEFGROUPEND */

extern FRCoreHFTMgr *_gpCoreHFTMgr;
extern void* _gPID;

/**
 * @brief 
 * @param[in] categorySEL
 * @param[in] interfaceSEL
 * @return
 * @note
*/
#define FRCOREROUTINE(categorySEL, interfaceSEL, pid) (_gpCoreHFTMgr->QueryInterface(categorySEL, interfaceSEL, pid))

#undef CATEGORY
#define CATEGORY(name) name##SEL,

#ifndef CATEGORY_SELECTOR
#define CATEGORY_SELECTOR
enum
{
#include "..\basic\fs_categoryTempl.h"
	CATEGORYSELECTORS
};
#endif
#define CoreCategoriesNum (CATEGORYSELECTORS)
#undef CATEGORY

/* @DEFCALLSSTART CALL_REPLACED_PROC */

/**
 * @name Macros for entries replacing.
 */
/*@{*/

/**
 * @brief Calls the previous implementation of a replaced method(that is, the code that would have been executed before the method was replaced
 * using <a>FSExtensionHFTMgrReplaceEntry</a>).
 * @param[in] hftSEL	The HFT selector indicates a HFT which containing the replaced method to execute. For example, FSExtensionHFTMgrSEL.
 * @param[in] sel		The selector for the replaced method to execute. The name must have the characters <Italic>SEL</Italic> appended.
 * @param[in] oldProc	The callback whose previouse implementation is called. A method may be replaced more than once, and all replacements
 *						for a particular method are kept in a linked list. <Italic>oldProc</Italic> must be an element in that linked list,
 *						and the entry before <Italic>oldProc</Italic> is the one that is called.
 */
#define CALL_REPLACED_PROC(hftSEL, sel, oldProc) (*((sel##PROTO )(_gpCoreHFTMgr->GetReplacedEntry(hftSEL, sel, oldProc))))


/*@}*/

/* @DEFCALLSEND */


/* @DEFCALLSSTART INIT_CALLBACK_STRUCT */
/**
 * @name Macros for initializing a structure.
 */
/*@{*/
/**
 * @brief Init a structure, calling this method to init all callback structure which register into Foxit Reader.
 * @param[in] addressOfStruct	The address of a structure which to be init.
 * @param[in] sizeOfStruct		The size of a structure which to be init.
 */
#define INIT_CALLBACK_STRUCT(addressOfStruct, sizeOfStruct) (memset(addressOfStruct, 0, sizeOfStruct))
/*@}*/
/* @DEFCALLSEND */

/* @COMMONEND */
#ifdef __cplusplus
};
#endif


#endif



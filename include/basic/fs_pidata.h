
/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.	

	
---------------------------------------------------------------------
PIData.h
		
  - Data structures, types, and other things related to plug-ins and
	version changes. This file is shared between foxit reader and plug-ins.
	  
 - Contains handshaking versioning types and data.
			
*********************************************************************/

#ifndef FS_PIDATA_H
#define FS_PIDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif


/* @COMMONSTART */

/* @CALLBACKSTART PISetupSDKProcType*/		
/**
 * @brief It is called by foxit reader to set up the SDK.
 * @param[in] handshakeVersion	The version of the handshake.
 * @param[in] sdkData			A pointer to <a>PISDKData_V0100</a> structure, it also be used to pass to
 * <a>PISDSetHandshakeProc</a>() as <param>thisData</param> parameter.
 * @return TRUE for success, otherwise FALSE.
 * @note
*/
typedef FS_BOOL (*PISetupSDKProcType)(FS_INT32 handshakeVersion, void* sdkData);
/* @CALLBACKEND */

/* @CALLBACKSTART PIMakeTokenProcType*/		
/**
 * @brief It is called by foxit reader to validate an internal plug-in.
 * @param[in] lpwsEncryptedToken	The encrypted token.
 * @param[out] bufSourceToken		Buffer for output source token.
 * @param[in] nBufLength			Buffer length.
 * @return void.
 * @note
*/
typedef void (*PIMakeTokenProcType)(FS_LPCWSTR lpwsEncryptedToken, void* bufSourceToken, FS_INT32 nBufLength);
/* @CALLBACKEND */

/* @CALLBACKSTART PIHandshakeProcType*/	
/**
 * @brief It is called by foxit reader to do the handshake.
 * @param[in] handshakeVersion		The handshakeVersion.
 * @param[in] handshakeData			A pointer to <a>PIHandshakeData_V0100</a> structure, it also used to
 * pass to <a>PIHDRegisterPlugin</a>(), <a>PIHDSetExportHFTsCallback</a>(), <a>PIHDSetImportReplaceAndRegisterCallback</a>(),
 * <a><PIHDSetInitCallback/a>() and <a>PIHDSetUnloadCallback</a>() as <param>thisData</param> parameter.
 * @return TRUE for success, otherwise FALSE.
 * @note
*/
typedef FS_BOOL (*PIHandshakeProcType)(FS_INT32 handshakeVersion, void* handshakeData);
/* @CALLBACKEND */

/* @CALLBACKSTART PIExportHFTsProcType*/	
/**
 * @brief It is called by foxit reader to notify the plug-in to export the HFTs.
 * @return TRUE for success, otherwise FALSE.
 * @note
*/
typedef FS_BOOL (*PIExportHFTsProcType)(void);
/* @CALLBACKEND */

/* @CALLBACKSTART PIImportReplaceAndRegisterProcType */		
/**
 * @brief It is called by foxit reader to notify the plug-in to import the HFTs.
 * @return TRUE for success, otherwise FALSE.
 * @note
*/
typedef FS_BOOL (*PIImportReplaceAndRegisterProcType)(void);
/* @CALLBACKEND */

/* @CALLBACKSTART PIInitDataProcType*/
/**
 * @brief It is called by foxit reader to notify the plug-in to initialize the data only. The plug-in must initialize the UI in PIInitUIProcs.
 * @return TRUE for success, otherwise FALSE.
 * @note
*/
typedef FS_BOOL (*PIInitDataProcType)(void);
/* @CALLBACKEND */

/* @CALLBACKGROUPSTART PIInitUIProcs */
/**
 * @brief Structure containing callbacks to initialize the UI. Invokes <a>INIT_CALLBACK_STRUCT</a> to initialize the callbacks.
 */

typedef struct {

	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>PIInitUIProcs</a>).  */
	unsigned long lStructSize;

	/* @CALLBACKSTART PILoadMenuBarUI */
	/**
	 * @brief It will be invoked when Foxit Reader starts to initialize and load the menu bar.
	 * @param[in] pParentWnd	A pointer to the parent window. You can convert it to <Italic>MFC CWnd*</Italic>.
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	 * @see 
	 */
	void (*PILoadMenuBarUI)(void* pParentWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIReleaseMenuBarUI */
	/**
	 * @brief It will be invoked to notify the plug-in to release the menu bar.
	 * @param[in] pParentWnd	A pointer to the parent window. You can convert it to <Italic>MFC CWnd*</Italic>.
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	 * @see 
	 */
	void (*PIReleaseMenuBarUI)(void* pParentWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PILoadToolBarUI */
	/**
	 * @brief It will be invoked when Foxit Reader starts to initialize and load the tool bar.
	 * @param[in] pParentWnd	A pointer to the parent window. You can convert it to <Italic>MFC CWnd*</Italic>.
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	 * @see 
	 */
	void (*PILoadToolBarUI)(void* pParentWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIReleaseToolBarUI */
	/**
	 * @brief It will be invoked to notify the plug-in to release the tool bar.
	 * @param[in] pParentWnd	A pointer to the parent window. You can convert it to <Italic>MFC CWnd*</Italic>.
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	 * @see 
	 */
	void (*PIReleaseToolBarUI)(void* pParentWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PILoadRibbonUI */
	/**
	 * @brief It will be invoked when Foxit Reader starts to initialize and load the ribbon mode UI.
	 * @param[in] pParentWnd	A pointer to the parent window. You can convert it to <Italic>MFC CWnd*</Italic>.
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	 * @see 
	 */
	void (*PILoadRibbonUI)(void* pParentWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PILoadStatusBarUI */
	/**
	 * @brief It will be invoked when Foxit Reader starts to initialize and load the status bar.
	 * @param[in] pParentWnd	A pointer to the parent window. You can convert it to <Italic>MFC CWnd*</Italic>.
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	 * @see 
	 */
	void (*PILoadStatusBarUI)(void* pParentWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIReleaseStatusBarUI */
	/**
	* @brief  It will be invoked to notify the plug-in to release the status bar.
	* @param[in] pParentWnd	A pointer to the parent window. You can convert it to <Italic>MFC CWnd*</Italic>.
	* @return void
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	* @see
	*/
	void(*PIReleaseStatusBarUI)(void* pParentWnd);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIReleaseRibbonUI */
	/**
	* @brief  It will be invoked to notify the plug-in to release the ribbon bar.
	* @param[in] pParentWnd	A pointer to the parent window. You can convert it to <Italic>MFC CWnd*</Italic>.
	* @return void
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	* @see
	*/
	void(*PIReleaseRibbonUI)(void* pParentWnd);
	/* @CALLBACKEND */


	
} PIInitUIProcs;
/* @CALLBACKGROUPEND */

/* @CALLBACKSTART PIUnloadProcType*/
/**
 * @brief It is called by foxit reader to notify the plug-in to unload.
 * @return TRUE for success, otherwise FALSE.
 * @note
*/
typedef FS_BOOL (*PIUnloadProcType)(void);

/* @CALLBACKEND */

 
/* @CALLBACKSTART PIMainProcType*/

/**
 * @brief  A callback called by Foxit Reader at the first time a plug-in is loading. 
 * @param[in] handshakeVersion		Version of the handshake struct, send by Foxit Reader.
 * @param[out] setupProc			A pointer to the handshake procedure.			
 * @return  If <a>TRUE</a>, the plug-in will be load continue on. <a>FALSE</a>, the plug-in will be unload.
 */
typedef FS_BOOL (*PIMainProcType)(FS_INT32* handshakeVersion, PISetupSDKProcType* setupProc);
/* @CALLBACKEND */


/* @CALLBACKSTART PIOnAboutPluginsProcType*/

/**
 * @brief  A callback called by Foxit Reader to show info of all plug-ins. 
 * @param[in] pluginData		Data of loaded plug-ins.
 * @return
 */
typedef void (*PIOnAboutPluginsProcType)(void* pluginData);
/* @CALLBACKEND */

/* @CALLBACKSTART PIOnDelayLoadJSPluginsProcType*/

/**
* @brief  This callback is invoked by framework to notify the plug-in platform that it is
 * the appropriate time to delay loading js plug-ins. 
 * @param[in] bSilent It indicates whether the js plug-in is loaded silently or not.
 * @param[in] pParentWnd A pointer to the parent window. You can convert it to <Italic>MFC CWnd*</Italic>.
 * @return
 */
typedef void (*PIOnDelayLoadJSPluginsProcType)(FS_BOOL bSilent, void* pParentWnd);
/* @CALLBACKEND */


/* @DEFGROUPSTART Handshakeverssion */
/**
 * @brief Known handshake versions and data structures should be listed below:<br>
 * <ul>
 * <li>Top 2 bytes contains the major version; bottom 2 bytes the minor version.</li>
 * <li>All shipping versions have a zero minor version.</li>
 * <li>All apps and plugs-ins must support all previous shipping versions.</li>
 * <li>Interpet last 4 digits of the name as MMmm, where MM is the major #; mm is the minor.</li>
 * </ul>
 */

/*@{*/
/* @brief */
#define HANDSHAKE_V0100			((FS_INT32)((1L<<16) + 0))
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKGROUPSTART PISDKData_V0100 */
/**
 * @brief Structure containing callbacks to get or send data to the plug-in's PISetupSDK() routine.
 * This routine is implemented in the PIMain.c routine supplied with the Plug-in SDK.
 * The first field of any SDKData_VMMmm struct must be handshakeVersion.
 */

typedef struct {

	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>PISDKData_V0100</a>).  */
	unsigned long lStructSize;

	/* @CALLBACKSTART PISDGetHandshakeVersion*/
	/**
	 * @brief Gets the version of handshake structure.
	 * @return The handshake version.
	 * @note
	 */
	FS_INT32				(*PISDGetHandshakeVersion)(void);
	/* @CALLBACKEND */
	
	/* @CALLBACKSTART PISDSetHandshakeProc */
	/**
	 * @brief Sets handshake process to Reader.
	 * @param[in] thisData	A pointer to a PISDKData_V0100 structure which passed by <a>PISetupSDKProcType</a>().
	 * @param[in] proc 		The input handshake callback.
	 * @return 
	 * @note
	 */
	void					(*PISDSetHandshakeProc)(void* thisData, PIHandshakeProcType proc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PISDGetCoreHFT */
	/**
	 * @brief Gets the core HFT manager.
	 * @return The core HFT manager.
	 * @note
	 */
	FRCoreHFTMgr*			(*PISDGetCoreHFT)(void);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PISDGetPID */
	/**
	 * @brief  Gets the Plug-in ID generated by Reader.
	 * @param[in] thisData	A pointer to a PISDKData_V0100 structure which passed by <a>PISetupSDKProcType</a>().
	 * @return The plug-in ID.
	 * @note
	 */
	FS_LPVOID				(*PISDGetPID)(void* thisData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PISetSDKVersion */
	/**
	 * @brief  Pass the Plug-in SDK version used to Reader. Then Reader will not load the Plug-in whose version is larger.
	 * @param[in] thisData		A pointer to a PISDKData_V0100 structure which passed by <a>PISetupSDKProcType</a>().
	 * @param[in] nPISDKVersion	The version of the Plug-in SDK.
	 * @return 
	 * @note
	 */
	void					(*PISetSDKVersion)(void* thisData, FS_INT32 nPISDKVersion);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PISDSetMakeTokenProc */
	/**
	 * @brief Sets make-token process to Reader.
	 * @param[in] thisData	A pointer to a PISDKData_V0100 structure which passed by <a>PISetupSDKProcType</a>().
	 * @param[in] proc 		The input make-token callback.
	 * @return 
	 * @note
	 */
	void					(*PISDSetMakeTokenProc)(void* thisData, PIMakeTokenProcType proc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PISetPluginSDKVersion */
	/**
	 * @brief  Pass the Plug-in SDK version used to Reader. Then Reader will not load the Plug-in whose version is larger.
	 * @param[in] thisData		A pointer to a PISDKData_V0100 structure which passed by <a>PISetupSDKProcType</a>().
	 * @param[in] nPISDKVersion	The version of the Plug-in SDK.
	 * @return
	 * @note
	 */
	void                    (*PISetPluginSDKVersion)(void* thisData, FS_LPCSTR sVersion);
	/* @CALLBACKEND */
} PISDKData_V0100;

/* @CALLBACKGROUPEND */


/* @CALLBACKGROUPSTART PIHDPltfmData */
/** @brief PIHDPltfmData
*
 * Structure containing data to exchange with plug-in platform and will not be passed to 
 * common plug-in.
 */
typedef struct {

	/* @CALLBACKSTART PIHDLoadPlugin */
	/**
	 * @brief Notify Reader to load plug-in(s).
	 * @param[in] arrLibPath		A pointer to an array of library path.
	 * @param[in] bFreeLibWhenFailed		Flag to indicate whether to free library when failed load plug-in(s).
	 * @return  TRUE means successful, otherwise not.
	 * @note
	 */
	FS_BOOL					(*PIHDLoadPlugin)(void* arrLibPath, FS_BOOL bFreeLibWhenFailed);

	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDSetOnAboutPluginsCallback*/
	/**
	 * @brief Sets the on about plug-ins process.
	 * @param[in] proc			A callback supplied by plug-in platform to call to manage plug-ins.
	 * @return 
	 * @note
	 */
	void					(*PIHDSetOnAboutPluginsCallback)(PIOnAboutPluginsProcType proc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDGetLastPluginLoadError */
	/**
	 * @brief		Gets the error while loading the last plug-in from Foxit Reader Application.
	 * @return		The error code while loading the last plug-in.
	 * @note
	 */
	FS_INT32				(*PIHDGetLastPluginLoadError)(void);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDIsPluginDisabledBy */
	/**
	 * @brief		Tests a plug-in is disabled by some strategy(like GPO) or not.
	 * @param[in] lpwsFileName		The file name of the tested plug-in.
	 * @return		TRUE means yes, otherwise not.
	 * @note
	 */
	FS_BOOL				(*PIHDIsPluginDisabledBy)(FS_LPCWSTR lpwsFileName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDSetOnDelayLoadJSPluginsCallback*/
	/**
	 * @brief This callback is invoked by framework to notify the plug-in platform that it is
	 * the appropriate time to delay loading js plug-ins.
	 * @param[in] proc			A callback supplied by plug-in platform and invoked by framework.
	 * @return 
	 * @note
	 */
	void (*PIHDSetOnDelayLoadJSPluginsCallback)(PIOnDelayLoadJSPluginsProcType proc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDLoadPluginUI */
	/**
	 * @brief Notify Reader to load plug-in(s) UI.
	 * @param[in] hWnd		 The main frame window of Foxit Reader.
	 * @param[in] arrLibPath Self-defined data structure.
	 * @return  TRUE means successful, otherwise not.
	 * @note
	 */
	FS_BOOL				(*PIHDLoadPluginUI)(HWND hWnd, void* arrLibPath);
	/* @CALLBACKEND */

}PIHDPltfmData;

/* @CALLBACKGROUPEND */


/* @CALLBACKGROUPSTART PIHandshakeData_V0100 */
/** @brief PIHandshakeData_V0100
*
 * Structure containing data to be passed in and out of the plug-ins PIHandshake() routine.
 * This routine MUST be implemented with that name by the plug-in writer.
 * The first field of any PIHandshakeData_VMMmm struct must be handshakeVersion.
 */
typedef struct {

	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>PIHandshakeData_V0100</a>).  */
	unsigned long lStructSize;

	/* @CALLBACKSTART PIHDGetHandshakeVersion */
	/**
	 * @brief		Gets the handshakeVersion from Foxit Reader Application.
	 * @return		The build-in handshakeVersion of Foxit Reader Application.
	 * @note
	 */
	FS_INT32				(*PIHDGetHandshakeVersion)(void);					
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDGetAppName */
	/**
	 * @brief Gets the application name.
	 * @return The application name.
	 * @note
	 */
	char*					(*PIHDGetAppName)(void);							
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDRegisterPlugin */
	/**
	 * @brief Register a name and a title for plugin to Reader.
	 * @param[in] thisData		A pointer to a PIHandshakeData_V0100 structure which passed by <a>PIHandshakeProcType</a>().
	 * @param[in] name			The plug-in name.
	 * @param[in] lpwsTitle     The title to be displayed.
	 * @return  TRUE means successful, otherwise not.
	 * @note
	 */
	FS_BOOL					(*PIHDRegisterPlugin)(void* thisData, char* name, FS_LPCWSTR lpwsTitle);						
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDSetExportHFTsCallback */
	/**
	 * @brief  Sets the export process.
	 * @param[in] thisData		A pointer to a PIHandshakeData_V0100 structure which passed by <a>PIHandshakeProcType</a>().
	 * @param[in] proc			A user-supplied callback to call whenever plug-ins need to export its owner HFT.
	 * @return 
	 * @note
	 */
	void					(*PIHDSetExportHFTsCallback)(void* thisData, PIExportHFTsProcType proc);				
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDSetImportReplaceAndRegisterCallback */
	/**
	 * @brief Sets the replacing process.
	 * @param[in] thisData		A pointer to a PIHandshakeData_V0100 structure which passed by <a>PIHandshakeProcType</a>().
	 * @param[in] proc			A user-supplied callback to call whenever plug-ins need to replace or register some entry.
	 * @return 
	 * @note
	 */
	void					(*PIHDSetImportReplaceAndRegisterCallback)(void* thisData, PIImportReplaceAndRegisterProcType proc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDSetInitDataCallback */
	/**
	 * @brief Sets the callback to initialize the data.
	 * @param[in] thisData		A pointer to a PIHandshakeData_V0100 structure which passed by <a>PIHandshakeProcType</a>().
	 * @param[in] proc			A user-supplied callback to call whenever plug-ins need to do some initialization.
	 * @return 
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	 * @see 
	 */
	void					(*PIHDSetInitDataCallback)(void* thisData, PIInitDataProcType proc);						
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDSetInitUICallbacks */
	/**
	 * @brief Sets the callbacks to initialize the UI. If you do not set the callbacks, the plug-in will not be loaded.
	 * @param[in] thisData		A pointer to a PIHandshakeData_V0100 structure which passed by <a>PIHandshakeProcType</a>().
	 * @param[in] pProcs		The user-supplied callbacks to call when plug-ins need to initialize the UI.
	 * @return 
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	 * @see 
	 */
	void					(*PIHDSetInitUICallbacks)(void* thisData, PIInitUIProcs* pProcs);						
	/* @CALLBACKEND */

	/* @CALLBACKSTART PIHDSetUnloadCallback*/
	/**
	 * @brief Sets the unload process.
	 * @param[in] thisData		A pointer to a PIHandshakeData_V0100 structure which passed by <a>PIHandshakeProcType</a>().
	 * @param[in] proc			A user-supplied callback to call whenever plug-ins need to unload.
	 * @return 
	 * @note
	 */
	void					(*PIHDSetUnloadCallback)(void* thisData, PIUnloadProcType proc);						
	/* @CALLBACKEND */

	/* Data for plug-in platform */
	PIHDPltfmData			*pPltfmData;

} PIHandshakeData_V0100;


/* @CALLBACKGROUPEND */

/* @COMMONEND */
#ifdef __cplusplus
}
#endif

#endif
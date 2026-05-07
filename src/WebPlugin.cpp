/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.

 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.

---------------------------------------------------------------------

WebPlugin.cpp

 - Defines the entry point for the DLL application, the entry point is PlugInMain.

 - This plugin provides embedded web browser functionality with domain whitelist.

*********************************************************************/

#include "stdafx.h"
#include "WebPlugin.h"
#include "WebBrowserDlg.h"
#include "ConfigManager.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWebPluginApp

BEGIN_MESSAGE_MAP(CWebPluginApp, CWinApp)
	//{{AFX_MSG_MAP(CWebPluginApp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebPluginApp construction

CWebPluginApp::CWebPluginApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CWebPluginApp object

CWebPluginApp theApp;

// Global config manager instance
CConfigManager g_ConfigManager;

/////////////////////////////////////////////////////////////////////////////
// Plugin Functions

/* PIExportHFTs
** ------------------------------------------------------
**/
/** 
** Create and Add the extension HFT's.
**
** @return true to continue loading plug-in,
** false to cause plug-in loading to stop.
*/
FS_BOOL PIExportHFTs(void)
{
	return TRUE;
}

/** 
The application calls this function to allow it to
<ul>
<li> Import HFTs supplied by other plug-ins.
<li> Replace functions in the HFTs you're using (where allowed).
<li> Register to receive notification events.
</ul>
*/
FS_BOOL PIImportReplaceAndRegister(void)
{
	return TRUE;
}

////////////////////////////////////////////////////////////////////
/* Plug-ins can use their Initialization procedures to hook into Foxit PDF Editor's 
	 * user interface by adding menu items, toolbar buttons, windows, and so on.
	 * It is also acceptable to modify Foxit PDF Editor's user interface later when the plug-in is running.
	 */
void PILoadMenuBarUI(void* pParentWnd)
{

}

void PIReleaseMenuBarUI(void* pParentWnd)
{

}

//////////////////////////////////////////////////////////
void PILoadToolBarUI(void* pParentWnd)
{

}

void PIReleaseToolBarUI(void* pParentWnd)
{

}

// Open Web Browser Dialog
void OpenWebBrowserDlgProc(void* pData)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HWND hWnd = FRAppGetMainFrameWnd();
	
	// Get URL from config or use default
	CString strDefaultURL = g_ConfigManager.GetDefaultURL();
	
	CWebBrowserDlg dlg(CWnd::FromHandle(hWnd), strDefaultURL);
	dlg.DoModal();
}

void PILoadRibbonUI(void* pParentWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	FR_RibbonBar fr_Bar = FRAppGetRibbonBar(pParentWnd);
	if (!fr_Bar) return;

	// Create a new category for WebPlugin
	FR_RibbonCategory fr_Category = FRRibbonBarAddCategory(fr_Bar, "WebPlugin_Category", 
		(FS_LPCWSTR)L"Web Browser");

	if (!fr_Category) return;

	// Create a panel
	FR_RibbonPanel fr_Panel = FRRibbonCategoryAddPanel(fr_Category, "WebPlugin_Panel", 
		(FS_LPCWSTR)L"Web Browser", NULL);

	if (!fr_Panel) return;

	// Add Open Browser button
	FR_RibbonButton fr_Button = (FR_RibbonButton)FRRibbonPanelAddElement(fr_Panel, 
		FR_RIBBON_BUTTON, "OpenWebBrowser", (FS_LPCWSTR)L"Open Browser", -1);
	
	if (fr_Button)
	{
		FRRibbonElementSetExecuteProc((FR_RibbonElement)fr_Button, OpenWebBrowserDlgProc);
	}
}

void PILoadStatusBarUI(void* pParentWnd)
{

}

/* PIInit
** ------------------------------------------------------
**/
/** 
	The main initialization routine.
	
	@return true to continue loading the plug-in, 
	false to cause plug-in loading to stop.
*/
FS_BOOL PIInit(void)
{
	// Initialize configuration manager
	if (!g_ConfigManager.LoadConfig())
	{
		// Log error but don't fail plugin load
		OutputDebugString(_T("WebPlugin: Failed to load configuration\n"));
	}
	
	return TRUE;
}

/* PIUnload
** ------------------------------------------------------
**/
/** 
	The unload routine.
	Called when your plug-in is being unloaded when the application quits.
	Use this routine to release any system resources you may have
	allocated.

	Returning false will cause an alert to display that unloading failed.
	@return true to indicate the plug-in unloaded.
*/
FS_BOOL PIUnload(void)
{
	// Cleanup configuration
	g_ConfigManager.SaveConfig();
	
	return TRUE;
}

/** PIHandshake
	function provides the initial interface between your plug-in and the application.
	This function provides the callback functions to the application that allow it to 
	register the plug-in with the application environment.

	Required Plug-in handshaking routine:
	
	@param handshakeVersion the version this plug-in works with. 
	@param handshakeData OUT the data structure used to provide the primary entry points for the plug-in. These
	entry points are used in registering the plug-in with the application and allowing the plug-in to register for 
	other plug-in services and offer its own.
	@return true to indicate success, false otherwise (the plug-in will not load).
*/
FS_BOOL PIHandshake(FS_INT32 handshakeVersion, void *handshakeData)
{
	if(handshakeVersion != HANDSHAKE_V0100)
		return FALSE;
	
	/* Cast handshakeData to the appropriate type */
	PIHandshakeData_V0100* pData = (PIHandshakeData_V0100*)handshakeData;
	
	/* Set the name we want to go by */
	pData->PIHDRegisterPlugin(pData, "WebPlugin", (FS_LPCWSTR)L"WebPlugin");

	/* If you export your own HFT, do so in here */
	pData->PIHDSetExportHFTsCallback(pData, &PIExportHFTs);
		
	/*
	** If you import plug-in HFTs, replace functionality, and/or want to register for notifications before
	** the user has a chance to do anything, do so in here.
	*/
	pData->PIHDSetImportReplaceAndRegisterCallback(pData, &PIImportReplaceAndRegister);

	/* Perform your plug-in's initialization in here */
	pData->PIHDSetInitDataCallback(pData, &PIInit);

	PIInitUIProcs initUIProcs;
	INIT_CALLBACK_STRUCT(&initUIProcs, sizeof(PIInitUIProcs));
	initUIProcs.lStructSize = sizeof(PIInitUIProcs);
	initUIProcs.PILoadMenuBarUI = PILoadMenuBarUI;
	initUIProcs.PIReleaseMenuBarUI = PIReleaseMenuBarUI;
	initUIProcs.PILoadToolBarUI = PILoadToolBarUI;
	initUIProcs.PIReleaseToolBarUI = PIReleaseToolBarUI;
	initUIProcs.PILoadRibbonUI = PILoadRibbonUI;
	initUIProcs.PILoadStatusBarUI = PILoadStatusBarUI;
	pData->PIHDSetInitUICallbacks(pData, &initUIProcs);

	/* Perform any memory freeing or state saving on "quit" in here */
	pData->PIHDSetUnloadCallback(pData, &PIUnload);

	return TRUE;
}

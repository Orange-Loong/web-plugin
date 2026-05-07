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

 - Defines the entry point for the DLL application.

 - This plugin provides embedded web browser functionality with domain whitelist.

*********************************************************************/

#include "stdafx.h"
#include "WebPlugin.h"
#include "WebBrowserDlg.h"
#include "ConfigManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWebPluginApp

BEGIN_MESSAGE_MAP(CWebPluginApp, CWinApp)
END_MESSAGE_MAP()

CWebPluginApp::CWebPluginApp()
{
}

CWebPluginApp theApp;

// Global config manager instance
CConfigManager g_ConfigManager;

/////////////////////////////////////////////////////////////////////////////
// Plugin Functions

FS_BOOL PIExportHFTs(void)
{
	return TRUE;
}

FS_BOOL PIImportReplaceAndRegister(void)
{
	return TRUE;
}

void PILoadMenuBarUI(void* pParentWnd)
{
}

void PIReleaseMenuBarUI(void* pParentWnd)
{
}

void PILoadToolBarUI(void* pParentWnd)
{
}

void PIReleaseToolBarUI(void* pParentWnd)
{
}

// Execute callback for ribbon button
void OpenWebBrowserExecuteProc(void* clientData)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HWND hWnd = FRAppGetMainFrameWnd();
	
	// Get URL from config or use default
	CString strDefaultURL = g_ConfigManager.GetDefaultURL();
	
	CWebBrowserDlg dlg(CWnd::FromHandle(hWnd), strDefaultURL);
	dlg.DoModal();
}

// Compute enabled callback - always enabled
FS_BOOL OpenWebBrowserComputeEnabledProc(void* clientData)
{
	return TRUE;
}

void PILoadRibbonUI(void* pParentWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// Get RibbonBar
	FR_RibbonBar fr_Bar = FRAppGetRibbonBar(NULL);
	if (!fr_Bar) return;

	// Create a new category for WebPlugin
	FR_RibbonCategory fr_Category = FRRibbonBarAddCategory(fr_Bar, "WebPlugin_Category", 
		(FS_LPCWSTR)L"Web Browser");
	if (!fr_Category) return;

	// Create a panel
	FR_RibbonPanel fr_Panel = FRRibbonCategoryAddPanel(fr_Category, "WebPlugin_Panel", 
		(FS_LPCWSTR)L"Browser", NULL);
	if (!fr_Panel) return;

	// Add Open Browser button using CommonControl API (more reliable)
	FR_CommonControl fr_Button = FRRibbonPanelAddControl(
		fr_Panel,
		FR_CommonControl_BUTTON,
		"OpenWebBrowser",
		(FS_LPCWSTR)L"Open Browser"
	);
	
	if (fr_Button)
	{
		// Set callbacks
		FRCommonControlSetExecuteProc(fr_Button, &OpenWebBrowserExecuteProc);
		FRCommonControlSetComputeEnabledProc(fr_Button, &OpenWebBrowserComputeEnabledProc);
	}
}

void PILoadStatusBarUI(void* pParentWnd)
{
}

FS_BOOL PIInit(void)
{
	// Initialize configuration manager
	if (!g_ConfigManager.LoadConfig())
	{
		OutputDebugString(_T("WebPlugin: Failed to load configuration\n"));
	}
	
	return TRUE;
}

FS_BOOL PIUnload(void)
{
	// Cleanup configuration
	g_ConfigManager.SaveConfig();
	
	return TRUE;
}

FS_BOOL PIHandshake(FS_INT32 handshakeVersion, void *handshakeData)
{
	if(handshakeVersion != HANDSHAKE_V0100)
		return FALSE;
	
	PIHandshakeData_V0100* pData = (PIHandshakeData_V0100*)handshakeData;
	
	// Register plugin name
	pData->PIHDRegisterPlugin(pData, "WebPlugin", (FS_LPCWSTR)L"WebPlugin");

	// Set callbacks
	pData->PIHDSetExportHFTsCallback(pData, &PIExportHFTs);
	pData->PIHDSetImportReplaceAndRegisterCallback(pData, &PIImportReplaceAndRegister);
	pData->PIHDSetInitDataCallback(pData, &PIInit);

	// Set UI callbacks
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

	// Set unload callback
	pData->PIHDSetUnloadCallback(pData, &PIUnload);

	return TRUE;
}

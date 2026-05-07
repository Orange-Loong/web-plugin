// WebBrowserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WebBrowserDlg.h"
#include "afxdialogex.h"
#include "ConfigManager.h"

// External config manager
extern CConfigManager g_ConfigManager;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserDlg dialog

IMPLEMENT_DYNAMIC(CWebBrowserDlg, CDialog)

CWebBrowserDlg::CWebBrowserDlg(CWnd* pParent, CString strDefaultURL)
	: CDialog(CWebBrowserDlg::IDD, pParent)
	, m_strDefaultURL(strDefaultURL)
	, m_pWebBrowser(NULL)
	, m_bIsNavigating(FALSE)
{
	m_strCurrentDomain = _T("");
}

CWebBrowserDlg::~CWebBrowserDlg()
{
	if (m_pWebBrowser)
	{
		m_pWebBrowser->Release();
		m_pWebBrowser = NULL;
	}
}

void CWebBrowserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWebBrowserDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_GO, &CWebBrowserDlg::OnBnClickedBtnGo)
	ON_BN_CLICKED(IDC_BTN_BACK, &CWebBrowserDlg::OnBnClickedBtnBack)
	ON_BN_CLICKED(IDC_BTN_FORWARD, &CWebBrowserDlg::OnBnClickedBtnForward)
	ON_BN_CLICKED(IDC_BTN_REFRESH, &CWebBrowserDlg::OnBnClickedBtnRefresh)
	ON_BN_CLICKED(IDC_BTN_STOP, &CWebBrowserDlg::OnBnClickedBtnStop)
	ON_EN_CHANGE(IDC_EDIT_URL, &CWebBrowserDlg::OnEnChangeEditUrl)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserDlg message handlers

BOOL CWebBrowserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Initialize COM
	CoInitialize(NULL);
	
	// Initialize web browser control
	if (!InitWebBrowser())
	{
		ShowError(_T("Failed to initialize web browser control"));
		return FALSE;
	}
	
	// Set default URL
	m_wndUrlEdit.SetWindowText(m_strDefaultURL);
	
	// Navigate to default URL if valid
	if (!m_strDefaultURL.IsEmpty())
	{
		NavigateToURL(m_strDefaultURL);
	}
	
	return TRUE;
}

// Initialize WebBrowser control
BOOL CWebBrowserDlg::InitWebBrowser()
{
	// Get the browser control window
	CWnd* pBrowserWnd = GetDlgItem(IDC_EXPLORER1);
	if (!pBrowserWnd)
	{
		return FALSE;
	}
	
	// Get the IWebBrowser2 interface
	HWND hBrowserWnd = pBrowserWnd->m_hWnd;
	if (!hBrowserWnd)
	{
		return FALSE;
	}
	
	// Get the automation interface
	LPDISPATCH pDispatch = NULL;
	pBrowserWnd->GetControlUnknown()->QueryInterface(IID_IDispatch, (void**)&pDispatch);
	if (!pDispatch)
	{
		return FALSE;
	}
	
	// Get IWebBrowser2 interface
	HRESULT hr = pDispatch->QueryInterface(IID_IWebBrowser2, (void**)&m_pWebBrowser);
	pDispatch->Release();
	
	if (FAILED(hr))
	{
		return FALSE;
	}
	
	// Set browser properties
	if (m_pWebBrowser)
	{
		m_pWebBrowser->put_Silent(VARIANT_TRUE); // Disable script errors
	}
	
	return TRUE;
}

// Navigate to URL
BOOL CWebBrowserDlg::NavigateToURL(const CString& strURL)
{
	if (!m_pWebBrowser || strURL.IsEmpty())
	{
		return FALSE;
	}
	
	// Check if navigation is allowed
	if (!IsNavigationAllowed(strURL))
	{
		CString strMsg;
		strMsg.Format(_T("Navigation to %s is not allowed.\nOnly configured domains are permitted."), 
			ExtractDomain(strURL));
		ShowError(strMsg);
		return FALSE;
	}
	
	// Convert URL to BSTR
	CString strURLToNavigate = strURL;
	
	// Add http:// if no protocol specified
	if (strURLToNavigate.Find(_T("://")) == -1)
	{
		strURLToNavigate = _T("http://") + strURLToNavigate;
	}
	
	BSTR bstrURL = strURLToNavigate.AllocSysString();
	
	// Navigate
	VARIANT vFlags, vTargetFrame, vPostData, vHeaders;
	VariantInit(&vFlags);
	VariantInit(&vTargetFrame);
	VariantInit(&vPostData);
	VariantInit(&vHeaders);
	
	HRESULT hr = m_pWebBrowser->Navigate(bstrURL, &vFlags, &vTargetFrame, &vPostData, &vHeaders);
	
	SysFreeString(bstrURL);
	
	if (SUCCEEDED(hr))
	{
		m_bIsNavigating = TRUE;
		m_strCurrentDomain = ExtractDomain(strURL);
		UpdateNavButtons();
	}
	
	return SUCCEEDED(hr);
}

// Check if navigation is allowed
BOOL CWebBrowserDlg::IsNavigationAllowed(const CString& strURL)
{
	return g_ConfigManager.IsDomainAllowed(strURL);
}

// Extract domain from URL
CString CWebBrowserDlg::ExtractDomain(const CString& strURL)
{
	CString strDomain = strURL;
	strDomain.MakeLower();
	
	// Remove protocol
	int nPos = strDomain.Find(_T("://"));
	if (nPos != -1)
	{
		strDomain = strDomain.Mid(nPos + 3);
	}
	
	// Remove path
	nPos = strDomain.Find(_T("/"));
	if (nPos != -1)
	{
		strDomain = strDomain.Left(nPos);
	}
	
	// Remove port
	nPos = strDomain.Find(_T(":"));
	if (nPos != -1)
	{
		strDomain = strDomain.Left(nPos);
	}
	
	return strDomain;
}

// Get current URL
CString CWebBrowserDlg::GetCurrentURL() const
{
	if (!m_pWebBrowser)
	{
		return _T("");
	}
	
	BSTR bstrURL = NULL;
	if (SUCCEEDED(m_pWebBrowser->get_LocationURL(&bstrURL)))
	{
		CString strURL(bstrURL);
		SysFreeString(bstrURL);
		return strURL;
	}
	
	return _T("");
}

// Update navigation buttons state
void CWebBrowserDlg::UpdateNavButtons()
{
	if (!m_pWebBrowser)
	{
		return;
	}
	
	// Update back button
	VARIANT_BOOL bCanGoBack;
	m_pWebBrowser->get_Back(&bCanGoBack);
	m_wndBtnBack.EnableWindow(bCanGoBack == VARIANT_TRUE);
	
	// Update forward button
	VARIANT_BOOL bCanGoForward;
	m_pWebBrowser->get_Forward(&bCanGoForward);
	m_wndBtnForward.EnableWindow(bCanGoForward == VARIANT_TRUE);
	
	// Update stop button
	m_wndBtnStop.EnableWindow(m_bIsNavigating);
}

void CWebBrowserDlg::OnBnClickedBtnGo()
{
	UpdateData(TRUE);
	
	CString strURL;
	m_wndUrlEdit.GetWindowText(strURL);
	
	if (!strURL.IsEmpty())
	{
		NavigateToURL(strURL);
	}
}

void CWebBrowserDlg::OnBnClickedBtnBack()
{
	if (m_pWebBrowser)
	{
		m_pWebBrowser->GoBack();
	}
}

void CWebBrowserDlg::OnBnClickedBtnForward()
{
	if (m_pWebBrowser)
	{
		m_pWebBrowser->GoForward();
	}
}

void CWebBrowserDlg::OnBnClickedBtnRefresh()
{
	if (m_pWebBrowser)
	{
		m_pWebBrowser->Refresh();
	}
}

void CWebBrowserDlg::OnBnClickedBtnStop()
{
	if (m_pWebBrowser)
	{
		m_pWebBrowser->Stop();
		m_bIsNavigating = FALSE;
		UpdateNavButtons();
	}
}

void CWebBrowserDlg::OnEnChangeEditUrl()
{
	// Could add URL validation here
}

void CWebBrowserDlg::OnDestroy()
{
	if (m_pWebBrowser)
	{
		m_pWebBrowser->Stop();
		m_pWebBrowser->Release();
		m_pWebBrowser = NULL;
	}
	
	CoUninitialize();
	
	CDialog::OnDestroy();
}

// Show error message
void CWebBrowserDlg::ShowError(const CString& strMessage)
{
	MessageBox(strMessage, _T("WebPlugin Error"), MB_OK | MB_ICONERROR);
}

LRESULT CWebBrowserDlg::OnDocumentComplete(WPARAM wParam, LPARAM lParam)
{
	m_bIsNavigating = FALSE;
	UpdateNavButtons();
	
	// Update URL in edit box
	CString strCurrentURL = GetCurrentURL();
	if (!strCurrentURL.IsEmpty())
	{
		m_wndUrlEdit.SetWindowText(strCurrentURL);
	}
	
	return 0;
}

LRESULT CWebBrowserDlg::OnNavigateComplete(WPARAM wParam, LPARAM lParam)
{
	m_bIsNavigating = FALSE;
	UpdateNavButtons();
	
	return 0;
}

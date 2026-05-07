#ifndef WEBBROWSERDLG_H
#define WEBBROWSERDLG_H

#pragma once

#include <exdisp.h>

// WebBrowserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWebBrowserDlg dialog

class CWebBrowserDlg : public CDialog
{
	DECLARE_DYNAMIC(CWebBrowserDlg)

public:
	CWebBrowserDlg(CWnd* pParent = NULL, CString strDefaultURL = _T(""));
	virtual ~CWebBrowserDlg();

// Dialog Data
	enum { IDD = IDD_WEBBROWSER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnGo();
	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnBnClickedBtnForward();
	afx_msg void OnBnClickedBtnRefresh();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnDestroy();

	// Navigate to URL with domain checking
	BOOL NavigateToURL(const CString& strURL);
	// Get current URL
	CString GetCurrentURL() const;
	// Check if navigation is allowed
	BOOL IsNavigationAllowed(const CString& strURL);

private:
	// Initialize web browser control
	BOOL InitWebBrowser();
	// Update navigation buttons state
	void UpdateNavButtons();
	// Extract domain from URL
	CString ExtractDomain(const CString& strURL);
	// Show error message
	void ShowError(const CString& strMessage);

private:
	CString m_strDefaultURL;
	IWebBrowser2* m_pWebBrowser;
	BOOL m_bIsNavigating;
	CString m_strCurrentDomain;

	// Controls
	CEdit m_wndUrlEdit;
	CButton m_wndBtnGo;
	CButton m_wndBtnBack;
	CButton m_wndBtnForward;
	CButton m_wndBtnRefresh;
	CButton m_wndBtnStop;
};

#endif // WEBBROWSERDLG_H

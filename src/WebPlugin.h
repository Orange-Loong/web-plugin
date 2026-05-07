#ifndef WEBPLUGIN_H
#define WEBPLUGIN_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWebPluginApp
// See WebPlugin.cpp for the implementation of this class
//

class CWebPluginApp : public CWinApp
{
public:
	CWebPluginApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebPluginApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CWebPluginApp)
		// NOTE - the ClassWizard will add and member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBPLUGIN_H__INCLUDED_)

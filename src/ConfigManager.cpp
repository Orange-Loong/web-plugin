#include "stdafx.h"
#include "ConfigManager.h"
#include <fstream>
#include <shlwapi.h>

#pragma comment(lib, "shlwapi.lib")

CConfigManager::CConfigManager()
{
	m_bEnabled = TRUE;
	m_strDefaultURL = _T("https://www.example.com");
}

CConfigManager::~CConfigManager()
{
	// Cleanup domain list
	for (int i = 0; i < m_arrDomains.GetSize(); i++)
	{
		delete m_arrDomains.GetAt(i);
	}
	m_arrDomains.RemoveAll();
}

// Get plugin directory
CString CConfigManager::GetPluginDir() const
{
	HMODULE hModule = GetModuleHandle(NULL);
	if (hModule)
	{
		wchar_t szPath[MAX_PATH];
		GetModuleFileName(hModule, szPath, MAX_PATH);
		PathRemoveFileSpec(szPath);
		return CString(szPath);
	}
	return _T("");
}

// Get config file path
CString CConfigManager::GetConfigFilePath() const
{
	CString strPluginDir = GetPluginDir();
	CString strConfigPath;
	
	// Try to find config in plugin directory first
	strConfigPath = strPluginDir + _T("\\config\\domains.json");
	
	// If not found, try application directory
	if (!PathFileExists(strConfigPath))
	{
		wchar_t szAppPath[MAX_PATH];
		GetModuleFileName(NULL, szAppPath, MAX_PATH);
		PathRemoveFileSpec(szAppPath);
		strConfigPath = CString(szAppPath) + _T("\\config\\domains.json");
	}
	
	return strConfigPath;
}

// Load configuration from JSON file
BOOL CConfigManager::LoadConfig()
{
	CString strConfigPath = GetConfigFilePath();
	
	// If config file doesn't exist, create default
	if (!PathFileExists(strConfigPath))
	{
		// Create config directory
		CString strConfigDir = strConfigPath.Left(strConfigPath.ReverseFind(_T('\\')));
		CreateDirectory(strConfigDir, NULL);
		
		// Create default config
		SaveConfig();
		return TRUE;
	}
	
	// Read config file
	std::ifstream file(strConfigPath);
	if (!file.is_open())
	{
		OutputDebugString(_T("WebPlugin: Cannot open config file\n"));
		return FALSE;
	}
	
	// Read file content
	std::string strContent((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());
	file.close();
	
	return ParseConfigFile(CString(strContent.c_str()));
}

// Parse JSON config content
BOOL CConfigManager::ParseConfigFile(const CString& strContent)
{
	// Simple JSON parser for our config format
	// Format: { "enabled": true, "defaultURL": "...", "domains": ["..."] }
	
	// Clear existing domains
	for (int i = 0; i < m_arrDomains.GetSize(); i++)
	{
		delete m_arrDomains.GetAt(i);
	}
	m_arrDomains.RemoveAll();
	
	// Parse enabled
	if (strContent.Find(_T("\"enabled\":")) != -1)
	{
		int nEnabledPos = strContent.Find(_T("\"enabled\":"));
		int nValuePos = nEnabledPos + 9;
		CString strValue = strContent.Mid(nValuePos, 10);
		strValue.Trim();
		m_bEnabled = (strValue.Left(4) == _T("true"));
	}
	
	// Parse defaultURL
	if (strContent.Find(_T("\"defaultURL\":")) != -1)
	{
		int nURLPos = strContent.Find(_T("\"defaultURL\":"));
		int nQuote1 = strContent.Find(_T("\""), nURLPos + 12);
		int nQuote2 = strContent.Find(_T("\""), nQuote1 + 1);
		if (nQuote1 != -1 && nQuote2 != -1)
		{
			m_strDefaultURL = strContent.Mid(nQuote1 + 1, nQuote2 - nQuote1 - 1);
		}
	}
	
	// Parse domains array
	int nDomainsPos = strContent.Find(_T("\"domains\":"));
	if (nDomainsPos != -1)
	{
		int nArrayStart = strContent.Find(_T("["), nDomainsPos);
		int nArrayEnd = strContent.Find(_T("]"), nArrayStart);
		
		if (nArrayStart != -1 && nArrayEnd != -1)
		{
			CString strDomains = strContent.Mid(nArrayStart + 1, nArrayEnd - nArrayStart - 1);
			
			// Extract each domain
			int nPos = 0;
			while (nPos < strDomains.GetLength())
			{
				int nQuote1 = strDomains.Find(_T("\""), nPos);
				if (nQuote1 == -1) break;
				
				int nQuote2 = strDomains.Find(_T("\""), nQuote1 + 1);
				if (nQuote2 == -1) break;
				
				CString strDomain = strDomains.Mid(nQuote1 + 1, nQuote2 - nQuote1 - 1);
				strDomain.Trim();
				
				if (!strDomain.IsEmpty())
				{
					DomainConfig* pDomain = new DomainConfig();
					pDomain->strDomain = strDomain;
					pDomain->bEnabled = TRUE;
					m_arrDomains.Add(pDomain);
				}
				
				nPos = nQuote2 + 1;
			}
		}
	}
	
	return TRUE;
}

// Generate JSON config content
CString CConfigManager::GenerateConfigContent() const
{
	CString strContent;
	strContent.Format(_T("{\n  \"enabled\": %s,\n  \"defaultURL\": \"%s\",\n  \"domains\": [\n"),
		m_bEnabled ? _T("true") : _T("false"),
		m_strDefaultURL);
	
	// Add domains
	for (int i = 0; i < m_arrDomains.GetSize(); i++)
	{
		DomainConfig* pDomain = m_arrDomains.GetAt(i);
		if (i > 0) strContent += _T(",\n");
		strContent.AppendFormat(_T("    \"%s\""), pDomain->strDomain);
	}
	
	strContent += _T("\n  ]\n}\n");
	return strContent;
}

// Save configuration to file
BOOL CConfigManager::SaveConfig()
{
	CString strConfigPath = GetConfigFilePath();
	CString strConfigDir = strConfigPath.Left(strConfigPath.ReverseFind(_T('\\')));
	
	// Create config directory if not exists
	CreateDirectory(strConfigDir, NULL);
	
	// Generate config content
	CString strContent = GenerateConfigContent();
	
	// Write to file
	std::ofstream file(strConfigPath);
	if (!file.is_open())
	{
		OutputDebugString(_T("WebPlugin: Cannot create config file\n"));
		return FALSE;
	}
	
	file << (CStringA)strContent;
	file.close();
	
	return TRUE;
}

// Get domain by index
DomainConfig* CConfigManager::GetDomain(int nIndex)
{
	if (nIndex >= 0 && nIndex < m_arrDomains.GetSize())
	{
		return m_arrDomains.GetAt(nIndex);
	}
	return NULL;
}

// Add new domain
BOOL CConfigManager::AddDomain(const CString& strDomain)
{
	// Check if domain already exists
	for (int i = 0; i < m_arrDomains.GetSize(); i++)
	{
		if (m_arrDomains.GetAt(i)->strDomain == strDomain)
		{
			return FALSE; // Already exists
		}
	}
	
	DomainConfig* pDomain = new DomainConfig();
	pDomain->strDomain = strDomain;
	pDomain->bEnabled = TRUE;
	m_arrDomains.Add(pDomain);
	
	return TRUE;
}

// Remove domain by index
BOOL CConfigManager::RemoveDomain(int nIndex)
{
	if (nIndex >= 0 && nIndex < m_arrDomains.GetSize())
	{
		delete m_arrDomains.GetAt(nIndex);
		m_arrDomains.RemoveAt(nIndex);
		return TRUE;
	}
	return FALSE;
}

// Set domain enabled status
BOOL CConfigManager::SetDomainEnabled(int nIndex, BOOL bEnabled)
{
	if (nIndex >= 0 && nIndex < m_arrDomains.GetSize())
	{
		m_arrDomains.GetAt(nIndex)->bEnabled = bEnabled;
		return TRUE;
	}
	return FALSE;
}

// Check if URL domain is allowed
BOOL CConfigManager::IsDomainAllowed(const CString& strURL)
{
	if (!m_bEnabled)
		return FALSE;
	
	// Extract domain from URL
	CString strURLLower = strURL;
	strURLLower.MakeLower();
	
	// Remove protocol
	int nProtocolPos = strURLLower.Find(_T("://"));
	if (nProtocolPos != -1)
	{
		strURLLower = strURLLower.Mid(nProtocolPos + 3);
	}
	
	// Remove path
	int nPathPos = strURLLower.Find(_T("/"));
	if (nPathPos != -1)
	{
		strURLLower = strURLLower.Left(nPathPos);
	}
	
	// Remove port
	int nPortPos = strURLLower.Find(_T(":"));
	if (nPortPos != -1)
	{
		strURLLower = strURLLower.Left(nPortPos);
	}
	
	// Check against allowed domains
	for (int i = 0; i < m_arrDomains.GetSize(); i++)
	{
		DomainConfig* pDomain = m_arrDomains.GetAt(i);
		if (pDomain->bEnabled && MatchDomain(strURLLower, pDomain->strDomain))
		{
			return TRUE;
		}
	}
	
	return FALSE;
}

// Match URL domain against pattern (supports wildcards)
BOOL CConfigManager::MatchDomain(const CString& strURL, const CString& strPattern)
{
	CString strPatternLower = strPattern;
	strPatternLower.MakeLower();
	
	// Simple wildcard matching
	// *.example.com matches www.example.com, api.example.com, etc.
	if (strPatternLower.GetAt(0) == _T('*'))
	{
		CString strSuffix = strPatternLower.Mid(2); // Skip "*."
		return strURL.Right(strSuffix.GetLength()) == strSuffix;
	}
	
	return strURL == strPatternLower;
}

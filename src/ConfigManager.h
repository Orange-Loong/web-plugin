#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#pragma once

#include <windows.h>
#include <atlstr.h>
#include <vector>

// Configuration structure
struct DomainConfig
{
	CString strDomain;
	BOOL bEnabled;
};

// Main configuration class
class CConfigManager
{
public:
	CConfigManager();
	~CConfigManager();

	// Load configuration from file
	BOOL LoadConfig();

	// Save configuration to file
	BOOL SaveConfig();

	// Check if a URL matches any allowed domain
	BOOL IsDomainAllowed(const CString& strURL);

	// Get/Set enabled status
	BOOL IsEnabled() const { return m_bEnabled; }
	void SetEnabled(BOOL bEnabled) { m_bEnabled = bEnabled; }

	// Get default URL
	CString GetDefaultURL() const { return m_strDefaultURL; }
	void SetDefaultURL(const CString& strURL) { m_strDefaultURL = strURL; }

	// Domain list management
	int GetDomainCount() const { return m_arrDomains.GetSize(); }
	DomainConfig* GetDomain(int nIndex);
	BOOL AddDomain(const CString& strDomain);
	BOOL RemoveDomain(int nIndex);
	BOOL SetDomainEnabled(int nIndex, BOOL bEnabled);

	// Get plugin directory
	CString GetPluginDir() const;

private:
	// Internal helpers
	CString GetConfigFilePath() const;
	BOOL ParseConfigFile(const CString& strContent);
	CString GenerateConfigContent() const;
	BOOL MatchDomain(const CString& strURL, const CString& strPattern);

private:
	BOOL m_bEnabled;
	CString m_strDefaultURL;
	CTypedPtrArray<CPtrArray, DomainConfig*> m_arrDomains;
};

#endif // CONFIGMANAGER_H

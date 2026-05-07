#ifndef frd_PluginsManager_h__
#define frd_PluginsManager_h__
#include "pluginsdk/include/basic/fs_pidata.h"
#include "FoxitReader/frd_PlgsMgrExportTypes.h"
#include <set>

#define PluginsManager CReader_PluginsManager::GetInstance()

//从7.0开始，不对7.0以前的版本做兼容，但是7.0版本以后，还是要尽量保持这种兼容规则。
//3.0.0.0
#define LOWEST_COMPATIBLE_VERSION ((FS_INT32)((3L<<24) + (0L<<16) + (0L<<8) + 0L))

//从7.3开始，去掉经典模式,因此要控制在IE下不加载7.3以前的插件,否则可能在IE添加不可预知的ribbon按钮,引起功能问题.
//7.3.0.0
#define LOWEST_COMPATIBLE_VERSION_IE ((FS_INT32)((7L<<24) + (3L<<16) + (0L<<8) + 0L))

class JSPluginData;

class CReader_PluginsManager
{
	// 不能使用CFX_WideString代替CString，否则无排序效果
	typedef std::set<CString> SET_LOADED_LIBPATH;

public:
	static CReader_PluginsManager& GetInstance()
	{
		static CReader_PluginsManager instance;
		return instance;
	}
	~CReader_PluginsManager(void);

	static BOOL LoadPlugin(void* arrLibPath, BOOL bFreeLibWhenFailed = FALSE);
	static void SetOnAboutPluginsProc(PIOnAboutPluginsProcType proc);
	static int GetLastPluginLoadError();
	static BOOL IsPluginDisabledBy(LPCTSTR lpszPlgFileName);
	static void SetOnDelayLoadJSPluginsCallback(PIOnDelayLoadJSPluginsProcType proc);
	static BOOL LoadPluginUI(HWND hParentWnd, void* arrLibPath);

	// Main entry
	void LoadPlugins();

	BOOL LoadAndInitPlugin(
		HWND hFrame,
		VEC_TOLOAD_PLGPATH& vecToloadPlgPath, 
		BOOL bSysLevelorPltfm = FALSE);
	void UnloadPlugins();
	void UnLoadOutwardPlugins();
	PluginData* GetPluginData(const CFX_WideString& wsPID);
	void FreeFailedPlugin(const CFX_WideString& csLibrary_Path);
	void FreePlugins();
	int GetSize();
	PluginData* GetAt(int nIndex);
	PluginData* GetPluginDataByName(const CFX_ByteString& bsName);
	// Show plugins' info in a dialog.
	void OnAboutPlugins();
	void OnDelayLoadJSPlugins(BOOL bSlient = TRUE, CWnd* pWnd = NULL);
	// Record crashed plugin info.
	void RecordCrashedPluginInfo(LPCTSTR pcszFileName, LPCTSTR pcszFilePath);

	// add by ykw 2014-4-28，IE单实例调整，将UI的初始化从数据初始化中分离出来
	void LoadMenuBarUI(CWnd* pParentWnd);
	void LoadToolBarUI(CWnd* pParentWnd);
	void LoadRibbonUI(CWnd* pParentWnd);
	void ReleaseRibbonUI(CWnd* pParentWnd);

	void LoadStatusBarUI(CWnd* pParentWnd);
	void ReleaseStatusBarUI(CWnd* pParentWnd);
	
	void ReleaseToolbarUI(CWnd* pParentWnd);
	void ReleaseMenubarUI(CWnd* pParentWnd);

	//#11353-FXNET-HCM 2018-0710 延迟加载,处理主程序启动慢问题
	void LoadRibbonUIByPlugName(CWnd* pParentWnd, CFX_ByteString csName);
	//#11353-FXNET-HCM 2018-0710 延迟加载,处理主程序启动慢问题
	void DoLoadRibbonUIByPlugName(CWnd* pParentWnd, BOOL bInternal, CFX_ByteString csName);
	//#7392-END-FXNET-HCM 升级方案改后，主程序启动慢

#if defined(FXNET_FRD_PLUS) || defined(FXNET_FRD) || defined(FXNET_FPM_PER)
	//#7392-BEGIN-FXNET-HCM 升级方案改后，主程序启动慢
	//#11353-FXNET-HCM 2018-0710 延迟加载,处理主程序启动慢问题
	void LoadStatusBarUIByPlugName(CWnd* pParentWnd, CFX_ByteString csName);	
#endif
	// end add

	void RegisterPluginEventHandler(IPlugin_EventHandler* pHandler);
	void UnRegisterPluginEventHandler(IPlugin_EventHandler* pHandler);
	//获取当前加载的插件列表信息，给AI插件服务端使用
	//vector<PluginDataMini> GetLoadPluginDatas();

private:
	// Ctor
	CReader_PluginsManager();

	// Load system-level plugins, like "Updater.fpi"...
	void LoadSysLevelPlugins();
	// Load plugin platform, "PlgPltfm.fpi"
	void LoadPluginPlatform();
	// Get the directory path where we hold default plugins.
	CFX_WideString GetPluginsDirPath();
	//验证plugin的完整性
	BOOL CheckPluginIntegrity(CFR_PISmplCert* pCert, const CFX_WideString& wsPluginPath, const CFX_ByteString& bsDigest);
	//检查证书是否合法
	BOOL CheckCertificate(CFR_PISmplCert* pCert);
	BOOL IsSNExist(const CFX_WideString& wsSN, CFX_WideString& wsUsedPlg)const;
	void GetPIVersion(HINSTANCE hInst, int& nMajor, int& nMinor, int& nRevision, int& nBuild);	
	PluginData* ValidatePlugin(const PLUGIN_PATH& pluginPath);
	BOOL ValidateInternalPlgToken(PluginData* pPlugin);
	BOOL ValidatePluginSN(HINSTANCE hDLL, const CFX_WideString& csLibrary_Path, PluginData* pPlugin);
	BOOL BuildupPlugin( std::vector<PluginData*>& vecPluginData );
	BOOL DoPIHandshake(PluginData* pPluginData);
	BOOL DoPIExportHFTs(PluginData* pPluginData);
	BOOL DoPIImportReplaceAndRegister(PluginData* pPluginData);
	BOOL DoPIInit(PluginData* pPluginData);
	void DoPIUnload(PluginData* pPluginData);
	void UnloadFailedPI();
	BOOL IsLoadingPlgPltfm();
	PluginData* GetPluginDataBySN(const CFX_WideString& wsSN);
	PluginData* GetPluginDataByLibPath(const CFX_WideString& wsLibPath);

	CFX_WideString GetFileNameFromPath(const CFX_WideString& strPlgPath);
	BOOL IsLoadedPlugin(const CFX_WideString& csLibrary_Path);
	void AddtoSET_LOADED_LIBPATH(const CFX_WideString& csLibrary_Path);
	void DelfromSET_LOADED_LIBPATH(const CFX_WideString& csLibrary_Path);
	BOOL NoPluinLoaded();
	void SetLastPluginLoadError(PLUGIN_LOAD_ERROR ple);
	BOOL IsPluginDisabled(LPCTSTR lpszPlgFileName);

	// 成员函数指针
	typedef BOOL (CReader_PluginsManager::*pPIOperationFun)(PluginData* pPluginData);
	void DoPIOperation(
		pPIOperationFun pPIOpera, 
		std::vector<PluginData*>& vecPluginData, 
		BOOL& bResult, PLUGIN_LOAD_ERROR ple);

	bool UptoMinVersion( HINSTANCE hDLL, const CString& strMinVersion);
	void OnInnerPluginsLoadFinish(CWnd* pParentWnd);

	void LoadUI_InstallingPlug(const CFX_WideString& csLibrary_Path);
	void UIAdjust_InstallingPlug();

	void CreateEncryptedToken();

	PluginData* ValidateJSPlugin(const PLUGIN_PATH& pluginPath);
	BOOL BuildupJSPlugin(PluginData *pPluginData);
	void ParseManifestFile(CString csJSManifestFile, PluginData *pPluginData, JSPluginData* pJSPluginData, CFX_WideStringArray& arrJSFile);
	CFX_WideString ExtractJSTextFromFile(CFX_WideStringArray* arrJSFile);

	void DoLoadRibbonUI(CWnd* pParentWnd, BOOL bInternal);
	BOOL DoLoadRibbonUI(HWND hParentWnd, CFX_WideString strPluginPathName);
	BOOL DoLoadJSRibbonUI(HWND hParentWnd, CFX_WideString strPluginPathName);
	BOOL DoLoadRibbonUI(HWND hParentWnd, VEC_TOLOAD_PLGPATH& vecToloadPlgPath);

	std::vector<int> splitVersion(const std::string& version);
	int compareVersion(const CFX_ByteString version1, const CFX_ByteString version2);

private:
	// All loaded plug-ins' detailed information container.
	CTypedPtrArray<CPtrArray, PluginData*> m_lsPlugins;
	// Indicating whether loading the plugin platform or platform extension.
	BOOL m_bLoadingPlgPltfm;
	// 已加载的lib路径集合，为了加快查找而使用容器std::set。
	SET_LOADED_LIBPATH m_setLoadedLibPath;
	// 最近一个插件的加载错误
	PLUGIN_LOAD_ERROR m_lastPLError;
	// Source token
	CString m_strSourceToken;
	// Encrypted token
	CString m_strEncryptedToken;

	static PIOnAboutPluginsProcType s_pOnAboutPluginsProc;
	static PIOnDelayLoadJSPluginsProcType s_pOnDelayLoadJSPluginsProc;
	static LPCSTR s_szTokenKey;

	std::vector<std::unique_ptr<IPlugin_EventHandler>> m_plgEventHandlerList;
};

#endif // frd_PluginsManager_h__


#ifndef FS_COMMONIMPL_H
#define FS_COMMONIMPL_H

//
// #ifndef FR_COMMON_H
// #include "../../include/basic/fr_common.h"
// #endif


#ifndef FS_INTERNALINC_H
#include "../fs_internalInc.h"
#endif

#ifndef FS_CALLSINCLUDE_H
//#include "../fs_callsInclude.h"
#endif



#ifdef __cplusplus
extern "C"{
#endif

extern void InitInterfaceMgr_sdk1();
extern void ReleaseHFTMgr();

extern FRCoreHFTMgr* GetCoreInterfaceMgr();

#ifdef SDK_VERSION_1_SELECTED
#define InitInterfaceMgr InitInterfaceMgr_sdk1
#endif


#ifndef CFR_COREHFTMGR
#define CFR_COREHFTMGR

// abstract type for function pointer.
struct __FUNCTION { };
typedef __FUNCTION* FUNC;



typedef struct ReplacedEntryRec{
	void* proc;
	ReplacedEntryRec* next;

	ReplacedEntryRec()
	{
		proc = NULL; next = NULL;
	}
}ReplacedEntry;

typedef struct ReplacedListHeaderRec{
	FS_INT32 hftSEL;
	ReplacedListHeaderRec* prev;
	ReplacedListHeaderRec* next;
	ReplacedEntryRec* pProcList;
	ReplacedListHeaderRec()
	{
		hftSEL = -1;
		prev = NULL;
		next = NULL;
		pProcList = NULL;
	}
	
	
}ReplacedListHeader;

class CFR_HFT : public CFX_Object
{
public:
	CFR_HFT(FS_INT32 nFuncs, FS_INT32 iSel);
	~CFR_HFT();
	
	void	SetFuncAt(FS_INT32 index, void* pFunc);
	void*	GetFuncAt(FS_INT32 index);
	void*	GetReplacedFunc(FS_INT32 index, void* thisProc);
	void	ReplaceFuncAt(FS_INT32 index, void* pFunc);
protected:
	ReplacedListHeader* m_pReplacedMap; //the header, must be the minimize hft selector.
	FS_INT32 m_nFuncs;
	std::unique_ptr<FUNC[]> m_pFuncList;
	FS_INT32 m_iSel;
private:
	void	InitFuncList(FS_INT32 nFuncs);
	void	FreeReplacement();
};

class CFR_CoreHFTMgr : public CFX_Object
{
public:
	static CFR_CoreHFTMgr* GetMgr();
	CFR_HFT* GetHFT(FS_INT32 iHFTSel);
	void	Release();

	FS_BOOL	UpdateInterface(FS_INT32 iHFTSel, FS_INT32 iInterfaceSel, void* pFunc);
	void*	QueryInterface(FS_INT32 iHFTSel, FS_INT32 iInterfaceSel, void* wsPID);
	void	SetHFT(FS_INT32 iHFTSel, void* pHFT);

protected:
	CFR_CoreHFTMgr();
	~CFR_CoreHFTMgr();
private:	
	CFR_HFT** m_pHFTList;
	static FS_INT32 m_nHFTs;
	static CFR_CoreHFTMgr* m_pCoreHFTMgr;
};

#endif //CCore_MAPPING_TABLE

#ifndef CFR_PLUGINMGR
#define CFR_PLUGINMGR



class CFR_PluginMgr : public CFX_Object
{
public:
	static CFR_PluginMgr *GetMgr();
	void Release();
protected:
	CFR_PluginMgr();
	~CFR_PluginMgr();
	
public:
	CFR_HFT* NewHFT(FS_INT32 numOfIntefaces);
	FS_INT32 AddHFT(const FS_CHAR* hftName, FS_INT32 version, CFR_HFT* pHFT);
	CFR_HFT* QueryHFT(const FS_CHAR* hftName, FS_INT32 version, FS_LPCWSTR csPluginName = L"");
	
private:
	CFX_ByteString BuildKey(const FS_CHAR* categoryName, FS_INT32 version);
	CFX_MapByteStringToPtr m_mapHFT;	
	static CFR_PluginMgr *m_pMgr;
	static FS_INT32 m_nCurrentMaxHFTSel;
};
#endif



#ifdef __cplusplus
};
#endif

#endif
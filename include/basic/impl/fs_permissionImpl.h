#ifndef FS_PERMISSIONIMPL_H
#define FS_PERMISSIONIMPL_H

#include "../fs_internalInc.h"
#include "fs_commonImpl.h"
#include "../../pdf/fpd_serialExpT.h"

#define HFT_Per_PageContentEdit				0x00000001
#define HFT_Per_PageContentExtract			0x00000002
#define HFT_Per_DocEdit						0x00000004
#define HFT_Per_Rendering					0x00000008

#define HFT_Per_Annotation					0x00000010
#define HFT_Per_InterForm                   0x00000020
#define HFT_Per_Security					0x00000040
#define HFT_Per_PDCreator					0x00000080

#define HFT_Per_StreamW						0x00000100

//#define OUTPUTINTERFACE 1
#define Plug_to_Export "Prot-On"
//#define Plug_to_Export "DRM"

struct PluginData;
class CFR_HFTPermissionMgr
{
public:
	//PageContentEdit Layer
	static void* FPDPage_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDForm_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	
	//PageContentExtract Layer
	static void* FPDTextPage_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDImageObject_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDTextObject_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	
	//DocEdit Layer
	static void* FPDDoc_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDAction_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDAAction_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDDocJSActions_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDFileSpec_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDMediaPlayer_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FRDoc_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDFDFDoc_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDReference_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	
	//DictAndStm Layer
//	static void* FPDDictionary_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDStream_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
//	static void* FPDStreamAcc_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	
	//Rendering Layer
	static void* FPDRenderContext_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDProgressiveRender_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	
	//Annotation Layer
	static void* FPDAnnot_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDAnnotList_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	
	//InterForm Layer
	static void* FPDInterForm_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDFormField_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDFormControl_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	
	//EncryptAndDecrypt Layer
	static void* FPDCreator_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	static void* FPDWrapperCreator_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	
	//FRApp
	static void* FRApp_QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	
	//Interface Manager
	static void* QueryInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);

	static PluginData* GetPluginData(FS_WideString wsPID);
	
	static void OutputInterface(int iHFTSel, int iInterfaceSel, FS_WideString wsPID);
	
};


#endif


#ifndef _FR_PLUGIN_SDK_MOODULE_H_
#define _FR_PLUGIN_SDK_MOODULE_H_

#define PLUGIN_SDK_MODULE "PluginSDK"

#include "fr_plugin_handler.h"

class CPlugin_Module : public IReader_Module {
	CPlugin_PageEventHandler *m_pPageEventHandler;

	std::vector<std::unique_ptr<CPlugin_DocProteryHandler>> m_pDocProteryHandlers;
	std::vector<std::unique_ptr<CPlugin_PreferenceHandler>> m_pPreferenceHandlers;
#if 0
	std::unique_ptr<CPlugin_DocEventHandler> m_pDocEventHandler;
#endif
	CPlugin_Module(HMODULE hModule);

public:
	friend IReader_Module *Reader_CreatePluginModule(HMODULE hModule,
		IReader_App *pApp);

	~CPlugin_Module();

	CFX_ByteString GetModuleName() override { return PLUGIN_SDK_MODULE; }

	bool Register(FR_DocPropertypageCallbacksRec *callback);
	bool Register(FR_PageEventCallbacksRec *callback);
	bool Register(FR_PreferPageCallbacksRec *callback);
#if 0
	bool Register(FR_DocEventCallbacksRec *callback);

	// 暂时放在Module中执行
	void OnMouseClickOnText(IReader_Document *pDoc, FX_LPCWSTR wsText,
		CRect rtClient);
	void OnDrawAnnot(IReader_PageView *pPageView, HDC hDC, IReader_Annot *pAnnot,
		CFX_RenderDevice *pDevice, CPDF_Matrix *pUser2Device,
		const CRect &rcWindow, DWORD dwFlags);
	void OnThumbnailWillDraw(IReader_ThumbnailView *pThumbnailView, HDC dc);
	void OnThumbnailDidDraw(IReader_ThumbnailView *pThumbnailView, HDC dc);
	void OnPageViewerWillDraw(CReader_PageViewer *pPageViewer, HDC dc);
	BOOL OnDocCanPaste();
	BOOL OnDocSaveAsBeforeReopen(FS_LPCWSTR wszFilePath);
	BOOL CanDocBeSaved(IReader_Document *pDoc);
	void OnDocDidFileClose(FS_LPCWSTR lpwsFilePath);
	void OnDocDidSave(IReader_Document *pDoc, FX_BOOL bSaveAs, BOOL bPromptToSave,
		FX_LPCWSTR lpwsFilePath);
#endif
};
namespace plugin {
	CPlugin_Module *GetModule();
}

IReader_Module *Reader_CreatePluginModule(HMODULE hModule, IReader_App *pApp);
#endif
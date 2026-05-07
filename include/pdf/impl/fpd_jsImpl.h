#ifndef FPD_JSIMPL_H
#define FPD_JSIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifndef FPD_JSEXPT_H
#include "../fpd_jsExpt.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


class CFPD_JSEngine_V17
{
public:
	static FPD_JSEngine GetJSEngine(FPD_JSAppProvider pApp);
	static FPD_JSActionReturn RunFieldCalculate(FPD_JSEngine engine, FPD_JSDocumentProvider pDocument,
		FS_LPCWSTR sourceName,
		FS_LPCWSTR targetName,
		FS_WideString* value,
		FS_LPCWSTR script,
		FS_BOOLEAN* rc);
	static FPD_JSAppProvider GetAppProvider(FPD_JSEngine engine);
	static FPD_JSRuntime GetDocJSRuntime(FPD_JSEngine engine, FPD_JSDocumentProvider pDocProvider,
		FS_BOOLEAN bForJSPlugins,
		FS_BOOLEAN bJustGet);
	static void SetJSRuntime(FPD_JSEngine engine, FPD_JSRuntime pRuntime);
	static void ReleaseJSEngine();
	static FPD_JSActionReturn RunDocJavaScript(FPD_JSEngine engine, FPD_JSDocumentProvider pDocProvider,
		FPD_AActionType type,
		FS_LPCWSTR sScriptName,
		FS_LPCWSTR script,
		FS_WideString* errInfo);
	static FPD_JSActionReturn RunFieldJavaScript(FPD_JSEngine engine, FPD_JSDocumentProvider pDocument,
		FPD_FormField pFormField,
		FPD_AActionType type,
		FPD_JSFieldAction* data,
		const FS_LPCWSTR script);
	static FPD_JSActionReturn RunFieldFormat(FPD_JSEngine engine, FPD_JSDocumentProvider pDocument,
		FS_INT32 commitKey,
		FS_LPCWSTR targetName,
		FS_WideString* value,
		FS_LPCWSTR script,
		FS_BOOLEAN willCommit);
	static FPD_JSActionReturn RunLinkJavaScript(FPD_JSEngine engine, FPD_JSDocumentProvider pDocument, FS_LPCWSTR script);
	static FPD_JSActionReturn RunOutsideEnv(FPD_JSEngine engine, FPD_JSDocumentProvider pDocument,
		FPD_JSEnv env,
		FS_LPCWSTR script,
		FS_WideString* errInfo);
};


class CFPD_JSAppProvider_V17
{
public:
	static FPD_JSDocumentProvider GetReaderDocument(FPD_JSAppProvider pApp, FPD_Document doc);
	static void JSSetValueNotify(FPD_JSAppProvider pApp, const FS_LPCWSTR wsFieldName,
		FPD_JSNOTIFY_TRIGGER_TYPE eTriggerType,
		const FS_WideStringArray wsBValueVec,
		const FS_WideStringArray wsAValueVec);	
	static FS_INT32 ExecuteNamedAction(FPD_JSAppProvider pApp, FPD_JSDocumentProvider pDoc, FS_LPCSTR namedAction);
	static FS_BOOLEAN OpenURL(FPD_JSAppProvider pApp, FS_LPCWSTR csURL, FS_BOOLEAN bOpenInNewTab);
};

class CFPD_JSRuntime_V17
{
public:
	static FPD_JSContext NewContext(FPD_JSRuntime runtime, FPD_JSContext_Level level);
	static void ReleaseContext(FPD_JSRuntime runtime);
	static void SetReaderDocument(FPD_JSRuntime runtime, FPD_JSDocumentProvider pReaderDoc);
};

class CFPD_JSContext_V17
{
public:
	static void OnField_Calculate(FPD_JSContext context, FPD_FormField pSource,
		FPD_FormField pTarget,
		FS_WideString* Value,
		FS_BOOLEAN* bRc);
	static FS_BOOLEAN RunScript(FPD_JSContext context, FS_LPCWSTR script, FS_WideString* errInfo);
	static void OnDocOpen(FPD_JSContext context, FPD_JSDocumentProvider pDoc, const FS_LPCWSTR strTargetName);
};

class CFPD_JSFieldAction_V17
{
public:
	static FPD_JSFieldAction New();
	static void Delete(FPD_JSFieldAction fieldAction);
	static FS_BOOLEAN GetbModifier(FPD_JSFieldAction fieldAction);
	static void SetbModifier(FPD_JSFieldAction fieldAction, FS_BOOLEAN bModifier);
	static FS_BOOLEAN GetbShift(FPD_JSFieldAction fieldAction);
	static void SetbShift(FPD_JSFieldAction fieldAction, FS_BOOLEAN bShift);
	static FS_INT32 GetCommitKey(FPD_JSFieldAction fieldAction);
	static void SetCommitKey(FPD_JSFieldAction fieldAction, FS_INT32 nCommitKey);
	static void GetChange(FPD_JSFieldAction fieldAction, FS_WideString* outChange);
	static void SetChange(FPD_JSFieldAction fieldAction, FS_LPCWSTR sChange);
	static void GetChangeEx(FPD_JSFieldAction fieldAction, FS_WideString* outChange);
	static void SetChangeEx(FPD_JSFieldAction fieldAction, FS_LPCWSTR sChange);
	static FS_BOOLEAN GetbKeyDown(FPD_JSFieldAction fieldAction);
	static void SetbKeyDown(FPD_JSFieldAction fieldAction, FS_BOOLEAN bKeyDown);
	static FS_INT32 GetSelEnd(FPD_JSFieldAction fieldAction);
	static void SetSelEnd(FPD_JSFieldAction fieldAction, FS_INT32 nSelEnd);
	static FS_INT32 GetSelStart(FPD_JSFieldAction fieldAction);
	static void SetSelStart(FPD_JSFieldAction fieldAction, FS_INT32 nSelStart);
	static void GetValue(FPD_JSFieldAction fieldAction, FS_WideString* outValue);
	static void SetValue(FPD_JSFieldAction fieldAction, FS_LPCWSTR sValue);
	static FS_BOOLEAN GetbWillCommit(FPD_JSFieldAction fieldAction);
	static void SetbWillCommit(FPD_JSFieldAction fieldAction, FS_BOOLEAN bWillCommit);
	static FS_BOOLEAN GetbFieldFull(FPD_JSFieldAction fieldAction);
	static void SetbFieldFull(FPD_JSFieldAction fieldAction, FS_BOOLEAN bFieldFull);
	static FS_BOOLEAN GetbRC(FPD_JSFieldAction fieldAction);
	static void SetbRC(FPD_JSFieldAction fieldAction, FS_BOOLEAN bRC);
};

class CFPD_JSDocumentProvider_V17
{
public:	
	static FPD_JSFormProvider GetInterForm(FPD_JSDocumentProvider docProvider);
};

class CFPD_JSFormProvider_V17
{
public:
	static FS_BOOLEAN SubmitForm(FPD_JSFormProvider formProvider, FPD_JSFileFormatType nFormat,
		const FS_LPCWSTR csDestination,
		const FS_PtrArray fields,
		FS_BOOLEAN bIncludeOrExclude,
		FS_BOOLEAN bUrlEncoded,
		FS_ByteString* sServiceType,
		FS_BOOLEAN bIncludeAnnot,
		FS_BOOLEAN bAllField,
		FPD_EM_CODEENCODING encoding);
};

#ifdef __cplusplus
};
#endif

#endif
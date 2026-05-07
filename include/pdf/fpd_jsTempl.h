/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

//----------_V1----------
//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
//----------_V11----------
//----------_V12----------
//----------_V13----------
//----------_V14----------
//----------_V15----------
//----------_V16----------
//----------_V17----------
//*****************************
/* JSEngine HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_JSEngine, FPDJSEngineGetJSEngine, (FPD_JSAppProvider pApp))

INTERFACE(FPD_JSActionReturn, FPDJSEngineRunFieldCalculate, (FPD_JSEngine engine,  FPD_JSDocumentProvider pDocument,  FS_LPCWSTR sourceName,  FS_LPCWSTR targetName,  FS_WideString* value,  FS_LPCWSTR script,  FS_BOOLEAN* rc))

INTERFACE(FPD_JSAppProvider, FPDJSEngineGetAppProvider, (FPD_JSEngine engine))

INTERFACE(FPD_JSRuntime, FPDJSEngineGetDocJSRuntime, (FPD_JSEngine engine,  FPD_JSDocumentProvider pDocProvider,  FS_BOOLEAN bForJSPlugins,  FS_BOOLEAN bJustGet))

INTERFACE(void, FPDJSEngineSetJSRuntime, (FPD_JSEngine engine,  FPD_JSRuntime pRuntime))

INTERFACE(void, FPDJSEngineReleaseJSEngine, ())

INTERFACE(FPD_JSActionReturn, FPDJSEngineRunDocJavaScript, (FPD_JSEngine engine,  FPD_JSDocumentProvider pDocProvider,  FPD_AActionType type,  FS_LPCWSTR sScriptName,  FS_LPCWSTR script,  FS_WideString* errInfo))

INTERFACE(FPD_JSActionReturn, FPDJSEngineRunFieldJavaScript, (FPD_JSEngine engine,  FPD_JSDocumentProvider pDocument,  FPD_FormField pFormField,  FPD_AActionType type,  FPD_JSFieldAction* data,  const FS_LPCWSTR script))

INTERFACE(FPD_JSActionReturn, FPDJSEngineRunFieldFormat, (FPD_JSEngine engine,  FPD_JSDocumentProvider pDocument,  FS_INT32 commitKey,  FS_LPCWSTR targetName,  FS_WideString* value,  FS_LPCWSTR script,  FS_BOOLEAN willCommit))

INTERFACE(FPD_JSActionReturn, FPDJSEngineRunLinkJavaScript, (FPD_JSEngine engine,  FPD_JSDocumentProvider pDocument,  FS_LPCWSTR script))

INTERFACE(FPD_JSActionReturn, FPDJSEngineRunOutsideEnv, (FPD_JSEngine engine,  FPD_JSDocumentProvider pDocument,  FPD_JSEnv env,  FS_LPCWSTR script,  FS_WideString* errInfo))

NumOfSelector(FPDJSEngine)
ENDENUM

//*****************************
/* JSAppProvider HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_JSDocumentProvider, FPDJSAppProviderGetReaderDocument, (FPD_JSAppProvider pApp,  FPD_Document doc))

INTERFACE(void, FPDJSAppProviderJSSetValueNotify, (FPD_JSAppProvider pApp,  const FS_LPCWSTR wsFieldName,  FPD_JSNOTIFY_TRIGGER_TYPE eTriggerType,  const FS_WideStringArray wsBValueVec,  const FS_WideStringArray wsAValueVec))

INTERFACE(FS_INT32, FPDJSAppProviderExecuteNamedAction, (FPD_JSAppProvider pApp,  FPD_JSDocumentProvider pDoc,  FS_LPCSTR namedAction))

INTERFACE(FS_BOOLEAN, FPDJSAppProviderOpenURL, (FPD_JSAppProvider pApp,  FS_LPCWSTR csURL,  FS_BOOLEAN bOpenInNewTab))

NumOfSelector(FPDJSAppProvider)
ENDENUM

//*****************************
/* JSRuntime HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_JSContext, FPDJSRuntimeNewContext, (FPD_JSRuntime runtime,  FPD_JSContext_Level level))

INTERFACE(void, FPDJSRuntimeReleaseContext, (FPD_JSRuntime runtime))

INTERFACE(void, FPDJSRuntimeSetReaderDocument, (FPD_JSRuntime runtime,  FPD_JSDocumentProvider pReaderDoc))

NumOfSelector(FPDJSRuntime)
ENDENUM

//*****************************
/* JSContext HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FPDJSContextOnField_Calculate, (FPD_JSContext context,  FPD_FormField pSource,  FPD_FormField pTarget,  FS_WideString* Value,  FS_BOOLEAN* bRc))

INTERFACE(FS_BOOLEAN, FPDJSContextRunScript, (FPD_JSContext context,  FS_LPCWSTR script,  FS_WideString* errInfo))

INTERFACE(void, FPDJSContextOnDocOpen, (FPD_JSContext context,  FPD_JSDocumentProvider pDoc,  const FS_LPCWSTR strTargetName))

NumOfSelector(FPDJSContext)
ENDENUM

//*****************************
/* JSFieldAction HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_JSFieldAction, FPDJSFieldActionNew, ())

INTERFACE(void, FPDJSFieldActionDelete, (FPD_JSFieldAction fieldAction))

INTERFACE(FS_BOOLEAN, FPDJSFieldActionGetbModifier, (FPD_JSFieldAction fieldAction))

INTERFACE(void, FPDJSFieldActionSetbModifier, (FPD_JSFieldAction fieldAction,  FS_BOOLEAN bModifier))

INTERFACE(FS_BOOLEAN, FPDJSFieldActionGetbShift, (FPD_JSFieldAction fieldAction))

INTERFACE(void, FPDJSFieldActionSetbShift, (FPD_JSFieldAction fieldAction,  FS_BOOLEAN bShift))

INTERFACE(FS_INT32, FPDJSFieldActionGetCommitKey, (FPD_JSFieldAction fieldAction))

INTERFACE(void, FPDJSFieldActionSetCommitKey, (FPD_JSFieldAction fieldAction,  FS_INT32 nCommitKey))

INTERFACE(void, FPDJSFieldActionGetChange, (FPD_JSFieldAction fieldAction,  FS_WideString* outChange))

INTERFACE(void, FPDJSFieldActionSetChange, (FPD_JSFieldAction fieldAction,  FS_LPCWSTR sChange))

INTERFACE(void, FPDJSFieldActionGetChangeEx, (FPD_JSFieldAction fieldAction,  FS_WideString* outChange))

INTERFACE(void, FPDJSFieldActionSetChangeEx, (FPD_JSFieldAction fieldAction,  FS_LPCWSTR sChange))

INTERFACE(FS_BOOLEAN, FPDJSFieldActionGetbKeyDown, (FPD_JSFieldAction fieldAction))

INTERFACE(void, FPDJSFieldActionSetbKeyDown, (FPD_JSFieldAction fieldAction,  FS_BOOLEAN bKeyDown))

INTERFACE(FS_INT32, FPDJSFieldActionGetSelEnd, (FPD_JSFieldAction fieldAction))

INTERFACE(void, FPDJSFieldActionSetSelEnd, (FPD_JSFieldAction fieldAction,  FS_INT32 nSelEnd))

INTERFACE(FS_INT32, FPDJSFieldActionGetSelStart, (FPD_JSFieldAction fieldAction))

INTERFACE(void, FPDJSFieldActionSetSelStart, (FPD_JSFieldAction fieldAction,  FS_INT32 nSelStart))

INTERFACE(void, FPDJSFieldActionGetValue, (FPD_JSFieldAction fieldAction,  FS_WideString* outValue))

INTERFACE(void, FPDJSFieldActionSetValue, (FPD_JSFieldAction fieldAction,  FS_LPCWSTR sValue))

INTERFACE(FS_BOOLEAN, FPDJSFieldActionGetbWillCommit, (FPD_JSFieldAction fieldAction))

INTERFACE(void, FPDJSFieldActionSetbWillCommit, (FPD_JSFieldAction fieldAction,  FS_BOOLEAN bWillCommit))

INTERFACE(FS_BOOLEAN, FPDJSFieldActionGetbFieldFull, (FPD_JSFieldAction fieldAction))

INTERFACE(void, FPDJSFieldActionSetbFieldFull, (FPD_JSFieldAction fieldAction,  FS_BOOLEAN bFieldFull))

INTERFACE(FS_BOOLEAN, FPDJSFieldActionGetbRC, (FPD_JSFieldAction fieldAction))

INTERFACE(void, FPDJSFieldActionSetbRC, (FPD_JSFieldAction fieldAction,  FS_BOOLEAN bRC))

NumOfSelector(FPDJSFieldAction)
ENDENUM

//*****************************
/* JSDocumentProvider HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_JSFormProvider, FPDJSDocumentProviderGetInterForm, (FPD_JSDocumentProvider docProvider))

NumOfSelector(FPDJSDocumentProvider)
ENDENUM

//*****************************
/* JSFormProvider HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOLEAN, FPDJSFormProviderSubmitForm, (FPD_JSFormProvider formProvider,  FPD_JSFileFormatType nFormat,  const FS_LPCWSTR csDestination,  const FS_PtrArray fields,  FS_BOOLEAN bIncludeOrExclude,  FS_BOOLEAN bUrlEncoded,  FS_ByteString* sServiceType,  FS_BOOLEAN bIncludeAnnot,  FS_BOOLEAN bAllField,  FPD_EM_CODEENCODING encoding))

NumOfSelector(FPDJSFormProvider)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

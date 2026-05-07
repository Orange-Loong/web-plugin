/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FR_DOCCALLS_H
#define FR_DOCCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_DOCEXPT_H
#include "fr_docExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fr_docImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fr_docTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fr_docImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fr_docTempl.h"

//----------_V1----------
//*****************************
/* Doc HFT functions */
//*****************************

#define FRDocOpenFromFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocOpenFromFileSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocOpenFromFileSEL, _gPID)))

#define FRDocOpenFromPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocOpenFromPDDocSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocOpenFromPDDocSEL, _gPID)))

#define FRDocFromPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocFromPDDocSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocFromPDDocSEL, _gPID)))

#define FRDocClose (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCloseSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCloseSEL, _gPID)))

#define FRDocGetPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetPDDocSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetPDDocSEL, _gPID)))

#define FRDocDoSave (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoSaveSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoSaveSEL, _gPID)))

#define FRDocDoSaveAs (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoSaveAsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoSaveAsSEL, _gPID)))

#define FRDocSetChangeMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetChangeMarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetChangeMarkSEL, _gPID)))

#define FRDocGetChangeMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetChangeMarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetChangeMarkSEL, _gPID)))

#define FRDocClearChangeMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocClearChangeMarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocClearChangeMarkSEL, _gPID)))

#define FRDocDoPrint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoPrintSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoPrintSEL, _gPID)))

#define FRDocPrintPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocPrintPagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocPrintPagesSEL, _gPID)))

#define FRDocPrintSetup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocPrintSetupSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocPrintSetupSEL, _gPID)))

#define FRDocCountDocViews (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCountDocViewsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCountDocViewsSEL, _gPID)))

#define FRDocGetDocView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetDocViewSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetDocViewSEL, _gPID)))

#define FRDocGetCurrentDocView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurrentDocViewSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurrentDocViewSEL, _gPID)))

#define FRDocGetPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetPermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetPermissionsSEL, _gPID)))

#define FRDocSetPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetPermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetPermissionsSEL, _gPID)))

#define FRDocGetFilePath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetFilePathSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetFilePathSEL, _gPID)))

#define FRDocSetCurSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetCurSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetCurSelectionSEL, _gPID)))

#define FRDocAddToCurrentSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocAddToCurrentSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocAddToCurrentSelectionSEL, _gPID)))

#define FRDocRemoveFromSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRemoveFromSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRemoveFromSelectionSEL, _gPID)))

#define FRDocGetCurSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurSelectionSEL, _gPID)))

#define FRDocGetCurSelectionType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurSelectionTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurSelectionTypeSEL, _gPID)))

#define FRDocShowSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocShowSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocShowSelectionSEL, _gPID)))

#define FRDocClearSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocClearSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocClearSelectionSEL, _gPID)))

#define FRDocDeleteSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDeleteSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDeleteSelectionSEL, _gPID)))

#define FRDocCopySelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCopySelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCopySelectionSEL, _gPID)))

#define FRDocSetCurCapture (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetCurCaptureSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetCurCaptureSEL, _gPID)))

#define FRDocGetCurCapture (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurCaptureSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurCaptureSEL, _gPID)))

#define FRDocGetCurCaptureType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurCaptureTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurCaptureTypeSEL, _gPID)))

#define FRDocReleaseCurCapture (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocReleaseCurCaptureSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocReleaseCurCaptureSEL, _gPID)))

#define FRDocGetParser (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetParserSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetParserSEL, _gPID)))

#define FRDocGetPDFCreator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetPDFCreatorSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetPDFCreatorSEL, _gPID)))

#define FRDocDoPrintSilently (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoPrintSilentlySELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoPrintSilentlySEL, _gPID)))

#define FRDocGetTextSelectTool (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetTextSelectToolSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetTextSelectToolSEL, _gPID)))

#define FRDocGetDocumentType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetDocumentTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetDocumentTypeSEL, _gPID)))

#define FRDocCanSecurityMethodBeModified (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCanSecurityMethodBeModifiedSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCanSecurityMethodBeModifiedSEL, _gPID)))

#define FRDocUpdateSecurityMethod (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocUpdateSecurityMethodSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocUpdateSecurityMethodSEL, _gPID)))

#define FRDocIsEncrypted (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsEncryptedSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsEncryptedSEL, _gPID)))

#define FRDocRemoveSecurityMethod (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRemoveSecurityMethodSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRemoveSecurityMethodSEL, _gPID)))

#define FRDocIsMemoryDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsMemoryDocSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsMemoryDocSEL, _gPID)))

#define FRDocGetCurrentSecurityMethodName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurrentSecurityMethodNameSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurrentSecurityMethodNameSEL, _gPID)))

#define FRDocSetAppPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetAppPermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetAppPermissionsSEL, _gPID)))

#define FRDocGetAppPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetAppPermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetAppPermissionsSEL, _gPID)))

#define FRDocGetAppPermissionsII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetAppPermissionsIISELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetAppPermissionsIISEL, _gPID)))

#define FRDocGetPermissionsII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetPermissionsIISELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetPermissionsIISEL, _gPID)))

#define FRDocGetMergedPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetMergedPermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetMergedPermissionsSEL, _gPID)))

#define FRDocKillFocusAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocKillFocusAnnotSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocKillFocusAnnotSEL, _gPID)))

#define FRDocDoSaveAs2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoSaveAs2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoSaveAs2SEL, _gPID)))

#define FRDocShowSaveProgressCancelButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocShowSaveProgressCancelButtonSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocShowSaveProgressCancelButtonSEL, _gPID)))

#define FRDocSetInputPasswordProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetInputPasswordProcSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetInputPasswordProcSEL, _gPID)))

#define FRDocGetUIParentWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetUIParentWndSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetUIParentWndSEL, _gPID)))

#define FRDocGetDocFrameHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetDocFrameHandlerSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetDocFrameHandlerSEL, _gPID)))

#define FRDocGetDocShowTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetDocShowTitleSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetDocShowTitleSEL, _gPID)))

#define FRDocDoSave2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoSave2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoSave2SEL, _gPID)))

#define FRDocResetDocTitleColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocResetDocTitleColorSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocResetDocTitleColorSEL, _gPID)))

#define FRDocSetDocTitleColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetDocTitleColorSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetDocTitleColorSEL, _gPID)))

#define FRDocGetOriginalType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetOriginalTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetOriginalTypeSEL, _gPID)))

#define FRDocSetOriginalType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetOriginalTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetOriginalTypeSEL, _gPID)))

#define FRDocSetFocusAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetFocusAnnotSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetFocusAnnotSEL, _gPID)))

#define FRDocHasRedactAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocHasRedactAnnotSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocHasRedactAnnotSEL, _gPID)))

#define FRDocGenerateRedactions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGenerateRedactionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGenerateRedactionsSEL, _gPID)))

#define FRDocReloadPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocReloadPageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocReloadPageSEL, _gPID)))

#define FRDocForbidChangeMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocForbidChangeMarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocForbidChangeMarkSEL, _gPID)))

#define FRDocOpenFromPDDoc2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocOpenFromPDDoc2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocOpenFromPDDoc2SEL, _gPID)))

#define FRDocParsePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocParsePageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocParsePageSEL, _gPID)))

#define FRDocIsValidAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsValidAnnotSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsValidAnnotSEL, _gPID)))

#define FRDocOpenFromFile2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocOpenFromFile2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocOpenFromFile2SEL, _gPID)))

#define FRDocGetSignaturePermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetSignaturePermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetSignaturePermissionsSEL, _gPID)))

#define FRDocConvertPdfToOtherFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocConvertPdfToOtherFormatSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocConvertPdfToOtherFormatSEL, _gPID)))

#define FRDocDoPassWordEncrypt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoPassWordEncryptSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoPassWordEncryptSEL, _gPID)))

#define FRDocIsInProtectedViewMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsInProtectedViewModeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsInProtectedViewModeSEL, _gPID)))

#define FRDocIsVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsVisibleSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsVisibleSEL, _gPID)))

#define FRDocConvertPdfToOtherFormat2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocConvertPdfToOtherFormat2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocConvertPdfToOtherFormat2SEL, _gPID)))

#define FRDocAddWatermark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocAddWatermarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocAddWatermarkSEL, _gPID)))

#define FRDocAddAndUpdateWatermark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocAddAndUpdateWatermarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocAddAndUpdateWatermarkSEL, _gPID)))

#define FRDocRemoveWatermark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRemoveWatermarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRemoveWatermarkSEL, _gPID)))

#define FRDocRemoveAndUpdateWatermark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRemoveAndUpdateWatermarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRemoveAndUpdateWatermarkSEL, _gPID)))

#define FRDocAddHeaderFooter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocAddHeaderFooterSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocAddHeaderFooterSEL, _gPID)))

#define FRDocAddAndUpdateHeaderFooter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocAddAndUpdateHeaderFooterSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocAddAndUpdateHeaderFooterSEL, _gPID)))

#define FRDocRemoveHeaderFooter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRemoveHeaderFooterSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRemoveHeaderFooterSEL, _gPID)))

#define FRDocRemoveAndUpdateHeaderFooter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRemoveAndUpdateHeaderFooterSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRemoveAndUpdateHeaderFooterSEL, _gPID)))

#define FRDocIsReadSafeMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsReadSafeModeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsReadSafeModeSEL, _gPID)))

#define FRDocGetInterForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetInterFormSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetInterFormSEL, _gPID)))

#define FRDocGeneratePageContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGeneratePageContentSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGeneratePageContentSEL, _gPID)))

#define FRDocGetFocusAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetFocusAnnotSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetFocusAnnotSEL, _gPID)))

#define FRDocAddSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocAddSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocAddSelectionSEL, _gPID)))

#define FRDocGetPageFirstAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetPageFirstAnnotSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetPageFirstAnnotSEL, _gPID)))

#define FRDocCreateFormControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCreateFormControlSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCreateFormControlSEL, _gPID)))

#define FRDocNotifyAddWidget (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocNotifyAddWidgetSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocNotifyAddWidgetSEL, _gPID)))

#define FRDocUpdateAllViews (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocUpdateAllViewsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocUpdateAllViewsSEL, _gPID)))

#define FRDocGetAnnotByDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetAnnotByDictSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetAnnotByDictSEL, _gPID)))

#define FRDocAddAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocAddAnnotSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocAddAnnotSEL, _gPID)))

#define FRDocAddAnnot2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocAddAnnot2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocAddAnnot2SEL, _gPID)))

#define FRDocReplacePages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocReplacePagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocReplacePagesSEL, _gPID)))

#define FRDocInsertPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocInsertPagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocInsertPagesSEL, _gPID)))

#define FRDocExtractPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocExtractPagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocExtractPagesSEL, _gPID)))

#define FRDocRemoveSecurityInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRemoveSecurityInfoSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRemoveSecurityInfoSEL, _gPID)))

#define FRDocUpdateDocAllViews (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocUpdateDocAllViewsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocUpdateDocAllViewsSEL, _gPID)))

#define FRDocSendAsAttachment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSendAsAttachmentSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSendAsAttachmentSEL, _gPID)))

#define FRDocConvertPdfToOtherFormat3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocConvertPdfToOtherFormat3SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocConvertPdfToOtherFormat3SEL, _gPID)))

#define FRDocSetNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetNotifySELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetNotifySEL, _gPID)))

#define FRDocReConStructAcroform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocReConStructAcroformSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocReConStructAcroformSEL, _gPID)))

#define FRDocSetSaveMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetSaveModeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetSaveModeSEL, _gPID)))

#define FRDocGetSaveMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetSaveModeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetSaveModeSEL, _gPID)))

#define FRDocGetReaderDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetReaderDocumentSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetReaderDocumentSEL, _gPID)))

#define FRDocCountSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCountSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCountSelectionSEL, _gPID)))

#define FRDocGetSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetSelectionSEL, _gPID)))

#define FRDocGetTopPageState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetTopPageStateSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetTopPageStateSEL, _gPID)))

#define FRDocSetMemDocCanReopen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetMemDocCanReopenSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetMemDocCanReopenSEL, _gPID)))

#define FRDocAppendUnCompressObjects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocAppendUnCompressObjectsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocAppendUnCompressObjectsSEL, _gPID)))

#define FRDocDoSaveAs3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoSaveAs3SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoSaveAs3SEL, _gPID)))

#define FRDocIsReflowViewMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsReflowViewModeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsReflowViewModeSEL, _gPID)))

#define FRDocGetOpenFilePath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetOpenFilePathSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetOpenFilePathSEL, _gPID)))

#define FRDocGetTabTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetTabTitleSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetTabTitleSEL, _gPID)))

#define FRDocGetTextPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetTextPageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetTextPageSEL, _gPID)))

#define FRDocGetDocPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetDocPagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetDocPagesSEL, _gPID)))

#define FRDocOpenDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocOpenDocumentSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocOpenDocumentSEL, _gPID)))

#define FRDocGetFileName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetFileNameSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetFileNameSEL, _gPID)))

#define FRDocResizePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocResizePageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocResizePageSEL, _gPID)))

#define FRDocGetPageLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetPageLabelSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetPageLabelSEL, _gPID)))

#define FRDocRequestDocPermPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRequestDocPermPDDocSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRequestDocPermPDDocSEL, _gPID)))

#define FRDocGetSelectPageFromPagePanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetSelectPageFromPagePanelSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetSelectPageFromPagePanelSEL, _gPID)))

#define FRDocReversePages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocReversePagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocReversePagesSEL, _gPID)))

#define FRDocIsDynamicXFADocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsDynamicXFADocumentSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsDynamicXFADocumentSEL, _gPID)))

#define FRDocDeletePages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDeletePagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDeletePagesSEL, _gPID)))

#define FRDocExtractPages2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocExtractPages2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocExtractPages2SEL, _gPID)))

#define FRDocSwapTwoPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSwapTwoPageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSwapTwoPageSEL, _gPID)))

#define FRDocMovePages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocMovePagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocMovePagesSEL, _gPID)))

#define FRDocGetPageIndexByLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetPageIndexByLabelSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetPageIndexByLabelSEL, _gPID)))

#define FRDocRotatePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRotatePageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRotatePageSEL, _gPID)))

#define FRDocHasOwnerPermission (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocHasOwnerPermissionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocHasOwnerPermissionSEL, _gPID)))

#define FRDocGetHitImageObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetHitImageObjSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetHitImageObjSEL, _gPID)))

#define FRDocClearHitImageObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocClearHitImageObjSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocClearHitImageObjSEL, _gPID)))

#define FRDocMergeTwoDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocMergeTwoDocSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocMergeTwoDocSEL, _gPID)))

#define FRDocGetCurrentTool (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurrentToolSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurrentToolSEL, _gPID)))

#define FRDocMovePages2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocMovePages2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocMovePages2SEL, _gPID)))

#define FRDocDoSaveAsWithDefaultPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoSaveAsWithDefaultPathSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoSaveAsWithDefaultPathSEL, _gPID)))

#define FRDocSplitPageByRects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSplitPageByRectsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSplitPageByRectsSEL, _gPID)))

#define FRDocSetPageLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetPageLabelSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetPageLabelSEL, _gPID)))

#define FRDocRunPageOCR (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRunPageOCRSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRunPageOCRSEL, _gPID)))

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//*****************************
/* CustomSignature HFT functions */
//*****************************

#define FRCustomSignatureGenerateSignInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureGenerateSignInfoSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureGenerateSignInfoSEL, _gPID)))

#define FRCustomSignatureGetDefaultServer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureGetDefaultServerSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureGetDefaultServerSEL, _gPID)))

#define FRCustomSignatureCreateSignatureHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureCreateSignatureHandlerSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureCreateSignatureHandlerSEL, _gPID)))

#define FRCustomSignatureRegisterSignatureHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureRegisterSignatureHandlerSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureRegisterSignatureHandlerSEL, _gPID)))

#define FRCustomSignatureDestroySignatureHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureDestroySignatureHandlerSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureDestroySignatureHandlerSEL, _gPID)))

#define FRCustomSignatureSetSignatureVerify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureSetSignatureVerifySELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureSetSignatureVerifySEL, _gPID)))

#define FRCustomSignatureGetDocSigatureCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureGetDocSigatureCountSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureGetDocSigatureCountSEL, _gPID)))

#define FRCustomSignatureGetSignatureBaseInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureGetSignatureBaseInfoSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureGetSignatureBaseInfoSEL, _gPID)))

#define FRCustomSignatureClearSignature (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureClearSignatureSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureClearSignatureSEL, _gPID)))

#define FRCustomSignatureFoxitSignInScope (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureFoxitSignInScopeSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureFoxitSignInScopeSEL, _gPID)))

#define FRCustomSignatureFoixtCreateSignatureF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureFoixtCreateSignatureFSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureFoixtCreateSignatureFSEL, _gPID)))

#define FRCustomSignatureSetPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureSetPositionSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureSetPositionSEL, _gPID)))

#define FRCustomSignatureGenerateSignInfo2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureGenerateSignInfo2SELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureGenerateSignInfo2SEL, _gPID)))

#define FRCustomSignaturePrepareSign (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignaturePrepareSignSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignaturePrepareSignSEL, _gPID)))

//----------_V9----------
//----------_V10----------
//----------_V11----------
//----------_V12----------
//----------_V13----------
//*****************************
/* ReaderInterform HFT functions */
//*****************************

#define FRReaderInterformGetInterForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRReaderInterformGetInterFormSELPROTO)FRCOREROUTINE(FRReaderInterformSEL,FRReaderInterformGetInterFormSEL, _gPID)))

//----------_V14----------
//*****************************
/* UndoItemCreateWidget HFT functions */
//*****************************

//*****************************
/* CRSAStamp HFT functions */
//*****************************

//*****************************
/* MarkupAnnot HFT functions */
//*****************************

//*****************************
/* MarkupPopup HFT functions */
//*****************************

//*****************************
/* MarkupPanel HFT functions */
//*****************************

#define FRMarkupPanelGetMarkupPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMarkupPanelGetMarkupPanelSELPROTO)FRCOREROUTINE(FRMarkupPanelSEL,FRMarkupPanelGetMarkupPanelSEL, _gPID)))

#define FRMarkupPanelRefreshAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMarkupPanelRefreshAnnotSELPROTO)FRCOREROUTINE(FRMarkupPanelSEL,FRMarkupPanelRefreshAnnotSEL, _gPID)))

#define FRMarkupPanelReloadAnnots (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMarkupPanelReloadAnnotsSELPROTO)FRCOREROUTINE(FRMarkupPanelSEL,FRMarkupPanelReloadAnnotsSEL, _gPID)))

#define FRMarkupPanelAddAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMarkupPanelAddAnnotSELPROTO)FRCOREROUTINE(FRMarkupPanelSEL,FRMarkupPanelAddAnnotSEL, _gPID)))

//*****************************
/* CRSASStampAnnot HFT functions */
//*****************************

//*****************************
/* EncryptPermisson HFT functions */
//*****************************

//*****************************
/* CSGCertFileManage HFT functions */
//*****************************

//*****************************
/* CSG HFT functions */
//*****************************

//*****************************
/* Page HFT functions */
//*****************************

//*****************************
/* IBAAnnotFiller HFT functions */
//*****************************

//*****************************
/* IBAAnnotDesigner HFT functions */
//*****************************

//*****************************
/* CBFInterForm HFT functions */
//*****************************

//*****************************
/* BFFormNotify HFT functions */
//*****************************

//*****************************
/* BFAnnotHandler HFT functions */
//*****************************

//*****************************
/* BaseForm HFT functions */
//*****************************

#define FRBaseFormGetBaseForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormGetBaseFormSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormGetBaseFormSEL, _gPID)))

#define FRBaseFormBeginTabOrderDesign (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormBeginTabOrderDesignSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormBeginTabOrderDesignSEL, _gPID)))

#define FRBaseFormEndTabOrderDesign (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormEndTabOrderDesignSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormEndTabOrderDesignSEL, _gPID)))

#define FRBaseFormShowTabOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormShowTabOrderSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormShowTabOrderSEL, _gPID)))

#define FRBaseFormSetFormFiller (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormSetFormFillerSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormSetFormFillerSEL, _gPID)))

#define FRBaseFormSetSignatureFiller (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormSetSignatureFillerSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormSetSignatureFillerSEL, _gPID)))

#define FRBaseFormGetFillerByAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormGetFillerByAnnotSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormGetFillerByAnnotSEL, _gPID)))

#define FRBaseFormSetFormDesigner (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormSetFormDesignerSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormSetFormDesignerSEL, _gPID)))

#define FRBaseFormSetSignatureHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormSetSignatureHandlerSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormSetSignatureHandlerSEL, _gPID)))

#define FRBaseFormSetXFASignatureHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormSetXFASignatureHandlerSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormSetXFASignatureHandlerSEL, _gPID)))

#define FRBaseFormGetXFASignatureHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormGetXFASignatureHandlerSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormGetXFASignatureHandlerSEL, _gPID)))

#define FRBaseFormIsHighLight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormIsHighLightSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormIsHighLightSEL, _gPID)))

#define FRBaseFormSetHighLight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormSetHighLightSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormSetHighLightSEL, _gPID)))

#define FRBaseFormSetHighLightColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormSetHighLightColorSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormSetHighLightColorSEL, _gPID)))

#define FRBaseFormGetHighLightColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormGetHighLightColorSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormGetHighLightColorSEL, _gPID)))

#define FRBaseFormGetRequiredColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormGetRequiredColorSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormGetRequiredColorSEL, _gPID)))

#define FRBaseFormIsFormDesignerAssistEnabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormIsFormDesignerAssistEnabledSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormIsFormDesignerAssistEnabledSEL, _gPID)))

#define FRBaseFormSetFormDesignerAssistEnabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormSetFormDesignerAssistEnabledSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormSetFormDesignerAssistEnabledSEL, _gPID)))

#define FRBaseFormGetAutoCompleteChoice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormGetAutoCompleteChoiceSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormGetAutoCompleteChoiceSEL, _gPID)))

#define FRBaseFormIsOpenPropertyAfterCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormIsOpenPropertyAfterCreateSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormIsOpenPropertyAfterCreateSEL, _gPID)))

#define FRBaseFormShowFocusRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormShowFocusRectSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormShowFocusRectSEL, _gPID)))

#define FRBaseFormShowOverflowIndicator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormShowOverflowIndicatorSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormShowOverflowIndicatorSEL, _gPID)))

#define FRBaseFormIsNumericalDataEnable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormIsNumericalDataEnableSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormIsNumericalDataEnableSEL, _gPID)))

#define FRBaseFormSetFormNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormSetFormNotifySELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormSetFormNotifySEL, _gPID)))

#define FRBaseFormCollectAPStreamRefCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormCollectAPStreamRefCountSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormCollectAPStreamRefCountSEL, _gPID)))

#define FRBaseFormClearAPStreamRefCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormClearAPStreamRefCountSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormClearAPStreamRefCountSEL, _gPID)))

#define FRBaseFormGetAPStreamRefCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormGetAPStreamRefCountSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormGetAPStreamRefCountSEL, _gPID)))

#define FRBaseFormShow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBaseFormShowSELPROTO)FRCOREROUTINE(FRBaseFormSEL,FRBaseFormShowSEL, _gPID)))

//*****************************
/* IFormDesignerNotify HFT functions */
//*****************************

#define FRIFormDesignerNotifyNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRIFormDesignerNotifyNewSELPROTO)FRCOREROUTINE(FRIFormDesignerNotifySEL,FRIFormDesignerNotifyNewSEL, _gPID)))

#define FRIFormDesignerNotifyDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRIFormDesignerNotifyDestroySELPROTO)FRCOREROUTINE(FRIFormDesignerNotifySEL,FRIFormDesignerNotifyDestroySEL, _gPID)))

//*****************************
/* CBFWidget HFT functions */
//*****************************

#define FRCBFWidgetResetAppearance (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetResetAppearanceSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetResetAppearanceSEL, _gPID)))

#define FRCBFWidgetGetFieldType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetGetFieldTypeSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetGetFieldTypeSEL, _gPID)))

#define FRCBFWidgetGetRotate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetGetRotateSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetGetRotateSEL, _gPID)))

#define FRCBFWidgetGetTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetGetTextColorSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetGetTextColorSEL, _gPID)))

#define FRCBFWidgetGetFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetGetFontSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetGetFontSEL, _gPID)))

#define FRCBFWidgetGetBaseFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetGetBaseFontSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetGetBaseFontSEL, _gPID)))

#define FRCBFWidgetIsVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetIsVisibleSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetIsVisibleSEL, _gPID)))

#define FRCBFWidgetSetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetSetRectSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetSetRectSEL, _gPID)))

#define FRCBFWidgetGetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetGetRectSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetGetRectSEL, _gPID)))

#define FRCBFWidgetGetFormControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetGetFormControlSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetGetFormControlSEL, _gPID)))

#define FRCBFWidgetGetAnnotDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetGetAnnotDictSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetGetAnnotDictSEL, _gPID)))

#define FRCBFWidgetGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetGetNameSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetGetNameSEL, _gPID)))

#define FRCBFWidgetSetRotate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetSetRotateSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetSetRotateSEL, _gPID)))

#define FRCBFWidgetGetIReaderAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetGetIReaderAnnotSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetGetIReaderAnnotSEL, _gPID)))

#define FRCBFWidgetSetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetSetNameSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetSetNameSEL, _gPID)))

#define FRCBFWidgetHasAAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBFWidgetHasAActionSELPROTO)FRCOREROUTINE(FRCBFWidgetSEL,FRCBFWidgetHasAActionSEL, _gPID)))

//*****************************
/* IBFSimpleFromProperties HFT functions */
//*****************************

//*****************************
/* SGRDN HFT functions */
//*****************************

//*****************************
/* SGCERTIFICATE HFT functions */
//*****************************

//*****************************
/* SGSEEDVALUE HFT functions */
//*****************************

//*****************************
/* SGBaseHandler HFT functions */
//*****************************

//*****************************
/* IClipBoard HFT functions */
//*****************************

//*****************************
/* CCBAnnotation HFT functions */
//*****************************

//*****************************
/* ISpellCheck HFT functions */
//*****************************

//*****************************
/* CJavaScriptEditer HFT functions */
//*****************************

//*****************************
/* IBAImageSource HFT functions */
//*****************************

#define FRIBAImageSourceNewIBAImageSource (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRIBAImageSourceNewIBAImageSourceSELPROTO)FRCOREROUTINE(FRIBAImageSourceSEL,FRIBAImageSourceNewIBAImageSourceSEL, _gPID)))

#define FRIBAImageSourceDestroyImageSource (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRIBAImageSourceDestroyImageSourceSELPROTO)FRCOREROUTINE(FRIBAImageSourceSEL,FRIBAImageSourceDestroyImageSourceSEL, _gPID)))

//*****************************
/* CBAFigureRecognition HFT functions */
//*****************************

#define FRCBAFigureRecognitionNewCBAFigureRecognition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBAFigureRecognitionNewCBAFigureRecognitionSELPROTO)FRCOREROUTINE(FRCBAFigureRecognitionSEL,FRCBAFigureRecognitionNewCBAFigureRecognitionSEL, _gPID)))

#define FRCBAFigureRecognitionDestroyCBA_FigureRecognition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBAFigureRecognitionDestroyCBA_FigureRecognitionSELPROTO)FRCOREROUTINE(FRCBAFigureRecognitionSEL,FRCBAFigureRecognitionDestroyCBA_FigureRecognitionSEL, _gPID)))

#define FRCBAFigureRecognitionSetColorSource (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBAFigureRecognitionSetColorSourceSELPROTO)FRCOREROUTINE(FRCBAFigureRecognitionSEL,FRCBAFigureRecognitionSetColorSourceSEL, _gPID)))

#define FRCBAFigureRecognitionFindRectBy4Point (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCBAFigureRecognitionFindRectBy4PointSELPROTO)FRCOREROUTINE(FRCBAFigureRecognitionSEL,FRCBAFigureRecognitionFindRectBy4PointSEL, _gPID)))

//*****************************
/* AnnotObserver HFT functions */
//*****************************

#define FRAnnotObserverCreateAnnotObserver (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotObserverCreateAnnotObserverSELPROTO)FRCOREROUTINE(FRAnnotObserverSEL,FRAnnotObserverCreateAnnotObserverSEL, _gPID)))

#define FRAnnotObserverDestroyAnnotObserver (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotObserverDestroyAnnotObserverSELPROTO)FRCOREROUTINE(FRAnnotObserverSEL,FRAnnotObserverDestroyAnnotObserverSEL, _gPID)))

#define FRAnnotObserverIsValid (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotObserverIsValidSELPROTO)FRCOREROUTINE(FRAnnotObserverSEL,FRAnnotObserverIsValidSEL, _gPID)))

#define FRAnnotObserverGetAnnotObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotObserverGetAnnotObjSELPROTO)FRCOREROUTINE(FRAnnotObserverSEL,FRAnnotObserverGetAnnotObjSEL, _gPID)))

//*****************************
/* DocumentObserver HFT functions */
//*****************************

#define FRDocumentObserverCreateDocumentObserver (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocumentObserverCreateDocumentObserverSELPROTO)FRCOREROUTINE(FRDocumentObserverSEL,FRDocumentObserverCreateDocumentObserverSEL, _gPID)))

#define FRDocumentObserverDestroyDocumentObserver (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocumentObserverDestroyDocumentObserverSELPROTO)FRCOREROUTINE(FRDocumentObserverSEL,FRDocumentObserverDestroyDocumentObserverSEL, _gPID)))

#define FRDocumentObserverIsValid (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocumentObserverIsValidSELPROTO)FRCOREROUTINE(FRDocumentObserverSEL,FRDocumentObserverIsValidSEL, _gPID)))

#define FRDocumentObserverGetDocumentObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocumentObserverGetDocumentObjSELPROTO)FRCOREROUTINE(FRDocumentObserverSEL,FRDocumentObserverGetDocumentObjSEL, _gPID)))

//*****************************
/* InnerContentProvider HFT functions */
//*****************************

#define FRInnerContentProviderGetInnerContentProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInnerContentProviderGetInnerContentProviderSELPROTO)FRCOREROUTINE(FRInnerContentProviderSEL,FRInnerContentProviderGetInnerContentProviderSEL, _gPID)))

#define FRInnerContentProviderOnGetContentSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInnerContentProviderOnGetContentSizeSELPROTO)FRCOREROUTINE(FRInnerContentProviderSEL,FRInnerContentProviderOnGetContentSizeSEL, _gPID)))

#define FRInnerContentProviderOnReadContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInnerContentProviderOnReadContentSELPROTO)FRCOREROUTINE(FRInnerContentProviderSEL,FRInnerContentProviderOnReadContentSEL, _gPID)))

#define FRInnerContentProviderOnBackFillContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInnerContentProviderOnBackFillContentSELPROTO)FRCOREROUTINE(FRInnerContentProviderSEL,FRInnerContentProviderOnBackFillContentSEL, _gPID)))

#define FRInnerContentProviderOnGetAppPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInnerContentProviderOnGetAppPermissionsSELPROTO)FRCOREROUTINE(FRInnerContentProviderSEL,FRInnerContentProviderOnGetAppPermissionsSEL, _gPID)))

#define FRInnerContentProviderOnGetAttachmentSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInnerContentProviderOnGetAttachmentSizeSELPROTO)FRCOREROUTINE(FRInnerContentProviderSEL,FRInnerContentProviderOnGetAttachmentSizeSEL, _gPID)))

#define FRInnerContentProviderOnReadAttachmentContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInnerContentProviderOnReadAttachmentContentSELPROTO)FRCOREROUTINE(FRInnerContentProviderSEL,FRInnerContentProviderOnReadAttachmentContentSEL, _gPID)))

//*****************************
/* IFXPDFAInterface HFT functions */
//*****************************

#define FRIFXPDFAInterfaceGetIFXPDFAInterface (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRIFXPDFAInterfaceGetIFXPDFAInterfaceSELPROTO)FRCOREROUTINE(FRIFXPDFAInterfaceSEL,FRIFXPDFAInterfaceGetIFXPDFAInterfaceSEL, _gPID)))

#define FRIFXPDFAInterfaceSimplePDFACheck (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRIFXPDFAInterfaceSimplePDFACheckSELPROTO)FRCOREROUTINE(FRIFXPDFAInterfaceSEL,FRIFXPDFAInterfaceSimplePDFACheckSEL, _gPID)))

#define FRIFXPDFAInterfacePDFACheckIsClickEditing (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRIFXPDFAInterfacePDFACheckIsClickEditingSELPROTO)FRCOREROUTINE(FRIFXPDFAInterfaceSEL,FRIFXPDFAInterfacePDFACheckIsClickEditingSEL, _gPID)))

#define FRIFXPDFAInterfaceShowPreflightWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRIFXPDFAInterfaceShowPreflightWndSELPROTO)FRCOREROUTINE(FRIFXPDFAInterfaceSEL,FRIFXPDFAInterfaceShowPreflightWndSEL, _gPID)))

#define FRIFXPDFAInterfaceGetPreflightWndShow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRIFXPDFAInterfaceGetPreflightWndShowSELPROTO)FRCOREROUTINE(FRIFXPDFAInterfaceSEL,FRIFXPDFAInterfaceGetPreflightWndShowSEL, _gPID)))

//*****************************
/* IConvertToPDF HFT functions */
//*****************************

//*****************************
/* ITagePDF HFT functions */
//*****************************

//*****************************
/* TextPage HFT functions */
//*****************************

//*****************************
/* ISignatureCheck HFT functions */
//*****************************

//----------_V15----------
//----------_V16----------
//*****************************
/* TextLinkInfo HFT functions */
//*****************************

//*****************************
/* TextLinkMgr HFT functions */
//*****************************

//*****************************
/* SelectedImageInfo HFT functions */
//*****************************

#define FRSelectedImageInfoGetImagePDFRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSelectedImageInfoGetImagePDFRectSELPROTO)FRCOREROUTINE(FRSelectedImageInfoSEL,FRSelectedImageInfoGetImagePDFRectSEL, _gPID)))

#define FRSelectedImageInfoGetObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSelectedImageInfoGetObjSELPROTO)FRCOREROUTINE(FRSelectedImageInfoSEL,FRSelectedImageInfoGetObjSEL, _gPID)))

//*****************************
/* ContentObject HFT functions */
//*****************************

//----------_V17----------
//*****************************
/* Accessible HFT functions */
//*****************************

//*****************************
/* PageObserver HFT functions */
//*****************************

//*****************************
/* AnnotHandler HFT functions */
//*****************************

//*****************************
/* WidgetAnnotHandler HFT functions */
//*****************************

//*****************************
/* AnnotOperateHandler HFT functions */
//*****************************

//*****************************
/* BaseAnnot HFT functions */
//*****************************

//*****************************
/* SaveAsNotify HFT functions */
//*****************************

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
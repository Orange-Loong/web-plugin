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
//*****************************
/* CategoryRead HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FDRMCategoryReadCountSubCategories
 * @details 
 * @param[in]  reader 
 * @param[in]  hParent 
 * @param[in]  bsFilter 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_INT32, FDRMCategoryReadCountSubCategories, (FDRM_CategoryRead reader,  FDRM_CATEGORY_HANDLER hParent,  FS_ByteString bsFilter))

/**
 * @brief FDRMCategoryReadGetSubCategory
 * @details 
 * @param[in]  reader 
 * @param[in]  hParent 
 * @param[in]  bsFilter 
 * @param[in]  index 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FDRM_CATEGORY_HANDLER, FDRMCategoryReadGetSubCategory, (FDRM_CategoryRead reader,  FDRM_CATEGORY_HANDLER hParent,  FS_ByteString bsFilter,  FS_INT32 index))

INTERFACE(FDRM_CATEGORY_HANDLER, FDRMCategoryReadFindSubCategory, (FDRM_CategoryRead reader,  FDRM_CATEGORY_HANDLER hParent,  FS_ByteString bsFilter,  FS_ByteString bsKey,  FS_ByteString bsValue,  FS_LPVOID pCur))

INTERFACE(FDRM_CATEGORY_HANDLER, FDRMCategoryReadGetParentCategory, (FDRM_CategoryRead reader,  FDRM_CATEGORY_HANDLER hCategory))

INTERFACE(FS_INT32, FDRMCategoryReadGetCategoryName, (FDRM_CategoryRead reader,  FDRM_CATEGORY_HANDLER hCategory,  FS_ByteString out_bsCategory))

INTERFACE(FS_INT32, FDRMCategoryReadCountAttributes, (FDRM_CategoryRead reader,  FDRM_CATEGORY_HANDLER hCategory))

INTERFACE(FS_INT32, FDRMCategoryReadGetAttribute, (FDRM_CategoryRead reader,  FDRM_CATEGORY_HANDLER hCategory,  FS_INT32 index,  FS_ByteString out_bsName,  FS_ByteString out_bsValue))

INTERFACE(FS_INT32, FDRMCategoryReadGetAttributeValue, (FDRM_CategoryRead reader,  FDRM_CATEGORY_HANDLER hCategory,  FS_ByteString bsName,  FS_ByteString out_bsValue))

INTERFACE(FS_INT32, FDRMCategoryReadGetCategoryData, (FDRM_CategoryRead reader,  FDRM_CATEGORY_HANDLER hCategory,  FS_ByteString out_bsData))

INTERFACE(void, FDRMCategoryReadDestroy, (FDRM_CategoryRead reader))

NumOfSelector(FDRMCategoryRead)
ENDENUM

//*****************************
/* CategoryWrite HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_CATEGORY_HANDLER, FDRMCategoryWriteAddCategory, (FDRM_CategoryWrite Writer,  FDRM_CATEGORY_HANDLER hParent,  FS_ByteString bsCategory,  FS_BOOL bUnique))

INTERFACE(FDRM_CATEGORY_HANDLER, FDRMCategoryWriteAddCategory2, (FDRM_CategoryWrite Writer,  FDRM_CATEGORY_HANDLER hParent,  FS_ByteString bsCategory,  FS_ByteString bsKey,  FS_ByteString bsValue))

INTERFACE(void, FDRMCategoryWriteSetAttribute, (FDRM_CategoryWrite Writer,  FDRM_CATEGORY_HANDLER hCategory,  FS_ByteString bsName,  FS_ByteString bsValue))

INTERFACE(void, FDRMCategoryWriteRemoveAttribute, (FDRM_CategoryWrite Writer,  FDRM_CATEGORY_HANDLER hCategory,  FS_ByteString bsName))

INTERFACE(void, FDRMCategoryWriteSetCategoryData, (FDRM_CategoryWrite Writer,  FDRM_CATEGORY_HANDLER hCategory,  FS_ByteString bsData))

INTERFACE(void, FDRMCategoryWriteRemoveCategory, (FDRM_CategoryWrite Writer,  FDRM_CATEGORY_HANDLER hParent,  FS_ByteString bsCategory))

INTERFACE(void, FDRMCategoryWriteRemoveCategory2, (FDRM_CategoryWrite Writer,  FDRM_CATEGORY_HANDLER hParent,  FDRM_CATEGORY_HANDLER hCategory))

INTERFACE(void, FDRMCategoryWriteRemoveCategory3, (FDRM_CategoryWrite Writer,  FDRM_CATEGORY_HANDLER hCategory))

INTERFACE(FDRM_CategoryRead, FDRMCategoryWriteCastToCategoryRead, (FDRM_CategoryWrite Writer))

INTERFACE(void, FDRMCategoryWriteDestroy, (FDRM_CategoryWrite Writer))

NumOfSelector(FDRMCategoryWrite)
ENDENUM

//*****************************
/* DescData HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_DescData, FDRMDescDataNew, (void))

INTERFACE(void, FDRMDescDataDestroy, (FDRM_DescData data))

INTERFACE(void, FDRMDescDataGetPackageName, (FDRM_DescData data,  FS_ByteString out_PackageName))

INTERFACE(void, FDRMDescDataGetDefNameSpace, (FDRM_DescData data,  FS_ByteString out_DefNameSpace))

INTERFACE(void, FDRMDescDataGetFDRMNameSpace, (FDRM_DescData data,  FS_ByteString out_FDRMNameSpace))

INTERFACE(void, FDRMDescDataSetPackageName, (FDRM_DescData data,  FS_ByteString bsPackageName))

INTERFACE(void, FDRMDescDataSetDefNameSpace, (FDRM_DescData data,  FS_ByteString bsDefNameSpace))

INTERFACE(void, FDRMDescDataSetFDRMNameSpace, (FDRM_DescData data,  FS_ByteString bsFDRMNameSpace))

NumOfSelector(FDRMDescData)
ENDENUM

//*****************************
/* ScriptData HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_ScriptData, FDRMScriptDataNew, (void))

INTERFACE(void, FDRMScriptDataDestroy, (FDRM_ScriptData data))

INTERFACE(void, FDRMScriptDataGetDivision, (FDRM_ScriptData data,  FS_ByteString out_bsDivision))

INTERFACE(void, FDRMScriptDataGetFormatOrg, (FDRM_ScriptData data,  FS_ByteString out_bsFormatOrg))

INTERFACE(void, FDRMScriptDataGetFormatVer, (FDRM_ScriptData data,  FS_ByteString out_bsFormatVer))

INTERFACE(void, FDRMScriptDataGetAppOrg, (FDRM_ScriptData data,  FS_ByteString out_bsAppOrg))

INTERFACE(void, FDRMScriptDataGetAppVer, (FDRM_ScriptData data,  FS_ByteString out_bsAppVer))

INTERFACE(void, FDRMScriptDataGetAuthority, (FDRM_ScriptData data,  FS_ByteString out_bsAuthority))

INTERFACE(void, FDRMScriptDataSetDivision, (FDRM_ScriptData data,  FS_ByteString bsDivision))

INTERFACE(void, FDRMScriptDataSetFormatOrg, (FDRM_ScriptData data,  FS_ByteString bsFormatOrg))

INTERFACE(void, FDRMScriptDataSetFormatVer, (FDRM_ScriptData data,  FS_ByteString bsFormatVer))

INTERFACE(void, FDRMScriptDataSetAppOrg, (FDRM_ScriptData data,  FS_ByteString bsAppOrg))

INTERFACE(void, FDRMScriptDataSetAppVer, (FDRM_ScriptData data,  FS_ByteString bsAppVer))

INTERFACE(void, FDRMScriptDataSetAuthority, (FDRM_ScriptData data,  FS_ByteString bsAuthority))

NumOfSelector(FDRMScriptData)
ENDENUM

//*****************************
/* PresentationData HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_PresentationData, FDRMPresentationDataNew, (void))

INTERFACE(void, FDRMPresentationDataDestroy, (FDRM_PresentationData data))

INTERFACE(void, FDRMPresentationDataGetDivision, (FDRM_PresentationData data,  FS_ByteString out_bsDivision))

INTERFACE(void, FDRMPresentationDataGetAuthority, (FDRM_PresentationData data,  FS_ByteString out_bsAuthority))

INTERFACE(void, FDRMPresentationDataSetDivision, (FDRM_PresentationData data,  FS_ByteString bsDivision))

INTERFACE(void, FDRMPresentationDataSetAuthority, (FDRM_PresentationData data,  FS_ByteString bsAuthority))

NumOfSelector(FDRMPresentationData)
ENDENUM

//*****************************
/* SignatureData HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_SignatureData, FDRMSignatureDataNew, (void))

INTERFACE(void, FDRMSignatureDataDestroy, (FDRM_SignatureData data))

INTERFACE(void, FDRMSignatureDataGetDivision, (FDRM_SignatureData data,  FS_ByteString out_bsDivision))

INTERFACE(void, FDRMSignatureDataGetAgentOrg, (FDRM_SignatureData data,  FS_ByteString out_bsAgentOrg))

INTERFACE(void, FDRMSignatureDataGetAgentVer, (FDRM_SignatureData data,  FS_ByteString out_bsAgentVer))

INTERFACE(void, FDRMSignatureDataGetFormatOrg, (FDRM_SignatureData data,  FS_ByteString out_bsFormatOrg))

INTERFACE(void, FDRMSignatureDataGetFormatVer, (FDRM_SignatureData data,  FS_ByteString out_bsFormatVer))

INTERFACE(void, FDRMSignatureDataGetKey, (FDRM_SignatureData data,  FS_ByteString out_bsKey))

INTERFACE(void, FDRMSignatureDataSetDivision, (FDRM_SignatureData data,  FS_ByteString bsDivision))

INTERFACE(void, FDRMSignatureDataSetAgentOrg, (FDRM_SignatureData data,  FS_ByteString bsAgentOrg))

INTERFACE(void, FDRMSignatureDataSetAgentVer, (FDRM_SignatureData data,  FS_ByteString bsAgentVer))

INTERFACE(void, FDRMSignatureDataSetFormatOrg, (FDRM_SignatureData data,  FS_ByteString bsFormatOrg))

INTERFACE(void, FDRMSignatureDataSetFormatVer, (FDRM_SignatureData data,  FS_ByteString bsFormatVer))

INTERFACE(void, FDRMSignatureDataSetKey, (FDRM_SignatureData data,  FS_ByteString bsKey))

NumOfSelector(FDRMSignatureData)
ENDENUM

//*****************************
/* DescRead HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_DescRead, FDRMDescReadNew, (void))

INTERFACE(void, FDRMDescReadDestroy, (FDRM_DescRead reader))

INTERFACE(FS_INT32, FDRMDescReadLoad, (FDRM_DescRead reader,  FS_FileReadHandler file))

INTERFACE(FS_INT32, FDRMDescReadVerifyDescriptor, (FDRM_DescRead reader,  const FDRM_DescData descData))

INTERFACE(void, FDRMDescReadGetDescType, (FDRM_DescRead reader,  FS_ByteString out_bsType))

INTERFACE(FDRM_DESCSCRIPT_HANDLER, FDRMDescReadGetScript, (FDRM_DescRead reader,  const FDRM_ScriptData scriptData))

INTERFACE(FS_INT32, FDRMDescReadCountScripts, (FDRM_DescRead reader))

INTERFACE(FDRM_DESCSCRIPT_HANDLER, FDRMDescReadGetScript2, (FDRM_DescRead reader,  FS_INT32 nIndex))

INTERFACE(FS_INT32, FDRMDescReadGetScriptData, (FDRM_DescRead reader,  FDRM_DESCSCRIPT_HANDLER hScript,  FDRM_ScriptData out_scriptData))

INTERFACE(FDRM_CategoryRead, FDRMDescReadGetScriptParams, (FDRM_DescRead reader,  FDRM_DESCSCRIPT_HANDLER hScript))

INTERFACE(FDRM_DESCPRES_HANDLER, FDRMDescReadGetPresentation, (FDRM_DescRead reader,  FDRM_DESCSCRIPT_HANDLER hScript,  const FDRM_PresentationData presData))

INTERFACE(FS_INT32, FDRMDescReadGetPresentationData, (FDRM_DescRead reader,  FDRM_DESCPRES_HANDLER hPresentation,  FDRM_PresentationData out_presData))

INTERFACE(FDRM_CategoryRead, FDRMDescReadGetPresentationParams, (FDRM_DescRead reader,  FDRM_DESCPRES_HANDLER hPresentation))

INTERFACE(FDRM_DESCSIGN_HANDLER, FDRMDescReadGetSignature, (FDRM_DescRead reader,  const FDRM_SignatureData signData))

INTERFACE(FS_INT32, FDRMDescReadGetSignatureData, (FDRM_DescRead reader,  FDRM_DESCSIGN_HANDLER hSign,  FDRM_SignatureData out_signData))

INTERFACE(FDRM_CategoryRead, FDRMDescReadGetSignatureParams, (FDRM_DescRead reader,  FDRM_DESCSIGN_HANDLER hSign))

INTERFACE(FS_INT32, FDRMDescReadGetSignatureData2, (FDRM_DescRead reader,  FDRM_DESCSIGN_HANDLER hSign,  FS_ByteString out_bksData))

INTERFACE(FS_INT32, FDRMDescReadCheckSignature, (FDRM_DescRead reader,  FDRM_DESCSIGN_HANDLER hSign,  const FS_ByteString bksKey))

INTERFACE(FS_INT32, FDRMDescReadVerifyValidation, (FDRM_DescRead reader))

NumOfSelector(FDRMDescRead)
ENDENUM

//*****************************
/* DescWrite HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_DescWrite, FDRMDescWriteNew, (FS_ByteString bsType))

INTERFACE(void, FDRMDescWriteDestroy, (FDRM_DescWrite writer))

INTERFACE(FS_INT32, FDRMDescWriteInitDescriptor, (FDRM_DescWrite writer,  const FDRM_DescData descData))

INTERFACE(void, FDRMDescWriteRemoveScript, (FDRM_DescWrite writer,  FS_ByteString bsDivision))

INTERFACE(FDRM_DESCSCRIPT_HANDLER, FDRMDescWriteAddScript, (FDRM_DescWrite writer,  const FDRM_ScriptData scriptData))

INTERFACE(FS_INT32, FDRMDescWriteSetScriptFormat, (FDRM_DescWrite writer,  FDRM_DESCSCRIPT_HANDLER hScript,  FS_ByteString bsOrg,  FS_ByteString bsVer))

INTERFACE(FS_INT32, FDRMDescWriteSetScriptApplication, (FDRM_DescWrite writer,  FDRM_DESCSCRIPT_HANDLER hScript,  FS_ByteString bsOrg,  FS_ByteString bsVer))

INTERFACE(FS_INT32, FDRMDescWriteSetScriptAuthority, (FDRM_DescWrite writer,  FDRM_DESCSCRIPT_HANDLER hScript,  FS_ByteString bsAuth))

INTERFACE(FDRM_CategoryWrite, FDRMDescWriteSetScriptParams, (FDRM_DescWrite writer,  FDRM_DESCSCRIPT_HANDLER hScript))

INTERFACE(void, FDRMDescWriteRemovePresentation, (FDRM_DescWrite writer,  FDRM_DESCSCRIPT_HANDLER hScript,  FS_ByteString bsDivision))

INTERFACE(FDRM_DESCPRES_HANDLER, FDRMDescWriteAddPresentation, (FDRM_DescWrite writer,  FDRM_DESCSCRIPT_HANDLER hScript,  const FDRM_PresentationData presData))

INTERFACE(FS_INT32, FDRMDescWriteSetPresentationAuthority, (FDRM_DescWrite writer,  FDRM_DESCPRES_HANDLER hPresentation,  FS_ByteString bsAuth))

INTERFACE(FDRM_CategoryWrite, FDRMDescWriteSetPresentationParams, (FDRM_DescWrite writer,  FDRM_DESCPRES_HANDLER hPresentation))

INTERFACE(void, FDRMDescWriteRemoveSignature, (FDRM_DescWrite writer,  FS_ByteString bsDivision))

INTERFACE(FDRM_DESCSIGN_HANDLER, FDRMDescWriteAddSignature, (FDRM_DescWrite writer,  const FDRM_SignatureData signData))

INTERFACE(FS_INT32, FDRMDescWriteSetSignatureAgent, (FDRM_DescWrite writer,  FDRM_DESCSIGN_HANDLER hSign,  FS_ByteString bsOrg,  FS_ByteString bsVer))

INTERFACE(FS_INT32, FDRMDescWriteSetSignatureFormat, (FDRM_DescWrite writer,  FDRM_DESCSIGN_HANDLER hSign,  FS_ByteString bsOrg,  FS_ByteString bsVer))

INTERFACE(FDRM_CategoryWrite, FDRMDescWriteSetSignatureParams, (FDRM_DescWrite writer,  FDRM_DESCSIGN_HANDLER hSign))

INTERFACE(FS_INT32, FDRMDescWriteSetSignatureKey, (FDRM_DescWrite writer,  FDRM_DESCSIGN_HANDLER hSign,  const FS_ByteString bksKey))

INTERFACE(FS_BOOL, FDRMDescWriteSave, (FDRM_DescWrite writer,  FS_FileWriteHandler fileWrite))

INTERFACE(FDRM_DescRead, FDRMDescWriteCastToDescRead, (FDRM_DescWrite writer))

NumOfSelector(FDRMDescWrite)
ENDENUM

//*****************************
/* FoacRead HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_FoacRead, FDRMFoacReadNew, (FDRM_DescRead descRead))

INTERFACE(void, FDRMFoacReadDestroy, (FDRM_FoacRead reader))

INTERFACE(FDRM_DescRead, FDRMFoacReadGetDescRead, (FDRM_FoacRead reader))

INTERFACE(FS_INT32, FDRMFoacReadVerifyFoac, (FDRM_FoacRead reader,  const FDRM_DescData descData,  const FDRM_ScriptData scriptData))

INTERFACE(FS_INT32, FDRMFoacReadGetType, (FDRM_FoacRead reader,  FS_ByteString out_bsType))

INTERFACE(FS_INT32, FDRMFoacReadGetSessionID, (FDRM_FoacRead reader,  FS_ByteString out_bsSessionID))

INTERFACE(FS_INT32, FDRMFoacReadGetRequestID, (FDRM_FoacRead reader,  FS_ByteString out_bsID))

INTERFACE(FDRM_CategoryRead, FDRMFoacReadGetRequestData, (FDRM_FoacRead reader))

INTERFACE(FS_INT32, FDRMFoacReadGetAnswerState, (FDRM_FoacRead reader,  FS_ByteString out_bsState))

INTERFACE(FDRM_CategoryRead, FDRMFoacReadGetAnswerData, (FDRM_FoacRead reader))

NumOfSelector(FDRMFoacRead)
ENDENUM

//*****************************
/* FoacWrite HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_FoacWrite, FDRMFoacWriteNew, (FDRM_DescWrite descWrite))

INTERFACE(void, FDRMFoacWriteDestroy, (FDRM_FoacWrite writer))

INTERFACE(FDRM_DescWrite, FDRMFoacWriteGetDescWrite, (FDRM_FoacWrite writer))

INTERFACE(FS_INT32, FDRMFoacWriteInitFoac, (FDRM_FoacWrite writer,  const FDRM_DescData descData,  const FDRM_ScriptData scriptData))

INTERFACE(FS_INT32, FDRMFoacWriteSetSessionID, (FDRM_FoacWrite writer,  FS_ByteString bsSessionID))

INTERFACE(FS_INT32, FDRMFoacWriteSetRequestID, (FDRM_FoacWrite writer,  FS_ByteString bsID))

INTERFACE(FDRM_CategoryWrite, FDRMFoacWriteSetRequestData, (FDRM_FoacWrite writer))

INTERFACE(FS_INT32, FDRMFoacWriteSetAnswerState, (FDRM_FoacWrite writer,  FS_ByteString bsState))

INTERFACE(FDRM_CategoryWrite, FDRMFoacWriteSetAnswerData, (FDRM_FoacWrite writer))

INTERFACE(FDRM_FoacRead, FDRMFoacWriteCastToFoacRead, (FDRM_FoacWrite writer))

NumOfSelector(FDRMFoacWrite)
ENDENUM

//*****************************
/* EnvelopeRead HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_EnvelopeRead, FDRMEnvelopeReadNew, (void))

INTERFACE(void, FDRMEnvelopeReadDestroy, (FDRM_EnvelopeRead envRead))

INTERFACE(FS_BOOL, FDRMEnvelopeReadLoadEnvelope, (FDRM_EnvelopeRead envRead,  FS_FileReadHandler fileRead))

INTERFACE(FS_BOOL, FDRMEnvelopeReadGetFormat, (FDRM_EnvelopeRead envRead,  FS_WideString out_wsOrg,  FS_WideString out_wsVer))

INTERFACE(FS_BOOL, FDRMEnvelopeReadGetApplication, (FDRM_EnvelopeRead envRead,  FS_WideString out_wsOrg,  FS_WideString out_wsVer))

INTERFACE(FS_BOOL, FDRMEnvelopeReadGetEnvelopeSN, (FDRM_EnvelopeRead envRead,  FS_WideString out_wsSN))

INTERFACE(FS_BOOL, FDRMEnvelopeReadGetFileID, (FDRM_EnvelopeRead envRead,  FS_WideString out_wsFileId))

INTERFACE(FS_BOOL, FDRMEnvelopeReadGetIssuer, (FDRM_EnvelopeRead envRead,  FS_WideString out_wsIssuerId,  FS_WideString out_wsIssuerCertSN,  FS_WideString out_wsIssuerServiceURL))

INTERFACE(FS_BOOL, FDRMEnvelopeReadGetConsumerId, (FDRM_EnvelopeRead envRead,  FS_WideString out_wsConsumerId))

INTERFACE(FS_INT32, FDRMEnvelopeReadCountAuthKeys, (FDRM_EnvelopeRead envRead))

INTERFACE(FS_BOOL, FDRMEnvelopeReadGetAuthKey, (FDRM_EnvelopeRead envRead,  FS_INT32 nIndex,  FS_WideString out_wsKeyId,  FS_WideString out_wsTreatment,  FS_WideString out_wsAuthValue))

INTERFACE(FS_INT32, FDRMEnvelopeReadCountLimits, (FDRM_EnvelopeRead envRead))

INTERFACE(FS_BOOL, FDRMEnvelopeReadGetLimit, (FDRM_EnvelopeRead envRead,  FS_INT32 nIndex,  FS_WideString out_wsType,  FS_WideString out_wsValue))

INTERFACE(FS_INT32, FDRMEnvelopeReadCountRights, (FDRM_EnvelopeRead envRead))

INTERFACE(FS_BOOL, FDRMEnvelopeReadGetRight, (FDRM_EnvelopeRead envRead,  FS_INT32 nIndex,  FS_WideString out_wsRightType))

INTERFACE(FS_BOOL, FDRMEnvelopeReadGetCipher, (FDRM_EnvelopeRead envRead,  FS_WideString out_wsAlgorithm,  FS_WideString out_wsEncryptKey))

INTERFACE(FS_BOOL, FDRMEnvelopeReadValidateEnvelope, (FDRM_EnvelopeRead envRead))

NumOfSelector(FDRMEnvelopeRead)
ENDENUM

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
//----------_V18----------
//----------_V19----------
//----------_V20----------

/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

//*****************************
/* Template HFT functions */
//*****************************

BEGINENUM

INTERFACE(FRMS_Template, FRMSTemplateNew, (FS_LPWSTR wsTemplateFile))

INTERFACE(FRMS_Template, FRMSTemplateNew2, (FS_LPWSTR wsName, UINT lcid, FS_LPWSTR wsDescription))

INTERFACE(void, FRMSTemplateRelease, (FRMS_Template tmplt))

INTERFACE(FS_BOOL, FRMSTemplateSave, (FRMS_Template tmplt, FS_LPWSTR wsTemplateFile))

INTERFACE(FS_BOOL, FRMSTemplateIsOfficial, (FRMS_Template tmplt))

INTERFACE(void, FRMSTemplateGetContentGUID, (FRMS_Template tmplt, FS_WideString* wsGUID))

INTERFACE(void, FRMSTemplateGetFilePath, (FRMS_Template tmplt, FS_WideString* wsFilwPath))

INTERFACE(FS_INT32, FRMSTemplateCountUsers, (FRMS_Template tmplt))

INTERFACE(void, FRMSTemplateGetUser, (FRMS_Template tmplt, FS_INT32 index, FS_WideString* wsUserEmail))

INTERFACE(FS_BOOL, FRMSTemplateAddUserWithEmail, (FRMS_Template tmplt, FS_LPWSTR wsUserEmail))
	
INTERFACE(FS_BOOL, FRMSTemplateRemoveUser, (FRMS_Template tmplt, FS_LPWSTR wsUserName))

INTERFACE(FS_INT32, FRMSTemplateCountRights, (FRMS_Template tmplt, FS_LPWSTR wsUserEmail))

INTERFACE(FS_BOOL, FRMSTemplateAddRight, (FRMS_Template tmplt, FS_LPWSTR wsUserEmail, FS_LPWSTR pwszRight))

INTERFACE(FS_BOOL, FRMSTemplateGetRight, (FRMS_Template tmplt, FS_LPWSTR wsUserEmail, FS_INT32 index, FS_WideString* wsRight))

INTERFACE(FS_BOOL, FRMSTemplateRemoveRight, (FRMS_Template tmplt, FS_LPWSTR wsUserEmail, FS_LPWSTR pwszRight))

INTERFACE(FS_INT32, FRMSTemplateCountTemplateIDs, (FRMS_Template tmplt))

INTERFACE(FS_BOOL, FRMSTemplateGetTemplateID, (FRMS_Template tmplt, FS_INT32 index, FS_WideString* wsName, LCID* lcid, FS_WideString* wsDescription))

INTERFACE(FS_BOOL, FRMSTemplateAddTemplateID, (FRMS_Template tmplt, FS_LPWSTR wsName, LCID lcid, FS_LPWSTR wsDescription))

INTERFACE(FS_BOOL, FRMSTemplateRemoveTemplateID, (FRMS_Template tmplt, FS_INT32 index))	

INTERFACE(FS_BOOL, FRMSTemplateGetContentExpiration, (FRMS_Template tmplt, FS_INT32* uDays))

INTERFACE(FS_BOOL, FRMSTemplateGetContentExpirationDate, (FRMS_Template tmplt, FS_WideString* wsFrom, FS_WideString* wsUntil))

INTERFACE(FS_BOOL, FRMSTemplateGetLicenseExpiration, (FRMS_Template tmplt, FS_INT32* uDays))

INTERFACE(FS_BOOL, FRMSTemplateSetLicenseExpiration, (FRMS_Template tmplt, UINT uDays))

INTERFACE(FS_BOOL, FRMSTemplateGetRightRequestURL, (FRMS_Template tmplt, FS_WideString* wsURL))

INTERFACE(FS_BOOL, FRMSTemplateGetRevocationListURL, (FRMS_Template tmplt, FS_WideString* URL))

INTERFACE(FS_BOOL, FRMSTemplateGetRevocationRefreshFrequency, (FRMS_Template tmplt, SYSTEMTIME* pstFrequency))

INTERFACE(FS_BOOL, FRMSTemplateSetMetaData, (FRMS_Template tmplt, FS_LPWSTR pwszContentId, FS_LPWSTR pwszContentIdType, FS_LPWSTR pwszSKUId, FS_LPWSTR pwszSKUIdType, FS_LPWSTR pwszContentType, FS_LPWSTR pwszContentName))

INTERFACE(FS_INT32, FRMSTemplateCountApplicationSpecificData, (FRMS_Template tmplt))

INTERFACE(FS_BOOL, FRMSTemplateRemoveApplicationSpecificData, (FRMS_Template tmplt, FS_INT32 index))

INTERFACE(FS_BOOL, FRMSTemplateSetApplicationSpecificData, (FRMS_Template tmplt, FS_LPWSTR wsName, FS_LPWSTR wsValue))

INTERFACE(FS_BOOL, FRMSTemplateGetApplicationSpecificData, (FRMS_Template tmplt, FS_INT32 index, FS_WideString* wsName, FS_WideString* wsValue))

INTERFACE(FS_BOOL, FRMSTemplateSetRevocationPoint, (FRMS_Template tmplt, FS_LPWSTR pwszId, FS_LPWSTR pwszIdType, FS_LPWSTR pwszURL, SYSTEMTIME* pstFrequency, FS_LPWSTR pwszName, FS_LPWSTR pwszPublicKey))

NumOfSelector(FRMSTemplate)
ENDENUM


//*****************************
/* Common HFT functions */
//*****************************

BEGINENUM

INTERFACE(void, FRMSCommonSetDefServer, (FS_LPWSTR pwszCertURL, FS_LPWSTR pwszLicensingURL))

INTERFACE(void, FRMSCommonSetDefCredential, (FS_LPWSTR pwszUserEmail))

INTERFACE(FRMSHRESULT, FRMSCommonIsActivated, (FS_INT32 nType, FS_LPWSTR pwszUserEmail))

INTERFACE(FRMSHRESULT, FRMSCommonActivate, (FS_INT32 nType, FS_LPWSTR pwszCertURL, HWND hWnd, FS_WideString* wsResult))

INTERFACE(FRMSHRESULT, FRMSCommonCreateBoundLicense, (FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszEULChain, FS_LPWSTR pwszRightsRequested))

INTERFACE(void, FRMSCommonRegisterCommonEventHandler, (FRMS_CommonEventCallbacks commonEventCallbacks))

NumOfSelector(FRMSCommon)
ENDENUM

//*****************************
/* Decryption HFT functions */
//*****************************

BEGINENUM

INTERFACE(FS_BOOL, FRMSDecryptionGetSIL, (FPD_Object encryptDict, FS_WideString* wsIL))

INTERFACE(FRMSHRESULT, FRMSDecryptionAcquireEULChain, (FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszSIL, FS_LPWSTR pwszLicensingURL, FS_WideString* wsEULChain))

INTERFACE(FRMSHRESULT, FRMSDecryptionAcquireRevocationList, (FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszSIL, FS_LPWSTR pwszEULChain))

INTERFACE(FRMSHRESULT, FRMSDecryptionRegisterLocalRevocationList, (FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszSIL))

INTERFACE(void, FRMSDecryptionRegisterDecryptionEventHandler, (FRMS_DecryptionEventCallbacks decryptionEventCallbacks))

INTERFACE(void, FRMSDecryptionRegisterCusAuthHandler, (FRMS_DecryptionCusAuthCallbacks callbacks))

INTERFACE(FRMSHRESULT, FRMSDecryptionGetAppDataCount, (FS_LPWSTR pwszEULChain, FS_INT32* outCount))

INTERFACE(FRMSHRESULT, FRMSDecryptionGetAppDataByIndex, (FS_LPWSTR pwszEULChain, FS_INT32 iIndex, FS_WideString &wsName, FS_WideString &wsValve))

INTERFACE(FRMSHRESULT, FRMSDecryptionGetUserRightsFromEULChain, (FS_LPWSTR pwszEULChain, FS_WideString* outUserName, FS_WideStringArray* outRihgtsArr))

NumOfSelector(FRMSDecryption)
ENDENUM

//*****************************
/* Encryption HFT functions  */
//*****************************

BEGINENUM

INTERFACE(void, FRMSEncryptionSetDefTemplate, (FS_LPWSTR pwszPath))

INTERFACE(FS_BOOL, FRMSEncryptionDoEncryption, ())

INTERFACE(void, FRMSEncryptionRegisterEncryptionEventHandler, (FRMS_EncryptionEventCallbacks encryptionEventCallbacks))

NumOfSelector(FRMSEncryption)
ENDENUM
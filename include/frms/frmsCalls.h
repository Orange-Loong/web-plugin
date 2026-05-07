/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FRMS_CALLS_H
#define FRMS_CALLS_H

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FRMS_EXPT_H
#include "frmsExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif//__cplusplus

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file frmsImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "frmsTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file frmsImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
	typedef returnType (*interfaceName##SELPROTO)params;
#include "frmsTempl.h"

/*The Template HFT name.*/
#define HFT_NAME_TEMPLATE "FRMS Template"

/*The Decryption HFT name.*/
#define HFT_NAME_DECRYPTION "FRMS Decryption"

/*The Encryption HFT name.*/
#define HFT_NAME_ENCRYPTION "FRMS Encryption"

/*The Environment HFT name.*/
#define HFT_NAME_COMMON "FRMS Common"
	
/*The extension HFT version.*/
#define EXTENSION_HFT_VERSION 1
	
extern FS_HFT frmsTemplateHFT;

extern FS_HFT frmsDecryptionHFT;

extern FS_HFT frmsEncryptionHFT;

extern FS_HFT frmsCommonHFT;

//*****************************
/* Template HFT functions */
//*****************************

/*Define the template methods as macros.*/
#define FRMSTemplateNew (*(FRMSTemplateNewSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateNewSEL)))

#define FRMSTemplateNew2 (*(FRMSTemplateNew2SELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateNew2SEL)))

#define FRMSTemplateRelease (*(FRMSTemplateReleaseSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateReleaseSEL)))

#define FRMSTemplateSave (*(FRMSTemplateSaveSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateSaveSEL)))

#define FRMSTemplateIsOfficial (*(FRMSTemplateIsOfficialSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateIsOfficialSEL)))

#define FRMSTemplateGetContentGUID (*(FRMSTemplateGetContentGUIDSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetContentGUIDSEL)))

#define FRMSTemplateGetFilePath (*(FRMSTemplateGetFilePathSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetFilePathSEL)))

#define FRMSTemplateCountUsers (*(FRMSTemplateCountUsersSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateCountUsersSEL)))

#define FRMSTemplateGetUser (*(FRMSTemplateGetUserSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetUserSEL)))

#define FRMSTemplateAddUserWithEmail (*(FRMSTemplateAddUserWithEmailSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateAddUserWithEmailSEL)))

#define FRMSTemplateRemoveUser (*(FRMSTemplateRemoveUserSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateRemoveUserSEL)))

#define FRMSTemplateCountRights (*(FRMSTemplateCountRightsSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateCountRightsSEL)))

#define FRMSTemplateAddRight (*(FRMSTemplateAddRightSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateAddRightSEL)))

#define FRMSTemplateGetRight (*(FRMSTemplateGetRightSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetRightSEL)))

#define FRMSTemplateRemoveRight (*(FRMSTemplateRemoveRightSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateRemoveRightSEL)))

#define FRMSTemplateCountTemplateIDs (*(FRMSTemplateCountTemplateIDsSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateCountTemplateIDsSEL)))

#define FRMSTemplateGetTemplateID (*(FRMSTemplateGetTemplateIDSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetTemplateIDSEL)))

#define FRMSTemplateAddTemplateID (*(FRMSTemplateAddTemplateIDSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateAddTemplateIDSEL)))

#define FRMSTemplateRemoveTemplateID (*(FRMSTemplateRemoveTemplateIDSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateRemoveTemplateIDSEL)))

#define FRMSTemplateGetContentExpiration (*(FRMSTemplateGetContentExpirationSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetContentExpirationSEL)))

#define FRMSTemplateGetContentExpirationDate (*(FRMSTemplateGetContentExpirationDateSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetContentExpirationDateSEL)))

#define FRMSTemplateGetLicenseExpiration (*(FRMSTemplateGetLicenseExpirationSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetLicenseExpirationSEL)))

#define FRMSTemplateSetLicenseExpiration (*(FRMSTemplateSetLicenseExpirationSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateSetLicenseExpirationSEL)))

#define FRMSTemplateGetRightRequestURL (*(FRMSTemplateGetRightRequestURLSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetRightRequestURLSEL)))

#define FRMSTemplateGetRevocationListURL (*(FRMSTemplateGetRevocationListURLSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetRevocationListURLSEL)))

#define FRMSTemplateGetRevocationRefreshFrequency (*(FRMSTemplateGetRevocationRefreshFrequencySELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetRevocationRefreshFrequencySEL)))

#define FRMSTemplateSetMetaData (*(FRMSTemplateSetMetaDataSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateSetMetaDataSEL)))

#define FRMSTemplateCountApplicationSpecificData (*(FRMSTemplateCountApplicationSpecificDataSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateCountApplicationSpecificDataSEL)))

#define FRMSTemplateRemoveApplicationSpecificData (*(FRMSTemplateRemoveApplicationSpecificDataSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateRemoveApplicationSpecificDataSEL)))

#define FRMSTemplateSetApplicationSpecificData (*(FRMSTemplateSetApplicationSpecificDataSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateSetApplicationSpecificDataSEL)))

#define FRMSTemplateGetApplicationSpecificData (*(FRMSTemplateGetApplicationSpecificDataSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateGetApplicationSpecificDataSEL)))

#define FRMSTemplateSetRevocationPoint (*(FRMSTemplateSetRevocationPointSELPROTO)(FSExtensionHFTMgrGetEntry(frmsTemplateHFT, FRMSTemplateSetRevocationPointSEL)))

//*****************************
/* Common HFT functions */
//*****************************

/*Define the common methods as macros.*/
#define FRMSCommonSetDefServer (*(FRMSCommonSetDefServerSELPROTO)(FSExtensionHFTMgrGetEntry(frmsCommonHFT, FRMSCommonSetDefServerSEL)))

#define FRMSCommonSetDefCredential (*(FRMSCommonSetDefCredentialSELPROTO)(FSExtensionHFTMgrGetEntry(frmsCommonHFT, FRMSCommonSetDefCredentialSEL)))

#define FRMSCommonIsActivated (*(FRMSCommonIsActivatedSELPROTO)(FSExtensionHFTMgrGetEntry(frmsCommonHFT, FRMSCommonIsActivatedSEL)))

#define FRMSCommonActivate (*(FRMSCommonActivateSELPROTO)(FSExtensionHFTMgrGetEntry(frmsCommonHFT, FRMSCommonActivateSEL)))

#define FRMSCommonCreateBoundLicense (*(FRMSCommonCreateBoundLicenseSELPROTO)(FSExtensionHFTMgrGetEntry(frmsCommonHFT, FRMSCommonCreateBoundLicenseSEL)))

#define FRMSCommonRegisterCommonEventHandler (*(FRMSCommonRegisterCommonEventHandlerSELPROTO)(FSExtensionHFTMgrGetEntry(frmsCommonHFT, FRMSCommonRegisterCommonEventHandlerSEL)))

//*****************************
/* Decryption HFT functions */
//*****************************

/*Define the decryption methods as macros.*/
#define FRMSDecryptionGetSIL (*(FRMSDecryptionGetSILSELPROTO)(FSExtensionHFTMgrGetEntry(frmsDecryptionHFT, FRMSDecryptionGetSILSEL)))

#define FRMSDecryptionAcquireEULChain (*(FRMSDecryptionAcquireEULChainSELPROTO)(FSExtensionHFTMgrGetEntry(frmsDecryptionHFT, FRMSDecryptionAcquireEULChainSEL)))

#define FRMSDecryptionAcquireRevocationList (*(FRMSDecryptionAcquireRevocationListSELPROTO)(FSExtensionHFTMgrGetEntry(frmsDecryptionHFT, FRMSDecryptionAcquireRevocationListSEL)))

#define FRMSDecryptionRegisterLocalRevocationList (*(FRMSDecryptionRegisterLocalRevocationListSELPROTO)(FSExtensionHFTMgrGetEntry(frmsDecryptionHFT, FRMSDecryptionRegisterLocalRevocationListSEL)))

#define FRMSDecryptionRegisterDecryptionEventHandler (*(FRMSDecryptionRegisterDecryptionEventHandlerSELPROTO)(FSExtensionHFTMgrGetEntry(frmsDecryptionHFT, FRMSDecryptionRegisterDecryptionEventHandlerSEL)))

#define FRMSDecryptionRegisterCusAuthHandler (*(FRMSDecryptionRegisterCusAuthHandlerSELPROTO)(FSExtensionHFTMgrGetEntry(frmsDecryptionHFT, FRMSDecryptionRegisterCusAuthHandlerSEL)))

#define FRMSDecryptionGetAppDataCount (*(FRMSDecryptionGetAppDataCountSELPROTO)(FSExtensionHFTMgrGetEntry(frmsDecryptionHFT, FRMSDecryptionGetAppDataCountSEL)))

#define FRMSDecryptionGetAppDataByIndex (*(FRMSDecryptionGetAppDataByIndexSELPROTO)(FSExtensionHFTMgrGetEntry(frmsDecryptionHFT, FRMSDecryptionGetAppDataByIndexSEL)))

#define FRMSDecryptionGetUserRightsFromEULChain (*(FRMSDecryptionGetUserRightsFromEULChainSELPROTO)(FSExtensionHFTMgrGetEntry(frmsDecryptionHFT, FRMSDecryptionGetUserRightsFromEULChainSEL)))

//*****************************
/* Encryption HFT functions	 */
//*****************************

/*Define the encryption methods as macros.*/
#define FRMSEncryptionSetDefTemplate (*(FRMSEncryptionSetDefTemplateSELPROTO)(FSExtensionHFTMgrGetEntry(frmsEncryptionHFT, FRMSEncryptionSetDefTemplateSEL)))

#define FRMSEncryptionDoEncryption (*(FRMSEncryptionDoEncryptionSELPROTO)(FSExtensionHFTMgrGetEntry(frmsEncryptionHFT, FRMSEncryptionDoEncryptionSEL)))

#define FRMSEncryptionRegisterEncryptionEventHandler (*(FRMSEncryptionRegisterEncryptionEventHandlerSELPROTO)(FSExtensionHFTMgrGetEntry(frmsEncryptionHFT, FRMSEncryptionRegisterEncryptionEventHandlerSEL)))

#ifdef __cplusplus
};
#endif//__cplusplus

#endif//FRMS_CALLS_H
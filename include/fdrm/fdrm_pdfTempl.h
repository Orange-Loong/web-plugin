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
/* PDFSecurityHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_PDFSecurityHandler, FDRMPDFSecurityHandlerNew, (void))

INTERFACE(void, FDRMPDFSecurityHandlerDestroy, (FDRM_PDFSecurityHandler hanlder))

INTERFACE(FS_BOOL, FDRMPDFSecurityHandlerInit, (FDRM_PDFSecurityHandler hanlder,  FPD_Parser parser,  FPD_Object encryptDict))

INTERFACE(FS_DWORD, FDRMPDFSecurityHandlerGetPermissions, (FDRM_PDFSecurityHandler hanlder))

INTERFACE(FS_BOOL, FDRMPDFSecurityHandlerIsOwner, (FDRM_PDFSecurityHandler hanlder))

INTERFACE(FS_BOOL, FDRMPDFSecurityHandlerGetCryptInfo, (FDRM_PDFSecurityHandler hanlder,  int* out_cipher,  FS_LPCBYTE* out_buffer,  int* out_keylen))

INTERFACE(FS_BOOL, FDRMPDFSecurityHandlerSetSubFilter, (FDRM_PDFSecurityHandler hanlder,  FS_ByteString bsSubFilter))

INTERFACE(FS_BOOL, FDRMPDFSecurityHandlerSetIdentityEntry, (FDRM_PDFSecurityHandler hanlder,  FS_ByteString bsEntryName,  FS_ByteString bsEntryValue))

INTERFACE(FS_BOOL, FDRMPDFSecurityHandlerGetSubFilter, (FDRM_PDFSecurityHandler hanlder,  FS_ByteString* out_bsSubFilter))

INTERFACE(FS_BOOL, FDRMPDFSecurityHandlerGetIdentityEntry, (FDRM_PDFSecurityHandler hanlder,  FS_ByteString bsEntryName,  FS_ByteString* outbsEntryValue))

INTERFACE(FS_BOOL, FDRMPDFSecurityHandlerSetCryptInfo, (FDRM_PDFSecurityHandler hanlder,  int nCipher,  const FS_LPCBYTE keyBuf,  int nKeylen))

INTERFACE(FS_BOOL, FDRMPDFSecurityHandlerCheckValidity, (FDRM_PDFSecurityHandler hanlder))

INTERFACE(FDRM_PDFCryptoHandler, FDRMPDFSecurityHandlerCreateCryptoHandler, (FDRM_PDFSecurityHandler hanlder))

NumOfSelector(FDRMPDFSecurityHandler)
ENDENUM

//*****************************
/* PDFSchema HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_PDFSchema, FDRMPDFSchemaNew, (void))

INTERFACE(void, FDRMPDFSchemaDestroy, (FDRM_PDFSchema schema))

INTERFACE(FS_INT32, FDRMPDFSchemaLoadSchema, (FDRM_PDFSchema schema,  FS_FileReadHandler schemaFile))

INTERFACE(FS_INT32, FDRMPDFSchemaGetPDFFileSize, (FDRM_PDFSchema schema))

INTERFACE(FS_INT32, FDRMPDFSchemaGetXRefOffset, (FDRM_PDFSchema schema))

INTERFACE(FS_INT32, FDRMPDFSchemaCountPages, (FDRM_PDFSchema schema))

INTERFACE(FS_INT32, FDRMPDFSchemaGetSchemaInfo, (FDRM_PDFSchema schema,  FS_DWORD dwItem,  FS_DWORD dwIndex,  FS_DWordArray out_pdfObjs))

INTERFACE(FS_INT32, FDRMPDFSchemaGetPageSize, (FDRM_PDFSchema schema,  FS_INT32 pageIndex,  FS_FLOAT* out_Width,  FS_FLOAT* out_height))

NumOfSelector(FDRMPDFSchema)
ENDENUM

//*****************************
/* EncryptDictRead HFT functions */
//*****************************

BEGINENUM
INTERFACE(FDRM_EncryptDictRead, FDRMEncryptDictReadNew, (FPD_Object encryptDict))

INTERFACE(void, FDRMEncryptDictReadDestroy, (FDRM_EncryptDictRead reader))

INTERFACE(FS_BOOL, FDRMEncryptDictReadVerify, (FDRM_EncryptDictRead reader))

INTERFACE(FS_BOOL, FDRMEncryptDictReadGetSubFilter, (FDRM_EncryptDictRead reader,  FS_WideString out_SubFilter))

INTERFACE(FS_BOOL, FDRMEncryptDictReadGetIssuer, (FDRM_EncryptDictRead reader,  FS_WideString out_Issuer))

INTERFACE(FS_BOOL, FDRMEncryptDictReadGetCreator, (FDRM_EncryptDictRead reader,  FS_WideString out_Creator))

INTERFACE(FS_BOOL, FDRMEncryptDictReadGetFileId, (FDRM_EncryptDictRead reader,  FS_WideString out_FileId))

INTERFACE(FS_BOOL, FDRMEncryptDictReadGetFlowCode, (FDRM_EncryptDictRead reader,  FS_WideString out_FlowCode))

INTERFACE(FS_BOOL, FDRMEncryptDictReadGetOrder, (FDRM_EncryptDictRead reader,  FS_WideString out_Order))

INTERFACE(FS_BOOL, FDRMEncryptDictReadGetUser, (FDRM_EncryptDictRead reader,  FS_WideString out_User))

INTERFACE(FS_BOOL, FDRMEncryptDictReadGetServiceURL, (FDRM_EncryptDictRead reader,  FS_WideString out_ServiceURL))

NumOfSelector(FDRMEncryptDictRead)
ENDENUM

//*****************************
/* Encryptor HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FDRMEncryptorArcFourCryptBlock, (FS_LPBYTE data,  FS_DWORD size,  FS_LPCBYTE key,  FS_DWORD keylen))

INTERFACE(void, FDRMEncryptorArcFourSetup, (FS_LPVOID context,  FS_LPCBYTE key,  FS_DWORD length))

INTERFACE(void, FDRMEncryptorArcFourCrypt, (FS_LPVOID context,  FS_LPBYTE data,  FS_DWORD size))

INTERFACE(void, FDRMEncryptorSHA256Start, (FS_LPVOID context))

INTERFACE(void, FDRMEncryptorSHA256Update, (FS_LPVOID context,  FS_LPCBYTE data,  FS_DWORD size))

INTERFACE(void, FDRMEncryptorSHA256Finish, (FS_LPVOID context,  FS_BYTE digest[32]))

INTERFACE(FS_INT32, FDRMEncryptorSHA256DigestGenerate, (FS_LPCBYTE pBuffer,  FS_DWORD dwSize,  FS_ByteString outDigest))

INTERFACE(FS_INT32, FDRMEncryptorHashMD5128, (FS_LPCBYTE pBuffer,  FS_DWORD dwSize,  FS_ByteString outMD5))

INTERFACE(void, FDRMEncryptorAESSetKey, (FS_LPVOID context,  FS_DWORD blocklen,  FS_LPCBYTE key,  FS_DWORD keylen))

INTERFACE(void, FDRMEncryptorAESSetIV, (FS_LPVOID context,  FS_LPCBYTE iv))

INTERFACE(void, FDRMEncryptorAESDecrypt, (FS_LPVOID context,  FS_LPBYTE dest,  FS_LPCBYTE src,  FS_DWORD size))

INTERFACE(void, FDRMEncryptorAESEncrypt, (FS_LPVOID context,  FS_LPBYTE dest,  FS_LPCBYTE src,  FS_DWORD size))

INTERFACE(void, FDRMEncryptorAESSetKey2, (FS_LPVOID context,  FS_DWORD blocklen,  FS_LPCBYTE key,  FS_DWORD keylen,  FS_BOOL bEncrypt))

INTERFACE(void, FDRMEncryptorMD5Start, (FS_LPVOID context))

INTERFACE(void, FDRMEncryptorMD5Update, (FS_LPVOID context,  FS_LPCBYTE data,  FS_DWORD size))

INTERFACE(void, FDRMEncryptorMD5Finish, (FS_LPVOID context,  FS_BYTE digest[16]))

NumOfSelector(FDRMEncryptor)
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

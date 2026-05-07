/*****************************************************************************

  Copyright (C) 2024 Foxit Corporation
  All rights reserved.
  
	NOTICE: Foxit permits you to use, modify, and distribute this file
	in accordance with the terms of the Foxit license agreement
	accompanying it. If you have received this file from a source other
	than Foxit, then your use, modification, or distribution of it
	requires the prior written permission of Foxit.
	
*****************************************************************************/

#ifndef FDRM_PDFIMPL_H
#define FDRM_PDFIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../../basic/fs_basicExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../../pdf/fpd_parserExpT.h"
#endif

#ifndef FDRM_PDFEXPT_H
#include "../fdrm_pdfExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

class CFDRM_PDFSecurityHandler_V2
{
public:
	static FDRM_PDFSecurityHandler New(void);
	static void Destroy(FDRM_PDFSecurityHandler hanlder);

	static FS_BOOL		Init(FDRM_PDFSecurityHandler hanlder, FPD_Parser parser, FPD_Object encryptDict);
	static FS_DWORD		GetPermissions(FDRM_PDFSecurityHandler hanlder);
	static FS_BOOL		IsOwner(FDRM_PDFSecurityHandler hanlder);
	static FS_BOOL		GetCryptInfo(FDRM_PDFSecurityHandler hanlder, int* out_cipher, FS_LPCBYTE* out_buffer, int* out_keylen);
	static FS_BOOL 		SetSubFilter(FDRM_PDFSecurityHandler hanlder, FS_ByteString bsSubFilter);

	static FS_BOOL 	SetIdentityEntry(FDRM_PDFSecurityHandler hanlder, FS_ByteString bsEntryName, FS_ByteString bsEntryValue);
	static FS_BOOL 	GetSubFilter(FDRM_PDFSecurityHandler hanlder, FS_ByteString* out_bsSubFilter);
	static FS_BOOL 	GetIdentityEntry(FDRM_PDFSecurityHandler hanlder, FS_ByteString bsEntryName, FS_ByteString* outbsEntryValue);
	static FS_BOOL	SetCryptInfo(FDRM_PDFSecurityHandler hanlder, int nCipher, const FS_LPCBYTE keyBuf, int nKeylen);
	static FS_BOOL	CheckValidity(FDRM_PDFSecurityHandler hanlder);
	static FDRM_PDFCryptoHandler	CreateCryptoHandler(FDRM_PDFSecurityHandler hanlder);
};


class CFDRM_PDFSchema_V2
{
public:
	static FDRM_PDFSchema New(void);
	static void Destroy(FDRM_PDFSchema schema);

	static FS_INT32			LoadSchema(FDRM_PDFSchema schema, FS_FileReadHandler schemaFile);
	static FS_INT32			GetPDFFileSize(FDRM_PDFSchema schema);
	static FS_INT32			GetXRefOffset(FDRM_PDFSchema schema);
	static FS_INT32			CountPages(FDRM_PDFSchema schema);
	static FS_INT32			GetSchemaInfo(FDRM_PDFSchema schema, FS_DWORD dwItem, FS_DWORD dwIndex, FS_DWordArray out_pdfObjs);
	static FS_INT32			GetPageSize(FDRM_PDFSchema schema, FS_INT32 pageIndex, FS_FLOAT* out_Width, FS_FLOAT* out_height); 

};

class CFDRM_EncryptDictRead_V2
{
public:
	static FDRM_EncryptDictRead New(FPD_Object encryptDict);
	static void Destroy(FDRM_EncryptDictRead reader);

	static FS_BOOL		Verify(FDRM_EncryptDictRead reader);	
	static FS_BOOL		GetSubFilter(FDRM_EncryptDictRead reader, FS_WideString out_SubFilter);
	static FS_BOOL		GetIssuer(FDRM_EncryptDictRead reader, FS_WideString out_Issuer);
	static FS_BOOL		GetCreator(FDRM_EncryptDictRead reader, FS_WideString out_Creator);
	static FS_BOOL		GetFileId(FDRM_EncryptDictRead reader, FS_WideString out_FileId);
	static FS_BOOL		GetFlowCode(FDRM_EncryptDictRead reader, FS_WideString out_FlowCode);
	static FS_BOOL		GetOrder(FDRM_EncryptDictRead reader, FS_WideString out_Order);	
	static FS_BOOL		GetUser(FDRM_EncryptDictRead reader, FS_WideString out_User);	
	static FS_BOOL		GetServiceURL(FDRM_EncryptDictRead reader, FS_WideString out_ServiceURL);

};

class CFDRM_Encryptor_V2
{
public:
	static void ArcFourCryptBlock(FS_LPBYTE data, FS_DWORD size, FS_LPCBYTE key, FS_DWORD keylen);
	static void ArcFourSetup(FS_LPVOID context, FS_LPCBYTE key, FS_DWORD length);
	static void ArcFourCrypt(FS_LPVOID context, FS_LPBYTE data, FS_DWORD size);
	static void SHA256Start(FS_LPVOID context);
	static void SHA256Update(FS_LPVOID context, FS_LPCBYTE data, FS_DWORD size);
	static void SHA256Finish(FS_LPVOID context, FS_BYTE digest[32]);
	static FS_INT32 SHA256DigestGenerate(FS_LPCBYTE pBuffer, FS_DWORD dwSize, FS_ByteString outDigest);
	static FS_INT32 HashMD5128(FS_LPCBYTE pBuffer, FS_DWORD dwSize, FS_ByteString outMD5);
	static void AESSetKey(FS_LPVOID context, FS_DWORD blocklen, FS_LPCBYTE key, FS_DWORD keylen);
	static void AESSetIV(FS_LPVOID context, FS_LPCBYTE iv);
	static void AESDecrypt(FS_LPVOID context, FS_LPBYTE dest, FS_LPCBYTE src, FS_DWORD size);
	static void AESEncrypt(FS_LPVOID context, FS_LPBYTE dest, FS_LPCBYTE src, FS_DWORD size);
	static void AESSetKey2(FS_LPVOID context, FS_DWORD blocklen, FS_LPCBYTE key, FS_DWORD keylen, FS_BOOL bEncrypt);

	static void MD5Start(FS_LPVOID context);
	static void MD5Update(FS_LPVOID context, FS_LPCBYTE data, FS_DWORD size);
	static void MD5Finish(FS_LPVOID context, FS_BYTE digest[16]);
};

#ifdef __cplusplus
};
#endif



#endif
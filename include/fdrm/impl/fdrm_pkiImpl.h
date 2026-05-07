/*****************************************************************************

  Copyright (C) 2024 Foxit Corporation
  All rights reserved.
  
	NOTICE: Foxit permits you to use, modify, and distribute this file
	in accordance with the terms of the Foxit license agreement
	accompanying it. If you have received this file from a source other
	than Foxit, then your use, modification, or distribution of it
	requires the prior written permission of Foxit.
	
*****************************************************************************/

#ifndef FDRM_PKIIMPL_H
#define FDRM_PKIIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../../basic/fs_basicExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../../pdf/fpd_parserExpT.h"
#endif

#ifndef FDRM_PKIEXPT_H
#include "../fdrm_pkiExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

class CFDRM_PKI_V2
{
public:
	static void CreateRsaKey(FS_INT32 nBits, FS_LPCSTR seed, FS_LPCSTR password, FS_ByteString out_bsPubKey, FS_ByteString out_bsPrvKey);
	static void RsaEncrypt(FS_ByteString bsData, FS_ByteString bsPubKey, FS_ByteString out_bsEncryptedData);
	static void RsaDecrypt(FS_ByteString bsData, FS_ByteString bsPrvKey, FS_ByteString out_bsDecryptedData);
	static void RsaSign(FS_ByteString bsData, FS_ByteString bsPrvKey, FS_ByteString out_bsSign);
	static FS_BOOL VerifyRsaSign(FS_ByteString bsData, FS_ByteString bsSign, FS_ByteString bsPubKey);
	static void CreateDsaKey(FS_LPCSTR seed, FS_LPCSTR password, FS_ByteString out_bsPubKey, FS_ByteString out_bsPrvKey);
	static void DsaSign(FS_ByteString bsData, FS_ByteString bsPrvKey, FS_ByteString out_bsSign);
	static FS_BOOL VerifyDsaSign(FS_ByteString bsData, FS_ByteString bsSign, FS_ByteString bsPubKey);
	static FS_BOOL VerifyRsaKey(FS_ByteString bsKey, FS_INT32 nBits, FS_BOOL bIsPubKey, FS_INT32* out_nRet);
	static FS_BOOL VerifyDasKey(FS_ByteString bsKey, FS_INT32 nBits, FS_BOOL bIsPubKey, FS_INT32* out_nRet);
	static FS_INT32 GenMD5Digest(FS_INT32 nBits, FS_LPCBYTE pBuffer, FS_DWORD dwSize, FS_ByteString out_bsDigest);
	
};

#ifdef __cplusplus
};
#endif



#endif
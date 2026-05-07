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
/* PKI HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FDRMPKICreateRsaKey, (FS_INT32 nBits,  FS_LPCSTR seed,  FS_LPCSTR password,  FS_ByteString out_bsPubKey,  FS_ByteString out_bsPrvKey))

INTERFACE(void, FDRMPKIRsaEncrypt, (FS_ByteString bsData,  FS_ByteString bsPubKey,  FS_ByteString out_bsEncryptedData))

INTERFACE(void, FDRMPKIRsaDecrypt, (FS_ByteString bsData,  FS_ByteString bsPrvKey,  FS_ByteString out_bsDecryptedData))

INTERFACE(void, FDRMPKIRsaSign, (FS_ByteString bsData,  FS_ByteString bsPrvKey,  FS_ByteString out_bsSign))

INTERFACE(FS_BOOL, FDRMPKIVerifyRsaSign, (FS_ByteString bsData,  FS_ByteString bsSign,  FS_ByteString bsPubKey))

INTERFACE(void, FDRMPKICreateDsaKey, (FS_LPCSTR seed,  FS_LPCSTR password,  FS_ByteString out_bsPubKey,  FS_ByteString out_bsPrvKey))

INTERFACE(void, FDRMPKIDsaSign, (FS_ByteString bsData,  FS_ByteString bsPrvKey,  FS_ByteString out_bsSign))

INTERFACE(FS_BOOL, FDRMPKIVerifyDsaSign, (FS_ByteString bsData,  FS_ByteString bsSign,  FS_ByteString bsPubKey))

INTERFACE(FS_BOOL, FDRMPKIVerifyRsaKey, (FS_ByteString bsKey,  FS_INT32 nBits,  FS_BOOL bIsPubKey,  FS_INT32* out_nRet))

INTERFACE(FS_BOOL, FDRMPKIVerifyDasKey, (FS_ByteString bsKey,  FS_INT32 nBits,  FS_BOOL bIsPubKey,  FS_INT32* out_nRet))

INTERFACE(FS_INT32, FDRMPKIGenMD5Digest, (FS_INT32 nBits,  FS_LPCBYTE pBuffer,  FS_DWORD dwSize,  FS_ByteString out_bsDigest))

NumOfSelector(FDRMPKI)
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

/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_BARCODECALLS_H
#define FPD_BARCODECALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_BARCODEEXPT_H
#include "fpd_barcodeExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_barcodeImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_barcodeTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_barcodeImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_barcodeTempl.h"

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
/* CBCCodeBase HFT functions */
//*****************************

#define FPDCBCCodeBaseGetType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseGetTypeSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseGetTypeSEL, _gPID)))

#define FPDCBCCodeBaseSetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseSetWidthSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseSetWidthSEL, _gPID)))

#define FPDCBCCodeBaseEncode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseEncodeSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseEncodeSEL, _gPID)))

#define FPDCBCCodeBaseRenderDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseRenderDeviceSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseRenderDeviceSEL, _gPID)))

#define FPDCBCCodeBaseRenderBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseRenderBitmapSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseRenderBitmapSEL, _gPID)))

#define FPDCBCCodeBaseDecode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseDecodeSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseDecodeSEL, _gPID)))

#define FPDCBCCodeBaseDecode2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseDecode2SELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseDecode2SEL, _gPID)))

#define FPDCBCCodeBaseSetCharEncoding (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseSetCharEncodingSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseSetCharEncodingSEL, _gPID)))

#define FPDCBCCodeBaseSetModuleHeight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseSetModuleHeightSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseSetModuleHeightSEL, _gPID)))

#define FPDCBCCodeBaseSetModuleWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseSetModuleWidthSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseSetModuleWidthSEL, _gPID)))

#define FPDCBCCodeBaseSetHeight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseSetHeightSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseSetHeightSEL, _gPID)))

#define FPDCBCCodeBaseSetBackgroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseSetBackgroundColorSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseSetBackgroundColorSEL, _gPID)))

#define FPDCBCCodeBaseSetBarcodeColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseSetBarcodeColorSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseSetBarcodeColorSEL, _gPID)))

#define FPDCBCCodeBaseCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseCreateSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseCreateSEL, _gPID)))

#define FPDCBCCodeBaseDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCCodeBaseDeleteSELPROTO)FRCOREROUTINE(FPDCBCCodeBaseSEL,FPDCBCCodeBaseDeleteSEL, _gPID)))

//*****************************
/* CBCDataMatrix HFT functions */
//*****************************

//*****************************
/* CBCPDF417I HFT functions */
//*****************************

#define FPDCBCPDF417ISetIsXFABarcode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCPDF417ISetIsXFABarcodeSELPROTO)FRCOREROUTINE(FPDCBCPDF417ISEL,FPDCBCPDF417ISetIsXFABarcodeSEL, _gPID)))

#define FPDCBCPDF417ISetErrorCorrectionLevel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCPDF417ISetErrorCorrectionLevelSELPROTO)FRCOREROUTINE(FPDCBCPDF417ISEL,FPDCBCPDF417ISetErrorCorrectionLevelSEL, _gPID)))

#define FPDCBCPDF417ISetTruncated (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCPDF417ISetTruncatedSELPROTO)FRCOREROUTINE(FPDCBCPDF417ISEL,FPDCBCPDF417ISetTruncatedSEL, _gPID)))

//*****************************
/* CBCQRCode HFT functions */
//*****************************

#define FPDCBCQRCodeSetVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCQRCodeSetVersionSELPROTO)FRCOREROUTINE(FPDCBCQRCodeSEL,FPDCBCQRCodeSetVersionSEL, _gPID)))

#define FPDCBCQRCodeSetErrorCorrectionLevel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCBCQRCodeSetErrorCorrectionLevelSELPROTO)FRCOREROUTINE(FPDCBCQRCodeSEL,FPDCBCQRCodeSetErrorCorrectionLevelSEL, _gPID)))

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
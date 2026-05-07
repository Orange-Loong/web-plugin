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
/* CBCCodeBase HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_BC_TYPE, FPDCBCCodeBaseGetType, (FPD_CBCCodeBase code))

INTERFACE(FS_BOOLEAN, FPDCBCCodeBaseSetWidth, (FPD_CBCCodeBase code,  FS_INT32 width))

/**
 * @brief FPDCBCCodeBaseEncode
 * @details Encode contents.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @param[in]  contents The input content need to encode.
 * @param[in]  isDevice If it is device.
 * @param[out]  exception Get exception info.
 * @param[out]  pOutWidth Get width value.
 * @param[out]  pOutHeight Get height value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDCBCCodeBaseEncode, (FPD_CBCCodeBase code,  FS_LPCWSTR contents,  FS_BOOLEAN isDevice,  FS_INT32* exception,  FS_INT32* pOutWidth,  FS_INT32* pOutHeight))

/**
 * @brief FPDCBCCodeBaseRenderDevice
 * @details Render device.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @param[in]  device The input FPD_RenderDevice.
 * @param[in]  matirx The input matrix.
 * @param[out]  exception Get exception info.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDCBCCodeBaseRenderDevice, (FPD_CBCCodeBase code,  FPD_RenderDevice device,  const FS_AffineMatrix matrix,  FS_INT32* exception))

/**
 * @brief FPDCBCCodeBaseRenderBitmap
 * @details Render device.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @param[out]  pOutBitmap The input FPD_RenderDevice.
 * @param[out]  exception Get exception info.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDCBCCodeBaseRenderBitmap, (FPD_CBCCodeBase code,  FS_DIBitmap* pOutBitmap,  FS_INT32* exception))

/**
 * @brief FPDCBCCodeBaseDecode
 * @details Decode buffer.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @param[in]  buf The input FPD_RenderDevice.
 * @param[in]  width The input width.
 * @param[in]  height The input height.
 * @param[out]  exception Get exception info.
 * @param[out]  outDecode Get the decode contents.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDCBCCodeBaseDecode, (FPD_CBCCodeBase code,  FS_BYTE* buf,  FS_INT32 width,  FS_INT32 height,  FS_INT32* exception,  FS_WideString* outDecode))

/**
 * @brief FPDCBCCodeBaseDecode2
 * @details Decode bitmap.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @param[in]  pBitmap The input FPD_RenderDevice.
 * @param[out]  exception Get exception info.
 * @param[out]  outDecode Get the decode contents.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDCBCCodeBaseDecode2, (FPD_CBCCodeBase code,  FS_DIBitmap pBitmap,  FS_INT32* exception,  FS_WideString* outDecode))

/**
 * @brief FPDCBCCodeBaseSetCharEncoding
 * @details Set char encoding.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @param[in]  encoding The input char encoding, like FPD_BC_CHAR_ENCODING.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDCBCCodeBaseSetCharEncoding, (FPD_CBCCodeBase code,  FS_INT32 encoding))

/**
 * @brief FPDCBCCodeBaseSetModuleHeight
 * @details Set module height.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @param[in]  moduleHeight The input module height.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDCBCCodeBaseSetModuleHeight, (FPD_CBCCodeBase code,  FS_INT32 moduleHeight))

/**
 * @brief FPDCBCCodeBaseSetModuleWidth
 * @details Set module width.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @param[in]  moduleWidth The input module width.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDCBCCodeBaseSetModuleWidth, (FPD_CBCCodeBase code,  FS_INT32 moduleWidth))

/**
 * @brief FPDCBCCodeBaseSetHeight
 * @details Set height.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @param[in]  height The input height.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDCBCCodeBaseSetHeight, (FPD_CBCCodeBase code,  FS_INT32 height))

/**
 * @brief FPDCBCCodeBaseSetBackgroundColor
 * @details Set background color.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @param[in]  backgroundColor The input background color.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDCBCCodeBaseSetBackgroundColor, (FPD_CBCCodeBase code,  FS_ARGB backgroundColor))

/**
 * @brief FPDCBCCodeBaseSetBarcodeColor
 * @details Set barcode color.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @param[in]  foregroundColor The input forground color.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDCBCCodeBaseSetBarcodeColor, (FPD_CBCCodeBase code,  FS_ARGB foregroundColor))

/**
 * @brief FPDCBCCodeBaseCreate
 * @details Create FPD_CBCCodeBase obj.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_CBCCodeBase, FPDCBCCodeBaseCreate, (FPD_BC_TYPE type))

/**
 * @brief FPDCBCCodeBaseDelete
 * @details Delete FPD_CBCCodeBase obj.
 * @param[in]  code The input FPD_CBCCodeBase.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 */
INTERFACE(void, FPDCBCCodeBaseDelete, (FPD_CBCCodeBase code))

NumOfSelector(FPDCBCCodeBase)
ENDENUM

//*****************************
/* CBCDataMatrix HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FPDCBCDataMatrix)
ENDENUM

//*****************************
/* CBCPDF417I HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDCBCPDF417ISetIsXFABarcode
 * @details Set if xfa barcode.
 * @param[in]  obj The input FPD_CBCPDF417I.
 * @param[in]  bXFABarcode Set if xfa barcode.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDCBCPDF417ISetIsXFABarcode, (FPD_CBCCodeBase obj,  const FS_BOOLEAN& bXFABarcode))

/**
 * @brief FPDCBCPDF417ISetErrorCorrectionLevel
 * @details Set error correction level.
 * @param[in]  obj The input FPD_CBCPDF417I.
 * @param[in]  level The input error level.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDCBCPDF417ISetErrorCorrectionLevel, (FPD_CBCCodeBase obj,  FS_INT32 level))

/**
 * @brief FPDCBCPDF417ISetTruncated
 * @details Set if it's truncate.
 * @param[in]  obj The input FPD_CBCPDF417I.
 * @param[in]  truncated Set if it's truncate.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDCBCPDF417ISetTruncated, (FPD_CBCCodeBase obj,  FS_BOOLEAN truncated))

NumOfSelector(FPDCBCPDF417I)
ENDENUM

//*****************************
/* CBCQRCode HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDCBCQRCodeSetVersion
 * @details Set version.
 * @param[in]  code The input FPD_CBCQRCode.
 * @param[in]  version The input version.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDCBCQRCodeSetVersion, (FPD_CBCCodeBase code,  FS_INT32 version))

/**
 * @brief FPDCBCQRCodeSetErrorCorrectionLevel
 * @details Set error correction level.
 * @param[in]  code The input FPD_CBCQRCode.
 * @param[in]  level The input error level.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDCBCQRCodeSetErrorCorrectionLevel, (FPD_CBCCodeBase code,  FS_INT32 level))

NumOfSelector(FPDCBCQRCode)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

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
//*****************************
/* ConvertTaggedPDFHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDConvertTaggedPDFHandlerNewHandler
 * @details Create FPD_ConvertTaggedPDFHandler.
 * @param[in]  callbacks The input FPD_ConvertTaggedPDFCallbacks.
 * @return   FPD_ConvertTaggedPDFHandler
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ConvertTaggedPDFHandler, FPDConvertTaggedPDFHandlerNewHandler, (FPD_ConvertTaggedPDFCallbacks callbacks))

/**
 * @brief FPDConvertTaggedPDFHandlerDestroyHandler
 * @details Destroy FPD_ConvertTaggedPDFHandler.
 * @param[in]  handler The input FPD_ConvertTaggedPDFHandler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDConvertTaggedPDFHandlerDestroyHandler, (FPD_ConvertTaggedPDFHandler handler))

NumOfSelector(FPDConvertTaggedPDFHandler)
ENDENUM

//*****************************
/* DestructObject HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDDestructObjectFormRecognitionCreate
 * @details Create FPD_DestructObject to from recognition.
 * @param[in]  handler The input FPD_ConvertTaggedPDFHandler.
 * @return   FPD_DestructObject
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_DestructObject, FPDDestructObjectFormRecognitionCreate, (FPD_ConvertTaggedPDFHandler handler))

/**
 * @brief FPDDestructObjectRecognitionCreateFrom
 * @details Create FPD_DestructObject from generated formedPDF on the original PDF.
 * @return   FPD_DestructObject
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_DestructObject, FPDDestructObjectRecognitionCreateFrom, ())

INTERFACE(FPD_DestructObject, FPDDestructObjectFormRecognitionCreate2, (FDF_FormRecognitionOption options))

INTERFACE(FDF_FormRecognitionHandler, FPDDestructObjectCreateFormRecHandler, (FPD_FormRecognitionCallbacks callbacks))

INTERFACE(void, FPDDestructObjectDeleteFormRecHandler, (FDF_FormRecognitionHandler handler))

INTERFACE(FDF_FormRecognitionOption, FPDDestructObjectCreateFormRecOption, ())

INTERFACE(void, FPDDestructObjectDeleteFormRecOption, (FDF_FormRecognitionOption option))

INTERFACE(FDF_FormRecognitionHandler, FPDDestructObjectGetRecCallback, (FDF_FormRecognitionOption option))

INTERFACE(void, FPDDestructObjectSetRecCallback, (FDF_FormRecognitionOption option,  FDF_FormRecognitionHandler handler))

/**
 * @brief FPDDestructObjectGetOutputPath
 * @details Get output path.
 * @param[in]  option The input FDF_FormRecognitionOption.
 * @return   FS_LPCWSTR
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
 */
INTERFACE(FS_LPCWSTR, FPDDestructObjectGetOutputPath, (FDF_FormRecognitionOption option))

/**
 * @brief FPDDestructObjectSetOutputPath
 * @details Set output path.
 * @param[in]  option The input FDF_FormRecognitionOption.
 * @param[in]  path The input output path.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
 */
INTERFACE(void, FPDDestructObjectSetOutputPath, (FDF_FormRecognitionOption option,  FS_LPCWSTR path))

/**
 * @brief FPDDestructObjectGetFileStream
 * @details Get file stream.
 * @param[in]  option The input FDF_FormRecognitionOption.
 * @return   FS_FileStream
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
 */
INTERFACE(FS_FileStream, FPDDestructObjectGetFileStream, (FDF_FormRecognitionOption option))

/**
 * @brief FPDDestructObjectSetFileStream
 * @details Set file stream.
 * @param[in]  option The input FDF_FormRecognitionOption.
 * @param[in]  fileStream The input file stream.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
 */
INTERFACE(void, FPDDestructObjectSetFileStream, (FDF_FormRecognitionOption option,  FS_FileStream fileStream))

NumOfSelector(FPDDestructObject)
ENDENUM

//*****************************
/* ConverterOptions HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDConverterOptionsNewConverterOptions
 * @details Create FDF_ConverterOptions.
 * @return   FDF_ConverterOptions   Create FDF_ConverterOptions.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FDF_ConverterOptions, FPDConverterOptionsNewConverterOptions, ())

/**
 * @brief FPDConverterOptionsDestroyConverterOptions
 * @details Destroy FDF_ConverterOptions.
 * @param[in]  option The input FDF_ConverterOptions.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDConverterOptionsDestroyConverterOptions, (FDF_ConverterOptions option))

/**
 * @brief FPDConverterOptionsGetImageDPP
 * @details Get per point of images.
 * @param[in]  option The input FDF_ConverterOptions.
 * @return   FS_FLOAT      Get per point of images.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_FLOAT, FPDConverterOptionsGetImageDPP, (FDF_ConverterOptions option))

/**
 * @brief FPDConverterOptionsSetImageDPP
 * @details Set per point of images.
 * @param[in]  option The input FDF_ConverterOptions.
 * @param[in]  dpp The input per point of images.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDConverterOptionsSetImageDPP, (FDF_ConverterOptions option,  FS_FLOAT dpp))

/**
 * @brief FPDConverterOptionsGetStopWhenTimeout
 * @details Get if stop when time out.
 * @param[in]  option The input FDF_ConverterOptions.
 * @return   FS_BOOLEAN    Get if stop when time out.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDConverterOptionsGetStopWhenTimeout, (FDF_ConverterOptions option))

/**
 * @brief FPDConverterOptionsSetStopWhenTimeout
 * @details Set if stop when time out.
 * @param[in]  option The input FDF_ConverterOptions.
 * @param[in]  bTimeOut Set if stop when time out.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDConverterOptionsSetStopWhenTimeout, (FDF_ConverterOptions option,  FS_BOOLEAN bTimeOut))

/**
 * @brief FPDConverterOptionsGetOCContext
 * @details Get the OCContext.
 * @param[in]  option The input FDF_ConverterOptions.
 * @return   FPD_OCContext Get the OCContext.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_OCContext, FPDConverterOptionsGetOCContext, (FDF_ConverterOptions option))

/**
 * @brief FPDConverterOptionsSetOCContext
 * @details Set the OCContext.
 * @param[in]  option The input FDF_ConverterOptions.
 * @param[in]  ocContext The input OCContext.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDConverterOptionsSetOCContext, (FDF_ConverterOptions option,  FPD_OCContext ocContext))

/**
 * @brief FPDConverterOptionsGetLRVersion
 * @details Get LR version.
 * @param[in]  option The input FDF_ConverterOptions.
 * @return   FS_INT32      Get LR version.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_INT32, FPDConverterOptionsGetLRVersion, (FDF_ConverterOptions option))

/**
 * @brief FPDConverterOptionsSetLRVersion
 * @details Set LR version.
 * @param[in]  option The input FDF_ConverterOptions.
 * @param[in]  version The input LR version.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDConverterOptionsSetLRVersion, (FDF_ConverterOptions option,  FS_INT32 version))

NumOfSelector(FPDConverterOptions)
ENDENUM

//*****************************
/* ConverterHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDConverterHandlerNewConvertHandler
 * @details Create FPD_ConverterHandler from FPD_ConverterCallbacks.
 * @param[in]  callbacks The input FPD_ConverterCallbacks.
 * @return   FPD_ConverterHandler
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ConverterHandler, FPDConverterHandlerNewConvertHandler, (FPD_ConverterCallbacks callbacks))

/**
 * @brief FPDConverterHandlerDestroyConvertHandler
 * @details Destroy FPD_ConverterHandler.
 * @param[in]  handler The input FPD_ConverterHandler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDConverterHandlerDestroyConvertHandler, (FPD_ConverterHandler handler))

INTERFACE(FS_BOOLEAN, FPDConverterHandlerNeedToPauseNow, (FPD_ConverterHandler handler))

INTERFACE(FS_BOOLEAN, FPDConverterHandlerPreparePage, (FPD_ConverterHandler handler,  FS_INT32 nPageIdx,  FPD_Page pPage))

INTERFACE(void, FPDConverterHandlerConfigureAnalysisOptions, (FPD_ConverterHandler handler,  FS_INT32 nPageIdx,  FPD_Page pPage,  FPD_LR_AnalysisOptions pOptions))

INTERFACE(void, FPDConverterHandlerUpdateProgress, (FPD_ConverterHandler handler,  FS_INT32 nConvertedCount))

NumOfSelector(FPDConverterHandler)
ENDENUM

//*****************************
/* Converter HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDConverterCreate
 * @details Create FPD_Converter with target object.
 * @param[in]  pTarget The input FPD_DestructObject.
 * @return   FPD_Converter
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Converter, FPDConverterCreate, (FPD_DestructObject pTarget))

/**
 * @brief FPDConverterDestroyConverter
 * @details Destory FPD_Converter.
 * @param[in]  converter The input FPD_Converter.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDConverterDestroyConverter, (FPD_Converter converter))

/**
 * @brief FPDConverterStart
 * @details Start convert by convert option.
 * @param[in]  converter The input FPD_Converter.
 * @param[in]  pPage The input FPD_Page.
 * @param[in]  pStructureElement The input FPD_LR_StructureElementRef.
 * @param[in]  options The input FDF_ConverterOptions.
 * @return   FPD_ProgressiveStatus Convert progress status.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ProgressiveStatus, FPDConverterStart, (FPD_Converter converter,  FPD_Page pPage,  FPD_LR_StructureElementRef pStructureElement,  FDF_ConverterOptions options))

/**
 * @brief FPDConverterStart2
 * @details Start convert by convert option.
 * @param[in]  converter The input FPD_Converter.
 * @param[in]  pDocument The input FPD_Document.
 * @param[in]  options The input FDF_ConverterOptions.
 * @return   FPD_ProgressiveStatus Convert progress status.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ProgressiveStatus, FPDConverterStart2, (FPD_Converter converter,  FPD_Document pDocument,  FDF_ConverterOptions options))

/**
 * @brief FPDConverterStart3
 * @details Start convert by convert option.
 * @param[in]  converter The input FPD_Converter.
 * @param[in]  pPage The input FPD_Page.
 * @param[in]  options The input FDF_ConverterOptions.
 * @return   FPD_ProgressiveStatus Convert progress status.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ProgressiveStatus, FPDConverterStart3, (FPD_Converter converter,  FPD_Page pPage,  FDF_ConverterOptions options))

/**
 * @brief FPDConverterContinue
 * @details Continue convert by convert handler.
 * @param[in]  converter The input FPD_Converter.
 * @param[in]  handler The input FPD_ConverterHandler.
 * @return   FPD_ProgressiveStatus Convert progress status.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_ProgressiveStatus, FPDConverterContinue, (FPD_Converter converter,  FPD_ConverterHandler handler))

NumOfSelector(FPDConverter)
ENDENUM

//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------

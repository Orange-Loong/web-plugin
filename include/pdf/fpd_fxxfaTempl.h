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
/* XFARenderOptions HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDXFARenderOptionsCreateXFARenderOptions
 * @details Create XFA render options.
 * @return   FPD_XFARenderOptions    Create XFA render options.
 * @note 
 */
INTERFACE(FPD_XFARenderOptions, FPDXFARenderOptionsCreateXFARenderOptions, ())

/**
 * @brief FPDXFARenderOptionsDeleteXFARenderOptions
 * @details Delete FPD_XFARenderOptions object.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDXFARenderOptionsDeleteXFARenderOptions, (FPD_XFARenderOptions options))

/**
 * @brief FPDXFARenderOptionsGetIsPrint
 * @details Get whether be print.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @return   FS_BOOLEAN          true: be print.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDXFARenderOptionsGetIsPrint, (FPD_XFARenderOptions options))

/**
 * @brief FPDXFARenderOptionsSetIsPrint
 * @details Set whether be print.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @param[in]  bPrint Set whether be print.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDXFARenderOptionsSetIsPrint, (FPD_XFARenderOptions options,  FS_BOOLEAN bPrint))

/**
 * @brief FPDXFARenderOptionsGetIsHighlight
 * @details Get whether it is highlight.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @return   FS_BOOLEAN           true: is highlight.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDXFARenderOptionsGetIsHighlight, (FPD_XFARenderOptions options))

/**
 * @brief FPDXFARenderOptionsSetIsHighlight
 * @details Set whether it is highlight
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @param[in]  bHighlight Set whether it is highlight.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDXFARenderOptionsSetIsHighlight, (FPD_XFARenderOptions options,  FS_BOOLEAN bHighlight))

/**
 * @brief FPDXFARenderOptionsGetIsConverPdf
 * @details Get whether it is convert pdf.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @return   FS_BOOLEAN           true: is convert pdf.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDXFARenderOptionsGetIsConverPdf, (FPD_XFARenderOptions options))

/**
 * @brief FPDXFARenderOptionsSetIsConverPdf
 * @details Get whether it is convert pdf.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @param[in]  bConverPdf Set whether it is convert pdf.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDXFARenderOptionsSetIsConverPdf, (FPD_XFARenderOptions options,  FS_BOOLEAN bConverPdf))

/**
 * @brief FPDXFARenderOptionsGetColorMode
 * @details Get display mode.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @return   FS_INT32           Get the color mode.
 * @note like FPD_RENDER_COLOR_NORMAL,FPD_RENDER_COLOR_GRAY
 */
INTERFACE(FS_INT32, FPDXFARenderOptionsGetColorMode, (FPD_XFARenderOptions options))

/**
 * @brief FPDXFARenderOptionsSetColorMode
 * @details Set the color mode.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @param[in]  colorMode Set the color mode.
 * @return   void
 * @note like FPD_RENDER_COLOR_NORMAL,FPD_RENDER_COLOR_GRAY
 */
INTERFACE(void, FPDXFARenderOptionsSetColorMode, (FPD_XFARenderOptions options,  FS_INT32 colorMode))

/**
 * @brief FPDXFARenderOptionsGetDocTextColor
 * @details The text and path color for custom mode.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @return   FS_COLORREF         Get the doc text color.
 * @note default is black.
 */
INTERFACE(FS_COLORREF, FPDXFARenderOptionsGetDocTextColor, (FPD_XFARenderOptions options))

/**
 * @brief FPDXFARenderOptionsSetDocTextColor
 * @details Set the doc text color.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @param[in]  color The text and path color for custom mode.
 * @return   void
 * @note default is black.
 */
INTERFACE(void, FPDXFARenderOptionsSetDocTextColor, (FPD_XFARenderOptions options,  FS_COLORREF color))

/**
 * @brief FPDXFARenderOptionsSetCustomColorMode
 * @details Set the foreground color mode for custom mode.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @param[in]  mode The input foreground color mode for custom mode.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDXFARenderOptionsSetCustomColorMode, (FPD_XFARenderOptions options,  FS_DWORD mode))

/**
 * @brief FPDXFARenderOptionsTranslateColor
 * @details Translate a color.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @param[in]  argb The input color.
 * @param[in]  objType The object type.
 * @return   FS_COLORREF        The translated color.
 * @note 
 * @Deprecated    Internal use. It has been deprecated.
 */
INTERFACE(FS_ARGB, FPDXFARenderOptionsTranslateColor, (FPD_XFARenderOptions options,  FS_ARGB argb,  FS_INT32 objType))

/**
 * @brief FPDXFARenderOptionsGetCustomColorMode
 * @details Get the foreground color mode for custom mode.
 * @param[in]  options The input FPD_XFARenderOptions object.
 * @return   FS_DWORD            Get the foreground color mode for custom mode.
 * @note 
 */
INTERFACE(FS_DWORD, FPDXFARenderOptionsGetCustomColorMode, (FPD_XFARenderOptions options))

NumOfSelector(FPDXFARenderOptions)
ENDENUM

//*****************************
/* XFARenderContext HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDXFARenderContextCreate
 * @details Create FPD_XFARenderContext.
 * @return   FPD_XFARenderContext        Create FPD_XFARenderContext.
 * @note 
 */
INTERFACE(FPD_XFARenderContext, FPDXFARenderContextCreate, ())

/**
 * @brief FPDXFARenderContextRelease
 * @details Release FPD_XFARenderContext.
 * @param[in]  context The input FPD_XFARenderContext.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDXFARenderContextRelease, (FPD_XFARenderContext context))

/**
 * @brief FPDXFARenderContextStartRender
 * @details Start render.
 * @param[in]  context The input FPD_XFARenderContext.
 * @param[in]  pPageView The input FPD_XFAPageView.
 * @param[in]  pGS The input FPD_Graphics.
 * @param[in]  pMatrix The input FS_AffineMatrix.
 * @param[in]  options The input FPD_XFARenderOptions.
 * @return   FS_INT32
 * @note 
 */
INTERFACE(FS_INT32, FPDXFARenderContextStartRender, (FPD_XFARenderContext context,  FPD_XFAPageView pPageView,  FPD_Graphics pGS,  const FS_AffineMatrix pMatrix,  const FPD_XFARenderOptions options))

/**
 * @brief FPDXFARenderContextDoRender
 * @details Do render.
 * @param[in]  context The input FPD_XFARenderContext.
 * @param[in]  pPause The input FS_PauseHandler.
 * @return   FS_INT32
 * @note 
 */
INTERFACE(FS_INT32, FPDXFARenderContextDoRender, (FPD_XFARenderContext context,  FS_PauseHandler pPause))

/**
 * @brief FPDXFARenderContextStopRender
 * @details Stop render.
 * @param[in]  context The input FPD_XFARenderContext.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDXFARenderContextStopRender, (FPD_XFARenderContext context))

NumOfSelector(FPDXFARenderContext)
ENDENUM

//*****************************
/* XFAConverter HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDXFAConverterCreate
 * @details Create XFA Converter Interface.
 * @param[in]  type The input convert type.
 * @return   void
 * @note 
 */
INTERFACE(FPD_XFAConverter, FPDXFAConverterCreate, (FPDXFA_CONVERT_TYPE type))

/**
 * @brief FPDXFAConverterRelease
 * @details Release XFA Converter Interface.
 * @param[in]  converter The input FPD_XFAConverter.
 * @return   void
 * @note When release the converter, the FPD_Document will be release also.
 */
INTERFACE(void, FPDXFAConverterRelease, (FPD_XFAConverter converter))

/**
 * @brief FPDXFAConverterStartConvert
 * @details Start convert XFA File To PDF File.
 * @param[in]  converter The input FPD_XFAConverter.
 * @param[in]  wsXFAFile The XFA file path.
 * @param[in]  wsPDFFile The PDF file path.
 * @param[in]  bUsePDFJS Whether use PDFJS, default is true.
 * @return   FPDXFA_CONVERT_STATUS
 * @note 
 */
INTERFACE(FPDXFA_CONVERT_STATUS, FPDXFAConverterStartConvert, (FPD_XFAConverter converter,  FS_LPCWSTR wsXFAFile,  FS_LPCWSTR wsPDFFile,  FS_BOOLEAN bUsePDFJS))

/**
 * @brief FPDXFAConverterStartConvert2
 * @details Start convert XFA File Stream To PDF File Stream.
 * @param[in]  converter The input FPD_XFAConverter.
 * @param[in]  fsXFAFile The XFA file stream.
 * @param[in]  fsPDFFile The PDF file stream.
 * @param[in]  bUsePDFJS Whether use PDFJS, default is true.
 * @return   FPDXFA_CONVERT_STATUS
 * @note 
 */
INTERFACE(FPDXFA_CONVERT_STATUS, FPDXFAConverterStartConvert2, (FPD_XFAConverter converter,  FS_FileReadHandler fsXFAFile,  FS_FileWriteHandler fsPDFFile,  FS_BOOLEAN bUsePDFJS))

/**
 * @brief FPDXFAConverterStartConvert3
 * @details Start convert XFA Document To PDF Document.You need to do xfa page render.
 * @param[in]  converter The input FPD_XFAConverter.
 * @param[in]  hXFADoc The XFA document handler.
 * @param[out]  pDstDocument The convert PDF document.
 * @param[in]  psrcDocument The input source document, it can't be nullptr.
 * @return   FPDXFA_CONVERT_STATUS
 * @note 
 */
INTERFACE(FPDXFA_CONVERT_STATUS, FPDXFAConverterStartConvert3, (FPD_XFAConverter converter,  PFPDXFA_HDOC hXFADoc,  FPD_Document* pDstDocument,  FPD_Document psrcDocument))

/**
 * @brief FPDXFAConverterStartConvert4
 * @details Start convert XFA Page To PDF Document.You need to do xfa page render.
 * @param[in]  converter The input FPD_XFAConverter.
 * @param[in]  pPageViewArray The XFA page views array.
 * @param[in]  PageViewCount The XFA page count.
 * @param[out]  pDstDocument The PDF document.
 * @param[in]  psrcDocument The input source document, it can't be nullptr.
 * @return   FPDXFA_CONVERT_STATUS
 * @note 
 */
INTERFACE(FPDXFA_CONVERT_STATUS, FPDXFAConverterStartConvert4, (FPD_XFAConverter converter,  FPD_XFAPageView* pPageViewArray,  const FS_INT32 PageViewCount,  FPD_Document* pDstDocument,  FPD_Document psrcDocument))

/**
 * @brief FPDXFAConverterDoConvert
 * @details Continue convert.
 * @param[in]  converter The input FPD_XFAConverter.
 * @param[in]  pPause The pause interface.
 * @return   FPDXFA_CONVERT_STATUS
 * @note 
 */
INTERFACE(FPDXFA_CONVERT_STATUS, FPDXFAConverterDoConvert, (FPD_XFAConverter converter,  FS_PauseHandler pPause))

NumOfSelector(FPDXFAConverter)
ENDENUM

//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------

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
/* LongImageEncoder HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLongImageEncoderCreateLongImageEncoder
 * @details Create FPD_LongImageEncoder.
 * @return   FPD_LongImageEncoder         Return FPD_LongImageEncoder.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_LongImageEncoder, FPDLongImageEncoderCreateLongImageEncoder, (FPD_LongImageEncoderCallbacks callbacks))

/**
 * @brief FPDLongImageEncoderDeleteLongImageEncoder
 * @details Delete FPD_LongImageEncoder.
 * @param[in]  imageEncode The input FPD_LongImageEncoder.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDLongImageEncoderDeleteLongImageEncoder, (FPD_LongImageEncoder imageEncode))

NumOfSelector(FPDLongImageEncoder)
ENDENUM

//*****************************
/* LongImage HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLongImageCreateLongImage
 * @details Create FPD_LongImage.
 * @return   FPD_LongImage         Return FPD_LongImage.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_LongImage, FPDLongImageCreateLongImage, ())

/**
 * @brief FPDLongImageDeleteLongImage
 * @details Delete FPD_LongImage.
 * @param[in]  longImg The input FPD_LongImage.
 * @return   FPD_LongImage         Return FPD_LongImage.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FPDLongImageDeleteLongImage, (FPD_LongImage longImg))

/**
 * @brief FPDLongImageAddPage
 * @details Add a page to dest long image. Call the function multiple times to add multiple
	*			  pages to dest long image.
 * @param[in]  longImg The input FPD_LongImage.
 * @param[in]  pPage The page that you want to add.
 * @param[in]  pAnnotList The annot list of the page. If pAnnotList was nullptr,the class
	*                          would creat an inner annout list to render.
 * @param[in]  fDPI The display dpi of the page.
 * @return   FPD_LongImageError  Return FPD_LongImageError if success, or error type if any error is found.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_LongImageError, FPDLongImageAddPage, (FPD_LongImage longImg,  FPD_Page pPage,  FPD_AnnotList pAnnotList,  FS_FLOAT fDPI))

/**
 * @brief FPDLongImageAddPage2
 * @details Add a page to dest long image. Call the function multiple times to add multiple
	 *			  pages to dest long image.
 * @param[in]  longImg The input FPD_LongImage.
 * @param[in]  pDoc The document of the page that you want to add.
 * @param[in]  pPageDict The dictionary of the page that you want to add.
 * @param[in]  fDPI The display dpi of the page.
 * @return   FPD_LongImageError  Return FPD_LongImageError if success, or error type if any error is found.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_LongImageError, FPDLongImageAddPage2, (FPD_LongImage longImg,  FPD_Document pDoc,  FPD_Object pPageDict,  FS_FLOAT fDPI))

/**
 * @brief FPDLongImageOutput
 * @details Output the dest long image through a file stream.
 * @param[in]  longImg The input FPD_LongImage.
 * @param[in]  pStream The reuslt file stream.
 * @param[in]  colorMode The color mode of the dest long image.
 * @param[in]  imageFormat The image format of the dest long image.
 * @param[in]  pAttribute The attribute information of the dest long image.
 * @return   FPD_LongImageError  Return FPD_LongImageError if success, or error type if any error is found.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_LongImageError, FPDLongImageOutput, (FPD_LongImage longImg,  FS_FileStream pStream,  FPD_ColorMode colorMode,  FPD_ImageFormat imageFormat,  FS_DIBAttribute pAttribute))

/**
 * @brief FPDLongImageOutput2
 * @details Output the dest long image through a callback class.
 * @param[in]  longImg The input FPD_LongImage.
 * @param[in]  colorMode The color mode of the dest long image.
 * @param[in]  pImageEncoder The output callback class.The class would encode the dest long	image.
 * @return   FPD_LongImageError  Return FPD_LongImageError if success, or error type if any error is found.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_LongImageError, FPDLongImageOutput2, (FPD_LongImage longImg,  FPD_ColorMode colorMode,  FPD_LongImageEncoder pImageEncoder))

NumOfSelector(FPDLongImage)
ENDENUM

//----------_V17----------
//*****************************
/* MathGraphics HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDMathGraphicsGetGraphics
 * @details Get FPD_MathGraphics.
 * @return   FPD_MathGraphics
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_MathGraphics, FPDMathGraphicsGetGraphics, ())

/**
 * @brief FPDMathGraphicsDifference
 * @details Delete FPD_LongImageEncoder.
 * @param[in]  graphics The input FPD_MathGraphics.
 * @param[in]  path1 The input object of FPD_Path.
 * @param[in]  path2 The input object of FPD_Path.
 * @param[out]  differencePath Get the difference of the two objects.
 * @param[in]  path1_fillmode The input fill mode 1, default is FPDFILL_ALTERNATE.
 * @param[in]  path2_fillmode The input fill mode 2, default is FPDFILL_ALTERNATE.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDMathGraphicsDifference, (FPD_MathGraphics graphics,  FPD_Path path1,  FPD_Path path2,  FPD_Path* differencePath,  FS_INT32 path1_fillmode,  FS_INT32 path2_fillmode))

/**
 * @brief FPDMathGraphicsIntersection
 * @details Delete FPD_LongImageEncoder.
 * @param[in]  graphics The input FPD_MathGraphics.
 * @param[in]  path1 The input object of FPD_Path.
 * @param[in]  path2 The input object of FPD_Path.
 * @param[out]  differencePath Get the difference of the two objects.
 * @param[in]  path1_fillmode The input fill mode 1, default is FPDFILL_ALTERNATE.
 * @param[in]  path2_fillmode The input fill mode 2, default is FPDFILL_ALTERNATE.
 * @param[in]  bIsClip Whether is clip.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDMathGraphicsIntersection, (FPD_MathGraphics graphics,  FPD_Path path1,  FPD_Path path2,  FPD_Path* IntersectionPath,  FS_INT32 path1_fillmode,  FS_INT32 path2_fillmode,  FS_BOOLEAN bIsClip))

NumOfSelector(FPDMathGraphics)
ENDENUM

//----------_V18----------
//*****************************
/* MonoscaleBitmap HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_MonoscaleBitmap, FPDMonoscaleBitmapGet, (FS_Monoscale monoscale))

/**
 * @brief FPDMonoscaleBitmapNew
 * @details Create FPD_MonoscaleBitmap object.
 * @param[in]  pAllocator The input allocator.
 * @return   FPD_MonoscaleBitmap
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 */
INTERFACE(FPD_MonoscaleBitmap, FPDMonoscaleBitmapNew, (FS_LPVOID pAllocator))

/**
 * @brief FPDMonoscaleBitmapRelease
 * @details Release the FPD_MonoscaleBitmap object.
 * @param[in]  bitmap The input FPD_MonoscaleBitmap.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 */
INTERFACE(void, FPDMonoscaleBitmapRelease, (FPD_MonoscaleBitmap bitmap))

/**
 * @brief FPDMonoscaleBitmapCreate
 * @details Create bitmap by specified size.
 * @param[in]  monoscale The input FS_Monoscale.
 * @param[in]  width The input width of bitmap.
 * @param[in]  height The input height of bitmap.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
 */
INTERFACE(FS_BOOLEAN, FPDMonoscaleBitmapCreate, (FPD_MonoscaleBitmap bitmap,  FS_INT32 width,  FS_INT32 height))

NumOfSelector(FPDMonoscaleBitmap)
ENDENUM

//----------_V19----------
//----------_V20----------

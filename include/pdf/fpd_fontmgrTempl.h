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
/* FMFontMgr HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_FMFontMgr, FPDFMFontMgrGet, ())

/**
 * @brief FPDFMFontMgrGetCodePageFromCharset
 * @details Get code page from charset.
 * @param[in]  charset The input charset, like FPDFM_CHARSET_xx.
 * @return   FS_WORD
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_WORD, FPDFMFontMgrGetCodePageFromCharset, (FS_BYTE charset))

/**
 * @brief FPDFMFontMgrSetPlatformLanguage
 * @details Set the platform and language information.
 * @param[in]  fontMgr The input FPD_FMFontMgr object.
 * @param[in]  language The input language ID, like FPDXM_LANGUAGE_xx.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFMFontMgrSetPlatformLanguage, (FPD_FMFontMgr fontMgr,  FS_INT32 language))

/**
 * @brief FPDFMFontMgrLoadSystemFonts
 * @details Load the system fonts.
 * @param[in]  fontMgr The input FPD_FMFontMgr object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFMFontMgrLoadSystemFonts, (FPD_FMFontMgr fontMgr))

/**
 * @brief FPDFMFontMgrGetFontDescArray
 * @details Load the system fonts.
 * @param[in]  fontMgr The input FPD_FMFontMgr object.
 * @param[out]  fontDesArray Get the FPD_FMFontDescriptor object array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOL, FPDFMFontMgrGetFontDescArray, (FPD_FMFontMgr fontMgr,  FS_PtrArray* fontDesArray))

NumOfSelector(FPDFMFontMgr)
ENDENUM

//*****************************
/* FMFontDescriptor HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFMFontDescriptorCreate
 * @details Create FPD_FMFontDescriptor obj.
 * @return   FPD_FMFontDescriptor
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FMFontDescriptor, FPDFMFontDescriptorCreate, ())

/**
 * @brief FPDFMFontDescriptorDelete
 * @details Release FPD_FMFontDescriptor object.
 * @param[in]  descriptor The input FPD_FMFontDescriptor object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFMFontDescriptorDelete, (FPD_FMFontDescriptor descriptor))

/**
 * @brief FPDFMFontDescriptorGetFamiliyName
 * @details Get family name.
 * @param[in]  descriptor The input FPD_FMFontDescriptor object.
 * @param[out]  name Get family name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFMFontDescriptorGetFamiliyName, (FPD_FMFontDescriptor descriptor,  FS_WideString* name))

/**
 * @brief FPDFMFontDescriptorSetFamiliyName
 * @details Set family name.
 * @param[in]  descriptor The input FPD_FMFontDescriptor object.
 * @param[in]  name The input family name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFMFontDescriptorSetFamiliyName, (FPD_FMFontDescriptor descriptor,  FS_LPCWSTR name))

/**
 * @brief FPDFMFontDescriptorGetPostscriptName
 * @details Get Postscript name.
 * @param[in]  descriptor The input FPD_FMFontDescriptor object.
 * @param[out]  name Get Postscript name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFMFontDescriptorGetPostscriptName, (FPD_FMFontDescriptor descriptor,  FS_WideString* name))

/**
 * @brief FPDFMFontDescriptorSetPostscriptName
 * @details Set Postscript name.
 * @param[in]  descriptor The input FPD_FMFontDescriptor object.
 * @param[in]  name The input Postscript name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFMFontDescriptorSetPostscriptName, (FPD_FMFontDescriptor descriptor,  FS_LPCWSTR name))

/**
 * @brief FPDFMFontDescriptorGetFullName
 * @details Get local full font name.
 * @param[in]  descriptor The input FPD_FMFontDescriptor object.
 * @param[out]  name Get local full font name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFMFontDescriptorGetFullName, (FPD_FMFontDescriptor descriptor,  FS_WideString* name))

/**
 * @brief FPDFMFontDescriptorSetFullName
 * @details Set local full font name.
 * @param[in]  descriptor The input FPD_FMFontDescriptor object.
 * @param[in]  name Set local full font name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFMFontDescriptorSetFullName, (FPD_FMFontDescriptor descriptor,  FS_LPCWSTR name))

/**
 * @brief FPDFMFontDescriptorGetBsFamilyName
 * @details Get font family name, UTF-8 string.
 * @param[in]  descriptor The input FPD_FMFontDescriptor object.
 * @param[out]  name Get font family name, UTF-8 string.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFMFontDescriptorGetBsFamilyName, (FPD_FMFontDescriptor descriptor,  FS_ByteString* name))

/**
 * @brief FPDFMFontDescriptorSetBsFamilyName
 * @details Set font family name, UTF-8 string.
 * @param[in]  descriptor The input FPD_FMFontDescriptor object.
 * @param[in]  name Set font family name, UTF-8 string.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFMFontDescriptorSetBsFamilyName, (FPD_FMFontDescriptor descriptor,  FS_LPCSTR name))

/**
 * @brief FPDFMFontDescriptorGetCharset
 * @details Get the charset.
 * @param[in]  descriptor The input FPD_FMFontMgr object.
 * @return   FS_DWORD, like  FPDFM_CHARSET_.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 */
INTERFACE(FS_DWORD, FPDFMFontDescriptorGetCharset, (FPD_FMFontDescriptor descriptor))

NumOfSelector(FPDFMFontDescriptor)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

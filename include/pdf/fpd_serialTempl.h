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
//*****************************
/* ObjArchiveSaver HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDObjArchiveSaverNew
 * @details Creates a PDF object archive saver.
 * @return   The PDF object archive saver.
 * @note 
 */
INTERFACE(FPD_ObjArchiveSaver, FPDObjArchiveSaverNew, (void))

/**
 * @brief FPDObjArchiveSaverDestroy
 * @details Destroys the PDF object archive saver.
 * @param[in]  ar The input PDF object archive saver.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDObjArchiveSaverDestroy, (FPD_ObjArchiveSaver ar))

/**
 * @brief FPDObjArchiveSaverSaveObject
 * @details Overloads operator for serializing a PDF object.
 * @param[in]  ar Ref to output PDF object archive saver.
 * @param[in]  pObj The input PDF object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDObjArchiveSaverSaveObject, (FPD_ObjArchiveSaver ar,  const FPD_Object pObj))

/**
 * @brief FPDObjArchiveSaverGetLength
 * @details Gets the length of saved data.
 * @param[in]  ar The input PDF object archive saver.
 * @return   The length in bytes of the saved data.
 * @note 
 */
INTERFACE(FS_INTPTR, FPDObjArchiveSaverGetLength, (FPD_ObjArchiveSaver ar))

/**
 * @brief FPDObjArchiveSaverGetBuffer
 * @details Gets the constant byte pointer to the saved data.
 * @param[in]  ar The input PDF object archive saver.
 * @return   The constant byte pointer to the saved data.
 * @note 
 */
INTERFACE(FS_LPCBYTE, FPDObjArchiveSaverGetBuffer, (FPD_ObjArchiveSaver ar))

/**
 * @brief FPDObjArchiveSaverSaveByte
 * @details Overloads operator for serializing a single byte.
 * @param[in]  ar The input PDF object archive saver.
 * @param[in]  i The input byte.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveSaverSaveByte, (FPD_ObjArchiveSaver ar,  FS_BYTE i))

/**
 * @brief FPDObjArchiveSaverSaveInteger
 * @details Overloads operator for serializing a integer.
 * @param[in]  ar The input PDF object archive saver.
 * @param[in]  i The input integer.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveSaverSaveInteger, (FPD_ObjArchiveSaver ar,  FS_INT32 i))

/**
 * @brief FPDObjArchiveSaverSaveDWORD
 * @details Overloads operator for serializing a DWORD value.
 * @param[in]  ar The input PDF object archive saver.
 * @param[in]  i The input DWORD value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveSaverSaveDWORD, (FPD_ObjArchiveSaver ar,  FS_DWORD i))

/**
 * @brief FPDObjArchiveSaverSaveFloat
 * @details Overloads operator for serializing a floating-point.
 * @param[in]  ar The input PDF object archive saver.
 * @param[in]  i The input floating-point.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveSaverSaveFloat, (FPD_ObjArchiveSaver ar,  FS_FLOAT i))

/**
 * @brief FPDObjArchiveSaverSaveByteString
 * @details Overloads operator for serializing a byte string.
 * @param[in]  ar The input PDF object archive saver.
 * @param[in]  str The input byte string.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveSaverSaveByteString, (FPD_ObjArchiveSaver ar,  FS_ByteString str))

/**
 * @brief FPDObjArchiveSaverSaveWideString
 * @details Overloads operator for serializing a wide string.
 * @param[in]  ar The input PDF object archive saver.
 * @param[in]  wstr The input wide string.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveSaverSaveWideString, (FPD_ObjArchiveSaver ar,  FS_WideString wstr))

/**
 * @brief FPDObjArchiveSaverSaveWideStringII
 * @details Overloads operator for serializing a wide string.
 * @param[in]  ar The input PDF object archive saver.
 * @param[in]  wstr The input wide string.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveSaverSaveWideStringII, (FPD_ObjArchiveSaver ar,  FS_LPCWSTR wstr))

/**
 * @brief FPDObjArchiveSaverWrite
 * @details Overloads operator for serializing a memory block.
 * @param[in]  ar The input PDF object archive saver.
 * @param[in]  pData The pointer to a memory block.
 * @param[in]  dwSize The size in bytes of the memory block.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveSaverWrite, (FPD_ObjArchiveSaver ar,  void* pData,  FS_DWORD dwSize))

NumOfSelector(FPDObjArchiveSaver)
ENDENUM

//*****************************
/* ObjArchiveLoader HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDObjArchiveLoaderNew
 * @details Creates a PDF object archive loader.
 * @param[in]  pData The input memory block.
 * @param[in]  dwSize The size of the input memory block.
 * @return   The PDF object archive loader.
 * @note 
 */
INTERFACE(FPD_ObjArchiveLoader, FPDObjArchiveLoaderNew, (FS_LPCBYTE pData,  FS_DWORD dwSize))

/**
 * @brief FPDObjArchiveLoaderDestroy
 * @details Destroys the PDF object archive loader.
 * @param[in]  ar The input object archive loader.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDObjArchiveLoaderDestroy, (FPD_ObjArchiveLoader ar))

/**
 * @brief FPDObjArchiveLoaderLoadObject
 * @details Loads an object from archive.
 * @param[in]  ar Ref to the input object archive loader.
 * @param[out]  pObj It receives the loaded PDF object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDObjArchiveLoaderLoadObject, (FPD_ObjArchiveLoader ar,  FPD_Object* pObj))

/**
 * @brief FPDObjArchiveLoaderIsEOF
 * @details Returns whether de-serializing to the end of the loading buffer.
 * @param[in]  ar The input object archive loader.
 * @return   non-zero means de-serializing to the end, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDObjArchiveLoaderIsEOF, (FPD_ObjArchiveLoader ar))

/**
 * @brief FPDObjArchiveLoaderRead
 * @details De-serializes a memory block.
 * @param[in]  ar The input object archive loader.
 * @param[]  in,out] pBuf	A memory block pointer to receive the data.
 * @param[]  in] dwSize	The size in bytes of the memory block.
 * @return   non-zero means successful, otherwise failed.
 * @note 
 */
INTERFACE(FS_BOOL, FPDObjArchiveLoaderRead, (FPD_ObjArchiveLoader ar,  FS_LPVOID pBuf,  FS_DWORD dwSize))

/**
 * @brief FPDObjArchiveLoaderLoadByte
 * @details Loads a byte value from archive.
 * @param[in]  ar Ref to the input object archive loader.
 * @param[out]  i It receives the byte value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveLoaderLoadByte, (FPD_ObjArchiveLoader ar,  FS_BYTE* i))

/**
 * @brief FPDObjArchiveLoaderLoadInteger
 * @details Loads a integer value from archive.
 * @param[in]  ar Ref to the input object archive loader.
 * @param[out]  i It receives the integer value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveLoaderLoadInteger, (FPD_ObjArchiveLoader ar,  FS_INT32* i))

/**
 * @brief FPDObjArchiveLoaderLoadDWORD
 * @details Loads a DWORD value from archive.
 * @param[in]  ar Ref to the input object archive loader.
 * @param[out]  i It receives the DWORD value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveLoaderLoadDWORD, (FPD_ObjArchiveLoader ar,  FS_DWORD* i))

/**
 * @brief FPDObjArchiveLoaderLoadFloat
 * @details Loads a float value from archive.
 * @param[in]  ar Ref to the input object archive loader.
 * @param[out]  i It receives the float value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveLoaderLoadFloat, (FPD_ObjArchiveLoader ar,  FS_FLOAT* i))

/**
 * @brief FPDObjArchiveLoaderLoadByteString
 * @details Loads a byte string value from archive.
 * @param[in]  ar Ref to the input object archive loader.
 * @param[out]  pStr It receives the byte string value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveLoaderLoadByteString, (FPD_ObjArchiveLoader ar,  FS_ByteString* pStr))

/**
 * @brief FPDObjArchiveLoaderLoadWideString
 * @details Loads a wide string value from archive.
 * @param[in]  ar Ref to the input object archive loader.
 * @param[out]  pwStr It receives the wide string value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDObjArchiveLoaderLoadWideString, (FPD_ObjArchiveLoader ar,  FS_WideString* pwStr))

NumOfSelector(FPDObjArchiveLoader)
ENDENUM

//*****************************
/* PageArchiveSaver HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDPageArchiveSaverNew
 * @details Creates a PDF page archive saver.
 * @param[in]  pPageObjs The input page object list.
 * @return   The PDF page archive saver.
 * @note 
 */
INTERFACE(FPD_PageArchiveSaver, FPDPageArchiveSaverNew, (FPD_Page pPageObjs))

/**
 * @brief FPDPageArchiveSaverDestroy
 * @details Destroys the PDF page archive saver.
 * @param[in]  ar The input page archive saver.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDPageArchiveSaverDestroy, (FPD_PageArchiveSaver ar))

/**
 * @brief FPDPageArchiveSaverSavePageObject
 * @details Saves page object.
 * @param[in]  ar Ref to the output page archive saver.
 * @param[in]  pObj The input page object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveSaverSavePageObject, (FPD_PageArchiveSaver ar,  FPD_PageObject pObj))

/**
 * @brief FPDPageArchiveSaverSaveClipPath
 * @details Saves clipping path.
 * @param[in]  ar Ref to the output page archive saver.
 * @param[in]  clip_path The input clipping path.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveSaverSaveClipPath, (FPD_PageArchiveSaver ar,  FPD_ClipPath clip_path))

/**
 * @brief FPDPageArchiveSaverSaveGraphState
 * @details Saves graph state.
 * @param[in]  ar Ref to the output page archive saver.
 * @param[in]  graph_state The input graph state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveSaverSaveGraphState, (FPD_PageArchiveSaver ar,  FPD_GraphState graph_state))

/**
 * @brief FPDPageArchiveSaverSaveTextState
 * @details Saves text state.
 * @param[in]  ar Ref to the output page archive saver.
 * @param[in]  text_state The input text state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveSaverSaveTextState, (FPD_PageArchiveSaver ar,  FPD_TextState text_state))

/**
 * @brief FPDPageArchiveSaverSaveColorState
 * @details Saves color state.
 * @param[in]  ar Ref to the output page archive saver.
 * @param[in]  color_state The input color state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveSaverSaveColorState, (FPD_PageArchiveSaver ar,  FPD_ColorState color_state))

/**
 * @brief FPDPageArchiveSaverSaveGeneralState
 * @details Saves general state.
 * @param[in]  ar Ref to the output page archive saver.
 * @param[in]  general_state The input general state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveSaverSaveGeneralState, (FPD_PageArchiveSaver ar,  FPD_GeneralState general_state))

/**
 * @brief FPDPageArchiveSaverNew2
 * @details Creates a PDF page archive saver.
 * @param[in]  pPageObjs The input page object list.
 * @return   The PDF page archive saver.
 * @note 
 */
INTERFACE(FPD_PageArchiveSaver, FPDPageArchiveSaverNew2, (FPD_GraphicsObjects pPageObjs))

/**
 * @brief FPDPageArchiveSaverSetStream
 * @details Set the attached stream.
 * @param[in]  ar Ref to the output page archive saver.
 * @param[in]  pStream The stream to the saved data.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveSaverSetStream, (FPD_PageArchiveSaver ar,  FS_FileStream pStream))

NumOfSelector(FPDPageArchiveSaver)
ENDENUM

//*****************************
/* PageArchiveLoader HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDPageArchiveLoaderNew
 * @details Constructs a loading archive.
 * @param[in]  pPageObjs The current page/form.
 * @param[in]  pData The input memory buffer.
 * @param[in]  dwSize The size of the input buffer.
 * @return   The PDF page archive loader.
 * @note 
 */
INTERFACE(FPD_PageArchiveLoader, FPDPageArchiveLoaderNew, (FPD_Page pPageObjs,  FS_LPCBYTE pData,  FS_DWORD dwSize))

/**
 * @brief FPDPageArchiveLoaderDestroy
 * @details Destroys the PDF page archive loader.
 * @param[in]  ar The input page archive loader.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDPageArchiveLoaderDestroy, (FPD_PageArchiveLoader ar))

/**
 * @brief FPDPageArchiveLoaderLoadObject
 * @details Loads an object from archive.
 * @param[in]  ar Ref to the input page archive loader.
 * @param[out]  pObj It receives the loaded PDF object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveLoaderLoadObject, (FPD_PageArchiveLoader ar,  FPD_PageObject* pObj))

/**
 * @brief FPDPageArchiveLoaderLoadClipPath
 * @details Load or restore the clipping path.
 * @param[in]  ar Ref to the input page archive loader.
 * @param[out]  clip_path It receives the clipping path.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveLoaderLoadClipPath, (FPD_PageArchiveLoader ar,  FPD_ClipPath* clip_path))

/**
 * @brief FPDPageArchiveLoaderLoadGraphState
 * @details Load or restore the graph state.
 * @param[in]  ar Ref to the input page archive loader.
 * @param[out]  graph_state It receives the graph state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveLoaderLoadGraphState, (FPD_PageArchiveLoader ar,  FPD_GraphState* graph_state))

/**
 * @brief FPDPageArchiveLoaderLoadTextState
 * @details Load or restore the text state.
 * @param[in]  ar Ref to the input page archive loader.
 * @param[out]  text_state It receives the text state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveLoaderLoadTextState, (FPD_PageArchiveLoader ar,  FPD_TextState* text_state))

/**
 * @brief FPDPageArchiveLoaderLoadColorState
 * @details Load or restore the color state.
 * @param[in]  ar Ref to the input page archive loader.
 * @param[out]  color_state It receives the color state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveLoaderLoadColorState, (FPD_PageArchiveLoader ar,  FPD_ColorState* color_state))

/**
 * @brief FPDPageArchiveLoaderLoadGeneralState
 * @details Load or restore the general state.
 * @param[in]  ar Ref to the input page archive loader.
 * @param[out]  general_state It receives the general state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageArchiveLoaderLoadGeneralState, (FPD_PageArchiveLoader ar,  FPD_GeneralState* general_state))

/**
 * @brief FPDPageArchiveLoaderNew2
 * @details Constructs a loading archive.
 * @param[in]  pPageObjs The current page/form.
 * @param[in]  pData The input memory buffer.
 * @param[in]  dwSize The size of the input buffer.
 * @return   The PDF page archive loader.
 * @note 
 */
INTERFACE(FPD_PageArchiveLoader, FPDPageArchiveLoaderNew2, (FPD_GraphicsObjects pPageObjs,  FS_LPCBYTE pData,  FS_DWORD dwSize))

NumOfSelector(FPDPageArchiveLoader)
ENDENUM

//*****************************
/* Creator HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDCreatorNew
 * @details creates PDF file from a document object
 * @param[in]  pDoc The PDF Document Object.
 * @return   The PDF Creater.
 * @note 
 */
INTERFACE(FPD_Creator, FPDCreatorNew, (FPD_Document pDoc))

/**
 * @brief FPDCreatorDestroy
 * @details Destroys the PDF file Creator.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDCreatorDestroy, (FPD_Creator pFPDCreator))

/**
 * @brief FPDCreatorCompress
 * @details Sets data compression. By default, FPD_Creator use Flate compression for all data streams 
	*            in release mode, but not in debug mode.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  bEnable Whether to do data compressing.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDCreatorCompress, (FPD_Creator pFPDCreator,  FS_BOOL bEnable))

/**
 * @brief FPDCreatorSetStandardSecurity
 * @details Sets security settings using standard security handler only.
	*            Can't be used with incremental update.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  permissions The user permissions.
 * @param[in]  user_pass The user password.
 * @param[in]  user_pass_len The length of user password.
 * @param[in]  owner_pass The owner password.
 * @param[in]  owner_pass_len The length of owner password.
 * @param[in]  cipher The cipher type, RC4 or AES.
 * @param[in]  key_bytes The length of the document key.
 * @param[in]  bEncryptMetadata Whether to encrypt the metadata.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDCreatorSetStandardSecurity, (FPD_Creator pFPDCreator,  FS_DWORD permissions,  FS_LPCBYTE user_pass,  FS_INT32 user_pass_len,  FS_LPCBYTE owner_pass,  FS_INT32 owner_pass_len,  FS_INT32 cipher,  FS_INT32 key_bytes,  FS_BOOL bEncryptMetadata))

/**
 * @brief FPDCreatorModifyR5Security
 * @details Modifies security permissions for Revision 5 handler (AES 256)
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  bPermissions Whether permission and EncryptMetadata changed.
 * @param[in]  permissions New permissions value.
 * @param[in]  bEncryptMetadata New EncryptMetadata value.
 * @param[in]  bUserPassword Whether user password changed (owner password required).
 * @param[in]  user_pass The user password pointer.
 * @param[in]  user_size The length of the user password.
 * @param[in]  bOwnerPassword Whether owner password changed.
 * @param[in]  owner_pass The owner password pointer.
 * @param[in]  owner_size The length of the owner password.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDCreatorModifyR5Security, (FPD_Creator pFPDCreator,  FS_BOOL bPermissions,  FS_DWORD permissions,  FS_BOOL bEncryptMetadata,  FS_BOOL bUserPassword,  FS_LPCBYTE user_pass,  FS_DWORD user_size,  FS_BOOL bOwnerPassword,  FS_LPCBYTE owner_pass,  FS_DWORD owner_size))

/**
 * @brief FPDCreatorSetCustomSecurity
 * @details Sets security using custom security handler and custom encryption.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  pEncryptDict The Encrypt dictionary.
 * @param[in]  pCryptoHandler The crypto handler.
 * @param[in]  bEncryptMetadata Whether to encrypt the metadata.
 * @return   The data need to be released. You can invoke FPDCreatorReleaseCustomSecurityData.
 * @note Application should provide a full encryption dictionary (application can destroy it after this call),
	*            and a custom encryption handler.
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void*, FPDCreatorSetCustomSecurity, (FPD_Creator pFPDCreator,  FPD_Object pEncryptDict,  FPD_CryptoHandler pCryptoHandler,  FS_BOOL bEncryptMetadata))

/**
 * @brief FPDCreatorReleaseCustomSecurityData
 * @details Release the custom security data generated by FPDCreatorSetCustomSecurity.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  cusSecurityData The custom security data to be released.
 * @return   The data need to be released.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDCreatorReleaseCustomSecurityData, (FPD_Creator pFPDCreator,  void* cusSecurityData))

/**
 * @brief FPDCreatorRemoveSecurity
 * @details Removes security settings. The output file will not be encrypted.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @return   void.
 * @note Can't be used with incremental update.
 */
INTERFACE(void, FPDCreatorRemoveSecurity, (FPD_Creator pFPDCreator))

/**
 * @brief FPDCreatorCreate
 * @details Write the whole document into a new file (using Unicode file name). Unicode version.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  filename The output filename.
 * @param[in]  flags The creating flags.
 * @return   Non-zero means success, otherwise failed.
 * @note 
 */
INTERFACE(FS_BOOL, FPDCreatorCreate, (FPD_Creator pFPDCreator,  FS_LPCWSTR filename,  FS_DWORD flags))

/**
 * @brief FPDCreatorCreate2
 * @details Write the whole document into a new file (using local file name). Local version.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  filename The output filename.
 * @param[in]  flags The creating flags.
 * @return   Non-zero means success, otherwise failed.
 * @note 
 */
INTERFACE(FS_BOOL, FPDCreatorCreate2, (FPD_Creator pFPDCreator,  FS_LPCSTR filename,  FS_DWORD flags))

/**
 * @brief FPDCreatorCreate3
 * @details Write the whole document to a custom file access.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[out]  pFile The output file access.
 * @param[in]  flags The creating flags.
 * @return   Non-zero means success, otherwise failed.
 * @note 
 */
INTERFACE(FS_BOOL, FPDCreatorCreate3, (FPD_Creator pFPDCreator,  FS_StreamWriteHandler* pFile,  FS_DWORD flags))

/**
 * @brief FPDCreatorGetObjectOffset
 * @details Gets object offset.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  objnum The object number.
 * @return   the object offset.
 * @note If the object with specific number doesn't exist, the returned value will be zero.
	*            If incremental update is used, offsets and sizes are only valid for modified indirect objects.
 */
INTERFACE(FS_DWORD, FPDCreatorGetObjectOffset, (FPD_Creator pFPDCreator,  FS_DWORD objnum))

/**
 * @brief FPDCreatorGetObjectSize
 * @details Gets object size.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  objnum The object number.
 * @return   the object size.
 * @note If the object with specific number doesn't exist, the returned value will be zero.
	*            If incremental update is used, offsets and sizes are only valid for modified indirect objects.
 */
INTERFACE(FS_DWORD, FPDCreatorGetObjectSize, (FPD_Creator pFPDCreator,  FS_DWORD objnum))

/**
 * @brief FPDCreatorSetProgressiveEncryptHandler
 * @details Sets the progressive encrypt handler so that the creator can encrypt the content progressively.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  callbacks The callback set for progressive encrypt handler.
 * @return   The progressive encrypt handler.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FPDCreatorReleaseProgressiveEncryptHandler
 */
INTERFACE(FPD_ProgressiveEncryptHandler, FPDCreatorSetProgressiveEncryptHandler, (FPD_Creator pFPDCreator,  FPD_ProgressiveEncryptCallbacks callbacks))

/**
 * @brief FPDCreatorReleaseProgressiveEncryptHandler
 * @details Releases the progressive encrypt handler.
 * @param[in]  handler The input progressive encrypt handler to be released.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 */
INTERFACE(void, FPDCreatorReleaseProgressiveEncryptHandler, (FPD_ProgressiveEncryptHandler handler))

/**
 * @brief FPDCreatorSetOption
 * @details Sets the creator option so that the creator can decode or encode the content progressively.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  callbacks The callback set for creator option.
 * @return   The creator option.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FPDCreatorReleaseOption
 */
INTERFACE(FPD_CreatorOption, FPDCreatorSetOption, (FPD_Creator pFPDCreator,  FPD_CreatorOptionCallbacks callbacks))

/**
 * @brief FPDCreatorReleaseOption
 * @details Releases the creator option.
 * @param[in]  handler The input creator option.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDCreatorReleaseOption, (FPD_CreatorOption creatorOption))

/**
 * @brief FPDCreatorDeprecatedSetDRMSecurity
 * @details Sets security using custom security handler and custom encryption.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  pEncryptDict The Encrypt dictionary.
 * @param[in]  pCryptoHandler The crypto handler.
 * @param[in]  bEncryptMetadata Whether to encrypt the metadata.
 * @return   The data need to be released. You can invoke FPDCreatorReleaseDRMSecurityData.
 * @note Application should provide a full encryption dictionary (application can destroy it after this call),
	*            and a custom encryption handler.
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.5
 */
INTERFACE(void*, FPDCreatorDeprecatedSetDRMSecurity, (FPD_Creator pFPDCreator,  FPD_Object pEncryptDict,  FPD_CryptoHandler pCryptoHandler,  FS_BOOL bEncryptMetadata))

/**
 * @brief FPDCreatorDeprecatedReleaseDRMSecurityData
 * @details Release the custom security data generated by FPDCreatorSetDRMSecurity.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  cusSecurityData The custom security data to be released.
 * @return   The data need to be released.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.5
 */
INTERFACE(void, FPDCreatorDeprecatedReleaseDRMSecurityData, (FPD_Creator pFPDCreator,  void* cusSecurityData))

/**
 * @brief FPDCreatorDeprecatedSetDRMProgressiveEncryptHandler
 * @details Sets the progressive encrypt handler so that the creator can encrypt the content progressively.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  callbacks The callback set for progressive encrypt handler.
 * @return   The progressive encrypt handler.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.5
 * @see FPDCreatorDRMReleaseProgressiveEncryptHandler
 */
INTERFACE(FPD_ProgressiveEncryptHandler, FPDCreatorDeprecatedSetDRMProgressiveEncryptHandler, (FPD_Creator pFPDCreator,  FPD_ProgressiveEncryptCallbacks callbacks))

/**
 * @brief FPDCreatorDeprecatedReleaseDRMProgressiveEncryptHandler
 * @details Releases the progressive encrypt handler.
 * @param[in]  handler The input progressive encrypt handler to be released.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.5
 */
INTERFACE(void, FPDCreatorDeprecatedReleaseDRMProgressiveEncryptHandler, (FPD_ProgressiveEncryptHandler handler))

/**
 * @brief FPDCreatorSetProgressiveEncryptHandler2
 * @details Sets the progressive encrypt handler so that the creator can encrypt the content progressively.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  callbacks The callback set for progressive encrypt handler.
 * @param[in]  releaseClientData The release callback,that need to be release in plugin.
 * @param[in]  bNeedCrypto Whether set crypto handler by FPDCreatorSetCustomSecurity before.
 * @return   The progressive encrypt handler.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FPDCreatorReleaseProgressiveEncryptHandler
 */
INTERFACE(FPD_ProgressiveEncryptHandler, FPDCreatorSetProgressiveEncryptHandler2, (FPD_Creator pFPDCreator,  FPD_ProgressiveEncryptCallbacks callbacks,  FPD_ReleaseProgressiveEncryptClientData releaseClientData,  FS_BOOL bNeedCrypto))

/**
 * @brief FPDCreatorSetCustomSecurity2
 * @details Sets security using custom security handler and custom encryption.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  pEncryptDict The Encrypt dictionary.
 * @param[in]  pCryptoHandler The crypto handler.
 * @param[in]  bEncryptMetadata Whether to encrypt the metadata.
 * @return   
 * @note Application should provide a full encryption dictionary (application can destroy it after this call),
	*            and a custom encryption handler.
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDCreatorSetCustomSecurity2, (FPD_Creator pFPDCreator,  FPD_Object pEncryptDict,  FPD_StandardCryptoHandler cryptoHandler,  FS_BOOL bEncryptMetadata))

/**
 * @brief FPDCreatorSetCustomSecurity3
 * @details Sets security using custom security handler and custom encryption.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  pEncryptDict The Encrypt dictionary.
 * @param[in]  pCryptoHandler The crypto handler.
 * @param[in]  bEncryptMetadata Whether to encrypt the metadata.
 * @return   
 * @note Application should provide a full encryption dictionary (application can destroy it after this call),
	*            and a custom encryption handler.
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDCreatorSetCustomSecurity3, (FPD_Creator pFPDCreator,  FPD_Object pEncryptDict,  FPD_FipsStandardCryptoHandler cryptoHandler,  FS_BOOL bEncryptMetadata))

/**
 * @brief FPDCreatorAttachUncompressObjects
 * @details Attach uncompress objects. The objects will not be compressed to the object stream.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[]  in] pObjNums	        Ignored object numbers' pointer.
 * @param[]  in] dwSize	        Count of input object numbers.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FPDCreatorAttachUncompressObjects, (FPD_Creator pFPDCreator,  const FS_DWORD* pObjNums,  FS_DWORD dwSize))

/**
 * @brief FPDCreatorGetStandardLinearizationObj
 * @details Get CPDF_StandardLinearization obj, CPDF_StandardLinearization inheritance CPDF_Creator.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @return   FPD_StandardLinearization.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FPD_StandardLinearization, FPDCreatorGetStandardLinearizationObj, (FPD_Creator pFPDCreator))

/**
 * @brief FPDCreatorCreate4
 * @details Write the whole document to a custom file access.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[out]  pFile The output file access.
 * @param[in]  flags The creating flags.
 * @return   Non-zero means success, otherwise failed.
 * @note 
 */
INTERFACE(FS_BOOL, FPDCreatorCreate4, (FPD_Creator pFPDCreator,  FS_FileWriteHandler pFile,  FS_DWORD flags))

/**
 * @brief FPDCreatorSetStandardSecurity2
 * @details Sets security settings using standard security handler only.
	*            Can't be used with incremental update.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  permissions The user permissions.
 * @param[in]  user_pass The user password.
 * @param[in]  user_pass_len The length of user password.
 * @param[in]  owner_pass The owner password.
 * @param[in]  owner_pass_len The length of owner password.
 * @param[in]  bEncryptMetadata Whether to encrypt the metadata.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDCreatorSetStandardSecurity2, (FPD_Creator pFPDCreator,  FS_DWORD permissions,  FS_LPCWSTR user_pass,  FS_INT32 user_pass_len,  FS_LPCWSTR owner_pass,  FS_INT32 owner_pass_len,  FS_BOOLEAN bEncryptMetadata))

/**
 * @brief FPDCreatorModifyR5Security2
 * @details Modifies security permissions for Revision 5 handler (AES 256)
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  bPermissions Whether permission and EncryptMetadata changed.
 * @param[in]  permissions New permissions value.
 * @param[in]  bEncryptMetadata New EncryptMetadata value.
 * @param[in]  bUserPassword Whether user password changed (owner password required).
 * @param[in]  user_pass The user password pointer.
 * @param[in]  user_size The length of the user password.
 * @param[in]  bOwnerPassword Whether owner password changed.
 * @param[in]  owner_pass The owner password pointer.
 * @param[in]  owner_size The length of the owner password.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDCreatorModifyR5Security2, (FPD_Creator pFPDCreator,  FS_BOOL bPermissions,  FS_DWORD permissions,  FS_BOOL bEncryptMetadata,  FS_BOOL bUserPassword,  FS_LPCWSTR user_pass,  FS_DWORD user_size,  FS_BOOL bOwnerPassword,  FS_LPCWSTR owner_pass,  FS_DWORD owner_size))

/**
 * @brief FPDCreatorAttachIgnoredObjects
 * @details Attach ignored objects. The objects will not be written into the creating file.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  pObjNums Ignored object numbers' pointer.
 * @param[in]  dwSize Count of input object numbers.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDCreatorAttachIgnoredObjects, (FPD_Creator pFPDCreator,  const FS_DWORD* pObjNums,  FS_DWORD dwSize))

/**
 * @brief FPDCreatorSetAESV4GCMSecurity
 * @details Set security settings using standard security handler for AES-GCM with unicode password.
	* And the Revision must be 7 and later, the PDF file version should be 2.0.
	* Can't be used with incremental update.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @param[in]  permissions The user permissions.
 * @param[in]  user_pass The user password.
 * @param[in]  user_pass_len The length of user password.
 * @param[in]  owner_pass The owner password.
 * @param[in]  owner_pass_len The length of owner password.
 * @param[in]  bEncryptMetadata Whether to encrypt the metadata.
 * @return   void.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDCreatorSetAESV4GCMSecurity, (FPD_Creator pFPDCreator,  FS_DWORD permissions,  FS_LPCWSTR user_pass,  FS_INT32 user_pass_len,  FS_LPCWSTR owner_pass,  FS_INT32 owner_pass_len,  FS_BOOLEAN bEncryptMetadata))

NumOfSelector(FPDCreator)
ENDENUM

//----------_V2----------
//*****************************
/* WrapperCreator HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDWrapperCreatorNew
 * @details Creates an instance of FPD_WrapperCreator.
 * @param[in]  pWrapperDoc A document object which defines wrapper version, caller maintains its life-time.
 * @param[in]  dwWrapperOffset Offset in bytes from the beginning of PDF file, for wrapper version.
 * @return   An instance of interface FPD_WrapperCreator, NULL pointer if error happens.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FPD_WrapperCreator, FPDWrapperCreatorNew, (FPD_Document pWrapperDoc,  FS_DWORD dwWrapperOffset))

/**
 * @brief FPDWrapperCreatorDestroy
 * @details Destroy the wrapper creator.
 * @param[in]  wrapperCreator The input wrapper creator object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDWrapperCreatorDestroy, (FPD_WrapperCreator wrapperCreator))

/**
 * @brief FPDWrapperCreatorSetWrapperData
 * @details Set wrapper data.
 * @param[in]  wrapperCreator The input wrapper creator object.
 * @param[in]  szType Wrapper type name.
 * @param[in]  iVersion Wrapper version.
 * @param[in]  szApplication Application identity which indicates how to process the current wrapper file.
 * @param[in]  szURI An URI site to retrieve more helpful information if necessary.
 * @param[in]  szDescription Description text for application.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDWrapperCreatorSetWrapperData, (FPD_WrapperCreator wrapperCreator,  FS_LPSTR szType,  FS_INT32 iVersion,  FS_LPSTR szApplication,  FS_LPSTR szURI,  FS_LPSTR szDescription))

/**
 * @brief FPDWrapperCreatorCreate
 * @details Write the wrapper version to a custom file access.
 * @param[in]  wrapperCreator The input wrapper creator object.
 * @param[in]  pFile The output file access.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDWrapperCreatorCreate, (FPD_WrapperCreator wrapperCreator,  FS_StreamWriteHandler* pFile))

/**
 * @brief FPDWrapperCreatorSetStandardSecurity
 * @details Set security settings using standard security handler only. Can't be used with incremental update.
 * @param[in]  wrapperCreator The input wrapper creator object.
 * @param[in]  permissions The user permissions.
 * @param[in]  owner_pass The owner password.
 * @param[in]  owner_pass_len The length of owner password.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDWrapperCreatorSetStandardSecurity, (FPD_WrapperCreator wrapperCreator,  FS_DWORD permissions,  FS_LPCBYTE owner_pass,  FS_INT32 owner_pass_len))

NumOfSelector(FPDWrapperCreator)
ENDENUM

//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
//*****************************
/* UnencryptedWrapperCreator HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDUnencryptedWrapperCreatorNew
 * @details Creates an instance of FPD_Wrapper20Creator.
 * @param[in]  pWrapperDoc A document object which defines wrapper version, caller maintains its life-time.
 * @return   An instance of interface FPD_Wrapper20Creator, NULL pointer if error happens.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FPD_UnencryptedWrapperCreator, FPDUnencryptedWrapperCreatorNew, (FPD_Document pWrapperDoc))

/**
 * @brief FPDUnencryptedWrapperCreatorDestroy
 * @details Destroy the wrapper creator.
 * @param[in]  wrapperCreator The input wrapper creator object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(void, FPDUnencryptedWrapperCreatorDestroy, (FPD_UnencryptedWrapperCreator wrapperCreator))

/**
 * @brief FPDUnencryptedWrapperCreatorSetPayloadInfo
 * @details Set data of the embedded encrypted payload document for the wrapper doc.
 * @param[in]  wrapperCreator The input wrapper creator object.
 * @param[in]  wsSubType The name of the cryptographic filter used to encrypt the encrypted payload document.
 * @param[in]  wsFileName The file name for encrypted payload document which shall include the name of the
	*							cryptographic filter needed to decrypt the document.
 * @param[in]  wsDescription Description text for the embedded encrypted payload document.
 * @param[in]  fVersion The version number of the cryptographic filter used to encrypt the encrypted payload.
 * @return   void.
 * @note The Param "bsFileName" must not contain or be derived from the encrypted payload’s actual file name. 
	*			  This is to avoid potential disclosure of sensitive information in the original filename.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(void, FPDUnencryptedWrapperCreatorSetPayloadInfo, (FPD_UnencryptedWrapperCreator wrapperCreator,  FS_LPWSTR wsSubType,  FS_LPWSTR wsFileName,  FS_LPWSTR wsDescription,  FS_FLOAT fVersion))

/**
 * @brief FPDUnencryptedWrapperCreatorSetPayLoad
 * @details Set the embedded encrypted payload document for the wrapper doc.
 * @param[in]  wrapperCreator The input wrapper creator object.
	* param[in]: pPayload			The embedded encrypted payload document.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(void, FPDUnencryptedWrapperCreatorSetPayLoad, (FPD_UnencryptedWrapperCreator wrapperCreator,  FS_FileReadHandler pPayload))

/**
 * @brief FPDUnencryptedWrapperCreatorCreate
 * @details Write the wrapper version to a custom file access.
 * @param[in]  wrapperCreator The input wrapper creator object.
 * @param[out]  pFile The output file access.
 * @param[in]  flags The creating flags.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FS_BOOL, FPDUnencryptedWrapperCreatorCreate, (FPD_UnencryptedWrapperCreator wrapperCreator,  FS_FileWriteHandler *pFile,  FS_DWORD flags))

/**
 * @brief FPDUnencryptedWrapperCreatorContinue
 * @details Continue to write wrapper document data under progressive mode.
 * @param[in]  wrapperCreator The input wrapper creator object.
 * @param[in]  pPause Pause object, optional.
 * @return   Negative value if failure, 0 if finishes, and positive value if need to be continued.
 * @note Only valid if pass FPDFCREATE_PROGRESSIVE flag in calling Create method.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FS_INT32, FPDUnencryptedWrapperCreatorContinue, (FPD_UnencryptedWrapperCreator wrapperCreator,  FS_PauseHandler pPause))

/**
 * @brief FPDUnencryptedWrapperCreatorSetStandardSecurity
 * @details Set security settings using standard security handler only.
 * @param[in]  wrapperCreator The input wrapper creator object.
 * @param[in]  permissions The user permissions.
 * @param[in]  owner_pass The owner password.
 * @param[in]  owner_pass_len The length of owner password.
 * @return   void.
 * @note Can't be used with incremental update.
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(void, FPDUnencryptedWrapperCreatorSetStandardSecurity, (FPD_UnencryptedWrapperCreator wrapperCreator,  FS_DWORD permissions,  FS_LPCBYTE owner_pass,  FS_INT32 owner_pass_len))

NumOfSelector(FPDUnencryptedWrapperCreator)
ENDENUM

//----------_V11----------
//----------_V12----------
//----------_V13----------
//----------_V14----------
//*****************************
/* StandardLinearization HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDStandardLinearizationGetCFPDLinearizedObj
 * @details Support CPDF_Creator convert to CPDF_StandardLinearization.
 * @param[in]  pFPDCreator The input PDF file Creator.
 * @return   FPD_StandardLinearization.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FPD_StandardLinearization, FPDStandardLinearizationGetCFPDLinearizedObj, (FPD_Creator pFPDCreator))

/**
 * @brief FPDStandardLinearizationGetLinearizedObjNum
 * @details Get the new object number in the linearized PDF.
 * @param[in]  linearzation The input StandardLinearization obj.
 * @param[in]  objnum The old object number in the original PDF.
 * @return   FS_DWORD.   The new object number in the linearized PDF.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_DWORD, FPDStandardLinearizationGetLinearizedObjNum, (FPD_StandardLinearization linearzation,  FS_DWORD objnum))

/**
 * @brief FPDStandardLinearizationLinearize
 * @details Analyze and linearize the PDF document.
 * @param[in]  linearzation The input StandardLinearization obj.
 * @param[in]  bRegenMetadata Whether to regenerate the XMP metadata with padding bytes.
 * @return   FS_BOOLEAN.   If this method returns false, means error occurs. true for successful linearization.
 * @note If want r save as a linearized PDF, this function must be called before FPDCreatorCreate function.
	 *			And all the operations which will modify the document must be called firstly, such as
	 *			FPDCreatorAttachIgnoredObjects and FPDCreatorAttachUncompressObjects and so on.
	 *			Not call it will save as a no linearized PDF.When return false, application can still
	 *			call::Create but it will save as a no linearized PDF.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
 */
INTERFACE(FS_BOOLEAN, FPDStandardLinearizationLinearize, (FPD_StandardLinearization linearzation,  FS_BOOLEAN bRegenMetadata))

/**
 * @brief FPDStandardLinearizationNew
 * @details Construct with a Linearized PDF document.
 * @param[in]  pDocument The input FPD_Document obj.
 * @return   FPD_StandardLinearization    Construct FPD_StandardLinearization object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1
 */
INTERFACE(FPD_StandardLinearization, FPDStandardLinearizationNew, (FPD_Document pDocument))

/**
 * @brief FPDStandardLinearizationDelete
 * @details Delete FPD_StandardLinearization obj.
 * @param[in]  linearzation The input FPD_StandardLinearization obj.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1
 */
INTERFACE(void, FPDStandardLinearizationDelete, (FPD_StandardLinearization linearzation))

/**
 * @brief FPDStandardLinearizationCastToCreator
 * @details Cast to parent of FPD_Creator object.
 * @param[in]  linearzation The input FPD_StandardLinearization obj.
 * @return   FPD_Creator
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1
 */
INTERFACE(FPD_Creator, FPDStandardLinearizationCastToCreator, (FPD_StandardLinearization linearzation))

/**
 * @brief FPDStandardLinearizationCreate
 * @details Write the whole document to a custom file access.
 * @param[in]  linearzation The input FPD_StandardLinearization obj.
 * @param[in]  pFile The output file access.
 * @param[in]  dwFlags flags indicate how to linearize PDF document, refer to FPD_SAVE_XXXX macros.
 * @return   FS_BOOLEAN   false if failure, otherwise finishes successfully.
 * @note If want to save as a linearized PDF, the Linearize function must be called firstly.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1
 */
INTERFACE(FS_BOOLEAN, FPDStandardLinearizationCreate, (FPD_StandardLinearization linearzation,  FS_FileWriteHandler pFile,  FS_DWORD dwFlags))

NumOfSelector(FPDStandardLinearization)
ENDENUM

//----------_V15----------
//----------_V16----------
//----------_V17----------
//*****************************
/* CustomCryptoHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDCustomCryptoHandlerCreate
 * @details Create the FPD_CustomCryptoHandler object.
 * @param[in]  pCallbacks The input FPD_CryptoHandler callback.
 * @return   FPD_CustomCryptoHandler.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_CustomCryptoHandler, FPDCustomCryptoHandlerCreate, (FPD_CryptoHandler pCallbacks))

/**
 * @brief FPDCustomCryptoHandlerDestroy
 * @details Destroy the FPD_CustomCryptoHandler object.
 * @param[in]  cryptoHandler The input FPD_CustomCryptoHandler.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDCustomCryptoHandlerDestroy, (FPD_CustomCryptoHandler cryptoHandler))

NumOfSelector(FPDCustomCryptoHandler)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

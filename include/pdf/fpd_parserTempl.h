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
/* Parser HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDParserNew
 * @details Creates a new PDF file parser. </Brief>The PDF file parser will parse entire PDF file and then build a <a>FPD_Document</a> object,
	* use <a>FPDParserGetDocument</a>() to get a <a>FPD_Document</a> object.
 * @param[in]  void 
 * @return   The newly created parser.
 * @note 
 */
INTERFACE(FPD_Parser, FPDParserNew, (void))

/**
 * @brief FPDParserDestroy
 * @details Destroy a PDF file parser.
 * @param[in]  parser The parser to be free.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserDestroy, (FPD_Parser parser))

/**
 * @brief FPDParserStartParse
 * @details Starts parsing from a file, ANSIC version. Use <a>FPDParserCloseParse</a>() to end the parsing.
 * @param[in]  parser The PDF file parser.
 * @param[in]  filename The file full path name that will be parsed.
 * @param[in]  bReParse A flag indicates whether you will do reparsing.
 * @return   The status of PDF parsing. See <a>FPDParseErrCodes</a>.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserStartParse, (FPD_Parser parser,  FS_LPCSTR filename,  FS_BOOL bReParse))

/**
 * @brief FPDParserStartParseW
 * @details Starts parsing from a file, Unicode version. Use <a>FPDParserCloseParse</a>() to end the parsing.
 * @param[in]  parser The PDF file parser.
 * @param[in]  filename The file full path name that will be parsed.
 * @param[in]  bReParse A flag indicates whether you will do reparsing.
 * @return   The status of PDF parsing. See <a>FPDParseErrCodes</a>
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserStartParseW, (FPD_Parser parser,  FS_LPCWSTR filename,  FS_BOOL bReParse))

/**
 * @brief FPDParserStartParseFormMem
 * @details Starts parsing from memory block. Use <a>FPDParserCloseParse</a>() to end the parsing.
 * @param[in]  parser The PDF file parser.
 * @param[in]  pData The input memory block that contains the PDF file data.
 * @param[in]  nSize The size in bytes of the memory block.
 * @param[in]  bReParse A flag indicates whether you will do reparsing.
 * @return   The status of PDF parsing. See <a>FPDParseErrCodes</a>
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserStartParseFormMem, (FPD_Parser parser,  FS_LPCBYTE pData,  FS_DWORD nSize,  FS_BOOL bReParse))

/**
 * @brief FPDParserStartParseCustomFile
 * @details Starts parsing a custom file. Use <a>FPDParserCloseParse</a>() to end the parsing.
 * @param[in]  parser The PDF file parser.
 * @param[in]  file The stream access interface. Use <a>FSFileReadHandlerNew</a>() to create a file access interface.
 * @param[in]  bReParse A flag indicates whether you will do reparsing.
 * @param[in]  bOwnFileRead A flag indicated whether <a>FPD_Parser</a> takes ownership of the file read structure (by calling <a>FSFileReadHandlerDestroy</a>() when parser cleans up).
 * @return   The status of PDF parsing. See <a>FPDParseErrCodes</a>
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserStartParseCustomFile, (FPD_Parser parser,  FS_FileReadHandler file,  FS_BOOL bReParse,  FS_BOOL bOwnFileRead))

/**
 * @brief FPDParserCloseParser
 * @details Closes the parser, as well as the file. If reparsing is used, the document will be kept.
 * @param[in]  parser The PDF file parser.
 * @param[in]  bReParse A flag indicates whether reparsing is used.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserCloseParser, (FPD_Parser parser,  FS_BOOL bReParse))

/**
 * @brief FPDParserGetPermissions
 * @details Gets the use permissions of a PDF file.
 * @param[in]  parser The PDF file parser.
 * @return   The permission codes. See <a>FPDDocPermissions</a>.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetPermissions, (FPD_Parser parser))

/**
 * @brief FPDParserIsOwner
 * @details Tests whether the user has the owner permission of the document.
 * @param[in]  parser The PDF file parser.
 * @return   <a>TRUE</a> for owner permission, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserIsOwner, (FPD_Parser parser))

/**
 * @brief FPDParserSetPassword
 * @details Sets the password of standard encryption for the parser.
 * @param[in]  parser The PDF file parser.
 * @param[in]  password The input password string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserSetPassword, (FPD_Parser parser,  const FS_CHAR* password))

/**
 * @brief FPDParserGetPassword
 * @details Gets the password string.
 * @param[in]  parser The PDF file parser.
 * @param[out]  outPassword A buffer to receive the password string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserGetPassword, (FPD_Parser parser,  FS_ByteString* outPassword))

/**
 * @brief FPDParserGetTrailer
 * @details Gets the trailer dictionary.
 * @param[in]  parser The PDF file parser.
 * @return   The trailer dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserGetTrailer, (FPD_Parser parser))

/**
 * @brief FPDParserGetLastXRefOffset
 * @details Gets the offset of last xref.
 * @param[in]  parser The PDF file parser.
 * @return   The bytes of the xref offset.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetLastXRefOffset, (FPD_Parser parser))

/**
 * @brief FPDParserGetDocument
 * @details Gets the <a>FPD_Document</a> object which associate with a PDF file.
 * @param[in]  parser The PDF file parser.
 * @return   The new empty document.
 * @note 
 */
INTERFACE(FPD_Document, FPDParserGetDocument, (FPD_Parser parser))

/**
 * @brief FPDParserCountOtherTrailers
 * @details Gets the total number of the trailers in a PDF file.
 * @param[in]  parser The PDF file parser.
 * @return   The total number of the trailers in a PDF file.
 * @note 
 */
INTERFACE(FS_INT32, FPDParserCountOtherTrailers, (FPD_Parser parser))

/**
 * @brief FPDParserGetOtherTrailerByIndex
 * @details Gets the specified trailer dictionary.
 * @param[in]  parser The PDF file parser.
 * @param[in]  index The index of trailer which will be obtained, the range is 0 to <a>FPDParserCountOtherTrailers</a>()-1.
 * @return   The specified trailer dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserGetOtherTrailerByIndex, (FPD_Parser parser,  FS_INT32 index))

/**
 * @brief FPDParserGetRootObjNum
 * @details Gets the object number of file catalog dictionary.
 * @param[in]  parser The PDF file parser.
 * @return   The object number of file root(catalog) dictionary.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetRootObjNum, (FPD_Parser parser))

/**
 * @brief FPDParserGetInfoObjNum
 * @details Gets the object number of the file information dictionary.
 * @param[in]  parser The PDF file parser.
 * @return   The object number indicates the file information dictionary.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetInfoObjNum, (FPD_Parser parser))

/**
 * @brief FPDParserGetIDArray
 * @details Gets the ID array in a PDF file.
 * @param[in]  parser The PDF file parser.
 * @return   A PDF array object which contain the IDs of a PDF file.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserGetIDArray, (FPD_Parser parser))

/**
 * @brief FPDParserGetEncryptDict
 * @details Gets the encrypt dictionary which contain encrypt information.
 * @param[in]  parser The PDF file parser.
 * @return   The encrypt dictionary object.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserGetEncryptDict, (FPD_Parser parser))

/**
 * @brief FPDParserParseIndirectObject
 * @details Parses the indirect objects.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objList The <a>FPD_Document</a> object which contains all indirect objects.
 * @param[in]  objnum The object number.
 * @param[in]  pContext The parse context. See <a>FPD_PARSE_CONTEXT</a>.
 * @return   A PDF object.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserParseIndirectObject, (FPD_Parser parser,  FPD_Document objList,  FS_DWORD objnum,  FPD_PARSE_CONTEXT* pContext))

/**
 * @brief FPDParserGetLastObjNum
 * @details Gets the lastest object number.
 * @param[in]  parser The PDF file parser.
 * @return   The object number of the last object in a PDF file.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetLastObjNum, (FPD_Parser parser))

/**
 * @brief FPDParserIsFormStream
 * @details Checks if an indirect object is a form stream or not, without actually loading the object.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The stream object number.
 * @param[out]  bForm It receive whether it's a form stream or not.
 * @return   Non-zero means determined, otherwise unknown.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserIsFormStream, (FPD_Parser parser,  FS_DWORD objnum,  FS_BOOL* bForm))

/**
 * @brief FPDParserReloadFileStream
 * @details Reloads stream content of a specified stream object.
 * @param[in]  parser The PDF file parser.
 * @param[in]  stream The stream object which content stream will be reload.
 * @return   <a>TRUE</a> for success, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserReloadFileStream, (FPD_Parser parser,  FPD_Object stream))

/**
 * @brief FPDParserDeleteIndirectObject
 * @details Deletes a indirect object form a file.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number to be deleted.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserDeleteIndirectObject, (FPD_Parser parser,  FS_DWORD objnum))

/**
 * @brief FPDParserGetLengthOfVersions
 * @details Gets the version's length of the file.
 * @param[in]  parser The PDF file parser.
 * @param[in]  arrayLengths A DWORD array to receive the length of versions.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserGetLengthOfVersions, (FPD_Parser parser,  FS_DWordArray arrayLengths))

/**
 * @brief FPDParserGetObjectOffset
 * @details Gets offset of indirect object.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number.
 * @return   The offset of the indirect object. For objects stored in object stream, this is the 
	* offset of the object stream.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetObjectOffset, (FPD_Parser parser,  FS_DWORD objnum))

/**
 * @brief FPDParserGetObjectSize
 * @details Gets data size of indirect object.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number.
 * @return   The data size, in bytes, of the indirect object. For objects stored in object stream, this is the 
	* data size of the object stream.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetObjectSize, (FPD_Parser parser,  FS_DWORD objnum))

/**
 * @brief FPDParserGetObjectVersion
 * @details Gets the generation number of indirect object.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number.
 * @return   The generation number of the indirect object.
 * @note 
 */
INTERFACE(int, FPDParserGetObjectVersion, (FPD_Parser parser,  FS_DWORD objnum))

/**
 * @brief FPDParserGetIndirectBinary
 * @details For faster file updating, we can get the binary form of an indirect object, then
	* directly output to destination file. In this case we must call the following
	* function to get the binary buffer.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number.
 * @param[in]  buffer A binary buffer to receive bytes.
 * @return   void
 * @note This function can't be used for any updated PDF file.
 */
INTERFACE(void, FPDParserGetIndirectBinary, (FPD_Parser parser,  FS_DWORD objnum,  FS_BinaryBuf buffer))

/**
 * @brief FPDParserParseStreamPos
 * @details Gets position information for a stream:<br>
	* <ul>
	* <li>Start position (just before "<<") and end position (just after ">>") of the stream's dictionary</li>
	* <li>Start position (first byte) and end position (just after the last byte) of the stream's data</li>
	* </ul>
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number.
 * @param[out]  dict_start Start position of the stream's dictionary.
 * @param[out]  dict_end End position of the stream's dictionary.
 * @param[out]  data_start Start position of the stream's data.
 * @param[out]  data_end End position of the stream's data.
 * @return   Non-zero means parse successfully, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserParseStreamPos, (FPD_Parser parser,  FS_DWORD objnum,  FS_DWORD* dict_start,  FS_DWORD* dict_end,  FS_DWORD* data_start,  FS_DWORD* data_end))

/**
 * @brief FPDParserParseIndirectObjectsAtRange
 * @details Gets the indirect objects in specify byte range.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objNum The indirect object number.
 * @param[in]  objPos The indirect object's start position.
 * @param[in]  dwPos The start position.
 * @param[in]  dwLen The length will be parsed.
 * @param[in]  context The parse context.
 * @return   Non_zero means parse successfully, otherwise not.
 * @note This function is bitwise search so very slow.
 */
INTERFACE(FS_BOOL, FPDParserParseIndirectObjectsAtRange, (FPD_Parser parser,  FS_DWordArray objNum,  FS_DWordArray objPos,  FS_DWORD dwPos,  FS_DWORD dwLen,  FPD_PARSE_CONTEXT* context))

/**
 * @brief FPDParserGetFileStreamOption
 * @details Get the file stream option.
	* <brief>Loading stream content into memory will improve performance for frequent access,
	* however, it will also consume a lot of memory space.
	* Therefore, we provide an option to leave stream content on file system, and read them
	* whenever we need them. If may reduce the performance a little bit, but greatly reduce
	* the memory consumption, especially when the file is big.
 * @param[in]  parser The PDF file parser.
 * @return   The new empty document.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserGetFileStreamOption, (FPD_Parser parser))

/**
 * @brief FPDParserSetFileStreamOption
 * @details Sets the file stream option.
 * @param[in]  parser The PDF file parser.
 * @param[in]  b A flag indicates whether the stream is a file stream.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserSetFileStreamOption, (FPD_Parser parser,  FS_BOOL b))

/**
 * @brief FPDParserGetFileAccess
 * @details Gets the stream access interface.
 * @param[in]  parser The PDF file parser.
 * @return   A file access interface handler.
 * @note 
 */
INTERFACE(FS_FileReadHandler, FPDParserGetFileAccess, (FPD_Parser parser))

/**
 * @brief FPDParserGetFileVersion
 * @details Gets the file version. File version: 14 for 1.4, 15 for 1.5, ...
 * @param[in]  parser The PDF file parser.
 * @return   The new empty document.
 * @note 
 */
INTERFACE(FS_INT32, FPDParserGetFileVersion, (FPD_Parser parser))

/**
 * @brief FPDParserIsXRefStream
 * @details Tests whether cross reference stream is used.
 * @param[in]  parser The PDF file parser.
 * @return   <a>TRUE</a> for xref stream, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserIsXRefStream, (FPD_Parser parser))

/**
 * @brief FPDParserParseIndirectObjectAt
 * @details Parses an indirect object specified by object position.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objList The <a>FPD_Document</a> object that contain the indirect objects.
 * @param[in]  pos The position specified the indirect object.
 * @param[in]  objnum The indirect object number.
 * @param[in]  pContext The parse context.
 * @return   A PDF object.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserParseIndirectObjectAt, (FPD_Parser parser,  FPD_Document objList,  FS_DWORD pos,  FS_DWORD objnum,  FPD_PARSE_CONTEXT* pContext))

/**
 * @brief FPDParserStartAsynParse
 * @details Asynchronous parsing a custom file.
 * @param[in]  parser The PDF file parser.
 * @param[in]  pFile The stream access interface handler.
 * @param[in]  bReParse A flag indicates whether we will do reparsing.
 * @return   The status of PDF parsing.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserStartAsynParse, (FPD_Parser parser,  FS_FileReadHandler pFile,  FS_BOOL bReParse))

/**
 * @brief FPDParserGetFirstPageNo
 * @details Get the first page number.
 * @param[in]  parser The PDF file parser.
 * @return   The index of first page.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetFirstPageNo, (FPD_Parser parser))

/**
 * @brief FPDParserGetSecurityPermissions
 * @details Gets permission settings of the document.
 * @param[in]  parser The PDF file parser.
 * @return   The permission settings of the document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DWORD, FPDParserGetSecurityPermissions, (FPD_Parser parser))

/**
 * @brief FPDParserIsSecurityOwner
 * @details Checks whether the current user is owner of the document.
 * @param[in]  parser The PDF file parser.
 * @return   Whether the current user is owner of the document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDParserIsSecurityOwner, (FPD_Parser parser))

/**
 * @brief FPDParserGetSecurityCryptInfo
 * @details Gets encryption information including standard algorithm and key.
 * @param[in]  parser The PDF file parser.
 * @param[out]  outCipher Receives cipher identifier (FPD_CIPHER_NONE, FPD_CIPHER_RC4 or FPD_CIPHER_AES).
 * @param[out]  outBuffer Receives a pointer to the key buffer.
 * @param[out]  outKeylen Receives number of bytes in the key.
 * @return   <a>TRUE</a> if successful. <a>FALSE</a> if no standard key info is provided or failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDParserGetSecurityCryptInfo, (FPD_Parser parser,  FS_INT32* outCipher,  FS_LPCBYTE* outBuffer,  FS_INT32* outKeylen))

/**
 * @brief FPDParserIsMetadataEncryptedBySecurity
 * @details Checks whether document metadata needs to be encrypted.
 * @param[in]  parser The PDF file parser.
 * @return   Whether document metadata needs to be encrypted.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDParserIsMetadataEncryptedBySecurity, (FPD_Parser parser))

/**
 * @brief FPDParserGetStandardSecurityUserPassword
 * @details Gets user password from an owner password.
 * @param[in]  parser The PDF file parser.
 * @param[in]  owner_pass The owner password pointer.
 * @param[in]  pass_size The length of the owner password.
 * @param[out]  outUserPsswrd Receives number of bytes in the key.
 * @return   It receives the correspond user password for this standard security handler.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDParserGetStandardSecurityUserPassword, (FPD_Parser parser,  FS_LPCBYTE owner_pass,  FS_DWORD pass_size,  FS_ByteString* outUserPsswrd))

/**
 * @brief FPDParserGetStandardSecurityVersion
 * @details Gets the version of standard security.
 * @param[in]  parser The PDF file parser.
 * @return   The version of standard security.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_INT32, FPDParserGetStandardSecurityVersion, (FPD_Parser parser))

/**
 * @brief FPDParserGetStandardSecurityRevision
 * @details Gets the revision of standard security.
 * @param[in]  parser The PDF file parser.
 * @return   The revision of standard security.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_INT32, FPDParserGetStandardSecurityRevision, (FPD_Parser parser))

/**
 * @brief FPDParserCheckStandardSecurityPassword
 * @details Checks whether the password is verified successfully.
 * @param[in]  parser The PDF file parser.
 * @param[in]  password The input password pointer.
 * @param[in]  pass_size The size of the password.
 * @param[in]  bOwner Whether check the owner password.
 * @param[out]  key Pointer to key buffer to receive the encryption key. NULL for don't calculate the key.
 * @return   <a>FALSE</a> for invalid password, <a>TRUE</a> for password verified.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDParserCheckStandardSecurityPassword, (FPD_Parser parser,  FS_LPCBYTE password,  FS_DWORD pass_size,  FS_BOOL bOwner,  FS_LPBYTE* key))

/**
 * @brief FPDParserCheckEmbeddedSecurity
 * @details Checks the access to the encrypted embedded file stream.
 * @param[in]  parser The PDF file parser.
 * @param[in]  name The name of the crypt filter that should be used by default when encrypting embedded file streams.
 * @return   The returned value can refer to <a>FPDParseErrCodes</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 */
INTERFACE(FS_DWORD, FPDParserCheckEmbeddedSecurity, (FPD_Parser parser,  FS_LPCSTR name))

/**
 * @brief FPDParserLoadAttachmentStream
 * @details Loads the attachment stream.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The object number of the attachment stream.
 * @param[out]  outStremObj It receives the pointer to the loaded attachment stream object.
 * @return   The returned value can refer to <a>FPDParseErrCodes</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 */
INTERFACE(FS_DWORD, FPDParserLoadAttachmentStream, (FPD_Parser parser,  FS_DWORD objnum,  FPD_Object* outStremObj))

/**
 * @brief FPDParserSetUnicodePassword
 * @details Set the unicode password of standard encryption for the parser.
 * @param[in]  parser The PDF file parser.
 * @param[in]  password The input unicode password string.
 * @return   Zero means the unicode password strings include invalid characters.
 * @note Only the PDF2.0 supports for the Unicode-based passwords.
 */
INTERFACE(FS_BOOL, FPDParserSetUnicodePassword, (FPD_Parser parser,  const FS_WCHAR* password))

/**
 * @brief FPDParserGetUnicodePassword
 * @details Get the Unicode-based passwords.
 * @param[in]  parser The PDF file parser.
 * @param[out]  outPassword A buffer to receive the Unicode-based password string.
 * @return   void
 * @note Only the PDF2.0 supports for the Unicode-based passwords.
 */
INTERFACE(void, FPDParserGetUnicodePassword, (FPD_Parser parser,  FS_WideString* outPassword))

/**
 * @brief FPDParserCheckPassword
 * @details Check whether the password is verified successfully.
 * @param[in]  parser The PDF file parser.
 * @param[in]  password The input password pointer.
 * @param[in]  pass_size The size of the password.
 * @param[in]  bOwner Whether check the owner password
 * @param[out]  key Pointer to key buffer to receive the encryption key. NULL for don't calculate the key.
 * @return   FALSE for invalid password, TRUE for password verified.
 * @note Only the PDF2.0 supports for the Unicode-based CheckPassword.
 */
INTERFACE(FS_INT32, FPDParserCheckPassword, (FPD_Parser parser,  FS_LPCWSTR password,  FS_DWORD pass_size,  FS_BOOL bOwner,  FS_LPBYTE* key))

/**
 * @brief FPDParserSetPassword2
 * @details Sets the password of standard encryption for the parser.
 * @param[in]  parser The PDF file parser.
 * @param[in]  password The input password string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserSetPassword2, (FPD_Parser parser,  const FS_ByteString password))

/**
 * @brief FPDParserSetPassword3
 * @details Sets the password of standard encryption for the parser.
 * @param[in]  parser The PDF file parser.
 * @param[in]  password The input password string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserSetPassword3, (FPD_Parser parser,  const FS_WideString  password))

/**
 * @brief FPDParserCheckHasCryptoHandler
 * @details Check if has encrypt handler.
 * @param[in]  parser The PDF file parser.
 * @return   FS_BOOL            TRUE means encrypt handler is not NULL.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserCheckHasCryptoHandler, (FPD_Parser parser))

INTERFACE(FS_INT32, FPDParserCheckPassword2, (FPD_Parser parser,  FS_LPBYTE password,  FS_DWORD pass_size,  FS_BOOL bOwner,  FS_LPBYTE* key))

/**
 * @brief FPDParserIsParsingLinearized
 * @details Whether the parsing file is a Linearized PDF.
 * @param[in]  parser The PDF file parser.
 * @return   FS_BOOLEAN         Non_zero means is a Linearized PDF, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDParserIsParsingLinearized, (FPD_Parser parser))

/**
 * @brief FPDParserHasRebuildXRef
 * @details Whether the cross-reference information has been rebuild.
 * @param[in]  parser The PDF file parser.
 * @return   FS_BOOLEAN        true means rebuilded, otherwise false.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDParserHasRebuildXRef, (FPD_Parser parser))

/**
 * @brief FPDParserGetSizeAnalysis
 * @details Get FPD_SizeAnalysis object.
 * @param[in]  parser The PDF file parser.
 * @return   FPD_SizeAnalysis
 * @note 
 */
INTERFACE(FPD_SizeAnalysis, FPDParserGetSizeAnalysis, (FPD_Parser parser))

/**
 * @brief FPDParserEnableSizeAnalysis
 * @details Set whether enable size analysis.
 * @param[in]  parser The PDF file parser.
 * @param[in]  bEnable Whether enable size analysis.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserEnableSizeAnalysis, (FPD_Parser parser,  FS_BOOLEAN bEnable))

/**
 * @brief FPDParserSetObjStmCacheLimitSize
 * @details Set Object Stream Cache limit size.
 * @param[in]  parser The PDF file parser.
 * @param[in]  dwLimitSize The cache limit size.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserSetObjStmCacheLimitSize, (FPD_Parser parser,  FS_DWORD dwLimitSize))

/**
 * @brief FPDParserContinue
 * @details The status of PDF parsing.
 * @param[in]  parser The PDF file parser.
 * @param[in]  dwLimitSize The pause interface.
 * @return   void
 * @note 
 */
INTERFACE(FS_INT32, FPDParserContinue, (FPD_Parser parser,  FS_PauseHandler pPause))

/**
 * @brief FPDParserSetRecipient
 * @details Set the recipient content.
 * @param[in]  parser The PDF file parser.
 * @param[in]  bsRecipient The input recipient content.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserSetRecipient, (FPD_Parser parser,  FS_LPCSTR bsRecipient))

/**
 * @brief FPDParserCheckStandardSecurityPassword2
 * @details Checks whether the password is verified successfully.
 * @param[in]  parser The PDF file parser.
 * @param[in]  password The input password pointer.
 * @param[in]  pass_size The size of the password.
 * @param[in]  bOwner Whether check the owner password.
 * @param[out]  key Pointer to key buffer to receive the encryption key. NULL for don't calculate the key.
 * @return   <a>FALSE</a> for invalid password, <a>TRUE</a> for password verified.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 */
INTERFACE(FS_BOOL, FPDParserCheckStandardSecurityPassword2, (FPD_Parser parser,  FS_LPCWSTR password,  FS_DWORD pass_size,  FS_BOOL bOwner,  FS_LPBYTE* key))

NumOfSelector(FPDParser)
ENDENUM

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
//*****************************
/* StandardCryptoHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_StandardCryptoHandler, FPDStandardCryptoHandlerNew, ())

INTERFACE(void, FPDStandardCryptoHandlerDestroy, (FPD_StandardCryptoHandler handler))

INTERFACE(FS_BOOL, FPDStandardCryptoHandlerInit, (FPD_StandardCryptoHandler handler,  FS_INT32 cipher,  FS_LPCBYTE key,  FS_INT32 keylen))

INTERFACE(FS_BOOL, FPDStandardCryptoHandlerInitByDic, (FPD_StandardCryptoHandler handler,  FPD_Object pEncryptDict,  FPD_Parser parser))

INTERFACE(FS_DWORD, FPDStandardCryptoHandlerDecryptGetSize, (FPD_StandardCryptoHandler handler,  FS_DWORD src_size))

INTERFACE(FS_LPVOID, FPDStandardCryptoHandlerDecryptStart, (FPD_StandardCryptoHandler handler,  FS_DWORD objnum,  FS_DWORD gennum))

INTERFACE(FS_BOOL, FPDStandardCryptoHandlerDecryptStream, (FPD_StandardCryptoHandler handler,  FS_LPVOID context,  FS_LPCBYTE src_buf,  FS_DWORD src_size,  FS_BinaryBuf& dest_buf))

INTERFACE(FS_BOOL, FPDStandardCryptoHandlerDecryptFinish, (FPD_StandardCryptoHandler handler,  FS_LPVOID context,  FS_BinaryBuf& dest_buf))

INTERFACE(FS_DWORD, FPDStandardCryptoHandlerEncryptGetSize, (FPD_StandardCryptoHandler handler,  FS_DWORD objnum,  FS_DWORD gennum,  FS_LPCBYTE src_buf,  FS_DWORD src_size))

INTERFACE(FS_BOOL, FPDStandardCryptoHandlerEncryptContent, (FPD_StandardCryptoHandler handler,  FS_DWORD objnum,  FS_DWORD gennum,  FS_LPCBYTE src_buf,  FS_DWORD src_size,  FS_LPBYTE dest_buf,  FS_DWORD& dest_size))

INTERFACE(FS_LPVOID, FPDStandardCryptoHandlerClone, (FPD_StandardCryptoHandler handler))

NumOfSelector(FPDStandardCryptoHandler)
ENDENUM

//*****************************
/* FipsStandardCryptoHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_FipsStandardCryptoHandler, FPDFipsStandardCryptoHandlerNew, ())

INTERFACE(void, FPDFipsStandardCryptoHandlerDestroy, (FPD_FipsStandardCryptoHandler handler))

INTERFACE(FS_BOOL, FPDFipsStandardCryptoHandlerInit, (FPD_FipsStandardCryptoHandler handler,  FS_INT32 cipher,  FS_LPCBYTE key,  FS_INT32 keylen))

INTERFACE(FS_BOOL, FPDFipsStandardCryptoHandlerInit2, (FPD_FipsStandardCryptoHandler handler,  FPD_Object pEncryptDict,  FPD_Parser parser))

NumOfSelector(FPDFipsStandardCryptoHandler)
ENDENUM

//*****************************
/* SimpleParser HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDSimpleParserNew
 * @details Construct a simple parser from a buffer. The buffer must retain valid until parsing finished.
	 * use <a>FPDParserGetDocument</a>() to get a <a>FPD_Document</a> object.
 * @param[in]  pData The input buffer.
 * @param[in]  dwSize The size in bytes of the buffer.
 * @return   FPD_SimpleParser   The newly created Simple parser.
 * @note 
 */
INTERFACE(FPD_SimpleParser, FPDSimpleParserNew, (FS_LPCBYTE pData,  FS_DWORD dwSize))

/**
 * @brief FPDSimpleParserNew2
 * @details Construct a simple parser from string. The string must retain valid until parsing finished.
	 * use <a>FPDParserGetDocument</a>() to get a <a>FPD_Document</a> object.
 * @param[in]  str The input string.
 * @return   FPD_SimpleParser   The newly created Simple parser.
 * @note 
 */
INTERFACE(FPD_SimpleParser, FPDSimpleParserNew2, (FS_LPCBYTE str))

/**
 * @brief FPDSimpleParserDestroy
 * @details Destroy the parser obj.
 * @param[in]  parser The input parser obj.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDSimpleParserDestroy, (FPD_SimpleParser parser))

/**
 * @brief FPDSimpleParserGetWord
 * @details * Get next word. NOTE: the word will be returned in its original form, unescaped, un-decoded.
	 *For example, it will recognize "(hello(there)! :\))" as a legimate PDF string constant, however it
	 *won't return the value "hello(there)! :)", instead, the original form "(hello(there)!:\))" is returned.
	 *Likewise, names are always returned with the preceding "/".
 * @param[in]  parser The input parser obj.
 * @param[out]  word The input string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDSimpleParserGetWord, (FPD_SimpleParser parser,  FS_ByteString* word))

/**
 * @brief FPDSimpleParserSearchToken
 * @details Search a token from the current position, when stopped, the current position will be immediately
	 *after the found token.If token not found, the parser will stop at end of the buffer, and return false.
 * @param[in]  parser The input parser obj.
 * @param[out]  token The token to be searched.
 * @return   FS_BOOLEAN    return Non-zero means found a token, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDSimpleParserSearchToken, (FPD_SimpleParser parser,  FS_LPCBYTE token))

/**
 * @brief FPDSimpleParserSkipWord
 * @details Search a word from the current position. The parser will stop immediately after the found word.
	  *If not found, the parser will stop at end of the buffer, and return false.
 * @param[in]  parser The input parser obj.
 * @param[out]  token The token to be skipped.
 * @return   FS_BOOLEAN    return Non-zero means found a token, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDSimpleParserSkipWord, (FPD_SimpleParser parser,  FS_LPCBYTE token))

/**
 * @brief FPDSimpleParserFindTagPair
 * @details Find a start token and an end token (compared word by word), get the position after the start token,
	 * and position before the end token.
 * @param[in]  parser The input parser obj.
	 *param[in] start_token	The start token to be found.
	 *param[in] end_token		The end token to be found.
	 *param[out] start_pos	It receives the position after the start token.
	 *param[out] end_pos		It receives the position before the end token.
 * @return   FS_BOOLEAN    Non-zero means find one, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDSimpleParserFindTagPair, (FPD_SimpleParser parser,  FS_LPCBYTE start_token,  FS_LPCBYTE end_token,  FS_DWORD* start_pos,  FS_DWORD* end_pos))

/**
 * @brief FPDSimpleParserFindTagParam
 * @details Search from the current position for a parameter of a tag. This is often used for parsing simple PostScript style
	*texts.For example, if you have a buffer like "/F1 12.5 Tf ...", and you search for param #1 of "Tf" token,
	*the parser will first search for token "Tf", then go back one word, and stop at the parameter value "12.5".
 * @param[in]  parser The input parser obj.
	*param[in] token			The token to be searched.
	*param[in] nParams		Zero-based index of the parameters for the token.
 * @return   FS_BOOLEAN   Non-zero means find successfully, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDSimpleParserFindTagParam, (FPD_SimpleParser parser,  FS_LPCBYTE token,  FS_INT32 nParams))

/**
 * @brief FPDSimpleParserGetPos
 * @details Get current position of the parser.
 * @param[in]  parser The input parser obj.
 * @return   FS_DWORD
 * @note 
 */
INTERFACE(FS_DWORD, FPDSimpleParserGetPos, (FPD_SimpleParser parser))

/**
 * @brief FPDSimpleParserSetPos
 * @details Set current position.
 * @param[in]  parser The input parser obj.
 * @param[in]  pos The postion.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDSimpleParserSetPos, (FPD_SimpleParser parser,  FS_DWORD pos))

NumOfSelector(FPDSimpleParser)
ENDENUM

//----------_V15----------
//----------_V16----------
//*****************************
/* NumberTree HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDNumberTreeCreteNumberTree
 * @details Construct a number tree object from the parent dictionary.
 * @param[in]  pParent The dictionary which the number tree will be set to, like "Catalog", "StructTreeRoot" dictionary, etc.
 * @param[in]  sCategory The category key name for number tree, like "PageLabels", "ParentTree", etc.
 * @return   FPD_NumberTree
 * @note 
 */
INTERFACE(FPD_NumberTree, FPDNumberTreeCreteNumberTree, (FPD_Object pParent,  FS_LPCSTR sCategory))

/**
 * @brief FPDNumberTreeDeleteNumberTree
 * @details Delete FPD_NumberTree.
 * @param[in]  numberTree The input FPD_NumberTree.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDNumberTreeDeleteNumberTree, (FPD_NumberTree numberTree))

/**
 * @brief FPDNumberTreeLookupValue
 * @details Lookup a PDF object identified by number.
 * @param[in]  numberTree The input FPD_NumberTree.
 * @param[in]  num The input number.
 * @return   FPD_Object
 * @note 
 */
INTERFACE(FPD_Object, FPDNumberTreeLookupValue, (FPD_NumberTree numberTree,  FS_INT32 num))

/**
 * @brief FPDNumberTreeSetValue
 * @details Set the entry value of specified PDF number tree node that contains specified number.
 * @param[in]  numberTree The input FPD_NumberTree.
 * @param[in]  pDoc The input FPD_Document.
 * @param[in]  num The input number.
 * @param[in]  pValue The input entry value.
 * @return   FS_BOOLEAN     The value nonzero if successful, otherwise 0.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDNumberTreeSetValue, (FPD_NumberTree numberTree,  FPD_Document pDoc,  FS_INT32 num,  FPD_Object pValue))

/**
 * @brief FPDNumberTreeRemove
 * @details Remove the number form the number tree.
 * @param[in]  numberTree The input FPD_NumberTree.
 * @param[in]  num The input number.
 * @return   FS_BOOLEAN     The value nonzero if successful, otherwise 0.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDNumberTreeRemove, (FPD_NumberTree numberTree,  FS_INT32 num))

NumOfSelector(FPDNumberTree)
ENDENUM

//*****************************
/* SizeAnalysis HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDSizeAnalysisGetObjectSize
 * @details Get the size of the object.
 * @param[in]  analysis The PDF file parser.
 * @param[in]  pObj The input object.
 * @return   FS_DWORD
 * @note 
 */
INTERFACE(FS_DWORD, FPDSizeAnalysisGetObjectSize, (FPD_SizeAnalysis analysis,  FPD_Object pObj))

/**
 * @brief FPDSizeAnalysisGetContentSize
 * @details Get the content size of the object.
 * @param[in]  analysis The PDF file parser.
 * @param[in]  pObj The input object.
 * @return   FS_DWORD
 * @note 
 */
INTERFACE(FS_DWORD, FPDSizeAnalysisGetContentSize, (FPD_SizeAnalysis analysis,  FPD_Object pObj))

/**
 * @brief FPDSizeAnalysisGetXRefSize
 * @details Get the reference size of the object.
 * @param[in]  analysis The PDF file parser.
 * @return   FS_DWORD
 * @note 
 */
INTERFACE(FS_DWORD, FPDSizeAnalysisGetXRefSize, (FPD_SizeAnalysis analysis))

/**
 * @brief FPDSizeAnalysisClear
 * @details Clear the data of the analysis.
 * @param[in]  analysis The PDF file parser.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDSizeAnalysisClear, (FPD_SizeAnalysis analysis))

NumOfSelector(FPDSizeAnalysis)
ENDENUM

//----------_V17----------
//*****************************
/* SyntaxParser HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDSyntaxParserNew
 * @details Create FPD_SyntaxParser object.
 * @return   FPD_SyntaxParser
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 */
INTERFACE(FPD_SyntaxParser, FPDSyntaxParserNew, ())

/**
 * @brief FPDSyntaxParserDestroy
 * @details Destroy FPD_SyntaxParser object.
 * @param[in]  parser The input FPD_SyntaxParser object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 */
INTERFACE(void, FPDSyntaxParserDestroy, (FPD_SyntaxParser parser))

/**
 * @brief FPDSyntaxParserInitParser
 * @details Init he syntax parser.
 * @param[in]  parser The input FPD_SyntaxParser object.
 * @param[in]  pFileAccess The stream access interface.
 * @param[in]  HeaderOffset The PDF header offset in the stream.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 */
INTERFACE(void, FPDSyntaxParserInitParser, (FPD_SyntaxParser parser,  FS_FileReadHandler pFileAccess,  FS_DWORD HeaderOffset))

/**
 * @brief FPDSyntaxParserGetObject
 * @details Init he syntax parser.
 * @param[in]  parser The input FPD_SyntaxParser object.
 * @param[in]  pObjList An indirect object list.
 * @param[in]  objnum The object number.
 * @param[in]  gennum The object generation number.
 * @param[in]  level The input level.
 * @param[in]  pContext The parser context.
 * @param[in]  bDecrypt Whether need to decrypt.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 */
INTERFACE(FPD_Object, FPDSyntaxParserGetObject, (FPD_SyntaxParser parser,  FPD_Document pObjList,  FS_DWORD objnum,  FS_DWORD gennum,  FS_INT32 level,  FPD_PARSE_CONTEXT* pContext,  FS_BOOLEAN bDecrypt))

NumOfSelector(FPDSyntaxParser)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

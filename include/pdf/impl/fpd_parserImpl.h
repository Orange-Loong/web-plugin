#ifndef FPD_PARSERIMPL_H
#define FPD_PARSERIMPL_H

#ifndef FPD_PARSEREXPT_H
#include "../fpd_parserExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif


#ifdef __cplusplus
extern "C"{
#endif

class CFPD_Parser_V1
{
public:
	//************************************
	// Function: New
	// Param[in]: void
	// Return:   The newly created parser.
	// Remarks:	 Creates a new PDF file parser. </Brief>The PDF file parser will parse entire PDF file and then build a <a>FPD_Document</a> object,
	// use <a>FPDParserGetDocument</a>() to get a <a>FPD_Document</a> object.
	// Notes:
	//************************************
	static FPD_Parser New(void);

	//************************************
	// Function: Destroy
	// Param[in]:	parser		The parser to be free.
	// Return:   void
	// Remarks:	 Destroy a PDF file parser.
	// Notes:
	//************************************
	static void Destroy(FPD_Parser parser);

	//************************************
	// Function: StartParse
	// Param[in]: parser		The PDF file parser.
	// Param[in]: filename		The file full path name that will be parsed.
	// Param[in]: bReParse		A flag indicates whether you will do reparsing.
	// Return:   The status of PDF parsing. See <a>FPDParseErrCodes</a>.
	// Remarks:	 Starts parsing from a file, ANSIC version. Use <a>FPDParserCloseParse</a>() to end the parsing.
	// Notes:
	//************************************
	static FS_DWORD			StartParse(FPD_Parser parser, FS_LPCSTR filename, FS_BOOL bReParse);

	//************************************
	// Function: StartParseW
	// Param[in]: parser		The PDF file parser.
	// Param[in]: filename		The file full path name that will be parsed.
	// Param[in]: bReParse		A flag indicates whether you will do reparsing.
	// Return:   The status of PDF parsing. See <a>FPDParseErrCodes</a>
	// Remarks:	 Starts parsing from a file, Unicode version. Use <a>FPDParserCloseParse</a>() to end the parsing.
	// Notes:
	//************************************
	static FS_DWORD			StartParseW(FPD_Parser parser, FS_LPCWSTR filename, FS_BOOL bReParse);

	//************************************
	// Function: StartParseFormMem
	// Param[in]: parser		The PDF file parser.
	// Param[in]: pData			The input memory block that contains the PDF file data.
	// Param[in]: nSize			The size in bytes of the memory block.
	// Param[in]: bReParse		A flag indicates whether you will do reparsing.
	// Return:   The status of PDF parsing. See <a>FPDParseErrCodes</a>
	// Remarks:	 Starts parsing from memory block. Use <a>FPDParserCloseParse</a>() to end the parsing.
	// Notes:
	//************************************
	static FS_DWORD			StartParseFormMem(FPD_Parser parser, FS_LPCBYTE pData, FS_DWORD nSize, FS_BOOL bReParse);

	//************************************
	// Function: StartParseCustomFile
	// Param[in]: parser				The PDF file parser.
	// Param[in]: file				The stream access interface. Use <a>FSFileReadHandlerNew</a>() to create a file access interface.
	// Param[in]: bReParse			A flag indicates whether you will do reparsing.
	// Param[in]: bOwnFileRead		A flag indicated whether <a>FPD_Parser</a> takes ownership of the file read structure (by calling <a>FSFileReadHandlerDestroy</a>() when parser cleans up).
	// Return:   The status of PDF parsing. See <a>FPDParseErrCodes</a>
	// Remarks:	 Starts parsing a custom file. Use <a>FPDParserCloseParse</a>() to end the parsing.
	// Notes:
	//************************************
	static FS_DWORD			StartParseCustomFile(FPD_Parser parser, FS_FileReadHandler file, FS_BOOL bReParse, FS_BOOL bOwnFileRead);

	//************************************
	// Function: CloseParser
	// Param[in]: parser			The PDF file parser.
	// Param[in]: bReParse		A flag indicates whether reparsing is used.
	// Return:   void
	// Remarks:	 Closes the parser, as well as the file. If reparsing is used, the document will be kept.
	// Notes:
	//************************************
	static void				CloseParser(FPD_Parser parser, FS_BOOL bReParse);

	//************************************
	// Function: GetPermissions
	// Param[in]: parser			The PDF file parser.
	// Return:   The permission codes. See <a>FPDDocPermissions</a>.
	// Remarks:	 Gets the use permissions of a PDF file.
	// Notes:
	//************************************
	static FS_DWORD			GetPermissions(FPD_Parser parser);

	//************************************
	// Function: IsOwner
	// Param[in]: parser			The PDF file parser.
	// Return:   <a>TRUE</a> for owner permission, otherwise <a>FALSE</a>.
	// Remarks:	 Tests whether the user has the owner permission of the document.
	// Notes:
	//************************************
	static FS_BOOL			IsOwner(FPD_Parser parser);

	//************************************
	// Function: SetPassword
	// Param[in]: parser			The PDF file parser.
	// Param[in]: password			The input password string.
	// Return:   void
	// Remarks:	 Sets the password of standard encryption for the parser.
	// Notes:
	//************************************
	static void				SetPassword(FPD_Parser parser,  const FS_CHAR* password);

	//************************************
	// Function: GetPassword
	// Param[in]: parser			The PDF file parser.
	// Param[out]: outPassword		A buffer to receive the password string. 
	// Return:   void
	// Remarks:	 Gets the password string.
	// Notes:
	//************************************
	static void				GetPassword(FPD_Parser parser, FS_ByteString* outPassword);

	//************************************
	// Function: GetTrailer
	// Param[in]: parser			The PDF file parser.
	// Return:   The trailer dictionary.
	// Remarks:	 Gets the trailer dictionary.
	// Notes:
	//************************************
	static FPD_Object		GetTrailer(FPD_Parser parser);

	//************************************
	// Function: GetLastXRefOffset
	// Param[in]: parser			The PDF file parser.
	// Return:   The bytes of the xref offset.
	// Remarks:	 Gets the offset of last xref.
	// Notes:
	//************************************
	static FS_DWORD			GetLastXRefOffset(FPD_Parser parser);

	//************************************
	// Function: GetDocument
	// Param[in]: parser			The PDF file parser.
	// Return:   The new empty document.
	// Remarks:	 Gets the <a>FPD_Document</a> object which associate with a PDF file.
	// Notes:
	//************************************
	static FPD_Document		GetDocument(FPD_Parser parser);

	//************************************
	// Function: CountOtherTrailers
	// Param[in]: parser			The PDF file parser.
	// Return:   The total number of the trailers in a PDF file.
	// Remarks:	 Gets the total number of the trailers in a PDF file.
	// Notes:
	//************************************
	static FS_INT32			CountOtherTrailers(FPD_Parser parser);

	//************************************
	// Function: GetOtherTrailerByIndex
	// Param[in]: parser			The PDF file parser.
	// Param[in]: index				The index of trailer which will be obtained, the range is 0 to <a>FPDParserCountOtherTrailers</a>()-1.
	// Return:   The specified trailer dictionary.
	// Remarks:	 Gets the specified trailer dictionary.
	// Notes:
	//************************************
	static FPD_Object		GetOtherTrailerByIndex(FPD_Parser parser, FS_INT32 index);

	//************************************
	// Function: GetRootObjNum
	// Param[in]:	parser			The PDF file parser.
	// Return:   The object number of file root(catalog) dictionary.
	// Remarks:	 Gets the object number of file catalog dictionary.
	// Notes:
	//************************************
	static FS_DWORD			GetRootObjNum(FPD_Parser parser);

	//************************************
	// Function: GetInfoObjNum
	// Param[in]:	parser			The PDF file parser.
	// Return:   The object number indicates the file information dictionary.
	// Remarks:	 Gets the object number of the file information dictionary.
	// Notes:
	//************************************
	static FS_DWORD			GetInfoObjNum(FPD_Parser parser);

	//************************************
	// Function: GetIDArray
	// Param[in]:	parser			The PDF file parser.
	// Return:   A PDF array object which contain the IDs of a PDF file.
	// Remarks:	 Gets the ID array in a PDF file.
	// Notes:
	//************************************
	static FPD_Object		GetIDArray(FPD_Parser parser);

	//************************************
	// Function: GetEncryptDict
	// Param[in]:	parser			The PDF file parser.
	// Return:   The encrypt dictionary object.
	// Remarks:	 Gets the encrypt dictionary which contain encrypt information.
	// Notes:
	//************************************
	static FPD_Object		GetEncryptDict(FPD_Parser parser);

	//************************************
	// Function: ParseIndirectObject
	// Param[in]: parser			The PDF file parser.
	// Param[in]: objList			The <a>FPD_Document</a> object which contains all indirect objects.
	// Param[in]: objnum			The object number.
	// Param[in]: pContext			The parse context. See <a>FPD_PARSE_CONTEXT</a>.
	// Return:   A PDF object.
	// Remarks:	 Parses the indirect objects.
	// Notes:
	//************************************
	static FPD_Object		ParseIndirectObject(FPD_Parser parser, FPD_Document objList, FS_DWORD objnum, FPD_PARSE_CONTEXT* pContext);

	//************************************
	// Function: GetLastObjNum
	// Param[in]:	parser			The PDF file parser.
	// Return:   The object number of the last object in a PDF file.
	// Remarks:	 Gets the lastest object number.
	// Notes:
	//************************************
	static FS_DWORD			GetLastObjNum(FPD_Parser parser);
	
	//************************************
	// Function: IsFormStream
	// Param[in]: parser			The PDF file parser.
	// Param[in]: objnum			The stream object number.
	// Param[out]: bForm			It receive whether it's a form stream or not.
	// Return:   Non-zero means determined, otherwise unknown.
	// Remarks:	 Checks if an indirect object is a form stream or not, without actually loading the object.
	// Notes:
	//************************************
	static FS_BOOL			IsFormStream(FPD_Parser parser, FS_DWORD objnum, FS_BOOL* bForm);

	//************************************
	// Function: ReloadFileStream
	// Param[in]: parser			The PDF file parser.
	// Param[in]: stream			The stream object which content stream will be reload.
	// Return:   <a>TRUE</a> for success, otherwise <a>FALSE</a>.
	// Remarks:	 Reloads stream content of a specified stream object.
	// Notes:
	//************************************
	static FS_BOOL			ReloadFileStream(FPD_Parser parser, FPD_Object stream);

	//************************************
	// Function: DeleteIndirectObject
	// Param[in]: parser			The PDF file parser.
	// Param[in]: objnum			The indirect object number to be deleted.
	// Return:   void
	// Remarks:	 Deletes a indirect object form a file.
	// Notes:
	//************************************
	static void				DeleteIndirectObject(FPD_Parser parser, FS_DWORD objnum);

	//************************************
	// Function: GetLengthOfVersions
	// Param[in]: parser			The PDF file parser.
	// Param[in]: arrayLengths		A DWORD array to receive the length of versions.
	// Return:   void
	// Remarks:	 Gets the version's length of the file.
	// Notes:
	//************************************
	static void				GetLengthOfVersions(FPD_Parser parser, FS_DWordArray arrayLengths);
	
	//************************************
	// Function: GetObjectOffset
	// Param[in]: parser			The PDF file parser.
	// Param[in]: objnum			The indirect object number.
	// Return:   The offset of the indirect object. For objects stored in object stream, this is the 
	// offset of the object stream.
	// Remarks:	 Gets offset of indirect object.
	// Notes:
	//************************************
	static FS_DWORD			GetObjectOffset(FPD_Parser parser, FS_DWORD objnum);

	//************************************
	// Function: GetObjectSize
	// Param[in]: parser			The PDF file parser.
	// Param[in]: objnum			The indirect object number.
	// Return:   The data size, in bytes, of the indirect object. For objects stored in object stream, this is the 
	// data size of the object stream.
	// Remarks:	 Gets data size of indirect object.
	// Notes:
	//************************************
	static FS_DWORD			GetObjectSize(FPD_Parser parser, FS_DWORD objnum);

	//************************************
	// Function: GetObjectVersion
	// Param[in]: parser			The PDF file parser.
	// Param[in]: objnum			The indirect object number.
	// Return:   The generation number of the indirect object.
	// Remarks:	 Gets the generation number of indirect object.
	// Notes:
	//************************************
	static int				GetObjectVersion(FPD_Parser parser, FS_DWORD objnum);

	//************************************
	// Function: GetIndirectBinary
	// Param[in]:	parser			The PDF file parser.
	// Param[in]: objnum			The indirect object number.
	// Param[in]: buffer			A binary buffer to receive bytes.
	// Return:   void
	// Remarks:	 For faster file updating, we can get the binary form of an indirect object, then
	// directly output to destination file. In this case we must call the following
	// function to get the binary buffer.
	// Notes: This function can't be used for any updated PDF file.
	//************************************
	static void				GetIndirectBinary(FPD_Parser parser, FS_DWORD objnum, FS_BinaryBuf buffer);

	//************************************
	// Function: ParseStreamPos
	// Param[in]: parser			The PDF file parser.
	// Param[in]: objnum			The indirect object number.
	// Param[out]: dict_start		Start position of the stream's dictionary.
	// Param[out]: dict_end			End position of the stream's dictionary.
	// Param[out]: data_start		Start position of the stream's data.
	// Param[out]: data_end			End position of the stream's data.
	// Return:   Non-zero means parse successfully, otherwise not.
	// Remarks:	 Gets position information for a stream:<br>
	// <ul>
	// <li>Start position (just before "<<") and end position (just after ">>") of the stream's dictionary</li>
	// <li>Start position (first byte) and end position (just after the last byte) of the stream's data</li>
	// </ul>
	// Notes:
	//************************************
	static FS_BOOL			ParseStreamPos(FPD_Parser parser, 
												FS_DWORD objnum, 
												FS_DWORD* dict_start, 
												FS_DWORD* dict_end,
												FS_DWORD* data_start, 
												FS_DWORD* data_end
												);
	
	//************************************
	// Function: ParseIndirectObjectsAtRange
	// Param[in]: parser			The PDF file parser.
	// Param[in]: objNum			The indirect object number.
	// Param[in]: objPos			The indirect object's start position.
	// Param[in]: dwPos				The start position.
	// Param[in]: dwLen				The length will be parsed.
	// Param[in]: context			The parse context.
	// Return:   Non_zero means parse successfully, otherwise not.
	// Remarks:	 Gets the indirect objects in specify byte range.
	// Notes: This function is bitwise search so very slow.
	//************************************
	static FS_BOOL				ParseIndirectObjectsAtRange(FPD_Parser parser,
															FS_DWordArray objNum, 
															FS_DWordArray objPos, 
															FS_DWORD dwPos, 
															FS_DWORD dwLen, 
															FPD_PARSE_CONTEXT* context
															);

	//************************************
	// Function: GetFileStreamOption
	// Param[in]: parser			The PDF file parser.
	// Return:   The new empty document.
	// Remarks:	 Get the file stream option.
	// <brief>Loading stream content into memory will improve performance for frequent access,
	// however, it will also consume a lot of memory space.
	// Therefore, we provide an option to leave stream content on file system, and read them
	// whenever we need them. If may reduce the performance a little bit, but greatly reduce
	// the memory consumption, especially when the file is big. 
	// Notes:
	//************************************
	static FS_BOOL				GetFileStreamOption(FPD_Parser parser);

	//************************************
	// Function: SetFileStreamOption
	// Param[in]: parser			The PDF file parser.
	// Param[in]: b					A flag indicates whether the stream is a file stream.
	// Return:   void
	// Remarks:	 Sets the file stream option.
	// Notes:
	//************************************
	static void					SetFileStreamOption(FPD_Parser parser, FS_BOOL b);

	//************************************
	// Function: GetFileAccess
	// Param[in]: parser			The PDF file parser.
	// Return:   A file access interface handler.
	// Remarks:	 Gets the stream access interface.
	// Notes:
	//************************************
	static FS_FileReadHandler		GetFileAccess(FPD_Parser parser);

	//************************************
	// Function: GetFileVersion
	// Param[in]: parser			The PDF file parser.
	// Return:   The new empty document.
	// Remarks:	 Gets the file version. File version: 14 for 1.4, 15 for 1.5, ... 
	// Notes:
	//************************************
	static FS_INT32					GetFileVersion(FPD_Parser parser);

	//************************************
	// Function: IsXRefStream
	// Param[in]: parser			The PDF file parser.
	// Return:   <a>TRUE</a> for xref stream, otherwise <a>FALSE</a>.
	// Remarks:	 Tests whether cross reference stream is used. 
	// Notes:
	//************************************
	static FS_BOOL				IsXRefStream(FPD_Parser parser);

	//************************************
	// Function: ParseIndirectObjectAt
	// Param[in]: parser			The PDF file parser.
	// Param[in]: objList			The <a>FPD_Document</a> object that contain the indirect objects.
	// Param[in]: pos				The position specified the indirect object.
	// Param[in]: objnum			The indirect object number.
	// Param[in]: pContext			The parse context.
	// Return:   A PDF object.
	// Remarks:	 Parses an indirect object specified by object position.
	// Notes:
	//************************************
	static FPD_Object			ParseIndirectObjectAt(FPD_Parser parser, 
														FPD_Document objList, 
														FS_DWORD pos, 
														FS_DWORD objnum, 
														FPD_PARSE_CONTEXT* pContext
														);

	//************************************
	// Function: StartAsynParse
	// Param[in]: parser			The PDF file parser.
	// Param[in]: pFile				The stream access interface handler.
	// Param[in]: bReParse			A flag indicates whether we will do reparsing.
	// Return:   The status of PDF parsing.
	// Remarks:	 Asynchronous parsing a custom file.
	// Notes:
	//************************************
	static FS_DWORD			StartAsynParse(FPD_Parser parser, FS_FileReadHandler pFile, FS_BOOL bReParse);

	//************************************
	// Function: GetFirstPageNo
	// Param[in]: parser			The PDF file parser.
	// Return:   The index of first page.
	// Remarks:	 Get the first page number.
	// Notes:
	//************************************
	static FS_DWORD			GetFirstPageNo(FPD_Parser parser);

	//************************************
	// Function: GetSecurityPermissions
	// Param[in]: parser			The PDF file parser.
	// Return:   The permission settings of the document.
	// Remarks:	 Gets permission settings of the document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_DWORD	GetSecurityPermissions(FPD_Parser parser);

	//************************************
	// Function: IsSecurityOwner
	// Param[in]: parser			The PDF file parser.
	// Return:   Whether the current user is owner of the document.
	// Remarks:	 Checks whether the current user is owner of the document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL IsSecurityOwner(FPD_Parser parser);

	//************************************
	// Function: GetSecurityCryptInfo
	// Param[in]: parser			The PDF file parser.
	// Param[out]: outCipher		Receives cipher identifier (FPD_CIPHER_NONE, FPD_CIPHER_RC4 or FPD_CIPHER_AES).
	// Param[out]: outBuffer		Receives a pointer to the key buffer.
	// Param[out]: outKeylen		Receives number of bytes in the key.
	// Return:   <a>TRUE</a> if successful. <a>FALSE</a> if no standard key info is provided or failure.
	// Remarks:	 Gets encryption information including standard algorithm and key.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL GetSecurityCryptInfo(FPD_Parser parser, FS_INT32* outCipher, FS_LPCBYTE* outBuffer, FS_INT32* outKeylen);
	
	//************************************
	// Function: IsMetadataEncryptedBySecurity
	// Param[in]: parser			The PDF file parser.
	// Return:   Whether document metadata needs to be encrypted.
	// Remarks:	 Checks whether document metadata needs to be encrypted.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL IsMetadataEncryptedBySecurity(FPD_Parser parser);
	
	//************************************
	// Function: GetStandardSecurityUserPassword
	// Param[in]: parser			The PDF file parser.
	// Param[in]: owner_pass		The owner password pointer.
	// Param[in]: pass_size			The length of the owner password.
	// Param[out]: outUserPsswrd	Receives number of bytes in the key.
	// Return:   It receives the correspond user password for this standard security handler.
	// Remarks:	 Gets user password from an owner password.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void GetStandardSecurityUserPassword(FPD_Parser parser, FS_LPCBYTE owner_pass, FS_DWORD pass_size, FS_ByteString* outUserPsswrd);
	
	//************************************
	// Function: GetStandardSecurityVersion
	// Param[in]: parser			The PDF file parser.
	// Return:   The version of standard security.
	// Remarks:	 Gets the version of standard security.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_INT32 GetStandardSecurityVersion(FPD_Parser parser);

	//************************************
	// Function: GetStandardSecurityRevision
	// Param[in]: parser			The PDF file parser.
	// Return:   The revision of standard security.
	// Remarks:	 Gets the revision of standard security.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_INT32 GetStandardSecurityRevision(FPD_Parser parser);

	//************************************
	// Function: CheckStandardSecurityPassword
	// Param[in]: parser			The PDF file parser.
	// Param[in]: password			The input password pointer.
	// Param[in]: pass_size			The size of the password.
	// Param[in]: bOwner			Whether check the owner password.
	// Param[out]: key				Pointer to key buffer to receive the encryption key. NULL for don't calculate the key.
	// Return:	<a>FALSE</a> for invalid password, <a>TRUE</a> for password verified.
	// Remarks:	Checks whether the password is verified successfully.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL CheckStandardSecurityPassword(FPD_Parser parser, FS_LPCBYTE password, FS_DWORD pass_size, FS_BOOL bOwner, FS_LPBYTE* key);

	//************************************
	// Function: CheckEmbeddedSecurity
	// Param[in]: parser	The PDF file parser.
	// Param[in]: name		The name of the crypt filter that should be used by default when encrypting embedded file streams.
	// Return:	The returned value can refer to <a>FPDParseErrCodes</a>.
	// Remarks:	Checks the access to the encrypted embedded file stream.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1
	//************************************
	static FS_DWORD	CheckEmbeddedSecurity(FPD_Parser parser, FS_LPCSTR name);

	//************************************
	// Function: LoadAttachmentStream
	// Param[in]: parser		The PDF file parser.
	// Param[in]: objnum		The object number of the attachment stream.
	// Param[out]: outStremObj	It receives the pointer to the loaded attachment stream object.
	// Return:	The returned value can refer to <a>FPDParseErrCodes</a>.
	// Remarks:	Loads the attachment stream.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1
	//************************************
	static FS_DWORD LoadAttachmentStream(FPD_Parser parser, FS_DWORD objnum, FPD_Object* outStremObj);	

    //************************************
    // Function: SetUnicodePassword
    // Param[in]: parser			The PDF file parser.
    // Param[in]: password			The input unicode password string.
    // Return:   Zero means the unicode password strings include invalid characters.
    // Remarks:	 Set the unicode password of standard encryption for the parser.
    // Notes: Only the PDF2.0 supports for the Unicode-based passwords.
    //************************************
    static FS_BOOL				SetUnicodePassword(FPD_Parser parser,  const FS_WCHAR* password);

    //************************************
    // Function: GetUnicodePassword
    // Param[in]: parser			The PDF file parser.
    // Param[out]: outPassword		A buffer to receive the Unicode-based password string.
    // Return:   void
    // Remarks:	 Get the Unicode-based passwords.
    // Notes: Only the PDF2.0 supports for the Unicode-based passwords.
    //************************************
    static void					GetUnicodePassword(FPD_Parser parser, FS_WideString* outPassword);

    //************************************
    // Function: CheckPassword
    // Param[in]: parser			The PDF file parser.
    // Param[in]: password			The input password pointer.
    // Param[in]: pass_size			The size of the password.
    // Param[in]: bOwner			Whether check the owner password
    // Param[out]: key				Pointer to key buffer to receive the encryption key. NULL for don't calculate the key.
    // Return:   FALSE for invalid password, TRUE for password verified.
    // Remarks:	 Check whether the password is verified successfully.
    // Notes: Only the PDF2.0 supports for the Unicode-based CheckPassword.
    //************************************
    static	FS_INT32			CheckPassword(FPD_Parser parser, FS_LPCWSTR password, FS_DWORD pass_size, FS_BOOL bOwner, FS_LPBYTE* key);

	//************************************
	// Function: SetPassword2
	// Param[in]: parser			The PDF file parser.
	// Param[in]: password			The input password string.
	// Return:   void
	// Remarks:	 Sets the password of standard encryption for the parser.
	// Notes:
	//************************************
	static void				SetPassword2(FPD_Parser parser, const FS_ByteString password);

	//************************************
	// Function: SetPassword3
	// Param[in]: parser			The PDF file parser.
	// Param[in]: password			The input password string.
	// Return:   void
	// Remarks:	 Sets the password of standard encryption for the parser.
	// Notes:
	//************************************
	static void				SetPassword3(FPD_Parser parser, const FS_WideString  password);

	//************************************
	// Function: CheckHasCryptoHandler
	// Param[in]: parser			The PDF file parser.	
	// Return:   FS_BOOL            TRUE means encrypt handler is not NULL.
	// Remarks:	 Check if has encrypt handler.
	// Notes:
	//************************************
	static FS_BOOL          CheckHasCryptoHandler(FPD_Parser parser);

   //************************************
   // Function: CheckPassword
   // Param[in]: parser			The PDF file parser.
   // Param[in]: password		The input password pointer.
   // Param[in]: pass_size		The size of the password.
   // Param[in]: bOwner			Whether check the owner password
   // Param[out]: key			Pointer to key buffer to receive the encryption key. NULL for don't calculate the key.
   // Return:   FALSE for invalid password, TRUE for password verified.
   // Remarks:	 Check whether the password is verified successfully.
   // Notes: Only the PDF2.0 supports for the Unicode-based CheckPassword.
   //************************************
	static	FS_INT32			CheckPassword2(FPD_Parser parser, FS_LPBYTE password, FS_DWORD pass_size, FS_BOOL bOwner, FS_LPBYTE* key);
	
	//************************************
	// Function: IsParsingLinearized
	// Param[in]: parser			The PDF file parser.	
	// Return:   FS_BOOLEAN         Non_zero means is a Linearized PDF, otherwise not.
	// Remarks:	Whether the parsing file is a Linearized PDF.
	// Notes: 
	//************************************
	static	FS_BOOLEAN			IsParsingLinearized(FPD_Parser parser);
	
	 //************************************
	 // Function: HasRebuildXRef
	 // Param[in]: parser			The PDF file parser.	
	 // Return:   FS_BOOLEAN        true means rebuilded, otherwise false.
	 // Remarks:	Whether the cross-reference information has been rebuild.
	 // Notes: 
	 //************************************
	static	FS_BOOLEAN				HasRebuildXRef(FPD_Parser parser);

	//************************************
	// Function: GetSizeAnalysis
	// Param[in]: parser			The PDF file parser.	
	// Return:   FPD_SizeAnalysis
	// Remarks:	Get FPD_SizeAnalysis object.
	// Notes: 
	//************************************
	static FPD_SizeAnalysis   GetSizeAnalysis(FPD_Parser parser);

	//************************************
	// Function: EnableSizeAnalysis
	// Param[in]: parser			The PDF file parser.	
	// Param[in]: bEnable			Whether enable size analysis.	
	// Return:   void
	// Remarks:	Set whether enable size analysis.	
	// Notes: 
	//************************************
	static void				EnableSizeAnalysis(FPD_Parser parser, FS_BOOLEAN bEnable);
	
	//************************************
	// Function: SetObjStmCacheLimitSize
    // Param[in]: parser			The PDF file parser.	
	// Param[in]: dwLimitSize		The cache limit size.
	// Return:   void
	// Remarks: Set Object Stream Cache limit size.	
	// Notes: 
	//************************************
	static void				SetObjStmCacheLimitSize(FPD_Parser parser, FS_DWORD dwLimitSize);
	
	 //************************************
	 // Function: Continue
	 // Param[in]: parser			The PDF file parser.	
	 // Param[in]: dwLimitSize		The pause interface.
	 // Return:   void
	 // Remarks: The status of PDF parsing.
	 // Notes: 
	 //************************************
	static FS_INT32			Continue(FPD_Parser parser, FS_PauseHandler pPause);
	
	//************************************
	// Function: SetRecipient
	// Param[in]: parser			The PDF file parser.	
	// Param[in]: bsRecipient		The input recipient content.
	// Return:   void
	// Remarks: Set the recipient content.
	// Notes: 
	//************************************
	static void				SetRecipient(FPD_Parser parser, FS_LPCSTR bsRecipient);

	//************************************
	// Function: CheckStandardSecurityPassword2
	// Param[in]: parser			The PDF file parser.
	// Param[in]: password			The input password pointer.
	// Param[in]: pass_size			The size of the password.
	// Param[in]: bOwner			Whether check the owner password.
	// Param[out]: key				Pointer to key buffer to receive the encryption key. NULL for don't calculate the key.
	// Return:	<a>FALSE</a> for invalid password, <a>TRUE</a> for password verified.
	// Remarks:	Checks whether the password is verified successfully.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	//************************************
	static FS_BOOL CheckStandardSecurityPassword2(FPD_Parser parser, FS_LPCWSTR password, FS_DWORD pass_size, FS_BOOL bOwner, FS_LPBYTE* key);
};

class CFPD_StandardCryptoHandler_V14
{
public:
    static FPD_StandardCryptoHandler New();
    static void Destroy(FPD_StandardCryptoHandler handler);
    static FS_BOOL		Init(FPD_StandardCryptoHandler handler,FS_INT32 cipher, FS_LPCBYTE key, FS_INT32 keylen);
    static FS_BOOL		InitByDic(FPD_StandardCryptoHandler handler, FPD_Object pEncryptDict, FPD_Parser parser);
    static FS_DWORD  	DecryptGetSize(FPD_StandardCryptoHandler handler, FS_DWORD src_size);
    static FS_LPVOID	DecryptStart(FPD_StandardCryptoHandler handler, FS_DWORD objnum, FS_DWORD gennum);
    static FS_BOOL		DecryptStream(FPD_StandardCryptoHandler handler, FS_LPVOID context, FS_LPCBYTE src_buf, FS_DWORD src_size, FS_BinaryBuf& dest_buf);
    static FS_BOOL		DecryptFinish(FPD_StandardCryptoHandler handler, FS_LPVOID context, FS_BinaryBuf& dest_buf);
    static FS_DWORD 	EncryptGetSize(FPD_StandardCryptoHandler handler, FS_DWORD objnum, FS_DWORD gennum, FS_LPCBYTE src_buf, FS_DWORD src_size);
    static FS_BOOL		EncryptContent(FPD_StandardCryptoHandler handler, FS_DWORD objnum, FS_DWORD gennum, FS_LPCBYTE src_buf, FS_DWORD src_size,	FS_LPBYTE dest_buf, FS_DWORD& dest_size);
    static FS_LPVOID    Clone(FPD_StandardCryptoHandler handler);
};

class CFPD_FipsStandardCryptoHandler_V14
{
public:
	static FPD_FipsStandardCryptoHandler New();
	static void Destroy(FPD_FipsStandardCryptoHandler handler);
    static FS_BOOL	Init(FPD_FipsStandardCryptoHandler handler,FS_INT32 cipher, FS_LPCBYTE key, FS_INT32 keylen);
	static FS_BOOL	Init2(FPD_FipsStandardCryptoHandler handler,FPD_Object pEncryptDict, FPD_Parser parser);
};

class CFPD_SimpleParser_V14
{
public:	
	 //************************************
	 // Function: New
	 // Param[in]: pData   The input buffer.
	 // Param[in]: dwSize  The size in bytes of the buffer.
	 // Return: FPD_SimpleParser   The newly created Simple parser.
	 // Remarks:  Construct a simple parser from a buffer. The buffer must retain valid until parsing finished.
	 // use <a>FPDParserGetDocument</a>() to get a <a>FPD_Document</a> object.
	 // Notes:
	 //************************************
	static FPD_SimpleParser New(FS_LPCBYTE pData, FS_DWORD dwSize);
	
	 //************************************
	 // Function: New2
	 // Param[in]: str   The input string.
	 // Return: FPD_SimpleParser   The newly created Simple parser.
	 // Remarks: Construct a simple parser from string. The string must retain valid until parsing finished.
	 // use <a>FPDParserGetDocument</a>() to get a <a>FPD_Document</a> object.
	 // Notes:
	 //************************************
	static FPD_SimpleParser  New2(FS_LPCBYTE str);

	//************************************
	 // Function: Destroy
	 // Param[in]: parser   The input parser obj.
	 // Return: void
	 // Remarks: Destroy the parser obj.
	 // Notes:
	 //************************************
	static void  Destroy(FPD_SimpleParser parser);

	 //************************************
	 // Function: GetWord
	 // Param[in]: parser   The input parser obj.
	 // Param[out]: word    The input string.
	 // Return: void   
	 // Remarks:  * Get next word. NOTE: the word will be returned in its original form, unescaped, un-decoded.
	 //For example, it will recognize "(hello(there)! :\))" as a legimate PDF string constant, however it
	 //won't return the value "hello(there)! :)", instead, the original form "(hello(there)!:\))" is returned.
	 //Likewise, names are always returned with the preceding "/".
	 // Notes:
	 //************************************
	static void		GetWord(FPD_SimpleParser parser, FS_ByteString* word);
	
	 //************************************
	 // Function: SearchToken
	 // Param[in]: parser   The input parser obj.
	 // Param[out]: token   The token to be searched.
	 // Return: FS_BOOLEAN    return Non-zero means found a token, otherwise not.
	 // Remarks: Search a token from the current position, when stopped, the current position will be immediately
	 //after the found token.If token not found, the parser will stop at end of the buffer, and return false.	
	 // Notes:
	 //************************************
	static FS_BOOLEAN		SearchToken(FPD_SimpleParser parser, FS_LPCBYTE token);

	 //************************************
	  // Function: SkipWord
	  // Param[in]: parser   The input parser obj.
	  // Param[out]: token   The token to be skipped.
	  // Return: FS_BOOLEAN    return Non-zero means found a token, otherwise not.
	  // Remarks: Search a word from the current position. The parser will stop immediately after the found word.
	  //If not found, the parser will stop at end of the buffer, and return false.	  
	  // Notes:
	  //************************************
	static FS_BOOLEAN				SkipWord(FPD_SimpleParser parser, FS_LPCBYTE token);
	
	 //************************************
	 // Function: FindTagPair	
	 // Param[in]: parser   The input parser obj.
	 //param[in] start_token	The start token to be found.
	 //param[in] end_token		The end token to be found.
	 //param[out] start_pos	It receives the position after the start token.
	 //param[out] end_pos		It receives the position before the end token.
	 // Return: FS_BOOLEAN    Non-zero means find one, otherwise not.
	 // Remarks: Find a start token and an end token (compared word by word), get the position after the start token,
	 // and position before the end token.
	 // Notes:
	 //************************************
	 static FS_BOOLEAN				FindTagPair(FPD_SimpleParser parser, FS_LPCBYTE start_token, FS_LPCBYTE end_token,
		FS_DWORD* start_pos, FS_DWORD* end_pos);
	
	//************************************
	// Function: FindTagParam	
	// Param[in]: parser   The input parser obj.
	//param[in] token			The token to be searched.
	//param[in] nParams		Zero-based index of the parameters for the token.
	// Return: FS_BOOLEAN   Non-zero means find successfully, otherwise not.
	// Remarks: Search from the current position for a parameter of a tag. This is often used for parsing simple PostScript style
	//texts.For example, if you have a buffer like "/F1 12.5 Tf ...", and you search for param #1 of "Tf" token,
	//the parser will first search for token "Tf", then go back one word, and stop at the parameter value "12.5".
	// Notes:
	//************************************
	 static FS_BOOLEAN				FindTagParam(FPD_SimpleParser parser, FS_LPCBYTE token, FS_INT32 nParams);
	
	//************************************
	// Function: GetPos	
	// Param[in]: parser   The input parser obj.	
	// Return: FS_DWORD   
	// Remarks:Get current position of the parser.
	// Notes:
	//************************************
	 static FS_DWORD			GetPos(FPD_SimpleParser parser);

	 //************************************
	// Function: SetPos	
	// Param[in]: parser   The input parser obj.	
	// Param[in]: pos      The postion.
	// Return: void   
	// Remarks:Set current position.
	// Notes:
	//************************************
	 static  void				SetPos(FPD_SimpleParser parser, FS_DWORD pos);
};

class CFPD_NumberTree_V16
{
public:
	//************************************
	// Function: CreteNumberTree
	// Param[in]: pParent    The dictionary which the number tree will be set to, like "Catalog", "StructTreeRoot" dictionary, etc.
	// Param[in]: sCategory  The category key name for number tree, like "PageLabels", "ParentTree", etc.
	// Return:   FPD_NumberTree
	// Remarks:	 Construct a number tree object from the parent dictionary.
	// Notes:
	//************************************
	static FPD_NumberTree CreteNumberTree(FPD_Object pParent, FS_LPCSTR sCategory);

	//************************************
	// Function: DeleteNumberTree
	// Param[in]: numberTree    The input FPD_NumberTree.
	// Return:   void
	// Remarks:	 Delete FPD_NumberTree.
	// Notes:
	//************************************
	static void  DeleteNumberTree(FPD_NumberTree numberTree);

	//************************************
	// Function: LookupValue
	// Param[in]: numberTree    The input FPD_NumberTree.
	// Param[in]: num           The input number.
	// Return:   FPD_Object
	// Remarks:	 Lookup a PDF object identified by number.
	// Notes:
	//************************************
	static FPD_Object		LookupValue(FPD_NumberTree numberTree, FS_INT32 num);

	//************************************
	// Function: SetValue
	// Param[in]: numberTree    The input FPD_NumberTree.
	// Param[in]: pDoc          The input FPD_Document.
	// Param[in]: num           The input number.
	// Param[in]: pValue        The input entry value.
	// Return:   FS_BOOLEAN     The value nonzero if successful, otherwise 0.
	// Remarks:	 Set the entry value of specified PDF number tree node that contains specified number.
	// Notes:
	//************************************
	static FS_BOOLEAN		SetValue(FPD_NumberTree numberTree, FPD_Document pDoc, FS_INT32 num, FPD_Object pValue);
	
	//************************************
	// Function: Remove
	// Param[in]: numberTree    The input FPD_NumberTree.
	// Param[in]: num           The input number.
	// Return:   FS_BOOLEAN     The value nonzero if successful, otherwise 0.
	// Remarks:	 Remove the number form the number tree.
	// Notes:
	//************************************
	static FS_BOOLEAN		Remove(FPD_NumberTree numberTree, FS_INT32 num);
};

class CFPD_SizeAnalysis_V16
{
public:
	//************************************
	// Function: GetObjectSize
	// Param[in]: analysis		The PDF file parser.
	// Param[in]: pObj			The input object.
	// Return:  FS_DWORD
	// Remarks:	Get the size of the object.
	// Notes: 
	//************************************
	static FS_DWORD		GetObjectSize(FPD_SizeAnalysis analysis, FPD_Object pObj);

	//************************************
	// Function: GetContentSize
	// Param[in]: analysis			The PDF file parser.
	// Param[in]: pObj			    The input object.
	// Return:   FS_DWORD
	// Remarks:	Get the content size of the object.
	// Notes: 
	//************************************
	static FS_DWORD		GetContentSize(FPD_SizeAnalysis analysis, FPD_Object pObj);

	//************************************
	// Function: GetXRefSize
	// Param[in]: analysis			The PDF file parser.
	// Return:   FS_DWORD
	// Remarks:	Get the reference size of the object.
	// Notes: 
	//************************************
	static FS_DWORD		GetXRefSize(FPD_SizeAnalysis analysis);

	//************************************
	// Function: Clear
	// Param[in]: analysis			The PDF file parser.
	// Return:   void
	// Remarks:	Clear the data of the analysis.
	// Notes: 
	//************************************
	static void			Clear(FPD_SizeAnalysis analysis);
};

class CFPD_SyntaxParser_V17
{
public:
	//************************************
	// Function: New	
	// Return:   FPD_SyntaxParser
	// Remarks:	Create FPD_SyntaxParser object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static FPD_SyntaxParser New();

	//************************************
	// Function: Destroy	
	// Param[in]: parser			The input FPD_SyntaxParser object.
	// Return:   void
	// Remarks:	Destroy FPD_SyntaxParser object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static void Destroy(FPD_SyntaxParser parser);
	
	//************************************
	// Function: InitParser	
	// Param[in]: parser			The input FPD_SyntaxParser object.
	// Param[in]: pFileAccess		The stream access interface.
	// Param[in]: HeaderOffset		The PDF header offset in the stream.
	// Return:   void
	// Remarks: Init he syntax parser.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static void	InitParser(FPD_SyntaxParser parser, FS_FileReadHandler pFileAccess, FS_DWORD HeaderOffset);
	
	 //************************************
	 // Function: GetObject	
	 // Param[in]: parser			The input FPD_SyntaxParser object.
	 // Param[in]: pObjList		An indirect object list.
	 // Param[in]: objnum		    The object number.
	 // Param[in]: gennum			The object generation number.
	 // Param[in]: level		    The input level.
	 // Param[in]: pContext		    The parser context.
	 // Param[in]: bDecrypt		    Whether need to decrypt.
	 // Return:   void
	 // Remarks: Init he syntax parser.
	 // Notes: 
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	 //************************************
	static FPD_Object GetObject(FPD_SyntaxParser parser, FPD_Document pObjList, FS_DWORD objnum, FS_DWORD gennum, FS_INT32 level,  FPD_PARSE_CONTEXT* pContext, FS_BOOLEAN bDecrypt);
};

#ifdef __cplusplus
};
#endif

#endif

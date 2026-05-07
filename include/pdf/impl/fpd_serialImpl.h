#ifndef FPD_SERIALIMPL_H
#define FPD_SERIALIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../fs_basicExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "../fpd_pageExpT.h"
#endif

#ifndef FPD_PAGEOBJEXPT_H
#include "../fpd_pageobjExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_SERIALEXPT_H
#include "../fpd_serialExpT.h"
#endif

/*@}*/ 



#ifdef __cplusplus
extern "C"{
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*                           CFPD_ObjArchiveSaver_V1                              */
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_ObjArchiveSaver_V1
{
public:
	//************************************
	// Function: New
	// Return:   The PDF object archive saver.
	// Remarks:	 Creates a PDF object archive saver.
	// Notes:
	//************************************ 
	static FPD_ObjArchiveSaver New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: ar	The input PDF object archive saver.
	// Return:    void.
	// Remarks:	  Destroys the PDF object archive saver.
	// Notes:
	//************************************ 
	static void Destroy(FPD_ObjArchiveSaver ar);

	//************************************
	// Function:   SaveObject
	// Param[in]:  ar		Ref to output PDF object archive saver.
	// Param[in]:  pObj		The input PDF object.
	// Return:     void
	// Remarks:	   Overloads operator for serializing a PDF object.
	// Notes:
	//************************************ 
	static void SaveObject(FPD_ObjArchiveSaver ar, const FPD_Object pObj);

	//************************************
	// Function:  GetLength
	// Param[in]: ar	The input PDF object archive saver.
	// Return:    The length in bytes of the saved data.
	// Remarks:	  Gets the length of saved data.
	// Notes:
	//************************************ 
	static FS_INTPTR GetLength(FPD_ObjArchiveSaver ar);

	//************************************
	// Function:  GetBuffer
	// Param[in]: ar	The input PDF object archive saver.
	// Return:    The constant byte pointer to the saved data.
	// Remarks:	  Gets the constant byte pointer to the saved data.
	// Notes:
	//************************************ 
	static FS_LPCBYTE GetBuffer(FPD_ObjArchiveSaver ar);

	//************************************
	// Function:  SaveByte
	// Param[in]: ar	The input PDF object archive saver.
	// Param[in]: i		The input byte.
	// Return:    void
	// Remarks:	  Overloads operator for serializing a single byte.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void SaveByte(FPD_ObjArchiveSaver ar, FS_BYTE i);

	//************************************
	// Function:  SaveInteger
	// Param[in]: ar	The input PDF object archive saver.
	// Param[in]: i		The input integer.
	// Return:    void
	// Remarks:	  Overloads operator for serializing a integer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void SaveInteger(FPD_ObjArchiveSaver ar, FS_INT32 i);

	//************************************
	// Function:  SaveDWORD
	// Param[in]: ar	The input PDF object archive saver.
	// Param[in]: i		The input DWORD value.
	// Return:    void
	// Remarks:	  Overloads operator for serializing a DWORD value.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void SaveDWORD(FPD_ObjArchiveSaver ar, FS_DWORD i);

	//************************************
	// Function:  SaveFloat
	// Param[in]: ar	The input PDF object archive saver.
	// Param[in]: i		The input floating-point.
	// Return:    void
	// Remarks:	  Overloads operator for serializing a floating-point.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void SaveFloat(FPD_ObjArchiveSaver ar, FS_FLOAT i);

	//************************************
	// Function:  SaveByteString
	// Param[in]: ar	The input PDF object archive saver.
	// Param[in]: str	The input byte string.
	// Return:    void
	// Remarks:	  Overloads operator for serializing a byte string.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void SaveByteString(FPD_ObjArchiveSaver ar, FS_ByteString str);

	//************************************
	// Function:  SaveWideString
	// Param[in]: ar	The input PDF object archive saver.
	// Param[in]: wstr	The input wide string.
	// Return:    void
	// Remarks:	  Overloads operator for serializing a wide string.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void SaveWideString(FPD_ObjArchiveSaver ar, FS_WideString wstr);

	//************************************
	// Function:  SaveWideStringII
	// Param[in]: ar	The input PDF object archive saver.
	// Param[in]: wstr	The input wide string.
	// Return:    void
	// Remarks:	  Overloads operator for serializing a wide string.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void SaveWideStringII(FPD_ObjArchiveSaver ar, FS_LPCWSTR wstr);

	//************************************
	// Function:  Write
	// Param[in]: ar		The input PDF object archive saver.
	// Param[in]: pData		The pointer to a memory block.
	// Param[in]: dwSize	The size in bytes of the memory block.
	// Return:    void
	// Remarks:	  Overloads operator for serializing a memory block.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void Write(FPD_ObjArchiveSaver ar, void* pData, FS_DWORD dwSize);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*                           CFPD_ObjArchiveLoader_V1                              */
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_ObjArchiveLoader_V1
{
public:	
	//************************************
	// Function:  New
	// Param[in]: pData	The input memory block.
	// Param[in]: dwSize	The size of the input memory block.
	// Return:    The PDF object archive loader.
	// Remarks:	  Creates a PDF object archive loader.
	// Notes:
	//************************************ 
	static FPD_ObjArchiveLoader New(FS_LPCBYTE pData, FS_DWORD dwSize);

	//************************************
	// Function:  Destroy
	// Param[in]: ar	The input object archive loader.
	// Return:    void.
	// Remarks:	  Destroys the PDF object archive loader.
	// Notes:
	//************************************ 
	static void Destroy(FPD_ObjArchiveLoader ar);
	
	//************************************
	// Function:   LoadObject
	// Param[in]:  ar	Ref to the input object archive loader.
	// Param[out]: pObj	It receives the loaded PDF object.
	// Return:     void
	// Remarks:	   Loads an object from archive.
	// Notes:
	//************************************ 
	static void LoadObject(FPD_ObjArchiveLoader ar, FPD_Object* pObj);

	//************************************
	// Function:  IsEOF
	// Param[in]: ar	The input object archive loader.
	// Return:    non-zero means de-serializing to the end, otherwise not.
	// Remarks:	  Returns whether de-serializing to the end of the loading buffer.
	// Notes:
	//************************************ 
	static FS_BOOL IsEOF(FPD_ObjArchiveLoader ar);

	//************************************
	// Function:     Read
	// Param[in]:    ar	    The input object archive loader.
	// Param[in,out] pBuf	A memory block pointer to receive the data.
	// Param[in]     dwSize	The size in bytes of the memory block.
	// Return:       non-zero means successful, otherwise failed.
	// Remarks:	     De-serializes a memory block.
	// Notes:
	//************************************ 
	static FS_BOOL Read(FPD_ObjArchiveLoader ar, FS_LPVOID pBuf, FS_DWORD dwSize);

	//************************************
	// Function:   LoadByte
	// Param[in]:  ar	Ref to the input object archive loader.
	// Param[out]: i	It receives the byte value.
	// Return:     void
	// Remarks:	   Loads a byte value from archive.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void LoadByte(FPD_ObjArchiveLoader ar, FS_BYTE* i);

	//************************************
	// Function:   LoadInteger
	// Param[in]:  ar	Ref to the input object archive loader.
	// Param[out]: i	It receives the integer value.
	// Return:     void
	// Remarks:	   Loads a integer value from archive.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void LoadInteger(FPD_ObjArchiveLoader ar, FS_INT32* i);

	//************************************
	// Function:   LoadDWORD
	// Param[in]:  ar	Ref to the input object archive loader.
	// Param[out]: i	It receives the DWORD value.
	// Return:     void
	// Remarks:	   Loads a DWORD value from archive.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void LoadDWORD(FPD_ObjArchiveLoader ar, FS_DWORD* i);

	//************************************
	// Function:   LoadFloat
	// Param[in]:  ar	Ref to the input object archive loader.
	// Param[out]: i	It receives the float value.
	// Return:     void
	// Remarks:	   Loads a float value from archive.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void LoadFloat(FPD_ObjArchiveLoader ar, FS_FLOAT* i);

	//************************************
	// Function:   LoadByteString
	// Param[in]:  ar	Ref to the input object archive loader.
	// Param[out]: pStr	It receives the byte string value.
	// Return:     void
	// Remarks:	   Loads a byte string value from archive.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void LoadByteString(FPD_ObjArchiveLoader ar, FS_ByteString* pStr);

	//************************************
	// Function:   LoadWideString
	// Param[in]:  ar		Ref to the input object archive loader.
	// Param[out]: pwStr	It receives the wide string value.
	// Return:     void
	// Remarks:	   Loads a wide string value from archive.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void LoadWideString(FPD_ObjArchiveLoader ar, FS_WideString* pwStr);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*                           CFPD_PageArchiveSaver_V1                              */
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_PageArchiveSaver_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: pPageObjs	The input page object list.
	// Return:    The PDF page archive saver.
	// Remarks:	  Creates a PDF page archive saver.
	// Notes:
	//************************************ 
	static FPD_PageArchiveSaver New(FPD_Page pPageObjs);

	//************************************
	// Function:  Destroy
	// Param[in]: ar	The input page archive saver.
	// Return:    void.
	// Remarks:	  Destroys the PDF page archive saver.
	// Notes:
	//************************************ 
	static void Destroy(FPD_PageArchiveSaver ar);

	//************************************
	// Function:   SavePageObject
	// Param[in]:  ar	Ref to the output page archive saver.
	// Param[in]:  pObj	The input page object.
	// Return:     void
	// Remarks:	   Saves page object.
	// Notes:
	//************************************ 
	static void SavePageObject(FPD_PageArchiveSaver ar, FPD_PageObject pObj);

	//************************************
	// Function:   SaveClipPath
	// Param[in]:  ar	Ref to the output page archive saver.
	// Param[in]:  clip_path	The input clipping path.
	// Return:     void
	// Remarks:	   Saves clipping path.
	// Notes:
	//************************************ 
	static void SaveClipPath(FPD_PageArchiveSaver ar, FPD_ClipPath clip_path);

	//************************************
	// Function:   SaveGraphState
	// Param[in]:  ar	Ref to the output page archive saver.
	// Param[in]:  graph_state   The input graph state.
	// Return:     void
	// Remarks:	   Saves graph state.
	// Notes:
	//************************************ 
	static void SaveGraphState(FPD_PageArchiveSaver ar, FPD_GraphState graph_state);

	//************************************
	// Function:   SaveTextState
	// Param[in]:  ar	Ref to the output page archive saver.
	// Param[in]:  text_state	The input text state.
	// Return:     void
	// Remarks:	   Saves text state.
	// Notes:
	//************************************ 
	static void SaveTextState(FPD_PageArchiveSaver ar, FPD_TextState text_state);

	//************************************
	// Function:   SaveColorState
	// Param[in]:  ar	Ref to the output page archive saver.
	// Param[in]:  color_state	The input color state.
	// Return:     void
	// Remarks:	   Saves color state.
	// Notes:
	//************************************ 
	static void SaveColorState(FPD_PageArchiveSaver ar, FPD_ColorState color_state);

	//************************************
	// Function:   SaveGeneralState
	// Param[in]:  ar	Ref to the output page archive saver.
	// Param[in]:  general_state	The input general state.
	// Return:     void
	// Remarks:	   Saves general state.
	// Notes:
	//************************************ 
	static void SaveGeneralState(FPD_PageArchiveSaver ar, FPD_GeneralState general_state);

	//************************************
	// Function:  New2
	// Param[in]: pPageObjs	The input page object list.
	// Return:    The PDF page archive saver.
	// Remarks:	  Creates a PDF page archive saver.
	// Notes:
	//************************************ 
	static FPD_PageArchiveSaver New2(FPD_GraphicsObjects pPageObjs);
	
	 //************************************
	 // Function:  SetStream
	 // Param[in]: ar	Ref to the output page archive saver.
	 // Param[in]: pStream	    The stream to the saved data.
	 // Return:    void
	 // Remarks:	Set the attached stream.
	 // Notes:
	 //************************************ 
	static void          SetStream(FPD_PageArchiveSaver ar, FS_FileStream pStream);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*                           CFPD_PageArchiveLoader_V1                              */
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_PageArchiveLoader_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: pPageObjs	The current page/form.
	// Param[in]: pData	The input memory buffer.
	// Param[in]: dwSize	The size of the input buffer.
	// Return:    The PDF page archive loader.
	// Remarks:	  Constructs a loading archive.
	// Notes:
	//************************************ 
	static FPD_PageArchiveLoader New(FPD_Page pPageObjs, FS_LPCBYTE pData, FS_DWORD dwSize);

	//************************************
	// Function:  Destroy
	// Param[in]: ar	The input page archive loader.
	// Return:    void.
	// Remarks:	  Destroys the PDF page archive loader.
	// Notes:
	//************************************ 
	static void Destroy(FPD_PageArchiveLoader ar);
	
	//************************************
	// Function:   LoadObject
	// Param[in]:  ar	Ref to the input page archive loader.
	// Param[out]: pObj	It receives the loaded PDF object.
	// Return:     void
	// Remarks:	   Loads an object from archive.
	// Notes:
	//************************************ 
	static void LoadObject(FPD_PageArchiveLoader ar, FPD_PageObject* pObj);

	//************************************
	// Function:   LoadClipPath
	// Param[in]:  ar	Ref to the input page archive loader.
	// Param[out]: clip_path	 It receives the clipping path.
	// Return:     void
	// Remarks:	   Load or restore the clipping path.
	// Notes:
	//************************************ 
	static void LoadClipPath(FPD_PageArchiveLoader ar, FPD_ClipPath* clip_path);

	//************************************
	// Function:   LoadGraphState
	// Param[in]:  ar	Ref to the input page archive loader.
	// Param[out]: graph_state	It receives the graph state.
	// Return:     void
	// Remarks:	   Load or restore the graph state.
	// Notes:
	//************************************ 
	static void LoadGraphState(FPD_PageArchiveLoader ar, FPD_GraphState* graph_state);

	//************************************
	// Function:   LoadTextState
	// Param[in]:  ar	Ref to the input page archive loader.
	// Param[out]: text_state	It receives the text state.
	// Return:     void
	// Remarks:	   Load or restore the text state.
	// Notes:
	//************************************ 
	static void LoadTextState(FPD_PageArchiveLoader ar, FPD_TextState* text_state);

	//************************************
	// Function:   LoadColorState
	// Param[in]:  ar	Ref to the input page archive loader.
	// Param[out]: color_state	It receives the color state.
	// Return:     void
	// Remarks:	   Load or restore the color state.
	// Notes:
	//************************************ 
	static void LoadColorState(FPD_PageArchiveLoader ar, FPD_ColorState* color_state);

	//************************************
	// Function:   LoadGeneralState
	// Param[in]:  ar	Ref to the input page archive loader.
	// Param[out]: general_state	It receives the general state.
	// Return:     void
	// Remarks:	   Load or restore the general state.
	// Notes:
	//************************************ 
	static void LoadGeneralState(FPD_PageArchiveLoader ar, FPD_GeneralState* general_state);

	//************************************
	// Function:  New2
	// Param[in]: pPageObjs	The current page/form.
	// Param[in]: pData	The input memory buffer.
	// Param[in]: dwSize	The size of the input buffer.
	// Return:    The PDF page archive loader.
	// Remarks:	  Constructs a loading archive.
	// Notes:
	//************************************ 
	static FPD_PageArchiveLoader New2(FPD_GraphicsObjects pPageObjs, FS_LPCBYTE pData, FS_DWORD dwSize);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*                             CFPD_Creator_V1                                 */
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_Creator_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: pDoc	The PDF Document Object.
	// Return:    The PDF Creater.
	// Remarks:	  creates PDF file from a document object
	// Notes:
	//************************************ 
	static FPD_Creator New(FPD_Document pDoc);

	//************************************
	// Function:  Destroy
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Return:    void.
	// Remarks:	  Destroys the PDF file Creator.
	// Notes:
	//************************************ 
	static void Destroy(FPD_Creator pFPDCreator);

	//************************************
	// Function:  Compress
	// Param[in]: pFPDCreator	  The input PDF file Creator.
	// Param[in]: bEnable	Whether to do data compressing.
	// Return:    void.
	// Remarks:	  Sets data compression. By default, FPD_Creator use Flate compression for all data streams 
	//            in release mode, but not in debug mode.
	// Notes:
	//************************************ 
	static void Compress(FPD_Creator pFPDCreator, FS_BOOL bEnable);

	//************************************
	// Function:  SetStandardSecurity
	// Param[in]: pFPDCreator	    The input PDF file Creator.
	// Param[in]: permissions		The user permissions.
	// Param[in]: user_pass			The user password.
	// Param[in]: user_pass_len		The length of user password.
	// Param[in]: owner_pass			The owner password.
	// Param[in]: owner_pass_len		The length of owner password.
	// Param[in]: cipher				The cipher type, RC4 or AES.
	// Param[in]: key_bytes			The length of the document key.
	// Param[in]: bEncryptMetadata	Whether to encrypt the metadata.
	// Return:    void.
	// Remarks:	  Sets security settings using standard security handler only.
	//            Can't be used with incremental update.
	// Notes:
	//************************************ 
	static void SetStandardSecurity(FPD_Creator pFPDCreator, FS_DWORD permissions, FS_LPCBYTE user_pass, FS_INT32 user_pass_len,
								FS_LPCBYTE owner_pass, FS_INT32 owner_pass_len, FS_INT32 cipher, FS_INT32 key_bytes,
								FS_BOOL bEncryptMetadata);

	//************************************
	// Function:  ModifyR5Security
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Param[in]: bPermissions		Whether permission and EncryptMetadata changed.
	// Param[in]: permissions		New permissions value.
	// Param[in]: bEncryptMetadata	New EncryptMetadata value.
	// Param[in]: bUserPassword		Whether user password changed (owner password required).
	// Param[in]: user_pass			The user password pointer.
	// Param[in]: user_size			The length of the user password.
	// Param[in]: bOwnerPassword	Whether owner password changed.
	// Param[in]: owner_pass		The owner password pointer.
	// Param[in]: owner_size		The length of the owner password.
	// Return:    void.
	// Remarks:	  Modifies security permissions for Revision 5 handler (AES 256)
	// Notes:
	//************************************ 
	static void ModifyR5Security(FPD_Creator pFPDCreator, FS_BOOL bPermissions, FS_DWORD permissions, FS_BOOL bEncryptMetadata,
								FS_BOOL bUserPassword, FS_LPCBYTE user_pass, FS_DWORD user_size, 
								FS_BOOL bOwnerPassword, FS_LPCBYTE owner_pass, FS_DWORD owner_size);

	//************************************
	// Function:  SetCustomSecurity
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Param[in]: pEncryptDict			The Encrypt dictionary.
	// Param[in]: pCryptoHandler		The crypto handler.
	// Param[in]: bEncryptMetadata		Whether to encrypt the metadata.
	// Return:    The data need to be released. You can invoke FPDCreatorReleaseCustomSecurityData.
	// Remarks:	  Sets security using custom security handler and custom encryption.
	// Notes:     Application should provide a full encryption dictionary (application can destroy it after this call),
	//            and a custom encryption handler.
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void* SetCustomSecurity(FPD_Creator pFPDCreator, FPD_Object pEncryptDict, FPD_CryptoHandler pCryptoHandler, FS_BOOL bEncryptMetadata);

	//************************************
	// Function:  ReleaseCustomSecurityData
	// Param[in]: pFPDCreator		The input PDF file Creator.
	// Param[in]: cusSecurityData	The custom security data to be released.
	// Return:    The data need to be released.
	// Remarks:	  Release the custom security data generated by FPDCreatorSetCustomSecurity.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void ReleaseCustomSecurityData(FPD_Creator pFPDCreator, void* cusSecurityData);

	//************************************
	// Function:  RemoveSecurity
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Return:    void.
	// Remarks:	  Removes security settings. The output file will not be encrypted.
	// Notes:     Can't be used with incremental update.
	//************************************ 
	static void RemoveSecurity(FPD_Creator pFPDCreator);

	//************************************
	// Function:  Create
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Param[in]: filename		The output filename.
	// Param[in]: flags			The creating flags.
	// Return:    Non-zero means success, otherwise failed.
	// Remarks:	  Write the whole document into a new file (using Unicode file name). Unicode version.
	// Notes:    
	//************************************ 
	static FS_BOOL Create(FPD_Creator pFPDCreator, FS_LPCWSTR filename, FS_DWORD flags);

	//************************************
	// Function:  Create2
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Param[in]: filename		The output filename.
	// Param[in]: flags			The creating flags.
	// Return:    Non-zero means success, otherwise failed.
	// Remarks:	  Write the whole document into a new file (using local file name). Local version.
	// Notes:    
	//************************************ 
	static FS_BOOL Create2(FPD_Creator pFPDCreator, FS_LPCSTR filename, FS_DWORD flags);

	//************************************
	// Function:   Create3
	// Param[in]:  pFPDCreator	The input PDF file Creator.
	// Param[out]: pFile			The output file access.
	// Param[in]:  flags			The creating flags.
	// Return:     Non-zero means success, otherwise failed.
	// Remarks:	   Write the whole document to a custom file access.
	// Notes:    
	//************************************ 
	static FS_BOOL Create3(FPD_Creator pFPDCreator, FS_StreamWriteHandler* pFile, FS_DWORD flags);

	//************************************
	// Function:  GetObjectOffset
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Param[in]: objnum			The object number.
	// Return:    the object offset.
	// Remarks:	  Gets object offset.
	// Notes:     If the object with specific number doesn't exist, the returned value will be zero.
	//            If incremental update is used, offsets and sizes are only valid for modified indirect objects.
	//************************************ 
	static FS_DWORD GetObjectOffset(FPD_Creator pFPDCreator, FS_DWORD objnum);

	//************************************
	// Function:  GetObjectSize
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Param[in]: objnum			The object number.
	// Return:    the object size.
	// Remarks:	  Gets object size.
	// Notes:     If the object with specific number doesn't exist, the returned value will be zero.
	//            If incremental update is used, offsets and sizes are only valid for modified indirect objects.
	//************************************ 
	static FS_DWORD GetObjectSize(FPD_Creator pFPDCreator, FS_DWORD objnum);

	//************************************
	// Function:  SetProgressiveEncryptHandler
	// Param[in]: pFPDCreator		The input PDF file Creator.
	// Param[in]: callbacks			The callback set for progressive encrypt handler.
	// Return:    The progressive encrypt handler.
	// Remarks:	  Sets the progressive encrypt handler so that the creator can encrypt the content progressively.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See: FPDCreatorReleaseProgressiveEncryptHandler
	//************************************ 
	static FPD_ProgressiveEncryptHandler SetProgressiveEncryptHandler(FPD_Creator pFPDCreator, FPD_ProgressiveEncryptCallbacks callbacks);
	
	//************************************
	// Function:  ReleaseProgressiveEncryptHandler
	// Param[in]: handler The input progressive encrypt handler to be released.
	// Return:    void.
	// Remarks:	  Releases the progressive encrypt handler.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	//************************************
	static void ReleaseProgressiveEncryptHandler(FPD_ProgressiveEncryptHandler handler);

	//************************************
	// Function:  SetOption
	// Param[in]: pFPDCreator		The input PDF file Creator.
	// Param[in]: callbacks			The callback set for creator option.
	// Return:    The creator option.
	// Remarks:	  Sets the creator option so that the creator can decode or encode the content progressively.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: FPDCreatorReleaseOption
	//************************************ 
	static FPD_CreatorOption SetOption(FPD_Creator pFPDCreator, FPD_CreatorOptionCallbacks callbacks);
	
	//************************************
	// Function:  ReleaseOption
	// Param[in]: handler The input creator option.
	// Return:    void.
	// Remarks:	  Releases the creator option.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void ReleaseOption(FPD_CreatorOption creatorOption);

	//************************************
	// Function:  DeprecatedSetDRMSecurity
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Param[in]: pEncryptDict			The Encrypt dictionary.
	// Param[in]: pCryptoHandler		The crypto handler.
	// Param[in]: bEncryptMetadata		Whether to encrypt the metadata.
	// Return:    The data need to be released. You can invoke FPDCreatorReleaseDRMSecurityData.
	// Remarks:	  Sets security using custom security handler and custom encryption.
	// Notes:     Application should provide a full encryption dictionary (application can destroy it after this call),
	//            and a custom encryption handler.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.5
	//************************************
	static void* DeprecatedSetDRMSecurity(FPD_Creator pFPDCreator, FPD_Object pEncryptDict, FPD_CryptoHandler pCryptoHandler, FS_BOOL bEncryptMetadata);

	//************************************
	// Function:  DeprecatedReleaseDRMSecurityData
	// Param[in]: pFPDCreator		The input PDF file Creator.
	// Param[in]: cusSecurityData	The custom security data to be released.
	// Return:    The data need to be released.
	// Remarks:	  Release the custom security data generated by FPDCreatorSetDRMSecurity.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.5
	//************************************
	static void DeprecatedReleaseDRMSecurityData(FPD_Creator pFPDCreator, void* cusSecurityData);

	//************************************
	// Function:  DeprecatedSetDRMProgressiveEncryptHandler
	// Param[in]: pFPDCreator		The input PDF file Creator.
	// Param[in]: callbacks			The callback set for progressive encrypt handler.
	// Return:    The progressive encrypt handler.
	// Remarks:	  Sets the progressive encrypt handler so that the creator can encrypt the content progressively.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.5
	// See: FPDCreatorDRMReleaseProgressiveEncryptHandler
	//************************************
	static FPD_ProgressiveEncryptHandler DeprecatedSetDRMProgressiveEncryptHandler(FPD_Creator pFPDCreator, FPD_ProgressiveEncryptCallbacks callbacks);

	//************************************
	// Function:  DeprecatedReleaseDRMProgressiveEncryptHandler
	// Param[in]: handler The input progressive encrypt handler to be released.
	// Return:    void.
	// Remarks:	  Releases the progressive encrypt handler.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.5
	//************************************
	static void DeprecatedReleaseDRMProgressiveEncryptHandler(FPD_ProgressiveEncryptHandler handler);

	//************************************
	// Function:  SetProgressiveEncryptHandler2
	// Param[in]: pFPDCreator		The input PDF file Creator.
	// Param[in]: callbacks			The callback set for progressive encrypt handler.
	// Param[in]: releaseClientData	The release callback,that need to be release in plugin.
	// Param[in]: bNeedCrypto	    Whether set crypto handler by FPDCreatorSetCustomSecurity before.
	// Return:    The progressive encrypt handler.
	// Remarks:	  Sets the progressive encrypt handler so that the creator can encrypt the content progressively.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// See: FPDCreatorReleaseProgressiveEncryptHandler
	//************************************ 
	static FPD_ProgressiveEncryptHandler SetProgressiveEncryptHandler2(FPD_Creator pFPDCreator, FPD_ProgressiveEncryptCallbacks callbacks, FPD_ReleaseProgressiveEncryptClientData releaseClientData,FS_BOOL bNeedCrypto);

	//************************************
	// Function:  SetCustomSecurity2
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Param[in]: pEncryptDict			The Encrypt dictionary.
	// Param[in]: pCryptoHandler		The crypto handler.
	// Param[in]: bEncryptMetadata		Whether to encrypt the metadata.
	// Return:   
	// Remarks:	  Sets security using custom security handler and custom encryption.
	// Notes:     Application should provide a full encryption dictionary (application can destroy it after this call),
	//            and a custom encryption handler.
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void SetCustomSecurity2(FPD_Creator pFPDCreator, FPD_Object pEncryptDict, FPD_StandardCryptoHandler cryptoHandler, FS_BOOL bEncryptMetadata);

	//************************************
	// Function:  SetCustomSecurity3
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Param[in]: pEncryptDict			The Encrypt dictionary.
	// Param[in]: pCryptoHandler		The crypto handler.
	// Param[in]: bEncryptMetadata		Whether to encrypt the metadata.
	// Return:   
	// Remarks:	  Sets security using custom security handler and custom encryption.
	// Notes:     Application should provide a full encryption dictionary (application can destroy it after this call),
	//            and a custom encryption handler.
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void SetCustomSecurity3(FPD_Creator pFPDCreator, FPD_Object pEncryptDict, FPD_FipsStandardCryptoHandler cryptoHandler, FS_BOOL bEncryptMetadata);
	
	 //************************************
	 // Function:  AttachUncompressObjects
	 // Param[in]: pFPDCreator		The input PDF file Creator.
	 // Param[in]  pObjNums	        Ignored object numbers' pointer.
	 // Param[in]  dwSize	        Count of input object numbers.
	 // Return:  void.
	 // Remarks: Attach uncompress objects. The objects will not be compressed to the object stream.
	 // Notes:    
	 // Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	 //************************************
	static void		AttachUncompressObjects(FPD_Creator pFPDCreator, const FS_DWORD* pObjNums, FS_DWORD dwSize);

	//************************************
	 // Function:  GetStandardLinearizationObj
	 // Param[in]: pFPDCreator		The input PDF file Creator.	 
	 // Return:  FPD_StandardLinearization.
	 // Remarks: Get CPDF_StandardLinearization obj, CPDF_StandardLinearization inheritance CPDF_Creator.
	 // Notes:    
	 // Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	 //************************************
	static FPD_StandardLinearization  GetStandardLinearizationObj(FPD_Creator pFPDCreator);

	//************************************
	// Function:   Create4
	// Param[in]:  pFPDCreator	The input PDF file Creator.
	// Param[out]: pFile			The output file access.
	// Param[in]:  flags			The creating flags.
	// Return:     Non-zero means success, otherwise failed.
	// Remarks:	   Write the whole document to a custom file access.
	// Notes:    
	//************************************ 
	static FS_BOOL Create4(FPD_Creator pFPDCreator, FS_FileWriteHandler pFile, FS_DWORD flags);

	//************************************
	// Function:  SetStandardSecurity2
	// Param[in]: pFPDCreator	    The input PDF file Creator.
	// Param[in]: permissions		The user permissions.
	// Param[in]: user_pass			The user password.
	// Param[in]: user_pass_len		The length of user password.
	// Param[in]: owner_pass		The owner password.
	// Param[in]: owner_pass_len	The length of owner password.
	// Param[in]: bEncryptMetadata	Whether to encrypt the metadata.
	// Return:    void.
	// Remarks:	  Sets security settings using standard security handler only.
	//            Can't be used with incremental update.
	// Notes:
	//************************************ 
	static void SetStandardSecurity2(FPD_Creator pFPDCreator, FS_DWORD permissions, FS_LPCWSTR user_pass, FS_INT32 user_pass_len,
		FS_LPCWSTR owner_pass, FS_INT32 owner_pass_len, FS_BOOLEAN bEncryptMetadata);

	//************************************
	// Function:  ModifyR5Security2
	// Param[in]: pFPDCreator	The input PDF file Creator.
	// Param[in]: bPermissions		Whether permission and EncryptMetadata changed.
	// Param[in]: permissions		New permissions value.
	// Param[in]: bEncryptMetadata	New EncryptMetadata value.
	// Param[in]: bUserPassword		Whether user password changed (owner password required).
	// Param[in]: user_pass			The user password pointer.
	// Param[in]: user_size			The length of the user password.
	// Param[in]: bOwnerPassword	Whether owner password changed.
	// Param[in]: owner_pass		The owner password pointer.
	// Param[in]: owner_size		The length of the owner password.
	// Return:    void.
	// Remarks:	  Modifies security permissions for Revision 5 handler (AES 256)
	// Notes:
	//************************************ 
	static void ModifyR5Security2(FPD_Creator pFPDCreator, FS_BOOL bPermissions, FS_DWORD permissions, FS_BOOL bEncryptMetadata,
		FS_BOOL bUserPassword, FS_LPCWSTR user_pass, FS_DWORD user_size,
		FS_BOOL bOwnerPassword, FS_LPCWSTR owner_pass, FS_DWORD owner_size);
	
	 //************************************
	 // Function:  AttachIgnoredObjects
	 // Param[in]: pFPDCreator	    The input PDF file Creator.
	 // Param[in]: pObjNums			Ignored object numbers' pointer.
	 // Param[in]: dwSize			Count of input object numbers.
	 // Return:    void.
	 // Remarks:	  Attach ignored objects. The objects will not be written into the creating file.
	 // Notes:
	 //************************************ 
	static void	AttachIgnoredObjects(FPD_Creator pFPDCreator, const FS_DWORD* pObjNums, FS_DWORD dwSize);
	
	//************************************
	// Function:  SetAESV4GCMSecurity
	// Param[in]: pFPDCreator	    The input PDF file Creator.
	// Param[in]: permissions	    The user permissions.
	// Param[in]: user_pass				The user password.
	// Param[in]: user_pass_len			The length of user password.
	// Param[in]: owner_pass			The owner password.
	// Param[in]: owner_pass_len		The length of owner password.
	// Param[in]: bEncryptMetadata		Whether to encrypt the metadata.
	// Return:    void.
	// Remarks:	  Set security settings using standard security handler for AES-GCM with unicode password.
	// And the Revision must be 7 and later, the PDF file version should be 2.0.
	// Can't be used with incremental update.
	// Notes:
	//************************************ 
	static FS_BOOLEAN SetAESV4GCMSecurity(FPD_Creator pFPDCreator, FS_DWORD permissions,
		FS_LPCWSTR user_pass,
		FS_INT32 user_pass_len,
		FS_LPCWSTR owner_pass,
		FS_INT32 owner_pass_len,
		FS_BOOLEAN bEncryptMetadata);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*                             class CFPD_WrapperCreator_V2                                         */
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_WrapperCreator_V2
{
public:
	//************************************
	// Function:  New
	// Param[in]: pWrapperDoc		A document object which defines wrapper version, caller maintains its life-time.
	// Param[in]: dwWrapperOffset	Offset in bytes from the beginning of PDF file, for wrapper version.
	// Return:    An instance of interface FPD_WrapperCreator, NULL pointer if error happens.
	// Remarks:	  Creates an instance of FPD_WrapperCreator.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static FPD_WrapperCreator New(FPD_Document pWrapperDoc, FS_DWORD dwWrapperOffset);

	//************************************
	// Function:  Destroy
	// Param[in]: wrapperCreator		The input wrapper creator object.
	// Return:    void.
	// Remarks:	  Destroy the wrapper creator.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void Destroy(FPD_WrapperCreator wrapperCreator);

	//************************************
	// Function:  SetWrapperData
	// Param[in]: wrapperCreator	The input wrapper creator object.
	// Param[in]: szType			Wrapper type name.
	// Param[in]: iVersion			Wrapper version.
	// Param[in]: szApplication		Application identity which indicates how to process the current wrapper file.
	// Param[in]: szURI				An URI site to retrieve more helpful information if necessary.
	// Param[in]: szDescription		Description text for application.
	// Return:    void.
	// Remarks:	  Set wrapper data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void SetWrapperData(FPD_WrapperCreator wrapperCreator, FS_LPSTR szType, FS_INT32 iVersion, FS_LPSTR szApplication, FS_LPSTR szURI, FS_LPSTR szDescription);

	//************************************
	// Function:  Create
	// Param[in]: wrapperCreator	The input wrapper creator object.
	// Param[in]: pFile				The output file access.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:	  Write the wrapper version to a custom file access.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static FS_BOOL Create(FPD_WrapperCreator wrapperCreator, FS_StreamWriteHandler* pFile);

	//************************************
	// Function:  SetStandardSecurity
	// Param[in]: wrapperCreator	The input wrapper creator object.
	// Param[in]: permissions		The user permissions.
	// Param[in]: owner_pass		The owner password.
	// Param[in]: owner_pass_len	The length of owner password.
	// Return:    void.
	// Remarks:	  Set security settings using standard security handler only. Can't be used with incremental update.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************ 
	static void SetStandardSecurity(FPD_WrapperCreator wrapperCreator, FS_DWORD permissions, FS_LPCBYTE owner_pass, FS_INT32 owner_pass_len);

};

class CFPD_UnencryptedWrapperCreator_V10
{
public:
	//************************************
	// Function:  New
	// Param[in]: pWrapperDoc		A document object which defines wrapper version, caller maintains its life-time.
	// Return:    An instance of interface FPD_Wrapper20Creator, NULL pointer if error happens.
	// Remarks:	  Creates an instance of FPD_Wrapper20Creator.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************ 
	static FPD_UnencryptedWrapperCreator New(FPD_Document pWrapperDoc);

	//************************************
	// Function:  Destroy
	// Param[in]: wrapperCreator	The input wrapper creator object.
	// Return:    void.
	// Remarks:	  Destroy the wrapper creator.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************ 
	static void Destroy(FPD_UnencryptedWrapperCreator wrapperCreator);

	//************************************
	// Function:  SetPayloadInfo
	// Param[in]: wrapperCreator	The input wrapper creator object.
	// Param[in]: wsSubType			The name of the cryptographic filter used to encrypt the encrypted payload document.
	// Param[in]: wsFileName		The file name for encrypted payload document which shall include the name of the
	//							cryptographic filter needed to decrypt the document.
	// Param[in]: wsDescription		Description text for the embedded encrypted payload document.
	// Param[in]: fVersion			The version number of the cryptographic filter used to encrypt the encrypted payload.
	// Return:    void.
	// Remarks:	  Set data of the embedded encrypted payload document for the wrapper doc.
	// Notes:	  The Param "bsFileName" must not contain or be derived from the encrypted payload’s actual file name. 
	//			  This is to avoid potential disclosure of sensitive information in the original filename.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************ 
	static void SetPayloadInfo(FPD_UnencryptedWrapperCreator wrapperCreator, FS_LPWSTR wsSubType, FS_LPWSTR wsFileName, FS_LPWSTR wsDescription, FS_FLOAT fVersion);

	//************************************
	// Function:  SetPayLoad
	// Param[in]: wrapperCreator	The input wrapper creator object.
	// param[in]: pPayload			The embedded encrypted payload document.
	// Return:    void.
	// Remarks:	  Set the embedded encrypted payload document for the wrapper doc.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************ 
	static void SetPayLoad(FPD_UnencryptedWrapperCreator wrapperCreator, FS_FileReadHandler pPayload);

	//************************************
	// Function:  Create
	// Param[in]: wrapperCreator	The input wrapper creator object.
	// Param[out]: pFile				The output file access.
	// Param[in]: flags				The creating flags.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:	  Write the wrapper version to a custom file access.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************ 
	static FS_BOOL Create(FPD_UnencryptedWrapperCreator wrapperCreator, FS_FileWriteHandler *pFile, FS_DWORD flags);

	//************************************
	// Function:  Continue
	// Param[in]: wrapperCreator	The input wrapper creator object.
	// Param[in]: pPause	Pause object, optional.
	// Return:    Negative value if failure, 0 if finishes, and positive value if need to be continued.
	// Remarks:	  Continue to write wrapper document data under progressive mode.
	// Notes:	  Only valid if pass FPDFCREATE_PROGRESSIVE flag in calling Create method.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************ 
	static FS_INT32	Continue(FPD_UnencryptedWrapperCreator wrapperCreator, FS_PauseHandler pPause);

	//************************************
	// Function:  SetStandardSecurity
	// Param[in]: wrapperCreator	The input wrapper creator object.
	// Param[in]: permissions		The user permissions.
	// Param[in]: owner_pass		The owner password.
	// Param[in]: owner_pass_len	The length of owner password.
	// Return:	void.
	// Remarks:	  Set security settings using standard security handler only.
	// Notes:	  Can't be used with incremental update.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.1
	//************************************ 
	static void	SetStandardSecurity(FPD_UnencryptedWrapperCreator wrapperCreator, FS_DWORD permissions, FS_LPCBYTE owner_pass, FS_INT32 owner_pass_len);
};

class CFPD_StandardLinearization_V14
{
public:
	//************************************
	// Function:  GetCFPDLinearizedObj
	// Param[in]: pFPDCreator		The input PDF file Creator.	
	// Return:  FPD_StandardLinearization.
	// Remarks: Support CPDF_Creator convert to CPDF_StandardLinearization.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static  FPD_StandardLinearization		GetCFPDLinearizedObj(FPD_Creator pFPDCreator);

	//************************************
	// Function:  GetLinearizedObjNum
	// Param[in]: linearzation		The input StandardLinearization obj.	
	// Param[in]: objnum		The old object number in the original PDF.	
	// Return:  FS_DWORD.   The new object number in the linearized PDF.
	// Remarks: Get the new object number in the linearized PDF.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static  FS_DWORD		GetLinearizedObjNum(FPD_StandardLinearization linearzation, FS_DWORD objnum);
	
	 //************************************
	 // Function:  Linearize
	 // Param[in]: linearzation		The input StandardLinearization obj.	
	 // Param[in]: bRegenMetadata	Whether to regenerate the XMP metadata with padding bytes.	
	 // Return:  FS_BOOLEAN.   If this method returns false, means error occurs. true for successful linearization.
	 // Remarks: Analyze and linearize the PDF document.
	 // Notes: If want r save as a linearized PDF, this function must be called before FPDCreatorCreate function.
	 //			And all the operations which will modify the document must be called firstly, such as
	 //			FPDCreatorAttachIgnoredObjects and FPDCreatorAttachUncompressObjects and so on.
	 //			Not call it will save as a no linearized PDF.When return false, application can still
	 //			call::Create but it will save as a no linearized PDF.
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	 //************************************
	static FS_BOOLEAN		Linearize(FPD_StandardLinearization linearzation, FS_BOOLEAN bRegenMetadata);

	//************************************
	// Function:  New
	// Param[in]: pDocument		The input FPD_Document obj.	
	// Return:  FPD_StandardLinearization    Construct FPD_StandardLinearization object.
	// Remarks: Construct with a Linearized PDF document. 
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	//************************************
	static FPD_StandardLinearization New(FPD_Document pDocument);

	//************************************
	// Function:  Delete
	// Param[in]: linearzation		The input FPD_StandardLinearization obj.	
	// Return: void
	// Remarks: Delete FPD_StandardLinearization obj.	
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	//************************************
	static void Delete(FPD_StandardLinearization linearzation);

	//************************************
	// Function:  CastToCreator
	// Param[in]: linearzation		The input FPD_StandardLinearization obj.	
	// Return: FPD_Creator
	// Remarks: Cast to parent of FPD_Creator object.	
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	//************************************
	static FPD_Creator CastToCreator(FPD_StandardLinearization linearzation);
	
	 //************************************
	 // Function:  Create
	 // Param[in]: linearzation		The input FPD_StandardLinearization obj.	
	 // Param[in]: pFile			The output file access.
	 // Param[in]: dwFlags			flags indicate how to linearize PDF document, refer to FPD_SAVE_XXXX macros.
	 // Return: FS_BOOLEAN   false if failure, otherwise finishes successfully.
	 // Remarks: Write the whole document to a custom file access.
	 // Notes:    If want to save as a linearized PDF, the Linearize function must be called firstly.
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	 //************************************
	static FS_BOOLEAN Create(FPD_StandardLinearization linearzation, FS_FileWriteHandler pFile, FS_DWORD dwFlags);
};

class CFPD_CustomCryptoHandler_V17
{
public:
	//************************************
	// Function:  Create
	// Param[in]: pCallbacks		The input FPD_CryptoHandler callback.
	// Return:  FPD_CustomCryptoHandler.   
	// Remarks: Create the FPD_CustomCryptoHandler object.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_CustomCryptoHandler Create(FPD_CryptoHandler pCallbacks);

	//************************************
	// Function:  Destroy
	// Param[in]: cryptoHandler		The input FPD_CustomCryptoHandler.
	// Return:  void.   
	// Remarks: Destroy the FPD_CustomCryptoHandler object.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void Destroy(FPD_CustomCryptoHandler cryptoHandler);
};



#ifdef __cplusplus
};
#endif

#endif //FPD_DERIALIMPL_H

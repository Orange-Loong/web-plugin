

#ifndef FPD_DOCIMPL_H
#define FPD_DOCIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../fpd_parserExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifndef FPD_RESOURCEIMPL_H
#include "../fpd_resourceExpT.h"
#endif

#ifndef FPD_RESOURCEIMPL_H
#include "../fpd_renderExpT.h"
#endif

#ifndef FPD_FXXFAEXPT_H
#include "../fpd_fxxfaExpT.h"
#endif

/*@}*/ 


#ifdef __cplusplus
extern "C"{
#endif

/** @brief Page enumeration handler interface. */
class CFPD_CustomerEnumPageHandler : public IPDF_EnumPageHandler, public CFX_Object
{
public:
	CFPD_CustomerEnumPageHandler(FPD_EnumPage enumPage);
	/**
	 * Enumerates page function for call back. Return TRUE if you want the enumeration to continue.
	 *
	 * @param[in] pPageDict		The page dictionary. 
	 * @return Non-zero means you want the enumeration to continue, otherwise want not.
	 */
	virtual FX_BOOL EnumPage(CPDF_Dictionary* pPageDict);

	void* GetClientData(){return m_enumPage.clientData;}
public:
	FPD_EnumPage m_enumPage;
};


class CFPD_Doc_V1
{
public:
	//************************************
	// Function: New
	// Param[in]:    void
	// Return:   The new empty document.
	// Remarks:	 Creates a new empty document. </Brief> The only <a>FPD_Object</a> in the document will be a
	// Catalog dictionary. See <Italic>Section 3.6 in the PDF Reference</Italic>. 
	// Notes:
	//************************************      
	static FPD_Document	New(void);

	//************************************
	// Function:  Destroy 
	// Param[in]: doc	The document to destroy.	
	// Return:	  void
	// Remarks:   Destroys the document created by <a>FPDDocNew</a>. When Foxit Reader opens the doc, it is taken over and 
	// don't destroy it.
	// Notes:	
	//************************************
	static void	Destroy(FPD_Document doc);

	//************************************
	// Function:  Open
	// Param[in]: wszFilePath	The input file full path name.
	// Param[in]: szPassword	The input password string.
	// Return:	 The newly createddocument from an existing PDF file.
	// Remarks:	  Creates a new document from an existing PDF file. You must call <a>FPDDocClose</a>() once for every
	// successful open. 	
	// Notes:
	//************************************
	static FPD_Document	Open(FS_LPCWSTR wszFilePath, FS_LPCSTR szPassword);

	//************************************
	// Function:  OpenMemDocument
	// Param[in]: dataBuf	The input memory block.
	// Param[in]: size		The size in bytes of the memory block.
	// Param[in]: szPassword	The input password string.
	// Return:	  The newly created document from memory block.
	// Remarks:   Creates a  document from memory block. You must call <a>FPDDocClose</a>() once for every
	// successful open. 
	// Notes:
	//************************************
	static FPD_Document	OpenMemDocument(void* dataBuf, FS_INT32 size, FS_LPCSTR szPassword);

	//************************************
	// Function:  StartProgressiveLoad
	// Param[in]: fileRead		The file access handler. Plug-ins should free the object after the document is parsed completely.
	// Param[in]: szPassword	The input password string.
	// Param[in]: pause			The pause handler. This can be <a>NULL</a> if you don't want to pause.
	// Param[out]: outPDDoc		Receiving the document.
	// Return:	  The result code. See <a>FPDLoadErrCodes</a>.
	// Remarks:   Document loading is a progressive process. It might take a long time to
	// load a document, especially when a file is corrupted, FPDFEMB will try to recover the document contents by scanning the whole 
	// file. If "pause" parameter is provided, this function may return FPDFERR_TOBECONTINUED any time during the document loading.<br>
	// When <a>FPD_LOADERR_TOBECONTINUED</a> is returned, the "outPDDoc" parameter will still receive a valid document handle, however, 
	// no further operations can be performed on the document, except the <a>FPDDocContinueLoad</a>() function call, which resume the 
	// document loading. 
	// Notes:
	//************************************
	static FS_RESULT StartProgressiveLoad(FS_FileReadHandler fileRead, FS_LPCSTR szPassword, FS_PauseHandler pause, FPD_Document* outPDDoc);
	
	//************************************
	// Function:  ContinueLoad
	// Param[in]: doc	The PDF document.
	// Param[in]: pause		The pause handler. This can be <a>NULL</a> if you don't want to pause.
	// Return:	  The result code. See <a>FPDLoadErrCodes</a>.
	// Remarks:   Continue loading a PDF document. You must call <a>FPDDocClose</a>() once for every
	// successful open. 
	// Notes:
	//************************************
	static FS_RESULT ContinueLoad(FPD_Document doc, FS_PauseHandler pause);
	

	//************************************
	// Function:  Close 
	// Param[in]: doc	The document returned by <a>FPDDocOpen</a>(), <a>FPDDocStartProgressiveLoad</a>() or <a>FPDDocOpenMemDocument</a>().
	// Return:    Error code. FPD_LOADERR_SUCCESS for success.
	// Remarks:   Closes the document returned by <a>FPDDocOpen</a>(), <a>FPDDocStartProgressiveLoad</a>() or <a>FPDDocOpenMemDocument</a>(). 	
	// Notes: Call <a>FPDDocDestroy</a>() to release a document which created by <a>FPDDocNew</a>().
	//************************************
	static FS_RESULT	Close(FPD_Document doc);

	//************************************
	// Function:  GetRoot
	// Param[in]: doc	A PDF document.
	// Return:    The root dictionary (document catalog dictionary).
	// Remarks:   Gets root dictionary (document catalog dictionary) from a PDF document.
	// Notes:
	//************************************
	static FPD_Object GetRoot(FPD_Document doc);

	//************************************
	// Function:  GetInfo
	// Param[in]: doc	A PDF document.
	// Return:    The document info dictionary.
	// Remarks:   Gets document info dictionary from a PDF document. Could be NULL.
	// Notes:
	//************************************
	static FPD_Object GetInfo(FPD_Document doc);

	//************************************
	// Function:  GetID
	// Param[in]: doc		A PDF document.
	// Param[out]:outID1	It receives the first ID string of the document.
	// Param[out]:outID2	It receives the second ID string of the document.
	// Return:    void
	// Remarks:   Gets ID strings of the document. Could be empty.
	// Notes:
	//************************************
	static void	GetID(FPD_Document doc,FS_ByteString* outID1, FS_ByteString* outID2);

	//************************************
	// Function:  GetPageCount
	// Param[in]: doc
	// Return: The page count.
	// Remarks:   Gets number of pages in this document.
	// Notes:
	//************************************
	static FS_INT32	GetPageCount(FPD_Document doc);

	//************************************
	// Function:  GetPage
	// Param[in]: doc			A PDF document.
	// Param[in]: page_index	Specifies the zero-based index of the page in the document.
	// Return:    The specified page dictionary of the document.
	// Remarks:   Gets page dictionary of a specified page of the document. Page index starts from zero for the first page.
	// Notes:
	//************************************
	static FPD_Object GetPage(FPD_Document doc, FS_INT32 page_index);	
	
	//************************************
	// Function:  GetPageIndex
	// Param[in]: doc		A PDF document.
	// Param[in]: objNum	The input indirect object number int the document.
	// Return:    The zero-based index of page in the document.
	// Remarks:   Gets the page index from a indirect object number in the document.
	// Notes:
	//************************************
	static FS_INT32	GetPageIndex(FPD_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  GetUserPermissions
	// Param[in]: doc The input PDF document.
	// Return:    The user permission of the document.
	// Remarks:   Gets the user permission of the document.
	// Notes:
	//************************************
	static FS_DWORD	GetUserPermissions(FPD_Document doc);

	//************************************
	// Function:  IsOwner
	// Param[in]: doc The input PDF document.
	// Return:    <a>TRUE</a> for being owner.
	// Remarks:   Whether the user has the owner permission of the document.
    // Notes:
	//************************************
	static FS_BOOL IsOwner(FPD_Document doc);

	//************************************
	// Function:  IsFormStream	
	// Param[in]: doc		A PDF document.
	// Param[in]: objnum	The input indirect object number.
	// Param[out]:outIsFormStream	It receive whether it's a form stream or not.
	// Return:    Non-zero means determined, otherwise unknown.
	// Remarks:   Checks if an indirect object is a form stream or not, without actually loading the object.
	// Notes:
	//************************************
	static FS_BOOL IsFormStream(FPD_Document doc,FS_DWORD objnum, FS_BOOL* outIsFormStream);


	//************************************
	// Function:  LoadFont
	// Param[in]: doc		A PDF document.
	// Param[in]: fontDict	The input font dictionary.
	// Return:    A PDF font.
	// Remarks:   Loads a font from font dictionary in the document.
	// Notes:
	//************************************
	static FPD_Font	LoadFont(FPD_Document doc, FPD_Object fontDict);

	//************************************
	// Function:  LoadColorSpace
	// Param[in]: doc		A PDF document.
	// Param[in]: csObj		The input PDF object.
	// Return:    A PDF color space.
	// Remarks:   Loads a color space from a PDF object in the document.
	// Notes:
	//************************************
	static FPD_ColorSpace LoadColorSpace(FPD_Document doc, FPD_Object csObj);

	//************************************
	// Function:  LoadPattern
	// Param[in]: doc		A PDF document.
	// Param[in]: csObj		The input PDF object.
	// Param[in]: bShading	Whether the pattern is a shading pattern or not.
	// Return:    A PDF pattern.
	// Remarks:   Loads a pattern from a PDF object in the document.
	// Notes:
	//************************************
	static FPD_Pattern LoadPattern(FPD_Document doc, FPD_Object csObj, FS_BOOL bShading);

	//************************************
	// Function:  LoadImageF
	// Param[in]: doc		A PDF document.
	// Param[in]: obj		The input PDF object.
	// Param[in]: bCache	Whether we will cache the image or not.
	// Return:    A PDF image.
	// Remarks:   Loads an image from a PDF object in the document.
	// Notes:
	//************************************
	static FPD_Image LoadImageF(FPD_Document doc, FPD_Object obj, FS_BOOL bCache);

	//************************************
	// Function:  LoadFontFile
	// Param[in]: doc	A PDF document.
	// Param[in]: stm	The input PDF stream.
	// Return:    A PDF stream accessor.
	// Remarks:   Loads a PDF stream accessor from a PDF stream in the document.
	// Notes:
	//************************************
	static FPD_StreamAcc LoadFontFile(FPD_Document doc, FPD_Object stm);

	//************************************
	// Function:  GetInfoObjNum
	// Param[in]: doc The input PDF document.
	// Return:    The number of info object.
	// Remarks:   Gets the number of info object.
	// Notes:
	//************************************
	static FS_DWORD	GetInfoObjNum(FPD_Document doc);

	//************************************
	// Function:  GetRootObjNum
	// Param[in]: doc The input PDF document.
	// Return:    The number of root object.
	// Remarks:   Gets the number of root object.
	// Notes:
	//************************************
	static FS_DWORD	GetRootObjNum(FPD_Document doc);

	//************************************
	// Function:  EnumPages
	// Param[in]: doc				A PDF document.
	// Param[in]: pEnumPageHandler	The user-supplied page enumeration handler.
	// Return:    void
	// Remarks:   Enumerates pages with user-supplied page enumeration handler.
	// Notes:
	//************************************
	static void	EnumPages(FPD_Document doc, FPD_EnumPageHandler pEnumPageHandler);

	//************************************
	// Function:  NewEnumPageHandler 
	// Param[in]: enumPage	The user-supplied page enumeration struct.
	// Return:    The user-supplied page enumeration handler.
	// Remarks:   Creates user-supplied page enumeration handler.
	// Notes:
	//************************************
	static FPD_EnumPageHandler NewEnumPageHandler(FPD_EnumPage enumPage);	

	//************************************
	// Function:  DeleteEnumPageHandler
	// Param[in]: pEnumPageHandler	The user-supplied page enumeration handler.
	// Return:    void
	// Remarks:   Deletes the user-supplied page enumeration handler.
	// Notes:
	//************************************
	static void	DeleteEnumPageHandler(FPD_EnumPageHandler pEnumPageHandler);


	//************************************
	// Function:  SetRootObjNum	
	// Param[in]: doc			A empty PDF document.
	// Param[in]: RootObjNum	The input root object number.
	// Return:    void
	// Remarks:   Sets the root object number in the PDF document. Must be called for an empty document.
	// Notes:
	//************************************
	static void	SetRootObjNum(FPD_Document doc, FS_INT32 RootObjNum);

	//************************************
	// Function:  SetInfoObjNum	
	// Param[in]: doc			A empty PDF document.
	// Param[in]: InfoObjNum	The input info object number.
	// Return:    void
	// Remarks:   Sets the info object number in the PDF document. Must be called for an empty document.
	// Notes:
	//************************************
	static void	SetInfoObjNum(FPD_Document doc, FS_INT32 InfoObjNum);

	//************************************
	// Function:  SetID
	// Param[in]: doc		A PDF document.
	// Param[in]: szID1		The first file ID.
	// Param[in]: nLen1		The length of the first ID byte string.
	// Param[in]: szID2		The second file ID.
	// Param[in]: nLen2		The length of the second ID byte string.
	// Return:    void
	// Remarks:   Sets the PDF file ID.
	// Notes:
	//************************************
	static void	SetID(FPD_Document doc, FS_LPCBYTE szID1, FS_INT32 nLen1, FS_LPCBYTE szID2, FS_INT32 nLen2);

	//************************************
	// Function:  AddWindowsFont
	// Param[in]: doc				A PDF document.
	// Param[in]: pLogFont			Points to a LOGFONT(WIN32) structure that defines the characteristics of the logical font.
	// Param[in]: bVert				Whether the font is a vertical font or not.
	// Param[in]: bTranslateName	Whether we will do font name translating or not.
	// Return:    A PDF font.
	// Remarks:   Imports a Windows font into the PDF document.
	// Notes:
	//************************************
	static FPD_Font	AddWindowsFont(FPD_Document doc, void* pLogFont, FS_BOOL bVert, FS_BOOL bTranslateName);

	//************************************
	// Function:  AddWindowsFontW
	// Param[in]: doc				A PDF document.
	// Param[in]: pLogFont			Points to a LOGFONTW(WIN32) structure that defines the characteristics of the logical font.
	// Param[in]: bVert				Whether the font is a vertical font or not.
	// Param[in]: bTranslateName	Whether we will do font name translating or not.
	// Return:    A PDF font.
	// Remarks:	  Imports a Windows font into the PDF document.
	// Notes:
	//************************************
	static FPD_Font	AddWindowsFontW(FPD_Document doc, void* pLogFont, FS_BOOL bVert, FS_BOOL bTranslateName);
	
	//************************************
	// Function:  AddStandardFont
	// Param[in]: doc		A PDF document.
	// Param[in]: font		The font name.
	// Param[in]: encoding	The font encoding.
	// Return:    
    // Remarks:   Adds a Type1 base-14 font to the PDF document.
	// Notes:
	//************************************
	static FPD_Font	AddStandardFont(FPD_Document doc, const FS_CHAR* font, FPD_FontEncoding encoding);

	//************************************
	// Function:  BuildResourceList
	// Param[in]: doc	A PDF document.
	// Param[in]: type	The name of specified type.
	// Param[out]:arr	It will receive all resource objects of specified type in the document.
	// Return:    void
	// Remarks:   Build a list of all resources of specified type in this document. On return,
	//            the array contains pointers to FPD_Object objects.
	// Notes:
	//************************************
	static void	BuildResourceList(FPD_Document doc, const FS_CHAR* type, FS_PtrArray arr);

	//************************************
	// Function:  CreateNewPage
	// Param[in]: doc		A PDF document.
	// Param[in]: iPage		Specifies the zero-based index of page to be created.
	// Return:    The created page dictionary.
	// Remarks:   Creates a new page in the PDF document. Return the created page.
	// Notes:
	//************************************
	static FPD_Object CreateNewPage(FPD_Document doc, FS_INT32 iPage);

	//************************************
	// Function:  DeletePage
	// Param[in]: doc		A PDF document.
	// Param[in]: iPage		Specifies the zero-based index of page to be deleted.
	// Return:    void
	// Remarks:   Deletes specified page in the PDF document.
	// Notes:
	//************************************
	static void	DeletePage(FPD_Document doc, FS_INT32 iPage);

	//************************************
	// Function:  ConvertIndirectObjects
	// Param[in]: doc					A PDF document.
	// Param[in]: obj					The input PDF object.
	// Param[in]: bConvertStream		Whether we will convert stream to indirect object or not.
	// Param[in]: bConvertDictionary	Whether we will convert dictionary to indirect object or not.
	// Return:    void
	// Remarks:   Converts stream of dictionary members of an object to be indirect objects.
	// Notes:
	//************************************
	static void	ConvertIndirectObjects(FPD_Document doc, FPD_Object obj, FS_BOOL bConvertStream, FS_BOOL bConvertDictionary);
	
	//************************************
	// Function:  GetPageContentModify
	// Param[in]: doc			A PDF document.
	// Param[in]: page_dict		The input page dictionary.
	// Return:    An modifiable content stream for the page.
	// Remarks:   Gets a modifiable content stream for a page in the PDF document.
	// Notes:
	//************************************
	static FPD_Object GetPageContentModify(FPD_Document doc, FPD_Object page_dict);

	//************************************
	// Function:  QuickSearch
	// Param[in]: doc				The input PDF document.
	// Param[in]: page_index		The zero-based page index to be searched.
	// Param[in]: pattern			The pattern to search.
	// Param[in]: bCaseSensitive	Whether the pattern matching is case sensitive.
	// Return:    Non-zero means searched one successfully.
	// Remarks:   Quick search an pattern for specified page in the PDF document.
	// Notes:
	//************************************
	static FS_BOOL QuickSearch(FPD_Document doc, FS_INT32 page_index, FS_LPCWSTR pattern, FS_BOOL bCaseSensitive);
	
	//************************************
	// Function:  ReloadPages
	// Param[in]: doc	A PDF document.
	// Return:    void
	// Remarks:   Reload page list. This can be used when document is progressively downloaded.
	// Notes:
	//************************************
	static void	ReloadPages(FPD_Document doc);

	//************************************
	// Function:  LoadDoc
	// Param[in]: doc The input PDF document.
	// Return:    void
	// Remarks:   Internally used
	// Notes:
	//************************************
	static void	LoadDoc(FPD_Document doc);

	//************************************
	// Function:  GetIndirectObject
	// Param[in]: doc		The input document.
	// Param[in]: objNum	The input object number.
	// Return:    An indirect object.
	// Remarks:   Loads an indirect object by an object number.
	// Notes:
	//************************************
	static FPD_Object GetIndirectObject(FPD_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  GetIndirectType
	// Param[in]: doc		The input document.
	// Param[in]: objNum	The input object number.
	// Return:    The type of the document.
	// Remarks:   Gets type of an document, without loading the object content.
	// Notes:
	//************************************
	static FS_INT32	GetIndirectType(FPD_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  AddIndirectObject
	// Param[in]: doc		The input document.
	// Param[in]: obj		The input object.
	// Return:    The new object number.
	// Remarks:   Adds an object to indirect object list. The new object number is returned.
	// Notes:
	//************************************
	static FS_DWORD	AddIndirectObject(FPD_Document doc, FPD_Object obj);

	//************************************
	// Function:  ReleaseIndirectObject
	// Param[in]: doc		The input document.
	// Param[in]: objNum	The object number to release.
	// Return:    void
	// Remarks:   Sometimes, for saving memory space, we can release a loaded indirect object.
	//            However, use this with caution because the object pointer will become invalid.
	// Notes:
	//************************************
	static void	ReleaseIndirectObject(FPD_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  DeleteIndirectObject
	// Param[in]: doc		The input document.
	// Param[in]: objNum	The object number to delete.
	// Return:    void
	// Remarks:   Deletes an indirect object. Use this function with caution!
	// Notes:
	//************************************
	static void	DeleteIndirectObject(FPD_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  ImportIndirectObject
	// Param[in]: doc		The input document.
	// Param[in]: pBuffer	The binary data for the document. It must be not encrypted.
	// Param[in]: size		The size in bytes of the binary data.
	// Return:    An object.
	// Remarks:   Imports an object from its binary format.
	//            This is used when the PDF is fetched in "Progressive Downloading" fashion.
	//            After this function call, the data buffer can be destroyed.
	//            This object must not be encrypted.
	// Notes:
	//************************************
	static FPD_Object ImportIndirectObject(FPD_Document doc, FS_LPBYTE pBuffer, FS_DWORD size);

	//************************************
	// Function:  ImportExternalObject
	// Param[in]: doc		The input document.
	// Param[in]: obj		The object in external object collection.
	// Param[out]:mapping   It updates the mapping from old object number to new object number.	
	// Return:    A new indirect object.
	// Remarks:   Imports an object from external object collection as a new document.
	//            If the external object refers to other external indirect objects, those indirect objects
	//            are also imported.
	//            The mapping from old object number to new object number is updated during the import process.
	// Notes:
	//************************************
	static FPD_Object ImportExternalObject(FPD_Document doc, FPD_Object obj, FS_MapPtrToPtr mapping);

	//************************************
	// Function:  InsertIndirectObject
	// Param[in]: doc		The input document.
	// Param[in]: objNum	The new object number of the indirect object to insert.
	// Param[in]: obj		The indirect object to insert.
	// Return:    void
	// Remarks:   Inserts an indirect object with specified object number.
	//			  This is used when the PDF is fetched in "Progressive Downloading" fashion, or parsing FDF.
	//            If an indirect object with the same object number exists, the previous one will be destroyed.
	// Notes:
	//************************************
	static void	InsertIndirectObject(FPD_Document doc, FS_DWORD objNum, FPD_Object obj);

	//************************************
	// Function:  GetLastobjNum
	// Param[in]: doc		The input document.
	// Return: The number of the last object.
	// Remarks:   Gets last assigned indirect object number.
	// Notes:
	//************************************
	static FS_DWORD	GetLastobjNum(FPD_Document doc);

	//************************************
	// Function:  ReloadFileStreams
	// Param[in]: doc		The input document.
	// Return:    void
	// Remarks:   Reload all file based stream when we do reparsing.
	// Notes:
	//************************************
	static void	ReloadFileStreams(FPD_Document doc);

	//************************************
	// Function:  GetStartPosition
	// Param[in]: doc		The input document.
	// Return: The start position of the indirect objects.
	// Remarks:   Gets the start position of the indirect objects.
	// Notes:
	//************************************
	static FS_POSITION GetStartPosition(FPD_Document doc);

	//************************************
	// Function:  GetNextAssoc
	// Param[in]: doc			The input document.
	// Param[in,out]:outPos		Input current position and receive the next position.
	// Param[out]:outObjNum		It receives the current object number.
	// Param[out]:outObject		It receives the current indirect object pointer.
	// Return:    void
	// Remarks:   Accesses the indirect object of current position, and move the position to next.
	// Notes:
	//************************************
	static void	GetNextAssoc(FPD_Document doc, FS_POSITION* outPos, FS_DWORD* outObjNum, FPD_Object* outObject);

	//************************************
	// Function:  IsModified
	// Param[in]: doc		The input document.
	// Return: <a>TRUE</a> if the document is modified, otherwise not. 
	// Remarks:   Checks if any of the indirect objects are modified, since loading from parser, or last ClearModified.
	// Notes:
	//************************************
	static FS_BOOL IsModified(FPD_Document doc);

	//************************************
	// Function:  ClearModified
	// Param[in]: doc		The input document.
	// Return:    void
	// Remarks:   Clears the modified flag.
	// Notes:
	//************************************
	static void	ClearModified(FPD_Document doc);

	//************************************
	// Function:  Save
	// Param[in]: doc		The input document.
	// Param[in]: filename	The output file name.
	// Param[in]: flags		The saving flags. You can set FPD_SAVE_DEFAULT by default.
	// Param[in]: bEnable	Whether to do data compressing.
	// Return:    Non-zero means success, otherwise failed.
	// Remarks:   Writes the whole document into a new file.
	// Notes:
	//************************************
	static FS_BOOL	Save(FPD_Document doc, FS_LPCSTR filename, FS_DWORD flags, FS_BOOL bEnable);

	//************************************
	// Function:  GetParser
	// Param[in]: doc		The input document.
	// Return:    The PDF parser.
	// Remarks:   Gets the PDF file parser associated with a <a>FPD_Document</a> object.
	// Notes:
	//************************************
	static FPD_Parser GetParser(FPD_Document doc);

	//************************************
	// Function:  CheckSignature
	// Param[in]: doc The input document.
	// Return: <a>TRUE</a> if the document is signed, otherwise not.
	// Remarks: Checks whether the document is signed or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1
	//************************************
	static FS_BOOL CheckSignature(FPD_Document doc);

	//************************************
	// Function:  GenerateFileID
	// Param[in]: dwSeed1	A seed value to initialize MT generator.
	// Param[in]: dwSeed2	A seed value to initialize MT generator.
	// Param[out]: pBuffer	It receives the file ID.
	// Return: <a>TRUE</a> for success, otherwise failure.
	// Remarks: Generates the ID of the PDF document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_BOOL GenerateFileID(FS_DWORD dwSeed1, FS_DWORD dwSeed2, FS_LPDWORD pBuffer);

	//************************************
	// Function:  GetReviewType
	// Param[in]: doc				The document.
	// Return: The review type. 0:normal, 1:share, 2:email.
	// Remarks: Gets the review type. 0:normal, 1:share, 2:email.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_INT32 GetReviewType(FPD_Document doc);

	//************************************
	// Function:  IsPortfolio
	// Param[in]: doc	The input PDF document.
	// Return: TRUE if the document is a portfolio document, otherwise not.
	// Remarks: Checks whether the document is a portfolio document or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_BOOL IsPortfolio(FPD_Document doc);

	//************************************
	// Function:  RemoveUR3
	// Param[in]: doc	The input PDF document.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Removes the UR3 signature.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	//************************************
	static FS_BOOL RemoveUR3(FPD_Document doc);

	//************************************
	// Function:  AddFXFont
	// Param[in]: doc		The input PDF document.
	// Param[in]: pFXFont	The input Foxit GE font object.
	// Param[in]: charset	The input Charset ID.
	// Param[in]: bVert		Whether it's a vertical writing font. For CJK charsets only.
	// Return: The PDF font object.
	// Remarks: Adds the Foxit GE font to the PDF document. It will return a PDF font object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.0.0
	//************************************
	static FPD_Font AddFXFont(FPD_Document doc, FPD_FXFont pFXFont, FS_INT32 charset, FS_BOOL bVert);

	//************************************
	// Function:  GetIndirectObjsCount
	// Param[in]: doc	The input PDF document.
	// Return: The indirect object count.
	// Remarks: Gets the indirect object count.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
	//************************************
	static FS_INT32 GetIndirectObjsCount(FPD_Document doc);

	//************************************
	// Function:  Save2
	// Param[in]: doc		The input document.
	// Param[in]: wStrfilename	The output file name,wide string type.
	// Param[in]: flags		The saving flags. You can set FPD_SAVE_DEFAULT by default.
	// Param[in]: bEnable	Whether to do data compressing.
	// Return:    Non-zero means success, otherwise failed.
	// Remarks:   Writes the whole document into a new file.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static FS_BOOL Save2(FPD_Document doc, FS_LPCWSTR wStrfilename, FS_DWORD flags, FS_BOOL bEnable);

	//************************************
	// Function:  InsertDocumentAtPos
	// Param[in]: doc				The input document.
	// Param[in]: index				The page index where the document will be inserted.
	// Param[in]: insertedDoc		The inserted document.
	// Param[in]: pBookmarkTitle	The input bookmark title. Set NULL as default.
	// Return:    TRUE means success, otherwise failed.
	// Remarks:   Inserts the document into the original document at the specified position.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.4.0
	//************************************
	static FS_BOOL InsertDocumentAtPos(FPD_Document doc, FS_INT32 index, FPD_Document insertedDoc, const FS_WCHAR* pBookmarkTitle);

	//************************************
	// Function:  MetadataGetAllCustomKeys
	// Param[in]: doc				The input document.
	// Param[out]: keys				All the custom keys in the info dictionary.
	// Return:  The number of all the custom keys.
	// Remarks: Get all custom keys in metadata.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_INT32 MetadataGetAllCustomKeys(FPD_Document doc, FS_WideStringArray keys);

	//************************************
	// Function:  MetadataDeleteCustomKey
	// Param[in]: doc				The input document.
	// Param[in]: wsItem			The custom keys to be deleted.
	// Return:  whether delete the custom key success.
	//			if the key is a standard key, return false.
	// Remarks: Delete special custom key in metadata.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_BOOL MetadataDeleteCustomKey(FPD_Document doc, const FS_WideString wsItem);

	//************************************
	// Function:  MetadataGetString
	// Param[in]: doc				The input document.
	// Param[in]: wsItem			The specified item to get.
	// Param[out]: wsStr			Receive content string of the item.
	// Param[out]: pbUseInfoOrXML	Whether to get the metadata string is using the info dictionary or the metadata stream.
	// Return: Whether get the string success. 0 for success.
	// Remarks: Get specific item string corresponding to document info or root entries.
	// Notes:	Metadata provides some application level information about document, such as author, title, creation time and others. <br>
	//			There are two ways to store these information in PDF file:
	//			<ul>
	//			<li> in "Info" dictionary in trail dictionary.</li>
	//			<li> in metadata stream(with XML format) in the "Catalog" dictionary. </li>
	//			</ul>
	//			Which information would be got depends on the information of modified date, which is defined in key "ModDate" in the "Info" dictionary and "MetadataDate" in XML.<br>	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_INT32 MetadataGetString(FPD_Document doc,
									  const FS_WideString wsItem,
									  FS_WideString wsStr,
									  FS_INT32 *pbUseInfoOrXML);

	//************************************
	// Function:  MetadataSetString
	// Param[in]: doc				The input document.
	// Param[in]: wsItem			The specified item to set.
	// Param[in]: wsStr				The content string of the item.
	// Param[in]: bUTF8				Whether the content string is saved as UTF-8 encoding or not in PDF.
	// Return: Whether set the string success.
	//		   For custom keys, if "wsStr" is NULL, return false.
	// Remarks: Set specific item string corresponding to specific item.
	// Notes:	Only the PDF2.0 supports for the UTF-8 Unicode character encoding scheme.
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_BOOL MetadataSetString(FPD_Document doc,
									const FS_WideString wsItem,
									const FS_WideString wsStr,
									FS_BOOL bUTF8);

	//************************************
	// Function:  MetadataSyncUpdate
	// Param[in]: doc				The input document.
	// Return:  whether update the metadata success.
	// Remarks: Preserve the consistency of the metadata string that is saved by the information dictionary or the metadata stream.
	//			Be called only after the edit operation : MetadataSetString.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7
	//************************************
	static FS_BOOL MetadataSyncUpdate(FPD_Document doc);
	

	//************************************
	// Function:  MetadataSetDateTime
	// Param[in]: doc				The input document.
	// Param[in]: wsItem			The specified item to set.
	//							    Currently it can be one of the followings : <br>
	//							    <ul>
	//							    <li>"CreationDate"< / li>
	//							    <li>"ModDate"< / li>
	//							    </ ul>
	// Param[in]: dt				data time.
	// Return:  return whether set the date time success.
	// Remarks: Set specific item string corresponding to specific item.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOLEAN		MetadataSetDateTime(FPD_Document doc, FS_WideString wsItem, const FPDCRT_DATETIMEZONE dt);
	
	 //************************************
	 // Function:  AddNewIndirectObject
	 // Param[in]: doc				The input document.
	 // Param[in]: object_type		The type of the object, one of the PDFOBJ_xxxx constants, except PDFOBJ_REFERENCE.
	 // Return:  A pdf object, it may be null when object's type is invalid.
	 // Remarks:Add an object to indirect object list. The new object is returned, only for direct object.
	 // Takes ownership of the object created internally, returns an unowned pdf object pointer.
	 // Notes:	
	 // Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	 //************************************
	static FPD_Object		AddNewIndirectObject(FPD_Document doc, FS_INT32 object_type);

	//************************************
	 // Function:  LoadPages
	 // Param[in]: doc				The input document.	
	 // Return:  void
	 // Remarks: Load pages of the document.
	 // Notes:	
	 // Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	 //************************************
	static void				LoadPages(FPD_Document doc);

	//************************************
	// Function:  MetadataGetRoot
	// Param[in]: doc				The input document.
	// Param[out]: outRoot			Get the XML root of the Metadata.
	// Return: FS_BOOL              TRUE: Get the XML root of the Metadata success.
	// Remarks: Get the XML root of the Metadata.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1
	//************************************
	static FS_XMLElement MetadataGetRoot(FPD_Document doc);
	
	//************************************
	// Function:  ConstructFromParser
	// Param[in]: pParser		The input document parser.
	// Return: FPD_Document     Construct document from a document parser.
	// Remarks: Construct from a document parser.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1
	//************************************
	static FPD_Document ConstructFromParser(FPD_Parser pParser);

	//************************************
	// Function:  MetadataGetRoot
	// Param[in]: doc				The input document.
	// Return: FS_XMLElement        Get the XML root of the Metadata.
	// Remarks: Get the XML root of the Metadata.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1
	//************************************
	static FS_BOOLEAN MetadataCreateNewMetadata(FPD_Document doc);

	//************************************
	// Function:  ReferenceIndirectObject
	// Param[in]: doc				The input document.
	// Param[in]: pIndirectObject	The input indirect object.
	// Return: FPD_Object           Return the referece object.
	// Remarks: Get the referece object of the indirect object.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1
	//************************************
	static FPD_Object ReferenceIndirectObject(FPD_Document doc, FPD_Object pIndirectObject);
	
	//************************************
	// Function:  MetadataGetRdfXMLString
	// Param[in]: stream				The input metedata stream.
	// Param[in]: wsNamespace		The XML namespace for the schema in which the property is to be found.
	// Param[in]: wsKey				The name of the desired simple property.
	// Param[out]: wsStr			Receive content string of the item.
	// Return: FS_BOOL             Whether get the string success. 0: for success.
	// Remarks: Get item string in Metadata XML stream.
	// Metadata provides some application level information about document, such as author, title, creation time and others.
	// In XMPSpecification part3 Table20 provide the mapping of PDF keys to XMP properties.These properties should get by function CPDF_Metadata::GetString.
	// Notes:	If the specific item key is not found, return FX_ERR_CODE_METADATA_NOTFOUND_KEY.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	//************************************
	static FS_BOOL MetadataGetRdfXMLString(FPD_Object stream, FS_LPCWSTR wsNamespace, FS_LPCWSTR wsKey, FS_WideString* wsStr);

	//************************************
	// Function:  CreateChunkFileStream
	// Param[in]: doc				The input document.	
	// Return: FS_FileStream       Create a Chunk-Based file stream.
	// Remarks: Create a Chunk-Based file stream.
	// Notes: Need to use FPDDocReleaseChunkFileStream to release stream.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	//************************************
	static FS_FileStream CreateChunkFileStream(FPD_Document doc);

	//************************************
	// Function:  ReleaseChunkFileStream
	// Param[in]: chunkFileStream	The input chunk file stream.
	// Return: FS_FileStream        Release Chunk-Based file stream.
	// Remarks: Release Chunk-Based file stream.
	// Notes: Need to use FPDDocReleaseChunkFileStream to release stream.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	//************************************
	static void ReleaseChunkFileStream(FS_FileStream chunkFileStream);

	//************************************
	// Function:  BuildResourceList
	// Param[in]: doc	A PDF document.
	// Param[in]: type	The name of specified type.
	// Param[out]:arr	It will receive all resource objects of specified type in the document.
	// Param[in]:bEnumDRResource	Whether to enum resources of the DR dictory，which in the catalog dictory. Default is true.
	// Return:    void
	// Remarks:   Build a list of all resources of specified type in this document. On return,
	//            the array contains pointers to FPD_Object objects.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	//************************************
	static void	BuildResourceList2(FPD_Document doc, const FS_CHAR* type, FS_PtrArray arr, FS_BOOLEAN bEnumDRResource);
	
	//************************************
	// Function:  SetFileVersion
	// Param[in]: doc	          The input chunk file stream.
	// Param[in]: fileVersion	  The file version.
	// Return: FS_BOOLEAN        It will return false if the file version is out of range or smaller than
	//		                      the right file version which is modified for new features.
	// Remarks: Set the document file version, which will affect the creator's file version.
	// Call it when add any new feature which is introduced in later PDF specification.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static FS_BOOLEAN	SetFileVersion(FPD_Document doc, FS_INT32 fileVersion);
	
	//************************************
    // Function:  GetFileVersion
	// Param[in]: doc	          The input chunk file stream.
	// Return: FS_INT32         Get file version.
	// Remarks: Get the document file version.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static FS_INT32		GetFileVersion(FPD_Document doc);

	//************************************
	// Function:  GetAllRdfXMLKeys
	// Param[in]: doc	          The input chunk file stream.
	// Param[in/out]: keys	      All the namespace:key pairs in RDF XML, the format in array is namespace:key.
	// Return: FS_INT32         The number of all the custom keys.	-1 for error.
	// Remarks: Get all namespace:key pairs in RDF XML.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static FS_INT32  GetAllRdfXMLKeys(FPD_Document doc, FS_WideStringArray* keys);
	
	//************************************
	// Function:  CountDeveloperExtensions
	// Param[in]: doc	          A PDF document.
	// Param[in]: bsPrefixName	  The prefixname of extensions dictionary.	
	// Return: FS_INT32         The Count of developer extensions.
	// Remarks: Count the developer extensions dictionary under the bsPrefixName dictionary, only for pdf 2.0.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	//************************************
	static FS_INT32 CountDeveloperExtensions(FPD_Document doc, FS_LPCSTR bsPrefixName);
	
	//************************************
	// Function:  GetDeveloperExtensions
	// Param[in]: doc	          A PDF document.
	// Param[in]: bsPrefixName	  The prefixname of extensions dictionary.
	// Param[in]: index			  The index of extensions dictionary.
	// Return: FPD_Object         The developer extensions dictionary.
	// Remarks:  Get the developer extensions dictionary, only for pdf 2.0.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	//************************************
	static FPD_Object GetDeveloperExtensions(FPD_Document doc, FS_LPCSTR bsPrefixName, FS_INT32 index);
	
	//************************************
	// Function:  GetDestNameTree
	// Param[in]: doc	          A PDF document.
	// Return: FPD_NameTree       Get the destination name tree which build on the document.
	// Remarks:  Get the destination name tree which build on the document.
	// The nameTree cache data may be subject to external changes,
	// Calling the reload method when the nametree is changed externally
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	//************************************
	static FPD_NameTree GetDestNameTree(FPD_Document doc);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*								 CFPD_NameTree_V1				                    */
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_NameTree_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: rootDict	The root dictionary for the name tree (See Ref Table 3.28).
	// Return:    A name tree object from a root dictionary.
	// Remarks:   Creates a name tree object from a root dictionary.
	// Notes:
	//************************************
	static FPD_NameTree	New(FPD_Object rootDict);

	//************************************
	// Function:  New2	
	// Param[in]: doc			The PDF document.
	// Param[in]: szCategory	The category key name for name tree, like "Dests", "AP", etc. (See Ref Table 3.28).
	// Return:    A name tree object from a root dictionary.
	// Remarks:   Creates a name tree object from a root dictionary.
	// Notes:
	//************************************
	static FPD_NameTree	New2(FPD_Document doc, FS_LPCSTR szCategory);

	//************************************
	// Function:  Destroy	
	// Param[in]: nameTree	A name tree object created by FPDNameTreeNew or FPDNameTreeNew2.
	// Return:    void
	// Remarks:   Destroys a name tree object created by FPDNameTreeNew or FPDNameTreeNew2.
	// Notes:
	//************************************
	static void	Destroy(FPD_NameTree nameTree);
	
	//************************************
	// Function:  LookupValue	
	// Param[in]: nameTree		A name tree object.
	// Param[in]: index			The zero-based index of entry value.
	// Param[out]:outName		The name to be searched.
	// Return:    The value of specified entry of the found PDF name tree node.
	// Remarks:   Lookup a PDF name tree node by index that contains the name, and return specified entry value.
	// Notes:
	//************************************
	static FPD_Object LookupValue(FPD_NameTree nameTree, FS_INT32 index, FS_WideString* outName);

	//************************************
	// Function:  LookupValueByName	
	// Param[in]: nameTree	A name tree object.
	// Param[in]: wszName	The name to be searched.
	// Return:    The value of specified entry of the found PDF name tree node.
	// Remarks:   Lookup a PDF name tree node that contains the name, and return specified entry value.
	// Notes:
	//************************************
	static FPD_Object LookupValueByName(FPD_NameTree nameTree, FS_LPCWSTR wszName);

	//************************************
	// Function:  LookupNamedDest	
	// Param[in]: nameTree	A name tree object.
	// Param[in]: doc		The document.
	// Param[in]: szName	The input name.
	// Return:    The corresponding destination.
	// Remarks:   Lookup PDF name destination.
	// Notes:
	//************************************
	static FPD_Object LookupNamedDest(FPD_NameTree nameTree, FPD_Document doc, FS_LPSTR szName);

	//************************************
	// Function:  SetValue	
	// Param[in]: nameTree	A name tree object.
	// Param[in]: doc		The document.
	// Param[in]: szKey		The key is entry in the names dictionary.
	// Param[in]: wszName	The name to be searched.
	// Param[in]: value		The input entry value.
	// Return:    The index of the set value
	// Remarks:   Sets the entry value of specified PDF name tree node that contains specified name.
	// Notes:
	// Deprecated: Internal use. Suggest use FPDNameTreeSetValue2.
	//************************************
	static FS_INT32	SetValue(FPD_NameTree nameTree, FPD_Document doc, FS_LPCSTR szKey, FS_LPCWSTR wszName, FPD_Object value);

	//************************************
	// Function:  GetIndex	
	// Param[in]: nameTree	A name tree object.
	// Param[in]: wszName	The name to be searched.
	// Return:    The index of the name If found csName. otherwise return -1. 
	// Remarks:   Gets index of the name in name tree.
	// Notes:
	//************************************
	static FS_INT32	GetIndex(FPD_NameTree nameTree, FS_LPCWSTR wszName);

	//************************************
	// Function:  Remove	
	// Param[in]: nameTree	A name tree object.
	// Param[in]: index		The zero-based index of entry value.
	// Param[in]: wszName	The name to be searched.
	// Return:    The value nonzero if successful, otherwise 0.
	// Remarks:   Removes the name and entry value by nIndex in name tree, if csName is empty. otherwise ignore nIndex.
	// Notes:
	//************************************
	static FS_BOOL Remove(FPD_NameTree nameTree, FS_INT32 index, FS_LPCWSTR wszName);

	//************************************
	// Function:  GetCount	
	// Param[in]: nameTree	A name tree object.
	// Return:    The number of key-value pairs.
	// Remarks:   Gets the number of key-value pairs in name tree.
	// Notes:
	//************************************
	static FS_INT32	GetCount(FPD_NameTree nameTree);

	//************************************
	// Function:  GetRoot	
	// Param[in]: nameTree	A name tree object.
	// Return:    The root dictionary of the tree.
	// Remarks:   Gets the root dictionary of the tree.
	// Notes:
	//************************************
	static FPD_Object GetRoot(FPD_NameTree nameTree);
	
	//************************************
	// Function:  LookupValue2	
	// Param[in]: nameTree	A name tree object.
	// Param[in]: csName	The name to be searched.
	// Return:  FPD_Object  The value of specified entry of the found PDF name tree node.
	// Remarks:   Lookup a PDF name tree node that contains the name, and return specified entry value.
	// Notes:
	//************************************
	static FPD_Object	LookupValue2(FPD_NameTree nameTree, FS_ByteString csName);

	//************************************
	// Function:  New3	
	// Param[in]: dict			The dictionary which the name tree will be set to, like "Names", "StructTreeRoot" dictionary, etc.
	// Param[in]: szCategory	The category key name for name tree, like "Dests", "AP", etc. (See Ref Table 3.28).
	// Return:    A name tree object from a root dictionary.
	// Remarks:   Creates a name tree object from a root dictionary.
	// Notes:
	//************************************
	static FPD_NameTree	New3(FPD_Object dict, FS_LPCSTR szCategory);

	//************************************
	// Function:  SetValue2	
	// Param[in]: nameTree	A name tree object.
	// Param[in]: doc		The document.
	// Param[in]: szKey		The key is entry in the names dictionary.
	// Param[in]: wszName	The name to be searched.
	// Param[in]: value		The input entry value.
	// Return:    The index of the set value
	// Remarks:   Sets the entry value of specified PDF name tree node that contains specified name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static FS_INT32	SetValue2(FPD_NameTree nameTree, FPD_Document doc, FS_LPCSTR szKey,  FPD_Object value);
	
	//************************************
	// Function:  Reload	
	// Param[in]: nameTree		A name tree object.
	// Return:    true: Reload success, otherwise reload fail.
	// Remarks:   Reload NameInfo to cache.
	// If other nametree objects in the same document undergo changes such as addition or deletion,
	// this method needs to be called.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	//************************************
	static FS_BOOLEAN Reload(FPD_NameTree nameTree);
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_Bookmark_V1		                    */
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_Bookmark_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: outlineDict	The input outline item dictionary.
	// Return:    A PDF Bookmark object
	// Remarks:   Creates a PDF Bookmark object from a outline item dictionary.
	// Notes:
	//************************************
	static FPD_Bookmark	New(FPD_Object outlineDict);

	//************************************
	// Function:  Destroy
	// Param[in]: bookmark	A PDF Bookmark object created by FPDBookmarkNew.
	// Return:    void
	// Remarks:   Destroys a PDF Bookmark object created by FPDBookmarkNew.
	// Notes:
	//************************************
	static void	Destroy(FPD_Bookmark bookmark);

	//************************************
	// Function:  IsVaild
	// Param[in]: bookmark The input bookmark.
	// Return:    <a>TRUE</a> for being valid.
	// Remarks:   Tests wWhether the bookmark is valid.
	// Notes:
	//************************************
	static FS_BOOL IsVaild(FPD_Bookmark bookmark);


	//************************************
	// Function:  GetColorRef
	// Param[in]: bookmark The input bookmark.
	// Return:    The color of a bookmark.
	// Remarks:   Gets the color of a bookmark. In Windows FS_COLORREF format: 0x00ggbbrr.
	// Notes:
	//************************************
	static FS_DWORD	GetColorRef(FPD_Bookmark bookmark);


	//************************************
	// Function:  GetFontStyle
	// Param[in]: bookmark The input bookmark.
	// Return:    The font style of a bookmark.
	// Remarks:   Gets the font style of a bookmark. Italic and/or bold.
	// Notes:
	//************************************
	static FS_DWORD	GetFontStyle(FPD_Bookmark bookmark);

	//************************************
	// Function:  GetTitle
	// Param[in]: bookmark The input bookmark.
	// Param[out]:outTitle It receives the title of a bookmark.
	// Return:    void
	// Remarks:   Gets the title of a bookmark. A unicode encoded string is returned.
	// Notes:
	//************************************
	static void	GetTitle(FPD_Bookmark bookmark, FS_WideString* outTitle);


	//************************************
	// Function:  GetDest
	// Param[in]: bookmark  The input bookmark.
	// Param[in]: doc		The input PDF document.
	// Param[out]:outDest	A PDF destination object.
	// Return:    void
	// Remarks:   Gets the destination of a bookmark.
	// Notes:
	//************************************
	static void GetDest(FPD_Bookmark bookmark, FPD_Document doc, FPD_Dest* outDest);

	//************************************
	// Function:  GetAction
	// Param[in]: bookmark		The input bookmark.
	// Param[out]:outAction		It receives the PDF action of a bookmark.
	// Return:    void
	// Remarks:   Gets the PDF action of a bookmark.
	// Notes:
	//************************************
	static void GetAction(FPD_Bookmark bookmark, FPD_Action* outAction);

	//************************************
	// Function:  GetDictionary
	// Param[in]: bookmark The input bookmark.
	// Return:    The outline item dictionary.
	// Remarks:	  Gets the outline item dictionary.
	// Notes:
	//************************************
	static FPD_Object GetDictionary(FPD_Bookmark bookmark);


	//************************************
	// Function:  GetFirstChild
	// Param[in]: doc				The input PDF document.
	// Param[in]: parent			The input parent bookmark.
	// Param[out]:outFirstChild		The first child bookmark.
	// Return:    <a>TRUE</a> if the child bookmark exist,otherwise <a>FALSE</a>.
	// Remarks:   Gets the first child bookmark of specified parent bookmark.
	//            If <param>pParent</param> is <a>NULL</a>, gets top level items.
	// Notes:
	//************************************
	static FS_BOOL	 GetFirstChild(FPD_Document doc, FPD_Bookmark parent, FPD_Bookmark* outFirstChild);

	//************************************
	// Function:  GetNextSibling
	// Param[in]: doc				The input PDF document.
	// Param[in]: bookmark			The input bookmark.
	// Param[out]:outNextSibling	The next sibling bookmark.
	// Return:    <a>TRUE</a> if the next sibling bookmark exist, otherwise <a>FALSE</a>.
	// Remarks:   Gets the next sibling bookmark of specified bookmark in the same level.
	// Notes:	
	//************************************
	static FS_BOOL	 GetNextSibling(FPD_Document doc, FPD_Bookmark bookmark, FPD_Bookmark* outNextSibling);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_Dest_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_Dest_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: obj	The input PDF object.
	// Return:    A PDF destination object
	// Remarks:   Creates a PDF destination object from a PDF object.
	// Notes:
	//************************************
	static FPD_Dest	New(FPD_Object obj);

	//************************************
	// Function:  Destroy
	// Param[in]: dest The input PDF destination object.
	// Return:    void
	// Remarks:   Destroys a PDF destination object.
	// Notes:
	//************************************
	static void	Destroy(FPD_Dest dest);
	
	//************************************
	// Function:  GetRemoteName
	// Param[in]: dest			A PDF destination object.
	// Param[out]:pStrResult	It receives the remote name of named destination.
	// Return:    void
	// Remarks:   Gets the remote name of named destination.
	// Notes:
	//************************************
	static void	GetRemoteName(FPD_Dest dest, FS_ByteString* pStrResult);

	//************************************
	// Function:  GetPageIndex
	// Param[in]: doc	The PDF document.
	// Param[in]: dest	A PDF destination object.
	// Return:    The zero-based index of the page referred to.
	// Remarks:   Gets zero-based index of the page in the document.
	// Notes:
	//************************************
	static FS_INT32	GetPageIndex(FPD_Document doc, FPD_Dest dest);

	//************************************
	// Function:  GetPageObjNum
	// Param[in]: dest	A PDF destination object.
	// Param[in]: pDoc	The input document.
	// Return:    The object number of the page.
	// Remarks:   Gets the object number of the page.
	// Notes:
	//************************************
	static FS_DWORD	GetPageObjNum(FPD_Dest dest, FPD_Document pDoc);

	//************************************
	// Function:  GetZoomMode
	// Param[in]: dest	A PDF destination object.
	// Return:    The zoom mode of the destination.
	// Remarks:   Gets the zoom mode of the destination.
	// Notes:
	//************************************
	static FS_INT32	GetZoomMode(FPD_Dest dest);

	//************************************
	// Function:  GetParam
	// Param[in]: dest		A PDF destination object.
	// Param[in]: index		The zero-based index of the param.
	// Return:    The param by index.
	// Remarks:   Gets a param.
	// Notes:
	//************************************
	static double GetParam(FPD_Dest dest, FS_INT32 index);

	//************************************
	// Function:  GetPDFObject
	// Param[in]: dest		A PDF destination object.
	// Param[out]: pObject	It receives the PDF object of the destination.
	// Return:    void
	// Remarks:   Gets the PDF object of the destination.
	// Notes:
	//************************************
	static void GetPDFObject(FPD_Dest dest, FPD_Object* pObject);

	//************************************
	// Function:  CheckObjectIsNull
	// Param[in]: dest		A PDF destination object.
	// Return:    FS_BOOL
	// Remarks:  Check pdf object is null.
	// Notes:
	//************************************
	static FS_BOOL CheckObjectIsNull(FPD_Dest dest);

	//************************************
	// Function:  GetPDFObject
	// Param[in]: dest		A PDF destination object.
	// Param[out]: pObject	It receives the PDF object of the destination.
	// Return:    void
	// Remarks:   Gets the PDF object of the destination.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static FPD_Object GetPDFObject2(FPD_Dest dest);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_OCContext_V1											*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_OCContext_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: doc		The input PDF document.
	// Param[in]: UsageType	The intended usage type of optional content.
	// Return:    An optional content context.
	// Remarks:	  Creates optional content context from a PDF document.
	// Notes:
	//************************************
	static FPD_OCContext New(FPD_Document doc, FPD_OCC_UsageType UsageType);

	//************************************
	// Function:  Destroy
	// Param[in]: occ	Optional content context.
	// Return:    void
	// Remarks:   Destroys optional content context.
	// Notes:
	//************************************
	static void	Destroy(FPD_OCContext occ);
	
	//************************************
	// Function:  GetDocument
	// Param[in]: occ	The input optional content context.
	// Return:    The PDF document in the optional content context.
	// Remarks:   Gets the PDF document in the optional content context.
	// Notes:
	//************************************
	static FPD_Document	GetDocument(FPD_OCContext occ);

	//************************************
	// Function:  GetUsageType
	// Param[in]: occ The input optional content context.
	// Return:    The usage type of optional content.
	// Remarks:   Gets the usage type of optional content.
	// Notes:
	//************************************
	static FS_INT32	GetUsageType(FPD_OCContext occ);

	//************************************
	// Function:  CheckOCGVisible
	// Param[in]: occ		The input optional content context.
	// Param[in]: OCGDict	The optional content group dictionary.
	// Return:    <a>TRUE</a> for being visible.
	// Remarks:   Checks whether the optional content group is visible or not.
	// Notes:
	//************************************
	static FS_BOOL CheckOCGVisible(FPD_OCContext occ, const FPD_Object OCGDict);

	//************************************
	// Function:  ResetOCContext
	// Param[in]: occ The input optional content context.
	// Return:    void
	// Remarks:   Resets the optional content context.
	// Notes:
	//************************************
	static void	ResetOCContext(FPD_OCContext occ);	

	//************************************
	// Function:  SetOCGState
	// Param[in]: occ		The input optional content context.
	// Param[in]: ocgDict	The input OCG dictionary.
	// Param[in]: bState	The new state of the OCG.
	// Param[in]: bNotify	Whether to notify or not.
	// Return:    void
	// Remarks:   Resets the optional content context.
	// Notes:
	//************************************
	static void	SetOCGState(FPD_OCContext occ, FPD_Object ocgDict, FS_BOOL bState, FS_BOOL bNotify);

	//************************************
	// Function:  CheckObjectVisible
	// Param[in]: occ		The input optional content context.
	// Param[in]: pObj	    Page object.	
	// Return:    FS_BOOL  Non-zero means visible, otherwise invisible.
	// Remarks:   Check whether an object is visible in this context.
	// Notes:
	//************************************	
	static FS_BOOL CheckObjectVisible(FPD_OCContext occ, const FPD_PageObject pObj);

	//************************************
	// Function:  ConvertToFPDOCContextHandler
	// Param[in]: occ		The input optional content context.	
	// Return:    FPD_OCContextHandler  Convert FPD_OCContext to FPD_OCContextHandler object.
	// Remarks:   Convert FPD_OCContext to FPD_OCContextHandler object.
	// Notes:
	//************************************	
	static FPD_OCContextHandler ConvertToFPDOCContextHandler(FPD_OCContext occ);
	
	 //************************************
	 // Function:  MergeContext
	 // Param[in]: occ		    The input optional content context.	
	 // Param[in]: mergeocc		The input merge content context.	
	 // Return:    void
	 // Remarks:   Only OFF items in occ will be merged.
	 // Merge content from an optional content context. The method will not change the usage type.
	 // Notes:
	 //************************************	
	static void		MergeContext(FPD_OCContext occ, FPD_OCContext mergeocc);
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_OCGroup_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_OCGroup_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: dict	The input PDF dictionary.
	// Return:    Optional content group from a PDF dictionary.
	// Remarks:   Creates optional content group from a PDF dictionary.
	// Notes:
	//************************************
	static FPD_OCGroup New(FPD_Object dict);

	//************************************
	// Function:  Destroy
	// Param[in]: ocg	Optional content group.
	// Return:    void
	// Remarks:   Destroys optional content group;
	// Notes:
	//************************************
	static void	Destroy(FPD_OCGroup ocg);


	//************************************
	// Function:  GetName
	// Param[in]: ocg		Optional content group.
	// Param[out]:outName	It will receive the name of the OCG.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Gets the name of the OCG.
	// Notes:
	//************************************
	static FS_BOOL GetName(FPD_OCGroup ocg, FS_WideString* outName);

	//************************************
	// Function:  SetName
	// Param[in]: ocg		Optional content group.
	// Param[in]: wszName	The new OCG name.
	// Return:    void
	// Remarks:   Sets the name of the OCG.
	// Notes:
	//************************************
	static void	SetName(FPD_OCGroup ocg, FS_LPCWSTR wszName);


	//************************************
	// Function:  HasIntent
	// Param[in]: ocg		Optional content group.
	// Param[in]: szIntent	The input intent.
	// Return:    Whether the OCG has the specified intent or not.
	// Remarks:   Does the OCG have the specified intent?
	// Notes:
	//************************************
	static FS_BOOL HasIntent(FPD_OCGroup ocg, FS_LPCSTR szIntent);


	//************************************
	// Function:  GetCreatorInfo
	// Param[in]: ocg				Optional content group.
	// Param[out]:outWstrCreator	It receives that specifies the application that created the group.
	// Param[out]:outStrType		It receives that specifies the type of content controlled by the group.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   CreatorInfo entry of optional content usage dictionary.
	// Notes:
	//************************************
	static FS_BOOL GetCreatorInfo(FPD_OCGroup ocg, FS_WideString* outWstrCreator, FS_ByteString* outStrType);

	//************************************
	// Function:  GetLanguageInfo
	// Param[in]: ocg			Optional content group.
	// Param[out]:outInfo		It receives that specifies a language and possibly a locale.
	// Param[out]:outPrefered	It receives whether the language is a preferred language.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Language entry of optional content usage dictionary.
	// Notes:
	//************************************
	static FS_BOOL GetLanguageInfo(FPD_OCGroup ocg, FS_ByteString* outInfo, FS_BOOL* outPrefered);

	//************************************
	// Function:  GetExportState
	// Param[in]: ocg	Optional content group.
	// Return:    The export state of the OCG.
	// Remarks:   Gets the export state of the OCG. Exports entry of optional content usage dictionary.
	// Notes:
	//************************************
	static FS_BOOL GetExportState(FPD_OCGroup ocg);

	//************************************
	// Function:  GetZoomRange
	// Param[in]: ocg		Optional content group.
	// Param[out]:outMin	It receives the minimum recommended magnification factor. 
	// Param[out]:outMax	It receives the maximum recommended magnification factor
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Gets zoom entry of optional content usage dictionary.
	// Notes:
	//************************************
	static FS_BOOL GetZoomRange(FPD_OCGroup ocg, FS_FLOAT* outMin, FS_FLOAT* outMax);

	//************************************
	// Function:  GetPrintInfo
	// Param[in]: ocg		Optional content group.
	// Param[out]:outType	It receives that specifies the kind of content controlled by the group.
	// Param[out]:outState	It receives the printing state of OCG.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Gets print entry of optional content usage dictionary.
	// Notes:
	//************************************
	static FS_BOOL GetPrintInfo(FPD_OCGroup ocg, FS_ByteString* outType, FS_BOOL* outState);

	//************************************
	// Function:  GetViewState
	// Param[in]: ocg	Optional content group.
	// Return:    The view state of the OCG.
	// Remarks:   Gets the view state of the OCG. View entry of optional content usage dictionary.
	// Notes:
	//************************************
	static FS_BOOL GetViewState(FPD_OCGroup ocg);

	//************************************
	// Function:  GetUserType
	// Param[in]: ocg			Optional content group.
	// Param[out]:outType		It receives the user type of whom this OCG is primarily intended.
	// Param[out]:outUserArr	It receives a string that represents the name(s) of the individual, position or organization.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   User entry of optional content usage dictionary.
	// Notes:
	//************************************
	static FS_BOOL GetUserType(FPD_OCGroup ocg, FS_ByteString* outType, FS_WideStringArray* outUserArr);

	//************************************
	// Function:  GetPageElementType
	// Param[in]: ocg		Optional content group.
	// Param[out]:outName	It receives the page element type.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Gets PageElement entry of optional content usage dictionary.
	// Notes:
	//************************************
	static FS_BOOL GetPageElementType(FPD_OCGroup ocg, FS_ByteString* outName);	

	//************************************
	// Function:  GetDictionary
	// Param[in]: ocg		Optional content group.
	// Return:    The OCG dictionary.
	// Remarks: Get the OCG dictionary.
	// Notes:
	//************************************
	static FPD_Object GetDictionary(FPD_OCGroup ocg);	
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_OCGroupSet_V1							*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_OCGroupSet_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: obj	A PDF object.
	// Return:    An optional content group set.
	// Remarks:   Creates optional content group set from a PDF object.
	// Notes:
	//************************************
	static FPD_OCGroupSet New(FPD_Object obj);

	//************************************
	// Function:  Destroy
	// Param[in]: ocgs	Optional content group set.
	// Return:    void
	// Remarks:   Destroys optional content group set.
	// Notes:
	//************************************
	static void	Destroy(FPD_OCGroupSet ocgs);
	
	//************************************
	// Function:  CountElements
	// Param[in]: ocgs	Optional content group set.
	// Return:    The count of elements in the OCG set.
	// Remarks:   Gets the count of elements in the OCG set.
	// Notes:
	//************************************
	static FS_INT32	CountElements(FPD_OCGroupSet ocgs);

	//************************************
	// Function:  IsSubGroupSet
	// Param[in]: ocgs		Optional content group set.
	// Param[in]: index		The input zero-based element in the array.
	// Return:    Non-zero means a subgroup, otherwise not.
	// Remarks:   Checks whether the specified element is a subgroup or not.
	// Notes:
	//************************************
	static FS_BOOL IsSubGroupSet(FPD_OCGroupSet ocgs, FS_INT32 index);

	//************************************
	// Function:  GetGroup
	// Param[in]: ocgs		Optional content group set.
	// Param[in]: index		The input zero-based element in the array.
	// Param[out]:pOCGroup	It receives the optional content group.
	// Return:    void
	// Remarks:   Gets a OCG from specified position.
	// Notes:
	//************************************
	static void GetGroup(FPD_OCGroupSet ocgs, FS_INT32 index, FPD_OCGroup* pOCGroup);

	//************************************
	// Function:  GetSubGroupSet
	// Param[in]: ocgs			Optional content group set.
	// Param[in]: index			The input zero-based element in the array.
	// Param[out]:pOCGroupSet	It receives the optional content group set.
	// Return:    void
	// Remarks:   Gets a OCG set from specified position.
	// Notes:
	//************************************
	static void	GetSubGroupSet(FPD_OCGroupSet ocgs, FS_INT32 index, FPD_OCGroupSet* pOCGroupSet);

	//************************************
	// Function:  FindGroup
	// Param[in]: ocgs			Optional content group set.
	// Param[in]: groupDict		The input OCG dictionary.
	// Return:    The zero-based index in the array.
	// Remarks:   Finds a OCG in the array.
	// Notes:
	//************************************
	static FS_INT32	FindGroup(FPD_OCGroupSet ocgs, const FPD_Object groupDict);

	//************************************
	// Function:  GetSubGroupSetName
	// Param[in]: ocgs		Optional content group set.
	// Param[out]:outName	It receives the name of the OCG set.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Gets the group set name.
	// Notes:
	//************************************
	static FS_BOOL GetSubGroupSetName(FPD_OCGroupSet ocgs, FS_WideString* outName);

    //************************************
    // Function:  GetArray
    // Param[in]: ocgs	Optional content group set.
    // Return:    The Optional content group set array.
    // Remarks:   Gets the Optional content group set array.
    // Notes:
    //************************************
    static FPD_Object GetArray(FPD_OCGroupSet ocgs);

};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_OCProperties_V1						*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef _FPDFAPI_MINI_
class IPDF_OCNotify{};
class CPDF_OCGroup{};
#endif

class CFPD_CustomerOCNotifyHandler : public IPDF_OCNotify, public CFX_Object
{
public:
	CFPD_CustomerOCNotifyHandler(FPD_OCGStateChangedNotify lpProc);
	void	OnOCGStateChanged(CPDF_Document* pDoc, CPDF_OCGroup ocg, FX_BOOL bVisible);

	FPD_OCGStateChangedNotify m_lpProc;

};

class CFPD_OCNotify_V1
{
public:
	//************************************
	// Function:  FPD_OCNotifyNew
	// Param[in]: proc A callback for Optional Content Notification FPD_OCNotify object.
	// Return:    The OC notify interface.
	// Remarks:   Creates a new OC notify interface.
	// Notes:
	//************************************
	static FPD_OCNotify	FPD_OCNotifyNew(FPD_OCGStateChangedNotify proc);

	//************************************
	// Function:  FPD_OCNotifyDestroy
	// Param[in]: notify The OC notify interface.
	// Return:    void
	// Remarks:   Destroys the OC notify interface.
	// Notes:
	//************************************
	static void	FPD_OCNotifyDestroy(FPD_OCNotify notify);
};

class CFPD_OCProperties_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: doc	The input PDF document.
	// Return:    Optional content properties.
	// Remarks:   Creates optional content properties from a PDF document.
	// Notes:
	//************************************
	static FPD_OCProperties	New(FPD_Document doc);

	//************************************
	// Function:  Destroy
	// Param[in]: ocprops	Optional content properties.
	// Return:    void
	// Remarks:   Destroys optional content properties.
	// Notes:
	//************************************
	static void	Destroy(FPD_OCProperties ocprops);
	
	//************************************
	// Function:  GetDocument
	// Param[in]: ocprops	Optional content properties.
	// Return:    The PDF document.
	// Remarks:	  Gets the PDF document.
	// Notes:
	//************************************
	static FPD_Document	GetDocument(FPD_OCProperties ocprops);

	//************************************
	// Function:  GetOCGroups
	// Param[in]: ocprops		Optional content properties.
	// Param[out]:arrOCGs		It receives all OCG objects in specified page.
	// Param[in]: page_index	The input zero-based page index.
	// Return:    The number of OCG retrieved.
	// Remarks:   Retrieves all OCG objects for a document or a page.
	//            If iPageIndex equals to -1, all document level OCG objects are returned; 
	//            or all page level OCG objects are returned.
	// Notes:
	//************************************
	static FS_INT32	GetOCGroups(FPD_OCProperties ocprops, FS_PtrArray* arrOCGs, FS_INT32 page_index);

	//************************************
	// Function:  IsOCGroup
	// Param[in]: ocprops	Optional content properties.
	// Param[in]: dict		The input PDF dictionary.
	// Return:    Non-zero means valid, otherwise invalid.
	// Remarks:   Determines whether a dictionary object is a valid OCG object.
	// Notes:
	//************************************
	static FS_BOOL IsOCGroup(FPD_OCProperties ocprops, const FPD_Object dict);

	//************************************
	// Function:  RetrieveOCGPages
	// Param[in]: ocprops		Optional content properties.
	// Param[in]: dict			The input OCG dictionary.
	// Param[out]:arrPages		It receives all page dictionaries in which the specified OCG is referenced.
	// Return:    The number of pages referenced.
	// Remarks:   Retrieves all pages objects in which the specified pOCGDict is referenced.
	//            One OCG can be shared by several pages. pages is an array of page dictionary objects.
	//            The returned value is the count of the elements in pages array.
	// Notes:
	//************************************
	static FS_INT32	RetrieveOCGPages(FPD_OCProperties ocprops, const FPD_Object dict, FS_PtrArray* arrPages);
	
	//************************************
	// Function:  IsOCGInPage
	// Param[in]: ocprops		Optional content properties.
	// Param[in]: page_dict		The input page dictionary.
	// Param[in]: ocg_dict		The input OCG dictionary.
	// Return:    Non-zero means in the page, otherwise not.
	// Remarks:   Determines whether a OCG object is in a page or not.
	// Notes:
	//************************************
	static FS_BOOL IsOCGInPage(FPD_OCProperties ocprops, const FPD_Object page_dict, FPD_Object ocg_dict);

	//************************************
	// Function:  GetOCGroupOrder
	// Param[in]: ocprops			Optional content properties.
	// Param[out]:pOCGroupSet		It receives the OCG set.
	// Return:    void
	// Remarks:   Orders entry in optional content configuration dictionary.
	//            All document level OCG objects can be stored in an ordered tree object, this will be showed in UI.
	// Notes:
	//************************************
	static void GetOCGroupOrder(FPD_OCProperties ocprops, FPD_OCGroupSet* pOCGroupSet);




	//************************************
	// Function:  CountConfigs
	// Param[in]: ocprops	Optional content properties.
	// Return:    The count of configuration dictionaries in the OCP.
	// Remarks:   Gets the count of configuration dictionaries in the OCP.
	// Notes:
	//************************************
	static FS_INT32	CountConfigs(FPD_OCProperties ocprops);

	//************************************
	// Function:  GetConfig
	// Param[in]: ocprops	Optional content properties.
	// Param[in]: index		The input zero-based configuration dictionary index.
	// Return:    A configuration dictionary.
	// Remarks:   Gets a configuration dictionary in the OCP.
	// Notes:
	//************************************
	static FPD_Object GetConfig(FPD_OCProperties ocprops, FS_INT32 index);


	//************************************
	// Function:  AddOCNotify
	// Param[in]: ocprops				Optional content properties.
	// Param[in]: ocgNotifyCallback		The input user supplied notify interface to add.
	// Return:    void
	// Remarks:   Adds an user-supplied optional content notify interface to the OCP.
	// Notes:
	//************************************
	static void	AddOCNotify(FPD_OCProperties ocprops, FPD_OCNotify ocgNotifyCallback);

	//************************************
	// Function:  RemoveOCNotify
	// Param[in]: ocprops				Optional content properties.
	// Param[in]: ocgNotifyCallback		The input user supplied notify interface to remove.
	// Return:    void
	// Remarks:   Removes an user-supplied optional content notify interface from OCP.
	// Notes:
	//************************************
	static void	RemoveOCNotify(FPD_OCProperties ocprops, FPD_OCNotify ocgNotifyCallback);
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Actions
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*									CFPD_LWinParam_V1												*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_LWinParam_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: dict	The input PDF dictionary.
	// Return:    Windows launch Param.
	// Remarks:   Creates windows launch param from a PDF dictionary.
	// Notes:
	//************************************
	static FPD_LWinParam New(FPD_Object dict);

	//************************************
	// Function:  Destroy
	// Param[in]: param		Windows launch param.
	// Return:    void
	// Remarks:	  Destroys windows launch param.
	// Notes:
	//************************************
	static void	Destroy(FPD_LWinParam param);

	//************************************
	// Function:  GetFileName
	// Param[in]: param			Windows launch param.
	// Param[out]:outFileName	It receives the file name
	// Return:    void
	// Remarks:   Gets the file name of the the application to be launched or the document to be opened or printed.
	// Notes:
	//************************************
	static void	GetFileName(FPD_LWinParam param, FS_ByteString* outFileName);

	//************************************
	// Function:  SetFileName
	// Param[in]: param		Windows launch param.
	// Param[in]: szFile	The new file name.
	// Return:    void
	// Remarks:   Sets the file name in the windows launch param.
	// Notes:
	//************************************
	static void	SetFileName(FPD_LWinParam param, FS_LPSTR szFile);

	//************************************
	// Function:  GetDefaultDirectory
	// Param[in]: param				Windows launch param.
	// Param[out]:outDirectory		The default directory in standard DOS syntax.
	// Return:    void
	// Remarks:   Gets the default directory in standard DOS syntax.
	// Notes:
	//************************************
	static void	GetDefaultDirectory(FPD_LWinParam param, FS_ByteString* outDirectory);

	//************************************
	// Function:  SetDefaultDirectory
	// Param[in]: param			Windows launch param.
	// Param[in]: szDirectory	The new default directory.
	// Return:    void
	// Remarks:   Sets the default directory.
	// Notes:
	//************************************
	static void	SetDefaultDirectory(FPD_LWinParam param, FS_LPSTR szDirectory);

	//************************************
	// Function:  GetOperation
	// Param[in]: param				Windows launch param.
	// Param[out]:outOperation		It receives the operation to perform.
	// Return:    void
	// Remarks:   Gets the operation to perform.
	// Notes:
	//************************************
	static void	GetOperation(FPD_LWinParam param, FS_ByteString* outOperation);

	//************************************
	// Function:  SetOperation
	// Param[in]: param				Windows launch param.
	// Param[in]: szOperation		The new operation string.
	// Return:    void
	// Remarks:   Sets the operation ASCII string.
	// Notes:
	//************************************
	static void	SetOperation(FPD_LWinParam param, FS_LPSTR szOperation);

	//************************************
	// Function:  GetParam
	// Param[in]: param			Windows launch param.
	// Param[out]:outParam		It receives the param to be passed to the application designated by the F entry. 
	// Return:    void
	// Remarks:   Gets the param to be passed to the application designated by the F entry. 
	// Notes:
	//************************************
	static void	GetParam(FPD_LWinParam param, FS_ByteString* outParam);

	//************************************
	// Function:  SetParam
	// Param[in]: param			Windows launch param.
	// Param[in]: szParam		The new application params.
	// Return:    void
	// Remarks:   Sets the application Params.
	// Notes:
	//************************************
	static void	SetParam(FPD_LWinParam param, FS_LPSTR szParam);

	//************************************
	// Function:  GetDict
	// Param[in]: param			Windows launch param.
	// Return:    The windows launch param dictionary.
	// Remarks:   Gets the windows launch Param dictionary.
	// Notes:
	//************************************
	static FPD_Object GetDict(FPD_LWinParam param);

	//************************************
	// Function:  SetDict
	// Param[in]: param			Windows launch param.
	// Param[in]: pDict			Set the windows launch Param dictionary.
	// Return:    void.
	// Remarks:   Sets the windows launch Param dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void SetDict(FPD_LWinParam param, FPD_Object pDict);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*								 CFPD_ActionFields_V1												*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_ActionFields_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: action	The input PDF action.
	// Return:    PDF action fields.
	// Remarks:   Creates PDF action fields from a PDF action.
	// Notes:
	//************************************
	static FPD_ActionFields	New(FPD_Action action);

	//************************************
	// Function:  Destroy
	// Param[in]: actFields		The input PDF action fields.
	// Return:    void
	// Remarks:   Destroys PDF action fields.
	// Notes:
	//************************************
	static void	Destroy(FPD_ActionFields actFields);
	
	//************************************
	// Function:  GetFieldsCount
	// Param[in]: actFields		The input PDF action fields.
	// Return:    The count of action fields.
	// Remarks:   Gets the count of action fields.
	// Notes:
	//************************************
	static FS_DWORD	GetFieldsCount(FPD_ActionFields actFields);

	//************************************
	// Function:  GetAllFields
	// Param[in]: actFields			The input PDF action fields.
	// Param[out]:outFieldObjects	It receives all fields in the action dictionary.
	// Return:    void
	// Remarks:   Gets all fields in the action dictionary.
	//            outFieldObjects is an array of FPD_Object.
	// Notes:
	//************************************
	static void	GetAllFields(FPD_ActionFields actFields, FS_PtrArray* outFieldObjects);

	//************************************
	// Function:  GetField
	// Param[in]: actFields		The input PDF action fields.
	// Param[in]: index			The zero-based field index.
	// Return:    A PDF object.
	// Remarks:   Gets a field value.
	//			  returned object may be FPD_Object or FPD_String.
	// Notes:
	//************************************
	static FPD_Object GetField(FPD_ActionFields actFields, FS_DWORD index);

	//************************************
	// Function:  InsertField
	// Param[in]: actFields		The input PDF action fields.
	// Param[in]: iInsertAt		The zero-based field index to insert at.
	// Param[in]: field			The field value.
	// Return:    void
	// Remarks:	  Inserts a field.
	//            field: it can be FPD_Object or FPD_String object,
	//            if need insert field as name(string), construct name as FPD_String object
	// Notes:
	//************************************
	static void	InsertField(FPD_ActionFields actFields, FS_DWORD iInsertAt, const FPD_Object field);
	
	//************************************
	// Function:  RemoveField
	// Param[in]: actFields		The input PDF action fields.
	// Param[in]: index			The zero-based field index to be removed.
	// Return:    void
	// Remarks:   Removes a field from PDF action fields. 
	// Notes:
	//************************************
	static void	RemoveField(FPD_ActionFields actFields, FS_DWORD index);

	//************************************
	// Function:  GetAction
	// Param[in]: actFields		The input PDF action fields.
	// Return:    The PDF action dictionary.
	// Remarks:	  Gets the PDF action dictionary.
	// Notes:
	//************************************
	static FPD_Action GetAction(FPD_ActionFields actFields);
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_Action_V1												*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_Action_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: dict	The input PDF dictionary.
	// Return:    A PDF action.
	// Remarks:   Creates a PDF action from a PDF dictionary.
	// Notes:
	//************************************
	static FPD_Action New(FPD_Object dict);

	//************************************
	// Function:  New2
	// Param[in]: doc			The input PDF document.
	// Param[in]: actionType	The input action type.
	// Return:    A PDF action.
	// Remarks:   Creates a PDF action with specified action type.
	// Notes:
	//************************************
	static FPD_Action New2(FPD_Document doc, FPD_ActionType actionType);

	//************************************
	// Function:  New3
	// Param[in]: doc		The input PDF document.
	// Param[in]: szType	The input action type name.
	// Return:	  A PDF action.
	// Remarks:   Creates a PDF action with specified action type name.
	// Notes:
	//************************************
	static FPD_Action New3(FPD_Document doc, FS_LPSTR szType);

	//************************************
	// Function:  Destroy
	// Param[in]: action	A PDF action.
	// Return:    void
	// Remarks:   Destroys a PDF action.
	// Notes:
	//************************************
	static void	Destroy(FPD_Action action);

	//************************************
	// Function:  GetTypeName
	// Param[in]: action		A PDF action.
	// Param[out]:outTypeName	It receives the type name of the action.
	// Return:    void
	// Remarks:   Gets the type name of the action.
	// Notes:
	//************************************
	static void	GetTypeName(FPD_Action action, FS_ByteString* outTypeName);

	//************************************
	// Function:  GetType
	// Param[in]: action	A PDF action.
	// Return:    The type of the action.
	// Remarks:   Gets the type of the action.
	// Notes:
	//************************************
	static FS_INT32	GetType(FPD_Action action);

	//************************************
	// Function:  GetDest
	// Param[in]: action	A PDF action.
	// Param[in]: doc		The input PDF document.
	// Param[out]:outDest	A PDF destination.
	// Return:    void
	// Remarks:   Gets the destination.
	// Notes:
	//************************************
	static void GetDest(FPD_Action action, FPD_Document doc, FPD_Dest* outDest);

	//************************************
	// Function:  SetDest
	// Param[in]: action	A PDF action.
	// Param[in]: dest		Ref to a PDF destination.
	// Return:    void
	// Remarks:   Sets the destination.
	// Notes:
	//************************************
	static void	SetDest(FPD_Action action, const FPD_Dest dest);


	//************************************
	// Function:  GetFilePath
	// Param[in]: action	A PDF action.
	// Param[out]:outName	It receives the file full path.
	// Return:    void
	// Remarks:   Gets the file full path.
	// Notes:
	//************************************
	static void	GetFilePath(FPD_Action action, FS_WideString* outName);

	//************************************
	// Function:  SetFilePath
	// Param[in]: action		A PDF action.
	// Param[in]: wszFilePath	The input file full path.
	// Param[in]: bIsURL		Whether the file path is a URL or not.
	// Return:    void
	// Remarks:   Sets the file full path.
	// Notes:
	//************************************
	static void	SetFilePath(FPD_Action action, FS_LPCWSTR wszFilePath, FS_BOOL bIsURL);


	//************************************
	// Function:  GetNewWindow
	// Param[in]: action	A PDF action.
	// Return:    <a>TRUE</a> for opening the destination document in a new window.
	// Remarks:   Checks whether to open the destination document in a new window or not.
	// Notes:
	//************************************
	static FS_BOOL GetNewWindow(FPD_Action action);

	//************************************
	// Function:  SetNewWindow
	// Param[in]: action		A PDF action.
	// Param[in]: bNewWindow	The flag which identifies whether to open the destination document in a new window or not.
	// Return:    void
	// Remarks:   Sets the new window flag.
	// Notes:
	//************************************
	static void	SetNewWindow(FPD_Action action, FS_BOOL bNewWindow);


	//************************************
	// Function:  GetWinParam
	// Param[in]: action		A PDF action.
	// Param[out]:outWinParam	The windows launch params.
	// Return:    void
	// Remarks:   Gets the windows launch param.
	// Notes:
	//************************************
	static void GetWinParam(FPD_Action action, FPD_LWinParam* outWinParam);

	//************************************
	// Function:  SetWinParam
	// Param[in]: action	A PDF action.
	// Param[in]: param		Ref to a windows launch param object.
	// Return:    void
	// Remarks:   Sets the windows launch params.
	// Notes:
	//************************************
	static void	SetWinParam(FPD_Action action, const FPD_LWinParam param);


	//************************************
	// Function:  GetURI
	// Param[in]: action	A PDF action.
	// Param[in]: doc		The input PDF document.
	// Param[out]:outURL	It receives the URI.
	// Return:    void
	// Remarks:   Gets the URI(uniform resource identifier) of the PDF action.
	// Notes:
	//************************************
	static void	GetURI(FPD_Action action, FPD_Document doc, FS_ByteString* outURL);

	//************************************
	// Function:  SetURI	
	// Param[in]: action	A PDF action.
	// Param[in]: szURI		The input URI.
	// Return:    void
	// Remarks:   Sets the URI of the PDF action.
	// Notes:
	//************************************
	static void	SetURI(FPD_Action action, FS_LPSTR szURI);


	//************************************
	// Function:  GetMouseMap
	// Param[in]: action	A PDF action.
	// Return:    <a>TRUE</a> for tracking the mouse position when the URI is resolved.
	// Remarks:   Gets the flag which indicates whether to track the mouse position when the URI is resolved.
	// Notes:
	//************************************
	static FS_BOOL GetMouseMap(FPD_Action action);

	//************************************
	// Function:  SetMouseMap
	// Param[in]: action	A PDF action.
	// Param[in]: bMap		The new mouse-position-tracking flag.
	// Return:    void
	// Remarks:   Sets the mouse-position-tracking flag. 
	// Notes:
	//************************************
	static void	SetMouseMap(FPD_Action action, FS_BOOL bMap);


	//************************************
	// Function:  GetWidgets
	// Param[in]: action		A PDF action.
	// Param[out]:outWidgets	It receives the action fields.
	// Return:    void
	// Remarks:   Gets the fields array.
	// Notes:
	//************************************
	static void GetWidgets(FPD_Action action, FPD_ActionFields* outWidgets);


	//************************************
	// Function:  GetHideStatus
	// Param[in]: action	A PDF action.
	// Return:    The hide status of a PDF action.
	// Remarks:   Gets the hide status of a PDF action.
	// Notes:
	//************************************
	static FS_BOOL GetHideStatus(FPD_Action action);

	//************************************
	// Function:  SetHideStatus
	// Param[in]: action	A PDF action.
	// Param[in]: bHide		The input hide status.
	// Return:    void
	// Remarks:   Sets the hide status of a PDF action.
	// Notes:
	//************************************
	static void SetHideStatus(FPD_Action action, FS_BOOL bHide);


	//************************************
	// Function:  GetNameAction
	// Param[in]: action			A PDF action.
	// Param[out]:outNamedAction	It receives the name of named action.
	// Return:    void
	// Remarks:   Gets the name of named action.
	// Notes:
	//************************************
	static void GetNameAction(FPD_Action action, FS_ByteString* outNamedAction);

	//************************************
	// Function:  SetNameAction
	// Param[in]: action	A PDF action.
	// Param[in]: szName	The  input name of named action.
	// Return:    void
	// Remarks:   Sets the name of named action.
	// Notes:
	//************************************
	static void	SetNameAction(FPD_Action action, FS_LPCSTR szName);


	//************************************
	// Function:  GetFlags
	// Param[in]: action	A PDF action.
	// Return:    The flags for action type SubmitForm, ResetForm.
	// Remarks:   Gets the flags for action type SubmitForm, ResetForm.
	// Notes:
	//************************************
	static FS_DWORD	GetFlags(FPD_Action action);

	//************************************
	// Function:  SetFlags
	// Param[in]: action	A PDF action.
	// Param[in]: dwFlags	The input flags.
	// Return:    void
	// Remarks:   Sets the flags for action type SubmitForm, ResetForm.
	// Notes:
	//************************************
	static void	SetFlags(FPD_Action action, FS_DWORD dwFlags);


	//************************************
	// Function:  GetJavaScript
	// Param[in]: action			A PDF action.
	// Param[out]:outJavaScript		It receives the javascript script to be executed.
	// Return:    void
	// Remarks:   Gets the javascript script to be executed.
	// Notes:
	//************************************
	static void	GetJavaScript(FPD_Action action, FS_WideString* outJavaScript);

	//************************************
	// Function:  SetJavaScript
	// Param[in]: action			A PDF action.
	// Param[in]: doc				The input PDF document.
	// Param[in]: szJavaScript		The javascript in byte string.
	// Return:    void
	// Remarks:   Sets the javascript with a byte string. 
	// Notes:
	//************************************
	static void	SetJavaScript(FPD_Action action, FPD_Document doc, FS_LPCSTR szJavaScript);

	//************************************
	// Function:  SetJavaScriptW
	// Param[in]: action			A PDF action.
	// Param[in]: doc				The input PDF document.
	// Param[in]: wszJavaScript		The javascript in wide string.
	// Return:    void
	// Remarks:	  Sets the javascript with a wide string. 
	// Notes:
	//************************************
	static void	SetJavaScriptW(FPD_Action action, FPD_Document doc, FS_LPCWSTR wszJavaScript);


	//************************************
	// Function:  CountRenditions
	// Param[in]: action	A PDF action.
	// Return:    The count of renditions.
	// Remarks:   Gets the count of renditions.
	// Notes:
	//************************************
	static FS_INT32	CountRenditions(FPD_Action action);

	//************************************
	// Function:  GetRendition
	// Param[in]: action			A PDF action.
	// Param[in]: index				The zero-based rendition index.
	// Param[out]:outRendition		It receives the rendition.
	// Return:    void
	// Remarks:   Gets a rendition. 
	// Notes:
	//************************************
	static void GetRendition(FPD_Action action, FS_INT32 index, FPD_Rendition* outRendition);

	//************************************
	// Function:  InsertRendition
	// Param[in]: action			A PDF action.
	// Param[in]: doc				The input PDF document.
	// Param[in]: renditionDict		The input rendition dictionary.
	// Param[in]: index				The zero-based rendition index.
	// Return:    The inserted index in the rendition array.
	// Remarks:   Inserts a rendition.
	// Notes:
	//************************************
	static FS_INT32	InsertRendition(FPD_Action action, FPD_Document doc, FPD_Object renditionDict, FS_INT32 index);

	//************************************
	// Function:  RemoveRendition
	// Param[in]: action			A PDF action.
	// Param[in]: renditionDict		The input rendition dictionary.
	// Return:    void
	// Remarks:   Removes a rendition.
	// Notes:
	//************************************
	static void	RemoveRendition(FPD_Action action, FPD_Object renditionDict);


	//************************************
	// Function:  GetAnnot
	// Param[in]: action	A PDF action.
	// Return:	  The annotation dictionary.
	// Remarks:   Gets the annotation dictionary.
	// Notes:
	//************************************
	static FPD_Object GetAnnot(FPD_Action action);

	//************************************
	// Function:  SetAnnot
	// Param[in]: action		A PDF action.
	// Param[in]: doc			The input PDF document.
	// Param[in]: annotDict		The input annotation dictionary.
	// Return:    void
	// Remarks:   Sets the annotation dictionary.
	// Notes:
	//************************************
	static void	SetAnnot(FPD_Action action, FPD_Document doc, FPD_Object annotDict);	

	
	//************************************
	// Function:  GetOperationType
	// Param[in]: action	A PDF action.
	// Return:    The operation type.
	// Remarks:   Gets the operation type.
	// Notes:
	//************************************
	static FS_INT32	GetOperationType(FPD_Action action);

	//************************************
	// Function:  SetOperationType
	// Param[in]: action	A PDF action.
	// Param[in]: iType		The input operation type.
	// Return:    void
	// Remarks:   Sets the operation type.
	// Notes:
	//************************************
	static void	SetOperationType(FPD_Action action, FS_INT32 iType);


	//************************************
	// Function:  GetSoundStream
	// Param[in]: action	A PDF action.
	// Return:    The sound stream object.
	// Remarks:   Gets the sound stream object.
	// Notes:
	//************************************
	static FPD_Object GetSoundStream(FPD_Action action);

	//************************************
	// Function:  GetVolume
	// Param[in]: action	A PDF action.
	// Return:    The volume of the sound.
	// Remarks:   Gets the volume of the sound.  The volume at which to play the sound, in the range -1.0 to 1.0.
	// Notes:
	//************************************
	static FS_FLOAT	GetVolume(FPD_Action action);

	//************************************
	// Function:  IsSynchronous
	// Param[in]: action	A PDF action.
	// Return:    <a>TRUE</a> for playing the sound synchronously.
	// Remarks:   Checks whether to play the sound synchronously or asynchronously.
	// Notes:
	//************************************
	static FS_BOOL IsSynchronous(FPD_Action action);

	//************************************
	// Function:  IsRepeat
	// Param[in]: action	A PDF action.
	// Return:    <a>TRUE</a> for repeating the sound indefinitely.
	// Remarks:   Checks whether to repeat the sound indefinitely.
	// Notes:
	//************************************
	static FS_BOOL IsRepeat(FPD_Action action);

	//************************************
	// Function:  IsMixPlay
	// Param[in]: action	A PDF action.
	// Return:    <a>TRUE</a> for mixing this sound with any other sound already playing.
	// Remarks:   Checks whether to mix this sound with any other sound already playing.
	// Notes:
	//************************************
	static FS_BOOL IsMixPlay(FPD_Action action);


	//************************************
	// Function:  CountOCGStates
	// Param[in]: action	A PDF action.
	// Return:    The count of OCG states.
	// Remarks:   Gets the count of OCG states.
	// Notes:
	//************************************
	static FS_INT32 CountOCGStates(FPD_Action action);

	//************************************
	// Function:  GetOCGStates
	// Param[in]: action		A PDF action.
	// Param[in]: iIndex		The zero-based OCG state index.
	// Param[out]:outState		It receives the OCG state.
	// Param[out]:outArrOcgs	It receives the OCG state.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Gets OCG array with specified state.
	// Notes: 
	//************************************
	static FS_BOOL GetOCGStates(FPD_Action action, FS_INT32 iIndex, FS_INT32* outState, FS_PtrArray* outArrOcgs);

	//************************************
	// Function:  InsertOCGStates
	// Param[in]: action		A PDF action.
	// Param[in]: doc			The input PDF document.
	// Param[in]: iIndex		The OCG state index to insert at.
	// Param[in]: OCGState		The OCG state to insert.
	// Param[in]: arrOcgs		The OCG array.
	// Return:    The number of states inserted.
	// Remarks:   Inserts a OCG state.
	// Notes:
	//************************************
	static FS_INT32	InsertOCGStates(FPD_Action action, FPD_Document doc, FS_INT32 iIndex, FPD_OCGState OCGState, const FS_PtrArray arrOcgs);

	//************************************
	// Function:  ReplaceOCGStates
	// Param[in]: action	A PDF action.
	// Param[in]: doc		The input PDF document.
	// Param[in]: iIndex	The start OCG state index to replace.
	// Param[in]: arrOcgs	The OCG array.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Replaces a OCG state.
	// Notes: 
	//************************************
	static FS_BOOL ReplaceOCGStates(FPD_Action action, FPD_Document doc, FS_INT32 iIndex, const FS_PtrArray arrOcgs);

	//************************************
	// Function:  RemoveOCGStates
	// Param[in]: action	A PDF action.
	// Param[in]: index		The OCG state index.
	// Return:    void
	// Remarks:   Removes a OCG state.
	// Notes:
	//************************************
	static void	RemoveOCGStates(FPD_Action action, FS_INT32 index);

	//************************************
	// Function:  IsStatePreserved
	// Param[in]: action	A PDF action.
	// Return:    <a>TRUE</a> for the radio-button state relationships between optional content groups applying. Otherwise not.
	// Remarks:   Checks whether the radio-button state relationships between optional content groups apply or not.
	// Notes:
	//************************************
	static FS_BOOL IsStatePreserved(FPD_Action action);

	//************************************
	// Function:  SetStatePreserved
	// Param[in]: action		A PDF action.
	// Param[in]: bPreserved	The new flag.
	// Return:    void
	// Remarks:   Sets the radio-button state relationships flag.
	// Notes:
	//************************************
	static void	SetStatePreserved(FPD_Action action, FS_BOOL bPreserved);


	//************************************
	// Function:  GetSubActionsCount
	// Param[in]: action	A PDF action.
	// Return:    The sub-action count.
	// Remarks:   Gets the sub-action count.
	// Notes:
	//************************************
	static FS_DWORD	GetSubActionsCount(FPD_Action action);

	//************************************
	// Function:  GetSubAction
	// Param[in]: action	A PDF action.
	// Param[in]: index		The zero-based sub-action index.
	// Param[out]  outAction It receives the sub-action.
	// Return:    void
	// Remarks:   Gets a sub-action.
	// Notes:
	//************************************
	static void GetSubAction(FPD_Action action, FS_DWORD index, FPD_Action* outAction);

	//************************************
	// Function:  InsertSubAction
	// Param[in]: action		A PDF action.
	// Param[in]: index			The zero-based sub-action index to insert at.
	// Param[in]: document		The PDF document.
	// Param[in]: subAction		The input sub-action.
	// Return:    void
	// Remarks:   Inserts a sub-action at specified position.
	// Notes:
	//************************************
	static void	InsertSubAction(FPD_Action action, FS_DWORD index, FPD_Document document, const FPD_Action subAction);

	//************************************
	// Function:  RemoveSubAction
	// Param[in]: action	A PDF action.
	// Param[in]: index		The zero-based sub-action index.
	// Return:    void
	// Remarks:   Removes a sub-action.
	// Notes:
	//************************************
	static void	RemoveSubAction(FPD_Action action, FS_DWORD index);

	//************************************
	// Function:  RemoveAllSubActions
	// Param[in]: action	A PDF action.
	// Return:    void
	// Remarks:   Removes all sub-actions.
	// Notes:
	//************************************
	static void	RemoveAllSubActions(FPD_Action action);

	//************************************
	// Function:  GetDict
	// Param[in]: action	A PDF action.
	// Return:    The PDF action dictionary.
	// Remarks:   Gets the PDF action dictionary.
	// Notes:
	//************************************
	static FPD_Object GetDict(FPD_Action action);	
	
	//************************************
	// Function:  New4
	// Return:   FPD_Action.
	// Remarks:   Create FPD_Action object.
	// Notes:
	//************************************
	static FPD_Action New4();

	//************************************
	// Function:  CreateGoToE
	// Param[in]: pDocument	    The input PDF document.
	// Param[in]: destination	The destination in the target to jump to.
	// Param[in]: targetDictionary	The target dictionary specifying path information to the target doc.
	// Param[in]: newWindow	    If the action open in newWindow.
	// Param[out]: outAction	Get a PDF action.
	// Return:   void
	// Remarks:   Create a PDF action.
	// Notes:
	//************************************
	static void CreateGoToE(FPD_Document pDocument, const FPD_Dest destination, FPD_Object targetDictionary, FS_BOOLEAN newWindow, FPD_Action* outAction);

	//************************************
	// Function:  SetDest2
	// Param[in]: action	A PDF action.
	// Param[in]: dest		Ref to a PDF destination.
	// Param[in]: doc       The input PDF document.In fact, this is the use of indirect object collection, required if dest is an indirect object.In this case,
	//                      a reference object will be created and inserted into the dictionary.
	//					    for interface unification, the use of CPDF_Document pointer does not use CPDF_IndirectObjects pointer.
	// Return:    void
	// Remarks:   Sets the destination.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void	SetDest2(FPD_Action action, const FPD_Dest dest, FPD_Document doc);
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_AAction_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_AAction_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: dict	The input PDF dictionary.
	// Return:    PDF additional-action.
	// Remarks:   Creates PDF additional-action from a PDF dictionary.
	// Notes:
	//************************************
	static FPD_AAction New(FPD_Object dict);

	//************************************
	// Function:  Destroy
	// Param[in]: aaction	PDF additional-action
	// Return:    void
	// Remarks:   Destroys PDF additional-action.
	// Notes:
	//************************************
	static void	Destroy(FPD_AAction aaction);
	
	//************************************
	// Function:  ActionExist
	// Param[in]: aaction	PDF additional-action
	// Param[in]: eType		The input additional-action type.
	// Return:    Non-zero means exist, otherwise not exist.
	// Remarks:   Checks whether the specified additional-action type exists or not.
	// Notes:
	//************************************
	static FS_BOOL ActionExist(FPD_AAction aaction, FPD_AActionType eType);

	//************************************
	// Function:  GetAction
	// Param[in]: aaction		PDF additional-action
	// Param[in]: eType			The input additional-action type.
	// Param[out]:outAction		An action.
	// Return:    void
	// Remarks:   Gets an action from the additional-action with specified additional-action type. 
	// Notes:
	//************************************
	static void GetAction(FPD_AAction aaction, FPD_AActionType eType, FPD_Action* outAction);

	//************************************
	// Function:  SetAction
	// Param[in]: aaction	PDF additional-action
	// Param[in]: doc		The PDF document.
	// Param[in]: eType		The additional-action type.
	// Param[in]: action	The input action.
	// Return:    void
	// Remarks:   Sets a additional-action of specified type.
	// Notes:
	//************************************
	static void SetAction(FPD_AAction aaction, FPD_Document doc, FPD_AActionType eType, const FPD_Action action);

	//************************************
	// Function:  RemoveAction
	// Param[in]: aaction	PDF additional-action
	// Param[in]: eType		The additional-action type to be removed.
	// Return:    void
	// Remarks:   Removes a additional-action.
	// Notes:
	//************************************
	static void	RemoveAction(FPD_AAction aaction, FPD_AActionType eType);

	//************************************
	// Function:  GetStartPos
	// Param[in]: aaction	PDF additional-action
	// Return:	  The start position of action list.
	// Remarks:   Gets the start position of action list.
	// Notes:
	//************************************
	static FS_POSITION GetStartPos(FPD_AAction aaction);

	//************************************
	// Function:  GetNextAction
	// Param[in]: aaction		PDF additional-action
	// Param[in,out]:outPos		Input the current position and receive the next position.
	// Param[out]:outType		Receive the additional-action type.
	// Param[out]:outAction		Receive the current action.
	// Return:    void
	// Remarks:   Gets the current action and move the position to next position.
	// Notes:
	//************************************
	static void GetNextAction(FPD_AAction aaction, FS_POSITION* outPos, FPD_AActionType* outType, FPD_Action* outAction);

	//************************************
	// Function:  GetDictionary
	// Param[in]: aaction		PDF additional-action
	// Return:    The additional-action dictionary.
	// Remarks:   Gets the additional-action dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	//************************************
	static FPD_Object GetDictionary(FPD_AAction aaction);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*								 CFPD_DocJSActions_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_DocJSActions_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: doc	The input PDF document.
	// Return:    Document-level JavaScript actions.
	// Remarks:   Creates document-level JavaScript actions from a PDF document.
	// Notes:
	//************************************
	static FPD_DocJSActions New(FPD_Document doc);

	//************************************
	// Function:  Destroy
	// Param[in]: jsActions		The input document-level JavaScript actions.
	// Return:    void
	// Remarks:   Destroys document-level JavaScript actions.
	// Notes:
	//************************************
	static void	Destroy(FPD_DocJSActions jsActions);
	
	//************************************
	// Function:  CountJSActions
	// Param[in]: jsActions		The input document-level JavaScript actions.
	// Return:    The count of JavaScript actions.
	// Remarks:   Gets the count of JavaScript actions.
	// Notes:
	//************************************
	static FS_INT32	CountJSActions(FPD_DocJSActions jsActions);

	//************************************
	// Function:  GetJSAction
	// Param[in]: jsActions		The input document-level JavaScript actions.
	// Param[in]: index			The zero-based JavaScipt action index.
	// Param[out]: wszName		The name of the JavaScript action.
	// Param[out]:outAction		A JavaScript action.
	// Return:    void
	// Remarks:   Gets a JavaScript action with the position and the name.
	// Notes:
	//************************************
	static void GetJSAction(FPD_DocJSActions jsActions, FS_INT32 index, FS_ByteString* wszName, FPD_Action* outAction);

	//************************************
	// Function:  GetJSAction2
	// Param[in]: jsActions		The input document-level JavaScript actions.
	// Param[in]: wszName		The name of the JavaScript action.
	// Param[out]:outAction		A JavaScript action.
	// Return:    void
	// Remarks:   Gets a JavaScript action with the name.
	// Notes:
	//************************************
	static void GetJSAction2(FPD_DocJSActions jsActions, FS_LPCWSTR wszName, FPD_Action* outAction);

	//************************************
	// Function:  SetJSAction
	// Param[in]: jsActions		The input document-level JavaScript actions.
	// Param[in]: wszName		The name of the JavaScript action.
	// Param[in]: action		The JavaScript action.
	// Return:    The zero-based index of the JavaScript action.
	// Remarks:   Sets a JavaScript action.
	// Notes:
	//************************************
	static FS_INT32	SetJSAction(FPD_DocJSActions jsActions, FS_LPCWSTR wszName, FPD_Action action);

	//************************************
	// Function:  FindJSAction
	// Param[in]: jsActions		The input document-level JavaScript actions.
	// Param[in]: wszName		The name of the JavaScript action.
	// Return:    The zero-based index of the JavaScript action.
	// Remarks:   Finds a JavaScript action.
	//            return the position (zero based index), -1 means not found.
	// Notes:
	//************************************
	static FS_INT32	FindJSAction(FPD_DocJSActions jsActions, FS_LPCWSTR wszName);

	//************************************
	// Function:  RemoveJSAction
	// Param[in]: jsActions		The input document-level JavaScript actions.
	// Param[in]: index			The zero-based index of JavaScript action to be removed.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Removes a JavaScript action.
	// Notes:
	//************************************
	static FS_BOOL RemoveJSAction(FPD_DocJSActions jsActions, FS_INT32 index);

	//************************************
	// Function:  GetDocument
	// Param[in]: jsActions		The input document-level JavaScript actions.
	// Return:    The PDF document.
	// Remarks:   Gets the PDF document.
	// Notes:
	//************************************
	static FPD_Document	GetDocument(FPD_DocJSActions jsActions);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*									 CFPD_FileSpec_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////


class CFPD_FileSpec_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new file specification object.
	// Remarks:   Creates a new file specification object - dictionary object.
	// Notes:
	//************************************
	static FPD_FileSpec	New(void);

	//************************************
	// Function:  NewFromObj
	// Param[in]: obj	The input PDF object.
	// Return:    A new file specification object.
	// Remarks:   Creates a new file specification object from a PDF object.
	// Notes:
	//************************************
	static FPD_FileSpec	NewFromObj(FPD_Object obj);

	//************************************
	// Function:  Destroy
	// Param[in]: fileSpec	A file specification object.
	// Return:    void
	// Remarks:   Destroys a file specification object.
	// Notes:
	//************************************
	static void	Destroy(FPD_FileSpec fileSpec);
	
	//************************************
	// Function:  IsURL
	// Param[in]: fileSpec	A file specification object.
	// Return:    <a>TRUE</a> for being a URL, otherwise not.
	// Remarks:   Checks whether it's a URL or not.
	//            If is an URL, FPDFileSpecGetFileName gets the URL address.
	// Notes:
	//************************************
	static FS_BOOL IsURL(FPD_FileSpec fileSpec);

	//************************************
	// Function:  GetFileName
	// Param[in]: fileSpec	A file specification object.
	// Param[out]:outFile	It receives the file name.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Gets the file name.
	// Notes:
	//************************************
	static FS_BOOL GetFileName(FPD_FileSpec fileSpec, FS_WideString* outFile);

	//************************************
	// Function:  GetFileStream
	// Param[in]: fileSpec	A file specification object.
	// Return:    The PDF stream object from the file specification.
	// Remarks:   Gets a PDF stream from the file specification.
	// Notes:
	//************************************
	static FPD_Object GetFileStream(FPD_FileSpec fileSpec);

	//************************************
	// Function:  SetFileName
	// Param[in]: fileSpec	A file specification object.
	// Param[in]: wszFile	Input a file name.
	// Param[in]: bURL		Whether the input file name is an URL.
	// Return:    void
	// Remarks:   Sets the file name.
	// Notes:
	//************************************
	static void	SetFileName(FPD_FileSpec fileSpec, FS_LPCWSTR wszFile, FS_BOOL bURL);

	//************************************
	// Function:  SetEmbeddedFile
	// Param[in]: fileSpec				A file specification object.
	// Param[in]: doc					The PDF document.
	// Param[in]: pFileReadHandler		The file access interface.
	// Param[in]: szFilePath			The file path.
	// Return:    void
	// Remarks:   Sets an embedded file.
	// Notes:
	//************************************
	static void	SetEmbeddedFile(FPD_FileSpec fileSpec, FPD_Document doc, FS_FileReadHandler pFileReadHandler, FS_LPCWSTR szFilePath);	
	
	//************************************
	// Function:  GetPDFObjct
	// Param[in]: fileSpec				A file specification object.	
	// Return:    FPD_Object   The pointer to the PDF object of file specification.
	// Remarks:   This casting operator accesses the PDF object of file specification.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	//************************************
	static FPD_Object	GetPDFObjct(FPD_FileSpec fileSpec);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_Media_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_MediaPlayer_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    An empty media player information object.
	// Remarks:   Creates an empty media player information object.
	// Notes:
	//************************************
	static FPD_MediaPlayer New(void);

	//************************************
	// Function:  NewFromDict
	// Param[in]: dict	The input PDF dictionary.
	// Return:    An media player information object.
	// Remarks:   Creates an media player information object from a PDF dictionary.
	// Notes:
	//************************************
	static FPD_MediaPlayer NewFromDict(FPD_Object dict);

	//************************************
	// Function:  Destroy
	// Param[in]: player	The media player information object.
	// Return:    void
	// Remarks:   Destroys the media player information object.
	// Notes:
	//************************************
	static void	Destroy(FPD_MediaPlayer player);

	
	//************************************
	// Function:  GetSoftwareURI
	// Param[in]: player	The media player information object.
	// Param[out]:outURL	The software URI.
	// Return:    void
	// Remarks:   Gets the software URI.
	// Notes:
	//************************************
	static void	GetSoftwareURI(FPD_MediaPlayer player, FS_ByteString* outURL);

	//************************************
	// Function:  SetSoftwareURI
	// Param[in]: player	The media player information object.
	// Param[in]: szURI		The input software URI.
	// Return:    void
	// Remarks:   Sets the software URI.
	// Notes:
	//************************************
	static void	SetSoftwareURI(FPD_MediaPlayer player, FS_LPCSTR szURI);


	//************************************
	// Function:  GetOSArray
	// Param[in]: player		The media player information object.
	// Param[out]:outOSArray	It receives the OS array.
	// Return:    The number of OS in the array.
	// Remarks:   Gets the OS array in the software identifier dictionary.
	// Notes:
	//************************************
	static FS_INT32	GetOSArray(FPD_MediaPlayer player, FS_ByteStringArray* outOSArray);

	//************************************
	// Function:  SetOSArray
	// Param[in]: player	The media player information object.
	// Param[in]: osArray	The input OS array.
	// Return:    void
	// Remarks:   Sets the OS array.
	// Notes:
	//************************************
	static void	SetOSArray(FPD_MediaPlayer player, const FS_ByteStringArray osArray);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*									 CFPD_Rendition_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_Rendition_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    An empty rendition object.
	// Remarks:   Creates an empty rendition object.
	// Notes:
	//************************************
	static FPD_Rendition New(void);

	//************************************
	// Function:  NewFromDict
	// Param[in]: dict	The input PDF dictionary.
	// Return:    A rendition object.
	// Remarks:   Creates a rendition object from a PDF dictionary.
	// Notes:
	//************************************
	static FPD_Rendition NewFromDict(FPD_Object dict);

	//************************************
	// Function:  Destroy
	// Param[in]: rendition		The input rendition object.
	// Return:    void
	// Remarks:   Destroys a rendition object.
	// Notes:
	//************************************
	static void	Destroy(FPD_Rendition rendition);	

	
	//************************************
	// Function:  HasMediaClip
	// Param[in]: rendition		The input rendition object.
	// Return:    <a>TRUE</a> for the rendition dictionary having the C entry, otherwise not.
	// Remarks:   Checks whether the rendition dictionary has the C entry.
	// Notes:
	//************************************
	static FS_BOOL HasMediaClip(FPD_Rendition rendition);


	//************************************
	// Function:  GetRenditionName
	// Param[in]: rendition		The input rendition object.
	// Param[out]:outName		The rendition name.
	// Return:    void
	// Remarks:   Gets the rendition name.
	// Notes:
	//************************************
	static void	GetRenditionName(FPD_Rendition rendition, FS_WideString* outName);

	//************************************
	// Function:  SetRenditionName
	// Param[in]: rendition		The input rendition object.
	// Param[in]: wszName		The input rendition name.
	// Return:    void
	// Remarks:   Sets the rendition name.
	// Notes:
	//************************************
	static void	SetRenditionName(FPD_Rendition rendition, FS_LPCWSTR wszName);


	//************************************
	// Function:  GetMediaClipName
	// Param[in]: rendition		The input rendition object.
	// Param[out]:outName		The media clip name.
	// Return:    void
	// Remarks:   Gets the media clip name.
	// Notes:
	//************************************
	static void	GetMediaClipName(FPD_Rendition rendition, FS_WideString* outName);

	//************************************
	// Function:  SetMediaClipName
	// Param[in]: rendition		The input rendition object.
	// Param[in]: wszName		The input media clip name.
	// Return:    void
	// Remarks:   Sets the media clip name.
	// Notes:
	//************************************
	static void	SetMediaClipName(FPD_Rendition rendition, FS_LPCWSTR wszName);


	//************************************
	// Function:  GetMediaClipFile
	// Param[in]: rendition		The input rendition object.
	// Param[out]:outFileSpec	The file specification of the actual media data.
	// Return:    void
	// Remarks:   Gets the file specification of the actual media data.
	// Notes:
	//************************************
	static void GetMediaClipFile(FPD_Rendition rendition, FPD_FileSpec* outFileSpec);

	//************************************
	// Function:  SetMediaClipFile
	// Param[in]: rendition		The input rendition object.
	// Param[in]: doc			The input PDF document.
	// Param[in]: file			The input file specification object.
	// Return:    void
	// Remarks:   Sets the file specification of the actual media data.
	// Notes:
	//************************************
	static void	SetMediaClipFile(FPD_Rendition rendition, FPD_Document doc, FPD_FileSpec file);


	//************************************
	// Function:  GetMediaClipContentType
	// Param[in]: rendition			The input rendition object.
	// Param[out]:outContentType	The content type (MIME type) of the media data.
	// Return:    void
	// Remarks:   Gets the content type (MIME type) of the media data.
	// Notes:
	//************************************
	static void	GetMediaClipContentType(FPD_Rendition rendition, FS_ByteString* outContentType);

	//************************************
	// Function:  SetMediaClipContentType
	// Param[in]: rendition			The input rendition object.
	// Param[in]: szContentType		The input content type.
	// Return:    void
	// Remarks:   Sets the content type (MIME type) of the media data.
	// Notes:
	//************************************
	static void	SetMediaClipContentType(FPD_Rendition rendition, FS_LPCSTR szContentType );


	//************************************
	// Function:  GetPermission
	// Param[in]: rendition		The input rendition object.
	// Return:    The media permission
	// Remarks:   Gets the media permission that indicates the circumstances under which it is acceptable 
	//			  to write a temporary file in order to play a media clip.
	// Notes:
	//************************************
	static FPD_MediaPermission	GetPermission(FPD_Rendition rendition);

	//************************************
	// Function:  SetPermission
	// Param[in]: rendition			The input rendition object.
	// Param[in]: ePermission		The input media permission.
	// Return:    void
	// Remarks:   Sets the media permission.
	// Notes:
	//************************************
	static void	SetPermission(FPD_Rendition rendition, FPD_MediaPermission ePermission);


	//************************************
	// Function:  GetMediaDescriptions	
	// Param[in]: rendition			The input rendition object.
	// Param[out]:outDescArray		It receives the text descriptions array.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Gets the text descriptions array that provides alternate text descriptions for 
	//            the media clip data in case it cannot be played.
	// Notes:
	//************************************
	static FS_BOOL GetMediaDescriptions(FPD_Rendition rendition, FS_WideStringArray* outDescArray);

	//************************************
	// Function:  SetMediaDescriptions
	// Param[in]: rendition		The input rendition object.
	// Param[in]: descArray		The input text descriptions array.
	// Return:    void
	// Remarks:   Sets the text descriptions array.
	// Notes:
	//************************************
	static void	SetMediaDescriptions(FPD_Rendition rendition, const FS_WideStringArray descArray);


	//************************************
	// Function:  GetMediaBaseURL
	// Param[in]: rendition		The input rendition object.
	// Param[out]:outURL		It receives the absolute URL.
	// Return:    void
	// Remarks:   Gets an absolute URL to be used as the base URL in resolving any relative URLs found within the media data.
	// Notes:
	//************************************
	static void	GetMediaBaseURL(FPD_Rendition rendition, FS_ByteString* outURL);

	//************************************
	// Function:  SetMediaBaseURL
	// Param[in]: rendition		The input rendition object.
	// Param[in]: szBaseURL		The input base URL.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the base URL.
	// Notes:
	//************************************
	static void	SetMediaBaseURL(FPD_Rendition rendition, FS_LPCSTR szBaseURL, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  CountMediaPlayers
	// Param[in]: rendition		The input rendition object.
	// Param[in]: ePlayerType	The input media player type.
	// Return:    The count of media player of specified type.
	// Remarks:   Gets the count of media players of specified type.
	// Notes:
	//************************************
	static FS_INT32	CountMediaPlayers(FPD_Rendition rendition, FPD_MediaPlayerType ePlayerType);

	//************************************
	// Function:  GetMediaPlayer
	// Param[in]: rendition			The input rendition object.
	// Param[in]: ePlayerType		The input media player type.
	// Param[in]: index				The zero-based index in the specified media player type.
	// Param[out]:outMediaPlayer	A media player.
	// Return:    void
	// Remarks:   Gets a media player.
	// Notes:
	//************************************
	static void GetMediaPlayer(FPD_Rendition rendition, FPD_MediaPlayerType ePlayerType, FS_INT32 index, FPD_MediaPlayer* outMediaPlayer);

	//************************************
	// Function:  AddMediaPlayer
	// Param[in]: rendition		The input rendition object.
	// Param[in]: ePlayerType	The input media player type.
	// Param[in]: player		The input media player.
	// Return:    The current count of specified media player type.
	// Remarks:   Adds a media player.
	// Notes:
	//************************************
	static FS_INT32 AddMediaPlayer(FPD_Rendition rendition, FPD_MediaPlayerType ePlayerType, FPD_MediaPlayer player);

	//************************************
	// Function:  RemoveMediaPlayer
	// Param[in]: rendition		The input rendition object.
	// Param[in]: ePlayerType	The input media player type.
	// Param[in]: player		The media player to be removed.
	// Return:    void
	// Remarks:   Removes a media player.
	// Notes:
	//************************************
	static void	RemoveMediaPlayer(FPD_Rendition rendition, FPD_MediaPlayerType ePlayerType, FPD_MediaPlayer player);


	//************************************
	// Function:  GetVolumn	
	// Param[in]: rendition		The input rendition object.
	// Return:    The volume
	// Remarks:   Gets the volume that specifies the desired volume level as a percentage of recorded volume level.
	// Notes:
	//************************************
	static FS_INT32 GetVolumn(FPD_Rendition rendition);
	//************************************
	// Function:  SetVolumn
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iVolumn		The input volume.
	// Param[in]: eParamType	The media play param type.
	// Return:    void
	// Remarks:   Sets the volume.
	// Notes:
	//************************************
	static void	SetVolumn(FPD_Rendition rendition, FS_INT32 iVolumn, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  IsControlBarVisible
	// Param[in]: rendition		The input rendition object.
	// Return:    <a>TRUE</a> for being visible, otherwise not.
	// Remarks:   Checks to display a player-specific controller user interface (for example, play/pause/stop controls) when playing.
	// Notes:
	//************************************
	static FS_BOOL IsControlBarVisible(FPD_Rendition rendition);


	//************************************
	// Function:  EnableControlBarVisible
	// Param[in]: rendition		The input rendition object.
	// Param[in]: bVisible		The input visibility flag of the control bar.
	// Param[in]: eParamType		The input media play param type.
	// Return:    void	
	// Remarks:   Sets the control bar visibility flag.
	// Notes:
	//************************************
	static void	EnableControlBarVisible(FPD_Rendition rendition, FS_BOOL bVisible, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  GetFitStyle
	// Param[in]: rendition		The input rendition object.
	// Return:    The fit style (manner).
	// Remarks:   Gets the fit style (manner) in which the player should treat a visual media 
	//            type that does not exactly fit the rectangle in which it plays.
	// Notes:
	//************************************
	static FS_INT32	GetFitStyle(FPD_Rendition rendition);

	//************************************
	// Function:  SetFitStyle
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iFitStyle		The input fit style.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the fit style.
	// Notes:
	//************************************
	static void	SetFitStyle(FPD_Rendition rendition, FS_INT32 iFitStyle, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  GetDuration	
	// Param[in]: rendition		The input rendition object.
	// Return:    The intrinsic duration.
	// Remarks:   Gets the intrinsic duration.
	// Notes:
	//************************************
	static FS_INT32	GetDuration(FPD_Rendition rendition);

	//************************************
	// Function:  SetDuration
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iDuration		The input intrinsic duration.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the intrinsic duration.
	// Notes:
	//************************************
	static void	SetDuration(FPD_Rendition rendition, FS_INT32 iDuration, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  AutoPlay
	// Param[in]: rendition		The input rendition object.
	// Return:    <a>TRUE</a> for the media automatically playing when activated, otherwise not.
	// Remarks:   Checks whether the media should automatically play when activated.
	// Notes:
	//************************************
	static FS_BOOL AutoPlay(FPD_Rendition rendition);

	//************************************
	// Function:  EnableAutoPlay
	// Param[in]: rendition		The input rendition object.
	// Param[in]: bAuto			The input auto-play flag.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the auto-play flag.
	// Notes:
	//************************************
	static void	EnableAutoPlay(FPD_Rendition rendition, FS_BOOL bAuto, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  RepeatCount
	// Param[in]: rendition		The input rendition object.
	// Return:    The repeat count.
	// Remarks:	  Gets the repeat count.
	// Notes:
	//************************************
	static FS_INT32	RepeatCount(FPD_Rendition rendition);

	//************************************
	// Function:  SetRepeatCount
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iCount		The input repeat count.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the repeat count.
	// Notes:
	//************************************
	static void	SetRepeatCount(FPD_Rendition rendition, FS_INT32 iCount, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  GetWindowStatus	
	// Param[in]: rendition		The input rendition object.
	// Return:    0: floating window; 1: full screen; 2: hidden window; 3: child window.
	// Remarks:   Gets the window status(type) that the media object should play in.
	// Notes:
	//************************************
	static FS_INT32	GetWindowStatus(FPD_Rendition rendition);

	//************************************
	// Function:  SetWindowStatus	
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iStatus		The input window status.0: floating window; 1: full screen; 2: hidden window; 3: child window.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the window status.
	// Notes:
	//************************************
	static void	SetWindowStatus(FPD_Rendition rendition, FS_INT32 iStatus, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  GetBackgroundColor	
	// Param[in]: rendition		The input rendition object.
	// Return:    The background color for the rectangle in which the media is being played. 
	// Remarks:   Gets the background color for the rectangle in which the media is being played. 
	// Notes:
	//************************************
	static FS_COLORREF GetBackgroundColor(FPD_Rendition rendition);

	//************************************
	// Function:  SetBackgroundColor
	// Param[in]: rendition		The input rendition object.
	// Param[in]: color			The input background color.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the background color.
	// Notes:
	//************************************
	static void	SetBackgroundColor(FPD_Rendition rendition, FS_COLORREF color, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  GetBackgroundOpacity	
	// Param[in]: rendition		The input rendition object.
	// Return:    The background opacity.
	// Remarks:   Gets the background opacity.
	// Notes:
	//************************************
	static FS_FLOAT	GetBackgroundOpacity(FPD_Rendition rendition);

	//************************************
	// Function:  SetBackgroundOpacity
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iOpacity		The input background opacity.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the background opacity.
	// Notes:
	//************************************
	static void	SetBackgroundOpacity(FPD_Rendition rendition, FS_FLOAT iOpacity, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  GetMonitor
	// Param[in]: rendition		The input rendition object.
	// Return:    The monitor specifier
	// Remarks:   Gets the monitor specifier that specifies which monitor in a multi-monitor 
	//            system a floating or full-screen window should appear on.
	// Notes:
	//************************************
	static FS_INT32	GetMonitor(FPD_Rendition rendition);

	//************************************
	// Function:  SetMonitor	
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iMonitor		The input monitor specifier.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the monitor specifier.
	// Notes:
	//************************************
	static void	SetMonitor(FPD_Rendition rendition, FS_INT32 iMonitor, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  GetFloatingWindowSize
	// Param[in]: rendition		The input rendition object.
	// Param[out]:iWidth		It receives the floating window's width.
	// Param[out]:iHeight		It receives the floating window's height.
	// Return:    <a>TRUE</a>: returned size is available; <a>FALSE</a>: not available.
	// Remarks:   Gets the floating window's width and height.
	// Notes:
	//************************************
	static FS_BOOL GetFloatingWindowSize(FPD_Rendition rendition, FS_INT32* iWidth, FS_INT32* iHeight);

	//************************************
	// Function:  SetFloatingWindowSize
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iWidth		The width of the floating window.
	// Param[in]: iHeight		The height of the floating window.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the floating window's width and height.
	// Notes:
	//************************************
	static void	SetFloatingWindowSize(
		FPD_Rendition rendition, 
		FS_INT32 iWidth, 
		FS_INT32 iHeight, 
		FPD_MediaPlayParamType eParamType
		);


	//************************************
	// Function:  GetFloatingWindowRelativeType
	// Param[in]: rendition		The input rendition object.
	// Return:    0: document window; 1: application window; 2: full virtual desktop; 3: monitor screen.
	// Remarks:   Gets the window type relative to which the floating window should be positioned. 
	// Notes:
	//************************************
	static FS_INT32	GetFloatingWindowRelativeType(FPD_Rendition rendition);

	//************************************
	// Function:  SetFloatingWindowRelativeType
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iType			The input window relative type. 0: document window; 1: application window; 2: full virtual desktop; 3: monitor screen.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the window relative type.
	// Notes:
	//************************************
	static void	SetFloatingWindowRelativeType(FPD_Rendition rendition, FS_INT32 iType, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  GetFloatingWindowPosition	
	// Param[in]: rendition		The input rendition object.
	// Return:    0: upper left; 1: upper center; 2: upper right; 3: center left; 4: center; 5: center right; 6: lower left; 7: lower center; 8: lower right.
	// Remarks:   Gets the floating window position.
	// Notes:
	//************************************
	static FS_INT32 GetFloatingWindowPosition(FPD_Rendition rendition);

	//************************************
	// Function:  SetFloatingWindowPosition
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iPosition		The input floating window position. 0: upper left; 1: upper center; 2: upper right; 3: center left; 4: center; 5: center right; 6: lower left; 7: lower center; 8: lower right.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the floating window position.
	// Notes:
	//************************************
	static void	SetFloatingWindowPosition(FPD_Rendition rendition, FS_INT32 iPosition, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  GetFloatingWindowOffscreen
	// Param[in]: rendition		The input rendition object.
	// Return:    0: nothing; 1: move or resize; 2: consider the object non-viable.
	// Remarks:   Gets what should occur if the floating window is positioned totally or partially off screen.
	// Notes:
	//************************************
	static FS_INT32	GetFloatingWindowOffscreen(FPD_Rendition rendition);

	//************************************
	// Function:  SetFloatingWindowOffscreen
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iOffscreen	The input action Function.0: nothing; 1: move or resize; 2: consider the object non-viable.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the action Function.
	// Notes:
	//************************************
	static void	SetFloatingWindowOffscreen(FPD_Rendition rendition, FS_INT32 iOffscreen, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  HasFloatingWindowTitleBar
	// Param[in]: rendition		The input rendition object.
	// Return:    <a>TRUE</a> for the floating window having a title bar.
	// Remarks:   Checks whether the floating window should have a title bar.
	// Notes:
	//************************************
	static FS_BOOL HasFloatingWindowTitleBar(FPD_Rendition rendition);

	//************************************
	// Function:  EnableFloatingWindowTitleBar
	// Param[in]: rendition		The input rendition object.
	// Param[in]: bVisible		The input visibility flag.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the title bar visibility flag.
	// Notes:
	//************************************
	static void	EnableFloatingWindowTitleBar(FPD_Rendition rendition, FS_BOOL bVisible, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  HasFloatingWindowCloseButton	
	// Param[in]: rendition		The input rendition object.
	// Return:    <a>TRUE</a> for the floating window including user interface elements, otherwise not.
	// Remarks:   Checks whether the floating window should include user interface elements that allow a user to close a floating window.
	// Notes:
	//************************************
	static FS_BOOL HasFloatingWindowCloseButton(FPD_Rendition rendition);

	//************************************
	// Function:  EnableFloatingWindowCloseButton
	// Param[in]: rendition		The input rendition object.
	// Param[in]: bVisible		The input visibility flag.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the visibility flag of close-button.
	// Notes:
	//************************************
	static void	EnableFloatingWindowCloseButton(FPD_Rendition rendition, FS_BOOL bVisible, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  GetFloatingWindowResizeType	
	// Param[in]: rendition		The input rendition object.
	// Return:    0: may not be resized; 1: resize with aspect ratio; 2: resize anyway.
	// Remarks:   Checks whether the floating window may be resized by a user.
	// Notes:
	//************************************
	static FS_INT32	GetFloatingWindowResizeType(FPD_Rendition rendition);

	//************************************
	// Function:  SetFloatingWindowResizeType
	// Param[in]: rendition		The input rendition object.
	// Param[in]: iType			The input floating window resizing type. 0: may not be resized; 1: resize with aspect ratio; 2: resize anyway.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the floating window resizing type.
	// Notes:
	//************************************
	static void	SetFloatingWindowResizeType(FPD_Rendition rendition, FS_INT32 iType, FPD_MediaPlayParamType eParamType);


	//************************************
	// Function:  GetFloatingWindowTitle
	// Param[in]: rendition			The input rendition object.
	// Param[out]:outTitleArray		It receives the multi-language text array.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Gets the multi-language text array providing text to display on the floating window's title bar.
	// Notes:
	//************************************
	static FS_BOOL GetFloatingWindowTitle(FPD_Rendition rendition, FS_WideStringArray* outTitleArray);

	//************************************
	// Function:  SetFloatingWindowTitle
	// Param[in]: rendition		The input rendition object.
	// Param[in]: titleArray	The input multi-language text array.
	// Param[in]: eParamType	The input media play param type.
	// Return:    void
	// Remarks:   Sets the multi-language text array to provide text for title bar.
	// Notes:
	//************************************
	static void	SetFloatingWindowTitle(FPD_Rendition rendition, FS_WideStringArray titleArray, FPD_MediaPlayParamType eParamType);
};



//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_Link_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////


class CFPD_Link_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: dict		The input PDF dictionary.
	// Return:    A PDF link.
	// Remarks:   Creates a PDF link from a PDF dictionary.
	// Notes:
	//************************************
	static FPD_Link	New(FPD_Object dict);

	//************************************
	// Function:  Destroy
	// Param[in]: link		The input PDF link.
	// Return:    void
	// Remarks:   Destroys a PDF link.
	// Notes:
	//************************************
	static void	Destroy(FPD_Link link);
	
	//************************************
	// Function:  GetLinkAtPoint
	// Param[in]: doc		The input PDF document.
	// Param[in]: page		The input PDF page.
	// Param[in]: x			The input x-coordinate of the point.
	// Param[in]: y			The input y-coordinate of the point.
	// Param[out]: outLink It receives the link at specified point.
	// Return:	  void
	// Remarks:   Gets the link at specified point. The point is specified in user space. 
	//            <a>NULL</a> for no link at that point.
	// Notes:
	//************************************
	static void	GetLinkAtPoint(FPD_Document doc, FPD_Page page, FS_FLOAT x, FS_FLOAT y, FPD_Link* outLink);

	//************************************
	// Function:  CountLinks
	// Param[in]: doc		The input PDF document.
	// Param[in]: page		The input PDF page.
	// Return:    The count of links in the page.
	// Remarks:   Gets the count of links in specified page.
	// Notes:
	//************************************
	static FS_INT32	CountLinks(FPD_Document doc, FPD_Page page);

	//************************************
	// Function:  GetLink
	// Param[in]: doc		The input PDF document.
	// Param[in]: page		The input PDF page.
	// Param[in]: index		The zero-based link index int the page.
	// Param[out]: outLink It receives the link by index.
	// Return:    void
	// Remarks:   Gets a PDF link.
	// Notes:
	//************************************
	static void	GetLink(FPD_Document doc, FPD_Page page, FS_INT32 index, FPD_Link* outLink);
	
	//************************************
	// Function:  GetRect
	// Param[in]: link The input link.
	// Return:    The rectangle in which the link should be activated.
	// Remarks:   Gets the rectangle in which the link should be activated.
	// Notes:
	//************************************
	static FS_FloatRect	GetRect(FPD_Link link);


	//************************************
	// Function:  GetDest
	// Param[in]: link		The input PDF link.
	// Param[in]: doc		The input PDF document.
	// Param[out]:outDest	The destination of the link.
	// Return:    void
	// Remarks:   Gets the destination of the link.
	// Notes:
	//************************************
	static void GetDest(FPD_Link link, FPD_Document doc, FPD_Dest* outDest);

	//************************************
	// Function:  GetAction
	// Param[in]: link			The input PDF link.
	// Param[out]:outAction		The action of the link.
	// Return:    void
	// Remarks:   Gets the action of the link.
	// Notes:
	//************************************
	static void GetAction(FPD_Link link, FPD_Action* outAction);
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_Annot_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_Annot_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: dict		The input PDF dictionary.
	// Return:    An annotation.
	// Remarks:   Creates an annotation from a PDF dictionary.
	// Notes:
	//************************************
	static FPD_Annot New(FPD_Object dict);

	//************************************
	// Function:  Destroy
	// Param[in]: annot		The input annotation.
	// Return:    void
	// Remarks:   Destroys an annotation.
	// Notes:
	//************************************
	static void	Destroy(FPD_Annot annot);
	
	//************************************
	// Function:  GetAnnotDict
	// Param[in]: annot		The input annotation.
	// Return:    The annotation dictionary.
	// Remarks:   Gets the annotation dictionary. We store all information within the original annotation dictionary.
	// Notes:
	//************************************
	static FPD_Object GetAnnotDict(FPD_Annot annot);

	//************************************
	// Function:  GetSubType
	// Param[in]: annot			The input annotation.
	// Param[out]:outSubType	It receives the annotation type name.
	// Return:    void
	// Remarks:   Gets the annotation type name.
	// Notes:
	//************************************
	static void	GetSubType(FPD_Annot annot, FS_ByteString* outSubType);

	//************************************
	// Function:  GetFlags
	// Param[in]: annot		The input annotation.
	// Return:    The annotation flags.
	// Remarks:   Gets the annotation flags.
	// Notes:
	//************************************
	static FS_DWORD	GetFlags(FPD_Annot annot);

	//************************************
	// Function:  GetRect
	// Param[in]: annot		The input annotation.
	// Return:    The bounding box of the annotation. 
	// Remarks:   Gets annotation bounding box in user space.
	// Notes:
	//************************************
	static FS_FloatRect	GetRect(FPD_Annot annot);

	//************************************
	// Function:  DrawAppearance
	// Param[in]: annot		The input annotation.
	// Param[in]: page		The page it belongs to.
	// Param[in]: dc		The device to draw on.
	// Param[in]: matrix	The transformation matrix from user space to device space.
	// Param[in]: eMode		The input appearance mode.
	// Param[in]: opts		The render options.
	// Return:    <a>TRUE</a> if the appearance successfully found and drawn.
	// Remarks:   Draws annotation's appearance, using default appearance rules.
	// Notes:
	//************************************
	static FS_BOOL DrawAppearance(FPD_Annot annot, 
		const FPD_Page page, 
		FPD_RenderDevice dc, 
		FS_AffineMatrix matrix, 
		FPD_AnnotAppearanceMode eMode, 
		const FPD_RenderOptions opts);

	//************************************
	// Function:  DrawInContext
	// Param[in]: annot		The input annotation.
	// Param[in]: page		The page it belongs to.
	// Param[in]: context	The context to draw in.
	// Param[in]: matrix	The transformation matrix from user space to device space.
	// Param[in]: eMode		The input appearance mode.
	// Return:    <a>TRUE</a> if the appearance successfully found and drawn.
	// Remarks:   Draws annotation's appearance in rendering context.
	// Notes:
	//************************************
	static FS_BOOL DrawInContext(
		FPD_Annot annot, 
		const FPD_Page page, 
		const FPD_RenderContext context,
		FS_AffineMatrix matrix, 
		FPD_AnnotAppearanceMode eMode
		);

	//************************************
	// Function:  ClearCachedAP
	// Param[in]: annot		The input annotation.
	// Return:    void
	// Remarks:   Clears all cached appearance, when the application changed any appearance settings.
	// Notes:
	//************************************
	static void	ClearCachedAP(FPD_Annot annot);

	//************************************
	// Function:  DrawBorder
	// Param[in]: annot		The input annotation.
	// Param[in]: dc		The device to draw on.
	// Param[in]: matrix	The transformation matrix from user space to device space.
	// Param[in]: opts		The render options.
	// Return:    void
	// Remarks:   Draws border of the annotation, using border settings within the dictionary.
	// Notes:
	//************************************
	static void	DrawBorder(
		FPD_Annot annot, 
		FPD_RenderDevice dc, 
		FS_AffineMatrix matrix,
		const FPD_RenderOptions opts
		);


	//************************************
	// Function:  CountIRTNotes
	// Param[in]: annot		The input annotation.
	// Return:    The count of annotations in "in reply to" annotation list.
	// Remarks:   Gets the count of annotations in "in reply to" annotation list.
	// Notes:
	//************************************
	static FS_INT32	CountIRTNotes(FPD_Annot annot);

	//************************************
	// Function:  GetIRTNote
	// Param[in]: annot		The input annotation.
	// Param[in]: index		The zero-based index in the "in reply to" annotation list.
	// Return:    An "in reply to" annotation.
	// Remarks:   Gets an "in reply to" annotation. 
	// Notes:
	//************************************
	static FPD_Annot GetIRTNote(FPD_Annot annot, FS_INT32 index);

	//************************************
	// Function:  GetAPForm
	// Param[in]: annot		The input annotation.
	// Param[in]: page		The page it belongs to.
	// Param[in]: eMode		The input appearance mode.
	// Return:    A PDF form.
	// Remarks:   Gets an appearance stream.
	// Notes:
	//************************************
	static FPD_Form	GetAPForm(FPD_Annot annot, const FPD_Page page, FPD_AnnotAppearanceMode eMode);

    //************************************
    // Function:  SetPrivateData
    // Param[in]: annot		The input annotation.
    // Param[in]: module_id
    // Param[in]: pData
    // Param[in]: callback
    // Return:    void
    // Remarks:
    // Notes:
    //************************************
	static void    SetPrivateData(FPD_Annot annot, FS_LPVOID module_id, FS_LPVOID pData, FRPD_CALLBACK_FREEDATA callback);

    //************************************
    // Function:  GetPrivateData
    // Param[in]: annot		The input annotation.
    // Param[in]: module_id
    // Return:    FS_LPVOID
    // Remarks:
    // Notes:
    //************************************
	static FS_LPVOID       GetPrivateData(FPD_Annot annot, FS_LPVOID module_id);

	//************************************
	// Function:  GetAnnotList
	// Param[in]: annot		The input annotation.
	// Return:    FPD_AnnotList
	// Remarks:  Get the "in reply to" annotation list.
	// Notes:
	//************************************
	static FPD_AnnotList   GetAnnotList(FPD_Annot annot);
};



//////////////////////////////////////////////////////////////////////////////////////////////////////
/*									 CFPD_AnnotList_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_AnnotList_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: page		The input PDF page.
	// Return:    An annotation list.
	// Remarks:   Creates an annotation list from a PDF page.
	// Notes:
	//************************************
	static FPD_AnnotList New(FPD_Page page);

	//************************************
	// Function:  Destroy
	// Param[in]: annotList		The input annotation list.
	// Return:    void
	// Remarks:   Destroys an annotation list.
	// Notes:
	//************************************
	static void	Destroy(FPD_AnnotList annotList);
	
	//************************************
	// Function:  DisplayAnnots
	// Param[in]: annotList		The input annotation list.
	// Param[in]: page			The page it belongs to.
	// Param[in]: dc			The device to draw on.
	// Param[in]: matrix		The transformation matrix from objects space to device space.
	// Param[in]: bShowWidget	Whether to show widget or not.
	// Param[in]: opts			The render options.
	// Return:    void
	// Remarks:   Display all annotations with specified object to DC transformation.
	// Notes:
	//************************************
	static void	DisplayAnnots(
		FPD_AnnotList annotList, 
		const FPD_Page page, 
		FPD_RenderDevice dc, 
		FS_AffineMatrix matrix, 
		FS_BOOL bShowWidget, 
		FPD_RenderOptions opts
		);
	
	//************************************
	// Function:  DisplayAnnotsEx
	// Param[in]: annotList		The input annotation list.
	// Param[in]: pPage			The page it belongs to.
	// Param[in]: context		The context to draw in.
	// Param[in]: bPrinting		Whether to print or not.
	// Param[in]: matrix		The transformation matrix from objects space to device space.
	// Param[in]: bShowWidget	Whether to show widget or not.
	// Param[in]: opts			The render options.
	// Return:    void
	// Remarks:   Adds annotations to render job list, used in printing for transparency support.
	// Notes:
	//************************************
	static void	DisplayAnnotsEx(
		FPD_AnnotList annotList, 
		const FPD_Page pPage, 
		FPD_RenderContext context, 
		FS_BOOL bPrinting, 
		FS_AffineMatrix matrix, 
		FS_BOOL bShowWidget, 
		FPD_RenderOptions opts
		);
	


	//************************************
	// Function:  GetAt
	// Param[in]: annotList		The input annotation list.
	// Param[in]: index			The zero-based index in the annotation list.
	// Return:    An annotation.
	// Remarks:   Gets an annotation at specified position.
	// Notes:
	//************************************
	static FPD_Annot GetAt(FPD_AnnotList annotList, FS_INT32 index);

	//************************************
	// Function:  Count
	// Param[in]: annotList		The input annotation list.
	// Return:    The count of annotations in the annotation list.
	// Remarks:   Gets the count of annotations in the annotation list.
	// Notes:
	//************************************
	static FS_INT32	Count(FPD_AnnotList annotList);

	//************************************
	// Function:  GetIndex
	// Param[in]: annotList		The input annotation list.
	// Param[in]: annot			The input annotation.
	// Return:    The zero-based index in the annotation list.
	// Remarks:   Gets the annotation's index.
	// Notes:
	//************************************
	static FS_INT32	GetIndex(FPD_AnnotList annotList, FPD_Annot annot);


	//************************************
	// Function:  RemoveAll
	// Param[in]: annotList		The input annotation list.
	// Return:    void
	// Remarks:   Removes all the annotations.
	// Notes:     Operations to the annotation list will be reflected in the PDF document structure.
	//            For example, the "Annots" array of page dictionary will get changed.
	//************************************
	static void	RemoveAll(FPD_AnnotList annotList);

	//************************************
	// Function:  Replace
	// Param[in]: annotList		The input annotation list.
	// Param[in]: index			The zero-based index in the annotation list.
	// Param[in]: annot			The new annotation.
	// Return:    void
	// Remarks:   Replaces the specified position with a new annotation.
	// Notes:
	//************************************
	static void	Replace(FPD_AnnotList annotList, FS_INT32 index, FPD_Annot annot);

	//************************************
	// Function:  Insert
	// Param[in]: annotList		The input annotation list.
	// Param[in]: index			The zero-based index to insert before.
	// Param[in]: annot			The annotation to insert.
	// Return:    void
	// Remarks:   Inserts BEFORE the index, if index equals to current count, then append.
	// Notes:
	//************************************
	static void	Insert(FPD_AnnotList annotList, FS_INT32 index, FPD_Annot annot);

	//************************************
	// Function:  Remove
	// Param[in]: annotList		The input annotation list.
	// Param[in]: index			The zero-based index of the annotation to be removed.
	// Return:    void
	// Remarks:   Removes an annotation.
	// Notes:
	//************************************
	static void	Remove(FPD_AnnotList annotList, FS_INT32 index);

	//************************************
	// Function:  RemoveTemp
	// Param[in]: annotList		The input annotation list.
	// Param[in]: index			The zero-based index of the annotation to be removed.
	// Return:    void
	// Remarks:   Removes from list only, not from page.
	// Notes:
	//************************************
	static void	RemoveTemp(FPD_AnnotList annotList, FS_INT32 index);

	//************************************
	// Function:  MoveToFirst
	// Param[in]: annotList		The input annotation list.
	// Param[in]: index			The zero-based index of the annotation to be moved.
	// Return:    void
	// Remarks:   Moves an annotation to the first of the annotation list.
	// Notes:
	//************************************
	static void	MoveToFirst(FPD_AnnotList annotList, FS_INT32 index);

	//************************************
	// Function:  MoveToLast
	// Param[in]: annotList		The input annotation list.
	// Param[in]: index			The zero-based index of the annotation to be moved.
	// Return:    void
	// Remarks:   Moves an annotation to the last of the annotation list.
	// Notes:
	//************************************
	static void	MoveToLast(FPD_AnnotList annotList, FS_INT32 index);

	//************************************
	// Function:  MoveTo
	// Param[in]: annotList		The input annotation list.
	// Param[in]: annot			The annotation to be moved.
	// Param[in]: iNewIndex		The new position to move to.
	// Return:    void
	// Remarks:   Moves an annotation to specified position.
	// Notes:
	//************************************
	static void	MoveTo(FPD_AnnotList annotList, FPD_Annot annot, FS_INT32 iNewIndex);

	//************************************
	// Function:  GetDocument
	// Param[in]: annotList		The input annotation list.
	// Return:    The PDF document.
	// Remarks:   Gets the PDF document.
	// Notes:
	//************************************
	static FPD_Document	GetDocument(FPD_AnnotList annotList);

	//************************************
	// Function:  SetFixedIconParams
	// Param[in]: annotList			The input annotation list.
	// Param[in]: nFixedIconType	Indicates how to display fixed annotations.
	// 0 is to show as normal annotations, ignore NoZoom or NoRotate flag,
	// and 1 is to show as fixed scaling size, <param>sx</param> and <param>sy</param> specifies scaling fractors in x and y axes,
	// and 2 is to show as fixed device size which is specified by <param>sx</param> and <param>sy</param> in device units.
	// Param[in]: sx				Fixed scaling size or fixed device size according to the value of <param>nFixedIconType</param> in x axis.
	// Param[in]: sy				Fixed scaling size or fixed device size according to the value of <param>nFixedIconType</param> in y axis.
	// Param[in]: nRotate			Page rotation, valid values are 0, 1, 2, 3, same as <a>FPDPageGetDisplayMatrix</a>.
	// Return:    The PDF document.
	// Remarks:   Enable to show icon annotations as fixed size (NoZoom or NoRotate flag).
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	//************************************
	static void SetFixedIconParams(FPD_AnnotList annotList, FS_INT32 nFixedIconType, FS_FLOAT sx, FS_FLOAT sy, FS_INT32 nRotate);
	
	//************************************
	// Function:  GetAnnotMatrix
	// Param[in]: annotList			The input annotation list.
	// Param[in]: pAnnotDict		Annotation's dictionary object.
	// Param[in]: pUser2Device		Current displaying transformation matrix.
	// Param[out]: outMatrix		Annotation matrix to display.
	// Return:    void.
	// Remarks:   Gets annotation transformation matrix from page space to device space.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	//************************************
	static void GetAnnotMatrix(FPD_AnnotList annotList, FPD_Object pAnnotDict, FS_AffineMatrix pUser2Device, FS_AffineMatrix* outMatrix);
	
	//************************************
	// Function:  GetAnnotRect
	// Param[in]: annotList			The input annotation list.
	// Param[in]: pAnnotDict		Annotation's dictionary object.
	// Param[in]: pUser2Device		Transformation matrix from user space to device space.
	// Param[out]: outAnnotRC		Annotation rectangle in device coordinates.
	// Return:    void.
	// Remarks:   Gets annotation rectangle in device coordinates.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	//************************************
	static void GetAnnotRect(FPD_AnnotList annotList, FPD_Object pAnnotDict, FS_AffineMatrix pUser2Device, FS_FloatRect* outAnnotRC);
	
	//************************************
	// Function:  GetPage
	// Param[in]: annotList			The input annotation list.	
	// Return:    FPD_Page          Get the PDF Page.
	// Remarks:   Get the PDF Page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FPD_Page			GetPage(FPD_AnnotList annotList);

	//************************************
	// Function:  GetAnnotByDict
	// Param[in]: annotList			The input annotation list.	
	// Param[in]: pAnnotDict		The input annotation dictionary.	
	// Return:    FPD_Annot         Get the annot.
	// Remarks:   Get the annot by specified dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	//************************************
	static FPD_Annot	GetAnnotByDict(FPD_AnnotList annotList, FPD_Object pAnnotDict);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Interactive forms
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
/*							 CFPD_DefaultAppearance_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_DefaultAppearance_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: szAppearance		The input default appearance string.
	// Return:    Default appearance interpreter, serves for DA entry in form field dictionary.
	// Remarks:   Creates from a default appearance string that containing a sequence of valid 
    //            page-content graphics or text state operators that define such properties as the field's 
	//            text size and color.
	// Notes:
	//************************************
	static FPD_DefaultAppearance New(FS_LPCSTR szAppearance);

	//************************************
	// Function:  Destroy
	// Param[in]: defAppearance		The input default appearance interpreter.
	// Return:    void
	// Remarks:   Destroys default appearance interpreter.
	// Notes:
	//************************************
	static void	Destroy(FPD_DefaultAppearance defAppearance);

	
	//************************************
	// Function:  HasFont
	// Param[in]: defAppearance		The input default appearance interpreter.
	// Return:    <a>TRUE</a> for a font having been used in the appearance, otherwise not.
	// Remarks:   Checks whether a font has been used in the appearance. 
	// Notes:
	//************************************
	static FS_BOOL HasFont(FPD_DefaultAppearance defAppearance);

	//************************************
	// Function:  GetFontString
	// Param[in]: defAppearance		The input default appearance interpreter.
	// Param[out]:outFontString		It receives the font instruction in the appearance string.
	// Return:    void
	// Remarks:   Gets the font instruction in the appearance string.
	// Notes:
	//************************************
	static void	GetFontString(FPD_DefaultAppearance defAppearance, FS_ByteString* outFontString);

	//************************************
	// Function:  GetFont
	// Param[in]: defAppearance		The input default appearance interpreter.
	// Param[out]:outFontNameTag	It receives font name tag of font.
	// Param[out]:outFontSize		It receives the font size of the font.
	// Return:    void
	// Remarks:   Gets the font. 
	// Notes:
	//************************************
	static void	GetFont(FPD_DefaultAppearance defAppearance, FS_ByteString* outFontNameTag, FS_FLOAT* outFontSize);

	//************************************
	// Function:  SetFont
	// Param[in]: defAppearance		The input default appearance interpreter.
	// Param[in]: szFontNameTag		The font name tag of the font.
	// Param[in]: fFontSize			The size of the font.
	// Return:    void
	// Remarks:   Sets the font name tag and size of the font.
	// Notes:
	//************************************
	static void	SetFont(FPD_DefaultAppearance defAppearance, FS_LPSTR szFontNameTag, FS_FLOAT fFontSize);


	//************************************
	// Function:  HasColor
	// Param[in]: defAppearance			The input default appearance interpreter.
	// Param[in]: bStrokingOperation	Whether the stroking color to be checked.
	// Return:    Non-zero means having one, otherwise having none.
	// Remarks:   Checks whether a color has been used in the appearance.
	// Notes:
	//************************************
	static FS_BOOL HasColor(FPD_DefaultAppearance defAppearance, FS_BOOL bStrokingOperation);

	//************************************
	// Function:  GetColorString
	// Param[in]: defAppearance			The input default appearance interpreter.
	// Param[in]: bStrokingOperation	Whether the stroking color instruction to be fetched.
	// Param[out]:outColorString		The color instruction in the appearance string.
	// Return:    void
	// Remarks:   Gets the color instruction in the appearance string.
	// Notes:
	//************************************
	static void	GetColorString(
		FPD_DefaultAppearance defAppearance, 
		FS_BOOL bStrokingOperation, 
		FS_ByteString* outColorString
		);

	//************************************
	// Function:  GetColorInclueCMYK
	// Param[in]: defAppearance			The input default appearance interpreter.
	// Param[out]:pIclrType				It receives the color type.
	// Param[out]:fc[4]					It receives the color values of components.
	// Param[in]: bStrokingOperation	Whether the stroking color to be fetched.
	// Return:    void
	// Remarks:   Gets the color (including CMYK).
	// Notes:
	//************************************
	static void	GetColorInclueCMYK(
		FPD_DefaultAppearance defAppearance, 
		FS_INT32* pIclrType, 
		FS_FLOAT fc[4], 
		FS_BOOL bStrokingOperation
		);

	//************************************
	// Function:  GetColor
	// Param[in]: defAppearance			The input default appearance interpreter.
	// Param[out]:pClr					It receives the color.
	// Param[out]:pIclrType				It receives the color type.
	// Param[in]: bStrokingOperation	Whether the stroking color to be fetched.
	// Return:    void
	// Remarks:   Gets the color (not including CMYK).
	// Notes:
	//************************************
	static void	GetColor(
		FPD_DefaultAppearance defAppearance, 
		FS_ARGB* pClr, 
		FS_INT32* pIclrType, 
		FS_BOOL bStrokingOperation
		);

	//************************************
	// Function:  SetColor
	// Param[in]: defAppearance			The input default appearance interpreter.
	// Param[in]: clr					The input color.
	// Param[in]: iClrType				The input color type.
	// Param[in]: bStrokingOperation	Whether the stroking color to be set.
	// Return:    void
	// Remarks:   Sets the color.
	// Notes:
	//************************************
	static void	SetColor(
		FPD_DefaultAppearance defAppearance, 
		FS_ARGB clr, 
		FS_INT32 iClrType, 
		FS_BOOL bStrokingOperation
		);



	//************************************
	// Function:  HasTextMatrix
	// Param[in]: defAppearance		The input default appearance interpreter.
	// Return:    <a>TRUE</a> for a text matrix having been used in the appearance, otherwise not.
	// Remarks:   Checks whether a text matrix has been used in the appearance.
	// Notes:
	//************************************
	static FS_BOOL HasTextMatrix(FPD_DefaultAppearance defAppearance);

	//************************************
	// Function:  GetTextMatrixString
	// Param[in]: defAppearance			The input default appearance interpreter.
	// Param[out]:outMatrixString		It receives the text matrix instruction in the appearance string.
	// Return:    void
	// Remarks:   Gets the text matrix instruction in the appearance string.
	// Notes:
	//************************************
	static void	GetTextMatrixString(FPD_DefaultAppearance defAppearance, FS_ByteString* outMatrixString);

	//************************************
	// Function:  GetTextMatrix
	// Param[in]: defAppearance		The input default appearance interpreter.
	// Return:    The text matrix.
	// Remarks:   Gets the text matrix.
	// Notes:
	//************************************
	static FS_AffineMatrix GetTextMatrix(FPD_DefaultAppearance defAppearance);

	//************************************
	// Function:  SetTextMatrix
	// Param[in]: defAppearance		The input default appearance interpreter.
	// Param[in]: matrix			The input text matrix.
	// Return:    void
	// Remarks:   Sets the text matrix.
	// Notes:
	//************************************
	static void	SetTextMatrix(FPD_DefaultAppearance defAppearance, FS_AffineMatrix matrix);
	
	//************************************
	// Function:  GetFontSize
	// Param[in]: defAppearance		The input default appearance interpreter.	
	// Return:    FS_FLOAT    It receives the font size.
	// Remarks:   Get the font size when there is no font.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_FLOAT	GetFontSize(FPD_DefaultAppearance defAppearance);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*									 CFPD_InterForm_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_CustomerFormNotifyHandler : public CPDF_FormNotify
{
public:
	CFPD_CustomerFormNotifyHandler(const FPD_FormNotifyCallbacksRec* pNotify);
	virtual FS_INT32		BeforeValueChange(const CPDF_FormField* pField, CFX_WideString& csValue);
	virtual FS_INT32		AfterValueChange(const CPDF_FormField* pField);
	virtual FS_INT32		BeforeSelectionChange(const CPDF_FormField* pField, CFX_WideString& csValue);
	virtual FS_INT32		AfterSelectionChange(const CPDF_FormField* pField);
	virtual FS_INT32		AfterCheckedStatusChange(const CPDF_FormField* pField, const CFX_ByteArray& statusArray);
	virtual FS_INT32		BeforeFormReset(const CPDF_InterForm* pForm);
	virtual FS_INT32		AfterFormReset(const CPDF_InterForm* pForm);
	virtual FS_INT32		BeforeFormImportData(const CPDF_InterForm* pForm);
	virtual FS_INT32		AfterFormImportData(const CPDF_InterForm* pForm);

//protected:
	FPD_FormNotifyCallbacksRec m_Notify;
	
};

class CFPD_FormNotify_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: callbacks		The callback set.
	// Return:    A newly form notify object.
	// Remarks:   Creates a form notify object.
	// See: FPDInterFormGetFormNotify
	// See: FPDInterFormSetFormNotify
	// See: FPDFormNotifyDestroy
	// Notes:
	//************************************
	static FPD_FormNotify New(FPD_FormNotifyCallbacks callbacks);

	//************************************
	// Function:  Destroy
	// Param[in]: formNotify	The <a>FPD_FormNotify</a> object to be destroied.
	// Return:    void
	// Remarks:   Destroys a form notify object.
	// Notes:
	//************************************
	static void Destroy(FPD_FormNotify formNotify);
};

class CFPD_InterForm_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: doc			The PDF document.
	// Param[in]: bUpdateAP		Whether we need to regenerate appearance streams for fields.
	// Return:    A PDF interactive form.
	// Remarks:   Creates a form from a document. The bUpdateAP param specifies whether we need to 
	//            regenerate appearance streams for the fields.
	// Notes:
	//************************************
	static FPD_InterForm New(FPD_Document doc, FS_BOOL bUpdateAP);

	//************************************
	// Function:  Destroy
	// Param[in]: form		The input PDF interactive form.
	// Return:    void
	// Remarks:   Destroys a PDF interactive form.
	// Notes:
	//************************************
	static void	Destroy(FPD_InterForm form);


	//************************************
	// Function:  EnableUpdateAP
	// Param[in]: bUpdateAP		the input auto-update-appearance flag.
	// Return:    void
	// Remarks:   Change the auto-update-appearance flag.
	// Notes:
	//************************************
	static void	EnableUpdateAP(FS_BOOL bUpdateAP);

	//************************************
	// Function:  UpdatingAPEnabled
	// Param[in]: void
	// Return:    <a>TRUE</a> for needing to update appearance automatically.
	// Remarks:   Checks whether need to update appearance automatically.
	// Notes:
	//************************************
	static FS_BOOL UpdatingAPEnabled(void);

	//************************************
	// Function:  GenerateNewResourceName
	// Param[in]: resDict		An existing resource dictionary.
	// Param[in]: csType		Specifies resource type to generate a new name string, currently,
	//							it can be ExtGState, ColorSpace, Font, any other is no sense.
	// Param[in]: iMinLen		The minimum length of the resource name.
	// Param[in]: csPrefix		A prefix string to add in the head of he new resource name.
	// Param[out]:outName		A resource tag name.
	// Return:    void
	// Remarks:   Generate a new resource tag name, especially for ExtGState, ColorSpace, Font, etc.
	// Notes:
	//************************************
	static void	GenerateNewResourceName(const FPD_Object resDict, FS_LPCSTR csType, FS_INT32 iMinLen, FS_LPSTR csPrefix, FS_ByteString* outName);


	//************************************
	// Function:  AddSystemDefaultFont
	// Param[in]: doc		The PDF document.
	// Return:    A PDF font.
	// Remarks:   Adds the system default font.
	// Notes:
	//************************************
	static FPD_Font	AddSystemDefaultFont(const FPD_Document doc);

	//************************************
	// Function:  AddSystemFont
	// Param[in]: doc			The PDF document.
	// Param[in]: szFontName	The input font name.
	// Param[in]: iCharSet		The input character set.
	// Return:    A PDF font.
	// Remarks:   Adds a system font with font name and character set. ANSI version.
	// Notes:
	//************************************
	static FPD_Font	AddSystemFont(const FPD_Document doc, FS_LPSTR szFontName, FS_BYTE iCharSet);

	//************************************
	// Function:  AddSystemFontW
	// Param[in]: doc			The PDF document.
	// Param[in]: wszFontName	he input font name.
	// Param[in]: iCharSet		The input character set.
	// Return:    A PDF font.
	// Remarks:   Adds a system font with font name and character set. Unicode version.
	// Notes:
	//************************************
	static FPD_Font	AddSystemFontW(const FPD_Document doc, FS_LPWSTR wszFontName, FS_BYTE iCharSet);

	//************************************
	// Function:  AddStandardFont
	// Param[in]: doc			The PDF document.
	// Param[in]: szFontName	The input font name.
	// Return:    A PDF font.
	// Remarks:   Adds a standard font with font name.
	// Notes:
	//************************************
	static FPD_Font	AddStandardFont(const FPD_Document doc, FS_LPSTR szFontName);

	//************************************
	// Function:  GetNativeFont
	// Param[in]: iCharSet		The input character set.
	// Param[out]:pLogFont		It receives the font information. Points to LOGFONTA structure.
	// Param[out]:outFont		The font name.
	// Return:    void
	// Remarks:   Gets the native font name with a character set and a logical font structure.
	// Notes:
	//************************************
	static void	GetNativeFont(FS_BYTE iCharSet, FS_LPVOID pLogFont, FS_ByteString* outFont);

	//************************************
	// Function:  GetNativeFont2
	// Param[out]:pLogFont		It receives the font information. Points to LOGFONTA structure.
	// Param[out]:outFont		The font name.
	// Return:    void
	// Remarks:   Gets the native font name with a logical font structure.
	// Notes:
	//************************************
	static void	GetNativeFont2(FS_LPVOID pLogFont, FS_ByteString* outFont);

	//************************************
	// Function:  AddNativeFont
	// Param[in]: iCharSet		The input character set.
	// Param[in]: doc			The PDF document.
	// Return:    A PDF font.
	// Remarks:   Adds a native font with a character set.
	// Notes:
	//************************************
	static FPD_Font	AddNativeFont(FS_BYTE iCharSet, const FPD_Document doc);

	//************************************
	// Function:  AddNativeFont2
	// Param[in]: doc	The PDF document.
	// Return:    A PDF font.
	// Remarks:   Adds the native font of the PDF document.
	// Notes:
	//************************************
	static FPD_Font	AddNativeFont2(const FPD_Document doc);


	//************************************
	// Function:  ValidateFieldName
	// Param[in]: form				The input PDF interactive form.
	// Param[in,out]:inOutNewFieldName	Input a field name and receives the valid field name.
	// Param[in]: iType				The field type. uses FPD_FORM_FIELDTYPE_X macros.
	// Return:    Non-zero means the input field name is valid, otherwise invalid.
	// Remarks:   Checks the field name of specified type is valid or not, receives the valid field name when it's invalid.
	// Notes:
	//************************************
	static FS_BOOL ValidateFieldName(FPD_InterForm form, FS_WideString* inOutNewFieldName, FS_INT32 iType);

	//************************************
	// Function:  ValidateFieldName2
	// Param[in]: form				The input PDF interactive form.
	// Param[in]: field				The input field.
	// Param[in,out]:inOutNewFieldName	Input a field name and receives the valid field name.
	// Return:    Non-zero means the input field name is valid, otherwise invalid.
	// Remarks:   Checks the field name for the input field is valid or not, receives the valid field name when it's invalid.
	// Notes:
	//************************************
	static FS_BOOL ValidateFieldName2(FPD_InterForm form, const FPD_FormField field, FS_WideString* inOutNewFieldName);

	//************************************
	// Function:  ValidateFieldName3
	// Param[in]: form				The input PDF interactive form.
	// Param[in]: control			The input control.
	// Param[in,out]:inOutNewFieldName	Input a field name and receives the valid field name.
	// Return:    Non-zero means the input field name is valid, otherwise invalid.
	// Remarks:   Checks the field name for the input control is valid or not, receives the valid field name when it's invalid.
	// Notes:
	//************************************
	static FS_BOOL ValidateFieldName3(FPD_InterForm form, const FPD_FormControl control, FS_WideString* inOutNewFieldName);

	//************************************
	// Function:  NewField
	// Param[in]: form					The input PDF interactive form.
	// Param[in,out]:inOutFieldName		Input a field name and receives the valid field full name.
	// Param[in]: iType					The input field type.
	// Return:    A form field.
	// Remarks:   Creates and add a field in form, param iType uses FPD_FORM_FIELDTYPE_X macros.
	//            inOutFieldName is in/out param. If succeed, csFieldName is the validated field full name.
	// Notes:
	//************************************
	static FPD_FormField NewField(FPD_InterForm form, FS_WideString* inOutFieldName, FS_INT32 iType);

	//************************************
	// Function:  NewControl
	// Param[in]: form					The input PDF interactive form.
	// Param[in,out]:inOutFieldName		Input a field name and receives the valid field full name.
	// Param[in]: iType					The input field type.
	// Return:    A form control.
	// Remarks:   Creates and add a control in form, param iType uses FPD_FORM_FIELDTYPE_X macros.
	//            inOutFieldName is in/out param. If succeed, inOutFieldName is the validated field full name.
	// Notes:     This Function will call NewField if necessary.
	//            Use this Function to create a control and use returned object to initialize Widget.
	//************************************
	static FPD_FormControl NewControl(FPD_InterForm form, FS_WideString* inOutFieldName, FS_INT32 iType);

	
	//************************************
	// Function:  CountFields
	// Param[in]: form				The input PDF interactive form.
	// Param[in]: wszFieldName		The input field name to be matched.
	//  -empty means for all fields; or system will match the field name.
	//  -as shortest string, for example, text1 will match text1.0, text1.2.0, etc. but text1 will not match test10 or test11.1..
	// Return:    The count of fields with specified field name to be matched. 
	// Remarks:   Gets the count of specified fields.
	// Notes:
	//************************************
	static FS_DWORD	CountFields(FPD_InterForm form, FS_LPWSTR wszFieldName);

	//************************************
	// Function:  GetField
	// Param[in]: form				The input PDF interactive form.
	// Param[in]: index				The zero-based field index in the matched field array.
	// Param[in]: wszFieldName		The field name to be matched.
	//  -empty means for all fields; or system will match the field name.
	//  -as shortest string, for example, text1 will match text1.0, text1.2.0, etc. but text1 will not match test10 or test11.1..
	// Return:    A form field.
	// Remarks:   Gets a form field.
	// Notes:
	//************************************
	static FPD_FormField GetField(FPD_InterForm form, FS_DWORD index, FS_LPWSTR wszFieldName);

	//************************************
	// Function:  GetAllFieldNames
	// Param[in]: form					The input PDF interactive form.
	// Param[out]:outAllFieldNames		It receives all field names in the form.
	// Return:    void
	// Remarks:   Gets all field names in the form.
	// Notes:
	//************************************
	static void	GetAllFieldNames(FPD_InterForm form, FS_WideStringArray* outAllFieldNames);

	//************************************
	// Function:  IsValidFormField
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: pField	The input pointer.
	// Return:    Non-zero means it's a form field pointer, otherwise is not.
	// Remarks:   Checks whether a pointer is a form field pointer.
	// Notes:
	//************************************
	static FS_BOOL IsValidFormField(FPD_InterForm form, const void* pField);

	//************************************
	// Function:  GetFieldByDict
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: fieldDict		The input form field dictionary.
	// Return:    A form field.
	// Remarks:   Retrieves the field by field dictionary.
	// Notes:
	//************************************
	static FPD_FormField GetFieldByDict(FPD_InterForm form, FPD_Object fieldDict);


	//************************************
	// Function:  CountControls
	// Param[in]: form				The input PDF interactive form.
	// Param[in]: wszFieldName		The input field name to be matched.
	//  -empty means for all fields; or system will match the field name.
	//  -as shortest string, for example, text1 will match text1.0, text1.2.0, etc. but text1 will not match test10 or test11.1..
	// Return:    The count of controls with specified field name to be matched. 
	// Remarks:   Gets the count of specified controls.
	// Notes:
	//************************************
	static FS_DWORD	CountControls(FPD_InterForm form, FS_LPWSTR wszFieldName);

	//************************************
	// Function:  GetControl
	// Param[in]: form				The input PDF interactive form.
	// Param[in]: index				The zero-based control index in the matched control array.
	// Param[in]: wszFieldName		The field name to be matched.
	//  -empty means for all fields; or system will match the field name.
	//  -as shortest string, for example, text1 will match text1.0, text1.2.0, etc. but text1 will not match test10 or test11.1..
	// Return:    A form control.
	// Remarks:   Gets a form control.
	// Notes:
	//************************************
	static FPD_FormControl GetControl(FPD_InterForm form, FS_DWORD index, FS_LPWSTR wszFieldName);

	//************************************
	// Function:  IsValidFormControl
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: pControl		The input pointer.
	// Return:    Non-zero means it's a form control pointer, otherwise is not.
	// Remarks:   Checks whether a pointer is a form control pointer.
	// Notes:
	//************************************
	static FS_BOOL IsValidFormControl(FPD_InterForm form, const void* pControl);

	//************************************
	// Function:  CountPageControls
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: page		The input PDF page.
	// Return:    The count of controls in specified page. 
	// Remarks:   Gets the count of controls in specified page.
	// Notes:
	//************************************
	static FS_INT32	CountPageControls(FPD_InterForm form, FPD_Page page);

	//************************************
	// Function:  GetPageControl
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: page		The input PDF page.
	// Param[in]: index		The zero-based control index in the page.
	// Return:    A control int the page.
	// Remarks:   Gets a control in specified page.
	// Notes:
	//************************************
	static FPD_FormControl GetPageControl(FPD_InterForm form, FPD_Page page, FS_INT32 index);

	//************************************
	// Function:  GetControlAtPoint
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: page		The input PDF page.
	// Param[in]: pdfX		The x-coordinate of mouse position in user space.
	// Param[in]: pdfY		The y-coordinate of mouse position in user space.
	// Return:    A control.
	// Remarks:   Retrieves the control by mouse position.
	// Notes:
	//************************************
	static FPD_FormControl GetControlAtPoint(FPD_InterForm form, FPD_Page page, FS_FLOAT pdfX, FS_FLOAT pdfY);

	//************************************
	// Function:  GetControlByDict
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: widgetDict	The input widget dictionary.
	// Return:    A control.
	// Remarks:   Retrieves the control by widget dictionary.
	// Notes:
	//************************************
	static FPD_FormControl GetControlByDict(FPD_InterForm form, FPD_Object widgetDict);


	//************************************
	// Function:  RenameField
	// Param[in]: form					The input PDF interactive form.
	// Param[in]: wszOldName			The field's old name.
	// Param[in,out]:inOutNewName		Input the field's new name and receive the validated field full name, if success.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Rename a field's full name. The field identified by it's old full name.
	// Notes:
	//************************************
	static FS_BOOL RenameField(FPD_InterForm form, FS_LPWSTR wszOldName, FS_WideString* inOutNewName);

	//************************************
	// Function:  RenameField2
	// Param[in]: form					The input PDF interactive form.
	// Param[in]: field					The input field.
	// Param[in,out]:inOutNewName		Input the field's new name and receive the validated field full name.if success.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Rename a field's full name. 
	// Notes:
	//************************************
	static FS_BOOL RenameField2(FPD_InterForm form, FPD_FormField field, FS_WideString* inOutNewName);

	//************************************
	// Function:  RenameControl
	// Param[in]: form					The input PDF interactive form.
	// Param[in]: pControl				The input control.
	// Param[in,out]:inOutNewName		Input the control's new name and receive the validated control full name.if success.
	// Return:    <a>TRUE</a> for success, otherwise not.
	// Remarks:   Rename a control's full name. 
	// Notes:
	//************************************
	static FS_BOOL RenameControl(FPD_InterForm form, FPD_FormControl pControl, FS_WideString* inOutNewName);

	//************************************
	// Function:  DeleteField
	// Param[in]: form				The input PDF interactive form.
	// Param[in]: wszFieldName		The input field name.
	// Return:    void
	// Remarks:   Deletes a field with specified field name.
	//            If csName is empty, means for all fields.
	// Notes:     When delete fields, all controls assigned to them will be deleted too.
	//************************************
	static void	DeleteField(FPD_InterForm form, FS_LPWSTR wszFieldName);

	//************************************
	// Function:  DeleteField2
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: field		The input field.
	// Return:    void
	// Remarks:   Deletes a field.
	//            Field object will be deleted if success.
	// Notes:     When delete fields, all controls assigned to them will be deleted too.
	//************************************
	static void	DeleteField2(FPD_InterForm form, FPD_FormField field);

	//************************************
	// Function:  DeleteControl
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: control		The input control.
	// Return:    void
	// Remarks:   Deletes a control.
	//            control object will be deleted if success.
	// Notes:     When delete controls, corresponding fields will be deleted only when they have no any control associated
	//  with them. If csFieldName is empty, it means to all fields or controls.
	//************************************
	static void	DeleteControl(FPD_InterForm form, FPD_FormControl control);


	//************************************
	// Function:  CountInternalFields
	// Param[in]: form				The input PDF interactive form.
	// Param[in]: wszFieldName		The input field name to be matched.
	//  -If empty, this will retrieve all internal field dictionaries from the root list of the whole form.
	//  -If has value, all internal fields which names match the csfieldName will return.
	// Return:    The count of internal fields with specified field name to be matched. 
	// Remarks:   Gets the count of specified internal fields.
	// Notes:
	//************************************
	static FS_DWORD	CountInternalFields(FPD_InterForm form, FS_LPWSTR wszFieldName);

	//************************************
	// Function:  GetInternalField
	// Param[in]: form				The input PDF interactive form.
	// Param[in]: index				The zero-based internal field index in the matched internal field array.
	// Param[in]: wszFieldName		The field name to be matched.
	//  -If empty, this will retrieve all internal field dictionaries from the root list of the whole form.
	//  -If has value, all internal fields which names match the csfieldName will return.
	// Return:	  The internal field dictionary.
	// Remarks:   Gets an internal field.
	// Notes:
	//************************************
	static FPD_Object GetInternalField(FPD_InterForm form, FS_DWORD index, FS_LPWSTR wszFieldName);


	//************************************
	// Function:  GetDocument
	// Param[in]: form		The input PDF interactive form.
	// Return:    The PDF document.
	// Remarks:   Gets the PDF document.
	// Notes:
	//************************************
	static FPD_Document	GetDocument(FPD_InterForm form);

	//************************************
	// Function:  GetFormDict
	// Param[in]: form		The input PDF interactive form.
	// Return:    The AcroForm dictionary.
	// Remarks:   Gets the AcroForm dictionary.
	// Notes:
	//************************************
	static FPD_Object GetFormDict(FPD_InterForm form);


	//************************************
	// Function:  NeedConstructAP
	// Param[in]: form		The input PDF interactive form.
	// Return:    <a>TRUE</a> for constructing appearance streams and appearance dictionaries, otherwise not.
	// Remarks:   Checks whether to construct appearance streams and appearance dictionaries for all widget annotations in the document.
	// Notes:
	//************************************
	static FS_BOOL NeedConstructAP(FPD_InterForm form);

	//************************************
	// Function:  NeedConstructAP2
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: bNeedAP		The input construct flag.
	// Return:    void
	// Remarks:   Sets the construct flag.
	// Notes:
	//************************************
	static void	NeedConstructAP2(FPD_InterForm form, FS_BOOL bNeedAP);


	//************************************
	// Function:  CountFieldsInCalculationOrder
	// Param[in]: form		The input PDF interactive form.
	// Return:    The count of all fields in CO array.
	// Remarks:   The count of all fields in CO array.
	// Notes:
	//************************************
	static FS_INT32	CountFieldsInCalculationOrder(FPD_InterForm form);

	//************************************
	// Function:  GetFieldInCalculationOrder
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: index		The zero-based field index in the CO array.
	// Return:    A form field.
	// Remarks:   Gets a form field from the calculation array.
	// Notes:
	//************************************
	static FPD_FormField GetFieldInCalculationOrder(FPD_InterForm form, FS_INT32 index);

	//************************************
	// Function:  FindFieldInCalculationOrder
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: field		The input form field.
	// Return:    The zero-based index of the specified field in the CO array. -1 means not found.
	// Remarks:   Finds a form field in the CO array.
	// Notes:
	//************************************
	static FS_INT32	FindFieldInCalculationOrder(FPD_InterForm form, const FPD_FormField field);

	//************************************
	// Function:  InsertFieldInCalculationOrder
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: field		The input form field.
	// Param[in]: index		The zero-based field index in the CO array to insert at.
	// Return:    The zero-based index of the inserted field. -1 means failed.
	// Remarks:   Inserts a form field to the CO array.
	// Notes:
	//************************************
	static FS_INT32	InsertFieldInCalculationOrder(FPD_InterForm form, const FPD_FormField field, FS_INT32 index );

	//************************************
	// Function:  MoveFieldInCalculationOrder
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: field			The input form field.
	// Param[in]: iNewIndex		The new zero-based field index in the CO array.
	// Return:    The current index of specified field. -1 means failed.
	// Remarks:   Moves a form field in the CO array to another position.
	// Notes:
	//************************************
	static FS_INT32	MoveFieldInCalculationOrder(FPD_InterForm form, const FPD_FormField field, FS_INT32 iNewIndex);

	//************************************
	// Function:  RemoveFieldInCalculationOrder
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: field		The input form field to be removed.
	// Return:    void
	// Remarks:   Removes a field in the CO array.
	// Notes:
	//************************************
	static void	RemoveFieldInCalculationOrder(FPD_InterForm form, const FPD_FormField field);


	//************************************
	// Function:  CountFormFonts
	// Param[in]: form		The input PDF interactive form.
	// Return:    The count of font resources.
	// Remarks:   Gets the count of font resources.
	// Notes:
	//************************************
	static FS_DWORD	CountFormFonts(FPD_InterForm form);

	//************************************
	// Function:  GetFormFont
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: index			The zero-based font index in the font resources.
	// Param[out]:outNameTag	It receives the name tag of the font, such as /Helv (get rid of slash).
	// Return:    A PDF font.
	// Remarks:   Gets a PDF font from the font resources.
	// Notes:
	//************************************
	static FPD_Font	GetFormFont(FPD_InterForm form, FS_DWORD index, FS_ByteString* outNameTag);

	//************************************
	// Function:  GetFormFont2
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: szNameTag		the name tag of the font, such as /Helv (get rid of slash).
	// Return:    A PDF font.
	// Remarks:   Gets a PDF font with specified name tag.
	// Notes:
	//************************************
	static FPD_Font	GetFormFont2(FPD_InterForm form, FS_LPSTR szNameTag);

	//************************************
	// Function:  GetFormFont3
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: szFontName	The input font name.
	// Param[out]:outNameTag	It receives the name tag of the font, such as /Helv (get rid of slash).
	// Return:    A PDF font.
	// Remarks:   Finds a PDF font with specified font name.
	// Notes:
	//************************************
	static FPD_Font	GetFormFont3(FPD_InterForm form, FS_LPSTR szFontName, FS_ByteString* outNameTag);

	//************************************
	// Function:  GetNativeFormFont
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: iCharSet		The input character set.
	// Param[out]:outNameTag	It receives the name tag of the font, such as /Helv (get rid of slash).
	// Return:    A PDF font.
	// Remarks:   Gets a native-form font with a character set.
	// Notes:
	//************************************
	static FPD_Font	GetNativeFormFont(FPD_InterForm form, FS_BYTE iCharSet, FS_ByteString* outNameTag);

	//************************************
	// Function:  GetNativeFormFont2
	// Param[in]: form			The input PDF interactive form.
	// Param[out]:outNameTag	It receives the name tag of the font, such as /Helv (get rid of slash).
	// Return:    A PDF font.
	// Remarks:   Gets the native-form font.
	// Notes:
	//************************************
	static FPD_Font	GetNativeFormFont2(FPD_InterForm form, FS_ByteString* outNameTag);

	//************************************
	// Function:  FindFormFont
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: font			The input PDF font.
	// Param[out]:outNameTag	It receives the name tag of the font, such as /Helv (get rid of slash).
	// Return:    Non-zero means found, otherwise not found.
	// Remarks:   Finds a font with font pointer.
	// Notes:
	//************************************
	static FS_BOOL FindFormFont(FPD_InterForm form, const FPD_Font font, FS_ByteString* outNameTag);

	//************************************
	// Function:  FindFormFont2
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: szFontName	The input font name.
	// Param[out]:outFont		It receives the found PDF font.
	// Param[out]:outNameTag	It receives the name tag of the font, such as /Helv (get rid of slash).
	// Return:    Non-zero means found, otherwise not found.
	// Remarks:   Finds a font with font name. ANSI version.
	// Notes:
	//************************************
	static FS_BOOL FindFormFont2(FPD_InterForm form, FS_LPSTR szFontName, FPD_Font* outFont, FS_ByteString* outNameTag);

	//************************************
	// Function:  FindFormFont3
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: wszFontName	The input font name.
	// Param[out]:outFont		It receives the found PDF font.
	// Param[out]:outNameTag	It receives the name tag of the font, such as /Helv (get rid of slash).
	// Return:    Non-zero means found, otherwise not found.
	// Remarks:   Finds a font with font name. Unicode version.
	// Notes:
	//************************************
	static FS_BOOL FindFormFont3(FPD_InterForm form, FS_LPWSTR wszFontName, FPD_Font* outFont, FS_ByteString* outNameTag);

	//************************************
	// Function:  AddFormFont
	// Param[in]: form				The input PDF interactive form.
	// Param[in]: font				The input PDF font.
	// Param[in,out]:inOutNameTag	Input a name tag and receive a valid name tag of the font, such as /Helv (get rid of slash).
	// Return:    void
	// Remarks:   Adds a form font with specified name tag.
	// Notes:
	//************************************
	static void	AddFormFont(FPD_InterForm form, const FPD_Font font, FS_ByteString* inOutNameTag);

	//************************************
	// Function:  AddNativeFormFont
	// Param[in]: form				The input PDF interactive form.
	// Param[in]: iCharSet			The input character set.
	// Param[in,out]:inOutNameTag	Input a name tag and receive a valid name tag of the font, such as /Helv (get rid of slash).
	// Return:    A PDF font.
	// Remarks:   Adds a native form font with specified name tag.
	// Notes:
	//************************************
	static FPD_Font	AddNativeFormFont(FPD_InterForm form, FS_BYTE iCharSet, FS_ByteString* inOutNameTag);

	//************************************
	// Function:  AddNativeFormFont2
	// Param[in]: form				The input PDF interactive form.
	// Param[in,out]:inOutNameTag	Input a name tag and receive a valid name tag of the font, such as /Helv (get rid of slash).
	// Return:    A PDF font.
	// Remarks:   Adds the native form font.
	// Notes:
	//************************************
	static FPD_Font	AddNativeFormFont2(FPD_InterForm form, FS_ByteString* inOutNameTag);

	//************************************
	// Function:  RemoveFormFont
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: font		The input PDF font pointer.
	// Return:    void
	// Remarks:   Removes a form font with font pointer.
	// Notes:
	//************************************
	static void	RemoveFormFont(FPD_InterForm form, const FPD_Font font);

	//************************************
	// Function:  RemoveFormFont2
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: szNameTag		The input name tag of the font, such as /Helv (get rid of slash).
	// Return:    void
	// Remarks:   Removes a form font with specified name tag.
	// Notes:
	//************************************
	static void	RemoveFormFont2(FPD_InterForm form, FS_LPCSTR szNameTag);
	

	//************************************
	// Function:  GetDefaultAppearance
	// Param[in]: form			The input PDF interactive form.
	// Param[out]:outDefAP		The default appearance interpreter.
	// Return:    void
	// Remarks:   Gets the default appearance interpreter.
	// Notes:     Do not forget to save default appearance after you change any setting in it when you
	//   retrieve an object of FPD_DefaultAppearance by GetDefaultAppearance method.
	//************************************
	static void	GetDefaultAppearance(FPD_InterForm form, FPD_DefaultAppearance* outDefAP);

	//************************************
	// Function:  SetDefaultAppearance
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: cDA		The input default appearance interpreter.
	// Return:    void
	// Remarks:   Sets the default appearance interpreter.
	// Notes:
	//************************************
	static void	SetDefaultAppearance(FPD_InterForm form, const FPD_DefaultAppearance cDA);

	//************************************
	// Function:  GetDefaultFormFont
	// Param[in]: form		The input PDF interactive form.
	// Return:    The default form font. 
	// Remarks:   Gets the default form font. 
	// Notes:
	//************************************
	static FPD_Font GetDefaultFormFont(FPD_InterForm form);

	//************************************
	// Function:  SetDefaultFormFont
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: font		The input font.
	// Return:    void
	// Remarks:   Sets the default form font.
	// Notes:
	//************************************
	static void	SetDefaultFormFont(FPD_InterForm form, const FPD_Font font);


	//************************************
	// Function:  GetFormAlignment
	// Param[in]: form		The input PDF interactive form.
	// Return:    alignment value: 
	//   <ul>
	//   <li>0 - left alignment, the default setting.</li>
	//   <li>1 - centered.</li>
	//   <li>2 - right alignment.</li>
	//   </ul>
	// Remarks:   Gets the form alignment.
	// Notes:
	//************************************
	static FS_INT32	GetFormAlignment(FPD_InterForm form);

	//************************************
	// Function:  SetFormAlignment
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: iAlignment	The input form alignment type.
	//   <ul>
	//   <li>0 - left alignment, the default setting.</li>
	//   <li>1 - centered,</li>
	//   <li>2 - right alignment.</li>
	//   </ul>
	// Return:    void
	// Remarks:   Sets the form alignment.
	// Notes:
	//************************************
	static void	SetFormAlignment(FPD_InterForm form, FS_INT32 iAlignment);


	//************************************
	// Function:  CheckRequiredFields
	// Param[in]: form					The input PDF interactive form.
	// Param[in]: fields				The input form fields array. fields is the array of FPD_FormField.
	// Param[in]: bIncludeOrExclude		Whether to include or exclude the required fields.
	// Return:    The checked form field.
	// Remarks:   Checks the required fields' checked flag.
	// Notes:
	//************************************
	static FPD_FormField CheckRequiredFields(FPD_InterForm form, const FS_PtrArray fields, FS_BOOL bIncludeOrExclude);

	//************************************
	// Function:  ExportToFDF
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: szPDFPath		The input FDF file full path.
	// Return:    A FDF document.
	// Remarks:   Exports the interactive form to a FDF format file.
	// Notes:
	//************************************
	static FDF_Document ExportToFDF(FPD_InterForm form, FS_LPCWSTR szPDFPath);

	//************************************
	// Function:  ExportToFDF2
	// Param[in]: form					The input PDF interactive form.
	// Param[in]: szPDFPath				The input FDF file full path.
	// Param[in]: fields				The input form fields array. fields is the array of FPD_FormField.
	// Param[in]: bIncludeOrExclude		Whether to include or exclude the form fields.
	// Return:    A FDF document.
	// Remarks:   Exports the interactive form to a FDF format file, include or exclude some fields. 
	// Notes:
	//************************************
	static FDF_Document	ExportToFDF2(FPD_InterForm form, FS_LPCWSTR szPDFPath, FS_PtrArray fields, FS_BOOL bIncludeOrExclude);

	//************************************
	// Function:  ImportFromFDF
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: FDFDoc		The input FDF document.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Imports a FDF document.
	// Notes:
	//************************************
	static FS_BOOL ImportFromFDF(FPD_InterForm form, const FDF_Document FDFDoc, FS_BOOL bNotify);


	//************************************
	// Function:  ResetForm
	// Param[in]: form					The input PDF interactive form.
	// Param[in]: fields				The input form fields array. Fields is the array of FPD_FormField.
	// Param[in]: bIncludeOrExclude		Whether to include or exclude the form fields.
	// Param[in]: bNotify				Whether to do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Resets form fields.
	// Notes:
	//************************************
	static FS_BOOL ResetForm(FPD_InterForm form, const FS_PtrArray fields, FS_BOOL bIncludeOrExclude, FS_BOOL bNotify);

	//************************************
	// Function:  ResetForm2
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: bNotify		Whether to do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Resets all form fields.
	// Notes:
	//************************************
	static FS_BOOL ResetForm2(FPD_InterForm form, FS_BOOL bNotify);

	//************************************
	// Function:  ReloadForm
	// Param[in]: form		The input PDF interactive form.
	// Return:    void
	// Remarks:   Reload the interactive form.
	// Notes:
	//************************************
	static void	ReloadForm(FPD_InterForm form);

	//************************************
	// Function:  GetFormNotify
	// Param[in]: form			The input PDF interactive form.
	// Return:	  A form notify handler.
	// Remarks:   Gets the form notify handler.
	// Notes:
	//************************************
	static FPD_FormNotify GetFormNotify(FPD_InterForm form);

	//************************************
	// Function:  SetFormNotify
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: pNotify		The notify callbacks.
	// Return:	  A previous form notify handler.
	// Remarks:   Sets the form notify handler.
	// Notes:
	//************************************
	static void SetFormNotify(FPD_InterForm form, FPD_FormNotify formNotify);

	//************************************
	// Function:  GetPageWithWidget
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: iCurPage		The current page index.
	// Param[in]: bNext			Whether to retrieve the next or previous page.
	// Return:	  The next or previous page index.
	// Remarks:   Retrieves the next or previous page for the page specified by iCurPage.
	// Notes:
	//************************************
	static FS_INT32	GetPageWithWidget(FPD_InterForm form, FS_INT32 iCurPage, FS_BOOL bNext);


	//************************************
	// Function:  IsUpdated
	// Param[in]: form		The input PDF interactive form.
	// Return:    <a>TRUE</a> for the form being updated.
	// Remarks:   Checks whether the form is updated.
	// Notes:
	//************************************
	static FS_BOOL IsUpdated(FPD_InterForm form);

	//************************************
	// Function:  ClearUpdatedFlag
	// Param[in]: form		The input PDF interactive form.
	// Return:    void
	// Remarks:   Clears the updated flag.
	// Notes:
	//************************************
	static void	ClearUpdatedFlag(FPD_InterForm form);

	//************************************
	// Function:  FixPageFields
	// Param[in]: form		The input PDF interactive form.
	// Param[in]: page		The input page dictionary.
	// Return:    void
	// Remarks:   Supplement some form field from a page
	// Notes:
	//************************************
	static void	FixPageFields(FPD_InterForm form, FPD_Page page);

	//************************************
	// Function:  AddControl
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: fieldDict		The input field dictionary.
	// Param[in]: pWidgetDict	The input widget dictionary.
	// Return:    A form control.
	// Remarks:   Adds a control to the PDF interactive form with a widget.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	//************************************
	static FPD_FormControl AddControl(FPD_InterForm form, const FPD_Object fieldDict, const FPD_Object pWidgetDict);

	//************************************
	// Function:  New2
	// Param[in]: doc			The PDF document.
	// Param[in]: bUpdateAP		Whether we need to regenerate appearance streams for fields.
	// Param[in]: bOmitTemplate	Whether we need to check Template in page.
	// Return:    A PDF interactive form.
	// Remarks:   Creates a form from a document. The bUpdateAP param specifies whether we need to 
	//            regenerate appearance streams for the fields.
	// Notes:
	//************************************
	static FPD_InterForm  New2(FPD_Document doc, FS_BOOLEAN bUpdateAP, FS_BOOLEAN bOmitTemplate);

	//************************************
	// Function:  ExportToFDF3
	// Param[in]: form			The input PDF interactive form.
	// Param[in]: pdf_path		The input FDF file full path.
	// Param[in]: fields	    The input form fields array. fields is the array of FPD_FormField.
	// Param[in]: bIncludeOrExclude		Whether to include or exclude the form fields.
	// Param[in]: bSimpleFileSpec	    Indicates whether use simple file specification format or full format. Default is full.
	// Param[in]: pHandler		The input FPD_FormExportHandler.
	// Param[in]: encoding	    The input code encode.
	// Return:    FDF_Document   A FDF document.
	// Remarks:   Export the interactive form to a FDF format file, include or exclude some fields. 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static FDF_Document  ExportToFDF3(FPD_InterForm form, FS_LPCWSTR pdf_path,
		FS_PtrArray* fields,
		FS_BOOLEAN bIncludeOrExclude,
		FS_BOOLEAN bSimpleFileSpec,
		FPD_FormExportHandler pHandler,
		FPD_EM_CODEENCODING encoding);

	//************************************
	// Function:  CreateField
	// Param[in]: form			     The input PDF interactive form.
	// Param[in]: pNewField		 The input field dictionary.
	// Param[in\ou]: csFieldName	 Input a field name and receive the valid field name.
	// Param[in]: pControls		 The param is controls in the old field. Default is NULL.
	// Return:    FPD_FormField    A form field.
	// Remarks:   Create a form field from field dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	//************************************
	static FPD_FormField  CreateField(FPD_InterForm form, FPD_Object pNewField, FS_WideString* csFieldName, FS_PtrArray pControls);
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
/*									 CFPD_FormField_V1;								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_FormField_V1
{
public:
	
	//************************************
	// Function:  GetFullName
	// Param[in]: formField		The input PDF interactive form field.
	// Param[out]:outName		The full name of the field.
	// Return:    void
	// Remarks:   Gets the full name of the field.
	// Notes:
	//************************************
	static void	GetFullName(FPD_FormField formField, FS_WideString* outName);

	//************************************
	// Function:  GetType
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The type of the field.
	// Remarks:   Gets the type of the field.
	// Notes:
	//************************************
	static FPD_FormFieldType	GetType(FPD_FormField formField);

	//************************************
	// Function:  GetFlags
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The field flags.
	// Remarks:   Gets the field flags.
	// Notes:
	//************************************
	static FS_DWORD	GetFlags(FPD_FormField formField);

	//************************************
	// Function:  GetInterForm
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The interactive form which it belongs to.
	// Remarks:   Gets the interactive form which it belongs to.
	// Notes:
	//************************************
	static FPD_InterForm GetInterForm(FPD_FormField formField);

	//************************************
	// Function:  GetFieldDict
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The field dictionary.
	// Remarks:   Gets the field dictionary.
	// Notes:
	//************************************
	static FPD_Object GetFieldDict(FPD_FormField formField);

	//************************************
	// Function:  ResetField
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Resets the form field.
	// Notes:
	//************************************
	static FS_BOOL ResetField(FPD_FormField formField, FS_BOOL bNotify);


	//************************************
	// Function:  CountControls
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The count of controls belongs to this field.
	// Remarks:   Gets the count of controls belongs to this field.
	// Notes:
	//************************************
	static FS_INT32	CountControls(FPD_FormField formField);

	//************************************
	// Function:  GetControl
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The input zero-based control index in the field.
	// Return:    A form control.
	// Remarks:   Gets a control.
	// Notes:
	//************************************
	static FPD_FormControl GetControl(FPD_FormField formField, FS_INT32 index);

	//************************************
	// Function:  GetControlIndex
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: control		The input form control.
	// Return:    The index of the control in the field.
	// Remarks:   Gets the index of a control.
	// Notes:
	//************************************
	static FS_INT32	GetControlIndex(FPD_FormField formField, FPD_FormControl control);


	//************************************
	// Function:  GetFieldType
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    Types like FPD_FORM_FIELDTYPE_xxxx
	// Remarks:   Gets the field type.
	// Notes:
	//************************************
	static FS_INT32	GetFieldType(FPD_FormField formField);


	//************************************
	// Function:  GetAdditionalAction
	// Param[in]: formField		The input PDF interactive form field.
	// Param[out]:outAAction	The additional action of the field.
	// Return:    void
	// Remarks:   Gets the additional action of the field.
	// Notes:
	//************************************
	static void GetAdditionalAction(FPD_FormField formField, FPD_AAction* outAAction);

	//************************************
	// Function:  SetAdditionalAction
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: aa			The input additional action.
	// Return:    void
	// Remarks:   Sets the additional action of the field.
	// Notes:
	//************************************
	static void	SetAdditionalAction(FPD_FormField formField, FPD_AAction aa);


	//************************************
	// Function:  GetAlternateName
	// Param[in]: formField		The input PDF interactive form field.
	// Param[out]:outName		The alternate field name
	// Return:    void
	// Remarks:   Gets the alternate field name to be used in place of the actual
	//            field name wherever the field must be identified in the user interface.
	// Notes:
	//************************************
	static void	GetAlternateName(FPD_FormField formField, FS_WideString* outName);

	//************************************
	// Function:  SetAlternateName
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: szName		The input alternate field name.
	// Return:    void
	// Remarks:   Sets the alternate field name. ANSI version.
	// Notes:
	//************************************
	static void	SetAlternateName(FPD_FormField formField, FS_LPCSTR szName);

	//************************************
	// Function:  SetAlternateNameW
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: wszName		The input alternate field name.
	// Return:    void
	// Remarks:   Sets the alternate field name. Unicode version.
	// Notes:
	//************************************
	static void	SetAlternateNameW(FPD_FormField formField, FS_LPCWSTR wszName);


	//************************************
	// Function:  GetMappingName
	// Param[in]: formField		The input PDF interactive form field.
	// Param[out]:outName		The mapping name
	// Return:    void
	// Remarks:   Gets the mapping name to be used when exporting interactive form field data from the document.
	// Notes:
	//************************************
	static void	GetMappingName(FPD_FormField formField, FS_WideString* outName);

	//************************************
	// Function:  SetMappingName
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: szName		The input mapping name. 
	// Return:    void
	// Remarks:   Sets the mapping name. ANSI version.
	// Notes:
	//************************************
	static void	SetMappingName(FPD_FormField formField, FS_LPCSTR szName);

	//************************************
	// Function:  SetMappingNameW
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: wszName		The input mapping name. 
	// Return:    void
	// Remarks:   Sets the mapping name. Unicode version.
	// Notes:
	//************************************
	static void	SetMappingNameW(FPD_FormField formField, FS_LPCWSTR wszName);


	//************************************
	// Function:  GetFieldFlags
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The field flags.
	// Remarks:   Gets the field flags.
	// Notes:
	//************************************
	static FS_DWORD	GetFieldFlags(FPD_FormField formField);

	//************************************
	// Function:  SetFieldFlags
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: dwFlags		The input field flags.
	// Return:    void
	// Remarks:   Sets the field flags.
	// Notes:
	//************************************
	static void	SetFieldFlags(FPD_FormField formField, FS_DWORD dwFlags);


	//************************************
	// Function:  GetDefaultStyle
	// Param[in]: formField		The input PDF interactive form field.
	// Param[out]:outStyle		The default style string.
	// Return:    void
	// Remarks:   Gets the default style string.
	// Notes:
	//************************************
	static void	GetDefaultStyle(FPD_FormField formField, FS_ByteString* outStyle);

	//************************************
	// Function:  SetDefaultStyle
	// Param[in]: formField			The input PDF interactive form field.
	// Param[in]: szDefaultStyle	The input default style string.
	// Return:    void
	// Remarks:   Sets the default style string.
	// Notes:
	//************************************
	static void	SetDefaultStyle(FPD_FormField formField, FS_LPSTR szDefaultStyle);


	//************************************
	// Function:  GetRichTextString
	// Param[in]: formField		The input PDF interactive form field.
	// Param[out]:outText		The rich text string.
	// Return:    void
	// Remarks:   Gets the rich text string.
	// Notes:
	//************************************
	static void	GetRichTextString(FPD_FormField formField, FS_WideString* outText);

	//************************************
	// Function:  SetRichTextString
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: szRichText	The input rich text string.
	// Return:    void
	// Remarks:   Sets the rich text string. ANSI version.
	// Notes:
	//************************************
	static void	SetRichTextString(FPD_FormField formField, FS_LPCSTR szRichText);

	//************************************
	// Function:  SetRichTextStringW
	// Param[in]: formField			The input PDF interactive form field.
	// Param[in]: wszRichText		The input rich text string.
	// Return:    void
	// Remarks:   Sets the rich text string. Unicode version.
	// Notes:
	//************************************
	static void	SetRichTextStringW(FPD_FormField formField, FS_LPCWSTR wszRichText);


	//************************************
	// Function:  GetValue
	// Param[in]: formField		The input PDF interactive form field.
	// Param[out]:outValue		The value of the field.
	// Return:    void
	// Remarks:   Gets the value of the field.
	// Notes:
	//  <ul>
	//  <li>For a text field, the value is the text string;</li>
	//  <li>For a rich text field, the value is the rich text XML element;</li>
	//  <li>For a file field, the value is the path name of the file;</li>
	//  <li>For a radio button or check box field, the value is value string of the selected button;</li>
	//  <li>For a list box field, the value is the value of first selected item, if any;</li>
	//  <li>For a comb box field, the value is the text string.</li>
	//  </ul>
	//************************************
	static void	GetValue(FPD_FormField formField, FS_WideString* outValue);

	//************************************
	// Function:  GetDefaultValue
	// Param[in]: formField		The input PDF interactive form field.
	// Param[out]:outValue		The default value of the field.
	// Return:    void
	// Remarks:   Gets the default value of the field.
	// Notes:
	//  <ul>
	//  <li>For a text field, the value is the text string;</li>
	//  <li>For a rich text field, the value is the rich text XML element;</li>
	//  <li>For a file field, the value is the path name of the file;</li>
	//  <li>For a radio button or check box field, the value is value string of the selected button;</li>
	//  <li>For a list box field, the value is the value of first selected item, if any;</li>
	//  <li>For a comb box field, the value is the text string.</li>
	//  </ul>
	//************************************
	static void	GetDefaultValue(FPD_FormField formField, FS_WideString* outValue);

	//************************************
	// Function:  SetValue
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: wszValue		The input field value.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Sets the value of the field. not applicable to non-unison radio box.
	// Notes:
	//  <ul>
	//  <li>For a text field, the value is the text string;</li>
	//  <li>For a rich text field, the value is the rich text XML element;</li>
	//  <li>For a file field, the value is the path name of the file;</li>
	//  <li>For a radio button or check box field, the value is value string of the selected button;</li>
	//  <li>For a list box field, the value is the value of first selected item, if any;</li>
	//  <li>For a comb box field, the value is the text string.</li>
	//  </ul>
	//************************************
	static FS_BOOL SetValue(FPD_FormField formField, FS_LPCWSTR wszValue, FS_BOOL bNotify);

	//************************************
	// Function:  SetDefaultValue
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: wszValue		The input default field value.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Sets the default value of the field.
	// Notes:
	//  <ul>
	//  <li>For a text field, the value is the text string;</li>
	//  <li>For a rich text field, the value is the rich text XML element;</li>
	//  <li>For a file field, the value is the path name of the file;</li>
	//  <li>For a radio button or check box field, the value is value string of the selected button;</li>
	//  <li>For a list box field, the value is the value of first selected item, if any;</li>
	//  <li>For a comb box field, the value is the text string.</li>
	//  </ul>
	//************************************
	static FS_BOOL SetDefaultValue(FPD_FormField formField, FS_LPCWSTR wszValue);


	//************************************
	// Function:  GetMaxLen
	// Param[in]: formField		The input PDF interactive form field.
	// Return:	  The maximum length of the field's text, in characters.
	// Remarks:   Gets the maximum length of the field's text, in characters.
	// Notes:
	//************************************
	static FS_INT32	GetMaxLen(FPD_FormField formField);

	//************************************
	// Function:  SetMaxLen
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: iMaxLen		The input maximum length.
	// Return:    void
	// Remarks:   Sets the maximum length of the field's text, in characters.
	// Notes:
	//************************************
	static void	SetMaxLen(FPD_FormField formField, FS_INT32 iMaxLen);


	//************************************
	// Function:  CountSelectedItems
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The count of selected items.
	// Remarks:   Gets the count of selected items.
	// Notes:
	//************************************
	static FS_INT32	CountSelectedItems(FPD_FormField formField);

	//************************************
	// Function:  GetSelectedIndex
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The item index in the selected item array.
	// Return:    The item index in all item array(include selected and unselected).
	// Remarks:   Gets the selected item index in the item array(include selected and unselected).
	// Notes:
	//************************************
	static FS_INT32	GetSelectedIndex(FPD_FormField formField, FS_INT32 index);

	//************************************
	// Function:  ClearSelection
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Clears the selection.
	// Notes:
	//************************************
	static FS_BOOL ClearSelection(FPD_FormField formField, FS_BOOL bNotify);

	//************************************
	// Function:  IsItemSelected
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The zero-based item index in the item array.
	// Return:    Non-zero means selected, otherwise unselected.
	// Remarks:   Checks whether the specified item has been selected.
	// Notes:
	//************************************
	static FS_BOOL IsItemSelected(FPD_FormField formField, FS_INT32 index);

	//************************************
	// Function:  SetItemSelection
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The zero-based item index in the item array.
	// Param[in]: bSelected		The input selection flag.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Sets the selection flag of specified item.
	// Notes:
	//************************************
	static FS_BOOL SetItemSelection(FPD_FormField formField, FS_INT32 index, FS_BOOL bSelected, FS_BOOL bNotify);

	//************************************
	// Function:  IsItemDefaultSelected
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The zero-based item index in the item array.
	// Return:    Non-zero means default selected, otherwise default unselected.
	// Remarks:   Checks whether the specified item's default selection flag is set.
	// Notes:
	//************************************
	static FS_BOOL IsItemDefaultSelected(FPD_FormField formField, FS_INT32 index);

	//************************************
	// Function:  SetItemDefaultSelection
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The zero-based item index in the item array.
	// Param[in]: bSelected		The input default selection flag.
	// Return:    void
	// Remarks:   Sets the default selection flag of specified item.
	// Notes:
	//************************************
	static void	SetItemDefaultSelection(FPD_FormField formField, FS_INT32 index, FS_BOOL bSelected);

	//************************************
	// Function:  GetDefaultSelectedItem
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The default selected item index.
	// Remarks:   Gets the default selected item index.
	// Notes:
	//************************************
	static FS_INT32	GetDefaultSelectedItem(FPD_FormField formField);


	//************************************
	// Function:  CountOptions
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The count of options.
	// Remarks:   Gets the count of options.
	// Notes:
	//************************************
	static FS_INT32	CountOptions(FPD_FormField formField);

	//************************************
	// Function:  GetOptionLabel
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The zero-based option index.
	// Param[out]:outLabel		The label of the option.
	// Return:    void
	// Remarks:   Gets the label of specified option.
	// Notes:
	//************************************
	static void	GetOptionLabel(FPD_FormField formField, FS_INT32 index, FS_WideString* outLabel);

	//************************************
	// Function:  GetOptionValue
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The zero-based option index.
	// Param[out]:outValue		The value of the option.
	// Return:    void
	// Remarks:   Gets the value of specified option.
	// Notes:
	//************************************
	static void	GetOptionValue(FPD_FormField formField, FS_INT32 index, FS_WideString* outValue);

	//************************************
	// Function:  InsertOption
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: wszOptLabel	The label of the option.
	// Param[in]: index			The option index to insert at.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    The inserted option index.
	// Remarks:   Inserts an option at specified position.
	// Notes:
	//************************************
	static FS_INT32	InsertOption(FPD_FormField formField, FS_LPWSTR wszOptLabel, FS_INT32 index, FS_BOOL bNotify);

	//************************************
	// Function:  FindOption
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: wszOptLabel	The label of the option to be found.
	// Return:    The index of the found option.
	// Remarks:   Finds an option by the label.
	// Notes:
	//************************************
	static FS_INT32	FindOption(FPD_FormField formField, FS_LPWSTR wszOptLabel);

	//************************************
	// Function:  FindOptionValue
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: csOptValue	The value of the option to be found.
	// Param[in]: iStartIndex	The start option index to find.
	// Return:    The index of the found option.
	// Remarks:   Finds an option by it's value.
	// Notes:
	//************************************
	static FS_INT32	FindOptionValue(FPD_FormField formField, FS_LPCWSTR csOptValue, FS_INT32 iStartIndex);

	//************************************
	// Function:  SetOptionLabel
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The zero-based index of the option.
	// Param[in]: wszOptLabel	The new option label.
	// Param[in]: bNotify		Whether do notifying.
	// Return:	  Non-zero means success, otherwise failure.
	// Remarks:   Sets the option label.
	// Notes:
	//************************************
	static FS_BOOL SetOptionLabel(FPD_FormField formField, FS_INT32 index, FS_LPCWSTR wszOptLabel, FS_BOOL bNotify);

	//************************************
	// Function:  SetOptionValue
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The zero-based index of the option.
	// Param[in]: wszOptValue	The new option label.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Sets the option value.
	// Notes:
	//************************************
	static FS_BOOL SetOptionValue(FPD_FormField formField, FS_INT32 index, FS_LPCWSTR wszOptValue, FS_BOOL bNotify);

	//************************************
	// Function:  DeleteOption
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The zero-based index of the option to be deleted.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Deletes an option.
	// Notes:
	//************************************
	static FS_BOOL DeleteOption(FPD_FormField formField, FS_INT32 index, FS_BOOL bNotify);

	//************************************
	// Function:  ClearOptions
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Clears all options.
	// Notes:
	//************************************
	static FS_BOOL ClearOptions(FPD_FormField formField, FS_BOOL bNotify);


	//************************************
	// Function:  CheckControl	
	// Param[in]: formField			The input PDF interactive form field.
	// Param[in]: iControlIndex		The index of the control.
	// Param[in]: bChecked			The input check state.
	// Param[in]: bNotify			Whether do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Checks a control.
	// Notes:
	//************************************
	static FS_BOOL CheckControl(FPD_FormField formField, FS_INT32 iControlIndex, FS_BOOL bChecked, FS_BOOL bNotify);

	//************************************
	// Function:  DefaultCheckControl
	// Param[in]: formField			The input PDF interactive form field.
	// Param[in]: iControlIndex		The index of the control.
	// Param[in]: bChecked			the input check state.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Checks a control's default check state.
	// Notes:
	//************************************
	static FS_BOOL DefaultCheckControl(FPD_FormField formField, FS_INT32 iControlIndex, FS_BOOL bChecked);

	//************************************
	// Function:  UpdateUnisonStatus
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    void
	// Remarks:   Resets or recreate Opt array list and AP stream, for RadioButton only.
	//            This is used whenever unison status is changed.
	// Notes:
	//************************************
	static void	UpdateUnisonStatus(FPD_FormField formField, FS_BOOL bNotify);


	//************************************
	// Function:  GetTopVisibleIndex	
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The top visible option index.
	// Remarks:   Gets the top visible option index.
	// Notes:
	//************************************
	static FS_INT32	GetTopVisibleIndex(FPD_FormField formField);

	//************************************
	// Function:  SetTopVisibleIndex
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			The input option index.
	// Return:    void
	// Remarks:   Sets the top visible option index.
	// Notes:
	//************************************
	static void	SetTopVisibleIndex(FPD_FormField formField, FS_INT32 index);


	//************************************
	// Function:  CountSelectedOptions
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The count of option indices in the "I" entry list.
	// Remarks:   Gets the count of option indices in the "I" entry list.
	// Notes:
	//************************************
	static FS_INT32	CountSelectedOptions(FPD_FormField formField);

	//************************************
	// Function:  GetSelectedOptionIndex
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: index			zero-based index in "I" entry list.
	// Return:    The index in all option array.
	// Remarks:   Gets the index of a selection option in all option array.
	// Notes:
	//************************************
	static FS_INT32	GetSelectedOptionIndex(FPD_FormField formField, FS_INT32 index);

	//************************************
	// Function:  IsOptionSelected
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: iOptIndex		zero-based index of option in Opt list.
	// Return:    Non-zero means selected, otherwise unselected.
	// Remarks:   Checks whether specified option has been selected.
	// Notes:
	//************************************
	static FS_BOOL IsOptionSelected(FPD_FormField formField, FS_INT32 iOptIndex);

	//************************************
	// Function:  SelectOption
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: iOptIndex		zero-based index of option in Opt list.
	// Param[in]: bSelected		The input selection flag.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Sets specified option to be selected.
	// Notes:
	//************************************
	static FS_BOOL SelectOption(FPD_FormField formField, FS_INT32 iOptIndex, FS_BOOL bSelected, FS_BOOL bNotify);

	//************************************
	// Function:  ClearSelectedOptions
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: bNotify		Whether do notifying.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Clears selected options to be unselected.
	// Notes:
	//************************************
	static FS_BOOL ClearSelectedOptions(FPD_FormField formField, FS_BOOL bNotify);
	

	//************************************
	// Function:  GetFontSize	
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The font size.
	// Remarks:   Gets the font size.
	// Notes:
	//************************************
	static FS_FLOAT GetFontSize(FPD_FormField formField);

	//************************************
	// Function:  GetFont
	// Param[in]: formField		The input PDF interactive form field.
	// Return:    The PDF font.
	// Remarks:   Gets the font.
	// Notes:
	//************************************
	static FPD_Font	GetFont(FPD_FormField formField);
	
	//************************************
	// Function:  SetItemDefaultSelection2
	// Param[in]: formField		The input PDF interactive form field.
	// Param[in]: indexArray		The zero-based index array in the item array.
	// Param[in]: bSelected		The input default selection flag.
	// Return:    void
	// Remarks:   Set the default selection flag of specified index array.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static void	SetItemDefaultSelection2(FPD_FormField formField, const FS_Int32Array indexArray, FS_BOOLEAN bSelected);
	
	//************************************
	// Function:  GetDefaultSelectedItemArray
	// Param[in]: formField		    The input PDF interactive form field.
	// Param[in/out]: indexArray	Get the default selected item index array.
	// Return:    void
	// Remarks:   Get the default selected item index array.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static void	 GetDefaultSelectedItemArray(FPD_FormField formField, FS_Int32Array* indexArray);
	
	//************************************
	// Function:  IsTextOverflow
	// Param[in]: formField		    The input PDF interactive form field.
	// Param[in]: pPage				The input page.
	// Param[in]: pWidget			The input widget form control.
	// Return:    FS_BOOLEAN    return true means overflow, otherwise no overflow.
	// Remarks:   Check if the text in text filed is overflow.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static FS_BOOLEAN IsTextOverflow(FPD_FormField formField, FPD_Page pPage, FPD_FormControl pWidget);	
	
	 //************************************
	 // Function:  GetListBoxValues
	 // Param[in]: formField		    The input PDF interactive form field.
	 // Param[in,out]: wsValueArray		It reveive the all field values.	
	 // Return:    FS_BOOLEAN    True means get values successfully, otherwise get empty array.
	 // Remarks:   Get the listbox values of the field.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	 //************************************
	static FS_BOOLEAN GetListBoxValues(FPD_FormField formField, FS_WideStringArray* wsValueArray);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										 CFPD_IconFit_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_IconFit_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: dict		The input PDF dictionary.
	// Return:    A PDF icon fit.
	// Remarks:   Creates a PDF icon fit from a PDF dictionary.
	// Notes:
	//************************************
	static FPD_IconFit New(FPD_Object dict);

	//************************************
	// Function:  Destroy
	// Param[in]: iconFit		The input PDF icon fit.
	// Return:    void
	// Remarks:   Destroys a PDF icon fit.
	// Notes:
	//************************************
	static void	Destroy(FPD_IconFit iconFit);


	//************************************
	// Function:  GetScaleMethod
	// Param[in]: iconFit		The input PDF icon fit.
	// Return:    The scale method.
	// Remarks:   Gets the scale method.
	// Notes:
	//************************************
	static FS_INT32	GetScaleMethod(FPD_IconFit iconFit);

	//************************************
	// Function:  SetScaleMethod
	// Param[in]: iconFit			The input PDF icon fit.
	// Param[in]: eScaleFunction	The new scale method.
	// Return:    void
	// Remarks:   Sets the scale method.
	// Notes:
	//************************************
	static void	SetScaleMethod(FPD_IconFit iconFit, FPD_IconScaleMethod eScaleFunction);


	//************************************
	// Function:  IsProportionalScale
	// Param[in]: iconFit		The input PDF icon fit.
	// Return:    <a>TRUE</a> for the scaling being proportional.
	// Remarks:   Checks whether the scaling is proportional.
	// Notes:
	//************************************
	static FS_BOOL IsProportionalScale(FPD_IconFit iconFit);

	//************************************
	// Function:  ProportionalScale
	// Param[in]: iconFit		The input PDF icon fit.
	// Param[in]: bScale		Whether the proportional scaling flag to be set.
	// Return:    void
	// Remarks:   Change the proportional scaling flag.
	// Notes:
	//************************************
	static void	ProportionalScale(FPD_IconFit iconFit, FS_BOOL bScale);


	//************************************
	// Function:  GetIconPosition
	// Param[in]: iconFit		The input PDF icon fit.
	// Param[out]:outLeft		It receives the x-direction fraction.
	// Param[out]:outBottom		It receives the y-direction fraction.
	// Return:    void
	// Remarks:   Gets the the fraction of leftover space to allocate at the left and bottom of the icon.
	// Notes:
	//************************************
	static void	GetIconPosition(FPD_IconFit iconFit, FS_FLOAT* outLeft, FS_FLOAT* outBottom);

	//************************************
	// Function:  SetIconPosition
	// Param[in]: iconFit		The input PDF icon fit.
	// Param[in]: fLeft			The input x-direction fraction.
	// Param[in]: fBottom		The input y-direction fraction.
	// Return:    void
	// Remarks:   Sets the the fraction of leftover space to allocate at the left and bottom of the icon.
	// Notes:
	//************************************
	static void	SetIconPosition(FPD_IconFit iconFit, FS_FLOAT fLeft, FS_FLOAT fBottom);


	//************************************
	// Function:  GetFittingBounds
	// Param[in]: iconFit		The input PDF icon fit.
	// Return:    The fiting-bound flag
	// Remarks:   Gets the fiting-bound flag which indicates that the button appearance should be scaled to fit 
    //            fully within the bounds of the annotation without taking into consideration the line 
	//            width of the border.
	// Notes:
	//************************************
	static FS_BOOL GetFittingBounds(FPD_IconFit iconFit);

	//************************************
	// Function:  SetFittingBounds
	// Param[in]: iconFit		The input PDF icon fit.
	// Param[in]: bFitBounds	The input fitting bound flag.
	// Return:    void
	// Remarks:   Sets the fitting-bound flag.
	// Notes:
	//************************************
	static void	SetFittingBounds(FPD_IconFit iconFit, FS_BOOL bFitBounds);

	//************************************
	// Function:  GetDict
	// Param[in]: iconFit		The input PDF icon fit.
	// Return:    The icon fit dictionary.
	// Remarks:   Gets the icon fit dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	//************************************
	static FPD_Object GetDict(FPD_IconFit iconFit);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*									 CFPD_FormControl_V1								*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_FormControl_V1
{
public:

	//************************************
	// Function:  GetType
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    A PDF interactive form control.
	// Remarks:   Gets the field type.
	// Notes:
	//************************************
	static FPD_FormFieldType	GetType(FPD_FormControl formContrl);

	//************************************
	// Function:  GetInterForm
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    The interactive form it belongs to.
	// Remarks:   Gets the interactive form it belongs to.
	// Notes:
	//************************************
	static FPD_InterForm GetInterForm(FPD_FormControl formContrl);

	//************************************
	// Function:  GetField
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    The field it belongs to.
	// Remarks:   Gets the field it belongs to.
	// Notes:
	//************************************
	static FPD_FormField GetField(FPD_FormControl formContrl);

	//************************************
	// Function:  GetWidget
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    The widget annotation dictionary.
	// Remarks:   Gets the widget annotation dictionary.
	// Notes:
	//************************************
	static FPD_Object GetWidget(FPD_FormControl formContrl);

	//************************************
	// Function:  GetRect
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outRect			The rectangle of the widget.
	// Return:    void
	// Remarks:   Gets the rectangle of the widget.
	// Notes:
	//************************************
	static void	GetRect(FPD_FormControl formContrl, FS_FloatRect* outRect);

	//************************************
	// Function:  DrawControl
	// Param[in]: formContrl			The input PDF interactive form control.
	// Param[in]: device				The device to draw on.
	// Param[in]: matrix				The transformation matrix from form control space to device space.
	// Param[in]: page					The PDF page it belongs to.
	// Param[in]: eMode					The input appearance mode.
	// Return:    void
	// Remarks:   Draws the form control.
	// Notes:
	//************************************
	static void	DrawControl(
		FPD_FormControl formContrl, 
		FPD_RenderDevice device, 
		FS_AffineMatrix matrix,
		FPD_Page page, 
		FPD_AnnotAppearanceMode eMode
		);


	//************************************
	// Function:  GetCheckedAPState
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outState			The checked state appearance string.
	// Return:    void
	// Remarks:   Gets the checked state appearance string.
	// Notes:
	//************************************
	static void	GetCheckedAPState(FPD_FormControl formContrl, FS_ByteString* outState);

	//************************************
	// Function:  GetExportValue
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outValue			The export mapping name.
	// Return:    void
	// Remarks:   Gets the export mapping name.
	// Notes:
	//************************************
	static void	GetExportValue(FPD_FormControl formContrl, FS_WideString* outValue);

	//************************************
	// Function:  SetExportValue
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: wszValue			The input export name.
	// Param[in]: bNotify			Whether do notifying.
	// Return:    void
	// Remarks:   Sets the export mapping name.
	// Notes:
	//************************************
	static void	SetExportValue(FPD_FormControl formContrl, FS_LPCWSTR wszValue, FS_BOOL bNotify);

	//************************************
	// Function:  IsChecked
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    <a>TRUE</a> for the control being checked.
	// Remarks:   Checks whether the control is checked.
	// Notes:
	//************************************
	static FS_BOOL IsChecked(FPD_FormControl formContrl);

	//************************************
	// Function:  IsDefaultChecked
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    <a>TRUE</a> for the contro being default checked.
	// Remarks:   Checks whether the control is default checked.
	// Notes:
	//************************************
	static FS_BOOL IsDefaultChecked(FPD_FormControl formContrl);


	//************************************
	// Function:  GetHighlightingMode
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    The highlighting mode.
	// Remarks:   Gets the highlighting mode.
	// Notes:
	//************************************
	static FPD_FormCtrlHighlightingMode	GetHighlightingMode(FPD_FormControl formContrl);

	//************************************
	// Function:  SetHighlightingMode
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: eHLMode			The input highlighting mode.
	// Return:    void
	// Remarks:   Sets the highlighting mode.
	// Notes:
	//************************************
	static void	SetHighlightingMode(FPD_FormControl formContrl, FPD_FormCtrlHighlightingMode eHLMode);


	//************************************
	// Function:  HasMKEntry
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: szEntry			The input entry name.
	// Return:    Non-zero means exist, otherwise not exist.
	// Remarks:   Checks whether the specified entry exist in the appearance characteristics dictionary.
	// Notes:
	//************************************
	static FS_BOOL HasMKEntry(FPD_FormControl formContrl, FS_LPSTR szEntry);

	//************************************
	// Function:  RemoveMKEntry
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: szEntry			The input entry name to be removed.
	// Return:    void
	// Remarks:   Removes a entry in the appearance characteristics dictionary.
	// Notes:
	//************************************
	static void	RemoveMKEntry(FPD_FormControl formContrl, FS_LPSTR szEntry);


	//************************************
	// Function:  GetRotation
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    The number of degrees.
	// Remarks:   Gets the number of degrees by which the widget annotation is rotated 
	//            counterclockwise relative to the page. The value must be a multiple of 90.
	// Notes:
	//************************************
	static FS_INT32	GetRotation(FPD_FormControl formContrl);

	//************************************
	// Function:  SetRotation
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: iDegree			The input number of degrees to rotated counterclockwise.
	// Return:    void
	// Remarks:   Sets the rotation.
	// Notes:
	//************************************
	static void	SetRotation(FPD_FormControl formContrl, FS_INT32 iDegree);


	//************************************
	// Function:  GetBorderColor
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:iColorType		It receives the color type.
	// Return:    The FX_ARGB color.
	// Remarks:   Gets the border color.
	// Notes:
	//************************************
	static FS_ARGB GetBorderColor(FPD_FormControl formContrl, FS_INT32* iColorType);

	//************************************
	// Function:  GetOriginalBorderColor
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: index				The component index of the original color.
	// Return:    The value of the component.
	// Remarks:   Gets an original color component of the border color.
	// Notes:
	//************************************
	static FS_FLOAT GetOriginalBorderColor(FPD_FormControl formContrl, FS_INT32 index);

	//************************************
	// Function:  GetOriginalBorderColor2
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outColorType		It receives the color type.
	// Param[out]:outFc[4]			It receives the values of the components.
	// Return:    void
	// Remarks:   Gets the original color of the border.
	// Notes:
	//************************************
	static void	GetOriginalBorderColor2(FPD_FormControl formContrl, FS_INT32* outColorType, FS_FLOAT outFc[4]);

	//************************************
	// Function:  SetBorderColor
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: iColorType		The input color type.
	// Param[in]: color				The FS_ARGB value of the input color.
	// Return:    void
	// Remarks:   Sets the border color.
	// Notes:
	//************************************
	static void	SetBorderColor(FPD_FormControl formContrl, FS_INT32 iColorType, FS_ARGB color);


	//************************************
	// Function:  GetBackgroundColor
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outColorType		It receives the color type.
	// Return:    The FS_ARGB color.c
	// Remarks:   Gets the background color.
	// Notes:
	//************************************
	static FS_ARGB GetBackgroundColor(FPD_FormControl formContrl, FS_INT32* outColorType);

	//************************************
	// Function:  GetOriginalBackgroundColor
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: index				The component index of the original color.
	// Return:    The value of the component.
	// Remarks:   Gets an original color component of the background color.
	// Notes:
	//************************************
	static FS_FLOAT	GetOriginalBackgroundColor(FPD_FormControl formContrl, FS_INT32 index);

	//************************************
	// Function:  GetOriginalBackgroundColor2
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outColorType		It receives the color type.
	// Param[out]:fc[4]				It receives the values of the components.
	// Return:    void
	// Remarks:   Gets the original color of the background.
	// Notes:
	//************************************
	static void	GetOriginalBackgroundColor2(FPD_FormControl formContrl, FS_INT32* outColorType, FS_FLOAT fc[4]);

	//************************************
	// Function:  SetBackgroundColor
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: iColorType		The input color type.
	// Param[in]: color				The FS_ARGB value of the input color.
	// Return:    void
	// Remarks:   Sets the background color.
	// Notes: 
	//************************************
	static void	SetBackgroundColor(FPD_FormControl formContrl, FS_INT32 iColorType, FS_ARGB color);


	//************************************
	// Function:  GetNormalCaption
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outCaption		The widget annotation's normal caption.
	// Return:    void
	// Remarks:   Gets the widget annotation's normal caption.
	// Notes:
	//************************************
	static void	GetNormalCaption(FPD_FormControl formContrl, FS_WideString* outCaption);

	//************************************
	// Function:  SetNormalCaption
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: szCaption			The input normal caption.
	// Return:    void
	// Remarks:   Sets the widget annotation's normal caption. ANSI version.
	// Notes:
	//************************************
	static void	SetNormalCaption(FPD_FormControl formContrl, FS_LPCSTR szCaption);

	//************************************
	// Function:  SetNormalCaptionW
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: wszCaption		The input normal caption.
	// Return:    void
	// Remarks:   Sets the widget annotation's normal caption. Unicode version.
	// Notes:
	//************************************
	static void	SetNormalCaptionW(FPD_FormControl formContrl, FS_LPCWSTR wszCaption);


	//************************************
	// Function:  GetRolloverCaption
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outCaption		The widget annotation's rollover caption.
	// Return:    void
	// Remarks:   Gets the widget annotation's rollover caption.
	// Notes:
	//************************************
	static void	GetRolloverCaption(FPD_FormControl formContrl, FS_WideString* outCaption);

	//************************************
	// Function:  SetRolloverCaption
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: szCaption			The input rollover caption.
	// Return:    void
	// Remarks:   Sets the widget annotation's rollover caption. ANSI version.
	// Notes:
	//************************************
	static void	SetRolloverCaption(FPD_FormControl formContrl, FS_LPCSTR szCaption);

	//************************************
	// Function:  SetRolloverCaptionW
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: wszCaption		The input rollover caption.
	// Return:    void
	// Remarks:   Sets the widget annotation's rollover caption. Unicode version.
	// Notes:
	//************************************
	static void	SetRolloverCaptionW(FPD_FormControl formContrl, FS_LPCWSTR wszCaption);


	//************************************
	// Function:  GetDownCaption
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outCaption		The widget annotation's alternate (down) caption.
	// Return:    void
	// Remarks:   Gets the widget annotation's alternate (down) caption.
	// Notes:
	//************************************
	static void	GetDownCaption(FPD_FormControl formContrl, FS_WideString* outCaption);

	//************************************
	// Function:  SetDownCaption
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: szCaption			The input down caption.
	// Return:    void	
	// Remarks:   Sets the widget annotation's down caption. ANSI version.
	// Notes:
	//************************************
	static void	SetDownCaption(FPD_FormControl formContrl,  FS_LPCSTR szCaption);

	//************************************
	// Function:  SetDownCaptionW
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: wszCaption		The input down caption.
	// Return:    void
	// Remarks:   Sets the widget annotation's down caption. Unicode version.
	// Notes:
	//************************************
	static void	SetDownCaptionW(FPD_FormControl formContrl, FS_LPCWSTR wszCaption);


	//************************************
	// Function:  GetNormalIcon
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    The widget annotation's normal icon. 
	// Remarks:   Gets the widget annotation's normal icon. 
	// Notes:
	//************************************
	static FPD_Object GetNormalIcon(FPD_FormControl formContrl);

	//************************************
	// Function:  SetNormalIcon
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: iconStm			The input PDF stream of normal icon.
	// Return:    void
	// Remarks:   Sets the widget annotation's normal icon.
	// Notes:
	//************************************
	static void	SetNormalIcon(FPD_FormControl formContrl, const FPD_Object iconStm);


	//************************************
	// Function:  GetRolloverIcon
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    The widget annotation's rollover icon.
	// Remarks:   Gets the widget annotation's rollover icon.
	// Notes:
	//************************************
	static FPD_Object GetRolloverIcon(FPD_FormControl formContrl);

	//************************************
	// Function:  SetRolloverIcon
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: iconStream		The input PDF stream of rollover icon.
	// Return:    void
	// Remarks:   Sets the widget annotation's rollover icon.
	// Notes:
	//************************************
	static void	SetRolloverIcon(FPD_FormControl formContrl, const FPD_Object iconStream);


	//************************************
	// Function:  GetDownIcon
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    The widget annotation's down icon.
	// Remarks:   Gets the widget annotation's down icon.
	// Notes:
	//************************************
	static FPD_Object GetDownIcon(FPD_FormControl formContrl);

	//************************************
	// Function:  SetDownIcon
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: iconStream		The input PDF stream of down icon.
	// Return:    void
	// Remarks:   Sets the widget annotation's down icon.
	// Notes:
	//************************************
	static void	SetDownIcon(FPD_FormControl formContrl, const FPD_Object iconStream);


	//************************************
	// Function:  GetIconFit
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outIconFit		The icon fit of the widget. 
	// Return:    void
	// Remarks:   Gets the icon fit of the widget. 
	// Notes:
	//************************************
	static void GetIconFit(FPD_FormControl formContrl, FPD_IconFit* outIconFit);

	//************************************
	// Function:  SetIconFit
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: cIF				The input icon fit.
	// Param[in]: pDoc				The input FPD_Document.
	// Return:    void
	// Remarks:   Sets the icon fit of the widget.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void	SetIconFit(FPD_FormControl formContrl, const FPD_IconFit cIF, FPD_Document pDoc);

	//************************************
	// Function:  GetTextPosition
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    The text position.
	// Remarks:   Gets where to position the text of the widget annotation's caption relative to its icon.
	// Notes:
	//************************************
	static FS_INT32	GetTextPosition(FPD_FormControl formContrl);

	//************************************
	// Function:  SetTextPosition
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: iPos				The input text position.
	// Return:    void
	// Remarks:   Sets the text position.
	// Notes:
	//************************************
	static void	SetTextPosition(FPD_FormControl formContrl, FS_INT32 iPos);


	//************************************
	// Function:  GetAction
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outAction			The action to be performed when the annotation is activated.
	// Return:    void
	// Remarks:   Gets the action to be performed when the annotation is activated.
	// Notes:
	//************************************
	static void GetAction(FPD_FormControl formContrl, FPD_Action* outAction);

	//************************************
	// Function:  SetAction
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: action			The input action.
	// Return:    void
	// Remarks:   Sets the action to be performed when the annotation is activated.
	// Notes:
	//************************************
	static void	SetAction(FPD_FormControl formContrl, const FPD_Action action);


	//************************************
	// Function:  GetAdditionalAction
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:pAAction			It receives the additional-actions.
	// Return:    void
	// Remarks:   Gets the additional-actions defining the annotation's behavior in response to various trigger events. 
	// Notes:
	//************************************
	static void GetAdditionalAction(FPD_FormControl formContrl, FPD_AAction* pAAction);

	//************************************
	// Function:  SetAdditionalAction
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: aaction			The input additional-actions.
	// Return:    void
	// Remarks:   Sets the additional-actions.
	// Notes:
	//************************************
	static void	SetAdditionalAction(FPD_FormControl formContrl, const FPD_AAction aaction);


	//************************************
	// Function:  GetDefaultAppearance
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[out]:outDefAP			The default appearance.
	// Return:    void
	// Remarks:   Gets the default appearance.
	// Notes: Do not forget to save default appearance after you change any setting in it when you
	//		retrieve an object of FPD_DefaultAppearance by GetDefaultAppearance method.
	//************************************
	static void	GetDefaultAppearance(FPD_FormControl formContrl, FPD_DefaultAppearance* outDefAP);

	//************************************
	// Function:  SetDefaultAppearance
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: cDA				The input default appearance.
	// Return:    void
	// Remarks:   Sets the default appearance.
	// Notes:
	//************************************
	static void	SetDefaultAppearance(FPD_FormControl formContrl, const FPD_DefaultAppearance cDA);

	//************************************
	// Function:  GetDefaultControlFont
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    The default font of the control.
	// Remarks:   Gets the default font of the control.
	// Notes:
	//************************************
	static FPD_Font	GetDefaultControlFont(FPD_FormControl formContrl);

	//************************************
	// Function:  SetDefaultControlFont
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: font				The input PDF font.
	// Return:    void
	// Remarks:   Sets the default font of the control. 
	// Notes:
	//************************************
	static void	SetDefaultControlFont(FPD_FormControl formContrl, const FPD_Font font);


	//************************************
	// Function:  GetControlAlignment
	// Param[in]: formContrl		The input PDF interactive form control.
	// Return:    The alignment of the control.
	//  <ul><li>0 - left alignment, the default setting.</li>
	//  <li>1 - centered, </li>
	//  <li>2 - right alignment. </li></ul>
	// Remarks:   Gets the alignment of the control.
	// Notes:
	//************************************
	static FS_INT32	GetControlAlignment(FPD_FormControl formContrl);

	//************************************
	// Function:  SetControlAlignment
	// Param[in]: formContrl		The input PDF interactive form control.
	// Param[in]: iAlignment		The input alignment.
	//  0 - left alignment, the default setting.
	//  1 - centered, 
	//  2 - right alignment. 
	// Return:    void.
	// Remarks:   Sets the alignment of the control. 
	// Notes:
	//************************************
	static void	SetControlAlignment(FPD_FormControl formContrl, FS_INT32 iAlignment);

	//************************************
	// Function:  DrawControl2
	// Param[in]: formContrl			The input PDF interactive form control.
	// Param[in]: device				The device to draw on.
	// Param[in]: matrix				The transformation matrix from form control space to device space.
	// Param[in]: page					The PDF page it belongs to.
	// Param[in]: eMode					The input appearance mode.
	// Param[in]: pOptions		        Render options.
	// Return:    void
	// Remarks:   Draws the form control.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static void	DrawControl2(
		FPD_FormControl formContrl,
		FPD_RenderDevice device,
		FS_AffineMatrix matrix,
		FPD_Page page,
		FPD_AnnotAppearanceMode eMode,
		FPD_RenderOptions option
	);

	//************************************
	// Function:  GetAAction
	// Param[in]: formField		    The input PDF interactive form control.
	// Param[in]: eAAT			    The input action type.
	// Param[in/out]: outAction		Get the action.
	// Return:   void
	// Remarks:   Get the addition action when the annotation is activated.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static void GetAAction(FPD_FormControl formContrl, FPD_AActionType eAAT, FPD_Action* outAction);
};

class CFPD_FDFDoc_V1
{
public:

	//************************************
	// Function: New
	// Return:   A new empty FDF document.
	// Remarks:  Creates a new empty FDF document.
	// Notes:
	//************************************
	static FDF_Document New();

	//************************************
	// Function:  OpenFromFile
	// Param[in]: strFilePath		The input file full path.
	// Return:    The FDF document.
	// Remarks:   Loads a FDF document from a file.
	// Notes:
	//************************************
	static FDF_Document OpenFromFile(FS_LPCSTR strFilePath);

	//************************************
	// Function:  PareMemory
	// Param[in]: memoryBlock		The input memory block.
	// Param[in]: size				The size in bytes of the block.
	// Return:    The FDF document.
	// Remarks:   Loads a FDF document from a memory block.
	// Notes:
	//************************************
	static FDF_Document PareMemory(FS_LPCBYTE memoryBlock, FS_DWORD size);

	//************************************
	// Function:  Destroy
	// Param[in]: doc	The input FDF document.	
	// Return:    void
	// Remarks:   Destroys The FDF document.
	// Notes:
	//************************************
	static void Destroy(FDF_Document doc);

	//************************************
	// Function:  WriteFile
	// Param[in]: doc				The input FDF document.	
	// Param[in]: strFilePath		The file full path to write to.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Writes the content of this FDF document to a file.
	// Notes:
	//************************************
	static FS_BOOL WriteFile(FDF_Document doc, FS_LPCSTR strFilePath);

	//************************************
	// Function:  GetRoot
	// Param[in]: doc	The input FDF document.	
	// Return:    Root dictionary of the FDF document.
	// Remarks:   Gets root dictionary of the FDF document. All other data can be fetched from this root.
	// Notes:
	//************************************
	static FPD_Object GetRoot(FDF_Document doc);

	//************************************
	// Function:  GetWin32Path
	// Param[in]: doc			The input FDF document.	
	// Param[out]:outPath		The file path of attached PDF document, if any.
	// Return:    Root dictionary of the FDF document.
	// Remarks:   Gets file path of attached PDF document, if any. Different platform has different format.
	// Notes:
	//************************************
	static void GetWin32Path(FDF_Document doc, FS_WideString* outPath);

	//************************************
	// Function:  GetIndirectObject
	// Param[in]: doc		The input memory document.
	// Param[in]: objNum	The input object number.
	// Return:    An memory document.
	// Remarks:   Loads an indirect object by an object number.
	// Notes:
	//************************************
	static FPD_Object GetIndirectObject(FDF_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  GetIndirectType
	// Param[in]: doc		The input memory document.
	// Param[in]: objNum	The input object number.
	// Return:    The type of the memory document.
	// Remarks:   Gets type of an memory document, without loading the object content.
	// Notes:
	//************************************
	static FS_INT32	GetIndirectType(FDF_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  AddIndirectObject
	// Param[in]: doc		The input memory document.
	// Param[in]: obj		The input object.
	// Return:    The new object number.
	// Remarks:   Adds an object to indirect object list. The new object number is returned.
	// Notes:
	//************************************
	static FS_DWORD	AddIndirectObject(FDF_Document doc, FPD_Object obj);

	//************************************
	// Function:  ReleaseIndirectObject
	// Param[in]: doc		The input memory document.
	// Param[in]: objNum	The object number to release.
	// Return:    void
	// Remarks:   Sometimes, for saving memory space, we can release a loaded memory document.
	//            However, use this with caution because the object pointer will become invalid.
	// Notes:
	//************************************
	static void	ReleaseIndirectObject(FDF_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  DeleteIndirectObject
	// Param[in]: doc		The input memory document.
	// Param[in]: objNum	The object number to delete.
	// Return:    void
	// Remarks:   Deletes an memory document. Use this function with caution!
	// Notes:
	//************************************
	static void	DeleteIndirectObject(FDF_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  ImportIndirectObject
	// Param[in]: doc		The input memory document.
	// Param[in]: pBuffer	The binary data for the memory document. It must be not encrypted.
	// Param[in]: size		The size in bytes of the binary data.
	// Return:    An object.
	// Remarks:   Imports an object from its binary format.
	//            This is used when the PDF is fetched in "Progressive Downloading" fashion.
	//            After this function call, the data buffer can be destroyed.
	//            This object must not be encrypted.
	// Notes:
	//************************************
	static FPD_Object ImportIndirectObject(FDF_Document doc, FS_LPCBYTE pBuffer, FS_DWORD size);

	//************************************
	// Function:  ImportExternalObject
	// Param[in]: doc		The input memory document.
	// Param[in]: obj		The object in external object collection.
	// Param[out]:mapping   It updates the mapping from old object number to new object number.	
	// Return:    A new memory document.
	// Remarks:   Imports an object from external object collection as a new memory document.
	//            If the external object refers to other external indirect objects, those indirect objects
	//            are also imported.
	//            The mapping from old object number to new object number is updated during the import process.
	// Notes:
	//************************************
	static FPD_Object ImportExternalObject(FDF_Document doc, FPD_Object obj, FS_MapPtrToPtr mapping);

	//************************************
	// Function:  InsertIndirectObject
	// Param[in]: doc		The input memory document.
	// Param[in]: objNum	The new object number of the indirect object to insert.
	// Param[in]: obj		The indirect object to insert.
	// Return:    void
	// Remarks:   Inserts an indirect object with specified object number.
	//			  This is used when the PDF is fetched in "Progressive Downloading" fashion, or parsing FDF.
	//            If an indirect object with the same object number exists, the previous one will be destroyed.
	// Notes:
	//************************************
	static void	InsertIndirectObject(FDF_Document doc, FS_DWORD objNum, FPD_Object obj);

	//************************************
	// Function:  GetLastobjNum
	// Param[in]: doc		The input memory document.
	// Return:    Last assigned indirect object number.
	// Remarks:   Gets last assigned indirect object number.
	// Notes:
	//************************************
	static FS_DWORD	GetLastobjNum(FDF_Document doc);

	//************************************
	// Function:  ReloadFileStreams
	// Param[in]: doc		The input memory document.
	// Return:    void
	// Remarks:   Reload all file based stream when we do reparsing.
	// Notes:
	//************************************
	static void	ReloadFileStreams(FDF_Document doc);

	//************************************
	// Function:  GetStartPosition
	// Param[in]: doc		The input memory document.
	// Return:    The start position of the indirect objects.
	// Remarks:   Gets the start position of the indirect objects.
	// Notes:
	//************************************
	static FS_POSITION GetStartPosition(FDF_Document doc);

	//************************************
	// Function:  GetNextAssoc
	// Param[in]: doc			The input memory document.
	// Param[in,out]:outPos		Input current position and receive the next position.
	// Param[out]:outObjNum		It receives the current object number.
	// Param[out]:outObject		It receives the current indirect object pointer.
	// Return:    void
	// Remarks:   Accesses the indirect object of current position, and move the position to next.
	// Notes:
	//************************************
	static void	GetNextAssoc(FDF_Document doc, FS_POSITION* outPos, FS_DWORD* outObjNum, FPD_Object* outObject);

	//************************************
	// Function:  IsModified
	// Param[in]: doc		The input memory document.
	// Return:    <a>TRUE</a> for the indirect objects are modified, otherwise not.
	// Remarks:   Checks if any of the indirect objects are modified, since loading from parser, or last ClearModified.
	// Notes:
	//************************************
	static FS_BOOL IsModified(FDF_Document doc);

	//************************************
	// Function:  ClearModified
	// Param[in]: doc		The input memory document.
	// Return:    void
	// Remarks:   Clears the modified flag.
	// Notes:
	//************************************
	static void	ClearModified(FDF_Document doc);

	//************************************
	// Function:  WriteBuf
	// Param[in]: doc		The input document.
	// Param[out]:outBuf	It will receive the content of this PDF document.
	// Return:    <a>TRUE</a> means success, otherwise failure.
	// Remarks:   Writes the content of this FDF document to a memory block.
	// Notes:
	//************************************
	static FS_BOOL WriteBuf(FDF_Document doc, FS_ByteString* outBuf);

	//************************************
	// Function:  GetAnnotCount
	// Param[in]: doc		The input document.
	// Param[in]: szFilter	Pointer to a filter string. 
	//						It can be NULL, otherwise it must be like "Text" or "Text, Link, Circle".
	// Return:    The count of annotations.
	// Remarks:   Count annotations in a FDF document by specific filter.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_INT32 GetAnnotCount(FDF_Document doc, FS_LPCSTR szFilter);

	//************************************
	// Function:  GetAnnotDict
	// Param[in]: doc		The input document.
	// Param[in]: szFilter	Pointer to a filter string. 
	//						It can be NULL, otherwise it must be like "Text" or "Text, Link, Circle".
	// Param[in]: nIndex	A zero-based annotation index based on the annotations which are specified by filter.
	// Return:    The FDF annotation dictionary.
	// Remarks:   Get an annotation dictionary from FDF document by specific filter and index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FPD_Object GetAnnotDict(FDF_Document doc, FS_LPCSTR szFilter, FS_INT32 nIndex);

	//************************************
	// Function:  GetAnnotPageIndex
	// Param[in]: fdfAnnotDict		The FDF annotation dictionary.
	// Return:    The zero-based index of PDF page.
	// Remarks:   Get the zero-based index of PDF page on which the original PDF annotation locates.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_INT32 GetAnnotPageIndex(FPD_Object fdfAnnotDict);

	//************************************
	// Function:  ExportAnnotToPDFPage
	// Param[in]: doc				The input document.
	// Param[in]: fdfAnnotDict		The FDF annotation dictionary.
	// Param[in]: pdfDoc			The PDF document to which the FDF annotation is exported.
	// Param[in]: pdfPage			The PDF page to which the FDF annotation is exported.
	// Param[out]: arrAnnotDict		The pointer array to receive generated PDF annotation dictionaries.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Export an annotation object loaded from a FDF document into a PDF page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_BOOL ExportAnnotToPDFPage(FDF_Document doc, FPD_Object fdfAnnotDict, FPD_Document pdfDoc, FPD_Page pdfPage, FS_PtrArray* arrAnnotDict);

	//************************************
	// Function:  ImportPDFAnnot
	// Param[in]: doc			The input document.
	// Param[in]: pdfAnnotDict	The PDF annotation dictionary to be imported. 
	// Param[in]: nPageIndex	The zero-based index of PDF page on which the annotation locates.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Import an annotation from PDF document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_BOOL ImportPDFAnnot(FDF_Document doc, FPD_Object pdfAnnotDict, FS_INT32 nPageIndex);

	//************************************
	// Function:  SetPDFPath
	// Param[in]: doc			The input document.
	// Param[in]: wszPDFPath	The PDF path. 
	// Return:    
	// Remarks:   Set the path of PDF document to FDF document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void SetPDFPath(FDF_Document doc, FS_LPCWSTR wszPDFPath);
	
	//************************************
	// Function:  GetFieldAttr	
	// Param[in]: pFieldDict	The input field dictionary.
	// Param[in]: name	        The attribute(entry) name.
	// Param[in]: nLevel	    It count the time of recursive invocation.
	// Return:  FPD_Object   A PDF object of the attribute(entry) value.
	// Remarks:  Get a field attribute (an entry of field dictionary).
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_Object  GetFieldAttr(FPD_Object pFieldDict, const FS_CHAR* name, FS_INT32 nLevel);

	 //************************************
	 // Function: GetFieldAttrTB	 
	 // Param[in]: pFieldDict	The input field dictionary.
	 // Param[in]: name	        The attribute(entry) name.	
	 // Return:  FPD_Object   A PDF object of the attribute(entry) value.
	 // Remarks:  Get a field attribute (an entry of field dictionary).
	 // GetFieldAttr: from this to parent, GetFieldAttrTB : from parent to this.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	 //************************************
	static FPD_Object GetFieldAttrTB(FPD_Object pFieldDict, const FS_CHAR* name);
};

class CFPD_ConnectedInfo_V7
{
public:
	//************************************
	// Function:  New
	// Param[in]: fpdDoc	The input document.
	// Return: The connected PDF info object.
	// Remarks: Creates the connected PDF info object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	//************************************
	static FPD_ConnectedInfo New(FPD_Document fpdDoc);

	//************************************
	// Function:  Destroy
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Return: void.
	// Remarks: Destroys the connected PDF info object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	//************************************
	static void Destroy(FPD_ConnectedInfo connectedInfo);

	//************************************
	// Function:  SetId
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[in]: nIdType		The input Id type.
	// Param[in]: bsURI			The input URI.
	// Param[in]: bsCert		The input certificate. This param is reserved now.
	// Return: void.
	// Remarks: Sets the Id of the connected PDF info object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	//************************************
	static void SetId(FPD_ConnectedInfo connectedInfo, FS_INT32 nIdType, FS_ByteString bsURI, FS_ByteString bsCert);

	//************************************
	// Function:  GetId
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[in]: nIdType		The input Id type.
	// Param[out]: outURI		It receives the URI.
	// Param[out]: outCert		It receives the certificate. This param is reserved now.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Gets the Id of the connected PDF info object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	//************************************
	static FS_BOOL GetId(FPD_ConnectedInfo connectedInfo, FS_INT32 nIdType, FS_ByteString* outURI, FS_ByteString* outCert);

	//************************************
	// Function:  IsConnectedPDF
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Return: TRUE if the PDF document is a connected PDF, otherwise not.
	// Remarks: Checks whether the PDF document is a connected PDF or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	//************************************
	static FS_BOOL IsConnectedPDF(FPD_ConnectedInfo connectedInfo);

	//************************************
	// Function:  IsConnectedPDF2
	// Param[in]: fpdDoc	The input PDF document.
	// Return: TRUE if the PDF document is a connected PDF, otherwise not.
	// Remarks: Checks whether the PDF document is a connected PDF or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	//************************************
	static FS_BOOL IsConnectedPDF2(FPD_Document fpdDoc);

	//************************************
	// Function:  SetTracking
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[in]: track			The input tracking type.
	// Return: void.
	// Remarks: Sets the tracking type. This interface is reserved now.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	//************************************
	static void SetTracking(FPD_ConnectedInfo connectedInfo, FS_INT32 track);

	//************************************
	// Function:  GetTracking
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[out]: outTrack		It receives the tracking type.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Gets the tracking type. This interface is reserved now.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	//************************************
	static FS_BOOL GetTracking(FPD_ConnectedInfo connectedInfo, FS_INT32* outTrack);

	//************************************
	// Function:  Update
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[in]: bOpenAction	Whether to add open action to ConnectedPDF document or not. Sets it FALSE as default.
	// Return: void.
	// Remarks: Updates the connected PDF info.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	//************************************
	static void Update(FPD_ConnectedInfo connectedInfo, FS_BOOL bOpenAction);

	//************************************
	// Function:  SetEncryptOffline
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[in]: bOffline		The input offline flag parameter.
	// Return: void.
	// Remarks: Sets whether the encrypted connected PDF is offline or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static void SetEncryptOffline(FPD_ConnectedInfo connectedInfo, FS_BOOL bOffline);

	//************************************
	// Function:  SetEncryptEnvelope
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[in]: bsEnvelope	The input offline envelope.
	// Return: void.
	// Remarks: Sets envelope string to encrypt dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static void SetEncryptEnvelope(FPD_ConnectedInfo connectedInfo, FS_ByteString bsEnvelope);

	//************************************
	// Function:  GetEncryptOffline
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[out]: outIsOffline	It receives the result whether the encrypted connected PDF is offline or not.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Sets envelope string to encrypt dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_BOOL GetEncryptOffline(FPD_ConnectedInfo connectedInfo, FS_BOOL* outIsOffline);

	//************************************
	// Function:  GetEncryptEnvelope
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[out]: outEnvelope	It receives the offline envelope.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Gets the offline envelope.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_BOOL GetEncryptEnvelope(FPD_ConnectedInfo connectedInfo, FS_ByteString* outEnvelope);
	
	//************************************
	// Function:  SetOpenActionURL
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[in]: lpsURL		The input sever URL.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Sets OpenAction javascript server URL.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_BOOL SetOpenActionURL(FPD_ConnectedInfo connectedInfo, FS_LPCSTR lpsURL);

	//************************************
	// Function:  SetOpenActionURL2
	// Param[in]: connectedInfo	The input connected PDF info object.
	 // Param[in]: nType		Sees <a>FPDConnectedOpenActionURLTypes</a> definitions.
	// Param[in]: lpsURL		The input sever URL.
	// Return: TRUE for success, otherwise failure.
	// Remarks: Sets OpenAction javascript server URL.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0.2
	//************************************
	static FS_BOOL SetOpenActionURL2(FPD_ConnectedInfo connectedInfo, FS_INT32 nType, FS_LPCSTR lpsURL);

	//************************************
	// Function:  CheckSettingOpenAction
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[in]: nType		Sees <a>FPDConnectedOpenActionURLTypes</a> definitions.
	// Param[in]: lpsURL		The input sever URL.
	// Return: TRUE if the OpenAction javascript server URL is set.
	// Remarks: Checks whether the OpenAction javascript server URL is set or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0.2
	//************************************
	static FS_BOOL CheckSettingOpenAction(FPD_ConnectedInfo connectedInfo, FS_INT32 nType, FS_LPCSTR lpsURL);

	//************************************
	// Function:  DeleteOpenAction
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Return: void.
	// Remarks: Deletes ConnectedPDF info in OpenAction.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.2.1
	//************************************
	static void DeleteOpenAction(FPD_ConnectedInfo connectedInfo);

	//************************************
	// Function:  SetEndpoint
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[in]: lpsEndPoint	The input URL of connected PDF web services.
	// Return: void.
	// Remarks: Sets the URL of connected PDF web services.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3
	//************************************
	static void SetEndpoint(FPD_ConnectedInfo connectedInfo, FS_LPCSTR lpsEndPoint);
	
	//************************************
	// Function:  GetEndpoint
	// Param[in]: connectedInfo	The input connected PDF info object.
	// Param[out]: outEndPoint	It receives the URL of connected PDF web services.
	// Return: TRUE if success, FALSE if failed.
	// Remarks: Gets the URL of connected PDF web services.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3
	//************************************
	static FS_BOOL GetEndpoint(FPD_ConnectedInfo connectedInfo, FS_ByteString* outEndPoint);
	
	 //************************************
	 // Function:  RemoveConnectPDF
	 // Param[in]: connectedInfo	The input connected PDF info object.
	 // Param[in]: flag   	        It could be FPDF_CONNECT_DOCUMENTID, FPDF_CONNECT_VERSIONID, or there xor value.
	 //	                            Remove all connectPDF info if there is PDF_CONNECT_DOCUMENTID in flag.
	 // Return: void
	 // Remarks: Remove Connect PDF info from PDF file.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	 //************************************
	static void	 RemoveConnectPDF(FPD_ConnectedInfo connectedInfo, FS_DWORD flag);
};

class CFPD_WrapperDoc_V10
{
public:
	//************************************
	// Function:  New
	// Param[in]: fpdDoc	The input document.
	// Return: The wrapper document object.
	// Remarks: Create the wrapper document object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static FPD_WrapperDoc New(FPD_Document fpdDoc);

	//************************************
	// Function:  Destroy
	// Param[in]: wrapperDoc	The input wrapper document object.
	// Return: void.
	// Remarks: Destroys the wrapper document object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static void Destroy(FPD_WrapperDoc wrapperDoc);

	//************************************
	// Function:  GetWrapperType
	// Param[in]: wrapperDoc	The input wrapper document object.
	// Return:	-1 for error;
	//			<a>PDF_WRAPPERTYPE_NO</a> for no wrapper document;
	//			<a>PDF_WRAPPERTYPE_FOXIT</a> for Foxit wrapper document;
	//			<a>PDF_WRAPPERTYPE_PDF2</a> for PDF2.0 wrapper document.
	// Remarks: Whether the document is a wrapper document or normal.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static FS_INT32	GetWrapperType(FPD_WrapperDoc wrapperDoc);

	//************************************
	// Function:  GetCryptographicFilter
	// Param[in]: wrapperDoc	The input wrapper document object.
	// Param[out]: wsGraphicFilter	The name of the cryptographic filter.
	// Param[out]: fVersion			The version number of the cryptographic filter, if present; Otherwise, 0.
	// Return:	TRUE if success, otherwise return FALSE.
	// Remarks:	Get the details of the cryptographic filter needed to decrypt the encrypted payload.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static FS_BOOL GetCryptographicFilter(FPD_WrapperDoc wrapperDoc, FS_WideString *wsGraphicFilter, FS_FLOAT *fVersion);

	//************************************
	// Function:  GetPayLoadSize
	// Param[in]: wrapperDoc	The input wrapper document object.
	// Return:	The size of payload;
	// Remarks: Get the file size of the uncompressed encrypted payload document.
	// Notes:	if no "size" key, return -1;
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static FS_INT64 GetPayLoadSize(FPD_WrapperDoc wrapperDoc);

	//************************************
	// Function:  GetPayloadFileName
	// Param[in]: wrapperDoc	The input wrapper document object.
	// Param[out]: wsFileName	The file name for encrypted payload documents.
	// Return:	TRUE if success, otherwise return FALSE.
	// Remarks:	Get the file name for encrypted payload documents which shall include the name of the
	//			cryptographic filter needed to decrypt the document.
	// Notes:	The name must not contain or be derived from the encrypted payload's actual file name.
	//			This is to avoid potential disclosure of sensitive information in the original filename.
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static FS_BOOL GetPayloadFileName(FPD_WrapperDoc wrapperDoc, FS_WideString *wsFileName);

	//************************************
	// Function:   StartGetPayload
	// Param[in]: wrapperDoc	The input wrapper document object.
	// Param[out]: pPayload		The embedded encrypted payload document's file stream.
	// Param[in]:  pPause		The user-supplied pause object.
	// Return:	   TRUE, to be continued, otherwise, finished.
	// Remarks:	   Get the embedded encrypted payload document's file stream.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static FS_BOOL StartGetPayload(FPD_WrapperDoc wrapperDoc, FS_FileWriteHandler *pPayload, FS_PauseHandler pPause);

	//************************************
	// Function:   Continue
	// Param[in]: wrapperDoc	The input wrapper document object.
	// Param[in]:  pPause		The user-supplied pause object.
	// Return:	   Negative value if failure, 0 if finishes, and positive value if need to be continued.
	// Remarks:	   Continue getting the embedded encrypted payload document's file stream.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static FS_INT32 Continue(FPD_WrapperDoc wrapperDoc, FS_PauseHandler pPause);
};

class CFPD_CertStore_V14
{
public:
	static FPD_CertStore New(void);
	static void Destroy(FPD_CertStore certStore);
	static FS_LPVOID  GetHCertStore(FPD_CertStore certStore);
	static FS_INT32  LoadMYSystemCerts(FPD_CertStore certStore, const FS_BOOL& bOnlyUsedForSign);
	static FS_LPVOID GetCertFromCertSNId(FPD_CertStore certStore, FS_ByteString csCertID);
	static void GetCertSNID(const FS_LPVOID pCert, FS_ByteString* bsSNID);
	static FS_DWORD GetCertCount(FPD_CertStore certStore);
	static void GetCertsArray(FPD_CertStore certStore, FS_PtrArray* pArray);
	static FS_BOOL IsPrivateKeyCert(FPD_CertStore certStore, FS_LPVOID pCertContext);
	static FS_INT32 LoadOtherCerts(FPD_CertStore certStore, const FS_ByteString csStoreName);
	static FS_INT32 LoadFileCerts(FPD_CertStore certStore, const FS_WideString cwFilePath, const FS_BOOL bOnlyUseSign);
	static FS_LPVOID AddCert(FPD_CertStore certStore, FS_LPVOID pCertContext);
	static void AddCerts(FPD_CertStore certStore, FS_PtrArray pCertsArr);
	static void AddDocDssCerts(FPD_CertStore certStore, FPD_Object pDSSCerts);
	static FS_LPVOID GetCertFromCertSNIDHEX(FPD_CertStore certStore, const FS_ByteString csCertID);
	static FS_LPVOID FindCert(FPD_CertStore certStore, FS_LPVOID pCertContext);
	static FS_BOOLEAN IsPrivateHasUsage(FPD_CertStore certStore, FS_LPVOID pCertContext, FS_BOOLEAN bExUsagesameUsage, FS_BOOLEAN bUserVerify);
	static FS_BOOLEAN IsSm2SignWithSm3(FPD_CertStore certStore, FS_LPVOID pCertContext);	
	static FS_LPVOID AddCert2(FPD_CertStore certStore, const FS_LPCWSTR wsCertfile, const FS_LPCWSTR password);
};

class CFPD_PageLabel_V14
{
public:
     //************************************
     // Function:  New
     // Param[in]: pDocument			The input PDF document.
     // Return:    FPD_PageLabel.
     // Remarks:   Construct from a PDF document.
     // Notes:
     // Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
     //************************************
    static FPD_PageLabel New(FPD_Document pDocument);

    //************************************
    // Function:  Destroy
    // Param[in]: pagelabel			The input object CPDF_PageLabel.
    // Return:	  void
    // Remarks:   Destroys the pagelabel created by <a>FPDDocNew</a>.
    // Notes:
     // Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    //************************************
    static void	Destroy(FPD_PageLabel pagelabel);

    //************************************
    // Function:  GetLabel
    // Param[in]: pagelabel			The input object CPDF_PageLabel.
    // Param[in]: nPage				Specifies the zero-based index of the page.
    // Param[out]: wsLabel			 FS_WideString type of page label.
    // Return:    FS_WideString type of page label.
    // Remarks:   Get page label full string.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    //************************************
    static void     GetLabel(FPD_PageLabel pagelabel, FS_INT32 nPage,FS_WideString* wsLabel);

    //************************************
    // Function:  GetPageByLabel
    // Param[in]: pagelabel			The input object CPDF_PageLabel.
    // Param[in]: bsLabel			Specifies the page label.
    // Return:    Get the page index of specified page label.
    // Remarks:
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    //************************************
    static FS_INT32     GetPageByLabel(FPD_PageLabel pagelabel, FS_LPCBYTE bsLabel);

    //************************************
    // Function:  GetPageByLabel2
    // Param[in]: pagelabel			The input object CPDF_PageLabel.
    // Param[in]: wsLabel			Specifies the page label.
    // Return:     Get the page index of specified page label.
    // Remarks:
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
    //************************************
    static FS_INT32     GetPageByLabel2(FPD_PageLabel pagelabel, FS_LPCWSTR wsLabel);
};

class CFPD_SignCert_V14
{
public:  
	//************************************
	// function:  CreateCert	
	// fundeleted: deleted.
	//************************************
	static FPD_SignCert  CreateCert();

	//************************************
	// function:  DestroyCert	
	// fundeleted: deleted.
	//************************************
	static void DestroyCert(FPD_SignCert cert);

	//************************************
	// function:  Init	
	// fundeleted: deleted.
	//************************************
	static FS_BOOL Init(FPD_SignCert cert, FPD_Object pStream);

	//************************************
	// function:  Init1	
	// fundeleted: deleted.
	//************************************
	static FS_BOOL Init1(FPD_SignCert cert, const FS_LPBYTE str, FS_INT32 length);

	//************************************
	// function:  Init2	
	// fundeleted: deleted.
	//************************************
	static FS_BOOL Init2(FPD_SignCert cert, const FS_WideString wsCertPath);

	//************************************
	// function:  GetStream	
	// fundeleted: deleted.
	//************************************
	static FPD_Object GetStream(FPD_SignCert cert);
};

class CFPD_SignCertHandler : public IFX_CertHandler
{
public:
    CFPD_SignCertHandler(FPD_SignCertHandlerCallbacksRec* pHandler);
    virtual FX_BOOL GetCertSummary(const CFX_ByteString& X509CertData, CertSummary& pCertSummary);
    virtual FX_BOOL IsIssuerMatchCert(const CFX_ByteString& X509CertData, const CFX_ByteString& X509IssuerData);
    virtual FX_BOOL IsCA(const CFX_ByteString& X509CertData);
    virtual FX_BOOL IsCertCanUsedForSigning(const CFX_ByteString& X509CertData);
    virtual FX_BOOL IsCertExpired(const CFX_ByteString& X509CertData);

    FPD_SignCertHandlerCallbacksRec m_handler;
};

class CFPD_SignCertHandler_V14
{
public:
    static FPD_SignCertHandler New(FPD_SignCertHandlerCallbacks callbacks);
    static void Destroy(FPD_SignCertHandler handler);
};

class CFPD_CertMethod_V14
{
public:
    static void GetCertSNID(const FS_LPVOID pCert, FS_ByteString* bsSNID);
    static void GetCertSNIDHEX(const FS_LPVOID pCert, FS_ByteString* bsSNIDHEX);
    static FS_BOOL GetCertChainsFromCert(const FS_LPVOID pCert, FS_PtrArray* outCertsArr, FS_BOOL bContainsCertItself);
    static void FreeCertChains(FS_PtrArray* CertsArr);
    static FS_BOOL GetCertChainsFromCert1(const FS_LPVOID pCert, FS_ByteStringArray* CertsArr);
    static void ClearCertPin(void* pCert);
    static void GetCertIssuer(FS_LPVOID pCertContext, FS_WideString* wsIssuer);
    static void GetCertExpries(FS_LPVOID pCertContext, FS_WideString* wsExpries);
    static void GetCertIssuerName(FS_LPVOID pCertContext, FS_BOOL bHaveEmail, FS_WideString* wsIssuerName);
    static void GetCertName(FS_LPVOID pCertContext, FS_BOOL bHaveEmail, FS_WideString* wsCertName);
    static void GetSignerName(const FS_ByteString csContents, FS_WideString* wsSignerName);
	static FS_BOOL IsSelfSignedCert(FS_LPBYTE pBuffer, FS_DWORD bufferLent);
    static FS_BOOL IsValidRoot(FS_LPVOID pCert);
    static FS_BOOL GetCertStartTime(FS_LPVOID pCert, FPD_SYSTEMTIME* time);
    static void GetCertStartTime1(FS_LPVOID pCert, FS_WideString* wsStartTime);
    static FS_BOOL GetCertExpiredTime(FS_LPVOID pCert, FPD_SYSTEMTIME* time);
    static void SystemTimeToString(FS_UINT nLangID, const FPD_SYSTEMTIME systemTime, FS_DWORD* dwTimeZone, FS_WideString* outwsTime);
	static FS_BOOL CertOverdue(FS_LPVOID pCert, const PFPD_SYSTEMTIME pUTCTime);
    static void CertToString(FS_LPVOID pCert, FS_WideString* wsCert);
    static void GetCertDN(FS_LPVOID pCert, FS_WideString* wsCertDN);
    static FS_LPVOID CertClone(FS_LPVOID pCertContext, FS_ByteString pChainParentSn);
    static FS_BOOL GetExtKeyUsage(FS_LPVOID pCertContext, FS_INT32* nType);
    static FS_BOOL GetCertStartTime2(FS_LPVOID pCert, FS_WideString* outwsCertZeroTime, FS_WideString* outwsCertLocalTime, FS_INT32* nTimeZone);
    static FS_BOOL GetCertExpritesTime(FS_LPVOID pCert, FS_WideString wsCertZeroTime, FS_WideString wsCertLocalTime, FS_INT32* nTimeZone);
    static void CsToHex(const FS_ByteString csstr, FS_ByteString* outbsHex);
    static FS_BOOL	GenerateHashData(const FS_INT32 nHashAlg, const FS_BYTE* pbToHash, FS_DWORD cbToHash, FS_DWORD* nlen, FS_ByteString* outhashData);
    static FS_BOOL GenerateHashData1(const FS_INT32 nHashAlg, FS_DWORD cContents, FS_LPCBYTE rgpbContents[], FS_DWORD rgcbContents[], FS_DWORD* nlen, FS_ByteString* outhashData);
    static FS_BOOL	FindCustomSignOID(const FS_ByteString strOID);
	static FS_BOOLEAN GetQCStatements(FS_LPVOID pCert, FS_ByteStringArray* qcstatements);
	static FS_BOOLEAN IsTime1NotLaterThanTime2(FPD_SYSTEMTIME Time1, FPD_SYSTEMTIME Time2);
};

class CFPD_SignCRL_V14
{
public:
    static FPD_CRL New();
    static void Destroy(FPD_CRL crl);
    static FS_BOOL Init(FPD_CRL crl, FPD_Object pStream);
    static FS_BOOL Init1(FPD_CRL crl, FS_LPBYTE pCRLData, FS_INT32 nCRLDataSize);
    static FPD_Object GetStream(FPD_CRL crl);
};

class CFPD_SignOCSP_V14
{
public:
    static FPD_OCSP New();
    static void Destroy(FPD_OCSP ocsp);
    static FS_BOOL Init(FPD_OCSP ocsp, FPD_Object pStream);
    static FS_BOOL Init1(FPD_OCSP ocsp, FS_LPBYTE pCRLData, FS_INT32 nCRLDataSize);
    static FPD_Object GetStream(FPD_OCSP ocsp);
};

class CFPD_CGWSignDataRevoInfo_V14
{
public:
	static FPD_OCSPSTATUSTYPE GetType(FPD_ICGW_SignDataRevoInfo info);
	static void SetType(FPD_ICGW_SignDataRevoInfo info, FPD_OCSPSTATUSTYPE type);
	static FPD_Object GetRevoInfoPDFSteam(FPD_ICGW_SignDataRevoInfo info, FPDOCSP_PROCESSTYPE* eType);
	static FS_INT64 GetRevoinfoSize(FPD_ICGW_SignDataRevoInfo info);
	static FS_BOOL GetLocalSignVarifyTime(FPD_ICGW_SignDataRevoInfo info, FPD_SYSTEMTIME* time);
	static void SetLocalSignVarifyTime(FPD_ICGW_SignDataRevoInfo info, const FPD_SYSTEMTIME time);
	static FS_BOOL GetLocalRevoCheckTime(FPD_ICGW_SignDataRevoInfo info, FPD_SYSTEMTIME* time);
	static void SetLocalRevoCheckTime(FPD_ICGW_SignDataRevoInfo info, const FPD_SYSTEMTIME localtime);
	static void GetRevoInfoHashKey(FPD_ICGW_SignDataRevoInfo info, FS_ByteString* bsKey);
	static void Destroy(FPD_ICGW_SignDataRevoInfo info);
};


class CFPD_ReovcationProgressCallBackMgr : public IFX_ReovcationProgressCallBack
{
public:
	CFPD_ReovcationProgressCallBackMgr(FPD_ReovcationProgressCallBackRec* callback);
	virtual void SetCurValue(FX_INT32 nCurPos);
	virtual FX_BOOL IsCancelled();
	virtual void PeekAndPump();
	virtual void SetText(REOVACATION_TEXT type, const CFX_ByteString& csURL);
	virtual void CreateUIProgress();
	virtual void DestroyUIProgress();

	FPD_ReovcationProgressCallBackRec m_callback;
};

class CFPD_ReovcationProgressCallBack_V14
{
public:
    static FPD_ReovationProgressCallbackMgr New(FPD_ReovcationProgressCallBack callback);
    static void Destroy(FPD_ReovationProgressCallbackMgr mgr);
};

class CFPD_CHECKREVOINFODATA_V14
{
public:
    static FPD_CHECKREVOINFODATA New();
    static void Destroy(FPD_CHECKREVOINFODATA data);
    static void GetSignContens(FPD_CHECKREVOINFODATA data, FS_ByteString* outContens);
    static void SetSignContens(FPD_CHECKREVOINFODATA data, FS_ByteString  signContens);
    static void GetSignHash(FPD_CHECKREVOINFODATA data, FS_ByteString* outHash);
    static void SetSignHash(FPD_CHECKREVOINFODATA data, FS_ByteString signHash);
    static void SetEType(FPD_CHECKREVOINFODATA data, FPD_VERIFYTIMETYPE type);
    static FPD_VERIFYTIMETYPE GetEType(FPD_CHECKREVOINFODATA data);
    static void GetUTCtime(FPD_CHECKREVOINFODATA data, FPD_SYSTEMTIME* outTime);
    static void SetUTCtime(FPD_CHECKREVOINFODATA data, FPD_SYSTEMTIME time);
    static FPD_ICGW_SignDataRevoInfo GetDSSInfo(FPD_CHECKREVOINFODATA data);
    static void SetDSSInfo(FPD_CHECKREVOINFODATA data, FPD_ICGW_SignDataRevoInfo info);
    static FPD_ICGW_SignDataRevoInfo GetSignInfo(FPD_CHECKREVOINFODATA data);
    static void SetSignInfo(FPD_CHECKREVOINFODATA data, FPD_ICGW_SignDataRevoInfo info);
    static void SetEReturnType(FPD_CHECKREVOINFODATA data, FPD_VERIFYTIMETYPE type);
    static FPD_VERIFYTIMETYPE GetEReturnType(FPD_CHECKREVOINFODATA data);
    static void GetReturnUTCtime(FPD_CHECKREVOINFODATA data, FPD_SYSTEMTIME* outTime);
    static void SetReturnUTCtime(FPD_CHECKREVOINFODATA data, FPD_SYSTEMTIME time);
};

class CFPD_CHECKData_V14
{
public:
	static FPD_CHECKData New();
	static void Destroy(FPD_CHECKData data);
	static void GetCheckDataType(FPD_CHECKData data, FPD_OCSPCHECKDATATYPE* outtype);
	static void SetCheckDataType(FPD_CHECKData data, FPD_OCSPCHECKDATATYPE type);
	static void GetSigntime(FPD_CHECKData data, FPD_SYSTEMTIME* outTime);
	static void SetSigntime(FPD_CHECKData data, FPD_SYSTEMTIME time);
	static void GetNexttime(FPD_CHECKData data, FPD_SYSTEMTIME* outTime);
	static void SetNexttime(FPD_CHECKData data, FPD_SYSTEMTIME time);
	static void GetRevocationtime(FPD_CHECKData data, FPD_SYSTEMTIME* outTime);
	static void SetRevocationtime(FPD_CHECKData data, FPD_SYSTEMTIME time);
	static void GetIssuer(FPD_CHECKData data, FS_WideString* outWsIssuer);
	static void SetIssuer(FPD_CHECKData data, FS_WideString wsIssuer);
	static void GetURL(FPD_CHECKData data, FS_ByteString* outURL);
	static void SetURL(FPD_CHECKData data, FS_ByteString wsURL);
	static FPD_CHECKData GetResponseData(FPD_CHECKData data);
	static void SetResponseData(FPD_CHECKData data, FPD_CHECKData chkData);
	static FPD_ICGW_SignDataRevoInfo GetRevoData(FPD_CHECKData data);
	static void SetResponseData2(FPD_CHECKData data, FPD_ICGW_SignDataRevoInfo info);
	static FS_LPCVOID GetResponseIssuer(FPD_CHECKData data);
};


class CFPD_VerifyRevoke_V14
{
public:
	static FPD_VerifyRevoke CreateRevoke();
	static void DeleteRevoke(FPD_VerifyRevoke revoke);
	static void SetReovactionProgressCallBack(FPD_VerifyRevoke revoke, FPD_ReovationProgressCallbackMgr pReovationCallBack);
	static void CheckRevoInfo(FPD_VerifyRevoke revoke, FPD_Document pPDFDoc, FPD_CHECKREVOINFODATA* checkData, FPD_CHECKData* infoData, FS_BOOL bIgnoreDoc, FS_BOOL bTrustSelf, FS_BOOL bCheckTime, FPD_OCSPCHECKDATATYPE* outDataType);
	static void SetRevoCheckTime(FPD_VerifyRevoke revoke, const PFPD_SYSTEMTIME time);
	static void SetSignTime(FPD_VerifyRevoke revoke, FPD_TIMETYPE eType, const FPD_SYSTEMTIME ctSignTime);
	static void SetCRLPath(FPD_VerifyRevoke revoke, const FS_WideString crlPath);
	static void SetTimeOutUrl(FPD_VerifyRevoke revoke, const FS_ByteStringArray url);
	static void GetTimeOutUrl(FPD_VerifyRevoke revoke, FS_ByteStringArray* url);
	static void SetCertAndIssure(FPD_VerifyRevoke revoke, const FS_ByteString cert, const FS_ByteStringArray issuerChain, FS_BOOL bEnd, FPD_OCSPCHECKDATATYPE* outType);
	static void ClearCheckData(FPD_VerifyRevoke revoke);
	static void ClearCheckRevo(FPD_VerifyRevoke revoke);
	static FPD_ICGW_SignDataRevoInfo GetRevoInfoInDss(FPD_VerifyRevoke revoke, FPD_Document pPDFDoc, const FS_ByteString csSignHash);
	static FPD_ICGW_SignDataRevoInfo GetDSSDataRevoinfo(FPD_VerifyRevoke revoke, FPD_Object pDssDict, const FS_ByteString csSignHash);
	static FPD_ICGW_SignDataRevoInfo GetSignDataRevoinfo(FPD_VerifyRevoke revoke, FS_LPCBYTE pbSig, FS_DWORD cbSig);
	static void CheckCertRevo_online(FPD_VerifyRevoke revoke, FS_LPVOID xCert, FS_LPVOID xIssure, FPD_CHECKData* reData, FPD_Response* responseInfo, FPD_OCSPCHECKDATATYPE* outType);
	static void CheckRevoInfoInSignData(FPD_VerifyRevoke revoke, FPD_ICGW_SignDataRevoInfo pInfo, FS_LPVOID xCert, FS_LPVOID xIssure, FPD_CHECKData* reData, FPD_OCSPCHECKDATATYPE* outType);
	static FS_LPVOID GetXCert(FPD_VerifyRevoke revoke);
	static FS_LPVOID GetXIssuer(FPD_VerifyRevoke revoke);
	static void SetCRLDownloadHandler(FPD_VerifyRevoke revoke, FPD_DownloadHandlerCallBack pDownloadHandlerCallback);
};


class CFPD_VRI_V14
{
public:
    static FPD_VRI CreateVRI(FPD_Document pDoc, FPD_VRICreatedTimeType type);
    static FPD_VRI CreateVRI1(FPD_Object pDict, FPD_Document pDoc);
    static void DeleteVRI(FPD_VRI vriObj);
    static FS_BOOL				AddTU(FPD_VRI vriObj, FPD_SYSTEMTIME tuTime);
    static FS_BOOL				AddCRL(FPD_VRI vriObj, FPD_CRL pSelectedCRL);
    static FS_BOOL				AddOCSP(FPD_VRI vriObj, FPD_OCSP pSelectedOCSP);
    static FS_BOOL		IsInArray(FPD_Object pArray, FPD_Object pStream);
    static FPD_Object	GetDict(FPD_VRI vriObj);
    static FPD_Object	GetCRLArray(FPD_VRI vriObj);
    static FPD_Object	GetOCSPArray(FPD_VRI vriObj);
};

class CFPD_DSS_V14
{
public:
    static FPD_DSS CreateDSS(FPD_Document pDoc);
    static void DeleteDSS(FPD_DSS dssObj);
    static FS_BOOL	IsEmpty(FPD_DSS dssObj);
    static FS_BOOL	AddVRI(FPD_DSS dssObj, FS_LPCBYTE key, FPD_VRI pVRI);
    static FS_BOOL	AddVRI1(FPD_DSS dssObj, FS_ByteString key, FS_ByteStringArray* strArray, FS_PtrArray* certArray, FPD_SYSTEMTIME tuTime);
    static  FPD_Object	GetVRIDict(FPD_DSS dssObj);
    static  FPD_Object	GetCertArray(FPD_DSS dssObj);
    static  FPD_Object	GetCRLArray(FPD_DSS dssObj);
    static  FPD_Object	GetOCSPArray(FPD_DSS dssObj);
    static  FPD_Object	GetDSS(FPD_DSS dssObj);
    static void	CreateDSSForDoc(FPD_DSS dssObj);
};

class CFPD_SignatureVerifyResult_V14
{
public:
    static FPD_SignatureVerifyResult CreateVerifyResult();
    static void DeleteResult(FPD_SignatureVerifyResult result);
    static void SetOCSPRespResult(FPD_SignatureVerifyResult result, FPD_SignatureVerifyResult pSVI);
    static void SetTSTResult(FPD_SignatureVerifyResult result, FPD_SignatureVerifyResult pSVI);
    static void GetSignatureName(FPD_SignatureVerifyResult result, FS_ByteString* name);
    static void GetSignatureHash(FPD_SignatureVerifyResult result, FS_ByteString* hash);
    static FS_DWORD GetSignatureStatus(FPD_SignatureVerifyResult result);
    static void GetSigCheckTime(FPD_SignatureVerifyResult result, FPD_SYSTEMTIME* checkTime);
    static FPD_LTVState GetLTVattribute(FPD_SignatureVerifyResult result);
    static FPD_SigTimeType GetSigCheckTimeType(FPD_SignatureVerifyResult result);
    static void GetCertResultString(FPD_SignatureVerifyResult result, FS_ByteStringArray* bsArray);
    static void GetCertVerifyResult(FPD_SignatureVerifyResult result, FS_PtrArray* resultArray);
    static void GetOCSPSigResult(FPD_SignatureVerifyResult result, FS_PtrArray* OCSPresultArray);
    static FPD_SignatureVerifyResult GetSigTSTResult(FPD_SignatureVerifyResult result);
};

class CFPD_TrustedCertStoreHandler : public IPDF_TrustedCertStore
{
public:
	CFPD_TrustedCertStoreHandler(FPD_TrustedCertStoreCallBackRec* callback);
	virtual FX_BOOL IsCertTrusted(const CFX_ByteString& cert);
	virtual FX_BOOL IsCertTrustedRoot(const CFX_ByteString& cert);

	FPD_TrustedCertStoreCallBackRec m_callback;
};

class CFPD_TrustedCertStore_V14
{
public:
    static FPD_TrustedCertStore New(FPD_TrustedCertStoreCallBack callbacks);
    static void Destroy(FPD_TrustedCertStore handler);
};


class CFPD_LtvVerifier_V14
{
public:
    //************************************
    // Function:  New
    //param[in] pDoc				The document of the PDF file.
    //param[in] pFile				The PDF file reader.
    //param[in] isVerifySig	        Whether verify signature validity when verify signature.
    //param[in] useExpireTST		Whether use the expired TST to verify signature.
    //param[in] ignoreDocInfo		Whether use the revocation info in DSS and signature.
    //param[in] sigTimeType		    The verify time user selected to verify the signature.
    //                              User should not set TU_TIME, but can set other three timetype.
    // Return:    FPD_LtvVerifier object
    // Remarks:
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
    //************************************
    static FPD_LtvVerifier New(FPD_Document pDoc, FS_FileReadHandler pFile, FS_BOOL isVerifySig, FS_BOOL useExpireTST, FS_BOOL ignoreDocInfo, FPD_SigTimeType sigTimeType);

    //************************************
    // Function:  Destory
    // param[in]  verifier				The CPDF_LtvVerifier object.
    // Return:    void
    // Remarks:
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
    //************************************
    static void Destory(FPD_LtvVerifier verifier);

    //************************************
    // Function:  Destory
    // param[in]  verifier		The CPDF_LtvVerifier object.
    // param[in]  pHandler		The handler used for set.
    // Return:  FS_BOOL  true for success, false for error.
    // Remarks:  Set the handler used for parse the cert and response.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
    //************************************
    static FS_BOOL	SetRevocationHandler(FPD_LtvVerifier verifier, FPD_RevocationHandler handler);

    //************************************
    // Function:  SetVerifyMode
    // param[in]  verifier		The CPDF_LtvVerifier object.
    // param[in]  mode		The verify mode used for express verify process.
    // Return:  FS_BOOL  true for success, false for error.
    // Remarks:  Set the verify process.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
    //************************************
    static FS_BOOL		SetVerifyMode(FPD_LtvVerifier verifier, FPD_VerifyMode mode);

    //************************************
    // Function:  SetCertStore
    // param[in]  verifier		The CPDF_LtvVerifier object.
    // param[in]  trustedCertStore		The handler used for set.
    // Return:  FS_BOOL  true for success, false for error.
    // Remarks:  Set the class derived from IPDF_TrustedCertStore,this class should implement interface IsCertTrusted().
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
    //************************************
    static void			SetCertStore(FPD_LtvVerifier verifier, FPD_TrustedCertStore trustedCertStore);

    //************************************
    // Function:  Verify
    // param[in]  verifier		The CPDF_LtvVerifier object.
    // param[out] sviArray		Save all the result of signature in file specified by pFile,
    //							user should delete the point in sviArray to free memory after use.
    // param[in]  pSignatureEdit	The pointer to a CPDF_SignatureEdit object.
    // param[in]  pClientData		SDK need this param transmit data to CPDF_SignatureVerify.
    // Return:  verify result for the file.
    // Remarks:  Verify all the signature in the file specified by pFile,and save all the result to sviArray.
    // Notes:   When use mode - MODE_ETSI:
    //			If some signature verify failed, the validation process will stop,
    //          so the sviArray will only contains partial result of signature.
    //			When use mode - MODE_ACROBAT :
    //          Verify all the signature in the PDF file.
    // Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
    //************************************
    static FPD_VerifyResult	Verify(FPD_LtvVerifier verifier, FS_PtrArray sviArray, FPD_SignatureEdit pSignatureEdit, FS_LPVOID pClientData);

    //************************************
    // Function:  VerifySingleSig
    // param[in]  verifier		The CPDF_LtvVerifier object.
    // param[out]  sviArray		Save all the result of signature in file specified by pFile,
    //							user should delete the point in sviArray to free memory after use.
    // param[in]  pSignatureEdit	The pointer to a CPDF_SignatureEdit object.
    // param[in]  pInSig		The signature used for verify.
    // param[in]  pClientData	SDK need this param transmit data to CPDF_SignatureVerify.
    // Return:  FS_BOOL  true for success, false for error.
    // Remarks:  Verify the single signature in the file specified by pFile,and save the result to sviArray.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
    //************************************
    static FPD_VerifyResult	VerifySingleSig(FPD_LtvVerifier verifier, FS_PtrArray sviArray, FPD_SignatureEdit pSignatureEdit, FPD_Signature pInSig, FS_LPVOID pClientData);

    //************************************
    // Function:  AddDSS
    // param[in]  verifier		The CPDF_LtvVerifier object.
    // param[out]  pSVI		    The signature whose VRI info will be add to DSS.
    // Return:  FS_BOOL         true for success, false for error.
    // Remarks:  Add the VRI info of the signature to the DSS dictionary.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 8.3.2
    //************************************
    static FS_BOOL			AddDSS(FPD_LtvVerifier verifier, FPD_SignatureVerifyResult pSVI);
};

class CFPD_SigModifyList_V14
{
public:
	static FPD_SigModifyList New();
	static void Delete(FPD_SigModifyList modifylist);
	static void GetOBJECTTYPEList(FPD_SigModifyList modifylist, FS_Int32Array* outobjtypeArr);
	static void GetMODIFYTYPEByOBJTYPE(FPD_SigModifyList modifylist, FPD_OBJECTTYPE objtype, FS_Int32Array* outmodifytypeArr);
	static FS_INT32 GetMODIFYADATACountByModifyType(FPD_SigModifyList modifylist, FPD_OBJECTTYPE objtype, FPD_MODIFYTYPE modifyType);
	static void GetMODIFYADATAByModifyTypeAndIndex(FPD_SigModifyList modifylist, FPD_OBJECTTYPE objtype, FPD_MODIFYTYPE modifyType,FS_INT32 index, FPD_MODIFYDATA* outData);
};

class CFPD_IncreSaveModifyDetector_V14
{
public:
	static FPD_IncreSaveModifyDetector New(FPD_Document pDoc, FS_FileReadHandler pFile, FS_INT32 docType, FS_BOOL isModifyed);
	static void Delete(FPD_IncreSaveModifyDetector detector);
	static FS_BOOL ParseIncrementObject(FPD_IncreSaveModifyDetector detector);
	static FPD_CHECKRESULT CheckLegalityForModify(FPD_IncreSaveModifyDetector detector, FS_DWORD nSignFieldObjNum,
		FS_DWORD nSignvObjNum,
		FPD_PERRESULT eSignPermission,
		FS_BOOL bDocMDP,
		FPD_PermissionResult result,
		FS_FileReadHandler pFile);
	static FPD_PERRESULT GetAccessPermissions(FPD_Object pSigDIct,
		FPD_Object plockDict,
		FS_BOOLEAN* bDocMDP,
		FPD_PermissionResult result);
	static FS_BOOL IsHasSign(FPD_IncreSaveModifyDetector detector);
	static FS_INT32 GetSignListCount(FPD_IncreSaveModifyDetector detector);
	static void FindIncrementIndex(FPD_IncreSaveModifyDetector detector, FS_DWORD dwObjNum, FPD_IncrementIndex* outindex);
	static void FindNextIncrementIndex(FPD_IncreSaveModifyDetector detector, FPD_IncrementIndex nIndex, FPD_IncrementIndex* outindex);
	static void FindPreIncrementIndex(FPD_IncreSaveModifyDetector detector, FPD_IncrementIndex nIndex, FPD_IncrementIndex* outindex);
	static void ClearSignData(FPD_IncreSaveModifyDetector detector, FS_DWORD signObjectnum);
	static void ClearData(FPD_IncreSaveModifyDetector detector);
	static FS_DWORD UpdateVerifyFromCHECKRESULT(FPD_IncreSaveModifyDetector detector, FPD_CHECKRESULT eResult, FS_DWORD dwVerify, FS_BOOL bCertify, FPD_PERRESULT nAccessPermiss);
	static void GetModifyListForSign(FPD_IncreSaveModifyDetector detector, FS_DWORD signObjectnum, FS_BOOL bDocMDP, FPD_SigModifyList* poutModiyfList);
	static void AddModifyData(FPD_IncreSaveModifyDetector detector, FPD_OBJECTTYPE eMtype, FPD_MODIFYTYPE eType, FPD_MODIFYDATA scdata, FPD_SigModifyList* poutModiyfList);
	static void GetModifySign(FPD_IncreSaveModifyDetector detector, FPD_IncrementIndex nIndex, FS_BOOL bDocMDP, FPD_SigModifyList* poutModiyfList);
	static void GetSignByIndex(FPD_IncreSaveModifyDetector detector, FS_INT32 index, FPD_SignAndIncrementIndex* signIncrement);
};

class CFPD_PermissionResult_V14
{
public:
	static FPD_PermissionResult  New();
	static void  Destroy(FPD_PermissionResult result);
	static void  GetPermissionsKeyArray(FPD_PermissionResult result, FS_Int32Array* indexArray);
	static void  GetPermissionsValueByKey(FPD_PermissionResult result, FS_INT32 key, FS_ByteStringArray* dataArray);
};

class CFPD_SignatureEdit_V14
{
public:
    static FPD_SignatureEdit NewSignatureEdit(FPD_Document pDoc);
    static FPD_SignatureEdit NewSignatureEdit1(FPD_Document pDoc, FPD_InterForm pInterForm);
    static void DeleteSignatureEdit(FPD_SignatureEdit edit);
    static FS_BOOL	LoadSignatures(FPD_SignatureEdit edit);
    static void	FixPageSignatureFields(FPD_SignatureEdit edit, const FPD_Object pPageDict);
    static FS_INT32		CountSignatures(FPD_SignatureEdit edit);
    static FPD_Signature GetSignature(FPD_SignatureEdit edit, FS_INT32 nIndex);
    static FPD_Signature GetSignatureAtPos(FPD_SignatureEdit edit, FPD_Page pPage, FS_FLOAT x, FS_FLOAT y, FS_FLOAT tolerance);
    static FS_BOOL AddNewSignature(FPD_SignatureEdit edit, FPD_Signature pSig, FPD_Page pPage, FS_FloatRect pRect, FS_BOOL bCheck, FS_BOOL bIsIgnoreUR3, FS_BOOL bIsInsertToPage);
    static FS_BOOL	UpdateSignature(FPD_SignatureEdit edit, FPD_Signature pSig);
    static FS_BOOL	RemoveSignature(FPD_SignatureEdit edit, FPD_Signature pSig);
    static FS_BOOL	RemoveSignatures(FPD_SignatureEdit edit);
    static FS_BOOL	IsSigned(FPD_SignatureEdit edit);
};

class CFPD_Signature_V14
{
public:
    static FPD_Signature NewSignature(FS_INT32 type);
    static FPD_Signature NewSignature1(FPD_Object pFormfieldDict, FS_INT32 type);
    static void DeleteSignature(FPD_Signature sig);
    static FPD_Object CreateSigVDict(FPD_Signature sig, const FS_ByteString psubFilter, const FS_ByteString pFilter);
    static FPD_Object GetSignatureDict(FPD_Signature sig);
    static FPD_Object GetSignatureVDict(FPD_Signature sig);
    static FS_BOOL	SetKeyValue(FPD_Signature sig, FS_LPCBYTE bsKey, const FS_ByteString bsValue);
    static FS_BOOL	SetKeyValue1(FPD_Signature sig, FS_LPCBYTE bsKey, const FS_WideString wsValue);
    static FS_BOOL	GetKeyValue(FPD_Signature sig, FS_LPCBYTE bsKey, FS_ByteString* bsValue);
    static FS_BOOL	GetKeyValue1(FPD_Signature sig, FS_LPCBYTE bsKey, FS_WideString* wsValue);
    static FS_BOOL	SetFlags(FPD_Signature sig, FS_LPCBYTE bsKey, FS_DWORD wFlags);
    static FS_DWORD	GetFlags(FPD_Signature sig, FS_LPCBYTE bsKey);
    static FS_BOOL	SetCertChain(FPD_Signature sig, const FS_WideStringArray wsCertChainArray);
    static FS_INT32	CountCerts(FPD_Signature sig);
    static FS_BOOL GetCert(FPD_Signature sig, FS_INT32 nIndex, FS_ByteString* csCert);
    static FS_BOOL	SetDataTime(FPD_Signature sig, const FPDCRT_DATETIMEZONE dt);
    static FS_BOOL	GetDataTime(FPD_Signature sig, FPDCRT_DATETIMEZONE* dt);
    static FS_BOOL	SetEstimateContentLength(FPD_Signature sig, FS_DWORD wLength);
    static FS_DWORD	GetEstimateContentLength(FPD_Signature sig);
    static FS_BOOL	IsTimeStamp(FPD_Signature sig);
    static void		ResetAppearance(FPD_Signature sig, FPD_Form pForm);
    static FPD_Form	GetAppearance(FPD_Signature sig);
    static void	 SetPermissions(FPD_Signature sig, FS_INT32 nPerm);
    static FS_INT32	GetPermissions(FPD_Signature sig);
    static void		SetFormFieldAction(FPD_Signature sig, FS_LPCBYTE bsAction, const FS_WideStringArray fieldArray);
    static void		GetFormFieldAction(FPD_Signature sig, FS_ByteString* bsAction, FS_WideStringArray* fieldArray);
    static void		SetJavaScript(FPD_Signature sig, const FS_WideString wsJavaScript);
    static void		SetSignerCertPath(FPD_Signature sig, const FS_WideString wsCertPath, const FS_WideString wsPasssword);
    static void		GetSignerCertPath(FPD_Signature sig, FS_WideString* wsCertPath, FS_WideString* wsPassword);
    static void		SetSignerCertFileStream(FPD_Signature sig, FS_FileStream pFileStream, const FS_WideString wsPasssword);
    static void		GetSignerCertFileStream(FPD_Signature sig, FS_FileStream* pFileStream, FS_WideString* wsPassword);
    static void		SetCertID(FPD_Signature sig, const FS_ByteString certID, const FS_ByteString pCertPrivateKey);
    static void		GetPrivateKey(FPD_Signature sig, FS_ByteString* bsKey);
    static void		GetCertID(FPD_Signature sig, FS_ByteString* bsID);
    static FPD_CertInfoType		GetCertInfoType(FPD_Signature sig);
    static void		SetSignatureType(FPD_Signature sig, FS_INT32 nSigType);
    static FS_INT32	GetSignatureType(FPD_Signature sig);
    static void		SetVerifyState(FPD_Signature sig, FS_INT32 nVeriState);
    static FS_INT32	GetVerifyState(FPD_Signature sig);
    static void		SetIncludeRevocationStatus(FPD_Signature sig, FS_BOOL bInclude);
    static FS_BOOL	GetIncludeRevocationStatus(FPD_Signature sig);
    static FS_BOOL	SetSMID(FPD_Signature sig, FS_LPBYTE pSMID, FS_INT32 nIDLen);
    static FS_LPBYTE GetSMID(FPD_Signature sig);
    static void		SetSealID(FPD_Signature sig, FS_LPBYTE SealID, FS_INT32 IDLen);
    static void		GetSealID(FPD_Signature sig, FS_ByteString* bsID);
    static void		SetOnLine(FPD_Signature sig, FS_BOOL bOnLine);
    static FS_BOOL	GetOnLine(FPD_Signature sig);
    static void		AddDSSVRI(FPD_Signature sig);
    static void		AddDSSCerts(FPD_Signature sig);
    static void		AddDSSCRLs(FPD_Signature sig);
    static void		AddDSSOCSPs(FPD_Signature sig);
    static FS_BOOL	IsHasFieldMDP(FPD_Signature sig);
};

class CFPD_SignatureSign_V14
{
public:
	static FPD_SignatureSign New(FPD_Document pDoc, FPD_Signature pSig, FS_FileStream pFile, FS_LPVOID pClientData);
	static FPD_SignatureSign New1(FPD_Document pDoc, FPD_Signature pSig, FS_LPCSTR sFile, FS_LPVOID pClientData);
	static FPD_SignatureSign New2(FPD_Document pDoc, FPD_Signature pSig, FS_LPCWSTR wsFile, FS_LPVOID pClientData);
	static void Delete(FPD_SignatureSign sign);
	static FS_BOOL Start(FPD_SignatureSign sign, FS_BOOL isCallerSaveTempFile, FPD_InterForm pInterForm);
	static FPD_ProgressiveStatus Continue(FPD_SignatureSign sign, FS_PauseHandler pPause);
	static FS_INT32	GetPercent(FPD_SignatureSign sign);
	static void SetSignedFile(FPD_SignatureSign sign, FS_FileStream pSignedStream);
	static void SetParserCallback(FPD_SignatureSign sign, FPD_CALLBACK_GETKEY pCallback);
};

class CFPD_SignatureVerify_V14
{
public:
	static FPD_SignatureVerify New(FS_FileReadHandler pFile, FPD_Signature pSig, FPD_SGCLIENTDATA pClientData);
	static FPD_SignatureVerify New1(FS_FileReadHandler pFile, FPD_Signature pSig, FPD_Document pDoc, FPD_SGCLIENTDATA pClientData);
	static FPD_SignatureVerify New2(FPD_Signature pSig, FS_LPCSTR sFile, FPD_SGCLIENTDATA pClientData);
	static FPD_SignatureVerify New3(FPD_Signature pSig, FS_LPCWSTR wsFile, FPD_SGCLIENTDATA pClientData);
	static void Delete(FPD_SignatureVerify verify);
	static FS_BOOL		Start(FPD_SignatureVerify verify);
	static FPD_ProgressiveStatus	Continue(FPD_SignatureVerify verify, FS_PauseHandler pPause);
	static FS_DWORD GetVerifyResult(FPD_SignatureVerify verify);
	static FS_DWORD GetVerifySubResult(FPD_SignatureVerify verify);
	static FS_INT32 GetPercent(FPD_SignatureVerify verify);
};

class CFPD_TimeStampServer_V14
{
public:
    static FPD_RequestResult	SendTimestampRequest(FPD_TimeStampServer server, FS_LPCBYTE pRequest, FS_INT32 nRequestLen);
    static FS_BOOL	GetTimestamp(FPD_TimeStampServer server, FS_LPBYTE* pTimestamp, FS_INT32* nTimestampLen);
    static void 	GetServerName(FPD_TimeStampServer server, FS_WideString* wsName);
    static void 	GetUserNameF(FPD_TimeStampServer server, FS_WideString* wsUserName);
    static void 	GetServerURL(FPD_TimeStampServer server, FS_WideString* wsURL);
    static void 	GetPassword(FPD_TimeStampServer server, FS_WideString* wspwd);
};

class CFPD_TimeStampServerMgr_V14
{
public:
    static FPD_TimeStampServerMgr		CreateTimeStampServerMgr();
    static FPD_TimeStampServerMgr		GetTimeStampServerMgr();
    static void							Destroy(FPD_TimeStampServerMgr mgr);
    static FS_INT32						CreateNewServer(FPD_TimeStampServerMgr mgr, const FS_WideString serverName, const FS_WideString serverURL, const FS_WideString userName, const FS_WideString password);
    static FS_INT32						CountServers(FPD_TimeStampServerMgr mgr);
    static FPD_TimeStampServer			GetServer(FPD_TimeStampServerMgr mgr, FS_INT32 nIndex);
    static FS_INT32						GetIndex(FPD_TimeStampServerMgr mgr, const FPD_TimeStampServer pServer);
    static FPD_TimeStampServer			GetDefaultServer(FPD_TimeStampServerMgr mgr);
    static FS_BOOL						SetDefaultServer(FPD_TimeStampServerMgr mgr, FS_INT32 nIndex);
    static void							RemoveServer(FPD_TimeStampServerMgr mgr, FS_INT32 nIndex);
	static void                         SetServerNotify(FPD_TimeStampServerMgr mgr, FPD_TimeStampServerNotify pNotify);
	static FPD_TimeStampServerNotify    GetServerNotify(FPD_TimeStampServerMgr mgr);
	static void                         SetSSLRequestServerNotify(FPD_TimeStampServerMgr mgr,FPD_SSLServerNoify pNotify);
	static FPD_SSLServerNoify           GetSSLRequestServerNotify(FPD_TimeStampServerMgr mgr);
};

class CFPD_SGBuffer_V14
{
public:
    static FPD_SGBuffer  CreateBuffer();
    static FPD_SGBuffer  CreateBuffer1(FS_DWORD size);
    static void DeleteBuffer(FPD_SGBuffer buffer);
    static FS_BYTE* GetBuffer(FPD_SGBuffer buffer);
    static FS_DWORD GetSize(FPD_SGBuffer buffer);
    static FS_BOOL IsEmpty(FPD_SGBuffer buffer);
    static FS_BOOL  IsEqual(FPD_SGBuffer buffer, const FPD_SGBuffer other);
    static void Reset(FPD_SGBuffer buffer, FS_BYTE* pBuffer, FS_DWORD size);
    static FS_BYTE* DetachBuffer(FPD_SGBuffer buffer);
    static FS_BYTE* ReAlloc(FPD_SGBuffer buffer, FS_DWORD size);
};

class CFPD_CertVerifyCallBackHandler : public IPDF_CertVerifyCallBack
{
public:
	CFPD_CertVerifyCallBackHandler(FPD_CertVerifyHandlerCallBackRec* callback);
	virtual FX_BOOL IsCertTrusted(void* pCert,
		const std::vector<void*>& cerList,
		FX_BOOL bDigitalSig,
		FX_BOOL bTimeStamp,
		FX_INT32 nCurIndex,
		FX_INT32& nTrustIndex);

	virtual FX_BOOL IsCertTrustedRoot(void* pCert, FX_BOOL bDigitalSig);

	virtual FX_BOOL TimeStampBefore();	

	virtual void* GetCertSoureType(const CFX_ByteString* Certid, FX_INT16& nType);

	FPD_CertVerifyHandlerCallBackRec m_callback;
};

class CFPD_CertVerifyCallBack_V14
{
public:
	static FPD_CertVerifyCallBack New(FPD_CertVerifyHandlerCallBack callbacks);
	static void Destroy(FPD_CertVerifyCallBack handler);
};

class CFPD_CheckDataTemplate_V14
{
public:
    static FPD_CheckDataTemplate GetCheckDataTemplate();
    static void GetCheckDataTemplate2(FPD_CheckDataTemplate data, FS_INT32 index, FS_PtrArray dataArr);
};


class CFPD_WinDefaultHandler_V14
{
public:
	static FPD_WinDefaultHandler CreateWinDefaultHandler();
	static void DeleteWinDefaultHandler(FPD_WinDefaultHandler handler);
	static FS_INT32 GetCertificateInfo(FPD_WinDefaultHandler handler, FPD_Signature pSig, FS_LPVOID pClientData);
	static FS_BOOL StartCalcDigest(FPD_WinDefaultHandler handler, FS_FileReadHandler pFile, const FS_DWordArray byteArray, FPD_Signature pSig, FS_LPVOID pClientData);
	static FS_INT32 ContinueCalcDigest(FPD_WinDefaultHandler handler, FS_PauseHandler pPause, FS_LPVOID pClientData);
	static FS_BOOL StartSign(FPD_WinDefaultHandler handler, FS_LPVOID pClientData);
	static FS_BOOL IsNeedPadData(FPD_WinDefaultHandler handler);
	static void SetCertVerifyCallBack(FPD_WinDefaultHandler handler, FPD_CertVerifyCallBack pCertVerifyCallBack);
	static void SetReovactionProgressCallBack(FPD_WinDefaultHandler handler, FPD_ReovationProgressCallbackMgr pReovationCallBack);
	static void SetCRLDownloadHandler(FPD_WinDefaultHandler handler, FPD_DownloadHandlerCallBack pDownloadHandlerCallback);
	static FS_BOOL Verify(FPD_WinDefaultHandler handler, const FS_ByteString bsSignedData, FS_DWORD* dwVerResult, FS_LPVOID pClientData, FS_DWORD* pVerSubResult);
	static void SetSigmedVDictObjNum(FPD_WinDefaultHandler handler, FS_DWORD objNum);
	static FS_BOOL GetSignVDictObjNum(FPD_WinDefaultHandler handler, FS_DWORD* objNum);
	static FS_BOOL IsSignCancel(FPD_WinDefaultHandler handler);
	static void SetDocument(FPD_WinDefaultHandler handler, FPD_Document pDocument);
	static void  GetSignedHashData(FPD_WinDefaultHandler handler, FS_ByteString* outHashData);
	static FS_DWORD VerifyDigest(FPD_WinDefaultHandler handler, FPD_Signature pSig,
		const FS_ByteString csSubFilter,
		FS_LPCBYTE pbSig,
		FS_DWORD cbSig,
		FS_DWORD cContents,
		FS_LPCBYTE rgpbContents[],
		FS_DWORD rgcbContents[],
		FS_DWORD* pVerSubResult);
	static FPD_VERIFYTIMETYPE	GetSignedTime(FPD_WinDefaultHandler handler, FS_DWORD dwVerify, FPD_SYSTEMTIME* pSystemTime, FS_BOOL bTrueDictM);
	static FS_BOOL GetTimeStampError(FPD_WinDefaultHandler handler);
	static FPD_REVOCATION_TYPE GetReocationType(FPD_SGCLIENTDATA data, FS_BOOL useTimeStamp);
	static FPD_LTVTYPE IsLTV(FPD_VERIFYTIMETYPE vType, FPD_SGCLIENTDATA data, FPD_CHECKRESULT cModifyType, FS_DWORD dwVerify);
	static FPD_CADESLEVEL GetCadesLevel(FS_BOOL bCades, FS_BOOL bDocTimeStamp, FS_BOOL bInDss, FS_BOOL bNextHadDocStamp, FS_DWORD dwVerify);
	static void SetPDFSigForPoliciesData(FPD_WinDefaultHandler handler, FPD_CertPolicesData certData);
	static FPD_SignatureHandler GetSignatureHandler(FPD_WinDefaultHandler handler);
	static FS_INT32 ContinueSign(FPD_WinDefaultHandler handler, FS_PauseHandler pPause, FS_LPVOID pClientData);
};


class CFPD_CertPolicesData_V14
{
public:
	static FPD_CertPolicesData  New(); 
	static void  Destroy(FPD_CertPolicesData data);
	static void AddItem(FPD_CertPolicesData data, FS_LPCSTR key, FPD_PoliciesData value);
	static void GetKeys(FPD_CertPolicesData data, FS_ByteStringArray* keyArr);
	static void GetPoliciesDataByKey(FPD_CertPolicesData data, FS_LPCSTR key, FPD_PoliciesData* policesData);
};

class CFPD_SignatureHandler : public IPDF_SignatureHandler
{
public:
    CFPD_SignatureHandler(FPD_SignatureHandlerCallBackRec* callback);
	virtual FX_INT32			GetCertificateInfo(CPDF_Signature* pSig, FX_LPVOID pClientData = NULL);
	virtual FX_BOOL				StartCalcDigest(IFX_FileRead* pFile, const CFX_DWordArray& byteArray, CPDF_Signature* pSig, FX_LPVOID pClientData = NULL);
	virtual FX_INT32			ContinueCalcDigest(IFX_Pause* pPause = NULL, FX_LPVOID pClientData = NULL);
	virtual FX_BOOL				StartSign(FX_LPVOID pClientData = NULL);	
	virtual FX_BOOL				IsNeedPadData();
	virtual FX_BOOL				Verify(const CFX_ByteString& bsSignedData, FX_DWORD& dwVerResult, FX_LPVOID pClientData = NULL, FX_DWORD* pVerSubResult = NULL);
	virtual FX_BOOL GetSignVDictObjNum(FX_DWORD& objNum);
	virtual FX_INT32            ContinueSign(IFX_Pause* pPause = NULL, FX_LPVOID pClientData = NULL);
	virtual CFX_ByteString      GetSignedData(FX_LPVOID pClientData = NULL);

    FPD_SignatureHandlerCallBackRec m_callback;
};

class CFPD_SignatureHandler_V14
{
public:
	static FPD_SignatureHandler New(FPD_SignatureHandlerCallBack callbacks);
	static void Destroy(FPD_SignatureHandler handler);
	static FPD_WinDefaultHandler GetWinDefaultHandler(FPD_SignatureHandler handler);
};

class CFPD_SignatureHandlerMgr_V14
{
public:
	//************************************
	// Function:  CreateSignatureHandlerMgr	
	// Deprecated: Internal use.
	//************************************
    static FPD_SignatureHandlerMgr  	CreateSignatureHandlerMgr();

	//************************************
	// Function:  GetSignatureHandlerMgr
	// Deprecated: Internal use.
	//************************************
    static FPD_SignatureHandlerMgr    	GetSignatureHandlerMgr();

	//************************************
	// Function:  Destroy	
	// Deprecated: Internal use.
	//************************************
    static void							Destroy(FPD_SignatureHandlerMgr mgr);

	//************************************
	// Function:  RegisterSignatureHandler	
	// Deprecated: Internal use.
	//************************************
	static void			RegisterSignatureHandler(FPD_SignatureHandlerMgr mgr, const FS_LPCSTR bsFilter, const FS_LPCSTR bsSubFilter, const FPD_SignatureHandler pHandler);
	
	//************************************
	// Function:  RegisterDefaultSignatureHandler	
	// FunDeleted: Deleted.
	//************************************
	static void         RegisterDefaultSignatureHandler(FPD_SignatureHandlerMgr mgr, FPD_SignatureHandlerType handlerType);
	
	//************************************
	// Function:  UnRegisterSignatureHandler
	// Deprecated: Internal use.
	//************************************
	static void		UnRegisterSignatureHandler(FPD_SignatureHandlerMgr mgr, const FS_LPCSTR bsFilter, const FS_LPCSTR bsSubFilter);
	
	//************************************
	// Function:  GetSignatureHandler	
	// Deprecated: Internal use.
	//************************************
	static FPD_SignatureHandler			GetSignatureHandler(FPD_SignatureHandlerMgr mgr, const FS_LPCSTR bsFilter, const FS_LPCSTR bsSubFilter);
};

class CFPD_Response_V14
{
public:
    static FPD_Response CreateResonse();
    static void DeleteResonse(FPD_Response response);
    static FPD_ResponseType GetResponseType(FPD_Response response);
    static void FPD_ResponseData(FPD_Response response, FS_ByteString* bsData);
};


class CFPD_RevocationHandler : public IFX_RevocationHandler
{
public:
    CFPD_RevocationHandler(FPD_RevocationHandlerCallBackRec* callback);

    virtual FX_BOOL		GetCertChainFromSig(const CFX_ByteString& sigContent, std::vector<CFX_ByteString>& certChain);
    virtual Response*	GetResponseOnLineForSingleCert(const CFX_ByteString& cert, const CFX_ByteString& issuer);
    virtual FX_BOOL		VerifyOCSP(const CFX_ByteString& cert, const CFX_ByteString& issuer, const CFX_ByteString& OCSPData, CertVerifyResult& result);
    virtual FX_BOOL		VerifyCRL(const CFX_ByteString& cert, const CFX_ByteString& issuer, const CFX_ByteString& CRLData, CertVerifyResult& reason);
    virtual FX_BOOL		IsCA(const CFX_ByteString& cert);
    virtual FX_BOOL		GetDTSTime(const CFX_ByteString& sigContent, FX_SYSTEMTIME& sysTime);
    virtual FX_BOOL		GetTSTSig(const CFX_ByteString& sigContent, CFX_ByteString& TSTsig);
    virtual FX_BOOL		GetTSTTime(const CFX_ByteString& sigContent, FX_SYSTEMTIME& sysTime);
    virtual FX_BOOL		GetOCSPCertAndIssuer(const CFX_ByteString& OCSPData,
        const std::vector<CFX_ByteString>& trustChain,
        CFX_ByteString& OCSPCert,
        CFX_ByteString& OCSPIssuer);
    virtual FX_BOOL		GetOCSPProducedAtTime(const CFX_ByteString& OCSPData, FX_SYSTEMTIME& producedAtTime);
    virtual FX_BOOL		IsOCSPNeedCheck(const CFX_ByteString& OCSPData);
	virtual FX_BOOL		GetCertValidDate(const CFX_ByteString& cert, FX_SYSTEMTIME& certStart, FX_SYSTEMTIME& certEnd);
    virtual FX_BOOL		GetOCSPSig(const CFX_ByteString& OCSPData, CFX_ByteString& sigContent);
    virtual FX_BOOL		GetCRLSig(const CFX_ByteString& CRLData, CFX_ByteString& sigContent);
    virtual FX_BOOL		GetRevocationInfoFromSignData(const CFX_ByteString& sigContent,
        std::vector<CFX_ByteString>& OCSPVector,
        std::vector<CFX_ByteString>& CRLVector);
    virtual FX_BOOL		IsIssuerMatchCert(const CFX_ByteString& cert, const CFX_ByteString& issuer);
	virtual void SetSignTime(TIME_TYPE eType, const FX_SYSTEMTIME& ctSignTime);
    virtual FX_SYSTEMTIME GetRevoCheckTime();
    virtual void SetRevoCheckTime(const FX_SYSTEMTIME* ptime);
    virtual void GetTimeOutUrl(std::vector<CFX_ByteString>& url);
    virtual void SetTimeOutUrl(const std::vector<CFX_ByteString>& url);
    virtual void ClearCheckData();
    virtual void ClearCheckRevocation();

    FPD_RevocationHandlerCallBackRec m_callback;
};

class CFPD_RevocationHandler_V14
{
public:
    static FPD_RevocationHandler New(FPD_RevocationHandlerCallBack callbacks);
    static void Destroy(FPD_RevocationHandler handler);
};


class CFPD_DownloadHandler : public IFX_DownloadHandler
{
public:
	CFPD_DownloadHandler(FPD_DownloadHandlerCallBackRec* callback);
	virtual DownLoadResult DownloadData(const char* url, IFX_FileStream* pFile);

	FPD_DownloadHandlerCallBackRec m_callback;
};

class CFPD_DownloadHandler_V14
{
public:	
	static FPD_RevocationHandler CreateDefaultRevocationHandler(FPD_DownloadHandlerCallBack pDownloadHandlerCallback);
};

class CFPD_SGCLIENTDATA_V14
{
public:
	static FPD_SGCLIENTDATA New();
	static void Delete(FPD_SGCLIENTDATA data);
	static void SetCreateStore(FPD_SGCLIENTDATA data, FPD_CertStore certStore);
	static FPD_CertStore GetCreateStore(FPD_SGCLIENTDATA data);
	static void SetVerifyStore(FPD_SGCLIENTDATA data, FPD_CertStore certStore);
	static FPD_CertStore GetVerifyStore(FPD_SGCLIENTDATA data);
	static void AddVerifyCertList(FPD_SGCLIENTDATA data, FS_ByteStringArray certList);
	static FS_INT32 GetVerifyCertListCount(FPD_SGCLIENTDATA data);
	static void GetVerifyCertListByIndex(FPD_SGCLIENTDATA data, FS_INT32 index, FS_ByteStringArray* certList);
	static void SetChainListIndex(FPD_SGCLIENTDATA data, FS_INT32 index);
	static FS_INT32 GetChainListIndex(FPD_SGCLIENTDATA data);
	static void SettsverifyStore(FPD_SGCLIENTDATA data, FPD_CertStore certStore);
	static FPD_CertStore GettsverifyStore(FPD_SGCLIENTDATA data);
	static void AddVerifyTimeStampCertList(FPD_SGCLIENTDATA data, FS_ByteStringArray certList);
	static FS_INT32 GetVerifyTimeStampCertListCount(FPD_SGCLIENTDATA data);
	static void GetVerifytsTimeStampCertListByIndex(FPD_SGCLIENTDATA data, FS_INT32 index, FS_ByteStringArray* certList);
	static void SetCurTimeStampChainListIndex(FPD_SGCLIENTDATA data, FS_INT32 index);
	static FS_INT32 GetCurTimeStampChainListIndex(FPD_SGCLIENTDATA data);
	static void SetTrustStore(FPD_SGCLIENTDATA data, FPD_CertStore certStore);
	static FPD_CertStore GetTrustStore(FPD_SGCLIENTDATA data);
	static void SetHashAlg(FPD_SGCLIENTDATA data, FS_LPCSTR hashAlg);
	static void GetHashAlg(FPD_SGCLIENTDATA data, FS_ByteString* outhashAlg);
	static void SetSignAlg(FPD_SGCLIENTDATA data, FS_LPCSTR signAlg);
	static void GetSignAlg(FPD_SGCLIENTDATA data, FS_ByteString* outSignAlg);
	static void SetRevocTimeoutURLs(FPD_SGCLIENTDATA data, FS_ByteStringArray urls);
	static void GetRevocTimeoutURLs(FPD_SGCLIENTDATA data, FS_ByteStringArray* outURLs);
	static void SetCRLPath(FPD_SGCLIENTDATA data, FS_LPCWSTR path);
	static void GetCRLPath(FPD_SGCLIENTDATA data, FS_WideString* path);
	static void SetFileStorePath(FPD_SGCLIENTDATA data, FS_LPCWSTR path);
	static void GetFileStorePath(FPD_SGCLIENTDATA data, FS_WideString* path);
	static void SetCertFilePath(FPD_SGCLIENTDATA data, FS_LPCSTR certPath);
	static void GetCertFilePath(FPD_SGCLIENTDATA data, FS_ByteString* outcertPath);
	static void SetCertFilePass(FPD_SGCLIENTDATA data, FS_LPCSTR certPass);
	static void GetCertFilePass(FPD_SGCLIENTDATA data, FS_ByteString* certPass);
	static void SetVERIFYDATA(FPD_SGCLIENTDATA data, FPDVERIFY_DATA verifyData);
	static void GetVERIFYDATA(FPD_SGCLIENTDATA data, FPDVERIFY_DATA* outverifydata);
	static void AddToRevocVerify(FPD_SGCLIENTDATA data, FS_INT32 nkeyIndex, FPD_CHECKData arr);
	static void GetRevocVerifyKeyIndex(FPD_SGCLIENTDATA data, FS_Int32Array* outkeyIndexArr);
	static FS_INT32 GetRevocVerifyCountByKeyIndex(FPD_SGCLIENTDATA data, FS_INT32 nkeyIndex);
	static FPD_CHECKData GetRevocVerifyByIndex(FPD_SGCLIENTDATA data, FS_INT32 nkeyIndex, FS_INT32 nIndex);
	static void AddToTimeStampRevocVerify(FPD_SGCLIENTDATA data, FS_INT32 nkeyIndex, FPD_CHECKData arr);
	static void GetTimeStampRevocVerifyKeyIndex(FPD_SGCLIENTDATA data, FS_Int32Array* outIndexArr);
	static FS_INT32 GetTimeStampRevocVerifyCountByKeyIndex(FPD_SGCLIENTDATA data, FS_INT32 nkeyIndex);
	static FPD_CHECKData GetTimeStampRevocRevocVerifyByIndex(FPD_SGCLIENTDATA data, FS_INT32 keyindex, FS_INT32 nIndex);	
	static void GetVerifytsTimeStampCertListByIndexAndArryIndex(FPD_SGCLIENTDATA data, FS_INT32 index, FS_INT32 arrIndex, FS_ByteString* certInfo);	
	static void GetVerifyCertListByIndexAndArryIndex(FPD_SGCLIENTDATA data, FS_INT32 index, FS_INT32 arrIndex, FS_ByteString* certInfo);
	static void SetIsEnableSeal(FPD_SGCLIENTDATA data, FS_BOOLEAN bEnable);
	static FPD_SealInfo GetSealInfo(FPD_SGCLIENTDATA data);
};

class CFPD_MODIFYDATA_V14
{
public:
	static FPD_MODIFYDATA Create();
	static void Destroy(FPD_MODIFYDATA data);
	static void SetRect(FPD_MODIFYDATA data, FS_FloatRect rect);
	static FS_FloatRect GetRect(FPD_MODIFYDATA data);
	static void SetObjectNum(FPD_MODIFYDATA data, FS_INT32 num);
	static FS_INT32 GetObjectNum(FPD_MODIFYDATA data);
	static void SetPageIndex(FPD_MODIFYDATA data, FS_INT32 pageIndex);
	static FS_INT32 GetPageIndex(FPD_MODIFYDATA data);
	static void SetType(FPD_MODIFYDATA data, FS_LPCWSTR type);
	static FS_LPCWSTR GetType(FPD_MODIFYDATA data);
	static void SetTName(FPD_MODIFYDATA data, FS_LPCWSTR name);
	static FS_LPCWSTR GetTName(FPD_MODIFYDATA data);
	static void SetNM(FPD_MODIFYDATA data, FS_LPCWSTR name);
	static FS_LPCWSTR GetNM(FPD_MODIFYDATA data);
	static void SetbNomodify(FPD_MODIFYDATA data, FS_BOOLEAN bNoModify);
	static FS_BOOLEAN GetbNomodify(FPD_MODIFYDATA data);
};


class CFPD_XFADocView_V14
{
public:
    static PFPDXFA_HDOC			GetDoc(FPD_XFADocView xfaDocView);
    static	FS_INT32			StartLayout(FPD_XFADocView xfaDocView, FS_INT32 iStartPage);
    static FS_INT32			    DoLayout(FPD_XFADocView xfaDocView, FS_PauseHandler pPause);
    static void				    StopLayout(FPD_XFADocView xfaDocView);
    static FS_INT32			    GetLayoutStatus(FPD_XFADocView xfaDocView);
    static	void				UpdateDocView(FPD_XFADocView xfaDocView);
    static FS_INT32			    CountPageViews(FPD_XFADocView xfaDocView);
    static FPD_XFAPageView		GetPageView(FPD_XFADocView xfaDocView, FS_INT32 nIndex);
    static PFPDXFA_HWIDGET       GetWidgetByName(FPD_XFADocView xfaDocView, FS_LPCWSTR wsName, FS_INT32 iNameType);
    static FPD_XFAWidgetAcc     GetWidgetAccByName(FPD_XFADocView xfaDocView, FS_LPCWSTR wsName, FS_INT32 iNameType);
    static void				    ResetWidgetData(FPD_XFADocView xfaDocView, FPD_XFAWidgetAcc pWidgetAcc);
    static FS_INT32			    ProcessWidgetEvent(FPD_XFADocView xfaDocView, FPD_XFAEventParam pParam, FPD_XFAWidgetAcc pWidgetAcc);
    static FPD_XFAWidgetHandler	GetWidgetHandler(FPD_XFADocView xfaDocView);
    static FPD_XFAWidgetIterator	CreateWidgetIterator(FPD_XFADocView xfaDocView);
    static FPD_XFAWidgetAccIterator CreateWidgetAccIterator(FPD_XFADocView xfaDocView, FPDXFA_WIDGETORDER eOrder);
    static PFPDXFA_HWIDGET			GetFocusWidget(FPD_XFADocView xfaDocView);
    static void				    KillFocus(FPD_XFADocView xfaDocView);
    static FS_BOOL				SetFocus(FPD_XFADocView xfaDocView, PFPDXFA_HWIDGET hWidget);
    static FS_BOOL				IsTableFormFirstPage(FPD_XFADocView xfaDocView);
    static void                 GetChangedFieldFullNames(FPD_XFADocView xfaDocView, FS_WideStringArray* wsValueChangedNames, FS_WideStringArray* wsPropertyChangedNames);
};

class CFPD_IXFAPageView_V14
{
public:
    static FPD_XFADocView	GetDocView(FPD_XFAPageView xfaPageView);
    static FS_INT32		    GetPageViewIndex(FPD_XFAPageView xfaPageView);
    static void			    GetPageViewRect(FPD_XFAPageView xfaPageView, FS_FloatRect* rtPage);
    static void			    GetDisplayMatrix(FPD_XFAPageView xfaPageView, FS_AffineMatrix* mt, const FS_Rect rtDisp, FS_INT32 iRotate);
    static FS_INT32		    LoadPageView(FPD_XFAPageView xfaPageView, FS_PauseHandler pPause);
    static void			    UnloadPageView(FPD_XFAPageView xfaPageView);
    static PFPDXFA_HWIDGET	GetWidgetByPos(FPD_XFAPageView xfaPageView, FS_FLOAT fx, FS_FLOAT fy);
    static FPD_XFAWidgetIterator CreateWidgetIterator(FPD_XFAPageView xfaPageView, FS_DWORD dwTraverseWay, FS_DWORD dwWidgetFilter);
};

class CFPD_CXFAWidgetAcc_V14
{
public:
    static FS_BOOL			GetName(FPD_XFAWidgetAcc acc, FS_WideString* wsName, FS_INT32 iNameType);
    static FS_BOOL			ProcessValueChanged(FPD_XFAWidgetAcc acc);
    static void			    ResetData(FPD_XFAWidgetAcc acc);
    static void			    SetImageEdit(FPD_XFAWidgetAcc acc, FS_LPCWSTR wsContentType, FS_LPCWSTR wsHref, FS_LPCWSTR wsData, FS_BOOL bNotify);
    static FPD_XFAWidgetAcc	GetExclGroup(FPD_XFAWidgetAcc acc);
    static FS_INT32		ProcessEvent(FPD_XFAWidgetAcc acc, FS_INT32 iActivity, FPD_XFAEventParam pEventParam);
    static FPDXFA_ATTRIBUTEENUM GetManifestAction(FPD_XFAWidgetAcc acc);
    static FS_INT32         GetManifestCountReives(FPD_XFAWidgetAcc acc);
    static void             GetManifestRefContent(FPD_XFAWidgetAcc acc, FS_INT32 index, FS_WideString* outContent);
    static FPDXFA_ELEMENT	GetUIType(FPD_XFAWidgetAcc acc);
    static FS_INT32		    GetAccess(FPD_XFAWidgetAcc acc, FS_BOOL bTemplate);
    static FS_BOOL			SetAccess(FPD_XFAWidgetAcc acc, FS_INT32 iAccess, FS_BOOL bNotify);
};


class CFPD_IXFAWidgetHandler_V14
{
public:
	static void			 GetName(FPD_XFAWidgetHandler handler, PFPDXFA_HWIDGET hWidget, FS_WideString* wsName, FS_INT32 iNameType);
	static FPD_XFAWidgetAcc  GetDataAcc(FPD_XFAWidgetHandler handler, PFPDXFA_HWIDGET hWidget);
	static FS_BOOL			GetBBox(FPD_XFAWidgetHandler handler, PFPDXFA_HWIDGET hWidget, FS_FloatRect* rtBox, FS_DWORD dwStatus, FS_BOOL bDrawFocus);
	static FS_BOOL			HasEvent(FPD_XFAWidgetHandler handler, FPD_XFAWidgetAcc pWidgetAcc, FPDXFA_EVENTTYPE eEventType);
	static FS_INT32		   ProcessEvent(FPD_XFAWidgetHandler handler, FPD_XFAWidgetAcc pWidgetAcc, FPD_XFAEventParam pParam);
	static FS_DWORD		   GetStatus(FPD_XFAWidgetHandler handler, PFPDXFA_HWIDGET hWidget);
	static FPD_XFAPageView	GetPageView(FPD_XFAWidgetHandler handler, PFPDXFA_HWIDGET hWidget);	
	static void			RenderWidget(FPD_XFAWidgetHandler handler, PFPDXFA_HWIDGET hWidget, FPD_Graphics pGS, FPD_XFARenderOptions pOptions, FS_AffineMatrix pMatrix, FS_BOOLEAN bFocus);
};

class CFPD_IXFAWidgetIterator_V14
{
public:
    static void				Release(FPD_XFAWidgetIterator iterator);
    static void				Reset(FPD_XFAWidgetIterator iterator);
    static PFPDXFA_HWIDGET			MoveToFirst(FPD_XFAWidgetIterator iterator);
    static PFPDXFA_HWIDGET			MoveToLast(FPD_XFAWidgetIterator iterator);
    static PFPDXFA_HWIDGET			MoveToNext(FPD_XFAWidgetIterator iterator);
    static PFPDXFA_HWIDGET			MoveToPrevious(FPD_XFAWidgetIterator iterator);
    static PFPDXFA_HWIDGET			GetCurrentWidget(FPD_XFAWidgetIterator iterator);
    static FS_BOOL				SetCurrentWidget(FPD_XFAWidgetIterator iterator, PFPDXFA_HWIDGET hWidget);
};


class CFPD_IXFAWidgetAccIterator_V14
{
public:
    static void				Release(FPD_XFAWidgetAccIterator iterator);
    static void				Reset(FPD_XFAWidgetAccIterator iterator);
    static FPD_XFAWidgetAcc		MoveToFirst(FPD_XFAWidgetAccIterator iterator);
    static FPD_XFAWidgetAcc		MoveToLast(FPD_XFAWidgetAccIterator iterator);
    static FPD_XFAWidgetAcc		MoveToNext(FPD_XFAWidgetAccIterator iterator);
    static FPD_XFAWidgetAcc		MoveToPrevious(FPD_XFAWidgetAccIterator iterator);
    static FPD_XFAWidgetAcc		GetCurrentWidgetAcc(FPD_XFAWidgetAccIterator iterator);
    static FS_BOOL				SetCurrentWidgetAcc(FPD_XFAWidgetAccIterator iterator, FPD_XFAWidgetAcc hWidget);
    static void				SkipTree(FPD_XFAWidgetAccIterator iterator);
};

class CFPD_CXFAEventParam_V14
{
public:
    static FPD_XFAEventParam		CreateEventParam();
    static void		SetEventType(FPD_XFAEventParam param, FPDXFA_EVENTTYPE eventType);
    static void DeleteEventParam(FPD_XFAEventParam param);	
	static void SetIsCancelAction(FPD_XFAEventParam param, FS_BOOLEAN m_bCancelAction);
	static FS_BOOLEAN GetIsCancelAction(FPD_XFAEventParam param);
};

class CFPD_StructTree_V16
{
public:
	//************************************
	// Function:  LoadDoc
	// Param[in]: pDoc			      The input PDF document.
	// Param[in]: bCreateIfNotExist	  Whether create if not exist, default is FALSE.
	// Return:	FPD_StructTree  The whole structure tree of the input PDF document.
	// Remarks:	 Load the whole structure tree of a parsed PDF document. 	
	// Notes: It needs to release by FPDStructTreeReleaseStructTree.
	//************************************
	static FPD_StructTree LoadDoc(FPD_Document pDoc, FS_BOOLEAN bCreateIfNotExist);

	//************************************
	// Function:  CountKids
	// Param[in]: structTree			      The input FPD_StructTree.
	// Return:	FS_INT32   Get the count of immediate children.
	// Remarks:	 Get the count of immediate children.
	// Notes: 
	//************************************
	static FS_INT32		 CountKids(FPD_StructTree structTree);
	
	//************************************
	// Function:  GetKid
	// Param[in]: structTree		  The input FPD_StructTree.
	// Param[in]: index			      The index of child.
	// Return:	FPD_StructElement     The child element of the struct tree.
	// Remarks:	 Get an immediate child.
	// Notes: 
	//************************************
	static FPD_StructElement GetKid(FPD_StructTree structTree, FS_INT32 index);

	//************************************
	// Function:  GetMCR
	// Param[in]: structTree		  The input FPD_StructTree.
	// Param[in]: pPageDict			  The input page dictionary.
	// Param[in]: pPageObjects		  The input page or form object.
	// Param[in]: pPageObject		  The input PDF graphics object.
	// Param[in]: bCreateIfNotExist	  Whether create if not exist.
	// Return:	FPD_MarkContentReference     The child element of the struct tree.
	// Remarks:	 Get mark content reference.
	// Notes: 
	//************************************
	static FPD_MarkContentReference 	GetMCR(FPD_StructTree structTree, FPD_Object pPageDict, FS_LPVOID pPageObjects, FPD_PageObject pPageObject, FS_BOOLEAN bCreateIfNotExist);
	
	//************************************
	// Function:  GetMCR2
	// Param[in]: structTree		  The input FPD_StructTree.
	// Param[in]: pPageDict			  The index page dictionary.
	// Param[in]: pAnnot		      The input annot object.
	// Param[in]: pPageObjects		  The input page or form object.
	// Param[in]: pPageObject		  The input PDF graphics object .
	// Param[in]: bCreateIfNotExist	  Whether create if not exist.
	// Return:	FPD_MarkContentReference     The child element of the struct tree.
	// Remarks:	 Get mark content reference.
	// Notes: 
	//************************************
	static FPD_MarkContentReference 	GetMCR2(FPD_StructTree structTree, FPD_Object pPageDict, FPD_Annot pAnnot, FS_LPVOID pPageObjects, FPD_PageObject pPageObject, FS_BOOLEAN bCreateIfNotExist);

	//************************************
	// Function:  GetOBJR
	// Param[in]: structTree		  The input FPD_StructTree.
	// Param[in]: pPageDict			  The input page dictionary.
	// Param[in]: pTargetObj		  The input target dictionary.
	// Param[in]: bCreateIfNotExist	  Whether create if not exist.
	// Return:	FPD_ObjectReference   Get object reference.
	// Remarks:	 Get object.
	// Notes: 
	//************************************
	static FPD_ObjectReference 		GetOBJR(FPD_StructTree structTree, FPD_Object pPageDict, FPD_Object pTargetObj, FS_BOOLEAN bCreateIfNotExist);
	
	//************************************
	// Function:  GetOBJR2
	// Param[in]: structTree		  The input FPD_StructTree.
	// Param[in]: pPageDict			  The input page dictionary.
	// Param[in]: pForm		          The input form object.
	// Param[in]: bCreateIfNotExist	  Whether create if not exist.
	// Return:	FPD_ObjectReference   Get object reference.
	// Remarks:	 Get object.
	// Notes: 
	//************************************
	static FPD_ObjectReference 		GetOBJR2(FPD_StructTree structTree, FPD_Object pPageDict, FPD_Form pForm, FS_BOOLEAN bCreateIfNotExist);

	//************************************
	// Function:  GetOBJR3
	// Param[in]: structTree		  The input FPD_StructTree.
	// Param[in]: pPageDict			  The input page dictionary.
	// Param[in]: pImage		      The input image object.
	// Param[in]: bCreateIfNotExist	  Whether create if not exist.
	// Return:	FPD_ObjectReference   Get object reference.
	// Remarks:	 Get object.
	// Notes: 
	//************************************
	static FPD_ObjectReference 		GetOBJR3(FPD_StructTree structTree, FPD_Object pPageDict, FPD_Image pImage, FS_BOOLEAN bCreateIfNotExist);

	//************************************
	// Function:  GetOBJR4
	// Param[in]: structTree		  The input FPD_StructTree.
	// Param[in]: pPageDict			  The input page dictionary.
	// Param[in]: pAnnot		      The input annot object.
	// Param[in]: bCreateIfNotExist	  Whether create if not exist.
	// Return:	FPD_ObjectReference   Get object reference.
	// Remarks:	 Get object.
	// Notes: 
	//************************************
	static FPD_ObjectReference 		GetOBJR4(FPD_StructTree structTree, FPD_Object pPageDict, FPD_Annot pAnnot, FS_BOOLEAN bCreateIfNotExist);

	//************************************
	// Function:  DetachFromTree
	// Param[in]: structTree		  The input FPD_StructTree.
	// Param[in]: pEntity			  The input FPD_StructTreeEntity.	
	// Return:	FS_BOOLEAN            Detach from struct tree.
	// Remarks:	 Detach from struct tree.
	// Notes: 
	//************************************
	static FS_BOOLEAN 				DetachFromTree(FPD_StructTree structTree, FPD_StructTreeEntity pEntity);

	//************************************
	// Function:  ReleaseStructTree
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Return:	void  
	// Remarks:	 It need to release in app by get from FPDStructTreeLoadDoc.	
	// Notes: 
	//************************************
	static void  ReleaseStructTree(FPD_StructTree structTree);

	//************************************
	// Function:  GetRootDict
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Return:	FPD_Object            Get root dictionary.
	// Remarks:	 Get root dictionary.
	// Notes: 
	//************************************
	static FPD_Object	GetRootDict(FPD_StructTree structTree);

	//************************************
	// Function:  GetStructElement
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Param[in]: pObjDict		      The input FPD_Object.	
	// Return:	FPD_StructElement            Get root dictionary.
	// Remarks:	 Get struct element.
	// Notes: 
	//************************************
	static FPD_StructElement	GetStructElement(FPD_StructTree structTree, FPD_Object pObjDict);

	//************************************
	// Function:  CreateStructElement
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Param[in]: bsRole		      The input FPD_StructTree.	
	// Param[in]: pObjDict		      The input FPD_Object.	
	// Return:	FPD_StructElement     Create the struct element.
	// Remarks:	 Create the struct element.
	// Notes: 
	//************************************
	static FPD_StructElement	CreateStructElement(FPD_StructTree structTree, FS_LPCSTR bsRole, FPD_Object pPageDict);

	//************************************
	// Function:  IsConnectedWithRoot
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Param[in]: pEntity		      The input FPD_StructTreeEntity.	
	// Return:	FS_BOOLEAN            true: It's connect with root.
	// Remarks:	 Whether is connect with root.
	// Notes: 
	//************************************
	static FS_BOOLEAN			IsConnectedWithRoot(FPD_StructTree structTree, FPD_StructTreeEntity pEntity);

	//************************************
	// Function:  AttachAsTreeKid
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Param[in]: pElement		      The input FPD_StructElement.	
	// Param[in]: nNewIndex		      The index of the tree kid.	
	// Return:	FS_BOOLEAN            true: Attach tree kid success.
	// Remarks:	 Attach the tree kid.
	// Notes: 
	//************************************
	static FS_BOOLEAN 			AttachAsTreeKid(FPD_StructTree structTree, FPD_StructElement pElement, FS_INT32 nNewIndex);

	//************************************
	// Function:  AttachAsElementKid
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Param[in]: pEntity		      The input FPD_StructTreeEntity.	
	// Param[in]: pNewParent		  The input FPD_StructElement.	
	// Param[in]: nNewIndex		      The index of the element kid.	
	// Return:	FS_BOOLEAN            true: Attach the element kid success.
	// Remarks:	 Attach as element kid.
	// Notes: 
	//************************************
	static FS_BOOLEAN 			AttachAsElementKid(FPD_StructTree structTree, FPD_StructTreeEntity pEntity, FPD_StructElement pNewParent, FS_INT32 nNewIndex);

	//************************************
	// Function:  GetDocument
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Return:	FPD_Document          Get FPD_Document of the structtree.
	// Remarks:	 Get FPD_Document of the structtree.
	// Notes: 
	//************************************
	static FPD_Document			GetDocument(FPD_StructTree structTree);

	//************************************
	// Function:  GetMCRWithMCID
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Param[in]: pPageDict		      The input page dictionary.
	// Param[in]: pPageObjects		  The input page objects.
	// Param[in]: nMCID		          The input MCID.
	// Param[in]: bCreateIfNotExist	  Whether need to create if not exist.
	// Return:	FPD_MarkContentReference   Get FPD_MarkContentReference with MCID.
	// Remarks:	 Get FPD_MarkContentReference with MCID.
	// Notes: 
	//************************************
	static FPD_MarkContentReference 	GetMCRWithMCID(FPD_StructTree structTree,FPD_Object pPageDict, FS_LPVOID pPageObjects, FS_INT32 nMCID, FS_BOOLEAN bCreateIfNotExist);
	
	//************************************
	// Function:  GetMCRWithMCID2
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Param[in]: pPageDict		      The input page dictionary.
	// Param[in]: pAnnot		      The input annot.
	// Param[in]: pPageObjects		  The input page objects.
	// Param[in]: nMCID		          The input MCID.
	// Param[in]: bCreateIfNotExist	  Whether need to create if not exist.
	// Return:	FPD_MarkContentReference   Get FPD_MarkContentReference with MCID.
	// Remarks:	 Get FPD_MarkContentReference with MCID.
	// Notes: 
	//************************************
	static FPD_MarkContentReference 	GetMCRWithMCID2(FPD_StructTree structTree, FPD_Object pPageDict, FPD_Annot pAnnot, FS_LPVOID pPageObjects, FS_INT32 nMCID, FS_BOOLEAN bCreateIfNotExist);

	//************************************
	// Function:  TraverseForPage
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Param[in]: pPageDict		      The input page dictionary.
	// Param[in]: pCallback		      The input traverse callback.
	// Param[in]: pUserData		      The client data of the calback.	
	// Return:	void
	// Remarks:	 Traverse for page dictionary.
	// Notes: 
	//************************************
	static void	TraverseForPage(FPD_StructTree structTree, FPD_Object pPageDict, FPDTraverseCallback pCallback, FS_LPVOID pUserData);

	//************************************
	// Function:  GetElementByID
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Param[in]: bsID		          The input ID.
	// Return:	void
	// Remarks:	 Get FPD_StructElement by input ID.
	// Notes: 
	//************************************
	static FPD_StructElement GetElementByID(FPD_StructTree structTree, FS_LPCSTR bsID);
	
	//************************************
	// Function:  GetDefaultStructNamespace
	// Param[in]: structTree		  The input FPD_StructTree.	
	// Return:	void
	// Remarks: Get a default Structure NameSpace.
	// Notes: 
	//************************************
	static FPD_StructNamespace	GetDefaultStructNamespace(FPD_StructTree structTree);

	//************************************
	// Function:  LoadDoc2
	// Param[in]: pDoc			      The input PDF document.
	// Param[in]: bCreateIfNotExist	  Whether create if not exist, default is FALSE.
	// Param[in]: bOnlyPDF20	      Load registered namespaces for PDF2.0.
	// Return:	FPD_StructTree  The whole structure tree of the input PDF document.
	// Remarks:	 Load the whole structure tree of a parsed PDF document. 	
	// Notes: It needs to release by FPDStructTreeReleaseStructTree.
	//************************************
	static FPD_StructTree LoadDoc2(FPD_Document pDoc, FS_BOOLEAN bCreateIfNotExist, FS_BOOLEAN bOnlyPDF20);
};


class CFPD_StructElement_V16
{
public:
	//************************************
	// Function:  GetType
	// Param[in]: element			      The input FPD_StructElement.
	// Return:	FPD_EntityType   Get the structure element Entity type.
	// Remarks:	 Get the structure element Entity type.
	// Notes: 
	//************************************
	static FPD_EntityType	GetType(FPD_StructElement element);
	
	//************************************
	// Function:  GetMappedRole
	// Param[in]: element			      The input FPD_StructElement.
	// Param[in]: bChainMap			      Whether is chain map.
	// Param[out]: bsRole			      Get the mapped role.
	// Return:	void
	// Remarks:	 Get map role of the FPD_StructElement.
	// Notes: 
	//************************************
	static void  GetMappedRole(FPD_StructElement element, FS_BOOLEAN bChainMap, FS_ByteString* bsRole);

	//************************************
	// Function:  CountKids
	// Param[in]: element			      The input FPD_StructElement.	
	// Return:	void
	// Remarks:	 Get the count of kids in the structure element.
	// Notes: 
	//************************************
	static FS_INT32 CountKids(FPD_StructElement element);
	
	//************************************
	// Function:  CountKids
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[in]: index			          The index of the child.	
	// Return:	FPD_StructTreeEntity
	// Remarks:	 Get a kid by zero-based kid index in the structure element.
	// Notes: 
	//************************************
	static FPD_StructTreeEntity GetKid(FPD_StructElement element, FS_INT32 index);
	
	//************************************
	// Function:  GetMappedRole
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[out]: bsRole			      Get the role.
	// Return:	void
	// Remarks:	 Get the structure element type name.
	// Notes: 
	//************************************
	static void GetRole(FPD_StructElement element, FS_ByteString* bsRole);
	
	//************************************
	// Function:  GetInfo
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[out]: outInfo			      Get the structure element info string.
	// Return:	void
	// Remarks:	 Get the structure element info string.
	// Notes: 
	//************************************
	static void GetInfo(FPD_StructElement element, FPD_StructElementInfo eInfo, FS_WideString* outInfo);
	
	//************************************
	// Function:  GetID
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[out]: outID			      Get the structure element ID.
	// Return:	void
	// Remarks:	 Get the structure element ID.
	// Notes: 
	//************************************
	static void  GetID(FPD_StructElement element, FS_ByteString* outID);
	
	//************************************
	// Function:  SetInfo
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[in]: eInfo			          The input FPD_StructElementInfo.
	// Param[in]: wsValue			      Set the info string.
	// Return:	void
	// Remarks:	 Set the structure element info string.
	// Notes: 
	//************************************
	static void SetInfo(FPD_StructElement element, FPD_StructElementInfo eInfo, FS_WideString wsValue);
	
	//************************************
	// Function:  SetRole
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[in]: bsRole			      The input structure element type name.
	// Return:	void
	// Remarks:	 Set the structure element type name.
	// Notes: 
	//************************************
	static void SetRole(FPD_StructElement element, FS_LPCSTR bsRole);
	
	//************************************
	// Function:  SetID
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[in]: bsValue			      The input structure element ID.
	// Return:	void
	// Remarks:	 Set the structure element ID.
	// Notes: 
	//************************************
	static void SetID(FPD_StructElement element, FS_ByteString bsValue);
	
	//************************************
	// Function:  HasInfo
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[in]: eInfo			          The input FPD_StructElementInfo.
	// Return:	FS_BOOLEAN   true: The structure element info string is exist.
	// Remarks:	 Check whether the structure element info string exist.
	// Notes: 
	//************************************
	static FS_BOOLEAN	HasInfo(FPD_StructElement element, FPD_StructElementInfo eInfo);
	
	//************************************
	// Function:  GetInfoRaw
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[in]: eInfo			          The input FPD_StructElementInfo.
	// Return:	FS_LPCSTR                 Get the element info string.
	// Remarks:	 Get the raw representation of structure element info string. 
	// Notes: 
	//************************************
	static FS_LPCSTR  GetInfoRaw(FPD_StructElement element, FPD_StructElementInfo eInfo);
	
	//************************************
	// Function:  GetAttr
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[in]: owner			          The input onwer string.
	// Param[in]: name			          The input name string.
	// Param[in]: bInheritable			  Whether inherit.
	// Param[in]: pDefaultValue			  If get fail will return default value.
	// Return:	FPD_Object                Get attribute value. 
	// Remarks:	 Get attribute value. 
	// Notes: 
	//************************************
	static FPD_Object GetAttr(FPD_StructElement element, FS_LPCSTR owner, FS_LPCSTR name, FS_BOOLEAN bInheritable, FPD_Object pDefaultValue);
	
	//************************************
	// Function:  SetAttr
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[in]: owner			          The input onwer string.
	// Param[in]: name			          The input name string.
	// Param[in]: pValue			      Set attribute value.
	// Param[in]: bCloneValue			  Whether to clone the value.
	// Return:	void
	// Remarks:	 Set attribute value.
	// Notes: 
	//************************************
	static void SetAttr(FPD_StructElement element, FS_LPCSTR owner, FS_LPCSTR name, FPD_Object pValue, FS_BOOLEAN bCloneValue);

	//************************************
	// Function:  GetNS
	// Param[in]: element			      The input FPD_StructElement.	
	// Return:	FPD_StructNamespace
	// Remarks:	 Get FPD_StructNamespace obj.
	// Notes: 
	//************************************
	static FPD_StructNamespace GetNS(FPD_StructElement element);

	//************************************
	// Function:  SetNS
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[in]: pNS			          The input FPD_StructNamespace obj.
	// Return:	void
	// Remarks:	 Set the structure element namespace.
	// Notes: 
	//************************************
	static void SetNS(FPD_StructElement element, FPD_StructNamespace pNS);
	
	//************************************
	// Function:  GetMappedRoleAndNS
	// Param[in]: element			      The input FPD_StructElement.	
	// Param[in/out]: pNSResult			  Get the FPD_StructNamespace obj.
	// Param[in]: bChainMap			      If chain map.
	// Param[in/out]: outName			  Get the element name.
	// Return:	void
	// Remarks:	 Get the structure element namespace after mapping.
	// Notes: 
	//************************************
	static void GetMappedRoleAndNS(FPD_StructElement element, FPD_StructNamespace* pNSResult, FS_BOOLEAN bChainMap, FS_ByteString* outName);
};


class CFPD_StructTreeEntity_V16
{
public:
	//************************************
	// Function:  AsStructElem
	// Param[in]: entity			      The input FPD_StructTreeEntity.
	// Return:	FPD_StructElement         Get FPD_StructElement object.
	// Remarks:	 Get FPD_StructElement object.
	// Notes: 
	//************************************
	static FPD_StructElement  AsStructElem(FPD_StructTreeEntity entity);

	//************************************
	// Function:  GetPage
	// Param[in]: entity			      The input FPD_StructTreeEntity.
	// Return:	FPD_Object                Get the page dictionary.
	// Remarks:	 Get the page dictionary.
	// Notes: 
	//************************************
	static FPD_Object GetPage(FPD_StructTreeEntity entity);

	//************************************
	// Function:  GetType
	// Param[in]: entity			      The input FPD_StructTreeEntity.
	// Return:	FPD_Object                Get the type of FPD_StructTreeEntity.
	// Remarks:	 Get the type of FPD_StructTreeEntity.
	// Notes: 
	//************************************
	static FPD_EntityType GetType(FPD_StructTreeEntity entity);

	//************************************
	// Function:  AsMCR
	// Param[in]: entity			      The input FPD_StructTreeEntity.
	// Return:	FPD_MarkContentReference  Get the MarkContentReference.
	// Remarks:	 Get the MarkContentReference.
	// Notes: 
	//************************************
	static FPD_MarkContentReference AsMCR(FPD_StructTreeEntity entity);
	
	//************************************
	// Function:  AsOBJR
	// Param[in]: entity			      The input FPD_StructTreeEntity.
	// Return:	FPD_ObjectReference       Get the ObjectReference.
	// Remarks:	 Get the ObjectReference.
	// Notes: 
	//************************************
	static FPD_ObjectReference AsOBJR(FPD_StructTreeEntity entity);
	
	//************************************
	// Function:  GetObjectF
	// Param[in]: entity			      The input FPD_StructTreeEntity.
	// Return:	FPD_Object                Get the object of FPD_StructTreeEntity.
	// Remarks:	 Get the object of FPD_StructTreeEntity.
	// Notes: 
	//************************************
	static FPD_Object GetObjectF(FPD_StructTreeEntity entity);

	//************************************
	// Function:  CastFromStructElement
	// Param[in]: element			      The input FPD_StructElement.	
	// Return:	FPD_StructTreeEntity
	// Remarks:	 Get parent object of FPD_StructTreeEntity.
	// Notes: 
	//************************************
	static FPD_StructTreeEntity CastFromStructElement(FPD_StructElement element);

	//************************************
	// Function:  CastFromMarkContent
	// Param[in]: markcontentRef			      The input FPD_MarkContentReference.	
	// Return:	FPD_StructTreeEntity
	// Remarks:	 Get parent object of FPD_StructTreeEntity.
	// Notes: 
	//************************************
	static FPD_StructTreeEntity CastFromMarkContent(FPD_MarkContentReference markcontentRef);

	//************************************
	// Function:  CastFromObjectRef
	// Param[in]: objectRef			      The input FPD_ObjectReference.	
	// Return:	FPD_StructTreeEntity
	// Remarks:	 Get parent object of FPD_StructTreeEntity.
	// Notes: 
	//************************************
	static FPD_StructTreeEntity CastFromObjectRef(FPD_ObjectReference objectRef);

	//************************************
	// Function:  GetParent
	// Param[in]: entity		      The input FPD_StructTreeEntity.	
	// Return:	FPD_StructElement     Get parent of the FPD_MarkContentReference.
	// Remarks:	 Get parent of the FPD_MarkContentReference;
	// Notes: 
	//************************************
	static FPD_StructElement GetParent(FPD_StructTreeEntity entity);

	//************************************
	// Function:  GetTree
	// Param[in]: entity		      The input FPD_StructTreeEntity.	
	// Return:	FPD_StructTree        Get the struct tree.
	// Remarks:	 Get the struct tree.
	// Notes: 
	//************************************
	static FPD_StructTree GetTree(FPD_StructTreeEntity entity);

	//************************************
	// Function:  CastToStructElement
	// Param[in]: entity		      The input FPD_StructTreeEntity.	
	// Return:	FPD_StructElement     Cast to FPD_StructElement.
	// Remarks:	 Cast to FPD_StructElement.
	// Notes: 
	//************************************
	static FPD_StructElement CastToStructElement(FPD_StructTreeEntity entity);

	//************************************
	// Function:  SetPage
	// Param[in]: entity		      The input FPD_StructTreeEntity.	
	// Param[in]: pPage		          The input page dictionary.
	// Return:	FS_BOOLEAN     true if success, otherwise return false.
	// Remarks:	Set the page dictionary when the annotation is moved to another page.
	// Notes: 
	//************************************
	static FS_BOOLEAN SetPage(FPD_StructTreeEntity entity, FPD_Object pPage);
};


class CFPD_MarkContentReference_V16
{
public:	
	//************************************
	// Function:  GetType
	// Param[in]: contentRef		  The input FPD_MarkContentReference.	
	// Return:	FPD_EntityType   Get the entity type of the FPD_MarkContentReference.
	// Remarks:	 Get object.
	// Notes: 
	//************************************
	static FPD_EntityType	GetType(FPD_MarkContentReference contentRef);

	//************************************
	// Function:  GetContentStream
	// Param[in]: contentRef		  The input FPD_MarkContentReference.	
	// Return:	FPD_Object           Get the content stream.
	// Remarks:	  Get the content stream.
	// Notes: 
	//************************************
	static FPD_Object 	GetContentStream(FPD_MarkContentReference contentRef);

	//************************************
	// Function:  GetOwner
	// Param[in]: contentRef		  The input FPD_MarkContentReference.	
	// Return:	FPD_Object             Get the owner object.
	// Remarks:	 Get the owner object.
	// Notes: 
	//************************************
	static FPD_Object 	GetOwner(FPD_MarkContentReference contentRef);

	//************************************
	// Function:  GetMCID
	// Param[in]: contentRef		  The input FPD_MarkContentReference.	
	// Return:	FS_DWORD              Get MCID of the FPD_MarkContentReference.
	// Remarks:	 Get MCID of the FPD_MarkContentReference.
	// Notes: 
	//************************************
	static FS_DWORD		GetMCID(FPD_MarkContentReference contentRef);
};

class CFPD_ObjectReference_V16
{
public:
	//************************************
	// Function:  GetType
	// Param[in]: objRef		  The input FPD_ObjectReference.	
	// Return:	FPD_EntityType    Get entity type of the FPD_ObjectReference.
	// Remarks:	 Get entity type of the FPD_ObjectReference.
	// Notes: 
	//************************************
	static FPD_EntityType	GetType(FPD_ObjectReference objRef);

	//************************************
	// Function:  GetTarget
	// Param[in]: objRef		  The input FPD_ObjectReference.	
	// Return:	FPD_Object        Get the target of the FPD_ObjectReference.
	// Remarks:	 Get the target of the FPD_ObjectReference.
	// Notes: 
	//************************************
	static FPD_Object 	    GetTarget(FPD_ObjectReference objRef);

	//************************************
	// Function:  GetTargetType
	// Param[in]: objRef		  The input FPD_ObjectReference.	
	// Return:	FPD_ObjectType    Get the target type of the FPD_ObjectReference.
	// Remarks:	 Get the target type of the FPD_ObjectReference.
	// Notes: 
	//************************************
	static FPD_ObjectType	GetTargetType(FPD_ObjectReference objRef);

	//************************************
	// Function:  GetTargetImageDict
	// Param[in]: objRef		  The input FPD_ObjectReference.	
	// Return:	FPD_Object        Get the target image dictionary of the FPD_ObjectReference.
	// Remarks:	 Get the target image dictionary of the FPD_ObjectReference.
	// Notes: 
	//************************************
	static FPD_Object GetTargetImageDict(FPD_ObjectReference objRef);

	//************************************
	// Function:  GetTargetFormDict
	// Param[in]: objRef		  The input FPD_ObjectReference.	
	// Return:	FPD_Object        Get the target form dictionary of the FPD_ObjectReference.
	// Remarks:	 Get the target form dictionary of the FPD_ObjectReference.
	// Notes: 
	//************************************
	static FPD_Object 	GetTargetFormDict(FPD_ObjectReference objRef);

	//************************************
	// Function:  GetTargetAnnotDict
	// Param[in]: objRef		  The input FPD_ObjectReference.	
	// Return:	FPD_Object        Get the target annot dictionary of the FPD_ObjectReference.
	// Remarks:	 Get the target annot dictionary of the FPD_ObjectReference.
	// Notes: 
	//************************************
	static FPD_Object 	GetTargetAnnotDict(FPD_ObjectReference objRef);
};

class CFPD_MarkInfo_V16
{
public:
	//************************************
	// Function:  CreateMarkInfo
	// Param[in]: doc		  The input FPD_Document.	
	// Return:	FPD_MarkInfo  Create FPD_MarkInfo object.
	// Remarks:	 Create FPD_MarkInfo object.
	// Notes: 
	//************************************
	static FPD_MarkInfo CreateMarkInfo(FPD_Document doc);

	//************************************
	// Function:  DeleteMarkInfo
	// Param[in]: info		  The input FPD_MarkInfo.	
	// Return:	void
	// Remarks:	 Delete FPD_MarkInfo object.
	// Notes: 
	//************************************
	static void DeleteMarkInfo(FPD_MarkInfo info);

	//************************************
	// Function:  GetMarked
	// Param[in]: info		  The input FPD_MarkInfo.	
	// Return:	FS_BOOLEAN    Get the marked flag.
	// Remarks:	 Get the flag indicating whether the document conforms to Tagged PDF conventions.
	// Notes: Default is false.
	//************************************
	static FS_BOOLEAN		GetMarked(FPD_MarkInfo info);

	//************************************
	// Function:  GetUserProperties
	// Param[in]: info		  The input FPD_MarkInfo.	
	// Return:	FS_BOOLEAN    Get if contain user properties.
	// Remarks:	 Get the flag indicating the presence of structure elements that
	// contain user properties attributes.
	// Notes: Default is false.
	//************************************
	static FS_BOOLEAN		GetUserProperties(FPD_MarkInfo info);

	//************************************
	// Function:  GetSuspects
	// Param[in]: info		  The input FPD_MarkInfo.	
	// Return:	FS_BOOLEAN    Get the tag suspects flag.
	// Remarks:	 Get the flag indicating the presence of tag suspects.
	// Notes: 
	//************************************
	static FS_BOOLEAN		GetSuspects(FPD_MarkInfo info);

	//************************************
	// Function:  SetMarked
	// Param[in]: info		  The input FPD_MarkInfo.	
	// Param[in]: bMarked	  Set the mark flag.	
	// Return:	void    
	// Remarks:	 Set the flag indicating whether the document conforms to Tagged PDF conventions.
	// Notes: Defalut is false.
	//************************************
	static void		SetMarked(FPD_MarkInfo info, FS_BOOLEAN bMarked);

	//************************************
	// Function:  SetUserProperties
	// Param[in]: info		          The input FPD_MarkInfo.	
	// Param[in]: bUserProperties	  Set the user properties flag.	
	// Return:	void    
	// Remarks:	 Set the flag indicating the presence of structure elements that
	// contain user properties attributes.
	// Notes: 
	//************************************
	static void		SetUserProperties(FPD_MarkInfo info, FS_BOOLEAN bUserProperties);

	//************************************
	// Function:  SetSuspects
	// Param[in]: info		          The input FPD_MarkInfo.	
	// Param[in]: bSuspect      	  Set the tag suspect flag.	
	// Return:	void    
	// Remarks:	 Set the flag indicating the presence of tag suspects.		
	// Notes: 
	//************************************
	static void		SetSuspects(FPD_MarkInfo info, FS_BOOLEAN bSuspect);
};

class CFPD_PageTemplate_V16
{
public:
	//************************************
	// Function:  CreatePageTemplate
	// Param[in]: pDoc		          The input FPD_Document.	
	// Return:	FPD_PageTemplate    
	// Remarks:	 Construct a page template organizer.		
	// Notes: 
	//************************************
	static FPD_PageTemplate CreatePageTemplate(FPD_Document pDoc);
	
	//************************************
	// Function:  DestroyFPDPageTemplate
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Return:	void    
	// Remarks:	 Destroy a page template organizer.		
	// Notes: 
	//************************************
	static void DestroyFPDPageTemplate(FPD_PageTemplate pageTemplate);

	//************************************
	// Function:  LoadTemplateDatas
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Return:	FS_BOOLEAN                    true means load template success.
	// Remarks:	 Load page template dates.		
	// Notes: 
	//************************************
	static FS_BOOLEAN LoadTemplateDatas(FPD_PageTemplate pageTemplate);

	//************************************
	// Function:  GetTemplateCount
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Param[in]: bVisible		              Whether the template visible.
	// Return:	FS_INT32                      Get the template count by specified visual.
	// Remarks:	  Get the template count by specified visual.
	// Notes: 
	//************************************
	static FS_INT32 GetTemplateCount(FPD_PageTemplate pageTemplate, FS_BOOLEAN bVisible);

	//************************************
	// Function:  GetTemplateName
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Param[in]: bVisible		              Whether the template visible.
	// Param[out]: cwName		              Get the template names.
	// Return:	FS_BOOLEAN                    true means get the template success.
	// Remarks:	 Get the template names by specified visual.
	// Notes: 
	//************************************
	static FS_BOOLEAN  GetTemplateName(FPD_PageTemplate pageTemplate, FS_BOOLEAN bVisible, FS_WideStringArray* cwName);

	//************************************
	// Function:  AddTemplate
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Param[in]: nPageIndex		          The input page index.
	// Param[int]: cwName		              The input template name.
	// Return:	FS_BOOLEAN                    Add the template success.
	// Remarks:	 Add the template by page index and template name.
	// Notes: 
	//************************************
	static FS_BOOLEAN AddTemplate(FPD_PageTemplate pageTemplate, FS_INT32 nPageIndex, FS_LPCWSTR cwName);

	//************************************
	// Function:  CheckExistForTempName
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Param[in]: cwTempName		          The input template name.
	// Return:	FS_BOOLEAN                    true the specified template is exist.
	// Remarks:	 Check the template is exist by specified template name.
	// Notes: 
	//************************************
	static FS_BOOLEAN CheckExistForTempName(FPD_PageTemplate pageTemplate, FS_LPCWSTR cwTempName);

	//************************************
	// Function:  CheckExistForDict
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Param[in]: pDict						  The input template dictionary.
	// Return:	FS_BOOLEAN                    true the specified template is exist.
	// Remarks:	 Check the template is exist by specified template dictionary.
	// Notes: 
	//************************************
	static FS_BOOLEAN CheckExistForDict(FPD_PageTemplate pageTemplate, FPD_Object pDict);

	//************************************
	// Function:  RenameTemplate
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Param[in]: cwOldName					  The old template name.
	// Param[in]: cwNewName					  The new template name.
	// Return:	FS_BOOLEAN                    true rename the specified template success.
	// Remarks:	 Rename the template by new name.
	// Notes: 
	//************************************
	static FS_BOOLEAN RenameTemplate(FPD_PageTemplate pageTemplate, FS_LPCWSTR cwOldName, FS_LPCWSTR cwNewName);

	//************************************
	// Function:  DeleteTemplate
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Param[in]: cwName					  The input template name.
	// Return:	FS_BOOLEAN                    true delete e the specified template success.
	// Remarks:	 Delete the template by specified name.
	// Notes: 
	//************************************
	static FS_BOOLEAN DeleteTemplate(FPD_PageTemplate pageTemplate, FS_LPCWSTR cwName);

	//************************************
	// Function:  GetTemplateVisible
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Param[in]: cwName					  The input template name.
	// Return:	FS_BOOLEAN                    true the specified template is visible.
	// Remarks:	 Get the visual state of the specified template.
	// Notes: 
	//************************************
	static FS_BOOLEAN GetTemplateVisible(FPD_PageTemplate pageTemplate, FS_LPCWSTR cwName);

	//************************************
	// Function:  SetTemplateVisible
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Param[in]: cwName					  The input template name.
	// Param[in]: bVisible					  The input visual state.
	// Return:	FS_BOOLEAN                    true set the visual state of specified template success.
	// Remarks:	 Set the visual state of the specified template.
	// Notes: 
	//************************************
	static FS_BOOLEAN SetTemplateVisible(FPD_PageTemplate pageTemplate, FS_LPCWSTR cwName, FS_BOOLEAN bVisible);
	
	//************************************
	// Function:  GetPageIndex
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Param[in]: cwName					  The input template name.
	// Return:	FS_INT32                      Get the page index of the template by specifed name.
	// Remarks:	 Get the page index of the template by specifed name.
	// Notes: 
	//************************************
	static FS_INT32 GetPageIndex(FPD_PageTemplate pageTemplate, FS_LPCWSTR cwName);

	//************************************
	// Function:  GetTemplateObject
	// Param[in]: pageTemplate		          The input FPD_PageTemplate.	
	// Param[in]: cwName					  The input template name.
	// Return:	FPD_Object                    Get the dictionary of the template by specifed name.
	// Remarks:	 Get the dictionary of the template by specifed name.
	// Notes: 
	//************************************
	static FPD_Object GetTemplateObject(FPD_PageTemplate pageTemplate, FS_LPCWSTR cwName);
};

class CFPD_EmbedFontSubset_V16
{
public:	
	//************************************
	// Function:  Create
	// Param[in]: pDoc		          The input FPD_Document.	
	// Return:	FPD_EmbedFontSubset   The embed font subset handler.
	// Remarks: Construct an embed font subset handler.
	// Notes: 
	//************************************
	static FPD_EmbedFontSubset Create(FPD_Document pDoc);

	//************************************
	// Function:  Delete
	// Param[in]: fontSubset		          The input FPD_EmbedFontSubset.	
	// Return:	void   
	// Remarks: Delete FPD_EmbedFontSubset.
	// Notes: 
	//************************************
	static void Delete(FPD_EmbedFontSubset fontSubset);
	
	 //************************************
	 // Function:  Start	 
	 // Param[in]: fontSubset		          The input FPD_EmbedFontSubset.
	 // Param[in]: option		              The option of the embed font subset.
	 // Return:	FPD_ProgressiveStatus         Ready means success, otherwise not.
	 // Remarks: Start the embed font subsetting progress.
	 // Notes: 
	 //************************************
	static FPD_ProgressiveStatus Start(FPD_EmbedFontSubset fontSubset, FS_INT32 option);
	
	 //************************************
	 // Function:  Continue
	 // Param[in]: fontSubset		          The input FPD_EmbedFontSubset.
	 // Param[in]: pPause		              The pause interface.
	 // Return:	FPD_ProgressiveStatus         Done if finish.
	 // Remarks: Continue embed font subsetting.
	 // Notes: 
	 //************************************
	static FPD_ProgressiveStatus Continue(FPD_EmbedFontSubset fontSubset, FS_PauseHandler pPause);
};


class CFPD_Engine_V16 // Internal use.
{
public:	
	static FPD_EngineNotify CreateNofify(FPD_EngineNoifyCallBack callback);
	static void ReleaseNofify(FPD_EngineNotify notify);	
	static FPD_Engine GetEngine(FPD_EngineType engineType, FPD_EngineNotify notify);
	static FS_BOOLEAN SetDeriver(FPD_Engine engine, const FS_LPCWSTR deriverpath);		
	static void Clear(FPD_Engine engine);
	static void GetX509Cert(FPD_Engine engine, const FPD_EngineTokenINFO info, FS_PtrArray* outlist);
	static FS_INT32 GetTokenInfoSize(FPD_Engine engine);
	static FS_BOOLEAN GetTokenInfoByIndex(FPD_Engine engine, FS_INT32 index, FPD_EngineTokenINFO* outInfo);
	static FS_BOOLEAN GetlibInfo(FPD_Engine engine, FPD_EngineLIBINFO* info);
	static FS_BOOLEAN Login(FPD_Engine engine, FS_LPVOID  pToken, FS_ByteString* password);
	static FS_BOOLEAN Logout(FPD_Engine engine, FS_LPVOID pToken);
	static void ReleaseCert(FPD_Engine engine, FS_LPVOID pcert);
};

class CFPD_FlattenOptions_V16
{
public:
	//************************************
	// Function:  Create
	// Return:	FPD_FlattenOptions        
	// Remarks: Create FPD_FlattenOptions.
	// Notes: 
	//************************************
	static FPD_FlattenOptions Create();

	//************************************
	// Function:  Delete
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	void        
	// Remarks: Delete FPD_FlattenOptions.
	// Notes: 
	//************************************
	static void Delete(FPD_FlattenOptions options);

	//************************************
	// Function:  GetRasterVectorBalance
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FS_FLOAT        
	// Remarks: Get Raster/Vector balance.
	// Notes: It specifies the amount of vector information that will be preserved.
	// Higher settings preserve more vector objects, while lower settings rasterize more vector
	// objects; intermediate settings preserve simple areas in vector form and rasterize complex
	// ones.Select the lowest setting to rasterize all the artwork.domain: [0.0f, 100.0f].
	//************************************
	static FS_FLOAT GetRasterVectorBalance(FPD_FlattenOptions options);

	//************************************
	// Function:  SetRasterVectorBalance
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: balance		          The input Raster/Vector balance.
	// Return:	void        
	// Remarks: Set Raster/Vector balance.
	// Notes: It specifies the amount of vector information that will be preserved.
	// Higher settings preserve more vector objects, while lower settings rasterize more vector
	// objects; intermediate settings preserve simple areas in vector form and rasterize complex
	// ones.Select the lowest setting to rasterize all the artwork.domain: [0.0f, 100.0f].
	//************************************
	static void SetRasterVectorBalance(FPD_FlattenOptions options, FS_FLOAT balance);

	//************************************
	// Function:  GetLineArtAndTextResolution
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FS_FLOAT        
	// Remarks: Get Line Art And Text Resolution.
	// Notes: It Rasterizes all objects, including images, vector artwork, text, and gradients, to the
	// specified resolution.Acrobat and InDesign allow a maximum of 9600 pixels per inch(ppi) for
	// line art, and 1200 ppi for gradient mesh.Illustrator allows a maximum of 9600 ppi for both
	// line art and gradient mesh.The resolution affects the precision of intersections when
	// flattened.Line Art and Text Resolution should generally be set to 600 - 1200 to provide
	// high - quality rasterization, especially on serif or small point sized type.
	//************************************
	static FS_FLOAT GetLineArtAndTextResolution(FPD_FlattenOptions options);

	//************************************
	// Function:  SetLineArtAndTextResolution
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: resolution		      The input Line Art And Text Resolution.
	// Return:	void        
	// Remarks: Set Line Art And Text Resolution.
	// Notes: It Rasterizes all objects, including images, vector artwork, text, and gradients, to the
	// specified resolution.Acrobat and InDesign allow a maximum of 9600 pixels per inch(ppi) for
	// line art, and 1200 ppi for gradient mesh.Illustrator allows a maximum of 9600 ppi for both
	// line art and gradient mesh.The resolution affects the precision of intersections when
	// flattened.Line Art and Text Resolution should generally be set to 600 - 1200 to provide
	// high - quality rasterization, especially on serif or small point sized type.
	//************************************
	static void SetLineArtAndTextResolution(FPD_FlattenOptions options, FS_FLOAT resolution);

	//************************************
	// Function:  GetGradientAndMeshResolution
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FS_FLOAT        
	// Remarks: Set Gradient And Mesh Resolution.
	// Notes: It Specifies the resolution for gradients and Illustrator mesh objects rasterized as a result of
	// flattening, from 72 to 2400 ppi.The resolution affects the precision of intersections when
	// flattened.Gradient and mesh resolution should generally be set between 150 and 300 ppi,
	// because the quality of the gradients, drop shadows, and feathers do not improve with higher
	// resolutions, but printing time and file size increase.
	//************************************
	static FS_FLOAT GetGradientAndMeshResolution(FPD_FlattenOptions options);

	//************************************
	// Function:  SetGradientAndMeshResolution
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: resolution		      The input Gradient And Mesh Resolution.
	// Return:	void        
	// Remarks: Set Gradient And Mesh Resolution.
	// Notes: It specifies the resolution for gradients and Illustrator mesh objects rasterized as a result of
	// flattening, from 72 to 2400 ppi.The resolution affects the precision of intersections when
	// flattened.Gradient and mesh resolution should generally be set between 150 and 300 ppi,
	// because the quality of the gradients, drop shadows, and feathers do not improve with higher
	// resolutions, but printing time and file size increase.
	//************************************
	static void SetGradientAndMeshResolution(FPD_FlattenOptions options, FS_FLOAT resolution);

	//************************************
	// Function:  GetIsConvertTextToOutline
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FS_BOOLEAN        
	// Remarks: Get All Text To Outlines.
	// Notes: It specifies Converts all type objects (point type, area type, and path type) to outlines
	// and discards all type glyph information on pages containing transparency.
	// This option ensures that the width of text stays consistent during flattening.
	// Note that enabling this option will cause small fonts to appear slightly thicker
	// when viewed in Acrobat or printed on low - resolution desktop printers.
	// It doesn't affect the quality of the type printed on high-resolution printers or
	// imagesetters.
	//************************************
	static FS_BOOLEAN GetIsConvertTextToOutline(FPD_FlattenOptions options);

	//************************************
	// Function:  SetIsConvertTextToOutline
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: bConvert		          Whether need to convert to set all text to outlines.
	// Return:	void        
	// Remarks: Set All Text To Outlines.
	// Notes: It specifies Converts all type objects (point type, area type, and path type) to outlines
	// and discards all type glyph information on pages containing transparency.
	// This option ensures that the width of text stays consistent during flattening.
	// Note that enabling this option will cause small fonts to appear slightly thicker
	// when viewed in Acrobat or printed on low - resolution desktop printers.
	// It doesn't affect the quality of the type printed on high-resolution printers or
	// imagesetters.
	//************************************
	static void SetIsConvertTextToOutline(FPD_FlattenOptions options, FS_BOOLEAN bConvert);

	//************************************
	// Function:  GetIsConvertStrokeToOutline
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FS_BOOLEAN        
	// Remarks: Get All Strokes To Outlines.
	// Notes: It specifies Converts all strokes to simple filled paths on pages containing transparency.
	// This option ensures that the width of strokes stays consistent during flattening.
	// Note that enabling this option causes thin strokes to appear slightly thicker and may degrade
	// flattening performance.
	//************************************
	static FS_BOOLEAN GetIsConvertStrokeToOutline(FPD_FlattenOptions options);

	//************************************
	// Function:  SetIsConvertStrokeToOutline
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: bConvert		          Whether need to convert all strokes To outlines.
	// Return:	void        
	// Remarks: Set All Strokes To Outlines.
	// Notes: It specifies Converts all strokes to simple filled paths on pages containing transparency.
	// This option ensures that the width of strokes stays consistent during flattening.
	// Note that enabling this option causes thin strokes to appear slightly thicker and may degrade
	// flattening performance.
	//************************************
	static void SetIsConvertStrokeToOutline(FPD_FlattenOptions options, FS_BOOLEAN bConvert);

	//************************************
	// Function:  GetIsClipComplexRegions
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FS_BOOLEAN        
	// Remarks: Get Clip Complex Regions.
	// Notes: It specifies esures that the boundaries between vector artwork and rasterized artwork fall along object
	// paths.This option reduces stitching artifacts that result when part of an object is
	// rasterized while another part of the object remains in vector form.However, selecting this
	// option may result in paths that are too complex for the printer to handle.
	//************************************
	static FS_BOOLEAN GetIsClipComplexRegions(FPD_FlattenOptions options);

	//************************************
	// Function:  SetIsClipComplexRegions
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: bClip		              The input clip complex regions.
	// Return:	void        
	// Remarks: Set Clip Complex Regions.
	// Notes: It specifies esures that the boundaries between vector artwork and rasterized artwork fall along object
	// paths.This option reduces stitching artifacts that result when part of an object is
	// rasterized while another part of the object remains in vector form.However, selecting this
	// option may result in paths that are too complex for the printer to handle.
	//************************************
	static void SetIsClipComplexRegions(FPD_FlattenOptions options, FS_BOOLEAN bClip);

	//************************************
	// Function:  GetIsPreserveOverprint
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FS_BOOLEAN        
	// Remarks: Set Preserve Overprint.
	// Notes: It specifies Blends the color of transparent artwork with the background color to create an overprint
	// effect.
	//************************************
	static FS_BOOLEAN GetIsPreserveOverprint(FPD_FlattenOptions options);

	//************************************
	// Function:  SetIsPreserveOverprint
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: bPreserve		          The input  Preserve Overprint.
	// Return:	void        
	// Remarks: Set Preserve Overprint.
	// Notes: It specifies Blends the color of transparent artwork with the background color to create an overprint
	// effect.
	//************************************
	static void SetIsPreserveOverprint(FPD_FlattenOptions options, FS_BOOLEAN bPreserve);

	//************************************
	// Function:  GetIccProfile
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[out]: wsIcc		          Get the Page-Level Transparency Blending Color Space.
	// Return:	void        
	// Remarks: Get the Page-Level Transparency Blending Color Space.
	// Notes: 
	//************************************
	static void GetIccProfile(FPD_FlattenOptions options, FS_WideString* wsIcc);

	//************************************
	// Function:  SetIccProfile
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: wsIcc		              The Page-Level Transparency Blending Color Space.
	// Return:	void        
	// Remarks: Set the Page-Level Transparency Blending Color Space.
	// Notes: 
	//************************************
	static void SetIccProfile(FPD_FlattenOptions options, FS_WideString wsIcc);

	//************************************
	// Function:  GetMonochrome
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FPD_FlattenCompression        
	// Remarks: Get the monochraome compression.
	// Notes: 
	//************************************
	static FPD_FlattenCompression GetMonochrome(FPD_FlattenOptions options);

	//************************************
	// Function:  SetMonochrome
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: compression		      The input monochraome compression.
	// Return:	void        
	// Remarks: Set the monochraome compression.
	// Notes: 
	//************************************
	static void SetMonochrome(FPD_FlattenOptions options, FPD_FlattenCompression compression);

	//************************************
	// Function:  GetGrayscale
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FPD_FlattenCompression        
	// Remarks: Get the gray scale compression.
	// Notes: 
	//************************************
	static FPD_FlattenCompression GetGrayscale(FPD_FlattenOptions options);

	//************************************
	// Function:  SetGrayscale
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: compression		      The input gray scale compression.
	// Return:	void        
	// Remarks: Set the gray scale compression.
	// Notes: 
	//************************************
	static void SetGrayscale(FPD_FlattenOptions options, FPD_FlattenCompression compression);

	//************************************
	// Function:  GetColor
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FPD_FlattenCompression        
	// Remarks: Get the color compression.
	// Notes: 
	//************************************
	static FPD_FlattenCompression GetColor(FPD_FlattenOptions options);

	//************************************
	// Function:  GetColor
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: compression		      The input color compression.
	// Return:	FPD_FlattenCompression        
	// Remarks: Set the color compression.
	// Notes: 
	//************************************
	static void SetColor(FPD_FlattenOptions options, FPD_FlattenCompression compression);

	//************************************
	// Function:  GetQuality
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FPD_FlattenQuality        
	// Remarks: Get the quality.
	// Notes: 
	//************************************
	static FPD_FlattenQuality GetQuality(FPD_FlattenOptions options);

	//************************************
	// Function:  SetQuality
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: compression		      The input quality.
	// Return:	void        
	// Remarks: Set the quality.
	// Notes: 
	//************************************
	static void SetQuality(FPD_FlattenOptions options, FPD_FlattenQuality compression);

	//************************************
	// Function:  GetDPI
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FS_FLOAT        
	// Remarks: Get the dpi.
	// Notes: 
	//************************************
	static FS_FLOAT GetDPI(FPD_FlattenOptions options);

	//************************************
	// Function:  SetDPI
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: dpi		              The input dpi.
	// Return:	void        
	// Remarks: Set the dpi.
	// Notes: 
	//************************************
	static void SetDPI(FPD_FlattenOptions options, FS_FLOAT dpi);

	//************************************
	// Function:  GetBackColor
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FS_COLORREF        
	// Remarks: Get the background color for gray mode (default: white).
	// Notes: 
	//************************************
	static FS_COLORREF GetBackColor(FPD_FlattenOptions options);

	//************************************
	// Function:  SetBackColor
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: color		              The input background color.
	// Return:	FS_COLORREF        
	// Remarks: Set the background color for gray mode (default: white).
	// Notes: 
	//************************************
	static void SetBackColor(FPD_FlattenOptions options, FS_COLORREF color);

	//************************************
	// Function:  GetRenderFlags
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Return:	FS_DWORD        
	// Remarks: Get the Render flags.
	// Notes: 
	//************************************
	static FS_DWORD GetRenderFlags(FPD_FlattenOptions options);

	//************************************
	// Function:  SetRenderFlags
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: flag		              The input Render flags.
	// Return:	void        
	// Remarks: Set the Render flags.
	// Notes: 
	//************************************
	static void SetRenderFlags(FPD_FlattenOptions options, FS_DWORD flag);

	//************************************
	// Function:  SetOCContext
	// Param[in]: options		          The input FPD_FlattenOptions.
	// Param[in]: hander		          The input Optional content context interface.
	// Return:	void        
	// Remarks: Set the Optional content context interface.
	// Notes: 
	//************************************
	static void SetOCContext(FPD_FlattenOptions options, FPD_OCContextHandler hander);
};

class CFPD_OCSPCache_V16
{
public:
	static void DisableAutoCache(FS_BOOLEAN bEnable);
	static void DiscardExpiredCache();
	static void ClearAllCache();
};

class CFPD_TimeStampServerNotify_V16
{
public:
	static FPD_TimeStampServerNotify Create(FPD_TimeStampServerNotifyCallbacks callback);
	static void Destroy(FPD_TimeStampServerNotify notify);
};

class CFPD_DateTime_V17
{
public:
	//************************************
	// Function:  Create	
	// Return:	FPD_DateTime        
	// Remarks: Create FPD_DateTime object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_DateTime Create();

	//************************************
	// Function:  Create2
	// Param[in]: pdfDateTimeStr		  The input datetime str.
	// Return:	FPD_DateTime        
	// Remarks: Create FPD_DateTime object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_DateTime Create2(FS_LPCSTR pdfDateTimeStr);

	//************************************
	// Function:  Create3
	// Param[in]: pdfDateTimeStr		  The input FPDCRT_DATETIMEZONE object.
	// Return:	FPD_DateTime        
	// Remarks: Create FPD_DateTime object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_DateTime Create3(FPDCRT_DATETIMEZONE st);

	//************************************
	// Function:  Destroy
	// Param[in]: dateTime		          The input FPD_DateTime object.
	// Return:	void        
	// Remarks: Destroy FPD_DateTime object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void Destroy(FPD_DateTime dateTime);

	//************************************
	// Function:  ParserPDFDateTimeString
	// Param[in]: dateTime		          The input FPD_DateTime object.
	// Param[in]: dtStr		              The input pdf datetime str.
	// Return:	FS_BOOLEAN        
	// Remarks: Parser pdf datetime str.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN	ParserPDFDateTimeString(FPD_DateTime dateTime, FS_LPCSTR dtStr);

	//************************************
	// Function:  ParserPDFXMPDateTimeString
	// Param[in]: dateTime		          The input FPD_DateTime object.
	// Param[in]: dtStr		              The input pdf xmp datetime str.
	// Return:	FS_BOOLEAN        
	// Remarks: Parser pdf xmp datetime str.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN	ParserPDFXMPDateTimeString(FPD_DateTime dateTime, FS_LPCWSTR dtStr);

	//************************************
	// Function:  ToPDFDateTimeString
	// Param[in]: dateTime		          The input FPD_DateTime object.
	// Param[out]: bsDate		          Convert to pdf datetime str.
	// Return:	void        
	// Remarks: Convert to pdf datetime str.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void     	ToPDFDateTimeString(FPD_DateTime dateTime, FS_ByteString* bsDate);

	//************************************
	// Function:  ToXMPDateTimeString
	// Param[in]: dateTime		          The input FPD_DateTime object.
	// Param[out]: wsDate		          Convert to xmp datetime str.
	// Return:	void        
	// Remarks: Convert to pdf xmp datetime str.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void         ToXMPDateTimeString(FPD_DateTime dateTime, FS_WideString* wsDate);

	//************************************
	// Function:  SetCurrentSystemDateTime
	// Param[in]: dateTime		          The input FPD_DateTime object.
	// Return:	void        
	// Remarks: Set current system datetime.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void			SetCurrentSystemDateTime(FPD_DateTime dateTime);

	//************************************
	// Function:  GetCRTDateTimeZone
	// Param[in]: dateTime		          The input FPD_DateTime object.
	// Return:	FPDCRT_DATETIMEZONE        
	// Remarks: Get CRTDateTimeZone.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPDCRT_DATETIMEZONE   GetCRTDateTimeZone(FPD_DateTime dateTime);

	//************************************
	// Function:  GetCurrentSystemTime
	// Return:	FPDCRT_DATETIMEZONE        
	// Remarks: Get current system time.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPDCRT_DATETIMEZONE	GetCurrentSystemTime();
};

class CFPD_OrganizeParam_V17
{
public:
	//************************************
	// Function:  Create
	// Return:	FPD_OrganizeParam        
	// Remarks: Construct organize param.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_OrganizeParam Create();

	//************************************
	// Function:  Destroy
	// Param[in]: param		          The input FPD_OrganizeParam.
	// Return:	void        
	// Remarks: Destory a organizer.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void Destroy(FPD_OrganizeParam param);

	//************************************
	// Function:  GetInterForm
	// Param[in]: param		          The input FPD_OrganizeParam.
	// Return:	FPD_InterForm        
	// Remarks: Get interform obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_InterForm GetInterForm(FPD_OrganizeParam param);

	//************************************
	// Function:  SetInterForm
	// Param[in]: param		          The input FPD_OrganizeParam.
	// Param[in]: form		          The input interform obj.
	// Return:	void        
	// Remarks: Set interform obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void SetInterForm(FPD_OrganizeParam param, FPD_InterForm form);

	//************************************
	// Function:  GetStructTree
	// Param[in]: param		          The input FPD_OrganizeParam.	
	// Return:	FPD_StructTree        
	// Remarks: Set struct tree obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_StructTree GetStructTree(FPD_OrganizeParam param);

	//************************************
	// Function:  SetStructTree
	// Param[in]: param		          The input FPD_OrganizeParam.
	// Param[in]: structTree		  The input FPD_StructTree obj.
	// Return:	void        
	// Remarks: Set FPD_StructTree obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void SetStructTree(FPD_OrganizeParam param, FPD_StructTree structTree);

	//************************************
	// Function:  GetOtherInterForm
	// Param[in]: param		          The input FPD_OrganizeParam.
	// Return:	FPD_InterForm        
	// Remarks: Get other interform obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_InterForm GetOtherInterForm(FPD_OrganizeParam param);

	//************************************
	// Function:  SetOtherInterForm
	// Param[in]: param		          The input FPD_OrganizeParam.
	// Param[in]: form		          The input other interform obj.
	// Return:	void        
	// Remarks: Set other interform obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void SetOtherInterForm(FPD_OrganizeParam param, FPD_InterForm form);
};


class CFPD_Organizer_V17
{
public:	
	//************************************
	// Function:  Create
	// Param[in]: pDoc		          The input FPD_Document.
	// Return:	void        
	// Remarks: Construct a organizer.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_Organize Create(FPD_Document pDoc);

	//************************************
	// Function:  Destroy
	// Param[in]: organizer		          The input FPD_Organize.
	// Return:	void        
	// Remarks: Destory a organizer.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void Destroy(FPD_Organize organizer);

	//************************************
	// Function:  SetOrganizeParam
	// Param[in]: organizer		          The input FPD_Organize.
	// Param[in]: pParam		          The input FPD_OrganizeParam.
	// Return:	void        
	// Remarks: Set the parameters of organizer.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void	SetOrganizeParam(FPD_Organize organizer, FPD_OrganizeParam pParam);

	//************************************
	// Function:  InsertDocumentAtPos
	// Param[in]: organizer			The input FPD_Organize.
	// Param[in]: index				The page index where the document will be inserted.
	// Param[in]: insertedDoc		The inserted document.
	// Param[in]: option		    Options: e.g. FPDINSERT_OPTION_ATTACHMENTS or FPDINSERT_OPTION_BOOKMARK.
	// Param[in]: pBookmarkTitle	The input bookmark title. Set NULL as default.
	// Param[in]: pPageObjNums	    Page object numbers in the other document, those object numbers will be reused.
	// Return:    TRUE means success, otherwise failed.
	// Remarks:   Inserts the document into the original document at the specified position.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static FS_BOOLEAN InsertDocumentAtPos(FPD_Organize organizer, FS_INT32 index, FPD_Document insertedDoc, FS_INT32 option, const FS_WCHAR* pBookmarkTitle, const FS_DWordArray pPageObjNums);
};


class CFPD_FormExportHandler : public IPDF_FormExportHandler
{
public:
	CFPD_FormExportHandler(FPD_FormExportCallBacks callbacks);
	virtual ~CFPD_FormExportHandler();

	virtual void			Initialize(const CPDF_InterForm* pInterform);
	virtual IFX_FileRead*	RetrieveEmbeddedFile(CPDF_FormField *pField);
	virtual void			Finalize(const CPDF_InterForm* pInterform);

	FPD_FormExportCallBacksRec m_callbacks;
};

class CFPD_FormExportHandler_V17
{
public:
	static FPD_FormExportHandler Create(FPD_FormExportCallBacks callbacks);
	static void Delete(FPD_FormExportHandler handler);
};

class CFPD_EngineLIBINFO_V17
{
public:
	static FPD_EngineLIBINFO Create();
	static void Delete(FPD_EngineLIBINFO info);
	static void GetCrypVersion(FPD_EngineLIBINFO info, FS_ByteString* outVersion);
	static void SetCrypVersion(FPD_EngineLIBINFO info, FS_LPCSTR version);
	static void GetManuID(FPD_EngineLIBINFO info, FS_ByteString* outID);
	static void SetManuID(FPD_EngineLIBINFO info, FS_LPCSTR id);
	static void GetLibDes(FPD_EngineLIBINFO info, FS_ByteString* outDes);
	static void SetLibDes(FPD_EngineLIBINFO info, FS_LPCSTR des);
	static void GetLibVersion(FPD_EngineLIBINFO info, FS_ByteString* outVersion);
	static void SetLibVersion(FPD_EngineLIBINFO info, FS_LPCSTR version);
};

class CFPD_EngineTokenINFO_V17
{
public:
	static FPD_EngineTokenINFO Create();
	static void Delete(FPD_EngineTokenINFO info);
	static FS_LPVOID GetToken(FPD_EngineTokenINFO info);
	static void SetToken(FPD_EngineTokenINFO info, FS_LPVOID token);
	static void GetTokenLabel(FPD_EngineTokenINFO info, FS_ByteString* outTokenLabel);
	static void SetTokenLabel(FPD_EngineTokenINFO info, FS_LPCSTR tokenLabel);
	static void GetManuID(FPD_EngineTokenINFO info, FS_ByteString* outID);
	static void SetManuID(FPD_EngineTokenINFO info, FS_LPCSTR id);
	static void GetModel(FPD_EngineTokenINFO info, FS_ByteString* outModel);
	static void SetModel(FPD_EngineTokenINFO info, FS_LPCSTR model);
	static void GetSerialNumber(FPD_EngineTokenINFO info, FS_ByteString* outNumber);
	static void SetSerialNumber(FPD_EngineTokenINFO info, FS_LPCSTR serNumber);
};

class CFPD_Extracter_V17
{
public:
	//************************************
	// Function:  Create	
	// Return:	FPD_Extracter        
	// Remarks: Create FPD_Extracter obj.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	//************************************
	static FPD_Extracter Create();

	//************************************
	// Function:  LoadDocument
	// Param[in]: extracter			The input FPD_Extracter.
	// Param[in]: filename			The path name of the to be extract PDF file.
	// Param[in]: pPassword		    The password of the to be extract PDF file, if it is encrypted.
	// Return:   FPD_EXTRACT_STATE  The state of extracter, the value may be FPD_EXTRACT_*.
	// Remarks:   Add a PDF file into the merger.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	//************************************
	static FPD_EXTRACT_STATE LoadDocument(FPD_Extracter extracter, FS_LPCWSTR filename, const FS_LPWSTR pPassword);

	//************************************
	// Function:  LoadDocument2
	// Param[in]: extracter			The input FPD_Extracter.
	// Param[in]: pDoc			    The document of the to be extracted PDF file.
	// Return:   FPD_EXTRACT_STATE  The state of extracter, the value may be FPD_EXTRACT_*.
	// Remarks:   Add a PDF file into the merger.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	//************************************
	static FPD_EXTRACT_STATE LoadDocument2(FPD_Extracter extracter, FPD_Document pDoc);

	//************************************
	// Function:  Start
	// Param[in]: extracter			The input FPD_Extracter.
	// Param[in]: pFile			    The dest result PDF file.
	// Param[in]: pageIndex			The extract page number array.
	// Param[in]: option			The option of the extract.
	// Return:   Ready means success, otherwise not.
	// Remarks:  Start the extracting progress.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	//************************************
	static FS_ProgressiveStatus	 Start(FPD_Extracter extracter, FS_FileWriteHandler pFile, const FS_Int32Array pageIndex, FS_DWORD option);

	//************************************
	// Function:  Continue
	// Param[in]: extracter			The input FPD_Extracter.
	// Param[in]: pPause			The pause interface.
	// Return:   The status of PDF extracting.
	// Remarks: Continue merging.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0
	//************************************
	static FS_ProgressiveStatus	 Continue(FPD_Extracter extracter, FS_PauseHandler pPause);

	//************************************
	// Function:  Delete
	// Param[in]: extracter			The input FPD_Extracter.
	// Return:	void        
	// Remarks: Delete FPD_Extracter obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	//************************************
	static void Delete(FPD_Extracter extracter);
};

class CFPD_SSLServerNoifyNotify_V18
{
public:
	static FPD_SSLServerNoify Create(FPD_SSLServerNoifyCallbacks callback);
	static FPD_SSLServerNoify CreateDefault();
	static void Destroy(FPD_SSLServerNoify notify);
	static FS_BOOLEAN GetTimeStamp(FPD_SSLServerNoify notify, FS_ByteString* buffer, const FS_LPCSTR bsHost, FS_ByteString* sendData, FPD_RequestResult* outresult);
};

class CFPD_CCnki_V20
{
public:	
};

class CFPD_SealInfo_V20
{
public:
	static FPD_SealInfo Create();
	static void Delete(FPD_SealInfo info);
	static FS_INT32 GetNohterCurChainListIndex(FPD_SealInfo info);
	static FS_INT32 GetVerifyohterCertListCount(FPD_SealInfo info, FS_PtrArray* outList);
	static void GetVerifyohterCertByIndex(FPD_SealInfo info, FS_INT32 nIndex, FS_ByteStringArray* outCerts);
	static void GetSealName(FPD_SealInfo info, FS_WideString* outName);
	static FPD_SYSTEMTIME GetSealmaketime(FPD_SealInfo info);
	static FPD_SYSTEMTIME GetSealbegin(FPD_SealInfo info);
	static FPD_SYSTEMTIME GetSealEnd(FPD_SealInfo info);
	static void GetRevocVerifyKeyIndex(FPD_SealInfo info, FS_Int32Array* outIndexArr);
	static void GetRevocVerifyByKey(FPD_SealInfo info, FS_INT32 nKey, FS_PtrArray* outRevocVerify);
};

class CFPD_StructNamespace_V21
{
public:
	static void GetNamespace(FPD_StructNamespace space, FS_WideString* outName);
	static FPD_FileSpec	GetSchema(FPD_StructNamespace space);
	static FPD_StructTree GetTree(FPD_StructNamespace space);
	static FS_BOOLEAN	IsDefaultNS(FPD_StructNamespace space);
};

class CFPD_Repair_V21
{
public:
	//************************************
	// Function:  Create	
	// Return: FPD_Repair	    Return FPD_Repair obj. 
	// Remarks: Create FPD_Repair obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static FPD_Repair Create();

	//************************************
	// Function:  Delete
	// Param[in]: repair			The input FPD_Repair obj. 
	// Return: void	   
	// Remarks: Delete FPD_Repair obj. 
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static void	Delete(FPD_Repair repair);
	
	//************************************
	// Function:  Repair
	// Param[in]: pInputFile			The corrupted document file stream.
	// Param[in]: pOutFile			    The document file stream after repair.
	// Param[in]: sTmpPath			    The tmp path.
	// Param[in]: option			    The optional.
	// Return: FS_INT32	    Return document error code.    
	// Remarks: PDF document repair.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static FS_INT32 Repair(FPD_Repair repair, FS_FileStream pInputFile,
		FS_FileStream pOutFile,
		const FS_LPCWSTR sTmpPath,
		FS_INT32 option);
};

class CFPD_BookmarkTree_V21
{
public:
	//************************************
	// Function:  Create
	// Param[in]: pDoc			The input PDF document.
	// Return: FPD_BookmarkTree	    Return FPD_BookmarkTree obj. 
	// Remarks: Construct from a PDF document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static FPD_BookmarkTree Create(FPD_Document pDoc);

	//************************************
	// Function:  Delete
	// Param[in]: tree			The input FPD_BookmarkTree obj.
	// Return: void 
	// Remarks: Delete FPD_BookmarkTree obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static void Delete(FPD_BookmarkTree tree);

	//************************************
	// Function:  InsertItem
	// Param[in]: tree			   The input FPD_BookmarkTree obj.
	// Param[in]: wsTitle		   The title of new bookmark.
	// Param[in]: bmkParent		   Parent of new bookmark. Can be NULL, if bmkInsertAfter
	//                             not NULL or it will be the first item of the tree.
	// Param[in]: bmkInsertAfter   The item after which the new item is to be inserted.
	//							   If NULL, will be inserted to the first child of parent.
	// Param[in/out]: newBookmark  The new item if successful.
	// Return: void
	// Remarks: Create a new bookmark item and insert into bookmark tree.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static void	 InsertItem(FPD_BookmarkTree tree, FS_LPCWSTR wsTitle, FPD_Bookmark bmkParent, FPD_Bookmark bmkInsertAfter, FPD_Bookmark* newBookmark);
	
	//************************************
	// Function:  InsertItem2
	// Param[in]: tree			   The input FPD_BookmarkTree obj.
	// Param[in]: wsTitle		   The title of new bookmark.
	// Param[in]: bUTF8		       Whether the title is saved as UTF-8 encoding or not in PDF.
	// Param[in]: bmkParent		   Parent of new bookmark. Can be NULL, if bmkInsertAfter
	//                             not NULL or it will be the first item of the tree.
	// Param[in]: bmkInsertAfter   The item after which the new item is to be inserted.
	//							   If NULL, will be inserted to the first child of parent.
	// Param[in/out]: newBookmark  The new item if successful; otherwise NULL.
	// Return: void
	// Remarks: Create a new bookmark item and insert into bookmark tree.
	// Notes:  Only the PDF2.0 supports for the UTF-8 Unicode character encoding scheme.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static void  InsertItem2(FPD_BookmarkTree tree, FS_LPCWSTR wsTitle, FS_BOOLEAN bUTF8, FPD_Bookmark bmkParent, FPD_Bookmark bmkInsertAfter, FPD_Bookmark* newBookmark);
	
	//************************************
	// Function:  InsertItem3
	// Param[in]: tree			   The input FPD_BookmarkTree obj.
	// Param[in]: bmkInserted	   The item to be inserted.	
	// Param[in]: bmkParent		   Parent of new bookmark. Can be NULL, if bmkInsertAfter
	//                             not NULL or it will be the first item of the tree.
	// Param[in]: bmkInsertAfter   The item after which the new item is to be inserted.
	//							   If NULL, will be inserted to the first child of parent.	
	// Return: FS_BOOLEAN
	// Remarks: Create a new bookmark item and insert into bookmark tree.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static FS_BOOLEAN   InsertItem3(FPD_BookmarkTree tree, FPD_Bookmark bmkInserted, FPD_Bookmark bmkParent, FPD_Bookmark bmkInsertAfter);
	
	//************************************
	// Function:  RemoveItem
	// Param[in]: tree			   The input FPD_BookmarkTree obj.
	// Param[in]: bookmark	       The bookmark item to be removed.
	// Return: void
	// Remarks: Remove a bookmark item from bookmark tree.
	// Notes:  
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static void		RemoveItem(FPD_BookmarkTree tree, FPD_Bookmark bookmark);
};

#ifdef __cplusplus
};
#endif

#endif//FPD_DOCIMPL_H

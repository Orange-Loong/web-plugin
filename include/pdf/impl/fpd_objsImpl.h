
#ifndef FPD_OBJSIMPL_H
#define FPD_OBJSIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_SERIALEXPT_H
#include "../fpd_serialExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif
//////////////////////////////////////////////////////////////////////////////////////////////////////
/*											 CFPD_Object_V1						                    */
//////////////////////////////////////////////////////////////////////////////////////////////////////
/** @brief Basic object for all PDF syntax objects */
class CFPD_Object_V1
{
public:
	//************************************
	// Function:  GetType
	// Param[in]: obj		The input PDF syntax objects.
	// Return:    One of the FPD_OBJ_xxxx constants.
	// Remarks:   Gets type of the object.
	// Notes:   
	//************************************
	static FS_INT32 GetType(FPD_Object obj);

	//************************************
	// Function:  GetobjNum
	// Param[in]: obj		The input PDF syntax objects.
	// Return:    The indirect number of the object.
	// Remarks:   Gets indirect number of the object. 0 for direct object.
	// Notes:
	//************************************
	static FS_DWORD	GetobjNum(FPD_Object obj);

	//************************************
	// Function:  IsIdentical
	// Param[in]: obj			The input PDF syntax objects.
	// Param[in]: otherObj		The input object.
	// Return:    Non-zero means identical, otherwise not identical. 
	// Remarks:   Compares with another object.
	// Notes:
	//************************************
	static FS_BOOL IsIdentical(FPD_Object obj, FPD_Object otherObj);

	//************************************
	// Function:  Clone
	// Param[in]: srcObj		The input PDF syntax objects.
	// Param[in]: bDirect		Whether a totally direct copy is requested.
	// Return:    A complete clone object.
	// Remarks:   Gets a complete clone. The bDirect param specifies whether a totally direct copy
	//            is requested (without any reference inside, so the copy can be copied to other document).
	// Notes:
	//************************************
	static FPD_Object Clone(FPD_Object srcObj, FS_BOOL bDirect);

	//************************************
	// Function:  CloneRefToDoc
	// Param[in]: srcObj		The input PDF syntax objects.
	// Param[in]: others		The document.
	// Return:    A clone direct object or a reference for document.
	// Remarks:   Gets a clone for direct object, or a reference for document.
	// Notes:
	//************************************
	static FPD_Object CloneRefToDoc(FPD_Object srcObj, FPD_Document others);

	//************************************
	// Function:  CloneRefToFDFDoc
	// Param[in]: srcObj		The input PDF syntax objects.
	// Param[in]: others		The memory document.
	// Return:    A clone direct object or a reference for memory document.
	// Remarks:   Gets a clone for direct object, or a reference for memory document.
	// Notes:
	//************************************
	static FPD_Object CloneRefToFDFDoc(FPD_Object srcObj, FDF_Document others);

	//************************************
	// Function:  GetDirect
	// Param[in]: obj		The input PDF syntax objects.
	// Return:    The direct object (the object data itself) of an object.
	// Remarks:   Gets direct object (the object data itself) of an object.
	//            For direct object, return itself; for reference object, return the referred object.
	// Notes: 
	//************************************
	static FPD_Object GetDirect(FPD_Object obj);

	//************************************
	// Function:  Destroy
	// Param[in]: obj		The input PDF syntax objects.
	// Return:    void
	// Remarks:   Destroys the object. This function has no effect to indirect objects.
	// Notes:
	//************************************
	static void	Destroy(FPD_Object obj);

	//************************************
	// Function:  GetString
	// Param[in]: obj			The input PDF syntax objects.
	// Param[out]:outString		It receives the string value of the object.
	// Return:    void
	// Remarks:   Gets string value of the object. Applicable to string, name, and number objects.
	//            If object type not supported, empty string is returned.
	// Notes:
	//************************************
	static void	GetString(FPD_Object obj, FS_ByteString* outString);

	//************************************
	// Function:  GetUnicodeText
	// Param[in]: obj				The input PDF syntax objects.
	// Param[out]:outUnicodeText	An Unicode text value.
	// Return:    void
	// Remarks:   Gets Unicode text value of the object. Applicable to string and stream objects.
    //            If object type not supported, empty string is returned.
	//	          We assume the original text are encoding in PDF text encoding scheme.
	//	          The returned text is encoded in UTF-16LE encoding.
	//	          A character mapper can be used to convert the original text (if not already encoded in Unicode).
	//            If no character mapper used, PDFDocEncoding mapping is used.
	// Notes:
	//************************************
	static void	GetUnicodeText(FPD_Object obj, FS_WideString* outUnicodeText);	

	//************************************
	// Function:  GetNumber
	// Param[in]: obj		The input PDF syntax objects.
	// Return:    The float number value of the object.
	// Remarks:   Gets float number value of the object. Applicable to number objects only.
	//            If object type is not number, 0.0f is returned.
	//            FIX: when FIX format is used, the returned value will be in FIX24.8 format.
	// Notes:
	//************************************
	static FS_FLOAT	GetNumber(FPD_Object obj);
		
	//************************************
	// Function:  GetInteger
	// Param[in]: obj		The input PDF syntax objects.
	// Return:    The integer number value of the object.
	// Remarks:   Gets integer number value of the object. Applicable to number and boolean objects.
	//            If object type not supported, 0 is returned.
	// Notes:
	//************************************
	static FS_INT32 GetInteger(FPD_Object obj);

	//************************************
	// Function:  GetDict
	// Param[in]: obj		The input PDF syntax objects.
	// Return:    The dictionary value of the object.
	// Remarks:   Gets dictionary value of the object. Applicable to dictionaries or stream only.
	//            <a>NULL</a> is returned for other types of objects.
	// Notes:
	//************************************
	static FPD_Object GetDict(FPD_Object obj);

	//************************************
	// Function:  GetArray
	// Param[in]: obj		The input PDF syntax objects.
	// Return:    The array value of the object.
	// Remarks:   Gets array value of the object. Applicable to arrays only.
	//            <a>NULL</a> is returned for non-array objects.
	// Notes:
	//************************************
	static FPD_Object GetArray(FPD_Object obj);

	//************************************
	// Function:  SetString
	// Param[in]: obj		The input PDF syntax objects.
	// Param[in]: str		The input string value.
	// Return:    void
	// Remarks:   Sets string value into the object. Applicable to boolean, number, string and name objects.
	//            For non-supported object types, this function does nothing.
	// Notes:
	//************************************
	static void	SetString(FPD_Object obj, FS_LPCSTR str);

	//************************************
	// Function:  SetUnicodeText
	// Param[in]: obj		The input PDF syntax objects.
	// Param[in]: str		Pointer to UTF-16LE format characters.
	// Param[in]: len		Number of the input characters.
	// Return:    void
	// Remarks:   Sets text encoded in Unicode (UTF-16LE format). Applicable to string and stream objects.
	//            "len" is number of characters, not bytes. -1 for null terminated string.
	// Notes:
	//************************************
	static void	SetUnicodeText(FPD_Object obj, FS_LPCWSTR str, FS_INT32 len);

	//************************************
	// Function:  GetDirectType
	// Param[in]: obj		The input PDF syntax objects.
	// Return:    The type of direct object without loading it.
	// Remarks:   Gets type of direct object without loading it.
	// Notes:
	//************************************
	static FS_INT32 GetDirectType(FPD_Object obj);

	//************************************
	// Function:  IsModified
	// Param[in]: obj		The input PDF syntax objects.
	// Return:    <a>TRUE</a> for the object having been "modified".
	// Remarks:   Tests whether the object has been "modified".
	// Notes:
	//************************************
	static FS_BOOL IsModified(FPD_Object obj);

	//************************************
	// Function:  SetModified
	// Param[in]: obj			The input PDF syntax objects.
	// Param[in]: bModified		The "modified" flag. TRUE means "modified".
	// Return:    void
	// Remarks:   Changes the object's "modified" flag.
	// Notes:
	//************************************
	static void	SetModified(FPD_Object obj, FS_BOOL bModified);

	//************************************
	// Function:  GetContainer
	// Param[in]: obj		The input PDF syntax objects.
	// Return:    The container of this object. 
	// Remarks:   Gets the container of this object. 
	// Notes:
	//************************************
	static FPD_Object GetContainer(FPD_Object obj);

	//************************************
	// Function:  SetContainer
	// Param[in]: obj			The input PDF syntax objects.
	// Param[in]: container		The container of this object.
	// Return:    void
	// Remarks:   Sets the container of this object.
	// Notes:
	//************************************
	static void	SetContainer(FPD_Object obj, FPD_Object container);

	//************************************
	// Function:  ParseString
	// Param[in]: str		A string containing the object
	// Return:    A parsed object, or <a>NULL</a> if error.
	// Remarks:   Parses an object from a memory buffer. 
	// Notes: Parsing indirect reference inside the string will
	// bring undefined result.
	//************************************
	static FPD_Object ParseString(FS_LPCSTR str);
	
	//************************************
	// Function:  GetConstString
	// Param[in]: obj		The input PDF syntax objects.
	// Return:  FS_LPCSTR  
	// Remarks:  Get string value of the object. 
	// Notes: Only applicable to string and name.
	//************************************
	static FS_LPCSTR	GetConstString(FPD_Object obj);
	
	//************************************
	// Function:  IsNewCreated
	// Param[in]: obj		  The input PDF syntax objects.
	// Return:  FS_BOOLEAN   true for being created newly, false for obtaining form cache.
	// Remarks:  Whether the object was created newly.
	// Notes: 
	//************************************
	static FS_BOOLEAN	IsNewCreated(FPD_Object obj);

	//************************************
	// Function:  GetUnicodeText2
	// Param[in]: obj				The input PDF syntax objects.
	// Param[in]: pCharMap			The input character mapper.
	// Param[in]: encoding			The input encoding.
	// Param[out]:outUnicodeText	An Unicode text value.
	// Return:    void
	// Remarks:   Gets Unicode text value of the object. Applicable to string and stream objects.
	//            If object type not supported, empty string is returned.
	//	           We assume the original text are encoding in PDF text encoding scheme.
	//	           The returned text is encoded in UTF-16LE encoding.
	//	           A character mapper can be used to convert the original text (if not already encoded in Unicode).
	//            If no character mapper used, PDFDocEncoding mapping is used.
	// Notes:
	//************************************
	static void	GetUnicodeText2(FPD_Object obj, FS_CharMap pCharMap, FS_LPCSTR encoding, FS_WideString* outUnicodeText);

	//************************************
	// Function:  DeepClone
	// Param[in]: obj		      The input PDF syntax objects.
	// Param[in]: pDocObjs		  The input FPD_Document.
	// Param[in]: pPred		      The input FPD_ClonePredicateHandler.
	// Param[out]: outkeyArray	  Get the deep obj numbers.
	// Param[out]: outObjNumberArray	Get the deep obj numbers.
	// Return:  FPD_Object   true for being created newly, false for obtaining form cache.
	// Remarks:  Deep clone the objects.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static FPD_Object DeepClone(FPD_Object obj, FPD_Document pDocObjs,FPD_ClonePredicateHandler pPred, FS_DWordArray* outkeyArray, FS_DWordArray* outObjNumberArray);

	//************************************
	// Function:  CreateClonePredicateHandler
	// Param[in]: callbacks		      The input FPD_ClonePredicateCallbacks object.	
	// Return:  FPD_ClonePredicateHandler   
	// Remarks:  Create FPD_ClonePredicateHandler obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static FPD_ClonePredicateHandler CreateClonePredicateHandler(FPD_ClonePredicateCallbacks callbacks);

	//************************************
	// Function:  DestroyClonePredicateHandler
	// Param[in]: handler		      The input FPD_ClonePredicateHandler object.	
	// Return:  void   
	// Remarks:  Destroy FPD_ClonePredicateHandler obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static void DestroyClonePredicateHandler(FPD_ClonePredicateHandler handler);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*									 CFPD_Boolean_V1		  		                                */
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_Boolean_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: value		A boolean value.
	// Return:    A boolean object.
	// Remarks:   Creates a boolean object from a single boolean value.
	// Notes:
	// See:  FPDObjectDestroy
	//************************************
	static FPD_Object New(FS_BOOL value);

	//************************************
	// Function:  Identical
	// Param[in]: ObjBoolean		The boolean object.
	// Param[in]: otherBoolean		The other boolean object.
	// Return:    Non-zero means identical, otherwise not identical.
	// Remarks:   Compares with another boolean object.
	// Notes:
	//************************************
	static FS_BOOL Identical(FPD_Object ObjBoolean, FPD_Object otherBoolean);

};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										CFPD_Number_V1           			                    */
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_Number_V1
{
public:
	//************************************
	// Function:  NewByInt
	// Param[in]: value		The input integer.
	// Return:    A number object.
	// Remarks:   Creates a number object from an integer.
	// Notes:
	// See: FPDObjectDestroy
	// See: FPDNumberNewByFloat
	// See: FPDNumberNewByStr
	// See: FPDNumberNewFromData
	//************************************
	static FPD_Object NewByInt(FS_INT32 value);

	//************************************
	// Function:  NewByFloat
	// Param[in]: value		The input floating-point.
	// Return:    A number object.
	// Remarks:   Creates a number object from a floating-point value.
	// Notes:
	// See: FPDObjectDestroy
	// See: FPDNumberNewByInt
	// See: FPDNumberNewByStr
	// See: FPDNumberNewFromData
	//************************************
	static FPD_Object NewByFloat(FS_FLOAT value);

	//************************************
	// Function:  NewByStr
	// Param[in]: pStr		The input non-buffered byte string.
	// Return:    A number object.
	// Remarks:   Creates a number object from a non-buffered byte string.
	// Notes:
	// See: FPDObjectDestroy
	// See: FPDNumberNewByFloat
	// See: FPDNumberNewByInt
	// See: FPDNumberNewFromData
	//************************************
	static FPD_Object NewByStr(FS_LPCSTR pStr);

	//************************************
	// Function:  NewFromData
	// Param[in]: bInteger		Whether the input data is actually an integer.
	// Param[in]: pData			The input data.
	// Return:    A number object.
	// Remarks:   Creates a number object from data.
	// Notes:
	// See: FPDObjectDestroy
	// See: FPDNumberNewByFloat
	// See: FPDNumberNewByStr
	// See: FPDNumberNewByInt
	//************************************
	static FPD_Object NewFromData(FS_BOOL bInteger, void* pData);

	//************************************
	// Function:  Identical
	// Param[in]: objNumber			The input number object.
	// Param[in]: other_number		The other number object.
	// Return:    Non-zero means identical, otherwise not identical.
	// Remarks:   Compares with another number object.
	// Notes:
	//************************************
	static FS_BOOL Identical(FPD_Object objNumber, FPD_Object other_number);

	//************************************
	// Function:  GetString
	// Param[in]: objNumber		The input number object.
	// Param[out]:outResult	A byte string from this object.
	// Return:    void
	// Remarks:   Gets a byte string from this object.
	// Notes:
	//************************************
	static void	GetString(FPD_Object objNumber, FS_ByteString* outResult);

	//************************************
	// Function:  SetString
	// Param[in]: objNumber		The input number object.
	// Param[in]: str			The input non-buffered byte string.
	// Return:    void
	// Remarks:   Sets a non-buffered byte string.
	// Notes: 
	//************************************
	static void	SetString(FPD_Object objNumber, FS_LPSTR str);

	//************************************
	// Function:  IsInteger
	// Param[in]: objNumber		The input number object.
	// Return:    <a>TRUE</a> for the number being an integer.
	// Remarks:   Whether the number is an integer.
	// Notes:
	//************************************
	static FS_BOOL IsInteger(FPD_Object objNumber);

	//************************************
	// Function:  GetInteger
	// Param[in]: objNumber		The input number object.
	// Return:    The integer value.
	// Remarks:   Gets the integer value.
	// Notes:
	//************************************
	static FS_INT32	GetInteger(FPD_Object objNumber);

	//************************************
	// Function:  GetNumber
	// Param[in]: objNumber		The input number object.
	// Return:    The FIX24.8 value.
	// Remarks:   Gets the FIX24.8 value.
	// Notes:
	//************************************
	static FS_FLOAT GetNumber(FPD_Object objNumber);

	//************************************
	// Function:  SetNumber
	// Param[in]: objNumber		The input number object.
	// Param[in]: value			The input FIX24.8 value.
	// Return:    void
	// Remarks:   Sets a FIX24.8 value.
	// Notes:
	//************************************
	static void	SetNumber(FPD_Object objNumber, FS_FLOAT value);

	//************************************
	// Function:  GetFloat
	// Param[in]: objNumber		The input number object.
	// Return:    The floating-point value.
	// Remarks:   Gets the floating-point value.
	// Notes:
	//************************************
	static FS_FLOAT	GetFloat(FPD_Object objNumber);

	//************************************
	// Function:  NewByFloat2
	// Param[in]: value		The input floating-point.
	// Param[in]: precision The number of decimal digits.Default value : 0.
	// Return:    A number object.
	// Remarks:   Creates a number object from a floating-point value.
	// Notes:
	// See: FPDObjectDestroy
	// See: FPDNumberNewByInt
	// See: FPDNumberNewByStr
	// See: FPDNumberNewFromData
	//************************************
	static FPD_Object NewByFloat2(FS_FLOAT value, FS_BYTE precison);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										CFPD_String_V1											*/
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_String_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: str		The input byte string.
	// Param[in]: bHex		The input hex flag.
	// Return:    A string object.
	// Remarks:   Creates a string object from a byte string.
	// Notes:
	// See:  FPDObjectDestroy
	//************************************
	static FPD_Object New(FS_ByteString str, FS_BOOL bHex);

	//************************************
	// Function:  NewW
	// Param[in]: wstr		The input wide string.
	// Return:    A string object.
	// Remarks:   Creates a string object from a wide string.
	// Notes:
	// See:  FPDObjectDestroy
	//************************************
	static FPD_Object NewW(FS_LPCWSTR wstr);
	
	//************************************
	// Function:  GetString
	// Param[in]: objString		The input string object.
	// Param[out]: outString	It receives the ref to the data of the string object.
	// Return:    void
	// Remarks:   Gets a ref to the data of the string object.
	// Notes:
	//************************************
	static void GetString(FPD_Object objString, FS_ByteString* outString);

	//************************************
	// Function:  Identical
	// Param[in]: objString			The input string object.
	// Param[in]: other_objString	The other string object.
	// Return:    Non-zero means identical, otherwise not identical.
	// Remarks:   Compares with another string object.
	// Notes:
	//************************************
	static FS_BOOL Identical(FPD_Object objString, FPD_Object other_objString);

	//************************************
	// Function:  SetHex
	// Param[in]: objString		The input string object.
	// Param[in]: bHex			The input hex flag.
	// Return:    void
	// Remarks:   Changes the hex flag.
	// Notes:
	//************************************
	static void	SetHex(FPD_Object objString, FS_BOOL bHex);

	//************************************
	// Function:  IsHex
	// Param[in]: objString		The input string object.
	// Return:    <a>TRUE</a> for string object having the hex flag.
	// Remarks:   Tests whether this string object has the hex flag.
	// Notes:
	//************************************
	static FS_BOOL IsHex(FPD_Object objString);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										CFPD_Name_V1							                    */
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_Name_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: str		The input byte string.
	// Return:    A name object.
	// Remarks:   Creates a name object from a byte string.
	// Notes:
	// See:  FPDObjectDestroy
	//************************************
	static FPD_Object  New(FS_LPCSTR str);
	
	//************************************
	// Function:  GetString
	// Param[in]: objName		The input name object.
	// Param[out]: outString	It receives the data of the name object.
	// Return:    void
	// Remarks:   Gets a ref to the data of the name object.
	// Notes:
	//************************************
	static void GetString(FPD_Object objName, FS_ByteString* outString);

	//************************************
	// Function:  Identical
	// Param[in]: objName			The input name object.
	// Param[in]: other_objName		The other name object.
	// Return:    Non-zero means identical, otherwise not identical.
	// Remarks:   Compares with another name object.
	// Notes:
	//************************************
	static FS_BOOL Identical(FPD_Object objName, FPD_Object other_objName);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*										CFPD_Array_V1						                    */
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_Array_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    An empty array object.
	// Remarks:   Creates an empty array object.
	// Notes:
	// See:  FPDObjectDestroy
	//************************************
	static FPD_Object New(void);
	
	//************************************
	// Function:  GetCount
	// Param[in]: objArray		The input PDF array object.
	// Return:    The count of objects in the array.
	// Remarks:   Gets the count of objects in the array.
	// Notes:
	//************************************
	static FS_DWORD	GetCount(FPD_Object objArray);

	//************************************
	// Function:  GetElement
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Return:    Pointer to specified element.
	// Remarks:   Gets reference to element. Returns direct reference to the element.
	// Notes: Don't release the returned object.
	//************************************
	static FPD_Object GetElement(FPD_Object objArray, FS_DWORD index);

	//************************************
	// Function:  GetElementValue
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Return:    A direct or referred indirect object.
	// Remarks:   Gets direct or referred indirect object.
	// Notes: Don't release the returned object.
	//************************************
	static FPD_Object GetElementValue(FPD_Object objArray, FS_DWORD index);


	//************************************
	// Function:  GetMatrix
	// Param[in]: objArray		The input PDF array object.
	// Return:    A matrix from the array.
	// Remarks:   Gets a matrix from the array.
	// Notes:
	//************************************
	static FS_AffineMatrix GetMatrix(FPD_Object objArray);

	//************************************
	// Function:  GetRect
	// Param[in]: objArray		The input PDF array object.
	// Return:    A rectangle from the array.
	// Remarks:   Gets a rectangle from the array.
	// Notes:
	//************************************
	static FS_FloatRect	GetRect(FPD_Object objArray);


	//************************************
	// Function:  GetString
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Param[out]:outString		A byte string.
	// Return:    void
	// Remarks:   Gets a string with specified position.
	// Notes:
	//************************************
	static void	GetString(FPD_Object objArray, FS_DWORD index, FS_ByteString* outString);

	//************************************
	// Function:  GetInteger
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Return:    An integer.
	// Remarks:   Gets an integer with specified position.
	// Notes:
	//************************************
	static FS_INT32	GetInteger(FPD_Object objArray, FS_DWORD index);

	//************************************
	// Function:  GetNumber
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Return:    A FIX24.8 number.
	// Remarks:   Gets a number with specified position.
	// Notes:
	//************************************
	static FS_FLOAT	GetNumber(FPD_Object objArray, FS_DWORD index);

	//************************************
	// Function:  GetDict
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Return:    A dictionary object.
	// Remarks:   Gets a dictionary object with specified position.
	// Notes:
	//************************************
	static FPD_Object GetDict(FPD_Object objArray, FS_DWORD index);

	//************************************
	// Function:  GetStream
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Return:    A stream object.
	// Remarks:   Gets a stream object with specified position.
	// Notes:
	//************************************
	static FPD_Object GetStream(FPD_Object objArray, FS_DWORD index);

	//************************************
	// Function:  GetArray
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Return:    An array object.
	// Remarks:   Gets an array object with specified position.
	// Notes:
	//************************************
	static FPD_Object GetArray(FPD_Object objArray, FS_DWORD index);

	//************************************
	// Function:  GetFloat
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Return:    A floating-point value.
	// Remarks:   Gets a floating-point with specified position.
	// Notes:
	//************************************
	static FS_FLOAT	GetFloat(FPD_Object objArray, FS_DWORD index);

	
	//************************************
	// Function:  SetAt
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Param[in]: otherObj		The input object.
	// Param[in]: objs			The indirect object collection, it can be a FDF_Document object or a FPD_Document object, required if pObj is an indirect object. In this case, a reference object will be created and inserted into the array.
	// Return:    void
	// Remarks:   Changes the element at specified position.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void	SetAt(FPD_Object objArray, FS_DWORD index, FPD_Object otherObj, void* objs);

	//************************************
	// Function:  InsertAt
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Param[in]: otherObj		The input object.
	// Param[in]: pDoc			The indirect object collection, it can be a FDF_Document object or a FPD_Document object, required if pObj is an indirect object. In this case, a reference object will be created and inserted into the array.
	// Return:    void
	// Remarks:   Inserts an element at specified position.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void	InsertAt(FPD_Object objArray, FS_DWORD index, FPD_Object otherObj, FPD_Document pDoc);

	//************************************
	// Function:  RemoveAt
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Return:    void
	// Remarks:   Removes an element.
	// Notes:
	//************************************
	static void	RemoveAt(FPD_Object objArray, FS_DWORD index);

	//************************************
	// Function:  Add
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: other_obj		The input object.
	// Param[in]: pDoc			The input FPD_Document object.
	// Return:    void
	// Remarks:   Adds a new element to array. 
	// Notes: All elements will be managed with the array object, so the object pointer
	//           must NOT be freed by caller
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void	Add(FPD_Object objArray, FPD_Object other_obj, FPD_Document pDoc);

	//************************************
	// Function:  AddNumber
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: num			The input FIX24.8 value.
	// Return:    void
	// Remarks:   Adds a number object with a FIX24.8 value.
	// Notes:
	//************************************
	static void	AddNumber(FPD_Object objArray, FS_FLOAT num);

	//************************************
	// Function:  AddInteger
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: value			The input integer value.
	// Return:    void
	// Remarks:   Adds a number object with an integer value.
	// Notes:
	//************************************
	static void	AddInteger(FPD_Object objArray, FS_INT32 value);

	//************************************
	// Function:  AddString
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: str			The input string data.
	// Param[in]: nLen			The length of the input string data.
	// Return:    void
	// Remarks:   Adds a string object.
	// Notes:
	//************************************
	static void	AddString(FPD_Object objArray, FS_LPCSTR str, FS_INT32 nLen);

	//************************************
	// Function:  AddName
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: szName		The input name data.
	// Return:    void
	// Remarks:   Adds a name object.
	// Notes:
	//************************************
	static void	AddName(FPD_Object objArray, FS_LPCSTR szName);

	//************************************
	// Function:  AddReferenceToDoc
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: doc			The input indirect object collection.
	// Param[in]: objNum		The referred object number.
	// Return:    void
	// Remarks:   Adds a reference object with object number.
	// Notes:
	//************************************
	static void	AddReferenceToDoc(FPD_Object objArray, FPD_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  AddReferenceToFDFDoc
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: doc			The input indirect object collection.
	// Param[in]: objNum		The referred object number.
	// Return:    void
	// Remarks:   Adds a reference object with object number.
	// Notes:
	//************************************
	static void	AddReferenceToFDFDoc(FPD_Object objArray, FDF_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  AddReference2ToDoc
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: doc			The input indirect object collection.
	// Param[in]: obj			The input object.
	// Return:    void
	// Remarks:   Adds a reference object with object pointer.
	// Notes:
	//************************************
	static void	AddReference2ToDoc(FPD_Object objArray, FPD_Document doc, FPD_Object obj);

	//************************************
	// Function:  AddReference2ToFDFDoc
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: doc			The input indirect object collection.
	// Param[in]: obj			The input object.
	// Return:    void
	// Remarks:   Adds a reference object with object pointer.
	// Notes:
	//************************************
	static void	AddReference2ToFDFDoc(FPD_Object objArray, FDF_Document doc, FPD_Object obj);
	
	//************************************
	// Function:  IsIdentical
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: otherArray	The other PDF array object.
	// Return:    Non-zero means identical, otherwise not identical.
	// Remarks:   Compares with another object.
	// Notes:
	//************************************
	static FS_BOOL IsIdentical(FPD_Object objArray, FPD_Object otherArray);
	
	 //************************************
	 // Function:  RemoveAt2
	 // Param[in]: objArray		The input PDF array object.
	 // Param[in]: index		Specifies the zero-based index in the array.
	 // Param[in]: bRelease	    true: release the data of the index.
	 // Return:    void
	 // Remarks:   Removes an element.
	 // Notes:
	 //************************************
	static void		RemoveAt2(FPD_Object objArray, FS_DWORD index, FS_BOOLEAN bRelease);
	
	//************************************
	// Function:  AddNew
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: object_type	The type of the object, one of the FPD_PAGEOBJ constants.
	// Return:    FPD_Object   A pdf object, it may be null when object's type is invalid.
	// Remarks:    Allocate and add an object element by object_type.
	//            Takes ownership of the object created internally, returns an unowned pdf object pointer.
	// Notes:
	//************************************
	static FPD_Object	AddNew(FPD_Object objArray, FS_INT32 object_type);

	//************************************
	// Function:  Release
	// Param[in]: objArray		The input PDF array object.
	// Return:   void
	// Remarks:  Release (free, destroy) the object. This function has no effect to indirect objects.
	// Notes:
	//************************************
	static void	 Release(FPD_Object objArray);

	//************************************
	// Function:  Add2
	// Param[in]: objArray		The input PDF array object.
	// Param[in]: other_obj		The input object.
	// Param[in]: pDoc			The input FDF_Document object.
	// Return:    void
	// Remarks:   Adds a new element to array. 
	// Notes: All elements will be managed with the array object, so the object pointer
	//           must NOT be freed by caller
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static void	Add2(FPD_Object objArray, FPD_Object other_obj, FDF_Document pDoc);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*									CFPD_Dictionary_V1						                    */
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_Dictionary_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A PDF dictionary object.
	// Remarks:   Creates an empty dictionary.
	// Notes:
	// See:  FPDObjectDestroy
	//************************************
	static FPD_Object New(void);

	
	//************************************
	// Function:  GetElement
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    A pointer to the object (include reference).
	// Remarks:   Gets direct reference to the object (include reference), 
	//            Don't free the returned object.
	// Notes:
	//************************************
	static FPD_Object GetElement(FPD_Object objDict, const char* key);

	//************************************
	// Function:  GetElementValue
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    A pointer to direct or referred indirect object.
	// Remarks:   Gets a direct or referred indirect object, 
	//            Don't free the returned object.
	// Notes:
	//************************************
	static FPD_Object GetElementValue(FPD_Object objDict, const char* key);


	//************************************
	// Function:  GetString	
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[out]:outString		A byte string for the specified element.
	// Return:    void
	// Remarks:   Gets the string data for the element specified by key.
	// Notes:
	//************************************
	static void	GetString(FPD_Object objDict, const char* key, FS_ByteString* outString);

	//************************************
	// Function:  GetUnicodeText
	// Param[in]: objDict			The input PDF dictionary object.
	// Param[in]: key				The input key string.
	// Param[out]:outUnicodeText	An Unicode string for the specified element.
	// Return:    void
	// Remarks:   Gets the Unicode string data for the element specified by key with a character mapping.
	// Notes:
	//************************************
	static void	GetUnicodeText(FPD_Object objDict, const char* key, FS_WideString* outUnicodeText);

	//************************************
	// Function:  GetInteger
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    An integer value for the specified element.
	// Remarks:   Gets the integer data for the element specified by key.
	// Notes:
	//************************************
	static FS_INT32	GetInteger(FPD_Object objDict, const char* key);

	//************************************
	// Function:  GetInteger2
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: defaultInt	The default integer value.
	// Return:    An integer value for the specified element.
	// Remarks:   Gets the integer data for the element specified by key with a default integer value.
	// Notes:
	//************************************
	static FS_INT32	GetInteger2(FPD_Object objDict, const char* key, FS_INT32 defaultInt);

	//************************************
	// Function:  GetBoolean
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    A boolean value for the specified element.
	// Remarks:   Gets the boolean data for the element specified by key with a default boolean value.
	// Notes:
	//************************************
	static FS_BOOL GetBoolean(FPD_Object objDict, const char* key);

	//************************************
	// Function:  GetNumber
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    A FIX24.8 value for the specified element.
	// Remarks:   Gets the number data for the element specified by key.
	// Notes:
	//************************************
	static FS_FLOAT	GetNumber(FPD_Object objDict, const char* key);

	//************************************
	// Function:  GetDict
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    A dictionary object.
	// Remarks:   Gets a dictionary object specified by key.
	// Notes:
	//************************************
	static FPD_Object GetDict(FPD_Object objDict, const char* key);

	//************************************
	// Function:  GetStream
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    A stream object.
	// Remarks:   Gets a stream object specified by key.
	// Notes:
	//************************************
	static FPD_Object GetStream(FPD_Object objDict, const char* key);

	//************************************
	// Function:  GetArray
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    An array object.
	// Remarks:   Gets an array object specified by key.
	// Notes:
	//************************************
	static FPD_Object GetArray(FPD_Object objDict, const char* key);

	//************************************
	// Function:  GetRect
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    A rectangle.
	// Remarks:   Gets a rectangle for the element specified by key.
	// Notes:
	//************************************
	static FS_FloatRect GetRect(FPD_Object objDict, const char* key);

	//************************************
	// Function:  GetMatrix
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    A matrix.
	// Remarks:   Gets a matrix for the element specified by key.
	// Notes:
	//************************************
	static FS_AffineMatrix GetMatrix(FPD_Object objDict, const char* key);

	//************************************
	// Function:  GetFloat
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:	  A floating-point value.
	// Remarks:   Gets a floating-point value for the element specified by key.
	// Notes: 
	//************************************
	static FS_FLOAT	GetFloat(FPD_Object objDict, const char* key);
	
	//************************************
	// Function:  KeyExist
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    Non-zero means exist, otherwise not.
	// Remarks:   Tests whether the element specified by key is exist.
	// Notes:
	//************************************
	static FS_BOOL KeyExist(FPD_Object objDict, const char* key);

	//************************************
	// Function:  GetStartPosition
	// Param[in]: objDict		The input PDF dictionary object.
	// Return:    The position for the first element.
	// Remarks:   Gets the position for the first element.
	// Notes:
	//************************************
	static FS_POSITION GetStartPosition(FPD_Object objDict);

	//************************************
	// Function:  GetNextElement
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in,out]:outPos		Input current position and receive the next position.
	// Param[out]:outKey		It receives the current key string.
	// Return:    The direct reference to the current element.
	// Remarks:   Gets a direct reference to the element and move the position to next. 
	//            Don't free the returned object.
	// Notes:
	//************************************
	static FPD_Object GetNextElement(FPD_Object objDict, FS_POSITION* outPos, FS_ByteString* outKey);

	//************************************
	// Function:  SetAt
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: obj			The input element data.
	// param[in] objs			The indirect object collection, required if obj is an indirect object. In this case,
	//							a reference object will be created and inserted into the dictionary. If not requied, sets it as NULL.
	// Return:    void
	// Remarks:   Sets element data. Please note all elements will be managed with the dictionary object, 
	//            so the object pointer must NOT be freed by caller.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void	SetAt(FPD_Object objDict, const char* key, FPD_Object obj, FPD_Document objs);


	//************************************
	// Function:  SetAtName
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: szName		The name string.
	// Return:    void
	// Remarks:   Sets a string of name object for the element specified by key.
	// Notes:
	//************************************
	static void	SetAtName(FPD_Object objDict, const char* key, FS_LPCSTR szName);

	//************************************
	// Function:  SetAtString
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: str			The input string.
	// Return:    void
	// Remarks:   Sets a string of string object for the element specified by key.
	// Notes:
	//************************************
	static void	SetAtString(FPD_Object objDict, const char* key, FS_ByteString str);

	//************************************
	// Function:  SetAtInteger
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: i				The input integer.
	// Return:    void
	// Remarks:   Sets an integer of number object for the element specified by key.
	// Notes:
	//************************************
	static void	SetAtInteger(FPD_Object objDict, const char* key, FS_INT32 i);

	//************************************
	// Function:  SetAtNumber
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: f				The input FIX24.8 value.
	// Return:    void
	// Remarks:   Sets a FIX24.8 of number object for the element specified by key.
	// Notes:
	//************************************
	static void	SetAtNumber(FPD_Object objDict, const char* key, FS_FLOAT f);

	//************************************
	// Function:  SetAtReferenceToDoc
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: doc			The indirect objects collection for the reference object.
	// Param[in]: objNum		The referred object number for the reference object.
	// Return:    void
	// Remarks:   Sets a reference object for the element specified by key.
	// Notes:
	//************************************
	static void	SetAtReferenceToDoc(FPD_Object objDict, const char* key, FPD_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  SetAtReferenceToFDFDoc
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: doc			The indirect objects collection for the reference object.
	// Param[in]: objNum		The referred object number for the reference object.
	// Return:    void
	// Remarks:   Sets a reference object for the element specified by key.
	// Notes:
	//************************************
	static void	SetAtReferenceToFDFDoc(FPD_Object objDict, const char* key, FDF_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  SetAtReference2ToDoc
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: doc			The indirect objects collection for the reference object.
	// Param[in]: obj			The referred object pointer for the reference object.
	// Return:    void
	// Remarks:   Sets a reference object for the element specified by key.
	// Notes:
	//************************************
	static void	SetAtReference2ToDoc(FPD_Object objDict, const char* key, FPD_Document doc, FPD_Object obj);

	//************************************
	// Function:  SetAtReference2ToFDFDoc
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: doc			The indirect objects collection for the reference object.
	// Param[in]: obj			The referred object pointer for the reference object.
	// Return:    void
	// Remarks:   Sets a reference object for the element specified by key.
	// Notes:
	//************************************
	static void	SetAtReference2ToFDFDoc(FPD_Object objDict, const char* key, FDF_Document doc, FPD_Object obj);

	//************************************
	// Function:  SetAtRect
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: rect			The input rectangle.
	// Return:    void
	// Remarks:   Sets a rectangle for the element specified by key.
	// Notes:
	//************************************
	static void	SetAtRect(FPD_Object objDict, const char* key, FS_FloatRect rect);

	//************************************
	// Function:  SetAtMatrix
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: matrix		The input matrix.
	// Return:    void
	// Remarks:   Sets a matrix for the element specified by key.
	// Notes: 
	//************************************
	static void	SetAtMatrix(FPD_Object objDict, const char* key, FS_AffineMatrix matrix);

	//************************************
	// Function:  SetAtBoolean
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: value			The input boolean value.
	// Return:    void
	// Remarks:   Sets a boolean value of boolean object for the element specified by key.
	// Notes:
	//************************************
	static void	SetAtBoolean(FPD_Object objDict, const char* key, FS_BOOL value);

	//************************************
	// Function:  RemoveAt	
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Return:    void
	// Remarks:   Removes the element specified by key.
	// Notes:
	//************************************
	static void	RemoveAt(FPD_Object objDict, const char* key);

	//************************************
	// Function:  ReplaceKey
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: oldkey		The old key string.
	// Param[in]: newKey		The new key string.
	// Return:    void
	// Remarks:   Replaces the key of the element specified by key with new key string.
	// Notes:
	//************************************
	static void	ReplaceKey(FPD_Object objDict, const char* oldkey, const char* newKey);

	//************************************
	// Function:  Identical
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: otherDict		The another dictionary.
	// Return:    Non-zero means identical, otherwise not identical.
	// Remarks:   Compares value with another object.
	// Notes:
	//************************************
	static FS_BOOL Identical(FPD_Object objDict, FPD_Object otherDict);

	//************************************
	// Function:  GetCount
	// Param[in]: objDict		The input PDF dictionary object.
	// Return:    The number of elements in the dictionary.
	// Remarks:   Gets the number of elements in the dictionary.
	// Notes:
	//************************************
	static FS_INT32	GetCount(FPD_Object objDict);

	//************************************
	// Function:  AddValue
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key.
	// Param[in]: obj			The input value.
	// Return:    void
	// Remarks:   Adds a key-value pair to the dictionary, assuming there is no duplicated key existing.
    //	          This is a function for quickly building up the whole dictionary, but should be used
	//         	  with care. If duplicate key happens, only the first value will prevail.
	// Notes:
	//************************************
	static void	AddValue(FPD_Object objDict, const char* key, FPD_Object obj);

    //************************************
    // Function:  GetBoolean2
    // Param[in]: objDict		The input PDF dictionary object.
    // Param[in]: key			The input key string.
    // Param[in]: bDefault		The default return value.
    // Return:    A boolean value for the specified element.
    // Remarks:   Gets the boolean data for the element specified by key with a default boolean value.
    // Notes:
    //************************************
    static FS_BOOL GetBoolean2(FPD_Object objDict, const char* key,FS_BOOL bDefault);

	//************************************
	// Function:  SetAtName2
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: szName		The name string.
	// Return:    void
	// Remarks:   Sets a string of name object for the element specified by key.
	// Notes:
	//************************************
	static void	SetAtName2(FPD_Object objDict, const char* key, FS_ByteString szName);
	
	//************************************
	// Function:  SetNewAt
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: object_type	The type of the object, one of the FPD_OBJ_xxxx constants.
	// Return:    FPD_Object   A pdf object, it may be null when object's type is invalid.
	// Remarks:   Allocate by object_type and set object element at specified position.
	// Takes ownership of the object created internally when object does not exist, returns an unowned pdf object pointer.
	// Notes:
	//************************************
	static FPD_Object SetNewAt(FPD_Object objDict, FS_LPCSTR key, FS_INT32 object_type);
	
	//************************************
	// Function:  AddReference
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: pDoc	        The input FPD_Document.
	// Param[in]: objnum	    The referred object number for the reference object.
	// Return:    void
	// Remarks:   Add a reference object for the element specified by key.
	// Notes:
	//************************************
	static void					AddReference(FPD_Object objDict, FS_LPCSTR key, FPD_Document pDoc, FS_DWORD objnum);
	
	 //************************************
	 // Function:  GetString2
	 // Param[in]: objDict		The input PDF dictionary object.
	 // Param[in]: key			The input key string.
	 // Param[in]: default_str	The default string.
	 // Param[out]: outStr	    A byte string for the specified element.
	 // Return:    void
	 // Remarks:   Get the string data for the element specified by key with a default string additionally.
	 // Notes:
	 //************************************
	static void GetString2(FPD_Object objDict, FS_LPCSTR key, FS_LPCSTR default_str,FS_ByteString* outStr);

	//************************************
	// Function:  Release
	// Param[in]: objDict		The input PDF dictionary object.	
	// Return:    void
	// Remarks:   Release (free, destroy) the object. This function has no effect to indirect objects.
	// Notes:
	//************************************
	static void	Release(FPD_Object objDict);

	 //************************************
	 // Function:  SetAtString2
	 // Param[in]: objDict		The input PDF dictionary object.
	 // Param[in]: key		    The input key string.	
	 // Param[in]: wsStr		The input wide string.	
	 // Param[in]: bUTF8		Whether the wide string is saved as UTF-8 encoding or not in PDF.
	 // Return:    void
	 // Remarks:   Set a wide string of string object for the element specified by key.
	 // Notes: Only the PDF2.0 supports for the UTF-8 Unicode character encoding scheme.
	 //************************************
	static void	 SetAtString2(FPD_Object objDict, FS_LPCSTR key, FS_LPCWSTR wsStr, FS_BOOLEAN bUTF8);

	 //************************************
	 // Function:  MoveData
	 // Param[in]: objDict		The input PDF dictionary object.
	 // Param[in]: pSrcDict		The another dictionary.	
	 // Return:    void
	 // Remarks:   Replace all dictionary data with those within another dictionary. Clear the given dictionary.
	 // Notes: 
	 //************************************
	static void	MoveData(FPD_Object objDict, FPD_Object pSrcDict);
	
	 //************************************
	 // Function:  SetAt2
	 // Param[in]: objDict		The input PDF dictionary object.
	 // Param[in]: key		    The input key string.
	 // Param[in]: pObj		    The input element data.
	 // Param[in]: fpdDoc		The input FPD_Document.
	 // Return:    void
	 // Remarks:  Setting element data. Please note all elements will be managed with the dictionary object, so the object pointer
	 // must NOT be freed by caller.
	 // Notes: 
	 //************************************
	static void	SetAt2(FPD_Object objDict, FS_LPCSTR key, FPD_Object pObj, FPD_Document fpdDoc);
	
	 //************************************
	 // Function:  RemoveAt2
	 // Param[in]: objDict		The input PDF dictionary object.
	 // Param[in]: key		    The input key string.
	 // Param[in]: bRelease		true for releasing value.
	 // Return:    void
	 // Remarks:  Remove the element specified by key.
	 // Notes: 
	 //************************************
	static void	RemoveAt2(FPD_Object objDict, FS_LPCSTR key, FS_BOOLEAN bRelease);
	
	 //************************************
	 // Function:  AddReference2
	 // Param[in]: objDict		The input PDF dictionary object.
	 // Param[in]: key			The input key string.
	 // Param[in]: pDoc	        The input FPD_Document.
	 // Param[in]: obj	        The referred object pointer for the reference object.
	 // Return:    void
	 // Remarks:  Add a reference object for the element specified by key.
	 // Notes:
	 //************************************
	static void	AddReference2(FPD_Object objDict, FS_LPCSTR key, FPD_Document pDoc, FPD_Object obj);

	//************************************
	// Function:  GetInteger64
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.	
	// Return:    FS_INT64
	// Remarks:  Get a 64-bit integer value for the specified element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	//************************************
	static FS_INT64 GetInteger64(FPD_Object objDict, FS_LPCSTR key);

	//************************************
	// Function:  GetInteger64ByDefault
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.	
	// Param[in]: default_int	The default integer value.
	// Return:    FS_INT64
	// Remarks:  Get a 64-bit integer value for the specified element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	//************************************
	static FS_INT64	GetInteger64ByDefault(FPD_Object objDict, FS_LPCSTR key, FS_INT64 default_int);
	
	//************************************
	// Function:  GetName
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.	
	// Return:    FPD_Object    Return a name object.
	// Remarks:  Get a dictionary object specified by key.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	//************************************
	static FPD_Object	GetName(FPD_Object objDict, FS_LPCSTR key);

	//************************************
	// Function:  SetAt3
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key		    The input key string.
	// Param[in]: pObj		    The input element data.
	// Param[in]: fpdDoc		The input FPD_Document.
	// Return:    void
	// Remarks:  Setting element data. Please note all elements will be managed with the dictionary object, so the object pointer
	// must NOT be freed by caller.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static void SetAt3(FPD_Object objDict, FS_LPCSTR key, FPD_Object pObj, FDF_Document doc);

	//************************************
	// Function:  AddReference3
	// Param[in]: objDict		The input PDF dictionary object.
	// Param[in]: key			The input key string.
	// Param[in]: pDoc	        The input FDF_Document.
	// Param[in]: objnum	    The referred object number for the reference object.
	// Return:    void
	// Remarks:   Add a reference object for the element specified by key.
	// Notes:
	//************************************
	static void	AddReference3(FPD_Object objDict, FS_LPCSTR key, FDF_Document pDoc, FS_DWORD objnum);

	//************************************
	 // Function:  AddReference4
	 // Param[in]: objDict		The input PDF dictionary object.
	 // Param[in]: key			The input key string.
	 // Param[in]: pDoc	        The input FDF_Document.
	 // Param[in]: obj	        The referred object pointer for the reference object.
	 // Return:    void
	 // Remarks:  Add a reference object for the element specified by key.
	 // Notes:
	 //************************************
	static void	AddReference4(FPD_Object objDict, FS_LPCSTR key, FDF_Document pDoc, FPD_Object obj);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*									CFPD_Stream_V1												*/ 
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_Stream_V1
{
public:
	//************************************
	// Function:  New
	// Return:    A stream object.
	// Remarks:   Creates a new empty stream object.
	// Notes:	  Destroys the stream object through <a>FPDObjectDestroy</a>();
	//************************************
	static FPD_Object New(void);

	//************************************
	// Function: InitStream
	// param[in] pData			The stream data to initialize with.
	// param[in] size			the size in bytes of the stream data.
	// param[in] dictionary	The input dictionary for the stream object.
	// Return:   void
	// Remarks: Initializes a stream with data and dictionary.  
	// If no dictionary specified, the old dictionary is retained.
	// Notes:	  
	//************************************
	static void InitStream(FPD_Object objStream, FS_BYTE* pData, FS_DWORD size, FPD_Object dictionary);

	//************************************
	// Function:  GetDict
	// Param[in]: objStream		The input stream object.
	// Return:    The dictionary of the stream object.
	// Remarks:   Gets the dictionary of the stream object.
	// Notes:
	//************************************
	static FPD_Object GetDict(FPD_Object objStream);

	//************************************
	// Function:  SetData
	// Param[in]: objStream		The input stream object.
	// Param[in]: pData			The stream data to set.
	// Param[in]: size			The size in bytes of the stream data.
	// Param[in]: bCompressed	Whether the data is compressed.
	// param[in]  bKeepBuf		Whether the buffer will be maintained by the stream object.
	// Return:    void
	// Remarks:   Sets stream data. If <param>pData</param> is <a>NULL</a>, just allocate stream buffer.
    //            The data can be uncompressed or compressed. If it's uncompressed, then previous filter
	//            info will be dropped (if any). If it's compressed, the caller should also maintain
	//            the filter information in the dictionary.
	// Notes:
	//************************************
	static void	SetData(FPD_Object objStream, FS_LPBYTE pData, FS_DWORD size, FS_BOOL bCompressed, FS_BOOL bKeepBuf);

	//************************************
	// Function:  Identical
	// Param[in]: objStream		The input stream object.
	// Param[in]: other_stm		The another stream object.	
	// Return:    Non-zero means identical, otherwise not identical.
	// Remarks:   Compares value with another object.
	// Notes:
	//************************************
	static FS_BOOL Identical(FPD_Object objStream, FPD_Object other_stm);

	//************************************
	// Function:  GetStreamFilter
	// Param[in]: objStream		The input stream object.
	// Param[in]: bRaw			Whether the stream filter will do decoding.
	// Return:    A stream filter object.
	// Remarks:   Creates a stream-based data filter from the PDF stream.
    //            The filter can output either raw data (decrypted) or decoded data.
	//            JBIG2 and JPEG2000 decoding not supported.
	//            Caller must destroy the created filter.
	// Notes:
	//************************************
	static FPD_StreamFilter GetStreamFilter(FPD_Object objStream, FS_BOOL bRaw);


	//************************************
	// Function:  GetRawSize
	// Param[in]: objStream		The input stream object.
	// Return:    The raw data size in bytes.
	// Remarks:   Gets the raw data size in bytes.
	// Notes:
	//************************************
	static FS_DWORD GetRawSize(FPD_Object objStream);

	//************************************
	// Function:  ReadRawData
	// Param[in]: objStream		The input stream object.
	// Param[in]: start_pos		The start position in the stream data to read from.
	// Param[out]: pBuf			The buffer to receive the read data.
	// Param[in]: bufSize		The size in bytes expected to read.
	// Return:    Non-zero means successful, otherwise failed.
	// Remarks:   Reads raw data. 
	// Notes:
	//************************************
	static FS_BOOL ReadRawData(FPD_Object objStream, FS_DWORD start_pos, FS_LPBYTE pBuf, FS_DWORD bufSize);

	//************************************
	// Function:  IsMemoryBased
	// Param[in]: objStream		The input stream object.
	// Return:    <a>TRUE</a> for the stream data being memory-based.
	// Remarks:   Test whether the stream data is memory-based.
	// Notes:
	//************************************
	static FS_BOOL IsMemoryBased(FPD_Object objStream);

    //************************************
    // Function:  Clone
    // Param[in]: objStream		The input stream object.
    // Param[in]: bDirect		Whether a totally direct copy is requested, affect indirect object.
    // Param[in]: lpfCallback	Callback function is used to create file stream object for CPDF_Stream.
    // Param[in]: pUserData		User private data pointer passed to callback function.
    // Return:    A complete clone object.
    // Remarks:   Get a complete clone.
    // Notes:
    //************************************
    static FPD_Object Clone(FPD_Object objStream, FS_BOOL bDirect, FPD_LPFCloneStreamCallback lpfCallback, FS_LPVOID pUserData);

	 //************************************
	 // Function:  Create
	 // Param[in]: pData			Pointer to the memory buffer.
	 // Param[in]: size			    The size in bytes of the memory buffer.
	 // Param[in]: pDict			The input dictionary for the stream object.
	 // Return:    FPD_Object
	 // Remarks:   Create a stream object from a memory buffer, with a dictionary.
	 // Notes:
	 //************************************
	static FPD_Object	Create(FS_LPBYTE pData, FS_UINT size, FPD_Object pDict);
	
	 //************************************
	 // Function:  New2
	 // Param[in]: pFile		The file access interface.
	 // Param[in]: pCrypto		The encrypt-handler of the stream data in the file.	 
	 // Param[in]: offset		The offset in the file.
	 // Param[in]: size			The size in bytes of the stream data.
	 // Param[in]: pDict		The input dictionary for the stream object.
	 // Param[in]: gennum		The generation number for the stream object.
	 // Return:    FPD_Object
	 // Remarks:   Construct a file based stream. May be encrypted. The dictionary is taken by the stream.
	 // Notes: It need to call FSFileReadHandlerDestroy after relase stream object.
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	 //************************************
	static FPD_Object New2(FS_FileReadHandler pFile, FPD_CustomCryptoHandler pCrypto,
		FS_INT64 offset, FS_INT64 size, FPD_Object pDict, FS_DWORD gennum);
	
	 //************************************
	 // Function:  SetStreamFile
	 // Param[in]: objStream	The input stream object.
	 // Param[in]: pFile		The file access interface.
	 // Param[in]: offset		The offset in the file.
	 // Param[in]: size			The size in bytes of the stream data.
	 // Param[in]: bCompressed	The flag to determine if stream need to be compressed during export. 
	 // Param[in]: bKeepFile	Whether need to release file stream when stream destructed.
	 // Return:    FPD_Object
	 // Remarks:  Set stream file.
	 // Notes: If bKeepFile set false, it need to call FSFileReadHandlerDestroy after relase stream object.
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	 //************************************
	static void	 SetStreamFile(FPD_Object objStream, FS_FileReadHandler pFile, FS_INT64 offset, FS_INT64 size, FS_BOOLEAN bCompressed, FS_BOOLEAN bKeepFile);

	//************************************
	// Function:  DecryptStream
	// Param[in]: objStream		The input stream object.
	// Param[in]: pFileWrite		The decrypted data to the end.		 
	// Return:    FS_BOOLEAN   Non-zero means success, otherwise failure.
	// Remarks:   Decrypt stream data to a file stream.
	// Notes: It need to call FSFileReadHandlerDestroy after relase stream object.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1
	//************************************
	static FS_BOOLEAN     DecryptStream(FPD_Object objStream, FS_FileWriteHandler pFileWrite);
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
/*								CFPD_StreamAcc_V1												*/ 
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_StreamAcc_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    The accessor of stream object.
	// Remarks:   Creates the accessor of stream object.
	// Notes:
	//************************************
	static FPD_StreamAcc New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: stmAcc		The input accessor of stream object.
	// Return:    void
	// Remarks:   Destroys the accessor of stream object.
	// Notes:
	//************************************
	static void	Destroy(FPD_StreamAcc stmAcc);

	//************************************
	// Function:  LoadAllData
	// Param[in]: stmAcc			The input accessor of stream object.
	// Param[in]: obj				The stream object to be attached to.
	// Param[in]: bRawAccess		Whether access the stream data rawly.
	// Param[in]: estimated_size	The estimated size in bytes of the loaded stream data.
	// Param[in]: bImageAcc			Whether access the image filter or not.
	// Return:    void
	// Remarks:   Must call this function to actually attach to a stream.
	// Notes:
	//************************************
	static void	LoadAllData(FPD_StreamAcc stmAcc, 
		FPD_Object obj, 
		FS_BOOL bRawAccess, 
		FS_DWORD estimated_size, 
		FS_BOOL bImageAcc);

	//************************************
	// Function:  GetStream
	// Param[in]: stmAcc		The input accessor of stream object.
	// Return:    The stream object attached to.
	// Remarks:   Gets the stream object attached to.
	// Notes:
	//************************************
	static FPD_Object GetStream(FPD_StreamAcc stmAcc);

	//************************************
	// Function:  GetDict
	// Param[in]: stmAcc		The input accessor of stream object.
	// Return:    The dictionary of the stream object attached to.
	// Remarks:	  Gets the dictionary of the stream object attached to.
	// Notes:
	//************************************
	static FPD_Object GetDict(FPD_StreamAcc stmAcc);

	//************************************
	// Function:  GetData
	// Param[in]: stmAcc		The input accessor of stream object.
	// Return:    The loaded data pointer.
	// Remarks:   Gets the loaded data pointer.
	// Notes:
	//************************************
	static FS_LPCBYTE GetData(FPD_StreamAcc stmAcc);

	//************************************
	// Function:  GetSize
	// Param[in]: stmAcc		The input accessor of stream object.
	// Return:    The loaded data size in bytes.
	// Remarks:   Gets the loaded data size in bytes.
	// Notes:
	//************************************
	static FS_DWORD	GetSize(FPD_StreamAcc stmAcc);

	//************************************
	// Function:  DetachData
	// Param[in]: stmAcc		The input accessor of stream object.
	// Return:    The data buffer from this stream accessor.
	// Remarks:   Detaches the data buffer from this stream accessor.
	//            After this call, the caller is now responsible for releasing the data buffer.
	// Notes:
	//************************************
	static FS_LPBYTE DetachData(FPD_StreamAcc stmAcc);

	//************************************
	// Function:  GetImageDecoder
	// Param[in]: stmAcc		The input accessor of stream object.
	// Return:    The image decoder name.
	// Remarks:   Gets the image decoder name.
	// Notes:
	//************************************
	static char* GetImageDecoder(FPD_StreamAcc stmAcc);

	//************************************
	// Function:  GetImageParam
	// Param[in]: stmAcc		The input accessor of stream object.
	// Return:    The image params dictionary.
	// Remarks:   Gets the image params dictionary.
	// Notes:
	//************************************
	static FPD_Object GetImageParam(FPD_StreamAcc stmAcc);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*								CFPD_StreamFilter_V1												*/ 
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_StreamFilter_V1
{
public:
	//************************************
	// Function:  Destroy
	// Param[in]: flt		The input data filter created for accessing PDF stream data.
	// Return:    void
	// Remarks:   Destroys the data filter created for accessing PDF stream data.
	// Notes:
	//************************************
	static void	Destroy(FPD_StreamFilter flt);
	
	//************************************
	// Function:  ReadBlock
	// Param[in]: flt		The input data filter created for accessing PDF stream data.
	// Param[out]:buffer	It receives the read data.
	// Param[in]: size		The size in bytes to read.
	// Return:    The number of bytes actually read.
	// Remarks:   Reads a data block. Return number of bytes actually read.
	//            If read size is less than the asked size, it indicates EOF.
	// Notes:
	//************************************
	static FS_DWORD	ReadBlock(FPD_StreamFilter flt, FS_LPBYTE buffer, FS_DWORD size);

	//************************************
	// Function:  GetSrcPos
	// Param[in]: flt		The input data filter created for accessing PDF stream data.
	// Return:    The current source position (in the raw data stream). 
	// Remarks:   Gets current source position (in the raw data stream). 
	// Notes:
	//************************************
	static FS_DWORD	GetSrcPos(FPD_StreamFilter flt);

	//************************************
	// Function:  GetStream
	// Param[in]: flt		The input data filter created for accessing PDF stream data.
	// Return:    The stream object.
	// Remarks:   Gets the stream object.
	// Notes:
	//************************************
	static FPD_Object GetStream(FPD_StreamFilter flt);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*									CFPD_Null_V1													*/ 
//////////////////////////////////////////////////////////////////////////////////////////////////////

class CFPD_Null_V1
{
public:
	//************************************
	// Function:   New
	// Param[in]:  void
	// Return:     A null object.
	// Remarks:    Creates a null object.
	// Notes:
	//************************************
	static FPD_Object New(void);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*								CFPD_Reference_V1													*/ 
//////////////////////////////////////////////////////////////////////////////////////////////////////
class CFPD_Reference_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: doc		The indirect object collection.
	// Param[in]: objNum	The referred object number.
	// Return:    A reference object.
	// Remarks:   Creates a reference object with indirect object collection and referred object number.
	// Notes:
	//************************************
	static FPD_Object New(FPD_Document doc, FS_INT32 objNum);

	//************************************
	// Function:  New2
	// Param[in]: doc		The indirect object collection.
	// Param[in]: objNum	The referred object number.
	// Return:    A reference object.
	// Remarks:   Creates a reference object with indirect object collection and referred object number.
	// Notes:
	//************************************
	static FPD_Object New2(FDF_Document doc, FS_INT32 objNum);


	//************************************
	// Function:  GetRefObjNum
	// Param[in]: objReference		The input reference object.
	// Return:    The referred object number.
	// Remarks:   Gets the referred object number.
	// Notes:
	//************************************
	static FS_DWORD	GetRefObjNum(FPD_Object objReference);

	//************************************
	// Function:  SetRefToDoc
	// Param[in]: objReference		The input reference object.
	// Param[in]: doc				The new indirect object collection.
	// Param[in]: objNum			The new referred indirect object number.
	// Return:    void
	// Remarks:   Changes the reference.
	// Notes:
	//************************************
	static void	SetRefToDoc(FPD_Object objReference, FPD_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  SetRefToFDFDoc
	// Param[in]: objReference		The input reference object.
	// Param[in]: doc				The new indirect object collection.
	// Param[in]: objNum			The new referred indirect object number.
	// Return:    void
	// Remarks:   Changes the reference.
	// Notes:
	//************************************
	static void	SetRefToFDFDoc(FPD_Object objReference, FDF_Document doc, FS_DWORD objNum);

	//************************************
	// Function:  Identical
	// Param[in]: objReference		The input reference object.
	// Param[in]: otherReference	The another reference object.
	// Return:    Non-zero means identical, otherwise not identical.
	// Remarks:   Compares with another object.
	// Notes:
	//************************************
	static FS_BOOL Identical(FPD_Object objReference, FPD_Object otherReference);	
};



#ifdef __cplusplus
};
#endif

#endif//FPD_OBJSIMPL_H

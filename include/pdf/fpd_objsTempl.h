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
/* Object HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDObjectGetType
 * @details Gets type of the object.
 * @param[in]  obj The input PDF syntax objects.
 * @return   One of the FPD_OBJ_xxxx constants.
 * @note 
 */
INTERFACE(FS_INT32, FPDObjectGetType, (FPD_Object obj))

/**
 * @brief FPDObjectGetobjNum
 * @details Gets indirect number of the object. 0 for direct object.
 * @param[in]  obj The input PDF syntax objects.
 * @return   The indirect number of the object.
 * @note 
 */
INTERFACE(FS_DWORD, FPDObjectGetobjNum, (FPD_Object obj))

/**
 * @brief FPDObjectIsIdentical
 * @details Compares with another object.
 * @param[in]  obj The input PDF syntax objects.
 * @param[in]  otherObj The input object.
 * @return   Non-zero means identical, otherwise not identical.
 * @note 
 */
INTERFACE(FS_BOOL, FPDObjectIsIdentical, (FPD_Object obj,  FPD_Object otherObj))

/**
 * @brief FPDObjectClone
 * @details Gets a complete clone. The bDirect param specifies whether a totally direct copy
	*            is requested (without any reference inside, so the copy can be copied to other document).
 * @param[in]  srcObj The input PDF syntax objects.
 * @param[in]  bDirect Whether a totally direct copy is requested.
 * @return   A complete clone object.
 * @note 
 */
INTERFACE(FPD_Object, FPDObjectClone, (FPD_Object srcObj,  FS_BOOL bDirect))

/**
 * @brief FPDObjectCloneRefToDoc
 * @details Gets a clone for direct object, or a reference for document.
 * @param[in]  srcObj The input PDF syntax objects.
 * @param[in]  others The document.
 * @return   A clone direct object or a reference for document.
 * @note 
 */
INTERFACE(FPD_Object, FPDObjectCloneRefToDoc, (FPD_Object srcObj,  FPD_Document others))

/**
 * @brief FPDObjectCloneRefToFDFDoc
 * @details Gets a clone for direct object, or a reference for memory document.
 * @param[in]  srcObj The input PDF syntax objects.
 * @param[in]  others The memory document.
 * @return   A clone direct object or a reference for memory document.
 * @note 
 */
INTERFACE(FPD_Object, FPDObjectCloneRefToFDFDoc, (FPD_Object srcObj,  FDF_Document others))

/**
 * @brief FPDObjectGetDirect
 * @details Gets direct object (the object data itself) of an object.
	*            For direct object, return itself; for reference object, return the referred object.
 * @param[in]  obj The input PDF syntax objects.
 * @return   The direct object (the object data itself) of an object.
 * @note 
 */
INTERFACE(FPD_Object, FPDObjectGetDirect, (FPD_Object obj))

/**
 * @brief FPDObjectDestroy
 * @details Destroys the object. This function has no effect to indirect objects.
 * @param[in]  obj The input PDF syntax objects.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDObjectDestroy, (FPD_Object obj))

/**
 * @brief FPDObjectGetString
 * @details Gets string value of the object. Applicable to string, name, and number objects.
	*            If object type not supported, empty string is returned.
 * @param[in]  obj The input PDF syntax objects.
 * @param[out]  outString It receives the string value of the object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDObjectGetString, (FPD_Object obj,  FS_ByteString* outString))

/**
 * @brief FPDObjectGetUnicodeText
 * @details Gets Unicode text value of the object. Applicable to string and stream objects.
    *            If object type not supported, empty string is returned.
	*	          We assume the original text are encoding in PDF text encoding scheme.
	*	          The returned text is encoded in UTF-16LE encoding.
	*	          A character mapper can be used to convert the original text (if not already encoded in Unicode).
	*            If no character mapper used, PDFDocEncoding mapping is used.
 * @param[in]  obj The input PDF syntax objects.
 * @param[out]  outUnicodeText An Unicode text value.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDObjectGetUnicodeText, (FPD_Object obj,  FS_WideString* outUnicodeText))

/**
 * @brief FPDObjectGetNumber
 * @details Gets float number value of the object. Applicable to number objects only.
	*            If object type is not number, 0.0f is returned.
	*            FIX: when FIX format is used, the returned value will be in FIX24.8 format.
 * @param[in]  obj The input PDF syntax objects.
 * @return   The float number value of the object.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDObjectGetNumber, (FPD_Object obj))

/**
 * @brief FPDObjectGetInteger
 * @details Gets integer number value of the object. Applicable to number and boolean objects.
	*            If object type not supported, 0 is returned.
 * @param[in]  obj The input PDF syntax objects.
 * @return   The integer number value of the object.
 * @note 
 */
INTERFACE(FS_INT32, FPDObjectGetInteger, (FPD_Object obj))

/**
 * @brief FPDObjectGetDict
 * @details Gets dictionary value of the object. Applicable to dictionaries or stream only.
	*            <a>NULL</a> is returned for other types of objects.
 * @param[in]  obj The input PDF syntax objects.
 * @return   The dictionary value of the object.
 * @note 
 */
INTERFACE(FPD_Object, FPDObjectGetDict, (FPD_Object obj))

/**
 * @brief FPDObjectGetArray
 * @details Gets array value of the object. Applicable to arrays only.
	*            <a>NULL</a> is returned for non-array objects.
 * @param[in]  obj The input PDF syntax objects.
 * @return   The array value of the object.
 * @note 
 */
INTERFACE(FPD_Object, FPDObjectGetArray, (FPD_Object obj))

/**
 * @brief FPDObjectSetString
 * @details Sets string value into the object. Applicable to boolean, number, string and name objects.
	*            For non-supported object types, this function does nothing.
 * @param[in]  obj The input PDF syntax objects.
 * @param[in]  str The input string value.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDObjectSetString, (FPD_Object obj,  FS_LPCSTR str))

/**
 * @brief FPDObjectSetUnicodeText
 * @details Sets text encoded in Unicode (UTF-16LE format). Applicable to string and stream objects.
	*            "len" is number of characters, not bytes. -1 for null terminated string.
 * @param[in]  obj The input PDF syntax objects.
 * @param[in]  str Pointer to UTF-16LE format characters.
 * @param[in]  len Number of the input characters.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDObjectSetUnicodeText, (FPD_Object obj,  FS_LPCWSTR str,  FS_INT32 len))

/**
 * @brief FPDObjectGetDirectType
 * @details Gets type of direct object without loading it.
 * @param[in]  obj The input PDF syntax objects.
 * @return   The type of direct object without loading it.
 * @note 
 */
INTERFACE(FS_INT32, FPDObjectGetDirectType, (FPD_Object obj))

/**
 * @brief FPDObjectIsModified
 * @details Tests whether the object has been "modified".
 * @param[in]  obj The input PDF syntax objects.
 * @return   <a>TRUE</a> for the object having been "modified".
 * @note 
 */
INTERFACE(FS_BOOL, FPDObjectIsModified, (FPD_Object obj))

/**
 * @brief FPDObjectSetModified
 * @details Changes the object's "modified" flag.
 * @param[in]  obj The input PDF syntax objects.
 * @param[in]  bModified The "modified" flag. TRUE means "modified".
 * @return   void
 * @note 
 */
INTERFACE(void, FPDObjectSetModified, (FPD_Object obj,  FS_BOOL bModified))

/**
 * @brief FPDObjectGetContainer
 * @details Gets the container of this object.
 * @param[in]  obj The input PDF syntax objects.
 * @return   The container of this object.
 * @note 
 */
INTERFACE(FPD_Object, FPDObjectGetContainer, (FPD_Object obj))

/**
 * @brief FPDObjectSetContainer
 * @details Sets the container of this object.
 * @param[in]  obj The input PDF syntax objects.
 * @param[in]  container The container of this object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDObjectSetContainer, (FPD_Object obj,  FPD_Object container))

/**
 * @brief FPDObjectParseString
 * @details Parses an object from a memory buffer.
 * @param[in]  str A string containing the object
 * @return   A parsed object, or <a>NULL</a> if error.
 * @note Parsing indirect reference inside the string will
	* bring undefined result.
 */
INTERFACE(FPD_Object, FPDObjectParseString, (FS_LPCSTR str))

/**
 * @brief FPDObjectGetConstString
 * @details Get string value of the object.
 * @param[in]  obj The input PDF syntax objects.
 * @return   FS_LPCSTR
 * @note Only applicable to string and name.
 */
INTERFACE(FS_LPCSTR, FPDObjectGetConstString, (FPD_Object obj))

/**
 * @brief FPDObjectIsNewCreated
 * @details Whether the object was created newly.
 * @param[in]  obj The input PDF syntax objects.
 * @return   FS_BOOLEAN   true for being created newly, false for obtaining form cache.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDObjectIsNewCreated, (FPD_Object obj))

/**
 * @brief FPDObjectGetUnicodeText2
 * @details Gets Unicode text value of the object. Applicable to string and stream objects.
	*            If object type not supported, empty string is returned.
	*	           We assume the original text are encoding in PDF text encoding scheme.
	*	           The returned text is encoded in UTF-16LE encoding.
	*	           A character mapper can be used to convert the original text (if not already encoded in Unicode).
	*            If no character mapper used, PDFDocEncoding mapping is used.
 * @param[in]  obj The input PDF syntax objects.
 * @param[in]  pCharMap The input character mapper.
 * @param[in]  encoding The input encoding.
 * @param[out]  outUnicodeText An Unicode text value.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDObjectGetUnicodeText2, (FPD_Object obj,  FS_CharMap pCharMap,  FS_LPCSTR encoding,  FS_WideString* outUnicodeText))

/**
 * @brief FPDObjectDeepClone
 * @details Deep clone the objects.
 * @param[in]  obj The input PDF syntax objects.
 * @param[in]  pDocObjs The input FPD_Document.
 * @param[in]  pPred The input FPD_ClonePredicateHandler.
 * @param[out]  outkeyArray Get the deep obj numbers.
 * @param[out]  outObjNumberArray Get the deep obj numbers.
 * @return   FPD_Object   true for being created newly, false for obtaining form cache.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
 */
INTERFACE(FPD_Object, FPDObjectDeepClone, (FPD_Object obj,  FPD_Document pDocObjs,  FPD_ClonePredicateHandler pPred,  FS_DWordArray* outkeyArray,  FS_DWordArray* outObjNumberArray))

/**
 * @brief FPDObjectCreateClonePredicateHandler
 * @details Create FPD_ClonePredicateHandler obj.
 * @param[in]  callbacks The input FPD_ClonePredicateCallbacks object.
 * @return   FPD_ClonePredicateHandler
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
 */
INTERFACE(FPD_ClonePredicateHandler, FPDObjectCreateClonePredicateHandler, (FPD_ClonePredicateCallbacks callbacks))

/**
 * @brief FPDObjectDestroyClonePredicateHandler
 * @details Destroy FPD_ClonePredicateHandler obj.
 * @param[in]  handler The input FPD_ClonePredicateHandler object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
 */
INTERFACE(void, FPDObjectDestroyClonePredicateHandler, (FPD_ClonePredicateHandler handler))

NumOfSelector(FPDObject)
ENDENUM

//*****************************
/* Boolean HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDBooleanNew
 * @details Creates a boolean object from a single boolean value.
 * @param[in]  value A boolean value.
 * @return   A boolean object.
 * @note 
 * @see FPDObjectDestroy
 */
INTERFACE(FPD_Object, FPDBooleanNew, (FS_BOOL value))

/**
 * @brief FPDBooleanIdentical
 * @details Compares with another boolean object.
 * @param[in]  ObjBoolean The boolean object.
 * @param[in]  otherBoolean The other boolean object.
 * @return   Non-zero means identical, otherwise not identical.
 * @note 
 */
INTERFACE(FS_BOOL, FPDBooleanIdentical, (FPD_Object ObjBoolean,  FPD_Object otherBoolean))

NumOfSelector(FPDBoolean)
ENDENUM

//*****************************
/* Number HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDNumberNewByInt
 * @details Creates a number object from an integer.
 * @param[in]  value The input integer.
 * @return   A number object.
 * @note 
 * @see FPDObjectDestroy
 * @see FPDNumberNewByFloat
 * @see FPDNumberNewByStr
 * @see FPDNumberNewFromData
 */
INTERFACE(FPD_Object, FPDNumberNewByInt, (FS_INT32 value))

/**
 * @brief FPDNumberNewByFloat
 * @details Creates a number object from a floating-point value.
 * @param[in]  value The input floating-point.
 * @return   A number object.
 * @note 
 * @see FPDObjectDestroy
 * @see FPDNumberNewByInt
 * @see FPDNumberNewByStr
 * @see FPDNumberNewFromData
 */
INTERFACE(FPD_Object, FPDNumberNewByFloat, (FS_FLOAT value))

/**
 * @brief FPDNumberNewByStr
 * @details Creates a number object from a non-buffered byte string.
 * @param[in]  pStr The input non-buffered byte string.
 * @return   A number object.
 * @note 
 * @see FPDObjectDestroy
 * @see FPDNumberNewByFloat
 * @see FPDNumberNewByInt
 * @see FPDNumberNewFromData
 */
INTERFACE(FPD_Object, FPDNumberNewByStr, (FS_LPCSTR pStr))

/**
 * @brief FPDNumberNewFromData
 * @details Creates a number object from data.
 * @param[in]  bInteger Whether the input data is actually an integer.
 * @param[in]  pData The input data.
 * @return   A number object.
 * @note 
 * @see FPDObjectDestroy
 * @see FPDNumberNewByFloat
 * @see FPDNumberNewByStr
 * @see FPDNumberNewByInt
 */
INTERFACE(FPD_Object, FPDNumberNewFromData, (FS_BOOL bInteger,  void* pData))

/**
 * @brief FPDNumberIdentical
 * @details Compares with another number object.
 * @param[in]  objNumber The input number object.
 * @param[in]  other_number The other number object.
 * @return   Non-zero means identical, otherwise not identical.
 * @note 
 */
INTERFACE(FS_BOOL, FPDNumberIdentical, (FPD_Object objNumber,  FPD_Object other_number))

/**
 * @brief FPDNumberGetString
 * @details Gets a byte string from this object.
 * @param[in]  objNumber The input number object.
 * @param[out]  outResult A byte string from this object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDNumberGetString, (FPD_Object objNumber,  FS_ByteString* outResult))

/**
 * @brief FPDNumberSetString
 * @details Sets a non-buffered byte string.
 * @param[in]  objNumber The input number object.
 * @param[in]  str The input non-buffered byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDNumberSetString, (FPD_Object objNumber,  FS_LPSTR str))

/**
 * @brief FPDNumberIsInteger
 * @details Whether the number is an integer.
 * @param[in]  objNumber The input number object.
 * @return   <a>TRUE</a> for the number being an integer.
 * @note 
 */
INTERFACE(FS_BOOL, FPDNumberIsInteger, (FPD_Object objNumber))

/**
 * @brief FPDNumberGetInteger
 * @details Gets the integer value.
 * @param[in]  objNumber The input number object.
 * @return   The integer value.
 * @note 
 */
INTERFACE(FS_INT32, FPDNumberGetInteger, (FPD_Object objNumber))

/**
 * @brief FPDNumberGetNumber
 * @details Gets the FIX24.8 value.
 * @param[in]  objNumber The input number object.
 * @return   The FIX24.8 value.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDNumberGetNumber, (FPD_Object objNumber))

/**
 * @brief FPDNumberSetNumber
 * @details Sets a FIX24.8 value.
 * @param[in]  objNumber The input number object.
 * @param[in]  value The input FIX24.8 value.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDNumberSetNumber, (FPD_Object objNumber,  FS_FLOAT value))

/**
 * @brief FPDNumberGetFloat
 * @details Gets the floating-point value.
 * @param[in]  objNumber The input number object.
 * @return   The floating-point value.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDNumberGetFloat, (FPD_Object objNumber))

/**
 * @brief FPDNumberNewByFloat2
 * @details Creates a number object from a floating-point value.
 * @param[in]  value The input floating-point.
 * @param[in]  precision The number of decimal digits.Default value : 0.
 * @return   A number object.
 * @note 
 * @see FPDObjectDestroy
 * @see FPDNumberNewByInt
 * @see FPDNumberNewByStr
 * @see FPDNumberNewFromData
 */
INTERFACE(FPD_Object, FPDNumberNewByFloat2, (FS_FLOAT value,  FS_BYTE precison))

NumOfSelector(FPDNumber)
ENDENUM

//*****************************
/* String HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDStringNew
 * @details Creates a string object from a byte string.
 * @param[in]  str The input byte string.
 * @param[in]  bHex The input hex flag.
 * @return   A string object.
 * @note 
 * @see FPDObjectDestroy
 */
INTERFACE(FPD_Object, FPDStringNew, (FS_ByteString str,  FS_BOOL bHex))

/**
 * @brief FPDStringNewW
 * @details Creates a string object from a wide string.
 * @param[in]  wstr The input wide string.
 * @return   A string object.
 * @note 
 * @see FPDObjectDestroy
 */
INTERFACE(FPD_Object, FPDStringNewW, (FS_LPCWSTR wstr))

/**
 * @brief FPDStringGetString
 * @details Gets a ref to the data of the string object.
 * @param[in]  objString The input string object.
 * @param[out]  outString It receives the ref to the data of the string object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDStringGetString, (FPD_Object objString,  FS_ByteString* outString))

/**
 * @brief FPDStringIdentical
 * @details Compares with another string object.
 * @param[in]  objString The input string object.
 * @param[in]  other_objString The other string object.
 * @return   Non-zero means identical, otherwise not identical.
 * @note 
 */
INTERFACE(FS_BOOL, FPDStringIdentical, (FPD_Object objString,  FPD_Object other_objString))

/**
 * @brief FPDStringSetHex
 * @details Changes the hex flag.
 * @param[in]  objString The input string object.
 * @param[in]  bHex The input hex flag.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDStringSetHex, (FPD_Object objString,  FS_BOOL bHex))

/**
 * @brief FPDStringIsHex
 * @details Tests whether this string object has the hex flag.
 * @param[in]  objString The input string object.
 * @return   <a>TRUE</a> for string object having the hex flag.
 * @note 
 */
INTERFACE(FS_BOOL, FPDStringIsHex, (FPD_Object objString))

NumOfSelector(FPDString)
ENDENUM

//*****************************
/* Name HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDNameNew
 * @details Creates a name object from a byte string.
 * @param[in]  str The input byte string.
 * @return   A name object.
 * @note 
 * @see FPDObjectDestroy
 */
INTERFACE(FPD_Object, FPDNameNew, (FS_LPCSTR str))

/**
 * @brief FPDNameGetString
 * @details Gets a ref to the data of the name object.
 * @param[in]  objName The input name object.
 * @param[out]  outString It receives the data of the name object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDNameGetString, (FPD_Object objName,  FS_ByteString* outString))

/**
 * @brief FPDNameIdentical
 * @details Compares with another name object.
 * @param[in]  objName The input name object.
 * @param[in]  other_objName The other name object.
 * @return   Non-zero means identical, otherwise not identical.
 * @note 
 */
INTERFACE(FS_BOOL, FPDNameIdentical, (FPD_Object objName,  FPD_Object other_objName))

NumOfSelector(FPDName)
ENDENUM

//*****************************
/* Array HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDArrayNew
 * @details Creates an empty array object.
 * @param[in]  void 
 * @return   An empty array object.
 * @note 
 * @see FPDObjectDestroy
 */
INTERFACE(FPD_Object, FPDArrayNew, (void))

/**
 * @brief FPDArrayGetCount
 * @details Gets the count of objects in the array.
 * @param[in]  objArray The input PDF array object.
 * @return   The count of objects in the array.
 * @note 
 */
INTERFACE(FS_DWORD, FPDArrayGetCount, (FPD_Object objArray))

/**
 * @brief FPDArrayGetElement
 * @details Gets reference to element. Returns direct reference to the element.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @return   Pointer to specified element.
 * @note Don't release the returned object.
 */
INTERFACE(FPD_Object, FPDArrayGetElement, (FPD_Object objArray,  FS_DWORD index))

/**
 * @brief FPDArrayGetElementValue
 * @details Gets direct or referred indirect object.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @return   A direct or referred indirect object.
 * @note Don't release the returned object.
 */
INTERFACE(FPD_Object, FPDArrayGetElementValue, (FPD_Object objArray,  FS_DWORD index))

/**
 * @brief FPDArrayGetMatrix
 * @details Gets a matrix from the array.
 * @param[in]  objArray The input PDF array object.
 * @return   A matrix from the array.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FPDArrayGetMatrix, (FPD_Object objArray))

/**
 * @brief FPDArrayGetRect
 * @details Gets a rectangle from the array.
 * @param[in]  objArray The input PDF array object.
 * @return   A rectangle from the array.
 * @note 
 */
INTERFACE(FS_FloatRect, FPDArrayGetRect, (FPD_Object objArray))

/**
 * @brief FPDArrayGetString
 * @details Gets a string with specified position.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[out]  outString A byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayGetString, (FPD_Object objArray,  FS_DWORD index,  FS_ByteString* outString))

/**
 * @brief FPDArrayGetInteger
 * @details Gets an integer with specified position.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @return   An integer.
 * @note 
 */
INTERFACE(FS_INT32, FPDArrayGetInteger, (FPD_Object objArray,  FS_DWORD index))

/**
 * @brief FPDArrayGetNumber
 * @details Gets a number with specified position.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @return   A FIX24.8 number.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDArrayGetNumber, (FPD_Object objArray,  FS_DWORD index))

/**
 * @brief FPDArrayGetDict
 * @details Gets a dictionary object with specified position.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @return   A dictionary object.
 * @note 
 */
INTERFACE(FPD_Object, FPDArrayGetDict, (FPD_Object objArray,  FS_DWORD index))

/**
 * @brief FPDArrayGetStream
 * @details Gets a stream object with specified position.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @return   A stream object.
 * @note 
 */
INTERFACE(FPD_Object, FPDArrayGetStream, (FPD_Object objArray,  FS_DWORD index))

/**
 * @brief FPDArrayGetArray
 * @details Gets an array object with specified position.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @return   An array object.
 * @note 
 */
INTERFACE(FPD_Object, FPDArrayGetArray, (FPD_Object objArray,  FS_DWORD index))

/**
 * @brief FPDArrayGetFloat
 * @details Gets a floating-point with specified position.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @return   A floating-point value.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDArrayGetFloat, (FPD_Object objArray,  FS_DWORD index))

/**
 * @brief FPDArraySetAt
 * @details Changes the element at specified position.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  otherObj The input object.
 * @param[in]  objs The indirect object collection, it can be a FDF_Document object or a FPD_Document object, required if pObj is an indirect object. In this case, a reference object will be created and inserted into the array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDArraySetAt, (FPD_Object objArray,  FS_DWORD index,  FPD_Object otherObj,  void* objs))

/**
 * @brief FPDArrayInsertAt
 * @details Inserts an element at specified position.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  otherObj The input object.
 * @param[in]  pDoc The indirect object collection, it can be a FDF_Document object or a FPD_Document object, required if pObj is an indirect object. In this case, a reference object will be created and inserted into the array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDArrayInsertAt, (FPD_Object objArray,  FS_DWORD index,  FPD_Object otherObj,  FPD_Document pDoc))

/**
 * @brief FPDArrayRemoveAt
 * @details Removes an element.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayRemoveAt, (FPD_Object objArray,  FS_DWORD index))

/**
 * @brief FPDArrayAdd
 * @details Adds a new element to array.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  other_obj The input object.
 * @param[in]  pDoc The input FPD_Document object.
 * @return   void
 * @note All elements will be managed with the array object, so the object pointer
	*           must NOT be freed by caller
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDArrayAdd, (FPD_Object objArray,  FPD_Object other_obj,  FPD_Document pDoc))

/**
 * @brief FPDArrayAddNumber
 * @details Adds a number object with a FIX24.8 value.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  num The input FIX24.8 value.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayAddNumber, (FPD_Object objArray,  FS_FLOAT num))

/**
 * @brief FPDArrayAddInteger
 * @details Adds a number object with an integer value.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  value The input integer value.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayAddInteger, (FPD_Object objArray,  FS_INT32 value))

/**
 * @brief FPDArrayAddString
 * @details Adds a string object.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  str The input string data.
 * @param[in]  nLen The length of the input string data.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayAddString, (FPD_Object objArray,  FS_LPCSTR str,  FS_INT32 nLen))

/**
 * @brief FPDArrayAddName
 * @details Adds a name object.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  szName The input name data.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayAddName, (FPD_Object objArray,  FS_LPCSTR szName))

/**
 * @brief FPDArrayAddReferenceToDoc
 * @details Adds a reference object with object number.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  doc The input indirect object collection.
 * @param[in]  objNum The referred object number.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayAddReferenceToDoc, (FPD_Object objArray,  FPD_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDArrayAddReferenceToFDFDoc
 * @details Adds a reference object with object number.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  doc The input indirect object collection.
 * @param[in]  objNum The referred object number.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayAddReferenceToFDFDoc, (FPD_Object objArray,  FDF_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDArrayAddReference2ToDoc
 * @details Adds a reference object with object pointer.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  doc The input indirect object collection.
 * @param[in]  obj The input object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayAddReference2ToDoc, (FPD_Object objArray,  FPD_Document doc,  FPD_Object obj))

/**
 * @brief FPDArrayAddReference2ToFDFDoc
 * @details Adds a reference object with object pointer.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  doc The input indirect object collection.
 * @param[in]  obj The input object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayAddReference2ToFDFDoc, (FPD_Object objArray,  FDF_Document doc,  FPD_Object obj))

/**
 * @brief FPDArrayIsIdentical
 * @details Compares with another object.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  otherArray The other PDF array object.
 * @return   Non-zero means identical, otherwise not identical.
 * @note 
 */
INTERFACE(FS_BOOL, FPDArrayIsIdentical, (FPD_Object objArray,  FPD_Object otherArray))

/**
 * @brief FPDArrayRemoveAt2
 * @details Removes an element.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  bRelease true: release the data of the index.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayRemoveAt2, (FPD_Object objArray,  FS_DWORD index,  FS_BOOLEAN bRelease))

/**
 * @brief FPDArrayAddNew
 * @details Allocate and add an object element by object_type.
	*            Takes ownership of the object created internally, returns an unowned pdf object pointer.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  object_type The type of the object, one of the FPD_PAGEOBJ constants.
 * @return   FPD_Object   A pdf object, it may be null when object's type is invalid.
 * @note 
 */
INTERFACE(FPD_Object, FPDArrayAddNew, (FPD_Object objArray,  FS_INT32 object_type))

/**
 * @brief FPDArrayRelease
 * @details Release (free, destroy) the object. This function has no effect to indirect objects.
 * @param[in]  objArray The input PDF array object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDArrayRelease, (FPD_Object objArray))

/**
 * @brief FPDArrayAdd2
 * @details Adds a new element to array.
 * @param[in]  objArray The input PDF array object.
 * @param[in]  other_obj The input object.
 * @param[in]  pDoc The input FDF_Document object.
 * @return   void
 * @note All elements will be managed with the array object, so the object pointer
	*           must NOT be freed by caller
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 */
INTERFACE(void, FPDArrayAdd2, (FPD_Object objArray,  FPD_Object other_obj,  FDF_Document pDoc))

NumOfSelector(FPDArray)
ENDENUM

//*****************************
/* Dictionary HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDDictionaryNew
 * @details Creates an empty dictionary.
 * @param[in]  void 
 * @return   A PDF dictionary object.
 * @note 
 * @see FPDObjectDestroy
 */
INTERFACE(FPD_Object, FPDDictionaryNew, (void))

/**
 * @brief FPDDictionaryGetElement
 * @details Gets direct reference to the object (include reference), 
	*            Don't free the returned object.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   A pointer to the object (include reference).
 * @note 
 */
INTERFACE(FPD_Object, FPDDictionaryGetElement, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryGetElementValue
 * @details Gets a direct or referred indirect object, 
	*            Don't free the returned object.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   A pointer to direct or referred indirect object.
 * @note 
 */
INTERFACE(FPD_Object, FPDDictionaryGetElementValue, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryGetString
 * @details Gets the string data for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[out]  outString A byte string for the specified element.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryGetString, (FPD_Object objDict,  const char* key,  FS_ByteString* outString))

/**
 * @brief FPDDictionaryGetUnicodeText
 * @details Gets the Unicode string data for the element specified by key with a character mapping.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[out]  outUnicodeText An Unicode string for the specified element.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryGetUnicodeText, (FPD_Object objDict,  const char* key,  FS_WideString* outUnicodeText))

/**
 * @brief FPDDictionaryGetInteger
 * @details Gets the integer data for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   An integer value for the specified element.
 * @note 
 */
INTERFACE(FS_INT32, FPDDictionaryGetInteger, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryGetInteger2
 * @details Gets the integer data for the element specified by key with a default integer value.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  defaultInt The default integer value.
 * @return   An integer value for the specified element.
 * @note 
 */
INTERFACE(FS_INT32, FPDDictionaryGetInteger2, (FPD_Object objDict,  const char* key,  FS_INT32 defaultInt))

/**
 * @brief FPDDictionaryGetBoolean
 * @details Gets the boolean data for the element specified by key with a default boolean value.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   A boolean value for the specified element.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDictionaryGetBoolean, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryGetNumber
 * @details Gets the number data for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   A FIX24.8 value for the specified element.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDDictionaryGetNumber, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryGetDict
 * @details Gets a dictionary object specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   A dictionary object.
 * @note 
 */
INTERFACE(FPD_Object, FPDDictionaryGetDict, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryGetStream
 * @details Gets a stream object specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   A stream object.
 * @note 
 */
INTERFACE(FPD_Object, FPDDictionaryGetStream, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryGetArray
 * @details Gets an array object specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   An array object.
 * @note 
 */
INTERFACE(FPD_Object, FPDDictionaryGetArray, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryGetRect
 * @details Gets a rectangle for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   A rectangle.
 * @note 
 */
INTERFACE(FS_FloatRect, FPDDictionaryGetRect, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryGetMatrix
 * @details Gets a matrix for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   A matrix.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FPDDictionaryGetMatrix, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryGetFloat
 * @details Gets a floating-point value for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   A floating-point value.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDDictionaryGetFloat, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryKeyExist
 * @details Tests whether the element specified by key is exist.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   Non-zero means exist, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDictionaryKeyExist, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryGetStartPosition
 * @details Gets the position for the first element.
 * @param[in]  objDict The input PDF dictionary object.
 * @return   The position for the first element.
 * @note 
 */
INTERFACE(FS_POSITION, FPDDictionaryGetStartPosition, (FPD_Object objDict))

/**
 * @brief FPDDictionaryGetNextElement
 * @details Gets a direct reference to the element and move the position to next. 
	*            Don't free the returned object.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in,out]  outPos Input current position and receive the next position.
 * @param[out]  outKey It receives the current key string.
 * @return   The direct reference to the current element.
 * @note 
 */
INTERFACE(FPD_Object, FPDDictionaryGetNextElement, (FPD_Object objDict,  FS_POSITION* outPos,  FS_ByteString* outKey))

/**
 * @brief FPDDictionarySetAt
 * @details Sets element data. Please note all elements will be managed with the dictionary object, 
	*            so the object pointer must NOT be freed by caller.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  obj The input element data.
	* param[in] objs			The indirect object collection, required if obj is an indirect object. In this case,
	*							a reference object will be created and inserted into the dictionary. If not requied, sets it as NULL.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDDictionarySetAt, (FPD_Object objDict,  const char* key,  FPD_Object obj,  FPD_Document objs))

/**
 * @brief FPDDictionarySetAtName
 * @details Sets a string of name object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  szName The name string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtName, (FPD_Object objDict,  const char* key,  FS_LPCSTR szName))

/**
 * @brief FPDDictionarySetAtString
 * @details Sets a string of string object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  str The input string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtString, (FPD_Object objDict,  const char* key,  FS_ByteString str))

/**
 * @brief FPDDictionarySetAtInteger
 * @details Sets an integer of number object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  i The input integer.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtInteger, (FPD_Object objDict,  const char* key,  FS_INT32 i))

/**
 * @brief FPDDictionarySetAtNumber
 * @details Sets a FIX24.8 of number object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  f The input FIX24.8 value.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtNumber, (FPD_Object objDict,  const char* key,  FS_FLOAT f))

/**
 * @brief FPDDictionarySetAtReferenceToDoc
 * @details Sets a reference object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  doc The indirect objects collection for the reference object.
 * @param[in]  objNum The referred object number for the reference object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtReferenceToDoc, (FPD_Object objDict,  const char* key,  FPD_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDDictionarySetAtReferenceToFDFDoc
 * @details Sets a reference object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  doc The indirect objects collection for the reference object.
 * @param[in]  objNum The referred object number for the reference object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtReferenceToFDFDoc, (FPD_Object objDict,  const char* key,  FDF_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDDictionarySetAtReference2ToDoc
 * @details Sets a reference object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  doc The indirect objects collection for the reference object.
 * @param[in]  obj The referred object pointer for the reference object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtReference2ToDoc, (FPD_Object objDict,  const char* key,  FPD_Document doc,  FPD_Object obj))

/**
 * @brief FPDDictionarySetAtReference2ToFDFDoc
 * @details Sets a reference object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  doc The indirect objects collection for the reference object.
 * @param[in]  obj The referred object pointer for the reference object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtReference2ToFDFDoc, (FPD_Object objDict,  const char* key,  FDF_Document doc,  FPD_Object obj))

/**
 * @brief FPDDictionarySetAtRect
 * @details Sets a rectangle for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  rect The input rectangle.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtRect, (FPD_Object objDict,  const char* key,  FS_FloatRect rect))

/**
 * @brief FPDDictionarySetAtMatrix
 * @details Sets a matrix for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  matrix The input matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtMatrix, (FPD_Object objDict,  const char* key,  FS_AffineMatrix matrix))

/**
 * @brief FPDDictionarySetAtBoolean
 * @details Sets a boolean value of boolean object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  value The input boolean value.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtBoolean, (FPD_Object objDict,  const char* key,  FS_BOOL value))

/**
 * @brief FPDDictionaryRemoveAt
 * @details Removes the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryRemoveAt, (FPD_Object objDict,  const char* key))

/**
 * @brief FPDDictionaryReplaceKey
 * @details Replaces the key of the element specified by key with new key string.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  oldkey The old key string.
 * @param[in]  newKey The new key string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryReplaceKey, (FPD_Object objDict,  const char* oldkey,  const char* newKey))

/**
 * @brief FPDDictionaryIdentical
 * @details Compares value with another object.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  otherDict The another dictionary.
 * @return   Non-zero means identical, otherwise not identical.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDictionaryIdentical, (FPD_Object objDict,  FPD_Object otherDict))

/**
 * @brief FPDDictionaryGetCount
 * @details Gets the number of elements in the dictionary.
 * @param[in]  objDict The input PDF dictionary object.
 * @return   The number of elements in the dictionary.
 * @note 
 */
INTERFACE(FS_INT32, FPDDictionaryGetCount, (FPD_Object objDict))

/**
 * @brief FPDDictionaryAddValue
 * @details Adds a key-value pair to the dictionary, assuming there is no duplicated key existing.
    *	          This is a function for quickly building up the whole dictionary, but should be used
	*         	  with care. If duplicate key happens, only the first value will prevail.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key.
 * @param[in]  obj The input value.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryAddValue, (FPD_Object objDict,  const char* key,  FPD_Object obj))

/**
 * @brief FPDDictionaryGetBoolean2
 * @details Gets the boolean data for the element specified by key with a default boolean value.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  bDefault The default return value.
 * @return   A boolean value for the specified element.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDictionaryGetBoolean2, (FPD_Object objDict,  const char* key,  FS_BOOL bDefault))

/**
 * @brief FPDDictionarySetAtName2
 * @details Sets a string of name object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  szName The name string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAtName2, (FPD_Object objDict,  const char* key,  FS_ByteString szName))

/**
 * @brief FPDDictionarySetNewAt
 * @details Allocate by object_type and set object element at specified position.
	* Takes ownership of the object created internally when object does not exist, returns an unowned pdf object pointer.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  object_type The type of the object, one of the FPD_OBJ_xxxx constants.
 * @return   FPD_Object   A pdf object, it may be null when object's type is invalid.
 * @note 
 */
INTERFACE(FPD_Object, FPDDictionarySetNewAt, (FPD_Object objDict,  FS_LPCSTR key,  FS_INT32 object_type))

/**
 * @brief FPDDictionaryAddReference
 * @details Add a reference object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  pDoc The input FPD_Document.
 * @param[in]  objnum The referred object number for the reference object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryAddReference, (FPD_Object objDict,  FS_LPCSTR key,  FPD_Document pDoc,  FS_DWORD objnum))

/**
 * @brief FPDDictionaryGetString2
 * @details Get the string data for the element specified by key with a default string additionally.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  default_str The default string.
 * @param[out]  outStr A byte string for the specified element.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryGetString2, (FPD_Object objDict,  FS_LPCSTR key,  FS_LPCSTR default_str,  FS_ByteString* outStr))

/**
 * @brief FPDDictionaryRelease
 * @details Release (free, destroy) the object. This function has no effect to indirect objects.
 * @param[in]  objDict The input PDF dictionary object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryRelease, (FPD_Object objDict))

/**
 * @brief FPDDictionarySetAtString2
 * @details Set a wide string of string object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  wsStr The input wide string.
 * @param[in]  bUTF8 Whether the wide string is saved as UTF-8 encoding or not in PDF.
 * @return   void
 * @note Only the PDF2.0 supports for the UTF-8 Unicode character encoding scheme.
 */
INTERFACE(void, FPDDictionarySetAtString2, (FPD_Object objDict,  FS_LPCSTR key,  FS_LPCWSTR wsStr,  FS_BOOLEAN bUTF8))

/**
 * @brief FPDDictionaryMoveData
 * @details Replace all dictionary data with those within another dictionary. Clear the given dictionary.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  pSrcDict The another dictionary.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryMoveData, (FPD_Object objDict,  FPD_Object pSrcDict))

/**
 * @brief FPDDictionarySetAt2
 * @details Setting element data. Please note all elements will be managed with the dictionary object, so the object pointer
	 * must NOT be freed by caller.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  pObj The input element data.
 * @param[in]  fpdDoc The input FPD_Document.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionarySetAt2, (FPD_Object objDict,  FS_LPCSTR key,  FPD_Object pObj,  FPD_Document fpdDoc))

/**
 * @brief FPDDictionaryRemoveAt2
 * @details Remove the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  bRelease true for releasing value.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryRemoveAt2, (FPD_Object objDict,  FS_LPCSTR key,  FS_BOOLEAN bRelease))

/**
 * @brief FPDDictionaryAddReference2
 * @details Add a reference object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  pDoc The input FPD_Document.
 * @param[in]  obj The referred object pointer for the reference object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryAddReference2, (FPD_Object objDict,  FS_LPCSTR key,  FPD_Document pDoc,  FPD_Object obj))

/**
 * @brief FPDDictionaryAddReference3
 * @details Add a reference object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  pDoc The input FDF_Document.
 * @param[in]  objnum The referred object number for the reference object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryAddReference3, (FPD_Object objDict,  FS_LPCSTR key,  FDF_Document pDoc,  FS_DWORD objnum))

/**
 * @brief FPDDictionaryAddReference4
 * @details Add a reference object for the element specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  pDoc The input FDF_Document.
 * @param[in]  obj The referred object pointer for the reference object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDictionaryAddReference4, (FPD_Object objDict,  FS_LPCSTR key,  FDF_Document pDoc,  FPD_Object obj))

/**
 * @brief FPDDictionaryGetName
 * @details Get a dictionary object specified by key.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   FPD_Object    Return a name object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 */
INTERFACE(FPD_Object, FPDDictionaryGetName, (FPD_Object objDict,  FS_LPCSTR key))

/**
 * @brief FPDDictionaryGetInteger64
 * @details Get a 64-bit integer value for the specified element.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @return   FS_INT64
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 */
INTERFACE(FS_INT64, FPDDictionaryGetInteger64, (FPD_Object objDict,  FS_LPCSTR key))

/**
 * @brief FPDDictionaryGetInteger64ByDefault
 * @details Get a 64-bit integer value for the specified element.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  default_int The default integer value.
 * @return   FS_INT64
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1
 */
INTERFACE(FS_INT64, FPDDictionaryGetInteger64ByDefault, (FPD_Object objDict,  FS_LPCSTR key,  FS_INT64 default_int))

/**
 * @brief FPDDictionarySetAt3
 * @details Setting element data. Please note all elements will be managed with the dictionary object, so the object pointer
	* must NOT be freed by caller.
 * @param[in]  objDict The input PDF dictionary object.
 * @param[in]  key The input key string.
 * @param[in]  pObj The input element data.
 * @param[in]  fpdDoc The input FPD_Document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 */
INTERFACE(void, FPDDictionarySetAt3, (FPD_Object objDict,  FS_LPCSTR key,  FPD_Object pObj,  FDF_Document doc))

NumOfSelector(FPDDictionary)
ENDENUM

//*****************************
/* Stream HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDStreamNew
 * @details Creates a new empty stream object.
 * @return   A stream object.
 * @note Destroys the stream object through <a>FPDObjectDestroy</a>();
 */
INTERFACE(FPD_Object, FPDStreamNew, (void))

/**
 * @brief FPDStreamInitStream
 * @details Initializes a stream with data and dictionary.  
	* If no dictionary specified, the old dictionary is retained.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDStreamInitStream, (FPD_Object objStream,  FS_BYTE* pData,  FS_DWORD size,  FPD_Object dictionary))

/**
 * @brief FPDStreamGetDict
 * @details Gets the dictionary of the stream object.
 * @param[in]  objStream The input stream object.
 * @return   The dictionary of the stream object.
 * @note 
 */
INTERFACE(FPD_Object, FPDStreamGetDict, (FPD_Object objStream))

/**
 * @brief FPDStreamSetData
 * @details Sets stream data. If <param>pData</param> is <a>NULL</a>, just allocate stream buffer.
    *            The data can be uncompressed or compressed. If it's uncompressed, then previous filter
	*            info will be dropped (if any). If it's compressed, the caller should also maintain
	*            the filter information in the dictionary.
 * @param[in]  objStream The input stream object.
 * @param[in]  pData The stream data to set.
 * @param[in]  size The size in bytes of the stream data.
 * @param[in]  bCompressed Whether the data is compressed.
	* param[in]  bKeepBuf		Whether the buffer will be maintained by the stream object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDStreamSetData, (FPD_Object objStream,  FS_LPBYTE pData,  FS_DWORD size,  FS_BOOL bCompressed,  FS_BOOL bKeepBuf))

/**
 * @brief FPDStreamIdentical
 * @details Compares value with another object.
 * @param[in]  objStream The input stream object.
 * @param[in]  other_stm The another stream object.
 * @return   Non-zero means identical, otherwise not identical.
 * @note 
 */
INTERFACE(FS_BOOL, FPDStreamIdentical, (FPD_Object objStream,  FPD_Object other_stm))

/**
 * @brief FPDStreamGetStreamFilter
 * @details Creates a stream-based data filter from the PDF stream.
    *            The filter can output either raw data (decrypted) or decoded data.
	*            JBIG2 and JPEG2000 decoding not supported.
	*            Caller must destroy the created filter.
 * @param[in]  objStream The input stream object.
 * @param[in]  bRaw Whether the stream filter will do decoding.
 * @return   A stream filter object.
 * @note 
 */
INTERFACE(FPD_StreamFilter, FPDStreamGetStreamFilter, (FPD_Object objStream,  FS_BOOL bRaw))

/**
 * @brief FPDStreamGetRawSize
 * @details Gets the raw data size in bytes.
 * @param[in]  objStream The input stream object.
 * @return   The raw data size in bytes.
 * @note 
 */
INTERFACE(FS_DWORD, FPDStreamGetRawSize, (FPD_Object objStream))

/**
 * @brief FPDStreamReadRawData
 * @details Reads raw data.
 * @param[in]  objStream The input stream object.
 * @param[in]  start_pos The start position in the stream data to read from.
 * @param[out]  pBuf The buffer to receive the read data.
 * @param[in]  bufSize The size in bytes expected to read.
 * @return   Non-zero means successful, otherwise failed.
 * @note 
 */
INTERFACE(FS_BOOL, FPDStreamReadRawData, (FPD_Object objStream,  FS_DWORD start_pos,  FS_LPBYTE pBuf,  FS_DWORD bufSize))

/**
 * @brief FPDStreamIsMemoryBased
 * @details Test whether the stream data is memory-based.
 * @param[in]  objStream The input stream object.
 * @return   <a>TRUE</a> for the stream data being memory-based.
 * @note 
 */
INTERFACE(FS_BOOL, FPDStreamIsMemoryBased, (FPD_Object objStream))

/**
 * @brief FPDStreamClone
 * @details Get a complete clone.
 * @param[in]  objStream The input stream object.
 * @param[in]  bDirect Whether a totally direct copy is requested, affect indirect object.
 * @param[in]  lpfCallback Callback function is used to create file stream object for CPDF_Stream.
 * @param[in]  pUserData User private data pointer passed to callback function.
 * @return   A complete clone object.
 * @note 
 */
INTERFACE(FPD_Object, FPDStreamClone, (FPD_Object objStream,  FS_BOOL bDirect,  FPD_LPFCloneStreamCallback lpfCallback,  FS_LPVOID pUserData))

/**
 * @brief FPDStreamCreate
 * @details Create a stream object from a memory buffer, with a dictionary.
 * @param[in]  pData Pointer to the memory buffer.
 * @param[in]  size The size in bytes of the memory buffer.
 * @param[in]  pDict The input dictionary for the stream object.
 * @return   FPD_Object
 * @note 
 */
INTERFACE(FPD_Object, FPDStreamCreate, (FS_LPBYTE pData,  FS_UINT size,  FPD_Object pDict))

/**
 * @brief FPDStreamNew2
 * @details Construct a file based stream. May be encrypted. The dictionary is taken by the stream.
 * @param[in]  pFile The file access interface.
 * @param[in]  pCrypto The encrypt-handler of the stream data in the file.
 * @param[in]  offset The offset in the file.
 * @param[in]  size The size in bytes of the stream data.
 * @param[in]  pDict The input dictionary for the stream object.
 * @param[in]  gennum The generation number for the stream object.
 * @return   FPD_Object
 * @note It need to call FSFileReadHandlerDestroy after relase stream object.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 */
INTERFACE(FPD_Object, FPDStreamNew2, (FS_FileReadHandler pFile,  FPD_CustomCryptoHandler pCrypto,  FS_INT64 offset,  FS_INT64 size,  FPD_Object pDict,  FS_DWORD gennum))

/**
 * @brief FPDStreamSetStreamFile
 * @details Set stream file.
 * @param[in]  objStream The input stream object.
 * @param[in]  pFile The file access interface.
 * @param[in]  offset The offset in the file.
 * @param[in]  size The size in bytes of the stream data.
 * @param[in]  bCompressed The flag to determine if stream need to be compressed during export.
 * @param[in]  bKeepFile Whether need to release file stream when stream destructed.
 * @return   FPD_Object
 * @note If bKeepFile set false, it need to call FSFileReadHandlerDestroy after relase stream object.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 */
INTERFACE(void, FPDStreamSetStreamFile, (FPD_Object objStream,  FS_FileReadHandler pFile,  FS_INT64 offset,  FS_INT64 size,  FS_BOOLEAN bCompressed,  FS_BOOLEAN bKeepFile))

/**
 * @brief FPDStreamDecryptStream
 * @details Decrypt stream data to a file stream.
 * @param[in]  objStream The input stream object.
 * @param[in]  pFileWrite The decrypted data to the end.
 * @return   FS_BOOLEAN   Non-zero means success, otherwise failure.
 * @note It need to call FSFileReadHandlerDestroy after relase stream object.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.1
 */
INTERFACE(FS_BOOLEAN, FPDStreamDecryptStream, (FPD_Object objStream,  FS_FileWriteHandler pFileWrite))

NumOfSelector(FPDStream)
ENDENUM

//*****************************
/* StreamAcc HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDStreamAccNew
 * @details Creates the accessor of stream object.
 * @param[in]  void 
 * @return   The accessor of stream object.
 * @note 
 */
INTERFACE(FPD_StreamAcc, FPDStreamAccNew, (void))

/**
 * @brief FPDStreamAccDestroy
 * @details Destroys the accessor of stream object.
 * @param[in]  stmAcc The input accessor of stream object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDStreamAccDestroy, (FPD_StreamAcc stmAcc))

/**
 * @brief FPDStreamAccLoadAllData
 * @details Must call this function to actually attach to a stream.
 * @param[in]  stmAcc The input accessor of stream object.
 * @param[in]  obj The stream object to be attached to.
 * @param[in]  bRawAccess Whether access the stream data rawly.
 * @param[in]  estimated_size The estimated size in bytes of the loaded stream data.
 * @param[in]  bImageAcc Whether access the image filter or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDStreamAccLoadAllData, (FPD_StreamAcc stmAcc,  FPD_Object obj,  FS_BOOL bRawAccess,  FS_DWORD estimated_size,  FS_BOOL bImageAcc))

/**
 * @brief FPDStreamAccGetStream
 * @details Gets the stream object attached to.
 * @param[in]  stmAcc The input accessor of stream object.
 * @return   The stream object attached to.
 * @note 
 */
INTERFACE(FPD_Object, FPDStreamAccGetStream, (FPD_StreamAcc stmAcc))

/**
 * @brief FPDStreamAccGetDict
 * @details Gets the dictionary of the stream object attached to.
 * @param[in]  stmAcc The input accessor of stream object.
 * @return   The dictionary of the stream object attached to.
 * @note 
 */
INTERFACE(FPD_Object, FPDStreamAccGetDict, (FPD_StreamAcc stmAcc))

/**
 * @brief FPDStreamAccGetData
 * @details Gets the loaded data pointer.
 * @param[in]  stmAcc The input accessor of stream object.
 * @return   The loaded data pointer.
 * @note 
 */
INTERFACE(FS_LPCBYTE, FPDStreamAccGetData, (FPD_StreamAcc stmAcc))

/**
 * @brief FPDStreamAccGetSize
 * @details Gets the loaded data size in bytes.
 * @param[in]  stmAcc The input accessor of stream object.
 * @return   The loaded data size in bytes.
 * @note 
 */
INTERFACE(FS_DWORD, FPDStreamAccGetSize, (FPD_StreamAcc stmAcc))

/**
 * @brief FPDStreamAccDetachData
 * @details Detaches the data buffer from this stream accessor.
	*            After this call, the caller is now responsible for releasing the data buffer.
 * @param[in]  stmAcc The input accessor of stream object.
 * @return   The data buffer from this stream accessor.
 * @note 
 */
INTERFACE(FS_LPBYTE, FPDStreamAccDetachData, (FPD_StreamAcc stmAcc))

/**
 * @brief FPDStreamAccGetImageDecoder
 * @details Gets the image decoder name.
 * @param[in]  stmAcc The input accessor of stream object.
 * @return   The image decoder name.
 * @note 
 */
INTERFACE(char*, FPDStreamAccGetImageDecoder, (FPD_StreamAcc stmAcc))

/**
 * @brief FPDStreamAccGetImageParam
 * @details Gets the image params dictionary.
 * @param[in]  stmAcc The input accessor of stream object.
 * @return   The image params dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDStreamAccGetImageParam, (FPD_StreamAcc stmAcc))

NumOfSelector(FPDStreamAcc)
ENDENUM

//*****************************
/* StreamFilter HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDStreamFilterDestroy
 * @details Destroys the data filter created for accessing PDF stream data.
 * @param[in]  flt The input data filter created for accessing PDF stream data.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDStreamFilterDestroy, (FPD_StreamFilter flt))

/**
 * @brief FPDStreamFilterReadBlock
 * @details Reads a data block. Return number of bytes actually read.
	*            If read size is less than the asked size, it indicates EOF.
 * @param[in]  flt The input data filter created for accessing PDF stream data.
 * @param[out]  buffer It receives the read data.
 * @param[in]  size The size in bytes to read.
 * @return   The number of bytes actually read.
 * @note 
 */
INTERFACE(FS_DWORD, FPDStreamFilterReadBlock, (FPD_StreamFilter flt,  FS_LPBYTE buffer,  FS_DWORD size))

/**
 * @brief FPDStreamFilterGetSrcPos
 * @details Gets current source position (in the raw data stream).
 * @param[in]  flt The input data filter created for accessing PDF stream data.
 * @return   The current source position (in the raw data stream).
 * @note 
 */
INTERFACE(FS_DWORD, FPDStreamFilterGetSrcPos, (FPD_StreamFilter flt))

/**
 * @brief FPDStreamFilterGetStream
 * @details Gets the stream object.
 * @param[in]  flt The input data filter created for accessing PDF stream data.
 * @return   The stream object.
 * @note 
 */
INTERFACE(FPD_Object, FPDStreamFilterGetStream, (FPD_StreamFilter flt))

NumOfSelector(FPDStreamFilter)
ENDENUM

//*****************************
/* Null HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDNullNew
 * @details Creates a null object.
 * @param[in]  void 
 * @return   A null object.
 * @note 
 */
INTERFACE(FPD_Object, FPDNullNew, (void))

NumOfSelector(FPDNull)
ENDENUM

//*****************************
/* Reference HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDReferenceNew
 * @details Creates a reference object with indirect object collection and referred object number.
 * @param[in]  doc The indirect object collection.
 * @param[in]  objNum The referred object number.
 * @return   A reference object.
 * @note 
 */
INTERFACE(FPD_Object, FPDReferenceNew, (FPD_Document doc,  FS_INT32 objNum))

/**
 * @brief FPDReferenceNew2
 * @details Creates a reference object with indirect object collection and referred object number.
 * @param[in]  doc The indirect object collection.
 * @param[in]  objNum The referred object number.
 * @return   A reference object.
 * @note 
 */
INTERFACE(FPD_Object, FPDReferenceNew2, (FDF_Document doc,  FS_INT32 objNum))

/**
 * @brief FPDReferenceGetRefObjNum
 * @details Gets the referred object number.
 * @param[in]  objReference The input reference object.
 * @return   The referred object number.
 * @note 
 */
INTERFACE(FS_DWORD, FPDReferenceGetRefObjNum, (FPD_Object objReference))

/**
 * @brief FPDReferenceSetRefToDoc
 * @details Changes the reference.
 * @param[in]  objReference The input reference object.
 * @param[in]  doc The new indirect object collection.
 * @param[in]  objNum The new referred indirect object number.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDReferenceSetRefToDoc, (FPD_Object objReference,  FPD_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDReferenceSetRefToFDFDoc
 * @details Changes the reference.
 * @param[in]  objReference The input reference object.
 * @param[in]  doc The new indirect object collection.
 * @param[in]  objNum The new referred indirect object number.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDReferenceSetRefToFDFDoc, (FPD_Object objReference,  FDF_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDReferenceIdentical
 * @details Compares with another object.
 * @param[in]  objReference The input reference object.
 * @param[in]  otherReference The another reference object.
 * @return   Non-zero means identical, otherwise not identical.
 * @note 
 */
INTERFACE(FS_BOOL, FPDReferenceIdentical, (FPD_Object objReference,  FPD_Object otherReference))

NumOfSelector(FPDReference)
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
//----------_V15----------
//----------_V16----------
//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------

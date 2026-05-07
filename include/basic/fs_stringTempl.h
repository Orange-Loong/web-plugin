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
/* CharMap HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSCharMapNew
 * @details Creates a new char mapper.
 * @param[in]  GetWideString A pointer type to <a>FSCharmapGetWideString</a>.
 * @param[out]  GetByteString A pointer type to <a>FSCharmapGetByteString</a>.
 * @return   A newly created mapper
 * @note 
 * @see FSCharMapRelease
 * @see FSCharMapGetDefaultMapper
 */
INTERFACE(FS_CharMap, FSCharMapNew, (FSCharmapGetWideString GetWideString,  FSCharmapGetByteString GetByteString))

/**
 * @brief FSCharMapRelease
 * @details Destroys a character mapper.
 * @param[in]  mapper The mapper to release.
 * @return   void
 * @note 
 * @see FSCharMapNew
 */
INTERFACE(void, FSCharMapRelease, (FS_CharMap mapper))

/**
 * @brief FSCharMapGetDefaultMapper
 * @details Gets a character mapper according to Windows code page or other encoding system.</Brief>
	* This char maps are managed by Foxit Reader, don't destroy them.
	* This is system default mapper according to locale settings.
 * @return   A character mapper.
 * @note 
 * @see FSCharMapNew
 */
INTERFACE(FS_CharMap, FSCharMapGetDefaultMapper, (void))

/**
 * @brief FSCharMapGetDefaultMapper2
 * @details Gets a character mapper according to Windows code page or other encoding system.</Brief>
	* This char maps are managed by Foxit Reader, don't destroy them.
	* This is system default mapper according to locale settings.
 * @param[in]  codepage The input code page. Sets it 0 as default.
 * @return   A character mapper.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see FSCharMapNew
 */
INTERFACE(FS_CharMap, FSCharMapGetDefaultMapper2, (FS_INT32 codepage))

NumOfSelector(FSCharMap)
ENDENUM

//*****************************
/* ByteString HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSByteStringNew
 * @details Creates a new empty byte string.
 * @param[in]  void 
 * @return   A new empty byte string.
 * @note 
 */
INTERFACE(FS_ByteString, FSByteStringNew, (void))

/**
 * @brief FSByteStringNew2
 * @details Creates a new byte string from a single character.
 * @param[in]  ch A single character.
 * @return   A new byte string.
 * @note 
 */
INTERFACE(FS_ByteString, FSByteStringNew2, (FS_CHAR ch))

/**
 * @brief FSByteStringNew3
 * @details Creates a new byte string from a character string.
 * @param[in]  ptr Pointer to a character string
 * @param[in]  len The length of the character string. len can be -1 for zero terminated string.
 * @return   A new byte string.
 * @note 
 */
INTERFACE(FS_ByteString, FSByteStringNew3, (FS_LPCSTR ptr,  FS_StrSize len))

/**
 * @brief FSByteStringNew4
 * @details Creates a new byte string from a byte string.
 * @param[in]  ptr Pointer to a byte string.
 * @param[in]  len The length of the byte string.
 * @return   A new byte string.
 * @note 
 */
INTERFACE(FS_ByteString, FSByteStringNew4, (FS_LPCBYTE ptr,  FS_StrSize len))

/**
 * @brief FSByteStringFromUnicode
 * @details Converts from Unicode to system multi-byte charset.
 * @param[in]  src Pointer to a Unicode string.
 * @param[in]  len The length of the Unicode string. len can be -1 for zero terminated Unicode string.
 * @param[out]  outStr The result byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringFromUnicode, (const FS_LPWSTR src,  FS_StrSize len,  FS_ByteString* outStr))

/**
 * @brief FSByteStringFromUnicode2
 * @details Converts from Unicode to system multi-byte charset.
 * @param[in]  src Pointer to a Unicode string.
 * @param[out]  outStr The result byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringFromUnicode2, (const FS_WideString src,  FS_ByteString* outStr))

/**
 * @brief FSByteStringDestroy
 * @details Destroys the byte string.
 * @param[in]  str The input byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringDestroy, (FS_ByteString str))

/**
 * @brief FSByteStringGetLength
 * @details Gets number of bytes in the byte string (not counting any possible terminator).
 * @param[in]  str The input byte string.
 * @return   The Length of the byte string.
 * @note 
 */
INTERFACE(FS_StrSize, FSByteStringGetLength, (FS_ByteString str))

/**
 * @brief FSByteStringIsEmpty
 * @details Determines whether it is empty or not.
 * @param[in]  str The input byte string.
 * @return   <a>TRUE</a> means empty, otherwise not empty.
 * @note 
 */
INTERFACE(FS_BOOL, FSByteStringIsEmpty, (FS_ByteString str))

/**
 * @brief FSByteStringCompare
 * @details Compares the the string with another string. case-sensitive.
 * @param[in]  str1 The input byte string.
 * @param[in]  str2 The byte string to be compared.
 * @return   -1 if this string is "smaller" (in alphabetic order) than the other,
	*            0 for equal, 1 for larger in alphabetic order.
 * @note 
 */
INTERFACE(FS_INT32, FSByteStringCompare, (FS_ByteString str1,  const FS_ByteString str2))

/**
 * @brief FSByteStringEqual
 * @details Checks if this string equals to another.
 * @param[in]  str1 The input byte string.
 * @param[in]  str2 The byte string to be compared.
 * @return   <a>TRUE</a> means equal, otherwise not equal.
 * @note It's faster than Compares if you just want to check whether two strings equal.
 */
INTERFACE(FS_BOOL, FSByteStringEqual, (FS_ByteString str1,  const FS_ByteString str2))

/**
 * @brief FSByteStringEqualNoCase
 * @details Checks if two string equal not considering case. 
	*            </Brief> It means letters 'A'-'Z' will be considered same as 'a'-'z'.
 * @param[in]  str1 The input byte string.
 * @param[in]  str2 Byte string to be compared.
 * @return   <a>TRUE</a> means equal, otherwise not equal.
 * @note 
 */
INTERFACE(FS_BOOL, FSByteStringEqualNoCase, (FS_ByteString str1,  const FS_ByteString str2))

/**
 * @brief FSByteStringCopy
 * @details Copies from a source byte string.
 * @param[in]  str The input byte string.
 * @param[in]  src The source byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringCopy, (FS_ByteString str,  const FS_ByteString src))

/**
 * @brief FSByteStringFill
 * @details Fills a normal string to byte string.
 * @param[in]  str The input byte string.
 * @param[in]  src The source normal string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringFill, (FS_ByteString str,  FS_LPCSTR src))

/**
 * @brief FSByteStringConcat
 * @details Concatenates a source byte string.
 * @param[in]  str The input byte string.
 * @param[in]  src The source byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringConcat, (FS_ByteString str,  const FS_ByteString src))

/**
 * @brief FSByteStringConcat2
 * @details Concatenates a normal string to byte string.
 * @param[in]  str The input byte string.
 * @param[in]  src The source normal string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringConcat2, (FS_ByteString str,  FS_LPCSTR src))

/**
 * @brief FSByteStringEmpty
 * @details Sets this string to be empty.
 * @param[in]  str The input byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringEmpty, (FS_ByteString str))

/**
 * @brief FSByteStringGetAt
 * @details Retrieves a single byte specified by an index number.
 * @param[in]  str The input byte string.
 * @param[in]  nIndex Specifies the zero-based index in the byte string.
 * @return   A single byte.
 * @note 
 */
INTERFACE(FS_BYTE, FSByteStringGetAt, (FS_ByteString str,  FS_StrSize nIndex))

/**
 * @brief FSByteStringSetAt
 * @details Overwrites a single byte specified by an index number.
 * @param[in]  str The input byte string.
 * @param[in]  nIndex Specifies the zero-based index in the byte string.
 * @param[in]  ch A single character.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringSetAt, (FS_ByteString str,  FS_StrSize nIndex,  FS_CHAR ch))

/**
 * @brief FSByteStringInsert
 * @details Inserts a character before specific position.
 * @param[in]  str The input byte string.
 * @param[in]  nIndex Specifies the zero-based index in the byte string.
 * @param[in]  ch A single character.
 * @return   The new length of the byte string.
 * @note 
 */
INTERFACE(FS_StrSize, FSByteStringInsert, (FS_ByteString str,  FS_StrSize nIndex,  FS_CHAR ch))

/**
 * @brief FSByteStringDelete
 * @details Deletes one or more characters starting from specific position.
 * @param[in]  str The input byte string.
 * @param[in]  nIndex Specifies the zero-based index in the byte string for starting deleting.
 * @param[in]  count Count of bytes to be deleted.
 * @return   The new length of the byte string.
 * @note 
 */
INTERFACE(FS_StrSize, FSByteStringDelete, (FS_ByteString str,  FS_StrSize nIndex,  FS_StrSize count))

/**
 * @brief FSByteStringFormat
 * @details Formats a number of parameters into this byte string.
 * @param[in]  str The input byte string.
 * @param[in]  lpszFormat Specifies a format-control string.
 * @param[in]  ... format arguments list.
 * @return   void
 * @note On desktop platforms, this function supports all the sprintf() formats.
	*            On embedded platforms, it supports only a subset of formats:<br>
	*            <ul>
	*            - <li>Supported types: d, u, f, g, x, X, s, c, %.</li>
	*            - <li>Width field supported;</li>
	*            - <li>Precision not supported;</li>
	*            - <li>Flags supported: '0';</li>
	*            </ul>
 */
INTERFACE(void, FSByteStringFormat, (FS_ByteString str,  FS_LPCSTR lpszFormat,  ...))

/**
 * @brief FSByteStringReserve
 * @details Reserves a buffer that can hold specific number of bytes.
 * @param[in]  str The input byte string.
 * @param[in]  len The Length expected to reserve.
 * @return   void
 * @note The content of this string won't be changed.
	*            This can be used if application anticipates the string may grow many times, in this case,
	*            reserving a larger buffer will support string growth without buffer reallocation.
 */
INTERFACE(void, FSByteStringReserve, (FS_ByteString str,  FS_StrSize len))

/**
 * @brief FSByteStringMid
 * @details Extracts a substring starting at position nFirst (zero-based) to last.
 * @param[in]  str The input byte string.
 * @param[in]  first Specifies the zero-based index of the starting position in the byte string.
 * @param[out]  outStr A substring.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringMid, (FS_ByteString str,  FS_StrSize first,  FS_ByteString* outStr))

/**
 * @brief FSByteStringMid2
 * @details Extracts a substring starting at position nFirst (zero-based) to position <param>first</param> + <param>count</param>.
 * @param[in]  str The input byte string.
 * @param[in]  first Specifies the zero-based index of the starting position in the byte string.
 * @param[in]  count The count of bytes expected to extract for the sub-string.
 * @param[in]  outStr A substring.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringMid2, (FS_ByteString str,  FS_StrSize first,  FS_StrSize count,  FS_ByteString* outStr))

/**
 * @brief FSByteStringLeft
 * @details Extracts the leftmost count bytes as a substring.
 * @param[in]  str The input byte string.
 * @param[in]  count The count of bytes expected to extract for the substring.
 * @param[in]  outStr A leftmost substring.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringLeft, (FS_ByteString str,  FS_StrSize count,  FS_ByteString* outStr))

/**
 * @brief FSByteStringRight
 * @details Extracts the rightmost count as a substring.
 * @param[in]  str The input byte string.
 * @param[in]  count The count of bytes expected to extract for the substring.
 * @param[in]  outStr A rightmost substring.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringRight, (FS_ByteString str,  FS_StrSize count,  FS_ByteString* outStr))

/**
 * @brief FSByteStringFind
 * @details Finds a sub-string, from specific position. Only first occurrence is found.
 * @param[in]  str The input byte string.
 * @param[in]  strSub The sub-string to be found.
 * @param[in]  start Specifies the zero-based index of the starting position to do finding.
 * @return   -1:Not found. <br>
	*            other value: Specifies position in the string.
 * @note 
 */
INTERFACE(FS_StrSize, FSByteStringFind, (FS_ByteString str,  const FS_ByteString strSub,  FS_StrSize start))

/**
 * @brief FSByteStringFind2
 * @details Finds a character, from specific position. Only first occurrence is found.
 * @param[in]  str The input byte string.
 * @param[in]  ch The character to be found.
 * @param[in]  start Specifies the zero-based index of the starting position to do finding.
 * @return   -1: Not found.
	*            other value: Specifies position in the string.
 * @note 
 */
INTERFACE(FS_StrSize, FSByteStringFind2, (FS_ByteString str,  FS_CHAR ch,  FS_StrSize start))

/**
 * @brief FSByteStringMakeLower
 * @details Changes case of English letters to lower.
 * @param[in]  str The input byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringMakeLower, (FS_ByteString str))

/**
 * @brief FSByteStringMakeUpper
 * @details Changes case of English letters to upper.
 * @param[in]  str The input byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringMakeUpper, (FS_ByteString str))

/**
 * @brief FSByteStringTrimRight
 * @details Trims white spaces from the right side of the byte string.
 * @param[in]  str The input byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringTrimRight, (FS_ByteString str))

/**
 * @brief FSByteStringTrimRight2
 * @details Trims continuous occurrences of specified character from right side of the byte string.
 * @param[in]  str The input byte string.
 * @param[in]  chTarget The specified character.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringTrimRight2, (FS_ByteString str,  FS_CHAR chTarget))

/**
 * @brief FSByteStringTrimRight3
 * @details Trims continuous occurrences of specified characters from right side of the byte string.
 * @param[in]  str The input byte string.
 * @param[in]  szTargets The specified characters.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringTrimRight3, (FS_ByteString str,  FS_ByteString szTargets))

/**
 * @brief FSByteStringTrimLeft
 * @details Trims white spaces from the left side of the byte string.
 * @param[in]  str The input byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringTrimLeft, (FS_ByteString str))

/**
 * @brief FSByteStringTrimLeft2
 * @details Trims continuous occurrences of specified characters from left side of the byte string.
 * @param[in]  str The input byte string.
 * @param[in]  chTarget The specified character.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringTrimLeft2, (FS_ByteString str,  FS_CHAR chTarget))

/**
 * @brief FSByteStringTrimLeft3
 * @details 
 * @param[in]  str The input byte string.
 * @param[in]  szTargets The specified characters.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringTrimLeft3, (FS_ByteString str,  FS_ByteString szTargets))

/**
 * @brief FSByteStringReplace
 * @details Replace all patterns in the string with a new sub-string.
 * @param[in]  str The input byte string.
 * @param[in]  strOld Specified the string to be matched and replaced in the byte string.
 * @param[in]  strNew Specified the string to replace.
 * @return   The number of replaced patterns.
 * @note 
 */
INTERFACE(FS_StrSize, FSByteStringReplace, (FS_ByteString str,  const FS_ByteString strOld,  const FS_ByteString strNew))

/**
 * @brief FSByteStringRemove
 * @details Removes all occurrence of a particular character.
 * @param[in]  str The input byte string.
 * @param[in]  ch Specified the character to be removed.
 * @return   The number of characters removed.
 * @note 
 */
INTERFACE(FS_StrSize, FSByteStringRemove, (FS_ByteString str,  FS_CHAR ch))

/**
 * @brief FSByteStringGetID
 * @details Gets a DWORD identifier of the string, from a particular position. </Brief> 
	*            This DWORD can be used for quick comparison. Using MSB-first scheme.
	*            If the string doesn't have enough bytes, then zero will be used missing bytes.
 * @param[in]  str The input byte string.
 * @param[in]  startPos Start position in the byte string.
 * @return   A DWORD identifier of the string, from a particular position.
 * @note 
 */
INTERFACE(FS_DWORD, FSByteStringGetID, (FS_ByteString str,  FS_StrSize startPos))

/**
 * @brief FSByteStringFormatInteger
 * @details Converts from Integer.
 * @param[in]  i The input integer
 * @param[in]  flags The formating flags.
 * @param[out]  outResult A result byte string.
 * @return   void
 * @note The flags can be following flags (single or compound):
	*            - FS_FORMAT_SIGNED 
	*            - FS_FORMAT_HEX
	*            - FS_FORMAT_CAPITAL
 */
INTERFACE(void, FSByteStringFormatInteger, (FS_INT32 i,  FS_DWORD flags,  FS_ByteString* outResult))

/**
 * @brief FSByteStringFormatFloat
 * @details Converts from floating-point number.
 * @param[in]  f The input floating-point number.
 * @param[out]  outResult A result byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringFormatFloat, (FS_FLOAT f,  FS_ByteString* outResult))

/**
 * @brief FSByteStringCastToLPCSTR
 * @details cast the byte string to char buffer.
 * @param[in]  str The input byte string.
 * @return   The casted char buffer.
 * @note 
 */
INTERFACE(FS_LPCSTR, FSByteStringCastToLPCSTR, (FS_ByteString str))

/**
 * @brief FSByteStringUTF8Decode
 * @details Decode a UTF-8 unicode string (assume this byte string is UTF-8 encoded)
 * @param[in]  str The input byte string.
 * @param[out]  outWstr The result wide string.
 * @return   A unicode string.
 * @note 
 */
INTERFACE(void, FSByteStringUTF8Decode, (FS_ByteString str,  FS_WideString* outWstr))

/**
 * @brief FSByteStringFormatV
 * @details Formats a number of parameters into this byte string. using va_list.
 * @param[in]  str The input byte string.
 * @param[in]  lpszFormat Specifies a format-control string.
 * @param[in]  argList Variable-argument lists.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringFormatV, (FS_ByteString str,  FS_LPCSTR lpszFormat,  va_list argList))

/**
 * @brief FSByteStringCastToLPCBYTE
 * @details Casts the byte string to byte buffer.
 * @param[in]  str The input byte string.
 * @return   The casted byte buffer.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_LPCBYTE, FSByteStringCastToLPCBYTE, (FS_ByteString str))

/**
 * @brief FSByteStringConvertFrom
 * @details Loads unicode data into this byte string, using specified character mapper.
	* If no character mapper specified, the system default mapper will be used.
 * @param[in]  str The input byte string.
 * @param[in]  wstr A wide string.
 * @param[in]  pCharMap A character mapper. Invokes <a>FSCharMapGetDefaultMapper</a> to get the default mapper. Sets it NULL as default.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FSByteStringConvertFrom, (FS_ByteString str,  FS_WideString wstr,  FS_CharMap pCharMap))

/**
 * @brief FSByteStringEqual2
 * @details Checks if this string equals to another.
 * @param[in]  str1 The input byte string.
 * @param[in]  str2 The byte string to be compared.
 * @return   <a>TRUE</a> means equal, otherwise not equal.
 * @note It's faster than Compares if you just want to check whether two strings equal.
 */
INTERFACE(FS_BOOL, FSByteStringEqual2, (FS_ByteString str1,  FS_LPCSTR str2))

/**
 * @brief FSByteStringReverseFind
 * @details Find a character from end of the string.
 * @param[in]  str The input byte string.
 * @param[in]  ch A character to be found in curren string, from the end.
 * @return   The position of input character in current string. -1 means Not found.
 * @note 
 */
INTERFACE(FS_INT32, FSByteStringReverseFind, (FS_ByteString str,  FS_CHAR ch))

NumOfSelector(FSByteString)
ENDENUM

//*****************************
/* WideString HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSWideStringNew
 * @details Creates a new empty wide string.
 * @param[in]  void 
 * @return   A new empty wide string.
 * @note 
 */
INTERFACE(FS_WideString, FSWideStringNew, (void))

/**
 * @brief FSWideStringNew2
 * @details Creates a new wide string from a single wide character.
 * @param[in]  wch A single character.
 * @return   A new wide string.
 * @note 
 */
INTERFACE(FS_WideString, FSWideStringNew2, (FS_WCHAR wch))

/**
 * @brief FSWideStringNew3
 * @details Creates a new wide string from a wide character string.
 * @param[in]  wsz Pointer to a character string
 * @param[in]  len The length of the character string. len can be -1 for zero terminated string.
 * @return   A new wide string.
 * @note 
 */
INTERFACE(FS_WideString, FSWideStringNew3, (FS_LPCWSTR wsz,  FS_StrSize len))

/**
 * @brief FSWideStringDestroy
 * @details Destroys the wide string.
 * @param[in]  wstr The input wide string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringDestroy, (FS_WideString wstr))

/**
 * @brief FSWideStringGetLength
 * @details Gets number of bytes in the byte string (not counting any possible terminator).
 * @param[in]  wstr The input wide string.
 * @return   The Length of the byte string.
 * @note 
 */
INTERFACE(FS_StrSize, FSWideStringGetLength, (FS_WideString wstr))

/**
 * @brief FSWideStringIsEmpty
 * @details Determines whether it is empty or not.
 * @param[in]  wstr The input wide string.
 * @return   <a>TRUE</a> means empty, otherwise not empty.
 * @note 
 */
INTERFACE(FS_BOOL, FSWideStringIsEmpty, (FS_WideString wstr))

/**
 * @brief FSWideStringCompare
 * @details Compares the the string with another FS_WCHAR buffer. case-sensitive.
 * @param[in]  wstr1 The input wide string.
 * @param[in]  wstr2 The FS_WCHAR buffer to be compared
 * @return   -1 if this string is "smaller" (in alphabetic order) than the other,
	*            0 for equal, 1 for larger in alphabetic order.
 * @note 
 */
INTERFACE(FS_INT32, FSWideStringCompare, (FS_WideString wstr1,  FS_LPCWSTR wstr2))

/**
 * @brief FSWideStringCompare2
 * @details Compares the the string with another string. case-sensitive.
 * @param[in]  wstr1 The input wide string.
 * @param[in]  wstr2 The byte string to be compared.
 * @return   -1 if this string is "smaller" (in alphabetic order) than the other,
	*            0 for equal, 1 for larger in alphabetic order.
 * @note 
 */
INTERFACE(FS_INT32, FSWideStringCompare2, (FS_WideString wstr1,  const FS_WideString wstr2))

/**
 * @brief FSWideStringEqual
 * @details Checks if this string equals to FS_WCHAR buffer.
 * @param[in]  wstr1 The input wide string.
 * @param[in]  wstr2 The FS_WCHAR buffer to be compared.
 * @return   <a>TRUE</a> means equal, otherwise not equal.
 * @note It's faster than Compare if you just want to check whether two strings equal.
 */
INTERFACE(FS_BOOL, FSWideStringEqual, (FS_WideString wstr1,  FS_LPCWSTR wstr2))

/**
 * @brief FSWideStringEqual2
 * @details Checks if this string equals to another.
 * @param[in]  wstr1 The input wide string.
 * @param[in]  wstr2 The byte string to be compared.
 * @return   <a>TRUE</a> means equal, otherwise not equal.
 * @note It's faster than Compare if you just want to check whether two strings equal.
 */
INTERFACE(FS_BOOL, FSWideStringEqual2, (FS_WideString wstr1,  const FS_WideString wstr2))

/**
 * @brief FSWideStringCopy
 * @details Copies from a source byte string.
 * @param[in]  wstr The input wide string.
 * @param[in]  src The source byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringCopy, (FS_WideString wstr,  const FS_WideString src))

/**
 * @brief FSWideStringFill
 * @details Fills a normal  unicode string to wide string.
 * @param[in]  wstr The input wide string.
 * @param[in]  src The source normal unicode string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringFill, (FS_WideString wstr,  FS_LPCWSTR src))

/**
 * @brief FSWideStringConcat
 * @details Concatenates a source byte string.
 * @param[in]  wstr The input wide string.
 * @param[in]  src The source byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringConcat, (FS_WideString wstr,  const FS_WideString src))

/**
 * @brief FSWideStringConcat2
 * @details Concatenates a normal  unicode string to wide string.
 * @param[in]  wstr The input wide string.
 * @param[in]  src The source normal unicode string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringConcat2, (FS_WideString wstr,  FS_LPCWSTR src))

/**
 * @brief FSWideStringEmpty
 * @details Sets this string to be empty.
 * @param[in]  wstr The input wide string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringEmpty, (FS_WideString wstr))

/**
 * @brief FSWideStringGetAt
 * @details Retrieves a single wide char specified by an index number.
 * @param[in]  wstr The input wide string.
 * @param[in]  nIndex Specifies the zero-based index in the byte string.
 * @return   A single byte.
 * @note 
 */
INTERFACE(FS_WCHAR, FSWideStringGetAt, (FS_WideString wstr,  FS_StrSize nIndex))

/**
 * @brief FSWideStringSetAt
 * @details Overwrites a single byte specified by an index number.
 * @param[in]  wstr The input wide string.
 * @param[in]  nIndex Specifies the zero-based index in the byte string.
 * @param[in]  wch A single character.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringSetAt, (FS_WideString wstr,  FS_StrSize nIndex,  FS_WCHAR wch))

/**
 * @brief FSWideStringInsert
 * @details Inserts a character before specific position.
 * @param[in]  wstr The input wide string.
 * @param[in]  nIndex Specifies the zero-based index in the byte string.
 * @param[in]  wch A single character.
 * @return   The new length of the byte string.
 * @note 
 */
INTERFACE(FS_StrSize, FSWideStringInsert, (FS_WideString wstr,  FS_StrSize nIndex,  FS_WCHAR wch))

/**
 * @brief FSWideStringDelete
 * @details Deletes one or more characters starting from specific position.
 * @param[in]  wstr The input wide string.
 * @param[in]  nIndex Specifies the zero-based index in the byte string for starting deleting.
 * @param[in]  count Count of bytes to be deleted.
 * @return   The new length of the byte string.
 * @note 
 */
INTERFACE(FS_StrSize, FSWideStringDelete, (FS_WideString wstr,  FS_StrSize nIndex,  FS_StrSize count))

/**
 * @brief FSWideStringFormat
 * @details Formats a number of parameters into this byte string.
 * @param[in]  wstr The input wide string.
 * @param[in]  lpszFormat Specifies a format-control string.
 * @param[in]  ... arguments list.
 * @return   void
 * @note On desktop platforms, this function supports all the sprintf() formats.
	*            On embedded platforms, it supports only a subset of formats:<br>
	*            <ul>
	*            - <li>Supported types: d, u, f, g, x, X, s, c, %.</li>
	*            - <li>Width field supported;</li>
	*            - <li>Precision not supported;</li>
	*            - <li>Flags supported: '0';</li>
	*            </ul>
 */
INTERFACE(void, FSWideStringFormat, (FS_WideString wstr,  FS_LPCWSTR lpszFormat,  ...))

/**
 * @brief FSWideStringReserve
 * @details Reserves a buffer that can hold specific number of bytes.
 * @param[in]  wstr The input wide string.
 * @param[in]  len The Length expected to reserve.
 * @return   void
 * @note The content of this string won't be changed.
	*            This can be used if application anticipates the string may grow many times, in this case,
	*            reserving a larger buffer will support string growth without buffer reallocation.
 */
INTERFACE(void, FSWideStringReserve, (FS_WideString wstr,  FS_StrSize len))

/**
 * @brief FSWideStringMid
 * @details Extracts a substring starting at position nFirst (zero-based) to last.
 * @param[in]  wstr The input wide string.
 * @param[in]  first Specifies the zero-based index of the starting position in the byte string.
 * @param[out]  outStr A substring.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringMid, (FS_WideString wstr,  FS_StrSize first,  FS_WideString* outStr))

/**
 * @brief FSWideStringMid2
 * @details Extracts a substring starting at position nFirst (zero-based) to position nFirst + count
 * @param[in]  wstr The input wide string.
 * @param[in]  first Specifies the zero-based index of the starting position in the byte string.
 * @param[in]  count The count of bytes expected to extract for the sub-string.
 * @param[in]  outStr A substring.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringMid2, (FS_WideString wstr,  FS_StrSize first,  FS_StrSize count,  FS_WideString* outStr))

/**
 * @brief FSWideStringLeft
 * @details Extracts the leftmost count bytes as a substring.
 * @param[in]  wstr The input wide string.
 * @param[in]  count The count of bytes expected to extract for the substring.
 * @param[in]  outStr Return A leftmost substring.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringLeft, (FS_WideString wstr,  FS_StrSize count,  FS_WideString* outStr))

/**
 * @brief FSWideStringRight
 * @details Extracts the rightmost count as a substring.
 * @param[in]  wstr The input wide string.
 * @param[in]  count The count of bytes expected to extract for the substring
 * @param[in]  outStr Return A rightmost substring.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringRight, (FS_WideString wstr,  FS_StrSize count,  FS_WideString* outStr))

/**
 * @brief FSWideStringFind
 * @details Finds a sub-string, from specific position. Only first occurrence is found.
 * @param[in]  wstr The input wide string.
 * @param[in]  wstrSub The sub-string to be found.
 * @param[in]  start Specifies the zero-based index of the starting position to do finding.
 * @return   -1:Not found. 
	*            other value: Specifies position in the string.
 * @note 
 */
INTERFACE(FS_StrSize, FSWideStringFind, (FS_WideString wstr,  const FS_WideString wstrSub,  FS_StrSize start))

/**
 * @brief FSWideStringFind2
 * @details Finds a character, from specific position. Only first occurrence is found.
 * @param[in]  wstr The input wide string.
 * @param[in]  wch The character to be found.
 * @param[in]  start Specifies the zero-based index of the starting position to do finding.
 * @return   -1: Not found.
	*            other value: Specifies position in the string.
 * @note 
 */
INTERFACE(FS_StrSize, FSWideStringFind2, (FS_WideString wstr,  FS_WCHAR wch,  FS_StrSize start))

/**
 * @brief FSWideStringMakeLower
 * @details Changes case of English letters to lower.
 * @param[in]  wstr The input wide string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringMakeLower, (FS_WideString wstr))

/**
 * @brief FSWideStringMakeUpper
 * @details Changes case of English letters to upper.
 * @param[in]  wstr The input wide string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringMakeUpper, (FS_WideString wstr))

/**
 * @brief FSWideStringTrimRight
 * @details Trims white spaces from the right side of the byte string.
 * @param[in]  wstr The input wide string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringTrimRight, (FS_WideString wstr))

/**
 * @brief FSWideStringTrimRight2
 * @details Trims continuous occurrences of specified character from right side of the byte string.
 * @param[in]  wstr The input wide string.
 * @param[in]  wchTarget The specified character.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringTrimRight2, (FS_WideString wstr,  FS_WCHAR wchTarget))

/**
 * @brief FSWideStringTrimRight3
 * @details Trims continuous occurrences of specified characters from right side of the byte string.
 * @param[in]  wstr The input wide string.
 * @param[in]  wszTargets The specified characters.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringTrimRight3, (FS_WideString wstr,  FS_LPCWSTR wszTargets))

/**
 * @brief FSWideStringTrimLeft
 * @details Trims white spaces from the left side of the byte string.
 * @param[in]  wstr The input wide string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringTrimLeft, (FS_WideString wstr))

/**
 * @brief FSWideStringTrimLeft2
 * @details Trims continuous occurrences of specified characters from left side of the byte string.
 * @param[in]  wstr The input wide string.
 * @param[in]  wchTarget The specified character.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringTrimLeft2, (FS_WideString wstr,  FS_WCHAR wchTarget))

/**
 * @brief FSWideStringTrimLeft3
 * @details Trims continuous occurrences of specified characters from left side of the byte string.
 * @param[in]  wstr The input wide string.
 * @param[in]  wszTargets The specified characters.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringTrimLeft3, (FS_WideString wstr,  FS_LPCWSTR wszTargets))

/**
 * @brief FSWideStringReplace
 * @details Replace all patterns in the string with a new sub-string.
 * @param[in]  wstr The input wide string.
 * @param[in]  wstrOld Specified the string to be matched and replaced in the byte string.
 * @param[in]  wstrNew Specified the string to replace.
 * @return   The number of replaced patterns.
 * @note 
 */
INTERFACE(FS_StrSize, FSWideStringReplace, (FS_WideString wstr,  const FS_WideString wstrOld,  const FS_WideString wstrNew))

/**
 * @brief FSWideStringRemove
 * @details Removes all occurrence of a particular character.
 * @param[in]  wstr The input wide string.
 * @param[in]  wch Specified the character to be removed.
 * @return   The number of characters removed.
 * @note 
 */
INTERFACE(FS_StrSize, FSWideStringRemove, (FS_WideString wstr,  FS_WCHAR wch))

/**
 * @brief FSWideStringGetInteger
 * @details Converts to other data type.
 * @param[in]  wstr The input wide string.
 * @return   A decimal number
 * @note 
 */
INTERFACE(FS_INT32, FSWideStringGetInteger, (FS_WideString wstr))

/**
 * @brief FSWideStringFromUTF8
 * @details Creates a wide string from UTF-8 string (ASCII string compatible).
 * @param[in]  wstr A UTF8 string.
 * @param[in]  len The length in bytes of the UTF8 string. len can be -1 for zero terminated UTF8 string.
 * @param[out]  outWstr A wide string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringFromUTF8, (FS_LPSTR wstr,  FS_StrSize len,  FS_WideString* outWstr))

/**
 * @brief FSWideStringFromUTF16LE
 * @details Creates a wide string from UTF16LE encoded string.
 * @param[in]  wstr A UTF16LE encoded string.
 * @param[in]  len The length in bytes of the UTF16LE encoded string. len can be -1 for zero terminated UTF16LE string.
 * @param[out]  outWstr A wide string.
 * @return   void
 * @note <param>len</param> is number of bytes.
 */
INTERFACE(void, FSWideStringFromUTF16LE, (FS_LPWSTR wstr,  FS_StrSize len,  FS_WideString* outWstr))

/**
 * @brief FSWideStringUTF8Encode
 * @details Does UTF8 encoding.
 * @param[in]  wstrSrc The input wide string.
 * @param[out]  outEncode A byte string result.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringUTF8Encode, (FS_WideString wstrSrc,  FS_ByteString* outEncode))

/**
 * @brief FSWideStringUTF16LE_Encode
 * @details Does UTF16LE encoding. Gets UTF-16LE encoded memory block.
 * @param[in]  wstr The input wide string.
 * @param[in]  bTerminate need to add terminate symbol? In most of times you can choose 'TRUE'
 * @param[in]  outEncode A byte string result.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringUTF16LE_Encode, (FS_WideString wstr,  FS_BOOL bTerminate,  FS_ByteString* outEncode))

/**
 * @brief FSWideStringCastToLPCWSTR
 * @details Cast the wide string to wide char typed pointer.
 * @param[in]  wstr The input wide string.
 * @return   A wide char buffer.
 * @note 
 */
INTERFACE(FS_LPCWSTR, FSWideStringCastToLPCWSTR, (FS_WideString wstr))

/**
 * @brief FSWideStringFormatV
 * @details Formats a number of parameters into this wide string. using va_list.
 * @param[in]  wstr The input wide string.
 * @param[in]  lpszFormat Specifies a format-control string.
 * @param[in]  argList Variable-argument lists.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringFormatV, (FS_WideString wstr,  FS_LPCWSTR lpszFormat,  va_list argList))

/**
 * @brief FSWideStringFromLocal
 * @details Creates a wide string from system multi-byte charset.
 * @param[in]  str A multi-byte charset string.
 * @param[in]  len The length in bytes of the multi-byte charset string. len can be -1 for zero terminated multi-byte charset string.
 * @param[out]  outWstr A wide string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringFromLocal, (FS_LPSTR str,  FS_StrSize len,  FS_WideString* outWstr))

/**
 * @brief FSWideStringFromLocal2
 * @details Creates a wide string from system multi-byte charset.
 * @param[in]  str A multi-byte charset string.
 * @param[out]  outWstr A wide string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringFromLocal2, (FS_ByteString str,  FS_WideString* outWstr))

/**
 * @brief FSWideStringCompareNoCase
 * @details Compares the string with a wide character string. case-insensitive.
 * @param[in]  wstr1 The input wide string.
 * @param[in]  wstr2 The wide character string to be compared.
 * @return   -1 if this string is "smaller" (in alphabetic order) than the other,
	*            0 for equal, 1 for larger in alphabetic order.
 * @note 
 */
INTERFACE(FS_INT32, FSWideStringCompareNoCase, (FS_WideString wstr1,  FS_LPCWSTR wstr2))

/**
 * @brief FSWideStringCompareNoCase2
 * @details Compares the the string with another. case-insensitive.
 * @param[in]  wstr1 The input wide string.
 * @param[in]  wstr2 The wide string to be compared.
 * @return   -1 if this string is "smaller" (in alphabetic order) than the other,
	*            0 for equal, 1 for larger in alphabetic order.
 * @note 
 */
INTERFACE(FS_INT32, FSWideStringCompareNoCase2, (FS_WideString wstr1,  const FS_WideString wstr2))

/**
 * @brief FSWideStringConvertFrom
 * @details Loads MBCS data into this wide string, using specified character mapper.
	* If no character mapper specified, the system default mapper will be used.
 * @param[in]  wstr The input wide string.
 * @param[in]  str A byte string.
 * @param[in]  pCharMap A character mapper. Invokes <a>FSCharMapGetDefaultMapper</a> to get the default mapper.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(void, FSWideStringConvertFrom, (FS_WideString wstr,  FS_ByteString str,  FS_CharMap pCharMap))

INTERFACE(void, FSWideStringFromLocal3, (FS_LPCSTR str,  FS_StrSize len,  FS_WideString* outWstr))

/**
 * @brief FSWideStringGetFloat
 * @details Convert to other data type.
 * @param[in]  str A multi-byte charset string.
 * @return   A floating point number.
 * @note 
 */
INTERFACE(FS_FLOAT, FSWideStringGetFloat, (FS_WideString wstr))

/**
 * @brief FSWideStringFind3
 * @details Finds a sub-string, from specific position. Only first occurrence is found.
 * @param[in]  wstr The input wide string.
 * @param[in]  wstrSub The sub-string to be found.
 * @param[in]  start Specifies the zero-based index of the starting position to do finding.
 * @return   -1:Not found. 
	*            other value: Specifies position in the string.
 * @note 
 */
INTERFACE(FS_StrSize, FSWideStringFind3, (FS_WideString wstr,  const FS_LPCWSTR wstrSub,  FS_StrSize start))

NumOfSelector(FSWideString)
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
//*****************************
/* UnicodeMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSUnicodeMgrGetUnicodeGeneralCategory
 * @details Get the general category.
 * @param[in]  code codepoint.
 * @return   value according to FS_UNICODE_GENERAL_CATEGORY.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_UNICODE_GENERAL_CATEGORY, FSUnicodeMgrGetUnicodeGeneralCategory, (FS_WCHAR code))

/**
 * @brief FSUnicodeMgrEastAsianWidth
 * @details Get east-asian width of a unicode.
 * @param[in]  unicode Unicode codepoint.
 * @return   FS_UNICODE_WIDTH  value according to FS_UNICODE_WIDTH.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_UNICODE_WIDTH, FSUnicodeMgrEastAsianWidth, (FS_WCHAR unicode))

/**
 * @brief FSUnicodeMgrNFKD
 * @details Get east-asian width of a unicode.
 * @param[in]  unicode Points to the unicode string buffer.
 * @param[in]  len Length of the unicode string buffer (FX_WCHAR).
 * @param[out]  nfkd_unicode Newly allocated Unicode string, that is the NFKD normalized form of @unicode.
 * @param[in]  nfkd_len Length of the NFKD normalized string.
 * @return   FS_BOOLEAN     false means either the unicode string includes invalid characters or the unicode string is empty.
 * @note The @nfkd_unicode must ::FSCodeTransformationMemFree by user.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FSUnicodeMgrNFKD, (const FS_WCHAR* unicode,  FS_INT32 len,  FS_WCHAR** nfkd_unicode,  FS_INT32* nfkd_len))

NumOfSelector(FSUnicodeMgr)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

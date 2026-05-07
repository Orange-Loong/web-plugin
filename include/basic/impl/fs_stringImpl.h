#ifndef FS_STRINGIMPL_H
#define FS_STRINGIMPL_H

#ifndef FS_INTERNALINC_H
#include "../fs_internalInc.h"
#endif



#ifdef __cplusplus
extern "C"{
#endif

class CFS_CharMap_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: GetWideString				 A pointer type to <a>FSCharmapGetWideString</a>.
	// Param[out]:GetByteString				 A pointer type to <a>FSCharmapGetByteString</a>.
	// Return:    A newly created mapper
	// Remarks:   Creates a new char mapper.
	// Notes:
	// See: FSCharMapRelease
	// See: FSCharMapGetDefaultMapper
	//************************************
	static FS_CharMap	New(FSCharmapGetWideString GetWideString, FSCharmapGetByteString GetByteString);


	//************************************
	// Function:  Release
	// Param[in]: mapper				 The mapper to release.
	// Return:    void
	// Remarks:   Destroys a character mapper.
	// Notes:
	// See: FSCharMapNew
	//************************************
	static void			Release(FS_CharMap mapper);

	//************************************
	// Function:  GetDefaultMapper
	// Return:    A character mapper.
	// Remarks:   Gets a character mapper according to Windows code page or other encoding system.</Brief>
	// This char maps are managed by Foxit Reader, don't destroy them.
	// This is system default mapper according to locale settings.
	// Notes:
	// See: FSCharMapNew
	//************************************
	static FS_CharMap	GetDefaultMapper(void);

	//************************************
	// Function:  GetDefaultMapper2
	// Param[in]: codepage	The input code page. Sets it 0 as default.
	// Return:    A character mapper.
	// Remarks:   Gets a character mapper according to Windows code page or other encoding system.</Brief>
	// This char maps are managed by Foxit Reader, don't destroy them.
	// This is system default mapper according to locale settings.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	// See: FSCharMapNew
	//************************************
	static FS_CharMap GetDefaultMapper2(FS_INT32 codepage);
};


class CFS_ByteString_V1
{
public:
	
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty byte string.
	// Remarks:   Creates a new empty byte string.
	// Notes:
	//************************************
	static FS_ByteString New(void);

	//************************************
	// Function:  New2
	// Param[in]: ch		A single character.
	// Return:    A new byte string.
	// Remarks:   Creates a new byte string from a single character.
	// Notes:
	//************************************
	static FS_ByteString New2(FS_CHAR ch);

	//************************************
	// Function:  New3
	// Param[in]: ptr	Pointer to a character string
	// Param[in]: len	The length of the character string. len can be -1 for zero terminated string.
	// Return:    A new byte string.
	// Remarks:   Creates a new byte string from a character string.
	// Notes:
	//************************************
	static FS_ByteString New3(FS_LPCSTR ptr, FS_StrSize len);

	//************************************
	// Function:  New4
	// Param[in]: ptr	Pointer to a byte string.
	// Param[in]: len	The length of the byte string.
	// Return:    A new byte string.
	// Remarks:   Creates a new byte string from a byte string.
	// Notes:
	//************************************
	static FS_ByteString New4(FS_LPCBYTE ptr, FS_StrSize len);

	//************************************
	// Function:    FromUnicode
	// Param[in]: src		Pointer to a Unicode string.
	// Param[in]: len		The length of the Unicode string. len can be -1 for zero terminated Unicode string.
	// Param[out]:outStr	The result byte string.
	// Return:    void
	// Remarks:   Converts from Unicode to system multi-byte charset.
	// Notes:
	//************************************
	static void FromUnicode(const FS_LPWSTR src, FS_StrSize len, FS_ByteString* outStr);

	//************************************
	// Function:  FromUnicode2
	// Param[in]: src		Pointer to a Unicode string.
	// Param[out]:outStr	The result byte string.
	// Return:    void
	// Remarks:   Converts from Unicode to system multi-byte charset.
	// Notes:
	//************************************
	static void FromUnicode2(const FS_WideString src, FS_ByteString* outStr);

	//************************************
	// Function:  Destroy
	// Param[in]: str The input byte string.
	// Return:    void
	// Remarks:   Destroys the byte string.
	// Notes:
	//************************************
	static void	Destroy(FS_ByteString str);

	//************************************
	// Function:  GetLength
	// Param[in]: str The input byte string.
	// Return:    The Length of the byte string.
	// Remarks:   Gets number of bytes in the byte string (not counting any possible terminator).
	// Notes:
	//************************************
	static FS_StrSize GetLength(FS_ByteString str);

	//************************************
	// Function:  IsEmpty
	// Param[in]: str The input byte string.
	// Return:    <a>TRUE</a> means empty, otherwise not empty.
	// Remarks:   Determines whether it is empty or not.
	// Notes:
	//************************************
	static FS_BOOL	IsEmpty(FS_ByteString str);

	//************************************
	// Function:  Compare
	// Param[in]: str1		The input byte string.
	// Param[in]: str2		The byte string to be compared.
	// Return:    -1 if this string is "smaller" (in alphabetic order) than the other,
	//            0 for equal, 1 for larger in alphabetic order.
	// Remarks:   Compares the the string with another string. case-sensitive.
	// Notes:
	//************************************
	static FS_INT32 Compare( FS_ByteString str1, const FS_ByteString str2);

	//************************************
	// Function:   Equal
	// Param[in]:  str1		The input byte string.
	// Param[in]:  str2		The byte string to be compared.
	// Return:     <a>TRUE</a> means equal, otherwise not equal.
	// Remarks:	   Checks if this string equals to another.
	// Notes:      It's faster than Compares if you just want to check whether two strings equal.
	//************************************
	static FS_BOOL Equal( FS_ByteString str1, const FS_ByteString str2);

	//************************************
	// Function:  EqualNoCase
	// Param[in]: str1		The input byte string.
	// Param[in]: str2		Byte string to be compared.
	// Return:    <a>TRUE</a> means equal, otherwise not equal.
	// Remarks:   Checks if two string equal not considering case. 
	//            </Brief> It means letters 'A'-'Z' will be considered same as 'a'-'z'.
	// Notes:
	//************************************
	static FS_BOOL EqualNoCase( FS_ByteString str1, const FS_ByteString str2);

	//************************************
	// Function:    Copy
	// Param[in]: str		The input byte string.
	// Param[in]: src		The source byte string.
	// Return:    void
	// Remarks:   Copies from a source byte string.
	// Notes:
	//************************************
	static void Copy( FS_ByteString str, const FS_ByteString src);

	//************************************
	// Function:   Fill
	// Param[in]: str		The input byte string.
	// Param[in]: src		The source normal string.
	// Return:    void
	// Remarks:   Fills a normal string to byte string.
	// Notes:
	//************************************
	static void Fill(FS_ByteString str, FS_LPCSTR src);

	//************************************
	// Function:    Concat
	// Param[in]: str		The input byte string.
	// Param[in]: src		The source byte string.
	// Return:    void
	// Remarks:   Concatenates a source byte string.
	// Notes:
	//************************************
	static void Concat(FS_ByteString str, const FS_ByteString src);

	//************************************
	// Function:  Concat2
	// Param[in]: str		The input byte string.
	// Param[in]: src		The source normal string.
	// Return:    void
	// Remarks:   Concatenates a normal string to byte string.
	// Notes:
	//************************************
	static void Concat2(FS_ByteString str, FS_LPCSTR src);

	//************************************
	// Function:  Empty
	// Param[in]: str	The input byte string.
	// Return:    void
	// Remarks:   Sets this string to be empty.
	// Notes:
	//************************************
	static void Empty(FS_ByteString str);

	//************************************
	// Function:  GetAt
	// Param[in]: str		The input byte string.
	// Param[in]: nIndex	Specifies the zero-based index in the byte string.
	// Return:   A single byte.
	// Remarks:   Retrieves a single byte specified by an index number.
	// Notes:
	//************************************
	static FS_BYTE GetAt(FS_ByteString str, FS_StrSize nIndex);

	//************************************
	// Function:  SetAt
	// Param[in]: str		The input byte string.
	// Param[in]: nIndex	Specifies the zero-based index in the byte string.
	// Param[in]: ch		A single character.
	// Return:    void
	// Remarks:   Overwrites a single byte specified by an index number.
	// Notes:
	//************************************
	static void SetAt(FS_ByteString str, FS_StrSize nIndex, FS_CHAR ch);

	//************************************
	// Function:  Insert
	// Param[in]: str			The input byte string.
	// Param[in]: nIndex		Specifies the zero-based index in the byte string.
	// Param[in]: ch			A single character.
	// Return:    The new length of the byte string.
	// Remarks:   Inserts a character before specific position.
	// Notes:
	//************************************
	static FS_StrSize Insert(FS_ByteString str, FS_StrSize nIndex, FS_CHAR ch);

	//************************************
	// Function:  Delete
	// Param[in]: str		The input byte string.
	// Param[in]: nIndex	Specifies the zero-based index in the byte string for starting deleting.
	// Param[in]: count		Count of bytes to be deleted.
	// Return:    The new length of the byte string.
	// Remarks:	  Deletes one or more characters starting from specific position.
	// Notes:
	//************************************
	static FS_StrSize Delete(FS_ByteString str, FS_StrSize nIndex, FS_StrSize count);

	//************************************
	// Function:  Format
	// Param[in]: str				The input byte string.
	// Param[in]: lpszFormat		Specifies a format-control string.
	// Param[in]: ...				format arguments list.					
	// Return:    void
	// Remarks:   Formats a number of parameters into this byte string.
	// Notes:     On desktop platforms, this function supports all the sprintf() formats.
	//            On embedded platforms, it supports only a subset of formats:<br>
	//            <ul>
	//            - <li>Supported types: d, u, f, g, x, X, s, c, %.</li>
	//            - <li>Width field supported;</li>
	//            - <li>Precision not supported;</li>
	//            - <li>Flags supported: '0';</li>
	//            </ul>
	//************************************
	static void Format(FS_ByteString str, FS_LPCSTR lpszFormat, ...);

	//************************************
	// Function:  Reserve	
	// Param[in]: str		The input byte string.
	// Param[in]: len		The Length expected to reserve.
	// Return:    void
	// Remarks:	  Reserves a buffer that can hold specific number of bytes.
	// Notes:     The content of this string won't be changed.
	//            This can be used if application anticipates the string may grow many times, in this case,
	//            reserving a larger buffer will support string growth without buffer reallocation.
	//************************************
	static void Reserve(FS_ByteString str, FS_StrSize len);

	//************************************
	// Function:  Mid
	// Param[in]: str		The input byte string.
	// Param[in]: first		Specifies the zero-based index of the starting position in the byte string.
	// Param[out]:outStr	A substring.
	// Return:    void
	// Remarks:   Extracts a substring starting at position nFirst (zero-based) to last. 
	// Notes: 
	//************************************
	static void Mid(FS_ByteString str, FS_StrSize first, FS_ByteString* outStr);

	//************************************
	// Function:  Mid2
	// Param[in]: str		The input byte string.
	// Param[in]: first		Specifies the zero-based index of the starting position in the byte string.
	// Param[in]: count		The count of bytes expected to extract for the sub-string.
	// Param[in]: outStr	A substring.
	// Return:    void
	// Remarks:   Extracts a substring starting at position nFirst (zero-based) to position <param>first</param> + <param>count</param>.
	// Notes:
	//************************************
	static void	Mid2(FS_ByteString str, FS_StrSize first, FS_StrSize count, FS_ByteString* outStr);

	//************************************
	// Function:  Left
	// Param[in]: str		The input byte string.
	// Param[in]: count		The count of bytes expected to extract for the substring.
	// Param[in]: outStr	A leftmost substring.
	// Return:    void
	// Remarks:   Extracts the leftmost count bytes as a substring. 
	// Notes:
	//************************************
	static void	Left(FS_ByteString str, FS_StrSize count, FS_ByteString* outStr);

	//************************************
	// Function:  Right	
	// Param[in]: str		The input byte string.
	// Param[in]: count		The count of bytes expected to extract for the substring.
	// Param[in]: outStr	A rightmost substring.
	// Return:    void
	// Remarks:   Extracts the rightmost count as a substring.
	// Notes:
	//************************************
	static void	Right(FS_ByteString str, FS_StrSize count, FS_ByteString* outStr);

	//************************************
	// Function:  Find
	// Param[in]: str		The input byte string.
	// Param[in]: strSub	The sub-string to be found.
	// Param[in]: start		Specifies the zero-based index of the starting position to do finding.
	// Return:    -1:Not found. <br>
	//            other value: Specifies position in the string.
	// Remarks:   Finds a sub-string, from specific position. Only first occurrence is found.
	// Notes:
	//************************************
	static FS_StrSize Find(FS_ByteString str, const FS_ByteString strSub, FS_StrSize start);

	//************************************
	// Function:  Find2
	// Param[in]: str		The input byte string.
	// Param[in]: ch		The character to be found.
	// Param[in]: start		Specifies the zero-based index of the starting position to do finding.
	// Return:    -1: Not found.
	//            other value: Specifies position in the string.
	// Remarks:   Finds a character, from specific position. Only first occurrence is found.
	// Notes:
	//************************************
	static FS_StrSize Find2(FS_ByteString str, FS_CHAR ch, FS_StrSize start);

	//************************************
	// Function:  MakeLower
	// Param[in]: str	The input byte string.
	// Return:    void
	// Remarks:   Changes case of English letters to lower.
	// Notes:
	//************************************
	static void	 MakeLower(FS_ByteString str);

	//************************************
	// Function:  MakeUpper	
	// Param[in]: str	The input byte string.
	// Return:    void
	// Remarks:   Changes case of English letters to upper.
	// Notes:
	//************************************
	static void	MakeUpper(FS_ByteString str);

	//************************************
	// Function:  TrimRight	
	// Param[in]: str	The input byte string.
	// Return:    void
	// Remarks:   Trims white spaces from the right side of the byte string.
	// Notes:
	//************************************
	static void	TrimRight(FS_ByteString str);

	//************************************
	// Function:  TrimRight2
	// Param[in]: str			The input byte string.
	// Param[in]: chTarget		The specified character.
	// Return:    void
	// Remarks:	  Trims continuous occurrences of specified character from right side of the byte string.
	// Notes:
	//************************************
	static void	TrimRight2(FS_ByteString str, FS_CHAR chTarget);

	//************************************
	// Function:  TrimRight3
	// Param[in]: str			The input byte string.
	// Param[in]: szTargets		The specified characters.
	// Return:    void
	// Remarks:   Trims continuous occurrences of specified characters from right side of the byte string.
	// Notes:
	//************************************
	static void TrimRight3(FS_ByteString str, FS_ByteString szTargets);

	//************************************
	// Function:  TrimLeft
	// Param[in]: str	The input byte string.
	// Return:    void
	// Remarks:   Trims white spaces from the left side of the byte string.
	// Notes:
	//************************************
	static void	TrimLeft(FS_ByteString str);

	//************************************
	// Function:  TrimLeft2
	// Param[in]: str			The input byte string.
	// Param[in]: chTarget		The specified character.
	// Return:    void
	// Remarks:   Trims continuous occurrences of specified characters from left side of the byte string.
	// Notes:
	//************************************
	static void	TrimLeft2(FS_ByteString str, FS_CHAR chTarget);

	//************************************
	// Function:  TrimLeft3
	// Param[in]: str			The input byte string.
	// Param[in]: szTargets		The specified characters.
	// Return:    void
	// Remarks:   Trims continuous occurrences of specified characters from left side of the byte string.
	// Notes;
	//************************************
	static void TrimLeft3(FS_ByteString str, FS_ByteString szTargets);

	//************************************
	// Function:    Replace	
	// Param[in]: str			The input byte string.
	// Param[in]: strOld		Specified the string to be matched and replaced in the byte string.
	// Param[in]: strNew		Specified the string to replace.
	// Return:    The number of replaced patterns.
	// Remarks:   Replace all patterns in the string with a new sub-string.
	// Notes:
	//************************************
	static FS_StrSize Replace(FS_ByteString str, const FS_ByteString strOld,  const FS_ByteString strNew);

	//************************************
	// Function:  Remove
	// Param[in]: str	The input byte string.
	// Param[in]: ch	Specified the character to be removed.
	// Return:    The number of characters removed.
	// Remarks:   Removes all occurrence of a particular character.
	// Notes:
	//************************************
	static FS_StrSize Remove(FS_ByteString str, FS_CHAR ch);

	//************************************
	// Function:  GetID
	// Param[in]: str			The input byte string.
	// Param[in]: startPos		Start position in the byte string.
	// Return:    A DWORD identifier of the string, from a particular position.
	// Remarks:	  Gets a DWORD identifier of the string, from a particular position. </Brief> 
	//            This DWORD can be used for quick comparison. Using MSB-first scheme.
	//            If the string doesn't have enough bytes, then zero will be used missing bytes.
	// Notes:     
	//************************************
	static FS_DWORD GetID(FS_ByteString str, FS_StrSize startPos);

	//************************************
	// Function:  FormatInteger
	// Param[in]: i				The input integer
	// Param[in]: flags			The formating flags.
	// Param[out]:outResult		A result byte string.
	// Return:    void
	// Remarks:   Converts from Integer.
	// Notes:     The flags can be following flags (single or compound):
	//            - FS_FORMAT_SIGNED 
	//            - FS_FORMAT_HEX
	//            - FS_FORMAT_CAPITAL
	//************************************
	static void FormatInteger(FS_INT32 i, FS_DWORD flags, FS_ByteString* outResult);

	//************************************
	// Function:  FormatFloat
	// Param[in]: f				The input floating-point number.
	// Param[out]:outResult		A result byte string.
	// Return:    void
	// Remarks:   Converts from floating-point number.
	// Notes:
	//************************************
	static void FormatFloat(FS_FLOAT f, FS_ByteString* outResult);


	//************************************
	// Function:  CastToLPCSTR
	// Param[in]: str	The input byte string.
	// Return:    The casted char buffer.
	// Remarks:   cast the byte string to char buffer.
	// Notes:
	//************************************
	static FS_LPCSTR CastToLPCSTR(FS_ByteString str);

	//************************************
	// Function:  UTF8Decode
	// Param[in]: str		The input byte string.
	// Param[out]:outWstr   The result wide string.
	// Return:    A unicode string.
	// Remarks:   Decode a UTF-8 unicode string (assume this byte string is UTF-8 encoded)
	// Notes:
	//************************************
	static void	UTF8Decode(FS_ByteString str, FS_WideString* outWstr);

	//************************************
	// Function:  FormatV
	// Param[in]: str				The input byte string.
	// Param[in]: lpszFormat		Specifies a format-control string.
	// Param[in]: argList			Variable-argument lists.
	// Return:    void
	// Remarks:   Formats a number of parameters into this byte string. using va_list.
	// Notes:
	//************************************
	static void	FormatV(FS_ByteString str, FS_LPCSTR lpszFormat, va_list argList);

	//************************************
	// Function:  CastToLPCBYTE
	// Param[in]: str	The input byte string.
	// Return:    The casted byte buffer.
	// Remarks:   Casts the byte string to byte buffer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_LPCBYTE CastToLPCBYTE(FS_ByteString str);

	//************************************
	// Function:  ConvertFrom
	// Param[in]: str		The input byte string.
	// Param[in]: wstr		A wide string.
	// Param[in]: pCharMap	A character mapper. Invokes <a>FSCharMapGetDefaultMapper</a> to get the default mapper. Sets it NULL as default.
	// Return: void
	// Remarks: Loads unicode data into this byte string, using specified character mapper.
	// If no character mapper specified, the system default mapper will be used.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static void ConvertFrom(FS_ByteString str, FS_WideString wstr, FS_CharMap pCharMap);

	//************************************
	// Function:   Equal2
	// Param[in]:  str1		The input byte string.
	// Param[in]:  str2		The byte string to be compared.
	// Return:     <a>TRUE</a> means equal, otherwise not equal.
	// Remarks:	   Checks if this string equals to another.
	// Notes:      It's faster than Compares if you just want to check whether two strings equal.
	//************************************
	static FS_BOOL Equal2(FS_ByteString str1, FS_LPCSTR str2);
	
	 //************************************
	 // Function:   ReverseFind
	 // Param[in]:  str		The input byte string.
	 // Param[in]:  ch		A character to be found in curren string, from the end.
	 // Return:    The position of input character in current string. -1 means Not found.
	 // Remarks:	Find a character from end of the string.
	 // Notes:    
	 //************************************
	static FS_INT32	 ReverseFind(FS_ByteString str, FS_CHAR ch);
};


class CFS_WideString_V1
{
public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty wide string.
	// Remarks:   Creates a new empty wide string.
	// Notes:
	//************************************
	static FS_WideString New(void);

	//************************************
	// Function:  New2
	// Param[in]: wch		A single character.
	// Return:    A new wide string.
	// Remarks:   Creates a new wide string from a single wide character.
	// Notes:
	//************************************
	static FS_WideString New2(FS_WCHAR wch);

	//************************************
	// Function:  New3
	// Param[in]: wsz	Pointer to a character string
	// Param[in]: len	The length of the character string. len can be -1 for zero terminated string.
	// Return:    A new wide string.
	// Remarks:   Creates a new wide string from a wide character string.
	// Notes:
	//************************************
	static FS_WideString New3(FS_LPCWSTR wsz, FS_StrSize len);


	//************************************
	// Function:  Destroy
	// Param[in]: wstr The input wide string.
	// Return:    void
	// Remarks:   Destroys the wide string.
	// Notes:
	//************************************
	static void	Destroy(FS_WideString wstr);

	//************************************
	// Function:  GetLength
	// Param[in]: wstr The input wide string.
	// Return:   The Length of the byte string.
	// Remarks:   Gets number of bytes in the byte string (not counting any possible terminator).
	// Notes:
	//************************************
	static FS_StrSize GetLength(FS_WideString wstr);

	//************************************
	// Function:  IsEmpty
	// Param[in]: wstr The input wide string.
	// Return:    <a>TRUE</a> means empty, otherwise not empty.
	// Remarks:   Determines whether it is empty or not.
	// Notes:
	//************************************
	static FS_BOOL	IsEmpty(FS_WideString wstr);

	//************************************
	// Function:  Compare
	// Param[in]: wstr1     The input wide string.
	// Param[in]: wstr2		The FS_WCHAR buffer to be compared
	// Return:    -1 if this string is "smaller" (in alphabetic order) than the other,
	//            0 for equal, 1 for larger in alphabetic order.
	// Remarks:   Compares the the string with another FS_WCHAR buffer. case-sensitive.
	// Notes:
	//************************************
	static FS_INT32 Compare( FS_WideString wstr1, FS_LPCWSTR wstr2);

	//************************************
	// Function:  Compare2
	// Param[in]: wstr1		The input wide string.
	// Param[in]: wstr2		The byte string to be compared.
	// Return:    -1 if this string is "smaller" (in alphabetic order) than the other,
	//            0 for equal, 1 for larger in alphabetic order.
	// Remarks:   Compares the the string with another string. case-sensitive.
	// Notes:
	//************************************
	static FS_INT32 Compare2( FS_WideString wstr1, const FS_WideString wstr2);

	//************************************
	// Function:   Equal
	// Param[in]:  wstr1		The input wide string.
	// Param[in]:  wstr2		The FS_WCHAR buffer to be compared.
	// Return:     <a>TRUE</a> means equal, otherwise not equal.
	// Remarks:	   Checks if this string equals to FS_WCHAR buffer.
	// Notes:      It's faster than Compare if you just want to check whether two strings equal.
	//************************************
	static FS_BOOL Equal( FS_WideString wstr1, FS_LPCWSTR wstr2);

	//************************************
	// Function:   Equal2
	// Param[in]:  wstr1		The input wide string.
	// Param[in]:  wstr2		The byte string to be compared.
	// Return:     <a>TRUE</a> means equal, otherwise not equal.
	// Remarks:	   Checks if this string equals to another.
	// Notes:      It's faster than Compare if you just want to check whether two strings equal.
	//************************************
	static FS_BOOL Equal2( FS_WideString wstr1, const FS_WideString wstr2);

	//************************************
	// Function:    Copy
	// Param[in]: wstr		The input wide string.
	// Param[in]: src		The source byte string.
	// Return:    void
	// Remarks:   Copies from a source byte string.
	// Notes:
	//************************************
	static void Copy( FS_WideString wstr, const FS_WideString src);

	//************************************
	// Function:  Fill
	// Param[in]: wstr		The input wide string.
	// Param[in]: src		The source normal unicode string.
	// Return:    void
	// Remarks:   Fills a normal  unicode string to wide string.
	// Notes:
	//************************************
	static void Fill(FS_WideString wstr, FS_LPCWSTR src);

	//************************************
	// Function:    Concat
	// Param[in]: wstr		The input wide string.
	// Param[in]: src		The source byte string.
	// Return:    void
	// Remarks:   Concatenates a source byte string.
	// Notes:
	//************************************
	static void Concat(FS_WideString wstr, const FS_WideString src);

	//************************************
	// Function:  Concat2
	// Param[in]: wstr		The input wide string.
	// Param[in]: src		The source normal unicode string.
	// Return:    void
	// Remarks:   Concatenates a normal  unicode string to wide string.
	// Notes:
	//************************************
	static void Concat2(FS_WideString wstr, FS_LPCWSTR src);

	//************************************
	// Function:  Empty
	// Param[in]: wstr The input wide string.
	// Return:    void
	// Remarks:   Sets this string to be empty.
	// Notes:
	//************************************
	static void Empty(FS_WideString wstr);

	//************************************
	// Function:  GetAt
	// Param[in]: wstr		The input wide string.
	// Param[in]: nIndex	Specifies the zero-based index in the byte string.
	// Return:    A single byte.
	// Remarks:   Retrieves a single wide char specified by an index number.
	// Notes:
	//************************************
	static FS_WCHAR GetAt(FS_WideString wstr, FS_StrSize nIndex);

	//************************************
	// Function:  SetAt
	// Param[in]: wstr		The input wide string.
	// Param[in]: nIndex	Specifies the zero-based index in the byte string.
	// Param[in]: wch		A single character.
	// Return:    void
	// Remarks:   Overwrites a single byte specified by an index number.
	// Notes:
	//************************************
	static void SetAt(FS_WideString wstr, FS_StrSize nIndex, FS_WCHAR wch);

	//************************************
	// Function:  Insert
	// Param[in]: wstr			The input wide string.
	// Param[in]: nIndex		Specifies the zero-based index in the byte string.
	// Param[in]: wch			A single character.
	// Return:    The new length of the byte string.
	// Remarks:   Inserts a character before specific position.
	// Notes:
	//************************************
	static FS_StrSize Insert(FS_WideString wstr, FS_StrSize nIndex, FS_WCHAR wch);

	//************************************
	// Function:  Delete
	// Param[in]: wstr		The input wide string.
	// Param[in]: nIndex	Specifies the zero-based index in the byte string for starting deleting.
	// Param[in]: count		Count of bytes to be deleted.
	// Return:    The new length of the byte string.
	// Remarks:	  Deletes one or more characters starting from specific position.
	// Notes:
	//************************************
	static FS_StrSize Delete(FS_WideString wstr, FS_StrSize nIndex, FS_StrSize count);

	//************************************
	// Function:  Format
	// Param[in]: wstr			The input wide string.
	// Param[in]: lpszFormat	Specifies a format-control string.
	// Param[in]: ...			arguments list.
	// Return:    void
	// Remarks:   Formats a number of parameters into this byte string.
	// Notes:     On desktop platforms, this function supports all the sprintf() formats.
	//            On embedded platforms, it supports only a subset of formats:<br>
	//            <ul>
	//            - <li>Supported types: d, u, f, g, x, X, s, c, %.</li>
	//            - <li>Width field supported;</li>
	//            - <li>Precision not supported;</li>
	//            - <li>Flags supported: '0';</li>
	//            </ul>
	//************************************
	static void Format(FS_WideString wstr, FS_LPCWSTR lpszFormat, ...);

	//************************************
	// Function:  Reserve	
	// Param[in]: wstr		The input wide string.
	// Param[in]: len		The Length expected to reserve.
	// Return:    void
	// Remarks:	  Reserves a buffer that can hold specific number of bytes.
	// Notes:     The content of this string won't be changed.
	//            This can be used if application anticipates the string may grow many times, in this case,
	//            reserving a larger buffer will support string growth without buffer reallocation.
	//************************************
	static void Reserve(FS_WideString wstr, FS_StrSize len);

	//************************************
	// Function:  Mid
	// Param[in]: wstr		The input wide string.
	// Param[in]: first		Specifies the zero-based index of the starting position in the byte string.
	// Param[out]:outStr	A substring.
	// Return:    void
	// Remarks:   Extracts a substring starting at position nFirst (zero-based) to last. 
	// Notes: 
	//************************************
	static void Mid(FS_WideString wstr, FS_StrSize first, FS_WideString* outStr);

	//************************************
	// Function:  Mid2
	// Param[in]: wstr		The input wide string.
	// Param[in]: first		Specifies the zero-based index of the starting position in the byte string.
	// Param[in]: count		The count of bytes expected to extract for the sub-string.
	// Param[in]: outStr	A substring.
	// Return:    void
	// Remarks:   Extracts a substring starting at position nFirst (zero-based) to position nFirst + count
	// Notes:
	//************************************
	static void	Mid2(FS_WideString wstr, FS_StrSize first, FS_StrSize count, FS_WideString* outStr);

	//************************************
	// Function:  Left
	// Param[in]: wstr		The input wide string.
	// Param[in]: count		The count of bytes expected to extract for the substring.
	// Param[in]: outStr	Return A leftmost substring.
	// Return:    void
	// Remarks:   Extracts the leftmost count bytes as a substring. 
	// Notes:
	//************************************
	static void	Left(FS_WideString wstr, FS_StrSize count, FS_WideString* outStr);

	//************************************
	// Function:  Right	
	// Param[in]: wstr		The input wide string.
	// Param[in]: count		The count of bytes expected to extract for the substring
	// Param[in]: outStr	Return A rightmost substring.
	// Return:    void
	// Remarks:   Extracts the rightmost count as a substring.
	// Notes:
	//************************************
	static void	Right(FS_WideString wstr, FS_StrSize count, FS_WideString* outStr);

	//************************************
	// Function:  Find
	// Param[in]: wstr		The input wide string.
	// Param[in]: wstrSub	The sub-string to be found.
	// Param[in]: start		Specifies the zero-based index of the starting position to do finding.
	// Return:    -1:Not found. 
	//            other value: Specifies position in the string.
	// Remarks:   Finds a sub-string, from specific position. Only first occurrence is found.
	// Notes:
	//************************************
	static FS_StrSize Find(FS_WideString wstr, const FS_WideString wstrSub, FS_StrSize start);

	//************************************
	// Function:  Find2
	// Param[in]: wstr		The input wide string.
	// Param[in]: wch		The character to be found.
	// Param[in]: start		Specifies the zero-based index of the starting position to do finding.
	// Return:    -1: Not found.
	//            other value: Specifies position in the string.
	// Remarks:   Finds a character, from specific position. Only first occurrence is found.
	// Notes:
	//************************************
	static FS_StrSize Find2(FS_WideString wstr, FS_WCHAR wch, FS_StrSize start);

	//************************************
	// Function:  MakeLower
	// Param[in]: wstr	The input wide string.
	// Return:    void
	// Remarks:   Changes case of English letters to lower.
	// Notes:
	//************************************
	static void	MakeLower(FS_WideString wstr);

	//************************************
	// Function:  MakeUpper	
	// Param[in]: wstr	The input wide string.
	// Return:    void
	// Remarks:   Changes case of English letters to upper.
	// Notes:
	//************************************
	static void	MakeUpper(FS_WideString wstr);

	//************************************
	// Function:  TrimRight	
	// Param[in]: wstr	The input wide string.
	// Return:    void
	// Remarks:   Trims white spaces from the right side of the byte string.
	// Notes:
	//************************************
	static void	TrimRight(FS_WideString wstr);

	//************************************
	// Function:  TrimRight2
	// Param[in]: wstr			The input wide string.
	// Param[in]: wchTarget		The specified character.
	// Return:    void
	// Remarks:	  Trims continuous occurrences of specified character from right side of the byte string.
	// Notes:
	//************************************
	static void	TrimRight2(FS_WideString wstr, FS_WCHAR wchTarget);

	//************************************
	// Function:  TrimRight3
	// Param[in]: wstr			The input wide string.
	// Param[in]: wszTargets	The specified characters.
	// Return:    void
	// Remarks:   Trims continuous occurrences of specified characters from right side of the byte string.
	// Notes:
	//************************************
	static void TrimRight3(FS_WideString wstr, FS_LPCWSTR wszTargets);

	//************************************
	// Function:  TrimLeft
	// Param[in]: wstr	The input wide string.
	// Return:    void
	// Remarks:   Trims white spaces from the left side of the byte string.
	// Notes:
	//************************************
	static void	TrimLeft(FS_WideString wstr);

	//************************************
	// Function:  TrimLeft2
	// Param[in]: wstr			The input wide string.
	// Param[in]: wchTarget		The specified character.
	// Return:    void
	// Remarks:   Trims continuous occurrences of specified characters from left side of the byte string.
	// Notes:
	//************************************
	static void	TrimLeft2(FS_WideString wstr, FS_WCHAR wchTarget);

	//************************************
	// Function:  TrimLeft3
	// Param[in]: wstr			The input wide string.
	// Param[in]: wszTargets	The specified characters.
	// Return:    void
	// Remarks:   Trims continuous occurrences of specified characters from left side of the byte string.
	// Notes:
	//************************************
	static void TrimLeft3(FS_WideString wstr, FS_LPCWSTR wszTargets);

	//************************************
	// Function:  Replace
	// Param[in]: wstr			The input wide string.
	// Param[in]: wstrOld		Specified the string to be matched and replaced in the byte string.
	// Param[in]: wstrNew		Specified the string to replace.
	// Return:    The number of replaced patterns.
	// Remarks:   Replace all patterns in the string with a new sub-string.
	// Notes:
	//************************************
	static FS_StrSize Replace(FS_WideString wstr, const FS_WideString wstrOld, const FS_WideString wstrNew);

	//************************************
	// Function:  Remove
	// Param[in]: wstr	The input wide string.
	// Param[in]: wch	Specified the character to be removed.
	// Return:    The number of characters removed.
	// Remarks:   Removes all occurrence of a particular character.
	// Notes:
	//************************************
	static FS_StrSize Remove(FS_WideString wstr, FS_WCHAR wch);



	//************************************
	// Function:  GetInteger 
	// Param[in]: wstr		The input wide string.
	// Return:    A decimal number
	// Remarks:	  Converts to other data type.
	// Notes:
	//************************************
	static FS_INT32 GetInteger(FS_WideString wstr);

	//************************************
	// Function:  FromUTF8
	// Param[in]: wstr		A UTF8 string.
	// Param[in]: len		The length in bytes of the UTF8 string. len can be -1 for zero terminated UTF8 string.
	// Param[out]:outWstr	A wide string.
	// Return:    void
	// Remarks:   Creates a wide string from UTF-8 string (ASCII string compatible).
	// Notes: 
	//************************************
	static void	 FromUTF8(FS_LPSTR wstr, FS_StrSize len, FS_WideString* outWstr);


	//************************************
	// Function:  FromUTF16LE
	// Param[in]: wstr		A UTF16LE encoded string.
	// Param[in]: len		The length in bytes of the UTF16LE encoded string. len can be -1 for zero terminated UTF16LE string.
	// Param[out]:outWstr	A wide string.
	// Return:    void
	// Remarks:   Creates a wide string from UTF16LE encoded string.
	// Notes:     <param>len</param> is number of bytes.
	//************************************
	static void FromUTF16LE(FS_LPWSTR wstr, FS_StrSize len, FS_WideString* outWstr);

	//************************************
	// Function:  UTF8Encode
	// Param[in]: wstrSrc		The input wide string.
	// Param[out]:outEncode		A byte string result.
	// Return:    void
	// Remarks:   Does UTF8 encoding.
	// Notes:
	//************************************
	static void	UTF8Encode(FS_WideString wstrSrc, FS_ByteString* outEncode);


	//************************************
	// Function:  UTF16LE_Encode
	// Param[in]: wstr			The input wide string.
	// Param[in]: bTerminate	need to add terminate symbol? In most of times you can choose 'TRUE'
	// Param[in]: outEncode		A byte string result.
	// Return:    void
	// Remarks:	  Does UTF16LE encoding. Gets UTF-16LE encoded memory block. 
	// Notes:
	//************************************
	static void	UTF16LE_Encode(FS_WideString wstr,FS_BOOL bTerminate, FS_ByteString* outEncode);

	//************************************
	// Function:  CastToLPCWSTR	
	// Param[in]: wstr	The input wide string.
	// Return:   A wide char buffer.
	// Remarks:   Cast the wide string to wide char typed pointer.
	// Notes:
	//************************************
	static FS_LPCWSTR CastToLPCWSTR(FS_WideString wstr);

	//************************************
	// Function:  FormatV	
	// Param[in]: wstr	The input wide string.
	// Param[in]: lpszFormat	Specifies a format-control string.
	// Param[in]: argList Variable-argument lists.
	// Return:    void
	// Remarks:   Formats a number of parameters into this wide string. using va_list.
	// Notes:
	//************************************
	static void FormatV(FS_WideString wstr, FS_LPCWSTR lpszFormat, va_list argList);

	//************************************
	// Function:  FromLocal
	// Param[in]: str		A multi-byte charset string.
	// Param[in]: len		The length in bytes of the multi-byte charset string. len can be -1 for zero terminated multi-byte charset string.
	// Param[out]:outWstr	A wide string.
	// Return:    void
	// Remarks:   Creates a wide string from system multi-byte charset.
	// Notes:
	//************************************
	static void FromLocal(FS_LPSTR str, FS_StrSize len, FS_WideString* outWstr);

	//************************************
	// Function:  FromLocal2
	// Param[in]: str		A multi-byte charset string.
	// Param[out]:outWstr	A wide string.
	// Return:    void
	// Remarks:   Creates a wide string from system multi-byte charset.
	// Notes:
	//************************************
	static void FromLocal2(FS_ByteString str, FS_WideString* outWstr);

	//************************************
	// Function:  CompareNoCase
	// Param[in]: wstr1     The input wide string.
	// Param[in]: wstr2		The wide character string to be compared.
	// Return:    -1 if this string is "smaller" (in alphabetic order) than the other,
	//            0 for equal, 1 for larger in alphabetic order.
	// Remarks:   Compares the string with a wide character string. case-insensitive.
	// Notes:
	//************************************
	static FS_INT32 CompareNoCase( FS_WideString wstr1, FS_LPCWSTR wstr2);

	//************************************
	// Function:  CompareNoCase2
	// Param[in]: wstr1		The input wide string.
	// Param[in]: wstr2		The wide string to be compared.
	// Return:    -1 if this string is "smaller" (in alphabetic order) than the other,
	//            0 for equal, 1 for larger in alphabetic order.
	// Remarks:   Compares the the string with another. case-insensitive.
	// Notes:
	//************************************
	static FS_INT32 CompareNoCase2( FS_WideString wstr1, const FS_WideString wstr2);

	//************************************
	// Function:  ConvertFrom
	// Param[in]: wstr		The input wide string.
	// Param[in]: str		A byte string.
	// Param[in]: pCharMap	A character mapper. Invokes <a>FSCharMapGetDefaultMapper</a> to get the default mapper.
	// Return: void
	// Remarks: Loads MBCS data into this wide string, using specified character mapper.
	// If no character mapper specified, the system default mapper will be used.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
	//************************************
	static void ConvertFrom(FS_WideString wstr, FS_ByteString str, FS_CharMap pCharMap);

	//************************************
	// Function:  FromLocal
	// Param[in]: str		A multi-byte charset string.
	// Param[in]: len		The length in bytes of the multi-byte charset string. len can be -1 for zero terminated multi-byte charset string.
	// Param[out]:outWstr	A wide string.
	// Return:    void
	// Remarks:   Creates a wide string from system multi-byte charset.
	// Notes:
	//************************************
	static void FromLocal3(FS_LPCSTR str, FS_StrSize len, FS_WideString* outWstr);
	
	 //************************************
	 // Function:  GetFloat
	 // Param[in]: str		A multi-byte charset string.
	 // Return:    A floating point number.
	 // Remarks:   Convert to other data type.
	 // Notes:
	 //************************************
	static FS_FLOAT				GetFloat(FS_WideString wstr);

	//************************************
	// Function:  Find3
	// Param[in]: wstr		The input wide string.
	// Param[in]: wstrSub	The sub-string to be found.
	// Param[in]: start		Specifies the zero-based index of the starting position to do finding.
	// Return:    -1:Not found. 
	//            other value: Specifies position in the string.
	// Remarks:   Finds a sub-string, from specific position. Only first occurrence is found.
	// Notes:
	//************************************
	static FS_StrSize Find3(FS_WideString wstr, const FS_LPCWSTR wstrSub, FS_StrSize start);
};

class CFS_UnicodeMgr_V17
{
public:
	//************************************
	// Function:  GetUnicodeGeneralCategory
	// Param[in]: code	    codepoint.
	// Return:    value according to FS_UNICODE_GENERAL_CATEGORY.
	// Remarks:  Get the general category.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_UNICODE_GENERAL_CATEGORY GetUnicodeGeneralCategory(FS_WCHAR code);

	 //************************************
	 // Function:  EastAsianWidth
	 // Param[in]: unicode	    Unicode codepoint.
	 // Return:   FS_UNICODE_WIDTH  value according to FS_UNICODE_WIDTH.
	 // Remarks:  Get east-asian width of a unicode.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	 //************************************
	static FS_UNICODE_WIDTH	 EastAsianWidth(FS_WCHAR unicode);

	//************************************
    // Function:  NFKD
	// Param[in]: unicode	    Points to the unicode string buffer.
	// Param[in]: len	        Length of the unicode string buffer (FX_WCHAR).
	// Param[out]: nfkd_unicode  Newly allocated Unicode string, that is the NFKD normalized form of @unicode.
	// Param[in]: nfkd_len	    Length of the NFKD normalized string.
	// Return:   FS_BOOLEAN     false means either the unicode string includes invalid characters or the unicode string is empty.
	// Remarks:  Get east-asian width of a unicode.
	// Notes: The @nfkd_unicode must ::FSCodeTransformationMemFree by user.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0	
	//************************************
	static FS_BOOLEAN NFKD(const FS_WCHAR* unicode, FS_INT32 len, FS_WCHAR** nfkd_unicode, FS_INT32* nfkd_len);
};

#ifdef __cplusplus
};
#endif

#endif

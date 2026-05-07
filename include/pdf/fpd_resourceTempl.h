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
/* Font HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFontNew
 * @details Creates a new PDF font object from a font dictionary.
 * @param[in]  doc The PDF document.
 * @param[in]  dic The font dictionary.
 * @return   A new PDF font object.
 * @note 
 */
INTERFACE(FPD_Font, FPDFontNew, (FPD_Document doc,  FPD_Object dic))

/**
 * @brief FPDFontDestroy
 * @details Destroys the PDF font object.
 * @param[in]  font The input PDF font object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFontDestroy, (FPD_Font font))

/**
 * @brief FPDFontGetStockFont
 * @details Gets the "stocked" fonts (Adobe base 14 fonts), which are always available for rendering activities.
	*            However, these fonts can't be directly referred in any document, unless the font resource is added to the document.
 * @param[in]  fpdDoc The document associated with the font name.
 * @param[in]  szFontName The font name.
 * @return   Return a pdf font.
 * @note List of currently supported standard fonts:<br>
	*            <ul>
	*            <li>Courier, Courier-Bold, Courier-BoldOblique, Courier-Oblique.</li>
	*            <li>Helvetica, Helvetica-Bold, Helvetica-BoldOblique, Helvetica-Oblique.</li>
	*            <li>Times-Roman, Times-Bold, Times-Italic, Times-BoldItalic.</li>
	*            <li>Symbol, ZapfDingbats.</li>
	*            </ul>
 */
INTERFACE(FPD_Font, FPDFontGetStockFont, (FPD_Document fpdDoc,  FS_LPCSTR szFontName))

/**
 * @brief FPDFontGetFontType
 * @details Gets the font type.
 * @param[in]  font The input PDF font object.
 * @return   The font type.
 * @note 
 */
INTERFACE(FS_INT32, FPDFontGetFontType, (FPD_Font font))

/**
 * @brief FPDFontGetFontTypeName
 * @details Gets the font type name.
 * @param[in]  font The input PDF font object.
 * @param[out]  outName The font type name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFontGetFontTypeName, (FPD_Font font,  FS_ByteString* outName))

/**
 * @brief FPDFontGetBaseFont
 * @details Gets the base font name.
 * @param[in]  font The input PDF font object.
 * @param[out]  outFontName It receives the base font name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFontGetBaseFont, (FPD_Font font,  FS_ByteString* outFontName))

/**
 * @brief FPDFontGetSubstFont
 * @details Gets the substitute font.
 * @param[in]  font The input PDF font object.
 * @return   The substitute font.
 * @note 
 */
INTERFACE(FPD_SubstFont, FPDFontGetSubstFont, (FPD_Font font))

/**
 * @brief FPDFontGetFlags
 * @details Gets the font flags.
 * @param[in]  font The input PDF font object.
 * @return   The font flags.
 * @note 
 */
INTERFACE(FS_DWORD, FPDFontGetFlags, (FPD_Font font))

/**
 * @brief FPDFontGetType1Font
 * @details Gets a type1 font.
 * @param[in]  font The input PDF font object.
 * @return   A type1 font.
 * @note 
 */
INTERFACE(FPD_Font, FPDFontGetType1Font, (FPD_Font font))

/**
 * @brief FPDFontGetTrueTypeFont
 * @details Gets a true type font.
 * @param[in]  font The input PDF font object.
 * @return   A True-type font.
 * @note 
 */
INTERFACE(FPD_Font, FPDFontGetTrueTypeFont, (FPD_Font font))

/**
 * @brief FPDFontGetCIDFont
 * @details Gets a CID font.
 * @param[in]  font The input PDF font object.
 * @return   A CID font.
 * @note 
 */
INTERFACE(FPD_Font, FPDFontGetCIDFont, (FPD_Font font))

/**
 * @brief FPDFontGetType3Font
 * @details Gets a type3 font.
 * @param[in]  font The input PDF font object.
 * @return   A type3 font.
 * @note 
 */
INTERFACE(FPD_Font, FPDFontGetType3Font, (FPD_Font font))

/**
 * @brief FPDFontIsEmbedded
 * @details Checks whether the font is an embedded font.
 * @param[in]  font The input PDF font object.
 * @return   <a>TRUE</a> if the font is an embedded font, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFontIsEmbedded, (FPD_Font font))

/**
 * @brief FPDFontIsUnicodeCompatible
 * @details Checks whether the font is Unicode compatible.
 * @param[in]  font The input PDF font object.
 * @return   <a>TRUE</a> if the font is Unicode compatible, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFontIsUnicodeCompatible, (FPD_Font font))

/**
 * @brief FPDFontGetFontFile
 * @details Gets the font stream.
 * @param[in]  font The input PDF font object.
 * @return   The font stream.
 * @note 
 */
INTERFACE(FPD_StreamAcc, FPDFontGetFontFile, (FPD_Font font))

/**
 * @brief FPDFontGetFontDict
 * @details Gets the font dictionary.
 * @param[in]  font The input PDF font object.
 * @return   The font dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDFontGetFontDict, (FPD_Font font))

/**
 * @brief FPDFontIsStandardFont
 * @details Checks whether the font is a standard font.
 * @param[in]  font The input PDF font object.
 * @return   <a>TRUE</a> if the font is a standard font, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFontIsStandardFont, (FPD_Font font))

/**
 * @brief FPDFontGetFace
 * @details Gets embedded or substituted FT font face.
 * @param[in]  font The input PDF font object.
 * @return   The embedded or substituted FT font face.
 * @note 
 */
INTERFACE(FPD_FT_Face, FPDFontGetFace, (FPD_Font font))

/**
 * @brief FPDFontGetNextChar
 * @details Gets a charcode from a string at specified position.
 * @param[in]  font The input PDF font object.
 * @param[in]  str The char buffer.
 * @param[in,out]  inOutOffset Input the zero-based position and receive the next charcode position.
 * @return   A charcode with next char.
 * @note 
 */
INTERFACE(FS_DWORD, FPDFontGetNextChar, (FPD_Font font,  FS_LPCSTR str,  FS_INT32* inOutOffset))

/**
 * @brief FPDFontCountChar
 * @details Gets the count of characters in a string.
 * @param[in]  font The input PDF font object.
 * @param[in]  str The string buffer.
 * @param[in]  size The length in bytes of the string.
 * @return   The count of characters in the string.
 * @note 
 */
INTERFACE(FS_INT32, FPDFontCountChar, (FPD_Font font,  FS_LPCSTR str,  FS_INT32 size))

/**
 * @brief FPDFontAppendChar
 * @details Append a charcode to a string buffer.
 * @param[in]  font The input PDF font object.
 * @param[in,out]  inOutStr Input a string buffer and append a charcode to it.
 * @param[in]  charcode The charcode to append.
 * @return   The number of bytes appended to the string buffer.
 * @note 
 */
INTERFACE(FS_INT32, FPDFontAppendChar, (FPD_Font font,  FS_LPSTR inOutStr,  FS_DWORD charcode))

/**
 * @brief FPDFontAppendChar2
 * @details Append a charcode to a string buffer.
 * @param[in]  font The input PDF font object.
 * @param[in,out]  str Input a string buffer and append a charcode to it.
 * @param[in]  charcode The charcode to append.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDFontAppendChar2, (FPD_Font font,  FS_ByteString str,  FS_DWORD charcode))

/**
 * @brief FPDFontGetCharSize
 * @details Gets the number of bytes for the char code.
 * @param[in]  font The input PDF font object.
 * @param[in]  charcode Input a charcode.
 * @return   The number of bytes for the char code.
 * @note 
 */
INTERFACE(FS_INT32, FPDFontGetCharSize, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDFontGlyphFromCharCode
 * @details Gets the glyph index for a charcode.
 * @param[in]  font The input PDF font object.
 * @param[in]  charcode The charcode.
 * @return   The glyph index of the charcode.  Return -1 for unknown.
 * @note For embedded font only.
 */
INTERFACE(FS_INT32, FPDFontGlyphFromCharCode, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDFontUnicodeFromCharCode
 * @details Gets a unicode string for a charcode.
 * @param[in]  font The input PDF font object.
 * @param[in]  charcode The charcode.
 * @param[out]  outUnicode The unicode string for the charcode. NULL for unknown.
 * @return   
 * @note 
 */
INTERFACE(void, FPDFontUnicodeFromCharCode, (FPD_Font font,  FS_DWORD charcode,  FS_WideString* outUnicode))

/**
 * @brief FPDFontCharCodeFromUnicode
 * @details Gets a charcode from a Unicode.
 * @param[in]  font The input PDF font object.
 * @param[in]  unicode The charcode.
 * @return   The charcode for the unicode.
 * @note 
 */
INTERFACE(FS_DWORD, FPDFontCharCodeFromUnicode, (FPD_Font font,  FS_WCHAR unicode))

/**
 * @brief FPDFontIsCharEmbedded
 * @details Checks whether a character is embedded.
 * @param[in]  font The input PDF font object.
 * @param[in]  charcode The charcode.
 * @return   <a>TRUE</a> if a character is embedded, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFontIsCharEmbedded, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDFontGetCharMap
 * @details Gets the character map.
 * @param[in]  font The input PDF font object.
 * @return   The character map.
 * @note 
 */
INTERFACE(FS_CharMap, FPDFontGetCharMap, (FPD_Font font))

/**
 * @brief FPDFontEncodeString
 * @details Encode an unicode string to font string.
 * @param[in]  font The input PDF font object.
 * @param[in]  wszSrc The unicode string.
 * @param[out]  outEncodeString The encoded font string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFontEncodeString, (FPD_Font font,  FS_LPCWSTR wszSrc,  FS_ByteString* outEncodeString))

/**
 * @brief FPDFontDecodeString
 * @details Decode a font string to unicode string.
 * @param[in]  font The input PDF font object.
 * @param[in]  src The source font string.
 * @param[out]  outResult The decoded unicode string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFontDecodeString, (FPD_Font font,  FS_LPCSTR src,  FS_WideString* outResult))

/**
 * @brief FPDFontRecognizeChar
 * @details Use OCR to recognize a character and return Unicode.
 * @param[in]  font The input PDF font object.
 * @param[in]  charcode The charcode.
 * @return   The recognized unicode.
 * @note This function may be called when UnicodeFromCharCode() fails to get a character
 */
INTERFACE(FS_WCHAR, FPDFontRecognizeChar, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDFontGetFontBBox
 * @details Gets the font's bounding box.
 * @param[in]  font The input PDF font object.
 * @return   The font's bounding box.
 * @note 
 */
INTERFACE(FS_Rect, FPDFontGetFontBBox, (FPD_Font font))

/**
 * @brief FPDFontGetTypeAscent
 * @details Gets the typographic ascent.
 * @param[in]  font The input PDF font object.
 * @return   The typographic ascent.
 * @note 
 */
INTERFACE(FS_INT32, FPDFontGetTypeAscent, (FPD_Font font))

/**
 * @brief FPDFontGetTypeDescent
 * @details Gets the typographic descent, most negative.
 * @param[in]  font The input PDF font object.
 * @return   The typographic descent, most negative.
 * @note 
 */
INTERFACE(FS_INT32, FPDFontGetTypeDescent, (FPD_Font font))

/**
 * @brief FPDFontGetItalicAngle
 * @details Gets the angle, expressed in degrees counterclockwise from the vertical, of the dominant vertical strokes of the font.
 * @param[in]  font The input PDF font object.
 * @return   The angle.
 * @note 
 */
INTERFACE(FS_INT32, FPDFontGetItalicAngle, (FPD_Font font))

/**
 * @brief FPDFontGetStringWidth
 * @details Gets a string's width.
 * @param[in]  font The input PDF font object.
 * @param[in]  pCharBuf The char buffer. Must be in font encoding.
 * @param[in]  size The length in bytes of the string.
 * @return   The width of the string.
 * @note 
 */
INTERFACE(FS_INT32, FPDFontGetStringWidth, (FPD_Font font,  const FS_CHAR* pCharBuf,  FS_INT32 size))

/**
 * @brief FPDFontGetCharWidthF
 * @details Gets a character's PDF width.
 * @param[in]  font The input PDF font object.
 * @param[in]  charcode The character code.
 * @return   The PDF width of the character.
 * @note 
 */
INTERFACE(FS_INT32, FPDFontGetCharWidthF, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDFontGetCharTypeWidth
 * @details Gets a character's real width in the font file.
 * @param[in]  font The input PDF font object.
 * @param[in]  charcode The character code.
 * @return   The real width of the character
 * @note 
 */
INTERFACE(FS_INT32, FPDFontGetCharTypeWidth, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDFontGetCharBBox
 * @details Gets the bounding box of a character.
 * @param[in]  font The input PDF font object.
 * @param[in]  Input The charcode a character code.
 * @return   The bounding box of a character.
 * @note 
 */
INTERFACE(FS_Rect, FPDFontGetCharBBox, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDFontGetPDFDoc
 * @details Gets the PDF document.
 * @param[in]  font The input PDF font object.
 * @return   The PDF document.
 * @note 
 */
INTERFACE(FPD_Document, FPDFontGetPDFDoc, (FPD_Font font))

/**
 * @brief FPDFontLoadGlyphPath
 * @details Gets a character's path data. for T1, TT, and CIDFont only.
 * @param[in]  font The input PDF font object.
 * @param[in]  charcode The character code.
 * @param[in]  destWidth The destination's width.
 * @return   A character's path data. for T1, TT, and CIDFont only.
 * @note 
 */
INTERFACE(FPD_Path, FPDFontLoadGlyphPath, (FPD_Font font,  FS_DWORD charcode,  FS_INT32 destWidth))

/**
 * @brief FPDFontGetSubstFontCharset
 * @details Gets the charset of the substitution font.
 * @param[in]  substFont The input substitution font object.
 * @return   The charset of the substitution font.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_INT32, FPDFontGetSubstFontCharset, (FPD_SubstFont substFont))

/**
 * @brief FPDFontIsVertWriting
 * @details Checks whether the font is vertical writing.
 * @param[in]  font The input PDF font object.
 * @return   <a>TRUE</a> if the PDF font is vertical writing.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FPDFontIsVertWriting, (FPD_Font font))

/**
 * @brief FPDFontGetFXFont
 * @details Gets the Foxit GE font.
 * @param[in]  font The input PDF font object.
 * @return   The Foxit GE font.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FPD_FXFont, FPDFontGetFXFont, (FPD_Font font))

/**
 * @brief FPDFontFXFontGetFaceName
 * @details Gets the face name of the Foxit GE font.
 * @param[in]  font The input Foxit GE font object.
 * @param[out]  outFaceName It receives the face name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDFontFXFontGetFaceName, (FPD_FXFont font,  FS_ByteString* outFaceName))

/**
 * @brief FPDFontFXFontGetPsName
 * @details Gets the postscript name of the Foxit GE font.
 * @param[in]  font The input Foxit GE font object.
 * @param[out]  outPsName It receives the postscript name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDFontFXFontGetPsName, (FPD_FXFont font,  FS_WideString* outPsName))

/**
 * @brief FPDFontFXFontGetFamilyName
 * @details Gets the family name of the Foxit GE font.
 * @param[in]  font The input Foxit GE font object.
 * @param[out]  outFamilyName It receives the face name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDFontFXFontGetFamilyName, (FPD_FXFont font,  FS_ByteString* outFamilyName))

/**
 * @brief FPDFontFXFontIsItalic
 * @details Checks whether it is italic font or not.
 * @param[in]  font The input Foxit GE font object.
 * @return   TRUE if it is italic font, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FPDFontFXFontIsItalic, (FPD_FXFont font))

/**
 * @brief FPDFontFXFontIsBold
 * @details Checks whether it is bold font or not.
 * @param[in]  font The input Foxit GE font object.
 * @return   TRUE if it is bold font, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FPDFontFXFontIsBold, (FPD_FXFont font))

/**
 * @brief FPDFontUnicodeFromCharCodeEx
 * @details Gets a unicode string for a charcode. We will use "/Encoding" first if "/Encoding" is neither "Identity-H" nor "Identity-V".
 * @param[in]  font The input PDF font object.
 * @param[in]  charcode The charcode.
 * @param[out]  outUnicode The unicode string for the charcode. NULL for unknown.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDFontUnicodeFromCharCodeEx, (FPD_Font font,  FS_DWORD charcode,  FS_WideString* outUnicode))

/**
 * @brief FPDFontGetSubstFontWeight
 * @details Gets the weight parameter, non-zero for synthetic weight generation only.
 * @param[in]  substFont The input substitution font object.
 * @return   The weight parameter, non-zero for synthetic weight generation only.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_INT32, FPDFontGetSubstFontWeight, (FPD_SubstFont substFont))

/**
 * @brief FPDFontFXFontLoadSubst
 * @details Loads a font through font mapper.
 * @param[in]  font The input Foxit GE font object.
 * @param[in]  lpsFaceName PostScript name.
 * @param[in]  bTrueType TrueType or Type1.
 * @param[in]  flags PDF font flags (see PDF Reference section 5.7.1).
 * @param[in]  weight Original font weight. 0 for not specified.
 * @param[in]  nItalicAngle Original font italic angle. 0 for not specified.
 * @param[in]  nCharsetCP Code page for charset (see Win32 GetACP()).
 * @param[in]  bVertical Whether vertical writing-mode. Sets it FALSE as default.
 * @return   TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.0.0
 */
INTERFACE(FS_BOOL, FPDFontFXFontLoadSubst, (FPD_FXFont font,  FS_LPCSTR lpsFaceName,  FS_BOOL bTrueType,  FS_DWORD flags,  FS_INT32 weight,  FS_INT32 nItalicAngle,  FS_INT32 nCharsetCP,  FS_BOOL bVertical))

/**
 * @brief FPDFontGetUnicodeBaseFont
 * @details Get unicode base font.
 * @param[in]  font The input font object.
 * @param[out]  outUnicode The unicode string for the charcode.NULL for unknown.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.0.0
 */
INTERFACE(void, FPDFontGetUnicodeBaseFont, (FPD_Font font,  FS_WideString* outUnicode))

/**
 * @brief FPDFontIsTTFont
 * @details Check whether it is truetype font.
 * @param[in]  font The input font object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDFontIsTTFont, (FPD_FXFont font))

/**
 * @brief FPDFontNewFXFont
 * @details Creates the Foxit GE font.
 * @return   The Foxit GE font.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 */
INTERFACE(FPD_FXFont, FPDFontNewFXFont, (void))

/**
 * @brief FPDFontDeleteFXFont
 * @details Delete FPD_FXFont object.
 * @param[in]  fxFont The input FPD_FXFont object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 */
INTERFACE(void, FPDFontDeleteFXFont, (FPD_FXFont fxFont))

/**
 * @brief FPDFontGetCharOutBBox
 * @details Get the typographic(display and printing) bounding box of a character.
 * @param[in]  font The input FPD_FXFont object.
 * @param[in]  charcode Input a character code.
 * @param[out]  rect It receives the typographic bounding box of the character.
 * @param[in]  level Recursive level control, optional.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 */
INTERFACE(void, FPDFontGetCharOutBBox, (FPD_Font font,  FS_DWORD charcode,  FS_Rect* rect,  FS_INT32 level))

NumOfSelector(FPDFont)
ENDENUM

//*****************************
/* FontEncoding HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFontEncodingNew
 * @details Creates a new single byte font encoding used by T1 or TT fonts.
 * @param[in]  void 
 * @return   A new font encoding.
 * @note 
 */
INTERFACE(FPD_FontEncoding, FPDFontEncodingNew, (void))

/**
 * @brief FPDFontEncodingNew2
 * @details Creates a new font encoding with a predefined encoding.
 * @param[in]  PredefinedEncoding The input predefined encoding.
 * @return   A new font encoding.
 * @note 
 */
INTERFACE(FPD_FontEncoding, FPDFontEncodingNew2, (int PredefinedEncoding))

/**
 * @brief FPDFontEncodingDestroy
 * @details Destroys the font encoding.
 * @param[in]  fontEncoding The input font encoding.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFontEncodingDestroy, (FPD_FontEncoding fontEncoding))

/**
 * @brief FPDFontEncodingLoadEncoding
 * @details Loads encoding from a PDF encoding object.
 * @param[in]  fontEncoding The input font encoding.
 * @param[in]  encoding The PDF object of encoding.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFontEncodingLoadEncoding, (FPD_FontEncoding fontEncoding,  FPD_Object encoding))

/**
 * @brief FPDFontEncodingIsIdentical
 * @details Checks whether the encoding is identical with another encoding.
 * @param[in]  fontEncoding The input font encoding.
 * @param[in]  another The another encoding.
 * @return   <a>TRUE</a> means identical, <a>FLASE</a> not identical.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFontEncodingIsIdentical, (FPD_FontEncoding fontEncoding,  FPD_FontEncoding another))

/**
 * @brief FPDFontEncodingUnicodeFromCharCode
 * @details Gets the unicode from a charcode.
 * @param[in]  fontEncoding The input font encoding.
 * @param[in]  charcode The input charcode.
 * @return   The unicode of the charcode.
 * @note 
 */
INTERFACE(FS_WCHAR, FPDFontEncodingUnicodeFromCharCode, (FPD_FontEncoding fontEncoding,  FS_BYTE charcode))

/**
 * @brief FPDFontEncodingCharCodeFromUnicode
 * @details Gets the charcode from a unicode.
 * @param[in]  fontEncoding The input font encoding.
 * @param[in]  unicode The unicode char code.
 * @return   The charcode of the unicode. -1 for not found.
 * @note 
 */
INTERFACE(FS_INT32, FPDFontEncodingCharCodeFromUnicode, (FPD_FontEncoding fontEncoding,  FS_WCHAR unicode))

/**
 * @brief FPDFontEncodingSetUnicode
 * @details Sets the unicode of a charcode.
 * @param[in]  fontEncoding The input font encoding.
 * @param[in]  charcode Input a charcode.
 * @param[in]  unicode The new unicode value for the charcode.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFontEncodingSetUnicode, (FPD_FontEncoding fontEncoding,  FS_BYTE charcode,  FS_WCHAR unicode))

/**
 * @brief FPDFontEncodingRealize
 * @details Realizes the font encoding in a PDF encoding object. Can be NULL is not needed.
 * @param[in]  fontEncoding The input font encoding.
 * @return   A new PDF encoding object corresponding to the encoding table.
 * @note 
 */
INTERFACE(FPD_Object, FPDFontEncodingRealize, (FPD_FontEncoding fontEncoding))

NumOfSelector(FPDFontEncoding)
ENDENUM

//*****************************
/* Type1Font HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDType1FontNew
 * @details Creates a new empty PDF type1 font.
 * @param[in]  void 
 * @return   A new empty PDF type1 font.
 * @note 
 */
INTERFACE(FPD_Font, FPDType1FontNew, (void))

/**
 * @brief FPDType1FontDestroy
 * @details Destroys the PDF type1 font.
 * @param[in]  font The input PDF type1 font.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDType1FontDestroy, (FPD_Font font))

/**
 * @brief FPDType1FontGetEncoding
 * @details Gets the font encoding.
 * @param[in]  font The input PDF type1 font.
 * @return   The font encoding.
 * @note 
 */
INTERFACE(FPD_FontEncoding, FPDType1FontGetEncoding, (FPD_Font font))

/**
 * @brief FPDType1FontGetCharWidthF
 * @details The PDF width of the character.
 * @param[in]  font The input PDF type1 font.
 * @param[in]  charcode Input a charcode.
 * @return   The PDF width of the character.
 * @note 
 */
INTERFACE(FS_INT32, FPDType1FontGetCharWidthF, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDType1FontGetCharBBox
 * @details Gets the bounding box of a character.
 * @param[in]  font The input PDF type1 font.
 * @param[in]  charcode Input a charcode.
 * @return   The bounding box of a character.
 * @note 
 */
INTERFACE(FS_Rect, FPDType1FontGetCharBBox, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDType1FontGlyphFromCharCode
 * @details Gets the glyph index for a charcode.
 * @param[in]  font The input PDF type1 font.
 * @param[in]  charcode Input a charcode.
 * @return   The glyph index of the charcode.  Return -1 for unknown.
 * @note For embedded font only.
 */
INTERFACE(FS_INT32, FPDType1FontGlyphFromCharCode, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDType1FontIsUnicodeCompatible
 * @details Tests whether the Type1 font is compatible for unicode.
 * @param[in]  font The input PDF type1 font.
 * @return   <a>TRUE</a> if the font is compatible for unicode, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDType1FontIsUnicodeCompatible, (FPD_Font font))

/**
 * @brief FPDType1FontGetBase14Font
 * @details Gets an ID of standard 14 font.
 * @param[in]  font The input PDF type1 font.
 * @return   An ID of standard 14 font. -1 for none. See list of standard fonts in PDF Reference.
 * @note 
 */
INTERFACE(FS_INT32, FPDType1FontGetBase14Font, (FPD_Font font))

NumOfSelector(FPDType1Font)
ENDENUM

//*****************************
/* TrueTypeFont HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDTrueTypeFontNew
 * @details Creates a new True-type font.
 * @param[in]  void 
 * @return   A new empty PDF True-type font.
 * @note 
 */
INTERFACE(FPD_Font, FPDTrueTypeFontNew, (void))

/**
 * @brief FPDTrueTypeFontDestroy
 * @details Destroys the True-type font.
 * @param[in]  font The input True-type font.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTrueTypeFontDestroy, (FPD_Font font))

/**
 * @brief FPDTrueTypeFontGetEncoding
 * @details Gets the font encoding.
 * @param[in]  font The input True-type font.
 * @return   The font encoding.
 * @note 
 */
INTERFACE(FPD_FontEncoding, FPDTrueTypeFontGetEncoding, (FPD_Font font))

/**
 * @brief FPDTrueTypeFontGetCharWidthF
 * @details The PDF width of the character.
 * @param[in]  font The input True-type font.
 * @param[in]  charcode Input a charcode.
 * @return   The PDF width of the character.
 * @note 
 */
INTERFACE(FS_INT32, FPDTrueTypeFontGetCharWidthF, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDTrueTypeFontGetCharBBox
 * @details Gets the bounding box of a character.
 * @param[in]  font The input True-type font.
 * @param[in]  charcode Input a charcode.
 * @return   The bounding box of a character.
 * @note 
 */
INTERFACE(FS_Rect, FPDTrueTypeFontGetCharBBox, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDTrueTypeFontGlyphFromCharCode
 * @details Gets the glyph index for a charcode.
 * @param[in]  font The input True-type font.
 * @param[in]  charcode Input a charcode.
 * @return   The glyph index of the charcode.  Return -1 for unknown.
 * @note For embedded font only.
 */
INTERFACE(FS_INT32, FPDTrueTypeFontGlyphFromCharCode, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDTrueTypeFontIsUnicodeCompatible
 * @details Tests whether a True-type font is compatible for unicode.
 * @param[in]  font The input True-type font.
 * @return   <a>TRUE</a> if the font is compatible for unicode, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDTrueTypeFontIsUnicodeCompatible, (FPD_Font font))

NumOfSelector(FPDTrueTypeFont)
ENDENUM

//*****************************
/* Type3Char HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDType3CharNew
 * @details Creates a new empty type3 character information object.
 * @param[in]  void 
 * @return   A new empty type3 character information object.
 * @note 
 */
INTERFACE(FPD_Type3Char, FPDType3CharNew, (void))

/**
 * @brief FPDType3CharDestroy
 * @details Destroys the type3 character information object.
 * @param[in]  type3char The input type3 character information object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDType3CharDestroy, (FPD_Type3Char type3char))

/**
 * @brief FPDType3CharIsColored
 * @details Tests whether the type3 character is colored.
 * @param[in]  type3char The input type3 character information object.
 * @return   <a>TRUE</a> if the type3 character is colored, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDType3CharIsColored, (FPD_Type3Char type3char))

/**
 * @brief FPDType3CharIsPageRequired
 * @details Tests whether the Type3 font is using a page resource.
 * @param[in]  type3char The input type3 character information object.
 * @return   <a>TRUE</a> if using a page resource therefore we can't load the char.
 * @note 
 */
INTERFACE(FS_BOOL, FPDType3CharIsPageRequired, (FPD_Type3Char type3char))

/**
 * @brief FPDType3CharGetForm
 * @details Gets the form pointer if it's a form.
 * @param[in]  type3char The input type3 character information object.
 * @return   The form pointer if it's a form.
 * @note 
 */
INTERFACE(FPD_Form, FPDType3CharGetForm, (FPD_Type3Char type3char))

/**
 * @brief FPDType3CharGetImageMatrix
 * @details Gets the image matrix if it's a image
 * @param[in]  type3char The input type3 character information object.
 * @return   The image matrix if it's a image
 * @note 
 */
INTERFACE(FS_AffineMatrix, FPDType3CharGetImageMatrix, (FPD_Type3Char type3char))

/**
 * @brief FPDType3CharGetDIBitmap
 * @details Gets the image pointer if it's a image.
 * @param[in]  type3char The input type3 character information object.
 * @return   The image pointer if it's a image.
 * @note 
 */
INTERFACE(FS_DIBitmap, FPDType3CharGetDIBitmap, (FPD_Type3Char type3char))

/**
 * @brief FPDType3CharGetWidth
 * @details Gets the character width. In font coordinate (1/1000 of em).
 * @param[in]  type3char The input type3 character information object.
 * @return   The character width. In font coordinate (1/1000 of em).
 * @note 
 */
INTERFACE(FS_INT32, FPDType3CharGetWidth, (FPD_Type3Char type3char))

/**
 * @brief FPDType3CharGetBBox
 * @details Gets the character's bounding box. In font coordinate (1/1000 of em).
 * @param[in]  type3char The input type3 character information object.
 * @return   The character's bounding box. In font coordinate (1/1000 of em).
 * @note 
 */
INTERFACE(FS_Rect, FPDType3CharGetBBox, (FPD_Type3Char type3char))

NumOfSelector(FPDType3Char)
ENDENUM

//*****************************
/* Type3Font HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDType3FontNew
 * @details Creates a new empty Type3 font.
 * @param[in]  void 
 * @return   A new empty Type3 font.
 * @note 
 */
INTERFACE(FPD_Font, FPDType3FontNew, (void))

/**
 * @brief FPDType3FontDestroy
 * @details Destroys the Type3 font.
 * @param[in]  font The input Type3 font.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDType3FontDestroy, (FPD_Font font))

/**
 * @brief FPDType3FontGetEncoding
 * @details Gets the font encoding.
 * @param[in]  font The input Type3 font.
 * @return   The font encoding.
 * @note 
 */
INTERFACE(FPD_FontEncoding, FPDType3FontGetEncoding, (FPD_Font font))

/**
 * @brief FPDType3FontGetCharWidthF
 * @details Gets the PDF width of the character.
 * @param[in]  font The input Type3 font.
 * @param[in]  charcode Input a charcode.
 * @return   The PDF width of the character.
 * @note 
 */
INTERFACE(FS_INT32, FPDType3FontGetCharWidthF, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDType3FontGetCharBBox
 * @details Gets the bounding box of a character.
 * @param[in]  font The input Type3 font.
 * @param[in]  charcode Input a charcode.
 * @return   The bounding box of a character.
 * @note 
 */
INTERFACE(FS_Rect, FPDType3FontGetCharBBox, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDType3FontGlyphFromCharCode
 * @details Gets the glyph index for a charcode.
 * @param[in]  font The input Type3 font.
 * @param[in]  charcode Input a charcode.
 * @return   The glyph index of the charcode.  Return -1 for unknown.
 * @note For embedded font only.
 */
INTERFACE(FS_INT32, FPDType3FontGlyphFromCharCode, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDType3FontIsUnicodeCompatible
 * @details Tests whether a Type3 font is compatible for unicode.
 * @param[in]  font The input Type3 font.
 * @return   <a>TRUE</a> if font is compatible for unicode, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDType3FontIsUnicodeCompatible, (FPD_Font font))

/**
 * @brief FPDType3FontSetPageResources
 * @details Sets Page resources.
 * @param[in]  font The input Type3 font.
 * @param[in]  resourcesDic the Dictionary contenting the resource.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDType3FontSetPageResources, (FPD_Font font,  FPD_Object resourcesDic))

/**
 * @brief FPDType3FontLoadChar
 * @details Loads a character.
 * @param[in]  font The input Type3 font.
 * @param[in]  charcode Input a charcode.
 * @return   The type3 character information.
 * @note 
 */
INTERFACE(FPD_Type3Char, FPDType3FontLoadChar, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDType3FontGetCharTypeWidth
 * @details Gets the PDF width of the character.
 * @param[in]  font The input Type3 font.
 * @param[in]  charcode The input character code.
 * @return   the PDF width of the character.
 * @note 
 */
INTERFACE(FS_INT32, FPDType3FontGetCharTypeWidth, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDType3FontGetFontMatrix
 * @details Gets the matrix of the font.
 * @param[in]  font The input Type3 font.
 * @return   The matrix of the font.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FPDType3FontGetFontMatrix, (FPD_Font font))

NumOfSelector(FPDType3Font)
ENDENUM

//*****************************
/* CIDFont HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDCIDFontNew
 * @details Creates a new empty CID specific font.
 * @param[in]  void 
 * @return   A new empty CID specific font.
 * @note 
 */
INTERFACE(FPD_Font, FPDCIDFontNew, (void))

/**
 * @brief FPDCIDFontDestroy
 * @details Destroys the CID specific font.
 * @param[in]  font The input CID specific font.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDCIDFontDestroy, (FPD_Font font))

/**
 * @brief FPDCIDFontGetCharWidthF
 * @details Gets the font char width.
 * @param[in]  font The input CID specific font.
 * @param[in]  charcode Input a charcode.
 * @return   The font char width.
 * @note 
 */
INTERFACE(FS_INT32, FPDCIDFontGetCharWidthF, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDCIDFontGetCharBBox
 * @details Gets the char bounding box.
 * @param[in]  font The input CID specific font.
 * @param[in]  charcode Input a charcode.
 * @return   The char bounding box.
 * @note 
 */
INTERFACE(FS_Rect, FPDCIDFontGetCharBBox, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDCIDFontGlyphFromCharCode
 * @details The glyph index for a charcode.
 * @param[in]  font The input CID specific font.
 * @param[in]  charcode Input a charcode.
 * @return   The glyph index of the charcode.  Return -1 for unknown.
 * @note For embedded font only.
 */
INTERFACE(FS_INT32, FPDCIDFontGlyphFromCharCode, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDCIDFontIsUnicodeCompatible
 * @details Tests whether a CID font is compatible for unicode.
 * @param[in]  font The input CID specific font.
 * @return   <a>TRUE</a> if the CID font is compatible for unicode, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDCIDFontIsUnicodeCompatible, (FPD_Font font))

/**
 * @brief FPDCIDFontGetNextChar
 * @details Gets a charcode from a string at specified position.
 * @param[in]  font The input CID specific font.
 * @param[in]  str The char buffer.
 * @param[in,out]  inOutOffset Input the zero-based position and receive the next charcode position.
 * @return   A charcode.
 * @note 
 */
INTERFACE(FS_DWORD, FPDCIDFontGetNextChar, (FPD_Font font,  FS_LPCSTR str,  FS_INT32* inOutOffset))

/**
 * @brief FPDCIDFontCountChar
 * @details Gets the count of characters in a string.
 * @param[in]  font The input CID specific font.
 * @param[in]  str The string buffer.
 * @param[in]  size The length in bytes of the string.
 * @return   The count of characters in the string.
 * @note 
 */
INTERFACE(FS_INT32, FPDCIDFontCountChar, (FPD_Font font,  FS_LPCSTR str,  FS_INT32 size))

/**
 * @brief FPDCIDFontAppendChar
 * @details Append a charcode to a string buffer.
 * @param[in]  font The input CID specific font.
 * @param[in,out]  inOutStr Input a string buffer and append a charcode to it.
 * @param[in]  charcode The charcode to append.
 * @return   The number of bytes appended to the string buffer.
 * @note 
 */
INTERFACE(FS_INT32, FPDCIDFontAppendChar, (FPD_Font font,  FS_LPSTR inOutStr,  FS_DWORD charcode))

/**
 * @brief FPDCIDFontGetCharSize
 * @details Gets the number of bytes for the char code.
 * @param[in]  font The input CID specific font.
 * @param[in]  charcode Input a charcode.
 * @return   The number of bytes for the char code.
 * @note 
 */
INTERFACE(FS_INT32, FPDCIDFontGetCharSize, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDCIDFontLoadGB2312
 * @details Loads GB2312 char set.
 * @param[in]  font The input CID specific font.
 * @return   <a>TRUE</a> if the font is loaded successfully.
 * @note 
 */
INTERFACE(FS_BOOL, FPDCIDFontLoadGB2312, (FPD_Font font))

/**
 * @brief FPDCIDFontCIDFromCharCode
 * @details Gets the CID code from charcode.
 * @param[in]  font The input CID specific font.
 * @param[in]  charcode Input a charcode.
 * @return   The CID of the charcode.
 * @note 
 */
INTERFACE(FS_WORD, FPDCIDFontCIDFromCharCode, (FPD_Font font,  FS_DWORD charcode))

/**
 * @brief FPDCIDFontIsTrueType
 * @details Test whether the CID font is a True-type font.
 * @param[in]  font The input CID specific font.
 * @return   <a>TRUE</a> if the font is a True-type font.
 * @note 
 */
INTERFACE(FS_BOOL, FPDCIDFontIsTrueType, (FPD_Font font))

/**
 * @brief FPDCIDFontGetCharset
 * @details Gets the character set.
 * @param[in]  font The input CID specific font.
 * @return   The character set.
 * @note 
 */
INTERFACE(FS_INT32, FPDCIDFontGetCharset, (FPD_Font font))

/**
 * @brief FPDCIDFontGetCIDTransform
 * @details Gets the CID transform.
 * @param[in]  font The input CID specific font.
 * @param[in]  CID The input CID.
 * @return   The CID transform.
 * @note 
 */
INTERFACE(FS_LPBYTE, FPDCIDFontGetCIDTransform, (FPD_Font font,  FS_WORD CID))

/**
 * @brief FPDCIDFontIsVertWriting
 * @details Checks whether the font is vertical writing.
 * @param[in]  font The input CID specific font.
 * @return   <a>TRUE</a> if the CID font is vertical writing.
 * @note 
 */
INTERFACE(FS_BOOL, FPDCIDFontIsVertWriting, (FPD_Font font))

/**
 * @brief FPDCIDFontGetVertWidth
 * @details Gets glyph width in vertical writing.
 * @param[in]  font The input CID specific font.
 * @param[in]  CID Input a CID code.
 * @return   The glyph width in vertical writing.
 * @note 
 */
INTERFACE(short, FPDCIDFontGetVertWidth, (FPD_Font font,  FS_WORD CID))

/**
 * @brief FPDCIDFontGetVertOrigin
 * @details Gets character origin in vertical writing.
 * @param[in]  font The input CID specific font.
 * @param[in]  CID Input a CID code.
 * @param[out]  outVxResult It receives the x-coordinate of the character origin.
 * @param[out]  outVyResult It receives the y-coordinate of the character origin.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDCIDFontGetVertOrigin, (FPD_Font font,  FS_WORD CID,  FS_SHORT* outVxResult,  FS_SHORT* outVyResult))

NumOfSelector(FPDCIDFont)
ENDENUM

//*****************************
/* CIDUtil HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDCIDUtilIsVerticalJapanCID
 * @details Whether the specified CID is vertical Japanese CID.
 * @param[in]  CID The input CID
 * @return   Return whether the specified CID is vertical Japanese CID.
 * @note 
 */
INTERFACE(FS_BOOL, FPDCIDUtilIsVerticalJapanCID, (FS_WORD CID))

NumOfSelector(FPDCIDUtil)
ENDENUM

//*****************************
/* ColorSpace HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDColorSpaceGetStockCS
 * @details Gets stocked color spaces. Stocked color spaces can not be destroyed
	*            The following color spaces are stocked:
	*            /DeviceGray, /DeviceRGB, /DeviceCMYK, /Pattern (colored patterns only).
 * @param[in]  family The color space family. See <a>FPDFontColorSpaceFamilies</a>.
 * @return   The stocked color spaces.
 * @note 
 */
INTERFACE(FPD_ColorSpace, FPDColorSpaceGetStockCS, (FS_INT32 family))

/**
 * @brief FPDColorSpaceLoad
 * @details Loads color space from a PDF object.
	*            The object can be a name or an array.
	*            The returned color space can be one of the stocked color spaces, or a new instance of
	*            one derived color space class. Application should call Release() to destroy the new
	*            instance when it's not used any more.
 * @param[in]  doc The PDF document.
 * @param[in]  CSObj The PDF object of a color space.
 * @return   The color space loaded from a PDF object.
 * @note 
 */
INTERFACE(FPD_ColorSpace, FPDColorSpaceLoad, (FPD_Document doc,  FPD_Object CSObj))

/**
 * @brief FPDColorSpaceReleaseCS
 * @details Release the color space.
 * @param[in]  cs The input color space.
 * @return   void
 * @note Applications should not delete color space directly, because some color spaces are 
	*            stocked. Call Release() function instead.
 */
INTERFACE(void, FPDColorSpaceReleaseCS, (FPD_ColorSpace cs))

/**
 * @brief FPDColorSpaceGetBufSize
 * @details Gets color buffer size.
 * @param[in]  cs The input color space.
 * @return   The color buffer size.
 * @note 
 */
INTERFACE(FS_INT32, FPDColorSpaceGetBufSize, (FPD_ColorSpace cs))

/**
 * @brief FPDColorSpaceCreateBuf
 * @details Creates a color buffer.
 * @param[in]  cs The input color space.
 * @return   The created color buffer.
 * @note 
 */
INTERFACE(FS_FLOAT*, FPDColorSpaceCreateBuf, (FPD_ColorSpace cs))

/**
 * @brief FPDColorSpaceGetDefaultColor
 * @details Gets the default color.
 * @param[in]  cs The input color space.
 * @param[out]  outBuf It receives the color components.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorSpaceGetDefaultColor, (FPD_ColorSpace cs,  FS_FLOAT* outBuf))

/**
 * @brief FPDColorSpaceCountComponents
 * @details Gets the number of components.
 * @param[in]  cs The input color space.
 * @return   The number of components.
 * @note 
 */
INTERFACE(FS_INT32, FPDColorSpaceCountComponents, (FPD_ColorSpace cs))

/**
 * @brief FPDColorSpaceGetFamily
 * @details Gets the color space family.
 * @param[in]  cs The input color space.
 * @return   The color space family.
 * @note 
 */
INTERFACE(FS_INT32, FPDColorSpaceGetFamily, (FPD_ColorSpace cs))

/**
 * @brief FPDColorSpaceGetDefaultValue
 * @details Gets the default value of a component.
 * @param[in]  cs The input color space.
 * @param[in]  iComponent The zero-based component index.
 * @param[out]  outValue It receives the component value.
 * @param[out]  outMin It receives the minimize component value valid.
 * @param[out]  outMax It receives the maximize component value valid.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorSpaceGetDefaultValue, (FPD_ColorSpace cs,  FS_INT32 iComponent,  FS_FLOAT* outValue,  FS_FLOAT* outMin,  FS_FLOAT* outMax))

/**
 * @brief FPDColorSpacesRGB
 * @details Checks whether it's sRGB or equivalent color space.
 * @param[in]  cs The input color space.
 * @return   <a>TRUE</a> if  the <param>cs</param> is sRGB or equivalent color space.
 * @note 
 */
INTERFACE(FS_BOOL, FPDColorSpacesRGB, (FPD_ColorSpace cs))

/**
 * @brief FPDColorSpaceGetRGB
 * @details Converts a color to RGB color space.
 * @param[in]  cs The input color space.
 * @param[in]  pBuf The input color components.
 * @param[out]  outR It receives the red component.
 * @param[out]  outG It receives the green component.
 * @param[out]  outB It receives the blue component.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDColorSpaceGetRGB, (FPD_ColorSpace cs,  FS_FLOAT* pBuf,  FS_FLOAT* outR,  FS_FLOAT* outG,  FS_FLOAT* outB))

/**
 * @brief FPDColorSpaceSetRGB
 * @details Converts a color from RGB color space.
 * @param[in]  cs The input color space.
 * @param[out]  outBuf It receives the converted color.
 * @param[in]  R The red component of the color.
 * @param[in]  G The green component of the color.
 * @param[in]  B The blue component of the color.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDColorSpaceSetRGB, (FPD_ColorSpace cs,  FS_FLOAT* outBuf,  FS_FLOAT R,  FS_FLOAT G,  FS_FLOAT B))

/**
 * @brief FPDColorSpaceGetCMYK
 * @details Converts a color to CMYK color space.
 * @param[in]  cs The input color space.
 * @param[in]  pBuf The input color components.
 * @param[out]  outC It receives the C component
 * @param[out]  outM It receives the M component
 * @param[out]  outY It receives the Y component
 * @param[out]  outK It receives the K component
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDColorSpaceGetCMYK, (FPD_ColorSpace cs,  FS_FLOAT* pBuf,  FS_FLOAT* outC,  FS_FLOAT* outM,  FS_FLOAT* outY,  FS_FLOAT* outK))

/**
 * @brief FPDColorSpaceSetCMYK
 * @details Converts a color from CMYK color space.
 * @param[in]  cs The input color space.
 * @param[out]  outBuf It receives the converted color.
 * @param[in]  c The C component of the color.
 * @param[in]  m The M component of the color.
 * @param[in]  y The Y component of the color.
 * @param[in]  k The K component of the color.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDColorSpaceSetCMYK, (FPD_ColorSpace cs,  FS_FLOAT* outBuf,  FS_FLOAT c,  FS_FLOAT m,  FS_FLOAT y,  FS_FLOAT k))

/**
 * @brief FPDColorSpaceTranslateImageLine
 * @details Converts a bitmap scan line. Source must be 8bpc with default encoding, dest is be 24bpp sRGB
 * @param[in]  cs The input color space.
 * @param[in]  destBuf The destinate line buffer.
 * @param[in]  srcBuf The source line buffer.
 * @param[in]  pixels The pixel in the line.
 * @param[in]  imageWidth The image_width.
 * @param[in]  imageHeight The image height.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorSpaceTranslateImageLine, (FPD_ColorSpace cs,  FS_LPBYTE destBuf,  FS_LPCBYTE srcBuf,  FS_INT32 pixels,  FS_INT32 imageWidth,  FS_INT32 imageHeight))

/**
 * @brief FPDColorSpaceGetArray
 * @details Gets the color space parameters array.
 * @param[in]  cs The input color space.
 * @return   The color space parameters array.
 * @note 
 */
INTERFACE(FPD_Object, FPDColorSpaceGetArray, (FPD_ColorSpace cs))

/**
 * @brief FPDColorSpaceGetMaxIndex
 * @details Gets the max index. For Indexed color space only.
 * @param[in]  cs The input color space.
 * @return   The max index. For Indexed color space only.
 * @note 
 */
INTERFACE(FS_INT32, FPDColorSpaceGetMaxIndex, (FPD_ColorSpace cs))

/**
 * @brief FPDColorSpaceGetBaseCS
 * @details Gets based color space.
 * @param[in]  cs The input color space.
 * @return   The based color space.
 * @note 
 */
INTERFACE(FPD_ColorSpace, FPDColorSpaceGetBaseCS, (FPD_ColorSpace cs))

NumOfSelector(FPDColorSpace)
ENDENUM

//*****************************
/* Color HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDColorNew
 * @details Creates a new empty PDF color object.
 * @param[in]  void 
 * @return   A new PDF color object.
 * @note 
 */
INTERFACE(FPD_Color, FPDColorNew, (void))

/**
 * @brief FPDColorDestroy
 * @details Destroys the PDF color object.
 * @param[in]  color The input PDF color object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorDestroy, (FPD_Color color))

/**
 * @brief FPDColorIsNull
 * @details Checks whether the color is <a>NULL</a>.
 * @param[in]  color The input PDF color object.
 * @return   <a>TRUE</a> if the color is <a>NULL</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDColorIsNull, (FPD_Color color))

/**
 * @brief FPDColorIsEqual
 * @details Compares with another color
 * @param[in]  color The input PDF color object.
 * @param[in]  other The another color object.
 * @return   Non-zero means equal, otherwise not equal.
 * @note 
 */
INTERFACE(FS_BOOL, FPDColorIsEqual, (FPD_Color color,  FPD_Color other))

/**
 * @brief FPDColorIsPattern
 * @details Checks whether the color is a pattern.
 * @param[in]  color The input PDF color object.
 * @return   <a>TRUE</a> if the color is a pattern, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDColorIsPattern, (FPD_Color color))

/**
 * @brief FPDColorCopy
 * @details Copies from another color.
 * @param[in]  color The input PDF color object.
 * @param[in]  src The source color object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorCopy, (FPD_Color color,  const FPD_Color src))

/**
 * @brief FPDColorSetColorSpace
 * @details Sets the color space.
 * @param[in]  color The input PDF color object.
 * @param[in]  cs The new color space.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorSetColorSpace, (FPD_Color color,  FPD_ColorSpace cs))

/**
 * @brief FPDColorGetColorSpace
 * @details Gets the color space
 * @param[in]  color The input PDF color object.
 * @return   The color space
 * @note 
 */
INTERFACE(FPD_ColorSpace, FPDColorGetColorSpace, (FPD_Color color))

/**
 * @brief FPDColorSetValue
 * @details Sets color components in normal color space.
 * @param[in]  color The input PDF color object.
 * @param[in]  pCompBuf The input color components.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorSetValue, (FPD_Color color,  FS_FLOAT* pCompBuf))

/**
 * @brief FPDColorSetValue2
 * @details Sets a color in pattern color space.
 * @param[in]  color The input PDF color object.
 * @param[in]  pattern The input pattern
 * @param[in]  pCompBuf The components buffer.
 * @param[in]  ncomps The count of components.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorSetValue2, (FPD_Color color,  FPD_Pattern pattern,  FS_FLOAT* pCompBuf,  FS_INT32 ncomps))

/**
 * @brief FPDColorGetRGB
 * @details Converts to default RGB color space, using single byte encoding (0-255).
 * @param[in]  color The input PDF color object.
 * @param[out]  outR It receives the red component.
 * @param[out]  outG It receives the green component.
 * @param[out]  outB It receives the blue component.
 * @return   <a>TRUE</a> if the color is RGB format, otherwise <a>FALSE</a>. If the return value is <a>FALSE</a>, then this color should be treated as "no-color".
 * @note 
 */
INTERFACE(FS_BOOL, FPDColorGetRGB, (FPD_Color color,  FS_INT32* outR,  FS_INT32* outG,  FS_INT32* outB))

/**
 * @brief FPDColorGetPattern
 * @details Gets pattern information for <a>PDFCS_PATTERN</a> color space.
 * @param[in]  color The input PDF color object.
 * @return   A pattern object. <a>NULL</a> if this color is not a pattern.
 * @note 
 */
INTERFACE(FPD_Pattern, FPDColorGetPattern, (FPD_Color color))

/**
 * @brief FPDColorGetPatternCS
 * @details Gets base color space for an uncolored tiling pattern.
 * @param[in]  color The input PDF color object.
 * @return   The base color space for an uncolored tiling pattern.
 * @note 
 */
INTERFACE(FPD_ColorSpace, FPDColorGetPatternCS, (FPD_Color color))

/**
 * @brief FPDColorGetPatternColor
 * @details Gets component buffer for the base color space used for pattern (uncolored tiling only).
 * @param[in]  color The input PDF color object.
 * @return   A buffer for the components. <a>NULL</a> if not applicable.
 * @note 
 */
INTERFACE(FS_FLOAT*, FPDColorGetPatternColor, (FPD_Color color))

/**
 * @brief FPDColorGetColorBuffer
 * @details Gets the component buffer.
 * @param[in]  color The input PDF color object.
 * @return   <a>NULL</a> for unspecified color.
 * @note 
 */
INTERFACE(FS_FLOAT*, FPDColorGetColorBuffer, (FPD_Color color))

NumOfSelector(FPDColor)
ENDENUM

//*****************************
/* Pattern HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDPatternDestroy
 * @details Destroys the PDF pattern.
 * @param[in]  pattern The input PDF pattern.
 * @return   void
 * @note Can't construct a FPD_Pattern directly.
 */
INTERFACE(void, FPDPatternDestroy, (FPD_Pattern pattern))

/**
 * @brief FPDPatternGetPatternObj
 * @details Gets dictionary for shading, stream for tiling.
 * @param[in]  pattern The input PDF pattern.
 * @return   A dictionary for shading, stream for tiling.
 * @note 
 */
INTERFACE(FPD_Object, FPDPatternGetPatternObj, (FPD_Pattern pattern))

/**
 * @brief FPDPatternGetPatternType
 * @details Gets the pattern type
 * @param[in]  pattern The input PDF pattern.
 * @return   The pattern type. Like FPD_PATTERN_xxx.
 * @note 
 */
INTERFACE(FS_INT32, FPDPatternGetPatternType, (FPD_Pattern pattern))

/**
 * @brief FPDPatternGetPatternMatrix
 * @details Gets matrix from pattern to parent stream.
 * @param[in]  pattern The input PDF pattern.
 * @return   The matrix from pattern to parent stream.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FPDPatternGetPatternMatrix, (FPD_Pattern pattern))

/**
 * @brief FPDPatternGetPDDoc
 * @details Gets the PDF document.
 * @param[in]  pattern The input PDF pattern.
 * @return   The PDF document that is the pattern associated with.
 * @note 
 */
INTERFACE(FPD_Document, FPDPatternGetPDDoc, (FPD_Pattern pattern))

/**
 * @brief FPDPatternCastToShadingPatternObj
 * @details Cast to sub class FPD_ShadingPattern.
 * @param[in]  pattern The input PDF pattern.
 * @return   FPD_ShadingPattern
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_ShadingPattern, FPDPatternCastToShadingPatternObj, (FPD_Pattern pattern))

/**
 * @brief FPDPatternCastToTilingPatternObj
 * @details Cast to sub class FPD_TilingPattern.
 * @param[in]  pattern The input PDF pattern.
 * @return   FPD_TilingPattern
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_TilingPattern, FPDPatternCastToTilingPatternObj, (FPD_Pattern pattern))

NumOfSelector(FPDPattern)
ENDENUM

//*****************************
/* TilingPattern HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDTilingPatternNew
 * @details Creates a new tiling pattern object.
 * @param[in]  doc The PDF document.
 * @param[in]  obj The PDF object of the pattern.
 * @return   A new tiling pattern object.
 * @note Not support since <a>SDK_LATEEST_VERSION</a> > 1.0. You can use FPDTilingPatternNewII instead.
 */
INTERFACE(FPD_TilingPattern, FPDTilingPatternNew, (FPD_Document doc,  FPD_Object obj))

/**
 * @brief FPDTilingPatternDestroy
 * @details Destroys the PDF tiling pattern object.
 * @param[in]  pattern The input PDF tiling pattern object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTilingPatternDestroy, (FPD_TilingPattern pattern))

/**
 * @brief FPDTilingPatternGetPatternObj
 * @details Gets dictionary for shading, stream for tiling.
 * @param[in]  pattern The input PDF tiling pattern object.
 * @return   A dictionary for shading, stream for tiling.
 * @note 
 */
INTERFACE(FPD_Object, FPDTilingPatternGetPatternObj, (FPD_TilingPattern pattern))

/**
 * @brief FPDTilingPatternGetPatternType
 * @details Gets the pattern type.
 * @param[in]  pattern The input PDF tiling pattern object.
 * @return   The pattern type.
 * @note 
 */
INTERFACE(FS_INT32, FPDTilingPatternGetPatternType, (FPD_TilingPattern pattern))

/**
 * @brief FPDTilingPatternGetPatternMatrix
 * @details Gets matrix from pattern to parent stream.
 * @param[in]  pattern The input PDF tiling pattern object.
 * @return   The matrix from pattern to parent stream.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FPDTilingPatternGetPatternMatrix, (FPD_TilingPattern pattern))

/**
 * @brief FPDTilingPatternGetPDDoc
 * @details Gets the PDF document.
 * @param[in]  pattern The input PDF tiling pattern object.
 * @return   The PDF document associated with the tiling pattern.
 * @note 
 */
INTERFACE(FPD_Document, FPDTilingPatternGetPDDoc, (FPD_TilingPattern pattern))

/**
 * @brief FPDTilingPatternLoad
 * @details Loads all following data.
 * @param[in]  pattern The input PDF tiling pattern object.
 * @return   <a>TRUE</a> if the data is loaded, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDTilingPatternLoad, (FPD_TilingPattern pattern))

/**
 * @brief FPDTilingPatternIsColored
 * @details Tests whether the pattern is a colored pattern or not.
 * @param[in]  pattern The input PDF tiling pattern object.
 * @return   <a>TRUE</a> if the pattern is a colored pattern, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDTilingPatternIsColored, (FPD_TilingPattern pattern))

/**
 * @brief FPDTilingPatternGetBBox
 * @details Gets the bounding box in pattern space.
 * @param[in]  pattern The input PDF tiling pattern object.
 * @return   The bounding box. In pattern space.
 * @note 
 */
INTERFACE(FS_FloatRect, FPDTilingPatternGetBBox, (FPD_TilingPattern pattern))

/**
 * @brief FPDTilingPatternGetXStep
 * @details Gets the desired horizontal spacing between pattern cells. In pattern space, absolute values only.
 * @param[in]  pattern The input PDF tiling pattern object.
 * @return   The desired horizontal spacing between pattern cells.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTilingPatternGetXStep, (FPD_TilingPattern pattern))

/**
 * @brief FPDTilingPatternGetYStep
 * @details Gets the desired vertical spacing between pattern cells. In pattern space, absolute values only.
 * @param[in]  pattern The input PDF tiling pattern object.
 * @return   The desired vertical spacing between pattern cells.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTilingPatternGetYStep, (FPD_TilingPattern pattern))

/**
 * @brief FPDTilingPatternGetForm
 * @details Gets all objects contained in this pattern.
 * @param[in]  pattern The input PDF tiling pattern object.
 * @return   All objects contained in this pattern. <a>NULL</a> if not loaded.
 * @note 
 */
INTERFACE(FPD_Form, FPDTilingPatternGetForm, (FPD_TilingPattern pattern))

/**
 * @brief FPDTilingPatternNewII
 * @details Creates a new tiling pattern object.
 * @param[in]  doc The PDF document.
 * @param[in]  obj The PDF object of the pattern.
 * @param[in]  parentMatrix The parent matrix.
 * @return   A new tiling pattern object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FPD_TilingPattern, FPDTilingPatternNewII, (FPD_Document doc,  FPD_Object obj,  FS_AffineMatrix parentMatrix))

NumOfSelector(FPDTilingPattern)
ENDENUM

//*****************************
/* ShadingPattern HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDShadingPatternNew
 * @details Creates a new empty PDF shading pattern object.
 * @param[in]  doc The PDF document.
 * @param[in]  obj The PDF object of pattern.
 * @param[in]  bShading Whether it's just a shading object.
 * @return   A new shading pattern object.
 * @note 
 */
INTERFACE(FPD_ShadingPattern, FPDShadingPatternNew, (FPD_Document doc,  FPD_Object obj,  FS_BOOL bShading))

/**
 * @brief FPDShadingPatternDestroy
 * @details Destroys the shading pattern object.
 * @param[in]  pattern The shading pattern object to be destroyed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDShadingPatternDestroy, (FPD_ShadingPattern pattern))

/**
 * @brief FPDShadingPatternGetPatternObj
 * @details Gets dictionary for shading, stream for tiling.
 * @param[in]  pattern The input PDF shading pattern object.
 * @return   A dictionary for shading, stream for tiling.
 * @note 
 */
INTERFACE(FPD_Object, FPDShadingPatternGetPatternObj, (FPD_ShadingPattern pattern))

/**
 * @brief FPDShadingPatternGetPatternType
 * @details Gets the pattern type
 * @param[in]  pattern The input PDF shading pattern object.
 * @return   The pattern type
 * @note 
 */
INTERFACE(FS_INT32, FPDShadingPatternGetPatternType, (FPD_ShadingPattern pattern))

/**
 * @brief FPDShadingPatternGetPatternMatrix
 * @details Gets matrix from pattern to parent stream.
 * @param[in]  pattern The input PDF shading pattern object.
 * @return   The matrix from pattern to parent stream.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FPDShadingPatternGetPatternMatrix, (FPD_ShadingPattern pattern))

/**
 * @brief FPDShadingPatternGetPDDoc
 * @details Gets the PDF document.
 * @param[in]  pattern The input PDF shading pattern object.
 * @return   The PDF document.
 * @note 
 */
INTERFACE(FPD_Document, FPDShadingPatternGetPDDoc, (FPD_ShadingPattern pattern))

/**
 * @brief FPDShadingPatternLoad
 * @details Loads all following data.
 * @param[in]  pattern The input PDF shading pattern object.
 * @return   <a>TRUE</a> if the data is loaded, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDShadingPatternLoad, (FPD_ShadingPattern pattern))

/**
 * @brief FPDShadingPatternReLoad
 * @details Reloads shading data after shading dictionary changed .
 * @param[in]  pattern The input PDF shading pattern object.
 * @return   <a>TRUE</a> if the data is reloaded, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDShadingPatternReLoad, (FPD_ShadingPattern pattern))

/**
 * @brief FPDShadingPatternGetColorSpace
 * @details Gets the color space.
 * @param[in]  pattern The input PDF shading pattern object.
 * @return   The color space.
 * @note 
 */
INTERFACE(FPD_ColorSpace, FPDShadingPatternGetColorSpace, (FPD_ShadingPattern pattern))

/**
 * @brief FPDShadingPatternGetFunc
 * @details Gets the function pointer.
 * @param[in]  pattern The input PDF shading pattern object.
 * @param[in]  index Function pointer index.
 * @return   The function pointer.
 * @note 
 */
INTERFACE(FPD_Function, FPDShadingPatternGetFunc, (FPD_ShadingPattern pattern,  FS_INT32 index))

/**
 * @brief FPDShadingPatternGetFuncsCount
 * @details Gets the count of functions.
 * @param[in]  pattern The input PDF shading pattern object.
 * @return   The count of functions.
 * @note 
 */
INTERFACE(FS_INT32, FPDShadingPatternGetFuncsCount, (FPD_ShadingPattern pattern))

/**
 * @brief FPDShadingPatternSetColorSpace
 * @details Sets the color space.
 * @param[in]  pattern The input PDF shading pattern object.
 * @param[in]  colorSpace The input color space to be set.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDShadingPatternSetColorSpace, (FPD_ShadingPattern pattern,  FPD_ColorSpace colorSpace))

/**
 * @brief FPDShadingPatternGetShadingObject
 * @details Gets the PDF object of shading..
 * @param[in]  pattern The input PDF shading pattern object.
 * @return   The PDF object of shading..
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FPD_Object, FPDShadingPatternGetShadingObject, (FPD_ShadingPattern pattern))

NumOfSelector(FPDShadingPattern)
ENDENUM

//*****************************
/* MeshStream HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDMeshStreamNew
 * @details Creates a new PDF mesh stream with the shading stream, functions, and color-spaces.
 * @param[in]  shadingStream The input shading stream.
 * @param[in]  pFuncs The array of 1-in, 1-out functions for shading.
 * @param[in]  nFuncs The count of functions.
 * @param[in]  cs The base color-space for shading.
 * @return   A new PDF mesh stream.
 * @note 
 */
INTERFACE(FPD_MeshStream, FPDMeshStreamNew, (FPD_Object shadingStream,  FPD_Function* pFuncs,  FS_INT32 nFuncs,  FPD_ColorSpace cs))

/**
 * @brief FPDMeshStreamDestroy
 * @details Destroys the PDF mesh stream.
 * @param[in]  meshStream The input PDF mesh stream.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDMeshStreamDestroy, (FPD_MeshStream meshStream))

/**
 * @brief FPDMeshStreamGetFlag
 * @details Reads a vertex flag from mesh stream.
 * @param[in]  meshStream The input PDF mesh stream.
 * @return   The vertex flag from mesh stream.
 * @note 
 */
INTERFACE(FS_DWORD, FPDMeshStreamGetFlag, (FPD_MeshStream meshStream))

/**
 * @brief FPDMeshStreamGetCoords
 * @details Reads a vertex coords from mesh stream.
 * @param[in]  meshStream The input PDF mesh stream.
 * @param[out]  outX It receives the X coordinate.
 * @param[out]  outY It receives the Y coordinate.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDMeshStreamGetCoords, (FPD_MeshStream meshStream,  FS_FLOAT* outX,  FS_FLOAT* outY))

/**
 * @brief FPDMeshStreamGetColor
 * @details Reads a vertex color from mesh stream.
 * @param[in]  meshStream The input PDF mesh stream.
 * @param[out]  outR It receives the R value of a vertex color.
 * @param[out]  outG It receives the G value of a vertex color.
 * @param[out]  outB It receives the B value of a vertex color.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDMeshStreamGetColor, (FPD_MeshStream meshStream,  FS_FLOAT* outR,  FS_FLOAT* outG,  FS_FLOAT* outB))

/**
 * @brief FPDMeshStreamGetVertex
 * @details Reads a vertex from mesh stream.
 * @param[in]  meshStream The input PDF mesh stream.
 * @param[out]  outVertex It receives the vertex from mesh stream.
 * @param[in]  object2Bitmap The input matrix.
 * @return   A vertex of <param>meshStream</param>.
 * @note 
 */
INTERFACE(FS_DWORD, FPDMeshStreamGetVertex, (FPD_MeshStream meshStream,  FPD_MeshVertex* outVertex,  FS_AffineMatrix object2Bitmap,  FPD_OutputPreview outPreview))

/**
 * @brief FPDMeshStreamGetVertexRow
 * @details Reads a vertex array from mesh stream.
 * @param[in]  meshStream The input PDF mesh stream.
 * @param[out]  outVertex It receives the vertex from mesh stream.
 * @param[in]  count The count of the vertex array.
 * @param[in]  object2Bitmap The input matrix.
 * @return   <a>TRUE</a> means success, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDMeshStreamGetVertexRow, (FPD_MeshStream meshStream,  FPD_MeshVertex* outVertex,  FS_INT32 count,  FS_AffineMatrix object2Bitmap))

NumOfSelector(FPDMeshStream)
ENDENUM

//*****************************
/* Image HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDImageNew
 * @details Creates a new PDF image data object.
 * @param[in]  doc The PDF document.
 * @return   A new PDF image data object.
 * @note 
 */
INTERFACE(FPD_Image, FPDImageNew, (FPD_Document doc))

/**
 * @brief FPDImageDestroy
 * @details Destroys the PDF image data object.
 * @param[in]  image The input PDF image data object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDImageDestroy, (FPD_Image image))

/**
 * @brief FPDImageLoadImageF
 * @details Loads from an image stream.
 * @param[in]  image The input PDF image data object.
 * @param[in]  imageStream The input image stream.
 * @param[in]  bInline Whether this is an inline image. If yes, the stream will be destroyed when image destroyed.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDImageLoadImageF, (FPD_Image image,  FPD_Object imageStream,  FS_BOOLEAN bInline))

/**
 * @brief FPDImageClone
 * @details Clones an image.
 * @param[in]  image The input PDF image data object.
 * @return   The clone of the image.
 * @note 
 */
INTERFACE(FPD_Image, FPDImageClone, (FPD_Image image))

/**
 * @brief FPDImageGetStream
 * @details Gets the image stream.
 * @param[in]  image The input PDF image data object.
 * @return   The image stream.
 * @note 
 */
INTERFACE(FPD_Object, FPDImageGetStream, (FPD_Image image))

/**
 * @brief FPDImageGetDict
 * @details Gets the image dictionary.
 * @param[in]  image The input PDF image data object.
 * @return   The image dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDImageGetDict, (FPD_Image image))

/**
 * @brief FPDImageGetOC
 * @details Gets the optional content dictionary.
 * @param[in]  image The input PDF image data object.
 * @return   The optional content dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDImageGetOC, (FPD_Image image))

/**
 * @brief FPDImageGetDocument
 * @details Gets the document.
 * @param[in]  image The input PDF image data object.
 * @return   The document.
 * @note 
 */
INTERFACE(FPD_Document, FPDImageGetDocument, (FPD_Image image))

/**
 * @brief FPDImageGetPixelHeight
 * @details Gets the pixel height.
 * @param[in]  image The input PDF image data object.
 * @return   The pixel height.
 * @note 
 */
INTERFACE(FS_INT32, FPDImageGetPixelHeight, (FPD_Image image))

/**
 * @brief FPDImageGetPixelWidth
 * @details Gets the pixel width.
 * @param[in]  image The input PDF image data object.
 * @return   The pixel width.
 * @note 
 */
INTERFACE(FS_INT32, FPDImageGetPixelWidth, (FPD_Image image))

/**
 * @brief FPDImageIsMask
 * @details Checks whether the image is a mask.
 * @param[in]  image The input PDF image data object.
 * @return   <a>TRUE</a> if the image is a mask, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDImageIsMask, (FPD_Image image))

/**
 * @brief FPDImageIsInterpol
 * @details Checks whether image interpolation is to be performed.
 * @param[in]  image The input PDF image data object.
 * @return   <a>TRUE</a> if the image interpolation is to be performed, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDImageIsInterpol, (FPD_Image image))

/**
 * @brief FPDImageLoadDIBitmap
 * @details Loads DIB source of the image. Optionally the mask info can be returned as well. You need invoke FSDIBitmapClone to generate the buffer for bitmap.
 * @param[in]  image The input PDF image data object.
 * @param[out]  outMask It receives the mask of the image.
 * @param[out]  outMatteColor It receives the matte color.
 * @param[in]  bStdCS The default value is <a>FALSE</a>. Indicates whether use standard colorspace conversion(CMYK->RGB) or not.
 * @param[in]  GroupFamily The default value is 0. The group color space family for whether to adopt a special algorithm, and the group is a group or form include this image source.
 * @param[in]  bLoadMask The default value is <a>FALSE</a>. when processing luminosity to mask alpha, adopt a special algorithm.
 * @return   The DIB source constructed.
 * @note The result bitmaps are NOT cached, so the caller must release them when finished using.
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more. User can use FSBitmapLoadDIBitmap2 instead.
 */
INTERFACE(FS_DIBitmap, FPDImageLoadDIBitmap, (FPD_Image image,  FS_DIBitmap* outMask,  FS_DWORD* outMatteColor,  FS_BOOL bStdCS,  FS_DWORD GroupFamily,  FS_BOOL bLoadMask))

/**
 * @brief FPDImageSetImage
 * @details Changes image data from a DIB.
 * @param[in]  image The input PDF image data object.
 * @param[in]  DIBitmap The DIB data.
 * @param[in]  bCompress Whether to compress the DIB.
 * @param[in]  pMask Mask image, it's valid only <param>DIBitmap</param> has on alpha channel. Mask image should be FS_DIB_1bppMask or FS_DIB_8bppMask.
 * @return   void
 * @note The bitmaps stored in the page cache must be reset
	*            by FPDImageResetCache() for all loaded pages.
 */
INTERFACE(void, FPDImageSetImage, (FPD_Image image,  const FS_DIBitmap DIBitmap,  FS_BOOL bCompress,  FS_DIBitmap pMask))

/**
 * @brief FPDImageSetJpegImage
 * @details Changes image data from a JPEG encoded block.
 * @param[in]  image The input PDF image data object.
 * @param[in]  pImageDataBuf The JPEG data.
 * @param[in]  size The size in bytes of the JPEG data.
 * @return   void
 * @note The bitmaps stored in the page cache must be reset
	*            by FPDImageResetCache() for all loaded pages.
 */
INTERFACE(void, FPDImageSetJpegImage, (FPD_Image image,  FS_BYTE* pImageDataBuf,  FS_DWORD size))

/**
 * @brief FPDImageResetCache
 * @details Resets the page cache.
 * @param[in]  image The input PDF image data object.
 * @param[in]  page The page.
 * @param[in]  DIBitmap The new DIB to set.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDImageResetCache, (FPD_Image image,  FPD_Page page,  const FS_DIBitmap DIBitmap))

/**
 * @brief FPDImageLoadDIBitmapProgressive
 * @details Loads DIB source of the image progressively. You need invoke FSDIBitmapClone to generate the buffer for bitmap.
 * @param[in]  image The input PDF image data object.
 * @param[in]  formResourceDict The input form resource dictionary.
 * @param[in]  pageResourceDict The input page resource dictionary.
 * @param[in]  bStdCS The default value is <a>FALSE</a>. Indicates whether use standard colorspace conversion(CMYK->RGB) or not.
 * @param[in]  GroupFamily The default value is 0. The group color space family for whether to adopt a special algorithm, and the group is a group or form include this image source.
 * @param[in]  bLoadMask The default value is <a>FALSE</a>. when processing luminosity to mask alpha, adopt a special algorithm.
 * @return   TRUE for success, otherwise failure.
 * @note The result bitmaps are NOT cached, so the caller must release them when finished using.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 */
INTERFACE(FS_BOOL, FPDImageLoadDIBitmapProgressive, (FPD_Image image,  FPD_Object formResourceDict,  FPD_Object pageResourceDict,  FS_BOOL bStdCS,  FS_DWORD GroupFamily,  FS_BOOL bLoadMask))

/**
 * @brief FPDImageGetDIBSource
 * @details Gets the DIB source.
 * @param[in]  image The input PDF image data object.
 * @return   The DIB source.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more. User can use FSBitmapGetDIBSource2 instead.
 */
INTERFACE(FS_DIBitmap, FPDImageGetDIBSource, (FPD_Image image))

/**
 * @brief FPDImageGetMask
 * @details Gets the mask.
 * @param[in]  image The input PDF image data object.
 * @return   The mask.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more. User can use FSBitmapGetMask2 instead.
 */
INTERFACE(FS_DIBitmap, FPDImageGetMask, (FPD_Image image))

/**
 * @brief FPDImageGetMatteColor
 * @details 
 * @param[in]  image The input PDF image data object.
 * @return   The matte color.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 */
INTERFACE(FS_DWORD, FPDImageGetMatteColor, (FPD_Image image))

INTERFACE(FS_BOOLEAN, FPDImageSetImage2, (FPD_Image image,  const FS_DIBitmap pDIBitmap,  FS_INT32 iCompress,  FS_FileWriteHandler pFileWrite,  FS_FileReadHandler pFileRead,  const FS_DIBitmap pMask,  const FPD_ImageSetParam pParam,  FS_INT32* pColorKey,  FS_INT32 nColorKeySize))

/**
 * @brief FPDImageDetachBitmap
 * @details 
 * @param[in]  image The input PDF image data object.
 * @return   FS_DIBitmap.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more. User can use FSBitmapDetachBitmap2 instead.
 */
INTERFACE(FS_DIBitmap, FPDImageDetachBitmap, (FPD_Image image))

/**
 * @brief FPDImageDetachMask
 * @details 
 * @param[in]  image The input PDF image data object.
 * @return   FS_DIBitmap.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @Deprecated    Current function has been deprecated , so not recommend to use current function any more. User can use FSBitmapDetachMask2 instead.
 */
INTERFACE(FS_DIBitmap, FPDImageDetachMask, (FPD_Image image))

/**
 * @brief FPDImageGetInlineDict
 * @details 
 * @param[in]  image The input PDF image data object.
 * @return   FPD_Object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(FPD_Object, FPDImageGetInlineDict, (FPD_Image image))

/**
 * @brief FPDImageGetDIBSource2
 * @details Gets the DIB source.
 * @param[in]  image The input PDF image data object.
 * @return   The DIB source.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 */
INTERFACE(FS_DIBSource, FPDImageGetDIBSource2, (FPD_Image image))

/**
 * @brief FPDImageGetMask2
 * @details Gets the mask.
 * @param[in]  image The input PDF image data object.
 * @return   The mask.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 */
INTERFACE(FS_DIBSource, FPDImageGetMask2, (FPD_Image image))

/**
 * @brief FPDImageDetachBitmap2
 * @details 
 * @param[in]  image The input PDF image data object.
 * @return   FS_DIBSource.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 */
INTERFACE(FS_DIBSource, FPDImageDetachBitmap2, (FPD_Image image))

/**
 * @brief FPDImageDetachMask2
 * @details 
 * @param[in]  image The input PDF image data object.
 * @return   FS_DIBSource.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 */
INTERFACE(FS_DIBSource, FPDImageDetachMask2, (FPD_Image image))

/**
 * @brief FPDImageLoadDIBitmap2
 * @details Loads DIB source of the image. Optionally the mask info can be returned as well. You need invoke FSDIBitmapClone to generate the buffer for bitmap.
 * @param[in]  image The input PDF image data object.
 * @param[out]  outMask It receives the mask of the image.
 * @param[out]  outMatteColor It receives the matte color.
 * @param[in]  bStdCS The default value is <a>FALSE</a>. Indicates whether use standard colorspace conversion(CMYK->RGB) or not.
 * @param[in]  GroupFamily The default value is 0. The group color space family for whether to adopt a special algorithm, and the group is a group or form include this image source.
 * @param[in]  bLoadMask The default value is <a>FALSE</a>. when processing luminosity to mask alpha, adopt a special algorithm.
 * @return   The DIB source constructed.
 * @note The result bitmaps are NOT cached, so the caller must release them when finished using.
 */
INTERFACE(FS_DIBSource, FPDImageLoadDIBitmap2, (FPD_Image image,  FS_DIBSource* outMask,  FS_DWORD* outMatteColor,  FS_BOOL bStdCS,  FS_DWORD GroupFamily,  FS_BOOL bLoadMask))

/**
 * @brief FPDImageIsInline
 * @details 
 * @param[in]  image The input PDF image data object.
 * @return   FS_BOOLEAN.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 */
INTERFACE(FS_BOOLEAN, FPDImageIsInline, (FPD_Image image))

/**
 * @brief FPDImageRelease
 * @details 
 * @param[in]  image The input PDF image data object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0
 */
INTERFACE(void, FPDImageRelease, (FPD_Image image))

/**
 * @brief FPDImageSetJpegImage2
 * @details 
 * @param[in]  image The input PDF image data object.
 * @param[in]  pFile The input JPEG data stream.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 */
INTERFACE(void, FPDImageSetJpegImage2, (FPD_Image image,  FS_FileReadHandler pFile))

/**
 * @brief FPDImageSetPngFileRead
 * @details 
 * @param[in]  image The input PDF image data object.
 * @param[in]  pFile The input PNG data stream.
 * @param[in]  quality if the image is color image and compress using DCT, so need set the param.
	 *							        the param is 0 - 100, and default is 80
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.2.0
 */
INTERFACE(FS_BOOLEAN, FPDImageSetPngFileRead, (FPD_Image image,  FS_FileReadHandler pFile,  FS_INT32 quality))

NumOfSelector(FPDImage)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* FXFontEncoding HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFXFontEncodingNew
 * @details It works with a font to translate character codes into glyph indices in that font. It also deals with Unicode mapping (if supported).
 * @param[in]  fpdFont The input PDF font object.
 * @return   A new font encoding.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FPD_FXFontEncoding, FPDFXFontEncodingNew, (FPD_Font fpdFont))

/**
 * @brief FPDFXFontEncodingDestroy
 * @details Destroys the font encoding.
 * @param[in]  fontEncoding The input font encoding.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDFXFontEncodingDestroy, (FPD_FXFontEncoding fontEncoding))

/**
 * @brief FPDFXFontEncodingGlyphFromCharCode
 * @details Gets the glyph index for a charcode. Return -1 for unknown. For embedded font only.
 * @param[in]  fontEncoding The input font encoding.
 * @param[in]  charcode Input a charcode.
 * @return   The glyph index of the charcode.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DWORD, FPDFXFontEncodingGlyphFromCharCode, (FPD_FXFontEncoding fontEncoding,  FS_DWORD charcode))

/**
 * @brief FPDFXFontEncodingUnicodeFromCharCode
 * @details Gets a unicode string for a charcode. Return empty for unknown.
 * @param[in]  fontEncoding The input font encoding.
 * @param[in]  charcode Input a charcode.
 * @param[out]  outUnicodeString It receives the unicode string for the charcode.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDFXFontEncodingUnicodeFromCharCode, (FPD_FXFontEncoding fontEncoding,  FS_DWORD charcode,  FS_WideString* outUnicodeString))

/**
 * @brief FPDFXFontEncodingCharCodeFromUnicode
 * @details Gets a charcode from a Unicode. Return -1 for unknown.
 * @param[in]  fontEncoding The input font encoding.
 * @param[in]  Unicode Input a unicode.
 * @return   The charcode for the unicode.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DWORD, FPDFXFontEncodingCharCodeFromUnicode, (FPD_FXFontEncoding fontEncoding,  FS_WCHAR Unicode))

/**
 * @brief FPDFXFontEncodingIsUnicodeCompatible
 * @details Checks whether the encoding is Unicode compatible.
 * @param[in]  fontEncoding The input font encoding.
 * @return   Checks whether the encoding is Unicode compatible.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDFXFontEncodingIsUnicodeCompatible, (FPD_FXFontEncoding fontEncoding))

/**
 * @brief FPDFXFontEncodingGlyphFromCharCodeEx
 * @details Gets the glyph index for a charcode. Return -1 for unknown. For embedded font only.
 * @param[in]  fontEncoding The input font encoding.
 * @param[in]  charcode Input a charcode.
 * @param[in]  encodingType The input encoding type. See <a>FPDFXEncodingType</a>.
 * @return   The glyph index of the charcode.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DWORD, FPDFXFontEncodingGlyphFromCharCodeEx, (FPD_FXFontEncoding fontEncoding,  FS_DWORD charcode,  FS_INT32 encodingType))

NumOfSelector(FPDFXFontEncoding)
ENDENUM

//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
//----------_V11----------
//*****************************
/* ColorConvertor HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDColorConvertorNew
 * @details Creates a new color convertor.
 * @param[in]  pDocument The input PDF document.
 * @return   A new color convertor.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(FPD_ColorConvertor, FPDColorConvertorNew, (FPD_Document pDocument))

/**
 * @brief FPDColorConvertorDestroy
 * @details Destroys the color convertor.
 * @param[in]  colorConvertor The input color convertor.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(void, FPDColorConvertorDestroy, (FPD_ColorConvertor colorConvertor))

/**
 * @brief FPDColorConvertorSetICCProfilesPath
 * @details Sets the ICC profiles path.
 * @param[in]  colorConvertor The input color convertor.
 * @param[in]  path The input path.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(void, FPDColorConvertorSetICCProfilesPath, (FPD_ColorConvertor colorConvertor,  FS_WideString path))

/**
 * @brief FPDColorConvertorGetObjColorSpace
 * @details Gets the color space of the page object.
 * @param[in]  colorConvertor The input color convertor.
 * @param[in]  pPageObject The input page object.
 * @param[in]  pResourcesDic The input resources dictionary.
 * @param[out]  outColorSpace It receives the color space.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(void, FPDColorConvertorGetObjColorSpace, (FPD_ColorConvertor colorConvertor,  FPD_PageObject pPageObject,  FPD_Object pResourcesDic,  FS_ByteString* outColorSpace))

/**
 * @brief FPDColorConvertorIsCalibrateColorSpace
 * @details Checks whether it is the calibrating color space or not.
 * @param[in]  colorConvertor The input color convertor.
 * @param[in]  pPageObject The input page object.
 * @param[in]  pResourcesDic The input resources dictionary.
 * @return   <a>TRUE</a> if it is the calibrating color space, otherwise <a>FALSE</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(FS_BOOL, FPDColorConvertorIsCalibrateColorSpace, (FPD_ColorConvertor colorConvertor,  FPD_PageObject pPageObject,  FPD_Object pResourcesDic))

/**
 * @brief FPDColorConvertorDecalibrateColor
 * @details Decalibrates color.
 * @param[in]  colorConvertor The input color convertor.
 * @param[in]  pPageObject The input page object.
 * @param[in]  pResourcesDic The input resources dictionary.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(FS_BOOL, FPDColorConvertorDecalibrateColor, (FPD_ColorConvertor colorConvertor,  FPD_PageObject pPageObject,  FPD_Object pResourcesDic))

/**
 * @brief FPDColorConvertorConvertColor
 * @details Starts to convert color.
 * @param[in]  colorConvertor The input color convertor.
 * @param[in]  pPage The input page.
 * @param[in]  pFormResourcesDic The input form resources dictionary.
 * @param[in]  pPageObject The input page object.
 * @param[in]  eGoalColorSpace The input color space.
 * @param[in]  eIntent The input rendering intent.
 * @param[in]  convertOption The input converting option.
 * @return   The converting result.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.6
 */
INTERFACE(FPD_ConvertResult, FPDColorConvertorConvertColor, (FPD_ColorConvertor colorConvertor,  FPD_Page pPage,  FPD_Object pFormResourcesDic,  FPD_PageObject pPageObject,  FPD_ColorSpaceAbbr eGoalColorSpace,  FPD_RenderingIntent eIntent,  FS_BYTE convertOption))

NumOfSelector(FPDColorConvertor)
ENDENUM

//----------_V12----------
//----------_V13----------
//----------_V14----------
//*****************************
/* OutputPreview HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_OutputPreview, FPDOutputPreviewCreate, (FPD_Document pDoc))

INTERFACE(void, FPDOutputPreviewDestroy, (FPD_OutputPreview preview))

INTERFACE(FPD_EnumColorSpace, FPDOutputPreviewSetSimulationProfile, (FPD_OutputPreview preview,  const FS_WideString& wsICCProfile))

INTERFACE(FS_BOOL, FPDOutputPreviewHasPageOverprint, (FPD_OutputPreview preview))

INTERFACE(void, FPDOutputPreviewSetShow, (FPD_OutputPreview preview,  FPD_Show eShow))

INTERFACE(void, FPDOutputPreviewSetPreview, (FPD_OutputPreview preview,  FPD_Preview ePreview))

INTERFACE(FS_BOOL, FPDOutputPreviewGetPlates, (FPD_OutputPreview preview,  FPD_ColorantType eType,  FS_ByteStringArray* aPlates))

INTERFACE(void, FPDOutputPreviewSetCheck, (FPD_OutputPreview preview,  const FS_ByteString& wsPlate,  FS_BOOL bCheck))

INTERFACE(FS_BOOL, FPDOutputPreviewGetCheck, (FPD_OutputPreview preview,  const FS_ByteString& wsPlate))

INTERFACE(FS_DIBitmap, FPDOutputPreviewGetFinalBitmap, (FPD_OutputPreview preview,  const FS_DIBitmap pDeviceBMP))

NumOfSelector(FPDOutputPreview)
ENDENUM

//*****************************
/* ImageSetParam HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_ImageSetParam, FPDImageSetParamCreate, ())

INTERFACE(void, FPDImageSetParamDestroy, (FPD_ImageSetParam param))

INTERFACE(void, FPDImageSetParamSetColor, (FPD_ImageSetParam param,  FS_ARGB* color))

INTERFACE(FS_ARGB*, FPDImageSetParamGetColor, (FPD_ImageSetParam param))

INTERFACE(void, FPDImageSetParamSetQuality, (FPD_ImageSetParam param,  FS_INT32 quality))

INTERFACE(FS_INT32, FPDImageSetParamGetQuality, (FPD_ImageSetParam param))

NumOfSelector(FPDImageSetParam)
ENDENUM

//*****************************
/* Type3FontDict HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_Type3FontDict, FPDType3FontDictCreate, ())

INTERFACE(void, FPDType3FontDictDestroy, (FPD_Type3FontDict dict))

INTERFACE(FS_BOOLEAN, FPDType3FontDictAddUnicode, (FPD_Type3FontDict dict,  FS_DWORD unicode,  FS_DIBitmap pBitmap))

INTERFACE(FPD_Object, FPDType3FontDictGenerateFontDict, (FPD_Type3FontDict dict,  FPD_Document pDocument))

NumOfSelector(FPDType3FontDict)
ENDENUM

//----------_V15----------
//----------_V16----------
//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------

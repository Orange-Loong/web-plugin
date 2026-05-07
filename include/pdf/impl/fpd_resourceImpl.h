
#ifndef FPD_RESOURCEIMPL_H
#define FPD_RESOURCEIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_RESOURCEEXPT_H
#include "../fpd_resourceExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

class CFPD_Font_V1
{	
public:
	//************************************
	// Function:  New
	// Param[in]: doc	The PDF document.
	// Param[in]: dic	The font dictionary.
	// Return:   A new PDF font object.
	// Remarks:  Creates a new PDF font object from a font dictionary.
	// Notes:
	//************************************
	static FPD_Font New(FPD_Document doc, FPD_Object dic);

	//************************************
	// Function:  Destroy	
	// Param[in]: font The input PDF font object.
	// Return:    void
	// Remarks:   Destroys the PDF font object.
	// Notes:
	//************************************
	static void Destroy(FPD_Font font);	

	//************************************
	// Function:  GetStockFont
	// Param[in]: fpdDoc		The document associated with the font name.
	// Param[in]: szFontName	The font name.
	// Return:   Return a pdf font.
	// Remarks:   Gets the "stocked" fonts (Adobe base 14 fonts), which are always available for rendering activities.
	//            However, these fonts can't be directly referred in any document, unless the font resource is added to the document.
	// Notes:	  List of currently supported standard fonts:<br>
	//            <ul>
	//            <li>Courier, Courier-Bold, Courier-BoldOblique, Courier-Oblique.</li>
	//            <li>Helvetica, Helvetica-Bold, Helvetica-BoldOblique, Helvetica-Oblique.</li>
	//            <li>Times-Roman, Times-Bold, Times-Italic, Times-BoldItalic.</li>
	//            <li>Symbol, ZapfDingbats.</li>
	//            </ul>
	//************************************
	static FPD_Font GetStockFont(FPD_Document fpdDoc, FS_LPCSTR szFontName);

	//************************************
	// Function:  GetFontType
	// Param[in]: font	The input PDF font object.
	// Return:     The font type.
	// Remarks:	  Gets the font type.
	// Notes:
	//************************************
	static FS_INT32	GetFontType(FPD_Font font);

	//************************************
	// Function:  GetFontTypeName
	// Param[in]: font			The input PDF font object.
	// Param[out]:outName		The font type name.
	// Return:    void
	// Remarks:   Gets the font type name.
	// Notes:
	//************************************
	static void GetFontTypeName(FPD_Font font,FS_ByteString* outName);

	//************************************
	// Function:  GetBaseFont
	// Param[in]: font	The input PDF font object.
	// Param[out]: outFontName It receives the base font name.
	// Return:     void
	// Remarks:   Gets the base font name.
	// Notes:
	//************************************
	static void GetBaseFont(FPD_Font font, FS_ByteString* outFontName);

	//************************************
	// Function:  GetSubstFont
	// Param[in]: font	The input PDF font object.
	// Return:    The substitute font.
	// Remarks:   Gets the substitute font.
	// Notes:
	//************************************
	static FPD_SubstFont GetSubstFont(FPD_Font font);

	//************************************
	// Function:  GetFlags 
	// Param[in]: font	The input PDF font object.
	// Return:    The font flags.
	// Remarks:   Gets the font flags.
	// Notes:
	//************************************
	static FS_DWORD GetFlags(FPD_Font font);

	
	//************************************
	// Function:  GetType1Font
	// Param[in]: font	The input PDF font object.
	// Return:    A type1 font.
	// Remarks:   Gets a type1 font.
	// Notes:
	//************************************
	static FPD_Font GetType1Font(FPD_Font font);

	//************************************
	// Function:  GetTrueTypeFont 
	// Param[in]: font	The input PDF font object.
	// Return:    A True-type font.
	// Remarks:   Gets a true type font.
	// Notes:
	//************************************
	static FPD_Font GetTrueTypeFont(FPD_Font font);

	//************************************
	// Function:  GetCIDFont
	// Param[in]: font	The input PDF font object.
	// Return:    A CID font.
	// Remarks:   Gets a CID font.
	// Notes:
	//************************************
	static FPD_Font GetCIDFont(FPD_Font font);

	//************************************
	// Function:  GetType3Font
	// Param[in]: font	The input PDF font object.
	// Return:   A type3 font.
	// Remarks:   Gets a type3 font.
	// Notes:
	//************************************
	static FPD_Font GetType3Font(FPD_Font font);

	//************************************
	// Function:  IsEmbedded
	// Param[in]: font	The input PDF font object.
	// Return:    <a>TRUE</a> if the font is an embedded font, otherwise <a>FALSE</a>.
	// Remarks:   Checks whether the font is an embedded font.
	// Notes:
	//************************************
	static FS_BOOL IsEmbedded(FPD_Font font);

	//************************************
	// Function:  IsUnicodeCompatible
	// Param[in]: font	The input PDF font object.
	// Return:    <a>TRUE</a> if the font is Unicode compatible, otherwise <a>FALSE</a>. 
	// Remarks:   Checks whether the font is Unicode compatible.
	// Notes:
	//************************************
	static FS_BOOL IsUnicodeCompatible(FPD_Font font);

	//************************************
	// Function:  GetFontFile 
	// Param[in]: font	The input PDF font object.
	// Return:    The font stream.
	// Remarks:   Gets the font stream.
	// Notes:
	//************************************
	static FPD_StreamAcc GetFontFile(FPD_Font font);

	//************************************
	// Function:  GetFontDict
	// Param[in]: font	The input PDF font object.
	// Return:   The font dictionary.
	// Remarks:   Gets the font dictionary.
	// Notes:
	//************************************
	static FPD_Object GetFontDict(FPD_Font font);

	//************************************
	// Function:  IsStandardFont 
	// Param[in]: font	The input PDF font object.
	// Return:    <a>TRUE</a> if the font is a standard font, otherwise <a>FALSE</a>.
	// Remarks:   Checks whether the font is a standard font.
	// Notes:
	//************************************
	static FS_BOOL IsStandardFont(FPD_Font font);

	//************************************
	// Function:  GetFace
	// Param[in]: font	The input PDF font object.
	// Return:    The embedded or substituted FT font face.
	// Remarks:   Gets embedded or substituted FT font face.
	// Notes:
	//************************************
	static FPD_FT_Face GetFace(FPD_Font font);


	//************************************
	// Function:      GetNextChar
	// Param[in]:     font			The input PDF font object.
	// Param[in]:     str			The char buffer.
	// Param[in,out]: inOutOffset	Input the zero-based position and receive the next charcode position.
	// Return:        A charcode with next char.
	// Remarks:       Gets a charcode from a string at specified position.
	// Notes:
	//************************************
	static FS_DWORD GetNextChar(FPD_Font font, FS_LPCSTR str, FS_INT32* inOutOffset);

	//************************************
	// Function:  CountChar
	// Param[in]: font			The input PDF font object.
	// Param[in]: str			The string buffer.
	// Param[in]: size			The length in bytes of the string.
	// Return:    The count of characters in the string.
	// Remarks:   Gets the count of characters in a string.
	// Notes:
	//************************************
	static FS_INT32 CountChar(FPD_Font font, FS_LPCSTR str, FS_INT32 size);

	//************************************
	// Function:      AppendChar
	// Param[in]:     font			The input PDF font object.
	// Param[in,out]: inOutStr		Input a string buffer and append a charcode to it.
	// Param[in]:     charcode		The charcode to append.
	// Return:        The number of bytes appended to the string buffer.
	// Remarks:       Append a charcode to a string buffer.
	// Notes:
	//************************************
	static FS_INT32 AppendChar(FPD_Font font, FS_LPSTR inOutStr, FS_DWORD charcode);

	//************************************
	// Function:      AppendChar2
	// Param[in]:     font		The input PDF font object.
	// Param[in,out]: str		Input a string buffer and append a charcode to it.
	// Param[in]:     charcode	The charcode to append.
	// Return:        void.
	// Remarks:       Append a charcode to a string buffer.
	// Notes:
	//************************************
	static void AppendChar2(FPD_Font font, FS_ByteString str, FS_DWORD charcode);

	//************************************
	// Function:  GetCharSize
	// Param[in]: font			The input PDF font object.
	// Param[in]: charcode		Input a charcode.
	// Return:    The number of bytes for the char code.
	// Remarks:   Gets the number of bytes for the char code.
	// Notes:
	//************************************
	static FS_INT32 GetCharSize(FPD_Font font, FS_DWORD charcode);


	//************************************
	// Function:  GlyphFromCharCode
	// Param[in]: font			The input PDF font object.
	// Param[in]: charcode		The charcode.
	// Return:    The glyph index of the charcode.  Return -1 for unknown.
	// Remarks:   Gets the glyph index for a charcode.
	// Notes:     For embedded font only.
	//************************************
	static FS_INT32 GlyphFromCharCode(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:   UnicodeFromCharCode
	// Param[in]:  font			The input PDF font object.
	// Param[in]:  charcode		The charcode.
	// Param[out]: outUnicode	The unicode string for the charcode. NULL for unknown.
	// Return:     
	// Remarks:    Gets a unicode string for a charcode.
	// Notes:
	//************************************
	static void UnicodeFromCharCode(FPD_Font font, FS_DWORD charcode, FS_WideString* outUnicode);

	//************************************
	// Function:  CharCodeFromUnicode
	// Param[in]: font		The input PDF font object.
	// Param[in]: unicode	The charcode.
	// Return:    The charcode for the unicode.
	// Remarks:   Gets a charcode from a Unicode.
	// Notes:
	//************************************
	static FS_DWORD CharCodeFromUnicode(FPD_Font font, FS_WCHAR unicode);

	//************************************
	// Function:  IsCharEmbedded	
	// Param[in]: font			The input PDF font object.
	// Param[in]: charcode		The charcode.
	// Return:    <a>TRUE</a> if a character is embedded, otherwise <a>FALSE</a>.
	// Remarks:   Checks whether a character is embedded.
	// Notes:
	//************************************
	static FS_BOOL IsCharEmbedded(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GetCharMap
	// Param[in]: font	The input PDF font object.
	// Return:    The character map.
	// Remarks:   Gets the character map.
	// Notes:
	//************************************
	static FS_CharMap GetCharMap(FPD_Font font);

	//************************************
	// Function:  EncodeString
	// Param[in]: font				The input PDF font object.
	// Param[in]: wszSrc			The unicode string.
	// Param[out]:outEncodeString	The encoded font string.
	// Return:    void
	// Remarks:   Encode an unicode string to font string.
	// Notes:
	//************************************
	static void EncodeString(FPD_Font font, FS_LPCWSTR wszSrc, FS_ByteString* outEncodeString);

	//************************************
	// Function:  DecodeString
	// Param[in]: font			The input PDF font object.
	// Param[in]: src			The source font string.
	// Param[out]:outResult		The decoded unicode string.
	// Return:    void
	// Remarks:   Decode a font string to unicode string.
	// Notes:
	//************************************
	static void DecodeString(FPD_Font font, FS_LPCSTR src,FS_WideString* outResult);

	//************************************
	// Function:  RecognizeChar
	// Param[in]: font			The input PDF font object.
	// Param[in]: charcode		The charcode.
	// Return:	  The recognized unicode.
	// Remarks:   Use OCR to recognize a character and return Unicode. 
	// Notes:     This function may be called when UnicodeFromCharCode() fails to get a character
	//************************************
	static FS_WCHAR RecognizeChar(FPD_Font font,FS_DWORD charcode);

	
	//************************************
	// Function:  GetFontBBox
	// Param[in]: font	The input PDF font object.
	// Return:    The font's bounding box.
	// Remarks:   Gets the font's bounding box.
	// Notes:
	//************************************
	static FS_Rect GetFontBBox(FPD_Font font);

	//************************************
	// Function:  GetTypeAscent
	// Param[in]: font	The input PDF font object.
	// Return:    The typographic ascent.
	// Remarks:   Gets the typographic ascent.
	// Notes:
	//************************************
	static FS_INT32 GetTypeAscent(FPD_Font font);

	//************************************
	// Function:  GetTypeDescent
	// Param[in]: font	The input PDF font object.
	// Return:    The typographic descent, most negative.
	// Remarks:   Gets the typographic descent, most negative.
	// Notes:
	//************************************
	static FS_INT32 GetTypeDescent(FPD_Font font);

	//************************************
	// Function:  GetItalicAngle
	// Param[in]: font	The input PDF font object.
	// Return:    The angle.
	// Remarks:   Gets the angle, expressed in degrees counterclockwise from the vertical, of the dominant vertical strokes of the font.
	// Notes:
	//************************************
	static FS_INT32 GetItalicAngle(FPD_Font font);

	//************************************
	// Function:  GetStringWidth
	// Param[in]: font				The input PDF font object.
	// Param[in]: pCharBuf			The char buffer. Must be in font encoding.
	// Param[in]: size				The length in bytes of the string.
	// Return:	  The width of the string.
	// Remarks:   Gets a string's width.
	// Notes:
	//************************************
	static FS_INT32 GetStringWidth(FPD_Font font, const FS_CHAR* pCharBuf, FS_INT32 size);

	//************************************
	// Function:  GetCharWidthF
	// Param[in]: font			The input PDF font object.
	// Param[in]: charcode		The character code.
	// Return:    The PDF width of the character. 
	// Remarks:   Gets a character's PDF width.
	// Notes:
	//************************************
	static FS_INT32 GetCharWidthF(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GetCharTypeWidth
	// Param[in]: font			The input PDF font object.
	// Param[in]: charcode		The character code.
	// Return:    The real width of the character
	// Remarks:   Gets a character's real width in the font file.
	// Notes:
	//************************************
	static FS_INT32 GetCharTypeWidth(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GetCharBBox
	// Param[in]: font			The input PDF font object.
	// Param[in]: Input			The charcode a character code.
	// Return:    The bounding box of a character.
	// Remarks:   Gets the bounding box of a character.
	// Notes:
	//************************************
	static FS_Rect GetCharBBox(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GetPDFDoc
	// Param[in]: font	The input PDF font object.
	// Return:    The PDF document.
	// Remarks:   Gets the PDF document.
	// Notes:
	//************************************
	static FPD_Document GetPDFDoc(FPD_Font font);

	//************************************
	// Function:  LoadGlyphPath
	// Param[in]: font			The input PDF font object.
	// Param[in]: charcode		The character code.
	// Param[in]: destWidth		The destination's width.
	// Return:    A character's path data. for T1, TT, and CIDFont only.
	// Remarks:   Gets a character's path data. for T1, TT, and CIDFont only.
	// Notes:
	//************************************
	static FPD_Path LoadGlyphPath(FPD_Font font, FS_DWORD charcode, FS_INT32 destWidth);

	//************************************
	// Function:  GetSubstFontCharset
	// Param[in]: substFont	The input substitution font object.
	// Return:    The charset of the substitution font.
	// Remarks:   Gets the charset of the substitution font.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static  FS_INT32 GetSubstFontCharset(FPD_SubstFont substFont);

	//************************************
	// Function:  IsVertWriting
	// Param[in]: font	The input PDF font object.
	// Return:    <a>TRUE</a> if the PDF font is vertical writing.
	// Remarks:   Checks whether the font is vertical writing.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_BOOL IsVertWriting(FPD_Font font);

	//************************************
	// Function:  GetFXFont
	// Param[in]: font	The input PDF font object.
	// Return:    The Foxit GE font.
	// Remarks:   Gets the Foxit GE font.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FPD_FXFont GetFXFont(FPD_Font font);

	//************************************
	// Function:  FXFontGetFaceName
	// Param[in]: font			The input Foxit GE font object.
	// Param[out]: outFaceName	It receives the face name.
	// Return:    void.
	// Remarks:   Gets the face name of the Foxit GE font.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void FXFontGetFaceName(FPD_FXFont font, FS_ByteString* outFaceName);

	//************************************
	// Function:  FXFontGetPsName
	// Param[in]: font			The input Foxit GE font object.
	// Param[out]: outPsName	It receives the postscript name.
	// Return:    void.
	// Remarks:   Gets the postscript name of the Foxit GE font.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void FXFontGetPsName(FPD_FXFont font, FS_WideString* outPsName);

	//************************************
	// Function:  FXFontGetFamilyName
	// Param[in]: font				The input Foxit GE font object.
	// Param[out]: outFamilyName	It receives the face name.
	// Return:   void.
	// Remarks:   Gets the family name of the Foxit GE font.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void FXFontGetFamilyName(FPD_FXFont font, FS_ByteString* outFamilyName);

	//************************************
	// Function:  FXFontIsItalic
	// Param[in]: font The input Foxit GE font object.
	// Return: TRUE if it is italic font, otherwise not.
	// Remarks: Checks whether it is italic font or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_BOOL FXFontIsItalic(FPD_FXFont font);

	//************************************
	// Function:  FXFontIsBold
	// Param[in]: font The input Foxit GE font object.
	// Return: TRUE if it is bold font, otherwise not.
	// Remarks: Checks whether it is bold font or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_BOOL FXFontIsBold(FPD_FXFont font);

	//************************************
	// Function:   UnicodeFromCharCodeEx
	// Param[in]:  font			The input PDF font object.
	// Param[in]:  charcode		The charcode.
	// Param[out]: outUnicode	The unicode string for the charcode. NULL for unknown.
	// Return: void.
	// Remarks: Gets a unicode string for a charcode. We will use "/Encoding" first if "/Encoding" is neither "Identity-H" nor "Identity-V".
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void UnicodeFromCharCodeEx(FPD_Font font, FS_DWORD charcode, FS_WideString* outUnicode);

	//************************************
	// Function:  GetSubstFontWeight
	// Param[in]: substFont	The input substitution font object.
	// Return:    The weight parameter, non-zero for synthetic weight generation only.
	// Remarks:   Gets the weight parameter, non-zero for synthetic weight generation only.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static  FS_INT32 GetSubstFontWeight(FPD_SubstFont substFont);

	//************************************
	// Function:  FXFontLoadSubst
	// Param[in]: font			The input Foxit GE font object.
	// Param[in]: lpsFaceName	PostScript name.
	// Param[in]: bTrueType		TrueType or Type1.
	// Param[in]: flags			PDF font flags (see PDF Reference section 5.7.1).
	// Param[in]: weight		Original font weight. 0 for not specified.
	// Param[in]: nItalicAngle	Original font italic angle. 0 for not specified.
	// Param[in]: nCharsetCP	Code page for charset (see Win32 GetACP()).
	// Param[in]: bVertical		Whether vertical writing-mode. Sets it FALSE as default.
	// Return: TRUE for success, otherwise not.
	// Remarks: Loads a font through font mapper.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.0.0
	//************************************
	static FS_BOOL FXFontLoadSubst(FPD_FXFont font, FS_LPCSTR lpsFaceName, FS_BOOL bTrueType, FS_DWORD flags, FS_INT32 weight, FS_INT32 nItalicAngle, FS_INT32 nCharsetCP, FS_BOOL bVertical);

	//************************************
	// Function:  GetUnicodeBaseFont
	// Param[in]: font			The input font object.
	// Param[out]: outUnicode	The unicode string for the charcode.NULL for unknown.
	// Return: void.
	// Remarks: Get unicode base font.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.0.0
	//************************************
	static void GetUnicodeBaseFont(FPD_Font font, FS_WideString* outUnicode);
	
	//************************************
	// Function:  IsTTFont
	// Param[in]: font			The input font object.
	// Return: void.
	// Remarks: Check whether it is truetype font.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FS_BOOLEAN	IsTTFont(FPD_FXFont font);

	//************************************
	// Function:  NewFXFont
	// Return:    The Foxit GE font.
	// Remarks:   Creates the Foxit GE font.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static FPD_FXFont NewFXFont(void);

	//************************************
	// Function:  DeleteFXFont
	// Param[in]: fxFont			The input FPD_FXFont object.
	// Return:    void.
	// Remarks:  Delete FPD_FXFont object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static void DeleteFXFont(FPD_FXFont fxFont);
	
	//************************************
	// Function:  GetCharOutBBox
	// Param[in]: font			The input FPD_FXFont object.
	// Param[in]: charcode		Input a character code.
	// Param[out]: rect			It receives the typographic bounding box of the character.
	// Param[in]: level			Recursive level control, optional.
	// Return:    void.
	// Remarks:  Get the typographic(display and printing) bounding box of a character.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static void	GetCharOutBBox(FPD_Font font, FS_DWORD charcode, FS_Rect* rect, FS_INT32 level);
};

class CFPD_FontEncoding_V1
{	
public:
	//************************************
	// Function:    New 
	// Param[in]: void
	// Return:   A new font encoding.
	// Remarks:  Creates a new single byte font encoding used by T1 or TT fonts.
	// Notes:
	//************************************
	static FPD_FontEncoding	New(void);

	//************************************
	// Function:    New2 
	// Param[in]: PredefinedEncoding	The input predefined encoding.
	// Return:   A new font encoding.
	// Remarks:  Creates a new font encoding with a predefined encoding.
	// Notes:
	//************************************
	static FPD_FontEncoding	New2(int PredefinedEncoding);

	//************************************
	// Function:  Destroy
	// Param[in]: fontEncoding The input font encoding.
	// Return:    void
	// Remarks:   Destroys the font encoding.
	// Notes:
	//************************************
	static void Destroy(FPD_FontEncoding fontEncoding);	

	//************************************
	// Function:  LoadEncoding
	// Param[in]: fontEncoding		The input font encoding.
	// Param[in]: encoding			The PDF object of encoding.
	// Return:    void
	// Remarks:   Loads encoding from a PDF encoding object.
	// Notes:
	//************************************
	static void	LoadEncoding(FPD_FontEncoding fontEncoding, FPD_Object encoding);

	//************************************
	// Function:  IsIdentical
	// Param[in]: fontEncoding		The input font encoding.
	// Param[in]: another			The another encoding.
	// Return:    <a>TRUE</a> means identical, <a>FLASE</a> not identical.
	// Remarks:   Checks whether the encoding is identical with another encoding.
	// Notes:
	//************************************
	static FS_BOOL IsIdentical(FPD_FontEncoding fontEncoding, FPD_FontEncoding another);

	//************************************
	// Function:  UnicodeFromCharCode	
	// Param[in]: fontEncoding		The input font encoding.
	// Param[in]: charcode			The input charcode.
	// Return:    The unicode of the charcode.
	// Remarks:   Gets the unicode from a charcode.
	// Notes:
	//************************************
	static FS_WCHAR	UnicodeFromCharCode(FPD_FontEncoding fontEncoding, FS_BYTE charcode);

	//************************************
	// Function:  CharCodeFromUnicode
	// Param[in]: fontEncoding		The input font encoding.
	// Param[in]: unicode			The unicode char code.
	// Return:    The charcode of the unicode. -1 for not found.
	// Remarks:   Gets the charcode from a unicode.
	// Notes:
	//************************************
	static FS_INT32 CharCodeFromUnicode(FPD_FontEncoding fontEncoding, FS_WCHAR unicode);

	//************************************
	// Function:  SetUnicode
	// Param[in]: fontEncoding	The input font encoding.
	// Param[in]: charcode		Input a charcode.
	// Param[in]: unicode		The new unicode value for the charcode.
	// Return:    void
	// Remarks:   Sets the unicode of a charcode.
	// Notes:
	//************************************
	static void	SetUnicode(FPD_FontEncoding fontEncoding, FS_BYTE charcode, FS_WCHAR unicode);

	//************************************
	// Function:  Realize
	// Param[in]: fontEncoding	The input font encoding.
	// Return:    A new PDF encoding object corresponding to the encoding table.
	// Remarks:   Realizes the font encoding in a PDF encoding object. Can be NULL is not needed.
	// Notes:
	//************************************
	static FPD_Object Realize(FPD_FontEncoding fontEncoding);
};

class CFPD_Type1Font_V1
{	
public:

	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty PDF type1 font.
	// Remarks:   Creates a new empty PDF type1 font.
	// Notes:
	//************************************
	static FPD_Font	New(void);

	//************************************
	// Function:  Destroy 	
	// Param[in]: font The input PDF type1 font.
	// Return:    void
	// Remarks:   Destroys the PDF type1 font.
	// Notes:
	//************************************
	static void	Destroy(FPD_Font font);	

	//************************************
	// Function:  GetEncoding
	// Param[in]: font	The input PDF type1 font.
	// Return:    The font encoding.
	// Remarks:   Gets the font encoding.
	// Notes:
	//************************************
	static FPD_FontEncoding GetEncoding(FPD_Font font);

	//************************************
	// Function:  GetCharWidthF
	// Param[in]: font			The input PDF type1 font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The PDF width of the character.
	// Remarks:   The PDF width of the character.
	// Notes:
	//************************************
	static FS_INT32 GetCharWidthF(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GetCharBBox
	// Param[in]: font			The input PDF type1 font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The bounding box of a character.
	// Remarks:   Gets the bounding box of a character.
	// Notes:
	//************************************
	static FS_Rect GetCharBBox(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GlyphFromCharCode
	// Param[in]: font			The input PDF type1 font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The glyph index of the charcode.  Return -1 for unknown.
	// Remarks:   Gets the glyph index for a charcode.
	// Notes:     For embedded font only.
	//************************************
	static FS_INT32 GlyphFromCharCode(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  IsUnicodeCompatible
	// Param[in]: font	The input PDF type1 font.
	// Return:    <a>TRUE</a> if the font is compatible for unicode, otherwise <a>FALSE</a>.
	// Remarks:   Tests whether the Type1 font is compatible for unicode.
	// Notes:
	//************************************
	static FS_BOOL IsUnicodeCompatible(FPD_Font font);

	//************************************
	// Function:  GetBase14Font
	// Param[in]: font	The input PDF type1 font.
	// Return:    An ID of standard 14 font. -1 for none. See list of standard fonts in PDF Reference.
	// Remarks:   Gets an ID of standard 14 font.
	// Notes:
	//************************************
	static FS_INT32 GetBase14Font(FPD_Font font);
};

class CFPD_TrueTypeFont_V1
{	
public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty PDF True-type font.
	// Remarks:   Creates a new True-type font.
	// Notes:
	//************************************
	static FPD_Font	New(void);

	//************************************
	// Function:  Destroy 	
	// Param[in]: font	The input True-type font.
	// Return:    void
	// Remarks:   Destroys the True-type font.
	// Notes:
	//************************************
	static void	Destroy(FPD_Font font);	

	//************************************
	// Function:  GetEncoding
	// Param[in]: font	The input True-type font.
	// Return:    The font encoding.
	// Remarks:   Gets the font encoding.
	// Notes:
	//************************************
	static FPD_FontEncoding GetEncoding(FPD_Font font);

	//************************************
	// Function:  GetCharWidthF
	// Param[in]: font			The input True-type font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The PDF width of the character.
	// Remarks:   The PDF width of the character.
	// Notes:
	//************************************
	static FS_INT32 GetCharWidthF(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GetCharBBox
	// Param[in]: font			The input True-type font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The bounding box of a character.
	// Remarks:   Gets the bounding box of a character.
	// Notes:
	//************************************
	static FS_Rect GetCharBBox(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GlyphFromCharCode
	// Param[in]: font			The input True-type font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The glyph index of the charcode.  Return -1 for unknown.
	// Remarks:   Gets the glyph index for a charcode.
	// Notes:     For embedded font only.
	//************************************
	static FS_INT32 GlyphFromCharCode(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  IsUnicodeCompatible
	// Param[in]: font	The input True-type font.
	// Return:    <a>TRUE</a> if the font is compatible for unicode, otherwise <a>FALSE</a>.
	// Remarks:   Tests whether a True-type font is compatible for unicode.
	// Notes:
	//************************************
	static FS_BOOL IsUnicodeCompatible(FPD_Font font);
};

class CFPD_Type3Char_V1
{	
public:
	//************************************
	// Function:  New 	
	// Param[in]: void
	// Return:    A new empty type3 character information object.
	// Remarks:   Creates a new empty type3 character information object.
	// Notes:
	//************************************
	static FPD_Type3Char New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: type3char The input type3 character information object.
	// Return:    void
	// Remarks:   Destroys the type3 character information object.
	// Notes:
	//************************************
	static void Destroy(FPD_Type3Char type3char);

	//************************************
	// Function:  IsColored
	// Param[in]: type3char	The input type3 character information object.
	// Return:    <a>TRUE</a> if the type3 character is colored, otherwise <a>FALSE</a>.
	// Remarks:   Tests whether the type3 character is colored.
	// Notes:
	//************************************
	static FS_BOOL IsColored(FPD_Type3Char type3char);

	//************************************
	// Function:  IsPageRequired
	// Param[in]: type3char	The input type3 character information object.
	// Return:    <a>TRUE</a> if using a page resource therefore we can't load the char.
	// Remarks:   Tests whether the Type3 font is using a page resource.
	// Notes:
	//************************************
	static FS_BOOL IsPageRequired(FPD_Type3Char type3char);	


	//************************************
	// Function:  GetForm
	// Param[in]: type3char	The input type3 character information object.
	// Return:    The form pointer if it's a form.
	// Remarks:   Gets the form pointer if it's a form.
	// Notes:
	//************************************
	static FPD_Form GetForm(FPD_Type3Char type3char);

	//************************************
	// Function:  GetImageMatrix	
	// Param[in]: type3char	The input type3 character information object.
	// Return:    The image matrix if it's a image
	// Remarks:   Gets the image matrix if it's a image
	// Notes:
	//************************************
	static FS_AffineMatrix GetImageMatrix(FPD_Type3Char type3char);

	//************************************
	// Function:  GetDIBitmap	
	// Param[in]: type3char	The input type3 character information object.
	// Return:    The image pointer if it's a image.
	// Remarks:   Gets the image pointer if it's a image.
	// Notes:
	//************************************
	static FS_DIBitmap GetDIBitmap(FPD_Type3Char type3char);

	//************************************
	// Function:  GetWidth
	// Param[in]: type3char	The input type3 character information object.
	// Return:    The character width. In font coordinate (1/1000 of em).	
	// Remarks:   Gets the character width. In font coordinate (1/1000 of em).
	// Notes:
	//************************************
	static FS_INT32 GetWidth(FPD_Type3Char type3char);

	//************************************
	// Function:  GetBBox
	// Param[in]: type3char	The input type3 character information object.
	// Return:    The character's bounding box. In font coordinate (1/1000 of em).
	// Remarks:   Gets the character's bounding box. In font coordinate (1/1000 of em).
	// Notes:
	//************************************
	static FS_Rect GetBBox(FPD_Type3Char type3char);
};

class CFPD_Type3Font_V1
{	
public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty Type3 font.
	// Remarks:   Creates a new empty Type3 font.
	// Notes:
	//************************************
	static FPD_Font	New(void);

	//************************************
	// Function:  Destroy 	
	// Param[in]: font The input Type3 font.
	// Return:    void
	// Remarks:   Destroys the Type3 font.
	// Notes:
	//************************************
	static void	Destroy(FPD_Font font);	

	//************************************
	// Function:  GetEncoding
	// Param[in]: font	The input Type3 font.
	// Return:    The font encoding.
	// Remarks:   Gets the font encoding.
	// Notes:
	//************************************
	static FPD_FontEncoding GetEncoding(FPD_Font font);

	//************************************
	// Function:  GetCharWidthF
	// Param[in]: font			The input Type3 font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The PDF width of the character.
	// Remarks:   Gets the PDF width of the character.
	// Notes:
	//************************************
	static FS_INT32 GetCharWidthF(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GetCharBBox
	// Param[in]: font			The input Type3 font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The bounding box of a character.
	// Remarks:   Gets the bounding box of a character.
	// Notes:
	//************************************
	static FS_Rect GetCharBBox(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GlyphFromCharCode
	// Param[in]: font			The input Type3 font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The glyph index of the charcode.  Return -1 for unknown.
	// Remarks:   Gets the glyph index for a charcode.
	// Notes:     For embedded font only.
	//************************************
	static FS_INT32 GlyphFromCharCode(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  IsUnicodeCompatible
	// Param[in]: font	The input Type3 font.
	// Return:    <a>TRUE</a> if font is compatible for unicode, otherwise <a>FALSE</a>.
	// Remarks:   Tests whether a Type3 font is compatible for unicode.
	// Notes:
	//************************************
	static FS_BOOL IsUnicodeCompatible(FPD_Font font);

	//************************************
	// Function:  SetPageResources 
	// Param[in]: font			The input Type3 font.
	// Param[in]: resourcesDic	the Dictionary contenting the resource.
	// Return:    void
	// Remarks:   Sets Page resources.
	// Notes:
	//************************************
	static void	SetPageResources(FPD_Font font, FPD_Object resourcesDic);

	//************************************
	// Function:  LoadChar
	// Param[in]: font			The input Type3 font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The type3 character information.
	// Remarks:	  Loads a character.
	// Notes:
	//************************************
	static FPD_Type3Char LoadChar(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GetCharTypeWidth
	// Param[in]: font			The input Type3 font.
	// Param[in]: charcode		The input character code.
	// Return:    the PDF width of the character.
	// Remarks:   Gets the PDF width of the character.
	// Notes:
	//************************************
	static FS_INT32 GetCharTypeWidth(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GetFontMatrix
	// Param[in]: font	The input Type3 font.
	// Return:    The matrix of the font. 
	// Remarks:   Gets the matrix of the font. 
	// Notes:
	//************************************
	static FS_AffineMatrix GetFontMatrix(FPD_Font font);
};

class CFPD_CIDFont_V1
{	
public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:   A new empty CID specific font.
	// Remarks:  Creates a new empty CID specific font.
	// Notes:
	//************************************
	static FPD_Font	New(void);

	//************************************
	// Function:  Destroy 	
	// Param[in]: font The input CID specific font.
	// Return:    void
	// Remarks:   Destroys the CID specific font.
	// Notes:
	//************************************
	static void	Destroy(FPD_Font font);	
		
	//************************************
	// Function:  GetCharWidthF
	// Param[in]: font			The input CID specific font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The font char width.
	// Remarks:   Gets the font char width.
	// Notes:
	//************************************
	static FS_INT32 GetCharWidthF(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GetCharBBox
	// Param[in]: font			The input CID specific font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The char bounding box.
	// Remarks:   Gets the char bounding box.
	// Notes:
	//************************************
	static FS_Rect GetCharBBox(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  GlyphFromCharCode
	// Param[in]: font			The input CID specific font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The glyph index of the charcode.  Return -1 for unknown.
	// Remarks:   The glyph index for a charcode.
	// Notes:     For embedded font only.
	//************************************
	static FS_INT32 GlyphFromCharCode(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  IsUnicodeCompatible
	// Param[in]: font	The input CID specific font.
	// Return:    <a>TRUE</a> if the CID font is compatible for unicode, otherwise <a>FALSE</a>.
	// Remarks:   Tests whether a CID font is compatible for unicode.
	// Notes:
	//************************************
	static FS_BOOL IsUnicodeCompatible(FPD_Font font);

	
	//************************************
	// Function:      GetNextChar
	// Param[in]:     font				The input CID specific font.
	// Param[in]:     str				The char buffer.
	// Param[in,out]: inOutOffset		Input the zero-based position and receive the next charcode position.
	// Return:        A charcode.
	// Remarks:       Gets a charcode from a string at specified position.
	// Notes:
	//************************************
	static FS_DWORD GetNextChar(FPD_Font font, FS_LPCSTR str, FS_INT32* inOutOffset);

	//************************************
	// Function:  CountChar
	// Param[in]: font			The input CID specific font.
	// Param[in]: str			The string buffer.
	// Param[in]: size			The length in bytes of the string.
	// Return:    The count of characters in the string.
	// Remarks:   Gets the count of characters in a string.
	// Notes:
	//************************************
	static FS_INT32 CountChar(FPD_Font font, FS_LPCSTR str, FS_INT32 size);

	//************************************
	// Function:      AppendChar
	// Param[in]:     font			The input CID specific font.
	// Param[in,out]: inOutStr		Input a string buffer and append a charcode to it.
	// Param[in]:     charcode		The charcode to append.
	// Return:        The number of bytes appended to the string buffer.
	// Remarks:       Append a charcode to a string buffer.
	// Notes:
	//************************************
	static FS_INT32 AppendChar(FPD_Font font, FS_LPSTR inOutStr, FS_DWORD charcode);

	//************************************
	// Function:  GetCharSize
	// Param[in]: font			The input CID specific font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The number of bytes for the char code.
	// Remarks:   Gets the number of bytes for the char code.
	// Notes:
	//************************************
	static FS_INT32 GetCharSize(FPD_Font font, FS_DWORD charcode);
		
	//************************************
	// Function:  LoadGB2312	
	// Param[in]: font	The input CID specific font.
	// Return:    <a>TRUE</a> if the font is loaded successfully.
	// Remarks:   Loads GB2312 char set.
	// Notes:
	//************************************
	static FS_BOOL LoadGB2312(FPD_Font font);

	//************************************
	// Function:  CIDFromCharCode
	// Param[in]: font			The input CID specific font.
	// Param[in]: charcode		Input a charcode.
	// Return:    The CID of the charcode.
	// Remarks:   Gets the CID code from charcode.
	// Notes:
	//************************************
	static FS_WORD CIDFromCharCode(FPD_Font font, FS_DWORD charcode);

	//************************************
	// Function:  IsTrueType
	// Param[in]: font	The input CID specific font.
	// Return:    <a>TRUE</a> if the font is a True-type font.
	// Remarks:   Test whether the CID font is a True-type font.
	// Notes:
	//************************************
	static FS_BOOL IsTrueType(FPD_Font font);

	//************************************
	// Function:  GetCharset
	// Param[in]: font	The input CID specific font.
	// Return:    The character set.
	// Remarks:   Gets the character set.
	// Notes:
	//************************************
	static FS_INT32 GetCharset(FPD_Font font);

	//************************************
	// Function:  GetCIDTransform
	// Param[in]: font	The input CID specific font.
	// Param[in]: CID	The input CID.
	// Return:    The CID transform.
	// Remarks:   Gets the CID transform.
	// Notes:
	//************************************
	static FS_LPBYTE GetCIDTransform(FPD_Font font, FS_WORD CID);


	//************************************
	// Function:  IsVertWriting
	// Param[in]: font	The input CID specific font.
	// Return:    <a>TRUE</a> if the CID font is vertical writing.
	// Remarks:   Checks whether the font is vertical writing.
	// Notes:
	//************************************
	static FS_BOOL IsVertWriting(FPD_Font font);	

	//************************************
	// Function:  GetVertWidth
	// Param[in]: font	The input CID specific font.
	// Param[in]: CID	Input a CID code.
	// Return:    The glyph width in vertical writing.
	// Remarks:   Gets glyph width in vertical writing.
	// Notes:
	//************************************
	static short GetVertWidth(FPD_Font font, FS_WORD CID);	

	//************************************
	// Function:  GetVertOrigin
	// Param[in]: font				The input CID specific font.
	// Param[in]: CID				Input a CID code.
	// Param[out]:outVxResult		It receives the x-coordinate of the character origin.
	// Param[out]:outVyResult		It receives the y-coordinate of the character origin.
	// Return:    void
	// Remarks:   Gets character origin in vertical writing.
	// Notes:
	//************************************
	static void GetVertOrigin(FPD_Font font, FS_WORD CID, FS_SHORT* outVxResult, FS_SHORT* outVyResult);
};

class CFPD_CIDUtil_V1
{	
public:
	//************************************
	// Function:  IsVerticalJapanCID		
	// Param[in]: CID The input CID
	// Return:    Return whether the specified CID is vertical Japanese CID.
	// Remarks:   Whether the specified CID is vertical Japanese CID.
	// Notes:
	//************************************
	static FS_BOOL IsVerticalJapanCID(FS_WORD CID);
};

class CFPD_ColorSpace_V1
{
public:
	//************************************
	// Function:  GetStockCS		
	// Param[in]: family	The color space family. See <a>FPDFontColorSpaceFamilies</a>.
	// Return:    The stocked color spaces.
	// Remarks:   Gets stocked color spaces. Stocked color spaces can not be destroyed
	//            The following color spaces are stocked:
	//            /DeviceGray, /DeviceRGB, /DeviceCMYK, /Pattern (colored patterns only).
	// Notes:
	//************************************
	static FPD_ColorSpace GetStockCS(FS_INT32 family);

	//************************************
	// Function:  Load
	// Param[in]: doc		The PDF document.
	// Param[in]: CSObj		The PDF object of a color space.
	// Return:    The color space loaded from a PDF object.
	// Remarks:   Loads color space from a PDF object.
	//            The object can be a name or an array.
	//            The returned color space can be one of the stocked color spaces, or a new instance of
	//            one derived color space class. Application should call Release() to destroy the new
	//            instance when it's not used any more.
	// Notes:
	//************************************
	static FPD_ColorSpace Load(FPD_Document doc, FPD_Object CSObj);	

	//************************************
	// Function:  ReleaseCS
	// Param[in]: cs The input color space.
	// Return:    void
	// Remarks:   Release the color space.
	// Notes:     Applications should not delete color space directly, because some color spaces are 
	//            stocked. Call Release() function instead.
	//************************************
	static void	ReleaseCS(FPD_ColorSpace cs);
	
	//************************************
	// Function:  GetBufSize
	// Param[in]: cs	The input color space.
	// Return:    The color buffer size.
	// Remarks:   Gets color buffer size.
	// Notes:
	//************************************
	static FS_INT32	GetBufSize(FPD_ColorSpace cs);	

	//************************************
	// Function:  CreateBuf
	// Param[in]: cs	The input color space.
	// Return:    The created color buffer.
	// Remarks:   Creates a color buffer.
	// Notes:
	//************************************
	static FS_FLOAT* CreateBuf(FPD_ColorSpace cs);	

	//************************************
	// Function:  GetDefaultColor
	
	// Param[in]: cs		The input color space.
	// Param[out]:outBuf	It receives the color components.
	// Return:    void
	// Remarks:   Gets the default color.
	// Notes:
	//************************************
	static void GetDefaultColor(FPD_ColorSpace cs, FS_FLOAT* outBuf);

	//************************************
	// Function:  CountComponents	
	// Param[in]: cs	The input color space.
	// Return:    The number of components.
	// Remarks:   Gets the number of components.
	// Notes:
	//************************************
	static FS_INT32	CountComponents(FPD_ColorSpace cs);

	//************************************
	// Function:  GetFamily	
	// Param[in]: cs	The input color space.
	// Return:    The color space family.
	// Remarks:   Gets the color space family.
	// Notes:
	//************************************
	static FS_INT32 GetFamily(FPD_ColorSpace cs);	

	//************************************
	// Function:  GetDefaultValue
	// Param[in]: cs			The input color space.
	// Param[in]: iComponent	The zero-based component index.
	// Param[out]:outValue		It receives the component value.
	// Param[out]:outMin		It receives the minimize component value valid.
	// Param[out]:outMax		It receives the maximize component value valid.
	// Return:    void
	// Remarks:   Gets the default value of a component.
	// Notes:
	//************************************
	static void GetDefaultValue( 
		FPD_ColorSpace cs, 
		FS_INT32 iComponent, 
		FS_FLOAT* outValue, 
		FS_FLOAT* outMin, 
		FS_FLOAT* outMax 
		);

	//************************************
	// Function:  sRGB
	// Param[in]: cs	The input color space.
	// Return:    <a>TRUE</a> if  the <param>cs</param> is sRGB or equivalent color space.
	// Remarks:   Checks whether it's sRGB or equivalent color space.
	// Notes:
	//************************************
	static FS_BOOL sRGB(FPD_ColorSpace cs);


	//************************************
	// Function:  GetRGB
	// Param[in]: cs		The input color space.
	// Param[in]: pBuf		The input color components.
	// Param[out]:outR		It receives the red component.
	// Param[out]:outG		It receives the green component.
	// Param[out]:outB		It receives the blue component.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Converts a color to RGB color space.
	// Notes:
	//************************************
	static FS_BOOL GetRGB( FPD_ColorSpace cs, FS_FLOAT* pBuf, FS_FLOAT* outR, FS_FLOAT* outG, FS_FLOAT* outB);
	
	//************************************
	// Function:  SetRGB
	// Param[in]: cs		The input color space.
	// Param[out]:outBuf	It receives the converted color.
	// Param[in]: R			The red component of the color.
	// Param[in]: G			The green component of the color.
	// Param[in]: B			The blue component of the color.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Converts a color from RGB color space.
	// Notes:
	//************************************
	static FS_BOOL SetRGB( FPD_ColorSpace cs, FS_FLOAT* outBuf, FS_FLOAT R, FS_FLOAT G, FS_FLOAT B );


	//************************************
	// Function:  GetCMYK	
	// Param[in]: cs	The input color space.
	// Param[in]: pBuf	The input color components.
	// Param[out]:outC	It receives the C component
	// Param[out]:outM	It receives the M component
	// Param[out]:outY	It receives the Y component
	// Param[out]:outK	It receives the K component
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Converts a color to CMYK color space.
	// Notes:
	//************************************
	static FS_BOOL GetCMYK( FPD_ColorSpace cs, FS_FLOAT* pBuf, FS_FLOAT* outC, FS_FLOAT* outM, FS_FLOAT* outY, FS_FLOAT* outK );	

	//************************************
	// Function:  SetCMYK
	// Param[in]: cs		The input color space.
	// Param[out]:outBuf	It receives the converted color.
	// Param[in]: c			The C component of the color.
	// Param[in]: m			The M component of the color.
	// Param[in]: y			The Y component of the color.
	// Param[in]: k			The K component of the color.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Converts a color from CMYK color space.
	// Notes:
	//************************************
	static FS_BOOL SetCMYK( FPD_ColorSpace cs, FS_FLOAT* outBuf, FS_FLOAT c, FS_FLOAT m, FS_FLOAT y, FS_FLOAT k );

	//************************************
	// Function:  TranslateImageLine
	// Param[in]: cs			The input color space.
	// Param[in]: destBuf		The destinate line buffer.
	// Param[in]: srcBuf		The source line buffer.
	// Param[in]: pixels		The pixel in the line.
	// Param[in]: imageWidth	The image_width.
	// Param[in]: imageHeight	The image height.
	// Return:    void
	// Remarks:   Converts a bitmap scan line. Source must be 8bpc with default encoding, dest is be 24bpp sRGB
	// Notes:
	//************************************
	static void	TranslateImageLine(
		FPD_ColorSpace cs,
		FS_LPBYTE destBuf,
		FS_LPCBYTE srcBuf, 
		FS_INT32 pixels,
		FS_INT32 imageWidth,
		FS_INT32 imageHeight
		);

	//************************************
	// Function:  GetArray
	// Param[in]: cs	The input color space.
	// Return:    The color space parameters array. 
	// Remarks:   Gets the color space parameters array.
	// Notes:
	//************************************
	static FPD_Object GetArray(FPD_ColorSpace cs);

	//************************************
	// Function:  GetMaxIndex
	// Param[in]: cs	The input color space.
	// Return:    The max index. For Indexed color space only.
	// Remarks:   Gets the max index. For Indexed color space only.
	// Notes:
	//************************************
	static FS_INT32 GetMaxIndex(FPD_ColorSpace cs);

	//************************************
	// Function:  GetBaseCS
	// Param[in]: cs	The input color space.
	// Return:    The based color space.    
	// Remarks:   Gets based color space. 
	// Notes:
	//************************************
	static FPD_ColorSpace GetBaseCS(FPD_ColorSpace cs);

};

class CFPD_Color_V1
{
public:

	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new PDF color object.
	// Remarks:   Creates a new empty PDF color object.
	// Notes:
	//************************************
	static FPD_Color New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: color The input PDF color object.
	// Return:    void
	// Remarks:   Destroys the PDF color object.
	// Notes:
	//************************************
	static void	Destroy(FPD_Color color);

	//************************************
	// Function:  IsNull
	// Param[in]: color	The input PDF color object.
	// Return:    <a>TRUE</a> if the color is <a>NULL</a>.
	// Remarks:   Checks whether the color is <a>NULL</a>.
	// Notes:
	//************************************
	static FS_BOOL IsNull(FPD_Color color);

	//************************************
	// Function:  IsEqual
	// Param[in]: color		The input PDF color object.
	// Param[in]: other		The another color object.
	// Return:    Non-zero means equal, otherwise not equal.
	// Remarks:   Compares with another color
	// Notes:
	//************************************
	static FS_BOOL IsEqual(FPD_Color color, FPD_Color other);	

	//************************************
	// Function:  IsPattern
	// Param[in]: color	The input PDF color object.
	// Return:    <a>TRUE</a> if the color is a pattern, otherwise <a>FALSE</a>.
	// Remarks:   Checks whether the color is a pattern.
	// Notes:
	//************************************
	static FS_BOOL IsPattern(FPD_Color color);

	//************************************
	// Function:  Copy
	// Param[in]: color	The input PDF color object.
	// Param[in]: src	The source color object.
	// Return:    void
	// Remarks:   Copies from another color.
	// Notes:
	//************************************
	static void Copy(FPD_Color color, const FPD_Color src);	

	//************************************
	// Function:  SetColorSpace
	// Param[in]: color The input PDF color object.
	// Param[in]: cs	The new color space.
	// Return:    void
	// Remarks:   Sets the color space. 
	// Notes:
	//************************************
	static void	SetColorSpace(FPD_Color color, FPD_ColorSpace cs);

	//************************************
	// Function:  GetColorSpace
	// Param[in]: color The input PDF color object.
	// Return:    The color space
	// Remarks:   Gets the color space
	// Notes:
	//************************************
	static FPD_ColorSpace GetColorSpace(FPD_Color color);	

	//************************************
	// Function:  SetValue
	// Param[in]: color			The input PDF color object.
	// Param[in]: pCompBuf		The input color components.
	// Return:    void
	// Remarks:   Sets color components in normal color space. 
	// Notes:
	//************************************
	static void SetValue(FPD_Color color, FS_FLOAT* pCompBuf);	

	//************************************
	// Function:  SetValue2
	// Param[in]: color			The input PDF color object.
	// Param[in]: pattern		The input pattern
	// Param[in]: pCompBuf		The components buffer.
	// Param[in]: ncomps		The count of components.
	// Return:    void
	// Remarks:   Sets a color in pattern color space.
	// Notes:
	//************************************
	static void SetValue2(FPD_Color color, FPD_Pattern pattern, FS_FLOAT* pCompBuf, FS_INT32 ncomps);

	//************************************
	// Function:  GetRGB
	// Param[in]: color		The input PDF color object.
	// Param[out]:outR		It receives the red component.
	// Param[out]:outG		It receives the green component.
	// Param[out]:outB		It receives the blue component.
	// Return:    <a>TRUE</a> if the color is RGB format, otherwise <a>FALSE</a>. If the return value is <a>FALSE</a>, then this color should be treated as "no-color".
	// Remarks:   Converts to default RGB color space, using single byte encoding (0-255).
	// Notes:
	//************************************
	static FS_BOOL GetRGB(FPD_Color color, FS_INT32* outR, FS_INT32* outG, FS_INT32* outB);

	//************************************
	// Function:  GetPattern
	// Param[in]: color	The input PDF color object.
	// Return:    A pattern object. <a>NULL</a> if this color is not a pattern.
	// Remarks:   Gets pattern information for <a>PDFCS_PATTERN</a> color space.
	// Notes:
	//************************************
	static FPD_Pattern GetPattern(FPD_Color color);

	//************************************
	// Function:  GetPatternCS
	// Param[in]: color	The input PDF color object.
	// Return:    The base color space for an uncolored tiling pattern.
	// Remarks:   Gets base color space for an uncolored tiling pattern.
	// Notes:
	//************************************
	static FPD_ColorSpace GetPatternCS(FPD_Color color);

	//************************************
	// Function:  GetPatternColor
	// Param[in]: color	The input PDF color object.
	// Return:    A buffer for the components. <a>NULL</a> if not applicable.
	// Remarks:   Gets component buffer for the base color space used for pattern (uncolored tiling only).
	// Notes:
	//************************************
	static FS_FLOAT* GetPatternColor(FPD_Color color);

	//************************************
	// Function:  GetColorBuffer
	// Param[in]: color	The input PDF color object.
	// Return:    <a>NULL</a> for unspecified color.
	// Remarks:   Gets the component buffer.
	// Notes:
	//************************************
	static FS_FLOAT* GetColorBuffer(FPD_Color color);
};

class CFPD_Pattern_V1
{
public:

	//************************************
	// Function:  Destroy
	// Param[in]: pattern The input PDF pattern.
	// Return: void
	// Remarks:   Destroys the PDF pattern.
	// Notes:     Can't construct a FPD_Pattern directly.
	//************************************
	static void	Destroy(FPD_Pattern pattern);
	
	//************************************
	// Function:  GetPatternObj
	// Param[in]: pattern	The input PDF pattern.
	// Return:    A dictionary for shading, stream for tiling.
	// Remarks:   Gets dictionary for shading, stream for tiling.
	// Notes:
	//************************************
	static FPD_Object GetPatternObj(FPD_Pattern pattern);

	//************************************
	// Function:  GetPatternType
	// Param[in]: pattern	The input PDF pattern.
	// Return:    The pattern type. Like FPD_PATTERN_xxx.
	// Remarks:   Gets the pattern type
	// Notes:
	//************************************
	static FS_INT32	GetPatternType(FPD_Pattern pattern);

	//************************************
	// Function:  GetPatternMatrix
	// Param[in]: pattern	The input PDF pattern.
	// Return:    The matrix from pattern to parent stream.
	// Remarks:   Gets matrix from pattern to parent stream.
	// Notes:
	//************************************
	static FS_AffineMatrix GetPatternMatrix(FPD_Pattern pattern);

	//************************************
	// Function:  GetPDDoc
	// Param[in]: pattern	The input PDF pattern.
	// Return:    The PDF document that is the pattern associated with.
	// Remarks:   Gets the PDF document.
	// Notes:
	//************************************
	static FPD_Document	GetPDDoc(FPD_Pattern pattern);

	//************************************
	// Function:  CastToShadingPatternObj
	// Param[in]: pattern	The input PDF pattern.
	// Return:    FPD_ShadingPattern
	// Remarks:   Cast to sub class FPD_ShadingPattern.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_ShadingPattern CastToShadingPatternObj(FPD_Pattern pattern);

	//************************************
	// Function:  CastToTilingPatternObj
	// Param[in]: pattern	The input PDF pattern.
	// Return:    FPD_TilingPattern
	// Remarks:   Cast to sub class FPD_TilingPattern.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_TilingPattern CastToTilingPatternObj(FPD_Pattern pattern);
};

class CFPD_TilingPattern_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: doc	The PDF document.
	// Param[in]: obj	The PDF object of the pattern.
	// Return:    A new tiling pattern object.
	// Remarks:   Creates a new tiling pattern object.
	// Notes: Not support since <a>SDK_LATEEST_VERSION</a> > 1.0. You can use FPDTilingPatternNewII instead.
	//************************************
	static FPD_TilingPattern New(FPD_Document doc, FPD_Object obj);

	//************************************
	// Function:  Destroy
	// Param[in]: pattern The input PDF tiling pattern object.
	// Return:    void
	// Remarks:   Destroys the PDF tiling pattern object.
	// Notes:
	//************************************
	static void Destroy(FPD_TilingPattern pattern);
	
	//************************************
	// Function:  GetPatternObj
	// Param[in]: pattern	The input PDF tiling pattern object.
	// Return:    A dictionary for shading, stream for tiling.
	// Remarks:   Gets dictionary for shading, stream for tiling.
	// Notes:
	//************************************
	static FPD_Object GetPatternObj(FPD_TilingPattern pattern);

	//************************************
	// Function:  GetPatternType
	// Param[in]: pattern	The input PDF tiling pattern object.
	// Return:    The pattern type.
	// Remarks:   Gets the pattern type.
	// Notes:
	//************************************
	static FS_INT32	GetPatternType(FPD_TilingPattern pattern);

	//************************************
	// Function:  GetPatternMatrix
	// Param[in]: pattern	The input PDF tiling pattern object.
	// Return:    The matrix from pattern to parent stream.
	// Remarks:   Gets matrix from pattern to parent stream.
	// Notes:
	//************************************
	static FS_AffineMatrix GetPatternMatrix(FPD_TilingPattern pattern);

	//************************************
	// Function:  GetPDDoc
	// Param[in]: pattern	The input PDF tiling pattern object.
	// Return:    The PDF document associated with the tiling pattern.
	// Remarks:   Gets the PDF document.
	// Notes:
	//************************************
	static FPD_Document	GetPDDoc(FPD_TilingPattern pattern);

	//************************************
	// Function:  Load
	// Param[in]: pattern	The input PDF tiling pattern object.
	// Return:    <a>TRUE</a> if the data is loaded, otherwise <a>FALSE</a>.
	// Remarks:   Loads all following data.  
	// Notes:
	//************************************
	static FS_BOOL Load(FPD_TilingPattern pattern);


	//************************************
	// Function:  IsColored
	// Param[in]: pattern	The input PDF tiling pattern object.
	// Return:    <a>TRUE</a> if the pattern is a colored pattern, otherwise <a>FALSE</a>.
	// Remarks:   Tests whether the pattern is a colored pattern or not.
	// Notes:
	//************************************
	static FS_BOOL IsColored(FPD_TilingPattern pattern);

	//************************************
	// Function:  GetBBox
	// Param[in]: pattern	The input PDF tiling pattern object.
	// Return:    The bounding box. In pattern space.
	// Remarks:   Gets the bounding box in pattern space.
	// Notes:
	//************************************
	static FS_FloatRect	GetBBox(FPD_TilingPattern pattern);

	//************************************
	// Function:  GetXStep
	// Param[in]: pattern	The input PDF tiling pattern object.
	// Return:    The desired horizontal spacing between pattern cells.
	// Remarks:   Gets the desired horizontal spacing between pattern cells. In pattern space, absolute values only.
	// Notes:
	//************************************
	static FS_FLOAT	GetXStep(FPD_TilingPattern pattern);

	//************************************
	// Function:  GetYStep
	// Param[in]: pattern	The input PDF tiling pattern object.
	// Return:    The desired vertical spacing between pattern cells. 
	// Remarks:   Gets the desired vertical spacing between pattern cells. In pattern space, absolute values only.
	// Notes:
	//************************************
	static FS_FLOAT	GetYStep(FPD_TilingPattern pattern);

	//************************************
	// Function:  GetForm
	// Param[in]: pattern	The input PDF tiling pattern object.
	// Return:    All objects contained in this pattern. <a>NULL</a> if not loaded.
	// Remarks:   Gets all objects contained in this pattern. 
	// Notes:
	//************************************
	static FPD_Form	GetForm(FPD_TilingPattern pattern);

	//************************************
	// Function:  NewII
	// Param[in]: doc			The PDF document.
	// Param[in]: obj			The PDF object of the pattern.
	// Param[in]: parentMatrix	The parent matrix.
	// Return:    A new tiling pattern object.
	// Remarks:   Creates a new tiling pattern object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FPD_TilingPattern NewII(FPD_Document doc, FPD_Object obj, FS_AffineMatrix parentMatrix);
};

class CFPD_ShadingPattern_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: doc			The PDF document.
	// Param[in]: obj			The PDF object of pattern.
	// Param[in]: bShading		Whether it's just a shading object.
	// Return:    A new shading pattern object.
	// Remarks:   Creates a new empty PDF shading pattern object.
	// Notes:
	//************************************
	static FPD_ShadingPattern New(FPD_Document doc, FPD_Object obj, FS_BOOL bShading);

	//************************************
	// Function:  Destroy
	// Param[in]: pattern The shading pattern object to be destroyed.
	// Return:    void
	// Remarks:   Destroys the shading pattern object.
	// Notes:
	//************************************
	static void	Destroy(FPD_ShadingPattern pattern);
	
	//************************************
	// Function:  GetPatternObj
	// Param[in]: pattern	The input PDF shading pattern object.
	// Return:    A dictionary for shading, stream for tiling.
	// Remarks:   Gets dictionary for shading, stream for tiling.
	// Notes:
	//************************************
	static FPD_Object GetPatternObj(FPD_ShadingPattern pattern);

	//************************************
	// Function:  GetPatternType
	// Param[in]: pattern	The input PDF shading pattern object.
	// Return:    The pattern type
	// Remarks:   Gets the pattern type
	// Notes:
	//************************************
	static FS_INT32	GetPatternType(FPD_ShadingPattern pattern);

	//************************************
	// Function:  GetPatternMatrix
	// Param[in]: pattern	The input PDF shading pattern object.
	// Return:    The matrix from pattern to parent stream.
	// Remarks:   Gets matrix from pattern to parent stream.
	// Notes:
	//************************************
	static FS_AffineMatrix GetPatternMatrix(FPD_ShadingPattern pattern);

	//************************************
	// Function:  GetPDDoc
	// Param[in]: pattern	The input PDF shading pattern object.
	// Return:    The PDF document.
	// Remarks:   Gets the PDF document.
	// Notes:
	//************************************
	static FPD_Document	GetPDDoc(FPD_ShadingPattern pattern);
	
	//************************************
	// Function:  Load
	// Param[in]: pattern	The input PDF shading pattern object.
	// Return:    <a>TRUE</a> if the data is loaded, otherwise <a>FALSE</a>.
	// Remarks:   Loads all following data.
	// Notes:
	//************************************
	static FS_BOOL Load(FPD_ShadingPattern pattern);

	//************************************
	// Function:  ReLoad
	// Param[in]: pattern	The input PDF shading pattern object.
	// Return:    <a>TRUE</a> if the data is reloaded, otherwise <a>FALSE</a>.
	// Remarks:   Reloads shading data after shading dictionary changed .
	// Notes:
	//************************************
	static FS_BOOL ReLoad(FPD_ShadingPattern pattern);

	//************************************
	// Function:  GetColorSpace
	// Param[in]: pattern	The input PDF shading pattern object.
	// Return:    The color space.
	// Remarks:   Gets the color space.
	// Notes:
	//************************************
	static FPD_ColorSpace GetColorSpace(FPD_ShadingPattern pattern);

	//************************************
	// Function:  GetFunc
	// Param[in]: pattern	The input PDF shading pattern object.
	// Param[in]: index		Function pointer index.
	// Return:    The function pointer.
	// Remarks:   Gets the function pointer.
	// Notes:
	//************************************
	static FPD_Function	GetFunc(FPD_ShadingPattern pattern, FS_INT32 index);

	//************************************
	// Function:  GetFuncsCount
	// Param[in]: pattern	The input PDF shading pattern object.
	// Return:    The count of functions.
	// Remarks:   Gets the count of functions.
	// Notes:
	//************************************
	static FS_INT32	GetFuncsCount(FPD_ShadingPattern pattern);

	//************************************
	// Function:  SetColorSpace
	// Param[in]: pattern		The input PDF shading pattern object.
	// Param[in]: colorSpace	The input color space to be set.
	// Return:    void.
	// Remarks:   Sets the color space.
	// Notes:
	//************************************
	static void SetColorSpace(FPD_ShadingPattern pattern, FPD_ColorSpace colorSpace);

	//************************************
	// Function:  GetShadingObject
	// Param[in]: pattern		The input PDF shading pattern object.
	// Return:    The PDF object of shading..
	// Remarks:   Gets the PDF object of shading..
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FPD_Object GetShadingObject(FPD_ShadingPattern pattern);
};

class CFPD_MeshStream_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: shadingStream	The input shading stream.
	// Param[in]: pFuncs		The array of 1-in, 1-out functions for shading.
	// Param[in]: nFuncs		The count of functions.
	// Param[in]: cs			The base color-space for shading.
	// Return:    A new PDF mesh stream.
	// Remarks:   Creates a new PDF mesh stream with the shading stream, functions, and color-spaces.
	// Notes:
	//************************************
	static FPD_MeshStream New(
		FPD_Object shadingStream, 
		FPD_Function* pFuncs, 
		FS_INT32 nFuncs,
		FPD_ColorSpace cs
		);

	//************************************
	// Function:  Destroy
	// Param[in]: meshStream The input PDF mesh stream.
	// Return:    void
	// Remarks:   Destroys the PDF mesh stream.
	// Notes:
	//************************************
	static void	Destroy(FPD_MeshStream meshStream);
	
	//************************************
	// Function:  GetFlag
	// Param[in]: meshStream	The input PDF mesh stream.
	// Return:    The vertex flag from mesh stream.
	// Remarks:   Reads a vertex flag from mesh stream.
	// Notes:
	//************************************
	static FS_DWORD	GetFlag(FPD_MeshStream meshStream);

	//************************************
	// Function:  GetCoords
	// Param[in]: meshStream	The input PDF mesh stream.
	// Param[out]:outX			It receives the X coordinate.
	// Param[out]:outY			It receives the Y coordinate.
	// Return:    void
	// Remarks:   Reads a vertex coords from mesh stream.
	// Notes:
	//************************************
	static void GetCoords(FPD_MeshStream meshStream, FS_FLOAT* outX, FS_FLOAT* outY);

	//************************************
	// Function:  GetColor
	// Param[in]: meshStream The input PDF mesh stream.
	// Param[out]:outR		 It receives the R value of a vertex color.
	// Param[out]:outG		 It receives the G value of a vertex color.
	// Param[out]:outB		 It receives the B value of a vertex color.
	// Return:    void
	// Remarks:   Reads a vertex color from mesh stream.
	// Notes:
	//************************************
	static void GetColor( FPD_MeshStream meshStream, FS_FLOAT* outR, FS_FLOAT* outG, FS_FLOAT* outB );

	//************************************
	// Function:  GetVertex
	// Param[in]: meshStream	The input PDF mesh stream.
	// Param[out]:outVertex		It receives the vertex from mesh stream.
	// Param[in]: object2Bitmap The input matrix.
	// Return:    A vertex of <param>meshStream</param>.
	// Remarks:   Reads a vertex from mesh stream.
	// Notes:
	//************************************
	static FS_DWORD GetVertex( FPD_MeshStream meshStream, FPD_MeshVertex* outVertex, FS_AffineMatrix object2Bitmap, FPD_OutputPreview outPreview);

	//************************************
	// Function:  GetVertexRow
	// Param[in]: meshStream	The input PDF mesh stream.
	// Param[out]:outVertex		It receives the vertex from mesh stream.
	// Param[in]: count			The count of the vertex array.
	// Param[in]: object2Bitmap The input matrix.
	// Return:    <a>TRUE</a> means success, otherwise <a>FALSE</a>.
	// Remarks:   Reads a vertex array from mesh stream.
	// Notes:
	//************************************
	static FS_BOOL GetVertexRow(
		FPD_MeshStream meshStream,
		FPD_MeshVertex* outVertex, 
		FS_INT32 count,
		FS_AffineMatrix object2Bitmap 
		);
};

class CFPD_Image_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: doc	The PDF document.
	// Return:    A new PDF image data object.
	// Remarks:   Creates a new PDF image data object.
	// Notes:
	//************************************
	static FPD_Image New(FPD_Document doc);

	//************************************
	// Function:  Destroy
	// Param[in]: image The input PDF image data object.
	// Return:    void
	// Remarks:   Destroys the PDF image data object.
	// Notes:
	//************************************
	static void	Destroy(FPD_Image image);
	
	//************************************
	// Function:  LoadImageF
	// Param[in]: image				The input PDF image data object.
	// Param[in]: imageStream		The input image stream.
	// Param[in]: bInline		    Whether this is an inline image. If yes, the stream will be destroyed when image destroyed.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Loads from an image stream.
	// Notes:
	//************************************
	static FS_BOOL LoadImageF(FPD_Image image, FPD_Object imageStream, FS_BOOLEAN bInline);

	//************************************
	// Function:  Clone
	// Param[in]: image	The input PDF image data object.
	// Return:    The clone of the image.
	// Remarks:   Clones an image.
	// Notes:
	//************************************
	static FPD_Image Clone(FPD_Image image);

	//************************************
	// Function:  GetStream
	// Param[in]: image	The input PDF image data object.
	// Return:    The image stream.
	// Remarks:   Gets the image stream.
	// Notes:
	//************************************
	static FPD_Object GetStream(FPD_Image image);

	//************************************
	// Function:  GetDict
	// Param[in]: image	The input PDF image data object.
	// Return:   The image dictionary.
	// Remarks:   Gets the image dictionary.
	// Notes:
	//************************************
	static FPD_Object GetDict(FPD_Image image);	

	//************************************
	// Function:  GetOC
	// Param[in]: image	The input PDF image data object.
	// Return:    The optional content dictionary.
	// Remarks:   Gets the optional content dictionary.
	// Notes:
	//************************************
	static FPD_Object GetOC(FPD_Image image);

	//************************************
	// Function:  GetDocument
	// Param[in]: image	The input PDF image data object.
	// Return:    The document.
	// Remarks:   Gets the document.
	// Notes:
	//************************************
	static FPD_Document	GetDocument(FPD_Image image);


	//************************************
	// Function:  GetPixelHeight
	// Param[in]: image	The input PDF image data object.
	// Return:    The pixel height.
	// Remarks:   Gets the pixel height.
	// Notes:
	//************************************
	static FS_INT32	GetPixelHeight(FPD_Image image);	

	//************************************
	// Function:  GetPixelWidth
	// Param[in]: image	The input PDF image data object.
	// Return:    The pixel width.
	// Remarks:   Gets the pixel width.
	// Notes:
	//************************************
	static FS_INT32	GetPixelWidth(FPD_Image image);

	//************************************
	// Function:  IsMask
	// Param[in]: image	The input PDF image data object.
	// Return:    <a>TRUE</a> if the image is a mask, otherwise <a>FALSE</a>.
	// Remarks:   Checks whether the image is a mask.
	// Notes:
	//************************************
	static FS_BOOL IsMask(FPD_Image image);	

	//************************************
	// Function:  IsInterpol
	// Param[in]: image	The input PDF image data object.
	// Return:    <a>TRUE</a> if the image interpolation is to be performed, otherwise <a>FALSE</a>.
	// Remarks:   Checks whether image interpolation is to be performed.
	// Notes:
	//************************************
	static FS_BOOL IsInterpol(FPD_Image image);

	//************************************
	// Function:  LoadDIBitmap
	// Param[in]: image				The input PDF image data object.
	// Param[out]: outMask			It receives the mask of the image.	
	// Param[out]: outMatteColor	It receives the matte color.
	// Param[in]: bStdCS			The default value is <a>FALSE</a>. Indicates whether use standard colorspace conversion(CMYK->RGB) or not.
	// Param[in]: GroupFamily		The default value is 0. The group color space family for whether to adopt a special algorithm, and the group is a group or form include this image source.
	// Param[in]: bLoadMask			The default value is <a>FALSE</a>. when processing luminosity to mask alpha, adopt a special algorithm.
	// Return:    The DIB source constructed.
	// Remarks:   Loads DIB source of the image. Optionally the mask info can be returned as well. You need invoke FSDIBitmapClone to generate the buffer for bitmap.
	// Notes:     The result bitmaps are NOT cached, so the caller must release them when finished using.
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use FSBitmapLoadDIBitmap2 instead.
	//************************************
	static FS_DIBitmap LoadDIBitmap(FPD_Image image, FS_DIBitmap* outMask, FS_DWORD* outMatteColor, FS_BOOL bStdCS, FS_DWORD GroupFamily, FS_BOOL bLoadMask);

	//************************************
	// Function:  SetImage
	// Param[in]: image		The input PDF image data object.
	// Param[in]: DIBitmap	The DIB data.
	// Param[in]: bCompress Whether to compress the DIB.
	// Param[in]: pMask		Mask image, it's valid only <param>DIBitmap</param> has on alpha channel. Mask image should be FS_DIB_1bppMask or FS_DIB_8bppMask.
	// Return:    void
	// Remarks:   Changes image data from a DIB. 
	// Notes:     The bitmaps stored in the page cache must be reset
	//            by FPDImageResetCache() for all loaded pages.
	//************************************
	static void SetImage(FPD_Image image, const FS_DIBitmap DIBitmap, FS_BOOL bCompress, FS_DIBitmap pMask);

	//************************************
	// Function:  SetJpegImage
	// Param[in]: image				The input PDF image data object.
	// Param[in]: pImageDataBuf		The JPEG data.
	// Param[in]: size				The size in bytes of the JPEG data.
	// Return:    void
	// Remarks:   Changes image data from a JPEG encoded block.
	// Notes:     The bitmaps stored in the page cache must be reset
	//            by FPDImageResetCache() for all loaded pages.
	//************************************
	static void SetJpegImage(FPD_Image image, FS_BYTE* pImageDataBuf, FS_DWORD size);

	//************************************
	// Function:  ResetCache
	// Param[in]: image			The input PDF image data object.
	// Param[in]: page			The page.
	// Param[in]: DIBitmap		The new DIB to set.
	// Return:    void
	// Remarks:   Resets the page cache.
	// Notes:
	//************************************
	static void ResetCache(FPD_Image image, FPD_Page page, const FS_DIBitmap DIBitmap);

	//************************************
	// Function:  LoadDIBitmapProgressive
	// Param[in]: image				The input PDF image data object.
	// Param[in]: formResourceDict	The input form resource dictionary.
	// Param[in]: pageResourceDict	The input page resource dictionary.
	// Param[in]: bStdCS			The default value is <a>FALSE</a>. Indicates whether use standard colorspace conversion(CMYK->RGB) or not.
	// Param[in]: GroupFamily		The default value is 0. The group color space family for whether to adopt a special algorithm, and the group is a group or form include this image source.
	// Param[in]: bLoadMask			The default value is <a>FALSE</a>. when processing luminosity to mask alpha, adopt a special algorithm.
	// Return: TRUE for success, otherwise failure.
	// Remarks:   Loads DIB source of the image progressively. You need invoke FSDIBitmapClone to generate the buffer for bitmap.
	// Notes:     The result bitmaps are NOT cached, so the caller must release them when finished using.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	//************************************
	static FS_BOOL LoadDIBitmapProgressive(FPD_Image image, FPD_Object formResourceDict, FPD_Object pageResourceDict, FS_BOOL bStdCS, FS_DWORD GroupFamily, FS_BOOL bLoadMask);

	//************************************
	// Function:  GetDIBSource
	// Param[in]: image	The input PDF image data object.
	// Return: The DIB source.
	// Remarks: Gets the DIB source.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use FSBitmapGetDIBSource2 instead.
	//************************************
	static FS_DIBitmap GetDIBSource(FPD_Image image);

	//************************************
	// Function:  GetMask
	// Param[in]: image				The input PDF image data object.
	// Return:    The mask.
	// Remarks: Gets the mask.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use FSBitmapGetMask2 instead.
	//************************************
	static FS_DIBitmap GetMask(FPD_Image image);

	//************************************
	// Function:  GetMatteColor
	// Param[in]: image				The input PDF image data object.
	// Return:    The matte color.
	// Remarks: Gets the matte color.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	//************************************
	static FS_DWORD GetMatteColor(FPD_Image image);

	//************************************
	// Function:  SetImage
	// Param[in]: image		  The input PDF image data object.
	// Param[in]: DIBitmap	  The DIB data.
	// Param[in]: iCompress   Compress type, like FPDF_IMAGE_NO_COMPRESS.
	// Param[in]: pFileWrite  A file writing object is used to store DIB data, if available.
	// Param[in]: pFileRead   A file reading object is used to initialize image stream, if available.
	// Param[in]: pMask		  Mask image, it's valid only <i>pDIBitmap</i> has on alpha channel. Mask image should be FXDIB_1bppMask or FXDIB_8bppMask.
	// Param[in]: pParam	  Matte color indicate image has been preblended.Only for FXDIB_Argb format.
	// Param[in]: pColorKey   The Color key mask, for 8bpprgb image now.
	// Param[in]: nColorKeySize		The Color key mask size.
	// Return:    FS_BOOLEAN   return true means success, otherwise failure.
	// Remarks:   pFileWrite and pFileRead should be valid together if caller need save memory.
	// Notes:     
	//************************************
	static	FS_BOOLEAN					SetImage2(FPD_Image image, const FS_DIBitmap pDIBitmap, FS_INT32 iCompress,
		 FS_FileWriteHandler pFileWrite, FS_FileReadHandler pFileRead,
			const FS_DIBitmap pMask, const FPD_ImageSetParam pParam,
		FS_INT32* pColorKey, FS_INT32 nColorKeySize);

	//************************************
	// Function:  DetachBitmap
	// Param[in]: image				The input PDF image data object.
	// Return:    FS_DIBitmap.
	// Remarks: Detach bitmap.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use FSBitmapDetachBitmap2 instead.
	//************************************
	static FS_DIBitmap			DetachBitmap(FPD_Image image);

	//************************************
	// Function:  DetachMask
	// Param[in]: image				The input PDF image data object.
	// Return:    FS_DIBitmap.
	// Remarks: Detach mask.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	// Deprecated:  Current function has been deprecated , so not recommend to use current function any more. User can use FSBitmapDetachMask2 instead.
	//************************************
	static FS_DIBitmap			DetachMask(FPD_Image image);
	
	//************************************
	// Function:  GetInlineDict
	// Param[in]: image				The input PDF image data object.
	// Return:    FPD_Object.
	// Remarks: Get the inline image dictionary.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_Object	GetInlineDict(FPD_Image image);

	//************************************
	// Function:  GetDIBSource2
	// Param[in]: image	The input PDF image data object.
	// Return: The DIB source.
	// Remarks: Gets the DIB source.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	//************************************
	static FS_DIBSource GetDIBSource2(FPD_Image image);

	//************************************
	// Function:  GetMask2
	// Param[in]: image				The input PDF image data object.
	// Return:    The mask.
	// Remarks: Gets the mask.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	//************************************
	static FS_DIBSource GetMask2(FPD_Image image);

	//************************************
	// Function:  DetachBitmap2
	// Param[in]: image				The input PDF image data object.
	// Return:    FS_DIBSource.
	// Remarks: Detach bitmap.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	//************************************
	static FS_DIBSource			DetachBitmap2(FPD_Image image);

	//************************************
	// Function:  DetachMask2
	// Param[in]: image				The input PDF image data object.
	// Return:    FS_DIBSource.
	// Remarks: Detach mask.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	//************************************
	static FS_DIBSource			DetachMask2(FPD_Image image);

	//************************************
	// Function:  LoadDIBitmap2
	// Param[in]: image				The input PDF image data object.
	// Param[out]: outMask			It receives the mask of the image.	
	// Param[out]: outMatteColor	It receives the matte color.
	// Param[in]: bStdCS			The default value is <a>FALSE</a>. Indicates whether use standard colorspace conversion(CMYK->RGB) or not.
	// Param[in]: GroupFamily		The default value is 0. The group color space family for whether to adopt a special algorithm, and the group is a group or form include this image source.
	// Param[in]: bLoadMask			The default value is <a>FALSE</a>. when processing luminosity to mask alpha, adopt a special algorithm.
	// Return:    The DIB source constructed.
	// Remarks:   Loads DIB source of the image. Optionally the mask info can be returned as well. You need invoke FSDIBitmapClone to generate the buffer for bitmap.
	// Notes:     The result bitmaps are NOT cached, so the caller must release them when finished using.
	//************************************
	static FS_DIBSource LoadDIBitmap2(FPD_Image image, FS_DIBSource* outMask, FS_DWORD* outMatteColor, FS_BOOL bStdCS, FS_DWORD GroupFamily, FS_BOOL bLoadMask);

	//************************************
	// Function:  IsInline
	// Param[in]: image				The input PDF image data object.
	// Return:    FS_BOOLEAN.
	// Remarks:  Whether the image is inline.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	//************************************
	static FS_BOOLEAN		IsInline(FPD_Image image);

	//************************************
	// Function:  Release
	// Param[in]: image				The input PDF image data object.
	// Return:    void.
	// Remarks:  Release the image.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static void Release(FPD_Image image);

	//************************************
	// Function:  SetJpegImage2
	// Param[in]: image				The input PDF image data object.
	// Param[in]: pFile				The input JPEG data stream.
	// Return:    void.
	// Remarks:  Change image data from a JPEG stream. Note the bitmaps stored in the
	// page cache must be dropped by ResetCache() for all loaded pages.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	//************************************
	static void	SetJpegImage2(FPD_Image image, FS_FileReadHandler pFile);
	
	 //************************************
	 // Function:  SetPngFileRead
	 // Param[in]: image				The input PDF image data object.
	 // Param[in]: pFile				The input PNG data stream.
	 // Param[in]: quality				if the image is color image and compress using DCT, so need set the param.
	 //							        the param is 0 - 100, and default is 80
	 // Return:    void.
	 // Remarks:  Change image data from a PNG stream. Note the bitmaps stored in the
	 // page cache must be dropped by ResetCache() for all loaded pages.
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0
	 //************************************
	static FS_BOOLEAN	SetPngFileRead(FPD_Image image, FS_FileReadHandler pFile, FS_INT32 quality);
};

class CFPD_FXFontEncoding_V5
{	
public:
	//************************************
	// Function:    New 
	// Param[in]: fpdFont The input PDF font object.
	// Return:   A new font encoding.
	// Remarks:  It works with a font to translate character codes into glyph indices in that font. It also deals with Unicode mapping (if supported).
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FPD_FXFontEncoding	New(FPD_Font fpdFont);

	//************************************
	// Function:  Destroy
	// Param[in]: fontEncoding The input font encoding.
	// Return:    void
	// Remarks:   Destroys the font encoding.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void Destroy(FPD_FXFontEncoding fontEncoding);

	//************************************
	// Function:  GlyphFromCharCode
	// Param[in]: fontEncoding The input font encoding.
	// Param[in]: charcode Input a charcode.
	// Return:    The glyph index of the charcode.
	// Remarks:   Gets the glyph index for a charcode. Return -1 for unknown. For embedded font only.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_DWORD	GlyphFromCharCode(FPD_FXFontEncoding fontEncoding, FS_DWORD charcode);

	//************************************
	// Function:  UnicodeFromCharCode
	// Param[in]: fontEncoding The input font encoding.
	// Param[in]: charcode Input a charcode.
	// Param[out]: outUnicodeString It receives the unicode string for the charcode.
	// Return:    void.
	// Remarks:   Gets a unicode string for a charcode. Return empty for unknown.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void	UnicodeFromCharCode(FPD_FXFontEncoding fontEncoding, FS_DWORD charcode, FS_WideString* outUnicodeString);

	//************************************
	// Function:  CharCodeFromUnicode
	// Param[in]: fontEncoding The input font encoding.
	// Param[in]: Unicode Input a unicode.
	// Return:    The charcode for the unicode.
	// Remarks:   Gets a charcode from a Unicode. Return -1 for unknown.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_DWORD CharCodeFromUnicode(FPD_FXFontEncoding fontEncoding, FS_WCHAR Unicode);

	//************************************
	// Function:  IsUnicodeCompatible
	// Param[in]: fontEncoding The input font encoding.
	// Return:    Checks whether the encoding is Unicode compatible.
	// Remarks:   Checks whether the encoding is Unicode compatible.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL IsUnicodeCompatible(FPD_FXFontEncoding fontEncoding);

	//************************************
	// Function:  GlyphFromCharCodeEx
	// Param[in]: fontEncoding The input font encoding.
	// Param[in]: charcode Input a charcode.
	// Param[in]: encodingType The input encoding type. See <a>FPDFXEncodingType</a>.
	// Return:    The glyph index of the charcode.
	// Remarks:   Gets the glyph index for a charcode. Return -1 for unknown. For embedded font only.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_DWORD	GlyphFromCharCodeEx(FPD_FXFontEncoding fontEncoding, FS_DWORD charcode, FS_INT32 encodingType);
};

class CFPD_ColorConvertor_V11
{
public:
	//************************************
	// Function:    New 
	// Param[in]: pDocument The input PDF document.
	// Return:   A new color convertor.
	// Remarks:  Creates a new color convertor.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static FPD_ColorConvertor New(FPD_Document pDocument);

	//************************************
	// Function:  Destroy
	// Param[in]: colorConvertor The input color convertor.
	// Return:    void
	// Remarks:   Destroys the color convertor.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static void Destroy(FPD_ColorConvertor colorConvertor);

	//************************************
	// Function:    SetICCProfilesPath 
	// Param[in]: colorConvertor The input color convertor.
	// Param[in]: path The input path.
	// Return:   void.
	// Remarks:  Sets the ICC profiles path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static void SetICCProfilesPath(FPD_ColorConvertor colorConvertor, FS_WideString path);

	//************************************
	// Function:    GetObjColorSpace 
	// Param[in]: colorConvertor The input color convertor.
	// Param[in]: pPageObject The input page object.
	// Param[in]: pResourcesDic The input resources dictionary.
	// Param[out]: outColorSpace It receives the color space.
	// Return:   void.
	// Remarks:  Gets the color space of the page object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static void GetObjColorSpace(FPD_ColorConvertor colorConvertor, FPD_PageObject pPageObject, FPD_Object pResourcesDic, FS_ByteString* outColorSpace);

	//************************************
	// Function:    IsCalibrateColorSpace 
	// Param[in]: colorConvertor The input color convertor.
	// Param[in]: pPageObject The input page object.
	// Param[in]: pResourcesDic The input resources dictionary.
	// Return:   <a>TRUE</a> if it is the calibrating color space, otherwise <a>FALSE</a>.
	// Remarks:  Checks whether it is the calibrating color space or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static FS_BOOL IsCalibrateColorSpace(FPD_ColorConvertor colorConvertor, FPD_PageObject pPageObject, FPD_Object pResourcesDic);

	//************************************
	// Function:    DecalibrateColor 
	// Param[in]: colorConvertor The input color convertor.
	// Param[in]: pPageObject The input page object.
	// Param[in]: pResourcesDic The input resources dictionary.
	// Return:   <a>TRUE</a> for success, otherwise failure.
	// Remarks:  Decalibrates color.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static FS_BOOL DecalibrateColor(FPD_ColorConvertor colorConvertor, FPD_PageObject pPageObject, FPD_Object pResourcesDic);

	//************************************
	// Function:    ConvertColor 
	// Param[in]: colorConvertor The input color convertor.
	// Param[in]: pPage The input page.
	// Param[in]: pFormResourcesDic The input form resources dictionary.
	// Param[in]: pPageObject The input page object.
	// Param[in]: eGoalColorSpace The input color space.
	// Param[in]: eIntent The input rendering intent.
	// Param[in]: convertOption The input converting option.
	// Return:   The converting result.
	// Remarks:  Starts to convert color.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static FPD_ConvertResult ConvertColor(
		FPD_ColorConvertor colorConvertor, 
		FPD_Page pPage,
		FPD_Object pFormResourcesDic,
		FPD_PageObject pPageObject,
		FPD_ColorSpaceAbbr eGoalColorSpace,
		FPD_RenderingIntent eIntent,
		FS_BYTE convertOption);
};

class CFPD_OutputPreview_V14
{
public:
	static FPD_OutputPreview Create(FPD_Document pDoc);	
	static void Destroy(FPD_OutputPreview preview);
	static FPD_EnumColorSpace SetSimulationProfile(FPD_OutputPreview preview, const FS_WideString& wsICCProfile);
	static FS_BOOL HasPageOverprint(FPD_OutputPreview preview);
	static void SetShow(FPD_OutputPreview preview, FPD_Show eShow);
	static void SetPreview(FPD_OutputPreview preview, FPD_Preview ePreview);
	static FS_BOOL GetPlates(FPD_OutputPreview preview, FPD_ColorantType eType, FS_ByteStringArray* aPlates);
	static void SetCheck(FPD_OutputPreview preview, const FS_ByteString& wsPlate, FS_BOOL bCheck);
	static FS_BOOL GetCheck(FPD_OutputPreview preview, const FS_ByteString& wsPlate);
	static FS_DIBitmap GetFinalBitmap(FPD_OutputPreview preview, const FS_DIBitmap pDeviceBMP);
};

class CFPD_ImageSetParam_V14
{
public:
	static FPD_ImageSetParam Create();
	static void Destroy(FPD_ImageSetParam param);
	static void SetColor(FPD_ImageSetParam param, FS_ARGB* color);
	static FS_ARGB* GetColor(FPD_ImageSetParam param);
	static void SetQuality(FPD_ImageSetParam param, FS_INT32 quality);
	static FS_INT32 GetQuality(FPD_ImageSetParam param);
};

class CFPD_Type3FontDict_V14
{
public:	
	static FPD_Type3FontDict Create();
	static void Destroy(FPD_Type3FontDict dict);
	static FS_BOOLEAN		AddUnicode(FPD_Type3FontDict dict, FS_DWORD unicode, FS_DIBitmap pBitmap);
	static FPD_Object	    GenerateFontDict(FPD_Type3FontDict dict, FPD_Document pDocument);
};


#ifdef __cplusplus
};
#endif//__cplusplus


#endif//FPD_RESOURCEIMPL_H

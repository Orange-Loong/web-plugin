/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_resourceExpT.h
		
 - Types, macros, structures, etc. 

*********************************************************************/

/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/

/**
* @file
* @brief PDF resource classes.
*/

/** @addtogroup FPDRESOURCE*/
/*@{*/

#ifndef FPD_RESOURCEEXPT_H
#define FPD_RESOURCEEXPT_H



#ifndef FPD_OBJSEXPT_H
#include "fpd_objsExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/* @OBJSTART FPD_Font */
/** 
  * @brief The <a>FPD_Font</a> object is used to manipulate the PDF font. See <a>FPDFontNew</a>, <a>FPDFontDestroy</a>.
  */
#ifndef FPD_FONT
#define FPD_FONT
typedef struct _t_FPD_Font* FPD_Font;
#endif

/* @DEFGROUPSTART FPDFontTypeIDs */
/**
 * @name Font type IDs. See <a>FPDFontGetFontType</a>.
 */
/*@{*/

/** @brief Type1. */
#define FPD_FONT_TYPE1			1
/** @brief True type. */
#define FPD_FONT_TRUETYPE		2
/** @brief Type3. */
#define FPD_FONT_TYPE3			3
/** @brief CID font. */
#define FPD_FONT_CIDFONT		4
	
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDFontFlags */
/**
  * @name Font flags. See <a>FPDFontGetFlags</a>.
  */

/*@{*/

/** @brief All glyphs have the same width. */
#define FPD_FONT_FIXEDPITCH		1
/** @brief Glyphs have serifs, which are short strokes drawn at an angle on the top and bottom of glyph stems. */
#define FPD_FONT_SERIF			2
/** @brief Font contains glyphs outside the Adobe standard Latin character set. */
#define FPD_FONT_SYMBOLIC		4
/** @brief Glyphs resemble cursive handwriting. */
#define FPD_FONT_SCRIPT			8
/** @brief Font uses the Adobe standard Latin character set or a subset of it. */
#define FPD_FONT_NONSYMBOLIC	32
/** @brief Glyphs have dominant vertical strokes that are slanted. */
#define FPD_FONT_ITALIC			64
/** @brief Font contains no lowercase letters. */
#define FPD_FONT_ALLCAP			0x10000
/** @brief Font contains both uppercase and lowercase letters. */
#define FPD_FONT_SMALLCAP		0x20000
/** @brief Whether bold glyphs are painted with extra pixels even at very small text sizes. */
#define FPD_FONT_FORCEBOLD		0x40000

/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDFontPredefinedEncoding */
/**
 * @name Predefined encoding. See <a>FPDFontEncodingNew</a>.
 */
/*@{*/

/** @brief Built-in encoding. */
#define FPD_FONT_ENCODING_BUILTIN		0
/** @brief Windows ansic encoding. */
#define FPD_FONT_ENCODING_WINANSI		1
/** @brief Mac roman encoding. */
#define FPD_FONT_ENCODING_MACROMAN		2
/** @brief Mac expert encoding. */
#define FPD_FONT_ENCODING_MACEXPERT		3
/** @brief Adobe standard encoding. */
#define FPD_FONT_ENCODING_STANDARD		4
/** @brief Adobe symbol encoding. */
#define FPD_FONT_ENCODING_ADOBE_SYMBOL	5
/** @brief ZapfDingbats encoding. */
#define FPD_FONT_ENCODING_ZAPFDINGBATS	6
/** @brief PDF Document encoding. */
#define FPD_FONT_ENCODING_PDFDOC	    7
/** @brief Microsoft symbol encoding. */
#define FPD_FONT_ENCODING_MS_SYMBOL		8
/** @brief Unicode encoding. */
#define FPD_FONT_ENCODING_UNICODE		9

/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDFontColorSpaceFamilies */
/**
 * @name Color space families. See <a>FPDColorSpaceGetFamily</a>.
 */
/*@{*/

/** @brief DeviceGray. */
#define FPD_CS_DEVICEGRAY		1
/** @brief DeviceRGB. */	
#define FPD_CS_DEVICERGB		2
/** @brief DeviceCMYK. */
#define FPD_CS_DEVICECMYK		3
/** @brief CalGray. */
#define FPD_CS_CALGRAY			4
/** @brief CalRGB. */
#define FPD_CS_CALRGB			5
/** @brief Lab. */
#define FPD_CS_LAB				6
/** @brief ICCBased. */
#define FPD_CS_ICCBASED			7
/** @brief Separation. */
#define FPD_CS_SEPARATION		8
/** @brief DeviceN. */
#define FPD_CS_DEVICEN			9
/** @brief Indexed. */
#define FPD_CS_INDEXED			10
/** @brief Pattern. */
#define FPD_CS_PATTERN			11

/*@}*/
/* @DEFGROUPEND */



/* @OBJEND */

/* @OBJSTART FPD_Type1Font */
/** @brief The Type1 font.
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_TrueTypeFont */
/** @brief  The True-Type font.
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_Type3Font */
/** @brief The Type3 font. Type 3 fonts do not have the ability to provide a base font with more than one encoding. 
 * For each Type 3 font, there is only one encoding. This encoding is completely specified in the PDF file; there are 
 * no shortcuts as there are for other fonts.
 * <Italic>See Section 5.7, Font Descriptors, in the PDF Reference </Italic>for a discussion of font descriptors.
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_CIDFont */
/** @brief The CIDFont. A CIDFont is designed to contain a large number of glyph procedures and is used for languages such 
 * as Chinese, Japanese, or Korean. Instead of being accessed by a name, each glyph procedure is accessed by an integer 
 * known as a character identifier or CID. Instead of a font encoding, CIDFonts use a CMap to define the mapping from 
 * character codes to a font number and a character selector.
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_SubstFont */
/** 
  * @brief Substitution font. See <a>FPDSubstFontNew</a>, <a>FPDSubstFontDestroy</a>.
  */
#ifndef FPD_SUBSTFONT
#define FPD_SUBSTFONT
typedef struct _t_FPD_SubstFont* FPD_SubstFont;
#endif
/* @OBJEND */

/* @OBJSTART FPD_FT_Face */
#ifndef FPD_FT_FACE
#define FPD_FT_FACE

/** @brief FreeType root face class structure. A face object models a
  * typeface in a font file.
  */
typedef struct _t_FPD_FT_Face* FPD_FT_Face;
#endif
/* @OBJEND */

/* @OBJSTART FPD_FontEncoding */
/** 
  * @brief Single byte font encoding used by T1 or TT fonts. See <a>FPDFontEncodingNew</a>, <a>FPDFontEncodingDestroy</a>.
  */
#ifndef FPD_FONTENCODING
#define FPD_FONTENCODING
typedef struct _t_FPD_FontEncoding* FPD_FontEncoding;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Type3Char */
/** 
  * @brief Type3 character information. See <a>FPDType3CharNew</a>, <a>FPDType3CharDestroy</a>.
  */
#ifndef FPD_TYPE3CHAR
#define FPD_TYPE3CHAR
typedef struct _t_FPD_Type3Char* FPD_Type3Char;
#endif
/* @OBJEND */

/* @OBJSTART FPD_CIDUtil */
/** 
  * @brief An utility class for CID processing. See <a>FPDCIDUtilIsVerticalJapanCID</a>.
  */
#ifndef FPD_CIDUTIL
#define FPD_CIDUTIL
typedef struct _t_FPD_CIDUtil* FPD_CIDUtil;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ColorSpace */
/** 
  * @brief The color space used in pdf color system. see <Italic>CHAPTER 4.5 in PDF reference</Italic>. 
  * See <a>FPDColorSpaceLoad</a>, <a>FPDColorSpaceReleaseCS</a>.
  */
#ifndef FPD_COLORSPACE
#define FPD_COLORSPACE
typedef struct _t_FPD_ColorSpace* FPD_ColorSpace;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Color */
/** 
  * @brief PDF color. see <Italic>CHAPTER 4.5 in PDF reference</Italic>. See <a>FPDColorNew</a>, <a>FPDColorDestroy</a>.
  */
#ifndef FPD_COLOR
#define FPD_COLOR
typedef struct _t_FPD_Color* FPD_Color;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Pattern */
/** 
  * @brief The abstract class for tiling pattern and shading pattern.  Has no "new" functions. see <Italic>CHAPTER 4.6 in PDF reference</Italic>. 
  * See <a>FPDPatternDestroy</a>.
  */
#ifndef FPD_PATTERN
#define FPD_PATTERN
typedef struct _t_FPD_Pattern* FPD_Pattern;
#endif

/* @DEFGROUPSTART Pattern types*/
/**
* @brief Name Pattern types.
*/
/*@{*/

/** @brief repeating pattern cells. */
#define FPD_PATTERN_TILING		1
/** @brief gradient color shading. */
#define FPD_PATTERN_SHADING		2

/* @DEFGROUPEND */
/* @OBJEND */

/* @OBJSTART FPD_TilingPattern */
/** 
  * @brief The tiling pattern. see <Italic>CHAPTER 4.6.2 in PDF reference</Italic>. 
  *
  * Consist of colored tiling pattern and uncolored tiling pattern.
  * A colored tiling pattern is a pattern whose color is self-contained.
  * An uncolored tiling pattern is a pattern that has no inherent color.
  * See <a>FPDTilingPatternNew</a>, <a>FPDTilingPatternDestroy</a>.
  */
#ifndef FPD_TILINGPATTERN
#define FPD_TILINGPATTERN
typedef struct _t_FPD_TilingPattern* FPD_TilingPattern;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ShadingPattern */
/** 
  * @brief PDF shading pattern.  see <Italic>CHAPTER 4.6.3 in PDF reference</Italic>. 
  *
  * Shading patterns provide a smooth transition between colors across an area to be painted, 
  * independent of the resolution of any particular output device and 
  * without specifying the number of steps in the color transition.
  * See <a>FPDShadingPatternNew</a>, <a>FPDShadingPatternDestroy</a>.
  */
#ifndef FPD_SHADINGPATTERN
#define FPD_SHADINGPATTERN
typedef struct _t_FPD_ShadingPattern* FPD_ShadingPattern;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Function */
/** 
  * @brief No document exits. 
  */
#ifndef FPD_FUNCTION
#define FPD_FUNCTION
typedef struct _t_FPD_Function* FPD_Function;
#endif
/* @OBJEND */

/* @OBJSTART FPD_MeshStream */
/** 
  * @brief No document exits. See <a>FPDMeshStreamNew</a>, <a>FPDMeshStreamDestroy</a>.
  */
#ifndef FPD_MESHSTREAM
#define FPD_MESHSTREAM
typedef struct _t_FPD_MeshStream* FPD_MeshStream;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Image */
/** 
  * @brief Holding image(sampled image) data . see <Italic>CHAPTER 4.8 in PDF reference</Italic>.
  *
  * A sampled image (or just image for short) is a rectangular array of sample values, each representing a color.
  * It can be an <Italic>XObject</Italic> image, or an <Italic>inline</Italic> image.
  * See <a>FPDImageNew</a>, <a>FPDImageDestroy</a>.
  */
#ifndef FPD_IMAGE
#define FPD_IMAGE
typedef struct _t_FPD_Image* FPD_Image;
#endif

#ifndef FPD_IMAGESETPARAM
#define FPD_IMAGESETPARAM
typedef struct _t_FPD_ImageSetParam* FPD_ImageSetParam;
#endif


#ifndef FPD_TYPE3FONTDICT
#define FPD_TYPE3FONTDICT
typedef struct _t_FPD_Type3FontDict* FPD_Type3FontDict;
#endif



/* @STRUCTSTART FPD_MeshVertex */
/** @brief No document exits. */
#ifndef FPD_MESHVERTEX
#define FPD_MESHVERTEX
typedef struct __FPD_MeshVertex__
{
	FS_FLOAT x, y;
	FS_FLOAT r, g, b;
}FPD_MeshVertex, *PFPD_MeshVertex;
#endif
/* @STRUCTEND */
/* @OBJEND */

/* @OBJSTART FPD_FXFontEncoding */
/** 
* @brief It works with a font to translate character codes into glyph indices in that font. It also deals with Unicode mapping (if supported).
  * See <a>FPDFXFontEncodingNew</a>, <a>FPDFXFontEncodingDestroy</a>.
  */
#ifndef FPD_FXFONTENCODING
#define FPD_FXFONTENCODING
typedef struct _t_FPD_FXFontEncoding* FPD_FXFontEncoding;
#endif

/* @DEFGROUPSTART FPDFXEncodingType */
/**
 * @name Encoding type. See <a>FPDFXFontEncodingGlyphFromCharCodeEx</a>.
 */
/*@{*/
/** @brief Whatever internal encoding in the font. */
#define FPD_FXENCODING_INTERNAL		0
/** @brief Unicode encoding. */
#define FPD_FXENCODING_UNICODE		1
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_FXFont */
/** 
  * @brief The <a>FPD_FXFont</a> object is used to manipulate the Foxit GE font. See <a>FPDFontGetFXFont</a>.
  */
#ifndef FPD_FXFONT
#define FPD_FXFONT
typedef struct _t_FPD_FXFont* FPD_FXFont;
#endif

/* @OBJEND */

/* @OBJSTART FPD_ColorConvertor */

#ifndef FS_COLORCONVERTOR
#define	FS_COLORCONVERTOR
/**
* @brief An object representing a PDF color convertor.
*
*
*/
typedef struct _t_FPD_ColorConvertor* FPD_ColorConvertor;
#endif

/* @ENUMSTART */
/**
  * @brief PDF color space attributes.
  */
enum FPD_ColorSpaceAbbr
{
	FPD_BW = 0,		/**< Black & White. */
	FPD_sGray,		/**< sGray. */
	FPD_sRGB,		/**< sRGB IEC61966-2.1. */
	FPD_CMYK		/**< U.S. Web Coated(SWOP) v2. */
};
/* @ENUMEND */

/* @ENUMSTART */
/**
  * @brief PDF rendering intent.
  */

enum FPD_RenderingIntent
{
	FPD_Perceptual = 0,		/**< Perceptual. */
	FPD_RelColorimetric,	/**< Relative Colorimetric. */
	FPD_Saturation,			/**< Saturation. */
	FPD_AbsColorimetric		/**< Absolute Colorimetric. */
};
/* @ENUMEND */

/* @ENUMSTART */
/**
  * @brief PDF converting option.
  */
enum FPD_ConvertOption
{
	FPD_None = 0x00,			/**< No Option setted. */
	FPD_EmbedProfile = 0x01,	/**< Embed Profile. */
	FPD_PreserveBlack = 0x02,	/**< Preserve Black. */
	FPD_ProGrayToCmykB = 0x04,	/**< Promote Gray to CMYK Black. */
	FPD_PreserveCmykPri = 0x08,	/**< Preserve CMYK Primaries. */
};
/* @ENUMEND */

/* @ENUMSTART */
/**
  * @brief The PDF color converting result.
  */
enum FPD_ConvertResult
{
	FPD_Error = 0,		/**< Error. */
	FPD_Success,		/**< Error. */
	FPD_NotConvert,		/**< Not convert. */
};
/* @ENUMEND */

/* @OBJEND */


#ifndef FS_OUTPUTPREVIEW
#define	FS_OUTPUTPREVIEW
typedef struct _t_FPD_OutputPreview* FPD_OutputPreview;
#endif

enum FPD_EnumColorSpace
{
	FPD_Unknown = -1,	// ICC not set, or damaged ICC profile file.
	FPD_IccGray,		 // Gray ICC profile.
	FPD_IccRgb,			 // RGB  ICC profile.
	FPD_IccCmyk			 // CMYK ICC profile.
};


enum FPD_Show
{
	FPDShow_All = 0,				// Show all objects and colors.
	FPDShow_DeviceCMYK,				// Only show DeviceCMYK color.
	FPDShow_NotDeviceCMYK,			// Only Show not DeviceCMYK color.
	FPDShow_ICCBasedCMYK,			// Only show ICCbasedCMYK color.
	FPDShow_SpotColor,				// Only show Spot color.
	FPDShow_DeviceCMYKAndSpot,		// Only Show DeviceCMYK color and Spot color.
	FPDShow_NotDeviceCMYKOrSpot,	// Only Show not DeviceCMYK color or Spot color.
	FPDShow_DeviceN,				// Only show DeviceN color.
	FPDShow_CMYK,					// Only Show CMYK color.
	FPDShow_RGB,					// Only Show RGB color.
	FPDShow_DeviceRGB,				// Only show DeviceRGB color.
	FPDShow_ICCBasedRGB,			// Only show ICCBasedRGB color.
	FPDShow_Gray,					// Only Show Gray color.
	FPDShow_DeviceGray,				// Only show DeviceGray color.
	FPDShow_CalGray,				// Only show CalGray color.
	FPDShow_Calibrated,				// Only Show Calibrated color.
	FPDShow_Lab,					// Only show Lab color.
	FPDShow_Device,					// Only Show Device color.
	FPDShow_Images,					// Only show image object.
	FPDShow_SolidColor,				// Only show solid color.
	FPDShow_SmoothShades,			// Only show smooth shades.
	FPDShow_RegistrationColor,		// Only show registration color.
	FPDShow_Text,					// Only show text object.
	FPDShow_LineArt					// Only Show line art.
};

enum FPD_Preview
{
	FPD_Separations = 0,	// Preview separations.
	FPD_ColorWarnings,		// Preview color warnings.
	FPD_ObjectInspector		// Preview object inspector.
};

enum FPD_ColorantType
{
	FPD_Process = 0,	// Process plate.
	FPD_Spot			// Spot plate.
};
/* @DEFGROUPSTART FPDFontFlags */
/**
 * @name Basic font flags, same as flags used in PDF fonts.
 */
/*@{*/
/** @brief  */
#define FPD_FXFONT_FIXED_PITCH		0x01
/** @brief  */
#define FPD_FXFONT_SERIF			0x02
/** @brief  */
#define FPD_FXFONT_SYMBOLIC			0x04
/** @brief  */
#define FPD_FXFONT_SCRIPT			0x08
/** @brief  */
#define FPD_FXFONT_ITALIC			0x40
/** @brief  */
#define FPD_FXFONT_BOLD				0x40000
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDImageCompressTypes */
/**
 * @name Image compress types.
 */
/*@{*/
/** @brief no compress. */
#define FPDF_IMAGE_NO_COMPRESS				0x0000
/** @brief lossy compress. */
#define FPDF_IMAGE_LOSSY_COMPRESS			0x0001
/** @brief lossless compress. */
#define FPDF_IMAGE_LOSSLESS_COMPRESS			0x0002
/** @brief mask image lossy compress. */
#define FPDF_IMAGE_MASK_LOSSY_COMPRESS		0x0004
/** @brief mask image lossless compress. */
#define FPDF_IMAGE_MASK_LOSSLESS_COMPRESS	0x0008
/*@}*/
/* @DEFGROUPEND */

#ifdef __cplusplus
};
#endif

#endif

/*@}*/

/*@}*/
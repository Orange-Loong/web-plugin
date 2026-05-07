#ifndef FPD_LREXPT_H
#define FPD_LREXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "fpd_parserExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "fpd_objsExpT.h"
#endif

#ifndef FPD_RESOURCEEXPT_H
#include "fpd_resourceExpT.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "fpd_pageExpT.h"
#endif

#ifndef FPD_RENDEREXPT_H
#include "fpd_renderExpT.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif


/* @OBJSTART FPD_LR_Context */
#ifndef FPD_LRCONTEXT
#define	FPD_LRCONTEXT
	typedef struct _t_FPD_LR_Context* FPD_LR_Context;
#endif

/* @DEFGROUPSTART FPDLR_VERSION */
/**
 * @brief LR version.
 */
 /*@{*/
#define FPDLR_VERSION_2_5 20500
#define FPDLR_VERSION_2_6 20600 
#define FPDLR_VERSION_2_6_1 20601
#define FPDLR_VERSION_2_6_2 20602
#define FPDLR_VERSION_LATEST FPDLR_VERSION_2_6_1
#define FPDLR_VERSION_DEFAULT FPDLR_VERSION_2_5
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_LR_StructureElementRef */
#ifndef FPD_LRSTRUCTUREELEMENTREF
#define	FPD_LRSTRUCTUREELEMENTREF
	typedef struct _t_FPD_LR_StructureElementRef* FPD_LR_StructureElementRef;
#endif

#define FPDLR_TAG(c1,c2,c3,c4) (((FS_DWORD) (c1)<<24) | (FS_DWORD) (c2)<<16 | (FS_DWORD) (c3)<<8 | (FS_DWORD) (c4))

	/* @ENUMSTART */
/**
 * @brief Layout attribute types.
 */
	typedef enum _FPDLR_StdAttr {
		FPDLR_A_Invalid = FPDLR_TAG(0, 0, 0, 0),							/**< Invalid. */
		FPDLR_A_Role = FPDLR_TAG('R', 'O', 'L', 'E'),						/**< Strings of structure element meaning and standard type it maps to. */
		FPDLR_A_FormStyle = FPDLR_TAG('F', 'R', 'M', 'S'),				/**< Strings of Form field style. */
		FPDLR_A_FormMaxLen = FPDLR_TAG('F', 'L', 'E', 'N'),				/**< Form field Max len*/
		FPDLR_A_Placement = FPDLR_TAG('P', 'L', 'A', 'C'),				/**< Enum (Block, Inline, Before, Start, End). */
		FPDLR_A_Rotation = FPDLR_TAG('R', 'O', 'T', 'A'),					/**< Number or enum. */
		FPDLR_A_WritingMode = FPDLR_TAG('W', 'M', 'O', 'D'),				/**< Enum (LrTb, RlTb, TbRl). */
		FPLR_A_Destination = FPDLR_TAG('D', 'E', 'S', 'T'),				/**< Array of zero or stirngs with Id. it provides a means to access content. Since PDF2.0. */
		FPDLR_A_BBox = FPDLR_TAG('B', 'B', 'O', 'X'),						/**< Array of numbers. */
		FPDLR_A_Width = FPDLR_TAG('W', 'D', 'T', 'H'),					/**< Number or enum (Auto). */
		FPDLR_A_Height = FPDLR_TAG('H', 'G', 'H', 'T'),					/**< Number or enum (Auto). */

		FPDLR_A_BackgroundColor = FPDLR_TAG('B', 'K', 'G', 'C'),			/**< Color. */

		FPDLR_A_BorderColor = FPDLR_TAG('B', 'D', 'R', 'C'),				/**< Color, or array of colors. */
		FPDLR_A_BorderStyle = FPDLR_TAG('B', 'D', 'R', 'S'),				/**< Enum (None, Hidden, Dotted, Dashed, Solid, Double, Groove, Ridge, Inset, Outset), or array of enums. */
		FPDLR_A_BorderThickness = FPDLR_TAG('B', 'D', 'R', 'T'),			/**< Number, of array of numbers. */

		FPDLR_A_Attached = FPDLR_TAG('A', 'T', 'T', 'H'),					/**< Array of enums (Top, Left, Bottom, Right). */
		FPDLR_A_SubType = FPDLR_TAG('S', 'U', 'B', 'T'),					/**< String for Annot, Enum (Pagination, Layout, Page, or Background) for Artifact. */
		FPDLR_A_Padding = FPDLR_TAG('P', 'A', 'D', 'G'),					/**< Number, or array of numbers. */
		FPDLR_A_Color = FPDLR_TAG('C', 'O', 'L', 'R'),					/**< Color. */
		FPDLR_A_SpaceBefore = FPDLR_TAG('S', 'P', 'B', 'F'),				/**< Number. */
		FPDLR_A_SpaceAfter = FPDLR_TAG('S', 'P', 'A', 'F'),				/**< Number. */
		FPDLR_A_StartIndent = FPDLR_TAG('S', 'I', 'N', 'D'),				/**< Number. */
		FPDLR_A_EndIndent = FPDLR_TAG('E', 'I', 'N', 'D'),				/**< Number. */
		FPDLR_A_TextIndent = FPDLR_TAG('T', 'I', 'N', 'D'),				/**< Number. */
		FPDLR_A_TextAlign = FPDLR_TAG('T', 'A', 'L', 'N'),				/**< Enum (Start, Center, End, Justify). */
		FPDLR_A_BlockAlign = FPDLR_TAG('B', 'A', 'L', 'N'),				/**< Enum (Before, Middle, After, Justify). */
		FPDLR_A_InlineAlign = FPDLR_TAG('I', 'A', 'L', 'N'),				/**< Enum (Start, Center, End). */
		FPDLR_A_TBorderStyle = FPDLR_TAG('T', 'B', 'D', 'S'),				/**< Enum (None, Hidden, Dotted, Dashed, Solid, Double, Groove, Ridge, Inset, Outset), or array of enums. */
		FPDLR_A_TPadding = FPDLR_TAG('T', 'P', 'A', 'D'),					/**< Number, or array of numbers. */
		FPDLR_A_BaselineShift = FPDLR_TAG('B', 'S', 'H', 'F'),			/**< Number. */
		FPDLR_A_LineHeight = FPDLR_TAG('L', 'H', 'G', 'T'),				/**< Number or enum (Normal, Auto). */
		FPDLR_A_TextDecorationColor = FPDLR_TAG('T', 'D', 'C', 'L'),		/**< Color. */
		FPDLR_A_TextDecorationThickness = FPDLR_TAG('T', 'D', 'T', 'H'),	/**< Number. */
		FPDLR_A_TextDecorationType = FPDLR_TAG('T', 'D', 'T', 'Y'),		/**< Enum (None, Underline, Overline, LineThrough). */
		FPDLR_A_RubyAlign = FPDLR_TAG('R', 'B', 'A', 'L'),				/**< Enum (Start, Center, End, Justify, Distribute). */
		FPDLR_A_RubyPosition = FPDLR_TAG('R', 'B', 'P', 'S'),				/**< Enum (Before, After, Warichu, Inline). */
		FPDLR_A_GlyphOrientationVertical = FPDLR_TAG('G', 'O', 'V', 'T'),	/**< Enum (Auto, -90, 0, 90, 180, 270). */
		FPDLR_A_ColumnCount = FPDLR_TAG('C', 'L', 'C', 'N'),				/**< Number. */
		FPDLR_A_ColumnGap = FPDLR_TAG('C', 'L', 'G', 'P'),				/**< Number, or array of numbers. */
		FPDLR_A_ColumnWidths = FPDLR_TAG('C', 'L', 'W', 'D'),				/**< Number, or array of numbers. */
		FPDLR_A_ListNumbering = FPDLR_TAG('L', 'N', 'U', 'M'),			/**< Owner = 'List', Enum (None, Disc, Circle, Square, Decimal, UpperRoman, LowerRoman, UpperAlpha, LowerAlpha). */
		FPDLR_A_FieldRole = FPDLR_TAG('F', 'R', 'O', 'L'),				/**< Owner = 'PrintField', Enum (rb, cb, pb, tv). */
		FPDLR_A_FieldChecked = FPDLR_TAG('C', 'H', 'K', 'D'),				/**< Owner = 'PrintField', Enum (on, off, neutral). */
		FPDLR_A_FieldDesc = FPDLR_TAG('F', 'D', 'S', 'C'),				/**< Owner = 'PrintField', Text. */
		FPDLR_A_RowSpan = FPDLR_TAG('R', 'S', 'P', 'N'),					/**< Owner = 'Table', Number. */
		FPDLR_A_ColSpan = FPDLR_TAG('C', 'S', 'P', 'N'),					/**< Owner = 'Table', Number. */
		FPDLR_A_TableHeaders = FPDLR_TAG('T', 'H', 'D', 'S'),				/**< Owner = 'Table', Array of element IDs (not supported now). */
		FPDLR_A_TableHeaderScope = FPDLR_TAG('T', 'H', 'S', 'C'),			/**< Owner = 'Table', Enum (Row, Column, Both). */
		FPDLR_A_TableSummary = FPDLR_TAG('T', 'B', 'S', 'M'),				/**< Owner = 'Table', Text. */
		FPDLR_A_Short = FPDLR_TAG('S', 'H', 'O', 'R'),					/**< a short content of the TH. Since PDF2.0. */
		FPDLR_A_Direction = FPDLR_TAG('D', 'I', 'R', 'E'),					/**< Enum (Start, End, Before, After, Other). */
		FPDLR_A_ABox = FPDLR_TAG('A', 'L', 'B', 'X'),						/**< Array of numbers. */
		FPDLR_A_Version = FPDLR_TAG('V', 'E', 'S', 'N'),					/**< Schema version of LR. */
		FPDLR_A_SurmiseCaption = FPDLR_TAG('S', 'M', 'C', 'P'),
	} FPDLR_StdAttr;
	/* @ENUMEND */
	
	/* @ENUMSTART */
	/**
	 * @brief Layout attribute enums.
	 */
	enum FPDLR_StdAttrValueEnum {
		FPDLR_AV_Invalid = FPDLR_TAG(0, 0, 0, 0),					/**< Invalid. */
		FPDLR_AV_Block = FPDLR_TAG('B', 'L', 'C', 'K'),			/**< Block. */
		FPDLR_AV_Inline = FPDLR_TAG('I', 'N', 'L', 'N'),			/**< Inline. */
		FPDLR_AV_Warichu = FPDLR_TAG('W', 'A', 'R', 'I'),		/**< Warichu.	*/
		FPDLR_AV_Before = FPDLR_TAG('B', 'E', 'F', 'R'),			/**< Before. */
		FPDLR_AV_After = FPDLR_TAG('A', 'F', 'T', 'E'),			/**< After. */
		FPDLR_AV_Start = FPDLR_TAG('S', 'T', 'R', 'T'),			/**< Start. */
		FPDLR_AV_End = FPDLR_TAG('E', 'N', 'D', 0),				/**< End. */
		FPDLR_AV_LrTb = FPDLR_TAG('L', 'R', 'T', 'B'),			/**< LrTb. */
		FPDLR_AV_RlTb = FPDLR_TAG('R', 'L', 'T', 'B'),			/**< RlTb. */
		FPDLR_AV_TbRl = FPDLR_TAG('T', 'B', 'R', 'L'),			/**< TbRl. */
		FPDLR_AV_TbLr = FPDLR_TAG('T', 'B', 'L', 'R'),			/**< TbLr. Since PDF2.0. */
		FPDLR_AV_None = FPDLR_TAG('N', 'O', 'N', 'E'),			/**< None. */
		FPDLR_AV_Hidden = FPDLR_TAG('H', 'I', 'D', 'N'),			/**< Hidden. */
		FPDLR_AV_Dotted = FPDLR_TAG('D', 'O', 'T', 'D'),			/**< Dotted. */
		FPDLR_AV_Dashed = FPDLR_TAG('D', 'S', 'H', 'D'),			/**< Dashed. */
		FPDLR_AV_Solid = FPDLR_TAG('S', 'O', 'L', 'D'),			/**< Solid. */
		FPDLR_AV_Double = FPDLR_TAG('D', 'B', 'L', 'E'),			/**< Double. */
		FPDLR_AV_Groove = FPDLR_TAG('A', 'R', 'T', 'Y'),			/**< Groove. */
		FPDLR_AV_Ridge = FPDLR_TAG('R', 'D', 'G', 'E'),			/**< Ridge. */
		FPDLR_AV_Inset = FPDLR_TAG('I', 'N', 'S', 'T'),			/**< Inset. */
		FPDLR_AV_Outset = FPDLR_TAG('O', 'T', 'S', 'T'),			/**< Outset. */
		FPDLR_AV_Normal = FPDLR_TAG('N', 'R', 'M', 'L'),			/**< Normal. */
		FPDLR_AV_Auto = FPDLR_TAG('A', 'U', 'T', 'O'),			/**< Auto. */
		FPDLR_AV_Center = FPDLR_TAG('C', 'N', 'T', 'R'),			/**< Center. */
		FPDLR_AV_Justify = FPDLR_TAG('J', 'S', 'T', 'Y'),			/**< End. */
		FPDLR_AV_Middle = FPDLR_TAG('M', 'I', 'D', 'L'),			/**< Justify. */
		FPDLR_AV_Underline = FPDLR_TAG('U', 'D', 'L', 'N'),		/**< Underline. */
		FPDLR_AV_Overline = FPDLR_TAG('O', 'V', 'L', 'N'),		/**< Overline. */
		FPDLR_AV_LineThrough = FPDLR_TAG('L', 'N', 'T', 'H'),		/**< LineThrough. */
		FPDLR_AV_Distribute = FPDLR_TAG('D', 'S', 'T', 'B'),		/**< Distribute. */
		FPDLR_AV_Disc = FPDLR_TAG('D', 'I', 'S', 'C'),			/**< Disc. */
		FPDLR_AV_Circle = FPDLR_TAG('C', 'R', 'C', 'L'),			/**< Circle. */
		FPDLR_AV_Square = FPDLR_TAG('S', 'Q', 'U', 'R'),			/**< Square. */
		FPDLR_AV_Decimal = FPDLR_TAG('D', 'C', 'M', 'L'),			/**< Decimal. */
		FPDLR_AV_UpperRoman = FPDLR_TAG('U', 'P', 'R', 'M'),		/**< UpperRoman. */
		FPDLR_AV_LowerRoman = FPDLR_TAG('L', 'W', 'R', 'M'),		/**< LowerRoman. */
		FPDLR_AV_UpperAlpha = FPDLR_TAG('U', 'P', 'A', 'L'),		/**< UpperAlpha. */
		FPDLR_AV_LowerAlpha = FPDLR_TAG('L', 'W', 'A', 'L'),		/**< LowerAlpha. */
		FPDLR_AV_Unordered = FPDLR_TAG('U', 'N', 'O', 'R'),		/**< Unordered. Since PDF2.0. */
		FPDLR_AV_Ordered = FPDLR_TAG('O', 'R', 'D', 'E'),			/**< ORdered. Since PDF2.0. */
		FPDLR_AV_Float = FPDLR_TAG('F', 'L', 'O', 'T'),			/**< float. */
		FPDLR_AV_RB = FPDLR_TAG('R', 'B', 0, 0),					/**< rb. */
		FPDLR_AV_CB = FPDLR_TAG('C', 'B', 0, 0),					/**< cb. */
		FPDLR_AV_PB = FPDLR_TAG('P', 'D', 0, 0),					/**< pd. */
		FPDLR_AV_TV = FPDLR_TAG('T', 'V', 0, 0),					/**< tv. */
		FPDLR_AV_On = FPDLR_TAG('O', 'N', 0, 0),					/**< on. */
		FPDLR_AV_Off = FPDLR_TAG('O', 'F', 'F', 0),				/**< off. */
		FPDLR_AV_Neutral = FPDLR_TAG('N', 'U', 'T', 'R'),			/**< neutral. */
		FPDLR_AV_Row = FPDLR_TAG('R', 'O', 'W', 0),				/**< Row. */
		FPDLR_AV_Column = FPDLR_TAG('C', 'L', 'M', 'N'),			/**< Column. */
		FPDLR_AV_Both = FPDLR_TAG('B', 'O', 'T', 'H'),			/**< Both. */
		FPDLR_AV_Left = FPDLR_TAG('L', 'E', 'F', 'T'),			/**< Left. */
		FPDLR_AV_Top = FPDLR_TAG('T', 'O', 'P', 0),				/**< Top. */
		FPDLR_AV_Bottom = FPDLR_TAG('B', 'T', 'O', 'M'),			/**< Bottom. */
		FPDLR_AV_Right = FPDLR_TAG('R', 'G', 'H', 'T'),			/**< Right. */
		FPDLR_AV_Pagination = FPDLR_TAG('P', 'A', 'G', 'N'),		/**< Pagination. */
		FPDLR_AV_Layout = FPDLR_TAG('L', 'A', 'Y', 'O'),			/**< Layout. */
		FPDLR_AV_Page = FPDLR_TAG('P', 'A', 'G', 'E'),			/**< Page. */
		FPDLR_AV_Background = FPDLR_TAG('B', 'K', 'G', 'N'),		/**< Background. */
		FPDLR_AV_Header = FPDLR_TAG('H', 'E', 'A', 'D'),			/**< Header. */
		FPDLR_AV_Footer = FPDLR_TAG('F', 'O', 'O', 'T'),			/**< Footer. */
		FPDLR_AV_Watermark = FPDLR_TAG('W', 'T', 'M', 'K'),		/**< Watermark. */
		FPDLR_AV_PageNum = FPDLR_TAG('P', 'N', 'U', 'M'),		/**< PageNum. Since PDF2.0. */
		FPDLR_AV_Bates = FPDLR_TAG('B', 'A', 'T', 'E'),		/**< Bates. Since PDF2.0. */
		FPDLR_AV_Other = FPDLR_TAG('O', 'T', 'H', 'E'),		/**< Bates. Since PDF2.0. */
		FPDLR_AV_Logical = FPDLR_TAG('L', 'O', 'G', 'I')			/**< Logical. */
	} ;
	/* @ENUMEND */

	/* @ENUMSTART */
	/**
	 * @brief Layout attribute types.
	*/
	enum FPDLR_StdAttrValueType
	{
		FPDLR_VT_Empty = 0x0,
		FPDLR_VT_Enum = 0x1,
		FPDLR_VT_Int32 = 0x2,
		FPDLR_VT_Float = 0x3,
		FPDLR_VT_ARGB = 0x4,
		FPDLR_VT_WStr = 0x5,
		FPDLR_VT_Element = 0x6,
		FPDLR_VT_ArrayMask = 0x100,
		FPDLR_VT_EnumArray = FPDLR_VT_ArrayMask | FPDLR_VT_Enum,
		FPDLR_VT_FloatArray = FPDLR_VT_ArrayMask | FPDLR_VT_Float,
		FPDLR_VT_Int32Array = FPDLR_VT_ArrayMask | FPDLR_VT_Int32,
		FPDLR_VT_ARGBArray = FPDLR_VT_ArrayMask | FPDLR_VT_ARGB,
		FPDLR_VT_WStrArray = FPDLR_VT_ArrayMask | FPDLR_VT_WStr,
		FPDLR_VT_ElementArray = FPDLR_VT_ArrayMask | FPDLR_VT_Element,
	} ;
	/* @ENUMEND */

/* @OBJEND */

/* @OBJSTART FPD_LR_ElementRef */
#ifndef FPD_LRELEMENTREF
#define	FPD_LRELEMENTREF
	typedef struct _t_FPD_LR_ElementRef* FPD_LR_ElementRef;
#endif

/* @DEFGROUPSTART FPDLR_ETMask */
/**
 * @brief FPDLR_ETMask.
 */
/*@{*/
#define FPDLR_ETMask_StructureStandard  0x00000000
#define FPDLR_ETMask_StructureCustom	0x40000000
#define FPDLR_ETMask_PageObject		    0x80000000
#define FPDLR_ETMask_Content			0xC0000000
#define FPDLR_ETMaskSelector			0xC0000000
/*@}*/
/* @DEFGROUPEND */

	/* @OBJEND */

	/* @OBJSTART FPD_LR_ParseOptions */
#ifndef FPD_LRPARSEOPTION
#define	FPD_LRPARSEOPTION
	typedef struct _t_FPD_LR_ParseOptions* FPD_LR_ParseOptions;
#endif

#define FPDLR_PROFILE_STANDARD              0x00000000
#define FPDLR_PROFILE_STRUCTURE_MARKUP      0x00010000
#define FPDLR_PROFILE_CONTENTFLOW           0x00020000
#define FPDLR_PROFILE_CONTENTFLOW_NONSTRICT 0x00028000
#define FPDLR_PROFILE_SLIDEDECK             0x00030000
#define FPDLR_PROFILE_SPREADSHEET           0x00040000
#define FPDLR_PROFILE_FORMFILL_NONSTRICT    0x00058000
#define FPDLR_PROFILE_NN_STANDARD           0x00060000
#define FPDLR_PROFILE_NN_STANDARD_TEST           0x00061000
#define FPDLR_PROFILE_TEST_PAGINATION_ONLY       0x00062000
#define FPDLR_PROFILE_DIVIDING_TEXTLINE_ONLY     0x00063000
#define FPDLR_PROFILE_TEXT_NODE_ONLY		 0x00064000
#define FPDLR_PROFILE_CONVERT_WML			 0x00065000
#define FPDLR_PROFILE_CONVERT_PML			 0x00066000
#define FPDLR_PROFILE_CONVERT_SML			 0x00067000
#define FPDLR_PROFILE_25_SECTION			 0x00068000
#define	FPDLR_PROFILE_DOCUMENTBODY_GENERATE  0x00069000
#define FPDLR_PROFILE_INTERNAL_TEXTGROUP    0x00070000
#define FPDLR_PROFILE_ABOX					0x00071000
#define FPDLR_PROFILE_PAGINATION_OCR        0x00072000
#define FPDLR_PROFILE_CONVERT_TXT           0x00073000
#define FPDLR_PROFILE_COLOR_GROUP_WML       0x00074000

#define FPDLR_PROFILE_TEST_NEW_FEATURE		 0xFFFFFFFF

#define FPDLR_PROFILE_AUTO_TAG "auto_tag"
	/* @OBJEND */

	/* @OBJSTART FPD_LR_ElementListRef */
#ifndef FPD_LRELEMENTLISTREF
#define	FPD_LRELEMENTLISTREF
	typedef struct _t_FPD_LR_ElementListRef* FPD_LR_ElementListRef;
#endif

/* @OBJSTART FPD_LRStdStructElemType */
/* @ENUMSTART */
	/**
	* @Layout element types. Including all element types defined in PDF Reference 1.7.
	*/

	/*@{*/
	enum FPD_LRStdStructElemType{
		FPDLR_ET_Document = 0x0000,		/**< (Document) A complete document. */
		FPDLR_ET_DocumentFragment = 0x0001,		/**< (DocumentFragment) A part of A complete document. since PDF2.0.*/
		FPDLR_ET_Part = 0x0002,		/**< (Part) A large-scale division of a document. */
		FPDLR_ET_Art = 0x0101,		/**< (Article) A relatively self-contained body of text constituting a single narrative or exposition. */
		FPDLR_ET_Sect = 0x0102,		/**< (Section) A container for grouping related content elements. */
		FPDLR_ET_Div = 0x0100,		/**< (Division) A generic block-level element or group of elements. */
		FPDLR_ET_BlockQuote = 0x0103,		/**< (Block quotation) A portion of text consisting of one or more paragraphs attributed to someone other than the author of the surrounding text. */
		FPDLR_ET_Caption = 0x0104,		/**< (Caption) A brief portion of text describing a table or figure. */
		FPDLR_ET_TOC = 0x0105,		/**< (Table of contents) A list made up of table of contents item entries and/or other nested table of contents entries (TOC). */
		FPDLR_ET_TOCI = 0x0106,		/**< (Table of contents item) An individual member of a table of contents. */
		FPDLR_ET_Index = 0x0107,		/**< (Index) A sequence of entries containing identifying text accompanied by reference elements that point out occurrences of the specified text in the main body of a document. */
		FPDLR_ET_Aside = 0x0108,		/**< (Aside) Enclose content that is distinct from other content within its parent. since PDF2.0. */
		FPDLR_ET_Title = 0x0109,		/**< (Title) The title of a document. Since PDF2.0. */
		FPDLR_ET_FENote = 0x010A,		/**< (FENote) Used to markup footnotes and endnotes. Since PDF2.0. */
		FPDLR_ET_NonStruct = 0x010F,		/**< (Nonstructural element) A grouping element having no inherent structural significance; it serves solely for grouping purposes. */
		FPDLR_ET_Private = 0x0110,		/**< (Private element) A grouping element containing private content belonging to the application producing it. */
		FPDLR_ET_PrivateMax = 0x01FF,		/**< Max usuable type recognized as private element.*/
		FPDLR_ET_User = FPDLR_ET_Private,			/**< Alias for ET_Private.*/
		FPDLR_ET_Paragraph = 0x0200,		/**< (Paragraph) A low-level division of text. */
		FPDLR_ET_Heading = 0x0201,		/**< (Heading) A label for a subdivision of a document's content. It should be the first child of the division that it heads. */
		FPDLR_ET_Heading1 = 0x0202,		/**< (H1) Headings level 1. */
		FPDLR_ET_Heading2 = 0x0203,		/**< (H2) Headings level 2. */
		FPDLR_ET_Heading3 = 0x0204,		/**< (H3) Headings level 3. */
		FPDLR_ET_Heading4 = 0x0205,		/**< (H4) Headings level 4. */
		FPDLR_ET_Heading5 = 0x0206,		/**< (H5) Headings level 5. */
		FPDLR_ET_Heading6 = 0x0207,		/**< (H6) Headings level 6. */
		FPDLR_ET_HeadingN = 0x0208,		/**< (Hn) Headings level 7 or more. Since PDF 2.0 */
		FPDLR_ET_List = 0x0209,		/**< (List) A sequence of items of like meaning and importance. */
		FPDLR_ET_ListItem = 0x020A,		/**< (List item) An individual member of a list. */
		FPDLR_ET_ListLabel = 0x020B,		/**< (Label) A name or number that distinguishes a given item from others in the same list or other group of like items. */
		FPDLR_ET_ListBody = 0x020C,		/**< (List body) The descriptive content of a list item. */
		FPDLR_ET_Table = 0x020D,		/**< (Table) A two-dimensional layout of rectangular data cells, possibly having a complex substructure. */
		FPDLR_ET_TableRow = 0x020E,		/**< (Table row) A row of headings or data in a table. */
		FPDLR_ET_TableHeaderCell = 0x020F,		/**< (Table header cell) A table cell containing header text describing one or more rows or columns of the table. */
		FPDLR_ET_TableDataCell = 0x0210,		/**< (Table data cell) A table cell containing data that is part of the table's content. */
		FPDLR_ET_TableHeaderGroup = 0x0211,		/**< (Table header row group; PDF 1.5) A group of rows that constitute the header of a table. */
		FPDLR_ET_TableBodyGroup = 0x0212,		/**< (Table body row group; PDF 1.5) A group of rows that constitute the main body portion of a table. */
		FPDLR_ET_TableFootGroup = 0x0213,		/**< (Table footer row group; PDF 1.5) A group of rows that constitute the footer of a table. */
		FPDLR_ET_Span = 0x0300,		/**< (Span) A generic inline portion of text having no particular inherent characteristics. */
		FPDLR_ET_Quote = 0x0301,		/**< (Quotation) An inline portion of text attributed to someone other than the author of the surrounding text. */
		FPDLR_ET_Note = 0x0302,		/**< (Note) An item of explanatory text, such as a footnote or an endnote, that is referred to from within the body of the document. */
		FPDLR_ET_Reference = 0x0303,		/**< (Reference) A citation to content elsewhere in the document. */
		FPDLR_ET_BibEntry = 0x0304,		/**< (Bibliography entry) A reference identifying the external source of some cited content. */
		FPDLR_ET_Code = 0x0305,		/**< (Code) A fragment of computer program text. */
		FPDLR_ET_Link = 0x0306,		/**< (Link) An association between a portion of the ILSE's content and a corresponding link annotation or annotations. */
		FPDLR_ET_Annot = 0x0307,		/**< (Annotation; PDF 1.5) An association between a portion of the ILSE's content and a corresponding PDF annotation. */
		FPDLR_ET_Ruby = 0x0308,		/**< (Ruby) The wrapper around the entire ruby assembly. */
		FPDLR_ET_RubyBase = 0x0309,		/**< (Ruby base text) The full-size text to which the ruby annotation is applied. */
		FPDLR_ET_RubyAnnot = 0x030A,		/**< (Ruby annotation text) The smaller-size text that is placed adjacent to the ruby base text. */
		FPDLR_ET_RubyPunc = 0x030B,		/**< (Ruby punctuation) Punctuation surrounding the ruby annotation text. */
		FPDLR_ET_Warichu = 0x030C,		/**< (Warichu) The wrapper around the entire warichu assembly. */
		FPDLR_ET_WarichuText = 0x030D,		/**< (Warichu text) The smaller-size text of a warichu comment that is formatted into two lines and placed between surrounding WP elements. */
		FPDLR_ET_WarichuPunc = 0x030E,		/**< (Warichu punctuation) The punctuation that surrounds the WT text. */
		FPDLR_ET_Em = 0x030F,		/**< (Em) Enclose content for the purpose of emphasis. Since PDF2.0. */
		FPDLR_ET_Strong = 0x0310,		/**< (Strong) Enclose content for the purpose of emphasis, emphasis strong than Em. Since PDF2.0. */
		FPDLR_ET_Sub = 0x0311,		/**< (Sub) Encloses content typically perceived as a sub-division inside a block level structure element. Since PDF2.0. */
		FPDLR_ET_Figure = 0x0400,		/**< (Figure) An item of graphical content. Its placement may be specified with the Placement layout attribute. */
		FPDLR_ET_Formula = 0x0401,		/**< (Formula) A mathematical formula. */
		FPDLR_ET_Form = 0x0402,		/**< (Form) A widget annotation representing an interactive form field. */
		FPDLR_ET_Artifact = 0x1000,		/**< (Artifact) Including other Pagination, Layout, Page and Background artifacts. */
		FPDLR_ET_Transparent = 0x2000, 		/**< ($Transparent$) Internal invisible element. */
		FPDLR_ET_StardardMax = 0xFFFF, 		/**< ($StardardMax$) Max value used as standard tag. */
		FPDLR_ET_CustomMax = 0x4000FFFF, 	/**< ($CustomMax$) Max value used as custom tag. */
	};
	/*@}*/
/* @ENUMEND */
/* @OBJEND */

/* @OBJSTART FPD_LR_ContentElementRef */
#ifndef FPD_LRCONTENTELEMENTREF
#define	FPD_LRCONTENTELEMENTREF
	typedef struct _t_FPD_LR_ContentElementRef* FPD_LR_ContentElementRef;
#endif
/* @OBJEND */

/* @OBJSTART FPD_LR_PageObjectElementRef */
#define FPDLR_ETMask_StructureStandard 0x00000000
#define FPDLR_ETMask_StructureCustom	0x40000000
#define FPDLR_ETMask_PageObject		0x80000000
#define FPDLR_ETMask_Content			0xC0000000
#define FPDLR_ETMaskSelector			0xC0000000

#define FPDLR_StructureETMask_Document	    0x0000
#define FPDLR_StructureETMask_Grouping	    0x0100
#define FPDLR_StructureETMask_BLSE		    0x0200
#define FPDLR_StructureETMask_ILSE		    0x0300
#define FPDLR_StructureETMask_Illustration 0x0400
#define FPDLR_StructureETMask_Artifact     0x1000
#define FPDLR_StructureETMask_User			0x8000
#define FPDLR_StructureETMaskSelector      0xFF00

#define FPDLR_StructureTypeETMaskSelector      0xFFFF

#ifdef PDFPAGE_PLACE
#define FPDPAGE_LR_PLACE		PDFPAGE_PLACE
#else
#define FPDPAGE_LR_PLACE		0x0B
#endif

#define FPDPAGE_LR_ANNOT_APPEARANCE 0x09
#define FPDPAGE_LR_PARTIAL		0x0A		
#define FPDPAGE_LR_CONTAINER	0x0C
#define FPDPAGE_LR_COMPLEX		0x0D
#define FPDPAGE_LR_ANNOT		0x0E
#define FPDPAGE_LR_PAGE			0x0F

#define FPDLR_ET_TextContentElement	(FPDLR_ETMask_Content		| FPD_PAGEOBJ_TEXT		)	/**< Text piece, graphics unit. */
#define FPDLR_ET_PathContentElement	(FPDLR_ETMask_Content		| FPD_PAGEOBJ_PATH		)	/**< Path, graphics unit. */
#define FPDLR_ET_ImageContentElement	(FPDLR_ETMask_Content		| FPD_PAGEOBJ_IMAGE		)	/**< Image, graphics unit. */
#define FPDLR_ET_ShadingContentElement	(FPDLR_ETMask_Content		| FPD_PAGEOBJ_SHADING	)	/**< Shading, graphics unit. */
#define FPDLR_ET_AnnotContentElement	(FPDLR_ETMask_Content		| FPDPAGE_LR_ANNOT	)	/**< Annot*/	
#define FPDLR_ET_ComplexContentElement	(FPDLR_ETMask_Content		| FPDPAGE_LR_COMPLEX)	/**< Complex and displayable object */

#define FPDLR_ET_TextObject			(FPDLR_ETMask_PageObject	| FPD_PAGEOBJ_TEXT		)
#define FPDLR_ET_PathObject			(FPDLR_ETMask_PageObject	| FPD_PAGEOBJ_PATH		)
#define FPDLR_ET_ImageObject		(FPDLR_ETMask_PageObject	| FPD_PAGEOBJ_IMAGE		)
#define FPDLR_ET_ShadingObject		(FPDLR_ETMask_PageObject	| FPD_PAGEOBJ_SHADING	)
#define FPDLR_ET_FormObject			(FPDLR_ETMask_PageObject	| FPD_PAGEOBJ_FORM		)
#define FPDLR_ET_AnnotObject		(FPDLR_ETMask_PageObject	| FPDPAGE_LR_ANNOT	)
#define FPDLR_ET_ContainerObject	(FPDLR_ETMask_PageObject	| FPDPAGE_LR_CONTAINER)
#define FPDLR_ET_PageObject			(FPDLR_ETMask_PageObject	| FPDPAGE_LR_PAGE	)
#define FPDLR_ET_AnnotAppearanceObject (FPDLR_ETMask_PageObject   | FPDPAGE_LR_ANNOT_APPEARANCE)

#define FPDLR_IS_CONTENTTYPE(elemType)		(((FS_DWORD)(FPDLR_ETMask_Content)) == (elemType & ((FS_DWORD)(FPDLR_ETMaskSelector))))
#define FPDLR_IS_PAGEOBJTYPE(elemType)		(((FS_DWORD)(FPDLR_ETMask_PageObject)) == (elemType & ((FS_DWORD)(FPDLR_ETMaskSelector))))
#define FPDLR_IS_STRUCTURETYPE(elemType)	(((FS_DWORD)(FPDLR_ETMask_StructureCustom)) >= (elemType & ((FS_DWORD)(FPDLR_ETMaskSelector))))
#define FPDLR_GET_STDTYPE(elemType)		(elemType & (~((FS_DWORD)(FPDLR_ETMaskSelector))))


#ifndef FPD_LRPAGEOBJECTELEMENTREF
#define	FPD_LRPAGEOBJECTELEMENTREF
	typedef struct _t_FPD_LR_PageObjectElementRef* FPD_LR_PageObjectElementRef;
#endif
/* @OBJEND */

/* @OBJSTART FPD_LR_AnalysisOptions */
#ifndef FPD_LRANALYSISOPTIONS
#define	FPD_LRANALYSISOPTIONS
	typedef struct _t_FPD_LR_AnalysisOptions* FPD_LR_AnalysisOptions;
#endif
/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
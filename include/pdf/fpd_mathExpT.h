/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.

 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.

 ---------------------------------------------------------------------

fpd_mathExpT.h

 - Types, macros, structures, etc. required to use the FPDLayer HFT.

*********************************************************************/

#ifndef FPD_MATHEXPT_H
#define FPD_MATHEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* @OBJSTART FPD_LongImage */
#ifndef FPD_LONGIMAGE
#define	FPD_LONGIMAGE
/**
* @brief
*/
	typedef struct _t_FPD_LongImage* FPD_LongImage;
#endif

	enum FPD_ImageFormat
	{
		FPD_e_BMP,
		FPD_e_JEPG,
		FPD_e_JEPG2000,
		FPD_e_PNG,
		FPD_e_Tiff
	};

	enum FPD_ColorMode
	{
		FPD_e_RGB,
		FPD_e_Gray,
	};

	enum FPD_LongImageError
	{
		FPD_e_NoError,
		FPD_e_PageIsNull,
		FPD_e_PageNotParsed,
		FPD_e_DocIsNull,
		FPD_e_PageDictIsNull,
		FPD_e_ImageTooBig,
		FPD_e_ErrorPage,
		FPD_e_IllegalDPIValue,
		FPD_e_FileStreamIsNull,
		FPD_e_CodecModuleIsNull,
		FPD_e_EncoderIsNull,
		FPD_e_EncodeFailed,
		FPD_e_NoSupportedImageFormat,
		FPD_e_NoPageAdded
	};
/* @OBJEND */

/* @OBJSTART FPD_LongImageEncoder */
#ifndef FPD_LONGIMAGEENCODER
#define	FPD_LONGIMAGEENCODER
/**
* @brief
*/
	typedef struct _t_FPD_LongImageEncoder* FPD_LongImageEncoder;
#endif

	/* @CALLBACKGROUPSTART FPD_ValidatorCallbacks */
/** @brief A set of callbacks for Validator handler. */
	typedef struct _fpd_LongImageEncoder_callbacks_
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_LongImageEncoderCallbacksRec</a>) */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART FPDLongImageEncode */
		/**
		* @brief FPDLongImageEncode.
		* @param[in] clientData	The user-supplied data.
		* @param[in] pDIBSource	The image source.
		* @return void
		* @note
		*/		
		FS_BOOLEAN(*FPDLongImageEncode)(FS_LPVOID clientData, FS_DIBitmap pDIBSource);
		/* @CALLBACKEND */
		
	}FPD_LongImageEncoderCallbacksRec, *FPD_LongImageEncoderCallbacks;
	/* @CALLBACKGROUPEND */
/* @OBJEND */


/* @OBJSTART FPD_MathGraphics */
#ifndef FPD_MATHGRAPHICS
#define	FPD_MATHGRAPHICS
/**
* @brief
*/
	typedef struct _t_FPD_MathGraphics* FPD_MathGraphics;
#endif

/* @DEFGROUPSTART Fill mode */
/**
*/
/*@{*/
/** @brief Alternate. */
#define FPDFILL_ALTERNATE		1
/** @brief Winding. */
#define FPDFILL_WINDING			2
/**
 * @brief A special flag that can be applied to fill mode, indicating
 * all pixels partially covered by the path will be fully painted.
 */
#define FPDFILL_FULLCOVER		4
 /**
  * @brief A special flag that can be applied to fill mode, indicating
  * the rectangle won't be fully filled (like by default), instead, it will
  * be filled using standard anti-aliasing.
  */
#define FPDFILL_RECT_AA			8

  /** @brief When fill then stroke, we must use stroke
   * knockout output a path or a text path.
   */
#define FPD_FILL_STROKE			16

   /** @brief A flag specifying whether to apply automatic stroke adjustment. */
#define FPD_STROKE_ADJUST		32

/** @brief A flag specifying whether to apply text mode render.
 * We must not draw text object like a path when specified width is zero or small (draw a single-pixel wide line for path),
 * we'll not adjust the width.
 */
#define FPD_STROKE_TEXT_MODE		64

 /** @brief A flag specifying whether to draw text like a path.
  * We Don't draw a text object like a path that it makes a 0 area.
  */
#define FPD_FILL_TEXT_MODE		128

  /** @brief A flag specifying whether to draw a path with a 0 width. */
#define FPD_ZEROAREA_FILL		256

/** @brief A flag specifying whether to draw a path with smooth(anti-aliasing) process. */
#define FPDFILL_NOPATHSMOOTH		512

/** @brief A flag specifying whether the text knockout is true. */
#define FPD_TEXTKNOCKOUT			1024
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_MonoscaleBitmap */
#ifndef FPD_MONOSCALEBITMAP
#define	FPD_MONOSCALEBITMAP
/**
* @brief
*/
	typedef struct _t_FPD_MonoscaleBitmap* FPD_MonoscaleBitmap;
#endif
/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
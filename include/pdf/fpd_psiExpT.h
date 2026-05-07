/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.

 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.

 ---------------------------------------------------------------------

fpd_convertExpT.h

 - Types, macros, structures, etc. required to use the FPDLayer HFT.

*********************************************************************/

#ifndef FPD_PSIEXPT_H
#define FPD_PSIEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* @OBJSTART FPD_FXGInkPath */
#ifndef FPD_FXGINKPATH
#define	FPD_FXGINKPATH
/**
* @brief
*/
	typedef struct _t_FPD_FXGInkPath* FPD_FXGInkPath;
#endif


/* @DEFGROUPSTART ValidateRuleType */
/**
 /*@{*/
 /**
 * @brief Point flags used in FXG_INK_POINT. */
#define FPD_FXGPT_LINETO			0x02
#define FPD_FXGPT_MOVETO			0x04
#define FPD_FXGPT_ENDPATH			0x08
/*@}*/
/* @DEFGROUPEND */


/**@brief Structure of point struct used in IFXG_InkPath */
typedef struct __FPD_FXGINKPOINT__
{
	/**< The flag defined above, FPD_FXGPT_XXX. */
	FS_INT32 m_nFlag;
	/**< The x-coordinate of the point. */
	FS_FLOAT m_fPointX;	
	/**< The y-coordinate of the point. */
	FS_FLOAT m_fPointY;	
	/**< The pressure of the point, in range [0, 1]. */
	FS_FLOAT m_fPressure;	
	/**< The gradient of the point, reserved now. */
	FS_FLOAT m_fGradient;
	/**< The angle of the point, reserved now. */
	FS_FLOAT m_fAngle;		
}FPD_FXGINKPOINT, *PFPD_FXGINKPOINT;


 /*@{*/
/* @DEFGROUPSTART ValidateRuleType */
/**
* @brief Flags of PSI Vector.
*/
/*@{*/
#define FPD_PSI_TYPE_PATH	1	/**< Indicate the CFX_PathData as the PSI DATA. */
#define FPD_PSI_TYPE_DATA	2	/**< Indicate the FXG_PSI_DATA as the PSI DATA. */
/*@}*/
/* @DEFGROUPEND */
/* @OBJEND */

/* @OBJSTART FPD_FXGPaintModuleMgr */
#ifndef FPD_FXGPAINTMODULEMGR
#define	FPD_FXGPAINTMODULEMGR
/**
* @brief
*/
typedef struct _t_FPD_FXGPaintModuleMgr* FPD_FXGPaintModuleMgr;
#endif

/*@{*/
/*@{*/
/* @DEFGROUPSTART Paint Error Flags */
/**
* @brief Paint Error Flags.
*/
/*@{*/
#define FPD_FXGPAINT_ERROR_OK				0	/**< Success. */
#define FPD_FXGPAINT_ERROR_FATAL			-1	/**< Fatal error. */
#define FPD_FXGPAINT_ERROR_PARAMS			1	/**< User input parameter error. */
#define FPD_FXGPAINT_ERROR_READ			    2	/**< File read error */
#define FPD_FXGPAINT_ERROR_WRITE			3	/**< File write error */
#define FPD_FXGPAINT_ERROR_DATA			    4	/**< File data error. */
#define FPD_FXGPAINT_ERROR_MEM				5	/**< Not enough memory. */
#define	FPD_FXGPAINT_ERROR_TYPE			    6	/**< File type error. */
#define FPD_FXGPAINT_ERROR_FILE_VERSION	    7	/**< File version error. */
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART Flags of Nib cache limit. Default 10M. */ 
/**
* @brief Flags of Nib cache limit. Default 10M. 
*/
/*@{*/
#define FPD_FXGDEFAULT_CACHE_LIMIT		  10*1024*1024
/*@}*/
/* @DEFGROUPEND */

/*@{*/
/* @DEFGROUPSTART Paint Nib file types */
/**
* @brief Paint Nib file types.
*/
/*@{*/
#define FPD_FXGNIB_FILE_TYPE_FBR		1	/**< Reserved now */
#define FPD_FXGNIB_FILE_TYPE_ABR		2	/**< Reserved now */
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_FXGCanvas */
#ifndef FPD_FXGCANVAS
#define	FPD_FXGCANVAS
/**
* @brief
*/
typedef struct _t_FPD_FXGCanvas* FPD_FXGCanvas;
#endif
/* @OBJEND */

/* @OBJSTART FPD_FXGFilterNotifyHandler */
#ifndef FPD_FXGFILTERHANDLER
#define	FPD_FXGFILTERHANDLER
/**
* @brief
*/
typedef struct _t_FPD_FXGFilterNotifyHandler* FPD_FXGFilterNotifyHandler;
#endif

/* @CALLBACKGROUPSTART FPD_FXGFilterNotifyCallbacks */
/** @brief A set of callbacks for FilterNotify. */
typedef struct _fpd_FXGFilterNotify_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_ConverterCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FPDFlush */
	/**
	* @brief FPDFlush.
	* @param[in] clientData	The user-supplied data.
	* @param[in] rect   	The rect should be flush.
	* @return void
	* @note
	*/
	FS_BOOLEAN(*FPDFlush)(FS_LPVOID clientData, FS_Rect rect);
	/* @CALLBACKEND */
}FPD_FXGFilterNotifyCallbacksRec, *FPD_FXGFilterNotifyCallbacks;
/* @CALLBACKGROUPEND */

/*@{*/
/* @DEFGROUPSTART The color space supported now. */
/**
* @brief The color space supported now.
*/
/*@{*/
#define FPD_FXGCS_DeviceGray					1	/**< Indicate the color in device Gray. */
#define FPD_FXGCS_DeviceRGB					    2	/**< Indicate the color in device RGB. */
#define FPD_FXGCS_DeviceCMYK					3	/**< Indicate the color in device CMYK. */
/*@}*/
/* @DEFGROUPEND */


/**@brief Structure of point struct used in IFXG_InkPath */
typedef struct __FPD_FXGCOLOR__
{
	__FPD_FXGCOLOR__()
	{
		m_nCs = 2;
		a = 0;
		r = 0;
		g = 0;
		b = 0;
	}

	/**< Defined above, FPD_FXGCS_XXX. */
	FS_INT32 m_nCs;
	/**< The A value. */
	FS_FLOAT a;
	/**< The r value. */
	FS_FLOAT r;
	/**< The g value. */
	FS_FLOAT g;
	/**< The b value. */
	FS_FLOAT b;
}FPD_FXGCOLOR, *PFPD_FXGCOLOR;
/* @OBJEND */


/* @OBJSTART FPD_FXGPaint */
#ifndef FPD_FXGPAINT
#define	FPD_FXGPAINT
/**
* @brief
*/
typedef struct _t_FPD_FXGPaint* FPD_FXGPaint;
#endif

/* @DEFGROUPSTART Paint types */
/**
* @brief Paint types.
*/
/*@{*/
#define FPD_FXGPAINT_UNKNOWN			0
#define FPD_FXGPAINT_PENCIL			    1	/**< Reserved now */
#define FPD_FXGPAINT_PEN				2
#define FPD_FXGPAINT_ERASER			    3	/**< Reserved now */
#define FPD_FXGPAINT_BLUR				4	/**< Reserved now */
#define FPD_FXGPAINT_SHARPEN			5	/**< Reserved now */
#define FPD_FXGPAINT_MAX				6	/**< Not a valid paint type, just indicate the up-bound */
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART Path filters. */
/**
* @brief Specific path filter, most of them could be used together except that FXG_PATH_FILTER_DIB and FXG_PATH_FILTER_VECTOR are mutually exclusive.
*/
/*@{*/
#define FPD_FXGPATH_FILTER_SIMULATION	0	/**< If this filter turn on, the default sensitive filter will be repalced. */
#define FPD_FXGPATH_FILTER_DIB			1	/**< This filter is the default one. If this filter turn on, IFXG_Paint render dib real time. */
#define FPD_FXGPATH_FILTER_VECTOR		2	/**< Only this filter turn on, IFXG_Paint could render path real time.*/
#define FPD_FXGPATH_FILTER_PSI			3	/**< Only this filter turn on, IFXG_InkPath could genelate a vectored data. */
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART Filter type. */
/**
* @brief 
*/
/*@{*/
/** @brief Construct a ID from four integer values. */
#define FPDBSTR_ID(c1, c2, c3, c4) ((c1 << 24) | (c2 << 16) | (c3 << 8) | (c4))
#define FPD_FXGFILTERTYPE_PAINT			 FPDBSTR_ID(c1, c2, c3, c4) ((c1 << 24) | (c2 << 16) | (c3 << 8) | (c4))
/*@}*/
/* @DEFGROUPEND */


/* @DEFGROUPSTART Filter rendering status. */
/**
* @brief
*/
/*@{*/
#define FPD_FXGFILTER_RENDER_READY				1	/**< Indicate the filter is ready for render. */
#define FPD_FXGFILTER_RENDER_TOBECONTINUE		2	/**< Indicate the filter must be continue. */
#define FPD_FXGFILTER_RENDER_FINISH			3	/**< Indicate the filter has finished rendering. */
#define FPD_FXGFILTER_RENDER_ERROR_MEMORY		4	/**< Indicate the filter is out of memory. */
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_FXGPaintNib */
#ifndef FPD_FXGPAINTNIB
#define	FPD_FXGPAINTNIB
/**
* @brief
*/
typedef struct _t_FPD_FXGPaintNib* FPD_FXGPaintNib;
#endif

/*@{*/
/* @DEFGROUPSTART Paint Nib types supported. */
/**
* @brief Paint Nib types supported.
*/
/*@{*/
#define FPD_FXGNIB_ROUND				1
#define FPD_FXGNIB_BASIC				2	/**< Reserved now */
#define FPD_FXGNIB_MASK				    3	/**< Reserved now */
#define FPD_FXGNIB_SAMPLE				4	/**< Reserved now */
#define FPD_FXGNIB_CUSTOM				5
/*@}*/
/* @DEFGROUPEND */
/* @OBJEND */

/* @OBJSTART FPD_FXGNIB_PARAMS */
#ifndef FPD_FXGNIBPARAMS
#define	FPD_FXGNIBPARAMS
/**
* @brief
*/
typedef struct _t_FPD_FXGNIBParams* FPD_FXGNIBParams;
#endif
/* @OBJEND */

/* @OBJSTART FPD_FXGPaintRenderOption */
#ifndef FPD_FXGPAINTRENDEROPTION
#define	FPD_FXGPAINTRENDEROPTION
/**
* @brief
*/
typedef struct _t_FPD_FXGPaintRenderOption* FPD_FXGPaintRenderOption;
#endif

/*@{*/
/* @DEFGROUPSTART Paint Nib types supported. */
/**
* @brief Paint Nib types supported.
*/
/*@{*/
/**
 * @brief Selects the source color, ignoring the backdrop.\n
 * B(Cb, Cs) = Cs
 */
#define FPD_FXGBLEND_NORMAL						0	
/**
  * @brief Multiplies the backdrop and source color values.\n
  * B(Cb, Cs) = Cb * Cs
 */
#define FPD_FXGBLEND_MULTIPLY						1
 /**
  * @brief Multiplies the complements of the backdrop and source color values, then complements the result.\n
  * B(Cb, Cs) = 1 - [(1 - Cb) * (1 - Cs)] = Cb + Cs - Cb * Cs
*/
#define FPD_FXGBLEND_SCREEN						2
/**
 * @brief Multiplies or screens the colors, depending on the backdrop color value.\n
 * B(Cb, Cs) = HardLight(Cs, Cb)
 */
#define FPD_FXGBLEND_OVERLAY						3
/**
  * @brief Selects the darker of the backdrop and source colors.\n
  * B(Cb, Cs) = min(Cb, Cs)
*/
#define FPD_FXGBLEND_DARKEN						4
/**
 * @brief Selects the lighter of the backdrop and source colors.\n
 * B(Cb, Cs) = max(Cb, Cs)
 */
#define FPD_FXGBLEND_LIGHTEN						5
/**
   * @brief Brightens the backdrop color to reflect the source color. Painting with black produces no changes.\n
   * B(Cb, Cs) =
   * - min(1, Cb / (1 - Cs))		if Cs < 1
   * - 1							if Cs = 1
*/
#define FPD_FXGBLEND_COLORDODGE					6 
/**
 * @brief Darkens the backdrop color to reflect the source color. Painting with white produces no changes.\n
 * B(Cb, Cs) =
 * - 1 - min(1, (1 - Cb) / Cs)	if Cs > 0
 * - 0							if Cs = 0
 */
#define FPD_FXGBLEND_COLORBURN						7
/**
  * @brief Multiplies or screens the colors, depending on the source color value.\n
  * B(Cb, Cs) =
  * - Multiply(Cb, 2 * Cs)		if Cs <= 0.5
  * - Screen(Cb, 2 * Cs - 1)		if Cs > 0.5
*/
#define FPD_FXGBLEND_HARDLIGHT						8
/**
 * @brief Darkens or lightens the colors, depending on the source color value.\n
 * B(Cb, Cs) =
 * - Cb - (1 - 2 * Cs) * Cb * (1 - Cb)		if Cs <= 0.5
 * - Cb + (2 * Cs - 1) * (D(Cb) - Cb)		if Cs > 0.5 \n
 * where D(x) =
 * - ((16 * x - 12) * x + 4) * x			if x <= 0.25
 * - sqrt(x)								if x > 0.25
 */
#define FPD_FXGBLEND_SOFTLIGHT						9
/**
  * @brief Subtracts the darker of the two constituent colors from the lighter color.\n
  * B(Cb, Cs) = |Cb - Cs|
*/
#define FPD_FXGBLEND_DIFFERENCE					10
/**
 * @brief Produces an effect similar to that of the Difference mode but lower in contrast.\n
 * B(Cb, Cs) = Cb + Cs - 2 * Cb * Cs
*/
#define FPD_FXGBLEND_EXCLUSION						11
/*@}*/
/* @DEFGROUPEND */
/* @OBJEND */




#ifdef __cplusplus
};
#endif

#endif
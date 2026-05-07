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

#ifndef FPD_CONVERTEXPT_H
#define FPD_CONVERTEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* @OBJSTART FDF_Converter */
#ifndef FPD_CONVERTER
#define	FPD_CONVERTER
	/**
	* @brief 
	*/
	typedef struct _t_FPD_Converter* FPD_Converter;
#endif
/* @OBJEND */

/* @OBJSTART FDF_ConvertTaggedPDFHandler */
#ifndef FPD_CONVERTTAGGEDPDFHANDLER
#define	FPD_CONVERTTAGGEDPDFHANDLER
	/**
	* @brief
	*/
	typedef struct _t_FPD_ConvertTaggedPDFHandler* FPD_ConvertTaggedPDFHandler;
#endif

	enum FPDConvert_TaggedPDF_ReportCategory
	{
		FPDConvert_TaggedPDF_ReportCategory_Region,
		FPDConvert_TaggedPDF_ReportCategory_Artifact,
		FPDConvert_TaggedPDF_ReportCategory_Paragraph,
		FPDConvert_TaggedPDF_ReportCategory_ListItem,
		FPDConvert_TaggedPDF_ReportCategory_Figure,
		FPDConvert_TaggedPDF_ReportCategory_Table,
		FPDConvert_TaggedPDF_ReportCategory_TableRow,
		FPDConvert_TaggedPDF_ReportCategory_TableHeader,
		FPDConvert_TaggedPDF_ReportCategory_TocItem,
	};

	enum FPDConvert_TaggedPDF_ReportConfidence
	{
		FPDConvert_TaggedPDF_ReportConfidence_High,
		FPDConvert_TaggedPDF_ReportConfidence_MiddleHigh,
		FPDConvert_TaggedPDF_ReportConfidence_Middle,
		FPDConvert_TaggedPDF_ReportConfidence_MiddleLow,
		FPDConvert_TaggedPDF_ReportConfidence_Low,
	};


/* @CALLBACKGROUPSTART FPD_ConvertTaggedPDFCallbacks */
/** @brief A set of callbacks for convert tagged pdf handler. */
	typedef struct _fpd_convertTaggedPDF_callbacks_
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_ConvertTaggedPDFCallbacksRec</a>) */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART FPDReport */
		/**
		* @brief Report.
		* @param[in] clientData	The user-supplied data.
		* @param[in] eCategory		The report category.
		* @param[in] eConfidence	The report confidence.
		* @param[in] nCurPageIdx	The current page index.
		* @param[in] rcRect     	The rect range.
		* @return void
		* @note
		*/
		void(*FPDReport)(FS_LPVOID clientData, FPDConvert_TaggedPDF_ReportCategory eCategory, FPDConvert_TaggedPDF_ReportConfidence eConfidence, FS_INT32 nCurPageIdx, const FS_FloatRect rcRect);
		/* @CALLBACKEND */
	}FPD_ConvertTaggedPDFCallbacksRec, *FPD_ConvertTaggedPDFCallbacks;
/* @CALLBACKGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_ConverterOptions */
#ifndef FPD_CONVERTOPTIONS
#define	FPD_CONVERTOPTIONS
	/**
	* @brief
	*/
	typedef struct _t_FPD_ConverterOptions* FDF_ConverterOptions;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ConverterHandler */
#ifndef FPD_CONVERTHANDLER
#define	FPD_CONVERTHANDLER
	/**
	* @brief
	*/
	typedef struct _t_FPD_ConverterHandler* FPD_ConverterHandler;
#endif

/* @CALLBACKGROUPSTART FPD_ConverterCallbacks */
/** @brief A set of callbacks for converter handler. */
	typedef struct _fpd_converter_callbacks_
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_ConverterCallbacksRec</a>) */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART FPDNeedToPauseNow */
		/**
		* @brief FPDNeedToPauseNow.
		* @param[in] clientData	The user-supplied data.		
		* @return void
		* @note
		*/
		FS_BOOLEAN(*FPDNeedToPauseNow)(FS_LPVOID clientData);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FPDPreparePage */
		/**
		* @brief FPDPreparePage.
		* @param[in] clientData	The user-supplied data.
		* @param[in] nPageIdx	The page index.
		* @param[in] pPage	    The page object.		
		* @return void
		* @note
		*/
		FS_BOOLEAN(*FPDPreparePage)(FS_LPVOID clientData, FS_INT32 nPageIdx, FPD_Page pPage);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FPDUpdateProgress */
		/**
		* @brief FPDUpdateProgress.
		* @param[in] clientData    	    The user-supplied data.
		* @param[in] nConvertedCount	The convert count.
		* @return void
		* @note
		*/
		void(*FPDUpdateProgress)(FS_LPVOID clientData, FS_INT32 nConvertedCount);
		/* @CALLBACKEND */
	}FPD_ConverterCallbacksRec, *FPD_ConverterCallbacks;
/* @CALLBACKGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_FormRecognitionOption */
#ifndef FPD_FORMRECOGNITIONOPTION
#define	FPD_FORMRECOGNITIONOPTION
	/**
	* @brief
	*/
	typedef struct _t_FPD_FormRecognitionOption* FDF_FormRecognitionOption;
#endif

	/* @CALLBACKGROUPSTART FPD_FormRecognitionCallbacks */
	/** @brief A set of callbacks for form recognition. */
	typedef struct _fpd_converter_formrecognitioncallbacks_
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_ConverterCallbacksRec</a>) */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART FPDPreprocessFieldAndWidget */
		/**
		* @brief FPDPreprocessFieldAndWidget.
		* @param[in] clientData	    The user-supplied data.
		* @param[in] pWidgetDict	The widget dictionary.
		* @param[in] nPageIdx	    The page index.
		* @return FS_BOOLEAN
		* @note
		*/
		FS_BOOLEAN(*FPDPreprocessFieldAndWidget)(FS_LPVOID clientData, FPD_Object pWidgetDict, FS_INT32 nPageIdx);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FPDRegisterDefaultFont */
		/**
		* @brief FPDRegisterDefaultFont.
		* @param[in] clientData	The user-supplied data.
		* @param[in] outFont	Get the default font.
		* @return void
		* @note
		*/
		void(*FPDRegisterDefaultFont)(FS_LPVOID clientData, FS_ByteString* outFont);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FPDPreprocessFieldName */
		/**
		* @brief FPDPreprocessFieldName.
		* @param[in] clientData    	    The user-supplied data.
		* @param[out] wsFieldName	    The input field name.
		* @return void
		* @note
		*/
		void(*FPDPreprocessFieldName)(FS_LPVOID clientData, FS_WideString* wsFieldName);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FPDPreprocessFieldTooltip */
		/**
		* @brief FPDPreprocessFieldTooltip.
		* @param[in] clientData    	    The user-supplied data.
		* @param[out] wsFieldTooltip	    The input field tooltip.
		* @return void
		* @note
		*/
		void(*FPDPreprocessFieldTooltip)(FS_LPVOID clientData, FS_WideString* wsFieldTooltip);
		/* @CALLBACKEND */
	}FPD_FormRecognitionCallbacksRec, *FPD_FormRecognitionCallbacks;
	/* @CALLBACKGROUPEND */
/* @OBJEND */

/* @OBJSTART FPD_FormRecognitionHandler */
#ifndef FPD_FORMRECOGNITIONHANDLER
#define	FPD_FORMRECOGNITIONHANDLER
	/**
	* @brief
	*/
	typedef struct _t_FPD_FormRecognitionHandler* FDF_FormRecognitionHandler;
#endif	
	/* @OBJEND */


#ifdef __cplusplus
};
#endif

#endif
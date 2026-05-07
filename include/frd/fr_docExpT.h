/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.	

*********************************************************************/


/**
 * @defgroup FRLayer Foxit Reader Layer
 */

/*@{*/

/** @file fr_docExpT.h.
 * 
 *  @brief .
 */

/**
 * @addtogroup FRDOCUMENT
 * @{
 */

#ifndef FR_DOCEXPT_H
#define FR_DOCEXPT_H

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_VIEWEXPT_H
#include "../frd/fr_viewExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../pdf/fpd_docExpT.h"
#endif

//#include "../plugin_layer/sign/fr_SigExpT.h"

#ifdef __cplusplus
extern "C"{
#endif

///*  FR_Page */
//#ifndef FR_PAGE
//#define FR_PAGE
///**
// * @brief
// * see FPDPage
// */
// /** @deprecated Internal use. */
//typedef struct _t_FR_Page* FR_Page;
//#endif
///* FR_Page */


/* @OBJSTART FR_Document */
#ifndef FR_DOCUMENT
#define FR_DOCUMENT
/**
 * @brief A <a>FR_Document</a> is a view of a PDF document in a window.<br>
 *
 * Usually there is one <a>FR_Document</a> per displayed document, but some times(such as New Window), 
 * there may be two or more <a>FR_Document</a> per displayed document.
 * Unlike a <a>FPD_Document</a>, an <a>FR_Document</a> has a window associated with it. And a <a>FPD_Document</a> 
 * may have one or more associated <a>FR_Document</a>.<br>
 * 
 */
typedef struct _t_FR_Document* FR_Document;
#endif

/* @DEFGROUPSTART FRMenuEnableNames */
/**
 * @brief The macro definitions for the name of menu you want to enable. See <a>FRDocSetMenuEnableByName</a>.
 */
/*@{*/

/** @brief save as menu*/
#define FR_MENU_ENABLE_SAVEAS "SaveAs"

/** @brief email menu*/
#define FR_MENU_ENABLE_EMAIL "Email"

/** @brief snapshot menu*/
#define FR_MENU_ENABLE_SNAPSHOT "Snapshot"

/** @brief stamp menu*/
#define FR_MENU_ENABLE_STAMP "Stamp"
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FRDocTypes */
/**
 * @brief The macro definitions for the types of <a>FR_Document</a>. See <a>FRDocGetDocumentType</a>.
 */
/*@{*/

/** @brief The type is PDF.*/
#define FR_DOCTYPE_PDF				0

/** @brief The type dynimic xfa.*/
#define FR_DOCTYPE_DYNIMIC_XFA		1

/** @brief The type is static XFA.*/
#define FR_DOCTYPE_STATIC_XFA		2

/*@}*/
/* @DEFGROUPEND */

/* @ENUMSTART */
/** @brief The original type of the document. The real format of the opened document is PDF, but its wrapper format may be PPDF. See <a>FRDocGetOriginalType</a>.*/
enum FROriginalDocType
{
    FR_ORI_DOCTYPE_PDF = 0,			/**The original type of the document is PDF.*/
    FR_ORI_DOCTYPE_DYNAMIC_XFA = 1,	/**The original type of the document is dynamic XFA.*/
    FR_ORI_DOCTYPE_STATIC_XFA = 2,	/**The original type of the document is static PDF.*/
    FR_ORI_DOCTYPE_FDF = 3,			/**The original type of the document is FDF.*/
    FR_ORI_DOCTYPE_XDP = 4,			/**The original type of the document is XDP.*/
    FR_ORI_DOCTYPE_XFDF = 5,		/**The original type of the document is XFDF.*/
    FR_ORI_DOCTYPE_PPDF = 6			/**The original type of the document is PPDF. This type is currently available only for windows.*/
};
/* @ENUMEND */


/* @ENUMSTART */
/**
*@brief The source type of the document.
*/
/** @deprecated: Internal use. */
enum FRCreateDocSource
{
    FR_DOC_SOURCE_NORMAL = 0,				/**Normal.*/
    FR_DOC_SOURCE_BLANK = 1,				/**Blank.*/
    FR_DOC_SOURCE_FROM_FILE = 2,			/**From file.*/
    FR_DOC_SOURCE_FROM_MULTIPLE_FILES = 3,  /**From Multiple Files.*/
    FR_DOC_SOURCE_FROM_SCANNER = 4,		    /**From Scanner.*/
    FR_DOC_SOURCE_FROM_CLIPBOARD = 5,		/**From Clipboard.*/
    FR_DOC_SOURCE_PDF_PORTFOLIO = 6		    /**PDF Portfolio.*/
};
/* @ENUMEND */

/* @CALLBACKSTART FR_DocSaveAsProc */
/**
 * @brief Prototype of callback function invoked by <Italic>Foxit Reader</Italic> when performs <Italic>SaveAs</Italic>.
 * @param[in] frDoc The document to be saved as.
 * @param[in] pwszFilePath	The path where the document to be saved as.
 * @param[in] pProcData	The client data.
 * @return void
 * @note
 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRDocDoSave2
 */
typedef void (*FR_DocSaveAsProc)(FR_Document frDoc, FS_LPCWSTR pwszFilePath, void* pProcData);
/* @CALLBACKEND */

/* @CALLBACKSTART FR_DocSaveProc */
/**
 * @brief Prototype of callback function invoked by <Italic>Foxit Reader</Italic> when performs <Italic>Save</Italic>.
 * @param[in] frDoc The document to be saved as.
 * @param[in] pwszFilePath	The path where the document to be saved.
 * @param[in] pProcData	The client data.
 * @return void
 * @note
 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRDocDoSave
 */
typedef void (*FR_DocSaveProc)(FR_Document frDoc, FS_LPCWSTR pwszFilePath, void* pProcData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRInputPasswordProc */
/**
 * @brief Prototype of callback function invoked by <Italic>Foxit Reader</Italic> if you want to
 * set the document password through interface instead of the password input dialog.
 * @param[in] frDoc			The document.
 * @param[out] bsPassword	It receives the password.
 * @param[out] bReset		It indicates whether <Italic>Foxit Reader</Italic> need to reset the password if the password is incorrect.
 * @return <a>TRUE</a> if the plug-in takes over the procedure, otherwise not.
 * @note
 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.2
 * @see FRDocSetInputPasswordProc
 */
typedef FS_BOOL (*FRInputPasswordProc)(FR_Document frDoc, FS_ByteString bsPassword, FS_BOOL* bReset);
/* @CALLBACKEND */

/* @CALLBACKSTART FRPasswordEncryptProc */
/**
 * @brief Prototype of callback function invoked by <Italic>Foxit Reader</Italic> if you want to
 * set the document password through the password input dialog.
 * @param[in] frDoc			The document.
 * @param[in] nAction		<a>0</a> means user cancel protect.<a>0</a> cancel. <a>1</a> means will start protecting document and can be canceled by <a>bCancel</a>
 *							parameter. <a>2</a> means the document finished protecting. <a>3</a> check if show save popup waring.
 * @param[out] bCancel		When <a>nAction</a> return <a>1</a>, set <a>TRUE</a> to cancel the protection.
 * @param[out] pVariable	This is a reserved parameter.
 * @return void.
 * @note
 * @since <a>SDK_LATEEST_VERSION</a> > 9.1
 * @see FRDocSetInputPasswordProc
 */
typedef void (*FRPasswordEncryptProc)(FR_Document frDoc, FS_INT32 nAction, FS_BOOL *bCancel, void *pVariable);
/* @CALLBACKEND */

/* @CALLBACKSTART FRDocOleSaveProc */
/**
* @brief Prototype of callback function invoked by <Italic>Foxit Reader</Italic> if you want to
* set the ole proc to save the document.
* @param[in] pDoc			The document.
* @param[in] pPDFBuf	    The pdf buffer to be saved.
* @param[in] dwPDFLen		The file length.
* @param[in] pProcData	    The client data.
* @return <a>TRUE</a> if the plug-in takes over the procedure, otherwise not.
* @note
* @since <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
* @see FRDocOleSaveProc
* @deprecated: Internal use.
*/
typedef void(*FRDocOleSaveProc)(FR_Document pDoc, FS_BYTE*& pPDFBuf, FS_DWORD dwPDFLen, FS_LPVOID pProcData);
/* @CALLBACKEND */

/* @ENUMSTART */
/** @brief The target object of the permissions request.*/
enum  FRPermReqObj
{
	FRPermReqObjDoc = 1, /**The PDDoc whose permissions are being requested.*/
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief The target operation of the permissions request.*/
enum FRPermReqOpr
{
	FRPermReqOprCopy, /**The operation of copy permissions are being requested.*/
	FRPermReqOprExport /**The operation of export permissions are being requested.*/
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief The request status constant.*/
enum FRPermReqStatus
{
	FRPermReqDenied = -1, /**The Deny permisson of the operation.*/
	FRPermReqGranted = 0  /**The Grant permisson of the operation.*/
};
/* @ENUMEND */

/* @STRUCTSTART FR_WatemarkElementInfo*/
#ifndef FR_WATERMARKELEMENT_INFO
#define FR_WATERMARKELEMENT_INFO
/**
* @brief <a>FR_WatemarkElementInfo</a> The watermark data structure used pass to <a>FRDocAddWatermark</a>.
*
*/
typedef struct __FR_WatemarkElementInfo__
{
	__FR_WatemarkElementInfo__()
	{
		nType = 0;
		nPage = 0;
		fFontSize = 0.0f;
		crText = 0;
		nRotation = 0;
		fOpacity = 0.0f;
		fScale = 0.0f;
		bTop = FALSE;
		fVerticalDistance = 0.0f;
		nVerticalDistanceFrom = 0;
		fHorizontalDistance = 0.0f;
		nHorizontalDistanceFrom = 0;
		nStart = 0;
		nEnd = 0;
		bEven = true;
		bOdd = true;
		bOnScreen = TRUE;
		bOnPrint = TRUE;
		bFixedPrint = FALSE;
		bPercentage = FALSE;
		bPontUnit = FALSE;

		lpwStrPathName = NULL;
		lpwStrText = NULL;
		lpwStrFontName = L"Helvetica";
		lpbSpecifyWatermarkDicValue = NULL;
	}

	/** 0-Text, 1-File */
	int nType;
	/** Image or pdf absolute path, valid when nType is 1.*/
	FS_LPCWSTR lpwStrPathName;
	/** The pages will use for setting watermark.(0~nPageCount). */
	FS_INT32 nPage;
	/** The watermark text, valid when nType is 0. */
	FS_LPCWSTR lpwStrText;
	/** The font name of watermark text. */
	FS_LPCWSTR lpwStrFontName;
	/** The font size of watermark text. */
	FS_FLOAT fFontSize;
	/** The color of watermark text. */
	FS_COLORREF crText;
	/** The watermak text range (0~360) */
	FS_INT32 nRotation;
    /** Required, must to be set, range (0~1, Percentage) */
	FS_FLOAT fOpacity;
    /** Scale relative to target page, （0-1, Percentage）. */
	FS_FLOAT fScale;
	/** FALSE-Appear behind page , TRUE-Appear on top of page. */
	FS_BOOL bTop;
	/** The distance of vertical , default unit is Inches.  */
	FS_FLOAT fVerticalDistance;
	/**  Top 0, Center 1 , Bottom 2.  */
	FS_INT32 nVerticalDistanceFrom;
	/** The distance of horizontal, default unit is Inches.  */
	FS_FLOAT fHorizontalDistance;
	/** Left 0, Center 1 , Right 2.  */
	FS_INT32 nHorizontalDistanceFrom;
	/** Required:  start from 0.*/
	FS_INT32 nStart;
	/** Required:  specify end of page.*/
	FS_INT32 nEnd;
	/** If only even pages, bOdd need set false.*/
	FS_BOOL bEven;
	/** If only odd pages, bEven need set false.*/
	FS_BOOL bOdd;
	/** If show on screen.*/
	FS_BOOL bOnScreen;
	/** If show when print.*/
	FS_BOOL bOnPrint;
	/** If as annot object to add.*/
	FS_BOOL bFixedPrint;
	/** The percertage of the page.*/
	FS_BOOL bPercentage;
	/** If use points as unit.*/
	FS_BOOL bPontUnit;
	/** If is empty, that's not AIP Label.*/
	FS_LPCSTR lpbSpecifyWatermarkDicValue;
}FR_WatemarkElementInfo, *FR_PWatemarkElementInfo;
#endif
/* @STRUCTEND */

/* @STRUCTSTART FR_MERGRINFO*/
#ifndef FR_MERGR_INFO
#define FR_MERGR_INFO
/**
* @brief merge file info.
*
*/
typedef struct __FR_MERGRINFO__
{
	FS_LPCWSTR cwFileName;
	FS_LPCWSTR cwPassWord;
}FR_MERGRINFO;
#endif
/* @STRUCTEND */

/* @STRUCTSTART FR_HeaderFooterElementInfo*/
#ifndef FR_HEADERFOOTERELEMENT_INFO
#define FR_HEADERFOOTERELEMENT_INFO
/**
* @brief <a>FR_HeaderFooterElementInfo</a> The header and footer data structure used pass to <a>FRDocAddHeaderFooter</a>.
*
*/
typedef struct __FR_HeaderFooterElementInfo__
{
	__FR_HeaderFooterElementInfo__()
	{
		fFontSize = 9.0f;
		bUnderLine = FALSE;
		bEmbed = FALSE;
		lpwStrFontName = L"Helvetica";
		clrText = RGB(0, 0, 0);
		ftop = 0.5f;
		fleft = 1.0f;
		fbottom = 0.5f;
		fright = 1.0f;
		bshrink = FALSE;
		bfixedprint = FALSE;
		nStart = 0;
		nEnd = 0;
		bEven = TRUE;
		bOdd = TRUE;
		lpbSpecifyHeaderFooterDicValue = NULL;
		lpwsHeaderLeft = NULL;
		lpwsHeaderRight = NULL;
		lpwsHeaderCenter = NULL;

		lpwsFooterLeft = NULL;
		lpwsFooterRight = NULL;
		lpwsFooterCenter = NULL;
	}

	/** The font size of the HF.*/
	FS_FLOAT fFontSize;
	/** If show underline of the HF.*/
	FS_BOOL  bUnderLine;
	/** If the embed font of the HF.*/
	FS_BOOL  bEmbed;
	/** The font name of the HF.*/
	FS_LPCWSTR lpwStrFontName;
	/** The text color of the HF.*/
	FS_COLORREF clrText;
	/** The margin of top, default unit is inch.*/
	FS_FLOAT ftop;
	/** The margin of left, default unit is inch.*/
	FS_FLOAT fleft;
	/** The margin of bottom, default unit is inch.*/
	FS_FLOAT fbottom;
	/** The margin of right, default unit is inch.*/
	FS_FLOAT fright;
	/** If need shrik the HF to avoid overwrite text and graphics.*/
	FS_BOOL bshrink;
	/** If as annot object to add.*/
	FS_BOOL bfixedprint;
	/** The left header text.*/
	FS_LPCWSTR lpwsHeaderLeft;
	/** The right header text.*/
	FS_LPCWSTR lpwsHeaderRight;
	/** The center header text.*/
	FS_LPCWSTR lpwsHeaderCenter;
	/** The left footer text.*/
	FS_LPCWSTR lpwsFooterLeft;
	/** The right footer text.*/
	FS_LPCWSTR lpwsFooterRight;
	/** The center footer text.*/
	FS_LPCWSTR lpwsFooterCenter;
	/** Required: The start page.*/
	FS_INT32 nStart;
	/** Required: The end page.*/
	FS_INT32 nEnd;
	/** If only even pages, bOdd need set false.*/
	FS_BOOL bEven;
	/** If only odd pages, bEven need set false.*/
	FS_BOOL bOdd;
	/** If is empty, that's not AIP Label.*/
	FS_LPCSTR lpbSpecifyHeaderFooterDicValue;
}FR_HeaderFooterElementInfo, *FR_PHeaderFooterElementInfo;
#endif
/* @STRUCTEND */

/* @CALLBACKGROUPSTART FPD_FormNotifyCallbacks */
/** @brief A set of callbacks for PDF form notify handler. */
typedef struct _frd_formdesignnotify_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART OnTabOrderChanged */
	/**
	* @brief			A callback when set tab order in right menu of right click form or in fields panel.
	*
	* It is called when tab order changed.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] pPage		The <a>FR_Page</a> contains widget.
	* @note
	*/
	void(*OnTabOrderChanged)(FS_LPVOID clientData, FR_Page pPage);
	/* @CALLBACKEND */

	/* @CALLBACKSTART OnWidgetChanged */
	/**
	* @brief			A callback when widget form property changed.
	*
	* It is called when widget changed.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] pAnnot		The <a>FR_Annot</a> changed.
	* @note
	*/
	void(*OnWidgetChanged)(FS_LPVOID clientData, FR_Annot pAnnot);
	/* @CALLBACKEND */

	/* @CALLBACKSTART OnSetAsDefaultSetting */
	/**
	* @brief			A callback when set "use current properties as new defaults" in fields panel.
	*
	* It is called when set as default setting.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] pPageView	The current <a>FR_PageView</a>.
	* @note
	*/
	void(*OnSetAsDefaultSetting)(FS_LPVOID clientData, FR_PageView pPageView);
	/* @CALLBACKEND */

	/* @CALLBACKSTART OnMltiplyCopies */
	/**
	* @brief			A callback when "create multiple copies" of FIELDTYPE_SIGNATURE type.
	*
	* It is called when copy multiple.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] pPageView	The current <a>FR_PageView</a>.
	* @note
	*/
	void(*OnMltiplyCopies)(FS_LPVOID clientData, FR_PageView pPageView);
	/* @CALLBACKEND */

	/* @CALLBACKSTART OnAddWidgetFinish */
	/**
	* @brief			A callback when add widget finish.
	*
	* It is called when add widget finish.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] pAnnot  	The widget has been added.
	* @note
	*/
	void(*OnAddWidgetFinish)(FS_LPVOID clientData, FR_Annot pAnnot);
	/* @CALLBACKEND */
}FRD_FormDesignNotifyCallbacksRec, *FRD_FormDesignNotifyCallbacks;
/* @CALLBACKGROUPEND */


/* @ENUMSTART */
/** @brief The type of tab order.*/
enum FR_TabOrder
{
	FRMixOrOthers = -1,
	FRUnspecified,
	FRRowOrder,
	FRColumnOrder,
	FRStructureOrder,
	FRManually
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief The result of send mail.*/
enum FR_MailtoResult
{
	FRMailtoFailed = 0,
	FRMailtoSuccess = 1,
	FRMailtoUserAbort = 2,
};
/* @ENUMEND */

/* @STRUCTSTART FR_PAGESTATE*/
#ifndef FR_PAGESTATE_INFO
#define FR_PAGESTATE_INFO
/**
* @brief <a>FR_PAGESTATE</a> The information of page state.
*
*/
typedef struct __FR_PAGESTATE__
{
	__FR_PAGESTATE__()
	{
		nFitType = 0;
		cwNamedDes = NULL;
		dest = NULL;
	}

	/**The Zoom mode for PDF destination, Like FPD_ZOOM_XYZ.*/
	FS_INT32 nFitType;
	/**The left、top、bottom、right of the page state.You need to use FSFloatArrayNew to instantiat object.*/
	FS_FloatArray dest;
	/**The names of the destination.It is not be used now, just be sync with the PAGESTATE of framework.*/
	FS_WideString cwNamedDes;
}FR_PAGESTATE;
#endif
/* @STRUCTEND */


/* @STRUCTSTART FR_SaveDocOption*/
#ifndef FR_SAVEDOCOPTION
#define FR_SAVEDOCOPTION
/**
* @brief <a>FR_SaveDocOption</a> The information of page state.
*
*/
typedef struct __FR_SaveDocOption__
{
	__FR_SaveDocOption__()
	{
		bSaveAsTempFile = FALSE;
		bShowProgressBar = FALSE;
		bDocPDFOptimizer = FALSE;
		bPromptInfo = FALSE;
	}
	/**Sets it FALSE as default.*/
	FS_BOOL bSaveAsTempFile;
	/**Whether to show the progress bar or not.*/
	FS_BOOL bShowProgressBar;
	/**Sets true means need to optimize.*/
	FS_BOOL bDocPDFOptimizer;
	/**Whether to show prompt info or not.*/
	FS_BOOL bPromptInfo;
}FR_SaveDocOption;
#endif
/* @STRUCTEND */

/* @STRUCTSTART FR_OpenFileOption*/
#ifndef FR_OPENFILEOPTION
#define FR_OPENFILEOPTION
/**
* @brief <a>FR_OpenFileOption</a> The option when open file.
*
*/
typedef struct __FR_OpenFileOption__
{
	__FR_OpenFileOption__()
	{
		bLocalFile = TRUE;
		bNoOriginalFile = TRUE;
		bAttachment = FALSE;
		bMakeVisible = TRUE;
		csPassword = L"";
		bAddToMRU = TRUE;
		bShowCertPassDlg = TRUE;
		bCanReOpenAlready = FALSE;
		offset = 0;
		size = 0;
		bIgnoreInvisible = FALSE;
	}
	/**Set FALSE is not local file.*/
	FS_BOOL bLocalFile;
	/**Set FALSE is original file.*/
	FS_BOOL bNoOriginalFile;
	/**Set TRUE is attachment file.*/
	FS_BOOL bAttachment;
	/**Set TRUE the document will be made visible.*/
	FS_BOOL bMakeVisible;
	/**Set password of the password.*/
	FS_LPCWSTR csPassword;
	/**Set TRUE will add to Recently opened records.*/
    FS_BOOL bAddToMRU;
	/**Set TRUE will show cert password dialog.*/
    FS_BOOL bShowCertPassDlg;
	/**Set TRUE will can be reopen.*/
    FS_BOOL bCanReOpenAlready;
	/**Ignore.*/
	FS_INT64 offset;
	/**Ignore.*/
	FS_INT64 size;
	/**Ignore.*/
	FS_BOOL bIgnoreInvisible;
}FR_OpenFileOption;
#endif
/* @STRUCTEND */

/* @ENUMSTART */
/** @brief The style of pagelable.*/
enum FR_PageLabelStyle
{
	FRPageLabelNone = -1,
	FRPageLabelNum,
	FRPageLabelCapRomanNum,
	FRPageLabelLowerRomanNum,
	FRPageLabelCapLetter,
	FRPageLabelLowerLetter
};
/* @ENUMEND */


/* @STRUCTSTART FR_PageLabelOption*/
#ifndef FR_PAGELABELOPTION
#define FR_PAGELABELOPTION
/**
* @brief <a>FR_PageLabelOption</a> The option when set page label.
* */
typedef struct __FR_PageLabelOption__
{
	__FR_PageLabelOption__()
	{
		lStructSize = 0;
		nFrom = -1;
		nTo = -1;
		nStyle = FRPageLabelNone;
		wsPrefix = L"";
		nStart = 1;
	}

	/** The size of data structure. */
	unsigned long lStructSize;
	/**Set the start page that requires pagelabel. 0: first page.*/
	FS_INT32 nFrom;
	/**Set the end page that requires pagelabel.*/
	FS_INT32 nTo;
	/**Set the style of page label.*/
	FR_PageLabelStyle nStyle;
	/**Set the prefix.*/
	FS_LPCWSTR wsPrefix;
	/**Set the start value of the current style. 
	For instance, if the FRPageLabelCapLetter style is set and nStart is set to 2, then the page label of the first page will be "prefix + B".*/
	FS_INT32 nStart;
}FR_PageLabelOption;
#endif
/* @STRUCTEND */

/* @ENUMSTART */
/** @brief The ocr language.*/
enum FR_OCRLanguage
{
	FR_OCRLanEnglish = 0,
	FR_OCRLanFrench,
	FR_OCRLanGerman,
	FR_OCRLanItalian,
	FR_OCRLanSpanish,
	FR_OCRLanChinesePRC,
	FR_OCRLanChineseTaiwan,
	FR_OCRLanJapanese,
	FR_OCRLanKorean,
	FR_OCRLanDutch,
	FR_OCRLanPolish,
	FR_OCRLanPortugueseStandard,
	FR_OCRLanRussian,
	FR_OCRLanTurkish,
	FR_OCRLanLithuanian,
	FR_OCRLanLatvian,
	FR_OCRLanEstonian,
	FR_OCRLanFinnish,
	FR_OCRLanThai,
	FR_OCRLanNorwegian,
	FR_OCRLanIcelandic,
	FR_OCRLanSwedish,
	FR_OCRLanRomanian,
	FR_OCRLanSlovak,
	FR_OCRLanCzech,
	FR_OCRLanHungarian,
	FR_OCRLanArabic,
	FR_OCRLanHebrew,
	FR_OCRLanFaeroese,
	FR_OCRLanDanish,
	FR_OCRLanGreek,
	FR_OCRLanBasque,
	FR_OCRLanBulgarian,
	FR_OCRLanCatalan,
	FR_OCRLanCroatian,
	FR_OCRLanGalician,
	FR_OCRLanMacedonian,
	FR_OCRLanMaltese,
	FR_OCRLanSerbianLatin,
	FR_OCRLanSlovenian,
	FR_OCRLanUkrainian,
	FR_OCRLanIndonesian,
	FR_OCRLanVietnamesen
};
/* @ENUMEND */


/* @STRUCTSTART FR_OCRSettingInfo*/
#ifndef FR_OCRSETTINGINFO
#define FR_OCRSETTINGINFO
/**
* @brief <a>FR_OCRSettingInfo</a> Set the configuration before OCR execution.
* */
typedef struct __FR_OCRSettingInfo__
{
	__FR_OCRSettingInfo__()
	{
		lStructSize = 0;
		m_bSearchable = true;
		nLans = NULL;
	}

	/** The size of data structure. */
	unsigned long lStructSize;
	/**Set the support ocr language array, set values like FR_OCRLanguage::FR_OCRLanEnglish,FR_OCRLanguage::FR_OCRLanFrench. */
	FS_Int32Array nLans;
	/**Set if searchable mode.true:text can be searched and selected but can not be edited,false:text can be edited. */
	FS_BOOLEAN m_bSearchable;
}FR_OCRSettingInfo;
#endif
/* @STRUCTEND */

/* @OBJEND */


/* @COMMONSTART */

/* @DEFGROUPSTART FRSIGShowAPFlags */
/**

/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FRSIGVarifySignatureStates */
/**
 * @brief The state for verifying signature.
 */
/*@{*/
/** @brief	Unsigned signature. */
#define FR_SIG_STATE_UNSIGNED				0x00000001
/** @brief	Signed signature. */
#define FR_SIG_STATE_SIGNED					0x00000002

/** @brief The signature state is valid. */
#define FR_SIG_VERIFY_VALID					0x00000004
/** @brief The signature state is invalid. */
#define FR_SIG_VERIFY_INVALID				0x00000008
/** @brief The signature data is corrupted and can not be parsed successfully. */
#define FR_SIG_VERIFY_ERRORDATA				0x00000010
/** @brief The signature type is not supported. */
#define FR_SIG_VERIFY_NOSUPPORTWAY			0x00000020
/** @brief The signature data bytes is not in the expected range. */
#define FR_SIG_VERIFY_ERRORBYTERANGE		0x00000040
/** @brief The document is changed beyond the limits. */
#define FR_SIG_VERIFY_CHANGE				0x00000080
/** @brief The signature is not trusted. */
#define FR_SIG_VERIFY_INCREDIBLE			0x00000100
/** @brief Signature SMID length is not equal to 16. */
#define FR_SIG_VERIFY_SMIDINVALID			0x00000200
/** @brief The document has no changed within the scope of the signature. */
#define FR_SIG_VERIFY_NONECHANGE            0x00000400

/** @brief Verify the issuer is not verify. */
#define FR_SIG_VERIFY_ISSUER_NOVERIFY       0x00000800
/** @brief The issuer is valid. */
#define FR_SIG_VERIFY_ISSUER_VALID			0x00001000
/** @brief The issuer is  unknown. */
#define FR_SIG_VERIFY_ISSUER_UNKNOW			0x00002000
/** @brief The certificate is revoked. */
#define FR_SIG_VERIFY_ISSUER_REVOKE			0x00004000
/** @brief The certificate is expired. */
#define FR_SIG_VERIFY_ISSUER_EXPIRE			0x00008000
/** @brief The issuer is unchecked. */
#define FR_SIG_VERIFY_ISSUER_UNCHECK		0x00010000
/** @brief The issuer is the current issuer. */
#define FR_SIG_VERIFY_ISSUER_CURRENT		0x00020000

/** @brief No timestamp. */
#define FR_SIG_TIMESTAMP_NONE				0x00040000
/** @brief It is the type of document timestamp. */
#define FR_SIG_TIMESTAMP_DOC				0x00080000
/** @brief The time stamp is valid. */
#define FR_SIG_TIMESTAMP_VALID				0x00100000
/** @brief The time stamp is invalid. */
#define FR_SIG_TIMESTAMP_INVALID			0x00200000
/** @brief The time stamp is expired. */
#define FR_SIG_TIMESTAMP_EXPIRE				0x00400000
/** @brief The issuer of the time stamp is unknown. */
#define FR_SIG_TIMESTAMP_ISSUER_ISUNKNOWN	0x00800000
/** @brief The issuer of the time stamp is valid. */
#define FR_SIG_TIMESTAMP_ISSUER_ISVALID		0x01000000
/** @brief Verify the timestamp time is valid. */
#define FR_SIG_TIMESTAMP_TIMEBEFORE		    0x02000000
/** @brief Can't get Verify relevant information. */
#define FR_SIG_STATE_CERT_CANNOT_GET_VRI	0x04000000
/** @brief The document has been changed outside of signature scope, but the changed is permitted. */
#define FR_SIG_VERIFY_CHANGE_LEGAL		    0x08000000
/** @brief The document has been changed outside of signature scope, and the changed invalidate the signature. */
#define FR_SIG_VERIFY_CHANGE_ILLEGAL		0x10000000
/** @brief	Unknown signature. */
#define FR_SIG_STATE_UNKNOWN				0x80000000

/** @briefVerify the issuer is invalid. */
#define FR_SIG_VERIFY_ISSUER_INVALID        0x20000000
/** @brief Verify the issuer is onesigner. */
#define FR_SIG_VERIFY_ISSUER_ONESIGNER      0x40000000

/*The following subdivides the state, directly using the number representation*/
#define FR_SIG_STATE_SUB_NONE               0x00000000

/** @brief The segmentation algorithm under CPDF_SIGNATURE_STATE_VERIFY_NOSUPPORTWAY is not
 * supported  */
#define FR_SIG_STATE_SUB_ALG_NOSUPPORTWAY    0x00000001

 /** @brief Policy restrictions cannot be used for PDF signatures*/
#define FR_SIG_STATE_SUB_POLICYRESTRICTIONSNOPDFSIG    0x00000002
/*@}*/
/* @DEFGROUPEND */


/* @ENUMSTART */
/** 
  * @brief The handle of the result.
  */
/** @deprecated: Internal use. */

/* @ENUMEND */

/* @STRUCTSTART FR_SignatureDictInfo*/

/* @STRUCTEND */

/* @ENUMSTART */
/** 
  * @brief The icon type of showing graphic on signature appearance.
  */

/* @ENUMEND */

/* @ENUMSTART */
/** 
  * @brief The text direction on signature appearance.
  */

/* @ENUMEND */

/* @ENUMSTART */
/** 
  * @brief The definition for signature permission.
  */


/* @STRUCTSTART FR_MSGBOX_ATTRIBUTE*/
/**
* @brief messbox info when convert fail.
*
*/
typedef struct __FR_MSGBOX_ATTRIBUTE__
{
	__FR_MSGBOX_ATTRIBUTE__()
	{
		bShow = TRUE;
		nMsgType = FR_MsgBtnType::FR_MBOK;
		wsPrompt = L"";
		nSetIgnoreErrorType = nullptr;
	}

	/** Whether display messagebox when convert error. */
	FS_BOOL			bShow;
	/** Messagebox type. */
	FS_UINT	        nMsgType;
	/** Prompt message. If null, the default message will be displayed. */
	FS_LPCWSTR      wsPrompt;
	/** If the return value is in errorType with you set, no error msg will be display. */
	FS_Int32Array   nSetIgnoreErrorType;
}FR_MSGBOX_ATTRIBUTE, *FR_PMSGBOX_ATTRIBUTE;
/* @STRUCTEND*/

/* @ENUMSTART */
/**
* @brief The support file type to convert to pdf.
*/
enum FR_SUPPORT_FILE_TYPE
{
	FR_UnknownFileType = 0,
	FR_MS_WordFile,
	FR_MS_PorwerPointFile,
	FR_MS_ExcelFile,
	FR_MS_ProjectFile,
	FR_MS_VisioFile,
	FR_MS_OutLook,
	FR_KS_WordFile,
	FR_KS_PowerPointFile,
	FR_KS_ExcelFile,
	FR_TextFile,
	FR_ImageFile,
	FR_HtmlFile,
	FR_PdfFile,
	FR_HCOM_HWP,
	FR_XpsFile,
};
/* @ENUMEND */

/* @STRUCTSTART FR_SrcFileInfo*/
/**
* @brief source file info.
*
*/
typedef struct __FR_SRCFILEINFO__
{
	/** Source file type. */
	FR_SUPPORT_FILE_TYPE fileType;
	/** Password of source file. */
	FS_LPCWSTR wcPassword;
}FR_SrcFileInfo, *FR_PSrcFileInfo;
/* @STRUCTEND*/

/* @STRUCTSTART FR_DocProPerty*/
/**
* @brief Set the doc property.
*
*/
typedef struct __FR_DOCPROPERTY_
{
	FS_LPCWSTR wcComments;
	FS_LPCWSTR wcCompany;
	FS_LPCWSTR wcCagegory;
	FS_LPCWSTR wcManager;
}FR_DocProPerty, *FR_PDocProPerty;
/* @STRUCTEND*/

/* @STRUCTSTART FR_PDFDocInfo*/
/**
* @brief Set the convert pdf info.
*
*/
typedef struct __FR_PDFDOCINFO__
{
	FS_LPCWSTR wcTitle;
	FS_LPCWSTR wcSubject;
	FS_LPCWSTR wcAuthor;
	FS_LPCWSTR wcKeyWords;
	FS_LPCWSTR wcCreator;
	FS_LPCWSTR wcProducer;
	FS_BOOL bPDFA_1b;
	FR_DocProPerty docProperties;
}FR_PDFDocInfo, *FR_PPDFDocInfo;
/* @STRUCTEND*/

/* @STRUCTSTART FR_DocumentInfo*/
/**
* @brief Set the convert pdf info, default is null.
*
*/
typedef struct __FR_DOCUMENTINFO__
{
	FR_SrcFileInfo  srcFileInfo;
	FR_PDFDocInfo   pdfDocInfo;
	FS_LPCWSTR      wsUserID;
	FS_LPCWSTR      wcUserToken;
	FS_LPCWSTR      wcSrcFilePath;
	FS_LPCWSTR      wcPDFFilePath;
	FS_LPCWSTR      wsPluginDataPath;
	FS_LPCWSTR      wsLanguageShortName;
	FS_BOOL         bIsAppend;
	FS_BOOL         bIsFolder;
	FS_INT64        nConvertSetting;
}FR_DocumentInfo, *FR_PDocumentInfo;
/* @STRUCTEND*/

/* @ENUMSTART */
/**
  * @brief The type of tagpanel.
  */
enum FR_TagPDF_PanelType
{
	FRTagPDF_TagsPanel = 1,
	FRTagPDF_OrderPanel,
	FRTagPDF_ContentPanel
};
/* @ENUMEND */
/* @COMMONEND */


/* @OBJSTART FR_ReaderInterform */
#ifndef FR_READERINTERFROMA
#define FR_READERINTERFROMA
/**
 * @brief A <a>FR_ReaderInterform</a> is an object for widget operation in App. You can call FRReaderInterformGetInterForm
 * API to get FPD_InterForm to change the widget, and it not require to reset appearance.
 *
 */
typedef struct _t_FR_ReaderInterform* FR_ReaderInterform;
#endif
/* @OBJEND */

/*  FR_UndoCreateWidget */
#ifndef FR_UNDOCREATEWIDGET
#define FR_UNDOCREATEWIDGET
/**
 * @brief A <a>FR_UndoCreateWidget</a> is an object for undo after create widget.
 * @deprecated: Internal use.
 */
typedef struct _t_FR_UndoCreateWidget* FR_UndoCreateWidget;
#endif
/* FR_UndoCreateWidget */

/*  FR_CRSAStamp */
#ifndef FR_CRSASTAMP
#define FR_CRSASTAMP
/**
 * @brief A <a>FR_CRSAStamp</a> is an object for Stamp.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_CRSAStamp* FR_CRSAStamp;
#endif

/* @ENUMSTART */
/**
  * @brief The definition for page piece info.
  */
/** @deprecated: Internal use. */
enum FR_PIECE_INFO_KEY
{
	FR_PI_FAVORITE,
	FR_PI_DEFAULT_WH,
	FR_PI_APP_CLOST_DEL,
	FR_PI_SIGN_IDX,
	FR_PI_DEFAULT_CROP_WH
};
/* @ENUMEND */

/* @ENUMSTART */
/**
  * @brief The definition for permission type.
  */
/** @deprecated: Internal use. */
enum FRRS_PASSWORD
{
	FRRS_NOPERMISSION = 0,
	FRRS_PASSWORDBLANK,
	FRRS_HASPERMISSION
};
/* @ENUMEND */

/* @ENUMSTART */
/**
  * @brief The EnhancementAlogrithms type.
  */
/** @Deprecated: Internal use. */
enum FREnhancementAlogrithms
{
	FR_GRAY_LEVEL_TRANS = 0,
};
/* @ENUMEND */

/* @ENUMSTART */
/**
  * @brief The ThreshAlogrithm type.
  */
/** @deprecated: Internal use. */
enum FRThreshAlogrithm
{
	FR_FIXED_THRESH = 0,
	FR_OTSU,
	//Adding New Items Here for Extension
	//END_THRESH_CALC_ALGO,	
};
/* @ENUMEND */
/* FR_CRSAStamp */


/*  FR_MarkupAnnot */
#ifndef FR_MARKUPANNOT
#define FR_MARKUPANNOT
/**
 * @brief A <a>FR_MarkupAnnot</a> is an object for markup annot.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_MarkupAnnot* FR_MarkupAnnot;
#endif
/*FR_MarkupAnnot */


/*  FR_MarkupAnnot */
#ifndef FR_MARKUPPOPUP
#define FR_MARKUPPOPUP
/**
 * @brief A <a>FR_MarkupPopup</a> is an object for markup popup annot.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_MarkupPopup* FR_MarkupPopup;
#endif
/* FR_MarkupAnnot */


/* @OBJSTART FR_MarkupPanel */
#ifndef FR_MARKUPPANEL
#define FR_MARKUPPANEL
/**
 * @brief A <a>FR_MarkupPanel</a> is an object for comments panel.
 */
typedef struct _t_FR_MarkupPanel* FR_MarkupPanel;
#endif
/* @OBJEND */

/*  FR_CRSASStampAnnot */
#ifndef FR_CRSASTAMPANNOT
#define FR_CRSASTAMPANNOT
/**
 * @brief A <a>FR_CRSASStampAnnot</a> is an object for Stamp annot.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_CRSASStampAnnot* FR_CRSASStampAnnot;
#endif
/* FR_CRSASStampAnnot */


/* FR_EncryptPermisson */
#ifndef FR_ENCRYPTPERMISSION
#define FR_ENCRYPTPERMISSION
/**
 * @brief A <a>FR_EncryptPermisson</a> is to get info of permisson settings dialog.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_EncryptPermisson* FR_EncryptPermisson;
#endif

/* @ENUMSTART */
/**
  * @brief The print permisson of permisson setting dialog.
  */
/** @deprecated: Internal use. */
enum FRPRINT_PERMISSON
{
	FR_PRINT_NONE = 0,
	FR_PRINT_LOW,
	FR_PRINT_HIGH
};
/* @ENUMEND */

/* @ENUMSTART */
/**
  * @brief The change permisson of permisson setting dialog.
  */
/** @deprecated: Internal use. */
enum FRCHANGE_PERMISSON
{
	FR_CHANGE_NONE = 0,
	FR_CHANGE_INSERTDELROTATE,
	FR_CHANGE_FORMFILL,
	FR_CHANGE_COMMENTSFORMFILL,
	FR_CHANGE_ANYEXCEPTEXTRACT
};
/* @ENUMEND */

/* @ENUMSTART */
/**
  * @brief The operation permisson of permisson setting dialog.
  */
/** @deprecated: Internal use. */
enum FRPROPERTITY_PERMISSON
{
	FR_PERMISSON_PRINTING = 0,			//Printing;
	FR_PERMISSION_CHANGEDOC,			//Changing the Document;
	FR_PERMISSON_DOCASSEMBLY,			//Document Assembly;
	FR_PERMISSION_CONTENTCOPY,			//Content Copying;
	FR_PERMISSION_CONTENTCOPYACCESS,	// Content Copying for Accessibility;
	FR_PERMISSON_PAGEEXTRACT,			//Page Extraction;
	FR_PERMISSON_COMMENT,				//Commenting;
	FR_PERMISSON_FILLFORM,				//Filling of form fields;
	FR_PERMISSON_SIGN					//Signing;
};
/* @ENUMEND */


/* @STRUCTSTART FR_SignatureDictInfo*/
#ifndef FRPENPermission
#define FRPENPermission
/**
* @brief Data structure for settins of permisson setting dialog.
*/
/** @Deprecated: Internal use. */
typedef struct __FR_ENPERMISSON__
{
	__FR_ENPERMISSON__()
	{
		bEnableCopy = FALSE;
		bEnableTextAccess = FALSE;
		printPer = FR_PRINT_NONE;
		changePer = FR_CHANGE_NONE;
	}

	FS_BOOL bEnableCopy;
	FS_BOOL bEnableTextAccess;

	FRPRINT_PERMISSON	 printPer;
	FRCHANGE_PERMISSON changePer;
}FR_ENPermission, *FR_PENPermission;
#endif
/* @STRUCTEND */
/* FR_EncryptPermisson */

/* @OBJSTART FR_Accessible */
#ifndef FR_ACCESSIBLE
#define FR_ACCESSIBLE
/**
* @brief
*/
typedef struct _t_FR_Accessible *FR_Accessible;
#endif

/* @CALLBACKGROUPSTART FR_AccessibleCallbacks */
/**
* @brief A callback when implement IAccessible.
*/
/** @Deprecated: Internal use. */
typedef struct _fr_Accessible_callbacks_
{
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOLEAN(*FRAccessbileGetChildCount)(FS_LPVOID clientData, long *pcountChildren);
	FS_BOOLEAN(*FRAccessbileGetRect)(FS_LPVOID clientData, FS_Rect* rect);
	FS_BOOLEAN(*FRAccessbileHasChild)(FS_LPVOID clientData, long index);
	FS_BOOLEAN(*FRAccessbileGetName)(FS_LPVOID clientData, FS_WideString* name);
	FS_BOOLEAN(*FRAccessbileGetValue)(FS_LPVOID clientData, FS_WideString* value);
	FS_BOOLEAN(*FRAccessbileGetDescription)(FS_LPVOID clientData, FS_WideString* description);	
	FS_BOOLEAN(*FRAccessbileGetRole)(FS_LPVOID clientData, FS_INT32* type);
	FS_BOOLEAN(*FRAccessbileGetState)(FS_LPVOID clientData, FS_INT32* type);
	FS_BOOLEAN(*FRAccessbileGetSelection)(FS_LPVOID clientData, FS_INT32* index);
	FS_BOOLEAN(*FRAccessbileGetAction)(FS_LPVOID clientData, FS_WideString* action);
	FS_BOOLEAN(*FRAccessbileDoDefaultAction)(FS_LPVOID clientData);
	FS_BOOLEAN(*FRAccessbileSetValue)(FS_LPVOID clientData, FS_WideString* value);
	FS_BOOLEAN(*FRAccessbileGetState2)(FS_LPVOID clientData, FS_INT32 index, FS_INT32* type);
	FS_BOOLEAN(*FRAccessbileGetOptionLabel)(FS_LPVOID clientData, FS_INT32 index, FS_WideString* value);
	FS_BOOLEAN(*FRAccessbileGetOptionValue)(FS_LPVOID clientData, FS_INT32 index, FS_WideString* value);
	FS_INT32(*FRAccessbileGetAction2)(FS_LPVOID clientData, FS_INT32 index, FS_WideString* value);
	FS_BOOLEAN(*FRAccessbileSetSelection)(FS_LPVOID clientData, FS_INT32 index, FS_INT32 selecttype);
	FS_BOOLEAN(*FRAccessbileDoDefaultAction2)(FS_LPVOID clientData, FS_INT32 index);
	FS_BOOLEAN(*FRAccessbileGetSelectCount)(FS_LPVOID clientData, FS_INT32* nCount);
	FS_BOOLEAN(*FRAccessbileGetCurIndexSelectindex)(FS_LPVOID clientData, FS_INT32* nindex, FS_INT32 curselectindex);
}FR_AccessibleCallbacksRec, *FR_AccessibleCallbacks;
/* @CALLBACKGROUPEND */

/* @OBJEND */


/*  FR_CSGCertFileManage */
#ifndef FR_CSGCERTFILEMANAGE
#define FR_CSGCERTFILEMANAGE
/**
 * @brief A <a>FR_CSGCertFileManage</a> is used to manage our trusted certificates.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_CSGCertFileManage* FR_CSGCertFileManage;
#endif
/* FR_CSGCertFileManage */

/*  FR_CSGCreateCert */
#ifndef FR_CSGCREATECERT
#define FR_CSGCREATECERT
/**
 * @brief A <a>FR_CSGCreateCert</a> is used to create HCERTSTORE.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_CSGCreateCert* FR_CSGCreateCert;
#endif


/* @STRUCTSTART FR_PSGCertData*/
/**
* @brief Data structure for cert data.
*
*/
/** @Deprecated: Internal use. */
typedef struct __FR_SGCERTDATA__
{
	FS_LPCWSTR path;
	FS_LPCWSTR pass;
	FS_LPCWSTR issuer;
	FS_LPCWSTR serial;
	__FR_SGCERTDATA__ & operator=(__FR_SGCERTDATA__ data)
	{
		path = data.path;
		pass = data.pass;
		issuer = data.issuer;
		serial = data.serial;
		return *this;
	}
}FR_SGCertData, *FR_PSGCertData;
/* @STRUCTEND */

/* @STRUCTSTART FR_PSGDataStruct*/
/**
* @brief Data structure for signature data.
*
*/
/** @Deprecated: Internal use. */
typedef struct __FR_SGDATASTRUCT__
{
	__FR_SGDATASTRUCT__() :nSaveMode(0), nAddMode(0),
		cwName(L""), cwOU(L""),
		cwON(L""), cwMail(L""),
		csCR(""), nKA(0),
		nUDF(2), cwSaveFilePath(L""),
		cwSavePass(L""), cwFromFilePath(L""),
		cwFromPass(L""), cwCertName(L""), psgData(NULL) {}
	FS_INT32 nAddMode;//0:file,1:new id
	FS_INT32 nSaveMode;//0:for savefile,1:for windows store
	FS_LPCWSTR cwName;
	FS_LPCWSTR cwOU;
	FS_LPCWSTR cwON;
	FS_LPCWSTR cwMail;
	FS_LPCSTR csCR;
	FS_INT32 nKA;// 0:for 1024, 1:for 2048
	FS_INT32 nUDF; // 0:for Digital Signature, 1:for Encrypt ,2:All
	FS_LPCWSTR cwSaveFilePath;
	FS_LPCWSTR cwSavePass;

	FS_LPCWSTR cwFromFilePath;
	FS_LPCWSTR cwFromPass;
	FS_LPCWSTR cwCertName;

    FS_LPVOID  psgData;//用来保存SG_DATASTRUCT指针数据, 插件不需要赋值
}FR_SGDataStruct, *FR_PSGDataStruct;
/* @STRUCTEND */
/* FR_CSGCreateCert */


/*FR_BAAnnotFiller */
#ifndef FR_BAANNOTFILLER
#define FR_BAANNOTFILLER
/**
 * @brief A <a>FR_BAAnnotFiller</a> is used to fill the form, it will set to FRBaseFormSetFormFiller.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_BAAnnotFiller* FR_BAAnnotFiller;
#endif

/* @CALLBACKGROUPSTART FRD_BAAnnotFillerCallbacks */
/**
* @brief A callback set for form filler.
*/
/** @Deprecated: Internal use. */
typedef struct _frd_BAAnnotFiller_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_Rect(*FRGetViewBBox)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	void(*FROnDraw)(FS_LPVOID clientData, FR_PageView pPageView, FR_WinPort hDC, FR_Annot pAnnot,
		FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device,
		const FS_Rect rcWindow, FS_DWORD dwFlags);
	void(*FRAnnot_OnVisible)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	void(*FROnCreate)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnLoad)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnRelease)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnMouseEnter)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	void(*FROnMouseExit)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	FS_BOOL(*FROnLButtonDown)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnLButtonUp)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnLButtonDblClk)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnMouseMove)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnMouseWheel)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, FS_SHORT zDelta, const FS_DevicePoint point);
	FS_BOOL(*FROnRButtonDown)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnRButtonUp)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnRButtonDblClk)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	void(*FROnDeSelected)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnSelected)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOL(*FROnSetFocus)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOL(*FROnKillFocus)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOL(*FROnReturn)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	FS_BOOL(*FROnESC)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOL(*FRIsFilling)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnTabd)(FS_LPVOID clientData, FR_Annot pAnnot);
}FRD_BAAnnotFillerCallbacksRec, *FRD_BAAnnotFillerCallbacks;
/* @CALLBACKGROUPEND */
/* FR_BAAnnotFiller */


/*  FR_BAAnnotDesigner */
#ifndef FR_BAANNOTDESIGNER
#define FR_BAANNOTDESIGNER
/**
 * @brief A <a>FR_BAAnnotDesigner</a> is used to design the form, it will set to FRBaseFormSetFormDesigner.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_BAAnnotDesigner* FR_BAAnnotDesigner;
#endif

/* @CALLBACKGROUPSTART FRD_BAAnnotDesignerCallbacks */
/**
* @brief A callback set for form design.
*/
/** @Deprecated: Internal use. */
typedef struct _frd_BAAnnotDesigner_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_Rect(*FRGetViewBBox)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
    void(*FROnDraw)(FS_LPVOID clientData, FR_PageView pPageView, FS_HDC hDC, FR_Annot pAnnot,
		FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device,
		const FS_Rect rcWindow, FS_DWORD dwFlags);
	void(*FRAnnot_OnVisible)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	void(*FROnCreate)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnLoad)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnDelete)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnRelease)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FRDeleteAnnot)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnMouseEnter)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	void(*FROnMouseExit)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	FS_BOOL(*FROnLButtonDown)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnLButtonUp)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnLButtonDblClk)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnMouseMove)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnMouseWheel)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, FS_SHORT zDelta, const FS_DevicePoint point);
	FS_BOOL(*FROnRButtonDown)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnRButtonUp)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnRButtonDblClk)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	void(*FROnDeSelected)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnSelected)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOL(*FROnSetFocus)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOL(*FROnKillFocus)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOL(*FRCanReSize)(FS_LPVOID clientData);
	FS_BOOL(*FRCanMove)(FS_LPVOID clientData);
	FS_INT32(*FRGetMoveType)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, const FS_DevicePoint point);
	void(*FROnMoving)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 nMovingType,
		const FS_DevicePoint ptOrigin, const FS_DevicePoint ptOld, const FS_DevicePoint ptNew, FS_BOOL bFirst);
	void(*FROnMoved)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 nMovingType,
		const FS_DevicePoint ptOrigin, const FS_DevicePoint ptNew);
	void(*FRCancelMoving)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 nMovingType,
		const FS_DevicePoint& ptOrigin, const FS_DevicePoint& ptNew);
	FS_BOOL(*FROnMoving2)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot,
		const FS_Rect rcOld, const FS_Rect& rcNew, FS_BOOL bFirst);
	void(*FROnMoved2)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot,
		const FS_Rect rcOrigin, const FS_Rect rcNew);
	void(*FROnMovedOutPage)(FS_LPVOID clientData, FR_PageView pPageView, FR_PageView pDestPageView, FR_Annot pAnnot,
		const FS_Rect rcOrigin, const FS_Rect rcNew, FS_INT32 nIndex);
	void(*FRCancelMoving2)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot,
		const FS_Rect rcOrigin, const FS_Rect rcNew);
	void(*FROnSetPosition)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot,
		const FS_FloatRect& rect, FS_INT32 nSrcType);
	FS_BOOL(*FRIsMenuItemSupported)(FS_LPVOID clientData, FS_INT32 nMenuItem);
    void(*FROnPopupMenu)(FS_LPVOID clientData, FS_MENU& menu, FS_INT32& ret);
	void(*FROnPopupMenuItem)(FS_LPVOID clientData, FR_PageView pPageView, FS_INT32 nMenuItemID);
	FS_BOOLEAN(*FRCanAnswer)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOLEAN(*FRCanCopy)(FS_LPVOID clientData, const FS_ByteString sSubType);
	FS_BOOLEAN(*FRCanCut)(FS_LPVOID clientData, const FS_ByteString  sSubType);
	FS_BOOLEAN(*FRCanPaste)(FS_LPVOID clientData, const FS_ByteString sSubType);
	FS_XMLElement(*FROnCopy)(FS_LPVOID clientData, FR_Annot pAnnot);
	FR_Annot(*FROnPaste)(FS_LPVOID clientData, FS_XMLElement pElement, FR_Page pPage, const FS_FloatRect rcAnnot);
	FS_BOOLEAN(*FRCanDelete)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOLEAN(*FRIsPermissionAllowed)(FS_LPVOID clientData, FR_Document pDocument, const FS_ByteString sSubType);
	void(*FRGetPropertyBoxTitle)(FS_LPVOID clientData, const FS_ByteString sSubType, FS_WideString* wsTitle);
	FS_BOOLEAN(*FROnReturn)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	FS_BOOLEAN(*FROnESC)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnTabd)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOLEAN(*FRIsVisible)(FS_LPVOID clientData, FR_Annot pAnnot);
}FRD_BAAnnotDesignerCallbacksRec, *FRD_BAAnnotDesignerCallbacks;
/* @CALLBACKGROUPEND */
/* FR_BAAnnotDesigner */


/*  FR_CBFInterForm */
#ifndef FR_BFINTERFORM
#define FR_BFINTERFORM
/**
* @brief A <a>FR_CBFInterForm</a> is used to design the form, it will set to FRBaseFormSetFormDesigner.
*/
/** @Deprecated: Internal use. */
typedef struct _t_FR_CBFInterForm* FR_CBFInterForm;
#endif
/* FR_CBFInterForm */


/*  FR_IBFFormNotify */
#ifndef FR_BFFORMNOTIFY
#define FR_BFFORMNOTIFY
/**
 * @brief A data structure representing the cursor.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_IBFFormNotify* FR_IBFFormNotify;
#endif

/* @CALLBACKGROUPSTART FRD_BFFormNotifyCallbacks */
/**
* @brief A callback when form changed.
*/
/** @Deprecated: Internal use. */
typedef struct _frd_BFFormNotify_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void(*FRBeforeFormReset)(FS_LPVOID clientData, FR_CBFInterForm pInterForm);
	void(*FRAfterFormReset)(FS_LPVOID clientData, FR_CBFInterForm  pInterForm);
	FS_INT32(*FRBeforeValueChange)(FS_LPVOID clientData, const FPD_FormField pField, FS_WideString* csValue);
}FRD_BFFormNotifyCallbacksRec, *FRD_BFFormNotifyCallbacks;
/* @CALLBACKGROUPEND */
/* FR_IBFFormNotify */


/*  FR_BAAnnotHandler */
#ifndef FR_BAANNOTHANDLER
#define FR_BAANNOTHANDLER
/**
 * @brief A data structure of annot handler.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_BAAnnotHandler* FR_BAAnnotHandler;
#endif

/* @CALLBACKGROUPSTART FRD_BAAnnotFillerCallbacks */
/**
* @brief A callback when create new annot.
*/
/** @Deprecated: Internal use. */
typedef struct _frd_BFAnnotHandler_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOL(*FRCanAnswer)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOL(*FRIsDesigner)(FS_LPVOID clientData, const FS_ByteString sSubType);
	FS_BOOL(*FRCanReSize)(FS_LPVOID clientData, const FS_ByteString sSubType);
	FS_BOOL(*FRCanMove)(FS_LPVOID clientData, const FS_ByteString sSubType);
	void(*FRGetType)(FS_LPVOID clientData, FS_ByteString* bsType);
	void(*FRGetName)(FS_LPVOID clientData, FS_ByteString* bsType);
	FR_Annot(*FRNewAnnot)(FS_LPVOID clientData, FPD_Annot pAnnot, FR_Page pReaderPage);
	void(*FRDeleteAnnot)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_Rect(*FRGetViewBBox)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	FS_BOOL(*FRHitTest)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, const FS_DevicePoint point);
	void(*FROnDraw)(FS_LPVOID clientData, FR_PageView pPageView, FR_WinPort hDC, FR_Annot pAnnot, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device, const FS_Rect rcWindow, FS_DWORD dwFlags);
	void(*FROnDrawSleep)(FS_LPVOID clientData, FR_PageView pPageView, FR_WinPort hDC, FR_Annot pAnnot, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device, const FS_Rect rcWindow, FS_DWORD dwFlags);
	void(*FROnCreate)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnLoad)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnDelete)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnRelease)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnMouseEnter)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	void(*FROnMouseExit)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	FS_BOOL(*FROnLButtonDown)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnLButtonUp)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnLButtonDblClk)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnMouseMove)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnMouseWheel)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, FS_SHORT zDelta, const FS_DevicePoint point);
	FS_BOOL(*FROnRButtonDown)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnRButtonUp)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnRButtonDblClk)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_UINT nFlags, const FS_DevicePoint point);
	FS_BOOL(*FROnContextMenu)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, const FS_DevicePoint point);
	void(*FROnDeSelected)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FROnSelected)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOL(*FROnSetFocus)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOL(*FROnKillFocus)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_INT32(*FRGetMoveType)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, const FS_DevicePoint& point);
	void(*FROnMoving)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 nMovingType,
		const FS_DevicePoint ptOrigin, const FS_DevicePoint ptOld, const FS_DevicePoint ptNew, FS_BOOL bFirst);
	void(*FROnMoved)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 nMovingType,
		const FS_DevicePoint ptOrigin, const FS_DevicePoint ptNew);
	void(*FRCancelMoving)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 nMovingType,
		const FS_DevicePoint& ptOrigin, const FS_DevicePoint& ptNew);
	FS_BOOL(*FROnMoving2)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot,
		const FS_Rect rcOld, const FS_Rect& rcNew, FS_BOOL bFirst);
	void(*FROnMoved2)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot,
		const FS_Rect rcOrigin, const FS_Rect rcNew);
	void(*FROnMovedOutPage)(FS_LPVOID clientData, FR_PageView pPageView, FR_PageView pDestPageView, FR_Annot pAnnot,
		const FS_Rect rcOrigin, const FS_Rect rcNew, FS_INT32 nIndex);
	void(*FRCancelMoving2)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot,
		const FS_Rect rcOrigin, const FS_Rect rcNew);
	void(*FROnSetPosition)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot,
		const FS_FloatRect& rect, FS_INT32 nSrcType);
	FS_BOOL(*FRIsMenuItemSupported)(FS_LPVOID clientData, FS_ByteString sSubType, FS_INT32 nMenuItem);
	void(*FROnPopupMenu)(FS_LPVOID clientData, FS_ByteString sSubType, FS_INT32* nIDAfter, FS_MENU& menu, FS_INT32& ret);
	void(*FROnPopupMenuItem)(FS_LPVOID clientData, FR_PageView pPageView, FS_ByteString sSubType, FS_INT32 nMenuItemID);
	FS_BOOL(*FRCanCopy)(FS_LPVOID clientData, const FS_ByteString sSubType);
	FS_BOOL(*FRCanCut)(FS_LPVOID clientData, const FS_ByteString sSubType);
	FS_BOOL(*FRCanPaste)(FS_LPVOID clientData, const FS_ByteString sSubType);
	FS_XMLElement(*FROnCopy)(FS_LPVOID clientData, FR_Annot pAnnot);
	FR_Annot(*FROnPaste)(FS_LPVOID clientData, FS_XMLElement pElement, FR_Page pPage, const FS_FloatRect rcAnnot);
	FS_BOOL(*FRIsPermissionAllowed)(FS_LPVOID clientData, FR_Document pDocument, const FS_ByteString sSubType);
	void(*FRGetPropertyBoxTitle)(FS_LPVOID clientData, const FS_ByteString sSubType, FS_WideString* strTitle);
	FS_BOOL(*FROnReturn)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
	FR_Annot(*FRNewAnnot2)(FS_LPVOID clientData, PFPDXFA_HWIDGET pWidget, FR_Page pPage);
	FS_BOOL(*FRCanDelete)(FS_LPVOID clientData, FR_Annot pAnnot);
	void(*FRAnnot_OnRelease)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_BOOLEAN(*FRAnnot_ReleasePopupMenu)(FS_LPVOID clientData, FS_MENU pMenu);
	FR_Accessible(*FROnGetAccessible)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot);
}FRD_BAAnnotHandlerCallbacksRec, *FRD_BAAnnotHandlerCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FRD_MarkupAnnotHandlerCallbacks */
/**
* @brief A callback when create new markup annot.
*/
/** @Deprecated: Internal use. */
typedef struct _frd_MarkupAnnotHandler_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FRD_BAAnnotHandlerCallbacksRec baseAnnotHandler;

	void(*FRTimerProc)(FS_LPVOID clientData);
	FS_LPVOID(*FRGetSystemHandler)(FS_LPVOID clientData);
	FS_XMLElement(*FRCopyReply)(FS_LPVOID clientData, FR_Annot pAnnot);
}FRD_MarkupAnnotHandlerCallbacksRec, *FRD_MarkupAnnotHandlerCallbacks;
/* @CALLBACKGROUPEND */
/* FR_BAAnnotHandler */



/*  FR_BaseForm */
#ifndef FR_BASEFORM
#define FR_BASEFORM
/**
 * @brief A data structure of baseform.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_BaseForm* FR_BaseForm;
#endif

/* @ENUMSTART */
/**
  * @brief The auto complete choice.
  */
/** @deprecated: Internal use. */
enum FR_AUTOCOMPLETECHOICE
{
	FRAUTOCOMPLETEOFF,
	FRAUTOCOMPLETEBASIC,
	FRAUTOCOMPLETEADVANCED
};
/* @ENUMEND */
/* FR_BaseForm */


/* @OBJSTART FR_IFormDesignerNotify */
#ifndef FR_FORMDESIGNERNOTIFY
#define FR_FORMDESIGNERNOTIFY
/**
 * @brief A data structure when form changed, it will set to FRDocSetNotify.
 */
typedef struct _t_FR_IFormDesignerNotify* FR_IFormDesignerNotify;
#endif
/* @OBJEND */

/* @OBJSTART FR_CBF_Widget */
#ifndef FR_CBFWIDGET
#define FR_CBFWIDGET
/**
 * @brief A data structure of widget annot.
 */
typedef struct _t_FR_CBF_Widget* FR_CBF_Widget;
#endif

/* @STRUCTSTART FR_BAFieldAction*/
/**
* @brief Data structure for field action.
*/
/** @Deprecated: Internal use. */
typedef struct __FR_BAFieldAction__
{
	FS_BOOL					bModifier;		//in
	FS_BOOL					bShift;			//in
	FS_INT32				nCommitKey;		//in
	FS_WideString			sChange;		//in[out]
	FS_WideString			sChangeEx;		//in
	FS_BOOL					bKeyDown;		//in
	FS_INT32				nSelEnd;		//in[out]
	FS_INT32				nSelStart;		//in[out]
	FS_WideString			sValue;			//in[out]
	FS_BOOL					bWillCommit;	//in
	FS_BOOL					bFieldFull;		//in
	FS_BOOL					bRC;			//in[out]
}FR_BAFieldAction;
/* @STRUCTEND*/
/* @OBJEND */


/*  FR_BFSimpleFromProperties */
#ifndef FR_BFSIMPLEFROMPROPERTIES
#define FR_BFSIMPLEFROMPROPERTIES
/**
 * @brief A data structure of base form simple properties.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_BFSimpleFromProperties* FR_BFSimpleFromProperties;
#endif
/* FR_BFSimpleFromProperties */


#ifndef SIG_EXPT_H_00001_
#define SIG_EXPT_H_00001_

/* @DEFGROUPSTART BuildInToolName */

/** @brief Shows signer name on description. */
#define FR_SIG_SHOW_NAME					0x001
/** @brief Shows location on description. */
#define FR_SIG_SHOW_LOCATION				0x002
/** @brief Shows dn on description. */
#define FR_SIG_SHOW_DN						0x004
/** @brief Shows date on description. */
#define FR_SIG_SHOW_DATE					0x008
/** @brief Shows reason on description. */
#define FR_SIG_SHOW_REASON					0x010
/** @brief Shows label on description. */
#define FR_SIG_SHOW_LABEL					0x020
/** @brief Shows foxit logo on signature ap. */
#define FR_SIG_SHOW_FOXITFLOGO				0x040
/** @brief Shows all flags. */
#define FR_SIG_SHOW_ALL					FR_SIG_SHOW_NAME |	FR_SIG_SHOW_LOCATION |	FR_SIG_SHOW_DN | FR_SIG_SHOW_DATE | FR_SIG_SHOW_REASON | FR_SIG_SHOW_LABEL | FR_SIG_SHOW_FOXITFLOGO			

/*@}*/
/* @DEFGROUPEND */

typedef enum
{
	FR_SIG_NONE = 0,
	FR_SIG_TRUE,
	FR_SIG_DOMDP
} FR_SIG_TYPE;

typedef enum {
	FRTM_NONE = -1,
	FRTM_SIGN,
	FRTM_FIELD,
	FRTM_CERTIFY
} FR_SGToolMode;

typedef enum
{
	FR_SIG_HANDLE_SUCCESS,	/** Succeed.*/
	FR_SIG_HANDLE_FAIL,		/** Fail.*/
	FR_SIG_HANDLE_NONE		/** None.*/
} FR_SG_HANDLE;

typedef enum
{
	FR_SIG_MODIFYDETECTOR_UNCHANGE = 0,
	FR_SIG_MODIFYDETECTOR_CHANGE,
	FR_SIG_MODIFYDETECTOR_ERROR,
} FR_SIG_MODIFYDETECTOR_RESULT;

typedef enum
{
	FR_SIG_MODIFYDETECTOR_FORMCREATE,
	FR_SIG_MODIFYDETECTOR_FORMDELETE,
	FR_SIG_MODIFYDETECTOR_FORMFILLIN,
	FR_SIG_MODIFYDETECTOR_FORMMODIFY,
	FR_SIG_MODIFYDETECTOR_ANNOTCREATE,
	FR_SIG_MODIFYDETECTOR_ANNOTDELETE,
	FR_SIG_MODIFYDETECTOR_ANNOTMODIFY,
	FR_SIG_MODIFYDETECTOR_PAGECREATE,
	FR_SIG_MODIFYDETECTOR_PAGEDELETE,
	FR_SIG_MODIFYDETECTOR_PAGEMODIFY
} FR_SIG_MODIFYDETECTOR_TYPE;

typedef enum
{
	FR_SIG_UPDATE_OK,
	FR_SIG_UPDATE_NONEED,
	FR_SIG_UPDATE_ERROR,
} FR_SIG_UPDATESTATE;

typedef enum
{
	FR_SGIT_NONE,			/** None. */
	FR_SGIT_GRAPHICS,		/** The type is graphic.*/
	FR_SGIT_NAME,			/** The type is name.*/
	FR_SGIT_DRAW            /** Deprecated.*/
} FR_SG_ICONTYPE;

enum FR_SG_TEXTDIR
{
	FR_SGTD_AUTO,			/** Auto. */
	FR_SGTD_LEFTTORIGHT,	/** Left to right. */
	FR_SGTD_RIGHTTOLEFT		/** Right to left. */
};
typedef enum
{
	FR_APG_NONE = 0,		/** None. */
	FR_APG_ONE = 1,			/** No changes allowed. */
	FR_APG_TWO = 2,			/** Form fill-in and digital signatures. */
	FR_APG_THREE = 3,		/** Annotations, form fill-in, and digital signatures. */
	FR_APG_LOCK = 4,			/** Lock document. */
	FR_APG_READONLY = 5/** Lock document. */
} FR_SG_PERMISSION;

/* @STRUCTSTART FR_SignatureTimestampServer*/
typedef struct __FR_SignatureTimestampServer__
{
	__FR_SignatureTimestampServer__()
	{
		memset(wsServerURL, 0, 2048 * sizeof(FS_WCHAR));
		memset(wsUserName, 0, 128 * sizeof(FS_WCHAR));
		memset(wsPassWord, 0, 128 * sizeof(FS_WCHAR));
		flags = -1;
	}
	/** The server URL. */
	FS_WCHAR wsServerURL[2048];

	/** The user name. */
	FS_WCHAR wsUserName[128];

	/** The password. */
	FS_WCHAR wsPassWord[128];

	FS_INT32 flags;
}FR_SignatureTimestampServer;
/* @STRUCTEND */
/* @STRUCTSTART FR_SignaturePosInfo*/
typedef struct __FR_SignaturePosInfo__
{
	__FR_SignaturePosInfo__()
	{
		pPDFDoc = NULL;
		nPageIndex = -1;
		nLeft = nRight = nTop = nBottom = 0;
		memset(FileSavePath, 0, 260 * sizeof(FS_WCHAR));
		pFieldDict = NULL;
	}

	/** The FPD_Document which need to be add signature. */
	FPD_Document	pPDFDoc;
	/** The page index of the doc which need to be add signature. */
	FS_INT32		nPageIndex;
	/** The margin left of signature. */
	FS_INT32		nLeft;
	/** The margin right of signature. */
	FS_INT32		nRight;
	/** The margin top of signature. */
	FS_INT32		nTop;
	/** The margin bottom of signature. */
	FS_INT32		nBottom;
	/** The savefile path need to save. */
	FS_WCHAR		FileSavePath[260];
	/** The dictionary info. */
	FPD_Object      pFieldDict;
}FR_SignaturePosInfo;
/* @STRUCTEND */
/* @STRUCTSTART FR_SignatureTimestamp*/
typedef struct __FR_SignatureTimestamp__
{

	__FR_SignatureTimestamp__()
	{
		dwLowDateTime = 0;
		dwHighDateTime = 0;
	}
	/** The LowDateTime. */
	FS_DWORD dwLowDateTime;
	/** The HighDateTime. */
	FS_DWORD dwHighDateTime;

}FR_SignatureTimestamp;
/* @STRUCTEND */
/* @STRUCTSTART FR_SignatureDictInfo*/
typedef struct __FR_SignatureDictInfo__
{
	__FR_SignatureDictInfo__()
	{
		memset(wsName, 0, 128 * sizeof(wchar_t));
		memset(wsDate, 0, 128 * sizeof(wchar_t));
		memset(wsReason, 0, 256 * sizeof(wchar_t));
		memset(wsLocation, 0, 256 * sizeof(wchar_t));
		memset(wsFilter, 0, 128 * sizeof(wchar_t));
		memset(wsContactInfo, 0, 256 * sizeof(wchar_t));
	}

	/** The signer. */
	wchar_t					wsName[128];
	/** The signing date. */
	wchar_t					wsDate[128];
	/** The reason for signing. */
	wchar_t					wsReason[256];
	/** The location for signing. */
	wchar_t					wsLocation[256];
	/** The filter of the signing. */
	wchar_t					wsFilter[128];
	/** Deprecated.*/
	wchar_t					wsContactInfo[256];
}FR_SignatureDictInfo;
/* @STRUCTEND */
/* @STRUCTSTART FR_SignatureInfo*/
typedef struct __FR_SignatureInfo__
{
	__FR_SignatureInfo__()
	{
		memset(wsCN, 0, 64 * sizeof(FS_WCHAR));
		memset(wsO, 0, 64 * sizeof(FS_WCHAR));
		memset(wsOU, 0, 64 * sizeof(FS_WCHAR));
		memset(wsE, 0, 128 * sizeof(FS_WCHAR));
		memset(wsC, 0, 64 * sizeof(FS_WCHAR));
		lShowFlag = FR_SIG_SHOW_ALL;
		TextDir = FR_SGTD_AUTO;
		Icontype = FR_SGIT_NAME;
		memset(ImagePath, 0, 260);
		nImageOpt = 100;
		PermissionType = FR_APG_NONE;
		lEstimateSignData = 0;
		bDocTimeStamp = false;
		pCertContext = NULL;
		memset(wsPassword, 0, 64 * sizeof(FS_WCHAR));
		memset(wsAppearance, 0, 128 * sizeof(FS_WCHAR));
		bUseStandAppearance = false;
		memset(wsTimestampURL, 0, 256 * sizeof(FS_WCHAR));
		memset(wsCertFile, 0, MAX_PATH * sizeof(FS_WCHAR));
		bExecutesign = TRUE;
	}

	/** The siganture author.*/
	FS_WCHAR				wsCN[64];
	/** The organization name. */
	FS_WCHAR				wsO[64];
	/** The organizational unit info. */
	FS_WCHAR				wsOU[64];
	/** The email address. */
	FS_WCHAR				wsE[128];
	/** The country/region info. */
	FS_WCHAR				wsC[64];
	/** Data structure for signature dictionary info */
	FR_SignatureDictInfo	SignDictInfo;
	/** The flag for showing appearance. See <a>FRSIGShowAPFlags</a>. */
	FS_DWORD			    lShowFlag;
	/** The style of showing graphic on signature appearance. */
	FR_SG_ICONTYPE			Icontype;
	/** The text direction on signature appearance. */
	FR_SG_TEXTDIR			TextDir;
	/** The definition for signature permission.*/
	FR_SG_PERMISSION		PermissionType;
	/** The image path. */
	FS_WCHAR				ImagePath[260];
	/** The image opacity. */
	FS_INT32				nImageOpt;
	/** The length of sign data if you need limit the length. Default is 0.*/
	FS_DWORD			    lEstimateSignData;
	/** It's not be used.*/
	FS_BOOL					bDocTimeStamp;
	/** The PCCERT_CONTEXT info.*/
	FS_LPVOID               pCertContext;
	/** The password of the cert.*/
	FS_WCHAR				wsPassword[64];
	/** The appearance style name of the signature. You can set apperance style from preference\Signature first.
	It's valid when bUseStandAppearance set true.
	*/
	FS_WCHAR				wsAppearance[128];
	/** If use standard style. If need to display specified apperance, it need to be set false.  */
	FS_BOOLEAN				bUseStandAppearance;
	/** The server url of timestamp.*/
	FS_WCHAR				wsTimestampURL[256];
	/** If path of the cert file.*/
	FS_WCHAR				wsCertFile[MAX_PATH];
	/** If need to sign.*/
	FS_BOOL					bExecutesign;
}FR_SignatureInfo;
/* @STRUCTEND */


/* @STRUCTSTART FR_SignatureInfo*/
typedef struct __FR_SignatureExtendInfo__
{
	__FR_SignatureExtendInfo__()
	{
		imageData = NULL;
		imageLen = 0;
		imageType = FS_IMAGE_TYPE::FS_IMAGE_PNG;
		blendMode = 0;
		memset(wsSubFilter, 0, 128 * sizeof(wchar_t));
	}

	/** The size of data structure. */
	unsigned long lStructSize;

	/** The sub-filter of the signing. */
	wchar_t                 wsSubFilter[128];

	/** The image buffer. If not set, we'll get image from ImagePath property.*/
	FS_BYTE*                imageData;
	/** The image length.*/
	FS_INT32                imageLen;
	/** The image type.*/
	FS_IMAGE_TYPE           imageType;
	/** The blend mode. 0: not blend backgroud, 1: blend backgroud.*/
	FS_INT32                blendMode;
}FR_SignatureExtendInfo;


/* @STRUCTSTART FR_SignatureBaseInfo*/
typedef struct __FR_SignatureBaseInfo__
{
	__FR_SignatureBaseInfo__()
	{
		memset(wsSignedAutorName, 0, 128 * sizeof(wchar_t));
		memset(wsSignatureName, 0, 128 * sizeof(wchar_t));
		bSignedField = FALSE;
		nSignedPageIndex = 0;
		bVerified = FALSE;
		dwVerifyState = 0;
		memset(wsSignedTime, 0, 256 * sizeof(wchar_t));
		memset(wsSignedCertName, 0, 256 * sizeof(wchar_t));
		memset(wsSignedReason, 0, 256 * sizeof(wchar_t));
		memset(wsSignedLocation, 0, 256 * sizeof(wchar_t));
	}

	/** The UTC time when the signature was signed. */
	FS_FILETIME	ftSignedTime;
	/** Date and time before which the certificate is not valid. */
	FS_FILETIME	ftValidTimeNotBefore;
	/** Date and time after which the certificate is not valid.*/
	FS_FILETIME	ftValidTimeNotAfter;
	/** The author name. */
	wchar_t		wsSignedAutorName[128];
	/** The signature name. */
	wchar_t		wsSignatureName[128];
	/** Whether it is a signed field or not. */
	FS_BOOL		bSignedField;
	/** The index of the page where the signature was signed. */
	FS_INT32	nSignedPageIndex;
	/** The verifying state. */
	FS_DWORD    dwVerifyState;
	/** Whether the signature has been verified or not. */
	FS_BOOL		bVerified;
	/** The system time when the signature was signed. */
	wchar_t     wsSignedTime[256];
	/** The certificate name. Mac is not support now*/
	wchar_t		wsSignedCertName[256];
	/** The reason of signature. Mac is not support now*/
	wchar_t		wsSignedReason[256];
	/** The location of signature. Mac is not support now*/
	wchar_t		wsSignedLocation[256];
}FR_SignatureBaseInfo;
/* @STRUCTEND */

/* @CALLBACKGROUPSTART FR_SigHandlerCallbacksRec */
typedef struct _fr_signaturehandler_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_SignatureHandlerCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRSignatureHandlerGetName */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to provide the name of the signature handler.
	*
	* @param[in] clientData	The user-supplied data.
	* @return The name of the signature handler.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	char* (*FRSignatureHandlerGetName)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerSignData */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to pass the data to be signed to the plug-in.
	*
	* @param[in] clientData			The user-supplied data.
	* @param[in] pData2BSigned		The data to be signed.
	* @param[in] ulData2BSignedLen	The length of the data to be signed.
	* @param[out] pPSignedData		Pass the signed data back to the framework.
	* @param[out] pulSignedDataLen	Pass the length of the signed data back to the framework.
	* @return The result of signing the data.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	FR_SG_HANDLE(*FRSignatureHandlerSignData)(FS_LPVOID clientData, const unsigned char* pData2BSigned, unsigned long ulData2BSignedLen, unsigned char** pPSignedData, FS_DWORD* pulSignedDataLen);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerTimeStampDate */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to receive the timestamp date from plug-in.
	*
	* @param[in] clientData			The user-supplied data.
	* @param[out] pSgTimeStampDate	Receives the timestamp date from plug-in.
	* @param[in] pSignDict			The dictionary data of sign.
	* @return The result of getting the timestamp date.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	FR_SG_HANDLE(*FRSignatureHandlerTimeStampDate)(FS_LPVOID clientData, FR_SignatureTimestamp* pSgTimeStampDate, FPD_Object pSignDict);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerVerifyData */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to pass the data to the plug-in. Then the plug-in can takes over the process for verifying the signed data.
	*
	* @param[in] clientData			The user-supplied data.
	* @param[in] pSignedData		The signed data.
	* @param[in] ulSignedDataLen	The length of the signed data.
	* @param[in] pData2BSigned		The source data that is signed.
	* @param[in] ulDataT2BSignedLen	The length of the source data that is signed.
	* @param[out] outVerifyState	Pass the verifying state back to framework. See <a>FRSIGVarifySignatureStates</a>.
	* @param[out] hCertContext		The certificate context. It will be passed to <a>FRSignatureHandlerShowStateUI</a>;
	* @return The result of verifying the data. If the plug-in returns <a>FR_SIG_HANDLE_NONE</a>, the Foxit Reader will verify the data by default method.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	FR_SG_HANDLE(*FRSignatureHandlerVerifyData)(FS_LPVOID clientData, const unsigned char* pSignedData, FS_DWORD ulSignedDataLen,
		const unsigned char* pData2BSigned, unsigned long ulDataT2BSignedLen, FS_DWORD* outVerifyState, void** hCertContext);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerShowStateUI */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to show the state UI. The plug-in can create its own UI.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] nVerifyState	The verifying state.
	* @param[in] pWnd			The parent window of the state UI. It represents the <Italic>MFC CWnd*</Italic>.
	* @param[in] hCertContext	The certificate context from <a>FRSignatureHandlerVerifyData</a>.
	* @param[in] pSignDictInfo	The signature dictionary info.
	* @param[in] pSignDict	    The signature dictionary.
	* @return The result of showing state UI.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	FR_SG_HANDLE(*FRSignatureHandlerShowStateUI)(FS_LPVOID clientData, const FS_DWORD nVerifyState, void* pWnd, void* hCertContext, FR_SignatureDictInfo* pSignDictInfo, FPD_Object pSignDict);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerCanClear */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to check whether the signature can be cleared or not.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] hCertContext	The certificate context from <a>FRSignatureHandlerVerifyData</a>.
	* @param[out] bCanClear		Whether the signature can be cleared or not.
	* @param[in] pSignDict	    The signature dictionary.
	* @return The result of this checking.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	FR_SG_HANDLE(*FRSignatureHandlerCanClear)(FS_LPVOID clientData, void* hCertContext, FS_BOOL* bCanClear, FPD_Object pSignDict);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerShowSignProperties */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to show the signing properties. The plug-in can create its own UI.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] pSignedData		The signed data.
	* @param[in] ulSignedDataLen	The length of the signed data.
	* @param[in] pData2BSigned		The source data that is signed.
	* @param[in] ulDataT2BSignedLen	The length of the source data that is signed.
	* @param[in] pWnd			The parent window of the property UI. It represents the <Italic>MFC CWnd*</Italic>.
	* @param[in] pSignDictInfo	The signature dictionary info.
	* @param[in] hCertContext	The certificate context from <a>FRSignatureHandlerVerifyData</a>.
	* @param[in] pSignDict	    The signature dictionary.
	* @return The result of showing the signing property UI.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.3
	*/
	FR_SG_HANDLE(*FRSignatureHandlerShowSignProperties)(FS_LPVOID clientData, const unsigned char* pSignedData, unsigned long ulSignedDataLen,
		const unsigned char* pData2BSigned, unsigned long ulDataT2BSignedLen, void* pWnd, FR_SignatureDictInfo* pSignDictInfo, void* hCertContext, FPD_Object pSignDict);
	/* @CALLBACKEND */

	/* @CALLBACKSTART RSignatureHandlerRleaseSignData */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to Rlease the data to be signed.
	*
	* @param[in] clientData		    The user-supplied data.
	* @param[in] pPSignedData		The data to be Rleased.
	* @param[in] pulSignedDataLen	The length of the data to be Rleased.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 9.1
	*/
	void(*FRSignatureHandlerRleaseSignData)(FS_LPVOID clientData, unsigned char **pPSignedData, FS_DWORD *pulSignedDataLen);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerSGVerifyCanSign */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to check if the doc can sign.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] pSignDict	    The dictionary of the sign.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 9.1
	*/
	FR_SG_HANDLE(*FRSignatureHandlerSGVerifyCanSign)(FS_LPVOID clientData, FPD_Object pSignDict);
	/* @CALLBACKEND */

	/* @CALLBACKSTART RSignatureHandlerRleaseSignData */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to check if the doc can verify.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] pSignDict	    The dictionary of the sign.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 9.1
	*/
	FR_SG_HANDLE(*FRSignatureHandlerSGVerifyCanVerify)(FS_LPVOID clientData, FPD_Object pSignDict);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerCanClear2 */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to check whether the signature can be cleared or not.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] hCertContext	The certificate context from <a>FRSignatureHandlerVerifyData</a>.
	* @param[out] bCanClear		Whether the signature can be cleared or not.
	* @param[in] pSignDict	    The signature dictionary.
	* @param[in] pFieldDict	    The filed dictionary.
	* @return The result of this checking.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 12.1.0
	*/
	FR_SG_HANDLE(*FRSignatureHandlerCanClear2)(FS_LPVOID clientData, void* hCertContext, FS_BOOL* bCanClear, FPD_Object pSignDict, FPD_Object pFieldDict);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerClearedSignature */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to check whether the signature can be cleared or not.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] pFieldDict	    The input field dictionary that need to delete.
	* @param[in] pageindex		The input pageindex.	
	* @return The result of this checking.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 13.0
	*/
	void(*FRSignatureHandlerClearedSignature)(FS_LPVOID clientData, FPD_Object pFieldDict, FS_INT32 pageindex);
	/* @CALLBACKEND */
}FR_SignatureHandlerCallbacksRec, *FR_SignatureHandlerCallbacks;
/* @CALLBACKGROUPEND */


/* @OBJSTART FR_SIGBaseHandler
 */

 /* @OBJEND */

 /* @OBJSTART FRSG_RDN
  */
typedef struct _t_FRSG_RDN* FRSG_RDN;
/* @OBJEND */


/* @OBJSTART FRSG_SEEDVALUE_INFO
 */
typedef struct _t_FRSG_SEEDVALUE_INFO* FRSG_SEEDVALUE_INFO;
/* @OBJEND */

/* @OBJSTART FRSG_CERTIFICATE_INFO
 */
typedef struct _t_FRSG_CERTIFICATE_INFO* FRSG_CERTIFICATE_INFO;
/* @OBJEND */
#endif


/* FRSG_CERTIFICATE_INFO */



#define FRBA_MOVETYPE_NONE			0
#define FRBA_MOVETYPE_MOVE			1
#define FRBA_MOVETYPE_ELSE			2

#define FRBBS_SOLID					0
#define FRBBS_DASH					1
#define FRBBS_BEVELED				2
#define FRBBS_INSET					3
#define FRBBS_UNDERLINE				4

/* @ENUMSTART */
/**
  * @brief The modify detector result.
  */
/** @deprecated: Internal use. */
enum FRSIG_MODIFYDETECTOR_RESULT
{
	FRSIG_MODIFYDETECTOR_UNCHANGE = 0,
	FRSIG_MODIFYDETECTOR_CHANGE,
	FRSIG_MODIFYDETECTOR_ERROR,
};
/* @ENUMEND */

/* @ENUMSTART */
/**
  * @brief The modify detector type.
  */
/** @deprecated: Internal use. */
enum FRSIG_MODIFYDETECTOR_TYPE
{
	FRSIG_MODIFYDETECTOR_FORMCREATE,
	FRSIG_MODIFYDETECTOR_FORMDELETE,
	FRSIG_MODIFYDETECTOR_FORMFILLIN,
	FRSIG_MODIFYDETECTOR_FORMMODIFY,
	FRSIG_MODIFYDETECTOR_ANNOTCREATE,
	FRSIG_MODIFYDETECTOR_ANNOTDELETE,
	FRSIG_MODIFYDETECTOR_ANNOTMODIFY,
	FRSIG_MODIFYDETECTOR_PAGECREATE,
	FRSIG_MODIFYDETECTOR_PAGEDELETE,
	FRSIG_MODIFYDETECTOR_PAGEMODIFY
};
/* @ENUMEND */

/* @CALLBACKGROUPSTART FRD_SGBaseHandlerCallbacks */
/**
* @brief A callback when signature.
*/
/** @Deprecated: Internal use. */
typedef struct _frd_SGBaseHandler_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FRD_SGBaseHandlerCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOLEAN(*FRSG_GenerateSignInfo)(FS_LPVOID clientData, FR_SignatureInfo* pSgInfo, FR_SignaturePosInfo* pSgPosInfo);
	FS_BOOLEAN(*FRGetDefaultServer)(FS_LPVOID clientData, FR_SignatureTimestampServer* pSgTMServer);
	FS_BOOLEAN(*FRSetSignatureVerify)(FS_LPVOID clientData, FR_Document frDoc, const unsigned char* pSignedData, FS_DWORD ulSignedDataLen);
	FS_INT32(*FRSG_GetDocSigatureCount)(FS_LPVOID clientData, FR_Document frDoc);
	FS_BOOLEAN(*FRSG_GetSignatureBaseInfo)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nIndex, FR_SignatureBaseInfo* pInfo);
	FS_BOOLEAN(*FRSG_ClearSignature)(FS_LPVOID clientData, FR_Document frDoc, FS_INT32 nIndex);
	FS_BOOLEAN(*FRSG_GetAppearanceArray)(FS_LPVOID clientData, FS_WideStringArray* wideStringArr);
	FS_BOOLEAN(*FRSG_GetSignatureBaseInfo2)(FS_LPVOID clientData, FR_Document frDoc, FPD_Object pSignDict, FR_SignatureBaseInfo* &pBaseSignInfo);
	FS_BOOLEAN(*FRSG_SetSignatureVerify)(FS_LPVOID clientData, FR_Document frDoc, FPD_Object pSignDict);
	void(*FRSG_GetSignatureVerifyStateText)(FS_LPVOID clientData, FR_Document frDoc, FPD_Object pSignDict, const FS_DWORD dwVerifyState, FS_WideString* wsText);
	FS_BOOLEAN(*FRSG_SetSeedValue)(FS_LPVOID clientData, FR_Document frDoc, FPD_Object pSignFieldDict, FRSG_SEEDVALUE_INFO pSeedValue);
	FS_BOOLEAN(*FRSG_GetSeedValue)(FS_LPVOID clientData, FR_Document frDoc, FPD_Object pSignDict, FRSG_SEEDVALUE_INFO* pSeedValue);
	FRSIG_MODIFYDETECTOR_RESULT(*FRSG_CheckModifyDetector)(FS_LPVOID clientData, FR_Document frDoc, FPD_Object pSignDict);
	FS_INT32(*FRSG_GetModifyDetectorTypeResultSize)(FS_LPVOID clientData, const FRSIG_MODIFYDETECTOR_TYPE nType);
	FS_BOOLEAN(*FRSG_GetModifyDetectorTypeResult)(FS_LPVOID clientData, const FRSIG_MODIFYDETECTOR_TYPE nType, FPD_MODIFYDATA data[]);
	FS_BOOLEAN(*FRSG_DoShowSignatureVerify)(FS_LPVOID clientData, FR_Document frDoc, FPD_Object pSignDict);
	FPD_Object(*FRSG_CreateSignatureF)(FS_LPVOID clientData, FR_Document pRDDoc, FS_BOOLEAN bSetSignS);
	void(*FRSG_SetPosition)(FS_LPVOID clientData, FR_PageView pPageView, FPD_Object pDict, const FS_FloatRect rcSig);
}FRD_SGBaseHandlerCallbacksRec, *FRD_SGBaseHandlerCallbacks;
/* @CALLBACKGROUPEND */
/* FR_SGBaseHandler */


/*  FR_ClipBoard */
#ifndef FR_CLIPBOARD
#define FR_CLIPBOARD
/**
 * @brief A data structure of clipboard.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_ClipBoard* FR_ClipBoard;
#endif
/* FR_ClipBoard */

/*  FR_CCBAnnotation */
#ifndef FR_CCBANNOTATION
#define FR_CCBANNOTATION
/**
 * @brief A data structure of CCBAnnotation.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_CCBAnnotation* FR_CCBAnnotation;
#endif

/* @CALLBACKGROUPSTART FR_CCBAnnotationCallbacks */
/**
* @brief A callback when parse dict to xml.
*/
/** @Deprecated: Internal use. */
typedef struct _fr_CCBAnnotation_callbacks_
{
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOLEAN(*FRParseToXML)(FS_LPVOID clientData, FPD_Object pAnnotDict, FS_XMLElement pElement);
	FS_BOOLEAN(*FRParseToDict)(FS_LPVOID clientData, FS_XMLElement pElement, FPD_Object pAnnotDict);
	FS_BOOLEAN(*FRIsKeyNeeded_ToXML)(FS_LPVOID clientData, FS_ByteString csKeyName, FS_INT32 nObjType);
	FS_BOOLEAN(*FRIsKeyNeeded_ToDict)(FS_LPVOID clientData, FS_ByteString csKeyName, FS_INT32 nObjType);
	void(*FRAddNecessaryKeyToList_ToXML)(FS_LPVOID clientData, FS_ByteString csKeyName);
}FR_CCBAnnotationCallbacksRec, *FR_CCBAnnotationCallbacks;
/* @CALLBACKGROUPEND */
/* FR_CCBAnnotation */

/*  FR_ISpellCheck */
#ifndef FR_ISPELLCHECK
#define FR_ISPELLCHECK
/**
 * @brief A data structure of ISpellCheck.
 */
/** @Deprecated: Internal use. */
typedef struct _t_FR_ISpellCheck* FR_ISpellCheck;
#endif
/* FR_ISpellCheck */


/* FR_IBAImageSource */
#ifndef FR_IBAIMAGESOURCE
#define FR_IBAIMAGESOURCE
/**
 * @brief A data structure of base image source.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_IBAImageSource* FR_IBAImageSource;
#endif

/* @CALLBACKGROUPSTART FR_IBAImageSourceHandlerCallbacks */
/**
* @brief A callback when image source.
*/
/** @Deprecated: Internal use. */
typedef struct _fr_IBAImageSourceHandler_callbacks_
{
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRGetRect */
	/**
	* @brief A callback for ImageSource.
	* @param[in] clientData	The user-supplied data.
	* @return Get the rect of the imagesource.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	*/
	FS_Rect(*FRGetRect)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRGetColor */
	/**
	* @brief A callback for ImageSource.
	* @param[in] clientData	The user-supplied data.
	* @param[in] x	        The X coordinate.
	* @param[in] y	        The Y coordinate
	* @return GetPixel of x,y to create COLORREF.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	*/
	FS_COLORREF(*FRGetColor)(FS_LPVOID clientData, FS_INT32 x, FS_INT32 y);
	/* @CALLBACKEND */
}FR_IBAImageSourceHandlerCallbacksRec, *FR_IBAImageSourceHandlerCallbacks;
/* @CALLBACKGROUPEND */
/* FR_IBAImageSource */


/* FR_CBAFigureRecognition */
#ifndef FR_CBAFIGURERECOGNTION
#define FR_CBAFIGURERECOGNTION
/**
 * @brief A data structure of base form recognition.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_CBAFigureRecognition* FR_CBAFigureRecognition;
#endif
/* FR_CBAFigureRecognition */


/* FR_AnnotObserver */
#ifndef FR_ANNOTOBSERVER
#define FR_ANNOTOBSERVER
/**
 * @brief  A <a>FR_AnnotObserver</a> is used to monitor FR_Annot object.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_AnnotObserver* FR_AnnotObserver;
#endif
/* FR_AnnotObserver */


/* FR_DocumentObserver */
#ifndef FR_DOCUMENTOBSERVER
#define FR_DOCUMENTOBSERVER
/**
 * @brief  A <a>FR_DocumentObserver</a> is used to monitor FR_Document object.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_DocumentObserver* FR_DocumentObserver;
#endif
/* FR_DocumentObserver */

/* FR_PageObserver */
#ifndef FR_PAGEOBSERVER
#define FR_PAGEOBSERVER
/**
 * @brief  A <a>FR_PageObserver</a> is used to monitor FR_Page object.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_PageObserver* FR_PageObserver;
#endif
/* FR_PageObserver */


/* FR_InnerContentProvider */
#ifndef FR_INNERCONTENTPROVIDER
#define FR_INNERCONTENTPROVIDER
/**
 * @brief  A <a>FR_InnerContentProvider</a> is used to get content.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_InnerContentProvider* FR_InnerContentProvider;
#endif
/* FR_InnerContentProvider */


/* FR_IFXPDFAInterface */
#ifndef FR_IFXPDFAINTERFACE
#define FR_IFXPDFAINTERFACE
/**
 * @brief  A <a>FR_IFXPDFAInterface</a> is convert pdfa.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_IFXPDFAInterface* FR_IFXPDFAInterface;
#endif
/* FR_IFXPDFAInterface */

/*  FR_TextPage */
#ifndef FR_TEXTPAGE
#define FR_TEXTPAGE
/**
 * @brief  A <a>FR_TextPage</a> is convert pdfa.
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_TextPage* FR_TextPage;
#endif
/*  FR_TextPage*/

/*  FR_ISignatureCheck */
#ifndef FR_ISIGNATURECHECK
#define FR_ISIGNATURECHECK
/**
 * @brief  A <a>FR_ISignatureCheck</a> is convert pdfa.
 */
 /** @Deprecated: Internal use. */

#endif

/* @ENUMSTART */
/**
  * @brief The sign type.
  */
/** @deprecated: Internal use. */
enum FR_SIGHTYPE
{
	FRSIGNNONE = 0,
	FRSIGNATURE,
	FRDOCMDP
};
/* @ENUMEND */

/* @CALLBACKGROUPSTART FR_SignatureCheckCallbacks */
/**
* @brief A callback when check the document if sign.
*/
/* @Deprecated: Internal use. */

/* @CALLBACKGROUPEND */
/*  FR_ISignatureCheck */


/* @STRUCTSTART FR_IdentityInfo*/
/**
* @brief The infomation of identity. Related to <a>FRAppGetPreferenceIdentity</a>
*/
typedef struct __FR_PTLfile_data_
{
	FPD_Object  pFolder;
	FPD_Object  pFileSpec;
}FR_PTLFILEDATA, *FR_PPTLFILEDATA;
/* @STRUCTEND */
/*  FR_Portfolio */

/* @OBJSTART FR_TextLinkInfo */
#ifndef FR_TEXTLINKINTO
#define FR_TEXTLINKINTO
/**
* @brief  A <a>FR_TextLinkInfo</a> is information of text link.
*/
typedef struct _t_FR_TextLinkInfo* FR_TextLinkInfo;
#endif
/* @OBJEND */

/* @OBJSTART FR_TextLinkMgr */
#ifndef FR_TEXTLINKMGR
#define FR_TEXTLINKMGR
/**
* @brief  A <a>FR_TextLinkMgr</a> is used to extract text link.
*/
typedef struct _t_FR_TextLinkMgr* FR_TextLinkMgr;
#endif
/* @OBJEND */

/* @OBJSTART FR_SelectedImageInfo */
#ifndef FR_SELECTEDIMAGEINFO
#define FR_SELECTEDIMAGEINFO
/**
* @brief  A <a>FR_SelectedImageInfo</a> is information of current selected image.
*/
typedef struct _t_FR_SelectedImageInfo* FR_SelectedImageInfo;
#endif
/* @OBJEND */

/* @OBJSTART FR_STRUCTCONTENT_OBJECT */
#ifndef FR_STRUCTCONTENTOBJECT
#define FR_STRUCTCONTENTOBJECT
/**
* @brief  A <a>FR_STRUCTCONTENT_OBJECT</a> is information of page content object.
*/
typedef struct _t_FR_STRUCTCONTENT_OBJECT *FR_STRUCTCONTENT_OBJECT;
#endif

typedef struct __FR_TEXTRANGE__
{
	int nStart;
	int nLen;

	FS_BOOL operator < (const __FR_TEXTRANGE__ &TRB)const
	{
		return nStart < TRB.nStart;
	}
	FS_BOOL operator==(const  __FR_TEXTRANGE__& src) const
	{
		return (nStart == src.nStart && nLen == src.nLen);
	}
} FR_TEXTRANGE, *PFR_TEXTRANGE;
/* @OBJEND */

/* @OBJSTART FR_DeletePageUndoItem */
#ifndef FR_DELETEAGEUNDOITEM
#define FR_DELETEAGEUNDOITEM
/**
 * @brief  A <a>FR_DeletePageUndoItem</a>
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_DeletePageUndoItem* FR_DeletePageUndoItem;
#endif
/* OBJEND */

/* @OBJSTART FR_AnnotHandler */
#ifndef FR_ANNOTHANDLER
#define FR_ANNOTHANDLER
/**
 * @brief  A <a>FR_AnnotHandler</a>
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_AnnotHandler* FR_AnnotHandler;
#endif
/* OBJEND */

/* @OBJSTART FR_WidgetAnnotHandler */
#ifndef FR_WIDGETANNOTHANDLER
#define FR_WIDGETANNOTHANDLER
/**
 * @brief  A <a>FR_WidgetAnnotHandler</a>
 */
 /** @Deprecated: Internal use. */
typedef struct _t_FR_WidgetAnnotHandler* FR_WidgetAnnotHandler;
#endif

/* @CALLBACKGROUPSTART FR_DRMEventCallbacks */
/**
 * @brief The structure containing DRM event callbacks. Plug-ins invoke these callbacks to provide encrypted and decrypted file.
 * See <a>FRAppRegisterDRMEventHandler</a>.
 *
 */
typedef struct _fr_widgetannothandler_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DRMEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRWidgetOnGetCustomHightColor */
	/**
	* @brief It will be invoked when opreate the widget annot.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pAnnot	    The widget annot that is currently operated on.
	 * @param[out] fillcolorW   Get the hight color.
	 * @return <a>TRUE</a> means get the hight color success.
	 * @note
	 */
	FS_BOOLEAN(*FRWidgetOnGetCustomHightColor)(FS_LPVOID clientData, FR_Annot pAnnot, FS_DWORD* fillcolorW);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWidgetOnIsShowQuickAccPropery */
	/**
	* @brief It will be invoked when need to encrypt pdf file.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pAnnot	    The widget annot that is currently operated on.
	 * @return <a>TRUE</a> means need show quick acc property.
	 * @note
	 */
	FS_BOOLEAN(*FRWidgetOnIsShowQuickAccPropery)(FS_LPVOID clientData, FR_Annot pAnnot);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWidgetOnGetSignatureAuditTrail */
	/**
	* @brief It will be invoked when close the encrypt pdf file.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pAnnotDict	The dictionary of the widget annot.
	 * @param[out] text			Get the audit trail.
	 * @return <a>TRUE</a> means get the trail success.
	 * @note
	 */
	FS_BOOLEAN(*FRWidgetOnGetSignatureAuditTrail)(FS_LPVOID clientData, FPD_Object pAnnotDict, FS_WideString* text);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWidgetOnGetSignatureHashInfo */
	/**
	* @brief It will be invoked when close the encrypt pdf file.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pAnnotDict	The dictionary of the widget annot.
	 * @param[out] lastHash		Get the last hash info.
	 * @param[out] currentHash	Get the current hash info.
	 * @return <a>TRUE</a> means get the hash info success.
	 * @note
	 */
	FS_BOOLEAN(*FRWidgetOnGetSignatureHashInfo)(FS_LPVOID clientData, FPD_Object pAnnotDict, FS_WideString* lastHash, FS_WideString* currentHash);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRWidgetOnIsShowSignaturePanelMenu */
	/**
	* @brief It will be invoked when close the encrypt pdf file.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pAnnotDict	The dictionary of the widget annot.
	 * @param[out] nExData		Get the ext data.
	 * @return <a>TRUE</a> means get the hash info success.
	 * @note
	 */
	FS_BOOLEAN(*FRWidgetOnIsShowSignaturePanelMenu)(FS_LPVOID clientData, FPD_Object pAnnotDict, FS_INT32* nExData);
	/* @CALLBACKEND */
}FR_WidgetAnnotHandlerCallbacksRec, *FR_WidgetAnnotHandlerCallbacks;
/* @CALLBACKGROUPEND */
/* OBJEND */

/* @OBJSTART FR_AnnotOperateHandler */
#ifndef FR_ANNOOPERATETHANDLER
#define FR_ANNOOPERATETHANDLER
/**
* @brief  A <a>FR_AnnotOperateHandler</a>
*/
/** @Deprecated: Internal use. */
typedef struct _t_FR_AnnotOperateHandler* FR_AnnotOperateHandler;
#endif

enum FR_AnnotMsgType
{
	FR_AnnotOnLDown = 0,
	FR_AnnotOnLUp,
	FR_AnnotOnRUp,
	FR_AnnotOnRDown,
};

/* @CALLBACKGROUPSTART FR_DRMEventCallbacks */
/**
* @brief The structure containing DRM event callbacks. Plug-ins invoke these callbacks to provide encrypted and decrypted file.
* See <a>FRAppRegisterDRMEventHandler</a>.
*
*/
typedef struct _fr_annotoperatehandler_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DRMEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRAnnotOnMouseMsg */
	/**
	* @brief It will be invoked when opreate the widget annot.
	* @param[in] clientData	The user-supplied data.
	* @param[in] pPageView		The input FR_PageView.
	* @param[in] pAnnot	    The widget annot that is currently operated on.
	* @param[in] emsgtype      The operate msg type.
	* @return <a>TRUE</a> means operate success.
	* @note
	*/
	FS_BOOLEAN(*FRAnnotOnMouseMsg)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FR_AnnotMsgType emsgtype);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAnnotCanMove */
	/**
	* @brief It will be invoked when move.
	* @param[in] clientData	The user-supplied data.
	* @param[in] pPageView	    The dictionary of the widget annot.
	* @param[in] pAnnot	    The dictionary of the widget annot.
	* @param[in] movetype	    1: means move area; otherwise means move through the control point.
	* @param[out] bCanMove		Check if can move the widget.
	* @return <a>TRUE</a> means get success.
	* @note
	*/
	FS_BOOLEAN(*FRAnnotCanMove)(FS_LPVOID clientData, FR_PageView pPageView, FR_Annot pAnnot, FS_INT32 movetype, FS_BOOLEAN* bCanMove);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAnnotCanAnswer */
	/**
	* @brief It will be invoked when annot has no permisson, Whether the specific annot can edit.
	* @param[in] clientData	The user-supplied data.
	* @param[in] pAnnot	    The input widget annot.
	* @return <a>TRUE</a> means the specified annot can edit.
	* @note
	*/
	FS_BOOLEAN(*FRAnnotCanAnswer)(FS_LPVOID clientData, FR_Annot pAnnot);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAnnotCanCopy */
	/**
	* @brief It will be invoked when annot has no permisson, Whether the specific annot can edit.
	* @param[in] clientData	The user-supplied data.
	* @param[in] pAnnot	    The input widget annot.
	* @param[in] pageIndex	The input page index.
	* @return <a>TRUE</a> means the specified annot can copy.
	* @note
	*/
	FS_BOOLEAN(*FRAnnotCanCopy)(FS_LPVOID clientData, FR_Annot pAnnot, FS_INT32 pageIndex);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRAnnotOnLock */
	/**
	* @brief It will be invoked when annot has lock or unlock.
	* @param[in] clientData	The user-supplied data.
	* @param[in] pAnnot	    The input FR_Annot.
	* @param[in] bLock	    If annot locked.
	* @return <a>TRUE</a> means the specified annot can copy.
	* @note
	*/
	FS_BOOLEAN(*FRAnnotOnLock)(FS_LPVOID clientData, FR_Annot pAnnot, FS_BOOLEAN bLock);
	/* @CALLBACKEND */

}FR_AnnotOperateHandlerCallbacksRec, *FR_AnnotOperateHandlerCallbacks;
/* @CALLBACKGROUPEND */
/* OBJEND */

/* @OBJSTART FR_Save_SaveAsNotify */
#ifndef FR_SAVEASNOTIFY
#define FR_SAVEASNOTIFY
/**
* @brief  A <a>FR_Save_SaveAsNotify</a>
*/
/** @Deprecated: Internal use. */
typedef struct _t_FR_Save_SaveAsNotify* FR_Save_SaveAsNotify;
#endif

/* @CALLBACKGROUPSTART FR_SaveAsCallbacks */
/**
* @brief The structure containing save as event callbacks. Plug-ins invoke these callbacks to provide save as default name.
* See <a>FR_SaveAsCallbacks</a>.
*
*/
typedef struct _fr_save_saveasnotify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DRMEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRIsSaveAsSaveTo */
	/**
	* @brief It will be invoked when save the file.
	* @param[in] clientData	The user-supplied data.
	* @param[in] pRDoc		The input FR_Document.	
	* @return <a>TRUE</a> means need to save as saveas opera.
	* @note
	*/
	FS_BOOLEAN(*FRIsSaveAsSaveTo)(FS_LPVOID clientData, FR_Document pRDoc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRGetSaveToDefaultName */
	/**
	* @brief It will be invoked when get default name.
	* @param[in] clientData	The user-supplied data.
	* @param[in] pRDoc	    The input FR_Document.	
	* @param[out] saveDefaultName	    Get the default save as name.	
	* @return void
	* @note
	*/
	void(*FRGetSaveToDefaultName)(FS_LPVOID clientData, FR_Document pRDoc, FS_WideString* saveDefaultName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRIsNeedShowSaveDlg */
	/**
	* @brief It will be invoked when save doc.
	* @param[in] clientData	The user-supplied data.	
	* @return <a>TRUE</a> means need to show save dialog.
	* @note
	*/
	FS_BOOLEAN(*FRIsNeedShowSaveDlg)(FS_LPVOID clientData);
	/* @CALLBACKEND */
}FR_SaveAsNotifyCallbacksRec, *FR_SaveAsCallbacks;
/* @CALLBACKGROUPEND */
/* OBJEND */


/* @OBJSTART FR_OrganizeNotify */
#ifndef FR_ORGANIZENOTIFY
#define FR_ORGANIZENOTIFY
/**
* @brief  A <a>FR_OrganizeNotify</a>
*/
/** @Deprecated: Internal use. */
typedef struct _t_FR_OrganizeNotify* FR_OrganizeNotify;
#endif

/* @CALLBACKGROUPSTART FR_OrganizeNotifyCallbacks */
/** @brief A set of callbacks for PDF form notify handler. */
typedef struct _frd_organizenotify_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART OnReady */
	/**
	* @brief			A callback when ready to organize page.
	*
	* It is called when ready to organize page.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] nMin		The input progress minimum.
	* @param[in] nMax		The input progress maximum.
	* @note
	*/
	void(*OnReady)(FS_LPVOID clientData, FS_INT32 nMin, FS_INT32 nMax);
	/* @CALLBACKEND */

	/* @CALLBACKSTART OnProgress */
	/**
	* @brief			A callback when progress is updated.
	*
	* It is called when progress is updated.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] nValue		The current progress value.
	* @note
	*/
	FS_BOOLEAN(*OnProgress)(FS_LPVOID clientData, FS_INT32 nValue);
	/* @CALLBACKEND */

	/* @CALLBACKSTART OnDone */
	/**
	* @brief			A callback when finished.
	*
	* It is called when finished.
	*
	* @param[in] clientData	The user-supplied data.
	* @note
	*/
	void(*OnDone)(FS_LPVOID clientData);
	/* @CALLBACKEND */
}FR_OrganizeNotifyCallbacksRec, * FR_OrganizeNotifyCallbacks;
/* @CALLBACKGROUPEND */

/* OBJEND */

#ifdef __cplusplus
};
#endif

#endif
/*@}*/


/*@}*/

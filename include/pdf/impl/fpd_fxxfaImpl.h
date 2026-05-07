#ifndef FPD_FXXFAIMPL_H
#define FPD_FXXFAIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_FXXFAEXPT_H
#include "../fpd_fxxfaExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../fpd_parserExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

class CFPD_XFARenderOptions_V16
{
public:
	//************************************
	// Function: CreateXFARenderOptions	
	// Return: FPD_XFARenderOptions    Create XFA render options.
	// Remarks:	 Create XFA render options.
	// Notes:	
	//************************************ 
	static FPD_XFARenderOptions CreateXFARenderOptions();

	//************************************
	// Function: DeleteXFARenderOptions
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Return: void
	// Remarks:	Delete FPD_XFARenderOptions object.	
	// Notes:	
	//************************************ 
	static void DeleteXFARenderOptions(FPD_XFARenderOptions options);

	//************************************
	// Function: GetIsPrint
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Return: FS_BOOLEAN          true: be print.
	// Remarks:	Get whether be print.
	// Notes:	
	//************************************ 
	static FS_BOOLEAN			GetIsPrint(FPD_XFARenderOptions options);

	//************************************
	// Function: SetIsPrint
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Param[in]: bPrint           Set whether be print.
	// Return: void
	// Remarks:	Set whether be print.
	// Notes:	
	//************************************ 
	static 	void		SetIsPrint(FPD_XFARenderOptions options, FS_BOOLEAN bPrint);

	//************************************
	// Function: GetIsHighlight
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Return: FS_BOOLEAN           true: is highlight.
	// Remarks:	Get whether it is highlight.
	// Notes:	
	//************************************ 
	static FS_BOOLEAN			GetIsHighlight(FPD_XFARenderOptions options);

	//************************************
	// Function: SetIsHighlight
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Param[in]: bHighlight       Set whether it is highlight.
	// Return: void         
	// Remarks:	Set whether it is highlight
	// Notes:	
	//************************************ 
	static void			SetIsHighlight(FPD_XFARenderOptions options, FS_BOOLEAN bHighlight);

	//************************************
	// Function: GetIsConverPdf
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Return: FS_BOOLEAN           true: is convert pdf.
	// Remarks:	Get whether it is convert pdf.
	// Notes:	
	//************************************ 
	static FS_BOOLEAN			GetIsConverPdf(FPD_XFARenderOptions options);

	//************************************
	// Function: SetIsConverPdf
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Param[in]: bConverPdf       Set whether it is convert pdf.	
	// Return: void
	// Remarks:	Get whether it is convert pdf.
	// Notes:	
	//************************************ 
	static 	void		SetIsConverPdf(FPD_XFARenderOptions options, FS_BOOLEAN bConverPdf);
	
	//************************************
	// Function: GetColorMode
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Return: FS_INT32           Get the color mode.
	// Remarks:	 Get display mode.
	// Notes:	like FPD_RENDER_COLOR_NORMAL,FPD_RENDER_COLOR_GRAY
	//************************************ 
	static FS_INT32		GetColorMode(FPD_XFARenderOptions options);

	//************************************
	// Function: SetColorMode
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Param[in]: colorMode        Set the color mode.	
	// Return: void
	// Remarks:	Set the color mode.
	// Notes:	like FPD_RENDER_COLOR_NORMAL,FPD_RENDER_COLOR_GRAY
	//************************************ 
	static 	void	SetColorMode(FPD_XFARenderOptions options, FS_INT32 colorMode);
	
	//************************************
	// Function: GetDocTextColor
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Return: FS_COLORREF         Get the doc text color.
	// Remarks:	 The text and path color for custom mode.
	// Notes:	default is black.
	//************************************ 
	static FS_COLORREF		GetDocTextColor(FPD_XFARenderOptions options);

	//************************************
	// Function: SetDocTextColor
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Param[in]: color            The text and path color for custom mode.
	// Return: void
	// Remarks:	 Set the doc text color.
	// Notes:	default is black.
	//************************************ 
	static void		SetDocTextColor(FPD_XFARenderOptions options, FS_COLORREF color);	

	//************************************ 
	 // Function: SetCustomColorMode
	 // Param[in]: options          The input FPD_XFARenderOptions object.	
	 // Param[in]: mode          The input foreground color mode for custom mode.
	 // Return: void
	 // Remarks: Set the foreground color mode for custom mode.
	 // Notes:	
	 //************************************ 
	static void		SetCustomColorMode(FPD_XFARenderOptions options, FS_DWORD mode);

	 //************************************
	 // Function: TranslateColor
	 // Param[in]: options          The input FPD_XFARenderOptions object.	
	 // Param[in]: argb             The input color.
	 // Param[in]: objType          The object type.	
	 // Return: FS_COLORREF        The translated color.
	 // Remarks:	 Translate a color.
	 // Notes:	
	 // Deprecated: Internal use. It has been deprecated.
	 //************************************ 
	static FS_ARGB			TranslateColor(FPD_XFARenderOptions options, FS_ARGB argb, FS_INT32 objType);

	//************************************ 
	// Function: GetCustomColorMode
	// Param[in]: options          The input FPD_XFARenderOptions object.	
	// Return: FS_DWORD            Get the foreground color mode for custom mode.
	// Remarks:	 Get the foreground color mode for custom mode.
	// Notes:	
	//************************************ 
	static FS_DWORD		GetCustomColorMode(FPD_XFARenderOptions options);
};

class CFPD_XFARenderContext_V16
{
public:
	//************************************
	// Function: Create
	// Return: FPD_XFARenderContext        Create FPD_XFARenderContext.
	// Remarks:	 Create FPD_XFARenderContext.
	// Notes:	
	//************************************ 
	static FPD_XFARenderContext	Create();

	//************************************
	// Function: Release
	// Param[in]: context         The input FPD_XFARenderContext.
	// Return: void
	// Remarks:	 Release FPD_XFARenderContext.
	// Notes:	
	//************************************ 
	static void	Release(FPD_XFARenderContext context);

	//************************************
	// Function: StartRender
	// Param[in]: context         The input FPD_XFARenderContext.
	// Param[in]: pPageView       The input FPD_XFAPageView.
	// Param[in]: pGS             The input FPD_Graphics.
	// Param[in]: pMatrix         The input FS_AffineMatrix.
	// Param[in]: options         The input FPD_XFARenderOptions.
	// Return: FS_INT32
	// Remarks:	 Start render.
	// Notes:	
	//************************************ 
	static FS_INT32	StartRender(FPD_XFARenderContext context, FPD_XFAPageView pPageView, FPD_Graphics pGS, const FS_AffineMatrix pMatrix, const FPD_XFARenderOptions options);
	
	//************************************
	// Function: DoRender
	// Param[in]: context         The input FPD_XFARenderContext.
	// Param[in]: pPause          The input FS_PauseHandler.
	// Return: FS_INT32
	// Remarks:	 Do render.
	// Notes:	
	//************************************ 
	static FS_INT32	DoRender(FPD_XFARenderContext context, FS_PauseHandler pPause);

	//************************************
	// Function: StopRender
	// Param[in]: context         The input FPD_XFARenderContext.
	// Return: void
	// Remarks:	 Stop render.
	// Notes:	
	//************************************ 
	static void	StopRender(FPD_XFARenderContext context);
};

class CFPD_XFAConverter_V16
{
public:	
	//************************************
	// Function: Create
	// Param[in]: type         The input convert type.
	// Return: void
	// Remarks:	Create XFA Converter Interface.
	// Notes:	
	//************************************ 
	static FPD_XFAConverter Create(FPDXFA_CONVERT_TYPE type);

	//************************************
	// Function: Release
	// Param[in]: converter         The input FPD_XFAConverter.
	// Return: void
	// Remarks:	Release XFA Converter Interface.
	// Notes:	When release the converter, the FPD_Document will be release also.
	//************************************ 
	static void Release(FPD_XFAConverter converter);	
	
	//************************************
	// Function: StartConvert
	// Param[in]: converter         The input FPD_XFAConverter.
	// Param[in]: wsXFAFile         The XFA file path.
	// Param[in]: wsPDFFile         The PDF file path.
	// Param[in]: bUsePDFJS         Whether use PDFJS, default is true.
	// Return: FPDXFA_CONVERT_STATUS
	// Remarks:	Start convert XFA File To PDF File.
	// Notes:	
	//************************************ 
	static FPDXFA_CONVERT_STATUS StartConvert(FPD_XFAConverter converter, FS_LPCWSTR wsXFAFile, FS_LPCWSTR wsPDFFile, FS_BOOLEAN bUsePDFJS);

	//************************************
	// Function: StartConvert2
	// Param[in]: converter         The input FPD_XFAConverter.
	// Param[in]: fsXFAFile         The XFA file stream.
	// Param[in]: fsPDFFile         The PDF file stream.
	// Param[in]: bUsePDFJS         Whether use PDFJS, default is true.
	// Return: FPDXFA_CONVERT_STATUS
	// Remarks:	Start convert XFA File Stream To PDF File Stream.
	// Notes:	
	//************************************ 
	static FPDXFA_CONVERT_STATUS StartConvert2(FPD_XFAConverter converter, FS_FileReadHandler fsXFAFile, FS_FileWriteHandler fsPDFFile, FS_BOOLEAN bUsePDFJS);

	//************************************
	// Function: StartConvert3
	// Param[in]: converter         The input FPD_XFAConverter.
	// Param[in]: hXFADoc           The XFA document handler.
	// Param[out]: pDstDocument     The convert PDF document.
	// Param[in]: psrcDocument      The input source document, it can't be nullptr.
	// Return: FPDXFA_CONVERT_STATUS
	// Remarks:	Start convert XFA Document To PDF Document.You need to do xfa page render.
	// Notes:	
	//************************************ 
	static FPDXFA_CONVERT_STATUS StartConvert3(FPD_XFAConverter converter, PFPDXFA_HDOC hXFADoc, FPD_Document* pDstDocument, FPD_Document psrcDocument);

	//************************************
	// Function: StartConvert4
	// Param[in]: converter         The input FPD_XFAConverter.
	// Param[in]: pPageViewArray    The XFA page views array.
	// Param[in]: PageViewCount     The XFA page count.
	// Param[out]: pDstDocument     The PDF document.
	// Param[in]: psrcDocument      The input source document, it can't be nullptr.
	// Return: FPDXFA_CONVERT_STATUS
	// Remarks:	Start convert XFA Page To PDF Document.You need to do xfa page render.
	// Notes:	
	//************************************ 
	static FPDXFA_CONVERT_STATUS StartConvert4(FPD_XFAConverter converter, FPD_XFAPageView* pPageViewArray, const FS_INT32 PageViewCount, FPD_Document* pDstDocument, FPD_Document psrcDocument);

	//************************************
	// Function: DoConvert
	// Param[in]: converter         The input FPD_XFAConverter.
	// Param[in]: pPause            The pause interface.
	// Return: FPDXFA_CONVERT_STATUS
	// Remarks:	 Continue convert.
	// Notes:	
	//************************************ 
	static FPDXFA_CONVERT_STATUS DoConvert(FPD_XFAConverter converter, FS_PauseHandler pPause);
};


#ifdef __cplusplus
};
#endif

#endif
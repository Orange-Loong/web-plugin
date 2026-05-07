#ifndef FPD_CONVERTIMPL_H
#define FPD_CONVERTIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
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

#ifndef FPD_PAGEEXPT_H
#include "../fpd_pageExpT.h"
#endif

#ifndef FPD_CONVERTEXPT_H
#include "../fpd_convertExpT.h"
#endif

#ifndef FPD_LREXPT_H
#include "../fpd_lrExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

class CFPD_ConvertTaggedPDFHandler_V16
{
public:
	//************************************
	// Function:  NewHandler
	// Param[in]: callbacks		The input FPD_ConvertTaggedPDFCallbacks.
	// Return:    FPD_ConvertTaggedPDFHandler
	// Remarks:   Create FPD_ConvertTaggedPDFHandler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_ConvertTaggedPDFHandler NewHandler(FPD_ConvertTaggedPDFCallbacks callbacks);

	//************************************
	// Function:  DestroyHandler
	// Param[in]: handler		The input FPD_ConvertTaggedPDFHandler.
	// Return:    void
	// Remarks:   Destroy FPD_ConvertTaggedPDFHandler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void DestroyHandler(FPD_ConvertTaggedPDFHandler handler);
};

class CFPD_DestructObject_V16
{
public:
	//************************************
	// Function:  FormRecognitionCreate
	// Param[in]: handler		The input FPD_ConvertTaggedPDFHandler.
	// Return:    FPD_DestructObject
	// Remarks:   Create FPD_DestructObject to from recognition.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_DestructObject FormRecognitionCreate(FPD_ConvertTaggedPDFHandler handler);
	
	//************************************
	// Function:  RecognitionCreateFrom
	// Return:    FPD_DestructObject
	// Remarks:   Create FPD_DestructObject from generated formedPDF on the original PDF.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_DestructObject RecognitionCreateFrom();

	//************************************
	// Function:  FormRecognitionCreate
	// Param[in]: options		The input FDF_FormRecognitionOption.
	// Return:    FPD_DestructObject
	// Remarks:   Create FPD_DestructObject from generated formedPDF on the original PDF.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static FPD_DestructObject FormRecognitionCreate2(FDF_FormRecognitionOption options);

	//************************************
	// Function:  CreateFormRecognitionHandler
	// Param[in]: callbacks		The input FPD_FormRecognitionCallbacks.
	// Return:    FDF_FormRecognitionHandler. It used to SetRecognitionCallback to recognition option. 
	// Remarks:   Create FDF_FormRecognitionHandler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static FDF_FormRecognitionHandler CreateFormRecHandler(FPD_FormRecognitionCallbacks callbacks);

	//************************************
	// Function:  DeleteFormRecognitionHandler
	// Param[in]: handler		The input FDF_FormRecognitionHandler.
	// Return:    void
	// Remarks:   Delete FDF_FormRecognitionHandler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static void DeleteFormRecHandler(FDF_FormRecognitionHandler handler);

	//************************************
	// Function:  CreateFormRecognitionOption	
	// Return:    FDF_FormRecognitionOption. It used to FormRecognitionCreate.
	// Remarks:   Create FDF_FormRecognitionOption.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static FDF_FormRecognitionOption CreateFormRecOption();

	//************************************
	// Function:  DeleteFormRecognitionOption	
	// Param[in]: handler		The input FDF_FormRecognitionOption.
	// Return:    void
	// Remarks:   Delete FDF_FormRecognitionOption.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static void DeleteFormRecOption(FDF_FormRecognitionOption option);

	//************************************
	// Function:  GetRecognitionCallback	
	// Param[in]: option		The input FDF_FormRecognitionOption.
	// Return:    FDF_FormRecognitionHandler
	// Remarks:   Get the recognition callback.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static FDF_FormRecognitionHandler GetRecCallback(FDF_FormRecognitionOption option);

	//************************************
	// Function:  SetRecognitionCallback	
	// Param[in]: option		The input FDF_FormRecognitionOption.
	// Param[in]: handler		The input FDF_FormRecognitionHandler.
	// Return:    void
	// Remarks:  Set the recognition callback.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static void SetRecCallback(FDF_FormRecognitionOption option, FDF_FormRecognitionHandler handler);

	//************************************
	// Function:  GetOutputPath	
	// Param[in]: option		The input FDF_FormRecognitionOption.
	// Return:    FS_LPCWSTR
	// Remarks:  Get output path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static FS_LPCWSTR GetOutputPath(FDF_FormRecognitionOption option);

	//************************************
	// Function:  SetOutputPath	
	// Param[in]: option		The input FDF_FormRecognitionOption.
	// Param[in]: path		    The input output path.
	// Return:    void
	// Remarks:  Set output path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static void SetOutputPath(FDF_FormRecognitionOption option, FS_LPCWSTR path);

	//************************************
	// Function:  GetFileStream	
	// Param[in]: option		The input FDF_FormRecognitionOption.
	// Return:    FS_FileStream
	// Remarks:  Get file stream.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static FS_FileStream GetFileStream(FDF_FormRecognitionOption option);

	//************************************
	// Function:  SetFileStream	
	// Param[in]: option		The input FDF_FormRecognitionOption.
	// Param[in]: fileStream	The input file stream.
	// Return:    void
	// Remarks:  Set file stream.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static void SetFileStream(FDF_FormRecognitionOption option, FS_FileStream fileStream);
};

class CFPD_ConverterOptions_V16
{
public:
	//************************************
	// Function:  NewConverterOptions	
	// Return:    FDF_ConverterOptions   Create FDF_ConverterOptions.
	// Remarks:   Create FDF_ConverterOptions.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FDF_ConverterOptions NewConverterOptions();

	//************************************
	// Function:  DestroyConverterOptions	
	// Param[in]: option		The input FDF_ConverterOptions.
	// Return:    void
	// Remarks:   Destroy FDF_ConverterOptions.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void DestroyConverterOptions(FDF_ConverterOptions option);

	//************************************
	// Function:  GetImageDPP	
	// Param[in]: option		The input FDF_ConverterOptions.
	// Return:    FS_FLOAT      Get per point of images.
	// Remarks:   Get per point of images.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FS_FLOAT GetImageDPP(FDF_ConverterOptions option);

	//************************************
	// Function:  SetImageDPP	
	// Param[in]: option		The input FDF_ConverterOptions.
	// Param[in]: dpp		    The input per point of images.
	// Return:    void
	// Remarks:   Set per point of images.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void SetImageDPP(FDF_ConverterOptions option, FS_FLOAT dpp);

	//************************************
	// Function:  GetStopWhenTimeout	
	// Param[in]: option		The input FDF_ConverterOptions.
	// Return:    FS_BOOLEAN    Get if stop when time out.
	// Remarks:   Get if stop when time out.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FS_BOOLEAN GetStopWhenTimeout(FDF_ConverterOptions option);

	//************************************
	// Function:  SetStopWhenTimeout	
	// Param[in]: option		The input FDF_ConverterOptions.
	// Param[in]: bTimeOut		Set if stop when time out.
	// Return:    void
	// Remarks:   Set if stop when time out.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void SetStopWhenTimeout(FDF_ConverterOptions option, FS_BOOLEAN bTimeOut);

	//************************************
	// Function:  GetOCContext	
	// Param[in]: option		The input FDF_ConverterOptions.	
	// Return:    FPD_OCContext Get the OCContext.
	// Remarks:   Get the OCContext.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_OCContext GetOCContext(FDF_ConverterOptions option);

	//************************************
	// Function:  SetOCContext	
	// Param[in]: option		The input FDF_ConverterOptions.	
	// Param[in]: ocContext		The input OCContext.	
	// Return:    void
	// Remarks:   Set the OCContext.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void SetOCContext(FDF_ConverterOptions option, FPD_OCContext ocContext);

	//************************************
	// Function:  GetLRVersion	
	// Param[in]: option		The input FDF_ConverterOptions.		
	// Return:    FS_INT32      Get LR version.
	// Remarks:   Get LR version.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FS_INT32 GetLRVersion(FDF_ConverterOptions option);

	//************************************
	// Function:  SetLRVersion	
	// Param[in]: option		The input FDF_ConverterOptions.	
	// Param[in]: version		The input LR version.		
	// Return:    void      
	// Remarks:   Set LR version.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void SetLRVersion(FDF_ConverterOptions option, FS_INT32 version);	
};

class CFPD_ConverterHandler_V16
{
public:
	//************************************
	// Function:  NewConvertHandler
	// Param[in]: callbacks		The input FPD_ConverterCallbacks.
	// Return:    FPD_ConverterHandler
	// Remarks:   Create FPD_ConverterHandler from FPD_ConverterCallbacks.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_ConverterHandler NewConvertHandler(FPD_ConverterCallbacks callbacks);

	//************************************
	// Function:  DestroyConvertHandler
	// Param[in]: handler		The input FPD_ConverterHandler.
	// Return:    void
	// Remarks:   Destroy FPD_ConverterHandler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void DestroyConvertHandler(FPD_ConverterHandler handler);

	static FS_BOOLEAN	NeedToPauseNow(FPD_ConverterHandler handler);
	static FS_BOOLEAN PreparePage(FPD_ConverterHandler handler, FS_INT32 nPageIdx, FPD_Page pPage);
	static void ConfigureAnalysisOptions(FPD_ConverterHandler handler, FS_INT32 nPageIdx, FPD_Page pPage, FPD_LR_AnalysisOptions pOptions);
	static void UpdateProgress(FPD_ConverterHandler handler, FS_INT32 nConvertedCount);
};


class CFPD_Converter_V16
{
public:
	//************************************
	// Function:  Create
	// Param[in]: pTarget		The input FPD_DestructObject.
	// Return:    FPD_Converter
	// Remarks:   Create FPD_Converter with target object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_Converter Create(FPD_DestructObject pTarget);

	//************************************
	// Function:  DestroyConverter
	// Param[in]: converter		The input FPD_Converter.
	// Return:    void
	// Remarks:   Destory FPD_Converter.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void DestroyConverter(FPD_Converter converter);

	//************************************
	// Function:  Start
	// Param[in]: converter		        The input FPD_Converter.
	// Param[in]: pPage		            The input FPD_Page.
	// Param[in]: pStructureElement		The input FPD_LR_StructureElementRef.
	// Param[in]: options				The input FDF_ConverterOptions.
	// Return:    FPD_ProgressiveStatus Convert progress status.
	// Remarks:   Start convert by convert option.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_ProgressiveStatus Start(FPD_Converter converter, FPD_Page pPage, FPD_LR_StructureElementRef pStructureElement,FDF_ConverterOptions options);
	
	//************************************
	// Function:  Start2
	// Param[in]: converter		        The input FPD_Converter.
	// Param[in]: pDocument		        The input FPD_Document.
	// Param[in]: options				The input FDF_ConverterOptions.
	// Return:    FPD_ProgressiveStatus Convert progress status.
	// Remarks:   Start convert by convert option.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_ProgressiveStatus Start2(FPD_Converter converter, FPD_Document pDocument, FDF_ConverterOptions options);

	//************************************
	// Function:  Start3
	// Param[in]: converter		        The input FPD_Converter.
	// Param[in]: pPage		            The input FPD_Page.
	// Param[in]: options				The input FDF_ConverterOptions.
	// Return:    FPD_ProgressiveStatus Convert progress status.
	// Remarks:   Start convert by convert option.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_ProgressiveStatus Start3(FPD_Converter converter, FPD_Page pPage, FDF_ConverterOptions options);

	//************************************
	// Function:  Continue
	// Param[in]: converter		        The input FPD_Converter.
	// Param[in]: handler		        The input FPD_ConverterHandler.	
	// Return:    FPD_ProgressiveStatus Convert progress status.
	// Remarks:   Continue convert by convert handler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_ProgressiveStatus Continue(FPD_Converter converter, FPD_ConverterHandler handler);
};


#ifdef __cplusplus
};
#endif

#endif
#ifndef FPD_MATHIMPL_H
#define FPD_MATHIMPL_H

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

#ifndef FPD_MATHEXPT_H
#include "../fpd_mathExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

class CFPD_LongImageEncoder_V16
{
public:
	//************************************
	// Function:  CreateLongImageEncoder	
	// Return:    FPD_LongImageEncoder         Return FPD_LongImageEncoder.
	// Remarks:  Create FPD_LongImageEncoder.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_LongImageEncoder CreateLongImageEncoder(FPD_LongImageEncoderCallbacks callbacks);

	//************************************
	// Function:  DeleteLongImageEncoder	
	// Param[in]: imageEncode		    The input FPD_LongImageEncoder.
	// Return:    void
	// Remarks:  Delete FPD_LongImageEncoder.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void DeleteLongImageEncoder(FPD_LongImageEncoder imageEncode);
};

class CFPD_LongImage_V16
{
public:
	//************************************
	// Function:  CreateLongImage	
	// Return:    FPD_LongImage         Return FPD_LongImage.
	// Remarks:  Create FPD_LongImage.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_LongImage CreateLongImage();

	//************************************
	// Function:  DeleteLongImage	
	// Param[in]: longImg		The input FPD_LongImage.
	// Return:    FPD_LongImage         Return FPD_LongImage.
	// Remarks:  Delete FPD_LongImage.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void DeleteLongImage(FPD_LongImage longImg);
	
	//************************************
	// Function:  AddPage
	// Param[in]: longImg		The input FPD_LongImage.
	// Param[in]: pPage		    The page that you want to add.
	// Param[in]: pAnnotList	The annot list of the page. If pAnnotList was nullptr,the class
	//                          would creat an inner annout list to render.
	// Param[in]: fDPI		    The display dpi of the page.
	// Return:    FPD_LongImageError  Return FPD_LongImageError if success, or error type if any error is found.
	// Remarks:   Add a page to dest long image. Call the function multiple times to add multiple
	//			  pages to dest long image.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_LongImageError AddPage(FPD_LongImage longImg, FPD_Page pPage, FPD_AnnotList pAnnotList, FS_FLOAT fDPI);
	
	 //************************************
	 // Function:  AddPage2
	 // Param[in]: longImg		The input FPD_LongImage.
	 // Param[in]: pDoc		    The document of the page that you want to add.
	 // Param[in]: pPageDict	The dictionary of the page that you want to add.
	 // Param[in]: fDPI		    The display dpi of the page.
	 // Return:    FPD_LongImageError  Return FPD_LongImageError if success, or error type if any error is found.
	 // Remarks:   Add a page to dest long image. Call the function multiple times to add multiple
	 //			  pages to dest long image.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	 //************************************
	static FPD_LongImageError AddPage2(FPD_LongImage longImg, FPD_Document pDoc, FPD_Object pPageDict, FS_FLOAT fDPI);
	
	 //************************************
	 // Function:  Output
	 // Param[in]: longImg		The input FPD_LongImage.
	 // Param[in]: pStream		The reuslt file stream.
	 // Param[in]: colorMode	The color mode of the dest long image.
	 // Param[in]: imageFormat	The image format of the dest long image.
	 // Param[in]: pAttribute	The attribute information of the dest long image.
	 // Return:    FPD_LongImageError  Return FPD_LongImageError if success, or error type if any error is found.
	 // Remarks:   Output the dest long image through a file stream.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	 //************************************
	static FPD_LongImageError Output(FPD_LongImage longImg, FS_FileStream pStream, FPD_ColorMode colorMode, FPD_ImageFormat imageFormat, FS_DIBAttribute pAttribute);

	//************************************
	 // Function:  Output2
	 // Param[in]: longImg		The input FPD_LongImage.
	 // Param[in]: colorMode	The color mode of the dest long image.
	 // Param[in]: pImageEncoder The output callback class.The class would encode the dest long	image.
	 // Return:    FPD_LongImageError  Return FPD_LongImageError if success, or error type if any error is found.
	 // Remarks:   Output the dest long image through a callback class.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	 //************************************
	static FPD_LongImageError Output2(FPD_LongImage longImg, FPD_ColorMode colorMode, FPD_LongImageEncoder pImageEncoder);
};

class CFPD_MathGraphics_V17
{
public:
	//************************************
	// Function:  GetGraphics		
	// Return:    FPD_MathGraphics
	// Remarks:  Get FPD_MathGraphics.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_MathGraphics GetGraphics();

	//************************************
	// Function:  Difference	
	// Param[in]: graphics		    The input FPD_MathGraphics.
	// Param[in]: path1		        The input object of FPD_Path.
	// Param[in]: path2		        The input object of FPD_Path.
	// Param[out]: differencePath	Get the difference of the two objects.
	// Param[in]: path1_fillmode	The input fill mode 1, default is FPDFILL_ALTERNATE.
	// Param[in]: path2_fillmode	The input fill mode 2, default is FPDFILL_ALTERNATE.
	// Return:    FS_BOOLEAN
	// Remarks:  Delete FPD_LongImageEncoder.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN Difference(FPD_MathGraphics graphics, FPD_Path path1,
		FPD_Path path2,
		FPD_Path* differencePath,
		FS_INT32 path1_fillmode,
		FS_INT32 path2_fillmode);

	//************************************
	// Function:  Intersection	
	// Param[in]: graphics		    The input FPD_MathGraphics.
	// Param[in]: path1		        The input object of FPD_Path.
	// Param[in]: path2		        The input object of FPD_Path.
	// Param[out]: differencePath	Get the difference of the two objects.
	// Param[in]: path1_fillmode	The input fill mode 1, default is FPDFILL_ALTERNATE.
	// Param[in]: path2_fillmode	The input fill mode 2, default is FPDFILL_ALTERNATE.
	// Param[in]: bIsClip	        Whether is clip.
	// Return:    FS_BOOLEAN
	// Remarks:  Delete FPD_LongImageEncoder.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN Intersection(FPD_MathGraphics graphics, FPD_Path path1,
		FPD_Path path2,
		FPD_Path* IntersectionPath,
		FS_INT32 path1_fillmode,
		FS_INT32 path2_fillmode,
		FS_BOOLEAN bIsClip);
};

class CFPD_MonoscaleBitmap_V18
{
public:
	//************************************
	// Function:  New
	// Param[in]: pAllocator		The input allocator.
	// Return:    FPD_MonoscaleBitmap
	// Remarks:   Create FPD_MonoscaleBitmap object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static FPD_MonoscaleBitmap New(FS_LPVOID pAllocator);

	//************************************
	// Function:  GetMonoscaleDitheringBitmap
	// Param[in]: monoscale		The input FS_Monoscale.
	// Return:    FPD_MonoscaleBitmap A new DIB bitmap object which is a mono Dithering one, the format is FXDIB_1bppRgb
	//			without palette.<br> Caller should call FPDMonoscaleBitmapRelease to destroy the returned object.
	// Remarks:   Get a whole mono Dithering bitmap to DIB source.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static FPD_MonoscaleBitmap	Get(FS_Monoscale monoscale);

	//************************************
	// Function:  Release
	// Param[in]: bitmap		The input FPD_MonoscaleBitmap.
	// Return:    void
	// Remarks:   Release the FPD_MonoscaleBitmap object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static void		Release(FPD_MonoscaleBitmap bitmap);

	//************************************
	// Function:  Create
	// Param[in]: monoscale		The input FS_Monoscale.
	// Param[in]: width		    The input width of bitmap.
	// Param[in]: height		The input height of bitmap.
	// Return:   FS_BOOLEAN
	// Remarks:   Create bitmap by specified size.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
	//************************************
	static FS_BOOLEAN		Create(FPD_MonoscaleBitmap bitmap, FS_INT32 width, FS_INT32 height);
};

#ifdef __cplusplus
};
#endif

#endif
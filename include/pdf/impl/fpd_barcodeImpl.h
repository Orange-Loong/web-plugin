#ifndef FPD_BARCODEIMPL_H
#define FPD_BARCODEIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifndef FPD_BARCODEEXPT_H
#include "../fpd_barcodeExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


	class CFPD_CBCCodeBase_V17
	{
	public:
		//************************************
		// Function:  Create	
		// Return:    void
		// Remarks:   Create FPD_CBCCodeBase obj.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FPD_BC_TYPE		GetType(FPD_CBCCodeBase code);

		//************************************
		// Function:  Encode
		// Param[in]: code		    The input FPD_CBCCodeBase.
		// Param[in]: contents		The input content need to encode.
		// Param[in]: isDevice		If it is device.
		// Param[out]: exception   	Get exception info.		
		// Param[out]: pOutWidth   	Get width value.
		// Param[out]: pOutHeight   Get height value.
		// Return:    void
		// Remarks:   Encode contents.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_BOOLEAN	 Encode(FPD_CBCCodeBase code, FS_LPCWSTR contents, FS_BOOLEAN isDevice, FS_INT32* exception, FS_INT32* pOutWidth, FS_INT32* pOutHeight);

		//************************************
		// Function:  RenderDevice
		// Param[in]: code		    The input FPD_CBCCodeBase.
		// Param[in]: device		The input FPD_RenderDevice.
		// Param[in]: matirx		The input matrix.
		// Param[out]: exception   	Get exception info.		
		// Return:    FS_BOOLEAN
		// Remarks:   Render device.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_BOOLEAN	 RenderDevice(FPD_CBCCodeBase code, FPD_RenderDevice device, const FS_AffineMatrix matrix, FS_INT32* exception);

		//************************************
		// Function:  RenderBitmap
		// Param[in]: code		    The input FPD_CBCCodeBase.
		// Param[out]: pOutBitmap	The input FPD_RenderDevice.	
		// Param[out]: exception   	Get exception info.		
		// Return:    FS_BOOLEAN
		// Remarks:   Render device.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_BOOLEAN	 RenderBitmap(FPD_CBCCodeBase code, FS_DIBitmap* pOutBitmap, FS_INT32* exception);

		//************************************
		// Function:  Decode
		// Param[in]: code		    The input FPD_CBCCodeBase.
		// Param[in]: buf	        The input FPD_RenderDevice.	
		// Param[in]: width   		The input width.	
		// Param[in]: height	    The input height.	
		// Param[out]: exception   	Get exception info.	
		// Param[out]: outDecode	Get the decode contents.	
		// Return:    void
		// Remarks:   Decode buffer.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static void Decode(FPD_CBCCodeBase code, FS_BYTE* buf, FS_INT32 width, FS_INT32 height, FS_INT32* exception, FS_WideString* outDecode);

		//************************************
		// Function:  Decode2
		// Param[in]: code		    The input FPD_CBCCodeBase.
		// Param[in]: pBitmap	    The input FPD_RenderDevice.	
		// Param[out]: exception   	Get exception info.			
		// Param[out]: outDecode	Get the decode contents.	
		// Return:    void
		// Remarks:   Decode bitmap.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static void Decode2(FPD_CBCCodeBase code, FS_DIBitmap pBitmap, FS_INT32* exception, FS_WideString* outDecode);

		//************************************
		// Function:  SetCharEncoding
		// Param[in]: code		    The input FPD_CBCCodeBase.
		// Param[in]: encoding	    The input char encoding, like FPD_BC_CHAR_ENCODING.	
		// Return:    FS_BOOLEAN
		// Remarks:   Set char encoding.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_BOOLEAN  SetCharEncoding(FPD_CBCCodeBase code, FS_INT32 encoding);

		//************************************
		// Function:  SetModuleHeight
		// Param[in]: code		    The input FPD_CBCCodeBase.
		// Param[in]: moduleHeight	The input module height.
		// Return:    FS_BOOLEAN
		// Remarks:   Set module height.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_BOOLEAN  SetModuleHeight(FPD_CBCCodeBase code, FS_INT32 moduleHeight);

		//************************************
		// Function:  SetModuleWidth
		// Param[in]: code		    The input FPD_CBCCodeBase.
		// Param[in]: moduleWidth	The input module width.
		// Return:    FS_BOOLEAN
		// Remarks:   Set module width.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_BOOLEAN  SetModuleWidth(FPD_CBCCodeBase code, FS_INT32 moduleWidth);

		//************************************
		// Function:  SetHeight
		// Param[in]: code		    The input FPD_CBCCodeBase.
		// Param[in]: height	    The input height.
		// Return:    FS_BOOLEAN
		// Remarks:   Set height.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_BOOLEAN  SetHeight(FPD_CBCCodeBase code, FS_INT32 height);

		//************************************
		// Function:  SetHeight
		// Param[in]: code		    The input FPD_CBCCodeBase.
		// Param[in]: height	    The input width.
		// Return:    FS_BOOLEAN
		// Remarks:   Set width.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_BOOLEAN  SetWidth(FPD_CBCCodeBase code, FS_INT32 width);

		//************************************
		// Function:  SetBackgroundColor
		// Param[in]: code		            The input FPD_CBCCodeBase.
		// Param[in]: backgroundColor	    The input background color.
		// Return:    void
		// Remarks:   Set background color.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static void     SetBackgroundColor(FPD_CBCCodeBase code, FS_ARGB backgroundColor);

		//************************************
		// Function:  SetBarcodeColor
		// Param[in]: code		            The input FPD_CBCCodeBase.
		// Param[in]: foregroundColor	    The input forground color.
		// Return:    void
		// Remarks:   Set barcode color.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static void     SetBarcodeColor(FPD_CBCCodeBase code, FS_ARGB foregroundColor);

		//************************************
		// Function:  FPD_CBCCodeBase
		// Param[in]: type		            The input FPD_BC_TYPE.		
		// Return:    FPD_CBCCodeBase
		// Remarks:   Create FPD_CBCCodeBase obj.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
		//************************************
		static FPD_CBCCodeBase Create(FPD_BC_TYPE type);

		//************************************
		// Function:  Delete
		// Param[in]: code		            The input FPD_CBCCodeBase.		
		// Return:    void
		// Remarks:   Delete FPD_CBCCodeBase obj.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.2.0.0
		//************************************
		static void Delete(FPD_CBCCodeBase code);
	};

	class CFPD_CBCDataMatrix_V17
	{
	public:

	};

	class CFPD_CBCPDF417I_V17
	{
	public:
		//************************************
		// Function:  SetIsXFABarcode
		// Param[in]: obj     	    The input FPD_CBCPDF417I.
		// Param[in]: bXFABarcode	Set if xfa barcode.		
		// Return:    void
		// Remarks:   Set if xfa barcode.		
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static void		SetIsXFABarcode(FPD_CBCCodeBase obj, const FS_BOOLEAN& bXFABarcode);

		//************************************
		// Function:  SetErrorCorrectionLevel
		// Param[in]: obj     	    The input FPD_CBCPDF417I.	
		// Param[in]: level     	The input error level.
		// Return:    FS_BOOLEAN
		// Remarks:  Set error correction level.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_BOOLEAN	SetErrorCorrectionLevel(FPD_CBCCodeBase obj, FS_INT32 level);

		//************************************
		// Function:  SetTruncated
		// Param[in]: obj     	    The input FPD_CBCPDF417I.	
		// Param[in]: truncated     Set if it's truncate.
		// Return:    FS_BOOLEAN
		// Remarks:  Set if it's truncate.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static void		SetTruncated(FPD_CBCCodeBase obj, FS_BOOLEAN truncated);
	};

	class CFPD_CBCQRCode_V17
	{
	public:
		//************************************
		// Function:  SetVersion
		// Param[in]: code     	    The input FPD_CBCQRCode.	
		// Param[in]: version     	The input version.	
		// Return:    FS_BOOLEAN
		// Remarks:   Set version.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_BOOLEAN	SetVersion(FPD_CBCCodeBase code, FS_INT32 version);

		//************************************
		// Function:  SetErrorCorrectionLevel
		// Param[in]: code     	    The input FPD_CBCQRCode.	
		// Param[in]: level     	The input error level.
		// Return:    FS_BOOLEAN
		// Remarks:   Set error correction level.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_BOOLEAN	SetErrorCorrectionLevel(FPD_CBCCodeBase code, FS_INT32 level);
	};

	class CFPD_CBCCode39_V21
	{
	public:
		static FPD_CBCCodeBase Create1(FS_BOOLEAN usingCheckDigit);
		static FPD_CBCCodeBase Create2(FS_BOOLEAN usingCheckDigit, FS_BOOLEAN extendedMode);
		static FS_BOOLEAN	SetTextLocation(FPD_CBCCodeBase code, FPD_BC_TEXT_LOC location);
		static FS_BOOLEAN	SetWideNarrowRatio(FPD_CBCCodeBase code, FS_INT32 ratio);
	};

	class CFPD_CBCCodebar_V21
	{
	public:
		static FS_BOOLEAN	SetStartChar(FPD_CBCCodeBase code, FS_CHAR start);
		static FS_BOOLEAN	SetEndChar(FPD_CBCCodeBase code, FS_CHAR end);
		static FS_BOOLEAN	SetTextLocation(FPD_CBCCodeBase code, FPD_BC_TEXT_LOC location);
		static FS_BOOLEAN	SetWideNarrowRatio(FPD_CBCCodeBase code, FS_INT32 ratio);
	};

	class CFPD_CBCCode128_V21
	{
	public:
		static FS_BOOLEAN	SetTextLocation(FPD_CBCCodeBase code, FPD_BC_TEXT_LOC location);
	};

	class CFPD_CBCOneCode_V21
	{
	public:
		static void	 SetPrintChecksum(FPD_CBCCodeBase code, FS_BOOLEAN checksum);
		static void	 SetDataLength(FPD_CBCCodeBase code, FS_INT32 length);
		static void	 SetCalChecksum(FPD_CBCCodeBase code, FS_BOOLEAN calc);
		static FS_BOOLEAN	SetFont(FPD_CBCCodeBase code, FPD_Font cFont);
		static void		SetFontSize(FPD_CBCCodeBase code, FS_FLOAT size);
		static void		SetFontStyle(FPD_CBCCodeBase code, FS_INT32 style);
		static void		SetFontColor(FPD_CBCCodeBase code, FS_ARGB color);
	};

#ifdef __cplusplus
};
#endif

#endif
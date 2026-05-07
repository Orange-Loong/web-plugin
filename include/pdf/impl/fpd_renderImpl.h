#ifndef FPD_RENDERIMPL_H
#define FPD_RENDERIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif


#include "../../../ExternalModule/fxcore/include/pdfwindow/fx_systemhandler.h"

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

class CFPD_CustomerOCContextHandler : public IPDF_OCContext, public CFX_Object
{
public:
	CFPD_CustomerOCContextHandler(FPD_OCContextCallBack OCContext);

    virtual FX_BOOL	CheckOCGVisible(const CPDF_Dictionary* pOCG);

    FX_BOOL CheckObjectVisible(const CPDF_GraphicsObject* pObj);

public:
	FPD_OCContextCallBack m_OCContext;
};

class CFPD_RenderOptions_V1
{	
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty page rendering options object.
	// Remarks:   Creates a new empty page rendering options object.
	// Notes:
	//************************************
	static FPD_RenderOptions New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: opts The input page rendering options object.
	// Return:    void
	// Remarks:   Destroys the page rendering options object.
	// Notes:
	//************************************
	static void	Destroy(FPD_RenderOptions opts);

	//************************************
	// Function:  GetColorMode
	// Param[in]: opts	The input page rendering options object.
	// Return:    The display mode code.
	// Remarks:   Gets display mode code.
	// Notes:
	//************************************
	static FS_INT32	GetColorMode(FPD_RenderOptions opts);

	//************************************
	// Function:  SetColorMode
	// Param[in]: opts			The input page rendering options object.
	// Param[in]: nClrMode		The new mode code.
	// Return:    void
	// Remarks:   Sets display mode code.
	// Notes:
	//************************************
	static void	SetColorMode(FPD_RenderOptions opts, FS_INT32 nClrMode);

	//************************************
	// Function:  GetBackColor
	// Param[in]: opts	The input page rendering options object.
	// Return:    The background color for gray mode (default: white).
	// Remarks:   Gets the background color for gray mode (default: white).
	// Notes:
	//************************************
	static FS_COLORREF GetBackColor(FPD_RenderOptions opts);

	//************************************
	// Function:  SetBackColor
	// Param[in]: opts		The input page rendering options object.
	// Param[in]: clr		Input the background color for gray mode (default: white).
	// Return:    void
	// Remarks:   Sets the background color for gray mode (default: white).
	// Notes:
	//************************************
	static void	SetBackColor(FPD_RenderOptions opts, FS_COLORREF clr);

	//************************************
	// Function:  GetForeColor
	// Param[in]: opts	The input page rendering options object.
	// Return:    The foreground color for gray mode (default: black).
	// Remarks:   Gets the foreground color for gray mode (default: black).
	// Notes:
	//************************************
	static FS_COLORREF GetForeColor(FPD_RenderOptions opts);

	//************************************
	// Function:  SetForeColor
	// Param[in]: opts		The input page rendering options object.
	// Param[in]: clr		Input the foreground color for gray mode (default: black).
	// Return:    void
	// Remarks:   Sets the foreground color for gray mode (default: black).
	// Notes:
	//************************************
	static void	SetForeColor(FPD_RenderOptions opts, FS_COLORREF clr);

	//************************************
	// Function:  GetRenderFlag
	// Param[in]: opts	The input page rendering options object.
	// Return:    The  render flags.
	// Remarks:   Gets render flags.
	// Notes:
	//************************************
	static FS_DWORD	GetRenderFlag(FPD_RenderOptions opts);

	//************************************
	// Function:  SetRenderFlag
	// Param[in]: opts			The input page rendering options object.
	// Param[in]: dwFlag		Input render flags.
	// Return:    void
	// Remarks:   Sets  render flags.
	// Notes:
	//************************************
	static void	SetRenderFlag(FPD_RenderOptions opts, FS_DWORD dwFlag);

	//************************************
	// Function:  GetAddtionalFlag
	// Param[in]: opts	The input page rendering options object.
	// Return:    The additional flags depending on the device.
	// Remarks:   Gets additional flags depending on the device.
	// Notes:
	//************************************
	static FS_DWORD	GetAddtionalFlag(FPD_RenderOptions opts);

	//************************************
	// Function:  SetAddtionalFlag
	// Param[in]: opts			The input page rendering options object.
	// Param[in]: dwFlag		Input additional flags depending on the device.
	// Return:    void
	// Remarks:   Sets additional flags depending on the device.
	// Notes:
	//************************************
	static void SetAddtionalFlag(FPD_RenderOptions opts, FS_DWORD dwFlag);
	
	//************************************
	// Function:  SetOCCHandler
	// Param[in]: opts			The input page rendering options object.
	// Param[in]: OCCHandler	Input optional content context handler.
	// Return:    void
	// Remarks:   Sets optional content context handler.
	// Notes:
	//************************************
	static void	SetOCCHandler(FPD_RenderOptions opts, FPD_OCContextHandler OCCHandler);

	//************************************
	// Function:  TranslateColor
	// Param[in]: opts		The input page rendering options object.
	// Param[in]: argb		The input color.
	// Return:    The translated color. 
	// Remarks:   Translates a color.
	// Notes:
	//************************************
	static FS_ARGB TranslateColor(FPD_RenderOptions opts, FS_ARGB argb);

	//************************************
	// Function:  CreateOCContextHandler
	// Param[in]: OCContext					The input page rendering options object.
	// Return:    FPD_OCContextHandler		Input optional content context handler.
	// Remarks:   Creates optional content context handler.
	// Notes:
	//************************************
	static FPD_OCContextHandler CreateOCContextHandler(FPD_OCContextCallBack OCContext);	

	//************************************
	// Function:  DeleteOCContextHandler
	// Param[in]: OCCHandler		Input optional content context handler to be deleted.
	// Return:    void
	// Remarks:   Deletes optional content context handler.
	// Notes:
	//************************************
	static void	DeleteOCContextHandler(FPD_OCContextHandler OCCHandler);

	//************************************
	// Function:  SetDocTextColor
	// Param[in]: OCCHandler		The input page rendering options object.
	// Param[in]: color     		The color of text color.
	// Return:    void
	// Remarks:   Set text color of the render options.
	// Notes:
	//************************************
	static void SetDocTextColor(FPD_RenderOptions opts, FS_COLORREF color);

	//************************************
	// Function:  GetDocTextColor
	// Param[in]: OCCHandler		The input page rendering options object.
	// Return:    FS_COLORREF       Get the text color of the render options.
	// Remarks:   Get text color of the render options.
	// Notes:
	//************************************
	static FS_COLORREF GetDocTextColor(FPD_RenderOptions opts);

	//************************************
	// Function:  SetCustomColorMode
	// Param[in]: OCCHandler		The input page rendering options object.
	// Param[in]: mode      		The custom color mode of the render options.
	// Return:    FS_COLORREF       Set the custom color mode of the render options.
	// Remarks:   Set the custom color mode of the render options.
	// Notes:
	//************************************
	static void SetCustomColorMode(FPD_RenderOptions opts, FS_DWORD mode);

	//************************************
	// Function:  GetCustomColorMode
	// Param[in]: OCCHandler		The input page rendering options object.	
	// Return:    FS_DWORD          Get the custom color mode of the render options.
	// Remarks:   Get the custom color mode of the render options.
	// Notes:
	//************************************
	static FS_DWORD GetCustomColorMode(FPD_RenderOptions opts);

	//************************************
	// Function:  TranslateColor2
	// Param[in]: opts		The input page rendering options object.
	// Param[in]: argb		The input color.
	// Param[in]: objType	The input obj type.
	// Return:    The translated color. 
	// Remarks:   Translates a color.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static FS_ARGB TranslateColor2(FPD_RenderOptions opts, FS_ARGB argb, FS_INT32 objType);
};

class CFPD_CustomerBackgroundDrawHandler:public IPDF_BackgroundDraw, public CFX_Object
{
public:

	CFPD_CustomerBackgroundDrawHandler(FPD_BackgroundDraw backgroundDraw);

	void	OnDrawBackground(CFX_RenderDevice* pBitmapDevice,const CFX_AffineMatrix* pOriginal2Bitmap);
private:
	FPD_BackgroundDraw m_backgroundDraw;
};

class CFPD_RenderContext_V1
{	
public:
	//************************************
	// Function:  New
	// Param[in]: page			The input page.
	// Param[in]: bFirstLayer	Whether it's the first layer.
	// Return:    A empty PDF rendering context object.
	// Remarks:   Creates a new PDF rendering context object.
	// Notes:
	//************************************
	static FPD_RenderContext New(FPD_Page page, FS_BOOL bFirstLayer);

	//************************************
	// Function:  New2
	// Param[in]: doc					The PDF document.
	// Param[in]: pageCache				The page render cache.
	// Param[in]: pageResources			The Resources dictionary.
	// Param[in]: bFirstLayer			Whether it's the first layer.
	// Return:    A new PDF rendering context object.
	// Remarks:   Creates a new PDF rendering context object.
	// Notes:
	//************************************
	static FPD_RenderContext New2(
		FPD_Document doc, 
		FPD_PageRenderCache pageCache, 
		FPD_Object pageResources,
		FS_BOOL bFirstLayer
		);

	//************************************
	// Function:  Destroy
	// Param[in]: context The input PDF rendering context object.
	// Return:    void
	// Remarks:   Destroys the PDF rendering context object.
	// Notes:
	//************************************
	static void	Destroy(FPD_RenderContext context);	
	
	//************************************
	// Function:  DrawStream
	// Param[in]: context			The input PDF rendering context object.
	// Param[out]: outDevice		The output device.
	// Param[in]: pStreamDataBuf	The page description stream buffer.
	// Param[in]: stream_size		The size in bytes of the page description stream. -1 for <a>NULL</a> terminated byte string.
	// Param[in]: displayMatrix		The matrix from stream coords to device coords. Can be <a>NULL</a> if no transformation needed.
	// Return:    void
	// Remarks:   Draws a page description stream.
	// Notes:
	//************************************
	static void DrawStream( 
		FPD_RenderContext context, 
		FPD_RenderDevice* outDevice, 
		const void* pStreamDataBuf, 
		FS_DWORD stream_size, 
		FS_AffineMatrix displayMatrix 
		);
	
	//************************************
	// Function:  AppendPage
	// Param[in]: context			The input PDF rendering context object.
	// Param[in]: objs				The input page.
	// Param[in]: object2Device		The matrix from object coords to device coords.
	// Return:    void
	// Remarks:   Append page to the current layer.
	// Notes:
	//************************************
	static void	AppendPage(
		FPD_RenderContext context, 
		FPD_Page objs,
		FS_AffineMatrix object2Device
		);

	//************************************
	// Function:  AppendForm
	// Param[in]: context			The input PDF rendering context object.
	// Param[in]: objs				The input Form
	// Param[in]: object2Device		The matrix from object coords to device coords
	// Return:    void
	// Remarks:   Append Form to the current layer.
	// Notes:
	//************************************
	static void	AppendForm(
		FPD_RenderContext context, 
		FPD_Form objs,
		FS_AffineMatrix object2Device
		);

	//************************************
	// Function:  SetBackground
	// Param[in]: context					The input PDF rendering context object.
	// Param[in]: BackgroundDrawHandler		The background drawing handler.
	// Return:    void
	// Remarks:   Sets custom background drawing.
	// Notes:
	//************************************
	static void	SetBackground(FPD_RenderContext context, FPD_BackgroundDrawHandler BackgroundDrawHandler);

	//************************************
	// Function:  CreateBackgroundDrawHandler
	// Param[in]: backgroundDraw	The input background drawing handler structure.
	// Return:    The background drawing handler.
	// Remarks:   Creates the background drawing handler.
	// Notes:
	//************************************
	static FPD_BackgroundDrawHandler CreateBackgroundDrawHandler(FPD_BackgroundDraw backgroundDraw);

	//************************************
	// Function:  DeleteBackgroundDrawHandler
	// Param[in]: backgroundDrawHandler		The input background drawing handler structure.
	// Return:    void
	// Remarks:   Deletes the background drawing handler.
	// Notes:
	//************************************
	static void	DeleteBackgroundDrawHandler(FPD_BackgroundDrawHandler backgroundDrawHandler);

	//************************************
	// Function:    Render	
	// Param[in]: context			The input PDF rendering context object.
	// Param[in]: device			The output device.
	// Param[in]: options			The render options.
	// Param[in]: pFinalMatrix		The final matrix to transform the result, Default value is <a>NULL</a>.
	// Return:    void
	// Remarks:   Do the real rendering. Optionally, rendering matrix can be modified by the last matrix.
	// Notes:    
	//************************************
	static void	Render(
		FPD_RenderContext context, 
		FPD_RenderDevice device, 
		const FPD_RenderOptions options, 
		FS_AffineMatrix* pFinalMatrix
		);

	//************************************
	// Function:  DrawPage
	// Param[in]: context			The input PDF rendering context object.
	// Param[out]:outDevice			The output device.
	// Param[in]: objs				The input page.
	// Param[in]: pObject2Device	The matrix from object coords to device coords, can be NULL.
	// Param[in]: options			The render options.
	// Return:    void
	// Remarks:   Draws a list of page objects.
	// Notes:
	//************************************
	static void DrawPage( 
		FPD_RenderContext context,
		FPD_RenderDevice* outDevice, 
		FPD_Page objs,
		FS_AffineMatrix* pObject2Device,
		const FPD_RenderOptions options 
		);

	//************************************
	// Function:  DrawForm
	// Param[in]: context			The input PDF rendering context object.
	// Param[out]:outDevice			The output device.
	// Param[in]: objs				The input Form.
	// Param[in]: pObject2Device	The matrix from object coords to device coords, can be NULL.
	// Param[in]: options			The render options.
	// Return:    void
	// Remarks:   Draws a list of page objects.
	// Notes:
	//************************************
	static void DrawForm( 
		FPD_RenderContext context,
		FPD_RenderDevice* outDevice, 
		FPD_Form objs,
		FS_AffineMatrix* pObject2Device,
		const FPD_RenderOptions options 
		);

	//************************************
	// Function:  QuickDraw
	// Param[in]: context		The input PDF rendering context object.
	// Param[out]:outDevice		The output device.
	// Return:    void
	// Remarks:   Draws a rough preview (quick draw).
	// Notes:
	//************************************
	static void QuickDraw(FPD_RenderContext context, FPD_RenderDevice* outDevice);

	//************************************
	// Function:  GetBackground
	// Param[in]: context				The input PDF rendering context object.
	// Param[out]:outBitmapBuffer		It receives the background bitmap.
	// Param[in]: obj					The input page object.
	// Param[in]: options				The render options.
	// Param[in]: pFinalMatrix			The matrix from object coords to device coords.
	// Return:    void
	// Remarks:   Gets background of a page object within the rendering context.
	// Notes:
	//************************************
	static void GetBackground( 
		FPD_RenderContext context,
		FS_DIBitmap* outBitmapBuffer, 
		const FPD_PageObject obj,
		const FPD_RenderOptions options,
		FS_AffineMatrix* pFinalMatrix 
		);

	//************************************
	// Function:  GetPageCache
	// Param[in]: context	The input PDF rendering context object.
	// Return:    The page render cache.
	// Remarks:   Gets the page render cache.
	// Notes:
	//************************************
	static FPD_PageRenderCache GetPageCache(FPD_RenderContext context);
};

class CFPD_ProgressiveRender_V1
{	
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty PDF progressive renderer object.
	// Remarks:   Creates a new empty PDF progressive renderer object.
	// Notes:
	//************************************
	static FPD_ProgressiveRender New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: render The input PDF progressive renderer object.
	// Return:    void
	// Remarks:   Destroys the PDF progressive renderer object.
	// Notes:
	//************************************
	static void	Destroy(FPD_ProgressiveRender render);

	
	//************************************
	// Function:  Start
	// Param[in]: render			The input PDF progressive renderer object.
	// Param[in]: context			The render context.
	// Param[in]: device			The output device.
	// Param[in]: options			The render options.
	// Param[in]: pauseHandler		The pause handler.
	// Return:    void
	// Remarks:   Starts rendering.
	// Notes:
	//************************************
	static void	Start(
		FPD_ProgressiveRender render, 
		FPD_RenderContext context, 
		FPD_RenderDevice* device, 
		const FPD_RenderOptions options, 
		FS_PauseHandler pauseHandler
		);

	//************************************
	// Function:  Continue
	// Param[in]: render			The input PDF progressive renderer object.
	// Param[in]: pauseHandler		The pause handler.
	// Return:    void
	// Remarks:   Continue rendering.
	// Notes:
	//************************************
	static void	Continue(FPD_ProgressiveRender render, FS_PauseHandler pauseHandler);
	
	//************************************
	// Function:  EstimateProgress
	// Param[in]: render	The input PDF progressive renderer object.
	// Return:    An estimated percentage of progress.
	// Remarks:   Estimates percentage of progress.
	// Notes:
	//************************************
	static FS_INT32	EstimateProgress(FPD_ProgressiveRender render);

	//************************************
	// Function:  Clear
	// Param[in]: render	The input PDF progressive renderer object.
	// Return:    void
	// Remarks:   Gets ready for next rendering.
	// Notes:
	//************************************
	static void	Clear(FPD_ProgressiveRender render);

	//************************************
	// Function:  GetStatus
	// Param[in]: render	The input PDF progressive renderer object.
	// Return:    void
	// Remarks:   Get the render status.
	// Notes:
	//************************************
	static FPDRenderStatus GetStatus(FPD_ProgressiveRender render);
};

class CFPD_RenderDevice_V1
{	
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty render device object.
	// Remarks:   Creates a new empty render device object.
	// Notes:
	//************************************
	static FPD_RenderDevice	New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: dc The input render device object.
	// Return:    void
	// Remarks:   Destroys the render device object.
	// Notes:
	//************************************
	static void	Destroy(FPD_RenderDevice dc);


	//************************************
	// Function:  StartRendering
	// Param[in]: dc	The input render device object.
	// Return:  Non-zero means success, otherwise failure.
	// Remarks: Starts rendering.
	// Notes: Called only once for each rendering job.
	//************************************
	static FS_BOOL StartRendering(FPD_RenderDevice dc);

	//************************************
	// Function:  EndRendering
	// Param[in]: dc	The input render device object.
	// Return:  Non-zero means success, otherwise failure.
	// Remarks: End rendering.
	// Notes: Called only once for each rendering job.
	//************************************
	static void EndRendering(FPD_RenderDevice dc);

	//************************************
	// Function:  SaveState
	// Param[in]: dc	The input render device object.
	// Return:  void
	// Remarks: Saves all graphic states.
	// Notes: 
	//************************************
	static void SaveState(FPD_RenderDevice dc);

	//************************************
	// Function:  RestoreState
	// Param[in]: dc				The input render device object.
	// Param[in]: bKeepSaved		Whether to keep the restored states saved in buffer.
	// Return:    void
	// Remarks: Restores all graphic states.
	// Notes: 
	//************************************
	static void	RestoreState(FPD_RenderDevice dc, FS_BOOL bKeepSaved);

	//************************************
	// Function:  GetWidth
	// Param[in]: dc	The input render device object.
	// Return:    The device width.
	// Remarks: Gets the device width.
	// Notes: 
	//************************************
	static FS_INT32 GetWidth(FPD_RenderDevice dc);

	//************************************
	// Function:  GetHeight
	// Param[in]: dc	The input render device object.
	// Return:  The device height.
	// Remarks: Gets the device height.
	// Notes: 
	//************************************
	static FS_INT32 GetHeight(FPD_RenderDevice dc);

	//************************************
	// Function:  GetBPP
	// Param[in]: dc	The input render device object.
	// Return:  The bits per pixel.
	// Remarks: Gets the bits per pixel.
	// Notes: 
	//************************************
	static FS_BOOL GetBPP(FPD_RenderDevice dc);

	//************************************
	// Function:  GetRenderCaps
	// Param[in]: dc	The input render device object.
	// Return:  The render capabilities.
	// Remarks: Gets the render capabilities.
	// Notes: 
	//************************************
	static FS_INT32 GetRenderCaps(FPD_RenderDevice dc);

	//************************************
	// Function:  GetDeviceCapsXY
	// Param[in]: dc	The input render device object.
	// Param[in]: id	The input device capability ID
	// Return:  The render capabilities.
	// Remarks: Gets the render capabilities.
	// Notes: 
	//************************************
	static FS_INT32 GetDeviceCapsXY(FPD_RenderDevice dc, FS_INT32 id);

	//************************************
	// Function:  GetBitmap
	// Param[in]: dc	The input render device object.
	// Return:  The bitmap of the device.
	// Remarks: Gets the bitmap of the device.
	// Notes: 
	//************************************
	static FS_DIBitmap GetBitmap(FPD_RenderDevice dc);

	//************************************
	// Function:  SetBitmap
	// Param[in]: dc		The input render device object.
	// Param[in]: bitmap	The input bitmap
	// Return:  void
	// Remarks: Sets the bitmap to the device.
	// Notes: 
	//************************************
	static void SetBitmap(FPD_RenderDevice dc, FS_DIBitmap bitmap);

	//************************************
	// Function:  SetPixel
	// Param[in]: dc				The input render device object.
	// Param[in]: x					The x-coordinate of the pixel.
	// Param[in]: y					The y-coordinate of the pixel.
	// Param[in]: argb				The color of the pixel.
	// Return: Non-zero means success, otherwise failure. 
	// Remarks: Sets or composite a pixel.
	// Notes: 
	//************************************
	static FS_BOOL SetPixel(FPD_RenderDevice dc, FS_INT32 x, FS_INT32 y, FS_ARGB argb);

	
	//************************************
	// Function:  SetClip_Rect
	// Param[in]: dc			The input render device object.
	// Param[in]: rect			The input clipping rectangle.
	// Return: Non-zero means success, otherwise failure. 
	// Remarks: Sets a clipping rectangle.
	// Notes: 
	//************************************
	static FS_BOOL SetClip_Rect(FPD_RenderDevice dc, const FS_Rect rect);

	//************************************
	// Function:  CreateCompatibleBitmap
	// Param[in]:     dc		The input render device object.	
	// Param[in,out]: inoutDIB	It receives the created bitmap data.
	// Param[in,out]: width		The bitmap width.
	// Param[in,out]: height	The bitmap height.
	// Return: Non-zero means success, otherwise failure. 
	// Remarks: Creates a compatible bitmap.
	// Notes: 
	//************************************
	static void CreateCompatibleBitmap(FPD_RenderDevice dc, FS_DIBitmap* inoutDIB, FS_INT32 width, FS_INT32 height);

	//************************************
	// Function:  FillRect
	// Param[in]:     dc		The input render device object.
	// Param[in,out]: pRect		The input rectangle
	// Param[in,out]: fill_argb	The color to fill.
	// Return: Non-zero means success, otherwise failure. 
	// Remarks: Fills a rectangle.
	// Notes: 
	//************************************
	static FS_BOOL FillRect(FPD_RenderDevice dc, const FS_Rect* pRect, FS_ARGB fill_argb);

	//************************************
	// Function:  DrawCosmeticLine
	// Param[in]: dc			The input render device object.
	// Param[in]: x1			The x-coordinate of the start point.
	// Param[in]: y1			The y-coordinate of the start point.
	// Param[in]: x2			The x-coordinate of the end point.
	// Param[in]: y2			The y-coordinate of the end point.
	// Param[in]: argb			The line color.
	// Return: Non-zero means success, otherwise failure. 
	// Remarks: Draws a single pixel (device dependent) line. 
	// Notes: 
	//************************************
	static FS_BOOL DrawCosmeticLine(FPD_RenderDevice dc, FS_FLOAT x1, FS_FLOAT y1, FS_FLOAT x2, FS_FLOAT y2, FS_ARGB argb);

	//************************************
	// Function:  GetDIBits
	// Param[in]: dc				The input render device object.
	// Param[out]: bitmap			It receives the loaded device buffer.
	// Param[in]: left				The x-coordinate in the device.
	// Param[in]: top				The y-coordinate in the device.
	// Return: Non-zero means success, otherwise failure. 
	// Remarks: Loads device buffer into a DIB. 
	// Notes: 
	//************************************
	static FS_BOOL GetDIBits(FPD_RenderDevice dc, FS_DIBitmap bitmap, FS_INT32 left, FS_INT32 top);

	//************************************
	// Function:  SetDIBits
	// Param[in]: dc				The input render device object.
	// Param[in]: bitmap			The input colored DIB.
	// Param[in]: left				The x-coordinate in the device.
	// Param[in]: top				The y-coordinate in the device.
	// Param[in]: blend_type		Blend mode.
	// Return: Non-zero means success, otherwise failure. 
	// Remarks: Outputs a colored DIB, pixel-to-pixel. 
	// Notes: When ARGB bitmap is specified, device capability <a>FSRC_ALPHA_IMAGE</a> or <a>FSRC_GET_BITS</a> is required.
	// When non-normal blending type is used, device capability <a>FSRC_BLEND_MODE</a> or <a>FSRC_GET_BITS</a> is required.
	//************************************
	static FS_BOOL SetDIBits(FPD_RenderDevice dc, const FS_DIBitmap bitmap, FS_INT32 left, FS_INT32 top, FS_INT32 blend_type);

	//************************************
	// Function:  StretchDIBits
	// Param[in]: dc				The input render device object.
	// Param[in]: bitmap			The input colored DIB.
	// Param[in]: left				The x-coordinate in the device.
	// Param[in]: top				The y-coordinate in the device.
	// Param[in]: dest_width		The destinate width in the device.
	// Param[in]: dest_height		The destinate height in the device.
	// Param[in]: flags				The stretching flags.
	// Return: Non-zero means success, otherwise failure. 
	// Remarks: Stretches a colored DIB onto the device. 
	// Notes: When ARGB bitmap is specified, device capability <a>FSRC_ALPHA_IMAGE</a> or <a>FSRC_GET_BITS</a> is required.
	//************************************
	static FS_BOOL StretchDIBits(FPD_RenderDevice dc, const FS_DIBitmap bitmap, FS_INT32 left, FS_INT32 top, FS_INT32 dest_width, FS_INT32 dest_height,
						FS_DWORD flags);

	//************************************
	// Function:  SetBitMask
	// Param[in]: dc				The input render device object.
	// Param[in]: bitmap			The inpput mask.
	// Param[in]: left				The x-coordinate in the device.
	// Param[in]: top				The y-coordinate in the device.
	// Param[in]: argb				The color to be masked.
	// Return: Non-zero means success, otherwise failure. 
	// Remarks: Outputs masked bitmap. The bitmap can be a monochrome bitmask, or a 8-bit alpha mask.
	// Notes: If the mask is monochrome, device capability <a>FSRC_BIT_MASK</a> or <a>FSRC_GET_BITS</a> is required.
	//        If the mask is an alpha mask, device capability <a>FSRC_ALPHA_MAS>K</a or <a>FSRC_GET_BITS</a> is required.
	//************************************
	static FS_BOOL SetBitMask(FPD_RenderDevice dc, const FS_DIBitmap bitmap, FS_INT32 left, FS_INT32 top, FS_ARGB argb);


	//************************************
	// Function:  StretchBitMask
	// Param[in]: dc				The input render device object.
	// Param[in]: bitmap			The inpput mask.
	// Param[in]: left				The x-coordinate in the device.
	// Param[in]: top				The y-coordinate in the device.
	// Param[in]: dest_width		The destinate width in the device.
	// Param[in]: dest_height		The destinate height in the device.
	// Param[in]: argb				The color to be masked.
	// Param[in]: flags				The stretching flags.
	// Return: Non-zero means success, otherwise failure. 
	// Remarks: Outputs masked bitmap. The bitmap can be a monochrome bitmask, or a 8-bit alpha mask.
	// Notes: If the mask is monochrome, device capability <a>FSRC_BIT_MASK</a> or <a>FSRC_GET_BITS</a> is required.
	//        If the mask is an alpha mask, device capability <a>FSRC_ALPHA_MASK</a> or <a>FSRC_GET_BITS</a> is required.
	//************************************
	static FS_BOOL StretchBitMask(FPD_RenderDevice dc, const FS_DIBitmap bitmap, FS_INT32 left, FS_INT32 top, FS_INT32 dest_width, FS_INT32 dest_height, 
						FS_ARGB argb, FS_DWORD flags);

	
	//************************************
	// Function:  GetDitherBits
	// Param[in]: dc	The input render device object.
	// Return:    The dither bits.
	// Remarks:   Gets the dither bits.
	// Notes:
	//************************************
	static FS_INT32	GetDitherBits(FPD_RenderDevice dc);
	
	//************************************
	// Function:  DrawTextString
	// Param[in]: dc		The input render device object.
	// Param[in]: left		x position, in device coordinate.
	// Param[in]: top		y position, in device coordinate.
	// Param[in]: font		The input font.
	// Param[in]: height	height of the character cell, in pixels.
	// Param[in]: str		a string using font encoding.
	// Param[in]: argb		color and alpha value, in 0xaarrggbb format.
	// Return:    void
	// Remarks:   Draws a text string, using Windows style parameters.
	// Notes:
	//************************************
	static void	DrawTextString(
		FPD_RenderDevice dc,
		FS_INT32 left,
		FS_INT32 top,
		FPD_Font font,	
		FS_INT32 height,
		FS_LPCSTR str,
		FS_ARGB argb
		);
	
	//************************************
	// Function:  DrawTextString2
	// Param[in]: dc			The input render device object.
	// Param[in]: originX		x position of the origin (for first character), in device coord.
	// Param[in]: originY		y position of the origin (for first character), in device coord.
	// Param[in]: font			The font will be used to draw text.
	// Param[in]: fontSize		number of points for the font em square.
	// Param[in]: matrix		a matrix from text space to device space, used for font rotation,
	//                          scaling and skewing. Can be NULL for identity matrix.
	//                          If specified, the "e" and "f" coefficients (for translation) are ignored.
	// Param[in]: str			a string using font encoding.
	// Param[in]: fillArgb		color and alpha value, in 0xaarrggbb format. 0 for not filling.
	// Param[in]: strokeArgb	color for stroking text. 0 for not stroking.
	// Param[in]: graphState	required for stroking.
	// Param[in]: opts			rendering options, like clear-type flag.
	// Return:    void
	// Remarks:	  Draws a text string using PDF style parameters.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void DrawTextString2( 
		FPD_RenderDevice dc, 
		FS_FLOAT originX, 
		FS_FLOAT originY, 
		FPD_Font font, 
		FS_FLOAT fontSize,
		FS_AffineMatrix matrix,
		FS_ByteString str, 
		FS_ARGB fillArgb, 
		FS_ARGB strokeArgb,
		const FPD_GraphState graphState,
		const FPD_RenderOptions opts 
		);
	
	//************************************
	// Function:  DrawTextPath
	// Param[in]: dc				The input render device object.
	// Param[in]: nChars			The number of characters in the text.
	// Param[in]: pCharCodesBuf		The character codes.
	// Param[in]: pCharPosBuf		The character positions.

	// Param[in]: font				The font will be used to draw text.
	// Param[in]: fontSize			The font size.
	// Param[in]: text2User			The matrix from text coordinate to user coordinate.
	// Param[in]: user2Device		The matrix from user coordinate  to user coordinate.
	// Param[in]: graphState		Graphic state, for pen attributes.
	// Param[in]: fillArgb			Fill color.
	// Param[in]: strokeArgb		Stroke color
	// Param[in]: clippingPath		The clipping path to add to.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Draws text path.
	// Notes:
	//************************************
	static FS_BOOL DrawTextPath( 
		FPD_RenderDevice dc, 
		FS_INT32 nChars, 
		FS_DWORD* pCharCodesBuf, 
		FS_FLOAT* pCharPosBuf, 
		FPD_Font font, 
		FS_FLOAT fontSize, 
		FS_AffineMatrix text2User, 
		FS_AffineMatrix user2Device,
		const FPD_GraphState graphState, 
		FS_ARGB fillArgb, 
		FS_ARGB strokeArgb,
		FPD_Path clippingPath 
		);

	//************************************
	// Function:    DrawNormalText
	// Param[in]: dc				The input render device object.
	// Param[in]: nChars			The number of characters in the text.
	// Param[in]: pCharCodesBuf		The character codes.
	// Param[in]: pCharPosBuf		The character positions.
	// Param[in]: font				The font will be used to draw text.
	// Param[in]: fontSize			The font size.
	// Param[in]: text2Device		The matrix from text coordinate to device coordinate.
	// Param[in]: fillArgb			The fill color used to fill the text.
	// Param[in]: opts				The render options.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Draws normal text.
	// Notes:
	//************************************
	static FS_BOOL DrawNormalText(
		FPD_RenderDevice dc, 
		FS_INT32 nChars, 
		FS_DWORD* pCharCodesBuf,
		FS_FLOAT* pCharPosBuf, 
		FPD_Font font,
		FS_FLOAT fontSize, 
		FS_AffineMatrix text2Device,
		FS_ARGB fillArgb,
		const FPD_RenderOptions opts
		);

	//************************************
	// Function:  DrawType3Text
	// Param[in]: dc				The input render device object.
	// Param[in]: pContext			The input render context.
	// Param[in]: pOptions			The input render options.
	// Param[in]: pStates1			The input graphic states.
	// Param[in]: nChars			The number of characters in the text.
	// Param[in]: pCharCodesBuf		The character codes.
	// Param[in]: pCharPosBuf		The character positions.
	// Param[in]: font				The Type3 font will be used to draw text.
	// Param[in]: fontSize			The font size.
	// Param[in]: pTextToDevice		The pointer of  matrix from text coordinate to device coordinate.
	// Param[in]: fillArgb			The fill color use to fill the text.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Draws type3 text.
	// Notes:
	//************************************
	static FS_BOOL DrawType3Text( 
		FPD_RenderDevice dc,
		FPD_RenderContext pContext,
		FPD_RenderOptions pOptions,
		FPD_PageObject pStates1,
		FS_INT32 nChars, 
		FS_DWORD* pCharCodesBuf, 
		FS_FLOAT* pCharPosBuf, 
		FPD_Font font, 
		FS_FLOAT fontSize, 
		FS_AffineMatrix* pTextToDevice, 
		FS_ARGB fillArgb 
		);

	//************************************
	// Function:  DrawPath
	// Param[in]: dc				The input render device object.
	// Param[in]: path				Path info.
	// Param[in]: pObject2Device	Optional transformation.
	// Param[in]: graphState		Graphic state, for pen attributes.
	// Param[in]: fill_color		Fill color.
	// Param[in]: stroke_color		Stroke color.
	// Param[in]: fill_mode			Fill mode, FSFILL_WINDING or FSFILL_ALTERNATE. 0 for not filled. Also FSFILL_FULLCOVER or FSFILL_RECT_AA bit can be used with fill mode.
	// Param[in]: bAntiAlias		This param has beed deprecated, false can be set in by default. 
	// Param[in]: alpha_flag		The flag indicates color type and alpha value, each components 8 bits.
	// alpha_flag == (stroke_alpha<<16)|(color_type<<8)|fill_alpha
	// color type: 0 for rgb, 1 for cmyk
	// Param[in]: pIccTransform		The color transform handle.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:   Draw a path. If either <param>fill_argb</param> or <param>stroke_argb</param> is used and with 
	// alpha value between 0 and 255, then device capability FSRC_ALPHA_PATH or FSRC_GET_BITS is required.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL DrawPath(
						FPD_RenderDevice dc,
						FPD_Path path,
						FS_AffineMatrix pObject2Device,
						FPD_GraphState graphState,
						FS_DWORD fill_color,
						FS_DWORD stroke_color,
						FS_INT32 fill_mode,
						FS_BOOL bAntiAlias,
						FS_INT32 alpha_flag,
						void* pIccTransform
						);

	//************************************
	// Function:  SetClip_PathFill
	// Param[in]: dc				The input render device object.
	// Param[in]: path				The input path info.
	// Param[in]: pObject2Device	Optional transformation.
	// Param[in]: fill_mode			Fill mode, <a>FSFILL_WINDING</a> or <a>FSFILL_ALTERNATE</a>.
	// Return:    Non-zero means success, otherwise failure.
	// Remarks:	  Set clipping path using filled region.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL SetClip_PathFill(FPD_RenderDevice dc,
						FPD_Path path,
						FS_AffineMatrix pObject2Device,
						FS_INT32 fill_mode
						);

    //************************************
    // Function:  SetClip_PathFill2
    // Param[in]: dc				The input render device object.
    // Param[in]: path				The input path info.
    // Param[in]: fill_mode			Fill mode, <a>FSFILL_WINDING</a> or <a>FSFILL_ALTERNATE</a>.
    // Return:    Non-zero means success, otherwise failure.
    // Remarks:	  Set clipping path using filled region.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 1.0
    //************************************
    static FS_BOOL SetClip_PathFill2(FPD_RenderDevice dc,
                        FPD_Path path,
                        FS_INT32 fill_mode
                        );

	//************************************
	// Function:  GetMatrix
	// Param[in]: dc				The input render device object.
	// Return:    FS_AffineMatrix
	// Remarks:	  Get current transform matrix to device.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static FS_AffineMatrix GetMatrix(FPD_RenderDevice dc);
};

class CFPD_FxgeDevice_V1
{	
public:

	//************************************
	// Function: New
	// Return:   A new empty GE rendering device object.
	// Remarks:  Creates a new empty GE rendering device object.
	// Notes:
	//************************************
	static FPD_RenderDevice	New();

	//************************************
	// Function:  Create
	// Param[in]: dc			The input GE rendering device object.
	// Param[in]: width			The bitmap width.
	// Param[in]: height		The bitmap height
	// Param[in]: format		The bitmap format.
	// Param[in]: ditherBits	The optional dithering bits. 0 for no dithering
	// Return:   void
	// Remarks:	  Creates a new bitmap and attach to this device. 
	// Notes:     The bitmap will be destroyed when the device destructs.
	//************************************
	static void Create(FPD_RenderDevice dc, FS_INT32 width, FS_INT32 height, FS_DIB_Format format, FS_INT32 ditherBits);

	//************************************
	// Function:  Destroy
	// Param[in]: dc	The input GE rendering device object.
	// Return:    void
	// Remarks:   Destroys the GE rendering device object.
	// Notes:
	//************************************
	static void	Destroy(FPD_RenderDevice dc);

	//************************************
	// Function:  Attach
	// Param[in]: dc			The input GE rendering device object.
	// Param[in]: bitmap		The input bitmap to be attached.
	// Param[in]: ditherBits	The input dither bits.
	// Return:    void
	// Remarks:   Attach a bitmap.
	// Notes:
	//************************************
	static void Attach(FPD_RenderDevice dc, FS_DIBitmap bitmap, FS_INT32 ditherBits);
};

class CFPD_WindowsDevice_V1
{	
public:
	//************************************
	// Function:  New
	// Param[in]: windowsDC The input Windows device.
	// Return:    A new empty Windows rendering device object.
	// Remarks:   Creates a new empty Windows device object.
	// Notes:
	//************************************
	static FPD_RenderDevice New(void* windowsDC);

	//************************************
	// Function:  Destroy
	// Param[in]: dc	The input PDF Windows device object.
	// Return:    void
	// Remarks:   Destroys the PDF Windows device object.
	// Notes:
	//************************************
	static void	Destroy(FPD_RenderDevice dc);

	//************************************
	// Function:  GetDC
	// Param[in]: dc	The input PDF Windows device object.
	// Return:    void* The PDF Windows device object.
	// Remarks:   Get the PDF Windows device object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.2
	//************************************
	static void* GetDC(FPD_RenderDevice dc);
};

class CFPD_PageRenderCache_V1
{	
public:
	//************************************
	// Function:  New
	// Param[in]: page	The input PDF page.
	// Return:    A new empty page rendering cache object.
	// Remarks:   Creates a new empty page rendering cache object.
	// Notes:
	//************************************
	static FPD_PageRenderCache New(FPD_Page page);

	//************************************
	// Function:  Destroy
	// Param[in]: cache The input page rendering cache object.
	// Return:    void
	// Remarks:   Destroys the page rendering cache object.
	// Notes:
	//************************************
	static void	Destroy(FPD_PageRenderCache cache);
	
	//************************************
	// Function:  ClearAll
	// Param[in]: cache	The input page rendering cache object.
	// Return:    void
	// Remarks:   Clears all items in the cache.
	// Notes:
	//************************************
	static void	ClearAll(FPD_PageRenderCache cache);

	//************************************
	// Function:  ClearImageData
	// Param[in]: cache	The input page rendering cache object.
	// Return:    void
	// Remarks:   Clears image data.
	// Notes:
	//************************************
	static void	ClearImageData(FPD_PageRenderCache cache);	
	
	//************************************
	// Function:  EstimateSize
	// Param[in]: cache	The input page rendering cache object.
	// Return:    Estimated size of the total cache.
	// Remarks:   Gets estimated size of the total cache.
	// Notes:     The application can use some strategy for dispense page caches according the memory size they occupy.
	//************************************
	static FS_DWORD	EstimateSize(FPD_PageRenderCache cache);

	//************************************
	// Function:   GetCachedBitmap
	// Param[in]:  cache			The input page rendering cache object.
	// Param[in]:  stream			The stream of the bitmap.
	// Param[out]: outBitmap		It retrieves the bitmap.
	// Param[out]: outMask			It retrieves the mask.	
	// Param[out]: outMatteColor	It retrieves the matte color.
	// Return:     void
	// Remarks:    Gets cached items
	// Notes:
	//************************************
	static void GetCachedBitmap( 
		FPD_PageRenderCache cache,
		FPD_Object stream,
		FS_DIBitmap* outBitmap,
		FS_DIBitmap* outMask, 
		FS_DWORD* outMatteColor
		);

	//************************************
	// Function:  ResetBitmap
	// Param[in]: cache		The input page rendering cache object.
	// Param[in]: stream	The stream of the bitmap.
	// Param[in]: bitmap	Input the bitmap.
	// Return:    void
	// Remarks:	  Resets the image cache or force the cache to be expired
	// Notes:
	//************************************
	static void ResetBitmap(FPD_PageRenderCache cache, FPD_Object stream, const FS_DIBitmap bitmap);

	static void CalcBitmapMargin(FS_LPCBYTE pDIBBuffer, FS_DIB_Format dibFormat, FS_INT32 width, FS_INT32 height, FS_INT32 stride, FS_INT32 flag, FS_DWORD backColor, FS_INT32 windowSize, FS_INT32 tolerance, FS_FloatRect* rtMargin);
};


class CFPD_WinBitmapDevice_V14
{
public:
	//************************************
	// Function:  New
	// Param[in]:width   The bitmap width.
	// Param[in]:height  The bitmap height.
	// Param[in]:format  The bitmap format.
	// Return:    A new empty Windows Bitmap Device object.
	// Remarks:   Creates a new empty Windows Bitmap Device object.
	// Notes:
	//************************************
	static FPD_WinBitmapDevice New(FS_INT32 width, FS_INT32 height, FS_DIB_Format format);

	//************************************
	// Function:  Destroy
	// Param[in]: dc	The input Windows Bitmap Device object.
	// Return:    void
	// Remarks:   Destroys the Windows Bitmap Device object.
	// Notes:
	//************************************
	static void	Destroy(FPD_WinBitmapDevice dc);

	//************************************
	// Function:  GetDC
	// Param[in]: dc	The input Windows Bitmap Device object.
	// Return:    void* The Windows Bitmap object.
	// Remarks:   Get the Windows Bitmap object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.2
	//************************************
	static void* GetDC(FPD_WinBitmapDevice dc);

	//************************************
	// Function:  CastToRenderDevice
	// Param[in]: dc	The input Windows Bitmap Device object.
	// Return:    FPD_RenderDevice   Cast to FPD_RenderDevice object.
	// Remarks:   Cast to FPD_RenderDevice object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0
	//************************************
	static FPD_RenderDevice CastToRenderDevice(FPD_WinBitmapDevice dc);
};

class CFPD_CPWLPluginInterface
{
public:
	virtual void DrawThisAppearanceInternal(CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device, FX_BOOL bBaseFun) =0;
	virtual void CreateInternal(const window::PWL_CREATEPARAM& cp, FX_BOOL bBaseFun)= 0;
};


class CFPD_CPWLImageHandler : public window::CPWL_Image, public CFPD_CPWLPluginInterface
{
public:
	CFPD_CPWLImageHandler(FPD_CPWLImageCallbacksRec*  callback);
	virtual ~CFPD_CPWLImageHandler();

	virtual CFX_ByteString GetImageAppStream();
	virtual void GetScale(FX_FLOAT& fHScale, FX_FLOAT& fVScale);
	virtual void GetImageOffset(FX_FLOAT& x, FX_FLOAT& y);
	virtual CPDF_Stream* GetPDFStream();
	virtual void DrawThisAppearance(CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device);
	virtual void DrawChildAppearance(CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device);
	virtual void  Create(const window::PWL_CREATEPARAM& cp);

	CFX_ByteString GetImageAppStreamInternal(FX_BOOL bBaseFun);
	void GetScaleInternal(FX_FLOAT& fHScale, FX_FLOAT& fVScale, FX_BOOL bBaseFun);
	void GetImageOffsetInternal(FX_FLOAT& x, FX_FLOAT& y, FX_BOOL bBaseFun);
	CPDF_Stream* GetPDFStreamInternal(FX_BOOL bBaseFun);
	void DrawThisAppearanceInternal(CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device, FX_BOOL bBaseFun);
	void DrawChildAppearanceInternal(CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device, FX_BOOL bBaseFun);
	void CreateInternal(const window::PWL_CREATEPARAM& cp, FX_BOOL bBaseFun);

	FPD_CPWLImageCallbacksRec m_callback;
};



class CFPD_CPWLImage_V14
{
public:
	static FPD_CPWL_Image New(FPD_CPWLImageCallbacks callbacks);
	static void  Delete(FPD_CPWL_Image img);
	static void GetImageAppStream(FPD_CPWL_Image img, FS_ByteString* bsStream, FS_BOOLEAN bBaseFun);
	static void GetScale(FPD_CPWL_Image img, FS_FLOAT* fHScale, FS_FLOAT* fVScale, FS_BOOLEAN bBaseFun);
	static void GetImageOffset(FPD_CPWL_Image img, FS_FLOAT* x, FS_FLOAT* y, FS_BOOLEAN bBaseFun);
	static FPD_Object GetPDFStream(FPD_CPWL_Image img, FS_BOOLEAN bBaseFun);
	static void SetPDFStream(FPD_CPWL_Image img, FPD_Object pStream);
	static void GetImageSize(FPD_CPWL_Image img, FS_FLOAT* fWidth, FS_FLOAT* fHeight);
	static void GetImageMatrix(FPD_CPWL_Image img, FS_AffineMatrix* outMatrix);
	static void GetImageAlias(FPD_CPWL_Image img, FS_ByteString* bsAlias);
	static void SetImageAlias(FPD_CPWL_Image img, FS_LPCSTR sImageAlias);
	static FPD_CPWL_Wnd GetCPWLWnd(FPD_CPWL_Image img);
	static void DrawThisAppearance(FPD_CPWL_Image img, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device, FS_BOOLEAN bBaseFun);
	static void DrawChildAppearance(FPD_CPWL_Image img, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device, FS_BOOLEAN bBaseFun);
	static FPD_CPWL_Image New2();
};

class CFPD_CPWLLabelHandler : public window::CPWL_Label, public CFPD_CPWLPluginInterface
{
public:
	CFPD_CPWLLabelHandler(FPD_CPWLLabelCallbacksRec* callback);
	virtual ~CFPD_CPWLLabelHandler();

	virtual CFX_ByteString GetClassNamePWL();
	virtual void SetFontSize(FX_FLOAT fFontSize);
	virtual FX_FLOAT GetFontSize();
	virtual void SetDirectionRTL(FX_BOOL bRTL,FX_BOOL bApplyAllSection,	FX_BOOL bAddUndo);
	virtual void OnCreated();
	virtual void DrawThisAppearance(CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device);
	virtual void GetThisAppearanceStream(CFX_ByteTextBuf& sAppStream,
		edit::CFX_EditFontArray* fontindexlist = nullptr,
		FX_BOOL bEmbedded = false);
	virtual void RePosChildWnd();
	virtual void Create(const window::PWL_CREATEPARAM& cp);

	CFX_ByteString GetClassNamePWLInternal(FX_BOOL bBaseFun);
	void SetFontSizeInternal(FX_FLOAT fFontSize, FX_BOOL bBaseFun);
	FX_FLOAT GetFontSizeInternal(FX_BOOL bBaseFun);
	void SetDirectionRTLInternal(FX_BOOL bRTL, FX_BOOL bApplyAllSection, FX_BOOL bAddUndo, FX_BOOL bBaseFun);
	void OnCreatedInternal(FX_BOOL bBaseFun);
	void DrawThisAppearanceInternal(CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device, FX_BOOL bBaseFun);	
	void RePosChildWndInternal(FX_BOOL bBaseFun);
	void SetParamByFlag();
	void CreateInternal(const window::PWL_CREATEPARAM& cp, FX_BOOL bBaseFun);

	FPD_CPWLLabelCallbacksRec m_callback;
};


class CFPD_CPWLLabel_V14
{
public:
	static FPD_CPWL_Label New(FPD_CPWLLabelCallbacks callback);
	static void  Delete(FPD_CPWL_Label label);
	static void GetClassNamePWL(FPD_CPWL_Label label, FS_ByteString* bsPWL, FS_BOOLEAN bBaseFun);
	static void SetFontSize(FPD_CPWL_Label label, FS_FLOAT fFontSize, FS_BOOLEAN bBaseFun);
	static FS_FLOAT GetFontSize(FPD_CPWL_Label label, FS_BOOLEAN bBaseFun);
	static void SetDirectionRTL(FPD_CPWL_Label label, FS_BOOL bRTL, FS_BOOL bApplyAllSection, FS_BOOL bAddUndo, FS_BOOLEAN bBaseFun);
	static void SetText(FPD_CPWL_Label label, FS_LPCWSTR csText);
	static void GetText(FPD_CPWL_Label label, FS_WideString* wsText);
	static void SetLimitChar(FPD_CPWL_Label label, FS_INT32 nLimitChar);
	static void SetHorzScale(FPD_CPWL_Label label, FS_INT32 nHorzScale);
	static void SetCharSpace(FPD_CPWL_Label label, FS_FLOAT fCharSpace);
	static FS_FloatRect GetContentRect(FPD_CPWL_Label label);
	static FS_INT32 GetTotalWords(FPD_CPWL_Label label);
	static void GetTextAppearanceStream(FPD_CPWL_Label label, const FS_FloatPoint ptOffset, FR_EDIT_FontData* outFontDataArray, FS_INT32* outFontDataArrayCount, FS_BOOL bEmbedded, FS_ByteString* bsStream);
	static void DrawPrintAppearance(FPD_CPWL_Label label, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device, FS_FloatRect popupRect);
	static FR_Edit GetEdit(FPD_CPWL_Label label);
	static FPD_CPWL_Wnd GetCPWLWnd(FPD_CPWL_Label label);
	static void OnCreated(FPD_CPWL_Label label, FS_BOOLEAN bBaseFun);
	static void DrawThisAppearance(FPD_CPWL_Label label,FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device, FS_BOOLEAN bBaseFun);
	static void GetThisAppearanceStream(FPD_CPWL_Label label, FS_ByteString* sAppStream,
		FR_EDIT_FontData* outFontDataArray, FS_INT32* outFontDataArrayCount,
		FS_BOOLEAN bEmbedded);
	static void RePosChildWnd(FPD_CPWL_Label label, FS_BOOLEAN bBaseFun);
	static void SetParamByFlag(FPD_CPWL_Label label);
	static FPD_CPWL_Label New2();
	static void SetRichTextByXML(FPD_CPWL_Label label, FS_LPCWSTR xml, FS_LPCWSTR ds,FS_INT32 charset, FS_BOOLEAN bAutoSetAgin, FS_BOOLEAN bSimulateBold);
};

class CFPD_CPWLTimerHandler : public window::CPWL_TimerHandler
{
public:
    CFPD_CPWLTimerHandler(FPD_CPWLTimerHandlerCallbacksRec* callback);

    virtual void TimerProc();
	virtual window::IFX_SystemHandler* GetSystemHandler() const;

	FPD_CPWLTimerHandlerCallbacksRec m_callback;
};

class CFPD_CPWLTimerHandler_V14
{
public:
	static FPD_CPWL_TimerHandler New(FPD_CPWLTimerHandlerCallback callbacks);
	static void Destroy(FPD_CPWL_TimerHandler handler);
	static void BeginTimer(FPD_CPWL_TimerHandler handler,FS_INT32 nElapse);
	static void EndTimer(FPD_CPWL_TimerHandler handler);
};

class CFPD_CPWLFocusHandler : window::IPWL_FocusHandler
{
public:
    CFPD_CPWLFocusHandler(FPD_CPWLFoucsHandlerCallbacksRec* callback);
    virtual void OnSetFocus(window::CPWL_Wnd* pWnd);
    virtual void OnKillFocus(window::CPWL_Wnd* pWnd);

    FPD_CPWLFoucsHandlerCallbacksRec m_callback;
};

class CFPD_CPWLFocusHandler_V14
{
public:
	static FPD_CPWL_FocusHandler New(FPD_CPWLFoucsHandlerCallback callbacks);
	static void Destroy(FPD_CPWL_FocusHandler handler);
};

class CFPD_CPWLProviderHandler : window::IPWL_Provider
{
public:
    CFPD_CPWLProviderHandler(FPD_CPWLProviderCallbacksRec* callback);
    virtual CPDF_Matrix GetWindowMatrix(void* pAttachedData);
    virtual CFX_WideString LoadPopupMenuString(FX_INT32 nIndex);
    virtual void AddSubMenu(window::FX_HMENU pPopup, window::CPWL_Edit* pEdit);
    virtual FX_BOOL CanUndo(window::CPWL_Edit* pEdit);
    virtual FX_BOOL CanRedo(window::CPWL_Edit* pEdit);
    virtual void Undo(window::CPWL_Edit* pEdit);
    virtual void Redo(window::CPWL_Edit* pEdit);	

    FPD_CPWLProviderCallbacksRec m_callback;
};

class CFPD_CPWLProviderHandler_V14
{
public:
	static FPD_CPWL_Provider New(FPD_CPWLProviderCallback callbacks);
	static void Destroy(FPD_CPWL_Provider handler);
};

class CFPD_CPWLWndHandler : public window::CPWL_Wnd, public CFPD_CPWLPluginInterface
{
public:
    CFPD_CPWLWndHandler(FPD_CPWLWndCallbacksRec* callback);
	virtual ~CFPD_CPWLWndHandler();
    void Create(const window::PWL_CREATEPARAM& cp);
    virtual void SetTextColor(const CFX_ColorF& color);
    virtual void CreateChildWnd(const window::PWL_CREATEPARAM& cp);
    virtual void RePosChildWnd();
    virtual void DrawThisAppearance(CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device);

	void CreateInternal(const window::PWL_CREATEPARAM& cp, FX_BOOL bBaseFun);
	void SetTextColorInternal(const CFX_ColorF& color, FX_BOOL bBaseFun);
	void CreateChildWndInternal(const window::PWL_CREATEPARAM& cp, FX_BOOL bBaseFun);
	void RePosChildWndInternal(FX_BOOL bBaseFun);
	void DrawThisAppearanceInternal(CFX_RenderDevice* pDevice, CPDF_Matrix* pUser2Device, FX_BOOL bBaseFun);

	FPD_CPWLWndCallbacksRec m_callback;
};

class CFPD_PWLNofify : public window::IPWL_Nofify
{
public:
	CFPD_PWLNofify(FPD_PWLNotifyCallbacks callbacks);
	virtual ~CFPD_PWLNofify();
	virtual FX_BOOL WindowsRectChangeNotify(const CPDF_Rect& crWindows, CPDF_Rect& crClient);

protected:
	FPD_PWLNotifyCallbacksRec m_callbacks;
};

class CFPD_CPWLWnd_V14
{
public:
	static FPD_CPWL_Wnd New(FPD_CPWLWndCallback callbacks);
	static void Destroy(FPD_CPWL_Wnd wnd);
	static FPD_CPWL_Label CreateChildItemPWLLabel(FPD_CPWL_Wnd wnd, const FS_LPVOID cp);
	static void Create(FPD_CPWL_Wnd wnd, const FS_LPVOID cp,FS_BOOLEAN bBaseFun);
	static void GetClassNamePWL(FPD_CPWL_Wnd wnd, FS_ByteString* bsName);
	static void Move(FPD_CPWL_Wnd wnd, const FS_FloatRect& rcNew, FS_BOOL bReset, FS_BOOL bRefresh);
	static void InvalidateRect(FPD_CPWL_Wnd wnd, FS_FloatRect pRect);
	static void GetAppearanceStream(FPD_CPWL_Wnd wnd, FS_ByteString* sAppStream, FR_EDIT_FontData* outFontDataArray, FS_INT32* outFontDataArrayCount, FS_BOOL bEmbedded);
	static void DrawAppearance(FPD_CPWL_Wnd wnd, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device);
	static FS_BOOL OnKeyDown(FPD_CPWL_Wnd wnd, FS_DWORD nChar);
	static FS_BOOL OnKeyUp(FPD_CPWL_Wnd wnd, FS_DWORD nChar);
	static FS_BOOL OnChar(FPD_CPWL_Wnd wnd, FS_DWORD nChar);
	static FS_BOOL OnLButtonDblClk(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL OnLButtonDown(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL OnLButtonUp(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL OnMButtonDblClk(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL OnMButtonDown(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL OnMButtonUp(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL OnRButtonDblClk(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL OnRButtonDown(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL OnRButtonUp(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL OnMouseMove(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL OnMouseWheel(FPD_CPWL_Wnd wnd, FS_SHORT zDelta, const FS_FloatPoint point);
	static void SetShowTextColor(FPD_CPWL_Wnd wnd, FS_COLORREF cShowColor);
	static void SetShowBackColor(FPD_CPWL_Wnd wnd, FS_COLORREF cShowBackColor);
	static void SetFocus(FPD_CPWL_Wnd wnd);
	static void KillFocus(FPD_CPWL_Wnd wnd);
	static void SetCapture(FPD_CPWL_Wnd wnd);
	static void ReleaseCapture(FPD_CPWL_Wnd wnd);
	static void OnNotify(FPD_CPWL_Wnd wnd, FPD_CPWL_Wnd pWnd, FS_DWORD msg, FS_INTPTR wParam, FS_INTPTR lParam);
	static void SetTextColor(FPD_CPWL_Wnd wnd, const FPD_ColorF color,FS_BOOLEAN bBaseFun);
	static void SetTextStrokeColor(FPD_CPWL_Wnd wnd, const FPD_ColorF color);
	static void SetVisible(FPD_CPWL_Wnd wnd, FS_BOOL bVisible);
	static FS_FloatRect GetFocusRect(FPD_CPWL_Wnd wnd);
	static FPD_ColorF GetBackgroundColor(FPD_CPWL_Wnd wnd);
	static FPD_ColorF GetBorderColor(FPD_CPWL_Wnd wnd);
	static FPD_ColorF GetTextColor(FPD_CPWL_Wnd wnd);
	static FPD_ColorF GetTextStrokeColor(FPD_CPWL_Wnd wnd);
	static FS_FLOAT GetFontSize(FPD_CPWL_Wnd wnd);
	static FS_INT32 GetInnerBorderWidth(FPD_CPWL_Wnd wnd);
	static FPD_ColorF GetBorderLeftTopColor(FPD_CPWL_Wnd wnd, FS_INT32 nBorderStyle);
	static FPD_ColorF GetBorderRightBottomColor(FPD_CPWL_Wnd wnd, FS_INT32 nBorderStyle);
	static FS_BOOL IsModified(FPD_CPWL_Wnd wnd);
	static void SetFontSize(FPD_CPWL_Wnd wnd, FS_FLOAT fFontSize);
	static void SetBackgroundColor(FPD_CPWL_Wnd wnd, const FPD_ColorF color);
	static void SetBorderColor(FPD_CPWL_Wnd wnd, const FPD_ColorF color);
	static void SetBorderWidth(FPD_CPWL_Wnd wnd, FS_INT32 nBorderWidth);
	static void SetClipRect(FPD_CPWL_Wnd wnd, const FS_FloatRect rect);
	static void SetBorderStyle(FPD_CPWL_Wnd wnd, FS_INT32 eBorderStyle);
	static void SetBorderDash(FPD_CPWL_Wnd wnd, const FPDCPWL_Dash sDash);
	static FS_FloatRect GetOriginWindowRect(FPD_CPWL_Wnd wnd);
	static  FS_FloatRect GetWindowRect(FPD_CPWL_Wnd wnd);
	static  FS_FloatRect GetClientRect(FPD_CPWL_Wnd wnd);
	static FS_FloatPoint GetCenterPoint(FPD_CPWL_Wnd wnd);
	static FS_FloatRect GetClientCenterSquare(FPD_CPWL_Wnd wnd);
	static FS_FloatRect GetWindowCenterSquare(FPD_CPWL_Wnd wnd);
	static FS_INT32 GetBorderWidth(FPD_CPWL_Wnd wnd);
	static FS_BOOL IsVisible(FPD_CPWL_Wnd wnd);
	static FS_BOOL HasFlag(FPD_CPWL_Wnd wnd, FS_DWORD dwFlags);
	static void AddFlag(FPD_CPWL_Wnd wnd, FS_DWORD dwFlags);
	static void RemoveFlag(FPD_CPWL_Wnd wnd, FS_DWORD dwFlags);
	static FS_BOOL IsUseFXFontDeAscent(FPD_CPWL_Wnd wnd);
	static FS_FloatRect GetClipRect(FPD_CPWL_Wnd wnd);
	static FPD_CPWL_Wnd GetParentWindow(FPD_CPWL_Wnd wnd);
	static FS_INT32 GetBorderStyle(FPD_CPWL_Wnd wnd);
	static FPDCPWL_Dash GetBorderDash(FPD_CPWL_Wnd wnd);
	static FS_LPVOID GetAttachedData(FPD_CPWL_Wnd wnd);
	static FS_BOOL WndHitTest(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL ClientHitTest(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_BOOL IsCaptureMouse(FPD_CPWL_Wnd wnd);
	static FPD_CPWL_Wnd GetFocused(FPD_CPWL_Wnd wnd);
	static FS_BOOL IsFocused(FPD_CPWL_Wnd wnd);
	static FS_BOOL IsReadOnly(FPD_CPWL_Wnd wnd);
	static FS_LPVOID GetVScrollBar(FPD_CPWL_Wnd wnd);
	static FR_Edit_FontMap GetFontMap(FPD_CPWL_Wnd wnd);
	static FPD_CPWL_Provider GetProvider(FPD_CPWL_Wnd wnd);
	static FS_LPVOID GetSystemHandler(FPD_CPWL_Wnd wnd);
	static FPD_CPWL_FocusHandler GetFocusHandler(FPD_CPWL_Wnd wnd);
	static FS_INT32 GetTransparency(FPD_CPWL_Wnd wnd);
	static void SetTransparency(FPD_CPWL_Wnd wnd, FS_INT32 nTransparency);
	static FS_AffineMatrix GetChildToRoot(FPD_CPWL_Wnd wnd);
	static FS_AffineMatrix GetChildMatrix(FPD_CPWL_Wnd wnd);
	static void SetChildMatrix(FPD_CPWL_Wnd wnd, const FS_AffineMatrix mt);
	static FS_AffineMatrix GetWindowMatrix(FPD_CPWL_Wnd wnd);
	static FS_FloatPoint ChildToParent(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_FloatRect ChildToParent2(FPD_CPWL_Wnd wnd, const FS_FloatRect rect);
	static FS_FloatPoint ParentToChild(FPD_CPWL_Wnd wnd, const FS_FloatPoint point);
	static FS_FloatRect ParentToChild2(FPD_CPWL_Wnd wnd, const FS_FloatRect rect);
	static FS_FLOAT GetItemHeight(FPD_CPWL_Wnd wnd, FS_FLOAT fLimitWidth);
	static FS_FLOAT GetItemLeftMargin(FPD_CPWL_Wnd wnd);
	static FS_FLOAT GetItemRightMargin(FPD_CPWL_Wnd wnd);
	static void EnableWindow(FPD_CPWL_Wnd wnd, FS_BOOL bEnable);
	static FS_BOOL IsEnabled(FPD_CPWL_Wnd wnd);
	static void SetCursor(FPD_CPWL_Wnd wnd);
	static void EnableRefresh(FPD_CPWL_Wnd wnd, FS_BOOL bRefresh);
	static void GetListTooltip(FPD_CPWL_Wnd wnd, const FS_FloatPoint point, FS_WideString* outwsTip);
	static void SetLayout(FPD_CPWL_Wnd wnd, FS_DWORD dwLayout);
	static void SetNofify(FPD_CPWL_Wnd wnd, FPD_PWLNotify pNofity);
	static void SetClientRect(FPD_CPWL_Wnd wnd, FS_FloatRect crClient);
	static  FS_FloatRect GetOwnerClientRect(FPD_CPWL_Wnd wnd);
	static FS_FLOAT AdpatDPI_X(FPD_CPWL_Wnd wnd, FS_FLOAT fSrc);
	static FS_FLOAT AdpatDPI_Y(FPD_CPWL_Wnd wnd, FS_FLOAT fSrc);
	static void AddChild(FPD_CPWL_Wnd wnd, FPD_CPWL_Wnd spWnd);
	static FS_INT32 RemoveChild(FPD_CPWL_Wnd wnd, FPD_CPWL_Wnd pWnd);
	static void DrawThisAppearance(FPD_CPWL_Wnd wnd, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device, FS_BOOLEAN bBaseFun);
	static void CreateChildWnd(FPD_CPWL_Wnd wnd, const FS_LPVOID cp, FS_BOOLEAN bBaseFun);
	static void RePosChildWnd(FPD_CPWL_Wnd wnd, FS_BOOLEAN bBaseFun);
	static void GetAppearanceStream2(FPD_CPWL_Wnd wnd, FS_ByteString* sAppStream, FPD_EDITFONTArray* outFontDataArray, FS_BOOL bEmbedded);	
	static FPD_CPWL_Wnd New2();
	static void SetCaretToEnd(FPD_CPWL_Wnd wnd);
	static FPD_PWLNotify CreateNotify(FPD_PWLNotifyCallbacks callback);
	static void DeleteNotify(FPD_PWLNotify notify);
};

class CFPD_CPWLUtils_V14
{
public:
	static void GetIconAppStream(FS_INT32 nType,
		const FS_FloatRect rect,
		const FPD_ColorF crFill,
		const FPD_ColorF crStroke,
		FS_ByteString* bsStream);
	static void DrawIconAppStream(FPD_RenderDevice pDevice,
		FS_AffineMatrix pUser2Device,
		FS_INT32 nType,
		const FS_FloatRect rect,
		const FPD_ColorF crFill,
		const FPD_ColorF crStroke,
		const FS_INT32 nTransparancy);
	static void GetDBClickWordRange(FR_Edit pEdit,
		FPD_VTWordPlace place,
		FS_BOOLEAN bLatin,
		FS_BOOLEAN bArabic, FPD_VTWordRange* outWordRange);
	static void GetRectFillAppStream(FS_FloatRect rect, FPD_ColorF color, FS_ByteString* outStream);
	static void GetBorderAppStream(FS_FloatRect rect,
		FS_FLOAT fWidth,
		FPD_ColorF color,
		FPD_ColorF crLeftTop,
		FPD_ColorF crRightBottom,
		FS_INT32 nStyle,
		FPDCPWL_Dash dash, FS_ByteString* outStream);
	static void GetColorAppStream(FPD_ColorF color,
		const FS_BOOLEAN bFillOrStroke, FS_ByteString* outStream);
	static FS_FloatRect InflateRect(const FS_FloatRect rcRect, FS_FLOAT fSize);
	static void DrawFillRect(FPD_RenderDevice pDevice,
		FS_AffineMatrix pUser2Device,
		const FS_FloatRect& rect,
		const FPD_ColorF& color,
		FS_INT32 nTransparancy);
	static void DrawFillRect2(FPD_RenderDevice pDevice,
		FS_AffineMatrix pUser2Device,
		const FS_FloatRect rect,
		const FS_COLORREF color);
	static void GetEditAppStream(FR_Edit pEdit,
		const FS_FloatPoint& ptOffset,
		const FPD_VTWordRange pRange,
		FS_BOOLEAN bContinuous,
		FS_WORD SubWord,
		FPD_EDITFONTArray* outFontDataArray,
		FS_ByteString pPathStream,
		FS_BOOLEAN IsEmbedded,
		FS_ByteStringArray pFontReference, FS_ByteString* outStream);
	static void PWLColorToARGB(
		const FPD_ColorF color, FS_INT32* alpha, FS_FLOAT* red, FS_FLOAT* green, FS_FLOAT* blue);
	static FS_COLORREF PWLColorToFXColor(const FPD_ColorF color, FS_INT32 nTransparancy);
	static FS_FloatRect DeflateRect(const FS_FloatRect& rcRect, FS_FLOAT fSize);
	static FPD_ColorF DevideColor(const FPD_ColorF sColor, FS_FLOAT fColorDevide);
	static void  GetCheckBoxAppStream(const FS_FloatRect rcBBox, FS_INT32 nStyle, const FPD_ColorF crText, FS_ByteString* outStream);
	static void  GetCircleBorderAppStream(const FS_FloatRect rect,
		FS_FLOAT fWidth,
		const FPD_ColorF& color,
		const FPD_ColorF& crLeftTop,
		const FPD_ColorF& crRightBottom,
		FS_INT32 nStyle,
		const FPDCPWL_Dash& dash, FS_ByteString* outStream);
	static void GetCircleFillAppStream(const FS_FloatRect& rect, const FPD_ColorF& color, FS_ByteString* outStream);
	static void GetDropButtonAppStream(const FS_FloatRect& rcBBox, FS_ByteString* outStream);
	static void	GetPushButtonAppStream(const FS_FloatRect& rcBBox,
		    FPD_Edit_FontMap pFontMap,
		    FPD_Object pIconStream,
		    FPD_Object* IconFit,
			const FS_LPCWSTR sLabel,
			const FPD_ColorF& crText,
			FS_FLOAT fFontSize,
			FS_INT32 nLayOut,
			FS_INT32 nFontIndex,
		    FPD_EDITFONTArray* outFontDataArray,
			FS_BOOL bRTL,
			FS_ByteStringArray pFontReference, FS_ByteString* outStream);
	static void GetRadioButtonAppStream(const FS_FloatRect& rcBBox, FS_INT32 nStyle, const FPD_ColorF& crText, FS_ByteString* outStream);
	static FPD_ColorF SubstractColor(const FPD_ColorF& sColor, FS_FLOAT fColorSub);
	static FS_FloatRect GetCenterSquare(const FS_FloatRect& rect);
	static void DrawStrokeRect(FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device,const FS_FloatRect rect,const FS_COLORREF color,FS_FLOAT fWidth);
};


class CFPD_ColorF_V14
{
public:
	static FPD_ColorF	ConvertColorType(FPD_ColorF color, FS_INT32 other_nColorType);
};

using namespace window;
class CFPD_SystemHandler : public window::IFX_SystemHandler
{
public:
	CFPD_SystemHandler(FPD_SystemHandlerCallbacks callbacks);
	virtual ~CFPD_SystemHandler();
	virtual void Release();
	virtual void InvalidateRect(FX_HWND hWnd, FX_RECT rect);
	virtual void OutputSelectedRect(void* pFormFiller, CPDF_Rect& rect);
	virtual FX_BOOL IsSelectionImplemented();
	virtual CFX_WideString GetClipboardText(FX_HWND hWnd);
	virtual FX_BOOL SetClipboardText(FX_HWND hWnd, CFX_WideString string);
	virtual void ClientToScreen(FX_HWND hWnd, FX_INT32& x, FX_INT32& y);
	virtual void ScreenToClient(FX_HWND hWnd, FX_INT32& x, FX_INT32& y);
	virtual void SetCursor(FX_INT32 nCursorType, FX_HWND hWnd);
	virtual FX_HMENU CreatePopupMenu(FX_HWND hParent);
	virtual FX_HMENU CreatePopupSubMenu();
	virtual FX_BOOL AppendMenuItem(FX_HMENU hMenu, FX_INT32 nIDItem, CFX_WideString string);
	virtual FX_BOOL AppendSubMenu(FX_HMENU hMenu, FX_HMENU hSubMenu, CFX_WideString string);
	virtual FX_BOOL EnableMenuItem(FX_HMENU hMenu, FX_INT32 nIDItem, FX_BOOL bEnabled);
	virtual FX_BOOL CheckMenuItem(FX_HMENU hMenu, FX_INT32 nIDItem, FX_BOOL bEnabled);
	virtual FX_INT32 TrackPopupMenu(FX_HMENU hMenu, FX_INT32 x, FX_INT32 y, FX_HWND hParent);
	virtual void DestroyMenu(FX_HMENU hMenu);
	virtual CFX_WideString GetNativeTrueTypeFont(FX_INT32 nCharset);
	virtual FX_BOOL FindNativeTrueTypeFont(FX_INT32 nCharset, const CFX_WideString& wsFontFaceName);
	virtual CPDF_Font* AddNativeTrueTypeFontToPDF(CPDF_Document* pDoc, const CFX_WideString& wsFontFaceName,
		FX_BYTE nCharset,
		FX_BOOL bBold,
		FX_BOOL bItalic);
	virtual FX_INT32 SetTimer(FX_INT32 uElapse, TimerCallback lpTimerFunc);
	virtual void KillTimer(FX_INT32 nID);
	virtual FX_BOOL IsSHIFTKeyDown();
	virtual FX_BOOL IsCTRLKeyDown();
	virtual FX_BOOL IsALTKeyDown();
	virtual FX_BOOL IsINSERTKeyDown();
	virtual FX_SYSTEMTIME GetLocalTime();
	virtual FX_DWORD GetMSTickCount();
	virtual FX_DWORD GetMSDoubleClickTime();
	virtual FX_BOOL GetWIPPluginProvider();
	virtual FX_BOOL PasteRTF(void* pEdit);
	virtual FX_BOOL GetDefaultFontNameByCharset(CFX_WideString& csFontname, int nCharSet);
	virtual FX_BOOL GetFontCharset(const CFX_WideString& cwFontFaceName, FX_INT32& charset);
	virtual FX_BOOL AddFontToAnnotDict(CPDF_Dictionary* pAnnnotDict,
		CPDF_Document* pPDFDoc,
		CPDF_Font* pFont,
		const CFX_ByteString& sAlias,
		const CFX_ByteString& sAPType);
	virtual CPDF_Font* GetAnnotDefaultFontName(CPDF_Document* pDoc,
		CPDF_Dictionary* pAnnotDict,
		CFX_WideString& csFontName);
	virtual void GetFullName(CFX_ByteString& csFontName, FX_BOOL bBold, FX_BOOL bItalic);
	virtual FX_BOOL GetDeviceCapsPixelsXY(float& x, float& y);
	virtual unsigned short GetCurrentAppLanguage();
	virtual unsigned short GetSystemDefaultLangIDF();
	virtual FX_BOOL GetFaceName(CFX_WideString& swScriptName, FX_BOOL bRemoveSymbol) const;
	virtual CFX_WideString GetSystemDefaultFontName();
	virtual void GetFontFaceNameBoldItalic(const CFX_WideString& sFontName,
		CFX_WideString& sFaceName,
		FX_BOOL& bBold,
		FX_BOOL& bItalic);
	virtual const CFX_WideStringArray& GetSystemFont();
	virtual void GetSystemSymbolFont(CFX_WideStringArray* pSymbolfontlist);
	virtual FX_BOOL IsFontExistInSystem(const CFX_WideString& fontName, int nCharset);
	virtual FX_DWORD ConvertToFWLVitrualKeyCode(FX_DWORD nChar, FX_BOOL bOnChar);
	virtual void SetCustomCursorHandler(ICustomCursorHandler* pCustomCursorHandler);

protected:
	FPD_SystemHandlerCallbacksRec m_Callbacks;
	CFX_WideStringArray pArr;
};

class CFPD_SystemHanler_V15 //Internal use.
{
public:
	static FPD_SystemHandler CreateSystemHandler(FPD_SystemHandlerCallbacks callback);
	static void DeleteSystemHandler(FPD_SystemHandler handler);
};
class CFPD_Graphics_V16
{
public:
	//************************************
	// Function: CreateGraphics
	// Return: FPD_Graphics    Create FPD_Graphics.
	// Remarks:	Create FPD_Graphics.
	// Notes:	
	//************************************ 
	static FPD_Graphics	CreateGraphics();

	//************************************
	// Function: DeleteGraphics
	// Param[in]: graphics          The input FPD_Graphics object.	
	// Return: void    
	// Remarks:	Frees the memory of the specified context.
	// Notes:	
	//************************************ 
	static void DeleteGraphics(FPD_Graphics graphics);

	//************************************
	// Function: Create
	// Param[in]: graphics          The input FPD_Graphics object.	
	// Param[in]: renderDevice      The native screen graphics. On Windows, it's a handle of 
	//								 HDC; on Linux, it's a pointer to cairo_t; on Mac, it's a 
	//								 value of CGContextRef.
	// Param[in]: isAntialiasing     Whether antialias.	
	// Return: FS_INT32    
	// Remarks:	Creates a new screen context with the native screen graphics context.
	// Notes:	
	//************************************ 
	static FS_INT32 Create(FPD_Graphics graphics, FPD_RenderDevice  renderDevice, FS_BOOLEAN isAntialiasing);
};

class CFPD_CustomCursorHandler : public window::ICustomCursorHandler
{
public:
	CFPD_CustomCursorHandler(FPD_CustomCursorHandlerCallbacks callbacks);
	virtual ~CFPD_CustomCursorHandler();

	virtual void SetCustomCursor(FX_INT32 nCursorType, FX_HWND hWnd);

protected:
	FPD_CustomCursorHandlerCallbacksRec m_Callbacks;
};

class CFPD_CustomCursorHandler_V17
{
public:
	static FPD_CustomCursorHandler New(FPD_CustomCursorHandlerCallbacks callback);
	static void Delete(FPD_CustomCursorHandler handler);
	static void SetCustomCursor(FPD_CustomCursorHandler handler, FS_INT32 nCursorType, FS_LPVOID hWnd);
};


#ifdef __cplusplus
};
#endif//__cplusplus

#endif//FPD_RENDERIMPL_H

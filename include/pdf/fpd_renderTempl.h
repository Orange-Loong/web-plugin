/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

//----------_V1----------
//*****************************
/* RenderOptions HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDRenderOptionsNew
 * @details Creates a new empty page rendering options object.
 * @param[in]  void 
 * @return   A new empty page rendering options object.
 * @note 
 */
INTERFACE(FPD_RenderOptions, FPDRenderOptionsNew, (void))

/**
 * @brief FPDRenderOptionsDestroy
 * @details Destroys the page rendering options object.
 * @param[in]  opts The input page rendering options object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsDestroy, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsGetColorMode
 * @details Gets display mode code.
 * @param[in]  opts The input page rendering options object.
 * @return   The display mode code.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderOptionsGetColorMode, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsSetColorMode
 * @details Sets display mode code.
 * @param[in]  opts The input page rendering options object.
 * @param[in]  nClrMode The new mode code.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetColorMode, (FPD_RenderOptions opts,  FS_INT32 nClrMode))

/**
 * @brief FPDRenderOptionsGetBackColor
 * @details Gets the background color for gray mode (default: white).
 * @param[in]  opts The input page rendering options object.
 * @return   The background color for gray mode (default: white).
 * @note 
 */
INTERFACE(FS_COLORREF, FPDRenderOptionsGetBackColor, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsSetBackColor
 * @details Sets the background color for gray mode (default: white).
 * @param[in]  opts The input page rendering options object.
 * @param[in]  clr Input the background color for gray mode (default: white).
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetBackColor, (FPD_RenderOptions opts,  FS_COLORREF clr))

/**
 * @brief FPDRenderOptionsGetForeColor
 * @details Gets the foreground color for gray mode (default: black).
 * @param[in]  opts The input page rendering options object.
 * @return   The foreground color for gray mode (default: black).
 * @note 
 */
INTERFACE(FS_COLORREF, FPDRenderOptionsGetForeColor, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsSetForeColor
 * @details Sets the foreground color for gray mode (default: black).
 * @param[in]  opts The input page rendering options object.
 * @param[in]  clr Input the foreground color for gray mode (default: black).
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetForeColor, (FPD_RenderOptions opts,  FS_COLORREF clr))

/**
 * @brief FPDRenderOptionsGetRenderFlag
 * @details Gets render flags.
 * @param[in]  opts The input page rendering options object.
 * @return   The  render flags.
 * @note 
 */
INTERFACE(FS_DWORD, FPDRenderOptionsGetRenderFlag, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsSetRenderFlag
 * @details Sets  render flags.
 * @param[in]  opts The input page rendering options object.
 * @param[in]  dwFlag Input render flags.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetRenderFlag, (FPD_RenderOptions opts,  FS_DWORD dwFlag))

/**
 * @brief FPDRenderOptionsGetAddtionalFlag
 * @details Gets additional flags depending on the device.
 * @param[in]  opts The input page rendering options object.
 * @return   The additional flags depending on the device.
 * @note 
 */
INTERFACE(FS_DWORD, FPDRenderOptionsGetAddtionalFlag, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsSetAddtionalFlag
 * @details Sets additional flags depending on the device.
 * @param[in]  opts The input page rendering options object.
 * @param[in]  dwFlag Input additional flags depending on the device.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetAddtionalFlag, (FPD_RenderOptions opts,  FS_DWORD dwFlag))

/**
 * @brief FPDRenderOptionsSetOCCHandler
 * @details Sets optional content context handler.
 * @param[in]  opts The input page rendering options object.
 * @param[in]  OCCHandler Input optional content context handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetOCCHandler, (FPD_RenderOptions opts,  FPD_OCContextHandler OCCHandler))

/**
 * @brief FPDRenderOptionsTranslateColor
 * @details Translates a color.
 * @param[in]  opts The input page rendering options object.
 * @param[in]  argb The input color.
 * @return   The translated color.
 * @note 
 */
INTERFACE(FS_ARGB, FPDRenderOptionsTranslateColor, (FPD_RenderOptions opts,  FS_ARGB argb))

/**
 * @brief FPDRenderOptionsCreateOCContextHandler
 * @details Creates optional content context handler.
 * @param[in]  OCContext The input page rendering options object.
 * @return   FPD_OCContextHandler		Input optional content context handler.
 * @note 
 */
INTERFACE(FPD_OCContextHandler, FPDRenderOptionsCreateOCContextHandler, (FPD_OCContextCallBack OCContext))

/**
 * @brief FPDRenderOptionsDeleteOCContextHandler
 * @details Deletes optional content context handler.
 * @param[in]  OCCHandler Input optional content context handler to be deleted.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsDeleteOCContextHandler, (FPD_OCContextHandler OCCHandler))

/**
 * @brief FPDRenderOptionsSetDocTextColor
 * @details Set text color of the render options.
 * @param[in]  OCCHandler The input page rendering options object.
 * @param[in]  color The color of text color.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetDocTextColor, (FPD_RenderOptions opts,  FS_COLORREF color))

/**
 * @brief FPDRenderOptionsGetDocTextColor
 * @details Get text color of the render options.
 * @param[in]  OCCHandler The input page rendering options object.
 * @return   FS_COLORREF       Get the text color of the render options.
 * @note 
 */
INTERFACE(FS_COLORREF, FPDRenderOptionsGetDocTextColor, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsSetCustomColorMode
 * @details Set the custom color mode of the render options.
 * @param[in]  OCCHandler The input page rendering options object.
 * @param[in]  mode The custom color mode of the render options.
 * @return   FS_COLORREF       Set the custom color mode of the render options.
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetCustomColorMode, (FPD_RenderOptions opts,  FS_DWORD mode))

/**
 * @brief FPDRenderOptionsGetCustomColorMode
 * @details Get the custom color mode of the render options.
 * @param[in]  OCCHandler The input page rendering options object.
 * @return   FS_DWORD          Get the custom color mode of the render options.
 * @note 
 */
INTERFACE(FS_DWORD, FPDRenderOptionsGetCustomColorMode, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsTranslateColor2
 * @details Translates a color.
 * @param[in]  opts The input page rendering options object.
 * @param[in]  argb The input color.
 * @param[in]  objType The input obj type.
 * @return   The translated color.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 */
INTERFACE(FS_ARGB, FPDRenderOptionsTranslateColor2, (FPD_RenderOptions opts,  FS_ARGB argb,  FS_INT32 objType))

NumOfSelector(FPDRenderOptions)
ENDENUM

//*****************************
/* RenderContext HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDRenderContextNew
 * @details Creates a new PDF rendering context object.
 * @param[in]  page The input page.
 * @param[in]  bFirstLayer Whether it's the first layer.
 * @return   A empty PDF rendering context object.
 * @note 
 */
INTERFACE(FPD_RenderContext, FPDRenderContextNew, (FPD_Page page,  FS_BOOL bFirstLayer))

/**
 * @brief FPDRenderContextNew2
 * @details Creates a new PDF rendering context object.
 * @param[in]  doc The PDF document.
 * @param[in]  pageCache The page render cache.
 * @param[in]  pageResources The Resources dictionary.
 * @param[in]  bFirstLayer Whether it's the first layer.
 * @return   A new PDF rendering context object.
 * @note 
 */
INTERFACE(FPD_RenderContext, FPDRenderContextNew2, (FPD_Document doc,  FPD_PageRenderCache pageCache,  FPD_Object pageResources,  FS_BOOL bFirstLayer))

/**
 * @brief FPDRenderContextDestroy
 * @details Destroys the PDF rendering context object.
 * @param[in]  context The input PDF rendering context object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextDestroy, (FPD_RenderContext context))

/**
 * @brief FPDRenderContextDrawStream
 * @details Draws a page description stream.
 * @param[in]  context The input PDF rendering context object.
 * @param[out]  outDevice The output device.
 * @param[in]  pStreamDataBuf The page description stream buffer.
 * @param[in]  stream_size The size in bytes of the page description stream. -1 for <a>NULL</a> terminated byte string.
 * @param[in]  displayMatrix The matrix from stream coords to device coords. Can be <a>NULL</a> if no transformation needed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextDrawStream, (FPD_RenderContext context,  FPD_RenderDevice* outDevice,  const void* pStreamDataBuf,  FS_DWORD stream_size,  FS_AffineMatrix displayMatrix))

/**
 * @brief FPDRenderContextAppendPage
 * @details Append page to the current layer.
 * @param[in]  context The input PDF rendering context object.
 * @param[in]  objs The input page.
 * @param[in]  object2Device The matrix from object coords to device coords.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextAppendPage, (FPD_RenderContext context,  FPD_Page objs,  FS_AffineMatrix object2Device))

/**
 * @brief FPDRenderContextAppendForm
 * @details Append Form to the current layer.
 * @param[in]  context The input PDF rendering context object.
 * @param[in]  objs The input Form
 * @param[in]  object2Device The matrix from object coords to device coords
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextAppendForm, (FPD_RenderContext context,  FPD_Form objs,  FS_AffineMatrix object2Device))

/**
 * @brief FPDRenderContextSetBackground
 * @details Sets custom background drawing.
 * @param[in]  context The input PDF rendering context object.
 * @param[in]  BackgroundDrawHandler The background drawing handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextSetBackground, (FPD_RenderContext context,  FPD_BackgroundDrawHandler BackgroundDrawHandler))

/**
 * @brief FPDRenderContextCreateBackgroundDrawHandler
 * @details Creates the background drawing handler.
 * @param[in]  backgroundDraw The input background drawing handler structure.
 * @return   The background drawing handler.
 * @note 
 */
INTERFACE(FPD_BackgroundDrawHandler, FPDRenderContextCreateBackgroundDrawHandler, (FPD_BackgroundDraw backgroundDraw))

/**
 * @brief FPDRenderContextDeleteBackgroundDrawHandler
 * @details Deletes the background drawing handler.
 * @param[in]  backgroundDrawHandler The input background drawing handler structure.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextDeleteBackgroundDrawHandler, (FPD_BackgroundDrawHandler backgroundDrawHandler))

/**
 * @brief FPDRenderContextRender
 * @details Do the real rendering. Optionally, rendering matrix can be modified by the last matrix.
 * @param[in]  context The input PDF rendering context object.
 * @param[in]  device The output device.
 * @param[in]  options The render options.
 * @param[in]  pFinalMatrix The final matrix to transform the result, Default value is <a>NULL</a>.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextRender, (FPD_RenderContext context,  FPD_RenderDevice device,  const FPD_RenderOptions options,  FS_AffineMatrix* pFinalMatrix))

/**
 * @brief FPDRenderContextDrawPage
 * @details Draws a list of page objects.
 * @param[in]  context The input PDF rendering context object.
 * @param[out]  outDevice The output device.
 * @param[in]  objs The input page.
 * @param[in]  pObject2Device The matrix from object coords to device coords, can be NULL.
 * @param[in]  options The render options.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextDrawPage, (FPD_RenderContext context,  FPD_RenderDevice* outDevice,  FPD_Page objs,  FS_AffineMatrix* pObject2Device,  const FPD_RenderOptions options))

/**
 * @brief FPDRenderContextDrawForm
 * @details Draws a list of page objects.
 * @param[in]  context The input PDF rendering context object.
 * @param[out]  outDevice The output device.
 * @param[in]  objs The input Form.
 * @param[in]  pObject2Device The matrix from object coords to device coords, can be NULL.
 * @param[in]  options The render options.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextDrawForm, (FPD_RenderContext context,  FPD_RenderDevice* outDevice,  FPD_Form objs,  FS_AffineMatrix* pObject2Device,  const FPD_RenderOptions options))

/**
 * @brief FPDRenderContextQuickDraw
 * @details Draws a rough preview (quick draw).
 * @param[in]  context The input PDF rendering context object.
 * @param[out]  outDevice The output device.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextQuickDraw, (FPD_RenderContext context,  FPD_RenderDevice* outDevice))

/**
 * @brief FPDRenderContextGetBackground
 * @details Gets background of a page object within the rendering context.
 * @param[in]  context The input PDF rendering context object.
 * @param[out]  outBitmapBuffer It receives the background bitmap.
 * @param[in]  obj The input page object.
 * @param[in]  options The render options.
 * @param[in]  pFinalMatrix The matrix from object coords to device coords.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextGetBackground, (FPD_RenderContext context,  FS_DIBitmap* outBitmapBuffer,  const FPD_PageObject obj,  const FPD_RenderOptions options,  FS_AffineMatrix* pFinalMatrix))

/**
 * @brief FPDRenderContextGetPageCache
 * @details Gets the page render cache.
 * @param[in]  context The input PDF rendering context object.
 * @return   The page render cache.
 * @note 
 */
INTERFACE(FPD_PageRenderCache, FPDRenderContextGetPageCache, (FPD_RenderContext context))

NumOfSelector(FPDRenderContext)
ENDENUM

//*****************************
/* ProgressiveRender HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDProgressiveRenderNew
 * @details Creates a new empty PDF progressive renderer object.
 * @param[in]  void 
 * @return   A new empty PDF progressive renderer object.
 * @note 
 */
INTERFACE(FPD_ProgressiveRender, FPDProgressiveRenderNew, (void))

/**
 * @brief FPDProgressiveRenderDestroy
 * @details Destroys the PDF progressive renderer object.
 * @param[in]  render The input PDF progressive renderer object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveRenderDestroy, (FPD_ProgressiveRender render))

/**
 * @brief FPDProgressiveRenderStart
 * @details Starts rendering.
 * @param[in]  render The input PDF progressive renderer object.
 * @param[in]  context The render context.
 * @param[in]  device The output device.
 * @param[in]  options The render options.
 * @param[in]  pauseHandler The pause handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveRenderStart, (FPD_ProgressiveRender render,  FPD_RenderContext context,  FPD_RenderDevice* device,  const FPD_RenderOptions options,  FS_PauseHandler pauseHandler))

/**
 * @brief FPDProgressiveRenderContinue
 * @details Continue rendering.
 * @param[in]  render The input PDF progressive renderer object.
 * @param[in]  pauseHandler The pause handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveRenderContinue, (FPD_ProgressiveRender render,  FS_PauseHandler pauseHandler))

/**
 * @brief FPDProgressiveRenderEstimateProgress
 * @details Estimates percentage of progress.
 * @param[in]  render The input PDF progressive renderer object.
 * @return   An estimated percentage of progress.
 * @note 
 */
INTERFACE(FS_INT32, FPDProgressiveRenderEstimateProgress, (FPD_ProgressiveRender render))

/**
 * @brief FPDProgressiveRenderClear
 * @details Gets ready for next rendering.
 * @param[in]  render The input PDF progressive renderer object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveRenderClear, (FPD_ProgressiveRender render))

/**
 * @brief FPDProgressiveRenderGetStatus
 * @details Get the render status.
 * @param[in]  render The input PDF progressive renderer object.
 * @return   void
 * @note 
 */
INTERFACE(FPDRenderStatus, FPDProgressiveRenderGetStatus, (FPD_ProgressiveRender render))

NumOfSelector(FPDProgressiveRender)
ENDENUM

//*****************************
/* RenderDevice HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDRenderDeviceNew
 * @details Creates a new empty render device object.
 * @param[in]  void 
 * @return   A new empty render device object.
 * @note 
 */
INTERFACE(FPD_RenderDevice, FPDRenderDeviceNew, (void))

/**
 * @brief FPDRenderDeviceDestroy
 * @details Destroys the render device object.
 * @param[in]  dc The input render device object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderDeviceDestroy, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceStartRendering
 * @details Starts rendering.
 * @param[in]  dc The input render device object.
 * @return   Non-zero means success, otherwise failure.
 * @note Called only once for each rendering job.
 */
INTERFACE(FS_BOOL, FPDRenderDeviceStartRendering, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceEndRendering
 * @details End rendering.
 * @param[in]  dc The input render device object.
 * @return   Non-zero means success, otherwise failure.
 * @note Called only once for each rendering job.
 */
INTERFACE(void, FPDRenderDeviceEndRendering, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceSaveState
 * @details Saves all graphic states.
 * @param[in]  dc The input render device object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderDeviceSaveState, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceRestoreState
 * @details Restores all graphic states.
 * @param[in]  dc The input render device object.
 * @param[in]  bKeepSaved Whether to keep the restored states saved in buffer.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderDeviceRestoreState, (FPD_RenderDevice dc,  FS_BOOL bKeepSaved))

/**
 * @brief FPDRenderDeviceGetWidth
 * @details Gets the device width.
 * @param[in]  dc The input render device object.
 * @return   The device width.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderDeviceGetWidth, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceGetHeight
 * @details Gets the device height.
 * @param[in]  dc The input render device object.
 * @return   The device height.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderDeviceGetHeight, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceGetBPP
 * @details Gets the bits per pixel.
 * @param[in]  dc The input render device object.
 * @return   The bits per pixel.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceGetBPP, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceGetRenderCaps
 * @details Gets the render capabilities.
 * @param[in]  dc The input render device object.
 * @return   The render capabilities.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderDeviceGetRenderCaps, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceGetDeviceCapsXY
 * @details Gets the render capabilities.
 * @param[in]  dc The input render device object.
 * @param[in]  id The input device capability ID
 * @return   The render capabilities.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderDeviceGetDeviceCapsXY, (FPD_RenderDevice dc,  FS_INT32 id))

/**
 * @brief FPDRenderDeviceGetBitmap
 * @details Gets the bitmap of the device.
 * @param[in]  dc The input render device object.
 * @return   The bitmap of the device.
 * @note 
 */
INTERFACE(FS_DIBitmap, FPDRenderDeviceGetBitmap, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceSetBitmap
 * @details Sets the bitmap to the device.
 * @param[in]  dc The input render device object.
 * @param[in]  bitmap The input bitmap
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderDeviceSetBitmap, (FPD_RenderDevice dc,  FS_DIBitmap bitmap))

/**
 * @brief FPDRenderDeviceSetPixel
 * @details Sets or composite a pixel.
 * @param[in]  dc The input render device object.
 * @param[in]  x The x-coordinate of the pixel.
 * @param[in]  y The y-coordinate of the pixel.
 * @param[in]  argb The color of the pixel.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceSetPixel, (FPD_RenderDevice dc,  FS_INT32 x,  FS_INT32 y,  FS_ARGB argb))

/**
 * @brief FPDRenderDeviceSetClip_Rect
 * @details Sets a clipping rectangle.
 * @param[in]  dc The input render device object.
 * @param[in]  rect The input clipping rectangle.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceSetClip_Rect, (FPD_RenderDevice dc,  const FS_Rect rect))

/**
 * @brief FPDRenderDeviceCreateCompatibleBitmap
 * @details Creates a compatible bitmap.
 * @param[in]  dc The input render device object.
 * @param[in,out]  inoutDIB It receives the created bitmap data.
 * @param[in,out]  width The bitmap width.
 * @param[in,out]  height The bitmap height.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(void, FPDRenderDeviceCreateCompatibleBitmap, (FPD_RenderDevice dc,  FS_DIBitmap* inoutDIB,  FS_INT32 width,  FS_INT32 height))

/**
 * @brief FPDRenderDeviceFillRect
 * @details Fills a rectangle.
 * @param[in]  dc The input render device object.
 * @param[in,out]  pRect The input rectangle
 * @param[in,out]  fill_argb The color to fill.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceFillRect, (FPD_RenderDevice dc,  const FS_Rect* pRect,  FS_ARGB fill_argb))

/**
 * @brief FPDRenderDeviceDrawCosmeticLine
 * @details Draws a single pixel (device dependent) line.
 * @param[in]  dc The input render device object.
 * @param[in]  x1 The x-coordinate of the start point.
 * @param[in]  y1 The y-coordinate of the start point.
 * @param[in]  x2 The x-coordinate of the end point.
 * @param[in]  y2 The y-coordinate of the end point.
 * @param[in]  argb The line color.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceDrawCosmeticLine, (FPD_RenderDevice dc,  FS_FLOAT x1,  FS_FLOAT y1,  FS_FLOAT x2,  FS_FLOAT y2,  FS_ARGB argb))

/**
 * @brief FPDRenderDeviceGetDIBits
 * @details Loads device buffer into a DIB.
 * @param[in]  dc The input render device object.
 * @param[out]  bitmap It receives the loaded device buffer.
 * @param[in]  left The x-coordinate in the device.
 * @param[in]  top The y-coordinate in the device.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceGetDIBits, (FPD_RenderDevice dc,  FS_DIBitmap bitmap,  FS_INT32 left,  FS_INT32 top))

/**
 * @brief FPDRenderDeviceSetDIBits
 * @details Outputs a colored DIB, pixel-to-pixel.
 * @param[in]  dc The input render device object.
 * @param[in]  bitmap The input colored DIB.
 * @param[in]  left The x-coordinate in the device.
 * @param[in]  top The y-coordinate in the device.
 * @param[in]  blend_type Blend mode.
 * @return   Non-zero means success, otherwise failure.
 * @note When ARGB bitmap is specified, device capability <a>FSRC_ALPHA_IMAGE</a> or <a>FSRC_GET_BITS</a> is required.
	* When non-normal blending type is used, device capability <a>FSRC_BLEND_MODE</a> or <a>FSRC_GET_BITS</a> is required.
 */
INTERFACE(FS_BOOL, FPDRenderDeviceSetDIBits, (FPD_RenderDevice dc,  const FS_DIBitmap bitmap,  FS_INT32 left,  FS_INT32 top,  FS_INT32 blend_type))

/**
 * @brief FPDRenderDeviceStretchDIBits
 * @details Stretches a colored DIB onto the device.
 * @param[in]  dc The input render device object.
 * @param[in]  bitmap The input colored DIB.
 * @param[in]  left The x-coordinate in the device.
 * @param[in]  top The y-coordinate in the device.
 * @param[in]  dest_width The destinate width in the device.
 * @param[in]  dest_height The destinate height in the device.
 * @param[in]  flags The stretching flags.
 * @return   Non-zero means success, otherwise failure.
 * @note When ARGB bitmap is specified, device capability <a>FSRC_ALPHA_IMAGE</a> or <a>FSRC_GET_BITS</a> is required.
 */
INTERFACE(FS_BOOL, FPDRenderDeviceStretchDIBits, (FPD_RenderDevice dc,  const FS_DIBitmap bitmap,  FS_INT32 left,  FS_INT32 top,  FS_INT32 dest_width,  FS_INT32 dest_height,  FS_DWORD flags))

/**
 * @brief FPDRenderDeviceSetBitMask
 * @details Outputs masked bitmap. The bitmap can be a monochrome bitmask, or a 8-bit alpha mask.
 * @param[in]  dc The input render device object.
 * @param[in]  bitmap The inpput mask.
 * @param[in]  left The x-coordinate in the device.
 * @param[in]  top The y-coordinate in the device.
 * @param[in]  argb The color to be masked.
 * @return   Non-zero means success, otherwise failure.
 * @note If the mask is monochrome, device capability <a>FSRC_BIT_MASK</a> or <a>FSRC_GET_BITS</a> is required.
	*        If the mask is an alpha mask, device capability <a>FSRC_ALPHA_MAS>K</a or <a>FSRC_GET_BITS</a> is required.
 */
INTERFACE(FS_BOOL, FPDRenderDeviceSetBitMask, (FPD_RenderDevice dc,  const FS_DIBitmap bitmap,  FS_INT32 left,  FS_INT32 top,  FS_ARGB argb))

/**
 * @brief FPDRenderDeviceStretchBitMask
 * @details Outputs masked bitmap. The bitmap can be a monochrome bitmask, or a 8-bit alpha mask.
 * @param[in]  dc The input render device object.
 * @param[in]  bitmap The inpput mask.
 * @param[in]  left The x-coordinate in the device.
 * @param[in]  top The y-coordinate in the device.
 * @param[in]  dest_width The destinate width in the device.
 * @param[in]  dest_height The destinate height in the device.
 * @param[in]  argb The color to be masked.
 * @param[in]  flags The stretching flags.
 * @return   Non-zero means success, otherwise failure.
 * @note If the mask is monochrome, device capability <a>FSRC_BIT_MASK</a> or <a>FSRC_GET_BITS</a> is required.
	*        If the mask is an alpha mask, device capability <a>FSRC_ALPHA_MASK</a> or <a>FSRC_GET_BITS</a> is required.
 */
INTERFACE(FS_BOOL, FPDRenderDeviceStretchBitMask, (FPD_RenderDevice dc,  const FS_DIBitmap bitmap,  FS_INT32 left,  FS_INT32 top,  FS_INT32 dest_width,  FS_INT32 dest_height,  FS_ARGB argb,  FS_DWORD flags))

/**
 * @brief FPDRenderDeviceGetDitherBits
 * @details Gets the dither bits.
 * @param[in]  dc The input render device object.
 * @return   The dither bits.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderDeviceGetDitherBits, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceDrawTextString
 * @details Draws a text string, using Windows style parameters.
 * @param[in]  dc The input render device object.
 * @param[in]  left x position, in device coordinate.
 * @param[in]  top y position, in device coordinate.
 * @param[in]  font The input font.
 * @param[in]  height height of the character cell, in pixels.
 * @param[in]  str a string using font encoding.
 * @param[in]  argb color and alpha value, in 0xaarrggbb format.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderDeviceDrawTextString, (FPD_RenderDevice dc,  FS_INT32 left,  FS_INT32 top,  FPD_Font font,  FS_INT32 height,  FS_LPCSTR str,  FS_ARGB argb))

/**
 * @brief FPDRenderDeviceDrawTextString2
 * @details Draws a text string using PDF style parameters.
 * @param[in]  dc The input render device object.
 * @param[in]  originX x position of the origin (for first character), in device coord.
 * @param[in]  originY y position of the origin (for first character), in device coord.
 * @param[in]  font The font will be used to draw text.
 * @param[in]  fontSize number of points for the font em square.
 * @param[in]  matrix a matrix from text space to device space, used for font rotation,
	*                          scaling and skewing. Can be NULL for identity matrix.
	*                          If specified, the "e" and "f" coefficients (for translation) are ignored.
 * @param[in]  str a string using font encoding.
 * @param[in]  fillArgb color and alpha value, in 0xaarrggbb format. 0 for not filling.
 * @param[in]  strokeArgb color for stroking text. 0 for not stroking.
 * @param[in]  graphState required for stroking.
 * @param[in]  opts rendering options, like clear-type flag.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDRenderDeviceDrawTextString2, (FPD_RenderDevice dc,  FS_FLOAT originX,  FS_FLOAT originY,  FPD_Font font,  FS_FLOAT fontSize,  FS_AffineMatrix matrix,  FS_ByteString str,  FS_ARGB fillArgb,  FS_ARGB strokeArgb,  const FPD_GraphState graphState,  const FPD_RenderOptions opts))

/**
 * @brief FPDRenderDeviceDrawTextPath
 * @details Draws text path.
 * @param[in]  dc The input render device object.
 * @param[in]  nChars The number of characters in the text.
 * @param[in]  pCharCodesBuf The character codes.
 * @param[in]  pCharPosBuf The character positions.
 * @param[in]  font The font will be used to draw text.
 * @param[in]  fontSize The font size.
 * @param[in]  text2User The matrix from text coordinate to user coordinate.
 * @param[in]  user2Device The matrix from user coordinate  to user coordinate.
 * @param[in]  graphState Graphic state, for pen attributes.
 * @param[in]  fillArgb Fill color.
 * @param[in]  strokeArgb Stroke color
 * @param[in]  clippingPath The clipping path to add to.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceDrawTextPath, (FPD_RenderDevice dc,  FS_INT32 nChars,  FS_DWORD* pCharCodesBuf,  FS_FLOAT* pCharPosBuf,  FPD_Font font,  FS_FLOAT fontSize,  FS_AffineMatrix text2User,  FS_AffineMatrix user2Device,  const FPD_GraphState graphState,  FS_ARGB fillArgb,  FS_ARGB strokeArgb,  FPD_Path clippingPath))

/**
 * @brief FPDRenderDeviceDrawNormalText
 * @details Draws normal text.
 * @param[in]  dc The input render device object.
 * @param[in]  nChars The number of characters in the text.
 * @param[in]  pCharCodesBuf The character codes.
 * @param[in]  pCharPosBuf The character positions.
 * @param[in]  font The font will be used to draw text.
 * @param[in]  fontSize The font size.
 * @param[in]  text2Device The matrix from text coordinate to device coordinate.
 * @param[in]  fillArgb The fill color used to fill the text.
 * @param[in]  opts The render options.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceDrawNormalText, (FPD_RenderDevice dc,  FS_INT32 nChars,  FS_DWORD* pCharCodesBuf,  FS_FLOAT* pCharPosBuf,  FPD_Font font,  FS_FLOAT fontSize,  FS_AffineMatrix text2Device,  FS_ARGB fillArgb,  const FPD_RenderOptions opts))

/**
 * @brief FPDRenderDeviceDrawType3Text
 * @details Draws type3 text.
 * @param[in]  dc The input render device object.
 * @param[in]  pContext The input render context.
 * @param[in]  pOptions The input render options.
 * @param[in]  pStates1 The input graphic states.
 * @param[in]  nChars The number of characters in the text.
 * @param[in]  pCharCodesBuf The character codes.
 * @param[in]  pCharPosBuf The character positions.
 * @param[in]  font The Type3 font will be used to draw text.
 * @param[in]  fontSize The font size.
 * @param[in]  pTextToDevice The pointer of  matrix from text coordinate to device coordinate.
 * @param[in]  fillArgb The fill color use to fill the text.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceDrawType3Text, (FPD_RenderDevice dc,  FPD_RenderContext pContext,  FPD_RenderOptions pOptions,  FPD_PageObject pStates1,  FS_INT32 nChars,  FS_DWORD* pCharCodesBuf,  FS_FLOAT* pCharPosBuf,  FPD_Font font,  FS_FLOAT fontSize,  FS_AffineMatrix* pTextToDevice,  FS_ARGB fillArgb))

/**
 * @brief FPDRenderDeviceDrawPath
 * @details Draw a path. If either <param>fill_argb</param> or <param>stroke_argb</param> is used and with 
	* alpha value between 0 and 255, then device capability FSRC_ALPHA_PATH or FSRC_GET_BITS is required.
 * @param[in]  dc The input render device object.
 * @param[in]  path Path info.
 * @param[in]  pObject2Device Optional transformation.
 * @param[in]  graphState Graphic state, for pen attributes.
 * @param[in]  fill_color Fill color.
 * @param[in]  stroke_color Stroke color.
 * @param[in]  fill_mode Fill mode, FSFILL_WINDING or FSFILL_ALTERNATE. 0 for not filled. Also FSFILL_FULLCOVER or FSFILL_RECT_AA bit can be used with fill mode.
 * @param[in]  bAntiAlias This param has beed deprecated, false can be set in by default.
 * @param[in]  alpha_flag The flag indicates color type and alpha value, each components 8 bits.
	* alpha_flag == (stroke_alpha<<16)|(color_type<<8)|fill_alpha
	* color type: 0 for rgb, 1 for cmyk
 * @param[in]  pIccTransform The color transform handle.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDRenderDeviceDrawPath, (FPD_RenderDevice dc,  FPD_Path path,  FS_AffineMatrix pObject2Device,  FPD_GraphState graphState,  FS_DWORD fill_color,  FS_DWORD stroke_color,  FS_INT32 fill_mode,  FS_BOOL bAntiAlias,  FS_INT32 alpha_flag,  void* pIccTransform))

/**
 * @brief FPDRenderDeviceSetClip_PathFill
 * @details Set clipping path using filled region.
 * @param[in]  dc The input render device object.
 * @param[in]  path The input path info.
 * @param[in]  pObject2Device Optional transformation.
 * @param[in]  fill_mode Fill mode, <a>FSFILL_WINDING</a> or <a>FSFILL_ALTERNATE</a>.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDRenderDeviceSetClip_PathFill, (FPD_RenderDevice dc,  FPD_Path path,  FS_AffineMatrix pObject2Device,  FS_INT32 fill_mode))

/**
 * @brief FPDRenderDeviceSetClip_PathFill2
 * @details Set clipping path using filled region.
 * @param[in]  dc The input render device object.
 * @param[in]  path The input path info.
 * @param[in]  fill_mode Fill mode, <a>FSFILL_WINDING</a> or <a>FSFILL_ALTERNATE</a>.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDRenderDeviceSetClip_PathFill2, (FPD_RenderDevice dc,  FPD_Path path,  FS_INT32 fill_mode))

/**
 * @brief FPDRenderDeviceGetMatrix
 * @details Get current transform matrix to device.
 * @param[in]  dc The input render device object.
 * @return   FS_AffineMatrix
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 */
INTERFACE(FS_AffineMatrix, FPDRenderDeviceGetMatrix, (FPD_RenderDevice dc))

NumOfSelector(FPDRenderDevice)
ENDENUM

//*****************************
/* FxgeDevice HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFxgeDeviceNew
 * @details Creates a new empty GE rendering device object.
 * @return   A new empty GE rendering device object.
 * @note 
 */
INTERFACE(FPD_RenderDevice, FPDFxgeDeviceNew, ())

/**
 * @brief FPDFxgeDeviceCreate
 * @details Creates a new bitmap and attach to this device.
 * @param[in]  dc The input GE rendering device object.
 * @param[in]  width The bitmap width.
 * @param[in]  height The bitmap height
 * @param[in]  format The bitmap format.
 * @param[in]  ditherBits The optional dithering bits. 0 for no dithering
 * @return   void
 * @note The bitmap will be destroyed when the device destructs.
 */
INTERFACE(void, FPDFxgeDeviceCreate, (FPD_RenderDevice dc,  FS_INT32 width,  FS_INT32 height,  FS_DIB_Format format,  FS_INT32 ditherBits))

/**
 * @brief FPDFxgeDeviceDestroy
 * @details Destroys the GE rendering device object.
 * @param[in]  dc The input GE rendering device object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFxgeDeviceDestroy, (FPD_RenderDevice dc))

/**
 * @brief FPDFxgeDeviceAttach
 * @details Attach a bitmap.
 * @param[in]  dc The input GE rendering device object.
 * @param[in]  bitmap The input bitmap to be attached.
 * @param[in]  ditherBits The input dither bits.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFxgeDeviceAttach, (FPD_RenderDevice dc,  FS_DIBitmap bitmap,  FS_INT32 ditherBits))

NumOfSelector(FPDFxgeDevice)
ENDENUM

//*****************************
/* WindowsDevice HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDWindowsDeviceNew
 * @details Creates a new empty Windows device object.
 * @param[in]  windowsDC The input Windows device.
 * @return   A new empty Windows rendering device object.
 * @note 
 */
INTERFACE(FPD_RenderDevice, FPDWindowsDeviceNew, (void* windowsDC))

/**
 * @brief FPDWindowsDeviceDestroy
 * @details Destroys the PDF Windows device object.
 * @param[in]  dc The input PDF Windows device object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDWindowsDeviceDestroy, (FPD_RenderDevice dc))

/**
 * @brief FPDWindowsDeviceGetDC
 * @details Get the PDF Windows device object.
 * @param[in]  dc The input PDF Windows device object.
 * @return   void* The PDF Windows device object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.2
 */
INTERFACE(void*, FPDWindowsDeviceGetDC, (FPD_RenderDevice dc))

NumOfSelector(FPDWindowsDevice)
ENDENUM

//*****************************
/* PageRenderCache HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDPageRenderCacheNew
 * @details Creates a new empty page rendering cache object.
 * @param[in]  page The input PDF page.
 * @return   A new empty page rendering cache object.
 * @note 
 */
INTERFACE(FPD_PageRenderCache, FPDPageRenderCacheNew, (FPD_Page page))

/**
 * @brief FPDPageRenderCacheDestroy
 * @details Destroys the page rendering cache object.
 * @param[in]  cache The input page rendering cache object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageRenderCacheDestroy, (FPD_PageRenderCache cache))

/**
 * @brief FPDPageRenderCacheClearAll
 * @details Clears all items in the cache.
 * @param[in]  cache The input page rendering cache object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageRenderCacheClearAll, (FPD_PageRenderCache cache))

/**
 * @brief FPDPageRenderCacheClearImageData
 * @details Clears image data.
 * @param[in]  cache The input page rendering cache object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageRenderCacheClearImageData, (FPD_PageRenderCache cache))

/**
 * @brief FPDPageRenderCacheEstimateSize
 * @details Gets estimated size of the total cache.
 * @param[in]  cache The input page rendering cache object.
 * @return   Estimated size of the total cache.
 * @note The application can use some strategy for dispense page caches according the memory size they occupy.
 */
INTERFACE(FS_DWORD, FPDPageRenderCacheEstimateSize, (FPD_PageRenderCache cache))

/**
 * @brief FPDPageRenderCacheGetCachedBitmap
 * @details Gets cached items
 * @param[in]  cache The input page rendering cache object.
 * @param[in]  stream The stream of the bitmap.
 * @param[out]  outBitmap It retrieves the bitmap.
 * @param[out]  outMask It retrieves the mask.
 * @param[out]  outMatteColor It retrieves the matte color.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageRenderCacheGetCachedBitmap, (FPD_PageRenderCache cache,  FPD_Object stream,  FS_DIBitmap* outBitmap,  FS_DIBitmap* outMask,  FS_DWORD* outMatteColor))

/**
 * @brief FPDPageRenderCacheResetBitmap
 * @details Resets the image cache or force the cache to be expired
 * @param[in]  cache The input page rendering cache object.
 * @param[in]  stream The stream of the bitmap.
 * @param[in]  bitmap Input the bitmap.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageRenderCacheResetBitmap, (FPD_PageRenderCache cache,  FPD_Object stream,  const FS_DIBitmap bitmap))

INTERFACE(void, FPDPageRenderCacheCalcBitmapMargin, (FS_LPCBYTE pDIBBuffer,  FS_DIB_Format dibFormat,  FS_INT32 width,  FS_INT32 height,  FS_INT32 stride,  FS_INT32 flag,  FS_DWORD backColor,  FS_INT32 windowSize,  FS_INT32 tolerance,  FS_FloatRect* rtMargin))

NumOfSelector(FPDPageRenderCache)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
//----------_V11----------
//----------_V12----------
//----------_V13----------
//----------_V14----------
//*****************************
/* WinBitmapDevice HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDWinBitmapDeviceNew
 * @details Creates a new empty Windows Bitmap Device object.
 * @param[in]  width The bitmap width.
 * @param[in]  height The bitmap height.
 * @param[in]  format The bitmap format.
 * @return   A new empty Windows Bitmap Device object.
 * @note 
 */
INTERFACE(FPD_WinBitmapDevice, FPDWinBitmapDeviceNew, (FS_INT32 width,  FS_INT32 height,  FS_DIB_Format format))

/**
 * @brief FPDWinBitmapDeviceDestroy
 * @details Destroys the Windows Bitmap Device object.
 * @param[in]  dc The input Windows Bitmap Device object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDWinBitmapDeviceDestroy, (FPD_WinBitmapDevice dc))

/**
 * @brief FPDWinBitmapDeviceGetDC
 * @details Get the Windows Bitmap object.
 * @param[in]  dc The input Windows Bitmap Device object.
 * @return   void* The Windows Bitmap object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.2
 */
INTERFACE(void*, FPDWinBitmapDeviceGetDC, (FPD_WinBitmapDevice dc))

/**
 * @brief FPDWinBitmapDeviceCastToRenderDevice
 * @details Cast to FPD_RenderDevice object.
 * @param[in]  dc The input Windows Bitmap Device object.
 * @return   FPD_RenderDevice   Cast to FPD_RenderDevice object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0
 */
INTERFACE(FPD_RenderDevice, FPDWinBitmapDeviceCastToRenderDevice, (FPD_WinBitmapDevice dc))

NumOfSelector(FPDWinBitmapDevice)
ENDENUM

//*****************************
/* CPWLImage HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_Image, FPDCPWLImageNew, (FPD_CPWLImageCallbacks callbacks))

INTERFACE(void, FPDCPWLImageDelete, (FPD_CPWL_Image img))

INTERFACE(void, FPDCPWLImageGetImageAppStream, (FPD_CPWL_Image img,  FS_ByteString* bsStream,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLImageGetScale, (FPD_CPWL_Image img,  FS_FLOAT* fHScale,  FS_FLOAT* fVScale,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLImageGetImageOffset, (FPD_CPWL_Image img,  FS_FLOAT* x,  FS_FLOAT* y,  FS_BOOLEAN bBaseFun))

INTERFACE(FPD_Object, FPDCPWLImageGetPDFStream, (FPD_CPWL_Image img,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLImageSetPDFStream, (FPD_CPWL_Image img,  FPD_Object pStream))

INTERFACE(void, FPDCPWLImageGetImageSize, (FPD_CPWL_Image img,  FS_FLOAT* fWidth,  FS_FLOAT* fHeight))

INTERFACE(void, FPDCPWLImageGetImageMatrix, (FPD_CPWL_Image img,  FS_AffineMatrix* outMatrix))

INTERFACE(void, FPDCPWLImageGetImageAlias, (FPD_CPWL_Image img,  FS_ByteString* bsAlias))

INTERFACE(void, FPDCPWLImageSetImageAlias, (FPD_CPWL_Image img,  FS_LPCSTR sImageAlias))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLImageGetCPWLWnd, (FPD_CPWL_Image img))

INTERFACE(void, FPDCPWLImageDrawThisAppearance, (FPD_CPWL_Image img,  FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLImageDrawChildAppearance, (FPD_CPWL_Image img,  FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device,  FS_BOOLEAN bBaseFun))

INTERFACE(FPD_CPWL_Image, FPDCPWLImageNew2, ())

NumOfSelector(FPDCPWLImage)
ENDENUM

//*****************************
/* CPWLLabel HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_Label, FPDCPWLLabelNew, (FPD_CPWLLabelCallbacks callback))

INTERFACE(void, FPDCPWLLabelDelete, (FPD_CPWL_Label label))

INTERFACE(void, FPDCPWLLabelGetClassNamePWL, (FPD_CPWL_Label label,  FS_ByteString* bsPWL,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLLabelSetFontSize, (FPD_CPWL_Label label,  FS_FLOAT fFontSize,  FS_BOOLEAN bBaseFun))

INTERFACE(FS_FLOAT, FPDCPWLLabelGetFontSize, (FPD_CPWL_Label label,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLLabelSetDirectionRTL, (FPD_CPWL_Label label,  FS_BOOL bRTL,  FS_BOOL bApplyAllSection,  FS_BOOL bAddUndo,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLLabelSetText, (FPD_CPWL_Label label,  FS_LPCWSTR csText))

INTERFACE(void, FPDCPWLLabelGetText, (FPD_CPWL_Label label,  FS_WideString* wsText))

INTERFACE(void, FPDCPWLLabelSetLimitChar, (FPD_CPWL_Label label,  FS_INT32 nLimitChar))

INTERFACE(void, FPDCPWLLabelSetHorzScale, (FPD_CPWL_Label label,  FS_INT32 nHorzScale))

INTERFACE(void, FPDCPWLLabelSetCharSpace, (FPD_CPWL_Label label,  FS_FLOAT fCharSpace))

INTERFACE(FS_FloatRect, FPDCPWLLabelGetContentRect, (FPD_CPWL_Label label))

INTERFACE(FS_INT32, FPDCPWLLabelGetTotalWords, (FPD_CPWL_Label label))

INTERFACE(void, FPDCPWLLabelGetTextAppearanceStream, (FPD_CPWL_Label label,  const FS_FloatPoint ptOffset,  FR_EDIT_FontData* outFontDataArray,  FS_INT32* outFontDataArrayCount,  FS_BOOL bEmbedded,  FS_ByteString* bsStream))

INTERFACE(void, FPDCPWLLabelDrawPrintAppearance, (FPD_CPWL_Label label,  FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device,  FS_FloatRect popupRect))

INTERFACE(FR_Edit, FPDCPWLLabelGetEdit, (FPD_CPWL_Label label))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLLabelGetCPWLWnd, (FPD_CPWL_Label label))

INTERFACE(void, FPDCPWLLabelOnCreated, (FPD_CPWL_Label label,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLLabelDrawThisAppearance, (FPD_CPWL_Label label,  FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLLabelGetThisAppearanceStream, (FPD_CPWL_Label label,  FS_ByteString* sAppStream,  FR_EDIT_FontData* outFontDataArray,  FS_INT32* outFontDataArrayCount,  FS_BOOLEAN bEmbedded))

INTERFACE(void, FPDCPWLLabelRePosChildWnd, (FPD_CPWL_Label label,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLLabelSetParamByFlag, (FPD_CPWL_Label label))

INTERFACE(FPD_CPWL_Label, FPDCPWLLabelNew2, ())

INTERFACE(void, FPDCPWLLabelSetRichTextByXML, (FPD_CPWL_Label label,  FS_LPCWSTR xml,  FS_LPCWSTR ds,  FS_INT32 charset,  FS_BOOLEAN bAutoSetAgin,  FS_BOOLEAN bSimulateBold))

NumOfSelector(FPDCPWLLabel)
ENDENUM

//*****************************
/* CPWLTimerHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_TimerHandler, FPDCPWLTimerHandlerNew, (FPD_CPWLTimerHandlerCallback callbacks))

INTERFACE(void, FPDCPWLTimerHandlerDestroy, (FPD_CPWL_TimerHandler handler))

INTERFACE(void, FPDCPWLTimerHandlerBeginTimer, (FPD_CPWL_TimerHandler handler,  FS_INT32 nElapse))

INTERFACE(void, FPDCPWLTimerHandlerEndTimer, (FPD_CPWL_TimerHandler handler))

NumOfSelector(FPDCPWLTimerHandler)
ENDENUM

//*****************************
/* CPWLFocusHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_FocusHandler, FPDCPWLFocusHandlerNew, (FPD_CPWLFoucsHandlerCallback callbacks))

INTERFACE(void, FPDCPWLFocusHandlerDestroy, (FPD_CPWL_FocusHandler handler))

NumOfSelector(FPDCPWLFocusHandler)
ENDENUM

//*****************************
/* CPWLProviderHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_Provider, FPDCPWLProviderHandlerNew, (FPD_CPWLProviderCallback callbacks))

INTERFACE(void, FPDCPWLProviderHandlerDestroy, (FPD_CPWL_Provider handler))

NumOfSelector(FPDCPWLProviderHandler)
ENDENUM

//*****************************
/* CPWLWnd HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_Wnd, FPDCPWLWndNew, (FPD_CPWLWndCallback callbacks))

INTERFACE(void, FPDCPWLWndDestroy, (FPD_CPWL_Wnd wnd))

INTERFACE(FPD_CPWL_Label, FPDCPWLWndCreateChildItemPWLLabel, (FPD_CPWL_Wnd wnd,  const FS_LPVOID cp))

INTERFACE(void, FPDCPWLWndCreate, (FPD_CPWL_Wnd wnd,  const FS_LPVOID cp,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLWndGetClassNamePWL, (FPD_CPWL_Wnd wnd,  FS_ByteString* bsName))

INTERFACE(void, FPDCPWLWndMove, (FPD_CPWL_Wnd wnd,  const FS_FloatRect& rcNew,  FS_BOOL bReset,  FS_BOOL bRefresh))

INTERFACE(void, FPDCPWLWndInvalidateRect, (FPD_CPWL_Wnd wnd,  FS_FloatRect pRect))

INTERFACE(void, FPDCPWLWndGetAppearanceStream, (FPD_CPWL_Wnd wnd,  FS_ByteString* sAppStream,  FR_EDIT_FontData* outFontDataArray,  FS_INT32* outFontDataArrayCount,  FS_BOOL bEmbedded))

INTERFACE(void, FPDCPWLWndDrawAppearance, (FPD_CPWL_Wnd wnd,  FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device))

INTERFACE(FS_BOOL, FPDCPWLWndOnKeyDown, (FPD_CPWL_Wnd wnd,  FS_DWORD nChar))

INTERFACE(FS_BOOL, FPDCPWLWndOnKeyUp, (FPD_CPWL_Wnd wnd,  FS_DWORD nChar))

INTERFACE(FS_BOOL, FPDCPWLWndOnChar, (FPD_CPWL_Wnd wnd,  FS_DWORD nChar))

INTERFACE(FS_BOOL, FPDCPWLWndOnLButtonDblClk, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndOnLButtonDown, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndOnLButtonUp, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndOnMButtonDblClk, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndOnMButtonDown, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndOnMButtonUp, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndOnRButtonDblClk, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndOnRButtonDown, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndOnRButtonUp, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndOnMouseMove, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndOnMouseWheel, (FPD_CPWL_Wnd wnd,  FS_SHORT zDelta,  const FS_FloatPoint point))

INTERFACE(void, FPDCPWLWndSetShowTextColor, (FPD_CPWL_Wnd wnd,  FS_COLORREF cShowColor))

INTERFACE(void, FPDCPWLWndSetShowBackColor, (FPD_CPWL_Wnd wnd,  FS_COLORREF cShowBackColor))

INTERFACE(void, FPDCPWLWndSetFocus, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLWndKillFocus, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLWndSetCapture, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLWndReleaseCapture, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLWndOnNotify, (FPD_CPWL_Wnd wnd,  FPD_CPWL_Wnd pWnd,  FS_DWORD msg,  FS_INTPTR wParam,  FS_INTPTR lParam))

INTERFACE(void, FPDCPWLWndSetTextColor, (FPD_CPWL_Wnd wnd,  const FPD_ColorF color,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLWndSetTextStrokeColor, (FPD_CPWL_Wnd wnd,  const FPD_ColorF color))

INTERFACE(void, FPDCPWLWndSetVisible, (FPD_CPWL_Wnd wnd,  FS_BOOL bVisible))

INTERFACE(FS_FloatRect, FPDCPWLWndGetFocusRect, (FPD_CPWL_Wnd wnd))

INTERFACE(FPD_ColorF, FPDCPWLWndGetBackgroundColor, (FPD_CPWL_Wnd wnd))

INTERFACE(FPD_ColorF, FPDCPWLWndGetBorderColor, (FPD_CPWL_Wnd wnd))

INTERFACE(FPD_ColorF, FPDCPWLWndGetTextColor, (FPD_CPWL_Wnd wnd))

INTERFACE(FPD_ColorF, FPDCPWLWndGetTextStrokeColor, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_FLOAT, FPDCPWLWndGetFontSize, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_INT32, FPDCPWLWndGetInnerBorderWidth, (FPD_CPWL_Wnd wnd))

INTERFACE(FPD_ColorF, FPDCPWLWndGetBorderLeftTopColor, (FPD_CPWL_Wnd wnd,  FS_INT32 nBorderStyle))

INTERFACE(FPD_ColorF, FPDCPWLWndGetBorderRightBottomColor, (FPD_CPWL_Wnd wnd,  FS_INT32 nBorderStyle))

INTERFACE(FS_BOOL, FPDCPWLWndIsModified, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLWndSetFontSize, (FPD_CPWL_Wnd wnd,  FS_FLOAT fFontSize))

INTERFACE(void, FPDCPWLWndSetBackgroundColor, (FPD_CPWL_Wnd wnd,  const FPD_ColorF color))

INTERFACE(void, FPDCPWLWndSetBorderColor, (FPD_CPWL_Wnd wnd,  const FPD_ColorF color))

INTERFACE(void, FPDCPWLWndSetBorderWidth, (FPD_CPWL_Wnd wnd,  FS_INT32 nBorderWidth))

INTERFACE(void, FPDCPWLWndSetClipRect, (FPD_CPWL_Wnd wnd,  const FS_FloatRect rect))

INTERFACE(void, FPDCPWLWndSetBorderStyle, (FPD_CPWL_Wnd wnd,  FS_INT32 eBorderStyle))

INTERFACE(void, FPDCPWLWndSetBorderDash, (FPD_CPWL_Wnd wnd,  const FPDCPWL_Dash sDash))

INTERFACE(FS_FloatRect, FPDCPWLWndGetOriginWindowRect, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_FloatRect, FPDCPWLWndGetWindowRect, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_FloatRect, FPDCPWLWndGetClientRect, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_FloatPoint, FPDCPWLWndGetCenterPoint, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_FloatRect, FPDCPWLWndGetClientCenterSquare, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_FloatRect, FPDCPWLWndGetWindowCenterSquare, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_INT32, FPDCPWLWndGetBorderWidth, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_BOOL, FPDCPWLWndIsVisible, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_BOOL, FPDCPWLWndHasFlag, (FPD_CPWL_Wnd wnd,  FS_DWORD dwFlags))

INTERFACE(void, FPDCPWLWndAddFlag, (FPD_CPWL_Wnd wnd,  FS_DWORD dwFlags))

INTERFACE(void, FPDCPWLWndRemoveFlag, (FPD_CPWL_Wnd wnd,  FS_DWORD dwFlags))

INTERFACE(FS_BOOL, FPDCPWLWndIsUseFXFontDeAscent, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_FloatRect, FPDCPWLWndGetClipRect, (FPD_CPWL_Wnd wnd))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLWndGetParentWindow, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_INT32, FPDCPWLWndGetBorderStyle, (FPD_CPWL_Wnd wnd))

INTERFACE(FPDCPWL_Dash, FPDCPWLWndGetBorderDash, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_LPVOID, FPDCPWLWndGetAttachedData, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_BOOL, FPDCPWLWndWndHitTest, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndClientHitTest, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_BOOL, FPDCPWLWndIsCaptureMouse, (FPD_CPWL_Wnd wnd))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLWndGetFocused, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_BOOL, FPDCPWLWndIsFocused, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_BOOL, FPDCPWLWndIsReadOnly, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_LPVOID, FPDCPWLWndGetVScrollBar, (FPD_CPWL_Wnd wnd))

INTERFACE(FR_Edit_FontMap, FPDCPWLWndGetFontMap, (FPD_CPWL_Wnd wnd))

INTERFACE(FPD_CPWL_Provider, FPDCPWLWndGetProvider, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_LPVOID, FPDCPWLWndGetSystemHandler, (FPD_CPWL_Wnd wnd))

INTERFACE(FPD_CPWL_FocusHandler, FPDCPWLWndGetFocusHandler, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_INT32, FPDCPWLWndGetTransparency, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLWndSetTransparency, (FPD_CPWL_Wnd wnd,  FS_INT32 nTransparency))

INTERFACE(FS_AffineMatrix, FPDCPWLWndGetChildToRoot, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_AffineMatrix, FPDCPWLWndGetChildMatrix, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLWndSetChildMatrix, (FPD_CPWL_Wnd wnd,  const FS_AffineMatrix mt))

INTERFACE(FS_AffineMatrix, FPDCPWLWndGetWindowMatrix, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_FloatPoint, FPDCPWLWndChildToParent, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_FloatRect, FPDCPWLWndChildToParent2, (FPD_CPWL_Wnd wnd,  const FS_FloatRect rect))

INTERFACE(FS_FloatPoint, FPDCPWLWndParentToChild, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point))

INTERFACE(FS_FloatRect, FPDCPWLWndParentToChild2, (FPD_CPWL_Wnd wnd,  const FS_FloatRect rect))

INTERFACE(FS_FLOAT, FPDCPWLWndGetItemHeight, (FPD_CPWL_Wnd wnd,  FS_FLOAT fLimitWidth))

INTERFACE(FS_FLOAT, FPDCPWLWndGetItemLeftMargin, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_FLOAT, FPDCPWLWndGetItemRightMargin, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLWndEnableWindow, (FPD_CPWL_Wnd wnd,  FS_BOOL bEnable))

INTERFACE(FS_BOOL, FPDCPWLWndIsEnabled, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLWndSetCursor, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLWndEnableRefresh, (FPD_CPWL_Wnd wnd,  FS_BOOL bRefresh))

INTERFACE(void, FPDCPWLWndGetListTooltip, (FPD_CPWL_Wnd wnd,  const FS_FloatPoint point,  FS_WideString* outwsTip))

INTERFACE(void, FPDCPWLWndSetLayout, (FPD_CPWL_Wnd wnd,  FS_DWORD dwLayout))

INTERFACE(void, FPDCPWLWndSetNofify, (FPD_CPWL_Wnd wnd,  FPD_PWLNotify pNofity))

INTERFACE(void, FPDCPWLWndSetClientRect, (FPD_CPWL_Wnd wnd,  FS_FloatRect crClient))

INTERFACE(FS_FloatRect, FPDCPWLWndGetOwnerClientRect, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_FLOAT, FPDCPWLWndAdpatDPI_X, (FPD_CPWL_Wnd wnd,  FS_FLOAT fSrc))

INTERFACE(FS_FLOAT, FPDCPWLWndAdpatDPI_Y, (FPD_CPWL_Wnd wnd,  FS_FLOAT fSrc))

INTERFACE(void, FPDCPWLWndAddChild, (FPD_CPWL_Wnd wnd,  FPD_CPWL_Wnd spWnd))

INTERFACE(FS_INT32, FPDCPWLWndRemoveChild, (FPD_CPWL_Wnd wnd,  FPD_CPWL_Wnd pWnd))

INTERFACE(void, FPDCPWLWndDrawThisAppearance, (FPD_CPWL_Wnd wnd,  FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLWndCreateChildWnd, (FPD_CPWL_Wnd wnd,  const FS_LPVOID cp,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLWndRePosChildWnd, (FPD_CPWL_Wnd wnd,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLWndGetAppearanceStream2, (FPD_CPWL_Wnd wnd,  FS_ByteString* sAppStream,  FPD_EDITFONTArray* outFontDataArray,  FS_BOOL bEmbedded))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLWndNew2, ())

INTERFACE(void, FPDCPWLWndSetCaretToEnd, (FPD_CPWL_Wnd wnd))

INTERFACE(FPD_PWLNotify, FPDCPWLWndCreateNotify, (FPD_PWLNotifyCallbacks callback))

INTERFACE(void, FPDCPWLWndDeleteNotify, (FPD_PWLNotify notify))

NumOfSelector(FPDCPWLWnd)
ENDENUM

//*****************************
/* CPWLUtils HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FPDCPWLUtilsGetIconAppStream, (FS_INT32 nType,  const FS_FloatRect rect,  const FPD_ColorF crFill,  const FPD_ColorF crStroke,  FS_ByteString* bsStream))

INTERFACE(void, FPDCPWLUtilsDrawIconAppStream, (FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device,  FS_INT32 nType,  const FS_FloatRect rect,  const FPD_ColorF crFill,  const FPD_ColorF crStroke,  const FS_INT32 nTransparancy))

INTERFACE(void, FPDCPWLUtilsGetDBClickWordRange, (FR_Edit pEdit,  FPD_VTWordPlace place,  FS_BOOLEAN bLatin,  FS_BOOLEAN bArabic,  FPD_VTWordRange* outWordRange))

INTERFACE(void, FPDCPWLUtilsGetRectFillAppStream, (FS_FloatRect rect,  FPD_ColorF color,  FS_ByteString* outStream))

INTERFACE(void, FPDCPWLUtilsGetBorderAppStream, (FS_FloatRect rect,  FS_FLOAT fWidth,  FPD_ColorF color,  FPD_ColorF crLeftTop,  FPD_ColorF crRightBottom,  FS_INT32 nStyle,  FPDCPWL_Dash dash,  FS_ByteString* outStream))

INTERFACE(void, FPDCPWLUtilsGetColorAppStream, (FPD_ColorF color,  const FS_BOOLEAN bFillOrStroke,  FS_ByteString* outStream))

INTERFACE(FS_FloatRect, FPDCPWLUtilsInflateRect, (const FS_FloatRect rcRect,  FS_FLOAT fSize))

INTERFACE(void, FPDCPWLUtilsDrawFillRect, (FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device,  const FS_FloatRect& rect,  const FPD_ColorF& color,  FS_INT32 nTransparancy))

INTERFACE(void, FPDCPWLUtilsDrawFillRect2, (FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device,  const FS_FloatRect rect,  const FS_COLORREF color))

INTERFACE(void, FPDCPWLUtilsGetEditAppStream, (FR_Edit pEdit,  const FS_FloatPoint& ptOffset,  const FPD_VTWordRange pRange,  FS_BOOLEAN bContinuous,  FS_WORD SubWord,  FPD_EDITFONTArray* outFontDataArray,  FS_ByteString pPathStream,  FS_BOOLEAN IsEmbedded,  FS_ByteStringArray pFontReference,  FS_ByteString* outStream))

INTERFACE(void, FPDCPWLUtilsPWLColorToARGB, (const FPD_ColorF color,  FS_INT32* alpha,  FS_FLOAT* red,  FS_FLOAT* green,  FS_FLOAT* blue))

INTERFACE(FS_COLORREF, FPDCPWLUtilsPWLColorToFXColor, (const FPD_ColorF color,  FS_INT32 nTransparancy))

INTERFACE(FS_FloatRect, FPDCPWLUtilsDeflateRect, (const FS_FloatRect& rcRect,  FS_FLOAT fSize))

INTERFACE(FPD_ColorF, FPDCPWLUtilsDevideColor, (const FPD_ColorF sColor,  FS_FLOAT fColorDevide))

INTERFACE(void, FPDCPWLUtilsGetCheckBoxAppStream, (const FS_FloatRect rcBBox,  FS_INT32 nStyle,  const FPD_ColorF crText,  FS_ByteString* outStream))

INTERFACE(void, FPDCPWLUtilsGetCircleBorderAppStream, (const FS_FloatRect rect,  FS_FLOAT fWidth,  const FPD_ColorF& color,  const FPD_ColorF& crLeftTop,  const FPD_ColorF& crRightBottom,  FS_INT32 nStyle,  const FPDCPWL_Dash& dash,  FS_ByteString* outStream))

INTERFACE(void, FPDCPWLUtilsGetCircleFillAppStream, (const FS_FloatRect& rect,  const FPD_ColorF& color,  FS_ByteString* outStream))

INTERFACE(void, FPDCPWLUtilsGetDropButtonAppStream, (const FS_FloatRect& rcBBox,  FS_ByteString* outStream))

INTERFACE(void, FPDCPWLUtilsGetPushButtonAppStream, (const FS_FloatRect& rcBBox,  FPD_Edit_FontMap pFontMap,  FPD_Object pIconStream,  FPD_Object* IconFit,  const FS_LPCWSTR sLabel,  const FPD_ColorF& crText,  FS_FLOAT fFontSize,  FS_INT32 nLayOut,  FS_INT32 nFontIndex,  FPD_EDITFONTArray* outFontDataArray,  FS_BOOL bRTL,  FS_ByteStringArray pFontReference,  FS_ByteString* outStream))

INTERFACE(void, FPDCPWLUtilsGetRadioButtonAppStream, (const FS_FloatRect& rcBBox,  FS_INT32 nStyle,  const FPD_ColorF& crText,  FS_ByteString* outStream))

INTERFACE(FPD_ColorF, FPDCPWLUtilsSubstractColor, (const FPD_ColorF& sColor,  FS_FLOAT fColorSub))

INTERFACE(FS_FloatRect, FPDCPWLUtilsGetCenterSquare, (const FS_FloatRect& rect))

INTERFACE(void, FPDCPWLUtilsDrawStrokeRect, (FPD_RenderDevice pDevice,  FS_AffineMatrix pUser2Device,  const FS_FloatRect rect,  const FS_COLORREF color,  FS_FLOAT fWidth))

NumOfSelector(FPDCPWLUtils)
ENDENUM

//*****************************
/* ColorF HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_ColorF, FPDColorFConvertColorType, (FPD_ColorF color,  FS_INT32 other_nColorType))

NumOfSelector(FPDColorF)
ENDENUM

//----------_V15----------
//*****************************
/* SystemHanler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_SystemHandler, FPDSystemHanlerCreateSystemHandler, (FPD_SystemHandlerCallbacks callback))

INTERFACE(void, FPDSystemHanlerDeleteSystemHandler, (FPD_SystemHandler handler))

NumOfSelector(FPDSystemHanler)
ENDENUM

//----------_V16----------
//*****************************
/* Graphics HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDGraphicsCreateGraphics
 * @details Create FPD_Graphics.
 * @return   FPD_Graphics    Create FPD_Graphics.
 * @note 
 */
INTERFACE(FPD_Graphics, FPDGraphicsCreateGraphics, ())

/**
 * @brief FPDGraphicsDeleteGraphics
 * @details Frees the memory of the specified context.
 * @param[in]  graphics The input FPD_Graphics object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGraphicsDeleteGraphics, (FPD_Graphics graphics))

/**
 * @brief FPDGraphicsCreate
 * @details Creates a new screen context with the native screen graphics context.
 * @param[in]  graphics The input FPD_Graphics object.
 * @param[in]  renderDevice The native screen graphics. On Windows, it's a handle of 
	*								 HDC; on Linux, it's a pointer to cairo_t; on Mac, it's a 
	*								 value of CGContextRef.
 * @param[in]  isAntialiasing Whether antialias.
 * @return   FS_INT32
 * @note 
 */
INTERFACE(FS_INT32, FPDGraphicsCreate, (FPD_Graphics graphics,  FPD_RenderDevice  renderDevice,  FS_BOOLEAN isAntialiasing))

NumOfSelector(FPDGraphics)
ENDENUM

//----------_V17----------
//*****************************
/* CustomCursorHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CustomCursorHandler, FPDCustomCursorHandlerNew, (FPD_CustomCursorHandlerCallbacks callback))

INTERFACE(void, FPDCustomCursorHandlerDelete, (FPD_CustomCursorHandler handler))

INTERFACE(void, FPDCustomCursorHandlerSetCustomCursor, (FPD_CustomCursorHandler handler,  FS_INT32 nCursorType,  FS_LPVOID hWnd))

NumOfSelector(FPDCustomCursorHandler)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

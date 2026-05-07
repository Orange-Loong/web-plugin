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
//----------_V15----------
//----------_V16----------
//----------_V17----------
//*****************************
/* FXGInkPath HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFXGInkPathAddPoint
 * @details Add the pressure sensitive ink point to the path.
 * @param[in]  inkPath The input FPD_FXGInkPath.
 * @param[in]  point The point of pressure sensitive ink.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGInkPathAddPoint, (FPD_FXGInkPath inkPath,  const FPD_FXGINKPOINT point))

/**
 * @brief FPDFXGInkPathGeneratePSI
 * @details Generate the PSI data (A vectored data).
 * @param[in]  inkPath The input FPD_FXGInkPath.
 * @param[in]  nType Defined above, FXG_PSI_TYPE_XXX.
 * @param[out]  pData A Pointer to the vectored data. Caller need to interpret the data (s)he needed according to nType.
 * @return   FS_BOOLEAN   true indicate the PSI vector data generate success, otherwise pData has no meaning.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDFXGInkPathGeneratePSI, (FPD_FXGInkPath inkPath,  FS_INT32 nType,  FPD_PathData* pData))

NumOfSelector(FPDFXGInkPath)
ENDENUM

//*****************************
/* FXGPaintModuleMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFXGPaintModuleMgrCreate
 * @details Create a Paint module.
 * @return   FPD_FXGPaintModuleMgr
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGPaintModuleMgr, FPDFXGPaintModuleMgrCreate, ())

/**
 * @brief FPDFXGPaintModuleMgrDestroy
 * @details Destroy the current Paint module.
 * @param[in]  moduleMgr The input FPD_FXGPaintModuleMgr.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGPaintModuleMgrDestroy, (FPD_FXGPaintModuleMgr moduleMgr))

/**
 * @brief FPDFXGPaintModuleMgrGetCanvas
 * @details Get the default canvas, and then you should config it.
 * @param[in]  moduleMgr The input FPD_FXGPaintModuleMgr.
 * @return   FPD_FXGCanvas   A pointer to the default canvas.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGCanvas, FPDFXGPaintModuleMgrGetCanvas, (FPD_FXGPaintModuleMgr moduleMgr))

/**
 * @brief FPDFXGPaintModuleMgrGetPaint
 * @details Get a paint according paint type. The module manage will associate the paint and the default canvas.
 * @param[in]  moduleMgr The input FPD_FXGPaintModuleMgr.
 * @param[in]  nPaintType The input paint type,like FPD_FXGPAINT_xxx.
 * @return   FPD_FXGPaint   A pointer to FPD_FXGPaint.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGPaint, FPDFXGPaintModuleMgrGetPaint, (FPD_FXGPaintModuleMgr moduleMgr,  FS_INT32 nPaintType))

/**
 * @brief FPDFXGPaintModuleMgrSetCacheLimit
 * @details Set the cache limit of the paint nib.
 * @param[in]  moduleMgr The input FPD_FXGPaintModuleMgr.
 * @param[in]  dwLimitSize The size of the cache limit.
 * @return   FPD_FXGPaint   A pointer to FPD_FXGPaint.
 * @note If the caller does not set it, the paint module will use FPD_FXGDEFAULT_CACHE_LIMIT as default
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGPaintModuleMgrSetCacheLimit, (FPD_FXGPaintModuleMgr moduleMgr,  FS_DWORD dwLimitSize))

/**
 * @brief FPDFXGPaintModuleMgrCreatePaintNib
 * @details Create a paint nib according to the nNibType.
	* If the nNibType is FXG_NIB_CUSTOM, the paint module will create the nib according to the
	* canvas(clipped by clip region and the DIB data)
	* The created paint nib managed by the paint module, caller could destroy it only by DestroyPaintNib.
	* If caller does not destroy it manual, it will be free when the paint module Destroy or LoadPaintNib with replace.
 * @param[in]  moduleMgr The input FPD_FXGPaintModuleMgr.
 * @param[in]  pStrName The paint nib name the caller wanna.
 * @param[in]  nNibType The paint nib type defined above, FPD_FXGNIB_FILE_TYPE_XXX. If FPD_FXGNIB_CUSTOM, the pParams value will be ignore.
 * @param[in]  pParams The parameter of the nib according nNibType.
 * @return   FPD_FXGPaintNib   A pointer to FPD_FXGPaint.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGPaintNib, FPDFXGPaintModuleMgrCreatePaintNib, (FPD_FXGPaintModuleMgr moduleMgr,  FS_LPCSTR pStrName,  FS_INT32 nNibType,  FPD_FXGNIBParams pParams))

/**
 * @brief FPDFXGPaintModuleMgrDestroyPaintNib
 * @details If the caller believe that the paint nib is no longer useful, you can destroy it by the method.
 * @param[in]  moduleMgr The input FPD_FXGPaintModuleMgr.
 * @param[in]  pNib The paint nib will bes destroyed.
 * @return   true indicate success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDFXGPaintModuleMgrDestroyPaintNib, (FPD_FXGPaintModuleMgr moduleMgr,  FPD_FXGPaintNib pNib))

/**
 * @brief FPDFXGPaintModuleMgrLoadPaintNib
 * @details Load a set of paint nibs from a file. Reserved now.
 * @param[in]  moduleMgr The input FPD_FXGPaintModuleMgr.
 * @param[in]  pFile The stream access interface.
 * @param[in]  bReplace The flags indicate a new set of paint nibs whether to replace the previous ones.
 * @return   A flag defined above, FPD_FXGPAINT_ERROR_XXX
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDFXGPaintModuleMgrLoadPaintNib, (FPD_FXGPaintModuleMgr moduleMgr,  FS_FileReadHandler pFile,  FS_BOOLEAN bReplace))

/**
 * @brief FPDFXGPaintModuleMgrSavePaintNib
 * @details Load a set of paint nibs from a file. Reserved now.
 * @param[in]  moduleMgr The input FPD_FXGPaintModuleMgr.
 * @param[in]  pFile The stream access interface.
 * @param[in]  nType The flags indicate the encoding nib file's type.
 * @return   A flag defined above, FPD_FXGPAINT_ERROR_XXX
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDFXGPaintModuleMgrSavePaintNib, (FPD_FXGPaintModuleMgr moduleMgr,  FS_FileWriteHandler pFile,  FS_INT32 nType))

/**
 * @brief FPDFXGPaintModuleMgrListAllPaintNib
 * @details List all paint nibs of current set of paint nibs.
 * @param[in]  moduleMgr The input FPD_FXGPaintModuleMgr.
 * @param[out]  nib_array It received a set of current paint nibs.
 * @return   FS_BOOLEAN   true indicate success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDFXGPaintModuleMgrListAllPaintNib, (FPD_FXGPaintModuleMgr moduleMgr,  FS_PtrArray* nib_array))

NumOfSelector(FPDFXGPaintModuleMgr)
ENDENUM

//*****************************
/* FXGNIBParams HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FPDFXGNIBParamsSetbFlipX, (FPD_FXGNIBParams params,  FS_BOOLEAN bFlipx))

INTERFACE(void, FPDFXGNIBParamsSetbFlipY, (FPD_FXGNIBParams params,  FS_BOOLEAN bFlipy))

/**
 * @brief FPDFXGNIBParamsCreate
 * @details Create FPD_FXGNIBParams obj.
 * @return   FPD_FXGNIBParams
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGNIBParams, FPDFXGNIBParamsCreate, ())

/**
 * @brief FPDFXGNIBParamsDelete
 * @details Delete FPD_FXGNIBParams obj.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGNIBParamsDelete, (FPD_FXGNIBParams params))

/**
 * @brief FPDFXGNIBParamsGetDiameter
 * @details Get the nib diameter or line width.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @return   FS_FLOAT
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_FLOAT, FPDFXGNIBParamsGetDiameter, (FPD_FXGNIBParams params))

/**
 * @brief FPDFXGNIBParamsSetDiameter
 * @details Set the nib diameter or line width.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @param[in]  diameter The input nib diameter or line width.
 * @return   FS_FLOAT
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGNIBParamsSetDiameter, (FPD_FXGNIBParams params,  FS_FLOAT diameter))

/**
 * @brief FPDFXGNIBParamsGetbFlipX
 * @details Get the nib whether be horizontal flip.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDFXGNIBParamsGetbFlipX, (FPD_FXGNIBParams params))

/**
 * @brief FPDFXGNIBParamsGetbFlipY
 * @details Get the nib whether be vertical flip.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDFXGNIBParamsGetbFlipY, (FPD_FXGNIBParams params))

/**
 * @brief FPDFXGNIBParamsGetAngle
 * @details Get the nib whether be rotate. In range [0, 360).
 * @param[in]  params The input FPD_FXGNIBParams.
 * @return   FS_FLOAT
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_FLOAT, FPDFXGNIBParamsGetAngle, (FPD_FXGNIBParams params))

/**
 * @brief FPDFXGNIBParamsSetAngle
 * @details Set the nib whether be rotate. In range [0, 360).
 * @param[in]  params The input FPD_FXGNIBParams.
 * @param[in]  fAngle The input nib whether be rotate.
 * @return   FS_FLOAT
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGNIBParamsSetAngle, (FPD_FXGNIBParams params,  FS_FLOAT fAngle))

/**
 * @brief FPDFXGNIBParamsGetRoundness
 * @details Get the nib whether be pinch flat.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @return   FS_FLOAT
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_FLOAT, FPDFXGNIBParamsGetRoundness, (FPD_FXGNIBParams params))

/**
 * @brief FPDFXGNIBParamsSetRoundness
 * @details Set the nib whether be pinch flat.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @param[in]  fRoundness The input the nib whether be pinch flat.
 * @return   FS_FLOAT
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGNIBParamsSetRoundness, (FPD_FXGNIBParams params,  FS_FLOAT fRoundness))

/**
 * @brief FPDFXGNIBParamsGetDashScale
 * @details Get the range is (0, n), n is infinity.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @return   FS_FLOAT
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_FLOAT, FPDFXGNIBParamsGetDashScale, (FPD_FXGNIBParams params))

/**
 * @brief FPDFXGNIBParamsSetDashScale
 * @details Set the nib whether be pinch flat.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @param[in]  fDashScale The input the range is (0, n), n is infinity.
 * @return   FS_FLOAT
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGNIBParamsSetDashScale, (FPD_FXGNIBParams params,  FS_FLOAT fDashScale))

/**
 * @brief FPDFXGNIBParamsGetHardness
 * @details Get FXG_NIB_ROUND, the range is [0, 1].
 * @param[in]  params The input FPD_FXGNIBParams.
 * @return   FS_FLOAT
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_FLOAT, FPDFXGNIBParamsGetHardness, (FPD_FXGNIBParams params))

/**
 * @brief FPDFXGNIBParamsSetHardness
 * @details Set FXG_NIB_ROUND, the range is [0, 1].
 * @param[in]  params The input FPD_FXGNIBParams.
 * @param[in]  fHardness The input FXG_NIB_ROUND, the range is [0, 1].
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGNIBParamsSetHardness, (FPD_FXGNIBParams params,  FS_FLOAT fHardness))

/**
 * @brief FPDFXGNIBParamsGetPath
 * @details Get the path.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @param[out]  outPath Get the path data.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGNIBParamsGetPath, (FPD_FXGNIBParams params,  FPD_PathData* outPath))

/**
 * @brief FPDFXGNIBParamsSetPath
 * @details Set the path.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @param[in]  outPath Set the path.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGNIBParamsSetPath, (FPD_FXGNIBParams params,  FPD_PathData path))

/**
 * @brief FPDFXGNIBParamsGetPattern
 * @details Get the pattern.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @return   FS_DIBitmap
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_DIBitmap, FPDFXGNIBParamsGetPattern, (FPD_FXGNIBParams params))

/**
 * @brief FPDFXGNIBParamsSetPattern
 * @details Set the pattern.
 * @param[in]  params The input FPD_FXGNIBParams.
 * @param[in]  pattern The input pattern.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGNIBParamsSetPattern, (FPD_FXGNIBParams params,  FS_DIBitmap pattern))

NumOfSelector(FPDFXGNIBParams)
ENDENUM

//*****************************
/* FXGCanvas HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFXGCanvasCreate
 * @details Create FPD_FXGCanvas obj.
 * @return   FPD_FXGCanvas
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGCanvas, FPDFXGCanvasCreate, ())

/**
 * @brief FPDFXGCanvasDestroy
 * @details Destroy the current canvas.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGCanvasDestroy, (FPD_FXGCanvas canvas))

/**
 * @brief FPDFXGCanvasSetFilterNotify
 * @details Set the filter notify.Required if the application needs to control real - time flush.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @param[in]  pNotify The notify will be invoked multiple times when rendering. It create by FPDFXGCanvasCreateFilterNofity.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGCanvasSetFilterNotify, (FPD_FXGCanvas canvas,  FPD_FXGFilterNotifyHandler pNotify))

/**
 * @brief FPDFXGCanvasAttachLayer
 * @details Attach an existing bitmap to the canvas. Required if CreateLayer does not used.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @param[in]  pBitmap The bitmap to be attached.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGCanvasAttachLayer, (FPD_FXGCanvas canvas,  FS_DIBitmap pBitmap))

/**
 * @brief FPDFXGCanvasCreateLayer
 * @details Create a new bitmap and attach to the canvas. 
	*           The bitmap will be destroyed when the canvas destructs.
	*           Required if AttachLayer does not used.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @param[in]  nWidth The bitmap width.
 * @param[in]  nHeight The bitmap height.
 * @param[in]  format The bitmap format.
 * @return   false if creation failed (OOM), or true if success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDFXGCanvasCreateLayer, (FPD_FXGCanvas canvas,  FS_INT32 nWidth,  FS_INT32 nHeight,  FS_DIB_Format format))

/**
 * @brief FPDFXGCanvasSetFGColor
 * @details Set the foreground color.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @param[in]  color Set the foreground color of canvas.
 * @return   void
 * @note If the color does not set, the canvas will use black as foreground color.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGCanvasSetFGColor, (FPD_FXGCanvas canvas,  FPD_FXGCOLOR color))

/**
 * @brief FPDFXGCanvasSetBGColor
 * @details Set the background color.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @param[in]  color Set the background color of canvas.
 * @return   void
 * @note If the color does not set, the canvas will use black as background color.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGCanvasSetBGColor, (FPD_FXGCanvas canvas,  FPD_FXGCOLOR color))

/**
 * @brief FPDFXGCanvasSetActiveChannel
 * @details Set the active channel of the canvas. Reserved now.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @param[in]  nChannel Set the channel.
 * @return   void
 * @note If the color does not set, default all channels active, otherwise, the filter process only active channel.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGCanvasSetActiveChannel, (FPD_FXGCanvas canvas,  FS_INT32 nChannel))

/**
 * @brief FPDFXGCanvasGetFilterNotify
 * @details Get current filter notify if exist.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @return   FPD_FXGFilterNotifyHandler
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGFilterNotifyHandler, FPDFXGCanvasGetFilterNotify, (FPD_FXGCanvas canvas))

/**
 * @brief FPDFXGCanvasGetLayer
 * @details Get current layer if exist.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @return   FS_DIBitmap
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_DIBitmap, FPDFXGCanvasGetLayer, (FPD_FXGCanvas canvas))

/**
 * @brief FPDFXGCanvasGetFGColor
 * @details Get current foreground color.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @return   FPD_FXGCOLOR
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGCOLOR, FPDFXGCanvasGetFGColor, (FPD_FXGCanvas canvas))

/**
 * @brief FPDFXGCanvasGetBGColor
 * @details Get current background color.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @return   FPD_FXGCOLOR
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGCOLOR, FPDFXGCanvasGetBGColor, (FPD_FXGCanvas canvas))

/**
 * @brief FPDFXGCanvasGetActiveChannel
 * @details Get current active channel, if -1 indicate that all channels active. Reserved now.
 * @param[in]  canvas The input FPD_FXGCanvas.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDFXGCanvasGetActiveChannel, (FPD_FXGCanvas canvas))

/**
 * @brief FPDFXGCanvasCreateFilterNofity
 * @details Create FPD_FXGFilterNotifyHandler obj.
 * @param[in]  callbacks The input FPD_FXGFilterNotifyCallbacks.
 * @return   FPD_FXGFilterNotifyHandler
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGFilterNotifyHandler, FPDFXGCanvasCreateFilterNofity, (FPD_FXGFilterNotifyCallbacks callbacks))

/**
 * @brief FPDFXGCanvasDeleteFilterNofity
 * @details Delete FPD_FXGFilterNotifyHandler obj.
 * @param[in]  handler The input FPD_FXGFilterNotifyHandler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGCanvasDeleteFilterNofity, (FPD_FXGFilterNotifyHandler handler))

NumOfSelector(FPDFXGCanvas)
ENDENUM

//*****************************
/* FXGPaintNib HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFXGPaintNibGetType
 * @details Get the paint nib type defined in FPD_FXGNIB_xxx.
 * @param[in]  nib The input FPD_FXGPaintNib.
 * @return   FS_INT32     Get the paint nib type.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDFXGPaintNibGetType, (FPD_FXGPaintNib nib))

/**
 * @brief FPDFXGPaintNibGetNib
 * @details Get the paint nib bitmap.
 * @param[in]  nib The input FPD_FXGPaintNib.
 * @return   FS_DIBitmap  Get the bitmap.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_DIBitmap, FPDFXGPaintNibGetNib, (FPD_FXGPaintNib nib))

/**
 * @brief FPDFXGPaintNibGetName
 * @details Get paint nib name.
 * @param[in]  nib The input FPD_FXGPaintNib.
 * @return   FS_LPCSTR  A pointer to the byte string of paint nib name.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_LPCSTR, FPDFXGPaintNibGetName, (FPD_FXGPaintNib nib))

/**
 * @brief FPDFXGPaintNibGetParams
 * @details Get paint nib parameters. User can change the parameters according to nib type.
 * @param[in]  nib The input FPD_FXGPaintNib.
 * @return   FPD_FXGNIBParams  A pointer to the paint nib parameters.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGNIBParams, FPDFXGPaintNibGetParams, (FPD_FXGPaintNib nib))

NumOfSelector(FPDFXGPaintNib)
ENDENUM

//*****************************
/* FXGPaintRenderOption HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFXGPaintRenderOptionCreate
 * @details Create a default rendering option if the user does not need to control the rendering option.
 * @return   FPD_FXGPaintRenderOption
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGPaintRenderOption, FPDFXGPaintRenderOptionCreate, ())

/**
 * @brief FPDFXGPaintRenderOptionDestroy
 * @details Destroy the current paint render option.
 * @param[in]  option The input FPD_FXGPaintRenderOption.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGPaintRenderOptionDestroy, (FPD_FXGPaintRenderOption option))

/**
 * @brief FPDFXGPaintRenderOptionGetBlendMode
 * @details Get blend mode.
 * @param[in]  option The input FPD_FXGPaintRenderOption.
 * @return   FS_INT32    The blending mode defined above, FPD_FXGBLEND_xxx.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDFXGPaintRenderOptionGetBlendMode, (FPD_FXGPaintRenderOption option))

/**
 * @brief FPDFXGPaintRenderOptionGetOpacity
 * @details Get the opacity.
 * @param[in]  option The input FPD_FXGPaintRenderOption.
 * @return   FS_FLOAT         The opacity of the paint foreground, in range [0, 1].
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_FLOAT, FPDFXGPaintRenderOptionGetOpacity, (FPD_FXGPaintRenderOption option))

/**
 * @brief FPDFXGPaintRenderOptionGetFlow
 * @details Get the flow value.
 * @param[in]  option The input FPD_FXGPaintRenderOption.
 * @return   FS_FLOAT         The flow of the paint foreground, in range [0, 1]
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_FLOAT, FPDFXGPaintRenderOptionGetFlow, (FPD_FXGPaintRenderOption option))

/**
 * @brief FPDFXGPaintRenderOptionGetAutoErase
 * @details Automatically erase means that if the canvas color of the starting point is located 
	*          is equal the foreground color, the paint will use background as paint color drawing in pencil mode.
 * @param[in]  option The input FPD_FXGPaintRenderOption.
 * @return   FS_BOOLEAN       true indicate should be automatically erase.
 * @note The property effect in pencil mode(FPD_FXGPAINT_PEN) only.
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDFXGPaintRenderOptionGetAutoErase, (FPD_FXGPaintRenderOption option))

NumOfSelector(FPDFXGPaintRenderOption)
ENDENUM

//*****************************
/* FXGPaint HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFXGPaintGetPaintType
 * @details Get the paint type, defined in FPD_FXGPAINT_XXX, such as, FPD_FXGPAINT_PEN
 * @param[in]  paint The input FPD_FXGPaint.
 * @return   FS_INT32      return FPD_FXGPAINT_XXX type.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDFXGPaintGetPaintType, (FPD_FXGPaint paint))

/**
 * @brief FPDFXGPaintGetInkPath
 * @details Get the ink path, then if the paint is prepared, caller can add point to the path.
 * @param[in]  paint The input FPD_FXGPaint.
 * @return   FPD_FXGInkPath
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGInkPath, FPDFXGPaintGetInkPath, (FPD_FXGPaint paint))

/**
 * @brief FPDFXGPaintAddPathFilter
 * @details Adds a specific path filter to IFXG_InkPath.
 * @param[in]  paint The input FPD_FXGPaint.
 * @param[in]  nFilter A path filter type indicate in FPD_FXGPATH_FILTER_XXX above.
 * @return   FS_BOOLEAN        true indicate success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDFXGPaintAddPathFilter, (FPD_FXGPaint paint,  FS_INT32 nFilter))

/**
 * @brief FPDFXGPaintRemovePathFilter
 * @details Removes a specific path filter from IFXG_InkPath.
 * @param[in]  paint The input FPD_FXGPaint.
 * @param[in]  nFilter A path filter type indicate in FPD_FXGPATH_FILTER_XXX above.
 * @return   FS_BOOLEAN        true indicate success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDFXGPaintRemovePathFilter, (FPD_FXGPaint paint,  FS_INT32 nFilter))

/**
 * @brief FPDFXGPaintGetPaintNib
 * @details Get current paint nib.
 * @param[in]  paint The input FPD_FXGPaint.
 * @return   FPD_FXGPaintNib   A pointer to the IFXG_PaintNib.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGPaintNib, FPDFXGPaintGetPaintNib, (FPD_FXGPaint paint))

/**
 * @brief FPDFXGPaintSetPaintNib
 * @details Set the paint nib as current nib.
 * @param[in]  paint The input FPD_FXGPaint.
 * @param[in]  pPaintNib A pointer to the IFXG_PaintNib.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGPaintSetPaintNib, (FPD_FXGPaint paint,  FPD_FXGPaintNib pPaintNib))

/**
 * @brief FPDFXGPaintSetRenderOption
 * @details Set the rendering option to the paint.
 * @param[in]  paint The input FPD_FXGPaint.
 * @param[in]  pRenderOption A pointer to the IFXG_PaintRenderOption.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGPaintSetRenderOption, (FPD_FXGPaint paint,  FPD_FXGPaintRenderOption pRenderOption))

/**
 * @brief FPDFXGPaintGetFilterType
 * @details Get the filter type.
 * @param[in]  paint The input FPD_FXGPaint.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDFXGPaintGetFilterType, (FPD_FXGPaint paint))

/**
 * @brief FPDFXGPaintSetCanvas
 * @details Associated filter and canvas.
 * @param[in]  paint The input FPD_FXGPaint.
 * @param[in]  pCanvas The canvas to be associated with the filter.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDFXGPaintSetCanvas, (FPD_FXGPaint paint,  FPD_FXGCanvas pCanvas))

/**
 * @brief FPDFXGPaintGetCanvas
 * @details Get the associated canvas if exist.
 * @param[in]  paint The input FPD_FXGPaint.
 * @return   FPD_FXGCanvas    A pointer to IFXG_Canvas.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_FXGCanvas, FPDFXGPaintGetCanvas, (FPD_FXGPaint paint))

/**
 * @brief FPDFXGPaintPrepare
 * @details Prepare the filter.
 * @param[in]  paint The input FPD_FXGPaint.
 * @return   FS_BOOLEAN    true indicate success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDFXGPaintPrepare, (FPD_FXGPaint paint))

/**
 * @brief FPDFXGPaintRender
 * @details If the filter is ready by Prepare, then we can start rendering.
 * @param[in]  paint The input FPD_FXGPaint.
 * @param[in]  pPause The input FS_PauseHandler.
 * @return   FS_INT32    Flag defined like FPD_FXGFILTER_RENDER_XXX.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDFXGPaintRender, (FPD_FXGPaint paint,  FS_PauseHandler pPause))

NumOfSelector(FPDFXGPaint)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

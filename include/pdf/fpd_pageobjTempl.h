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
/* Path HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDPathNew
 * @details Creates a new empty PDF path data object.
 * @return   A new empty PDF path data object.
 * @note 
 */
INTERFACE(FPD_Path, FPDPathNew, (void))

/**
 * @brief FPDPathDestroy
 * @details Destroys the PDF path data object.
 * @param[in]  path The input PDF path data object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathDestroy, (FPD_Path path))

/**
 * @brief FPDPathGetPointCount
 * @details Gets the point count int the path.
 * @param[in]  path The input PDF path data object.
 * @return   The point count int the path.
 * @note 
 */
INTERFACE(FS_INT32, FPDPathGetPointCount, (FPD_Path path))

/**
 * @brief FPDPathGetFlag
 * @details Gets the flag of specified path point.
 * @param[in]  path The input PDF path data object.
 * @param[in]  index Specifies the zero-based index of path point in the path.
 * @return   The flag of specified path point.
 * @note 
 */
INTERFACE(FS_INT32, FPDPathGetFlag, (FPD_Path path,  FS_INT32 index))

/**
 * @brief FPDPathGetPointX
 * @details Gets the x-coordinate of specified path point.
 * @param[in]  path The input PDF path data object.
 * @param[in]  index Specifies the zero-based index of path point in the path.
 * @return   The x-coordinate of specified path point.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDPathGetPointX, (FPD_Path path,  FS_INT32 index))

/**
 * @brief FPDPathGetPointY
 * @details Gets the y-coordinate of specified path point.
 * @param[in]  path The input PDF path data object.
 * @param[in]  index Specifies the zero-based index of path point in the path.
 * @return   The y-coordinate of specified path point.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDPathGetPointY, (FPD_Path path,  FS_INT32 index))

/**
 * @brief FPDPathGetPoint
 * @details Gets the path point in the path points array by the index.
 * @param[in]  path The input PDF path data object.
 * @param[in]  index The point index in the points array.
 * @return   The path point in the path points array by the index.
 * @note 
 */
INTERFACE(FS_PATHPOINT, FPDPathGetPoint, (FPD_Path path,  FS_INT32 index))

/**
 * @brief FPDPathGetBoundingBox
 * @details Gets bounding box of all control points.
 * @param[in]  path The input PDF path data object.
 * @return   The bounding box of all control points.
 * @note The result can be used as the bounding box of the whole filled path.
	*            However, when path is stroked using geometry pen, the actual bounding box can be much larger.
 */
INTERFACE(FS_FloatRect, FPDPathGetBoundingBox, (FPD_Path path))

/**
 * @brief FPDPathGetBoundingBox2
 * @details Calculates bounding box (guaranteed to contain all path, may be larger) for stroked path.
 * @param[in]  path The input PDF path data object.
 * @param[in]  lineWidth The line width used in stroking.
 * @param[in]  miterLimit The miter limit value for line joint in stroking.
 * @return   The bounding box for stroked path.
 * @note 
 */
INTERFACE(FS_FloatRect, FPDPathGetBoundingBox2, (FPD_Path path,  FS_FLOAT lineWidth,  FS_FLOAT miterLimit))

/**
 * @brief FPDPathTransform
 * @details Transforms this path.
 * @param[in]  path The input PDF path data object.
 * @param[in]  matrix The input matrix used to transform.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathTransform, (FPD_Path path,  FS_AffineMatrix matrix))

/**
 * @brief FPDPathAppend
 * @details Appends a path. Optionally a matrix can be specified to transform the source path before appending.
 * @param[in]  path The input PDF path data object.
 * @param[in]  src The source path.
 * @param[in]  pMatrix The specified matrix. <a>NULL</a> means no transformation.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathAppend, (FPD_Path path,  FPD_Path src,  FS_AffineMatrix* pMatrix))

/**
 * @brief FPDPathAppendRect
 * @details Appends a rectangle.
 * @param[in]  path The input PDF path data object.
 * @param[in]  left The x-coordinate of the left-bottom corner.
 * @param[in]  bottom The y-coordinate of the left-bottom corner.
 * @param[in]  right The x-coordinate of the right-top corner.
 * @param[in]  top The y-coordinate of the right-top corner.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathAppendRect, (FPD_Path path,  FS_FLOAT left,  FS_FLOAT bottom,  FS_FLOAT right,  FS_FLOAT top))

/**
 * @brief FPDPathIsRect
 * @details Tests whether the path is a actually rectangle.
 * @param[in]  path The input PDF path data object.
 * @return   <a>TRUE</a> if the path is actually a rectangle, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDPathIsRect, (FPD_Path path))

/**
 * @brief FPDPathSetPointCount
 * @details Changes the path point count and prepares adequate allocated buffer.
 * @param[in]  path The input PDF path data object.
 * @param[in]  nPoints The new count of path point to change.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathSetPointCount, (FPD_Path path,  FS_INT32 nPoints))

/**
 * @brief FPDPathSetPoint
 * @details Sets the point data for specified path point.
 * @param[in]  path The input PDF path data object.
 * @param[in]  index Specifies the zero-based index of path point in the path.
 * @param[in]  x The x-coordinate of the point to set.
 * @param[in]  y The y-coordinate of the point to set.
 * @param[in]  flag The flag of the point to set.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathSetPoint, (FPD_Path path,  FS_INT32 index,  FS_FLOAT x,  FS_FLOAT y,  FS_INT32 flag))

/**
 * @brief FPDPathGetModify
 * @details The interface helps init the object if the object is NULL.
 * @param[in]  path The input PDF path data object.
 * @return   FPD_PathData.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FPD_PathData, FPDPathGetModify, (FPD_Path path))

/**
 * @brief FPDPathTrimPoints
 * @details Trim the number of path point in the path data to specified number.
 * @param[in]  path The input PDF path data object.
 * @param[in]  nPoints The new count of path point to trim to.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDPathTrimPoints, (FPD_Path path,  FS_INT32 nPoints))

/**
 * @brief FPDPathTransformPathData
 * @details Transforms the path data.
 * @param[in]  path The input PDF path data object.
 * @param[in]  matrix The input matrix used to transform.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDPathTransformPathData, (FPD_Path path,  FS_AffineMatrix matrix))

/**
 * @brief FPDPathCopy
 * @details Copy a path data.
 * @param[in]  path The input PDF path data object.
 * @return   FPD_Path
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FPD_Path, FPDPathCopy, (FPD_Path path))

/**
 * @brief FPDPathAddPointCount
 * @details Add number of path point to the path data and prepare adequate allocated buffer.
 * @param[in]  path The input PDF path data object.
 * @param[in]  addPoints The count of path point to add.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0
 */
INTERFACE(FS_BOOLEAN, FPDPathAddPointCount, (FPD_Path path,  FS_INT32 addPoints))

NumOfSelector(FPDPath)
ENDENUM

//*****************************
/* ClipPath HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDClipPathNew
 * @details Creates a new empty clip path data object.
 * @return   A new empty clip path data object.
 * @note 
 */
INTERFACE(FPD_ClipPath, FPDClipPathNew, (void))

/**
 * @brief FPDClipPathDestroy
 * @details Destroys the clip path data object.
 * @param[in]  path The input clip path data object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDClipPathDestroy, (FPD_ClipPath path))

/**
 * @brief FPDClipPathAppendPath
 * @details Appends a clipping path.
 * @param[in]  path The input clip path data object.
 * @param[in]  pathAppendTo The input clipping path.
 * @param[in]  type The clip type of the input clipping path.
 * @param[in]  bAutoMerge Whether to merge the clipping path automatically.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDClipPathAppendPath, (FPD_ClipPath path,  FPD_Path pathAppendTo,  FS_INT32 type,  FS_BOOL bAutoMerge))

/**
 * @brief FPDClipPathDeletePath
 * @details Removes a path from path list.
 * @param[in]  path The input clip path data object.
 * @param[in]  layerIndex The path index to remove.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDClipPathDeletePath, (FPD_ClipPath path,  FS_INT32 layerIndex))

/**
 * @brief FPDClipPathGetPathCount
 * @details Gets the count of paths in the clip path.
 * @param[in]  path The input clip path data object.
 * @return   The count of paths in the clip path.
 * @note 
 */
INTERFACE(FS_DWORD, FPDClipPathGetPathCount, (FPD_ClipPath path))

/**
 * @brief FPDClipPathTransform
 * @details Transforms this path.
 * @param[in]  path The input clip path data object.
 * @param[in]  matrix The input matrix used to transform.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDClipPathTransform, (FPD_ClipPath path,  const FS_AffineMatrix matrix))

/**
 * @brief FPDClipPathGetPath
 * @details Gets a path.
 * @param[in]  path The input clip path data object.
 * @param[in]  index Specifies the zero-based path index in the clip path.
 * @param[out]  outPath It receives the path.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDClipPathGetPath, (FPD_ClipPath path,  FS_INT32 index,  FPD_Path* outPath))

/**
 * @brief FPDClipPathGetClipType
 * @details Gets the clip type of specified path.
 * @param[in]  path The input clip path data object.
 * @param[in]  index Specifies the zero-based path index in the clip path
 * @return   The clip type of specified path
 * @note 
 */
INTERFACE(FS_INT32, FPDClipPathGetClipType, (FPD_ClipPath path,  FS_INT32 index))

/**
 * @brief FPDClipPathGetTextCount
 * @details Gets the count of text objects in the clip path.
 * @param[in]  path The input clip path data object.
 * @return   The count of text objects in the clip path.
 * @note 
 */
INTERFACE(FS_DWORD, FPDClipPathGetTextCount, (FPD_ClipPath path))

/**
 * @brief FPDClipPathGetClipBox
 * @details Gets the clip box of the clip path.
 * @param[in]  path The input clip path data object.
 * @return   The clip box of the clip path.
 * @note 
 */
INTERFACE(FS_FloatRect, FPDClipPathGetClipBox, (FPD_ClipPath path))

/**
 * @brief FPDClipPathGetText
 * @details Gets a text object.
 * @param[in]  path The input clip path data object.
 * @param[in]  i Specifies the zero-based text object index in the clip path.
 * @return   A text object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDClipPathGetText, (FPD_ClipPath path,  FS_INT32 i))

/**
 * @brief FPDClipPathAppendTexts
 * @details Appends clipping text objects.
 * @param[in]  path The input clip path data object.
 * @param[in]  pTextsBuf Pointer to clipping text objects to append.
 * @param[in]  count The count of clipping text objects to append.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDClipPathAppendTexts, (FPD_ClipPath path,  FPD_PageObject* pTextsBuf,  FS_INT32 count))

/**
 * @brief FPDClipPathSetCount
 * @details Estimates the count of path and text in the clip path data, and allocate the memory.
 * @param[in]  path The input clip path data object.
 * @param[in]  path_count The estimated count of path in the clip path data.
 * @param[in]  text_count The estimated count of text object in the clip path data.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDClipPathSetCount, (FPD_ClipPath path,  FS_INT32 path_count,  FS_INT32 text_count))

/**
 * @brief FPDClipPathIsNull
 * @details Tests whether the path data object is <a>NULL</a> or not.
 * @param[in]  path The input clip path data object.
 * @return   Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDClipPathIsNull, (FPD_ClipPath path))

/**
 * @brief FPDClipPathGetModify
 * @details The interface helps init the object if the object is NULL.
 * @param[in]  path The input clip path data object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDClipPathGetModify, (FPD_ClipPath path))

/**
 * @brief FPDClipPathGetPathPointer
 * @details Gets the pointer to the specified path.
 * @param[in]  path The input clip path data object.
 * @param[in]  index Specifies the zero-based path index in the clip path.
 * @return   The pointer to the specified path.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FPD_Path, FPDClipPathGetPathPointer, (FPD_ClipPath path,  FS_INT32 index))

/**
 * @brief FPDClipPathCopy
 * @details Copy clip path data object.
 * @param[in]  path The input clip path data object.
 * @return   FPD_ClipPath.
 * @note 
 */
INTERFACE(FPD_ClipPath, FPDClipPathCopy, (FPD_ClipPath path))

NumOfSelector(FPDClipPath)
ENDENUM

//*****************************
/* ColorState HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDColorStateNew
 * @details Creates a new empty PDF color state object.
 * @param[in]  void 
 * @return   A new empty PDF color state object.
 * @note 
 */
INTERFACE(FPD_ColorState, FPDColorStateNew, (void))

/**
 * @brief FPDColorStateDestroy
 * @details Destroys the PDF color state object.
 * @param[in]  clrState The input PDF color state object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorStateDestroy, (FPD_ColorState clrState))

/**
 * @brief FPDColorStateGetFillColor
 * @details Gets the filling color.
 * @param[in]  clrState The input PDF color state object.
 * @return   The filling color.
 * @note 
 */
INTERFACE(FPD_Color, FPDColorStateGetFillColor, (FPD_ColorState clrState))

/**
 * @brief FPDColorStateGetStrokeColor
 * @details Gets the stroking color.
 * @param[in]  clrState The input PDF color state object.
 * @return   The stroking color.
 * @note 
 */
INTERFACE(FPD_Color, FPDColorStateGetStrokeColor, (FPD_ColorState clrState))

/**
 * @brief FPDColorStateSetFillColor
 * @details Sets the filling normal color.
 * @param[in]  clrState The input PDF color state object.
 * @param[in]  clrSpace The color space of the filling color.
 * @param[in]  pValue The color component values in the specified color space.
 * @param[in]  nValues The count of the input parameters.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorStateSetFillColor, (FPD_ColorState clrState,  FPD_ColorSpace clrSpace,  FS_FLOAT* pValue,  FS_INT32 nValues))

/**
 * @brief FPDColorStateSetStrokeColor
 * @details Sets the stroking normal color.
 * @param[in]  clrState The input PDF color state object.
 * @param[in]  clrSpace The color space of the stroking color.
 * @param[in]  pValue The color component values in the specified color space.
 * @param[in]  nValues The count of the input parameters.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorStateSetStrokeColor, (FPD_ColorState clrState,  FPD_ColorSpace clrSpace,  FS_FLOAT* pValue,  FS_INT32 nValues))

/**
 * @brief FPDColorStateSetFillPatternColor
 * @details Sets the filling pattern color.
 * @param[in]  clrState The input PDF color state object.
 * @param[in]  pattern The input pattern.
 * @param[in]  pValue The input parameters for the pattern color.
 * @param[in]  nValues The count of the input parameters.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorStateSetFillPatternColor, (FPD_ColorState clrState,  FPD_Pattern pattern,  FS_FLOAT* pValue,  int nValues))

/**
 * @brief FPDColorStateSetStrokePatternColor
 * @details Sets the stroking pattern color.
 * @param[in]  clrState The input PDF color state object.
 * @param[in]  pattern The input pattern.
 * @param[in]  pValue The input parameters for the pattern color.
 * @param[in]  nValues The count of the input parameters.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDColorStateSetStrokePatternColor, (FPD_ColorState clrState,  FPD_Pattern pattern,  FS_FLOAT* pValue,  int nValues))

/**
 * @brief FPDColorStateIsNull
 * @details Tests whether the color state object is <a>NULL</a> or not.
 * @param[in]  clrState The input PDF color state object.
 * @return   Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDColorStateIsNull, (FPD_ColorState clrState))

/**
 * @brief FPDColorStateGetModify
 * @details The interface helps init the object if the object is NULL.
 * @param[in]  clrState The input PDF color state object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDColorStateGetModify, (FPD_ColorState clrState))

/**
 * @brief FPDColorStateNotUseFillColor
 * @details Do not use the filling mode.
 * @param[in]  clrState The input PDF color state object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDColorStateNotUseFillColor, (FPD_ColorState clrState))

/**
 * @brief FPDColorStateCopy
 * @details Copy color state object.
 * @param[in]  colorState The input PDF color state object.
 * @return   FPD_ColorState.
 * @note 
 */
INTERFACE(FPD_ColorState, FPDColorStateCopy, (FPD_ColorState colorState))

NumOfSelector(FPDColorState)
ENDENUM

//*****************************
/* TextState HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDTextStateNew
 * @details Creates a new empty PDF text state object.
 * @param[in]  void 
 * @return   A new empty PDF text state object.
 * @note 
 */
INTERFACE(FPD_TextState, FPDTextStateNew, (void))

/**
 * @brief FPDTextStateDestroy
 * @details Destroys the PDF text state object.
 * @param[in]  textState The input PDF text state object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextStateDestroy, (FPD_TextState textState))

/**
 * @brief FPDTextStateGetFont
 * @details Gets the font.
 * @param[in]  textState The input PDF text state object.
 * @return   The font.
 * @note 
 */
INTERFACE(FPD_Font, FPDTextStateGetFont, (FPD_TextState textState))

/**
 * @brief FPDTextStateSetFont
 * @details Sets the font.
 * @param[in]  textState The input PDF text state object.
 * @param[in]  font The font to set.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextStateSetFont, (FPD_TextState textState,  FPD_Font font))

/**
 * @brief FPDTextStateGetFontSize
 * @details Gets the font size.
 * @param[in]  textState The input PDF text state object.
 * @return   The font size.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTextStateGetFontSize, (FPD_TextState textState))

/**
 * @brief FPDTextStateGetMatrix
 * @details Gets The text transformation matrix. Tt has 4 items.(matrix[4]).
 * @param[in]  textState The input PDF text state object.
 * @return   The text transformation matrix. It has 4 items.(matrix[4]).
 * @note 
 */
INTERFACE(FS_FLOAT*, FPDTextStateGetMatrix, (FPD_TextState textState))

/**
 * @brief FPDTextStateGetFontSizeV
 * @details Gets the vertical size in device units.
 * @param[in]  textState The input PDF text state object.
 * @return   The vertical size in device units.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTextStateGetFontSizeV, (FPD_TextState textState))

/**
 * @brief FPDTextStateGetFontSizeH
 * @details Gets the horizontal size in device units
 * @param[in]  textState The input PDF text state object.
 * @return   The horizontal size in device units
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTextStateGetFontSizeH, (FPD_TextState textState))

/**
 * @brief FPDTextStateGetBaselineAngle
 * @details Gets the angle between device space X-axis and text baseline. In radians.
 * @param[in]  textState The input PDF text state object.
 * @return   The angle between device space X-axis and text baseline. In radians.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTextStateGetBaselineAngle, (FPD_TextState textState))

/**
 * @brief FPDTextStateGetShearAngle
 * @details Gets the angle that text space Y-axis shears in device space. In radians.
 * @param[in]  textState The input PDF text state object.
 * @return   The angle that text space Y-axis shears in device space. In radians.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTextStateGetShearAngle, (FPD_TextState textState))

/**
 * @brief FPDTextStateSetFontSize
 * @details Sets the font size.
 * @param[in]  textState The input PDF text state object.
 * @param[in]  fontSize The input font size.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextStateSetFontSize, (FPD_TextState textState,  FS_FLOAT fontSize))

/**
 * @brief FPDTextStateSetCharSpace
 * @details Sets the character space.
 * @param[in]  textState The input PDF text state object.
 * @param[in]  fCharSpace The input character space.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextStateSetCharSpace, (FPD_TextState textState,  FS_FLOAT fCharSpace))

/**
 * @brief FPDTextStateSetWordSpace
 * @details Sets the word space.
 * @param[in]  textState The input PDF text state object.
 * @param[in]  fWordSpace The input word space.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextStateSetWordSpace, (FPD_TextState textState,  FS_FLOAT fWordSpace))

/**
 * @brief FPDTextStateSetMatrix
 * @details Sets the text transformation matrix.
 * @param[in]  textState The input PDF text state object.
 * @param[in]  matrix The input text transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextStateSetMatrix, (FPD_TextState textState,  FS_FLOAT	matrix[4]))

/**
 * @brief FPDTextStateSetTextMode
 * @details Sets the text mode.
 * @param[in]  textState The input PDF text state object.
 * @param[in]  iTextMode The input text mode. Only 0 is valid in this version.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextStateSetTextMode, (FPD_TextState textState,  FS_INT32 iTextMode))

/**
 * @brief FPDTextStateSetTextCTM
 * @details Sets the CTM for stroking purpose.
 * @param[in]  textState The input PDF text state object.
 * @param[in]  CTM The input CTM.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextStateSetTextCTM, (FPD_TextState textState,  FS_FLOAT CTM[4]))

/**
 * @brief FPDTextStateGetTextMode
 * @details Gets the text mode.
 * @param[in]  textState The input PDF text state object.
 * @return   The text mode.
 * @note 
 */
INTERFACE(FS_INT32, FPDTextStateGetTextMode, (FPD_TextState textState))

/**
 * @brief FPDTextStateGetTextCTM
 * @details Gets the CTM for stroking purpose. The CTM array must be allocated and freed by caller. 
	* It must contain 4 elements.
 * @param[in]  textState The input PDF text state object.
 * @param[out]  outCTM It receives the text CTM for stroking purpose.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextStateGetTextCTM, (FPD_TextState textState,  FS_FLOAT* outCTM))

/**
 * @brief FPDTextStateGetCharSpace
 * @details Gets the character space.
 * @param[in]  textState The input PDF text state object.
 * @return   The character space.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTextStateGetCharSpace, (FPD_TextState textState))

/**
 * @brief FPDTextStateGetWordSpace
 * @details Gets the word space.
 * @param[in]  textState The input PDF text state object.
 * @return   The word space.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTextStateGetWordSpace, (FPD_TextState textState))

/**
 * @brief FPDTextStateIsNull
 * @details Tests whether the text state object is <a>NULL</a> or not.
 * @param[in]  textState The input PDF text state object.
 * @return   Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDTextStateIsNull, (FPD_TextState textState))

/**
 * @brief FPDTextStateGetModify
 * @details The interface helps init the object if the object is NULL.
 * @param[in]  textState The input PDF text state object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDTextStateGetModify, (FPD_TextState textState))

NumOfSelector(FPDTextState)
ENDENUM

//*****************************
/* GeneralState HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDGeneralStateNew
 * @details Creates a new empty PDF general state object.
 * @param[in]  void 
 * @return   A new empty PDF general state object.
 * @note 
 */
INTERFACE(FPD_GeneralState, FPDGeneralStateNew, (void))

/**
 * @brief FPDGeneralStateDestroy
 * @details Destroys the PDF general state data object.
 * @param[in]  genState The input PDF general state data object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGeneralStateDestroy, (FPD_GeneralState genState))

/**
 * @brief FPDGeneralStateSetRenderIntent
 * @details Sets the rendering intent.
 * @param[in]  genState The input PDF general state data object.
 * @param[in]  ri The input rendering intent.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGeneralStateSetRenderIntent, (FPD_GeneralState genState,  FS_LPCSTR ri))

/**
 * @brief FPDGeneralStateGetBlendType
 * @details Gets the blend mode.
 * @param[in]  genState The input PDF general state data object.
 * @return   The blend mode.
 * @note 
 */
INTERFACE(FS_INT32, FPDGeneralStateGetBlendType, (FPD_GeneralState genState))

/**
 * @brief FPDGeneralStateGetAlpha
 * @details Gets the current filling or stroking alpha constant.
 * @param[in]  genState The input PDF general state data object.
 * @param[in]  bStroke Whether to get the current stroking alpha constant.
 * @return   The current filling or stroking alpha constant.
 * @note 
 */
INTERFACE(FS_INT32, FPDGeneralStateGetAlpha, (FPD_GeneralState genState,  FS_BOOL bStroke))

/**
 * @brief FPDGeneralStateSetBlendMode
 * @details Sets the current blend mode name.
 * @param[in]  genState The input PDF general state data object.
 * @param[in]  BlendMode The input current blend mode name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGeneralStateSetBlendMode, (FPD_GeneralState genState,  char BlendMode[16]))

/**
 * @brief FPDGeneralStateSetBlendType
 * @details Sets the current blend mode to be used in the transparent imaging model.
 * @param[in]  genState The input PDF general state data object.
 * @param[in]  iBlendType The input blend type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGeneralStateSetBlendType, (FPD_GeneralState genState,  FS_INT32 iBlendType))

/**
 * @brief FPDGeneralStateSetSoftMask
 * @details Sets the current soft mask, specifying the mask shape or mask opacity values to be used in the transparent imaging model.
 * @param[in]  genState The input PDF general state data object.
 * @param[in]  softMask The input current soft mask.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGeneralStateSetSoftMask, (FPD_GeneralState genState,  FPD_Object softMask))

/**
 * @brief FPDGeneralStateSetSoftMaskMatrix
 * @details Sets the matrix of the current soft mask.
 * @param[in]  genState The input PDF general state data object.
 * @param[in]  SoftMaskMatrix The input matrix of the current soft mask.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGeneralStateSetSoftMaskMatrix, (FPD_GeneralState genState,  FS_FLOAT SoftMaskMatrix[6]))

/**
 * @brief FPDGeneralStateSetStrokeAlpha
 * @details Sets The current stroking alpha constant, specifying the constant shape or constant 
	*            opacity value to be used for stroking operations in the transparent imaging model.
 * @param[in]  genState The input PDF general state data object.
 * @param[in]  fStrokeAlpha The input current stroking alpha constant.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGeneralStateSetStrokeAlpha, (FPD_GeneralState genState,  FS_FLOAT fStrokeAlpha))

/**
 * @brief FPDGeneralStateSetFillAlpha
 * @details Same as stroking alpha, but for non-stroking operations.
 * @param[in]  genState The input PDF general state data object.
 * @param[in]  fFillAlpha The input current filling alpha constant.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGeneralStateSetFillAlpha, (FPD_GeneralState genState,  FS_FLOAT fFillAlpha))

/**
 * @brief FPDGeneralStateIsNull
 * @details Tests whether the general state object is <a>NULL</a> or not.
 * @param[in]  genState The input PDF general state data object.
 * @return   Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDGeneralStateIsNull, (FPD_GeneralState genState))

/**
 * @brief FPDGeneralStateGetModify
 * @details The interface helps init the object if the object is NULL.
 * @param[in]  genState The input PDF general state object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDGeneralStateGetModify, (FPD_GeneralState genState))

NumOfSelector(FPDGeneralState)
ENDENUM

//*****************************
/* GraphState HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDGraphStateNew
 * @details Creates a new empty PDF graphic state object.
 * @param[in]  void 
 * @return   A new empty PDF graphic state object.
 * @note 
 */
INTERFACE(FPD_GraphState, FPDGraphStateNew, (void))

/**
 * @brief FPDGraphStateDestroy
 * @details Destroys a graphic state object.
 * @param[in]  graphState The graphic state object to be destroyed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGraphStateDestroy, (FPD_GraphState graphState))

/**
 * @brief FPDGraphStateSetDashCount
 * @details In order to keep heap integrity, the function is used to allocate enough buffer for dash array.
 * @param[in]  graphState The input graphic state object.
 * @param[in]  count The new count of dash points.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGraphStateSetDashCount, (FPD_GraphState graphState,  FS_INT32 count))

/**
 * @brief FPDGraphStateGetDashCount
 * @details Gets the total size of dash array.
 * @param[in]  graphState The input graphic state object.
 * @return   The total size of dash array.
 * @note 
 */
INTERFACE(FS_INT32, FPDGraphStateGetDashCount, (FPD_GraphState graphState))

/**
 * @brief FPDGraphStateGetDashArray
 * @details Gets the dash array.
 * @param[in]  graphState The input graphic state object.
 * @return   The dash array used by graphic state object.
 * @note 
 */
INTERFACE(FS_FLOAT*, FPDGraphStateGetDashArray, (FPD_GraphState graphState))

/**
 * @brief FPDGraphStateGetDashPhase
 * @details Gets the dash phase for line dash pattern.
 * @param[in]  graphState The input graphic state object.
 * @return   The dash phase for line dash pattern.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDGraphStateGetDashPhase, (FPD_GraphState graphState))

/**
 * @brief FPDGraphStateSetDashPhase
 * @details Sets the new dash phase for line dash pattern.
 * @param[in]  graphState The input graphic state object.
 * @param[in]  dashPhase The new dash phase.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGraphStateSetDashPhase, (FPD_GraphState graphState,  FS_FLOAT dashPhase))

/**
 * @brief FPDGraphStateGetLineCap
 * @details Gets the line cap style.
 * @param[in]  graphState The input graphic state object.
 * @return   The line cap style.
 * @note 
 */
INTERFACE(FPD_LineCap, FPDGraphStateGetLineCap, (FPD_GraphState graphState))

/**
 * @brief FPDGraphStateSetLineCap
 * @details Sets the new line cap style.
 * @param[in]  graphState The input graphic state object.
 * @param[in]  cap The new style of line cap.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGraphStateSetLineCap, (FPD_GraphState graphState,  FPD_LineCap cap))

/**
 * @brief FPDGraphStateGetLineJoin
 * @details Gets the line join style.
 * @param[in]  graphState The input graphic state object.
 * @return   The line join style.
 * @note 
 */
INTERFACE(FPD_LineJoin, FPDGraphStateGetLineJoin, (FPD_GraphState graphState))

/**
 * @brief FPDGraphStateSetLineJoin
 * @details Sets the new style of line join.
 * @param[in]  graphState The input graphic state object.
 * @param[in]  join The new style of line join.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGraphStateSetLineJoin, (FPD_GraphState graphState,  FPD_LineJoin join))

/**
 * @brief FPDGraphStateGetMiterLimit
 * @details Gets the miter limit for line join.
 * @param[in]  graphState The input graphic state object.
 * @return   The miter limit for line join.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDGraphStateGetMiterLimit, (FPD_GraphState graphState))

/**
 * @brief FPDGraphStateSetMiterLimit
 * @details Sets the new miter limit for line join.
 * @param[in]  graphState The input graphic state object.
 * @param[in]  limit The new miter limit for line join.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGraphStateSetMiterLimit, (FPD_GraphState graphState,  FS_FLOAT limit))

/**
 * @brief FPDGraphStateGetLineWidth
 * @details Gets the line width.
 * @param[in]  graphState The input graphic state object.
 * @return   The line width.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDGraphStateGetLineWidth, (FPD_GraphState graphState))

/**
 * @brief FPDGraphStateSetLineWidth
 * @details Sets new width of lines.
 * @param[in]  graphState The input graphic state object.
 * @param[in]  width The new width of lines.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDGraphStateSetLineWidth, (FPD_GraphState graphState,  FS_FLOAT width))

/**
 * @brief FPDGraphStateIsNull
 * @details Tests whether the graphic state object is <a>NULL</a> or not.
 * @param[in]  graphState The input graphic state object.
 * @return   Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDGraphStateIsNull, (FPD_GraphState graphState))

/**
 * @brief FPDGraphStateGetModify
 * @details The interface helps init the object if the object is NULL.
 * @param[in]  graphState The input PDF graph state object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDGraphStateGetModify, (FPD_GraphState graphState))

/**
 * @brief FPDGraphStateSetDashArray
 * @details Sets the dash phase for line dash pattern.
 * @param[in]  graphState The input graphic state object.
 * @param[in]  dashArray The input dash array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDGraphStateSetDashArray, (FPD_GraphState graphState,  FS_FLOAT* dashArray))

NumOfSelector(FPDGraphState)
ENDENUM

//*****************************
/* PageObject HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDPageObjectNew
 * @details Creates a new empty PDF page object.
 * @param[in]  type The input page object type. Like FPD_PAGEOBJ_TEXT,FPD_PAGE_EMPTY
 * @return   A page object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDPageObjectNew, (FS_INT32 type))

/**
 * @brief FPDPageObjectDestroy
 * @details Destroys the PDF page object.
 * @param[in]  pageObj The input PDF page object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectDestroy, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectClone
 * @details Clones a page object.
 * @param[in]  pageObj The source object.
 * @return   The cloned object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDPageObjectClone, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectCopy
 * @details Copies from another page object.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  srcObject The source page object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectCopy, (FPD_PageObject pageObj,  const FPD_PageObject srcObject))

/**
 * @brief FPDPageObjectRemoveClipPath
 * @details Removes clipping path of the object.
 * @param[in]  pageObj The input PDF page object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectRemoveClipPath, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectAppendClipPath
 * @details Appends a clipping path.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  path The input clipping path.
 * @param[in]  type The clip type of the input clipping path.
 * @param[in]  bAutoMerge Whether to merge the clipping path automatically.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectAppendClipPath, (FPD_PageObject pageObj,  FPD_Path path,  FS_INT32 type,  FS_BOOL bAutoMerge))

/**
 * @brief FPDPageObjectCopyClipPath
 * @details Copies clipping path from another object.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  srcObj The source page object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectCopyClipPath, (FPD_PageObject pageObj,  FPD_PageObject srcObj))

/**
 * @brief FPDPageObjectTransformClipPath
 * @details Transforms the clip path. Rotate, shear, or move clip path.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  matrix The matrix used to transform.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectTransformClipPath, (FPD_PageObject pageObj,  FS_AffineMatrix matrix))

/**
 * @brief FPDPageObjectSetColorState
 * @details Sets the color state.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  state The new color state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectSetColorState, (FPD_PageObject pageObj,  FPD_ColorState state))

/**
 * @brief FPDPageObjectGetBBox
 * @details Gets the bounding box of the page object, optionally with a transformation matrix.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  pMatrix The input transformation matrix.
 * @return   The bounding box of the page object.
 * @note 
 */
INTERFACE(FS_Rect, FPDPageObjectGetBBox, (FPD_PageObject pageObj,  FS_AffineMatrix* pMatrix))

/**
 * @brief FPDPageObjectGetOriginalBBox
 * @details Gets the original bounding box of the page object.
 * @param[in]  pageObj The input PDF page object.
 * @return   The original bounding box of the page object
 * @note 
 */
INTERFACE(FS_FloatRect, FPDPageObjectGetOriginalBBox, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectGetType
 * @details The page object type.
 * @param[in]  pageObj The input PDF page object.
 * @return   Gets the page object type. Like FPD_PAGEOBJ_TEXT, FPD_PAGEOBJ_PATH etc..
 * @note 
 */
INTERFACE(FS_INT32, FPDPageObjectGetType, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectGetClipPath
 * @details Gets the clip path state.
 * @param[in]  pageObj The input PDF page object.
 * @return   The clip path state.
 * @note It will get a modifiable copy of the object,suggest use FPDClipPathGetClipPath2.
 */
INTERFACE(FPD_ClipPath, FPDPageObjectGetClipPath, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectGetGraphState
 * @details Gets the graph state. For graphs and type3 font or stroke texts.
 * @param[in]  pageObj The input PDF page object.
 * @return   The graph state for graphs and type3 font or stroke texts.
 * @note 
 */
INTERFACE(FPD_GraphState, FPDPageObjectGetGraphState, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectGetColorState
 * @details Gets the color state. For texts, graphs and uncolored images.
 * @param[in]  pageObj The input PDF page object.
 * @return   The color state for texts, graphs and uncolored images.
 * @note It will a modifiable copy of the object. Suggest use FPDColorStateGetColorState2;
 */
INTERFACE(FPD_ColorState, FPDPageObjectGetColorState, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectGetTextState
 * @details Gets the text state. For texts only.
 * @param[in]  pageObj The input PDF page object.
 * @return   The text state for texts only.
 * @note 
 */
INTERFACE(FPD_TextState, FPDPageObjectGetTextState, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectGetGeneralState
 * @details Gets the general state. For all objects.
 * @param[in]  pageObj The input PDF page object.
 * @return   The general state for all objects.
 * @note 
 */
INTERFACE(FPD_GeneralState, FPDPageObjectGetGeneralState, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectGetContentMark
 * @details Gets the agent object CPlugin_InternalObj, it will return data of ContentMark object.
 * @param[in]  pageObj The input PDF page object.
 * @param[out]  outContentMark The input FPD_ContentMark. It create by FPDContentMarkNew.
 * @return   The content mark. For all objects.
 * @note 
 */
INTERFACE(void, FPDPageObjectGetContentMark, (FPD_PageObject pageObj,  FPD_ContentMark* outContentMark))

/**
 * @brief FPDPageObjectDefaultStates
 * @details Sets all graphic states to default.
 * @param[in]  pageObj The input PDF page object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectDefaultStates, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectCopyStates
 * @details Copies from another graphic states.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  src The input graphic states.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectCopyStates, (FPD_PageObject pageObj,  const FPD_PageObject src))

/**
 * @brief FPDPageObjectSetGraphState
 * @details Sets the graph state.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  grahpState The graphic state to be set.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectSetGraphState, (FPD_PageObject pageObj,  FPD_GraphState grahpState))

/**
 * @brief FPDPageObjectSetTextState
 * @details Sets the text state.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  textState The text state to be set.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectSetTextState, (FPD_PageObject pageObj,  FPD_TextState textState))

/**
 * @brief FPDPageObjectSetGeneralState
 * @details Sets the general state.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  genState The general state to be set.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectSetGeneralState, (FPD_PageObject pageObj,  FPD_GeneralState genState))

/**
 * @brief FPDPageObjectHasClipPath
 * @details Checks whether the page object has the clip path or not.
 * @param[in]  pageObj The input PDF page object.
 * @return   <a>TRUE</a> if the page object has the clip path, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(FS_BOOL, FPDPageObjectHasClipPath, (FPD_PageObject pageObj))

/**
 * @brief FPDPageObjectGetContentMark2
 * @details Gets the agent object CPlugin_InternalObj, it will return data of ContentMark object.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  bModify Whether get a copy object.
 * @param[out]  outContentMark The input FPD_ContentMark object. It create by FPDContentMarkNew.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(void, FPDPageObjectGetContentMark2, (FPD_PageObject pageObj,  FS_BOOL bModify,  FPD_ContentMark* outContentMark))

/**
 * @brief FPDPageObjectTransformGeneralState
 * @details Transform the general state matrix.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  matrix The matrix used to transform.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 */
INTERFACE(void, FPDPageObjectTransformGeneralState, (FPD_PageObject pageObj,  FS_AffineMatrix matrix))

/**
 * @brief FPDPageObjectTransform
 * @details Transform the graphics object. Rotate, shear, or move object.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  matrix The transform matrix used to transform.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 */
INTERFACE(void, FPDPageObjectTransform, (FPD_PageObject pageObj,  FS_AffineMatrix matrix))

/**
 * @brief FPDPageObjectCastToFormObject
 * @details Convert  GraphicObject to CPDF_FormObject.
 * @param[in]  pageObj The input PDF page object.
 * @return   FPD_PageObject
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 */
INTERFACE(FPD_PageObject, FPDPageObjectCastToFormObject, (FPD_PageObject pageObj))

INTERFACE(void, FPDPageObjectSetContentMark, (FPD_PageObject pageObj,  FPD_ContentMark contentMark))

/**
 * @brief FPDPageObjectGetClipPath2
 * @details Gets the FPD_ClipPathInternal, it can get FPD_ClipPath by FPDClipPathInternalGetClipPath.
 * @param[in]  pageObj The input PDF page object.
 * @param[out]  outClipPath The input FPD_ClipPathInternal object,it create by FPDClipPathInternalNew.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectGetClipPath2, (FPD_PageObject pageObj,  FPD_ClipPath* outClipPath))

/**
 * @brief FPDPageObjectGetColorState2
 * @details Get the color state.
 * @param[in]  pageObj The input PDF page object.
 * @param[out]  outColorState Get the color state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageObjectGetColorState2, (FPD_PageObject pageObj,  FPD_ColorState *outColorState))

/**
 * @brief FPDPageObjectClone2
 * @details Clone a graphics object.
 * @param[in]  pageObj The input PDF page object.
 * @param[in]  bCloneMC Whether to clone the marked content.
 * @return   FPD_PageObject   A cloned graphics object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDPageObjectClone2, (FPD_PageObject pageObj,  FS_BOOLEAN bCloneMC))

NumOfSelector(FPDPageObject)
ENDENUM

//*****************************
/* TextObject HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDTextObjectNew
 * @details Creates a new empty PDF text object.
 * @param[in]  void 
 * @return   The PDF text object
 * @note 
 */
INTERFACE(FPD_PageObject, FPDTextObjectNew, (void))

/**
 * @brief FPDTextObjectDestroy
 * @details Destroys the input PDF text object. If it is added to the page, it is taken over and don't destroy it.
 * @param[in]  objText The input PDF text object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectDestroy, (FPD_PageObject objText))

/**
 * @brief FPDTextObjectCountItems
 * @details Gets the count of text object items.
 * @param[in]  objText The input PDF text object.
 * @return   The count of text object items.
 * @note 
 */
INTERFACE(FS_INT32, FPDTextObjectCountItems, (FPD_PageObject objText))

/**
 * @brief FPDTextObjectGetItemInfo
 * @details Gets specified text object item information.
 * @param[in]  objText The input PDF text object.
 * @param[in]  index Specifies zero-based item index in the text object.
 * @return   The specified text object item information.
 * @note 
 */
INTERFACE(FPD_TextObjectItem, FPDTextObjectGetItemInfo, (FPD_PageObject objText,  FS_INT32 index))

/**
 * @brief FPDTextObjectCountChars
 * @details Gets the count of characters in the text object.
 * @param[in]  objText The input PDF text object.
 * @return   The count of characters in the text object.
 * @note 
 */
INTERFACE(FS_INT32, FPDTextObjectCountChars, (FPD_PageObject objText))

/**
 * @brief FPDTextObjectGetCharInfo
 * @details Gets the information of specified character.
 * @param[in]  objText The input PDF text object.
 * @param[in]  index Specifies zero-based character index in the text object.
 * @param[out]  outCharcode It receives the character code.
 * @param[out]  outKerning It receives the kerning(x-direction only).
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectGetCharInfo, (FPD_PageObject objText,  FS_INT32 index,  FS_DWORD* outCharcode,  FS_FLOAT* outKerning))

/**
 * @brief FPDTextObjectGetPosX
 * @details Gets the x-coordinate of the origin in the device space
 * @param[in]  objText The input PDF text object.
 * @return   The x-coordinate of the origin in the device space
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTextObjectGetPosX, (FPD_PageObject objText))

/**
 * @brief FPDTextObjectGetPosY
 * @details Gets the y-coordinate of the origin in the device space.
 * @param[in]  objText The input PDF text object.
 * @return   The y-coordinate of the origin in the device space.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTextObjectGetPosY, (FPD_PageObject objText))

/**
 * @brief FPDTextObjectGetTextMatrix
 * @details Gets matrix from text space to object space.
 * @param[in]  objText The input PDF text object.
 * @param[out]  outMatrix It receives the matrix from text space to object space.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectGetTextMatrix, (FPD_PageObject objText,  FS_AffineMatrix* outMatrix))

/**
 * @brief FPDTextObjectGetFont
 * @details Gets the font.
 * @param[in]  objText The input PDF text object.
 * @return   The font.
 * @note 
 */
INTERFACE(FPD_Font, FPDTextObjectGetFont, (FPD_PageObject objText))

/**
 * @brief FPDTextObjectGetFontSize
 * @details Gets the font size.
 * @param[in]  objText The input PDF text object.
 * @return   The font size.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTextObjectGetFontSize, (FPD_PageObject objText))

/**
 * @brief FPDTextObjectSetEmpty
 * @details Sets the text object to be empty.
 * @param[in]  objText The input PDF text object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectSetEmpty, (FPD_PageObject objText))

/**
 * @brief FPDTextObjectSetText
 * @details Sets a single text segment without any kerning inside.
 * @param[in]  objText The input PDF text object.
 * @param[in]  strText The input text segment.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectSetText, (FPD_PageObject objText,  const FS_ByteString strText))

/**
 * @brief FPDTextObjectSetText2
 * @details Sets text using segmented fashion.
 * @param[in]  objText The input PDF text object.
 * @param[in]  strTextArr The input text segments.
 * @param[in]  pKerning The kerning array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDTextObjectSetText2, (FPD_PageObject objText,  FS_ByteStringArray strTextArr,  FS_FLOAT* pKerning))

/**
 * @brief FPDTextObjectSetText3
 * @details Sets text using char-kerning pair fashion.
 * @param[in]  objText The input PDF text object.
 * @param[in]  nChars The count of input character codes.
 * @param[in]  pCharCodes The input character codes.
 * @param[in]  pKernings The input kerning array.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectSetText3, (FPD_PageObject objText,  FS_INT32 nChars,  FS_DWORD* pCharCodes,  FS_FLOAT* pKernings))

/**
 * @brief FPDTextObjectSetPosition
 * @details Sets the origin position in device space.
 * @param[in]  objText The input PDF text object.
 * @param[in]  x The x-coordinate in device space.
 * @param[in]  y The y-coordinate in device space.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectSetPosition, (FPD_PageObject objText,  FS_FLOAT x,  FS_FLOAT y))

/**
 * @brief FPDTextObjectSetTextState
 * @details Sets the text state.
 * @param[in]  objText The input PDF text object.
 * @param[in]  textState The new text state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectSetTextState, (FPD_PageObject objText,  FPD_TextState textState))

/**
 * @brief FPDTextObjectTransform
 * @details Transforms the text object.
 * @param[in]  objText The input PDF text object.
 * @param[in]  matrix The transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectTransform, (FPD_PageObject objText,  FS_AffineMatrix matrix))

/**
 * @brief FPDTextObjectCalcCharPos
 * @details Calculates origin positions in text space, for each character.
 * @param[in]  objText The input PDF text object.
 * @param[out]  outPosArray It receives the character position array.
 * @return   void
 * @note The position array must be allocated and freed by caller. It must contain at least nChars*2 elements.
	*   For each character, the origin position (along the text baseline) and next origin position will be calculated.
 */
INTERFACE(void, FPDTextObjectCalcCharPos, (FPD_PageObject objText,  FS_FLOAT* outPosArray))

/**
 * @brief FPDTextObjectSetData
 * @details Sets text data.
 * @param[in]  objText The input PDF text object.
 * @param[in]  nChars The count of characters to set.
 * @param[in]  pCharCodes The input character codes array.
 * @param[in]  pCharPos The input character positions array in text space.
 * @param[in]  x The x-coordinate of the origin position, in device space.
 * @param[in]  y The y-coordinate of the origin position, in device space.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectSetData, (FPD_PageObject objText,  FS_INT32 nChars,  FS_DWORD* pCharCodes,  FS_FLOAT* pCharPos,  FS_FLOAT x,  FS_FLOAT y))

/**
 * @brief FPDTextObjectGetData
 * @details Gets text data.
 * @param[in]  objText The input PDF text object.
 * @param[out]  outCharCount It receives the count of characters.
 * @param[out]  outCharCodes It receives the character codes array.
 * @param[out]  outCharPos It receives the character positions array in text space.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectGetData, (FPD_PageObject objText,  FS_INT32* outCharCount,  FS_DWORD** outCharCodes,  FS_FLOAT** outCharPos))

/**
 * @brief FPDTextObjectRecalcPositionData
 * @details Recalculates the position data.
 * @param[in]  objText The input PDF text object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectRecalcPositionData, (FPD_PageObject objText))

/**
 * @brief FPDTextObjectGetCharRect
 * @details Get the rect of specified character.
 * @param[in]  objText The input PDF text object.
 * @param[in]  index Specify zero-based character index in the text object.
 * @param[in]  rect It receives the rect.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectGetCharRect, (FPD_PageObject objText,  FS_INT32 index,  FS_FloatRect* rect))

/**
 * @brief FPDTextObjectGetSpaceCharWidth
 * @details Get the space width.
 * @param[in]  objText The input PDF text object.
 * @return   FS_FLOAT
 * @note 
 */
INTERFACE(FS_FLOAT, FPDTextObjectGetSpaceCharWidth, (FPD_PageObject objText))

/**
 * @brief FPDTextObjectGetCharInfo2
 * @details Get the information of specified character.
 * @param[in]  objText The input PDF text object.
 * @param[in]  index Specify zero-based character index in the text object.
 * @return   FPD_TextObjectItem  It returns the specified text object item information.
 * @note The item must not be a kerning.
 */
INTERFACE(FPD_TextObjectItem, FPDTextObjectGetCharInfo2, (FPD_PageObject objText,  FS_INT32 index))

/**
 * @brief FPDTextObjectGetIndex
 * @details Get the index of the text object.
 * @param[in]  objText The input PDF text object.
 * @return   FS_INT32       Return the index of the text object.
 * @note 
 */
INTERFACE(FS_INT32, FPDTextObjectGetIndex, (FPD_PageObject objText))

/**
 * @brief FPDTextObjectSetIndex
 * @details Set the index of the text object.
 * @param[in]  objText The input PDF text object.
 * @param[in]  index The input index of text object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDTextObjectSetIndex, (FPD_PageObject objText,  FS_INT32 index))

NumOfSelector(FPDTextObject)
ENDENUM

//*****************************
/* PathObject HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDPathObjectNew
 * @details Creates a new empty PDF path object.
 * @param[in]  void 
 * @return   A new empty PDF path object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDPathObjectNew, (void))

/**
 * @brief FPDPathObjectDestroy
 * @details Destroys the PDF path object.
 * @param[in]  objPath The input PDF path object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathObjectDestroy, (FPD_PageObject objPath))

/**
 * @brief FPDPathObjectTransform
 * @details Transforms the path object.
 * @param[in]  objPath The input PDF path object.
 * @param[in]  matrix The transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathObjectTransform, (FPD_PageObject objPath,  FS_AffineMatrix matrix))

/**
 * @brief FPDPathObjectSetGraphState
 * @details Sets the graph state.
 * @param[in]  objPath The input PDF path object.
 * @param[in]  graphState The input new graph state.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathObjectSetGraphState, (FPD_PageObject objPath,  FPD_GraphState graphState))

/**
 * @brief FPDPathObjectCalcBoundingBox
 * @details Calculates the bounding box.
 * @param[in]  objPath The input PDF path object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathObjectCalcBoundingBox, (FPD_PageObject objPath))

/**
 * @brief FPDPathObjectGetTransformMatrix
 * @details Gets the transformation matrix.
 * @param[in]  objPath The input PDF path object.
 * @param[out]  outmatrix It receives the transformation matrix.
 * @return   void
 * @note Transformation matrix used to transform the path coordinates. Also used to determine line geometry.
 */
INTERFACE(void, FPDPathObjectGetTransformMatrix, (FPD_PageObject objPath,  FS_AffineMatrix* outmatrix))

/**
 * @brief FPDPathObjectSetTransformMatrix
 * @details Sets the transformation matrix.
 * @param[in]  objPath The input PDF path object.
 * @param[in]  matrix The transformation matrix.
 * @return   void
 * @note Transformation matrix used to transform the path coordinates. Also used to determine line geometry.
 */
INTERFACE(void, FPDPathObjectSetTransformMatrix, (FPD_PageObject objPath,  const FS_AffineMatrix* matrix))

/**
 * @brief FPDPathObjectGetPath
 * @details Gets the path data object. Reference to path data.
 * @param[in]  objPath The input PDF path object.
 * @return   The path data object.
 * @note It will get a modifiable copy of the object. Suggest use FPDPathObjectGetPath2.
 */
INTERFACE(FPD_Path, FPDPathObjectGetPath, (FPD_PageObject objPath))

/**
 * @brief FPDPathObjectIsStrokeMode
 * @details Tests whether the paint mode for the path object is stroking mode.
 * @param[in]  objPath The input PDF path object.
 * @return   <a>TRUE</a> to stroke the path, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDPathObjectIsStrokeMode, (FPD_PageObject objPath))

/**
 * @brief FPDPathObjectSetStrokeMode
 * @details Sets whether to stroke the path.
 * @param[in]  objPath The input PDF path object.
 * @param[in]  bStroke True to stroke the path, otherwise not.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathObjectSetStrokeMode, (FPD_PageObject objPath,  FS_BOOL bStroke))

/**
 * @brief FPDPathObjectGetFillMode
 * @details Gets the filling mode of the page object.
 * @param[in]  objPath The input PDF path object.
 * @return   The filling mode code. See <a>FSFillingModeFlags</a>.
 * @note 
 */
INTERFACE(FS_INT32, FPDPathObjectGetFillMode, (FPD_PageObject objPath))

/**
 * @brief FPDPathObjectSetFillMode
 * @details Sets the new filling mode.
 * @param[in]  objPath The input PDF path object.
 * @param[in]  mode The new filling mode. See <a>FSFillingModeFlags</a>.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPathObjectSetFillMode, (FPD_PageObject objPath,  FS_INT32 mode))

/**
 * @brief FPDPathObjectGetPath2
 * @details Get the path object.
 * @param[in]  objPath The input PDF path object.
 * @param[out]  outPath Get the path object.
 * @return   The path data object.
 * @note 
 */
INTERFACE(void, FPDPathObjectGetPath2, (FPD_PageObject objPath,  FPD_Path* outPath))

/**
 * @brief FPDPathObjectSetPath
 * @details Set the path object.
 * @param[in]  objPath The input PDF path object.
 * @param[out]  path Set the path object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDPathObjectSetPath, (FPD_PageObject objPath,  FPD_Path path))

NumOfSelector(FPDPathObject)
ENDENUM

//*****************************
/* ImageObject HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDImageObjectNew
 * @details Creates a new empty PDF image object.
 * @param[in]  void 
 * @return   A new empty PDF image object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDImageObjectNew, (void))

/**
 * @brief FPDImageObjectDestroy
 * @details Destroys the PDF image object.
 * @param[in]  objImage The input PDF image object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDImageObjectDestroy, (FPD_PageObject objImage))

/**
 * @brief FPDImageObjectTransform
 * @details Transforms the image object.
 * @param[in]  objImage The input PDF image object.
 * @param[in]  matrix The transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDImageObjectTransform, (FPD_PageObject objImage,  FS_AffineMatrix matrix))

/**
 * @brief FPDImageObjectCalcBoundingBox
 * @details Calculates the bounding box.
 * @param[in]  objImage The input PDF image object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDImageObjectCalcBoundingBox, (FPD_PageObject objImage))

/**
 * @brief FPDImageObjectGetTransformMatrix
 * @details Gets the transformation matrix.
 * @param[in]  objImage The input PDF image object.
 * @param[out]  outmatrix It receives the transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDImageObjectGetTransformMatrix, (FPD_PageObject objImage,  FS_AffineMatrix* outmatrix))

/**
 * @brief FPDImageObjectSetTransformMatrix
 * @details Sets the transformation matrix.
 * @param[in]  objImage The input PDF image object.
 * @param[in]  matrix The transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDImageObjectSetTransformMatrix, (FPD_PageObject objImage,  const FS_AffineMatrix* matrix))

/**
 * @brief FPDImageObjectGetImage
 * @details Gets the image data object.
 * @param[in]  objImage The input PDF image object.
 * @return   The image data object.
 * @note 
 */
INTERFACE(FPD_Image, FPDImageObjectGetImage, (FPD_PageObject objImage))

/**
 * @brief FPDImageObjectSetImage
 * @details Sets the image data object.
 * @param[in]  objImage The input PDF image object.
 * @param[in]  image The input image data object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDImageObjectSetImage, (FPD_PageObject objImage,  FPD_Image image))

NumOfSelector(FPDImageObject)
ENDENUM

//*****************************
/* ShadingObject HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDShadingObjectNew
 * @details Creates a new empty PDF shading object.
 * @param[in]  void 
 * @return   A new empty PDF shading object
 * @note 
 */
INTERFACE(FPD_PageObject, FPDShadingObjectNew, (void))

/**
 * @brief FPDShadingObjectDestroy
 * @details Destroys the PDF shading object.
 * @param[in]  objShading The input PDF shading object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDShadingObjectDestroy, (FPD_PageObject objShading))

/**
 * @brief FPDShadingObjectTransform
 * @details Transforms the path object.
 * @param[in]  objShading The input PDF shading object.
 * @param[in]  matrix The transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDShadingObjectTransform, (FPD_PageObject objShading,  FS_AffineMatrix matrix))

/**
 * @brief FPDShadingObjectCalcBoundingBox
 * @details Calculates the bounding box.
 * @param[in]  objShading The input PDF shading object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDShadingObjectCalcBoundingBox, (FPD_PageObject objShading))

/**
 * @brief FPDShadingObjectGetTransformMatrix
 * @details Gets the transformation matrix.
 * @param[in]  objShading The input PDF shading object.
 * @param[out]  outmatrix It receives the transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDShadingObjectGetTransformMatrix, (FPD_PageObject objShading,  FS_AffineMatrix* outmatrix))

/**
 * @brief FPDShadingObjectSetTransformMatrix
 * @details Sets the transformation matrix.
 * @param[in]  objShading The input PDF shading object.
 * @param[in]  matrix The transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDShadingObjectSetTransformMatrix, (FPD_PageObject objShading,  const FS_AffineMatrix* matrix))

/**
 * @brief FPDShadingObjectGetPage
 * @details Gets the page.
 * @param[in]  objShading The input PDF shading object.
 * @return   The page.
 * @note 
 */
INTERFACE(FPD_Page, FPDShadingObjectGetPage, (FPD_PageObject objShading))

/**
 * @brief FPDShadingObjectSetPage
 * @details Sets the page.
 * @param[in]  objShading The input PDF shading object.
 * @param[in]  page The input page.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDShadingObjectSetPage, (FPD_PageObject objShading,  FPD_Page page))

/**
 * @brief FPDShadingObjectGetShadingPattern
 * @details Gets the shading pattern.
 * @param[in]  objShading The input PDF shading object.
 * @return   void
 * @note 
 */
INTERFACE(FPD_ShadingPattern, FPDShadingObjectGetShadingPattern, (FPD_PageObject objShading))

/**
 * @brief FPDShadingObjectSetShadingPattern
 * @details Sets the shading pattern.
 * @param[in]  objShading The input PDF shading object.
 * @param[in]  pattern The input shading pattern.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDShadingObjectSetShadingPattern, (FPD_PageObject objShading,  FPD_ShadingPattern pattern))

NumOfSelector(FPDShadingObject)
ENDENUM

//*****************************
/* FormObject HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFormObjectNew
 * @details Creates a new empty PDF form object.
 * @param[in]  void 
 * @return   A new empty PDF form object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDFormObjectNew, (void))

/**
 * @brief FPDFormObjectDestroy
 * @details Destroys the PDF form object.
 * @param[in]  objForm The input PDF form object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormObjectDestroy, (FPD_PageObject objForm))

/**
 * @brief FPDFormObjectTransform
 * @details Transforms the path object.
 * @param[in]  objForm The input PDF form object.
 * @param[in]  matrix The transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormObjectTransform, (FPD_PageObject objForm,  FS_AffineMatrix matrix))

/**
 * @brief FPDFormObjectCalcBoundingBox
 * @details Calculates the bounding box.
 * @param[in]  objForm The input PDF form object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormObjectCalcBoundingBox, (FPD_PageObject objForm))

/**
 * @brief FPDFormObjectGetTransformMatrix
 * @details Gets the transformation matrix.
 * @param[in]  objForm The input PDF form object.
 * @param[out]  outmatrix It receives the transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormObjectGetTransformMatrix, (FPD_PageObject objForm,  FS_AffineMatrix* outmatrix))

/**
 * @brief FPDFormObjectSetTransformMatrix
 * @details Sets the transformation matrix.
 * @param[in]  objForm The input PDF form object.
 * @param[in]  matrix The transformation matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormObjectSetTransformMatrix, (FPD_PageObject objForm,  const FS_AffineMatrix* matrix))

/**
 * @brief FPDFormObjectGetForm
 * @details Gets the form.
 * @param[in]  objForm The input PDF form object.
 * @return   The form.
 * @note 
 */
INTERFACE(FPD_Form, FPDFormObjectGetForm, (FPD_PageObject objForm))

/**
 * @brief FPDFormObjectSetForm
 * @details Sets the form.
 * @param[in]  objForm The input PDF form object.
 * @param[in]  form The input form.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormObjectSetForm, (FPD_PageObject objForm,  FPD_Form form))

NumOfSelector(FPDFormObject)
ENDENUM

//*****************************
/* InlineImages HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDInlineImagesNew
 * @details Creates a new empty PDF inline images object.
 * @param[in]  void 
 * @return   A new empty PDF inline images object.
 * @note 
 */
INTERFACE(FPD_PageObject, FPDInlineImagesNew, (void))

/**
 * @brief FPDInlineImagesDestroy
 * @details Destroys the PDF inline images object.
 * @param[in]  objInlineImgs The input PDF inline images object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInlineImagesDestroy, (FPD_PageObject objInlineImgs))

/**
 * @brief FPDInlineImagesAddMatrix
 * @details Adds a transform matrix.
 * @param[in]  objInlineImgs The input PDF inline images object.
 * @param[in]  matrix The input transform matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInlineImagesAddMatrix, (FPD_PageObject objInlineImgs,  const FS_AffineMatrix* matrix))

/**
 * @brief FPDInlineImagesCountMatrix
 * @details Counts the number of transform matrix in this object.
 * @param[in]  objInlineImgs The input PDF inline images object.
 * @return   The number of transform matrix in this object.
 * @note 
 */
INTERFACE(int, FPDInlineImagesCountMatrix, (FPD_PageObject objInlineImgs))

/**
 * @brief FPDInlineImagesGetMatrix
 * @details Gets a transform matrix from object by index.
 * @param[in]  objInlineImgs The input PDF inline images object.
 * @param[in]  index The index of transform matrix.
 * @return   The transform matrix from object by index.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FPDInlineImagesGetMatrix, (FPD_PageObject objInlineImgs,  FS_INT32 index))

/**
 * @brief FPDInlineImagesGetStream
 * @details Gets the stream.
 * @param[in]  objInlineImgs The input PDF inline images object.
 * @return   The stream.
 * @note 
 */
INTERFACE(FPD_Object, FPDInlineImagesGetStream, (FPD_PageObject objInlineImgs))

/**
 * @brief FPDInlineImagesSetStream
 * @details Sets the stream
 * @param[in]  objInlineImgs The input PDF inline images object.
 * @param[in]  stream The input stream
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInlineImagesSetStream, (FPD_PageObject objInlineImgs,  FPD_Object stream))

/**
 * @brief FPDInlineImagesGetDIBitmap
 * @details Get the bitmap.
 * @param[in]  objInlineImgs The input PDF inline images object.
 * @return   FS_DIBitmap
 * @note 
 */
INTERFACE(FS_DIBitmap, FPDInlineImagesGetDIBitmap, (FPD_PageObject objInlineImgs))

NumOfSelector(FPDInlineImages)
ENDENUM

//*****************************
/* ContentMarkItem HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDContentMarkItemNew
 * @details Creates a new empty PDF content mark item object.
 * @param[in]  void 
 * @return   A new empty PDF content mark item object.
 * @note 
 */
INTERFACE(FPD_ContentMarkItem, FPDContentMarkItemNew, (void))

/**
 * @brief FPDContentMarkItemDestroy
 * @details Destroys the PDF content mark item object.
 * @param[in]  item The input PDF content mark item object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkItemDestroy, (FPD_ContentMarkItem item))

/**
 * @brief FPDContentMarkItemGetName
 * @details Gets the name(tag) of the content mark item.
 * @param[in]  item The input PDF content mark item object.
 * @param[out]  outName Get the name(tag) of the content mark item.
 * @return   FS_BOOL  TRUE get name success.
 * @note 
 */
INTERFACE(FS_BOOL, FPDContentMarkItemGetName, (FPD_ContentMarkItem item,  FS_ByteString* outName))

/**
 * @brief FPDContentMarkItemGetParamType
 * @details Gets the parameter type of the content mark item.
 * @param[in]  item The input PDF content mark item object.
 * @return   The parameter type of the content mark item.
 * @note 
 */
INTERFACE(FPD_MarkItemParamType, FPDContentMarkItemGetParamType, (FPD_ContentMarkItem item))

/**
 * @brief FPDContentMarkItemGetParam
 * @details Gets the parameter of the content mark item.
 * @param[in]  item The input PDF content mark item object.
 * @return   The parameter of the content mark item.
 * @note 
 */
INTERFACE(void*, FPDContentMarkItemGetParam, (FPD_ContentMarkItem item))

/**
 * @brief FPDContentMarkItemSetName
 * @details Sets the name(tag) of the content mark item.
 * @param[in]  item The input PDF content mark item object.
 * @param[in]  csName The input new name(tag).
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkItemSetName, (FPD_ContentMarkItem item,  FS_LPCSTR csName))

/**
 * @brief FPDContentMarkItemSetParam
 * @details Sets the parameter of the content mark item.
 * @param[in]  item The input PDF content mark item object.
 * @param[in]  type The input new parameter type.
 * @param[in]  param The input new parameter.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkItemSetParam, (FPD_ContentMarkItem item,  FPD_MarkItemParamType type,  void* param))

/**
 * @brief FPDContentMarkItemHasMCID
 * @details Has MCID entry.
 * @param[in]  item The input PDF content mark item object.
 * @return   FS_BOOLEAN	true: Has MCID entry.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDContentMarkItemHasMCID, (FPD_ContentMarkItem item))

NumOfSelector(FPDContentMarkItem)
ENDENUM

//*****************************
/* ContentMark HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDContentMarkNew
 * @details Creates a new empty agent internal object.
 * @param[in]  void 
 * @return   A new empty FPD_ContentMark object, it can get content mark object by it.
 * @note 
 */
INTERFACE(FPD_ContentMark, FPDContentMarkNew, (void))

/**
 * @brief FPDContentMarkDestroy
 * @details Destroys the agent internal object.
 * @param[in]  mark The input FPD_ContentMark object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkDestroy, (FPD_ContentMark mark))

/**
 * @brief FPDContentMarkGetMCID
 * @details Gets the marked-content identifier.
 * @param[in]  mark The input FPD_ContentMark object.
 * @return   The marked-content identifier.
 * @note 
 */
INTERFACE(FS_INT32, FPDContentMarkGetMCID, (FPD_ContentMark mark))

/**
 * @brief FPDContentMarkHasMark
 * @details Checks whether the content mark has a specified content mark item.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[in]  tag The name(tag) of the content mark item.
 * @return   Non-zero means it has, otherwise it has not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDContentMarkHasMark, (FPD_ContentMark mark,  FS_LPCSTR tag))

/**
 * @brief FPDContentMarkLookupMark
 * @details Lookups a content mark item.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[in]  tag The name(tag) of the content mark item.
 * @param[out]  outDict It receives the parameter(attributes) dictionary.
 * @return   Non-zero means found one, otherwise found none.
 * @note 
 */
INTERFACE(FS_BOOL, FPDContentMarkLookupMark, (FPD_ContentMark mark,  FS_LPCSTR tag,  FPD_Object* outDict))

/**
 * @brief FPDContentMarkCountItems
 * @details Counts the number of content mark data in this object.
 * @param[in]  mark The input FPD_ContentMark object.
 * @return   The number of content mark data in this object.
 * @note 
 */
INTERFACE(FS_INT32, FPDContentMarkCountItems, (FPD_ContentMark mark))

/**
 * @brief FPDContentMarkGetItem
 * @details Gets the content mark item by index.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[in]  index The zero-based content mark item index in the content mark data.
 * @return   A content mark item.
 * @note 
 */
INTERFACE(FPD_ContentMarkItem, FPDContentMarkGetItem, (FPD_ContentMark mark,  FS_INT32 index))

/**
 * @brief FPDContentMarkAddMark
 * @details Adds a content mark item.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[in]  tag The input name(tag) of the content mark item.
 * @param[in]  dict The parameter(attributes) dictionary of the content mark item.
 * @param[in]  bDictNeedClone Whether the input dictionary must be copied or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkAddMark, (FPD_ContentMark mark,  FS_LPCSTR tag,  FPD_Object dict,  FS_BOOL bDictNeedClone))

/**
 * @brief FPDContentMarkDeleteMark
 * @details Deletes a content mark item.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[in]  tag The name(tag) of the content mark item.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkDeleteMark, (FPD_ContentMark mark,  FS_LPCSTR tag))

/**
 * @brief FPDContentMarkDeleteLastMark
 * @details Deletes the last content mark item.
 * @param[in]  mark The input FPD_ContentMark object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkDeleteLastMark, (FPD_ContentMark mark))

/**
 * @brief FPDContentMarkIsNull
 * @details Tests whether the content mark object is <a>NULL</a> or not.
 * @param[in]  mark The input FPD_ContentMark object.
 * @return   Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDContentMarkIsNull, (FPD_ContentMark mark))

/**
 * @brief FPDContentMarkCopy
 * @details Copies the source content mark to the specified one.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[in]  pSrcContentMark The input PDF content mark object to be copied.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(void, FPDContentMarkCopy, (FPD_ContentMark mark,  FPD_ContentMark pSrcContentMark))

INTERFACE(FS_INT32, FPDContentMarkGetContentMarkDataMCID, (FPD_ContentMark mark))

/**
 * @brief FPDContentMarkCheckContentMarkDataIsNULL
 * @details Check the ContentMarkData.
 * @param[in]  mark The input FPD_ContentMark object.
 * @return   FS_BOOL    TRUE: ContentMarkData is NULL.
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDContentMarkCheckContentMarkDataIsNULL, (FPD_ContentMark mark))

/**
 * @brief FPDContentMarkGetItem2
 * @details Gets the content mark item ref by index.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[in]  index The zero-based content mark item index in the content mark data.
 * @param[out]  ref Gets the content mark item ref by index..
 * @return   A content mark item ref.
 * @note 
 */
INTERFACE(void, FPDContentMarkGetItem2, (FPD_ContentMark mark,  FS_INT32 index,  FPD_ContentMarkItemRef* ref))

/**
 * @brief FPDContentMarkAddMark2
 * @details Add a content mark item.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[in]  itemRef The input content mark item ref.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkAddMark2, (FPD_ContentMark mark,  FPD_ContentMarkItemRef itemRef))

/**
 * @brief FPDContentMarkGetItems
 * @details Get content mark items.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[out]  outItems Get content mark items.
 * @return   FS_BOOL   TRUE: Get itmes success.
 * @note 
 */
INTERFACE(FS_BOOL, FPDContentMarkGetItems, (FPD_ContentMark mark,  FS_PtrArray* outItems))

/**
 * @brief FPDContentMarkGetModify
 * @details Get a modifiable copy of the object. If the reference was refer to null, 
	* then a new object will be created. The returned pointer can be used to alter the object.
 * @param[in]  mark The input FPD_ContentMark object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDContentMarkGetModify, (FPD_ContentMark mark))

/**
 * @brief FPDContentMarkDoObjectNew
 * @details Create a new object and refer to it. 
	* The returned pointer to the object can be used to modify the content of objects.
 * @param[in]  mark The input FPD_ContentMark object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0
 */
INTERFACE(void, FPDContentMarkDoObjectNew, (FPD_ContentMark mark))

/**
 * @brief FPDContentMarkIsEqual
 * @details Compare with another object.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[in]  markMatch The input agent internal object need to compare.
 * @return   FS_BOOLEAN.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0
 */
INTERFACE(FS_BOOLEAN, FPDContentMarkIsEqual, (FPD_ContentMark mark,  FPD_ContentMark mark2))

/**
 * @brief FPDContentMarkCopy2
 * @details Copy a FPD_ContentMark.
 * @param[in]  mark The input FPD_ContentMark object.
 * @return   FPD_ContentMark.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0
 */
INTERFACE(FPD_ContentMark, FPDContentMarkCopy2, (FPD_ContentMark mark))

/**
 * @brief FPDContentMarkGetItem3
 * @details Gets the content mark item by index.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[in]  index The zero-based content mark item index in the content mark data.
 * @param[in]  bModify If need modify the object.
 * @return   A content mark item.
 * @note 
 */
INTERFACE(FPD_ContentMarkItem, FPDContentMarkGetItem3, (FPD_ContentMark mark,  FS_INT32 index,  FS_BOOL bModify))

/**
 * @brief FPDContentMarkRemoveItem
 * @details Remove item with specified index.
 * @param[in]  mark The input FPD_ContentMark object.
 * @param[in]  index The zero-based content mark item index in the content mark data.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkRemoveItem, (FPD_ContentMark mark,  FS_INT32 index))

/**
 * @brief FPDContentMarkRemoveAllItems
 * @details Remove all items.
 * @param[in]  mark The input FPD_ContentMark object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkRemoveAllItems, (FPD_ContentMark mark))

NumOfSelector(FPDContentMark)
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
//----------_V15----------
//----------_V16----------
//*****************************
/* ContentMarkItemRef HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDContentMarkItemRefGetContentMarkItemObject
 * @details Get it's count object FPD_ContentMarkItem.
 * @param[in]  itemRef The input FPD_ContentMarkItemRef.
 * @return   FPD_ContentMarkItem
 * @note 
 */
INTERFACE(FPD_ContentMarkItem, FPDContentMarkItemRefGetContentMarkItemObject, (FPD_ContentMarkItemRef itemRef))

/**
 * @brief FPDContentMarkItemRefNew
 * @details Create a new FPD_ContentMarkItem object and refer to it.
 * @param[in]  itemRef The input FPD_ContentMarkItemRef.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkItemRefNew, (FPD_ContentMarkItemRef itemRef))

/**
 * @brief FPDContentMarkItemRefGetModify
 * @details Get a modifiable copy of the FPD_ContentMarkItem.
 * @param[in]  itemRef The input FPD_ContentMarkItemRef.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkItemRefGetModify, (FPD_ContentMarkItemRef itemRef))

/**
 * @brief FPDContentMarkItemRefCreate
 * @details Get a modifiable copy of the FPD_ContentMarkItem.
 * @param[in]  itemRef The input FPD_ContentMarkItemRef.
 * @return   FPD_ContentMarkItemRef
 * @note 
 */
INTERFACE(FPD_ContentMarkItemRef, FPDContentMarkItemRefCreate, ())

/**
 * @brief FPDContentMarkItemRefDelete
 * @details Delete the FPD_ContentMarkItemRef.
 * @param[in]  ref The input FPD_ContentMarkItemRef.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDContentMarkItemRefDelete, (FPD_ContentMarkItemRef ref))

/**
 * @brief FPDContentMarkItemRefCopy
 * @details Copy a FPD_ContentMarkItemRef.
 * @param[in]  ref The input FPD_ContentMarkItemRef.
 * @return   FPD_ContentMarkItemRef
 * @note 
 */
INTERFACE(FPD_ContentMarkItemRef, FPDContentMarkItemRefCopy, (FPD_ContentMarkItemRef ref))

NumOfSelector(FPDContentMarkItemRef)
ENDENUM

//----------_V17----------
//*****************************
/* PathData HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDPathDataNew
 * @details Construct an empty path data.
 * @return   FPD_PathData
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_PathData, FPDPathDataNew, ())

/**
 * @brief FPDPathDataNew2
 * @details Copy constructor.
 * @param[in]  src The input FPD_PathData.
 * @return   FPD_PathData
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_PathData, FPDPathDataNew2, (FPD_PathData src))

/**
 * @brief FPDPathDataDestroty
 * @details Destroy FPD_PathData.
 * @param[in]  pathdata The input FPD_PathData.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDPathDataDestroty, (FPD_PathData pathdata))

/**
 * @brief FPDPathDataGetPointCount
 * @details Get the point count int the path data.
 * @param[in]  pathdata The input FPD_PathData.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDPathDataGetPointCount, (FPD_PathData pathdata))

/**
 * @brief FPDPathDataGetFlag
 * @details Get the flag of specified path point.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  index Specifies the zero-based index of path point in the path data.
 * @return   FS_INT32      The flag of specified path point.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDPathDataGetFlag, (FPD_PathData pathdata,  FS_INT32 index))

/**
 * @brief FPDPathDataGetPointX
 * @details Get the x-coordinate of specified path point.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  index Specifies the zero-based index of path point in the path data.
 * @return   FS_FLOAT      The x-coordinate of specified path point.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_FLOAT, FPDPathDataGetPointX, (FPD_PathData pathdata,  FS_INT32 index))

/**
 * @brief FPDPathDataGetPointY
 * @details Get the y-coordinate of specified path point.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  index Specifies the zero-based index of path point in the path data.
 * @return   FS_FLOAT      The y-coordinate of specified path point.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_FLOAT, FPDPathDataGetPointY, (FPD_PathData pathdata,  FS_INT32 index))

/**
 * @brief FPDPathDataGetPoint
 * @details Gets the path point in the path points array by the index.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  index The point index in the points array.
 * @return   FS_PATHPOINT  The path point in the path points array by the index.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_PATHPOINT, FPDPathDataGetPoint, (FPD_PathData pathdata,  FS_INT32 index))

/**
 * @brief FPDPathDataSetPointCount
 * @details Change the path point count and prepare adequate allocated buffer.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  nPoints The new count of path point to change.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDPathDataSetPointCount, (FPD_PathData pathdata,  FS_INT32 nPoints))

/**
 * @brief FPDPathDataAllocPointCount
 * @details Allocate enough point buffer without change number of current points.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  nPoints The new count of path point to to allocated.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDPathDataAllocPointCount, (FPD_PathData pathdata,  FS_INT32 nPoints))

/**
 * @brief FPDPathDataAddPointCount
 * @details Add number of path point to the path data and prepare adequate allocated buffer.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  addPoints The count of path point to add.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDPathDataAddPointCount, (FPD_PathData pathdata,  FS_INT32 addPoints))

/**
 * @brief FPDPathDataGetBoundingBox
 * @details Get the bounding box. Ignoring line thickness.
 * @param[in]  pathdata The input FPD_PathData.
 * @return   FS_FloatRect
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_FloatRect, FPDPathDataGetBoundingBox, (FPD_PathData pathdata))

/**
 * @brief FPDPathDataGetBoundingBox2
 * @details Get the bounding box, respecting line thickness. all points in the stroked path must be in the bounding box.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  line_width The line width used in stroking.
 * @param[in]  miter_limit The miter limit value for line joint in stroking.
 * @return   FS_FloatRect
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_FloatRect, FPDPathDataGetBoundingBox2, (FPD_PathData pathdata,  FS_FLOAT line_width,  FS_FLOAT miter_limit))

/**
 * @brief FPDPathDataTransform
 * @details Transform all path point in the path data using specified matrix.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  pMatrix The specified matrix.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDPathDataTransform, (FPD_PathData pathdata,  FS_AffineMatrix pMatrix))

/**
 * @brief FPDPathDataAppend
 * @details Append a path data. Optionally a matrix can be specified to transform the source path data before appending.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  pSrc The source path data.
 * @param[in]  pMatrix The specified matrix. NULL means no transformation.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDPathDataAppend, (FPD_PathData pathdata,  const FPD_PathData pSrc,  const FS_AffineMatrix* pMatrix))

/**
 * @brief FPDPathDataAppendRect
 * @details Append a rectangle.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  left The x-coordinate of the left-bottom corner.
 * @param[in]  bottom The y-coordinate of the left-bottom corner.
 * @param[in]  right The x-coordinate of the right-top corner.
 * @param[in]  top The y-coordinate of the right-top corner.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDPathDataAppendRect, (FPD_PathData pathdata,  FS_FLOAT left,  FS_FLOAT bottom,  FS_FLOAT right,  FS_FLOAT top))

/**
 * @brief FPDPathDataSetPoint
 * @details Set the point data for specified path point.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  index Specifies the zero-based index of path point in the path data.
 * @param[in]  x The x-coordinate of the point to set.
 * @param[in]  y The y-coordinate of the point to set.
 * @param[in]  flag The flag of the point to set.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDPathDataSetPoint, (FPD_PathData pathdata,  FS_INT32 index,  FS_FLOAT x,  FS_FLOAT y,  FS_INT32 flag))

/**
 * @brief FPDPathDataTrimPoints
 * @details Trim the number of path point in the path data to specified number.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  nPoints The new count of path point to trim to.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDPathDataTrimPoints, (FPD_PathData pathdata,  FS_INT32 nPoints))

/**
 * @brief FPDPathDataCopy
 * @details Copy path data from another instance.
 * @param[in]  pathdata The input FPD_PathData.
 * @param[in]  src The source path data.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDPathDataCopy, (FPD_PathData pathdata,  const FPD_PathData src))

/**
 * @brief FPDPathDataIsRect
 * @details Copy path data from another instance.
 * @param[in]  pathdata The input FPD_PathData.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_BOOLEAN, FPDPathDataIsRect, (FPD_PathData pathdata))

NumOfSelector(FPDPathData)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

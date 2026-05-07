/** @file fpd_pageobj.h.
 * 
 *  @brief defined  page objects.
 */


#ifndef FPD_PAGEOBJIMPL_H
#define FPD_PAGEOBJIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_PAGEOBJEXPT_H
#include "../fpd_pageobjExpT.h"
#endif

#ifndef	FPD_RESOURCEEXPT_H
#include "../fpd_resourceExpT.h"
#endif

#ifndef	FPD_PAGEEXPT_H
#include "../fpd_pageExpT.h"
#endif

#include "../../basic/fs_basicExpT.h"
#include "../../basic/fs_basicCalls.h"

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

class CFPD_Path_V1
{	
public:
	//************************************
	// Function: New
	// Return:   A new empty PDF path data object.
	// Remarks:  Creates a new empty PDF path data object.
	// Notes:	
	//************************************
	static FPD_Path	New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: path The input PDF path data object.
	// Return:    void
	// Remarks:   Destroys the PDF path data object.
	// Notes:
	//************************************
	static void	Destroy(FPD_Path path);


	//************************************
	// Function:  GetPointCount
	// Param[in]: path	The input PDF path data object.
	// Return:    The point count int the path.
	// Remarks:   Gets the point count int the path.
	// Notes:
	//************************************
	static FS_INT32	GetPointCount(FPD_Path path);

	//************************************
	// Function:  GetFlag
	// Param[in]: path		The input PDF path data object.
	// Param[in]: index		Specifies the zero-based index of path point in the path.
	// Return:    The flag of specified path point. 
	// Remarks:   Gets the flag of specified path point.
	// Notes:
	//************************************
	static FS_INT32	GetFlag(FPD_Path path, FS_INT32 index);

	//************************************
	// Function:  GetPointX
	// Param[in]: path		The input PDF path data object.
	// Param[in]: index		Specifies the zero-based index of path point in the path.
	// Return:	  The x-coordinate of specified path point.
	// Remarks:   Gets the x-coordinate of specified path point.
	// Notes:
	//************************************
	static FS_FLOAT	GetPointX(FPD_Path path, FS_INT32 index);

	//************************************
	// Function:  GetPointY
	// Param[in]: path		The input PDF path data object.
	// Param[in]: index		Specifies the zero-based index of path point in the path.
	// Return:    The y-coordinate of specified path point.
	// Remarks:   Gets the y-coordinate of specified path point.
	// Notes:
	//************************************
	static FS_FLOAT	GetPointY(FPD_Path path, FS_INT32 index);

	//************************************
	// Function:  GetPoint
	// Param[in]: path		The input PDF path data object.
	// Param[in]: index		The point index in the points array.
	// Return:    The path point in the path points array by the index.
	// Remarks:   Gets the path point in the path points array by the index.
	// Notes:
	//************************************
	static FS_PATHPOINT	GetPoint(FPD_Path path, FS_INT32 index);

	//************************************
	// Function:  GetBoundingBox
	// Param[in]: path	The input PDF path data object.
	// Return:    The bounding box of all control points.
	// Remarks:   Gets bounding box of all control points.
	// Notes:     The result can be used as the bounding box of the whole filled path.
	//            However, when path is stroked using geometry pen, the actual bounding box can be much larger.
	//************************************
	static FS_FloatRect	GetBoundingBox(FPD_Path path);

	//************************************
	// Function:  GetBoundingBox2
	// Param[in]: path			The input PDF path data object.
	// Param[in]: lineWidth		The line width used in stroking.
	// Param[in]: miterLimit	The miter limit value for line joint in stroking.
	// Return:    The bounding box for stroked path.
	// Remarks:   Calculates bounding box (guaranteed to contain all path, may be larger) for stroked path.
	// Notes:
	//************************************
	static FS_FloatRect	GetBoundingBox2(FPD_Path path, FS_FLOAT lineWidth, FS_FLOAT miterLimit);

	//************************************
	// Function:  Transform
	// Param[in]: path			The input PDF path data object.
	// Param[in]: matrix		The input matrix used to transform.
	// Return:    void
	// Remarks:   Transforms this path.
	// Notes:
	//************************************
	static void	Transform(FPD_Path path, FS_AffineMatrix matrix);

	//************************************
	// Function:  Append
	// Param[in]: path		The input PDF path data object.
	// Param[in]: src		The source path.
	// Param[in]: pMatrix	The specified matrix. <a>NULL</a> means no transformation.
	// Return:    void
	// Remarks:   Appends a path. Optionally a matrix can be specified to transform the source path before appending.
	// Notes:
	//************************************
	static void	Append(FPD_Path path, FPD_Path src, FS_AffineMatrix* pMatrix);

	//************************************
	// Function:  AppendRect
	// Param[in]: path			The input PDF path data object.
	// Param[in]: left			The x-coordinate of the left-bottom corner.
	// Param[in]: bottom		The y-coordinate of the left-bottom corner.
	// Param[in]: right			The x-coordinate of the right-top corner.
	// Param[in]: top			The y-coordinate of the right-top corner.
	// Return:    void
	// Remarks:   Appends a rectangle.
	// Notes:
	//************************************
	static void	AppendRect(FPD_Path path, FS_FLOAT left, FS_FLOAT bottom, FS_FLOAT right, FS_FLOAT top);

	//************************************
	// Function:  IsRect
	// Param[in]: path	The input PDF path data object.
	// Return:    <a>TRUE</a> if the path is actually a rectangle, otherwise not.
	// Remarks:   Tests whether the path is a actually rectangle.
	// Notes:
	//************************************
	static FS_BOOL IsRect(FPD_Path path);

	//************************************
	// Function:  SetPointCount
	// Param[in]: path		The input PDF path data object.
	// Param[in]: nPoints	The new count of path point to change.
	// Return:    void
	// Remarks:   Changes the path point count and prepares adequate allocated buffer.
	// Notes:
	//************************************
	static void SetPointCount(FPD_Path path, FS_INT32 nPoints);

	//************************************
	// Function:  SetPoint
	// Param[in]: path		The input PDF path data object.
	// Param[in]: index		Specifies the zero-based index of path point in the path.
	// Param[in]: x			The x-coordinate of the point to set.
	// Param[in]: y			The y-coordinate of the point to set.
	// Param[in]: flag		The flag of the point to set.
	// Return:    void
	// Remarks:   Sets the point data for specified path point.
	// Notes:
	//************************************
	static void SetPoint(FPD_Path path, FS_INT32 index, FS_FLOAT x, FS_FLOAT y, FS_INT32 flag);

	//************************************
	// Function:  GetModify
	// Param[in]: path		The input PDF path data object.
	// Return:    FPD_PathData.
	// Remarks:	  The interface helps init the object if the object is NULL.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FPD_PathData GetModify(FPD_Path path);
	
	//************************************
	// Function:  TrimPoints
	// Param[in]: path		The input PDF path data object.
	// Param[in]: nPoints	The new count of path point to trim to.
	// Return:    void.
	// Remarks:	  Trim the number of path point in the path data to specified number.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void	TrimPoints(FPD_Path path, FS_INT32 nPoints);

	//************************************
	// Function:  TransformPathData
	// Param[in]: path		The input PDF path data object.
	// Param[in]: matrix		The input matrix used to transform.
	// Return:    void
	// Remarks:   Transforms the path data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void TransformPathData(FPD_Path path, FS_AffineMatrix matrix);

	//************************************
	// Function:  Copy
	// Param[in]: path		The input PDF path data object.
	// Return:    FPD_Path
	// Remarks:   Copy a path data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FPD_Path Copy(FPD_Path path);
	
	 //************************************
	 // Function:  AddPointCount
	 // Param[in]: path		        The input PDF path data object.
	 // Param[in]: addPoints		The count of path point to add.
	 // Return:    FS_BOOLEAN
	 // Remarks:   Add number of path point to the path data and prepare adequate allocated buffer.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	 //************************************
	static FS_BOOLEAN	AddPointCount(FPD_Path path, FS_INT32 addPoints);
};


class CFPD_ClipPath_V1
{	
public:
	//************************************
	// Function: New
	// Return:   A new empty clip path data object.
	// Remarks:  Creates a new empty clip path data object.
	// Notes:	
	//************************************
	static FPD_ClipPath	New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: path The input clip path data object.
	// Return:    void
	// Remarks:   Destroys the clip path data object.
	// Notes:
	//************************************
	static void	Destroy(FPD_ClipPath path);

	//************************************
	// Function:  AppendPath
	// Param[in]: path				The input clip path data object.
	// Param[in]: pathAppendTo		The input clipping path.
	// Param[in]: type				The clip type of the input clipping path.
	// Param[in]: bAutoMerge		Whether to merge the clipping path automatically.
	// Return:    void
	// Remarks:   Appends a clipping path.
	// Notes:
	//************************************
	static void	AppendPath(FPD_ClipPath path, FPD_Path pathAppendTo, FS_INT32 type, FS_BOOL bAutoMerge);

	//************************************
	// Function:  DeletePath
	// Param[in]: path			The input clip path data object.
	// Param[in]: layerIndex	The path index to remove.
	// Return:    void
	// Remarks:   Removes a path from path list.
	// Notes:
	//************************************
	static void DeletePath(FPD_ClipPath path, FS_INT32 layerIndex);

	//************************************
	// Function:  GetPathCount
	// Param[in]: path	The input clip path data object.
	// Return:   The count of paths in the clip path.
	// Remarks:   Gets the count of paths in the clip path.
	// Notes:
	//************************************
	static FS_DWORD GetPathCount(FPD_ClipPath path);

	//************************************
	// Function:  Transform
	// Param[in]: path			The input clip path data object.
	// Param[in]: matrix		The input matrix used to transform.
	// Return:    void
	// Remarks:   Transforms this path.
	// Notes:
	//************************************
	static void	Transform(FPD_ClipPath path, const FS_AffineMatrix matrix);

	//************************************
	// Function:  GetPath
	// Param[in]: path		The input clip path data object.
	// Param[in]: index		Specifies the zero-based path index in the clip path.
	// Param[out]: outPath	It receives the path.
	// Return:    void
	// Remarks:   Gets a path.
	// Notes:
	//************************************
	static void	GetPath(FPD_ClipPath path, FS_INT32 index, FPD_Path* outPath);

	//************************************
	// Function:  GetClipType
	// Param[in]: path		The input clip path data object.
	// Param[in]: index		Specifies the zero-based path index in the clip path
	// Return:    The clip type of specified path
	// Remarks:   Gets the clip type of specified path.
	// Notes:
	//************************************
	static FS_INT32	GetClipType(FPD_ClipPath path, FS_INT32 index);

	//************************************
	// Function:  GetTextCount
	// Param[in]: path	The input clip path data object.
	// Return:    The count of text objects in the clip path.
	// Remarks:   Gets the count of text objects in the clip path.
	// Notes:
	//************************************
	static FS_DWORD	GetTextCount(FPD_ClipPath path);

	//************************************
	// Function:  GetClipBox
	// Param[in]: path	The input clip path data object.
	// Return:    The clip box of the clip path.
	// Remarks:   Gets the clip box of the clip path.
	// Notes:
	//************************************
	static FS_FloatRect	GetClipBox(FPD_ClipPath path);

	//************************************
	// Function:  GetText
	// Param[in]: path	 The input clip path data object.
	// Param[in]: i		 Specifies the zero-based text object index in the clip path.
	// Return:    A text object.
	// Remarks:   Gets a text object.
	// Notes:
	//************************************
	static FPD_PageObject GetText(FPD_ClipPath path, FS_INT32 i);

	//************************************
	// Function:  AppendTexts
	// Param[in]: path			The input clip path data object.
	// Param[in]: pTextsBuf		Pointer to clipping text objects to append.
	// Param[in]: count			The count of clipping text objects to append.
	// Return:    void
	// Remarks:   Appends clipping text objects.
	// Notes:
	//************************************
	static void AppendTexts(FPD_ClipPath path, FPD_PageObject* pTextsBuf, FS_INT32 count);

	//************************************
	// Function:  SetCount
	// Param[in]: path			The input clip path data object.
	// Param[in]: path_count	The estimated count of path in the clip path data.
	// Param[in]: text_count	The estimated count of text object in the clip path data.
	// Return:    void
	// Remarks:   Estimates the count of path and text in the clip path data, and allocate the memory.
	// Notes:
	//************************************
	static void SetCount(FPD_ClipPath path, FS_INT32 path_count, FS_INT32 text_count);

	//************************************
	// Function:  IsNull
	// Param[in]: path	The input clip path data object.
	// Return:    Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
	// Remarks:   Tests whether the path data object is <a>NULL</a> or not.
	// Notes:
	//************************************
	static FS_BOOL IsNull(FPD_ClipPath path);

	//************************************
	// Function:  GetModify
	// Param[in]: path	The input clip path data object.
	// Return:    void.
	// Remarks:	  The interface helps init the object if the object is NULL.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void GetModify(FPD_ClipPath path);

	//************************************
	// Function:  GetPathPointer
	// Param[in]: path		The input clip path data object.
	// Param[in]: index		Specifies the zero-based path index in the clip path.
	// Return:    The pointer to the specified path.
	// Remarks:   Gets the pointer to the specified path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FPD_Path	GetPathPointer(FPD_ClipPath path, FS_INT32 index);	

	//************************************
	// Function: Copy
	// Param[in]: path		The input clip path data object.
	// Return:   FPD_ClipPath.
	// Remarks: Copy clip path data object.
	// Notes:	
	//************************************
	static FPD_ClipPath	Copy(FPD_ClipPath path);
};

class CFPD_ColorState_V1
{	
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty PDF color state object.
	// Remarks:	  Creates a new empty PDF color state object.
	// Notes:
	//************************************
	static FPD_ColorState New(void);

	//************************************
	// Function:  Destroy 
	// Param[in]: clrState The input PDF color state object.
	// Return:    void
	// Remarks:   Destroys the PDF color state object.
	// Notes:
	//************************************
	static void	Destroy(FPD_ColorState clrState);

	
	//************************************
	// Function:  GetFillColor
	// Param[in]: clrState	The input PDF color state object.
	// Return:    The filling color.
	// Remarks:	  Gets the filling color.
	// Notes:
	//************************************
	static FPD_Color GetFillColor(FPD_ColorState clrState);


	//************************************
	// Function:  GetStrokeColor
	// Param[in]: clrState	The input PDF color state object.
	// Return:    The stroking color.
	// Remarks:	  Gets the stroking color.
	// Notes:
	//************************************
	static FPD_Color GetStrokeColor(FPD_ColorState clrState);


	//************************************
	// Function:  SetFillColor
	// Param[in]: clrState		The input PDF color state object.
	// Param[in]: clrSpace		The color space of the filling color.
	// Param[in]: pValue		The color component values in the specified color space.
	// Param[in]: nValues		The count of the input parameters.
	// Return:    void
	// Remarks:	  Sets the filling normal color.
	// Notes:
	//************************************
	static void SetFillColor(FPD_ColorState clrState, FPD_ColorSpace clrSpace, FS_FLOAT* pValue, FS_INT32 nValues);


	//************************************
	// Function:  SetStrokeColor
	// Param[in]: clrState		The input PDF color state object.
	// Param[in]: clrSpace		The color space of the stroking color.
	// Param[in]: pValue		The color component values in the specified color space.
	// Param[in]: nValues		The count of the input parameters.
	// Return:    void
	// Remarks:	  Sets the stroking normal color.
	// Notes:
	//************************************
	static void SetStrokeColor(FPD_ColorState clrState, FPD_ColorSpace clrSpace, FS_FLOAT* pValue, FS_INT32 nValues);


	//************************************
	// Function:  SetFillPatternColor
	// Param[in]: clrState		The input PDF color state object.
	// Param[in]: pattern		The input pattern.
	// Param[in]: pValue		The input parameters for the pattern color.
	// Param[in]: nValues		The count of the input parameters.
	// Return:    void
	// Remarks:	  Sets the filling pattern color.
	// Notes:
	//************************************
	static void SetFillPatternColor(
		FPD_ColorState clrState, 
		FPD_Pattern pattern, 
		FS_FLOAT* pValue, 
		int nValues
		);


	//************************************
	// Function:  SetStrokePatternColor
	// Param[in]: clrState		The input PDF color state object.
	// Param[in]: pattern		The input pattern.
	// Param[in]: pValue		The input parameters for the pattern color.
	// Param[in]: nValues		The count of the input parameters.
	// Return:    void
	// Remarks:	  Sets the stroking pattern color.
	// Notes:
	//************************************
	static void SetStrokePatternColor(
		FPD_ColorState clrState, 
		FPD_Pattern pattern, 
		FS_FLOAT* pValue, 
		int nValues
		);

	//************************************
	// Function:  IsNull
	// Param[in]: clrState		The input PDF color state object.
	// Return:    Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
	// Remarks:	  Tests whether the color state object is <a>NULL</a> or not.
	// Notes:
	//************************************
	static FS_BOOL IsNull(FPD_ColorState clrState);

	//************************************
	// Function:  GetModify
	// Param[in]: clrState The input PDF color state object.
	// Return:    void.
	// Remarks:	  The interface helps init the object if the object is NULL.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void GetModify(FPD_ColorState clrState);

	//************************************
	// Function:  NotUseFillColor
	// Param[in]: clrState		The input PDF color state object.
	// Return:    void
	// Remarks:	  Do not use the filling mode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void NotUseFillColor(FPD_ColorState clrState);

	//************************************
	// Function:  Copy
	// Param[in]: colorState		The input PDF color state object.
	// Return:   FPD_ColorState.
	// Remarks:	  Copy color state object.
	// Notes:
	//************************************
	static FPD_ColorState Copy(FPD_ColorState colorState);
};

class CFPD_TextState_V1
{
public:

	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty PDF text state object.
	// Remarks:	  Creates a new empty PDF text state object.
	// Notes:
	//************************************
	static FPD_TextState New(void);


	//************************************
	// Function:  Destroy
	// Param[in]: textState The input PDF text state object.
	// Return:    void
	// Remarks:	  Destroys the PDF text state object.
	// Notes:
	//************************************
	static void Destroy(FPD_TextState textState);


	//************************************
	// Function:  GetFont	
	// Param[in]: textState	The input PDF text state object.
	// Return:    The font.
	// Remarks:	  Gets the font.
	// Notes:
	//************************************
	static FPD_Font	GetFont(FPD_TextState textState);


	//************************************
	// Function:  SetFont
	// Param[in]: textState		The input PDF text state object.
	// Param[in]: font			The font to set.
	// Return:    void
	// Remarks:	  Sets the font. 
	// Notes:
	//************************************
	static void		SetFont(FPD_TextState textState, FPD_Font font);


	//************************************
	// Function:  GetFontSize
	// Param[in]: textState	The input PDF text state object.
	// Return:    The font size.
	// Remarks:	  Gets the font size.
	// Notes:
	//************************************
	static FS_FLOAT	GetFontSize(FPD_TextState textState);


	//************************************
	// Function:  GetMatrix	
	// Param[in]: textState	The input PDF text state object.
	// Return:    The text transformation matrix. It has 4 items.(matrix[4]).
	// Remarks:	  Gets The text transformation matrix. Tt has 4 items.(matrix[4]).
	// Notes:
	//************************************
	static FS_FLOAT* GetMatrix(FPD_TextState textState);


	//************************************
	// Function:  GetFontSizeV
	// Param[in]: textState	The input PDF text state object.
	// Return:    The vertical size in device units.
	// Remarks:	  Gets the vertical size in device units.
	// Notes:
	//************************************
	static FS_FLOAT	GetFontSizeV(FPD_TextState textState);


	//************************************
	// Function:  GetFontSizeH 
	// Param[in]: textState	The input PDF text state object.
	// Return:	  The horizontal size in device units
	// Remarks:	  Gets the horizontal size in device units
	// Notes:
	//************************************
	static FS_FLOAT	GetFontSizeH(FPD_TextState textState);


	//************************************
	// Function:  GetBaselineAngle
	// Param[in]: textState	The input PDF text state object.
	// Return:    The angle between device space X-axis and text baseline. In radians.
	// Remarks:	  Gets the angle between device space X-axis and text baseline. In radians.
	// Notes:
	//************************************
	static FS_FLOAT	GetBaselineAngle(FPD_TextState textState);


	//************************************
	// Function:  GetShearAngle
	// Param[in]: textState	The input PDF text state object.
	// Return:    The angle that text space Y-axis shears in device space. In radians.
	// Remarks:	  Gets the angle that text space Y-axis shears in device space. In radians.
	// Notes:
	//************************************
	static FS_FLOAT	GetShearAngle(FPD_TextState textState);

	//************************************
	// Function:  SetFontSize
	// Param[in]: textState	The input PDF text state object.
	// Param[in]: fontSize	The input font size.
	// Return:    void
	// Remarks:	  Sets the font size.
	// Notes:
	//************************************
	static void	SetFontSize(FPD_TextState textState, FS_FLOAT fontSize);

	//************************************
	// Function:  SetCharSpace
	// Param[in]: textState	The input PDF text state object.
	// Param[in]: fCharSpace	The input character space.
	// Return:    void
	// Remarks:	  Sets the character space.
	// Notes:
	//************************************
	static void	SetCharSpace(FPD_TextState textState, FS_FLOAT fCharSpace);

	//************************************
	// Function:  SetWordSpace
	// Param[in]: textState		The input PDF text state object.
	// Param[in]: fWordSpace	The input word space.
	// Return:    void
	// Remarks:	  Sets the word space.
	// Notes:
	//************************************
	static void	SetWordSpace(FPD_TextState textState, FS_FLOAT fWordSpace);

	//************************************
	// Function:  SetMatrix
	// Param[in]: textState		The input PDF text state object.
	// Param[in]: matrix		The input text transformation matrix.
	// Return:    void
	// Remarks:	  Sets the text transformation matrix.
	// Notes:
	//************************************
	static void	SetMatrix(FPD_TextState textState, FS_FLOAT	matrix[4]);

	//************************************
	// Function:  SetTextMode
	// Param[in]: textState		The input PDF text state object.
	// Param[in]: iTextMode		The input text mode. Only 0 is valid in this version.
	// Return:    void
	// Remarks:	  Sets the text mode.
	// Notes:
	//************************************
	static void	SetTextMode(FPD_TextState textState, FS_INT32 iTextMode);

	//************************************
	// Function:  SetTextCTM
	// Param[in]: textState		The input PDF text state object.
	// Param[in]: CTM			The input CTM.
	// Return:    void
	// Remarks:	  Sets the CTM for stroking purpose.
	// Notes:
	//************************************
	static void	SetTextCTM(FPD_TextState textState, FS_FLOAT CTM[4]);

	//************************************
	// Function:  GetTextMode
	// Param[in]: textState		The input PDF text state object.
	// Return:    The text mode.
	// Remarks:	  Gets the text mode.
	// Notes:
	//************************************
	static FS_INT32	GetTextMode(FPD_TextState textState);

	//************************************
	// Function:  GetTextCTM
	// Param[in]: textState		The input PDF text state object.
	// Param[out]: outCTM		It receives the text CTM for stroking purpose.
	// Return:    void
	// Remarks:	  Gets the CTM for stroking purpose. The CTM array must be allocated and freed by caller. 
	// It must contain 4 elements.
	// Notes:
	//************************************
	static void	GetTextCTM(FPD_TextState textState, FS_FLOAT* outCTM);

	//************************************
	// Function:  GetCharSpace
	// Param[in]: textState	The input PDF text state object.
	// Return:    The character space.
	// Remarks:	  Gets the character space.
	// Notes:
	//************************************
	static FS_FLOAT	GetCharSpace(FPD_TextState textState);

	//************************************
	// Function:  GetWordSpace
	// Param[in]: textState		The input PDF text state object.
	// Return:    The word space.
	// Remarks:	  Gets the word space.
	// Notes:
	//************************************
	static FS_FLOAT	GetWordSpace(FPD_TextState textState);

	//************************************
	// Function:  IsNull
	// Param[in]: textState		The input PDF text state object.
	// Return:    Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
	// Remarks:	  Tests whether the text state object is <a>NULL</a> or not.
	// Notes:
	//************************************
	static FS_BOOL	IsNull(FPD_TextState textState);

	//************************************
	// Function:  GetModify
	// Param[in]: textState The input PDF text state object.
	// Return:    void.
	// Remarks:	  The interface helps init the object if the object is NULL.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void GetModify(FPD_TextState textState);

};


//PDF general state class
class CFPD_GeneralState_V1
{
public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty PDF general state object.
	// Remarks:	  Creates a new empty PDF general state object.
	// Notes:
	//************************************
	static FPD_GeneralState New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: genState The input PDF general state data object.
	// Return:    void
	// Remarks:	  Destroys the PDF general state data object.
	// Notes:
	//************************************
	static void	Destroy(FPD_GeneralState genState);

	//************************************
	// Function:  SetRenderIntent
	// Param[in]: genState	The input PDF general state data object.
	// Param[in]: ri		The input rendering intent.
	// Return:    void
	// Remarks:	  Sets the rendering intent.
	// Notes:
	//************************************
	static void	SetRenderIntent(FPD_GeneralState genState, FS_LPCSTR ri);

	//************************************
	// Function:  GetBlendType
	// Param[in]: genState	The input PDF general state data object.
	// Return:    The blend mode.
	// Remarks:	  Gets the blend mode.
	// Notes:
	//************************************
	static FS_INT32 GetBlendType(FPD_GeneralState genState);

	//************************************
	// Function:  GetAlpha
	// Param[in]: genState		The input PDF general state data object.
	// Param[in]: bStroke		Whether to get the current stroking alpha constant.
	// Return:    The current filling or stroking alpha constant.
	// Remarks:	  Gets the current filling or stroking alpha constant.
	// Notes:
	//************************************
	static FS_INT32 GetAlpha(FPD_GeneralState genState, FS_BOOL bStroke);

	//************************************
	// Function:  SetBlendMode
	// Param[in]: genState		The input PDF general state data object.
	// Param[in]: BlendMode		The input current blend mode name.
	// Return:    void
	// Remarks:	  Sets the current blend mode name.
	// Notes:
	//************************************
	static void SetBlendMode(FPD_GeneralState genState, char BlendMode[16]);

	//************************************
	// Function:  SetBlendType
	// Param[in]: genState		The input PDF general state data object.
	// Param[in]: iBlendType	The input blend type.
	// Return:    void
	// Remarks:	  Sets the current blend mode to be used in the transparent imaging model.
	// Notes:
	//************************************
	static void SetBlendType(FPD_GeneralState genState, FS_INT32 iBlendType);

	//************************************
	// Function:  SetSoftMask
	// Param[in]: genState		The input PDF general state data object.
	// Param[in]: softMask		The input current soft mask.
	// Return:    void
	// Remarks:	  Sets the current soft mask, specifying the mask shape or mask opacity values to be used in the transparent imaging model.
	// Notes:
	//************************************
	static void SetSoftMask(FPD_GeneralState genState, FPD_Object softMask);

	//************************************
	// Function:  SetSoftMaskMatrix
	// Param[in]: genState			The input PDF general state data object.
	// Param[in]: SoftMaskMatrix	The input matrix of the current soft mask.
	// Return:    void
	// Remarks:	  Sets the matrix of the current soft mask.
	// Notes:
	//************************************
	static void SetSoftMaskMatrix(FPD_GeneralState genState, FS_FLOAT SoftMaskMatrix[6]);

	//************************************
	// Function:  SetStrokeAlpha
	// Param[in]: genState			The input PDF general state data object.
	// Param[in]: fStrokeAlpha		The input current stroking alpha constant.
	// Return:    void
	// Remarks:	  Sets The current stroking alpha constant, specifying the constant shape or constant 
	//            opacity value to be used for stroking operations in the transparent imaging model.
	// Notes:
	//************************************
	static void SetStrokeAlpha(FPD_GeneralState genState, FS_FLOAT fStrokeAlpha);

	//************************************
	// Function:  SetFillAlpha
	// Param[in]: genState			The input PDF general state data object.
	// Param[in]: fFillAlpha		The input current filling alpha constant.
	// Return:    void
	// Remarks:	  Same as stroking alpha, but for non-stroking operations.
	// Notes:
	//************************************
	static void SetFillAlpha(FPD_GeneralState genState, FS_FLOAT fFillAlpha);

	//************************************
	// Function:  IsNull
	// Param[in]: genState			The input PDF general state data object.
	// Return:    Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
	// Remarks:	  Tests whether the general state object is <a>NULL</a> or not.
	// Notes:
	//************************************
	static FS_BOOL IsNull(FPD_GeneralState genState);

	//************************************
	// Function:  GetModify
	// Param[in]: genState The input PDF general state object.
	// Return:    void.
	// Remarks:	  The interface helps init the object if the object is NULL.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void GetModify(FPD_GeneralState genState);
};

class CFPD_GraphState_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty PDF graphic state object.
	// Remarks:	  Creates a new empty PDF graphic state object.
	// Notes:
	//************************************
	static FPD_GraphState New(void);


	//************************************
	// Function:  Destroy
	// Param[in]: graphState	The graphic state object to be destroyed.
	// Return:    void
	// Remarks:	  Destroys a graphic state object.
	// Notes:
	//************************************
	static void Destroy(FPD_GraphState graphState);

	//************************************
	// Function:  SetDashCount
	// Param[in]: graphState	The input graphic state object.
	// Param[in]: count		The new count of dash points.
	// Return:    void
	// Remarks:	  In order to keep heap integrity, the function is used to allocate enough buffer for dash array.
	// Notes:
	//************************************
	static void	SetDashCount(FPD_GraphState graphState, FS_INT32 count);

	//************************************
	// Function:  GetDashCount
	// Param[in]: graphState	The input graphic state object.
	// Return:    The total size of dash array.
	// Remarks:	  Gets the total size of dash array.
	// Notes:
	//************************************
	static FS_INT32	GetDashCount(FPD_GraphState graphState);

	//************************************
	// Function:  GetDashArray
	// Param[in]: graphState	The input graphic state object.
	// Return:    The dash array used by graphic state object.
	// Remarks:	  Gets the dash array.
	// Notes:
	//************************************
	static FS_FLOAT* GetDashArray(FPD_GraphState graphState);


	//************************************
	// Function:  GetDashPhase
	// Param[in]: graphState	The input graphic state object.
	// Return:    The dash phase for line dash pattern.
	// Remarks:	  Gets the dash phase for line dash pattern.
	// Notes:
	//************************************
	static FS_FLOAT GetDashPhase(FPD_GraphState graphState);

	//************************************
	// Function:  SetDashPhase
	// Param[in]: graphState	The input graphic state object.
	// Param[in]: dashPhase		The new dash phase.
	// Return:    void
	// Remarks:	  Sets the new dash phase for line dash pattern.
	// Notes:
	//************************************
	static void SetDashPhase(FPD_GraphState graphState, FS_FLOAT dashPhase);

	//************************************
	// Function:  GetLineCap
	// Param[in]: graphState	The input graphic state object.
	// Return:    The line cap style.
	// Remarks:	  Gets the line cap style.
	// Notes:
	//************************************
	static FPD_LineCap GetLineCap(FPD_GraphState graphState);

	//************************************
	// Function:  SetLineCap
	// Param[in]: graphState	The input graphic state object.
	// Param[in]: cap	The new style of line cap.
	// Return:    void
	// Remarks:	  Sets the new line cap style.
	// Notes:
	//************************************
	static void SetLineCap(FPD_GraphState graphState, FPD_LineCap cap);

	//************************************
	// Function:  GetLineJoin
	// Param[in]: graphState	The input graphic state object.
	// Return:    The line join style.
	// Remarks:	  Gets the line join style.
	// Notes:
	//************************************
	static FPD_LineJoin GetLineJoin(FPD_GraphState graphState);

	//************************************
	// Function:  SetLineJoin
	// Param[in]: graphState	The input graphic state object.
	// Param[in]: join	The new style of line join.
	// Return:    void
	// Remarks:	  Sets the new style of line join.
	// Notes:
	//************************************
	static void SetLineJoin(FPD_GraphState graphState, FPD_LineJoin join);

	//************************************
	// Function:  GetMiterLimit
	// Param[in]: graphState	The input graphic state object.
	// Return:    The miter limit for line join.
	// Remarks:	  Gets the miter limit for line join.
	// Notes:
	//************************************
	static FS_FLOAT GetMiterLimit(FPD_GraphState graphState);

	//************************************
	// Function:  SetMiterLimit
	// Param[in]: graphState	The input graphic state object.
	// Param[in]: limit		The new miter limit for line join.
	// Return:    void
	// Remarks:	  Sets the new miter limit for line join.
	// Notes:
	//************************************
	static void SetMiterLimit(FPD_GraphState graphState, FS_FLOAT limit);

	//************************************
	// Function:  GetLineWidth
	// Param[in]: graphState	The input graphic state object.
	// Return:    The line width.
	// Remarks:	  Gets the line width.
	// Notes:
	//************************************
	static FS_FLOAT GetLineWidth(FPD_GraphState graphState);

	//************************************
	// Function:  SetLineWidth
	// Param[in]: graphState	The input graphic state object.
	// Param[in]: width		The new width of lines.
	// Return:    void
	// Remarks:	  Sets new width of lines.
	// Notes:
	//************************************
	static void SetLineWidth(FPD_GraphState graphState, FS_FLOAT width);

	//************************************
	// Function:  IsNull
	// Param[in]: graphState	The input graphic state object.
	// Return:    Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
	// Remarks:	  Tests whether the graphic state object is <a>NULL</a> or not.
	// Notes:
	//************************************
	static FS_BOOL IsNull(FPD_GraphState graphState);
	
	//************************************
	// Function:  GetModify
	// Param[in]: graphState The input PDF graph state object.
	// Return:    void.
	// Remarks:	  The interface helps init the object if the object is NULL.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void GetModify(FPD_GraphState graphState);

	//************************************
	// Function:  SetDashArray
	// Param[in]: graphState	The input graphic state object.
	// Param[in]: dashArray		The input dash array.
	// Return:    void
	// Remarks:	  Sets the dash phase for line dash pattern.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void SetDashArray(FPD_GraphState graphState, FS_FLOAT* dashArray);
};


//class page object
class CFPD_PageObject_V1
{
public:

	//************************************
	// Function:  New
	// Param[in]: type		The input page object type. Like FPD_PAGEOBJ_TEXT,FPD_PAGE_EMPTY
	// Return:    A page object.
	// Remarks:   Creates a new empty PDF page object.
	// Notes:
	//************************************
	static FPD_PageObject New(FS_INT32 type);


	//************************************
	// Function:  Destroy
	// Param[in]: pageObj The input PDF page object.
	// Return:    void
	// Remarks:   Destroys the PDF page object.
	// Notes:
	//************************************
	static void	Destroy(FPD_PageObject pageObj);


	//************************************
	// Function:  Clone
	// Param[in]: pageObj		The source object.
	// Return:    The cloned object.
	// Remarks:   Clones a page object.
	// Notes:
	//************************************
	static FPD_PageObject	Clone(FPD_PageObject pageObj);


	//************************************
	// Function:  Copy
	// Param[in]: pageObj		The input PDF page object.
	// Param[in]: srcObject		The source page object.
	// Return:    void
	// Remarks:   Copies from another page object.
	// Notes:
	//************************************
	static void	Copy(FPD_PageObject pageObj, const FPD_PageObject srcObject);

	//************************************
	// Function:  RemoveClipPath
	// Param[in]: pageObj	The input PDF page object.
	// Return:    void
	// Remarks:   Removes clipping path of the object.
	// Notes:
	//************************************
	static void	RemoveClipPath(FPD_PageObject pageObj);


	//************************************
	// Function:  AppendClipPath
	// Param[in]: pageObj		The input PDF page object.
	// Param[in]: path			The input clipping path.
	// Param[in]: type			The clip type of the input clipping path.
	// Param[in]: bAutoMerge	Whether to merge the clipping path automatically.
	// Return:    void
	// Remarks:   Appends a clipping path.
	// Notes:
	//************************************
	static void	AppendClipPath(FPD_PageObject pageObj, FPD_Path path, FS_INT32 type, FS_BOOL bAutoMerge);


	//************************************
	// Function:  CopyClipPath
	// Param[in]: pageObj		The input PDF page object.
	// Param[in]: srcObj		The source page object.
	// Return:    void
	// Remarks:   Copies clipping path from another object.
	// Notes:
	//************************************
	static void	CopyClipPath(FPD_PageObject pageObj, FPD_PageObject srcObj);


	//************************************
	// Function:  TransformClipPath
	// Param[in]: pageObj		The input PDF page object.
	// Param[in]: matrix		The matrix used to transform.
	// Return:    void
	// Remarks:   Transforms the clip path. Rotate, shear, or move clip path.
	// Notes:
	//************************************
	static void	TransformClipPath(FPD_PageObject pageObj, FS_AffineMatrix matrix);


	//************************************
	// Function:  SetColorState
	// Param[in]: pageObj	The input PDF page object.
	// Param[in]: state		The new color state.
	// Return:    void
	// Remarks:   Sets the color state.
	// Notes:
	//************************************
	static void	SetColorState(FPD_PageObject pageObj, FPD_ColorState state);


	//************************************
	// Function:  GetBBox
	// Param[in]: pageObj	The input PDF page object.
	// Param[in]: pMatrix	The input transformation matrix.
	// Return:    The bounding box of the page object.
	// Remarks:   Gets the bounding box of the page object, optionally with a transformation matrix.
	// Notes:
	//************************************
	static FS_Rect GetBBox(FPD_PageObject pageObj, FS_AffineMatrix* pMatrix);

	//************************************
	// Function:  GetOriginalBBox
	// Param[in]: pageObj	The input PDF page object.
	// Return:    The original bounding box of the page object
	// Remarks:   Gets the original bounding box of the page object.
	// Notes:
	//************************************
	static FS_FloatRect GetOriginalBBox(FPD_PageObject pageObj);

	//************************************
	// Function:  GetType
	// Param[in]: pageObj	The input PDF page object.
	// Return:    Gets the page object type. Like FPD_PAGEOBJ_TEXT, FPD_PAGEOBJ_PATH etc..
	// Remarks:   The page object type.
	// Notes:
	//************************************
	static FS_INT32	GetType(FPD_PageObject pageObj);

	//************************************
	// Function:  GetClipPath
	// Param[in]: pageObj	The input PDF page object.
	// Return:    The clip path state.
	// Remarks:   Gets the clip path state.
	// Notes: It will get a modifiable copy of the object,suggest use FPDClipPathGetClipPath2.
	//************************************
	static FPD_ClipPath	GetClipPath(FPD_PageObject pageObj);


	//************************************
	// Function:  GetGraphState
	// Param[in]: pageObj	The input PDF page object.
	// Return:    The graph state for graphs and type3 font or stroke texts.
	// Remarks:   Gets the graph state. For graphs and type3 font or stroke texts.
	// Notes:
	//************************************
	static FPD_GraphState GetGraphState(FPD_PageObject pageObj);


	//************************************
	// Function:  GetColorState
	// Param[in]: pageObj	The input PDF page object.
	// Return:    The color state for texts, graphs and uncolored images.
	// Remarks:   Gets the color state. For texts, graphs and uncolored images.
	// Notes: It will a modifiable copy of the object. Suggest use FPDColorStateGetColorState2;
	//************************************
	static FPD_ColorState GetColorState(FPD_PageObject pageObj);


	//************************************
	// Function:  GetTextState
	// Param[in]: pageObj	The input PDF page object.
	// Return:    The text state for texts only.
	// Remarks:   Gets the text state. For texts only.
	// Notes:
	//************************************
	static FPD_TextState GetTextState(FPD_PageObject pageObj);


	//************************************
	// Function:  GetGeneralState
	// Param[in]: pageObj	The input PDF page object.
	// Return:    The general state for all objects.
	// Remarks:   Gets the general state. For all objects.
	// Notes:
	//************************************
	static FPD_GeneralState	GetGeneralState(FPD_PageObject pageObj);

	//************************************
	// Function:  GetContentMark
	// Param[in]: pageObj	        The input PDF page object.
	// Param[out]: outContentMark	The input FPD_ContentMark. It create by FPDContentMarkNew.
	// Return:    The content mark. For all objects.
	// Remarks:   Gets the agent object CPlugin_InternalObj, it will return data of ContentMark object.
	// Notes:
	//************************************
	static void GetContentMark(FPD_PageObject pageObj, FPD_ContentMark* outContentMark);

	//************************************
	// Function:  DefaultStates
	// Param[in]: pageObj	The input PDF page object.
	// Return:    void
	// Remarks:   Sets all graphic states to default.
	// Notes:
	//************************************
	static void DefaultStates(FPD_PageObject pageObj);

	//************************************
	// Function:  CopyStates
	// Param[in]: pageObj	The input PDF page object.
	// Param[in]: src		The input graphic states.
	// Return:    void
	// Remarks:   Copies from another graphic states.
	// Notes:
	//************************************
	static void CopyStates(FPD_PageObject pageObj, const FPD_PageObject src);


	//************************************
	// Function:  SetGraphState
	// Param[in]: pageObj		The input PDF page object.
	// Param[in]: grahpState	The graphic state to be set.
	// Return:    void
	// Remarks:   Sets the graph state.
	// Notes:
	//************************************
	static void SetGraphState(FPD_PageObject pageObj, FPD_GraphState grahpState);

	//************************************
	// Function:  SetTextState
	// Param[in]: pageObj	The input PDF page object.
	// Param[in]: textState	The text state to be set.
	// Return:    void
	// Remarks:   Sets the text state. 
	// Notes:
	//************************************
	static void SetTextState(FPD_PageObject pageObj, FPD_TextState textState);

	//************************************
	// Function:  SetGeneralState
	// Param[in]: pageObj	The input PDF page object.
	// Param[in]: genState	The general state to be set.
	// Return:    void
	// Remarks:   Sets the general state. 
	// Notes:
	//************************************
	static void SetGeneralState(FPD_PageObject pageObj, FPD_GeneralState genState);

	//************************************
	// Function:  HasClipPath
	// Param[in]: pageObj	The input PDF page object.
	// Return: <a>TRUE</a> if the page object has the clip path, otherwise not.
	// Remarks: Checks whether the page object has the clip path or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	//************************************
	static FS_BOOL	HasClipPath(FPD_PageObject pageObj);

	//************************************
	// Function:  GetContentMark2
	// Param[in]: pageObj				The input PDF page object.
	// Param[in]: bModify				Whether get a copy object.
	// Param[out]: outContentMark	    The input FPD_ContentMark object. It create by FPDContentMarkNew.
	// Return:    void
	// Remarks:   Gets the agent object CPlugin_InternalObj, it will return data of ContentMark object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static void GetContentMark2(FPD_PageObject pageObj, FS_BOOL bModify, FPD_ContentMark* outContentMark);
	
	//************************************
	// Function:  TransformGeneralState
	// Param[in]: pageObj				The input PDF page object.
	// Param[in]: matrix	            The matrix used to transform.
	// Return:    void
	// Remarks:   Transform the general state matrix.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static void TransformGeneralState(FPD_PageObject pageObj, FS_AffineMatrix matrix);
	
	//************************************
    // Function:  Transform
	// Param[in]: pageObj				The input PDF page object.
	// Param[in]: matrix	            The transform matrix used to transform.
	// Return:    void
	// Remarks:   Transform the graphics object. Rotate, shear, or move object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static void		Transform(FPD_PageObject pageObj, FS_AffineMatrix matrix);

	//************************************
	// Function:  CastToFormObject
	// Param[in]: pageObj				The input PDF page object.	
	// Return:    FPD_PageObject
	// Remarks:   Convert  GraphicObject to CPDF_FormObject.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FPD_PageObject	CastToFormObject(FPD_PageObject pageObj);

	//************************************
	// Function:  CastToFormObject
	// Param[in]: pageObj				The input PDF page object.	
	// Param[in]: contentMark			The input content mark.	
	// Return:    void
	// Remarks:  Set the content mark.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void	SetContentMark(FPD_PageObject pageObj, FPD_ContentMark contentMark);

	//************************************
	// Function:  GetClipPath2
	// Param[in]: pageObj	The input PDF page object.
	// Param[out]: outClipPath	The input FPD_ClipPathInternal object,it create by FPDClipPathInternalNew.
	// Return:    void
	// Remarks:   Gets the FPD_ClipPathInternal, it can get FPD_ClipPath by FPDClipPathInternalGetClipPath.
	// Notes:
	//************************************
	static void	GetClipPath2(FPD_PageObject pageObj, FPD_ClipPath* outClipPath);

	//************************************
	// Function:  GetColorState2
	// Param[in]: pageObj	The input PDF page object.
	// Param[out]: outColorState	Get the color state.
	// Return:    void
	// Remarks:   Get the color state.
	// Notes:
	//************************************
	static void GetColorState2(FPD_PageObject pageObj, FPD_ColorState *outColorState);
	
	 //************************************
	 // Function:  Clone2
	 // Param[in]: pageObj	The input PDF page object.
	 // Param[in]: bCloneMC	Whether to clone the marked content.	 
	 // Return: FPD_PageObject   A cloned graphics object.
	 // Remarks:  Clone a graphics object.
	 // Notes:
	 //************************************
	static FPD_PageObject	Clone2(FPD_PageObject pageObj, FS_BOOLEAN bCloneMC);
};

//class page text object
class CFPD_TextObject_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    The PDF text object
	// Remarks:   Creates a new empty PDF text object.
	// Notes:
	//************************************
	static FPD_PageObject New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: objText The input PDF text object.
	// Return:    void
	// Remarks:   Destroys the input PDF text object. If it is added to the page, it is taken over and don't destroy it.
	// Notes:
	//************************************
	static void	Destroy(FPD_PageObject objText);

	//************************************
	// Function:  CountItems
	// Param[in]: objText	The input PDF text object.
	// Return:    The count of text object items.
	// Remarks:   Gets the count of text object items.
	// Notes:
	//************************************
	static FS_INT32 CountItems(FPD_PageObject objText);

	//************************************
	// Function:  GetItemInfo
	// Param[in]: objText	The input PDF text object.
	// Param[in]: index		Specifies zero-based item index in the text object.
	// Return:    The specified text object item information.
	// Remarks:   Gets specified text object item information.
	// Notes:
	//************************************
	static FPD_TextObjectItem GetItemInfo(FPD_PageObject objText, FS_INT32 index);

	//************************************
	// Function:  CountChars
	// Param[in]: objText	The input PDF text object.
	// Return:    The count of characters in the text object. 
	// Remarks:   Gets the count of characters in the text object. 
	// Notes:
	//************************************
	static FS_INT32 CountChars(FPD_PageObject objText);

	//************************************
	// Function:   GetCharInfo
	// Param[in]:  objText			The input PDF text object.
	// Param[in]:  index			Specifies zero-based character index in the text object.
	// Param[out]: outCharcode		It receives the character code.
	// Param[out]: outKerning		It receives the kerning(x-direction only).
	// Return:     void
	// Remarks:    Gets the information of specified character.
	// Notes:
	//************************************
	static void GetCharInfo(FPD_PageObject objText, FS_INT32 index, FS_DWORD* outCharcode, FS_FLOAT* outKerning);

	//************************************
	// Function:  GetPosX
	// Param[in]: objText	The input PDF text object.
	// Return:    The x-coordinate of the origin in the device space
	// Remarks:   Gets the x-coordinate of the origin in the device space
	// Notes:
	//************************************
	static FS_FLOAT	GetPosX(FPD_PageObject objText);

	//************************************
	// Function:  GetPosY
	// Param[in]: objText	The input PDF text object.
	// Return:    The y-coordinate of the origin in the device space.
	// Remarks:   Gets the y-coordinate of the origin in the device space.
	// Notes:
	//************************************
	static FS_FLOAT	GetPosY(FPD_PageObject objText);

	//************************************
	// Function:   GetTextMatrix
	// Param[in]:  objText			The input PDF text object.
	// Param[out]: outMatrix		It receives the matrix from text space to object space.
	// Return:     void
	// Remarks:    Gets matrix from text space to object space.
	// Notes:
	//************************************
	static void	GetTextMatrix(FPD_PageObject objText, FS_AffineMatrix* outMatrix);

	//************************************
	// Function:  GetFont
	// Param[in]: objText	The input PDF text object.
	// Return:    The font.
	// Remarks:   Gets the font.
	// Notes:
	//************************************
	static FPD_Font	GetFont(FPD_PageObject objText);

	//************************************
	// Function:  GetFontSize
	// Param[in]: objText	The input PDF text object.
	// Return:    The font size.
	// Remarks:   Gets the font size.
	// Notes:
	//************************************
	static FS_FLOAT	GetFontSize(FPD_PageObject objText);

	//************************************
	// Function:  SetEmpty
	// Param[in]: objText	The input PDF text object.
	// Return:    void
	// Remarks:   Sets the text object to be empty.
	// Notes:
	//************************************
	static void	SetEmpty(FPD_PageObject objText);

	//************************************
	// Function:  SetText
	// Param[in]: objText		The input PDF text object.
	// Param[in]: strText		The input text segment.
	// Return:    void
	// Remarks:   Sets a single text segment without any kerning inside.
	// Notes:
	//************************************
	static void SetText(FPD_PageObject objText, const FS_ByteString strText);


	//************************************
	// Function:  SetText2
	// Param[in]: objText		The input PDF text object.
	// Param[in]: strTextArr	The input text segments.
	// Param[in]: pKerning		The kerning array.
	// Return:    void
	// Remarks:   Sets text using segmented fashion.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void	SetText2(FPD_PageObject objText, FS_ByteStringArray strTextArr, FS_FLOAT* pKerning);


	//************************************
	// Function:  SetText3
	// Param[in]: objText		The input PDF text object.
	// Param[in]: nChars		The count of input character codes.
	// Param[in]: pCharCodes	The input character codes.
	// Param[in]: pKernings		The input kerning array.
	// Return:    void
	// Remarks:   Sets text using char-kerning pair fashion.
	// Notes:
	//************************************
	static void	SetText3(FPD_PageObject objText, FS_INT32 nChars, FS_DWORD* pCharCodes, FS_FLOAT* pKernings);


	//************************************
	// Function:  SetPosition
	// Param[in]: objText	The input PDF text object.
	// Param[in]: x			The x-coordinate in device space.
	// Param[in]: y			The y-coordinate in device space. 
	// Return:    void
	// Remarks:   Sets the origin position in device space.
	// Notes:
	//************************************
	static void	SetPosition(FPD_PageObject objText, FS_FLOAT x, FS_FLOAT y);


	//************************************
	// Function:  SetTextState
	// Param[in]: objText			The input PDF text object.
	// Param[in]: textState			The new text state.
	// Return:    void
	// Remarks:   Sets the text state.
	// Notes:
	//************************************
	static void	SetTextState(FPD_PageObject objText, FPD_TextState textState);

	//************************************
	// Function:  Transform
	// Param[in]: objText		The input PDF text object.
	// Param[in]: matrix		The transformation matrix.
	// Return:    void
	// Remarks:   Transforms the text object.
	// Notes:
	//************************************
	static void	Transform(FPD_PageObject objText, FS_AffineMatrix matrix);

	//************************************
	// Function:   CalcCharPos
	// Param[in]:  objText			The input PDF text object.
	// Param[out]: outPosArray		It receives the character position array.
	// Return:     void
	// Remarks:    Calculates origin positions in text space, for each character.
	// Notes:      The position array must be allocated and freed by caller. It must contain at least nChars*2 elements.
	//   For each character, the origin position (along the text baseline) and next origin position will be calculated.
	//************************************
	static void	CalcCharPos(FPD_PageObject objText, FS_FLOAT* outPosArray);

	//************************************
	// Function:  SetData
	// Param[in]: objText		The input PDF text object.
	// Param[in]: nChars		The count of characters to set.
	// Param[in]: pCharCodes	The input character codes array.
	// Param[in]: pCharPos		The input character positions array in text space.
	// Param[in]: x				The x-coordinate of the origin position, in device space.
	// Param[in]: y				The y-coordinate of the origin position, in device space.
	// Return:    void
	// Remarks:	  Sets text data.
	// Notes:
	//************************************
	static void	SetData(
		FPD_PageObject objText,
		FS_INT32 nChars, 
		FS_DWORD* pCharCodes, 
		FS_FLOAT* pCharPos, 
		FS_FLOAT x, 
		FS_FLOAT y
		);


	//************************************
	// Function:   GetData
	// Param[in]:  objText			The input PDF text object.
	// Param[out]: outCharCount		It receives the count of characters.
	// Param[out]: outCharCodes		It receives the character codes array.
	// Param[out]: outCharPos		It receives the character positions array in text space.
	// Return:     void
	// Remarks:	   Gets text data.
	// Notes:
	//************************************
	static void	GetData(FPD_PageObject objText, FS_INT32* outCharCount, FS_DWORD** outCharCodes, FS_FLOAT** outCharPos);

	//************************************
	// Function:  RecalcPositionData
	// Param[in]: objText	The input PDF text object.
	// Return:    void
	// Remarks:   Recalculates the position data.
	// Notes:
	//************************************
	static void	RecalcPositionData(FPD_PageObject objText);
	
	//************************************
	// Function:  GetCharRect
	// Param[in]: objText	The input PDF text object.
	// Param[in]: index	    Specify zero-based character index in the text object.
	// Param[in]: rect	    It receives the rect.
	// Return:    void
	// Remarks:   Get the rect of specified character.
	// Notes:
	//************************************
	static void	GetCharRect(FPD_PageObject objText, FS_INT32 index, FS_FloatRect* rect);

	//************************************
	// Function:  GetSpaceCharWidth
	// Param[in]: objText	The input PDF text object.	
	// Return:    FS_FLOAT
	// Remarks:   Get the space width.
	// Notes:
	//************************************
	static FS_FLOAT			GetSpaceCharWidth(FPD_PageObject objText);
	
	//************************************
	// Function:  GetCharInfo2
	// Param[in]: objText	    The input PDF text object.	
	// Param[in]: index			Specify zero-based character index in the text object.
	// Return:    FPD_TextObjectItem  It returns the specified text object item information.
    // Remarks:   Get the information of specified character.
	// Notes: The item must not be a kerning.
	//************************************
	static FPD_TextObjectItem GetCharInfo2(FPD_PageObject objText, FS_INT32 index);

	//************************************
	// Function:  GetIndex
	// Param[in]: objText	    The input PDF text object.
	// Return:   FS_INT32       Return the index of the text object.
	// Remarks:   Get the index of the text object.
	// Notes:
	//************************************
	static FS_INT32	 GetIndex(FPD_PageObject objText);

	//************************************
	// Function:  SetIndex
	// Param[in]: objText	    The input PDF text object.
	// Param[in]: index	        The input index of text object.
	// Return:  void
	// Remarks:   Set the index of the text object.
	// Notes:
	//************************************
	static void	 SetIndex(FPD_PageObject objText, FS_INT32 index);
};

//FPD_PathObject_V1
class CFPD_PathObject_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty PDF path object. 
	// Remarks:   Creates a new empty PDF path object.
	// Notes:
	//************************************
	static FPD_PageObject New(void);


	//************************************
	// Function:  Destroy
	// Param[in]: objPath	The input PDF path object.
	// Return:    void
	// Remarks:   Destroys the PDF path object.
	// Notes:
	//************************************
	static void	Destroy(FPD_PageObject objPath);


	//************************************
	// Function:  Transform
	// Param[in]: objPath		The input PDF path object.
	// Param[in]: matrix		The transformation matrix.
	// Return:    void
	// Remarks:   Transforms the path object.
	// Notes:
	//************************************
	static void	Transform(FPD_PageObject objPath, FS_AffineMatrix matrix);


	//************************************
	// Function:  SetGraphState
	// Param[in]: objPath			The input PDF path object.
	// Param[in]: graphState		The input new graph state.
	// Return:    void
	// Remarks:   Sets the graph state.
	// Notes:
	//************************************
	static void	SetGraphState(FPD_PageObject objPath, FPD_GraphState graphState);


	//************************************
	// Function:  CalcBoundingBox
	// Param[in]: objPath	The input PDF path object.
	// Return:    void
	// Remarks:   Calculates the bounding box.
	// Notes:
	//************************************
	static void	CalcBoundingBox(FPD_PageObject objPath);


	//************************************
	// Function:   GetTransformMatrix
	// Param[in]:  objPath				The input PDF path object.
	// Param[out]: outmatrix			It receives the transformation matrix.
	// Return:     void
	// Remarks:	   Gets the transformation matrix.
	// Notes:      Transformation matrix used to transform the path coordinates. Also used to determine line geometry.
	//************************************
	static void GetTransformMatrix(FPD_PageObject objPath, FS_AffineMatrix* outmatrix);


	//************************************
	// Function:  SetTransformMatrix
	// Param[in]: objPath		The input PDF path object.
	// Param[in]: matrix		The transformation matrix.
	// Return:    void
	// Remarks:   Sets the transformation matrix.
	// Notes:     Transformation matrix used to transform the path coordinates. Also used to determine line geometry.
	//************************************
	static void SetTransformMatrix(FPD_PageObject objPath, const FS_AffineMatrix* matrix);


	//************************************
	// Function:  GetPath
	// Param[in]: objPath	The input PDF path object.
	// Return:    The path data object.
	// Remarks:   Gets the path data object. Reference to path data.
	// Notes: It will get a modifiable copy of the object. Suggest use FPDPathObjectGetPath2.
	//************************************
	static FPD_Path	GetPath(FPD_PageObject objPath);


	//************************************
	// Function:  IsStrokeMode
	// Param[in]: objPath	The input PDF path object.
	// Return:    <a>TRUE</a> to stroke the path, otherwise not.
	// Remarks:   Tests whether the paint mode for the path object is stroking mode.
	// Notes:
	//************************************
	static FS_BOOL IsStrokeMode(FPD_PageObject objPath);


	//************************************
	// Function:  SetStrokeMode
	// Param[in]: objPath		The input PDF path object.
	// Param[in]: bStroke		True to stroke the path, otherwise not.
	// Return:    void
	// Remarks:   Sets whether to stroke the path.
	// Notes:
	//************************************
	static void	SetStrokeMode(FPD_PageObject objPath, FS_BOOL bStroke);


	//************************************
	// Function:  GetFillMode
	// Param[in]: objPath	The input PDF path object.
	// Return:    The filling mode code. See <a>FSFillingModeFlags</a>.
	// Remarks:   Gets the filling mode of the page object.
	// Notes:
	//************************************
	static FS_INT32 GetFillMode(FPD_PageObject objPath);

	//************************************
	// Function:  SetFillMode
	// Param[in]: objPath	The input PDF path object.
	// Param[in]: mode	The new filling mode. See <a>FSFillingModeFlags</a>.
	// Return:    void
	// Remarks:   Sets the new filling mode.
	// Notes:
	//************************************
	static void SetFillMode(FPD_PageObject objPath, FS_INT32 mode);

	//************************************
	// Function:  GetPath2
	// Param[in]: objPath	The input PDF path object.
	// Param[out]: outPath	Get the path object.
	// Return:    The path data object.
	// Remarks:   Get the path object.
	// Notes: 
	//************************************
	static void	GetPath2(FPD_PageObject objPath, FPD_Path* outPath);

	//************************************
	// Function:  SetPath
	// Param[in]: objPath	The input PDF path object.
	// Param[out]: path	    Set the path object.
	// Return:    void
	// Remarks:   Set the path object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void	SetPath(FPD_PageObject objPath, FPD_Path path);
};

//CFPD_ImageObject_V1
class CFPD_ImageObject_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty PDF image object.
	// Remarks:   Creates a new empty PDF image object.
	// Notes:
	//************************************
	static FPD_PageObject New(void);


	//************************************
	// Function:  Destroy
	// Param[in]: objImage The input PDF image object.
	// Return:    void
	// Remarks:   Destroys the PDF image object.
	// Notes:
	//************************************
	static void	Destroy(FPD_PageObject objImage);

	//************************************
	// Function:  Transform
	// Param[in]: objImage		The input PDF image object.
	// Param[in]: matrix		The transformation matrix.
	// Return:    void
	// Remarks:   Transforms the image object.
	// Notes:
	//************************************
	static void	Transform(FPD_PageObject objImage, FS_AffineMatrix matrix);


	//************************************
	// Function:  CalcBoundingBox
	// Param[in]: objImage	The input PDF image object.
	// Return:    void
	// Remarks:   Calculates the bounding box.
	// Notes:
	//************************************
	static void	CalcBoundingBox(FPD_PageObject objImage);


	//************************************
	// Function:   GetTransformMatrix
	// Param[in]:  objImage		The input PDF image object.
	// Param[out]: outmatrix	It receives the transformation matrix.
	// Return:     void
	// Remarks:    Gets the transformation matrix.
	// Notes:
	//************************************
	static void GetTransformMatrix(FPD_PageObject objImage, FS_AffineMatrix* outmatrix);


	//************************************
	// Function:  SetTransformMatrix
	// Param[in]: objImage		The input PDF image object.
	// Param[in]: matrix		The transformation matrix.
	// Return:    void
	// Remarks:   Sets the transformation matrix.
	// Notes:
	//************************************
	static void SetTransformMatrix(FPD_PageObject objImage, const FS_AffineMatrix* matrix);


	//************************************
	// Function:  GetImage
	// Param[in]: objImage	The input PDF image object.
	// Return:    The image data object.
	// Remarks:   Gets the image data object.
	// Notes:
	//************************************
	static FPD_Image GetImage(FPD_PageObject objImage);


	//************************************
	// Function:  SetImage
	// Param[in]: objImage		The input PDF image object.
	// Param[in]: image			The input image data object.
	// Return:    void
	// Remarks:   Sets the image data object.
	// Notes:
	//************************************
	static void	SetImage(FPD_PageObject objImage, FPD_Image image);

	
};

//CFPD_ShadingObject_V1
class CFPD_ShadingObject_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty PDF shading object
	// Remarks:   Creates a new empty PDF shading object.
	// Notes:
	//************************************
	static FPD_PageObject New(void);


	//************************************
	// Function:  Destroy
	// Param[in]: objShading The input PDF shading object.
	// Return:    void
	// Remarks:   Destroys the PDF shading object.
	// Notes:
	//************************************
	static void	Destroy(FPD_PageObject objShading);
	
	//************************************
	// Function:  Transform
	// Param[in]: objShading	The input PDF shading object.
	// Param[in]: matrix		The transformation matrix.
	// Return:    void
	// Remarks:   Transforms the path object.
	// Notes:
	//************************************
	static void	Transform(FPD_PageObject objShading, FS_AffineMatrix matrix);


	//************************************
	// Function:  CalcBoundingBox
	// Param[in]: objShading	The input PDF shading object.
	// Return:    void
	// Remarks:   Calculates the bounding box.
	// Notes:
	//************************************
	static void	CalcBoundingBox(FPD_PageObject objShading);


	//************************************
	// Function:   GetTransformMatrix
	// Param[in]:  objShading		The input PDF shading object.
	// Param[out]: outmatrix		It receives the transformation matrix.
	// Return:     void
	// Remarks:    Gets the transformation matrix.
	// Notes:
	//************************************
	static void GetTransformMatrix(FPD_PageObject objShading, FS_AffineMatrix* outmatrix);


	//************************************
	// Function:  SetTransformMatrix
	// Param[in]: objShading	The input PDF shading object.
	// Param[in]: matrix		The transformation matrix.
	// Return:    void
	// Remarks:   Sets the transformation matrix.
	// Notes:
	//************************************
	static void SetTransformMatrix(FPD_PageObject objShading, const FS_AffineMatrix* matrix);


	//************************************
	// Function:  GetPage
	// Param[in]: objShading	The input PDF shading object.
	// Return:    The page.
	// Remarks:   Gets the page.
	// Notes:
	//************************************
	static FPD_Page	GetPage(FPD_PageObject objShading);


	//************************************
	// Function:  SetPage
	// Param[in]: objShading	The input PDF shading object.
	// Param[in]: page			The input page.
	// Return:    void
	// Remarks:   Sets the page.
	// Notes:
	//************************************
	static void	SetPage(FPD_PageObject objShading, FPD_Page page);


	//************************************
	// Function:  GetShadingPattern
	// Param[in]: objShading	The input PDF shading object.
	// Return:    void
	// Remarks:   Gets the shading pattern.
	// Notes:
	//************************************
	static FPD_ShadingPattern GetShadingPattern(FPD_PageObject objShading);


	//************************************
	// Function:  SetShadingPattern
	// Param[in]: objShading	The input PDF shading object.
	// Param[in]: pattern		The input shading pattern.
	// Return:    void
	// Remarks:   Sets the shading pattern.
	// Notes:
	//************************************
	static void	SetShadingPattern(FPD_PageObject objShading, FPD_ShadingPattern pattern);
};

//CFPD_FormObject_V1
class CFPD_FormObject_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty PDF form object.
	// Remarks:   Creates a new empty PDF form object.
	// Notes:
	//************************************
	static FPD_PageObject New(void);


	//************************************
	// Function:  Destroy
	// Param[in]: objForm The input PDF form object.
	// Return:    void
	// Remarks:   Destroys the PDF form object.
	// Notes:
	//************************************
	static void	Destroy(FPD_PageObject objForm);

	//************************************
	// Function:  Transform
	// Param[in]: objForm		The input PDF form object.
	// Param[in]: matrix		The transformation matrix.
	// Return:    void
	// Remarks:   Transforms the path object.
	// Notes:
	//************************************
	static void	Transform(FPD_PageObject objForm, FS_AffineMatrix matrix);


	//************************************
	// Function:  CalcBoundingBox
	// Param[in]: objForm	The input PDF form object.
	// Return:    void
	// Remarks:   Calculates the bounding box.
	// Notes:
	//************************************
	static void	CalcBoundingBox(FPD_PageObject objForm);


	//************************************
	// Function:   GetTransformMatrix
	// Param[in]:  objForm			The input PDF form object.
	// Param[out]: outmatrix		It receives the transformation matrix.
	// Return:     void
	// Remarks:    Gets the transformation matrix.
	// Notes:
	//************************************
	static void GetTransformMatrix(FPD_PageObject objForm, FS_AffineMatrix* outmatrix);


	//************************************
	// Function:  SetTransformMatrix
	// Param[in]: objForm		The input PDF form object.
	// Param[in]: matrix		The transformation matrix.
	// Return:    void
	// Remarks:   Sets the transformation matrix.
	// Notes:
	//************************************
	static void SetTransformMatrix(FPD_PageObject objForm, const FS_AffineMatrix* matrix);


	//************************************
	// Function:  GetForm
	// Param[in]: objForm	The input PDF form object.
	// Return:    The form.
	// Remarks:   Gets the form.
	// Notes:
	//************************************
	static FPD_Form	GetForm(FPD_PageObject objForm);


	//************************************
	// Function:  SetForm
	// Param[in]: objForm		The input PDF form object.
	// Param[in]: form			The input form.
	// Return:    void
	// Remarks:   Sets the form.
	// Notes:
	//************************************
	static void	SetForm(FPD_PageObject objForm, FPD_Form form);
};

//CFPD_InlineImages_V1
class CFPD_InlineImages_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty PDF inline images object.
	// Remarks:   Creates a new empty PDF inline images object.
	// Notes:
	//************************************
	static FPD_PageObject New(void);


	//************************************
	// Function:  Destroy
	// Param[in]: objInlineImgs The input PDF inline images object.
	// Return:    void
	// Remarks:   Destroys the PDF inline images object.
	// Notes:
	//************************************
	static void	Destroy(FPD_PageObject objInlineImgs);

	//************************************
	// Function:  AddMatrix
	// Param[in]: objInlineImgs			The input PDF inline images object.
	// Param[in]: matrix				The input transform matrix.
	// Return:    void
	// Remarks:   Adds a transform matrix.
	// Notes:
	//************************************
	static void	AddMatrix(FPD_PageObject objInlineImgs, const FS_AffineMatrix* matrix);


	//************************************
	// Function:  CountMatrix
	// Param[in]: objInlineImgs	The input PDF inline images object.
	// Return:    The number of transform matrix in this object.
	// Remarks:   Counts the number of transform matrix in this object.
	// Notes:
	//************************************
	static int	CountMatrix(FPD_PageObject objInlineImgs);


	//************************************
	// Function:  GetMatrix
	// Param[in]: objInlineImgs		The input PDF inline images object.
	// Param[in]: index				The index of transform matrix.
	// Return:    The transform matrix from object by index.
	// Remarks:   Gets a transform matrix from object by index.
	// Notes:
	//************************************
	static FS_AffineMatrix	GetMatrix(FPD_PageObject objInlineImgs, FS_INT32 index);


	//************************************
	// Function:  GetStream
	// Param[in]: objInlineImgs	The input PDF inline images object.
	// Return:    The stream.
	// Remarks:   Gets the stream.
	// Notes:
	//************************************
	static FPD_Object GetStream(FPD_PageObject objInlineImgs);

	//************************************
	// Function:  SetStream
	// Param[in]: objInlineImgs			The input PDF inline images object.
	// Param[in]: stream				The input stream
	// Return:    void
	// Remarks:   Sets the stream
	// Notes:
	//************************************
	static void	SetStream(FPD_PageObject objInlineImgs, FPD_Object stream);

	//************************************
	// Function:  GetDIBitmap
	// Param[in]: objInlineImgs			The input PDF inline images object.
	// Return:    FS_DIBitmap
	// Remarks:   Get the bitmap.
	// Notes:
	//************************************
	static FS_DIBitmap	GetDIBitmap(FPD_PageObject objInlineImgs);
};

//content mark

/** @brief PDF content mark item class. */
class CFPD_ContentMarkItem_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty PDF content mark item object.
	// Remarks:   Creates a new empty PDF content mark item object.
	// Notes:
	//************************************
	static FPD_ContentMarkItem New(void);


	//************************************
	// Function:  Destroy
	// Param[in]: item The input PDF content mark item object.
	// Return:    void
	// Remarks:   Destroys the PDF content mark item object.
	// Notes:
	//************************************
	static void	Destroy(FPD_ContentMarkItem item);

	//************************************
	// Function:  GetName
	// Param[in]: item     The input PDF content mark item object.
	// Param[out]: outName Get the name(tag) of the content mark item.
	// Return:    FS_BOOL  TRUE get name success.
	// Remarks:   Gets the name(tag) of the content mark item.
	// Notes:
	//************************************
	static FS_BOOL GetName(FPD_ContentMarkItem item, FS_ByteString* outName);


	//************************************
	// Function:  GetParamType
	// Param[in]: item	The input PDF content mark item object.
	// Return:    The parameter type of the content mark item.
	// Remarks:   Gets the parameter type of the content mark item.
	// Notes:
	//************************************
	static FPD_MarkItemParamType GetParamType(FPD_ContentMarkItem item);


	//************************************
	// Function:  GetParam
	// Param[in]: item	The input PDF content mark item object.
	// Return:    The parameter of the content mark item.
	// Remarks:   Gets the parameter of the content mark item.
	// Notes:
	//************************************
	static void* GetParam(FPD_ContentMarkItem item);


	//************************************
	// Function:  SetName
	// Param[in]: item			The input PDF content mark item object.
	// Param[in]: csName		The input new name(tag).
	// Return:    void
	// Remarks:   Sets the name(tag) of the content mark item.
	// Notes:
	//************************************
	static void	SetName(FPD_ContentMarkItem item, FS_LPCSTR csName);

	//************************************
	// Function:  SetParam
	// Param[in]: item			The input PDF content mark item object.
	// Param[in]: type			The input new parameter type.
	// Param[in]: param			The input new parameter.
	// Return:    void
	// Remarks:   Sets the parameter of the content mark item.
	// Notes:
	//************************************
	static void	SetParam(FPD_ContentMarkItem item, FPD_MarkItemParamType type, void* param);

	//************************************
	// Function:  HasMCID
	// Param[in]: item			The input PDF content mark item object.	
	// Return:    FS_BOOLEAN	true: Has MCID entry. 
	// Remarks:   Has MCID entry. 
	// Notes:
	//************************************
	static FS_BOOLEAN		HasMCID(FPD_ContentMarkItem item);
};

/** @brief PDF content mark class. */
class CFPD_ContentMark_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty FPD_ContentMark object, it can get content mark object by it.
	// Remarks:   Creates a new empty agent internal object.
	// Notes:
	//************************************
	static FPD_ContentMark	New(void);


	//************************************
	// Function:  Destroy
	// Param[in]: mark   The input FPD_ContentMark object.
	// Return:    void
	// Remarks:   Destroys the agent internal object.
	// Notes:
	//************************************
	static void	Destroy(FPD_ContentMark mark);

	
	//************************************
	// Function:  GetMCID
	// Param[in]: mark The input FPD_ContentMark object.
	// Return:    The marked-content identifier.
	// Remarks:   Gets the marked-content identifier.
	// Notes:
	//************************************
	static FS_INT32 GetMCID(FPD_ContentMark mark);


	//************************************
	// Function:  HasMark
	// Param[in]: mark		The input FPD_ContentMark object.
	// Param[in]: tag		The name(tag) of the content mark item.
	// Return:    Non-zero means it has, otherwise it has not.
	// Remarks:   Checks whether the content mark has a specified content mark item.
	// Notes:
	//************************************
	static FS_BOOL HasMark(FPD_ContentMark mark, FS_LPCSTR tag);


	//************************************
	// Function:   LookupMark
	// Param[in]:  mark		The input FPD_ContentMark object.
	// Param[in]:  tag		The name(tag) of the content mark item.
	// Param[out]: outDict  It receives the parameter(attributes) dictionary.
	// Return:    Non-zero means found one, otherwise found none.
	// Remarks:   Lookups a content mark item.
	// Notes:
	//************************************
	static FS_BOOL LookupMark(FPD_ContentMark mark, FS_LPCSTR tag, FPD_Object* outDict);

	//************************************
	// Function:  CountItems
	// Param[in]: mark	The input FPD_ContentMark object.
	// Return:    The number of content mark data in this object.
	// Remarks:   Counts the number of content mark data in this object.
	// Notes:
	//************************************
	static FS_INT32 CountItems(FPD_ContentMark mark);


	//************************************
	// Function:  GetItem
	// Param[in]: mark		The input FPD_ContentMark object.
	// Param[in]: index		The zero-based content mark item index in the content mark data.
	// Return:    A content mark item.
	// Remarks:   Gets the content mark item by index.
	// Notes:
	//************************************
	static FPD_ContentMarkItem GetItem(FPD_ContentMark mark, FS_INT32 index);

	//************************************
	// Function:  AddMark
	// Param[in]: mark		The input FPD_ContentMark object.
	// Param[in]: tag		The input name(tag) of the content mark item.
	// Param[in]: dict		The parameter(attributes) dictionary of the content mark item.
	// Param[in]: bDictNeedClone	Whether the input dictionary must be copied or not.
	// Return:    void
	// Remarks:   Adds a content mark item.
	// Notes:
	//************************************
	static void AddMark(FPD_ContentMark mark, FS_LPCSTR tag, FPD_Object dict, FS_BOOL bDictNeedClone);

	//************************************
	// Function:  DeleteMark
	// Param[in]: mark		The input FPD_ContentMark object.
	// Param[in]: tag		The name(tag) of the content mark item.
	// Return:    void
	// Remarks:   Deletes a content mark item.
	// Notes:
	//************************************
	static void DeleteMark(FPD_ContentMark mark, FS_LPCSTR tag);

	//************************************
	// Function:  DeleteLastMark
	// Param[in]: mark		The input FPD_ContentMark object.
	// Return:    void
	// Remarks:   Deletes the last content mark item.
	// Notes:
	//************************************
	static void DeleteLastMark(FPD_ContentMark mark);

	//************************************
	// Function:  IsNull
	// Param[in]: mark		The input FPD_ContentMark object.
	// Return:    Non-zero means <a>NULL</a>, otherwise not <a>NULL</a>.
	// Remarks:   Tests whether the content mark object is <a>NULL</a> or not.
	// Notes:
	//************************************
	static FS_BOOL IsNull(FPD_ContentMark mark);

	//************************************
	// Function:  Copy
	// Param[in]: mark				The input FPD_ContentMark object.
	// Param[in]: pSrcContentMark	The input PDF content mark object to be copied.
	// Return:    void.
	// Remarks:   Copies the source content mark to the specified one.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.3.1
	//************************************
	static void Copy(FPD_ContentMark mark, FPD_ContentMark pSrcContentMark);

	//************************************
	// Function:  GetMCID
	// Param[in]: mark  The input FPD_ContentMark object.
	// Return: FS_INT32   The marked-content identifier.
	// Remarks:   Gets the marked-content identifier.
	// Notes:
	//************************************
	static FS_INT32 GetContentMarkDataMCID(FPD_ContentMark mark);

	//************************************
	// Function:  CheckContentMarkDataIsNULL
	// Param[in]: mark    The input FPD_ContentMark object.
	// Return:    FS_BOOL    TRUE: ContentMarkData is NULL.
	// Remarks:   Check the ContentMarkData.
	// Notes:
	//************************************	
	static FS_BOOLEAN CheckContentMarkDataIsNULL(FPD_ContentMark mark);

	//************************************
	// Function:  GetItem2
	// Param[in]: mark		The input FPD_ContentMark object.
	// Param[in]: index		The zero-based content mark item index in the content mark data.
	// Param[out]: ref		Gets the content mark item ref by index..
	// Return:    A content mark item ref.
	// Remarks:   Gets the content mark item ref by index.
	// Notes:
	//************************************
	static void GetItem2(FPD_ContentMark mark, FS_INT32 index, FPD_ContentMarkItemRef* ref);

	//************************************
	// Function:  AddMark2
	// Param[in]: mark		The input FPD_ContentMark object.
	// Param[in]: itemRef	The input content mark item ref.
	// Return:    void
	// Remarks:   Add a content mark item.
	// Notes:
	//************************************
	static void	AddMark2(FPD_ContentMark mark, FPD_ContentMarkItemRef itemRef);
	
	//************************************
	// Function:  GetItems
	// Param[in]: mark		The input FPD_ContentMark object.
	// Param[out]: outItems	Get content mark items.
	// Return:    FS_BOOL   TRUE: Get itmes success.
	// Remarks:   Get content mark items.
	// Notes:
	//************************************
	static FS_BOOL GetItems(FPD_ContentMark mark, FS_PtrArray* outItems);

	//************************************
	// Function:  GetModify
	// Param[in]: mark		The input FPD_ContentMark object.
	// Return:    void.
	// Remarks:	  Get a modifiable copy of the object. If the reference was refer to null, 
	// then a new object will be created. The returned pointer can be used to alter the object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void GetModify(FPD_ContentMark mark);

	//************************************
	// Function:  DoObjectNew
	// Param[in]: mark		The input FPD_ContentMark object.
	// Return:    void.
	// Remarks:	  Create a new object and refer to it. 
	// The returned pointer to the object can be used to modify the content of objects.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	//************************************
	static void DoObjectNew(FPD_ContentMark mark);

	//************************************
	// Function:  IsEqual
	// Param[in]: mark		The input FPD_ContentMark object.
	// Param[in]: markMatch	The input agent internal object need to compare.
	// Return:    FS_BOOLEAN.
	// Remarks:	  Compare with another object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	//************************************
	static FS_BOOLEAN IsEqual(FPD_ContentMark mark, FPD_ContentMark mark2);

	//************************************
	// Function:  Copy2
	// Param[in]: mark		The input FPD_ContentMark object.
	// Return:    FPD_ContentMark.
	// Remarks:	 Copy a FPD_ContentMark.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	//************************************
	static FPD_ContentMark Copy2(FPD_ContentMark mark);

	//************************************
	// Function:  GetItem3
	// Param[in]: mark		The input FPD_ContentMark object.
	// Param[in]: index		The zero-based content mark item index in the content mark data.
	// Param[in]: bModify	If need modify the object.
	// Return:    A content mark item.
	// Remarks:   Gets the content mark item by index.
	// Notes:
	//************************************
	static FPD_ContentMarkItem GetItem3(FPD_ContentMark mark, FS_INT32 index, FS_BOOL bModify);

	//************************************
	// Function:  RemoveItem
	// Param[in]: mark		The input FPD_ContentMark object.
	// Param[in]: index		The zero-based content mark item index in the content mark data.
	// Return:    void
	// Remarks:   Remove item with specified index.
	// Notes:
	//************************************
	static void RemoveItem(FPD_ContentMark mark, FS_INT32 index);

	//************************************
	// Function:  RemoveAllItems
	// Param[in]: mark		The input FPD_ContentMark object.	
	// Return:    void
	// Remarks:   Remove all items.
	// Notes:
	//************************************
	static void RemoveAllItems(FPD_ContentMark mark);
};

class CFPD_ContentMarkItemRef_V16
{
public:
	//************************************
	// Function:  GetContentMarkItemObject
	// Param[in]: itemRef		The input FPD_ContentMarkItemRef. 
	// Return:    FPD_ContentMarkItem  
	// Remarks:   Get it's count object FPD_ContentMarkItem.
	// Notes: 
	//************************************
	static FPD_ContentMarkItem GetContentMarkItemObject(FPD_ContentMarkItemRef itemRef);

	//************************************
	// Function:  New
	// Param[in]: itemRef		The input FPD_ContentMarkItemRef. 
	// Return:    void
	// Remarks:   Create a new FPD_ContentMarkItem object and refer to it.
	// Notes: 
	//************************************
	static void New(FPD_ContentMarkItemRef itemRef);

	//************************************
	// Function:  GetModify
	// Param[in]: itemRef		The input FPD_ContentMarkItemRef. 
	// Return:    void
	// Remarks:   Get a modifiable copy of the FPD_ContentMarkItem.
	// Notes: 
	//************************************
	static void GetModify(FPD_ContentMarkItemRef itemRef);

	//************************************
	// Function:  Create
	// Param[in]: itemRef		The input FPD_ContentMarkItemRef. 
	// Return:    FPD_ContentMarkItemRef
	// Remarks:   Get a modifiable copy of the FPD_ContentMarkItem.
	// Notes: 
	//************************************
	static FPD_ContentMarkItemRef Create();

	//************************************
	// Function:  Delete
	// Param[in]: ref		The input FPD_ContentMarkItemRef. 
	// Return:    void
	// Remarks:  Delete the FPD_ContentMarkItemRef.
	// Notes: 
	//************************************
	static void Delete(FPD_ContentMarkItemRef ref);

	//************************************
	// Function:  Copy
	// Param[in]: ref		The input FPD_ContentMarkItemRef. 
	// Return:    FPD_ContentMarkItemRef
	// Remarks:  Copy a FPD_ContentMarkItemRef.
	// Notes: 
	//************************************
	static FPD_ContentMarkItemRef Copy(FPD_ContentMarkItemRef ref);
};

class CFPD_PathData_V17
{
public:
	//************************************
	// Function:  New	
	// Return:    FPD_PathData
	// Remarks:  Construct an empty path data.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_PathData New();

	//************************************
	// Function:  New2
	// Param[in]: src		The input FPD_PathData. 
	// Return:    FPD_PathData
	// Remarks:  Copy constructor.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_PathData New2(FPD_PathData src);

	//************************************
	// Function:  Destroty
	// Param[in]: pathdata		The input FPD_PathData. 
	// Return:    void
	// Remarks:  Destroy FPD_PathData.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void Destroty(FPD_PathData pathdata);

	//************************************
	// Function:  GetPointCount
	// Param[in]: pathdata		The input FPD_PathData. 
	// Return:    FS_INT32
	// Remarks:  Get the point count int the path data.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_INT32	 GetPointCount(FPD_PathData pathdata);

	//************************************
	// Function:  GetFlag
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: index   		Specifies the zero-based index of path point in the path data.
	// Return:    FS_INT32      The flag of specified path point.
	// Remarks:  Get the flag of specified path point.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_INT32	 GetFlag(FPD_PathData pathdata, FS_INT32 index);

	//************************************
	// Function:  GetPointX
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: index   		Specifies the zero-based index of path point in the path data.
	// Return:    FS_FLOAT      The x-coordinate of specified path point.
	// Remarks:  Get the x-coordinate of specified path point.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_FLOAT	 GetPointX(FPD_PathData pathdata, FS_INT32 index);

	//************************************
	// Function:  GetPointY
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: index   		Specifies the zero-based index of path point in the path data.
	// Return:    FS_FLOAT      The y-coordinate of specified path point.
	// Remarks:  Get the y-coordinate of specified path point.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_FLOAT	 GetPointY(FPD_PathData pathdata, FS_INT32 index);

	//************************************
	// Function:  GetPoint
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: index   		The point index in the points array.
	// Return:    FS_PATHPOINT  The path point in the path points array by the index.
	// Remarks:  Gets the path point in the path points array by the index.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_PATHPOINT		GetPoint(FPD_PathData pathdata, FS_INT32 index);

	//************************************
	// Function:  SetPointCount
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: nPoints   	The new count of path point to change.
	// Return:    FS_BOOLEAN    
	// Remarks:  Change the path point count and prepare adequate allocated buffer.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN		SetPointCount(FPD_PathData pathdata, FS_INT32 nPoints);

	//************************************
	// Function:  AllocPointCount
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: nPoints   	The new count of path point to to allocated.
	// Return:    FS_BOOLEAN    
	// Remarks:  Allocate enough point buffer without change number of current points.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN		AllocPointCount(FPD_PathData pathdata, FS_INT32 nPoints);

	//************************************
	// Function:  AddPointCount
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: addPoints   	The count of path point to add.
	// Return:    FS_BOOLEAN    
	// Remarks:  Add number of path point to the path data and prepare adequate allocated buffer.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN		AddPointCount(FPD_PathData pathdata, FS_INT32 addPoints);

	//************************************
	// Function:  GetBoundingBox
	// Param[in]: pathdata		The input FPD_PathData. 
	// Return:    FS_FloatRect    
	// Remarks: Get the bounding box. Ignoring line thickness.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_FloatRect		GetBoundingBox(FPD_PathData pathdata);

	//************************************
	// Function:  GetBoundingBox2
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: line_width	The line width used in stroking.
	// Param[in]: miter_limit	The miter limit value for line joint in stroking.
	// Return:    FS_FloatRect    
	// Remarks: Get the bounding box, respecting line thickness. all points in the stroked path must be in the bounding box.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_FloatRect		GetBoundingBox2(FPD_PathData pathdata, FS_FLOAT line_width, FS_FLOAT miter_limit);

	//************************************
	// Function:  Transform
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: pMatrix	    The specified matrix.
	// Return:    void    
	// Remarks: Transform all path point in the path data using specified matrix.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void				Transform(FPD_PathData pathdata, FS_AffineMatrix pMatrix);

	//************************************
	// Function:  Append
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: pSrc	        The source path data.
	// Param[in]: pMatrix	    The specified matrix. NULL means no transformation.
	// Return:    FS_BOOLEAN    
	// Remarks: Append a path data. Optionally a matrix can be specified to transform the source path data before appending. 
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN		Append(FPD_PathData pathdata, const FPD_PathData pSrc, const FS_AffineMatrix* pMatrix);

	//************************************
	// Function:  AppendRect
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: left	        The x-coordinate of the left-bottom corner.
	// Param[in]: bottom	    The y-coordinate of the left-bottom corner.
	// Param[in]: right	        The x-coordinate of the right-top corner.
	// Param[in]: top	        The y-coordinate of the right-top corner.
	// Return:    FS_BOOLEAN    
	// Remarks: Append a rectangle.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN		AppendRect(FPD_PathData pathdata, FS_FLOAT left, FS_FLOAT bottom, FS_FLOAT right, FS_FLOAT top);

	//************************************
	// Function:  SetPoint
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: index	        Specifies the zero-based index of path point in the path data.
	// Param[in]: x	            The x-coordinate of the point to set.
	// Param[in]: y	            The y-coordinate of the point to set.
	// Param[in]: flag	        The flag of the point to set.
	// Return:    void    
	// Remarks: Set the point data for specified path point.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void				SetPoint(FPD_PathData pathdata, FS_INT32 index, FS_FLOAT x, FS_FLOAT y, FS_INT32 flag);

	//************************************
	// Function:  TrimPoints
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: nPoints	    The new count of path point to trim to.
	// Return:    void    
	// Remarks: Trim the number of path point in the path data to specified number.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void				TrimPoints(FPD_PathData pathdata, FS_INT32 nPoints);

	//************************************
	// Function:  Copy
	// Param[in]: pathdata		The input FPD_PathData. 
	// Param[in]: src	        The source path data.
	// Return:    FS_BOOLEAN    
	// Remarks: Copy path data from another instance.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN		Copy(FPD_PathData pathdata, const FPD_PathData src);

	//************************************
	// Function:  IsRect
	// Param[in]: pathdata		The input FPD_PathData. 
	// Return:    FS_BOOLEAN    
	// Remarks: Copy path data from another instance.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN		IsRect(FPD_PathData pathdata);
};

#ifdef __cplusplus
};
#endif//__cplusplus

#endif//FPD_PAGEOBJIMPL_H

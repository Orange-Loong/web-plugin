/** @file fr_basic.h.
 * 
 *  @brief defined data types.
 */

#ifndef FS_BASICIMPL_H
#define FS_BASICIMPL_H

#ifndef FS_INTERNALINC_H
#include "../fs_internalInc.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

class CFS_ExtensionHFTMgr_V1
{
public:

	//************************************
	// Function:  NewHFT
	// Param[in]: numOfIntefaces	The capacity of this new function table. 	
	// Return:    A new function table.
	// Remarks:   Creates a new function table which can be filled with several functions.
	// Notes:
	// See: FSExtensionHFTMgrAddHFT
	// See: FSExtensionHFTMgrGetHFT
	//************************************
	static FS_HFT	NewHFT(FS_INT32 numOfIntefaces);

	//************************************
	// Function:  AddHFT
	// Param[in]: hftName		The name of function table, used to identify it.
	// Param[in]: version		Version of this function table.
	// Param[in]: hft			The instance to be added.
	// Return:    If success, return <a>ERR_ADDHFT_NAMEEXIST</a>(1), else(hft not exist) return <a>ERR_ADDHFT_UNKNOWN</a>(0).
	// Remarks:   Adds a new function table.
	// Notes:
	// See: FSExtensionHFTMgrNewHFT
	//************************************
	static FS_INT32		AddHFT(const FS_CHAR* hftName, FS_INT32 version, FS_HFT hft);

	//************************************
	// Function:  GetHFT
	// Param[in]: hftName		The name of function table, used to identify it.
	// Param[in]: version		Version of this function table.
	// Return:    If exists, returns the instance, else returns <a>NULL</a>.
	// Remarks:   Gets the function table.
	// Notes:
	// See: FSExtensionHFTMgrReplaceEntry
	//************************************
	static FS_HFT	GetHFT(const FS_CHAR* hftName, FS_INT32 version);

	//************************************
	// Function:  ReplaceEntry
	// Param[in]: hft			The function table which contains the entry to be replaced.	
	// Param[in]: iSel			The index of entry to be replaced.
	// Param[in]: newEntry		The new entry to replaced.
	// Return:    
	// Remarks:   Replaces the entry by specified selector.
	// Notes:
	// See: FSExtensionHFTMgrGetEntry
	//************************************
	static void		ReplaceEntry(FS_HFT hft, FS_INT32 iSel, void* newEntry);

	//************************************
	// Function:  GetEntry
	// Param[in]: hft		The function table which contains several entries.
	// Param[in]: iSel		The index of entry to be found.
	// Return:    If entry exists, returns the instance, else returns <a>NULL</a>.
	// Remarks:   Gets the entry by specified selector.
	// Notes:
	// See: FSExtensionHFTMgrReplaceEntry
	//************************************
	static void*	GetEntry(FS_HFT hft, FS_INT32 iSel);

	//************************************
	// Function:  GetHFT2
	// Param[in]: hftName		The name of function table, used to identify it.
	// Param[in]: version		Version of this function table.
	// Param[in]: pluginname	The plugin name need to be load.
	// Return:    If exists, returns the instance, else returns <a>NULL</a>.
	// Remarks:   Gets the function table.
	// Notes:
	// See: FSExtensionHFTMgrReplaceEntry
	//************************************
	static FS_HFT	GetHFT2(const FS_CHAR* hftName, FS_INT32 version, FS_LPCWSTR pluginname);
};


class CFS_AffineMatrix_V1
{
public:

	//************************************
	// Function:  IsScaled
	// Param[in]: matrix The input matrix.
	// Return:    <a>TRUE</a> for this matrix having scaling (or translating) only, no rotating. Otherwise not.
	// Remarks:   Whether this matrix has scaling (or translating) only. No rotating.
	// Notes: 
	// See: FSAffineMatrixScale
	//************************************
	static FS_BOOL IsScaled(FS_AffineMatrix matrix);


	//************************************
	// Function:  Is90Rotated
	// Param[in]: matrix The input matrix.
	// Return:    <a>TRUE</a> for this matrix having rotating, otherwise not.
	// Remarks:   Whether this matrix has rotating of 90, or -90 degrees.
	// Notes:
	//************************************
	static FS_BOOL Is90Rotated(FS_AffineMatrix matrix);


	//************************************
	// Function:  GetReverse 
	// Param[in]: src The input matrix.
	// Return:    The inverse matrix base on a source matrix.
	// Remarks:   Gets the inverse matrix base on a source matrix.
	// Notes:
	//************************************
	static FS_AffineMatrix GetReverse(FS_AffineMatrix src);


	//************************************
	// Function:   TransformPoint
	// Param[in]:  matrix The input matrix.
	// Param[in]:  x	 The input x-coordinate of the point
	// Param[in]:  y	 The input y-coordinate of the point.
	// Param[out]: outX  It receives the output transformed x-coordinate.
	// Param[out]: outY  It receives the output transformed y-coordinate.
	// Return:     void
	// Remarks:    Transforms a point.
	// Notes:
	// See: FSAffineMatrixTransformRect
	// See: FSAffineMatrixTransformDistance
	//************************************
	static void TransformPoint(FS_AffineMatrix matrix, FS_FLOAT x, FS_FLOAT y, FS_FLOAT* outX, FS_FLOAT* outY);


	//************************************
	// Function:  TransformRect
	// Param[in]: matrix The input matrix.
	// Param[in]: rc	 Rectangle to transform.
	// Return:    The result rectangle.
	// Remarks:   Transforms a rectangle and return a bounding rectangle. </Brief> The result rectangle is always normalized.
	// Notes:
	// See: FSAffineMatrixTransformPoint
	// See: FSAffineMatrixTransformDistance
	//************************************
	static FS_FloatRect TransformRect(FS_AffineMatrix matrix, FS_FloatRect rc);

	//************************************
	// Function:  Concat
	// Param[in]: matrix    The input matrix.
	// Param[in]: src		The input matrix.
	// Return:    The result matrix.
	// Remarks:   Concatenates with another matrix.
	// Notes:
	// See: FSAffineMatrixConcatInverse
	//************************************
	static FS_AffineMatrix Concat(FS_AffineMatrix matrix, FS_AffineMatrix src);

	//************************************
	// Function:  Translate
	// Param[in]: matrix The input matrix.
	// Param[in]: x		 The x-direction delta value.
	// Param[in]: y		 The y-direction delta value.
	// Return:    The result matrix.
	// Remarks:   Translates the matrix.
	// Notes:
	// See: FSAffineMatrixTranslateI
	//************************************
	static FS_AffineMatrix	Translate(FS_AffineMatrix matrix, FS_FLOAT x, FS_FLOAT y);

	//************************************
	// Function:  TranslateI
	// Param[in]: matrix The input matrix.
	// Param[in]: x		 The x-direction delta integer value.
	// Param[in]: y		 The y-direction delta integer value.
	// Return:    The result matrix.
	// Remarks:   Translates the matrix using integer value.
	// Notes:
	// See: FSAffineMatrixTranslate
	//************************************
	static FS_AffineMatrix	TranslateI(FS_AffineMatrix matrix, FS_INT32 x, FS_INT32 y);

	//************************************
	// Function:  Scale
	// Param[in]: matrix    The input matrix.
	// Param[in]: xScale	The x-direction scale coefficient.
	// Param[in]: yScale	The y-direction scale coefficient.
	// Return:    The result matrix.
	// Remarks:   Scales the matrix.
	// Notes:
	// See: FSAffineMatrixIsScale
	//************************************
	static FS_AffineMatrix	Scale(FS_AffineMatrix matrix, FS_FLOAT xScale, FS_FLOAT yScale);

	//************************************
	// Function:  ConcatInverse
	// Param[in]: matrix The input matrix.
	// Param[in]: src	 The input matrix, to be inversed.
	// Return:    The result of a matrix concatenating another matrix inversed;
	// Remarks:   Concatenates the inverse of another matrix.
	// Notes:
	// See: FSAffineMatrixConcat
	//************************************
	static FS_AffineMatrix	ConcatInverse(FS_AffineMatrix matrix, FS_AffineMatrix src);

	//************************************
	// Function:  MatchRect
	// Param[in]: dest	 The dest rectangle
	// Param[in]: src	 The source rectangle.
	// Return:    The matrix that transforms a source rectangle to dest rectangle.
	// Remarks:   Gets a matrix that transforms a source rectangle to dest rectangle.
	// Notes:
	// See: FSAffineMatrix
	//************************************
	static FS_AffineMatrix	MatchRect(FS_FloatRect dest, FS_FloatRect src);

	//************************************
	// Function:  GetUnitRect
	// Param[in]: matrix The input matrix.
	// Return:    The unit rectangle.
	// Remarks:   Gets a bounding rectangle of the parallelogram composing two unit vectors.
	// Notes:  
	// See: FSAffineMatrixGetUnitArea
	//************************************
	static FS_FloatRect GetUnitRect(FS_AffineMatrix matrix);

	//************************************
	// Function:  GetUnitArea
	// Param[in]: matrix The input matrix.
	// Return:    The unit area
	// Remarks:   Gets area of the parallelogram composing two unit vectors.
	// Notes:
	// See: FSAffineMatrixGetUnitRect
	//************************************
	static FS_FLOAT GetUnitArea(FS_AffineMatrix matrix);

	//************************************
	// Function:  GetXUnit
	// Param[in]: matrix The input matrix.
	// Return:    The x-direction unit size.
	// Remarks:   Gets the x-direction unit size.
	// Notes:
	// See: FSAffineMatrixGetYUnit
	//************************************
	static FS_FLOAT GetXUnit(FS_AffineMatrix matrix);


	//************************************
	// Function:  GetYUnit	
	// Param[in]: matrix The input matrix.
	// Return:    The y-direction unit size.
	// Remarks:   Gets the y-direction unit size.
	// Notes:
	// See: FSAffineMatrixGetXUnit
	//************************************
	static FS_FLOAT GetYUnit(FS_AffineMatrix matrix);


	//************************************
	// Function:  TransformDistance
	// Param[in]: matrix        The input matrix.
	// Param[in]: distance		The input distance.
	// Return:    The transformed distance.
	// Remarks:   Transforms a distance.
	// Notes:
	// See: FSAffineMatrixTransformRect
	// See: FSAffineMatrixTransformPoint
	//************************************
	static FS_FLOAT TransformDistance(FS_AffineMatrix matrix, FS_FLOAT distance);

	//************************************
	// Function:  Rotate
	// Param[in]: matrix        The input matrix.
	// Param[in]: fRadian		Rotation angle in radian.
	// Param[in]: bPrepended	If it's TRUE, a rotation matrix is multiplied at left side, or at right side. Sets it FALSE as default.
	// Return:    The result matrix.
	// Remarks:   Rotates the matrix.
	// Notes:
	//************************************
	static FS_AffineMatrix Rotate(FS_AffineMatrix matrix, FS_FLOAT fRadian, FS_BOOL bPrepended);
	
	 //************************************
	 // Function:  RotateAt
	 // Param[in]: matrix       The input matrix.
	 // Param[in]: fRadian		Rotation angle in radian.
	 // Param[in]: x		    The x coordinate from which to rotate.
	 // Param[in]: y		    The y coordinate from which to rotate.
	 // Param[in]: bPrepended	If it's TRUE, a rotation matrix is multiplied at left side, or at right side. Sets it FALSE as default.
	 // Return:    FS_AffineMatrix.
	 // Remarks:   brief Rotate the matrix at a position.
	 // Notes:
	 //************************************
	static FS_AffineMatrix			RotateAt(FS_AffineMatrix matrix, FS_FLOAT fRadian, FS_FLOAT x, FS_FLOAT y, FS_BOOLEAN bPrepended);
	
	 //************************************
	 // Function:  TransformXDistance
	 // Param[in]: matrix       The input matrix.
	 // Param[in]: dx		    The input x-distance.	
	 // Return:    FS_FLOAT     The transformed distance.
	 // Remarks:  Transform a x-distance.
	 // Notes:
	 //************************************
	static FS_FLOAT		TransformXDistance(FS_AffineMatrix matrix, FS_FLOAT dx);
	
	 //************************************
	 // Function:  TransformXDistance2
	 // Param[in]: matrix       The input matrix.
	 // Param[in]: dx		    The input x-distance.	
	 // Return:    FS_FLOAT     The transformed distance.
	 // Remarks:  Transform a x-distance.
	 // Notes:
	 //************************************
	static FS_INT32		TransformXDistance2(FS_AffineMatrix matrix, FS_INT32 dx);
	
	 //************************************
	 // Function:  TransformYDistance
	 // Param[in]: matrix       The input matrix.
	 // Param[in]: dy		    The input y-distance.	
	 // Return:    FS_FLOAT     The transformed distance.
	 // Remarks:  Transform a y-distance.
	 // Notes:
	 //************************************
	static FS_FLOAT		TransformYDistance(FS_AffineMatrix matrix, FS_FLOAT dy);
	
	 //************************************
	 // Function:  TransformYDistance2
	 // Param[in]: matrix       The input matrix.
	 // Param[in]: dy		    The input y-distance.	
	 // Return:    FS_FLOAT     The transformed distance.
	 // Remarks:  Transform a y-distance.
	 // Notes:
	 //************************************
	static FS_INT32		TransformYDistance2(FS_AffineMatrix matrix, FS_INT32 dy);
	
	//************************************
	// Function:  SetIdentity
	// Param[in/out]: matrix       The input matrix.		
	// Return:    void
	// Remarks: Set the matrix to be an identity transformation matrix.
    // Notes:
	//************************************
	static void			SetIdentity(FS_AffineMatrix* matrix);

	//************************************
	// Function:  Translate2
	// Param[in]: matrix        The input matrix.
	// Param[in]: x		        The x-direction delta value.
	// Param[in]: y		        The y-direction delta value.
	// Param[in]: bPrepended	If this is <b>true</b>, a translation matrix is multiplied at left side, or at right side.
	// Return:    The result matrix.
	// Remarks:   Translates the matrix.
	// Notes:
	// See: FSAffineMatrixTranslateI
	//************************************
	static FS_AffineMatrix	Translate2(FS_AffineMatrix matrix, FS_FLOAT x, FS_FLOAT y, FS_BOOLEAN bPrepended);

	//************************************
	// Function:  Translate3
	// Param[in]: matrix The input matrix.
	// Param[in]: x		 The x-direction delta integer value.
	// Param[in]: y		 The y-direction delta integer value.
	// Param[in]: bPrepended	If this is <b>true</b>, a translation matrix is multiplied at left side, or at right side.
	// Return:    The result matrix.
	// Remarks:   Translates the matrix using integer value.
	// Notes:
	// See: FSAffineMatrixTranslate
	//************************************
	static FS_AffineMatrix	Translate3(FS_AffineMatrix matrix, FS_INT32 x, FS_INT32 y, FS_BOOLEAN bPrepended);

	//************************************
	// Function:  Concat2
	// Param[in]: matrix    The input matrix.
	// Param[in]: src		The input matrix.
	// Param[in]: bPrepended	Whether the input matrix is prepended.
	// Return:    The result matrix.
	// Remarks:   Concatenates with another matrix.
	// Notes:
	// See: FSAffineMatrixConcatInverse
	//************************************
	static FS_AffineMatrix Concat2(FS_AffineMatrix matrix, FS_AffineMatrix src, FS_BOOLEAN bPrepended);
	
	//************************************
	// Function:  TransformPoints
	// Param[in]: matrix           The input matrix.
	// Param[in,out]: points		The input a array of the points, and it receives the output array of the transformed points.
	// Param[in]: iCount	        The input count of the points.
	// Return:    void
	// Remarks:   Transform points.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void	TransformPoints(FS_AffineMatrix matrix, FS_FloatPoint** points, FS_INT32 iCount);
	
	 //************************************
	 // Function:  TransformPoints2
	 // Param[in]: matrix           The input matrix.
	 // Param[in,out]: points		The input a array of the points, and it receives the output array of the transformed points.
	 // Param[in]: iCount	        The input count of the points.
	 // Return:    void
	 // Remarks:   Transform points.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	 //************************************
	static void	TransformPoints2(FS_AffineMatrix matrix, FS_DevicePoint** points, FS_INT32 iCount);
};


class CFS_DIBitmap_V1
{	
public:

	//************************************
	// Function:  New       
	// Return:	  A <a>FS_DIBitmap</a> object.
	// Remarks:   Creates a bitmap. Optionally an external buffer provided by caller can be used. Using
	// <a>FSDIBitmapCreate</a>() to initialize after a bitmap object is created.
	// Notes:     The buffer should be kept by caller during the existence of the bitmap.
	// See: FSDIBitmapClear
	// See: FSDIBitmapCreate
	// See: FSDIBitmapDestroy
	//************************************
	static FS_DIBitmap New(void);

	//************************************
	// Function:  Create  
	// Param[in]: bitmap    The input bitmap.
	// Param[in]: width		The width of the bitmap.
	// Param[in]: height	The height of the bitmap.
	// Param[in]: format	The format of the bitmap.
	// Param[in]: pBuffer	The data buffer of the bitmap.
	// Param[in]: pitch		Specified row pitch in bytes.
	// Return:   FS_BOOLEAN return true for success, false for failure.
	// Remarks:   Actually create the <Italic>DIB</Italic>. Optionally the <Italic>DIB</Italic> can use external buffer provided by caller.
	// Notes:     The buffer should be kept by caller during the existence of the bitmap.
	// See: FSDIBitmapNew
	// See: FSDIBitmapClear
	// See: FSDIBitmapDestroy
	//************************************
	static FS_BOOLEAN	Create(FS_DIBitmap bitmap, FS_INT32 width, FS_INT32 height, FS_DIB_Format format, FS_LPBYTE pBuffer, FS_INT32 pitch);

	//************************************
	// Function:  Destroy
	// Param[in]: bitmap The input bitmap.
	// Return:    void
	// Remarks:   Destroys the bitmap.
	// Notes:
	// See: FSDIBitmapCreate
	// See: FSDIBitmapNew
	//************************************
	static void Destroy(FS_DIBitmap bitmap);
	
	//************************************
	// Function:  GetWidth
	// Param[in]: bitmap The input bitmap.
	// Return:    The width of the bitmap.
	// Remarks:   Gets the width of the bitmap.
	// Notes:
	// See: FSDIBitmapGetHeight
	//************************************
	static FS_INT32 GetWidth(FS_DIBitmap bitmap);


	//************************************
	// Function:  GetHeight
	// Param[in]: bitmap The input bitmap.
	// Return:    The height of the bitmap.
	// Remarks:   Gets the height of the bitmap.
	// Notes:
	// See: FSDIBitmapGetWidth
	//************************************
	static FS_INT32 GetHeight(FS_DIBitmap bitmap);


	//************************************
	// Function:  GetFormat
	// Param[in]: bitmap The input bitmap.
	// Return:    The format of the bitmap.
	// Remarks:   Gets the format of the bitmap.
	// Notes:
	//************************************
	static FS_DIB_Format GetFormat(FS_DIBitmap bitmap);


	//************************************
	// Function:  GetPitch	
	// Param[in]: bitmap The input bitmap.
	// Return:    The row pitch of the bitmap.
	// Remarks:   Gets the specified row pitch of the bitmap.
	// Notes:
	//************************************
	static FS_DWORD GetPitch(FS_DIBitmap bitmap);


	//************************************
	// Function:  GetPalette	
	// Param[in]: bitmap The input bitmap.
	// Return:    The palette of the bitmap.
	// Remarks:   Gets the palette of the bitmap.
	// Notes:
	//************************************
	static FS_ARGB* GetPalette(FS_DIBitmap bitmap);


	//************************************
	// Function:  GetBuffer
	// Param[in]: bitmap The input bitmap.
	// Return:    A buffer for the whole <Italic>DIB</Italic>.
	// Remarks:   Gets a buffer for whole <Italic>DIB</Italic>. Only in-memory DIB can supply such a buffer.
	// Notes:     
	//************************************
	static FS_LPBYTE GetBuffer(FS_DIBitmap bitmap);


	//************************************
	// Function:  GetScanline
	// Param[in]: bitmap    The input bitmap.
	// Param[in]: line		The zero-based line number. [0, height).
	// Return:    A pointer to the scan line.
	// Remarks:   Fetches a single scan line.
	// Notes:
	// See: FSDIBitmapDownSampleScanline
	//************************************
	static FS_LPBYTE GetScanline(FS_DIBitmap bitmap, FS_INT32 line);


	//************************************
	// Function:  DownSampleScanline	
	// Param[in]: bitmap    The input bitmap.
	// Param[in]: line		The zero-based line number.
	// Param[in,out]: destScan  The destination scanline buffer to receive down-sample result.
	// Param[in]: destBpp   The destination bits per pixel.
	// Param[in]: destWidth	The destination width of pixels in the scanline.
	// Param[in]: bFlipX    Whether to flip the bitmap in x-direction. 
	// Param[in]: clipLeft	Clip start of the destination scanline.
	// Param[in]: clipWidth Clip width of the destination scanline.
	// Return:    void
	// Remarks:   Downs sample a scanline, for quick stretching.
	//            </Brief> The down-sampled result would be either 8bpp (for mask and grayscale), 24bpp or 32bpp.
	// Notes:
	// See: FSDIBitmapGetScanline
	//************************************
	static void	DownSampleScanline(
		FS_DIBitmap bitmap, 
		FS_INT32 line,
		FS_LPBYTE destScan,
		FS_INT32 destBpp,
		FS_INT32 destWidth, 
		FS_BOOL bFlipX,
		FS_INT32 clipLeft, 
		FS_INT32 clipWidth
		);

	//************************************
	// Function:  TakeOver	
	// Param[in]: bitmap        The input bitmap.
	// Param[in]: srcBitmap		The input source bitmap.
	// Return:    void
	// Remarks:   Takeovers a bitmap.
	// Notes:     After taking-over, the source bitmap will contain an empty bitmap, and this bitmap will contain all data of the source bitmap.
	//************************************
	static void TakeOver(FS_DIBitmap bitmap, FS_DIBitmap srcBitmap);

	//************************************
	// Function:  ConvertFormat 
	// Param[in]: bitmap    The input bitmap.
	// Param[in]: format	The destination bitmap format.
	// Return:    void
	// Remarks:   Converts a bitmap. All informations in the old bitmap are retained.
	// Notes:     Supported conversion:
	//            <ul>
	//              - <li>1bppMask => 8bppMask;</li>
	//              - <li>1bppRgb => Rgb / Rgb32 / Argb;</li>
	//              - <li>8bppRgb => Rgb / Rgb32 / Argb;</li>
	//              - <li>Rgb / Rgb32 => 8bppRgb;</li>
	//              - <li>Rgb => Rgb32 / Argb;</li>
	//              - <li>Rgb32 => Rgb / Argb</li>
	//             </ul>
	//************************************
	static void ConvertFormat(FS_DIBitmap bitmap, FS_DIB_Format format);

	//************************************
	// Function:  Clear
	// Param[in]: bitmap    The input bitmap.
	// Param[in]: argb		The specified color to fill.
	// Return:    void
	// Remarks:   Fills the whole bitmap with specified color. For alpha mask bitmaps, only the alpha value is taken.
	// Notes:
	//************************************
	static void Clear(FS_DIBitmap bitmap, FS_ARGB argb);

	//************************************
	// Function:  GetPixel
	// Param[in]: bitmap The input bitmap.
	// Param[in]: x		 The x-coordinate in bitmap.
	// Param[in]: y		 The y-coordinate in bitmap.
	// Return:    The pixel ARGB value.
	// Remarks:   Gets pixel ARGB value.
	// Notes:     For alpha mask bitmaps, only the alpha value of returned value is valid.
	// See: FSDIBitmapSetPixel
	//************************************
	static FS_DWORD GetPixel(FS_DIBitmap bitmap, FS_INT32 x, FS_INT32 y);

	//************************************
	// Function:  SetPixel	
	// Param[in]: bitmap The input bitmap.
	// Param[in]: x		 The x-coordinate in bitmap.
	// Param[in]: y		 The y-coordinate in bitmap.
	// Param[in]: argb	 The input pixel ARGB value.
	// Return:    void
	// Remarks:   Sets pixel ARGB value.
	// Notes:     For alpha mask bitmaps, only the alpha value is taken.
	// See: FSDIBitmapGetPixel
	//************************************
	static void SetPixel(FS_DIBitmap bitmap, FS_INT32 x, FS_INT32 y, FS_ARGB argb);

	//************************************
	// Function:  LoadChannel
	// Param[in]: bitmap      The input bitmap.
	// Param[in]: destChannel The destination channel.
	// Param[in]: srcBitmap   The DIB source.
	// Param[in]: srcChannel  The source channel.
	// Return:    void
	// Remarks:   Loads a full channel from a source bitmap to this bitmap.
	//            </Brief>The source bitmap can be any format, but must have specified source channel.
	// Notes:     If the destination channel is a color channel (R/G/B), then the this bitmap must be a colored image.
	//            If the destination channel is the alpha channel, and this bitmap doesn't have an alpha channel.
	//            it will be expanded with the alpha mask loaded. If this bitmap has already an alpha channel,
	//            then the previous alpha data will be replaced.
	//            If the source bitmap doesn't have same size as this bitmap, the source bitmap will stretched
	//            to match the destination size before channel transferring.
	//
	// See: FSDIBitmapLoadChannel2
	//************************************
	static void LoadChannel(FS_DIBitmap bitmap, FS_DIB_Channel destChannel, const FS_DIBitmap srcBitmap, FS_DIB_Channel srcChannel);

	//************************************
	// Function:  LoadChannel2
	// Param[in]: bitmap        The input bitmap.
	// Param[in]: destChannel	The destination channel.
	// Param[in]: value			The value to fill channel.
	// Return:    void
	// Remarks:   Sets a full channel to specified value (0-255).
	// Notes:     This bitmap must be in Rgb, Rgb32, or Argb format.
	// See: FSDIBitmapLoadChannel
	//************************************
	static void	LoadChannel2(FS_DIBitmap bitmap, FS_DIB_Channel destChannel, FS_INT32 value);

	//************************************
	// Function:  MultiplyAlpha
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: alpha		The alpha value to multiply with.
	// Return:    void
	// Remarks:   Multiplies alpha data with addition alpha (0-255).
	// Notes:     Applicable to all formats:
	//            If this is an alpha mask (1bppMask or 8bppMask), the result will be a 8bppMask with mask data modified;
	//            If this is an image without alpha channel, the bitmap will be expanded to include an alpha channel with new alpha data;
	//            If this is an image with alpha channel, then the alpha value will be multiplied into existing alpha data.
	// See: FSDIBitmapMultiplyAlpha2
	//************************************
	static void	MultiplyAlpha(FS_DIBitmap bitmap, FS_INT32 alpha);

	//************************************
	// Function:  MultiplyAlpha2	
	// Param[in]: bitmap		The input bitmap.
	// Param[in]: alphaMask		The alpha mask to multiply with.
	// Return:    void
	// Remarks:   Multiplies existing alpha data with another alpha mask.
	// Notes:     Applicable to all destination formats:
	//            If this is an alpha mask (1bppMask or 8bppMask), the result will be a 8bppMask with mask data multiplied;
	//            If this is an image without alpha channel, the bitmap will be expanded to include an alpha channel with new alpha data;
	//            If this is an image with alpha channel, then the alpha value will be multiplied into existing alpha data.
	//            If the source mask doesn't have same size as this bitmap, the source mask will stretched
	//            to match the destination size before multiplying.
	// See: FSDIBitmapMultiplyAlpha
	//************************************
	static void MultiplyAlpha2(FS_DIBitmap bitmap, const FS_DIBitmap alphaMask);

	//************************************
	// Function:  TransferBitmap
	// Param[in]: bitmap		The input bitmap.
	// Param[in]: destLeft		The x-coordinate in destination bitmap.
	// Param[in]: destTop		The y-coordinate in destination bitmap.
	// Param[in]: width			The area width to transfer.
	// Param[in]: height		The area height to transfer.
	// Param[in]: srcBitmap		The DIB source.
	// Param[in]: srcLeft		The x-coordinate in source bitmap.
	// Param[in]: srcTop		The y-coordinate in source bitmap.
	// Return:    void
	// Remarks:   Transforms pixels from another bitmap into specified position.
	// Notes:     The destination and source bitmaps can have different format, but need to be compatible.
	//            "width" and "height" parameters can not be negative. 
	//            Positions will be automatically clipped if out of source or destination bitmap region.
	//            The destination region will be replaced by data from the source bitmap.
	// See: FSDIBitmap
	//************************************
	static void TransferBitmap(
		FS_DIBitmap bitmap,
		FS_INT32 destLeft,
		FS_INT32 destTop,
		FS_INT32 width, 
		FS_INT32 height,
		const FS_DIBitmap srcBitmap,
		FS_INT32 srcLeft, 
		FS_INT32 srcTop
		);



	//************************************
	// Function:  TransferMask
	// Param[in]: bitmap		The input bitmap.
	// Param[in]: destLeft		The x-coordinate in destination bitmap.
	// Param[in]: destTop		The y-coordinate in destination bitmap.
	// Param[in]: width			The area width to transfer.
	// Param[in]: height		The area height to transfer.
	// Param[in]: mask			The mask source.
	// Param[in]: argb			The source color.
	// Param[in]: srcLeft		The x-coordinate in source bitmap.
	// Param[in]: srcTop		The y-coordinate in source bitmap.
	// Return:    void
	// Remarks:   Transfers (portion of) an alpha mask (with source color) to this bitmap.
	// Notes:     Applicable to Argb formats only. The changed portion will be replaced (not blended).
	//            The mask parameter must point to an alpha mask bitmap (1bppMask or 8bppMask).
	// See: FSDIBitmapCompositeBitmap
	// See: FSDIBitmapCompositeMask
	// See: FSDIBitmapCompositeRect
	//************************************
	static void TransferMask(
		FS_DIBitmap bitmap,
		FS_INT32 destLeft,
		FS_INT32 destTop,
		FS_INT32 width,
		FS_INT32 height,
		const FS_DIBitmap mask,
		FS_ARGB argb,
		FS_INT32 srcLeft,
		FS_INT32 srcTop
		);


	//************************************
	// Function:  CompositeBitmap
	// Param[in]: bitmap		The input bitmap.
	// Param[in]: destLeft		The x-coordinate in destination bitmap.
	// Param[in]: destTop		The y-coordinate in destination bitmap.
	// Param[in]: width			The area width to composite.
	// Param[in]: height		The area height to composite.
	// Param[in]: srcBitmap		The source bitmap.
	// Param[in]: srcLeft		The x-coordinate in source bitmap.
	// Param[in]: srcTop		The y-coordinate in source bitmap.
	// Param[in]: blend_type	The blend type. Decleared in <a>FSDIBlendTypes</a> group.
	// Return:    void
	// Remarks:   Composites and blend source bitmap into this <param>bitmap</param>.<br></brief>
	// This bitmap can be Rgb/Rgb32/Argb bitmap, and source bitmap can be any kind of bitmap (except masks).<br>
	// This bitmap can also be an 8bppMask, in this case only alpha channel from the source bitmap is composited.
	// Notes: 
	// See: FSDIBitmapCompositeMask
	// See: FSDIBitmapCompositeRect
	//************************************

	static void CompositeBitmap(
		FS_DIBitmap bitmap,
		FS_INT32 destLeft,
		FS_INT32 destTop,
		FS_INT32 width,
		FS_INT32 height,
		const FS_DIBitmap srcBitmap,
		FS_INT32 src_left, 
		FS_INT32 src_top,
		FS_INT32 blend_type
		);

	//************************************
	// Function:  CompositeRect
	// Param[in]: bitmap		The input bitmap.
	// Param[in]: destLeft		The x-coordinate of the left-top corner.
	// Param[in]: destTop		The y-coordinate of the left-top corner.
	// Param[in]: width			The area width.
	// Param[in]: height		The area height.
	// Param[in]: argb			The fixed color.
    // Return:    void
	// Remarks:   Composites a fixed color into a rectangle area.
	// Notes:     Applicable to 8bppMask/Rgb/Rgb32/Argb formats only.
	// See: FSDIBitmapCompositeBitmap
	// See: FSDIBitmapTransferMask
	// See: FSDIBitmapCompositeMask
	//************************************
	static void	CompositeRect(
		FS_DIBitmap bitmap, 
		FS_INT32 destLeft,
		FS_INT32 destTop, 
		FS_INT32 width, 
		FS_INT32 height, 
		FS_ARGB argb
		);


	//************************************
	// Function:  GammaAdjust
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: bInvert	Whether reverse gamma adjustment or not.
	// Return:    void
	// Remarks:   Gamma adjustment.
	// Notes:
	//************************************
	static void	GammaAdjust(FS_DIBitmap bitmap, FS_BOOL bInvert);

	//************************************
	// Function:  ConvertColorScale
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: forecolor The input forecolor.
	// Param[in]: backcolor The input backcolor.
	// Return:    void
	// Remarks:   Converts current bitmap to a color scale bitmap. The DIB format won't be changed.
	// Notes:     Color scale means all colors are a scale from forecolor to backcolor.
	//            If forecolor is black and backcolor is white, that's gray scale
	//            Doesn't work with masks.
	//************************************
	static void	ConvertColorScale(FS_DIBitmap bitmap, FS_COLORREF forecolor, FS_COLORREF backcolor);

	//************************************
	// Function:  DitherFS
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: pPalette	The input palette color.
	// Param[in]: palSize	The input palette size.
	// Param[in]: pRect		The input rect for ditherning.
	// Return:    void
	// Remarks:   Floyd-Steinberg dithering for (portion of) the bitmap, using a palette.
	// Notes:     Currently only 8-bit gray scale bitmap is supported!
	//************************************
	static void	DitherFS(FS_DIBitmap bitmap, FS_ARGB* pPalette, FS_INT32 palSize, FS_Rect* pRect);

	//************************************
	// Function:  GetBPP	
	// Param[in]: bitmap The input bitmap.
	// Return:    The number of bits per pixel.
	// Remarks:   Gets the number of bits per pixel.
	// Notes:
	//************************************
	static FS_INT32 GetBPP(FS_DIBitmap bitmap);

	//************************************
	// Function:  IsAlphaMask	
	// Param[in]: bitmap The input bitmap.
	// Return:    <a>TRUE</a> for bitmap being an alpha mask.
	// Remarks:   Checks whether the bitmap is an alpha mask (either 1bpp bitmask or 8bpp gray scale).
	// Notes:
	//************************************
	static FS_BOOL IsAlphaMask(FS_DIBitmap bitmap);

	//************************************
	// Function:  HasAlpha
	// Param[in]: bitmap The input bitmap.
	// Return:    Non-zero means it has a alpha channel, otherwise has not.
	// Remarks:   Checks if it's a bitmap with alpha channel.
	// Notes:     Alpha masks return <a>FALSE</a>.
	//************************************
	static FS_BOOL HasAlpha(FS_DIBitmap bitmap);

	//************************************
	// Function:  IsOpaqueImage	
	// Param[in]: bitmap The input bitmap.
	// Return:    Non-zero means it is a solid (opaque) image, otherwise is not.
	// Remarks:   Checks if it's a solid (opaque) image.
	// Notes:
	//************************************
	static FS_BOOL IsOpaqueImage(FS_DIBitmap bitmap);

	//************************************
	// Function:  GetPaletteSize	
	// Param[in]: bitmap The input bitmap.
	// Return:    The number of palette entries.
	// Remarks:   Gets the number of palette entries.
	// Notes:
	//************************************
	static FS_INT32	GetPaletteSize(FS_DIBitmap bitmap);

	//************************************
	// Function:  GetPaletteArgb
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: index		Zero-based palette entry index of the palette.
	// Return:    A palette entry value.
	// Remarks:   Gets palette entry with specified palette entry index.
	// Notes:     
	// See: FSDIBitmapSetPaletteArgb
	//************************************
	static FS_ARGB GetPaletteArgb(FS_DIBitmap bitmap,FS_INT32 index);

	//************************************
	// Function:  SetPaletteArgb	
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: index		Zero-based palette entry index of the palette.
	// Param[in]: argb		The new value the entry.
	// Return:    void
	// Remarks:   Changes a specified palette entry.
	// Notes:     
	// See: FSDIBitmapGetPaletteArgb
	//************************************
	static void SetPaletteArgb(FS_DIBitmap bitmap, FS_INT32 index, FS_ARGB argb);

	//************************************
	// Function:  Clone	
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: pClip		The clipping region of source bitmap
	// Return:    A cloned bitmap.
	// Remarks:   Clones a bitmap. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:     Optionally a clipping region in bitmap coordinates can be specified to limit the size of result bitmap.
	// See: FSDIBitmapCloneConvert
	//************************************
	static FS_DIBitmap Clone(FS_DIBitmap bitmap, FS_Rect* pClip);

	//************************************
	// Function:  CloneConvert	
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: format	The destination bitmap format.
	// Param[in]: pClip		The clipping region of source bitmap.
	// Return:    The cloned bitmap.
	// Remarks:   Converts a bitmap, but clone first. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:     Optionally a clipping region in bitmap coordinates can be specified to limit the size of result bitmap.
	// See: FSDIBitmapClone
	//************************************
	static FS_DIBitmap CloneConvert(FS_DIBitmap bitmap, FS_DIB_Format format, FS_Rect* pClip);

	//************************************
	// Function:  GetAlphaMask 
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: pClip		The clipping region of source bitmap.
	// Return:    An alpha mask.
	// Remarks:   Gets alpha mask from a bitmap. Returns a 8bpp alpha mask. The returned value must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:     Applicable to Argb format only.
	//            Optionally a clipping region in bitmap coordinates can be specified to limit the size of result mask.
	//************************************
	static FS_DIBitmap GetAlphaMask(FS_DIBitmap bitmap, FS_Rect* pClip);
	
	//************************************
	// Function:  StretchTo	
	// Param[in]: bitmap		The input bitmap.
	// Param[in]: destWidth		The width of the destination bitmap.
	// Param[in]: destHeight	The height of the destination bitmap.
	// Param[in]: flags			Stretching flags. It can use <a>FS_DIB_DOWNSAMPLE</a> and <a>FS_DIB_INTERPOL</a> flags
	// Param[in]: pClip			The clipping region of destination bitmap.
	// Return:    A new bitmap with different size.
	// Remarks:   Stretches this bitmap into a new bitmap with different size. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:     If dest width or dest height is negative, the bitmap will be flipped.
	//            If a 1bpp bitmap is stretched, it will become either a RGB bitmap, if it's a colored bitmap;
	//            or a 8bpp gray scale mask if it's a bit mask.
	//            Stretching can be done in down-sample mode, which doesn't do interpolation so significantly faster
	//            especially when stretching big images into small ones.
	//            Optionally a clipping region in result bitmap coordinates can be specified to limit the size of result bitmap.

	//************************************
	static FS_DIBitmap StretchTo(FS_DIBitmap bitmap, FS_INT32 destWidth, FS_INT32 destHeight, FS_DWORD flags, FS_Rect* pClip);


	//************************************
	// Function:   TransformTo	
	// Param[in]:  bitmap		The input bitmap.
	// Param[in]:  pMatrix		The transformation matrix.
	// Param[out]: outLeft		Receives x-coordinate of the left-top corner of the result bitmap in destination coords.
	// Param[out]: outTop		Receives y-coordinate of the left-top corner of the result bitmap in destination coords.
	// Param[in]:  flags		Stretching flags. It can use <a>FS_DIB_DOWNSAMPLE</a> and <a>FS_DIB_INTERPOL</a> flags.
	// Param[in]:  pClip		The clipping region of destination bitmap.
	// Return:     A new transformed bitmap.
	// Remarks:    Transforms this bitmap. A new transformed bitmap is returned. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:      This bitmap can be colored bitmap, or an alpha mask. In case of colored bitmap,
	//             certain transformation (rotating or skewing) will cause the return bitmap as ARGB, no matter
	//             what the source bitmap format is.
	//             If a 1bpp bitmap is transformed, it will become either a RGB bitmap, if it's a colored bitmap;
	//             or a 8bpp gray scale mask if it's a bit mask.
	//             The dimension of returned bitmap always match the dimension of the matrix.
	//             Transformation can be done in down-sample mode, which doesn't do interpolation so significantly faster
	//             especially when transforming big images into small ones.
	//             Optionally a clipping region in result bitmap coordinates can be specified to limit the size of result bitmap.
	//             The position of left-top corner (in destination coordinates) of the result bitmap is also returned.
	//************************************
	static FS_DIBitmap TransformTo(
		FS_DIBitmap bitmap, 
		FS_AffineMatrix* pMatrix,
		FS_INT32* outLeft,
		FS_INT32* outTop, 
		FS_DWORD flags, 
		FS_Rect* pClip
		);

	//************************************
	// Function:  SwapXY
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: bXFlip	Whether to flip the bitmap in x-direction.
	// Param[in]: bYFlip	Whether to flip the bitmap in y-direction.
	// Param[in]: pClip		The clipping region of destination bitmap.
	// Return:    A new bitmap.
	// Remarks:   Swaps X,Y coordinations of the bitmap. The image can also be flipped at the same time. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:     Optionally a clipping region (in destination bitmap coordinates) can be specified to limit the size of result.
	//            This function can be used to rotate the bitmap 90 or 270 degree.
	//            Suppose the original image has the following 4 pixels:
	//			  
	//            +---+---+
	//			  | 1 | 2 |
	//			  +---+---+
	//			  | 3 | 4 |
	//			  +---+---+
	//			  Then, depends on value of <param>bXFlip</param> and <param>bYFlip</param>, the result would look like this:
	//				 
	//			  if bXFlip = FALSE, bYFlip = FALSE:
	//			  +---+---+
	//			  | 1 | 3 |
	//			  +---+---+
	//			  | 2 | 4 |
	//			  +---+---+
	//					
	//			  if bXFlip = TRUE, bYFlip = FALSE:
	//			  +---+---+
	//			  | 3 | 1 |
	//			  +---+---+
	//			  | 4 | 2 |
	//			  +---+---+
	//					
	//			  if bxflip = false, byflip = true:
	//			  +---+---+
	//			  | 2 | 4 |
	//			  +---+---+
	//			  | 1 | 3 |
	//			  +---+---+
	//					
	//			  if bxflip = true, byflip = true:
	//			  +---+---+
	//			  | 4 | 2 |
	//			  +---+---+
	//			  | 3 | 1 |
	//			  +---+---+  
	//************************************
	static FS_DIBitmap SwapXY(FS_DIBitmap bitmap, FS_BOOL bXFlip, FS_BOOL bYFlip, FS_Rect* pClip);

	//************************************
	// Function:  FlipImage	
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: bXFlip	Whether to flip the bitmap in x-direction.
	// Param[in]: bYFlip	Whether to flip the bitmap in y-direction.
	// Return:    A flipped bitmap.
	// Remarks:   Flips image. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:
	//************************************
	static FS_DIBitmap FlipImage(FS_DIBitmap bitmap, FS_BOOL bXFlip, FS_BOOL bYFlip);
	
	//************************************
	// Function:  LoadFromPNGIcon	
	// Param[in]: pwsFilePath	The input PNG file path.
	// Return:    The bitmap loaded.
	// Remarks:   Loads a bitmap from a PNG file.
	// Notes:
	//************************************
	static FS_DIBitmap LoadFromPNGIcon(FS_LPCWSTR pwsFilePath);

	//************************************
	// Function:  LoadFromPNGIcon2	
	// Param[in]: handler	The file access handler. The core API will take over the handler and release it. The plug-in do not need to release it.
	// Return:    The bitmap loaded.
	// Remarks:   Loads a bitmap from a buffer.
	// Notes:
	//************************************
	static FS_DIBitmap LoadFromPNGIcon2(FS_FileReadHandler handler);

	//************************************
	// Function:  Copy	
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: src		The DIB source.
	// Return:    TRUE for success, FALSE for failure.
	// Remarks:   Copy from a DIB source, including bitmap info and all pixel data.
	// This DIBitmap must be newly constructed.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// Deprecated: Internal use. Suggest to use FSDIBitmapCopy2.
	//************************************
	static FS_BOOL Copy(FS_DIBitmap bitmap, FS_DIBitmap src);

	//************************************
	// Function:  LoadInfo	
	// Param[in]: handler	The file access handler.
	// Param[in]: imageType The image type.
	// Return:    The bitmap attribute loaded.
	// Remarks:   Loads a bitmap attribute from a buffer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSDIBitmapDestroyDIBAttribute
	//************************************
	static FS_DIBAttribute LoadInfo(FS_FileReadHandler handler, FS_DIB_IMAGE_TYPE imageType);

	//************************************
	// Function:  DestroyDIBAttribute	
	// Param[in]: attr	The input bitmap attribute object to be destroyed.
	// Return:    void
	// Remarks: Destroys the input bitmap attribute object. Otherwise the plug-in will cause the memory leak problem.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSDIBitmapLoadInfo
	//************************************
	static void DestroyDIBAttribute(FS_DIBAttribute attr);

	//************************************
	// Function:  GetXDPI	
	// Param[in]: attr	The input bitmap attribute object.
	// Return: The horizontal resolution, -1 means the bitmap doesn't contain this information, 0 or 1 means the user should use default DPI value. 
	// Remarks: Gets the horizontal resolution attribute of the bitmap.
	// Notes: JBIG2 cannot get DPI information now.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSDIBitmapLoadInfo
	//************************************
	static FS_INT32 GetXDPI(FS_DIBAttribute attr);

	//************************************
	// Function:  GetYDPI	
	// Param[in]: attr	The input bitmap attribute object.
	// Return: The vertical resolution, -1 means the bitmap doesn't contain this information, 0 or 1 means the user should use default DPI value.
	// Remarks: Gets the Vertical resolution attribute of the bitmap.
	// Notes: JBIG2 cannot get DPI information now.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSDIBitmapLoadInfo
	//************************************
	static FS_INT32 GetYDPI(FS_DIBAttribute attr);

	//************************************
	// Function:  GetDPIUnit	
	// Param[in]: attr	The input bitmap attribute object.
	// Return: The resolution unit.
	// Remarks: Gets the resolution unit, described by <a>FS_DIB_RESUNIT</a>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSDIBitmapLoadInfo
	//************************************
	static FS_WORD GetDPIUnit(FS_DIBAttribute attr);

	//************************************
	// Function:  GetExifInfo	
	// Param[in]: attr	The input bitmap attribute object.
	// Param[in]: tag	The input tag of the exchangeable image file information of camera in JPEG file, described by <a>FSDIBEXIFTAG</a>.
	// Param[out]: val	The output value of the exchangeable image file information.
	// Return: <a>TRUE</a> means success, otherwise failure.
	// Remarks: Gets the exchangeable image file information of camera in JPEG file.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSDIBitmapLoadInfo
	//************************************
	static FS_BOOL GetExifInfo(FS_DIBAttribute attr, FS_WORD tag, FS_LPVOID val);

	//************************************
	// Function:  LoadFromPNGIcon3	
	// Param[in]: hInstance	The input plug-in instance handle.
	// Param[in]: lpwsName	The input name of PNG resource. The <Italic>MAKEINTRESOURCE</Italic> macro can be used to create this value.
	// Return:    The bitmap loaded.
	// Remarks:   Loads a bitmap from a instance handle.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_DIBitmap LoadFromPNGIcon3(FS_HINSTANCE hInstance, FS_LPCWSTR lpwsName);

	//************************************
	// Function:  LoadFromImage	
	// Param[in]: handler	The file access handler.
	// Return:    The bitmap loaded.
	// Remarks:   Loads a bitmap from a buffer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_DIBitmap LoadFromImage(FS_FileReadHandler handler);

	//************************************
	// Function:  GetBitmapAlphaMask	
	// Param[in]: bitmap	The input bitmap.
	// Return:  FS_DIBitmap  Must be 8bpp Mask. for extra alpha channel.
	// Remarks:   Get the alpha mask.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_DIBitmap GetBitmapAlphaMask(FS_DIBitmap bitmap);

	//************************************
	// Function:  New2 
	// Param[in]: bitmapHandler	The input bitmap.
	// Return:	  A <a>FS_DIBitmap</a> object.
	// Remarks:   Creates a bitmap. 
	// Notes:     The buffer should be kept by caller during the existence of the bitmap.	
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: FSDIBitmapDestroy
	//************************************
	static FS_DIBitmap New2(FPD_DIBitmapCallbacks bitmapHandler);

	//************************************
	// Function:  InitDIBitmapAttribute 
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: attribute	The input bitmap attribute.
	// Return:	 void
	// Remarks:   Init property of bitmap. 
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: 
	//************************************
	static void	InitDIBitmapAttribute(FS_DIBitmap bitmap, FPD_DIBitmap_Attribute attribute);

	//************************************
	// Function:  Copy2
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: src		The DIB source.
	// Return:    TRUE for success, FALSE for failure.
	// Remarks:   Copy from a DIB source, including bitmap info and all pixel data.
	// This DIBitmap must be newly constructed.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_BOOL Copy2(FS_DIBitmap bitmap, FS_DIBSource src);

	//************************************
	// Function:  CloneConvert	
	// Param[in]: bitmap	The input bitmap.
	// Param[in]: format	The destination bitmap format.
	// Param[in]: pClip		The clipping region of source bitmap.
	// param[in]  pIccTransform		The color mapping context for source format to destination.
	// Return:    The cloned bitmap.
	// Remarks:   Converts a bitmap, but clone first. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:     Optionally a clipping region in bitmap coordinates can be specified to limit the size of result bitmap.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: FSDIBitmapClone
	//************************************
	static FS_DIBitmap CloneConvert2(FS_DIBitmap bitmap, FS_DIB_Format format, FS_Rect* pClip, FS_LPVOID pIccTransform);

	//************************************
	// Function:  MultiplyAlpha3	
	// Param[in]: bitmap		The input bitmap.
	// Param[in]: alphaMask		The alpha mask to multiply with.
	// Return:    void
	// Remarks:   Multiplies existing alpha data with another alpha mask.
	// Notes:     Applicable to all destination formats:
	//            If this is an alpha mask (1bppMask or 8bppMask), the result will be a 8bppMask with mask data multiplied;
	//            If this is an image without alpha channel, the bitmap will be expanded to include an alpha channel with new alpha data;
	//            If this is an image with alpha channel, then the alpha value will be multiplied into existing alpha data.
	//            If the source mask doesn't have same size as this bitmap, the source mask will stretched
	//            to match the destination size before multiplying.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See: FSDIBitmapMultiplyAlpha
	//************************************
	static void MultiplyAlpha3(FS_DIBitmap bitmap, const FS_DIBSource alphaMask);

	//************************************
	// Function:  CastToBitsource
	// Param[in]: bitmap	The input bitmap.
	// Return:    FS_DIBSource.
	// Remarks:   Convert to FS_DIBSource.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	//************************************
	static FS_DIBSource CastToBitSource(FS_DIBitmap bitmap);
};

class CFS_MapPtrToPtr_V1
{
	
public:


	//************************************
	// Function:  New	
	// Param[in]: nBlockSize	The internal block
	// Return:    An empty ptr-to-ptr map.
	// Remarks:   Creates an empty ptr-to-ptr map.
	// Notes:
	//************************************
	static FS_MapPtrToPtr New(FS_INT32 nBlockSize);


	//************************************
	// Function:  Destroy
	// Param[in]: map The input ptr-to-ptr map.
	// Return:    void
	// Remarks:   Destroys a ptr-to-ptr map.
	// Notes:
	//************************************
	static void	Destroy(FS_MapPtrToPtr map);
	
	//************************************
	// Function:  GetCount	
	// Param[in]: map The input ptr-to-ptr map.
	// Return:   The number of elements in the map.
	// Remarks:   Gets the number of elements.
	// Notes:    
	//************************************
	static FS_INT32	GetCount(FS_MapPtrToPtr map);


	//************************************
	// Function:  IsEmpty	
	// Param[in]: map The input ptr-to-ptr map.
	// Return:    <a>TRUE</a> for map being empty. <a>FALSE</a> otherwise.
	// Remarks:   Tests whether the <param>map</param> is empty.
	// Notes:
	//************************************
	static FS_BOOL IsEmpty(FS_MapPtrToPtr map);


	//************************************
	// Function:   Lookup
	// Param[in]:  map The input ptr-to-ptr map.
	// Param[in]:  key The key to lookup.
	// Param[out]: outValue A ref of a typeless pointer to receive the found value.
	// Return:     <a>TRUE</a> for value being found. <a>FALSE</a> otherwise.
	// Remarks:    Lookups by a key.
	// Notes:
	//************************************
	static FS_BOOL Lookup(FS_MapPtrToPtr map, void* key, void** outValue);


	//************************************
	// Function:  GetValueAt	
	// Param[in]: map The input ptr-to-ptr map.
	// Param[in]: key The key to specify a value.
	// Return:   A value. <a>NULL</a> if the key is not found.
	// Remarks:   Retrieves a value pointer by a key
	// Notes:
	//************************************
	static void* GetValueAt(FS_MapPtrToPtr map, void* key);


	//************************************
	// Function:  SetAt	
	// Param[in]: map			The input ptr-to-ptr map.
	// Param[in]: key			The key to specify a position.
	// Param[in]: newValue		The new value.
	// Return:    void
	// Remarks:   Adds a new (key, value) pair. Adds if not exist, otherwise modify.
	// Notes:
	//************************************
	static void SetAt(FS_MapPtrToPtr map, void* key, void* newValue);


	//************************************
	// Function:  RemoveKey	
	// Param[in]: map The input ptr-to-ptr map.
	// Param[in]: key The key to remove.
	// Return:    <a>TRUE</a> for success, otherwise <a>FALSE</a>.
	// Remarks:   Removes existing (key, value) pair.
	// Notes:     
	//************************************
	static FS_BOOL RemoveKey(FS_MapPtrToPtr map, void* key);


	//************************************
	// Function:  RemoveAll	
	// Param[in]: map The input ptr-to-ptr map.
	// Return:    void
	// Remarks:   Removes all the (key, value) pairs in the map.
	// Notes:
	//************************************
	static void RemoveAll(FS_MapPtrToPtr map);


	//************************************
	// Function:  GetStartPosition	
	// Param[in]: map The input ptr-to-ptr map.
	// Return:    The first key-value pair position in the map
	// Remarks:   Gets the first key-value pair position, iterating all (key, value) pairs.
	// Notes:
	//************************************
	static FS_POSITION GetStartPosition(FS_MapPtrToPtr map);


	//************************************
	// Function:      GetNextAssoc
	// Param[in]:     map					The input ptr-to-ptr map.
	// Param[in,out]: inOutNextPosition		Input a position, and receive the next association position.
	// Param[out]:    outKey				(Filled by this method)Receive a key.
	// Param[out]:    outValue				(Filled by this method)Receive a value.
	// Return:        void
	// Remarks:       Gets the current association and sets the position to next association.
	// Notes:
	//************************************
	static void GetNextAssoc(FS_MapPtrToPtr map, FS_POSITION* inOutNextPosition, void** outKey, void** outValue);


	//************************************
	// Function:  GetHashTableSize
	// Param[in]: map		The input ptr-to-ptr map.
	// Return:    The hash table size.
	// Remarks:   Gets the internal hash table size. Advanced features for derived classes.
	// Notes:     
	//************************************
	static FS_DWORD GetHashTableSize(FS_MapPtrToPtr map);


	//************************************
	// Function:  InitHashTable	
	// Param[in]: map			The input ptr-to-ptr map.
	// Param[in]: hashSize		Initializes the hash table size.
	// Param[in]: bAllocNow		Does it Now allocate the hash table? No-zero means yes, otherwise not.
	// Return:    void
	// Remarks:   Initializes the hash table
	// Notes:     
	//************************************
	static void InitHashTable(FS_MapPtrToPtr map, FS_DWORD hashSize, FS_BOOL bAllocNow);

};



class CFS_PtrArray_V1
{
	
public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty pointer array.
	// Remarks:   Creates a new empty pointer array.
	// Notes:
	//************************************
	static FS_PtrArray New(void);


	//************************************
	// Function:  Destroy	
	// Param[in]: arr		The input pointer array.
	// Return:    void
	// Remarks:   Destroys a pointer array.
	// Notes:
	//************************************
	static void Destroy(FS_PtrArray arr);

	//************************************
	// Function:  GetSize	
	// Param[in]: arr		The input pointer array.
	// Return:    The number of elements in the array.
	// Remarks:   Gets the number of elements in the array.
	// Notes:
	//************************************
	static FS_INT32	GetSize(FS_PtrArray arr);


	//************************************
	// Function:  GetUpperBound	
	// Param[in]: arr		The input pointer array.
	// Return:    The upper bound.
	// Remarks:   Gets the upper bound in the array, actually the maximum valid index.
	// Notes:
	//************************************
	static FS_INT32	GetUpperBound(FS_PtrArray arr);


	//************************************
	// Function:  SetSize
	// Param[in]: arr		 The input pointer array.
	// Param[in]: nNewSize	 The new size in elements expected.
	// Param[in]: nGrowBy	 The grow amount in elements expected, nGrowBy can be -1 for the grow amount unchanged.
	// Return:    void
	// Remarks:   Changes the allocated size and the growing amount.
	// Notes:
	//************************************
	static void	SetSize(FS_PtrArray arr, FS_INT32 nNewSize, FS_INT32 nGrowBy);


	//************************************
	// Function:  RemoveAll	
	// Param[in]: arr		The input pointer array.
	// Return:    void
	// Remarks:   Cleans up the array.
	// Notes:
	//************************************
	static void	RemoveAll(FS_PtrArray arr);


	//************************************
	// Function:  GetAt	
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Return:    An element.
	// Remarks:	  Retrieves an element specified by an index number.
	// Notes:
	//************************************
	static void* GetAt(FS_PtrArray arr, FS_INT32 index);


	//************************************
	// Function:  SetAt
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Param[in]: newItem	An element
	// Return:    void
	// Remarks:	  Overwrites an element specified by an index number.
	// Notes:
	//************************************
	static void SetAt(FS_PtrArray arr, FS_INT32 index, void* newItem);


	//************************************
	// Function:  SetAtGrow
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Param[in]: newItem	The input element.
	// Return:    void
	// Remarks:	  Sets an element value at specified position. Potentially grow the array.
	// Notes:
	//************************************
	static void SetAtGrow(FS_PtrArray arr, FS_INT32 index, void* newItem);


	//************************************
	// Function:  Add
	// Param[in]: arr		The input pointer array.
	// Param[in]: newItem	The input element.
	// Return:    The added element's index in the array.
	// Remarks:   Adds an element at the tail. Potentially grow the array.
	// Notes:    
	//************************************
	static FS_INT32 Add(FS_PtrArray arr, void* newItem);


	//************************************
	// Function:  Append	
	// Param[in]: arr		The input pointer array.
	// Param[in]: srcArr	The input array.
	// Return:    The old size in elements.
	// Remarks:	  Appends an array.
	// Notes:
	//************************************
	static FS_INT32 Append(FS_PtrArray arr, const FS_PtrArray srcArr);


	//************************************
	// Function:  Copy	
	// Param[in]: arr		The input pointer array.
	// Param[in]: srcArr	The input array.
	// Return:    void
	// Remarks:   Copies from an array.
	// Notes:
	//************************************
	static void	Copy(FS_PtrArray arr, FS_PtrArray srcArr);

	//************************************
	// Function:    GetDataPtr
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Return:    A pointer to the specified element.
	// Remarks:   Gets a pointer to the specified element in the array. Direct pointer access.
	// Notes:
	//************************************
	static void** GetDataPtr(FS_PtrArray arr, FS_INT32 index);

	//************************************
	// Function:  InsertAt	
	// Param[in]: arr			The input pointer array.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Param[in]: newItem	    Specifies the element value to insert.
	// Param[in]: nCount		Specifies the count of the element to insert.
	// Return:    void
	// Remarks:   Inserts one or more continuous element at specified position.
	// Notes:
	//************************************
	static void InsertAt(FS_PtrArray arr, FS_INT32 index, void* newItem, FS_INT32 nCount);


	//************************************
	// Function:  RemoveAt
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index in the array.
	// Param[in]: nCount	Specifies the count of element to remove.
	// Return:    void
	// Remarks:   Removes a number of elements at specified position.
	// Notes:     
	//************************************
	static void	RemoveAt(FS_PtrArray arr, FS_INT32 index, FS_INT32 nCount);


	//************************************
	// Function:  InsertNewArrayAt		
	// Param[in]: arr			The input pointer array.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to insert at.
	// Param[in]: newArray		The input array.
	// Return:    void
	// Remarks:   Inserts an array at specified position.
	// Notes:
	//************************************
	static void	InsertNewArrayAt(FS_PtrArray arr, FS_INT32 nStartIndex, FS_PtrArray newArray);


	//************************************
	// Function:  Find	   
	// Param[in]: arr			The input pointer array.
	// Param[in]: item			The input element.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to find.
	// Return:	  An index of the found element. It can be -1 for finding none.
	// Remarks:   Finds an element from specified position to last
	// Notes:
	//************************************
	static FS_INT32 Find(FS_PtrArray arr, void* item, FS_INT32 nStartIndex);
};

class CFS_ByteArray_V1
{

public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty byte array.
	// Remarks:   Creates a new empty byte array.
	// Notes:
	//************************************
	static FS_ByteArray New(void);


	//************************************
	// Function:  Destroy	
	// Param[in]: arr		The input byte array.
	// Return:    void
	// Remarks:   Destroys a byte array.
	// Notes:
	//************************************
	static void Destroy(FS_ByteArray arr);

	//************************************
	// Function:  GetSize	
	// Param[in]: arr		The input byte array.
	// Return:    The number of elements in the array.
	// Remarks:   Gets the number of elements in the array.
	// Notes:
	//************************************
	static FS_INT32	GetSize(FS_ByteArray arr);


	//************************************
	// Function:  GetUpperBound	
	// Param[in]: arr		The input byte array.
	// Return:   The upper bound.
	// Remarks:   Gets the upper bound in the array, actually the maximum valid index.
	// Notes:
	//************************************
	static FS_INT32	GetUpperBound(FS_ByteArray arr);


	//************************************
	// Function:  SetSize
	// Param[in]: arr		 The input byte array.
	// Param[in]: nNewSize	 The new size in elements expected.
	// Param[in]: nGrowBy	 The growing amount in elements expected. <param>nGrowBy</param> can be -1 for the growing amount unchanged.
	// Return:    void
	// Remarks:   Changes the allocated size and the growing amount.
	// Notes:
	//************************************
	static void	SetSize(FS_ByteArray arr, FS_INT32 nNewSize, FS_INT32 nGrowBy);


	//************************************
	// Function:  RemoveAll	
	// Param[in]: arr		The input byte array.
	// Return:    void
	// Remarks:   Cleans up the array.
	// Notes:
	//************************************
	static void	RemoveAll(FS_ByteArray arr);


	//************************************
	// Function:  GetAt	
	// Param[in]: arr		The input byte array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Return:    An element
	// Remarks:	  Retrieves an element specified by an index number.
	// Notes:
	//************************************
	static FS_BYTE GetAt(FS_ByteArray arr, FS_INT32 index);


	//************************************
	// Function:  SetAt
	// Param[in]: arr		The input byte array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Param[in]: newItem	An element
	// Return:    void
	// Remarks:	  Overwrites an element specified by an index number.
	// Notes:
	//************************************
	static void SetAt(FS_ByteArray arr, FS_INT32 index, FS_BYTE newItem);


	//************************************
	// Function:  SetAtGrow
	// Param[in]: arr		The input byte array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Param[in]: newItem	The input element.
	// Return:    void
	// Remarks:	  Sets an element value at specified position. Potentially grow the array.
	// Notes:
	//************************************
	static void SetAtGrow(FS_ByteArray arr, FS_INT32 index, FS_BYTE newItem);


	//************************************
	// Function:  Add
	// Param[in]: arr		The input byte array.
	// Param[in]: newItem	The input element.
	// Return:    The added element's index in the array.
	// Remarks:   Adds an element at the tail. Potentially grow the array
	// Notes:    
	//************************************
	static FS_INT32 Add(FS_ByteArray arr, FS_BYTE newItem);


	//************************************
	// Function:  Append	
	// Param[in]: arr		The input byte array.
	// Param[in]: srcArr	The input array.
	// Return:    The old size in elements.
	// Remarks:	  Appends an array.
	// Notes:
	//************************************
	static FS_INT32 Append(FS_ByteArray arr, const FS_ByteArray srcArr);


	//************************************
	// Function:  Copy	
	// Param[in]: arr		The input byte array.
	// Param[in]: srcArr	The input array.
	// Return:    void
	// Remarks:   Copies from an array.
	// Notes:
	//************************************
	static void	Copy(FS_ByteArray arr, FS_ByteArray srcArr);

	//************************************
	// Function:    GetDataPtr
	// Param[in]: arr		The input byte array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Return:    A pointer to the specified element.
	// Remarks:   Gets a pointer to the specified element in the array. Direct pointer access.
	// Notes:
	//************************************
	static FS_BYTE* GetDataPtr(FS_ByteArray arr, FS_INT32 index);

	//************************************
	// Function:  InsertAt	
	// Param[in]: arr			The input byte array.	
	// Param[in]: index			Specifies the zero-based index in the array.
	// Param[in]: newItem	    Specifies the element value to insert.
	// Param[in]: nCount		Specifies the count of the element to insert.
	// Return:    void
	// Remarks:   Inserts one or more continuous element at specified position.
	// Notes:
	//************************************
	static void InsertAt(FS_ByteArray arr, FS_INT32 index, FS_BYTE newItem, FS_INT32 nCount);


	//************************************
	// Function:  RemoveAt
	// Param[in]: arr		The input byte array.
	// Param[in]: index		Specifies the zero-based index in the array.
	// Param[in]: nCount	Specifies the count of element to remove.
	// Return:    void
	// Remarks:   Removes a number of elements at specified position.
	// Notes:     
	//************************************
	static void	RemoveAt(FS_ByteArray arr, FS_INT32 index, FS_INT32 nCount);


	//************************************
	// Function:  InsertNewArrayAt		
	// Param[in]: arr			The input byte array.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to insert at.
	// Param[in]: newArray		The input array.
	// Return:    void
	// Remarks:   Inserts an array at specified position.
	// Notes:
	//************************************
	static void	InsertNewArrayAt(FS_ByteArray arr, FS_INT32 nStartIndex, FS_ByteArray newArray);


	//************************************
	// Function:  Find	   
	// Param[in]: arr			The input byte array.
	// Param[in]: item			The input element.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to find.
	// Return:	  An index of the found element. It can be -1 for finding none.
	// Remarks:   Finds an element from specified position to last
	// Notes:
	//************************************
	static FS_INT32 Find(FS_ByteArray arr, FS_BYTE item, FS_INT32 nStartIndex);
};

class CFS_WordArray_V1
{

public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty word array.
	// Remarks:   Creates a new empty word array.
	// Notes:
	//************************************
	static FS_WordArray New(void);


	//************************************
	// Function:  Destroy	
	// Param[in]: arr		The input word array.
	// Return:    void
	// Remarks:   Destroys a word array.
	// Notes:
	//************************************
	static void Destroy(FS_WordArray arr);

	//************************************
	// Function:  GetSize	
	// Param[in]: arr		The input word array.
	// Return:   The number of elements in the array.
	// Remarks:   Gets the number of elements in the array.
	// Notes:
	//************************************
	static FS_INT32	GetSize(FS_WordArray arr);


	//************************************
	// Function:  GetUpperBound	
	// Param[in]: arr		The input word array.
	// Return:   The upper bound.
	// Remarks:   Gets the upper bound in the array, actually the maximum valid index.
	// Notes:
	//************************************
	static FS_INT32	GetUpperBound(FS_WordArray arr);


	//************************************
	// Function:  SetSize
	// Param[in]: arr		 The input word array.
	// Param[in]: nNewSize	 The new size in elements expected.
	// Param[in]: nGrowBy	 The growing amount in elements expected. <param>nGrowBy</param> can be -1 for the growing amount unchanged.
	// Return:    void
	// Remarks:   Changes the allocated size and the growing amount.
	// Notes:
	//************************************
	static void	SetSize(FS_WordArray arr, FS_INT32 nNewSize, FS_INT32 nGrowBy);


	//************************************
	// Function:  RemoveAll	
	// Param[in]: arr The input word array.
	// Return:    void
	// Remarks:   Cleans up the array.
	// Notes:
	//************************************
	static void	RemoveAll(FS_WordArray arr);


	//************************************
	// Function:  GetAt	
	// Param[in]: arr		The input word array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Return:    An element
	// Remarks:	  Retrieves an element specified by an index number.
	// Notes:
	//************************************
	static FS_WORD GetAt(FS_WordArray arr, FS_INT32 index);


	//************************************
	// Function:  SetAt
	// Param[in]: arr		The input word array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Param[in]: newItem	An element
	// Return:    void
	// Remarks:	  Overwrites an element specified by an index number.
	// Notes:
	//************************************
	static void SetAt(FS_WordArray arr, FS_INT32 index, FS_WORD newItem);


	//************************************
	// Function:  SetAtGrow
	// Param[in]: arr		The input word array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Param[in]: newItem	The input element.
	// Return:    void
	// Remarks:	  Sets an element value at specified position. Potentially growing the array.
	// Notes:
	//************************************
	static void SetAtGrow(FS_WordArray arr, FS_INT32 index, FS_WORD newItem);


	//************************************
	// Function:  Add
	// Param[in]: arr		The input word array.
	// Param[in]: newItem	The input element.
	// Return:    The added element's index.
	// Remarks:   Adds an element at the tail. Potentially growing the array
	// Notes:    
	//************************************
	static FS_INT32 Add(FS_WordArray arr, FS_WORD newItem);


	//************************************
	// Function:  Append	
	// Param[in]: arr		The input word array.
	// Param[in]: srcArr	The input array.
	// Return:    The old size in elements.
	// Remarks:	  Appends an array.
	// Notes:
	//************************************
	static FS_INT32 Append(FS_WordArray arr, const FS_WordArray srcArr);


	//************************************
	// Function:  Copy	
	// Param[in]: arr		The input word array.
	// Param[in]: srcArr	The input array.
	// Return:    void
	// Remarks:   Copies from an array.
	// Notes:
	//************************************
	static void	Copy(FS_WordArray arr, FS_WordArray srcArr);

	//************************************
	// Function:    GetDataPtr
	// Param[in]: arr		The input word array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Return:    A pointer to the specified element.
	// Remarks:   Gets a pointer to the specified element in the array. Direct pointer access.
	// Notes:
	//************************************
	static FS_WORD* GetDataPtr(FS_WordArray arr, FS_INT32 index);

	//************************************
	// Function:  InsertAt	
	// Param[in]: arr			The input word array.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Param[in]: newItem	    Specifies the element value to insert.
	// Param[in]: nCount		Specifies the count of the element to insert.
	// Return:    void
	// Remarks:   Inserts one or more continuous element at specified position.
	// Notes:
	//************************************
	static void InsertAt(FS_WordArray arr, FS_INT32 index, FS_WORD newItem, FS_INT32 nCount);


	//************************************
	// Function:  RemoveAt
	// Param[in]: arr		The input word array.
	// Param[in]: index		Specifies the zero-based index in the array.
	// Param[in]: nCount	Specifies the count of element to remove.
	// Return:    void
	// Remarks:   Removes a number of elements at specified position.
	// Notes:     
	//************************************
	static void	RemoveAt(FS_WordArray arr, FS_INT32 index, FS_INT32 nCount);


	//************************************
	// Function:  InsertNewArrayAt		
	// Param[in]: arr			The input word array.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to insert at.
	// Param[in]: newArray		The input array.
	// Return:    void
	// Remarks:   Inserts an array at specified position.
	// Notes:
	//************************************
	static void	InsertNewArrayAt(FS_WordArray arr, FS_INT32 nStartIndex, FS_WordArray newArray);


	//************************************
	// Function:  Find	   
	// Param[in]: arr			The input word array.
	// Param[in]: item			The input element.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to find.
	// Return:	  An index of the found element. It can be -1 for found none.
	// Remarks:   Finds an element from specified position to last
	// Notes:
	//************************************
	static FS_INT32 Find(FS_WordArray arr, FS_WORD item, FS_INT32 nStartIndex);
};

class CFS_DWordArray_V1
{

public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty DWord array.
	// Remarks:   Creates a new empty DWord array.
	// Notes:
	//************************************
	static FS_DWordArray New(void);


	//************************************
	// Function:  Destroy	
	// Param[in]: arr			The input DWord array.
	// Return:    void
	// Remarks:   Destroys a double word array.
	// Notes:
	//************************************
	static void Destroy(FS_DWordArray arr);

	//************************************
	// Function:  GetSize	
	// Param[in]: arr			The input DWord array.
	// Return:   The number of elements in the array.
	// Remarks:   Gets the number of elements in the array.
	// Notes:
	//************************************
	static FS_INT32	GetSize(FS_DWordArray arr);


	//************************************
	// Function:  GetUpperBound	
	// Param[in]: arr			The input DWord array.
	// Return:   The upper bound.
	// Remarks:   Gets the upper bound in the array. actually the maximum valid index.
	// Notes:
	//************************************
	static FS_INT32	GetUpperBound(FS_DWordArray arr);


	//************************************
	// Function:  SetSize
	// Param[in]: arr		 The input DWord array.
	// Param[in]: nNewSize	 The new size in elements expected.
	// Param[in]: nGrowBy	 The grow amount in elements expected, nGrowBy can be -1 for the grow amount unchanged.
	// Return:    void
	// Remarks:   Changes the allocated size and the grow amount.
	// Notes:
	//************************************
	static void	SetSize(FS_DWordArray arr, FS_INT32 nNewSize, FS_INT32 nGrowBy);


	//************************************
	// Function:  RemoveAll	
	// Param[in]: arr The input DWord array.
	// Return:    void
	// Remarks:   Cleans up the array.
	// Notes:
	//************************************
	static void	RemoveAll(FS_DWordArray arr);


	//************************************
	// Function:  GetAt	
	// Param[in]: arr		The input DWord array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Return:    An element
	// Remarks:	  Retrieves an element specified by an index number.
	// Notes:
	//************************************
	static FS_DWORD GetAt(FS_DWordArray arr, FS_INT32 index);


	//************************************
	// Function:  SetAt
	// Param[in]: arr		The input DWord array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Param[in]: newItem	An element
	// Return:    void
	// Remarks:	  Overwrites an element specified by an index number.
	// Notes:
	//************************************
	static void SetAt(FS_DWordArray arr, FS_INT32 index, FS_DWORD newItem);


	//************************************
	// Function:  SetAtGrow
	// Param[in]: arr		The input DWord array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Param[in]: newItem	The input element.
	// Return:    void
	// Remarks:	  Sets an element value at specified position. Potentially growing the array.
	// Notes:
	//************************************
	static void SetAtGrow(FS_DWordArray arr, FS_INT32 index, FS_DWORD newItem);


	//************************************
	// Function:  Add
	// Param[in]: arr		The input DWord array.
	// Param[in]: newItem	The input element.
	// Return:    The added element's index.
	// Remarks:   Adds an element at the tail. Potentially growing the array
	// Notes:    
	//************************************
	static FS_INT32 Add(FS_DWordArray arr, FS_DWORD newItem);


	//************************************
	// Function:  Append	
	// Param[in]: arr		The input DWord array.
	// Param[in]: srcArr	The input array.
	// Return:    The old size in elements.
	// Remarks:	  Appends an array.
	// Notes:
	//************************************
	static FS_INT32 Append(FS_DWordArray arr, const FS_DWordArray srcArr);


	//************************************
	// Function:  Copy	
	// Param[in]: arr		The input DWord array.
	// Param[in]: srcArr	The input array.
	// Return:    void
	// Remarks:   Copies from an array.
	// Notes:
	//************************************
	static void	Copy(FS_DWordArray arr, FS_DWordArray srcArr);

	//************************************
	// Function:    GetDataPtr
	// Param[in]: arr		The input DWord array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Return:    A pointer to the specified element.
	// Remarks:   Gets a pointer to the specified element in the array. Direct pointer access.
	// Notes:
	//************************************
	static FS_DWORD* GetDataPtr(FS_DWordArray arr, FS_INT32 index);

	//************************************
	// Function:  InsertAt	
	// Param[in]: arr			The input DWord array.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Param[in]: newItem	    Specifies the element value to insert.
	// Param[in]: nCount		Specifies the count of the element to insert.
	// Return:    void
	// Remarks:   Inserts one or more continuous element at specified position.
	// Notes:
	//************************************
	static void InsertAt(FS_DWordArray arr, FS_INT32 index, FS_DWORD newItem, FS_INT32 nCount);


	//************************************
	// Function:  RemoveAt
	// Param[in]: arr		The input DWord array.
	// Param[in]: index		Specifies the zero-based index in the array.
	// Param[in]: nCount	Specifies the count of element to remove.
	// Return:    void
	// Remarks:   Removes a number of elements at specified position.
	// Notes:     
	//************************************
	static void	RemoveAt(FS_DWordArray arr, FS_INT32 index, FS_INT32 nCount);


	//************************************
	// Function:  InsertNewArrayAt		
	// Param[in]: arr			The input DWord array.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to insert at.
	// Param[in]: newArray		The input array.
	// Return:    void
	// Remarks:   Insets an array at specified position.
	// Notes:
	//************************************
	static void	InsertNewArrayAt(FS_DWordArray arr, FS_INT32 nStartIndex, FS_DWordArray newArray);

	//************************************
	// Function:  Find	   
	// Param[in]: arr			The input DWord array.
	// Param[in]: item			The input element.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to find.
	// Return:	  An index of the found element. It can be -1 for found none.
	// Remarks:   Finds an element from specified position to last
	// Notes:
	//************************************
	static FS_INT32 Find(FS_DWordArray arr, FS_DWORD item, FS_INT32 nStartIndex);
	
	 //************************************
	 // Function:  GetData	   
	 // Param[in]: arr			The input DWord array.	
	 // Return:	 Get the element data.
	 // Remarks:  Direct Access to the element data.
	 // Notes:
	 //************************************
	static  FS_DWORD* GetData(FS_DWordArray arr);
};

class CFS_ByteStringArray_V1
{

public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty byte-string array.
	// Remarks:   Creates a new empty byte-string array.
	// Notes:
	//************************************
	static FS_ByteStringArray New(void);


	//************************************
	// Function:  Destroy	
	// Param[in]: arr			The input byte-string array.
	// Return:    void
	// Remarks:   Destroys the byte-string array.
	// Notes:
	//************************************
	static void Destroy(FS_ByteStringArray arr);

	//************************************
	// Function:  GetAt	
	// Param[in]: arr		The input byte-string array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Param[out]: outByteString It retrieves an element specified by an index number.
	// Return:    void
	// Remarks:	  Retrieves an element specified by an index number.
	// Notes:
	//************************************
	static void GetAt(FS_ByteStringArray arr, FS_INT32 index, FS_ByteString* outByteString);

	//************************************
	// Function:  GetSize	
	// Param[in]: arr			The input byte-string array.
	// Return:   The number of elements in the array.
	// Remarks:   Gets the number of elements in the array.
	// Notes:
	//************************************
	static FS_INT32	GetSize(FS_ByteStringArray arr);


	//************************************
	// Function:  RemoveAll	
	// Param[in]: arr The input byte-string array.
	// Return:    void
	// Remarks:   Cleans up the array.
	// Notes:
	//************************************
	static void	RemoveAll(FS_ByteStringArray arr);


	//************************************
	// Function:  Add
	// Param[in]: arr		The input byte-string array.
	// Param[in]: newItem	The input element.
	// Param[in]: newItem	The length.
	// Return:    void
	// Remarks:   Adds an element at the tail. Potentially growing the array
	// Notes:    
	//************************************
	static void Add(FS_ByteStringArray arr, FS_LPSTR newItem, FS_INT32 nLen);


	//************************************
	// Function:  RemoveAt
	// Param[in]: arr		The input byte-string array.
	// Param[in]: index		Specifies the zero-based index in the array.
	// Return:    void
	// Remarks:   Removes a number of elements at specified position.
	// Notes:     
	//************************************
	static void	RemoveAt(FS_ByteStringArray arr, FS_INT32 index);

	//************************************
	// Function:  Add2
	// Param[in]: arr		The input byte-string array.
	// Param[in]: bsNew		The new byte string.
	// Return:    void
	// Remarks:   Add a copy of an existing object to the array.
	// Notes:     
	//************************************
	static void	Add2(FS_ByteStringArray arr, FS_ByteString bsNew);

	//************************************
	// Function:  GetDataPtr	
	// Param[in]: arr		The input byte-string array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Return:    Gets the pointer to the specified element.
	// Remarks:	  The pointer to the specified element.
	// Notes:
	//************************************
	static FS_ByteString GetDataPtr(FS_ByteStringArray arr, FS_INT32 index);

};

class CFS_WideStringArray_V1
{

public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty wide-string array.
	// Remarks:   Creates a new empty wide-string array.
	// Notes:
	//************************************
	static FS_WideStringArray New(void);


	//************************************
	// Function:  Destroy	
	// Param[in]: arr The input wide-string array.
	// Return:    void
	// Remarks:   Destroys the wide-string array.
	// Notes:
	//************************************
	static void Destroy(FS_WideStringArray arr);

	//************************************
	// Function:  GetAt	
	// Param[in]: arr			The input wide-string array.
	// Param[in]: index			Specifies the zero-based index of the element.
	// Param[out]: outWideString Retrieves an element specified by an index number.
	// Return:    void
	// Remarks:	  Retrieves an element specified by an index number.
	// Notes:
	//************************************
	static void GetAt(FS_WideStringArray arr, FS_INT32 index, FS_WideString* outWideString);

	//************************************
	// Function:  GetSize	
	// Param[in]: arr		The input wide-string array.
	// Return:   The number of elements in the array.
	// Remarks:   Gets the number of elements in the array.
	// Notes:
	//************************************
	static FS_INT32	GetSize(FS_WideStringArray arr);


	//************************************
	// Function:  RemoveAll	
	// Param[in]: arr		The input wide-string array.
	// Return:    void
	// Remarks:   Cleans up the array.
	// Notes:
	//************************************
	static void	RemoveAll(FS_WideStringArray arr);


	//************************************
	// Function:  Add
	// Param[in]: arr		The input wide-string array.
	// Param[in]: newItem	The input element.
	// Return:    void
	// Remarks:   Adds an element at the tail. Potentially growing the array
	// Notes:    
	//************************************
	static void Add(FS_WideStringArray arr, FS_LPCWSTR newItem);


	//************************************
	// Function:  RemoveAt
	// Param[in]: arr		The input wide-string array.
	// Param[in]: index		Specifies the zero-based index in the array.
	// Return:    void
	// Remarks:   Removes a number of elements at specified position.
	// Notes:     
	//************************************
	static void	RemoveAt(FS_WideStringArray arr, FS_INT32 index);

	//************************************
	// Function:  Add2
	// Param[in]: arr		The input wide-string array.
	// Param[in]: newItem	The input element.
	// Return:    void
	// Remarks:   Adds an element at the tail. Potentially growing the array
	// Notes:    
	//************************************
	static void Add2(FS_WideStringArray arr, FS_WideString newItem);

	//************************************
	// Function:  Copy
	// Param[in]: arr		The input wide-string array.
	// Param[in]: srcarr	The source array.
	// Param[in]: nStart	The starting position to be copied in source array. Default value: 0
	// Param[in]: nCount	The total count of source elements to be copied, -1 means all elements from nStart position.
	//                      Default value : -1.
	// Return:    FS_INT32  The number of copied elements from source array.
	// Remarks:  Copy from an array.
	// Notes:    
	//************************************
	static FS_INT32 Copy(FS_WideStringArray arr, FS_WideStringArray srcarr, FS_INT32 nStart, FS_INT32 nCount);
};

class CFS_CodeTransformation_V1
{
public:
	//************************************
	// Function:  NameDecode	
	// Param[in]: orig				The input buffered name of lexical form.
	// Param[out]:outDecodedName	The decoded name.
	// Return:    void
	// Remarks:   Decode a name from it lexical form, From a buffered name of lexical form.
	// Notes:
	//************************************
	static void NameDecode(FS_ByteString orig, FS_ByteString* outDecodedName);


	//************************************
	// Function:   NameEncode	
	// Param[in]:  orig					The input name.
	// Param[out]: outDecodedName		A lexical form of the name.
	// Return:     void
	// Remarks:    Encode a name to lexical form (to be used for output).
	// Notes:
	//************************************
	static void NameEncode(FS_ByteString orig, FS_ByteString* outDecodedName);


	//************************************
	// Function:  EncodeString	
	// Param[in]: src					The input string.
	// Param[in]: bHex					Whether we will do hex-encoding.
	// Param[out]:outEncodedString		The PDF formatted string.
	// Return:    void
	// Remarks:   A PDF formatted string (including () or <>).
	// Notes:
	//************************************
	static void EncodeString(FS_ByteString src, FS_BOOL bHex, FS_ByteString* outEncodedString);


	//************************************
	// Function:  DecodeText
	// Param[in]: str				The input PDF encoded text string.
	// Param[in]: charMap			The input character mapping.
	// Param[out]:outDecodeText		A Unicode encoded string.
	// Return:    void
	// Remarks:   Decode PDF encoded text string into a Unicode encoded string, from a byte string.
	// Notes:     If no char map specified, PDFDocEncoding is used.
	//************************************
	static void DecodeText(FS_ByteString str, FS_CharMap charMap, FS_WideString* outDecodeText);



	//************************************
	// Function:   DecodeText2	
	// Param[in]:  pData			The input PDF encoded text buffer.
	// Param[in]:  size				The size in bytes of the buffer.
	// Param[in]:  charMap			The input character mapping.
	// Param[out]: outDecodeText	A Unicode encoded string.
	// Return:     void
	// Remarks:    Decode PDF encoded text string into a Unicode encoded string, from a memory block.	
	// Notes:      If no char map specified, PDFDocEncoding is used.
	//************************************
	static void DecodeText2(FS_LPBYTE pData, FS_DWORD size, FS_CharMap charMap, FS_WideString* outDecodeText);


	//************************************
	// Function:  EncodeText	
	// Param[in]: pString			The input Unicode text string (UTF-16LE).
	// Param[in]: len				The length of the input unicode string. -1 for zero-terminated Unicode string.
	// Param[in]: charMap			The input character mapping.
	// Param[out]: outEncodeText	The PDF encoded string.
	// Return:    void
	// Remarks:   Encode a Unicode text string (UTF-16LE) into PDF encoding.
	// Notes:     If no char map specified, PDFDocEncoding is used.
	//************************************
	static void EncodeText(FS_LPWORD pString, FS_INT32 len, FS_CharMap charMap, FS_ByteString* outEncodeText);

	//************************************
	// Function:  FlateEncodeProc
	// Param[in]: src_buf		The source data.
	// Param[in]: src_size		The size in bytes of the source data.
	// Param[out]: dest_buf		It will receive the encoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
	// Param[out]: dest_size	It will receive the size in bytes of the encoded data.
	// Return: void
	// Remarks: Flate encode algorithm.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FSCodeTransformationFlateDecodeProc
	//************************************
	static void FlateEncodeProc(FS_LPCBYTE src_buf, FS_DWORD src_size, FS_LPBYTE* dest_buf, FS_DWORD* dest_size);

	//************************************
	// Function:  FlateDecodeProc
	// Param[in]: src_buf		The source encoded data.
	// Param[in]: src_size		The size in bytes of the source encoded data.
	// Param[out]: dest_buf		It will receive the decoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
	// Param[out]: dest_size	It will receive the size in bytes of the decoded data.
	// Return: The size in bytes of source data consumed.
	// Remarks: Flate decode algorithm.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FSCodeTransformationFlateEncodeProc
	//************************************
	static FS_DWORD FlateDecodeProc(FS_LPCBYTE src_buf, FS_DWORD src_size, FS_LPBYTE* dest_buf, FS_DWORD* dest_size);

	//************************************
	// Function:  RunLengthDecodeProc
	// Param[in]: src_buf		The source encoded data.
	// Param[in]: src_size		The size in bytes of the source encoded data.
	// Param[out]: dest_buf		It will receive the decoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
	// Param[out]: dest_size	It will receive the size in bytes of the decoded data.
	// Return: The size in bytes of source data consumed.
	// Remarks: Run-length decode algorithm.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FSCodeTransformationRunLengthEncodeProc
	//************************************
	static FS_DWORD RunLengthDecodeProc(FS_LPCBYTE src_buf, FS_DWORD src_size, FS_LPBYTE* dest_buf, FS_DWORD* dest_size);

	//************************************
	// Function:  RunLengthEncodeProc
	// Param[in]: src_buf		The source data.
	// Param[in]: src_size		The size in bytes of the source data.
	// Param[out]: dest_buf		It will receive the encoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
	// Param[out]: dest_size	It will receive the size in bytes of the encoded data.
	// Return:    
	// Remarks: Run-length encode algorithm.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FSCodeTransformationRunLengthDecodeProc
	//************************************
	static FS_BOOL RunLengthEncodeProc(FS_LPCBYTE src_buf, FS_DWORD src_size, FS_LPBYTE* dest_buf, FS_DWORD* dest_size);

	//************************************
	// Function:  MemFree
	// Param[in]: pointer The pointer to free;
	// Return:   void. 
	// Remarks: Free the pointer;
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void MemFree(void* pointer);

	//************************************
	// Function:  BasicModuleA85Encode
	// Param[in]: src_buf		The source data.
	// Param[in]: src_size		The size in bytes of the source data.
	// Param[out]: dest_buf		It will receive the encoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
	// Param[out]: dest_size	It will receive the size in bytes of the encoded data.
	// Return: <a>TRUE</a> for success, <a>FALSE</a> for failure.
	// Remarks: A85 encode algorithm. This interface is for internal use only now.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL BasicModuleA85Encode(FS_LPCBYTE src_buf, FS_DWORD src_size, FS_LPBYTE* dest_buf, FS_DWORD* dest_size);

	//************************************
	// Function:  FlateModuleEncode
	// Param[in]: src_buf		The source data.
	// Param[in]: src_size		The size in bytes of the source data.
	// Param[out]: dest_buf		It will receive the encoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
	// Param[out]: dest_size	It will receive the size in bytes of the encoded data.
	// Return: <a>TRUE</a> for success, <a>FALSE</a> for failure.
	// Remarks: Flate module encode. This interface is for internal use only now.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_BOOL FlateModuleEncode(FS_LPCBYTE src_buf, FS_DWORD src_size, FS_LPBYTE* dest_buf, FS_DWORD* dest_size);

	//************************************
	// Function:  FlateModuleEncode2
	// Param[in]: src_buf			The source data.
	// Param[in]: src_size			The size in bytes of the source data.
	// Param[in]: predictor			The input predictor.
	// Param[in]: Colors			The input colors.
	// Param[in]: BitsPerComponent	The input bits per component.
	// Param[in]: Columns			The input columns.
	// Param[out]: dest_buf			It will receive the encoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
	// Param[out]: dest_size		It will receive the size in bytes of the encoded data.
	// Return: <a>TRUE</a> for success, <a>FALSE</a> for failure.
	// Remarks: Flate module encode. This interface is for internal use only now.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_BOOL FlateModuleEncode2(FS_LPCBYTE src_buf, FS_DWORD src_size, FS_INT32 predictor, FS_INT32 Colors, FS_INT32 BitsPerComponent, FS_INT32 Columns, FS_LPBYTE* dest_buf, FS_DWORD* dest_size);
	
	 //************************************
	 // Function:  PngModuleEncode
	 // Param[in]: pSource			The source image to be encoded.
	 // Param[in]: dest_buf			It receives the encoded PNG data.
	 // Param[in]: dest_size		It receives the size of the encoded PNG data.
	 // Param[in]: bInterlace		Whether the PNG file be interlace(7 passes)
	 // Param[in]: pAttribute	    The attribute information of bitmap.
	 // Return: return Non-zero means success, otherwise failure.
	 // Remarks: Encode an image to a memory block, the return buffer must be free by FX_Free.
	 // Notes: You need to call FSCodeTransformationReleaseEncodeBuffer to release buffer.
	 // Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	 //************************************
	static FS_BOOLEAN	PngModuleEncode(const FS_DIBitmap pSource, FS_LPBYTE* dest_buf, FS_DWORD* dest_size, FS_BOOLEAN bInterlace, FS_DIBAttribute pAttribute);

	//************************************
	// Function:  ReleaseEncodeBuffer
	// Param[in]: dest_buf			The source image to be encoded.	
	// Return: 
	// Remarks: Release encode buffer, because the buffer malloc from exe, so need to release in exe.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void ReleaseEncodeBuffer(FS_LPBYTE dest_buf);
	
	//************************************
	// Function:  GetUnicodeProperties
	// Param[in]: wch			The input char.	
	// Return: 
	// Remarks: Retrieve unicode properties list
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_DWORD  GetUnicodeProperties(FS_WCHAR wch);

	//************************************
	// Function:  EncodeText2	
	// Param[in]: pString			The input Unicode text string (UTF-16LE).
	// Param[in]: len				The length of the input unicode string. -1 for zero-terminated Unicode string.
	// Param[in]: charMap			The input character mapping.
	// Param[out]: outEncodeText	The PDF encoded string.
	// Return:    void
	// Remarks:   Encode a Unicode text string (UTF-16LE) into PDF encoding.
	// Notes:     If no char map specified, PDFDocEncoding is used.
	//************************************
	static void EncodeText2(FS_LPCWSTR pString, FS_INT32 len, FS_CharMap charMap, FS_ByteString* outEncodeText);
};



class CFS_FloatRectArray_V1
{

public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty float rectangle array.
	// Remarks:   Creates a new empty float rectangle array.
	// Notes:
	//************************************
	static FS_FloatRectArray New(void);


	//************************************
	// Function:  Destroy	
	// Param[in]: arr			The input float rectangle array.
	// Return:    void
	// Remarks:   Destroys the float rectangle array.
	// Notes:
	//************************************
	static void Destroy(FS_FloatRectArray arr);

	//************************************
	// Function:  GetSize	
	// Param[in]: arr			The input float rectangle array.
	// Return:    The number of elements in the array.
	// Remarks:   Gets the number of elements in the array.
	// Notes:
	//************************************
	static FS_INT32	GetSize(FS_FloatRectArray arr);


	//************************************
	// Function:  GetUpperBound	
	// Param[in]: arr			The input float rectangle array.
	// Return:    The upper bound.
	// Remarks:   Gets the upper bound in the array. actually the maximum valid index.
	// Notes:
	//************************************
	static FS_INT32	GetUpperBound(FS_FloatRectArray arr);


	//************************************
	// Function:  SetSize
	// Param[in]: arr		 The input float rectangle array.
	// Param[in]: nNewSize	 The new size in elements expected.
	// Param[in]: nGrowBy	 The grow amount in elements expected, nGrowBy can be -1 for the grow amount unchanged.
	// Return:    void
	// Remarks:   Changes the allocated size and the grow amount.
	// Notes:
	//************************************
	static void	SetSize(FS_FloatRectArray arr, FS_INT32 nNewSize, FS_INT32 nGrowBy);


	//************************************
	// Function:  RemoveAll	
	// Param[in]: arr		The input float rectangle array.
	// Return:    void
	// Remarks:   Cleans up the array.
	// Notes:
	//************************************
	static void	RemoveAll(FS_FloatRectArray arr);


	//************************************
	// Function:  GetAt	
	// Param[in]: arr		The input float rectangle array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Return:    An element
	// Remarks:	  Retrieves an element specified by an index number.
	// Notes:
	//************************************
	static FS_FloatRect GetAt(FS_FloatRectArray arr, FS_INT32 index);


	//************************************
	// Function:  SetAt
	// Param[in]: arr		The input float rectangle array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Param[in]: newItem	An element
	// Return:    void
	// Remarks:	  Overwrites an element specified by an index number.
	// Notes:
	//************************************
	static void SetAt(FS_FloatRectArray arr, FS_INT32 index, FS_FloatRect newItem);


	//************************************
	// Function:  SetAtGrow
	// Param[in]: arr		The input float rectangle array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Param[in]: newItem	The input element.
	// Return:    void
	// Remarks:	  Sets an element value at specified position. Potentially growing the array.
	// Notes:
	//************************************
	static void SetAtGrow(FS_FloatRectArray arr, FS_INT32 index, FS_FloatRect newItem);


	//************************************
	// Function:  Add
	// Param[in]: arr		The input float rectangle array.
	// Param[in]: newItem	The input element.
	// Return:    The added element's index.
	// Remarks:   Adds an element at the tail. Potentially growing the array
	// Notes:    
	//************************************
	static FS_INT32 Add(FS_FloatRectArray arr, FS_FloatRect newItem);


	//************************************
	// Function:  Append	
	// Param[in]: arr		The input float rectangle array.
	// Param[in]: srcArr	The input array.
	// Return:   The old size in elements.
	// Remarks:	  Appends an array.
	// Notes:
	//************************************
	static FS_INT32 Append(FS_FloatRectArray arr, const FS_FloatRectArray srcArr);


	//************************************
	// Function:  Copy
	// Param[in]: arr		The input float rectangle array.
	// Param[in]: srcArr	The input array.
	// Return:    void
	// Remarks:   Copies from an array.
	// Notes:
	//************************************
	static void	Copy(FS_FloatRectArray arr, FS_FloatRectArray srcArr);


	//************************************
	// Function:  InsertAt	
	// Param[in]: arr			The input float rectangle array.		
	// Param[in]: index			Specifies the zero-based index in the array.
	// Param[in]: newItem	    Specifies the element value to insert.
	// Param[in]: nCount		Specifies the count of the element to insert.
	// Return:    void
	// Remarks:   Insets one or more continuous element at specified position.
	// Notes:
	//************************************
	static void InsertAt(FS_FloatRectArray arr, FS_INT32 index, FS_FloatRect newItem, FS_INT32 nCount);


	//************************************
	// Function:  RemoveAt
	// Param[in]: arr		The input float rectangle array.
	// Param[in]: index		Specifies the zero-based index in the array.
	// Param[in]: nCount	Specifies the count of element to remove.
	// Return:    void
	// Remarks:   Removes a number of elements at specified position.
	// Notes:     
	//************************************
	static void	RemoveAt(FS_FloatRectArray arr, FS_INT32 index, FS_INT32 nCount);


	//************************************
	// Function:  InsertNewArrayAt		
	// Param[in]: arr			The input float rectangle array.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to insert at.
	// Param[in]: newArray		The input array.
	// Return:    void
	// Remarks:   Insets an array at specified position.
	// Notes:
	//************************************
	static void	InsertNewArrayAt(FS_FloatRectArray arr, FS_INT32 nStartIndex, FS_FloatRectArray newArray);


	//************************************
	// Function:  Find	   
	// Param[in]: arr			The input float rectangle array.
	// Param[in]: item			The input element.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to find.
	// Return:	  An index of the found element. It can be -1 for found none.
	// Remarks:   Finds an element from specified position to last
	// Notes:
	//************************************
	static FS_INT32 Find(FS_FloatRectArray arr, FS_FloatRect item, FS_INT32 nStartIndex);
};

//////////////////////////////////////////////////////////////////////////
//class CFS_BinaryBuf_V1

class CFS_BinaryBuf_V1
{
public:
	
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty binary buffer.
	// Remarks:   Creates a new empty binary buffer.
	// Notes:
	//************************************
	static FS_BinaryBuf	New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: buf The input binary buffer.
	// Return:    void
	// Remarks:   Destroys the binary buffer.
	// Notes:
	//************************************
	static void	 Destroy(FS_BinaryBuf buf);

	//************************************
	// Function:  Clear
	// Param[in]: buf The input binary buffer. 
	// Return:    void
	// Remarks:   Sets the binary buffer to be empty.
	// Notes:
	//************************************
	static void	Clear(FS_BinaryBuf buf);

	//************************************
	// Function:  EstimateSize
	// Param[in]: buf			The input binary buffer.
	// Param[in]: size			The new size expected.
	// Param[in]: allocStep		The new allocation step. If <param>allocstep</param> is 0, then the allocation step will not change.
	// Return:    void
	// Remarks:   Changes the allocated buffer size, and set the allocation step if <param>allocstep</param> is non-zero.
	// Notes:
	//************************************
	static void EstimateSize(FS_BinaryBuf buf, FS_StrSize size, FS_StrSize allocStep);

	//************************************
	// Function:  AppendBlock
	// Param[in]: buf		The input binary buffer.	
	// Param[in]: pBuf		A pointer to a binary buffer block.
	// Param[in]: size		The size in bytes of the buffer block.
	// Return:    void
	// Remarks:   Appends a binary buffer block.
	// Notes:
	//************************************
	static void	AppendBlock(FS_BinaryBuf buf, void* pBuf, FS_StrSize size);

	//************************************
	// Function:  AppendFill
	// Param[in]: buf		The input binary buffer.
	// Param[in]: byte		The input byte.
	// Param[in]: count		Number of times.
	// Return:    void
	// Remarks:   Appends a byte for specified number times. Not a byte-by-byte processing, but a byte filling processing internally.
	// Notes:
	//************************************
	static void	AppendFill(FS_BinaryBuf buf, FS_BYTE byte, FS_StrSize count);

	//************************************
	// Function:  AppendString
	// Param[in]: buf		The input binary buffer.
	// Param[in]: str		A no-buffered byte string.
	// Return:    void
	// Remarks:   Appends a non-buffered byte string.
	// Notes:
	//************************************
	static void	AppendString(FS_BinaryBuf buf, FS_CHAR* str);

	//************************************
	// Function:  AppendByte
	// Param[in]: buf		The input binary buffer.
	// Param[in]: byte		A single byte.
	// Return:    void
	// Remarks:   Appends a single byte.
	// Notes:
	//************************************
	static void	AppendByte(FS_BinaryBuf buf, FS_BYTE byte); 

	//************************************
	// Function:  InsertBlock
	// Param[in]: buf		The input binary buffer.
	// Param[in]: pos		Specifies the zero-based index of the position in the binary buffer.
	// Param[in]: pBuf		A pointer to a binary buffer block.
	// Param[in]: size		The size in bytes of the buffer block.
	// Return:    void
	// Remarks:   Insert a binary buffer block at the specified position.
	// Notes:
	//************************************
	static void InsertBlock(FS_BinaryBuf buf, FS_StrSize pos, const void* pBuf, FS_StrSize size);

	//************************************
	// Function:  AttachData
	// Param[in]: buf		The input binary buffer.
	// Param[in]: pBuf		A pointer to a binary buffer.
	// Param[in]: size		The size in bytes of the buffer.
	// Return:    void
	// Remarks:   Attach to a buffer (this buffer will belong to this object). The buffer must be allocated by FS_Alloc.
	// Notes:
	//************************************
	static void	AttachData(FS_BinaryBuf buf, void* pBuf, FS_StrSize size);

	//************************************
	// Function:  CopyData
	// Param[in]: buf		The input binary buffer.
	// Param[in]: pBuf		The input another buffer.
	// Param[in]: size		The size in bytes of the buffer.
	// Return:    void
	// Remarks:   Copies from another buffer.
	// Notes:
	//************************************
	static void CopyData(FS_BinaryBuf buf, const void* pBuf, FS_StrSize size);

	//************************************
	// Function:  TakeOver
	// Param[in]: buf		The input binary buffer.
	// Param[in]: other		Another buffer
	// Return:    void
	// Remarks:   Takeover another buffer. 
	// Notes:     It attaches to the source FS_BinaryBuf object's buffer; The source FS_BinaryBuf object
	//   has detached the buffer.
	//************************************
	static void	TakeOver(FS_BinaryBuf buf, FS_BinaryBuf other);

	//************************************
	// Function:  Delete
	// Param[in]: buf			The input binary buffer.
	// Param[in]: startIndex	Specifies the zero-based index of the start position to be deleted in the binary buffer.
	// Param[in]: count			Specifies the length in bytes to be deleted.
	// Return:    void
	// Remarks:   Delete a inter-zone buffer defining by parameters start_index and count in the binary buffer.
	// Notes:
	//************************************
	static void Delete(FS_BinaryBuf buf, FS_INT32 startIndex, FS_INT32 count);

	//************************************
	// Function:  GetBuffer
	// Param[in]: buf			The input binary buffer.
	// Return:    A byte pointer to the binary buffer.
	// Remarks:   Gets a byte pointer to the binary buffer.
	// Notes:
	//************************************
	static FS_LPBYTE GetBuffer(FS_BinaryBuf buf);

	//************************************
	// Function:  GetSize
	// Param[in]: buf		The input binary buffer.
	// Return:    The length in bytes of the binary buffer.
	// Remarks:   Gets the length of the binary buffer.
	// Notes:
	//************************************
	static FS_StrSize GetSize(FS_BinaryBuf buf);

	//************************************
	// Function:  GetByteString
	// Param[in]: buf			The input binary buffer.
	// Param[out]:outString		A byte string result.
	// Return:    void
	// Remarks:   Gets a byte string from the buffer.
	// Notes:
	//************************************
	static void	GetByteString(FS_BinaryBuf buf, FS_ByteString* outString);

	//************************************
	// Function:  DetachBuffer
	// Param[in]: buf			The input binary buffer.
	// Return:    void
	// Remarks:   Detachs the buffer. Just set buffer pointer to NULL, and set the binary buffer size to zero.
	// Notes:
	//************************************
	static void	DetachBuffer(FS_BinaryBuf buf);	
};

#ifndef CFS_CUSTOMERPAUSE
#define CFS_CUSTOMERPAUSE
class CFS_CustomerPauseHandler : public IFX_Pause, public CFX_Object
{
public:
	CFS_CustomerPauseHandler(FS_Pause pause);
	virtual FX_BOOL	NeedToPauseNow();
private:
	FS_Pause m_pause;
};
#endif

//////////////////////////////////////////////////////////////////////////
//class CFS_PauseHandler_V1

class CFS_PauseHandler_V1
{
public:
	//************************************
	// Function: Create
	// Param[in]: pause		The input pause handler structure.
	// Return:   The newly created pause handler.
	// Remarks:  Creates the pause handler.
	// Notes:
	//************************************
	static FS_PauseHandler	Create(FS_Pause pause);

	//************************************
	// Function: Destroy
	// Param[in]: pauseHandler		The input pause handler to be destroyed.
	// Return:   void
	// Remarks:  Destroys the pause handler.
	// Notes:
	//************************************
	static void	Destroy(FS_PauseHandler pauseHandler);

   //************************************
   // Function: NeedToPauseNow
   // Param[in]: pauseHandler    The input pause handler to be destroyed.
   // Return:   Non-zero means we need, otherwise we need not.
   // Remarks:  
   // Notes:
   //************************************
	static FS_BOOLEAN NeedToPauseNow(FS_PauseHandler pauseHandler);
};


class CFPD_CustomerFileReadHandler : public IFX_FileRead, public CFX_Object
{
public:
	CFPD_CustomerFileReadHandler(FS_FileRead fileRead);
	virtual FX_FILESIZE	GetSize();
	virtual FX_BOOL		ReadBlock(void* buffer, FX_FILESIZE offset, size_t size);
	virtual void		Release();

	FS_FileRead m_fileRead;
};


//////////////////////////////////////////////////////////////////////////
//class CFS_FileReadHandler_V1

class CFS_FileReadHandler_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: fileRead The input file read callbacks.
	// Return:    The file access interface.
	// Remarks:   Creates the file access handler.
	// Notes:
	//************************************
	static FS_FileReadHandler New(FS_FileRead fileRead);

	//************************************
	// Function:  Destroy
	// Param[in]: fileReadHander The file access handler.
	// Return:    void
	// Remarks:   Frees  file read handler.
	// Notes:
	//************************************
	static void Destroy(FS_FileReadHandler fileReadHander);

	
	//************************************
	// Function:  GetSize
	// Param[in]: fileReadHander The file access handler.
	// Return:    File size, in bytes..
	// Remarks:   GetS total size of the file.
	// Notes:
	//************************************
	static FS_DWORD	GetSize(FS_FileReadHandler fileReadHander);

	//************************************
	// Function:  ReadBlock
	// Param[in]: fileReadHander	The file access handler.
	// Param[in,out]: buffer		Pointer to a buffer receiving read data.
	// Param[in]: offset			Byte offset for the block, from beginning of the file.
	// Param[in]: size				Number of bytes for the block.
	// Return:    <a>TRUE</a> for success, <a>FALSE</a> for failure.
	// Remarks:   Reads a data block from the file.
	// Notes:
	//************************************
	static FS_BOOL		ReadBlock(FS_FileReadHandler fileReadHander, void* buffer, FS_DWORD offset, FS_DWORD size);

	//************************************
	// Function:  New2
	// Param[in]: fileRead The input file read callbacks.
	// Return:    The file access interface.
	// Remarks:   Creates the file access handler from file path name.
	// Notes:
	//************************************
	static FS_FileReadHandler New2(FS_LPCSTR filename);

	//************************************
	// Function:  New3
	// Param[in]: fileRead The input file read callbacks.
	// Return:    The file access interface.
	// Remarks:   Creates the file access handler from file path name(UNICODE).
	// Notes:
	//************************************
	static FS_FileReadHandler New3(FS_LPCWSTR filename);	

	//************************************
	// Function:  IsEOF
	// Param[in]: fileStream    The input file stream object.
	// Return:    FS_INT64      @return <b>true</b> means reach the end of stream, and <b>false</b> means not yet.
	// Remarks:  brief Determine whether reach the end of stream.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOLEAN				IsEOF(FS_FileReadHandler fileReadHander);

	//************************************
	// Function:  GetPosition
	// Param[in]: fileStream    The input file stream object.
	// Return:    FS_INT64      return Current reading position.
	// Remarks:  brief Get the current reading position in stream.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_INT64			GetPosition(FS_FileReadHandler fileReadHander);

	//************************************
	// Function:  ReadBlock2
	// Param[in]: fileStream    The input file stream object.
	// Param[in,out] buffer     Buffer to store data.
	// Param[in] size	         Total size of buffer, in bytes.
	// Return:    FS_UINT       return The length of data stored in buffer. If returns 0, means error or no data.
	// Remarks:  brief Read data block from stream.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_UINT				ReadBlock2(FS_FileReadHandler fileReadHander, FS_LPVOID buffer, FS_UINT size);

	 //************************************
	 // Function:  SetRange
	 // Param[in]: fileStream    The input file stream object.
	 // Param[in] offset         Set the offset of range.
	 // Param[in] size	         Set size of range.
	 // Return:    FS_BOOLEAN       <b>true</b> means success, and <b>false</b> means failure.
	 // Remarks:  Set accessing range.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	 //************************************
	static FS_BOOLEAN			SetRange(FS_FileReadHandler fileReadHander, FS_INT64 offset, FS_INT64 size);
};

class CFPD_CustomerStreamWriteHandler : public IFX_StreamWrite, public CFX_Object
{
public:
	CFPD_CustomerStreamWriteHandler(FS_StreamWrite streamWrite);
	virtual FX_BOOL		WriteBlock(const void* pData, size_t size);
	virtual void		Release();
	
	FS_StreamWrite m_streamWrite;
};

//////////////////////////////////////////////////////////////////////////
//class CFS_StreamWriteHandler_V1

class CFS_StreamWriteHandler_V1
{
public:
	//************************************
	// Function:  New
	// Param[in]: streamWrite The input stream write callbacks.
	// Return:    The stream access interface.
	// Remarks:   Creates the stream access handler.
	// Notes:
	//************************************
	static FS_StreamWriteHandler New(FS_StreamWrite streamWrite);

	//************************************
	// Function:  Destroy
	// Param[in]: streamWritehandler The stream access handler.
	// Return:    void
	// Remarks:   Frees stream write handler.
	// Notes:
	//************************************
	static void Destroy(FS_StreamWriteHandler streamWritehandler);

	//************************************
	// Function:  WriteBlock
	// Param[in]: streamWritehandler	The stream access handler.
	// Param[in]: pData					The block data.
	// Param[in]: size					The length in bytes of the block data.
	// Return:    <a>TRUE</a> for success, <a>FALSE</a> for failure.
	// Remarks:   Write a block data.
	// Notes:
	//************************************
	static FS_BOOL	WriteBlock(FS_StreamWriteHandler streamWritehandler, const void* pData, FS_DWORD size);
};

//////////////////////////////////////////////////////////////////////////
//class CFS_Base64Encoder_V2
class CFS_Base64Encoder_V2
{
public:
	//************************************
	// Function:  New
	// Param[in]: wEqual	The input character used as a suffix purposes. Sets it <Italic>=</Italic> as default.
	// Return: The Base64 encoder object.
	// Remarks: Creates the Base64 encoder object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64EncoderDestroy
	//************************************
	static FS_Base64Encoder New(FS_WCHAR wEqual);

	//************************************
	// Function:  Destroy
	// Param[in]: encoder	The input Base64 encoder object.
	// Return:    void
	// Remarks: Destroys the input Base64 encoder object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64EncoderNew
	//************************************
	static void		Destroy(FS_Base64Encoder encoder);

	//************************************
	// Function:  SetEncoder
	// Param[in]: encoder		The input Base64 encoder object.
	// Param[in]: pEncodeProc	Callback function address to provide an external encoder. Sets it as NULL if need use default Base64 encoder.
	// Return:    void
	// Remarks: Sets external Base64 encoder.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64EncoderNew
	//************************************
	static void		SetEncoder(FS_Base64Encoder encoder, FS_LPBase64EncodeProc* pEncodeProc);

	//************************************
	// Function:  Encode
	// Param[in]: encoder	The input Base64 encoder object.
	// Param[in]: pSrc		Source byte data array to encode.
	// Param[in]: iSrcLen	The length of source byte array, in bytes.
	// Param[out]: pDst		Destination pointer of wide character array.
	// Return: Returns the length of total data stored in destination buffer, in wide characters. If <param>pDst</param> is a NULL pointer, it returns the necessary buffer size in wide characters.
	// Remarks: Encodes byte data array into a wide character array.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64EncoderNew
	//************************************
	static FS_INT32	Encode(FS_Base64Encoder encoder, FS_LPCBYTE pSrc, FS_INT32 iSrcLen, FS_LPWSTR pDst);

	//************************************
	// Function:  Encode2
	// Param[in]: encoder	The input Base64 encoder object.
	// Param[in]: src		Source byte string to encode.
	// Param[out]: out_Dst	Destination wide string to store encoded data. Creates it by <a>FSWideStringNew</a>.
	// Return: Returns the length of total data stored in destination, in wide characters.
	// Remarks: Encodes byte string into a wide string.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64EncoderNew
	//************************************
	static FS_INT32	Encode2(FS_Base64Encoder encoder, const FS_ByteString src, FS_WideString* out_Dst);

	//************************************
	// Function:  Encode3
	// Param[in]: encoder	The input Base64 encoder object.
	// Param[in]: src		Source byte string to encode.
	// Param[out]: out_Dst	Destination byte string to store encoded data. Creates it by <a>FSByteStringNew</a>.
	// Return: Returns the length of total data stored in destination, in bytes.
	// Remarks: Encodes byte string into a UTF-8 byte string.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64EncoderNew
	//************************************
	static FS_INT32	Encode3(FS_Base64Encoder encoder, const FS_ByteString src, FS_ByteString* out_Dst);

	
};

//////////////////////////////////////////////////////////////////////////
//class CFS_Base64Decoder_V2
class CFS_Base64Decoder_V2
{
public:
	//************************************
	// Function:  New
	// Param[in]: wEqual	The input character used as a suffix purposes. Sets it <Italic>=</Italic> as default.
	// Return: The Base64 decoder object.
	// Remarks: Creates the Base64 decoder object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64DecoderDestroy
	//************************************
	static FS_Base64Decoder New(FS_WCHAR wEqual);

	//************************************
	// Function:  Destroy
	// Param[in]: decoder	The input Base64 decoder object.
	// Return:    void
	// Remarks: Destroys the input Base64 decoder object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64DecoderNew
	//************************************
	static void		Destroy(FS_Base64Decoder decoder);

	//************************************
	// Function:  SetDecoder
	// Param[in]: decoder		The input Base64 decoder object.
	// Param[in]: pDecodeProc	Callback function address to provide an external decoder. Sets it as NULL if need use default Base64 decoder.
	// Return: void
	// Remarks: Sets external Base64 decoder.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64DecoderNew
	//************************************
	static void		SetDecoder(FS_Base64Decoder decoder, FS_LPBase64DecodeProc pDecodeProc);

	//************************************
	// Function:  Decode
	// Param[in]: decoder	The input Base64 decoder object.
	// Param[in]: pSrc		Source wide character array to decode.
	// Param[in]: iSrcLen	The length of source wide character array, in wide characters.
	// Param[out]: pDst		Destination pointer of byte data array.
	// Return: Returns the length of total data stored in destination buffer, in bytes. If <param>pDst</param> is a NULL pointer, it returns the necessary buffer size in bytes.
	// Remarks: Decodes wide character array into byte buffer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64DecoderNew
	//************************************
	static FS_INT32	Decode(FS_Base64Decoder decoder, FS_LPCWSTR pSrc, FS_INT32 iSrcLen, FS_LPBYTE pDst);

	//************************************
	// Function:  Decode2
	// Param[in]: decoder	The input Base64 decoder object.
	// Param[in]: src		Source wide character string to decode.
	// Param[out]: out_Dst	Destination byte string to store decoded data.
	// Return: Returns the length of total data stored in destination, in bytes.
	// Remarks: Decodes wide string into a byte string.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64DecoderNew
	//************************************
	static FS_INT32	Decode2(FS_Base64Decoder decoder, const FS_WideString src, FS_ByteString* out_Dst);

	//************************************
	// Function:  Decode3
	// Param[in]: decoder	The input Base64 decoder object.
	// Param[in]: src		Source UTF-8 byte string to decode.
	// Param[out]: out_Dst	Destination byte string to store decoded data.
	// Return: Returns the length of total data stored in destination, in bytes.
	// Remarks: Decodes UTF-8 byte string into a byte string.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSBase64DecoderNew
	//************************************
	static FS_INT32	Decode3(FS_Base64Decoder decoder, const FS_ByteString src, FS_ByteString* out_Dst);

};

//////////////////////////////////////////////////////////////////////////
//class CFS_FileWriteHandler_V2
class CFS_FileWriteHandler_V2
{
public:
	
	//************************************
	// Function:  New
	// Param[in]: fileWrite	The input file write callbacks.
	// Return: The file access interface for writing.
	// Remarks: Creates the file access handler for writing.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSFileWriteHandlerDestroy
	//************************************
	static FS_FileWriteHandler New(FS_FileWrite fileWrite);

	//************************************
	// Function:  Destroy
	// Param[in]: handler	The input file write handler.
	// Return:    void
	// Remarks: Destroys the input file write handler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSFileWriteHandlerNew
	//************************************
	static void Destroy(FS_FileWriteHandler handler);	

	//************************************
	// Function:  New2
	// Param[in]: filename	     The file path name for write.
	// Param[in]: pAllocator	 The allocator object.
	// Return: The file access interface for writing.
	// Remarks: Creates the IFX_FileWrite for writing.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FSFileWriteHandlerNew2
	//************************************
	static FS_FileWriteHandler New2(FS_LPCWSTR filename, FS_LPVOID pAllocator);
	
	//************************************
	// Function:  Release
	// Param[in]: handler	The input IFX_FileWrite obj.
	// Return: void.
	// Remarks: Called when to release everything.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FSFileWriteHandlerRelease
	//************************************
	static void			Release(FS_FileWriteHandler handler);

	 //************************************
	 // Function:  Release
	 // Param[in]: handler	The input IFX_FileWrite obj.
	 // Return: FS_UINT64.
	 // Remarks: return File size, in bytes. Implementation can return 0 for any error.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	 // See: FSFileWriteHandlerGetSize
	 //************************************
	static FS_UINT64		GetSize(FS_FileWriteHandler handler);
	
	 //************************************
	  // Function:  Flush
	  // Param[in]: handler	   The input IFX_FileWrite obj.
	  // Return: FS_BOOLEAN.   return <b>true</b> means success, while <b>false</b> means failure.
	  // Remarks: brief Flush internal buffer of the file
	  // Notes:
	  // Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	  // See: FSFileWriteHandlerGetSize
	  //************************************
	static FS_BOOLEAN			Flush(FS_FileWriteHandler handler);
	
	 //************************************
	  // Function:  WriteBlock
	  // Param[in]: handler	   The input IFX_FileWrite obj.
	  // param[in]: pData      The block data.
	  // param[in]: offset     Byte offset from beginning of the file
	  // param[in]: size       The length in bytes of the block data.
	  // Return: FS_BOOLEAN.   return <b>true</b> means success, while <b>false</b> means failure.
	  // Remarks: brief Write a block data.
	  // Notes:
	  // Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	  // See: FSFileWriteHandlerGetSize
	  //************************************
	static	FS_BOOLEAN			WriteBlock(FS_FileWriteHandler handler, const FS_LPVOID pData, FS_UINT64 offset, FS_UINT size);
	
	 //************************************
	  // Function:  WriteBlock
	  // Param[in]: handler	   The input IFX_FileWrite obj.
	  // param[in]: pData      The block data.	
	  // param[in]: size       The length in bytes of the block data.
	  // Return: FS_BOOLEAN.   return <b>true</b> means success, while <b>false</b> means failure.
	  // Remarks: Write a block data to the end.
	  // Notes:
	  // Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	  // See: FSFileWriteHandlerGetSize
	  //************************************
	static	FS_BOOLEAN			WriteBlock2(FS_FileWriteHandler handler, const FS_LPVOID  pData, FS_UINT size);

};

//////////////////////////////////////////////////////////////////////////
//class CFS_XMLElement_V2
class CFS_XMLElement_V2
{
public:	
	//************************************
	// Function:  parse
	// Param[in]: pBuffer			The input buffer.
	// Param[in]: size				The size in bytes of the input buffer.
	// Param[in]: bSaveSpaceChars	Indicates whether need save space characters in content string, TRUE if save, or FALSE. Sets it FALSE as default.
	// Param[out]: pParsedSize		It receives the parsed size. Sets it NULL as default if you don't want to receive it.
	// Return: The XML element.
	// Remarks: Constructs an XML element using data in specified buffer.
	// The buffer can be discarded immediately after construction finished, because at this time,
	// all data have been loaded into the element (and its descendant element).
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementparse2
	//************************************
	static FS_XMLElement parse(const void* pBuffer, FS_DWORD size, FS_BOOL bSaveSpaceChars, FS_DWORD* pParsedSize);	

	//************************************
	// Function:  parse2
	// Param[in]: fileReadHander	The input file access object. Creates it by <a>FSFileReadHandlerNew</a>.
	// Param[in]: bSaveSpaceChars	Indicates whether need save space characters in content string, TRUE if save, or FALSE. Sets it FALSE as default.
	// Param[out]: pParsedSize		It receives the parsed size. Sets it NULL as default if you don't want to receive it.
	// Return: The XML element.
	// Remarks: Parses XML contents from a <a>FS_FileReadHandler</a> object.
	// The <a>FS_FileReadHandler</a> object can be discarded immediately after construction finished, because at this time,
	// all data have been loaded into the element (and its descendant element).
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementparse
	//************************************
	static FS_XMLElement parse2(FS_FileReadHandler fileReadHander, FS_BOOL bSaveSpaceChars, FS_DWORD* pParsedSize);

	//************************************
	// Function:  New
	// Param[in]: qSpace	Qualified namespace, or empty if no namespace or default namespace is used.
	// Param[in]: tagName	The input tag name.
	// Return: An empty XML element, with a qualified namespace and tag name.
	// Remarks: Creates an empty XML element, with a qualified namespace and tag name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementDestroy
	//************************************
	static FS_XMLElement New(FS_LPCSTR qSpace, FS_LPCSTR tagName);

	//************************************
	// Function:  New2
	// Param[in]: tagName	Qualified tag name.
	// Return: An empty element, with qualified tag name.
	// Remarks: Creates an empty element, with qualified tag name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementDestroy
	//************************************
	static FS_XMLElement New2(FS_LPCSTR tagName);

	//************************************
	// Function:  New3
	// Return: An empty element.
	// Remarks: Creates an empty element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementDestroy
	//************************************
	static FS_XMLElement New3();

	//************************************
	// Function:  Destroy
	// Param[in]: XMLElement	The input XML element.
	// Return: void
	// Remarks: Destroys the input XML element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementNew
	// See: FSXMLElementNew2
	// See: FSXMLElementNew3
	//************************************
	static void Destroy(FS_XMLElement XMLElement);	

	//************************************
	// Function:  GetTagName
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: bQualified	Indicates whether return a qualified tag name or not. 
	// Param[out]: outTagName	It receives the tag name. If <param>bQualified</param> is TRUE, the tag name is with qualified namespace, or only local tag name.
	// Return: void
	// Remarks: Gets the tag name of the XML element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementNew
	//************************************
	static void	GetTagName(FS_XMLElement XMLElement, FS_BOOL bQualified, FS_ByteString* outTagName);	

	//************************************
	// Function:  GetNamespace
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: bQualified	Indicates whether return a qualified namespace or full URI namespace.
	// Param[out]: outNamespace	It receives the name space. If <param>bQualified</param> is TRUE, returns qualified namespace value, or full URI value.
	// Return: void
	// Remarks: Gets the namespace of the XML element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementNew
	//************************************
	static void	GetNamespace(FS_XMLElement XMLElement, FS_BOOL bQualified, FS_ByteString* outNamespace);	

	//************************************
	// Function:  GetNamespaceURI
	// Param[in]: XMLElement		The input XML element.
	// Param[in]: name				Qualified namespace.
	// Param[out]: outNamespaceURI	It receives the full URI value.
	// Return: void
	// Remarks: Gets the full URI value for a qualified namespace.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetNamespace
	//************************************
	static void	GetNamespaceURI(FS_XMLElement XMLElement, FS_LPCSTR name, FS_ByteString* outNamespaceURI);	

	//************************************
	// Function:  GetParent
	// Param[in]: XMLElement	The input XML element.
	// Return: The parent XML element of the input XML element..
	// Remarks: Gets the parent element of the input XML element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementCountChildren
	//************************************
	static FS_XMLElement GetParent(FS_XMLElement XMLElement);	

	//************************************
	// Function:  CountAttrs
	// Param[in]: XMLElement	The input XML element.
	// Return: The count of attributes of the input XML element.
	// Remarks: Gets the count of attributes of the input XML element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetAttrByIndex
	//************************************
	static FS_DWORD CountAttrs(FS_XMLElement XMLElement);	

	//************************************
	// Function:  GetAttrByIndex
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: index			Index of the attribute (start from 0).
	// Param[out]: space		It receives the qualified namespace of attribute name.
	// Param[out]: name			It receives the attribute name (local name).
	// Param[out]: value		It receive the attribute value.
	// Return: void
	// Remarks: Gets the attribute by index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementCountAttrs
	//************************************
	static void GetAttrByIndex(FS_XMLElement XMLElement, FS_INT32 index, FS_ByteString* space, FS_ByteString* name, FS_WideString* value);

	//************************************
	// Function:  HasAttr
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: qName			The input qualified attribute name.
	// Return: <a>TRUE</a> if attribute exists, <a>FALSE</a> if doesn't exist.
	// Remarks: Determines whether a qualified attribute exists or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementCountAttrs
	// See: FSXMLElementGetAttrByIndex
	//************************************
	static FS_BOOL HasAttr(FS_XMLElement XMLElement, FS_LPCSTR qName);	

	//************************************
	// Function:  GetAttrValue
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: name			The qualified attribute name.
	// Param[out]: attribute	It receive the attribute value.
	// Return: Whether the attribute exists or not.
	// Remarks: Gets attribute value without a namespace.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementHasAttr
	// See: FSXMLElementGetAttrValue2
	//************************************
	static FS_BOOL GetAttrValue(FS_XMLElement XMLElement, FS_LPCSTR name, FS_WideString* attribute);	

	//************************************
	// Function:  GetAttrValue2
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: space			The qualified namespace.
	// Param[in]: name			The qualified attribute name.
	// Param[out]: attribute	It receive the attribute value, A UTF-16LE wide string.
	// Return: Whether the attribute exists or not.
	// Remarks: Gets attribute value. Encoded in UTF-16LE format.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetAttrValue
	//************************************
	static FS_BOOL GetAttrValue2(FS_XMLElement XMLElement, FS_LPCSTR space, FS_LPCSTR name, FS_WideString* attribute);	

	//************************************
	// Function:  GetAttrInteger
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: name			The qualified attribute name.
	// Param[out]: attribute	It receives the attribute value, a integer value.
	// Return: Whether the attribute exists or not.
	// Remarks: Gets an integer from a particular attribute without a namespace.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetAttrInteger2
	//************************************
	static FS_BOOL GetAttrInteger(FS_XMLElement XMLElement, FS_LPCSTR name, FS_INT32* attribute);

	//************************************
	// Function:  GetAttrInteger2
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: space			The qualified namespace.
	// Param[in]: name			The local name for the attribute.
	// Param[out]: attribute	It receives the attribute value, a integer value.
	// Return: Whether the attribute exists or not.
	// Remarks: Gets an integer from a particular attribute, using a namespace.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetAttrInteger
	//************************************
	static FS_BOOL GetAttrInteger2(FS_XMLElement XMLElement, FS_LPCSTR space, FS_LPCSTR name, FS_INT32* attribute);	

	//************************************
	// Function:  GetAttrFloat
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: name			The qualified attribute name.
	// Param[out]: attribute	It receives the attribute value, a float value.
	// Return: Whether the attribute exists or not.
	// Remarks: Gets a float from a particular attribute without a namespace.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetAttrFloat2
	//************************************
	static FS_BOOL GetAttrFloat(FS_XMLElement XMLElement, FS_LPCSTR name, FS_FLOAT* attribute);	

	//************************************
	// Function:  GetAttrFloat2
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: space			The qualified namespace.
	// Param[in]: name			The local name for the attribute.
	// Param[out]: attribute	It receives the attribute value, a float value.
	// Return: Whether the attribute exists or not.
	// Remarks: Gets an float from a particular attribute, using a namespace.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetAttrFloat
	//************************************
	static FS_BOOL GetAttrFloat2(FS_XMLElement XMLElement, FS_LPCSTR space, FS_LPCSTR name, FS_FLOAT* attribute);	

	//************************************
	// Function:  CountChildren
	// Param[in]: XMLElement	The input XML element.
	// Return: The number of children.
	// Remarks: Gets the number of children of this element, including content segments and sub-elements.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetChildType
	//************************************
	static FS_DWORD CountChildren(FS_XMLElement XMLElement);	

	//************************************
	// Function:  GetChildType
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: index			Specifies the zero-based index in children array.
	// Return: The type of specified child.
	// Remarks: Gets the type of a child, it can be either a content segment, or a sub-element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementCountChildren
	//************************************
	static FS_Child_Type GetChildType(FS_XMLElement XMLElement, FS_DWORD index);	

	//************************************
	// Function:  GetContent
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: index			Specifies the zero-based index in children array.
	// Param[out]: outContent	It receives the content.
	// Return: void
	// Remarks: Gets a content segment. If this child is an element, <param>outContent</param> will receive nothing.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetChildType
	//************************************
	static void GetContent(FS_XMLElement XMLElement, FS_DWORD index, FS_WideString* outContent);	

	//************************************
	// Function:  GetElement
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: index			Specifies the zero-based index in children array.
	// Return: A child element.
	// Remarks: Gets a particular child element. If this child is not an element, NULL will be returned.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetChildType
	// See: FSXMLElementGetElement2
	//************************************
	static FS_XMLElement GetElement(FS_XMLElement XMLElement, FS_DWORD index);	

	//************************************
	// Function:  GetElement2
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: space			The qualified namespace.
	// Param[in]: tag			The local name for the tag.
	// Return: An element.
	// Remarks: Gets an element with particular tag. If more than one element with the same tag, only the first one is returned.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetElement
	//************************************
	static FS_XMLElement GetElement2(FS_XMLElement XMLElement, FS_LPCSTR space, FS_LPCSTR tag);

	//************************************
	// Function:  GetElement3
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: space			The qualified namespace.
	// Param[in]: tag			The input tag.
	// Param[in]: index			Specifies the zero-based index of element with particular tag.
	// Return: An element.
	// Remarks: Gets an element with particular tag, and specified index if more than one elements with the same tag.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetElement
	// See: FSXMLElementGetElement2
	//************************************
	static FS_XMLElement GetElement3(FS_XMLElement XMLElement, FS_LPCSTR space, FS_LPCSTR tag, FS_INT32 index);

	//************************************
	// Function:  CountElements
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: space			The qualified namespace.
	// Param[in]: tag			The local name for the tag.
	// Return: The count number of elements with the input tag.
	// Remarks: Counts number of elements with particular tag.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetElement
	// See: FSXMLElementGetElement2
	// See: FSXMLElementGetElement3
	//************************************
	static FS_DWORD CountElements(FS_XMLElement XMLElement, FS_LPCSTR space, FS_LPCSTR tag);

	//************************************
	// Function:  FindElement
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: pChild		The input child element.
	// Return: The index number of child element, -1 if not found.
	// Remarks: Finds an element and returns its index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementCountElements
	//************************************
	static FS_DWORD FindElement(FS_XMLElement XMLElement, FS_XMLElement pChild);	

	//************************************
	// Function:  SetTag
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: qSpace		The qualified namespace for the tag.
	// Param[in]: tagname		The input tag name.
	// Return: void
	// Remarks: Sets the tag name of the element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetTagName
	//************************************
	static void SetTag(FS_XMLElement XMLElement, FS_LPCSTR qSpace, FS_LPCSTR tagname);

	//************************************
	// Function:  SetTag2
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: qTagName		The input tag name.
	// Return:    void
	// Remarks: Sets the tag name of the element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetTagName
	// See: FSXMLElementSetTag
	//************************************
	static void SetTag2(FS_XMLElement XMLElement, FS_LPCSTR qTagName);	

	//************************************
	// Function:  SetAttrValue
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: name			The qualified attribute name.
	// Param[in]: value			The input wide string.
	// Return: void
	// Remarks: Sets attribute with a wide string.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetAttrValue
	//************************************
	static void SetAttrValue(FS_XMLElement XMLElement, FS_LPCSTR name, FS_WideString value);	

	//************************************
	// Function:  SetAttrValue2
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: name			The qualified attribute name.
	// Param[in]: value			The input integer.
	// Return: void
	// Remarks: Sets attribute with an integer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetAttrInteger
	//************************************
	static void SetAttrValue2(FS_XMLElement XMLElement, FS_LPCSTR name, FS_INT32 value);

	//************************************
	// Function:  SetAttrValue3
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: name			The qualified attribute name.
	// Param[in]: value			The input float.
	// Return: void
	// Remarks: Sets attribute with a float.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementGetAttrFloat
	// See: FSXMLElementGetAttrFloat2
	//************************************
	static void SetAttrValue3(FS_XMLElement XMLElement, FS_LPCSTR name, FS_FLOAT value);	

	//************************************
	// Function:  RemoveAttr
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: name			The qualified attribute name.
	// Return: void
	// Remarks: Removes an attribute.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void RemoveAttr(FS_XMLElement XMLElement, FS_LPCSTR name);

	//************************************
	// Function:  AddChildElement
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: pElement		The input element.
	// Return: void
	// Remarks: Adds an element to the child list (at the last position).
	// Notes: The child element can't be directly destroyed any more.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementCountChildren
	//************************************
	static void AddChildElement(FS_XMLElement XMLElement, FS_XMLElement pElement);	

	//************************************
	// Function:  AddChildContent
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: content		The input content.
	// Param[in]: bCDATA		Whether the content is CDATA or not. Sets it <a>FALSE</a> as default.
	// Return: void
	// Remarks: Adds a content child.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementCountChildren
	// See: FSXMLElementAddChildElement
	//************************************
	static void AddChildContent(FS_XMLElement XMLElement, FS_WideString content, FS_BOOL bCDATA);	

	//************************************
	// Function:  InsertChildElement
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: index			Specifies the zero-based index of element in the child array.
	// Param[in]: pElement		The input element.
	// Return: void
	// Remarks: Inserts a child element before the specified index
	// Notes: The child element can't be directly destroyed any more.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementAddChildElement
	//************************************
	static void InsertChildElement(FS_XMLElement XMLElement, FS_DWORD index, FS_XMLElement pElement);	

	//************************************
	// Function:  InsertChildContent
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: index			Specifies the zero-based index of element in the child array.
	// Param[in]: content		The input content.
	// Param[in]: bCDATA		Whether the content is CDATA or not. Sets it <a>FALSE</a> as default.
	// Return: void
	// Remarks: Inserts a content segment before the specified index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementAddChildContent
	//************************************
	static void InsertChildContent(FS_XMLElement XMLElement, FS_DWORD index, FS_WideString content, FS_BOOL bCDATA);	

	//************************************
	// Function:  RemoveChildren
	// Param[in]: XMLElement	The input XML element.
	// Return: void
	// Remarks: Remove all children.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementRemoveChild
	//************************************
	static void RemoveChildren(FS_XMLElement XMLElement);	

	//************************************
	// Function:  RemoveChild
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: index			Specifies the zero-based index of element in the child array.
	// Return: void
	// Remarks: Removes a specified child item (element or content).
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementRemoveChildren
	//************************************
	static void RemoveChild(FS_XMLElement XMLElement, FS_DWORD index);	

	//************************************
	// Function:  OutputStream
	// Param[in]: XMLElement	The input XML element.
	// Param[out]: output		It receives the XML stream.
	// Return: void
	// Remarks: Outputs to a XML stream.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementOutputStream2
	//************************************
	static void OutputStream(FS_XMLElement XMLElement, FS_ByteString* output);	

	//************************************
	// Function:  OutputStream2
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: handler		The input file write handler. Creates it by <a>FSFileWriteHandlerNew</a>.
	// Return: void
	// Remarks: Outputs through the file write handler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See: FSXMLElementOutputStream
	//************************************
	static void OutputStream2(FS_XMLElement XMLElement, FS_FileWriteHandler handler);

	//************************************
	// Function:  Clone
	// Param[in]: XMLElement	The input XML element.
	// Return: The cloned XML element.
	// Remarks: Clones the specified XML element.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0.2
	// See: FSXMLElementparse2
	//************************************
	static FS_XMLElement Clone(FS_XMLElement XMLElement);

	//************************************
	// Function:  parse
	// Param[in]: pBuffer			The input buffer.
	// Param[in]: size				The size in bytes of the input buffer.
	// Param[in]: bSaveSpaceChars	Indicates whether need save space characters in content string, TRUE if save, or FALSE. Sets it FALSE as default.
	// Param[out]: pParsedSize		It receives the parsed size. Sets it NULL as default if you don't want to receive it.
	// param[in] pAllocator			Allocator used in this class.NULL is to use default allocator.
	// param[in] bSaveSpecialChar	Indicates whether need save special characters in content string, true if save, or false.
	// param[in] bSaveLineBreakChar	Indicates whether need save line break characters in content string, true if save, or false.
	// Return: The XML element.
	// Remarks: Constructs an XML element using data in specified buffer.
	// The buffer can be discarded immediately after construction finished, because at this time,
	// all data have been loaded into the element (and its descendant element).
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See: FSXMLElementparse2
	//************************************
	static FS_XMLElement parse3(const void* pBuffer, FS_DWORD size, FS_BOOL bSaveSpaceChars, FS_DWORD* pParsedSize, FS_LPVOID pAllocator, FS_BOOLEAN bSaveSpecialChar, FS_BOOLEAN bSaveLineBreakChar);

	//************************************
	// Function:  parse2
	// Param[in]: fileReadHander	The input file access object. Creates it by <a>FSFileReadHandlerNew</a>.
	// Param[in]: bSaveSpaceChars	Indicates whether need save space characters in content string, TRUE if save, or FALSE. Sets it FALSE as default.
	// Param[out]: pParsedSize		It receives the parsed size. Sets it NULL as default if you don't want to receive it.
	// param[in] pAllocator			Allocator used in this class.NULL is to use default allocator.
	// param[in] bSaveSpecialChar	Indicates whether need save special characters in content string, true if save, or false.
	// param[in] bSaveLineBreakChar	Indicates whether need save line break characters in content string, true if save, or false.
	// Return: The XML element.
	// Remarks: Parses XML contents from a <a>FS_FileReadHandler</a> object.
	// The <a>FS_FileReadHandler</a> object can be discarded immediately after construction finished, because at this time,
	// all data have been loaded into the element (and its descendant element).
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See: FSXMLElementparse
	//************************************
	static FS_XMLElement parse4(FS_FileReadHandler fileReadHander, FS_BOOL bSaveSpaceChars, FS_DWORD* pParsedSize, FS_LPVOID pAllocator, FS_BOOLEAN bSaveSpecialChar, FS_BOOLEAN bSaveLineBreakChar);

	//************************************
	// Function:  OutputStream3
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: bKeepSpecialCode	If keep special code.
	// Param[in]: bRemoveLineBreak	If remove line break.
	// Param[out]: output		It receives the XML stream.
	// Return: void
	// Remarks: Outputs to a XML stream.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// See: FSXMLElementOutputStream3
	//************************************
	static void OutputStream3(FS_XMLElement XMLElement, FS_BOOLEAN bKeepSpecialCode, FS_BOOLEAN bRemoveLineBreak, FS_ByteString* output);

	//************************************
	// Function:  OutputStream4
	// Param[in]: XMLElement	The input XML element.
	// Param[in]: bKeepSpecialCode	If keep special code.
	// Param[in]: bRemoveLineBreak	If remove line break.
	// Param[in]: handler		The input file write handler. Creates it by <a>FSFileWriteHandlerNew</a>.
	// Return: void
	// Remarks: Outputs through the file write handler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// See: FSXMLElementOutputStream4
	//************************************
	static void OutputStream4(FS_XMLElement XMLElement, FS_BOOLEAN bKeepSpecialCode, FS_BOOLEAN bRemoveLineBreak, FS_FileWriteHandler handler);
};

class CFS_UTF8Decoder_V5
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    The UTF8 decoder object.
	// Remarks:   Creates a new UTF8 decoder object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_UTF8Decoder New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: decoder The input UTF8 decoder.
	// Return:    void.
	// Remarks:   Destroys the UTF8 decoder object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void Destroy(FS_UTF8Decoder decoder);

	//************************************
	// Function:  Clear
	// Param[in]: decoder The input UTF8 decoder.
	// Return:    void.
	// Remarks:   Clears the decoding status and sets the output wide text buffer to be empty.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void Clear(FS_UTF8Decoder decoder);

	//************************************
	// Function:  Input
	// Param[in]: decoder	The input UTF8 decoder.
	// Param[in]: byte		The input byte.
	// Return:    void.
	// Remarks:   Inputs a byte.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void Input(FS_UTF8Decoder decoder, FS_BYTE byte);
	
	//************************************
	// Function:  AppendChar
	// Param[in]: decoder	The input UTF8 decoder.
	// Param[in]: ch		The input character.
	// Return:    void.
	// Remarks:   Appends characters to wide text buffer.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void AppendChar(FS_UTF8Decoder decoder, FS_DWORD ch);

	//************************************
	// Function:  ClearStatus
	// Param[in]: decoder	The input UTF8 decoder.
	// Return:    void.
	// Remarks:   Clears the decoding status.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void ClearStatus(FS_UTF8Decoder decoder);

	//************************************
	// Function:  GetResult
	// Param[in]: decoder		The input UTF8 decoder.
	// Param[out]: outResult	It receives the result.
	// Return:    void.
	// Remarks:   Gets the result.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void	GetResult(FS_UTF8Decoder decoder, FS_WideString* outResult);
};


class CFS_UTF8Encoder_V5
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    The UTF8 encoder object.
	// Remarks:   Creates a new UTF8 encoder object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_UTF8Encoder New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: encoder The input UTF8 encoder.
	// Return:    void.
	// Remarks:   Destroys the UTF8 encoder object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void Destroy(FS_UTF8Encoder encoder);

	//************************************
	// Function:  Input
	// Param[in]: encoder The input UTF8 encoder.
	// Param[in]: unicode The input unicode.
	// Return:    void.
	// Remarks:   Inputs a unicode.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void Input(FS_UTF8Encoder encoder, FS_WCHAR unicode);

	//************************************
	// Function:  AppendStr
	// Param[in]: encoder	The input UTF8 encoder.
	// Param[in]: str		A non-buffered byte string.
	// Return:    void.
	// Remarks:   Appends a non-buffered byte string.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void AppendStr(FS_UTF8Encoder encoder, FS_ByteString str);

	//************************************
	// Function:  GetResult
	// Param[in]: encoder	The input UTF8 encoder.
	// Param[out]: str		It receives the result.
	// Return:    void.
	// Remarks:   Gets the result.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void GetResult(FS_UTF8Encoder encoder, FS_ByteString* outResult);

	//************************************
	// Function:  IsUTF8Data
	// Param[in]: pData	The pointer to the data buffer.
	// Param[in,out]: pLen The pointer to the length of the data buffer, in bytes. When this function returns, it stores the number of bytes scanned.
	// Return:    TRUE if all data is UTF-8 encoded, FALSE if the data is not UTF-8 format..
	// Remarks:   Checks whether a data buffer is UTF-8 encoded or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	//************************************
	static FS_BOOL IsUTF8Data(FS_LPCBYTE pData, FS_INT32* pLen);
};

//////////////////////////////////////////////////////////////////////////
//class CFS_FileStream_V6

class CFS_FileStream_V6
{
public:
	//************************************
	// Function:  New
	// Param[in]: callbacks The input callback set for file stream reading and writing.
	// Return:    The file stream object.
	// Remarks:   Creates the file stream object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	//************************************
	static FS_FileStream New(FS_FileStreamCallbacks callbacks);

	//************************************
	// Function:  New2
	// Param[in]: filename	The input file path.
	// Param[in]: dwModes	The input file mode. See the definition of FSFileMode.
	// Param[in]: reserved	It is a reserved parameter. Must set it as NULL.
	// Return:    The file stream object.
	// Remarks:   Creates the file stream object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	//************************************
	static FS_FileStream New2(FS_LPCWSTR filename, FS_DWORD dwModes, void* reserved);

	//************************************
	// Function:  Destroy
	// Param[in]: fileStream The input file stream object.
	// Return:    void
	// Remarks:   Destroys the file stream object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	//************************************
	static void Destroy(FS_FileStream fileStream);

	//************************************
	// Function:  GetFileRead
	// Param[in]: fileStream    The input file stream object.	
	// Return: FS_FileReadHandler    
	// Remarks: IFX_FileStream inheritance IFX_FileRead,support a interface to convert to IFX_FileRead object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static  FS_FileReadHandler       GetFileRead(FS_FileStream fileStream);

	//************************************
	// Function:  GetFileWrite
	// Param[in]: fileStream    The input file stream object.	
	// Return: FS_FileWriteHandler    
	// Remarks: IFX_FileStream inheritance IFX_FileWrite,support a interface to convert to IFX_FileWrite object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static  FS_FileWriteHandler       GetFileWrite(FS_FileStream fileStream);

	//************************************
	// Function:  CreateMemoryStream
	// Param[in]: pBuffer    A memory buffer to read/write data.
	// Param[in]: nSize      Buffer size, in bytes.
	// Param[in]: bTakeOver   Indicates whether need to take over parameter <i>pBuffer</i>. If this is <b>true</b>,
	//                        parameter <i>pBuffer< / i> will release internally when destroy returned IFX_MemoryStream object.
	//                        Default value : <b>false< / b>.
	// Param[in]: pAllocator Pointer to ::IFX_Allocator object, this specifies an allocator. If this is <b>NULL</b>,
	//                        default allocator is used. Default value : <b>NULL< / b>.
	// Return: FS_FileStream    
	// Remarks: Creates a stream object by a given memory buffer. This function creates a consecutive memory stream object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1
	//************************************
	static FS_FileStream CreateMemoryStream(FS_LPBYTE pBuffer, FS_UINT nSize, FS_BOOLEAN bTakeOver, FS_LPVOID pAllocator);
};

//////////////////////////////////////////////////////////////////////////
//class CFS_GUID_V7
class CFS_GUID_V7
{
public:
	//************************************
	// Function:  Create
	// Param[out]: pGUID Pointer to store the returned GUID value, cannot be NULL. 
	// Return:    void
	// Remarks:   Creates a GUID, version 4.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	//************************************
	static void Create(FS_LPGUID pGUID);

	//************************************
	// Function:  ToString
	// Param[in]: pGUID			Pointer to a valid GUID value, cannot be NULL.
	// Param[out]: outStr		It receives the GUID string.
	// Param[in]: bSeparator	If TRUE, GUID string will include '-' separating characters.
	// Return:    void
	// Remarks:  FormatS GUID to a string.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.1
	//************************************
	static void ToString(FS_LPGUID pGUID, FS_ByteString* outStr, FS_BOOL bSeparator);
};

//////////////////////////////////////////////////////////////////////////
//class CFS_UUID_V9
class CFS_UUID_V9
{
public:
	//************************************
	// Function:  Generate
	// Param[out]: outID			It receives the ID.
	// Param[in]: userData			The input user data.
	// Param[in,out]: outLastState	It receives the last state of the ID.
	// Return:    The type of the UUID. See the definition of <a>FSUUIDType</a>.
	// Remarks:   Generates a UUID.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	//************************************
	static FS_INT32 Generate(FS_ByteString* outID, FS_INT32 userData, FS_ByteString* outLastState);

	//************************************
	// Function:  GenerateTime
	// Param[out]: outID			It receives the ID.
	// Param[in]: userData			The input user data.
	// Param[in,out]: outLastState	It receives the last state of the ID.
	// Param[in]: bOnlyUid			Whether generates the ID only or not.
	// Return:    The type of the UUID. See the definition of <a>FSUUIDType</a>.
	// Remarks:   Generates a UUID constructed by time.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	//************************************
	static FS_INT32	GenerateTime(FS_ByteString* outID, FS_INT32 userData, FS_ByteString* outLastState, FS_BOOL bOnlyUid);

	//************************************
	// Function:  GenerateRandom
	// Param[out]: outID		It receives the ID.
	// Param[in]: userData		The input user data.
	// Return:    The type of the UUID. See the definition of <a>FSUUIDType</a>.
	// Remarks:   Generates a UUID randomly.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	//************************************
	static FS_INT32	GenerateRandom(FS_ByteString* outID, FS_INT32 userData);

	//************************************
	// Function:  SetTsPath
	// Param[in]: bsTsPath		The input Ts path.
	// Return:    The type of the UUID. See the definition of <a>FSUUIDType</a>.
	// Remarks:   Sets the Ts path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	//************************************
	static FS_INT32	SetTsPath(FS_ByteString bsTsPath);

	//************************************
	// Function:  SetState
	// Param[in]: bsLastState		The input last state.
	// Return:    The type of the UUID. See the definition of <a>FSUUIDType</a>.
	// Remarks:   Sets the last state.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	//************************************
	static FS_INT32	SetState(FS_ByteString bsLastState);

	//************************************
	// Function:  SetUserData
	// Param[in]: bsUserData		The input user data.
	// Return:    The type of the UUID. See the definition of <a>FSUUIDType</a>.
	// Remarks:   Sets the user data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3
	//************************************
	static FS_INT32	SetUserData(FS_ByteString bsUserData);
};

//////////////////////////////////////////////////////////////////////////
//class CFS_MapByteStringToPtr_V9
class CFS_MapByteStringToPtr_V9
{
public:

	//************************************
	// Function:  New	
	// Param[in]: nBlockSize	The internal block. Sets it 10 as default.
	// Return:    An empty bytestring-to-ptr map.
	// Remarks:   Creates an empty bytestring-to-ptr map with specified block size.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_MapByteStringToPtr New(FS_INT32 nBlockSize);

	//************************************
	// Function:  Destroy
	// Param[in]: map The input bytestring-to-ptr map.
	// Return:    void
	// Remarks:   Destroys the bytestring-to-ptr map.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static void	Destroy(FS_MapByteStringToPtr map);

	//************************************
	// Function:  GetCount	
	// Param[in]: map The input bytestring-to-ptr map.
	// Return:   The number of elements in the map.
	// Remarks:   Gets the number of elements.
	// Notes:   
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_INT32 GetCount(FS_MapByteStringToPtr map);

	//************************************
	// Function:  IsEmpty	
	// Param[in]: map The input bytestring-to-ptr map.
	// Return:    <a>TRUE</a> for map being empty. <a>FALSE</a> otherwise.
	// Remarks:   Tests whether the <param>map</param> is empty.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_BOOL IsEmpty(FS_MapByteStringToPtr map);

	//************************************
	// Function:   Lookup
	// Param[in]:  map		The input bytestring-to-ptr map.
	// Param[in]:  key		The key to lookup.
	// Param[out]: outValue A ref of a typeless pointer to receive the found value.
	// Return:     <a>TRUE</a> for value being found. <a>FALSE</a> otherwise.
	// Remarks:    Looks up by a key.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_BOOL Lookup(FS_MapByteStringToPtr map, FS_ByteString key, void** outValue);
	
	//************************************
	// Function:  SetAt	
	// Param[in]: map			The input bytestring-to-ptr map.
	// Param[in]: key			The key to specify a position.
	// Param[in]: newValue		The new value.
	// Return:    void
	// Remarks:   Adds a new (key, value) pair. Adds if not exist, otherwise modify.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static void SetAt(FS_MapByteStringToPtr map, FS_ByteString key, void* newValue);

	//************************************
	// Function:  RemoveKey	
	// Param[in]: map The input bytestring-to-ptr map.
	// Param[in]: key The key to remove.
	// Return:    <a>TRUE</a> for success, otherwise <a>FALSE</a>.
	// Remarks:   Removes existing (key, value) pair.
	// Notes:     
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_BOOL RemoveKey(FS_MapByteStringToPtr map, FS_ByteString key);
	
	//************************************
	// Function:  RemoveAll	
	// Param[in]: map The input bytestring-to-ptr map.
	// Return:    void
	// Remarks:   Removes all the (key, value) pairs in the map.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static void RemoveAll(FS_MapByteStringToPtr map);

	//************************************
	// Function:  GetStartPosition	
	// Param[in]: map The input bytestring-to-ptr map.
	// Return:    The first key-value pair position in the map
	// Remarks:   Gets the first key-value pair position, iterating all (key, value) pairs.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_POSITION GetStartPosition(FS_MapByteStringToPtr map);
	
	//************************************
	// Function:      GetNextAssoc
	// Param[in]:     map					The input bytestring-to-ptr map.
	// Param[in,out]: inOutNextPosition		Input a position, and receive the next association position.
	// Param[out]:    outKey				(Filled by this method)Receive a key.
	// Param[out]:    outValue				(Filled by this method)Receive a value.
	// Return:        void
	// Remarks:       Gets the current association and sets the position to next association.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static void GetNextAssoc(FS_MapByteStringToPtr map, FS_POSITION* inOutNextPosition, FS_ByteString* outKey, void** outValue);

	//************************************
	// Function:      GetNextValue
	// Param[in]:     map					The input bytestring-to-ptr map.
	// Param[in,out]: inOutNextPosition		Input a position, and receive the next association position.
	// Return:        The value.
	// Remarks:       Gets the current value and sets the position to next association.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_LPVOID GetNextValue(FS_MapByteStringToPtr map, FS_POSITION* inOutNextPosition);

	//************************************
	// Function:  GetHashTableSize
	// Param[in]: map		The input bytestring-to-ptr map.
	// Return:    The hash table size.
	// Remarks:   Gets the internal hash table size. Advanced features for derived classes.
	// Notes:    
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_DWORD GetHashTableSize(FS_MapByteStringToPtr map);
	
	//************************************
	// Function:  InitHashTable	
	// Param[in]: map			The input bytestring-to-ptr map.
	// Param[in]: hashSize		Initializes the hash table size.
	// Param[in]: bAllocNow		Does it Now allocate the hash table? No-zero means yes, otherwise not. Sets it TRUE as default.
	// Return:    void
	// Remarks:   Initializes the hash table.
	// Notes:     
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static void InitHashTable(FS_MapByteStringToPtr map, FS_DWORD hashSize, FS_BOOL bAllocNow);

	//************************************
	// Function:  HashKey	
	// Param[in]: map		The input bytestring-to-ptr map.
	// Param[in]: key		The key used to produce the hash key.
	// Return:    A hash value.
	// Remarks:   Routine used to user-provided hash keys.
	// Notes: Overwrite-able: special non-virtual (see map implementation for details).
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.3.1
	//************************************
	static FS_DWORD HashKey(FS_MapByteStringToPtr map, FS_ByteString key);
};

class CFS_Image_V12
{
public:

	//************************************
	// Function:	Create
	// Return:		A <a>FS_Image</a> handler.
	// Remarks:		Need release by <a>FSImageRelease</a>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1
	//************************************
	static FS_Image Create();

	static void Release(FS_Image image);

	static FS_HImage Load(FS_Image image, FS_FileReadHandler readHandler);

	static FSCODEC_IMAGE_TYPE GetType(FS_Image image, FS_HImage hImage);
	
	static void EnableTransparent(FS_Image image, FS_HImage hImage, FS_BOOL bEnable);

	static void	SetBackgroundColor(FS_Image image, FS_HImage hImage, FS_ARGB argb);

	static void	SetOpacity(FS_Image image, FS_HImage hImage, FS_BYTE nOpacity);

	static FS_INT32	CountFrames(FS_Image image, FS_HImage hImage);

	static FS_BOOL LoadFrame(FS_Image image, FS_HImage hImage, FS_INT32 iFrame);

	static FS_BOOL NeedLoadPrevFrame(FS_Image image, FS_HImage hImage, FS_INT32 iFrame);

	static FS_BOOL GetFrameSize(FS_Image image, FS_HImage hImage, FS_INT32* poutWidth, FS_INT32* poutHeight);

	static FS_DIBitmap GetFrame(FS_Image image, FS_HImage hImage);

	static FS_BOOL GetFrameColorKey(FS_Image image, FS_HImage hImage, FS_INT32* poutColorKey);

	static FS_DIBitmap GetFrameWithTransparency(FS_Image image, FS_HImage hImage);

	static FS_BOOL GetFrameRawData(FS_Image image, FS_HImage hImage, FS_INT32 iFrame, FS_LPBYTE *pData, FS_UINT *pSize);

	static FS_INT32 GetFrameCompress(FS_Image image, FS_HImage hImage, FS_INT32 iFrame);

	static FS_INT32	GetFramePhotoInterpret(FS_Image image, FS_HImage hImage, FS_INT32 iFrame);

	static void	Free(FS_Image image, FS_HImage hImage);

	static FS_DIBAttribute	GetAttribute(FS_Image image, FS_HImage hImage);

	static FS_INT32	GetWidth(FS_Image image, FS_HImage hImage);

	static FS_INT32 GetHeight(FS_Image image, FS_HImage hImage);

	static FPD_PageObject CreateObject(FPD_Document pPDFDoc, FS_HImage hImage, FS_INT32 iFrame,
		FS_AffineMatrix *pMatrix, FS_BOOL bAutoRotate);

	static FPD_PageObject InsertToPDFPage(void *pPDFPageObjects, FS_POSITION posInsert,
		FS_HImage hImage, FS_INT32 iFrame, FS_AffineMatrix *pMatrix, FS_BOOL bAutoRotate);

	static FS_INT32 InsertToPDFDocument(FPD_Document pPDFDoc, FS_INT32 iPageStart,
		FS_HImage hImage, FS_INT32 iFrameStart, FS_INT32 iFrameCount, FS_BOOL bAutoRotate);
};


class CFS_ReaderDateTime_V14
{
public:
	static FS_ReaderDateTime CreateDateTimeDefault();
	static FS_ReaderDateTime CreateDateTimeStr(const FS_LPCSTR dtStr, FS_BOOL bUseCurrent);
	static FS_ReaderDateTime CreateDateTime(FS_ReaderDateTime datetime);
	static FS_ReaderDateTime CreateDateTimeSysTime(const FS_SYSTEMTIME* st);
	static FS_ReaderDateTime	FromPDFDateTimeString(FS_ReaderDateTime datetime, const FS_LPCSTR& dtStr);	
	static void		ToCommonDateTimeString(FS_ReaderDateTime datetime, FS_ByteString* bsOutStr);
	static void		ToPDFDateTimeString(FS_ReaderDateTime datetime, FS_ByteString* bsOutStr);
	static FS_BOOL				ToSystemTime(FS_ReaderDateTime datetime,FS_SYSTEMTIME* st);
	static void	ToGMT(FS_ReaderDateTime datetime, FS_ReaderDateTime* retTime);
	static void	ToLocalTime(FS_ReaderDateTime datetime, FS_ReaderDateTime* retTime);
	static void	AddDays(FS_ReaderDateTime datetime,FS_SHORT days, FS_ReaderDateTime* retTime);
	static void	AddSeconds(FS_ReaderDateTime datetime,FS_INT32 seconds, FS_ReaderDateTime* retTime);
	static FS_BOOL				IsEmpty(FS_ReaderDateTime datetime);
	static void				ResetDateTime(FS_ReaderDateTime datetime);
	static FS_BOOL				IsLeapYear(FS_ReaderDateTime datetime, FS_INT32 year);
	static FS_BOOL				IsValid(FS_ReaderDateTime datetime, FS_INT32 year, FS_INT32 month, FS_INT32 day);
	static void	FillDateTime (FS_ReaderDateTime datetime,const FS_ReaderDateTime filldatetime);
	static void	FillSystemtime (FS_ReaderDateTime datetime, FS_SYSTEMTIME& st);
	static FS_BOOL				IsEqual (FS_ReaderDateTime datetime, FS_ReaderDateTime& datetimeMatch);
	static FS_BOOL				IsUnEqual (FS_ReaderDateTime datetime, FS_ReaderDateTime& datetimeMatch);
	static FS_BOOL				IsGreater (FS_ReaderDateTime datetime, FS_ReaderDateTime& datetimeMatch);
	static FS_BOOL				IsEqualGreater (FS_ReaderDateTime datetime, FS_ReaderDateTime& datetimeMatch);
	static FS_BOOL				IsLess (FS_ReaderDateTime datetime, FS_ReaderDateTime& datetimeMatch);
	static FS_BOOL				IsEqualLess (FS_ReaderDateTime datetime, FS_ReaderDateTime& datetimeMatch);
	static void Destroy(FS_ReaderDateTime datetime);
};

class CFS_Monoscale_V14
{
public:
	static FS_Monoscale New();
	static void Destroy(FS_Monoscale monoscale);
	static FS_BOOL LoadDIBSource(FS_Monoscale monoscale, FS_DIBitmap bitmap);
	static FS_LPVOID	GetMonoscaleBitmap(FS_Monoscale monoscale, FSMONOALRITHEMETIC mode);	
};


class CFS_FloatArray_V14
{

public:
	//************************************
	// Function:  New	
	// Param[in]: void
	// Return:    A new empty pointer array.
	// Remarks:   Creates a new empty pointer array.
	// Notes:
	//************************************
	static FS_FloatArray New(void);


	//************************************
	// Function:  Destroy	
	// Param[in]: arr		The input pointer array.
	// Return:    void
	// Remarks:   Destroys a pointer array.
	// Notes:
	//************************************
	static void Destroy(FS_FloatArray arr);

	//************************************
	// Function:  GetSize	
	// Param[in]: arr		The input pointer array.
	// Return:    The number of elements in the array.
	// Remarks:   Gets the number of elements in the array.
	// Notes:
	//************************************
	static FS_INT32	GetSize(FS_FloatArray arr);


	//************************************
	// Function:  GetUpperBound	
	// Param[in]: arr		The input pointer array.
	// Return:    The upper bound.
	// Remarks:   Gets the upper bound in the array, actually the maximum valid index.
	// Notes:
	//************************************
	static FS_INT32	GetUpperBound(FS_FloatArray arr);


	//************************************
	// Function:  SetSize
	// Param[in]: arr		 The input pointer array.
	// Param[in]: nNewSize	 The new size in elements expected.
	// Param[in]: nGrowBy	 The grow amount in elements expected, nGrowBy can be -1 for the grow amount unchanged.
	// Return:    void
	// Remarks:   Changes the allocated size and the growing amount.
	// Notes:
	//************************************
	static void	SetSize(FS_FloatArray arr, FS_INT32 nNewSize, FS_INT32 nGrowBy);


	//************************************
	// Function:  RemoveAll	
	// Param[in]: arr		The input pointer array.
	// Return:    void
	// Remarks:   Cleans up the array.
	// Notes:
	//************************************
	static void	RemoveAll(FS_FloatArray arr);


	//************************************
	// Function:  GetAt	
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Return:    An element.
	// Remarks:	  Retrieves an element specified by an index number.
	// Notes:
	//************************************
	static FS_FLOAT GetAt(FS_FloatArray arr, FS_INT32 index);


	//************************************
	// Function:  SetAt
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Param[in]: newItem	An element
	// Return:    void
	// Remarks:	  Overwrites an element specified by an index number.
	// Notes:
	//************************************
	static void SetAt(FS_FloatArray arr, FS_INT32 index, FS_FLOAT newItem);


	//************************************
	// Function:  SetAtGrow
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Param[in]: newItem	The input element.
	// Return:    void
	// Remarks:	  Sets an element value at specified position. Potentially grow the array.
	// Notes:
	//************************************
	static void SetAtGrow(FS_FloatArray arr, FS_INT32 index, FS_FLOAT newItem);


	//************************************
	// Function:  Add
	// Param[in]: arr		The input pointer array.
	// Param[in]: newItem	The input element.
	// Return:    The added element's index in the array.
	// Remarks:   Adds an element at the tail. Potentially grow the array.
	// Notes:    
	//************************************
	static FS_INT32 Add(FS_FloatArray arr, FS_FLOAT newItem);


	//************************************
	// Function:  Append	
	// Param[in]: arr		The input pointer array.
	// Param[in]: srcArr	The input array.
	// Return:    The old size in elements.
	// Remarks:	  Appends an array.
	// Notes:
	//************************************
	static FS_INT32 Append(FS_FloatArray arr, const FS_FloatArray srcArr);


	//************************************
	// Function:  Copy	
	// Param[in]: arr		The input pointer array.
	// Param[in]: srcArr	The input array.
	// Return:    void
	// Remarks:   Copies from an array.
	// Notes:
	//************************************
	static void	Copy(FS_FloatArray arr, FS_FloatArray srcArr);

	//************************************
	// Function:    GetDataPtr
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Return:    A pointer to the specified element.
	// Remarks:   Gets a pointer to the specified element in the array. Direct pointer access.
	// Notes:
	//************************************
	static FS_FLOAT* GetDataPtr(FS_FloatArray arr, FS_INT32 index);

	//************************************
	// Function:  InsertAt	
	// Param[in]: arr			The input pointer array.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Param[in]: newItem	    Specifies the element value to insert.
	// Param[in]: nCount		Specifies the count of the element to insert.
	// Return:    void
	// Remarks:   Inserts one or more continuous element at specified position.
	// Notes:
	//************************************
	static void InsertAt(FS_FloatArray arr, FS_INT32 index, FS_FLOAT newItem, FS_INT32 nCount);


	//************************************
	// Function:  RemoveAt
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index in the array.
	// Param[in]: nCount	Specifies the count of element to remove.
	// Return:    void
	// Remarks:   Removes a number of elements at specified position.
	// Notes:     
	//************************************
	static void	RemoveAt(FS_FloatArray arr, FS_INT32 index, FS_INT32 nCount);


	//************************************
	// Function:  InsertNewArrayAt		
	// Param[in]: arr			The input pointer array.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to insert at.
	// Param[in]: newArray		The input array.
	// Return:    void
	// Remarks:   Inserts an array at specified position.
	// Notes:
	//************************************
	static void	InsertNewArrayAt(FS_FloatArray arr, FS_INT32 nStartIndex, FS_FloatArray newArray);


	//************************************
	// Function:  Find	   
	// Param[in]: arr			The input pointer array.
	// Param[in]: item			The input element.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to find.
	// Return:	  An index of the found element. It can be -1 for finding none.
	// Remarks:   Finds an element from specified position to last
	// Notes:
	//************************************
	static FS_INT32 Find(FS_FloatArray arr, FS_FLOAT item, FS_INT32 nStartIndex);
};


class CFS_Int32Array_V14
{
public:
	//************************************
	// Function:  New
	// Param[in]: void
	// Return:    A new empty pointer array.
	// Remarks:   Creates a new empty pointer array.
	// Notes:
	//************************************
	static FS_Int32Array New(void);

	//************************************
	// Function:  Destroy
	// Param[in]: arr		The input pointer array.
	// Return:    void
	// Remarks:   Destroys a pointer array.
	// Notes:
	//************************************
	static void Destroy(FS_Int32Array arr);

	//************************************
	// Function:  GetSize
	// Param[in]: arr		The input pointer array.
	// Return:    The number of elements in the array.
	// Remarks:   Gets the number of elements in the array.
	// Notes:
	//************************************
	static FS_INT32	GetSize(FS_Int32Array arr);

	//************************************
	// Function:  GetUpperBound
	// Param[in]: arr		The input pointer array.
	// Return:    The upper bound.
	// Remarks:   Gets the upper bound in the array, actually the maximum valid index.
	// Notes:
	//************************************
	static FS_INT32	GetUpperBound(FS_Int32Array arr);

	//************************************
	// Function:  SetSize
	// Param[in]: arr		 The input pointer array.
	// Param[in]: nNewSize	 The new size in elements expected.
	// Param[in]: nGrowBy	 The grow amount in elements expected, nGrowBy can be -1 for the grow amount unchanged.
	// Return:    void
	// Remarks:   Changes the allocated size and the growing amount.
	// Notes:
	//************************************
	static void	SetSize(FS_Int32Array arr, FS_INT32 nNewSize, FS_INT32 nGrowBy);

	//************************************
	// Function:  RemoveAll
	// Param[in]: arr		The input pointer array.
	// Return:    void
	// Remarks:   Cleans up the array.
	// Notes:
	//************************************
	static void	RemoveAll(FS_Int32Array arr);

	//************************************
	// Function:  GetAt
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Return:    An element.
	// Remarks:	  Retrieves an element specified by an index number.
	// Notes:
	//************************************
	static FS_INT32 GetAt(FS_Int32Array arr, FS_INT32 index);

	//************************************
	// Function:  SetAt
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of the element.
	// Param[in]: newItem	An element
	// Return:    void
	// Remarks:	  Overwrites an element specified by an index number.
	// Notes:
	//************************************
	static void SetAt(FS_Int32Array arr, FS_INT32 index, FS_INT32 newItem);

	//************************************
	// Function:  SetAtGrow
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Param[in]: newItem	The input element.
	// Return:    void
	// Remarks:	  Sets an element value at specified position. Potentially grow the array.
	// Notes:
	//************************************
	static void SetAtGrow(FS_Int32Array arr, FS_INT32 index, FS_INT32 newItem);

	//************************************
	// Function:  Add
	// Param[in]: arr		The input pointer array.
	// Param[in]: newItem	The input element.
	// Return:    The added element's index in the array.
	// Remarks:   Adds an element at the tail. Potentially grow the array.
	// Notes:
	//************************************
	static FS_INT32 Add(FS_Int32Array arr, FS_INT32 newItem);

	//************************************
	// Function:  Append
	// Param[in]: arr		The input pointer array.
	// Param[in]: srcArr	The input array.
	// Return:    The old size in elements.
	// Remarks:	  Appends an array.
	// Notes:
	//************************************
	static FS_INT32 Append(FS_Int32Array arr, const FS_Int32Array srcArr);

	//************************************
	// Function:  Copy
	// Param[in]: arr		The input pointer array.
	// Param[in]: srcArr	The input array.
	// Return:    void
	// Remarks:   Copies from an array.
	// Notes:
	//************************************
	static void	Copy(FS_Int32Array arr, FS_Int32Array srcArr);

	//************************************
	// Function:    GetDataPtr
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index of element in the array.
	// Return:    A pointer to the specified element.
	// Remarks:   Gets a pointer to the specified element in the array. Direct pointer access.
	// Notes:
	//************************************
	static FS_INT32* GetDataPtr(FS_Int32Array arr, FS_INT32 index);

	//************************************
	// Function:  InsertAt
	// Param[in]: arr			The input pointer array.
	// Param[in]: index			Specifies the zero-based index in the array.
	// Param[in]: newItem	    Specifies the element value to insert.
	// Param[in]: nCount		Specifies the count of the element to insert.
	// Return:    void
	// Remarks:   Inserts one or more continuous element at specified position.
	// Notes:
	//************************************
	static void InsertAt(FS_Int32Array arr, FS_INT32 index, FS_INT32 newItem, FS_INT32 nCount);

	//************************************
	// Function:  RemoveAt
	// Param[in]: arr		The input pointer array.
	// Param[in]: index		Specifies the zero-based index in the array.
	// Param[in]: nCount	Specifies the count of element to remove.
	// Return:    void
	// Remarks:   Removes a number of elements at specified position.
	// Notes:
	//************************************
	static void	RemoveAt(FS_Int32Array arr, FS_INT32 index, FS_INT32 nCount);

	//************************************
	// Function:  InsertNewArrayAt
	// Param[in]: arr			The input pointer array.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to insert at.
	// Param[in]: newArray		The input array.
	// Return:    void
	// Remarks:   Inserts an array at specified position.
	// Notes:
	//************************************
	static void	InsertNewArrayAt(FS_Int32Array arr, FS_INT32 nStartIndex, FS_Int32Array newArray);

	//************************************
	// Function:  Find
	// Param[in]: arr			The input pointer array.
	// Param[in]: item			The input element.
	// Param[in]: nStartIndex	Specifies the zero-based index of start element to find.
	// Return:	  An index of the found element. It can be -1 for finding none.
	// Remarks:   Finds an element from specified position to last
	// Notes:
	//************************************
	static FS_INT32 Find(FS_Int32Array arr, FS_INT32 item, FS_INT32 nStartIndex);

	//************************************
	 // Function:  GetData	   
	 // Param[in]: arr			The input DWord array.	
	 // Return:	  Get the element data.
	 // Remarks:  Direct Access to the element data.
	 // Notes:
	 //************************************
	static  FS_INT32* GetData(FS_Int32Array arr);
};


class CFS_RegistryManager_V14
{
public:
	//************************************
	// Function:  RegistryGetProfilePath
	// Param[out]: outProfilePath It receives the registry's profile path of the Foxit Reader.
	// Return:	void
	// Remarks:	Gets the registry's profile path of the Foxit Reader.
	// Notes:
	//************************************
	static void RegistryGetProfilePath(FS_WideString* outProfilePath);

	//************************************
	// Function:  RegistryWriteInt
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[in]: nValue		The input int value.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Write int value to the specified registry. If you want to set the value in registry like 
	// <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	// <param>lpszSection</param> can be set as <Italic>"Create Link"</Italic>.
	// If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	// <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
	// Notes:
	//************************************
	static FS_BOOL RegistryWriteInt(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry, FS_INT32 nValue);

	//************************************
	// Function:  RegistryWriteBinary
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[in]: pData			The input binary data.
	// Param[in]: nValue		The size of the binary data.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Write binary value to the specified registry. If you want to set the value in registry like 
	// <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	// <param>lpszSection</param> can be set as <Italic>"Create Link"</Italic>.
	// If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	// <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
	// Notes:
	//************************************
	static FS_BOOL RegistryWriteBinary(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry, FS_LPBYTE pData, FS_UINT nBytes);

	//************************************
	// Function:  RegistryWriteString
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[in]: lpszValue		The input string.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Write string to the specified registry. If you want to set the value in registry like 
	// <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	// <param>lpszSectio</param>n can be set as <Italic>"Create Link"</Italic>.
	// If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	// <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
	// Notes:
	//************************************
	static FS_BOOL RegistryWriteString(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry, FS_LPCWSTR lpszValue);

	//************************************
	// Function:  RegistryGetInt
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Return:	The int value in the specified section.
	// Remarks:	Gets the int value in the specified section.
	// Notes:
	//************************************
	static FS_UINT RegistryGetInt(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry, FS_INT32 nDefault);

	//************************************
	// Function:  RegistryGetBinary
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[out]: ppData		It receives the binary data.
	// Param[out]: pBytes		It receives the size of the binary data.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Gets the binary value in the specified section.
	// Notes: It need to use FSRegistryManagerRegistryDeleteBinary to release data.
	//************************************
	static FS_BOOL RegistryGetBinary(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry, FS_LPBYTE* ppData, FS_UINT* pBytes);

	//************************************
	// Function:  RegistryGetString
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[out]: outString	It receives the string.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Gets the string value in the specified section.
	// Notes:
	//************************************
	static FS_BOOL RegistryGetString(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry, FS_WideString* outString, FS_LPCWSTR lpszDefault);

	//************************************
	// Function:  RegistryGetEntryCount
	// Param[in]: lpszSection	The input registry section.
	// Return:	The entry count in the specified section.
	// Remarks:	Gets the entry count in the specified section.
	// Notes:
	//************************************
	static FS_INT32 RegistryGetEntryCount(FS_LPCWSTR lpszSection);

	//************************************
	// Function:  RegistryGetEntryName
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: nIndex		The specified index.
	// Param[out]: outName		It receives the entry name.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Gets the entry name in the specified section.
	// Notes:
	//************************************
	static FS_BOOL RegistryGetEntryName(FS_LPCWSTR lpszSection, FS_INT32 nIndex, FS_WideString* outName);

	//************************************
	// Function:  RegistryRemoveSection
	// Param[in]: lpszSection	The input registry section.
	// Return:	void
	// Remarks:	Removes the specified section.
	// Notes:
	//************************************
	static void RegistryRemoveSection(FS_LPCWSTR lpszSection);

	//************************************
	// Function:  RegistryRemoveEntry
	// Param[in]: lpszSection	The input registry section.
	// Param[in]: lpszEntry		The input registry entry.
	// Return:	void
	// Remarks:	Removes the specified entry.
	// Notes:
	//************************************
	static void RegistryRemoveEntry(FS_LPCWSTR lpszSection, FS_LPCWSTR lpszEntry);

	//************************************
	// Function:  RegistryGetKeyCounts
	// Param[in]: lpszSection	The input registry section.
	// Return:	The counts of key for the specified section.
	// Remarks:	Gets the counts of key for the specified section.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegistryGetProfilePath
	//************************************
	static FS_INT32 RegistryGetKeyCounts(FS_LPCWSTR lpszSection);

	//************************************
	// Function:  RegistryGetKeyName
	// Param[in]: lpszSection	The input registry section.	
	// Param[in]: nIndex		The specified index.
	// Param[out]: outName		It receives the key name.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Gets the key name in the specified section.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	// See: FRAppRegistryGetProfilePath
	//************************************
	static FS_BOOL RegistryGetKeyName(FS_LPCWSTR lpszSection, FS_INT32 nIndex, FS_WideString* outName);

	//************************************
	// Function:  DeleteGetBinary	
	// Param[in]: pData		It receives the binary data.
	// Return:	void
	// Remarks:	Release data from FSRegistryManagerRegistryGetBinary.
	// Notes:
	//************************************
	static void RegistryDeleteBinary(FS_LPBYTE pData);

	//************************************
	// Function:  GetEntryCountsByHKey	
	// Param[in]: key		The input handle to an open registry key.
	// Return:	FS_INT32    Get the entry counts of specified key.
	// Remarks:	Get the counts of specified key.
	// Notes:
	//************************************
	static FS_INT32	GetEntryCountsByHKey(FS_LPVOID key);

	//************************************
	// Function:  RemoveEntryByHKey	
	// Param[in]: key		    The input handle to an open registry key.
	// Param[in]: lpszEntry		The input entry.
	// Return:	void
	// Remarks: Remove entry by specified key.
	// Notes:
	//************************************
	static void RemoveEntryByHKey(FS_LPVOID key, FS_LPCWSTR lpszEntry);

	//************************************
	// Function:  GetKeyCountsByHKey	
	// Param[in]: key		The input handle to an open registry key.
	// Return:	FS_INT32    Get the key counts of specified key.
	// Remarks:	Get the key counts of specified key.
	// Notes:
	//************************************
	static FS_INT32	GetKeyCountsByHKey(FS_LPVOID key);

	//************************************
	// Function:  GetKeyNameByHKey	
	// Param[in]: key		    The input handle to an open registry key.
	// Param[in]: nIndex		The input index.
	// Param[in\out]: wsName	Get the key name.
	// Return:	FS_BOOL.   TRUE: Get key name success.
	// Remarks:	Get the key name of specified key and index.
	// Notes:
	//************************************
	static FS_BOOL GetKeyNameByHKey(FS_LPVOID key, FS_INT32 nIndex, FS_WideString* wsName);

	//************************************
	// Function:  GetKeyNameListByHKey	
	// Param[in]: key		                The input handle to an open registry key.
	// Param[in\out]: csKeyNameArray		Get the key names.
	// Return:	FS_INT32.
	// Remarks:	Get the key names of specified key.
	// Notes:
	//************************************
	static FS_INT32	GetKeyNameListByHKey(FS_LPVOID key, FS_WideStringArray* csKeyNameArray);

	//************************************
	// Function:  GetHKey	
	// Param[in]: lpszSection		The input section.
	// Param[bCreate]: bCreate		Whether need to create when the key not exist.
	// Return:	FS_LPVOID.
	// Remarks:	Get the input handle to an open registry key.
	// Notes:
	//************************************
	static FS_LPVOID GetHKey(FS_LPCWSTR lpszSection, FS_BOOLEAN bCreate);

	//************************************
	// Function:  CloseHKey	
	// Param[in]: key		                The input handle to an open registry key.	
	// Return:	void
	// Remarks:	Close the input handle to an open registry key.	
	// Notes:
	//************************************
	static void CloseHKey(FS_LPVOID key);

	//************************************
	// Function:  WriteProfileIntByHKey
	// Param[in]: key       	The input registry key.	
	// Param[in]: lpszEntry		The input registry entry.
	// Param[in]: nValue		The input int value.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Write int value to the specified registry. If you want to set the value in registry like 
	// <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	// <param>lpszSection</param> can be set as <Italic>"Create Link"</Italic>.
	// If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	// <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
	// Notes:
	//************************************
	static FS_BOOLEAN WriteProfileIntByHKey(FS_LPVOID key, FS_LPCWSTR lpszEntry, FS_INT32 nValue);

	//************************************
	// Function:  WriteProfileBinaryByHKey
	// Param[in]: key	        The input registry key.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[in]: pData			The input binary data.
	// Param[in]: nBytes		The size of the binary data.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Write binary value to the specified registry. If you want to set the value in registry like 
	// <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	// <param>lpszSection</param> can be set as <Italic>"Create Link"</Italic>.
	// If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	// <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
	// Notes:
	//************************************
	static FS_BOOLEAN WriteProfileBinaryByHKey(FS_LPVOID key, FS_LPCWSTR lpszEntry, FS_LPBYTE pData, FS_UINT nBytes);

	//************************************
	// Function:  WriteProfileStringByHKey
	// Param[in]: key       	The input registry key.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[in]: lpszValue		The input string.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Write string to the specified registry. If you want to set the value in registry like 
	// <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	// <param>lpszSectio</param>n can be set as <Italic>"Create Link"</Italic>.
	// If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	// <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
	// Notes:
	//************************************
	static FS_BOOLEAN WriteProfileStringByHKey(FS_LPVOID key, FS_LPCWSTR lpszEntry, FS_LPCWSTR lpszValue);

	//************************************
	// Function:  GetProfileIntByHKey
	// Param[in]: key	        The input registry key.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[in]: nDefault		The input default value.
	// Return:	The int value in the specified section.
	// Remarks:	Gets the int value in the specified section.
	// Notes:
	//************************************
	static FS_UINT GetProfileIntByHKey(FS_LPVOID key, FS_LPCWSTR lpszEntry, FS_INT32 nDefault);

	//************************************
	// Function:  GetProfileBinaryByHKey
	// Param[in]: lpszSection	The input registry key.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[out]: ppData		It receives the binary data.
	// Param[out]: pBytes		It receives the size of the binary data.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Gets the binary value in the specified section.
	// Notes: It need to use FSRegistryManagerRegistryDeleteBinary to release data.
	//************************************
	static FS_BOOLEAN GetProfileBinaryByHKey(FS_LPVOID key, FS_LPCWSTR lpszEntry, FS_LPBYTE* ppData, FS_UINT* pBytes);

	//************************************
	// Function:  GetProfileStringByHKey
	// Param[in]: lpszSection	The input registry key.
	// Param[in]: lpszEntry		The input registry entry.
	// Param[in]: lpszDefault	The input default value.
	// Param[out]: outString	It receives the string.
	// Return:	<a>TRUE</a> means successful, otherwise not.
	// Remarks:	Gets the string value in the specified section.
	// Notes:
	//************************************
	static FS_BOOL GetProfileStringByHKey(FS_LPVOID key, FS_LPCWSTR lpszEntry, FS_LPCWSTR lpszDefault, FS_WideString* outString);

	//************************************
	// Function:  GetKeyNameList	
	// Param[in]: lpszSection		        The input registry section.
	// Param[in\out]: csKeyNameArray		Get the key names.
	// Return:	FS_INT32.
	// Remarks:	Get the key names of specified key.
	// Notes:
	//************************************
	static FS_INT32	GetKeyNameList(FS_LPCWSTR lpszSection, FS_WideStringArray* csKeyNameArray);
};

class CFS_FloatRect_V14
{
public:	
	//************************************
	// Function:  IsEmpty	
	// Param[in]: rect		        The input FS_FloatRect.	
	// Return:	FS_BOOLEAN.
	// Remarks:	Check input rect is empty.
	// Notes:
	//************************************
	static FS_BOOLEAN	 IsEmpty(FS_FloatRect rect);

	//************************************
	// Function:  Normalize	
	// Param[in]: rect		        The pointer of FS_FloatRect.	
	// Return:	void.
	// Remarks:	Normalize the rect. Make sure left <= right, and bottom <= top.
	// Notes:
	//************************************
	static void			 Normalize(FS_FloatRect* rect);

	//************************************
	// Function:  IsEqualRect	
	// Param[in]: rect		        The input FS_FloatRect.	
	// Param[in]: src		        The rect to compare.
	// Return:	FS_BOOLEAN.  <b>true</b> means equal, while <b>false</b> means not equal.
	// Remarks:	Compare two rectangles. Please make sure they are normalized first.
	// Notes:
	//************************************
	static FS_BOOLEAN	 IsEqualRect(FS_FloatRect rect, const FS_FloatRect src);

	//************************************
	// Function:  IsNotEqualRect	
	// Param[in]: rect		        The input FS_FloatRect.	
	// Param[in]: src		        The rect to compare.
	// Return:	FS_BOOLEAN.  <b>true</b> means not equal, while <b>false</b> means equal.
	// Remarks:	Compare two rectangles. Please make sure they are normalized first.
	// Notes:
	//************************************
	static FS_BOOLEAN	 IsNotEqualRect(FS_FloatRect rect, const FS_FloatRect src);

	//************************************
	// Function:  Reset	
	// Param[in]: rect		        The pointer of FS_FloatRect.		
	// Return:	void
	// Remarks:	Reset rectangle, set coordinates to 0. 
	// Notes:
	//************************************
	static void			 Reset(FS_FloatRect* rect);

	//************************************
	// Function:  Contains	
	// Param[in]: rect		        The input FS_FloatRect.	
	// Param[in]: other_rect		The other provided rect.
	// Return:	FS_BOOLEAN   <b>true</b> means current rectangle fully contains the other one, while <b>false</b> means not.
	// Remarks:	Check if current rectangle fully contains the other provided rectangle.
	//        That means to check if the other rectangle is fully inside current one.
	// Notes:
	//************************************
	static FS_BOOLEAN	 Contains(FS_FloatRect rect, const FS_FloatRect other_rect);

	//************************************
	// Function:  Contains2	
	// Param[in]: rect		        The input FS_FloatRect.	
	// Param[in]: x		            The x coordinate of the provided point.
	// Param[in]: y		            The y coordinate of the provided point.
	// Return:	FS_BOOLEAN  <b>true</b> means current rectangle contains the provided point, while <b>false</b> means not.
	// Remarks:	Check if current rectangle fully contains the other provided rectangle.
	//        That means to check if the other rectangle is fully inside current one.
	// Notes:
	//************************************
	static FS_BOOLEAN	 Contains2(FS_FloatRect rect, FS_FLOAT x, FS_FLOAT y);

	//************************************
	// Function:  Transform	
	// Param[in]: rect		        The pointer of FS_FloatRect.	
	// Param[in]: pMatrix		    The transformation matrix.
	// Return:	void
	// Remarks:	Transform a matrix.
	// Notes:
	//************************************
	static void			 Transform(FS_FloatRect* rect, const FS_AffineMatrix pMatrix);

	//************************************
	// Function:  Intersect	
	// Param[in]: rect		        The pointer of FS_FloatRect.	
	// Param[in]: other_rect		The rect to intersect with.
	// Return:	void
	// Remarks:	Intersect with a rect.
	// Notes:
	//************************************
	static void			 Intersect(FS_FloatRect* rect, const FS_FloatRect other_rect);

	//************************************
	// Function:  Union	
	// Param[in]: rect		        The pointer of FS_FloatRect.	
	// Param[in]: other_rect		The rect to union with.
	// Return:	void
	// Remarks:	Union with a rect.
	// Notes:
	//************************************
	static void			 Union(FS_FloatRect* rect, const FS_FloatRect other_rect);

	//************************************
	// Function:  GetInnerRect	
	// Param[in]: rect		        The input FS_FloatRect.	
	// Param[in\out]: outRect		The inner integer rectangle.
	// Return:	void    
	// Remarks:	Convert to an inner integer rectangle. 
	// Notes:
	//************************************
	static void  		 GetInnerRect(FS_FloatRect rect, FS_Rect* outRect);

	//************************************
	// Function:  GetOutterRect	
	// Param[in]: rect		        The input FS_FloatRect.	
	// Param[in\out]: outRect		The outer integer rectangle.
	// Return:	void    
	// Remarks:	Convert to an outer integer rectangle.
	// Notes:
	//************************************
	static void			 GetOutterRect(FS_FloatRect rect, FS_Rect* outRect);

	//************************************
	// Function:  GetClosestRect	
	// Param[in]: rect		        The input FS_FloatRect.	
	// Param[in\out]: outRect		The closest integer rectangle.
	// Return:	void    
	// Remarks:	Get a closest integer rectangle.
	// Notes:
	//************************************
	static void			 GetClosestRect(FS_FloatRect rect, FS_Rect* outRect);

	//************************************
	// Function:  Substract4	
	// Param[in]: rect		        The input FS_FloatRect.	
	// Param[in]: substract_rect	The rectangle to be subtracted.
	// Param[in\out]: pRects		The rectangle array to receive result rectangles.
	// Return:	FS_INT32    The number of result rectangles. 
	// Remarks: Subtract a rectangle area from this rectangle. The result might be up to 4 rectangles.
	//        The number of result rectangles are returned.Caller must prepare enough rectangles(up to 4).
	// Notes:
	//************************************
	static FS_INT32		 Substract4(FS_FloatRect rect, FS_FloatRect substract_rect, FS_FloatRect* pRects);

	//************************************
	// Function:  InitRect	
	// Param[in]: rect		        The pointer of FS_FloatRect.	
	// Param[in]: x	                The x-coordinate of the input point.
	// Param[in]: y		            The y-coordinate of the input point.
	// Return:	void
	// Remarks: Initialize the rectangle to a single point.
	// Notes:
	//************************************
	static void			 InitRect(FS_FloatRect* rect, FS_FLOAT x, FS_FLOAT y);

	//************************************
	// Function:  UpdateRect	
	// Param[in]: rect		        The pointer of FS_FloatRect.	
	// Param[in]: x	                The x-coordinate of the input point.
	// Param[in]: y		            The y-coordinate of the input point.
	// Return:	void
	// Remarks: Update the rectangle to contain the specified point.
	// Notes:
	//************************************
	static void			 UpdateRect(FS_FloatRect* rect, FS_FLOAT x, FS_FLOAT y);

	//************************************
	// Function:  Width	
	// Param[in]: rect		        The input FS_FloatRect.		
	// Return:	FS_FLOAT   Width of the rectangle.
	// Remarks: Get the width of the rectangle.
	// Notes:
	//************************************
	static FS_FLOAT 	 Width(FS_FloatRect rect);

	//************************************
	// Function:  Height	
	// Param[in]: rect		        The input FS_FloatRect.		
	// Return:	FS_FLOAT   Height of the rectangle.
	// Remarks: Get the height of the rectangle.
	// Notes:
	//************************************
	static FS_FLOAT		 Height(FS_FloatRect rect);

	//************************************
	// Function:  Inflate	
	// Param[in]: rect		        The pointer of FS_FloatRect.
	// Param[in]: x		            The number to inflate the left and right of the rectangle.
	// Param[in]: y		            The number to inflate the top and bottom of the rectangle.
	// Return:	void
	// Remarks: Increases the width and height of the rectangle.
	// Notes:
	//************************************
	static void			 Inflate(FS_FloatRect* rect, FS_FLOAT x, FS_FLOAT y);

	//************************************
	// Function:  Inflate2	
	// Param[in]: rect		        The pointer of FS_FloatRect.
	// Param[in]: left		        The number to inflate the left of the rectangle.
	// Param[in]: bottom		    The number to inflate the bottom of the rectangle.
	// Param[in]: right		        The number to inflate the right of the rectangle.
	// Param[in]: top		        The number to inflate the top of the rectangle.
	// Return:	void
	// Remarks: Increases the width and height of the rectangle.
	// Notes:
	//************************************
	static void			 Inflate2(FS_FloatRect* rect, FS_FLOAT left, FS_FLOAT bottom, FS_FLOAT right, FS_FLOAT top);

	//************************************
	// Function:  Inflate3	
	// Param[in]: rect		        The pointer of FS_FloatRect.
	// Param[in]: rt		        The rectangle to inflate each side.
	// Return:	void
	// Remarks: Increases the width and height of the rectangle.
	// Notes:
	//************************************
	static void			 Inflate3(FS_FloatRect* rect, const FS_FloatRect rt);

	//************************************
	// Function:  Deflate	
	// Param[in]: rect		        The pointer of FS_FloatRect.
	// Param[in]: x		            The number to deflate the left and right of the rectangle.
	// Param[in]: y					The number to deflate the top and bottom of the rectangle.
	// Return:	void
	// Remarks: Decreases the width and height of the rectangle.
	// Notes:
	//************************************
	static void			 Deflate(FS_FloatRect* rect, FS_FLOAT x, FS_FLOAT y);

	//************************************
	// Function:  Deflate2	
	// Param[in]: rect		        The pointer of FS_FloatRect.
	// Param[in]: left		        The number to inflate the left of the rectangle.
	// Param[in]: bottom		    The number to inflate the bottom of the rectangle.
	// Param[in]: right		        The number to inflate the right of the rectangle.
	// Param[in]: top		        The number to inflate the top of the rectangle.
	// Param[in]: y					The number to deflate the top and bottom of the rectangle.
	// Return:	void
	// Remarks: Decreases the width and height of the rectangle.
	// Notes:
	//************************************
	static void			 Deflate2(FS_FloatRect* rect, FS_FLOAT left, FS_FLOAT bottom, FS_FLOAT right, FS_FLOAT top);

	//************************************
	// Function:  Deflate3	
	// Param[in]: rect		        The pointer of FS_FloatRect.
	// Param[in]: rt		        The rectangle to inflate each side.
	// Return:	void
	// Remarks: Decreases the width and height of the rectangle.
	// Notes:
	//************************************
	static void			 Deflate3(FS_FloatRect* rect, const FS_FloatRect rt);

	//************************************
	// Function:  Translate	
	// Param[in]: rect		        The pointer of FS_FloatRect.
	// Param[in]: e		            The rectangle to inflate each side.
	// Param[in]: f		            The rectangle to inflate each side.
	// Return:	void
	// Remarks: Translate rectangle.
	// Notes:
	//************************************
	static void			 Translate(FS_FloatRect* rect, FS_FLOAT e, FS_FLOAT f);

	//************************************
	// Function:  GetBBox	
	// Param[in]: pPoints		        The input points array.
	// Param[in]: nPoints		        The number of points in the array.
	// Param[in\out]: outRect		    Get the bounding box of input points array.
	// Return:	void
	// Remarks: Get the bounding box of input points array.
	// Notes:
	//************************************
	static void          GetBBox(const FS_FloatPoint* pPoints, FS_INT32 nPoints, FS_FloatRect* outRect);	
};

class CFS_CORLOR_V16
{
public:	
	//************************************
    // Function:  ToArgbDecode
    // Param[in]: argb	The input FS_ARGB value.	
	// Param[out]:a		It receives the alpha component.
	// Param[out]: rgb	It receives the RGB value.
	// Return: void
	// Remarks: Decode a FX_ARGB to the alpha and RGB values.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static void ToArgbDecode(FS_ARGB argb, FS_INT32* a, FS_COLORREF* rgb);

    //************************************
    // Function:  ToArgbDecode2
    // Param[in]: argb	The input FS_ARGB value.	
    // Param[out]:a		It receives the alpha component.
    // Param[out]: r	It receives the red component.
	// Param[out]: g	It receives the green component.
	// Param[out]: b	It receives the blue component.
    // Return: void
    // Remarks: Decode a FX_ARGB to the alpha, red, green and blue components.
    // Notes:
    // Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
    //************************************
	static void ToArgbDecode2(FS_ARGB argb, FS_INT32* a, FS_INT32* r, FS_INT32* g, FS_INT32* b);
	
	 //************************************
	 // Function:  ToArgbEncode
	 // Param[in]: a			The input alpha component.
	 // Param[in]: r			The input red component.
	 // Param[in]: g			The input green component.
	 // Param[in]: b			The input blue component.
	 // Return: FS_ARGB         Return a FX_ARGB value.
	 // Remarks: Encode a FX_ARGB from the alpha, red, green, and blue components.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	 //************************************
	static FS_ARGB ToArgbEncode(FS_INT32 a, FS_INT32 r, FS_INT32 g, FS_INT32 b);
	
	//************************************
	// Function:  ToArgbEncode2
	// Param[in]: a			The input alpha component.
	// Param[in]: rgb			The input RGB value.
	// Return: FS_ARGB        Return a FX_ARGB value.
	// Remarks: Encode a FX_ARGB from the alpha and RGB values.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FS_ARGB ToArgbEncode2(FS_INT32 a, FS_COLORREF rgb);

	//************************************
	// Function:  ToRgbEncode
	// Param[in]: r			The input red component.
	// Param[in]: g			The input green component.
	// Param[in]: b			The input blue component.
	// Return: FS_COLORREF         Return a FS_COLORREF value.
	// Remarks: Encode a FX_COLORREF from the red, green, and blue components.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FS_COLORREF ToRgbEncode(FS_INT32 r, FS_INT32 g, FS_INT32 b);

	//************************************
	// Function:  GetGValueFromColor
	// Param[in]: rgb			The input FS_COLORREF.
	// Return: FS_FLOAT         Return green component.
	// Remarks: Return green component.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FS_INT32    GetGValueFromColor(FS_COLORREF rgb);

	//************************************
	// Function:  GetRValueFromColor
	// Param[in]: rgb			The input FS_COLORREF.
	// Return: FS_FLOAT         Return red component.
	// Remarks: Return red component.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FS_INT32    GetRValueFromColor(FS_COLORREF rgb);

	//************************************
	// Function:  GetBValueFromColor
	// Param[in]: rgb			The input FS_COLORREF.
	// Return: FS_FLOAT         Return blue component.
	// Remarks: Return blue component.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static FS_INT32    GetBValueFromColor(FS_COLORREF rgb);

	//************************************
	// Function:  AdobeCMYKtosRGB
	// Param[in]: c			    The input c value.
	// Param[in]: m			    The input m value.
	// Param[in]: y			    The input y value.
	// Param[in]: k			    The input k value.
	// Param[in/out]: R			Get R value.
	// Param[in/out]: G			Get G value.
	// Param[in/out]: B			Get B value.
	// Return: void        
	// Remarks: CMYK to RGB.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
	// Deprecated: Internal use
	//************************************
	static void AdobeCMYKtosRGB(FS_FLOAT c, FS_FLOAT m, FS_FLOAT y, FS_FLOAT k, FS_FLOAT* R, FS_FLOAT* G, FS_FLOAT* B);
};

class CFS_GLOG_V16 //Internal use
{
public:
	static void LogMessage(FS_GLOG_Type logType, FS_LPCSTR msg);
};

class CFS_CCodec_ModuleMgr_V16
{
public:	
	//************************************
	// Function:  Create	
	// Return:	 FS_CCodecModuleMgr.
	// Remarks:   Create a Codec module.
	// Notes:
	//************************************
	static FS_CCodecModuleMgr Create();

	//************************************
	// Function:  DestroyMgr	
	// Return:	 void.
	// Remarks:  Destroy the current Codec module.
	// Notes:
	//************************************
	static void DestroyMgr(FS_CCodecModuleMgr codeMgr);	

	//************************************
	// Function:  PngEncode	
	// Param[in]: codeMgr			The input FS_CCodecModuleMgr.
	// Param[in]: pSource			The source image to be encoded.
	// Param[in]: file_name			Encoded PNG file save position.
	// Param[in]: bInterlace	    Whether the PNG file be interlace(7 passes).
	// Param[in]: pAttribute	    The attribute information of bitmap.
	// Param[in]: filter	        The filter type of encoded PNG file.
	// Return:	 FS_BOOLEAN. Non-zero means success, otherwise failure.
	// Remarks:  Encode an image to a file, Unicode version. 
	// Notes:
	//************************************
	static FS_BOOLEAN	PngEncode(FS_CCodecModuleMgr codeMgr, FS_DIBitmap pSource, FS_LPCWSTR file_name, FS_BOOLEAN bInterlace, FS_DIBAttribute pAttribute, FS_PNG_FILTER filter);

	//************************************
	// Function:  BmpEncode	
	// Param[in]: codeMgr			The input FS_CCodecModuleMgr.
	// Param[in]: pSource			The source image to be encoded.
	// Param[out]: dst_buf			It receives the encoded BMP data. The caller should set the dst_buf NULL when encode gif source dib first time.
	// Param[out]: dst_size	        It receives the size of the encoded BMP data. The caller must release the data by FX_Free.
	// Param[in]: pAttribute	    The attribute information of bitmap.
	// Return:	 FS_BOOLEAN. Non-zero means success, otherwise failure.
	// Remarks:  Encode the source dib to BMP file stream. Only support RGB color space.
	// Notes:
	//************************************
	static FS_BOOLEAN	BmpEncode(FS_CCodecModuleMgr codeMgr, FS_DIBitmap pSource, FS_LPBYTE* dst_buf, FS_DWORD* dst_size, FS_DIBAttribute pAttribute);
	
	 //************************************
	 // Function:  TiffEncode	
	 // Param[in]: codeMgr			The input FS_CCodecModuleMgr.
	 // Param[in]: file_ptr			It receives the encoded TIFF data.
	 // Param[in]: ppSource			The pointer of source image list.
	 // Param[in]: frames	        The number of source image to be encoded(the list size).
	 // Param[in]: ppAttribute	    The attribute information of bitmap.
	 // Return:	 FS_BOOLEAN. Non-zero means success, otherwise failure.
	 // Remarks: Encode an image.
	 // Notes:
	 //************************************
	static FS_BOOLEAN	TiffEncode(FS_CCodecModuleMgr codeMgr, FS_FileStream file_ptr, const FS_DIBitmap* ppSource, FS_INT32 frames, FS_DIBAttribute* ppAttribute);

	//************************************
	// Function:  LoadWorkingIccProfile	
	// Param[in]: space			    The input FS_ICCWorkingSpace.
	// Param[in/out]: pIccProfileData			Get the profile data.
	// Param[in/out]: dwIccProfileSize	        Get the profile size.
	// Return:	 FS_BOOLEAN.   true: Load work icc profile success.
	// Remarks: Encode an image.
	// Notes:
	//************************************
	static FS_BOOLEAN LoadWorkingIccProfile(FS_ICCWorkingSpace space, FS_LPBYTE* pIccProfileData, FS_DWORD* dwIccProfileSize);
	
	 //************************************
	 // Function:  CreateTransform	
	 // Param[in]: pInputParam		The input IccParam pointer.
	 // Param[in]: pOutputParam		The output IccParam pointer.
	 // Param[in]: pProofParamL	    The proofing IccParam pointer, NULL if don't use "Proofing" profile.
	 // Param[in]: dwIntent			The intent of transform from src to dst. Default is FSIcc_INTENT_PERCEPTUAL.
	 // Param[in]: dwFlag			A combination of bit-field constants described in FSIcc_FLAGS_XXX above.
	 // Param[in]: dwPrfIntent		The intent of proofing intent. Default is FSIcc_INTENT_ABSOLUTE_COLORIMETRIC.
	 // Param[in]: dwPrfFlag	    The combination of proofing combination. Default is FSIcc_FLAGS_SOFTPROOFING.
	 // Return:	 FS_LPVOID.   A handle to a transform object on success, NULL on error. This handle will be free when
	 //		FS_CCodecModuleMgr destructed, so it should not be destroy by DestroyTransform function.
	 // Remarks:Create a transform from source color space to destination color space.
	 // The obtained transform emulates the device described by the "Proofing" profile.
	 // Useful to preview final result without rendering to the physical medium.
	 // To enable proofing Icc_FLAGS_SOFTPROOFING : does emulate the Proofing device.
	 // Notes:
	 //************************************
	static FS_LPVOID	CreateTransform(FS_IccParam pInputParam,
		FS_IccParam pOutputParam,
		FS_IccParam pProofParamL,
		FS_DWORD dwIntent,
		FS_DWORD dwFlag,
		FS_DWORD dwPrfIntent,
		FS_DWORD dwPrfFlag);

	 //************************************
	 // Function:  JpegEncode	
	 // Param[in]: codeMgr		    The input FS_CCodecModuleMgr.
	 // Param[in]: pSource			The source image to be encoded.
	 // Param[out]: dest_buf		It receives the encoded JPEG data.
	 // Param[out]: dest_size		It receives the size of the encoded JPEG data. The caller must release the data by FX_Free.
	 // Param[in]: quality			The compressed quality of destination jpeg image(0~100).
	 // Param[in]: pParam			The param that h_samp_factor and v_samp_factor of each color component.
	 // Param[in]: nParamCount		The param count.
	 // Param[in]: icc_buf			The icc profile will embeded to the compressed stream.
	 // Param[in]: icc_length		The icc profile stream size.
	 // Param[in]: pAttribute		The attribute information of bitmap.
	 // Param[in]: format			The jpeg image format:(FSJPEGSTANDARD、FSJPEGOPTIMIZED、FSJPEGPROGRESSIVE)
	 // Return:	FS_BOOLEAN          Non-zero means success, otherwise failure.
	 // Remarks: Encode an image.
	 // If the encoded CMYK stream be embedded to PDF, the application must
	 // set an image dictionaries option entry, / Decode[1 0 1 0 1 0 1 0], first.
	 // Notes:
	 //************************************
	static FS_BOOLEAN JpegEncode(FS_CCodecModuleMgr codeMgr, const FS_DIBSource pSource,
		FS_LPBYTE* dest_buf,
		FS_INT32* dest_size,
		FS_INT32 quality,
		FS_Jpeg_Samp_Param pParam,
		FS_INT32 nParamCount,
		FS_LPCBYTE icc_buf,
		FS_DWORD icc_length,
		FS_DIBAttribute pAttribute,
		FS_JPEG_FORMAT format);

	//************************************
	 // Function:  JpegEncode2	
	 // Param[in]: codeMgr		    The input FS_CCodecModuleMgr.
	 // Param[in]: pSource			The source image to be encoded.
	 // Param[in]: pFile		    The input file wirter.
	 // Param[in]: quality			The compressed quality of destination jpeg image(0~100).
	 // Param[in]: pParam			The param that h_samp_factor and v_samp_factor of each color component.
	 // Param[in]: nParamCount		The param count.
	 // Param[in]: icc_buf			The icc profile will embeded to the compressed stream.
	 // Param[in]: icc_length		The icc profile stream size.
	 // Param[in]: pAttribute		The attribute information of bitmap.
	 // Param[in]: format			The jpeg image format:(FSJPEGSTANDARD、FSJPEGOPTIMIZED、FSJPEGPROGRESSIVE)
	 // Return:	FS_BOOLEAN          Non-zero means success, otherwise failure.
	 // Remarks: Encode an image.
	 // If the encoded CMYK stream be embedded to PDF, the application must
	 // set an image dictionaries option entry, / Decode[1 0 1 0 1 0 1 0], first.
	 // Notes:
	 //************************************
	static FS_BOOLEAN JpegEncode2(FS_CCodecModuleMgr codeMgr, const FS_DIBSource pSource,
		FS_FileWriteHandler pFile,
		FS_INT32 quality,
		FS_Jpeg_Samp_Param pParam,
		FS_INT32 nParamCount,
		FS_LPCBYTE icc_buf,
		FS_DWORD icc_length,
		FS_DIBAttribute pAttribute,
		FS_JPEG_FORMAT format);

	//************************************
	// Function:  PngEncode2	
	// Param[in]: codeMgr			The input FS_CCodecModuleMgr.
	// Param[in]: pSource			The source image to be encoded.
	// Param[out]: dest_buf			It receives the encoded PNG data.
	// Param[out]: dest_size	    It receives the size of the encoded PNG data.
	// Param[in]: bInterlace	    Whether the PNG file be interlace(7 passes)	
	// Param[in]: pAttribute	    The attribute information of bitmap.
	// Param[in]: filter	        The filter type of encoded PNG data.
	// Return:	 FS_BOOLEAN. Non-zero means success, otherwise failure.
	// Remarks:  Encode an image to a memory block, the return buffer must be free by FX_Free. 
	// Notes:
	//************************************
	static FS_BOOLEAN	PngEncode2(FS_CCodecModuleMgr codeMgr, const FS_DIBSource pSource, FS_LPBYTE* dest_buf, FS_DWORD* dest_size, FS_BOOLEAN bInterlace,
		FS_DIBAttribute pAttribute, FS_PNG_FILTER filter);
	
	 //************************************
	 // Function:  TiffModuleSetICCProfile	
	 // Param[in]: codeMgr			The input FS_CCodecModuleMgr.
	 // Param[in]: pucData			Buffer containing ICC profile data.
	 // Param[in]: dwSize			Length of buffer in bytes.
	 // Return:	 FS_BOOLEAN.  Non-zero means success, otherwise failure.
	 // Remarks:  Set an ICC profile associated with the image. 
	 // Notes:
	 //************************************
	static FS_BOOLEAN TiffModuleSetICCProfile(FS_CCodecModuleMgr codeMgr, FS_LPBYTE pucData, FS_DWORD dwSize);

	//************************************
	// Function:  PngModuleSetICCProfile	
	// Param[in]: codeMgr			The input FS_CCodecModuleMgr.
	// Param[in]: pucData			Buffer containing ICC profile data.
	// Param[in]: dwSize			Length of buffer in bytes.
	// Return:	 FS_BOOLEAN.  Non-zero means success, otherwise failure.
	// Remarks:  Set an ICC profile associated with the image. 
    // Notes:
	//************************************
	static FS_BOOLEAN    PngModuleSetICCProfile(FS_CCodecModuleMgr codeMgr, FS_LPBYTE pucData, FS_DWORD dwSize);

	//************************************
	// Function:  CreateJpxEncoder	
	// Param[in]: codeMgr			The input FS_CCodecModuleMgr.
	// Param[in]: pSource			The source image to be encoded.
	// Return:	 FS_JpxEncoder.  
	// Remarks:  Create JPX encoder, providing jpeg2000 encoding.
	// Notes: It need call FSCCodecDeleteJpxEncoder to release FS_JpxEncoder.
	//************************************
	static FS_JpxEncoder CreateJpxEncoder(FS_CCodecModuleMgr codeMgr, FS_DIBSource pSource);

	//************************************
	// Function:  DeleteJpxEncoder	
	// Param[in]: encoder			The input FS_JpxEncoder.
	// Return:	 void  
	// Remarks:  Delete JPX encoder.
	// Notes:
	//************************************
	static void DeleteJpxEncoder(FS_JpxEncoder encoder);

	//************************************
	// Function:  JpxEncoderSetICCProfile	
	// Param[in]: encoder			The input FS_JpxEncoder.
	// Param[in]: pucData			Buffer containing ICC profile data.
	// Param[in]: dwSize			Length of buffer in bytes.
	// Return:	 FS_BOOLEAN.  Non-zero means success, otherwise failure.
	// Remarks:  Set an ICC profile associated with the image. 
	// Notes:
	//************************************
	static FS_BOOLEAN    JpxEncoderSetICCProfile(FS_JpxEncoder encoder, FS_LPBYTE pucData, FS_DWORD dwSize);
	
	 //************************************
	 // Function:  JpxEncoderSetLossless	
	 // Param[in]: encoder			The input FS_JpxEncoder.
	 // Param[in]: isLossless	Is lossless compression or not.
	 // Return:	 FS_BOOLEAN.  Non-zero means success, otherwise failure.
	 // Remarks: Set lossless compression. Ignore the size or quality of target image set before.
	 // Notes:
	 //************************************
	static void JpxEncoderSetLossless(FS_JpxEncoder encoder, FS_BOOLEAN isLossless);
	
	 //************************************
	 // Function:  setColorSpace	
	 // Param[in]: encoder			The input FS_JpxEncoder.
	 // Param[in]: colorSpace		see FS_JP2_Color_Space.
	 // Return:	 FS_BOOLEAN.   Non-zero means success, otherwise failure.
	 // Remarks:  Set the colorspace of the input image.
	 // Notes:
	 //************************************
	static FS_BOOLEAN JpxEncoderSetColorSpace(FS_JpxEncoder encoder, FS_JP2_Color_Space colorSpace);
	
	//************************************
	// Function:  JpxEncoderEncode	
	// Param[in]: encoder			The input FS_JpxEncoder.
	// Param[out]: dst_buf			It receives the encoded JPEG2000 data.
	// Param[out]: dest_size		It receives the size of the encoded JPEG2000 data.
	// Param[in]: pAttribute		Default is NULL.
	// Return:	 FS_BOOLEAN.   Non-zero means success, otherwise failure.
	// Remarks:  Encode an image to a memory block, the return buffer must be free by FSCodeTransformationReleaseEncodeBuffer.
	// Notes:
	//************************************
	static FS_BOOLEAN JpxEncoderEncode(FS_JpxEncoder encoder, FS_LPBYTE* dst_buf, FS_DWORD* dst_size, FS_DIBAttribute pAttribute);
	
	//************************************
	// Function:  JpxEncoderEncode2	
	// Param[in]: encoder			The input FS_JpxEncoder.
	// Param[in]: dst_file			It receives the encoded JPEG2000 data.
	// Param[in]: pAttribute		Default is NULL.
	// Return:	 FS_BOOLEAN.   Non-zero means success, otherwise failure.
	// Remarks:  Encode an image to a memory block, the return buffer must be free by FSCodeTransformationReleaseEncodeBuffer.
	// Notes:
	//************************************
	static FS_BOOLEAN JpxEncoderEncode2(FS_JpxEncoder encoder, FS_FileWriteHandler dst_file, FS_DIBAttribute pAttribute);	
	
	 //************************************
	 // Function:  CreateProgressvieJpxEncoder	
	 // Param[in]: codeMgr			The input FS_JpxEncoder.	
	 // Return:	 FS_ProgressiveJpxEncoder. 
	 // Remarks: Create a progressive Jpx encoder.
	 // After use it, the caller should call FSCCodecDeleteProgressvieJpxEncoder to release the encoder.
	 // Notes:
	 //************************************
	static FS_ProgressiveJpxEncoder	CreateProgressvieJpxEncoder(FS_CCodecModuleMgr codeMgr);

	//************************************
	// Function:  DeleteProgressvieJpxEncoder	
	// Param[in]: codeMgr			The input FS_ProgressiveJpxEncoder.	
	// Return:	void
	// Remarks: Delete a progressive Jpx encoder.	
	// Notes:
	//************************************
	static void	DeleteProgressvieJpxEncoder(FS_ProgressiveJpxEncoder encoder);
	
	 //************************************
	 // Function:  ProgressiveJpxEncodeStart	
	 // Param[in]: pSource			The input image.
	 // Param[in/out]: pFileDest	It receives the encoded data.	
	 // Param[in]:level				The flag indicates which level is used.
	 // Param[in]: pAttribute		The attribute information of bitmap.
	 // Return:	FS_ProgressiveJpx_EncodeStatus   Ready means success, otherwise failure.
	 // Remarks: Prepare for encoding an image.
	 // Notes:
	 //************************************
	static FS_ProgressiveJpx_EncodeStatus ProgressiveJpxEncodeStart(FS_ProgressiveJpxEncoder encoder, const FS_DIBSource pSource, FS_FileStream pFileDest, FS_DWORD level, FS_DIBAttribute pAttibute);

	 //************************************
	 // Function:  ProgressiveJpxEncodeStart2	
	 // Param[in]: pSource			The input image.
	 // Param[in/out]: pFileDest	It receives the encoded data.	
	 // Param[in]:level				The flag indicates which level is used.
	 // param[in]:dest_bpp			The bits - per - pixel of destiny compressed image
	 // Param[in]: pAttribute		The attribute information of bitmap.
	 // Return:	FS_ProgressiveJpx_EncodeStatus   Ready means success, otherwise failure.
	 // Remarks: Prepare for encoding an image.
	 // Notes:
	 //************************************
	static FS_ProgressiveJpx_EncodeStatus ProgressiveJpxEncodeStart2(FS_ProgressiveJpxEncoder encoder, const FS_DIBSource pSource, FS_FileStream pFileDest, FS_DWORD level, FS_FLOAT dest_bpp, FS_DIBAttribute pAttibute);

	//************************************
	// Function:  ProgressiveJpxEncodeContinue	
	// Param[in]: pSource			The input image.
	// Param[in]: pPause			To control the progressive encoding.	
	// Return:	FS_ProgressiveJpx_EncodeStatus   Done means finish, ToBeContinued means not finish.
	// Remarks: Start to encode the image.
	// Notes:
	//************************************
	static FS_ProgressiveJpx_EncodeStatus ProgressiveJpxEncodeContinue(FS_ProgressiveJpxEncoder encoder, FS_PauseHandler pPause);

	//************************************
	// Function:  GetWebModule	
	// Param[in]: codeMgr			The input FS_CCodecModuleMgr.
	// Return:	FS_WebpModuleDecoder   
	// Remarks: Get the web module.
	// Notes:
	//************************************
	static FS_WebpModuleDecoder GetWebpModule(FS_CCodecModuleMgr codeMgr);

	//************************************
	// Function:  WebModuleCreateDecoder	
	// Param[in]: webModule			The input FS_WebpModuleDecoder.
	// Param[in]: src_buf			The source WEBP encoded data.
	// Param[in]: src_size			The size of the encoded data.
	// Return:	FS_LPVOID     The context of the WEBP decoder.
	// Remarks: Create a WEBP decoder.
	// Notes:
	//************************************
	static FS_LPVOID WebpModuleCreateDecoder(FS_WebpModuleDecoder webModule, FS_LPCBYTE src_buf, FS_UINT src_size);

	//************************************
	// Function:  WebModuleGetImageInfo	
	// Param[in]: webModule			The input FS_WebpModuleDecoder.
	// Param[in]: ctx			    The WEBP decoder context.
	// Param[out]: width			It receives the image width.
	// Param[out]: height			It receives the image height.
	// Param[out]: output_nComps	It receives the number of output channels.
	// Return:	FS_LPVOID     The context of the WEBP decoder.
	// Remarks: Get the image information.
	// if output_nComps == 3, then the image should be in FXDIB_Rgb format.
	// if output_nComps == 4, then the image should be in FXDIB_Argb format.
	// Notes:
	//************************************
	static void	WebpModuleGetImageInfo(FS_WebpModuleDecoder webModule, FS_LPVOID ctx, FS_DWORD& width, FS_DWORD& height, FS_DWORD& output_nComps);

	//************************************
	// Function:  WebModuleDecode	
	// Param[in]: webModule			The input FS_WebpModuleDecoder.
	// Param[in]: ctx			    The WEBP decoder context.
	// Param[in/out]: dest_data			It receives the decoded data.
	// Param[in]: pitch			    The row pitch of the provided destination data.
	// Return:	FS_LPVOID     The context of the WEBP decoder.
	// Remarks: Create a WEBP decoder.
	// Notes:
	//************************************
	static FS_BOOLEAN WebpModuleDecode(FS_WebpModuleDecoder webModule, FS_LPVOID ctx, FS_LPBYTE dest_data, FS_INT32 pitch);

	//************************************
	// Function:  WebModuleDestroyDecoder	
	// Param[in]: webModule			The input FS_WebpModuleDecoder.
	// Param[in]: ctx			    The WEBP decoder context.
	// Return:	void
	// Remarks: Destroy a WEBP decoder.
	// Notes:
	//************************************
	static void	WebpModuleDestroyDecoder(FS_WebpModuleDecoder webModule, FS_LPVOID ctx);

	//************************************
	// Function:  SetIccProfilesPath	
	// Param[in]: webModule			The input profiles path.
	// Return:	void
	// Remarks: Set icc profiles path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// Deprecated: Internal use.
	//************************************
	static void	SetIccProfilesPath(const FS_LPCWSTR path);

	//************************************
	// Function:  IsSetIccProfilesPath		
	// Return:	FS_BOOLEAN
	// Remarks: Get if set icc profiles path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN IsSetIccProfilesPath();

	//************************************
	// Function:  SetWorkingIccProfile	
	// Param[in]: space			   The input ICC working space.
	// Param[in]: IccProfileName   The input profiles name.
	// Return:	void
	// Remarks: Get if set icc profiles path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// Deprecated: Internal use.
	//************************************
	static void	SetWorkingIccProfile(FS_ICCWorkingSpace space, const FS_LPCWSTR IccProfileName);

	//************************************
	// Function:  LoadIccProfile		
	// Param[in]: IccProfileName     The input profiles name.
	// Param[out]: pIccProfileData	 Get the profile data.
	// Param[out]: dwIccProfileSize	 Get the profile size.
	// Return:	FS_BOOLEAN
	// Remarks: Load ICC profile.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN LoadIccProfile(const FS_LPCWSTR IccProfileName, FS_LPBYTE* pIccProfileData, FS_DWORD* dwIccProfileSize);
};

class CFS_SYSCommonMethod_V16
{
public:	
    //************************************
    // Function:  SYS_wtoi	
    // Param[in]: str			A wide string. 
    // Return:	FS_INT32.   An integer as converted result.
    // Remarks: Convert a wide string to an integer.
    // Notes:
    //************************************
	static FS_INT32	SYS_wtoi(FS_LPCWSTR str);

	 //************************************
	 // Function:  SYS_atoi	
	 // Param[in]: str		An ANSI string.
	 // Return:	FS_INT32.   An integer as converted result.
	 // Remarks: Convert an ANSI string to an integer.
	 // Notes:
	 //************************************
	static FS_INT32	SYS_atoi(FS_LPCSTR str);

	//************************************
	// Function:  ClientToScreen	
	// Param[in]: hWnd		    The current frame hwnd.
	// Param[in/out]: pt		Convert to screen point.
	// Return:	voit.
	// Remarks: Convert from client to screen point.
	// Notes:
	//************************************
	static void ClientToScreenPoint(FS_HWND hWnd, FS_DevicePoint* pt);

	//************************************
	// Function:  ScreenToClientPoint	
	// Param[in]: hWnd		    The current frame hwnd.
	// Param[in/out]: pt		Convert to client point.
	// Return:	voit.
	// Remarks: Convert from screen to client point.
	// Notes:
	//************************************
	static void ScreenToClientPoint(FS_HWND hWnd, FS_DevicePoint* pt);

	//************************************
	// Function:  GetDefaultScreenDpi		
	// Return:	FS_FLOAT.
	// Remarks: Get default screen dpi.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static FS_FLOAT GetDefaultScreenDpi();	

	//************************************
	// Function:  Uncompress	
	// Param[in/out]: dest		    The uncompress data.
	// Param[in/out]: destLen		The length of the uncompress data.
	// Param[in]: source		    The source data.
	// Param[in]: sourceLen		    The length of source data.
	// Return:	FS_INT32.      If uncompress success, it will return FS_UnCompress_OK.
	// Remarks: Uncompress data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.2
	//************************************
	static FS_INT32 Uncompress(FS_BYTE *dest, unsigned long *destLen, const FS_BYTE *source, unsigned long sourceLen);
};

class CFS_DIBSource_V16
{
public:
	//************************************
	// Function:  CastToBitmap	
	// Param[in]: dibSource		The input FS_DIBSource object.
	// Return:	FS_DIBitmap     Convert to FS_DIBitmap.
	// Remarks: Convert to FS_DIBitmap.
	// Notes:
	//************************************
	static FS_DIBitmap CastToBitmap(FS_DIBSource dibSource);

	//************************************
	// Function:  Destroy	
	// Param[in]: dibSource		The input FS_DIBSource object.
	// Return:	void
	// Remarks: Destroy the FS_DIBSource object.
	// Notes:
	//************************************
	static void Destroy(FS_DIBSource dibSource);

	//************************************
	// Function:  IsAlphaMask	
	// Param[in]: dibSource   The input FS_DIBSource object.
	// Return:    <a>TRUE</a> for bitmap being an alpha mask.
	// Remarks:   Checks whether the bitmap is an alpha mask (either 1bpp bitmask or 8bpp gray scale).
	// Notes:
	//************************************
	static FS_BOOL IsAlphaMask(FS_DIBSource dibSource);

	//************************************
	// Function:  CloneConvert	
	// Param[in]: dibSource	The input FS_DIBSource object.
	// Param[in]: format	The destination bitmap format.
	// Param[in]: pClip		The clipping region of source bitmap.
	// param[in]  pIccTransform		The color mapping context for source format to destination.
	// Return:    The cloned bitmap.
	// Remarks:   Converts a bitmap, but clone first. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:     Optionally a clipping region in bitmap coordinates can be specified to limit the size of result bitmap.
	// See: FSDIBitmapClone
	//************************************
	static FS_DIBitmap CloneConvert(FS_DIBSource dibSource, FS_DIB_Format format, FS_Rect* pClip, FS_LPVOID pIccTransform);

	//************************************
	// Function:  Clone	
	// Param[in]: dibSource	The input FS_DIBSource.
	// Param[in]: pClip		The clipping region of source bitmap
	// Return:    A cloned bitmap.
	// Remarks:   Clones a bitmap. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:     Optionally a clipping region in bitmap coordinates can be specified to limit the size of result bitmap.
	// See: FSDIBitmapCloneConvert
	//************************************
	static FS_DIBitmap Clone(FS_DIBSource dibSource, FS_Rect* pClip);

	//************************************
	// Function:  GetWidth
	// Param[in]: bitmap The input FS_DIBSource.
	// Return:    The width of the bitmap.
	// Remarks:   Gets the width of the bitmap.
	// Notes:
	// See: FSDIBitmapGetHeight
	//************************************
	static FS_INT32 GetWidth(FS_DIBSource dibSource);


	//************************************
	// Function:  GetHeight
	// Param[in]: bitmap The input FS_DIBSource.
	// Return:    The height of the bitmap.
	// Remarks:   Gets the height of the bitmap.
	// Notes:
	// See: FSDIBitmapGetWidth
	//************************************
	static FS_INT32 GetHeight(FS_DIBSource dibSource);


	//************************************
	// Function:  GetFormat
	// Param[in]: bitmap The input FS_DIBSource.
	// Return:    The format of the bitmap.
	// Remarks:   Gets the format of the bitmap.
	// Notes:
	//************************************
	static FS_DIB_Format GetFormat(FS_DIBSource dibSource);


	//************************************
	// Function:  GetPitch	
	// Param[in]: bitmap The input FS_DIBSource.
	// Return:    The row pitch of the bitmap.
	// Remarks:   Gets the specified row pitch of the bitmap.
	// Notes:
	//************************************
	static FS_DWORD GetPitch(FS_DIBSource dibSource);


	//************************************
	// Function:  GetPalette	
	// Param[in]: bitmap The input FS_DIBSource.
	// Return:    The palette of the bitmap.
	// Remarks:   Gets the palette of the bitmap.
	// Notes:
	//************************************
	static FS_ARGB* GetPalette(FS_DIBSource dibSource);


	//************************************
	// Function:  GetBuffer
	// Param[in]: bitmap The input FS_DIBSource.
	// Return:    A buffer for the whole <Italic>DIB</Italic>.
	// Remarks:   Gets a buffer for whole <Italic>DIB</Italic>. Only in-memory DIB can supply such a buffer.
	// Notes:     
	//************************************
	static FS_LPBYTE GetBuffer(FS_DIBSource dibSource);


	//************************************
	// Function:  GetScanline
	// Param[in]: bitmap    The input FS_DIBSource.
	// Param[in]: line		The zero-based line number. [0, height).
	// Return:    A pointer to the scan line.
	// Remarks:   Fetches a single scan line.
	// Notes:
	// See: FSDIBitmapDownSampleScanline
	//************************************
	static FS_LPBYTE GetScanline(FS_DIBSource dibSource, FS_INT32 line);


	//************************************
	// Function:  DownSampleScanline	
	// Param[in]: bitmap    The input FS_DIBSource.
	// Param[in]: line		The zero-based line number.
	// Param[in,out]: destScan  The destination scanline buffer to receive down-sample result.
	// Param[in]: destBpp   The destination bits per pixel.
	// Param[in]: destWidth	The destination width of pixels in the scanline.
	// Param[in]: bFlipX    Whether to flip the bitmap in x-direction. 
	// Param[in]: clipLeft	Clip start of the destination scanline.
	// Param[in]: clipWidth Clip width of the destination scanline.
	// Return:    void
	// Remarks:   Downs sample a scanline, for quick stretching.
	//            </Brief> The down-sampled result would be either 8bpp (for mask and grayscale), 24bpp or 32bpp.
	// Notes:
	// See: FSDIBitmapGetScanline
	//************************************
	static void	DownSampleScanline(
		FS_DIBSource dibSource,
		FS_INT32 line,
		FS_LPBYTE destScan,
		FS_INT32 destBpp,
		FS_INT32 destWidth,
		FS_BOOL bFlipX,
		FS_INT32 clipLeft,
		FS_INT32 clipWidth
	);

	//************************************
	// Function:  GetBPP	
	// Param[in]: bitmap The input FS_DIBSource.
	// Return:    The number of bits per pixel.
	// Remarks:   Gets the number of bits per pixel.
	// Notes:
	//************************************
	static FS_INT32 GetBPP(FS_DIBSource dibSource);

	//************************************
	// Function:  HasAlpha
	// Param[in]: bitmap The input FS_DIBSource.
	// Return:    Non-zero means it has a alpha channel, otherwise has not.
	// Remarks:   Checks if it's a bitmap with alpha channel.
	// Notes:     Alpha masks return <a>FALSE</a>.
	//************************************
	static FS_BOOL HasAlpha(FS_DIBSource dibSource);

	//************************************
	// Function:  IsOpaqueImage	
	// Param[in]: bitmap The input FS_DIBSource.
	// Return:    Non-zero means it is a solid (opaque) image, otherwise is not.
	// Remarks:   Checks if it's a solid (opaque) image.
	// Notes:
	//************************************
	static FS_BOOL IsOpaqueImage(FS_DIBSource dibSource);

	//************************************
	// Function:  GetPaletteSize	
	// Param[in]: bitmap The input FS_DIBSource.
	// Return:    The number of palette entries.
	// Remarks:   Gets the number of palette entries.
	// Notes:
	//************************************
	static FS_INT32	GetPaletteSize(FS_DIBSource dibSource);

	//************************************
	// Function:  GetPaletteArgb
	// Param[in]: bitmap	The input FS_DIBSource.
	// Param[in]: index		Zero-based palette entry index of the palette.
	// Return:    A palette entry value.
	// Remarks:   Gets palette entry with specified palette entry index.
	// Notes:     
	// See: FSDIBitmapSetPaletteArgb
	//************************************
	static FS_ARGB GetPaletteArgb(FS_DIBSource dibSource, FS_INT32 index);

	//************************************
	// Function:  SetPaletteArgb	
	// Param[in]: bitmap	The input FS_DIBSource.
	// Param[in]: index		Zero-based palette entry index of the palette.
	// Param[in]: argb		The new value the entry.
	// Return:    void
	// Remarks:   Changes a specified palette entry.
	// Notes:     
	// See: FSDIBitmapGetPaletteArgb
	//************************************
	static void SetPaletteArgb(FS_DIBSource dibSource, FS_INT32 index, FS_ARGB argb);

	//************************************
	// Function:  GetAlphaMask 
	// Param[in]: bitmap	The input FS_DIBSource.
	// Param[in]: pClip		The clipping region of source bitmap.
	// Return:    An alpha mask.
	// Remarks:   Gets alpha mask from a bitmap. Returns a 8bpp alpha mask. The returned value must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:     Applicable to Argb format only.
	//            Optionally a clipping region in bitmap coordinates can be specified to limit the size of result mask.
	//************************************
	static FS_DIBitmap GetAlphaMask(FS_DIBSource dibSource, FS_Rect* pClip);

	//************************************
	// Function:  StretchTo	
	// Param[in]: bitmap		The input FS_DIBSource.
	// Param[in]: destWidth		The width of the destination bitmap.
	// Param[in]: destHeight	The height of the destination bitmap.
	// Param[in]: flags			Stretching flags. It can use <a>FS_DIB_DOWNSAMPLE</a> and <a>FS_DIB_INTERPOL</a> flags
	// Param[in]: pClip			The clipping region of destination bitmap.
	// Return:    A new bitmap with different size.
	// Remarks:   Stretches this bitmap into a new bitmap with different size. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:     If dest width or dest height is negative, the bitmap will be flipped.
	//            If a 1bpp bitmap is stretched, it will become either a RGB bitmap, if it's a colored bitmap;
	//            or a 8bpp gray scale mask if it's a bit mask.
	//            Stretching can be done in down-sample mode, which doesn't do interpolation so significantly faster
	//            especially when stretching big images into small ones.
	//            Optionally a clipping region in result bitmap coordinates can be specified to limit the size of result bitmap.

	//************************************
	static FS_DIBitmap StretchTo(FS_DIBSource dibSource, FS_INT32 destWidth, FS_INT32 destHeight, FS_DWORD flags, FS_Rect* pClip);


	//************************************
	// Function:   TransformTo	
	// Param[in]:  bitmap		The input FS_DIBSource.
	// Param[in]:  pMatrix		The transformation matrix.
	// Param[out]: outLeft		Receives x-coordinate of the left-top corner of the result bitmap in destination coords.
	// Param[out]: outTop		Receives y-coordinate of the left-top corner of the result bitmap in destination coords.
	// Param[in]:  flags		Stretching flags. It can use <a>FS_DIB_DOWNSAMPLE</a> and <a>FS_DIB_INTERPOL</a> flags.
	// Param[in]:  pClip		The clipping region of destination bitmap.
	// Return:     A new transformed bitmap.
	// Remarks:    Transforms this bitmap. A new transformed bitmap is returned. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:      This bitmap can be colored bitmap, or an alpha mask. In case of colored bitmap,
	//             certain transformation (rotating or skewing) will cause the return bitmap as ARGB, no matter
	//             what the source bitmap format is.
	//             If a 1bpp bitmap is transformed, it will become either a RGB bitmap, if it's a colored bitmap;
	//             or a 8bpp gray scale mask if it's a bit mask.
	//             The dimension of returned bitmap always match the dimension of the matrix.
	//             Transformation can be done in down-sample mode, which doesn't do interpolation so significantly faster
	//             especially when transforming big images into small ones.
	//             Optionally a clipping region in result bitmap coordinates can be specified to limit the size of result bitmap.
	//             The position of left-top corner (in destination coordinates) of the result bitmap is also returned.
	//************************************
	static FS_DIBitmap TransformTo(
		FS_DIBSource dibSource,
		FS_AffineMatrix* pMatrix,
		FS_INT32* outLeft,
		FS_INT32* outTop,
		FS_DWORD flags,
		FS_Rect* pClip
	);

	//************************************
	// Function:  SwapXY
	// Param[in]: bitmap	The input FS_DIBSource.
	// Param[in]: bXFlip	Whether to flip the bitmap in x-direction.
	// Param[in]: bYFlip	Whether to flip the bitmap in y-direction.
	// Param[in]: pClip		The clipping region of destination bitmap.
	// Return:    A new bitmap.
	// Remarks:   Swaps X,Y coordinations of the bitmap. The image can also be flipped at the same time. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:     Optionally a clipping region (in destination bitmap coordinates) can be specified to limit the size of result.
	//            This function can be used to rotate the bitmap 90 or 270 degree.
	//            Suppose the original image has the following 4 pixels:
	//			  
	//            +---+---+
	//			  | 1 | 2 |
	//			  +---+---+
	//			  | 3 | 4 |
	//			  +---+---+
	//			  Then, depends on value of <param>bXFlip</param> and <param>bYFlip</param>, the result would look like this:
	//				 
	//			  if bXFlip = FALSE, bYFlip = FALSE:
	//			  +---+---+
	//			  | 1 | 3 |
	//			  +---+---+
	//			  | 2 | 4 |
	//			  +---+---+
	//					
	//			  if bXFlip = TRUE, bYFlip = FALSE:
	//			  +---+---+
	//			  | 3 | 1 |
	//			  +---+---+
	//			  | 4 | 2 |
	//			  +---+---+
	//					
	//			  if bxflip = false, byflip = true:
	//			  +---+---+
	//			  | 2 | 4 |
	//			  +---+---+
	//			  | 1 | 3 |
	//			  +---+---+
	//					
	//			  if bxflip = true, byflip = true:
	//			  +---+---+
	//			  | 4 | 2 |
	//			  +---+---+
	//			  | 3 | 1 |
	//			  +---+---+  
	//************************************
	static FS_DIBitmap SwapXY(FS_DIBSource dibSource, FS_BOOL bXFlip, FS_BOOL bYFlip, FS_Rect* pClip);

	//************************************
	// Function:  FlipImage	
	// Param[in]: bitmap	The input FS_DIBSource.
	// Param[in]: bXFlip	Whether to flip the bitmap in x-direction.
	// Param[in]: bYFlip	Whether to flip the bitmap in y-direction.
	// Return:    A flipped bitmap.
	// Remarks:   Flips image. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
	// Notes:
	//************************************
	static FS_DIBitmap FlipImage(FS_DIBSource dibSource, FS_BOOL bXFlip, FS_BOOL bYFlip);

	//************************************
	// Function:  GetBitmapAlphaMask	
	// Param[in]: dibSource	The input FS_DIBSource.
	// Return:  FS_DIBitmap  Must be 8bpp Mask. for extra alpha channel.
	// Remarks:   Get the alpha mask.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FS_DIBitmap GetBitmapAlphaMask(FS_DIBSource dibSource);
	
	//************************************
	// Function:  GetColorKey	
    // Param[in]: dibSource	The input FS_DIBSource.
	// Param[out]: pColorKey	Input NULL point and return color key array. Be freed by caller.
	// Param[out]: size     	Array size.
	// Return: FS_BOOLEAN  true for color key exist and get it, otherwise false.
	// Remarks:    Get color key mask of image.Returns a range of colors to be masked out.
	// Now support 8bpp image only.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static FS_BOOLEAN	GetColorKey(FS_DIBSource dibSource, FS_INT32* pColorKey, FS_INT32* size);
	
	 //************************************
	 // Function:  GetBitmapWithoutColorKey	
	 // Param[in]: dibSource	The input FS_DIBSource.
	 // Param[out]: pBitmap	    Raw bitmap with palette. Be freed by caller.
	 // Return: FS_BOOLEAN  true for get the 8bpp bitmap, otherwise false.
	 // Remarks:  If the image is 8bpp with palette and has color key mask.
	 // Get this 8bpp bitmap, and there is no color be masked out by color key mask.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	 //************************************
	static FS_BOOLEAN	GetBitmapWithoutColorKey(FS_DIBSource dibSource, FS_DIBitmap* pBitmap);

	//************************************
	// Function:  IsCmykImage	
	// Param[in]: dibSource	The input FS_DIBSource.	
	// Return: FS_BOOLEAN  Non-zero means it is a cmyk image, otherwise is not.
	// Remarks: Check if it's a cmyk format image.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0
	//************************************
	static FS_BOOLEAN	IsCmykImage(FS_DIBSource dibSource);
};

class CFS_DIBAttribute_V16
{
public:
	//************************************
	// Function:  Create	
	// Return:   FS_DIBAttribute
	// Remarks:  Create FS_DIBAttribute.
	// Notes: It need FSDIBitmapDelete to release.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: FSDIBitmapDelete
	//************************************
	static FS_DIBAttribute			Create();
	
	//************************************
	// Function:  Delete	
	// Param[in]: attr	The input FS_DIBAttribute.
	// Return:    void
	// Remarks: Destroys the input bitmap attribute object. 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: 
	//************************************
	static void Delete(FS_DIBAttribute attr);

	//************************************
	// Function:  SetXDPI	
	// Param[in]: attr	    The input bitmap attribute object.
	// Param[value]: value	Sets the horizontal resolution attribute of the bitmap.
	// Return: The horizontal resolution, -1 means the bitmap doesn't contain this information, 0 or 1 means the user should use default DPI value. 
	// Remarks: Sets the horizontal resolution attribute of the bitmap.
	// Notes: JBIG2 cannot get DPI information now.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: 
	//************************************
	static void	SetXDPI(FS_DIBAttribute attr, FS_INT32 value);

	//************************************
	// Function:  GetXDPI	
	// Param[in]: attr	The input bitmap attribute object.
	// Return: The horizontal resolution, -1 means the bitmap doesn't contain this information, 0 or 1 means the user should use default DPI value. 
	// Remarks: Gets the horizontal resolution attribute of the bitmap.
	// Notes: JBIG2 cannot get DPI information now.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: 
	//************************************
	static FS_INT32 GetXDPI(FS_DIBAttribute attr);

	//************************************
	// Function:  SetYDPI	
	// Param[in]: attr	The input bitmap attribute object.
	// Param[in]: value	The input vertical resolution.
	// Return: The vertical resolution, -1 means the bitmap doesn't contain this information, 0 or 1 means the user should use default DPI value.
	// Remarks: Sets the Vertical resolution attribute of the bitmap.
	// Notes: JBIG2 cannot get DPI information now.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See:
	//************************************
	static void SetYDPI(FS_DIBAttribute attr, FS_INT32 value);

	//************************************
	// Function:  GetYDPI	
	// Param[in]: attr	The input bitmap attribute object.
	// Return: The vertical resolution, -1 means the bitmap doesn't contain this information, 0 or 1 means the user should use default DPI value.
	// Remarks: Gets the Vertical resolution attribute of the bitmap.
	// Notes: JBIG2 cannot get DPI information now.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See:
	//************************************
	static FS_INT32 GetYDPI(FS_DIBAttribute attr);

	//************************************
	// Function:  GetDPIUnit	
	// Param[in]: attr	The input bitmap attribute object.
	// Return: The resolution unit.
	// Remarks: Gets the resolution unit, described by <a>FS_DIB_RESUNIT</a>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: FSDIBitmapLoadInfo
	//************************************
	static FS_WORD GetDPIUnit(FS_DIBAttribute attr);

	//************************************
	// Function:  GetExifInfo	
	// Param[in]: attr	The input bitmap attribute object.
	// Param[in]: tag	The input tag of the exchangeable image file information of camera in JPEG file, described by <a>FSDIBEXIFTAG</a>.
	// Param[out]: val	The output value of the exchangeable image file information.
	// Return: <a>TRUE</a> means success, otherwise failure.
	// Remarks: Gets the exchangeable image file information of camera in JPEG file.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: FSDIBitmapLoadInfo
	//************************************
	static FS_BOOL GetExifInfo(FS_DIBAttribute attr, FS_WORD tag, FS_LPVOID val);

	//************************************
	// Function:  SetTiffFrameCompressType	
	// Param[in]: attr	The input bitmap attribute object.
	// Param[in]: value	The input compress type.
	// Return: void.
	// Remarks: Set the compress type of tiff frame..
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: 
	//************************************
	static void	 SetTiffFrameCompressType(FS_DIBAttribute attr, FS_DWORD value);

	//************************************
	// Function:  SetTiffFrameCompressJpegQuality	
	// Param[in]: attr	The input bitmap attribute object.
	// Param[in]: value	The input compress quality.
	// Return: void.
	// Remarks: Set the compress jpeg quality of tiff frame..
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: 
	//************************************
	static void SetTiffFrameCompressJpegQuality(FS_DIBAttribute attr, FS_DWORD value);

	//************************************
	// Function:  SetDPIUnit	
	// Param[in]: attr	The input bitmap attribute object.
	// Param[in]: value	Set the resolution unit, described by FS_DIB_RESUNIT_XXX
	// Return: Set the resolution unit.
	// Remarks: Set the resolution unit, described by <a>FS_DIB_RESUNIT</a>.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0
	// See: FSDIBitmapLoadInfo
	//************************************
	static void SetDPIUnit(FS_DIBAttribute attr, FS_WORD value);
};

class CFS_Rect_V17
{
public:
	//************************************
	// Function:  Width	
	// Param[in]: rect		        The input FS_Rect.		
	// Return:	FS_FLOAT   Width of the rectangle.
	// Remarks: Get the width of the rectangle.
	// Notes:
	//************************************
	static FS_FLOAT 	 Width(FS_Rect rect);

	//************************************
	// Function:  Height	
	// Param[in]: rect		        The input FS_Rect.		
	// Return:	FS_FLOAT   Height of the rectangle.
	// Remarks: Get the height of the rectangle.
	// Notes:
	//************************************
	static FS_FLOAT		 Height(FS_Rect rect);

	//************************************
	// Function:  IsEmpty	
	// Param[in]: rect		        The input FS_Rect.	
	// Return:	FS_BOOLEAN.
	// Remarks:	Check input rect is empty.
	// Notes:
	//************************************
	static FS_BOOLEAN	 IsEmpty(FS_Rect rect);

	//************************************
	// Function:  Normalize	
	// Param[in]: rect		        The input pointer of FS_Rect.	
	// Return:	void.
	// Remarks:	Normalize the rect. Make sure left <= right, and bottom <= top.
	// Notes:
	//************************************
	static void		     Normalize(FS_Rect* rect);

	//************************************
	// Function:  Intersect	
	// Param[in]: rect		        The input pointer of FS_Rect.
	// Param[in]: src		        The rect to intersect with.
	// Return:	void.
	// Remarks:	Intersect with a rect.
	// Notes:
	//************************************
	static void		     Intersect(FS_Rect* rect, const FS_Rect src);

	//************************************
	// Function:  Intersect2	
	// Param[in]: rect		        The input pointer of FS_Rect.
	// Param[in]: left1		        The number to intersect the left of the rectangle.
	// Param[in]: top1		        The number to intersect the top of the rectangle.
	// Param[in]: right1		    The number to intersect the right of the rectangle.
	// Param[in]: bottom1		    The number to intersect the bottom of the rectangle.
	// Return:	void.
	// Remarks:	Intersect with a rect.
	// Notes:
	//************************************
	static void		     Intersect2(FS_Rect* rect, FS_INT32 left1, FS_INT32 top1, FS_INT32 right1, FS_INT32 bottom1);

	//************************************
	// Function:  Union	
	// Param[in]: rect		        The input pointer of FS_Rect.
	// Param[in]: other_rect		The rect to union with.
	// Return:	void.
	// Remarks:	Union with a rect.
	// Notes:
	//************************************
	static void		     Union(FS_Rect* rect, const FS_Rect other_rect);

	//************************************
	// Function:  IsEqualRect	
	// Param[in]: rect		        The input FS_Rect.
	// Param[in]: src		        The rect to compare with.
	// Return:	void.
	// Remarks:	Compare two rectangles. Please make sure they are normalized first.
	// Notes:
	//************************************
	static FS_BOOLEAN	 IsEqualRect(FS_Rect rect, const FS_Rect src);

	//************************************
	// Function:  IsNotEqualRect	
	// Param[in]: rect		        The input FS_Rect.
	// Param[in]: src		        The rect to compare with.
	// Return:	void.
	// Remarks:	Compare two rectangles. Please make sure they are normalized first.
	// Notes:
	//************************************
	static FS_BOOLEAN	 IsNotEqualRect(FS_Rect rect, const FS_Rect src);

	//************************************
	// Function:  Offset	
	// Param[in]: rect		        The pointer of FS_Rect.
	// Param[in]: dx		        The delta value of x-direction.
	// Param[in]: dy		        The delta value of y-direction.
	// Return:	void.
	// Remarks:	Shift the coordinates by delta value of x and y directions.
	// Notes:
	//************************************
	static void		     Offset(FS_Rect* rect, FS_INT32 dx, FS_INT32 dy);

	//************************************
	// Function:  Contains	
	// Param[in]: rect		        The input FS_Rect.
	// Param[in]: other_rect		The other provided rect.
	// Return:	FS_BOOLEAN.
	// Remarks: Check if current rectangle fully contains the other provided rectangle.
	//        That means to check if the other rectangle is fully inside current one.
	// Notes:
	//************************************
	static FS_BOOLEAN	 Contains(FS_Rect rect, const FS_Rect other_rect);

	//************************************
	// Function:  Contains2	
	// Param[in]: rect		        The input FS_Rect.
	// Param[in]: x		            The x coordinate of the provided point.
	// Param[in]: y		            The y coordinate of the provided point.
	// Return:	FS_BOOLEAN.
	// Remarks: Check if current rectangle fully contains the other provided rectangle.
	//        That means to check if the other rectangle is fully inside current one.
	// Notes:
	//************************************
	static FS_BOOLEAN	 Contains2(FS_Rect rect, FS_INT32 x, FS_INT32 y);

	//************************************
	// Function:  Valid	
	// Param[in]: rect		        The input FS_Rect.	
	// Return:	FS_BOOLEAN.
	// Remarks: Check if current rectangle is valid.
	// Notes:
	//************************************
	static FS_BOOLEAN	 Valid(FS_Rect rect);

	//************************************
	// Function:  Inflate	
	// Param[in]: rect		        The input FS_Rect.	
	// Param[in]: x		            The number to inflate the left and right of the rectangle.
	// Param[in]: y		            The number to inflate the top and bottom of the rectangle.
	// Return:	void.
	// Remarks: Increases the width and height of the rectangle.
	// Notes:
	//************************************
	static void	         Inflate(FS_Rect* rect, FS_INT32 x, FS_INT32 y);
};

class CFS_MemoryMgr_V17
{
public:
	//************************************
	// Function:  Alloc	
	// Param[in]: units		    The array size.
	// Param[in]: unit_size		Size of data types to allocate, like sizeof(FS_Byte).
	// Return:	FS_LPVOID. Returns the pointer to the beginning of newly allocated memory. 
	// Remarks: Allocates size bytes of uninitialized storage.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	//************************************
	static FS_LPVOID Alloc(FS_UINT units, FS_UINT unit_size);

	//************************************
	// Function:  Free	
	// Param[in]: pointer		    Alloc form FSMemoryMgrAlloc.
	// Return:	void.
	// Remarks: Free memory block.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0
	// See: FSMemoryMgrAlloc
	//************************************
	static void Free(FS_LPVOID pointer);
};

class CFS_PrivateData_V19
{
public:
	//************************************
	// Function:  New	
	// Param[in]: pAllocator     An allocator. Default value: <b>NULL</b>.
	// Return:    A new FS_PrivateData.
	// Remarks:  Construct with allocator.
	// Notes:
	//************************************
	static FS_PrivateData New(FS_LPVOID pAllocator);


	//************************************
	// Function:  Destroy	
	// Param[in]: data		The input FS_PrivateData obj.
	// Return:    void
	// Remarks:   Destroys FS_PrivateData obj.
	// Notes:
	//************************************
	static void Destroy(FS_PrivateData data);

	//************************************
	// Function:  ClearAll	
	// Param[in]: data		The input FS_PrivateData obj.
	// Return:    void
	// Remarks:   Release all remaining data.
	// Notes:
	//************************************
	static void  ClearAll(FS_PrivateData data);

	//************************************
	// Function:  SetPrivateData	
	// Param[in]: data		The input FS_PrivateData obj.
	// Param[in]: module_id	The module id.
	// Param[in]: pData		The private data.
	// Param[in]: callback	The callback function for deallocating provided private data.
	// Return:    void
	// Remarks:  Set private data.
	// Notes:    If the data points to an object that will belong to the attached object (which means
	//            when the attached object is destroyed, the private data should be destroyed too), then the caller
	//            must provide a callback for freeing the data.
	//            If the private data is just a number, or some external pointer, then the callback can be NULL.
	//            This function will free any previously stored data for with same module ID.The caller can not
	//            set same data twice(this will cause a crash).
	//************************************
	static void  SetPrivateData(FS_PrivateData data, FS_LPVOID module_id, FS_LPVOID pData, FS_PD_CALLBACK_FREEDATA callback);

	//************************************
	// Function:  SetPrivateObj
	// Param[in]: data		The input FS_PrivateData obj.
	// Param[in]: module_id	The module id.
	// Param[in]: pObj		The private data in fact a CFX_DestructObject derived object.
	// Return:    void
	// Remarks:   Set private object.
	// Notes:     The private object will become a part of the attached object, so when the attached object is destroyed,
	//            the private object will be destroyed too.This function will free any previously stored data
	//            for with same module ID.The caller can not set same object twice(this will cause a crash).
	//************************************
	static void  SetPrivateObj(FS_PrivateData data, FS_LPVOID module_id, FPD_DestructObject pObj);

	//************************************
	// Function:  GetPrivateData	
	// Param[in]: data		The input FS_PrivateData obj.
	// Param[in]: module_id	The module id.
	// Return:    FS_LPVOID
	// Remarks:  Get previously stored private data. Returns NULL for not stored.
	// Notes: This function works for private data set by function {@link CFX_PrivateData::SetPrivateData}
	//************************************
	static FS_LPVOID GetPrivateData(FS_PrivateData data, FS_LPVOID module_id);

	//************************************
	// Function:  LookupPrivateData	
	// Param[in]: data		The input FS_PrivateData obj.
	// Param[in]: module_id	The module id.
	// Param[in]: pData   	The module id.
	// Return:    FS_BOOLEAN  <b>true</b> means the private data exists, while <b>false</b> means not found.
	// Remarks:  Lookup a private data.
	// Notes: 
	//************************************
	static FS_BOOLEAN  LookupPrivateData(FS_PrivateData data, FS_LPVOID module_id, FS_LPVOID* pData);

	//************************************
	// Function:  RemovePrivateData	
	// Param[in]: data		The input FS_PrivateData obj.
	// Param[in]: module_id	The module id.
	// Return:    FS_BOOLEAN  <b>true</b> means the private data exists, while <b>false</b> means not found.
	// Remarks:  Remove previously stored private data.
	// Notes: 
	//************************************
	static FS_BOOLEAN  RemovePrivateData(FS_PrivateData data, FS_LPVOID module_id);
};

class CFS_VectorF_V19
{
public:
	static FS_VectorF Create();
	static void Destroy(FS_VectorF vec);
	static void	Set(FS_VectorF vec, FS_FLOAT x, FS_FLOAT y);
	static void	Set2(FS_VectorF vec, FS_VectorF vecOrigin);
	static void	Reset(FS_VectorF vec);
	static FS_FLOAT	SquareLength(FS_VectorF vec);
	static FS_FLOAT Length(FS_VectorF vec);
	static void		Normalize(FS_VectorF vec);
	static FS_FLOAT	GetX(FS_VectorF vec);
	static FS_FLOAT	GetY(FS_VectorF vec);
	static FS_FLOAT	DotProduct(FS_VectorF vec, FS_FLOAT x, FS_FLOAT y);
	static FS_FLOAT	DotProduct2(FS_VectorF vec, FS_VectorF vecOrigin);
};

#ifdef __cplusplus
};
#endif//__cplusplus

#endif//FR_BASIC_H

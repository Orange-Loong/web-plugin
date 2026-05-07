#ifndef FPD_PSIIMPL_H
#define FPD_PSIIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifndef FPD_PSIEXPT_H
#include "../fpd_psiExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

class CFPD_FXGInkPath_V17
{
public:
	//************************************
	// Function:  AddPoint
	// Param[in]: inkPath		The input FPD_FXGInkPath.
	// Param[in]: point			The point of pressure sensitive ink.
	// Return:    void
	// Remarks:   Add the pressure sensitive ink point to the path.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void				AddPoint(FPD_FXGInkPath inkPath, const FPD_FXGINKPOINT point);
	
	 //************************************
	 // Function:  GeneratePSI
	 // Param[in]: inkPath		The input FPD_FXGInkPath.
	 // Param[in]: nType		Defined above, FXG_PSI_TYPE_XXX.
	 // Param[out]: pData		A Pointer to the vectored data. Caller need to interpret the data (s)he needed according to nType.
	 // Return:    FS_BOOLEAN   true indicate the PSI vector data generate success, otherwise pData has no meaning.
	 // Remarks:   Generate the PSI data (A vectored data).
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	 //************************************	
	static FS_BOOLEAN		GeneratePSI(FPD_FXGInkPath inkPath, FS_INT32 nType, FPD_PathData* pData);
};


class CFPD_FXGPaintModuleMgr_V17
{
public:
	//************************************
	// Function:  Create	
	// Return:    FPD_FXGPaintModuleMgr   
	// Remarks:   Create a Paint module.
    // Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FPD_FXGPaintModuleMgr Create();

	//************************************
	// Function:  Destroy	
	// Param[in]: moduleMgr		The input FPD_FXGPaintModuleMgr.
	// Return:    void   
	// Remarks:   Destroy the current Paint module.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void Destroy(FPD_FXGPaintModuleMgr moduleMgr);

	//************************************
	// Function:  GetCanvas	
	// Param[in]: moduleMgr		The input FPD_FXGPaintModuleMgr.
	// Return:    FPD_FXGCanvas   A pointer to the default canvas. 
	// Remarks:   Get the default canvas, and then you should config it.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FPD_FXGCanvas GetCanvas(FPD_FXGPaintModuleMgr moduleMgr);

	//************************************
	// Function:  GetPaint	
	// Param[in]: moduleMgr		The input FPD_FXGPaintModuleMgr.
	// Param[in]: nPaintType	The input paint type,like FPD_FXGPAINT_xxx.
	// Return:    FPD_FXGPaint   A pointer to FPD_FXGPaint. 
	// Remarks:   Get a paint according paint type. The module manage will associate the paint and the default canvas. 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FPD_FXGPaint GetPaint(FPD_FXGPaintModuleMgr moduleMgr, FS_INT32 nPaintType);

	//************************************
	// Function:  SetCacheLimit	
	// Param[in]: moduleMgr		The input FPD_FXGPaintModuleMgr.
	// Param[in]: dwLimitSize	The size of the cache limit.
	// Return:    FPD_FXGPaint   A pointer to FPD_FXGPaint. 
	// Remarks:   Set the cache limit of the paint nib.
	// Notes: If the caller does not set it, the paint module will use FPD_FXGDEFAULT_CACHE_LIMIT as default
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void	SetCacheLimit(FPD_FXGPaintModuleMgr moduleMgr, FS_DWORD dwLimitSize);

	//************************************
	// Function:  CreatePaintNib	
	// Param[in]: moduleMgr		The input FPD_FXGPaintModuleMgr.
	// Param[in]: pStrName	    The paint nib name the caller wanna.
	// Param[in]: nNibType	    The paint nib type defined above, FPD_FXGNIB_FILE_TYPE_XXX. If FPD_FXGNIB_CUSTOM, the pParams value will be ignore.
	// Param[in]: pParams	    The parameter of the nib according nNibType. 
	// Return:    FPD_FXGPaintNib   A pointer to FPD_FXGPaint. 
	// Remarks:   Create a paint nib according to the nNibType.
	// If the nNibType is FXG_NIB_CUSTOM, the paint module will create the nib according to the
	// canvas(clipped by clip region and the DIB data)
	// The created paint nib managed by the paint module, caller could destroy it only by DestroyPaintNib.
	// If caller does not destroy it manual, it will be free when the paint module Destroy or LoadPaintNib with replace.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FPD_FXGPaintNib	CreatePaintNib(FPD_FXGPaintModuleMgr moduleMgr, FS_LPCSTR pStrName, FS_INT32 nNibType, FPD_FXGNIBParams pParams);

	//************************************
	// Function:  DestroyPaintNib	
	// Param[in]: moduleMgr		The input FPD_FXGPaintModuleMgr.
	// Param[in]: pNib	        The paint nib will bes destroyed.
	// Return:     true indicate success, otherwise failure.
	// Remarks:    If the caller believe that the paint nib is no longer useful, you can destroy it by the method.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_BOOLEAN	DestroyPaintNib(FPD_FXGPaintModuleMgr moduleMgr, FPD_FXGPaintNib pNib);

	//************************************
	// Function:  LoadPaintNib	
	// Param[in]: moduleMgr		The input FPD_FXGPaintModuleMgr.
	// Param[in]: pFile	        The stream access interface.
	// Param[in]: bReplace	    The flags indicate a new set of paint nibs whether to replace the previous ones.
	// Return:   A flag defined above, FPD_FXGPAINT_ERROR_XXX
	// Remarks:    Load a set of paint nibs from a file. Reserved now.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_INT32		LoadPaintNib(FPD_FXGPaintModuleMgr moduleMgr, FS_FileReadHandler pFile, FS_BOOLEAN bReplace);

	//************************************
	// Function:  SavePaintNib	
	// Param[in]: moduleMgr		The input FPD_FXGPaintModuleMgr.
	// Param[in]: pFile	        The stream access interface.
	// Param[in]: nType	        The flags indicate the encoding nib file's type.
	// Return:  A flag defined above, FPD_FXGPAINT_ERROR_XXX
	// Remarks:    Load a set of paint nibs from a file. Reserved now.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_INT32		SavePaintNib(FPD_FXGPaintModuleMgr moduleMgr, FS_FileWriteHandler pFile, FS_INT32 nType);

	//************************************
	// Function:  ListAllPaintNib	
	// Param[in]: moduleMgr		The input FPD_FXGPaintModuleMgr.
	// Param[out]: nib_array	It received a set of current paint nibs.
	// Return: FS_BOOLEAN   true indicate success, otherwise failure.
	// Remarks:  List all paint nibs of current set of paint nibs.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_BOOLEAN	ListAllPaintNib(FPD_FXGPaintModuleMgr moduleMgr, FS_PtrArray* nib_array);
};

class CFPD_FXGNIBParams_V17
{
public:
	//************************************
	// Function:  Create	
	// Return: FPD_FXGNIBParams   
	// Remarks: Create FPD_FXGNIBParams obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FPD_FXGNIBParams Create();

	//************************************
	// Function:  Delete	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Return: void   
	// Remarks:  Delete FPD_FXGNIBParams obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void Delete(FPD_FXGNIBParams params);

	//************************************
	// Function:  GetDiameter	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Return: FS_FLOAT   
	// Remarks:  Get the nib diameter or line width.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_FLOAT GetDiameter(FPD_FXGNIBParams params);

	//************************************
	// Function:  SetDiameter	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Param[in]: diameter		The input nib diameter or line width.
	// Return: FS_FLOAT   
	// Remarks: Set the nib diameter or line width.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void SetDiameter(FPD_FXGNIBParams params, FS_FLOAT diameter);

	//************************************
	// Function:  GetbFlipX	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Return: FS_BOOLEAN   
	// Remarks:  Get the nib whether be horizontal flip.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_BOOLEAN GetbFlipX(FPD_FXGNIBParams params);

	//************************************
	// Function:  SetDiameter	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Param[in]: bFlipx		The input the nib whether be horizontal flip.
	// Return: FS_FLOAT   
	// Remarks: Set the nib whether be horizontal flip.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void SetbFlipX(FPD_FXGNIBParams params, FS_BOOLEAN bFlipx);

	//************************************
	// Function:  GetbFlipY	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Return: FS_BOOLEAN   
	// Remarks:  Get the nib whether be vertical flip.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_BOOLEAN GetbFlipY(FPD_FXGNIBParams params);

	//************************************
	// Function:  SetDiameter	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Param[in]: bFlipy		The input the nib whether be vertical flip.
	// Return: FS_FLOAT   
	// Remarks: Set the nib whether be horizontal flip.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void SetbFlipY(FPD_FXGNIBParams params, FS_BOOLEAN bFlipy);

	//************************************
	// Function:  GetAngle	
	// Param[in]: params		The input FPD_FXGNIBParams.	
	// Return: FS_FLOAT   
	// Remarks: Get the nib whether be rotate. In range [0, 360).
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_FLOAT GetAngle(FPD_FXGNIBParams params);

	//************************************
	// Function:  SetAngle	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Param[in]: fAngle		The input nib whether be rotate.
	// Return: FS_FLOAT   
	// Remarks: Set the nib whether be rotate. In range [0, 360).
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void SetAngle(FPD_FXGNIBParams params, FS_FLOAT fAngle);

	//************************************
	// Function:  GetRoundness	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Return: FS_FLOAT   
	// Remarks: Get the nib whether be pinch flat.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_FLOAT GetRoundness(FPD_FXGNIBParams params);

	//************************************
	// Function:  SetRoundness	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Param[in]: fRoundness	The input the nib whether be pinch flat.
	// Return: FS_FLOAT   
	// Remarks: Set the nib whether be pinch flat.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void SetRoundness(FPD_FXGNIBParams params, FS_FLOAT fRoundness);

	//************************************
	// Function:  GetDashScale	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Return: FS_FLOAT   
	// Remarks: Get the range is (0, n), n is infinity.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_FLOAT GetDashScale(FPD_FXGNIBParams params);

	//************************************
	// Function:  SetDashScale	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Param[in]: fDashScale	The input the range is (0, n), n is infinity.
	// Return: FS_FLOAT   
	// Remarks: Set the nib whether be pinch flat.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void SetDashScale(FPD_FXGNIBParams params, FS_FLOAT fDashScale);

	//************************************
	// Function:  GetHardness	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Return: FS_FLOAT   
	// Remarks: Get FXG_NIB_ROUND, the range is [0, 1].
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_FLOAT GetHardness(FPD_FXGNIBParams params);

	//************************************
	// Function:  SetHardness	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Param[in]: fHardness  	The input FXG_NIB_ROUND, the range is [0, 1].
	// Return: void   
	// Remarks: Set FXG_NIB_ROUND, the range is [0, 1].
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void SetHardness(FPD_FXGNIBParams params, FS_FLOAT fHardness);

	//************************************
	// Function:  GetPath	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Param[out]: outPath		Get the path data.
	// Return: void   
	// Remarks: Get the path.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void GetPath(FPD_FXGNIBParams params, FPD_PathData* outPath);

	//************************************
	// Function:  SetPath	
	// Param[in]: params		The input FPD_FXGNIBParams.
	// Param[in]: outPath		Set the path.
	// Return: void   
	// Remarks: Set the path.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void SetPath(FPD_FXGNIBParams params, FPD_PathData path);

	//************************************
	// Function:  GetPattern	
	// Param[in]: params		The input FPD_FXGNIBParams.	
	// Return: FS_DIBitmap   
	// Remarks: Get the pattern.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_DIBitmap GetPattern(FPD_FXGNIBParams params);

	//************************************
	// Function:  SetPattern	
	// Param[in]: params		The input FPD_FXGNIBParams.	
	// Param[in]: pattern		The input pattern.	
	// Return: void   
	// Remarks: Set the pattern.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void SetPattern(FPD_FXGNIBParams params, FS_DIBitmap pattern);
};

class CFPD_FXGCanvas_V17
{
public:
	//************************************
	// Function:  Create	
	// Return: FPD_FXGCanvas   
	// Remarks: Create FPD_FXGCanvas obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FPD_FXGCanvas Create();

	//************************************
	// Function:  Destroy	
	// Param[in]: canvas		The input FPD_FXGCanvas.
	// Return: void   
	// Remarks:  Destroy the current canvas.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void Destroy(FPD_FXGCanvas canvas);

	//************************************
	// Function:  SetFilterNotify	
	// Param[in]: canvas		The input FPD_FXGCanvas.
	// Param[in]: pNotify		The notify will be invoked multiple times when rendering. It create by FPDFXGCanvasCreateFilterNofity.
	// Return: void   
	// Remarks:  Set the filter notify.Required if the application needs to control real - time flush.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void	SetFilterNotify(FPD_FXGCanvas canvas, FPD_FXGFilterNotifyHandler pNotify);

	//************************************
	// Function:  AttachLayer	
	// Param[in]: canvas		The input FPD_FXGCanvas.
	// Param[in]: pBitmap		The bitmap to be attached.
	// Return: void   
	// Remarks:  Attach an existing bitmap to the canvas. Required if CreateLayer does not used.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void	AttachLayer(FPD_FXGCanvas canvas, FS_DIBitmap pBitmap);

	//************************************
	// Function:  CreateLayer	
	// Param[in]: canvas		The input FPD_FXGCanvas.
	// Param[in]: nWidth		The bitmap width.
	// Param[in]: nHeight		The bitmap height.
	// Param[in]: format		The bitmap format.
	// Return: false if creation failed (OOM), or true if success.
	// Remarks:  Create a new bitmap and attach to the canvas. 
	//           The bitmap will be destroyed when the canvas destructs.
	//           Required if AttachLayer does not used.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN CreateLayer(FPD_FXGCanvas canvas, FS_INT32 nWidth, FS_INT32 nHeight, FS_DIB_Format format);

	//************************************
	// Function:  SetFGColor	
	// Param[in]: canvas		The input FPD_FXGCanvas.
	// Param[in]: color		    Set the foreground color of canvas.
	// Return: void   
	// Remarks:  Set the foreground color. 
	// Notes: If the color does not set, the canvas will use black as foreground color.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void	SetFGColor(FPD_FXGCanvas canvas, FPD_FXGCOLOR color);

	//************************************
	// Function:  SetBGColor	
	// Param[in]: canvas		The input FPD_FXGCanvas.
	// Param[in]: color		    Set the background color of canvas.
	// Return: void   
	// Remarks:  Set the background color.
	// Notes: If the color does not set, the canvas will use black as background color.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void	SetBGColor(FPD_FXGCanvas canvas, FPD_FXGCOLOR color);

	//************************************
	// Function:  SetActiveChannel	
	// Param[in]: canvas		The input FPD_FXGCanvas.
	// Param[in]: nChannel		Set the channel.
	// Return: void   
	// Remarks:  Set the active channel of the canvas. Reserved now.
	// Notes: If the color does not set, default all channels active, otherwise, the filter process only active channel.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void	SetActiveChannel(FPD_FXGCanvas canvas, FS_INT32 nChannel);

	//************************************
	// Function:  GetFilterNotify	
	// Param[in]: canvas		The input FPD_FXGCanvas.	
	// Return: FPD_FXGFilterNotifyHandler   
	// Remarks:  Get current filter notify if exist.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_FXGFilterNotifyHandler  GetFilterNotify(FPD_FXGCanvas canvas);

	//************************************
	// Function:  GetLayer	
	// Param[in]: canvas		The input FPD_FXGCanvas.	
	// Return: FS_DIBitmap   
	// Remarks:  Get current layer if exist.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_DIBitmap      GetLayer(FPD_FXGCanvas canvas);

	//************************************
	// Function:  GetFGColor	
	// Param[in]: canvas		The input FPD_FXGCanvas.	
	// Return: FPD_FXGCOLOR   
	// Remarks:  Get current foreground color.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_FXGCOLOR 	GetFGColor(FPD_FXGCanvas canvas);

	//************************************
	// Function:  GetBGColor	
	// Param[in]: canvas		The input FPD_FXGCanvas.	
	// Return: FPD_FXGCOLOR   
	// Remarks:  Get current background color.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_FXGCOLOR 	GetBGColor(FPD_FXGCanvas canvas);

	//************************************
	// Function:  GetActiveChannel	
	// Param[in]: canvas		The input FPD_FXGCanvas.	
	// Return: FS_INT32   
	// Remarks:  Get current active channel, if -1 indicate that all channels active. Reserved now.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_INT32         GetActiveChannel(FPD_FXGCanvas canvas);

	//************************************
	// Function:  CreateFilterNofity	
	// Param[in]: callbacks		The input FPD_FXGFilterNotifyCallbacks.	
	// Return: FPD_FXGFilterNotifyHandler   
	// Remarks:  Create FPD_FXGFilterNotifyHandler obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_FXGFilterNotifyHandler CreateFilterNofity(FPD_FXGFilterNotifyCallbacks callbacks);

	//************************************
	// Function:  DeleteFilterNofity	
	// Param[in]: handler		The input FPD_FXGFilterNotifyHandler.	
	// Return: void   
	// Remarks:  Delete FPD_FXGFilterNotifyHandler obj.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void DeleteFilterNofity(FPD_FXGFilterNotifyHandler handler);
};

class CFPD_FXGPaintNib_V17
{
public:
	//************************************
	// Function:  GetType	
	// Param[in]: nib		The input FPD_FXGPaintNib.	
	// Return: FS_INT32     Get the paint nib type.
	// Remarks:  Get the paint nib type defined in FPD_FXGNIB_xxx.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_INT32			GetType(FPD_FXGPaintNib nib);

	//************************************
	// Function:  GetNib	
	// Param[in]: nib		The input FPD_FXGPaintNib.	
	// Return: FS_DIBitmap  Get the bitmap.
	// Remarks:  Get the paint nib bitmap.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_DIBitmap  	GetNib(FPD_FXGPaintNib nib);

	//************************************
	// Function:  GetName	
	// Param[in]: nib		The input FPD_FXGPaintNib.	
	// Return: FS_LPCSTR  A pointer to the byte string of paint nib name. 
	// Remarks:  Get paint nib name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_LPCSTR		GetName(FPD_FXGPaintNib nib);

	//************************************
	// Function:  GetParams	
	// Param[in]: nib		The input FPD_FXGPaintNib.	
	// Return: FPD_FXGNIBParams  A pointer to the paint nib parameters. 
	// Remarks:  Get paint nib parameters. User can change the parameters according to nib type.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FPD_FXGNIBParams	GetParams(FPD_FXGPaintNib nib);
};

class CFPD_FXGPaintRenderOption_V17
{
public:
	//************************************
	// Function:  Create	
	// Return: FPD_FXGPaintRenderOption  
	// Remarks:  Create a default rendering option if the user does not need to control the rendering option.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_FXGPaintRenderOption Create();

	//************************************
	// Function:  Destroy	
	// Param[in]: option		The input FPD_FXGPaintRenderOption.	
	// Return: void
	// Remarks:  Destroy the current paint render option.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static void Destroy(FPD_FXGPaintRenderOption option);

	//************************************
	// Function:  GetBlendMode	
	// Param[in]: option		The input FPD_FXGPaintRenderOption.	
	// Return: FS_INT32    The blending mode defined above, FPD_FXGBLEND_xxx.
	// Remarks:  Get blend mode.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_INT32	GetBlendMode(FPD_FXGPaintRenderOption option);

	//************************************
	// Function:  GetOpacity	
	// Param[in]: option		The input FPD_FXGPaintRenderOption.	
	// Return: FS_FLOAT         The opacity of the paint foreground, in range [0, 1].
	// Remarks:  Get the opacity.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_FLOAT	GetOpacity(FPD_FXGPaintRenderOption option);

	//************************************
	// Function:  GetFlow	
	// Param[in]: option		The input FPD_FXGPaintRenderOption.	
	// Return: FS_FLOAT         The flow of the paint foreground, in range [0, 1]
	// Remarks:  Get the flow value.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_FLOAT	GetFlow(FPD_FXGPaintRenderOption option);

	//************************************
	// Function:  GetAutoErase	
	// Param[in]: option		The input FPD_FXGPaintRenderOption.	
	// Return: FS_BOOLEAN       true indicate should be automatically erase.
	// Remarks: Automatically erase means that if the canvas color of the starting point is located 
	//          is equal the foreground color, the paint will use background as paint color drawing in pencil mode.
	// Notes: The property effect in pencil mode(FPD_FXGPAINT_PEN) only.
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_BOOLEAN	GetAutoErase(FPD_FXGPaintRenderOption option);
};

class CFPD_FXGPaint_V17
{
public:
	//************************************
	// Function:  GetPaintType	
	// Param[in]: paint		 The input FPD_FXGPaint.	
	// Return: FS_INT32      return FPD_FXGPAINT_XXX type.
	// Remarks: Get the paint type, defined in FPD_FXGPAINT_XXX, such as, FPD_FXGPAINT_PEN 
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************	
	static FS_INT32			GetPaintType(FPD_FXGPaint paint);

	//************************************
	// Function:  GetInkPath	
	// Param[in]: paint		     The input FPD_FXGPaint.	
	// Return: FPD_FXGInkPath    
	// Remarks: Get the ink path, then if the paint is prepared, caller can add point to the path.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_FXGInkPath	GetInkPath(FPD_FXGPaint paint);

	//************************************
	// Function:  AddPathFilter	
	// Param[in]: paint		     The input FPD_FXGPaint.	
	// Param[in]: nFilter		 A path filter type indicate in FPD_FXGPATH_FILTER_XXX above.
	// Return: FS_BOOLEAN        true indicate success, otherwise failure.
	// Remarks: Adds a specific path filter to IFXG_InkPath.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN AddPathFilter(FPD_FXGPaint paint, FS_INT32 nFilter);

	//************************************
	// Function:  RemovePathFilter	
	// Param[in]: paint		     The input FPD_FXGPaint.	
	// Param[in]: nFilter		 A path filter type indicate in FPD_FXGPATH_FILTER_XXX above.
	// Return: FS_BOOLEAN        true indicate success, otherwise failure.
	// Remarks: Removes a specific path filter from IFXG_InkPath.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN RemovePathFilter(FPD_FXGPaint paint, FS_INT32 nFilter);

	//************************************
	// Function:  GetPaintNib	
	// Param[in]: paint		     The input FPD_FXGPaint.
	// Return: FPD_FXGPaintNib   A pointer to the IFXG_PaintNib.
	// Remarks: Get current paint nib.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_FXGPaintNib	GetPaintNib(FPD_FXGPaint paint);

	//************************************
	// Function:  SetPaintNib	
	// Param[in]: paint		     The input FPD_FXGPaint.
	// Param[in]: pPaintNib		 A pointer to the IFXG_PaintNib.
	// Return: void
	// Remarks: Set the paint nib as current nib. 
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void				SetPaintNib(FPD_FXGPaint paint, FPD_FXGPaintNib pPaintNib);

	//************************************
	// Function:  SetRenderOption	
	// Param[in]: paint		     The input FPD_FXGPaint.
	// Param[in]: pRenderOption	 A pointer to the IFXG_PaintRenderOption.
	// Return: void
	// Remarks: Set the rendering option to the paint. 
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void				SetRenderOption(FPD_FXGPaint paint, FPD_FXGPaintRenderOption pRenderOption);

	//************************************
	// Function:  GetFilterType	
	// Param[in]: paint		     The input FPD_FXGPaint.	
	// Return: FS_INT32
	// Remarks: Get the filter type.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_INT32			GetFilterType(FPD_FXGPaint paint);

	//************************************
	// Function:  SetCanvas	
	// Param[in]: paint		     The input FPD_FXGPaint.	
	// Param[in]: pCanvas		 The canvas to be associated with the filter.
	// Return: void
	// Remarks: Associated filter and canvas.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static void				SetCanvas(FPD_FXGPaint paint, FPD_FXGCanvas pCanvas);

	//************************************
	// Function:  GetCanvas	
	// Param[in]: paint		     The input FPD_FXGPaint.	
	// Return: FPD_FXGCanvas    A pointer to IFXG_Canvas.
	// Remarks: Get the associated canvas if exist. 
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FPD_FXGCanvas	GetCanvas(FPD_FXGPaint paint);

	//************************************
	// Function:  Prepare	
	// Param[in]: paint		     The input FPD_FXGPaint.	
	// Return: FS_BOOLEAN    true indicate success, otherwise failure.
	// Remarks: Prepare the filter. 
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_BOOLEAN		Prepare(FPD_FXGPaint paint);

	//************************************
	// Function:  Render	
	// Param[in]: paint		     The input FPD_FXGPaint.	
	// Param[in]: pPause		 The input FS_PauseHandler.	
	// Return: FS_INT32    Flag defined like FPD_FXGFILTER_RENDER_XXX.
	// Remarks: If the filter is ready by Prepare, then we can start rendering.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	//************************************
	static FS_INT32			Render(FPD_FXGPaint paint, FS_PauseHandler pPause);
};

#ifdef __cplusplus
};
#endif

#endif
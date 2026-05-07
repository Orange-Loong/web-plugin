/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.

 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
*/

#ifndef FPD_3DEXPT_H
#define FPD_3DEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "fpd_parserExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "fpd_objsExpT.h"
#endif

#ifndef FPD_RESOURCEEXPT_H
#include "fpd_resourceExpT.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "fpd_pageExpT.h"
#endif

#ifndef FPD_RENDEREXPT_H
#include "fpd_renderExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _t_FPD_3dContext* FPD_3dContext;
typedef struct _t_FPD_3dAnnotData* FPD_3dAnnotData;
typedef struct _t_FPD_3dAnnotData_3DArtwork* FPD_3dAnnotData_3dArtwork;
typedef struct _t_FPD_3dAnnotData_RichMedia* FPD_3dAnnotData_RichMedia;
typedef struct _t_FPD_3dScene* FPD_3dScene;
typedef struct _t_FPD_3deAsset* FPD_3deAsset;
typedef struct _t_FPD_3deRuntime* FPD_3deRuntime;
typedef struct _t_FPD_3deCanvas* FPD_3deCanvas;
typedef struct _t_FPD_3deView* FPD_3deView;
typedef struct _t_FPD_3dePresetViewBuilder *FPD_3dePresetViewBuilder;
typedef struct _t_FPD_3deViewLightingScheme* FPD_3deViewLightingScheme;
typedef struct _t_FPD_3deViewCameraParam* FPD_3deViewCameraParam;
typedef struct _t_FPD_3deViewCrossSection* FPD_3deViewCrossSection;
typedef struct  _t_FPD_3deViewNode* FPD_3deViewNode;
typedef struct  _t_FPD_3deMeasure* FPD_3deMeasure;
typedef struct _t_FPD_3deViewMiscOptions* FPD_3deViewMiscOptions;
typedef struct _t_FPD_3deTextProvider*		FPD_3deTextProvider;
typedef struct _t_FPD_Script3D_HostProvider*  FPD_Script3DHostProvider;
typedef struct _t_FPD_Script3D_Engine*  FPD_Script3D_Engine;
typedef struct _t_FPD_3D_ScriptProvider*  FPD_3DScriptProvider;
typedef struct _t_FPD_3de_I18nProvider*  FPD_3DEI18nProvider;
typedef struct _t_FPD_3DCompositionProvider*  FPD_3DCompositionProvider;
typedef struct _t_FPD_3DE_ViewOverlay*  FPD_3deViewOverlay;

typedef struct _t_FPDRM_Configuration*  FPDRM_Configuration;
typedef struct _t_FPDRM_Instance*  FPDRM_Instance;
typedef struct _t_FPDRM_3DInstance*  FPDRM_3DInstance;
//typedef struct _t_FPDFRM_AnnotData*  FPDFRM_AnnotData;
typedef struct _t_FPD_3DMatrix4x4*  FPD_3DMatrix4x4;

typedef struct _t_FPD_3deViewRenderMode
{

}FPD_3deViewRenderModeRec, *FPD_3deViewRenderMode;

typedef struct _t_FPD_3deCameraConfig1* FPD_3deCameraConfig1;
typedef struct _t_FPD_3deCameraConfig2* FPD_3deCameraConfig2;
typedef struct _t_FPD_3deViewProjection* FPD_3deViewProjection;
typedef struct _t_FPD_3deViewBackground* FPD_3deViewBackground;
typedef struct _tFPD_3dVendorTempFileHandler* FPD_3dVendorHandler;
typedef struct _tFPD_3deCanvas_ControllerTool* FPD_3deCanvas_ControllerTool;

typedef struct _t_FPD_3deAnimationStyle*  FPD_3deAnimationStyle;
typedef struct _t_FPD_RMWindowDimen*  FPD_RMWindowDimen;
typedef struct _t_FPD_RMWindowPos*  FPD_RMWindowPos;
typedef struct _t_FPD_RMWindow*  FPD_RMWindow;
typedef struct _t_FPD_RMPresentation*  FPD_RMPresentation;
typedef struct _t_FPD_RMActivation*  FPD_RMActivation;
typedef struct _t_FPD_RMActivation2*  FPD_RMActivation2;
typedef struct _t_FPD_RMDeactivation*  FPD_RMDeactivation;
typedef struct _t_FPD_3dCustomMenuItemData*  FPD_3dCustomMenuItemData;
typedef struct _t_FPD_3de_SpriteData* FPD_3deSpriteData;
typedef struct _t_FPD3D_Builtin_TempFileInfo* FPD3D_Builtin_TempFileInfo;
typedef struct _t_FPD3D_Builtin_TempFileHandler* FPD3D_Builtin_TempFileHandler;
typedef struct _t_FPD_3dCustomToolButtonData*  FPD_3dCustomToolButtonData;



typedef size_t FS3DE_USIZE;
typedef intptr_t FS3DE_ISIZE;

typedef double FS3DE_Duration;
typedef float  FS3DE_Coordinate;
typedef float  FS3DE_Angle;

#define FS3DE_USIZE_MAX SIZE_MAX
#define FS3DE_ISIZE_MAX INTPTR_MAX
#define FS3DE_ISIZE_MIN INTPTR_MIN

#define FS3DE_CANVAS_NATIVE_HANDLE   FS_HWND

typedef FS3DE_Angle FS3DE_Angle0to90;
typedef FS3DE_Angle FS3DE_AngleN360to360;
typedef FS3DE_Angle FS3DE_AngleN90to90;
typedef FS3DE_Angle FS3DE_AngleN180to180;

#define FS3DE_PI 3.14159265358979323846f
#define FS3DE_ALMOST_PI (FS3DE_PI * 0.999f)


#define FS3DE_DEFINEHANDLE(type_name) \
struct type_name { \
	uintptr_t reserved_; \
	operator void*() const { return reinterpret_cast<void*>(reserved_); } \
	static type_name Null() { type_name v; v.reserved_ = 0; return v; } \
	bool operator==(const type_name& rhs) const    \
	{                                              \
		return rhs.reserved_ == reserved_;         \
	}                                              \
	bool operator<(const type_name& rhs) const     \
	{                                              \
		return rhs.reserved_ < reserved_;          \
	}                                              \
}

FS3DE_DEFINEHANDLE(FPD_H3DE_AssetNode);
FS3DE_DEFINEHANDLE(FPD_H3DE_Environment);


/* @CALLBACKGROUPSTART FR_ToolCallbacksRec */
/**
* @brief
*/
/*typedef struct _t_FPD_3deCanvas_ControllerTool
{
	FS_DWORD  m_nTag = 0;
	FS_LPVOID m_lpUserData = 0;
}FPD_3deCanvas_ControllerTool;*/
/* @CALLBACKGROUPEND */

/* @STRUCTSTART FPD_3dVendor_TempFileInfo*/
typedef struct __FPD_3D_Vendor_TempFileInfo__
{
	__FPD_3D_Vendor_TempFileInfo__()
	{
		lpszFilePath = NULL;
		dwReserved = 0;
	}
	FS_LPCSTR  lpszFilePath;
	FS_UINTPTR dwReserved;

}FPD_3dVendor_TempFileInfo, *PFPD_3dVendor_TempFileInfo;
/* @STRUCTEND */

/* @CALLBACKGROUPSTART FPD_3dVendor_TempFileCallbackRec */
typedef struct _t_PDF3D_Vendor_TempFileCallback_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_3dVendor_TempFileCallbackRec</a>).  */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART AcquireTempFile */
	/**
	* @brief Get the temp file.
	*
	* @param[in] clientData	The user-supplied data.
	* @return the temp file information.
	* @note
	*/
	PFPD_3dVendor_TempFileInfo(*AcquireTempFile)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART ReleaseTempFile */
	/**
	* @brief Release the temp file.
	*
	* @param[in] clientData	The user-supplied data.
	* @param[in] fileInfo The file information.
	* @return void
	* @note
	*/
	void(*ReleaseTempFile)(FS_LPVOID clientData, PFPD_3dVendor_TempFileInfo fileInfo);
	/* @CALLBACKEND */

}FPD_3dVendor_TempFileCallbackRec, *FPD_3dVendor_TempFileCallback;
/* @CALLBACKGROUPEND */

/* @ENUMSTART */
/**
* @name Register format. See <a>RegisterFormatLoader</a>.
*/

/*@{*/
enum FPD_3DE_AssetFormat {
	FPD_3DE_AssetFormat_GLB = 0
};
/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
/**
* @name 
*/

/*@{*/
enum FPD_3DE_EnvFormat
{
	FPD_3DE_EnvFormat_PngRGBE,
};
/*@}*/
/* @ENUMEND */


/* @ENUMSTART */
/**
* @name Register format. See <a>RegisterFormatLoader</a>.
*/

/*@{*/
enum FPD_3DArtworkFormat
{
	FPD_3DArtworkFormat_Unknown = 0,
	FPD_3DArtworkFormat_U3D,
	FPD_3DArtworkFormat_PRC,
	FPD_3DArtworkFormat_GLB,
};
/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
/**
* @name Register format. See <a>RegisterFormatLoader</a>.
*/

/*@{*/
enum FS3DE_ActivationState
{
	FS3DE_ActivationState_Uninstantiated = 0,
	FS3DE_ActivationState_Instantiated,
	FS3DE_ActivationState_Live,
};
/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
/**
* @name Register format. See <a>FS3DE_RenderModeType</a>.
*/

/*@{*/
enum FS3DE_RenderModeType
{
	FS3DE_RenderModeType_Unknown = 0,
	FS3DE_RenderModeType_Solid,
	FS3DE_RenderModeType_SolidWireframe,
	FS3DE_RenderModeType_SolidOutline,
	FS3DE_RenderModeType_Transparent,
	FS3DE_RenderModeType_TransparentWireframe,
	FS3DE_RenderModeType_BoundingBox,
	FS3DE_RenderModeType_TransparentBoundingBox,
	FS3DE_RenderModeType_TransparentBoundingBoxOutline,
	FS3DE_RenderModeType_Wireframe,
	FS3DE_RenderModeType_ShadedWireframe,
	FS3DE_RenderModeType_HiddenWireframe,
	FS3DE_RenderModeType_Illustration,
	FS3DE_RenderModeType_ShadedIllustration,
	FS3DE_RenderModeType_Vertices,
	FS3DE_RenderModeType_ShadedVertices,
};
/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
/**
* @name Register format. See <a>FS3DE_LightingSchemeType</a>.
*/

/*@{*/
enum FS3DE_LightingSchemeType
{
	FS3DE_LightingSchemeType_Artwork = 0,
	FS3DE_LightingSchemeType_None,
	FS3DE_LightingSchemeType_White,
	FS3DE_LightingSchemeType_Day,
	FS3DE_LightingSchemeType_Night,
	FS3DE_LightingSchemeType_Hard,
	FS3DE_LightingSchemeType_Primary,
	FS3DE_LightingSchemeType_Blue,
	FS3DE_LightingSchemeType_Red,
	FS3DE_LightingSchemeType_Cube,
	FS3DE_LightingSchemeType_CAD,
	FS3DE_LightingSchemeType_Headlamp,
};
/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
/**
* @name Register format. See <a>FS3DE_ViewConfigSet</a>.
*/

/*@{*/
enum FS3DE_ViewConfigSet
{
	FS3DE_ViewConfigSet_Camera = 1 << 0,
	FS3DE_ViewConfigSet_Background = 1 << 1,
	FS3DE_ViewConfigSet_CrossSection = 1 << 2,
	FS3DE_ViewConfigSet_RenderMode = 1 << 3,
	FS3DE_ViewConfigSet_LightingScheme = 1 << 4,
	FS3DE_ViewConfigSet_NodeAppearance = 1 << 5,
	FS3DE_ViewConfigSet_Measurement = 1 << 6,
	FS3DE_ViewConfigSet_Name = 1 << 7,

	FS3DE_ViewConfigSet_None = 0,
	FS3DE_ViewConfigSet_Standard =
	FS3DE_ViewConfigSet_Camera | FS3DE_ViewConfigSet_Background |
	FS3DE_ViewConfigSet_CrossSection | FS3DE_ViewConfigSet_RenderMode |
	FS3DE_ViewConfigSet_LightingScheme | FS3DE_ViewConfigSet_NodeAppearance,
	FS3DE_ViewConfigSet_All = FS3DE_ViewConfigSet_Standard | FS3DE_ViewConfigSet_Name,
};
/*@}*/
/* @ENUMEND */

/* @CALLBACKSTART FPD_3DArtworkLoader */
/**
* @brief An callback function.
* @param[in] pStream
* @param[in] eFormat
* @param[in] p3DEngine
* @return FPD_3deAsset
* @note
* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
* @see FRDocDoSave
*/
typedef FPD_3deAsset(*FPD_3DArtworkLoader)(
	FPD_Object pStream, FPD_3DArtworkFormat eFormat, FPD_3deRuntime p3DEngine);
/* @CALLBACKEND */

/* @CALLBACKSTART FPD_NotificationCallback_ContextMenu */
/**
* @brief An callback function.
* @param[in] pUserData
* @param[in] canvas
* @param[in] bHasPosition
* @param[in] x
* @param[in] y
* @return void
* @note
*/
typedef void(*FPD_NotificationCallback_ContextMenu)(FS_LPVOID pUserData,
	FPD_3deCanvas canvas, FS_BOOL bHasPosition, FS3DE_ISIZE x, FS3DE_ISIZE y);
/* @CALLBACKEND */

/* @CALLBACKSTART NotificationCallback_PointerFocusEnter */
/**
* @brief An callback function.
* @param[in] pUserData
* @param[in] pCanvas
* @return void
* @note
*/
typedef void(*FPD_NotificationCallback_PointerFocusEnter)(
	FS_LPVOID pUserData, FPD_3deCanvas pCanvas);
/* @CALLBACKEND */

/* @CALLBACKSTART NotificationCallback_PointerFocusLost */
/**
* @brief An callback function.
* @param[in] pUserData
* @param[in] pCanvas
* @return void
* @note
*/
typedef void(*FPD_NotificationCallback_PointerFocusLost)(
	FS_LPVOID pUserData, FPD_3deCanvas pCanvas);
/* @CALLBACKEND */


/* @CALLBACKSTART NotificationCallback_ClaimMeasure */
/**
* @brief An callback function.
* @param[in] pUserData
* @param[in] pCanvas
* @param[in] pMeasure
* @param[in] pTrackingView
* @return void
* @note
*/
typedef void(*FPD_NotificationCallback_ClaimMeasure)(
	FS_LPVOID pUserData, FPD_3deCanvas pCanvas, FPD_3deMeasure pMeasure, FPD_3deView pTrackingView);
/* @CALLBACKEND */


/* @CALLBACKSTART FPD_Vendor_ModelLoaderCallback */
/**
* @brief An callback function.
* @param[in] pStream
* @param[in] eFormat
* @param[in] pActualFormat
* @return FS_FileStream
* @note
* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
* @see FRDocDoSave
*/
typedef FS_FileStream(*FPD_Vendor_ModelLoaderCallback)(
	FPD_Object pStream, FPD_3DArtworkFormat eFormat, FPD_3DArtworkFormat pActualFormat);
/* @CALLBACKEND */

/* @CALLBACKSTART FPD_Vendor_U3DLoaderCallback */
/**
* @brief An callback function.
* @param[in] pMeasure
* @param[in] pUserData
*/
typedef FPD_3deAsset(*FPD_MeasureValueChangeCallback)(
	FPD_3deMeasure pMeasure, FS_LPVOID pUserData);
/* @CALLBACKEND */


/* @CALLBACKSTART FPD_Vendor_U3DLoaderCallback */
/**
* @brief An callback function.
* @param[in] pMeasure
* @param[in] pUserData
*/
typedef void(*FPD_NotificationCallback_RequestUpdateBackground)(FS_DIBitmap bmpBitmap, FS_LPVOID pUserData, FPD_3deCanvas pCanvas);
/* @CALLBACKEND */


/* @CALLBACKSTART FPD_Vendor_U3DLoaderCallback */
/**
* @brief An callback function.
* @param[in] pMeasure
* @param[in] pUserData
*/
typedef void(*FPD_NotificationCallback_RequestUpdateForeground)(bool& bHaveBitmap, FS_DIBitmap bmpBitmap, FS_LPVOID pUserData, FPD_3deCanvas pCanvas);
/* @CALLBACKEND */


/* @ENUMSTART */
/**
* @name Register format. See <a>FSPDF3D_ActivateCondition</a>.
*/
/*@{*/
enum FSPDF3D_ActivateCondition
{
	FSPDF3D_ActivateCondition_PageOpen,
	FSPDF3D_ActivateCondition_PageBecomeVisible,
	FSPDF3D_ActivateCondition_ExplicitActivation
};
/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
/**
* @name Register format. See <a>FSPDF3D_DeactivateCondition</a>.
*/
/*@{*/
enum FSPDF3D_DeactivateCondition
{
	FSPDF3D_DeactivateCondition_PageClosed,
	FSPDF3D_DeactivateCondition_PageBecomeInvisible,
	FSPDF3D_DeactivateCondition_ExplicitDeactivation,
};
/*@}*/
/* @ENUMEND */

/* @STRUCTSTART FPDF3D_ActivationOptions*/
typedef struct __FPDF3D_Activation_Options__
{
	__FPDF3D_Activation_Options__()
	{
		eActivateCondition = FSPDF3D_ActivateCondition_ExplicitActivation;
		eDeactivateCondition = FSPDF3D_DeactivateCondition_PageBecomeInvisible;
		eActivatedInstantiateState = FS3DE_ActivationState_Live;
		eDeactivatedInstantiateState = FS3DE_ActivationState_Uninstantiated;
		bShowToolbar = TRUE;
		bShowNavigationPanel = FALSE;
	}

	FSPDF3D_ActivateCondition	 eActivateCondition;
	FSPDF3D_DeactivateCondition	 eDeactivateCondition;
	FS3DE_ActivationState eActivatedInstantiateState;
	FS3DE_ActivationState eDeactivatedInstantiateState;
	FS_BOOL						 bShowToolbar;
	FS_BOOL						 bShowNavigationPanel;

}FPDF3D_ActivationOptions, *PFPDF3D_ActivationOptions;
/* @STRUCTEND */

/* @ENUMSTART */
/**
* @name View projection format. See <a>FS3DE_ViewProjectionMode</a>.
*/
/*@{*/
enum FS3DE_ViewProjectionMode
{
	FS3DE_ViewProjectionMode_Perspective,
	FS3DE_ViewProjectionMode_Orthogonal,
};
/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
/**
* @name See <a>FSInitialAxis</a>.
*/
/*@{*/
enum FSInitialAxis
{
	InitialAxis_X = 0,
	InitialAxis_Y,
	InitialAxis_Z
};
/*@}*/
/* @ENUMEND */


/* @STRUCTSTART FS3DE_CrossSectionConfig1*/
typedef struct __FPD_3D_Cross_SectionConfig1__
{
	__FPD_3D_Cross_SectionConfig1__()
	{
	}
	FS_FLOAT				fOffsetPercent;
	FS3DE_AngleN180to180	fSlope1;
	FS3DE_AngleN180to180	fSlope2;
	FS_BOOL					bFlip;
	FSInitialAxis			eInitialAxis;

}FS3DE_CrossSectionConfig1, *PFS3DE_CrossSectionConfig1;
/* @STRUCTEND */


/* @STRUCTSTART FS3DE_CrossSectionConfig2*/
typedef struct __FPD_3D_Cross_SectionConfig2__
{
	__FPD_3D_Cross_SectionConfig2__()
	{
	}
	FS_FLOAT				fDistance;
	FS3DE_AngleN180to180	fSlope1;
	FS3DE_AngleN180to180	fSlope2;
	FS_BOOL					bFlip;
	FSInitialAxis			eInitialAxis;

}FS3DE_CrossSectionConfig2, *PFS3DE_CrossSectionConfig2;
/* @STRUCTEND */


/* @STRUCTSTART FS3DE_Vector*/
typedef struct __FPD_3D_Vector__
{
	__FPD_3D_Vector__()
	{
		rgComponents[0] = 0.0f;
		rgComponents[1] = 0.0f;
		rgComponents[2] = 0.0f;
	}
public:
	FS_FLOAT rgComponents[3];

}FS3DE_Vector, *PFS3DE_Vector;
/* @STRUCTEND */

/* @STRUCTSTART FS3DE_CameraConfig1*/
typedef struct __FPD_3DE_CameraConfig1__
{
	FS3DE_Vector		 vCameraPos;
	FS3DE_Vector		 vTargetPos;
	FS3DE_Angle0to90	 fFOV;
	FS3DE_AngleN360to360 fRoll;
}FS3DE_CameraConfig1, *PFS3DE_CameraConfig1;
/* @STRUCTEND */

/* @STRUCTSTART FS3DE_CameraConfig2*/
typedef struct __FPD_3DE_CameraConfig2__
{
	FS3DE_AngleN360to360 fAzimuth;
	FS3DE_AngleN90to90   fAltitude;
	FS3DE_Coordinate	 fDistance;
	FS3DE_Vector		 vTargetPos;
	FS3DE_Angle0to90	 fFOV;
	FS3DE_AngleN360to360 fRoll;
}FS3DE_CameraConfig2, *PFS3DE_CameraConfig2;
/* @STRUCTEND */

/* @ENUMSTART */
/**
* @name MesureType. See <a>FS3DE_MeasureType</a>.
*/
/*@{*/
enum FS3DE_MeasureType
{
	FS3DE_MeasureType_LinearDim,
	FS3DE_MeasureType_PerpendicularDim,
	FS3DE_MeasureType_AngularDim,
	FS3DE_MeasureType_RadialDim,
	FS3DE_MeasureType_3DCommentNote,
	FS3DE_MeasureType_Unknown
};
/*@}*/
/* @ENUMEND */


/* @ENUMSTART */
/**
* @name MesureType. See <a>FS3DE_MeasureType</a>.
*/
/*@{*/
enum FS3DE_ControllerToolTag
{
	FS3DE_ControllerToolTag_Rotate,
	FS3DE_ControllerToolTag_Spin,
	FS3DE_ControllerToolTag_Pan,
	FS3DE_ControllerToolTag_Zoom,
	FS3DE_ControllerToolTag_Walk,
	FS3DE_ControllerToolTag_Fly,
	FS3DE_ControllerToolTag_Measure,
	FS3DE_ControllerToolTag_Comment,
	FS3DE_ControllerToolTag_CustomTool0,
};
/*@}*/
/* @ENUMEND */



/* @ENUMSTART */
/**
* @name Measure Angle Type. See <a>FS3DE_MeasureAngleType</a>.
*/
/*@{*/
enum FS3DE_MeasureAngleType
{
	FS3DE_MeasureAngleType_Degree,
	FS3DE_MeasureAngleType_Radian
};
/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
/**
* @name Measure Radial Type. See <a>FS3DE_MeasureRadialType</a>.
*/
/*@{*/
enum FS3DE_MeasureRadialType
{
	FS3DE_MeasureRadialType_Radius,
	FS3DE_MeasureRadialType_Diameter
};
/*@}*/
/* @ENUMEND */

/* @STRUCTSTART FS3DE_CameraConfig1*/
typedef struct __FS3DE_RGBColor__
{
public:
	static __FS3DE_RGBColor__ NewUnchecked(FS_FLOAT r, FS_FLOAT g, FS_FLOAT b)
	{
		__FS3DE_RGBColor__ result;
		result.rgComponents[0] = r;
		result.rgComponents[1] = g;
		result.rgComponents[2] = b;
		return result;
	};
public:
	FS_FLOAT rgComponents[3];
}FS3DE_RGBColor, *PFS3DE_RGBColor;
/* @STRUCTEND */

/* @ENUMSTART */
/**
* @name View ConfigSet. See <a>FS3DE_ViewConfigSet</a>.
*/
/*@{*/
enum FS3DE_GridMode
{
	FS3DE_GRID_OFF,
	FS3DE_GRID_WIRE,
	FS3DE_GRID_SOLID,
	FS3DE_GRID_TRANSPARENT,
};
/*@}*/
/* @ENUMEND */


/* @CALLBACKGROUPSTART */
#ifndef FPD_ScriptHostProvider
#define FPD_ScriptHostProvider
/** @brief A callback for <a>FPD_ScriptHostProvider</a>. See <a>FPD_ScriptHostProvider</a>.
*/
typedef struct
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EnumPage</a>).  */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOL(*Host)(FS_LPVOID clientData, FPD_Document pDoc, FSJSE_HVALUE hValue);
	FS_BOOL(*ConsolePrint)(FS_LPVOID clientData, FS_LPCBYTE  bsText);
	FS_BOOL(*ConsolePrintLn)(FS_LPVOID clientData, FS_LPCBYTE bsText);
	void(*NotifyScriptExecutionStart)(FS_LPVOID clientData, FPD_Document pDoc);
	void(*NotifyScriptExecutionFinish)(FS_LPVOID clientData, FPD_Document pDoc);
	double(*RuntimeVersion)(FS_LPVOID clientData);
	/* @CALLBACKEND */
}FPD_ScriptHostProviderCallbacksRec, *FPD_ScriptHostProviderCallbacks;
#endif
/* @CALLBACKGROUPEND */


/* @CALLBACKGROUPSTART */
#ifndef FPD_I18NPROVIDER
#define FPD_I18NPROVIDER
/** @brief A callback for <a>FPD_ScriptHostProvider</a>. See <a>FPD_ScriptHostProvider</a>.
*/
typedef struct
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EnumPage</a>).  */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void(*FormatNumberWithPrecision)(FS_LPVOID clientData, FS_WideString wsResult, FS_FLOAT fNumber, FS3DE_USIZE nPrecision);
	void(*FormatNodeLocalizedName)(FS_LPVOID clientData, FS_WideString wsResult, FS_LPCWSTR wsInput);
}FPD_I18nProviderCallbacksRec, *FPD_I18nProviderCallbacks;
#endif
/* @CALLBACKGROUPEND */


/* @CALLBACKGROUPSTART */
#ifndef FPD_COMPOSITIONPROVIDER
#define FPD_COMPOSITIONPROVIDER
/** @brief A callback for <a>FPD_ScriptHostProvider</a>. See <a>FPD_ScriptHostProvider</a>.
*/
typedef struct
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EnumPage</a>).  */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	void(*FRGenerateBackground)(FS_LPVOID clientData, FS_DIBitmap* bmpBitmap, FPD_3dAnnotData pAnnotData, FPD_3deCanvas pCanvas);

	FS_BOOL(*FRGenerateForeground)(FS_LPVOID clientData, FS_DIBitmap* bmpBitmap, FPD_3dAnnotData pAnnotData, FPD_3deCanvas pCanvas, FPD_3deViewOverlay pViewOverlay);

	/* @CALLBACKEND */
}FPD_3DCompositionProviderCallbacksRec, *FPD_3DCompositionProviderCallbacks;
#endif
/* @CALLBACKGROUPEND */


/* @STRUCTSTART FS3DE_3DMatrix*/
typedef struct __FS3DE_3DMatrix__
{
	__FS3DE_3DMatrix__(FS_FLOAT val0, FS_FLOAT val1,
		FS_FLOAT val2, FS_FLOAT val3, FS_FLOAT val4,
		FS_FLOAT val5, FS_FLOAT val6, FS_FLOAT val7,
		FS_FLOAT val8, FS_FLOAT val9, FS_FLOAT val10,
		FS_FLOAT val11)
	{
		Coeffs[0] = val0;
		Coeffs[1] = val1;
		Coeffs[2] = val2;
		Coeffs[3] = val3;
		Coeffs[4] = val4;
		Coeffs[5] = val5;
		Coeffs[6] = val6;
		Coeffs[7] = val7;
		Coeffs[8] = val8;
		Coeffs[9] = val9;
		Coeffs[10] = val10;
		Coeffs[11] = val11;
	}

	FS_FLOAT Coeffs[4 * 3];
}FS3DE_3DMatrix, *PFS3DE_3DMatrix;
/* @STRUCTEND */

typedef struct _t_FS3DE_BoundingBox* FS3DE_BoundingBox;

enum FS3DE_MeasureSnapType
{
	FS3DE_MeasureSnapType_EdgeEndpoint,
	FS3DE_MeasureSnapType_LinearEdge,
	FS3DE_MeasureSnapType_RadialEdge,
	FS3DE_MeasureSnapType_Sihouette,
	FS3DE_MeasureSnapType_PlanarFace,
	FS3DE_MeasureSnapType_Unknown,
};

/* @ENUMSTART */
/**
* @name The temp file generation. See <a>FPD3D_Vendor_TempFileGeneration</a>.
*/

/*@{*/
enum FPD3D_Vendor_TempFileGeneration
{
	FPD3D_Vendor_TempFileGeneration_None,
	FPD3D_Vendor_TempFileGeneration_Source,
	FPD3D_Vendor_TempFileGeneration_Dest,
};
/*@}*/
/* @ENUMEND */

/* @CALLBACKSTART FPD_Vendor_U3DLoaderCallback */
/**
* @brief An callback function.
* @param[in] pMeasure
* @param[in] pUserData
*/
typedef void(*FPD3D_CursorChangeHookFn)(FPD_3deCanvas pCanvas, FS3DE_ControllerToolTag eToolTag, FS_UINT uCursorIdx, FS_LPVOID pUserData);
/* @CALLBACKEND*/

/* @ENUMSTART */
/**
* @name View ConfigSet. See <a>FS3DE_BuiltinSimpleControllerTool</a>.
*/
/*@{*/
enum FS3DE_BuiltinSimpleControllerTool
{
	FS3DE_BuiltinSimpleControllerTool_Rotate,
	FS3DE_BuiltinSimpleControllerTool_Spin,
	FS3DE_BuiltinSimpleControllerTool_Pan,
	FS3DE_BuiltinSimpleControllerTool_Zoom,
	FS3DE_BuiltinSimpleControllerTool_Walk,
	FS3DE_BuiltinSimpleControllerTool_Fly
};
/*@}*/
/* @ENUMEND */


/* @ENUMSTART */
/**
* @name View ConfigSet. See <a>FS3DE_BuiltinSimpleControllerTool</a>.
*/
/*@{*/
enum FS3DE_TextScalingKind
{
	FS3DE_TextScalingKind_WorldSpace = 1,
	FS3DE_TextScalingKind_ScreenSpace = 2,
};
/*@}*/
/* @ENUMEND */
/**
* @brief
*
*/
enum FPDRM_DisplayToolbar
{
	FPDRM_DisplayToolbar_Yes,
	FPDRM_DisplayToolbar_No,
	FPDRM_DisplayToolbar_YesIf3D,
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief
*
*/
enum FPD3D_CanvasWindowStyle
{
	FPD3D_CanvasWindowStyle_Embedded,
	FPD3D_CanvasWindowStyle_Windowed,
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief
*
*/
enum FS3DE_AnimationStyleType
{
	FS3DE_AnimationStyleType_None,
	FS3DE_AnimationStyleType_Linear,
	FS3DE_AnimationStyleType_Oscillating
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief
*
*/
enum FPDRM_WindowAlign
{
	FPDRM_WindowAlign_Near,
	FPDRM_WindowAlign_Center,
	FPDRM_WindowAlign_Far,
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief
*
*/
enum FPDRM_ContentType
{
	FPDRM_ContentType_Unknown,
	FPDRM_ContentType_3D,
	FPDRM_ContentType_Flash,
	FPDRM_ContentType_Sound,
	FPDRM_ContentType_Video,
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief
*
*/
enum FPD3D_CustomToolButtonType
{
	FPD3D_CustomToolButtonType_PushButton,
	FPD3D_CustomToolButtonType_ToolButton,
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief
*
*/
enum FPD3D_CustomMenuItemType
{
	FPD3D_CustomMenuItemType_Default,
	FPD3D_CustomMenuItemType_Checked,
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief
*
*/
enum FPD3DE_AssetCameraNode_ProjectionType
{
	FPD3DE_AssetCameraNode_ProjectionType_Perspective,
	FPD3DE_AssetCameraNode_ProjectionType_Orthographic,
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief
*
*/
enum FPD3DE_AssetCameraNode_BindingType
{
	FPD3DE_AssetCameraNode_BindingType_Absolute,
	FPD3DE_AssetCameraNode_BindingType_Min,
	FPD3DE_AssetCameraNode_BindingType_Max,
	FPD3DE_AssetCameraNode_BindingType_Horizontal,
	FPD3DE_AssetCameraNode_BindingType_Vertical,
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief
*
*/
enum FPD3D_Builtin_TempFileGeneration
{
	FPD3D_Builtin_TempFileGeneration_None,
	FPD3D_Builtin_TempFileGeneration_Source,
	FPD3D_Builtin_TempFileGeneration_Dest
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief
*
*/
enum FPD3DE_Asset_NodeType
{
	FPD3DE_Asset_NodeType_ModelRoot,
	FPD3DE_Asset_NodeType_Group,
	FPD3DE_Asset_NodeType_Mesh,
	FPD3DE_Asset_NodeType_Sprite,
	FPD3DE_Asset_NodeType_Markup,
	FPD3DE_Asset_NodeType_PunctualLight,
	FPD3DE_Asset_NodeType_AmbientLight,
	FPD3DE_Asset_NodeType_ViewCamera,
	FPD3DE_Asset_NodeType_ClippingPlane,
	FPD3DE_Asset_NodeType_Procedural,
	FPD3DE_Asset_NodeType_Bone,
	FPD3DE_Asset_NodeType_Dummy,
};
/* @ENUMEND */

/* @CALLBACKGROUPSTART */
#ifndef FPD_3DBUILTINTEMPFILECALLBACK
#define FPD_3DBUILTINTEMPFILECALLBACK
/** @brief A callback for <a>FPD_ScriptHostProvider</a>. See <a>FPD_ScriptHostProvider</a>.
*/
typedef struct
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EnumPage</a>).  */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;	

	FPD3D_Builtin_TempFileInfo(*FPDAcquireTempFile)(FS_LPVOID clientData, FPD3D_Builtin_TempFileGeneration fileGeneration);
	void(*FPDReleaseTempFile)(FS_LPVOID clientData, FPD3D_Builtin_TempFileInfo pTempFile);

	/* @CALLBACKEND */
}FPD_3DBuiltinTempFileCallbackRec, *FPD_3DBuiltinTempFileCallbacks;
#endif
/* @CALLBACKGROUPEND */

enum FPD3D_RenderingArtifactState
{
	FPD3D_RenderingArtifact_Occurred,
	FPD3D_RenderingArtifact_DoneAndDisappeared,
	FPD3D_RenderingArtifact_WontDisappearBeforeCancelling,
	FPD3D_RenderingArtifact_CancelledAndDisappeared,
};

/* @CALLBACKGROUPSTART */
#ifndef FPD_3DEVENTHANDLERPROVIDER
#define FPD_3DEVENTHANDLERPROVIDER
/** @brief A callback for <a>FPD_3DEventHandlerProvider</a>. See <a>FPD_3DEventHandlerProvider</a>.
*/
typedef struct
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EnumPage</a>).  */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;
	
	void(*FPDNotifyMeasureValueChanged)(FS_LPVOID clientData, FPD_3deMeasure pMeasure);
	void(*FPDRequestCursorUpdated)(FS_LPVOID clientData, FPD_3deCanvas pCanvas, FS3DE_ControllerToolTag eToolTag, FS3DE_USIZE uCursorIdx);
	void(*FPDRequestViewSwitched)(FS_LPVOID clientData, FPD_3dAnnotData pAnnotData, FPDRM_3DInstance p3dInstance, FPD_3deView pView, FS_BOOLEAN bUseAnimation);
	void(*FPDNotifyModelImportFailure)(FS_LPVOID clientData, FS_BOOLEAN bFromScript, FS_DWORD dwFailReason);
	void(*FPDRequestFreezeView)(FS_LPVOID clientData, FPD_3dAnnotData pAnnotData, FPDRM_3DInstance p3dInstance, FS_BOOLEAN bFreezeView);
	void(*FPDNotifyRenderingArtifact)(FS_LPVOID clientData, FPD_3dAnnotData pAnnotData, FPDRM_3DInstance p3DInstance, FPD3D_RenderingArtifactState eState);
	/* @CALLBACKEND */
}FPD_3DEventHandlerProviderCallbackRec, *FPD_3DEventHandlerProviderCallbacks;
#endif
/* @CALLBACKGROUPEND */




#ifdef __cplusplus
};
#endif

#endif
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
//*****************************
/* 3dContext HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3dContext, FPD3dContextNew, (FPD_Document fpdDoc))

INTERFACE(void, FPD3dContextDestroy, (FPD_3dContext context))

INTERFACE(FS_BOOL, FPD3dContextInitDefaultEngine, (FPD_3dContext contex))

INTERFACE(FS_BOOL, FPD3dContextInitializeWithEngine, (FPD_3dContext contex,  FPD_3deRuntime pEngine))

INTERFACE(void, FPD3dContextRegisterScriptProvider, (FPD_3dContext contex,  FPD_3DScriptProvider pHostProvider))

INTERFACE(void, FPD3dContextRegisterFormatLoader, (FPD_3dContext contex,  FPD_3DArtworkFormat format,  FPD_Vendor_ModelLoaderCallback loaderCallback))

INTERFACE(void, FPD3dContextRegisterCompositionProvider, (FPD_3dContext contex,  FPD_3DCompositionProvider pCompositionProvider))

INTERFACE(FPD_Document, FPD3dContextGetDocument, (FPD_3dContext contex))

INTERFACE(FPD_3deRuntime, FPD3dContextGetEngine, (FPD_3dContext contex))

INTERFACE(FS_BOOL, FPD3dContextIsPDF20, (FPD_3dContext contex))

INTERFACE(FPD_Vendor_ModelLoaderCallback, FPD3dContextGetFormatLoader, (FPD_3dContext contex,  FPD_3DArtworkFormat eFormat))

INTERFACE(FPD_3dAnnotData, FPD3dContextLoadAnnotData, (FPD_Object pPageDict,  FPD_Object pAnnotDict,  FPD_3dContext contex))

INTERFACE(FS_LPVOID, FPD3dContextRegisterEventHandlerProvider, (FPD_3dContext contex,  FPD_3DEventHandlerProviderCallbacks pCallback))

INTERFACE(void, FPD3dContextReleaseEventHandlerProvider, (FS_LPVOID handler))

INTERFACE(void, FPD3dContextEnableIsoTs32007, (FPD_3dContext contex))

NumOfSelector(FPD3dContext)
ENDENUM

//*****************************
/* 3dAnnotData HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3dAnnotData_3dArtwork, FPD3dAnnotDataAs3DArtwork, (FPD_3dAnnotData annotData))

INTERFACE(FPD_3dAnnotData_RichMedia, FPD3dAnnotDataAsRichMedia, (FPD_3dAnnotData annotData))

INTERFACE(void, FPD3dAnnotDataRelease, (FPD_3dAnnotData annotData))

NumOfSelector(FPD3dAnnotData)
ENDENUM

//*****************************
/* 3dAnnotData3dArtwork HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPDRM_3DInstance, FPD3dAnnotData3dArtworkGet3DInstance, (FPD_3dAnnotData_3dArtwork artwork))

INTERFACE(FPD_3deView, FPD3dAnnotData3dArtworkGetDefaultPresetView, (FPD_3dAnnotData_3dArtwork artwork))

INTERFACE(void, FPD3dAnnotData3dArtworkGetActivationOptions, (FPD_3dAnnotData_3dArtwork artwork,  PFPDF3D_ActivationOptions poutOptions))

INTERFACE(void, FPD3dAnnotData3dArtworkSetActivationOptions, (FPD_3dAnnotData_3dArtwork artwork,  PFPDF3D_ActivationOptions options))

INTERFACE(FS_BOOL, FPD3dAnnotData3dArtworkLoadActivationOptions, (FPD_3dAnnotData_3dArtwork artwork,  FPD_Object pAnnotDict,  PFPDF3D_ActivationOptions poutOptions))

INTERFACE(void, FPD3dAnnotData3dArtworkRetrievePresetViewList, (FPD_3dAnnotData_3dArtwork artwork,  FS_PtrArray p3deViewArray))

INTERFACE(void, FPD3dAnnotData3dArtworkUpdatePresetViewList, (FPD_3dAnnotData_3dArtwork artwork,  FS_PtrArray p3deViewArray))

INTERFACE(FPD_3deView, FPD3dAnnotData3dArtworkCreatePresetView, (FPD_3dAnnotData_3dArtwork artwork,  FS_LPCWSTR lpwsDisplayName))

INTERFACE(FPD_3deView, FPD3dAnnotData3dArtworkFindPresetView, (FPD_3dAnnotData_3dArtwork artwork,  FPD_Object pViewDict,  FS_BOOL bImportIfNotLoaded))

INTERFACE(FPD_3deView, FPD3dAnnotData3dArtworkGetArtworkDefaultPresetView, (FPD_3dAnnotData_3dArtwork artwork))

NumOfSelector(FPD3dAnnotData3dArtwork)
ENDENUM

//*****************************
/* 3dScene HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3dContext, FPD3dSceneGetContext, (FPD_3dScene scene))

INTERFACE(FS_BOOL, FPD3dSceneIsSharedScene, (FPD_3dScene scene))

INTERFACE(FPD_3deAsset, FPD3dSceneGetAssetFor3DInstance, (FPD_3dScene scene,  FPDRM_3DInstance pInstance))

INTERFACE(FPDRM_3DInstance, FPD3dSceneGet3DInstanceByAsset, (FPD_3dScene scene,  FPD_3deAsset pAsset))

INTERFACE(FPD_3DArtworkFormat, FPD3dSceneGetFormat, (FPD_3dScene scene))

NumOfSelector(FPD3dScene)
ENDENUM

//*****************************
/* 3deAsset HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_H3DE_AssetNode, FPD3deAssetGetRootNode, (FPD_3deAsset asset))

INTERFACE(FPD_H3DE_AssetNode, FPD3deAssetGetParentNode, (FPD_3deAsset asset,  FPD_H3DE_AssetNode *nodeCurrent))

INTERFACE(FPD_H3DE_AssetNode, FPD3deAssetGetNextSiblingNode, (FPD_3deAsset asset,  FPD_H3DE_AssetNode *nodeCurrent))

INTERFACE(FPD_H3DE_AssetNode, FPD3deAssetGetFirstChildNode, (FPD_3deAsset asset,  FPD_H3DE_AssetNode *nodeCurrent))

INTERFACE(void, FPD3deAssetGetNodeName, (FPD_3deAsset asset,  FPD_H3DE_AssetNode *node,  FS_WideString *wsName))

INTERFACE(void, FPD3deAssetNarrowScope, (FPD_3deAsset asset,  FPD_H3DE_AssetNode *node,  FS_BOOL bOnlyItsChildren))

INTERFACE(FS3DE_USIZE, FPD3deAssetGetNodeMetaDataCount, (FPD_3deAsset asset,  FPD_H3DE_AssetNode *node))

INTERFACE(void, FPD3deAssetGetNodeMetaDataItem, (FPD_3deAsset asset,  FPD_H3DE_AssetNode *node,  FS3DE_USIZE index,  FS_WideString *wsKey,  FS_WideString *wsValue))

INTERFACE(void, FPD3deAssetComputeBoundingBox, (FPD_3deAsset asset,  FS3DE_BoundingBox* box))

INTERFACE(void, FPD3deAssetSetShowOrientationAxes, (FPD_3deAsset asset,  FS_BOOL bShow))

INTERFACE(void, FPD3deAssetGetNodeUIName, (FPD_3deAsset asset,  FPD_H3DE_AssetNode *node,  FS_WideString* wsName))

INTERFACE(FPD_3deSpriteData, FPD3deAssetGetSpriteNodeSpriteData, (FPD_3deAsset asset,  FPD_H3DE_AssetNode* node))

INTERFACE(FPD_H3DE_AssetNode, FPD3deAssetFindNodeBySpriteData, (FPD_3deAsset asset,  FPD_3deSpriteData pSpriteData))

INTERFACE(FS_BOOLEAN, FPD3deAssetGetUnitsInMillimeters, (FPD_3deAsset asset,  FS_FLOAT* pUnits))

INTERFACE(FPD3DE_Asset_NodeType, FPD3deAssetGetNodeType, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(FS3DE_Vector, FPD3deAssetGetCameraNodeTargetPositionLocal, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(FPD_H3DE_AssetNode, FPD3deAssetGetCameraNodeTarget, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(FS3DE_Vector, FPD3deAssetGetCameraNodePositionLocal, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(FS_FLOAT, FPD3deAssetGetCameraNodeRoll, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(FPD3DE_AssetCameraNode_ProjectionType, FPD3deAssetGetCameraNodeProjectionType, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(FS_FLOAT, FPD3deAssetGetCameraNodeFov, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(FS_FLOAT, FPD3deAssetGetCameraNodeNear, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node,  FS_FLOAT* fNear))

INTERFACE(FS_FLOAT, FPD3deAssetGetCameraNodeFar, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node,  FS_FLOAT* fFar))

INTERFACE(FPD3DE_AssetCameraNode_BindingType, FPD3deAssetGetCameraNodeBinding, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(FS_FLOAT, FPD3deAssetGetCameraNodeViewPlaneSize, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(FS3DE_Vector, FPD3deAssetGetCameraNodeUpLocal, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(FS_FLOAT, FPD3deAssetGetCameraNodeAbsoluteBindingScale, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(FS_FLOAT, FPD3deAssetGetCameraNodeUseAbsoluteBinding, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node))

INTERFACE(void, FPD3deAssetSetCameraNodeNear, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node,  FS_FLOAT fNear))

INTERFACE(void, FPD3deAssetSetCameraNodeFar, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node,  FS_FLOAT fFar))

INTERFACE(FS3DE_Vector, FPD3deAssetGetCameraNodeDirectionFromScreen, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node,  FS_FLOAT fX,  FS_FLOAT fY,  FS_FLOAT fCanvasWidth,  FS_FLOAT fCanvasHeight))

INTERFACE(FS3DE_Vector, FPD3deAssetGetCameraNodeScreenFromPosition, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node,  const FS3DE_Vector vPosition,  FS_FLOAT fCanvasWidth,  FS_FLOAT fCanvasHeight))

INTERFACE(void, FPD3deAssetGetNodeWorldSpaceTransform, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node,  FPD_3DMatrix4x4* outMatrix))

INTERFACE(void, FPD3deAssetGetNodeLocalSpaceTransform, (FPD_3deAsset asset,  FPD_H3DE_AssetNode node,  FPD_3DMatrix4x4* outMatrix))

NumOfSelector(FPD3deAsset)
ENDENUM

//*****************************
/* 3deRuntime HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3deRuntime, FPD3deRuntimeCreateRuntime, ())

INTERFACE(FPD_3deRuntime, FPD3deRuntimeCreateRuntimeWithBackend, (FS_DWORD dwBackendId))

INTERFACE(FPD_3deAsset, FPD3deRuntimeLoadAsset, (FPD_3deRuntime runtime,  FS_FileStream pReadStream,  FPD_3DE_AssetFormat eFormat))

INTERFACE(void, FPD3deRuntimeTick, (FPD_3deRuntime runtime))

INTERFACE(FS3DE_USIZE, FPD3deRuntimeCountInstantiatedCanvases, (FPD_3deRuntime runtime))

INTERFACE(void, FPD3deRuntimeQueryAvailableBackendList, (FS_DWordArray rgBackends))

INTERFACE(void, FPD3deRuntimeGetBackendFriendlyName, (FS_DWORD dwBackendId,  FS_WideString wsoutName))

INTERFACE(void, FPD3deRuntimeUpdateTextProvider, (FPD_3deRuntime p3dEngine,  FPD_3deTextProvider pTextProvider))

INTERFACE(void, FPD3deRuntimeUpdatePreference_AngleUnitDisplay, (FPD_3deRuntime p3dEngine,  FS_WideString wsDegreeUnitText,  FS_WideString wsRadianUnitText))

INTERFACE(void, FPD3deRuntimeUpdatePreference_NodeMetadataStoragePath, (FPD_3deRuntime p3dEngine,  FS_LPCSTR lpszNodeMetadataStoragePath))

INTERFACE(void, FPD3deRuntimeUpdateProvider_I18n, (FPD_3deRuntime p3dEngine,  FPD_3DEI18nProvider pProvider))

INTERFACE(void, FPD3deRuntimeUpdatePreference_AntiAliasing, (FPD_3deRuntime p3dEngine,  const FS_WordArray rgPreferenceSequence))

INTERFACE(void, FPD3deRuntimeQueryPreference_ForceDoubleSidedRendering, (FPD_3deRuntime p3dEngine,  FS_BOOL* bForce))

INTERFACE(void, FPD3deRuntimeUpdatePreference_NodeNameStoragePath, (FPD_3deRuntime p3dEngine,  FS_LPCSTR lpszNodeNameStoragePath))

INTERFACE(FPD_3deAsset, FPD3deRuntimeCreateAsset, (FPD_3deRuntime runtime))

INTERFACE(void, FPD3deRuntimeUpdatePreference_ExtensionPrefix, (FPD_3deRuntime runtime,  FS_LPCSTR lpszExtensionPrefix))

INTERFACE(void, FPD3deRuntimeUpdatePreference_DrawBatchLimit, (FPD_3deRuntime runtime,  FS_DWORD nDrawBatchLimit))

INTERFACE(FPD_H3DE_Environment, FPD3deRuntimeCreateEnvironment, (FPD_3deRuntime runtime,  FS_FileStream pData,  FPD_3DE_EnvFormat eFormat,  FS_BOOLEAN bPhysicsMaterialOnly,  FS_BOOLEAN bSetAsDefault))

NumOfSelector(FPD3deRuntime)
ENDENUM

//*****************************
/* 3deCanvas HFT functions */
//*****************************

BEGINENUM
INTERFACE(void*, FPD3deCanvasGetNativeWindow, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deCanvasInstantiate, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deCanvasInstantiateAndLive, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deCanvasUninstantiate, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deCanvasGetState, (FPD_3deCanvas canvas))

INTERFACE(FPD_3deView, FPD3deCanvasAcquireCurrentView, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deCanvasReleaseCurrentView, (FPD_3deCanvas canvas,  FPD_3deView pView))

INTERFACE(FPD_3deAsset, FPD3deCanvasGetPrimaryAsset, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deCanvasSetControllerTool, (FPD_3deCanvas canvas,  const FPD_3deCanvas_ControllerTool tool))

INTERFACE(void, FPD3deCanvasRelocateInPlace, (FPD_3deCanvas canvas,  FS_Rect rect))

INTERFACE(void, FPD3deCanvasSetNotificationCallback_ContextMenu, (FPD_3deCanvas canvas,  FPD_NotificationCallback_ContextMenu pCallback,  FS_LPVOID pUserData))

INTERFACE(void, FPD3deCanvasSetNotificationCallback_PointerFocus, (FPD_3deCanvas canvas,  FPD_NotificationCallback_PointerFocusEnter pEnterCallback,  FPD_NotificationCallback_PointerFocusLost pLostCallback,  FS_LPVOID pUserData))

INTERFACE(FS_BOOL, FPD3deCanvasHaveAnimation, (FPD_3deCanvas canvas))

INTERFACE(FS_BOOL, FPD3deCanvasIsAnimationPlaying, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deCanvasToggleAnimation, (FPD_3deCanvas canvas,  FS_BOOL bPlaying))

INTERFACE(void, FPD3deCanvasSeekAnimationProgress, (FPD_3deCanvas canvas,  FS_FLOAT fPercentage))

INTERFACE(FS_FLOAT, FPD3deCanvasGetAnimationProgress, (FPD_3deCanvas canvas))

INTERFACE(FPD_H3DE_AssetNode, FPD3deCanvasGetChosenNode, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deCanvasSetChosenNode, (FPD_3deCanvas canvas,  FPD_H3DE_AssetNode hChosenNode))

INTERFACE(void, FPD3deCanvasSetNotificationCallback_ClaimMeasure, (FPD_3deCanvas canvas,  FPD_NotificationCallback_ClaimMeasure pCallback,  FS_LPVOID pUserData))

INTERFACE(FS_BOOL, FPD3deCanvasSnapshot, (FPD_3deCanvas canvas,  FS_DIBitmap* bmpDIBitmap))

INTERFACE(void, FPD3deCanvasSetNotificationCallback_RequestUpdateBackground, (FPD_3deCanvas canvas,  FPD_NotificationCallback_RequestUpdateBackground pCallback,  FS_LPVOID pUserData))

INTERFACE(void, FPD3deCanvasSetNotificationCallback_RequestUpdateForeground, (FPD_3deCanvas canvas,  FPD_NotificationCallback_RequestUpdateForeground pCallback,  FS_LPVOID pUserData))

INTERFACE(void, FPD3deCanvasRequestUpdateBackground, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deCanvasRequestUpdateForeground, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deCanvasGetControllerTool, (FPD_3deCanvas canvas,  FPD_3deCanvas_ControllerTool* tool))

INTERFACE(void, FPD3deCanvasResetViewRotation, (FPD_3deCanvas canvas,  FS_INT32 nRotationCWCount,  FS_BOOLEAN bImmediatelyApply))

INTERFACE(FPD_H3DE_AssetNode, FPD3deCanvasGetCameraNode, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deCanvasSetCameraNode, (FPD_3deCanvas canvas,  FPD_H3DE_AssetNode hNode))

NumOfSelector(FPD3deCanvas)
ENDENUM

//*****************************
/* 3deView HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3deAsset, FPD3deViewGetAsset, (FPD_3deView view))

INTERFACE(void, FPD3deViewGetName, (FPD_3deView view,  FS_WideString *wsName))

INTERFACE(void, FPD3deViewGetDisplayName, (FPD_3deView view,  FS_WideString *wsDisplayName))

INTERFACE(FS3DE_Coordinate*, FPD3deViewGetCenterOfOrbit, (FPD_3deView view))

INTERFACE(FPD_3deViewProjection, FPD3deViewGetProjection, (FPD_3deView view))

INTERFACE(FPD_3deViewBackground, FPD3deViewGetBackground, (FPD_3deView view))

INTERFACE(FPD_3deViewRenderMode, FPD3deViewGetRenderMode, (FPD_3deView view))

INTERFACE(FPD_3deViewLightingScheme, FPD3deViewGetLightingScheme, (FPD_3deView view))

INTERFACE(void, FPD3deViewSetCameraToWorldMatrixWithNode, (FPD_3deView view,  FS_LPVOID pNodePathData))

INTERFACE(void, FPD3deViewSetCenterOfOrbit, (FPD_3deView view,  FS3DE_Coordinate fDist))

INTERFACE(void, FPD3deViewSetProjection, (FPD_3deView view,  FPD_3deViewProjection pProjection))

INTERFACE(void, FPD3deViewSetBackground, (FPD_3deView view,  FPD_3deViewBackground bgBackground))

INTERFACE(void, FPD3deViewSetRenderMode, (FPD_3deView view,  FPD_3deViewRenderMode rmRenderMode))

INTERFACE(void, FPD3deViewSetLightingScheme, (FPD_3deView view,  FPD_3deViewLightingScheme lsLightingScheme))

INTERFACE(void, FPD3deViewImportViewConfig, (FPD_3deView view,  FPD_3deView source,  FS3DE_ViewConfigSet options))

INTERFACE(void, FPD3deViewSetNameAndDisplayName, (FPD_3deView view,  FS_LPCWSTR wsName,  FS_LPCWSTR wsDisplayName))

INTERFACE(void, FPD3deViewSetCrossSections, (FPD_3deView view,  FS_PtrArray fsViewCrossSectionArray))

INTERFACE(void, FPD3deViewClearViewConfig, (FPD_3deView view,  FS3DE_ViewConfigSet cfgConfigSet))

INTERFACE(FS_BOOL, FPD3deViewGetCrossSections, (FPD_3deView view,  FS_PtrArray *fsViewCrossSectionArray))

INTERFACE(void, FPD3deViewClearAndImportViewConfig, (FPD_3deView view,  FPD_3deView pSrcView,  FS3DE_ViewConfigSet cfgConfigSet))

INTERFACE(FS_BOOL, FPD3deViewGetMeasurements, (FPD_3deView view,  FS_PtrArray *fsViewMeasurementsArray))

INTERFACE(void, FPD3deViewSetMeasurements, (FPD_3deView view,  FS_PtrArray vecMeasurements))

INTERFACE(void, FPD3deViewSetTrackingView, (FPD_3deView view,  FPD_3deView pTrackingView))

INTERFACE(FPD_Object, FPD3deViewF3DViewGetDict, (FPD_3deView view))

INTERFACE(FPD_3deViewCameraParam, FPD3deViewGetCameraParam, (FPD_3deView view))

NumOfSelector(FPD3deView)
ENDENUM

//*****************************
/* 3deViewRenderMode HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FPD3deViewRenderModeSwitchKind, (FPD_3deViewRenderMode viewRender,  FS3DE_RenderModeType eType))

INTERFACE(FPD_3deViewRenderMode, FPD3deViewRenderModeCreate, (FS3DE_RenderModeType eType,  FS_COLORREF fActiveColor,  FS_BOOL bFaceColorUseBG,  FS_COLORREF fFaceColor,  FS_FLOAT fOpacity,  FS_FLOAT fCreaseValueAngle))

INTERFACE(void, FPD3deViewRenderModeRelease, (FPD_3deViewRenderMode renderMode))

INTERFACE(FS3DE_RenderModeType, FPD3deViewRenderModeQueryModeType, (FPD_3deViewRenderMode renderMode))

NumOfSelector(FPD3deViewRenderMode)
ENDENUM

//*****************************
/* 3deViewLightingScheme HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3deViewLightingScheme, FPD3deViewLightingSchemeCreate, (FS_BOOL bConfigured,  FS3DE_LightingSchemeType eTypeTag))

INTERFACE(void, FPD3deViewLightingSchemeDestroy, (FPD_3deViewLightingScheme scheme))

INTERFACE(FS3DE_LightingSchemeType, FPD3deViewLightingSchemeQuerySchemeType, (FPD_3deCanvas pCanvas))

INTERFACE(void, FPD3deViewLightingSchemeSwitchSchemeType, (FPD_3deCanvas pCanvas,  FS3DE_LightingSchemeType eType))

INTERFACE(FS_BOOL, FPD3deViewLightingSchemeQueryArtworkSchemeExist, (FPD_3deCanvas pCanvas))

NumOfSelector(FPD3deViewLightingScheme)
ENDENUM

//*****************************
/* 3deCanvasControllerTool HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3deCanvas_ControllerTool, FPD3deCanvasControllerToolGetRotateTool, ())

INTERFACE(FPD_3deCanvas_ControllerTool, FPD3deCanvasControllerToolGetSpinTool, ())

INTERFACE(FPD_3deCanvas_ControllerTool, FPD3deCanvasControllerToolGetPanTool, ())

INTERFACE(FPD_3deCanvas_ControllerTool, FPD3deCanvasControllerToolGetZoomTool, ())

INTERFACE(FPD_3deCanvas_ControllerTool, FPD3deCanvasControllerToolGetWalkTool, ())

INTERFACE(FPD_3deCanvas_ControllerTool, FPD3deCanvasControllerToolGetFlyTool, ())

INTERFACE(FPD_3deCanvas_ControllerTool, FPD3deCanvasControllerToolGetSimpleControllerTool, (FS3DE_BuiltinSimpleControllerTool eToolType))

INTERFACE(FPD_3deCanvas_ControllerTool, FPD3deCanvasControllerToolCreateCommentControllerTool, ())

INTERFACE(void, FPD3deCanvasControllerToolReleaseCommentControllerTool, (FPD_3deCanvas_ControllerTool tool))

INTERFACE(FPD_3deCanvas_ControllerTool, FPD3deCanvasControllerToolCreateMeasureControllerTool, (FS3DE_MeasureType eMeasureType))

INTERFACE(void, FPD3deCanvasControllerToolReleaseMeasureControllerTool, (FPD_3deCanvas_ControllerTool tool))

INTERFACE(void, FPD3deCanvasControllerToolSetMeasureControllerTooMeasureType, (FPD_3deCanvas_ControllerTool tool,  FPD_3deCanvas canvas,  FS3DE_MeasureType eMeasureType))

INTERFACE(void, FPD3deCanvasControllerToolSetMeasureScale, (FPD_3deCanvas_ControllerTool tool,  FPD_3deCanvas canvas,  FS_FLOAT fM,  FS_FLOAT fN,  const FS_WideString wsUnit))

INTERFACE(FPD_3deCanvas_ControllerTool, FPD3deCanvasControllerToolCreate3deCanvasControllerTool, ())

INTERFACE(void, FPD3deCanvasControllerToolDestroy, (FPD_3deCanvas_ControllerTool tool))

INTERFACE(void, FPD3deCanvasControllerToolSetTag, (FPD_3deCanvas_ControllerTool tool,  FS_DWORD tag))

INTERFACE(FS_DWORD, FPD3deCanvasControllerToolGetTag, (FPD_3deCanvas_ControllerTool tool))

INTERFACE(void, FPD3deCanvasControllerToolSetUserData, (FPD_3deCanvas_ControllerTool tool,  FS_LPVOID userData))

INTERFACE(FS_LPVOID, FPD3deCanvasControllerToolGetUserData, (FPD_3deCanvas_ControllerTool tool))

INTERFACE(void, FPD3deCanvasControllerToolSetMeasureSnapType, (FPD_3deCanvas_ControllerTool tool,  FPD_3deCanvas pCanvas,  FS3DE_MeasureSnapType eSnapType))

INTERFACE(void, FPD3deCanvasControllerToolSetCursorChangeHook, (FPD3D_CursorChangeHookFn pHookFn,  FS_LPVOID pUserData))

NumOfSelector(FPD3deCanvasControllerTool)
ENDENUM

//*****************************
/* 3dVendor HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3dVendorHandler, FPD3dVendorCreateHandler, (FPD_3dVendor_TempFileCallback pTempFileCallback))

INTERFACE(void, FPD3dVendorReleaseHandler, (FPD_3dVendorHandler pHandler))

INTERFACE(void, FPD3dVendorSetPDFModuleMgrIfNecessary, (void *pModuleMgr))

INTERFACE(void, FPD3dVendorSetTempFileCallback, (FPD_3dVendorHandler pHandler))

INTERFACE(FPD_3deAsset, FPD3dVendorU3DLoader, (FPD_Object pStream,  FPD_3DArtworkFormat eFormat,  FPD_3deRuntime p3DEngine))

INTERFACE(FPD_3deAsset, FPD3dVendorPRCLoader, (FPD_Object pStream,  FPD_3DArtworkFormat eFormat,  FPD_3deRuntime p3DEngine))

INTERFACE(void, FPD3dVendorGetNodeMetadataStorageKey, (FS_ByteString *bsStorageKey))

INTERFACE(FS_FileStream, FPD3dVendorModelLoader, (FPD_Object pStream,  FPD_3DArtworkFormat eFormat,  FPD_3DArtworkFormat* actualFormat))

INTERFACE(FS_FileStream, FPD3dVendorDorPRCLoader, (FPD_Object pStream,  FPD_3DArtworkFormat eFormat,  FPD_3DArtworkFormat* actualFormat))

INTERFACE(void, FPD3dVendorGetNodeNameStorageKey, (FS_ByteString *bsStorageKey))

INTERFACE(void, FPD3dVendorSetTempFileGenerationRule, (FPD3D_Vendor_TempFileGeneration eGeneration))

NumOfSelector(FPD3dVendor)
ENDENUM

//*****************************
/* 3deViewBackground HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3deViewBackground, FPD3deViewBackgroundCreate, (FS_COLORREF fBkgColor,  FS_BOOL bEntireAnnotation))

INTERFACE(void, FPD3deViewBackgroundRelease, (FPD_3deViewBackground viewBkg))

INTERFACE(void, FPD3deViewBackgroundSetBackgroundColor, (FPD_3deViewBackground viewBkg,  FS_COLORREF fBackgroundColor))

INTERFACE(FS_COLORREF, FPD3deViewBackgroundQueryBackgroundColor, (FPD_3deViewBackground viewBkg))

INTERFACE(FS_COLORREF, FPD3deViewBackgroundDefaultBackgroundColor, ())

INTERFACE(FS_BOOL, FPD3deViewBackgroundQueryEntireAnnotation, (FPD_3deViewBackground viewBkg))

NumOfSelector(FPD3deViewBackground)
ENDENUM

//*****************************
/* 3deViewCameraParam HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS3DE_ViewProjectionMode, FPD3deViewCameraParamQueryProjectionMode, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deViewCameraParamSwitchProjectionMode, (FPD_3deCanvas canvas,  FS3DE_ViewProjectionMode eProjectionMode))

INTERFACE(void, FPD3deViewCameraParamImportCameraConfig1, (FPD_3deCanvas canvas,  FS3DE_CameraConfig1 cfgCameraConfig))

INTERFACE(void, FPD3deViewCameraParamImportCameraConfig2, (FPD_3deCanvas canvas,  FS3DE_CameraConfig2 cfgCameraConfig))

INTERFACE(void, FPD3deViewCameraParamExportCameraConfig, (FPD_3deCanvas canvas,  FS3DE_CameraConfig1* pConfig1,  FS3DE_CameraConfig2* pConfig2))

INTERFACE(void, FPD3deViewCameraParamFitToVisible, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deViewCameraParamZoomToPart, (FPD_3deCanvas canvas,  FPD_H3DE_AssetNode hAssetNode))

INTERFACE(void, FPD3deViewCameraParamIsolateNode, (FPD_3deCanvas canvas,  FPD_H3DE_AssetNode hAssetNode))

INTERFACE(void, FPD3deViewCameraParamIsolateParentNode, (FPD_3deCanvas canvas,  FPD_H3DE_AssetNode hAssetNode))

INTERFACE(FS_BOOL, FPD3deViewCameraParamGet3DMatrix, (FPD_3deViewCameraParam param,  FS3DE_3DMatrix* matrix))

INTERFACE(FS_BOOL, FPD3deViewCameraParamGetbUseU3DPath, (FPD_3deViewCameraParam param))

INTERFACE(void, FPD3deViewCameraParamGetU3DPath, (FPD_3deViewCameraParam param,  FS_WideString* path))

INTERFACE(FS3DE_Coordinate, FPD3deViewCameraParamGetCenterOfOrbit, (FPD_3deViewCameraParam param))

INTERFACE(FS_FLOAT, FPD3deViewCameraParamGetProjectFOS, (FPD_3deViewCameraParam param))

NumOfSelector(FPD3deViewCameraParam)
ENDENUM

//*****************************
/* 3deViewCrossSection HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOL, FPD3deViewCrossSectionToggleCrossSection, (FPD_3deCanvas canvas))

INTERFACE(void, FPD3deViewCrossSectionImportCrossSectionConfig1, (FPD_3deCanvas canvas,  PFS3DE_CrossSectionConfig1 sectionConfig))

INTERFACE(void, FPD3deViewCrossSectionExportCrossSectionConfig1, (FPD_3deCanvas canvas,  FS3DE_CrossSectionConfig1 *outSectionConfig))

INTERFACE(void, FPD3deViewCrossSectionGetCenterPos, (FPD_3deViewCrossSection section,  FS3DE_Vector *pCenterPos))

INTERFACE(void, FPD3deViewCrossSectionSetCenterPos, (FPD_3deViewCrossSection section,  FS3DE_Vector CenterPos))

INTERFACE(FS_BOOL, FPD3deViewCrossSectionGetOrientation, (FPD_3deViewCrossSection section,  FS3DE_Vector *pvOrientationAngles,  FSInitialAxis *eInitialAxis))

INTERFACE(void, FPD3deViewCrossSectionSetOrientation, (FPD_3deViewCrossSection section,  FS3DE_Vector vOrientationAngles,  FSInitialAxis eInitialAxis))

INTERFACE(void, FPD3deViewCrossSectionGetPlane, (FPD_3deViewCrossSection section,  FS_BOOL *pbVisible,  FS_COLORREF *pcColor,  FS_FLOAT *pfOpacity))

INTERFACE(void, FPD3deViewCrossSectionSetPlane, (FPD_3deViewCrossSection section,  FS_BOOL bVisible,  FS_COLORREF cColor,  FS_FLOAT fOpacity))

INTERFACE(void, FPD3deViewCrossSectionGetIntersection, (FPD_3deViewCrossSection section,  FS_BOOL* pbVisible,  FS_COLORREF *pcColor))

INTERFACE(void, FPD3deViewCrossSectionSetIntersection, (FPD_3deViewCrossSection section,  FS_BOOL bVisible,  FS_COLORREF cColor))

INTERFACE(FS_BOOL, FPD3deViewCrossSectionGetShowTransparent, (FPD_3deViewCrossSection section))

INTERFACE(void, FPD3deViewCrossSectionSetShowTransparent, (FPD_3deViewCrossSection section,  FS_BOOL ShowTransparent))

INTERFACE(FS_BOOL, FPD3deViewCrossSectionGetSectionCapping, (FPD_3deViewCrossSection section))

INTERFACE(void, FPD3deViewCrossSectionSetSectionCapping, (FPD_3deViewCrossSection section,  FS_BOOL SectionCapping))

INTERFACE(FS_BOOL, FPD3deViewCrossSectionGetIgnoreChosenNode, (FPD_3deViewCrossSection section))

INTERFACE(void, FPD3deViewCrossSectionSetIgnoreChosenNode, (FPD_3deViewCrossSection section,  FS_BOOL IgnoreChosenNode))

INTERFACE(void, FPD3deViewCrossSectionImportCrossSectionConfig2, (FPD_3deCanvas canvas,  PFS3DE_CrossSectionConfig2 sectionConfig))

INTERFACE(void, FPD3deViewCrossSectionExportCrossSectionConfig2, (FPD_3deCanvas canvas,  FS3DE_CrossSectionConfig2 *outSectionConfig))

INTERFACE(FS_BOOLEAN, FPD3deViewCrossSectionQueryCrossSectionExist, (FPD_3deCanvas canvas))

NumOfSelector(FPD3deViewCrossSection)
ENDENUM

//*****************************
/* 3deViewNode HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3deViewNode, FPD3deViewNodeStartModifyNode, (FPD_3deCanvas pCanvas,  FPD_H3DE_AssetNode hNode))

INTERFACE(void, FPD3deViewNodeFinishModifyNode, (FPD_3deCanvas pCanvas,  FPD_3deViewNode pViewNode))

INTERFACE(FPD_3deViewNode, FPD3deViewNodeStartQueryNode, (FPD_3deCanvas pCanvas,  FPD_H3DE_AssetNode hNode))

INTERFACE(void, FPD3deViewNodeFinishQueryNode, (FPD_3deCanvas pCanvas,  FPD_3deViewNode pViewNode))

INTERFACE(void, FPD3deViewNodeGetName, (FPD_3deViewNode pViewNode,  FS_WideString *wsName))

INTERFACE(void, FPD3deViewNodeSetName, (FPD_3deViewNode pViewNode,  FS_WideString wsName))

INTERFACE(FS_BOOLEAN*, FPD3deViewNodeGetVisibility, (FPD_3deViewNode pViewNode))

INTERFACE(void, FPD3deViewNodeSetVisibility, (FPD_3deViewNode pViewNode,  FS_BOOL bVisible))

INTERFACE(FS_FLOAT*, FPD3deViewNodeGetOpacity, (FPD_3deViewNode pViewNode))

INTERFACE(void, FPD3deViewNodeSetOpacity, (FPD_3deViewNode pViewNode,  FS_FLOAT fOpacity))

INTERFACE(FS_BOOL, FPD3deViewNodeGetMatrix, (FPD_3deViewNode pViewNode,  FS3DE_3DMatrix* matrix))

INTERFACE(void, FPD3deViewNodeSetMatrix, (FPD_3deViewNode pViewNode,  FS3DE_3DMatrix mMatrix))

INTERFACE(FPD_3deViewRenderMode, FPD3deViewNodeGetRenderMode, (FPD_3deViewNode pViewNode))

INTERFACE(void, FPD3deViewNodeSetRenderMode, (FPD_3deViewNode pViewNode,  FPD_3deViewRenderMode rmRenderMode))

INTERFACE(FS_BOOLEAN, FPD3deViewNodeQueryNodeVisibility, (FPD_3deCanvas pCanvas,  FPD_H3DE_AssetNode hNode))

NumOfSelector(FPD3deViewNode)
ENDENUM

//*****************************
/* 3deMeasure HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS3DE_MeasureType, FPD3deMeasureGetType, (FPD_3deMeasure measure))

INTERFACE(FPD_3deView, FPD3deMeasureGetView, (FPD_3deMeasure measure))

INTERFACE(FS_BOOL, FPD3deMeasureGetName, (FPD_3deMeasure measure,  FS_WideString* outName))

INTERFACE(FS_BOOL, FPD3deMeasureGetPlane, (FPD_3deMeasure measure,  FS3DE_Vector* vec3d))

INTERFACE(FS_BOOL, FPD3deMeasureGetAnchorPoints, (FPD_3deMeasure measure,  FS_PtrArray vecAnchorPoints))

INTERFACE(void, FPD3deMeasureReleaseFS3DeVectorArray, (FS_PtrArray vecArray))

INTERFACE(FS_BOOL, FPD3deMeasureGetAnchorNames, (FPD_3deMeasure measure,  FS_WideStringArray vecAnchorNames))

INTERFACE(FS_BOOL, FPD3deMeasureGetExtraAnchorPoints, (FPD_3deMeasure measure,  FS_PtrArray vecAnchorPoints))

INTERFACE(FS_BOOL, FPD3deMeasureGetDirVectors, (FPD_3deMeasure measure,  FS_PtrArray vecDirVectors))

INTERFACE(FS_BOOL, FPD3deMeasureGetTextPos, (FPD_3deMeasure measure,  PFS3DE_Vector p3devec))

INTERFACE(FS_BOOL, FPD3deMeasureGetTextXDir, (FPD_3deMeasure measure,  PFS3DE_Vector p3devec))

INTERFACE(FS_BOOL, FPD3deMeasureGetTextYDir, (FPD_3deMeasure measure,  PFS3DE_Vector p3devec))

INTERFACE(FS_BOOL, FPD3deMeasureGetTextBoxSize, (FPD_3deMeasure measure,  FS_FLOAT& x,  FS_FLOAT& y))

INTERFACE(FS_BOOL, FPD3deMeasureGetExtensionLineLength, (FPD_3deMeasure measure,  FS_FLOAT& length))

INTERFACE(FS_BOOL, FPD3deMeasureGetTextSize, (FPD_3deMeasure measure,  FS_FLOAT& size))

INTERFACE(FS_BOOL, FPD3deMeasureGetColor, (FPD_3deMeasure measure,  FS3DE_RGBColor* color))

INTERFACE(FS_FLOAT, FPD3deMeasureGetValue, (FPD_3deMeasure measure))

INTERFACE(FS_WideString, FPD3deMeasureGetUnits, (FPD_3deMeasure measure))

INTERFACE(FS_UINT, FPD3deMeasureGetPrecision, (FPD_3deMeasure measure))

INTERFACE(FS_WideString, FPD3deMeasureGetUserText, (FPD_3deMeasure measure))

INTERFACE(FS_BOOL, FPD3deMeasureGetAngleType, (FPD_3deMeasure measure,  FS3DE_MeasureAngleType& angleType))

INTERFACE(FS_BOOL, FPD3deMeasureGetShowCircle, (FPD_3deMeasure measure))

INTERFACE(FS_BOOL, FPD3deMeasureGetRadialType, (FPD_3deMeasure measure,  FS3DE_MeasureRadialType& radicalType))

INTERFACE(FS_BOOL, FPD3deMeasureSetName, (FPD_3deMeasure measure,  FS_LPCWSTR lpwsStr))

INTERFACE(void, FPD3deMeasureSetTextPos, (FPD_3deMeasure measure,  FS3DE_Vector vNewPos))

INTERFACE(void, FPD3deMeasureSetAnchorPointsAndNames, (FPD_3deMeasure measure,  const FS_PtrArray vecAnchorPoints,  const FS_WideStringArray vecAnchorNames))

INTERFACE(void, FPD3deMeasureSetPlane, (FPD_3deMeasure measure,  const FS3DE_Vector vPlaneNoraml))

INTERFACE(void, FPD3deMeasureSetTextXDir, (FPD_3deMeasure measure,  const FS3DE_Vector vTXDir))

INTERFACE(void, FPD3deMeasureSetTextYDir, (FPD_3deMeasure measure,  const FS3DE_Vector vTYDir))

INTERFACE(void, FPD3deMeasureSetValue, (FPD_3deMeasure measure,  FS_FLOAT fValue))

INTERFACE(void, FPD3deMeasureSetColor, (FPD_3deMeasure measure,  const FS3DE_RGBColor cColor))

INTERFACE(void, FPD3deMeasureSetAngularShowArc, (FPD_3deMeasure measure,  FS_BOOL bShow))

INTERFACE(void, FPD3deMeasureSetDirVectors, (FPD_3deMeasure measure,  const FS_PtrArray vecDirVectors))

INTERFACE(void, FPD3deMeasureSetUserText, (FPD_3deMeasure measure,  const FS_WideString wsUT))

INTERFACE(void, FPD3deMeasureSetShow, (FPD_3deMeasure measure,  FS_BOOL bShow))

INTERFACE(void, FPD3deMeasureSetTextBoxSize, (FPD_3deMeasure measure,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(void, FPD3deMeasureSetUnits, (FPD_3deMeasure measure,  const FS_WideString wsUnits))

INTERFACE(FPD_3deMeasure, FPD3deMeasureControllerGetCurrentMeasure, (FPD_3deCanvas_ControllerTool pTool,  FPD_3deCanvas canvas))

INTERFACE(FS3DE_USIZE, FPD3deMeasureGetCurrentCollectedPointCount, (FPD_3deCanvas_ControllerTool pTool,  FPD_3deCanvas canvas))

INTERFACE(void, FPD3deMeasureSetMeasureValueChangeCallback, (FPD_MeasureValueChangeCallback pCallback,  FS_LPVOID pUserData))

INTERFACE(FPD_Object, FPD3deMeasureMeasure_GetDict, (FPD_3deMeasure measure))

NumOfSelector(FPD3deMeasure)
ENDENUM

//*****************************
/* 3deViewMiscOptions HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FPD3deViewMiscOptionsSetHighlightColor, (FPD_3deViewMiscOptions options,  FPD_3deCanvas pCanvas,  FS3DE_RGBColor cColor))

INTERFACE(void, FPD3deViewMiscOptionsSetBoundingBoxVisible, (FPD_3deViewMiscOptions options,  FPD_3deCanvas pCanvas,  FS_BOOL bVisible))

INTERFACE(void, FPD3deViewMiscOptionsSetBoundingBoxColor, (FPD_3deViewMiscOptions options,  FPD_3deCanvas pCanvas,  FS3DE_RGBColor cColor))

INTERFACE(void, FPD3deViewMiscOptionsSetShowGrid, (FPD_3deViewMiscOptions options,  FPD_3deCanvas pCanvas,  FS_BOOL bShow))

INTERFACE(FS_BOOL, FPD3deViewMiscOptionsGetShowGrid, (FPD_3deViewMiscOptions options,  FPD_3deCanvas pCanvas))

INTERFACE(void, FPD3deViewMiscOptionsSetGridMode, (FPD_3deViewMiscOptions options,  FPD_3deCanvas pCanvas,  FS3DE_GridMode eGridMode))

INTERFACE(FS_BOOL, FPD3deViewMiscOptionsGetGridMode, (FPD_3deViewMiscOptions options,  FPD_3deCanvas pCanvas,  FS3DE_GridMode& eGridMode))

INTERFACE(void, FPD3deViewMiscOptionsSetGridSize, (FPD_3deViewMiscOptions options,  FPD_3deCanvas pCanvas,  FS_INT32 nGridSize))

INTERFACE(FS_BOOL, FPD3deViewMiscOptionsGetGridSize, (FPD_3deViewMiscOptions options,  FPD_3deCanvas pCanvas,  FS_INT32& nGridSize))

NumOfSelector(FPD3deViewMiscOptions)
ENDENUM

//*****************************
/* 3deTextProvider HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3deTextProvider, FPD3deTextProviderCreate, ())

INTERFACE(void, FPD3deTextProviderRelease, (FPD_3deTextProvider pProvider))

INTERFACE(void, FPD3deTextProviderSetTextScalingRatio, (FPD_3deTextProvider pProvider,  FS_FLOAT fTextScalingRatio,  FS3DE_TextScalingKind scaleKind))

INTERFACE(void, FPD3deTextProviderSetSystemHandler, (FPD_3deTextProvider pProvider,  FPD_SystemHandler pSystemHandler,  FS_BOOLEAN bHold))

NumOfSelector(FPD3deTextProvider)
ENDENUM

//*****************************
/* ScriptHostHostProvider HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_Script3DHostProvider, FPDScriptHostHostProviderNew, (FPD_ScriptHostProviderCallbacks callbacks))

INTERFACE(void, FPDScriptHostHostProviderDestroy, (FPD_Script3DHostProvider provider))

NumOfSelector(FPDScriptHostHostProvider)
ENDENUM

//*****************************
/* Script3DEngine HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_Script3D_Engine, FPDScript3DEngineNew, (FSJSE_HRUNTIME hRuntime))

INTERFACE(void, FPDScript3DEngineDestroy, (FPD_Script3D_Engine engine))

INTERFACE(FSJSE_HCONTEXT, FPDScript3DEngineGet3DScriptContext, (FPD_Script3D_Engine engine,  FPDRM_3DInstance pInstance))

INTERFACE(void, FPDScript3DEngineRegisterHostProvider, (FPD_Script3D_Engine engine,  FPD_Script3DHostProvider pHostProvider))

INTERFACE(FPD_3DScriptProvider, FPDScript3DEngineGet3DScriptProvider, (FPD_Script3D_Engine engine))

NumOfSelector(FPDScript3DEngine)
ENDENUM

//*****************************
/* 3DI18NProviderHandler HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3DEI18nProvider, FPD3DI18NProviderHandlerNew, (FPD_I18nProviderCallbacks callbacks))

INTERFACE(void, FPD3DI18NProviderHandlerDestroy, (FPD_3DEI18nProvider provider))

NumOfSelector(FPD3DI18NProviderHandler)
ENDENUM

//----------_V13----------
//----------_V14----------
//*****************************
/* 3DCompositionProvider HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3DCompositionProvider, FPD3DCompositionProviderNew, (FPD_3DCompositionProviderCallbacks callbacks))

INTERFACE(void, FPD3DCompositionProviderDestroy, (FPD_3DCompositionProvider provider))

NumOfSelector(FPD3DCompositionProvider)
ENDENUM

//*****************************
/* BoundingBox HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS3DE_BoundingBox, FPDBoundingBoxCreateBox, (FS_FLOAT MinX,  FS_FLOAT MinY,  FS_FLOAT MinZ,  FS_FLOAT MaxX,  FS_FLOAT MaxY,  FS_FLOAT MaxZ))

INTERFACE(void, FPDBoundingBoxDeleteBox, (FS3DE_BoundingBox boundingBox))

INTERFACE(FS_FLOAT, FPDBoundingBoxGetSqr, (FS3DE_BoundingBox boundingBox))

INTERFACE(FS3DE_Vector, FPDBoundingBoxGetCenter, (FS3DE_BoundingBox boundingBox))

INTERFACE(FS3DE_Vector, FPDBoundingBoxGetSize, (FS3DE_BoundingBox boundingBox))

INTERFACE(void, FPDBoundingBoxGetMaxValues, (FS3DE_BoundingBox boundingBox,  FS_FloatArray* maxArray))

INTERFACE(void, FPDBoundingBoxGetMinValues, (FS3DE_BoundingBox boundingBox,  FS_FloatArray* minArray))

NumOfSelector(FPDBoundingBox)
ENDENUM

//----------_V15----------
//*****************************
/* 3DFRMConfiguration HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FPD3DFRMConfigurationGetName, (FPDRM_Configuration configuration,  FS_WideString* wsName))

INTERFACE(void, FPD3DFRMConfigurationGetContentType, (FPDRM_Configuration configuration,  FPDRM_ContentType* eContentType))

INTERFACE(void, FPD3DFRMConfigurationGetInstances, (FPDRM_Configuration configuration,  FS_PtrArray pInstancesArray))

NumOfSelector(FPD3DFRMConfiguration)
ENDENUM

//*****************************
/* 3DFRMInstance HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPDRM_3DInstance, FPD3DFRMInstanceAs3DInstance, (FPDRM_Instance instance))

INTERFACE(FPD_3dContext, FPD3DFRMInstanceGetContext, (FPDRM_Instance instance))

INTERFACE(FPD_3dAnnotData, FPD3DFRMInstanceGetAnnotData, (FPDRM_Instance instance))

INTERFACE(void, FPD3DFRMInstanceGetContentType, (FPDRM_Instance instance,  FPDRM_ContentType* eContentType))

INTERFACE(FPD_Object, FPD3DFRMInstanceGetAssetFileSpec, (FPDRM_Instance instance))

NumOfSelector(FPD3DFRMInstance)
ENDENUM

//*****************************
/* 3DInstance HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_ProgressiveStatus, FPD3DInstancePrepareActivate, (FPDRM_3DInstance pInstance,  FS_PauseHandler pPause))

INTERFACE(FPD_3deCanvas, FPD3DInstanceAllocAndActivateCanvasToplevel, (FPDRM_3DInstance pInstance,  FS3DE_ActivationState eNewState))

INTERFACE(FPD_3deCanvas, FPD3DInstanceAllocAndActivateCanvasEmbedded, (FPDRM_3DInstance pInstance,  FS3DE_ActivationState eNewState,  FS3DE_CANVAS_NATIVE_HANDLE pParentNativeWindow))

INTERFACE(FS_BOOL, FPD3DInstanceActivate, (FPDRM_3DInstance pInstance,  FS3DE_ActivationState eNewState))

INTERFACE(FPD_3deCanvas, FPD3DInstanceAllocCanvasToplevel, (FPDRM_3DInstance pInstance))

INTERFACE(FPD_3deCanvas, FPD3DInstanceAllocCanvasEmbedded, (FPDRM_3DInstance pInstance,  FS3DE_CANVAS_NATIVE_HANDLE pParentNativeWindow))

INTERFACE(void, FPD3DInstanceReleaseCanvas, (FPDRM_3DInstance pInstance,  FPD_3deCanvas pCanvas))

INTERFACE(void, FPD3DInstanceDeactivate, (FPDRM_3DInstance pInstance,  FS3DE_ActivationState eNewState))

INTERFACE(FPD_3dScene, FPD3DInstanceGetScene, (FPDRM_3DInstance pInstance))

INTERFACE(FPD_3deAsset, FPD3DInstanceGetAsset, (FPDRM_3DInstance pInstance))

INTERFACE(FPD_3deCanvas_ControllerTool, FPD3DInstanceGetTool, (FPDRM_3DInstance pInstance,  FS3DE_ControllerToolTag eTag))

INTERFACE(FPD_3deView, FPD3DInstanceGetDefaultPresetView, (FPDRM_3DInstance pInstance))

INTERFACE(void, FPD3DInstanceExecuteCustomMenuItem, (FPDRM_3DInstance pInstance,  FS3DE_USIZE uIndex,  FPD_3deCanvas pCanvas))

INTERFACE(FS_BOOL, FPD3DInstanceGetCustomMenuItemByIndex, (FPDRM_3DInstance pInstance,  FPD_3dCustomMenuItemData mdMenuData,  FS3DE_USIZE uIndex))

INTERFACE(FS_BOOL, FPD3DInstanceFindCustomMenuItemIndexByName, (FPDRM_3DInstance pInstance,  FS3DE_USIZE* uIndex,  FS_WideString wsMenuItemName))

INTERFACE(FS3DE_USIZE, FPD3DInstanceCountCustomMenuItems, (FPDRM_3DInstance pInstance))

INTERFACE(FS_BOOLEAN, FPD3DInstanceGetCustomToolButtonDataByIndex, (FPDRM_3DInstance pInstance,  FPD_3dCustomToolButtonData* ctdToolData,  FS3DE_USIZE uIndex))

INTERFACE(FS_BOOLEAN, FPD3DInstanceFindCustomToolButtonIndexByName, (FPDRM_3DInstance pInstance,  FS3DE_USIZE* uIndex,  const FS_LPCWSTR wsCustomToolButtonName))

INTERFACE(FS_BOOLEAN, FPD3DInstanceSetCustomToolButtonVisible, (FPDRM_3DInstance pInstance,  FS3DE_USIZE uIndex,  FS_BOOLEAN bVisible))

INTERFACE(FS_BOOLEAN, FPD3DInstanceSetCustomToolButtonEnabled, (FPDRM_3DInstance pInstance,  FS3DE_USIZE uIndex,  FS_BOOLEAN bEnabled))

INTERFACE(FS3DE_USIZE, FPD3DInstanceCountCustomTools, (FPDRM_3DInstance pInstance))

NumOfSelector(FPD3DInstance)
ENDENUM

//*****************************
/* 3dAnnotDataRichMedia HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FPD3dAnnotDataRichMediaRetrieve3DPresetViewList, (FPD_3dAnnotData_RichMedia richMedia,  FS_PtrArray p3deViewArray))

INTERFACE(void, FPD3dAnnotDataRichMediaUpdate3DPresetViewList, (FPD_3dAnnotData_RichMedia richMedia,  FS_PtrArray p3deViewArray))

INTERFACE(FPD_3deView, FPD3dAnnotDataRichMediaCreate3DPresetView, (FPD_3dAnnotData_RichMedia richMedia,  FS_LPCWSTR lpwsDisplayName))

INTERFACE(FPD_3deView, FPD3dAnnotDataRichMediaFind3DPresetView, (FPD_3dAnnotData_RichMedia richMedia,  FPD_Object pViewDict,  FS_BOOL bImportIfNotLoaded))

INTERFACE(FPD_3deView, FPD3dAnnotDataRichMediaGetArtworkDefault3DPresetView, (FPD_3dAnnotData_RichMedia richMedia))

INTERFACE(FS_BOOL, FPD3dAnnotDataRichMediaLoadSettingsOptions, (FPD_3dAnnotData_RichMedia richMedia,  FPD_3dContext pContext,  FPD_Object pAnnotDict,  FPD_RMActivation optActivationOptions,  FPD_RMDeactivation optDeactivationOptions))

INTERFACE(void, FPD3dAnnotDataRichMediaGetActivationOptions, (FPD_3dAnnotData_RichMedia richMedia,  FPD_RMActivation outActivation))

INTERFACE(void, FPD3dAnnotDataRichMediaGetDeactivationOptions, (FPD_3dAnnotData_RichMedia richMedia,  FPD_RMDeactivation outDeactivation))

INTERFACE(FPDRM_Configuration, FPD3dAnnotDataRichMediaGetActivationConfiguration, (FPD_3dAnnotData_RichMedia richMedia))

INTERFACE(FPD_3deView, FPD3dAnnotDataRichMediaGetActivationPresetView, (FPD_3dAnnotData_RichMedia richMedia))

INTERFACE(FPD_Object, FPD3dAnnotDataRichMediaGetAnnotDict, (FPD_3dAnnotData_RichMedia richMedia))

INTERFACE(FPD_Object, FPD3dAnnotDataRichMediaGetPageDict, (FPD_3dAnnotData_RichMedia richMedia))

NumOfSelector(FPD3dAnnotDataRichMedia)
ENDENUM

//*****************************
/* 3deAnimationStyle HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3deAnimationStyle, FPD3deAnimationStyleNew, ())

INTERFACE(void, FPD3deAnimationStyleDestory, (FPD_3deAnimationStyle st3deAnimationStyle))

INTERFACE(FPD_3deAnimationStyle, FPD3deAnimationStyleNoAnimation, ())

INTERFACE(FPD_3deAnimationStyle, FPD3deAnimationStyleLinearAnimation, (FS_INT32 nPlayCount,  FS_FLOAT fTimeMultiplier))

INTERFACE(FPD_3deAnimationStyle, FPD3deAnimationStyleOscillatingAnimation, (FS_INT32 nPlayCount,  FS_FLOAT fTimeMultiplier))

INTERFACE(void, FPD3deAnimationStyleSetType, (FPD_3deAnimationStyle st3deAnimationStyle,  FS3DE_AnimationStyleType eType))

INTERFACE(FS3DE_AnimationStyleType, FPD3deAnimationStyleGetType, (FPD_3deAnimationStyle st3deAnimationStyle))

INTERFACE(void, FPD3deAnimationStyleSetPlayCount, (FPD_3deAnimationStyle st3deAnimationStyle,  FS_INT32 nPlayCount))

INTERFACE(FS_INT32, FPD3deAnimationStyleGetPlayCount, (FPD_3deAnimationStyle st3deAnimationStyle))

INTERFACE(void, FPD3deAnimationStyleSetTimeMultiplier, (FPD_3deAnimationStyle st3deAnimationStyle,  FS_FLOAT fTimeMultiplier))

INTERFACE(FS_FLOAT, FPD3deAnimationStyleGetTimeMultiplier, (FPD_3deAnimationStyle st3deAnimationStyle))

NumOfSelector(FPD3deAnimationStyle)
ENDENUM

//*****************************
/* 3DFRMWindowDimen HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_RMWindowDimen, FPD3DFRMWindowDimenNew, ())

INTERFACE(void, FPD3DFRMWindowDimenDestory, (FPD_RMWindowDimen stRMWindowDimen))

INTERFACE(void, FPD3DFRMWindowDimenSetDefault, (FPD_RMWindowDimen stRMWindowDimen,  FS_FLOAT fDefault))

INTERFACE(FS_FLOAT, FPD3DFRMWindowDimenGetDefault, (FPD_RMWindowDimen stRMWindowDimen))

INTERFACE(void, FPD3DFRMWindowDimenSetMax, (FPD_RMWindowDimen stRMWindowDimen,  FS_FLOAT fMax))

INTERFACE(FS_FLOAT, FPD3DFRMWindowDimenGetMax, (FPD_RMWindowDimen stRMWindowDimen))

INTERFACE(void, FPD3DFRMWindowDimenSetMin, (FPD_RMWindowDimen stRMWindowDimen,  FS_FLOAT fMin))

INTERFACE(FS_FLOAT, FPD3DFRMWindowDimenGetMin, (FPD_RMWindowDimen stRMWindowDimen))

NumOfSelector(FPD3DFRMWindowDimen)
ENDENUM

//*****************************
/* 3DFRMWindowPos HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_RMWindowPos, FPD3DFRMWindowPosNew, ())

INTERFACE(void, FPD3DFRMWindowPosDestory, (FPD_RMWindowPos stRMWindowPos))

INTERFACE(void, FPD3DFRMWindowPosSetHAlign, (FPD_RMWindowPos stRMWindowPos,  FPDRM_WindowAlign waHAlign))

INTERFACE(FPDRM_WindowAlign, FPD3DFRMWindowPosGetHAlign, (FPD_RMWindowPos stRMWindowPos))

INTERFACE(void, FPD3DFRMWindowPosSetVAlign, (FPD_RMWindowPos stRMWindowPos,  FPDRM_WindowAlign waVAlign))

INTERFACE(FPDRM_WindowAlign, FPD3DFRMWindowPosGetVAlign, (FPD_RMWindowPos stRMWindowPos))

INTERFACE(void, FPD3DFRMWindowPosSetHOffset, (FPD_RMWindowPos stRMWindowPos,  FS_FLOAT fHOffset))

INTERFACE(FS_FLOAT, FPD3DFRMWindowPosGetHOffset, (FPD_RMWindowPos stRMWindowPos))

INTERFACE(void, FPD3DFRMWindowPosSetVOffset, (FPD_RMWindowPos stRMWindowPos,  FS_FLOAT fVOffset))

INTERFACE(FS_FLOAT, FPD3DFRMWindowPosGetVOffset, (FPD_RMWindowPos stRMWindowPos))

NumOfSelector(FPD3DFRMWindowPos)
ENDENUM

//*****************************
/* 3DFRMWindow HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_RMWindow, FPD3DFRMWindowNew, ())

INTERFACE(void, FPD3DFRMWindowDestory, (FPD_RMWindow stRMWindow))

INTERFACE(void, FPD3DFRMWindowSetDimWidth, (FPD_RMWindow stRMWindow,  FPD_RMWindowDimen dimWidth))

INTERFACE(void, FPD3DFRMWindowGetDimWidth, (FPD_RMWindow stRMWindow,  FPD_RMWindowDimen outDimWidth))

INTERFACE(void, FPD3DFRMWindowSetDimHeight, (FPD_RMWindow stRMWindow,  FPD_RMWindowDimen dimHeight))

INTERFACE(void, FPD3DFRMWindowGetDimHeight, (FPD_RMWindow stRMWindow,  FPD_RMWindowDimen outDimHeight))

INTERFACE(void, FPD3DFRMWindowSetPosPosition, (FPD_RMWindow stRMWindow,  FPD_RMWindowPos posPosition))

INTERFACE(void, FPD3DFRMWindowGetPosPosition, (FPD_RMWindow stRMWindow,  FPD_RMWindowPos outPosPosition))

NumOfSelector(FPD3DFRMWindow)
ENDENUM

//*****************************
/* 3DFRMPresentation HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_RMPresentation, FPD3DFRMPresentationNew, ())

INTERFACE(void, FPD3DFRMPresentationDestory, (FPD_RMPresentation stRMPresentation))

INTERFACE(void, FPD3DFRMPresentationSetStyle, (FPD_RMPresentation stRMPresentation,  FPD3D_CanvasWindowStyle wsStyle))

INTERFACE(FPD3D_CanvasWindowStyle, FPD3DFRMPresentationGetStyle, (FPD_RMPresentation stRMPresentation))

INTERFACE(void, FPD3DFRMPresentationSetWindow, (FPD_RMPresentation stRMPresentation,  FPD_RMWindow wWindow))

INTERFACE(void, FPD3DFRMPresentationGetWindow, (FPD_RMPresentation stRMPresentation,  FPD_RMWindow outWindow))

INTERFACE(void, FPD3DFRMPresentationSetTransparentCanvas, (FPD_RMPresentation stRMPresentation,  FS_BOOLEAN bTransparentCanvas))

INTERFACE(FS_BOOLEAN, FPD3DFRMPresentationGetTransparentCanvas, (FPD_RMPresentation stRMPresentation))

INTERFACE(void, FPD3DFRMPresentationSetShowNavigationPanel, (FPD_RMPresentation stRMPresentation,  FS_BOOLEAN bShowNavigationPanel))

INTERFACE(FS_BOOLEAN, FPD3DFRMPresentationGetShowNavigationPanel, (FPD_RMPresentation stRMPresentation))

INTERFACE(void, FPD3DFRMPresentationSetShowToolbar, (FPD_RMPresentation stRMPresentation,  FPDRM_DisplayToolbar bShowToolbar))

INTERFACE(FPDRM_DisplayToolbar, FPD3DFRMPresentationGetShowToolbar, (FPD_RMPresentation stRMPresentation))

INTERFACE(void, FPD3DFRMPresentationSetPassContextClick, (FPD_RMPresentation stRMPresentation,  FS_BOOLEAN bPassContextClick))

INTERFACE(FS_BOOLEAN, FPD3DFRMPresentationGetPassContextClick, (FPD_RMPresentation stRMPresentation))

NumOfSelector(FPD3DFRMPresentation)
ENDENUM

//*****************************
/* 3DFRMActivation HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_RMActivation, FPD3DFRMActivationNew, ())

INTERFACE(void, FPD3DFRMActivationDestory, (FPD_RMActivation stRMActivation))

INTERFACE(void, FPD3DFRMActivationSetCondition, (FPD_RMActivation stRMActivation,  FSPDF3D_ActivateCondition eCondition))

INTERFACE(FSPDF3D_ActivateCondition, FPD3DFRMActivationGetCondition, (FPD_RMActivation stRMActivation))

INTERFACE(void, FPD3DFRMActivationSetAnimation, (FPD_RMActivation stRMActivation,  FPD_3deAnimationStyle asAnimation))

INTERFACE(void, FPD3DFRMActivationGetAnimation, (FPD_RMActivation stRMActivation,  FPD_3deAnimationStyle outAnimation))

INTERFACE(void, FPD3DFRMActivationSetPresentation, (FPD_RMActivation stRMActivation,  FPD_RMPresentation prPresentation))

INTERFACE(void, FPD3DFRMActivationGetPresentation, (FPD_RMActivation stRMActivation,  FPD_RMPresentation outPresentation))

NumOfSelector(FPD3DFRMActivation)
ENDENUM

//*****************************
/* 3DFRMActivation2 HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_RMActivation2, FPD3DFRMActivation2New, ())

INTERFACE(void, FPD3DFRMActivation2Destory, (FPD_RMActivation2 stRMActivation2))

INTERFACE(void, FPD3DFRMActivation2SetView, (FPD_RMActivation2 stRMActivation2,  FPD_3deView pView))

INTERFACE(FPD_3deView, FPD3DFRMActivation2GetView, (FPD_RMActivation2 stRMActivation2))

INTERFACE(void, FPD3DFRMActivation2SetConfiguration, (FPD_RMActivation2 stRMActivation2,  FPDRM_Configuration pConfiguration))

INTERFACE(FPDRM_Configuration, FPD3DFRMActivation2GetConfiguration, (FPD_RMActivation2 stRMActivation2))

NumOfSelector(FPD3DFRMActivation2)
ENDENUM

//*****************************
/* 3DFRMDeactivation HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_RMDeactivation, FPD3DFRMDeactivationNew, ())

INTERFACE(void, FPD3DFRMDeactivationDestory, (FPD_RMDeactivation stRMDeactivation))

INTERFACE(void, FPD3DFRMDeactivationSetCondition, (FPD_RMDeactivation stRMDeactivation,  FSPDF3D_DeactivateCondition eCondition))

INTERFACE(FSPDF3D_DeactivateCondition, FPD3DFRMDeactivationGetCondition, (FPD_RMDeactivation stRMDeactivation))

NumOfSelector(FPD3DFRMDeactivation)
ENDENUM

//*****************************
/* 3dCustomMenuItemData HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3dCustomMenuItemData, FPD3dCustomMenuItemDataNew, ())

INTERFACE(void, FPD3dCustomMenuItemDataDestory, (FPD_3dCustomMenuItemData st3dMenuItem))

INTERFACE(void, FPD3dCustomMenuItemDataSetMenuItemName, (FPD_3dCustomMenuItemData st3dMenuItem,  FS_LPCWSTR wsMenuItemName))

INTERFACE(void, FPD3dCustomMenuItemDataGetMenuItemName, (FPD_3dCustomMenuItemData st3dMenuItem,  FS_WideString outMenuItemName))

INTERFACE(void, FPD3dCustomMenuItemDataSetMenuLabel, (FPD_3dCustomMenuItemData st3dMenuItem,  FS_LPCWSTR wsMenuLabel))

INTERFACE(void, FPD3dCustomMenuItemDataGetMenuLabel, (FPD_3dCustomMenuItemData st3dMenuItem,  FS_WideString outMenuLabel))

INTERFACE(void, FPD3dCustomMenuItemDataSetType, (FPD_3dCustomMenuItemData st3dMenuItem,  FPD3D_CustomMenuItemType eType))

INTERFACE(FPD3D_CustomMenuItemType, FPD3dCustomMenuItemDataGetType, (FPD_3dCustomMenuItemData st3dMenuItem))

INTERFACE(void, FPD3dCustomMenuItemDataSetChecked, (FPD_3dCustomMenuItemData st3dMenuItem,  FS_BOOLEAN bChecked))

INTERFACE(FS_BOOLEAN, FPD3dCustomMenuItemDataGetChecked, (FPD_3dCustomMenuItemData st3dMenuItem))

NumOfSelector(FPD3dCustomMenuItemData)
ENDENUM

//*****************************
/* 3deSpriteData HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3deMeasure, FPD3deSpriteDataAsMeasure, (FPD_3deSpriteData spriteData))

NumOfSelector(FPD3deSpriteData)
ENDENUM

//----------_V16----------
//*****************************
/* 3DBuiltin HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD3D_Builtin_TempFileInfo, FPD3DBuiltinCreateTempFileInfo, ())

INTERFACE(void, FPD3DBuiltinDeleteTempFileInfo, (FPD3D_Builtin_TempFileInfo info))

INTERFACE(FS_LPCSTR, FPD3DBuiltinGetFilePath, (FPD3D_Builtin_TempFileInfo info))

INTERFACE(void, FPD3DBuiltinSetFilePath, (FPD3D_Builtin_TempFileInfo info,  FS_LPCSTR filePath))

INTERFACE(FS_UINT, FPD3DBuiltinGetReserved, (FPD3D_Builtin_TempFileInfo info))

INTERFACE(void, FPD3DBuiltinSetReserved, (FPD3D_Builtin_TempFileInfo info,  FS_UINT reserved))

INTERFACE(FS_FileStream, FPD3DBuiltinU3DLoader, (FPD_Object pStream,  FPD_3DArtworkFormat eFormat,  FPD_3DArtworkFormat* pActualFormat))

INTERFACE(FS_FileStream, FPD3DBuiltinPRCLoader, (FPD_Object pStream,  FPD_3DArtworkFormat eFormat,  FPD_3DArtworkFormat* pActualFormat))

INTERFACE(FS_FileStream, FPD3DBuiltinU3DorPRCLoader, (FPD_Object pStream,  FPD_3DArtworkFormat eFormat,  FPD_3DArtworkFormat* pActualFormat))

INTERFACE(void, FPD3DBuiltinSetTempFileGenerationRule, (FPD3D_Builtin_TempFileGeneration eGeneration))

INTERFACE(FS_LPVOID, FPD3DBuiltinSetTempFileCallback, (FPD_3DBuiltinTempFileCallbacks pCallback))

INTERFACE(void, FPD3DBuiltinReleaseTempFileCallback, (FS_LPVOID handler))

NumOfSelector(FPD3DBuiltin)
ENDENUM

//----------_V17----------
//*****************************
/* 3DMatrix4x4 HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3DMatrix4x4, FPD3DMatrix4x4New, ())

INTERFACE(void, FPD3DMatrix4x4Delete, (FPD_3DMatrix4x4 mt))

INTERFACE(void, FPD3DMatrix4x4GetCoeffs, (FPD_3DMatrix4x4 mt,  FS3DE_Coordinate** coeffs))

NumOfSelector(FPD3DMatrix4x4)
ENDENUM

//*****************************
/* 3dCustomToolButtonData HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_3dCustomToolButtonData, FPD3dCustomToolButtonDataNew, ())

INTERFACE(void, FPD3dCustomToolButtonDataDestory, (FPD_3dCustomToolButtonData st3dMenuItem))

INTERFACE(void, FPD3dCustomToolButtonDataSetName, (FPD_3dCustomToolButtonData st3dMenuItem,  FS_LPCWSTR wsName))

INTERFACE(void, FPD3dCustomToolButtonDataGetName, (FPD_3dCustomToolButtonData st3dMenuItem,  FS_WideString* outName))

INTERFACE(void, FPD3dCustomToolButtonDataSetLabel, (FPD_3dCustomToolButtonData st3dMenuItem,  FS_LPCWSTR wsLabel))

INTERFACE(void, FPD3dCustomToolButtonDataGetLabel, (FPD_3dCustomToolButtonData st3dMenuItem,  FS_WideString* outLabel))

INTERFACE(void, FPD3dCustomToolButtonDataSetType, (FPD_3dCustomToolButtonData st3dMenuItem,  FPD3D_CustomToolButtonType eType))

INTERFACE(FPD3D_CustomToolButtonType, FPD3dCustomToolButtonDataGetType, (FPD_3dCustomToolButtonData st3dMenuItem))

INTERFACE(void, FPD3dCustomToolButtonDataSetRemovedState, (FPD_3dCustomToolButtonData st3dMenuItem,  FS_BOOLEAN bChecked))

INTERFACE(FS_BOOLEAN, FPD3dCustomToolButtonDataGetRemovedState, (FPD_3dCustomToolButtonData st3dMenuItem))

INTERFACE(void, FPD3dCustomToolButtonDataSetEnabledState, (FPD_3dCustomToolButtonData st3dMenuItem,  FS_BOOLEAN bChecked))

INTERFACE(FS_BOOLEAN, FPD3dCustomToolButtonDataGetEnabledState, (FPD_3dCustomToolButtonData st3dMenuItem))

NumOfSelector(FPD3dCustomToolButtonData)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

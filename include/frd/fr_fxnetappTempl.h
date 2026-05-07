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
//*****************************
/* AppFxNet HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOL, FRAppFxNetRegisterAppEventHandlerFxNet, (FR_AppEventFxNetCallbacks appEventFxNetCallbacks))

NumOfSelector(FRAppFxNet)
ENDENUM

//*****************************
/* InternalFxNet HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOL, FRInternalFxNetIsFRDGLogin, ())

INTERFACE(void, FRInternalFxNetShowLoginDlg, ())

INTERFACE(FS_BOOL, FRInternalFxNetDllGetTicket, (FS_CHAR* cTicket,  FS_INT32 len))

INTERFACE(FS_BOOL, FRInternalFxNetCheckActionPermission, (FS_LPWSTR wsAction))

INTERFACE(FS_LPSTR, FRInternalFxNetCheckPRDTimestampPermission, (FS_LPSTR bsFileHash))

INTERFACE(FS_BOOL, FRInternalFxNetCheckPermissionByFaceName, (FS_LPWSTR cwFontName))

INTERFACE(HWND, FRInternalFxNetGetLoginHwnd, ())

INTERFACE(FS_BOOL, FRInternalFxNetPreTranMsgToSdk, (MSG* pMsg))

INTERFACE(FS_BOOL, FRInternalFxNetDllShowPaymentDlg, (wchar_t *param))

INTERFACE(FS_BOOL, FRInternalFxNetGetUserId, (char* userId,  int len))

INTERFACE(FS_BOOL, FRInternalFxNetGetNickName, (char* userName,  int len))

INTERFACE(FS_BOOL, FRInternalFxNetGetHeadIcon, (char* headIcon,  int len))

INTERFACE(int, FRInternalFxNetGetUserType, ())

INTERFACE(FS_BOOL, FRInternalFxNetAddAnnotToMarkupPanel, (FPD_Object annotDict,  FS_INT32 nPage,  FS_BOOL bRedrawPanel,  FS_BOOL bExpand,  FPD_Document pDoc,  FS_BOOL bShow))

INTERFACE(void, FRInternalFxNetShowAnnotNote, (FR_Annot annot,  BOOL bShow))

INTERFACE(FPD_PageObject, FRInternalFxNetGetCurrentImageSelectObj, (FR_Document doc,  FR_PageView& inOutPageview))

INTERFACE(FS_BOOL, FRInternalFxNetOCRExtractText, (FR_PageView pageview,  FPD_PageObject imgObj,  FS_WideString* wsText))

INTERFACE(void, FRInternalFxNetGetOCRLanInfo, (FS_PtrArray* outObjArray))

INTERFACE(FS_BOOL, FRInternalFxNetGetImageBuf, (FR_PageView pageview,  FPD_PageObject imgObj,  FS_LPBYTE& buf,  FS_UINT& size))

NumOfSelector(FRInternalFxNet)
ENDENUM

//----------_V12----------
//----------_V13----------
//----------_V14----------
//----------_V15----------
//----------_V16----------
//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------

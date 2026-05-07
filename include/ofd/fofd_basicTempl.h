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
//*****************************
/* CryptoDict HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FOFDCryptoDict)
ENDENUM

//*****************************
/* SecurityHandler HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FOFDSecurityHandler)
ENDENUM

//*****************************
/* StdSecurityHandler HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FOFDStdSecurityHandler)
ENDENUM

//*****************************
/* StdCertSecurityHandler HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FOFDStdCertSecurityHandler)
ENDENUM

//*****************************
/* SMSecurityHandler HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FOFDSMSecurityHandler)
ENDENUM

//*****************************
/* CryptoHandler HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FOFDCryptoHandler)
ENDENUM

//*****************************
/* StdCryptoHandler HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FOFDStdCryptoHandler)
ENDENUM

//*****************************
/* SM4CryptoHandler HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FOFDSM4CryptoHandler)
ENDENUM

//*****************************
/* FileStream HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FOFDFileStream)
ENDENUM

//*****************************
/* PauseHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FOFDPauseHandlerCreate
 * @details Creates the pause handler.
 * @param[in]  pause The input pause handler structure.
 * @return   The newly created pause handler.
 * @note 
 */
INTERFACE(FOFD_PauseHandler, FOFDPauseHandlerCreate, (OFD_Pause pause))

/**
 * @brief FOFDPauseHandlerDestroy
 * @details Destroys the pause handler.
 * @param[in]  pauseHandler The input pause handler to be destroyed.
 * @return   void
 * @note 
 */
INTERFACE(void, FOFDPauseHandlerDestroy, (FOFD_PauseHandler pauseHandler))

NumOfSelector(FOFDPauseHandler)
ENDENUM

//*****************************
/* UIMgr HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FOFDUIMgrSetPanelIndex, (FR_PanelMgr panelMgr,  FS_LPCSTR csName,  FS_INT32 nInitialIndex))

INTERFACE(void, FOFDUIMgrTriggerPanel, (FR_PanelMgr pPanelMgr,  FS_ByteString bsName))

INTERFACE(void, FOFDUIMgrFormatComboBox, (FS_WideString csText,  FS_INT32 nType,  FS_WideString* out))

INTERFACE(void, FOFDUIMgrShowAutoHideStatusBar, (BOOL bShow,  int nOffset_X,  int nOffset_Y))

NumOfSelector(FOFDUIMgr)
ENDENUM

//*****************************
/* DIBAttribute HFT functions */
//*****************************

BEGINENUM
INTERFACE(FOFD_DIBAttribute, FOFDDIBAttributeCreate, ())

INTERFACE(FS_INT32, FOFDDIBAttributeGetXDPI, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetXDPI, (FOFD_DIBAttribute attr,  FS_INT32 value))

INTERFACE(FS_INT32, FOFDDIBAttributeGetYDPI, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetYDPI, (FOFD_DIBAttribute attr,  FS_INT32 value))

INTERFACE(FS_FLOAT, FOFDDIBAttributeGetAspectRatio, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetAspectRatio, (FOFD_DIBAttribute attr,  FS_FLOAT value))

INTERFACE(FS_DWORD, FOFDDIBAttributeGetDPIUnit, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetDPIUnit, (FOFD_DIBAttribute attr,  FS_DWORD value))

INTERFACE(void, FOFDDIBAttributeGetAuthor, (FOFD_DIBAttribute attr,  FS_ByteString* out))

INTERFACE(void, FOFDDIBAttributeSetAuthor, (FOFD_DIBAttribute attr,  FS_ByteString value))

INTERFACE(FS_LPBYTE, FOFDDIBAttributeGetTime, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetTime, (FOFD_DIBAttribute attr,  FS_LPBYTE value))

INTERFACE(FS_INT32, FOFDDIBAttributeGetGifLeft, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetGifLeft, (FOFD_DIBAttribute attr,  FS_INT32 value))

INTERFACE(FS_INT32, FOFDDIBAttributeGetGifTop, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetGifTop, (FOFD_DIBAttribute attr,  FS_INT32 value))

INTERFACE(FS_DWORD*, FOFDDIBAttributeGetGifLocalPalette, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetGifLocalPalette, (FOFD_DIBAttribute attr,  FS_DWORD* value))

INTERFACE(FS_DWORD, FOFDDIBAttributeGetGifLocalPalNum, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetGifLocalPalNum, (FOFD_DIBAttribute attr,  FS_DWORD value))

INTERFACE(FS_INT32, FOFDDIBAttributeGetBmpCompressType, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetBmpCompressType, (FOFD_DIBAttribute attr,  FS_INT32 value))

INTERFACE(FS_DWORD, FOFDDIBAttributeGetTiffFrameCompressType, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetTiffFrameCompressType, (FOFD_DIBAttribute attr,  FS_DWORD value))

INTERFACE(FS_DWORD, FOFDDIBAttributeGetTiffFrameCompressOptions, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetTiffFrameCompressOptions, (FOFD_DIBAttribute attr,  FS_DWORD value))

INTERFACE(FS_INT32, FOFDDIBAttributeGetTiffFrameFillOrder, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetTiffFrameFillOrder, (FOFD_DIBAttribute attr,  FS_INT32 value))

INTERFACE(FS_DWORD, FOFDDIBAttributeGetTiffFrameCompressJpegQuality, (FOFD_DIBAttribute attr))

INTERFACE(void, FOFDDIBAttributeSetTiffFrameCompressJpegQuality, (FOFD_DIBAttribute attr,  FS_DWORD value))

NumOfSelector(FOFDDIBAttribute)
ENDENUM

//*****************************
/* CodeC HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOL, FOFDCodeCPngEncode, (FS_DIBitmap pSource,  FS_LPCWSTR file_name,  FS_BOOL bInterlace,  FOFD_DIBAttribute pAttribute))

NumOfSelector(FOFDCodeC)
ENDENUM

//*****************************
/* PrintSetting HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_INT32, FOFDPrintSettingGetGlobalUnit, ())

INTERFACE(void, FOFDPrintSettingGetDefaultPrinterName, (FS_WideString* out))

INTERFACE(DEVMODE*, FOFDPrintSettingGetDefaultPrinterDevMode, ())

INTERFACE(void, FOFDPrintSettingSetDefaultPrinterDevMode, (HANDLE hDevNames,  HANDLE hDevMode))

INTERFACE(FS_BOOL, FOFDPrintSettingIsPrintUseGraphics, ())

NumOfSelector(FOFDPrintSetting)
ENDENUM

//*****************************
/* Sys HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FOFDSys)
ENDENUM

//----------_V11----------
//----------_V12----------
//----------_V13----------
//----------_V14----------
//*****************************
/* Fontmapper HFT functions */
//*****************************

BEGINENUM
NumOfSelector(FOFDFontmapper)
ENDENUM

//----------_V15----------
//----------_V16----------
//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------

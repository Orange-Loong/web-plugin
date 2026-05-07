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
/* Sys HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRSysLoadStandarCursor
 * @details Loads a standard cursor by type.
 * @param[in]  nCursorType The type of the cursor. See <a>FRCursorTypeFlags</a>.
 * @return   The specified cursor loaded.
 * @note 
 * @see FRSysSetCursor
 * @see FRSysGetCursor
 */
INTERFACE(FR_Cursor, FRSysLoadStandarCursor, (FS_INT32 nCursorType))

/**
 * @brief FRSysGetCursor
 * @details Gets the current cursor.
 * @return   The current cursor.
 * @note 
 * @see FRSysSetCursor
 * @see FRSysLoadStandarCursor
 */
INTERFACE(FR_Cursor, FRSysGetCursor, (void))

/**
 * @brief FRSysSetCursor
 * @details Sets the current cursor.
 * @param[in]  cursor The input cursor to be set.
 * @return   void
 * @note 
 * @see FRSysGetCursor
 * @see FRSysLoadStandarCursor
 */
INTERFACE(void, FRSysSetCursor, (FR_Cursor cursor))

/**
 * @brief FRSysShowMessageBox
 * @details Creates, displays, and operates a message box. The message box contains an application-defined message 
	* and title, plus any combination of predefined icons and push buttons.
 * @param[in]  wszPrompt Pointer to a null-terminated string that contains the message to be displayed.
 * @param[in]  nType Specifies the contents and behavior of the dialog box. See the description about <Italic>MessageBox</Italic> from MSDN.
 * @param[in]  wszCaption Pointer to a null-terminated string that contains the dialog box title. If this parameter is NULL, the default title is used.
 * @param[in]  pCheckBoxParams Pointer to a data structure representing the params of the check box on the message box. If this parameter is NULL, the default value is used.
 * @param[in]  hParent The parent window.
 * @return   See the description about <Italic>MessageBox</Italic> from <Italic>MSDN</Italic>.
 * @note 
 */
INTERFACE(FS_INT32, FRSysShowMessageBox, (FS_LPCWSTR wszPrompt,  unsigned int nType,  FS_LPCWSTR wszCaption,  FR_MSGBOX_CHECKBOXPARAMS* pCheckBoxParams,  HWND hParent))

/**
 * @brief FRSysInstallDialogSkinTheme
 * @details The dialog can install the skin theme of <Italic>Foxit Reader</Italic> to keep the same.
	* Invokes this interface in the <Italic>CReader_Dialog::OnInitDialog</Italic> routine of the dialog.
 * @param[in]  hWnd The dialog to install skin theme of <Italic>Foxit Reader</Italic>.
 * @return   <a>True</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRSysInstallDialogSkinTheme, (HWND hWnd))

/**
 * @brief FRSysInstallDialogScrollBar
 * @details Installs the dialog scroll bar.
 * @param[in]  hWnd The dialog to install the scroll bar.
 * @return   <a>True</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRSysInstallDialogScrollBar, (HWND hWnd))

/**
 * @brief FRSysGetSkinCount
 * @details Gets the count of skins for Foxit Reader.
 * @return   The count of skins for Foxit Reader.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
 * @see 
 */
INTERFACE(FS_INT32, FRSysGetSkinCount, ())

/**
 * @brief FRSysGetSkinNameByIndex
 * @details Gets the skin name by index.
 * @param[in]  nIndex The input index.
 * @param[out]  outName It receives the name of the skin.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
 * @see 
 */
INTERFACE(void, FRSysGetSkinNameByIndex, (FS_INT32 nIndex,  FS_WideString* outName))

/**
 * @brief FRSysSetActiveSkinByIndex
 * @details Sets the active skin by index.
 * @param[in]  nIndex The input index.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRSysSetActiveSkinByIndex, (FS_INT32 nIndex))

/**
 * @brief FRSysSetActiveSkinByName
 * @details Sets the active skin by name.
 * @param[in]  nIndex The input name of the skin.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRSysSetActiveSkinByName, (FS_LPCWSTR lpwsName))

/**
 * @brief FRSysShowStopLaunchDlg
 * @details Show the safe mode dialog.
 * @param[out]  pbModify If user modify the setting.
 * @param[in]  lpwsInfo The description of Safe Mode check button.
 * @param[in]  lpwsCheckSafeMode The text of Safe Mode check button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.7.1
 * @see 
 */
INTERFACE(void, FRSysShowStopLaunchDlg, (FS_BOOL *pbModify,  FS_LPCWSTR lpwsInfo,  FS_LPCWSTR lpwsCheckSafeMode))

INTERFACE(FS_INT32, FRSysShowMessageBox2, (FS_LPCWSTR wszPrompt,  unsigned int nType,  FS_LPCWSTR wszCaption,  FS_PtrArray arCheckBoxParams,  FS_BOOL bRadioBoxMode,  HWND hParent))

INTERFACE(FS_INT32, FRSysShowMessageBox3, (FS_LPCWSTR wszPrompt,  FR_MsgBtnType button,  FR_MsgType nType,  FS_LPCWSTR wszCaption,  FR_MSGBOX_CHECKBOXPARAMS2* pCheckBoxParams,  FS_HWND hParent))

NumOfSelector(FRSys)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* WindowsDIB HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRWindowsDIBNew
 * @details Constructs a DIB that can be efficiently interact with Windows device.
	* Currently the constructed DIB will always in <a>FS_DIB_Rgb</a> format.
 * @param[in]  hDC The input windows device context.
 * @param[in]  width The bimtap width.
 * @param[in]  height The bitmap height.
 * @return   A DIB.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBNew, (HDC hDC,  FS_INT32 width,  FS_INT32 height))

/**
 * @brief FRWindowsDIBDestroy
 * @details Destroys the input DIB bitmap.
 * @param[in]  pBitmap The input DIB bitmap.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRWindowsDIBDestroy, (FS_DIBitmap pBitmap))

/**
 * @brief FRWindowsDIBGetBitmapInfo
 * @details Get Windows bitmap info structure.
	* The result is a binary string that can be used at a <Italic>BITMAPINFO</Italic> structure.
 * @param[in]  pBitmap The input DIB bitmap.
 * @param[out]  outInfo It receives the windows bitmap info structure for the DIB.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRWindowsDIBGetBitmapInfo, (FS_DIBitmap pBitmap,  FS_ByteString* outInfo))

/**
 * @brief FRWindowsDIBLoadFromBuf
 * @details Constructs a bitmap from existing data.
 * @param[in]  pbmi The windows bitmap info structure.
 * @param[in]  pData The bitmap data.
 * @return   A bitmap from existing data.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBLoadFromBuf, (BITMAPINFO* pbmi,  void* pData))

/**
 * @brief FRWindowsDIBGetDDBitmap
 * @details Converts to device compatible bitmap.
 * @param[in]  pBitmap The input DIB.
 * @param[in]  hDC The input DC.
 * @return   A device dependent bitmap compatible with the input DC.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(HBITMAP, FRWindowsDIBGetDDBitmap, (FS_DIBitmap pBitmap,  HDC hDC))

/**
 * @brief FRWindowsDIBLoadFromDDB
 * @details Load DI bitmap from DDB. If <param>hDC</param> is NULL, system display DC will be used.
 * @param[in]  hDC The input DC.
 * @param[in]  hBitmap The input device dependent bitmap.
 * @param[in]  pPalette The bmp's palette, applicable to 1bppRgb and 8bppRgb formats.
 * @param[in]  size The palette's size.
 * @return   A DIB.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBLoadFromDDB, (HDC hDC,  HBITMAP hBitmap,  FS_DWORD* pPalette,  FS_DWORD size))

/**
 * @brief FRWindowsDIBLoadFromFile
 * @details Load DI bitmap from file. Unicode version. Without GDI+ support, we supports only BMP file.
	* With GDI support, we support much more.
 * @param[in]  filename The input full file path.
 * @return   A DIB.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBLoadFromFile, (FS_LPCWSTR filename))

/**
 * @brief FRWindowsDIBLoadFromFileII
 * @details Load DI bitmap from file. Unicode version. Without GDI+ support, we supports only BMP file.
	* With GDI support, we support much more.
 * @param[in]  filename The input full file path.
 * @return   A DIB.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBLoadFromFileII, (FS_LPCSTR filename))

/**
 * @brief FRWindowsDIBLoadDIBitmap
 * @details Load DI bitmap from file. Unicode version. Without GDI+ support, we supports only BMP file.
	* With GDI support, we support much more.
 * @param[in]  args The input full file path or memory.
 * @return   A DIB.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBLoadDIBitmap, (FR_WINDIB_Open_Args args))

/**
 * @brief FRWindowsDIBGetDC
 * @details Gets the DC.
 * @param[in]  pBitmap The input DIB bitmap.
 * @return   The DC.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(HDC, FRWindowsDIBGetDC, (FS_DIBitmap pBitmap))

/**
 * @brief FRWindowsDIBGetWindowsBitmap
 * @details Gets the bitmap.
 * @param[in]  pBitmap The input DIB bitmap.
 * @return   The bitmap handle.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(HBITMAP, FRWindowsDIBGetWindowsBitmap, (FS_DIBitmap pBitmap))

/**
 * @brief FRWindowsDIBLoadFromDevice
 * @details Loads from a device.
 * @param[in]  pBitmap The input DIB bitmap.
 * @param[in]  hDC The input windows device context.
 * @param[in]  left The x-coordinate in the windows DC.
 * @param[in]  top The y-coordinate in the windows DC.
 * @return   The bitmap.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRWindowsDIBLoadFromDevice, (FS_DIBitmap pBitmap,  HDC hDC,  FS_INT32 left,  FS_INT32 top))

/**
 * @brief FRWindowsDIBSetToDevice
 * @details Outputs to a device.
 * @param[in]  pBitmap The input DIB bitmap.
 * @param[in]  hDC The input windows device context.
 * @param[in]  left The x-coordinate in the windows DC.
 * @param[in]  top The y-coordinate in the windows DC.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRWindowsDIBSetToDevice, (FS_DIBitmap pBitmap,  HDC hDC,  FS_INT32 left,  FS_INT32 top))

NumOfSelector(FRWindowsDIB)
ENDENUM

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
/* SystemHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRSystemHandlerIsStandardFont
 * @details Check if it is an standard font.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[out]  sFontName The font name.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRSystemHandlerIsStandardFont, (FR_SystemHandler handler,  const FS_ByteString sFontName))

/**
 * @brief FRSystemHandlerGetDefaultFontNameByCharset
 * @details Get the name of the default font corresponding to charset through Charset.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[out]  csFontname Get the name of the default font corresponding to charset.
 * @param[in]  nCharSet The input charset.
 * @return   FS_BOOLEAN          TRUE means get success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 */
INTERFACE(FS_BOOLEAN, FRSystemHandlerGetDefaultFontNameByCharset, (FR_SystemHandler handler,  FS_WideString* csFontname,  FS_INT32 nCharSet))

/**
 * @brief FRSystemHandlerGetFullName
 * @details Get the full name.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[out]  csFontName Get the name of the default font corresponding to charset.
 * @param[in]  bBold Whether bold.
 * @param[in]  bItalic Whether italic.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRSystemHandlerGetFullName, (FR_SystemHandler handler,  FS_ByteString* csFontName,  FS_BOOLEAN bBold,  FS_BOOLEAN bItalic))

/**
 * @brief FRSystemHandlerGetNativeTrueTypeFont
 * @details Get the native true type font.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[out]  nCharset The input charset.
 * @return   FS_LPCWSTR
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_LPCWSTR, FRSystemHandlerGetNativeTrueTypeFont, (FR_SystemHandler handler,  FS_INT32 nCharset))

/**
 * @brief FRSystemHandlerFindNativeTrueTypeFont
 * @details Find native true type font.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[in]  nCharset The input charset.
 * @param[in]  wsFontFaceName The input font face name.
 * @return   FS_BOOLEAN         true: find suceess.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRSystemHandlerFindNativeTrueTypeFont, (FR_SystemHandler handler,  FS_INT32 nCharset,  FS_LPCWSTR wsFontFaceName))

/**
 * @brief FRSystemHandlerGetFontCharset
 * @details Get the font charset.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[in]  cwFontFaceName The input font face name.
 * @param[out]  charset Get the charset.
 * @return   FS_BOOLEAN         true: get suceess.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRSystemHandlerGetFontCharset, (FR_SystemHandler handler,  FS_LPCWSTR cwFontFaceName,  FS_INT32* charset))

/**
 * @brief FRSystemHandlerConvertToFWLVitrualKeyCode
 * @details Convert key info.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[in]  nChar The input char code of key.
 * @param[in]  bOnChar If it's windows key code.
 * @return   FS_DWORD
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_DWORD, FRSystemHandlerConvertToFWLVitrualKeyCode, (FR_SystemHandler handler,  FS_DWORD nChar,  FS_BOOL bOnChar))

/**
 * @brief FRSystemHandlerCreatePopupMenu
 * @details Create popup menu.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[in]  hWnd The input HWND.
 * @return   FS_LPVOID  Return the popup menu.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_LPVOID, FRSystemHandlerCreatePopupMenu, (FR_SystemHandler handler,  FS_LPVOID hWnd))

/**
 * @brief FRSystemHandlerAppendMenuItem
 * @details Append menu item.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[in]  hMenu The input HMENU need to append item.
 * @param[in]  nIDNewItem The input new item id.
 * @param[in]  str The input info of the item.
 * @return   FS_LPVOID   true: append success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRSystemHandlerAppendMenuItem, (FR_SystemHandler handler,  FS_LPVOID hMenu,  FS_INT32 nIDNewItem,  FS_LPCWSTR str))

/**
 * @brief FRSystemHandlerEnableMenuItem
 * @details Enable menu item.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[in]  hMenu The input HMENU.
 * @param[in]  nIDItem The input menu item id.
 * @param[in]  bEnabled Set the enable state.
 * @return   FS_BOOLEAN   true: set enable status success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRSystemHandlerEnableMenuItem, (FR_SystemHandler handler,  FS_LPVOID hMenu,  FS_INT32 nIDItem,  FS_BOOLEAN bEnabled))

/**
 * @brief FRSystemHandlerTrackPopupMenu
 * @details Track popup menu.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[in]  hMenu The input HMENU.
 * @param[in]  x The x postion of the menu.
 * @param[in]  y The x postion of the menu.
 * @param[in]  hParent The input parent HAND.
 * @return   FS_INT32   Return the commid id.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_INT32, FRSystemHandlerTrackPopupMenu, (FR_SystemHandler handler,  FS_LPVOID hMenu,  FS_INT32 x,  FS_INT32 y,  FS_LPVOID hParent))

/**
 * @brief FRSystemHandlerDestroyMenu
 * @details Destroy menu.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[in]  hMenu The input HMENU.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRSystemHandlerDestroyMenu, (FR_SystemHandler handler,  FS_LPVOID hMenu))

/**
 * @brief FRSystemHandlerCreatePopupSubMenu
 * @details Create popup sub menu.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @return   FS_LPVOID
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_LPVOID, FRSystemHandlerCreatePopupSubMenu, (FR_SystemHandler handler))

/**
 * @brief FRSystemHandlerAppendSubMenu
 * @details Appen sub menu.
 * @param[in]  handler The input system handler,it get from FRAppGetSystemHandler.
 * @param[in]  hMenu The input HMENU.
 * @param[in]  hSubMenu The input sub menu.
 * @param[in]  str The input sub menu info.
 * @return   FS_BOOLEAN  true: append sub menu success.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(FS_BOOLEAN, FRSystemHandlerAppendSubMenu, (FR_SystemHandler handler,  FS_LPVOID hMenu,  FS_LPVOID hSubMenu,  FS_LPCWSTR str))

/**
 * @brief FRSystemHandlerSetCursor
 * @details Set Cursor.
 * @param[in]  handler The input system handler
 * @param[out]  nCursorType 
 * @param[out]  hWnd 
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FRSystemHandlerSetCursor, (FR_SystemHandler handler,  FR_CURSORSTYLE nCursorType,  FS_HWND hWnd))

/**
 * @brief FRSystemHandlerSetCustomCursorHandler
 * @details Set custom cursor handler.
 * @param[in]  handler The input system handler
 * @param[out]  pCustomCursorHandler The input custom cursor handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 * @Deprecated    Internal use.
 */
INTERFACE(void, FRSystemHandlerSetCustomCursorHandler, (FR_SystemHandler handler,  FPD_CustomCursorHandler pCustomCursorHandler))

NumOfSelector(FRSystemHandler)
ENDENUM

//*****************************
/* CTBLogFonts HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRCTBLogFontsNew
 * @details Create FR_CTBLogFonts object, that used vector to manage logfont in APP.
 * @return   FR_CTBLogFonts
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_CTBLogFonts, FRCTBLogFontsNew, ())

/**
 * @brief FRCTBLogFontsDestroy
 * @details Release FR_CTBLogFonts object.
 * @param[in]  font The FR_CTBLogFonts object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRCTBLogFontsDestroy, (FR_CTBLogFonts font))

/**
 * @brief FRCTBLogFontsGetSize
 * @details Get the size of LogFonts.
 * @param[in]  font The FR_CTBLogFonts object.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_INT32, FRCTBLogFontsGetSize, (FR_CTBLogFonts font))

/**
 * @brief FRCTBLogFontsGetAt
 * @details Get the index of LogFonts.
 * @param[in]  font The FR_CTBLogFonts object.
 * @param[in]  index The index of logfonts vector.
 * @return   FS_FONT*
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_FONT*, FRCTBLogFontsGetAt, (FR_CTBLogFonts font,  FS_INT32 index))

/**
 * @brief FRCTBLogFontsAdd
 * @details Add font to LogFonts.
 * @param[in]  font The FR_CTBLogFonts object.
 * @param[in]  pLogFont The font need to add.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRCTBLogFontsAdd, (FR_CTBLogFonts font,  FS_FONT pLogFont))

NumOfSelector(FRCTBLogFonts)
ENDENUM

//*****************************
/* TBSYSFONTDATA HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRTBSYSFONTDATACreate
 * @details Create FR_TB_SYSFONTDATA object.
 * @return   FR_TB_SYSFONTDATA
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_TB_SYSFONTDATA, FRTBSYSFONTDATACreate, ())

/**
 * @brief FRTBSYSFONTDATADestroy
 * @details Destroy FR_TB_SYSFONTDATA object.
 * @param[in]  data The input FR_TB_SYSFONTDATA object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATADestroy, (FR_TB_SYSFONTDATA data))

/**
 * @brief FRTBSYSFONTDATASetFaceName
 * @details Set face name for  FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[in]  faceName The face name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATASetFaceName, (FR_TB_SYSFONTDATA data,  FS_WideString faceName))

/**
 * @brief FRTBSYSFONTDATAGetFaceName
 * @details Get face name for FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[out]  outfaceName Get the face name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATAGetFaceName, (FR_TB_SYSFONTDATA data,  FS_WideString* outfaceName))

/**
 * @brief FRTBSYSFONTDATASetScriptName
 * @details Set script name for FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[in]  scriptName The script name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATASetScriptName, (FR_TB_SYSFONTDATA data,  FS_WideString scriptName))

/**
 * @brief FRTBSYSFONTDATAGetScriptName
 * @details Get script name for FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[out]  outscriptName Get the script name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATAGetScriptName, (FR_TB_SYSFONTDATA data,  FS_WideString* outscriptName))

/**
 * @brief FRTBSYSFONTDATASetTagName
 * @details Set tag name for FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[in]  tagName The tag name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATASetTagName, (FR_TB_SYSFONTDATA data,  FS_WideString tagName))

/**
 * @brief FRTBSYSFONTDATAGetTagName
 * @details Get tag name for FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[out]  outtagName get the tag name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATAGetTagName, (FR_TB_SYSFONTDATA data,  FS_WideString* outtagName))

/**
 * @brief FRTBSYSFONTDATASetFullName
 * @details Set full name for FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[in]  fullName The full name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATASetFullName, (FR_TB_SYSFONTDATA data,  FS_WideString fullName))

/**
 * @brief FRTBSYSFONTDATAGetFullName
 * @details Get full name for FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[out]  outfullName Get the full name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATAGetFullName, (FR_TB_SYSFONTDATA data,  FS_WideString* outfullName))

/**
 * @brief FRTBSYSFONTDATASetPSName
 * @details Set ps name for FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[in]  PSName The ps name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATASetPSName, (FR_TB_SYSFONTDATA data,  FS_WideString PSName))

/**
 * @brief FRTBSYSFONTDATAGetPSName
 * @details Get ps name for FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[out]  outPSName get the ps name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATAGetPSName, (FR_TB_SYSFONTDATA data,  FS_WideString* outPSName))

/**
 * @brief FRTBSYSFONTDATASetNamesArr
 * @details Set name arr for FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[in]  namesArr names arr.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATASetNamesArr, (FR_TB_SYSFONTDATA data,  FS_WideStringArray namesArr))

/**
 * @brief FRTBSYSFONTDATAGetNamesArr
 * @details Get name arr for FR_TB_SYSFONTDATA object.
 * @param[in]  data The FR_TB_SYSFONTDATA object.
 * @param[out]  outnamesArr names arr.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRTBSYSFONTDATAGetNamesArr, (FR_TB_SYSFONTDATA data,  FS_WideStringArray* outnamesArr))

NumOfSelector(FRTBSYSFONTDATA)
ENDENUM

//*****************************
/* ITBSysFont HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRITBSysFontGetSysFontObject
 * @details Get FR_ITBSysFont object from APP.
 * @return   FR_ITBSysFont
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FR_ITBSysFont, FRITBSysFontGetSysFontObject, ())

/**
 * @brief FRITBSysFontLoadLogFonts
 * @details Load fonts.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @param[in]  swFaceName The font face name.
 * @param[out]  fontarray Load LogFonts.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRITBSysFontLoadLogFonts, (FR_ITBSysFont sysFont,  const FS_LPCWSTR swFaceName,  FR_CTBLogFonts* fontarray))

/**
 * @brief FRITBSysFontGetSysFontFaceName
 * @details Get system font face name.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @param[in]  lpwsScriptName The script name.
 * @param[out]  outName Get the face name..
 * @return   FS_BOOL
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOL, FRITBSysFontGetSysFontFaceName, (FR_ITBSysFont sysFont,  FS_LPCWSTR lpwsScriptName,  FS_WideString* outName))

/**
 * @brief FRITBSysFontGetAllFormatFontSize
 * @details Get the cout of font size.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_INT32, FRITBSysFontGetAllFormatFontSize, (FR_ITBSysFont sysFont))

/**
 * @brief FRITBSysFontGetAtAllFormatFont
 * @details Get the index of format font.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @param[in]  index The index of sysfont.
 * @param[out]  sFaceName Get the face name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRITBSysFontGetAtAllFormatFont, (FR_ITBSysFont sysFont,  FS_INT32 index,  FS_WideString* sFaceName))

/**
 * @brief FRITBSysFontGetFontFaceNameBoldItalic
 * @details Get font facename, Bold, Italic of the font.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @param[in]  sFontName The font name.
 * @param[out]  sFaceName Get the face name.
 * @param[out]  bBold Get the font is Bold.
 * @param[out]  bItalic Get the font is Italic.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRITBSysFontGetFontFaceNameBoldItalic, (FR_ITBSysFont sysFont,  const FS_WideString& sFontName,  FS_WideString* sFaceName,  FS_BOOL* bBold,  FS_BOOL* bItalic))

/**
 * @brief FRITBSysFontGetStdFontSize
 * @details Get fontsize of the standard font.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @return   FS_INT32
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_INT32, FRITBSysFontGetStdFontSize, (FR_ITBSysFont sysFont))

/**
 * @brief FRITBSysFontGetAtStdFont
 * @details Get font facename, Bold, Italic of the font.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @param[in]  index The index of the standard font.
 * @param[out]  sFaceName Get the face name of the standard font.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRITBSysFontGetAtStdFont, (FR_ITBSysFont sysFont,  FS_INT32 index,  FS_WideString sFaceName))

INTERFACE(void, FRITBSysFontGetAtStdFont2, (FR_ITBSysFont sysFont,  FS_INT32 index,  FR_TB_SYSFONTDATA* outdata))

/**
 * @brief FRITBSysFontIsStandardFont
 * @details Check if it is standard font.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @param[in]  sFontName The input font name.
 * @return   FS_BOOLEAN
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(FS_BOOLEAN, FRITBSysFontIsStandardFont, (FR_ITBSysFont sysFont,  FS_LPCWSTR sFontName))

/**
 * @brief FRITBSysFontGetScriptName
 * @details Get script name.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @param[in]  swFaceName The input face name.
 * @param[in]  bRemoveSymbol Whether to remove symbol.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 */
INTERFACE(void, FRITBSysFontGetScriptName, (FR_ITBSysFont sysFont,  FS_LPCWSTR swFaceName,  FS_BOOLEAN bRemoveSymbol,  FS_WideString* outScriptName))

/**
 * @brief FRITBSysFontFontNamePDF2Name
 * @details Get the system font name.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @param[in]  pdfName The input pdf name.
 * @param[out]  winName Get the system font name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FRITBSysFontFontNamePDF2Name, (FR_ITBSysFont sysFont,  FS_LPCWSTR pdfName,  FS_WideString* winName))

/**
 * @brief FRITBSysFontGetCharsetByFontName
 * @details Get the charset by font name.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @param[out]  nCharSet Get the charset.
 * @param[in]  sFontName The input font name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FRITBSysFontGetCharsetByFontName, (FR_ITBSysFont sysFont,  FS_INT32* nCharSet,  FS_LPCWSTR sFontName))

/**
 * @brief FRITBSysFontGetBaseFontName
 * @details Get base font name.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @param[in]  pFont The input FPD_Font.
 * @param[out]  outFontName Get base font name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
 */
INTERFACE(void, FRITBSysFontGetBaseFontName, (FR_ITBSysFont sysFont,  FPD_Font pFont,  FS_WideString* outFontName))

/**
 * @brief FRITBSysFontGetFullName
 * @details Get the full font name.
 * @param[in]  sysFont The FR_ITBSysFont object.
 * @param[in]  swBaseFontName The input base font name.
 * @param[in]  bRemoveSymbol Whether to remove symbol, default is true.
 * @param[out]  outFullName Get the full name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
 */
INTERFACE(void, FRITBSysFontGetFullName, (FR_ITBSysFont sysFont,  const FS_LPCWSTR swBaseFontName,  FS_BOOLEAN bRemoveSymbol,  FS_WideString* outFullName))

NumOfSelector(FRITBSysFont)
ENDENUM

//----------_V15----------
//----------_V16----------
//----------_V17----------
//----------_V18----------
//----------_V19----------
//----------_V20----------

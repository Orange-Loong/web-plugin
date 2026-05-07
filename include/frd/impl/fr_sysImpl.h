/** @file fr_sysImpl.h.
 * 
 *  @brief many system-wide utilies definitions .
 */

#ifndef FR_SYSIMPL_H
#define FR_SYSIMPL_H


#ifndef FR_SYSEXPT_H
#include "../fr_sysExpT.h"
#endif


#ifdef __cplusplus
extern "C"{
#endif

class CFR_Sys_V1
{
public:
	//************************************
	// Function:  LoadStandarCursor
	// Param[in]: nCursorType The type of the cursor. See <a>FRCursorTypeFlags</a>.
	// Return:	  The specified cursor loaded.
	// Remarks:   Loads a standard cursor by type.
	// Notes:	
	// See: FRSysSetCursor
	// See: FRSysGetCursor
	//************************************
	static FR_Cursor LoadStandarCursor(FS_INT32 nCursorType);

	//************************************
	// Function:  GetCursor
	// Return:	  The current cursor.
	// Remarks:   Gets the current cursor.
	// Notes:	
	// See: FRSysSetCursor
	// See: FRSysLoadStandarCursor
	//************************************
	static FR_Cursor GetCursor(void);

	//************************************
	// Function:  SetCursor
	// Param[in]: cursor The input cursor to be set.
	// Return:	 void 
	// Remarks:   Sets the current cursor.
	// Notes:
	// See: FRSysGetCursor
	// See: FRSysLoadStandarCursor
	//************************************
	static void	SetCursor(FR_Cursor cursor);

	//************************************
	// Function:  ShowMessageBox
	// Param[in]: wszPrompt			Pointer to a null-terminated string that contains the message to be displayed. 
	// Param[in]: nType				Specifies the contents and behavior of the dialog box. See the description about <Italic>MessageBox</Italic> from MSDN.
	// Param[in]: wszCaption		Pointer to a null-terminated string that contains the dialog box title. If this parameter is NULL, the default title is used.
	// Param[in]: pCheckBoxParams	Pointer to a data structure representing the params of the check box on the message box. If this parameter is NULL, the default value is used.
	// Param[in]: hParent			The parent window.
	// Return: See the description about <Italic>MessageBox</Italic> from <Italic>MSDN</Italic>.
	// Remarks: Creates, displays, and operates a message box. The message box contains an application-defined message 
	// and title, plus any combination of predefined icons and push buttons.
	// Notes:
	//************************************
	static FS_INT32 ShowMessageBox(FS_LPCWSTR wszPrompt, unsigned int nType, FS_LPCWSTR wszCaption, FR_MSGBOX_CHECKBOXPARAMS* pCheckBoxParams, HWND hParent);

	//************************************
	// Function:  InstallDialogSkinTheme
	// Param[in]: hWnd The dialog to install skin theme of <Italic>Foxit Reader</Italic>.
	// Return: <a>True</a> means successful, otherwise not.
	// Remarks: The dialog can install the skin theme of <Italic>Foxit Reader</Italic> to keep the same.
	// Invokes this interface in the <Italic>CReader_Dialog::OnInitDialog</Italic> routine of the dialog.
	// Notes:
	//************************************
	static FS_BOOL InstallDialogSkinTheme(HWND hWnd);

	//************************************
	// Function:  InstallDialogScrollBar
	// Param[in]: hWnd	The dialog to install the scroll bar.
	// Return:  <a>True</a> means successful, otherwise not.
	// Remarks: Installs the dialog scroll bar.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL InstallDialogScrollBar(HWND hWnd);

	//************************************
	// Function:  GetSkinCount
	// Return:  The count of skins for Foxit Reader.
	// Remarks: Gets the count of skins for Foxit Reader.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
	// See:
	//************************************
	static FS_INT32 GetSkinCount();

	//************************************
	// Function:  GetSkinNameByIndex
	// Param[in]: nIndex	The input index.
	// Param[out]: outName	It receives the name of the skin.
	// Return:  void.
	// Remarks: Gets the skin name by index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
	// See:
	//************************************
	static void GetSkinNameByIndex(FS_INT32 nIndex, FS_WideString* outName);

	//************************************
	// Function:  SetActiveSkinByIndex
	// Param[in]: nIndex	The input index.
	// Return:  TRUE for success, otherwise failure.
	// Remarks: Sets the active skin by index.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
	// See:
	//************************************
	static FS_BOOL SetActiveSkinByIndex(FS_INT32 nIndex);

	//************************************
	// Function:  SetActiveSkinByName
	// Param[in]: nIndex	The input name of the skin.
	// Return:  TRUE for success, otherwise failure.
	// Remarks: Sets the active skin by name.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
	// See:
	//************************************
	static FS_BOOL SetActiveSkinByName(FS_LPCWSTR lpwsName);

	//************************************
	// Function:  ShowStopLaunchDlg
	// Param[out]: pbModify			If user modify the setting.
	// Param[in]: lpwsInfo			The description of Safe Mode check button.
	// Param[in]: lpwsCheckSafeMode	The text of Safe Mode check button.
	// Return:  void
	// Remarks: Show the safe mode dialog.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.7.1
	// See:
	//************************************
	static void ShowStopLaunchDlg(FS_BOOL *pbModify, FS_LPCWSTR lpwsInfo, FS_LPCWSTR lpwsCheckSafeMode);

	//************************************
// Function:  ShowMessageBox
// Param[in]: wszPrompt			Pointer to a null-terminated string that contains the message to be displayed. 
// Param[in]: nType				Specifies the contents and behavior of the dialog box. See the description about <Italic>MessageBox</Italic> from MSDN.
// Param[in]: wszCaption		Pointer to a null-terminated string that contains the dialog box title. If this parameter is NULL, the default title is used.
// Param[in]: arCheckBoxParams	FR_MSGBOX_CHECKBOXPARAMS array, Pointer to a data structure representing the params of the check box on the message box. If this parameter is empty, the default value is used.
// Param[in]: bRadioBoxMode		Show radiobox or checkbox.
// Param[in]: hParent			The parent window.
// Return: See the description about <Italic>MessageBox</Italic> from <Italic>MSDN</Italic>.
// Remarks: Creates, displays, and operates a message box. The message box contains an application-defined message 
// and title, plus any combination of predefined icons and push buttons.
// Notes:
//************************************
	static FS_INT32 ShowMessageBox2(FS_LPCWSTR wszPrompt, unsigned int nType, FS_LPCWSTR wszCaption, FS_PtrArray arCheckBoxParams, FS_BOOL bRadioBoxMode, HWND hParent);

	//************************************
// Function:  ShowMessageBox
// Param[in]: wszPrompt			Pointer to a null-terminated string that contains the message to be displayed. 
// Param[in]: buttons			The type of the buttons,FR_MBOK equal to MB_OK
// Param[in]: nType				Specifies the contents and behavior of the dialog box. See the description about <Italic>MessageBox</Italic> from MSDN.
// Param[in]: wszCaption		Pointer to a null-terminated string that contains the dialog box title. If this parameter is NULL, the default title is used.
// Param[in]: arCheckBoxParams	FR_MSGBOX_CHECKBOXPARAMS array, Pointer to a data structure representing the params of the check box on the message box. If this parameter is empty, the default value is used.
// Param[in]: bRadioBoxMode		Show radiobox or checkbox.
// Param[in]: hParent			The parent window.
// Return: See the description about <Italic>MessageBox</Italic> from <Italic>MSDN</Italic>.
// Remarks: Creates, displays, and operates a message box. The message box contains an application-defined message 
// and title, plus any combination of predefined icons and push buttons.
// Notes:
//************************************
	static FS_INT32 ShowMessageBox3(FS_LPCWSTR wszPrompt, FR_MsgBtnType button, FR_MsgType nType, FS_LPCWSTR wszCaption, FR_MSGBOX_CHECKBOXPARAMS2* pCheckBoxParams, FS_HWND hParent);
};

class CFR_WindowsDIB_V5
{
public:
	//************************************
	// Function:  New
	// Param[in]: hDC		The input windows device context.
	// Param[in]: width		The bimtap width.
	// Param[in]: height	The bitmap height.
	// Return: A DIB.
	// Remarks: Constructs a DIB that can be efficiently interact with Windows device.
	// Currently the constructed DIB will always in <a>FS_DIB_Rgb</a> format.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_DIBitmap	New(HDC hDC, FS_INT32 width, FS_INT32 height);

	//************************************
	// Function:  Destroy
	// Param[in]: pBitmap	The input DIB bitmap.
	// Return: void.
	// Remarks: Destroys the input DIB bitmap.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void Destroy(FS_DIBitmap pBitmap);

	//************************************
	// Function:  GetBitmapInfo
	// Param[in]: pBitmap		The input DIB bitmap.
	// Param[out]: outInfo		It receives the windows bitmap info structure for the DIB.
	// Return: void.
	// Remarks: Get Windows bitmap info structure.
	// The result is a binary string that can be used at a <Italic>BITMAPINFO</Italic> structure.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void	GetBitmapInfo(FS_DIBitmap pBitmap, FS_ByteString* outInfo);

	//************************************
	// Function:  LoadFromBuf
	// Param[in]: pbmi		The windows bitmap info structure.
	// Param[in]: pData		The bitmap data.
	// Return: A bitmap from existing data.
	// Remarks: Constructs a bitmap from existing data.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_DIBitmap LoadFromBuf(BITMAPINFO* pbmi, void* pData);

	//************************************
	// Function:  GetDDBitmap
	// Param[in]: pBitmap		The input DIB.
	// Param[in]: hDC			The input DC.
	// Return: A device dependent bitmap compatible with the input DC.
	// Remarks: Converts to device compatible bitmap.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static HBITMAP GetDDBitmap(FS_DIBitmap pBitmap, HDC hDC);

	//************************************
	// Function:  LoadFromDDB
	// Param[in]: hDC		The input DC.
	// Param[in]: hBitmap	The input device dependent bitmap.
	// Param[in]: pPalette	The bmp's palette, applicable to 1bppRgb and 8bppRgb formats.
	// Param[in]: size		The palette's size.
	// Return: A DIB.
	// Remarks: Load DI bitmap from DDB. If <param>hDC</param> is NULL, system display DC will be used.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_DIBitmap LoadFromDDB(HDC hDC, HBITMAP hBitmap, FS_DWORD* pPalette, FS_DWORD size);

	//************************************
	// Function:  LoadFromFile
	// Param[in]: filename		The input full file path.
	// Return: A DIB.
	// Remarks: Load DI bitmap from file. Unicode version. Without GDI+ support, we supports only BMP file.
	// With GDI support, we support much more.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_DIBitmap LoadFromFile(FS_LPCWSTR filename);
	
	//************************************
	// Function:  LoadFromFileII
	// Param[in]: filename		The input full file path.
	// Return: A DIB.
	// Remarks: Load DI bitmap from file. Unicode version. Without GDI+ support, we supports only BMP file.
	// With GDI support, we support much more.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_DIBitmap LoadFromFileII(FS_LPCSTR filename);

	//************************************
	// Function:  LoadDIBitmap
	// Param[in]: args	The input full file path or memory.
	// Return: A DIB.
	// Remarks: Load DI bitmap from file. Unicode version. Without GDI+ support, we supports only BMP file.
	// With GDI support, we support much more.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_DIBitmap LoadDIBitmap(FR_WINDIB_Open_Args args);
	
	//************************************
	// Function:  GetDC
	// Param[in]: pBitmap	The input DIB bitmap.
	// Return: The DC.
	// Remarks: Gets the DC.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static HDC GetDC(FS_DIBitmap pBitmap);

	//************************************
	// Function:  GetWindowsBitmap
	// Param[in]: pBitmap	The input DIB bitmap.
	// Return: The bitmap handle.
	// Remarks: Gets the bitmap.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static HBITMAP GetWindowsBitmap(FS_DIBitmap pBitmap);

	//************************************
	// Function:  LoadFromDevice
	// Param[in]: pBitmap	The input DIB bitmap.
	// Param[in]: hDC		The input windows device context.
	// Param[in]: left		The x-coordinate in the windows DC.
	// Param[in]: top		The y-coordinate in the windows DC.
	// Return: The bitmap.
	// Remarks: Loads from a device.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void LoadFromDevice(FS_DIBitmap pBitmap, HDC hDC, FS_INT32 left, FS_INT32 top);

	//************************************
	// Function:  SetToDevice
	// Param[in]: pBitmap	The input DIB bitmap.
	// Param[in]: hDC		The input windows device context.
	// Param[in]: left		The x-coordinate in the windows DC.
	// Param[in]: top		The y-coordinate in the windows DC.
	// Return: void.
	// Remarks: Outputs to a device.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static void SetToDevice(FS_DIBitmap pBitmap, HDC hDC, FS_INT32 left, FS_INT32 top);
};

class CFR_SystemHandler_V14
{
public:	
	//************************************
	// Function:  IsStandardFont
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[out]: sFontName	   The font name.	
	// Return: FS_BOOLEAN
	// Remarks: Check if it is an standard font.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static	FS_BOOLEAN    IsStandardFont(FR_SystemHandler handler, const FS_ByteString sFontName);
	
	//************************************
	// Function:  GetDefaultFontNameByCharset
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[out]: csFontname	   Get the name of the default font corresponding to charset.	
	// Param[in]: nCharSet	       The input charset.
	// Return: FS_BOOLEAN          TRUE means get success.
	// Remarks: Get the name of the default font corresponding to charset through Charset.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	//************************************
	static	FS_BOOLEAN GetDefaultFontNameByCharset(FR_SystemHandler handler, FS_WideString* csFontname, FS_INT32 nCharSet);

	//************************************
	// Function:  GetFullName
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[out]: csFontName	   Get the name of the default font corresponding to charset.	
	// Param[in]: bBold	           Whether bold.
	// Param[in]: bItalic	       Whether italic.
	// Return: void
	// Remarks: Get the full name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	// Deprecated: Internal use.
	//************************************
	static void GetFullName(FR_SystemHandler handler, FS_ByteString* csFontName, FS_BOOLEAN bBold, FS_BOOLEAN bItalic);

	//************************************
	// Function:  GetNativeTrueTypeFont
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[out]: nCharset	       The input charset.
	// Return: FS_LPCWSTR
	// Remarks: Get the native true type font.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_LPCWSTR GetNativeTrueTypeFont(FR_SystemHandler handler, FS_INT32 nCharset);

	//************************************
	// Function:  FindNativeTrueTypeFont
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[in]: nCharset	       The input charset.
	// Param[in]: wsFontFaceName   The input font face name.
	// Return: FS_BOOLEAN         true: find suceess.
	// Remarks: Find native true type font.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN FindNativeTrueTypeFont(FR_SystemHandler handler, FS_INT32 nCharset, FS_LPCWSTR wsFontFaceName);

	//************************************
	// Function:  GetFontCharset
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[in]: cwFontFaceName   The input font face name.
	// Param[out]: charset         Get the charset.
	// Return: FS_BOOLEAN         true: get suceess.
	// Remarks: Get the font charset.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN GetFontCharset(FR_SystemHandler handler, FS_LPCWSTR cwFontFaceName, FS_INT32* charset);

	//************************************
	// Function:  ConvertToFWLVitrualKeyCode
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[in]: nChar            The input char code of key.
	// Param[in]: bOnChar          If it's windows key code.
	// Return: FS_DWORD
	// Remarks: Convert key info.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_DWORD	ConvertToFWLVitrualKeyCode(FR_SystemHandler handler, FS_DWORD nChar, FS_BOOL bOnChar);

	//************************************
	// Function:  CreatePopupMenu
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[in]: hWnd             The input HWND.
	// Return: FS_LPVOID  Return the popup menu.
	// Remarks: Create popup menu.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID CreatePopupMenu(FR_SystemHandler handler, FS_LPVOID hWnd);

	//************************************
	// Function:  AppendMenuItem
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[in]: hMenu            The input HMENU need to append item.
	// Param[in]: nIDNewItem       The input new item id.
	// Param[in]: str              The input info of the item.
	// Return: FS_LPVOID   true: append success.
	// Remarks: Append menu item.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	AppendMenuItem(FR_SystemHandler handler, FS_LPVOID hMenu, FS_INT32 nIDNewItem, FS_LPCWSTR str);

	//************************************
	// Function:  EnableMenuItem
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[in]: hMenu            The input HMENU.
	// Param[in]: nIDItem          The input menu item id.
	// Param[in]: bEnabled         Set the enable state.
	// Return: FS_BOOLEAN   true: set enable status success.
	// Remarks: Enable menu item.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	EnableMenuItem(FR_SystemHandler handler, FS_LPVOID hMenu, FS_INT32 nIDItem, FS_BOOLEAN bEnabled);

	//************************************
	// Function:  TrackPopupMenu
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[in]: hMenu            The input HMENU.
	// Param[in]: x                The x postion of the menu.
	// Param[in]: y                The x postion of the menu.
	// Param[in]: hParent          The input parent HAND.
	// Return: FS_INT32   Return the commid id.
	// Remarks: Track popup menu.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_INT32		TrackPopupMenu(FR_SystemHandler handler, FS_LPVOID hMenu, FS_INT32 x, FS_INT32 y, FS_LPVOID hParent);

	//************************************
	// Function:  DestroyMenu
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[in]: hMenu            The input HMENU.	
	// Return: void
	// Remarks: Destroy menu.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void			DestroyMenu(FR_SystemHandler handler, FS_LPVOID hMenu);

	//************************************
	// Function:  CreatePopupSubMenu
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Return: FS_LPVOID
	// Remarks: Create popup sub menu.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_LPVOID	CreatePopupSubMenu(FR_SystemHandler handler);

	//************************************
	// Function:  AppendSubMenu
	// Param[in]: handler		   The input system handler,it get from FRAppGetSystemHandler.	
	// Param[in]: hMenu            The input HMENU.
	// Param[in]: hSubMenu         The input sub menu.
	// Param[in]: str              The input sub menu info.
	// Return: FS_BOOLEAN  true: append sub menu success.
	// Remarks: Appen sub menu.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	// Deprecated: Internal use.
	//************************************
	static FS_BOOLEAN	AppendSubMenu(FR_SystemHandler handler, FS_LPVOID hMenu, FS_LPVOID hSubMenu, FS_LPCWSTR str);

	//************************************
	// Function:  SetCursor
	// Param[in]: handler           The input system handler
	// Param[out]: nCursorType
	// Param[out]: hWnd
	// Return: void
	// Remarks: Set Cursor.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void SetCursor(FR_SystemHandler handler, FR_CURSORSTYLE nCursorType, FS_HWND hWnd);

	//************************************
	// Function:  SetCustomCursorHandler
	// Param[in]: handler           The input system handler
	// Param[out]: pCustomCursorHandler The input custom cursor handler.
	// Return: void
	// Remarks: Set custom cursor handler.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
	// Deprecated: Internal use.
	//************************************
	static void	SetCustomCursorHandler(FR_SystemHandler handler, FPD_CustomCursorHandler pCustomCursorHandler);
};

class CFR_CTBLogFonts_V14
{
public:
	//************************************
	// Function:  New	
	// Return: FR_CTBLogFonts
	// Remarks: Create FR_CTBLogFonts object, that used vector to manage logfont in APP.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_CTBLogFonts  New();

	//************************************
	// Function:  Destroy	
	// Param[in]: font		   The FR_CTBLogFonts object.	
	// Return: void
	// Remarks: Release FR_CTBLogFonts object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void   Destroy(FR_CTBLogFonts font);

	//************************************
	// Function:  GetSize	
	// Param[in]: font		   The FR_CTBLogFonts object.	
	// Return: FS_INT32
	// Remarks: Get the size of LogFonts.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_INT32 GetSize(FR_CTBLogFonts font);

	//************************************
	// Function:  GetAt	
	// Param[in]: font		   The FR_CTBLogFonts object.	
	// Param[in]: index		   The index of logfonts vector.
	// Return: FS_FONT*
	// Remarks: Get the index of LogFonts.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_FONT* GetAt(FR_CTBLogFonts font, FS_INT32 index);

	//************************************
	// Function:  Add	
	// Param[in]: font		   The FR_CTBLogFonts object.	
	// Param[in]: pLogFont	   The font need to add.	
	// Return: FS_INT32
	// Remarks: Add font to LogFonts.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void Add(FR_CTBLogFonts font, FS_FONT pLogFont);
};


class CFR_TBSYSFONTDATA_V14
{
public:	
	//************************************
	// Function:  Create		
	// Return: FR_TB_SYSFONTDATA
	// Remarks: Create FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_TB_SYSFONTDATA Create();

	//************************************
	// Function:  Destroy		
	// Param[in]:	data		   The input FR_TB_SYSFONTDATA object.
	// Return: void
	// Remarks: Destroy FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void Destroy(FR_TB_SYSFONTDATA data);

	//************************************
	// Function:  SetFaceName		
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[in]:	faceName	   The face name.
	// Return: void
	// Remarks: Set face name for  FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void SetFaceName(FR_TB_SYSFONTDATA data, FS_WideString faceName);

	//************************************
	// Function:  GetFaceName	
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[out]:	outfaceName	   Get the face name.
	// Return: void
	// Remarks: Get face name for FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void GetFaceName(FR_TB_SYSFONTDATA data, FS_WideString* outfaceName);

	//************************************
	// Function:  SetScriptName		
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[in]:	scriptName	   The script name.
	// Return: void
	// Remarks: Set script name for FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void SetScriptName(FR_TB_SYSFONTDATA data, FS_WideString scriptName);

	//************************************
	// Function:  GetScriptName		
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[out]:	outscriptName  Get the script name.
	// Return: void
	// Remarks: Get script name for FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void GetScriptName(FR_TB_SYSFONTDATA data, FS_WideString* outscriptName);

	//************************************
	// Function:  SetTagName	
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[in]:	tagName		   The tag name.
	// Return: void
	// Remarks: Set tag name for FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void SetTagName(FR_TB_SYSFONTDATA data, FS_WideString tagName);

	//************************************
	// Function:  GetTagName	
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[out]:	outtagName	   get the tag name.
	// Return: void
	// Remarks: Get tag name for FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void GetTagName(FR_TB_SYSFONTDATA data, FS_WideString* outtagName);

	//************************************
	// Function:  SetFullName	
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[in]:	fullName	   The full name.
	// Return: void
	// Remarks: Set full name for FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void SetFullName(FR_TB_SYSFONTDATA data, FS_WideString fullName);

	//************************************
	// Function:  GetFullName	
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[out]:	outfullName	   Get the full name.
	// Return: void
	// Remarks: Get full name for FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void GetFullName(FR_TB_SYSFONTDATA data, FS_WideString* outfullName);

	//************************************
	// Function:  SetPSName		
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[in]:	PSName		   The ps name.
	// Return: void
	// Remarks: Set ps name for FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void SetPSName(FR_TB_SYSFONTDATA data, FS_WideString PSName);

	//************************************
	// Function:  GetPSName		
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[out]:	outPSName		get the ps name.
	// Return: void
	// Remarks: Get ps name for FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void GetPSName(FR_TB_SYSFONTDATA data, FS_WideString* outPSName);

	//************************************
	// Function:  SetNamesArr		
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[in]: namesArr		   names arr.	
	// Return: void
	// Remarks: Set name arr for FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void SetNamesArr(FR_TB_SYSFONTDATA data, FS_WideStringArray namesArr);

	//************************************
	// Function:  GetNamesArr	
	// Param[in]:	data		   The FR_TB_SYSFONTDATA object.	
	// Param[out]: outnamesArr	   names arr.	
	// Return: void
	// Remarks: Get name arr for FR_TB_SYSFONTDATA object.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void GetNamesArr(FR_TB_SYSFONTDATA data, FS_WideStringArray* outnamesArr);
};

class CFR_ITBSysFont_V14
{
public:
	//************************************
	// Function:  GetSysFontObject		
	// Return: FR_ITBSysFont
	// Remarks: Get FR_ITBSysFont object from APP.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FR_ITBSysFont GetSysFontObject();

	//************************************
	// Function:  LoadLogFonts	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[in]: swFaceName	   The font face name.	
	// Param[out]: fontarray	   Load LogFonts.	
	// Return: void
	// Remarks: Load fonts.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void		     LoadLogFonts(FR_ITBSysFont sysFont, const FS_LPCWSTR swFaceName, FR_CTBLogFonts* fontarray);

	//************************************
	// Function:  GetSysFontFaceName	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[in]: lpwsScriptName   The script name.	
	// Param[out]: outName	       Get the face name..	
	// Return: FS_BOOL
	// Remarks: Get system font face name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOL GetSysFontFaceName(FR_ITBSysFont sysFont, FS_LPCWSTR lpwsScriptName, FS_WideString* outName);

	//************************************
	// Function:  GetAllFormatFontSize	
	// Param[in]: sysFont		   The FR_ITBSysFont object.		
	// Return: FS_INT32
	// Remarks: Get the cout of font size.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_INT32 GetAllFormatFontSize(FR_ITBSysFont sysFont);

	//************************************
	// Function:  GetAtAllFormatFont	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[in]: index		       The index of sysfont.	
	// Param[out]: sFaceName	   Get the face name.	
	// Return: void
	// Remarks: Get the index of format font.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void GetAtAllFormatFont(FR_ITBSysFont sysFont, FS_INT32 index, FS_WideString* sFaceName);

	//************************************
	// Function:  GetFontFaceNameBoldItalic	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[in]: sFontName		   The font name.	
	// Param[out]: sFaceName	   Get the face name.	
	// Param[out]: bBold		   Get the font is Bold.	
	// Param[out]: bItalic		   Get the font is Italic.
	// Return: void
	// Remarks: Get font facename, Bold, Italic of the font.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void GetFontFaceNameBoldItalic(FR_ITBSysFont sysFont, const FS_WideString& sFontName, FS_WideString* sFaceName, FS_BOOL* bBold, FS_BOOL* bItalic);

	//************************************
	// Function:  GetStdFontSize	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Return: FS_INT32
	// Remarks: Get fontsize of the standard font.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_INT32			GetStdFontSize(FR_ITBSysFont sysFont);

	//************************************
	// Function:  GetAtStdFont	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[in]: index		       The index of the standard font.	
	// Param[out]: sFaceName	   Get the face name of the standard font.		
	// Return: void
	// Remarks: Get font facename, Bold, Italic of the font.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static	void			GetAtStdFont(FR_ITBSysFont sysFont, FS_INT32 index, FS_WideString sFaceName);

	//************************************
	// Function:  GetAtStdFont	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[in]: index		       The index of the standard font.	
	// Param[out]: outdata	       Get the SYSFONTDATA of the standard font. That need to call FRTBSYSFONTDATACreate first.		
	// Return: void  
	// Remarks: Get font facename, Bold, Italic of the font.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static	void			GetAtStdFont2(FR_ITBSysFont sysFont, FS_INT32 index, FR_TB_SYSFONTDATA* outdata);

	//************************************
	// Function:  IsStandardFont	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[in]: sFontName		   The input font name.	
	// Return: FS_BOOLEAN  
	// Remarks: Check if it is standard font.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static FS_BOOLEAN		IsStandardFont(FR_ITBSysFont sysFont, FS_LPCWSTR sFontName);

	//************************************
	// Function:  GetScriptName	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[in]: swFaceName	   The input face name.	
	// Param[in]: bRemoveSymbol	   Whether to remove symbol.
	// Return: void  
	// Remarks: Get script name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	//************************************
	static void	GetScriptName(FR_ITBSysFont sysFont, FS_LPCWSTR swFaceName, FS_BOOLEAN bRemoveSymbol, FS_WideString* outScriptName);

	//************************************
	// Function:  FontNamePDF2Name	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[in]: pdfName	       The input pdf name.	
	// Param[out]: winName	       Get the system font name.
	// Return: void  
	// Remarks: Get the system font name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void FontNamePDF2Name(FR_ITBSysFont sysFont, FS_LPCWSTR pdfName, FS_WideString* winName);

	//************************************
	// Function:  GetCharsetByFontName	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[out]: nCharSet	       Get the charset.	
	// Param[in]: sFontName	       The input font name.
	// Return: void  
	// Remarks: Get the charset by font name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void	GetCharsetByFontName(FR_ITBSysFont sysFont, FS_INT32* nCharSet, FS_LPCWSTR sFontName);

	//************************************
	// Function:  GetBaseFontName	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[in]: pFont	           The input FPD_Font.
	// Param[out]: outFontName	   Get base font name.
	// Return: void  
	// Remarks: Get base font name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void GetBaseFontName(FR_ITBSysFont sysFont, FPD_Font pFont, FS_WideString* outFontName);

	//************************************
	// Function:  GetFullName	
	// Param[in]: sysFont		   The FR_ITBSysFont object.	
	// Param[in]: swBaseFontName   The input base font name.
	// Param[in]: bRemoveSymbol    Whether to remove symbol, default is true.
	// Param[out]: outFullName	   Get the full name.
	// Return: void  
	// Remarks: Get the full font name.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0.0
	//************************************
	static void	GetFullName(FR_ITBSysFont sysFont, const FS_LPCWSTR swBaseFontName, FS_BOOLEAN bRemoveSymbol, FS_WideString* outFullName);
};

#ifdef __cplusplus
};
#endif
#endif

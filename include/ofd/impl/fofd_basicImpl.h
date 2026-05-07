#ifndef FOFD_BASICIMPL_H
#define FOFD_BASICIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FOFD_BASICEXPT_H
#include "../fofd_basicExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/************************************************************************/
/*                      CryptoDictionary                                */
/************************************************************************/

class CFOFD_CryptoDict_V10
{
public:
	
};

/************************************************************************/
/*                      SecurityHandler                                 */
/************************************************************************/
class CFOFD_SecurityHandler_V10
{
public:
	
};

class CFOFD_StdSecurityHandler_V10
{
public:
	
};

class CFOFD_StdCertSecurityHandler_V10
{
public:
	
};

class CFOFD_SMSecurityHandler_V10
{
public:
	
};

/************************************************************************/
/*                      CryptoHandler                                   */
/************************************************************************/
class CFOFD_CryptoHandler_V10
{
public:
	
};

class CFOFD_StdCryptoHandler_V10
{
public:
	
};

class CFOFD_SM4CryptoHandler_V10
{
public:
	
};

//////////////////////////////////////////////////////////////////////////
class CFOFD_FileStream_V10
{
public:
	
};

//////////////////////////////////////////////////////////////////////////
#ifndef COFD_CUSTOMERPAUSE
#define COFD_CUSTOMERPAUSE
class COFD_CustomerPauseHandler : public IFX_Pause, public CFX_Object
{
public:
	COFD_CustomerPauseHandler(OFD_Pause pause);
	virtual FX_BOOL	NeedToPauseNow();
private:
	OFD_Pause m_pause;
};
#endif

//////////////////////////////////////////////////////////////////////////
//class CFOFD_PauseHandler_V10

class CFOFD_PauseHandler_V10
{
public:
	//************************************
	// Function: Create
	// Param[in]: pause		The input pause handler structure.
	// Return:   The newly created pause handler.
	// Remarks:  Creates the pause handler.
	// Notes:
	//************************************
	static FOFD_PauseHandler	Create(OFD_Pause pause);

	//************************************
	// Function: Destroy
	// Param[in]: pauseHandler		The input pause handler to be destroyed.
	// Return:   void
	// Remarks:  Destroys the pause handler.
	// Notes:
	//************************************
	static void	Destroy(FOFD_PauseHandler pauseHandler);
};

class CFOFD_UIMgr_V10
{
public:
	static void				SetPanelIndex(FR_PanelMgr panelMgr, FS_LPCSTR csName, FS_INT32 nInitialIndex);
	static void				TriggerPanel(FR_PanelMgr pPanelMgr, FS_ByteString bsName);
	static void				FormatComboBox(FS_WideString csText, FS_INT32 nType, FS_WideString* out);
	static void				ShowAutoHideStatusBar(BOOL bShow, int nOffset_X, int nOffset_Y);
};

class CFOFD_DIBAttribute_V10
{
public:
	static FOFD_DIBAttribute			Create();

	static FS_INT32						GetXDPI(FOFD_DIBAttribute attr);
	static void							SetXDPI(FOFD_DIBAttribute attr, FS_INT32 value);

	static FS_INT32						GetYDPI(FOFD_DIBAttribute attr);
	static void							SetYDPI(FOFD_DIBAttribute attr, FS_INT32 value);
	
	static FS_FLOAT						GetAspectRatio(FOFD_DIBAttribute attr);
	static void							SetAspectRatio(FOFD_DIBAttribute attr, FS_FLOAT value);

	static FS_DWORD						GetDPIUnit(FOFD_DIBAttribute attr);
	static void							SetDPIUnit(FOFD_DIBAttribute attr, FS_DWORD value);

	static void							GetAuthor(FOFD_DIBAttribute attr, FS_ByteString* out);
	static void							SetAuthor(FOFD_DIBAttribute attr, FS_ByteString value);

	static FS_LPBYTE					GetTime(FOFD_DIBAttribute attr);
	static void							SetTime(FOFD_DIBAttribute attr, FS_LPBYTE value);

	static FS_INT32						GetGifLeft(FOFD_DIBAttribute attr);
	static void							SetGifLeft(FOFD_DIBAttribute attr, FS_INT32 value);

	static FS_INT32						GetGifTop(FOFD_DIBAttribute attr);
	static void							SetGifTop(FOFD_DIBAttribute attr, FS_INT32 value);

	static FS_DWORD*					GetGifLocalPalette(FOFD_DIBAttribute attr);
	static void							SetGifLocalPalette(FOFD_DIBAttribute attr, FS_DWORD* value);

	static FS_DWORD						GetGifLocalPalNum(FOFD_DIBAttribute attr);
	static void							SetGifLocalPalNum(FOFD_DIBAttribute attr, FS_DWORD value);

	static FS_INT32						GetBmpCompressType(FOFD_DIBAttribute attr);
	static void							SetBmpCompressType(FOFD_DIBAttribute attr, FS_INT32 value);

	static FS_DWORD						GetTiffFrameCompressType(FOFD_DIBAttribute attr);
	static void							SetTiffFrameCompressType(FOFD_DIBAttribute attr, FS_DWORD value);

	static FS_DWORD						GetTiffFrameCompressOptions(FOFD_DIBAttribute attr);
	static void							SetTiffFrameCompressOptions(FOFD_DIBAttribute attr, FS_DWORD value);

	static FS_INT32						GetTiffFrameFillOrder(FOFD_DIBAttribute attr);
	static void							SetTiffFrameFillOrder(FOFD_DIBAttribute attr, FS_INT32 value);

	static FS_DWORD						GetTiffFrameCompressJpegQuality(FOFD_DIBAttribute attr);
	static void							SetTiffFrameCompressJpegQuality(FOFD_DIBAttribute attr, FS_DWORD value);
};

class CFOFD_CodeC_V10
{
public:
	static FS_BOOL						PngEncode(FS_DIBitmap pSource, FS_LPCWSTR file_name, FS_BOOL bInterlace, FOFD_DIBAttribute pAttribute);

};

class CFOFD_PrintSetting_V10
{
public:
	static FS_INT32						GetGlobalUnit();
	static void							GetDefaultPrinterName(FS_WideString* out);
	static DEVMODE*						GetDefaultPrinterDevMode();
	static void							SetDefaultPrinterDevMode(HANDLE hDevNames, HANDLE hDevMode);
	static FS_BOOL						IsPrintUseGraphics();
};

class CFOFD_Sys_V10
{
public:
	
};

class CFOFD_Fontmapper_V14
{
public:
	
};


#ifdef __cplusplus
};
#endif

#endif//FOFD_BASICIMPL_H

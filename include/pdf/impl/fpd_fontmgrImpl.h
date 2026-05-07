#ifndef FPD_FONTMGRIMPL_H
#define FPD_FONTMGRIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifndef FPD_FONTMGREXPT_H
#include "../fpd_fontmgrExpt.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


	class CFPD_FMFontMgr_V17
	{
	public:
		//************************************
		// Function:  GetCodePageFromCharset
		// Param[in]: charset		    The input charset, like FPDFM_CHARSET_xx.
		// Return:    FS_WORD
		// Remarks:  Get code page from charset.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************	
		static FS_WORD	GetCodePageFromCharset(FS_BYTE charset);

		//************************************
		// Function:  GetFromGE		
		// Return:    FPD_FMFontMgr
		// Remarks:  Get FPD_FMFontMgr from ge module.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static FPD_FMFontMgr Get();		
	
		//************************************
		// Function:  SetPlatformLanguage	
		// Param[in]: fontMgr		    The input FPD_FMFontMgr object.
		// Param[in]: language		    The input language ID, like FPDXM_LANGUAGE_xx.
		// Return:    void
		// Remarks:  Set the platform and language information.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void	SetPlatformLanguage(FPD_FMFontMgr fontMgr, FS_INT32 language);
		
		//************************************
		// Function:  LoadSystemFonts	
		// Param[in]: fontMgr		    The input FPD_FMFontMgr object.		
		// Return:    void
		// Remarks:  Load the system fonts.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void	LoadSystemFonts(FPD_FMFontMgr fontMgr);

		//************************************
		// Function:  GetFontDescArray	
		// Param[in]: fontMgr		    The input FPD_FMFontMgr object.		
		// Param[out]: fontDesArray		Get the FPD_FMFontDescriptor object array.
		// Return:    void
		// Remarks:  Load the system fonts.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static FS_BOOL	GetFontDescArray(FPD_FMFontMgr fontMgr, FS_PtrArray* fontDesArray);
	};

	class CFPD_FMFontDescriptor_V17
	{
	public:
		//************************************
		// Function:  Create		
		// Return:    FPD_FMFontDescriptor
		// Remarks:  Create FPD_FMFontDescriptor obj.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static FPD_FMFontDescriptor Create();

		//************************************
		// Function:  Delete	
		// Param[in]: descriptor		The input FPD_FMFontDescriptor object.	
		// Return:    void
		// Remarks:  Release FPD_FMFontDescriptor object.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void Delete(FPD_FMFontDescriptor descriptor);

		//************************************
		// Function:  GetFamiliyName	
		// Param[in]: descriptor		The input FPD_FMFontDescriptor object.
		// Param[out]: name		        Get family name.		
		// Return:    void
		// Remarks:  Get family name.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void GetFamiliyName(FPD_FMFontDescriptor descriptor, FS_WideString* name);

		//************************************
		// Function:  SetFamiliyName	
		// Param[in]: descriptor		The input FPD_FMFontDescriptor object.
		// Param[in]: name		        The input family name.		
		// Return:    void
		// Remarks: Set family name.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void SetFamiliyName(FPD_FMFontDescriptor descriptor, FS_LPCWSTR name);

		//************************************
		// Function:  GetPostscriptName	
		// Param[in]: descriptor		The input FPD_FMFontDescriptor object.
		// Param[out]: name		        Get Postscript name.		
		// Return:    void
		// Remarks: Get Postscript name.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void GetPostscriptName(FPD_FMFontDescriptor descriptor, FS_WideString* name);

		//************************************
		// Function:  SetPostscriptName	
		// Param[in]: descriptor		The input FPD_FMFontDescriptor object.
		// Param[in]: name		        The input Postscript name.		
		// Return:    void
		// Remarks: Set Postscript name.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void SetPostscriptName(FPD_FMFontDescriptor descriptor, FS_LPCWSTR name);

		//************************************
		// Function:  GetFullName	
		// Param[in]: descriptor		The input FPD_FMFontDescriptor object.
		// Param[out]: name		        Get local full font name.	
		// Return:    void
		// Remarks: Get local full font name.	
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void GetFullName(FPD_FMFontDescriptor descriptor, FS_WideString* name);

		//************************************
		// Function:  SetFullName	
		// Param[in]: descriptor		The input FPD_FMFontDescriptor object.
		// Param[in]: name		        Set local full font name.	
		// Return:    void
		// Remarks: Set local full font name.	
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void SetFullName(FPD_FMFontDescriptor descriptor, FS_LPCWSTR name);

		//************************************
		// Function:  GetBsFamilyName	
		// Param[in]: descriptor		The input FPD_FMFontDescriptor object.
		// Param[out]: name		        Get font family name, UTF-8 string.
		// Return:    void
		// Remarks: Get font family name, UTF-8 string.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void GetBsFamilyName(FPD_FMFontDescriptor descriptor, FS_ByteString* name);

		//************************************
		// Function:  SetBsFamilyName	
		// Param[in]: descriptor		The input FPD_FMFontDescriptor object.
		// Param[in]: name		        Set font family name, UTF-8 string.
		// Return:    void
		// Remarks: Set font family name, UTF-8 string.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void SetBsFamilyName(FPD_FMFontDescriptor descriptor, FS_LPCSTR name);

		//************************************
		// Function:  GetCharset	
		// Param[in]: descriptor		    The input FPD_FMFontMgr object.
		// Return:    FS_DWORD, like  FPDFM_CHARSET_.
		// Remarks: Get the charset.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.1.0.0
		//************************************
		static FS_DWORD GetCharset(FPD_FMFontDescriptor descriptor);		
	};

#ifdef __cplusplus
};
#endif

#endif
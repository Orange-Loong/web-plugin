/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fs_basicExpT.h
		
 - Types, macros, structures, etc. 

*********************************************************************/

/**
 * @defgroup FSLayer Foxit Support Layer
 */

/*@{*/

/**
 * @addtogroup FSBASIC
 * @{
 */

/**
 * @file
 * @brief Basic data types
 */

#ifndef FS_BASICEXPT_H
#define FS_BASICEXPT_H


/**
 * @name OS Defines
 */
/*@{*/

/** @brief Windows desktop OS (from Windows 95) */
#define _FS_WIN32_DESKTOP_		1
/** @brief Windows Mobile OS (from Windows CE 4.0) */
#define _FS_WIN32_MOBILE_		2
/** @brief Windows 64 bit */
#define _FS_WIN64_				3
/** @brief Linux Desktop OS */
#define _FS_LINUX_DESKTOP_		4
/** @brief Embedded Linux OS */
#define _FS_LINUX_EMBEDDED_		5
/** @brief Symbian OS (from 7.0) */
#define _FS_SYMBIAN_			6
/** @brief MAC OS X */
#define _FS_MACOSX_				7
/** @brief Embedded OS */
#define _FS_EMBEDDED_			8
/** @brief Solaris 8 or later */
#define _FS_SOLARIS_			9
/** @brief PalmOS (5.0 or later) */
#define _FS_PALMOS_				10
#define _FS_NETBSD_				11
#define _FS_ANDROID_			12
#define _FS_VXWORKS_			13
#define _FS_MTK_				14

/*@}*/ 

/* OS */
#ifndef _FS_OS_
	#if defined(__SYMBIAN32__) || defined(__symbian__)
		#define _FS_OS_ _FS_SYMBIAN_
	#elif defined(_WIN32_WCE)
		#define _FS_OS_ _FS_WIN32_MOBILE_
	#elif defined(__linux__)
		#ifdef __arm__
			#define _FS_OS_ _FS_LINUX_EMBEDDED_
		#else
			#define _FS_OS_ _FS_LINUX_DESKTOP_
		#endif
	#elif defined(__NetBSD__)
		#define _FS_OS_ _FS_NETBSD_
	#elif defined(_WIN64)
		#define _FS_OS_ _FS_WIN64_
	#elif defined(_WIN32)
		/**
		 * @brief Current OS.
		 *
		 * Now it can be:
		 * - #_FS_WIN32_DESKTOP_
		 * - #_FS_WIN32_MOBILE_
		 * - #_FS_WIN64_
		 * - #_FS_LINUX_DESKTOP_
		 * - #_FS_LINUX_EMBEDDED_
		 * - #_FS_SYMBIAN_
		 * - #_FS_MACOSX_
		 * - #_FS_EMBEDDED_
		 * - #_FS_SOLARIS_
		 * - #_FS_PALMOS_
		 *
		 * @hideinitializer
		 */
		#define _FS_OS_ _FS_WIN32_DESKTOP_
	#elif defined(__sparc__)
		#define _FS_OS_ _FS_SOLARIS_
	#elif defined(__ARMCC_VERSION) || defined(__ICCARM__) || defined(__TMS470__)
		#define _FS_OS_ _FS_EMBEDDED_
	#elif defined(__APPLE__)
		#define _FS_OS_ _FS_MACOSX_
	#elif defined(__ARM_EABI__)
		#define _FS_OS_ _FS_EMBEDDED_
	#endif
#endif	/* !_FS_OS_ */

#if !defined(_FS_OS_) || _FS_OS_ == 0
	#error Sorry, can not figure out what OS you are targeting to. Please specify _FS_OS_ macro.
#endif

/**
 * @name Compiler Defines
 */
/*@{*/

/** @brief Microsoft Visual C++ 6.0 */
#define _FS_VC6_		1
/** @brief Microsoft Visual Studio.Net 2003 */
#define _FS_VC7_		2
/** @brief Microsoft Visual Studio.Net 2005 */
#define _FS_VC8_		3
/** @brief GNU C++ Compiler */
#define _FS_GCC_		4
/** @brief ADS 1.2 Compiler */
#define _FS_ADS_		5
/** @brief RVCT 2.1 Compiler */
#define _FS_RVCT_		6
/** @brief IAR C/C++ Compiler */
#define _FS_IARCC_		7
/** @brief Nokia X86 Compiler */
#define _FS_NOKIA_X86_	8
/** @brief Metrowerks C/C++ Compiler (with MSL) */
#define _FS_METROWERKS_	9
/** @brief Protein C/C++ Compiler (used by PalmOS) */
#define _FS_PACC_		10
/** @brief TMS470 */
#define _FS_TMS470_		11
/** @brief MIPS SDE */
#define _FS_MIPS_SDE_	12

/*@}*/ 

/* Compiler */
#ifndef _FS_COMPILER_
	#ifdef _MSC_VER
		#if _MSC_VER >= 1400
			#define _FS_COMPILER_ _FS_VC8_
		#elif _MSC_VER >= 1300
			#define _FS_COMPILER_ _FS_VC7_
		#else
			/**
			 * @brief Current Compiler.
			 *
			 * Now it can be:
			 * - #_FS_VC6_
			 * - #_FS_VC7_
			 * - #_FS_VC8_
			 * - #_FS_GCC_
			 * - #_FS_ADS_
			 * - #_FS_RVCT_
			 * - #_FS_IARCC_
			 * - #_FS_NOKIA_X86_
			 * - #_FS_METROWERKS_
			 * - #_FS_PACC_
			 * - #_FS_TMS470_
			 * - #_FS_MIPS_SDE_
			 *
			 * @hideinitializer
			 */
			#define _FS_COMPILER_ _FS_VC6_
		#endif
	#elif defined(__GNUC__)
		#define _FS_COMPILER_ _FS_GCC_
	#elif defined(__ARMCC_VERSION)
		#if __ARMCC_VERSION < 200000
			#define _FS_COMPILER_ _FS_ADS_
		#else
			#define _FS_COMPILER_ _FS_RVCT_
		#endif
	#elif defined(__ICCARM__)
		#define _FS_COMPILER_ _FS_IARCC_
	#elif defined(_PACC_VER)
		#define _FS_COMPILER_ _FS_PACC_
	#elif defined(__TMS470__)
		#define _FS_COMPILER_ _FS_TMS470_
	#endif
#endif	/* !_FS_COMPILER_ */

#if !defined(_FS_COMPILER_) || _FS_COMPILER_ == 0
	#error Sorry, can not figure out what compiler you are using. Please specify _FS_COMPILER_ macro.
#endif

/**
 * @name CPU Defines
 */
/*@{*/

/** @brief 32-bit x86 CPU */
#define _FS_X86_		1
/** @brief ARM */
#define _FS_ARM_		2
/** @brief Power PCPower PC */
#define _FS_POWERPC_	3
/** @brief Sparc */
#define _FS_SPARC_		4
/** @brief IA64 */
#define _FS_IA64_		5
/** @brief MIPS */
#define _FS_MIPS_		6
/** @brief 64-bit x86 CPU */
#define _FS_X64_		7
/** @brief ARM64 */
#define _FS_ARM64_      8
/** @brief MIPS64 */
#define _FS_MIPS64_		9
/** @brief Loongarch64 */
#define _FS_LOONGARCH64_		10

/*@}*/ 

/* CPU */
#ifndef _FS_CPU_
	#if defined(__arm__) || defined(ARM) || defined(_ARM_) || defined(__ARMCC_VERSION) || defined(__ICCARM__) || defined(__arm) || defined(arm9)
		#define _FS_CPU_ _FS_ARM_
	#elif defined(__arm64) || defined(__arm64__) || defined(__aarch64__) || defined(_ARM64_) || defined(_M_ARM64)
		#define _FS_CPU_ _FS_ARM64_
	#elif defined(_M_IX86) || defined(__i386__)
		/**
		* @brief Current CPU.
		*
		* Now it can be:
		* - #_FS_X86_
		* - #_FS_ARM_
		* - #_FS_POWERPC_
		* - #_FS_SPARC_
		* - #_FS_IA64_
		* - #_FS_MIPS_
		* - #_FS_X64_
		* - #_FS_MIPS_
		*
		* @hideinitializer
		*/
		#define _FS_CPU_ _FS_X86_
	#elif defined(_M_X64) || defined(__x86_64__)
		#define _FS_CPU_ _FS_X64_
	#elif defined(_M_IA64)
		#define _FS_CPU_ _FS_IA64_
	#elif defined(__POWERPC__)
		#define _FS_CPU_ _FS_POWERPC_
	#elif defined(__sparc__)
		#define _FS_CPU_ _FS_SPARC_
	#elif defined(__mips64)
		#define _FS_CPU_ _FS_MIPS64_
	#elif defined(__loongarch64)
		#define _FS_CPU_ _FS_LOONGARCH64_
	#elif defined(MIPS) || defined(_MIPS_) || defined(__mips)
		#define _FS_CPU_ _FS_MIPS_
	#endif
#endif

#if !defined(_FS_CPU_) || _FS_CPU_ == 0
	#error Sorry, can not figure out what CPU you are targeting to. Please specify _FS_CPU_ macro.
#endif

/**
 * @name Byte Order Defines
 */
/*@{*/

/** @brief big endian */
#define _FS_BIG_ENDIAN_		1
/** @brief little endian */
#define _FS_LITTLE_ENDIAN_	2

/*@}*/

/* Byte Order */
#ifndef _FS_ENDIAN_
	#if _FS_CPU_ == _FS_POWERPC_ || _FS_CPU_ == _FS_SPARC_
		#define _FS_ENDIAN_ _FS_BIG_ENDIAN_
	#else
		/**
		 * @brief Current Byte Order.
		 *
		 * Now it can be:
		 * - #_FS_BIG_ENDIAN_
		 * - #_FS_LITTLE_ENDIAN_
		 *
		 * @hideinitializer
		 */
		#define _FS_ENDIAN_ _FS_LITTLE_ENDIAN_
	#endif
#endif

#if _FS_COMPILER_ == _FS_ADS_ || _FS_COMPILER_ == _FS_RVCT_	|| _FS_COMPILER_ == _FS_TMS470_ || _FS_OS_ == _FS_ANDROID_
	#define _FS_NO_EXCEPTION_
	#define _FS_NO_NAMESPACE_
#endif

/**
 * @name Target Defines
 */
/*@{*/

/** @brief The default sdk information */
#define _FS_DEFAULT_TARGET_		0
/** @brief Brew SDK */
#define _FS_BREW_				1

/*@}*/

/* Include basic headers */
#include <stddef.h>
#include <stdarg.h>
#ifndef _FS_NO_ANSIC_
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <assert.h>
	#if _FS_OS_ != _FS_VXWORKS_ && _FS_OS_ != _FS_ANDROID_ && ((_FS_COMPILER_ == _FS_GCC_ && _FS_OS_ != _FS_SYMBIAN_) || _FS_COMPILER_ == _FS_NOKIA_X86_ || _FS_COMPILER_ == _FS_METROWERKS_ || _FS_COMPILER_ == _FS_IARCC_)
		#include <wchar.h>
	#endif	
#endif

#if (_FS_OS_ == _FS_WIN32_DESKTOP_ || _FS_OS_ == _FS_WIN32_MOBILE_ || _FS_OS_ == _FS_WIN64_) && !defined(_FS_NO_WINDOWS_)
#include <windows.h>
#endif

#ifdef __cplusplus
extern "C"{
#endif

#ifdef _DEBUG
#include <assert.h>
#define FS_ASSERT assert
#else
#define FS_ASSERT(x) 1
#endif

/* @COMMONSTART */
/* @TYPEDEFSTART */

/**
 * @name FSBasicTypes
 */
/*@{*/

/** @brief Pointer to any type. */
typedef void* FS_LPVOID;

/** @brief Pointer to any constant type. */
typedef void const*	FS_LPCVOID;

/** @brief Byte (8 bits). */
typedef unsigned char FS_BYTE;
/** @brief Pointer to a FS_BYTE. */
typedef unsigned char* FS_LPBYTE;

/** @brief Pointer to a constant <a>FS_BYTE</a>. */
typedef unsigned char const* FS_LPCBYTE;

/** @brief Short integer (16 bits). */
typedef short FS_SHORT;
/** @brief 16-bit unsigned integer. */
typedef unsigned short FS_WORD;
/** @brief Pointer to a <a>FS_WORD</a>. */
typedef unsigned short*	FS_LPWORD;
/** @brief 32-bit signed integer. */
typedef int	FS_INT32;
/** @brief Pointer to a widget. */
typedef HWND	FS_HWND;
/** @brief Pointer to plug-in. */
typedef HINSTANCE	FS_HINSTANCE;


/** @brief Device handle. */
typedef HDC FS_HDC;
/** @brief Icon Type */
typedef HICON FS_ICON;
/** @brief Menu handle */
typedef HMENU FS_MENU;
/** @brief Font handle */
typedef LOGFONT FS_FONT;
/** @brief Datatime format */
typedef SYSTEMTIME FS_SYSTEMTIME;
/** @brief FILETIME format */
typedef FILETIME FS_FILETIME;


#if !defined(_MSC_VER) && (_FS_CPU_ == _FS_X64_ || _FS_CPU_ == _FS_IA64_ || _FS_CPU_ == _FS_ARM64_ || _FS_CPU_ == _FS_MIPS64_ || _FS_CPU_ == _FS_LOONGARCH64_)
	/** @brief 32-bit unsigned integer. */
	typedef unsigned int			FS_DWORD;
	/** @brief Pointer to a DWORD. */
	typedef unsigned int*			FS_LPDWORD;
#else
	/** @brief 32-bit unsigned integer. */
	typedef unsigned long FS_DWORD;
	/** @brief Pointer to a <a>FS_DWORD</a>. */
	typedef unsigned long* FS_LPDWORD;
#endif

#if defined(_WIN64)
	typedef unsigned __int64 FS_DWORD_PTR;
#else	
	typedef FS_DWORD FS_DWORD_PTR;
#endif
	
/** @brief Boolean variable (should be <a>TRUE</a> or <a>FALSE</a>). */
typedef int     FS_BOOL;

/** @brief Boolean variable (should be <a>true</a> or <a>false</a>). */
typedef bool	FS_BOOLEAN;

/** @brief 8-bit Windows (ANSI) character. */
typedef char FS_CHAR;
/** @brief Pointer to 8-bit Windows (ANSI) characters. */
typedef char* FS_LPSTR;

/** @brief Pointer to constant 8-bit Windows (ANSI) characters. */
typedef char const* FS_LPCSTR;

/** @brief 32-bit unsigned integer. */
typedef unsigned int FS_UINT;

/** @brief 16-bit unicode character. */
typedef wchar_t FS_WCHAR;

/** @brief Pointer to 16-bit unicode characters. */
typedef wchar_t* FS_LPWSTR;

/** @brief Pointer to 16-bit unicode characters. */
typedef wchar_t const* FS_LPCWSTR;

/** @brief A value used to denote the position of an element in a collection. */
typedef void* FS_POSITION;


#ifdef _MSC_VER
	/** @brief Signed 64-bit integer. */
	typedef __int64				FS_INT64;
	/** @brief Unsigned 64-bit integer. */
	typedef unsigned __int64	FS_UINT64;
#else
	typedef long long int		FS_INT64;
	typedef unsigned long long	FS_UINT64;
#endif

#if (_FS_OS_ == _FS_WIN32_DESKTOP_ || _FS_OS_ == _FS_WIN64_) && !defined(_FS_NO_WINDOWS_)
	/** @brief Signed integral type for pointer precision. */
	typedef INT_PTR FS_INTPTR;
	/** @brief Unsigned integral type for pointer precision. */
	typedef UINT_PTR FS_UINTPTR;
#else
#if (_FS_CPU_ == _FS_X64_ || _FS_CPU_ == _FS_IA64_)
	typedef FS_INT64			FS_INTPTR;
	typedef FS_UINT64			FS_UINTPTR;
#else
	typedef int					FS_INTPTR;
	typedef unsigned int		FS_UINTPTR;
#endif
#endif

#define FSYS_RGB(r, g, b)  ((r) | ((g) << 8) | ((b) << 16))

#define FSSYS_qsort FXSYS_qsort

/** @brief 32-bit floating-point number. */
typedef float					FS_FLOAT;

/** @brief The result code for functoins. */
typedef int FS_RESULT;

/*@}*/
/* @TYPEDEFEND */


/* @DEFGROUPSTART FSBoolean */


/**
 * @name FSBoolean
 */
/*@{*/

#ifndef TRUE
/** @brief Keyword which value is 1. */
#define TRUE 1
#endif

#ifndef FALSE
/** @brief Keyword which value is 0. */
#define FALSE 0
#endif

/*@}*/

/* @DEFGROUPEND */


/* @DEFGROUPSTART FSNull */
/**
 * @name Macro definition for key NULL.
 */
/*@{*/

#ifndef NULL
/** @brief The null-pointer value. */
#define NULL 0
#endif

/*@}*/

/* @DEFGROUPEND */

/* @STRUCTSTART FS_GUID*/
#ifndef FS_GUID_STRUCT
#define FS_GUID_STRUCT
    /**
    * @brief Structure for GUID and type definitions.
    *
    */
    typedef struct __FS_GUID__
    {
        /** Data1. */
        FS_DWORD	data1;
        /** Data2. */
        FS_WORD		data2;
        /** Data3. */
        FS_WORD		data3;
        /** Data4. */
        FS_BYTE		data4[8];
    }FS_GUID, *FS_LPGUID;
#endif
/* @STRUCTEND */

/* @TYPEDEFSTART */
/** @brief Type definition of UUID. */
typedef unsigned char FS_UUID[16];
/* @TYPEDEFEND */

/* @DEFGROUPSTART FSUUIDType */
/**
 * @name Macro definitions for UUID types.
 */
/*@{*/
/** @brief The UUID is invalid. */
#define FS_UUIDTYPE_INVALID									-1

/** @brief The UUID is constructed by time and MAC address. */
#define FS_UUIDTYPE_WINDOWS_TIME_MAC						0x10001010

/** @brief The UUID is constructed by time and random number. */
#define FS_UUIDTYPE_WINDOWS_TIME_RANDOM						0x10001101

/** @brief The UUID is constructed by high quality number. */
#define FS_UUIDTYPE_WINDOWS_RANDOM_HIGHQUALITY				0x10001000

/** @brief The UUID is constructed by random number only. */
#define FS_UUIDTYPE_WINDOWS_RANDOM							0x10000010

/** @brief The other type. */
#define FS_UUIDTYPE_WINDOWS_OTHER							0x10001111
/*@}*/

/* @DEFGROUPEND */

/* @ENUMSTART */
/** @brief GLOG message type.
 */
enum FS_GLOG_Type
{
	FS_GLOG_INFO,	
	FS_GLOG_WARING,
	FS_GLOG_ERROR
};
/* @ENUMEND */
/* @COMMONEND */

/* @OBJSTART FS_HFT */
#ifndef FS_PLUGINHFT
#define FS_PLUGINHFT
/**
* @brief An object that describes a set of exported functions. It is an array of function pointers.
* See <a>FSExtensionHFTMgrNewHFT</a>, <a>FSExtensionHFTMgrGetHFT</a>, <a>FSExtensionHFTMgrReplaceEntry</a>.
*/
typedef struct _t_FS_HFT* FS_HFT;
#endif
/* @OBJEND */


/* @OBJSTART FS_DIBitmap */

#ifndef FS_DIBITMAP
#define	FS_DIBITMAP
/**
* @brief An object representing a device-independent bitmap.
*
* DI Bitmap data are organized in <a>FS_DWORD</a> aligned scan lines, from top to bottom. 
* Bitmap Coordinations: the bitmap coordinate has the origin at left-top corner.
* See <a>FSDIBitmapNew</a>, FSDIBitmapCreate</a>, <a>FSDIBitmapDestroy</a>.
*/
typedef struct _t_FS_DIBitmap* FS_DIBitmap;
#endif


/* @ENUMSTART */
/** 
  * @brief Device-independent bitmap formats. See <a>FSDIBitmapConvertFormat</a>.
  */
enum FS_DIB_Format
{
	FS_DIB_Invalid = 0,			/**< not a real format. */
	FS_DIB_1bppMask = 0x101,	/**< 1bpp bit mask. 0 for zero alpha, 1 for maximum alpha. */
	FS_DIB_1bppRgb = 0x001,		/**< 1bpp two color RGB bitmap. */
	FS_DIB_1bppCmyk = 0x401,	/**< 1bpp two color CMYK bitmap. */
	FS_DIB_8bppMask = 0x108,	/**< 8bpp alpha mask. */
	FS_DIB_8bppRgb = 0x008,		/**< 8bpp 256 color RGB bitmap. */
	FS_DIB_8bppRgba = 0x208,	/**< 8bpp 256 color RGB bitmap with extra alpha channel. */
	FS_DIB_8bppCmyk = 0x408,	/**< 8bpp 256 color CMYK bitmap. */
	FS_DIB_8bppCmyka = 0x608,	/**< 8bpp 256 color CMYK bitmap with extra alpha channel. */
	FS_DIB_Gray = 0x1008,		/**< 8bpp 256 color GrayScale bitmap. */
	FS_DIB_Rgb = 0x018,		    /**< 24bpp RGB bitmap. Byte order: BGR. */
	FS_DIB_Rgba = 0x218,		/**< 24bpp RGB bitmap with extra alpha channel. Byte order: BGR + 8bppMask. */
	FS_DIB_Rgb32 = 0x020,		/**< 32bpp RGB bitmap. Byte order: BGR, 4th byte not used. */
	FS_DIB_Argb = 0x220,		/**< 32bpp ARGB bitmap. Byte order: BGRA. */
	FS_DIB_Cmyk = 0x420,		/**< 32bpp CMYK bitmap. Byte order: CMYK. */
	FS_DIB_Cmyka = 0x620,		/**< 32bpp CMYKA bitmap with extra alpha channel. Byte order: CMYK + 8bppMask. */
};
/* @ENUMEND */

/* @ENUMSTART */
/** 
  * @brief Device-independent bitmap channel ID. See <a>FSDIBitmapLoadChannel</a>, <a>FSDIBitmapLoadChannel2</a>.
  */
enum FS_DIB_Channel
{
	FS_DIB_Red = 1,		/**< Red channel. */
	FS_DIB_Green,		/**< Green channel. */
	FS_DIB_Blue,			/**< Blue channel. */
	FS_DIB_Cyan,			/**< Cyan channel. */
	FS_DIB_Magenta,		/**< Magenta channel. */
	FS_DIB_Yellow,		/**< Yellow channel. */
	FS_DIB_Black,		/**< Key Black channel. */
	FS_DIB_Alpha			/**< Alpha channel. */
};
/* @ENUMEND */



/* @DEFGROUPSTART FSDIBSretchFlags */

/**
 * @brief Flags used for stretch or transformation.
 */
/*@{*/
/** @brief The default setting. */
#define FS_DIB_DEFAULT		0x0
/** @brief When set, don't do halftone for shrinking or rotating. */
#define FS_DIB_DOWNSAMPLE		0x04
/** @brief When set, do interpolation for enlarging. */
#define FS_DIB_INTERPOL			0x20
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FSDIBConvertFlags */
/**
 * @brief Flags used for converting format.
 */
/*@{*/
/** @brief When set, use the palette that built from a bitmap. */
#define FS_DIB_PALETTE_LOC		0x01
/** @brief When set, use the windows palette. */
#define FS_DIB_PALETTE_WIN		0x02
/** @brief When set, use the mac palette. */
#define FS_DIB_PALETTE_MAC		0x04
/*@}*/
/* @DEFGROUPEND */


/* @DEFGROUPSTART FSFillingModeFlags */
/**
 * @brief Flags used for filling page objects.
 */
/*@{*/
/** @brief Alternate. */
#define FSFILL_ALTERNATE		1
/** @brief Winding. */
#define FSFILL_WINDING			2
/**
 * @brief A special flag that can be applied to fill mode, indicating
 * all pixels partially covered by the path will be fully painted.
 */
#define FSFILL_FULLCOVER		4
/**
 * @brief A special flag that can be applied to fill mode, indicating
 * the rectangle won't be fully filled (like by default), instead, it will
 * be filled using standard anti-aliasing.
 */
#define FSFILL_RECT_AA			8
/*@}*/
/* @DEFGROUPEND */


/* @DEFGROUPSTART FSDIBlendTypes */

/**
 * @brief The flags for bitmap blend. 
 *
 * <ul>
 * <li>- B denotes blend function. It can be Normal, Multiply, Screen...</li>
 * <li>- Cr denotes result color components.</li>
 * <li>- Cb denotes background color components.</li>
 * <li>- Cs denotes source color components.</li>
 * </ul>
 *
 * See <a>FSDIBitmapCompositeBitmap</a>, <a>FSDIBitmapCompositeMask</a>.
 */

/*@{*/
/**
 * @brief Selects the source color, ignoring the backdrop.
 * B(Cb, Cs) = Cs
 */
#define FS_DIB_BLEND_NORMAL			0
/**
 * @brief Multiplies the backdrop and source color values.
 * B(Cb, Cs) = Cb * Cs
 */
#define FS_DIB_BLEND_MULTIPLY		1
/**
 * @brief Multiplies the complements of the backdrop and source color values, then complements the result.
 * B(Cb, Cs) = 1 - [(1 - Cb) * (1 - Cs)] = Cb + Cs - Cb * Cs
 */
#define FS_DIB_BLEND_SCREEN			2
/**
 * @brief Multiplies or screens the colors, depending on the backdrop color value.
 * B(Cb, Cs) = HardLight(Cs, Cb)
 */
#define FS_DIB_BLEND_OVERLAY		3
/**
 * @brief Selects the darker of the backdrop and source colors.
 * B(Cb, Cs) = min(Cb, Cs)
 */
#define FS_DIB_BLEND_DARKEN			4
/**
 * @brief Selects the lighter of the backdrop and source colors.
 * B(Cb, Cs) = max(Cb, Cs)
 */
#define FS_DIB_BLEND_LIGHTEN		5
 /**
  * @brief Brightens the backdrop color to reflect the source color. Painting with black produces no changes.
  * B(Cb, Cs) = 
  * <br><ul>
  * <li>- min(1, Cb / (1 - Cs))		if Cs < 1</li>
  * <li>- 1							if Cs = 1</li>
  * </ul>
  */
#define FS_DIB_BLEND_COLORDODGE		6
/**
 * @brief Darkens the backdrop color to reflect the source color. Painting with white produces no changes.
 * B(Cb, Cs) = 
 * <br><ul>
 * <li>- 1 - min(1, (1 - Cb) / Cs)	if Cs > 0</li>
 * <li>- 0							if Cs = 0</li>
 * </ul>
 */
#define FS_DIB_BLEND_COLORBURN		7
/**
 * @brief Multiplies or screens the colors, depending on the source color value.
 * B(Cb, Cs) = 
 * <br><ul>
 * <li>- Multiply(Cb, 2 * Cs)		if Cs <= 0.5</li>
 * <li>- Screen(Cb, 2 * Cs - 1)		if Cs > 0.5</li>
 * </ul>
 */
#define FS_DIB_BLEND_HARDLIGHT		8
/**
 * @brief Darkens or lightens the colors, depending on the source color value.
 * B(Cb, Cs) = 
 * <br><ul>
 * <li>- Cb - (1 - 2 * Cs) * Cb * (1 - Cb)		if Cs <= 0.5</li>
 * <li>- Cb + (2 * Cs - 1) * (D(Cb) - Cb)		if Cs > 0.5 \n</li>
 * </ul><br>
 * where D(x) = 
 * <br><ul>
 * <li>- ((16 * x - 12) * x + 4) * x			if x <= 0.25</li>
 * <li>- sqrt(x)								if x > 0.25</li>
  * </ul>
 */
#define FS_DIB_BLEND_SOFTLIGHT		9
/**
 * @brief Subtracts the darker of the two constituent colors from the lighter color.
 * B(Cb, Cs) = |Cb - Cs|
 */
#define FS_DIB_BLEND_DIFFERENCE		10
/**
 * @brief Produces an effect similar to that of the difference mode but lower in contrast.
 * B(Cb, Cs) = Cb + Cs - 2 * Cb * Cs
 */
#define FS_DIB_BLEND_EXCLUSION		11

/** @brief Standard nonseparable blend modes 
  * <Italic>SetLum</Italic>, <Italic>Lum</Italic>, <Italic>SetSat</Italic>, <Italic>Sat</Italic> defined in the p.524 of the pdf reference 1.7.  
  */
#define FS_DIB_BLEND_NONSEPARABLE	21

/**
 * @brief Creates a color with the hue of the source color and the saturation and
 * luminosity of the backdrop color.
 * B(Cb, Cs) = SetLum(SetSat(Cs, Sat(Cb)), Lum(Cb))
 */
#define FS_DIB_BLEND_HUE			21

/**
 * @brief Creates a color with the saturation of the source color and the hue and luminosity of the 
 * backdrop color. 
 * B(Cb, Cs) = SetLum(SetSat(Cb, Sat(Cs)), Lum(Cb))
 */
#define FS_DIB_BLEND_SATURATION		22

/**
 * @brief Creates a color with the hue and saturation of the source color and the luminosity of the 
 * backdrop color.  
 * B(Cb, Cs) = SetLum(Cs, Lum(Cb))
 */
#define FS_DIB_BLEND_COLOR			23

/**
 * @brief Creates a color with the luminosity of the source color and the hue and saturation of the 
 * backdrop color. 
 * B(Cb, Cs) = SetLum(Cb, Lum(Cs))
 */
#define FS_DIB_BLEND_LUMINOSITY		24

/** @brief Unsupported blend type. */
#define FS_DIB_BLEND_UNSUPPORTED	-1
/*@}*/
/* @DEFGROUPEND */


/* @TYPEDEFSTART */

/** @brief ARGB color type. ((b) | ((g) << 8) | ((r) << 16)) | ((a) << 24) */
typedef FS_DWORD	FS_ARGB;
/** @brief RGB color type. ((r) | ((g) << 8) | ((b) << 16))*/
typedef FS_DWORD	FS_COLORREF;

/* @TYPEDEFEND */


/* @CALLBACKGROUPSTART FPD_DIBitmapCallbacks */
/** @brief A set of callbacks for DIBitamp. */
typedef struct _fpd_diBitmap_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;
	
	 /* @CALLBACKSTART FPDOnCreate */
	 /**
	 * @brief			Fetches a single scanline.
	 *
	 * In FXDIB_XXXa mode, you should get alpha scanline individually from m_AlphaMask.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] line			The zero-based line number. [0, height).	
	 * @return A pointer to the scanline.
	 * @note
	 */
	FS_LPCBYTE(*FPDGetScanline)(FS_LPVOID clientData, FS_INT32 line);
	/* @CALLBACKEND */
}FPD_DIBitmapCallbacksRec, *FPD_DIBitmapCallbacks;
/* @CALLBACKGROUPEND */


/* @STRUCTSTART */
/** @brief ECM open info type. See <a>FRAppFileDialogECMOpenProc</a>.*/
typedef struct __FPD_DIBitmap_Attribute__
{
	/** The bitmap width. */
	FS_INT32		m_Width;
	/** The bitmap height. */
	FS_INT32		m_Height;
	/** Bits per pixel. */
	FS_INT32		m_bpp;
	/** Alpha flag. 1: alpha mask; 2: has alpha; 4: cmyk. */
	FS_DWORD		m_AlphaFlag;
	/** Row pitch in bytes. */
	FS_DWORD		m_Pitch;
	/** The bitmap buffer. */
	FS_LPBYTE		m_pBuffer;
	/** Whether the bitmap uses external buffer. */
	FS_BOOLEAN		m_bExtBuf;

	__FPD_DIBitmap_Attribute__()
	{
		m_pBuffer = NULL;
		m_bExtBuf = false;
	}
}FPD_DIBitmap_Attribute;
/* @STRUCTEND */
/* @OBJEND */

#ifndef FS_DIBSOURCE
#define	FS_DIBSOURCE
/**
* @brief @brief An abstract class for DIB source, either from a in-memory bitmap, or from a compressed stream.
 * This class can't be constructed directly, instead, a derived class (like FS_DIBitmap) should be used.
*/
typedef struct _t_FS_DIBSource* FS_DIBSource;
#endif
/* @OBJEND */


//////////////////////////////////////////////////////////////////////
//							Coordinates
//////////////////////////////////////////////////////////////////////

/* @COMMONSTART */

/* @STRUCTSTART FS_Rect*/
#ifndef FS_RECT
#define FS_RECT
/**
* @brief A data structure representing a rectangle (a quadrilateral 
* having only horizontal and vertical sides) in a window's coordinate space. 
*
*/
typedef struct __FS_RECT__
{
	/** The x-coordinate of the upper-left corner of a rectangle. */
	int			left;
	/** The y-coordinate of the upper-left corner of a rectangle. */
	int			top;
	/** The x-coordinate of the lower-right corner of a rectangle. */
	int			right;
	/** The y-coordinate of the lower-right corner of a rectangle. */
	int			bottom;
}FS_Rect;
#endif
/* @STRUCTEND */


/* @STRUCTSTART FS_FloatRect*/
#ifndef FS_FLOATRECT
#define FS_FLOATRECT
/**
* @brief A float-point coordination rectangle.
*
* A normalized float-point rectangle always has top larger than bottom, which is the opposite of Windows rectangle.
*/
typedef struct __FS_FloatRect__
{
	/** The x-coordinate of the left-bottom corner. */
	FS_FLOAT left;
	/** The y-coordinate of the left-bottom corner. */
	FS_FLOAT bottom;
	/** The x-coordinate of the right-top corner. */
	FS_FLOAT right;
	/** The y-coordinate of the right-top corner. */
	FS_FLOAT top;
}FS_FloatRect;
#endif
/* @STRUCTEND */




/* @STRUCTSTART FS_PATHPOINT */

/** 
 * @brief Point struct used in <a>FPD_Path</a>. See <a>FPDPathGetPoint</a>.
 */
typedef struct {
	/** x-coordinate of the point. */
	FS_FLOAT			m_PointX;
	/** y-coordinate of the point. */
	FS_FLOAT			m_PointY;
	/** flags of the point. */
	int					m_Flag;
} FS_PATHPOINT;

/* @STRUCTEND */


/* @STRUCTSTART FS_FloatPoint */

/**
 * @brief A float-point coordination point. See <a>FRPageViewDevicePointToPage</a>, <a>FRPageViewPointToDevice</a>.
 */
typedef struct {
	/** x-coordinate of the point. */
	FS_FLOAT			m_PointX;
	/** y-coordinate of the point. */
	FS_FLOAT			m_PointY;
} FS_FloatPoint;


/* @STRUCTEND */


/* @STRUCTSTART FS_DevicePoint */

/**
* @brief A data structure representing a point in a window's coordinate space. 
* See <a>FRAppGetMousePos</a>, <a>FRDocGetPageViewAtPoint</a>, <a>FRPageViewGetAnnotAtPoint</a>, 
* <a>FRPageViewDrawLine</a>, <a>FRPageViewDrawPolygon</a>, <a>FRPageViewDrawPolygonOutline</a>.
*
*/
#ifndef FS_DEVICEPOINT
#define FS_DEVICEPOINT
typedef struct _FS_DevicePoint_ 
{
	/** x-coordinate of the point. */
	int x;
	/** y-coordinate of the point. */
	int y;
}FS_DevicePoint, *PFS_DevicePoint;
#endif

/* @STRUCTEND */

/* @STRUCTSTART FS_AffineMatrix */
#ifndef FS_AFFINEMATRIX
#define FS_AFFINEMATRIX
/**
* @brief A data structure representing a affine-matrix object.
* 
* It defines six coefficients: a, b, c, d, e, f.
* The transformation equations are:
* dest_x = a * src_x + c * src_y + e;
* dest_y = b * src_x + d * src_y + f;
* 
* See <a>FSAffineMatrixGetReverse</a>, <a>FSAffineMatrixTransformPoint</a>, <a>FSAffineMatrixTransformRect</a>,
* <a>FSAffineMatrixConcat</a>, <a>FSAffineMatrixTransformDistance</a>, <a>FRPageViewGetCurrentMatrix</a>.
*/
typedef struct __FS_AffineMatrix__
{
	/** The coefficient a. */
	FS_FLOAT a;
	/** The coefficient b. */
	FS_FLOAT b;
	/** The coefficient c. */
	FS_FLOAT c;
	/** The coefficient d. */
	FS_FLOAT d;
	/** The coefficient e. */
	FS_FLOAT e;
	/** The coefficient f. */
	FS_FLOAT f;
}FS_AffineMatrix;
#endif
/* @STRUCTEND */

/* @ENUMSTART FS_ListStyleType*/
enum FS_ListStyleType
{
	FS_kListStyle_None,
	FS_kListStyle_Repeat,
	FS_kListStyle_Counter,
	FS_kListStyle_Unknown,
};
/* @ENUMEND */

/* @ENUMSTART FS_CounterStyleType*/
enum FS_CounterStyleType
{
	FS_kCounterStyle_None,
	FS_kCounterStyle_LowerLatin,	// a, b, c, ..., z, aa, ab
	FS_kCounterStyle_UpperLatin,	// A, B, C, ..., Z, AA, AB
	FS_kCounterStyle_LowerRoman,	// i, ii, iii, ..., xcviii, xcix, c
	FS_kCounterStyle_UpperRoman,	// I, II, III, ..., XCVIII, XCIX, C
	FS_kCounterStyle_Decimal,		 // 1, 2, 3, ..., 98, 99, 100
	FS_kCounterStyle_CJKDecimal,	//一, 二, 三, ..., 九八, 九九, 一〇〇
	FS_kCounterStyle_Unknown,
};
/* @ENUMEND */

/* @ENUMSTART FS_PrefixSuffixType*/
enum FS_PrefixSuffixType
{
	FS_kPrefixSuffix_None,
	FS_kPrefixSuffix_DotSuffix,
	FS_kPrefixSuffix_RParenSuffix,
	FS_kPrefixSuffix_ParenAround,
	FS_kPrefixSuffix_Unknown,
};
/* @ENUMEND */

/* @STRUCTSTART FS_FXEDIT_ListStyleDescriptor */
struct FS_FXEDIT_ListStyleDescriptor
{
	enum FS_ListStyleType m_eListStyle;
	enum FS_CounterStyleType m_eCounterStyle;
	enum FS_PrefixSuffixType m_ePrefixSuffix;
};
/* @STRUCTEND */

/* @DEFGROUPSTART FSBoolean */


/**
 * @name FS_DEFINEHANDLE
 */
/*@{*/
/** @brief Macro to define a handle type. */
#define FS_DEFINEHANDLE(name)	typedef struct _##name {FS_LPVOID pData;} * name;
/*@}*/

/* @DEFGROUPEND */

/* @COMMONEND */




//////////////////////////////////////////////////////////////////////
//							Buffers
//////////////////////////////////////////////////////////////////////
/* @OBJSTART FS_BinaryBuf */
#ifndef FS_BINARYBUF
#define FS_BINARYBUF
/**
 * @brief Dynamic binary buffers designed for more efficient appending. See <a>FSBinaryBufNew</a>, <a>FSBinaryBufDestroy</a>.
 */
typedef struct _t_FS_BinaryBuf* FS_BinaryBuf;
#endif
/* @OBJEND */



//////////////////////////////////////////////////////////////////////
//							Arrays
//////////////////////////////////////////////////////////////////////

/* @OBJSTART FS_PtrArray */
#ifndef	FS_PTRARRAY
#define FS_PTRARRAY
/**
 * @brief A typeless pointer array. See <a>FSPtrArrayNew</a>, <a>FSPtrArrayDestroy</a>.
 */
typedef struct _t_FS_PtrArray* FS_PtrArray;
#endif
/* @OBJEND */


/* @OBJSTART FS_FloatRectArray */
#ifndef FS_FLOATRECTARRAY
#define FS_FLOATRECTARRAY
/**
 * @brief A FS_FloatRect array. See <a>FSFloatRectArrayNew</a>, <a>FSFloatRectArrayDestroy</a>.
 */
typedef struct _t_FS_FloatRectArray* FS_FloatRectArray;
#endif
/* @OBJEND */


/* @OBJSTART FS_ByteArray */
#ifndef	FS_BYTEARRAY
#define FS_BYTEARRAY
/**
 * @brief A byte array. See <a>FSByteArrayNew</a>, <a>FSByteArrayDestroy</a>.
 */
typedef struct _t_FS_ByteArray* FS_ByteArray;
#endif
/* @OBJEND */


/* @OBJSTART FS_WordArray */
#ifndef	FS_WORDARRAY
#define FS_WORDARRAY
/**
 * @brief A word array. See <a>FSWordArrayNew</a>, <a>FSWordArrayDestroy</a>.
 */
typedef struct _t_FS_WordArray* FS_WordArray;
#endif
/* @OBJEND */


/* @OBJSTART FS_DWordArray */
#ifndef	FS_DWORDARRAY
#define FS_DWORDARRAY
/**
 * @brief A double word array. See <a>FSDWordArrayNew</a>, <a>FSDWordArrayDestroy</a>.
 */
typedef struct _t_FS_DWordArray* FS_DWordArray;
#endif
/* @OBJEND */


/* @OBJSTART FS_ByteStringArray */
#ifndef	FS_BYTESTRINGARRAY
#define FS_BYTESTRINGARRAY
/**
 * @brief A byte string array. See <a>FSByteStringArrayNew</a>, <a>FSByteStringArrayDestroy</a>.
 */
typedef struct _t_FS_ByteStringArray* FS_ByteStringArray;
#endif
/* @OBJEND */


/* @OBJSTART FS_WideStringArray */
#ifndef	FS_WIDESTRINGARRAY
#define FS_WIDESTRINGARRAY
/**
 * @brief A wide string array. See <a>FSWideStringArrayNew</a>, <a>FSWideStringArrayDestroy</a>.
 */
typedef struct _t_FS_WideStringArray* FS_WideStringArray;
#endif
/* @OBJEND */


/* @OBJSTART FS_PtrArray */
#ifndef	FS_FLOATARRAY
#define FS_FLOATARRAY
/**
 * @brief A typeless pointer array. See <a>FSFloatArrayNew</a>, <a>FSFloatArrayDestroy</a>.
 */
typedef struct _t_FS_FloatArray* FS_FloatArray;
#endif
/* @OBJEND */

/* @OBJSTART FS_Int32Array */
#ifndef FS_INT32ARRAY
#define FS_INT32ARRAY
/**
 * @brief A int array. See <a>FS_Int32ArrayNew</a>, <a>FS_Int32ArrayDestroy</a>.
 */
typedef struct _t_FS_Int32Array* FS_Int32Array;
#endif
/* @OBJEND */
//////////////////////////////////////////////////////////////////////
//							Maps
//////////////////////////////////////////////////////////////////////

/* @OBJSTART FS_MapPtrToPtr */
#ifndef FS_MAPTPRTOPTR
#define FS_MAPTPRTOPTR
/**
 * @brief POINTER/DWORD TO POINTER/DWORD MAP. See <a>FSMapPtrToPtrNew</a>, <a>FSMapPtrToPtrDestroy</a>.
 */
typedef	struct _t_FS_MapPtrToPtr* FS_MapPtrToPtr;
#endif
/* @OBJEND */

/* @OBJSTART FS_MapByteStringToPtr */
#ifndef FS_MAPBYTESTRINGTOPTR
#define FS_MAPBYTESTRINGTOPTR
/**
 * @brief FS_ByteString TO POINTER MAP. See <a>FSMapByteStringToPtrNew</a>, <a>FSMapByteStringToPtrDestroy</a>.
 */
typedef	struct _t_FS_MapByteStringToPtr* FS_MapByteStringToPtr;
#endif
/* @OBJEND */

/* @OBJSTART FS_CharMap */
#ifndef FS_CHARMAP
#define FS_CHARMAP
/**
 * @brief A map struct for character mappings (encodings).
 *
 * All character maps should have the ability to convert between internal encoding and Unicode.
 * See <a>FSCodeTransformationDecodeText</a>, <a>FSCodeTransformationDecodeText2</a>, <a>FSCodeTransformationEncodeText</a>.
 */
typedef struct _t_FS_CharMap* FS_CharMap;
#endif
/* @OBJEND */

//////////////////////////////////////////////////////////////////////
//							GE
//////////////////////////////////////////////////////////////////////

/* @COMMONSTART */

/* @CALLBACKSTART FS_CALLBACK_FREEDATA */
/**
 * @brief Prototype of callback function provided by custom module for deallocating private data.
 * @param[in] pData The data that need to free.
 * @return void
 * @note
 * @see FRAnnotSetPrivateData
 */
typedef void (*FS_CALLBACK_FREEDATA)(FS_LPVOID pData);
/* @CALLBACKEND */

/* @COMMONEND */

/* @OBJSTART FS_CodeTransformation*/
#ifndef FS_CODETRANSFORMATION
#define FS_CODETRANSFORMATION
/**
 * @brief Code transformation for name, string and text.
 * See <a>FSCodeTransformationNameDecode</a>, <a>FSCodeTransformationNameDecode2</a>, <a>FSCodeTransformationNameEncode</a>, 
 * <a>FSCodeTransformationEncodeString</a>, <a>FSCodeTransformationDecodeText</a>, 
 * <a>FSCodeTransformationDecodeText2</a>, <a>FSCodeTransformationEncodeText</a>.
 */
typedef struct _t_FS_CodeTransformation* FS_CodeTransformation;
#endif
/* @OBJEND */

/* @OBJSTART FS_ExtensionHFTMgr*/
#ifndef FS_EXTENSIONHFTMGR
#define FS_EXTENSIONHFTMGR
/**
 * @brief It is used to manage the extension HFTs. See <a>FSExtensionHFTMgrNewHFT</a>, <a>FSExtensionHFTMgrAddHFT</a>,
 * <a>FSExtensionHFTMgrGetHFT</a>, <a>FSExtensionHFTMgrReplaceEntry</a>, <a>FSExtensionHFTMgrGetEntry</a>.
 */
typedef struct _t_FS_ExtensionHFTMgr* FS_ExtensionHFTMgr;
#endif
/* @OBJEND */

/* @OBJSTART FS_PauseHandler*/
#ifndef FS_PAUSEHANDLER
#define FS_PAUSEHANDLER
/**
 * @brief An object preparing a simple pause instance.
 */
typedef struct _t_FS_PauseHandler* FS_PauseHandler;
#endif

/* @CALLBACKGROUPSTART FS_Pause */
#ifndef FS_PAUSE
#define FS_PAUSE
/**
 * @brief Simple pause interface.
 */
typedef struct
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FS_Pause</a>).  */
	unsigned long lStructSize;
    /** The user-supplied data. */
    FS_LPVOID		clientData;

	/* @CALLBACKSTART NeedToPauseNow */
	/**
	* @brief Prototype of callback function.
	* @param[in] void
	* @return Non-zero means we need, otherwise we need not.
	* @note
	*/
    FS_BOOL	(*NeedToPauseNow)(FS_LPVOID clientData);
	/* @CALLBACKEND */
}FS_Pause,*PFS_Pause;
#endif
/* @CALLBACKGROUPEND */

/* @OBJEND */

/* @OBJSTART FS_FileReadHandler */
#ifndef FS_FILEREADHANDLER
#define FS_FILEREADHANDLER
	/*@brief File reading interface.*/
	typedef struct _t_FS_FileReadHandler* FS_FileReadHandler;
#endif

/* @CALLBACKGROUPSTART FS_FileRead */
	// Structure for reading a file
	typedef struct 
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FS_FileRead</a>). */
		unsigned long lStructSize;
		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART FSFileRead_ReadBlock */
		/**
		* @brief Reada a data block from the file.
		*
		* Reads a data block from the file.
		*
		* @param[in] clientData The user-supplied data.
		* @param[out]buffer		Pointer to a buffer receiving read data
		* @param[in] offset		Byte offset for the block, from beginning of the file.
		* @param[in] size		Number of bytes for the block.
		* @return TRUE for success, FALSE for failure.
		* @note
		*/
		FS_BOOL		(*FSFileRead_ReadBlock)(FS_LPVOID clientData, void* buffer, FS_DWORD offset, FS_DWORD size);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FSFileRead_GetSize */
		/**
		* @brief Gets total size of the file.
		*
		* Gets total size of the file.
		*
		* @param[in] clientData The user-supplied data.
		* @return	File size, in bytes. Implementation can return 0 for any error.
		* @note
		*/
		FS_DWORD		(*FSFileRead_GetSize)(FS_LPVOID clientData);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FSFileRead_Release */
		/**
		* @brief Called when to release everything.
		*
		* Called when to release everything
		*
		* @param[in] clientData The user-supplied data.
		* @return void
		* @note
		*/
		void		(*FSFileRead_Release)(FS_LPVOID clientData);
		/* @CALLBACKEND */		
	} FS_FileRead;
/* @CALLBACKGROUPEND */

	/* @ENUMSTART */
	/**
	* @brief Enumeration for progressive status
	*
	* @details Values of this enumeration should be used alone.
	*/
	enum FS_ProgressiveStatus
	{
		/** @brief Ready. */
		FS_ProgressiveStatus_Ready,
		/** @brief To be continued. */
		FS_ProgressiveStatus_ToBeContinued,
		/** @brief Found. */
		FS_ProgressiveStatus_Found,
		/** @brief Not Found. */
		FS_ProgressiveStatus_NotFound,
		/** @brief Failed. */
		FS_ProgressiveStatus_Failed,
		/** @brief Done. */
		FS_ProgressiveStatus_Done
	};
	/* @ENUMEND */

/* @OBJEND */

/* @OBJSTART FS_StreamWriteHandler */
/** @brief stream writing interface.       
 *
 */
#ifndef FS_STREAMWRITEHANDLER
#define FS_STREAMWRITEHANDLER
typedef struct _t_FS_StreamWritehandler* FS_StreamWriteHandler;
#endif

/* @CALLBACKGROUPSTART FS_StreamWrite */
	// Structure for writing stream
	typedef struct 
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FS_StreamWrite</a>). */
		unsigned long lStructSize;
		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART FSStreamWrite_WriteBlock */
		/**
		* @brief Write a block data. 
		*
		* @param[in] clientData The user-supplied data.
		* @param[in] pData		The block data.
		* @param[in] size		The length in bytes of the block data.
		* @return TRUE for success, FALSE for failure.
		* @note
		*/
		FS_BOOL		(*FSStreamWrite_WriteBlock)(FS_LPVOID clientData, const void* pData, FS_DWORD size);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FSStreamWrite_Release */
		/**
		* @brief Called when to release everything.
		*
		* Called when to release everything
		*
		* @param[in] clientData The user-supplied data.
		* @return
		* @note
		*/
		void		(*FSStreamWrite_Release)(FS_LPVOID clientData);
		/* @CALLBACKEND */		
	} FS_StreamWrite;
/* @CALLBACKGROUPEND */
/* @OBJEND */


/* @OBJSTART FS_Base64Encoder */
/** @brief It represents a Base64 encoder object. You can use it to encode a byte data array into Base64.
 * See <a>FSBase64EncoderNew</a>, <a>FSBase64EncoderEncode</a>.
 */
#ifndef FS_BASE64ENCODER
#define FS_BASE64ENCODER
typedef struct _t_FS_Base64Encoder* FS_Base64Encoder;
#endif


/* @CALLBACKSTART FS_LPBase64EncodeProc */
/**
 * @brief Type definition for external Base64 encoder.
 * @param[in] b	a 6bits data to encode.
 * @return An encoded wide character value.
 * @note
 * @see FSBase64EncoderSetEncoder
 */
typedef FS_WCHAR (*FS_LPBase64EncodeProc)(FS_DWORD b);
/* @CALLBACKEND */

/* @OBJEND */


/* @OBJSTART FS_Base64Decoder */
/** @brief	It represents a Base64 decoder object. You can use it to decode Base64 encoded data.   
 *  See <a>FSBase64DecoderNew</a>, <a>FSBase64DecoderDecode</a>.
 */
#ifndef FS_BASE64DECODER
#define FS_BASE64DECODER
typedef struct _t_FS_Base64Decoder* FS_Base64Decoder;
#endif


/* @CALLBACKSTART FS_LPBase64DecodeProc */
/**
 * @brief Type definition for external Base64 decoder.
 * @param[in] wch A wide character to decode. 
 * @return A 6bits decoded byte value.
 * @note
 * @see FSBase64DecoderSetDecoder
 */
typedef FS_BYTE (*FS_LPBase64DecodeProc)(FS_WCHAR wch);
/* @CALLBACKEND */

/* @OBJEND */

/* @OBJSTART FS_FileWriteHandler */
/** @brief file writing interface. See <a>FSFileWriteHandlerNew</a>, <a>FSFileWriteHandlerDestroy</a>.
 */
#ifndef FS_FileWRITEHANDLER
#define FS_FileWRITEHANDLER
typedef struct _t_FS_FileWriteHandler* FS_FileWriteHandler;
#endif

/* @CALLBACKGROUPSTART FS_FileWrite */
	// Structure for writing stream
	typedef struct 
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FS_FileWrite</a>). */
		unsigned long lStructSize;
		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART FSFileWrite_GetSize */
		/**
		* @brief It is called by foxit reader to get the total size of the file.
		*
		* @param[in] clientData The user-supplied data.
		* @return File size, in bytes. Implementation can return 0 for any error.
		* @note
		*/
		FS_DWORD	(*FSFileWrite_GetSize)(FS_LPVOID clientData);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FSFileWrite_Flush */
		/**
		* @brief It is called by foxit reader to flush internal buffer of the file.
		*
		* @param[in] clientData The user-supplied data.
		* @return TRUE if flushes successfully, or FALSE to indicate error.
		* @note
		*/
		FS_DWORD	(*FSFileWrite_Flush)(FS_LPVOID clientData);
		/* @CALLBACKEND */
		
		/* @CALLBACKSTART FSFileWrite_WriteBlock */
		/**
		* @brief It is called by foxit reader to write a block data. 
		*
		* @param[in] clientData The user-supplied data.
		* @param[in] pData		The block data.
		* @param[in] offset		Byte offset from beginning of the file
		* @param[in] size		The length in bytes of the block data.
		* @return TRUE for success, or FALSE to indicate error.
		* @note
		*/
		FS_BOOL		(*FSFileWrite_WriteBlock)(FS_LPVOID clientData, const void* pData, FS_DWORD offset, FS_DWORD size);
		/* @CALLBACKEND */

		

		/* @CALLBACKSTART FSFileWrite_Release */
		/**
		* @brief Called when to release everything.
		*
		* @param[in] clientData The user-supplied data.
		* @return
		* @note
		*/
		void		(*FSFileWrite_Release)(FS_LPVOID clientData);
		/* @CALLBACKEND */		
	} FS_FileWrite;
/* @CALLBACKGROUPEND */
/* @OBJEND */


/* @OBJSTART FS_XMLElement */
/** @brief An object representing a XML element.
 *
 * You parse the XML data to get a XML element object, and then retrieve the attributes. You can also create an empty XML element object, 
 * and then edit the attributes, finally output the XML data. See <a>FSXMLElementparse</a>, <a>FSXMLElementNew</a>, 
 * <a>FSXMLElementSetTag</a>, <a>FSXMLElementOutputStream</a>.
 */

#ifndef FS_XMLELEMENT
#define FS_XMLELEMENT
typedef struct _t_FS_XMLElement* FS_XMLElement;
#endif

/* @ENUMSTART */
/** 
  * @brief Children Type of FS_XMLElement.
  */
enum FS_Child_Type
{
	Invalid,	/**< Invalid. */
	Element,	/**< Element. */
	Content,	/**< Content. */
};
/* @ENUMEND */
	
/* @OBJEND */

/* @OBJSTART FS_UTF8Decoder */
#ifndef	FS_UTF8DECODER
#define FS_UTF8DECODER
/**
 * @brief A UTF8 decoder object. You can use it to decode UTF-8 encoded data.
 * See  <a>FSUTF8DecoderNew </a>, <a>FSUTF8DecoderDestroy</a>.
 */
typedef struct _t_FS_UTF8Decoder* FS_UTF8Decoder;
#endif
/* @OBJEND */

/* @OBJSTART FS_UTF8Encoder */
#ifndef	FS_UTF8ENCODER
#define FS_UTF8ENCODER
/**
 * @brief A UTF8 encoder object. You can use it to encode data into UTF-8.
 * See <a>FSUTF8EncoderNew</a>, <a>FSUTF8EncoderDestroy</a>.
 */
typedef struct _t_FS_UTF8Encoder* FS_UTF8Encoder;
#endif

enum FPD_EM_CODEENCODING
{
	FPD_CODE_DEFAULT,
	FPD_CODE_UTF16,
	FPD_CODE_UTF8,
	FPD_CODE_BigFive,
	FPD_CODE_GBK,
	FPD_CODE_ShiftJS,
	FPD_CODE_UHC
};
/* @OBJEND */

/* @OBJSTART FS_DIBAttribute */

#ifndef FS_DIBATTRIBUTE
#define	FS_DIBATTRIBUTE
/**
* @brief An object representing a device-independent bitmap attribute. The bitmap has the attributes of horizontal resolution, 
* vertical resolution, resolution unit and so on. See <a>FSDIBitmapLoadInfo</a>.
*/
typedef struct _t_FS_DIBAttribute* FS_DIBAttribute;
#endif


/* @ENUMSTART */
/** 
  * @brief Device-independent bitmap image type.
  */
enum FS_DIB_IMAGE_TYPE
{
	FS_DIB_IMAGE_UNKNOWN = 0,			/**< Unknown image, will be auto detected */
	FS_DIB_IMAGE_BMP,					/**< Bmp */
	FS_DIB_IMAGE_JPG,					/**< Jpeg */
	FS_DIB_IMAGE_PNG,					/**< Png */
	FS_DIB_IMAGE_GIF,					/**< Gif */
	FS_DIB_IMAGE_TIF,					/**< Tiff */
	FS_DIB_IMAGE_JPX,					/**< Jpx */
	FS_DIB_IMAGE_JPX_DATA,				/**< Jpx image without header*/
	FS_DIB_IMAGE_JBIG2,				/**< JBIG2 */
	FS_DIB_IMAGE_MAX					/**< Max, the upperbound of image enum. */
};
/* @ENUMEND */

/* @ENUMSTART */
/** 
  * @brief Define the resolution unit type..
  */

enum FS_DIB_RESUNIT
{
	FS_DIB_RESUNIT_NONE = 0,		/**< no unit */
	FS_DIB_RESUNIT_INCH,			/**< unit inch */
	FS_DIB_RESUNIT_CENTIMETER,		/**< unit centimeter */
	FS_DIB_RESUNIT_METER			/**< unit meter */
};
/* @ENUMEND */

/* @DEFGROUPSTART FSDIBEXIFTAG */

/**
 *
 * @brief The exchangeable image file information of camera in JPEG file.
 */

/*@{*/
/** @brief Resolution unit. The value type is a 16-bit unsigned integer(FS_WORD). */
#define FS_DIB_EXIFTAG_USHORT_RESUNIT				296
/** @brief  Image resolution in width. The value type is 32 bits(FS_FLOAT).*/
#define FS_DIB_EXIFTAG_FLOAT_DPIX					282
/** @brief	Image resolution in width. The value type is 32 bits(FS_FLOAT).*/
#define FS_DIB_EXIFTAG_FLOAT_DPIY					283
/** @brief  The orientation. The value type is a 16-bit unsigned integer(FS_WORD).*/
#define FS_DIB_EXIFTAG_USHORT_ORIENTATION			274
/** @brief  Digital camera manufacturers. The value type is an 8-bit byte containing one 7-bit ASCII code. The final byte is terminated with NULL(FS_LPSTR). The caller should not release the string.*/
#define FS_DIB_EXIFTAG_STRING_MANUFACTURER			271
/** @brief  Digital camera module code. The value type is an 8-bit byte containing one 7-bit ASCII code. The final byte is terminated with NULL(FS_LPSTR). The caller should not release the string.*/
#define FS_DIB_EXIFTAG_STRING_MODULE				272
/** @brief  Software used. The value type is an 8-bit byte containing one 7-bit ASCII code. The final byte is terminated with NULL(FS_LPSTR). The caller should not release the string.*/
#define FS_DIB_EXIFTAG_STRING_SOFTWARE				305
/** @brief  The description of bitmap. Don't support double byte characters yards, like Chinese/Japanese/Korean etc. The value type is an 8-bit byte containing one 7-bit ASCII code. The final byte is terminated with NULL(FS_LPSTR). The caller should not release the string.*/
#define FS_DIB_EXIFTAG_STRING_IAMGEDESCRIPTION		270
/** @brief  File change date and time. The value type is an 8-bit byte containing one 7-bit ASCII code. The final byte is terminated with NULL(FS_LPSTR). The caller should not release the string.*/
#define FS_DIB_EXIFTAG_STRING_DATETIME				306
/** @brief  Copyright holder. The value type is an 8-bit byte containing one 7-bit ASCII code. The final byte is terminated with NULL(FS_LPSTR). The caller should not release the string.*/
#define FS_DIB_EXIFTAG_STRING_COPYRIGHT			33432
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FS_FileStream */
/**
 * @brief The <a>FS_FileStream</a> object is used to read and write stream. See <a>FSFileStreamNew</a>.
 */
#ifndef FS_FILESTREAM
#define FS_FILESTREAM
typedef struct _t_FS_FileStream* FS_FileStream;
#endif

/* @DEFGROUPSTART FSFileMode */
/**
* @brief Definitions for the file mode.
*/

/*@{*/
/** @brief	The writing mode. Creates automatically if the file doesn't exist. */
#define FS_FILEMODE_Write		0

/** @brief	The reading mode. */
#define FS_FILEMODE_ReadOnly	1

/** @brief	Clears existing content and sets the size of the file as 0. For writing mode only. */
#define FS_FILEMODE_Truncate	2	//
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKGROUPSTART FS_FileStreamCallbacksRec */

/**
 * @brief A callback set for file stream reading and writing.
 *
 */
typedef struct _fs_filestream_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FS_FileStreamCallbacksRec</a>). */
	unsigned long lStructSize;
	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FSFileStreamRetain */
	/**
	* @brief Create a shared instance.
	*
	* @param[in] clientData The user-supplied data.
	* @return The retained file stream object.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	* @see FSFileStreamNew
	*/
	FS_FileStream (*FSFileStreamRetain)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FSFileStreamRelease */
	/**
	* @brief Destroy the current instance.
	*
	* @param[in] clientData The user-supplied data.
	* @return void.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	* @see FSFileStreamNew
	*/
	void (*FSFileStreamRelease)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FSFileStreamGetSize */
	/**
	* @brief Gets the current stream size, in bytes.
	*
	* @param[in] clientData The user-supplied data.
	* @return The current stream size, in bytes.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	* @see FSFileStreamNew
	*/
	FS_INT32 (*FSFileStreamGetSize)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FSFileStreamIsEOF */
	/**
	* @brief Checks whether reach the end of the stream.
	*
	* @param[in] clientData The user-supplied data.
	* @return TRUE if reach the end of the stream, otherwise not.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	* @see FSFileStreamNew
	*/
	FS_BOOL (*FSFileStreamIsEOF)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FSFileStreamGetPosition */
	/**
	* @brief Gets the current reading position in stream.
	*
	* @param[in] clientData The user-supplied data.
	* @return The current reading position in stream.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	* @see FSFileStreamNew
	*/
	FS_INT32 (*FSFileStreamGetPosition)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FSFileStreamReadBlock */
	/**
	* @brief Reads a data block from stream.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in,out] buffer		Pointer to a buffer receiving data.
	* @param[in] offset			Byte offset from beginning of the file, the position to read data.
	* @param[in] size			Number of bytes to be read from stream.
	* @return TRUE for success, FALSE for failure.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	* @see FSFileStreamNew
	*/
	FS_BOOL (*FSFileStreamReadBlock)(FS_LPVOID clientData, void* buffer, FS_INT32 offset, unsigned int size);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FSFileStreamReadBlock2 */
	/**
	* @brief Reads a data block from stream.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in,out] buffer		Pointer to a buffer receiving data.
	* @param[in] size			Number of bytes to be read from stream.
	* @return The length of data stored in buffer. If returns 0, means error or no data.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	* @see FSFileStreamNew
	*/
	unsigned int (*FSFileStreamReadBlock2)(FS_LPVOID clientData, void* buffer, unsigned int size);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FSFileStreamWriteBlock */
	/**
	* @brief Writes a block data into stream.
	*
	* @param[in] clientData The user-supplied data.
	* @param[in] buffer		Pointer to the data block.
	* @param[in] offset		Byte offset from beginning of the file, the position to write data.
	* @param[in] size		The length in bytes of the buffer.
	* @return TRUE for success, FALSE for failure.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	* @see FSFileStreamNew
	*/
	FS_BOOL (*FSFileStreamWriteBlock)(FS_LPVOID clientData, const void* buffer, FS_INT32 offset, unsigned int size);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FSFileStreamFlush */
	/**
	* @brief Flushes internal buffer.
	*
	* @param[in] clientData The user-supplied data.
	* @return TRUE for success, FALSE for failure.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	* @see FSFileStreamNew
	*/
	FS_BOOL (*FSFileStreamFlush)(FS_LPVOID clientData);
	/* @CALLBACKEND */

} FS_FileStreamCallbacksRec, *FS_FileStreamCallbacks;
/* @CALLBACKGROUPEND */

/* @OBJEND */

/* @OBJSTART FS_Image */

#ifndef FS_IMAGE
#define	FS_IMAGE

#ifndef FPD_PAGEOBJECT
#define FPD_PAGEOBJECT
/**
* @brief A <a>FPD_PageObject</a> is the abstract superclass of page objects.
*
* You can find the type of any object
* with the <a>FPDPageObjectGetType</a>() method.
*
*/
typedef struct _t_FPD_PageObject* FPD_PageObject;
#endif

#ifndef FPD_DOCUMENT
#define	FPD_DOCUMENT
/**
* @brief The underlying PDF representation of a document.
*
* Each PDF document contains, among other things:<br>
* <ul>
* <li>- A tree of pages(<a>FPD_Page</a>).</li>
* <li>- (Optional) Trees of bookmarks and articles.</li>
* <li>- (Optional) Information and security dictionaries.</li>
* </ul>
* The FPD_Document object is the hidden object behind every FR_Document.
* Through FPD_Document objects, your application can perform most of the menu items for pages
* from Foxit Phantom (delete, replace, and so on). Thumbnails and Bookmarks can be created and deleted
* through this object. You can set and retrieve document information fields through this
* object as well. The first page in a FPD_Document is page 0. See <a>FPDDocNew</a>, <a>FPDDocDestroy</a>,
* <a>FPDDocOpen</a>, <a>FPDDocOpenMemDocument</a>, <a>FPDDocClose</a>, <a>FPDPageGetDocument</a>.
*/
typedef struct _t_FPD_Document* FPD_Document;

#endif

typedef struct _t_FS_Image* FS_Image;
typedef struct _t_FS_HImage* FS_HImage;

typedef struct _t_FS_ReaderDateTime* FS_ReaderDateTime;

typedef struct _t_FS_Monoscale* FS_Monoscale;




/* @ENUMSTART */
/** @brief The name definition of app mode.*/

enum FS_APPMODE {
    FS_APPMODE_LIGHT,
    FS_APPMODE_DARK
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief The name definition of button state.*/

enum FS_BTNSTATE {
    FS_BTNSTATE_NORMAL,
    FS_BTNSTATE_SELECT
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief The name definition of toolPropertyType.*/

enum FS_ICONSIZE {
	FS_ICONSIZE_16,
	FS_ICONSIZE_24,
	FS_ICONSIZE_32,
	FS_ICONSIZE_36,
	FS_ICONSIZE_48,
	FS_ICONSIZE_64
};
/* @ENUMEND */

/* @ENUMSTART */
/**
* @brief Define the various image type
*/

enum FSCODEC_IMAGE_TYPE
{
	FSCODEC_IMAGE_UNKNOWN = 0,			/**< Unknown image, will be auto detected */
	FSCODEC_IMAGE_BMP,					/**< Bmp */
	FSCODEC_IMAGE_JPG,					/**< Jpeg */
	FSCODEC_IMAGE_PNG,					/**< Png */
	FSCODEC_IMAGE_GIF,					/**< Gif */
	FSCODEC_IMAGE_TIF,					/**< Tiff */
	FSCODEC_IMAGE_JPX,					/**< Jpx */
	FSCODEC_IMAGE_JPX_DATA,				/**< Jpx image without header*/
	FSCODEC_IMAGE_JBIG2,				/**< JBIG2 */
	FSCODEC_IMAGE_MAX					/**< Max, the upperbound of image enum. */
};
/* @ENUMEND */


enum FSMONOALRITHEMETIC
{
	FSMONO_MeanThreshold,
	FSMONO_HuangFuzzyThreshold,
	FSMONO_MinimumThreshold,
	FSMONO_IntermodesThreshold,
	FSMONO_PTileThreshold,
	FSMONO_IterativeBestThreshold,
	FSMONO_OSTUThreshold,
	FSMONO_IsoDataThreshold
};

#endif


/* @OBJSTART FS_PtrArray */
#ifndef	FS_FLOATARRAY
#define FS_FLOATARRAY
/**
 * @brief A typeless pointer array. See <a>FSFloatArrayNew</a>, <a>FSFloatArrayDestroy</a>.
 */
typedef struct _t_FS_FloatArray* FS_FloatArray;
#endif
/* @OBJEND */


/* @OBJSTART FPD_CCodec_ModuleMgr */
#ifndef FS_CCODECMODULEMGR
#define	FS_CCODECMODULEMGR
/**
* @brief Foxit Codec module manager.
*
* Foxit Codec module manager. In order to use many codec, you must create the module first. 
*/
typedef struct _t_FS_CCodecModuleMgr* FS_CCodecModuleMgr;
#endif

enum FS_ICCWorkingSpace{
	FSIcc_WSRGB,			// RGB
	FSIcc_WSCMYK,			// CMYK
	FSIcc_WSGRAYSCALE		// Grayscale
};

/**< ICC color space */
enum FS_ICCCs{	
	FSIccCS_Unknown = 0,
	FSIccCS_XYZ,
	FSIccCS_Lab,
	FSIccCS_Luv,
	FSIccCS_YCbCr,
	FSIccCS_Yxy,
	FSIccCS_Hsv,
	FSIccCS_Hls,
	FSIccCS_Gray,
	FSIccCS_Rgb,
	FSIccCS_Cmyk,
	FSIccCS_Cmy
};

typedef struct _fs_icc_param_ 
{
	FS_DWORD	Version;		/**< The version of IccParam struct */
	FS_ICCCs	ColorSpace;
	FS_DWORD	dwProfileType;	/**< The type of custom params below, descripted in Icc_PARAMTYPE_XXX */
	FS_DWORD	dwFormat;		/**< The format described in Icc_FORMAT_XXX */

	FS_LPBYTE	pProfileData;
	FS_DWORD	dwProfileSize;

	FS_FLOAT	Gamma;
	FS_INT32    Components;
}FS_IccParam;


/** @brief Rendering intent */
#define FSIcc_INTENT_PERCEPTUAL				0
#define FSIcc_INTENT_RELATIVE_COLORIMETRIC	1
#define FSIcc_INTENT_SATURATION				2
#define FSIcc_INTENT_ABSOLUTE_COLORIMETRIC	3

/** @brief Transform and proofing Flags */
#define FSIcc_FLAGS_DEFAULT					0x0000
#define FSIcc_FLAGS_BLACKPOINTCOMPENSATION	0x2000
#define FSIcc_FLAGS_NOWHITEONWHITEFIXUP		0x0004		/**< Don't fix scum dot */
#define FSIcc_FLAGS_HIGHRESPRECALC			0x0400		/**< Use more memory to give better accurancy */
#define FSIcc_FLAGS_LOWRESPRECALC			0x0800		/**< Use less memory to minimize resources */
#define FSIcc_FLAGS_GAMUTCHECK				0x1000		/**< Out of Gamut alarm */
#define FSIcc_FLAGS_SOFTPROOFING			0x4000		/**< Do soft proofing */


/**@brief the h_samp_factor and v_samp_factor of each color component*/
struct FS_Jpeg_Samp_Param
{
	FS_INT32 h_samp_factor; /* horizontal sampling factor (1..4) */
	FS_INT32 v_samp_factor; /* vertical sampling factor (1..4) */
};

 /** @brief Define the filter type of png */
enum FS_PNG_FILTER
{
	FSNO_FILTER = 0x00,
	FSFILTER_NONE = 0x08,
	FSFILTER_SUB = 0x10,
	FSFILTER_UP = 0x20,
	FSFILTER_AVG = 0x40,
	FSFILTER_PAETH = 0x80,
	FSFILTER_ADAPTIVE = FSFILTER_NONE | FSFILTER_SUB | FSFILTER_UP | FSFILTER_AVG | FSFILTER_PAETH
};

/** @brief Format Flags */
enum FS_JPEG_FORMAT
{
	FSJPEGSTANDARD,				// standard format
	FSJPEGOPTIMIZED,			// optimized format
	FSJPEGPROGRESSIVE,			// Libjpeg turbo recommended progressive format
	FSJPEGPROGRESSIVE_3_SCANS,	// progressive format, 3 scans
	FSJPEGPROGRESSIVE_4_SCANS,	// progressive format, 4 scans
	FSJPEGPROGRESSIVE_5_SCANS		// progressive format, 5 scans
};

/** @brief Image type. */
enum FS_IMAGE_TYPE
{
	FS_IMAGE_PNG,			// png type
	FS_IMAGE_BMP,			// bmp type
	FS_IMAGE_ICON           // icon type
};
/* @OBJEND */


/* @OBJSTART FS_JpxEncoder */
#ifndef FS_JPXENCODER
#define	FS_JPXENCODER
/**
* @brief JPX encoder, providing jpeg2000 encoding.
*
* JPX decoder using luratech or kakadu or openjpeg.
*/
typedef struct _t_FS_JpxEncoder* FS_JpxEncoder;
#endif

enum FS_JP2_Color_Space
{
	FS_JP2_Colorspace_Gray = 10,	// for grayscale images
	FS_JP2_Colorspace_RGBa = 20,	// for sRGB images
	FS_JP2_Colorspace_RGB_YCCa = 30,	// for sRGB YCbCr images
	FS_JP2_Colorspace_ICCa = 40,   // for ICC images
	FS_JP2_Colorspace_CMYKa = 50	// for CMYK images
};
/* @OBJEND */

/* @OBJSTART FS_ProgressiveJpxEncoder */
#ifndef FS_PROGRESSIVEJPXENCODER
#define	FS_PROGRESSIVEJPXENCODER
/**
* @brief Progressive JPX encoder, providing jpeg2000 encoding.
*
* 
*/
typedef struct _t_FS_ProgressiveJpxEncoder* FS_ProgressiveJpxEncoder;
#endif

#define FS_JPX_COMPRESSION_LEVEL_LOSSLESS		1
#define FS_JPX_COMPRESSION_LEVEL_MAXIMUM		2
#define FS_JPX_COMPRESSION_LEVEL_HIGH			4
#define FS_JPX_COMPRESSION_LEVEL_MEDIUM		    8
#define FS_JPX_COMPRESSION_LEVEL_LOW			16
#define FS_JPX_COMPRESSION_LEVEL_MINIMUM		32
#define FS_JPX_COMPRESSION_LEVEL_USERDEFINED	64 // using user defined bpp

enum FS_ProgressiveJpx_EncodeStatus {
	FS_ProgressiveJpx_Ready,				/**< Ready. */
	FS_ProgressiveJpx_ToBeContinued,		/**< To be continued. */
	FS_ProgressiveJpx_Done,				/**< Done. */
	FS_ProgressiveJpx_Failed				/**< Failed. */
} ;
/* @OBJEND */

/* @OBJSTART FS_VectorF */
#ifndef FS_VECTORF
#define	FS_VECTORF
/**
* @brief
*
*
*/
typedef struct _t_FS_VectorF* FS_VectorF;
#endif
/* @OBJEND */


/* @OBJSTART FS_WebpModuleDecoder */
#ifndef FS_WEBMODULEDECODER
#define	FS_WEBMODULEDECODER
/**
* @brief  WEBP encoder, providing WEBP encoding. 
*
*
*/
typedef struct _t_FS_WebpModuleDecoder* FS_WebpModuleDecoder;
#endif
/* @OBJEND */

/* @OBJSTART FS_PrivateData */
#ifndef FS_PRIVATEDATA
#define	FS_PRIVATEDATA
/**
* @brief
*
*
*/
typedef struct _t_FS_PrivateData* FS_PrivateData;
#endif

typedef void(*FS_PD_CALLBACK_FREEDATA)(FS_LPVOID pData);

/* @OBJEND */

/* @OBJSTART FDF_DestructObject */
#ifndef FPD_DESTRUCTOBJECT
#define	FPD_DESTRUCTOBJECT
	/**
	* @brief
	*/
typedef struct _t_FPD_DestructObject* FPD_DestructObject;
#endif
/* @OBJEND */

#define FS_UnCompress_OK            0
#define FS_UnCompress_STREAM_END    1
#define FS_UnCompress_NEED_DICT     2
#define FS_UnCompress_ERRNO        (-1)
#define FS_UnCompress_STREAM_ERROR (-2)
#define FS_UnCompress_DATA_ERROR   (-3)
#define FS_UnCompress_MEM_ERROR    (-4)
#define FS_UnCompress_BUF_ERROR    (-5)
#define FS_UnCompress_VERSION_ERROR (-6)

#ifdef __cplusplus
};
#endif

#endif
/** @} */


/*@}*/
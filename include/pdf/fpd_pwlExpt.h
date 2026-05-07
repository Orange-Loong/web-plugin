/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.

 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.

 ---------------------------------------------------------------------

fpd_convertExpT.h

 - Types, macros, structures, etc. required to use the FPDLayer HFT.

*********************************************************************/

#ifndef FPD_PWLEXPT_H
#define FPD_PWLEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif


/* @OBJSTART FPD_CPWL_ListBox */
#ifndef FPD_CPWLLISTBOX
#define	FPD_CPWLLISTBOX
/**
* @brief
*/
	typedef struct _t_FPD_CPWL_ListBox* FPD_CPWL_ListBox;
#endif	

/* @ENUMSTART FPD_FWL_VKEYCODE*/
/** @brief Enumeration for Virtual Key Codes */
	enum FPD_FWL_VKEYCODE
	{
		FPD_FWL_VKEY_Back = 0x08,			   /**< @brief  Backspace key. */
		FPD_FWL_VKEY_Tab = 0x09,			   /**< @brief  Tab key. */
		FPD_FWL_VKEY_Clear = 0x0C,			   /**< @brief  Clear key. */
		FPD_FWL_VKEY_Return = 0x0D,			   /**< @brief  Enter key. */
		FPD_FWL_VKEY_Shift = 0x10,			   /**< @brief  Shift key. */
		FPD_FWL_VKEY_Control = 0x11,		   /**< @brief  Ctrl key. */
		FPD_FWL_VKEY_Menu = 0x12,			   /**< @brief  Menu key. */
		FPD_FWL_VKEY_Pause = 0x13,			   /**< @brief  Pause Break key. */
		FPD_FWL_VKEY_Capital = 0x14,		   /**< @brief  Caps Lock key. */
		FPD_FWL_VKEY_Kana = 0x15,			   /**< @brief  Used with IME. */
		FPD_FWL_VKEY_Hangul = 0x15,			   /**< @brief  Used with IME. */
		FPD_FWL_VKEY_Junja = 0x17,			   /**< @brief  Used with IME. */
		FPD_FWL_VKEY_Final = 0x18,			   /**< @brief  Used with IME. */
		FPD_FWL_VKEY_Hanja = 0x19,			   /**< @brief  Used with IME. */
		FPD_FWL_VKEY_Kanji = 0x19,			   /**< @brief  Used with IME. */
		FPD_FWL_VKEY_Escape = 0x1B,			   /**< @brief  ESC key. */
		FPD_FWL_VKEY_Convert = 0x1C,		   /**< @brief  Used with IME. */
		FPD_FWL_VKEY_NonConvert = 0x1D,		   /**< @brief  Used with IME. */
		FPD_FWL_VKEY_Accept = 0x1E,			   /**< @brief  Used with IME. */
		FPD_FWL_VKEY_ModeChange = 0x1F,		   /**< @brief  Used with IME. */
		FPD_FWL_VKEY_Space = 0x20,			   /**< @brief  Space key. */
		FPD_FWL_VKEY_Prior = 0x21,			   /**< @brief  Page Up key. */
		FPD_FWL_VKEY_Next = 0x22,			   /**< @brief  Page Down key. */
		FPD_FWL_VKEY_End = 0x01000011,         /**< @brief  End key. */
		FPD_FWL_VKEY_Home = 0x01000010,        /**< @brief  Home key. */
		FPD_FWL_VKEY_Left = 0x01000012,        /**< @brief  Left arrow key. */
		FPD_FWL_VKEY_Up = 0x01000013,          /**< @brief  Up arrow key. */
		FPD_FWL_VKEY_Right = 0x01000014,       /**< @brief  Right arrow key. */
		FPD_FWL_VKEY_Down = 0x01000015,        /**< @brief  Down arrow key. */
		FPD_FWL_VKEY_Select = 0x29,			   /**< @brief  Select key.*/
		FPD_FWL_VKEY_Print = 0x2A,			   /**< @brief  Print key. */
		FPD_FWL_VKEY_Execute = 0x2B,		   /**< @brief  Execute key. */
		FPD_FWL_VKEY_Snapshot = 0x2C,		   /**< @brief  Print Screen key. */
		FPD_FWL_VKEY_Insert = 0x2D,			   /**< @brief  Insert key. */
		FPD_FWL_VKEY_Delete = 0x2E,			   /**< @brief  Delete key. */
		FPD_FWL_VKEY_Help = 0x2F,			   /**< @brief  Help key. */
		FPD_FWL_VKEY_0 = 0x30,				   /**< @brief  0 key. */
		FPD_FWL_VKEY_1 = 0x31,				   /**< @brief  1 key. */
		FPD_FWL_VKEY_2 = 0x32,				   /**< @brief  2 key. */
		FPD_FWL_VKEY_3 = 0x33,				   /**< @brief  3 key. */
		FPD_FWL_VKEY_4 = 0x34,				   /**< @brief  4 key. */
		FPD_FWL_VKEY_5 = 0x35,				   /**< @brief  5 key. */
		FPD_FWL_VKEY_6 = 0x36,				   /**< @brief  6 key. */
		FPD_FWL_VKEY_7 = 0x37,				   /**< @brief  7 key. */
		FPD_FWL_VKEY_8 = 0x38,				   /**< @brief  8 key. */
		FPD_FWL_VKEY_9 = 0x39,				   /**< @brief  9 key. */
		FPD_FWL_VKEY_A = 0x41,				   /**< @brief  A key. */
		FPD_FWL_VKEY_B = 0x42,				   /**< @brief  B key. */
		FPD_FWL_VKEY_C = 0x43,				   /**< @brief  C key. */
		FPD_FWL_VKEY_D = 0x44,				   /**< @brief  D key. */
		FPD_FWL_VKEY_E = 0x45,				   /**< @brief  E key. */
		FPD_FWL_VKEY_F = 0x46,				   /**< @brief  F key. */
		FPD_FWL_VKEY_G = 0x47,				   /**< @brief  G key. */
		FPD_FWL_VKEY_H = 0x48,				   /**< @brief  H key. */
		FPD_FWL_VKEY_I = 0x49,				   /**< @brief  I key. */
		FPD_FWL_VKEY_J = 0x4A,				   /**< @brief  J key. */
		FPD_FWL_VKEY_K = 0x4B,				   /**< @brief  K key. */
		FPD_FWL_VKEY_L = 0x4C,				   /**< @brief  L key. */
		FPD_FWL_VKEY_M = 0x4D,				   /**< @brief  M key. */
		FPD_FWL_VKEY_N = 0x4E,				   /**< @brief  N key. */
		FPD_FWL_VKEY_O = 0x4F,				   /**< @brief  O key. */
		FPD_FWL_VKEY_P = 0x50,				   /**< @brief  P key. */
		FPD_FWL_VKEY_Q = 0x51,				   /**< @brief  Q key. */
		FPD_FWL_VKEY_R = 0x52,				   /**< @brief  R key. */
		FPD_FWL_VKEY_S = 0x53,				   /**< @brief  S key. */
		FPD_FWL_VKEY_T = 0x54,				   /**< @brief  T key. */
		FPD_FWL_VKEY_U = 0x55,				   /**< @brief  U key. */
		FPD_FWL_VKEY_V = 0x56,				   /**< @brief  V key. */
		FPD_FWL_VKEY_W = 0x57,				   /**< @brief  W key. */
		FPD_FWL_VKEY_X = 0x58,				   /**< @brief  X key. */
		FPD_FWL_VKEY_Y = 0x59,				   /**< @brief  Y key. */
		FPD_FWL_VKEY_Z = 0x5A,				   /**< @brief  Z key. */
		FPD_FWL_VKEY_LWin = 0x5B,			   /**< @brief  Left windows key(Microsoft keyboard). */
		FPD_FWL_VKEY_Command = 0x5B,		   /**< @brief  Command key.*/
		FPD_FWL_VKEY_RWin = 0x5C,			   /**< @brief  Right windows key(Microsoft keyboard). */
		FPD_FWL_VKEY_Apps = 0x5D,			   /**< @brief  Applications key(Microsoft keyboard). */
		FPD_FWL_VKEY_Sleep = 0x5F,			   /**< @brief  Sleeping key. */
		FPD_FWL_VKEY_NumPad0 = 0x60,		   /**< @brief  0 key in the numeric keypad. */
		FPD_FWL_VKEY_NumPad1 = 0x61,		   /**< @brief  1 key in the numeric keypad. */
		FPD_FWL_VKEY_NumPad2 = 0x62,		   /**< @brief  2 key in the numeric keypad. */
		FPD_FWL_VKEY_NumPad3 = 0x63,		   /**< @brief  3 key in the numeric keypad. */
		FPD_FWL_VKEY_NumPad4 = 0x64,		   /**< @brief  4 key in the numeric keypad. */
		FPD_FWL_VKEY_NumPad5 = 0x65,		   /**< @brief  5 key in the numeric keypad. */
		FPD_FWL_VKEY_NumPad6 = 0x66,		   /**< @brief  6 key in the numeric keypad. */
		FPD_FWL_VKEY_NumPad7 = 0x67,		   /**< @brief  7 key in the numeric keypad. */
		FPD_FWL_VKEY_NumPad8 = 0x68,		   /**< @brief  8 key in the numeric keypad. */
		FPD_FWL_VKEY_NumPad9 = 0x69,		   /**< @brief  9 key in the numeric keypad. */
		FPD_FWL_VKEY_Multiply = 0x6A,		   /**< @brief  Multiply key in the numeric keypad. */
		FPD_FWL_VKEY_Add = 0x6B,			   /**< @brief  Plus key in the numeric keypad. */
		FPD_FWL_VKEY_Separator = 0x6C,		   /**< @brief  Enter key in the numeric keypad. */
		FPD_FWL_VKEY_Subtract = 0x6D,		   /**< @brief  Minus key in the numeric keypad. */
		FPD_FWL_VKEY_Decimal = 0x6E,		   /**< @brief  Dot key in the numeric keypad. */
		FPD_FWL_VKEY_Divide = 0x6F,			   /**< @brief  Slash key in the numeric keypad. */
		FPD_FWL_VKEY_F1 = 0x70,				   /**< @brief  F1 key. */
		FPD_FWL_VKEY_F2 = 0x71,				   /**< @brief  F2 key. */
		FPD_FWL_VKEY_F3 = 0x72,				   /**< @brief  F3 key. */
		FPD_FWL_VKEY_F4 = 0x73,				   /**< @brief  F4 key. */
		FPD_FWL_VKEY_F5 = 0x74,				   /**< @brief  F5 key. */
		FPD_FWL_VKEY_F6 = 0x75,				   /**< @brief  F6 key. */
		FPD_FWL_VKEY_F7 = 0x76,				   /**< @brief  F7 key. */
		FPD_FWL_VKEY_F8 = 0x77,				   /**< @brief  F8 key. */
		FPD_FWL_VKEY_F9 = 0x78,				   /**< @brief  F9 key. */
		FPD_FWL_VKEY_F10 = 0x79,			   /**< @brief  F10 key. */
		FPD_FWL_VKEY_F11 = 0x7A,			   /**< @brief  F11 key. */
		FPD_FWL_VKEY_F12 = 0x7B,			   /**< @brief  F12 key. */
		FPD_FWL_VKEY_F13 = 0x7C,			   /**< @brief  F13 key. */
		FPD_FWL_VKEY_F14 = 0x7D,			   /**< @brief  F14 key. */
		FPD_FWL_VKEY_F15 = 0x7E,			   /**< @brief  F15 key. */
		FPD_FWL_VKEY_F16 = 0x7F,			   /**< @brief  F16 key. */
		FPD_FWL_VKEY_F17 = 0x80,			   /**< @brief  F17 key. */
		FPD_FWL_VKEY_F18 = 0x81,			   /**< @brief  F18 key. */
		FPD_FWL_VKEY_F19 = 0x82,			   /**< @brief  F19 key. */
		FPD_FWL_VKEY_F20 = 0x83,			   /**< @brief  F20 key. */
		FPD_FWL_VKEY_F21 = 0x84,			   /**< @brief  F21 key. */
		FPD_FWL_VKEY_F22 = 0x85,			   /**< @brief  F22 key. */
		FPD_FWL_VKEY_F23 = 0x86,			   /**< @brief  F23 key. */
		FPD_FWL_VKEY_F24 = 0x87,			   /**< @brief  F24 key. */
		FPD_FWL_VKEY_NunLock = 0x90,		   /**< @brief  Num Lock key. */
		FPD_FWL_VKEY_Scroll = 0x91,			   /**< @brief  Scroll Lock key. */
		FPD_FWL_VKEY_LShift = 0xA0,			   /**< @brief  Left Shift key. */
		FPD_FWL_VKEY_RShift = 0xA1,			   /**< @brief  Right Shift key. */
		FPD_FWL_VKEY_LControl = 0xA2,		   /**< @brief  Left Ctrl key. */
		FPD_FWL_VKEY_RControl = 0xA3,		   /**< @brief  Right Ctrl key. */
		FPD_FWL_VKEY_LMenu = 0xA4,			   /**< @brief  Left Alt key. */
		FPD_FWL_VKEY_RMenu = 0xA5,			   /**< @brief  Right Alt key. */
		FPD_FWL_VKEY_BROWSER_Back = 0xA6,	  /**< @brief Browser back key. */
		FPD_FWL_VKEY_BROWSER_Forward = 0xA7,   /**< @brief Browser forward key. */
		FPD_FWL_VKEY_BROWSER_Refresh = 0xA8,   /**< @brief Browser refresh key. */
		FPD_FWL_VKEY_BROWSER_Stop = 0xA9,	  /**< @brief Browser stop key. */
		FPD_FWL_VKEY_BROWSER_Search = 0xAA,	/**< @brief Browser search key. */
		FPD_FWL_VKEY_BROWSER_Favorites = 0xAB, /**< @brief Browser favorites key. */
		FPD_FWL_VKEY_BROWSER_Home = 0xAC,	  /**< @brief Browser home key. */
		FPD_FWL_VKEY_VOLUME_Mute = 0xAD,	   /**< @brief Volume mute key. */
		FPD_FWL_VKEY_VOLUME_Down = 0xAE,	   /**< @brief Volume down key. */
		FPD_FWL_VKEY_VOLUME_Up = 0xAF,		   /**< @brief Volume up key. */
		FPD_FWL_VKEY_MEDIA_NEXT_Track = 0xB0,  /**< @brief Next track key. */
		FPD_FWL_VKEY_MEDIA_PREV_Track = 0xB1,  /**< @brief Previous track key. */
		FPD_FWL_VKEY_MEDIA_Stop = 0xB2,		   /**< @brief Stop media key. */
		FPD_FWL_VKEY_MEDIA_PLAY_Pause = 0xB3,  /**< @brief Play/pause media key. */
		FPD_FWL_VKEY_MEDIA_LAUNCH_Mail = 0xB4, /**< @brief [media] Launch mail key. */
		FPD_FWL_VKEY_MEDIA_LAUNCH_MEDIA_Select = 0xB5, /**< @brief [media] Launch media select key. */
		FPD_FWL_VKEY_MEDIA_LAUNCH_APP1 = 0xB6,		   /**< @brief [media] Launch APP1 key. */
		FPD_FWL_VKEY_MEDIA_LAUNCH_APP2 = 0xB7,		   /**< @brief [media] Launch APP2 key. */
		FPD_FWL_VKEY_OEM_1 = 0xBA,					   /**< @brief ; : key. */
		FPD_FWL_VKEY_OEM_Plus = 0xBB,				   /**< @brief = + key. */
		FPD_FWL_VKEY_OEM_Comma = 0xBC,				   /**< @brief , < key. */
		FPD_FWL_VKEY_OEM_Minus = 0xBD,				   /**< @brief _ key. */
		FPD_FWL_VKEY_OEM_Period = 0xBE,				   /**< @brief . > key. */
		FPD_FWL_VKEY_OEM_2 = 0xBF,					   /**< @brief / ? key. */
		FPD_FWL_VKEY_OEM_3 = 0xC0,					   /**< @brief ` ~ key. */
		FPD_FWL_VKEY_OEM_4 = 0xDB,					   /**< @brief [ { key. */
		FPD_FWL_VKEY_OEM_5 = 0xDC,					   /**< @brief \ | key. */
		FPD_FWL_VKEY_OEM_6 = 0xDD,					   /**< @brief ] } key. */
		FPD_FWL_VKEY_OEM_7 = 0xDE,					   /**< @brief ' " key. */
		FPD_FWL_VKEY_OEM_8 = 0xDF, /**< @brief Used for miscellaneous characters; it can vary by keyboard. */
		FPD_FWL_VKEY_OEM_102 = 0xE2, /**< @brief Either the angle bracket key or the backslash key on the RT
									102-key keyboard */
		FPD_FWL_VKEY_ProcessKey = 0xE5, /**< @brief IME PROCESS key */
		FPD_FWL_VKEY_Packet = 0xE7,			  /**< @brief Used to pass Unicode characters as if they were keystrokes. */
		FPD_FWL_VKEY_Attn = 0xF6, /**< @brief Attn key. */
		FPD_FWL_VKEY_Crsel = 0xF7,	 /**< @brief CrSel key. */
		FPD_FWL_VKEY_Exsel = 0xF8,	 /**< @brief ExSel key. */
		FPD_FWL_VKEY_Ereof = 0xF9,	 /**< @brief Erase EOF key. */
		FPD_FWL_VKEY_Play = 0xFA,	  /**< @brief Play key. */
		FPD_FWL_VKEY_Zoom = 0xFB,	  /**< @brief Zoom key. */
		FPD_FWL_VKEY_NoName = 0xFC,	/**< @brief The key without a name. */
		FPD_FWL_VKEY_PA1 = 0xFD,	   /**< @brief PA1 key. */
		FPD_FWL_VKEY_OEM_Clear = 0xFE, /**< @brief Clear key */
		FPD_FWL_VKEY_Unknown = 0,	  /**< @brief An unkown key. */
	};
/* @ENUMEND */

/* @DEFGROUPSTART listbox styles. */
	/**
	* @brief listbox styles.
	*/
	/*@{*/
	#define FPD_PLBS_MULTIPLESEL 0x0001L
	#define FPD_PLBS_HOVERSEL    0x0008L
	/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART combobox styles. */
	/**
	* @brief combobox styles.
	*/
	/*@{*/
	#define FPD_PCBS_ALLOWCUSTOMTEXT 0x0001L
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_CPWL_ComboBox */
#ifndef FPD_CPWLCOMBOBOX
#define	FPD_CPWLCOMBOBOX
/**
* @brief
*/
	typedef struct _t_FPD_CPWL_ComboBox* FPD_CPWL_ComboBox;
#endif	
/* @OBJEND */

/* @OBJSTART FPD_CPWL_CheckBox */
#ifndef FPD_CPWLCHECKBOX
#define	FPD_CPWLCHECKBOX
/**
* @brief
*/
	typedef struct _t_FPD_CPWL_CheckBox* FPD_CPWL_CheckBox;
#endif	
	/* @OBJEND */

/* @OBJSTART FPD_CPWL_RadioButton */
#ifndef FPD_CPWLRADIOBUTTON
#define	FPD_CPWLRADIOBUTTON
/**
* @brief
*/
	typedef struct _t_FPD_CPWL_RadioButton* FPD_CPWL_RadioButton;
#endif	
	/* @OBJEND */

/* @OBJSTART FPD_CPWL_PushButton */
#ifndef FPD_CPWLPUSHBUTTON
#define	FPD_CPWLPUSHBUTTON
/**
* @brief
*/
	typedef struct _t_FPD_CPWL_PushButton* FPD_CPWL_PushButton;
#endif	
	/* @OBJEND */

/* @OBJSTART FPD_CPWL_Icon */
#ifndef FPD_CPWLICON
#define	FPD_CPWLICON
/**
* @brief
*/
	typedef struct _t_FPD_CPWL_Icon* FPD_CPWL_Icon;
#endif	

#define FPD_PWL_REVIEWSTATE_NONE       0
#define FPD_PWL_REVIEWSTATE_ACCEPTED   1
#define FPD_PWL_REVIEWSTATE_REJECTED   2
#define FPD_PWL_REVIEWSTATE_CANCELLED  3
#define FPD_PWL_REVIEWSTATE_COMPLETED  4
#define FPD_PWL_REVIEWSTATE_DEFERRED   5
#define FPD_PWL_REVIEWSTATE_FUTURE     6

/* @OBJEND */

/* @OBJSTART FPD_CPWL_EditCtrl */
#ifndef FPD_CPWLEDITCTRL
#define	FPD_CPWLEDITCTRL
/**
* @brief
*/
	typedef struct _t_FPD_CPWL_EditCtrl* FPD_CPWL_EditCtrl;
#endif	
/* @OBJEND */

#ifndef FPD_SPELLCHECK
#define FPD_SPELLCHECK
	typedef struct _t_FPD_SpellCheck*  FPD_SpellCheck;
#endif

/* @CALLBACKGROUPSTART FPD_PWLSpellCheckCallbacks */
/**
 * @brief 
 * @deprecated Internal use
 *
 */
	typedef struct _fpd_pwlspellcheck_callbacks_
	{
		/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_VariableTextProviderCallbacksRec</a>). */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		FS_BOOLEAN(*FPDPWLCheckWord)(FS_LPVOID clientData, FS_LPCWSTR sWord);

		void(*FPDPWLSuggestWords)(FS_LPVOID clientData, FS_LPCWSTR sWord, FS_WideStringArray* sSuggest);

		FS_DWORD(*FPDPWLGetSCCodePage)(FS_LPVOID clientData);

		FS_BOOLEAN(*FPDPWLIsSCAvalible)(FS_LPVOID clientData);

		FS_BOOLEAN(*FPDPWLIsCurSCSupWord)(FS_LPVOID clientData, FS_WORD sUnicode);

	}FPD_PWLSpellCheckCallbacksRec, *FPD_PWLSpellCheckCallbacks;
/* @CALLBACKGROUPEND */

/* @OBJSTART FPD_CPWL_Signature */
#ifndef FPD_CPWLSIGNATURE
#define	FPD_CPWLSIGNATURE
/**
* @brief
*/
	typedef struct _t_FPD_CPWL_Signature* FPD_CPWL_Signature;
#endif	
/* @OBJEND */


#ifdef __cplusplus
};
#endif

#endif
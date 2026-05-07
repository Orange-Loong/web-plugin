#ifndef FPD_FEDITEXPT_H
#define FPD_FEDITEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "fpd_objsExpT.h"
#endif

#ifndef FPD_RESOURCEEXPT_H
#include "fpd_resourceExpT.h"
#endif

#ifndef FPD_PWLEXPT_H
#include "fpd_pwlExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

	
#ifndef FR_VTWORDPLACE
#define FR_VTWORDPLACE

typedef struct _t_FR_VTWordPlace* FR_VTWordPlace;
#endif

#ifndef FR_VTWORDRANGE
#define FR_VTWORDRANGE

typedef struct _t_FR_VTWordRange* FR_VTWordRange;
#endif
	
#ifndef FR_VTSECPROPS
#define FR_VTSECPROPS

typedef struct _t_FR_VTSecProps* FR_VTSecProps;
#endif

#ifndef FR_VTWORDPROPS
#define FR_VTWORDPROPS

typedef struct _t_FR_VTWordProps* FR_VTWordProps;
#endif

#ifndef FR_VTWORD
#define FR_VTWORD

typedef struct _t_FR_VTWord* FR_VTWord;

#define FPD_PVTWORD_STYLE_NORMAL                 0x0000L
#define FPD_PVTWORD_STYLE_HIGHLIGHT              0x0001L
#define FPD_PVTWORD_STYLE_UNDERLINE              0x0002L
#define FPD_PVTWORD_STYLE_CROSSOUT               0x0004L
#define FPD_PVTWORD_STYLE_SQUIGGLY               0x0008L
#define FPD_PVTWORD_STYLE_DUALCROSSOUT           0x0010L
#define FPD_PVTWORD_STYLE_FORMXOBJECT            0x0020L
#define FPD_PVTWORD_STYLE_ITALIC                 0x40
#define FPD_PVTWORD_STYLE_LINE_END_TYPESET_SPACE 0x0080L
#define FPD_PVTWORD_STYLE_BOLD                   0x40000

#define FPD_PVTWORD_SCRIPT_NORMAL                0
#define FPD_PVTWORD_SCRIPT_SUPER                 1
#define FPD_PVTWORD_SCRIPT_SUB                   2

#endif

#ifndef FRFMTRIBOOL
#define FRFMTRIBOOL
enum FRFMTribool
{
	FR_FMFalse = 0,
	FR_FMTrue,
	FR_FMIndeterminate
};
#endif

#ifndef FR_EDIT_ITERATOR
#define FR_EDIT_ITERATOR

typedef struct _t_FR_Edit_Iterator* FR_Edit_Iterator;
#endif

#ifndef FR_VARIABLETEXT
#define FR_VARIABLETEXT

typedef struct _t_FR_VariableText* FR_VariableText;
#endif

#ifndef FR_VARIABLETEXT_PROVIDER
#define FR_VARIABLETEXT_PROVIDER
typedef struct _t_FR_VariableText_Provider* FR_VariableText_Provider;
#endif

#ifndef FR_EDIT_UNDOITEM
#define FR_EDIT_UNDOITEM

typedef struct _t_FR_Edit_UndoItem* FR_Edit_UndoItem;
#endif



#ifndef FR_EDITUNDOITEM_CALLBACK
#define FR_EDITUNDOITEM_CALLBACK
/* @CALLBACKGROUPSTART FR_EditUndoItemCallbacks */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct _fr_editundoitem_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EditUndoItemCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void(*FREditUndoItemUndo)(FS_LPVOID clientData);

	void(*FREditUndoItemRedo)(FS_LPVOID clientData);

	void(*FREditUndoItemGetUndoTitle)(FS_LPVOID clientData, FS_WideString outTitle);

	void(*FREditUndoItemRefersh)(FS_LPVOID clientData);

	FS_BOOL(*FREditUndoItemIsPaint)(FS_LPVOID clientData);

	void(*FREditUndoItemSetFirst)(FS_LPVOID clientData, FS_BOOL bFirst);

	FS_BOOL(*FREditUndoItemIsFirst)(FS_LPVOID clientData);

	void(*FREditUndoItemSetLast)(FS_LPVOID clientData, FS_BOOL bLast);

	FS_BOOL(*FREditUndoItemIsLast)(FS_LPVOID clientData);

	void(*FREditUndoItemRelease)(FS_LPVOID clientData);

}FR_EditUndoItemCallbacksRec, *FR_EditUndoItemCallbacks;
/* @CALLBACKGROUPEND */
#endif

#ifndef FR_EDITDRAWNOTIFY_CALLBACK
#define FR_EDITDRAWNOTIFY_CALLBACK
/* @CALLBACKGROUPSTART FR_EditDrawNotifyCallbacks */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct _fr_editdrawnotify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EditDrawNotifyCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOL(*FREditDrawNotifyGetDrawData)(FS_LPVOID clientData, FPD_RenderContext *pContext, FPD_RenderOptions* pOptions, void* pKey);

}FR_EditDrawNotifyCallbacksRec, *FR_EditDrawNotifyCallbacks;
/* @CALLBACKGROUPEND */
#endif

#ifndef FR_EDITORPONOTIFY_CALLBACK
#define FR_EDITORPONOTIFY_CALLBACK
/* @CALLBACKGROUPSTART FR_EditOprNotifyCallbacks */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct _fr_editoprnotify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EditOprNotifyCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void(*FREditOprNotifyOnInsertWord)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);

	void(*FREditOprNotifyOnInsertReturn)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);

	void(*FREditOprNotifyOnBackSpace)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);

	void(*FREditOprNotifyOnDelete)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);

	void(*FREditOprNotifyOnClear)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);

	void(*FREditOprNotifyOnInsertText)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);

	void(*FREditOprNotifyOnSetText)(FS_LPVOID clientData, FR_VTWordPlace wordPlace, FR_VTWordPlace oldWordPlace);

	void(*FREditOprNotifyOnAddUndo)(FS_LPVOID clientData, FR_Edit_UndoItem undoItem);

}FR_EditOprNotifyCallbacksRec, *FR_EditOprNotifyCallbacks;
/* @CALLBACKGROUPEND */
#endif

#ifndef FR_EDITNOTIFY_CALLBACK
#define FR_EDITNOTIFY_CALLBACK
/* @CALLBACKGROUPSTART FR_EditNotifyCallbacks */
/**
 * @brief
 * @deprecated Internal use
 *
 */
typedef struct _fr_editnotify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_EditNotifyCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void(*FREditNotifyOnSetScrollInfoX)(FS_LPVOID clientData, FS_FLOAT fPlateMin, FS_FLOAT fPlateMax, FS_FLOAT fContentMin, FS_FLOAT fContentMax,
		FS_FLOAT fSmallStep, FS_FLOAT fBigStep);

	void(*FREditNotifyOnSetScrollInfoY)(FS_LPVOID clientData, FS_FLOAT fPlateMin, FS_FLOAT fPlateMax, FS_FLOAT fContentMin, FS_FLOAT fContentMax,
		FS_FLOAT fSmallStep, FS_FLOAT fBigStep);

	void(*FREditNotifyOnSetScrollPosX)(FS_LPVOID clientData, FS_FLOAT fx);

	void(*FREditNotifyOnSetScrollPosY)(FS_LPVOID clientData, FS_FLOAT fy);

	void(*FREditNotifyOnSetCaret)(FS_LPVOID clientData, FS_BOOL bVisible, FS_FLOAT headX, FS_FLOAT headY,
		FS_FLOAT footX, FS_FLOAT footY, FR_VTWordPlace wordPlace);

	void(*FREditNotifyOnCaretChange)(FS_LPVOID clientData, FR_VTSecProps secProps, FR_VTWordProps wordProps);

	void(*FREditNotifyOnContentChange)(FS_LPVOID clientData, FS_FloatRect rcContent);

	void(*FREditNotifyOnInvalidateRect)(FS_LPVOID clientData, FS_FloatRect rect);

	void(*FREditNotifyOnAfterRearrange)(FS_LPVOID clientData);

}FR_EditNotifyCallbacksRec, *FR_EditNotifyCallbacks;
/* @CALLBACKGROUPEND */
#endif


/* @OBJSTART FPD_PWLCREATEPARAM */
#ifndef FPD_PWL_CREATEPARAM
#define FPD_PWL_CREATEPARAM
typedef struct _t_FPD_PWLCREATEPARAM* FPD_PWLCREATEPARAM;
#endif
/* @OBJEND */

/* @OBJSTART FPD_VTWordProps */
#ifndef FPD_VTWORDPROPS
#define FPD_VTWORDPROPS
typedef FR_VTWordProps  FPD_VTWordProps;
#endif 
/* @OBJEND */


/* @OBJSTART FPD_Edit */
#ifndef FPD_EDIT
#define FPD_EDIT
typedef FR_Edit  FPD_Edit;
#endif 

enum FPD_FillMode_Value
{
	FPDFillMode_None,
	FPDFillMode_Repeat,	
};

enum FPD_Edit_ListStyleType
{
	FPDkListStyle_None,
	FPDkListStyle_Repeat,
	FPDkListStyle_Counter,
	FPDkListStyle_Unknown,
};

enum FPD_Edit_CounterStyleType
{
	FPDkCounterStyle_None,
	FPDkCounterStyle_LowerLatin,
	FPDkCounterStyle_UpperLatin,
	FPDkCounterStyle_LowerRoman,
	FPDkCounterStyle_UpperRoman,
	FPDkCounterStyle_Decimal,
	FPDkCounterStyle_CJKDecimal,
	FPDkCounterStyle_Unknown,
};

enum FPD_Edit_PrefixSuffixType
{
	FPDkPrefixSuffix_None,			
	FPDkPrefixSuffix_DotSuffix,	   
	FPDkPrefixSuffix_RParenSuffix,	
	FPDkPrefixSuffix_ParenAround,	
	FPDkPrefixSuffix_Unknown,
};

typedef struct __FPDEDIT_ListStyleDescriptor__
{
	FPD_Edit_ListStyleType m_eListStyle;
	FPD_Edit_CounterStyleType m_eCounterStyle;
	FPD_Edit_PrefixSuffixType m_ePrefixSuffix;

	__FPDEDIT_ListStyleDescriptor__()
	{
		m_eListStyle = FPD_Edit_ListStyleType::FPDkListStyle_None;
		m_eCounterStyle = FPD_Edit_CounterStyleType::FPDkCounterStyle_None;
		m_ePrefixSuffix = FPD_Edit_PrefixSuffixType::FPDkPrefixSuffix_None;
	}
}FPDEDIT_ListStyleDescriptor, *PFPDEDIT_ListStyleDescriptor;

/* @OBJEND */

#ifndef FPD_VARIABLETEXTPROVIDER
#define FPD_VARIABLETEXTPROVIDER
typedef FR_VariableText_Provider  FPD_VariableText_Provider;
#endif 

#ifndef FPD_EDITNOTIFYCALLBACKS
#define FPD_EDITNOTIFYCALLBACKS
typedef FR_EditNotifyCallbacks  FPD_EditNotifyCallbacks;
#endif 

#ifndef FPD_EDITOPRNOFITYCALLBACKS
#define FPD_EDITOPRNOFITYCALLBACKS
typedef FR_EditOprNotifyCallbacks  FPD_EditOprNotifyCallbacks;
#endif 

#ifndef FPD_EDITITERATOR
#define FPD_EDITITERATOR
typedef FR_Edit_Iterator  FPD_Edit_Iterator;
#endif 

/* @OBJSTART FPD_VariableText */
#ifndef FPD_VARIABLETEXT
#define FPD_VARIABLETEXT
typedef FR_VariableText  FPD_VariableText;
#endif 

/* @CALLBACKGROUPSTART FR_VariableTextProviderCallbacks */
/**
 * @brief Variable text provider
 * @deprecated Internal use
 *
 */
typedef struct _fpd_variabletextprovider_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_VariableTextProviderCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_INT32(*FPDVariableTextProviderGetCharWidth)(FS_LPVOID clientData, FS_INT32 nFontIndex, FS_WORD word, FS_INT32 nWordStyle);

	FS_INT32(*FPDVariableTextProviderGetCharItalicWidth)(FS_LPVOID clientData, FS_INT32 nFontIndex, FS_WORD word);

	FS_INT32(*FPDVariableTextProviderGetTypeAscent)(FS_LPVOID clientData, FS_INT32 nFontIndex);

	FS_INT32(*FPDVariableTextProviderGetTypeDescent)(FS_LPVOID clientData, FS_INT32 nFontIndex);

	FS_INT32(*FPDVariableTextProviderGetWordFontIndex)(FS_LPVOID clientData, FS_WORD word, FS_INT32 nFontIndex, FS_DWORD fontstyle, FS_DWORD nCharSet, FS_BOOL IsVertical);

	FS_BOOL(*FPDVariableTextProviderIsLatinWord)(FS_LPVOID clientData, FS_WORD word);

	FS_INT32(*FPDVariableTextProviderGetDefaultFontIndex)(FS_LPVOID clientData);

	void(*FPDVariableTextProviderSetDefaultFontIndex)(FS_LPVOID clientData, FS_INT32 nDefaultIndex);

	FS_BOOL(*FPDVariableTextProviderIsVerticalFont)(FS_LPVOID clientData, FS_INT32 nFontindex);

	FPD_Edit_FontMap(*FPDVariableTextProviderGetFontMap)(FS_LPVOID clientData);

}FPD_VariableTextProviderCallbacksRec, *FPD_VariableTextProviderCallbacks;
/* @CALLBACKGROUPEND */
/* @OBJEND */

#ifndef FPD_VTSECPROPS
#define FPD_VTSECPROPS
typedef FR_VTSecProps  FPD_VTSecProps;
#endif 

#ifndef FPD_EDITUNDOITEMCALLBACKS
#define FPD_EDITUNDOITEMCALLBACKS
typedef FR_EditUndoItemCallbacks  FPD_EditUndoItemCallbacks;
#endif 

#ifndef FPD_FMTribool
#define FPD_FMTribool
typedef FRFMTribool  FPDFMTribool;
#endif

/* @OBJSTART FPD_VTWord */
#ifndef FPD_VTWORD
#define FPD_VTWORD
typedef struct _t_FPD_VTWord*  FPD_VTWord;
#endif
/* @OBJEND */



/* @OBJSTART FPD_CPWL_Edit */
#ifndef FPD_CPWL_EDIT
#define FPD_CPWL_EDIT
typedef struct _t_FPD_CPWL_Edit* FPD_CPWL_Edit;
#endif

enum FPDPWL_EDIT_ALIGNFORMAT_H
{
	FPDPEAH_LEFT = 0,
	FPDPEAH_MIDDLE,
	FPDPEAH_RIGHT
};

enum FPDPWL_EDIT_ALIGNFORMAT_V
{
	FPDPEAV_TOP = 0,
	FPDPEAV_CENTER,
	FPDPEAV_BOTTOM
};

/* @CALLBACKGROUPSTART FPD_PWLEditNotifyCallbacks */
/**
 * @brief Variable text provider
 * @deprecated Internal use
 *
 */
typedef struct _fpd_pwledit_notify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_VariableTextProviderCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void(*FPDPWLEditOnCaretMove)(FS_LPVOID clientData, FS_INT32 x1, FS_INT32 y1, FS_INT32 x2, FS_INT32 y2);

	void(*FPDPWLEditOnCaretChange)(FS_LPVOID clientData, FS_INT32 nCaretPos);

	void(*FPDPWLEditOnContentChange)(FS_LPVOID clientData, FS_FloatRect rcContent);

	void(*FPDPWLEditOnInsertWord)(FS_LPVOID clientData, FPD_VTWordPlace place, FPD_VTWordPlace oldplace);

	void(*FPDPWLEditOnInsertReturn)(FS_LPVOID clientData, FPD_VTWordPlace place, FPD_VTWordPlace oldplace);

	void(*FPDPWLEditOnBackSpace)(FS_LPVOID clientData, FPD_VTWordPlace place, FPD_VTWordPlace oldplace);

	void(*FPDPWLEditOnDelete)(FS_LPVOID clientData, FPD_VTWordPlace place, FPD_VTWordPlace oldplace);

	void(*FPDPWLEditOnClear)(FS_LPVOID clientData, FPD_VTWordPlace place, FPD_VTWordPlace oldplace);

	void(*FPDPWLEditOnInsertText)(FS_LPVOID clientData, FPD_VTWordPlace place, FPD_VTWordPlace oldplace);

	void(*FPDPWLEditOnSetText)(FS_LPVOID clientData, FPD_VTWordPlace place, FPD_VTWordPlace oldplace);

	void(*FPDPWLEditOnBeginGroup)(FS_LPVOID clientData, FPD_CPWL_Edit edit);

	void(*FPDPWLEditOnEndGroup)(FS_LPVOID clientData, FPD_CPWL_Edit edit);

	void(*FPDPWLEditOnAddUndo)(FS_LPVOID clientData, FPD_CPWL_Edit edit);

}FPD_PWLEditNotifyCallbacksRec, *FPD_PWLEditNotifyCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FPD_PWLEditFillerNotifyCallbacks */
/**
 * @brief Variable text provider
 * @deprecated Internal use
 *
 */
typedef struct _fpd_pwlfiller_notify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_VariableTextProviderCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	void(*FPDPWLQueryWherePopup)(FS_LPVOID clientData, FS_LPVOID pPrivateData, FS_FLOAT fPopupMin, FS_FLOAT fPopupMax, FS_INT32* nRet, FS_FLOAT* fPopupRet);

	FS_INT32(*FPDPWLOnBeforeKeyStroke)(FS_LPVOID clientData, FS_BOOLEAN bEditOrList, void* pPrivateData, FS_INT32 nKeyCode, FS_WideString* strChange,
		FS_LPCWSTR strChangeEx,
		FS_INT32 nSelStart,
		FS_INT32 nSelEnd,
		FS_BOOLEAN bKeyDown,
		FS_BOOLEAN* bRC);

	FS_INT32(*FPDPWLOnAfterKeyStroke)(FS_LPVOID clientData, FS_BOOLEAN bEditOrList, FS_LPVOID pPrivateData);

	FS_INT32(*FPDPWLOnPopupPreOpen)(FS_LPVOID clientData, FS_LPVOID pPrivateData);

	FS_INT32(*FPDPWLOnPopupPostOpen)(FS_LPVOID clientData, FS_LPVOID pPrivateData);

}FPD_PWLFillerNotifyCallbacksRec, *FPD_PWLFillerNotifyCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FPD_PWLEditHandlerCallbacks */
/**
 * @brief 
 * @deprecated Internal use
 *
 */
typedef struct _fpd_pwledithandler_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_VariableTextProviderCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOLEAN(*FPDPWLEditOnRButtonUp)(FS_LPVOID clientData, const FS_FloatPoint point);
	void(*FPDPWLEditLoadCurrentWordProps)(FS_LPVOID clientData, FPD_VTWordProps* wp, FS_INT32 nCharset);
	void(*FPDPWLEditInsertWord)(FS_LPVOID clientData, FS_WORD wUnicode, FS_INT32 nCharset);
	FS_BOOLEAN(*FPDPWLEditAddExtendRightMenuItem)(FS_LPVOID clientData, FS_LPVOID hPopup);
	FS_BOOLEAN(*FPDPWLEditDoExtendRightMenuCommand)(FS_LPVOID clientData, FS_INT32 cmd);
	void(*FPDPWLEditIOnSetCaret)(FS_LPVOID clientData, FS_BOOL bVisible, const FS_FloatPoint ptHead,
		const FS_FloatPoint ptFoot, const FPD_VTWordPlace place);
}FPD_PWLEditHandlerCallbacksRec, *FPD_PWLEditHandlerCallbacks;
/* @CALLBACKGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_PWLEdit_Notify */
#ifndef FPD_PWLEDIT_NOTIFY
#define FPD_PWLEDIT_NOTIFY
typedef struct _t_FPD_PWLEdit_Notify* FPD_PWLEdit_Notify;
#endif
/* @OBJEND */

/* @OBJSTART FPD_PWLEdit_FillerNotify */
#ifndef FPD_PWLEDIT_FILLERNOTIFY
#define FPD_PWLEDIT_FILLERNOTIFY
typedef struct _t_FPD_PWLFillerNotify* FPD_PWLFillerNotify;
#endif
/* @OBJEND */

/* @OBJSTART FPD_VariableText_Iterator */
#ifndef FPD_VARIABLETEXT_ITERATOR
#define FPD_VARIABLETEXT_ITERATOR
typedef struct _t_FPD_VariableText_Iterator* FPD_VariableText_Iterator;
#endif
/* @OBJEND */

/* @OBJSTART FPD_VTLine */
#ifndef FPD_VTLINE
#define FPD_VTLINE
typedef struct _t_FPD_VTLine* FPD_VTLine;
#endif
/* @OBJEND */

/* @OBJSTART FPD_VTSection */
#ifndef FPD_VTSECTION
#define FPD_VTSECTION
typedef struct _t_FPD_VTSection* FPD_VTSection;
#endif
/* @OBJEND */

/* @OBJSTART FPD_TextListItem */
#ifndef FPD_TEXTLISTITEM
#define FPD_TEXTLISTITEM
typedef struct _t_FPD_TextListItem* FPD_TextListItem;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Bullet_WordIterator */
#ifndef FPD_BULLETWORDITERATOR
#define FPD_BULLETWORDITERATOR
typedef struct _t_FPD_Bullet_WordIterator* FPD_Bullet_WordIterator;
#endif
/* @OBJEND */

/* @OBJSTART FPD_VTBulletIterator */
#ifndef FR_VTBULLETITERATOR
#define FR_VTBULLETITERATOR
typedef struct _t_FPD_VTBulletIterator* FPD_VTBulletIterator;
#endif
/* @OBJEND */

/* @OBJSTART FPD_TextList */
#ifndef FPD_TEXTLIST
#define FPD_TEXTLIST
typedef struct _t_FPD_TextList* FPD_TextList;
#endif
/* @OBJEND */

/* @OBJSTART FPD_List */
#ifndef FPD_LIST
#define FPD_LIST
typedef struct _t_FPD_List* FPD_List;
#endif
/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
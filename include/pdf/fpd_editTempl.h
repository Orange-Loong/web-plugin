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
//----------_V13----------
//----------_V14----------
//----------_V15----------
//----------_V16----------
//*****************************
/* WordRange HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_VTWordRange, FPDWordRangeNew, ())

INTERFACE(void, FPDWordRangeDestroy, (FPD_VTWordRange wordRange))

INTERFACE(void, FPDWordRangeSetDefault, (FPD_VTWordRange wordRange))

INTERFACE(void, FPDWordRangeSet, (FPD_VTWordRange wordRange,  FPD_VTWordPlace begin,  FPD_VTWordPlace end))

INTERFACE(void, FPDWordRangeSetBeginPos, (FPD_VTWordRange wordRange,  FPD_VTWordPlace begin))

INTERFACE(void, FPDWordRangeSetEndPos, (FPD_VTWordRange wordRange,  FPD_VTWordPlace end))

INTERFACE(FS_BOOL, FPDWordRangeIsExist, (FPD_VTWordRange wordRange))

INTERFACE(FS_BOOL, FPDWordRangeEqual, (FPD_VTWordRange wordRange,  FPD_VTWordRange destWordRange))

INTERFACE(void, FPDWordRangeSwapWordPlace, (FPD_VTWordRange wordRange))

INTERFACE(FPD_VTWordPlace, FPDWordRangeGetBeginPos, (FPD_VTWordRange wordRange))

INTERFACE(FPD_VTWordPlace, FPDWordRangeGetEndPos, (FPD_VTWordRange wordRange))

NumOfSelector(FPDWordRange)
ENDENUM

//*****************************
/* WordProps HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_VTWordProps, FPDWordPropsNew, (FS_INT32	fontIndex,  FS_FLOAT fontSize,  FS_COLORREF wordColor,  FS_INT32 scriptType,  FS_INT32 wordStyle,  FS_FLOAT charSpace,  FS_FLOAT horzScale,  FS_FLOAT xOffset,  FS_FLOAT yOffset,  FS_COLORREF strokeColor,  FS_INT32 renderingMode,  FS_FLOAT lineWidth,  FS_FLOAT wordspace,  FS_DWORD dwCharCode,  short nAlphal))

INTERFACE(FPD_VTWordProps, FPDWordPropsNewII, (FPD_VTWordProps otherWordProps))

INTERFACE(void, FPDWordPropsDestroy, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetFontIndex, (FPD_VTWordProps wordProps,  FS_INT32 fontIndex))

INTERFACE(FS_INT32, FPDWordPropsGetFontIndex, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetFontSize, (FPD_VTWordProps wordProps,  FS_FLOAT fontSize))

INTERFACE(FS_FLOAT, FPDWordPropsGetFontSize, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetWordColor, (FPD_VTWordProps wordProps,  FS_COLORREF wordColor))

INTERFACE(FS_COLORREF, FPDWordPropsGetWordColor, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetStrokeColor, (FPD_VTWordProps wordProps,  FS_COLORREF dwStrokeColor))

INTERFACE(FS_COLORREF, FPDWordPropsGetStrokeColor, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetScriptType, (FPD_VTWordProps wordProps,  FS_INT32 nScriptType))

INTERFACE(FS_INT32, FPDWordPropsGetScriptType, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetWordStyle, (FPD_VTWordProps wordProps,  FS_INT32 nWordStyle))

INTERFACE(FS_INT32, FPDWordPropsGetWordStyle, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetCharSpace, (FPD_VTWordProps wordProps,  FS_FLOAT fCharSpace))

INTERFACE(FS_FLOAT, FPDWordPropsGetCharSpace, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetHorzScale, (FPD_VTWordProps wordProps,  FS_FLOAT fHorzScale))

INTERFACE(FS_FLOAT, FPDWordPropsGetHorzScale, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetXOffset, (FPD_VTWordProps wordProps,  FS_FLOAT fXOffset))

INTERFACE(FS_FLOAT, FPDWordPropsGetXOffset, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetYOffset, (FPD_VTWordProps wordProps,  FS_FLOAT fYOffset))

INTERFACE(FS_FLOAT, FPDWordPropsGetYOffset, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetRenderingMode, (FPD_VTWordProps wordProps,  FS_INT32 nRenderingMode))

INTERFACE(FS_INT32, FPDWordPropsGetRenderingMode, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetClientData, (FPD_VTWordProps wordProps,  void* pClientData))

INTERFACE(void*, FPDWordPropsGetClientData, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetLineWidth, (FPD_VTWordProps wordProps,  FS_FLOAT fLineWidth))

INTERFACE(FS_FLOAT, FPDWordPropsGetLineWidth, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetWordSpace, (FPD_VTWordProps wordProps,  FS_FLOAT fWordSpace))

INTERFACE(FS_FLOAT, FPDWordPropsGetWordSpace, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetCharCode, (FPD_VTWordProps wordProps,  FS_DWORD dwCharCode))

INTERFACE(FS_DWORD, FPDWordPropsGetCharCode, (FPD_VTWordProps wordProps))

INTERFACE(void, FPDWordPropsSetAlpha, (FPD_VTWordProps wordProps,  short nAlpha))

INTERFACE(short, FPDWordPropsGetAlpha, (FPD_VTWordProps wordProps))

NumOfSelector(FPDWordProps)
ENDENUM

//*****************************
/* Edit HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_Edit, FPDEditNew, ())

INTERFACE(void, FPDEditDel, (FPD_Edit edit))

INTERFACE(void, FPDEditSetFontMap, (FPD_Edit edit,  FPD_Edit_FontMap fontMap,  FS_INT32 nDefaultFontIndex))

INTERFACE(void, FPDEditSetVTProvider, (FPD_Edit edit,  FPD_VariableText_Provider provider))

INTERFACE(void*, FPDEditSetNotify, (FPD_Edit edit,  FPD_EditNotifyCallbacks callbacks))

INTERFACE(void*, FPDEditSetOprNotify, (FPD_Edit edit,  FPD_EditOprNotifyCallbacks callbacks))

INTERFACE(FPD_Edit_Iterator, FPDEditGetIterator, (FPD_Edit edit))

INTERFACE(FPD_VariableText, FPDEditGetVariableText, (FPD_Edit edit))

INTERFACE(FPD_Edit_FontMap, FPDEditGetFontMap, (FPD_Edit edit))

INTERFACE(void, FPDEditInitialize, (FPD_Edit edit))

INTERFACE(void, FPDEditSetPlateRect, (FPD_Edit edit,  FS_FloatRect rect,  FS_BOOL bPaint,  FS_BOOL bVerticalWriting))

INTERFACE(void, FPDEditSetScrollPos, (FPD_Edit edit,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(FS_BOOL, FPDEditIsVerticalWriting, (FPD_Edit edit))

INTERFACE(void, FPDEditSetAlignmentH, (FPD_Edit edit,  FS_INT32 nFormat,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetAlignmentV, (FPD_Edit edit,  FS_INT32 nFormat,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetPasswordChar, (FPD_Edit edit,  FS_WORD wSubWord,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetLimitChar, (FPD_Edit edit,  FS_INT32 nLimitChar,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetCharArray, (FPD_Edit edit,  FS_INT32 nCharArray,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetCharSpace, (FPD_Edit edit,  FS_FLOAT fCharSpace,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetWordSpace, (FPD_Edit edit,  FS_FLOAT fWordSpace,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetHorzScale, (FPD_Edit edit,  FS_FLOAT fHorzScale,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetLineLeading, (FPD_Edit edit,  FS_FLOAT fLineLeading,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetMultiLine, (FPD_Edit edit,  FS_BOOL bMultiLine,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetAutoReturn, (FPD_Edit edit,  FS_BOOL bAuto,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetAutoFontSize, (FPD_Edit edit,  FS_BOOL bAuto,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetAutoScroll, (FPD_Edit edit,  FS_BOOL bAuto,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetFontSize, (FPD_Edit edit,  FS_FLOAT fFontSize,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetTextOverflow, (FPD_Edit edit,  FS_BOOL bAllowed,  FS_BOOL bPaint))

INTERFACE(void, FPDEditSetDirectionRTL, (FPD_Edit edit,  FS_BOOL bRTL,  FS_BOOL bApplyAllSection,  FS_BOOL bPaint))

INTERFACE(FS_BOOL, FPDEditIsRichText, (FPD_Edit edit))

INTERFACE(void, FPDEditSetRichText, (FPD_Edit edit,  FS_BOOL bRichText,  FS_BOOL bPaint))

INTERFACE(FS_BOOL, FPDEditSetRichTextFont, (FPD_Edit edit,  FS_LPCSTR lpsFontName,  FS_INT32 nFontIndex))

INTERFACE(FS_BOOL, FPDEditSetRichTextIsBold, (FPD_Edit edit,  FS_BOOL bBold,  FS_BOOL bNeedToReaderingMode))

INTERFACE(FS_BOOL, FPDEditSetRichTextIsItalic, (FPD_Edit edit,  FS_BOOL bItalic))

INTERFACE(FS_BOOL, FPDEditSetRichFontSize, (FPD_Edit edit,  FS_FLOAT fFontSize))

INTERFACE(FS_BOOL, FPDEditSetRichTextColor, (FPD_Edit edit,  FS_COLORREF dwColor))

INTERFACE(FS_BOOL, FPDEditSetRichTextStrokeColor, (FPD_Edit edit,  FS_COLORREF dwColor))

INTERFACE(FS_BOOL, FPDEditSetRichRenderingMode, (FPD_Edit edit,  FS_INT32 nRenderingMode))

INTERFACE(FS_BOOL, FPDEditSetRichTextScript, (FPD_Edit edit,  FS_INT32 nScriptType))

INTERFACE(FS_BOOL, FPDEditSetRichTextUnderline, (FPD_Edit edit,  FS_BOOL bUnderline))

INTERFACE(FS_BOOL, FPDEditSetRichTextCrossout, (FPD_Edit edit,  FS_BOOL bCrossout))

INTERFACE(FS_BOOL, FPDEditSetRichTextCharSpace, (FPD_Edit edit,  FS_FLOAT fCharSpace))

INTERFACE(FS_BOOL, FPDEditSetRichTextWordSpace, (FPD_Edit edit,  FS_FLOAT fWordSpace))

INTERFACE(FS_BOOL, FPDEditSetRichTextHorzScale, (FPD_Edit edit,  FS_FLOAT fHorzScale))

INTERFACE(FS_BOOL, FPDEditSetRichTextLineLeading, (FPD_Edit edit,  FS_FLOAT fLineLeading))

INTERFACE(FS_BOOL, FPDEditSetRichTextLineIndent, (FPD_Edit edit,  FS_FLOAT fLineIndent))

INTERFACE(FS_BOOL, FPDEditSetRichTextAlignment, (FPD_Edit edit,  FS_INT32 nAlignment))

INTERFACE(FS_BOOL, FPDEditSetRichTextSoftReturn, (FPD_Edit edit,  FS_BOOL bEnable))

INTERFACE(void, FPDEditSetSel, (FPD_Edit edit,  FS_INT32 nStartChar,  FS_INT32 nEndChar))

INTERFACE(void, FPDEditGetSel, (FPD_Edit edit,  FS_INT32* nStartChar,  FS_INT32* nEndChar))

INTERFACE(void, FPDEditSelectAll, (FPD_Edit edit))

INTERFACE(void, FPDEditSelectNone, (FPD_Edit edit))

INTERFACE(FS_INT32, FPDEditGetCaret, (FPD_Edit edit))

INTERFACE(void, FPDEditGetCaretWordPlace, (FPD_Edit edit,  FPD_VTWordPlace* outWordPlace))

INTERFACE(void, FPDEditGetSelText, (FPD_Edit edit,  FS_WideString* outText))

INTERFACE(void, FPDEditGetText, (FPD_Edit edit,  FS_WideString* outText))

INTERFACE(void, FPDEditGetRichTextXML, (FPD_Edit edit,  FS_LPCWSTR ds,  FS_BOOL bSaveLineFeed,  FS_WideString* outXML))

INTERFACE(FS_BOOL, FPDEditIsSelected, (FPD_Edit edit))

INTERFACE(void, FPDEditGetScrollPos, (FPD_Edit edit,  FS_FLOAT* x,  FS_FLOAT* y))

INTERFACE(FS_FloatRect, FPDEditGetPlateRect, (FPD_Edit edit))

INTERFACE(FS_FloatRect, FPDEditGetContentRect, (FPD_Edit edit))

INTERFACE(void, FPDEditGetVisibleWordRange, (FPD_Edit edit,  FPD_VTWordRange* outWordRange))

INTERFACE(void, FPDEditGetWholeWordRange, (FPD_Edit edit,  FPD_VTWordRange* outWordRange))

INTERFACE(void, FPDEditGetSelectWordRange, (FPD_Edit edit,  FPD_VTWordRange* outWordRange))

INTERFACE(void, FPDEditOnMouseDown, (FPD_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FPDEditOnMouseMove, (FPD_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FPDEditOnVK_UP, (FPD_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FPDEditOnVK_DOWN, (FPD_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FPDEditOnVK_LEFT, (FPD_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FPDEditOnVK_RIGHT, (FPD_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FPDEditOnVK_HOME, (FPD_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FPDEditOnVK_END, (FPD_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FPDEditSetText, (FPD_Edit edit,  FS_LPCWSTR text,  FS_INT32 charset,  FPD_VTSecProps secProps,  FPD_VTWordProps pWordProps))

INTERFACE(void, FPDEditSetRichTextByXML, (FPD_Edit edit,  FS_LPCWSTR xml,  FS_LPCWSTR ds,  FS_INT32 charset))

INTERFACE(FS_BOOL, FPDEditInsertWord, (FPD_Edit edit,  FS_WORD word,  FS_INT32 charset,  FPD_VTWordProps pWordProps,  FS_BOOL bPaint,  FS_BOOL bNeedTransform))

INTERFACE(FS_BOOL, FPDEditInsertReturn, (FPD_Edit edit,  FPD_VTSecProps secProps,  FPD_VTWordProps pWordProps,  FS_BOOL bPaint))

INTERFACE(FS_BOOL, FPDEditInsertText, (FPD_Edit edit,  FS_LPCWSTR text,  FS_INT32 charset,  FPD_VTSecProps secProps,  FPD_VTWordProps pWordProps,  FS_BOOL bPaint,  FS_BOOL bNeedTransform))

INTERFACE(FS_BOOL, FPDEditBackspace, (FPD_Edit edit))

INTERFACE(FS_BOOL, FPDEditDelete, (FPD_Edit edit,  FS_BOOL bCtrl))

INTERFACE(FS_BOOL, FPDEditClear, (FPD_Edit edit))

INTERFACE(FS_BOOL, FPDEditRedo, (FPD_Edit edit))

INTERFACE(FS_BOOL, FPDEditUndo, (FPD_Edit edit))

INTERFACE(void, FPDEditSetCaret, (FPD_Edit edit,  FS_INT32 nPos))

INTERFACE(void, FPDEditPaint, (FPD_Edit edit))

INTERFACE(void, FPDEditEnableRefresh, (FPD_Edit edit,  FS_BOOL bRefresh))

INTERFACE(void, FPDEditRefreshWordRange, (FPD_Edit edit,  FPD_VTWordRange wordRange))

INTERFACE(void, FPDEditEnableUndo, (FPD_Edit edit,  FS_BOOL bUndo))

INTERFACE(void, FPDEditEnableNotify, (FPD_Edit edit,  FS_BOOL bNotify))

INTERFACE(void, FPDEditEnableOprNotify, (FPD_Edit edit,  FS_BOOL bNotify))

INTERFACE(FS_INT32, FPDEditWordPlaceToWordIndex, (FPD_Edit edit,  FPD_VTWordPlace wordPlace))

INTERFACE(void, FPDEditWordIndexToWordPlace, (FPD_Edit edit,  FS_INT32 index,  FPD_VTWordPlace* outWordPlace))

INTERFACE(void, FPDEditGetLineBeginPlace, (FPD_Edit edit,  FPD_VTWordPlace wordPlace,  FPD_VTWordPlace* outWordPlace))

INTERFACE(void, FPDEditGetLineEndPlace, (FPD_Edit edit,  FPD_VTWordPlace wordPlace,  FPD_VTWordPlace* outWordPlace))

INTERFACE(void, FPDEditGetSectionBeginPlace, (FPD_Edit edit,  FPD_VTWordPlace wordPlace,  FPD_VTWordPlace* outWordPlace))

INTERFACE(void, FPDEditGetSectionEndPlace, (FPD_Edit edit,  FPD_VTWordPlace wordPlace,  FPD_VTWordPlace* outWordPlace))

INTERFACE(void, FPDEditSearchWordPlace, (FPD_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordPlace* outWordPlace))

INTERFACE(FS_FLOAT, FPDEditGetFontSize, (FPD_Edit edit))

INTERFACE(FS_WORD, FPDEditGetPasswordChar, (FPD_Edit edit))

INTERFACE(FS_INT32, FPDEditGetCharArray, (FPD_Edit edit))

INTERFACE(FS_FLOAT, FPDEditGetHorzScale, (FPD_Edit edit))

INTERFACE(FS_FLOAT, FPDEditGetCharSpace, (FPD_Edit edit))

INTERFACE(void, FPDEditGetRangeText, (FPD_Edit edit,  FPD_VTWordRange wordRange,  FS_WideString* outText))

INTERFACE(FS_BOOL, FPDEditIsTextFull, (FPD_Edit edit))

INTERFACE(FS_BOOL, FPDEditCanUndo, (FPD_Edit edit))

INTERFACE(FS_BOOL, FPDEditCanRedo, (FPD_Edit edit))

INTERFACE(void, FPDEditResetUndo, (FPD_Edit edit))

INTERFACE(FS_BOOL, FPDEditIsModified, (FPD_Edit edit))

INTERFACE(FS_INT32, FPDEditGetTotalWords, (FPD_Edit edit))

INTERFACE(void*, FPDEditAddUndoItem, (FPD_Edit edit,  FPD_EditUndoItemCallbacks callbacks))

INTERFACE(void, FPDEditBeginGroupUndo, (FPD_Edit edit,  FS_LPCWSTR lpwsTitle))

INTERFACE(void, FPDEditEndGroupUndo, (FPD_Edit edit))

INTERFACE(void, FPDEditSaveLineOffset, (FPD_Edit edit))

INTERFACE(void, FPDEditGetEditAppearanceStream, (FPD_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordRange wordRange,  FS_BOOL bContinuous,  FS_WORD SubWord,  FPD_EDITFONTArray* outFontDataArray,  FS_ByteString* outStream))

INTERFACE(void, FPDEditGetRichEditAppearanceStream, (FPD_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordRange wordRange,  FS_BOOL bContinuous,  FS_WORD SubWord,  FPD_EDITFONTArray* outFontDataArray,  FS_ByteString* outStream,  FS_ByteString pPathStream))

INTERFACE(void, FPDEditGetSelectAppearanceStream, (FPD_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordRange wordRange,  FS_ByteString* outStream))

INTERFACE(void, FPDEditDrawEdit, (FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device,  FPD_Edit edit,  FS_ARGB crTextFill,  FS_COLORREF crTextStroke,  FS_FloatRect rcClip,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordRange wordRange))

INTERFACE(void, FPDEditDrawUnderline, (FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device,  FPD_Edit edit,  FS_COLORREF color,  FS_FloatRect rcClip,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordRange wordRange))

INTERFACE(void, FPDEditDrawRichEdit, (FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device,  FPD_Edit edit,  FS_FloatRect rcClip,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordRange wordRange,  FS_AffineMatrix text2Uer))

INTERFACE(void, FPDEditGeneratePageObjects, (void* pPageObjects,  FPD_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordRange wordRange,  FS_COLORREF crText,  FS_PtrArray* outTextObjectArray))

INTERFACE(void, FPDEditGenerateRichPageObjects, (void* pPageObjects,  FPD_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordRange wordRange,  FS_PtrArray* outTextObjectArray,  FS_POSITION* outPos,  FS_PtrArray* outPathObjectArray))

INTERFACE(void, FPDEditGenerateUnderlineObjects, (void* pPageObjects,  FPD_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordRange wordRange,  FS_COLORREF color))

INTERFACE(void, FPDEditGetRichTextPlainText, (FS_LPCWSTR xml,  FS_WideString* outText))

INTERFACE(void, FPDEditSetText2, (FPD_Edit edit,  FS_LPCWSTR text,  FS_INT32 charset,  FPD_VTSecProps secProps,  FPD_VTWordProps pWordProps,  FS_BOOLEAN bNeedEmbed))

INTERFACE(FS_BOOL, FPDEditIsPunctuation, (FS_DWORD word))

INTERFACE(void, FPDEditEnableArtificialBold, (FR_Edit edit,  FS_BOOLEAN bNeedToReaderingMode))

INTERFACE(void, FPDEditSetFillMode, (FPD_Edit edit,  FPD_FillMode_Value eVlaue))

INTERFACE(void, FPDEditBeginOperBullet, (FPD_Edit edit,  FS_INT32 ntype))

INTERFACE(FS_INT32, FPDEditEndOperBullet, (FPD_Edit edit,  FS_BOOLEAN bPrint))

INTERFACE(FPD_TextListItem, FPDEditGetBullet, (FPD_Edit edit,  FS_INT32 nSection))

INTERFACE(FPD_Bullet_WordIterator, FPDEditGetBulletWordIterator, (FPD_Edit edit,  FPD_TextListItem pBullet))

INTERFACE(void, FPDEditSetLineLeadingRatio, (FPD_Edit edit,  FS_FLOAT fLineLeadingratio,  FS_BOOLEAN bPaint))

INTERFACE(void, FPDEditGetRichTextXML2, (FPD_Edit edit,  FS_LPCWSTR ds,  FS_BOOL bSaveLineFeed,  FS_BOOLEAN bRichForm,  FS_WideString* outXML))

INTERFACE(FS_BOOLEAN, FPDEditDeleteTextList, (FPD_Edit edit))

INTERFACE(FS_BOOLEAN, FPDEditModifyNumberedList, (FPD_Edit edit,  FPDEDIT_ListStyleDescriptor numberListStyle))

INTERFACE(FS_BOOLEAN, FPDEditModifyBulletedList, (FPD_Edit edit,  FS_WCHAR bullet))

NumOfSelector(FPDEdit)
ENDENUM

//*****************************
/* EditFontMap HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOL, FPDEditFontMapGetFontStyle, (FPD_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_DWORD* dwFontStyle,  FS_INT32* nCharset))

INTERFACE(FS_BOOL, FPDEditFontMapIsExternalEmbedFont, (FPD_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(FS_BOOL, FPDEditFontMapIsEmbedded, (FPD_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(FS_INT32, FPDEditFontMapGetFontIndexByUnicode3, (FPD_Edit_FontMap editFontMap,  FS_WCHAR wUnicode,  FS_LPCWSTR lpsDefaultFontName,  FS_DWORD dwFontStyle,  FS_INT32 nCharSet,  FPDFMTribool bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FS_INT32, FPDEditFontMapGetFontIndex3, (FPD_Edit_FontMap editFontMap,  FS_LPCWSTR lpsFontName,  FS_INT32 nCharset,  FS_DWORD dwFontStyle,  FS_BOOL bAdd,  FPDFMTribool bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FS_INT32, FPDEditFontMapAddFXFont2, (FPD_Edit_FontMap editFontMap,  void* pFXFont,  FS_LPCWSTR lpsFontName,  FS_INT32 nCharset))

INTERFACE(FS_INT32, FPDEditFontMapAddPDFFont2, (FPD_Edit_FontMap editFontMap,  FPD_Font fpdFont,  FS_LPCWSTR lpsFontName,  FS_INT32 nCharset))

INTERFACE(FS_INT32, FPDEditFontMapLoadAllFontByDict, (FPD_Edit_FontMap editFontMap,  FPD_Object acroFormDict,  FPD_Object annotDict,  FS_LPCSTR lpsApType,  FS_BOOLEAN* pIsDAFont))

INTERFACE(FPD_Edit_FontMap, FPDEditFontMapCreate, (FPD_SystemHandler sysHandler,  FPD_Document pDoc))

INTERFACE(void, FPDEditFontMapDestroy, (FPD_Edit_FontMap editFontMap))

INTERFACE(void, FPDEditFontMapGetFontName, (FPD_Edit_FontMap editFontMap,  FS_UINT nFontIndex,  FS_WideString* fontName))

INTERFACE(FPD_FXFont, FPDEditFontMapGetFXFont, (FPD_Edit_FontMap editFontMap,  FS_UINT nFontIndex))

INTERFACE(FS_INT32, FPDEditFontMapGetCharset, (FPD_Edit_FontMap editFontMap,  FS_UINT nFontIndex))

INTERFACE(void, FPDEditFontMapInitialize, (FPD_Edit_FontMap editFontMap,  FS_LPCSTR fontname))

INTERFACE(FPD_Font, FPDEditFontMapGetPDFFont, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_DWordArray unicodeArray,  FS_BOOL bEmbedFont))

INTERFACE(void, FPDEditFontMapGetRealNameFromTagName, (FR_Edit_FontMap editFontMap,  FS_LPCSTR bsTagName,  FS_ByteString* outTagName))

INTERFACE(void, FPDEditFontMapGetSysDefaultFontName, (FR_Edit_FontMap editFontMap,  FS_WideString* fontname))

NumOfSelector(FPDEditFontMap)
ENDENUM

//*****************************
/* VTWord HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_VTWord, FPDVTWordNew, ())

INTERFACE(void, FPDVTWordDestroy, (FPD_VTWord word))

INTERFACE(void, FPDVTWordSetWord, (FPD_VTWord VTWord,  FS_WORD word))

INTERFACE(FS_WORD, FPDVTWordGetWord, (FPD_VTWord word))

INTERFACE(void, FPDVTWordSetWordDisplay, (FPD_VTWord word,  FS_WORD WordDisplay))

INTERFACE(FS_WORD, FPDVTWordGetWordDisplay, (FPD_VTWord word))

INTERFACE(void, FPDVTWordSetBidiOrder, (FPD_VTWord word,  short nBidiOrder))

INTERFACE(short, FPDVTWordGetBidiOrder, (FPD_VTWord word))

INTERFACE(void, FPDVTWordSetCharset, (FPD_VTWord word,  FS_INT32 nCharset))

INTERFACE(FS_INT32, FPDVTWordGetCharset, (FPD_VTWord word))

INTERFACE(void, FPDVTWordSetWordPlace, (FPD_VTWord word,  FPD_VTWordPlace WordPlace))

INTERFACE(FPD_VTWordPlace, FPDVTWordGetWordPlace, (FPD_VTWord word))

INTERFACE(void, FPDVTWordSetWordPoint, (FPD_VTWord word,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(void, FPDVTWordGetWordPoint, (FPD_VTWord word,  FS_FLOAT* x,  FS_FLOAT* y))

INTERFACE(void, FPDVTWordSetAscent, (FPD_VTWord word,  FS_FLOAT fAscent))

INTERFACE(FS_FLOAT, FPDVTWordGetAscent, (FPD_VTWord word))

INTERFACE(void, FPDVTWordSetDescent, (FPD_VTWord word,  FS_FLOAT fDescent))

INTERFACE(FS_FLOAT, FPDVTWordGetDescent, (FPD_VTWord word))

INTERFACE(void, FPDVTWordSetWidth, (FPD_VTWord word,  FS_FLOAT fWidth))

INTERFACE(FS_FLOAT, FPDVTWordGetWidth, (FPD_VTWord word))

INTERFACE(void, FPDVTWordSetFontIndex, (FPD_VTWord word,  FS_INT32 nFontIndex))

INTERFACE(FS_INT32, FPDVTWordGetFontIndex, (FPD_VTWord word))

INTERFACE(void, FPDVTWordSetFontSize, (FPD_VTWord word,  FS_FLOAT fFontSize))

INTERFACE(FS_FLOAT, FPDVTWordGetFontSize, (FPD_VTWord word))

INTERFACE(void, FPDVTWordSetWordProps, (FPD_VTWord word,  FPD_VTWordProps wordProps))

INTERFACE(FPD_VTWordProps, FPDVTWordGetWordProps, (FPD_VTWord word))

NumOfSelector(FPDVTWord)
ENDENUM

//----------_V17----------
//*****************************
/* PWLCREATEPARAM HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_PWLCREATEPARAM, FPDPWLCREATEPARAMPWLWndCreationParamNew, ())

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetFontMap, (FPD_PWLCREATEPARAM pCreationParam,  FPD_Edit_FontMap fontMap))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetFontIndex, (FPD_PWLCREATEPARAM pCreationParam,  FS_INT32 nFontIndex))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetFlag, (FPD_PWLCREATEPARAM pCreationParam,  FS_DWORD dwFlags))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetFontSize, (FPD_PWLCREATEPARAM pCreationParam,  FS_FLOAT fFontSize))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetTextColor, (FPD_PWLCREATEPARAM pCreationParam,  FS_INT32 r,  FS_INT32 g,  FS_INT32 b))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetTextColorII, (FPD_PWLCREATEPARAM pCreationParam,  FPD_ColorF color))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetRect, (FPD_PWLCREATEPARAM pCreationParam,  FS_FloatRect rect))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamDestroy, (FPD_PWLCREATEPARAM pCreationParam))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetSystemHandler, (FPD_PWLCREATEPARAM pCreationParam,  FS_LPVOID handler))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetProvider, (FPD_PWLCREATEPARAM pCreationParam,  FPD_CPWL_Provider handler))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetFocusHandler, (FPD_PWLCREATEPARAM pCreationParam,  FPD_CPWL_FocusHandler handler))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetBackgroundColor, (FPD_PWLCREATEPARAM pCreationParam,  FPD_ColorF color))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetAttachedWnd, (FPD_PWLCREATEPARAM pCreationParam,  FS_LPVOID wnd))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetSpellCheck, (FPD_PWLCREATEPARAM pCreationParam,  FPD_SpellCheck spellcheck))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetBorderStyle, (FPD_PWLCREATEPARAM pCreationParam,  FS_INT32 borderStyle))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetBorderWidth, (FPD_PWLCREATEPARAM pCreationParam,  FS_INT32 borderWidth))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetBorderColor, (FPD_PWLCREATEPARAM pCreationParam,  FPD_ColorF color))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetTextStrokeColor, (FPD_PWLCREATEPARAM pCreationParam,  FPD_ColorF color))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetTransparency, (FPD_PWLCREATEPARAM pCreationParam,  FS_INT32 transparency))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetUseFXFontDeAscent, (FPD_PWLCREATEPARAM pCreationParam,  FS_BOOL bUse))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetDash, (FPD_PWLCREATEPARAM pCreationParam,  FPDCPWL_Dash dash))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetAttachedData, (FPD_PWLCREATEPARAM pCreationParam,  FS_LPVOID data))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetParentWnd, (FPD_PWLCREATEPARAM pCreationParam,  FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetCursorType, (FPD_PWLCREATEPARAM pCreationParam,  FS_INT32 type))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetMtChild, (FPD_PWLCREATEPARAM pCreationParam,  FS_AffineMatrix mt))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetShowFontSizeDPI, (FPD_PWLCREATEPARAM pCreationParam,  FS_FLOAT dpi))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetNeedEmbed, (FPD_PWLCREATEPARAM pCreationParam,  FS_BOOL bEmbed))

INTERFACE(void, FPDPWLCREATEPARAMPWLWndCreationParamSetListBoxFontSize, (FPD_PWLCREATEPARAM pCreationParam,  FS_FLOAT fontsize))

INTERFACE(FS_DWORD, FPDPWLCREATEPARAMGetFlags, (FPD_PWLCREATEPARAM pCreationParam))

INTERFACE(FS_FloatRect, FPDPWLCREATEPARAMGetRect, (FPD_PWLCREATEPARAM pCreationParam))

NumOfSelector(FPDPWLCREATEPARAM)
ENDENUM

//*****************************
/* CPWLEdit HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_Edit, FPDCPWLEditNew, (FPD_PWLCREATEPARAM pCreationParam))

INTERFACE(void, FPDCPWLEditSetTextColor, (FPD_CPWL_Edit pEdit,  FS_INT32 r,  FS_INT32 g,  FS_INT32 b))

INTERFACE(void, FPDCPWLEditSetTextColorII, (FPD_CPWL_Edit pEdit,  FPD_ColorF color))

INTERFACE(void, FPDCPWLEditSetText, (FPD_CPWL_Edit pEdit,  FS_LPCWSTR csText))

INTERFACE(void, FPDCPWLEditGetContentRect, (FPD_CPWL_Edit pEdit,  FS_FloatRect* pRect))

INTERFACE(void, FPDCPWLEditGeneratePageObjects, (FPD_CPWL_Edit pEdit,  void* pPageObjects,  FS_FLOAT xx,  FS_FLOAT yy,  FS_PtrArray* outObjArray))

INTERFACE(void, FPDCPWLEditGeneratePageObjectsII, (FPD_CPWL_Edit pEdit,  void* pPageObjects,  FS_FLOAT xx,  FS_FLOAT yy))

INTERFACE(void, FPDCPWLEditDestroy, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditEnableRefresh, (FPD_CPWL_Edit pEdit,  FS_BOOLEAN bRefresh))

INTERFACE(void, FPDCPWLEditSetAlignFormatH, (FPD_CPWL_Edit pEdit,  FPDPWL_EDIT_ALIGNFORMAT_H nFormat,  FS_BOOLEAN bPaint))

INTERFACE(void, FPDCPWLEditSetAlignFormatV, (FPD_CPWL_Edit pEdit,  FPDPWL_EDIT_ALIGNFORMAT_V nFormat,  FS_BOOLEAN bPaint))

INTERFACE(void, FPDCPWLEditSetHorzScale, (FPD_CPWL_Edit pEdit,  FS_FLOAT fHorzScale,  FS_BOOLEAN bPaint))

INTERFACE(void, FPDCPWLEditSetCharSpace, (FPD_CPWL_Edit pEdit,  FS_FLOAT fCharSpace,  FS_BOOLEAN bPaint))

INTERFACE(void, FPDCPWLEditSetLineLeading, (FPD_CPWL_Edit pEdit,  FS_FLOAT fLineLeading,  FS_BOOLEAN bPaint))

INTERFACE(FPD_Edit, FPDCPWLEditGetEdit, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditGetTextAppearanceStream, (FPD_CPWL_Edit pEdit,  FS_FloatPoint ptOffset,  FPD_EDITFONTArray* outFontDataArray,  FS_BOOLEAN bEmbedded,  FS_ByteString* pFontReference,  FS_ByteString* outStream))

INTERFACE(FPD_Edit, FPDCPWLEditGetFXEdit, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditChangeApplyAllSection, (FPD_CPWL_Edit pEdit,  FS_BOOLEAN bAppleyAllSection))

INTERFACE(void, FPDCPWLEditSetRichText, (FPD_CPWL_Edit pEdit,  FS_LPCWSTR xml,  FS_LPCWSTR ds,  FS_BOOLEAN bAutoSetAgin,  FS_BOOLEAN bSimulateBold))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLEditGetCPWLWnd, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditRedo, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditUndo, (FPD_CPWL_Edit pEdit))

INTERFACE(FS_BOOLEAN, FPDCPWLEditCanSelectAll, (FPD_CPWL_Edit pEdit))

INTERFACE(FS_BOOLEAN, FPDCPWLEditCanClear, (FPD_CPWL_Edit pEdit))

INTERFACE(FS_BOOLEAN, FPDCPWLEditCanCopy, (FPD_CPWL_Edit pEdit))

INTERFACE(FS_BOOLEAN, FPDCPWLEditCanCut, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditCopyText, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditPasteText, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditCutText, (FPD_CPWL_Edit pEdit))

INTERFACE(FS_BOOLEAN, FPDCPWLEditCanPaste, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditGetTextWithBullet, (FPD_CPWL_Edit pEdit,  FS_WideString* outText))

INTERFACE(FPD_PWLEdit_Notify, FPDCPWLEditCreateNotify, (FPD_PWLEditNotifyCallbacks callbacks))

INTERFACE(void, FPDCPWLEditDeleteNotify, (FPD_PWLEdit_Notify notify))

INTERFACE(void, FPDCPWLEditSetEditNotify, (FPD_CPWL_Edit pEdit,  FPD_PWLEdit_Notify notify))

INTERFACE(void, FPDCPWLEditSetFillerNotify, (FPD_CPWL_Edit pEdit,  FPD_PWLFillerNotify notify))

INTERFACE(void, FPDCPWLEditReplaceSel, (FPD_CPWL_Edit pEdit,  FS_LPCWSTR csText))

INTERFACE(FPD_CPWL_Edit, FPDCPWLEditNew2, (FPD_PWLEditHandlerCallbacks callbacks))

INTERFACE(FPD_CPWL_Edit, FPDCPWLEditGetFromWnd, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_BOOLEAN, FPDCPWLEditSetRichTextIsBold, (FPD_CPWL_Edit pEdit,  FS_BOOLEAN bBold))

INTERFACE(FS_BOOLEAN, FPDCPWLEditSetRichTextIsItalic, (FPD_CPWL_Edit pEdit,  FS_BOOLEAN bItalic))

INTERFACE(FS_BOOLEAN, FPDCPWLEditSetRichTextUnderline, (FPD_CPWL_Edit pEdit,  FS_BOOLEAN bUnderline))

INTERFACE(FS_BOOLEAN, FPDCPWLEditSetRichTextScript, (FPD_CPWL_Edit pEdit,  FS_INT32 nScriptType))

INTERFACE(FPD_CPWL_EditCtrl, FPDCPWLEditCastToEditCtrl, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditIOnSetCaret, (FPD_CPWL_Edit pEdit,  FS_BOOLEAN bVisible,  FS_FloatPoint ptHead,  FS_FloatPoint ptFoot,  FPD_VTWordPlace* place,  FS_BOOLEAN bBaseFun))

INTERFACE(void, FPDCPWLEditSetCharSet, (FPD_CPWL_Edit pEdit,  FS_BYTE nCharSet))

INTERFACE(FS_INT32, FPDCPWLEditGetCharSet, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditSetCodePage, (FPD_CPWL_Edit pEdit,  FS_INT32 nCodePage))

INTERFACE(void, FPDCPWLEditSetInputText, (FPD_CPWL_Edit pEdit,  FS_LPCWSTR swText))

INTERFACE(FS_AffineMatrix, FPDCPWLEditGetWindowMatrix, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditGetCaretPos, (FPD_CPWL_Edit pEdit,  FS_INT32* x,  FS_INT32* y))

INTERFACE(FS_FLOAT, FPDCPWLEditGetCaretFontSize, (FPD_CPWL_Edit pEdit))

INTERFACE(FS_BOOLEAN, FPDCPWLEditIsTextFull, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditSetFontSize, (FPD_CPWL_Edit pEdit,  FS_FLOAT fFontSize))

INTERFACE(FS_FLOAT, FPDCPWLEditGetFontSize, (FPD_CPWL_Edit pEdit))

INTERFACE(FS_BOOLEAN, FPDCPWLEditOnChar, (FPD_CPWL_Edit pEdit,  FS_DWORD nChar))

INTERFACE(FS_BOOLEAN, FPDCPWLEditSetRichTextColor, (FPD_CPWL_Edit pEdit,  FS_COLORREF dwColor))

INTERFACE(void, FPDCPWLEditSetCaretColor, (FPD_CPWL_Edit pEdit,  const FS_ARGB color))

INTERFACE(void, FPDCPWLEditGetText, (FPD_CPWL_Edit pEdit,  FS_WideString* wsText))

INTERFACE(void, FPDCPWLEditGetRichTextXML, (FPD_CPWL_Edit pEdit,  FS_LPCWSTR ds,  FS_BOOLEAN bSaveLineFeed,  FS_BOOLEAN bRichForm,  FS_WideString* outText))

INTERFACE(FS_BOOLEAN, FPDCPWLEditCanUndo, (FPD_CPWL_Edit pEdit))

INTERFACE(FS_BOOLEAN, FPDCPWLEditCanRedo, (FPD_CPWL_Edit pEdit))

INTERFACE(void, FPDCPWLEditSelectAll, (FPD_CPWL_Edit pEdit))

INTERFACE(FS_BOOLEAN, FPDCPWLEditSetRichTextAlignment, (FPD_CPWL_Edit pEdit,  FS_INT32 nAlignment))

INTERFACE(FS_BOOLEAN, FPDCPWLEditOnLButtonDown, (FPD_CPWL_Edit pEdit,  FS_FloatPoint point))

INTERFACE(FS_BOOLEAN, FPDCPWLEditOnLButtonDblClk, (FPD_CPWL_Edit pEdit,  FS_FloatPoint point))

INTERFACE(FS_BOOLEAN, FPDCPWLEditOnRButtonUp, (FPD_CPWL_Edit pEdit,  FS_FloatPoint point))

INTERFACE(FS_BOOLEAN, FPDCPWLEditOnKeyDown, (FPD_CPWL_Edit pEdit,  FS_DWORD nChar))

INTERFACE(FS_BOOLEAN, FPDCPWLEditOnMouseMove, (FPD_CPWL_Edit pEdit,  FS_FloatPoint point))

INTERFACE(FS_BOOLEAN, FPDCPWLEditOnLButtonUp, (FPD_CPWL_Edit pEdit,  FS_FloatPoint point))

NumOfSelector(FPDCPWLEdit)
ENDENUM

//*****************************
/* VariableTextIterator HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOL, FPDVariableTextIteratorNextWord, (FPD_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FPDVariableTextIteratorPrevWord, (FPD_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FPDVariableTextIteratorNextLine, (FPD_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FPDVariableTextIteratorPrevLine, (FPD_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FPDVariableTextIteratorNextSection, (FPD_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FPDVariableTextIteratorPrevSection, (FPD_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FPDVariableTextIteratorGetWord, (FPD_VariableText_Iterator iterator,  FPD_VTWord* outWord))

INTERFACE(FS_BOOL, FPDVariableTextIteratorSetWord, (FPD_VariableText_Iterator iterator,  FPD_VTWord word))

INTERFACE(FS_BOOL, FPDVariableTextIteratorGetLine, (FPD_VariableText_Iterator iterator,  FPD_VTLine* outLine))

INTERFACE(FS_BOOL, FPDVariableTextIteratorGetSection, (FPD_VariableText_Iterator iterator,  FPD_VTSection* outSection))

INTERFACE(FS_BOOL, FPDVariableTextIteratorSetSection, (FPD_VariableText_Iterator iterator,  FPD_VTSection section))

INTERFACE(void, FPDVariableTextIteratorSetAt, (FPD_VariableText_Iterator iterator,  FS_INT32 nWordIndex))

INTERFACE(void, FPDVariableTextIteratorSetAtII, (FPD_VariableText_Iterator iterator,  FPD_VTWordPlace place))

INTERFACE(void, FPDVariableTextIteratorGetAt, (FPD_VariableText_Iterator iterator,  FPD_VTWordPlace* outWordPlace))

INTERFACE(FS_BOOL, FPDVariableTextIteratorGetDisplayWord, (FPD_VariableText_Iterator iterator,  FPD_VTWord* outWord))

NumOfSelector(FPDVariableTextIterator)
ENDENUM

//*****************************
/* VTLine HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_VTLine, FPDVTLineNew, ())

INTERFACE(void, FPDVTLineDestroy, (FPD_VTLine line))

INTERFACE(void, FPDVTLineSetStartWordPlace, (FPD_VTLine line,  FPD_VTWordPlace lineplace))

INTERFACE(FPD_VTWordPlace, FPDVTLineGetStartWordPlace, (FPD_VTLine line))

INTERFACE(void, FPDVTLineSetEndWordPlace, (FPD_VTLine line,  FPD_VTWordPlace lineEnd))

INTERFACE(FPD_VTWordPlace, FPDVTLineGetEndWordPlace, (FPD_VTLine line))

INTERFACE(void, FPDVTLineSetOriginalPosition, (FPD_VTLine line,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(void, FPDVTLineGetOriginalPosition, (FPD_VTLine line,  FS_FLOAT* x,  FS_FLOAT* y))

INTERFACE(void, FPDVTLineSetWidth, (FPD_VTLine line,  FS_FLOAT fLineWidth))

INTERFACE(FS_FLOAT, FPDVTLineGetWidth, (FPD_VTLine line))

INTERFACE(void, FPDVTLineSetAscent, (FPD_VTLine line,  FS_FLOAT fLineAscent))

INTERFACE(FS_FLOAT, FPDVTLineGetAscent, (FPD_VTLine line))

INTERFACE(void, FPDVTLineSetDescent, (FPD_VTLine line,  FS_FLOAT fLineDescent))

INTERFACE(FS_FLOAT, FPDVTLineGetDescent, (FPD_VTLine line))

NumOfSelector(FPDVTLine)
ENDENUM

//*****************************
/* VTSection HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_VTSection, FPDVTSectionNew, ())

INTERFACE(void, FPDVTSectionDestroy, (FPD_VTSection section))

INTERFACE(void, FPDVTSectionSetStartWordPlace, (FPD_VTSection section,  FPD_VTWordPlace secplace))

INTERFACE(FPD_VTWordPlace, FPDVTSectionGetStartWordPlace, (FPD_VTSection section))

INTERFACE(void, FPDVTSectionSetRect, (FPD_VTSection section,  FS_FloatRect rect))

INTERFACE(FS_FloatRect, FPDVTSectionGetRect, (FPD_VTSection section))

INTERFACE(void, FPDVTSectionSetSectionProperties, (FPD_VTSection section,  FPD_VTSecProps SecProps))

INTERFACE(FPD_VTSecProps, FPDVTSectionGetSectionProperties, (FPD_VTSection section))

INTERFACE(void, FPDVTSectionSetWordProperties, (FPD_VTSection section,  FPD_VTSecProps WordProps))

INTERFACE(FPD_VTWordProps, FPDVTSectionGetWordProperties, (FPD_VTSection section))

NumOfSelector(FPDVTSection)
ENDENUM

//*****************************
/* VariableText HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_VariableText, FPDVariableTextNew, ())

INTERFACE(void, FPDVariableTextDestroy, (FPD_VariableText variableText))

INTERFACE(FPD_VariableText_Provider, FPDVariableTextProviderNew, (FPD_VariableTextProviderCallbacks callbacks))

INTERFACE(void, FPDVariableTextProviderDestroy, (FPD_VariableText_Provider provider))

INTERFACE(FPD_VariableText_Provider, FPDVariableTextSetProvider, (FPD_VariableText variableText,  FPD_VariableText_Provider provider))

INTERFACE(FPD_VariableText_Iterator, FPDVariableTextGetIterator, (FPD_VariableText variableText))

INTERFACE(void, FPDVariableTextSetPlateRect, (FPD_VariableText variableText,  FS_FloatRect rect,  FS_BOOL bVerticalWriting))

INTERFACE(FS_BOOL, FPDVariableTextIsVerticalWriting, (FPD_VariableText variableText))

INTERFACE(void, FPDVariableTextSetAlignment, (FPD_VariableText variableText,  FS_INT32 nFormat))

INTERFACE(void, FPDVariableTextSetPasswordChar, (FPD_VariableText variableText,  FS_WORD wSubWord))

INTERFACE(void, FPDVariableTextSetLimitChar, (FPD_VariableText variableText,  FS_INT32 nLimitChar))

INTERFACE(void, FPDVariableTextSetCharArray, (FPD_VariableText variableText,  FS_INT32 nCharArray))

INTERFACE(void, FPDVariableTextSetCharSpace, (FPD_VariableText variableText,  FS_FLOAT fCharSpace))

INTERFACE(void, FPDVariableTextSetWordSpace, (FPD_VariableText variableText,  FS_FLOAT fWordSpace))

INTERFACE(void, FPDVariableTextSetHorzScale, (FPD_VariableText variableText,  FS_FLOAT fHorzScale))

INTERFACE(void, FPDVariableTextSetMultiLine, (FPD_VariableText variableText,  FS_BOOL bMultiLine))

INTERFACE(void, FPDVariableTextSetAutoReturn, (FPD_VariableText variableText,  FS_BOOL bAuto))

INTERFACE(void, FPDVariableTextSetAutoFontSize, (FPD_VariableText variableText,  FS_BOOL bAuto))

INTERFACE(void, FPDVariableTextSetFontSize, (FPD_VariableText variableText,  FS_FLOAT fFontSize))

INTERFACE(void, FPDVariableTextSetLineLeading, (FPD_VariableText variableText,  FS_FLOAT fLineLeading))

INTERFACE(void, FPDVariableTextSetRichText, (FPD_VariableText variableText,  FS_BOOL bRichText))

INTERFACE(void, FPDVariableTextSetDirectionRTL, (FPD_VariableText variableText,  FS_BOOL bRTL,  FR_VTWordRange PlaceRange))

INTERFACE(void, FPDVariableTextInitialize, (FPD_VariableText variableText))

INTERFACE(FS_BOOL, FPDVariableTextIsValid, (FPD_VariableText variableText))

INTERFACE(FS_BOOL, FPDVariableTextIsRichText, (FPD_VariableText variableText))

INTERFACE(void, FPDVariableTextRearrangeAll, (FPD_VariableText variableText))

INTERFACE(void, FPDVariableTextRearrangePart, (FPD_VariableText variableText,  FR_VTWordRange PlaceRange))

INTERFACE(void, FPDVariableTextResetAll, (FPD_VariableText variableText))

INTERFACE(void, FPDVariableTextSetText, (FPD_VariableText variableText,  FS_LPCWSTR text,  FS_INT32 charset,  FPD_VTSecProps pSecProps,  FPD_VTWordProps pWordProps))

INTERFACE(void, FPDVariableTextInsertWord, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FS_WORD word,  FS_INT32 charset,  FPD_VTWordProps pWordProps,  FS_BOOL bNeedTransform,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextInsertSection, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FPD_VTSecProps pSecProps,  FPD_VTWordProps pWordProps,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextInsertText, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FS_LPCWSTR text,  FS_INT32 charset,  FPD_VTSecProps pSecProps,  FPD_VTWordProps pWordProps,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextDeleteWords, (FPD_VariableText variableText,  FPD_VTWordRange PlaceRange,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextDeleteWord, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextBackSpaceWord, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FPD_VTWordPlace* outPlace))

INTERFACE(FS_FloatRect, FPDVariableTextGetPlateRect, (FPD_VariableText variableText))

INTERFACE(FS_FloatRect, FPDVariableTextGetContentRect, (FPD_VariableText variableText))

INTERFACE(FS_INT32, FPDVariableTextGetTotalWords, (FPD_VariableText variableText))

INTERFACE(FS_FLOAT, FPDVariableTextGetFontSize, (FPD_VariableText variableText))

INTERFACE(FS_INT32, FPDVariableTextGetAlignment, (FPD_VariableText variableText))

INTERFACE(FS_FLOAT, FPDVariableTextGetWordSpace, (FPD_VariableText variableText))

INTERFACE(FS_WORD, FPDVariableTextGetPasswordChar, (FPD_VariableText variableText))

INTERFACE(FS_INT32, FPDVariableTextGetCharArray, (FPD_VariableText variableText))

INTERFACE(FS_INT32, FPDVariableTextGetLimitChar, (FPD_VariableText variableText))

INTERFACE(FS_BOOL, FPDVariableTextIsMultiLine, (FPD_VariableText variableText))

INTERFACE(FS_BOOL, FPDVariableTextIsAutoReturn, (FPD_VariableText variableText))

INTERFACE(FS_FLOAT, FPDVariableTextGetHorzScale, (FPD_VariableText variableText))

INTERFACE(FS_FLOAT, FPDVariableTextGetCharSpace, (FPD_VariableText variableText))

INTERFACE(void, FPDVariableTextGetBeginWordPlace, (FPD_VariableText variableText,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextGetEndWordPlace, (FPD_VariableText variableText,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextGetPrevWordPlace, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextGetNextWordPlace, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextSearchWordPlace, (FPD_VariableText variableText,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextGetUpWordPlace, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextGetDownWordPlace, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FS_FLOAT x,  FS_FLOAT y,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextGetLineBeginPlace, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextGetLineEndPlace, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextGetSectionBeginPlace, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextGetSectionEndPlace, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FPD_VTWordPlace* outPlace))

INTERFACE(void, FPDVariableTextUpdateWordPlace, (FPD_VariableText variableText,  FPD_VTWordPlace place))

INTERFACE(void, FPDVariableTextAjustLineHeader, (FPD_VariableText variableText,  FPD_VTWordPlace place,  FS_BOOL bPrevOrNext,  FPD_VTWordPlace* outPlace))

INTERFACE(FS_INT32, FPDVariableTextWordPlaceToWordIndex, (FPD_VariableText variableText,  FPD_VTWordPlace place))

INTERFACE(void, FPDVariableTextWordIndexToWordPlace, (FPD_VariableText variableText,  FS_INT32 index,  FPD_VTWordPlace* outPlace))

INTERFACE(FS_BOOL, FPDVariableTextIsSectionComplexScript, (FPD_VariableText variableText,  FPD_VTWordPlace place))

INTERFACE(FS_BOOL, FPDVariableTextIsVerticalFont, (FPD_VariableText variableText,  FS_INT32 nFontindex))

NumOfSelector(FPDVariableText)
ENDENUM

//*****************************
/* EDITFontData HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_EDIT_FontData, FPDEDITFontDataNew, ())

INTERFACE(void, FPDEDITFontDataDestroy, (FPD_EDIT_FontData fontdata))

INTERFACE(void, FPDEDITFontDataSetFont, (FPD_EDIT_FontData fontdata,  FPD_Font font))

INTERFACE(FPD_Font, FPDEDITFontDataGetFont, (FPD_EDIT_FontData fontdata))

INTERFACE(void, FPDEDITFontDataSetFontName, (FPD_EDIT_FontData fontdata,  FS_LPCSTR fontName))

INTERFACE(void, FPDEDITFontDataGetFontName, (FPD_EDIT_FontData fontdata,  FS_ByteString* outFontName))

NumOfSelector(FPDEDITFontData)
ENDENUM

//*****************************
/* BulletWordIterator HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FPDBulletWordIteratorSetBeginBulletWordPos, (FPD_Bullet_WordIterator wordIterator,  FS_INT32 nWordIndex))

INTERFACE(FS_BOOLEAN, FPDBulletWordIteratorNextBulletWord, (FPD_Bullet_WordIterator wordIterator))

INTERFACE(FS_BOOLEAN, FPDBulletWordIteratorGetBulletWord, (FPD_Bullet_WordIterator wordIterator,  FPD_VTWord* outword))

INTERFACE(void, FPDBulletWordIteratorSetBulletWord, (FPD_Bullet_WordIterator wordIterator,  const FPD_VTWord word))

INTERFACE(FS_BOOLEAN, FPDBulletWordIteratorGetBulletDisplayWord, (FPD_Bullet_WordIterator wordIterator,  FPD_VTWord* outword))

INTERFACE(FS_INT32, FPDBulletWordIteratorGetBeginBulletWordPos, (FPD_Bullet_WordIterator wordIterator))

NumOfSelector(FPDBulletWordIterator)
ENDENUM

//*****************************
/* VTWordPlace HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_VTWordPlace, FPDVTWordPlaceNew, (FS_INT32 nSecIndex,  FS_INT32 nLineIndex,  FS_INT32 nWordIndex))

INTERFACE(void, FPDVTWordPlaceDestroy, (FPD_VTWordPlace wordPlace))

INTERFACE(void, FPDVTWordPlaceSetDefault, (FPD_VTWordPlace wordPlace))

INTERFACE(FS_BOOL, FPDVTWordPlaceEqual, (FPD_VTWordPlace wordPlace,  FPD_VTWordPlace destWordPlace))

INTERFACE(FS_INT32, FPDVTWordPlaceWordCmp, (FPD_VTWordPlace wordPlace,  FPD_VTWordPlace destWordPlace))

INTERFACE(FS_INT32, FPDVTWordPlaceLineCmp, (FPD_VTWordPlace wordPlace,  FPD_VTWordPlace destWordPlace))

INTERFACE(FS_INT32, FPDVTWordPlaceSecCmp, (FPD_VTWordPlace wordPlace,  FPD_VTWordPlace destWordPlace))

INTERFACE(void, FPDVTWordPlaceSetSectionIndex, (FPD_VTWordPlace wordPlace,  FS_INT32 nSecIndex))

INTERFACE(FS_INT32, FPDVTWordPlaceGetSectionIndex, (FPD_VTWordPlace wordPlace))

INTERFACE(void, FPDVTWordPlaceSetLineIndex, (FPD_VTWordPlace wordPlace,  FS_INT32 nLineIndex))

INTERFACE(FS_INT32, FPDVTWordPlaceGetLineIndex, (FPD_VTWordPlace wordPlace))

INTERFACE(void, FPDVTWordPlaceSetWordIndex, (FPD_VTWordPlace wordPlace,  FS_INT32 nWordIndex))

INTERFACE(FS_INT32, FPDVTWordPlaceGetWordIndex, (FPD_VTWordPlace wordPlace))

NumOfSelector(FPDVTWordPlace)
ENDENUM

//*****************************
/* EDITFONTDATAArray HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDEDITFONTDATAArrayCreate
 * @details Create FPD_EDITFONTArray obj.
 * @return   FPD_EDITFONTArray
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_EDITFONTArray, FPDEDITFONTDATAArrayCreate, ())

/**
 * @brief FPDEDITFONTDATAArrayDelete
 * @details Delete FPD_EDITFONTArray obj.
 * @param[in]  fontArr The input FPD_EDITFONTArray object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDEDITFONTDATAArrayDelete, (FPD_EDITFONTArray fontArr))

/**
 * @brief FPDEDITFONTDATAArrayGetSize
 * @details Get the size of the array.
 * @param[in]  fontArr The input FPD_EDITFONTArray object.
 * @return   FS_INT32         The size in objects in the array.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FS_INT32, FPDEDITFONTDATAArrayGetSize, (FPD_EDITFONTArray fontArr))

/**
 * @brief FPDEDITFONTDATAArrayGetData
 * @details Get a pointer to the specified element in the array. Direct pointer access.
 * @param[in]  fontArr The input FPD_EDITFONTArray object.
 * @param[in]  index Specifies the zero-based index of element in the array.
 * @return   FPD_EDIT_FontData  A pointer to the specified element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(FPD_EDIT_FontData, FPDEDITFONTDATAArrayGetData, (FPD_EDITFONTArray fontArr,  FS_INT32 index))

/**
 * @brief FPDEDITFONTDATAArrayRemoveAt
 * @details Remove an object at specified position.
 * @param[in]  fontArr The input FPD_EDITFONTArray object.
 * @param[in]  index Specifies the zero-based index of object in the array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDEDITFONTDATAArrayRemoveAt, (FPD_EDITFONTArray fontArr,  FS_INT32 index))

/**
 * @brief FPDEDITFONTDATAArrayRemoveAll
 * @details Remove all objects in the array.
 * @param[in]  fontArr The input FPD_EDITFONTArray object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
 */
INTERFACE(void, FPDEDITFONTDATAArrayRemoveAll, (FPD_EDITFONTArray fontArr))

NumOfSelector(FPDEDITFONTDATAArray)
ENDENUM

//*****************************
/* VTBulletIterator HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOLEAN, FPDVTBulletIteratorNextBullet, (FPD_VTBulletIterator iterator))

INTERFACE(FPD_TextList, FPDVTBulletIteratorGetBullet, (FPD_VTBulletIterator iterator))

INTERFACE(void, FPDVTBulletIteratorSetBeginnIndex, (FPD_VTBulletIterator iterator,  FS_INT32 nIndex))

INTERFACE(FS_INT32, FPDVTBulletIteratorGetCurIndex, (FPD_VTBulletIterator iterator))

NumOfSelector(FPDVTBulletIterator)
ENDENUM

//*****************************
/* TextList HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_TextListItem, FPDTextListGetChildItem, (FPD_TextList textList))

INTERFACE(void, FPDTextListReCalculateLableWidth, (FPD_TextList textList,  FPD_TextListItem pListItem))

INTERFACE(FPD_TextListItem, FPDTextListGetNextSiblingItem, (FPD_TextList textList,  FPD_TextListItem pItem))

NumOfSelector(FPDTextList)
ENDENUM

//*****************************
/* PWLFillerNotify HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_PWLFillerNotify, FPDPWLFillerNotifyCreate, (FPD_PWLFillerNotifyCallbacks callbacks))

INTERFACE(void, FPDPWLFillerNotifyDelete, (FPD_PWLFillerNotify notify))

NumOfSelector(FPDPWLFillerNotify)
ENDENUM

//*****************************
/* List HFT functions */
//*****************************

BEGINENUM
INTERFACE(void, FPDListSetDirectionRTL, (FPD_List list,  FS_BOOLEAN bRTL,  FS_BOOLEAN bApplyAllSection,  FS_BOOLEAN bPaint,  FS_BOOLEAN bAddUndo))

INTERFACE(void, FPDListSetAlignment, (FPD_List list,  FS_INT32 nAlignment))

INTERFACE(FS_INT32, FPDListGetAlignment, (FPD_List list))

NumOfSelector(FPDList)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

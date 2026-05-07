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
//----------_V17----------
//*****************************
/* CPWLListBox HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_ListBox, FPDCPWLListBoxNew, ())

INTERFACE(void, FPDCPWLListBoxDelete, (FPD_CPWL_ListBox listbox))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLListBoxCastToCPWLWnd, (FPD_CPWL_ListBox listbox))

INTERFACE(void, FPDCPWLListBoxAddString, (FPD_CPWL_ListBox listbox,  FS_LPCWSTR str,  FS_BOOLEAN bAutoFontSize))

INTERFACE(FS_UINT, FPDCPWLListBoxGetTopVisibleIndex, (FPD_CPWL_ListBox listbox,  FS_INT32 oldTopIndex))

INTERFACE(void, FPDCPWLListBoxSelect, (FPD_CPWL_ListBox listbox,  FS_INT32 nItemIndex))

INTERFACE(void, FPDCPWLListBoxSetTopVisibleIndex, (FPD_CPWL_ListBox listbox,  FS_INT32 nItemIndex))

INTERFACE(void, FPDCPWLListBoxSetSelectBackColor, (FPD_CPWL_ListBox listbox,  const FPD_ColorF color))

INTERFACE(void, FPDCPWLListBoxSetSelectTextColor, (FPD_CPWL_ListBox listbox,  const FPD_ColorF color))

INTERFACE(FS_UINT, FPDCPWLListBoxGetCurSel, (FPD_CPWL_ListBox listbox))

INTERFACE(FS_UINT, FPDCPWLListBoxGetCount, (FPD_CPWL_ListBox listbox))

INTERFACE(FS_BOOLEAN, FPDCPWLListBoxIsItemSelected, (FPD_CPWL_ListBox listbox,  FS_INT32 nItemIndex))

INTERFACE(FS_FLOAT, FPDCPWLListBoxGetFontSize, (FPD_CPWL_ListBox listbox))

INTERFACE(void, FPDCPWLListBoxSetCaret, (FPD_CPWL_ListBox listbox,  FS_INT32 nItemIndex))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLListBoxCastToWnd, (FPD_CPWL_ListBox listbox))

INTERFACE(FPD_CPWL_ListBox, FPDCPWLListBoxGetFromWnd, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLListBoxGetText, (FPD_CPWL_ListBox listbox,  FS_WideString* outText))

INTERFACE(void, FPDCPWLListBoxSetFillerNotify, (FPD_CPWL_ListBox listbox,  FPD_PWLFillerNotify notify))

INTERFACE(FPD_List, FPDCPWLListBoxGetControlList, (FPD_CPWL_ListBox listbox))

NumOfSelector(FPDCPWLListBox)
ENDENUM

//*****************************
/* CPWLComboBox HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_ComboBox, FPDCPWLComboBoxNew, ())

INTERFACE(void, FPDCPWLComboBoxDelete, (FPD_CPWL_ComboBox comboBox))

INTERFACE(void, FPDCPWLComboBoxAddString, (FPD_CPWL_ComboBox comboBox,  FS_LPCWSTR str,  FS_BOOLEAN bAutoFontSize))

INTERFACE(FS_UINT, FPDCPWLComboBoxGetSelect, (FPD_CPWL_ComboBox comboBox))

INTERFACE(void, FPDCPWLComboBoxSetSelect, (FPD_CPWL_ComboBox comboBox,  FS_INT32 nItemIndex))

INTERFACE(FS_UINT, FPDCPWLComboBoxGetLastSelect, (FPD_CPWL_ComboBox comboBox))

INTERFACE(void, FPDCPWLComboBoxGetText, (FPD_CPWL_ComboBox comboBox,  FS_WideString* outText))

INTERFACE(void, FPDCPWLComboBoxSetText, (FPD_CPWL_ComboBox comboBox,  FS_LPCWSTR text))

INTERFACE(void, FPDCPWLComboBoxSelectAll, (FPD_CPWL_ComboBox comboBox))

INTERFACE(FS_FLOAT, FPDCPWLComboBoxGetListFontSize, (FPD_CPWL_ComboBox comboBox))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLComboBoxCastToWnd, (FPD_CPWL_ComboBox comboBox))

INTERFACE(FPD_CPWL_ComboBox, FPDCPWLComboBoxGetFromWnd, (FPD_CPWL_Wnd wnd))

INTERFACE(void, FPDCPWLComboBoxSetEditSel, (FPD_CPWL_ComboBox comboBox,  FS_INT32 nStartChar,  FS_INT32 nEndChar))

INTERFACE(void, FPDCPWLComboBoxGetEditSel, (FPD_CPWL_ComboBox comboBox,  FS_INT32* nStartChar,  FS_INT32* nEndChar))

INTERFACE(void, FPDCPWLComboBoxSetFillerNotify, (FPD_CPWL_ComboBox comboBox,  FPD_PWLFillerNotify notify))

INTERFACE(FPD_CPWL_Edit, FPDCPWLComboBoxGetEdit, (FPD_CPWL_ComboBox comboBox))

NumOfSelector(FPDCPWLComboBox)
ENDENUM

//*****************************
/* CPWLCheckBox HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_CheckBox, FPDCPWLCheckBoxNew, ())

INTERFACE(void, FPDCPWLCheckBoxDelete, (FPD_CPWL_CheckBox checkBox))

INTERFACE(void, FPDCPWLCheckBoxSetCheck, (FPD_CPWL_CheckBox checkBox,  FS_BOOLEAN bCheck))

INTERFACE(FS_BOOLEAN, FPDCPWLCheckBoxIsChecked, (FPD_CPWL_CheckBox checkBox))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLCheckBoxCastToWnd, (FPD_CPWL_CheckBox checkBox))

INTERFACE(FPD_CPWL_CheckBox, FPDCPWLCheckBoxGetFromWnd, (FPD_CPWL_Wnd wnd))

NumOfSelector(FPDCPWLCheckBox)
ENDENUM

//*****************************
/* CPWLRadioButton HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_RadioButton, FPDCPWLRadioButtonNew, ())

INTERFACE(void, FPDCPWLRadioButtonDelete, (FPD_CPWL_RadioButton button))

INTERFACE(void, FPDCPWLRadioButtonSetCheck, (FPD_CPWL_RadioButton button,  FS_BOOLEAN bCheck))

INTERFACE(FS_BOOLEAN, FPDCPWLRadioButtonIsChecked, (FPD_CPWL_RadioButton button))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLRadioButtonCastToWnd, (FPD_CPWL_RadioButton button))

INTERFACE(FPD_CPWL_RadioButton, FPDCPWLRadioButtonGetFromWnd, (FPD_CPWL_Wnd wnd))

NumOfSelector(FPDCPWLRadioButton)
ENDENUM

//*****************************
/* CPWLPushButton HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_PushButton, FPDCPWLPushButtonNew, ())

INTERFACE(void, FPDCPWLPushButtonDelete, (FPD_CPWL_PushButton button))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLPushButtonCastToWnd, (FPD_CPWL_PushButton button))

INTERFACE(FPD_CPWL_PushButton, FPDCPWLPushButtonGetFromWnd, (FPD_CPWL_Wnd wnd))

NumOfSelector(FPDCPWLPushButton)
ENDENUM

//*****************************
/* CPWLIcon HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_Icon, FPDCPWLIconNew, ())

INTERFACE(void, FPDCPWLIconDelete, (FPD_CPWL_Icon icon))

INTERFACE(FS_INT32, FPDCPWLIconGetScaleMethod, (FPD_CPWL_Icon icon))

INTERFACE(FS_BOOLEAN, FPDCPWLIconIsProportionalScale, (FPD_CPWL_Icon icon))

INTERFACE(void, FPDCPWLIconGetIconPosition, (FPD_CPWL_Icon icon,  FS_FLOAT* fLeft,  FS_FLOAT* fBottom))

INTERFACE(FS_BOOLEAN, FPDCPWLIconGetFittingBounds, (FPD_CPWL_Icon icon))

INTERFACE(void, FPDCPWLIconSetIconFit, (FPD_CPWL_Icon icon,  FPD_IconFit pIconFit))

INTERFACE(FPD_CPWL_Image, FPDCPWLIconCastToImage, (FPD_CPWL_Icon icon))

NumOfSelector(FPDCPWLIcon)
ENDENUM

//*****************************
/* CPWLEditCtrl HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_EditCtrl, FPDCPWLEditCtrlNew, ())

INTERFACE(void, FPDCPWLEditCtrlDelete, (FPD_CPWL_EditCtrl ctrl))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLEditCtrlCastToWnd, (FPD_CPWL_EditCtrl ctrl))

INTERFACE(FS_INT32, FPDCPWLEditCtrlGetCharSet, (FPD_CPWL_EditCtrl ctrl))

INTERFACE(FPD_CPWL_EditCtrl, FPDCPWLEditCtrlGetFromWnd, (FPD_CPWL_Wnd wnd))

INTERFACE(FS_INT32, FPDCPWLEditCtrlGetCaret, (FPD_CPWL_EditCtrl ctrl))

INTERFACE(void, FPDCPWLEditCtrlLoadCurrentWordProps, (FPD_CPWL_EditCtrl ctrl,  FPD_VTWordProps* wp,  FS_INT32 nCharset))

INTERFACE(FS_BOOLEAN, FPDCPWLEditCtrlIsCJK, (FPD_CPWL_EditCtrl ctrl))

INTERFACE(void, FPDCPWLEditCtrlGetCaretPos, (FPD_CPWL_EditCtrl ctrl,  FS_INT32* x,  FS_INT32* y))

NumOfSelector(FPDCPWLEditCtrl)
ENDENUM

//*****************************
/* SpellCheck HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDSpellCheckNew
 * @details Create FPD_SpellCheck object.
 * @param[in]  callback The input FPD_PWLSpellCheckCallbacks object.
 * @return   FPD_SpellCheck
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FPD_SpellCheck, FPDSpellCheckNew, (FPD_PWLSpellCheckCallbacks callback))

/**
 * @brief FPDSpellCheckDelete
 * @details Delete spellcheck object.
 * @param[in]  spellcheck The input <a>FPD_SpellCheck</a> object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FPDSpellCheckDelete, (FPD_SpellCheck spellcheck))

/**
 * @brief FPDSpellCheckCheckWord
 * @details Checks whether the input words are correct or not.
 * @param[in]  spellCheck The input <a>FPD_SpellCheck</a> object.
 * @param[in]  sWord The input words to be checked.
 * @return   <a>TRUE</a> if the words are checked correctly, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FPDSpellCheckCheckWord, (FPD_SpellCheck spellCheck,  FS_LPCWSTR sWord))

/**
 * @brief FPDSpellCheckSuggestWords
 * @details Input the words to get its suggested words.
 * @param[in]  spellCheck The input <a>FPD_SpellCheck</a> object.
 * @param[in]  sWord The input words.
 * @param[out]  outSuggest It receives the suggested words.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FPDSpellCheckSuggestWords, (FPD_SpellCheck spellCheck,  FS_LPCWSTR sWord,  FS_WideStringArray* outSuggest))

/**
 * @brief FPDSpellCheckIsCurSCSupWord
 * @details brief According to the dictionary configuration that the current user chooses to do spell
	* check, whether characters should participate in spell check.
 * @param[in]  spellCheck The input <a>FPD_SpellCheck</a> object.
 * @param[in]  sUnicode The input Unicode.
 * @return   FS_BOOLEAN   return <b>true</b> means success, while <b>false</b> means failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
 * @see FRSpellCheckNew
 */
INTERFACE(FS_BOOLEAN, FPDSpellCheckIsCurSCSupWord, (FPD_SpellCheck spellCheck,  FS_WORD sUnicode))

/**
 * @brief FPDSpellCheckIsSCAvalible
 * @details 
 * @return   
 * @note 
 */
INTERFACE(FS_BOOLEAN, FPDSpellCheckIsSCAvalible, (FPD_SpellCheck spellCheck))

NumOfSelector(FPDSpellCheck)
ENDENUM

//*****************************
/* CPWLSignature HFT functions */
//*****************************

BEGINENUM
INTERFACE(FPD_CPWL_Signature, FPDCPWLSignatureNew, ())

INTERFACE(void, FPDCPWLSignatureDelete, (FPD_CPWL_Signature sig))

INTERFACE(void, FPDCPWLSignatureSetIconText, (FPD_CPWL_Signature sig,  FS_LPCWSTR sText))

INTERFACE(void, FPDCPWLSignatureSetDescription, (FPD_CPWL_Signature sig,  FS_LPCWSTR str))

INTERFACE(void, FPDCPWLSignatureSetImage, (FPD_CPWL_Signature sig,  FS_DIBSource pImage))

INTERFACE(void, FPDCPWLSignatureSetImageStream, (FPD_CPWL_Signature sig,  FPD_Object pStream,  FS_LPCSTR sImageAlias,  FS_BOOLEAN bKeepRatio))

INTERFACE(void, FPDCPWLSignatureSetTextFlag, (FPD_CPWL_Signature sig,  FS_BOOLEAN bTextExist))

INTERFACE(void, FPDCPWLSignatureSetImageFlag, (FPD_CPWL_Signature sig,  FS_BOOLEAN bImageExist))

INTERFACE(void, FPDCPWLSignatureSetFoxitFlag, (FPD_CPWL_Signature sig,  FS_BOOLEAN bFlagExist))

INTERFACE(void, FPDCPWLSignatureSetIconTextFontSize, (FPD_CPWL_Signature sig,  FS_FLOAT fFontSize))

INTERFACE(void, FPDCPWLSignatureSetDescriptionFontSize, (FPD_CPWL_Signature sig,  FS_FLOAT fFontSize))

INTERFACE(void, FPDCPWLSignatureSetIconTextColor, (FPD_CPWL_Signature sig,  FPD_ColorF color))

INTERFACE(void, FPDCPWLSignatureSetDescriptionColor, (FPD_CPWL_Signature sig,  FPD_ColorF color))

INTERFACE(FPD_CPWL_Wnd, FPDCPWLSignatureCastToWnd, (FPD_CPWL_Signature sig))

INTERFACE(FPD_CPWL_Signature, FPDCPWLSignatureGetFromWnd, (FPD_CPWL_Wnd wnd))

NumOfSelector(FPDCPWLSignature)
ENDENUM

//----------_V18----------
//----------_V19----------
//----------_V20----------

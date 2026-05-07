#ifndef FPD_PWLIMPL_H
#define FPD_PWLIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifndef FPD_PWLEXPT_H
#include "../fpd_pwlExpt.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


class CFPD_CPWLListBox_V17
{
public:
	static FPD_CPWL_ListBox New();
	static void Delete(FPD_CPWL_ListBox listbox);
	static FPD_CPWL_Wnd CastToCPWLWnd(FPD_CPWL_ListBox listbox);
	static void AddString(FPD_CPWL_ListBox listbox, FS_LPCWSTR str, FS_BOOLEAN bAutoFontSize);
	static FS_UINT GetTopVisibleIndex(FPD_CPWL_ListBox listbox, FS_INT32 oldTopIndex);
	static void Select(FPD_CPWL_ListBox listbox, FS_INT32 nItemIndex);
	static void SetTopVisibleIndex(FPD_CPWL_ListBox listbox, FS_INT32 nItemIndex);
	static void SetSelectBackColor(FPD_CPWL_ListBox listbox, const FPD_ColorF color);
	static void SetSelectTextColor(FPD_CPWL_ListBox listbox, const FPD_ColorF color);
	static FS_UINT GetCurSel(FPD_CPWL_ListBox listbox);
	static FS_UINT GetCount(FPD_CPWL_ListBox listbox);
	static FS_BOOLEAN IsItemSelected(FPD_CPWL_ListBox listbox, FS_INT32 nItemIndex);
	static FS_FLOAT GetFontSize(FPD_CPWL_ListBox listbox);	
	static void SetCaret(FPD_CPWL_ListBox listbox, FS_INT32 nItemIndex);
	static FPD_CPWL_Wnd CastToWnd(FPD_CPWL_ListBox listbox);
	static FPD_CPWL_ListBox GetFromWnd(FPD_CPWL_Wnd wnd);
	static void GetText(FPD_CPWL_ListBox listbox, FS_WideString* outText);
	static void SetFillerNotify(FPD_CPWL_ListBox listbox, FPD_PWLFillerNotify notify);
	static FPD_List GetControlList(FPD_CPWL_ListBox listbox);
};

class CFPD_CPWLComboBox_V17
{
public:
	static FPD_CPWL_ComboBox New();
	static void Delete(FPD_CPWL_ComboBox comboBox);
	static void AddString(FPD_CPWL_ComboBox comboBox, FS_LPCWSTR str, FS_BOOLEAN bAutoFontSize);
	static FS_UINT GetSelect(FPD_CPWL_ComboBox comboBox);
	static void SetSelect(FPD_CPWL_ComboBox comboBox, FS_INT32 nItemIndex);
	static FS_UINT GetLastSelect(FPD_CPWL_ComboBox comboBox);
	static void GetText(FPD_CPWL_ComboBox comboBox, FS_WideString* outText);
	static void SetText(FPD_CPWL_ComboBox comboBox, FS_LPCWSTR text);
	static void SelectAll(FPD_CPWL_ComboBox comboBox);
	static FS_FLOAT GetListFontSize(FPD_CPWL_ComboBox comboBox);
	static FPD_CPWL_Wnd CastToWnd(FPD_CPWL_ComboBox comboBox);
	static FPD_CPWL_ComboBox GetFromWnd(FPD_CPWL_Wnd wnd);
	static void SetEditSel(FPD_CPWL_ComboBox comboBox, FS_INT32 nStartChar, FS_INT32 nEndChar);
	static void GetEditSel(FPD_CPWL_ComboBox comboBox, FS_INT32* nStartChar, FS_INT32* nEndChar);
	static void SetFillerNotify(FPD_CPWL_ComboBox comboBox, FPD_PWLFillerNotify notify);
	static FPD_CPWL_Edit GetEdit(FPD_CPWL_ComboBox comboBox);
};

class CFPD_CPWLCheckBox_V17
{
public:
	static FPD_CPWL_CheckBox New();
	static void Delete(FPD_CPWL_CheckBox checkBox);
	static void SetCheck(FPD_CPWL_CheckBox checkBox, FS_BOOLEAN bCheck);
	static FS_BOOLEAN IsChecked(FPD_CPWL_CheckBox checkBox);
	static FPD_CPWL_Wnd CastToWnd(FPD_CPWL_CheckBox checkBox);
	static FPD_CPWL_CheckBox GetFromWnd(FPD_CPWL_Wnd wnd);
};
	
class CFPD_CPWLRadioButton_V17
{
public:
	static FPD_CPWL_RadioButton New();
	static void Delete(FPD_CPWL_RadioButton button);
	static void SetCheck(FPD_CPWL_RadioButton button, FS_BOOLEAN bCheck);
	static FS_BOOLEAN IsChecked(FPD_CPWL_RadioButton button);	
	static FPD_CPWL_Wnd CastToWnd(FPD_CPWL_RadioButton button);
	static FPD_CPWL_RadioButton GetFromWnd(FPD_CPWL_Wnd wnd);
};

class CFPD_CPWLPushButton_V17
{
public:
	static FPD_CPWL_PushButton New();
	static void Delete(FPD_CPWL_PushButton button);
	static FPD_CPWL_Wnd CastToWnd(FPD_CPWL_PushButton button);
	static FPD_CPWL_PushButton GetFromWnd(FPD_CPWL_Wnd wnd);
};

class CFPD_CPWLIcon_V17
{
public:
	static FPD_CPWL_Icon New();
	static void Delete(FPD_CPWL_Icon icon);
	static FS_INT32 GetScaleMethod(FPD_CPWL_Icon icon);
	static FS_BOOLEAN IsProportionalScale(FPD_CPWL_Icon icon);
	static void GetIconPosition(FPD_CPWL_Icon icon, FS_FLOAT* fLeft, FS_FLOAT* fBottom);
	static FS_BOOLEAN GetFittingBounds(FPD_CPWL_Icon icon);
	static void SetIconFit(FPD_CPWL_Icon icon, FPD_IconFit pIconFit);
	static FPD_CPWL_Image CastToImage(FPD_CPWL_Icon icon);
};

class CFPD_CPWLEditCtrl_V17
{
public:
	static FPD_CPWL_EditCtrl New();
	static void Delete(FPD_CPWL_EditCtrl ctrl);
	static FPD_CPWL_Wnd CastToWnd(FPD_CPWL_EditCtrl ctrl);
	static FS_INT32 GetCharSet(FPD_CPWL_EditCtrl ctrl);
	static FPD_CPWL_EditCtrl GetFromWnd(FPD_CPWL_Wnd wnd);	
	static FS_INT32 GetCaret(FPD_CPWL_EditCtrl ctrl);
	static void LoadCurrentWordProps(FPD_CPWL_EditCtrl ctrl, FPD_VTWordProps* wp, FS_INT32 nCharset);
	static FS_BOOLEAN IsCJK(FPD_CPWL_EditCtrl ctrl);
	static void GetCaretPos(FPD_CPWL_EditCtrl ctrl, FS_INT32* x, FS_INT32* y);
};

class CFPD_PluginSpellCheck : public window::IPWL_SpellCheck
{
public:
	CFPD_PluginSpellCheck(FPD_PWLSpellCheckCallbacks callbacks);
	virtual ~CFPD_PluginSpellCheck();
public:
	virtual FX_BOOL CheckWord(FX_LPCWSTR sWord);
	virtual void SuggestWords(FX_LPCWSTR sWord, CFX_WideStringArray& sSuggest);
	virtual FX_DWORD GetSCCodePage();
	virtual FX_BOOL IsSCAvalible();
	virtual FX_BOOL IsCurSCSupWord(FX_WCHAR sUnicode);

protected:
	FPD_PWLSpellCheckCallbacksRec m_callbacks;
};

class CFPD_SpellCheck_V17
{
public:
	//************************************
	// Function:  New
	// Param[in]: callback	The input FPD_PWLSpellCheckCallbacks object.
	// Return: FPD_SpellCheck
	// Remarks: Create FPD_SpellCheck object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FPD_SpellCheck New(FPD_PWLSpellCheckCallbacks callback);

	//************************************
	// Function:  Delete
	// Param[in]: spellcheck	The input <a>FPD_SpellCheck</a> object.
	// Return: void.
	// Remarks: Delete spellcheck object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void Delete(FPD_SpellCheck spellcheck);

	//************************************
	// Function:  CheckWord
	// Param[in]: spellCheck	The input <a>FPD_SpellCheck</a> object.
	// Param[in]: sWord			The input words to be checked.
	// Return: <a>TRUE</a> if the words are checked correctly, otherwise not.
	// Remarks: Checks whether the input words are correct or not.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static FS_BOOL CheckWord(FPD_SpellCheck spellCheck, FS_LPCWSTR sWord);

	//************************************
	// Function:  SuggestWords
	// Param[in]: spellCheck	The input <a>FPD_SpellCheck</a> object.
	// Param[in]: sWord			The input words.
	// Param[out]: outSuggest	It receives the suggested words.
	// Return: void
	// Remarks: Input the words to get its suggested words.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.0
	// See:
	//************************************
	static void	SuggestWords(FPD_SpellCheck spellCheck, FS_LPCWSTR sWord, FS_WideStringArray* outSuggest);

	//************************************
	// Function:  IsCurSCSupWord
	// Param[in]: spellCheck	The input <a>FPD_SpellCheck</a> object.
	// Param[in]: sUnicode		The input Unicode.
	// Return: FS_BOOLEAN   return <b>true</b> means success, while <b>false</b> means failure.
	// Remarks: brief According to the dictionary configuration that the current user chooses to do spell
	// check, whether characters should participate in spell check.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 11.0.0.0
	// See: FRSpellCheckNew
	//************************************
	static FS_BOOLEAN	IsCurSCSupWord(FPD_SpellCheck spellCheck, FS_WORD sUnicode);

	//************************************
	// Function:  IsSCAvalible
	// return <b>true</b> means success, while <b>false</b> means failure.
	// Remarks: Judge whether the user enables spell check.
	//************************************
	static FS_BOOLEAN	IsSCAvalible(FPD_SpellCheck spellCheck);
};

class CFPD_CPWLSignature_V17
{
public:
	static FPD_CPWL_Signature New();
	static void Delete(FPD_CPWL_Signature sig);
	static void SetIconText(FPD_CPWL_Signature sig, FS_LPCWSTR sText);
	static void SetDescription(FPD_CPWL_Signature sig, FS_LPCWSTR str);
	static void SetImage(FPD_CPWL_Signature sig, FS_DIBSource pImage);
	static void SetImageStream(FPD_CPWL_Signature sig, FPD_Object pStream, FS_LPCSTR sImageAlias, FS_BOOLEAN bKeepRatio);
	static void SetTextFlag(FPD_CPWL_Signature sig, FS_BOOLEAN bTextExist);
	static void SetImageFlag(FPD_CPWL_Signature sig, FS_BOOLEAN bImageExist);
	static void SetFoxitFlag(FPD_CPWL_Signature sig, FS_BOOLEAN bFlagExist);
	static void SetIconTextFontSize(FPD_CPWL_Signature sig, FS_FLOAT fFontSize);
	static void SetDescriptionFontSize(FPD_CPWL_Signature sig, FS_FLOAT fFontSize);
	static void SetIconTextColor(FPD_CPWL_Signature sig, FPD_ColorF color);
	static void SetDescriptionColor(FPD_CPWL_Signature sig, FPD_ColorF color);
	static FPD_CPWL_Wnd CastToWnd(FPD_CPWL_Signature sig);
	static FPD_CPWL_Signature GetFromWnd(FPD_CPWL_Wnd wnd);
};

#ifdef __cplusplus
};
#endif

#endif
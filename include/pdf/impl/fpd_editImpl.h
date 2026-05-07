#ifndef FPD_EDITIMPL_H
#define FPD_EDITIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../fpd_parserExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "../fpd_pageExpT.h"
#endif

#ifndef FPD_CONVERTEXPT_H
#include "../fpd_convertExpT.h"
#endif

#ifndef FPD_LREXPT_H
#include "../fpd_lrExpT.h"
#endif

#ifndef FPD_EDITEXPT_H
#include "../fpd_editExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif
	
	class CFPD_WordRange_V16
	{
	public:
		//CFVT_WordRange
		static FPD_VTWordRange New();
		static void Destroy(FPD_VTWordRange wordRange);
		static void SetDefault(FPD_VTWordRange wordRange);
		static void Set(FPD_VTWordRange wordRange, FPD_VTWordPlace begin, FPD_VTWordPlace end);
		static void SetBeginPos(FPD_VTWordRange wordRange, FPD_VTWordPlace begin);
		static void SetEndPos(FPD_VTWordRange wordRange, FPD_VTWordPlace end);
		static FS_BOOL IsExist(FPD_VTWordRange wordRange);
		static FS_BOOL Equal(FPD_VTWordRange wordRange, FPD_VTWordRange destWordRange);
		static void SwapWordPlace(FPD_VTWordRange wordRange);
		static FPD_VTWordPlace GetBeginPos(FPD_VTWordRange wordRange);
		static FPD_VTWordPlace GetEndPos(FPD_VTWordRange wordRange);
	};


	class CFPD_WordProps_V16
	{
	public:
		//CFVT_WordProps
		static FPD_VTWordProps New(FS_INT32	fontIndex, FS_FLOAT fontSize, FS_COLORREF wordColor, FS_INT32 scriptType, FS_INT32 wordStyle, FS_FLOAT charSpace, FS_FLOAT horzScale, FS_FLOAT xOffset, FS_FLOAT yOffset, FS_COLORREF strokeColor, FS_INT32 renderingMode, FS_FLOAT lineWidth, FS_FLOAT wordspace, FS_DWORD dwCharCode, short nAlphal);
		static FPD_VTWordProps NewII(FPD_VTWordProps otherWordProps);
		static void Destroy(FPD_VTWordProps wordProps);
		static void SetFontIndex(FPD_VTWordProps wordProps, FS_INT32 fontIndex);
		static FS_INT32 GetFontIndex(FPD_VTWordProps wordProps);
		static void SetFontSize(FPD_VTWordProps wordProps, FS_FLOAT fontSize);
		static FS_FLOAT GetFontSize(FPD_VTWordProps wordProps);
		static void SetWordColor(FPD_VTWordProps wordProps, FS_COLORREF wordColor);
		static FS_COLORREF GetWordColor(FPD_VTWordProps wordProps);
		static void SetStrokeColor(FPD_VTWordProps wordProps, FS_COLORREF dwStrokeColor);
		static FS_COLORREF GetStrokeColor(FPD_VTWordProps wordProps);
		static void SetScriptType(FPD_VTWordProps wordProps, FS_INT32 nScriptType);
		static FS_INT32 GetScriptType(FPD_VTWordProps wordProps);
		static void SetWordStyle(FPD_VTWordProps wordProps, FS_INT32 nWordStyle);
		static FS_INT32 GetWordStyle(FPD_VTWordProps wordProps);
		static void SetCharSpace(FPD_VTWordProps wordProps, FS_FLOAT fCharSpace);
		static FS_FLOAT GetCharSpace(FPD_VTWordProps wordProps);
		static void SetHorzScale(FPD_VTWordProps wordProps, FS_FLOAT fHorzScale);
		static FS_FLOAT GetHorzScale(FPD_VTWordProps wordProps);
		static void SetXOffset(FPD_VTWordProps wordProps, FS_FLOAT fXOffset);
		static FS_FLOAT GetXOffset(FPD_VTWordProps wordProps);
		static void SetYOffset(FPD_VTWordProps wordProps, FS_FLOAT fYOffset);
		static FS_FLOAT GetYOffset(FPD_VTWordProps wordProps);
		static void SetRenderingMode(FPD_VTWordProps wordProps, FS_INT32 nRenderingMode);
		static FS_INT32 GetRenderingMode(FPD_VTWordProps wordProps);
		static void SetClientData(FPD_VTWordProps wordProps, void* pClientData);
		static void* GetClientData(FPD_VTWordProps wordProps);
		static void SetLineWidth(FPD_VTWordProps wordProps, FS_FLOAT fLineWidth);
		static FS_FLOAT GetLineWidth(FPD_VTWordProps wordProps);
		static void SetWordSpace(FPD_VTWordProps wordProps, FS_FLOAT fWordSpace);
		static FS_FLOAT GetWordSpace(FPD_VTWordProps wordProps);
		static void SetCharCode(FPD_VTWordProps wordProps, FS_DWORD dwCharCode);
		static FS_DWORD GetCharCode(FPD_VTWordProps wordProps);
		static void SetAlpha(FPD_VTWordProps wordProps, short nAlpha);
		static short GetAlpha(FPD_VTWordProps wordProps);
	};

	class CFPD_Edit_V16 {
	public:
		//IFX_Edit	
		static FPD_Edit New();
		static void	Del(FPD_Edit edit);
		static void SetFontMap(FPD_Edit edit, FPD_Edit_FontMap fontMap, FS_INT32 nDefaultFontIndex);
		static void SetVTProvider(FPD_Edit edit, FPD_VariableText_Provider provider);
		static void* SetNotify(FPD_Edit edit, FPD_EditNotifyCallbacks callbacks);
		static void* SetOprNotify(FPD_Edit edit, FPD_EditOprNotifyCallbacks callbacks);
		static FPD_Edit_Iterator GetIterator(FPD_Edit edit);
		static FPD_VariableText GetVariableText(FPD_Edit edit);
		static FPD_Edit_FontMap GetFontMap(FPD_Edit edit);
		static void Initialize(FPD_Edit edit);
		static void SetPlateRect(FPD_Edit edit, FS_FloatRect rect, FS_BOOL bPaint, FS_BOOL bVerticalWriting);
		static void SetScrollPos(FPD_Edit edit, FS_FLOAT x, FS_FLOAT y);
		static FS_BOOL IsVerticalWriting(FPD_Edit edit);
		static void SetAlignmentH(FPD_Edit edit, FS_INT32 nFormat, FS_BOOL bPaint);
		static void SetAlignmentV(FPD_Edit edit, FS_INT32 nFormat, FS_BOOL bPaint);
		static void SetPasswordChar(FPD_Edit edit, FS_WORD wSubWord, FS_BOOL bPaint);
		static void SetLimitChar(FPD_Edit edit, FS_INT32 nLimitChar, FS_BOOL bPaint);
		static void SetCharArray(FPD_Edit edit, FS_INT32 nCharArray, FS_BOOL bPaint);
		static void SetCharSpace(FPD_Edit edit, FS_FLOAT fCharSpace, FS_BOOL bPaint);
		static void SetWordSpace(FPD_Edit edit, FS_FLOAT fWordSpace, FS_BOOL bPaint);
		static void SetHorzScale(FPD_Edit edit, FS_FLOAT fHorzScale, FS_BOOL bPaint);
		static void SetLineLeading(FPD_Edit edit, FS_FLOAT fLineLeading, FS_BOOL bPaint);
		static void SetMultiLine(FPD_Edit edit, FS_BOOL bMultiLine, FS_BOOL bPaint);
		static void SetAutoReturn(FPD_Edit edit, FS_BOOL bAuto, FS_BOOL bPaint);
		static void SetAutoFontSize(FPD_Edit edit, FS_BOOL bAuto, FS_BOOL bPaint);
		static void SetAutoScroll(FPD_Edit edit, FS_BOOL bAuto, FS_BOOL bPaint);
		static void SetFontSize(FPD_Edit edit, FS_FLOAT fFontSize, FS_BOOL bPaint);
		static void SetTextOverflow(FPD_Edit edit, FS_BOOL bAllowed, FS_BOOL bPaint);
		static void SetDirectionRTL(FPD_Edit edit, FS_BOOL bRTL, FS_BOOL bApplyAllSection, FS_BOOL bPaint);
		static FS_BOOL IsRichText(FPD_Edit edit);
		static void SetRichText(FPD_Edit edit, FS_BOOL bRichText, FS_BOOL bPaint);
		static FS_BOOL SetRichTextFont(FPD_Edit edit, FS_LPCSTR lpsFontName, FS_INT32 nFontIndex);
		static FS_BOOL SetRichTextIsBold(FPD_Edit edit, FS_BOOL bBold, FS_BOOL bNeedToReaderingMode);
		static FS_BOOL SetRichTextIsItalic(FPD_Edit edit, FS_BOOL bItalic);

		static FS_BOOL SetRichFontSize(FPD_Edit edit, FS_FLOAT fFontSize);
		static FS_BOOL SetRichTextColor(FPD_Edit edit, FS_COLORREF dwColor);
		static FS_BOOL SetRichTextStrokeColor(FPD_Edit edit, FS_COLORREF dwColor);
		static FS_BOOL SetRichRenderingMode(FPD_Edit edit, FS_INT32 nRenderingMode);
		static FS_BOOL SetRichTextScript(FPD_Edit edit, FS_INT32 nScriptType);
		static FS_BOOL SetRichTextUnderline(FPD_Edit edit, FS_BOOL bUnderline);
		static FS_BOOL SetRichTextCrossout(FPD_Edit edit, FS_BOOL bCrossout);
		static FS_BOOL SetRichTextCharSpace(FPD_Edit edit, FS_FLOAT fCharSpace);
		static FS_BOOL SetRichTextWordSpace(FPD_Edit edit, FS_FLOAT fWordSpace);
		static FS_BOOL SetRichTextHorzScale(FPD_Edit edit, FS_FLOAT fHorzScale);
		static FS_BOOL SetRichTextLineLeading(FPD_Edit edit, FS_FLOAT fLineLeading);
		static FS_BOOL SetRichTextLineIndent(FPD_Edit edit, FS_FLOAT fLineIndent);
		static FS_BOOL SetRichTextAlignment(FPD_Edit edit, FS_INT32 nAlignment);
		static FS_BOOL SetRichTextSoftReturn(FPD_Edit edit, FS_BOOL bEnable);
		static void SetSel(FPD_Edit edit, FS_INT32 nStartChar, FS_INT32 nEndChar);
		static void GetSel(FPD_Edit edit, FS_INT32* nStartChar, FS_INT32* nEndChar);
		static void SelectAll(FPD_Edit edit);
		static void SelectNone(FPD_Edit edit);
		static FS_INT32 GetCaret(FPD_Edit edit);
		static void GetCaretWordPlace(FPD_Edit edit, FPD_VTWordPlace* outWordPlace);
		static void GetSelText(FPD_Edit edit, FS_WideString* outText);
		static void GetText(FPD_Edit edit, FS_WideString* outText);
		static void GetRichTextXML(FPD_Edit edit, FS_LPCWSTR ds, FS_BOOL bSaveLineFeed, FS_WideString* outXML);
		static FS_BOOL IsSelected(FPD_Edit edit);
		static void GetScrollPos(FPD_Edit edit, FS_FLOAT* x, FS_FLOAT* y);
		static FS_FloatRect GetPlateRect(FPD_Edit edit);
		static FS_FloatRect GetContentRect(FPD_Edit edit);
		static void GetVisibleWordRange(FPD_Edit edit, FPD_VTWordRange* outWordRange);
		static void GetWholeWordRange(FPD_Edit edit, FPD_VTWordRange* outWordRange);
		static void GetSelectWordRange(FPD_Edit edit, FPD_VTWordRange* outWordRange);
		static void OnMouseDown(FPD_Edit edit, FS_FLOAT x, FS_FLOAT y, FS_BOOL bShift, FS_BOOL bCtrl);
		static void	OnMouseMove(FPD_Edit edit, FS_FLOAT x, FS_FLOAT y, FS_BOOL bShift, FS_BOOL bCtrl);
		static void OnVK_UP(FPD_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
		static void OnVK_DOWN(FPD_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
		static void OnVK_LEFT(FPD_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
		static void	OnVK_RIGHT(FPD_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
		static void OnVK_HOME(FPD_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
		static void OnVK_END(FPD_Edit edit, FS_BOOL bShift, FS_BOOL bCtrl);
		static void SetText(FPD_Edit edit, FS_LPCWSTR text, FS_INT32 charset, FPD_VTSecProps secProps, FPD_VTWordProps pWordProps);
		static void SetRichTextByXML(FPD_Edit edit, FS_LPCWSTR xml, FS_LPCWSTR ds, FS_INT32 charset);
		static FS_BOOL InsertWord(FPD_Edit edit, FS_WORD word, FS_INT32 charset, FPD_VTWordProps pWordProps, FS_BOOL bPaint, FS_BOOL bNeedTransform);
		static FS_BOOL InsertReturn(FPD_Edit edit, FPD_VTSecProps secProps, FPD_VTWordProps pWordProps, FS_BOOL bPaint);
		static FS_BOOL InsertText(FPD_Edit edit, FS_LPCWSTR text, FS_INT32 charset, FPD_VTSecProps secProps, FPD_VTWordProps pWordProps, FS_BOOL bPaint, FS_BOOL bNeedTransform);
		static FS_BOOL Backspace(FPD_Edit edit);
		static FS_BOOL Delete(FPD_Edit edit, FS_BOOL bCtrl);
		static FS_BOOL Clear(FPD_Edit edit);
		static FS_BOOL Redo(FPD_Edit edit);
		static FS_BOOL Undo(FPD_Edit edit);
		static void SetCaret(FPD_Edit edit, FS_INT32 nPos);
		static void Paint(FPD_Edit edit);
		static void EnableRefresh(FPD_Edit edit, FS_BOOL bRefresh);
		static void RefreshWordRange(FPD_Edit edit, FPD_VTWordRange wordRange);
		static void EnableUndo(FPD_Edit edit, FS_BOOL bUndo);
		static void	EnableNotify(FPD_Edit edit, FS_BOOL bNotify);
		static void EnableOprNotify(FPD_Edit edit, FS_BOOL bNotify);
		static FS_INT32 WordPlaceToWordIndex(FPD_Edit edit, FPD_VTWordPlace wordPlace);
		static void WordIndexToWordPlace(FPD_Edit edit, FS_INT32 index, FPD_VTWordPlace* outWordPlace);
		static void GetLineBeginPlace(FPD_Edit edit, FPD_VTWordPlace wordPlace, FPD_VTWordPlace* outWordPlace);
		static void GetLineEndPlace(FPD_Edit edit, FPD_VTWordPlace wordPlace, FPD_VTWordPlace* outWordPlace);
		static void GetSectionBeginPlace(FPD_Edit edit, FPD_VTWordPlace wordPlace, FPD_VTWordPlace* outWordPlace);
		static void GetSectionEndPlace(FPD_Edit edit, FPD_VTWordPlace wordPlace, FPD_VTWordPlace* outWordPlace);
		static void SearchWordPlace(FPD_Edit edit, FS_FLOAT x, FS_FLOAT y, FPD_VTWordPlace* outWordPlace);
		static FS_FLOAT GetFontSize(FPD_Edit edit);
		static FS_WORD GetPasswordChar(FPD_Edit edit);
		static FS_INT32 GetCharArray(FPD_Edit edit);
		static FS_FLOAT GetHorzScale(FPD_Edit edit);
		static FS_FLOAT GetCharSpace(FPD_Edit edit);
		static void GetRangeText(FPD_Edit edit, FPD_VTWordRange wordRange, FS_WideString* outText);
		static FS_BOOL IsTextFull(FPD_Edit edit);
		static FS_BOOL CanUndo(FPD_Edit edit);
		static FS_BOOL CanRedo(FPD_Edit edit);
		static void ResetUndo(FPD_Edit edit);
		static FS_BOOL IsModified(FPD_Edit edit);
		static FS_INT32 GetTotalWords(FPD_Edit edit);
		static void* AddUndoItem(FPD_Edit edit, FPD_EditUndoItemCallbacks callbacks);
		static void BeginGroupUndo(FPD_Edit edit, FS_LPCWSTR lpwsTitle);
		static void EndGroupUndo(FPD_Edit edit);
		static void SaveLineOffset(FPD_Edit edit);
		static void GetEditAppearanceStream(FPD_Edit edit, FS_FLOAT x, FS_FLOAT y, FPD_VTWordRange wordRange, FS_BOOL bContinuous, FS_WORD SubWord, FPD_EDITFONTArray* outFontDataArray, FS_ByteString* outStream);
		static void GetRichEditAppearanceStream(FPD_Edit edit, FS_FLOAT x, FS_FLOAT y, FPD_VTWordRange wordRange, FS_BOOL bContinuous, FS_WORD SubWord, FPD_EDITFONTArray* outFontDataArray, FS_ByteString* outStream, FS_ByteString pPathStream);
		static void GetSelectAppearanceStream(FPD_Edit edit, FS_FLOAT x, FS_FLOAT y, FPD_VTWordRange wordRange, FS_ByteString* outStream);
		static void DrawEdit(FPD_RenderDevice pDevice, FS_AffineMatrix user2Device, FPD_Edit edit, FS_ARGB crTextFill, FS_COLORREF crTextStroke, FS_FloatRect rcClip, FS_FLOAT x, FS_FLOAT y, FPD_VTWordRange wordRange);
		static void DrawUnderline(FPD_RenderDevice pDevice, FS_AffineMatrix user2Device, FPD_Edit edit, FS_COLORREF color, FS_FloatRect rcClip, FS_FLOAT x, FS_FLOAT y, FPD_VTWordRange wordRange);
		static void DrawRichEdit(FPD_RenderDevice pDevice, FS_AffineMatrix user2Device, FPD_Edit edit, FS_FloatRect rcClip, FS_FLOAT x, FS_FLOAT y, FPD_VTWordRange wordRange, FS_AffineMatrix text2Uer);
		static void GeneratePageObjects(void* pPageObjects, FPD_Edit edit, FS_FLOAT x, FS_FLOAT y, FPD_VTWordRange wordRange, FS_COLORREF crText, FS_PtrArray* outTextObjectArray);
		static void GenerateRichPageObjects(void* pPageObjects, FPD_Edit edit, FS_FLOAT x, FS_FLOAT y, FPD_VTWordRange wordRange, FS_PtrArray* outTextObjectArray, FS_POSITION* outPos, FS_PtrArray* outPathObjectArray);
		static void GenerateUnderlineObjects(void* pPageObjects, FPD_Edit edit, FS_FLOAT x, FS_FLOAT y, FPD_VTWordRange wordRange, FS_COLORREF color);
		static void GetRichTextPlainText(FS_LPCWSTR xml, FS_WideString* outText);
		static void  SetText2(FPD_Edit edit, FS_LPCWSTR text, FS_INT32 charset, FPD_VTSecProps secProps, FPD_VTWordProps pWordProps, FS_BOOLEAN bNeedEmbed);
		static FS_BOOL IsPunctuation(FS_DWORD word);
		static void EnableArtificialBold(FR_Edit edit, FS_BOOLEAN bNeedToReaderingMode);
		static void SetFillMode(FPD_Edit edit, FPD_FillMode_Value eVlaue);
		static void BeginOperBullet(FPD_Edit edit, FS_INT32 ntype);
		static FS_INT32 EndOperBullet(FPD_Edit edit, FS_BOOLEAN bPrint);
		static FPD_TextListItem GetBullet(FPD_Edit edit, FS_INT32 nSection);
		static FPD_Bullet_WordIterator GetBulletWordIterator(FPD_Edit edit, FPD_TextListItem pBullet);
		static void SetLineLeadingRatio(FPD_Edit edit, FS_FLOAT fLineLeadingratio, FS_BOOLEAN bPaint);
		static void GetRichTextXML2(FPD_Edit edit, FS_LPCWSTR ds, FS_BOOL bSaveLineFeed, FS_BOOLEAN bRichForm, FS_WideString* outXML);
		static FS_BOOLEAN DeleteTextList(FPD_Edit edit);
		static FS_BOOLEAN ModifyNumberedList(FPD_Edit edit, FPDEDIT_ListStyleDescriptor numberListStyle);	
		static FS_BOOLEAN  ModifyBulletedList(FPD_Edit edit, FS_WCHAR bullet);
	};

	class CFPD_EditFontMap_V16 {
	public:
		//IPWL_FontMap
		static FS_BOOL GetFontStyle(FPD_Edit_FontMap editFontMap, FS_INT32 nFontIndex, FS_DWORD* dwFontStyle, FS_INT32* nCharset);
		static FS_BOOL IsExternalEmbedFont(FPD_Edit_FontMap editFontMap, FS_INT32 nFontIndex);
		static FS_BOOL IsEmbedded(FPD_Edit_FontMap editFontMap, FS_INT32 nFontIndex);

		static FS_INT32 GetFontIndexByUnicode3(FPD_Edit_FontMap editFontMap, FS_WCHAR wUnicode, FS_LPCWSTR lpsDefaultFontName, FS_DWORD dwFontStyle, FS_INT32 nCharSet, FPDFMTribool bNeedEmbed, FS_BOOL bVertical);
		static FS_INT32 GetFontIndex3(FPD_Edit_FontMap editFontMap, FS_LPCWSTR lpsFontName, FS_INT32 nCharset, FS_DWORD dwFontStyle, FS_BOOL bAdd, FPDFMTribool bNeedEmbed, FS_BOOL bVertical);
		static FS_INT32 AddFXFont2(FPD_Edit_FontMap editFontMap, void* pFXFont, FS_LPCWSTR lpsFontName, FS_INT32 nCharset);
		static FS_INT32 AddPDFFont2(FPD_Edit_FontMap editFontMap, FPD_Font fpdFont, FS_LPCWSTR lpsFontName, FS_INT32 nCharset);
		static FS_INT32 LoadAllFontByDict(FPD_Edit_FontMap editFontMap, FPD_Object acroFormDict, FPD_Object annotDict, FS_LPCSTR lpsApType, FS_BOOLEAN* pIsDAFont);
		static FPD_Edit_FontMap Create(FPD_SystemHandler sysHandler, FPD_Document pDoc);
		static void Destroy(FPD_Edit_FontMap editFontMap);
		static void GetFontName(FPD_Edit_FontMap editFontMap, FS_UINT nFontIndex, FS_WideString* fontName);
		static FPD_FXFont GetFXFont(FPD_Edit_FontMap editFontMap, FS_UINT nFontIndex);
		static FS_INT32 GetCharset(FPD_Edit_FontMap editFontMap, FS_UINT nFontIndex);
		static void Initialize(FPD_Edit_FontMap editFontMap, FS_LPCSTR fontname);
		static FPD_Font GetPDFFont(FR_Edit_FontMap editFontMap, FS_INT32 nFontIndex, FS_DWordArray unicodeArray, FS_BOOL bEmbedFont);
		static void GetRealNameFromTagName(FR_Edit_FontMap editFontMap, FS_LPCSTR bsTagName, FS_ByteString* outTagName);
		static void GetSysDefaultFontName(FR_Edit_FontMap editFontMap, FS_WideString* fontname);
	};

	class CFPD_VTWord_V16 {
	public:
		static FPD_VTWord New();
		static void Destroy(FPD_VTWord word);
		static void SetWord(FPD_VTWord VTWord, FS_WORD word);
		static FS_WORD GetWord(FPD_VTWord word);
		static void SetWordDisplay(FPD_VTWord word, FS_WORD WordDisplay);
		static FS_WORD GetWordDisplay(FPD_VTWord word);
		static void SetBidiOrder(FPD_VTWord word, short nBidiOrder);
		static short GetBidiOrder(FPD_VTWord word);
		static void SetCharset(FPD_VTWord word, FS_INT32 nCharset);
		static FS_INT32 GetCharset(FPD_VTWord word);
		static void SetWordPlace(FPD_VTWord word, FPD_VTWordPlace WordPlace);
		static FPD_VTWordPlace GetWordPlace(FPD_VTWord word);
		static void SetWordPoint(FPD_VTWord word, FS_FLOAT x, FS_FLOAT y);
		static void GetWordPoint(FPD_VTWord word, FS_FLOAT* x, FS_FLOAT* y);
		static void SetAscent(FPD_VTWord word, FS_FLOAT fAscent);
		static FS_FLOAT GetAscent(FPD_VTWord word);
		static void SetDescent(FPD_VTWord word, FS_FLOAT fDescent);
		static FS_FLOAT GetDescent(FPD_VTWord word);
		static void SetWidth(FPD_VTWord word, FS_FLOAT fWidth);
		static FS_FLOAT GetWidth(FPD_VTWord word);
		static void SetFontIndex(FPD_VTWord word, FS_INT32 nFontIndex);
		static FS_INT32 GetFontIndex(FPD_VTWord word);
		static void SetFontSize(FPD_VTWord word, FS_FLOAT fFontSize);
		static FS_FLOAT GetFontSize(FPD_VTWord word);
		static void SetWordProps(FPD_VTWord word, FPD_VTWordProps wordProps);
		static FPD_VTWordProps GetWordProps(FPD_VTWord word);
	};

	class CFPD_PWLCREATEPARAM_V17
	{
	public:
		static FPD_PWLCREATEPARAM PWLWndCreationParamNew();
		static void            PWLWndCreationParamSetFontMap(FPD_PWLCREATEPARAM pCreationParam, FPD_Edit_FontMap fontMap);
		static void            PWLWndCreationParamSetFontIndex(FPD_PWLCREATEPARAM pCreationParam, FS_INT32 nFontIndex);
		static void            PWLWndCreationParamSetFlag(FPD_PWLCREATEPARAM pCreationParam, FS_DWORD dwFlags);
		static void            PWLWndCreationParamSetFontSize(FPD_PWLCREATEPARAM pCreationParam, FS_FLOAT fFontSize);
		static void            PWLWndCreationParamSetTextColor(FPD_PWLCREATEPARAM pCreationParam, FS_INT32 r, FS_INT32 g, FS_INT32 b);
		static void            PWLWndCreationParamSetTextColorII(FPD_PWLCREATEPARAM pCreationParam, FPD_ColorF color);
		static void            PWLWndCreationParamSetRect(FPD_PWLCREATEPARAM pCreationParam, FS_FloatRect rect);
		static void            PWLWndCreationParamDestroy(FPD_PWLCREATEPARAM pCreationParam);
		static void            PWLWndCreationParamSetSystemHandler(FPD_PWLCREATEPARAM pCreationParam, FS_LPVOID handler);
		static void            PWLWndCreationParamSetProvider(FPD_PWLCREATEPARAM pCreationParam, FPD_CPWL_Provider handler);
		static void            PWLWndCreationParamSetFocusHandler(FPD_PWLCREATEPARAM pCreationParam, FPD_CPWL_FocusHandler handler);
		static void            PWLWndCreationParamSetBackgroundColor(FPD_PWLCREATEPARAM pCreationParam, FPD_ColorF color);
		static void            PWLWndCreationParamSetAttachedWnd(FPD_PWLCREATEPARAM pCreationParam, FS_LPVOID wnd);
		static void			   PWLWndCreationParamSetSpellCheck(FPD_PWLCREATEPARAM pCreationParam, FPD_SpellCheck spellcheck);
		static void			   PWLWndCreationParamSetBorderStyle(FPD_PWLCREATEPARAM pCreationParam, FS_INT32 borderStyle);
		static void			   PWLWndCreationParamSetBorderWidth(FPD_PWLCREATEPARAM pCreationParam, FS_INT32 borderWidth);
		static void			   PWLWndCreationParamSetBorderColor(FPD_PWLCREATEPARAM pCreationParam, FPD_ColorF color);
		static void			   PWLWndCreationParamSetTextStrokeColor(FPD_PWLCREATEPARAM pCreationParam, FPD_ColorF color);
		static void            PWLWndCreationParamSetTransparency(FPD_PWLCREATEPARAM pCreationParam, FS_INT32 transparency);
		static void            PWLWndCreationParamSetUseFXFontDeAscent(FPD_PWLCREATEPARAM pCreationParam, FS_BOOL bUse);
		static void            PWLWndCreationParamSetDash(FPD_PWLCREATEPARAM pCreationParam, FPDCPWL_Dash dash);
		static void            PWLWndCreationParamSetAttachedData(FPD_PWLCREATEPARAM pCreationParam, FS_LPVOID data);
		static void            PWLWndCreationParamSetParentWnd(FPD_PWLCREATEPARAM pCreationParam, FPD_CPWL_Wnd wnd);
		static void            PWLWndCreationParamSetCursorType(FPD_PWLCREATEPARAM pCreationParam, FS_INT32 type);
		static void            PWLWndCreationParamSetMtChild(FPD_PWLCREATEPARAM pCreationParam, FS_AffineMatrix mt);
		static void            PWLWndCreationParamSetShowFontSizeDPI(FPD_PWLCREATEPARAM pCreationParam, FS_FLOAT dpi);
		static void            PWLWndCreationParamSetNeedEmbed(FPD_PWLCREATEPARAM pCreationParam, FS_BOOL bEmbed);
		static void            PWLWndCreationParamSetListBoxFontSize(FPD_PWLCREATEPARAM pCreationParam, FS_FLOAT fontsize); 
		static FS_DWORD        GetFlags(FPD_PWLCREATEPARAM pCreationParam);
		static FS_FloatRect    GetRect(FPD_PWLCREATEPARAM pCreationParam);
	};

	class CFPD_PWLFiller_Notify : public window::IPWL_Filler_Notify
	{
	public:
		CFPD_PWLFiller_Notify(FPD_PWLFillerNotifyCallbacks callbacks);
		virtual ~CFPD_PWLFiller_Notify();
	public:
		virtual void QueryWherePopup(void* pPrivateData,
			FX_FLOAT fPopupMin,
			FX_FLOAT fPopupMax,
			FX_INT32& nRet,
			FX_FLOAT& fPopupRet);	// nRet: (0:bottom 1:top)
		virtual int OnBeforeKeyStroke(FX_BOOL bEditOrList,
			void* pPrivateData,
			FX_INT32 nKeyCode,
			CFX_WideString& strChange,
			const CFX_WideString& strChangeEx,
			int nSelStart,
			int nSelEnd,
			FX_BOOL bKeyDown,
			FX_BOOL& bRC);
		virtual int OnAfterKeyStroke(FX_BOOL bEditOrList, void* pPrivateData);
		virtual int OnPopupPreOpen(void* pPrivateData);
		virtual int OnPopupPostOpen(void* pPrivateData);

	protected:
		FPD_PWLFillerNotifyCallbacksRec m_callbacks;
	};

	class CFPD_PWLEdit_Handler : public window::CPWL_Edit
	{
	public:
		CFPD_PWLEdit_Handler(FPD_PWLEditHandlerCallbacks callbacks);
		virtual ~CFPD_PWLEdit_Handler();
	public:
		virtual FX_BOOL OnRButtonUp(const CPDF_Point& point) override;
		virtual void LoadCurrentWordProps(edit::CFVT_WordProps& wp, FX_INT32 nCharset) override;
		virtual void InsertWord(FX_WCHAR wUnicode, FX_INT32 nCharset) override;
		virtual FX_BOOL AddExtendRightMenuItem(window::FX_HMENU hPopup) override;
		virtual FX_BOOL DoExtendRightMenuCommand(FX_INT32 cmd) override;
		virtual void IOnSetCaret(FX_BOOL bVisible, const CPDF_Point& ptHead,
			const CPDF_Point& ptFoot, const edit::CFVT_WordPlace& place) override;

		void IOnSetCaretInternal(FX_BOOL bVisible, const CPDF_Point& ptHead,
			const CPDF_Point& ptFoot, const edit::CFVT_WordPlace& place, FX_BOOL bBaseFun);

	protected:
		FPD_PWLEditHandlerCallbacksRec m_callbacks;
	};

	class CFPD_CPWLEdit_V17
	{
	public:
		static FPD_CPWL_Edit New(FPD_PWLCREATEPARAM pCreationParam);
		static void SetTextColor(FPD_CPWL_Edit pEdit, FS_INT32 r, FS_INT32 g, FS_INT32 b);
		static void SetTextColorII(FPD_CPWL_Edit pEdit, FPD_ColorF color);
		static void SetText(FPD_CPWL_Edit pEdit, FS_LPCWSTR csText);
		static void GetContentRect(FPD_CPWL_Edit pEdit, FS_FloatRect* pRect);
		static void GeneratePageObjects(FPD_CPWL_Edit pEdit, void* pPageObjects, FS_FLOAT xx, FS_FLOAT yy, FS_PtrArray* outObjArray);
		static void GeneratePageObjectsII(FPD_CPWL_Edit pEdit, void* pPageObjects, FS_FLOAT xx, FS_FLOAT yy);
		static void Destroy(FPD_CPWL_Edit pEdit);
		static void EnableRefresh(FPD_CPWL_Edit pEdit, FS_BOOLEAN bRefresh);
		static void SetAlignFormatH(FPD_CPWL_Edit pEdit, FPDPWL_EDIT_ALIGNFORMAT_H nFormat, FS_BOOLEAN bPaint);
		static void SetAlignFormatV(FPD_CPWL_Edit pEdit, FPDPWL_EDIT_ALIGNFORMAT_V nFormat, FS_BOOLEAN bPaint);
		static void SetHorzScale(FPD_CPWL_Edit pEdit, FS_FLOAT fHorzScale, FS_BOOLEAN bPaint);
		static void SetCharSpace(FPD_CPWL_Edit pEdit, FS_FLOAT fCharSpace, FS_BOOLEAN bPaint);
		static void SetLineLeading(FPD_CPWL_Edit pEdit, FS_FLOAT fLineLeading, FS_BOOLEAN bPaint);
		static FPD_Edit GetEdit(FPD_CPWL_Edit pEdit);
		static void GetTextAppearanceStream(FPD_CPWL_Edit pEdit, FS_FloatPoint ptOffset, FPD_EDITFONTArray* outFontDataArray, FS_BOOLEAN bEmbedded,
			FS_ByteString* pFontReference, FS_ByteString* outStream);
		static FPD_Edit GetFXEdit(FPD_CPWL_Edit pEdit);
		static void ChangeApplyAllSection(FPD_CPWL_Edit pEdit, FS_BOOLEAN bAppleyAllSection);
		static void SetRichText(FPD_CPWL_Edit pEdit, FS_LPCWSTR xml, FS_LPCWSTR ds, FS_BOOLEAN bAutoSetAgin, FS_BOOLEAN bSimulateBold);
		static FPD_CPWL_Wnd GetCPWLWnd(FPD_CPWL_Edit pEdit);
		static void Redo(FPD_CPWL_Edit pEdit);
		static void Undo(FPD_CPWL_Edit pEdit);
		static FS_BOOLEAN CanSelectAll(FPD_CPWL_Edit pEdit);
		static FS_BOOLEAN CanClear(FPD_CPWL_Edit pEdit);
		static FS_BOOLEAN CanCopy(FPD_CPWL_Edit pEdit);
		static FS_BOOLEAN CanCut(FPD_CPWL_Edit pEdit);
		static void CopyText(FPD_CPWL_Edit pEdit);
		static void PasteText(FPD_CPWL_Edit pEdit);
		static void CutText(FPD_CPWL_Edit pEdit);
		static FS_BOOLEAN CanPaste(FPD_CPWL_Edit pEdit);
		static void GetTextWithBullet(FPD_CPWL_Edit pEdit, FS_WideString* outText);
		static FPD_PWLEdit_Notify CreateNotify(FPD_PWLEditNotifyCallbacks callbacks);
		static void DeleteNotify(FPD_PWLEdit_Notify notify);
		static void SetEditNotify(FPD_CPWL_Edit pEdit, FPD_PWLEdit_Notify notify);		
		static void SetFillerNotify(FPD_CPWL_Edit pEdit, FPD_PWLFillerNotify notify);
		static void ReplaceSel(FPD_CPWL_Edit pEdit, FS_LPCWSTR csText);
		static FPD_CPWL_Edit New2(FPD_PWLEditHandlerCallbacks callbacks);
		static FPD_CPWL_Edit GetFromWnd(FPD_CPWL_Wnd wnd);
		static FS_BOOLEAN SetRichTextIsBold(FPD_CPWL_Edit pEdit, FS_BOOLEAN bBold);
		static FS_BOOLEAN SetRichTextIsItalic(FPD_CPWL_Edit pEdit, FS_BOOLEAN bItalic);
		static FS_BOOLEAN SetRichTextUnderline(FPD_CPWL_Edit pEdit, FS_BOOLEAN bUnderline);
		static FS_BOOLEAN SetRichTextScript(FPD_CPWL_Edit pEdit, FS_INT32 nScriptType);
		static FPD_CPWL_EditCtrl CastToEditCtrl(FPD_CPWL_Edit pEdit);
		static void IOnSetCaret(FPD_CPWL_Edit pEdit, FS_BOOLEAN bVisible, FS_FloatPoint ptHead,
			FS_FloatPoint ptFoot, FPD_VTWordPlace* place, FS_BOOLEAN bBaseFun);
		static void SetCharSet(FPD_CPWL_Edit pEdit, FS_BYTE nCharSet);
		static FS_INT32 GetCharSet(FPD_CPWL_Edit pEdit);
		static void SetCodePage(FPD_CPWL_Edit pEdit, FS_INT32 nCodePage);
		static void SetInputText(FPD_CPWL_Edit pEdit, FS_LPCWSTR swText);
		static FS_AffineMatrix GetWindowMatrix(FPD_CPWL_Edit pEdit);
		static void GetCaretPos(FPD_CPWL_Edit pEdit, FS_INT32* x, FS_INT32* y);
		static FS_FLOAT GetCaretFontSize(FPD_CPWL_Edit pEdit);
		static FS_BOOLEAN IsTextFull(FPD_CPWL_Edit pEdit);
		static void SetFontSize(FPD_CPWL_Edit pEdit, FS_FLOAT fFontSize);
		static FS_FLOAT GetFontSize(FPD_CPWL_Edit pEdit);
		static FS_BOOLEAN OnChar(FPD_CPWL_Edit pEdit, FS_DWORD nChar);
		static FS_BOOLEAN SetRichTextColor(FPD_CPWL_Edit pEdit, FS_COLORREF dwColor);
		static void SetCaretColor(FPD_CPWL_Edit pEdit, const FS_ARGB color);
		static void GetText(FPD_CPWL_Edit pEdit, FS_WideString* wsText);
		static void GetRichTextXML(FPD_CPWL_Edit pEdit, FS_LPCWSTR ds, FS_BOOLEAN bSaveLineFeed, FS_BOOLEAN bRichForm, FS_WideString* outText);
		static FS_BOOLEAN CanUndo(FPD_CPWL_Edit pEdit);
		static FS_BOOLEAN CanRedo(FPD_CPWL_Edit pEdit);
		static void  SelectAll(FPD_CPWL_Edit pEdit);
		static FS_BOOLEAN SetRichTextAlignment(FPD_CPWL_Edit pEdit, FS_INT32 nAlignment);
		static FS_BOOLEAN OnLButtonDown(FPD_CPWL_Edit pEdit, FS_FloatPoint point);
		static FS_BOOLEAN OnLButtonDblClk(FPD_CPWL_Edit pEdit, FS_FloatPoint point);
		static FS_BOOLEAN OnRButtonUp(FPD_CPWL_Edit pEdit, FS_FloatPoint point);
		static FS_BOOLEAN OnKeyDown(FPD_CPWL_Edit pEdit, FS_DWORD nChar);
		static FS_BOOLEAN OnMouseMove(FPD_CPWL_Edit pEdit, FS_FloatPoint point);
		static FS_BOOLEAN OnLButtonUp(FPD_CPWL_Edit pEdit, FS_FloatPoint point);
	};

	class CFPD_VariableTextIterator_V17
	{
	public:
		static FS_BOOL NextWord(FPD_VariableText_Iterator iterator);
		static FS_BOOL PrevWord(FPD_VariableText_Iterator iterator);
		static FS_BOOL NextLine(FPD_VariableText_Iterator iterator);
		static FS_BOOL PrevLine(FPD_VariableText_Iterator iterator);
		static FS_BOOL NextSection(FPD_VariableText_Iterator iterator);
		static FS_BOOL PrevSection(FPD_VariableText_Iterator iterator);
		static FS_BOOL GetWord(FPD_VariableText_Iterator iterator, FPD_VTWord* outWord);
		static FS_BOOL SetWord(FPD_VariableText_Iterator iterator, FPD_VTWord word);
		static FS_BOOL GetLine(FPD_VariableText_Iterator iterator, FPD_VTLine* outLine);
		static FS_BOOL GetSection(FPD_VariableText_Iterator iterator, FPD_VTSection* outSection);
		static FS_BOOL SetSection(FPD_VariableText_Iterator iterator, FPD_VTSection section);
		static void SetAt(FPD_VariableText_Iterator iterator, FS_INT32 nWordIndex);
		static void SetAtII(FPD_VariableText_Iterator iterator, FPD_VTWordPlace place);
		static void GetAt(FPD_VariableText_Iterator iterator, FPD_VTWordPlace* outWordPlace);
		static FS_BOOL GetDisplayWord(FPD_VariableText_Iterator iterator, FPD_VTWord* outWord);
	};

	class CFPD_VTLine_V17
	{
	public:
		static FPD_VTLine New();
		static void Destroy(FPD_VTLine line);
		static void SetStartWordPlace(FPD_VTLine line, FPD_VTWordPlace lineplace);
		static FPD_VTWordPlace GetStartWordPlace(FPD_VTLine line);
		static void  SetEndWordPlace(FPD_VTLine line, FPD_VTWordPlace lineEnd);
		static FPD_VTWordPlace GetEndWordPlace(FPD_VTLine line);
		static void  SetOriginalPosition(FPD_VTLine line, FS_FLOAT x, FS_FLOAT y);
		static void  GetOriginalPosition(FPD_VTLine line, FS_FLOAT* x, FS_FLOAT* y);
		static void  SetWidth(FPD_VTLine line, FS_FLOAT fLineWidth);
		static FS_FLOAT  GetWidth(FPD_VTLine line);
		static void  SetAscent(FPD_VTLine line, FS_FLOAT fLineAscent);
		static FS_FLOAT  GetAscent(FPD_VTLine line);
		static void  SetDescent(FPD_VTLine line, FS_FLOAT fLineDescent);
		static FS_FLOAT  GetDescent(FPD_VTLine line);
	};

	class CFPD_VTSection_V17
	{
	public:
		static FPD_VTSection New();
		static void Destroy(FPD_VTSection section);
		static void SetStartWordPlace(FPD_VTSection section, FPD_VTWordPlace secplace);
		static FPD_VTWordPlace GetStartWordPlace(FPD_VTSection section);
		static void SetRect(FPD_VTSection section, FS_FloatRect rect);
		static FS_FloatRect GetRect(FPD_VTSection section);
		static void SetSectionProperties(FPD_VTSection section, FPD_VTSecProps SecProps);
		static FPD_VTSecProps GetSectionProperties(FPD_VTSection section);
		static void SetWordProperties(FPD_VTSection section, FPD_VTSecProps WordProps);
		static FPD_VTWordProps GetWordProperties(FPD_VTSection section);
	};

	class CFPD_VariableText_V17
	{
	public:
		static FPD_VariableText New();
		static void	Destroy(FPD_VariableText variableText);
		static FPD_VariableText_Provider  ProviderNew(FPD_VariableTextProviderCallbacks callbacks);
		static void ProviderDestroy(FPD_VariableText_Provider provider);
		static FPD_VariableText_Provider SetProvider(FPD_VariableText variableText, FPD_VariableText_Provider provider);
		static FPD_VariableText_Iterator GetIterator(FPD_VariableText variableText);
		static void SetPlateRect(FPD_VariableText variableText, FS_FloatRect rect, FS_BOOL bVerticalWriting);
		static FS_BOOL IsVerticalWriting(FPD_VariableText variableText);
		static void SetAlignment(FPD_VariableText variableText, FS_INT32 nFormat);
		static void SetPasswordChar(FPD_VariableText variableText, FS_WORD wSubWord);
		static void SetLimitChar(FPD_VariableText variableText, FS_INT32 nLimitChar);
		static void SetCharArray(FPD_VariableText variableText, FS_INT32 nCharArray);
		static void SetCharSpace(FPD_VariableText variableText, FS_FLOAT fCharSpace);
		static void SetWordSpace(FPD_VariableText variableText, FS_FLOAT fWordSpace);
		static void SetHorzScale(FPD_VariableText variableText, FS_FLOAT fHorzScale);
		static void SetMultiLine(FPD_VariableText variableText, FS_BOOL bMultiLine);
		static void SetAutoReturn(FPD_VariableText variableText, FS_BOOL bAuto);
		static void SetAutoFontSize(FPD_VariableText variableText, FS_BOOL bAuto);
		static void SetFontSize(FPD_VariableText variableText, FS_FLOAT fFontSize);
		static void SetLineLeading(FPD_VariableText variableText, FS_FLOAT fLineLeading);
		static void SetRichText(FPD_VariableText variableText, FS_BOOL bRichText);
		static void SetDirectionRTL(FPD_VariableText variableText, FS_BOOL bRTL, FR_VTWordRange PlaceRange);
		static void Initialize(FPD_VariableText variableText);
		static FS_BOOL IsValid(FPD_VariableText variableText);
		static FS_BOOL IsRichText(FPD_VariableText variableText);
		static void RearrangeAll(FPD_VariableText variableText);
		static void RearrangePart(FPD_VariableText variableText, FR_VTWordRange PlaceRange);
		static void ResetAll(FPD_VariableText variableText);
		static void SetText(FPD_VariableText variableText, FS_LPCWSTR text, FS_INT32 charset, FPD_VTSecProps pSecProps, FPD_VTWordProps pWordProps);
		static void InsertWord(FPD_VariableText variableText, FPD_VTWordPlace place, FS_WORD word, FS_INT32 charset, FPD_VTWordProps pWordProps, FS_BOOL bNeedTransform, FPD_VTWordPlace* outPlace);
		static void InsertSection(FPD_VariableText variableText, FPD_VTWordPlace place, FPD_VTSecProps pSecProps, FPD_VTWordProps pWordProps, FPD_VTWordPlace* outPlace);
		static void InsertText(FPD_VariableText variableText, FPD_VTWordPlace place, FS_LPCWSTR text, FS_INT32 charset, FPD_VTSecProps pSecProps, FPD_VTWordProps pWordProps, FPD_VTWordPlace* outPlace);
		static void DeleteWords(FPD_VariableText variableText, FPD_VTWordRange PlaceRange, FPD_VTWordPlace* outPlace);
		static void DeleteWord(FPD_VariableText variableText, FPD_VTWordPlace place, FPD_VTWordPlace* outPlace);
		static void BackSpaceWord(FPD_VariableText variableText, FPD_VTWordPlace place, FPD_VTWordPlace* outPlace);
		static FS_FloatRect GetPlateRect(FPD_VariableText variableText);
		static FS_FloatRect GetContentRect(FPD_VariableText variableText);
		static FS_INT32 GetTotalWords(FPD_VariableText variableText);
		static FS_FLOAT GetFontSize(FPD_VariableText variableText);
		static FS_INT32 GetAlignment(FPD_VariableText variableText);
		static FS_FLOAT GetWordSpace(FPD_VariableText variableText);
		static FS_WORD GetPasswordChar(FPD_VariableText variableText);
		static FS_INT32 GetCharArray(FPD_VariableText variableText);
		static FS_INT32 GetLimitChar(FPD_VariableText variableText);
		static FS_BOOL IsMultiLine(FPD_VariableText variableText);
		static FS_BOOL IsAutoReturn(FPD_VariableText variableText);
		static FS_FLOAT GetHorzScale(FPD_VariableText variableText);
		static FS_FLOAT GetCharSpace(FPD_VariableText variableText);
		static void GetBeginWordPlace(FPD_VariableText variableText, FPD_VTWordPlace* outPlace);
		static void GetEndWordPlace(FPD_VariableText variableText, FPD_VTWordPlace* outPlace);
		static void GetPrevWordPlace(FPD_VariableText variableText, FPD_VTWordPlace place, FPD_VTWordPlace* outPlace);
		static void GetNextWordPlace(FPD_VariableText variableText, FPD_VTWordPlace place, FPD_VTWordPlace* outPlace);
		static void SearchWordPlace(FPD_VariableText variableText, FS_FLOAT x, FS_FLOAT y, FPD_VTWordPlace* outPlace);
		static void GetUpWordPlace(FPD_VariableText variableText, FPD_VTWordPlace place, FS_FLOAT x, FS_FLOAT y, FPD_VTWordPlace* outPlace);
		static void GetDownWordPlace(FPD_VariableText variableText, FPD_VTWordPlace place, FS_FLOAT x, FS_FLOAT y, FPD_VTWordPlace* outPlace);
		static void GetLineBeginPlace(FPD_VariableText variableText, FPD_VTWordPlace place, FPD_VTWordPlace* outPlace);
		static void GetLineEndPlace(FPD_VariableText variableText, FPD_VTWordPlace place, FPD_VTWordPlace* outPlace);
		static void GetSectionBeginPlace(FPD_VariableText variableText, FPD_VTWordPlace place, FPD_VTWordPlace* outPlace);
		static void GetSectionEndPlace(FPD_VariableText variableText, FPD_VTWordPlace place, FPD_VTWordPlace* outPlace);
		static void UpdateWordPlace(FPD_VariableText variableText, FPD_VTWordPlace place);
		static void AjustLineHeader(FPD_VariableText variableText, FPD_VTWordPlace place, FS_BOOL bPrevOrNext, FPD_VTWordPlace* outPlace);
		static FS_INT32 WordPlaceToWordIndex(FPD_VariableText variableText, FPD_VTWordPlace place);
		static void WordIndexToWordPlace(FPD_VariableText variableText, FS_INT32 index, FPD_VTWordPlace* outPlace);
		static FS_BOOL IsSectionComplexScript(FPD_VariableText variableText, FPD_VTWordPlace place);
		static FS_BOOL IsVerticalFont(FPD_VariableText variableText, FS_INT32 nFontindex);
	};

	class CFPD_EDITFontData_V17
	{
	public:
		static FPD_EDIT_FontData New();
		static void Destroy(FPD_EDIT_FontData fontdata);
		static void SetFont(FPD_EDIT_FontData fontdata, FPD_Font font);
		static FPD_Font GetFont(FPD_EDIT_FontData fontdata);
		static void SetFontName(FPD_EDIT_FontData fontdata, FS_LPCSTR fontName);
		static void GetFontName(FPD_EDIT_FontData fontdata, FS_ByteString* outFontName);
	};

	class CFPD_BulletWordIterator_V17
	{
	public:
		static void SetBeginBulletWordPos(FPD_Bullet_WordIterator wordIterator, FS_INT32 nWordIndex);
		static FS_BOOLEAN NextBulletWord(FPD_Bullet_WordIterator wordIterator);
		static FS_BOOLEAN GetBulletWord(FPD_Bullet_WordIterator wordIterator, FPD_VTWord* outword);
		static void SetBulletWord(FPD_Bullet_WordIterator wordIterator, const FPD_VTWord word);
		static FS_BOOLEAN GetBulletDisplayWord(FPD_Bullet_WordIterator wordIterator, FPD_VTWord* outword);
		static FS_INT32 GetBeginBulletWordPos(FPD_Bullet_WordIterator wordIterator);
	};

	class CFPD_VTWordPlace_V17
	{
	public:
		static FPD_VTWordPlace New(FS_INT32 nSecIndex, FS_INT32 nLineIndex, FS_INT32 nWordIndex);
		static void Destroy(FPD_VTWordPlace wordPlace);
		static void SetDefault(FPD_VTWordPlace wordPlace);
		static FS_BOOL Equal(FPD_VTWordPlace wordPlace, FPD_VTWordPlace destWordPlace);
		static FS_INT32 WordCmp(FPD_VTWordPlace wordPlace, FPD_VTWordPlace destWordPlace);
		static FS_INT32 LineCmp(FPD_VTWordPlace wordPlace, FPD_VTWordPlace destWordPlace);
		static FS_INT32 SecCmp(FPD_VTWordPlace wordPlace, FPD_VTWordPlace destWordPlace);
		static void SetSectionIndex(FPD_VTWordPlace wordPlace, FS_INT32 nSecIndex);
		static FS_INT32 GetSectionIndex(FPD_VTWordPlace wordPlace);
		static void SetLineIndex(FPD_VTWordPlace wordPlace, FS_INT32 nLineIndex);
		static FS_INT32 GetLineIndex(FPD_VTWordPlace wordPlace);
		static void SetWordIndex(FPD_VTWordPlace wordPlace, FS_INT32 nWordIndex);
		static FS_INT32 GetWordIndex(FPD_VTWordPlace wordPlace);
	};


	class CFPD_EDITFONTDATAArray_V17
	{
	public:
		//************************************
		// Function:  Create		
		// Return:    FPD_EDITFONTArray
		// Remarks:  Create FPD_EDITFONTArray obj.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static FPD_EDITFONTArray Create();

		//************************************
		// Function:  Delete	
		// Param[in]: fontArr		    The input FPD_EDITFONTArray object.		
		// Return:    void
		// Remarks:  Delete FPD_EDITFONTArray obj.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void Delete(FPD_EDITFONTArray fontArr);

		//************************************
		// Function:  GetSize	
		// Param[in]: fontArr		    The input FPD_EDITFONTArray object.		
		// Return:    FS_INT32         The size in objects in the array.
		// Remarks:  Get the size of the array.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static FS_INT32   GetSize(FPD_EDITFONTArray fontArr);

		//************************************
		// Function:  GetData	
		// Param[in]: fontArr		      The input FPD_EDITFONTArray object.		
		// Param[in]: index		      Specifies the zero-based index of element in the array.
		// Return:    FPD_EDIT_FontData  A pointer to the specified element.
		// Remarks:  Get a pointer to the specified element in the array. Direct pointer access.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static FPD_EDIT_FontData GetData(FPD_EDITFONTArray fontArr, FS_INT32 index);

		//************************************
		// Function:  RemoveAt	
		// Param[in]: fontArr		    The input FPD_EDITFONTArray object.		
		// Param[in]: index		    Specifies the zero-based index of object in the array.
		// Return:    void
		// Remarks:  Remove an object at specified position.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void      RemoveAt(FPD_EDITFONTArray fontArr, FS_INT32 index);

		//************************************
		// Function:  RemoveAll	
		// Param[in]: fontArr		    The input FPD_EDITFONTArray object.
		// Return:    void
		// Remarks:  Remove all objects in the array.
		// Notes:
		// Since: <a>SDK_LATEEST_VERSION</a> > 13.0.0.0
		//************************************
		static void      RemoveAll(FPD_EDITFONTArray fontArr);
	};
	
	class CFPD_VTBulletIterator_V17
	{
	public:
		static FS_BOOLEAN NextBullet(FPD_VTBulletIterator iterator);
		static FPD_TextList GetBullet(FPD_VTBulletIterator iterator);
		static void SetBeginnIndex(FPD_VTBulletIterator iterator, FS_INT32 nIndex);
		static FS_INT32 GetCurIndex(FPD_VTBulletIterator iterator);
	};

	class CFPD_TextList_V17
	{
	public:
		static FPD_TextListItem GetChildItem(FPD_TextList textList);
		static void ReCalculateLableWidth(FPD_TextList textList, FPD_TextListItem pListItem);
		static FPD_TextListItem GetNextSiblingItem(FPD_TextList textList, FPD_TextListItem pItem);
	};

	class CFPD_PWLFillerNotify_V17
	{
	public:
		static FPD_PWLFillerNotify Create(FPD_PWLFillerNotifyCallbacks callbacks);
		static void Delete(FPD_PWLFillerNotify notify);
	};	

	class CFPD_List_V17
	{
	public:
		static void SetDirectionRTL(FPD_List list, FS_BOOLEAN bRTL, FS_BOOLEAN bApplyAllSection, FS_BOOLEAN bPaint, FS_BOOLEAN bAddUndo);
		static void SetAlignment(FPD_List list, FS_INT32 nAlignment);
		static FS_INT32 GetAlignment(FPD_List list);
	};

#ifdef __cplusplus
};
#endif

#endif
/** @file fr_appImpl.h.
 * 
 *  @brief defined all interface associate with Foxit Reader user interface .
 */

#ifndef FR_APPIMPL_FXNET_H
#define FR_APPIMPL_FXNET_H

#ifndef FR_APPEXPT_H
#include "../fr_appExpT.h"
#endif
#ifndef FR_APPEXPTFXNET_H
#include "../fr_fxnetappExpT.h"
#endif

class IReader_Document;
class IReader_App;

#ifdef __cplusplus
extern "C"{
#endif
class CFR_AppFxNet_V11
{
public:
	//************************************
	// Function:  RegisterAppEventHandler
	// Param[in]: appEventCallbacks		The callback set. Reader will call a corresponding callback when the app event occurs.
	// Return:	<a>TRUE</a> for success, otherwise not.
	// Remarks: Registers a user-supplied procedure set to call when some application level event occurs.
	// Notes:
	//************************************
	static FS_BOOL			RegisterAppEventHandlerFxNet(FR_AppEventFxNetCallbacks appEventFxNetCallbacks);
};
class CFR_InternalFxNet_V11
{
public:
	//IFreshCustom.h
	static FS_BOOL                     IsFRDGLogin();
	static void                        ShowLoginDlg();
	static FS_BOOL					   DllGetTicket(FS_CHAR* cTicket, FS_INT32 len);
	static FS_BOOL					CheckActionPermission(FS_LPWSTR wsAction);
	static FS_LPSTR			        CheckPRDTimestampPermission(FS_LPSTR bsFileHash);
	static FS_BOOL					CheckPermissionByFaceName(FS_LPWSTR cwFontName);//通过字体名进行鉴权
	static HWND					    GetLoginHwnd();//获取登陆框句柄
	static FS_BOOL                  PreTranMsgToSdk(MSG* pMsg); //传递消息给SDK
	static FS_BOOL					DllShowPaymentDlg(wchar_t *param);
	//#13564-BEGIN-FXNET-HCM 翻译插件需求支撑
	static FS_BOOL					GetUserId(char* userId, int len);
	static FS_BOOL					GetNickName(char* userName, int len);
	static FS_BOOL					GetHeadIcon(char* headIcon, int len);
	static int						GetUserType();
	//#13564-END-FXNET-HCM 翻译插件需求支撑
	static FS_BOOL					AddAnnotToMarkupPanel(FPD_Object annotDict, FS_INT32 nPage, FS_BOOL bRedrawPanel, FS_BOOL bExpand, FPD_Document pDoc, FS_BOOL bShow);
	
//#ifdef FXNET_FPM_PER
	//#28161-FXNET-WZM 新增ocr识别功能做为福昕会员的特权功能
	static void						ShowAnnotNote(FR_Annot annot, BOOL bShow);
	static FPD_PageObject			GetCurrentImageSelectObj(FR_Document doc, FR_PageView& inOutPageview);	
	static FS_BOOL					OCRExtractText(FR_PageView pageview, FPD_PageObject imgObj, FS_WideString* wsText);
	static void						GetOCRLanInfo(FS_PtrArray* outObjArray);
	static FS_BOOL					GetImageBuf(FR_PageView pageview, FPD_PageObject imgObj, FS_LPBYTE& buf, FS_UINT& size);
	//#28161-FXNET-WZM 新增ocr识别功能做为福昕会员的特权功能
//#endif // FXNET_FPM_PER

};


#ifdef __cplusplus
};
#endif

#endif

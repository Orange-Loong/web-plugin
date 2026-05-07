#ifndef FRMS_IMPL_H
#define FRMS_IMPL_H

#ifdef __cplusplus
extern "C"{
#endif//__cplusplus

class CFRMS_Template_V2
{
public:
	static FRMS_Template	New(FS_LPWSTR wsTemplateFile);
	static FRMS_Template    New2(FS_LPWSTR wsName, UINT lcid, FS_LPWSTR wsDescription);
	static void				Release(FRMS_Template tmplt);
	static FS_BOOL			Save(FRMS_Template tmplt, FS_LPWSTR wsTemplateFile);
	
	static FS_BOOL			IsOfficial(FRMS_Template tmplt);
	static void				GetContentGUID(FRMS_Template tmplt, FS_WideString* wsGUID);
	static void				GetFilePath(FRMS_Template tmplt, FS_WideString* wsFilwPath);
	
	static FS_INT32			CountUsers(FRMS_Template tmplt);
	static void				GetUser(FRMS_Template tmplt, FS_INT32 index, FS_WideString* wsUserEmail);
	static FS_BOOL			AddUserWithEmail(FRMS_Template tmplt, FS_LPWSTR wsUserEmail);	
	static FS_BOOL			RemoveUser(FRMS_Template tmplt, FS_LPWSTR wsUserName);
	static FS_INT32         CountRights(FRMS_Template tmplt, FS_LPWSTR wsUserEmail);
	static FS_BOOL			AddRight(FRMS_Template tmplt, FS_LPWSTR wsUserEmail, FS_LPWSTR pwszRight);
	static FS_BOOL          GetRight(FRMS_Template tmplt, FS_LPWSTR wsUserEmail, FS_INT32 index, FS_WideString* wsRight);
	static FS_BOOL			RemoveRight(FRMS_Template tmplt, FS_LPWSTR wsUserEmail, FS_LPWSTR pwszRight);
	
	static FS_INT32			CountTemplateIDs(FRMS_Template tmplt);
	static FS_BOOL			GetTemplateID(FRMS_Template tmplt, FS_INT32 index, FS_WideString* wsName, LCID* lcid, FS_WideString* wsDescription);
	static FS_BOOL			AddTemplateID(FRMS_Template tmplt, FS_LPWSTR wsName, LCID lcid, FS_LPWSTR wsDescription);
	static FS_BOOL			RemoveTemplateID(FRMS_Template tmplt, FS_INT32 index);	
	
	static FS_BOOL			GetContentExpiration(FRMS_Template tmplt, FS_INT32* uDays);
	static FS_BOOL			GetContentExpirationDate(FRMS_Template tmplt, FS_WideString* wsFrom, FS_WideString* wsUntil);
	
	static FS_BOOL			GetLicenseExpiration(FRMS_Template tmplt, FS_INT32* uDays);
	static FS_BOOL			SetLicenseExpiration(FRMS_Template tmplt, UINT uDays);
	
	static FS_BOOL			GetRightRequestURL(FRMS_Template tmplt, FS_WideString* wsURL);
	static FS_BOOL			GetRevocationListURL(FRMS_Template tmplt, FS_WideString* URL);
	static FS_BOOL			GetRevocationRefreshFrequency(FRMS_Template tmplt, SYSTEMTIME* pstFrequency);
	
	static FS_BOOL          SetMetaData(
								FRMS_Template tmplt,
								FS_LPWSTR pwszContentId,
								FS_LPWSTR pwszContentIdType,
								FS_LPWSTR pwszSKUId,
								FS_LPWSTR pwszSKUIdType,
								FS_LPWSTR pwszContentType,
								FS_LPWSTR pwszContentName);

	static FS_INT32         CountApplicationSpecificData(FRMS_Template tmplt);
	static FS_BOOL			RemoveApplicationSpecificData(FRMS_Template tmplt, FS_INT32 index);
	static FS_BOOL			SetApplicationSpecificData(FRMS_Template tmplt, FS_LPWSTR wsName, FS_LPWSTR wsValue);
	static FS_BOOL			GetApplicationSpecificData(FRMS_Template tmplt, FS_INT32 index, FS_WideString* wsName, FS_WideString* wsValue);
	
	static FS_BOOL          SetRevocationPoint(
								FRMS_Template tmplt,
								FS_LPWSTR pwszId,
								FS_LPWSTR pwszIdType,
								FS_LPWSTR pwszURL,
								SYSTEMTIME* pstFrequency,
								FS_LPWSTR pwszName,
								FS_LPWSTR pwszPublicKey);
};

class CFRMS_Common_V2
{
public:	
	static void SetDefServer(FS_LPWSTR pwszCertURL, FS_LPWSTR pwszLicensingURL);
	static void SetDefCredential(FS_LPWSTR pwszUserEmail);
	static FRMSHRESULT IsActivated(FS_INT32 nType, FS_LPWSTR pwszUserEmail);
	static FRMSHRESULT Activate(FS_INT32 nType, FS_LPWSTR pwszCertURL, HWND hWnd, FS_WideString* wsResult);
	static FRMSHRESULT CreateBoundLicense(FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszEULChain, FS_LPWSTR pwszRightsRequested);
	static void RegisterCommonEventHandler(FRMS_CommonEventCallbacks commonEventCallbacks);
};

class CFRMS_Decryption_V2
{
public:	
	static FS_BOOL GetSIL(FPD_Object encryptDict, FS_WideString* wsIL);
	static FRMSHRESULT AcquireEULChain(FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszSIL,
										FS_LPWSTR pwszLicensingURL, FS_WideString* wsEULChain);
	static FRMSHRESULT AcquireRevocationList(FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszSIL, FS_LPWSTR pwszEULChain);
	static FRMSHRESULT RegisterLocalRevocationList(FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszSIL);
	static void RegisterDecryptionEventHandler(FRMS_DecryptionEventCallbacks decryptionEventCallbacks);
	static void RegisterCusAuthHandler(FRMS_DecryptionCusAuthCallbacks callbacks);
	static FRMSHRESULT GetAppDataCount(FS_LPWSTR pwszEULChain, FS_INT32* outCount);
	static FRMSHRESULT GetAppDataByIndex(FS_LPWSTR pwszEULChain, FS_INT32 iIndex, FS_WideString &wsName, FS_WideString &wsValve);
	static FRMSHRESULT GetUserRightsFromEULChain(FS_LPWSTR pwszEULChain, FS_WideString* outUserName, FS_WideStringArray* outRihgtsArr);
};

class CFRMS_Encryption_V2
{
public:
	static void SetDefTemplate(FS_LPWSTR pwszPath);
	static FS_BOOL DoEncryption();
	static void RegisterEncryptionEventHandler(FRMS_EncryptionEventCallbacks encryptionEventCallbacks);
};

#ifdef __cplusplus
};
#endif//__cplusplus

#endif//FRMS_IMPL_H
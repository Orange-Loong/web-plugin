/*****************************************************************************

  Copyright (C) 2024 Foxit Corporation
  All rights reserved.
  
	NOTICE: Foxit permits you to use, modify, and distribute this file
	in accordance with the terms of the Foxit license agreement
	accompanying it. If you have received this file from a source other
	than Foxit, then your use, modification, or distribution of it
	requires the prior written permission of Foxit.
	
*****************************************************************************/

#ifndef FDRM_DESCIMPL_H
#define FDRM_DESCIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../../basic/fs_basicExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../../pdf/fpd_parserExpT.h"
#endif

#ifndef FDRM_PDFEXPT_H
#include "../fdrm_descExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

class CFDRM_CategoryRead_V2
{
public:

	//************************************
	// Function:  CountSubCategories
	// Param[in]: reader
	// Param[in]: hParent
	// Param[in]: bsFilter
	// Return:    
	// Remarks:   
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FS_INT32		CountSubCategories(FDRM_CategoryRead reader, FDRM_CATEGORY_HANDLER hParent, FS_ByteString bsFilter);
	
	//************************************
	// Function:  GetSubCategory
	// Param[in]: reader
	// Param[in]: hParent
	// Param[in]: bsFilter
	// Param[in]: index
	// Return:    
	// Remarks:   
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 1.0
	//************************************
	static FDRM_CATEGORY_HANDLER	GetSubCategory(FDRM_CategoryRead reader, FDRM_CATEGORY_HANDLER hParent, FS_ByteString bsFilter, FS_INT32 index);
	static FDRM_CATEGORY_HANDLER	FindSubCategory(FDRM_CategoryRead reader, FDRM_CATEGORY_HANDLER hParent, FS_ByteString bsFilter, FS_ByteString bsKey, FS_ByteString bsValue, FS_LPVOID pCur);
	static FDRM_CATEGORY_HANDLER	GetParentCategory(FDRM_CategoryRead reader, FDRM_CATEGORY_HANDLER hCategory);

	static FS_INT32		GetCategoryName(FDRM_CategoryRead reader, FDRM_CATEGORY_HANDLER hCategory, FS_ByteString out_bsCategory);
	static FS_INT32		CountAttributes(FDRM_CategoryRead reader, FDRM_CATEGORY_HANDLER hCategory);
	static FS_INT32		GetAttribute(FDRM_CategoryRead reader, FDRM_CATEGORY_HANDLER hCategory, FS_INT32 index, FS_ByteString out_bsName, FS_ByteString out_bsValue);
	static FS_INT32		GetAttributeValue(FDRM_CategoryRead reader, FDRM_CATEGORY_HANDLER hCategory, FS_ByteString bsName, FS_ByteString out_bsValue);

	static FS_INT32		GetCategoryData(FDRM_CategoryRead reader, FDRM_CATEGORY_HANDLER hCategory, FS_ByteString out_bsData);
	static void			Destroy(FDRM_CategoryRead reader);
};


class CFDRM_CategoryWrite_V2
{
public:
	static FDRM_CATEGORY_HANDLER	AddCategory(FDRM_CategoryWrite Writer, FDRM_CATEGORY_HANDLER hParent, FS_ByteString bsCategory, FS_BOOL bUnique);
	static FDRM_CATEGORY_HANDLER	AddCategory2(FDRM_CategoryWrite Writer, FDRM_CATEGORY_HANDLER hParent, FS_ByteString bsCategory, FS_ByteString bsKey, FS_ByteString bsValue);

	static void			SetAttribute(FDRM_CategoryWrite Writer, FDRM_CATEGORY_HANDLER hCategory, FS_ByteString bsName, FS_ByteString bsValue);
	static void			RemoveAttribute(FDRM_CategoryWrite Writer, FDRM_CATEGORY_HANDLER hCategory, FS_ByteString bsName);
	static void			SetCategoryData(FDRM_CategoryWrite Writer, FDRM_CATEGORY_HANDLER hCategory, FS_ByteString bsData);
	static void			RemoveCategory(FDRM_CategoryWrite Writer, FDRM_CATEGORY_HANDLER hParent, FS_ByteString bsCategory);
	static void			RemoveCategory2(FDRM_CategoryWrite Writer, FDRM_CATEGORY_HANDLER hParent, FDRM_CATEGORY_HANDLER hCategory);
	static void			RemoveCategory3(FDRM_CategoryWrite Writer, FDRM_CATEGORY_HANDLER hCategory);
	static FDRM_CategoryRead CastToCategoryRead(FDRM_CategoryWrite Writer);
	static void			Destroy(FDRM_CategoryWrite Writer);
};

class CFDRM_DescData_V2
{
public:
	static FDRM_DescData New(void);
	static void Destroy(FDRM_DescData data);

	static void GetPackageName(FDRM_DescData data, FS_ByteString out_PackageName);
	static void GetDefNameSpace(FDRM_DescData data, FS_ByteString out_DefNameSpace);
	static void GetFDRMNameSpace(FDRM_DescData data, FS_ByteString out_FDRMNameSpace);

	static void SetPackageName(FDRM_DescData data, FS_ByteString bsPackageName);
	static void SetDefNameSpace(FDRM_DescData data, FS_ByteString bsDefNameSpace);
	static void SetFDRMNameSpace(FDRM_DescData data, FS_ByteString bsFDRMNameSpace);
};

class CFDRM_ScriptData_V2
{
public:
		static FDRM_ScriptData New(void);
		static void Destroy(FDRM_ScriptData data);
		static void GetDivision(FDRM_ScriptData data, FS_ByteString out_bsDivision);
		static void GetFormatOrg(FDRM_ScriptData data, FS_ByteString out_bsFormatOrg);
		static void GetFormatVer(FDRM_ScriptData data, FS_ByteString out_bsFormatVer);
		static void GetAppOrg(FDRM_ScriptData data, FS_ByteString out_bsAppOrg);
		static void GetAppVer(FDRM_ScriptData data, FS_ByteString out_bsAppVer);
		static void GetAuthority(FDRM_ScriptData data, FS_ByteString out_bsAuthority);

		static void SetDivision(FDRM_ScriptData data, FS_ByteString bsDivision);
		static void SetFormatOrg(FDRM_ScriptData data, FS_ByteString bsFormatOrg);
		static void SetFormatVer(FDRM_ScriptData data, FS_ByteString bsFormatVer);
		static void SetAppOrg(FDRM_ScriptData data, FS_ByteString bsAppOrg);
		static void SetAppVer(FDRM_ScriptData data, FS_ByteString bsAppVer);
		static void SetAuthority(FDRM_ScriptData data, FS_ByteString bsAuthority);
};

class CFDRM_PresentationData_V2
{
public:
	static FDRM_PresentationData New(void);
	static void Destroy(FDRM_PresentationData data);
	
	static void GetDivision(FDRM_PresentationData data, FS_ByteString out_bsDivision);
	static void GetAuthority(FDRM_PresentationData data, FS_ByteString out_bsAuthority);
	static void SetDivision(FDRM_PresentationData data, FS_ByteString bsDivision);
	static void SetAuthority(FDRM_PresentationData data, FS_ByteString bsAuthority);	
};

class CFDRM_SignatureData_V2
{
public:
	static FDRM_SignatureData New(void);
	static void Destroy(FDRM_SignatureData data);
	
	static void GetDivision(FDRM_SignatureData data, FS_ByteString out_bsDivision);
	static void GetAgentOrg(FDRM_SignatureData data, FS_ByteString out_bsAgentOrg);
	static void GetAgentVer(FDRM_SignatureData data, FS_ByteString out_bsAgentVer);
	static void GetFormatOrg(FDRM_SignatureData data, FS_ByteString out_bsFormatOrg);
	static void GetFormatVer(FDRM_SignatureData data, FS_ByteString out_bsFormatVer);
	static void GetKey(FDRM_SignatureData data, FS_ByteString out_bsKey);

	static void SetDivision(FDRM_SignatureData data, FS_ByteString bsDivision);
	static void SetAgentOrg(FDRM_SignatureData data, FS_ByteString bsAgentOrg);
	static void SetAgentVer(FDRM_SignatureData data, FS_ByteString bsAgentVer);
	static void SetFormatOrg(FDRM_SignatureData data, FS_ByteString bsFormatOrg);
	static void SetFormatVer(FDRM_SignatureData data, FS_ByteString bsFormatVer);
	static void SetKey(FDRM_SignatureData data, FS_ByteString bsKey);

};


class CFDRM_DescRead_V2
{
public:
	static FDRM_DescRead New(void);
	static void Destroy(FDRM_DescRead reader);


	static FS_INT32 Load(FDRM_DescRead reader, FS_FileReadHandler file);
	static FS_INT32 VerifyDescriptor(FDRM_DescRead reader, const FDRM_DescData descData);
	static void GetDescType(FDRM_DescRead reader, FS_ByteString out_bsType);

	static FDRM_DESCSCRIPT_HANDLER GetScript(FDRM_DescRead reader, const FDRM_ScriptData scriptData);
	static FS_INT32 CountScripts(FDRM_DescRead reader);
	static FDRM_DESCSCRIPT_HANDLER GetScript2(FDRM_DescRead reader, FS_INT32 nIndex);
	static FS_INT32 GetScriptData(FDRM_DescRead reader, FDRM_DESCSCRIPT_HANDLER hScript, FDRM_ScriptData out_scriptData);
	static FDRM_CategoryRead GetScriptParams(FDRM_DescRead reader, FDRM_DESCSCRIPT_HANDLER hScript);

	static FDRM_DESCPRES_HANDLER GetPresentation(FDRM_DescRead reader, FDRM_DESCSCRIPT_HANDLER hScript, const FDRM_PresentationData presData);
	static FS_INT32 GetPresentationData(FDRM_DescRead reader, FDRM_DESCPRES_HANDLER hPresentation, FDRM_PresentationData out_presData);
	static FDRM_CategoryRead GetPresentationParams(FDRM_DescRead reader, FDRM_DESCPRES_HANDLER hPresentation);

	static FDRM_DESCSIGN_HANDLER GetSignature(FDRM_DescRead reader, const FDRM_SignatureData signData);
	static FS_INT32 GetSignatureData(FDRM_DescRead reader, FDRM_DESCSIGN_HANDLER hSign, FDRM_SignatureData out_signData);
	static FDRM_CategoryRead GetSignatureParams(FDRM_DescRead reader, FDRM_DESCSIGN_HANDLER hSign);
	static FS_INT32 GetSignatureData2(FDRM_DescRead reader, FDRM_DESCSIGN_HANDLER hSign, FS_ByteString out_bksData);
	static FS_INT32 CheckSignature(FDRM_DescRead reader, FDRM_DESCSIGN_HANDLER hSign, const FS_ByteString bksKey);

	static FS_INT32 VerifyValidation(FDRM_DescRead reader);
};

class CFDRM_DescWrite_V2
{
public:
	static FDRM_DescWrite New(FS_ByteString bsType);
	static void Destroy(FDRM_DescWrite writer);

	static FS_INT32				InitDescriptor(FDRM_DescWrite writer, const FDRM_DescData descData);

	static void					RemoveScript(FDRM_DescWrite writer, FS_ByteString bsDivision);
	static FDRM_DESCSCRIPT_HANDLER		AddScript(FDRM_DescWrite writer, const FDRM_ScriptData scriptData);
	static FS_INT32				SetScriptFormat(FDRM_DescWrite writer, FDRM_DESCSCRIPT_HANDLER hScript, FS_ByteString bsOrg, FS_ByteString bsVer);
	static FS_INT32				SetScriptApplication(FDRM_DescWrite writer, FDRM_DESCSCRIPT_HANDLER hScript, FS_ByteString bsOrg, FS_ByteString bsVer);
	static FS_INT32				SetScriptAuthority(FDRM_DescWrite writer, FDRM_DESCSCRIPT_HANDLER hScript, FS_ByteString bsAuth);
	static FDRM_CategoryWrite	SetScriptParams(FDRM_DescWrite writer, FDRM_DESCSCRIPT_HANDLER hScript);

	static void					RemovePresentation(FDRM_DescWrite writer, FDRM_DESCSCRIPT_HANDLER hScript, FS_ByteString bsDivision);
	static FDRM_DESCPRES_HANDLER			AddPresentation(FDRM_DescWrite writer, FDRM_DESCSCRIPT_HANDLER hScript, const FDRM_PresentationData presData);
	static FS_INT32				SetPresentationAuthority(FDRM_DescWrite writer, FDRM_DESCPRES_HANDLER hPresentation, FS_ByteString bsAuth);
	static FDRM_CategoryWrite	SetPresentationParams(FDRM_DescWrite writer, FDRM_DESCPRES_HANDLER hPresentation);

	static void					RemoveSignature(FDRM_DescWrite writer, FS_ByteString bsDivision);
	static FDRM_DESCSIGN_HANDLER			AddSignature(FDRM_DescWrite writer, const FDRM_SignatureData signData);
	static FS_INT32				SetSignatureAgent(FDRM_DescWrite writer, FDRM_DESCSIGN_HANDLER hSign, FS_ByteString bsOrg, FS_ByteString bsVer);
	static FS_INT32				SetSignatureFormat(FDRM_DescWrite writer, FDRM_DESCSIGN_HANDLER hSign, FS_ByteString bsOrg, FS_ByteString bsVer);
	static FDRM_CategoryWrite	SetSignatureParams(FDRM_DescWrite writer, FDRM_DESCSIGN_HANDLER hSign);
	static FS_INT32				SetSignatureKey(FDRM_DescWrite writer, FDRM_DESCSIGN_HANDLER hSign, const FS_ByteString bksKey);

	static FS_BOOL					Save(FDRM_DescWrite writer, FS_FileWriteHandler fileWrite);
	static FDRM_DescRead		CastToDescRead(FDRM_DescWrite writer);


};

class CFDRM_FoacRead_V2
{
public:
	static FDRM_FoacRead New(FDRM_DescRead descRead);
	static void Destroy(FDRM_FoacRead reader);

	static FDRM_DescRead			GetDescRead(FDRM_FoacRead reader);
	static FS_INT32				VerifyFoac(FDRM_FoacRead reader, const FDRM_DescData descData, const FDRM_ScriptData scriptData);

	static FS_INT32				GetType(FDRM_FoacRead reader, FS_ByteString out_bsType);
	static FS_INT32				GetSessionID(FDRM_FoacRead reader, FS_ByteString out_bsSessionID);
	static FS_INT32				GetRequestID(FDRM_FoacRead reader, FS_ByteString out_bsID);
	static FDRM_CategoryRead		GetRequestData(FDRM_FoacRead reader);
	static FS_INT32				GetAnswerState(FDRM_FoacRead reader, FS_ByteString out_bsState);
	static FDRM_CategoryRead		GetAnswerData(FDRM_FoacRead reader);	
};

class CFDRM_FoacWrite_V2
{
public:
	static FDRM_FoacWrite New(FDRM_DescWrite descWrite);
	static void Destroy(FDRM_FoacWrite writer);

	static FDRM_DescWrite		GetDescWrite(FDRM_FoacWrite writer);
	static FS_INT32				InitFoac(FDRM_FoacWrite writer, const FDRM_DescData descData, const FDRM_ScriptData scriptData);

	static FS_INT32				SetSessionID(FDRM_FoacWrite writer, FS_ByteString bsSessionID);
	static FS_INT32				SetRequestID(FDRM_FoacWrite writer, FS_ByteString bsID);
	static FDRM_CategoryWrite	SetRequestData(FDRM_FoacWrite writer);
	static FS_INT32				SetAnswerState(FDRM_FoacWrite writer, FS_ByteString bsState);
	static FDRM_CategoryWrite	SetAnswerData(FDRM_FoacWrite writer);
	static FDRM_FoacRead		CastToFoacRead(FDRM_FoacWrite writer);
};

class CFDRM_EnvelopeRead_V2
{
public:
	static FDRM_EnvelopeRead New(void);
	static void Destroy(FDRM_EnvelopeRead envRead);
	
	static FS_BOOL		LoadEnvelope(FDRM_EnvelopeRead envRead, FS_FileReadHandler fileRead);
	
	//base info
	static FS_BOOL		GetFormat(FDRM_EnvelopeRead envRead, FS_WideString out_wsOrg, FS_WideString out_wsVer);
	static FS_BOOL		GetApplication(FDRM_EnvelopeRead envRead, FS_WideString out_wsOrg, FS_WideString out_wsVer);
	static FS_BOOL		GetEnvelopeSN(FDRM_EnvelopeRead envRead, FS_WideString out_wsSN);
	static FS_BOOL		GetFileID(FDRM_EnvelopeRead envRead, FS_WideString out_wsFileId) ;
	static FS_BOOL		GetIssuer(FDRM_EnvelopeRead envRead, FS_WideString out_wsIssuerId, FS_WideString out_wsIssuerCertSN, FS_WideString out_wsIssuerServiceURL);
	

	//permission info
	static FS_BOOL 	GetConsumerId(FDRM_EnvelopeRead envRead, FS_WideString out_wsConsumerId); 
	static FS_INT32	CountAuthKeys(FDRM_EnvelopeRead envRead);
	static FS_BOOL		GetAuthKey(FDRM_EnvelopeRead envRead, FS_INT32 nIndex, FS_WideString out_wsKeyId, FS_WideString out_wsTreatment, FS_WideString out_wsAuthValue);
	static FS_INT32	CountLimits(FDRM_EnvelopeRead envRead);
	static FS_BOOL 	GetLimit(FDRM_EnvelopeRead envRead, FS_INT32 nIndex, FS_WideString out_wsType, FS_WideString out_wsValue);
	static FS_INT32	CountRights(FDRM_EnvelopeRead envRead);
	static FS_BOOL 	GetRight(FDRM_EnvelopeRead envRead, FS_INT32 nIndex, FS_WideString out_wsRightType);

	//encryption info
	static FS_BOOL		GetCipher(FDRM_EnvelopeRead envRead, FS_WideString out_wsAlgorithm, FS_WideString out_wsEncryptKey);
	static FS_BOOL		ValidateEnvelope(FDRM_EnvelopeRead envRead);
};




#ifdef __cplusplus
};
#endif



#endif
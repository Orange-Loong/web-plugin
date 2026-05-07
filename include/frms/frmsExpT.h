/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.	

*********************************************************************/

#ifndef FRMS_EXPT_H
#define FRMS_EXPT_H

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FR_DOCEXPT_H
#include "../frd/fr_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../pdf/fpd_objsExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../pdf/fpd_docExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif//__cplusplus

/* @COMMONSTART */

/* @DEFGROUPSTART FRMS_ACTIVATION_FLAGS */
	
/** @brief Activate machine */ 
#define FRMS_ACTIVATE_MACHINE             0x01

/** @brief Activate credential */ 
#define FRMS_ACTIVATE_CREDENTIAL          0x02

/* @DEFGROUPEND */

/* @DEFGROUPSTART FRMS_ERR_CODES */

/** @brief */
#define FRMS_NEEDS_MACHINE_ACTIVATION			0x8004CF3D

/** @brief */
#define FRMS_NEEDS_CREDENTIAL_ACTIVATION		0x8004CF3E

/* @DEFGROUPEND */

/* @TYPEDEFSTART */

/** @brief */ 
typedef long FRMSHRESULT;

/* @TYPEDEFEND */


/* @CALLBACKGROUPSTART FRMS_CommonEventCallbacksRec */
/**
 * @brief A callback set for RMS common event handler.
 * @see 
 */
typedef struct _frms_commonevent_callbacks_
{    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FRMS_CommonEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	void*		clientData;

	/* @CALLBACKSTART FRMSCommonOnWillInitSecureEnvironment */
	/**
	 * @brief It is called when application will init the RMS secure environment. One application should init the
	 * RMS secure environment only once.
	 * @param[in]		clientData		The user-supplied data.
	 * @param[in]		pwszMachineCert	The machine certificate used to init the RMS secure environment.
	 * @param[in]		pwszManifest	The manifest certificate used to init the RMS secure environment.
	 * @return void
	 * @note
     */
	void (*FRMSCommonOnWillInitSecureEnvironment)(FS_LPVOID clientData, FS_LPWSTR pwszMachineCert, FS_LPWSTR pwszManifest);
	/* @CALLBACKEND */

	void (*FRMSCommonOnDidInitSecureEnvironment)(FS_LPVOID clientData);

	void (*FRMSCommonOnWillGetDefServer)(FS_LPVOID clientData);

	void (*FRMSCommonOnDidGetDefServer)(FS_LPVOID clientData, FS_LPWSTR pwszCertURL, FS_LPWSTR pwszLicensingURL);

	void (*FRMSCommonOnWillGetDefCredential)(FS_LPVOID clientData);

	void (*FRMSCommonOnDidGetDefCredential)(FS_LPVOID clientData, FS_LPWSTR pwszUserEmail);

	void (*FRMSCommonOnWillActivateMachine)(FS_LPVOID clientData);

	void (*FRMSCommonOnDidActivateMachine)(FS_LPVOID clientData, FS_LPWSTR pwszMachineCert);

	void (*FRMSCommonOnWillActivateCredential)(FS_LPVOID clientData, FS_LPWSTR pwszUserEmail);

	void (*FRMSCommonOnDidActivateCredential)(FS_LPVOID clientData, FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszRAC);

	void (*FRMSCommonOnSelCredential)(FS_LPVOID clientData, FS_LPWSTR pwszUserEmail);

}FRMS_CommonEventCallbacksRec, *FRMS_CommonEventCallbacks;
/* @CALLBACKGROUPEND */


/* @CALLBACKGROUPSTART FRMS_EncryptionEventCallbacksRec */
/**
 * @brief A callback set for RMS Encryption event handler.
 * @see 
 */
typedef struct _frms_encryptionevent_callbacks_
{    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FRMS_EncryptionEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	void*		clientData;

	void (*FRMSEncryptionOnWillGetDefTemplate)(FS_LPVOID clientData);

	void (*FRMSEncryptionOnDidGetDefTemplate)(FS_LPVOID clientData, FS_LPWSTR pwszPath);

	void (*FRMSEncryptionOnWillAcquireCLC)(FS_LPVOID clientData, FS_LPWSTR pwszUserEmail);

	void (*FRMSEncryptionOnDidAcquireCLC)(FS_LPVOID clientData, FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszCLC);

	void (*FRMSEncryptionOnWillGetSignedIL)(FS_LPVOID clientData, FPD_Document pdfDoc, FS_LPWSTR pwszCLC);

	void (*FRMSEncryptionOnDidGetSignedIL)(FS_LPVOID clientData, FPD_Document pdfDoc, FS_LPWSTR pwszSignedIL);

	void (*FRMSEncryptionOnGetOwnerLicense)(FS_LPVOID clientData, FS_LPWSTR pwszOwnerlicense);

	void (*FRMSEncryptionOnWillEncrypt)(FS_LPVOID clientData, FPD_Document pdfDoc);

	void (*FRMSEncryptionOnEncryptContent)(FS_LPVOID clientData, FPD_Document pdfDoc, FS_DWORD objnum, FS_DWORD version, FS_LPCBYTE src_buf, FS_DWORD src_size);

	void (*FRMSEncryptionOnDidEncrypt)(FS_LPVOID clientData, FPD_Document pdfDoc);

	void (*FRMSEncryptionOnSelTemplate)(FS_LPVOID clientData, FS_LPWSTR pwszPath);

}FRMS_EncryptionEventCallbacksRec, *FRMS_EncryptionEventCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FRMS_DecryptionEventCallbacksRec */
/**
 * @brief A callback set for RMS Decryption event handler.
 * @see 
 */
typedef struct _frms_decryptionevent_callbacks_
{    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FRMS_DecryptionEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	void*		clientData;	

	void (*FRMSDecryptionOnWillAuthentication)(FS_LPVOID clientData, FPD_Object encryptDict, FPD_Document doc);

	void (*FRMSDecryptionOnDidAuthentication)(FS_LPVOID clientData, FPD_Object encryptDict, FPD_Document doc, FS_LPWSTR pwszUserEmail);

	void (*FRMSDecryptionOnWillGetEULFromLocal)(FS_LPVOID clientData, FPD_Document doc, FS_LPWSTR pwszUserEmail);
	
	void (*FRMSDecryptionOnDidGetEULFromLocal)(FS_LPVOID clientData, FPD_Document doc, FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszEULChain);

	void (*FRMSDecryptionOnWillAcquireEUL)(FS_LPVOID clientData, FPD_Document doc, FS_LPWSTR pwszUserEmail);

	void (*FRMSDecryptionOnDidAcquireEUL)(FS_LPVOID clientData, FPD_Document doc, FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszEULChain);

	void (*FRMSDecryptionOnWillCreateBoundLicense)(FS_LPVOID clientData, FPD_Document doc, FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszEULChain, FS_LPWSTR pwszRight);

	void (*FRMSDecryptionOnDidCreateBoundLicense)(FS_LPVOID clientData, FPD_Document doc, FS_LPWSTR pwszUserEmail, FS_LPWSTR pwszEULChain, FS_LPWSTR pwszRight);

	void (*FRMSDecryptionOnDecryptStart)(FS_LPVOID clientData, FPD_Document doc, FS_DWORD objnum,  FS_DWORD gennum);

	void (*FRMSDecryptionOnDecryptContent)(FS_LPVOID clientData, FPD_Document doc, FS_LPCBYTE src_buf, FS_DWORD src_size);

	void (*FRMSDecryptionOnReEncryptContent)(FS_LPVOID clientData, FPD_Document doc, FS_DWORD objnum, FS_DWORD version, FS_LPCBYTE src_buf, FS_DWORD src_size);

}FRMS_DecryptionEventCallbacksRec, *FRMS_DecryptionEventCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FRMS_DecryptionCusAuthCallbacksRec */
/**
 * @brief A callback set for RMS decryption custom authorization handler.
 * @see 
 */
typedef struct _frms_decryptioncusauth_callbacks_
{    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FRMS_DecryptionCusAuthCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	void*		clientData;

	/* @CALLBACKSTART FRMSDecryptionCusAuth */
	/**
	 * @brief It is called when application is authorizing and user wants to do additional authorization.
	 * @param[in]		clientData		The user-supplied data.
	 * @param[in]		doc				The document app is authorizing.
	 * @param[in]		pwszSIL			The SIL associated with the document.
	 * @param[in]		pwszEULChain	The EUL app uses to do the authorization.
	 * @return <Italic>TRUE</Italic> means the additional authrization is done successfully. Once a additional authrization 
	 * is done unsuccessfully, the internal authorization will be terminated and the application will fail to open the document.
	 * @note
     */
	FS_BOOL (*FRMSDecryptionCusAuth)(FS_LPVOID clientData, FPD_Document doc, FS_LPWSTR pwszSIL, FS_LPWSTR pwszEULChain);
	/* @CALLBACKEND */

}FRMS_DecryptionCusAuthCallbacksRec, *FRMS_DecryptionCusAuthCallbacks;
/* @CALLBACKGROUPEND */

/* @COMMONEND */

/* @OBJSTART FRMS_Template */
#ifndef FRMS_TEMPLATE
#define FRMS_TEMPLATE
/**
 * @brief A <a>FRMS_Template</a> is an object that represents the rights policy template of RMS.
 *
 * A <a>FRMS_Template</a> is an object that represents the rights policy template of RMS. User can create the object
 * from the official template file, and can also create an empty template object by invoking <a>FRMSTemplateNew2</a>().
 */
typedef struct _t_FRMS_Template* FRMS_Template;
#endif
/* @OBJEND */

#ifdef __cplusplus
};
#endif//__cplusplus

#endif//FRMS_EXPT_H
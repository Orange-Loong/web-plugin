/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_serialExpT.h
		
 - Types, macros, structures, etc. 

*********************************************************************/

/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/

/**
* @addtogroup FPDSERIAL
* @{
 */

#ifndef FPD_SERIALEXPT_H
#define FPD_SERIALEXPT_H

#ifdef __cplusplus
extern "C"{
#endif

/* @OBJSTART FPD_ObjArchiveSaver */
/** @brief PDF object archive saver class. See <a>CFPDObjArchiveSaverNew</a>, <a>CFPDObjArchiveSaverDestroy</a>.
 */
#ifndef FPD_OBJARCHIVESAVER
#define FPD_OBJARCHIVESAVER
typedef struct _t_FPD_ObjArchiveSaver* FPD_ObjArchiveSaver;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ObjArchiveLoader */
/** @brief PDF object archive loader class. See <a>CFPDObjArchiveLoaderNew</a>, <a>CFPDObjArchiveLoaderDestroy</a>.
 */
#ifndef FPD_OBJARCHIVELOADER
#define FPD_OBJARCHIVELOADER
typedef struct _t_FPD_ObjArchiveLoader* FPD_ObjArchiveLoader;
#endif
/* @OBJEND */

/* @OBJSTART FPD_PageArchiveSaver */
/** @brief PDF page archive saver class. See <a>CFPDPageArchiveSaverNew</a>, <a>CFPDPageArchiveSaverDestroy</a>.
 */
#ifndef FPD_PAGEARCHIVESAVER
#define FPD_PAGEARCHIVESAVER
typedef struct _t_FPD_PageArchiveSaver* FPD_PageArchiveSaver;
#endif
/* @OBJEND */

/* @OBJSTART FPD_PageArchiveLoader */
/** @brief PDF page archive loader class. See <a>CFPDPageArchiveLoaderNew</a>, <a>CFPDPageArchiveLoaderDestroy</a>.
 */
#ifndef FPD_PAGEARCHIVELOADER
#define FPD_PAGEARCHIVELOADER
typedef struct _t_FPD_PageArchiveLoader* FPD_PageArchiveLoader;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Creator */
/* @DEFGROUPSTART FPDCreatingFlag */
/**
  * @name Creating flags for PDF creator.
  */

/*@{*/

/** @brief Incremental. */
#define FPDFCREATE_INCREMENTAL		1
/** @brief No original. */
#define FPDFCREATE_NO_ORIGINAL		2
/** @brief Use progressive creator. */
#define FPDFCREATE_PROGRESSIVE		4
/** @brief Use object stream creator. */
#define FPDFCREATE_OBJECTSTREAM		8
/*@}*/
/* @DEFGROUPEND */

/** @brief PDF Creator: creating PDF file from a document object. See <a>FPDCreatorNew</a>, <a>FPDCreatorDestroy</a>.
 */
#ifndef FPD_CREATER
#define FPD_CREATER
typedef struct _t_FPD_Creator* FPD_Creator;
#endif
/* @OBJEND */


/** @brief Linearized PDF: creating a Linearized PDF file from a document object..
 */
#ifndef FPD_STANDARDLINEARIZATION
#define FPD_STANDARDLINEARIZATION
typedef struct _t_FPD_StandardLinearization* FPD_StandardLinearization;
#endif
/* @OBJEND */


/* @OBJSTART FPD_CryptoHandler */
/** @brief Abstract class for PDF cryptographic operations (encryption and decryption).
 *  This class works with security handler which provides algorithm and key info.
 */
#ifndef FPD_CRYPTOHANDLER
#define FPD_CRYPTOHANDLER
typedef struct _fr_crypto_callbacks_* FPD_CryptoHandler;
#endif
/* @OBJEND */

/* @OBJSTART FPD_StreamWrite */
/** @brief stream writing interface.
 */
#ifndef FPD_STREAMWRITE
#define FPD_STREAMWRITE
typedef struct _fr_crypto_callbacks_* FPD_StreamWrite;
#endif
/* @OBJEND */

/* @OBJSTART FPD_WrapperCreator */

/** @brief PDF Wrapper Creator: creating a wrapper PDF file to an existing PDF file.
 * See <a>FPDWrapperCreatorNew</a>, <a>FPDWrapperCreatorDestroy</a>.
 */
#ifndef FPD_WRAPPERCREATER
#define FPD_WRAPPERCREATER
typedef struct _t_FPD_WrapperCreator* FPD_WrapperCreator;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Wrapper20Creator */

/** @brief PDF Wrapper Creator: creating a wrapper 2.0 PDF file to an existing PDF file.
 * See <a>FPDWrapper20CreatorNew</a>, <a>FPDWrapper20CreatorDestroy</a>.
 */
#ifndef FPD_WRAPPER20CREATER
#define FPD_WRAPPER20CREATER
typedef struct _t_FPD_UnencryptedWrapperCreator* FPD_UnencryptedWrapperCreator;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ProgressiveEncryptHandler */
#ifndef FPD_PROGRESSSIVEENCRYPTHANDLER
#define FPD_PROGRESSSIVEENCRYPTHANDLER
/**
 * @brief The <a>FPD_ProgressiveEncryptHandler</a> object is used to encrypt the file progressively. It is returned by 
 * <a>FPDCreatorSetProgressiveEncryptHandler</a> and can be released by <a>FPDCreatorReleaseProgressiveEncryptHandler</a>.
 */
typedef struct _t_FPD_ProgressiveEncryptHandler* FPD_ProgressiveEncryptHandler;
#endif

/* @CALLBACKGROUPSTART FPD_ProgressiveEncryptCallbacksRec */

/**
 * @brief A callback set for progressive encrypt handler. See <a>FPDCreatorSetProgressiveEncryptHandler</a>. The callbacks will
 * be invoked when the PDF creator is encrypting content progressively. The plug-in has to implement the callback function as needed.
 *
 */
typedef struct _fpd_progressiveencrypt_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_ProgressiveEncryptCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	/* @CALLBACKSTART FPDProgressiveEncrypGetTempFile */
	/**
     * @brief A callback for progressive encrypt handler.
	 *
	 * It is called when the PDF creator is encrypting content progressively. If the stream is very large, the plug-in
	 * can provide a temporary local file to store the data, or the creating may fail because of lacking of system memory.
	 * Foxit Reader will use memory if the plug-in returns null.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @return The <a>FS_FileStream</a> object used to store and read the temporary data.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	 * @see FPDCreatorSetProgressiveEncryptHandler
     */
	FS_FileStream (*FPDProgressiveEncrypGetTempFile)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FPDProgressiveEncrypReleaseTempFile */
	/**
     * @brief A callback for progressive encrypt handler.
	 *
	 * It is called when the PDF creator completes encrypting content progressively. Then the plug-in can release the <a>FS_FileStream</a> object.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @param[in] fileStream	The <a>FS_FileStream</a> object to be released.
	 * @return void.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
	 * @see FPDCreatorSetProgressiveEncryptHandler
     */
	void (*FPDProgressiveEncrypReleaseTempFile)(FS_LPVOID clientData, FS_FileStream fileStream);
	/* @CALLBACKEND */
}FPD_ProgressiveEncryptCallbacksRec, *FPD_ProgressiveEncryptCallbacks;
/* @CALLBACKGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_CreatorOption */
#ifndef FPD_CREATOROPTION
#define FPD_CREATOROPTION
/**
 * @brief The <a>FPD_CREATOROPTION</a> object is used to decode or encode the stream progressively. It is returned by 
 * <a>FPDCreatorSetOption</a> and can be released by <a>FPDCreatorReleaseOption</a>.
 */
typedef struct _t_FPD_CreatorOption* FPD_CreatorOption;
#endif

/* @CALLBACKGROUPSTART FPD_CreatorOptionCallbacksRec */

/**
 * @brief A callback set for creator option. See <a>FPDCreatorSetOption</a>. The callbacks will
 * be invoked when the PDF creator is decoding or encoding content progressively. The plug-in has to implement the callback function as needed.
 *
 */
typedef struct _fpd_creatoroption_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_CreatorOptionCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;


	/* @CALLBACKSTART FPDCreatorOptionGetTempFile */
	/**
     * @brief A callback for creator option.
	 *
	 * It is called when the PDF creator is decoding or encoding content progressively. If the stream is very large, the plug-in
	 * can provide a temporary local file to store the data, or the creating may fail because of lacking of system memory.
	 * Foxit Reader will use memory if the plug-in returns null.
	 *
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] obj			The object to be processed.
	 * @return The <a>FS_FileStream</a> object used to store and read the temporary data.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	 * @see FPDCreatorSetOption
     */
	FS_FileStream (*FPDCreatorOptionGetTempFile)(FS_LPVOID clientData, FPD_Object obj);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FPDCreatorOptionReleaseTempFile */
	/**
     * @brief A callback for creator option.
	 *
	 * It is called when the PDF creator completes decoding or encoding content progressively. Then the plug-in can release the <a>FS_FileStream</a> object.
	 *
	 * @param[in] clientData	The user-supplied data.
     * @param[in] fileStream	The <a>FS_FileStream</a> object to be released.
	 * @return void.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	 * @see FPDCreatorSetOption
     */
	void (*FPDCreatorOptionReleaseTempFile)(FS_LPVOID clientData, FS_FileStream fileStream);
	/* @CALLBACKEND */
}FPD_CreatorOptionCallbacksRec, *FPD_CreatorOptionCallbacks;
/* @CALLBACKGROUPEND */

typedef void(*FPD_ReleaseProgressiveEncryptClientData)(FS_LPVOID clientData);

/* @OBJEND */

/* @OBJSTART FPD_CustomCryptoHandler */
#ifndef FPD_CUSTOMCRYPTOHANDLER
#define FPD_CUSTOMCRYPTOHANDLER
/**
 * @brief 
 */
typedef struct _t_FPD_CustomCryptoHandler* FPD_CustomCryptoHandler;
#endif
/* @OBJEND */
#ifdef __cplusplus
};
#endif

#endif

/** @} */


/*@}*/
/*********************************************************************

  Copyright (C) 2024 Foxit Corporation
  All rights reserved.
  
	NOTICE: Foxit permits you to use, modify, and distribute this file
	in accordance with the terms of the Foxit license agreement
	accompanying it. If you have received this file from a source other
	than Foxit, then your use, modification, or distribution of it
	requires the prior written permission of Foxit.
	
	  ---------------------------------------------------------------------
	  
		fdrm_pdfExpT.h
		
		  - Types, macros, structures, etc. required to use the FDRMLayer HFT.
		  
*********************************************************************/

#ifndef FDRM_PDFEXPT_H
#define FDRM_PDFEXPT_H


#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../pdf/fpd_parserExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../pdf/fpd_objsExpT.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* @OBJSTART FDRM_PDFSecurityHandler */
#ifndef FDRM_PDFSECURITYHANDLER
#define FDRM_PDFSECURITYHANDLER
typedef struct _t_FDRM_PDFSecurityHandler* FDRM_PDFSecurityHandler;
#endif

/* @OBJEND*/


#ifndef FDRM_PDFCRYPTOHANDLER
#define FDRM_PDFCRYPTOHANDLER
typedef struct _t_FDRM_PDFCryptoHandler* FDRM_PDFCryptoHandler;
#endif

#ifndef FDRM_PDFSCHEMA
#define FDRM_PDFSCHEMA
typedef struct _t_FDRM_PDFSchema* FDRM_PDFSchema;
#endif


enum FDRM_PDFSCHEMAITEMS
{
	FDRM_PDFSCHEMA_Item_Trailer = 0,		//Trailer dictionary and its sub dictionaries.
		FDRM_PDFSCHEMA_Item_Catalog,			//Catalog dictionary and page-tree dictionaries.
		FDRM_PDFSCHEMA_Item_Page,			//Page dictionary and its sub dictionaries.
};


#ifndef FDRM_ENCRYPTDICTREAD
#define FDRM_ENCRYPTDICTREAD
typedef struct _t_FDRM_EncryptDictRead* FDRM_EncryptDictRead;
#endif




#ifdef __cplusplus
};
#endif





#endif


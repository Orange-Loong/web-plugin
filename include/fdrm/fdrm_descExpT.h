/*********************************************************************

  Copyright (C) 2024 Foxit Corporation
  All rights reserved.
  
	NOTICE: Foxit permits you to use, modify, and distribute this file
	in accordance with the terms of the Foxit license agreement
	accompanying it. If you have received this file from a source other
	than Foxit, then your use, modification, or distribution of it
	requires the prior written permission of Foxit.
	
	  ---------------------------------------------------------------------
	  
		fdrm_descExpT.h
		
		  - Types, macros, structures, etc. required to use the FDRMLayer HFT.
		  
*********************************************************************/
#ifndef FDRM_DESCEXPT_H
#define FDRM_DESCEXPT_H

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



#ifndef FDRM_CATEGORYREAD
#define FDRM_CATEGORYREAD
typedef struct _t_FDRM_CategoryRead* FDRM_CategoryRead;
#endif

typedef struct _t_FDRM_CATEGORY_HANDLER* FDRM_CATEGORY_HANDLER;

#ifndef FDRM_CATEGORYWRITE
#define FDRM_CATEGORYWRITE
typedef struct _t_FDRM_CategoryWrite* FDRM_CategoryWrite;
#endif


#define FDRM_DESC_TYPE_Contents		"Contents"
#define FDRM_DESC_TYPE_TOC			"TOC"
#define FDRM_DESC_TYPE_Resource		"Resource"
#define FDRM_DESC_TYPE_Permission	"Permission"
#define FDRM_DESC_TYPE_Encryption	"Encryption"
#define FDRM_DESC_TYPE_Certificate	"Certificate"
#define FDRM_DESC_TYPE_Envelope		"Envelope"
#define FDRM_DESC_TYPE_Foac			"Foac"


typedef struct _t_FDRM_DESCSCRIPT_HANDLER* FDRM_DESCSCRIPT_HANDLER;
typedef struct _t_FDRM_DESCPRES_HANDLER* FDRM_DESCPRES_HANDLER;
typedef struct _t_FDRM_DESCSIGN_HANDLER* FDRM_DESCSIGN_HANDLER;

#ifndef FDRM_DESCDATA
#define FDRM_DESCDATA
typedef struct _t_FDRM_DescData* FDRM_DescData;
#endif

#ifndef FDRM_SCRIPTDATA
#define FDRM_SCRIPTDATA
typedef struct _t_FDRM_ScriptData* FDRM_ScriptData;
#endif

#ifndef FDRM_PRESENTATIONDATA
#define FDRM_PRESENTATIONDATA
typedef struct _t_FDRM_PresentationData* FDRM_PresentationData;
#endif

#ifndef FDRM_SIGNATUREDATA
#define FDRM_SIGNATUREDATA
typedef struct _t_FDRM_SignatureData* FDRM_SignatureData;
#endif

#ifndef FDRM_DESCREAD
#define FDRM_DESCREAD
typedef struct _t_FDRM_DescRead* FDRM_DescRead;
#endif

#ifndef FDRM_DESCWRITE
#define FDRM_DESCWRITE
typedef struct _t_FDRM_DescWrite* FDRM_DescWrite;
#endif

#define FDRM_FOAC_TYPE_Request	"FoxitFOACRequest"
#define FDRM_FOAC_TYPE_Answer	"FoxitFOACAnswer"

#ifndef FDRM_FOACREAD
#define FDRM_FOACREAD
typedef struct _t_FDRM_FoacRead* FDRM_FoacRead;
#endif

#ifndef FDRM_FOACWRITE
#define FDRM_FOACWRITE
typedef struct _t_FDRM_FoacWrite* FDRM_FoacWrite;
#endif

#ifndef FDRM_ENVELOPEREAD
#define FDRM_ENVELOPEREAD
typedef struct _t_FDRM_EnvelopeRead* FDRM_EnvelopeRead;
#endif

#ifdef __cplusplus
};
#endif


#endif

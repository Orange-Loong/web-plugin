/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_EDITCALLS_H
#define FPD_EDITCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_EDITEXPT_H
#include "fpd_editExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_editImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_editTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_editImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_editTempl.h"

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
//*****************************
/* WordRange HFT functions */
//*****************************

//*****************************
/* WordProps HFT functions */
//*****************************

//*****************************
/* Edit HFT functions */
//*****************************

//*****************************
/* EditFontMap HFT functions */
//*****************************

//*****************************
/* VTWord HFT functions */
//*****************************

//----------_V17----------
//*****************************
/* PWLCREATEPARAM HFT functions */
//*****************************

//*****************************
/* CPWLEdit HFT functions */
//*****************************

//*****************************
/* VariableTextIterator HFT functions */
//*****************************

//*****************************
/* VTLine HFT functions */
//*****************************

//*****************************
/* VTSection HFT functions */
//*****************************

//*****************************
/* VariableText HFT functions */
//*****************************

//*****************************
/* EDITFontData HFT functions */
//*****************************

//*****************************
/* BulletWordIterator HFT functions */
//*****************************

//*****************************
/* VTWordPlace HFT functions */
//*****************************

//*****************************
/* EDITFONTDATAArray HFT functions */
//*****************************

#define FPDEDITFONTDATAArrayCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEDITFONTDATAArrayCreateSELPROTO)FRCOREROUTINE(FPDEDITFONTDATAArraySEL,FPDEDITFONTDATAArrayCreateSEL, _gPID)))

#define FPDEDITFONTDATAArrayDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEDITFONTDATAArrayDeleteSELPROTO)FRCOREROUTINE(FPDEDITFONTDATAArraySEL,FPDEDITFONTDATAArrayDeleteSEL, _gPID)))

#define FPDEDITFONTDATAArrayGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEDITFONTDATAArrayGetSizeSELPROTO)FRCOREROUTINE(FPDEDITFONTDATAArraySEL,FPDEDITFONTDATAArrayGetSizeSEL, _gPID)))

#define FPDEDITFONTDATAArrayGetData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEDITFONTDATAArrayGetDataSELPROTO)FRCOREROUTINE(FPDEDITFONTDATAArraySEL,FPDEDITFONTDATAArrayGetDataSEL, _gPID)))

#define FPDEDITFONTDATAArrayRemoveAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEDITFONTDATAArrayRemoveAtSELPROTO)FRCOREROUTINE(FPDEDITFONTDATAArraySEL,FPDEDITFONTDATAArrayRemoveAtSEL, _gPID)))

#define FPDEDITFONTDATAArrayRemoveAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEDITFONTDATAArrayRemoveAllSELPROTO)FRCOREROUTINE(FPDEDITFONTDATAArraySEL,FPDEDITFONTDATAArrayRemoveAllSEL, _gPID)))

//*****************************
/* VTBulletIterator HFT functions */
//*****************************

//*****************************
/* TextList HFT functions */
//*****************************

//*****************************
/* PWLFillerNotify HFT functions */
//*****************************

//*****************************
/* List HFT functions */
//*****************************

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
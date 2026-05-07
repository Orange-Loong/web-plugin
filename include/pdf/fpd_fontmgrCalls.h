/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_FONTMGRCALLS_H
#define FPD_FONTMGRCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_FONTMGREXPT_H
#include "fpd_fontmgrExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_fontmgrImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_fontmgrTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_fontmgrImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_fontmgrTempl.h"

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
//----------_V17----------
//*****************************
/* FMFontMgr HFT functions */
//*****************************

#define FPDFMFontMgrGet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontMgrGetSELPROTO)FRCOREROUTINE(FPDFMFontMgrSEL,FPDFMFontMgrGetSEL, _gPID)))

#define FPDFMFontMgrGetCodePageFromCharset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontMgrGetCodePageFromCharsetSELPROTO)FRCOREROUTINE(FPDFMFontMgrSEL,FPDFMFontMgrGetCodePageFromCharsetSEL, _gPID)))

#define FPDFMFontMgrSetPlatformLanguage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontMgrSetPlatformLanguageSELPROTO)FRCOREROUTINE(FPDFMFontMgrSEL,FPDFMFontMgrSetPlatformLanguageSEL, _gPID)))

#define FPDFMFontMgrLoadSystemFonts (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontMgrLoadSystemFontsSELPROTO)FRCOREROUTINE(FPDFMFontMgrSEL,FPDFMFontMgrLoadSystemFontsSEL, _gPID)))

#define FPDFMFontMgrGetFontDescArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontMgrGetFontDescArraySELPROTO)FRCOREROUTINE(FPDFMFontMgrSEL,FPDFMFontMgrGetFontDescArraySEL, _gPID)))

//*****************************
/* FMFontDescriptor HFT functions */
//*****************************

#define FPDFMFontDescriptorCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontDescriptorCreateSELPROTO)FRCOREROUTINE(FPDFMFontDescriptorSEL,FPDFMFontDescriptorCreateSEL, _gPID)))

#define FPDFMFontDescriptorDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontDescriptorDeleteSELPROTO)FRCOREROUTINE(FPDFMFontDescriptorSEL,FPDFMFontDescriptorDeleteSEL, _gPID)))

#define FPDFMFontDescriptorGetFamiliyName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontDescriptorGetFamiliyNameSELPROTO)FRCOREROUTINE(FPDFMFontDescriptorSEL,FPDFMFontDescriptorGetFamiliyNameSEL, _gPID)))

#define FPDFMFontDescriptorSetFamiliyName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontDescriptorSetFamiliyNameSELPROTO)FRCOREROUTINE(FPDFMFontDescriptorSEL,FPDFMFontDescriptorSetFamiliyNameSEL, _gPID)))

#define FPDFMFontDescriptorGetPostscriptName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontDescriptorGetPostscriptNameSELPROTO)FRCOREROUTINE(FPDFMFontDescriptorSEL,FPDFMFontDescriptorGetPostscriptNameSEL, _gPID)))

#define FPDFMFontDescriptorSetPostscriptName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontDescriptorSetPostscriptNameSELPROTO)FRCOREROUTINE(FPDFMFontDescriptorSEL,FPDFMFontDescriptorSetPostscriptNameSEL, _gPID)))

#define FPDFMFontDescriptorGetFullName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontDescriptorGetFullNameSELPROTO)FRCOREROUTINE(FPDFMFontDescriptorSEL,FPDFMFontDescriptorGetFullNameSEL, _gPID)))

#define FPDFMFontDescriptorSetFullName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontDescriptorSetFullNameSELPROTO)FRCOREROUTINE(FPDFMFontDescriptorSEL,FPDFMFontDescriptorSetFullNameSEL, _gPID)))

#define FPDFMFontDescriptorGetBsFamilyName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontDescriptorGetBsFamilyNameSELPROTO)FRCOREROUTINE(FPDFMFontDescriptorSEL,FPDFMFontDescriptorGetBsFamilyNameSEL, _gPID)))

#define FPDFMFontDescriptorSetBsFamilyName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontDescriptorSetBsFamilyNameSELPROTO)FRCOREROUTINE(FPDFMFontDescriptorSEL,FPDFMFontDescriptorSetBsFamilyNameSEL, _gPID)))

#define FPDFMFontDescriptorGetCharset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFMFontDescriptorGetCharsetSELPROTO)FRCOREROUTINE(FPDFMFontDescriptorSEL,FPDFMFontDescriptorGetCharsetSEL, _gPID)))

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_PWLCALLS_H
#define FPD_PWLCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PWLEXPT_H
#include "fpd_pwlExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_pwlImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_pwlTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_pwlImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_pwlTempl.h"

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
/* CPWLListBox HFT functions */
//*****************************

//*****************************
/* CPWLComboBox HFT functions */
//*****************************

//*****************************
/* CPWLCheckBox HFT functions */
//*****************************

//*****************************
/* CPWLRadioButton HFT functions */
//*****************************

//*****************************
/* CPWLPushButton HFT functions */
//*****************************

//*****************************
/* CPWLIcon HFT functions */
//*****************************

//*****************************
/* CPWLEditCtrl HFT functions */
//*****************************

//*****************************
/* SpellCheck HFT functions */
//*****************************

#define FPDSpellCheckNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDSpellCheckNewSELPROTO)FRCOREROUTINE(FPDSpellCheckSEL,FPDSpellCheckNewSEL, _gPID)))

#define FPDSpellCheckDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDSpellCheckDeleteSELPROTO)FRCOREROUTINE(FPDSpellCheckSEL,FPDSpellCheckDeleteSEL, _gPID)))

#define FPDSpellCheckCheckWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDSpellCheckCheckWordSELPROTO)FRCOREROUTINE(FPDSpellCheckSEL,FPDSpellCheckCheckWordSEL, _gPID)))

#define FPDSpellCheckSuggestWords (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDSpellCheckSuggestWordsSELPROTO)FRCOREROUTINE(FPDSpellCheckSEL,FPDSpellCheckSuggestWordsSEL, _gPID)))

#define FPDSpellCheckIsCurSCSupWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDSpellCheckIsCurSCSupWordSELPROTO)FRCOREROUTINE(FPDSpellCheckSEL,FPDSpellCheckIsCurSCSupWordSEL, _gPID)))

#define FPDSpellCheckIsSCAvalible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDSpellCheckIsSCAvalibleSELPROTO)FRCOREROUTINE(FPDSpellCheckSEL,FPDSpellCheckIsSCAvalibleSEL, _gPID)))

//*****************************
/* CPWLSignature HFT functions */
//*****************************

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_SERIALCALLS_H
#define FPD_SERIALCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_SERIALEXPT_H
#include "fpd_serialExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_serialImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_serialTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_serialImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_serialTempl.h"

//----------_V1----------
//*****************************
/* ObjArchiveSaver HFT functions */
//*****************************

#define FPDObjArchiveSaverNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverNewSELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverNewSEL, _gPID)))

#define FPDObjArchiveSaverDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverDestroySELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverDestroySEL, _gPID)))

#define FPDObjArchiveSaverSaveObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverSaveObjectSELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverSaveObjectSEL, _gPID)))

#define FPDObjArchiveSaverGetLength (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverGetLengthSELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverGetLengthSEL, _gPID)))

#define FPDObjArchiveSaverGetBuffer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverGetBufferSELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverGetBufferSEL, _gPID)))

#define FPDObjArchiveSaverSaveByte (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverSaveByteSELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverSaveByteSEL, _gPID)))

#define FPDObjArchiveSaverSaveInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverSaveIntegerSELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverSaveIntegerSEL, _gPID)))

#define FPDObjArchiveSaverSaveDWORD (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverSaveDWORDSELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverSaveDWORDSEL, _gPID)))

#define FPDObjArchiveSaverSaveFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverSaveFloatSELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverSaveFloatSEL, _gPID)))

#define FPDObjArchiveSaverSaveByteString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverSaveByteStringSELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverSaveByteStringSEL, _gPID)))

#define FPDObjArchiveSaverSaveWideString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverSaveWideStringSELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverSaveWideStringSEL, _gPID)))

#define FPDObjArchiveSaverSaveWideStringII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverSaveWideStringIISELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverSaveWideStringIISEL, _gPID)))

#define FPDObjArchiveSaverWrite (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveSaverWriteSELPROTO)FRCOREROUTINE(FPDObjArchiveSaverSEL,FPDObjArchiveSaverWriteSEL, _gPID)))

//*****************************
/* ObjArchiveLoader HFT functions */
//*****************************

#define FPDObjArchiveLoaderNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveLoaderNewSELPROTO)FRCOREROUTINE(FPDObjArchiveLoaderSEL,FPDObjArchiveLoaderNewSEL, _gPID)))

#define FPDObjArchiveLoaderDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveLoaderDestroySELPROTO)FRCOREROUTINE(FPDObjArchiveLoaderSEL,FPDObjArchiveLoaderDestroySEL, _gPID)))

#define FPDObjArchiveLoaderLoadObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveLoaderLoadObjectSELPROTO)FRCOREROUTINE(FPDObjArchiveLoaderSEL,FPDObjArchiveLoaderLoadObjectSEL, _gPID)))

#define FPDObjArchiveLoaderIsEOF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveLoaderIsEOFSELPROTO)FRCOREROUTINE(FPDObjArchiveLoaderSEL,FPDObjArchiveLoaderIsEOFSEL, _gPID)))

#define FPDObjArchiveLoaderRead (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveLoaderReadSELPROTO)FRCOREROUTINE(FPDObjArchiveLoaderSEL,FPDObjArchiveLoaderReadSEL, _gPID)))

#define FPDObjArchiveLoaderLoadByte (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveLoaderLoadByteSELPROTO)FRCOREROUTINE(FPDObjArchiveLoaderSEL,FPDObjArchiveLoaderLoadByteSEL, _gPID)))

#define FPDObjArchiveLoaderLoadInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveLoaderLoadIntegerSELPROTO)FRCOREROUTINE(FPDObjArchiveLoaderSEL,FPDObjArchiveLoaderLoadIntegerSEL, _gPID)))

#define FPDObjArchiveLoaderLoadDWORD (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveLoaderLoadDWORDSELPROTO)FRCOREROUTINE(FPDObjArchiveLoaderSEL,FPDObjArchiveLoaderLoadDWORDSEL, _gPID)))

#define FPDObjArchiveLoaderLoadFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveLoaderLoadFloatSELPROTO)FRCOREROUTINE(FPDObjArchiveLoaderSEL,FPDObjArchiveLoaderLoadFloatSEL, _gPID)))

#define FPDObjArchiveLoaderLoadByteString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveLoaderLoadByteStringSELPROTO)FRCOREROUTINE(FPDObjArchiveLoaderSEL,FPDObjArchiveLoaderLoadByteStringSEL, _gPID)))

#define FPDObjArchiveLoaderLoadWideString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjArchiveLoaderLoadWideStringSELPROTO)FRCOREROUTINE(FPDObjArchiveLoaderSEL,FPDObjArchiveLoaderLoadWideStringSEL, _gPID)))

//*****************************
/* PageArchiveSaver HFT functions */
//*****************************

#define FPDPageArchiveSaverNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveSaverNewSELPROTO)FRCOREROUTINE(FPDPageArchiveSaverSEL,FPDPageArchiveSaverNewSEL, _gPID)))

#define FPDPageArchiveSaverDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveSaverDestroySELPROTO)FRCOREROUTINE(FPDPageArchiveSaverSEL,FPDPageArchiveSaverDestroySEL, _gPID)))

#define FPDPageArchiveSaverSavePageObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveSaverSavePageObjectSELPROTO)FRCOREROUTINE(FPDPageArchiveSaverSEL,FPDPageArchiveSaverSavePageObjectSEL, _gPID)))

#define FPDPageArchiveSaverSaveClipPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveSaverSaveClipPathSELPROTO)FRCOREROUTINE(FPDPageArchiveSaverSEL,FPDPageArchiveSaverSaveClipPathSEL, _gPID)))

#define FPDPageArchiveSaverSaveGraphState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveSaverSaveGraphStateSELPROTO)FRCOREROUTINE(FPDPageArchiveSaverSEL,FPDPageArchiveSaverSaveGraphStateSEL, _gPID)))

#define FPDPageArchiveSaverSaveTextState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveSaverSaveTextStateSELPROTO)FRCOREROUTINE(FPDPageArchiveSaverSEL,FPDPageArchiveSaverSaveTextStateSEL, _gPID)))

#define FPDPageArchiveSaverSaveColorState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveSaverSaveColorStateSELPROTO)FRCOREROUTINE(FPDPageArchiveSaverSEL,FPDPageArchiveSaverSaveColorStateSEL, _gPID)))

#define FPDPageArchiveSaverSaveGeneralState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveSaverSaveGeneralStateSELPROTO)FRCOREROUTINE(FPDPageArchiveSaverSEL,FPDPageArchiveSaverSaveGeneralStateSEL, _gPID)))

#define FPDPageArchiveSaverNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveSaverNew2SELPROTO)FRCOREROUTINE(FPDPageArchiveSaverSEL,FPDPageArchiveSaverNew2SEL, _gPID)))

#define FPDPageArchiveSaverSetStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveSaverSetStreamSELPROTO)FRCOREROUTINE(FPDPageArchiveSaverSEL,FPDPageArchiveSaverSetStreamSEL, _gPID)))

//*****************************
/* PageArchiveLoader HFT functions */
//*****************************

#define FPDPageArchiveLoaderNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveLoaderNewSELPROTO)FRCOREROUTINE(FPDPageArchiveLoaderSEL,FPDPageArchiveLoaderNewSEL, _gPID)))

#define FPDPageArchiveLoaderDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveLoaderDestroySELPROTO)FRCOREROUTINE(FPDPageArchiveLoaderSEL,FPDPageArchiveLoaderDestroySEL, _gPID)))

#define FPDPageArchiveLoaderLoadObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveLoaderLoadObjectSELPROTO)FRCOREROUTINE(FPDPageArchiveLoaderSEL,FPDPageArchiveLoaderLoadObjectSEL, _gPID)))

#define FPDPageArchiveLoaderLoadClipPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveLoaderLoadClipPathSELPROTO)FRCOREROUTINE(FPDPageArchiveLoaderSEL,FPDPageArchiveLoaderLoadClipPathSEL, _gPID)))

#define FPDPageArchiveLoaderLoadGraphState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveLoaderLoadGraphStateSELPROTO)FRCOREROUTINE(FPDPageArchiveLoaderSEL,FPDPageArchiveLoaderLoadGraphStateSEL, _gPID)))

#define FPDPageArchiveLoaderLoadTextState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveLoaderLoadTextStateSELPROTO)FRCOREROUTINE(FPDPageArchiveLoaderSEL,FPDPageArchiveLoaderLoadTextStateSEL, _gPID)))

#define FPDPageArchiveLoaderLoadColorState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveLoaderLoadColorStateSELPROTO)FRCOREROUTINE(FPDPageArchiveLoaderSEL,FPDPageArchiveLoaderLoadColorStateSEL, _gPID)))

#define FPDPageArchiveLoaderLoadGeneralState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveLoaderLoadGeneralStateSELPROTO)FRCOREROUTINE(FPDPageArchiveLoaderSEL,FPDPageArchiveLoaderLoadGeneralStateSEL, _gPID)))

#define FPDPageArchiveLoaderNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageArchiveLoaderNew2SELPROTO)FRCOREROUTINE(FPDPageArchiveLoaderSEL,FPDPageArchiveLoaderNew2SEL, _gPID)))

//*****************************
/* Creator HFT functions */
//*****************************

#define FPDCreatorNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorNewSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorNewSEL, _gPID)))

#define FPDCreatorDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorDestroySELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorDestroySEL, _gPID)))

#define FPDCreatorCompress (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorCompressSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorCompressSEL, _gPID)))

#define FPDCreatorSetStandardSecurity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorSetStandardSecuritySELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorSetStandardSecuritySEL, _gPID)))

#define FPDCreatorModifyR5Security (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorModifyR5SecuritySELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorModifyR5SecuritySEL, _gPID)))

#define FPDCreatorSetCustomSecurity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorSetCustomSecuritySELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorSetCustomSecuritySEL, _gPID)))

#define FPDCreatorReleaseCustomSecurityData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorReleaseCustomSecurityDataSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorReleaseCustomSecurityDataSEL, _gPID)))

#define FPDCreatorRemoveSecurity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorRemoveSecuritySELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorRemoveSecuritySEL, _gPID)))

#define FPDCreatorCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorCreateSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorCreateSEL, _gPID)))

#define FPDCreatorCreate2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorCreate2SELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorCreate2SEL, _gPID)))

#define FPDCreatorCreate3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorCreate3SELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorCreate3SEL, _gPID)))

#define FPDCreatorGetObjectOffset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorGetObjectOffsetSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorGetObjectOffsetSEL, _gPID)))

#define FPDCreatorGetObjectSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorGetObjectSizeSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorGetObjectSizeSEL, _gPID)))

#define FPDCreatorSetProgressiveEncryptHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorSetProgressiveEncryptHandlerSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorSetProgressiveEncryptHandlerSEL, _gPID)))

#define FPDCreatorReleaseProgressiveEncryptHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorReleaseProgressiveEncryptHandlerSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorReleaseProgressiveEncryptHandlerSEL, _gPID)))

#define FPDCreatorSetOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorSetOptionSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorSetOptionSEL, _gPID)))

#define FPDCreatorReleaseOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorReleaseOptionSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorReleaseOptionSEL, _gPID)))

#define FPDCreatorDeprecatedSetDRMSecurity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorDeprecatedSetDRMSecuritySELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorDeprecatedSetDRMSecuritySEL, _gPID)))

#define FPDCreatorDeprecatedReleaseDRMSecurityData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorDeprecatedReleaseDRMSecurityDataSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorDeprecatedReleaseDRMSecurityDataSEL, _gPID)))

#define FPDCreatorDeprecatedSetDRMProgressiveEncryptHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorDeprecatedSetDRMProgressiveEncryptHandlerSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorDeprecatedSetDRMProgressiveEncryptHandlerSEL, _gPID)))

#define FPDCreatorDeprecatedReleaseDRMProgressiveEncryptHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorDeprecatedReleaseDRMProgressiveEncryptHandlerSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorDeprecatedReleaseDRMProgressiveEncryptHandlerSEL, _gPID)))

#define FPDCreatorSetProgressiveEncryptHandler2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorSetProgressiveEncryptHandler2SELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorSetProgressiveEncryptHandler2SEL, _gPID)))

#define FPDCreatorSetCustomSecurity2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorSetCustomSecurity2SELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorSetCustomSecurity2SEL, _gPID)))

#define FPDCreatorSetCustomSecurity3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorSetCustomSecurity3SELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorSetCustomSecurity3SEL, _gPID)))

#define FPDCreatorAttachUncompressObjects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorAttachUncompressObjectsSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorAttachUncompressObjectsSEL, _gPID)))

#define FPDCreatorGetStandardLinearizationObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorGetStandardLinearizationObjSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorGetStandardLinearizationObjSEL, _gPID)))

#define FPDCreatorCreate4 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorCreate4SELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorCreate4SEL, _gPID)))

#define FPDCreatorSetStandardSecurity2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorSetStandardSecurity2SELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorSetStandardSecurity2SEL, _gPID)))

#define FPDCreatorModifyR5Security2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorModifyR5Security2SELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorModifyR5Security2SEL, _gPID)))

#define FPDCreatorAttachIgnoredObjects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorAttachIgnoredObjectsSELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorAttachIgnoredObjectsSEL, _gPID)))

#define FPDCreatorSetAESV4GCMSecurity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCreatorSetAESV4GCMSecuritySELPROTO)FRCOREROUTINE(FPDCreatorSEL,FPDCreatorSetAESV4GCMSecuritySEL, _gPID)))

//----------_V2----------
//*****************************
/* WrapperCreator HFT functions */
//*****************************

#define FPDWrapperCreatorNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperCreatorNewSELPROTO)FRCOREROUTINE(FPDWrapperCreatorSEL,FPDWrapperCreatorNewSEL, _gPID)))

#define FPDWrapperCreatorDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperCreatorDestroySELPROTO)FRCOREROUTINE(FPDWrapperCreatorSEL,FPDWrapperCreatorDestroySEL, _gPID)))

#define FPDWrapperCreatorSetWrapperData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperCreatorSetWrapperDataSELPROTO)FRCOREROUTINE(FPDWrapperCreatorSEL,FPDWrapperCreatorSetWrapperDataSEL, _gPID)))

#define FPDWrapperCreatorCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperCreatorCreateSELPROTO)FRCOREROUTINE(FPDWrapperCreatorSEL,FPDWrapperCreatorCreateSEL, _gPID)))

#define FPDWrapperCreatorSetStandardSecurity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperCreatorSetStandardSecuritySELPROTO)FRCOREROUTINE(FPDWrapperCreatorSEL,FPDWrapperCreatorSetStandardSecuritySEL, _gPID)))

//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
//*****************************
/* UnencryptedWrapperCreator HFT functions */
//*****************************

#define FPDUnencryptedWrapperCreatorNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDUnencryptedWrapperCreatorNewSELPROTO)FRCOREROUTINE(FPDUnencryptedWrapperCreatorSEL,FPDUnencryptedWrapperCreatorNewSEL, _gPID)))

#define FPDUnencryptedWrapperCreatorDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDUnencryptedWrapperCreatorDestroySELPROTO)FRCOREROUTINE(FPDUnencryptedWrapperCreatorSEL,FPDUnencryptedWrapperCreatorDestroySEL, _gPID)))

#define FPDUnencryptedWrapperCreatorSetPayloadInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDUnencryptedWrapperCreatorSetPayloadInfoSELPROTO)FRCOREROUTINE(FPDUnencryptedWrapperCreatorSEL,FPDUnencryptedWrapperCreatorSetPayloadInfoSEL, _gPID)))

#define FPDUnencryptedWrapperCreatorSetPayLoad (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDUnencryptedWrapperCreatorSetPayLoadSELPROTO)FRCOREROUTINE(FPDUnencryptedWrapperCreatorSEL,FPDUnencryptedWrapperCreatorSetPayLoadSEL, _gPID)))

#define FPDUnencryptedWrapperCreatorCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDUnencryptedWrapperCreatorCreateSELPROTO)FRCOREROUTINE(FPDUnencryptedWrapperCreatorSEL,FPDUnencryptedWrapperCreatorCreateSEL, _gPID)))

#define FPDUnencryptedWrapperCreatorContinue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDUnencryptedWrapperCreatorContinueSELPROTO)FRCOREROUTINE(FPDUnencryptedWrapperCreatorSEL,FPDUnencryptedWrapperCreatorContinueSEL, _gPID)))

#define FPDUnencryptedWrapperCreatorSetStandardSecurity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDUnencryptedWrapperCreatorSetStandardSecuritySELPROTO)FRCOREROUTINE(FPDUnencryptedWrapperCreatorSEL,FPDUnencryptedWrapperCreatorSetStandardSecuritySEL, _gPID)))

//----------_V11----------
//----------_V12----------
//----------_V13----------
//----------_V14----------
//*****************************
/* StandardLinearization HFT functions */
//*****************************

#define FPDStandardLinearizationGetCFPDLinearizedObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStandardLinearizationGetCFPDLinearizedObjSELPROTO)FRCOREROUTINE(FPDStandardLinearizationSEL,FPDStandardLinearizationGetCFPDLinearizedObjSEL, _gPID)))

#define FPDStandardLinearizationGetLinearizedObjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStandardLinearizationGetLinearizedObjNumSELPROTO)FRCOREROUTINE(FPDStandardLinearizationSEL,FPDStandardLinearizationGetLinearizedObjNumSEL, _gPID)))

#define FPDStandardLinearizationLinearize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStandardLinearizationLinearizeSELPROTO)FRCOREROUTINE(FPDStandardLinearizationSEL,FPDStandardLinearizationLinearizeSEL, _gPID)))

#define FPDStandardLinearizationNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStandardLinearizationNewSELPROTO)FRCOREROUTINE(FPDStandardLinearizationSEL,FPDStandardLinearizationNewSEL, _gPID)))

#define FPDStandardLinearizationDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStandardLinearizationDeleteSELPROTO)FRCOREROUTINE(FPDStandardLinearizationSEL,FPDStandardLinearizationDeleteSEL, _gPID)))

#define FPDStandardLinearizationCastToCreator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStandardLinearizationCastToCreatorSELPROTO)FRCOREROUTINE(FPDStandardLinearizationSEL,FPDStandardLinearizationCastToCreatorSEL, _gPID)))

#define FPDStandardLinearizationCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStandardLinearizationCreateSELPROTO)FRCOREROUTINE(FPDStandardLinearizationSEL,FPDStandardLinearizationCreateSEL, _gPID)))

//----------_V15----------
//----------_V16----------
//----------_V17----------
//*****************************
/* CustomCryptoHandler HFT functions */
//*****************************

#define FPDCustomCryptoHandlerCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCustomCryptoHandlerCreateSELPROTO)FRCOREROUTINE(FPDCustomCryptoHandlerSEL,FPDCustomCryptoHandlerCreateSEL, _gPID)))

#define FPDCustomCryptoHandlerDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCustomCryptoHandlerDestroySELPROTO)FRCOREROUTINE(FPDCustomCryptoHandlerSEL,FPDCustomCryptoHandlerDestroySEL, _gPID)))

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
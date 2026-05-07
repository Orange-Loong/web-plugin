/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_OBJSCALLS_H
#define FPD_OBJSCALLS_H

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

#ifndef FPD_OBJSEXPT_H
#include "fpd_objsExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_objsImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_objsTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_objsImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_objsTempl.h"

//----------_V1----------
//*****************************
/* Object HFT functions */
//*****************************

#define FPDObjectGetType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetTypeSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetTypeSEL, _gPID)))

#define FPDObjectGetobjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetobjNumSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetobjNumSEL, _gPID)))

#define FPDObjectIsIdentical (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectIsIdenticalSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectIsIdenticalSEL, _gPID)))

#define FPDObjectClone (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectCloneSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectCloneSEL, _gPID)))

#define FPDObjectCloneRefToDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectCloneRefToDocSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectCloneRefToDocSEL, _gPID)))

#define FPDObjectCloneRefToFDFDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectCloneRefToFDFDocSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectCloneRefToFDFDocSEL, _gPID)))

#define FPDObjectGetDirect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetDirectSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetDirectSEL, _gPID)))

#define FPDObjectDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectDestroySELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectDestroySEL, _gPID)))

#define FPDObjectGetString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetStringSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetStringSEL, _gPID)))

#define FPDObjectGetUnicodeText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetUnicodeTextSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetUnicodeTextSEL, _gPID)))

#define FPDObjectGetNumber (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetNumberSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetNumberSEL, _gPID)))

#define FPDObjectGetInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetIntegerSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetIntegerSEL, _gPID)))

#define FPDObjectGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetDictSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetDictSEL, _gPID)))

#define FPDObjectGetArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetArraySELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetArraySEL, _gPID)))

#define FPDObjectSetString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectSetStringSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectSetStringSEL, _gPID)))

#define FPDObjectSetUnicodeText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectSetUnicodeTextSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectSetUnicodeTextSEL, _gPID)))

#define FPDObjectGetDirectType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetDirectTypeSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetDirectTypeSEL, _gPID)))

#define FPDObjectIsModified (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectIsModifiedSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectIsModifiedSEL, _gPID)))

#define FPDObjectSetModified (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectSetModifiedSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectSetModifiedSEL, _gPID)))

#define FPDObjectGetContainer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetContainerSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetContainerSEL, _gPID)))

#define FPDObjectSetContainer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectSetContainerSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectSetContainerSEL, _gPID)))

#define FPDObjectParseString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectParseStringSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectParseStringSEL, _gPID)))

#define FPDObjectGetConstString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetConstStringSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetConstStringSEL, _gPID)))

#define FPDObjectIsNewCreated (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectIsNewCreatedSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectIsNewCreatedSEL, _gPID)))

#define FPDObjectGetUnicodeText2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectGetUnicodeText2SELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectGetUnicodeText2SEL, _gPID)))

#define FPDObjectDeepClone (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectDeepCloneSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectDeepCloneSEL, _gPID)))

#define FPDObjectCreateClonePredicateHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectCreateClonePredicateHandlerSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectCreateClonePredicateHandlerSEL, _gPID)))

#define FPDObjectDestroyClonePredicateHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDObjectDestroyClonePredicateHandlerSELPROTO)FRCOREROUTINE(FPDObjectSEL,FPDObjectDestroyClonePredicateHandlerSEL, _gPID)))

//*****************************
/* Boolean HFT functions */
//*****************************

#define FPDBooleanNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBooleanNewSELPROTO)FRCOREROUTINE(FPDBooleanSEL,FPDBooleanNewSEL, _gPID)))

#define FPDBooleanIdentical (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBooleanIdenticalSELPROTO)FRCOREROUTINE(FPDBooleanSEL,FPDBooleanIdenticalSEL, _gPID)))

//*****************************
/* Number HFT functions */
//*****************************

#define FPDNumberNewByInt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberNewByIntSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberNewByIntSEL, _gPID)))

#define FPDNumberNewByFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberNewByFloatSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberNewByFloatSEL, _gPID)))

#define FPDNumberNewByStr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberNewByStrSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberNewByStrSEL, _gPID)))

#define FPDNumberNewFromData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberNewFromDataSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberNewFromDataSEL, _gPID)))

#define FPDNumberIdentical (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberIdenticalSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberIdenticalSEL, _gPID)))

#define FPDNumberGetString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberGetStringSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberGetStringSEL, _gPID)))

#define FPDNumberSetString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberSetStringSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberSetStringSEL, _gPID)))

#define FPDNumberIsInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberIsIntegerSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberIsIntegerSEL, _gPID)))

#define FPDNumberGetInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberGetIntegerSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberGetIntegerSEL, _gPID)))

#define FPDNumberGetNumber (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberGetNumberSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberGetNumberSEL, _gPID)))

#define FPDNumberSetNumber (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberSetNumberSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberSetNumberSEL, _gPID)))

#define FPDNumberGetFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberGetFloatSELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberGetFloatSEL, _gPID)))

#define FPDNumberNewByFloat2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNumberNewByFloat2SELPROTO)FRCOREROUTINE(FPDNumberSEL,FPDNumberNewByFloat2SEL, _gPID)))

//*****************************
/* String HFT functions */
//*****************************

#define FPDStringNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStringNewSELPROTO)FRCOREROUTINE(FPDStringSEL,FPDStringNewSEL, _gPID)))

#define FPDStringNewW (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStringNewWSELPROTO)FRCOREROUTINE(FPDStringSEL,FPDStringNewWSEL, _gPID)))

#define FPDStringGetString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStringGetStringSELPROTO)FRCOREROUTINE(FPDStringSEL,FPDStringGetStringSEL, _gPID)))

#define FPDStringIdentical (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStringIdenticalSELPROTO)FRCOREROUTINE(FPDStringSEL,FPDStringIdenticalSEL, _gPID)))

#define FPDStringSetHex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStringSetHexSELPROTO)FRCOREROUTINE(FPDStringSEL,FPDStringSetHexSEL, _gPID)))

#define FPDStringIsHex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStringIsHexSELPROTO)FRCOREROUTINE(FPDStringSEL,FPDStringIsHexSEL, _gPID)))

//*****************************
/* Name HFT functions */
//*****************************

#define FPDNameNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameNewSELPROTO)FRCOREROUTINE(FPDNameSEL,FPDNameNewSEL, _gPID)))

#define FPDNameGetString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameGetStringSELPROTO)FRCOREROUTINE(FPDNameSEL,FPDNameGetStringSEL, _gPID)))

#define FPDNameIdentical (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameIdenticalSELPROTO)FRCOREROUTINE(FPDNameSEL,FPDNameIdenticalSEL, _gPID)))

//*****************************
/* Array HFT functions */
//*****************************

#define FPDArrayNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayNewSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayNewSEL, _gPID)))

#define FPDArrayGetCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetCountSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetCountSEL, _gPID)))

#define FPDArrayGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetElementSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetElementSEL, _gPID)))

#define FPDArrayGetElementValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetElementValueSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetElementValueSEL, _gPID)))

#define FPDArrayGetMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetMatrixSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetMatrixSEL, _gPID)))

#define FPDArrayGetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetRectSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetRectSEL, _gPID)))

#define FPDArrayGetString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetStringSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetStringSEL, _gPID)))

#define FPDArrayGetInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetIntegerSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetIntegerSEL, _gPID)))

#define FPDArrayGetNumber (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetNumberSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetNumberSEL, _gPID)))

#define FPDArrayGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetDictSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetDictSEL, _gPID)))

#define FPDArrayGetStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetStreamSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetStreamSEL, _gPID)))

#define FPDArrayGetArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetArraySELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetArraySEL, _gPID)))

#define FPDArrayGetFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayGetFloatSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayGetFloatSEL, _gPID)))

#define FPDArraySetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArraySetAtSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArraySetAtSEL, _gPID)))

#define FPDArrayInsertAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayInsertAtSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayInsertAtSEL, _gPID)))

#define FPDArrayRemoveAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayRemoveAtSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayRemoveAtSEL, _gPID)))

#define FPDArrayAdd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayAddSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayAddSEL, _gPID)))

#define FPDArrayAddNumber (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayAddNumberSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayAddNumberSEL, _gPID)))

#define FPDArrayAddInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayAddIntegerSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayAddIntegerSEL, _gPID)))

#define FPDArrayAddString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayAddStringSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayAddStringSEL, _gPID)))

#define FPDArrayAddName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayAddNameSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayAddNameSEL, _gPID)))

#define FPDArrayAddReferenceToDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayAddReferenceToDocSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayAddReferenceToDocSEL, _gPID)))

#define FPDArrayAddReferenceToFDFDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayAddReferenceToFDFDocSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayAddReferenceToFDFDocSEL, _gPID)))

#define FPDArrayAddReference2ToDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayAddReference2ToDocSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayAddReference2ToDocSEL, _gPID)))

#define FPDArrayAddReference2ToFDFDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayAddReference2ToFDFDocSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayAddReference2ToFDFDocSEL, _gPID)))

#define FPDArrayIsIdentical (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayIsIdenticalSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayIsIdenticalSEL, _gPID)))

#define FPDArrayRemoveAt2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayRemoveAt2SELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayRemoveAt2SEL, _gPID)))

#define FPDArrayAddNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayAddNewSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayAddNewSEL, _gPID)))

#define FPDArrayRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayReleaseSELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayReleaseSEL, _gPID)))

#define FPDArrayAdd2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDArrayAdd2SELPROTO)FRCOREROUTINE(FPDArraySEL,FPDArrayAdd2SEL, _gPID)))

//*****************************
/* Dictionary HFT functions */
//*****************************

#define FPDDictionaryNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryNewSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryNewSEL, _gPID)))

#define FPDDictionaryGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetElementSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetElementSEL, _gPID)))

#define FPDDictionaryGetElementValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetElementValueSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetElementValueSEL, _gPID)))

#define FPDDictionaryGetString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetStringSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetStringSEL, _gPID)))

#define FPDDictionaryGetUnicodeText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetUnicodeTextSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetUnicodeTextSEL, _gPID)))

#define FPDDictionaryGetInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetIntegerSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetIntegerSEL, _gPID)))

#define FPDDictionaryGetInteger2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetInteger2SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetInteger2SEL, _gPID)))

#define FPDDictionaryGetBoolean (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetBooleanSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetBooleanSEL, _gPID)))

#define FPDDictionaryGetNumber (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetNumberSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetNumberSEL, _gPID)))

#define FPDDictionaryGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetDictSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetDictSEL, _gPID)))

#define FPDDictionaryGetStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetStreamSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetStreamSEL, _gPID)))

#define FPDDictionaryGetArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetArraySELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetArraySEL, _gPID)))

#define FPDDictionaryGetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetRectSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetRectSEL, _gPID)))

#define FPDDictionaryGetMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetMatrixSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetMatrixSEL, _gPID)))

#define FPDDictionaryGetFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetFloatSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetFloatSEL, _gPID)))

#define FPDDictionaryKeyExist (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryKeyExistSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryKeyExistSEL, _gPID)))

#define FPDDictionaryGetStartPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetStartPositionSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetStartPositionSEL, _gPID)))

#define FPDDictionaryGetNextElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetNextElementSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetNextElementSEL, _gPID)))

#define FPDDictionarySetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtSEL, _gPID)))

#define FPDDictionarySetAtName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtNameSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtNameSEL, _gPID)))

#define FPDDictionarySetAtString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtStringSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtStringSEL, _gPID)))

#define FPDDictionarySetAtInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtIntegerSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtIntegerSEL, _gPID)))

#define FPDDictionarySetAtNumber (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtNumberSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtNumberSEL, _gPID)))

#define FPDDictionarySetAtReferenceToDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtReferenceToDocSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtReferenceToDocSEL, _gPID)))

#define FPDDictionarySetAtReferenceToFDFDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtReferenceToFDFDocSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtReferenceToFDFDocSEL, _gPID)))

#define FPDDictionarySetAtReference2ToDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtReference2ToDocSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtReference2ToDocSEL, _gPID)))

#define FPDDictionarySetAtReference2ToFDFDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtReference2ToFDFDocSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtReference2ToFDFDocSEL, _gPID)))

#define FPDDictionarySetAtRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtRectSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtRectSEL, _gPID)))

#define FPDDictionarySetAtMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtMatrixSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtMatrixSEL, _gPID)))

#define FPDDictionarySetAtBoolean (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtBooleanSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtBooleanSEL, _gPID)))

#define FPDDictionaryRemoveAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryRemoveAtSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryRemoveAtSEL, _gPID)))

#define FPDDictionaryReplaceKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryReplaceKeySELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryReplaceKeySEL, _gPID)))

#define FPDDictionaryIdentical (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryIdenticalSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryIdenticalSEL, _gPID)))

#define FPDDictionaryGetCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetCountSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetCountSEL, _gPID)))

#define FPDDictionaryAddValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryAddValueSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryAddValueSEL, _gPID)))

#define FPDDictionaryGetBoolean2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetBoolean2SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetBoolean2SEL, _gPID)))

#define FPDDictionarySetAtName2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtName2SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtName2SEL, _gPID)))

#define FPDDictionarySetNewAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetNewAtSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetNewAtSEL, _gPID)))

#define FPDDictionaryAddReference (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryAddReferenceSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryAddReferenceSEL, _gPID)))

#define FPDDictionaryGetString2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetString2SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetString2SEL, _gPID)))

#define FPDDictionaryRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryReleaseSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryReleaseSEL, _gPID)))

#define FPDDictionarySetAtString2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAtString2SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAtString2SEL, _gPID)))

#define FPDDictionaryMoveData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryMoveDataSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryMoveDataSEL, _gPID)))

#define FPDDictionarySetAt2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAt2SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAt2SEL, _gPID)))

#define FPDDictionaryRemoveAt2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryRemoveAt2SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryRemoveAt2SEL, _gPID)))

#define FPDDictionaryAddReference2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryAddReference2SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryAddReference2SEL, _gPID)))

#define FPDDictionaryAddReference3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryAddReference3SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryAddReference3SEL, _gPID)))

#define FPDDictionaryAddReference4 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryAddReference4SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryAddReference4SEL, _gPID)))

#define FPDDictionaryGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetNameSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetNameSEL, _gPID)))

#define FPDDictionaryGetInteger64 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetInteger64SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetInteger64SEL, _gPID)))

#define FPDDictionaryGetInteger64ByDefault (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionaryGetInteger64ByDefaultSELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionaryGetInteger64ByDefaultSEL, _gPID)))

#define FPDDictionarySetAt3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDictionarySetAt3SELPROTO)FRCOREROUTINE(FPDDictionarySEL,FPDDictionarySetAt3SEL, _gPID)))

//*****************************
/* Stream HFT functions */
//*****************************

#define FPDStreamNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamNewSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamNewSEL, _gPID)))

#define FPDStreamInitStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamInitStreamSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamInitStreamSEL, _gPID)))

#define FPDStreamGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamGetDictSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamGetDictSEL, _gPID)))

#define FPDStreamSetData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamSetDataSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamSetDataSEL, _gPID)))

#define FPDStreamIdentical (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamIdenticalSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamIdenticalSEL, _gPID)))

#define FPDStreamGetStreamFilter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamGetStreamFilterSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamGetStreamFilterSEL, _gPID)))

#define FPDStreamGetRawSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamGetRawSizeSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamGetRawSizeSEL, _gPID)))

#define FPDStreamReadRawData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamReadRawDataSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamReadRawDataSEL, _gPID)))

#define FPDStreamIsMemoryBased (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamIsMemoryBasedSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamIsMemoryBasedSEL, _gPID)))

#define FPDStreamClone (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamCloneSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamCloneSEL, _gPID)))

#define FPDStreamCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamCreateSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamCreateSEL, _gPID)))

#define FPDStreamNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamNew2SELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamNew2SEL, _gPID)))

#define FPDStreamSetStreamFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamSetStreamFileSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamSetStreamFileSEL, _gPID)))

#define FPDStreamDecryptStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamDecryptStreamSELPROTO)FRCOREROUTINE(FPDStreamSEL,FPDStreamDecryptStreamSEL, _gPID)))

//*****************************
/* StreamAcc HFT functions */
//*****************************

#define FPDStreamAccNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamAccNewSELPROTO)FRCOREROUTINE(FPDStreamAccSEL,FPDStreamAccNewSEL, _gPID)))

#define FPDStreamAccDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamAccDestroySELPROTO)FRCOREROUTINE(FPDStreamAccSEL,FPDStreamAccDestroySEL, _gPID)))

#define FPDStreamAccLoadAllData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamAccLoadAllDataSELPROTO)FRCOREROUTINE(FPDStreamAccSEL,FPDStreamAccLoadAllDataSEL, _gPID)))

#define FPDStreamAccGetStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamAccGetStreamSELPROTO)FRCOREROUTINE(FPDStreamAccSEL,FPDStreamAccGetStreamSEL, _gPID)))

#define FPDStreamAccGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamAccGetDictSELPROTO)FRCOREROUTINE(FPDStreamAccSEL,FPDStreamAccGetDictSEL, _gPID)))

#define FPDStreamAccGetData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamAccGetDataSELPROTO)FRCOREROUTINE(FPDStreamAccSEL,FPDStreamAccGetDataSEL, _gPID)))

#define FPDStreamAccGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamAccGetSizeSELPROTO)FRCOREROUTINE(FPDStreamAccSEL,FPDStreamAccGetSizeSEL, _gPID)))

#define FPDStreamAccDetachData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamAccDetachDataSELPROTO)FRCOREROUTINE(FPDStreamAccSEL,FPDStreamAccDetachDataSEL, _gPID)))

#define FPDStreamAccGetImageDecoder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamAccGetImageDecoderSELPROTO)FRCOREROUTINE(FPDStreamAccSEL,FPDStreamAccGetImageDecoderSEL, _gPID)))

#define FPDStreamAccGetImageParam (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamAccGetImageParamSELPROTO)FRCOREROUTINE(FPDStreamAccSEL,FPDStreamAccGetImageParamSEL, _gPID)))

//*****************************
/* StreamFilter HFT functions */
//*****************************

#define FPDStreamFilterDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamFilterDestroySELPROTO)FRCOREROUTINE(FPDStreamFilterSEL,FPDStreamFilterDestroySEL, _gPID)))

#define FPDStreamFilterReadBlock (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamFilterReadBlockSELPROTO)FRCOREROUTINE(FPDStreamFilterSEL,FPDStreamFilterReadBlockSEL, _gPID)))

#define FPDStreamFilterGetSrcPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamFilterGetSrcPosSELPROTO)FRCOREROUTINE(FPDStreamFilterSEL,FPDStreamFilterGetSrcPosSEL, _gPID)))

#define FPDStreamFilterGetStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDStreamFilterGetStreamSELPROTO)FRCOREROUTINE(FPDStreamFilterSEL,FPDStreamFilterGetStreamSEL, _gPID)))

//*****************************
/* Null HFT functions */
//*****************************

#define FPDNullNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNullNewSELPROTO)FRCOREROUTINE(FPDNullSEL,FPDNullNewSEL, _gPID)))

//*****************************
/* Reference HFT functions */
//*****************************

#define FPDReferenceNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDReferenceNewSELPROTO)FRCOREROUTINE(FPDReferenceSEL,FPDReferenceNewSEL, _gPID)))

#define FPDReferenceNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDReferenceNew2SELPROTO)FRCOREROUTINE(FPDReferenceSEL,FPDReferenceNew2SEL, _gPID)))

#define FPDReferenceGetRefObjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDReferenceGetRefObjNumSELPROTO)FRCOREROUTINE(FPDReferenceSEL,FPDReferenceGetRefObjNumSEL, _gPID)))

#define FPDReferenceSetRefToDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDReferenceSetRefToDocSELPROTO)FRCOREROUTINE(FPDReferenceSEL,FPDReferenceSetRefToDocSEL, _gPID)))

#define FPDReferenceSetRefToFDFDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDReferenceSetRefToFDFDocSELPROTO)FRCOREROUTINE(FPDReferenceSEL,FPDReferenceSetRefToFDFDocSEL, _gPID)))

#define FPDReferenceIdentical (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDReferenceIdenticalSELPROTO)FRCOREROUTINE(FPDReferenceSEL,FPDReferenceIdenticalSEL, _gPID)))

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
//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
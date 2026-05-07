/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FS_STRINGCALLS_H
#define FS_STRINGCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "fs_stringExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fs_stringImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fs_stringTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fs_stringImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fs_stringTempl.h"

//----------_V1----------
//*****************************
/* CharMap HFT functions */
//*****************************

#define FSCharMapNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCharMapNewSELPROTO)FRCOREROUTINE(FSCharMapSEL,FSCharMapNewSEL, _gPID)))

#define FSCharMapRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCharMapReleaseSELPROTO)FRCOREROUTINE(FSCharMapSEL,FSCharMapReleaseSEL, _gPID)))

#define FSCharMapGetDefaultMapper (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCharMapGetDefaultMapperSELPROTO)FRCOREROUTINE(FSCharMapSEL,FSCharMapGetDefaultMapperSEL, _gPID)))

#define FSCharMapGetDefaultMapper2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCharMapGetDefaultMapper2SELPROTO)FRCOREROUTINE(FSCharMapSEL,FSCharMapGetDefaultMapper2SEL, _gPID)))

//*****************************
/* ByteString HFT functions */
//*****************************

#define FSByteStringNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringNewSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringNewSEL, _gPID)))

#define FSByteStringNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringNew2SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringNew2SEL, _gPID)))

#define FSByteStringNew3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringNew3SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringNew3SEL, _gPID)))

#define FSByteStringNew4 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringNew4SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringNew4SEL, _gPID)))

#define FSByteStringFromUnicode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringFromUnicodeSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringFromUnicodeSEL, _gPID)))

#define FSByteStringFromUnicode2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringFromUnicode2SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringFromUnicode2SEL, _gPID)))

#define FSByteStringDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringDestroySELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringDestroySEL, _gPID)))

#define FSByteStringGetLength (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringGetLengthSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringGetLengthSEL, _gPID)))

#define FSByteStringIsEmpty (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringIsEmptySELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringIsEmptySEL, _gPID)))

#define FSByteStringCompare (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringCompareSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringCompareSEL, _gPID)))

#define FSByteStringEqual (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringEqualSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringEqualSEL, _gPID)))

#define FSByteStringEqualNoCase (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringEqualNoCaseSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringEqualNoCaseSEL, _gPID)))

#define FSByteStringCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringCopySELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringCopySEL, _gPID)))

#define FSByteStringFill (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringFillSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringFillSEL, _gPID)))

#define FSByteStringConcat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringConcatSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringConcatSEL, _gPID)))

#define FSByteStringConcat2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringConcat2SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringConcat2SEL, _gPID)))

#define FSByteStringEmpty (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringEmptySELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringEmptySEL, _gPID)))

#define FSByteStringGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringGetAtSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringGetAtSEL, _gPID)))

#define FSByteStringSetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringSetAtSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringSetAtSEL, _gPID)))

#define FSByteStringInsert (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringInsertSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringInsertSEL, _gPID)))

#define FSByteStringDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringDeleteSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringDeleteSEL, _gPID)))

#define FSByteStringFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringFormatSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringFormatSEL, _gPID)))

#define FSByteStringReserve (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringReserveSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringReserveSEL, _gPID)))

#define FSByteStringMid (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringMidSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringMidSEL, _gPID)))

#define FSByteStringMid2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringMid2SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringMid2SEL, _gPID)))

#define FSByteStringLeft (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringLeftSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringLeftSEL, _gPID)))

#define FSByteStringRight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringRightSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringRightSEL, _gPID)))

#define FSByteStringFind (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringFindSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringFindSEL, _gPID)))

#define FSByteStringFind2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringFind2SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringFind2SEL, _gPID)))

#define FSByteStringMakeLower (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringMakeLowerSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringMakeLowerSEL, _gPID)))

#define FSByteStringMakeUpper (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringMakeUpperSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringMakeUpperSEL, _gPID)))

#define FSByteStringTrimRight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringTrimRightSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringTrimRightSEL, _gPID)))

#define FSByteStringTrimRight2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringTrimRight2SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringTrimRight2SEL, _gPID)))

#define FSByteStringTrimRight3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringTrimRight3SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringTrimRight3SEL, _gPID)))

#define FSByteStringTrimLeft (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringTrimLeftSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringTrimLeftSEL, _gPID)))

#define FSByteStringTrimLeft2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringTrimLeft2SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringTrimLeft2SEL, _gPID)))

#define FSByteStringTrimLeft3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringTrimLeft3SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringTrimLeft3SEL, _gPID)))

#define FSByteStringReplace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringReplaceSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringReplaceSEL, _gPID)))

#define FSByteStringRemove (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringRemoveSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringRemoveSEL, _gPID)))

#define FSByteStringGetID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringGetIDSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringGetIDSEL, _gPID)))

#define FSByteStringFormatInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringFormatIntegerSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringFormatIntegerSEL, _gPID)))

#define FSByteStringFormatFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringFormatFloatSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringFormatFloatSEL, _gPID)))

#define FSByteStringCastToLPCSTR (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringCastToLPCSTRSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringCastToLPCSTRSEL, _gPID)))

#define FSByteStringUTF8Decode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringUTF8DecodeSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringUTF8DecodeSEL, _gPID)))

#define FSByteStringFormatV (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringFormatVSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringFormatVSEL, _gPID)))

#define FSByteStringCastToLPCBYTE (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringCastToLPCBYTESELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringCastToLPCBYTESEL, _gPID)))

#define FSByteStringConvertFrom (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringConvertFromSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringConvertFromSEL, _gPID)))

#define FSByteStringEqual2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringEqual2SELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringEqual2SEL, _gPID)))

#define FSByteStringReverseFind (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringReverseFindSELPROTO)FRCOREROUTINE(FSByteStringSEL,FSByteStringReverseFindSEL, _gPID)))

//*****************************
/* WideString HFT functions */
//*****************************

#define FSWideStringNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringNewSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringNewSEL, _gPID)))

#define FSWideStringNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringNew2SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringNew2SEL, _gPID)))

#define FSWideStringNew3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringNew3SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringNew3SEL, _gPID)))

#define FSWideStringDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringDestroySELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringDestroySEL, _gPID)))

#define FSWideStringGetLength (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringGetLengthSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringGetLengthSEL, _gPID)))

#define FSWideStringIsEmpty (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringIsEmptySELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringIsEmptySEL, _gPID)))

#define FSWideStringCompare (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringCompareSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringCompareSEL, _gPID)))

#define FSWideStringCompare2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringCompare2SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringCompare2SEL, _gPID)))

#define FSWideStringEqual (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringEqualSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringEqualSEL, _gPID)))

#define FSWideStringEqual2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringEqual2SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringEqual2SEL, _gPID)))

#define FSWideStringCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringCopySELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringCopySEL, _gPID)))

#define FSWideStringFill (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringFillSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringFillSEL, _gPID)))

#define FSWideStringConcat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringConcatSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringConcatSEL, _gPID)))

#define FSWideStringConcat2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringConcat2SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringConcat2SEL, _gPID)))

#define FSWideStringEmpty (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringEmptySELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringEmptySEL, _gPID)))

#define FSWideStringGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringGetAtSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringGetAtSEL, _gPID)))

#define FSWideStringSetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringSetAtSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringSetAtSEL, _gPID)))

#define FSWideStringInsert (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringInsertSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringInsertSEL, _gPID)))

#define FSWideStringDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringDeleteSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringDeleteSEL, _gPID)))

#define FSWideStringFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringFormatSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringFormatSEL, _gPID)))

#define FSWideStringReserve (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringReserveSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringReserveSEL, _gPID)))

#define FSWideStringMid (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringMidSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringMidSEL, _gPID)))

#define FSWideStringMid2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringMid2SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringMid2SEL, _gPID)))

#define FSWideStringLeft (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringLeftSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringLeftSEL, _gPID)))

#define FSWideStringRight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringRightSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringRightSEL, _gPID)))

#define FSWideStringFind (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringFindSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringFindSEL, _gPID)))

#define FSWideStringFind2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringFind2SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringFind2SEL, _gPID)))

#define FSWideStringMakeLower (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringMakeLowerSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringMakeLowerSEL, _gPID)))

#define FSWideStringMakeUpper (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringMakeUpperSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringMakeUpperSEL, _gPID)))

#define FSWideStringTrimRight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringTrimRightSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringTrimRightSEL, _gPID)))

#define FSWideStringTrimRight2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringTrimRight2SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringTrimRight2SEL, _gPID)))

#define FSWideStringTrimRight3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringTrimRight3SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringTrimRight3SEL, _gPID)))

#define FSWideStringTrimLeft (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringTrimLeftSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringTrimLeftSEL, _gPID)))

#define FSWideStringTrimLeft2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringTrimLeft2SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringTrimLeft2SEL, _gPID)))

#define FSWideStringTrimLeft3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringTrimLeft3SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringTrimLeft3SEL, _gPID)))

#define FSWideStringReplace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringReplaceSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringReplaceSEL, _gPID)))

#define FSWideStringRemove (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringRemoveSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringRemoveSEL, _gPID)))

#define FSWideStringGetInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringGetIntegerSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringGetIntegerSEL, _gPID)))

#define FSWideStringFromUTF8 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringFromUTF8SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringFromUTF8SEL, _gPID)))

#define FSWideStringFromUTF16LE (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringFromUTF16LESELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringFromUTF16LESEL, _gPID)))

#define FSWideStringUTF8Encode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringUTF8EncodeSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringUTF8EncodeSEL, _gPID)))

#define FSWideStringUTF16LE_Encode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringUTF16LE_EncodeSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringUTF16LE_EncodeSEL, _gPID)))

#define FSWideStringCastToLPCWSTR (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringCastToLPCWSTRSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringCastToLPCWSTRSEL, _gPID)))

#define FSWideStringFormatV (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringFormatVSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringFormatVSEL, _gPID)))

#define FSWideStringFromLocal (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringFromLocalSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringFromLocalSEL, _gPID)))

#define FSWideStringFromLocal2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringFromLocal2SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringFromLocal2SEL, _gPID)))

#define FSWideStringCompareNoCase (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringCompareNoCaseSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringCompareNoCaseSEL, _gPID)))

#define FSWideStringCompareNoCase2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringCompareNoCase2SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringCompareNoCase2SEL, _gPID)))

#define FSWideStringConvertFrom (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringConvertFromSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringConvertFromSEL, _gPID)))

#define FSWideStringFromLocal3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringFromLocal3SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringFromLocal3SEL, _gPID)))

#define FSWideStringGetFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringGetFloatSELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringGetFloatSEL, _gPID)))

#define FSWideStringFind3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringFind3SELPROTO)FRCOREROUTINE(FSWideStringSEL,FSWideStringFind3SEL, _gPID)))

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
/* UnicodeMgr HFT functions */
//*****************************

#define FSUnicodeMgrGetUnicodeGeneralCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUnicodeMgrGetUnicodeGeneralCategorySELPROTO)FRCOREROUTINE(FSUnicodeMgrSEL,FSUnicodeMgrGetUnicodeGeneralCategorySEL, _gPID)))

#define FSUnicodeMgrEastAsianWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUnicodeMgrEastAsianWidthSELPROTO)FRCOREROUTINE(FSUnicodeMgrSEL,FSUnicodeMgrEastAsianWidthSEL, _gPID)))

#define FSUnicodeMgrNFKD (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUnicodeMgrNFKDSELPROTO)FRCOREROUTINE(FSUnicodeMgrSEL,FSUnicodeMgrNFKDSEL, _gPID)))

//----------_V18----------
//----------_V19----------
//----------_V20----------
#ifdef __cplusplus
}
#endif

#endif
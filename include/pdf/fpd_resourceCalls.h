/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_RESOURCECALLS_H
#define FPD_RESOURCECALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_RESOURCEEXPT_H
#include "fpd_resourceExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_resourceImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_resourceTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_resourceImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_resourceTempl.h"

//----------_V1----------
//*****************************
/* Font HFT functions */
//*****************************

#define FPDFontNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontNewSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontNewSEL, _gPID)))

#define FPDFontDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontDestroySELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontDestroySEL, _gPID)))

#define FPDFontGetStockFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetStockFontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetStockFontSEL, _gPID)))

#define FPDFontGetFontType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetFontTypeSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetFontTypeSEL, _gPID)))

#define FPDFontGetFontTypeName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetFontTypeNameSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetFontTypeNameSEL, _gPID)))

#define FPDFontGetBaseFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetBaseFontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetBaseFontSEL, _gPID)))

#define FPDFontGetSubstFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetSubstFontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetSubstFontSEL, _gPID)))

#define FPDFontGetFlags (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetFlagsSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetFlagsSEL, _gPID)))

#define FPDFontGetType1Font (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetType1FontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetType1FontSEL, _gPID)))

#define FPDFontGetTrueTypeFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetTrueTypeFontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetTrueTypeFontSEL, _gPID)))

#define FPDFontGetCIDFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetCIDFontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetCIDFontSEL, _gPID)))

#define FPDFontGetType3Font (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetType3FontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetType3FontSEL, _gPID)))

#define FPDFontIsEmbedded (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontIsEmbeddedSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontIsEmbeddedSEL, _gPID)))

#define FPDFontIsUnicodeCompatible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontIsUnicodeCompatibleSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontIsUnicodeCompatibleSEL, _gPID)))

#define FPDFontGetFontFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetFontFileSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetFontFileSEL, _gPID)))

#define FPDFontGetFontDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetFontDictSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetFontDictSEL, _gPID)))

#define FPDFontIsStandardFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontIsStandardFontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontIsStandardFontSEL, _gPID)))

#define FPDFontGetFace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetFaceSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetFaceSEL, _gPID)))

#define FPDFontGetNextChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetNextCharSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetNextCharSEL, _gPID)))

#define FPDFontCountChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontCountCharSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontCountCharSEL, _gPID)))

#define FPDFontAppendChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontAppendCharSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontAppendCharSEL, _gPID)))

#define FPDFontAppendChar2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontAppendChar2SELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontAppendChar2SEL, _gPID)))

#define FPDFontGetCharSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetCharSizeSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetCharSizeSEL, _gPID)))

#define FPDFontGlyphFromCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGlyphFromCharCodeSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGlyphFromCharCodeSEL, _gPID)))

#define FPDFontUnicodeFromCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontUnicodeFromCharCodeSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontUnicodeFromCharCodeSEL, _gPID)))

#define FPDFontCharCodeFromUnicode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontCharCodeFromUnicodeSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontCharCodeFromUnicodeSEL, _gPID)))

#define FPDFontIsCharEmbedded (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontIsCharEmbeddedSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontIsCharEmbeddedSEL, _gPID)))

#define FPDFontGetCharMap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetCharMapSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetCharMapSEL, _gPID)))

#define FPDFontEncodeString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontEncodeStringSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontEncodeStringSEL, _gPID)))

#define FPDFontDecodeString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontDecodeStringSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontDecodeStringSEL, _gPID)))

#define FPDFontRecognizeChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontRecognizeCharSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontRecognizeCharSEL, _gPID)))

#define FPDFontGetFontBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetFontBBoxSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetFontBBoxSEL, _gPID)))

#define FPDFontGetTypeAscent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetTypeAscentSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetTypeAscentSEL, _gPID)))

#define FPDFontGetTypeDescent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetTypeDescentSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetTypeDescentSEL, _gPID)))

#define FPDFontGetItalicAngle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetItalicAngleSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetItalicAngleSEL, _gPID)))

#define FPDFontGetStringWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetStringWidthSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetStringWidthSEL, _gPID)))

#define FPDFontGetCharWidthF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetCharWidthFSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetCharWidthFSEL, _gPID)))

#define FPDFontGetCharTypeWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetCharTypeWidthSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetCharTypeWidthSEL, _gPID)))

#define FPDFontGetCharBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetCharBBoxSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetCharBBoxSEL, _gPID)))

#define FPDFontGetPDFDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetPDFDocSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetPDFDocSEL, _gPID)))

#define FPDFontLoadGlyphPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontLoadGlyphPathSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontLoadGlyphPathSEL, _gPID)))

#define FPDFontGetSubstFontCharset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetSubstFontCharsetSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetSubstFontCharsetSEL, _gPID)))

#define FPDFontIsVertWriting (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontIsVertWritingSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontIsVertWritingSEL, _gPID)))

#define FPDFontGetFXFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetFXFontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetFXFontSEL, _gPID)))

#define FPDFontFXFontGetFaceName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontFXFontGetFaceNameSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontFXFontGetFaceNameSEL, _gPID)))

#define FPDFontFXFontGetPsName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontFXFontGetPsNameSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontFXFontGetPsNameSEL, _gPID)))

#define FPDFontFXFontGetFamilyName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontFXFontGetFamilyNameSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontFXFontGetFamilyNameSEL, _gPID)))

#define FPDFontFXFontIsItalic (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontFXFontIsItalicSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontFXFontIsItalicSEL, _gPID)))

#define FPDFontFXFontIsBold (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontFXFontIsBoldSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontFXFontIsBoldSEL, _gPID)))

#define FPDFontUnicodeFromCharCodeEx (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontUnicodeFromCharCodeExSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontUnicodeFromCharCodeExSEL, _gPID)))

#define FPDFontGetSubstFontWeight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetSubstFontWeightSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetSubstFontWeightSEL, _gPID)))

#define FPDFontFXFontLoadSubst (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontFXFontLoadSubstSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontFXFontLoadSubstSEL, _gPID)))

#define FPDFontGetUnicodeBaseFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetUnicodeBaseFontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetUnicodeBaseFontSEL, _gPID)))

#define FPDFontIsTTFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontIsTTFontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontIsTTFontSEL, _gPID)))

#define FPDFontNewFXFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontNewFXFontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontNewFXFontSEL, _gPID)))

#define FPDFontDeleteFXFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontDeleteFXFontSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontDeleteFXFontSEL, _gPID)))

#define FPDFontGetCharOutBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontGetCharOutBBoxSELPROTO)FRCOREROUTINE(FPDFontSEL,FPDFontGetCharOutBBoxSEL, _gPID)))

//*****************************
/* FontEncoding HFT functions */
//*****************************

#define FPDFontEncodingNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontEncodingNewSELPROTO)FRCOREROUTINE(FPDFontEncodingSEL,FPDFontEncodingNewSEL, _gPID)))

#define FPDFontEncodingNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontEncodingNew2SELPROTO)FRCOREROUTINE(FPDFontEncodingSEL,FPDFontEncodingNew2SEL, _gPID)))

#define FPDFontEncodingDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontEncodingDestroySELPROTO)FRCOREROUTINE(FPDFontEncodingSEL,FPDFontEncodingDestroySEL, _gPID)))

#define FPDFontEncodingLoadEncoding (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontEncodingLoadEncodingSELPROTO)FRCOREROUTINE(FPDFontEncodingSEL,FPDFontEncodingLoadEncodingSEL, _gPID)))

#define FPDFontEncodingIsIdentical (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontEncodingIsIdenticalSELPROTO)FRCOREROUTINE(FPDFontEncodingSEL,FPDFontEncodingIsIdenticalSEL, _gPID)))

#define FPDFontEncodingUnicodeFromCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontEncodingUnicodeFromCharCodeSELPROTO)FRCOREROUTINE(FPDFontEncodingSEL,FPDFontEncodingUnicodeFromCharCodeSEL, _gPID)))

#define FPDFontEncodingCharCodeFromUnicode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontEncodingCharCodeFromUnicodeSELPROTO)FRCOREROUTINE(FPDFontEncodingSEL,FPDFontEncodingCharCodeFromUnicodeSEL, _gPID)))

#define FPDFontEncodingSetUnicode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontEncodingSetUnicodeSELPROTO)FRCOREROUTINE(FPDFontEncodingSEL,FPDFontEncodingSetUnicodeSEL, _gPID)))

#define FPDFontEncodingRealize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFontEncodingRealizeSELPROTO)FRCOREROUTINE(FPDFontEncodingSEL,FPDFontEncodingRealizeSEL, _gPID)))

//*****************************
/* Type1Font HFT functions */
//*****************************

#define FPDType1FontNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType1FontNewSELPROTO)FRCOREROUTINE(FPDType1FontSEL,FPDType1FontNewSEL, _gPID)))

#define FPDType1FontDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType1FontDestroySELPROTO)FRCOREROUTINE(FPDType1FontSEL,FPDType1FontDestroySEL, _gPID)))

#define FPDType1FontGetEncoding (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType1FontGetEncodingSELPROTO)FRCOREROUTINE(FPDType1FontSEL,FPDType1FontGetEncodingSEL, _gPID)))

#define FPDType1FontGetCharWidthF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType1FontGetCharWidthFSELPROTO)FRCOREROUTINE(FPDType1FontSEL,FPDType1FontGetCharWidthFSEL, _gPID)))

#define FPDType1FontGetCharBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType1FontGetCharBBoxSELPROTO)FRCOREROUTINE(FPDType1FontSEL,FPDType1FontGetCharBBoxSEL, _gPID)))

#define FPDType1FontGlyphFromCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType1FontGlyphFromCharCodeSELPROTO)FRCOREROUTINE(FPDType1FontSEL,FPDType1FontGlyphFromCharCodeSEL, _gPID)))

#define FPDType1FontIsUnicodeCompatible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType1FontIsUnicodeCompatibleSELPROTO)FRCOREROUTINE(FPDType1FontSEL,FPDType1FontIsUnicodeCompatibleSEL, _gPID)))

#define FPDType1FontGetBase14Font (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType1FontGetBase14FontSELPROTO)FRCOREROUTINE(FPDType1FontSEL,FPDType1FontGetBase14FontSEL, _gPID)))

//*****************************
/* TrueTypeFont HFT functions */
//*****************************

#define FPDTrueTypeFontNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTrueTypeFontNewSELPROTO)FRCOREROUTINE(FPDTrueTypeFontSEL,FPDTrueTypeFontNewSEL, _gPID)))

#define FPDTrueTypeFontDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTrueTypeFontDestroySELPROTO)FRCOREROUTINE(FPDTrueTypeFontSEL,FPDTrueTypeFontDestroySEL, _gPID)))

#define FPDTrueTypeFontGetEncoding (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTrueTypeFontGetEncodingSELPROTO)FRCOREROUTINE(FPDTrueTypeFontSEL,FPDTrueTypeFontGetEncodingSEL, _gPID)))

#define FPDTrueTypeFontGetCharWidthF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTrueTypeFontGetCharWidthFSELPROTO)FRCOREROUTINE(FPDTrueTypeFontSEL,FPDTrueTypeFontGetCharWidthFSEL, _gPID)))

#define FPDTrueTypeFontGetCharBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTrueTypeFontGetCharBBoxSELPROTO)FRCOREROUTINE(FPDTrueTypeFontSEL,FPDTrueTypeFontGetCharBBoxSEL, _gPID)))

#define FPDTrueTypeFontGlyphFromCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTrueTypeFontGlyphFromCharCodeSELPROTO)FRCOREROUTINE(FPDTrueTypeFontSEL,FPDTrueTypeFontGlyphFromCharCodeSEL, _gPID)))

#define FPDTrueTypeFontIsUnicodeCompatible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTrueTypeFontIsUnicodeCompatibleSELPROTO)FRCOREROUTINE(FPDTrueTypeFontSEL,FPDTrueTypeFontIsUnicodeCompatibleSEL, _gPID)))

//*****************************
/* Type3Char HFT functions */
//*****************************

#define FPDType3CharNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3CharNewSELPROTO)FRCOREROUTINE(FPDType3CharSEL,FPDType3CharNewSEL, _gPID)))

#define FPDType3CharDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3CharDestroySELPROTO)FRCOREROUTINE(FPDType3CharSEL,FPDType3CharDestroySEL, _gPID)))

#define FPDType3CharIsColored (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3CharIsColoredSELPROTO)FRCOREROUTINE(FPDType3CharSEL,FPDType3CharIsColoredSEL, _gPID)))

#define FPDType3CharIsPageRequired (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3CharIsPageRequiredSELPROTO)FRCOREROUTINE(FPDType3CharSEL,FPDType3CharIsPageRequiredSEL, _gPID)))

#define FPDType3CharGetForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3CharGetFormSELPROTO)FRCOREROUTINE(FPDType3CharSEL,FPDType3CharGetFormSEL, _gPID)))

#define FPDType3CharGetImageMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3CharGetImageMatrixSELPROTO)FRCOREROUTINE(FPDType3CharSEL,FPDType3CharGetImageMatrixSEL, _gPID)))

#define FPDType3CharGetDIBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3CharGetDIBitmapSELPROTO)FRCOREROUTINE(FPDType3CharSEL,FPDType3CharGetDIBitmapSEL, _gPID)))

#define FPDType3CharGetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3CharGetWidthSELPROTO)FRCOREROUTINE(FPDType3CharSEL,FPDType3CharGetWidthSEL, _gPID)))

#define FPDType3CharGetBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3CharGetBBoxSELPROTO)FRCOREROUTINE(FPDType3CharSEL,FPDType3CharGetBBoxSEL, _gPID)))

//*****************************
/* Type3Font HFT functions */
//*****************************

#define FPDType3FontNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3FontNewSELPROTO)FRCOREROUTINE(FPDType3FontSEL,FPDType3FontNewSEL, _gPID)))

#define FPDType3FontDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3FontDestroySELPROTO)FRCOREROUTINE(FPDType3FontSEL,FPDType3FontDestroySEL, _gPID)))

#define FPDType3FontGetEncoding (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3FontGetEncodingSELPROTO)FRCOREROUTINE(FPDType3FontSEL,FPDType3FontGetEncodingSEL, _gPID)))

#define FPDType3FontGetCharWidthF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3FontGetCharWidthFSELPROTO)FRCOREROUTINE(FPDType3FontSEL,FPDType3FontGetCharWidthFSEL, _gPID)))

#define FPDType3FontGetCharBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3FontGetCharBBoxSELPROTO)FRCOREROUTINE(FPDType3FontSEL,FPDType3FontGetCharBBoxSEL, _gPID)))

#define FPDType3FontGlyphFromCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3FontGlyphFromCharCodeSELPROTO)FRCOREROUTINE(FPDType3FontSEL,FPDType3FontGlyphFromCharCodeSEL, _gPID)))

#define FPDType3FontIsUnicodeCompatible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3FontIsUnicodeCompatibleSELPROTO)FRCOREROUTINE(FPDType3FontSEL,FPDType3FontIsUnicodeCompatibleSEL, _gPID)))

#define FPDType3FontSetPageResources (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3FontSetPageResourcesSELPROTO)FRCOREROUTINE(FPDType3FontSEL,FPDType3FontSetPageResourcesSEL, _gPID)))

#define FPDType3FontLoadChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3FontLoadCharSELPROTO)FRCOREROUTINE(FPDType3FontSEL,FPDType3FontLoadCharSEL, _gPID)))

#define FPDType3FontGetCharTypeWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3FontGetCharTypeWidthSELPROTO)FRCOREROUTINE(FPDType3FontSEL,FPDType3FontGetCharTypeWidthSEL, _gPID)))

#define FPDType3FontGetFontMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDType3FontGetFontMatrixSELPROTO)FRCOREROUTINE(FPDType3FontSEL,FPDType3FontGetFontMatrixSEL, _gPID)))

//*****************************
/* CIDFont HFT functions */
//*****************************

#define FPDCIDFontNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontNewSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontNewSEL, _gPID)))

#define FPDCIDFontDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontDestroySELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontDestroySEL, _gPID)))

#define FPDCIDFontGetCharWidthF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontGetCharWidthFSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontGetCharWidthFSEL, _gPID)))

#define FPDCIDFontGetCharBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontGetCharBBoxSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontGetCharBBoxSEL, _gPID)))

#define FPDCIDFontGlyphFromCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontGlyphFromCharCodeSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontGlyphFromCharCodeSEL, _gPID)))

#define FPDCIDFontIsUnicodeCompatible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontIsUnicodeCompatibleSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontIsUnicodeCompatibleSEL, _gPID)))

#define FPDCIDFontGetNextChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontGetNextCharSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontGetNextCharSEL, _gPID)))

#define FPDCIDFontCountChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontCountCharSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontCountCharSEL, _gPID)))

#define FPDCIDFontAppendChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontAppendCharSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontAppendCharSEL, _gPID)))

#define FPDCIDFontGetCharSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontGetCharSizeSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontGetCharSizeSEL, _gPID)))

#define FPDCIDFontLoadGB2312 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontLoadGB2312SELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontLoadGB2312SEL, _gPID)))

#define FPDCIDFontCIDFromCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontCIDFromCharCodeSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontCIDFromCharCodeSEL, _gPID)))

#define FPDCIDFontIsTrueType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontIsTrueTypeSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontIsTrueTypeSEL, _gPID)))

#define FPDCIDFontGetCharset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontGetCharsetSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontGetCharsetSEL, _gPID)))

#define FPDCIDFontGetCIDTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontGetCIDTransformSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontGetCIDTransformSEL, _gPID)))

#define FPDCIDFontIsVertWriting (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontIsVertWritingSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontIsVertWritingSEL, _gPID)))

#define FPDCIDFontGetVertWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontGetVertWidthSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontGetVertWidthSEL, _gPID)))

#define FPDCIDFontGetVertOrigin (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDFontGetVertOriginSELPROTO)FRCOREROUTINE(FPDCIDFontSEL,FPDCIDFontGetVertOriginSEL, _gPID)))

//*****************************
/* CIDUtil HFT functions */
//*****************************

#define FPDCIDUtilIsVerticalJapanCID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDCIDUtilIsVerticalJapanCIDSELPROTO)FRCOREROUTINE(FPDCIDUtilSEL,FPDCIDUtilIsVerticalJapanCIDSEL, _gPID)))

//*****************************
/* ColorSpace HFT functions */
//*****************************

#define FPDColorSpaceGetStockCS (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceGetStockCSSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceGetStockCSSEL, _gPID)))

#define FPDColorSpaceLoad (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceLoadSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceLoadSEL, _gPID)))

#define FPDColorSpaceReleaseCS (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceReleaseCSSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceReleaseCSSEL, _gPID)))

#define FPDColorSpaceGetBufSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceGetBufSizeSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceGetBufSizeSEL, _gPID)))

#define FPDColorSpaceCreateBuf (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceCreateBufSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceCreateBufSEL, _gPID)))

#define FPDColorSpaceGetDefaultColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceGetDefaultColorSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceGetDefaultColorSEL, _gPID)))

#define FPDColorSpaceCountComponents (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceCountComponentsSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceCountComponentsSEL, _gPID)))

#define FPDColorSpaceGetFamily (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceGetFamilySELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceGetFamilySEL, _gPID)))

#define FPDColorSpaceGetDefaultValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceGetDefaultValueSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceGetDefaultValueSEL, _gPID)))

#define FPDColorSpacesRGB (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpacesRGBSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpacesRGBSEL, _gPID)))

#define FPDColorSpaceGetRGB (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceGetRGBSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceGetRGBSEL, _gPID)))

#define FPDColorSpaceSetRGB (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceSetRGBSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceSetRGBSEL, _gPID)))

#define FPDColorSpaceGetCMYK (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceGetCMYKSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceGetCMYKSEL, _gPID)))

#define FPDColorSpaceSetCMYK (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceSetCMYKSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceSetCMYKSEL, _gPID)))

#define FPDColorSpaceTranslateImageLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceTranslateImageLineSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceTranslateImageLineSEL, _gPID)))

#define FPDColorSpaceGetArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceGetArraySELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceGetArraySEL, _gPID)))

#define FPDColorSpaceGetMaxIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceGetMaxIndexSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceGetMaxIndexSEL, _gPID)))

#define FPDColorSpaceGetBaseCS (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSpaceGetBaseCSSELPROTO)FRCOREROUTINE(FPDColorSpaceSEL,FPDColorSpaceGetBaseCSSEL, _gPID)))

//*****************************
/* Color HFT functions */
//*****************************

#define FPDColorNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorNewSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorNewSEL, _gPID)))

#define FPDColorDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorDestroySELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorDestroySEL, _gPID)))

#define FPDColorIsNull (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorIsNullSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorIsNullSEL, _gPID)))

#define FPDColorIsEqual (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorIsEqualSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorIsEqualSEL, _gPID)))

#define FPDColorIsPattern (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorIsPatternSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorIsPatternSEL, _gPID)))

#define FPDColorCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorCopySELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorCopySEL, _gPID)))

#define FPDColorSetColorSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSetColorSpaceSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorSetColorSpaceSEL, _gPID)))

#define FPDColorGetColorSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorGetColorSpaceSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorGetColorSpaceSEL, _gPID)))

#define FPDColorSetValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSetValueSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorSetValueSEL, _gPID)))

#define FPDColorSetValue2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorSetValue2SELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorSetValue2SEL, _gPID)))

#define FPDColorGetRGB (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorGetRGBSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorGetRGBSEL, _gPID)))

#define FPDColorGetPattern (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorGetPatternSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorGetPatternSEL, _gPID)))

#define FPDColorGetPatternCS (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorGetPatternCSSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorGetPatternCSSEL, _gPID)))

#define FPDColorGetPatternColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorGetPatternColorSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorGetPatternColorSEL, _gPID)))

#define FPDColorGetColorBuffer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorGetColorBufferSELPROTO)FRCOREROUTINE(FPDColorSEL,FPDColorGetColorBufferSEL, _gPID)))

//*****************************
/* Pattern HFT functions */
//*****************************

#define FPDPatternDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPatternDestroySELPROTO)FRCOREROUTINE(FPDPatternSEL,FPDPatternDestroySEL, _gPID)))

#define FPDPatternGetPatternObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPatternGetPatternObjSELPROTO)FRCOREROUTINE(FPDPatternSEL,FPDPatternGetPatternObjSEL, _gPID)))

#define FPDPatternGetPatternType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPatternGetPatternTypeSELPROTO)FRCOREROUTINE(FPDPatternSEL,FPDPatternGetPatternTypeSEL, _gPID)))

#define FPDPatternGetPatternMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPatternGetPatternMatrixSELPROTO)FRCOREROUTINE(FPDPatternSEL,FPDPatternGetPatternMatrixSEL, _gPID)))

#define FPDPatternGetPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPatternGetPDDocSELPROTO)FRCOREROUTINE(FPDPatternSEL,FPDPatternGetPDDocSEL, _gPID)))

#define FPDPatternCastToShadingPatternObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPatternCastToShadingPatternObjSELPROTO)FRCOREROUTINE(FPDPatternSEL,FPDPatternCastToShadingPatternObjSEL, _gPID)))

#define FPDPatternCastToTilingPatternObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPatternCastToTilingPatternObjSELPROTO)FRCOREROUTINE(FPDPatternSEL,FPDPatternCastToTilingPatternObjSEL, _gPID)))

//*****************************
/* TilingPattern HFT functions */
//*****************************

#define FPDTilingPatternNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternNewSELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternNewSEL, _gPID)))

#define FPDTilingPatternDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternDestroySELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternDestroySEL, _gPID)))

#define FPDTilingPatternGetPatternObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternGetPatternObjSELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternGetPatternObjSEL, _gPID)))

#define FPDTilingPatternGetPatternType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternGetPatternTypeSELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternGetPatternTypeSEL, _gPID)))

#define FPDTilingPatternGetPatternMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternGetPatternMatrixSELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternGetPatternMatrixSEL, _gPID)))

#define FPDTilingPatternGetPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternGetPDDocSELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternGetPDDocSEL, _gPID)))

#define FPDTilingPatternLoad (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternLoadSELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternLoadSEL, _gPID)))

#define FPDTilingPatternIsColored (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternIsColoredSELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternIsColoredSEL, _gPID)))

#define FPDTilingPatternGetBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternGetBBoxSELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternGetBBoxSEL, _gPID)))

#define FPDTilingPatternGetXStep (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternGetXStepSELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternGetXStepSEL, _gPID)))

#define FPDTilingPatternGetYStep (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternGetYStepSELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternGetYStepSEL, _gPID)))

#define FPDTilingPatternGetForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternGetFormSELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternGetFormSEL, _gPID)))

#define FPDTilingPatternNewII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTilingPatternNewIISELPROTO)FRCOREROUTINE(FPDTilingPatternSEL,FPDTilingPatternNewIISEL, _gPID)))

//*****************************
/* ShadingPattern HFT functions */
//*****************************

#define FPDShadingPatternNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternNewSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternNewSEL, _gPID)))

#define FPDShadingPatternDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternDestroySELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternDestroySEL, _gPID)))

#define FPDShadingPatternGetPatternObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternGetPatternObjSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternGetPatternObjSEL, _gPID)))

#define FPDShadingPatternGetPatternType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternGetPatternTypeSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternGetPatternTypeSEL, _gPID)))

#define FPDShadingPatternGetPatternMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternGetPatternMatrixSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternGetPatternMatrixSEL, _gPID)))

#define FPDShadingPatternGetPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternGetPDDocSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternGetPDDocSEL, _gPID)))

#define FPDShadingPatternLoad (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternLoadSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternLoadSEL, _gPID)))

#define FPDShadingPatternReLoad (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternReLoadSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternReLoadSEL, _gPID)))

#define FPDShadingPatternGetColorSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternGetColorSpaceSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternGetColorSpaceSEL, _gPID)))

#define FPDShadingPatternGetFunc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternGetFuncSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternGetFuncSEL, _gPID)))

#define FPDShadingPatternGetFuncsCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternGetFuncsCountSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternGetFuncsCountSEL, _gPID)))

#define FPDShadingPatternSetColorSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternSetColorSpaceSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternSetColorSpaceSEL, _gPID)))

#define FPDShadingPatternGetShadingObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDShadingPatternGetShadingObjectSELPROTO)FRCOREROUTINE(FPDShadingPatternSEL,FPDShadingPatternGetShadingObjectSEL, _gPID)))

//*****************************
/* MeshStream HFT functions */
//*****************************

#define FPDMeshStreamNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMeshStreamNewSELPROTO)FRCOREROUTINE(FPDMeshStreamSEL,FPDMeshStreamNewSEL, _gPID)))

#define FPDMeshStreamDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMeshStreamDestroySELPROTO)FRCOREROUTINE(FPDMeshStreamSEL,FPDMeshStreamDestroySEL, _gPID)))

#define FPDMeshStreamGetFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMeshStreamGetFlagSELPROTO)FRCOREROUTINE(FPDMeshStreamSEL,FPDMeshStreamGetFlagSEL, _gPID)))

#define FPDMeshStreamGetCoords (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMeshStreamGetCoordsSELPROTO)FRCOREROUTINE(FPDMeshStreamSEL,FPDMeshStreamGetCoordsSEL, _gPID)))

#define FPDMeshStreamGetColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMeshStreamGetColorSELPROTO)FRCOREROUTINE(FPDMeshStreamSEL,FPDMeshStreamGetColorSEL, _gPID)))

#define FPDMeshStreamGetVertex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMeshStreamGetVertexSELPROTO)FRCOREROUTINE(FPDMeshStreamSEL,FPDMeshStreamGetVertexSEL, _gPID)))

#define FPDMeshStreamGetVertexRow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMeshStreamGetVertexRowSELPROTO)FRCOREROUTINE(FPDMeshStreamSEL,FPDMeshStreamGetVertexRowSEL, _gPID)))

//*****************************
/* Image HFT functions */
//*****************************

#define FPDImageNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageNewSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageNewSEL, _gPID)))

#define FPDImageDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageDestroySELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageDestroySEL, _gPID)))

#define FPDImageLoadImageF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageLoadImageFSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageLoadImageFSEL, _gPID)))

#define FPDImageClone (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageCloneSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageCloneSEL, _gPID)))

#define FPDImageGetStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetStreamSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetStreamSEL, _gPID)))

#define FPDImageGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetDictSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetDictSEL, _gPID)))

#define FPDImageGetOC (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetOCSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetOCSEL, _gPID)))

#define FPDImageGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetDocumentSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetDocumentSEL, _gPID)))

#define FPDImageGetPixelHeight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetPixelHeightSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetPixelHeightSEL, _gPID)))

#define FPDImageGetPixelWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetPixelWidthSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetPixelWidthSEL, _gPID)))

#define FPDImageIsMask (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageIsMaskSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageIsMaskSEL, _gPID)))

#define FPDImageIsInterpol (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageIsInterpolSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageIsInterpolSEL, _gPID)))

#define FPDImageLoadDIBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageLoadDIBitmapSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageLoadDIBitmapSEL, _gPID)))

#define FPDImageSetImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageSetImageSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageSetImageSEL, _gPID)))

#define FPDImageSetJpegImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageSetJpegImageSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageSetJpegImageSEL, _gPID)))

#define FPDImageResetCache (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageResetCacheSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageResetCacheSEL, _gPID)))

#define FPDImageLoadDIBitmapProgressive (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageLoadDIBitmapProgressiveSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageLoadDIBitmapProgressiveSEL, _gPID)))

#define FPDImageGetDIBSource (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetDIBSourceSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetDIBSourceSEL, _gPID)))

#define FPDImageGetMask (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetMaskSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetMaskSEL, _gPID)))

#define FPDImageGetMatteColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetMatteColorSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetMatteColorSEL, _gPID)))

#define FPDImageSetImage2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageSetImage2SELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageSetImage2SEL, _gPID)))

#define FPDImageDetachBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageDetachBitmapSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageDetachBitmapSEL, _gPID)))

#define FPDImageDetachMask (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageDetachMaskSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageDetachMaskSEL, _gPID)))

#define FPDImageGetInlineDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetInlineDictSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetInlineDictSEL, _gPID)))

#define FPDImageGetDIBSource2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetDIBSource2SELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetDIBSource2SEL, _gPID)))

#define FPDImageGetMask2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageGetMask2SELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageGetMask2SEL, _gPID)))

#define FPDImageDetachBitmap2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageDetachBitmap2SELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageDetachBitmap2SEL, _gPID)))

#define FPDImageDetachMask2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageDetachMask2SELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageDetachMask2SEL, _gPID)))

#define FPDImageLoadDIBitmap2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageLoadDIBitmap2SELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageLoadDIBitmap2SEL, _gPID)))

#define FPDImageIsInline (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageIsInlineSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageIsInlineSEL, _gPID)))

#define FPDImageRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageReleaseSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageReleaseSEL, _gPID)))

#define FPDImageSetJpegImage2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageSetJpegImage2SELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageSetJpegImage2SEL, _gPID)))

#define FPDImageSetPngFileRead (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDImageSetPngFileReadSELPROTO)FRCOREROUTINE(FPDImageSEL,FPDImageSetPngFileReadSEL, _gPID)))

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* FXFontEncoding HFT functions */
//*****************************

#define FPDFXFontEncodingNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXFontEncodingNewSELPROTO)FRCOREROUTINE(FPDFXFontEncodingSEL,FPDFXFontEncodingNewSEL, _gPID)))

#define FPDFXFontEncodingDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXFontEncodingDestroySELPROTO)FRCOREROUTINE(FPDFXFontEncodingSEL,FPDFXFontEncodingDestroySEL, _gPID)))

#define FPDFXFontEncodingGlyphFromCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXFontEncodingGlyphFromCharCodeSELPROTO)FRCOREROUTINE(FPDFXFontEncodingSEL,FPDFXFontEncodingGlyphFromCharCodeSEL, _gPID)))

#define FPDFXFontEncodingUnicodeFromCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXFontEncodingUnicodeFromCharCodeSELPROTO)FRCOREROUTINE(FPDFXFontEncodingSEL,FPDFXFontEncodingUnicodeFromCharCodeSEL, _gPID)))

#define FPDFXFontEncodingCharCodeFromUnicode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXFontEncodingCharCodeFromUnicodeSELPROTO)FRCOREROUTINE(FPDFXFontEncodingSEL,FPDFXFontEncodingCharCodeFromUnicodeSEL, _gPID)))

#define FPDFXFontEncodingIsUnicodeCompatible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXFontEncodingIsUnicodeCompatibleSELPROTO)FRCOREROUTINE(FPDFXFontEncodingSEL,FPDFXFontEncodingIsUnicodeCompatibleSEL, _gPID)))

#define FPDFXFontEncodingGlyphFromCharCodeEx (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFXFontEncodingGlyphFromCharCodeExSELPROTO)FRCOREROUTINE(FPDFXFontEncodingSEL,FPDFXFontEncodingGlyphFromCharCodeExSEL, _gPID)))

//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
//----------_V11----------
//*****************************
/* ColorConvertor HFT functions */
//*****************************

#define FPDColorConvertorNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorConvertorNewSELPROTO)FRCOREROUTINE(FPDColorConvertorSEL,FPDColorConvertorNewSEL, _gPID)))

#define FPDColorConvertorDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorConvertorDestroySELPROTO)FRCOREROUTINE(FPDColorConvertorSEL,FPDColorConvertorDestroySEL, _gPID)))

#define FPDColorConvertorSetICCProfilesPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorConvertorSetICCProfilesPathSELPROTO)FRCOREROUTINE(FPDColorConvertorSEL,FPDColorConvertorSetICCProfilesPathSEL, _gPID)))

#define FPDColorConvertorGetObjColorSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorConvertorGetObjColorSpaceSELPROTO)FRCOREROUTINE(FPDColorConvertorSEL,FPDColorConvertorGetObjColorSpaceSEL, _gPID)))

#define FPDColorConvertorIsCalibrateColorSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorConvertorIsCalibrateColorSpaceSELPROTO)FRCOREROUTINE(FPDColorConvertorSEL,FPDColorConvertorIsCalibrateColorSpaceSEL, _gPID)))

#define FPDColorConvertorDecalibrateColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorConvertorDecalibrateColorSELPROTO)FRCOREROUTINE(FPDColorConvertorSEL,FPDColorConvertorDecalibrateColorSEL, _gPID)))

#define FPDColorConvertorConvertColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDColorConvertorConvertColorSELPROTO)FRCOREROUTINE(FPDColorConvertorSEL,FPDColorConvertorConvertColorSEL, _gPID)))

//----------_V12----------
//----------_V13----------
//----------_V14----------
//*****************************
/* OutputPreview HFT functions */
//*****************************

//*****************************
/* ImageSetParam HFT functions */
//*****************************

//*****************************
/* Type3FontDict HFT functions */
//*****************************

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
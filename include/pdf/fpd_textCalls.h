/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_TEXTCALLS_H
#define FPD_TEXTCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_TEXTEXPT_H
#include "fpd_textExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_textImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_textTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_textImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_textTempl.h"

//----------_V1----------
//*****************************
/* ProgressiveSearch HFT functions */
//*****************************

#define FPDProgressiveSearchNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveSearchNewSELPROTO)FRCOREROUTINE(FPDProgressiveSearchSEL,FPDProgressiveSearchNewSEL, _gPID)))

#define FPDProgressiveSearchDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveSearchDestroySELPROTO)FRCOREROUTINE(FPDProgressiveSearchSEL,FPDProgressiveSearchDestroySEL, _gPID)))

#define FPDProgressiveSearchGetStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveSearchGetStatusSELPROTO)FRCOREROUTINE(FPDProgressiveSearchSEL,FPDProgressiveSearchGetStatusSEL, _gPID)))

#define FPDProgressiveSearchFindFrom (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveSearchFindFromSELPROTO)FRCOREROUTINE(FPDProgressiveSearchSEL,FPDProgressiveSearchFindFromSEL, _gPID)))

#define FPDProgressiveSearchContinue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveSearchContinueSELPROTO)FRCOREROUTINE(FPDProgressiveSearchSEL,FPDProgressiveSearchContinueSEL, _gPID)))

#define FPDProgressiveSearchFindNext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveSearchFindNextSELPROTO)FRCOREROUTINE(FPDProgressiveSearchSEL,FPDProgressiveSearchFindNextSEL, _gPID)))

#define FPDProgressiveSearchFindPrev (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveSearchFindPrevSELPROTO)FRCOREROUTINE(FPDProgressiveSearchSEL,FPDProgressiveSearchFindPrevSEL, _gPID)))

#define FPDProgressiveSearchCountRects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveSearchCountRectsSELPROTO)FRCOREROUTINE(FPDProgressiveSearchSEL,FPDProgressiveSearchCountRectsSEL, _gPID)))

#define FPDProgressiveSearchGetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveSearchGetRectSELPROTO)FRCOREROUTINE(FPDProgressiveSearchSEL,FPDProgressiveSearchGetRectSEL, _gPID)))

#define FPDProgressiveSearchGetPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDProgressiveSearchGetPosSELPROTO)FRCOREROUTINE(FPDProgressiveSearchSEL,FPDProgressiveSearchGetPosSEL, _gPID)))

//*****************************
/* TextPage HFT functions */
//*****************************

#define FPDTextPageNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageNewSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageNewSEL, _gPID)))

#define FPDTextPageDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageDestroySELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageDestroySEL, _gPID)))

#define FPDTextPageParseTextPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageParseTextPageSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageParseTextPageSEL, _gPID)))

#define FPDTextPageIsParsered (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageIsParseredSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageIsParseredSEL, _gPID)))

#define FPDTextPageCountChars (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageCountCharsSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageCountCharsSEL, _gPID)))

#define FPDTextPageGetCharInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetCharInfoSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetCharInfoSEL, _gPID)))

#define FPDTextPageGetRectArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetRectArraySELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetRectArraySEL, _gPID)))

#define FPDTextPageGetIndexAtPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetIndexAtPosSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetIndexAtPosSEL, _gPID)))

#define FPDTextPageGetOrderByDirection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetOrderByDirectionSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetOrderByDirectionSEL, _gPID)))

#define FPDTextPageGetTextByRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetTextByRectSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetTextByRectSEL, _gPID)))

#define FPDTextPageGetRectsArrayByRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetRectsArrayByRectSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetRectsArrayByRectSEL, _gPID)))

#define FPDTextPageCountRects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageCountRectsSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageCountRectsSEL, _gPID)))

#define FPDTextPageGetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetRectSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetRectSEL, _gPID)))

#define FPDTextPageCountBoundedSegments (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageCountBoundedSegmentsSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageCountBoundedSegmentsSEL, _gPID)))

#define FPDTextPageGetBoundedSegment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetBoundedSegmentSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetBoundedSegmentSEL, _gPID)))

#define FPDTextPageGetWordBreak (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetWordBreakSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetWordBreakSEL, _gPID)))

#define FPDTextPageGetPageText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetPageTextSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetPageTextSEL, _gPID)))

#define FPDTextPageGetUnicodeProperties (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetUnicodePropertiesSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetUnicodePropertiesSEL, _gPID)))

#define FPDTextPageNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageNew2SELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageNew2SEL, _gPID)))

#define FPDTextPageNew3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageNew3SELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageNew3SEL, _gPID)))

#define FPDTextPageGetRectArray2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetRectArray2SELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetRectArray2SEL, _gPID)))

#define FPDTextPageCharIndexFromTextIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageCharIndexFromTextIndexSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageCharIndexFromTextIndexSEL, _gPID)))

#define FPDTextPageTextIndexFromCharIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageTextIndexFromCharIndexSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageTextIndexFromCharIndexSEL, _gPID)))

#define FPDTextPageGetRectArrayPathData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageGetRectArrayPathDataSELPROTO)FRCOREROUTINE(FPDTextPageSEL,FPDTextPageGetRectArrayPathDataSEL, _gPID)))

//*****************************
/* TextPageFind HFT functions */
//*****************************

#define FPDTextPageFindNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageFindNewSELPROTO)FRCOREROUTINE(FPDTextPageFindSEL,FPDTextPageFindNewSEL, _gPID)))

#define FPDTextPageFindDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageFindDestroySELPROTO)FRCOREROUTINE(FPDTextPageFindSEL,FPDTextPageFindDestroySEL, _gPID)))

#define FPDTextPageFindFindFirst (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageFindFindFirstSELPROTO)FRCOREROUTINE(FPDTextPageFindSEL,FPDTextPageFindFindFirstSEL, _gPID)))

#define FPDTextPageFindFindNext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageFindFindNextSELPROTO)FRCOREROUTINE(FPDTextPageFindSEL,FPDTextPageFindFindNextSEL, _gPID)))

#define FPDTextPageFindFindPrev (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageFindFindPrevSELPROTO)FRCOREROUTINE(FPDTextPageFindSEL,FPDTextPageFindFindPrevSEL, _gPID)))

#define FPDTextPageFindGetRectArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageFindGetRectArraySELPROTO)FRCOREROUTINE(FPDTextPageFindSEL,FPDTextPageFindGetRectArraySEL, _gPID)))

#define FPDTextPageFindGetCurOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageFindGetCurOrderSELPROTO)FRCOREROUTINE(FPDTextPageFindSEL,FPDTextPageFindGetCurOrderSEL, _gPID)))

#define FPDTextPageFindGetMatchedCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageFindGetMatchedCountSELPROTO)FRCOREROUTINE(FPDTextPageFindSEL,FPDTextPageFindGetMatchedCountSEL, _gPID)))

#define FPDTextPageFindGetRectPathData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageFindGetRectPathDataSELPROTO)FRCOREROUTINE(FPDTextPageFindSEL,FPDTextPageFindGetRectPathDataSEL, _gPID)))

#define FPDTextPageFindReleasePathData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDTextPageFindReleasePathDataSELPROTO)FRCOREROUTINE(FPDTextPageFindSEL,FPDTextPageFindReleasePathDataSEL, _gPID)))

//*****************************
/* LinkExtract HFT functions */
//*****************************

#define FPDLinkExtractNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkExtractNewSELPROTO)FRCOREROUTINE(FPDLinkExtractSEL,FPDLinkExtractNewSEL, _gPID)))

#define FPDLinkExtractDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkExtractDestroySELPROTO)FRCOREROUTINE(FPDLinkExtractSEL,FPDLinkExtractDestroySEL, _gPID)))

#define FPDLinkExtractExtractLinks (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkExtractExtractLinksSELPROTO)FRCOREROUTINE(FPDLinkExtractSEL,FPDLinkExtractExtractLinksSEL, _gPID)))

#define FPDLinkExtractCountLinks (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkExtractCountLinksSELPROTO)FRCOREROUTINE(FPDLinkExtractSEL,FPDLinkExtractCountLinksSEL, _gPID)))

#define FPDLinkExtractGetURL (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkExtractGetURLSELPROTO)FRCOREROUTINE(FPDLinkExtractSEL,FPDLinkExtractGetURLSEL, _gPID)))

#define FPDLinkExtractGetRects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkExtractGetRectsSELPROTO)FRCOREROUTINE(FPDLinkExtractSEL,FPDLinkExtractGetRectsSEL, _gPID)))

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
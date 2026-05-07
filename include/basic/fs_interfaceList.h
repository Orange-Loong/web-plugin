/*****************************************************************************

Copyright (C) 2024 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

// Auto Generator Code Start, Please don't edit this file!
#ifndef FS_INTERFACELIST_H_
#define FS_INTERFACELIST_H_

#ifdef _DEBUG

struct InterfaceInfo
{
	int nCategoryIndex;
	int nInterfaceIndex;
	LPCWSTR lpwsName;
};

InterfaceInfo _gInterfaceInfoArray[] = {
//----------_V1----------
// In file fs_basicImpl.h
	{FSExtensionHFTMgrSEL, FSExtensionHFTMgrNewHFTSEL, L"FSExtensionHFTMgrNewHFT"},
	{FSExtensionHFTMgrSEL, FSExtensionHFTMgrAddHFTSEL, L"FSExtensionHFTMgrAddHFT"},
	{FSExtensionHFTMgrSEL, FSExtensionHFTMgrGetHFTSEL, L"FSExtensionHFTMgrGetHFT"},
	{FSExtensionHFTMgrSEL, FSExtensionHFTMgrReplaceEntrySEL, L"FSExtensionHFTMgrReplaceEntry"},
	{FSExtensionHFTMgrSEL, FSExtensionHFTMgrGetEntrySEL, L"FSExtensionHFTMgrGetEntry"},
	{FSExtensionHFTMgrSEL, FSExtensionHFTMgrGetHFT2SEL, L"FSExtensionHFTMgrGetHFT2"},
	{FSAffineMatrixSEL, FSAffineMatrixIsScaledSEL, L"FSAffineMatrixIsScaled"},
	{FSAffineMatrixSEL, FSAffineMatrixIs90RotatedSEL, L"FSAffineMatrixIs90Rotated"},
	{FSAffineMatrixSEL, FSAffineMatrixGetReverseSEL, L"FSAffineMatrixGetReverse"},
	{FSAffineMatrixSEL, FSAffineMatrixTransformPointSEL, L"FSAffineMatrixTransformPoint"},
	{FSAffineMatrixSEL, FSAffineMatrixTransformRectSEL, L"FSAffineMatrixTransformRect"},
	{FSAffineMatrixSEL, FSAffineMatrixConcatSEL, L"FSAffineMatrixConcat"},
	{FSAffineMatrixSEL, FSAffineMatrixTranslateSEL, L"FSAffineMatrixTranslate"},
	{FSAffineMatrixSEL, FSAffineMatrixTranslateISEL, L"FSAffineMatrixTranslateI"},
	{FSAffineMatrixSEL, FSAffineMatrixScaleSEL, L"FSAffineMatrixScale"},
	{FSAffineMatrixSEL, FSAffineMatrixConcatInverseSEL, L"FSAffineMatrixConcatInverse"},
	{FSAffineMatrixSEL, FSAffineMatrixMatchRectSEL, L"FSAffineMatrixMatchRect"},
	{FSAffineMatrixSEL, FSAffineMatrixGetUnitRectSEL, L"FSAffineMatrixGetUnitRect"},
	{FSAffineMatrixSEL, FSAffineMatrixGetUnitAreaSEL, L"FSAffineMatrixGetUnitArea"},
	{FSAffineMatrixSEL, FSAffineMatrixGetXUnitSEL, L"FSAffineMatrixGetXUnit"},
	{FSAffineMatrixSEL, FSAffineMatrixGetYUnitSEL, L"FSAffineMatrixGetYUnit"},
	{FSAffineMatrixSEL, FSAffineMatrixTransformDistanceSEL, L"FSAffineMatrixTransformDistance"},
	{FSAffineMatrixSEL, FSAffineMatrixRotateSEL, L"FSAffineMatrixRotate"},
	{FSAffineMatrixSEL, FSAffineMatrixRotateAtSEL, L"FSAffineMatrixRotateAt"},
	{FSAffineMatrixSEL, FSAffineMatrixTransformXDistanceSEL, L"FSAffineMatrixTransformXDistance"},
	{FSAffineMatrixSEL, FSAffineMatrixTransformXDistance2SEL, L"FSAffineMatrixTransformXDistance2"},
	{FSAffineMatrixSEL, FSAffineMatrixTransformYDistanceSEL, L"FSAffineMatrixTransformYDistance"},
	{FSAffineMatrixSEL, FSAffineMatrixTransformYDistance2SEL, L"FSAffineMatrixTransformYDistance2"},
	{FSAffineMatrixSEL, FSAffineMatrixSetIdentitySEL, L"FSAffineMatrixSetIdentity"},
	{FSAffineMatrixSEL, FSAffineMatrixTranslate2SEL, L"FSAffineMatrixTranslate2"},
	{FSAffineMatrixSEL, FSAffineMatrixTranslate3SEL, L"FSAffineMatrixTranslate3"},
	{FSAffineMatrixSEL, FSAffineMatrixConcat2SEL, L"FSAffineMatrixConcat2"},
	{FSAffineMatrixSEL, FSAffineMatrixTransformPointsSEL, L"FSAffineMatrixTransformPoints"},
	{FSAffineMatrixSEL, FSAffineMatrixTransformPoints2SEL, L"FSAffineMatrixTransformPoints2"},
	{FSDIBitmapSEL, FSDIBitmapNewSEL, L"FSDIBitmapNew"},
	{FSDIBitmapSEL, FSDIBitmapCreateSEL, L"FSDIBitmapCreate"},
	{FSDIBitmapSEL, FSDIBitmapDestroySEL, L"FSDIBitmapDestroy"},
	{FSDIBitmapSEL, FSDIBitmapGetWidthSEL, L"FSDIBitmapGetWidth"},
	{FSDIBitmapSEL, FSDIBitmapGetHeightSEL, L"FSDIBitmapGetHeight"},
	{FSDIBitmapSEL, FSDIBitmapGetFormatSEL, L"FSDIBitmapGetFormat"},
	{FSDIBitmapSEL, FSDIBitmapGetPitchSEL, L"FSDIBitmapGetPitch"},
	{FSDIBitmapSEL, FSDIBitmapGetPaletteSEL, L"FSDIBitmapGetPalette"},
	{FSDIBitmapSEL, FSDIBitmapGetBufferSEL, L"FSDIBitmapGetBuffer"},
	{FSDIBitmapSEL, FSDIBitmapGetScanlineSEL, L"FSDIBitmapGetScanline"},
	{FSDIBitmapSEL, FSDIBitmapDownSampleScanlineSEL, L"FSDIBitmapDownSampleScanline"},
	{FSDIBitmapSEL, FSDIBitmapTakeOverSEL, L"FSDIBitmapTakeOver"},
	{FSDIBitmapSEL, FSDIBitmapConvertFormatSEL, L"FSDIBitmapConvertFormat"},
	{FSDIBitmapSEL, FSDIBitmapClearSEL, L"FSDIBitmapClear"},
	{FSDIBitmapSEL, FSDIBitmapGetPixelSEL, L"FSDIBitmapGetPixel"},
	{FSDIBitmapSEL, FSDIBitmapSetPixelSEL, L"FSDIBitmapSetPixel"},
	{FSDIBitmapSEL, FSDIBitmapLoadChannelSEL, L"FSDIBitmapLoadChannel"},
	{FSDIBitmapSEL, FSDIBitmapLoadChannel2SEL, L"FSDIBitmapLoadChannel2"},
	{FSDIBitmapSEL, FSDIBitmapMultiplyAlphaSEL, L"FSDIBitmapMultiplyAlpha"},
	{FSDIBitmapSEL, FSDIBitmapMultiplyAlpha2SEL, L"FSDIBitmapMultiplyAlpha2"},
	{FSDIBitmapSEL, FSDIBitmapTransferBitmapSEL, L"FSDIBitmapTransferBitmap"},
	{FSDIBitmapSEL, FSDIBitmapTransferMaskSEL, L"FSDIBitmapTransferMask"},
	{FSDIBitmapSEL, FSDIBitmapCompositeBitmapSEL, L"FSDIBitmapCompositeBitmap"},
	{FSDIBitmapSEL, FSDIBitmapCompositeRectSEL, L"FSDIBitmapCompositeRect"},
	{FSDIBitmapSEL, FSDIBitmapGammaAdjustSEL, L"FSDIBitmapGammaAdjust"},
	{FSDIBitmapSEL, FSDIBitmapConvertColorScaleSEL, L"FSDIBitmapConvertColorScale"},
	{FSDIBitmapSEL, FSDIBitmapDitherFSSEL, L"FSDIBitmapDitherFS"},
	{FSDIBitmapSEL, FSDIBitmapGetBPPSEL, L"FSDIBitmapGetBPP"},
	{FSDIBitmapSEL, FSDIBitmapIsAlphaMaskSEL, L"FSDIBitmapIsAlphaMask"},
	{FSDIBitmapSEL, FSDIBitmapHasAlphaSEL, L"FSDIBitmapHasAlpha"},
	{FSDIBitmapSEL, FSDIBitmapIsOpaqueImageSEL, L"FSDIBitmapIsOpaqueImage"},
	{FSDIBitmapSEL, FSDIBitmapGetPaletteSizeSEL, L"FSDIBitmapGetPaletteSize"},
	{FSDIBitmapSEL, FSDIBitmapGetPaletteArgbSEL, L"FSDIBitmapGetPaletteArgb"},
	{FSDIBitmapSEL, FSDIBitmapSetPaletteArgbSEL, L"FSDIBitmapSetPaletteArgb"},
	{FSDIBitmapSEL, FSDIBitmapCloneSEL, L"FSDIBitmapClone"},
	{FSDIBitmapSEL, FSDIBitmapCloneConvertSEL, L"FSDIBitmapCloneConvert"},
	{FSDIBitmapSEL, FSDIBitmapGetAlphaMaskSEL, L"FSDIBitmapGetAlphaMask"},
	{FSDIBitmapSEL, FSDIBitmapStretchToSEL, L"FSDIBitmapStretchTo"},
	{FSDIBitmapSEL, FSDIBitmapTransformToSEL, L"FSDIBitmapTransformTo"},
	{FSDIBitmapSEL, FSDIBitmapSwapXYSEL, L"FSDIBitmapSwapXY"},
	{FSDIBitmapSEL, FSDIBitmapFlipImageSEL, L"FSDIBitmapFlipImage"},
	{FSDIBitmapSEL, FSDIBitmapLoadFromPNGIconSEL, L"FSDIBitmapLoadFromPNGIcon"},
	{FSDIBitmapSEL, FSDIBitmapLoadFromPNGIcon2SEL, L"FSDIBitmapLoadFromPNGIcon2"},
	{FSDIBitmapSEL, FSDIBitmapCopySEL, L"FSDIBitmapCopy"},
	{FSDIBitmapSEL, FSDIBitmapLoadInfoSEL, L"FSDIBitmapLoadInfo"},
	{FSDIBitmapSEL, FSDIBitmapDestroyDIBAttributeSEL, L"FSDIBitmapDestroyDIBAttribute"},
	{FSDIBitmapSEL, FSDIBitmapGetXDPISEL, L"FSDIBitmapGetXDPI"},
	{FSDIBitmapSEL, FSDIBitmapGetYDPISEL, L"FSDIBitmapGetYDPI"},
	{FSDIBitmapSEL, FSDIBitmapGetDPIUnitSEL, L"FSDIBitmapGetDPIUnit"},
	{FSDIBitmapSEL, FSDIBitmapGetExifInfoSEL, L"FSDIBitmapGetExifInfo"},
	{FSDIBitmapSEL, FSDIBitmapLoadFromPNGIcon3SEL, L"FSDIBitmapLoadFromPNGIcon3"},
	{FSDIBitmapSEL, FSDIBitmapLoadFromImageSEL, L"FSDIBitmapLoadFromImage"},
	{FSDIBitmapSEL, FSDIBitmapGetBitmapAlphaMaskSEL, L"FSDIBitmapGetBitmapAlphaMask"},
	{FSDIBitmapSEL, FSDIBitmapNew2SEL, L"FSDIBitmapNew2"},
	{FSDIBitmapSEL, FSDIBitmapInitDIBitmapAttributeSEL, L"FSDIBitmapInitDIBitmapAttribute"},
	{FSDIBitmapSEL, FSDIBitmapCopy2SEL, L"FSDIBitmapCopy2"},
	{FSDIBitmapSEL, FSDIBitmapCloneConvert2SEL, L"FSDIBitmapCloneConvert2"},
	{FSDIBitmapSEL, FSDIBitmapMultiplyAlpha3SEL, L"FSDIBitmapMultiplyAlpha3"},
	{FSDIBitmapSEL, FSDIBitmapCastToBitSourceSEL, L"FSDIBitmapCastToBitSource"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrNewSEL, L"FSMapPtrToPtrNew"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrDestroySEL, L"FSMapPtrToPtrDestroy"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrGetCountSEL, L"FSMapPtrToPtrGetCount"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrIsEmptySEL, L"FSMapPtrToPtrIsEmpty"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrLookupSEL, L"FSMapPtrToPtrLookup"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrGetValueAtSEL, L"FSMapPtrToPtrGetValueAt"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrSetAtSEL, L"FSMapPtrToPtrSetAt"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrRemoveKeySEL, L"FSMapPtrToPtrRemoveKey"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrRemoveAllSEL, L"FSMapPtrToPtrRemoveAll"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrGetStartPositionSEL, L"FSMapPtrToPtrGetStartPosition"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrGetNextAssocSEL, L"FSMapPtrToPtrGetNextAssoc"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrGetHashTableSizeSEL, L"FSMapPtrToPtrGetHashTableSize"},
	{FSMapPtrToPtrSEL, FSMapPtrToPtrInitHashTableSEL, L"FSMapPtrToPtrInitHashTable"},
	{FSPtrArraySEL, FSPtrArrayNewSEL, L"FSPtrArrayNew"},
	{FSPtrArraySEL, FSPtrArrayDestroySEL, L"FSPtrArrayDestroy"},
	{FSPtrArraySEL, FSPtrArrayGetSizeSEL, L"FSPtrArrayGetSize"},
	{FSPtrArraySEL, FSPtrArrayGetUpperBoundSEL, L"FSPtrArrayGetUpperBound"},
	{FSPtrArraySEL, FSPtrArraySetSizeSEL, L"FSPtrArraySetSize"},
	{FSPtrArraySEL, FSPtrArrayRemoveAllSEL, L"FSPtrArrayRemoveAll"},
	{FSPtrArraySEL, FSPtrArrayGetAtSEL, L"FSPtrArrayGetAt"},
	{FSPtrArraySEL, FSPtrArraySetAtSEL, L"FSPtrArraySetAt"},
	{FSPtrArraySEL, FSPtrArraySetAtGrowSEL, L"FSPtrArraySetAtGrow"},
	{FSPtrArraySEL, FSPtrArrayAddSEL, L"FSPtrArrayAdd"},
	{FSPtrArraySEL, FSPtrArrayAppendSEL, L"FSPtrArrayAppend"},
	{FSPtrArraySEL, FSPtrArrayCopySEL, L"FSPtrArrayCopy"},
	{FSPtrArraySEL, FSPtrArrayGetDataPtrSEL, L"FSPtrArrayGetDataPtr"},
	{FSPtrArraySEL, FSPtrArrayInsertAtSEL, L"FSPtrArrayInsertAt"},
	{FSPtrArraySEL, FSPtrArrayRemoveAtSEL, L"FSPtrArrayRemoveAt"},
	{FSPtrArraySEL, FSPtrArrayInsertNewArrayAtSEL, L"FSPtrArrayInsertNewArrayAt"},
	{FSPtrArraySEL, FSPtrArrayFindSEL, L"FSPtrArrayFind"},
	{FSByteArraySEL, FSByteArrayNewSEL, L"FSByteArrayNew"},
	{FSByteArraySEL, FSByteArrayDestroySEL, L"FSByteArrayDestroy"},
	{FSByteArraySEL, FSByteArrayGetSizeSEL, L"FSByteArrayGetSize"},
	{FSByteArraySEL, FSByteArrayGetUpperBoundSEL, L"FSByteArrayGetUpperBound"},
	{FSByteArraySEL, FSByteArraySetSizeSEL, L"FSByteArraySetSize"},
	{FSByteArraySEL, FSByteArrayRemoveAllSEL, L"FSByteArrayRemoveAll"},
	{FSByteArraySEL, FSByteArrayGetAtSEL, L"FSByteArrayGetAt"},
	{FSByteArraySEL, FSByteArraySetAtSEL, L"FSByteArraySetAt"},
	{FSByteArraySEL, FSByteArraySetAtGrowSEL, L"FSByteArraySetAtGrow"},
	{FSByteArraySEL, FSByteArrayAddSEL, L"FSByteArrayAdd"},
	{FSByteArraySEL, FSByteArrayAppendSEL, L"FSByteArrayAppend"},
	{FSByteArraySEL, FSByteArrayCopySEL, L"FSByteArrayCopy"},
	{FSByteArraySEL, FSByteArrayGetDataPtrSEL, L"FSByteArrayGetDataPtr"},
	{FSByteArraySEL, FSByteArrayInsertAtSEL, L"FSByteArrayInsertAt"},
	{FSByteArraySEL, FSByteArrayRemoveAtSEL, L"FSByteArrayRemoveAt"},
	{FSByteArraySEL, FSByteArrayInsertNewArrayAtSEL, L"FSByteArrayInsertNewArrayAt"},
	{FSByteArraySEL, FSByteArrayFindSEL, L"FSByteArrayFind"},
	{FSWordArraySEL, FSWordArrayNewSEL, L"FSWordArrayNew"},
	{FSWordArraySEL, FSWordArrayDestroySEL, L"FSWordArrayDestroy"},
	{FSWordArraySEL, FSWordArrayGetSizeSEL, L"FSWordArrayGetSize"},
	{FSWordArraySEL, FSWordArrayGetUpperBoundSEL, L"FSWordArrayGetUpperBound"},
	{FSWordArraySEL, FSWordArraySetSizeSEL, L"FSWordArraySetSize"},
	{FSWordArraySEL, FSWordArrayRemoveAllSEL, L"FSWordArrayRemoveAll"},
	{FSWordArraySEL, FSWordArrayGetAtSEL, L"FSWordArrayGetAt"},
	{FSWordArraySEL, FSWordArraySetAtSEL, L"FSWordArraySetAt"},
	{FSWordArraySEL, FSWordArraySetAtGrowSEL, L"FSWordArraySetAtGrow"},
	{FSWordArraySEL, FSWordArrayAddSEL, L"FSWordArrayAdd"},
	{FSWordArraySEL, FSWordArrayAppendSEL, L"FSWordArrayAppend"},
	{FSWordArraySEL, FSWordArrayCopySEL, L"FSWordArrayCopy"},
	{FSWordArraySEL, FSWordArrayGetDataPtrSEL, L"FSWordArrayGetDataPtr"},
	{FSWordArraySEL, FSWordArrayInsertAtSEL, L"FSWordArrayInsertAt"},
	{FSWordArraySEL, FSWordArrayRemoveAtSEL, L"FSWordArrayRemoveAt"},
	{FSWordArraySEL, FSWordArrayInsertNewArrayAtSEL, L"FSWordArrayInsertNewArrayAt"},
	{FSWordArraySEL, FSWordArrayFindSEL, L"FSWordArrayFind"},
	{FSDWordArraySEL, FSDWordArrayNewSEL, L"FSDWordArrayNew"},
	{FSDWordArraySEL, FSDWordArrayDestroySEL, L"FSDWordArrayDestroy"},
	{FSDWordArraySEL, FSDWordArrayGetSizeSEL, L"FSDWordArrayGetSize"},
	{FSDWordArraySEL, FSDWordArrayGetUpperBoundSEL, L"FSDWordArrayGetUpperBound"},
	{FSDWordArraySEL, FSDWordArraySetSizeSEL, L"FSDWordArraySetSize"},
	{FSDWordArraySEL, FSDWordArrayRemoveAllSEL, L"FSDWordArrayRemoveAll"},
	{FSDWordArraySEL, FSDWordArrayGetAtSEL, L"FSDWordArrayGetAt"},
	{FSDWordArraySEL, FSDWordArraySetAtSEL, L"FSDWordArraySetAt"},
	{FSDWordArraySEL, FSDWordArraySetAtGrowSEL, L"FSDWordArraySetAtGrow"},
	{FSDWordArraySEL, FSDWordArrayAddSEL, L"FSDWordArrayAdd"},
	{FSDWordArraySEL, FSDWordArrayAppendSEL, L"FSDWordArrayAppend"},
	{FSDWordArraySEL, FSDWordArrayCopySEL, L"FSDWordArrayCopy"},
	{FSDWordArraySEL, FSDWordArrayGetDataPtrSEL, L"FSDWordArrayGetDataPtr"},
	{FSDWordArraySEL, FSDWordArrayInsertAtSEL, L"FSDWordArrayInsertAt"},
	{FSDWordArraySEL, FSDWordArrayRemoveAtSEL, L"FSDWordArrayRemoveAt"},
	{FSDWordArraySEL, FSDWordArrayInsertNewArrayAtSEL, L"FSDWordArrayInsertNewArrayAt"},
	{FSDWordArraySEL, FSDWordArrayFindSEL, L"FSDWordArrayFind"},
	{FSDWordArraySEL, FSDWordArrayGetDataSEL, L"FSDWordArrayGetData"},
	{FSByteStringArraySEL, FSByteStringArrayNewSEL, L"FSByteStringArrayNew"},
	{FSByteStringArraySEL, FSByteStringArrayDestroySEL, L"FSByteStringArrayDestroy"},
	{FSByteStringArraySEL, FSByteStringArrayGetAtSEL, L"FSByteStringArrayGetAt"},
	{FSByteStringArraySEL, FSByteStringArrayGetSizeSEL, L"FSByteStringArrayGetSize"},
	{FSByteStringArraySEL, FSByteStringArrayRemoveAllSEL, L"FSByteStringArrayRemoveAll"},
	{FSByteStringArraySEL, FSByteStringArrayAddSEL, L"FSByteStringArrayAdd"},
	{FSByteStringArraySEL, FSByteStringArrayRemoveAtSEL, L"FSByteStringArrayRemoveAt"},
	{FSByteStringArraySEL, FSByteStringArrayAdd2SEL, L"FSByteStringArrayAdd2"},
	{FSByteStringArraySEL, FSByteStringArrayGetDataPtrSEL, L"FSByteStringArrayGetDataPtr"},
	{FSWideStringArraySEL, FSWideStringArrayNewSEL, L"FSWideStringArrayNew"},
	{FSWideStringArraySEL, FSWideStringArrayDestroySEL, L"FSWideStringArrayDestroy"},
	{FSWideStringArraySEL, FSWideStringArrayGetAtSEL, L"FSWideStringArrayGetAt"},
	{FSWideStringArraySEL, FSWideStringArrayGetSizeSEL, L"FSWideStringArrayGetSize"},
	{FSWideStringArraySEL, FSWideStringArrayRemoveAllSEL, L"FSWideStringArrayRemoveAll"},
	{FSWideStringArraySEL, FSWideStringArrayAddSEL, L"FSWideStringArrayAdd"},
	{FSWideStringArraySEL, FSWideStringArrayRemoveAtSEL, L"FSWideStringArrayRemoveAt"},
	{FSWideStringArraySEL, FSWideStringArrayAdd2SEL, L"FSWideStringArrayAdd2"},
	{FSWideStringArraySEL, FSWideStringArrayCopySEL, L"FSWideStringArrayCopy"},
	{FSCodeTransformationSEL, FSCodeTransformationNameDecodeSEL, L"FSCodeTransformationNameDecode"},
	{FSCodeTransformationSEL, FSCodeTransformationNameEncodeSEL, L"FSCodeTransformationNameEncode"},
	{FSCodeTransformationSEL, FSCodeTransformationEncodeStringSEL, L"FSCodeTransformationEncodeString"},
	{FSCodeTransformationSEL, FSCodeTransformationDecodeTextSEL, L"FSCodeTransformationDecodeText"},
	{FSCodeTransformationSEL, FSCodeTransformationDecodeText2SEL, L"FSCodeTransformationDecodeText2"},
	{FSCodeTransformationSEL, FSCodeTransformationEncodeTextSEL, L"FSCodeTransformationEncodeText"},
	{FSCodeTransformationSEL, FSCodeTransformationFlateEncodeProcSEL, L"FSCodeTransformationFlateEncodeProc"},
	{FSCodeTransformationSEL, FSCodeTransformationFlateDecodeProcSEL, L"FSCodeTransformationFlateDecodeProc"},
	{FSCodeTransformationSEL, FSCodeTransformationRunLengthDecodeProcSEL, L"FSCodeTransformationRunLengthDecodeProc"},
	{FSCodeTransformationSEL, FSCodeTransformationRunLengthEncodeProcSEL, L"FSCodeTransformationRunLengthEncodeProc"},
	{FSCodeTransformationSEL, FSCodeTransformationMemFreeSEL, L"FSCodeTransformationMemFree"},
	{FSCodeTransformationSEL, FSCodeTransformationBasicModuleA85EncodeSEL, L"FSCodeTransformationBasicModuleA85Encode"},
	{FSCodeTransformationSEL, FSCodeTransformationFlateModuleEncodeSEL, L"FSCodeTransformationFlateModuleEncode"},
	{FSCodeTransformationSEL, FSCodeTransformationFlateModuleEncode2SEL, L"FSCodeTransformationFlateModuleEncode2"},
	{FSCodeTransformationSEL, FSCodeTransformationPngModuleEncodeSEL, L"FSCodeTransformationPngModuleEncode"},
	{FSCodeTransformationSEL, FSCodeTransformationReleaseEncodeBufferSEL, L"FSCodeTransformationReleaseEncodeBuffer"},
	{FSCodeTransformationSEL, FSCodeTransformationGetUnicodePropertiesSEL, L"FSCodeTransformationGetUnicodeProperties"},
	{FSCodeTransformationSEL, FSCodeTransformationEncodeText2SEL, L"FSCodeTransformationEncodeText2"},
	{FSFloatRectArraySEL, FSFloatRectArrayNewSEL, L"FSFloatRectArrayNew"},
	{FSFloatRectArraySEL, FSFloatRectArrayDestroySEL, L"FSFloatRectArrayDestroy"},
	{FSFloatRectArraySEL, FSFloatRectArrayGetSizeSEL, L"FSFloatRectArrayGetSize"},
	{FSFloatRectArraySEL, FSFloatRectArrayGetUpperBoundSEL, L"FSFloatRectArrayGetUpperBound"},
	{FSFloatRectArraySEL, FSFloatRectArraySetSizeSEL, L"FSFloatRectArraySetSize"},
	{FSFloatRectArraySEL, FSFloatRectArrayRemoveAllSEL, L"FSFloatRectArrayRemoveAll"},
	{FSFloatRectArraySEL, FSFloatRectArrayGetAtSEL, L"FSFloatRectArrayGetAt"},
	{FSFloatRectArraySEL, FSFloatRectArraySetAtSEL, L"FSFloatRectArraySetAt"},
	{FSFloatRectArraySEL, FSFloatRectArraySetAtGrowSEL, L"FSFloatRectArraySetAtGrow"},
	{FSFloatRectArraySEL, FSFloatRectArrayAddSEL, L"FSFloatRectArrayAdd"},
	{FSFloatRectArraySEL, FSFloatRectArrayAppendSEL, L"FSFloatRectArrayAppend"},
	{FSFloatRectArraySEL, FSFloatRectArrayCopySEL, L"FSFloatRectArrayCopy"},
	{FSFloatRectArraySEL, FSFloatRectArrayInsertAtSEL, L"FSFloatRectArrayInsertAt"},
	{FSFloatRectArraySEL, FSFloatRectArrayRemoveAtSEL, L"FSFloatRectArrayRemoveAt"},
	{FSFloatRectArraySEL, FSFloatRectArrayInsertNewArrayAtSEL, L"FSFloatRectArrayInsertNewArrayAt"},
	{FSFloatRectArraySEL, FSFloatRectArrayFindSEL, L"FSFloatRectArrayFind"},
	{FSBinaryBufSEL, FSBinaryBufNewSEL, L"FSBinaryBufNew"},
	{FSBinaryBufSEL, FSBinaryBufDestroySEL, L"FSBinaryBufDestroy"},
	{FSBinaryBufSEL, FSBinaryBufClearSEL, L"FSBinaryBufClear"},
	{FSBinaryBufSEL, FSBinaryBufEstimateSizeSEL, L"FSBinaryBufEstimateSize"},
	{FSBinaryBufSEL, FSBinaryBufAppendBlockSEL, L"FSBinaryBufAppendBlock"},
	{FSBinaryBufSEL, FSBinaryBufAppendFillSEL, L"FSBinaryBufAppendFill"},
	{FSBinaryBufSEL, FSBinaryBufAppendStringSEL, L"FSBinaryBufAppendString"},
	{FSBinaryBufSEL, FSBinaryBufAppendByteSEL, L"FSBinaryBufAppendByte"},
	{FSBinaryBufSEL, FSBinaryBufInsertBlockSEL, L"FSBinaryBufInsertBlock"},
	{FSBinaryBufSEL, FSBinaryBufAttachDataSEL, L"FSBinaryBufAttachData"},
	{FSBinaryBufSEL, FSBinaryBufCopyDataSEL, L"FSBinaryBufCopyData"},
	{FSBinaryBufSEL, FSBinaryBufTakeOverSEL, L"FSBinaryBufTakeOver"},
	{FSBinaryBufSEL, FSBinaryBufDeleteSEL, L"FSBinaryBufDelete"},
	{FSBinaryBufSEL, FSBinaryBufGetBufferSEL, L"FSBinaryBufGetBuffer"},
	{FSBinaryBufSEL, FSBinaryBufGetSizeSEL, L"FSBinaryBufGetSize"},
	{FSBinaryBufSEL, FSBinaryBufGetByteStringSEL, L"FSBinaryBufGetByteString"},
	{FSBinaryBufSEL, FSBinaryBufDetachBufferSEL, L"FSBinaryBufDetachBuffer"},
	{FSPauseHandlerSEL, FSPauseHandlerCreateSEL, L"FSPauseHandlerCreate"},
	{FSPauseHandlerSEL, FSPauseHandlerDestroySEL, L"FSPauseHandlerDestroy"},
	{FSPauseHandlerSEL, FSPauseHandlerNeedToPauseNowSEL, L"FSPauseHandlerNeedToPauseNow"},
	{FSFileReadHandlerSEL, FSFileReadHandlerNewSEL, L"FSFileReadHandlerNew"},
	{FSFileReadHandlerSEL, FSFileReadHandlerDestroySEL, L"FSFileReadHandlerDestroy"},
	{FSFileReadHandlerSEL, FSFileReadHandlerGetSizeSEL, L"FSFileReadHandlerGetSize"},
	{FSFileReadHandlerSEL, FSFileReadHandlerReadBlockSEL, L"FSFileReadHandlerReadBlock"},
	{FSFileReadHandlerSEL, FSFileReadHandlerNew2SEL, L"FSFileReadHandlerNew2"},
	{FSFileReadHandlerSEL, FSFileReadHandlerNew3SEL, L"FSFileReadHandlerNew3"},
	{FSFileReadHandlerSEL, FSFileReadHandlerIsEOFSEL, L"FSFileReadHandlerIsEOF"},
	{FSFileReadHandlerSEL, FSFileReadHandlerGetPositionSEL, L"FSFileReadHandlerGetPosition"},
	{FSFileReadHandlerSEL, FSFileReadHandlerReadBlock2SEL, L"FSFileReadHandlerReadBlock2"},
	{FSFileReadHandlerSEL, FSFileReadHandlerSetRangeSEL, L"FSFileReadHandlerSetRange"},
	{FSStreamWriteHandlerSEL, FSStreamWriteHandlerNewSEL, L"FSStreamWriteHandlerNew"},
	{FSStreamWriteHandlerSEL, FSStreamWriteHandlerDestroySEL, L"FSStreamWriteHandlerDestroy"},
	{FSStreamWriteHandlerSEL, FSStreamWriteHandlerWriteBlockSEL, L"FSStreamWriteHandlerWriteBlock"},
// fs_basicImpl.h end

// In file fs_stringImpl.h
	{FSCharMapSEL, FSCharMapNewSEL, L"FSCharMapNew"},
	{FSCharMapSEL, FSCharMapReleaseSEL, L"FSCharMapRelease"},
	{FSCharMapSEL, FSCharMapGetDefaultMapperSEL, L"FSCharMapGetDefaultMapper"},
	{FSCharMapSEL, FSCharMapGetDefaultMapper2SEL, L"FSCharMapGetDefaultMapper2"},
	{FSByteStringSEL, FSByteStringNewSEL, L"FSByteStringNew"},
	{FSByteStringSEL, FSByteStringNew2SEL, L"FSByteStringNew2"},
	{FSByteStringSEL, FSByteStringNew3SEL, L"FSByteStringNew3"},
	{FSByteStringSEL, FSByteStringNew4SEL, L"FSByteStringNew4"},
	{FSByteStringSEL, FSByteStringFromUnicodeSEL, L"FSByteStringFromUnicode"},
	{FSByteStringSEL, FSByteStringFromUnicode2SEL, L"FSByteStringFromUnicode2"},
	{FSByteStringSEL, FSByteStringDestroySEL, L"FSByteStringDestroy"},
	{FSByteStringSEL, FSByteStringGetLengthSEL, L"FSByteStringGetLength"},
	{FSByteStringSEL, FSByteStringIsEmptySEL, L"FSByteStringIsEmpty"},
	{FSByteStringSEL, FSByteStringCompareSEL, L"FSByteStringCompare"},
	{FSByteStringSEL, FSByteStringEqualSEL, L"FSByteStringEqual"},
	{FSByteStringSEL, FSByteStringEqualNoCaseSEL, L"FSByteStringEqualNoCase"},
	{FSByteStringSEL, FSByteStringCopySEL, L"FSByteStringCopy"},
	{FSByteStringSEL, FSByteStringFillSEL, L"FSByteStringFill"},
	{FSByteStringSEL, FSByteStringConcatSEL, L"FSByteStringConcat"},
	{FSByteStringSEL, FSByteStringConcat2SEL, L"FSByteStringConcat2"},
	{FSByteStringSEL, FSByteStringEmptySEL, L"FSByteStringEmpty"},
	{FSByteStringSEL, FSByteStringGetAtSEL, L"FSByteStringGetAt"},
	{FSByteStringSEL, FSByteStringSetAtSEL, L"FSByteStringSetAt"},
	{FSByteStringSEL, FSByteStringInsertSEL, L"FSByteStringInsert"},
	{FSByteStringSEL, FSByteStringDeleteSEL, L"FSByteStringDelete"},
	{FSByteStringSEL, FSByteStringFormatSEL, L"FSByteStringFormat"},
	{FSByteStringSEL, FSByteStringReserveSEL, L"FSByteStringReserve"},
	{FSByteStringSEL, FSByteStringMidSEL, L"FSByteStringMid"},
	{FSByteStringSEL, FSByteStringMid2SEL, L"FSByteStringMid2"},
	{FSByteStringSEL, FSByteStringLeftSEL, L"FSByteStringLeft"},
	{FSByteStringSEL, FSByteStringRightSEL, L"FSByteStringRight"},
	{FSByteStringSEL, FSByteStringFindSEL, L"FSByteStringFind"},
	{FSByteStringSEL, FSByteStringFind2SEL, L"FSByteStringFind2"},
	{FSByteStringSEL, FSByteStringMakeLowerSEL, L"FSByteStringMakeLower"},
	{FSByteStringSEL, FSByteStringMakeUpperSEL, L"FSByteStringMakeUpper"},
	{FSByteStringSEL, FSByteStringTrimRightSEL, L"FSByteStringTrimRight"},
	{FSByteStringSEL, FSByteStringTrimRight2SEL, L"FSByteStringTrimRight2"},
	{FSByteStringSEL, FSByteStringTrimRight3SEL, L"FSByteStringTrimRight3"},
	{FSByteStringSEL, FSByteStringTrimLeftSEL, L"FSByteStringTrimLeft"},
	{FSByteStringSEL, FSByteStringTrimLeft2SEL, L"FSByteStringTrimLeft2"},
	{FSByteStringSEL, FSByteStringTrimLeft3SEL, L"FSByteStringTrimLeft3"},
	{FSByteStringSEL, FSByteStringReplaceSEL, L"FSByteStringReplace"},
	{FSByteStringSEL, FSByteStringRemoveSEL, L"FSByteStringRemove"},
	{FSByteStringSEL, FSByteStringGetIDSEL, L"FSByteStringGetID"},
	{FSByteStringSEL, FSByteStringFormatIntegerSEL, L"FSByteStringFormatInteger"},
	{FSByteStringSEL, FSByteStringFormatFloatSEL, L"FSByteStringFormatFloat"},
	{FSByteStringSEL, FSByteStringCastToLPCSTRSEL, L"FSByteStringCastToLPCSTR"},
	{FSByteStringSEL, FSByteStringUTF8DecodeSEL, L"FSByteStringUTF8Decode"},
	{FSByteStringSEL, FSByteStringFormatVSEL, L"FSByteStringFormatV"},
	{FSByteStringSEL, FSByteStringCastToLPCBYTESEL, L"FSByteStringCastToLPCBYTE"},
	{FSByteStringSEL, FSByteStringConvertFromSEL, L"FSByteStringConvertFrom"},
	{FSByteStringSEL, FSByteStringEqual2SEL, L"FSByteStringEqual2"},
	{FSByteStringSEL, FSByteStringReverseFindSEL, L"FSByteStringReverseFind"},
	{FSWideStringSEL, FSWideStringNewSEL, L"FSWideStringNew"},
	{FSWideStringSEL, FSWideStringNew2SEL, L"FSWideStringNew2"},
	{FSWideStringSEL, FSWideStringNew3SEL, L"FSWideStringNew3"},
	{FSWideStringSEL, FSWideStringDestroySEL, L"FSWideStringDestroy"},
	{FSWideStringSEL, FSWideStringGetLengthSEL, L"FSWideStringGetLength"},
	{FSWideStringSEL, FSWideStringIsEmptySEL, L"FSWideStringIsEmpty"},
	{FSWideStringSEL, FSWideStringCompareSEL, L"FSWideStringCompare"},
	{FSWideStringSEL, FSWideStringCompare2SEL, L"FSWideStringCompare2"},
	{FSWideStringSEL, FSWideStringEqualSEL, L"FSWideStringEqual"},
	{FSWideStringSEL, FSWideStringEqual2SEL, L"FSWideStringEqual2"},
	{FSWideStringSEL, FSWideStringCopySEL, L"FSWideStringCopy"},
	{FSWideStringSEL, FSWideStringFillSEL, L"FSWideStringFill"},
	{FSWideStringSEL, FSWideStringConcatSEL, L"FSWideStringConcat"},
	{FSWideStringSEL, FSWideStringConcat2SEL, L"FSWideStringConcat2"},
	{FSWideStringSEL, FSWideStringEmptySEL, L"FSWideStringEmpty"},
	{FSWideStringSEL, FSWideStringGetAtSEL, L"FSWideStringGetAt"},
	{FSWideStringSEL, FSWideStringSetAtSEL, L"FSWideStringSetAt"},
	{FSWideStringSEL, FSWideStringInsertSEL, L"FSWideStringInsert"},
	{FSWideStringSEL, FSWideStringDeleteSEL, L"FSWideStringDelete"},
	{FSWideStringSEL, FSWideStringFormatSEL, L"FSWideStringFormat"},
	{FSWideStringSEL, FSWideStringReserveSEL, L"FSWideStringReserve"},
	{FSWideStringSEL, FSWideStringMidSEL, L"FSWideStringMid"},
	{FSWideStringSEL, FSWideStringMid2SEL, L"FSWideStringMid2"},
	{FSWideStringSEL, FSWideStringLeftSEL, L"FSWideStringLeft"},
	{FSWideStringSEL, FSWideStringRightSEL, L"FSWideStringRight"},
	{FSWideStringSEL, FSWideStringFindSEL, L"FSWideStringFind"},
	{FSWideStringSEL, FSWideStringFind2SEL, L"FSWideStringFind2"},
	{FSWideStringSEL, FSWideStringMakeLowerSEL, L"FSWideStringMakeLower"},
	{FSWideStringSEL, FSWideStringMakeUpperSEL, L"FSWideStringMakeUpper"},
	{FSWideStringSEL, FSWideStringTrimRightSEL, L"FSWideStringTrimRight"},
	{FSWideStringSEL, FSWideStringTrimRight2SEL, L"FSWideStringTrimRight2"},
	{FSWideStringSEL, FSWideStringTrimRight3SEL, L"FSWideStringTrimRight3"},
	{FSWideStringSEL, FSWideStringTrimLeftSEL, L"FSWideStringTrimLeft"},
	{FSWideStringSEL, FSWideStringTrimLeft2SEL, L"FSWideStringTrimLeft2"},
	{FSWideStringSEL, FSWideStringTrimLeft3SEL, L"FSWideStringTrimLeft3"},
	{FSWideStringSEL, FSWideStringReplaceSEL, L"FSWideStringReplace"},
	{FSWideStringSEL, FSWideStringRemoveSEL, L"FSWideStringRemove"},
	{FSWideStringSEL, FSWideStringGetIntegerSEL, L"FSWideStringGetInteger"},
	{FSWideStringSEL, FSWideStringFromUTF8SEL, L"FSWideStringFromUTF8"},
	{FSWideStringSEL, FSWideStringFromUTF16LESEL, L"FSWideStringFromUTF16LE"},
	{FSWideStringSEL, FSWideStringUTF8EncodeSEL, L"FSWideStringUTF8Encode"},
	{FSWideStringSEL, FSWideStringUTF16LE_EncodeSEL, L"FSWideStringUTF16LE_Encode"},
	{FSWideStringSEL, FSWideStringCastToLPCWSTRSEL, L"FSWideStringCastToLPCWSTR"},
	{FSWideStringSEL, FSWideStringFormatVSEL, L"FSWideStringFormatV"},
	{FSWideStringSEL, FSWideStringFromLocalSEL, L"FSWideStringFromLocal"},
	{FSWideStringSEL, FSWideStringFromLocal2SEL, L"FSWideStringFromLocal2"},
	{FSWideStringSEL, FSWideStringCompareNoCaseSEL, L"FSWideStringCompareNoCase"},
	{FSWideStringSEL, FSWideStringCompareNoCase2SEL, L"FSWideStringCompareNoCase2"},
	{FSWideStringSEL, FSWideStringConvertFromSEL, L"FSWideStringConvertFrom"},
	{FSWideStringSEL, FSWideStringFromLocal3SEL, L"FSWideStringFromLocal3"},
	{FSWideStringSEL, FSWideStringGetFloatSEL, L"FSWideStringGetFloat"},
	{FSWideStringSEL, FSWideStringFind3SEL, L"FSWideStringFind3"},
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
	{FRToolSEL, FRToolNewSEL, L"FRToolNew"},
	{FRToolSEL, FRToolReleaseSEL, L"FRToolRelease"},
	{FRToolSEL, FRToolGetNameSEL, L"FRToolGetName"},
	{FRToolSEL, FRToolSetAssociatedMousePtHandlerTypeSEL, L"FRToolSetAssociatedMousePtHandlerType"},
	{FRToolSEL, FRToolSetAssociatedSelectionHandlerTypeSEL, L"FRToolSetAssociatedSelectionHandlerType"},
	{FRToolSEL, FRToolTool_GetBeginPointSEL, L"FRToolTool_GetBeginPoint"},
	{FRAppSEL, FRAppGetNameSEL, L"FRAppGetName"},
	{FRAppSEL, FRAppGetVersionSEL, L"FRAppGetVersion"},
	{FRAppSEL, FRAppGetAppTitleSEL, L"FRAppGetAppTitle"},
	{FRAppSEL, FRAppGetAppDataPathSEL, L"FRAppGetAppDataPath"},
	{FRAppSEL, FRAppCanQuitSEL, L"FRAppCanQuit"},
	{FRAppSEL, FRAppCountToolbarsSEL, L"FRAppCountToolbars"},
	{FRAppSEL, FRAppGetToolBarSEL, L"FRAppGetToolBar"},
	{FRAppSEL, FRAppGetToolBarByNameSEL, L"FRAppGetToolBarByName"},
	{FRAppSEL, FRAppGetMenuBarSEL, L"FRAppGetMenuBar"},
	{FRAppSEL, FRAppShowMenuBarSEL, L"FRAppShowMenuBar"},
	{FRAppSEL, FRAppRegisterToolSEL, L"FRAppRegisterTool"},
	{FRAppSEL, FRAppGetToolByNameSEL, L"FRAppGetToolByName"},
	{FRAppSEL, FRAppCountToolsSEL, L"FRAppCountTools"},
	{FRAppSEL, FRAppGetToolByIndexSEL, L"FRAppGetToolByIndex"},
	{FRAppSEL, FRAppSetActiveToolSEL, L"FRAppSetActiveTool"},
	{FRAppSEL, FRAppGetActiveToolSEL, L"FRAppGetActiveTool"},
	{FRAppSEL, FRAppRegisterPreferencePageHandlerSEL, L"FRAppRegisterPreferencePageHandler"},
	{FRAppSEL, FRAppAddPreferencePageSEL, L"FRAppAddPreferencePage"},
	{FRAppSEL, FRAppRegisterDocPropertyPageHandlerSEL, L"FRAppRegisterDocPropertyPageHandler"},
	{FRAppSEL, FRAppAddDocPropertyPageSEL, L"FRAppAddDocPropertyPage"},
	{FRAppSEL, FRAppRegisterNavPanelViewSEL, L"FRAppRegisterNavPanelView"},
	{FRAppSEL, FRAppRegisterAppEventHandlerSEL, L"FRAppRegisterAppEventHandler"},
	{FRAppSEL, FRAppCountDocsOfPDDocSEL, L"FRAppCountDocsOfPDDoc"},
	{FRAppSEL, FRAppGetDocOfPDDocSEL, L"FRAppGetDocOfPDDoc"},
	{FRAppSEL, FRAppGetActiveDocOfPDDocSEL, L"FRAppGetActiveDocOfPDDoc"},
	{FRAppSEL, FRAppSetActiveDocOfPDDocSEL, L"FRAppSetActiveDocOfPDDoc"},
	{FRAppSEL, FRAppRegisterDocHandlerOfPDDocSEL, L"FRAppRegisterDocHandlerOfPDDoc"},
	{FRAppSEL, FRAppIsFullScreenSEL, L"FRAppIsFullScreen"},
	{FRAppSEL, FRAppShowFullScreenSEL, L"FRAppShowFullScreen"},
	{FRAppSEL, FRAppEndFullScreenSEL, L"FRAppEndFullScreen"},
	{FRAppSEL, FRAppGetMousePosSEL, L"FRAppGetMousePos"},
	{FRAppSEL, FRAppModalWindowIsOpenSEL, L"FRAppModalWindowIsOpen"},
	{FRAppSEL, FRAppRegisterSecurityHandlerSEL, L"FRAppRegisterSecurityHandler"},
	{FRAppSEL, FRAppUnRegisterSecurityHandlerSEL, L"FRAppUnRegisterSecurityHandler"},
	{FRAppSEL, FRAppGetPassphraseSEL, L"FRAppGetPassphrase"},
	{FRAppSEL, FRAppRegisterContentProviderSEL, L"FRAppRegisterContentProvider"},
	{FRAppSEL, FRAppGetMainFrameWndSEL, L"FRAppGetMainFrameWnd"},
	{FRAppSEL, FRAppAddUndoRedoItemSEL, L"FRAppAddUndoRedoItem"},
	{FRAppSEL, FRAppRegisterPageHandlerOfPDDocSEL, L"FRAppRegisterPageHandlerOfPDDoc"},
	{FRAppSEL, FRAppRegisterForContextMenuAdditionSEL, L"FRAppRegisterForContextMenuAddition"},
	{FRAppSEL, FRAppRegisterSelectionHandlerSEL, L"FRAppRegisterSelectionHandler"},
	{FRAppSEL, FRAppUnRegisterSelectionHandlerSEL, L"FRAppUnRegisterSelectionHandler"},
	{FRAppSEL, FRAppRegisterCaptureHandlerSEL, L"FRAppRegisterCaptureHandler"},
	{FRAppSEL, FRAppUnRegisterCaptureHandlerSEL, L"FRAppUnRegisterCaptureHandler"},
	{FRAppSEL, FRAppRegistryGetProfilePathSEL, L"FRAppRegistryGetProfilePath"},
	{FRAppSEL, FRAppRegistryWriteIntSEL, L"FRAppRegistryWriteInt"},
	{FRAppSEL, FRAppRegistryWriteBinarySEL, L"FRAppRegistryWriteBinary"},
	{FRAppSEL, FRAppRegistryWriteStringSEL, L"FRAppRegistryWriteString"},
	{FRAppSEL, FRAppRegistryGetIntSEL, L"FRAppRegistryGetInt"},
	{FRAppSEL, FRAppRegistryGetBinarySEL, L"FRAppRegistryGetBinary"},
	{FRAppSEL, FRAppRegistryGetStringSEL, L"FRAppRegistryGetString"},
	{FRAppSEL, FRAppRegistryGetEntryCountSEL, L"FRAppRegistryGetEntryCount"},
	{FRAppSEL, FRAppRegistryGetEntryNameSEL, L"FRAppRegistryGetEntryName"},
	{FRAppSEL, FRAppRegistryRemoveSectionSEL, L"FRAppRegistryRemoveSection"},
	{FRAppSEL, FRAppRegistryRemoveEntrySEL, L"FRAppRegistryRemoveEntry"},
	{FRAppSEL, FRAppGetGEModuleSEL, L"FRAppGetGEModule"},
	{FRAppSEL, FRAppGetModuleMgrSEL, L"FRAppGetModuleMgr"},
	{FRAppSEL, FRAppCreateAnEmptyFrameWndSEL, L"FRAppCreateAnEmptyFrameWnd"},
	{FRAppSEL, FRAppIsRunEmbeddedSEL, L"FRAppIsRunEmbedded"},
	{FRAppSEL, FRAppRegisterExtraPrintInfoProviderSEL, L"FRAppRegisterExtraPrintInfoProvider"},
	{FRAppSEL, FRAppIsRibbonModeSEL, L"FRAppIsRibbonMode"},
	{FRAppSEL, FRAppGetStartMenuOfTabbedToobarModeSEL, L"FRAppGetStartMenuOfTabbedToobarMode"},
	{FRAppSEL, FRAppRegisterTaskPaneViewSEL, L"FRAppRegisterTaskPaneView"},
	{FRAppSEL, FRAppShowTaskPaneSEL, L"FRAppShowTaskPane"},
	{FRAppSEL, FRAppGetTaskPaneWndHandleByDocSEL, L"FRAppGetTaskPaneWndHandleByDoc"},
	{FRAppSEL, FRAppCommandLineHasSwitchSEL, L"FRAppCommandLineHasSwitch"},
	{FRAppSEL, FRAppCommandLineGetSafeArgumentSEL, L"FRAppCommandLineGetSafeArgument"},
	{FRAppSEL, FRAppCommandLineGetArgumentSEL, L"FRAppCommandLineGetArgument"},
	{FRAppSEL, FRAppCommandLineGetArgumentCountSEL, L"FRAppCommandLineGetArgumentCount"},
	{FRAppSEL, FRAppRegisterWinMSGHandlerSEL, L"FRAppRegisterWinMSGHandler"},
	{FRAppSEL, FRAppGetRecentFileListSEL, L"FRAppGetRecentFileList"},
	{FRAppSEL, FRAppAddFileToRecentFileListSEL, L"FRAppAddFileToRecentFileList"},
	{FRAppSEL, FRAppClearRecentFileListSEL, L"FRAppClearRecentFileList"},
	{FRAppSEL, FRAppRegisterSecurityMethodSEL, L"FRAppRegisterSecurityMethod"},
	{FRAppSEL, FRAppPopDocPropertyPageSEL, L"FRAppPopDocPropertyPage"},
	{FRAppSEL, FRAppCountDocPropertyPagesSEL, L"FRAppCountDocPropertyPages"},
	{FRAppSEL, FRAppCheckModuleLicenseSEL, L"FRAppCheckModuleLicense"},
	{FRAppSEL, FRAppRegisterOwnerFileTypeSEL, L"FRAppRegisterOwnerFileType"},
	{FRAppSEL, FRAppRegistryGetKeyCountsSEL, L"FRAppRegistryGetKeyCounts"},
	{FRAppSEL, FRAppRegistryGetKeyNameSEL, L"FRAppRegistryGetKeyName"},
	{FRAppSEL, FRAppGetRibbonBarSEL, L"FRAppGetRibbonBar"},
	{FRAppSEL, FRAppGetRibbonBarBackGroundColorSEL, L"FRAppGetRibbonBarBackGroundColor"},
	{FRAppSEL, FRAppGetRibbonBarBtnBackGroundColorSEL, L"FRAppGetRibbonBarBtnBackGroundColor"},
	{FRAppSEL, FRAppLoadLibrarySEL, L"FRAppLoadLibrary"},
	{FRAppSEL, FRAppIsCurDocShowInBrowserSEL, L"FRAppIsCurDocShowInBrowser"},
	{FRAppSEL, FRAppRemoveFileFromRecentFileListSEL, L"FRAppRemoveFileFromRecentFileList"},
	{FRAppSEL, FRAppCreateCustomRecentFileListSEL, L"FRAppCreateCustomRecentFileList"},
	{FRAppSEL, FRAppRemoveFileFromCustomRecentFileListSEL, L"FRAppRemoveFileFromCustomRecentFileList"},
	{FRAppSEL, FRAppAddFileToCustomRecentFileListSEL, L"FRAppAddFileToCustomRecentFileList"},
	{FRAppSEL, FRAppClearCustomRecentFileListSEL, L"FRAppClearCustomRecentFileList"},
	{FRAppSEL, FRAppRegisterMousePtHandlerSEL, L"FRAppRegisterMousePtHandler"},
	{FRAppSEL, FRAppUnRegisterMousePtHandlerSEL, L"FRAppUnRegisterMousePtHandler"},
	{FRAppSEL, FRAppIsLicenseValidOrInTrialSEL, L"FRAppIsLicenseValidOrInTrial"},
	{FRAppSEL, FRAppShowPreferenceDlgSEL, L"FRAppShowPreferenceDlg"},
	{FRAppSEL, FRAppUndoRedoIsEditingSEL, L"FRAppUndoRedoIsEditing"},
	{FRAppSEL, FRAppUndoRedoBeginEditSEL, L"FRAppUndoRedoBeginEdit"},
	{FRAppSEL, FRAppUndoRedoEndEditSEL, L"FRAppUndoRedoEndEdit"},
	{FRAppSEL, FRAppRegisterWndProviderSEL, L"FRAppRegisterWndProvider"},
	{FRAppSEL, FRAppUnRegisterWndProviderSEL, L"FRAppUnRegisterWndProvider"},
	{FRAppSEL, FRAppGetEditionTypeSEL, L"FRAppGetEditionType"},
	{FRAppSEL, FRAppGetRecentFileListSizeSEL, L"FRAppGetRecentFileListSize"},
	{FRAppSEL, FRAppGetModuleFileNameSEL, L"FRAppGetModuleFileName"},
	{FRAppSEL, FRAppGetToolbarLockedSEL, L"FRAppGetToolbarLocked"},
	{FRAppSEL, FRAppSetToolbarLockedSEL, L"FRAppSetToolbarLocked"},
	{FRAppSEL, FRAppRegisterCmdMsgEventHandlerSEL, L"FRAppRegisterCmdMsgEventHandler"},
	{FRAppSEL, FRAppUnRegisterCmdMsgEventHandlerSEL, L"FRAppUnRegisterCmdMsgEventHandler"},
	{FRAppSEL, FRAppRemoveTaskPanelByNameSEL, L"FRAppRemoveTaskPanelByName"},
	{FRAppSEL, FRAppDisableAllPanelSEL, L"FRAppDisableAllPanel"},
	{FRAppSEL, FRAppIsDisableAllPanelSEL, L"FRAppIsDisableAllPanel"},
	{FRAppSEL, FRAppGetPageContextMenuPosSEL, L"FRAppGetPageContextMenuPos"},
	{FRAppSEL, FRAppOnCmdMsgByNameSEL, L"FRAppOnCmdMsgByName"},
	{FRAppSEL, FRAppSetOwnUndoModeSEL, L"FRAppSetOwnUndoMode"},
	{FRAppSEL, FRAppExitOwnUndoModeSEL, L"FRAppExitOwnUndoMode"},
	{FRAppSEL, FRAppRegisterActionHandlerSEL, L"FRAppRegisterActionHandler"},
	{FRAppSEL, FRAppRedrawRecentFileListSEL, L"FRAppRedrawRecentFileList"},
	{FRAppSEL, FRAppSetCustomRecentFileListLabelSEL, L"FRAppSetCustomRecentFileListLabel"},
	{FRAppSEL, FRAppSetCustomRecentFileListItemBitmapSEL, L"FRAppSetCustomRecentFileListItemBitmap"},
	{FRAppSEL, FRAppSetCustomRecentFileListMaxSizeSEL, L"FRAppSetCustomRecentFileListMaxSize"},
	{FRAppSEL, FRAppSetCustomRecentFileListItemTitleSEL, L"FRAppSetCustomRecentFileListItemTitle"},
	{FRAppSEL, FRAppSetCustomRecentFileListItemTooltipSEL, L"FRAppSetCustomRecentFileListItemTooltip"},
	{FRAppSEL, FRAppGetCustomRecentFileListItemCountSEL, L"FRAppGetCustomRecentFileListItemCount"},
	{FRAppSEL, FRAppIsRTLLanguageSEL, L"FRAppIsRTLLanguage"},
	{FRAppSEL, FRAppGetOEMVersionSEL, L"FRAppGetOEMVersion"},
	{FRAppSEL, FRAppRegisterDataCollectionHadlerSEL, L"FRAppRegisterDataCollectionHadler"},
	{FRAppSEL, FRAppGetUIParentWndByTaskPaneSEL, L"FRAppGetUIParentWndByTaskPane"},
	{FRAppSEL, FRAppAdvWndSetCustomizeSEL, L"FRAppAdvWndSetCustomize"},
	{FRAppSEL, FRAppGetAdvWndSEL, L"FRAppGetAdvWnd"},
	{FRAppSEL, FRAppShowAdvWndSEL, L"FRAppShowAdvWnd"},
	{FRAppSEL, FRAppRegisterPOEventHandlerSEL, L"FRAppRegisterPOEventHandler"},
	{FRAppSEL, FRAppCreateBlankDocSEL, L"FRAppCreateBlankDoc"},
	{FRAppSEL, FRAppGetLocalFontNameSEL, L"FRAppGetLocalFontName"},
	{FRAppSEL, FRAppReLoadStartPageSEL, L"FRAppReLoadStartPage"},
	{FRAppSEL, FRAppSetRecentFileListImageByExtSEL, L"FRAppSetRecentFileListImageByExt"},
	{FRAppSEL, FRAppGetCurMeasurementUnitsSEL, L"FRAppGetCurMeasurementUnits"},
	{FRAppSEL, FRAppGetNavPanelViewByNameSEL, L"FRAppGetNavPanelViewByName"},
	{FRAppSEL, FRAppGetNavPanelNameByIndexSEL, L"FRAppGetNavPanelNameByIndex"},
	{FRAppSEL, FRAppGetNavPanelCountSEL, L"FRAppGetNavPanelCount"},
	{FRAppSEL, FRAppGetStartAppModeSEL, L"FRAppGetStartAppMode"},
	{FRAppSEL, FRAppRestartProcessSEL, L"FRAppRestartProcess"},
	{FRAppSEL, FRAppGetStatusBarBkGroundColorSEL, L"FRAppGetStatusBarBkGroundColor"},
	{FRAppSEL, FRAppGetStatusBarBkGroundPathSEL, L"FRAppGetStatusBarBkGroundPath"},
	{FRAppSEL, FRAppCountAllTypesVisibleDocumentsSEL, L"FRAppCountAllTypesVisibleDocuments"},
	{FRAppSEL, FRAppAddFileToCustomRecentFileList2SEL, L"FRAppAddFileToCustomRecentFileList2"},
	{FRAppSEL, FRAppRegisterRibbonRecentFileEventHandlerSEL, L"FRAppRegisterRibbonRecentFileEventHandler"},
	{FRAppSEL, FRAppDestroyRibbonRecentFileEventHandlerSEL, L"FRAppDestroyRibbonRecentFileEventHandler"},
	{FRAppSEL, FRAppSetMetadataOptionSEL, L"FRAppSetMetadataOption"},
	{FRAppSEL, FRAppSetSubscriptionProviderSEL, L"FRAppSetSubscriptionProvider"},
	{FRAppSEL, FRAppDestroySubscriptionProviderSEL, L"FRAppDestroySubscriptionProvider"},
	{FRAppSEL, FRAppGetKeyfileStartAndExpireDateSEL, L"FRAppGetKeyfileStartAndExpireDate"},
	{FRAppSEL, FRAppGetRibbonCategoryColorSEL, L"FRAppGetRibbonCategoryColor"},
	{FRAppSEL, FRAppGetRibbonElementColorSEL, L"FRAppGetRibbonElementColor"},
	{FRAppSEL, FRAppGetRibbonBaseBorderColorSEL, L"FRAppGetRibbonBaseBorderColor"},
	{FRAppSEL, FRAppGetRecentFolderListSizeSEL, L"FRAppGetRecentFolderListSize"},
	{FRAppSEL, FRAppCreateEmptyFrameViewEventHandlerSEL, L"FRAppCreateEmptyFrameViewEventHandler"},
	{FRAppSEL, FRAppDestroyEmptyFrameViewEventHandlerSEL, L"FRAppDestroyEmptyFrameViewEventHandler"},
	{FRAppSEL, FRAppCreateAnEmptyFrameWnd2SEL, L"FRAppCreateAnEmptyFrameWnd2"},
	{FRAppSEL, FRAppIsReadModeSEL, L"FRAppIsReadMode"},
	{FRAppSEL, FRAppExitReadModeSEL, L"FRAppExitReadMode"},
	{FRAppSEL, FRAppGetCurrentChildFrmSEL, L"FRAppGetCurrentChildFrm"},
	{FRAppSEL, FRAppCollectDocActionDataSEL, L"FRAppCollectDocActionData"},
	{FRAppSEL, FRAppActiveChildFrameSEL, L"FRAppActiveChildFrame"},
	{FRAppSEL, FRAppCollectNormalDataSEL, L"FRAppCollectNormalData"},
	{FRAppSEL, FRAppSetMainframeShowSEL, L"FRAppSetMainframeShow"},
	{FRAppSEL, FRAppGetMainframeShowSEL, L"FRAppGetMainframeShow"},
	{FRAppSEL, FRAppGetRibbonTooltipBorderColorSEL, L"FRAppGetRibbonTooltipBorderColor"},
	{FRAppSEL, FRAppGetRecentFileIndexSEL, L"FRAppGetRecentFileIndex"},
	{FRAppSEL, FRAppFZipUnzipSEL, L"FRAppFZipUnzip"},
	{FRAppSEL, FRAppIsJSEnabledSEL, L"FRAppIsJSEnabled"},
	{FRAppSEL, FRAppSetEnableJSSEL, L"FRAppSetEnableJS"},
	{FRAppSEL, FRAppCollectNormalData2SEL, L"FRAppCollectNormalData2"},
	{FRAppSEL, FRAppCollectBitmapDataSEL, L"FRAppCollectBitmapData"},
	{FRAppSEL, FRAppIsNeedCollectDataSEL, L"FRAppIsNeedCollectData"},
	{FRAppSEL, FRAppIsFipsModeSEL, L"FRAppIsFipsMode"},
	{FRAppSEL, FRAppAddNavPanelViewSEL, L"FRAppAddNavPanelView"},
	{FRAppSEL, FRAppReleaseNavPanelViewSEL, L"FRAppReleaseNavPanelView"},
	{FRAppSEL, FRAppAddFileAttachmentSEL, L"FRAppAddFileAttachment"},
	{FRAppSEL, FRAppOpenFileAttachmentSEL, L"FRAppOpenFileAttachment"},
	{FRAppSEL, FRAppIsPDF2DocSEL, L"FRAppIsPDF2Doc"},
	{FRAppSEL, FRAppConvertToPDFSEL, L"FRAppConvertToPDF"},
	{FRAppSEL, FRAppRegisterPDFAPluginHandlerSEL, L"FRAppRegisterPDFAPluginHandler"},
	{FRAppSEL, FRAppConvertToPDFASEL, L"FRAppConvertToPDFA"},
	{FRAppSEL, FRAppAddLogSEL, L"FRAppAddLog"},
	{FRAppSEL, FRAppIsReaderOnlyModeSEL, L"FRAppIsReaderOnlyMode"},
	{FRAppSEL, FRAppGetMainFrameWndCountSEL, L"FRAppGetMainFrameWndCount"},
	{FRAppSEL, FRAppGetMainFrameWndByIndexSEL, L"FRAppGetMainFrameWndByIndex"},
	{FRAppSEL, FRAppGetModelessParentWndSEL, L"FRAppGetModelessParentWnd"},
	{FRAppSEL, FRAppIsMainfrmActivatingSEL, L"FRAppIsMainfrmActivating"},
	{FRAppSEL, FRAppGetRibbonBar2SEL, L"FRAppGetRibbonBar2"},
	{FRAppSEL, FRAppRefreshLayerPanelViewSEL, L"FRAppRefreshLayerPanelView"},
	{FRAppSEL, FRAppDeprecatedRegisterDRMSecurityHandlerSEL, L"FRAppDeprecatedRegisterDRMSecurityHandler"},
	{FRAppSEL, FRAppAddECMFileDialogSEL, L"FRAppAddECMFileDialog"},
	{FRAppSEL, FRAppECMFileDialogAddMenuItemSEL, L"FRAppECMFileDialogAddMenuItem"},
	{FRAppSEL, FRAppECMFileDialogItemSelectedSEL, L"FRAppECMFileDialogItemSelected"},
	{FRAppSEL, FRAppGetECMFileDialogSEL, L"FRAppGetECMFileDialog"},
	{FRAppSEL, FRAppGetSelectedECMPluginNameSEL, L"FRAppGetSelectedECMPluginName"},
	{FRAppSEL, FRAppGetMainClientAreaWndSEL, L"FRAppGetMainClientAreaWnd"},
	{FRAppSEL, FRAppRegisterPortfolioEventHandlerSEL, L"FRAppRegisterPortfolioEventHandler"},
	{FRAppSEL, FRAppAddECMUploadProcSEL, L"FRAppAddECMUploadProc"},
	{FRAppSEL, FRAppGetConvertPDFErrMsgSEL, L"FRAppGetConvertPDFErrMsg"},
	{FRAppSEL, FRAppECMFileDialogUploadProcSEL, L"FRAppECMFileDialogUploadProc"},
	{FRAppSEL, FRAppECMFileDialogRemoveMenuItemSEL, L"FRAppECMFileDialogRemoveMenuItem"},
	{FRAppSEL, FRAppCollectSensorDataSEL, L"FRAppCollectSensorData"},
	{FRAppSEL, FRAppGetSystemHandlerSEL, L"FRAppGetSystemHandler"},
	{FRAppSEL, FRAppCreateAndRegisterFormDesignerToolHandlerSEL, L"FRAppCreateAndRegisterFormDesignerToolHandler"},
	{FRAppSEL, FRAppShowModuleNoLicenseDlgSEL, L"FRAppShowModuleNoLicenseDlg"},
	{FRAppSEL, FRAppDeleteAnnotSEL, L"FRAppDeleteAnnot"},
	{FRAppSEL, FRAppDoModulePreferDlgSEL, L"FRAppDoModulePreferDlg"},
	{FRAppSEL, FRAppRegisterAnnotHandlerSEL, L"FRAppRegisterAnnotHandler"},
	{FRAppSEL, FRAppAddUndoItemCRSASEL, L"FRAppAddUndoItemCRSA"},
	{FRAppSEL, FRAppBaseAnnotLoadCursorSEL, L"FRAppBaseAnnotLoadCursor"},
	{FRAppSEL, FRAppAddDragPointSEL, L"FRAppAddDragPoint"},
	{FRAppSEL, FRAppGetSystemDefaultFontSEL, L"FRAppGetSystemDefaultFont"},
	{FRAppSEL, FRAppGetRSAAnnotElementSEL, L"FRAppGetRSAAnnotElement"},
	{FRAppSEL, FRAppGetPopupElementSEL, L"FRAppGetPopupElement"},
	{FRAppSEL, FRAppGetJSEngineHRuntimeSEL, L"FRAppGetJSEngineHRuntime"},
	{FRAppSEL, FRAppUnRegisterDocHandlerOfPDDocSEL, L"FRAppUnRegisterDocHandlerOfPDDoc"},
	{FRAppSEL, FRAppGetOperatorPermissionSEL, L"FRAppGetOperatorPermission"},
	{FRAppSEL, FRAppGetHContextSEL, L"FRAppGetHContext"},
	{FRAppSEL, FRAppJSGetGlobalObjectSEL, L"FRAppJSGetGlobalObject"},
	{FRAppSEL, FRAppJSSetUndefinedSEL, L"FRAppJSSetUndefined"},
	{FRAppSEL, FRAppJSValueSetSEL, L"FRAppJSValueSet"},
	{FRAppSEL, FRAppJSValueReleaseSEL, L"FRAppJSValueRelease"},
	{FRAppSEL, FRAppRegisterTransitionHandlerSEL, L"FRAppRegisterTransitionHandler"},
	{FRAppSEL, FRAppGetPreferenceIdentitySEL, L"FRAppGetPreferenceIdentity"},
	{FRAppSEL, FRAppJSRuntimeNewContextSEL, L"FRAppJSRuntimeNewContext"},
	{FRAppSEL, FRAppJSRuntimeReleaseContextSEL, L"FRAppJSRuntimeReleaseContext"},
	{FRAppSEL, FRAppIsRunIPFrameSEL, L"FRAppIsRunIPFrame"},
	{FRAppSEL, FRAppOwnerFileTypeHandlerDoEmailSEL, L"FRAppOwnerFileTypeHandlerDoEmail"},
	{FRAppSEL, FRAppGetEmailTabDocInfoSEL, L"FRAppGetEmailTabDocInfo"},
	{FRAppSEL, FRAppGetAULIBCurrentLanguageSEL, L"FRAppGetAULIBCurrentLanguage"},
	{FRAppSEL, FRAppGetIsEmailChoosePageRangeSEL, L"FRAppGetIsEmailChoosePageRange"},
	{FRAppSEL, FRAppAddECMFileDialog2SEL, L"FRAppAddECMFileDialog2"},
	{FRAppSEL, FRAppIsEditingUseHindiDigitsSEL, L"FRAppIsEditingUseHindiDigits"},
	{FRAppSEL, FRAppCountTaskPaneNameSEL, L"FRAppCountTaskPaneName"},
	{FRAppSEL, FRAppGetTaskPaneNameByIndexSEL, L"FRAppGetTaskPaneNameByIndex"},
	{FRAppSEL, FRAppGetDocUnitSEL, L"FRAppGetDocUnit"},
	{FRAppSEL, FRAppChangeUnitsSEL, L"FRAppChangeUnits"},
	{FRAppSEL, FRAppGetSelectedECMPluginAccountSEL, L"FRAppGetSelectedECMPluginAccount"},
	{FRAppSEL, FRAppAddECMFileDialog3SEL, L"FRAppAddECMFileDialog3"},
	{FRAppSEL, FRAppRegisterUserMessageHanlerSEL, L"FRAppRegisterUserMessageHanler"},
	{FRAppSEL, FRAppUnRegisterUserMessageHanlerSEL, L"FRAppUnRegisterUserMessageHanler"},
	{FRAppSEL, FRAppSetSGBaseHandlerSEL, L"FRAppSetSGBaseHandler"},
	{FRAppSEL, FRAppDestoryRibbonFloatySEL, L"FRAppDestoryRibbonFloaty"},
	{FRAppSEL, FRAppSetActiveTool2SEL, L"FRAppSetActiveTool2"},
	{FRAppSEL, FRAppGetRedirectURLSEL, L"FRAppGetRedirectURL"},
	{FRAppSEL, FRAppIsPortfolioSubDocSEL, L"FRAppIsPortfolioSubDoc"},
	{FRAppSEL, FRAppIsCurDocViewShowInContainerFrmSEL, L"FRAppIsCurDocViewShowInContainerFrm"},
	{FRAppSEL, FRAppCheckTrustySitesSEL, L"FRAppCheckTrustySites"},
	{FRAppSEL, FRAppIsLinearizeSaveAsSEL, L"FRAppIsLinearizeSaveAs"},
	{FRAppSEL, FRAppGetMetaDataOptionSEL, L"FRAppGetMetaDataOption"},
	{FRAppSEL, FRAppIsECMDocumentSEL, L"FRAppIsECMDocument"},
	{FRAppSEL, FRAppGetDocumentSEL, L"FRAppGetDocument"},
	{FRAppSEL, FRAppRunFieldFormatSEL, L"FRAppRunFieldFormat"},
	{FRAppSEL, FRAppRemoveMapFormat2DocSEL, L"FRAppRemoveMapFormat2Doc"},
	{FRAppSEL, FRAppDownLoadAddonSEL, L"FRAppDownLoadAddon"},
	{FRAppSEL, FRAppGetDocProducerSEL, L"FRAppGetDocProducer"},
	{FRAppSEL, FRAppSetSignatureCheckSEL, L"FRAppSetSignatureCheck"},
	{FRAppSEL, FRAppDocRunOCRFinishSEL, L"FRAppDocRunOCRFinish"},
	{FRAppSEL, FRAppAddShareMessageBarSEL, L"FRAppAddShareMessageBar"},
	{FRAppSEL, FRAppShowShareMessageBarSEL, L"FRAppShowShareMessageBar"},
	{FRAppSEL, FRAppSetCurrentStartPageTabSEL, L"FRAppSetCurrentStartPageTab"},
	{FRAppSEL, FRAppGetAppPathSEL, L"FRAppGetAppPath"},
	{FRAppSEL, FRAppAddTrialDayDlgToCategorySEL, L"FRAppAddTrialDayDlgToCategory"},
	{FRAppSEL, FRAppRegisterPanelToolHandlerSEL, L"FRAppRegisterPanelToolHandler"},
	{FRAppSEL, FRAppIsTaskPaneShowSEL, L"FRAppIsTaskPaneShow"},
	{FRAppSEL, FRAppGetCurrentDocumentByFrameSEL, L"FRAppGetCurrentDocumentByFrame"},
	{FRAppSEL, FRAppSendUserDataMessageToAppSEL, L"FRAppSendUserDataMessageToApp"},
	{FRAppSEL, FRAppShowReadModeSEL, L"FRAppShowReadMode"},
	{FRAppSEL, FRAppLoadUnitStringSEL, L"FRAppLoadUnitString"},
	{FRAppSEL, FRAppSetECMFileDialogSensorDataTypeSEL, L"FRAppSetECMFileDialogSensorDataType"},
	{FRAppSEL, FRAppGetReplaceColorsSEL, L"FRAppGetReplaceColors"},
	{FRAppSEL, FRAppGetFileTypeCanSupportOpenSEL, L"FRAppGetFileTypeCanSupportOpen"},
	{FRAppSEL, FRAppOnDocPageLabelChangeSEL, L"FRAppOnDocPageLabelChange"},
	{FRAppSEL, FRAppSetCurrentToolByNameSEL, L"FRAppSetCurrentToolByName"},
	{FRAppSEL, FRAppWillSignatureDocSEL, L"FRAppWillSignatureDoc"},
	{FRAppSEL, FRAppDidSignatureDocSEL, L"FRAppDidSignatureDoc"},
	{FRAppSEL, FRAppDeleteUnusedFontSEL, L"FRAppDeleteUnusedFont"},
	{FRAppSEL, FRAppGetIsEditorAppSEL, L"FRAppGetIsEditorApp"},
	{FRAppSEL, FRAppOpenNewDocViewFrameSEL, L"FRAppOpenNewDocViewFrame"},
	{FRAppSEL, FRAppSetActiveTabByHWNDSEL, L"FRAppSetActiveTabByHWND"},
	{FRAppSEL, FRAppPopDocPropertyPage2SEL, L"FRAppPopDocPropertyPage2"},
	{FRAppSEL, FRAppRegisterPluginEventHandlerSEL, L"FRAppRegisterPluginEventHandler"},
	{FRAppSEL, FRAppUnregisterPluginEventHandlerSEL, L"FRAppUnregisterPluginEventHandler"},
	{FRAppSEL, FRAppSetDocCanSaveSessionSEL, L"FRAppSetDocCanSaveSession"},
	{FRAppSEL, FRAppGetBitmapFromClipboardSEL, L"FRAppGetBitmapFromClipboard"},
	{FRAppSEL, FRAppUnRegisterSecurityHandler2SEL, L"FRAppUnRegisterSecurityHandler2"},
	{FRAppSEL, FRAppToDecryptFileSEL, L"FRAppToDecryptFile"},
	{FRAppSEL, FRAppDeleteDecryptFileSEL, L"FRAppDeleteDecryptFile"},
	{FRAppSEL, FRAppUnRegisterPOEventHandlerSEL, L"FRAppUnRegisterPOEventHandler"},
	{FRAppSEL, FRAppUnRegisterToolSEL, L"FRAppUnRegisterTool"},
	{FRAppSEL, FRAppIsHideWndTaskSEL, L"FRAppIsHideWndTask"},
	{FRAppSEL, FRAppSetHideWndTaskSEL, L"FRAppSetHideWndTask"},
	{FRAppSEL, FRAppRegisterDRMEventHandlerSEL, L"FRAppRegisterDRMEventHandler"},
	{FRAppSEL, FRAppUnRegisterDRMEventHandlerSEL, L"FRAppUnRegisterDRMEventHandler"},
	{FRAppSEL, FRAppAddTrialDayDlgToCategory2SEL, L"FRAppAddTrialDayDlgToCategory2"},
	{FRAppSEL, FRAppCheckIsContinueSEL, L"FRAppCheckIsContinue"},
	{FRAppSEL, FRAppCheckIsOldSubProcessSEL, L"FRAppCheckIsOldSubProcess"},
	{FRAppSEL, FRAppGetAppDataRootPathSEL, L"FRAppGetAppDataRootPath"},
	{FRAppSEL, FRAppGetActiveTaskNameSEL, L"FRAppGetActiveTaskName"},
	{FRAppSEL, FRAppShowTaskPane2SEL, L"FRAppShowTaskPane2"},
	{FRAppSEL, FRAppIsDocRedactSaveToSaveAsSEL, L"FRAppIsDocRedactSaveToSaveAs"},
	{FRAppSEL, FRAppUpdateCustomRecentFileListSEL, L"FRAppUpdateCustomRecentFileList"},
	{FRAppSEL, FRAppCreateColorDialogSEL, L"FRAppCreateColorDialog"},
	{FRAppSEL, FRAppSetNotifySEL, L"FRAppSetNotify"},
	{FRAppSEL, FRAppShowColorDialogSEL, L"FRAppShowColorDialog"},
	{FRAppSEL, FRAppIsTaskPaneInTabSEL, L"FRAppIsTaskPaneInTab"},
	{FRAppSEL, FRAppIsRunOfficeEmbededSEL, L"FRAppIsRunOfficeEmbeded"},
	{FRAppSEL, FRAppIsStartPageClosedSEL, L"FRAppIsStartPageClosed"},
	{FRAppSEL, FRAppShowAboutPluginsSEL, L"FRAppShowAboutPlugins"},
	{FRAppSEL, FRAppSetFindResultHighlightColorSEL, L"FRAppSetFindResultHighlightColor"},
	{FRAppSEL, FRAppGetFindResultHighlightColorSEL, L"FRAppGetFindResultHighlightColor"},
	{FRAppSEL, FRAppSetFindResultHighlightOpacitySEL, L"FRAppSetFindResultHighlightOpacity"},
	{FRAppSEL, FRAppGetFindResultHighlightOpacitySEL, L"FRAppGetFindResultHighlightOpacity"},
	{FRAppSEL, FRAppRegisterStartPageEventHandlerSEL, L"FRAppRegisterStartPageEventHandler"},
	{FRAppSEL, FRAppUnRegisterStartPageEventHandlerSEL, L"FRAppUnRegisterStartPageEventHandler"},
	{FRAppSEL, FRAppRegisterUndoEventHandlerSEL, L"FRAppRegisterUndoEventHandler"},
	{FRAppSEL, FRAppUnRegisterUndoEventHandlerSEL, L"FRAppUnRegisterUndoEventHandler"},
	{FRAppSEL, FRAppGetPDFAViewModeSEL, L"FRAppGetPDFAViewMode"},
	{FRAppSEL, FRAppIsProtectedModeByPathSEL, L"FRAppIsProtectedModeByPath"},
	{FRAppSEL, FRAppAddFileAttachment2SEL, L"FRAppAddFileAttachment2"},
	{FRAppSEL, FRAppInitAESV4CryptoHandlerSEL, L"FRAppInitAESV4CryptoHandler"},
	{FRAppSEL, FRAppCombinePDFSEL, L"FRAppCombinePDF"},
	{FRAppSEL, FRAppLaunchSEL, L"FRAppLaunch"},
	{FRLanguageSEL, FRLanguageCreateSEL, L"FRLanguageCreate"},
	{FRLanguageSEL, FRLanguageReleaseSEL, L"FRLanguageRelease"},
	{FRLanguageSEL, FRLanguageChangeSEL, L"FRLanguageChange"},
	{FRLanguageSEL, FRLanguageGetCurrentIDSEL, L"FRLanguageGetCurrentID"},
	{FRLanguageSEL, FRLanguageTranslateMenuSEL, L"FRLanguageTranslateMenu"},
	{FRLanguageSEL, FRLanguageTranslateDialogSEL, L"FRLanguageTranslateDialog"},
	{FRLanguageSEL, FRLanguageLoadStringSEL, L"FRLanguageLoadString"},
	{FRLanguageSEL, FRLanguageLoadVersionResSEL, L"FRLanguageLoadVersionRes"},
	{FRLanguageSEL, FRLanguageGetLocalLangNameSEL, L"FRLanguageGetLocalLangName"},
	{FRLanguageSEL, FRLanguageTranslateDialog2SEL, L"FRLanguageTranslateDialog2"},
	{FRLanguageSEL, FRLanguageModifyLogFontSEL, L"FRLanguageModifyLogFont"},
	{FRLanguageSEL, FRLanguageFormatExSEL, L"FRLanguageFormatEx"},
	{FRLanguageSEL, FRLanguageJSPluginGetMessageSEL, L"FRLanguageJSPluginGetMessage"},
	{FRLanguageSEL, FRLanguageReleaseDialogUIFontSEL, L"FRLanguageReleaseDialogUIFont"},
	{FRUIProgressSEL, FRUIProgressCreateSEL, L"FRUIProgressCreate"},
	{FRUIProgressSEL, FRUIProgressSetTextSEL, L"FRUIProgressSetText"},
	{FRUIProgressSEL, FRUIProgressSetRangeSEL, L"FRUIProgressSetRange"},
	{FRUIProgressSEL, FRUIProgressSetCurrValueSEL, L"FRUIProgressSetCurrValue"},
	{FRUIProgressSEL, FRUIProgressPeekAndPumpSEL, L"FRUIProgressPeekAndPump"},
	{FRUIProgressSEL, FRUIProgressIsCancelledSEL, L"FRUIProgressIsCancelled"},
	{FRUIProgressSEL, FRUIProgressGetCurrentValueSEL, L"FRUIProgressGetCurrentValue"},
	{FRUIProgressSEL, FRUIProgressDestroySEL, L"FRUIProgressDestroy"},
	{FRUIProgressSEL, FRUIProgressDoCancelSEL, L"FRUIProgressDoCancel"},
	{FRUIProgressSEL, FRUIProgressCreate2SEL, L"FRUIProgressCreate2"},
	{FRUIProgressSEL, FRUIProgressCreate3SEL, L"FRUIProgressCreate3"},
	{FRUIProgressSEL, FRUIProgressGetHwndSEL, L"FRUIProgressGetHwnd"},
	{FRUIProgressSEL, FRUIProgressSetSecondLineTextSEL, L"FRUIProgressSetSecondLineText"},
	{FRUIProgressSEL, FRUIProgressGetTextSEL, L"FRUIProgressGetText"},
// fr_appImpl.h end

// In file fr_barImpl.h
	{FRToolButtonSEL, FRToolButtonNewSEL, L"FRToolButtonNew"},
	{FRToolButtonSEL, FRToolButtonReleaseSEL, L"FRToolButtonRelease"},
	{FRToolButtonSEL, FRToolButtonGetNameSEL, L"FRToolButtonGetName"},
	{FRToolButtonSEL, FRToolButtonGetLabelTextSEL, L"FRToolButtonGetLabelText"},
	{FRToolButtonSEL, FRToolButtonSetLabelTextSEL, L"FRToolButtonSetLabelText"},
	{FRToolButtonSEL, FRToolButtonSetHelpTextSEL, L"FRToolButtonSetHelpText"},
	{FRToolButtonSEL, FRToolButtonSetIconSEL, L"FRToolButtonSetIcon"},
	{FRToolButtonSEL, FRToolButtonIsSeparatorSEL, L"FRToolButtonIsSeparator"},
	{FRToolButtonSEL, FRToolButtonIsVisibleSEL, L"FRToolButtonIsVisible"},
	{FRToolButtonSEL, FRToolButtonSetExecuteProcSEL, L"FRToolButtonSetExecuteProc"},
	{FRToolButtonSEL, FRToolButtonSetEnableProcSEL, L"FRToolButtonSetEnableProc"},
	{FRToolButtonSEL, FRToolButtonSetMarkedProcSEL, L"FRToolButtonSetMarkedProc"},
	{FRToolButtonSEL, FRToolButtonSetDropDownProcSEL, L"FRToolButtonSetDropDownProc"},
	{FRToolButtonSEL, FRToolButtonGetClientDataSEL, L"FRToolButtonGetClientData"},
	{FRToolButtonSEL, FRToolButtonExecuteProcSEL, L"FRToolButtonExecuteProc"},
	{FRToolButtonSEL, FRToolButtonSetFlyoutToolBarSEL, L"FRToolButtonSetFlyoutToolBar"},
	{FRToolButtonSEL, FRToolButtonGetMapIdSEL, L"FRToolButtonGetMapId"},
	{FRToolButtonSEL, FRToolButtonSetClientDataSEL, L"FRToolButtonSetClientData"},
	{FRToolBarSEL, FRToolBarNewSEL, L"FRToolBarNew"},
	{FRToolBarSEL, FRToolBarNewFlyoutSEL, L"FRToolBarNewFlyout"},
	{FRToolBarSEL, FRToolBarReleaseSEL, L"FRToolBarRelease"},
	{FRToolBarSEL, FRToolBarGetNameSEL, L"FRToolBarGetName"},
	{FRToolBarSEL, FRToolBarCountButtonsSEL, L"FRToolBarCountButtons"},
	{FRToolBarSEL, FRToolBarGetButtonSEL, L"FRToolBarGetButton"},
	{FRToolBarSEL, FRToolBarGetTitleSEL, L"FRToolBarGetTitle"},
	{FRToolBarSEL, FRToolBarSetTitleSEL, L"FRToolBarSetTitle"},
	{FRToolBarSEL, FRToolBarGetButtonByNameSEL, L"FRToolBarGetButtonByName"},
	{FRToolBarSEL, FRToolBarAddButtonSEL, L"FRToolBarAddButton"},
	{FRToolBarSEL, FRToolBarInsertButtonSEL, L"FRToolBarInsertButton"},
	{FRToolBarSEL, FRToolBarShowToolBarSEL, L"FRToolBarShowToolBar"},
	{FRToolBarSEL, FRToolBarHideToolBarSEL, L"FRToolBarHideToolBar"},
	{FRToolBarSEL, FRToolBarShowToolButtonSEL, L"FRToolBarShowToolButton"},
	{FRToolBarSEL, FRToolBarHideToolButtonSEL, L"FRToolBarHideToolButton"},
	{FRToolBarSEL, FRToolBarRemoveButtonSEL, L"FRToolBarRemoveButton"},
	{FRToolBarSEL, FRToolBarUpdateButtonStatesSEL, L"FRToolBarUpdateButtonStates"},
	{FRToolBarSEL, FRToolBarIsFlyOutToolbarSEL, L"FRToolBarIsFlyOutToolbar"},
	{FRToolBarSEL, FRToolBarSetMenuTitleSEL, L"FRToolBarSetMenuTitle"},
	{FRToolBarSEL, FRToolBarSetDefaultToolbarSEL, L"FRToolBarSetDefaultToolbar"},
	{FRToolBarSEL, FRToolBarHideButtonInBrowserSEL, L"FRToolBarHideButtonInBrowser"},
	{FRToolBarSEL, FRToolBarIsVisibleSEL, L"FRToolBarIsVisible"},
	{FRToolBarSEL, FRToolBarIsDisableSEL, L"FRToolBarIsDisable"},
	{FRToolBarSEL, FRToolBarSetDisableSEL, L"FRToolBarSetDisable"},
	{FRToolBarSEL, FRToolBarDockSEL, L"FRToolBarDock"},
	{FRMessageBarSEL, FRMessageBarCreateSEL, L"FRMessageBarCreate"},
	{FRMessageBarSEL, FRMessageBarDestroySEL, L"FRMessageBarDestroy"},
	{FRMessageBarSEL, FRMessageBarShowSEL, L"FRMessageBarShow"},
	{FRMessageBarSEL, FRMessageBarIsVisibleSEL, L"FRMessageBarIsVisible"},
	{FRMessageBarSEL, FRMessageBarSetTextSEL, L"FRMessageBarSetText"},
	{FRMessageBarSEL, FRMessageBarSetBitmapSEL, L"FRMessageBarSetBitmap"},
	{FRMessageBarSEL, FRMessageBarAddButtonSEL, L"FRMessageBarAddButton"},
	{FRMessageBarSEL, FRMessageBarSetButtonAlignmentSEL, L"FRMessageBarSetButtonAlignment"},
	{FRMessageBarSEL, FRMessageBarSetButtonDropDownProcSEL, L"FRMessageBarSetButtonDropDownProc"},
	{FRMessageBarSEL, FRMessageBarSetButtonExecuteProcSEL, L"FRMessageBarSetButtonExecuteProc"},
	{FRMessageBarSEL, FRMessageBarSetButtonHelpTextSEL, L"FRMessageBarSetButtonHelpText"},
	{FRMessageBarSEL, FRMessageBarEnableButtonSEL, L"FRMessageBarEnableButton"},
	{FRMessageBarSEL, FRMessageBarSetButtonPressedSEL, L"FRMessageBarSetButtonPressed"},
	{FRMessageBarSEL, FRMessageBarSetClientDataSEL, L"FRMessageBarSetClientData"},
	{FRMessageBarSEL, FRMessageBarAddButtonImageSEL, L"FRMessageBarAddButtonImage"},
	{FRMessageBarSEL, FRMessageBarGetButtonImageSEL, L"FRMessageBarGetButtonImage"},
	{FRMessageBarSEL, FRMessageBarChangeButtonSEL, L"FRMessageBarChangeButton"},
	{FRMessageBarSEL, FRMessageBarIsButtonEnableSEL, L"FRMessageBarIsButtonEnable"},
	{FRMessageBarSEL, FRMessageBarCountVisibleMessageBarsSEL, L"FRMessageBarCountVisibleMessageBars"},
	{FRMessageBarSEL, FRMessageBarGetVisibleMessageBarSEL, L"FRMessageBarGetVisibleMessageBar"},
	{FRMessageBarSEL, FRMessageBarSetBitmap2SEL, L"FRMessageBarSetBitmap2"},
	{FRMessageBarSEL, FRMessageBarAddButton2SEL, L"FRMessageBarAddButton2"},
	{FRMessageBarSEL, FRMessageBarAddButtonImage2SEL, L"FRMessageBarAddButtonImage2"},
// fr_barImpl.h end

// In file fr_docImpl.h
	{FRDocSEL, FRDocOpenFromFileSEL, L"FRDocOpenFromFile"},
	{FRDocSEL, FRDocOpenFromPDDocSEL, L"FRDocOpenFromPDDoc"},
	{FRDocSEL, FRDocFromPDDocSEL, L"FRDocFromPDDoc"},
	{FRDocSEL, FRDocCloseSEL, L"FRDocClose"},
	{FRDocSEL, FRDocGetPDDocSEL, L"FRDocGetPDDoc"},
	{FRDocSEL, FRDocSetCustomSecuritySEL, L"FRDocSetCustomSecurity"},
	{FRDocSEL, FRDocDoSaveSEL, L"FRDocDoSave"},
	{FRDocSEL, FRDocDoSaveAsSEL, L"FRDocDoSaveAs"},
	{FRDocSEL, FRDocSetChangeMarkSEL, L"FRDocSetChangeMark"},
	{FRDocSEL, FRDocGetChangeMarkSEL, L"FRDocGetChangeMark"},
	{FRDocSEL, FRDocClearChangeMarkSEL, L"FRDocClearChangeMark"},
	{FRDocSEL, FRDocWillInsertPagesSEL, L"FRDocWillInsertPages"},
	{FRDocSEL, FRDocDidInsertPagesSEL, L"FRDocDidInsertPages"},
	{FRDocSEL, FRDocWillDeletePagesSEL, L"FRDocWillDeletePages"},
	{FRDocSEL, FRDocDidDeletePagesSEL, L"FRDocDidDeletePages"},
	{FRDocSEL, FRDocWillRotatePageSEL, L"FRDocWillRotatePage"},
	{FRDocSEL, FRDocDidRotatePageSEL, L"FRDocDidRotatePage"},
	{FRDocSEL, FRDocWillResizePageSEL, L"FRDocWillResizePage"},
	{FRDocSEL, FRDocDidResizePageSEL, L"FRDocDidResizePage"},
	{FRDocSEL, FRDocDoPrintSEL, L"FRDocDoPrint"},
	{FRDocSEL, FRDocPrintPagesSEL, L"FRDocPrintPages"},
	{FRDocSEL, FRDocPrintSetupSEL, L"FRDocPrintSetup"},
	{FRDocSEL, FRDocCountDocViewsSEL, L"FRDocCountDocViews"},
	{FRDocSEL, FRDocGetDocViewSEL, L"FRDocGetDocView"},
	{FRDocSEL, FRDocGetCurrentDocViewSEL, L"FRDocGetCurrentDocView"},
	{FRDocSEL, FRDocGetPermissionsSEL, L"FRDocGetPermissions"},
	{FRDocSEL, FRDocSetPermissionsSEL, L"FRDocSetPermissions"},
	{FRDocSEL, FRDocGetFilePathSEL, L"FRDocGetFilePath"},
	{FRDocSEL, FRDocSetCurSelectionSEL, L"FRDocSetCurSelection"},
	{FRDocSEL, FRDocAddToCurrentSelectionSEL, L"FRDocAddToCurrentSelection"},
	{FRDocSEL, FRDocRemoveFromSelectionSEL, L"FRDocRemoveFromSelection"},
	{FRDocSEL, FRDocGetCurSelectionSEL, L"FRDocGetCurSelection"},
	{FRDocSEL, FRDocGetCurSelectionTypeSEL, L"FRDocGetCurSelectionType"},
	{FRDocSEL, FRDocShowSelectionSEL, L"FRDocShowSelection"},
	{FRDocSEL, FRDocClearSelectionSEL, L"FRDocClearSelection"},
	{FRDocSEL, FRDocDeleteSelectionSEL, L"FRDocDeleteSelection"},
	{FRDocSEL, FRDocCopySelectionSEL, L"FRDocCopySelection"},
	{FRDocSEL, FRDocSetCurCaptureSEL, L"FRDocSetCurCapture"},
	{FRDocSEL, FRDocGetCurCaptureSEL, L"FRDocGetCurCapture"},
	{FRDocSEL, FRDocGetCurCaptureTypeSEL, L"FRDocGetCurCaptureType"},
	{FRDocSEL, FRDocReleaseCurCaptureSEL, L"FRDocReleaseCurCapture"},
	{FRDocSEL, FRDocSetMenuEnableByNameSEL, L"FRDocSetMenuEnableByName"},
	{FRDocSEL, FRDocGetParserSEL, L"FRDocGetParser"},
	{FRDocSEL, FRDocGetPDFCreatorSEL, L"FRDocGetPDFCreator"},
	{FRDocSEL, FRDocDoPrintSilentlySEL, L"FRDocDoPrintSilently"},
	{FRDocSEL, FRDocGetTextSelectToolSEL, L"FRDocGetTextSelectTool"},
	{FRDocSEL, FRDocGetDocumentTypeSEL, L"FRDocGetDocumentType"},
	{FRDocSEL, FRDocCanSecurityMethodBeModifiedSEL, L"FRDocCanSecurityMethodBeModified"},
	{FRDocSEL, FRDocUpdateSecurityMethodSEL, L"FRDocUpdateSecurityMethod"},
	{FRDocSEL, FRDocIsEncryptedSEL, L"FRDocIsEncrypted"},
	{FRDocSEL, FRDocRemoveSecurityMethodSEL, L"FRDocRemoveSecurityMethod"},
	{FRDocSEL, FRDocEnableRunScriptSEL, L"FRDocEnableRunScript"},
	{FRDocSEL, FRDocIsEnableRunScriptSEL, L"FRDocIsEnableRunScript"},
	{FRDocSEL, FRDocChangeDocShowTitleSEL, L"FRDocChangeDocShowTitle"},
	{FRDocSEL, FRDocIsMemoryDocSEL, L"FRDocIsMemoryDoc"},
	{FRDocSEL, FRDocGetCurrentSecurityMethodNameSEL, L"FRDocGetCurrentSecurityMethodName"},
	{FRDocSEL, FRDocGetCurrentWndProviderSEL, L"FRDocGetCurrentWndProvider"},
	{FRDocSEL, FRDocSetCurrentWndProviderSEL, L"FRDocSetCurrentWndProvider"},
	{FRDocSEL, FRDocGetWndProviderByNameSEL, L"FRDocGetWndProviderByName"},
	{FRDocSEL, FRDocGetReviewTypeSEL, L"FRDocGetReviewType"},
	{FRDocSEL, FRDocSetReviewTypeSEL, L"FRDocSetReviewType"},
	{FRDocSEL, FRDocSetAppPermissionsSEL, L"FRDocSetAppPermissions"},
	{FRDocSEL, FRDocGetAppPermissionsSEL, L"FRDocGetAppPermissions"},
	{FRDocSEL, FRDocGetAppPermissionsIISEL, L"FRDocGetAppPermissionsII"},
	{FRDocSEL, FRDocGetPermissionsIISEL, L"FRDocGetPermissionsII"},
	{FRDocSEL, FRDocGetMergedPermissionsSEL, L"FRDocGetMergedPermissions"},
	{FRDocSEL, FRDocKillFocusAnnotSEL, L"FRDocKillFocusAnnot"},
	{FRDocSEL, FRDocSetPropertiesPDFVersionSEL, L"FRDocSetPropertiesPDFVersion"},
	{FRDocSEL, FRDocSetPropertiesFilePathSEL, L"FRDocSetPropertiesFilePath"},
	{FRDocSEL, FRDocDoSaveAs2SEL, L"FRDocDoSaveAs2"},
	{FRDocSEL, FRDocShowSaveProgressCancelButtonSEL, L"FRDocShowSaveProgressCancelButton"},
	{FRDocSEL, FRDocSetInputPasswordProcSEL, L"FRDocSetInputPasswordProc"},
	{FRDocSEL, FRDocCheckInDocumentOLESEL, L"FRDocCheckInDocumentOLE"},
	{FRDocSEL, FRDocIsShowInBrowserSEL, L"FRDocIsShowInBrowser"},
	{FRDocSEL, FRDocGetUIParentWndSEL, L"FRDocGetUIParentWnd"},
	{FRDocSEL, FRDocGetDocFrameHandlerSEL, L"FRDocGetDocFrameHandler"},
	{FRDocSEL, FRDocCreateNewViewByWndProviderSEL, L"FRDocCreateNewViewByWndProvider"},
	{FRDocSEL, FRDocLoadAnnotsSEL, L"FRDocLoadAnnots"},
	{FRDocSEL, FRDocGetDocShowTitleSEL, L"FRDocGetDocShowTitle"},
	{FRDocSEL, FRDocDoSave2SEL, L"FRDocDoSave2"},
	{FRDocSEL, FRDocResetDocTitleColorSEL, L"FRDocResetDocTitleColor"},
	{FRDocSEL, FRDocSetDocTitleColorSEL, L"FRDocSetDocTitleColor"},
	{FRDocSEL, FRDocGetOriginalTypeSEL, L"FRDocGetOriginalType"},
	{FRDocSEL, FRDocSetOriginalTypeSEL, L"FRDocSetOriginalType"},
	{FRDocSEL, FRDocSetFocusAnnotSEL, L"FRDocSetFocusAnnot"},
	{FRDocSEL, FRDocGenerateUR3PermissionSEL, L"FRDocGenerateUR3Permission"},
	{FRDocSEL, FRDocHasRedactAnnotSEL, L"FRDocHasRedactAnnot"},
	{FRDocSEL, FRDocGenerateRedactionsSEL, L"FRDocGenerateRedactions"},
	{FRDocSEL, FRDocReloadPageSEL, L"FRDocReloadPage"},
	{FRDocSEL, FRDocForbidChangeMarkSEL, L"FRDocForbidChangeMark"},
	{FRDocSEL, FRDocOpenFromPDDoc2SEL, L"FRDocOpenFromPDDoc2"},
	{FRDocSEL, FRDocGetCreateDocSourceSEL, L"FRDocGetCreateDocSource"},
	{FRDocSEL, FRDocSetCreateDocSourceSEL, L"FRDocSetCreateDocSource"},
	{FRDocSEL, FRDocGetCreateDocSourceFileNameSEL, L"FRDocGetCreateDocSourceFileName"},
	{FRDocSEL, FRDocParsePageSEL, L"FRDocParsePage"},
	{FRDocSEL, FRDocIsValidAnnotSEL, L"FRDocIsValidAnnot"},
	{FRDocSEL, FRDocIsWillReopenSEL, L"FRDocIsWillReopen"},
	{FRDocSEL, FRDocOpenFromFile2SEL, L"FRDocOpenFromFile2"},
	{FRDocSEL, FRDocGetSignaturePermissionsSEL, L"FRDocGetSignaturePermissions"},
	{FRDocSEL, FRDocConvertPdfToOtherFormatSEL, L"FRDocConvertPdfToOtherFormat"},
	{FRDocSEL, FRDocDoPassWordEncryptSEL, L"FRDocDoPassWordEncrypt"},
	{FRDocSEL, FRDocIsInProtectedViewModeSEL, L"FRDocIsInProtectedViewMode"},
	{FRDocSEL, FRDocGetCreateDocSourceFilePathSEL, L"FRDocGetCreateDocSourceFilePath"},
	{FRDocSEL, FRDocIsImageBasedDocumentSEL, L"FRDocIsImageBasedDocument"},
	{FRDocSEL, FRDocSetDocEncryptedSEL, L"FRDocSetDocEncrypted"},
	{FRDocSEL, FRDocIsVisibleSEL, L"FRDocIsVisible"},
	{FRDocSEL, FRDocDeprecatedSetDRMSecuritySEL, L"FRDocDeprecatedSetDRMSecurity"},
	{FRDocSEL, FRDocConvertPdfToOtherFormat2SEL, L"FRDocConvertPdfToOtherFormat2"},
	{FRDocSEL, FRDocAddWatermarkSEL, L"FRDocAddWatermark"},
	{FRDocSEL, FRDocAddAndUpdateWatermarkSEL, L"FRDocAddAndUpdateWatermark"},
	{FRDocSEL, FRDocRemoveWatermarkSEL, L"FRDocRemoveWatermark"},
	{FRDocSEL, FRDocRemoveAndUpdateWatermarkSEL, L"FRDocRemoveAndUpdateWatermark"},
	{FRDocSEL, FRDocAddHeaderFooterSEL, L"FRDocAddHeaderFooter"},
	{FRDocSEL, FRDocAddAndUpdateHeaderFooterSEL, L"FRDocAddAndUpdateHeaderFooter"},
	{FRDocSEL, FRDocRemoveHeaderFooterSEL, L"FRDocRemoveHeaderFooter"},
	{FRDocSEL, FRDocRemoveAndUpdateHeaderFooterSEL, L"FRDocRemoveAndUpdateHeaderFooter"},
	{FRDocSEL, FRDocIsReadSafeModeSEL, L"FRDocIsReadSafeMode"},
	{FRDocSEL, FRDocGetInterFormSEL, L"FRDocGetInterForm"},
	{FRDocSEL, FRDocReplaceTextToSelectedTextSEL, L"FRDocReplaceTextToSelectedText"},
	{FRDocSEL, FRDocGeneratePageContentSEL, L"FRDocGeneratePageContent"},
	{FRDocSEL, FRDocGetFocusAnnotSEL, L"FRDocGetFocusAnnot"},
	{FRDocSEL, FRDocGetMenuEnableByNameSEL, L"FRDocGetMenuEnableByName"},
	{FRDocSEL, FRDocClearAllSelectionSEL, L"FRDocClearAllSelection"},
	{FRDocSEL, FRDocAddSelectionSEL, L"FRDocAddSelection"},
	{FRDocSEL, FRDocGetPageFirstAnnotSEL, L"FRDocGetPageFirstAnnot"},
	{FRDocSEL, FRDocCreateFormControlSEL, L"FRDocCreateFormControl"},
	{FRDocSEL, FRDocReCalTabOrderSEL, L"FRDocReCalTabOrder"},
	{FRDocSEL, FRDocNotifyAddWidgetSEL, L"FRDocNotifyAddWidget"},
	{FRDocSEL, FRDocUpdateAllViewsSEL, L"FRDocUpdateAllViews"},
	{FRDocSEL, FRDocGetAnnotByDictSEL, L"FRDocGetAnnotByDict"},
	{FRDocSEL, FRDocAddAnnotSEL, L"FRDocAddAnnot"},
	{FRDocSEL, FRDocAddAnnot2SEL, L"FRDocAddAnnot2"},
	{FRDocSEL, FRDocReplacePagesSEL, L"FRDocReplacePages"},
	{FRDocSEL, FRDocInsertPagesSEL, L"FRDocInsertPages"},
	{FRDocSEL, FRDocExtractPagesSEL, L"FRDocExtractPages"},
	{FRDocSEL, FRDocGetDocSecurityCanBeModifiedSEL, L"FRDocGetDocSecurityCanBeModified"},
	{FRDocSEL, FRDocGetDocumentSEL, L"FRDocGetDocument"},
	{FRDocSEL, FRDocGetAnnotByDict2SEL, L"FRDocGetAnnotByDict2"},
	{FRDocSEL, FRDocGetPageIndexSEL, L"FRDocGetPageIndex"},
	{FRDocSEL, FRDocRemoveSecurityInfoSEL, L"FRDocRemoveSecurityInfo"},
	{FRDocSEL, FRDocUpdateDocAllViewsSEL, L"FRDocUpdateDocAllViews"},
	{FRDocSEL, FRDocSendAsAttachmentSEL, L"FRDocSendAsAttachment"},
	{FRDocSEL, FRDocOnBeforeNotifySumbitSEL, L"FRDocOnBeforeNotifySumbit"},
	{FRDocSEL, FRDocOnAfterNotifySumbitSEL, L"FRDocOnAfterNotifySumbit"},
	{FRDocSEL, FRDocConvertPdfToOtherFormat3SEL, L"FRDocConvertPdfToOtherFormat3"},
	{FRDocSEL, FRDocGetPageSEL, L"FRDocGetPage"},
	{FRDocSEL, FRDocSetNotifySEL, L"FRDocSetNotify"},
	{FRDocSEL, FRDocSetTabOrderSEL, L"FRDocSetTabOrder"},
	{FRDocSEL, FRDocSetTabOrder2SEL, L"FRDocSetTabOrder2"},
	{FRDocSEL, FRDocIsKeepSelectedCheckedSEL, L"FRDocIsKeepSelectedChecked"},
	{FRDocSEL, FRDocReConStructAcroformSEL, L"FRDocReConStructAcroform"},
	{FRDocSEL, FRDocGetOCPropertiesSEL, L"FRDocGetOCProperties"},
	{FRDocSEL, FRDocResetOCPropertiesSEL, L"FRDocResetOCProperties"},
	{FRDocSEL, FRDocSetCertifyDocumentSEL, L"FRDocSetCertifyDocument"},
	{FRDocSEL, FRDocIsCertifyDocumentSEL, L"FRDocIsCertifyDocument"},
	{FRDocSEL, FRDocSetSignaturePermissionsSEL, L"FRDocSetSignaturePermissions"},
	{FRDocSEL, FRDocSetSaveModeSEL, L"FRDocSetSaveMode"},
	{FRDocSEL, FRDocGetSaveModeSEL, L"FRDocGetSaveMode"},
	{FRDocSEL, FRDocSetDocumentTrustBySignatureSEL, L"FRDocSetDocumentTrustBySignature"},
	{FRDocSEL, FRDocGetXFADocViewSEL, L"FRDocGetXFADocView"},
	{FRDocSEL, FRDocGetReaderDocumentSEL, L"FRDocGetReaderDocument"},
	{FRDocSEL, FRDocIsRunningJSActionSEL, L"FRDocIsRunningJSAction"},
	{FRDocSEL, FRDocCountSelectionSEL, L"FRDocCountSelection"},
	{FRDocSEL, FRDocGetSelectionSEL, L"FRDocGetSelection"},
	{FRDocSEL, FRDocGetTopPageStateSEL, L"FRDocGetTopPageState"},
	{FRDocSEL, FRDocSetValidationStatusSEL, L"FRDocSetValidationStatus"},
	{FRDocSEL, FRDocSetMemDocCanReopenSEL, L"FRDocSetMemDocCanReopen"},
	{FRDocSEL, FRDocAppendUnCompressObjectsSEL, L"FRDocAppendUnCompressObjects"},
	{FRDocSEL, FRDocDoSaveAs3SEL, L"FRDocDoSaveAs3"},
	{FRDocSEL, FRDocSaveAsOleProcSEL, L"FRDocSaveAsOleProc"},
	{FRDocSEL, FRDocGetUnCompressObjectsSEL, L"FRDocGetUnCompressObjects"},
	{FRDocSEL, FRDocIsReflowViewModeSEL, L"FRDocIsReflowViewMode"},
	{FRDocSEL, FRDocGetOpenFilePathSEL, L"FRDocGetOpenFilePath"},
	{FRDocSEL, FRDocGetTabTitleSEL, L"FRDocGetTabTitle"},
	{FRDocSEL, FRDocGetTextPageSEL, L"FRDocGetTextPage"},
	{FRDocSEL, FRDocCloseFileHandlerSEL, L"FRDocCloseFileHandler"},
	{FRDocSEL, FRDocResetFileHandlerSEL, L"FRDocResetFileHandler"},
	{FRDocSEL, FRDocGetDocPagesSEL, L"FRDocGetDocPages"},
	{FRDocSEL, FRDocOpenDocumentSEL, L"FRDocOpenDocument"},
	{FRDocSEL, FRDocGetFileNameSEL, L"FRDocGetFileName"},
	{FRDocSEL, FRDocClearMousePtHandleDataSEL, L"FRDocClearMousePtHandleData"},
	{FRDocSEL, FRDocResizePageSEL, L"FRDocResizePage"},
	{FRDocSEL, FRDocGetPageLabelSEL, L"FRDocGetPageLabel"},
	{FRDocSEL, FRDocRequestDocPermPDDocSEL, L"FRDocRequestDocPermPDDoc"},
	{FRDocSEL, FRDocGetSelectPageFromPagePanelSEL, L"FRDocGetSelectPageFromPagePanel"},
	{FRDocSEL, FRDocGetDocOpenJSFinishSEL, L"FRDocGetDocOpenJSFinish"},
	{FRDocSEL, FRDocGetDocRenderFinishSEL, L"FRDocGetDocRenderFinish"},
	{FRDocSEL, FRDocReversePagesSEL, L"FRDocReversePages"},
	{FRDocSEL, FRDocIsDynamicXFADocumentSEL, L"FRDocIsDynamicXFADocument"},
	{FRDocSEL, FRDocIsUseLogicalLabelSEL, L"FRDocIsUseLogicalLabel"},
	{FRDocSEL, FRDocDeletePagesSEL, L"FRDocDeletePages"},
	{FRDocSEL, FRDocExtractPages2SEL, L"FRDocExtractPages2"},
	{FRDocSEL, FRDocOnAfterExtractPagesExSEL, L"FRDocOnAfterExtractPagesEx"},
	{FRDocSEL, FRDocSwapTwoPageSEL, L"FRDocSwapTwoPage"},
	{FRDocSEL, FRDocMovePagesSEL, L"FRDocMovePages"},
	{FRDocSEL, FRDocGetSnapShotInfoSEL, L"FRDocGetSnapShotInfo"},
	{FRDocSEL, FRDocGetPageIndexByLabelSEL, L"FRDocGetPageIndexByLabel"},
	{FRDocSEL, FRDocRotatePageSEL, L"FRDocRotatePage"},
	{FRDocSEL, FRDocHasOwnerPermissionSEL, L"FRDocHasOwnerPermission"},
	{FRDocSEL, FRDocSetSaveParamSEL, L"FRDocSetSaveParam"},
	{FRDocSEL, FRDocCheckModuleLicenseSEL, L"FRDocCheckModuleLicense"},
	{FRDocSEL, FRDocGetDocFromContainerDocSEL, L"FRDocGetDocFromContainerDoc"},
	{FRDocSEL, FRDocIsDocClosingSEL, L"FRDocIsDocClosing"},
	{FRDocSEL, FRDocGetHitImageObjSEL, L"FRDocGetHitImageObj"},
	{FRDocSEL, FRDocClearHitImageObjSEL, L"FRDocClearHitImageObj"},
	{FRDocSEL, FRDocPromptToDetectFileHandleSEL, L"FRDocPromptToDetectFileHandle"},
	{FRDocSEL, FRDocAddIgnoreObjectsSEL, L"FRDocAddIgnoreObjects"},
	{FRDocSEL, FRDocInsertPageByDictSEL, L"FRDocInsertPageByDict"},
	{FRDocSEL, FRDocSaveToXFADocSEL, L"FRDocSaveToXFADoc"},
	{FRDocSEL, FRDocGetDeletePageUndoItemSEL, L"FRDocGetDeletePageUndoItem"},
	{FRDocSEL, FRDocReleaseDeletePageUndoItemSEL, L"FRDocReleaseDeletePageUndoItem"},
	{FRDocSEL, FRDocDeletePagesUndoSEL, L"FRDocDeletePagesUndo"},
	{FRDocSEL, FRDocDeletePagesRedoSEL, L"FRDocDeletePagesRedo"},
	{FRDocSEL, FRDocMergeTwoDocSEL, L"FRDocMergeTwoDoc"},
	{FRDocSEL, FRDocGetCurrentToolSEL, L"FRDocGetCurrentTool"},
	{FRDocSEL, FRDocIsDocumentShowLineWeightsSEL, L"FRDocIsDocumentShowLineWeights"},
	{FRDocSEL, FRDocIsCurDocViewShowInContainerFrmSEL, L"FRDocIsCurDocViewShowInContainerFrm"},
	{FRDocSEL, FRDocMovePages2SEL, L"FRDocMovePages2"},
	{FRDocSEL, FRDocRemoveAnnotSelectionSEL, L"FRDocRemoveAnnotSelection"},
	{FRDocSEL, FRDocDoSaveAsWithDefaultPathSEL, L"FRDocDoSaveAsWithDefaultPath"},
	{FRDocSEL, FRDocSplitPageByRectsSEL, L"FRDocSplitPageByRects"},
	{FRDocSEL, FRDocIsEmbededSEL, L"FRDocIsEmbeded"},
	{FRDocSEL, FRDocGetSaveSaveAsNotifySEL, L"FRDocGetSaveSaveAsNotify"},
	{FRDocSEL, FRDocSetSaveSaveAsNotifySEL, L"FRDocSetSaveSaveAsNotify"},
	{FRDocSEL, FRDocGetCanReopenSEL, L"FRDocGetCanReopen"},
	{FRDocSEL, FRDocSetTopmostAnnotSEL, L"FRDocSetTopmostAnnot"},
	{FRDocSEL, FRDocOnAfterRotatePagesSEL, L"FRDocOnAfterRotatePages"},
	{FRDocSEL, FRDocSetPageLabelSEL, L"FRDocSetPageLabel"},
	{FRDocSEL, FRDocRunOCRSEL, L"FRDocRunOCR"},
	{FRDocSEL, FRDocRunPageOCRSEL, L"FRDocRunPageOCR"},
	{FRDocSEL, FRDocCreateOrganizeNotifySEL, L"FRDocCreateOrganizeNotify"},
	{FRDocSEL, FRDocDestroyOrganizeNotifySEL, L"FRDocDestroyOrganizeNotify"},
	{FRDocSEL, FRDocExtractPages3SEL, L"FRDocExtractPages3"},
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
	{FRMenuBarSEL, FRMenuBarGetMenuCountSEL, L"FRMenuBarGetMenuCount"},
	{FRMenuBarSEL, FRMenuBarGetMenuByIndexSEL, L"FRMenuBarGetMenuByIndex"},
	{FRMenuBarSEL, FRMenuBarGetMenuByNameSEL, L"FRMenuBarGetMenuByName"},
	{FRMenuBarSEL, FRMenuBarAddMenuSEL, L"FRMenuBarAddMenu"},
	{FRMenuBarSEL, FRMenuBarGetMenuIndexSEL, L"FRMenuBarGetMenuIndex"},
	{FRMenuBarSEL, FRMenuBarDeleteMenuSEL, L"FRMenuBarDeleteMenu"},
	{FRMenuSEL, FRMenuNewSEL, L"FRMenuNew"},
	{FRMenuSEL, FRMenuReleaseSEL, L"FRMenuRelease"},
	{FRMenuSEL, FRMenuGetParentMenuItemSEL, L"FRMenuGetParentMenuItem"},
	{FRMenuSEL, FRMenuGetMenuItemByIndexSEL, L"FRMenuGetMenuItemByIndex"},
	{FRMenuSEL, FRMenuGetMenuItemByNameSEL, L"FRMenuGetMenuItemByName"},
	{FRMenuSEL, FRMenuGetMenuItemCountSEL, L"FRMenuGetMenuItemCount"},
	{FRMenuSEL, FRMenuAddMenuItemSEL, L"FRMenuAddMenuItem"},
	{FRMenuSEL, FRMenuDeleteMenuItemSEL, L"FRMenuDeleteMenuItem"},
	{FRMenuSEL, FRMenuGetMenuItemIndexSEL, L"FRMenuGetMenuItemIndex"},
	{FRMenuSEL, FRMenuDeleteOwnerDrawHandleSEL, L"FRMenuDeleteOwnerDrawHandle"},
	{FRMenuSEL, FRMenuRegisterOwnerDrawHandleSEL, L"FRMenuRegisterOwnerDrawHandle"},
	{FRMenuSEL, FRMenuTrackPopupSEL, L"FRMenuTrackPopup"},
	{FRMenuSEL, FRMenuSetVisibleSEL, L"FRMenuSetVisible"},
	{FRMenuSEL, FRMenuGetVisibleSEL, L"FRMenuGetVisible"},
	{FRMenuSEL, FRMenuSetTitleSEL, L"FRMenuSetTitle"},
	{FRMenuSEL, FRMenuNewIISEL, L"FRMenuNewII"},
	{FRMenuSEL, FRMenuTrackPopupMenuSEL, L"FRMenuTrackPopupMenu"},
	{FRMenuSEL, FRMenuCloseActivePopupMenuSEL, L"FRMenuCloseActivePopupMenu"},
	{FRMenuSEL, FRMenuNew3SEL, L"FRMenuNew3"},
	{FRMenuSEL, FRMenuDoPopupMenuSEL, L"FRMenuDoPopupMenu"},
	{FRMenuSEL, FRMenuTrackPopupMenu2SEL, L"FRMenuTrackPopupMenu2"},
	{FRMenuItemSEL, FRMenuItemNewSEL, L"FRMenuItemNew"},
	{FRMenuItemSEL, FRMenuItemReleaseSEL, L"FRMenuItemRelease"},
	{FRMenuItemSEL, FRMenuItemGetSubMenuSEL, L"FRMenuItemGetSubMenu"},
	{FRMenuItemSEL, FRMenuItemSetSubMenuSEL, L"FRMenuItemSetSubMenu"},
	{FRMenuItemSEL, FRMenuItemGetParentMenuSEL, L"FRMenuItemGetParentMenu"},
	{FRMenuItemSEL, FRMenuItemGetIconSEL, L"FRMenuItemGetIcon"},
	{FRMenuItemSEL, FRMenuItemSetIconSEL, L"FRMenuItemSetIcon"},
	{FRMenuItemSEL, FRMenuItemGetTitleSEL, L"FRMenuItemGetTitle"},
	{FRMenuItemSEL, FRMenuItemSetTitleSEL, L"FRMenuItemSetTitle"},
	{FRMenuItemSEL, FRMenuItemGetNameSEL, L"FRMenuItemGetName"},
	{FRMenuItemSEL, FRMenuItemSetToolTipSEL, L"FRMenuItemSetToolTip"},
	{FRMenuItemSEL, FRMenuItemSetDescribeTextSEL, L"FRMenuItemSetDescribeText"},
	{FRMenuItemSEL, FRMenuItemIsSeparatorSEL, L"FRMenuItemIsSeparator"},
	{FRMenuItemSEL, FRMenuItemSetExecuteProcSEL, L"FRMenuItemSetExecuteProc"},
	{FRMenuItemSEL, FRMenuItemSetComputeEnabledProcSEL, L"FRMenuItemSetComputeEnabledProc"},
	{FRMenuItemSEL, FRMenuItemSetComputeMarkedProcSEL, L"FRMenuItemSetComputeMarkedProc"},
	{FRMenuItemSEL, FRMenuItemDoExecuteProcSEL, L"FRMenuItemDoExecuteProc"},
	{FRMenuItemSEL, FRMenuItemIsEnabledSEL, L"FRMenuItemIsEnabled"},
	{FRMenuItemSEL, FRMenuItemIsMarkedSEL, L"FRMenuItemIsMarked"},
	{FRMenuItemSEL, FRMenuItemGetClientDataSEL, L"FRMenuItemGetClientData"},
	{FRMenuItemSEL, FRMenuItemSetAccelKeySEL, L"FRMenuItemSetAccelKey"},
	{FRMenuItemSEL, FRMenuItemGetCmdIDSEL, L"FRMenuItemGetCmdID"},
	{FRMenuItemSEL, FRMenuItemSetClientDataSEL, L"FRMenuItemSetClientData"},
	{FRMenuItemSEL, FRMenuItemSetVisibleSEL, L"FRMenuItemSetVisible"},
	{FRMenuItemSEL, FRMenuItemGetVisibleSEL, L"FRMenuItemGetVisible"},
	{FRMenuItemSEL, FRMenuItemSetBitmapIconWithIndexSEL, L"FRMenuItemSetBitmapIconWithIndex"},
	{FRMenuItemSEL, FRMenuItemSetPDFBitmapNameSEL, L"FRMenuItemSetPDFBitmapName"},
// fr_menuImpl.h end

// In file fr_sysImpl.h
	{FRSysSEL, FRSysLoadStandarCursorSEL, L"FRSysLoadStandarCursor"},
	{FRSysSEL, FRSysGetCursorSEL, L"FRSysGetCursor"},
	{FRSysSEL, FRSysSetCursorSEL, L"FRSysSetCursor"},
	{FRSysSEL, FRSysShowMessageBoxSEL, L"FRSysShowMessageBox"},
	{FRSysSEL, FRSysInstallDialogSkinThemeSEL, L"FRSysInstallDialogSkinTheme"},
	{FRSysSEL, FRSysInstallDialogScrollBarSEL, L"FRSysInstallDialogScrollBar"},
	{FRSysSEL, FRSysGetSkinCountSEL, L"FRSysGetSkinCount"},
	{FRSysSEL, FRSysGetSkinNameByIndexSEL, L"FRSysGetSkinNameByIndex"},
	{FRSysSEL, FRSysSetActiveSkinByIndexSEL, L"FRSysSetActiveSkinByIndex"},
	{FRSysSEL, FRSysSetActiveSkinByNameSEL, L"FRSysSetActiveSkinByName"},
	{FRSysSEL, FRSysShowStopLaunchDlgSEL, L"FRSysShowStopLaunchDlg"},
	{FRSysSEL, FRSysShowMessageBox2SEL, L"FRSysShowMessageBox2"},
	{FRSysSEL, FRSysShowMessageBox3SEL, L"FRSysShowMessageBox3"},
// fr_sysImpl.h end

// In file fr_viewImpl.h
	{FRDocViewSEL, FRDocViewGetDocumentSEL, L"FRDocViewGetDocument"},
	{FRDocViewSEL, FRDocViewCountPageViewsSEL, L"FRDocViewCountPageViews"},
	{FRDocViewSEL, FRDocViewGetPageViewSEL, L"FRDocViewGetPageView"},
	{FRDocViewSEL, FRDocViewGetPageViewAtPointSEL, L"FRDocViewGetPageViewAtPoint"},
	{FRDocViewSEL, FRDocViewCountVisiblePageViewsSEL, L"FRDocViewCountVisiblePageViews"},
	{FRDocViewSEL, FRDocViewGetVisiblePageViewSEL, L"FRDocViewGetVisiblePageView"},
	{FRDocViewSEL, FRDocViewGotoPageViewSEL, L"FRDocViewGotoPageView"},
	{FRDocViewSEL, FRDocViewGotoPageViewByPointSEL, L"FRDocViewGotoPageViewByPoint"},
	{FRDocViewSEL, FRDocViewGotoPageViewByRectSEL, L"FRDocViewGotoPageViewByRect"},
	{FRDocViewSEL, FRDocViewGetCurrentPageViewSEL, L"FRDocViewGetCurrentPageView"},
	{FRDocViewSEL, FRDocViewGetRotationSEL, L"FRDocViewGetRotation"},
	{FRDocViewSEL, FRDocViewSetRotationSEL, L"FRDocViewSetRotation"},
	{FRDocViewSEL, FRDocViewGetLayoutModeSEL, L"FRDocViewGetLayoutMode"},
	{FRDocViewSEL, FRDocViewSetLayoutModeSEL, L"FRDocViewSetLayoutMode"},
	{FRDocViewSEL, FRDocViewGetZoomSEL, L"FRDocViewGetZoom"},
	{FRDocViewSEL, FRDocViewGetZoomTypeSEL, L"FRDocViewGetZoomType"},
	{FRDocViewSEL, FRDocViewZoomToSEL, L"FRDocViewZoomTo"},
	{FRDocViewSEL, FRDocViewGoBackSEL, L"FRDocViewGoBack"},
	{FRDocViewSEL, FRDocViewGoForwardSEL, L"FRDocViewGoForward"},
	{FRDocViewSEL, FRDocViewShowAnnotsSEL, L"FRDocViewShowAnnots"},
	{FRDocViewSEL, FRDocViewProcActionSEL, L"FRDocViewProcAction"},
	{FRDocViewSEL, FRDocViewScrollToSEL, L"FRDocViewScrollTo"},
	{FRDocViewSEL, FRDocViewGetMaxScrollingSizeSEL, L"FRDocViewGetMaxScrollingSize"},
	{FRDocViewSEL, FRDocViewDrawNowSEL, L"FRDocViewDrawNow"},
	{FRDocViewSEL, FRDocViewInvalidateRectSEL, L"FRDocViewInvalidateRect"},
	{FRDocViewSEL, FRDocViewDrawRectSEL, L"FRDocViewDrawRect"},
	{FRDocViewSEL, FRDocViewDoPopUpMenuSEL, L"FRDocViewDoPopUpMenu"},
	{FRDocViewSEL, FRDocViewGetMachinePortSEL, L"FRDocViewGetMachinePort"},
	{FRDocViewSEL, FRDocViewReleaseMachinePortSEL, L"FRDocViewReleaseMachinePort"},
	{FRDocViewSEL, FRDocViewGetOCContextSEL, L"FRDocViewGetOCContext"},
	{FRDocViewSEL, FRDocViewGetCurrentSnapshotSEL, L"FRDocViewGetCurrentSnapshot"},
	{FRDocViewSEL, FRDocViewGetThumbnailViewSEL, L"FRDocViewGetThumbnailView"},
	{FRDocViewSEL, FRDocViewGotoPageViewByStateSEL, L"FRDocViewGotoPageViewByState"},
	{FRDocViewSEL, FRDocViewMovePageSEL, L"FRDocViewMovePage"},
	{FRDocViewSEL, FRDocViewIsValidPageViewSEL, L"FRDocViewIsValidPageView"},
	{FRDocViewSEL, FRDocViewGetTagDocViewTextSEL, L"FRDocViewGetTagDocViewText"},
	{FRDocViewSEL, FRDocViewGetLRDocViewTextSEL, L"FRDocViewGetLRDocViewText"},
	{FRDocViewSEL, FRDocViewGetWndSEL, L"FRDocViewGetWnd"},
	{FRDocViewSEL, FRDocViewScrollToCenterPointSEL, L"FRDocViewScrollToCenterPoint"},
	{FRDocViewSEL, FRDocViewSetRenderDataChangeSEL, L"FRDocViewSetRenderDataChange"},
	{FRDocViewSEL, FRDocViewGotoPageViewByAnnotSEL, L"FRDocViewGotoPageViewByAnnot"},
	{FRDocViewSEL, FRDocViewGotoPageByDestSEL, L"FRDocViewGotoPageByDest"},
	{FRDocViewSEL, FRDocViewGetHwndSEL, L"FRDocViewGetHwnd"},
	{FRDocViewSEL, FRDocViewGetRBDPageViewSEL, L"FRDocViewGetRBDPageView"},
	{FRDocViewSEL, FRDocViewUpdateStatusBarPagesInfoSEL, L"FRDocViewUpdateStatusBarPagesInfo"},
	{FRDocViewSEL, FRDocViewGotoPageViewByRect2SEL, L"FRDocViewGotoPageViewByRect2"},
	{FRDocViewSEL, FRDocViewUpdateAllViewsSEL, L"FRDocViewUpdateAllViews"},
	{FRDocViewSEL, FRDocViewUpdateAllNotesSEL, L"FRDocViewUpdateAllNotes"},
	{FRDocViewSEL, FRDocViewIsAutoScrollingSEL, L"FRDocViewIsAutoScrolling"},
	{FRDocViewSEL, FRDocViewScrollTo2SEL, L"FRDocViewScrollTo2"},
	{FRPageViewSEL, FRPageViewGetDocumentSEL, L"FRPageViewGetDocument"},
	{FRPageViewSEL, FRPageViewGetDocViewSEL, L"FRPageViewGetDocView"},
	{FRPageViewSEL, FRPageViewGetPDPageSEL, L"FRPageViewGetPDPage"},
	{FRPageViewSEL, FRPageViewGetPageIndexSEL, L"FRPageViewGetPageIndex"},
	{FRPageViewSEL, FRPageViewCountAnnotSEL, L"FRPageViewCountAnnot"},
	{FRPageViewSEL, FRPageViewGetCurrentMatrixSEL, L"FRPageViewGetCurrentMatrix"},
	{FRPageViewSEL, FRPageViewDevicePointToPageSEL, L"FRPageViewDevicePointToPage"},
	{FRPageViewSEL, FRPageViewDeviceRectToPageSEL, L"FRPageViewDeviceRectToPage"},
	{FRPageViewSEL, FRPageViewPointToDeviceSEL, L"FRPageViewPointToDevice"},
	{FRPageViewSEL, FRPageViewRectToDeviceSEL, L"FRPageViewRectToDevice"},
	{FRPageViewSEL, FRPageViewIsVisibleSEL, L"FRPageViewIsVisible"},
	{FRPageViewSEL, FRPageViewGetPageRectSEL, L"FRPageViewGetPageRect"},
	{FRPageViewSEL, FRPageViewGetPageVisibleRectSEL, L"FRPageViewGetPageVisibleRect"},
	{FRPageViewSEL, FRPageViewDidContentChangedSEL, L"FRPageViewDidContentChanged"},
	{FRPageViewSEL, FRPageViewGetHWndSEL, L"FRPageViewGetHWnd"},
	{FRPageViewSEL, FRPageViewDidTextObjectChangedSEL, L"FRPageViewDidTextObjectChanged"},
	{FRPageViewSEL, FRPageViewGetAnnotByIndexSEL, L"FRPageViewGetAnnotByIndex"},
	{FRPageViewSEL, FRPageViewGetPageStateSEL, L"FRPageViewGetPageState"},
	{FRPageViewSEL, FRPageViewDeleteAnnotSEL, L"FRPageViewDeleteAnnot"},
	{FRPageViewSEL, FRPageViewGetFocusAnnotSEL, L"FRPageViewGetFocusAnnot"},
	{FRPageViewSEL, FRPageViewGetPageScaleSEL, L"FRPageViewGetPageScale"},
	{FRPageViewSEL, FRPageViewGetAnnotAtPointSEL, L"FRPageViewGetAnnotAtPoint"},
	{FRPageViewSEL, FRPageViewUpdateAllViewsSEL, L"FRPageViewUpdateAllViews"},
	{FRPageViewSEL, FRPageViewAddAnnotSEL, L"FRPageViewAddAnnot"},
	{FRPageViewSEL, FRPageViewGetRenderOptionsSEL, L"FRPageViewGetRenderOptions"},
	{FRPageViewSEL, FRPageViewDidContentChanged2SEL, L"FRPageViewDidContentChanged2"},
	{FRPageViewSEL, FRPageViewDidContentChanged3SEL, L"FRPageViewDidContentChanged3"},
	{FRPageViewSEL, FRPageViewSetContentModificationSEL, L"FRPageViewSetContentModification"},
	{FRPageViewSEL, FRPageViewGenerateContentSEL, L"FRPageViewGenerateContent"},
	{FRPageViewSEL, FRPageViewUpdateAllViewsRectSEL, L"FRPageViewUpdateAllViewsRect"},
	{FRPageViewSEL, FRPageViewCountViewsSEL, L"FRPageViewCountViews"},
	{FRPageViewSEL, FRPageViewIsValidAnnotSEL, L"FRPageViewIsValidAnnot"},
	{FRPageViewSEL, FRPageViewAnnot_OnDrawSEL, L"FRPageViewAnnot_OnDraw"},
	{FRPageViewSEL, FRPageViewAnnot_OnHitTestSEL, L"FRPageViewAnnot_OnHitTest"},
	{FRPageViewSEL, FRPageViewGetReaderPageSEL, L"FRPageViewGetReaderPage"},
	{FRPageViewSEL, FRPageViewPostFormFilerMessageTextSEL, L"FRPageViewPostFormFilerMessageText"},
	{FRPageViewSEL, FRPageViewSetIsFindHighlightSEL, L"FRPageViewSetIsFindHighlight"},
	{FRPageViewSEL, FRPageViewIsFindHighlightSEL, L"FRPageViewIsFindHighlight"},
	{FRPageViewSEL, FRPageViewSetAdvancedFindHighlightSEL, L"FRPageViewSetAdvancedFindHighlight"},
	{FRPageViewSEL, FRPageViewIsAdvancedFindHighlightSEL, L"FRPageViewIsAdvancedFindHighlight"},
	{FRPageViewSEL, FRPageViewGetPageStateByFitTypeSEL, L"FRPageViewGetPageStateByFitType"},
	{FRPageViewSEL, FRPageViewGetPageRectIncludeMarginSEL, L"FRPageViewGetPageRectIncludeMargin"},
	{FRTextSelectToolSEL, FRTextSelectToolCreateSEL, L"FRTextSelectToolCreate"},
	{FRTextSelectToolSEL, FRTextSelectToolDestroyTextSelectToolSEL, L"FRTextSelectToolDestroyTextSelectTool"},
	{FRTextSelectToolSEL, FRTextSelectToolGetSelectedTextSEL, L"FRTextSelectToolGetSelectedText"},
	{FRTextSelectToolSEL, FRTextSelectToolDrawSelectionSEL, L"FRTextSelectToolDrawSelection"},
	{FRTextSelectToolSEL, FRTextSelectToolClearSelectionSEL, L"FRTextSelectToolClearSelection"},
	{FRTextSelectToolSEL, FRTextSelectToolDoLButtonUpSEL, L"FRTextSelectToolDoLButtonUp"},
	{FRTextSelectToolSEL, FRTextSelectToolDoLButtonDownSEL, L"FRTextSelectToolDoLButtonDown"},
	{FRTextSelectToolSEL, FRTextSelectToolDoLButtonDblClkSEL, L"FRTextSelectToolDoLButtonDblClk"},
	{FRTextSelectToolSEL, FRTextSelectToolDoRButtonUpSEL, L"FRTextSelectToolDoRButtonUp"},
	{FRTextSelectToolSEL, FRTextSelectToolDoMouseMoveSEL, L"FRTextSelectToolDoMouseMove"},
	{FRTextSelectToolSEL, FRTextSelectToolDoMouseWheelSEL, L"FRTextSelectToolDoMouseWheel"},
	{FRTextSelectToolSEL, FRTextSelectToolIsSelectingSEL, L"FRTextSelectToolIsSelecting"},
	{FRTextSelectToolSEL, FRTextSelectToolEnumTextObjectRectSEL, L"FRTextSelectToolEnumTextObjectRect"},
	{FRTextSelectToolSEL, FRTextSelectToolAddSelectSEL, L"FRTextSelectToolAddSelect"},
	{FRTextSelectToolSEL, FRTextSelectToolSelect_GetPageRangeSEL, L"FRTextSelectToolSelect_GetPageRange"},
	{FRTextSelectToolSEL, FRTextSelectToolGetSelectedText2SEL, L"FRTextSelectToolGetSelectedText2"},
	{FRTextSelectToolSEL, FRTextSelectToolGetSelectedTextInfoSEL, L"FRTextSelectToolGetSelectedTextInfo"},
	{FRTextSelectToolSEL, FRTextSelectToolReleaseSelectedInfoSEL, L"FRTextSelectToolReleaseSelectedInfo"},
	{FRTextSelectToolSEL, FRTextSelectToolIsSelectedSEL, L"FRTextSelectToolIsSelected"},
	{FRTextSelectToolSEL, FRTextSelectToolIsPageSelectAllSEL, L"FRTextSelectToolIsPageSelectAll"},
	{FRTextSelectToolSEL, FRTextSelectToolGetSelectedDataSEL, L"FRTextSelectToolGetSelectedData"},
	{FRTextSelectToolSEL, FRTextSelectToolAddSelect2SEL, L"FRTextSelectToolAddSelect2"},
	{FRTextSelectToolSEL, FRTextSelectToolAddSelectTextRectsSEL, L"FRTextSelectToolAddSelectTextRects"},
	{FRTextSelectToolSEL, FRTextSelectToolGetSelectPDFRectSEL, L"FRTextSelectToolGetSelectPDFRect"},
	{FRTextSelectToolSEL, FRTextSelectToolDeselectAllSEL, L"FRTextSelectToolDeselectAll"},
	{FRTextSelectToolSEL, FRTextSelectToolAddSelectTextRectsWithPagesSEL, L"FRTextSelectToolAddSelectTextRectsWithPages"},
	{FRTextSelectToolSEL, FRTextSelectToolGetExportSelectionPageRectsSEL, L"FRTextSelectToolGetExportSelectionPageRects"},
	{FRTextSelectToolSEL, FRTextSelectToolCopyToClipBoardSEL, L"FRTextSelectToolCopyToClipBoard"},
	{FRTextSelectToolSEL, FRTextSelectToolSelectEnumTextObjectPathPointSEL, L"FRTextSelectToolSelectEnumTextObjectPathPoint"},
	{FRTextSelectToolSEL, FRTextSelectToolReleaseTextObjectPathPointsSEL, L"FRTextSelectToolReleaseTextObjectPathPoints"},
	{FRTextSelectToolSEL, FRTextSelectToolSelectInitSelectionSEL, L"FRTextSelectToolSelectInitSelection"},
	{FRTextSelectToolSEL, FRTextSelectToolSelectOnKeyDownSEL, L"FRTextSelectToolSelectOnKeyDown"},
	{FRTextSelectToolSEL, FRTextSelectToolDoLButtonDown2SEL, L"FRTextSelectToolDoLButtonDown2"},
	{FRTextSelectToolSEL, FRTextSelectToolGetSelectedTextObjectSEL, L"FRTextSelectToolGetSelectedTextObject"},
	{FRTextSelectToolSEL, FRTextSelectToolDoCopySEL, L"FRTextSelectToolDoCopy"},
	{FRTextSelectToolSEL, FRTextSelectToolToolDrawSEL, L"FRTextSelectToolToolDraw"},
	{FRTextSelectToolSEL, FRTextSelectToolSetFloatyShowStateSEL, L"FRTextSelectToolSetFloatyShowState"},
	{FRTextSelectToolSEL, FRTextSelectToolGetFloatyShowStateSEL, L"FRTextSelectToolGetFloatyShowState"},
	{FRTextSelectToolSEL, FRTextSelectToolAddHighlightSelectSEL, L"FRTextSelectToolAddHighlightSelect"},
	{FRTextSelectToolSEL, FRTextSelectToolGetHltSelPagesTextPosSEL, L"FRTextSelectToolGetHltSelPagesTextPos"},
	{FRTextSelectToolSEL, FRTextSelectToolRelHltSelPagesTextPosSEL, L"FRTextSelectToolRelHltSelPagesTextPos"},
	{FRTextSelectToolSEL, FRTextSelectToolAddHighlightAdvSelectSEL, L"FRTextSelectToolAddHighlightAdvSelect"},
	{FRTextSelectToolSEL, FRTextSelectToolGetHltAdvSelPagesTextPosSEL, L"FRTextSelectToolGetHltAdvSelPagesTextPos"},
	{FRTextSelectToolSEL, FRTextSelectToolInvalidateHltSelectSEL, L"FRTextSelectToolInvalidateHltSelect"},
	{FRTextSelectToolSEL, FRTextSelectToolClearHltAdvSelectSEL, L"FRTextSelectToolClearHltAdvSelect"},
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
	{FPDDocSEL, FPDDocNewSEL, L"FPDDocNew"},
	{FPDDocSEL, FPDDocDestroySEL, L"FPDDocDestroy"},
	{FPDDocSEL, FPDDocOpenSEL, L"FPDDocOpen"},
	{FPDDocSEL, FPDDocOpenMemDocumentSEL, L"FPDDocOpenMemDocument"},
	{FPDDocSEL, FPDDocStartProgressiveLoadSEL, L"FPDDocStartProgressiveLoad"},
	{FPDDocSEL, FPDDocContinueLoadSEL, L"FPDDocContinueLoad"},
	{FPDDocSEL, FPDDocCloseSEL, L"FPDDocClose"},
	{FPDDocSEL, FPDDocGetRootSEL, L"FPDDocGetRoot"},
	{FPDDocSEL, FPDDocGetInfoSEL, L"FPDDocGetInfo"},
	{FPDDocSEL, FPDDocGetIDSEL, L"FPDDocGetID"},
	{FPDDocSEL, FPDDocGetPageCountSEL, L"FPDDocGetPageCount"},
	{FPDDocSEL, FPDDocGetPageSEL, L"FPDDocGetPage"},
	{FPDDocSEL, FPDDocGetPageIndexSEL, L"FPDDocGetPageIndex"},
	{FPDDocSEL, FPDDocGetUserPermissionsSEL, L"FPDDocGetUserPermissions"},
	{FPDDocSEL, FPDDocIsOwnerSEL, L"FPDDocIsOwner"},
	{FPDDocSEL, FPDDocIsFormStreamSEL, L"FPDDocIsFormStream"},
	{FPDDocSEL, FPDDocLoadFontSEL, L"FPDDocLoadFont"},
	{FPDDocSEL, FPDDocLoadColorSpaceSEL, L"FPDDocLoadColorSpace"},
	{FPDDocSEL, FPDDocLoadPatternSEL, L"FPDDocLoadPattern"},
	{FPDDocSEL, FPDDocLoadImageFSEL, L"FPDDocLoadImageF"},
	{FPDDocSEL, FPDDocLoadFontFileSEL, L"FPDDocLoadFontFile"},
	{FPDDocSEL, FPDDocGetInfoObjNumSEL, L"FPDDocGetInfoObjNum"},
	{FPDDocSEL, FPDDocGetRootObjNumSEL, L"FPDDocGetRootObjNum"},
	{FPDDocSEL, FPDDocEnumPagesSEL, L"FPDDocEnumPages"},
	{FPDDocSEL, FPDDocNewEnumPageHandlerSEL, L"FPDDocNewEnumPageHandler"},
	{FPDDocSEL, FPDDocDeleteEnumPageHandlerSEL, L"FPDDocDeleteEnumPageHandler"},
	{FPDDocSEL, FPDDocSetRootObjNumSEL, L"FPDDocSetRootObjNum"},
	{FPDDocSEL, FPDDocSetInfoObjNumSEL, L"FPDDocSetInfoObjNum"},
	{FPDDocSEL, FPDDocSetIDSEL, L"FPDDocSetID"},
	{FPDDocSEL, FPDDocAddWindowsFontSEL, L"FPDDocAddWindowsFont"},
	{FPDDocSEL, FPDDocAddWindowsFontWSEL, L"FPDDocAddWindowsFontW"},
	{FPDDocSEL, FPDDocAddStandardFontSEL, L"FPDDocAddStandardFont"},
	{FPDDocSEL, FPDDocBuildResourceListSEL, L"FPDDocBuildResourceList"},
	{FPDDocSEL, FPDDocCreateNewPageSEL, L"FPDDocCreateNewPage"},
	{FPDDocSEL, FPDDocDeletePageSEL, L"FPDDocDeletePage"},
	{FPDDocSEL, FPDDocConvertIndirectObjectsSEL, L"FPDDocConvertIndirectObjects"},
	{FPDDocSEL, FPDDocGetPageContentModifySEL, L"FPDDocGetPageContentModify"},
	{FPDDocSEL, FPDDocQuickSearchSEL, L"FPDDocQuickSearch"},
	{FPDDocSEL, FPDDocReloadPagesSEL, L"FPDDocReloadPages"},
	{FPDDocSEL, FPDDocLoadDocSEL, L"FPDDocLoadDoc"},
	{FPDDocSEL, FPDDocGetIndirectObjectSEL, L"FPDDocGetIndirectObject"},
	{FPDDocSEL, FPDDocGetIndirectTypeSEL, L"FPDDocGetIndirectType"},
	{FPDDocSEL, FPDDocAddIndirectObjectSEL, L"FPDDocAddIndirectObject"},
	{FPDDocSEL, FPDDocReleaseIndirectObjectSEL, L"FPDDocReleaseIndirectObject"},
	{FPDDocSEL, FPDDocDeleteIndirectObjectSEL, L"FPDDocDeleteIndirectObject"},
	{FPDDocSEL, FPDDocImportIndirectObjectSEL, L"FPDDocImportIndirectObject"},
	{FPDDocSEL, FPDDocImportExternalObjectSEL, L"FPDDocImportExternalObject"},
	{FPDDocSEL, FPDDocInsertIndirectObjectSEL, L"FPDDocInsertIndirectObject"},
	{FPDDocSEL, FPDDocGetLastobjNumSEL, L"FPDDocGetLastobjNum"},
	{FPDDocSEL, FPDDocReloadFileStreamsSEL, L"FPDDocReloadFileStreams"},
	{FPDDocSEL, FPDDocGetStartPositionSEL, L"FPDDocGetStartPosition"},
	{FPDDocSEL, FPDDocGetNextAssocSEL, L"FPDDocGetNextAssoc"},
	{FPDDocSEL, FPDDocIsModifiedSEL, L"FPDDocIsModified"},
	{FPDDocSEL, FPDDocClearModifiedSEL, L"FPDDocClearModified"},
	{FPDDocSEL, FPDDocSaveSEL, L"FPDDocSave"},
	{FPDDocSEL, FPDDocGetParserSEL, L"FPDDocGetParser"},
	{FPDDocSEL, FPDDocCheckSignatureSEL, L"FPDDocCheckSignature"},
	{FPDDocSEL, FPDDocGenerateFileIDSEL, L"FPDDocGenerateFileID"},
	{FPDDocSEL, FPDDocGetReviewTypeSEL, L"FPDDocGetReviewType"},
	{FPDDocSEL, FPDDocIsPortfolioSEL, L"FPDDocIsPortfolio"},
	{FPDDocSEL, FPDDocRemoveUR3SEL, L"FPDDocRemoveUR3"},
	{FPDDocSEL, FPDDocAddFXFontSEL, L"FPDDocAddFXFont"},
	{FPDDocSEL, FPDDocGetIndirectObjsCountSEL, L"FPDDocGetIndirectObjsCount"},
	{FPDDocSEL, FPDDocSave2SEL, L"FPDDocSave2"},
	{FPDDocSEL, FPDDocInsertDocumentAtPosSEL, L"FPDDocInsertDocumentAtPos"},
	{FPDDocSEL, FPDDocMetadataGetAllCustomKeysSEL, L"FPDDocMetadataGetAllCustomKeys"},
	{FPDDocSEL, FPDDocMetadataDeleteCustomKeySEL, L"FPDDocMetadataDeleteCustomKey"},
	{FPDDocSEL, FPDDocMetadataGetStringSEL, L"FPDDocMetadataGetString"},
	{FPDDocSEL, FPDDocMetadataSetStringSEL, L"FPDDocMetadataSetString"},
	{FPDDocSEL, FPDDocMetadataSyncUpdateSEL, L"FPDDocMetadataSyncUpdate"},
	{FPDDocSEL, FPDDocMetadataSetDateTimeSEL, L"FPDDocMetadataSetDateTime"},
	{FPDDocSEL, FPDDocAddNewIndirectObjectSEL, L"FPDDocAddNewIndirectObject"},
	{FPDDocSEL, FPDDocLoadPagesSEL, L"FPDDocLoadPages"},
	{FPDDocSEL, FPDDocMetadataGetRootSEL, L"FPDDocMetadataGetRoot"},
	{FPDDocSEL, FPDDocConstructFromParserSEL, L"FPDDocConstructFromParser"},
	{FPDDocSEL, FPDDocMetadataCreateNewMetadataSEL, L"FPDDocMetadataCreateNewMetadata"},
	{FPDDocSEL, FPDDocReferenceIndirectObjectSEL, L"FPDDocReferenceIndirectObject"},
	{FPDDocSEL, FPDDocMetadataGetRdfXMLStringSEL, L"FPDDocMetadataGetRdfXMLString"},
	{FPDDocSEL, FPDDocCreateChunkFileStreamSEL, L"FPDDocCreateChunkFileStream"},
	{FPDDocSEL, FPDDocReleaseChunkFileStreamSEL, L"FPDDocReleaseChunkFileStream"},
	{FPDDocSEL, FPDDocBuildResourceList2SEL, L"FPDDocBuildResourceList2"},
	{FPDDocSEL, FPDDocSetFileVersionSEL, L"FPDDocSetFileVersion"},
	{FPDDocSEL, FPDDocGetFileVersionSEL, L"FPDDocGetFileVersion"},
	{FPDDocSEL, FPDDocGetAllRdfXMLKeysSEL, L"FPDDocGetAllRdfXMLKeys"},
	{FPDDocSEL, FPDDocCountDeveloperExtensionsSEL, L"FPDDocCountDeveloperExtensions"},
	{FPDDocSEL, FPDDocGetDeveloperExtensionsSEL, L"FPDDocGetDeveloperExtensions"},
	{FPDDocSEL, FPDDocGetDestNameTreeSEL, L"FPDDocGetDestNameTree"},
	{FPDNameTreeSEL, FPDNameTreeNewSEL, L"FPDNameTreeNew"},
	{FPDNameTreeSEL, FPDNameTreeNew2SEL, L"FPDNameTreeNew2"},
	{FPDNameTreeSEL, FPDNameTreeDestroySEL, L"FPDNameTreeDestroy"},
	{FPDNameTreeSEL, FPDNameTreeLookupValueSEL, L"FPDNameTreeLookupValue"},
	{FPDNameTreeSEL, FPDNameTreeLookupValueByNameSEL, L"FPDNameTreeLookupValueByName"},
	{FPDNameTreeSEL, FPDNameTreeLookupNamedDestSEL, L"FPDNameTreeLookupNamedDest"},
	{FPDNameTreeSEL, FPDNameTreeSetValueSEL, L"FPDNameTreeSetValue"},
	{FPDNameTreeSEL, FPDNameTreeGetIndexSEL, L"FPDNameTreeGetIndex"},
	{FPDNameTreeSEL, FPDNameTreeRemoveSEL, L"FPDNameTreeRemove"},
	{FPDNameTreeSEL, FPDNameTreeGetCountSEL, L"FPDNameTreeGetCount"},
	{FPDNameTreeSEL, FPDNameTreeGetRootSEL, L"FPDNameTreeGetRoot"},
	{FPDNameTreeSEL, FPDNameTreeLookupValue2SEL, L"FPDNameTreeLookupValue2"},
	{FPDNameTreeSEL, FPDNameTreeNew3SEL, L"FPDNameTreeNew3"},
	{FPDNameTreeSEL, FPDNameTreeSetValue2SEL, L"FPDNameTreeSetValue2"},
	{FPDNameTreeSEL, FPDNameTreeReloadSEL, L"FPDNameTreeReload"},
	{FPDBookmarkSEL, FPDBookmarkNewSEL, L"FPDBookmarkNew"},
	{FPDBookmarkSEL, FPDBookmarkDestroySEL, L"FPDBookmarkDestroy"},
	{FPDBookmarkSEL, FPDBookmarkIsVaildSEL, L"FPDBookmarkIsVaild"},
	{FPDBookmarkSEL, FPDBookmarkGetColorRefSEL, L"FPDBookmarkGetColorRef"},
	{FPDBookmarkSEL, FPDBookmarkGetFontStyleSEL, L"FPDBookmarkGetFontStyle"},
	{FPDBookmarkSEL, FPDBookmarkGetTitleSEL, L"FPDBookmarkGetTitle"},
	{FPDBookmarkSEL, FPDBookmarkGetDestSEL, L"FPDBookmarkGetDest"},
	{FPDBookmarkSEL, FPDBookmarkGetActionSEL, L"FPDBookmarkGetAction"},
	{FPDBookmarkSEL, FPDBookmarkGetDictionarySEL, L"FPDBookmarkGetDictionary"},
	{FPDBookmarkSEL, FPDBookmarkGetFirstChildSEL, L"FPDBookmarkGetFirstChild"},
	{FPDBookmarkSEL, FPDBookmarkGetNextSiblingSEL, L"FPDBookmarkGetNextSibling"},
	{FPDDestSEL, FPDDestNewSEL, L"FPDDestNew"},
	{FPDDestSEL, FPDDestDestroySEL, L"FPDDestDestroy"},
	{FPDDestSEL, FPDDestGetRemoteNameSEL, L"FPDDestGetRemoteName"},
	{FPDDestSEL, FPDDestGetPageIndexSEL, L"FPDDestGetPageIndex"},
	{FPDDestSEL, FPDDestGetPageObjNumSEL, L"FPDDestGetPageObjNum"},
	{FPDDestSEL, FPDDestGetZoomModeSEL, L"FPDDestGetZoomMode"},
	{FPDDestSEL, FPDDestGetParamSEL, L"FPDDestGetParam"},
	{FPDDestSEL, FPDDestGetPDFObjectSEL, L"FPDDestGetPDFObject"},
	{FPDDestSEL, FPDDestCheckObjectIsNullSEL, L"FPDDestCheckObjectIsNull"},
	{FPDDestSEL, FPDDestGetPDFObject2SEL, L"FPDDestGetPDFObject2"},
	{FPDOCContextSEL, FPDOCContextNewSEL, L"FPDOCContextNew"},
	{FPDOCContextSEL, FPDOCContextDestroySEL, L"FPDOCContextDestroy"},
	{FPDOCContextSEL, FPDOCContextGetDocumentSEL, L"FPDOCContextGetDocument"},
	{FPDOCContextSEL, FPDOCContextGetUsageTypeSEL, L"FPDOCContextGetUsageType"},
	{FPDOCContextSEL, FPDOCContextCheckOCGVisibleSEL, L"FPDOCContextCheckOCGVisible"},
	{FPDOCContextSEL, FPDOCContextResetOCContextSEL, L"FPDOCContextResetOCContext"},
	{FPDOCContextSEL, FPDOCContextSetOCGStateSEL, L"FPDOCContextSetOCGState"},
	{FPDOCContextSEL, FPDOCContextCheckObjectVisibleSEL, L"FPDOCContextCheckObjectVisible"},
	{FPDOCContextSEL, FPDOCContextConvertToFPDOCContextHandlerSEL, L"FPDOCContextConvertToFPDOCContextHandler"},
	{FPDOCContextSEL, FPDOCContextMergeContextSEL, L"FPDOCContextMergeContext"},
	{FPDOCGroupSEL, FPDOCGroupNewSEL, L"FPDOCGroupNew"},
	{FPDOCGroupSEL, FPDOCGroupDestroySEL, L"FPDOCGroupDestroy"},
	{FPDOCGroupSEL, FPDOCGroupGetNameSEL, L"FPDOCGroupGetName"},
	{FPDOCGroupSEL, FPDOCGroupSetNameSEL, L"FPDOCGroupSetName"},
	{FPDOCGroupSEL, FPDOCGroupHasIntentSEL, L"FPDOCGroupHasIntent"},
	{FPDOCGroupSEL, FPDOCGroupGetCreatorInfoSEL, L"FPDOCGroupGetCreatorInfo"},
	{FPDOCGroupSEL, FPDOCGroupGetLanguageInfoSEL, L"FPDOCGroupGetLanguageInfo"},
	{FPDOCGroupSEL, FPDOCGroupGetExportStateSEL, L"FPDOCGroupGetExportState"},
	{FPDOCGroupSEL, FPDOCGroupGetZoomRangeSEL, L"FPDOCGroupGetZoomRange"},
	{FPDOCGroupSEL, FPDOCGroupGetPrintInfoSEL, L"FPDOCGroupGetPrintInfo"},
	{FPDOCGroupSEL, FPDOCGroupGetViewStateSEL, L"FPDOCGroupGetViewState"},
	{FPDOCGroupSEL, FPDOCGroupGetUserTypeSEL, L"FPDOCGroupGetUserType"},
	{FPDOCGroupSEL, FPDOCGroupGetPageElementTypeSEL, L"FPDOCGroupGetPageElementType"},
	{FPDOCGroupSEL, FPDOCGroupGetDictionarySEL, L"FPDOCGroupGetDictionary"},
	{FPDOCGroupSetSEL, FPDOCGroupSetNewSEL, L"FPDOCGroupSetNew"},
	{FPDOCGroupSetSEL, FPDOCGroupSetDestroySEL, L"FPDOCGroupSetDestroy"},
	{FPDOCGroupSetSEL, FPDOCGroupSetCountElementsSEL, L"FPDOCGroupSetCountElements"},
	{FPDOCGroupSetSEL, FPDOCGroupSetIsSubGroupSetSEL, L"FPDOCGroupSetIsSubGroupSet"},
	{FPDOCGroupSetSEL, FPDOCGroupSetGetGroupSEL, L"FPDOCGroupSetGetGroup"},
	{FPDOCGroupSetSEL, FPDOCGroupSetGetSubGroupSetSEL, L"FPDOCGroupSetGetSubGroupSet"},
	{FPDOCGroupSetSEL, FPDOCGroupSetFindGroupSEL, L"FPDOCGroupSetFindGroup"},
	{FPDOCGroupSetSEL, FPDOCGroupSetGetSubGroupSetNameSEL, L"FPDOCGroupSetGetSubGroupSetName"},
	{FPDOCGroupSetSEL, FPDOCGroupSetGetArraySEL, L"FPDOCGroupSetGetArray"},
	{FPDOCNotifySEL, FPDOCNotifyFPD_OCNotifyNewSEL, L"FPDOCNotifyFPD_OCNotifyNew"},
	{FPDOCNotifySEL, FPDOCNotifyFPD_OCNotifyDestroySEL, L"FPDOCNotifyFPD_OCNotifyDestroy"},
	{FPDOCPropertiesSEL, FPDOCPropertiesNewSEL, L"FPDOCPropertiesNew"},
	{FPDOCPropertiesSEL, FPDOCPropertiesDestroySEL, L"FPDOCPropertiesDestroy"},
	{FPDOCPropertiesSEL, FPDOCPropertiesGetDocumentSEL, L"FPDOCPropertiesGetDocument"},
	{FPDOCPropertiesSEL, FPDOCPropertiesGetOCGroupsSEL, L"FPDOCPropertiesGetOCGroups"},
	{FPDOCPropertiesSEL, FPDOCPropertiesIsOCGroupSEL, L"FPDOCPropertiesIsOCGroup"},
	{FPDOCPropertiesSEL, FPDOCPropertiesRetrieveOCGPagesSEL, L"FPDOCPropertiesRetrieveOCGPages"},
	{FPDOCPropertiesSEL, FPDOCPropertiesIsOCGInPageSEL, L"FPDOCPropertiesIsOCGInPage"},
	{FPDOCPropertiesSEL, FPDOCPropertiesGetOCGroupOrderSEL, L"FPDOCPropertiesGetOCGroupOrder"},
	{FPDOCPropertiesSEL, FPDOCPropertiesCountConfigsSEL, L"FPDOCPropertiesCountConfigs"},
	{FPDOCPropertiesSEL, FPDOCPropertiesGetConfigSEL, L"FPDOCPropertiesGetConfig"},
	{FPDOCPropertiesSEL, FPDOCPropertiesAddOCNotifySEL, L"FPDOCPropertiesAddOCNotify"},
	{FPDOCPropertiesSEL, FPDOCPropertiesRemoveOCNotifySEL, L"FPDOCPropertiesRemoveOCNotify"},
	{FPDLWinParamSEL, FPDLWinParamNewSEL, L"FPDLWinParamNew"},
	{FPDLWinParamSEL, FPDLWinParamDestroySEL, L"FPDLWinParamDestroy"},
	{FPDLWinParamSEL, FPDLWinParamGetFileNameSEL, L"FPDLWinParamGetFileName"},
	{FPDLWinParamSEL, FPDLWinParamSetFileNameSEL, L"FPDLWinParamSetFileName"},
	{FPDLWinParamSEL, FPDLWinParamGetDefaultDirectorySEL, L"FPDLWinParamGetDefaultDirectory"},
	{FPDLWinParamSEL, FPDLWinParamSetDefaultDirectorySEL, L"FPDLWinParamSetDefaultDirectory"},
	{FPDLWinParamSEL, FPDLWinParamGetOperationSEL, L"FPDLWinParamGetOperation"},
	{FPDLWinParamSEL, FPDLWinParamSetOperationSEL, L"FPDLWinParamSetOperation"},
	{FPDLWinParamSEL, FPDLWinParamGetParamSEL, L"FPDLWinParamGetParam"},
	{FPDLWinParamSEL, FPDLWinParamSetParamSEL, L"FPDLWinParamSetParam"},
	{FPDLWinParamSEL, FPDLWinParamGetDictSEL, L"FPDLWinParamGetDict"},
	{FPDLWinParamSEL, FPDLWinParamSetDictSEL, L"FPDLWinParamSetDict"},
	{FPDActionFieldsSEL, FPDActionFieldsNewSEL, L"FPDActionFieldsNew"},
	{FPDActionFieldsSEL, FPDActionFieldsDestroySEL, L"FPDActionFieldsDestroy"},
	{FPDActionFieldsSEL, FPDActionFieldsGetFieldsCountSEL, L"FPDActionFieldsGetFieldsCount"},
	{FPDActionFieldsSEL, FPDActionFieldsGetAllFieldsSEL, L"FPDActionFieldsGetAllFields"},
	{FPDActionFieldsSEL, FPDActionFieldsGetFieldSEL, L"FPDActionFieldsGetField"},
	{FPDActionFieldsSEL, FPDActionFieldsInsertFieldSEL, L"FPDActionFieldsInsertField"},
	{FPDActionFieldsSEL, FPDActionFieldsRemoveFieldSEL, L"FPDActionFieldsRemoveField"},
	{FPDActionFieldsSEL, FPDActionFieldsGetActionSEL, L"FPDActionFieldsGetAction"},
	{FPDActionSEL, FPDActionNewSEL, L"FPDActionNew"},
	{FPDActionSEL, FPDActionNew2SEL, L"FPDActionNew2"},
	{FPDActionSEL, FPDActionNew3SEL, L"FPDActionNew3"},
	{FPDActionSEL, FPDActionDestroySEL, L"FPDActionDestroy"},
	{FPDActionSEL, FPDActionGetTypeNameSEL, L"FPDActionGetTypeName"},
	{FPDActionSEL, FPDActionGetTypeSEL, L"FPDActionGetType"},
	{FPDActionSEL, FPDActionGetDestSEL, L"FPDActionGetDest"},
	{FPDActionSEL, FPDActionSetDestSEL, L"FPDActionSetDest"},
	{FPDActionSEL, FPDActionGetFilePathSEL, L"FPDActionGetFilePath"},
	{FPDActionSEL, FPDActionSetFilePathSEL, L"FPDActionSetFilePath"},
	{FPDActionSEL, FPDActionGetNewWindowSEL, L"FPDActionGetNewWindow"},
	{FPDActionSEL, FPDActionSetNewWindowSEL, L"FPDActionSetNewWindow"},
	{FPDActionSEL, FPDActionGetWinParamSEL, L"FPDActionGetWinParam"},
	{FPDActionSEL, FPDActionSetWinParamSEL, L"FPDActionSetWinParam"},
	{FPDActionSEL, FPDActionGetURISEL, L"FPDActionGetURI"},
	{FPDActionSEL, FPDActionSetURISEL, L"FPDActionSetURI"},
	{FPDActionSEL, FPDActionGetMouseMapSEL, L"FPDActionGetMouseMap"},
	{FPDActionSEL, FPDActionSetMouseMapSEL, L"FPDActionSetMouseMap"},
	{FPDActionSEL, FPDActionGetWidgetsSEL, L"FPDActionGetWidgets"},
	{FPDActionSEL, FPDActionGetHideStatusSEL, L"FPDActionGetHideStatus"},
	{FPDActionSEL, FPDActionSetHideStatusSEL, L"FPDActionSetHideStatus"},
	{FPDActionSEL, FPDActionGetNameActionSEL, L"FPDActionGetNameAction"},
	{FPDActionSEL, FPDActionSetNameActionSEL, L"FPDActionSetNameAction"},
	{FPDActionSEL, FPDActionGetFlagsSEL, L"FPDActionGetFlags"},
	{FPDActionSEL, FPDActionSetFlagsSEL, L"FPDActionSetFlags"},
	{FPDActionSEL, FPDActionGetJavaScriptSEL, L"FPDActionGetJavaScript"},
	{FPDActionSEL, FPDActionSetJavaScriptSEL, L"FPDActionSetJavaScript"},
	{FPDActionSEL, FPDActionSetJavaScriptWSEL, L"FPDActionSetJavaScriptW"},
	{FPDActionSEL, FPDActionCountRenditionsSEL, L"FPDActionCountRenditions"},
	{FPDActionSEL, FPDActionGetRenditionSEL, L"FPDActionGetRendition"},
	{FPDActionSEL, FPDActionInsertRenditionSEL, L"FPDActionInsertRendition"},
	{FPDActionSEL, FPDActionRemoveRenditionSEL, L"FPDActionRemoveRendition"},
	{FPDActionSEL, FPDActionGetAnnotSEL, L"FPDActionGetAnnot"},
	{FPDActionSEL, FPDActionSetAnnotSEL, L"FPDActionSetAnnot"},
	{FPDActionSEL, FPDActionGetOperationTypeSEL, L"FPDActionGetOperationType"},
	{FPDActionSEL, FPDActionSetOperationTypeSEL, L"FPDActionSetOperationType"},
	{FPDActionSEL, FPDActionGetSoundStreamSEL, L"FPDActionGetSoundStream"},
	{FPDActionSEL, FPDActionGetVolumeSEL, L"FPDActionGetVolume"},
	{FPDActionSEL, FPDActionIsSynchronousSEL, L"FPDActionIsSynchronous"},
	{FPDActionSEL, FPDActionIsRepeatSEL, L"FPDActionIsRepeat"},
	{FPDActionSEL, FPDActionIsMixPlaySEL, L"FPDActionIsMixPlay"},
	{FPDActionSEL, FPDActionCountOCGStatesSEL, L"FPDActionCountOCGStates"},
	{FPDActionSEL, FPDActionGetOCGStatesSEL, L"FPDActionGetOCGStates"},
	{FPDActionSEL, FPDActionInsertOCGStatesSEL, L"FPDActionInsertOCGStates"},
	{FPDActionSEL, FPDActionReplaceOCGStatesSEL, L"FPDActionReplaceOCGStates"},
	{FPDActionSEL, FPDActionRemoveOCGStatesSEL, L"FPDActionRemoveOCGStates"},
	{FPDActionSEL, FPDActionIsStatePreservedSEL, L"FPDActionIsStatePreserved"},
	{FPDActionSEL, FPDActionSetStatePreservedSEL, L"FPDActionSetStatePreserved"},
	{FPDActionSEL, FPDActionGetSubActionsCountSEL, L"FPDActionGetSubActionsCount"},
	{FPDActionSEL, FPDActionGetSubActionSEL, L"FPDActionGetSubAction"},
	{FPDActionSEL, FPDActionInsertSubActionSEL, L"FPDActionInsertSubAction"},
	{FPDActionSEL, FPDActionRemoveSubActionSEL, L"FPDActionRemoveSubAction"},
	{FPDActionSEL, FPDActionRemoveAllSubActionsSEL, L"FPDActionRemoveAllSubActions"},
	{FPDActionSEL, FPDActionGetDictSEL, L"FPDActionGetDict"},
	{FPDActionSEL, FPDActionNew4SEL, L"FPDActionNew4"},
	{FPDActionSEL, FPDActionCreateGoToESEL, L"FPDActionCreateGoToE"},
	{FPDActionSEL, FPDActionSetDest2SEL, L"FPDActionSetDest2"},
	{FPDAActionSEL, FPDAActionNewSEL, L"FPDAActionNew"},
	{FPDAActionSEL, FPDAActionDestroySEL, L"FPDAActionDestroy"},
	{FPDAActionSEL, FPDAActionActionExistSEL, L"FPDAActionActionExist"},
	{FPDAActionSEL, FPDAActionGetActionSEL, L"FPDAActionGetAction"},
	{FPDAActionSEL, FPDAActionSetActionSEL, L"FPDAActionSetAction"},
	{FPDAActionSEL, FPDAActionRemoveActionSEL, L"FPDAActionRemoveAction"},
	{FPDAActionSEL, FPDAActionGetStartPosSEL, L"FPDAActionGetStartPos"},
	{FPDAActionSEL, FPDAActionGetNextActionSEL, L"FPDAActionGetNextAction"},
	{FPDAActionSEL, FPDAActionGetDictionarySEL, L"FPDAActionGetDictionary"},
	{FPDDocJSActionsSEL, FPDDocJSActionsNewSEL, L"FPDDocJSActionsNew"},
	{FPDDocJSActionsSEL, FPDDocJSActionsDestroySEL, L"FPDDocJSActionsDestroy"},
	{FPDDocJSActionsSEL, FPDDocJSActionsCountJSActionsSEL, L"FPDDocJSActionsCountJSActions"},
	{FPDDocJSActionsSEL, FPDDocJSActionsGetJSActionSEL, L"FPDDocJSActionsGetJSAction"},
	{FPDDocJSActionsSEL, FPDDocJSActionsGetJSAction2SEL, L"FPDDocJSActionsGetJSAction2"},
	{FPDDocJSActionsSEL, FPDDocJSActionsSetJSActionSEL, L"FPDDocJSActionsSetJSAction"},
	{FPDDocJSActionsSEL, FPDDocJSActionsFindJSActionSEL, L"FPDDocJSActionsFindJSAction"},
	{FPDDocJSActionsSEL, FPDDocJSActionsRemoveJSActionSEL, L"FPDDocJSActionsRemoveJSAction"},
	{FPDDocJSActionsSEL, FPDDocJSActionsGetDocumentSEL, L"FPDDocJSActionsGetDocument"},
	{FPDFileSpecSEL, FPDFileSpecNewSEL, L"FPDFileSpecNew"},
	{FPDFileSpecSEL, FPDFileSpecNewFromObjSEL, L"FPDFileSpecNewFromObj"},
	{FPDFileSpecSEL, FPDFileSpecDestroySEL, L"FPDFileSpecDestroy"},
	{FPDFileSpecSEL, FPDFileSpecIsURLSEL, L"FPDFileSpecIsURL"},
	{FPDFileSpecSEL, FPDFileSpecGetFileNameSEL, L"FPDFileSpecGetFileName"},
	{FPDFileSpecSEL, FPDFileSpecGetFileStreamSEL, L"FPDFileSpecGetFileStream"},
	{FPDFileSpecSEL, FPDFileSpecSetFileNameSEL, L"FPDFileSpecSetFileName"},
	{FPDFileSpecSEL, FPDFileSpecSetEmbeddedFileSEL, L"FPDFileSpecSetEmbeddedFile"},
	{FPDFileSpecSEL, FPDFileSpecGetPDFObjctSEL, L"FPDFileSpecGetPDFObjct"},
	{FPDMediaPlayerSEL, FPDMediaPlayerNewSEL, L"FPDMediaPlayerNew"},
	{FPDMediaPlayerSEL, FPDMediaPlayerNewFromDictSEL, L"FPDMediaPlayerNewFromDict"},
	{FPDMediaPlayerSEL, FPDMediaPlayerDestroySEL, L"FPDMediaPlayerDestroy"},
	{FPDMediaPlayerSEL, FPDMediaPlayerGetSoftwareURISEL, L"FPDMediaPlayerGetSoftwareURI"},
	{FPDMediaPlayerSEL, FPDMediaPlayerSetSoftwareURISEL, L"FPDMediaPlayerSetSoftwareURI"},
	{FPDMediaPlayerSEL, FPDMediaPlayerGetOSArraySEL, L"FPDMediaPlayerGetOSArray"},
	{FPDMediaPlayerSEL, FPDMediaPlayerSetOSArraySEL, L"FPDMediaPlayerSetOSArray"},
	{FPDRenditionSEL, FPDRenditionNewSEL, L"FPDRenditionNew"},
	{FPDRenditionSEL, FPDRenditionNewFromDictSEL, L"FPDRenditionNewFromDict"},
	{FPDRenditionSEL, FPDRenditionDestroySEL, L"FPDRenditionDestroy"},
	{FPDRenditionSEL, FPDRenditionHasMediaClipSEL, L"FPDRenditionHasMediaClip"},
	{FPDRenditionSEL, FPDRenditionGetRenditionNameSEL, L"FPDRenditionGetRenditionName"},
	{FPDRenditionSEL, FPDRenditionSetRenditionNameSEL, L"FPDRenditionSetRenditionName"},
	{FPDRenditionSEL, FPDRenditionGetMediaClipNameSEL, L"FPDRenditionGetMediaClipName"},
	{FPDRenditionSEL, FPDRenditionSetMediaClipNameSEL, L"FPDRenditionSetMediaClipName"},
	{FPDRenditionSEL, FPDRenditionGetMediaClipFileSEL, L"FPDRenditionGetMediaClipFile"},
	{FPDRenditionSEL, FPDRenditionSetMediaClipFileSEL, L"FPDRenditionSetMediaClipFile"},
	{FPDRenditionSEL, FPDRenditionGetMediaClipContentTypeSEL, L"FPDRenditionGetMediaClipContentType"},
	{FPDRenditionSEL, FPDRenditionSetMediaClipContentTypeSEL, L"FPDRenditionSetMediaClipContentType"},
	{FPDRenditionSEL, FPDRenditionGetPermissionSEL, L"FPDRenditionGetPermission"},
	{FPDRenditionSEL, FPDRenditionSetPermissionSEL, L"FPDRenditionSetPermission"},
	{FPDRenditionSEL, FPDRenditionGetMediaDescriptionsSEL, L"FPDRenditionGetMediaDescriptions"},
	{FPDRenditionSEL, FPDRenditionSetMediaDescriptionsSEL, L"FPDRenditionSetMediaDescriptions"},
	{FPDRenditionSEL, FPDRenditionGetMediaBaseURLSEL, L"FPDRenditionGetMediaBaseURL"},
	{FPDRenditionSEL, FPDRenditionSetMediaBaseURLSEL, L"FPDRenditionSetMediaBaseURL"},
	{FPDRenditionSEL, FPDRenditionCountMediaPlayersSEL, L"FPDRenditionCountMediaPlayers"},
	{FPDRenditionSEL, FPDRenditionGetMediaPlayerSEL, L"FPDRenditionGetMediaPlayer"},
	{FPDRenditionSEL, FPDRenditionAddMediaPlayerSEL, L"FPDRenditionAddMediaPlayer"},
	{FPDRenditionSEL, FPDRenditionRemoveMediaPlayerSEL, L"FPDRenditionRemoveMediaPlayer"},
	{FPDRenditionSEL, FPDRenditionGetVolumnSEL, L"FPDRenditionGetVolumn"},
	{FPDRenditionSEL, FPDRenditionSetVolumnSEL, L"FPDRenditionSetVolumn"},
	{FPDRenditionSEL, FPDRenditionIsControlBarVisibleSEL, L"FPDRenditionIsControlBarVisible"},
	{FPDRenditionSEL, FPDRenditionEnableControlBarVisibleSEL, L"FPDRenditionEnableControlBarVisible"},
	{FPDRenditionSEL, FPDRenditionGetFitStyleSEL, L"FPDRenditionGetFitStyle"},
	{FPDRenditionSEL, FPDRenditionSetFitStyleSEL, L"FPDRenditionSetFitStyle"},
	{FPDRenditionSEL, FPDRenditionGetDurationSEL, L"FPDRenditionGetDuration"},
	{FPDRenditionSEL, FPDRenditionSetDurationSEL, L"FPDRenditionSetDuration"},
	{FPDRenditionSEL, FPDRenditionAutoPlaySEL, L"FPDRenditionAutoPlay"},
	{FPDRenditionSEL, FPDRenditionEnableAutoPlaySEL, L"FPDRenditionEnableAutoPlay"},
	{FPDRenditionSEL, FPDRenditionRepeatCountSEL, L"FPDRenditionRepeatCount"},
	{FPDRenditionSEL, FPDRenditionSetRepeatCountSEL, L"FPDRenditionSetRepeatCount"},
	{FPDRenditionSEL, FPDRenditionGetWindowStatusSEL, L"FPDRenditionGetWindowStatus"},
	{FPDRenditionSEL, FPDRenditionSetWindowStatusSEL, L"FPDRenditionSetWindowStatus"},
	{FPDRenditionSEL, FPDRenditionGetBackgroundColorSEL, L"FPDRenditionGetBackgroundColor"},
	{FPDRenditionSEL, FPDRenditionSetBackgroundColorSEL, L"FPDRenditionSetBackgroundColor"},
	{FPDRenditionSEL, FPDRenditionGetBackgroundOpacitySEL, L"FPDRenditionGetBackgroundOpacity"},
	{FPDRenditionSEL, FPDRenditionSetBackgroundOpacitySEL, L"FPDRenditionSetBackgroundOpacity"},
	{FPDRenditionSEL, FPDRenditionGetMonitorSEL, L"FPDRenditionGetMonitor"},
	{FPDRenditionSEL, FPDRenditionSetMonitorSEL, L"FPDRenditionSetMonitor"},
	{FPDRenditionSEL, FPDRenditionGetFloatingWindowSizeSEL, L"FPDRenditionGetFloatingWindowSize"},
	{FPDRenditionSEL, FPDRenditionSetFloatingWindowSizeSEL, L"FPDRenditionSetFloatingWindowSize"},
	{FPDRenditionSEL, FPDRenditionGetFloatingWindowRelativeTypeSEL, L"FPDRenditionGetFloatingWindowRelativeType"},
	{FPDRenditionSEL, FPDRenditionSetFloatingWindowRelativeTypeSEL, L"FPDRenditionSetFloatingWindowRelativeType"},
	{FPDRenditionSEL, FPDRenditionGetFloatingWindowPositionSEL, L"FPDRenditionGetFloatingWindowPosition"},
	{FPDRenditionSEL, FPDRenditionSetFloatingWindowPositionSEL, L"FPDRenditionSetFloatingWindowPosition"},
	{FPDRenditionSEL, FPDRenditionGetFloatingWindowOffscreenSEL, L"FPDRenditionGetFloatingWindowOffscreen"},
	{FPDRenditionSEL, FPDRenditionSetFloatingWindowOffscreenSEL, L"FPDRenditionSetFloatingWindowOffscreen"},
	{FPDRenditionSEL, FPDRenditionHasFloatingWindowTitleBarSEL, L"FPDRenditionHasFloatingWindowTitleBar"},
	{FPDRenditionSEL, FPDRenditionEnableFloatingWindowTitleBarSEL, L"FPDRenditionEnableFloatingWindowTitleBar"},
	{FPDRenditionSEL, FPDRenditionHasFloatingWindowCloseButtonSEL, L"FPDRenditionHasFloatingWindowCloseButton"},
	{FPDRenditionSEL, FPDRenditionEnableFloatingWindowCloseButtonSEL, L"FPDRenditionEnableFloatingWindowCloseButton"},
	{FPDRenditionSEL, FPDRenditionGetFloatingWindowResizeTypeSEL, L"FPDRenditionGetFloatingWindowResizeType"},
	{FPDRenditionSEL, FPDRenditionSetFloatingWindowResizeTypeSEL, L"FPDRenditionSetFloatingWindowResizeType"},
	{FPDRenditionSEL, FPDRenditionGetFloatingWindowTitleSEL, L"FPDRenditionGetFloatingWindowTitle"},
	{FPDRenditionSEL, FPDRenditionSetFloatingWindowTitleSEL, L"FPDRenditionSetFloatingWindowTitle"},
	{FPDLinkSEL, FPDLinkNewSEL, L"FPDLinkNew"},
	{FPDLinkSEL, FPDLinkDestroySEL, L"FPDLinkDestroy"},
	{FPDLinkSEL, FPDLinkGetLinkAtPointSEL, L"FPDLinkGetLinkAtPoint"},
	{FPDLinkSEL, FPDLinkCountLinksSEL, L"FPDLinkCountLinks"},
	{FPDLinkSEL, FPDLinkGetLinkSEL, L"FPDLinkGetLink"},
	{FPDLinkSEL, FPDLinkGetRectSEL, L"FPDLinkGetRect"},
	{FPDLinkSEL, FPDLinkGetDestSEL, L"FPDLinkGetDest"},
	{FPDLinkSEL, FPDLinkGetActionSEL, L"FPDLinkGetAction"},
	{FPDAnnotSEL, FPDAnnotNewSEL, L"FPDAnnotNew"},
	{FPDAnnotSEL, FPDAnnotDestroySEL, L"FPDAnnotDestroy"},
	{FPDAnnotSEL, FPDAnnotGetAnnotDictSEL, L"FPDAnnotGetAnnotDict"},
	{FPDAnnotSEL, FPDAnnotGetSubTypeSEL, L"FPDAnnotGetSubType"},
	{FPDAnnotSEL, FPDAnnotGetFlagsSEL, L"FPDAnnotGetFlags"},
	{FPDAnnotSEL, FPDAnnotGetRectSEL, L"FPDAnnotGetRect"},
	{FPDAnnotSEL, FPDAnnotDrawAppearanceSEL, L"FPDAnnotDrawAppearance"},
	{FPDAnnotSEL, FPDAnnotDrawInContextSEL, L"FPDAnnotDrawInContext"},
	{FPDAnnotSEL, FPDAnnotClearCachedAPSEL, L"FPDAnnotClearCachedAP"},
	{FPDAnnotSEL, FPDAnnotDrawBorderSEL, L"FPDAnnotDrawBorder"},
	{FPDAnnotSEL, FPDAnnotCountIRTNotesSEL, L"FPDAnnotCountIRTNotes"},
	{FPDAnnotSEL, FPDAnnotGetIRTNoteSEL, L"FPDAnnotGetIRTNote"},
	{FPDAnnotSEL, FPDAnnotGetAPFormSEL, L"FPDAnnotGetAPForm"},
	{FPDAnnotSEL, FPDAnnotSetPrivateDataSEL, L"FPDAnnotSetPrivateData"},
	{FPDAnnotSEL, FPDAnnotGetPrivateDataSEL, L"FPDAnnotGetPrivateData"},
	{FPDAnnotSEL, FPDAnnotGetAnnotListSEL, L"FPDAnnotGetAnnotList"},
	{FPDAnnotListSEL, FPDAnnotListNewSEL, L"FPDAnnotListNew"},
	{FPDAnnotListSEL, FPDAnnotListDestroySEL, L"FPDAnnotListDestroy"},
	{FPDAnnotListSEL, FPDAnnotListDisplayAnnotsSEL, L"FPDAnnotListDisplayAnnots"},
	{FPDAnnotListSEL, FPDAnnotListDisplayAnnotsExSEL, L"FPDAnnotListDisplayAnnotsEx"},
	{FPDAnnotListSEL, FPDAnnotListGetAtSEL, L"FPDAnnotListGetAt"},
	{FPDAnnotListSEL, FPDAnnotListCountSEL, L"FPDAnnotListCount"},
	{FPDAnnotListSEL, FPDAnnotListGetIndexSEL, L"FPDAnnotListGetIndex"},
	{FPDAnnotListSEL, FPDAnnotListRemoveAllSEL, L"FPDAnnotListRemoveAll"},
	{FPDAnnotListSEL, FPDAnnotListReplaceSEL, L"FPDAnnotListReplace"},
	{FPDAnnotListSEL, FPDAnnotListInsertSEL, L"FPDAnnotListInsert"},
	{FPDAnnotListSEL, FPDAnnotListRemoveSEL, L"FPDAnnotListRemove"},
	{FPDAnnotListSEL, FPDAnnotListRemoveTempSEL, L"FPDAnnotListRemoveTemp"},
	{FPDAnnotListSEL, FPDAnnotListMoveToFirstSEL, L"FPDAnnotListMoveToFirst"},
	{FPDAnnotListSEL, FPDAnnotListMoveToLastSEL, L"FPDAnnotListMoveToLast"},
	{FPDAnnotListSEL, FPDAnnotListMoveToSEL, L"FPDAnnotListMoveTo"},
	{FPDAnnotListSEL, FPDAnnotListGetDocumentSEL, L"FPDAnnotListGetDocument"},
	{FPDAnnotListSEL, FPDAnnotListSetFixedIconParamsSEL, L"FPDAnnotListSetFixedIconParams"},
	{FPDAnnotListSEL, FPDAnnotListGetAnnotMatrixSEL, L"FPDAnnotListGetAnnotMatrix"},
	{FPDAnnotListSEL, FPDAnnotListGetAnnotRectSEL, L"FPDAnnotListGetAnnotRect"},
	{FPDAnnotListSEL, FPDAnnotListGetPageSEL, L"FPDAnnotListGetPage"},
	{FPDAnnotListSEL, FPDAnnotListGetAnnotByDictSEL, L"FPDAnnotListGetAnnotByDict"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceNewSEL, L"FPDDefaultAppearanceNew"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceDestroySEL, L"FPDDefaultAppearanceDestroy"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceHasFontSEL, L"FPDDefaultAppearanceHasFont"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceGetFontStringSEL, L"FPDDefaultAppearanceGetFontString"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceGetFontSEL, L"FPDDefaultAppearanceGetFont"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceSetFontSEL, L"FPDDefaultAppearanceSetFont"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceHasColorSEL, L"FPDDefaultAppearanceHasColor"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceGetColorStringSEL, L"FPDDefaultAppearanceGetColorString"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceGetColorInclueCMYKSEL, L"FPDDefaultAppearanceGetColorInclueCMYK"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceGetColorSEL, L"FPDDefaultAppearanceGetColor"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceSetColorSEL, L"FPDDefaultAppearanceSetColor"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceHasTextMatrixSEL, L"FPDDefaultAppearanceHasTextMatrix"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceGetTextMatrixStringSEL, L"FPDDefaultAppearanceGetTextMatrixString"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceGetTextMatrixSEL, L"FPDDefaultAppearanceGetTextMatrix"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceSetTextMatrixSEL, L"FPDDefaultAppearanceSetTextMatrix"},
	{FPDDefaultAppearanceSEL, FPDDefaultAppearanceGetFontSizeSEL, L"FPDDefaultAppearanceGetFontSize"},
	{FPDFormNotifySEL, FPDFormNotifyNewSEL, L"FPDFormNotifyNew"},
	{FPDFormNotifySEL, FPDFormNotifyDestroySEL, L"FPDFormNotifyDestroy"},
	{FPDInterFormSEL, FPDInterFormNewSEL, L"FPDInterFormNew"},
	{FPDInterFormSEL, FPDInterFormDestroySEL, L"FPDInterFormDestroy"},
	{FPDInterFormSEL, FPDInterFormEnableUpdateAPSEL, L"FPDInterFormEnableUpdateAP"},
	{FPDInterFormSEL, FPDInterFormUpdatingAPEnabledSEL, L"FPDInterFormUpdatingAPEnabled"},
	{FPDInterFormSEL, FPDInterFormGenerateNewResourceNameSEL, L"FPDInterFormGenerateNewResourceName"},
	{FPDInterFormSEL, FPDInterFormAddSystemDefaultFontSEL, L"FPDInterFormAddSystemDefaultFont"},
	{FPDInterFormSEL, FPDInterFormAddSystemFontSEL, L"FPDInterFormAddSystemFont"},
	{FPDInterFormSEL, FPDInterFormAddSystemFontWSEL, L"FPDInterFormAddSystemFontW"},
	{FPDInterFormSEL, FPDInterFormAddStandardFontSEL, L"FPDInterFormAddStandardFont"},
	{FPDInterFormSEL, FPDInterFormGetNativeFontSEL, L"FPDInterFormGetNativeFont"},
	{FPDInterFormSEL, FPDInterFormGetNativeFont2SEL, L"FPDInterFormGetNativeFont2"},
	{FPDInterFormSEL, FPDInterFormAddNativeFontSEL, L"FPDInterFormAddNativeFont"},
	{FPDInterFormSEL, FPDInterFormAddNativeFont2SEL, L"FPDInterFormAddNativeFont2"},
	{FPDInterFormSEL, FPDInterFormValidateFieldNameSEL, L"FPDInterFormValidateFieldName"},
	{FPDInterFormSEL, FPDInterFormValidateFieldName2SEL, L"FPDInterFormValidateFieldName2"},
	{FPDInterFormSEL, FPDInterFormValidateFieldName3SEL, L"FPDInterFormValidateFieldName3"},
	{FPDInterFormSEL, FPDInterFormNewFieldSEL, L"FPDInterFormNewField"},
	{FPDInterFormSEL, FPDInterFormNewControlSEL, L"FPDInterFormNewControl"},
	{FPDInterFormSEL, FPDInterFormCountFieldsSEL, L"FPDInterFormCountFields"},
	{FPDInterFormSEL, FPDInterFormGetFieldSEL, L"FPDInterFormGetField"},
	{FPDInterFormSEL, FPDInterFormGetAllFieldNamesSEL, L"FPDInterFormGetAllFieldNames"},
	{FPDInterFormSEL, FPDInterFormIsValidFormFieldSEL, L"FPDInterFormIsValidFormField"},
	{FPDInterFormSEL, FPDInterFormGetFieldByDictSEL, L"FPDInterFormGetFieldByDict"},
	{FPDInterFormSEL, FPDInterFormCountControlsSEL, L"FPDInterFormCountControls"},
	{FPDInterFormSEL, FPDInterFormGetControlSEL, L"FPDInterFormGetControl"},
	{FPDInterFormSEL, FPDInterFormIsValidFormControlSEL, L"FPDInterFormIsValidFormControl"},
	{FPDInterFormSEL, FPDInterFormCountPageControlsSEL, L"FPDInterFormCountPageControls"},
	{FPDInterFormSEL, FPDInterFormGetPageControlSEL, L"FPDInterFormGetPageControl"},
	{FPDInterFormSEL, FPDInterFormGetControlAtPointSEL, L"FPDInterFormGetControlAtPoint"},
	{FPDInterFormSEL, FPDInterFormGetControlByDictSEL, L"FPDInterFormGetControlByDict"},
	{FPDInterFormSEL, FPDInterFormRenameFieldSEL, L"FPDInterFormRenameField"},
	{FPDInterFormSEL, FPDInterFormRenameField2SEL, L"FPDInterFormRenameField2"},
	{FPDInterFormSEL, FPDInterFormRenameControlSEL, L"FPDInterFormRenameControl"},
	{FPDInterFormSEL, FPDInterFormDeleteFieldSEL, L"FPDInterFormDeleteField"},
	{FPDInterFormSEL, FPDInterFormDeleteField2SEL, L"FPDInterFormDeleteField2"},
	{FPDInterFormSEL, FPDInterFormDeleteControlSEL, L"FPDInterFormDeleteControl"},
	{FPDInterFormSEL, FPDInterFormCountInternalFieldsSEL, L"FPDInterFormCountInternalFields"},
	{FPDInterFormSEL, FPDInterFormGetInternalFieldSEL, L"FPDInterFormGetInternalField"},
	{FPDInterFormSEL, FPDInterFormGetDocumentSEL, L"FPDInterFormGetDocument"},
	{FPDInterFormSEL, FPDInterFormGetFormDictSEL, L"FPDInterFormGetFormDict"},
	{FPDInterFormSEL, FPDInterFormNeedConstructAPSEL, L"FPDInterFormNeedConstructAP"},
	{FPDInterFormSEL, FPDInterFormNeedConstructAP2SEL, L"FPDInterFormNeedConstructAP2"},
	{FPDInterFormSEL, FPDInterFormCountFieldsInCalculationOrderSEL, L"FPDInterFormCountFieldsInCalculationOrder"},
	{FPDInterFormSEL, FPDInterFormGetFieldInCalculationOrderSEL, L"FPDInterFormGetFieldInCalculationOrder"},
	{FPDInterFormSEL, FPDInterFormFindFieldInCalculationOrderSEL, L"FPDInterFormFindFieldInCalculationOrder"},
	{FPDInterFormSEL, FPDInterFormInsertFieldInCalculationOrderSEL, L"FPDInterFormInsertFieldInCalculationOrder"},
	{FPDInterFormSEL, FPDInterFormMoveFieldInCalculationOrderSEL, L"FPDInterFormMoveFieldInCalculationOrder"},
	{FPDInterFormSEL, FPDInterFormRemoveFieldInCalculationOrderSEL, L"FPDInterFormRemoveFieldInCalculationOrder"},
	{FPDInterFormSEL, FPDInterFormCountFormFontsSEL, L"FPDInterFormCountFormFonts"},
	{FPDInterFormSEL, FPDInterFormGetFormFontSEL, L"FPDInterFormGetFormFont"},
	{FPDInterFormSEL, FPDInterFormGetFormFont2SEL, L"FPDInterFormGetFormFont2"},
	{FPDInterFormSEL, FPDInterFormGetFormFont3SEL, L"FPDInterFormGetFormFont3"},
	{FPDInterFormSEL, FPDInterFormGetNativeFormFontSEL, L"FPDInterFormGetNativeFormFont"},
	{FPDInterFormSEL, FPDInterFormGetNativeFormFont2SEL, L"FPDInterFormGetNativeFormFont2"},
	{FPDInterFormSEL, FPDInterFormFindFormFontSEL, L"FPDInterFormFindFormFont"},
	{FPDInterFormSEL, FPDInterFormFindFormFont2SEL, L"FPDInterFormFindFormFont2"},
	{FPDInterFormSEL, FPDInterFormFindFormFont3SEL, L"FPDInterFormFindFormFont3"},
	{FPDInterFormSEL, FPDInterFormAddFormFontSEL, L"FPDInterFormAddFormFont"},
	{FPDInterFormSEL, FPDInterFormAddNativeFormFontSEL, L"FPDInterFormAddNativeFormFont"},
	{FPDInterFormSEL, FPDInterFormAddNativeFormFont2SEL, L"FPDInterFormAddNativeFormFont2"},
	{FPDInterFormSEL, FPDInterFormRemoveFormFontSEL, L"FPDInterFormRemoveFormFont"},
	{FPDInterFormSEL, FPDInterFormRemoveFormFont2SEL, L"FPDInterFormRemoveFormFont2"},
	{FPDInterFormSEL, FPDInterFormGetDefaultAppearanceSEL, L"FPDInterFormGetDefaultAppearance"},
	{FPDInterFormSEL, FPDInterFormSetDefaultAppearanceSEL, L"FPDInterFormSetDefaultAppearance"},
	{FPDInterFormSEL, FPDInterFormGetDefaultFormFontSEL, L"FPDInterFormGetDefaultFormFont"},
	{FPDInterFormSEL, FPDInterFormSetDefaultFormFontSEL, L"FPDInterFormSetDefaultFormFont"},
	{FPDInterFormSEL, FPDInterFormGetFormAlignmentSEL, L"FPDInterFormGetFormAlignment"},
	{FPDInterFormSEL, FPDInterFormSetFormAlignmentSEL, L"FPDInterFormSetFormAlignment"},
	{FPDInterFormSEL, FPDInterFormCheckRequiredFieldsSEL, L"FPDInterFormCheckRequiredFields"},
	{FPDInterFormSEL, FPDInterFormExportToFDFSEL, L"FPDInterFormExportToFDF"},
	{FPDInterFormSEL, FPDInterFormExportToFDF2SEL, L"FPDInterFormExportToFDF2"},
	{FPDInterFormSEL, FPDInterFormImportFromFDFSEL, L"FPDInterFormImportFromFDF"},
	{FPDInterFormSEL, FPDInterFormResetFormSEL, L"FPDInterFormResetForm"},
	{FPDInterFormSEL, FPDInterFormResetForm2SEL, L"FPDInterFormResetForm2"},
	{FPDInterFormSEL, FPDInterFormReloadFormSEL, L"FPDInterFormReloadForm"},
	{FPDInterFormSEL, FPDInterFormGetFormNotifySEL, L"FPDInterFormGetFormNotify"},
	{FPDInterFormSEL, FPDInterFormSetFormNotifySEL, L"FPDInterFormSetFormNotify"},
	{FPDInterFormSEL, FPDInterFormGetPageWithWidgetSEL, L"FPDInterFormGetPageWithWidget"},
	{FPDInterFormSEL, FPDInterFormIsUpdatedSEL, L"FPDInterFormIsUpdated"},
	{FPDInterFormSEL, FPDInterFormClearUpdatedFlagSEL, L"FPDInterFormClearUpdatedFlag"},
	{FPDInterFormSEL, FPDInterFormFixPageFieldsSEL, L"FPDInterFormFixPageFields"},
	{FPDInterFormSEL, FPDInterFormAddControlSEL, L"FPDInterFormAddControl"},
	{FPDInterFormSEL, FPDInterFormNew2SEL, L"FPDInterFormNew2"},
	{FPDInterFormSEL, FPDInterFormExportToFDF3SEL, L"FPDInterFormExportToFDF3"},
	{FPDInterFormSEL, FPDInterFormCreateFieldSEL, L"FPDInterFormCreateField"},
	{FPDFormFieldSEL, FPDFormFieldGetFullNameSEL, L"FPDFormFieldGetFullName"},
	{FPDFormFieldSEL, FPDFormFieldGetTypeSEL, L"FPDFormFieldGetType"},
	{FPDFormFieldSEL, FPDFormFieldGetFlagsSEL, L"FPDFormFieldGetFlags"},
	{FPDFormFieldSEL, FPDFormFieldGetInterFormSEL, L"FPDFormFieldGetInterForm"},
	{FPDFormFieldSEL, FPDFormFieldGetFieldDictSEL, L"FPDFormFieldGetFieldDict"},
	{FPDFormFieldSEL, FPDFormFieldResetFieldSEL, L"FPDFormFieldResetField"},
	{FPDFormFieldSEL, FPDFormFieldCountControlsSEL, L"FPDFormFieldCountControls"},
	{FPDFormFieldSEL, FPDFormFieldGetControlSEL, L"FPDFormFieldGetControl"},
	{FPDFormFieldSEL, FPDFormFieldGetControlIndexSEL, L"FPDFormFieldGetControlIndex"},
	{FPDFormFieldSEL, FPDFormFieldGetFieldTypeSEL, L"FPDFormFieldGetFieldType"},
	{FPDFormFieldSEL, FPDFormFieldGetAdditionalActionSEL, L"FPDFormFieldGetAdditionalAction"},
	{FPDFormFieldSEL, FPDFormFieldSetAdditionalActionSEL, L"FPDFormFieldSetAdditionalAction"},
	{FPDFormFieldSEL, FPDFormFieldGetAlternateNameSEL, L"FPDFormFieldGetAlternateName"},
	{FPDFormFieldSEL, FPDFormFieldSetAlternateNameSEL, L"FPDFormFieldSetAlternateName"},
	{FPDFormFieldSEL, FPDFormFieldSetAlternateNameWSEL, L"FPDFormFieldSetAlternateNameW"},
	{FPDFormFieldSEL, FPDFormFieldGetMappingNameSEL, L"FPDFormFieldGetMappingName"},
	{FPDFormFieldSEL, FPDFormFieldSetMappingNameSEL, L"FPDFormFieldSetMappingName"},
	{FPDFormFieldSEL, FPDFormFieldSetMappingNameWSEL, L"FPDFormFieldSetMappingNameW"},
	{FPDFormFieldSEL, FPDFormFieldGetFieldFlagsSEL, L"FPDFormFieldGetFieldFlags"},
	{FPDFormFieldSEL, FPDFormFieldSetFieldFlagsSEL, L"FPDFormFieldSetFieldFlags"},
	{FPDFormFieldSEL, FPDFormFieldGetDefaultStyleSEL, L"FPDFormFieldGetDefaultStyle"},
	{FPDFormFieldSEL, FPDFormFieldSetDefaultStyleSEL, L"FPDFormFieldSetDefaultStyle"},
	{FPDFormFieldSEL, FPDFormFieldGetRichTextStringSEL, L"FPDFormFieldGetRichTextString"},
	{FPDFormFieldSEL, FPDFormFieldSetRichTextStringSEL, L"FPDFormFieldSetRichTextString"},
	{FPDFormFieldSEL, FPDFormFieldSetRichTextStringWSEL, L"FPDFormFieldSetRichTextStringW"},
	{FPDFormFieldSEL, FPDFormFieldGetValueSEL, L"FPDFormFieldGetValue"},
	{FPDFormFieldSEL, FPDFormFieldGetDefaultValueSEL, L"FPDFormFieldGetDefaultValue"},
	{FPDFormFieldSEL, FPDFormFieldSetValueSEL, L"FPDFormFieldSetValue"},
	{FPDFormFieldSEL, FPDFormFieldSetDefaultValueSEL, L"FPDFormFieldSetDefaultValue"},
	{FPDFormFieldSEL, FPDFormFieldGetMaxLenSEL, L"FPDFormFieldGetMaxLen"},
	{FPDFormFieldSEL, FPDFormFieldSetMaxLenSEL, L"FPDFormFieldSetMaxLen"},
	{FPDFormFieldSEL, FPDFormFieldCountSelectedItemsSEL, L"FPDFormFieldCountSelectedItems"},
	{FPDFormFieldSEL, FPDFormFieldGetSelectedIndexSEL, L"FPDFormFieldGetSelectedIndex"},
	{FPDFormFieldSEL, FPDFormFieldClearSelectionSEL, L"FPDFormFieldClearSelection"},
	{FPDFormFieldSEL, FPDFormFieldIsItemSelectedSEL, L"FPDFormFieldIsItemSelected"},
	{FPDFormFieldSEL, FPDFormFieldSetItemSelectionSEL, L"FPDFormFieldSetItemSelection"},
	{FPDFormFieldSEL, FPDFormFieldIsItemDefaultSelectedSEL, L"FPDFormFieldIsItemDefaultSelected"},
	{FPDFormFieldSEL, FPDFormFieldSetItemDefaultSelectionSEL, L"FPDFormFieldSetItemDefaultSelection"},
	{FPDFormFieldSEL, FPDFormFieldGetDefaultSelectedItemSEL, L"FPDFormFieldGetDefaultSelectedItem"},
	{FPDFormFieldSEL, FPDFormFieldCountOptionsSEL, L"FPDFormFieldCountOptions"},
	{FPDFormFieldSEL, FPDFormFieldGetOptionLabelSEL, L"FPDFormFieldGetOptionLabel"},
	{FPDFormFieldSEL, FPDFormFieldGetOptionValueSEL, L"FPDFormFieldGetOptionValue"},
	{FPDFormFieldSEL, FPDFormFieldInsertOptionSEL, L"FPDFormFieldInsertOption"},
	{FPDFormFieldSEL, FPDFormFieldFindOptionSEL, L"FPDFormFieldFindOption"},
	{FPDFormFieldSEL, FPDFormFieldFindOptionValueSEL, L"FPDFormFieldFindOptionValue"},
	{FPDFormFieldSEL, FPDFormFieldSetOptionLabelSEL, L"FPDFormFieldSetOptionLabel"},
	{FPDFormFieldSEL, FPDFormFieldSetOptionValueSEL, L"FPDFormFieldSetOptionValue"},
	{FPDFormFieldSEL, FPDFormFieldDeleteOptionSEL, L"FPDFormFieldDeleteOption"},
	{FPDFormFieldSEL, FPDFormFieldClearOptionsSEL, L"FPDFormFieldClearOptions"},
	{FPDFormFieldSEL, FPDFormFieldCheckControlSEL, L"FPDFormFieldCheckControl"},
	{FPDFormFieldSEL, FPDFormFieldDefaultCheckControlSEL, L"FPDFormFieldDefaultCheckControl"},
	{FPDFormFieldSEL, FPDFormFieldUpdateUnisonStatusSEL, L"FPDFormFieldUpdateUnisonStatus"},
	{FPDFormFieldSEL, FPDFormFieldGetTopVisibleIndexSEL, L"FPDFormFieldGetTopVisibleIndex"},
	{FPDFormFieldSEL, FPDFormFieldSetTopVisibleIndexSEL, L"FPDFormFieldSetTopVisibleIndex"},
	{FPDFormFieldSEL, FPDFormFieldCountSelectedOptionsSEL, L"FPDFormFieldCountSelectedOptions"},
	{FPDFormFieldSEL, FPDFormFieldGetSelectedOptionIndexSEL, L"FPDFormFieldGetSelectedOptionIndex"},
	{FPDFormFieldSEL, FPDFormFieldIsOptionSelectedSEL, L"FPDFormFieldIsOptionSelected"},
	{FPDFormFieldSEL, FPDFormFieldSelectOptionSEL, L"FPDFormFieldSelectOption"},
	{FPDFormFieldSEL, FPDFormFieldClearSelectedOptionsSEL, L"FPDFormFieldClearSelectedOptions"},
	{FPDFormFieldSEL, FPDFormFieldGetFontSizeSEL, L"FPDFormFieldGetFontSize"},
	{FPDFormFieldSEL, FPDFormFieldGetFontSEL, L"FPDFormFieldGetFont"},
	{FPDFormFieldSEL, FPDFormFieldSetItemDefaultSelection2SEL, L"FPDFormFieldSetItemDefaultSelection2"},
	{FPDFormFieldSEL, FPDFormFieldGetDefaultSelectedItemArraySEL, L"FPDFormFieldGetDefaultSelectedItemArray"},
	{FPDFormFieldSEL, FPDFormFieldIsTextOverflowSEL, L"FPDFormFieldIsTextOverflow"},
	{FPDFormFieldSEL, FPDFormFieldGetListBoxValuesSEL, L"FPDFormFieldGetListBoxValues"},
	{FPDIconFitSEL, FPDIconFitNewSEL, L"FPDIconFitNew"},
	{FPDIconFitSEL, FPDIconFitDestroySEL, L"FPDIconFitDestroy"},
	{FPDIconFitSEL, FPDIconFitGetScaleMethodSEL, L"FPDIconFitGetScaleMethod"},
	{FPDIconFitSEL, FPDIconFitSetScaleMethodSEL, L"FPDIconFitSetScaleMethod"},
	{FPDIconFitSEL, FPDIconFitIsProportionalScaleSEL, L"FPDIconFitIsProportionalScale"},
	{FPDIconFitSEL, FPDIconFitProportionalScaleSEL, L"FPDIconFitProportionalScale"},
	{FPDIconFitSEL, FPDIconFitGetIconPositionSEL, L"FPDIconFitGetIconPosition"},
	{FPDIconFitSEL, FPDIconFitSetIconPositionSEL, L"FPDIconFitSetIconPosition"},
	{FPDIconFitSEL, FPDIconFitGetFittingBoundsSEL, L"FPDIconFitGetFittingBounds"},
	{FPDIconFitSEL, FPDIconFitSetFittingBoundsSEL, L"FPDIconFitSetFittingBounds"},
	{FPDIconFitSEL, FPDIconFitGetDictSEL, L"FPDIconFitGetDict"},
	{FPDFormControlSEL, FPDFormControlGetTypeSEL, L"FPDFormControlGetType"},
	{FPDFormControlSEL, FPDFormControlGetInterFormSEL, L"FPDFormControlGetInterForm"},
	{FPDFormControlSEL, FPDFormControlGetFieldSEL, L"FPDFormControlGetField"},
	{FPDFormControlSEL, FPDFormControlGetWidgetSEL, L"FPDFormControlGetWidget"},
	{FPDFormControlSEL, FPDFormControlGetRectSEL, L"FPDFormControlGetRect"},
	{FPDFormControlSEL, FPDFormControlDrawControlSEL, L"FPDFormControlDrawControl"},
	{FPDFormControlSEL, FPDFormControlGetCheckedAPStateSEL, L"FPDFormControlGetCheckedAPState"},
	{FPDFormControlSEL, FPDFormControlGetExportValueSEL, L"FPDFormControlGetExportValue"},
	{FPDFormControlSEL, FPDFormControlSetExportValueSEL, L"FPDFormControlSetExportValue"},
	{FPDFormControlSEL, FPDFormControlIsCheckedSEL, L"FPDFormControlIsChecked"},
	{FPDFormControlSEL, FPDFormControlIsDefaultCheckedSEL, L"FPDFormControlIsDefaultChecked"},
	{FPDFormControlSEL, FPDFormControlGetHighlightingModeSEL, L"FPDFormControlGetHighlightingMode"},
	{FPDFormControlSEL, FPDFormControlSetHighlightingModeSEL, L"FPDFormControlSetHighlightingMode"},
	{FPDFormControlSEL, FPDFormControlHasMKEntrySEL, L"FPDFormControlHasMKEntry"},
	{FPDFormControlSEL, FPDFormControlRemoveMKEntrySEL, L"FPDFormControlRemoveMKEntry"},
	{FPDFormControlSEL, FPDFormControlGetRotationSEL, L"FPDFormControlGetRotation"},
	{FPDFormControlSEL, FPDFormControlSetRotationSEL, L"FPDFormControlSetRotation"},
	{FPDFormControlSEL, FPDFormControlGetBorderColorSEL, L"FPDFormControlGetBorderColor"},
	{FPDFormControlSEL, FPDFormControlGetOriginalBorderColorSEL, L"FPDFormControlGetOriginalBorderColor"},
	{FPDFormControlSEL, FPDFormControlGetOriginalBorderColor2SEL, L"FPDFormControlGetOriginalBorderColor2"},
	{FPDFormControlSEL, FPDFormControlSetBorderColorSEL, L"FPDFormControlSetBorderColor"},
	{FPDFormControlSEL, FPDFormControlGetBackgroundColorSEL, L"FPDFormControlGetBackgroundColor"},
	{FPDFormControlSEL, FPDFormControlGetOriginalBackgroundColorSEL, L"FPDFormControlGetOriginalBackgroundColor"},
	{FPDFormControlSEL, FPDFormControlGetOriginalBackgroundColor2SEL, L"FPDFormControlGetOriginalBackgroundColor2"},
	{FPDFormControlSEL, FPDFormControlSetBackgroundColorSEL, L"FPDFormControlSetBackgroundColor"},
	{FPDFormControlSEL, FPDFormControlGetNormalCaptionSEL, L"FPDFormControlGetNormalCaption"},
	{FPDFormControlSEL, FPDFormControlSetNormalCaptionSEL, L"FPDFormControlSetNormalCaption"},
	{FPDFormControlSEL, FPDFormControlSetNormalCaptionWSEL, L"FPDFormControlSetNormalCaptionW"},
	{FPDFormControlSEL, FPDFormControlGetRolloverCaptionSEL, L"FPDFormControlGetRolloverCaption"},
	{FPDFormControlSEL, FPDFormControlSetRolloverCaptionSEL, L"FPDFormControlSetRolloverCaption"},
	{FPDFormControlSEL, FPDFormControlSetRolloverCaptionWSEL, L"FPDFormControlSetRolloverCaptionW"},
	{FPDFormControlSEL, FPDFormControlGetDownCaptionSEL, L"FPDFormControlGetDownCaption"},
	{FPDFormControlSEL, FPDFormControlSetDownCaptionSEL, L"FPDFormControlSetDownCaption"},
	{FPDFormControlSEL, FPDFormControlSetDownCaptionWSEL, L"FPDFormControlSetDownCaptionW"},
	{FPDFormControlSEL, FPDFormControlGetNormalIconSEL, L"FPDFormControlGetNormalIcon"},
	{FPDFormControlSEL, FPDFormControlSetNormalIconSEL, L"FPDFormControlSetNormalIcon"},
	{FPDFormControlSEL, FPDFormControlGetRolloverIconSEL, L"FPDFormControlGetRolloverIcon"},
	{FPDFormControlSEL, FPDFormControlSetRolloverIconSEL, L"FPDFormControlSetRolloverIcon"},
	{FPDFormControlSEL, FPDFormControlGetDownIconSEL, L"FPDFormControlGetDownIcon"},
	{FPDFormControlSEL, FPDFormControlSetDownIconSEL, L"FPDFormControlSetDownIcon"},
	{FPDFormControlSEL, FPDFormControlGetIconFitSEL, L"FPDFormControlGetIconFit"},
	{FPDFormControlSEL, FPDFormControlSetIconFitSEL, L"FPDFormControlSetIconFit"},
	{FPDFormControlSEL, FPDFormControlGetTextPositionSEL, L"FPDFormControlGetTextPosition"},
	{FPDFormControlSEL, FPDFormControlSetTextPositionSEL, L"FPDFormControlSetTextPosition"},
	{FPDFormControlSEL, FPDFormControlGetActionSEL, L"FPDFormControlGetAction"},
	{FPDFormControlSEL, FPDFormControlSetActionSEL, L"FPDFormControlSetAction"},
	{FPDFormControlSEL, FPDFormControlGetAdditionalActionSEL, L"FPDFormControlGetAdditionalAction"},
	{FPDFormControlSEL, FPDFormControlSetAdditionalActionSEL, L"FPDFormControlSetAdditionalAction"},
	{FPDFormControlSEL, FPDFormControlGetDefaultAppearanceSEL, L"FPDFormControlGetDefaultAppearance"},
	{FPDFormControlSEL, FPDFormControlSetDefaultAppearanceSEL, L"FPDFormControlSetDefaultAppearance"},
	{FPDFormControlSEL, FPDFormControlGetDefaultControlFontSEL, L"FPDFormControlGetDefaultControlFont"},
	{FPDFormControlSEL, FPDFormControlSetDefaultControlFontSEL, L"FPDFormControlSetDefaultControlFont"},
	{FPDFormControlSEL, FPDFormControlGetControlAlignmentSEL, L"FPDFormControlGetControlAlignment"},
	{FPDFormControlSEL, FPDFormControlSetControlAlignmentSEL, L"FPDFormControlSetControlAlignment"},
	{FPDFormControlSEL, FPDFormControlDrawControl2SEL, L"FPDFormControlDrawControl2"},
	{FPDFormControlSEL, FPDFormControlGetAActionSEL, L"FPDFormControlGetAAction"},
	{FPDFDFDocSEL, FPDFDFDocNewSEL, L"FPDFDFDocNew"},
	{FPDFDFDocSEL, FPDFDFDocOpenFromFileSEL, L"FPDFDFDocOpenFromFile"},
	{FPDFDFDocSEL, FPDFDFDocPareMemorySEL, L"FPDFDFDocPareMemory"},
	{FPDFDFDocSEL, FPDFDFDocDestroySEL, L"FPDFDFDocDestroy"},
	{FPDFDFDocSEL, FPDFDFDocWriteFileSEL, L"FPDFDFDocWriteFile"},
	{FPDFDFDocSEL, FPDFDFDocGetRootSEL, L"FPDFDFDocGetRoot"},
	{FPDFDFDocSEL, FPDFDFDocGetWin32PathSEL, L"FPDFDFDocGetWin32Path"},
	{FPDFDFDocSEL, FPDFDFDocGetIndirectObjectSEL, L"FPDFDFDocGetIndirectObject"},
	{FPDFDFDocSEL, FPDFDFDocGetIndirectTypeSEL, L"FPDFDFDocGetIndirectType"},
	{FPDFDFDocSEL, FPDFDFDocAddIndirectObjectSEL, L"FPDFDFDocAddIndirectObject"},
	{FPDFDFDocSEL, FPDFDFDocReleaseIndirectObjectSEL, L"FPDFDFDocReleaseIndirectObject"},
	{FPDFDFDocSEL, FPDFDFDocDeleteIndirectObjectSEL, L"FPDFDFDocDeleteIndirectObject"},
	{FPDFDFDocSEL, FPDFDFDocImportIndirectObjectSEL, L"FPDFDFDocImportIndirectObject"},
	{FPDFDFDocSEL, FPDFDFDocImportExternalObjectSEL, L"FPDFDFDocImportExternalObject"},
	{FPDFDFDocSEL, FPDFDFDocInsertIndirectObjectSEL, L"FPDFDFDocInsertIndirectObject"},
	{FPDFDFDocSEL, FPDFDFDocGetLastobjNumSEL, L"FPDFDFDocGetLastobjNum"},
	{FPDFDFDocSEL, FPDFDFDocReloadFileStreamsSEL, L"FPDFDFDocReloadFileStreams"},
	{FPDFDFDocSEL, FPDFDFDocGetStartPositionSEL, L"FPDFDFDocGetStartPosition"},
	{FPDFDFDocSEL, FPDFDFDocGetNextAssocSEL, L"FPDFDFDocGetNextAssoc"},
	{FPDFDFDocSEL, FPDFDFDocIsModifiedSEL, L"FPDFDFDocIsModified"},
	{FPDFDFDocSEL, FPDFDFDocClearModifiedSEL, L"FPDFDFDocClearModified"},
	{FPDFDFDocSEL, FPDFDFDocWriteBufSEL, L"FPDFDFDocWriteBuf"},
	{FPDFDFDocSEL, FPDFDFDocGetAnnotCountSEL, L"FPDFDFDocGetAnnotCount"},
	{FPDFDFDocSEL, FPDFDFDocGetAnnotDictSEL, L"FPDFDFDocGetAnnotDict"},
	{FPDFDFDocSEL, FPDFDFDocGetAnnotPageIndexSEL, L"FPDFDFDocGetAnnotPageIndex"},
	{FPDFDFDocSEL, FPDFDFDocExportAnnotToPDFPageSEL, L"FPDFDFDocExportAnnotToPDFPage"},
	{FPDFDFDocSEL, FPDFDFDocImportPDFAnnotSEL, L"FPDFDFDocImportPDFAnnot"},
	{FPDFDFDocSEL, FPDFDFDocSetPDFPathSEL, L"FPDFDFDocSetPDFPath"},
	{FPDFDFDocSEL, FPDFDFDocGetFieldAttrSEL, L"FPDFDFDocGetFieldAttr"},
	{FPDFDFDocSEL, FPDFDFDocGetFieldAttrTBSEL, L"FPDFDFDocGetFieldAttrTB"},
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
	{FPDObjectSEL, FPDObjectGetTypeSEL, L"FPDObjectGetType"},
	{FPDObjectSEL, FPDObjectGetobjNumSEL, L"FPDObjectGetobjNum"},
	{FPDObjectSEL, FPDObjectIsIdenticalSEL, L"FPDObjectIsIdentical"},
	{FPDObjectSEL, FPDObjectCloneSEL, L"FPDObjectClone"},
	{FPDObjectSEL, FPDObjectCloneRefToDocSEL, L"FPDObjectCloneRefToDoc"},
	{FPDObjectSEL, FPDObjectCloneRefToFDFDocSEL, L"FPDObjectCloneRefToFDFDoc"},
	{FPDObjectSEL, FPDObjectGetDirectSEL, L"FPDObjectGetDirect"},
	{FPDObjectSEL, FPDObjectDestroySEL, L"FPDObjectDestroy"},
	{FPDObjectSEL, FPDObjectGetStringSEL, L"FPDObjectGetString"},
	{FPDObjectSEL, FPDObjectGetUnicodeTextSEL, L"FPDObjectGetUnicodeText"},
	{FPDObjectSEL, FPDObjectGetNumberSEL, L"FPDObjectGetNumber"},
	{FPDObjectSEL, FPDObjectGetIntegerSEL, L"FPDObjectGetInteger"},
	{FPDObjectSEL, FPDObjectGetDictSEL, L"FPDObjectGetDict"},
	{FPDObjectSEL, FPDObjectGetArraySEL, L"FPDObjectGetArray"},
	{FPDObjectSEL, FPDObjectSetStringSEL, L"FPDObjectSetString"},
	{FPDObjectSEL, FPDObjectSetUnicodeTextSEL, L"FPDObjectSetUnicodeText"},
	{FPDObjectSEL, FPDObjectGetDirectTypeSEL, L"FPDObjectGetDirectType"},
	{FPDObjectSEL, FPDObjectIsModifiedSEL, L"FPDObjectIsModified"},
	{FPDObjectSEL, FPDObjectSetModifiedSEL, L"FPDObjectSetModified"},
	{FPDObjectSEL, FPDObjectGetContainerSEL, L"FPDObjectGetContainer"},
	{FPDObjectSEL, FPDObjectSetContainerSEL, L"FPDObjectSetContainer"},
	{FPDObjectSEL, FPDObjectParseStringSEL, L"FPDObjectParseString"},
	{FPDObjectSEL, FPDObjectGetConstStringSEL, L"FPDObjectGetConstString"},
	{FPDObjectSEL, FPDObjectIsNewCreatedSEL, L"FPDObjectIsNewCreated"},
	{FPDObjectSEL, FPDObjectGetUnicodeText2SEL, L"FPDObjectGetUnicodeText2"},
	{FPDObjectSEL, FPDObjectDeepCloneSEL, L"FPDObjectDeepClone"},
	{FPDObjectSEL, FPDObjectCreateClonePredicateHandlerSEL, L"FPDObjectCreateClonePredicateHandler"},
	{FPDObjectSEL, FPDObjectDestroyClonePredicateHandlerSEL, L"FPDObjectDestroyClonePredicateHandler"},
	{FPDBooleanSEL, FPDBooleanNewSEL, L"FPDBooleanNew"},
	{FPDBooleanSEL, FPDBooleanIdenticalSEL, L"FPDBooleanIdentical"},
	{FPDNumberSEL, FPDNumberNewByIntSEL, L"FPDNumberNewByInt"},
	{FPDNumberSEL, FPDNumberNewByFloatSEL, L"FPDNumberNewByFloat"},
	{FPDNumberSEL, FPDNumberNewByStrSEL, L"FPDNumberNewByStr"},
	{FPDNumberSEL, FPDNumberNewFromDataSEL, L"FPDNumberNewFromData"},
	{FPDNumberSEL, FPDNumberIdenticalSEL, L"FPDNumberIdentical"},
	{FPDNumberSEL, FPDNumberGetStringSEL, L"FPDNumberGetString"},
	{FPDNumberSEL, FPDNumberSetStringSEL, L"FPDNumberSetString"},
	{FPDNumberSEL, FPDNumberIsIntegerSEL, L"FPDNumberIsInteger"},
	{FPDNumberSEL, FPDNumberGetIntegerSEL, L"FPDNumberGetInteger"},
	{FPDNumberSEL, FPDNumberGetNumberSEL, L"FPDNumberGetNumber"},
	{FPDNumberSEL, FPDNumberSetNumberSEL, L"FPDNumberSetNumber"},
	{FPDNumberSEL, FPDNumberGetFloatSEL, L"FPDNumberGetFloat"},
	{FPDNumberSEL, FPDNumberNewByFloat2SEL, L"FPDNumberNewByFloat2"},
	{FPDStringSEL, FPDStringNewSEL, L"FPDStringNew"},
	{FPDStringSEL, FPDStringNewWSEL, L"FPDStringNewW"},
	{FPDStringSEL, FPDStringGetStringSEL, L"FPDStringGetString"},
	{FPDStringSEL, FPDStringIdenticalSEL, L"FPDStringIdentical"},
	{FPDStringSEL, FPDStringSetHexSEL, L"FPDStringSetHex"},
	{FPDStringSEL, FPDStringIsHexSEL, L"FPDStringIsHex"},
	{FPDNameSEL, FPDNameNewSEL, L"FPDNameNew"},
	{FPDNameSEL, FPDNameGetStringSEL, L"FPDNameGetString"},
	{FPDNameSEL, FPDNameIdenticalSEL, L"FPDNameIdentical"},
	{FPDArraySEL, FPDArrayNewSEL, L"FPDArrayNew"},
	{FPDArraySEL, FPDArrayGetCountSEL, L"FPDArrayGetCount"},
	{FPDArraySEL, FPDArrayGetElementSEL, L"FPDArrayGetElement"},
	{FPDArraySEL, FPDArrayGetElementValueSEL, L"FPDArrayGetElementValue"},
	{FPDArraySEL, FPDArrayGetMatrixSEL, L"FPDArrayGetMatrix"},
	{FPDArraySEL, FPDArrayGetRectSEL, L"FPDArrayGetRect"},
	{FPDArraySEL, FPDArrayGetStringSEL, L"FPDArrayGetString"},
	{FPDArraySEL, FPDArrayGetIntegerSEL, L"FPDArrayGetInteger"},
	{FPDArraySEL, FPDArrayGetNumberSEL, L"FPDArrayGetNumber"},
	{FPDArraySEL, FPDArrayGetDictSEL, L"FPDArrayGetDict"},
	{FPDArraySEL, FPDArrayGetStreamSEL, L"FPDArrayGetStream"},
	{FPDArraySEL, FPDArrayGetArraySEL, L"FPDArrayGetArray"},
	{FPDArraySEL, FPDArrayGetFloatSEL, L"FPDArrayGetFloat"},
	{FPDArraySEL, FPDArraySetAtSEL, L"FPDArraySetAt"},
	{FPDArraySEL, FPDArrayInsertAtSEL, L"FPDArrayInsertAt"},
	{FPDArraySEL, FPDArrayRemoveAtSEL, L"FPDArrayRemoveAt"},
	{FPDArraySEL, FPDArrayAddSEL, L"FPDArrayAdd"},
	{FPDArraySEL, FPDArrayAddNumberSEL, L"FPDArrayAddNumber"},
	{FPDArraySEL, FPDArrayAddIntegerSEL, L"FPDArrayAddInteger"},
	{FPDArraySEL, FPDArrayAddStringSEL, L"FPDArrayAddString"},
	{FPDArraySEL, FPDArrayAddNameSEL, L"FPDArrayAddName"},
	{FPDArraySEL, FPDArrayAddReferenceToDocSEL, L"FPDArrayAddReferenceToDoc"},
	{FPDArraySEL, FPDArrayAddReferenceToFDFDocSEL, L"FPDArrayAddReferenceToFDFDoc"},
	{FPDArraySEL, FPDArrayAddReference2ToDocSEL, L"FPDArrayAddReference2ToDoc"},
	{FPDArraySEL, FPDArrayAddReference2ToFDFDocSEL, L"FPDArrayAddReference2ToFDFDoc"},
	{FPDArraySEL, FPDArrayIsIdenticalSEL, L"FPDArrayIsIdentical"},
	{FPDArraySEL, FPDArrayRemoveAt2SEL, L"FPDArrayRemoveAt2"},
	{FPDArraySEL, FPDArrayAddNewSEL, L"FPDArrayAddNew"},
	{FPDArraySEL, FPDArrayReleaseSEL, L"FPDArrayRelease"},
	{FPDArraySEL, FPDArrayAdd2SEL, L"FPDArrayAdd2"},
	{FPDDictionarySEL, FPDDictionaryNewSEL, L"FPDDictionaryNew"},
	{FPDDictionarySEL, FPDDictionaryGetElementSEL, L"FPDDictionaryGetElement"},
	{FPDDictionarySEL, FPDDictionaryGetElementValueSEL, L"FPDDictionaryGetElementValue"},
	{FPDDictionarySEL, FPDDictionaryGetStringSEL, L"FPDDictionaryGetString"},
	{FPDDictionarySEL, FPDDictionaryGetUnicodeTextSEL, L"FPDDictionaryGetUnicodeText"},
	{FPDDictionarySEL, FPDDictionaryGetIntegerSEL, L"FPDDictionaryGetInteger"},
	{FPDDictionarySEL, FPDDictionaryGetInteger2SEL, L"FPDDictionaryGetInteger2"},
	{FPDDictionarySEL, FPDDictionaryGetBooleanSEL, L"FPDDictionaryGetBoolean"},
	{FPDDictionarySEL, FPDDictionaryGetNumberSEL, L"FPDDictionaryGetNumber"},
	{FPDDictionarySEL, FPDDictionaryGetDictSEL, L"FPDDictionaryGetDict"},
	{FPDDictionarySEL, FPDDictionaryGetStreamSEL, L"FPDDictionaryGetStream"},
	{FPDDictionarySEL, FPDDictionaryGetArraySEL, L"FPDDictionaryGetArray"},
	{FPDDictionarySEL, FPDDictionaryGetRectSEL, L"FPDDictionaryGetRect"},
	{FPDDictionarySEL, FPDDictionaryGetMatrixSEL, L"FPDDictionaryGetMatrix"},
	{FPDDictionarySEL, FPDDictionaryGetFloatSEL, L"FPDDictionaryGetFloat"},
	{FPDDictionarySEL, FPDDictionaryKeyExistSEL, L"FPDDictionaryKeyExist"},
	{FPDDictionarySEL, FPDDictionaryGetStartPositionSEL, L"FPDDictionaryGetStartPosition"},
	{FPDDictionarySEL, FPDDictionaryGetNextElementSEL, L"FPDDictionaryGetNextElement"},
	{FPDDictionarySEL, FPDDictionarySetAtSEL, L"FPDDictionarySetAt"},
	{FPDDictionarySEL, FPDDictionarySetAtNameSEL, L"FPDDictionarySetAtName"},
	{FPDDictionarySEL, FPDDictionarySetAtStringSEL, L"FPDDictionarySetAtString"},
	{FPDDictionarySEL, FPDDictionarySetAtIntegerSEL, L"FPDDictionarySetAtInteger"},
	{FPDDictionarySEL, FPDDictionarySetAtNumberSEL, L"FPDDictionarySetAtNumber"},
	{FPDDictionarySEL, FPDDictionarySetAtReferenceToDocSEL, L"FPDDictionarySetAtReferenceToDoc"},
	{FPDDictionarySEL, FPDDictionarySetAtReferenceToFDFDocSEL, L"FPDDictionarySetAtReferenceToFDFDoc"},
	{FPDDictionarySEL, FPDDictionarySetAtReference2ToDocSEL, L"FPDDictionarySetAtReference2ToDoc"},
	{FPDDictionarySEL, FPDDictionarySetAtReference2ToFDFDocSEL, L"FPDDictionarySetAtReference2ToFDFDoc"},
	{FPDDictionarySEL, FPDDictionarySetAtRectSEL, L"FPDDictionarySetAtRect"},
	{FPDDictionarySEL, FPDDictionarySetAtMatrixSEL, L"FPDDictionarySetAtMatrix"},
	{FPDDictionarySEL, FPDDictionarySetAtBooleanSEL, L"FPDDictionarySetAtBoolean"},
	{FPDDictionarySEL, FPDDictionaryRemoveAtSEL, L"FPDDictionaryRemoveAt"},
	{FPDDictionarySEL, FPDDictionaryReplaceKeySEL, L"FPDDictionaryReplaceKey"},
	{FPDDictionarySEL, FPDDictionaryIdenticalSEL, L"FPDDictionaryIdentical"},
	{FPDDictionarySEL, FPDDictionaryGetCountSEL, L"FPDDictionaryGetCount"},
	{FPDDictionarySEL, FPDDictionaryAddValueSEL, L"FPDDictionaryAddValue"},
	{FPDDictionarySEL, FPDDictionaryGetBoolean2SEL, L"FPDDictionaryGetBoolean2"},
	{FPDDictionarySEL, FPDDictionarySetAtName2SEL, L"FPDDictionarySetAtName2"},
	{FPDDictionarySEL, FPDDictionarySetNewAtSEL, L"FPDDictionarySetNewAt"},
	{FPDDictionarySEL, FPDDictionaryAddReferenceSEL, L"FPDDictionaryAddReference"},
	{FPDDictionarySEL, FPDDictionaryGetString2SEL, L"FPDDictionaryGetString2"},
	{FPDDictionarySEL, FPDDictionaryReleaseSEL, L"FPDDictionaryRelease"},
	{FPDDictionarySEL, FPDDictionarySetAtString2SEL, L"FPDDictionarySetAtString2"},
	{FPDDictionarySEL, FPDDictionaryMoveDataSEL, L"FPDDictionaryMoveData"},
	{FPDDictionarySEL, FPDDictionarySetAt2SEL, L"FPDDictionarySetAt2"},
	{FPDDictionarySEL, FPDDictionaryRemoveAt2SEL, L"FPDDictionaryRemoveAt2"},
	{FPDDictionarySEL, FPDDictionaryAddReference2SEL, L"FPDDictionaryAddReference2"},
	{FPDDictionarySEL, FPDDictionaryAddReference3SEL, L"FPDDictionaryAddReference3"},
	{FPDDictionarySEL, FPDDictionaryAddReference4SEL, L"FPDDictionaryAddReference4"},
	{FPDDictionarySEL, FPDDictionaryGetNameSEL, L"FPDDictionaryGetName"},
	{FPDDictionarySEL, FPDDictionaryGetInteger64SEL, L"FPDDictionaryGetInteger64"},
	{FPDDictionarySEL, FPDDictionaryGetInteger64ByDefaultSEL, L"FPDDictionaryGetInteger64ByDefault"},
	{FPDDictionarySEL, FPDDictionarySetAt3SEL, L"FPDDictionarySetAt3"},
	{FPDStreamSEL, FPDStreamNewSEL, L"FPDStreamNew"},
	{FPDStreamSEL, FPDStreamInitStreamSEL, L"FPDStreamInitStream"},
	{FPDStreamSEL, FPDStreamGetDictSEL, L"FPDStreamGetDict"},
	{FPDStreamSEL, FPDStreamSetDataSEL, L"FPDStreamSetData"},
	{FPDStreamSEL, FPDStreamIdenticalSEL, L"FPDStreamIdentical"},
	{FPDStreamSEL, FPDStreamGetStreamFilterSEL, L"FPDStreamGetStreamFilter"},
	{FPDStreamSEL, FPDStreamGetRawSizeSEL, L"FPDStreamGetRawSize"},
	{FPDStreamSEL, FPDStreamReadRawDataSEL, L"FPDStreamReadRawData"},
	{FPDStreamSEL, FPDStreamIsMemoryBasedSEL, L"FPDStreamIsMemoryBased"},
	{FPDStreamSEL, FPDStreamCloneSEL, L"FPDStreamClone"},
	{FPDStreamSEL, FPDStreamCreateSEL, L"FPDStreamCreate"},
	{FPDStreamSEL, FPDStreamNew2SEL, L"FPDStreamNew2"},
	{FPDStreamSEL, FPDStreamSetStreamFileSEL, L"FPDStreamSetStreamFile"},
	{FPDStreamSEL, FPDStreamDecryptStreamSEL, L"FPDStreamDecryptStream"},
	{FPDStreamAccSEL, FPDStreamAccNewSEL, L"FPDStreamAccNew"},
	{FPDStreamAccSEL, FPDStreamAccDestroySEL, L"FPDStreamAccDestroy"},
	{FPDStreamAccSEL, FPDStreamAccLoadAllDataSEL, L"FPDStreamAccLoadAllData"},
	{FPDStreamAccSEL, FPDStreamAccGetStreamSEL, L"FPDStreamAccGetStream"},
	{FPDStreamAccSEL, FPDStreamAccGetDictSEL, L"FPDStreamAccGetDict"},
	{FPDStreamAccSEL, FPDStreamAccGetDataSEL, L"FPDStreamAccGetData"},
	{FPDStreamAccSEL, FPDStreamAccGetSizeSEL, L"FPDStreamAccGetSize"},
	{FPDStreamAccSEL, FPDStreamAccDetachDataSEL, L"FPDStreamAccDetachData"},
	{FPDStreamAccSEL, FPDStreamAccGetImageDecoderSEL, L"FPDStreamAccGetImageDecoder"},
	{FPDStreamAccSEL, FPDStreamAccGetImageParamSEL, L"FPDStreamAccGetImageParam"},
	{FPDStreamFilterSEL, FPDStreamFilterDestroySEL, L"FPDStreamFilterDestroy"},
	{FPDStreamFilterSEL, FPDStreamFilterReadBlockSEL, L"FPDStreamFilterReadBlock"},
	{FPDStreamFilterSEL, FPDStreamFilterGetSrcPosSEL, L"FPDStreamFilterGetSrcPos"},
	{FPDStreamFilterSEL, FPDStreamFilterGetStreamSEL, L"FPDStreamFilterGetStream"},
	{FPDNullSEL, FPDNullNewSEL, L"FPDNullNew"},
	{FPDReferenceSEL, FPDReferenceNewSEL, L"FPDReferenceNew"},
	{FPDReferenceSEL, FPDReferenceNew2SEL, L"FPDReferenceNew2"},
	{FPDReferenceSEL, FPDReferenceGetRefObjNumSEL, L"FPDReferenceGetRefObjNum"},
	{FPDReferenceSEL, FPDReferenceSetRefToDocSEL, L"FPDReferenceSetRefToDoc"},
	{FPDReferenceSEL, FPDReferenceSetRefToFDFDocSEL, L"FPDReferenceSetRefToFDFDoc"},
	{FPDReferenceSEL, FPDReferenceIdenticalSEL, L"FPDReferenceIdentical"},
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
	{FPDPageSEL, FPDPageNewSEL, L"FPDPageNew"},
	{FPDPageSEL, FPDPageDestroySEL, L"FPDPageDestroy"},
	{FPDPageSEL, FPDPageContinueParseSEL, L"FPDPageContinueParse"},
	{FPDPageSEL, FPDPageGetParseStateSEL, L"FPDPageGetParseState"},
	{FPDPageSEL, FPDPageIsParsedSEL, L"FPDPageIsParsed"},
	{FPDPageSEL, FPDPageEstimateParseProgressSEL, L"FPDPageEstimateParseProgress"},
	{FPDPageSEL, FPDPageGetFirstObjectPositionSEL, L"FPDPageGetFirstObjectPosition"},
	{FPDPageSEL, FPDPageGetLastObjectPositionSEL, L"FPDPageGetLastObjectPosition"},
	{FPDPageSEL, FPDPageGetNextObjectSEL, L"FPDPageGetNextObject"},
	{FPDPageSEL, FPDPageGetPrevObjectSEL, L"FPDPageGetPrevObject"},
	{FPDPageSEL, FPDPageGetObjectAtSEL, L"FPDPageGetObjectAt"},
	{FPDPageSEL, FPDPageCountObjectsSEL, L"FPDPageCountObjects"},
	{FPDPageSEL, FPDPageGetObjectIndexSEL, L"FPDPageGetObjectIndex"},
	{FPDPageSEL, FPDPageGetObjectByIndexSEL, L"FPDPageGetObjectByIndex"},
	{FPDPageSEL, FPDPageReplaceObjectSEL, L"FPDPageReplaceObject"},
	{FPDPageSEL, FPDPageInsertObjectSEL, L"FPDPageInsertObject"},
	{FPDPageSEL, FPDPageRemoveObjectSEL, L"FPDPageRemoveObject"},
	{FPDPageSEL, FPDPageMoveObjectSEL, L"FPDPageMoveObject"},
	{FPDPageSEL, FPDPageDebugOutputSEL, L"FPDPageDebugOutput"},
	{FPDPageSEL, FPDPageTransformSEL, L"FPDPageTransform"},
	{FPDPageSEL, FPDPageBackgroundAlphaNeededSEL, L"FPDPageBackgroundAlphaNeeded"},
	{FPDPageSEL, FPDPageCalcBoundingBoxSEL, L"FPDPageCalcBoundingBox"},
	{FPDPageSEL, FPDPageGetDictSEL, L"FPDPageGetDict"},
	{FPDPageSEL, FPDPageGetDocumentSEL, L"FPDPageGetDocument"},
	{FPDPageSEL, FPDPageRealizeResourceSEL, L"FPDPageRealizeResource"},
	{FPDPageSEL, FPDPageFindCSNameSEL, L"FPDPageFindCSName"},
	{FPDPageSEL, FPDPageFindFontNameSEL, L"FPDPageFindFontName"},
	{FPDPageSEL, FPDPageLoadSEL, L"FPDPageLoad"},
	{FPDPageSEL, FPDPageStartParseSEL, L"FPDPageStartParse"},
	{FPDPageSEL, FPDPageParseContentSEL, L"FPDPageParseContent"},
	{FPDPageSEL, FPDPageGetDisplayMatrixSEL, L"FPDPageGetDisplayMatrix"},
	{FPDPageSEL, FPDPageGetPageWidthSEL, L"FPDPageGetPageWidth"},
	{FPDPageSEL, FPDPageGetPageHeightSEL, L"FPDPageGetPageHeight"},
	{FPDPageSEL, FPDPageGetPageBBoxSEL, L"FPDPageGetPageBBox"},
	{FPDPageSEL, FPDPageGetPageMatrixSEL, L"FPDPageGetPageMatrix"},
	{FPDPageSEL, FPDPageGetPageAttrSEL, L"FPDPageGetPageAttr"},
	{FPDPageSEL, FPDPageGetRenderCacheSEL, L"FPDPageGetRenderCache"},
	{FPDPageSEL, FPDPageClearRenderCacheSEL, L"FPDPageClearRenderCache"},
	{FPDPageSEL, FPDPageGenerateContentSEL, L"FPDPageGenerateContent"},
	{FPDPageSEL, FPDPageGetPageTextSEL, L"FPDPageGetPageText"},
	{FPDPageSEL, FPDPageGetPageText_UnicodeSEL, L"FPDPageGetPageText_Unicode"},
	{FPDPageSEL, FPDPageNewContentGeneratorSEL, L"FPDPageNewContentGenerator"},
	{FPDPageSEL, FPDPageDestroyContentGeneratorSEL, L"FPDPageDestroyContentGenerator"},
	{FPDPageSEL, FPDPageStartGenerateContentSEL, L"FPDPageStartGenerateContent"},
	{FPDPageSEL, FPDPageContinueGenerateContentSEL, L"FPDPageContinueGenerateContent"},
	{FPDPageSEL, FPDPageGetResourcesDictionarySEL, L"FPDPageGetResourcesDictionary"},
	{FPDPageSEL, FPDPageSetResourcesDictionarySEL, L"FPDPageSetResourcesDictionary"},
	{FPDPageSEL, FPDPageStartGenerateContent2SEL, L"FPDPageStartGenerateContent2"},
	{FPDPageSEL, FPDPageGetPageRotationSEL, L"FPDPageGetPageRotation"},
	{FPDPageSEL, FPDPageGetPageResourcesSEL, L"FPDPageGetPageResources"},
	{FPDPageSEL, FPDPageGetPageBleedBoxSEL, L"FPDPageGetPageBleedBox"},
	{FPDPageSEL, FPDPageNew2SEL, L"FPDPageNew2"},
	{FPDPageSEL, FPDPageSetFormStreamSEL, L"FPDPageSetFormStream"},
	{FPDPageSEL, FPDPageSetFormDictSEL, L"FPDPageSetFormDict"},
	{FPDPageSEL, FPDPageCastToFPDGraphicsObjectsSEL, L"FPDPageCastToFPDGraphicsObjects"},
	{FPDPageSEL, FPDPageGenerateContent2SEL, L"FPDPageGenerateContent2"},
	{FPDParseOptionsSEL, FPDParseOptionsNewSEL, L"FPDParseOptionsNew"},
	{FPDParseOptionsSEL, FPDParseOptionsDestroySEL, L"FPDParseOptionsDestroy"},
	{FPDParseOptionsSEL, FPDParseOptionsSetTextFlagSEL, L"FPDParseOptionsSetTextFlag"},
	{FPDParseOptionsSEL, FPDParseOptionsSetMarkedContentLoadFlagSEL, L"FPDParseOptionsSetMarkedContentLoadFlag"},
	{FPDParseOptionsSEL, FPDParseOptionsSetFormGenerateFlagSEL, L"FPDParseOptionsSetFormGenerateFlag"},
	{FPDParseOptionsSEL, FPDParseOptionsSetInlineImageDecodeFlagSEL, L"FPDParseOptionsSetInlineImageDecodeFlag"},
	{FPDFormSEL, FPDFormNewSEL, L"FPDFormNew"},
	{FPDFormSEL, FPDFormDestroySEL, L"FPDFormDestroy"},
	{FPDFormSEL, FPDFormContinueParseSEL, L"FPDFormContinueParse"},
	{FPDFormSEL, FPDFormGetParseStateSEL, L"FPDFormGetParseState"},
	{FPDFormSEL, FPDFormIsParsedSEL, L"FPDFormIsParsed"},
	{FPDFormSEL, FPDFormEstimateParseProgressSEL, L"FPDFormEstimateParseProgress"},
	{FPDFormSEL, FPDFormGetFirstObjectPositionSEL, L"FPDFormGetFirstObjectPosition"},
	{FPDFormSEL, FPDFormGetLastObjectPositionSEL, L"FPDFormGetLastObjectPosition"},
	{FPDFormSEL, FPDFormGetNextObjectSEL, L"FPDFormGetNextObject"},
	{FPDFormSEL, FPDFormGetPrevObjectSEL, L"FPDFormGetPrevObject"},
	{FPDFormSEL, FPDFormGetObjectAtSEL, L"FPDFormGetObjectAt"},
	{FPDFormSEL, FPDFormCountObjectsSEL, L"FPDFormCountObjects"},
	{FPDFormSEL, FPDFormGetObjectIndexSEL, L"FPDFormGetObjectIndex"},
	{FPDFormSEL, FPDFormGetObjectByIndexSEL, L"FPDFormGetObjectByIndex"},
	{FPDFormSEL, FPDFormReplaceObjectSEL, L"FPDFormReplaceObject"},
	{FPDFormSEL, FPDFormInsertObjectSEL, L"FPDFormInsertObject"},
	{FPDFormSEL, FPDFormRemoveObjectSEL, L"FPDFormRemoveObject"},
	{FPDFormSEL, FPDFormMoveObjectSEL, L"FPDFormMoveObject"},
	{FPDFormSEL, FPDFormDebugOutputSEL, L"FPDFormDebugOutput"},
	{FPDFormSEL, FPDFormTransformSEL, L"FPDFormTransform"},
	{FPDFormSEL, FPDFormBackgroundAlphaNeededSEL, L"FPDFormBackgroundAlphaNeeded"},
	{FPDFormSEL, FPDFormCalcBoundingBoxSEL, L"FPDFormCalcBoundingBox"},
	{FPDFormSEL, FPDFormGetDictSEL, L"FPDFormGetDict"},
	{FPDFormSEL, FPDFormGetDocumentSEL, L"FPDFormGetDocument"},
	{FPDFormSEL, FPDFormRealizeResourceSEL, L"FPDFormRealizeResource"},
	{FPDFormSEL, FPDFormFindCSNameSEL, L"FPDFormFindCSName"},
	{FPDFormSEL, FPDFormFindFontNameSEL, L"FPDFormFindFontName"},
	{FPDFormSEL, FPDFormGetFormStreamSEL, L"FPDFormGetFormStream"},
	{FPDFormSEL, FPDFormStartParseSEL, L"FPDFormStartParse"},
	{FPDFormSEL, FPDFormParseContentSEL, L"FPDFormParseContent"},
	{FPDFormSEL, FPDFormCloneSEL, L"FPDFormClone"},
	{FPDFormSEL, FPDFormGenerateContentSEL, L"FPDFormGenerateContent"},
	{FPDFormSEL, FPDFormNewContentGeneratorSEL, L"FPDFormNewContentGenerator"},
	{FPDFormSEL, FPDFormDestroyContentGeneratorSEL, L"FPDFormDestroyContentGenerator"},
	{FPDFormSEL, FPDFormStartGenerateContentSEL, L"FPDFormStartGenerateContent"},
	{FPDFormSEL, FPDFormContinueGenerateContentSEL, L"FPDFormContinueGenerateContent"},
	{FPDFormSEL, FPDFormGetResourcesDictionarySEL, L"FPDFormGetResourcesDictionary"},
	{FPDFormSEL, FPDFormSetResourcesDictionarySEL, L"FPDFormSetResourcesDictionary"},
	{FPDFormSEL, FPDFormSetFormStreamSEL, L"FPDFormSetFormStream"},
	{FPDFormSEL, FPDFormSetFormDictSEL, L"FPDFormSetFormDict"},
	{FPDFormSEL, FPDFormCastToFPDGraphicsObjectsSEL, L"FPDFormCastToFPDGraphicsObjects"},
	{FPDFormSEL, FPDFormStartGenerateContent2SEL, L"FPDFormStartGenerateContent2"},
	{FPDFormSEL, FPDFormGenerateContent2SEL, L"FPDFormGenerateContent2"},
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
	{FPDPathSEL, FPDPathNewSEL, L"FPDPathNew"},
	{FPDPathSEL, FPDPathDestroySEL, L"FPDPathDestroy"},
	{FPDPathSEL, FPDPathGetPointCountSEL, L"FPDPathGetPointCount"},
	{FPDPathSEL, FPDPathGetFlagSEL, L"FPDPathGetFlag"},
	{FPDPathSEL, FPDPathGetPointXSEL, L"FPDPathGetPointX"},
	{FPDPathSEL, FPDPathGetPointYSEL, L"FPDPathGetPointY"},
	{FPDPathSEL, FPDPathGetPointSEL, L"FPDPathGetPoint"},
	{FPDPathSEL, FPDPathGetBoundingBoxSEL, L"FPDPathGetBoundingBox"},
	{FPDPathSEL, FPDPathGetBoundingBox2SEL, L"FPDPathGetBoundingBox2"},
	{FPDPathSEL, FPDPathTransformSEL, L"FPDPathTransform"},
	{FPDPathSEL, FPDPathAppendSEL, L"FPDPathAppend"},
	{FPDPathSEL, FPDPathAppendRectSEL, L"FPDPathAppendRect"},
	{FPDPathSEL, FPDPathIsRectSEL, L"FPDPathIsRect"},
	{FPDPathSEL, FPDPathSetPointCountSEL, L"FPDPathSetPointCount"},
	{FPDPathSEL, FPDPathSetPointSEL, L"FPDPathSetPoint"},
	{FPDPathSEL, FPDPathGetModifySEL, L"FPDPathGetModify"},
	{FPDPathSEL, FPDPathTrimPointsSEL, L"FPDPathTrimPoints"},
	{FPDPathSEL, FPDPathTransformPathDataSEL, L"FPDPathTransformPathData"},
	{FPDPathSEL, FPDPathCopySEL, L"FPDPathCopy"},
	{FPDPathSEL, FPDPathAddPointCountSEL, L"FPDPathAddPointCount"},
	{FPDClipPathSEL, FPDClipPathNewSEL, L"FPDClipPathNew"},
	{FPDClipPathSEL, FPDClipPathDestroySEL, L"FPDClipPathDestroy"},
	{FPDClipPathSEL, FPDClipPathAppendPathSEL, L"FPDClipPathAppendPath"},
	{FPDClipPathSEL, FPDClipPathDeletePathSEL, L"FPDClipPathDeletePath"},
	{FPDClipPathSEL, FPDClipPathGetPathCountSEL, L"FPDClipPathGetPathCount"},
	{FPDClipPathSEL, FPDClipPathTransformSEL, L"FPDClipPathTransform"},
	{FPDClipPathSEL, FPDClipPathGetPathSEL, L"FPDClipPathGetPath"},
	{FPDClipPathSEL, FPDClipPathGetClipTypeSEL, L"FPDClipPathGetClipType"},
	{FPDClipPathSEL, FPDClipPathGetTextCountSEL, L"FPDClipPathGetTextCount"},
	{FPDClipPathSEL, FPDClipPathGetClipBoxSEL, L"FPDClipPathGetClipBox"},
	{FPDClipPathSEL, FPDClipPathGetTextSEL, L"FPDClipPathGetText"},
	{FPDClipPathSEL, FPDClipPathAppendTextsSEL, L"FPDClipPathAppendTexts"},
	{FPDClipPathSEL, FPDClipPathSetCountSEL, L"FPDClipPathSetCount"},
	{FPDClipPathSEL, FPDClipPathIsNullSEL, L"FPDClipPathIsNull"},
	{FPDClipPathSEL, FPDClipPathGetModifySEL, L"FPDClipPathGetModify"},
	{FPDClipPathSEL, FPDClipPathGetPathPointerSEL, L"FPDClipPathGetPathPointer"},
	{FPDClipPathSEL, FPDClipPathCopySEL, L"FPDClipPathCopy"},
	{FPDColorStateSEL, FPDColorStateNewSEL, L"FPDColorStateNew"},
	{FPDColorStateSEL, FPDColorStateDestroySEL, L"FPDColorStateDestroy"},
	{FPDColorStateSEL, FPDColorStateGetFillColorSEL, L"FPDColorStateGetFillColor"},
	{FPDColorStateSEL, FPDColorStateGetStrokeColorSEL, L"FPDColorStateGetStrokeColor"},
	{FPDColorStateSEL, FPDColorStateSetFillColorSEL, L"FPDColorStateSetFillColor"},
	{FPDColorStateSEL, FPDColorStateSetStrokeColorSEL, L"FPDColorStateSetStrokeColor"},
	{FPDColorStateSEL, FPDColorStateSetFillPatternColorSEL, L"FPDColorStateSetFillPatternColor"},
	{FPDColorStateSEL, FPDColorStateSetStrokePatternColorSEL, L"FPDColorStateSetStrokePatternColor"},
	{FPDColorStateSEL, FPDColorStateIsNullSEL, L"FPDColorStateIsNull"},
	{FPDColorStateSEL, FPDColorStateGetModifySEL, L"FPDColorStateGetModify"},
	{FPDColorStateSEL, FPDColorStateNotUseFillColorSEL, L"FPDColorStateNotUseFillColor"},
	{FPDColorStateSEL, FPDColorStateCopySEL, L"FPDColorStateCopy"},
	{FPDTextStateSEL, FPDTextStateNewSEL, L"FPDTextStateNew"},
	{FPDTextStateSEL, FPDTextStateDestroySEL, L"FPDTextStateDestroy"},
	{FPDTextStateSEL, FPDTextStateGetFontSEL, L"FPDTextStateGetFont"},
	{FPDTextStateSEL, FPDTextStateSetFontSEL, L"FPDTextStateSetFont"},
	{FPDTextStateSEL, FPDTextStateGetFontSizeSEL, L"FPDTextStateGetFontSize"},
	{FPDTextStateSEL, FPDTextStateGetMatrixSEL, L"FPDTextStateGetMatrix"},
	{FPDTextStateSEL, FPDTextStateGetFontSizeVSEL, L"FPDTextStateGetFontSizeV"},
	{FPDTextStateSEL, FPDTextStateGetFontSizeHSEL, L"FPDTextStateGetFontSizeH"},
	{FPDTextStateSEL, FPDTextStateGetBaselineAngleSEL, L"FPDTextStateGetBaselineAngle"},
	{FPDTextStateSEL, FPDTextStateGetShearAngleSEL, L"FPDTextStateGetShearAngle"},
	{FPDTextStateSEL, FPDTextStateSetFontSizeSEL, L"FPDTextStateSetFontSize"},
	{FPDTextStateSEL, FPDTextStateSetCharSpaceSEL, L"FPDTextStateSetCharSpace"},
	{FPDTextStateSEL, FPDTextStateSetWordSpaceSEL, L"FPDTextStateSetWordSpace"},
	{FPDTextStateSEL, FPDTextStateSetMatrixSEL, L"FPDTextStateSetMatrix"},
	{FPDTextStateSEL, FPDTextStateSetTextModeSEL, L"FPDTextStateSetTextMode"},
	{FPDTextStateSEL, FPDTextStateSetTextCTMSEL, L"FPDTextStateSetTextCTM"},
	{FPDTextStateSEL, FPDTextStateGetTextModeSEL, L"FPDTextStateGetTextMode"},
	{FPDTextStateSEL, FPDTextStateGetTextCTMSEL, L"FPDTextStateGetTextCTM"},
	{FPDTextStateSEL, FPDTextStateGetCharSpaceSEL, L"FPDTextStateGetCharSpace"},
	{FPDTextStateSEL, FPDTextStateGetWordSpaceSEL, L"FPDTextStateGetWordSpace"},
	{FPDTextStateSEL, FPDTextStateIsNullSEL, L"FPDTextStateIsNull"},
	{FPDTextStateSEL, FPDTextStateGetModifySEL, L"FPDTextStateGetModify"},
	{FPDGeneralStateSEL, FPDGeneralStateNewSEL, L"FPDGeneralStateNew"},
	{FPDGeneralStateSEL, FPDGeneralStateDestroySEL, L"FPDGeneralStateDestroy"},
	{FPDGeneralStateSEL, FPDGeneralStateSetRenderIntentSEL, L"FPDGeneralStateSetRenderIntent"},
	{FPDGeneralStateSEL, FPDGeneralStateGetBlendTypeSEL, L"FPDGeneralStateGetBlendType"},
	{FPDGeneralStateSEL, FPDGeneralStateGetAlphaSEL, L"FPDGeneralStateGetAlpha"},
	{FPDGeneralStateSEL, FPDGeneralStateSetBlendModeSEL, L"FPDGeneralStateSetBlendMode"},
	{FPDGeneralStateSEL, FPDGeneralStateSetBlendTypeSEL, L"FPDGeneralStateSetBlendType"},
	{FPDGeneralStateSEL, FPDGeneralStateSetSoftMaskSEL, L"FPDGeneralStateSetSoftMask"},
	{FPDGeneralStateSEL, FPDGeneralStateSetSoftMaskMatrixSEL, L"FPDGeneralStateSetSoftMaskMatrix"},
	{FPDGeneralStateSEL, FPDGeneralStateSetStrokeAlphaSEL, L"FPDGeneralStateSetStrokeAlpha"},
	{FPDGeneralStateSEL, FPDGeneralStateSetFillAlphaSEL, L"FPDGeneralStateSetFillAlpha"},
	{FPDGeneralStateSEL, FPDGeneralStateIsNullSEL, L"FPDGeneralStateIsNull"},
	{FPDGeneralStateSEL, FPDGeneralStateGetModifySEL, L"FPDGeneralStateGetModify"},
	{FPDGraphStateSEL, FPDGraphStateNewSEL, L"FPDGraphStateNew"},
	{FPDGraphStateSEL, FPDGraphStateDestroySEL, L"FPDGraphStateDestroy"},
	{FPDGraphStateSEL, FPDGraphStateSetDashCountSEL, L"FPDGraphStateSetDashCount"},
	{FPDGraphStateSEL, FPDGraphStateGetDashCountSEL, L"FPDGraphStateGetDashCount"},
	{FPDGraphStateSEL, FPDGraphStateGetDashArraySEL, L"FPDGraphStateGetDashArray"},
	{FPDGraphStateSEL, FPDGraphStateGetDashPhaseSEL, L"FPDGraphStateGetDashPhase"},
	{FPDGraphStateSEL, FPDGraphStateSetDashPhaseSEL, L"FPDGraphStateSetDashPhase"},
	{FPDGraphStateSEL, FPDGraphStateGetLineCapSEL, L"FPDGraphStateGetLineCap"},
	{FPDGraphStateSEL, FPDGraphStateSetLineCapSEL, L"FPDGraphStateSetLineCap"},
	{FPDGraphStateSEL, FPDGraphStateGetLineJoinSEL, L"FPDGraphStateGetLineJoin"},
	{FPDGraphStateSEL, FPDGraphStateSetLineJoinSEL, L"FPDGraphStateSetLineJoin"},
	{FPDGraphStateSEL, FPDGraphStateGetMiterLimitSEL, L"FPDGraphStateGetMiterLimit"},
	{FPDGraphStateSEL, FPDGraphStateSetMiterLimitSEL, L"FPDGraphStateSetMiterLimit"},
	{FPDGraphStateSEL, FPDGraphStateGetLineWidthSEL, L"FPDGraphStateGetLineWidth"},
	{FPDGraphStateSEL, FPDGraphStateSetLineWidthSEL, L"FPDGraphStateSetLineWidth"},
	{FPDGraphStateSEL, FPDGraphStateIsNullSEL, L"FPDGraphStateIsNull"},
	{FPDGraphStateSEL, FPDGraphStateGetModifySEL, L"FPDGraphStateGetModify"},
	{FPDGraphStateSEL, FPDGraphStateSetDashArraySEL, L"FPDGraphStateSetDashArray"},
	{FPDPageObjectSEL, FPDPageObjectNewSEL, L"FPDPageObjectNew"},
	{FPDPageObjectSEL, FPDPageObjectDestroySEL, L"FPDPageObjectDestroy"},
	{FPDPageObjectSEL, FPDPageObjectCloneSEL, L"FPDPageObjectClone"},
	{FPDPageObjectSEL, FPDPageObjectCopySEL, L"FPDPageObjectCopy"},
	{FPDPageObjectSEL, FPDPageObjectRemoveClipPathSEL, L"FPDPageObjectRemoveClipPath"},
	{FPDPageObjectSEL, FPDPageObjectAppendClipPathSEL, L"FPDPageObjectAppendClipPath"},
	{FPDPageObjectSEL, FPDPageObjectCopyClipPathSEL, L"FPDPageObjectCopyClipPath"},
	{FPDPageObjectSEL, FPDPageObjectTransformClipPathSEL, L"FPDPageObjectTransformClipPath"},
	{FPDPageObjectSEL, FPDPageObjectSetColorStateSEL, L"FPDPageObjectSetColorState"},
	{FPDPageObjectSEL, FPDPageObjectGetBBoxSEL, L"FPDPageObjectGetBBox"},
	{FPDPageObjectSEL, FPDPageObjectGetOriginalBBoxSEL, L"FPDPageObjectGetOriginalBBox"},
	{FPDPageObjectSEL, FPDPageObjectGetTypeSEL, L"FPDPageObjectGetType"},
	{FPDPageObjectSEL, FPDPageObjectGetClipPathSEL, L"FPDPageObjectGetClipPath"},
	{FPDPageObjectSEL, FPDPageObjectGetGraphStateSEL, L"FPDPageObjectGetGraphState"},
	{FPDPageObjectSEL, FPDPageObjectGetColorStateSEL, L"FPDPageObjectGetColorState"},
	{FPDPageObjectSEL, FPDPageObjectGetTextStateSEL, L"FPDPageObjectGetTextState"},
	{FPDPageObjectSEL, FPDPageObjectGetGeneralStateSEL, L"FPDPageObjectGetGeneralState"},
	{FPDPageObjectSEL, FPDPageObjectGetContentMarkSEL, L"FPDPageObjectGetContentMark"},
	{FPDPageObjectSEL, FPDPageObjectDefaultStatesSEL, L"FPDPageObjectDefaultStates"},
	{FPDPageObjectSEL, FPDPageObjectCopyStatesSEL, L"FPDPageObjectCopyStates"},
	{FPDPageObjectSEL, FPDPageObjectSetGraphStateSEL, L"FPDPageObjectSetGraphState"},
	{FPDPageObjectSEL, FPDPageObjectSetTextStateSEL, L"FPDPageObjectSetTextState"},
	{FPDPageObjectSEL, FPDPageObjectSetGeneralStateSEL, L"FPDPageObjectSetGeneralState"},
	{FPDPageObjectSEL, FPDPageObjectHasClipPathSEL, L"FPDPageObjectHasClipPath"},
	{FPDPageObjectSEL, FPDPageObjectGetContentMark2SEL, L"FPDPageObjectGetContentMark2"},
	{FPDPageObjectSEL, FPDPageObjectTransformGeneralStateSEL, L"FPDPageObjectTransformGeneralState"},
	{FPDPageObjectSEL, FPDPageObjectTransformSEL, L"FPDPageObjectTransform"},
	{FPDPageObjectSEL, FPDPageObjectCastToFormObjectSEL, L"FPDPageObjectCastToFormObject"},
	{FPDPageObjectSEL, FPDPageObjectSetContentMarkSEL, L"FPDPageObjectSetContentMark"},
	{FPDPageObjectSEL, FPDPageObjectGetClipPath2SEL, L"FPDPageObjectGetClipPath2"},
	{FPDPageObjectSEL, FPDPageObjectGetColorState2SEL, L"FPDPageObjectGetColorState2"},
	{FPDPageObjectSEL, FPDPageObjectClone2SEL, L"FPDPageObjectClone2"},
	{FPDTextObjectSEL, FPDTextObjectNewSEL, L"FPDTextObjectNew"},
	{FPDTextObjectSEL, FPDTextObjectDestroySEL, L"FPDTextObjectDestroy"},
	{FPDTextObjectSEL, FPDTextObjectCountItemsSEL, L"FPDTextObjectCountItems"},
	{FPDTextObjectSEL, FPDTextObjectGetItemInfoSEL, L"FPDTextObjectGetItemInfo"},
	{FPDTextObjectSEL, FPDTextObjectCountCharsSEL, L"FPDTextObjectCountChars"},
	{FPDTextObjectSEL, FPDTextObjectGetCharInfoSEL, L"FPDTextObjectGetCharInfo"},
	{FPDTextObjectSEL, FPDTextObjectGetPosXSEL, L"FPDTextObjectGetPosX"},
	{FPDTextObjectSEL, FPDTextObjectGetPosYSEL, L"FPDTextObjectGetPosY"},
	{FPDTextObjectSEL, FPDTextObjectGetTextMatrixSEL, L"FPDTextObjectGetTextMatrix"},
	{FPDTextObjectSEL, FPDTextObjectGetFontSEL, L"FPDTextObjectGetFont"},
	{FPDTextObjectSEL, FPDTextObjectGetFontSizeSEL, L"FPDTextObjectGetFontSize"},
	{FPDTextObjectSEL, FPDTextObjectSetEmptySEL, L"FPDTextObjectSetEmpty"},
	{FPDTextObjectSEL, FPDTextObjectSetTextSEL, L"FPDTextObjectSetText"},
	{FPDTextObjectSEL, FPDTextObjectSetText2SEL, L"FPDTextObjectSetText2"},
	{FPDTextObjectSEL, FPDTextObjectSetText3SEL, L"FPDTextObjectSetText3"},
	{FPDTextObjectSEL, FPDTextObjectSetPositionSEL, L"FPDTextObjectSetPosition"},
	{FPDTextObjectSEL, FPDTextObjectSetTextStateSEL, L"FPDTextObjectSetTextState"},
	{FPDTextObjectSEL, FPDTextObjectTransformSEL, L"FPDTextObjectTransform"},
	{FPDTextObjectSEL, FPDTextObjectCalcCharPosSEL, L"FPDTextObjectCalcCharPos"},
	{FPDTextObjectSEL, FPDTextObjectSetDataSEL, L"FPDTextObjectSetData"},
	{FPDTextObjectSEL, FPDTextObjectGetDataSEL, L"FPDTextObjectGetData"},
	{FPDTextObjectSEL, FPDTextObjectRecalcPositionDataSEL, L"FPDTextObjectRecalcPositionData"},
	{FPDTextObjectSEL, FPDTextObjectGetCharRectSEL, L"FPDTextObjectGetCharRect"},
	{FPDTextObjectSEL, FPDTextObjectGetSpaceCharWidthSEL, L"FPDTextObjectGetSpaceCharWidth"},
	{FPDTextObjectSEL, FPDTextObjectGetCharInfo2SEL, L"FPDTextObjectGetCharInfo2"},
	{FPDTextObjectSEL, FPDTextObjectGetIndexSEL, L"FPDTextObjectGetIndex"},
	{FPDTextObjectSEL, FPDTextObjectSetIndexSEL, L"FPDTextObjectSetIndex"},
	{FPDPathObjectSEL, FPDPathObjectNewSEL, L"FPDPathObjectNew"},
	{FPDPathObjectSEL, FPDPathObjectDestroySEL, L"FPDPathObjectDestroy"},
	{FPDPathObjectSEL, FPDPathObjectTransformSEL, L"FPDPathObjectTransform"},
	{FPDPathObjectSEL, FPDPathObjectSetGraphStateSEL, L"FPDPathObjectSetGraphState"},
	{FPDPathObjectSEL, FPDPathObjectCalcBoundingBoxSEL, L"FPDPathObjectCalcBoundingBox"},
	{FPDPathObjectSEL, FPDPathObjectGetTransformMatrixSEL, L"FPDPathObjectGetTransformMatrix"},
	{FPDPathObjectSEL, FPDPathObjectSetTransformMatrixSEL, L"FPDPathObjectSetTransformMatrix"},
	{FPDPathObjectSEL, FPDPathObjectGetPathSEL, L"FPDPathObjectGetPath"},
	{FPDPathObjectSEL, FPDPathObjectIsStrokeModeSEL, L"FPDPathObjectIsStrokeMode"},
	{FPDPathObjectSEL, FPDPathObjectSetStrokeModeSEL, L"FPDPathObjectSetStrokeMode"},
	{FPDPathObjectSEL, FPDPathObjectGetFillModeSEL, L"FPDPathObjectGetFillMode"},
	{FPDPathObjectSEL, FPDPathObjectSetFillModeSEL, L"FPDPathObjectSetFillMode"},
	{FPDPathObjectSEL, FPDPathObjectGetPath2SEL, L"FPDPathObjectGetPath2"},
	{FPDPathObjectSEL, FPDPathObjectSetPathSEL, L"FPDPathObjectSetPath"},
	{FPDImageObjectSEL, FPDImageObjectNewSEL, L"FPDImageObjectNew"},
	{FPDImageObjectSEL, FPDImageObjectDestroySEL, L"FPDImageObjectDestroy"},
	{FPDImageObjectSEL, FPDImageObjectTransformSEL, L"FPDImageObjectTransform"},
	{FPDImageObjectSEL, FPDImageObjectCalcBoundingBoxSEL, L"FPDImageObjectCalcBoundingBox"},
	{FPDImageObjectSEL, FPDImageObjectGetTransformMatrixSEL, L"FPDImageObjectGetTransformMatrix"},
	{FPDImageObjectSEL, FPDImageObjectSetTransformMatrixSEL, L"FPDImageObjectSetTransformMatrix"},
	{FPDImageObjectSEL, FPDImageObjectGetImageSEL, L"FPDImageObjectGetImage"},
	{FPDImageObjectSEL, FPDImageObjectSetImageSEL, L"FPDImageObjectSetImage"},
	{FPDShadingObjectSEL, FPDShadingObjectNewSEL, L"FPDShadingObjectNew"},
	{FPDShadingObjectSEL, FPDShadingObjectDestroySEL, L"FPDShadingObjectDestroy"},
	{FPDShadingObjectSEL, FPDShadingObjectTransformSEL, L"FPDShadingObjectTransform"},
	{FPDShadingObjectSEL, FPDShadingObjectCalcBoundingBoxSEL, L"FPDShadingObjectCalcBoundingBox"},
	{FPDShadingObjectSEL, FPDShadingObjectGetTransformMatrixSEL, L"FPDShadingObjectGetTransformMatrix"},
	{FPDShadingObjectSEL, FPDShadingObjectSetTransformMatrixSEL, L"FPDShadingObjectSetTransformMatrix"},
	{FPDShadingObjectSEL, FPDShadingObjectGetPageSEL, L"FPDShadingObjectGetPage"},
	{FPDShadingObjectSEL, FPDShadingObjectSetPageSEL, L"FPDShadingObjectSetPage"},
	{FPDShadingObjectSEL, FPDShadingObjectGetShadingPatternSEL, L"FPDShadingObjectGetShadingPattern"},
	{FPDShadingObjectSEL, FPDShadingObjectSetShadingPatternSEL, L"FPDShadingObjectSetShadingPattern"},
	{FPDFormObjectSEL, FPDFormObjectNewSEL, L"FPDFormObjectNew"},
	{FPDFormObjectSEL, FPDFormObjectDestroySEL, L"FPDFormObjectDestroy"},
	{FPDFormObjectSEL, FPDFormObjectTransformSEL, L"FPDFormObjectTransform"},
	{FPDFormObjectSEL, FPDFormObjectCalcBoundingBoxSEL, L"FPDFormObjectCalcBoundingBox"},
	{FPDFormObjectSEL, FPDFormObjectGetTransformMatrixSEL, L"FPDFormObjectGetTransformMatrix"},
	{FPDFormObjectSEL, FPDFormObjectSetTransformMatrixSEL, L"FPDFormObjectSetTransformMatrix"},
	{FPDFormObjectSEL, FPDFormObjectGetFormSEL, L"FPDFormObjectGetForm"},
	{FPDFormObjectSEL, FPDFormObjectSetFormSEL, L"FPDFormObjectSetForm"},
	{FPDInlineImagesSEL, FPDInlineImagesNewSEL, L"FPDInlineImagesNew"},
	{FPDInlineImagesSEL, FPDInlineImagesDestroySEL, L"FPDInlineImagesDestroy"},
	{FPDInlineImagesSEL, FPDInlineImagesAddMatrixSEL, L"FPDInlineImagesAddMatrix"},
	{FPDInlineImagesSEL, FPDInlineImagesCountMatrixSEL, L"FPDInlineImagesCountMatrix"},
	{FPDInlineImagesSEL, FPDInlineImagesGetMatrixSEL, L"FPDInlineImagesGetMatrix"},
	{FPDInlineImagesSEL, FPDInlineImagesGetStreamSEL, L"FPDInlineImagesGetStream"},
	{FPDInlineImagesSEL, FPDInlineImagesSetStreamSEL, L"FPDInlineImagesSetStream"},
	{FPDInlineImagesSEL, FPDInlineImagesGetDIBitmapSEL, L"FPDInlineImagesGetDIBitmap"},
	{FPDContentMarkItemSEL, FPDContentMarkItemNewSEL, L"FPDContentMarkItemNew"},
	{FPDContentMarkItemSEL, FPDContentMarkItemDestroySEL, L"FPDContentMarkItemDestroy"},
	{FPDContentMarkItemSEL, FPDContentMarkItemGetNameSEL, L"FPDContentMarkItemGetName"},
	{FPDContentMarkItemSEL, FPDContentMarkItemGetParamTypeSEL, L"FPDContentMarkItemGetParamType"},
	{FPDContentMarkItemSEL, FPDContentMarkItemGetParamSEL, L"FPDContentMarkItemGetParam"},
	{FPDContentMarkItemSEL, FPDContentMarkItemSetNameSEL, L"FPDContentMarkItemSetName"},
	{FPDContentMarkItemSEL, FPDContentMarkItemSetParamSEL, L"FPDContentMarkItemSetParam"},
	{FPDContentMarkItemSEL, FPDContentMarkItemHasMCIDSEL, L"FPDContentMarkItemHasMCID"},
	{FPDContentMarkSEL, FPDContentMarkNewSEL, L"FPDContentMarkNew"},
	{FPDContentMarkSEL, FPDContentMarkDestroySEL, L"FPDContentMarkDestroy"},
	{FPDContentMarkSEL, FPDContentMarkGetMCIDSEL, L"FPDContentMarkGetMCID"},
	{FPDContentMarkSEL, FPDContentMarkHasMarkSEL, L"FPDContentMarkHasMark"},
	{FPDContentMarkSEL, FPDContentMarkLookupMarkSEL, L"FPDContentMarkLookupMark"},
	{FPDContentMarkSEL, FPDContentMarkCountItemsSEL, L"FPDContentMarkCountItems"},
	{FPDContentMarkSEL, FPDContentMarkGetItemSEL, L"FPDContentMarkGetItem"},
	{FPDContentMarkSEL, FPDContentMarkAddMarkSEL, L"FPDContentMarkAddMark"},
	{FPDContentMarkSEL, FPDContentMarkDeleteMarkSEL, L"FPDContentMarkDeleteMark"},
	{FPDContentMarkSEL, FPDContentMarkDeleteLastMarkSEL, L"FPDContentMarkDeleteLastMark"},
	{FPDContentMarkSEL, FPDContentMarkIsNullSEL, L"FPDContentMarkIsNull"},
	{FPDContentMarkSEL, FPDContentMarkCopySEL, L"FPDContentMarkCopy"},
	{FPDContentMarkSEL, FPDContentMarkGetContentMarkDataMCIDSEL, L"FPDContentMarkGetContentMarkDataMCID"},
	{FPDContentMarkSEL, FPDContentMarkCheckContentMarkDataIsNULLSEL, L"FPDContentMarkCheckContentMarkDataIsNULL"},
	{FPDContentMarkSEL, FPDContentMarkGetItem2SEL, L"FPDContentMarkGetItem2"},
	{FPDContentMarkSEL, FPDContentMarkAddMark2SEL, L"FPDContentMarkAddMark2"},
	{FPDContentMarkSEL, FPDContentMarkGetItemsSEL, L"FPDContentMarkGetItems"},
	{FPDContentMarkSEL, FPDContentMarkGetModifySEL, L"FPDContentMarkGetModify"},
	{FPDContentMarkSEL, FPDContentMarkDoObjectNewSEL, L"FPDContentMarkDoObjectNew"},
	{FPDContentMarkSEL, FPDContentMarkIsEqualSEL, L"FPDContentMarkIsEqual"},
	{FPDContentMarkSEL, FPDContentMarkCopy2SEL, L"FPDContentMarkCopy2"},
	{FPDContentMarkSEL, FPDContentMarkGetItem3SEL, L"FPDContentMarkGetItem3"},
	{FPDContentMarkSEL, FPDContentMarkRemoveItemSEL, L"FPDContentMarkRemoveItem"},
	{FPDContentMarkSEL, FPDContentMarkRemoveAllItemsSEL, L"FPDContentMarkRemoveAllItems"},
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
	{FPDParserSEL, FPDParserNewSEL, L"FPDParserNew"},
	{FPDParserSEL, FPDParserDestroySEL, L"FPDParserDestroy"},
	{FPDParserSEL, FPDParserStartParseSEL, L"FPDParserStartParse"},
	{FPDParserSEL, FPDParserStartParseWSEL, L"FPDParserStartParseW"},
	{FPDParserSEL, FPDParserStartParseFormMemSEL, L"FPDParserStartParseFormMem"},
	{FPDParserSEL, FPDParserStartParseCustomFileSEL, L"FPDParserStartParseCustomFile"},
	{FPDParserSEL, FPDParserCloseParserSEL, L"FPDParserCloseParser"},
	{FPDParserSEL, FPDParserGetPermissionsSEL, L"FPDParserGetPermissions"},
	{FPDParserSEL, FPDParserIsOwnerSEL, L"FPDParserIsOwner"},
	{FPDParserSEL, FPDParserSetPasswordSEL, L"FPDParserSetPassword"},
	{FPDParserSEL, FPDParserGetPasswordSEL, L"FPDParserGetPassword"},
	{FPDParserSEL, FPDParserGetTrailerSEL, L"FPDParserGetTrailer"},
	{FPDParserSEL, FPDParserGetLastXRefOffsetSEL, L"FPDParserGetLastXRefOffset"},
	{FPDParserSEL, FPDParserGetDocumentSEL, L"FPDParserGetDocument"},
	{FPDParserSEL, FPDParserCountOtherTrailersSEL, L"FPDParserCountOtherTrailers"},
	{FPDParserSEL, FPDParserGetOtherTrailerByIndexSEL, L"FPDParserGetOtherTrailerByIndex"},
	{FPDParserSEL, FPDParserGetRootObjNumSEL, L"FPDParserGetRootObjNum"},
	{FPDParserSEL, FPDParserGetInfoObjNumSEL, L"FPDParserGetInfoObjNum"},
	{FPDParserSEL, FPDParserGetIDArraySEL, L"FPDParserGetIDArray"},
	{FPDParserSEL, FPDParserGetEncryptDictSEL, L"FPDParserGetEncryptDict"},
	{FPDParserSEL, FPDParserParseIndirectObjectSEL, L"FPDParserParseIndirectObject"},
	{FPDParserSEL, FPDParserGetLastObjNumSEL, L"FPDParserGetLastObjNum"},
	{FPDParserSEL, FPDParserIsFormStreamSEL, L"FPDParserIsFormStream"},
	{FPDParserSEL, FPDParserReloadFileStreamSEL, L"FPDParserReloadFileStream"},
	{FPDParserSEL, FPDParserDeleteIndirectObjectSEL, L"FPDParserDeleteIndirectObject"},
	{FPDParserSEL, FPDParserGetLengthOfVersionsSEL, L"FPDParserGetLengthOfVersions"},
	{FPDParserSEL, FPDParserGetObjectOffsetSEL, L"FPDParserGetObjectOffset"},
	{FPDParserSEL, FPDParserGetObjectSizeSEL, L"FPDParserGetObjectSize"},
	{FPDParserSEL, FPDParserGetObjectVersionSEL, L"FPDParserGetObjectVersion"},
	{FPDParserSEL, FPDParserGetIndirectBinarySEL, L"FPDParserGetIndirectBinary"},
	{FPDParserSEL, FPDParserParseStreamPosSEL, L"FPDParserParseStreamPos"},
	{FPDParserSEL, FPDParserParseIndirectObjectsAtRangeSEL, L"FPDParserParseIndirectObjectsAtRange"},
	{FPDParserSEL, FPDParserGetFileStreamOptionSEL, L"FPDParserGetFileStreamOption"},
	{FPDParserSEL, FPDParserSetFileStreamOptionSEL, L"FPDParserSetFileStreamOption"},
	{FPDParserSEL, FPDParserGetFileAccessSEL, L"FPDParserGetFileAccess"},
	{FPDParserSEL, FPDParserGetFileVersionSEL, L"FPDParserGetFileVersion"},
	{FPDParserSEL, FPDParserIsXRefStreamSEL, L"FPDParserIsXRefStream"},
	{FPDParserSEL, FPDParserParseIndirectObjectAtSEL, L"FPDParserParseIndirectObjectAt"},
	{FPDParserSEL, FPDParserStartAsynParseSEL, L"FPDParserStartAsynParse"},
	{FPDParserSEL, FPDParserGetFirstPageNoSEL, L"FPDParserGetFirstPageNo"},
	{FPDParserSEL, FPDParserGetSecurityPermissionsSEL, L"FPDParserGetSecurityPermissions"},
	{FPDParserSEL, FPDParserIsSecurityOwnerSEL, L"FPDParserIsSecurityOwner"},
	{FPDParserSEL, FPDParserGetSecurityCryptInfoSEL, L"FPDParserGetSecurityCryptInfo"},
	{FPDParserSEL, FPDParserIsMetadataEncryptedBySecuritySEL, L"FPDParserIsMetadataEncryptedBySecurity"},
	{FPDParserSEL, FPDParserGetStandardSecurityUserPasswordSEL, L"FPDParserGetStandardSecurityUserPassword"},
	{FPDParserSEL, FPDParserGetStandardSecurityVersionSEL, L"FPDParserGetStandardSecurityVersion"},
	{FPDParserSEL, FPDParserGetStandardSecurityRevisionSEL, L"FPDParserGetStandardSecurityRevision"},
	{FPDParserSEL, FPDParserCheckStandardSecurityPasswordSEL, L"FPDParserCheckStandardSecurityPassword"},
	{FPDParserSEL, FPDParserCheckEmbeddedSecuritySEL, L"FPDParserCheckEmbeddedSecurity"},
	{FPDParserSEL, FPDParserLoadAttachmentStreamSEL, L"FPDParserLoadAttachmentStream"},
	{FPDParserSEL, FPDParserSetUnicodePasswordSEL, L"FPDParserSetUnicodePassword"},
	{FPDParserSEL, FPDParserGetUnicodePasswordSEL, L"FPDParserGetUnicodePassword"},
	{FPDParserSEL, FPDParserCheckPasswordSEL, L"FPDParserCheckPassword"},
	{FPDParserSEL, FPDParserSetPassword2SEL, L"FPDParserSetPassword2"},
	{FPDParserSEL, FPDParserSetPassword3SEL, L"FPDParserSetPassword3"},
	{FPDParserSEL, FPDParserCheckHasCryptoHandlerSEL, L"FPDParserCheckHasCryptoHandler"},
	{FPDParserSEL, FPDParserCheckPassword2SEL, L"FPDParserCheckPassword2"},
	{FPDParserSEL, FPDParserIsParsingLinearizedSEL, L"FPDParserIsParsingLinearized"},
	{FPDParserSEL, FPDParserHasRebuildXRefSEL, L"FPDParserHasRebuildXRef"},
	{FPDParserSEL, FPDParserGetSizeAnalysisSEL, L"FPDParserGetSizeAnalysis"},
	{FPDParserSEL, FPDParserEnableSizeAnalysisSEL, L"FPDParserEnableSizeAnalysis"},
	{FPDParserSEL, FPDParserSetObjStmCacheLimitSizeSEL, L"FPDParserSetObjStmCacheLimitSize"},
	{FPDParserSEL, FPDParserContinueSEL, L"FPDParserContinue"},
	{FPDParserSEL, FPDParserSetRecipientSEL, L"FPDParserSetRecipient"},
	{FPDParserSEL, FPDParserCheckStandardSecurityPassword2SEL, L"FPDParserCheckStandardSecurityPassword2"},
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
	{FPDRenderOptionsSEL, FPDRenderOptionsNewSEL, L"FPDRenderOptionsNew"},
	{FPDRenderOptionsSEL, FPDRenderOptionsDestroySEL, L"FPDRenderOptionsDestroy"},
	{FPDRenderOptionsSEL, FPDRenderOptionsGetColorModeSEL, L"FPDRenderOptionsGetColorMode"},
	{FPDRenderOptionsSEL, FPDRenderOptionsSetColorModeSEL, L"FPDRenderOptionsSetColorMode"},
	{FPDRenderOptionsSEL, FPDRenderOptionsGetBackColorSEL, L"FPDRenderOptionsGetBackColor"},
	{FPDRenderOptionsSEL, FPDRenderOptionsSetBackColorSEL, L"FPDRenderOptionsSetBackColor"},
	{FPDRenderOptionsSEL, FPDRenderOptionsGetForeColorSEL, L"FPDRenderOptionsGetForeColor"},
	{FPDRenderOptionsSEL, FPDRenderOptionsSetForeColorSEL, L"FPDRenderOptionsSetForeColor"},
	{FPDRenderOptionsSEL, FPDRenderOptionsGetRenderFlagSEL, L"FPDRenderOptionsGetRenderFlag"},
	{FPDRenderOptionsSEL, FPDRenderOptionsSetRenderFlagSEL, L"FPDRenderOptionsSetRenderFlag"},
	{FPDRenderOptionsSEL, FPDRenderOptionsGetAddtionalFlagSEL, L"FPDRenderOptionsGetAddtionalFlag"},
	{FPDRenderOptionsSEL, FPDRenderOptionsSetAddtionalFlagSEL, L"FPDRenderOptionsSetAddtionalFlag"},
	{FPDRenderOptionsSEL, FPDRenderOptionsSetOCCHandlerSEL, L"FPDRenderOptionsSetOCCHandler"},
	{FPDRenderOptionsSEL, FPDRenderOptionsTranslateColorSEL, L"FPDRenderOptionsTranslateColor"},
	{FPDRenderOptionsSEL, FPDRenderOptionsCreateOCContextHandlerSEL, L"FPDRenderOptionsCreateOCContextHandler"},
	{FPDRenderOptionsSEL, FPDRenderOptionsDeleteOCContextHandlerSEL, L"FPDRenderOptionsDeleteOCContextHandler"},
	{FPDRenderOptionsSEL, FPDRenderOptionsSetDocTextColorSEL, L"FPDRenderOptionsSetDocTextColor"},
	{FPDRenderOptionsSEL, FPDRenderOptionsGetDocTextColorSEL, L"FPDRenderOptionsGetDocTextColor"},
	{FPDRenderOptionsSEL, FPDRenderOptionsSetCustomColorModeSEL, L"FPDRenderOptionsSetCustomColorMode"},
	{FPDRenderOptionsSEL, FPDRenderOptionsGetCustomColorModeSEL, L"FPDRenderOptionsGetCustomColorMode"},
	{FPDRenderOptionsSEL, FPDRenderOptionsTranslateColor2SEL, L"FPDRenderOptionsTranslateColor2"},
	{FPDRenderContextSEL, FPDRenderContextNewSEL, L"FPDRenderContextNew"},
	{FPDRenderContextSEL, FPDRenderContextNew2SEL, L"FPDRenderContextNew2"},
	{FPDRenderContextSEL, FPDRenderContextDestroySEL, L"FPDRenderContextDestroy"},
	{FPDRenderContextSEL, FPDRenderContextDrawStreamSEL, L"FPDRenderContextDrawStream"},
	{FPDRenderContextSEL, FPDRenderContextAppendPageSEL, L"FPDRenderContextAppendPage"},
	{FPDRenderContextSEL, FPDRenderContextAppendFormSEL, L"FPDRenderContextAppendForm"},
	{FPDRenderContextSEL, FPDRenderContextSetBackgroundSEL, L"FPDRenderContextSetBackground"},
	{FPDRenderContextSEL, FPDRenderContextCreateBackgroundDrawHandlerSEL, L"FPDRenderContextCreateBackgroundDrawHandler"},
	{FPDRenderContextSEL, FPDRenderContextDeleteBackgroundDrawHandlerSEL, L"FPDRenderContextDeleteBackgroundDrawHandler"},
	{FPDRenderContextSEL, FPDRenderContextRenderSEL, L"FPDRenderContextRender"},
	{FPDRenderContextSEL, FPDRenderContextDrawPageSEL, L"FPDRenderContextDrawPage"},
	{FPDRenderContextSEL, FPDRenderContextDrawFormSEL, L"FPDRenderContextDrawForm"},
	{FPDRenderContextSEL, FPDRenderContextQuickDrawSEL, L"FPDRenderContextQuickDraw"},
	{FPDRenderContextSEL, FPDRenderContextGetBackgroundSEL, L"FPDRenderContextGetBackground"},
	{FPDRenderContextSEL, FPDRenderContextGetPageCacheSEL, L"FPDRenderContextGetPageCache"},
	{FPDProgressiveRenderSEL, FPDProgressiveRenderNewSEL, L"FPDProgressiveRenderNew"},
	{FPDProgressiveRenderSEL, FPDProgressiveRenderDestroySEL, L"FPDProgressiveRenderDestroy"},
	{FPDProgressiveRenderSEL, FPDProgressiveRenderStartSEL, L"FPDProgressiveRenderStart"},
	{FPDProgressiveRenderSEL, FPDProgressiveRenderContinueSEL, L"FPDProgressiveRenderContinue"},
	{FPDProgressiveRenderSEL, FPDProgressiveRenderEstimateProgressSEL, L"FPDProgressiveRenderEstimateProgress"},
	{FPDProgressiveRenderSEL, FPDProgressiveRenderClearSEL, L"FPDProgressiveRenderClear"},
	{FPDProgressiveRenderSEL, FPDProgressiveRenderGetStatusSEL, L"FPDProgressiveRenderGetStatus"},
	{FPDRenderDeviceSEL, FPDRenderDeviceNewSEL, L"FPDRenderDeviceNew"},
	{FPDRenderDeviceSEL, FPDRenderDeviceDestroySEL, L"FPDRenderDeviceDestroy"},
	{FPDRenderDeviceSEL, FPDRenderDeviceStartRenderingSEL, L"FPDRenderDeviceStartRendering"},
	{FPDRenderDeviceSEL, FPDRenderDeviceEndRenderingSEL, L"FPDRenderDeviceEndRendering"},
	{FPDRenderDeviceSEL, FPDRenderDeviceSaveStateSEL, L"FPDRenderDeviceSaveState"},
	{FPDRenderDeviceSEL, FPDRenderDeviceRestoreStateSEL, L"FPDRenderDeviceRestoreState"},
	{FPDRenderDeviceSEL, FPDRenderDeviceGetWidthSEL, L"FPDRenderDeviceGetWidth"},
	{FPDRenderDeviceSEL, FPDRenderDeviceGetHeightSEL, L"FPDRenderDeviceGetHeight"},
	{FPDRenderDeviceSEL, FPDRenderDeviceGetBPPSEL, L"FPDRenderDeviceGetBPP"},
	{FPDRenderDeviceSEL, FPDRenderDeviceGetRenderCapsSEL, L"FPDRenderDeviceGetRenderCaps"},
	{FPDRenderDeviceSEL, FPDRenderDeviceGetDeviceCapsXYSEL, L"FPDRenderDeviceGetDeviceCapsXY"},
	{FPDRenderDeviceSEL, FPDRenderDeviceGetBitmapSEL, L"FPDRenderDeviceGetBitmap"},
	{FPDRenderDeviceSEL, FPDRenderDeviceSetBitmapSEL, L"FPDRenderDeviceSetBitmap"},
	{FPDRenderDeviceSEL, FPDRenderDeviceSetPixelSEL, L"FPDRenderDeviceSetPixel"},
	{FPDRenderDeviceSEL, FPDRenderDeviceSetClip_RectSEL, L"FPDRenderDeviceSetClip_Rect"},
	{FPDRenderDeviceSEL, FPDRenderDeviceCreateCompatibleBitmapSEL, L"FPDRenderDeviceCreateCompatibleBitmap"},
	{FPDRenderDeviceSEL, FPDRenderDeviceFillRectSEL, L"FPDRenderDeviceFillRect"},
	{FPDRenderDeviceSEL, FPDRenderDeviceDrawCosmeticLineSEL, L"FPDRenderDeviceDrawCosmeticLine"},
	{FPDRenderDeviceSEL, FPDRenderDeviceGetDIBitsSEL, L"FPDRenderDeviceGetDIBits"},
	{FPDRenderDeviceSEL, FPDRenderDeviceSetDIBitsSEL, L"FPDRenderDeviceSetDIBits"},
	{FPDRenderDeviceSEL, FPDRenderDeviceStretchDIBitsSEL, L"FPDRenderDeviceStretchDIBits"},
	{FPDRenderDeviceSEL, FPDRenderDeviceSetBitMaskSEL, L"FPDRenderDeviceSetBitMask"},
	{FPDRenderDeviceSEL, FPDRenderDeviceStretchBitMaskSEL, L"FPDRenderDeviceStretchBitMask"},
	{FPDRenderDeviceSEL, FPDRenderDeviceGetDitherBitsSEL, L"FPDRenderDeviceGetDitherBits"},
	{FPDRenderDeviceSEL, FPDRenderDeviceDrawTextStringSEL, L"FPDRenderDeviceDrawTextString"},
	{FPDRenderDeviceSEL, FPDRenderDeviceDrawTextString2SEL, L"FPDRenderDeviceDrawTextString2"},
	{FPDRenderDeviceSEL, FPDRenderDeviceDrawTextPathSEL, L"FPDRenderDeviceDrawTextPath"},
	{FPDRenderDeviceSEL, FPDRenderDeviceDrawNormalTextSEL, L"FPDRenderDeviceDrawNormalText"},
	{FPDRenderDeviceSEL, FPDRenderDeviceDrawType3TextSEL, L"FPDRenderDeviceDrawType3Text"},
	{FPDRenderDeviceSEL, FPDRenderDeviceDrawPathSEL, L"FPDRenderDeviceDrawPath"},
	{FPDRenderDeviceSEL, FPDRenderDeviceSetClip_PathFillSEL, L"FPDRenderDeviceSetClip_PathFill"},
	{FPDRenderDeviceSEL, FPDRenderDeviceSetClip_PathFill2SEL, L"FPDRenderDeviceSetClip_PathFill2"},
	{FPDRenderDeviceSEL, FPDRenderDeviceGetMatrixSEL, L"FPDRenderDeviceGetMatrix"},
	{FPDFxgeDeviceSEL, FPDFxgeDeviceNewSEL, L"FPDFxgeDeviceNew"},
	{FPDFxgeDeviceSEL, FPDFxgeDeviceCreateSEL, L"FPDFxgeDeviceCreate"},
	{FPDFxgeDeviceSEL, FPDFxgeDeviceDestroySEL, L"FPDFxgeDeviceDestroy"},
	{FPDFxgeDeviceSEL, FPDFxgeDeviceAttachSEL, L"FPDFxgeDeviceAttach"},
	{FPDWindowsDeviceSEL, FPDWindowsDeviceNewSEL, L"FPDWindowsDeviceNew"},
	{FPDWindowsDeviceSEL, FPDWindowsDeviceDestroySEL, L"FPDWindowsDeviceDestroy"},
	{FPDWindowsDeviceSEL, FPDWindowsDeviceGetDCSEL, L"FPDWindowsDeviceGetDC"},
	{FPDPageRenderCacheSEL, FPDPageRenderCacheNewSEL, L"FPDPageRenderCacheNew"},
	{FPDPageRenderCacheSEL, FPDPageRenderCacheDestroySEL, L"FPDPageRenderCacheDestroy"},
	{FPDPageRenderCacheSEL, FPDPageRenderCacheClearAllSEL, L"FPDPageRenderCacheClearAll"},
	{FPDPageRenderCacheSEL, FPDPageRenderCacheClearImageDataSEL, L"FPDPageRenderCacheClearImageData"},
	{FPDPageRenderCacheSEL, FPDPageRenderCacheEstimateSizeSEL, L"FPDPageRenderCacheEstimateSize"},
	{FPDPageRenderCacheSEL, FPDPageRenderCacheGetCachedBitmapSEL, L"FPDPageRenderCacheGetCachedBitmap"},
	{FPDPageRenderCacheSEL, FPDPageRenderCacheResetBitmapSEL, L"FPDPageRenderCacheResetBitmap"},
	{FPDPageRenderCacheSEL, FPDPageRenderCacheCalcBitmapMarginSEL, L"FPDPageRenderCacheCalcBitmapMargin"},
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
	{FPDFontSEL, FPDFontNewSEL, L"FPDFontNew"},
	{FPDFontSEL, FPDFontDestroySEL, L"FPDFontDestroy"},
	{FPDFontSEL, FPDFontGetStockFontSEL, L"FPDFontGetStockFont"},
	{FPDFontSEL, FPDFontGetFontTypeSEL, L"FPDFontGetFontType"},
	{FPDFontSEL, FPDFontGetFontTypeNameSEL, L"FPDFontGetFontTypeName"},
	{FPDFontSEL, FPDFontGetBaseFontSEL, L"FPDFontGetBaseFont"},
	{FPDFontSEL, FPDFontGetSubstFontSEL, L"FPDFontGetSubstFont"},
	{FPDFontSEL, FPDFontGetFlagsSEL, L"FPDFontGetFlags"},
	{FPDFontSEL, FPDFontGetType1FontSEL, L"FPDFontGetType1Font"},
	{FPDFontSEL, FPDFontGetTrueTypeFontSEL, L"FPDFontGetTrueTypeFont"},
	{FPDFontSEL, FPDFontGetCIDFontSEL, L"FPDFontGetCIDFont"},
	{FPDFontSEL, FPDFontGetType3FontSEL, L"FPDFontGetType3Font"},
	{FPDFontSEL, FPDFontIsEmbeddedSEL, L"FPDFontIsEmbedded"},
	{FPDFontSEL, FPDFontIsUnicodeCompatibleSEL, L"FPDFontIsUnicodeCompatible"},
	{FPDFontSEL, FPDFontGetFontFileSEL, L"FPDFontGetFontFile"},
	{FPDFontSEL, FPDFontGetFontDictSEL, L"FPDFontGetFontDict"},
	{FPDFontSEL, FPDFontIsStandardFontSEL, L"FPDFontIsStandardFont"},
	{FPDFontSEL, FPDFontGetFaceSEL, L"FPDFontGetFace"},
	{FPDFontSEL, FPDFontGetNextCharSEL, L"FPDFontGetNextChar"},
	{FPDFontSEL, FPDFontCountCharSEL, L"FPDFontCountChar"},
	{FPDFontSEL, FPDFontAppendCharSEL, L"FPDFontAppendChar"},
	{FPDFontSEL, FPDFontAppendChar2SEL, L"FPDFontAppendChar2"},
	{FPDFontSEL, FPDFontGetCharSizeSEL, L"FPDFontGetCharSize"},
	{FPDFontSEL, FPDFontGlyphFromCharCodeSEL, L"FPDFontGlyphFromCharCode"},
	{FPDFontSEL, FPDFontUnicodeFromCharCodeSEL, L"FPDFontUnicodeFromCharCode"},
	{FPDFontSEL, FPDFontCharCodeFromUnicodeSEL, L"FPDFontCharCodeFromUnicode"},
	{FPDFontSEL, FPDFontIsCharEmbeddedSEL, L"FPDFontIsCharEmbedded"},
	{FPDFontSEL, FPDFontGetCharMapSEL, L"FPDFontGetCharMap"},
	{FPDFontSEL, FPDFontEncodeStringSEL, L"FPDFontEncodeString"},
	{FPDFontSEL, FPDFontDecodeStringSEL, L"FPDFontDecodeString"},
	{FPDFontSEL, FPDFontRecognizeCharSEL, L"FPDFontRecognizeChar"},
	{FPDFontSEL, FPDFontGetFontBBoxSEL, L"FPDFontGetFontBBox"},
	{FPDFontSEL, FPDFontGetTypeAscentSEL, L"FPDFontGetTypeAscent"},
	{FPDFontSEL, FPDFontGetTypeDescentSEL, L"FPDFontGetTypeDescent"},
	{FPDFontSEL, FPDFontGetItalicAngleSEL, L"FPDFontGetItalicAngle"},
	{FPDFontSEL, FPDFontGetStringWidthSEL, L"FPDFontGetStringWidth"},
	{FPDFontSEL, FPDFontGetCharWidthFSEL, L"FPDFontGetCharWidthF"},
	{FPDFontSEL, FPDFontGetCharTypeWidthSEL, L"FPDFontGetCharTypeWidth"},
	{FPDFontSEL, FPDFontGetCharBBoxSEL, L"FPDFontGetCharBBox"},
	{FPDFontSEL, FPDFontGetPDFDocSEL, L"FPDFontGetPDFDoc"},
	{FPDFontSEL, FPDFontLoadGlyphPathSEL, L"FPDFontLoadGlyphPath"},
	{FPDFontSEL, FPDFontGetSubstFontCharsetSEL, L"FPDFontGetSubstFontCharset"},
	{FPDFontSEL, FPDFontIsVertWritingSEL, L"FPDFontIsVertWriting"},
	{FPDFontSEL, FPDFontGetFXFontSEL, L"FPDFontGetFXFont"},
	{FPDFontSEL, FPDFontFXFontGetFaceNameSEL, L"FPDFontFXFontGetFaceName"},
	{FPDFontSEL, FPDFontFXFontGetPsNameSEL, L"FPDFontFXFontGetPsName"},
	{FPDFontSEL, FPDFontFXFontGetFamilyNameSEL, L"FPDFontFXFontGetFamilyName"},
	{FPDFontSEL, FPDFontFXFontIsItalicSEL, L"FPDFontFXFontIsItalic"},
	{FPDFontSEL, FPDFontFXFontIsBoldSEL, L"FPDFontFXFontIsBold"},
	{FPDFontSEL, FPDFontUnicodeFromCharCodeExSEL, L"FPDFontUnicodeFromCharCodeEx"},
	{FPDFontSEL, FPDFontGetSubstFontWeightSEL, L"FPDFontGetSubstFontWeight"},
	{FPDFontSEL, FPDFontFXFontLoadSubstSEL, L"FPDFontFXFontLoadSubst"},
	{FPDFontSEL, FPDFontGetUnicodeBaseFontSEL, L"FPDFontGetUnicodeBaseFont"},
	{FPDFontSEL, FPDFontIsTTFontSEL, L"FPDFontIsTTFont"},
	{FPDFontSEL, FPDFontNewFXFontSEL, L"FPDFontNewFXFont"},
	{FPDFontSEL, FPDFontDeleteFXFontSEL, L"FPDFontDeleteFXFont"},
	{FPDFontSEL, FPDFontGetCharOutBBoxSEL, L"FPDFontGetCharOutBBox"},
	{FPDFontEncodingSEL, FPDFontEncodingNewSEL, L"FPDFontEncodingNew"},
	{FPDFontEncodingSEL, FPDFontEncodingNew2SEL, L"FPDFontEncodingNew2"},
	{FPDFontEncodingSEL, FPDFontEncodingDestroySEL, L"FPDFontEncodingDestroy"},
	{FPDFontEncodingSEL, FPDFontEncodingLoadEncodingSEL, L"FPDFontEncodingLoadEncoding"},
	{FPDFontEncodingSEL, FPDFontEncodingIsIdenticalSEL, L"FPDFontEncodingIsIdentical"},
	{FPDFontEncodingSEL, FPDFontEncodingUnicodeFromCharCodeSEL, L"FPDFontEncodingUnicodeFromCharCode"},
	{FPDFontEncodingSEL, FPDFontEncodingCharCodeFromUnicodeSEL, L"FPDFontEncodingCharCodeFromUnicode"},
	{FPDFontEncodingSEL, FPDFontEncodingSetUnicodeSEL, L"FPDFontEncodingSetUnicode"},
	{FPDFontEncodingSEL, FPDFontEncodingRealizeSEL, L"FPDFontEncodingRealize"},
	{FPDType1FontSEL, FPDType1FontNewSEL, L"FPDType1FontNew"},
	{FPDType1FontSEL, FPDType1FontDestroySEL, L"FPDType1FontDestroy"},
	{FPDType1FontSEL, FPDType1FontGetEncodingSEL, L"FPDType1FontGetEncoding"},
	{FPDType1FontSEL, FPDType1FontGetCharWidthFSEL, L"FPDType1FontGetCharWidthF"},
	{FPDType1FontSEL, FPDType1FontGetCharBBoxSEL, L"FPDType1FontGetCharBBox"},
	{FPDType1FontSEL, FPDType1FontGlyphFromCharCodeSEL, L"FPDType1FontGlyphFromCharCode"},
	{FPDType1FontSEL, FPDType1FontIsUnicodeCompatibleSEL, L"FPDType1FontIsUnicodeCompatible"},
	{FPDType1FontSEL, FPDType1FontGetBase14FontSEL, L"FPDType1FontGetBase14Font"},
	{FPDTrueTypeFontSEL, FPDTrueTypeFontNewSEL, L"FPDTrueTypeFontNew"},
	{FPDTrueTypeFontSEL, FPDTrueTypeFontDestroySEL, L"FPDTrueTypeFontDestroy"},
	{FPDTrueTypeFontSEL, FPDTrueTypeFontGetEncodingSEL, L"FPDTrueTypeFontGetEncoding"},
	{FPDTrueTypeFontSEL, FPDTrueTypeFontGetCharWidthFSEL, L"FPDTrueTypeFontGetCharWidthF"},
	{FPDTrueTypeFontSEL, FPDTrueTypeFontGetCharBBoxSEL, L"FPDTrueTypeFontGetCharBBox"},
	{FPDTrueTypeFontSEL, FPDTrueTypeFontGlyphFromCharCodeSEL, L"FPDTrueTypeFontGlyphFromCharCode"},
	{FPDTrueTypeFontSEL, FPDTrueTypeFontIsUnicodeCompatibleSEL, L"FPDTrueTypeFontIsUnicodeCompatible"},
	{FPDType3CharSEL, FPDType3CharNewSEL, L"FPDType3CharNew"},
	{FPDType3CharSEL, FPDType3CharDestroySEL, L"FPDType3CharDestroy"},
	{FPDType3CharSEL, FPDType3CharIsColoredSEL, L"FPDType3CharIsColored"},
	{FPDType3CharSEL, FPDType3CharIsPageRequiredSEL, L"FPDType3CharIsPageRequired"},
	{FPDType3CharSEL, FPDType3CharGetFormSEL, L"FPDType3CharGetForm"},
	{FPDType3CharSEL, FPDType3CharGetImageMatrixSEL, L"FPDType3CharGetImageMatrix"},
	{FPDType3CharSEL, FPDType3CharGetDIBitmapSEL, L"FPDType3CharGetDIBitmap"},
	{FPDType3CharSEL, FPDType3CharGetWidthSEL, L"FPDType3CharGetWidth"},
	{FPDType3CharSEL, FPDType3CharGetBBoxSEL, L"FPDType3CharGetBBox"},
	{FPDType3FontSEL, FPDType3FontNewSEL, L"FPDType3FontNew"},
	{FPDType3FontSEL, FPDType3FontDestroySEL, L"FPDType3FontDestroy"},
	{FPDType3FontSEL, FPDType3FontGetEncodingSEL, L"FPDType3FontGetEncoding"},
	{FPDType3FontSEL, FPDType3FontGetCharWidthFSEL, L"FPDType3FontGetCharWidthF"},
	{FPDType3FontSEL, FPDType3FontGetCharBBoxSEL, L"FPDType3FontGetCharBBox"},
	{FPDType3FontSEL, FPDType3FontGlyphFromCharCodeSEL, L"FPDType3FontGlyphFromCharCode"},
	{FPDType3FontSEL, FPDType3FontIsUnicodeCompatibleSEL, L"FPDType3FontIsUnicodeCompatible"},
	{FPDType3FontSEL, FPDType3FontSetPageResourcesSEL, L"FPDType3FontSetPageResources"},
	{FPDType3FontSEL, FPDType3FontLoadCharSEL, L"FPDType3FontLoadChar"},
	{FPDType3FontSEL, FPDType3FontGetCharTypeWidthSEL, L"FPDType3FontGetCharTypeWidth"},
	{FPDType3FontSEL, FPDType3FontGetFontMatrixSEL, L"FPDType3FontGetFontMatrix"},
	{FPDCIDFontSEL, FPDCIDFontNewSEL, L"FPDCIDFontNew"},
	{FPDCIDFontSEL, FPDCIDFontDestroySEL, L"FPDCIDFontDestroy"},
	{FPDCIDFontSEL, FPDCIDFontGetCharWidthFSEL, L"FPDCIDFontGetCharWidthF"},
	{FPDCIDFontSEL, FPDCIDFontGetCharBBoxSEL, L"FPDCIDFontGetCharBBox"},
	{FPDCIDFontSEL, FPDCIDFontGlyphFromCharCodeSEL, L"FPDCIDFontGlyphFromCharCode"},
	{FPDCIDFontSEL, FPDCIDFontIsUnicodeCompatibleSEL, L"FPDCIDFontIsUnicodeCompatible"},
	{FPDCIDFontSEL, FPDCIDFontGetNextCharSEL, L"FPDCIDFontGetNextChar"},
	{FPDCIDFontSEL, FPDCIDFontCountCharSEL, L"FPDCIDFontCountChar"},
	{FPDCIDFontSEL, FPDCIDFontAppendCharSEL, L"FPDCIDFontAppendChar"},
	{FPDCIDFontSEL, FPDCIDFontGetCharSizeSEL, L"FPDCIDFontGetCharSize"},
	{FPDCIDFontSEL, FPDCIDFontLoadGB2312SEL, L"FPDCIDFontLoadGB2312"},
	{FPDCIDFontSEL, FPDCIDFontCIDFromCharCodeSEL, L"FPDCIDFontCIDFromCharCode"},
	{FPDCIDFontSEL, FPDCIDFontIsTrueTypeSEL, L"FPDCIDFontIsTrueType"},
	{FPDCIDFontSEL, FPDCIDFontGetCharsetSEL, L"FPDCIDFontGetCharset"},
	{FPDCIDFontSEL, FPDCIDFontGetCIDTransformSEL, L"FPDCIDFontGetCIDTransform"},
	{FPDCIDFontSEL, FPDCIDFontIsVertWritingSEL, L"FPDCIDFontIsVertWriting"},
	{FPDCIDFontSEL, FPDCIDFontGetVertWidthSEL, L"FPDCIDFontGetVertWidth"},
	{FPDCIDFontSEL, FPDCIDFontGetVertOriginSEL, L"FPDCIDFontGetVertOrigin"},
	{FPDCIDUtilSEL, FPDCIDUtilIsVerticalJapanCIDSEL, L"FPDCIDUtilIsVerticalJapanCID"},
	{FPDColorSpaceSEL, FPDColorSpaceGetStockCSSEL, L"FPDColorSpaceGetStockCS"},
	{FPDColorSpaceSEL, FPDColorSpaceLoadSEL, L"FPDColorSpaceLoad"},
	{FPDColorSpaceSEL, FPDColorSpaceReleaseCSSEL, L"FPDColorSpaceReleaseCS"},
	{FPDColorSpaceSEL, FPDColorSpaceGetBufSizeSEL, L"FPDColorSpaceGetBufSize"},
	{FPDColorSpaceSEL, FPDColorSpaceCreateBufSEL, L"FPDColorSpaceCreateBuf"},
	{FPDColorSpaceSEL, FPDColorSpaceGetDefaultColorSEL, L"FPDColorSpaceGetDefaultColor"},
	{FPDColorSpaceSEL, FPDColorSpaceCountComponentsSEL, L"FPDColorSpaceCountComponents"},
	{FPDColorSpaceSEL, FPDColorSpaceGetFamilySEL, L"FPDColorSpaceGetFamily"},
	{FPDColorSpaceSEL, FPDColorSpaceGetDefaultValueSEL, L"FPDColorSpaceGetDefaultValue"},
	{FPDColorSpaceSEL, FPDColorSpacesRGBSEL, L"FPDColorSpacesRGB"},
	{FPDColorSpaceSEL, FPDColorSpaceGetRGBSEL, L"FPDColorSpaceGetRGB"},
	{FPDColorSpaceSEL, FPDColorSpaceSetRGBSEL, L"FPDColorSpaceSetRGB"},
	{FPDColorSpaceSEL, FPDColorSpaceGetCMYKSEL, L"FPDColorSpaceGetCMYK"},
	{FPDColorSpaceSEL, FPDColorSpaceSetCMYKSEL, L"FPDColorSpaceSetCMYK"},
	{FPDColorSpaceSEL, FPDColorSpaceTranslateImageLineSEL, L"FPDColorSpaceTranslateImageLine"},
	{FPDColorSpaceSEL, FPDColorSpaceGetArraySEL, L"FPDColorSpaceGetArray"},
	{FPDColorSpaceSEL, FPDColorSpaceGetMaxIndexSEL, L"FPDColorSpaceGetMaxIndex"},
	{FPDColorSpaceSEL, FPDColorSpaceGetBaseCSSEL, L"FPDColorSpaceGetBaseCS"},
	{FPDColorSEL, FPDColorNewSEL, L"FPDColorNew"},
	{FPDColorSEL, FPDColorDestroySEL, L"FPDColorDestroy"},
	{FPDColorSEL, FPDColorIsNullSEL, L"FPDColorIsNull"},
	{FPDColorSEL, FPDColorIsEqualSEL, L"FPDColorIsEqual"},
	{FPDColorSEL, FPDColorIsPatternSEL, L"FPDColorIsPattern"},
	{FPDColorSEL, FPDColorCopySEL, L"FPDColorCopy"},
	{FPDColorSEL, FPDColorSetColorSpaceSEL, L"FPDColorSetColorSpace"},
	{FPDColorSEL, FPDColorGetColorSpaceSEL, L"FPDColorGetColorSpace"},
	{FPDColorSEL, FPDColorSetValueSEL, L"FPDColorSetValue"},
	{FPDColorSEL, FPDColorSetValue2SEL, L"FPDColorSetValue2"},
	{FPDColorSEL, FPDColorGetRGBSEL, L"FPDColorGetRGB"},
	{FPDColorSEL, FPDColorGetPatternSEL, L"FPDColorGetPattern"},
	{FPDColorSEL, FPDColorGetPatternCSSEL, L"FPDColorGetPatternCS"},
	{FPDColorSEL, FPDColorGetPatternColorSEL, L"FPDColorGetPatternColor"},
	{FPDColorSEL, FPDColorGetColorBufferSEL, L"FPDColorGetColorBuffer"},
	{FPDPatternSEL, FPDPatternDestroySEL, L"FPDPatternDestroy"},
	{FPDPatternSEL, FPDPatternGetPatternObjSEL, L"FPDPatternGetPatternObj"},
	{FPDPatternSEL, FPDPatternGetPatternTypeSEL, L"FPDPatternGetPatternType"},
	{FPDPatternSEL, FPDPatternGetPatternMatrixSEL, L"FPDPatternGetPatternMatrix"},
	{FPDPatternSEL, FPDPatternGetPDDocSEL, L"FPDPatternGetPDDoc"},
	{FPDPatternSEL, FPDPatternCastToShadingPatternObjSEL, L"FPDPatternCastToShadingPatternObj"},
	{FPDPatternSEL, FPDPatternCastToTilingPatternObjSEL, L"FPDPatternCastToTilingPatternObj"},
	{FPDTilingPatternSEL, FPDTilingPatternNewSEL, L"FPDTilingPatternNew"},
	{FPDTilingPatternSEL, FPDTilingPatternDestroySEL, L"FPDTilingPatternDestroy"},
	{FPDTilingPatternSEL, FPDTilingPatternGetPatternObjSEL, L"FPDTilingPatternGetPatternObj"},
	{FPDTilingPatternSEL, FPDTilingPatternGetPatternTypeSEL, L"FPDTilingPatternGetPatternType"},
	{FPDTilingPatternSEL, FPDTilingPatternGetPatternMatrixSEL, L"FPDTilingPatternGetPatternMatrix"},
	{FPDTilingPatternSEL, FPDTilingPatternGetPDDocSEL, L"FPDTilingPatternGetPDDoc"},
	{FPDTilingPatternSEL, FPDTilingPatternLoadSEL, L"FPDTilingPatternLoad"},
	{FPDTilingPatternSEL, FPDTilingPatternIsColoredSEL, L"FPDTilingPatternIsColored"},
	{FPDTilingPatternSEL, FPDTilingPatternGetBBoxSEL, L"FPDTilingPatternGetBBox"},
	{FPDTilingPatternSEL, FPDTilingPatternGetXStepSEL, L"FPDTilingPatternGetXStep"},
	{FPDTilingPatternSEL, FPDTilingPatternGetYStepSEL, L"FPDTilingPatternGetYStep"},
	{FPDTilingPatternSEL, FPDTilingPatternGetFormSEL, L"FPDTilingPatternGetForm"},
	{FPDTilingPatternSEL, FPDTilingPatternNewIISEL, L"FPDTilingPatternNewII"},
	{FPDShadingPatternSEL, FPDShadingPatternNewSEL, L"FPDShadingPatternNew"},
	{FPDShadingPatternSEL, FPDShadingPatternDestroySEL, L"FPDShadingPatternDestroy"},
	{FPDShadingPatternSEL, FPDShadingPatternGetPatternObjSEL, L"FPDShadingPatternGetPatternObj"},
	{FPDShadingPatternSEL, FPDShadingPatternGetPatternTypeSEL, L"FPDShadingPatternGetPatternType"},
	{FPDShadingPatternSEL, FPDShadingPatternGetPatternMatrixSEL, L"FPDShadingPatternGetPatternMatrix"},
	{FPDShadingPatternSEL, FPDShadingPatternGetPDDocSEL, L"FPDShadingPatternGetPDDoc"},
	{FPDShadingPatternSEL, FPDShadingPatternLoadSEL, L"FPDShadingPatternLoad"},
	{FPDShadingPatternSEL, FPDShadingPatternReLoadSEL, L"FPDShadingPatternReLoad"},
	{FPDShadingPatternSEL, FPDShadingPatternGetColorSpaceSEL, L"FPDShadingPatternGetColorSpace"},
	{FPDShadingPatternSEL, FPDShadingPatternGetFuncSEL, L"FPDShadingPatternGetFunc"},
	{FPDShadingPatternSEL, FPDShadingPatternGetFuncsCountSEL, L"FPDShadingPatternGetFuncsCount"},
	{FPDShadingPatternSEL, FPDShadingPatternSetColorSpaceSEL, L"FPDShadingPatternSetColorSpace"},
	{FPDShadingPatternSEL, FPDShadingPatternGetShadingObjectSEL, L"FPDShadingPatternGetShadingObject"},
	{FPDMeshStreamSEL, FPDMeshStreamNewSEL, L"FPDMeshStreamNew"},
	{FPDMeshStreamSEL, FPDMeshStreamDestroySEL, L"FPDMeshStreamDestroy"},
	{FPDMeshStreamSEL, FPDMeshStreamGetFlagSEL, L"FPDMeshStreamGetFlag"},
	{FPDMeshStreamSEL, FPDMeshStreamGetCoordsSEL, L"FPDMeshStreamGetCoords"},
	{FPDMeshStreamSEL, FPDMeshStreamGetColorSEL, L"FPDMeshStreamGetColor"},
	{FPDMeshStreamSEL, FPDMeshStreamGetVertexSEL, L"FPDMeshStreamGetVertex"},
	{FPDMeshStreamSEL, FPDMeshStreamGetVertexRowSEL, L"FPDMeshStreamGetVertexRow"},
	{FPDImageSEL, FPDImageNewSEL, L"FPDImageNew"},
	{FPDImageSEL, FPDImageDestroySEL, L"FPDImageDestroy"},
	{FPDImageSEL, FPDImageLoadImageFSEL, L"FPDImageLoadImageF"},
	{FPDImageSEL, FPDImageCloneSEL, L"FPDImageClone"},
	{FPDImageSEL, FPDImageGetStreamSEL, L"FPDImageGetStream"},
	{FPDImageSEL, FPDImageGetDictSEL, L"FPDImageGetDict"},
	{FPDImageSEL, FPDImageGetOCSEL, L"FPDImageGetOC"},
	{FPDImageSEL, FPDImageGetDocumentSEL, L"FPDImageGetDocument"},
	{FPDImageSEL, FPDImageGetPixelHeightSEL, L"FPDImageGetPixelHeight"},
	{FPDImageSEL, FPDImageGetPixelWidthSEL, L"FPDImageGetPixelWidth"},
	{FPDImageSEL, FPDImageIsMaskSEL, L"FPDImageIsMask"},
	{FPDImageSEL, FPDImageIsInterpolSEL, L"FPDImageIsInterpol"},
	{FPDImageSEL, FPDImageLoadDIBitmapSEL, L"FPDImageLoadDIBitmap"},
	{FPDImageSEL, FPDImageSetImageSEL, L"FPDImageSetImage"},
	{FPDImageSEL, FPDImageSetJpegImageSEL, L"FPDImageSetJpegImage"},
	{FPDImageSEL, FPDImageResetCacheSEL, L"FPDImageResetCache"},
	{FPDImageSEL, FPDImageLoadDIBitmapProgressiveSEL, L"FPDImageLoadDIBitmapProgressive"},
	{FPDImageSEL, FPDImageGetDIBSourceSEL, L"FPDImageGetDIBSource"},
	{FPDImageSEL, FPDImageGetMaskSEL, L"FPDImageGetMask"},
	{FPDImageSEL, FPDImageGetMatteColorSEL, L"FPDImageGetMatteColor"},
	{FPDImageSEL, FPDImageSetImage2SEL, L"FPDImageSetImage2"},
	{FPDImageSEL, FPDImageDetachBitmapSEL, L"FPDImageDetachBitmap"},
	{FPDImageSEL, FPDImageDetachMaskSEL, L"FPDImageDetachMask"},
	{FPDImageSEL, FPDImageGetInlineDictSEL, L"FPDImageGetInlineDict"},
	{FPDImageSEL, FPDImageGetDIBSource2SEL, L"FPDImageGetDIBSource2"},
	{FPDImageSEL, FPDImageGetMask2SEL, L"FPDImageGetMask2"},
	{FPDImageSEL, FPDImageDetachBitmap2SEL, L"FPDImageDetachBitmap2"},
	{FPDImageSEL, FPDImageDetachMask2SEL, L"FPDImageDetachMask2"},
	{FPDImageSEL, FPDImageLoadDIBitmap2SEL, L"FPDImageLoadDIBitmap2"},
	{FPDImageSEL, FPDImageIsInlineSEL, L"FPDImageIsInline"},
	{FPDImageSEL, FPDImageReleaseSEL, L"FPDImageRelease"},
	{FPDImageSEL, FPDImageSetJpegImage2SEL, L"FPDImageSetJpegImage2"},
	{FPDImageSEL, FPDImageSetPngFileReadSEL, L"FPDImageSetPngFileRead"},
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverNewSEL, L"FPDObjArchiveSaverNew"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverDestroySEL, L"FPDObjArchiveSaverDestroy"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverSaveObjectSEL, L"FPDObjArchiveSaverSaveObject"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverGetLengthSEL, L"FPDObjArchiveSaverGetLength"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverGetBufferSEL, L"FPDObjArchiveSaverGetBuffer"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverSaveByteSEL, L"FPDObjArchiveSaverSaveByte"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverSaveIntegerSEL, L"FPDObjArchiveSaverSaveInteger"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverSaveDWORDSEL, L"FPDObjArchiveSaverSaveDWORD"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverSaveFloatSEL, L"FPDObjArchiveSaverSaveFloat"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverSaveByteStringSEL, L"FPDObjArchiveSaverSaveByteString"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverSaveWideStringSEL, L"FPDObjArchiveSaverSaveWideString"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverSaveWideStringIISEL, L"FPDObjArchiveSaverSaveWideStringII"},
	{FPDObjArchiveSaverSEL, FPDObjArchiveSaverWriteSEL, L"FPDObjArchiveSaverWrite"},
	{FPDObjArchiveLoaderSEL, FPDObjArchiveLoaderNewSEL, L"FPDObjArchiveLoaderNew"},
	{FPDObjArchiveLoaderSEL, FPDObjArchiveLoaderDestroySEL, L"FPDObjArchiveLoaderDestroy"},
	{FPDObjArchiveLoaderSEL, FPDObjArchiveLoaderLoadObjectSEL, L"FPDObjArchiveLoaderLoadObject"},
	{FPDObjArchiveLoaderSEL, FPDObjArchiveLoaderIsEOFSEL, L"FPDObjArchiveLoaderIsEOF"},
	{FPDObjArchiveLoaderSEL, FPDObjArchiveLoaderReadSEL, L"FPDObjArchiveLoaderRead"},
	{FPDObjArchiveLoaderSEL, FPDObjArchiveLoaderLoadByteSEL, L"FPDObjArchiveLoaderLoadByte"},
	{FPDObjArchiveLoaderSEL, FPDObjArchiveLoaderLoadIntegerSEL, L"FPDObjArchiveLoaderLoadInteger"},
	{FPDObjArchiveLoaderSEL, FPDObjArchiveLoaderLoadDWORDSEL, L"FPDObjArchiveLoaderLoadDWORD"},
	{FPDObjArchiveLoaderSEL, FPDObjArchiveLoaderLoadFloatSEL, L"FPDObjArchiveLoaderLoadFloat"},
	{FPDObjArchiveLoaderSEL, FPDObjArchiveLoaderLoadByteStringSEL, L"FPDObjArchiveLoaderLoadByteString"},
	{FPDObjArchiveLoaderSEL, FPDObjArchiveLoaderLoadWideStringSEL, L"FPDObjArchiveLoaderLoadWideString"},
	{FPDPageArchiveSaverSEL, FPDPageArchiveSaverNewSEL, L"FPDPageArchiveSaverNew"},
	{FPDPageArchiveSaverSEL, FPDPageArchiveSaverDestroySEL, L"FPDPageArchiveSaverDestroy"},
	{FPDPageArchiveSaverSEL, FPDPageArchiveSaverSavePageObjectSEL, L"FPDPageArchiveSaverSavePageObject"},
	{FPDPageArchiveSaverSEL, FPDPageArchiveSaverSaveClipPathSEL, L"FPDPageArchiveSaverSaveClipPath"},
	{FPDPageArchiveSaverSEL, FPDPageArchiveSaverSaveGraphStateSEL, L"FPDPageArchiveSaverSaveGraphState"},
	{FPDPageArchiveSaverSEL, FPDPageArchiveSaverSaveTextStateSEL, L"FPDPageArchiveSaverSaveTextState"},
	{FPDPageArchiveSaverSEL, FPDPageArchiveSaverSaveColorStateSEL, L"FPDPageArchiveSaverSaveColorState"},
	{FPDPageArchiveSaverSEL, FPDPageArchiveSaverSaveGeneralStateSEL, L"FPDPageArchiveSaverSaveGeneralState"},
	{FPDPageArchiveSaverSEL, FPDPageArchiveSaverNew2SEL, L"FPDPageArchiveSaverNew2"},
	{FPDPageArchiveSaverSEL, FPDPageArchiveSaverSetStreamSEL, L"FPDPageArchiveSaverSetStream"},
	{FPDPageArchiveLoaderSEL, FPDPageArchiveLoaderNewSEL, L"FPDPageArchiveLoaderNew"},
	{FPDPageArchiveLoaderSEL, FPDPageArchiveLoaderDestroySEL, L"FPDPageArchiveLoaderDestroy"},
	{FPDPageArchiveLoaderSEL, FPDPageArchiveLoaderLoadObjectSEL, L"FPDPageArchiveLoaderLoadObject"},
	{FPDPageArchiveLoaderSEL, FPDPageArchiveLoaderLoadClipPathSEL, L"FPDPageArchiveLoaderLoadClipPath"},
	{FPDPageArchiveLoaderSEL, FPDPageArchiveLoaderLoadGraphStateSEL, L"FPDPageArchiveLoaderLoadGraphState"},
	{FPDPageArchiveLoaderSEL, FPDPageArchiveLoaderLoadTextStateSEL, L"FPDPageArchiveLoaderLoadTextState"},
	{FPDPageArchiveLoaderSEL, FPDPageArchiveLoaderLoadColorStateSEL, L"FPDPageArchiveLoaderLoadColorState"},
	{FPDPageArchiveLoaderSEL, FPDPageArchiveLoaderLoadGeneralStateSEL, L"FPDPageArchiveLoaderLoadGeneralState"},
	{FPDPageArchiveLoaderSEL, FPDPageArchiveLoaderNew2SEL, L"FPDPageArchiveLoaderNew2"},
	{FPDCreatorSEL, FPDCreatorNewSEL, L"FPDCreatorNew"},
	{FPDCreatorSEL, FPDCreatorDestroySEL, L"FPDCreatorDestroy"},
	{FPDCreatorSEL, FPDCreatorCompressSEL, L"FPDCreatorCompress"},
	{FPDCreatorSEL, FPDCreatorSetStandardSecuritySEL, L"FPDCreatorSetStandardSecurity"},
	{FPDCreatorSEL, FPDCreatorModifyR5SecuritySEL, L"FPDCreatorModifyR5Security"},
	{FPDCreatorSEL, FPDCreatorSetCustomSecuritySEL, L"FPDCreatorSetCustomSecurity"},
	{FPDCreatorSEL, FPDCreatorReleaseCustomSecurityDataSEL, L"FPDCreatorReleaseCustomSecurityData"},
	{FPDCreatorSEL, FPDCreatorRemoveSecuritySEL, L"FPDCreatorRemoveSecurity"},
	{FPDCreatorSEL, FPDCreatorCreateSEL, L"FPDCreatorCreate"},
	{FPDCreatorSEL, FPDCreatorCreate2SEL, L"FPDCreatorCreate2"},
	{FPDCreatorSEL, FPDCreatorCreate3SEL, L"FPDCreatorCreate3"},
	{FPDCreatorSEL, FPDCreatorGetObjectOffsetSEL, L"FPDCreatorGetObjectOffset"},
	{FPDCreatorSEL, FPDCreatorGetObjectSizeSEL, L"FPDCreatorGetObjectSize"},
	{FPDCreatorSEL, FPDCreatorSetProgressiveEncryptHandlerSEL, L"FPDCreatorSetProgressiveEncryptHandler"},
	{FPDCreatorSEL, FPDCreatorReleaseProgressiveEncryptHandlerSEL, L"FPDCreatorReleaseProgressiveEncryptHandler"},
	{FPDCreatorSEL, FPDCreatorSetOptionSEL, L"FPDCreatorSetOption"},
	{FPDCreatorSEL, FPDCreatorReleaseOptionSEL, L"FPDCreatorReleaseOption"},
	{FPDCreatorSEL, FPDCreatorDeprecatedSetDRMSecuritySEL, L"FPDCreatorDeprecatedSetDRMSecurity"},
	{FPDCreatorSEL, FPDCreatorDeprecatedReleaseDRMSecurityDataSEL, L"FPDCreatorDeprecatedReleaseDRMSecurityData"},
	{FPDCreatorSEL, FPDCreatorDeprecatedSetDRMProgressiveEncryptHandlerSEL, L"FPDCreatorDeprecatedSetDRMProgressiveEncryptHandler"},
	{FPDCreatorSEL, FPDCreatorDeprecatedReleaseDRMProgressiveEncryptHandlerSEL, L"FPDCreatorDeprecatedReleaseDRMProgressiveEncryptHandler"},
	{FPDCreatorSEL, FPDCreatorSetProgressiveEncryptHandler2SEL, L"FPDCreatorSetProgressiveEncryptHandler2"},
	{FPDCreatorSEL, FPDCreatorSetCustomSecurity2SEL, L"FPDCreatorSetCustomSecurity2"},
	{FPDCreatorSEL, FPDCreatorSetCustomSecurity3SEL, L"FPDCreatorSetCustomSecurity3"},
	{FPDCreatorSEL, FPDCreatorAttachUncompressObjectsSEL, L"FPDCreatorAttachUncompressObjects"},
	{FPDCreatorSEL, FPDCreatorGetStandardLinearizationObjSEL, L"FPDCreatorGetStandardLinearizationObj"},
	{FPDCreatorSEL, FPDCreatorCreate4SEL, L"FPDCreatorCreate4"},
	{FPDCreatorSEL, FPDCreatorSetStandardSecurity2SEL, L"FPDCreatorSetStandardSecurity2"},
	{FPDCreatorSEL, FPDCreatorModifyR5Security2SEL, L"FPDCreatorModifyR5Security2"},
	{FPDCreatorSEL, FPDCreatorAttachIgnoredObjectsSEL, L"FPDCreatorAttachIgnoredObjects"},
	{FPDCreatorSEL, FPDCreatorSetAESV4GCMSecuritySEL, L"FPDCreatorSetAESV4GCMSecurity"},
// fpd_serialImpl.h end

// In file fpd_textImpl.h
	{FPDProgressiveSearchSEL, FPDProgressiveSearchNewSEL, L"FPDProgressiveSearchNew"},
	{FPDProgressiveSearchSEL, FPDProgressiveSearchDestroySEL, L"FPDProgressiveSearchDestroy"},
	{FPDProgressiveSearchSEL, FPDProgressiveSearchGetStatusSEL, L"FPDProgressiveSearchGetStatus"},
	{FPDProgressiveSearchSEL, FPDProgressiveSearchFindFromSEL, L"FPDProgressiveSearchFindFrom"},
	{FPDProgressiveSearchSEL, FPDProgressiveSearchContinueSEL, L"FPDProgressiveSearchContinue"},
	{FPDProgressiveSearchSEL, FPDProgressiveSearchFindNextSEL, L"FPDProgressiveSearchFindNext"},
	{FPDProgressiveSearchSEL, FPDProgressiveSearchFindPrevSEL, L"FPDProgressiveSearchFindPrev"},
	{FPDProgressiveSearchSEL, FPDProgressiveSearchCountRectsSEL, L"FPDProgressiveSearchCountRects"},
	{FPDProgressiveSearchSEL, FPDProgressiveSearchGetRectSEL, L"FPDProgressiveSearchGetRect"},
	{FPDProgressiveSearchSEL, FPDProgressiveSearchGetPosSEL, L"FPDProgressiveSearchGetPos"},
	{FPDTextPageSEL, FPDTextPageNewSEL, L"FPDTextPageNew"},
	{FPDTextPageSEL, FPDTextPageDestroySEL, L"FPDTextPageDestroy"},
	{FPDTextPageSEL, FPDTextPageParseTextPageSEL, L"FPDTextPageParseTextPage"},
	{FPDTextPageSEL, FPDTextPageIsParseredSEL, L"FPDTextPageIsParsered"},
	{FPDTextPageSEL, FPDTextPageCountCharsSEL, L"FPDTextPageCountChars"},
	{FPDTextPageSEL, FPDTextPageGetCharInfoSEL, L"FPDTextPageGetCharInfo"},
	{FPDTextPageSEL, FPDTextPageGetRectArraySEL, L"FPDTextPageGetRectArray"},
	{FPDTextPageSEL, FPDTextPageGetIndexAtPosSEL, L"FPDTextPageGetIndexAtPos"},
	{FPDTextPageSEL, FPDTextPageGetOrderByDirectionSEL, L"FPDTextPageGetOrderByDirection"},
	{FPDTextPageSEL, FPDTextPageGetTextByRectSEL, L"FPDTextPageGetTextByRect"},
	{FPDTextPageSEL, FPDTextPageGetRectsArrayByRectSEL, L"FPDTextPageGetRectsArrayByRect"},
	{FPDTextPageSEL, FPDTextPageCountRectsSEL, L"FPDTextPageCountRects"},
	{FPDTextPageSEL, FPDTextPageGetRectSEL, L"FPDTextPageGetRect"},
	{FPDTextPageSEL, FPDTextPageCountBoundedSegmentsSEL, L"FPDTextPageCountBoundedSegments"},
	{FPDTextPageSEL, FPDTextPageGetBoundedSegmentSEL, L"FPDTextPageGetBoundedSegment"},
	{FPDTextPageSEL, FPDTextPageGetWordBreakSEL, L"FPDTextPageGetWordBreak"},
	{FPDTextPageSEL, FPDTextPageGetPageTextSEL, L"FPDTextPageGetPageText"},
	{FPDTextPageSEL, FPDTextPageGetUnicodePropertiesSEL, L"FPDTextPageGetUnicodeProperties"},
	{FPDTextPageSEL, FPDTextPageNew2SEL, L"FPDTextPageNew2"},
	{FPDTextPageSEL, FPDTextPageNew3SEL, L"FPDTextPageNew3"},
	{FPDTextPageSEL, FPDTextPageGetRectArray2SEL, L"FPDTextPageGetRectArray2"},
	{FPDTextPageSEL, FPDTextPageCharIndexFromTextIndexSEL, L"FPDTextPageCharIndexFromTextIndex"},
	{FPDTextPageSEL, FPDTextPageTextIndexFromCharIndexSEL, L"FPDTextPageTextIndexFromCharIndex"},
	{FPDTextPageSEL, FPDTextPageGetRectArrayPathDataSEL, L"FPDTextPageGetRectArrayPathData"},
	{FPDTextPageFindSEL, FPDTextPageFindNewSEL, L"FPDTextPageFindNew"},
	{FPDTextPageFindSEL, FPDTextPageFindDestroySEL, L"FPDTextPageFindDestroy"},
	{FPDTextPageFindSEL, FPDTextPageFindFindFirstSEL, L"FPDTextPageFindFindFirst"},
	{FPDTextPageFindSEL, FPDTextPageFindFindNextSEL, L"FPDTextPageFindFindNext"},
	{FPDTextPageFindSEL, FPDTextPageFindFindPrevSEL, L"FPDTextPageFindFindPrev"},
	{FPDTextPageFindSEL, FPDTextPageFindGetRectArraySEL, L"FPDTextPageFindGetRectArray"},
	{FPDTextPageFindSEL, FPDTextPageFindGetCurOrderSEL, L"FPDTextPageFindGetCurOrder"},
	{FPDTextPageFindSEL, FPDTextPageFindGetMatchedCountSEL, L"FPDTextPageFindGetMatchedCount"},
	{FPDTextPageFindSEL, FPDTextPageFindGetRectPathDataSEL, L"FPDTextPageFindGetRectPathData"},
	{FPDTextPageFindSEL, FPDTextPageFindReleasePathDataSEL, L"FPDTextPageFindReleasePathData"},
	{FPDLinkExtractSEL, FPDLinkExtractNewSEL, L"FPDLinkExtractNew"},
	{FPDLinkExtractSEL, FPDLinkExtractDestroySEL, L"FPDLinkExtractDestroy"},
	{FPDLinkExtractSEL, FPDLinkExtractExtractLinksSEL, L"FPDLinkExtractExtractLinks"},
	{FPDLinkExtractSEL, FPDLinkExtractCountLinksSEL, L"FPDLinkExtractCountLinks"},
	{FPDLinkExtractSEL, FPDLinkExtractGetURLSEL, L"FPDLinkExtractGetURL"},
	{FPDLinkExtractSEL, FPDLinkExtractGetRectsSEL, L"FPDLinkExtractGetRects"},
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V2----------
// In file fs_basicImpl.h
	{FSBase64EncoderSEL, FSBase64EncoderNewSEL, L"FSBase64EncoderNew"},
	{FSBase64EncoderSEL, FSBase64EncoderDestroySEL, L"FSBase64EncoderDestroy"},
	{FSBase64EncoderSEL, FSBase64EncoderSetEncoderSEL, L"FSBase64EncoderSetEncoder"},
	{FSBase64EncoderSEL, FSBase64EncoderEncodeSEL, L"FSBase64EncoderEncode"},
	{FSBase64EncoderSEL, FSBase64EncoderEncode2SEL, L"FSBase64EncoderEncode2"},
	{FSBase64EncoderSEL, FSBase64EncoderEncode3SEL, L"FSBase64EncoderEncode3"},
	{FSBase64DecoderSEL, FSBase64DecoderNewSEL, L"FSBase64DecoderNew"},
	{FSBase64DecoderSEL, FSBase64DecoderDestroySEL, L"FSBase64DecoderDestroy"},
	{FSBase64DecoderSEL, FSBase64DecoderSetDecoderSEL, L"FSBase64DecoderSetDecoder"},
	{FSBase64DecoderSEL, FSBase64DecoderDecodeSEL, L"FSBase64DecoderDecode"},
	{FSBase64DecoderSEL, FSBase64DecoderDecode2SEL, L"FSBase64DecoderDecode2"},
	{FSBase64DecoderSEL, FSBase64DecoderDecode3SEL, L"FSBase64DecoderDecode3"},
	{FSFileWriteHandlerSEL, FSFileWriteHandlerNewSEL, L"FSFileWriteHandlerNew"},
	{FSFileWriteHandlerSEL, FSFileWriteHandlerDestroySEL, L"FSFileWriteHandlerDestroy"},
	{FSFileWriteHandlerSEL, FSFileWriteHandlerNew2SEL, L"FSFileWriteHandlerNew2"},
	{FSFileWriteHandlerSEL, FSFileWriteHandlerReleaseSEL, L"FSFileWriteHandlerRelease"},
	{FSFileWriteHandlerSEL, FSFileWriteHandlerGetSizeSEL, L"FSFileWriteHandlerGetSize"},
	{FSFileWriteHandlerSEL, FSFileWriteHandlerFlushSEL, L"FSFileWriteHandlerFlush"},
	{FSFileWriteHandlerSEL, FSFileWriteHandlerWriteBlockSEL, L"FSFileWriteHandlerWriteBlock"},
	{FSFileWriteHandlerSEL, FSFileWriteHandlerWriteBlock2SEL, L"FSFileWriteHandlerWriteBlock2"},
	{FSXMLElementSEL, FSXMLElementparseSEL, L"FSXMLElementparse"},
	{FSXMLElementSEL, FSXMLElementparse2SEL, L"FSXMLElementparse2"},
	{FSXMLElementSEL, FSXMLElementNewSEL, L"FSXMLElementNew"},
	{FSXMLElementSEL, FSXMLElementNew2SEL, L"FSXMLElementNew2"},
	{FSXMLElementSEL, FSXMLElementNew3SEL, L"FSXMLElementNew3"},
	{FSXMLElementSEL, FSXMLElementDestroySEL, L"FSXMLElementDestroy"},
	{FSXMLElementSEL, FSXMLElementGetTagNameSEL, L"FSXMLElementGetTagName"},
	{FSXMLElementSEL, FSXMLElementGetNamespaceSEL, L"FSXMLElementGetNamespace"},
	{FSXMLElementSEL, FSXMLElementGetNamespaceURISEL, L"FSXMLElementGetNamespaceURI"},
	{FSXMLElementSEL, FSXMLElementGetParentSEL, L"FSXMLElementGetParent"},
	{FSXMLElementSEL, FSXMLElementCountAttrsSEL, L"FSXMLElementCountAttrs"},
	{FSXMLElementSEL, FSXMLElementGetAttrByIndexSEL, L"FSXMLElementGetAttrByIndex"},
	{FSXMLElementSEL, FSXMLElementHasAttrSEL, L"FSXMLElementHasAttr"},
	{FSXMLElementSEL, FSXMLElementGetAttrValueSEL, L"FSXMLElementGetAttrValue"},
	{FSXMLElementSEL, FSXMLElementGetAttrValue2SEL, L"FSXMLElementGetAttrValue2"},
	{FSXMLElementSEL, FSXMLElementGetAttrIntegerSEL, L"FSXMLElementGetAttrInteger"},
	{FSXMLElementSEL, FSXMLElementGetAttrInteger2SEL, L"FSXMLElementGetAttrInteger2"},
	{FSXMLElementSEL, FSXMLElementGetAttrFloatSEL, L"FSXMLElementGetAttrFloat"},
	{FSXMLElementSEL, FSXMLElementGetAttrFloat2SEL, L"FSXMLElementGetAttrFloat2"},
	{FSXMLElementSEL, FSXMLElementCountChildrenSEL, L"FSXMLElementCountChildren"},
	{FSXMLElementSEL, FSXMLElementGetChildTypeSEL, L"FSXMLElementGetChildType"},
	{FSXMLElementSEL, FSXMLElementGetContentSEL, L"FSXMLElementGetContent"},
	{FSXMLElementSEL, FSXMLElementGetElementSEL, L"FSXMLElementGetElement"},
	{FSXMLElementSEL, FSXMLElementGetElement2SEL, L"FSXMLElementGetElement2"},
	{FSXMLElementSEL, FSXMLElementGetElement3SEL, L"FSXMLElementGetElement3"},
	{FSXMLElementSEL, FSXMLElementCountElementsSEL, L"FSXMLElementCountElements"},
	{FSXMLElementSEL, FSXMLElementFindElementSEL, L"FSXMLElementFindElement"},
	{FSXMLElementSEL, FSXMLElementSetTagSEL, L"FSXMLElementSetTag"},
	{FSXMLElementSEL, FSXMLElementSetTag2SEL, L"FSXMLElementSetTag2"},
	{FSXMLElementSEL, FSXMLElementSetAttrValueSEL, L"FSXMLElementSetAttrValue"},
	{FSXMLElementSEL, FSXMLElementSetAttrValue2SEL, L"FSXMLElementSetAttrValue2"},
	{FSXMLElementSEL, FSXMLElementSetAttrValue3SEL, L"FSXMLElementSetAttrValue3"},
	{FSXMLElementSEL, FSXMLElementRemoveAttrSEL, L"FSXMLElementRemoveAttr"},
	{FSXMLElementSEL, FSXMLElementAddChildElementSEL, L"FSXMLElementAddChildElement"},
	{FSXMLElementSEL, FSXMLElementAddChildContentSEL, L"FSXMLElementAddChildContent"},
	{FSXMLElementSEL, FSXMLElementInsertChildElementSEL, L"FSXMLElementInsertChildElement"},
	{FSXMLElementSEL, FSXMLElementInsertChildContentSEL, L"FSXMLElementInsertChildContent"},
	{FSXMLElementSEL, FSXMLElementRemoveChildrenSEL, L"FSXMLElementRemoveChildren"},
	{FSXMLElementSEL, FSXMLElementRemoveChildSEL, L"FSXMLElementRemoveChild"},
	{FSXMLElementSEL, FSXMLElementOutputStreamSEL, L"FSXMLElementOutputStream"},
	{FSXMLElementSEL, FSXMLElementOutputStream2SEL, L"FSXMLElementOutputStream2"},
	{FSXMLElementSEL, FSXMLElementCloneSEL, L"FSXMLElementClone"},
	{FSXMLElementSEL, FSXMLElementparse3SEL, L"FSXMLElementparse3"},
	{FSXMLElementSEL, FSXMLElementparse4SEL, L"FSXMLElementparse4"},
	{FSXMLElementSEL, FSXMLElementOutputStream3SEL, L"FSXMLElementOutputStream3"},
	{FSXMLElementSEL, FSXMLElementOutputStream4SEL, L"FSXMLElementOutputStream4"},
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
	{FDRMCategoryReadSEL, FDRMCategoryReadCountSubCategoriesSEL, L"FDRMCategoryReadCountSubCategories"},
	{FDRMCategoryReadSEL, FDRMCategoryReadGetSubCategorySEL, L"FDRMCategoryReadGetSubCategory"},
	{FDRMCategoryReadSEL, FDRMCategoryReadFindSubCategorySEL, L"FDRMCategoryReadFindSubCategory"},
	{FDRMCategoryReadSEL, FDRMCategoryReadGetParentCategorySEL, L"FDRMCategoryReadGetParentCategory"},
	{FDRMCategoryReadSEL, FDRMCategoryReadGetCategoryNameSEL, L"FDRMCategoryReadGetCategoryName"},
	{FDRMCategoryReadSEL, FDRMCategoryReadCountAttributesSEL, L"FDRMCategoryReadCountAttributes"},
	{FDRMCategoryReadSEL, FDRMCategoryReadGetAttributeSEL, L"FDRMCategoryReadGetAttribute"},
	{FDRMCategoryReadSEL, FDRMCategoryReadGetAttributeValueSEL, L"FDRMCategoryReadGetAttributeValue"},
	{FDRMCategoryReadSEL, FDRMCategoryReadGetCategoryDataSEL, L"FDRMCategoryReadGetCategoryData"},
	{FDRMCategoryReadSEL, FDRMCategoryReadDestroySEL, L"FDRMCategoryReadDestroy"},
	{FDRMCategoryWriteSEL, FDRMCategoryWriteAddCategorySEL, L"FDRMCategoryWriteAddCategory"},
	{FDRMCategoryWriteSEL, FDRMCategoryWriteAddCategory2SEL, L"FDRMCategoryWriteAddCategory2"},
	{FDRMCategoryWriteSEL, FDRMCategoryWriteSetAttributeSEL, L"FDRMCategoryWriteSetAttribute"},
	{FDRMCategoryWriteSEL, FDRMCategoryWriteRemoveAttributeSEL, L"FDRMCategoryWriteRemoveAttribute"},
	{FDRMCategoryWriteSEL, FDRMCategoryWriteSetCategoryDataSEL, L"FDRMCategoryWriteSetCategoryData"},
	{FDRMCategoryWriteSEL, FDRMCategoryWriteRemoveCategorySEL, L"FDRMCategoryWriteRemoveCategory"},
	{FDRMCategoryWriteSEL, FDRMCategoryWriteRemoveCategory2SEL, L"FDRMCategoryWriteRemoveCategory2"},
	{FDRMCategoryWriteSEL, FDRMCategoryWriteRemoveCategory3SEL, L"FDRMCategoryWriteRemoveCategory3"},
	{FDRMCategoryWriteSEL, FDRMCategoryWriteCastToCategoryReadSEL, L"FDRMCategoryWriteCastToCategoryRead"},
	{FDRMCategoryWriteSEL, FDRMCategoryWriteDestroySEL, L"FDRMCategoryWriteDestroy"},
	{FDRMDescDataSEL, FDRMDescDataNewSEL, L"FDRMDescDataNew"},
	{FDRMDescDataSEL, FDRMDescDataDestroySEL, L"FDRMDescDataDestroy"},
	{FDRMDescDataSEL, FDRMDescDataGetPackageNameSEL, L"FDRMDescDataGetPackageName"},
	{FDRMDescDataSEL, FDRMDescDataGetDefNameSpaceSEL, L"FDRMDescDataGetDefNameSpace"},
	{FDRMDescDataSEL, FDRMDescDataGetFDRMNameSpaceSEL, L"FDRMDescDataGetFDRMNameSpace"},
	{FDRMDescDataSEL, FDRMDescDataSetPackageNameSEL, L"FDRMDescDataSetPackageName"},
	{FDRMDescDataSEL, FDRMDescDataSetDefNameSpaceSEL, L"FDRMDescDataSetDefNameSpace"},
	{FDRMDescDataSEL, FDRMDescDataSetFDRMNameSpaceSEL, L"FDRMDescDataSetFDRMNameSpace"},
	{FDRMScriptDataSEL, FDRMScriptDataNewSEL, L"FDRMScriptDataNew"},
	{FDRMScriptDataSEL, FDRMScriptDataDestroySEL, L"FDRMScriptDataDestroy"},
	{FDRMScriptDataSEL, FDRMScriptDataGetDivisionSEL, L"FDRMScriptDataGetDivision"},
	{FDRMScriptDataSEL, FDRMScriptDataGetFormatOrgSEL, L"FDRMScriptDataGetFormatOrg"},
	{FDRMScriptDataSEL, FDRMScriptDataGetFormatVerSEL, L"FDRMScriptDataGetFormatVer"},
	{FDRMScriptDataSEL, FDRMScriptDataGetAppOrgSEL, L"FDRMScriptDataGetAppOrg"},
	{FDRMScriptDataSEL, FDRMScriptDataGetAppVerSEL, L"FDRMScriptDataGetAppVer"},
	{FDRMScriptDataSEL, FDRMScriptDataGetAuthoritySEL, L"FDRMScriptDataGetAuthority"},
	{FDRMScriptDataSEL, FDRMScriptDataSetDivisionSEL, L"FDRMScriptDataSetDivision"},
	{FDRMScriptDataSEL, FDRMScriptDataSetFormatOrgSEL, L"FDRMScriptDataSetFormatOrg"},
	{FDRMScriptDataSEL, FDRMScriptDataSetFormatVerSEL, L"FDRMScriptDataSetFormatVer"},
	{FDRMScriptDataSEL, FDRMScriptDataSetAppOrgSEL, L"FDRMScriptDataSetAppOrg"},
	{FDRMScriptDataSEL, FDRMScriptDataSetAppVerSEL, L"FDRMScriptDataSetAppVer"},
	{FDRMScriptDataSEL, FDRMScriptDataSetAuthoritySEL, L"FDRMScriptDataSetAuthority"},
	{FDRMPresentationDataSEL, FDRMPresentationDataNewSEL, L"FDRMPresentationDataNew"},
	{FDRMPresentationDataSEL, FDRMPresentationDataDestroySEL, L"FDRMPresentationDataDestroy"},
	{FDRMPresentationDataSEL, FDRMPresentationDataGetDivisionSEL, L"FDRMPresentationDataGetDivision"},
	{FDRMPresentationDataSEL, FDRMPresentationDataGetAuthoritySEL, L"FDRMPresentationDataGetAuthority"},
	{FDRMPresentationDataSEL, FDRMPresentationDataSetDivisionSEL, L"FDRMPresentationDataSetDivision"},
	{FDRMPresentationDataSEL, FDRMPresentationDataSetAuthoritySEL, L"FDRMPresentationDataSetAuthority"},
	{FDRMSignatureDataSEL, FDRMSignatureDataNewSEL, L"FDRMSignatureDataNew"},
	{FDRMSignatureDataSEL, FDRMSignatureDataDestroySEL, L"FDRMSignatureDataDestroy"},
	{FDRMSignatureDataSEL, FDRMSignatureDataGetDivisionSEL, L"FDRMSignatureDataGetDivision"},
	{FDRMSignatureDataSEL, FDRMSignatureDataGetAgentOrgSEL, L"FDRMSignatureDataGetAgentOrg"},
	{FDRMSignatureDataSEL, FDRMSignatureDataGetAgentVerSEL, L"FDRMSignatureDataGetAgentVer"},
	{FDRMSignatureDataSEL, FDRMSignatureDataGetFormatOrgSEL, L"FDRMSignatureDataGetFormatOrg"},
	{FDRMSignatureDataSEL, FDRMSignatureDataGetFormatVerSEL, L"FDRMSignatureDataGetFormatVer"},
	{FDRMSignatureDataSEL, FDRMSignatureDataGetKeySEL, L"FDRMSignatureDataGetKey"},
	{FDRMSignatureDataSEL, FDRMSignatureDataSetDivisionSEL, L"FDRMSignatureDataSetDivision"},
	{FDRMSignatureDataSEL, FDRMSignatureDataSetAgentOrgSEL, L"FDRMSignatureDataSetAgentOrg"},
	{FDRMSignatureDataSEL, FDRMSignatureDataSetAgentVerSEL, L"FDRMSignatureDataSetAgentVer"},
	{FDRMSignatureDataSEL, FDRMSignatureDataSetFormatOrgSEL, L"FDRMSignatureDataSetFormatOrg"},
	{FDRMSignatureDataSEL, FDRMSignatureDataSetFormatVerSEL, L"FDRMSignatureDataSetFormatVer"},
	{FDRMSignatureDataSEL, FDRMSignatureDataSetKeySEL, L"FDRMSignatureDataSetKey"},
	{FDRMDescReadSEL, FDRMDescReadNewSEL, L"FDRMDescReadNew"},
	{FDRMDescReadSEL, FDRMDescReadDestroySEL, L"FDRMDescReadDestroy"},
	{FDRMDescReadSEL, FDRMDescReadLoadSEL, L"FDRMDescReadLoad"},
	{FDRMDescReadSEL, FDRMDescReadVerifyDescriptorSEL, L"FDRMDescReadVerifyDescriptor"},
	{FDRMDescReadSEL, FDRMDescReadGetDescTypeSEL, L"FDRMDescReadGetDescType"},
	{FDRMDescReadSEL, FDRMDescReadGetScriptSEL, L"FDRMDescReadGetScript"},
	{FDRMDescReadSEL, FDRMDescReadCountScriptsSEL, L"FDRMDescReadCountScripts"},
	{FDRMDescReadSEL, FDRMDescReadGetScript2SEL, L"FDRMDescReadGetScript2"},
	{FDRMDescReadSEL, FDRMDescReadGetScriptDataSEL, L"FDRMDescReadGetScriptData"},
	{FDRMDescReadSEL, FDRMDescReadGetScriptParamsSEL, L"FDRMDescReadGetScriptParams"},
	{FDRMDescReadSEL, FDRMDescReadGetPresentationSEL, L"FDRMDescReadGetPresentation"},
	{FDRMDescReadSEL, FDRMDescReadGetPresentationDataSEL, L"FDRMDescReadGetPresentationData"},
	{FDRMDescReadSEL, FDRMDescReadGetPresentationParamsSEL, L"FDRMDescReadGetPresentationParams"},
	{FDRMDescReadSEL, FDRMDescReadGetSignatureSEL, L"FDRMDescReadGetSignature"},
	{FDRMDescReadSEL, FDRMDescReadGetSignatureDataSEL, L"FDRMDescReadGetSignatureData"},
	{FDRMDescReadSEL, FDRMDescReadGetSignatureParamsSEL, L"FDRMDescReadGetSignatureParams"},
	{FDRMDescReadSEL, FDRMDescReadGetSignatureData2SEL, L"FDRMDescReadGetSignatureData2"},
	{FDRMDescReadSEL, FDRMDescReadCheckSignatureSEL, L"FDRMDescReadCheckSignature"},
	{FDRMDescReadSEL, FDRMDescReadVerifyValidationSEL, L"FDRMDescReadVerifyValidation"},
	{FDRMDescWriteSEL, FDRMDescWriteNewSEL, L"FDRMDescWriteNew"},
	{FDRMDescWriteSEL, FDRMDescWriteDestroySEL, L"FDRMDescWriteDestroy"},
	{FDRMDescWriteSEL, FDRMDescWriteInitDescriptorSEL, L"FDRMDescWriteInitDescriptor"},
	{FDRMDescWriteSEL, FDRMDescWriteRemoveScriptSEL, L"FDRMDescWriteRemoveScript"},
	{FDRMDescWriteSEL, FDRMDescWriteAddScriptSEL, L"FDRMDescWriteAddScript"},
	{FDRMDescWriteSEL, FDRMDescWriteSetScriptFormatSEL, L"FDRMDescWriteSetScriptFormat"},
	{FDRMDescWriteSEL, FDRMDescWriteSetScriptApplicationSEL, L"FDRMDescWriteSetScriptApplication"},
	{FDRMDescWriteSEL, FDRMDescWriteSetScriptAuthoritySEL, L"FDRMDescWriteSetScriptAuthority"},
	{FDRMDescWriteSEL, FDRMDescWriteSetScriptParamsSEL, L"FDRMDescWriteSetScriptParams"},
	{FDRMDescWriteSEL, FDRMDescWriteRemovePresentationSEL, L"FDRMDescWriteRemovePresentation"},
	{FDRMDescWriteSEL, FDRMDescWriteAddPresentationSEL, L"FDRMDescWriteAddPresentation"},
	{FDRMDescWriteSEL, FDRMDescWriteSetPresentationAuthoritySEL, L"FDRMDescWriteSetPresentationAuthority"},
	{FDRMDescWriteSEL, FDRMDescWriteSetPresentationParamsSEL, L"FDRMDescWriteSetPresentationParams"},
	{FDRMDescWriteSEL, FDRMDescWriteRemoveSignatureSEL, L"FDRMDescWriteRemoveSignature"},
	{FDRMDescWriteSEL, FDRMDescWriteAddSignatureSEL, L"FDRMDescWriteAddSignature"},
	{FDRMDescWriteSEL, FDRMDescWriteSetSignatureAgentSEL, L"FDRMDescWriteSetSignatureAgent"},
	{FDRMDescWriteSEL, FDRMDescWriteSetSignatureFormatSEL, L"FDRMDescWriteSetSignatureFormat"},
	{FDRMDescWriteSEL, FDRMDescWriteSetSignatureParamsSEL, L"FDRMDescWriteSetSignatureParams"},
	{FDRMDescWriteSEL, FDRMDescWriteSetSignatureKeySEL, L"FDRMDescWriteSetSignatureKey"},
	{FDRMDescWriteSEL, FDRMDescWriteSaveSEL, L"FDRMDescWriteSave"},
	{FDRMDescWriteSEL, FDRMDescWriteCastToDescReadSEL, L"FDRMDescWriteCastToDescRead"},
	{FDRMFoacReadSEL, FDRMFoacReadNewSEL, L"FDRMFoacReadNew"},
	{FDRMFoacReadSEL, FDRMFoacReadDestroySEL, L"FDRMFoacReadDestroy"},
	{FDRMFoacReadSEL, FDRMFoacReadGetDescReadSEL, L"FDRMFoacReadGetDescRead"},
	{FDRMFoacReadSEL, FDRMFoacReadVerifyFoacSEL, L"FDRMFoacReadVerifyFoac"},
	{FDRMFoacReadSEL, FDRMFoacReadGetTypeSEL, L"FDRMFoacReadGetType"},
	{FDRMFoacReadSEL, FDRMFoacReadGetSessionIDSEL, L"FDRMFoacReadGetSessionID"},
	{FDRMFoacReadSEL, FDRMFoacReadGetRequestIDSEL, L"FDRMFoacReadGetRequestID"},
	{FDRMFoacReadSEL, FDRMFoacReadGetRequestDataSEL, L"FDRMFoacReadGetRequestData"},
	{FDRMFoacReadSEL, FDRMFoacReadGetAnswerStateSEL, L"FDRMFoacReadGetAnswerState"},
	{FDRMFoacReadSEL, FDRMFoacReadGetAnswerDataSEL, L"FDRMFoacReadGetAnswerData"},
	{FDRMFoacWriteSEL, FDRMFoacWriteNewSEL, L"FDRMFoacWriteNew"},
	{FDRMFoacWriteSEL, FDRMFoacWriteDestroySEL, L"FDRMFoacWriteDestroy"},
	{FDRMFoacWriteSEL, FDRMFoacWriteGetDescWriteSEL, L"FDRMFoacWriteGetDescWrite"},
	{FDRMFoacWriteSEL, FDRMFoacWriteInitFoacSEL, L"FDRMFoacWriteInitFoac"},
	{FDRMFoacWriteSEL, FDRMFoacWriteSetSessionIDSEL, L"FDRMFoacWriteSetSessionID"},
	{FDRMFoacWriteSEL, FDRMFoacWriteSetRequestIDSEL, L"FDRMFoacWriteSetRequestID"},
	{FDRMFoacWriteSEL, FDRMFoacWriteSetRequestDataSEL, L"FDRMFoacWriteSetRequestData"},
	{FDRMFoacWriteSEL, FDRMFoacWriteSetAnswerStateSEL, L"FDRMFoacWriteSetAnswerState"},
	{FDRMFoacWriteSEL, FDRMFoacWriteSetAnswerDataSEL, L"FDRMFoacWriteSetAnswerData"},
	{FDRMFoacWriteSEL, FDRMFoacWriteCastToFoacReadSEL, L"FDRMFoacWriteCastToFoacRead"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadNewSEL, L"FDRMEnvelopeReadNew"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadDestroySEL, L"FDRMEnvelopeReadDestroy"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadLoadEnvelopeSEL, L"FDRMEnvelopeReadLoadEnvelope"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadGetFormatSEL, L"FDRMEnvelopeReadGetFormat"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadGetApplicationSEL, L"FDRMEnvelopeReadGetApplication"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadGetEnvelopeSNSEL, L"FDRMEnvelopeReadGetEnvelopeSN"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadGetFileIDSEL, L"FDRMEnvelopeReadGetFileID"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadGetIssuerSEL, L"FDRMEnvelopeReadGetIssuer"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadGetConsumerIdSEL, L"FDRMEnvelopeReadGetConsumerId"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadCountAuthKeysSEL, L"FDRMEnvelopeReadCountAuthKeys"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadGetAuthKeySEL, L"FDRMEnvelopeReadGetAuthKey"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadCountLimitsSEL, L"FDRMEnvelopeReadCountLimits"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadGetLimitSEL, L"FDRMEnvelopeReadGetLimit"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadCountRightsSEL, L"FDRMEnvelopeReadCountRights"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadGetRightSEL, L"FDRMEnvelopeReadGetRight"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadGetCipherSEL, L"FDRMEnvelopeReadGetCipher"},
	{FDRMEnvelopeReadSEL, FDRMEnvelopeReadValidateEnvelopeSEL, L"FDRMEnvelopeReadValidateEnvelope"},
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
	{FDRMMgrSEL, FDRMMgrCreateDefSEL, L"FDRMMgrCreateDef"},
	{FDRMMgrSEL, FDRMMgrGetCurrentUseSEL, L"FDRMMgrGetCurrentUse"},
	{FDRMMgrSEL, FDRMMgrSetCurrentUseSEL, L"FDRMMgrSetCurrentUse"},
	{FDRMMgrSEL, FDRMMgrDestroySEL, L"FDRMMgrDestroy"},
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerNewSEL, L"FDRMPDFSecurityHandlerNew"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerDestroySEL, L"FDRMPDFSecurityHandlerDestroy"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerInitSEL, L"FDRMPDFSecurityHandlerInit"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerGetPermissionsSEL, L"FDRMPDFSecurityHandlerGetPermissions"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerIsOwnerSEL, L"FDRMPDFSecurityHandlerIsOwner"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerGetCryptInfoSEL, L"FDRMPDFSecurityHandlerGetCryptInfo"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerSetSubFilterSEL, L"FDRMPDFSecurityHandlerSetSubFilter"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerSetIdentityEntrySEL, L"FDRMPDFSecurityHandlerSetIdentityEntry"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerGetSubFilterSEL, L"FDRMPDFSecurityHandlerGetSubFilter"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerGetIdentityEntrySEL, L"FDRMPDFSecurityHandlerGetIdentityEntry"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerSetCryptInfoSEL, L"FDRMPDFSecurityHandlerSetCryptInfo"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerCheckValiditySEL, L"FDRMPDFSecurityHandlerCheckValidity"},
	{FDRMPDFSecurityHandlerSEL, FDRMPDFSecurityHandlerCreateCryptoHandlerSEL, L"FDRMPDFSecurityHandlerCreateCryptoHandler"},
	{FDRMPDFSchemaSEL, FDRMPDFSchemaNewSEL, L"FDRMPDFSchemaNew"},
	{FDRMPDFSchemaSEL, FDRMPDFSchemaDestroySEL, L"FDRMPDFSchemaDestroy"},
	{FDRMPDFSchemaSEL, FDRMPDFSchemaLoadSchemaSEL, L"FDRMPDFSchemaLoadSchema"},
	{FDRMPDFSchemaSEL, FDRMPDFSchemaGetPDFFileSizeSEL, L"FDRMPDFSchemaGetPDFFileSize"},
	{FDRMPDFSchemaSEL, FDRMPDFSchemaGetXRefOffsetSEL, L"FDRMPDFSchemaGetXRefOffset"},
	{FDRMPDFSchemaSEL, FDRMPDFSchemaCountPagesSEL, L"FDRMPDFSchemaCountPages"},
	{FDRMPDFSchemaSEL, FDRMPDFSchemaGetSchemaInfoSEL, L"FDRMPDFSchemaGetSchemaInfo"},
	{FDRMPDFSchemaSEL, FDRMPDFSchemaGetPageSizeSEL, L"FDRMPDFSchemaGetPageSize"},
	{FDRMEncryptDictReadSEL, FDRMEncryptDictReadNewSEL, L"FDRMEncryptDictReadNew"},
	{FDRMEncryptDictReadSEL, FDRMEncryptDictReadDestroySEL, L"FDRMEncryptDictReadDestroy"},
	{FDRMEncryptDictReadSEL, FDRMEncryptDictReadVerifySEL, L"FDRMEncryptDictReadVerify"},
	{FDRMEncryptDictReadSEL, FDRMEncryptDictReadGetSubFilterSEL, L"FDRMEncryptDictReadGetSubFilter"},
	{FDRMEncryptDictReadSEL, FDRMEncryptDictReadGetIssuerSEL, L"FDRMEncryptDictReadGetIssuer"},
	{FDRMEncryptDictReadSEL, FDRMEncryptDictReadGetCreatorSEL, L"FDRMEncryptDictReadGetCreator"},
	{FDRMEncryptDictReadSEL, FDRMEncryptDictReadGetFileIdSEL, L"FDRMEncryptDictReadGetFileId"},
	{FDRMEncryptDictReadSEL, FDRMEncryptDictReadGetFlowCodeSEL, L"FDRMEncryptDictReadGetFlowCode"},
	{FDRMEncryptDictReadSEL, FDRMEncryptDictReadGetOrderSEL, L"FDRMEncryptDictReadGetOrder"},
	{FDRMEncryptDictReadSEL, FDRMEncryptDictReadGetUserSEL, L"FDRMEncryptDictReadGetUser"},
	{FDRMEncryptDictReadSEL, FDRMEncryptDictReadGetServiceURLSEL, L"FDRMEncryptDictReadGetServiceURL"},
	{FDRMEncryptorSEL, FDRMEncryptorArcFourCryptBlockSEL, L"FDRMEncryptorArcFourCryptBlock"},
	{FDRMEncryptorSEL, FDRMEncryptorArcFourSetupSEL, L"FDRMEncryptorArcFourSetup"},
	{FDRMEncryptorSEL, FDRMEncryptorArcFourCryptSEL, L"FDRMEncryptorArcFourCrypt"},
	{FDRMEncryptorSEL, FDRMEncryptorSHA256StartSEL, L"FDRMEncryptorSHA256Start"},
	{FDRMEncryptorSEL, FDRMEncryptorSHA256UpdateSEL, L"FDRMEncryptorSHA256Update"},
	{FDRMEncryptorSEL, FDRMEncryptorSHA256FinishSEL, L"FDRMEncryptorSHA256Finish"},
	{FDRMEncryptorSEL, FDRMEncryptorSHA256DigestGenerateSEL, L"FDRMEncryptorSHA256DigestGenerate"},
	{FDRMEncryptorSEL, FDRMEncryptorHashMD5128SEL, L"FDRMEncryptorHashMD5128"},
	{FDRMEncryptorSEL, FDRMEncryptorAESSetKeySEL, L"FDRMEncryptorAESSetKey"},
	{FDRMEncryptorSEL, FDRMEncryptorAESSetIVSEL, L"FDRMEncryptorAESSetIV"},
	{FDRMEncryptorSEL, FDRMEncryptorAESDecryptSEL, L"FDRMEncryptorAESDecrypt"},
	{FDRMEncryptorSEL, FDRMEncryptorAESEncryptSEL, L"FDRMEncryptorAESEncrypt"},
	{FDRMEncryptorSEL, FDRMEncryptorAESSetKey2SEL, L"FDRMEncryptorAESSetKey2"},
	{FDRMEncryptorSEL, FDRMEncryptorMD5StartSEL, L"FDRMEncryptorMD5Start"},
	{FDRMEncryptorSEL, FDRMEncryptorMD5UpdateSEL, L"FDRMEncryptorMD5Update"},
	{FDRMEncryptorSEL, FDRMEncryptorMD5FinishSEL, L"FDRMEncryptorMD5Finish"},
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
	{FDRMPKISEL, FDRMPKICreateRsaKeySEL, L"FDRMPKICreateRsaKey"},
	{FDRMPKISEL, FDRMPKIRsaEncryptSEL, L"FDRMPKIRsaEncrypt"},
	{FDRMPKISEL, FDRMPKIRsaDecryptSEL, L"FDRMPKIRsaDecrypt"},
	{FDRMPKISEL, FDRMPKIRsaSignSEL, L"FDRMPKIRsaSign"},
	{FDRMPKISEL, FDRMPKIVerifyRsaSignSEL, L"FDRMPKIVerifyRsaSign"},
	{FDRMPKISEL, FDRMPKICreateDsaKeySEL, L"FDRMPKICreateDsaKey"},
	{FDRMPKISEL, FDRMPKIDsaSignSEL, L"FDRMPKIDsaSign"},
	{FDRMPKISEL, FDRMPKIVerifyDsaSignSEL, L"FDRMPKIVerifyDsaSign"},
	{FDRMPKISEL, FDRMPKIVerifyRsaKeySEL, L"FDRMPKIVerifyRsaKey"},
	{FDRMPKISEL, FDRMPKIVerifyDasKeySEL, L"FDRMPKIVerifyDasKey"},
	{FDRMPKISEL, FDRMPKIGenMD5DigestSEL, L"FDRMPKIGenMD5Digest"},
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
	{FPDWrapperCreatorSEL, FPDWrapperCreatorNewSEL, L"FPDWrapperCreatorNew"},
	{FPDWrapperCreatorSEL, FPDWrapperCreatorDestroySEL, L"FPDWrapperCreatorDestroy"},
	{FPDWrapperCreatorSEL, FPDWrapperCreatorSetWrapperDataSEL, L"FPDWrapperCreatorSetWrapperData"},
	{FPDWrapperCreatorSEL, FPDWrapperCreatorCreateSEL, L"FPDWrapperCreatorCreate"},
	{FPDWrapperCreatorSEL, FPDWrapperCreatorSetStandardSecuritySEL, L"FPDWrapperCreatorSetStandardSecurity"},
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V3----------
// In file fs_basicImpl.h
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
	{FRThumbnailViewSEL, FRThumbnailViewCountPageSEL, L"FRThumbnailViewCountPage"},
	{FRThumbnailViewSEL, FRThumbnailViewCountVisiblePageSEL, L"FRThumbnailViewCountVisiblePage"},
	{FRThumbnailViewSEL, FRThumbnailViewGetPageRectSEL, L"FRThumbnailViewGetPageRect"},
	{FRThumbnailViewSEL, FRThumbnailViewGetVisiblePageRangeSEL, L"FRThumbnailViewGetVisiblePageRange"},
	{FRThumbnailViewSEL, FRThumbnailViewGetPDPageSEL, L"FRThumbnailViewGetPDPage"},
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V4----------
// In file fs_basicImpl.h
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
// fr_appImpl.h end

// In file fr_barImpl.h
	{FRTabBandSEL, FRTabBandGetSEL, L"FRTabBandGet"},
	{FRTabBandSEL, FRTabBandGetTabWndSEL, L"FRTabBandGetTabWnd"},
	{FRTabBandSEL, FRTabBandGetActiveTabWndSEL, L"FRTabBandGetActiveTabWnd"},
	{FRTabBandSEL, FRTabBandGetTabsNumSEL, L"FRTabBandGetTabsNum"},
	{FRTabBandSEL, FRTabBandCloseTabWndSEL, L"FRTabBandCloseTabWnd"},
	{FRTabBandSEL, FRTabBandGetActiveTabSEL, L"FRTabBandGetActiveTab"},
	{FRTabBandSEL, FRTabBandSetActiveTabSEL, L"FRTabBandSetActiveTab"},
	{FRTabBandSEL, FRTabBandRegisterAddBtnHandlerSEL, L"FRTabBandRegisterAddBtnHandler"},
	{FRTabBandSEL, FRTabBandSetTabTitleSEL, L"FRTabBandSetTabTitle"},
	{FRTabBandSEL, FRTabBandSetTabIconSEL, L"FRTabBandSetTabIcon"},
	{FRTabBandSEL, FRTabBandGet2SEL, L"FRTabBandGet2"},
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V5----------
// In file fs_basicImpl.h
	{FSUTF8DecoderSEL, FSUTF8DecoderNewSEL, L"FSUTF8DecoderNew"},
	{FSUTF8DecoderSEL, FSUTF8DecoderDestroySEL, L"FSUTF8DecoderDestroy"},
	{FSUTF8DecoderSEL, FSUTF8DecoderClearSEL, L"FSUTF8DecoderClear"},
	{FSUTF8DecoderSEL, FSUTF8DecoderInputSEL, L"FSUTF8DecoderInput"},
	{FSUTF8DecoderSEL, FSUTF8DecoderAppendCharSEL, L"FSUTF8DecoderAppendChar"},
	{FSUTF8DecoderSEL, FSUTF8DecoderClearStatusSEL, L"FSUTF8DecoderClearStatus"},
	{FSUTF8DecoderSEL, FSUTF8DecoderGetResultSEL, L"FSUTF8DecoderGetResult"},
	{FSUTF8EncoderSEL, FSUTF8EncoderNewSEL, L"FSUTF8EncoderNew"},
	{FSUTF8EncoderSEL, FSUTF8EncoderDestroySEL, L"FSUTF8EncoderDestroy"},
	{FSUTF8EncoderSEL, FSUTF8EncoderInputSEL, L"FSUTF8EncoderInput"},
	{FSUTF8EncoderSEL, FSUTF8EncoderAppendStrSEL, L"FSUTF8EncoderAppendStr"},
	{FSUTF8EncoderSEL, FSUTF8EncoderGetResultSEL, L"FSUTF8EncoderGetResult"},
	{FSUTF8EncoderSEL, FSUTF8EncoderIsUTF8DataSEL, L"FSUTF8EncoderIsUTF8Data"},
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
	{FRInternalSEL, FRInternalDoPrintCommentSummarySEL, L"FRInternalDoPrintCommentSummary"},
	{FRInternalSEL, FRInternalOptimizerModuleFlatDocumentSEL, L"FRInternalOptimizerModuleFlatDocument"},
	{FRInternalSEL, FRInternalGlobalWndOpenPassWordSEL, L"FRInternalGlobalWndOpenPassWord"},
	{FRInternalSEL, FRInternalGlobalWndCheckFileSizeSEL, L"FRInternalGlobalWndCheckFileSize"},
	{FRInternalSEL, FRInternalOpenCertifiedPDFSEL, L"FRInternalOpenCertifiedPDF"},
	{FRInternalSEL, FRInternalPWLWndCreationParamNewSEL, L"FRInternalPWLWndCreationParamNew"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetFontMapSEL, L"FRInternalPWLWndCreationParamSetFontMap"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetFontIndexSEL, L"FRInternalPWLWndCreationParamSetFontIndex"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetFlagSEL, L"FRInternalPWLWndCreationParamSetFlag"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetFontSizeSEL, L"FRInternalPWLWndCreationParamSetFontSize"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetTextColorSEL, L"FRInternalPWLWndCreationParamSetTextColor"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetTextColorIISEL, L"FRInternalPWLWndCreationParamSetTextColorII"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetRectSEL, L"FRInternalPWLWndCreationParamSetRect"},
	{FRInternalSEL, FRInternalPWLWndCreationParamDestroySEL, L"FRInternalPWLWndCreationParamDestroy"},
	{FRInternalSEL, FRInternalPWLWndEditNewSEL, L"FRInternalPWLWndEditNew"},
	{FRInternalSEL, FRInternalPWLWndEditSetTextColorSEL, L"FRInternalPWLWndEditSetTextColor"},
	{FRInternalSEL, FRInternalPWLWndEditSetTextColorIISEL, L"FRInternalPWLWndEditSetTextColorII"},
	{FRInternalSEL, FRInternalPWLWndEditSetTextSEL, L"FRInternalPWLWndEditSetText"},
	{FRInternalSEL, FRInternalPWLWndEditGetContentRectSEL, L"FRInternalPWLWndEditGetContentRect"},
	{FRInternalSEL, FRInternalPWLWndEditGeneratePageObjectsSEL, L"FRInternalPWLWndEditGeneratePageObjects"},
	{FRInternalSEL, FRInternalPWLWndEditGeneratePageObjectsIISEL, L"FRInternalPWLWndEditGeneratePageObjectsII"},
	{FRInternalSEL, FRInternalPWLWndEditDestroySEL, L"FRInternalPWLWndEditDestroy"},
	{FRInternalSEL, FRInternalSetReviewJSSEL, L"FRInternalSetReviewJS"},
	{FRInternalSEL, FRInternalGetReviewJSSEL, L"FRInternalGetReviewJS"},
	{FRInternalSEL, FRInternalRemoveReviewJSSEL, L"FRInternalRemoveReviewJS"},
	{FRInternalSEL, FRInternalExportAnnotToXFDFSEL, L"FRInternalExportAnnotToXFDF"},
	{FRInternalSEL, FRInternalImprotAnnotFromXFDFSEL, L"FRInternalImprotAnnotFromXFDF"},
	{FRInternalSEL, FRInternalEnableAnnotSEL, L"FRInternalEnableAnnot"},
	{FRInternalSEL, FRInternalDeleteAnnotSEL, L"FRInternalDeleteAnnot"},
	{FRInternalSEL, FRInternalUpdateAnnotAuthorSEL, L"FRInternalUpdateAnnotAuthor"},
	{FRInternalSEL, FRInternalUpdateAnnotAuthor2SEL, L"FRInternalUpdateAnnotAuthor2"},
	{FRInternalSEL, FRInternalSetIcommentsAnnotNotifySEL, L"FRInternalSetIcommentsAnnotNotify"},
	{FRInternalSEL, FRInternalRemoveIcommentsAnnotNotifySEL, L"FRInternalRemoveIcommentsAnnotNotify"},
	{FRInternalSEL, FRInternalShowChildScrollBarSEL, L"FRInternalShowChildScrollBar"},
	{FRInternalSEL, FRInternalChangeZoomScaleInfoSEL, L"FRInternalChangeZoomScaleInfo"},
	{FRInternalSEL, FRInternalAdvEditingSEL, L"FRInternalAdvEditing"},
	{FRInternalSEL, FRInternalToolbarModuleGetSysFontFaceNameSEL, L"FRInternalToolbarModuleGetSysFontFaceName"},
	{FRInternalSEL, FRInternalWordPlaceNewSEL, L"FRInternalWordPlaceNew"},
	{FRInternalSEL, FRInternalWordPlaceDestroySEL, L"FRInternalWordPlaceDestroy"},
	{FRInternalSEL, FRInternalWordPlaceSetDefaultSEL, L"FRInternalWordPlaceSetDefault"},
	{FRInternalSEL, FRInternalWordPlaceEqualSEL, L"FRInternalWordPlaceEqual"},
	{FRInternalSEL, FRInternalWordPlaceWordCmpSEL, L"FRInternalWordPlaceWordCmp"},
	{FRInternalSEL, FRInternalWordPlaceLineCmpSEL, L"FRInternalWordPlaceLineCmp"},
	{FRInternalSEL, FRInternalWordPlaceSecCmpSEL, L"FRInternalWordPlaceSecCmp"},
	{FRInternalSEL, FRInternalWordPlaceSetSectionIndexSEL, L"FRInternalWordPlaceSetSectionIndex"},
	{FRInternalSEL, FRInternalWordPlaceGetSectionIndexSEL, L"FRInternalWordPlaceGetSectionIndex"},
	{FRInternalSEL, FRInternalWordPlaceSetLineIndexSEL, L"FRInternalWordPlaceSetLineIndex"},
	{FRInternalSEL, FRInternalWordPlaceGetLineIndexSEL, L"FRInternalWordPlaceGetLineIndex"},
	{FRInternalSEL, FRInternalWordPlaceSetWordIndexSEL, L"FRInternalWordPlaceSetWordIndex"},
	{FRInternalSEL, FRInternalWordPlaceGetWordIndexSEL, L"FRInternalWordPlaceGetWordIndex"},
	{FRInternalSEL, FRInternalWordRangeNewSEL, L"FRInternalWordRangeNew"},
	{FRInternalSEL, FRInternalWordRangeDestroySEL, L"FRInternalWordRangeDestroy"},
	{FRInternalSEL, FRInternalWordRangeSetDefaultSEL, L"FRInternalWordRangeSetDefault"},
	{FRInternalSEL, FRInternalWordRangeSetSEL, L"FRInternalWordRangeSet"},
	{FRInternalSEL, FRInternalWordRangeSetBeginPosSEL, L"FRInternalWordRangeSetBeginPos"},
	{FRInternalSEL, FRInternalWordRangeSetEndPosSEL, L"FRInternalWordRangeSetEndPos"},
	{FRInternalSEL, FRInternalWordRangeIsExistSEL, L"FRInternalWordRangeIsExist"},
	{FRInternalSEL, FRInternalWordRangeEqualSEL, L"FRInternalWordRangeEqual"},
	{FRInternalSEL, FRInternalWordRangeSwapWordPlaceSEL, L"FRInternalWordRangeSwapWordPlace"},
	{FRInternalSEL, FRInternalWordRangeGetBeginPosSEL, L"FRInternalWordRangeGetBeginPos"},
	{FRInternalSEL, FRInternalWordRangeGetEndPosSEL, L"FRInternalWordRangeGetEndPos"},
	{FRInternalSEL, FRInternalSecPropsNewSEL, L"FRInternalSecPropsNew"},
	{FRInternalSEL, FRInternalSecPropsNewIISEL, L"FRInternalSecPropsNewII"},
	{FRInternalSEL, FRInternalSecPropsDestroySEL, L"FRInternalSecPropsDestroy"},
	{FRInternalSEL, FRInternalSecPropsSetLineLeadingSEL, L"FRInternalSecPropsSetLineLeading"},
	{FRInternalSEL, FRInternalSecPropsGetLineLeadingSEL, L"FRInternalSecPropsGetLineLeading"},
	{FRInternalSEL, FRInternalSecPropsSetLineIndentSEL, L"FRInternalSecPropsSetLineIndent"},
	{FRInternalSEL, FRInternalSecPropsGetLineIndentSEL, L"FRInternalSecPropsGetLineIndent"},
	{FRInternalSEL, FRInternalSecPropsSetAlignmentSEL, L"FRInternalSecPropsSetAlignment"},
	{FRInternalSEL, FRInternalSecPropsGetAlignmentSEL, L"FRInternalSecPropsGetAlignment"},
	{FRInternalSEL, FRInternalSecPropsSetSoftReturnSEL, L"FRInternalSecPropsSetSoftReturn"},
	{FRInternalSEL, FRInternalSecPropsGetSoftReturnSEL, L"FRInternalSecPropsGetSoftReturn"},
	{FRInternalSEL, FRInternalSecPropsSetRTLSEL, L"FRInternalSecPropsSetRTL"},
	{FRInternalSEL, FRInternalSecPropsGetRTLSEL, L"FRInternalSecPropsGetRTL"},
	{FRInternalSEL, FRInternalWordPropsNewSEL, L"FRInternalWordPropsNew"},
	{FRInternalSEL, FRInternalWordPropsNewIISEL, L"FRInternalWordPropsNewII"},
	{FRInternalSEL, FRInternalWordPropsDestroySEL, L"FRInternalWordPropsDestroy"},
	{FRInternalSEL, FRInternalWordPropsSetFontIndexSEL, L"FRInternalWordPropsSetFontIndex"},
	{FRInternalSEL, FRInternalWordPropsGetFontIndexSEL, L"FRInternalWordPropsGetFontIndex"},
	{FRInternalSEL, FRInternalWordPropsSetFontSizeSEL, L"FRInternalWordPropsSetFontSize"},
	{FRInternalSEL, FRInternalWordPropsGetFontSizeSEL, L"FRInternalWordPropsGetFontSize"},
	{FRInternalSEL, FRInternalWordPropsSetWordColorSEL, L"FRInternalWordPropsSetWordColor"},
	{FRInternalSEL, FRInternalWordPropsGetWordColorSEL, L"FRInternalWordPropsGetWordColor"},
	{FRInternalSEL, FRInternalWordPropsSetStrokeColorSEL, L"FRInternalWordPropsSetStrokeColor"},
	{FRInternalSEL, FRInternalWordPropsGetStrokeColorSEL, L"FRInternalWordPropsGetStrokeColor"},
	{FRInternalSEL, FRInternalWordPropsSetScriptTypeSEL, L"FRInternalWordPropsSetScriptType"},
	{FRInternalSEL, FRInternalWordPropsGetScriptTypeSEL, L"FRInternalWordPropsGetScriptType"},
	{FRInternalSEL, FRInternalWordPropsSetWordStyleSEL, L"FRInternalWordPropsSetWordStyle"},
	{FRInternalSEL, FRInternalWordPropsGetWordStyleSEL, L"FRInternalWordPropsGetWordStyle"},
	{FRInternalSEL, FRInternalWordPropsSetCharSpaceSEL, L"FRInternalWordPropsSetCharSpace"},
	{FRInternalSEL, FRInternalWordPropsGetCharSpaceSEL, L"FRInternalWordPropsGetCharSpace"},
	{FRInternalSEL, FRInternalWordPropsSetHorzScaleSEL, L"FRInternalWordPropsSetHorzScale"},
	{FRInternalSEL, FRInternalWordPropsGetHorzScaleSEL, L"FRInternalWordPropsGetHorzScale"},
	{FRInternalSEL, FRInternalWordPropsSetXOffsetSEL, L"FRInternalWordPropsSetXOffset"},
	{FRInternalSEL, FRInternalWordPropsGetXOffsetSEL, L"FRInternalWordPropsGetXOffset"},
	{FRInternalSEL, FRInternalWordPropsSetYOffsetSEL, L"FRInternalWordPropsSetYOffset"},
	{FRInternalSEL, FRInternalWordPropsGetYOffsetSEL, L"FRInternalWordPropsGetYOffset"},
	{FRInternalSEL, FRInternalWordPropsSetRenderingModeSEL, L"FRInternalWordPropsSetRenderingMode"},
	{FRInternalSEL, FRInternalWordPropsGetRenderingModeSEL, L"FRInternalWordPropsGetRenderingMode"},
	{FRInternalSEL, FRInternalWordPropsSetClientDataSEL, L"FRInternalWordPropsSetClientData"},
	{FRInternalSEL, FRInternalWordPropsGetClientDataSEL, L"FRInternalWordPropsGetClientData"},
	{FRInternalSEL, FRInternalWordPropsSetLineWidthSEL, L"FRInternalWordPropsSetLineWidth"},
	{FRInternalSEL, FRInternalWordPropsGetLineWidthSEL, L"FRInternalWordPropsGetLineWidth"},
	{FRInternalSEL, FRInternalWordPropsSetWordSpaceSEL, L"FRInternalWordPropsSetWordSpace"},
	{FRInternalSEL, FRInternalWordPropsGetWordSpaceSEL, L"FRInternalWordPropsGetWordSpace"},
	{FRInternalSEL, FRInternalWordPropsSetCharCodeSEL, L"FRInternalWordPropsSetCharCode"},
	{FRInternalSEL, FRInternalWordPropsGetCharCodeSEL, L"FRInternalWordPropsGetCharCode"},
	{FRInternalSEL, FRInternalWordPropsSetAlphaSEL, L"FRInternalWordPropsSetAlpha"},
	{FRInternalSEL, FRInternalWordPropsGetAlphaSEL, L"FRInternalWordPropsGetAlpha"},
	{FRInternalSEL, FRInternalWordNewSEL, L"FRInternalWordNew"},
	{FRInternalSEL, FRInternalWordDestroySEL, L"FRInternalWordDestroy"},
	{FRInternalSEL, FRInternalWordSetWordSEL, L"FRInternalWordSetWord"},
	{FRInternalSEL, FRInternalWordGetWordSEL, L"FRInternalWordGetWord"},
	{FRInternalSEL, FRInternalWordSetWordDisplaySEL, L"FRInternalWordSetWordDisplay"},
	{FRInternalSEL, FRInternalWordGetWordDisplaySEL, L"FRInternalWordGetWordDisplay"},
	{FRInternalSEL, FRInternalWordSetBidiOrderSEL, L"FRInternalWordSetBidiOrder"},
	{FRInternalSEL, FRInternalWordGetBidiOrderSEL, L"FRInternalWordGetBidiOrder"},
	{FRInternalSEL, FRInternalWordSetCharsetSEL, L"FRInternalWordSetCharset"},
	{FRInternalSEL, FRInternalWordGetCharsetSEL, L"FRInternalWordGetCharset"},
	{FRInternalSEL, FRInternalWordSetWordPlaceSEL, L"FRInternalWordSetWordPlace"},
	{FRInternalSEL, FRInternalWordGetWordPlaceSEL, L"FRInternalWordGetWordPlace"},
	{FRInternalSEL, FRInternalWordSetWordPointSEL, L"FRInternalWordSetWordPoint"},
	{FRInternalSEL, FRInternalWordGetWordPointSEL, L"FRInternalWordGetWordPoint"},
	{FRInternalSEL, FRInternalWordSetAscentSEL, L"FRInternalWordSetAscent"},
	{FRInternalSEL, FRInternalWordGetAscentSEL, L"FRInternalWordGetAscent"},
	{FRInternalSEL, FRInternalWordSetDescentSEL, L"FRInternalWordSetDescent"},
	{FRInternalSEL, FRInternalWordGetDescentSEL, L"FRInternalWordGetDescent"},
	{FRInternalSEL, FRInternalWordSetWidthSEL, L"FRInternalWordSetWidth"},
	{FRInternalSEL, FRInternalWordGetWidthSEL, L"FRInternalWordGetWidth"},
	{FRInternalSEL, FRInternalWordSetFontIndexSEL, L"FRInternalWordSetFontIndex"},
	{FRInternalSEL, FRInternalWordGetFontIndexSEL, L"FRInternalWordGetFontIndex"},
	{FRInternalSEL, FRInternalWordSetFontSizeSEL, L"FRInternalWordSetFontSize"},
	{FRInternalSEL, FRInternalWordGetFontSizeSEL, L"FRInternalWordGetFontSize"},
	{FRInternalSEL, FRInternalWordSetWordPropsSEL, L"FRInternalWordSetWordProps"},
	{FRInternalSEL, FRInternalWordGetWordPropsSEL, L"FRInternalWordGetWordProps"},
	{FRInternalSEL, FRInternalLineNewSEL, L"FRInternalLineNew"},
	{FRInternalSEL, FRInternalLineDestroySEL, L"FRInternalLineDestroy"},
	{FRInternalSEL, FRInternalLineSetStartWordPlaceSEL, L"FRInternalLineSetStartWordPlace"},
	{FRInternalSEL, FRInternalLineGetStartWordPlaceSEL, L"FRInternalLineGetStartWordPlace"},
	{FRInternalSEL, FRInternalLineSetEndWordPlaceSEL, L"FRInternalLineSetEndWordPlace"},
	{FRInternalSEL, FRInternalLineGetEndWordPlaceSEL, L"FRInternalLineGetEndWordPlace"},
	{FRInternalSEL, FRInternalLineSetOriginalPositionSEL, L"FRInternalLineSetOriginalPosition"},
	{FRInternalSEL, FRInternalLineGetOriginalPositionSEL, L"FRInternalLineGetOriginalPosition"},
	{FRInternalSEL, FRInternalLineSetWidthSEL, L"FRInternalLineSetWidth"},
	{FRInternalSEL, FRInternalLineGetWidthSEL, L"FRInternalLineGetWidth"},
	{FRInternalSEL, FRInternalLineSetAscentSEL, L"FRInternalLineSetAscent"},
	{FRInternalSEL, FRInternalLineGetAscentSEL, L"FRInternalLineGetAscent"},
	{FRInternalSEL, FRInternalLineSetDescentSEL, L"FRInternalLineSetDescent"},
	{FRInternalSEL, FRInternalLineGetDescentSEL, L"FRInternalLineGetDescent"},
	{FRInternalSEL, FRInternalSectionNewSEL, L"FRInternalSectionNew"},
	{FRInternalSEL, FRInternalSectionDestroySEL, L"FRInternalSectionDestroy"},
	{FRInternalSEL, FRInternalSectionSetStartWordPlaceSEL, L"FRInternalSectionSetStartWordPlace"},
	{FRInternalSEL, FRInternalSectionGetStartWordPlaceSEL, L"FRInternalSectionGetStartWordPlace"},
	{FRInternalSEL, FRInternalSectionSetRectSEL, L"FRInternalSectionSetRect"},
	{FRInternalSEL, FRInternalSectionGetRectSEL, L"FRInternalSectionGetRect"},
	{FRInternalSEL, FRInternalSectionSetSectionPropertiesSEL, L"FRInternalSectionSetSectionProperties"},
	{FRInternalSEL, FRInternalSectionGetSectionPropertiesSEL, L"FRInternalSectionGetSectionProperties"},
	{FRInternalSEL, FRInternalSectionSetWordPropertiesSEL, L"FRInternalSectionSetWordProperties"},
	{FRInternalSEL, FRInternalSectionGetWordPropertiesSEL, L"FRInternalSectionGetWordProperties"},
	{FRInternalSEL, FRInternalVTIteratorNextWordSEL, L"FRInternalVTIteratorNextWord"},
	{FRInternalSEL, FRInternalVTIteratorPrevWordSEL, L"FRInternalVTIteratorPrevWord"},
	{FRInternalSEL, FRInternalVTIteratorNextLineSEL, L"FRInternalVTIteratorNextLine"},
	{FRInternalSEL, FRInternalVTIteratorPrevLineSEL, L"FRInternalVTIteratorPrevLine"},
	{FRInternalSEL, FRInternalVTIteratorNextSectionSEL, L"FRInternalVTIteratorNextSection"},
	{FRInternalSEL, FRInternalVTIteratorPrevSectionSEL, L"FRInternalVTIteratorPrevSection"},
	{FRInternalSEL, FRInternalVTIteratorGetWordSEL, L"FRInternalVTIteratorGetWord"},
	{FRInternalSEL, FRInternalVTIteratorSetWordSEL, L"FRInternalVTIteratorSetWord"},
	{FRInternalSEL, FRInternalVTIteratorGetLineSEL, L"FRInternalVTIteratorGetLine"},
	{FRInternalSEL, FRInternalVTIteratorGetSectionSEL, L"FRInternalVTIteratorGetSection"},
	{FRInternalSEL, FRInternalVTIteratorSetSectionSEL, L"FRInternalVTIteratorSetSection"},
	{FRInternalSEL, FRInternalVTIteratorSetAtSEL, L"FRInternalVTIteratorSetAt"},
	{FRInternalSEL, FRInternalVTIteratorSetAtIISEL, L"FRInternalVTIteratorSetAtII"},
	{FRInternalSEL, FRInternalVTIteratorGetAtSEL, L"FRInternalVTIteratorGetAt"},
	{FRInternalSEL, FRInternalVTIteratorGetDisplayWordSEL, L"FRInternalVTIteratorGetDisplayWord"},
	{FRInternalSEL, FRInternalVariableTextNewSEL, L"FRInternalVariableTextNew"},
	{FRInternalSEL, FRInternalVariableTextDestroySEL, L"FRInternalVariableTextDestroy"},
	{FRInternalSEL, FRInternalVariableTextProviderNewSEL, L"FRInternalVariableTextProviderNew"},
	{FRInternalSEL, FRInternalVariableTextProviderDestroySEL, L"FRInternalVariableTextProviderDestroy"},
	{FRInternalSEL, FRInternalVariableTextSetProviderSEL, L"FRInternalVariableTextSetProvider"},
	{FRInternalSEL, FRInternalVariableTextGetIteratorSEL, L"FRInternalVariableTextGetIterator"},
	{FRInternalSEL, FRInternalVariableTextSetPlateRectSEL, L"FRInternalVariableTextSetPlateRect"},
	{FRInternalSEL, FRInternalVariableTextIsVerticalWritingSEL, L"FRInternalVariableTextIsVerticalWriting"},
	{FRInternalSEL, FRInternalVariableTextSetAlignmentSEL, L"FRInternalVariableTextSetAlignment"},
	{FRInternalSEL, FRInternalVariableTextSetPasswordCharSEL, L"FRInternalVariableTextSetPasswordChar"},
	{FRInternalSEL, FRInternalVariableTextSetLimitCharSEL, L"FRInternalVariableTextSetLimitChar"},
	{FRInternalSEL, FRInternalVariableTextSetCharArraySEL, L"FRInternalVariableTextSetCharArray"},
	{FRInternalSEL, FRInternalVariableTextSetCharSpaceSEL, L"FRInternalVariableTextSetCharSpace"},
	{FRInternalSEL, FRInternalVariableTextSetWordSpaceSEL, L"FRInternalVariableTextSetWordSpace"},
	{FRInternalSEL, FRInternalVariableTextSetHorzScaleSEL, L"FRInternalVariableTextSetHorzScale"},
	{FRInternalSEL, FRInternalVariableTextSetMultiLineSEL, L"FRInternalVariableTextSetMultiLine"},
	{FRInternalSEL, FRInternalVariableTextSetAutoReturnSEL, L"FRInternalVariableTextSetAutoReturn"},
	{FRInternalSEL, FRInternalVariableTextSetAutoFontSizeSEL, L"FRInternalVariableTextSetAutoFontSize"},
	{FRInternalSEL, FRInternalVariableTextSetFontSizeSEL, L"FRInternalVariableTextSetFontSize"},
	{FRInternalSEL, FRInternalVariableTextSetLineLeadingSEL, L"FRInternalVariableTextSetLineLeading"},
	{FRInternalSEL, FRInternalVariableTextSetRichTextSEL, L"FRInternalVariableTextSetRichText"},
	{FRInternalSEL, FRInternalVariableTextSetDirectionRTLSEL, L"FRInternalVariableTextSetDirectionRTL"},
	{FRInternalSEL, FRInternalVariableTextInitializeSEL, L"FRInternalVariableTextInitialize"},
	{FRInternalSEL, FRInternalVariableTextIsValidSEL, L"FRInternalVariableTextIsValid"},
	{FRInternalSEL, FRInternalVariableTextIsRichTextSEL, L"FRInternalVariableTextIsRichText"},
	{FRInternalSEL, FRInternalVariableTextRearrangeAllSEL, L"FRInternalVariableTextRearrangeAll"},
	{FRInternalSEL, FRInternalVariableTextRearrangePartSEL, L"FRInternalVariableTextRearrangePart"},
	{FRInternalSEL, FRInternalVariableTextResetAllSEL, L"FRInternalVariableTextResetAll"},
	{FRInternalSEL, FRInternalVariableTextSetTextSEL, L"FRInternalVariableTextSetText"},
	{FRInternalSEL, FRInternalVariableTextInsertWordSEL, L"FRInternalVariableTextInsertWord"},
	{FRInternalSEL, FRInternalVariableTextInsertSectionSEL, L"FRInternalVariableTextInsertSection"},
	{FRInternalSEL, FRInternalVariableTextInsertTextSEL, L"FRInternalVariableTextInsertText"},
	{FRInternalSEL, FRInternalVariableTextDeleteWordsSEL, L"FRInternalVariableTextDeleteWords"},
	{FRInternalSEL, FRInternalVariableTextDeleteWordSEL, L"FRInternalVariableTextDeleteWord"},
	{FRInternalSEL, FRInternalVariableTextBackSpaceWordSEL, L"FRInternalVariableTextBackSpaceWord"},
	{FRInternalSEL, FRInternalVariableTextGetPlateRectSEL, L"FRInternalVariableTextGetPlateRect"},
	{FRInternalSEL, FRInternalVariableTextGetContentRectSEL, L"FRInternalVariableTextGetContentRect"},
	{FRInternalSEL, FRInternalVariableTextGetTotalWordsSEL, L"FRInternalVariableTextGetTotalWords"},
	{FRInternalSEL, FRInternalVariableTextGetFontSizeSEL, L"FRInternalVariableTextGetFontSize"},
	{FRInternalSEL, FRInternalVariableTextGetAlignmentSEL, L"FRInternalVariableTextGetAlignment"},
	{FRInternalSEL, FRInternalVariableTextGetWordSpaceSEL, L"FRInternalVariableTextGetWordSpace"},
	{FRInternalSEL, FRInternalVariableTextGetPasswordCharSEL, L"FRInternalVariableTextGetPasswordChar"},
	{FRInternalSEL, FRInternalVariableTextGetCharArraySEL, L"FRInternalVariableTextGetCharArray"},
	{FRInternalSEL, FRInternalVariableTextGetLimitCharSEL, L"FRInternalVariableTextGetLimitChar"},
	{FRInternalSEL, FRInternalVariableTextIsMultiLineSEL, L"FRInternalVariableTextIsMultiLine"},
	{FRInternalSEL, FRInternalVariableTextIsAutoReturnSEL, L"FRInternalVariableTextIsAutoReturn"},
	{FRInternalSEL, FRInternalVariableTextGetHorzScaleSEL, L"FRInternalVariableTextGetHorzScale"},
	{FRInternalSEL, FRInternalVariableTextGetCharSpaceSEL, L"FRInternalVariableTextGetCharSpace"},
	{FRInternalSEL, FRInternalVariableTextGetBeginWordPlaceSEL, L"FRInternalVariableTextGetBeginWordPlace"},
	{FRInternalSEL, FRInternalVariableTextGetEndWordPlaceSEL, L"FRInternalVariableTextGetEndWordPlace"},
	{FRInternalSEL, FRInternalVariableTextGetPrevWordPlaceSEL, L"FRInternalVariableTextGetPrevWordPlace"},
	{FRInternalSEL, FRInternalVariableTextGetNextWordPlaceSEL, L"FRInternalVariableTextGetNextWordPlace"},
	{FRInternalSEL, FRInternalVariableTextSearchWordPlaceSEL, L"FRInternalVariableTextSearchWordPlace"},
	{FRInternalSEL, FRInternalVariableTextGetUpWordPlaceSEL, L"FRInternalVariableTextGetUpWordPlace"},
	{FRInternalSEL, FRInternalVariableTextGetDownWordPlaceSEL, L"FRInternalVariableTextGetDownWordPlace"},
	{FRInternalSEL, FRInternalVariableTextGetLineBeginPlaceSEL, L"FRInternalVariableTextGetLineBeginPlace"},
	{FRInternalSEL, FRInternalVariableTextGetLineEndPlaceSEL, L"FRInternalVariableTextGetLineEndPlace"},
	{FRInternalSEL, FRInternalVariableTextGetSectionBeginPlaceSEL, L"FRInternalVariableTextGetSectionBeginPlace"},
	{FRInternalSEL, FRInternalVariableTextGetSectionEndPlaceSEL, L"FRInternalVariableTextGetSectionEndPlace"},
	{FRInternalSEL, FRInternalVariableTextUpdateWordPlaceSEL, L"FRInternalVariableTextUpdateWordPlace"},
	{FRInternalSEL, FRInternalVariableTextAjustLineHeaderSEL, L"FRInternalVariableTextAjustLineHeader"},
	{FRInternalSEL, FRInternalVariableTextWordPlaceToWordIndexSEL, L"FRInternalVariableTextWordPlaceToWordIndex"},
	{FRInternalSEL, FRInternalVariableTextWordIndexToWordPlaceSEL, L"FRInternalVariableTextWordIndexToWordPlace"},
	{FRInternalSEL, FRInternalVariableTextIsSectionComplexScriptSEL, L"FRInternalVariableTextIsSectionComplexScript"},
	{FRInternalSEL, FRInternalVariableTextIsVerticalFontSEL, L"FRInternalVariableTextIsVerticalFont"},
	{FRInternalSEL, FRInternalGetBulletIteratorSEL, L"FRInternalGetBulletIterator"},
	{FRInternalSEL, FRInternalEditFontMapGetDocFontMapSEL, L"FRInternalEditFontMapGetDocFontMap"},
	{FRInternalSEL, FRInternalEditFontMapEncodeFontAliasSEL, L"FRInternalEditFontMapEncodeFontAlias"},
	{FRInternalSEL, FRInternalEditFontMapGetFontNameSEL, L"FRInternalEditFontMapGetFontName"},
	{FRInternalSEL, FRInternalEditFontMapGetCharsetSEL, L"FRInternalEditFontMapGetCharset"},
	{FRInternalSEL, FRInternalEditFontMapGetFXFontSEL, L"FRInternalEditFontMapGetFXFont"},
	{FRInternalSEL, FRInternalEditFontMapGetPDFFontSEL, L"FRInternalEditFontMapGetPDFFont"},
	{FRInternalSEL, FRInternalEditFontMapGetCharWidthFSEL, L"FRInternalEditFontMapGetCharWidthF"},
	{FRInternalSEL, FRInternalEditFontMapCharCodeFromUnicodeSEL, L"FRInternalEditFontMapCharCodeFromUnicode"},
	{FRInternalSEL, FRInternalEditFontMapGlyphFromCharCodeSEL, L"FRInternalEditFontMapGlyphFromCharCode"},
	{FRInternalSEL, FRInternalEditFontMapCharSetFromUnicodeSEL, L"FRInternalEditFontMapCharSetFromUnicode"},
	{FRInternalSEL, FRInternalEditFontMapGetFontIndexByUnicodeSEL, L"FRInternalEditFontMapGetFontIndexByUnicode"},
	{FRInternalSEL, FRInternalEditFontMapGetFontIndexSEL, L"FRInternalEditFontMapGetFontIndex"},
	{FRInternalSEL, FRInternalIsEmbeddedSEL, L"FRInternalIsEmbedded"},
	{FRInternalSEL, FRInternalSetFXFMEditFontSEL, L"FRInternalSetFXFMEditFont"},
	{FRInternalSEL, FRInternalGlyphFromCharCode2SEL, L"FRInternalGlyphFromCharCode2"},
	{FRInternalSEL, FRInternalEditFontMapAddFXFontSEL, L"FRInternalEditFontMapAddFXFont"},
	{FRInternalSEL, FRInternalEditFontMapAddPDFFontSEL, L"FRInternalEditFontMapAddPDFFont"},
	{FRInternalSEL, FRInternalEditFontMapGetDocumentSEL, L"FRInternalEditFontMapGetDocument"},
	{FRInternalSEL, FRInternalEditFontMapLoadAllFontByDictSEL, L"FRInternalEditFontMapLoadAllFontByDict"},
	{FRInternalSEL, FRInternalEditFontMapCheckCharacterIsSupportedSEL, L"FRInternalEditFontMapCheckCharacterIsSupported"},
	{FRInternalSEL, FRInternalEditFontMapGetStandardFontSEL, L"FRInternalEditFontMapGetStandardFont"},
	{FRInternalSEL, FRInternalEditFontMapIsExternalEmbedFontSEL, L"FRInternalEditFontMapIsExternalEmbedFont"},
	{FRInternalSEL, FRInternalEditIteratorNextWordSEL, L"FRInternalEditIteratorNextWord"},
	{FRInternalSEL, FRInternalEditIteratorNextLineSEL, L"FRInternalEditIteratorNextLine"},
	{FRInternalSEL, FRInternalEditIteratorNextSectionSEL, L"FRInternalEditIteratorNextSection"},
	{FRInternalSEL, FRInternalEditIteratorPrevWordSEL, L"FRInternalEditIteratorPrevWord"},
	{FRInternalSEL, FRInternalEditIteratorPrevLineSEL, L"FRInternalEditIteratorPrevLine"},
	{FRInternalSEL, FRInternalEditIteratorPrevSectionSEL, L"FRInternalEditIteratorPrevSection"},
	{FRInternalSEL, FRInternalEditIteratorGetWordSEL, L"FRInternalEditIteratorGetWord"},
	{FRInternalSEL, FRInternalEditIteratorGetDisplayWordSEL, L"FRInternalEditIteratorGetDisplayWord"},
	{FRInternalSEL, FRInternalEditIteratorGetLineSEL, L"FRInternalEditIteratorGetLine"},
	{FRInternalSEL, FRInternalEditIteratorGetSectionSEL, L"FRInternalEditIteratorGetSection"},
	{FRInternalSEL, FRInternalEditIteratorSetAtSEL, L"FRInternalEditIteratorSetAt"},
	{FRInternalSEL, FRInternalEditIteratorSetAtIISEL, L"FRInternalEditIteratorSetAtII"},
	{FRInternalSEL, FRInternalEditIteratorGetAtSEL, L"FRInternalEditIteratorGetAt"},
	{FRInternalSEL, FRInternalEditIteratorGetEditSEL, L"FRInternalEditIteratorGetEdit"},
	{FRInternalSEL, FRInternalEditNewSEL, L"FRInternalEditNew"},
	{FRInternalSEL, FRInternalEditDelSEL, L"FRInternalEditDel"},
	{FRInternalSEL, FRInternalEditSetFontMapSEL, L"FRInternalEditSetFontMap"},
	{FRInternalSEL, FRInternalEditSetVTProviderSEL, L"FRInternalEditSetVTProvider"},
	{FRInternalSEL, FRInternalEditSetNotifySEL, L"FRInternalEditSetNotify"},
	{FRInternalSEL, FRInternalEditSetOprNotifySEL, L"FRInternalEditSetOprNotify"},
	{FRInternalSEL, FRInternalEditGetIteratorSEL, L"FRInternalEditGetIterator"},
	{FRInternalSEL, FRInternalEditGetVariableTextSEL, L"FRInternalEditGetVariableText"},
	{FRInternalSEL, FRInternalEditGetFontMapSEL, L"FRInternalEditGetFontMap"},
	{FRInternalSEL, FRInternalEditInitializeSEL, L"FRInternalEditInitialize"},
	{FRInternalSEL, FRInternalEditSetPlateRectSEL, L"FRInternalEditSetPlateRect"},
	{FRInternalSEL, FRInternalEditSetScrollPosSEL, L"FRInternalEditSetScrollPos"},
	{FRInternalSEL, FRInternalEditIsVerticalWritingSEL, L"FRInternalEditIsVerticalWriting"},
	{FRInternalSEL, FRInternalEditSetAlignmentHSEL, L"FRInternalEditSetAlignmentH"},
	{FRInternalSEL, FRInternalEditSetAlignmentVSEL, L"FRInternalEditSetAlignmentV"},
	{FRInternalSEL, FRInternalEditSetPasswordCharSEL, L"FRInternalEditSetPasswordChar"},
	{FRInternalSEL, FRInternalEditSetLimitCharSEL, L"FRInternalEditSetLimitChar"},
	{FRInternalSEL, FRInternalEditSetCharArraySEL, L"FRInternalEditSetCharArray"},
	{FRInternalSEL, FRInternalEditSetCharSpaceSEL, L"FRInternalEditSetCharSpace"},
	{FRInternalSEL, FRInternalEditSetWordSpaceSEL, L"FRInternalEditSetWordSpace"},
	{FRInternalSEL, FRInternalEditSetHorzScaleSEL, L"FRInternalEditSetHorzScale"},
	{FRInternalSEL, FRInternalEditSetLineLeadingSEL, L"FRInternalEditSetLineLeading"},
	{FRInternalSEL, FRInternalEditSetMultiLineSEL, L"FRInternalEditSetMultiLine"},
	{FRInternalSEL, FRInternalEditSetAutoReturnSEL, L"FRInternalEditSetAutoReturn"},
	{FRInternalSEL, FRInternalEditSetAutoFontSizeSEL, L"FRInternalEditSetAutoFontSize"},
	{FRInternalSEL, FRInternalEditSetAutoScrollSEL, L"FRInternalEditSetAutoScroll"},
	{FRInternalSEL, FRInternalEditSetFontSizeSEL, L"FRInternalEditSetFontSize"},
	{FRInternalSEL, FRInternalEditSetTextOverflowSEL, L"FRInternalEditSetTextOverflow"},
	{FRInternalSEL, FRInternalSetDirectionRTLSEL, L"FRInternalSetDirectionRTL"},
	{FRInternalSEL, FRInternalEditIsRichTextSEL, L"FRInternalEditIsRichText"},
	{FRInternalSEL, FRInternalEditSetRichTextSEL, L"FRInternalEditSetRichText"},
	{FRInternalSEL, FRInternalEditSetRichTextFontSEL, L"FRInternalEditSetRichTextFont"},
	{FRInternalSEL, FRInternalSetRichTextIsBoldSEL, L"FRInternalSetRichTextIsBold"},
	{FRInternalSEL, FRInternalSetRichTextIsItalicSEL, L"FRInternalSetRichTextIsItalic"},
	{FRInternalSEL, FRInternalEditSetRichFontSizeSEL, L"FRInternalEditSetRichFontSize"},
	{FRInternalSEL, FRInternalEditSetRichTextColorSEL, L"FRInternalEditSetRichTextColor"},
	{FRInternalSEL, FRInternalEditSetRichTextStrokeColorSEL, L"FRInternalEditSetRichTextStrokeColor"},
	{FRInternalSEL, FRInternalEditSetRichRenderingModeSEL, L"FRInternalEditSetRichRenderingMode"},
	{FRInternalSEL, FRInternalEditSetRichTextScriptSEL, L"FRInternalEditSetRichTextScript"},
	{FRInternalSEL, FRInternalEditSetRichTextUnderlineSEL, L"FRInternalEditSetRichTextUnderline"},
	{FRInternalSEL, FRInternalEditSetRichTextCrossoutSEL, L"FRInternalEditSetRichTextCrossout"},
	{FRInternalSEL, FRInternalEditSetRichTextCharSpaceSEL, L"FRInternalEditSetRichTextCharSpace"},
	{FRInternalSEL, FRInternalEditSetRichTextWordSpaceSEL, L"FRInternalEditSetRichTextWordSpace"},
	{FRInternalSEL, FRInternalEditSetRichTextHorzScaleSEL, L"FRInternalEditSetRichTextHorzScale"},
	{FRInternalSEL, FRInternalEditSetRichTextLineLeadingSEL, L"FRInternalEditSetRichTextLineLeading"},
	{FRInternalSEL, FRInternalEditSetRichTextLineIndentSEL, L"FRInternalEditSetRichTextLineIndent"},
	{FRInternalSEL, FRInternalEditSetRichTextAlignmentSEL, L"FRInternalEditSetRichTextAlignment"},
	{FRInternalSEL, FRInternalEditSetRichTextSoftReturnSEL, L"FRInternalEditSetRichTextSoftReturn"},
	{FRInternalSEL, FRInternalEditSetSelSEL, L"FRInternalEditSetSel"},
	{FRInternalSEL, FRInternalEditGetSelSEL, L"FRInternalEditGetSel"},
	{FRInternalSEL, FRInternalEditSelectAllSEL, L"FRInternalEditSelectAll"},
	{FRInternalSEL, FRInternalEditSelectNoneSEL, L"FRInternalEditSelectNone"},
	{FRInternalSEL, FRInternalEditGetCaretSEL, L"FRInternalEditGetCaret"},
	{FRInternalSEL, FRInternalEditGetCaretWordPlaceSEL, L"FRInternalEditGetCaretWordPlace"},
	{FRInternalSEL, FRInternalEditGetSelTextSEL, L"FRInternalEditGetSelText"},
	{FRInternalSEL, FRInternalEditGetTextSEL, L"FRInternalEditGetText"},
	{FRInternalSEL, FRInternalEditGetRichTextXMLSEL, L"FRInternalEditGetRichTextXML"},
	{FRInternalSEL, FRInternalEditIsSelectedSEL, L"FRInternalEditIsSelected"},
	{FRInternalSEL, FRInternalEditGetScrollPosSEL, L"FRInternalEditGetScrollPos"},
	{FRInternalSEL, FRInternalEditGetPlateRectSEL, L"FRInternalEditGetPlateRect"},
	{FRInternalSEL, FRInternalEditGetContentRectSEL, L"FRInternalEditGetContentRect"},
	{FRInternalSEL, FRInternalEditGetVisibleWordRangeSEL, L"FRInternalEditGetVisibleWordRange"},
	{FRInternalSEL, FRInternalEditGetWholeWordRangeSEL, L"FRInternalEditGetWholeWordRange"},
	{FRInternalSEL, FRInternalEditGetSelectWordRangeSEL, L"FRInternalEditGetSelectWordRange"},
	{FRInternalSEL, FRInternalEditOnMouseDownSEL, L"FRInternalEditOnMouseDown"},
	{FRInternalSEL, FRInternalEditOnMouseMoveSEL, L"FRInternalEditOnMouseMove"},
	{FRInternalSEL, FRInternalEditOnVK_UPSEL, L"FRInternalEditOnVK_UP"},
	{FRInternalSEL, FRInternalEditOnVK_DOWNSEL, L"FRInternalEditOnVK_DOWN"},
	{FRInternalSEL, FRInternalEditOnVK_LEFTSEL, L"FRInternalEditOnVK_LEFT"},
	{FRInternalSEL, FRInternalEditOnVK_RIGHTSEL, L"FRInternalEditOnVK_RIGHT"},
	{FRInternalSEL, FRInternalEditOnVK_HOMESEL, L"FRInternalEditOnVK_HOME"},
	{FRInternalSEL, FRInternalEditOnVK_ENDSEL, L"FRInternalEditOnVK_END"},
	{FRInternalSEL, FRInternalEditSetTextSEL, L"FRInternalEditSetText"},
	{FRInternalSEL, FRInternalEditSetRichTextByXMLSEL, L"FRInternalEditSetRichTextByXML"},
	{FRInternalSEL, FRInternalEditInsertWordSEL, L"FRInternalEditInsertWord"},
	{FRInternalSEL, FRInternalEditInsertReturnSEL, L"FRInternalEditInsertReturn"},
	{FRInternalSEL, FRInternalEditInsertTextSEL, L"FRInternalEditInsertText"},
	{FRInternalSEL, FRInternalEditBackspaceSEL, L"FRInternalEditBackspace"},
	{FRInternalSEL, FRInternalEditDeleteSEL, L"FRInternalEditDelete"},
	{FRInternalSEL, FRInternalEditClearSEL, L"FRInternalEditClear"},
	{FRInternalSEL, FRInternalEditRedoSEL, L"FRInternalEditRedo"},
	{FRInternalSEL, FRInternalEditUndoSEL, L"FRInternalEditUndo"},
	{FRInternalSEL, FRInternalEditSetCaretSEL, L"FRInternalEditSetCaret"},
	{FRInternalSEL, FRInternalEditPaintSEL, L"FRInternalEditPaint"},
	{FRInternalSEL, FRInternalEditEnableRefreshSEL, L"FRInternalEditEnableRefresh"},
	{FRInternalSEL, FRInternalEditRefreshWordRangeSEL, L"FRInternalEditRefreshWordRange"},
	{FRInternalSEL, FRInternalEditEnableUndoSEL, L"FRInternalEditEnableUndo"},
	{FRInternalSEL, FRInternalEditEnableNotifySEL, L"FRInternalEditEnableNotify"},
	{FRInternalSEL, FRInternalEditEnableOprNotifySEL, L"FRInternalEditEnableOprNotify"},
	{FRInternalSEL, FRInternalEditWordPlaceToWordIndexSEL, L"FRInternalEditWordPlaceToWordIndex"},
	{FRInternalSEL, FRInternalEditWordIndexToWordPlaceSEL, L"FRInternalEditWordIndexToWordPlace"},
	{FRInternalSEL, FRInternalEditGetLineBeginPlaceSEL, L"FRInternalEditGetLineBeginPlace"},
	{FRInternalSEL, FRInternalEditGetLineEndPlaceSEL, L"FRInternalEditGetLineEndPlace"},
	{FRInternalSEL, FRInternalEditGetSectionBeginPlaceSEL, L"FRInternalEditGetSectionBeginPlace"},
	{FRInternalSEL, FRInternalEditGetSectionEndPlaceSEL, L"FRInternalEditGetSectionEndPlace"},
	{FRInternalSEL, FRInternalEditSearchWordPlaceSEL, L"FRInternalEditSearchWordPlace"},
	{FRInternalSEL, FRInternalEditGetFontSizeSEL, L"FRInternalEditGetFontSize"},
	{FRInternalSEL, FRInternalEditGetPasswordCharSEL, L"FRInternalEditGetPasswordChar"},
	{FRInternalSEL, FRInternalEditGetCharArraySEL, L"FRInternalEditGetCharArray"},
	{FRInternalSEL, FRInternalEditGetHorzScaleSEL, L"FRInternalEditGetHorzScale"},
	{FRInternalSEL, FRInternalEditGetCharSpaceSEL, L"FRInternalEditGetCharSpace"},
	{FRInternalSEL, FRInternalEditGetRangeTextSEL, L"FRInternalEditGetRangeText"},
	{FRInternalSEL, FRInternalEditIsTextFullSEL, L"FRInternalEditIsTextFull"},
	{FRInternalSEL, FRInternalEditCanUndoSEL, L"FRInternalEditCanUndo"},
	{FRInternalSEL, FRInternalEditCanRedoSEL, L"FRInternalEditCanRedo"},
	{FRInternalSEL, FRInternalEditResetUndoSEL, L"FRInternalEditResetUndo"},
	{FRInternalSEL, FRInternalEditIsModifiedSEL, L"FRInternalEditIsModified"},
	{FRInternalSEL, FRInternalEditGetTotalWordsSEL, L"FRInternalEditGetTotalWords"},
	{FRInternalSEL, FRInternalEditAddUndoItemSEL, L"FRInternalEditAddUndoItem"},
	{FRInternalSEL, FRInternalBeginGroupUndoSEL, L"FRInternalBeginGroupUndo"},
	{FRInternalSEL, FRInternalEndGroupUndoSEL, L"FRInternalEndGroupUndo"},
	{FRInternalSEL, FRInternalEditSaveLineOffsetSEL, L"FRInternalEditSaveLineOffset"},
	{FRInternalSEL, FRInternalEditGetEditAppearanceStreamSEL, L"FRInternalEditGetEditAppearanceStream"},
	{FRInternalSEL, FRInternalEditGetRichEditAppearanceStreamSEL, L"FRInternalEditGetRichEditAppearanceStream"},
	{FRInternalSEL, FRInternalEditGetSelectAppearanceStreamSEL, L"FRInternalEditGetSelectAppearanceStream"},
	{FRInternalSEL, FRInternalEditDrawEditSEL, L"FRInternalEditDrawEdit"},
	{FRInternalSEL, FRInternalEditDrawUnderlineSEL, L"FRInternalEditDrawUnderline"},
	{FRInternalSEL, FRInternalEditDrawRichEditSEL, L"FRInternalEditDrawRichEdit"},
	{FRInternalSEL, FRInternalEditGeneratePageObjectsSEL, L"FRInternalEditGeneratePageObjects"},
	{FRInternalSEL, FRInternalEditGenerateRichPageObjectsSEL, L"FRInternalEditGenerateRichPageObjects"},
	{FRInternalSEL, FRInternalEditGenerateUnderlineObjectsSEL, L"FRInternalEditGenerateUnderlineObjects"},
	{FRInternalSEL, FRInternalEditGetRichTextPlainTextSEL, L"FRInternalEditGetRichTextPlainText"},
	{FRInternalSEL, FRInternalGetTouchupSEL, L"FRInternalGetTouchup"},
	{FRInternalSEL, FRInternalBeginEditTextObjectSEL, L"FRInternalBeginEditTextObject"},
	{FRInternalSEL, FRInternalEndEditTextObjectSEL, L"FRInternalEndEditTextObject"},
	{FRInternalSEL, FRInternalEmailUtilSendMailUseConfigSEL, L"FRInternalEmailUtilSendMailUseConfig"},
	{FRInternalSEL, FRInternalEmailUtilShowAddressBookSEL, L"FRInternalEmailUtilShowAddressBook"},
	{FRInternalSEL, FRInternalIsKeyAndTrialValidSEL, L"FRInternalIsKeyAndTrialValid"},
	{FRInternalSEL, FRInternalCheckLicenseSEL, L"FRInternalCheckLicense"},
	{FRInternalSEL, FRInternalEditIsPunctuationSEL, L"FRInternalEditIsPunctuation"},
	{FRInternalSEL, FRInternalEditIsCJKSEL, L"FRInternalEditIsCJK"},
	{FRInternalSEL, FRInternalEditIsLatinSEL, L"FRInternalEditIsLatin"},
	{FRInternalSEL, FRInternalEditIsNeedToConvertSpaceSEL, L"FRInternalEditIsNeedToConvertSpace"},
	{FRInternalSEL, FRInternalGetCustomStringSEL, L"FRInternalGetCustomString"},
	{FRInternalSEL, FRInternalEditDestroyNotifySEL, L"FRInternalEditDestroyNotify"},
	{FRInternalSEL, FRInternalEditDestroyOprNotifySEL, L"FRInternalEditDestroyOprNotify"},
	{FRInternalSEL, FRInternalSetDocReviewIdentitySEL, L"FRInternalSetDocReviewIdentity"},
	{FRInternalSEL, FRInternalGetDocReviewIdentityNameSEL, L"FRInternalGetDocReviewIdentityName"},
	{FRInternalSEL, FRInternalGetDocReviewIdentityEmailSEL, L"FRInternalGetDocReviewIdentityEmail"},
	{FRInternalSEL, FRInternalHasVisibleTextObjSEL, L"FRInternalHasVisibleTextObj"},
	{FRInternalSEL, FRInternalGetProfStoreManagerSEL, L"FRInternalGetProfStoreManager"},
	{FRInternalSEL, FRInternalProfStoreGetStringSEL, L"FRInternalProfStoreGetString"},
	{FRInternalSEL, FRInternalProfStoreGetIntSEL, L"FRInternalProfStoreGetInt"},
	{FRInternalSEL, FRInternalProfStoreGetBooleanSEL, L"FRInternalProfStoreGetBoolean"},
	{FRInternalSEL, FRInternalProfStoreEnumAllKeyNameSEL, L"FRInternalProfStoreEnumAllKeyName"},
	{FRInternalSEL, FRInternalProfStoreEnumKeyNameSEL, L"FRInternalProfStoreEnumKeyName"},
	{FRInternalSEL, FRInternalProfStoreEnumKeyValueNameSEL, L"FRInternalProfStoreEnumKeyValueName"},
	{FRInternalSEL, FRInternalProfStoreEnumKeyValueSEL, L"FRInternalProfStoreEnumKeyValue"},
	{FRInternalSEL, FRInternalGWL10NHelperAutoResizeDropWidthSEL, L"FRInternalGWL10NHelperAutoResizeDropWidth"},
	{FRInternalSEL, FRInternalGWL10NHelperResetItemDropWidthSEL, L"FRInternalGWL10NHelperResetItemDropWidth"},
	{FRInternalSEL, FRInternalGetActivePopupMenuMessageWndSEL, L"FRInternalGetActivePopupMenuMessageWnd"},
	{FRInternalSEL, FRInternalGetPhoneNumberSEL, L"FRInternalGetPhoneNumber"},
	{FRInternalSEL, FRInternalGetEditionTitleSEL, L"FRInternalGetEditionTitle"},
	{FRInternalSEL, FRInternalGetEmailSEL, L"FRInternalGetEmail"},
	{FRInternalSEL, FRInternalEditGetWordLatinSmallLigatureSEL, L"FRInternalEditGetWordLatinSmallLigature"},
	{FRInternalSEL, FRInternalGetClonedDocSEL, L"FRInternalGetClonedDoc"},
	{FRInternalSEL, FRInternalEditFontMapReleaseDocFontMapSEL, L"FRInternalEditFontMapReleaseDocFontMap"},
	{FRInternalSEL, FRInternalCreateActionWizardHandlerMgrSEL, L"FRInternalCreateActionWizardHandlerMgr"},
	{FRInternalSEL, FRInternalDestroyActionWizardHandlerMgrSEL, L"FRInternalDestroyActionWizardHandlerMgr"},
	{FRInternalSEL, FRInternalSetActionWizardHandlerMgrSEL, L"FRInternalSetActionWizardHandlerMgr"},
	{FRInternalSEL, FRInternalGetActionWizardHandlerMgrSEL, L"FRInternalGetActionWizardHandlerMgr"},
	{FRInternalSEL, FRInternalCreateActionWizardHandlerSEL, L"FRInternalCreateActionWizardHandler"},
	{FRInternalSEL, FRInternalDestroyActionWizardHandlerSEL, L"FRInternalDestroyActionWizardHandler"},
	{FRInternalSEL, FRInternalRegisterActionWizardHandlerSEL, L"FRInternalRegisterActionWizardHandler"},
	{FRInternalSEL, FRInternalUnRegisterActionWizardHandlerSEL, L"FRInternalUnRegisterActionWizardHandler"},
	{FRInternalSEL, FRInternalActionWizardHandlerGetNameSEL, L"FRInternalActionWizardHandlerGetName"},
	{FRInternalSEL, FRInternalActionWizardHandlerGetCommandNameSEL, L"FRInternalActionWizardHandlerGetCommandName"},
	{FRInternalSEL, FRInternalActionWizardHandlerGetPresetFlagSEL, L"FRInternalActionWizardHandlerGetPresetFlag"},
	{FRInternalSEL, FRInternalActionWizardHandlerSettingSEL, L"FRInternalActionWizardHandlerSetting"},
	{FRInternalSEL, FRInternalActionWizardHandlerExecuteSEL, L"FRInternalActionWizardHandlerExecute"},
	{FRInternalSEL, FRInternalActionWizardHandlerGetTitleSEL, L"FRInternalActionWizardHandlerGetTitle"},
	{FRInternalSEL, FRInternalActionWizardHandlerNeedReopenSEL, L"FRInternalActionWizardHandlerNeedReopen"},
	{FRInternalSEL, FRInternalActionWizardHandlerNeedChangeExecuteDocSEL, L"FRInternalActionWizardHandlerNeedChangeExecuteDoc"},
	{FRInternalSEL, FRInternalExportAnnotToXFDF2SEL, L"FRInternalExportAnnotToXFDF2"},
	{FRInternalSEL, FRInternalImprotAnnotFromXFDF2SEL, L"FRInternalImprotAnnotFromXFDF2"},
	{FRInternalSEL, FRInternalSubscribeShowRibbonUISEL, L"FRInternalSubscribeShowRibbonUI"},
	{FRInternalSEL, FRInternalSubscribeStartWorkflowSEL, L"FRInternalSubscribeStartWorkflow"},
	{FRInternalSEL, FRInternalSubscribeIsLicenseRevokedSEL, L"FRInternalSubscribeIsLicenseRevoked"},
	{FRInternalSEL, FRInternalSubscribeShowFlashSEL, L"FRInternalSubscribeShowFlash"},
	{FRInternalSEL, FRInternalCPDFPluginProviderSetSEL, L"FRInternalCPDFPluginProviderSet"},
	{FRInternalSEL, FRInternalCPDFPluginProviderDestroySEL, L"FRInternalCPDFPluginProviderDestroy"},
	{FRInternalSEL, FRInternalCPDFPluginProviderGetSEL, L"FRInternalCPDFPluginProviderGet"},
	{FRInternalSEL, FRInternalCPDFPluginProviderShowConnectedPDFAdDialogSEL, L"FRInternalCPDFPluginProviderShowConnectedPDFAdDialog"},
	{FRInternalSEL, FRInternalGetRemainDaysSEL, L"FRInternalGetRemainDays"},
	{FRInternalSEL, FRInternalCommentsAnnotSetUpdateServerTimeSEL, L"FRInternalCommentsAnnotSetUpdateServerTime"},
	{FRInternalSEL, FRInternalGetLicenseSNSEL, L"FRInternalGetLicenseSN"},
	{FRInternalSEL, FRInternalGetKeyfileTypeSEL, L"FRInternalGetKeyfileType"},
	{FRInternalSEL, FRInternalGetFormatSymbolStringSEL, L"FRInternalGetFormatSymbolString"},
	{FRInternalSEL, FRInternalGetLocalFormatTimeStringSEL, L"FRInternalGetLocalFormatTimeString"},
	{FRInternalSEL, FRInternalConvertToPDFGetFileTypeSEL, L"FRInternalConvertToPDFGetFileType"},
	{FRInternalSEL, FRInternalGetFileFilterSEL, L"FRInternalGetFileFilter"},
	{FRInternalSEL, FRInternalRegisterDocHandlerOfPDDocForActionWizardSEL, L"FRInternalRegisterDocHandlerOfPDDocForActionWizard"},
	{FRInternalSEL, FRInternalCommentsAnnotSetIconStateSEL, L"FRInternalCommentsAnnotSetIconState"},
	{FRInternalSEL, FRInternalGetAnnotInputFontNameSEL, L"FRInternalGetAnnotInputFontName"},
	{FRInternalSEL, FRInternalIsDisableCPDFSEL, L"FRInternalIsDisableCPDF"},
	{FRInternalSEL, FRInternalRunJSPluginByFlagSEL, L"FRInternalRunJSPluginByFlag"},
	{FRInternalSEL, FRInternalRunJSPluginByNameSEL, L"FRInternalRunJSPluginByName"},
	{FRInternalSEL, FRInternalIsJSPanelActivatedSEL, L"FRInternalIsJSPanelActivated"},
	{FRInternalSEL, FRInternalExpandJSPanelSEL, L"FRInternalExpandJSPanel"},
	{FRInternalSEL, FRInternalEditSetDrawNotifySEL, L"FRInternalEditSetDrawNotify"},
	{FRInternalSEL, FRInternalEditDestroyDrawNotifySEL, L"FRInternalEditDestroyDrawNotify"},
	{FRInternalSEL, FRInternalEmailUtilRegisterPreSendMailHandlerSEL, L"FRInternalEmailUtilRegisterPreSendMailHandler"},
	{FRInternalSEL, FRInternalGetCurEditonTitleSEL, L"FRInternalGetCurEditonTitle"},
	{FRInternalSEL, FRInternalIsDisableInternetSEL, L"FRInternalIsDisableInternet"},
	{FRInternalSEL, FRInternalIsUseSystemSelectionColorSEL, L"FRInternalIsUseSystemSelectionColor"},
	{FRInternalSEL, FRInternalEditSetSelBkColorSEL, L"FRInternalEditSetSelBkColor"},
	{FRInternalSEL, FRInternalEditDrawRichEdit2SEL, L"FRInternalEditDrawRichEdit2"},
	{FRInternalSEL, FRInternalIsJSPluginDisabledSEL, L"FRInternalIsJSPluginDisabled"},
	{FRInternalSEL, FRInternalGetAccReadingOrderModeSEL, L"FRInternalGetAccReadingOrderMode"},
	{FRInternalSEL, FRInternalIsAccOverrideReadingOrderSEL, L"FRInternalIsAccOverrideReadingOrder"},
	{FRInternalSEL, FRInternalGetDocAccReadingOrderSEL, L"FRInternalGetDocAccReadingOrder"},
	{FRInternalSEL, FRInternalGetDocAccReadingModeSEL, L"FRInternalGetDocAccReadingMode"},
	{FRInternalSEL, FRInternalSetReadActivateStatusSEL, L"FRInternalSetReadActivateStatus"},
	{FRInternalSEL, FRInternalGetReadActivateStatusSEL, L"FRInternalGetReadActivateStatus"},
	{FRInternalSEL, FRInternalWIPPluginProviderSetSEL, L"FRInternalWIPPluginProviderSet"},
	{FRInternalSEL, FRInternalWIPPluginProviderDestroySEL, L"FRInternalWIPPluginProviderDestroy"},
	{FRInternalSEL, FRInternalWIPPluginProviderGetSEL, L"FRInternalWIPPluginProviderGet"},
	{FRInternalSEL, FRInternalWIPPluginProviderAllowedPasteSEL, L"FRInternalWIPPluginProviderAllowedPaste"},
	{FRInternalSEL, FRInternalThemeCheckHCMTSEL, L"FRInternalThemeCheckHCMT"},
	{FRInternalSEL, FRInternalThemeGetTextColorSEL, L"FRInternalThemeGetTextColor"},
	{FRInternalSEL, FRInternalThemeGetDisableTextColorSEL, L"FRInternalThemeGetDisableTextColor"},
	{FRInternalSEL, FRInternalThemeGetHyperlinkTextColorSEL, L"FRInternalThemeGetHyperlinkTextColor"},
	{FRInternalSEL, FRInternalThemeGetSelectedTextColorSEL, L"FRInternalThemeGetSelectedTextColor"},
	{FRInternalSEL, FRInternalThemeGetButtonTextColorSEL, L"FRInternalThemeGetButtonTextColor"},
	{FRInternalSEL, FRInternalThemeGetTooltipColorSEL, L"FRInternalThemeGetTooltipColor"},
	{FRInternalSEL, FRInternalThemeGetBackgroundColorSEL, L"FRInternalThemeGetBackgroundColor"},
	{FRInternalSEL, FRInternalEmailUtilRegisterAttachmentNameModifierSEL, L"FRInternalEmailUtilRegisterAttachmentNameModifier"},
	{FRInternalSEL, FRInternalGetAppSaveAsLocationSEL, L"FRInternalGetAppSaveAsLocation"},
	{FRInternalSEL, FRInternalLoadJSPluginSEL, L"FRInternalLoadJSPlugin"},
	{FRInternalSEL, FRInternalActionWizardHandlerIsEnableExecuteSEL, L"FRInternalActionWizardHandlerIsEnableExecute"},
	{FRInternalSEL, FRInternalActionWizardHandlerExecuteDoneSEL, L"FRInternalActionWizardHandlerExecuteDone"},
	{FRInternalSEL, FRInternalEditFontMapGetFontIndexByUnicode2SEL, L"FRInternalEditFontMapGetFontIndexByUnicode2"},
	{FRInternalSEL, FRInternalEditFontMapGetFontIndex2SEL, L"FRInternalEditFontMapGetFontIndex2"},
	{FRInternalSEL, FRInternalCompareGetDifInfosSEL, L"FRInternalCompareGetDifInfos"},
	{FRInternalSEL, FRInternalCompareReleaseDifInfosSEL, L"FRInternalCompareReleaseDifInfos"},
	{FRInternalSEL, FRInternalCompareDrawNoteAPSEL, L"FRInternalCompareDrawNoteAP"},
	{FRInternalSEL, FRInternalGetCreationDateSEL, L"FRInternalGetCreationDate"},
	{FRInternalSEL, FRInternalSetReadStatusSEL, L"FRInternalSetReadStatus"},
	{FRInternalSEL, FRInternalGetReadStatusSEL, L"FRInternalGetReadStatus"},
	{FRInternalSEL, FRInternalCheckActualLicenseSEL, L"FRInternalCheckActualLicense"},
	{FRInternalSEL, FRInternalOpenCreatedPDFDocSEL, L"FRInternalOpenCreatedPDFDoc"},
	{FRInternalSEL, FRInternalGetIsPheeModeSEL, L"FRInternalGetIsPheeMode"},
	{FRInternalSEL, FRInternalEditSetEastenArabicNumeralModeSEL, L"FRInternalEditSetEastenArabicNumeralMode"},
	{FRInternalSEL, FRInternalActionWizardLogCreateSEL, L"FRInternalActionWizardLogCreate"},
	{FRInternalSEL, FRInternalActionWizardLogWriteDetailInfoSEL, L"FRInternalActionWizardLogWriteDetailInfo"},
	{FRInternalSEL, FRInternalActionWizardLogWriteCurrentTimeSEL, L"FRInternalActionWizardLogWriteCurrentTime"},
	{FRInternalSEL, FRInternalActionWizardLogWriteBoundaryInfoSEL, L"FRInternalActionWizardLogWriteBoundaryInfo"},
	{FRInternalSEL, FRInternalActionWizardLogGenerateSEL, L"FRInternalActionWizardLogGenerate"},
	{FRInternalSEL, FRInternalActionWizardLogCloseSEL, L"FRInternalActionWizardLogClose"},
	{FRInternalSEL, FRInternalActionWizardLogWriteSEL, L"FRInternalActionWizardLogWrite"},
	{FRInternalSEL, FRInternalActionWizardLogGetStateSEL, L"FRInternalActionWizardLogGetState"},
	{FRInternalSEL, FRInternalActionWizardLogGetLastFilePathSEL, L"FRInternalActionWizardLogGetLastFilePath"},
	{FRInternalSEL, FRInternalActionWizardLogSetCurFilePathSEL, L"FRInternalActionWizardLogSetCurFilePath"},
	{FRInternalSEL, FRInternalActionWizardLogSetExcuteFileStatusSEL, L"FRInternalActionWizardLogSetExcuteFileStatus"},
	{FRInternalSEL, FRInternalGetUpgExpDateSEL, L"FRInternalGetUpgExpDate"},
	{FRInternalSEL, FRInternalIsUsedAnotherPerpetualLicenseSEL, L"FRInternalIsUsedAnotherPerpetualLicense"},
	{FRInternalSEL, FRInternalBaseAnnoteIsSnap2GridEnabledSEL, L"FRInternalBaseAnnoteIsSnap2GridEnabled"},
	{FRInternalSEL, FRInternalBaseAnnoteGetGridLineSEL, L"FRInternalBaseAnnoteGetGridLine"},
	{FRInternalSEL, FRInternalBaseAnnoteGetGridMainLineSEL, L"FRInternalBaseAnnoteGetGridMainLine"},
	{FRInternalSEL, FRInternalAddDocToPrivilegedListSEL, L"FRInternalAddDocToPrivilegedList"},
	{FRInternalSEL, FRInternalIsPrivilegedFileSEL, L"FRInternalIsPrivilegedFile"},
	{FRInternalSEL, FRInternalIsDisableInternet2SEL, L"FRInternalIsDisableInternet2"},
	{FRInternalSEL, FRInternalIsSimpleChineseVersionSEL, L"FRInternalIsSimpleChineseVersion"},
	{FRInternalSEL, FRInternalGetLicenseeSEL, L"FRInternalGetLicensee"},
	{FRInternalSEL, FRInternalEditFontMapGetFontIndexByUnicode3SEL, L"FRInternalEditFontMapGetFontIndexByUnicode3"},
	{FRInternalSEL, FRInternalEditFontMapGetFontIndex3SEL, L"FRInternalEditFontMapGetFontIndex3"},
	{FRInternalSEL, FRInternalEditFontMapAddFXFont2SEL, L"FRInternalEditFontMapAddFXFont2"},
	{FRInternalSEL, FRInternalEditFontMapAddPDFFont2SEL, L"FRInternalEditFontMapAddPDFFont2"},
	{FRInternalSEL, FRInternalEditSetRichTextFont2SEL, L"FRInternalEditSetRichTextFont2"},
	{FRInternalSEL, FRInternalEditFontMapGetFontName2SEL, L"FRInternalEditFontMapGetFontName2"},
	{FRInternalSEL, FRInternalClearDragRectsSEL, L"FRInternalClearDragRects"},
	{FRInternalSEL, FRInternalOnMovedByPointSEL, L"FRInternalOnMovedByPoint"},
	{FRInternalSEL, FRInternalOnMovedByRectSEL, L"FRInternalOnMovedByRect"},
	{FRInternalSEL, FRInternalSaveKeepToolSelectedToRegistrySEL, L"FRInternalSaveKeepToolSelectedToRegistry"},
	{FRInternalSEL, FRInternalEnableKeepToolSelectedSEL, L"FRInternalEnableKeepToolSelected"},
	{FRInternalSEL, FRInternalChangeKeepToolSelectedStateFromRegistrySEL, L"FRInternalChangeKeepToolSelectedStateFromRegistry"},
	{FRInternalSEL, FRInternalAddDragRectSEL, L"FRInternalAddDragRect"},
	{FRInternalSEL, FRInternalResetSEL, L"FRInternalReset"},
	{FRInternalSEL, FRInternalRunPageFlatSEL, L"FRInternalRunPageFlat"},
	{FRInternalSEL, FRInternalGetCurrentUserNameSEL, L"FRInternalGetCurrentUserName"},
	{FRInternalSEL, FRInternalEncryptAttachmentSEL, L"FRInternalEncryptAttachment"},
	{FRInternalSEL, FRInternalGetAllFormatFontSizeSEL, L"FRInternalGetAllFormatFontSize"},
	{FRInternalSEL, FRInternalGetAtAllFormatFontSEL, L"FRInternalGetAtAllFormatFont"},
	{FRInternalSEL, FRInternalGetFontFaceNameBoldItalicSEL, L"FRInternalGetFontFaceNameBoldItalic"},
	{FRInternalSEL, FRInternalGetFontStyleSEL, L"FRInternalGetFontStyle"},
	{FRInternalSEL, FRInternalEditSetEnableMLAutoFullFontSizeSEL, L"FRInternalEditSetEnableMLAutoFullFontSize"},
	{FRInternalSEL, FRInternalFlattenDynamicXFADocSEL, L"FRInternalFlattenDynamicXFADoc"},
	{FRInternalSEL, FRInternalIsSelfSignCertGenSEL, L"FRInternalIsSelfSignCertGen"},
	{FRInternalSEL, FRInternalGetIsCheckPrivateKeyCertSEL, L"FRInternalGetIsCheckPrivateKeyCert"},
	{FRInternalSEL, FRInternalParseMailtoURISEL, L"FRInternalParseMailtoURI"},
	{FRInternalSEL, FRInternalIsMailtoURISEL, L"FRInternalIsMailtoURI"},
	{FRInternalSEL, FRInternalAsyncUpdateCheckerInfoSEL, L"FRInternalAsyncUpdateCheckerInfo"},
	{FRInternalSEL, FRInternalIsCurrentToolSEL, L"FRInternalIsCurrentTool"},
	{FRInternalSEL, FRInternalSetToolModeSEL, L"FRInternalSetToolMode"},
	{FRInternalSEL, FRInternalGetToolModeSEL, L"FRInternalGetToolMode"},
	{FRInternalSEL, FRInternalSetPreToolHandlerSEL, L"FRInternalSetPreToolHandler"},
	{FRInternalSEL, FRInternalEmailUtilSendMailUseConfig2SEL, L"FRInternalEmailUtilSendMailUseConfig2"},
	{FRInternalSEL, FRInternalDIBSourceToBmpSEL, L"FRInternalDIBSourceToBmp"},
	{FRInternalSEL, FRInternalBeginBulletEditingSEL, L"FRInternalBeginBulletEditing"},
	{FRInternalSEL, FRInternalBeginBulletEditing2SEL, L"FRInternalBeginBulletEditing2"},
	{FRInternalSEL, FRInternalSetNotifySEL, L"FRInternalSetNotify"},
	{FRInternalSEL, FRInternalOnCharTabSEL, L"FRInternalOnCharTab"},
	{FRInternalSEL, FRInternalGetLicenseEditonSEL, L"FRInternalGetLicenseEditon"},
	{FRInternalSEL, FRInternalGetPropsSecSpaceSEL, L"FRInternalGetPropsSecSpace"},
	{FRInternalSEL, FRInternalIsUndoRedoingSEL, L"FRInternalIsUndoRedoing"},
	{FRInternalSEL, FRInternalBeginGroupSEL, L"FRInternalBeginGroup"},
	{FRInternalSEL, FRInternalEndGroupSEL, L"FRInternalEndGroup"},
	{FRInternalSEL, FRInternalGetUndoDescriptionSEL, L"FRInternalGetUndoDescription"},
	{FRInternalSEL, FRInternalGetRedoDescriptionSEL, L"FRInternalGetRedoDescription"},
	{FRInternalSEL, FRInternalLoadPopupMenuStringSEL, L"FRInternalLoadPopupMenuString"},
	{FRInternalSEL, FRInternalReleaseBulletNotifySEL, L"FRInternalReleaseBulletNotify"},
	{FRInternalSEL, FRInternalEndBulletEditingSEL, L"FRInternalEndBulletEditing"},
	{FRInternalSEL, FRInternalIsSupportSymbolSEL, L"FRInternalIsSupportSymbol"},
	{FRInternalSEL, FRInternalRunOCRSEL, L"FRInternalRunOCR"},
	{FRInternalSEL, FRInternalGetLocalAbyLanSEL, L"FRInternalGetLocalAbyLan"},
	{FRInternalSEL, FRInternalbExistFX_Abbyy_Ocr_dllSEL, L"FRInternalbExistFX_Abbyy_Ocr_dll"},
	{FRInternalSEL, FRInternalGetOCREngineSupportLanSEL, L"FRInternalGetOCREngineSupportLan"},
	{FRInternalSEL, FRInternalLoadAnnotIconSEL, L"FRInternalLoadAnnotIcon"},
	{FRInternalSEL, FRInternalSubscribeIsEducationSEL, L"FRInternalSubscribeIsEducation"},
	{FRInternalSEL, FRInternalAddFloatyBarBtnSEL, L"FRInternalAddFloatyBarBtn"},
	{FRInternalSEL, FRInternalAddRibbonBtnsToFloatySEL, L"FRInternalAddRibbonBtnsToFloaty"},
	{FRInternalSEL, FRInternalCreateRibbonFloatySEL, L"FRInternalCreateRibbonFloaty"},
	{FRInternalSEL, FRInternalUndoSEL, L"FRInternalUndo"},
	{FRInternalSEL, FRInternalRedoSEL, L"FRInternalRedo"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetSystemHandlerSEL, L"FRInternalPWLWndCreationParamSetSystemHandler"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetProviderSEL, L"FRInternalPWLWndCreationParamSetProvider"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetFocusHandlerSEL, L"FRInternalPWLWndCreationParamSetFocusHandler"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetBackgroundColorSEL, L"FRInternalPWLWndCreationParamSetBackgroundColor"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetAttachedWndSEL, L"FRInternalPWLWndCreationParamSetAttachedWnd"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetSpellCheckSEL, L"FRInternalPWLWndCreationParamSetSpellCheck"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetBorderStyleSEL, L"FRInternalPWLWndCreationParamSetBorderStyle"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetBorderWidthSEL, L"FRInternalPWLWndCreationParamSetBorderWidth"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetBorderColorSEL, L"FRInternalPWLWndCreationParamSetBorderColor"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetTextStrokeColorSEL, L"FRInternalPWLWndCreationParamSetTextStrokeColor"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetTransparencySEL, L"FRInternalPWLWndCreationParamSetTransparency"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetUseFXFontDeAscentSEL, L"FRInternalPWLWndCreationParamSetUseFXFontDeAscent"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetDashSEL, L"FRInternalPWLWndCreationParamSetDash"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetAttachedDataSEL, L"FRInternalPWLWndCreationParamSetAttachedData"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetParentWndSEL, L"FRInternalPWLWndCreationParamSetParentWnd"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetCursorTypeSEL, L"FRInternalPWLWndCreationParamSetCursorType"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetMtChildSEL, L"FRInternalPWLWndCreationParamSetMtChild"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetShowFontSizeDPISEL, L"FRInternalPWLWndCreationParamSetShowFontSizeDPI"},
	{FRInternalSEL, FRInternalPWLWndCreationParamSetNeedEmbedSEL, L"FRInternalPWLWndCreationParamSetNeedEmbed"},
	{FRInternalSEL, FRInternalOpenCertifiedPDF2SEL, L"FRInternalOpenCertifiedPDF2"},
	{FRInternalSEL, FRInternalFieldsMutiCopySEL, L"FRInternalFieldsMutiCopy"},
	{FRInternalSEL, FRInternalCreateDigitalIDSEL, L"FRInternalCreateDigitalID"},
	{FRInternalSEL, FRInternalOpenDigitalIDsManagerSEL, L"FRInternalOpenDigitalIDsManager"},
	{FRInternalSEL, FRInternalSetIsCheckPrivateKeyCertSEL, L"FRInternalSetIsCheckPrivateKeyCert"},
	{FRInternalSEL, FRInternalPWLWndCreationParamNew2SEL, L"FRInternalPWLWndCreationParamNew2"},
	{FRInternalSEL, FRInternalArabicResetWordSEL, L"FRInternalArabicResetWord"},
	{FRInternalSEL, FRInternalOnDestroyDocViewSEL, L"FRInternalOnDestroyDocView"},
	{FRInternalSEL, FRInternalEditSetText2SEL, L"FRInternalEditSetText2"},
	{FRInternalSEL, FRInternalWipPluginEncryptFileSEL, L"FRInternalWipPluginEncryptFile"},
	{FRInternalSEL, FRInternalCreatePrintMgrSEL, L"FRInternalCreatePrintMgr"},
	{FRInternalSEL, FRInternalSetPrintRangeSEL, L"FRInternalSetPrintRange"},
	{FRInternalSEL, FRInternalSetPrintRotateSEL, L"FRInternalSetPrintRotate"},
	{FRInternalSEL, FRInternalSetPrintScaleSEL, L"FRInternalSetPrintScale"},
	{FRInternalSEL, FRInternalSetPrintAutoCenterSEL, L"FRInternalSetPrintAutoCenter"},
	{FRInternalSEL, FRInternalSetPrintAutoRotateSEL, L"FRInternalSetPrintAutoRotate"},
	{FRInternalSEL, FRInternalSetPrintGraySEL, L"FRInternalSetPrintGray"},
	{FRInternalSEL, FRInternalSetPrintCollateSEL, L"FRInternalSetPrintCollate"},
	{FRInternalSEL, FRInternalSetPrintPageOrderSEL, L"FRInternalSetPrintPageOrder"},
	{FRInternalSEL, FRInternalSetPrintPrintWhatSEL, L"FRInternalSetPrintPrintWhat"},
	{FRInternalSEL, FRInternalSetPrintOrientationSEL, L"FRInternalSetPrintOrientation"},
	{FRInternalSEL, FRInternalSetPrintPagesPerSheetSEL, L"FRInternalSetPrintPagesPerSheet"},
	{FRInternalSEL, FRInternalSetPrintPaperSizeByPageSEL, L"FRInternalSetPrintPaperSizeByPage"},
	{FRInternalSEL, FRInternalSetPrintReverseSEL, L"FRInternalSetPrintReverse"},
	{FRInternalSEL, FRInternalSetPrintMarginsSEL, L"FRInternalSetPrintMargins"},
	{FRInternalSEL, FRInternalSetPrintAsImageSEL, L"FRInternalSetPrintAsImage"},
	{FRInternalSEL, FRInternalSetSimulateOverprintingSEL, L"FRInternalSetSimulateOverprinting"},
	{FRInternalSEL, FRInternalSetPrintIgnoreAdvancedSettingSEL, L"FRInternalSetPrintIgnoreAdvancedSetting"},
	{FRInternalSEL, FRInternalSetProgressDisplaySEL, L"FRInternalSetProgressDisplay"},
	{FRInternalSEL, FRInternalSetPaperSizeSEL, L"FRInternalSetPaperSize"},
	{FRInternalSEL, FRInternalSetPrintPageArraySEL, L"FRInternalSetPrintPageArray"},
	{FRInternalSEL, FRInternalGetDefaultPrintSEL, L"FRInternalGetDefaultPrint"},
	{FRInternalSEL, FRInternalSetDefaultPrintSEL, L"FRInternalSetDefaultPrint"},
	{FRInternalSEL, FRInternalSetPrintOutputFileNameSEL, L"FRInternalSetPrintOutputFileName"},
	{FRInternalSEL, FRInternalDoModalSEL, L"FRInternalDoModal"},
	{FRInternalSEL, FRInternalDeletePrintMgSEL, L"FRInternalDeletePrintMg"},
	{FRInternalSEL, FRInternalIsSearchingTextSEL, L"FRInternalIsSearchingText"},
	{FRInternalSEL, FRInternalWaitingFileClosedSEL, L"FRInternalWaitingFileClosed"},
	{FRInternalSEL, FRInternalConvertPdfFromWebSEL, L"FRInternalConvertPdfFromWeb"},
	{FRInternalSEL, FRInternalGetFromClipboardSEL, L"FRInternalGetFromClipboard"},
	{FRInternalSEL, FRInternalCreateTwainDriverSEL, L"FRInternalCreateTwainDriver"},
	{FRInternalSEL, FRInternalDeleteTwainDriverSEL, L"FRInternalDeleteTwainDriver"},
	{FRInternalSEL, FRInternalGetMenuItemSEL, L"FRInternalGetMenuItem"},
	{FRInternalSEL, FRInternalEnableInsertPositionSEL, L"FRInternalEnableInsertPosition"},
	{FRInternalSEL, FRInternalSetCurTypeSEL, L"FRInternalSetCurType"},
	{FRInternalSEL, FRInternalShowDialogSEL, L"FRInternalShowDialog"},
	{FRInternalSEL, FRInternalSetInsertPositionSEL, L"FRInternalSetInsertPosition"},
	{FRInternalSEL, FRInternalSetAppendFileInsertPosSEL, L"FRInternalSetAppendFileInsertPos"},
	{FRInternalSEL, FRInternalGetRecordOperSEL, L"FRInternalGetRecordOper"},
	{FRInternalSEL, FRInternalGetDataCountSEL, L"FRInternalGetDataCount"},
	{FRInternalSEL, FRInternalGetPresetNameAtSEL, L"FRInternalGetPresetNameAt"},
	{FRInternalSEL, FRInternalStartScanSEL, L"FRInternalStartScan"},
	{FRInternalSEL, FRInternalSameNameFieldExistSEL, L"FRInternalSameNameFieldExist"},
	{FRInternalSEL, FRInternalShowRenameMsgSEL, L"FRInternalShowRenameMsg"},
	{FRInternalSEL, FRInternalConvertPdfFromWeb2SEL, L"FRInternalConvertPdfFromWeb2"},
	{FRInternalSEL, FRInternalCopyFieldsSEL, L"FRInternalCopyFields"},
	{FRInternalSEL, FRInternalAddCRSAUndoItemSEL, L"FRInternalAddCRSAUndoItem"},
	{FRInternalSEL, FRInternalAddStampAPSEL, L"FRInternalAddStampAP"},
	{FRInternalSEL, FRInternalGetDestinationSEL, L"FRInternalGetDestination"},
	{FRInternalSEL, FRInternalDoAction_URISEL, L"FRInternalDoAction_URI"},
	{FRInternalSEL, FRInternalDoAction_LaunchSEL, L"FRInternalDoAction_Launch"},
	{FRInternalSEL, FRInternalDoAction_GoToRSEL, L"FRInternalDoAction_GoToR"},
	{FRInternalSEL, FRInternalDoAction_GoToESEL, L"FRInternalDoAction_GoToE"},
	{FRInternalSEL, FRInternalIsAttachDeniedSEL, L"FRInternalIsAttachDenied"},
	{FRInternalSEL, FRInternalIsAttachDenied2SEL, L"FRInternalIsAttachDenied2"},
	{FRInternalSEL, FRInternalShowAttachFailedDlgSEL, L"FRInternalShowAttachFailedDlg"},
	{FRInternalSEL, FRInternalConvertMediaToPDFSEL, L"FRInternalConvertMediaToPDF"},
	{FRInternalSEL, FRInternalRunProcJavaScriptSEL, L"FRInternalRunProcJavaScript"},
	{FRInternalSEL, FRInternalCheckDocTrustOneTimeSEL, L"FRInternalCheckDocTrustOneTime"},
	{FRInternalSEL, FRInternalAddDocTrustOneTimeSEL, L"FRInternalAddDocTrustOneTime"},
	{FRInternalSEL, FRInternalReBuildTreeViewSEL, L"FRInternalReBuildTreeView"},
	{FRInternalSEL, FRInternalAddAccessibilitySEL, L"FRInternalAddAccessibility"},
	{FRInternalSEL, FRInternalCanDoAddAccessibilitySEL, L"FRInternalCanDoAddAccessibility"},
	{FRInternalSEL, FRInternalCheckIsDownloadStatusSEL, L"FRInternalCheckIsDownloadStatus"},
	{FRInternalSEL, FRInternalSetFormRecognitionProcSEL, L"FRInternalSetFormRecognitionProc"},
	{FRInternalSEL, FRInternalGetContainedCountInPagesSEL, L"FRInternalGetContainedCountInPages"},
	{FRInternalSEL, FRInternalGetPrompPagesSEL, L"FRInternalGetPrompPages"},
	{FRInternalSEL, FRInternalReduceFileSizeSEL, L"FRInternalReduceFileSize"},
	{FRInternalSEL, FRInternalShowReduceSizeDlgSEL, L"FRInternalShowReduceSizeDlg"},
	{FRInternalSEL, FRInternalLoadAuiModuleStringSEL, L"FRInternalLoadAuiModuleString"},
	{FRInternalSEL, FRInternalIsNameExistSEL, L"FRInternalIsNameExist"},
	{FRInternalSEL, FRInternalAddFileAttachmentSEL, L"FRInternalAddFileAttachment"},
	{FRInternalSEL, FRInternalRedactTextSEL, L"FRInternalRedactText"},
	{FRInternalSEL, FRInternalExecScanDocTofileSEL, L"FRInternalExecScanDocTofile"},
	{FRInternalSEL, FRInternalIsFileAttachSubDocSEL, L"FRInternalIsFileAttachSubDoc"},
	{FRInternalSEL, FRInternalIsParentDocAllowModifySEL, L"FRInternalIsParentDocAllowModify"},
	{FRInternalSEL, FRInternalSetActiveToolSEL, L"FRInternalSetActiveTool"},
	{FRInternalSEL, FRInternalDoAction_DocOpenSEL, L"FRInternalDoAction_DocOpen"},
	{FRInternalSEL, FRInternalActionWizardHandlerNeedSaveDocSEL, L"FRInternalActionWizardHandlerNeedSaveDoc"},
	{FRInternalSEL, FRInternalGetPackageLanguageSEL, L"FRInternalGetPackageLanguage"},
	{FRInternalSEL, FRInternalShowSafeModeDialogSEL, L"FRInternalShowSafeModeDialog"},
	{FRInternalSEL, FRInternalReShowSafeModeDialogSEL, L"FRInternalReShowSafeModeDialog"},
	{FRInternalSEL, FRInternalSetDocRenderFinishOneTimeSEL, L"FRInternalSetDocRenderFinishOneTime"},
	{FRInternalSEL, FRInternalSetPageVisibleEventFinishSEL, L"FRInternalSetPageVisibleEventFinish"},
	{FRInternalSEL, FRInternalExecuteOnPortfolioFinishRenderSEL, L"FRInternalExecuteOnPortfolioFinishRender"},
	{FRInternalSEL, FRInternalSetRecipientSeedSEL, L"FRInternalSetRecipientSeed"},
	{FRInternalSEL, FRInternalConstructorInterformSEL, L"FRInternalConstructorInterform"},
	{FRInternalSEL, FRInternalParserOpenPasswordSEL, L"FRInternalParserOpenPassword"},
	{FRInternalSEL, FRInternalCheckOwerPasswordSEL, L"FRInternalCheckOwerPassword"},
	{FRInternalSEL, FRInternalSetTrialDaySEL, L"FRInternalSetTrialDay"},
	{FRInternalSEL, FRInternalSetTotalTrialDaySEL, L"FRInternalSetTotalTrialDay"},
	{FRInternalSEL, FRInternalSetAgainCheckLisenseSEL, L"FRInternalSetAgainCheckLisense"},
	{FRInternalSEL, FRInternalFindAllBMNodeSEL, L"FRInternalFindAllBMNode"},
	{FRInternalSEL, FRInternalFixRulesSEL, L"FRInternalFixRules"},
	{FRInternalSEL, FRInternalSetCallBackProcessSEL, L"FRInternalSetCallBackProcess"},
	{FRInternalSEL, FRInternalCreateAccessbilityFixSEL, L"FRInternalCreateAccessbilityFix"},
	{FRInternalSEL, FRInternalReleaseAccessbilityFixSEL, L"FRInternalReleaseAccessbilityFix"},
	{FRInternalSEL, FRInternalSetActionGotoSEL, L"FRInternalSetActionGoto"},
	{FRInternalSEL, FRInternalSetActionURLSEL, L"FRInternalSetActionURL"},
	{FRInternalSEL, FRInternalSetActionLaunchSEL, L"FRInternalSetActionLaunch"},
	{FRInternalSEL, FRInternalSetActionNamedSEL, L"FRInternalSetActionNamed"},
	{FRInternalSEL, FRInternalSetActionImportDataSEL, L"FRInternalSetActionImportData"},
	{FRInternalSEL, FRInternalSetActionJavaScriptSEL, L"FRInternalSetActionJavaScript"},
	{FRInternalSEL, FRInternalCanUndoSEL, L"FRInternalCanUndo"},
	{FRInternalSEL, FRInternalCanRedoSEL, L"FRInternalCanRedo"},
	{FRInternalSEL, FRInternalGridWindow2DocSEL, L"FRInternalGridWindow2Doc"},
	{FRInternalSEL, FRInternalGridWindow2Doc2SEL, L"FRInternalGridWindow2Doc2"},
	{FRInternalSEL, FRInternalSetSearchingTextFlagSEL, L"FRInternalSetSearchingTextFlag"},
	{FRInternalSEL, FRInternalGetTrialDaysSEL, L"FRInternalGetTrialDays"},
	{FRInternalSEL, FRInternalIsBlankPageSEL, L"FRInternalIsBlankPage"},
	{FRInternalSEL, FRInternalAddAttachFileSEL, L"FRInternalAddAttachFile"},
	{FRInternalSEL, FRInternalGetAttachFileSEL, L"FRInternalGetAttachFile"},
	{FRInternalSEL, FRInternalCheckIsFpeKeySEL, L"FRInternalCheckIsFpeKey"},
	{FRInternalSEL, FRInternalSetAgainCheckTrialSEL, L"FRInternalSetAgainCheckTrial"},
	{FRInternalSEL, FRInternalGetSEL, L"FRInternalGet"},
	{FRInternalSEL, FRInternalTextMarkupCreateAnnotSEL, L"FRInternalTextMarkupCreateAnnot"},
	{FRInternalSEL, FRInternalTextMarkupResetAnnotSEL, L"FRInternalTextMarkupResetAnnot"},
	{FRInternalSEL, FRInternalTextMarkupDeleteAnnotSEL, L"FRInternalTextMarkupDeleteAnnot"},
	{FRInternalSEL, FRInternalTextMarkupCloneAnnotSEL, L"FRInternalTextMarkupCloneAnnot"},
	{FRInternalSEL, FRInternalTextMarkupBeginModifySEL, L"FRInternalTextMarkupBeginModify"},
	{FRInternalSEL, FRInternalTextMarkupEndModifySEL, L"FRInternalTextMarkupEndModify"},
	{FRInternalSEL, FRInternalFAAItemObjectGetDicSEL, L"FRInternalFAAItemObjectGetDic"},
	{FRInternalSEL, FRInternalFAAItemObjectSetDicSEL, L"FRInternalFAAItemObjectSetDic"},
	{FRInternalSEL, FRInternalFAAItemObjectGetPageIndexSEL, L"FRInternalFAAItemObjectGetPageIndex"},
	{FRInternalSEL, FRInternalFAAItemObjectSetPageIndexSEL, L"FRInternalFAAItemObjectSetPageIndex"},
	{FRInternalSEL, FRInternalFAAItemObjectSetbAnnotSEL, L"FRInternalFAAItemObjectSetbAnnot"},
	{FRInternalSEL, FRInternalFAAItemObjectGetbAnnotSEL, L"FRInternalFAAItemObjectGetbAnnot"},
	{FRInternalSEL, FRInternalFAAItemObjectSetUFileNameSEL, L"FRInternalFAAItemObjectSetUFileName"},
	{FRInternalSEL, FRInternalFAAItemObjectGetUFileNameSEL, L"FRInternalFAAItemObjectGetUFileName"},
	{FRInternalSEL, FRInternalFAAItemObjectSetFileNameSEL, L"FRInternalFAAItemObjectSetFileName"},
	{FRInternalSEL, FRInternalFAAItemObjectGetFileNameSEL, L"FRInternalFAAItemObjectGetFileName"},
	{FRInternalSEL, FRInternalGetFileAttachmentObjectsSEL, L"FRInternalGetFileAttachmentObjects"},
	{FRInternalSEL, FRInternalReleaseFileAttachmentObjectsSEL, L"FRInternalReleaseFileAttachmentObjects"},
	{FRInternalSEL, FRInternalOpenFileAttachmentSEL, L"FRInternalOpenFileAttachment"},
	{FRInternalSEL, FRInternalOpenFileAttachment2SEL, L"FRInternalOpenFileAttachment2"},
	{FRInternalSEL, FRInternalIsTextMarkSEL, L"FRInternalIsTextMark"},
	{FRInternalSEL, FRInternalDoSearchAndRedactSEL, L"FRInternalDoSearchAndRedact"},
	{FRInternalSEL, FRInternalApplyRedactSEL, L"FRInternalApplyRedact"},
	{FRInternalSEL, FRInternalIsDisableAdvertiseSEL, L"FRInternalIsDisableAdvertise"},
	{FRInternalSEL, FRInternalGetSelectLoginMethodsSEL, L"FRInternalGetSelectLoginMethods"},
	{FRInternalSEL, FRInternalGetPackageLanguageNameSEL, L"FRInternalGetPackageLanguageName"},
	{FRInternalSEL, FRInternalGetPackageAgentNameSEL, L"FRInternalGetPackageAgentName"},
	{FRInternalSEL, FRInternalGetServiceDomainSEL, L"FRInternalGetServiceDomain"},
	{FRInternalSEL, FRInternalAddToLogSEL, L"FRInternalAddToLog"},
	{FRInternalSEL, FRInternalIsAttachCanOpenSEL, L"FRInternalIsAttachCanOpen"},
	{FRInternalSEL, FRInternalCheckSecuritySEL, L"FRInternalCheckSecurity"},
	{FRInternalSEL, FRInternalShowAndCheckAttachFaileDlgSEL, L"FRInternalShowAndCheckAttachFaileDlg"},
	{FRInternalSEL, FRInternalIsDisableDefaultLaunchAttachmentPermsSEL, L"FRInternalIsDisableDefaultLaunchAttachmentPerms"},
	{FRInternalSEL, FRInternalGetSubExpierDateSEL, L"FRInternalGetSubExpierDate"},
	{FRInternalSEL, FRInternalShowRibbonFilePageSEL, L"FRInternalShowRibbonFilePage"},
	{FRInternalSEL, FRInternalRemoveFileAttachmentObjectSEL, L"FRInternalRemoveFileAttachmentObject"},
	{FRInternalSEL, FRInternalSetReplaceColorsSEL, L"FRInternalSetReplaceColors"},
	{FRInternalSEL, FRInternalBFExportFormSEL, L"FRInternalBFExportForm"},
	{FRInternalSEL, FRInternalFrameRemoveAllGroupSEL, L"FRInternalFrameRemoveAllGroup"},
	{FRInternalSEL, FRInternalFrameNewVertGroupSEL, L"FRInternalFrameNewVertGroup"},
	{FRInternalSEL, FRInternalGetLoginDomainSEL, L"FRInternalGetLoginDomain"},
	{FRInternalSEL, FRInternalExportCommentsSEL, L"FRInternalExportComments"},
	{FRSpellCheckSEL, FRSpellCheckNewSEL, L"FRSpellCheckNew"},
	{FRSpellCheckSEL, FRSpellCheckIgnoreSEL, L"FRSpellCheckIgnore"},
	{FRSpellCheckSEL, FRSpellCheckCheckStringSEL, L"FRSpellCheckCheckString"},
	{FRSpellCheckSEL, FRSpellCheckAddDicSEL, L"FRSpellCheckAddDic"},
// fr_appImpl.h end

// In file fr_barImpl.h
	{FRRibbonBarSEL, FRRibbonBarAddCategorySEL, L"FRRibbonBarAddCategory"},
	{FRRibbonBarSEL, FRRibbonBarAddRibbonContextCategorySEL, L"FRRibbonBarAddRibbonContextCategory"},
	{FRRibbonBarSEL, FRRibbonBarActivateContextCategorySEL, L"FRRibbonBarActivateContextCategory"},
	{FRRibbonBarSEL, FRRibbonBarShowContextCategoriesSEL, L"FRRibbonBarShowContextCategories"},
	{FRRibbonBarSEL, FRRibbonBarGetCategoryCountSEL, L"FRRibbonBarGetCategoryCount"},
	{FRRibbonBarSEL, FRRibbonBarGetCategoryByIndexSEL, L"FRRibbonBarGetCategoryByIndex"},
	{FRRibbonBarSEL, FRRibbonBarGetCategoryByNameSEL, L"FRRibbonBarGetCategoryByName"},
	{FRRibbonBarSEL, FRRibbonBarAddAsQATSEL, L"FRRibbonBarAddAsQAT"},
	{FRRibbonBarSEL, FRRibbonBarAddToTabsSEL, L"FRRibbonBarAddToTabs"},
	{FRRibbonBarSEL, FRRibbonBarAddHiddenSEL, L"FRRibbonBarAddHidden"},
	{FRRibbonBarSEL, FRRibbonBarAddBackStageViewItemSEL, L"FRRibbonBarAddBackStageViewItem"},
	{FRRibbonBarSEL, FRRibbonBarGetBackStageViewItemSEL, L"FRRibbonBarGetBackStageViewItem"},
	{FRRibbonBarSEL, FRRibbonBarSelectBackStageViewItemSEL, L"FRRibbonBarSelectBackStageViewItem"},
	{FRRibbonBarSEL, FRRibbonBarAddButtonToAddPlaceSEL, L"FRRibbonBarAddButtonToAddPlace"},
	{FRRibbonBarSEL, FRRibbonBarCloseFilePageSEL, L"FRRibbonBarCloseFilePage"},
	{FRRibbonBarSEL, FRRibbonBarFindElementByNameSEL, L"FRRibbonBarFindElementByName"},
	{FRRibbonBarSEL, FRRibbonBarIsBackStageViewActiveSEL, L"FRRibbonBarIsBackStageViewActive"},
	{FRRibbonBarSEL, FRRibbonBarRecalcLayoutSEL, L"FRRibbonBarRecalcLayout"},
	{FRRibbonBarSEL, FRRibbonBarGetActiveCategorySEL, L"FRRibbonBarGetActiveCategory"},
	{FRRibbonBarSEL, FRRibbonBarSetActiveCategorySEL, L"FRRibbonBarSetActiveCategory"},
	{FRRibbonBarSEL, FRRibbonBarSetActiveCategory2SEL, L"FRRibbonBarSetActiveCategory2"},
	{FRRibbonBarSEL, FRRibbonBarIsMinimizeSEL, L"FRRibbonBarIsMinimize"},
	{FRRibbonBarSEL, FRRibbonBarAddCaptionButtonSEL, L"FRRibbonBarAddCaptionButton"},
	{FRRibbonBarSEL, FRRibbonBarRegisterFilePageEventHandlerSEL, L"FRRibbonBarRegisterFilePageEventHandler"},
	{FRRibbonBarSEL, FRRibbonBarDestroyFilePageEventHandlerSEL, L"FRRibbonBarDestroyFilePageEventHandler"},
	{FRRibbonBarSEL, FRRibbonBarAddCategory2SEL, L"FRRibbonBarAddCategory2"},
	{FRRibbonBarSEL, FRRibbonBarShowButtonInAddPlaceSEL, L"FRRibbonBarShowButtonInAddPlace"},
	{FRRibbonBarSEL, FRRibbonBarUpdateCmdUISEL, L"FRRibbonBarUpdateCmdUI"},
	{FRRibbonBarSEL, FRRibbonBarAddButtonToAddPlace2SEL, L"FRRibbonBarAddButtonToAddPlace2"},
	{FRRibbonBarSEL, FRRibbonBarAddToTabs2SEL, L"FRRibbonBarAddToTabs2"},
	{FRRibbonBarSEL, FRRibbonBarFindHiddenFloatySEL, L"FRRibbonBarFindHiddenFloaty"},
	{FRRibbonBarSEL, FRRibbonBarAddOnlyForAccelButtonSEL, L"FRRibbonBarAddOnlyForAccelButton"},
	{FRRibbonBarSEL, FRRibbonBarAddHidden2SEL, L"FRRibbonBarAddHidden2"},
	{FRRibbonBarSEL, FRRibbonBarAddToTabRightSEL, L"FRRibbonBarAddToTabRight"},
	{FRRibbonCategorySEL, FRRibbonCategorySetTitleSEL, L"FRRibbonCategorySetTitle"},
	{FRRibbonCategorySEL, FRRibbonCategoryGetTitleSEL, L"FRRibbonCategoryGetTitle"},
	{FRRibbonCategorySEL, FRRibbonCategorySetContextTitleSEL, L"FRRibbonCategorySetContextTitle"},
	{FRRibbonCategorySEL, FRRibbonCategoryGetContextTitleSEL, L"FRRibbonCategoryGetContextTitle"},
	{FRRibbonCategorySEL, FRRibbonCategorySetKeySEL, L"FRRibbonCategorySetKey"},
	{FRRibbonCategorySEL, FRRibbonCategoryGetKeySEL, L"FRRibbonCategoryGetKey"},
	{FRRibbonCategorySEL, FRRibbonCategorySetVisibleSEL, L"FRRibbonCategorySetVisible"},
	{FRRibbonCategorySEL, FRRibbonCategoryGetVisibleSEL, L"FRRibbonCategoryGetVisible"},
	{FRRibbonCategorySEL, FRRibbonCategoryAddPanelSEL, L"FRRibbonCategoryAddPanel"},
	{FRRibbonCategorySEL, FRRibbonCategoryGetPanelCountSEL, L"FRRibbonCategoryGetPanelCount"},
	{FRRibbonCategorySEL, FRRibbonCategoryGetPanelByIndexSEL, L"FRRibbonCategoryGetPanelByIndex"},
	{FRRibbonCategorySEL, FRRibbonCategoryGetPanelByNameSEL, L"FRRibbonCategoryGetPanelByName"},
	{FRRibbonCategorySEL, FRRibbonCategoryGetNameSEL, L"FRRibbonCategoryGetName"},
	{FRRibbonCategorySEL, FRRibbonCategoryShowInQATCustomizeToolsDlgSEL, L"FRRibbonCategoryShowInQATCustomizeToolsDlg"},
	{FRRibbonCategorySEL, FRRibbonCategoryCopyPanelSEL, L"FRRibbonCategoryCopyPanel"},
	{FRRibbonCategorySEL, FRRibbonCategoryRecalcLayoutSEL, L"FRRibbonCategoryRecalcLayout"},
	{FRRibbonCategorySEL, FRRibbonCategoryAddPanel2SEL, L"FRRibbonCategoryAddPanel2"},
	{FRRibbonCategorySEL, FRRibbonCategoryAddDialogSEL, L"FRRibbonCategoryAddDialog"},
	{FRRibbonCategorySEL, FRRibbonCategoryPreTranslateMessageSEL, L"FRRibbonCategoryPreTranslateMessage"},
	{FRRibbonCategorySEL, FRRibbonCategoryAddDialogToRightSEL, L"FRRibbonCategoryAddDialogToRight"},
	{FRRibbonCategorySEL, FRRibbonCategoryGetPosSEL, L"FRRibbonCategoryGetPos"},
	{FRRibbonCategorySEL, FRRibbonCategorySetPosSEL, L"FRRibbonCategorySetPos"},
	{FRRibbonCategorySEL, FRRibbonCategorySetHighlightSEL, L"FRRibbonCategorySetHighlight"},
	{FRRibbonCategorySEL, FRRibbonCategoryGetHighlightColorSEL, L"FRRibbonCategoryGetHighlightColor"},
	{FRRibbonCategorySEL, FRRibbonCategoryGetTabRectSEL, L"FRRibbonCategoryGetTabRect"},
	{FRRibbonPanelSEL, FRRibbonPanelAddElementSEL, L"FRRibbonPanelAddElement"},
	{FRRibbonPanelSEL, FRRibbonPanelChangeElementTypeSEL, L"FRRibbonPanelChangeElementType"},
	{FRRibbonPanelSEL, FRRibbonPanelAddElementToGroupSEL, L"FRRibbonPanelAddElementToGroup"},
	{FRRibbonPanelSEL, FRRibbonPanelSetLaunchButtonSEL, L"FRRibbonPanelSetLaunchButton"},
	{FRRibbonPanelSEL, FRRibbonPanelCopyElementToPanelSEL, L"FRRibbonPanelCopyElementToPanel"},
	{FRRibbonPanelSEL, FRRibbonPanelSetTitleSEL, L"FRRibbonPanelSetTitle"},
	{FRRibbonPanelSEL, FRRibbonPanelGetTitleSEL, L"FRRibbonPanelGetTitle"},
	{FRRibbonPanelSEL, FRRibbonPanelSetVisibleSEL, L"FRRibbonPanelSetVisible"},
	{FRRibbonPanelSEL, FRRibbonPanelGetVisibleSEL, L"FRRibbonPanelGetVisible"},
	{FRRibbonPanelSEL, FRRibbonPanelGetElementByNameSEL, L"FRRibbonPanelGetElementByName"},
	{FRRibbonPanelSEL, FRRibbonPanelGetElementCountSEL, L"FRRibbonPanelGetElementCount"},
	{FRRibbonPanelSEL, FRRibbonPanelGetElementByIndexSEL, L"FRRibbonPanelGetElementByIndex"},
	{FRRibbonPanelSEL, FRRibbonPanelSetPanelImageSEL, L"FRRibbonPanelSetPanelImage"},
	{FRRibbonPanelSEL, FRRibbonPanelGetNameSEL, L"FRRibbonPanelGetName"},
	{FRRibbonPanelSEL, FRRibbonPanelShowInQATCustomizeToolsDlgSEL, L"FRRibbonPanelShowInQATCustomizeToolsDlg"},
	{FRRibbonPanelSEL, FRRibbonPanelSetImageInitProcSEL, L"FRRibbonPanelSetImageInitProc"},
	{FRRibbonPanelSEL, FRRibbonPanelSetKeySEL, L"FRRibbonPanelSetKey"},
	{FRRibbonPanelSEL, FRRibbonPanelAddDialogSEL, L"FRRibbonPanelAddDialog"},
	{FRRibbonPanelSEL, FRRibbonPanelPreTranslateMessageSEL, L"FRRibbonPanelPreTranslateMessage"},
	{FRRibbonPanelSEL, FRRibbonPanelEnableAddToCustomizeDlgSEL, L"FRRibbonPanelEnableAddToCustomizeDlg"},
	{FRRibbonPanelSEL, FRRibbonPanelSetShowDefaultButtonAtLastSEL, L"FRRibbonPanelSetShowDefaultButtonAtLast"},
	{FRRibbonPanelSEL, FRRibbonPanelCopyElementToPanel2SEL, L"FRRibbonPanelCopyElementToPanel2"},
	{FRRibbonPanelSEL, FRRibbonPanelAddControlSEL, L"FRRibbonPanelAddControl"},
	{FRRibbonPanelSEL, FRRibbonPanelGetControlByNameSEL, L"FRRibbonPanelGetControlByName"},
	{FRRibbonPanelSEL, FRRibbonPanelGetControlByIndexSEL, L"FRRibbonPanelGetControlByIndex"},
	{FRRibbonPanelSEL, FRRibbonPanelAddElement2SEL, L"FRRibbonPanelAddElement2"},
	{FRRibbonPanelSEL, FRRibbonPanelAddElementToGroup2SEL, L"FRRibbonPanelAddElementToGroup2"},
	{FRRibbonPanelSEL, FRRibbonPanelSetPDFImageParentNameSEL, L"FRRibbonPanelSetPDFImageParentName"},
	{FRRibbonElementSEL, FRRibbonElementAddSubItemSEL, L"FRRibbonElementAddSubItem"},
	{FRRibbonElementSEL, FRRibbonElementSetExecuteProcSEL, L"FRRibbonElementSetExecuteProc"},
	{FRRibbonElementSEL, FRRibbonElementSetComputeEnabledProcSEL, L"FRRibbonElementSetComputeEnabledProc"},
	{FRRibbonElementSEL, FRRibbonElementSetComputeMarkedProcSEL, L"FRRibbonElementSetComputeMarkedProc"},
	{FRRibbonElementSEL, FRRibbonElementDoExecuteProcSEL, L"FRRibbonElementDoExecuteProc"},
	{FRRibbonElementSEL, FRRibbonElementIsEnabledSEL, L"FRRibbonElementIsEnabled"},
	{FRRibbonElementSEL, FRRibbonElementIsMarkedSEL, L"FRRibbonElementIsMarked"},
	{FRRibbonElementSEL, FRRibbonElementSetClientDataSEL, L"FRRibbonElementSetClientData"},
	{FRRibbonElementSEL, FRRibbonElementGetClientDataSEL, L"FRRibbonElementGetClientData"},
	{FRRibbonElementSEL, FRRibbonElementSetAccelSEL, L"FRRibbonElementSetAccel"},
	{FRRibbonElementSEL, FRRibbonElementGetAccelSEL, L"FRRibbonElementGetAccel"},
	{FRRibbonElementSEL, FRRibbonElementSetKeySEL, L"FRRibbonElementSetKey"},
	{FRRibbonElementSEL, FRRibbonElementGetKeySEL, L"FRRibbonElementGetKey"},
	{FRRibbonElementSEL, FRRibbonElementSetTooltipSEL, L"FRRibbonElementSetTooltip"},
	{FRRibbonElementSEL, FRRibbonElementGetTooltipSEL, L"FRRibbonElementGetTooltip"},
	{FRRibbonElementSEL, FRRibbonElementSetDescriptionSEL, L"FRRibbonElementSetDescription"},
	{FRRibbonElementSEL, FRRibbonElementGetDescriptionSEL, L"FRRibbonElementGetDescription"},
	{FRRibbonElementSEL, FRRibbonElementSetTitleSEL, L"FRRibbonElementSetTitle"},
	{FRRibbonElementSEL, FRRibbonElementGetTitleSEL, L"FRRibbonElementGetTitle"},
	{FRRibbonElementSEL, FRRibbonElementSetImageSEL, L"FRRibbonElementSetImage"},
	{FRRibbonElementSEL, FRRibbonElementAddChangeImageSEL, L"FRRibbonElementAddChangeImage"},
	{FRRibbonElementSEL, FRRibbonElementChangeImageSEL, L"FRRibbonElementChangeImage"},
	{FRRibbonElementSEL, FRRibbonElementSetTooltipImageSEL, L"FRRibbonElementSetTooltipImage"},
	{FRRibbonElementSEL, FRRibbonElementSetTooltipImageIISEL, L"FRRibbonElementSetTooltipImageII"},
	{FRRibbonElementSEL, FRRibbonElementSetVisibleSEL, L"FRRibbonElementSetVisible"},
	{FRRibbonElementSEL, FRRibbonElementGetVisibleSEL, L"FRRibbonElementGetVisible"},
	{FRRibbonElementSEL, FRRibbonElementRemoveSEL, L"FRRibbonElementRemove"},
	{FRRibbonElementSEL, FRRibbonElementGetTypeSEL, L"FRRibbonElementGetType"},
	{FRRibbonElementSEL, FRRibbonElementGetOriginalIDSEL, L"FRRibbonElementGetOriginalID"},
	{FRRibbonElementSEL, FRRibbonElementGetNameSEL, L"FRRibbonElementGetName"},
	{FRRibbonElementSEL, FRRibbonElementGetSubItemCountSEL, L"FRRibbonElementGetSubItemCount"},
	{FRRibbonElementSEL, FRRibbonElementFindSubElementByIndexSEL, L"FRRibbonElementFindSubElementByIndex"},
	{FRRibbonElementSEL, FRRibbonElementGetSubElementByNameSEL, L"FRRibbonElementGetSubElementByName"},
	{FRRibbonElementSEL, FRRibbonElementCopyElementAsSubItemSEL, L"FRRibbonElementCopyElementAsSubItem"},
	{FRRibbonElementSEL, FRRibbonElementGetCorrespondingButtonSEL, L"FRRibbonElementGetCorrespondingButton"},
	{FRRibbonElementSEL, FRRibbonElementSetAsSubElementSEL, L"FRRibbonElementSetAsSubElement"},
	{FRRibbonElementSEL, FRRibbonElementSetImplicitLargeBitmapSEL, L"FRRibbonElementSetImplicitLargeBitmap"},
	{FRRibbonElementSEL, FRRibbonElementSetShowModeSEL, L"FRRibbonElementSetShowMode"},
	{FRRibbonElementSEL, FRRibbonElementSetDropdownProcSEL, L"FRRibbonElementSetDropdownProc"},
	{FRRibbonElementSEL, FRRibbonElementGetClientRectSEL, L"FRRibbonElementGetClientRect"},
	{FRRibbonElementSEL, FRRibbonElementGetWindowRectSEL, L"FRRibbonElementGetWindowRect"},
	{FRRibbonElementSEL, FRRibbonElementShowInQATCustomizeToolsDlgSEL, L"FRRibbonElementShowInQATCustomizeToolsDlg"},
	{FRRibbonElementSEL, FRRibbonElementSetImageInitProcSEL, L"FRRibbonElementSetImageInitProc"},
	{FRRibbonElementSEL, FRRibbonElementGetButtonMapIdSEL, L"FRRibbonElementGetButtonMapId"},
	{FRRibbonElementSEL, FRRibbonElementSetBackstageViewTabElementKeepStateSEL, L"FRRibbonElementSetBackstageViewTabElementKeepState"},
	{FRRibbonElementSEL, FRRibbonElementIsBackstageViewTabElementKeepStateSEL, L"FRRibbonElementIsBackstageViewTabElementKeepState"},
	{FRRibbonElementSEL, FRRibbonElementSetSelectOnlySEL, L"FRRibbonElementSetSelectOnly"},
	{FRRibbonElementSEL, FRRibbonElementGetCategoryNameSEL, L"FRRibbonElementGetCategoryName"},
	{FRRibbonElementSEL, FRRibbonElementGetPanelNameSEL, L"FRRibbonElementGetPanelName"},
	{FRRibbonElementSEL, FRRibbonElementSetHighlightSEL, L"FRRibbonElementSetHighlight"},
	{FRRibbonElementSEL, FRRibbonElementSetPDFImageSEL, L"FRRibbonElementSetPDFImage"},
	{FRRibbonElementSEL, FRRibbonElementAddChangePDFImageSEL, L"FRRibbonElementAddChangePDFImage"},
	{FRRibbonElementSEL, FRRibbonElementChangePDFImageSEL, L"FRRibbonElementChangePDFImage"},
	{FRRibbonElementSEL, FRRibbonElementSetDropDownAddElementProcSEL, L"FRRibbonElementSetDropDownAddElementProc"},
	{FRRibbonElementSEL, FRRibbonElementAddSubItem2SEL, L"FRRibbonElementAddSubItem2"},
	{FRRibbonElementSEL, FRRibbonElementGetFullTitleSEL, L"FRRibbonElementGetFullTitle"},
	{FRRibbonElementSEL, FRRibbonElementSetTooltipHasHelpSEL, L"FRRibbonElementSetTooltipHasHelp"},
	{FRRibbonElementSEL, FRRibbonElementSetEditChangeProcSEL, L"FRRibbonElementSetEditChangeProc"},
	{FRRibbonElementSEL, FRRibbonElementAddHighlightImageSEL, L"FRRibbonElementAddHighlightImage"},
	{FRRibbonElementSEL, FRRibbonElementSetImageReplaceColorSEL, L"FRRibbonElementSetImageReplaceColor"},
	{FRRibbonElementSEL, FRRibbonElementSetPDFImageParentNameSEL, L"FRRibbonElementSetPDFImageParentName"},
	{FRRibbonElementSEL, FRRibbonElementFindElementByNameFloatySEL, L"FRRibbonElementFindElementByNameFloaty"},
	{FRRibbonElementSEL, FRRibbonElementSetClosePopupMenuProcSEL, L"FRRibbonElementSetClosePopupMenuProc"},
	{FRRibbonElementSEL, FRRibbonElementAddButtonToRightSEL, L"FRRibbonElementAddButtonToRight"},
	{FRRibbonElementSEL, FRRibbonElementSetRightButtonPDFBitmapSEL, L"FRRibbonElementSetRightButtonPDFBitmap"},
	{FRRibbonElementSEL, FRRibbonElementSetRighButtonAutoHideSEL, L"FRRibbonElementSetRighButtonAutoHide"},
	{FRRibbonElementSEL, FRRibbonElementDisableHighContrastThemeImageSEL, L"FRRibbonElementDisableHighContrastThemeImage"},
	{FRRibbonButtonSEL, FRRibbonButtonGetElementSEL, L"FRRibbonButtonGetElement"},
	{FRRibbonButtonSEL, FRRibbonButtonSetDefaultCommandSEL, L"FRRibbonButtonSetDefaultCommand"},
	{FRRibbonButtonSEL, FRRibbonButtonSetAlwaysShowDescriptionSEL, L"FRRibbonButtonSetAlwaysShowDescription"},
	{FRRibbonButtonSEL, FRRibbonButtonSetButtonPopupWndSEL, L"FRRibbonButtonSetButtonPopupWnd"},
	{FRRibbonButtonSEL, FRRibbonButtonCloseButtonPopupWndSEL, L"FRRibbonButtonCloseButtonPopupWnd"},
	{FRRibbonButtonSEL, FRRibbonButtonSetMenuSEL, L"FRRibbonButtonSetMenu"},
	{FRRibbonButtonSEL, FRRibbonButtonSetButtonArrowSEL, L"FRRibbonButtonSetButtonArrow"},
	{FRRibbonEditSEL, FRRibbonEditGetElementSEL, L"FRRibbonEditGetElement"},
	{FRRibbonEditSEL, FRRibbonEditGetTextSEL, L"FRRibbonEditGetText"},
	{FRRibbonEditSEL, FRRibbonEditSetTextSEL, L"FRRibbonEditSetText"},
	{FRRibbonEditSEL, FRRibbonEditEnableSpinButtonsSEL, L"FRRibbonEditEnableSpinButtons"},
	{FRRibbonEditSEL, FRRibbonEditSetSearchModeSEL, L"FRRibbonEditSetSearchMode"},
	{FRRibbonEditSEL, FRRibbonEditSetWidthSEL, L"FRRibbonEditSetWidth"},
	{FRRibbonEditSEL, FRRibbonEditGetHWndSEL, L"FRRibbonEditGetHWnd"},
	{FRRibbonEditSEL, FRRibbonEditSetTextFlagSEL, L"FRRibbonEditSetTextFlag"},
	{FRRibbonEditSEL, FRRibbonEditSetFocusSEL, L"FRRibbonEditSetFocus"},
	{FRRibbonEditSEL, FRRibbonEditAddButtonToRightSEL, L"FRRibbonEditAddButtonToRight"},
	{FRRibbonLabelSEL, FRRibbonLabelGetElementSEL, L"FRRibbonLabelGetElement"},
	{FRRibbonCheckBoxSEL, FRRibbonCheckBoxGetElementSEL, L"FRRibbonCheckBoxGetElement"},
	{FRRibbonCheckBoxSEL, FRRibbonCheckBoxIsCheckedSEL, L"FRRibbonCheckBoxIsChecked"},
	{FRRibbonCheckBoxSEL, FRRibbonCheckBoxSetCheckSEL, L"FRRibbonCheckBoxSetCheck"},
	{FRRibbonRadioButtonSEL, FRRibbonRadioButtonGetElementSEL, L"FRRibbonRadioButtonGetElement"},
	{FRRibbonRadioButtonSEL, FRRibbonRadioButtonIsCheckedSEL, L"FRRibbonRadioButtonIsChecked"},
	{FRRibbonRadioButtonSEL, FRRibbonRadioButtonSetCheckSEL, L"FRRibbonRadioButtonSetCheck"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxGetElementSEL, L"FRRibbonComboBoxGetElement"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxAddItemSEL, L"FRRibbonComboBoxAddItem"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxInsertItemSEL, L"FRRibbonComboBoxInsertItem"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxGetItemCountSEL, L"FRRibbonComboBoxGetItemCount"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxGetItemSEL, L"FRRibbonComboBoxGetItem"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxGetCurSelSEL, L"FRRibbonComboBoxGetCurSel"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxRemoveAllItemsSEL, L"FRRibbonComboBoxRemoveAllItems"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxSelectItemSEL, L"FRRibbonComboBoxSelectItem"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxDeleteItemSEL, L"FRRibbonComboBoxDeleteItem"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxFindItemSEL, L"FRRibbonComboBoxFindItem"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxSetWidthSEL, L"FRRibbonComboBoxSetWidth"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxSetEditBoxSEL, L"FRRibbonComboBoxSetEditBox"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxGetEditTextSEL, L"FRRibbonComboBoxGetEditText"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxSetEditTextSEL, L"FRRibbonComboBoxSetEditText"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxEnableDropDownListResizeSEL, L"FRRibbonComboBoxEnableDropDownListResize"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxGetHWndSEL, L"FRRibbonComboBoxGetHWnd"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxSetTextFlagSEL, L"FRRibbonComboBoxSetTextFlag"},
	{FRRibbonComboBoxSEL, FRRibbonComboBoxSetFocusSEL, L"FRRibbonComboBoxSetFocus"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxGetElementSEL, L"FRRibbonFontComboBoxGetElement"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxGetItemSEL, L"FRRibbonFontComboBoxGetItem"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxGetCurSelSEL, L"FRRibbonFontComboBoxGetCurSel"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxSelectItemSEL, L"FRRibbonFontComboBoxSelectItem"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxSetWidthSEL, L"FRRibbonFontComboBoxSetWidth"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxSetEditBoxSEL, L"FRRibbonFontComboBoxSetEditBox"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxGetEditTextSEL, L"FRRibbonFontComboBoxGetEditText"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxSetEditTextSEL, L"FRRibbonFontComboBoxSetEditText"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxEnableDropDownListResizeSEL, L"FRRibbonFontComboBoxEnableDropDownListResize"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxGetHWndSEL, L"FRRibbonFontComboBoxGetHWnd"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxAddFontSEL, L"FRRibbonFontComboBoxAddFont"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxInsertFontSEL, L"FRRibbonFontComboBoxInsertFont"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxGetFontIndexSEL, L"FRRibbonFontComboBoxGetFontIndex"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxGetFontNameSEL, L"FRRibbonFontComboBoxGetFontName"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxGetScriptNameSEL, L"FRRibbonFontComboBoxGetScriptName"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxSelectItem2SEL, L"FRRibbonFontComboBoxSelectItem2"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxRemoveFontSEL, L"FRRibbonFontComboBoxRemoveFont"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxRemoveFont2SEL, L"FRRibbonFontComboBoxRemoveFont2"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxGetFontCountSEL, L"FRRibbonFontComboBoxGetFontCount"},
	{FRRibbonFontComboBoxSEL, FRRibbonFontComboBoxSetFocusSEL, L"FRRibbonFontComboBoxSetFocus"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonGetElementSEL, L"FRRibbonPaletteButtonGetElement"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonAddGroupSEL, L"FRRibbonPaletteButtonAddGroup"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetGroupTitleSEL, L"FRRibbonPaletteButtonSetGroupTitle"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetItemToolTipSEL, L"FRRibbonPaletteButtonSetItemToolTip"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetScrollButtonTooltipSEL, L"FRRibbonPaletteButtonSetScrollButtonTooltip"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetMenuButtonTooltipSEL, L"FRRibbonPaletteButtonSetMenuButtonTooltip"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonGetGroupTitleSEL, L"FRRibbonPaletteButtonGetGroupTitle"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonGetItemToolTipSEL, L"FRRibbonPaletteButtonGetItemToolTip"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonGetScrollButtonTooltipSEL, L"FRRibbonPaletteButtonGetScrollButtonTooltip"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonGetMenuButtonTooltipSEL, L"FRRibbonPaletteButtonGetMenuButtonTooltip"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonGetGroupItemCountSEL, L"FRRibbonPaletteButtonGetGroupItemCount"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonGetGroupCountSEL, L"FRRibbonPaletteButtonGetGroupCount"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonIsGroupNameExistSEL, L"FRRibbonPaletteButtonIsGroupNameExist"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetButtonModeSEL, L"FRRibbonPaletteButtonSetButtonMode"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetIconsInRowSEL, L"FRRibbonPaletteButtonSetIconsInRow"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonEnableResizeSEL, L"FRRibbonPaletteButtonEnableResize"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonGetSelectedItemSEL, L"FRRibbonPaletteButtonGetSelectedItem"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonInsertItemToGroupLastSEL, L"FRRibbonPaletteButtonInsertItemToGroupLast"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetDefaultGroupSEL, L"FRRibbonPaletteButtonSetDefaultGroup"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonRemoveGroupSEL, L"FRRibbonPaletteButtonRemoveGroup"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonRemoveItemFromGroupSEL, L"FRRibbonPaletteButtonRemoveItemFromGroup"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetItemDataSEL, L"FRRibbonPaletteButtonSetItemData"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonGetItemDataSEL, L"FRRibbonPaletteButtonGetItemData"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetGroupItemEnableSEL, L"FRRibbonPaletteButtonSetGroupItemEnable"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetSelectedItemSEL, L"FRRibbonPaletteButtonSetSelectedItem"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetRowsSEL, L"FRRibbonPaletteButtonSetRows"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonRemoveAllGroupSEL, L"FRRibbonPaletteButtonRemoveAllGroup"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetInitSizeSEL, L"FRRibbonPaletteButtonSetInitSize"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonGetItemInfoSEL, L"FRRibbonPaletteButtonGetItemInfo"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetHighlightItemProcSEL, L"FRRibbonPaletteButtonSetHighlightItemProc"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetItemAccNameTitleSEL, L"FRRibbonPaletteButtonSetItemAccNameTitle"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonAddGroupPtrSEL, L"FRRibbonPaletteButtonAddGroupPtr"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonAddPDFBitmapToGroupSEL, L"FRRibbonPaletteButtonAddPDFBitmapToGroup"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetMarginSEL, L"FRRibbonPaletteButtonSetMargin"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetDrawItemBorderSEL, L"FRRibbonPaletteButtonSetDrawItemBorder"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetItemTitleSEL, L"FRRibbonPaletteButtonSetItemTitle"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonEnableShowTitleSEL, L"FRRibbonPaletteButtonEnableShowTitle"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonGetLineSEL, L"FRRibbonPaletteButtonGetLine"},
	{FRRibbonPaletteButtonSEL, FRRibbonPaletteButtonSetLineSEL, L"FRRibbonPaletteButtonSetLine"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonGetElementSEL, L"FRRibbonColorButtonGetElement"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonEnableAutomaticButtonSEL, L"FRRibbonColorButtonEnableAutomaticButton"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonSetAutomaticButtonLabelSEL, L"FRRibbonColorButtonSetAutomaticButtonLabel"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonSetAutomaticButtonToolTipSEL, L"FRRibbonColorButtonSetAutomaticButtonToolTip"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonEnableOtherButtonSEL, L"FRRibbonColorButtonEnableOtherButton"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonSetOtherButtonLabelSEL, L"FRRibbonColorButtonSetOtherButtonLabel"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonSetOtherButtonToolTipSEL, L"FRRibbonColorButtonSetOtherButtonToolTip"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonGetAutomaticButtonLabelSEL, L"FRRibbonColorButtonGetAutomaticButtonLabel"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonGetAutomaticButtonToolTipSEL, L"FRRibbonColorButtonGetAutomaticButtonToolTip"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonGetOtherButtonLabelSEL, L"FRRibbonColorButtonGetOtherButtonLabel"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonGetOtherButtonToolTipSEL, L"FRRibbonColorButtonGetOtherButtonToolTip"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonAddColorsGroupSEL, L"FRRibbonColorButtonAddColorsGroup"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonAddStandardColorSEL, L"FRRibbonColorButtonAddStandardColor"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonAddAdditionalColorSEL, L"FRRibbonColorButtonAddAdditionalColor"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonAddMainColorSEL, L"FRRibbonColorButtonAddMainColor"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonSetGroupLabelSEL, L"FRRibbonColorButtonSetGroupLabel"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonGetGroupLabelSEL, L"FRRibbonColorButtonGetGroupLabel"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonSetColorSEL, L"FRRibbonColorButtonSetColor"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonGetColorSEL, L"FRRibbonColorButtonGetColor"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonSetColumnsSEL, L"FRRibbonColorButtonSetColumns"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonSetColorBoxSizeSEL, L"FRRibbonColorButtonSetColorBoxSize"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonSetDefaultCommandSEL, L"FRRibbonColorButtonSetDefaultCommand"},
	{FRRibbonColorButtonSEL, FRRibbonColorButtonIsAutomaticButtonClickSEL, L"FRRibbonColorButtonIsAutomaticButtonClick"},
	{FRRibbonSliderSEL, FRRibbonSliderGetElementSEL, L"FRRibbonSliderGetElement"},
	{FRRibbonSliderSEL, FRRibbonSliderSetZoomButtonsSEL, L"FRRibbonSliderSetZoomButtons"},
	{FRRibbonSliderSEL, FRRibbonSliderSetRangeSEL, L"FRRibbonSliderSetRange"},
	{FRRibbonSliderSEL, FRRibbonSliderGetRangeMinSEL, L"FRRibbonSliderGetRangeMin"},
	{FRRibbonSliderSEL, FRRibbonSliderGetRangeMaxSEL, L"FRRibbonSliderGetRangeMax"},
	{FRRibbonSliderSEL, FRRibbonSliderSetPosSEL, L"FRRibbonSliderSetPos"},
	{FRRibbonSliderSEL, FRRibbonSliderGetPosSEL, L"FRRibbonSliderGetPos"},
	{FRRibbonSliderSEL, FRRibbonSliderSetWidthSEL, L"FRRibbonSliderSetWidth"},
	{FRRibbonSliderSEL, FRRibbonSliderSetStyleSEL, L"FRRibbonSliderSetStyle"},
	{FRRibbonSliderSEL, FRRibbonSliderGetMouseStatusSEL, L"FRRibbonSliderGetMouseStatus"},
	{FRRibbonListButtonSEL, FRRibbonListButtonGetElementSEL, L"FRRibbonListButtonGetElement"},
	{FRRibbonListButtonSEL, FRRibbonListButtonAddGroupSEL, L"FRRibbonListButtonAddGroup"},
	{FRRibbonListButtonSEL, FRRibbonListButtonGetGroupCountSEL, L"FRRibbonListButtonGetGroupCount"},
	{FRRibbonListButtonSEL, FRRibbonListButtonIsGroupNameExistSEL, L"FRRibbonListButtonIsGroupNameExist"},
	{FRRibbonListButtonSEL, FRRibbonListButtonEnableResizeSEL, L"FRRibbonListButtonEnableResize"},
	{FRRibbonListButtonSEL, FRRibbonListButtonSetGroupTitleSEL, L"FRRibbonListButtonSetGroupTitle"},
	{FRRibbonListButtonSEL, FRRibbonListButtonSetItemToolTipSEL, L"FRRibbonListButtonSetItemToolTip"},
	{FRRibbonListButtonSEL, FRRibbonListButtonSetItemTitleSEL, L"FRRibbonListButtonSetItemTitle"},
	{FRRibbonListButtonSEL, FRRibbonListButtonGetGroupTitleSEL, L"FRRibbonListButtonGetGroupTitle"},
	{FRRibbonListButtonSEL, FRRibbonListButtonGetItemToolTipSEL, L"FRRibbonListButtonGetItemToolTip"},
	{FRRibbonListButtonSEL, FRRibbonListButtonGetItemTitleSEL, L"FRRibbonListButtonGetItemTitle"},
	{FRRibbonListButtonSEL, FRRibbonListButtonGetItemCountSEL, L"FRRibbonListButtonGetItemCount"},
	{FRRibbonListButtonSEL, FRRibbonListButtonGetSelectedItemSEL, L"FRRibbonListButtonGetSelectedItem"},
	{FRRibbonListButtonSEL, FRRibbonListButtonSetAlignedSideSEL, L"FRRibbonListButtonSetAlignedSide"},
	{FRRibbonListButtonSEL, FRRibbonListButtonSetIconsInRowSEL, L"FRRibbonListButtonSetIconsInRow"},
	{FRRibbonListButtonSEL, FRRibbonListButtonSetSelectedItemSEL, L"FRRibbonListButtonSetSelectedItem"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemSetTitleSEL, L"FRRibbonBackStageViewItemSetTitle"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemAddDialogSEL, L"FRRibbonBackStageViewItemAddDialog"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemAddPropertySheetPageSEL, L"FRRibbonBackStageViewItemAddPropertySheetPage"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemRemovePropertySheetPageSEL, L"FRRibbonBackStageViewItemRemovePropertySheetPage"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemAddPropertySheetGroupSEL, L"FRRibbonBackStageViewItemAddPropertySheetGroup"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemSetGroupTitleSEL, L"FRRibbonBackStageViewItemSetGroupTitle"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemSetVisibleSEL, L"FRRibbonBackStageViewItemSetVisible"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemSetDisableSEL, L"FRRibbonBackStageViewItemSetDisable"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemAddAnchorSEL, L"FRRibbonBackStageViewItemAddAnchor"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemModifiedToRibbonStyleButtonSEL, L"FRRibbonBackStageViewItemModifiedToRibbonStyleButton"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemSetPropertyActivePageSEL, L"FRRibbonBackStageViewItemSetPropertyActivePage"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemSetPageTitleSEL, L"FRRibbonBackStageViewItemSetPageTitle"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemIsPropertySheetPageExistSEL, L"FRRibbonBackStageViewItemIsPropertySheetPageExist"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemIsDialogExistSEL, L"FRRibbonBackStageViewItemIsDialogExist"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemGetElementSEL, L"FRRibbonBackStageViewItemGetElement"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemEnablePropertyPageRemoveSEL, L"FRRibbonBackStageViewItemEnablePropertyPageRemove"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemRedrawPropertySheetSEL, L"FRRibbonBackStageViewItemRedrawPropertySheet"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemSetDlgItemMaxSizeSEL, L"FRRibbonBackStageViewItemSetDlgItemMaxSize"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemSetPageSelectProcSEL, L"FRRibbonBackStageViewItemSetPageSelectProc"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemBCGPreTranslateMessageSEL, L"FRRibbonBackStageViewItemBCGPreTranslateMessage"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemAddPropertySheetPage2SEL, L"FRRibbonBackStageViewItemAddPropertySheetPage2"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemEnableChangeHighLightImageColorSEL, L"FRRibbonBackStageViewItemEnableChangeHighLightImageColor"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemAddPropertySheetPage3SEL, L"FRRibbonBackStageViewItemAddPropertySheetPage3"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemAddPropertySheetPage4SEL, L"FRRibbonBackStageViewItemAddPropertySheetPage4"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemAddDialog2SEL, L"FRRibbonBackStageViewItemAddDialog2"},
	{FRRibbonBackStageViewItemSEL, FRRibbonBackStageViewItemSetPropertyPageShowSEL, L"FRRibbonBackStageViewItemSetPropertyPageShow"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetImageSEL, L"FRRibbonStyleButtonSetImage"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetAlignStyleSEL, L"FRRibbonStyleButtonSetAlignStyle"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetImageSideSEL, L"FRRibbonStyleButtonSetImageSide"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetFlatStyleSEL, L"FRRibbonStyleButtonSetFlatStyle"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetVertMarginSEL, L"FRRibbonStyleButtonSetVertMargin"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonGetMFCButtonSEL, L"FRRibbonStyleButtonGetMFCButton"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonReleaseSEL, L"FRRibbonStyleButtonRelease"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetImage2SEL, L"FRRibbonStyleButtonSetImage2"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetImage3SEL, L"FRRibbonStyleButtonSetImage3"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetTooltipSEL, L"FRRibbonStyleButtonSetTooltip"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetMarkStatusSEL, L"FRRibbonStyleButtonSetMarkStatus"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetDescriptionSEL, L"FRRibbonStyleButtonSetDescription"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonEnableHelpLinkSEL, L"FRRibbonStyleButtonEnableHelpLink"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetFontStyleSEL, L"FRRibbonStyleButtonSetFontStyle"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetBorderColorSEL, L"FRRibbonStyleButtonSetBorderColor"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetBackgroundColorSEL, L"FRRibbonStyleButtonSetBackgroundColor"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetTextColorSEL, L"FRRibbonStyleButtonSetTextColor"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetRoundRadiusSEL, L"FRRibbonStyleButtonSetRoundRadius"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetTransparentSEL, L"FRRibbonStyleButtonSetTransparent"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetFocusColorSEL, L"FRRibbonStyleButtonSetFocusColor"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetImageReplaceColorSEL, L"FRRibbonStyleButtonSetImageReplaceColor"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonSetDefaultStyleSEL, L"FRRibbonStyleButtonSetDefaultStyle"},
	{FRRibbonStyleButtonSEL, FRRibbonStyleButtonDisableHighContrastThemeImageSEL, L"FRRibbonStyleButtonDisableHighContrastThemeImage"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxAddImageSEL, L"FRRibbonStyleListBoxAddImage"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxAddStringSEL, L"FRRibbonStyleListBoxAddString"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxAddCaptionSEL, L"FRRibbonStyleListBoxAddCaption"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxDeleteStringSEL, L"FRRibbonStyleListBoxDeleteString"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxInsertStringSEL, L"FRRibbonStyleListBoxInsertString"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxGetItemDataSEL, L"FRRibbonStyleListBoxGetItemData"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxSetItemDataSEL, L"FRRibbonStyleListBoxSetItemData"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxGetMFCListBoxSEL, L"FRRibbonStyleListBoxGetMFCListBox"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxReleaseSEL, L"FRRibbonStyleListBoxRelease"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxAddImage2SEL, L"FRRibbonStyleListBoxAddImage2"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxEnablePinsSEL, L"FRRibbonStyleListBoxEnablePins"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxHasPinsSEL, L"FRRibbonStyleListBoxHasPins"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxSetItemPinnedSEL, L"FRRibbonStyleListBoxSetItemPinned"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxGetItemPinnedStateSEL, L"FRRibbonStyleListBoxGetItemPinnedState"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxIsSeparatorItemSEL, L"FRRibbonStyleListBoxIsSeparatorItem"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxRedrawListSEL, L"FRRibbonStyleListBoxRedrawList"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxSetClickItemProcSEL, L"FRRibbonStyleListBoxSetClickItemProc"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxSetClickPinProcSEL, L"FRRibbonStyleListBoxSetClickPinProc"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxSetClientDataSEL, L"FRRibbonStyleListBoxSetClientData"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxClearSEL, L"FRRibbonStyleListBoxClear"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxAddImage3SEL, L"FRRibbonStyleListBoxAddImage3"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxEnableSEL, L"FRRibbonStyleListBoxEnable"},
	{FRRibbonStyleListBoxSEL, FRRibbonStyleListBoxDisableHighContrastThemeImageSEL, L"FRRibbonStyleListBoxDisableHighContrastThemeImage"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticSetImageSEL, L"FRRibbonStyleStaticSetImage"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticGetMFCStaticSEL, L"FRRibbonStyleStaticGetMFCStatic"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticSetFontStyleSEL, L"FRRibbonStyleStaticSetFontStyle"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticSetTextColorSEL, L"FRRibbonStyleStaticSetTextColor"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticSetBackgroundColorSEL, L"FRRibbonStyleStaticSetBackgroundColor"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticSetTextDrawFormatSEL, L"FRRibbonStyleStaticSetTextDrawFormat"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticReleaseSEL, L"FRRibbonStyleStaticRelease"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticSetImage2SEL, L"FRRibbonStyleStaticSetImage2"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticSetImage3SEL, L"FRRibbonStyleStaticSetImage3"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticSetDescriptionSEL, L"FRRibbonStyleStaticSetDescription"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticEnableHelpLinkSEL, L"FRRibbonStyleStaticEnableHelpLink"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticSetTooltipSEL, L"FRRibbonStyleStaticSetTooltip"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticSetTextColorNameSEL, L"FRRibbonStyleStaticSetTextColorName"},
	{FRRibbonStyleStaticSEL, FRRibbonStyleStaticDisableHighContrastThemeImageSEL, L"FRRibbonStyleStaticDisableHighContrastThemeImage"},
	{FRFormatToolsSEL, FRFormatToolsGetSEL, L"FRFormatToolsGet"},
	{FRFormatToolsSEL, FRFormatToolsSetEventSEL, L"FRFormatToolsSetEvent"},
	{FRFormatToolsSEL, FRFormatToolsSetFontNameSEL, L"FRFormatToolsSetFontName"},
	{FRFormatToolsSEL, FRFormatToolsSetFontNameFirstSEL, L"FRFormatToolsSetFontNameFirst"},
	{FRFormatToolsSEL, FRFormatToolsSetFontSizeSEL, L"FRFormatToolsSetFontSize"},
	{FRFormatToolsSEL, FRFormatToolsSetFontSizeFirstSEL, L"FRFormatToolsSetFontSizeFirst"},
	{FRFormatToolsSEL, FRFormatToolsSetTextColorSEL, L"FRFormatToolsSetTextColor"},
	{FRFormatToolsSEL, FRFormatToolsSetLineColorSEL, L"FRFormatToolsSetLineColor"},
	{FRFormatToolsSEL, FRFormatToolsSetFillColorSEL, L"FRFormatToolsSetFillColor"},
	{FRFormatToolsSEL, FRFormatToolsSetBoldSEL, L"FRFormatToolsSetBold"},
	{FRFormatToolsSEL, FRFormatToolsSetItalicSEL, L"FRFormatToolsSetItalic"},
	{FRFormatToolsSEL, FRFormatToolsSetAlignSEL, L"FRFormatToolsSetAlign"},
	{FRFormatToolsSEL, FRFormatToolsSetCharSpaceSEL, L"FRFormatToolsSetCharSpace"},
	{FRFormatToolsSEL, FRFormatToolsSetCharHorzScaleSEL, L"FRFormatToolsSetCharHorzScale"},
	{FRFormatToolsSEL, FRFormatToolsSetLineLeadingSEL, L"FRFormatToolsSetLineLeading"},
	{FRFormatToolsSEL, FRFormatToolsSetSuperScriptSEL, L"FRFormatToolsSetSuperScript"},
	{FRFormatToolsSEL, FRFormatToolsSetSubScriptSEL, L"FRFormatToolsSetSubScript"},
	{FRFormatToolsSEL, FRFormatToolsSetUnderlineSEL, L"FRFormatToolsSetUnderline"},
	{FRFormatToolsSEL, FRFormatToolsSetCrossSEL, L"FRFormatToolsSetCross"},
	{FRFormatToolsSEL, FRFormatToolsSetWordSpaceSEL, L"FRFormatToolsSetWordSpace"},
	{FRFormatToolsSEL, FRFormatToolsGetFontNameSEL, L"FRFormatToolsGetFontName"},
	{FRFormatToolsSEL, FRFormatToolsGetFontSizeSEL, L"FRFormatToolsGetFontSize"},
	{FRFormatToolsSEL, FRFormatToolsGetTextColorSEL, L"FRFormatToolsGetTextColor"},
	{FRFormatToolsSEL, FRFormatToolsGetLineColorSEL, L"FRFormatToolsGetLineColor"},
	{FRFormatToolsSEL, FRFormatToolsGetFillColorSEL, L"FRFormatToolsGetFillColor"},
	{FRFormatToolsSEL, FRFormatToolsGetAlignSEL, L"FRFormatToolsGetAlign"},
	{FRFormatToolsSEL, FRFormatToolsGetCharSpaceSEL, L"FRFormatToolsGetCharSpace"},
	{FRFormatToolsSEL, FRFormatToolsGetCharHorzScaleSEL, L"FRFormatToolsGetCharHorzScale"},
	{FRFormatToolsSEL, FRFormatToolsGetLineLeadingSEL, L"FRFormatToolsGetLineLeading"},
	{FRFormatToolsSEL, FRFormatToolsGetUnderlineSEL, L"FRFormatToolsGetUnderline"},
	{FRFormatToolsSEL, FRFormatToolsGetCrossSEL, L"FRFormatToolsGetCross"},
	{FRFormatToolsSEL, FRFormatToolsGetSuperScriptSEL, L"FRFormatToolsGetSuperScript"},
	{FRFormatToolsSEL, FRFormatToolsGetSubScriptSEL, L"FRFormatToolsGetSubScript"},
	{FRFormatToolsSEL, FRFormatToolsIsBoldSEL, L"FRFormatToolsIsBold"},
	{FRFormatToolsSEL, FRFormatToolsIsItalicSEL, L"FRFormatToolsIsItalic"},
	{FRFormatToolsSEL, FRFormatToolsGetWordSpaceSEL, L"FRFormatToolsGetWordSpace"},
	{FRFormatToolsSEL, FRFormatToolsIsVisibledSEL, L"FRFormatToolsIsVisibled"},
	{FRFormatToolsSEL, FRFormatToolsShowSEL, L"FRFormatToolsShow"},
	{FRFormatToolsSEL, FRFormatToolsIsEnabledSEL, L"FRFormatToolsIsEnabled"},
	{FRFormatToolsSEL, FRFormatToolsEnableSEL, L"FRFormatToolsEnable"},
	{FRFormatToolsSEL, FRFormatToolsIsButtonVisibledSEL, L"FRFormatToolsIsButtonVisibled"},
	{FRFormatToolsSEL, FRFormatToolsHideButtonSEL, L"FRFormatToolsHideButton"},
	{FRFormatToolsSEL, FRFormatToolsIsButtonEnabledSEL, L"FRFormatToolsIsButtonEnabled"},
	{FRFormatToolsSEL, FRFormatToolsEnableButtonSEL, L"FRFormatToolsEnableButton"},
	{FRFormatToolsSEL, FRFormatToolsSetOwnerFontNameArrSEL, L"FRFormatToolsSetOwnerFontNameArr"},
	{FRFormatToolsSEL, FRFormatToolsCleanOwnerFontNameArrSEL, L"FRFormatToolsCleanOwnerFontNameArr"},
	{FRFormatToolsSEL, FRFormatToolsFindFontNameSEL, L"FRFormatToolsFindFontName"},
	{FRFormatToolsSEL, FRFormatToolsCountFontListSEL, L"FRFormatToolsCountFontList"},
	{FRFormatToolsSEL, FRFormatToolsGetFontListItemSEL, L"FRFormatToolsGetFontListItem"},
	{FRFormatToolsSEL, FRFormatToolsSetFormatContextTitleSEL, L"FRFormatToolsSetFormatContextTitle"},
	{FRFormatToolsSEL, FRFormatToolsActivateFormatCategorySEL, L"FRFormatToolsActivateFormatCategory"},
	{FRFormatToolsSEL, FRFormatToolsSetWritingDirectionSEL, L"FRFormatToolsSetWritingDirection"},
	{FRFormatToolsSEL, FRFormatToolsGetWritingDirectionSEL, L"FRFormatToolsGetWritingDirection"},
	{FRFormatToolsSEL, FRFormatToolsGetFontFaceNameSEL, L"FRFormatToolsGetFontFaceName"},
	{FRFormatToolsSEL, FRFormatToolsReleaseEventSEL, L"FRFormatToolsReleaseEvent"},
	{FRFormatToolsSEL, FRFormatToolsSetParagraphSpacingSEL, L"FRFormatToolsSetParagraphSpacing"},
	{FRFormatToolsSEL, FRFormatToolsSetNumberedListStyleSEL, L"FRFormatToolsSetNumberedListStyle"},
	{FRFormatToolsSEL, FRFormatToolsSetBulletedListStyleSEL, L"FRFormatToolsSetBulletedListStyle"},
	{FRFormatToolsSEL, FRFormatToolsSetFormatCaptureSEL, L"FRFormatToolsSetFormatCapture"},
	{FRFormatToolsSEL, FRFormatToolsReleaseFormatCaptureSEL, L"FRFormatToolsReleaseFormatCapture"},
	{FRFormatToolsSEL, FRFormatToolsEnableButton2SEL, L"FRFormatToolsEnableButton2"},
	{FRPropertyToolsSEL, FRPropertyToolsGetSEL, L"FRPropertyToolsGet"},
	{FRPropertyToolsSEL, FRPropertyToolsSetEventSEL, L"FRPropertyToolsSetEvent"},
	{FRPropertyToolsSEL, FRPropertyToolsSetColorSEL, L"FRPropertyToolsSetColor"},
	{FRPropertyToolsSEL, FRPropertyToolsSetOpacitySEL, L"FRPropertyToolsSetOpacity"},
	{FRPropertyToolsSEL, FRPropertyToolsIsVisibledSEL, L"FRPropertyToolsIsVisibled"},
	{FRPropertyToolsSEL, FRPropertyToolsShowSEL, L"FRPropertyToolsShow"},
	{FRPropertyToolsSEL, FRPropertyToolsIsEnabledSEL, L"FRPropertyToolsIsEnabled"},
	{FRPropertyToolsSEL, FRPropertyToolsEnableSEL, L"FRPropertyToolsEnable"},
	{FRPropertyToolsSEL, FRPropertyToolsReleaseEventSEL, L"FRPropertyToolsReleaseEvent"},
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
	{FRWindowsDIBSEL, FRWindowsDIBNewSEL, L"FRWindowsDIBNew"},
	{FRWindowsDIBSEL, FRWindowsDIBDestroySEL, L"FRWindowsDIBDestroy"},
	{FRWindowsDIBSEL, FRWindowsDIBGetBitmapInfoSEL, L"FRWindowsDIBGetBitmapInfo"},
	{FRWindowsDIBSEL, FRWindowsDIBLoadFromBufSEL, L"FRWindowsDIBLoadFromBuf"},
	{FRWindowsDIBSEL, FRWindowsDIBGetDDBitmapSEL, L"FRWindowsDIBGetDDBitmap"},
	{FRWindowsDIBSEL, FRWindowsDIBLoadFromDDBSEL, L"FRWindowsDIBLoadFromDDB"},
	{FRWindowsDIBSEL, FRWindowsDIBLoadFromFileSEL, L"FRWindowsDIBLoadFromFile"},
	{FRWindowsDIBSEL, FRWindowsDIBLoadFromFileIISEL, L"FRWindowsDIBLoadFromFileII"},
	{FRWindowsDIBSEL, FRWindowsDIBLoadDIBitmapSEL, L"FRWindowsDIBLoadDIBitmap"},
	{FRWindowsDIBSEL, FRWindowsDIBGetDCSEL, L"FRWindowsDIBGetDC"},
	{FRWindowsDIBSEL, FRWindowsDIBGetWindowsBitmapSEL, L"FRWindowsDIBGetWindowsBitmap"},
	{FRWindowsDIBSEL, FRWindowsDIBLoadFromDeviceSEL, L"FRWindowsDIBLoadFromDevice"},
	{FRWindowsDIBSEL, FRWindowsDIBSetToDeviceSEL, L"FRWindowsDIBSetToDevice"},
// fr_sysImpl.h end

// In file fr_viewImpl.h
	{FRAnnotSEL, FRAnnotGetPDFAnnotSEL, L"FRAnnotGetPDFAnnot"},
	{FRAnnotSEL, FRAnnotGetTypeSEL, L"FRAnnotGetType"},
	{FRAnnotSEL, FRAnnotGetSubTypeSEL, L"FRAnnotGetSubType"},
	{FRAnnotSEL, FRAnnotSetVisibleSEL, L"FRAnnotSetVisible"},
	{FRAnnotSEL, FRAnnotGetPageVewSEL, L"FRAnnotGetPageVew"},
	{FRAnnotSEL, FRAnnotGetTabOrderSEL, L"FRAnnotGetTabOrder"},
	{FRAnnotSEL, FRAnnotSetFlagsSEL, L"FRAnnotSetFlags"},
	{FRAnnotSEL, FRAnnotDrawAppearanceSEL, L"FRAnnotDrawAppearance"},
	{FRAnnotSEL, FRAnnotIsSelectedSEL, L"FRAnnotIsSelected"},
	{FRAnnotSEL, FRAnnotSetAuthorSEL, L"FRAnnotSetAuthor"},
	{FRAnnotSEL, FRAnnotGetFRDocByAnnotSEL, L"FRAnnotGetFRDocByAnnot"},
	{FRAnnotSEL, FRAnnotGetPageSEL, L"FRAnnotGetPage"},
	{FRAnnotSEL, FRAnnotGetXFAWidgetSEL, L"FRAnnotGetXFAWidget"},
	{FRAnnotSEL, FRAnnotGetCBFWidgetSEL, L"FRAnnotGetCBFWidget"},
	{FRAnnotSEL, FRAnnotGetBorderWidthSEL, L"FRAnnotGetBorderWidth"},
	{FRAnnotSEL, FRAnnotGetBorderStyleSEL, L"FRAnnotGetBorderStyle"},
	{FRAnnotSEL, FRAnnotSetBorderWidthSEL, L"FRAnnotSetBorderWidth"},
	{FRAnnotSEL, FRAnnotSetBorderStyleSEL, L"FRAnnotSetBorderStyle"},
	{FRAnnotSEL, FRAnnotGetLayoutOrderSEL, L"FRAnnotGetLayoutOrder"},
	{FRAnnotSEL, FRAnnotIsSameTabOrderSEL, L"FRAnnotIsSameTabOrder"},
	{FRAnnotSEL, FRAnnotNewSEL, L"FRAnnotNew"},
	{FRAnnotSEL, FRAnnotDeleteSEL, L"FRAnnotDelete"},
	{FRAnnotSEL, FRAnnotIsEnabledSEL, L"FRAnnotIsEnabled"},
	{FRAnnotSEL, FRAnnotSetEnabledSEL, L"FRAnnotSetEnabled"},
	{FRAnnotSEL, FRAnnotSelectAnnotSEL, L"FRAnnotSelectAnnot"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxGetSEL, L"FRResourcePropertyBoxGet"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxRegisterPropertyPageSEL, L"FRResourcePropertyBoxRegisterPropertyPage"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxRegisterSourceTypeSEL, L"FRResourcePropertyBoxRegisterSourceType"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxGetSourceTypeSEL, L"FRResourcePropertyBoxGetSourceType"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxGetSourceFuncSEL, L"FRResourcePropertyBoxGetSourceFunc"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxUpdatePropertyBoxSEL, L"FRResourcePropertyBoxUpdatePropertyBox"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxOpenPropertyBoxSEL, L"FRResourcePropertyBoxOpenPropertyBox"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxClosePropertyBoxSEL, L"FRResourcePropertyBoxClosePropertyBox"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxIsPropertyBoxVisibleSEL, L"FRResourcePropertyBoxIsPropertyBoxVisible"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxGetWndSEL, L"FRResourcePropertyBoxGetWnd"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxGetPropertyPageSEL, L"FRResourcePropertyBoxGetPropertyPage"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxSetCurrentPropertyPageSEL, L"FRResourcePropertyBoxSetCurrentPropertyPage"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxRegisterPropertyPage2SEL, L"FRResourcePropertyBoxRegisterPropertyPage2"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxDestroyPageSEL, L"FRResourcePropertyBoxDestroyPage"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxRegisterSourceType2SEL, L"FRResourcePropertyBoxRegisterSourceType2"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxDestroySourceSEL, L"FRResourcePropertyBoxDestroySource"},
	{FRResourcePropertyBoxSEL, FRResourcePropertyBoxAddPropertyNotifySEL, L"FRResourcePropertyBoxAddPropertyNotify"},
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
	{FPDFXFontEncodingSEL, FPDFXFontEncodingNewSEL, L"FPDFXFontEncodingNew"},
	{FPDFXFontEncodingSEL, FPDFXFontEncodingDestroySEL, L"FPDFXFontEncodingDestroy"},
	{FPDFXFontEncodingSEL, FPDFXFontEncodingGlyphFromCharCodeSEL, L"FPDFXFontEncodingGlyphFromCharCode"},
	{FPDFXFontEncodingSEL, FPDFXFontEncodingUnicodeFromCharCodeSEL, L"FPDFXFontEncodingUnicodeFromCharCode"},
	{FPDFXFontEncodingSEL, FPDFXFontEncodingCharCodeFromUnicodeSEL, L"FPDFXFontEncodingCharCodeFromUnicode"},
	{FPDFXFontEncodingSEL, FPDFXFontEncodingIsUnicodeCompatibleSEL, L"FPDFXFontEncodingIsUnicodeCompatible"},
	{FPDFXFontEncodingSEL, FPDFXFontEncodingGlyphFromCharCodeExSEL, L"FPDFXFontEncodingGlyphFromCharCodeEx"},
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V6----------
// In file fs_basicImpl.h
	{FSFileStreamSEL, FSFileStreamNewSEL, L"FSFileStreamNew"},
	{FSFileStreamSEL, FSFileStreamNew2SEL, L"FSFileStreamNew2"},
	{FSFileStreamSEL, FSFileStreamDestroySEL, L"FSFileStreamDestroy"},
	{FSFileStreamSEL, FSFileStreamGetFileReadSEL, L"FSFileStreamGetFileRead"},
	{FSFileStreamSEL, FSFileStreamGetFileWriteSEL, L"FSFileStreamGetFileWrite"},
	{FSFileStreamSEL, FSFileStreamCreateMemoryStreamSEL, L"FSFileStreamCreateMemoryStream"},
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
	{FRScrollBarThumbnailViewSEL, FRScrollBarThumbnailViewGetCurPageIndexSEL, L"FRScrollBarThumbnailViewGetCurPageIndex"},
	{FRScrollBarThumbnailViewSEL, FRScrollBarThumbnailViewGetPageRectSEL, L"FRScrollBarThumbnailViewGetPageRect"},
	{FRScrollBarThumbnailViewSEL, FRScrollBarThumbnailViewGetPDPageSEL, L"FRScrollBarThumbnailViewGetPDPage"},
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V7----------
// In file fs_basicImpl.h
	{FSGUIDSEL, FSGUIDCreateSEL, L"FSGUIDCreate"},
	{FSGUIDSEL, FSGUIDToStringSEL, L"FSGUIDToString"},
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
	{FRHTMLMgrSEL, FRHTMLMgrGetSEL, L"FRHTMLMgrGet"},
	{FRHTMLMgrSEL, FRHTMLMgrRegisterHTMLEventHandlerSEL, L"FRHTMLMgrRegisterHTMLEventHandler"},
	{FRHTMLMgrSEL, FRHTMLMgrOpenHTMLFromNewTabSEL, L"FRHTMLMgrOpenHTMLFromNewTab"},
	{FRHTMLMgrSEL, FRHTMLMgrOpenHTMLDocumentSEL, L"FRHTMLMgrOpenHTMLDocument"},
	{FRHTMLMgrSEL, FRHTMLMgrGetActiveHtmlViewSEL, L"FRHTMLMgrGetActiveHtmlView"},
	{FRHTMLMgrSEL, FRHTMLMgrRegisterFoxitBrowserEventHandlerSEL, L"FRHTMLMgrRegisterFoxitBrowserEventHandler"},
	{FRHTMLMgrSEL, FRHTMLMgrSetFoxitBrowserHomeSEL, L"FRHTMLMgrSetFoxitBrowserHome"},
	{FRHTMLMgrSEL, FRHTMLMgrSetFavoritesLinkSEL, L"FRHTMLMgrSetFavoritesLink"},
	{FRHTMLMgrSEL, FRHTMLMgrGetHtmlViewFromHandleSEL, L"FRHTMLMgrGetHtmlViewFromHandle"},
	{FRHTMLMgrSEL, FRHTMLMgrOpenHTMLFromNewTab2SEL, L"FRHTMLMgrOpenHTMLFromNewTab2"},
	{FRHTMLMgrSEL, FRHTMLMgrOpenHTMLDocument2SEL, L"FRHTMLMgrOpenHTMLDocument2"},
	{FRPanelMgrSEL, FRPanelMgrGetPanelMgrFromChildFrmSEL, L"FRPanelMgrGetPanelMgrFromChildFrm"},
	{FRPanelMgrSEL, FRPanelMgrNewPanelMgrSEL, L"FRPanelMgrNewPanelMgr"},
	{FRPanelMgrSEL, FRPanelMgrDeletePanelMgrSEL, L"FRPanelMgrDeletePanelMgr"},
	{FRPanelMgrSEL, FRPanelMgrCreatePanelEventHandlerSEL, L"FRPanelMgrCreatePanelEventHandler"},
	{FRPanelMgrSEL, FRPanelMgrDestroyPanelEventHandlerSEL, L"FRPanelMgrDestroyPanelEventHandler"},
	{FRPanelMgrSEL, FRPanelMgrCreateSEL, L"FRPanelMgrCreate"},
	{FRPanelMgrSEL, FRPanelMgrDockToFrameWindowSEL, L"FRPanelMgrDockToFrameWindow"},
	{FRPanelMgrSEL, FRPanelMgrAddPanelSEL, L"FRPanelMgrAddPanel"},
	{FRPanelMgrSEL, FRPanelMgrShowAllPanelSEL, L"FRPanelMgrShowAllPanel"},
	{FRPanelMgrSEL, FRPanelMgrShowPanelByNameSEL, L"FRPanelMgrShowPanelByName"},
	{FRPanelMgrSEL, FRPanelMgrResetAllPanelsSEL, L"FRPanelMgrResetAllPanels"},
	{FRPanelMgrSEL, FRPanelMgrGetPanelHwndByNameSEL, L"FRPanelMgrGetPanelHwndByName"},
	{FRPanelMgrSEL, FRPanelMgrIsAllPanelHideSEL, L"FRPanelMgrIsAllPanelHide"},
	{FRPanelMgrSEL, FRPanelMgrHasPanelFloatingSEL, L"FRPanelMgrHasPanelFloating"},
	{FRPanelMgrSEL, FRPanelMgrIsPanelHideSEL, L"FRPanelMgrIsPanelHide"},
	{FRPanelMgrSEL, FRPanelMgrGetParentFrameSEL, L"FRPanelMgrGetParentFrame"},
	{FRPanelMgrSEL, FRPanelMgrGetEnabledAlignmentSEL, L"FRPanelMgrGetEnabledAlignment"},
	{FRPanelMgrSEL, FRPanelMgrGetPanelViewByNameSEL, L"FRPanelMgrGetPanelViewByName"},
	{FRPanelMgrSEL, FRPanelMgrGetPanelNameByIndexSEL, L"FRPanelMgrGetPanelNameByIndex"},
	{FRPanelMgrSEL, FRPanelMgrGetPanelCountSEL, L"FRPanelMgrGetPanelCount"},
	{FRPanelMgrSEL, FRPanelMgrGetPanelTabRectByPtSEL, L"FRPanelMgrGetPanelTabRectByPt"},
	{FRPanelMgrSEL, FRPanelMgrGetPanelTabNameByPtSEL, L"FRPanelMgrGetPanelTabNameByPt"},
	{FRPanelMgrSEL, FRPanelMgrGetPanelTabRectByNameSEL, L"FRPanelMgrGetPanelTabRectByName"},
	{FRPanelMgrSEL, FRPanelMgrHidePanelTabByNameSEL, L"FRPanelMgrHidePanelTabByName"},
	{FRPanelMgrSEL, FRPanelMgrHasHistorySEL, L"FRPanelMgrHasHistory"},
	{FRPanelMgrSEL, FRPanelMgrLockAllPanelSEL, L"FRPanelMgrLockAllPanel"},
	{FRPanelMgrSEL, FRPanelMgrShowPanelByName2SEL, L"FRPanelMgrShowPanelByName2"},
	{FRPanelMgrSEL, FRPanelMgrIsPanelSpreadOutSEL, L"FRPanelMgrIsPanelSpreadOut"},
	{FRPanelMgrSEL, FRPanelMgrAddPanel2SEL, L"FRPanelMgrAddPanel2"},
	{FRPanelMgrSEL, FRPanelMgrRedockAllFloatToInitialSEL, L"FRPanelMgrRedockAllFloatToInitial"},
	{FRPanelMgrSEL, FRPanelMgrIsPanelFloatingSEL, L"FRPanelMgrIsPanelFloating"},
	{FRPanelMgrSEL, FRPanelMgrShrinkPanelByNameSEL, L"FRPanelMgrShrinkPanelByName"},
	{FRPanelMgrSEL, FRPanelMgrShowOnlyTabBarSEL, L"FRPanelMgrShowOnlyTabBar"},
// fr_appImpl.h end

// In file fr_barImpl.h
	{FRFuncBtnSEL, FRFuncBtnCreateSEL, L"FRFuncBtnCreate"},
	{FRFuncBtnSEL, FRFuncBtnAddToPanelSEL, L"FRFuncBtnAddToPanel"},
	{FRFuncBtnSEL, FRFuncBtnGetClientDataSEL, L"FRFuncBtnGetClientData"},
	{FRFuncBtnSEL, FRFuncBtnSetClientDataSEL, L"FRFuncBtnSetClientData"},
	{FRFuncBtnSEL, FRFuncBtnGetToolTipSEL, L"FRFuncBtnGetToolTip"},
	{FRFuncBtnSEL, FRFuncBtnSetToolTipSEL, L"FRFuncBtnSetToolTip"},
	{FRFuncBtnSEL, FRFuncBtnSetNameSEL, L"FRFuncBtnSetName"},
	{FRFuncBtnSEL, FRFuncBtnGetNameSEL, L"FRFuncBtnGetName"},
	{FRFuncBtnSEL, FRFuncBtnSetExecuteProcSEL, L"FRFuncBtnSetExecuteProc"},
	{FRFuncBtnSEL, FRFuncBtnSetComputeEnabledProcSEL, L"FRFuncBtnSetComputeEnabledProc"},
	{FRFuncBtnSEL, FRFuncBtnSetComputeMarkedProcSEL, L"FRFuncBtnSetComputeMarkedProc"},
	{FRFuncBtnSEL, FRFuncBtnUpdateImageSEL, L"FRFuncBtnUpdateImage"},
	{FRFuncBtnSEL, FRFuncBtnGetRectSEL, L"FRFuncBtnGetRect"},
	{FRFuncBtnSEL, FRFuncBtnAddToTabBandSEL, L"FRFuncBtnAddToTabBand"},
	{FRStatusBarSEL, FRStatusBarAddWndExSEL, L"FRStatusBarAddWndEx"},
	{FRStatusBarSEL, FRStatusBarResetSEL, L"FRStatusBarReset"},
	{FRStatusBarSEL, FRStatusBarSetZoomSliderRangeSEL, L"FRStatusBarSetZoomSliderRange"},
	{FRStatusBarSEL, FRStatusBarSetZoomSliderPosSEL, L"FRStatusBarSetZoomSliderPos"},
	{FRStatusBarSEL, FRStatusBarGetZoomSliderPosSEL, L"FRStatusBarGetZoomSliderPos"},
	{FRStatusBarSEL, FRStatusBarSetZoomPaneTextSEL, L"FRStatusBarSetZoomPaneText"},
	{FRStatusBarSEL, FRStatusBarSetComboBoxPageCountSEL, L"FRStatusBarSetComboBoxPageCount"},
	{FRStatusBarSEL, FRStatusBarSelectComboBoxItemSEL, L"FRStatusBarSelectComboBoxItem"},
	{FRStatusBarSEL, FRStatusBarGetComboBoxPageIndexSEL, L"FRStatusBarGetComboBoxPageIndex"},
	{FRStatusBarSEL, FRStatusBarGetComboBoxPageTextSEL, L"FRStatusBarGetComboBoxPageText"},
	{FRStatusBarSEL, FRStatusBarGetBkGroundColorSEL, L"FRStatusBarGetBkGroundColor"},
	{FRStatusBarSEL, FRStatusBarGetBkGroundPathSEL, L"FRStatusBarGetBkGroundPath"},
	{FRStatusBarSEL, FRStatusBarRecalcLayoutSEL, L"FRStatusBarRecalcLayout"},
	{FRStatusBarSEL, FRStatusBarSetComboBoxPageCount2SEL, L"FRStatusBarSetComboBoxPageCount2"},
	{FRStatusBarSEL, FRStatusBarSelectComboBoxItem2SEL, L"FRStatusBarSelectComboBoxItem2"},
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
	{FPDConnectedInfoSEL, FPDConnectedInfoNewSEL, L"FPDConnectedInfoNew"},
	{FPDConnectedInfoSEL, FPDConnectedInfoDestroySEL, L"FPDConnectedInfoDestroy"},
	{FPDConnectedInfoSEL, FPDConnectedInfoSetIdSEL, L"FPDConnectedInfoSetId"},
	{FPDConnectedInfoSEL, FPDConnectedInfoGetIdSEL, L"FPDConnectedInfoGetId"},
	{FPDConnectedInfoSEL, FPDConnectedInfoIsConnectedPDFSEL, L"FPDConnectedInfoIsConnectedPDF"},
	{FPDConnectedInfoSEL, FPDConnectedInfoIsConnectedPDF2SEL, L"FPDConnectedInfoIsConnectedPDF2"},
	{FPDConnectedInfoSEL, FPDConnectedInfoSetTrackingSEL, L"FPDConnectedInfoSetTracking"},
	{FPDConnectedInfoSEL, FPDConnectedInfoGetTrackingSEL, L"FPDConnectedInfoGetTracking"},
	{FPDConnectedInfoSEL, FPDConnectedInfoUpdateSEL, L"FPDConnectedInfoUpdate"},
	{FPDConnectedInfoSEL, FPDConnectedInfoSetEncryptOfflineSEL, L"FPDConnectedInfoSetEncryptOffline"},
	{FPDConnectedInfoSEL, FPDConnectedInfoSetEncryptEnvelopeSEL, L"FPDConnectedInfoSetEncryptEnvelope"},
	{FPDConnectedInfoSEL, FPDConnectedInfoGetEncryptOfflineSEL, L"FPDConnectedInfoGetEncryptOffline"},
	{FPDConnectedInfoSEL, FPDConnectedInfoGetEncryptEnvelopeSEL, L"FPDConnectedInfoGetEncryptEnvelope"},
	{FPDConnectedInfoSEL, FPDConnectedInfoSetOpenActionURLSEL, L"FPDConnectedInfoSetOpenActionURL"},
	{FPDConnectedInfoSEL, FPDConnectedInfoSetOpenActionURL2SEL, L"FPDConnectedInfoSetOpenActionURL2"},
	{FPDConnectedInfoSEL, FPDConnectedInfoCheckSettingOpenActionSEL, L"FPDConnectedInfoCheckSettingOpenAction"},
	{FPDConnectedInfoSEL, FPDConnectedInfoDeleteOpenActionSEL, L"FPDConnectedInfoDeleteOpenAction"},
	{FPDConnectedInfoSEL, FPDConnectedInfoSetEndpointSEL, L"FPDConnectedInfoSetEndpoint"},
	{FPDConnectedInfoSEL, FPDConnectedInfoGetEndpointSEL, L"FPDConnectedInfoGetEndpoint"},
	{FPDConnectedInfoSEL, FPDConnectedInfoRemoveConnectPDFSEL, L"FPDConnectedInfoRemoveConnectPDF"},
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V8----------
// In file fs_basicImpl.h
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
	{FRCustomSignatureSEL, FRCustomSignatureGenerateSignInfoSEL, L"FRCustomSignatureGenerateSignInfo"},
	{FRCustomSignatureSEL, FRCustomSignatureGetDefaultServerSEL, L"FRCustomSignatureGetDefaultServer"},
	{FRCustomSignatureSEL, FRCustomSignatureCreateSignatureHandlerSEL, L"FRCustomSignatureCreateSignatureHandler"},
	{FRCustomSignatureSEL, FRCustomSignatureRegisterSignatureHandlerSEL, L"FRCustomSignatureRegisterSignatureHandler"},
	{FRCustomSignatureSEL, FRCustomSignatureDestroySignatureHandlerSEL, L"FRCustomSignatureDestroySignatureHandler"},
	{FRCustomSignatureSEL, FRCustomSignatureSetSignatureVerifySEL, L"FRCustomSignatureSetSignatureVerify"},
	{FRCustomSignatureSEL, FRCustomSignatureGetDocSigatureCountSEL, L"FRCustomSignatureGetDocSigatureCount"},
	{FRCustomSignatureSEL, FRCustomSignatureGetSignatureBaseInfoSEL, L"FRCustomSignatureGetSignatureBaseInfo"},
	{FRCustomSignatureSEL, FRCustomSignatureClearSignatureSEL, L"FRCustomSignatureClearSignature"},
	{FRCustomSignatureSEL, FRCustomSignatureFoxitSignInScopeSEL, L"FRCustomSignatureFoxitSignInScope"},
	{FRCustomSignatureSEL, FRCustomSignatureFoixtCreateSignatureFSEL, L"FRCustomSignatureFoixtCreateSignatureF"},
	{FRCustomSignatureSEL, FRCustomSignatureSetPositionSEL, L"FRCustomSignatureSetPosition"},
	{FRCustomSignatureSEL, FRCustomSignatureGenerateSignInfo2SEL, L"FRCustomSignatureGenerateSignInfo2"},
	{FRCustomSignatureSEL, FRCustomSignaturePrepareSignSEL, L"FRCustomSignaturePrepareSign"},
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V9----------
// In file fs_basicImpl.h
	{FSUUIDSEL, FSUUIDGenerateSEL, L"FSUUIDGenerate"},
	{FSUUIDSEL, FSUUIDGenerateTimeSEL, L"FSUUIDGenerateTime"},
	{FSUUIDSEL, FSUUIDGenerateRandomSEL, L"FSUUIDGenerateRandom"},
	{FSUUIDSEL, FSUUIDSetTsPathSEL, L"FSUUIDSetTsPath"},
	{FSUUIDSEL, FSUUIDSetStateSEL, L"FSUUIDSetState"},
	{FSUUIDSEL, FSUUIDSetUserDataSEL, L"FSUUIDSetUserData"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrNewSEL, L"FSMapByteStringToPtrNew"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrDestroySEL, L"FSMapByteStringToPtrDestroy"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrGetCountSEL, L"FSMapByteStringToPtrGetCount"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrIsEmptySEL, L"FSMapByteStringToPtrIsEmpty"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrLookupSEL, L"FSMapByteStringToPtrLookup"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrSetAtSEL, L"FSMapByteStringToPtrSetAt"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrRemoveKeySEL, L"FSMapByteStringToPtrRemoveKey"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrRemoveAllSEL, L"FSMapByteStringToPtrRemoveAll"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrGetStartPositionSEL, L"FSMapByteStringToPtrGetStartPosition"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrGetNextAssocSEL, L"FSMapByteStringToPtrGetNextAssoc"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrGetNextValueSEL, L"FSMapByteStringToPtrGetNextValue"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrGetHashTableSizeSEL, L"FSMapByteStringToPtrGetHashTableSize"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrInitHashTableSEL, L"FSMapByteStringToPtrInitHashTable"},
	{FSMapByteStringToPtrSEL, FSMapByteStringToPtrHashKeySEL, L"FSMapByteStringToPtrHashKey"},
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
	{FRCloudLoginProviderSEL, FRCloudLoginProviderSetSEL, L"FRCloudLoginProviderSet"},
	{FRCloudLoginProviderSEL, FRCloudLoginProviderDestroySEL, L"FRCloudLoginProviderDestroy"},
	{FRCloudLoginProviderSEL, FRCloudLoginProviderGetSEL, L"FRCloudLoginProviderGet"},
	{FRCloudLoginProviderSEL, FRCloudLoginProviderIsLogInSEL, L"FRCloudLoginProviderIsLogIn"},
	{FRCloudLoginProviderSEL, FRCloudLoginProviderSignInSEL, L"FRCloudLoginProviderSignIn"},
	{FRCloudLoginProviderSEL, FRCloudLoginProviderSignOutSEL, L"FRCloudLoginProviderSignOut"},
	{FRCloudLoginProviderSEL, FRCloudLoginProviderGetUserInfoSEL, L"FRCloudLoginProviderGetUserInfo"},
// fr_appImpl.h end

// In file fr_barImpl.h
	{FRBulbMsgCenterSEL, FRBulbMsgCenterAddMessageSEL, L"FRBulbMsgCenterAddMessage"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterShowMessageSEL, L"FRBulbMsgCenterShowMessage"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterSetCheckSEL, L"FRBulbMsgCenterSetCheck"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterSetOpBtnEnableSEL, L"FRBulbMsgCenterSetOpBtnEnable"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterIsMessageExistSEL, L"FRBulbMsgCenterIsMessageExist"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterIsOpBtnEnableSEL, L"FRBulbMsgCenterIsOpBtnEnable"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterSetOpBtnTitleSEL, L"FRBulbMsgCenterSetOpBtnTitle"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterSetMessageContentSEL, L"FRBulbMsgCenterSetMessageContent"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterGetButtonRectSEL, L"FRBulbMsgCenterGetButtonRect"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterAddMessage2SEL, L"FRBulbMsgCenterAddMessage2"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterShowMessage2SEL, L"FRBulbMsgCenterShowMessage2"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterAddMessage3SEL, L"FRBulbMsgCenterAddMessage3"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterAddMessage4SEL, L"FRBulbMsgCenterAddMessage4"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterAddMessage5SEL, L"FRBulbMsgCenterAddMessage5"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterIsMessageVisibleSEL, L"FRBulbMsgCenterIsMessageVisible"},
	{FRBulbMsgCenterSEL, FRBulbMsgCenterAddAndShowMessageSEL, L"FRBulbMsgCenterAddAndShowMessage"},
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
	{FPDEPUBSEL, FPDEPUBOpenSEL, L"FPDEPUBOpen"},
	{FPDEPUBSEL, FPDEPUBReleaseDocumentSEL, L"FPDEPUBReleaseDocument"},
	{FPDEPUBSEL, FPDEPUBCloseSEL, L"FPDEPUBClose"},
	{FPDEPUBSEL, FPDEPUBUnLoadDocPageSEL, L"FPDEPUBUnLoadDocPage"},
	{FPDEPUBSEL, FPDEPUBLoadPageSEL, L"FPDEPUBLoadPage"},
	{FPDEPUBSEL, FPDEPUBUnloadPageSEL, L"FPDEPUBUnloadPage"},
	{FPDEPUBSEL, FPDEPUBLoadSectionSEL, L"FPDEPUBLoadSection"},
	{FPDEPUBSEL, FPDEPUBUnloadSectionSEL, L"FPDEPUBUnloadSection"},
	{FPDEPUBSEL, FPDEPUBGetParserSEL, L"FPDEPUBGetParser"},
	{FPDEPUBSEL, FPDEPUBGetPageSEL, L"FPDEPUBGetPage"},
	{FPDEPUBSEL, FPDEPUBGetDocumentSectionSEL, L"FPDEPUBGetDocumentSection"},
	{FPDEPUBSEL, FPDEPUBCountSectionsSEL, L"FPDEPUBCountSections"},
	{FPDEPUBSEL, FPDEPUBGetSectionIndexSEL, L"FPDEPUBGetSectionIndex"},
	{FPDEPUBSEL, FPDEPUBCountPagesSEL, L"FPDEPUBCountPages"},
	{FPDEPUBSEL, FPDEPUBGetBookmarkSEL, L"FPDEPUBGetBookmark"},
	{FPDEPUBSEL, FPDEPUBGetNamedDestSEL, L"FPDEPUBGetNamedDest"},
	{FPDEPUBSEL, FPDEPUBReParseSEL, L"FPDEPUBReParse"},
	{FPDEPUBSEL, FPDEPUBGetPageSectionSEL, L"FPDEPUBGetPageSection"},
	{FPDEPUBSEL, FPDEPUBGetPageRectSEL, L"FPDEPUBGetPageRect"},
	{FPDEPUBSEL, FPDEPUBGetParentBookmarkSEL, L"FPDEPUBGetParentBookmark"},
	{FPDEPUBSEL, FPDEPUBCountSubBookmarksSEL, L"FPDEPUBCountSubBookmarks"},
	{FPDEPUBSEL, FPDEPUBGetSubBookmarkSEL, L"FPDEPUBGetSubBookmark"},
	{FPDEPUBSEL, FPDEPUBGetBookmarkStylesSEL, L"FPDEPUBGetBookmarkStyles"},
	{FPDEPUBSEL, FPDEPUBGetBookmarkTitleSEL, L"FPDEPUBGetBookmarkTitle"},
	{FPDEPUBSEL, FPDEPUBGetBookmarkExternalDocNameSEL, L"FPDEPUBGetBookmarkExternalDocName"},
	{FPDEPUBSEL, FPDEPUBGetBookmarkURISEL, L"FPDEPUBGetBookmarkURI"},
	{FPDEPUBSEL, FPDEPUBGetBookmarkNamedStringSEL, L"FPDEPUBGetBookmarkNamedString"},
	{FPDEPUBSEL, FPDEPUBIsBookmarkOpenedSEL, L"FPDEPUBIsBookmarkOpened"},
	{FPDEPUBSEL, FPDEPUBCreateTextSelectionSEL, L"FPDEPUBCreateTextSelection"},
	{FPDEPUBSEL, FPDEPUBReleaseTextSelectionSEL, L"FPDEPUBReleaseTextSelection"},
	{FPDEPUBSEL, FPDEPUBTextSelectionAttachPageSEL, L"FPDEPUBTextSelectionAttachPage"},
	{FPDEPUBSEL, FPDEPUBTextSelectionResetSEL, L"FPDEPUBTextSelectionReset"},
	{FPDEPUBSEL, FPDEPUBSetSelectStartPosSEL, L"FPDEPUBSetSelectStartPos"},
	{FPDEPUBSEL, FPDEPUBGetSelectStartPosSEL, L"FPDEPUBGetSelectStartPos"},
	{FPDEPUBSEL, FPDEPUBGetSelectCurPosSEL, L"FPDEPUBGetSelectCurPos"},
	{FPDEPUBSEL, FPDEPUBSelectWordSEL, L"FPDEPUBSelectWord"},
	{FPDEPUBSEL, FPDEPUBSelectRectangleTextSEL, L"FPDEPUBSelectRectangleText"},
	{FPDEPUBSEL, FPDEPUBSelectParagraphTextSEL, L"FPDEPUBSelectParagraphText"},
	{FPDEPUBSEL, FPDEPUBSelectNextCharSEL, L"FPDEPUBSelectNextChar"},
	{FPDEPUBSEL, FPDEPUBSelectPrevCharSEL, L"FPDEPUBSelectPrevChar"},
	{FPDEPUBSEL, FPDEPUBSelectNextWordSEL, L"FPDEPUBSelectNextWord"},
	{FPDEPUBSEL, FPDEPUBSelectPrevWordSEL, L"FPDEPUBSelectPrevWord"},
	{FPDEPUBSEL, FPDEPUBSelectNextLineSEL, L"FPDEPUBSelectNextLine"},
	{FPDEPUBSEL, FPDEPUBSelectPrevLineSEL, L"FPDEPUBSelectPrevLine"},
	{FPDEPUBSEL, FPDEPUBCountSelectRectsSEL, L"FPDEPUBCountSelectRects"},
	{FPDEPUBSEL, FPDEPUBGetSelectRectSEL, L"FPDEPUBGetSelectRect"},
	{FPDEPUBSEL, FPDEPUBCopySelectTextSEL, L"FPDEPUBCopySelectText"},
	{FPDEPUBSEL, FPDEPUBCreateTextSearchSEL, L"FPDEPUBCreateTextSearch"},
	{FPDEPUBSEL, FPDEPUBReleaseTextSearchSEL, L"FPDEPUBReleaseTextSearch"},
	{FPDEPUBSEL, FPDEPUBTextSearchAttachPageSEL, L"FPDEPUBTextSearchAttachPage"},
	{FPDEPUBSEL, FPDEPUBFindFirstSEL, L"FPDEPUBFindFirst"},
	{FPDEPUBSEL, FPDEPUBFindNextSEL, L"FPDEPUBFindNext"},
	{FPDEPUBSEL, FPDEPUBFindPrevSEL, L"FPDEPUBFindPrev"},
	{FPDEPUBSEL, FPDEPUBGetSearchPosSEL, L"FPDEPUBGetSearchPos"},
	{FPDEPUBSEL, FPDEPUBCountSearchRectsSEL, L"FPDEPUBCountSearchRects"},
	{FPDEPUBSEL, FPDEPUBGetSearchRectSEL, L"FPDEPUBGetSearchRect"},
	{FPDEPUBSEL, FPDEPUBTransfer2DocPointSEL, L"FPDEPUBTransfer2DocPoint"},
	{FPDEPUBSEL, FPDEPUBTransfer2DocPointRectSEL, L"FPDEPUBTransfer2DocPointRect"},
	{FPDEPUBSEL, FPDEPUBFDEGetPageMatrixSEL, L"FPDEPUBFDEGetPageMatrix"},
	{FPDEPUBSEL, FPDEPUBCreateRenderDeviceSEL, L"FPDEPUBCreateRenderDevice"},
	{FPDEPUBSEL, FPDEPUBReleaseRenderDeviceSEL, L"FPDEPUBReleaseRenderDevice"},
	{FPDEPUBSEL, FPDEPUBRenderDeviceSetClipRectSEL, L"FPDEPUBRenderDeviceSetClipRect"},
	{FPDEPUBSEL, FPDEPUBCreateRenderContextSEL, L"FPDEPUBCreateRenderContext"},
	{FPDEPUBSEL, FPDEPUBReleaseRenderContextSEL, L"FPDEPUBReleaseRenderContext"},
	{FPDEPUBSEL, FPDEPUBRenderContextRenderingSEL, L"FPDEPUBRenderContextRendering"},
	{FPDEPUBSEL, FPDEPUBDoRenderSEL, L"FPDEPUBDoRender"},
	{FPDEPUBSEL, FPDEPUBEpubArgbEncodeSEL, L"FPDEPUBEpubArgbEncode"},
	{FPDEPUBSEL, FPDEPUBInitFDEMgrSEL, L"FPDEPUBInitFDEMgr"},
	{FPDEPUBSEL, FPDEPUBReleaseFDEMgrSEL, L"FPDEPUBReleaseFDEMgr"},
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V10----------
// In file fs_basicImpl.h
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
	{FOFDPauseHandlerSEL, FOFDPauseHandlerCreateSEL, L"FOFDPauseHandlerCreate"},
	{FOFDPauseHandlerSEL, FOFDPauseHandlerDestroySEL, L"FOFDPauseHandlerDestroy"},
	{FOFDUIMgrSEL, FOFDUIMgrSetPanelIndexSEL, L"FOFDUIMgrSetPanelIndex"},
	{FOFDUIMgrSEL, FOFDUIMgrTriggerPanelSEL, L"FOFDUIMgrTriggerPanel"},
	{FOFDUIMgrSEL, FOFDUIMgrFormatComboBoxSEL, L"FOFDUIMgrFormatComboBox"},
	{FOFDUIMgrSEL, FOFDUIMgrShowAutoHideStatusBarSEL, L"FOFDUIMgrShowAutoHideStatusBar"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeCreateSEL, L"FOFDDIBAttributeCreate"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetXDPISEL, L"FOFDDIBAttributeGetXDPI"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetXDPISEL, L"FOFDDIBAttributeSetXDPI"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetYDPISEL, L"FOFDDIBAttributeGetYDPI"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetYDPISEL, L"FOFDDIBAttributeSetYDPI"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetAspectRatioSEL, L"FOFDDIBAttributeGetAspectRatio"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetAspectRatioSEL, L"FOFDDIBAttributeSetAspectRatio"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetDPIUnitSEL, L"FOFDDIBAttributeGetDPIUnit"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetDPIUnitSEL, L"FOFDDIBAttributeSetDPIUnit"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetAuthorSEL, L"FOFDDIBAttributeGetAuthor"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetAuthorSEL, L"FOFDDIBAttributeSetAuthor"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetTimeSEL, L"FOFDDIBAttributeGetTime"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetTimeSEL, L"FOFDDIBAttributeSetTime"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetGifLeftSEL, L"FOFDDIBAttributeGetGifLeft"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetGifLeftSEL, L"FOFDDIBAttributeSetGifLeft"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetGifTopSEL, L"FOFDDIBAttributeGetGifTop"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetGifTopSEL, L"FOFDDIBAttributeSetGifTop"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetGifLocalPaletteSEL, L"FOFDDIBAttributeGetGifLocalPalette"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetGifLocalPaletteSEL, L"FOFDDIBAttributeSetGifLocalPalette"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetGifLocalPalNumSEL, L"FOFDDIBAttributeGetGifLocalPalNum"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetGifLocalPalNumSEL, L"FOFDDIBAttributeSetGifLocalPalNum"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetBmpCompressTypeSEL, L"FOFDDIBAttributeGetBmpCompressType"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetBmpCompressTypeSEL, L"FOFDDIBAttributeSetBmpCompressType"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetTiffFrameCompressTypeSEL, L"FOFDDIBAttributeGetTiffFrameCompressType"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetTiffFrameCompressTypeSEL, L"FOFDDIBAttributeSetTiffFrameCompressType"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetTiffFrameCompressOptionsSEL, L"FOFDDIBAttributeGetTiffFrameCompressOptions"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetTiffFrameCompressOptionsSEL, L"FOFDDIBAttributeSetTiffFrameCompressOptions"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetTiffFrameFillOrderSEL, L"FOFDDIBAttributeGetTiffFrameFillOrder"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetTiffFrameFillOrderSEL, L"FOFDDIBAttributeSetTiffFrameFillOrder"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeGetTiffFrameCompressJpegQualitySEL, L"FOFDDIBAttributeGetTiffFrameCompressJpegQuality"},
	{FOFDDIBAttributeSEL, FOFDDIBAttributeSetTiffFrameCompressJpegQualitySEL, L"FOFDDIBAttributeSetTiffFrameCompressJpegQuality"},
	{FOFDCodeCSEL, FOFDCodeCPngEncodeSEL, L"FOFDCodeCPngEncode"},
	{FOFDPrintSettingSEL, FOFDPrintSettingGetGlobalUnitSEL, L"FOFDPrintSettingGetGlobalUnit"},
	{FOFDPrintSettingSEL, FOFDPrintSettingGetDefaultPrinterNameSEL, L"FOFDPrintSettingGetDefaultPrinterName"},
	{FOFDPrintSettingSEL, FOFDPrintSettingGetDefaultPrinterDevModeSEL, L"FOFDPrintSettingGetDefaultPrinterDevMode"},
	{FOFDPrintSettingSEL, FOFDPrintSettingSetDefaultPrinterDevModeSEL, L"FOFDPrintSettingSetDefaultPrinterDevMode"},
	{FOFDPrintSettingSEL, FOFDPrintSettingIsPrintUseGraphicsSEL, L"FOFDPrintSettingIsPrintUseGraphics"},
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
	{FOFDRenderDeviceSEL, FOFDRenderDeviceSaveBitmapSEL, L"FOFDRenderDeviceSaveBitmap"},
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
	{FOFDSignSEL, FOFDSignCreateSealBitmapSEL, L"FOFDSignCreateSealBitmap"},
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
	{FPDWrapperDocSEL, FPDWrapperDocNewSEL, L"FPDWrapperDocNew"},
	{FPDWrapperDocSEL, FPDWrapperDocDestroySEL, L"FPDWrapperDocDestroy"},
	{FPDWrapperDocSEL, FPDWrapperDocGetWrapperTypeSEL, L"FPDWrapperDocGetWrapperType"},
	{FPDWrapperDocSEL, FPDWrapperDocGetCryptographicFilterSEL, L"FPDWrapperDocGetCryptographicFilter"},
	{FPDWrapperDocSEL, FPDWrapperDocGetPayLoadSizeSEL, L"FPDWrapperDocGetPayLoadSize"},
	{FPDWrapperDocSEL, FPDWrapperDocGetPayloadFileNameSEL, L"FPDWrapperDocGetPayloadFileName"},
	{FPDWrapperDocSEL, FPDWrapperDocStartGetPayloadSEL, L"FPDWrapperDocStartGetPayload"},
	{FPDWrapperDocSEL, FPDWrapperDocContinueSEL, L"FPDWrapperDocContinue"},
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
	{FPDUnencryptedWrapperCreatorSEL, FPDUnencryptedWrapperCreatorNewSEL, L"FPDUnencryptedWrapperCreatorNew"},
	{FPDUnencryptedWrapperCreatorSEL, FPDUnencryptedWrapperCreatorDestroySEL, L"FPDUnencryptedWrapperCreatorDestroy"},
	{FPDUnencryptedWrapperCreatorSEL, FPDUnencryptedWrapperCreatorSetPayloadInfoSEL, L"FPDUnencryptedWrapperCreatorSetPayloadInfo"},
	{FPDUnencryptedWrapperCreatorSEL, FPDUnencryptedWrapperCreatorSetPayLoadSEL, L"FPDUnencryptedWrapperCreatorSetPayLoad"},
	{FPDUnencryptedWrapperCreatorSEL, FPDUnencryptedWrapperCreatorCreateSEL, L"FPDUnencryptedWrapperCreatorCreate"},
	{FPDUnencryptedWrapperCreatorSEL, FPDUnencryptedWrapperCreatorContinueSEL, L"FPDUnencryptedWrapperCreatorContinue"},
	{FPDUnencryptedWrapperCreatorSEL, FPDUnencryptedWrapperCreatorSetStandardSecuritySEL, L"FPDUnencryptedWrapperCreatorSetStandardSecurity"},
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V11----------
// In file fs_basicImpl.h
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
	{FRAppFxNetSEL, FRAppFxNetRegisterAppEventHandlerFxNetSEL, L"FRAppFxNetRegisterAppEventHandlerFxNet"},
	{FRInternalFxNetSEL, FRInternalFxNetIsFRDGLoginSEL, L"FRInternalFxNetIsFRDGLogin"},
	{FRInternalFxNetSEL, FRInternalFxNetShowLoginDlgSEL, L"FRInternalFxNetShowLoginDlg"},
	{FRInternalFxNetSEL, FRInternalFxNetDllGetTicketSEL, L"FRInternalFxNetDllGetTicket"},
	{FRInternalFxNetSEL, FRInternalFxNetCheckActionPermissionSEL, L"FRInternalFxNetCheckActionPermission"},
	{FRInternalFxNetSEL, FRInternalFxNetCheckPRDTimestampPermissionSEL, L"FRInternalFxNetCheckPRDTimestampPermission"},
	{FRInternalFxNetSEL, FRInternalFxNetCheckPermissionByFaceNameSEL, L"FRInternalFxNetCheckPermissionByFaceName"},
	{FRInternalFxNetSEL, FRInternalFxNetGetLoginHwndSEL, L"FRInternalFxNetGetLoginHwnd"},
	{FRInternalFxNetSEL, FRInternalFxNetPreTranMsgToSdkSEL, L"FRInternalFxNetPreTranMsgToSdk"},
	{FRInternalFxNetSEL, FRInternalFxNetDllShowPaymentDlgSEL, L"FRInternalFxNetDllShowPaymentDlg"},
	{FRInternalFxNetSEL, FRInternalFxNetGetUserIdSEL, L"FRInternalFxNetGetUserId"},
	{FRInternalFxNetSEL, FRInternalFxNetGetNickNameSEL, L"FRInternalFxNetGetNickName"},
	{FRInternalFxNetSEL, FRInternalFxNetGetHeadIconSEL, L"FRInternalFxNetGetHeadIcon"},
	{FRInternalFxNetSEL, FRInternalFxNetGetUserTypeSEL, L"FRInternalFxNetGetUserType"},
	{FRInternalFxNetSEL, FRInternalFxNetAddAnnotToMarkupPanelSEL, L"FRInternalFxNetAddAnnotToMarkupPanel"},
	{FRInternalFxNetSEL, FRInternalFxNetShowAnnotNoteSEL, L"FRInternalFxNetShowAnnotNote"},
	{FRInternalFxNetSEL, FRInternalFxNetGetCurrentImageSelectObjSEL, L"FRInternalFxNetGetCurrentImageSelectObj"},
	{FRInternalFxNetSEL, FRInternalFxNetOCRExtractTextSEL, L"FRInternalFxNetOCRExtractText"},
	{FRInternalFxNetSEL, FRInternalFxNetGetOCRLanInfoSEL, L"FRInternalFxNetGetOCRLanInfo"},
	{FRInternalFxNetSEL, FRInternalFxNetGetImageBufSEL, L"FRInternalFxNetGetImageBuf"},
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
	{FPDColorSeparatorSEL, FPDColorSeparatorNewSEL, L"FPDColorSeparatorNew"},
	{FPDColorSeparatorSEL, FPDColorSeparatorDestroySEL, L"FPDColorSeparatorDestroy"},
	{FPDColorSeparatorSEL, FPDColorSeparatorCountColorantsSEL, L"FPDColorSeparatorCountColorants"},
	{FPDColorSeparatorSEL, FPDColorSeparatorGetColorantNameSEL, L"FPDColorSeparatorGetColorantName"},
	{FPDColorSeparatorSEL, FPDColorSeparatorSeparateColorantSEL, L"FPDColorSeparatorSeparateColorant"},
	{FPDColorSeparatorSEL, FPDColorSeparatorGetResultDocSEL, L"FPDColorSeparatorGetResultDoc"},
	{FPDColorSeparatorSEL, FPDColorSeparatorSetColorConverterSEL, L"FPDColorSeparatorSetColorConverter"},
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
	{FPDColorConvertorSEL, FPDColorConvertorNewSEL, L"FPDColorConvertorNew"},
	{FPDColorConvertorSEL, FPDColorConvertorDestroySEL, L"FPDColorConvertorDestroy"},
	{FPDColorConvertorSEL, FPDColorConvertorSetICCProfilesPathSEL, L"FPDColorConvertorSetICCProfilesPath"},
	{FPDColorConvertorSEL, FPDColorConvertorGetObjColorSpaceSEL, L"FPDColorConvertorGetObjColorSpace"},
	{FPDColorConvertorSEL, FPDColorConvertorIsCalibrateColorSpaceSEL, L"FPDColorConvertorIsCalibrateColorSpace"},
	{FPDColorConvertorSEL, FPDColorConvertorDecalibrateColorSEL, L"FPDColorConvertorDecalibrateColor"},
	{FPDColorConvertorSEL, FPDColorConvertorConvertColorSEL, L"FPDColorConvertorConvertColor"},
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V12----------
// In file fs_basicImpl.h
	{FSImageSEL, FSImageCreateSEL, L"FSImageCreate"},
	{FSImageSEL, FSImageReleaseSEL, L"FSImageRelease"},
	{FSImageSEL, FSImageLoadSEL, L"FSImageLoad"},
	{FSImageSEL, FSImageGetTypeSEL, L"FSImageGetType"},
	{FSImageSEL, FSImageEnableTransparentSEL, L"FSImageEnableTransparent"},
	{FSImageSEL, FSImageSetBackgroundColorSEL, L"FSImageSetBackgroundColor"},
	{FSImageSEL, FSImageSetOpacitySEL, L"FSImageSetOpacity"},
	{FSImageSEL, FSImageCountFramesSEL, L"FSImageCountFrames"},
	{FSImageSEL, FSImageLoadFrameSEL, L"FSImageLoadFrame"},
	{FSImageSEL, FSImageNeedLoadPrevFrameSEL, L"FSImageNeedLoadPrevFrame"},
	{FSImageSEL, FSImageGetFrameSizeSEL, L"FSImageGetFrameSize"},
	{FSImageSEL, FSImageGetFrameSEL, L"FSImageGetFrame"},
	{FSImageSEL, FSImageGetFrameColorKeySEL, L"FSImageGetFrameColorKey"},
	{FSImageSEL, FSImageGetFrameWithTransparencySEL, L"FSImageGetFrameWithTransparency"},
	{FSImageSEL, FSImageGetFrameRawDataSEL, L"FSImageGetFrameRawData"},
	{FSImageSEL, FSImageGetFrameCompressSEL, L"FSImageGetFrameCompress"},
	{FSImageSEL, FSImageGetFramePhotoInterpretSEL, L"FSImageGetFramePhotoInterpret"},
	{FSImageSEL, FSImageFreeSEL, L"FSImageFree"},
	{FSImageSEL, FSImageGetAttributeSEL, L"FSImageGetAttribute"},
	{FSImageSEL, FSImageGetWidthSEL, L"FSImageGetWidth"},
	{FSImageSEL, FSImageGetHeightSEL, L"FSImageGetHeight"},
	{FSImageSEL, FSImageCreateObjectSEL, L"FSImageCreateObject"},
	{FSImageSEL, FSImageInsertToPDFPageSEL, L"FSImageInsertToPDFPage"},
	{FSImageSEL, FSImageInsertToPDFDocumentSEL, L"FSImageInsertToPDFDocument"},
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
	{FRAssistantMgrSEL, FRAssistantMgrGetSEL, L"FRAssistantMgrGet"},
	{FRAssistantMgrSEL, FRAssistantMgrSetCurAsstTrackWndSEL, L"FRAssistantMgrSetCurAsstTrackWnd"},
	{FRAssistantMgrSEL, FRAssistantMgrUpdateAssistantHandlerSEL, L"FRAssistantMgrUpdateAssistantHandler"},
	{FRAssistantMgrSEL, FRAssistantMgrNotificationSEL, L"FRAssistantMgrNotification"},
	{FRAssistantMgrSEL, FRAssistantMgrClearNotificationSEL, L"FRAssistantMgrClearNotification"},
	{FRAssistantMgrSEL, FRAssistantMgrRegisterAsstUIHandlerSEL, L"FRAssistantMgrRegisterAsstUIHandler"},
	{FRAssistantMgrSEL, FRAssistantMgrUnRegisterAsstUIHandlerSEL, L"FRAssistantMgrUnRegisterAsstUIHandler"},
	{FRAssistantMgrSEL, FRAssistantMgrRegisterAssistantHandlerSEL, L"FRAssistantMgrRegisterAssistantHandler"},
	{FRAssistantMgrSEL, FRAssistantMgrUnRegisterAssistantHandlerSEL, L"FRAssistantMgrUnRegisterAssistantHandler"},
	{FRAssistantMgrSEL, FRAssistantMgrResetAssistantDlgSEL, L"FRAssistantMgrResetAssistantDlg"},
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
	{FPD3dContextSEL, FPD3dContextNewSEL, L"FPD3dContextNew"},
	{FPD3dContextSEL, FPD3dContextDestroySEL, L"FPD3dContextDestroy"},
	{FPD3dContextSEL, FPD3dContextInitDefaultEngineSEL, L"FPD3dContextInitDefaultEngine"},
	{FPD3dContextSEL, FPD3dContextInitializeWithEngineSEL, L"FPD3dContextInitializeWithEngine"},
	{FPD3dContextSEL, FPD3dContextRegisterScriptProviderSEL, L"FPD3dContextRegisterScriptProvider"},
	{FPD3dContextSEL, FPD3dContextRegisterFormatLoaderSEL, L"FPD3dContextRegisterFormatLoader"},
	{FPD3dContextSEL, FPD3dContextRegisterCompositionProviderSEL, L"FPD3dContextRegisterCompositionProvider"},
	{FPD3dContextSEL, FPD3dContextGetDocumentSEL, L"FPD3dContextGetDocument"},
	{FPD3dContextSEL, FPD3dContextGetEngineSEL, L"FPD3dContextGetEngine"},
	{FPD3dContextSEL, FPD3dContextIsPDF20SEL, L"FPD3dContextIsPDF20"},
	{FPD3dContextSEL, FPD3dContextGetFormatLoaderSEL, L"FPD3dContextGetFormatLoader"},
	{FPD3dContextSEL, FPD3dContextLoadAnnotDataSEL, L"FPD3dContextLoadAnnotData"},
	{FPD3dContextSEL, FPD3dContextRegisterEventHandlerProviderSEL, L"FPD3dContextRegisterEventHandlerProvider"},
	{FPD3dContextSEL, FPD3dContextReleaseEventHandlerProviderSEL, L"FPD3dContextReleaseEventHandlerProvider"},
	{FPD3dContextSEL, FPD3dContextEnableIsoTs32007SEL, L"FPD3dContextEnableIsoTs32007"},
	{FPD3dAnnotDataSEL, FPD3dAnnotDataAs3DArtworkSEL, L"FPD3dAnnotDataAs3DArtwork"},
	{FPD3dAnnotDataSEL, FPD3dAnnotDataAsRichMediaSEL, L"FPD3dAnnotDataAsRichMedia"},
	{FPD3dAnnotDataSEL, FPD3dAnnotDataReleaseSEL, L"FPD3dAnnotDataRelease"},
	{FPD3dAnnotData3dArtworkSEL, FPD3dAnnotData3dArtworkGet3DInstanceSEL, L"FPD3dAnnotData3dArtworkGet3DInstance"},
	{FPD3dAnnotData3dArtworkSEL, FPD3dAnnotData3dArtworkGetDefaultPresetViewSEL, L"FPD3dAnnotData3dArtworkGetDefaultPresetView"},
	{FPD3dAnnotData3dArtworkSEL, FPD3dAnnotData3dArtworkGetActivationOptionsSEL, L"FPD3dAnnotData3dArtworkGetActivationOptions"},
	{FPD3dAnnotData3dArtworkSEL, FPD3dAnnotData3dArtworkSetActivationOptionsSEL, L"FPD3dAnnotData3dArtworkSetActivationOptions"},
	{FPD3dAnnotData3dArtworkSEL, FPD3dAnnotData3dArtworkLoadActivationOptionsSEL, L"FPD3dAnnotData3dArtworkLoadActivationOptions"},
	{FPD3dAnnotData3dArtworkSEL, FPD3dAnnotData3dArtworkRetrievePresetViewListSEL, L"FPD3dAnnotData3dArtworkRetrievePresetViewList"},
	{FPD3dAnnotData3dArtworkSEL, FPD3dAnnotData3dArtworkUpdatePresetViewListSEL, L"FPD3dAnnotData3dArtworkUpdatePresetViewList"},
	{FPD3dAnnotData3dArtworkSEL, FPD3dAnnotData3dArtworkCreatePresetViewSEL, L"FPD3dAnnotData3dArtworkCreatePresetView"},
	{FPD3dAnnotData3dArtworkSEL, FPD3dAnnotData3dArtworkFindPresetViewSEL, L"FPD3dAnnotData3dArtworkFindPresetView"},
	{FPD3dAnnotData3dArtworkSEL, FPD3dAnnotData3dArtworkGetArtworkDefaultPresetViewSEL, L"FPD3dAnnotData3dArtworkGetArtworkDefaultPresetView"},
	{FPD3dSceneSEL, FPD3dSceneGetContextSEL, L"FPD3dSceneGetContext"},
	{FPD3dSceneSEL, FPD3dSceneIsSharedSceneSEL, L"FPD3dSceneIsSharedScene"},
	{FPD3dSceneSEL, FPD3dSceneGetAssetFor3DInstanceSEL, L"FPD3dSceneGetAssetFor3DInstance"},
	{FPD3dSceneSEL, FPD3dSceneGet3DInstanceByAssetSEL, L"FPD3dSceneGet3DInstanceByAsset"},
	{FPD3dSceneSEL, FPD3dSceneGetFormatSEL, L"FPD3dSceneGetFormat"},
	{FPD3deAssetSEL, FPD3deAssetGetRootNodeSEL, L"FPD3deAssetGetRootNode"},
	{FPD3deAssetSEL, FPD3deAssetGetParentNodeSEL, L"FPD3deAssetGetParentNode"},
	{FPD3deAssetSEL, FPD3deAssetGetNextSiblingNodeSEL, L"FPD3deAssetGetNextSiblingNode"},
	{FPD3deAssetSEL, FPD3deAssetGetFirstChildNodeSEL, L"FPD3deAssetGetFirstChildNode"},
	{FPD3deAssetSEL, FPD3deAssetGetNodeNameSEL, L"FPD3deAssetGetNodeName"},
	{FPD3deAssetSEL, FPD3deAssetNarrowScopeSEL, L"FPD3deAssetNarrowScope"},
	{FPD3deAssetSEL, FPD3deAssetGetNodeMetaDataCountSEL, L"FPD3deAssetGetNodeMetaDataCount"},
	{FPD3deAssetSEL, FPD3deAssetGetNodeMetaDataItemSEL, L"FPD3deAssetGetNodeMetaDataItem"},
	{FPD3deAssetSEL, FPD3deAssetComputeBoundingBoxSEL, L"FPD3deAssetComputeBoundingBox"},
	{FPD3deAssetSEL, FPD3deAssetSetShowOrientationAxesSEL, L"FPD3deAssetSetShowOrientationAxes"},
	{FPD3deAssetSEL, FPD3deAssetGetNodeUINameSEL, L"FPD3deAssetGetNodeUIName"},
	{FPD3deAssetSEL, FPD3deAssetGetSpriteNodeSpriteDataSEL, L"FPD3deAssetGetSpriteNodeSpriteData"},
	{FPD3deAssetSEL, FPD3deAssetFindNodeBySpriteDataSEL, L"FPD3deAssetFindNodeBySpriteData"},
	{FPD3deAssetSEL, FPD3deAssetGetUnitsInMillimetersSEL, L"FPD3deAssetGetUnitsInMillimeters"},
	{FPD3deAssetSEL, FPD3deAssetGetNodeTypeSEL, L"FPD3deAssetGetNodeType"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeTargetPositionLocalSEL, L"FPD3deAssetGetCameraNodeTargetPositionLocal"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeTargetSEL, L"FPD3deAssetGetCameraNodeTarget"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodePositionLocalSEL, L"FPD3deAssetGetCameraNodePositionLocal"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeRollSEL, L"FPD3deAssetGetCameraNodeRoll"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeProjectionTypeSEL, L"FPD3deAssetGetCameraNodeProjectionType"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeFovSEL, L"FPD3deAssetGetCameraNodeFov"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeNearSEL, L"FPD3deAssetGetCameraNodeNear"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeFarSEL, L"FPD3deAssetGetCameraNodeFar"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeBindingSEL, L"FPD3deAssetGetCameraNodeBinding"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeViewPlaneSizeSEL, L"FPD3deAssetGetCameraNodeViewPlaneSize"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeUpLocalSEL, L"FPD3deAssetGetCameraNodeUpLocal"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeAbsoluteBindingScaleSEL, L"FPD3deAssetGetCameraNodeAbsoluteBindingScale"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeUseAbsoluteBindingSEL, L"FPD3deAssetGetCameraNodeUseAbsoluteBinding"},
	{FPD3deAssetSEL, FPD3deAssetSetCameraNodeNearSEL, L"FPD3deAssetSetCameraNodeNear"},
	{FPD3deAssetSEL, FPD3deAssetSetCameraNodeFarSEL, L"FPD3deAssetSetCameraNodeFar"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeDirectionFromScreenSEL, L"FPD3deAssetGetCameraNodeDirectionFromScreen"},
	{FPD3deAssetSEL, FPD3deAssetGetCameraNodeScreenFromPositionSEL, L"FPD3deAssetGetCameraNodeScreenFromPosition"},
	{FPD3deAssetSEL, FPD3deAssetGetNodeWorldSpaceTransformSEL, L"FPD3deAssetGetNodeWorldSpaceTransform"},
	{FPD3deAssetSEL, FPD3deAssetGetNodeLocalSpaceTransformSEL, L"FPD3deAssetGetNodeLocalSpaceTransform"},
	{FPD3deRuntimeSEL, FPD3deRuntimeCreateRuntimeSEL, L"FPD3deRuntimeCreateRuntime"},
	{FPD3deRuntimeSEL, FPD3deRuntimeCreateRuntimeWithBackendSEL, L"FPD3deRuntimeCreateRuntimeWithBackend"},
	{FPD3deRuntimeSEL, FPD3deRuntimeLoadAssetSEL, L"FPD3deRuntimeLoadAsset"},
	{FPD3deRuntimeSEL, FPD3deRuntimeTickSEL, L"FPD3deRuntimeTick"},
	{FPD3deRuntimeSEL, FPD3deRuntimeCountInstantiatedCanvasesSEL, L"FPD3deRuntimeCountInstantiatedCanvases"},
	{FPD3deRuntimeSEL, FPD3deRuntimeQueryAvailableBackendListSEL, L"FPD3deRuntimeQueryAvailableBackendList"},
	{FPD3deRuntimeSEL, FPD3deRuntimeGetBackendFriendlyNameSEL, L"FPD3deRuntimeGetBackendFriendlyName"},
	{FPD3deRuntimeSEL, FPD3deRuntimeUpdateTextProviderSEL, L"FPD3deRuntimeUpdateTextProvider"},
	{FPD3deRuntimeSEL, FPD3deRuntimeUpdatePreference_AngleUnitDisplaySEL, L"FPD3deRuntimeUpdatePreference_AngleUnitDisplay"},
	{FPD3deRuntimeSEL, FPD3deRuntimeUpdatePreference_NodeMetadataStoragePathSEL, L"FPD3deRuntimeUpdatePreference_NodeMetadataStoragePath"},
	{FPD3deRuntimeSEL, FPD3deRuntimeUpdateProvider_I18nSEL, L"FPD3deRuntimeUpdateProvider_I18n"},
	{FPD3deRuntimeSEL, FPD3deRuntimeUpdatePreference_AntiAliasingSEL, L"FPD3deRuntimeUpdatePreference_AntiAliasing"},
	{FPD3deRuntimeSEL, FPD3deRuntimeQueryPreference_ForceDoubleSidedRenderingSEL, L"FPD3deRuntimeQueryPreference_ForceDoubleSidedRendering"},
	{FPD3deRuntimeSEL, FPD3deRuntimeUpdatePreference_NodeNameStoragePathSEL, L"FPD3deRuntimeUpdatePreference_NodeNameStoragePath"},
	{FPD3deRuntimeSEL, FPD3deRuntimeCreateAssetSEL, L"FPD3deRuntimeCreateAsset"},
	{FPD3deRuntimeSEL, FPD3deRuntimeUpdatePreference_ExtensionPrefixSEL, L"FPD3deRuntimeUpdatePreference_ExtensionPrefix"},
	{FPD3deRuntimeSEL, FPD3deRuntimeUpdatePreference_DrawBatchLimitSEL, L"FPD3deRuntimeUpdatePreference_DrawBatchLimit"},
	{FPD3deRuntimeSEL, FPD3deRuntimeCreateEnvironmentSEL, L"FPD3deRuntimeCreateEnvironment"},
	{FPD3deCanvasSEL, FPD3deCanvasGetNativeWindowSEL, L"FPD3deCanvasGetNativeWindow"},
	{FPD3deCanvasSEL, FPD3deCanvasInstantiateSEL, L"FPD3deCanvasInstantiate"},
	{FPD3deCanvasSEL, FPD3deCanvasInstantiateAndLiveSEL, L"FPD3deCanvasInstantiateAndLive"},
	{FPD3deCanvasSEL, FPD3deCanvasUninstantiateSEL, L"FPD3deCanvasUninstantiate"},
	{FPD3deCanvasSEL, FPD3deCanvasGetStateSEL, L"FPD3deCanvasGetState"},
	{FPD3deCanvasSEL, FPD3deCanvasAcquireCurrentViewSEL, L"FPD3deCanvasAcquireCurrentView"},
	{FPD3deCanvasSEL, FPD3deCanvasReleaseCurrentViewSEL, L"FPD3deCanvasReleaseCurrentView"},
	{FPD3deCanvasSEL, FPD3deCanvasGetPrimaryAssetSEL, L"FPD3deCanvasGetPrimaryAsset"},
	{FPD3deCanvasSEL, FPD3deCanvasSetControllerToolSEL, L"FPD3deCanvasSetControllerTool"},
	{FPD3deCanvasSEL, FPD3deCanvasRelocateInPlaceSEL, L"FPD3deCanvasRelocateInPlace"},
	{FPD3deCanvasSEL, FPD3deCanvasSetNotificationCallback_ContextMenuSEL, L"FPD3deCanvasSetNotificationCallback_ContextMenu"},
	{FPD3deCanvasSEL, FPD3deCanvasSetNotificationCallback_PointerFocusSEL, L"FPD3deCanvasSetNotificationCallback_PointerFocus"},
	{FPD3deCanvasSEL, FPD3deCanvasHaveAnimationSEL, L"FPD3deCanvasHaveAnimation"},
	{FPD3deCanvasSEL, FPD3deCanvasIsAnimationPlayingSEL, L"FPD3deCanvasIsAnimationPlaying"},
	{FPD3deCanvasSEL, FPD3deCanvasToggleAnimationSEL, L"FPD3deCanvasToggleAnimation"},
	{FPD3deCanvasSEL, FPD3deCanvasSeekAnimationProgressSEL, L"FPD3deCanvasSeekAnimationProgress"},
	{FPD3deCanvasSEL, FPD3deCanvasGetAnimationProgressSEL, L"FPD3deCanvasGetAnimationProgress"},
	{FPD3deCanvasSEL, FPD3deCanvasGetChosenNodeSEL, L"FPD3deCanvasGetChosenNode"},
	{FPD3deCanvasSEL, FPD3deCanvasSetChosenNodeSEL, L"FPD3deCanvasSetChosenNode"},
	{FPD3deCanvasSEL, FPD3deCanvasSetNotificationCallback_ClaimMeasureSEL, L"FPD3deCanvasSetNotificationCallback_ClaimMeasure"},
	{FPD3deCanvasSEL, FPD3deCanvasSnapshotSEL, L"FPD3deCanvasSnapshot"},
	{FPD3deCanvasSEL, FPD3deCanvasSetNotificationCallback_RequestUpdateBackgroundSEL, L"FPD3deCanvasSetNotificationCallback_RequestUpdateBackground"},
	{FPD3deCanvasSEL, FPD3deCanvasSetNotificationCallback_RequestUpdateForegroundSEL, L"FPD3deCanvasSetNotificationCallback_RequestUpdateForeground"},
	{FPD3deCanvasSEL, FPD3deCanvasRequestUpdateBackgroundSEL, L"FPD3deCanvasRequestUpdateBackground"},
	{FPD3deCanvasSEL, FPD3deCanvasRequestUpdateForegroundSEL, L"FPD3deCanvasRequestUpdateForeground"},
	{FPD3deCanvasSEL, FPD3deCanvasGetControllerToolSEL, L"FPD3deCanvasGetControllerTool"},
	{FPD3deCanvasSEL, FPD3deCanvasResetViewRotationSEL, L"FPD3deCanvasResetViewRotation"},
	{FPD3deCanvasSEL, FPD3deCanvasGetCameraNodeSEL, L"FPD3deCanvasGetCameraNode"},
	{FPD3deCanvasSEL, FPD3deCanvasSetCameraNodeSEL, L"FPD3deCanvasSetCameraNode"},
	{FPD3deViewSEL, FPD3deViewGetAssetSEL, L"FPD3deViewGetAsset"},
	{FPD3deViewSEL, FPD3deViewGetNameSEL, L"FPD3deViewGetName"},
	{FPD3deViewSEL, FPD3deViewGetDisplayNameSEL, L"FPD3deViewGetDisplayName"},
	{FPD3deViewSEL, FPD3deViewGetCenterOfOrbitSEL, L"FPD3deViewGetCenterOfOrbit"},
	{FPD3deViewSEL, FPD3deViewGetProjectionSEL, L"FPD3deViewGetProjection"},
	{FPD3deViewSEL, FPD3deViewGetBackgroundSEL, L"FPD3deViewGetBackground"},
	{FPD3deViewSEL, FPD3deViewGetRenderModeSEL, L"FPD3deViewGetRenderMode"},
	{FPD3deViewSEL, FPD3deViewGetLightingSchemeSEL, L"FPD3deViewGetLightingScheme"},
	{FPD3deViewSEL, FPD3deViewSetCameraToWorldMatrixWithNodeSEL, L"FPD3deViewSetCameraToWorldMatrixWithNode"},
	{FPD3deViewSEL, FPD3deViewSetCenterOfOrbitSEL, L"FPD3deViewSetCenterOfOrbit"},
	{FPD3deViewSEL, FPD3deViewSetProjectionSEL, L"FPD3deViewSetProjection"},
	{FPD3deViewSEL, FPD3deViewSetBackgroundSEL, L"FPD3deViewSetBackground"},
	{FPD3deViewSEL, FPD3deViewSetRenderModeSEL, L"FPD3deViewSetRenderMode"},
	{FPD3deViewSEL, FPD3deViewSetLightingSchemeSEL, L"FPD3deViewSetLightingScheme"},
	{FPD3deViewSEL, FPD3deViewImportViewConfigSEL, L"FPD3deViewImportViewConfig"},
	{FPD3deViewSEL, FPD3deViewSetNameAndDisplayNameSEL, L"FPD3deViewSetNameAndDisplayName"},
	{FPD3deViewSEL, FPD3deViewSetCrossSectionsSEL, L"FPD3deViewSetCrossSections"},
	{FPD3deViewSEL, FPD3deViewClearViewConfigSEL, L"FPD3deViewClearViewConfig"},
	{FPD3deViewSEL, FPD3deViewGetCrossSectionsSEL, L"FPD3deViewGetCrossSections"},
	{FPD3deViewSEL, FPD3deViewClearAndImportViewConfigSEL, L"FPD3deViewClearAndImportViewConfig"},
	{FPD3deViewSEL, FPD3deViewGetMeasurementsSEL, L"FPD3deViewGetMeasurements"},
	{FPD3deViewSEL, FPD3deViewSetMeasurementsSEL, L"FPD3deViewSetMeasurements"},
	{FPD3deViewSEL, FPD3deViewSetTrackingViewSEL, L"FPD3deViewSetTrackingView"},
	{FPD3deViewSEL, FPD3deViewF3DViewGetDictSEL, L"FPD3deViewF3DViewGetDict"},
	{FPD3deViewSEL, FPD3deViewGetCameraParamSEL, L"FPD3deViewGetCameraParam"},
	{FPD3deViewRenderModeSEL, FPD3deViewRenderModeSwitchKindSEL, L"FPD3deViewRenderModeSwitchKind"},
	{FPD3deViewRenderModeSEL, FPD3deViewRenderModeCreateSEL, L"FPD3deViewRenderModeCreate"},
	{FPD3deViewRenderModeSEL, FPD3deViewRenderModeReleaseSEL, L"FPD3deViewRenderModeRelease"},
	{FPD3deViewRenderModeSEL, FPD3deViewRenderModeQueryModeTypeSEL, L"FPD3deViewRenderModeQueryModeType"},
	{FPD3deViewLightingSchemeSEL, FPD3deViewLightingSchemeCreateSEL, L"FPD3deViewLightingSchemeCreate"},
	{FPD3deViewLightingSchemeSEL, FPD3deViewLightingSchemeDestroySEL, L"FPD3deViewLightingSchemeDestroy"},
	{FPD3deViewLightingSchemeSEL, FPD3deViewLightingSchemeQuerySchemeTypeSEL, L"FPD3deViewLightingSchemeQuerySchemeType"},
	{FPD3deViewLightingSchemeSEL, FPD3deViewLightingSchemeSwitchSchemeTypeSEL, L"FPD3deViewLightingSchemeSwitchSchemeType"},
	{FPD3deViewLightingSchemeSEL, FPD3deViewLightingSchemeQueryArtworkSchemeExistSEL, L"FPD3deViewLightingSchemeQueryArtworkSchemeExist"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolGetRotateToolSEL, L"FPD3deCanvasControllerToolGetRotateTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolGetSpinToolSEL, L"FPD3deCanvasControllerToolGetSpinTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolGetPanToolSEL, L"FPD3deCanvasControllerToolGetPanTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolGetZoomToolSEL, L"FPD3deCanvasControllerToolGetZoomTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolGetWalkToolSEL, L"FPD3deCanvasControllerToolGetWalkTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolGetFlyToolSEL, L"FPD3deCanvasControllerToolGetFlyTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolGetSimpleControllerToolSEL, L"FPD3deCanvasControllerToolGetSimpleControllerTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolCreateCommentControllerToolSEL, L"FPD3deCanvasControllerToolCreateCommentControllerTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolReleaseCommentControllerToolSEL, L"FPD3deCanvasControllerToolReleaseCommentControllerTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolCreateMeasureControllerToolSEL, L"FPD3deCanvasControllerToolCreateMeasureControllerTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolReleaseMeasureControllerToolSEL, L"FPD3deCanvasControllerToolReleaseMeasureControllerTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolSetMeasureControllerTooMeasureTypeSEL, L"FPD3deCanvasControllerToolSetMeasureControllerTooMeasureType"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolSetMeasureScaleSEL, L"FPD3deCanvasControllerToolSetMeasureScale"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolCreate3deCanvasControllerToolSEL, L"FPD3deCanvasControllerToolCreate3deCanvasControllerTool"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolDestroySEL, L"FPD3deCanvasControllerToolDestroy"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolSetTagSEL, L"FPD3deCanvasControllerToolSetTag"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolGetTagSEL, L"FPD3deCanvasControllerToolGetTag"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolSetUserDataSEL, L"FPD3deCanvasControllerToolSetUserData"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolGetUserDataSEL, L"FPD3deCanvasControllerToolGetUserData"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolSetMeasureSnapTypeSEL, L"FPD3deCanvasControllerToolSetMeasureSnapType"},
	{FPD3deCanvasControllerToolSEL, FPD3deCanvasControllerToolSetCursorChangeHookSEL, L"FPD3deCanvasControllerToolSetCursorChangeHook"},
	{FPD3dVendorSEL, FPD3dVendorCreateHandlerSEL, L"FPD3dVendorCreateHandler"},
	{FPD3dVendorSEL, FPD3dVendorReleaseHandlerSEL, L"FPD3dVendorReleaseHandler"},
	{FPD3dVendorSEL, FPD3dVendorSetPDFModuleMgrIfNecessarySEL, L"FPD3dVendorSetPDFModuleMgrIfNecessary"},
	{FPD3dVendorSEL, FPD3dVendorSetTempFileCallbackSEL, L"FPD3dVendorSetTempFileCallback"},
	{FPD3dVendorSEL, FPD3dVendorU3DLoaderSEL, L"FPD3dVendorU3DLoader"},
	{FPD3dVendorSEL, FPD3dVendorPRCLoaderSEL, L"FPD3dVendorPRCLoader"},
	{FPD3dVendorSEL, FPD3dVendorGetNodeMetadataStorageKeySEL, L"FPD3dVendorGetNodeMetadataStorageKey"},
	{FPD3dVendorSEL, FPD3dVendorModelLoaderSEL, L"FPD3dVendorModelLoader"},
	{FPD3dVendorSEL, FPD3dVendorDorPRCLoaderSEL, L"FPD3dVendorDorPRCLoader"},
	{FPD3dVendorSEL, FPD3dVendorGetNodeNameStorageKeySEL, L"FPD3dVendorGetNodeNameStorageKey"},
	{FPD3dVendorSEL, FPD3dVendorSetTempFileGenerationRuleSEL, L"FPD3dVendorSetTempFileGenerationRule"},
	{FPD3deViewBackgroundSEL, FPD3deViewBackgroundCreateSEL, L"FPD3deViewBackgroundCreate"},
	{FPD3deViewBackgroundSEL, FPD3deViewBackgroundReleaseSEL, L"FPD3deViewBackgroundRelease"},
	{FPD3deViewBackgroundSEL, FPD3deViewBackgroundSetBackgroundColorSEL, L"FPD3deViewBackgroundSetBackgroundColor"},
	{FPD3deViewBackgroundSEL, FPD3deViewBackgroundQueryBackgroundColorSEL, L"FPD3deViewBackgroundQueryBackgroundColor"},
	{FPD3deViewBackgroundSEL, FPD3deViewBackgroundDefaultBackgroundColorSEL, L"FPD3deViewBackgroundDefaultBackgroundColor"},
	{FPD3deViewBackgroundSEL, FPD3deViewBackgroundQueryEntireAnnotationSEL, L"FPD3deViewBackgroundQueryEntireAnnotation"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamQueryProjectionModeSEL, L"FPD3deViewCameraParamQueryProjectionMode"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamSwitchProjectionModeSEL, L"FPD3deViewCameraParamSwitchProjectionMode"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamImportCameraConfig1SEL, L"FPD3deViewCameraParamImportCameraConfig1"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamImportCameraConfig2SEL, L"FPD3deViewCameraParamImportCameraConfig2"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamExportCameraConfigSEL, L"FPD3deViewCameraParamExportCameraConfig"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamFitToVisibleSEL, L"FPD3deViewCameraParamFitToVisible"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamZoomToPartSEL, L"FPD3deViewCameraParamZoomToPart"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamIsolateNodeSEL, L"FPD3deViewCameraParamIsolateNode"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamIsolateParentNodeSEL, L"FPD3deViewCameraParamIsolateParentNode"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamGet3DMatrixSEL, L"FPD3deViewCameraParamGet3DMatrix"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamGetbUseU3DPathSEL, L"FPD3deViewCameraParamGetbUseU3DPath"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamGetU3DPathSEL, L"FPD3deViewCameraParamGetU3DPath"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamGetCenterOfOrbitSEL, L"FPD3deViewCameraParamGetCenterOfOrbit"},
	{FPD3deViewCameraParamSEL, FPD3deViewCameraParamGetProjectFOSSEL, L"FPD3deViewCameraParamGetProjectFOS"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionToggleCrossSectionSEL, L"FPD3deViewCrossSectionToggleCrossSection"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionImportCrossSectionConfig1SEL, L"FPD3deViewCrossSectionImportCrossSectionConfig1"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionExportCrossSectionConfig1SEL, L"FPD3deViewCrossSectionExportCrossSectionConfig1"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionGetCenterPosSEL, L"FPD3deViewCrossSectionGetCenterPos"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionSetCenterPosSEL, L"FPD3deViewCrossSectionSetCenterPos"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionGetOrientationSEL, L"FPD3deViewCrossSectionGetOrientation"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionSetOrientationSEL, L"FPD3deViewCrossSectionSetOrientation"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionGetPlaneSEL, L"FPD3deViewCrossSectionGetPlane"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionSetPlaneSEL, L"FPD3deViewCrossSectionSetPlane"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionGetIntersectionSEL, L"FPD3deViewCrossSectionGetIntersection"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionSetIntersectionSEL, L"FPD3deViewCrossSectionSetIntersection"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionGetShowTransparentSEL, L"FPD3deViewCrossSectionGetShowTransparent"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionSetShowTransparentSEL, L"FPD3deViewCrossSectionSetShowTransparent"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionGetSectionCappingSEL, L"FPD3deViewCrossSectionGetSectionCapping"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionSetSectionCappingSEL, L"FPD3deViewCrossSectionSetSectionCapping"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionGetIgnoreChosenNodeSEL, L"FPD3deViewCrossSectionGetIgnoreChosenNode"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionSetIgnoreChosenNodeSEL, L"FPD3deViewCrossSectionSetIgnoreChosenNode"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionImportCrossSectionConfig2SEL, L"FPD3deViewCrossSectionImportCrossSectionConfig2"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionExportCrossSectionConfig2SEL, L"FPD3deViewCrossSectionExportCrossSectionConfig2"},
	{FPD3deViewCrossSectionSEL, FPD3deViewCrossSectionQueryCrossSectionExistSEL, L"FPD3deViewCrossSectionQueryCrossSectionExist"},
	{FPD3deViewNodeSEL, FPD3deViewNodeStartModifyNodeSEL, L"FPD3deViewNodeStartModifyNode"},
	{FPD3deViewNodeSEL, FPD3deViewNodeFinishModifyNodeSEL, L"FPD3deViewNodeFinishModifyNode"},
	{FPD3deViewNodeSEL, FPD3deViewNodeStartQueryNodeSEL, L"FPD3deViewNodeStartQueryNode"},
	{FPD3deViewNodeSEL, FPD3deViewNodeFinishQueryNodeSEL, L"FPD3deViewNodeFinishQueryNode"},
	{FPD3deViewNodeSEL, FPD3deViewNodeGetNameSEL, L"FPD3deViewNodeGetName"},
	{FPD3deViewNodeSEL, FPD3deViewNodeSetNameSEL, L"FPD3deViewNodeSetName"},
	{FPD3deViewNodeSEL, FPD3deViewNodeGetVisibilitySEL, L"FPD3deViewNodeGetVisibility"},
	{FPD3deViewNodeSEL, FPD3deViewNodeSetVisibilitySEL, L"FPD3deViewNodeSetVisibility"},
	{FPD3deViewNodeSEL, FPD3deViewNodeGetOpacitySEL, L"FPD3deViewNodeGetOpacity"},
	{FPD3deViewNodeSEL, FPD3deViewNodeSetOpacitySEL, L"FPD3deViewNodeSetOpacity"},
	{FPD3deViewNodeSEL, FPD3deViewNodeGetMatrixSEL, L"FPD3deViewNodeGetMatrix"},
	{FPD3deViewNodeSEL, FPD3deViewNodeSetMatrixSEL, L"FPD3deViewNodeSetMatrix"},
	{FPD3deViewNodeSEL, FPD3deViewNodeGetRenderModeSEL, L"FPD3deViewNodeGetRenderMode"},
	{FPD3deViewNodeSEL, FPD3deViewNodeSetRenderModeSEL, L"FPD3deViewNodeSetRenderMode"},
	{FPD3deViewNodeSEL, FPD3deViewNodeQueryNodeVisibilitySEL, L"FPD3deViewNodeQueryNodeVisibility"},
	{FPD3deMeasureSEL, FPD3deMeasureGetTypeSEL, L"FPD3deMeasureGetType"},
	{FPD3deMeasureSEL, FPD3deMeasureGetViewSEL, L"FPD3deMeasureGetView"},
	{FPD3deMeasureSEL, FPD3deMeasureGetNameSEL, L"FPD3deMeasureGetName"},
	{FPD3deMeasureSEL, FPD3deMeasureGetPlaneSEL, L"FPD3deMeasureGetPlane"},
	{FPD3deMeasureSEL, FPD3deMeasureGetAnchorPointsSEL, L"FPD3deMeasureGetAnchorPoints"},
	{FPD3deMeasureSEL, FPD3deMeasureReleaseFS3DeVectorArraySEL, L"FPD3deMeasureReleaseFS3DeVectorArray"},
	{FPD3deMeasureSEL, FPD3deMeasureGetAnchorNamesSEL, L"FPD3deMeasureGetAnchorNames"},
	{FPD3deMeasureSEL, FPD3deMeasureGetExtraAnchorPointsSEL, L"FPD3deMeasureGetExtraAnchorPoints"},
	{FPD3deMeasureSEL, FPD3deMeasureGetDirVectorsSEL, L"FPD3deMeasureGetDirVectors"},
	{FPD3deMeasureSEL, FPD3deMeasureGetTextPosSEL, L"FPD3deMeasureGetTextPos"},
	{FPD3deMeasureSEL, FPD3deMeasureGetTextXDirSEL, L"FPD3deMeasureGetTextXDir"},
	{FPD3deMeasureSEL, FPD3deMeasureGetTextYDirSEL, L"FPD3deMeasureGetTextYDir"},
	{FPD3deMeasureSEL, FPD3deMeasureGetTextBoxSizeSEL, L"FPD3deMeasureGetTextBoxSize"},
	{FPD3deMeasureSEL, FPD3deMeasureGetExtensionLineLengthSEL, L"FPD3deMeasureGetExtensionLineLength"},
	{FPD3deMeasureSEL, FPD3deMeasureGetTextSizeSEL, L"FPD3deMeasureGetTextSize"},
	{FPD3deMeasureSEL, FPD3deMeasureGetColorSEL, L"FPD3deMeasureGetColor"},
	{FPD3deMeasureSEL, FPD3deMeasureGetValueSEL, L"FPD3deMeasureGetValue"},
	{FPD3deMeasureSEL, FPD3deMeasureGetUnitsSEL, L"FPD3deMeasureGetUnits"},
	{FPD3deMeasureSEL, FPD3deMeasureGetPrecisionSEL, L"FPD3deMeasureGetPrecision"},
	{FPD3deMeasureSEL, FPD3deMeasureGetUserTextSEL, L"FPD3deMeasureGetUserText"},
	{FPD3deMeasureSEL, FPD3deMeasureGetAngleTypeSEL, L"FPD3deMeasureGetAngleType"},
	{FPD3deMeasureSEL, FPD3deMeasureGetShowCircleSEL, L"FPD3deMeasureGetShowCircle"},
	{FPD3deMeasureSEL, FPD3deMeasureGetRadialTypeSEL, L"FPD3deMeasureGetRadialType"},
	{FPD3deMeasureSEL, FPD3deMeasureSetNameSEL, L"FPD3deMeasureSetName"},
	{FPD3deMeasureSEL, FPD3deMeasureSetTextPosSEL, L"FPD3deMeasureSetTextPos"},
	{FPD3deMeasureSEL, FPD3deMeasureSetAnchorPointsAndNamesSEL, L"FPD3deMeasureSetAnchorPointsAndNames"},
	{FPD3deMeasureSEL, FPD3deMeasureSetPlaneSEL, L"FPD3deMeasureSetPlane"},
	{FPD3deMeasureSEL, FPD3deMeasureSetTextXDirSEL, L"FPD3deMeasureSetTextXDir"},
	{FPD3deMeasureSEL, FPD3deMeasureSetTextYDirSEL, L"FPD3deMeasureSetTextYDir"},
	{FPD3deMeasureSEL, FPD3deMeasureSetValueSEL, L"FPD3deMeasureSetValue"},
	{FPD3deMeasureSEL, FPD3deMeasureSetColorSEL, L"FPD3deMeasureSetColor"},
	{FPD3deMeasureSEL, FPD3deMeasureSetAngularShowArcSEL, L"FPD3deMeasureSetAngularShowArc"},
	{FPD3deMeasureSEL, FPD3deMeasureSetDirVectorsSEL, L"FPD3deMeasureSetDirVectors"},
	{FPD3deMeasureSEL, FPD3deMeasureSetUserTextSEL, L"FPD3deMeasureSetUserText"},
	{FPD3deMeasureSEL, FPD3deMeasureSetShowSEL, L"FPD3deMeasureSetShow"},
	{FPD3deMeasureSEL, FPD3deMeasureSetTextBoxSizeSEL, L"FPD3deMeasureSetTextBoxSize"},
	{FPD3deMeasureSEL, FPD3deMeasureSetUnitsSEL, L"FPD3deMeasureSetUnits"},
	{FPD3deMeasureSEL, FPD3deMeasureControllerGetCurrentMeasureSEL, L"FPD3deMeasureControllerGetCurrentMeasure"},
	{FPD3deMeasureSEL, FPD3deMeasureGetCurrentCollectedPointCountSEL, L"FPD3deMeasureGetCurrentCollectedPointCount"},
	{FPD3deMeasureSEL, FPD3deMeasureSetMeasureValueChangeCallbackSEL, L"FPD3deMeasureSetMeasureValueChangeCallback"},
	{FPD3deMeasureSEL, FPD3deMeasureMeasure_GetDictSEL, L"FPD3deMeasureMeasure_GetDict"},
	{FPD3deViewMiscOptionsSEL, FPD3deViewMiscOptionsSetHighlightColorSEL, L"FPD3deViewMiscOptionsSetHighlightColor"},
	{FPD3deViewMiscOptionsSEL, FPD3deViewMiscOptionsSetBoundingBoxVisibleSEL, L"FPD3deViewMiscOptionsSetBoundingBoxVisible"},
	{FPD3deViewMiscOptionsSEL, FPD3deViewMiscOptionsSetBoundingBoxColorSEL, L"FPD3deViewMiscOptionsSetBoundingBoxColor"},
	{FPD3deViewMiscOptionsSEL, FPD3deViewMiscOptionsSetShowGridSEL, L"FPD3deViewMiscOptionsSetShowGrid"},
	{FPD3deViewMiscOptionsSEL, FPD3deViewMiscOptionsGetShowGridSEL, L"FPD3deViewMiscOptionsGetShowGrid"},
	{FPD3deViewMiscOptionsSEL, FPD3deViewMiscOptionsSetGridModeSEL, L"FPD3deViewMiscOptionsSetGridMode"},
	{FPD3deViewMiscOptionsSEL, FPD3deViewMiscOptionsGetGridModeSEL, L"FPD3deViewMiscOptionsGetGridMode"},
	{FPD3deViewMiscOptionsSEL, FPD3deViewMiscOptionsSetGridSizeSEL, L"FPD3deViewMiscOptionsSetGridSize"},
	{FPD3deViewMiscOptionsSEL, FPD3deViewMiscOptionsGetGridSizeSEL, L"FPD3deViewMiscOptionsGetGridSize"},
	{FPD3deTextProviderSEL, FPD3deTextProviderCreateSEL, L"FPD3deTextProviderCreate"},
	{FPD3deTextProviderSEL, FPD3deTextProviderReleaseSEL, L"FPD3deTextProviderRelease"},
	{FPD3deTextProviderSEL, FPD3deTextProviderSetTextScalingRatioSEL, L"FPD3deTextProviderSetTextScalingRatio"},
	{FPD3deTextProviderSEL, FPD3deTextProviderSetSystemHandlerSEL, L"FPD3deTextProviderSetSystemHandler"},
	{FPDScriptHostHostProviderSEL, FPDScriptHostHostProviderNewSEL, L"FPDScriptHostHostProviderNew"},
	{FPDScriptHostHostProviderSEL, FPDScriptHostHostProviderDestroySEL, L"FPDScriptHostHostProviderDestroy"},
	{FPDScript3DEngineSEL, FPDScript3DEngineNewSEL, L"FPDScript3DEngineNew"},
	{FPDScript3DEngineSEL, FPDScript3DEngineDestroySEL, L"FPDScript3DEngineDestroy"},
	{FPDScript3DEngineSEL, FPDScript3DEngineGet3DScriptContextSEL, L"FPDScript3DEngineGet3DScriptContext"},
	{FPDScript3DEngineSEL, FPDScript3DEngineRegisterHostProviderSEL, L"FPDScript3DEngineRegisterHostProvider"},
	{FPDScript3DEngineSEL, FPDScript3DEngineGet3DScriptProviderSEL, L"FPDScript3DEngineGet3DScriptProvider"},
	{FPD3DI18NProviderHandlerSEL, FPD3DI18NProviderHandlerNewSEL, L"FPD3DI18NProviderHandlerNew"},
	{FPD3DI18NProviderHandlerSEL, FPD3DI18NProviderHandlerDestroySEL, L"FPD3DI18NProviderHandlerDestroy"},
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V13----------
// In file fs_basicImpl.h
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
	{FRIReaderSEL, FRIReaderGetInputMethodSEL, L"FRIReaderGetInputMethod"},
	{FRIFXSEL, FRIFXOnWindowProcSEL, L"FRIFXOnWindowProc"},
	{FRIFXSEL, FRIFXRegisterInputHandlerSEL, L"FRIFXRegisterInputHandler"},
	{FRIFXSEL, FRIFXUnRegisterInputHandlerSEL, L"FRIFXUnRegisterInputHandler"},
	{FRIFXSEL, FRIFXEnterInputStatusSEL, L"FRIFXEnterInputStatus"},
	{FRIFXSEL, FRIFXExitInputStatusSEL, L"FRIFXExitInputStatus"},
	{FRInputMethodHandlerSEL, FRInputMethodHandlerNewSEL, L"FRInputMethodHandlerNew"},
	{FRInputMethodHandlerSEL, FRInputMethodHandlerDestroySEL, L"FRInputMethodHandlerDestroy"},
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
	{FRReaderInterformSEL, FRReaderInterformGetInterFormSEL, L"FRReaderInterformGetInterForm"},
	{FRReaderInterformSEL, FRReaderInterformLoadImageFromFileSEL, L"FRReaderInterformLoadImageFromFile"},
	{FRReaderInterformSEL, FRReaderInterformResetFieldAppearanceSEL, L"FRReaderInterformResetFieldAppearance"},
	{FRReaderInterformSEL, FRReaderInterformOnCalculateSEL, L"FRReaderInterformOnCalculate"},
	{FRReaderInterformSEL, FRReaderInterformOnCalculate2SEL, L"FRReaderInterformOnCalculate2"},
	{FRReaderInterformSEL, FRReaderInterformIsFormFieldInPageSEL, L"FRReaderInterformIsFormFieldInPage"},
	{FRReaderInterformSEL, FRReaderInterformGetBFinterformSEL, L"FRReaderInterformGetBFinterform"},
	{FRReaderInterformSEL, FRReaderInterformIsHighLightSEL, L"FRReaderInterformIsHighLight"},
	{FRReaderInterformSEL, FRReaderInterformGetBarCodeRenderBitmapSEL, L"FRReaderInterformGetBarCodeRenderBitmap"},
	{FRReaderInterformSEL, FRReaderInterformDeleteInterFormSEL, L"FRReaderInterformDeleteInterForm"},
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V14----------
// In file fs_basicImpl.h
	{FSReaderDateTimeSEL, FSReaderDateTimeCreateDateTimeDefaultSEL, L"FSReaderDateTimeCreateDateTimeDefault"},
	{FSReaderDateTimeSEL, FSReaderDateTimeCreateDateTimeStrSEL, L"FSReaderDateTimeCreateDateTimeStr"},
	{FSReaderDateTimeSEL, FSReaderDateTimeCreateDateTimeSEL, L"FSReaderDateTimeCreateDateTime"},
	{FSReaderDateTimeSEL, FSReaderDateTimeCreateDateTimeSysTimeSEL, L"FSReaderDateTimeCreateDateTimeSysTime"},
	{FSReaderDateTimeSEL, FSReaderDateTimeFromPDFDateTimeStringSEL, L"FSReaderDateTimeFromPDFDateTimeString"},
	{FSReaderDateTimeSEL, FSReaderDateTimeToCommonDateTimeStringSEL, L"FSReaderDateTimeToCommonDateTimeString"},
	{FSReaderDateTimeSEL, FSReaderDateTimeToPDFDateTimeStringSEL, L"FSReaderDateTimeToPDFDateTimeString"},
	{FSReaderDateTimeSEL, FSReaderDateTimeToSystemTimeSEL, L"FSReaderDateTimeToSystemTime"},
	{FSReaderDateTimeSEL, FSReaderDateTimeToGMTSEL, L"FSReaderDateTimeToGMT"},
	{FSReaderDateTimeSEL, FSReaderDateTimeToLocalTimeSEL, L"FSReaderDateTimeToLocalTime"},
	{FSReaderDateTimeSEL, FSReaderDateTimeAddDaysSEL, L"FSReaderDateTimeAddDays"},
	{FSReaderDateTimeSEL, FSReaderDateTimeAddSecondsSEL, L"FSReaderDateTimeAddSeconds"},
	{FSReaderDateTimeSEL, FSReaderDateTimeIsEmptySEL, L"FSReaderDateTimeIsEmpty"},
	{FSReaderDateTimeSEL, FSReaderDateTimeResetDateTimeSEL, L"FSReaderDateTimeResetDateTime"},
	{FSReaderDateTimeSEL, FSReaderDateTimeIsLeapYearSEL, L"FSReaderDateTimeIsLeapYear"},
	{FSReaderDateTimeSEL, FSReaderDateTimeIsValidSEL, L"FSReaderDateTimeIsValid"},
	{FSReaderDateTimeSEL, FSReaderDateTimeFillDateTimeSEL, L"FSReaderDateTimeFillDateTime"},
	{FSReaderDateTimeSEL, FSReaderDateTimeFillSystemtimeSEL, L"FSReaderDateTimeFillSystemtime"},
	{FSReaderDateTimeSEL, FSReaderDateTimeIsEqualSEL, L"FSReaderDateTimeIsEqual"},
	{FSReaderDateTimeSEL, FSReaderDateTimeIsUnEqualSEL, L"FSReaderDateTimeIsUnEqual"},
	{FSReaderDateTimeSEL, FSReaderDateTimeIsGreaterSEL, L"FSReaderDateTimeIsGreater"},
	{FSReaderDateTimeSEL, FSReaderDateTimeIsEqualGreaterSEL, L"FSReaderDateTimeIsEqualGreater"},
	{FSReaderDateTimeSEL, FSReaderDateTimeIsLessSEL, L"FSReaderDateTimeIsLess"},
	{FSReaderDateTimeSEL, FSReaderDateTimeIsEqualLessSEL, L"FSReaderDateTimeIsEqualLess"},
	{FSReaderDateTimeSEL, FSReaderDateTimeDestroySEL, L"FSReaderDateTimeDestroy"},
	{FSMonoscaleSEL, FSMonoscaleNewSEL, L"FSMonoscaleNew"},
	{FSMonoscaleSEL, FSMonoscaleDestroySEL, L"FSMonoscaleDestroy"},
	{FSMonoscaleSEL, FSMonoscaleLoadDIBSourceSEL, L"FSMonoscaleLoadDIBSource"},
	{FSMonoscaleSEL, FSMonoscaleGetMonoscaleBitmapSEL, L"FSMonoscaleGetMonoscaleBitmap"},
	{FSFloatArraySEL, FSFloatArrayNewSEL, L"FSFloatArrayNew"},
	{FSFloatArraySEL, FSFloatArrayDestroySEL, L"FSFloatArrayDestroy"},
	{FSFloatArraySEL, FSFloatArrayGetSizeSEL, L"FSFloatArrayGetSize"},
	{FSFloatArraySEL, FSFloatArrayGetUpperBoundSEL, L"FSFloatArrayGetUpperBound"},
	{FSFloatArraySEL, FSFloatArraySetSizeSEL, L"FSFloatArraySetSize"},
	{FSFloatArraySEL, FSFloatArrayRemoveAllSEL, L"FSFloatArrayRemoveAll"},
	{FSFloatArraySEL, FSFloatArrayGetAtSEL, L"FSFloatArrayGetAt"},
	{FSFloatArraySEL, FSFloatArraySetAtSEL, L"FSFloatArraySetAt"},
	{FSFloatArraySEL, FSFloatArraySetAtGrowSEL, L"FSFloatArraySetAtGrow"},
	{FSFloatArraySEL, FSFloatArrayAddSEL, L"FSFloatArrayAdd"},
	{FSFloatArraySEL, FSFloatArrayAppendSEL, L"FSFloatArrayAppend"},
	{FSFloatArraySEL, FSFloatArrayCopySEL, L"FSFloatArrayCopy"},
	{FSFloatArraySEL, FSFloatArrayGetDataPtrSEL, L"FSFloatArrayGetDataPtr"},
	{FSFloatArraySEL, FSFloatArrayInsertAtSEL, L"FSFloatArrayInsertAt"},
	{FSFloatArraySEL, FSFloatArrayRemoveAtSEL, L"FSFloatArrayRemoveAt"},
	{FSFloatArraySEL, FSFloatArrayInsertNewArrayAtSEL, L"FSFloatArrayInsertNewArrayAt"},
	{FSFloatArraySEL, FSFloatArrayFindSEL, L"FSFloatArrayFind"},
	{FSInt32ArraySEL, FSInt32ArrayNewSEL, L"FSInt32ArrayNew"},
	{FSInt32ArraySEL, FSInt32ArrayDestroySEL, L"FSInt32ArrayDestroy"},
	{FSInt32ArraySEL, FSInt32ArrayGetSizeSEL, L"FSInt32ArrayGetSize"},
	{FSInt32ArraySEL, FSInt32ArrayGetUpperBoundSEL, L"FSInt32ArrayGetUpperBound"},
	{FSInt32ArraySEL, FSInt32ArraySetSizeSEL, L"FSInt32ArraySetSize"},
	{FSInt32ArraySEL, FSInt32ArrayRemoveAllSEL, L"FSInt32ArrayRemoveAll"},
	{FSInt32ArraySEL, FSInt32ArrayGetAtSEL, L"FSInt32ArrayGetAt"},
	{FSInt32ArraySEL, FSInt32ArraySetAtSEL, L"FSInt32ArraySetAt"},
	{FSInt32ArraySEL, FSInt32ArraySetAtGrowSEL, L"FSInt32ArraySetAtGrow"},
	{FSInt32ArraySEL, FSInt32ArrayAddSEL, L"FSInt32ArrayAdd"},
	{FSInt32ArraySEL, FSInt32ArrayAppendSEL, L"FSInt32ArrayAppend"},
	{FSInt32ArraySEL, FSInt32ArrayCopySEL, L"FSInt32ArrayCopy"},
	{FSInt32ArraySEL, FSInt32ArrayGetDataPtrSEL, L"FSInt32ArrayGetDataPtr"},
	{FSInt32ArraySEL, FSInt32ArrayInsertAtSEL, L"FSInt32ArrayInsertAt"},
	{FSInt32ArraySEL, FSInt32ArrayRemoveAtSEL, L"FSInt32ArrayRemoveAt"},
	{FSInt32ArraySEL, FSInt32ArrayInsertNewArrayAtSEL, L"FSInt32ArrayInsertNewArrayAt"},
	{FSInt32ArraySEL, FSInt32ArrayFindSEL, L"FSInt32ArrayFind"},
	{FSInt32ArraySEL, FSInt32ArrayGetDataSEL, L"FSInt32ArrayGetData"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryGetProfilePathSEL, L"FSRegistryManagerRegistryGetProfilePath"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryWriteIntSEL, L"FSRegistryManagerRegistryWriteInt"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryWriteBinarySEL, L"FSRegistryManagerRegistryWriteBinary"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryWriteStringSEL, L"FSRegistryManagerRegistryWriteString"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryGetIntSEL, L"FSRegistryManagerRegistryGetInt"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryGetBinarySEL, L"FSRegistryManagerRegistryGetBinary"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryGetStringSEL, L"FSRegistryManagerRegistryGetString"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryGetEntryCountSEL, L"FSRegistryManagerRegistryGetEntryCount"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryGetEntryNameSEL, L"FSRegistryManagerRegistryGetEntryName"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryRemoveSectionSEL, L"FSRegistryManagerRegistryRemoveSection"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryRemoveEntrySEL, L"FSRegistryManagerRegistryRemoveEntry"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryGetKeyCountsSEL, L"FSRegistryManagerRegistryGetKeyCounts"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryGetKeyNameSEL, L"FSRegistryManagerRegistryGetKeyName"},
	{FSRegistryManagerSEL, FSRegistryManagerRegistryDeleteBinarySEL, L"FSRegistryManagerRegistryDeleteBinary"},
	{FSRegistryManagerSEL, FSRegistryManagerGetEntryCountsByHKeySEL, L"FSRegistryManagerGetEntryCountsByHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerRemoveEntryByHKeySEL, L"FSRegistryManagerRemoveEntryByHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerGetKeyCountsByHKeySEL, L"FSRegistryManagerGetKeyCountsByHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerGetKeyNameByHKeySEL, L"FSRegistryManagerGetKeyNameByHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerGetKeyNameListByHKeySEL, L"FSRegistryManagerGetKeyNameListByHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerGetHKeySEL, L"FSRegistryManagerGetHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerCloseHKeySEL, L"FSRegistryManagerCloseHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerWriteProfileIntByHKeySEL, L"FSRegistryManagerWriteProfileIntByHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerWriteProfileBinaryByHKeySEL, L"FSRegistryManagerWriteProfileBinaryByHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerWriteProfileStringByHKeySEL, L"FSRegistryManagerWriteProfileStringByHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerGetProfileIntByHKeySEL, L"FSRegistryManagerGetProfileIntByHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerGetProfileBinaryByHKeySEL, L"FSRegistryManagerGetProfileBinaryByHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerGetProfileStringByHKeySEL, L"FSRegistryManagerGetProfileStringByHKey"},
	{FSRegistryManagerSEL, FSRegistryManagerGetKeyNameListSEL, L"FSRegistryManagerGetKeyNameList"},
	{FSFloatRectSEL, FSFloatRectIsEmptySEL, L"FSFloatRectIsEmpty"},
	{FSFloatRectSEL, FSFloatRectNormalizeSEL, L"FSFloatRectNormalize"},
	{FSFloatRectSEL, FSFloatRectIsEqualRectSEL, L"FSFloatRectIsEqualRect"},
	{FSFloatRectSEL, FSFloatRectIsNotEqualRectSEL, L"FSFloatRectIsNotEqualRect"},
	{FSFloatRectSEL, FSFloatRectResetSEL, L"FSFloatRectReset"},
	{FSFloatRectSEL, FSFloatRectContainsSEL, L"FSFloatRectContains"},
	{FSFloatRectSEL, FSFloatRectContains2SEL, L"FSFloatRectContains2"},
	{FSFloatRectSEL, FSFloatRectTransformSEL, L"FSFloatRectTransform"},
	{FSFloatRectSEL, FSFloatRectIntersectSEL, L"FSFloatRectIntersect"},
	{FSFloatRectSEL, FSFloatRectUnionSEL, L"FSFloatRectUnion"},
	{FSFloatRectSEL, FSFloatRectGetInnerRectSEL, L"FSFloatRectGetInnerRect"},
	{FSFloatRectSEL, FSFloatRectGetOutterRectSEL, L"FSFloatRectGetOutterRect"},
	{FSFloatRectSEL, FSFloatRectGetClosestRectSEL, L"FSFloatRectGetClosestRect"},
	{FSFloatRectSEL, FSFloatRectSubstract4SEL, L"FSFloatRectSubstract4"},
	{FSFloatRectSEL, FSFloatRectInitRectSEL, L"FSFloatRectInitRect"},
	{FSFloatRectSEL, FSFloatRectUpdateRectSEL, L"FSFloatRectUpdateRect"},
	{FSFloatRectSEL, FSFloatRectWidthSEL, L"FSFloatRectWidth"},
	{FSFloatRectSEL, FSFloatRectHeightSEL, L"FSFloatRectHeight"},
	{FSFloatRectSEL, FSFloatRectInflateSEL, L"FSFloatRectInflate"},
	{FSFloatRectSEL, FSFloatRectInflate2SEL, L"FSFloatRectInflate2"},
	{FSFloatRectSEL, FSFloatRectInflate3SEL, L"FSFloatRectInflate3"},
	{FSFloatRectSEL, FSFloatRectDeflateSEL, L"FSFloatRectDeflate"},
	{FSFloatRectSEL, FSFloatRectDeflate2SEL, L"FSFloatRectDeflate2"},
	{FSFloatRectSEL, FSFloatRectDeflate3SEL, L"FSFloatRectDeflate3"},
	{FSFloatRectSEL, FSFloatRectTranslateSEL, L"FSFloatRectTranslate"},
	{FSFloatRectSEL, FSFloatRectGetBBoxSEL, L"FSFloatRectGetBBox"},
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
	{FRBrowserManagerSEL, FRBrowserManagerOpenHtmlOnNewTabSEL, L"FRBrowserManagerOpenHtmlOnNewTab"},
	{FRBrowserManagerSEL, FRBrowserManagerOpenWebPageDocumentSEL, L"FRBrowserManagerOpenWebPageDocument"},
	{FRBrowserManagerSEL, FRBrowserManagerReleaseWebPageDocumentSEL, L"FRBrowserManagerReleaseWebPageDocument"},
	{FRBrowserManagerSEL, FRBrowserManagerOnPretranslateMessageSEL, L"FRBrowserManagerOnPretranslateMessage"},
	{FRBrowserManagerSEL, FRBrowserManagerOnWebPageSizeSEL, L"FRBrowserManagerOnWebPageSize"},
	{FRBrowserManagerSEL, FRBrowserManagerExecuteJavaScriptSEL, L"FRBrowserManagerExecuteJavaScript"},
	{FRBrowserManagerSEL, FRBrowserManagerSetCookiesSEL, L"FRBrowserManagerSetCookies"},
	{FRBrowserManagerSEL, FRBrowserManagerGetCookiesSEL, L"FRBrowserManagerGetCookies"},
	{FRBrowserManagerSEL, FRBrowserManagerDeleteCookiesSEL, L"FRBrowserManagerDeleteCookies"},
	{FRBrowserManagerSEL, FRBrowserManagerExecuteJavaScriptOnCreatedSEL, L"FRBrowserManagerExecuteJavaScriptOnCreated"},
	{FRBrowserManagerSEL, FRBrowserManagerShowWindowSEL, L"FRBrowserManagerShowWindow"},
	{FRBrowserManagerSEL, FRBrowserManagerSetCookies2SEL, L"FRBrowserManagerSetCookies2"},
	{FRBrowserManagerSEL, FRBrowserManagerGetCookies2SEL, L"FRBrowserManagerGetCookies2"},
	{FRBrowserManagerSEL, FRBrowserManagerDeleteCookies2SEL, L"FRBrowserManagerDeleteCookies2"},
	{FRBrowserManagerSEL, FRBrowserManagerExecuteJavaScript2SEL, L"FRBrowserManagerExecuteJavaScript2"},
	{FRBrowserManagerSEL, FRBrowserManagerSetZoomFactorSEL, L"FRBrowserManagerSetZoomFactor"},
// fhtml_impl.h end

// In file fr_appImpl.h
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerBeginTimerSEL, L"FRMarkAnnotHandlerBeginTimer"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerEndTimerSEL, L"FRMarkAnnotHandlerEndTimer"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnMoveOutPageSEL, L"FRMarkAnnotHandlerOnMoveOutPage"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerCopyReplySEL, L"FRMarkAnnotHandlerCopyReply"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerDeleteAnnotSEL, L"FRMarkAnnotHandlerDeleteAnnot"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerIsDesignerSEL, L"FRMarkAnnotHandlerIsDesigner"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerCanReSizeSEL, L"FRMarkAnnotHandlerCanReSize"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerCanMoveSEL, L"FRMarkAnnotHandlerCanMove"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerCanAnswerSEL, L"FRMarkAnnotHandlerCanAnswer"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnLoadSEL, L"FRMarkAnnotHandlerOnLoad"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerGetViewBBoxSEL, L"FRMarkAnnotHandlerGetViewBBox"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnDrawSEL, L"FRMarkAnnotHandlerOnDraw"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnLButtonDownSEL, L"FRMarkAnnotHandlerOnLButtonDown"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnLButtonUpSEL, L"FRMarkAnnotHandlerOnLButtonUp"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnMouseMoveSEL, L"FRMarkAnnotHandlerOnMouseMove"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnLButtonDblClkSEL, L"FRMarkAnnotHandlerOnLButtonDblClk"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnDeSelectedSEL, L"FRMarkAnnotHandlerOnDeSelected"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnSelectedSEL, L"FRMarkAnnotHandlerOnSelected"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnPopupMenuSEL, L"FRMarkAnnotHandlerOnPopupMenu"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnPopupMenuItemSEL, L"FRMarkAnnotHandlerOnPopupMenuItem"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerIsMenuItemSupportedSEL, L"FRMarkAnnotHandlerIsMenuItemSupported"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerGetMoveTypeSEL, L"FRMarkAnnotHandlerGetMoveType"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnMovingSEL, L"FRMarkAnnotHandlerOnMoving"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnMovedSEL, L"FRMarkAnnotHandlerOnMoved"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerCancelMovingSEL, L"FRMarkAnnotHandlerCancelMoving"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnMovedOutPageSEL, L"FRMarkAnnotHandlerOnMovedOutPage"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnSetPositionSEL, L"FRMarkAnnotHandlerOnSetPosition"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnMoving2SEL, L"FRMarkAnnotHandlerOnMoving2"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnMoved2SEL, L"FRMarkAnnotHandlerOnMoved2"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnResizingSEL, L"FRMarkAnnotHandlerOnResizing"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnCopySEL, L"FRMarkAnnotHandlerOnCopy"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnSetFocusSEL, L"FRMarkAnnotHandlerOnSetFocus"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnKillFocusSEL, L"FRMarkAnnotHandlerOnKillFocus"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerDeleteMarkupHandlerSEL, L"FRMarkAnnotHandlerDeleteMarkupHandler"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerCreateMarkupHandlerSEL, L"FRMarkAnnotHandlerCreateMarkupHandler"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerCastToBAAnnotHandlerSEL, L"FRMarkAnnotHandlerCastToBAAnnotHandler"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerTimerProcSEL, L"FRMarkAnnotHandlerTimerProc"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerGetSystemHandlerSEL, L"FRMarkAnnotHandlerGetSystemHandler"},
	{FRMarkAnnotHandlerSEL, FRMarkAnnotHandlerOnPasteSEL, L"FRMarkAnnotHandlerOnPaste"},
	{FRReaderUserMessageHandlerSEL, FRReaderUserMessageHandlerNewSEL, L"FRReaderUserMessageHandlerNew"},
	{FRReaderUserMessageHandlerSEL, FRReaderUserMessageHandlerDestroySEL, L"FRReaderUserMessageHandlerDestroy"},
	{FRIFieldMulCopiesNotifySEL, FRIFieldMulCopiesNotifyNewSEL, L"FRIFieldMulCopiesNotifyNew"},
	{FRIFieldMulCopiesNotifySEL, FRIFieldMulCopiesNotifyDestroySEL, L"FRIFieldMulCopiesNotifyDestroy"},
	{FRIActionWizardDataSEL, FRIActionWizardDataCreateIActionWizardDataSEL, L"FRIActionWizardDataCreateIActionWizardData"},
	{FRIActionWizardDataSEL, FRIActionWizardDataSetRootXMLEleSEL, L"FRIActionWizardDataSetRootXMLEle"},
	{FRIActionWizardDataSEL, FRIActionWizardDataSaveItemsDataToXMLSEL, L"FRIActionWizardDataSaveItemsDataToXML"},
	{FRIActionWizardDataSEL, FRIActionWizardDataGetItemsDataFromXMLSEL, L"FRIActionWizardDataGetItemsDataFromXML"},
	{FRIActionWizardDataSEL, FRIActionWizardDataGetItemsSEL, L"FRIActionWizardDataGetItems"},
	{FRIActionWizardDataSEL, FRIActionWizardDataGetItemDataFromXMLINTSEL, L"FRIActionWizardDataGetItemDataFromXMLINT"},
	{FRIActionWizardDataSEL, FRIActionWizardDataGetItemDataFromXMLFLOATSEL, L"FRIActionWizardDataGetItemDataFromXMLFLOAT"},
	{FRIActionWizardDataSEL, FRIActionWizardDataGetItemDataFromXMLBOOLSEL, L"FRIActionWizardDataGetItemDataFromXMLBOOL"},
	{FRIActionWizardDataSEL, FRIActionWizardDataGetItemDataFromXMLStringSEL, L"FRIActionWizardDataGetItemDataFromXMLString"},
	{FRIActionWizardDataSEL, FRIActionWizardDataSaveItemDataToXMLBOOLSEL, L"FRIActionWizardDataSaveItemDataToXMLBOOL"},
	{FRIActionWizardDataSEL, FRIActionWizardDataSaveItemDataToXMLINTSEL, L"FRIActionWizardDataSaveItemDataToXMLINT"},
	{FRIActionWizardDataSEL, FRIActionWizardDataSaveItemDataToXMLFLOATSEL, L"FRIActionWizardDataSaveItemDataToXMLFLOAT"},
	{FRIActionWizardDataSEL, FRIActionWizardDataSaveItemDataToXMLWCHARSEL, L"FRIActionWizardDataSaveItemDataToXMLWCHAR"},
	{FRIActionWizardDataSEL, FRIActionWizardDataSaveItemDataToXMLSTRINGSEL, L"FRIActionWizardDataSaveItemDataToXMLSTRING"},
	{FRIActionWizardDataSEL, FRIActionWizardDataDestroyIActionWizardDataSEL, L"FRIActionWizardDataDestroyIActionWizardData"},
	{FRIActionWizardDataSEL, FRIActionWizardDataGetItemsChidrenCountSEL, L"FRIActionWizardDataGetItemsChidrenCount"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataSetItemDataBOOLSEL, L"FRCMapItemNameToDataSetItemDataBOOL"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataSetItemDataINTSEL, L"FRCMapItemNameToDataSetItemDataINT"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataSetItemDataFLOATSEL, L"FRCMapItemNameToDataSetItemDataFLOAT"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataSetItemDataWCHARSEL, L"FRCMapItemNameToDataSetItemDataWCHAR"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataSetItemDataSTRINGSEL, L"FRCMapItemNameToDataSetItemDataSTRING"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataGetItemDataINTSEL, L"FRCMapItemNameToDataGetItemDataINT"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataGetItemDataFLOATSEL, L"FRCMapItemNameToDataGetItemDataFLOAT"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataGetItemDataBOOLSEL, L"FRCMapItemNameToDataGetItemDataBOOL"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataGetItemDataSTRINGSEL, L"FRCMapItemNameToDataGetItemDataSTRING"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataCheckKeyExistSEL, L"FRCMapItemNameToDataCheckKeyExist"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataIsEmptySEL, L"FRCMapItemNameToDataIsEmpty"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataGetCountSEL, L"FRCMapItemNameToDataGetCount"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataRemoveAtSEL, L"FRCMapItemNameToDataRemoveAt"},
	{FRCMapItemNameToDataSEL, FRCMapItemNameToDataRemovAllSEL, L"FRCMapItemNameToDataRemovAll"},
	{FRReaderUIMgrSEL, FRReaderUIMgrShowFilePasswordDlgSEL, L"FRReaderUIMgrShowFilePasswordDlg"},
	{FRReaderUIMgrSEL, FRReaderUIMgrGetReaderThemeObjectSEL, L"FRReaderUIMgrGetReaderThemeObject"},
	{FRReaderThemeSEL, FRReaderThemeGetBkGroundColorSEL, L"FRReaderThemeGetBkGroundColor"},
	{FRReaderThemeSEL, FRReaderThemeInstallSkinThemeSEL, L"FRReaderThemeInstallSkinTheme"},
	{FRReaderThemeSEL, FRReaderThemeInstallSkinTheme2SEL, L"FRReaderThemeInstallSkinTheme2"},
	{FRReaderThemeSEL, FRReaderThemeRegistSkinChangeProcSEL, L"FRReaderThemeRegistSkinChangeProc"},
	{FRReaderThemeSEL, FRReaderThemeUnRegistSkinChangeProcSEL, L"FRReaderThemeUnRegistSkinChangeProc"},
	{FRReaderThemeSEL, FRReaderThemeGetSkinStyleSEL, L"FRReaderThemeGetSkinStyle"},
	{FRReaderThemeSEL, FRReaderThemeGetWindowColorSEL, L"FRReaderThemeGetWindowColor"},
	{FRReaderThemeSEL, FRReaderThemeGetWindowTextColorSEL, L"FRReaderThemeGetWindowTextColor"},
	{FRReaderThemeSEL, FRReaderThemeGetAppColorSEL, L"FRReaderThemeGetAppColor"},
	{FRReaderThemeSEL, FRReaderThemeGetLeftPanelSeparatorColorSEL, L"FRReaderThemeGetLeftPanelSeparatorColor"},
	{FRReaderThemeSEL, FRReaderThemeGetWindow2ColorSEL, L"FRReaderThemeGetWindow2Color"},
	{FRReaderThemeSEL, FRReaderThemeSetBkGroundColorSEL, L"FRReaderThemeSetBkGroundColor"},
	{FRReaderThemeSEL, FRReaderThemeEnableWindowRoundedCornersSEL, L"FRReaderThemeEnableWindowRoundedCorners"},
	{FRReaderThemeSEL, FRReaderThemeGetColorSEL, L"FRReaderThemeGetColor"},
	{FRReaderThemeSEL, FRReaderThemeGetColorMapSEL, L"FRReaderThemeGetColorMap"},
	{FRPluginsMamagerSEL, FRPluginsMamagerLoadPluginSEL, L"FRPluginsMamagerLoadPlugin"},
	{FRPluginsMamagerSEL, FRPluginsMamagerIsLoadedPluginSEL, L"FRPluginsMamagerIsLoadedPlugin"},
	{FRPluginsMamagerSEL, FRPluginsMamagerIsDisabledPluginSEL, L"FRPluginsMamagerIsDisabledPlugin"},
	{FRPluginsMamagerSEL, FRPluginsMamagerIsPluginNeedLoadByGPOSEL, L"FRPluginsMamagerIsPluginNeedLoadByGPO"},
	{FRIReplaceAllNotifySEL, FRIReplaceAllNotifyReplaceAllProcSEL, L"FRIReplaceAllNotifyReplaceAllProc"},
	{FRIFindReplaceMgrSEL, FRIFindReplaceMgrNewSEL, L"FRIFindReplaceMgrNew"},
	{FRIFindReplaceMgrSEL, FRIFindReplaceMgrDestroySEL, L"FRIFindReplaceMgrDestroy"},
	{FRIFindReplaceMgrSEL, FRIFindReplaceMgrSetToMgrSEL, L"FRIFindReplaceMgrSetToMgr"},
	{FRPDFBitmapSEL, FRPDFBitmapDrawSEL, L"FRPDFBitmapDraw"},
	{FRPDFBitmapSEL, FRPDFBitmapGetBitmapSEL, L"FRPDFBitmapGetBitmap"},
	{FRPDFBitmapSEL, FRPDFBitmapGetBitmapFromPDFIconSEL, L"FRPDFBitmapGetBitmapFromPDFIcon"},
	{FRPDFBitmapSEL, FRPDFBitmapFillRoundedRectangleSEL, L"FRPDFBitmapFillRoundedRectangle"},
	{FRPDFBitmapSEL, FRPDFBitmapDrawRoundedRectangleSEL, L"FRPDFBitmapDrawRoundedRectangle"},
	{FRPDFBitmapSEL, FRPDFBitmapDraw2SEL, L"FRPDFBitmapDraw2"},
	{FRPDFBitmapSEL, FRPDFBitmapGetBitmap2SEL, L"FRPDFBitmapGetBitmap2"},
	{FRPDFBitmapSEL, FRPDFBitmapGetFXBitmapSEL, L"FRPDFBitmapGetFXBitmap"},
	{FRAccessibilitySEL, FRAccessibilityIsScreenReaderRunningSEL, L"FRAccessibilityIsScreenReaderRunning"},
	{FRAccessibilitySEL, FRAccessibilityIsATSupportEnabledSEL, L"FRAccessibilityIsATSupportEnabled"},
	{FRAppUIStyleSEL, FRAppUIStyleGetAppColorSEL, L"FRAppUIStyleGetAppColor"},
	{FRAppUIStyleSEL, FRAppUIStyleGetRibbonImageScaleSEL, L"FRAppUIStyleGetRibbonImageScale"},
// fr_appImpl.h end

// In file fr_barImpl.h
	{FRRibbonStyleRadioBoxSEL, FRRibbonStyleRadioBoxGetMFCButtonSEL, L"FRRibbonStyleRadioBoxGetMFCButton"},
	{FRRibbonStyleRadioBoxSEL, FRRibbonStyleRadioBoxReleaseSEL, L"FRRibbonStyleRadioBoxRelease"},
	{FRRibbonStyleRadioBoxSEL, FRRibbonStyleRadioBoxSetDefaultStyleSEL, L"FRRibbonStyleRadioBoxSetDefaultStyle"},
	{FRRibbonStyleCheckBoxSEL, FRRibbonStyleCheckBoxIsCheckedSEL, L"FRRibbonStyleCheckBoxIsChecked"},
	{FRRibbonStyleCheckBoxSEL, FRRibbonStyleCheckBoxGetCheckStateSEL, L"FRRibbonStyleCheckBoxGetCheckState"},
	{FRRibbonStyleCheckBoxSEL, FRRibbonStyleCheckBoxSetCheckBox3StateSEL, L"FRRibbonStyleCheckBoxSetCheckBox3State"},
	{FRRibbonStyleCheckBoxSEL, FRRibbonStyleCheckBoxGetMFCButtonSEL, L"FRRibbonStyleCheckBoxGetMFCButton"},
	{FRRibbonStyleCheckBoxSEL, FRRibbonStyleCheckBoxReleaseSEL, L"FRRibbonStyleCheckBoxRelease"},
	{FRRibbonStyleCheckBoxSEL, FRRibbonStyleCheckBoxSetDefaultStyleSEL, L"FRRibbonStyleCheckBoxSetDefaultStyle"},
	{FRRibbonStyleEditSEL, FRRibbonStyleEditGetEditButtonSEL, L"FRRibbonStyleEditGetEditButton"},
	{FRRibbonStyleEditSEL, FRRibbonStyleEditReleaseSEL, L"FRRibbonStyleEditRelease"},
	{FRRibbonStyleEditSEL, FRRibbonStyleEditSetPromptTextSEL, L"FRRibbonStyleEditSetPromptText"},
	{FRRibbonStyleEditSEL, FRRibbonStyleEditSetBorderColorSEL, L"FRRibbonStyleEditSetBorderColor"},
	{FRRibbonStyleEditSEL, FRRibbonStyleEditSetRoundRadiusSEL, L"FRRibbonStyleEditSetRoundRadius"},
	{FRRibbonStyleEditSEL, FRRibbonStyleEditSetDefaultStyleSEL, L"FRRibbonStyleEditSetDefaultStyle"},
	{FRRibbonStyleLinkButtonSEL, FRRibbonStyleLinkButtonSetAlwaysUnderLineTextSEL, L"FRRibbonStyleLinkButtonSetAlwaysUnderLineText"},
	{FRRibbonStyleLinkButtonSEL, FRRibbonStyleLinkButtonSetMultilineTextSEL, L"FRRibbonStyleLinkButtonSetMultilineText"},
	{FRRibbonStyleLinkButtonSEL, FRRibbonStyleLinkButtonSetAlignStyleSEL, L"FRRibbonStyleLinkButtonSetAlignStyle"},
	{FRRibbonStyleLinkButtonSEL, FRRibbonStyleLinkButtonGetMFCButtonSEL, L"FRRibbonStyleLinkButtonGetMFCButton"},
	{FRRibbonStyleLinkButtonSEL, FRRibbonStyleLinkButtonReleaseSEL, L"FRRibbonStyleLinkButtonRelease"},
	{FRRibbonStyleSliderCtrlSEL, FRRibbonStyleSliderCtrlGetSliderButtonSEL, L"FRRibbonStyleSliderCtrlGetSliderButton"},
	{FRRibbonStyleSliderCtrlSEL, FRRibbonStyleSliderCtrlReleaseSEL, L"FRRibbonStyleSliderCtrlRelease"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonGetButtonSEL, L"FRRibbonStyleColorButtonGetButton"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonReleaseSEL, L"FRRibbonStyleColorButtonRelease"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonSetColorSEL, L"FRRibbonStyleColorButtonSetColor"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonGetColorSEL, L"FRRibbonStyleColorButtonGetColor"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonSetColumnsNumberSEL, L"FRRibbonStyleColorButtonSetColumnsNumber"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonSetImageSEL, L"FRRibbonStyleColorButtonSetImage"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonSetAppearanceSEL, L"FRRibbonStyleColorButtonSetAppearance"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonEnableAutomaticButtonSEL, L"FRRibbonStyleColorButtonEnableAutomaticButton"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonEnableOtherButtonSEL, L"FRRibbonStyleColorButtonEnableOtherButton"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonSetImage2SEL, L"FRRibbonStyleColorButtonSetImage2"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonSetTooltipSEL, L"FRRibbonStyleColorButtonSetTooltip"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonSetDescriptionSEL, L"FRRibbonStyleColorButtonSetDescription"},
	{FRRibbonStyleColorButtonSEL, FRRibbonStyleColorButtonEnableHelpLinkSEL, L"FRRibbonStyleColorButtonEnableHelpLink"},
	{FRRibbonStyleComboBoxSEL, FRRibbonStyleComboBoxGetButtonSEL, L"FRRibbonStyleComboBoxGetButton"},
	{FRRibbonStyleComboBoxSEL, FRRibbonStyleComboBoxSetPromptSEL, L"FRRibbonStyleComboBoxSetPrompt"},
	{FRRibbonStyleComboBoxSEL, FRRibbonStyleComboBoxReleaseSEL, L"FRRibbonStyleComboBoxRelease"},
	{FRRibbonStyleComboBoxSEL, FRRibbonStyleComboBoxSetInputTypeSEL, L"FRRibbonStyleComboBoxSetInputType"},
	{FRRibbonStyleComboBoxSEL, FRRibbonStyleComboBoxSetLimitDecimalNumSEL, L"FRRibbonStyleComboBoxSetLimitDecimalNum"},
	{FRRibbonStyleComboBoxSEL, FRRibbonStyleComboBoxSetMaxAndMinValueSEL, L"FRRibbonStyleComboBoxSetMaxAndMinValue"},
	{FRRibbonStyleComboBoxSEL, FRRibbonStyleComboBoxSetDescriptionSEL, L"FRRibbonStyleComboBoxSetDescription"},
	{FRRibbonStyleComboBoxSEL, FRRibbonStyleComboBoxEnableHelpLinkSEL, L"FRRibbonStyleComboBoxEnableHelpLink"},
	{FRRibbonStyleComboBoxSEL, FRRibbonStyleComboBoxSetTooltipSEL, L"FRRibbonStyleComboBoxSetTooltip"},
	{FRRibbonStyleComboBoxSEL, FRRibbonStyleComboBoxSetRoundRadiusSEL, L"FRRibbonStyleComboBoxSetRoundRadius"},
	{FRRibbonStyleComboBoxSEL, FRRibbonStyleComboBoxSetDefaultStyleSEL, L"FRRibbonStyleComboBoxSetDefaultStyle"},
	{FRRibbonStyleFontComboBoxSEL, FRRibbonStyleFontComboBoxGetButtonSEL, L"FRRibbonStyleFontComboBoxGetButton"},
	{FRRibbonStyleFontComboBoxSEL, FRRibbonStyleFontComboBoxReleaseSEL, L"FRRibbonStyleFontComboBoxRelease"},
	{FRRibbonStyleFontComboBoxSEL, FRRibbonStyleFontComboBoxSelectFontSEL, L"FRRibbonStyleFontComboBoxSelectFont"},
	{FRRibbonStyleFontComboBoxSEL, FRRibbonStyleFontComboBoxInsertFontSEL, L"FRRibbonStyleFontComboBoxInsertFont"},
	{FRRibbonStyleFontComboBoxSEL, FRRibbonStyleFontComboBoxAddFontSEL, L"FRRibbonStyleFontComboBoxAddFont"},
	{FRRibbonStyleFontComboBoxSEL, FRRibbonStyleFontComboBoxSetDescriptionSEL, L"FRRibbonStyleFontComboBoxSetDescription"},
	{FRRibbonStyleFontComboBoxSEL, FRRibbonStyleFontComboBoxEnableHelpLinkSEL, L"FRRibbonStyleFontComboBoxEnableHelpLink"},
	{FRRibbonStyleFontComboBoxSEL, FRRibbonStyleFontComboBoxSetTooltipSEL, L"FRRibbonStyleFontComboBoxSetTooltip"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlGetWndSEL, L"FRStyleGalleryCtrlGetWnd"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlReleaseSEL, L"FRStyleGalleryCtrlRelease"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlAddGroupSEL, L"FRStyleGalleryCtrlAddGroup"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlAddGroup1SEL, L"FRStyleGalleryCtrlAddGroup1"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlSelectItemSEL, L"FRStyleGalleryCtrlSelectItem"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlGetSelectedItemSEL, L"FRStyleGalleryCtrlGetSelectedItem"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlSetItemSizeSEL, L"FRStyleGalleryCtrlSetItemSize"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlSetImageMarginSEL, L"FRStyleGalleryCtrlSetImageMargin"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlSetAppearanceSEL, L"FRStyleGalleryCtrlSetAppearance"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlSetAlignedSideSEL, L"FRStyleGalleryCtrlSetAlignedSide"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlAddItemButtonSEL, L"FRStyleGalleryCtrlAddItemButton"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlSetItemToolTipSEL, L"FRStyleGalleryCtrlSetItemToolTip"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlSetItemAccNameSEL, L"FRStyleGalleryCtrlSetItemAccName"},
	{FRStyleGalleryCtrlSEL, FRStyleGalleryCtrlDisableHighContrastThemeImageSEL, L"FRStyleGalleryCtrlDisableHighContrastThemeImage"},
	{FRStyleSpinBtnCtrlSEL, FRStyleSpinBtnCtrlGetButtonSEL, L"FRStyleSpinBtnCtrlGetButton"},
	{FRStyleSpinBtnCtrlSEL, FRStyleSpinBtnCtrlReleaseSEL, L"FRStyleSpinBtnCtrlRelease"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlGetWndSEL, L"FRStyleComboGalleryCtrlGetWnd"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlReleaseSEL, L"FRStyleComboGalleryCtrlRelease"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlAddGroupSEL, L"FRStyleComboGalleryCtrlAddGroup"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlAddGroup1SEL, L"FRStyleComboGalleryCtrlAddGroup1"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlRemoveAllGroupSEL, L"FRStyleComboGalleryCtrlRemoveAllGroup"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlGetCountSEL, L"FRStyleComboGalleryCtrlGetCount"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlGetSelectedItemSEL, L"FRStyleComboGalleryCtrlGetSelectedItem"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlSelectItemSEL, L"FRStyleComboGalleryCtrlSelectItem"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlGetItemTextSEL, L"FRStyleComboGalleryCtrlGetItemText"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlSetAppearanceSEL, L"FRStyleComboGalleryCtrlSetAppearance"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlSetIconsInRowSEL, L"FRStyleComboGalleryCtrlSetIconsInRow"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlSetComboModeSEL, L"FRStyleComboGalleryCtrlSetComboMode"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlSetImageSEL, L"FRStyleComboGalleryCtrlSetImage"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlSetAlignStyleSEL, L"FRStyleComboGalleryCtrlSetAlignStyle"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlSetImageSideSEL, L"FRStyleComboGalleryCtrlSetImageSide"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlSetVertMarginSEL, L"FRStyleComboGalleryCtrlSetVertMargin"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlSetImage3SEL, L"FRStyleComboGalleryCtrlSetImage3"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlSetDescriptionSEL, L"FRStyleComboGalleryCtrlSetDescription"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlEnableHelpLinkSEL, L"FRStyleComboGalleryCtrlEnableHelpLink"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlSetTooltipSEL, L"FRStyleComboGalleryCtrlSetTooltip"},
	{FRStyleComboGalleryCtrlSEL, FRStyleComboGalleryCtrlDisableHighContrastThemeImageSEL, L"FRStyleComboGalleryCtrlDisableHighContrastThemeImage"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonGetButtonSEL, L"FRStyleMenuButtonGetButton"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonReleaseSEL, L"FRStyleMenuButtonRelease"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetMenuSEL, L"FRStyleMenuButtonSetMenu"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetDefaultClickSEL, L"FRStyleMenuButtonSetDefaultClick"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonGetMenuResultSEL, L"FRStyleMenuButtonGetMenuResult"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetImageSEL, L"FRStyleMenuButtonSetImage"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetImage2SEL, L"FRStyleMenuButtonSetImage2"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetAlignStyleSEL, L"FRStyleMenuButtonSetAlignStyle"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetImageSideSEL, L"FRStyleMenuButtonSetImageSide"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetFlatStyleSEL, L"FRStyleMenuButtonSetFlatStyle"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetVertMarginSEL, L"FRStyleMenuButtonSetVertMargin"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonEnablePopupWndSEL, L"FRStyleMenuButtonEnablePopupWnd"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetDropdownProcSEL, L"FRStyleMenuButtonSetDropdownProc"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetAppearanceSEL, L"FRStyleMenuButtonSetAppearance"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetTooltipSEL, L"FRStyleMenuButtonSetTooltip"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetDescriptionSEL, L"FRStyleMenuButtonSetDescription"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonEnableHelpLinkSEL, L"FRStyleMenuButtonEnableHelpLink"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetMenu2SEL, L"FRStyleMenuButtonSetMenu2"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetRoundRadiusSEL, L"FRStyleMenuButtonSetRoundRadius"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonSetDefaultStyleSEL, L"FRStyleMenuButtonSetDefaultStyle"},
	{FRStyleMenuButtonSEL, FRStyleMenuButtonDisableHighContrastThemeImageSEL, L"FRStyleMenuButtonDisableHighContrastThemeImage"},
	{FRCommonControlSEL, FRCommonControlAddMenuItemSEL, L"FRCommonControlAddMenuItem"},
	{FRCommonControlSEL, FRCommonControlSetExecuteProcSEL, L"FRCommonControlSetExecuteProc"},
	{FRCommonControlSEL, FRCommonControlSetComputeEnabledProcSEL, L"FRCommonControlSetComputeEnabledProc"},
	{FRCommonControlSEL, FRCommonControlSetAppearanceSettingProcSEL, L"FRCommonControlSetAppearanceSettingProc"},
	{FRCommonControlSEL, FRCommonControlDoExecuteProcSEL, L"FRCommonControlDoExecuteProc"},
	{FRCommonControlSEL, FRCommonControlIsEnabledSEL, L"FRCommonControlIsEnabled"},
	{FRCommonControlSEL, FRCommonControlSetAccelSEL, L"FRCommonControlSetAccel"},
	{FRCommonControlSEL, FRCommonControlGetAccelSEL, L"FRCommonControlGetAccel"},
	{FRCommonControlSEL, FRCommonControlSetTooltipSEL, L"FRCommonControlSetTooltip"},
	{FRCommonControlSEL, FRCommonControlGetTooltipSEL, L"FRCommonControlGetTooltip"},
	{FRCommonControlSEL, FRCommonControlSetTitleSEL, L"FRCommonControlSetTitle"},
	{FRCommonControlSEL, FRCommonControlGetTitleSEL, L"FRCommonControlGetTitle"},
	{FRCommonControlSEL, FRCommonControlSetImageSEL, L"FRCommonControlSetImage"},
	{FRCommonControlSEL, FRCommonControlSetVisibleSEL, L"FRCommonControlSetVisible"},
	{FRCommonControlSEL, FRCommonControlGetVisibleSEL, L"FRCommonControlGetVisible"},
	{FRCommonControlSEL, FRCommonControlGetTypeSEL, L"FRCommonControlGetType"},
	{FRCommonControlSEL, FRCommonControlGetNameSEL, L"FRCommonControlGetName"},
	{FRCommonControlSEL, FRCommonControlGetMenuItemCountSEL, L"FRCommonControlGetMenuItemCount"},
	{FRCommonControlSEL, FRCommonControlFindMenuItemByIndexSEL, L"FRCommonControlFindMenuItemByIndex"},
	{FRCommonControlSEL, FRCommonControlGetMenuItemByNameSEL, L"FRCommonControlGetMenuItemByName"},
	{FRCommonControlSEL, FRCommonControlGetCategoryNameSEL, L"FRCommonControlGetCategoryName"},
	{FRCommonControlSEL, FRCommonControlGetPanelNameSEL, L"FRCommonControlGetPanelName"},
	{FRCommonControlSEL, FRCommonControlIsCheckedSEL, L"FRCommonControlIsChecked"},
	{FRCommonControlSEL, FRCommonControlSetCheckSEL, L"FRCommonControlSetCheck"},
	{FRCommonControlSEL, FRCommonControlSetClientDataSEL, L"FRCommonControlSetClientData"},
	{FRCommonControlSEL, FRCommonControlSetDropDownAddElementProcSEL, L"FRCommonControlSetDropDownAddElementProc"},
	{FRCommonControlSEL, FRCommonControlSetTooltipHasHelpSEL, L"FRCommonControlSetTooltipHasHelp"},
// fr_barImpl.h end

// In file fr_docImpl.h
	{FRUndoItemCreateWidgetSEL, FRUndoItemCreateWidgetCreateUndoWidgetSEL, L"FRUndoItemCreateWidgetCreateUndoWidget"},
	{FRUndoItemCreateWidgetSEL, FRUndoItemCreateWidgetUndoSEL, L"FRUndoItemCreateWidgetUndo"},
	{FRUndoItemCreateWidgetSEL, FRUndoItemCreateWidgetRedoSEL, L"FRUndoItemCreateWidgetRedo"},
	{FRUndoItemCreateWidgetSEL, FRUndoItemCreateWidgetGetDescrSEL, L"FRUndoItemCreateWidgetGetDescr"},
	{FRCRSAStampSEL, FRCRSAStampNewSEL, L"FRCRSAStampNew"},
	{FRCRSAStampSEL, FRCRSAStampDestroySEL, L"FRCRSAStampDestroy"},
	{FRCRSAStampSEL, FRCRSAStampGetLeftValueSEL, L"FRCRSAStampGetLeftValue"},
	{FRCRSAStampSEL, FRCRSAStampGetTopValueSEL, L"FRCRSAStampGetTopValue"},
	{FRCRSAStampSEL, FRCRSAStampGetDefaultCropWValueSEL, L"FRCRSAStampGetDefaultCropWValue"},
	{FRCRSAStampSEL, FRCRSAStampSetDefaultCropWValueSEL, L"FRCRSAStampSetDefaultCropWValue"},
	{FRCRSAStampSEL, FRCRSAStampGetDefaultCropHValueSEL, L"FRCRSAStampGetDefaultCropHValue"},
	{FRCRSAStampSEL, FRCRSAStampSetDefaultCropHValueSEL, L"FRCRSAStampSetDefaultCropHValue"},
	{FRCRSAStampSEL, FRCRSAStampGetDefaultWValueSEL, L"FRCRSAStampGetDefaultWValue"},
	{FRCRSAStampSEL, FRCRSAStampSetDefaultWValueSEL, L"FRCRSAStampSetDefaultWValue"},
	{FRCRSAStampSEL, FRCRSAStampGetDefaultHValueSEL, L"FRCRSAStampGetDefaultHValue"},
	{FRCRSAStampSEL, FRCRSAStampSetDefaultHValueSEL, L"FRCRSAStampSetDefaultHValue"},
	{FRCRSAStampSEL, FRCRSAStampGetWidthValueSEL, L"FRCRSAStampGetWidthValue"},
	{FRCRSAStampSEL, FRCRSAStampSetWidthValueSEL, L"FRCRSAStampSetWidthValue"},
	{FRCRSAStampSEL, FRCRSAStampGetHeightValueSEL, L"FRCRSAStampGetHeightValue"},
	{FRCRSAStampSEL, FRCRSAStampSetHeightValueSEL, L"FRCRSAStampSetHeightValue"},
	{FRCRSAStampSEL, FRCRSAStampIsPathSEL, L"FRCRSAStampIsPath"},
	{FRCRSAStampSEL, FRCRSAStampSetPathSEL, L"FRCRSAStampSetPath"},
	{FRCRSAStampSEL, FRCRSAStampGetDIBitmapSEL, L"FRCRSAStampGetDIBitmap"},
	{FRCRSAStampSEL, FRCRSAStampSetDIBitmapSEL, L"FRCRSAStampSetDIBitmap"},
	{FRCRSAStampSEL, FRCRSAStampIsPDFSignStampSEL, L"FRCRSAStampIsPDFSignStamp"},
	{FRCRSAStampSEL, FRCRSAStampGetPDFPathSEL, L"FRCRSAStampGetPDFPath"},
	{FRCRSAStampSEL, FRCRSAStampIsDynamicSEL, L"FRCRSAStampIsDynamic"},
	{FRCRSAStampSEL, FRCRSAStampGetEncodeSEL, L"FRCRSAStampGetEncode"},
	{FRCRSAStampSEL, FRCRSAStampGetStampTypeSEL, L"FRCRSAStampGetStampType"},
	{FRCRSAStampSEL, FRCRSAStampSetPageIdxSEL, L"FRCRSAStampSetPageIdx"},
	{FRCRSAStampSEL, FRCRSAStampGetPageIdxSEL, L"FRCRSAStampGetPageIdx"},
	{FRCRSAStampSEL, FRCRSAStampPreViewArtBoxFileSEL, L"FRCRSAStampPreViewArtBoxFile"},
	{FRCRSAStampSEL, FRCRSAStampGetStampNameSEL, L"FRCRSAStampGetStampName"},
	{FRCRSAStampSEL, FRCRSAStampIsFavoriteSEL, L"FRCRSAStampIsFavorite"},
	{FRCRSAStampSEL, FRCRSAStampSetPagePieceInfoSEL, L"FRCRSAStampSetPagePieceInfo"},
	{FRCRSAStampSEL, FRCRSAStampSetPagePieceInfoByDocSEL, L"FRCRSAStampSetPagePieceInfoByDoc"},
	{FRCRSAStampSEL, FRCRSAStampGetIsRotateSEL, L"FRCRSAStampGetIsRotate"},
	{FRCRSAStampSEL, FRCRSAStampRemovePageSEL, L"FRCRSAStampRemovePage"},
	{FRCRSAStampSEL, FRCRSAStampCopySEL, L"FRCRSAStampCopy"},
	{FRCRSAStampSEL, FRCRSAStampGetPageFromNameSEL, L"FRCRSAStampGetPageFromName"},
	{FRCRSAStampSEL, FRCRSAStampSetStampNameSEL, L"FRCRSAStampSetStampName"},
	{FRCRSAStampSEL, FRCRSAStampSetPDFPathSEL, L"FRCRSAStampSetPDFPath"},
	{FRCRSAStampSEL, FRCRSAStampSetAppCloseDeleteSEL, L"FRCRSAStampSetAppCloseDelete"},
	{FRCRSAStampSEL, FRCRSAStampSetTypeSEL, L"FRCRSAStampSetType"},
	{FRCRSAStampSEL, FRCRSAStampSetEncodeSEL, L"FRCRSAStampSetEncode"},
	{FRCRSAStampSEL, FRCRSAStampSetSignListIdxSEL, L"FRCRSAStampSetSignListIdx"},
	{FRCRSAStampSEL, FRCRSAStampGetPDFStampSEL, L"FRCRSAStampGetPDFStamp"},
	{FRCRSAStampSEL, FRCRSAStampSaveStampToPageSEL, L"FRCRSAStampSaveStampToPage"},
	{FRCRSAStampSEL, FRCRSAStampGetSampInfoDicSEL, L"FRCRSAStampGetSampInfoDic"},
	{FRCRSAStampSEL, FRCRSAStampAddPageNameSEL, L"FRCRSAStampAddPageName"},
	{FRCRSAStampSEL, FRCRSAStampSetLeftValueSEL, L"FRCRSAStampSetLeftValue"},
	{FRCRSAStampSEL, FRCRSAStampSetTopValueSEL, L"FRCRSAStampSetTopValue"},
	{FRCRSAStampSEL, FRCRSAStampSetDynamicSEL, L"FRCRSAStampSetDynamic"},
	{FRCRSAStampSEL, FRCRSAStampSetFavoriteSEL, L"FRCRSAStampSetFavorite"},
	{FRCRSAStampSEL, FRCRSAStampGetTypeSEL, L"FRCRSAStampGetType"},
	{FRCRSAStampSEL, FRCRSAStampSetIsRotateSEL, L"FRCRSAStampSetIsRotate"},
	{FRCRSAStampSEL, FRCRSAStampCheckPDFPermissionSEL, L"FRCRSAStampCheckPDFPermission"},
	{FRCRSAStampSEL, FRCRSAStampFSFadeOutImageBackgroundSEL, L"FRCRSAStampFSFadeOutImageBackground"},
	{FRCRSAStampSEL, FRCRSAStampSetTipSEL, L"FRCRSAStampSetTip"},
	{FRCRSAStampSEL, FRCRSAStampSetTemplateNameSEL, L"FRCRSAStampSetTemplateName"},
	{FRCRSAStampSEL, FRCRSAStampSetThumbNailSEL, L"FRCRSAStampSetThumbNail"},
	{FRCRSAStampSEL, FRCRSAStampSetCanParserSEL, L"FRCRSAStampSetCanParser"},
	{FRCRSAStampSEL, FRCRSAStampSetImageSEL, L"FRCRSAStampSetImage"},
	{FRCRSAStampSEL, FRCRSAStampSetOpacitySEL, L"FRCRSAStampSetOpacity"},
	{FRCRSAStampSEL, FRCRSAStampGetSignFilePwdSEL, L"FRCRSAStampGetSignFilePwd"},
	{FRCRSAStampSEL, FRCRSAStampGetStampFormPageSEL, L"FRCRSAStampGetStampFormPage"},
	{FRCRSAStampSEL, FRCRSAStampSaveStampToPage2SEL, L"FRCRSAStampSaveStampToPage2"},
	{FRCRSAStampSEL, FRCRSAStampGetSignListIdxSEL, L"FRCRSAStampGetSignListIdx"},
	{FRCRSAStampSEL, FRCRSAStampSetStampGuidSEL, L"FRCRSAStampSetStampGuid"},
	{FRCRSAStampSEL, FRCRSAStampGetStampGuidSEL, L"FRCRSAStampGetStampGuid"},
	{FRMarkupAnnotSEL, FRMarkupAnnotCreateSEL, L"FRMarkupAnnotCreate"},
	{FRMarkupAnnotSEL, FRMarkupAnnotDestroySEL, L"FRMarkupAnnotDestroy"},
	{FRMarkupAnnotSEL, FRMarkupAnnotIsGroupSEL, L"FRMarkupAnnotIsGroup"},
	{FRMarkupAnnotSEL, FRMarkupAnnotIsHeaderSEL, L"FRMarkupAnnotIsHeader"},
	{FRMarkupAnnotSEL, FRMarkupAnnotGetPopupSEL, L"FRMarkupAnnotGetPopup"},
	{FRMarkupAnnotSEL, FRMarkupAnnotResetAppearanceSEL, L"FRMarkupAnnotResetAppearance"},
	{FRMarkupAnnotSEL, FRMarkupAnnotSetModifiedDateTimeSEL, L"FRMarkupAnnotSetModifiedDateTime"},
	{FRMarkupAnnotSEL, FRMarkupAnnotGetModifiedDateTimeSEL, L"FRMarkupAnnotGetModifiedDateTime"},
	{FRMarkupAnnotSEL, FRMarkupAnnotGetHotPointSEL, L"FRMarkupAnnotGetHotPoint"},
	{FRMarkupAnnotSEL, FRMarkupAnnotGetColorSEL, L"FRMarkupAnnotGetColor"},
	{FRMarkupAnnotSEL, FRMarkupAnnotMovedOutPageSEL, L"FRMarkupAnnotMovedOutPage"},
	{FRMarkupPopupSEL, FRMarkupPopupUpdateDataTimeSEL, L"FRMarkupPopupUpdateDataTime"},
	{FRMarkupPopupSEL, FRMarkupPopupSetNoteAnchorSEL, L"FRMarkupPopupSetNoteAnchor"},
	{FRMarkupPopupSEL, FRMarkupPopupShowRopeSEL, L"FRMarkupPopupShowRope"},
	{FRMarkupPopupSEL, FRMarkupPopupIsNoteVisibleSEL, L"FRMarkupPopupIsNoteVisible"},
	{FRMarkupPopupSEL, FRMarkupPopupUpdateNoteSEL, L"FRMarkupPopupUpdateNote"},
	{FRMarkupPopupSEL, FRMarkupPopupResetNotePositionSEL, L"FRMarkupPopupResetNotePosition"},
	{FRMarkupPopupSEL, FRMarkupPopupGetPopupAnnotSEL, L"FRMarkupPopupGetPopupAnnot"},
	{FRMarkupPopupSEL, FRMarkupPopupGetRectSEL, L"FRMarkupPopupGetRect"},
	{FRMarkupPopupSEL, FRMarkupPopupSetStateSEL, L"FRMarkupPopupSetState"},
	{FRMarkupPopupSEL, FRMarkupPopupShowNoteSEL, L"FRMarkupPopupShowNote"},
	{FRMarkupPopupSEL, FRMarkupPopupSetNoteFocusSEL, L"FRMarkupPopupSetNoteFocus"},
	{FRMarkupPopupSEL, FRMarkupPopupAddReplySEL, L"FRMarkupPopupAddReply"},
	{FRMarkupPanelSEL, FRMarkupPanelGetMarkupPanelSEL, L"FRMarkupPanelGetMarkupPanel"},
	{FRMarkupPanelSEL, FRMarkupPanelRefreshAnnotSEL, L"FRMarkupPanelRefreshAnnot"},
	{FRMarkupPanelSEL, FRMarkupPanelReloadAnnotsSEL, L"FRMarkupPanelReloadAnnots"},
	{FRMarkupPanelSEL, FRMarkupPanelAddAnnotSEL, L"FRMarkupPanelAddAnnot"},
	{FRMarkupPanelSEL, FRMarkupPanelSetFocusSEL, L"FRMarkupPanelSetFocus"},
	{FRMarkupPanelSEL, FRMarkupPanelUpdatePropertyBoxSEL, L"FRMarkupPanelUpdatePropertyBox"},
	{FRMarkupPanelSEL, FRMarkupPanelAddToCreateListSEL, L"FRMarkupPanelAddToCreateList"},
	{FRMarkupPanelSEL, FRMarkupPanelHideHintSEL, L"FRMarkupPanelHideHint"},
	{FRMarkupPanelSEL, FRMarkupPanelRemoveAnnotSEL, L"FRMarkupPanelRemoveAnnot"},
	{FRMarkupPanelSEL, FRMarkupPanelShowAnnotSEL, L"FRMarkupPanelShowAnnot"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotNewSEL, L"FRCRSASStampAnnotNew"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotDestroySEL, L"FRCRSASStampAnnotDestroy"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotSetStampSEL, L"FRCRSASStampAnnotSetStamp"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotAfterMovePagesSEL, L"FRCRSASStampAnnotAfterMovePages"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotResetAppearanceSEL, L"FRCRSASStampAnnotResetAppearance"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotSetColorSEL, L"FRCRSASStampAnnotSetColor"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotSetOpacitySEL, L"FRCRSASStampAnnotSetOpacity"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotSetCreationDateTimeSEL, L"FRCRSASStampAnnotSetCreationDateTime"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotGetModifiedDateTimeSEL, L"FRCRSASStampAnnotGetModifiedDateTime"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotGetPopupSEL, L"FRCRSASStampAnnotGetPopup"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotGetHotPointSEL, L"FRCRSASStampAnnotGetHotPoint"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotGetTypeSEL, L"FRCRSASStampAnnotGetType"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotIsGroupSEL, L"FRCRSASStampAnnotIsGroup"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotIsHeaderSEL, L"FRCRSASStampAnnotIsHeader"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotSetModifiedDateTimeSEL, L"FRCRSASStampAnnotSetModifiedDateTime"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotGetColorSEL, L"FRCRSASStampAnnotGetColor"},
	{FRCRSASStampAnnotSEL, FRCRSASStampAnnotGetReaderPageSEL, L"FRCRSASStampAnnotGetReaderPage"},
	{FREncryptPermissonSEL, FREncryptPermissonCreateEncryptPermissonSEL, L"FREncryptPermissonCreateEncryptPermisson"},
	{FREncryptPermissonSEL, FREncryptPermissonSetEncryptPermissonSEL, L"FREncryptPermissonSetEncryptPermisson"},
	{FREncryptPermissonSEL, FREncryptPermissonGetEncryptPermissonSEL, L"FREncryptPermissonGetEncryptPermisson"},
	{FREncryptPermissonSEL, FREncryptPermissonGetPropertyPermissonSEL, L"FREncryptPermissonGetPropertyPermisson"},
	{FREncryptPermissonSEL, FREncryptPermissonGetAllPermissionSEL, L"FREncryptPermissonGetAllPermission"},
	{FREncryptPermissonSEL, FREncryptPermissonDeleteEncryptPermissionSEL, L"FREncryptPermissonDeleteEncryptPermission"},
	{FRCSGCertFileManageSEL, FRCSGCertFileManageCreateCertFileManageSEL, L"FRCSGCertFileManageCreateCertFileManage"},
	{FRCSGCertFileManageSEL, FRCSGCertFileManageDestroySEL, L"FRCSGCertFileManageDestroy"},
	{FRCSGCertFileManageSEL, FRCSGCertFileManageGetCertFileStorePathSEL, L"FRCSGCertFileManageGetCertFileStorePath"},
	{FRCSGCertFileManageSEL, FRCSGCertFileManageNewCertDataSEL, L"FRCSGCertFileManageNewCertData"},
	{FRCSGCertFileManageSEL, FRCSGCertFileManageLoadStoreSEL, L"FRCSGCertFileManageLoadStore"},
	{FRCSGCertFileManageSEL, FRCSGCertFileManageGetPathAndPasswordSEL, L"FRCSGCertFileManageGetPathAndPassword"},
	{FRCSGCertFileManageSEL, FRCSGCertFileManageUpdateFileSEL, L"FRCSGCertFileManageUpdateFile"},
	{FRCSGCertFileManageSEL, FRCSGCertFileManageBase64ToStringSEL, L"FRCSGCertFileManageBase64ToString"},
	{FRCSGCertFileManageSEL, FRCSGCertFileManageStringToBase64SEL, L"FRCSGCertFileManageStringToBase64"},
	{FRCSGCertFileManageSEL, FRCSGCertFileManageReloadAllFileSEL, L"FRCSGCertFileManageReloadAllFile"},
	{FRCSGSEL, FRCSGCreateSEL, L"FRCSGCreate"},
	{FRCSGSEL, FRCSGDestroySEL, L"FRCSGDestroy"},
	{FRCSGSEL, FRCSGCreateCertSEL, L"FRCSGCreateCert"},
	{FRCSGSEL, FRCSGGetTmpNameSEL, L"FRCSGGetTmpName"},
	{FRCSGSEL, FRCSGOpenPFXStoreSEL, L"FRCSGOpenPFXStore"},
	{FRCSGSEL, FRCSGCreateOpenSSLCertSEL, L"FRCSGCreateOpenSSLCert"},
	{FRPageSEL, FRPageGetDocumentSEL, L"FRPageGetDocument"},
	{FRPageSEL, FRPageGetPageSEL, L"FRPageGetPage"},
	{FRPageSEL, FRPageParsePageSEL, L"FRPageParsePage"},
	{FRPageSEL, FRPageGetDynPDFPageSEL, L"FRPageGetDynPDFPage"},
	{FRPageSEL, FRPageGetPageIndexSEL, L"FRPageGetPageIndex"},
	{FRPageSEL, FRPageIsPDFPageLoadedSEL, L"FRPageIsPDFPageLoaded"},
	{FRPageSEL, FRPageAddAnnotSEL, L"FRPageAddAnnot"},
	{FRPageSEL, FRPageAddAnnot2SEL, L"FRPageAddAnnot2"},
	{FRPageSEL, FRPageAddAnnot3SEL, L"FRPageAddAnnot3"},
	{FRPageSEL, FRPageAddDynXFAPDFAnnotSEL, L"FRPageAddDynXFAPDFAnnot"},
	{FRPageSEL, FRPageDeleteAnnotSEL, L"FRPageDeleteAnnot"},
	{FRPageSEL, FRPageMoveAnnotSEL, L"FRPageMoveAnnot"},
	{FRPageSEL, FRPageCountAnnotsSEL, L"FRPageCountAnnots"},
	{FRPageSEL, FRPageGetAnnotSEL, L"FRPageGetAnnot"},
	{FRPageSEL, FRPageGetAnnotByDictSEL, L"FRPageGetAnnotByDict"},
	{FRPageSEL, FRPageIsValidAnnotSEL, L"FRPageIsValidAnnot"},
	{FRPageSEL, FRPageGetAnnotDataListSEL, L"FRPageGetAnnotDataList"},
	{FRPageSEL, FRPageGetAnnotListSEL, L"FRPageGetAnnotList"},
	{FRPageSEL, FRPageGetFocusAnnotSEL, L"FRPageGetFocusAnnot"},
	{FRPageSEL, FRPageSetFocusAnnotSEL, L"FRPageSetFocusAnnot"},
	{FRPageSEL, FRPageGetPageFirstAnnotSEL, L"FRPageGetPageFirstAnnot"},
	{FRPageSEL, FRPageGetPageLastAnnotSEL, L"FRPageGetPageLastAnnot"},
	{FRPageSEL, FRPageGetPagePriorAnnotSEL, L"FRPageGetPagePriorAnnot"},
	{FRPageSEL, FRPageGetPageNextAnnotSEL, L"FRPageGetPageNextAnnot"},
	{FRPageSEL, FRPageCountViewsSEL, L"FRPageCountViews"},
	{FRPageSEL, FRPageGetViewSEL, L"FRPageGetView"},
	{FRPageSEL, FRPageIsValidViewSEL, L"FRPageIsValidView"},
	{FRPageSEL, FRPageGetView2SEL, L"FRPageGetView2"},
	{FRPageSEL, FRPageUpdateAllViewsSEL, L"FRPageUpdateAllViews"},
	{FRPageSEL, FRPageUpdateViewSEL, L"FRPageUpdateView"},
	{FRPageSEL, FRPageUpdateAllViews2SEL, L"FRPageUpdateAllViews2"},
	{FRPageSEL, FRPageLockPageSEL, L"FRPageLockPage"},
	{FRPageSEL, FRPageUnLockPageSEL, L"FRPageUnLockPage"},
	{FRPageSEL, FRPageIsLockedSEL, L"FRPageIsLocked"},
	{FRPageSEL, FRPageIsParsedSEL, L"FRPageIsParsed"},
	{FRPageSEL, FRPageGetPageTabOrderSEL, L"FRPageGetPageTabOrder"},
	{FRPageSEL, FRPageSetPageTabOrderSEL, L"FRPageSetPageTabOrder"},
	{FRPageSEL, FRPageInsertWidgetTabOrderSEL, L"FRPageInsertWidgetTabOrder"},
	{FRPageSEL, FRPageSetContentModificationSEL, L"FRPageSetContentModification"},
	{FRPageSEL, FRPageGenerateContentSEL, L"FRPageGenerateContent"},
	{FRPageSEL, FRPageGetXFAPageSEL, L"FRPageGetXFAPage"},
	{FRPageSEL, FRPageGetAnnotByXFAWidgetSEL, L"FRPageGetAnnotByXFAWidget"},
	{FRPageSEL, FRPageRefreshXFAPageViewSEL, L"FRPageRefreshXFAPageView"},
	{FRPageSEL, FRPageSetMergeTextFlagSEL, L"FRPageSetMergeTextFlag"},
	{FRPageSEL, FRPageClearContentModificationSEL, L"FRPageClearContentModification"},
	{FRPageSEL, FRPageResetPageAnnotsSEL, L"FRPageResetPageAnnots"},
	{FRIBAAnnotFillerSEL, FRIBAAnnotFillerNewSEL, L"FRIBAAnnotFillerNew"},
	{FRIBAAnnotFillerSEL, FRIBAAnnotFillerDestroySEL, L"FRIBAAnnotFillerDestroy"},
	{FRIBAAnnotDesignerSEL, FRIBAAnnotDesignerNewSEL, L"FRIBAAnnotDesignerNew"},
	{FRIBAAnnotDesignerSEL, FRIBAAnnotDesignerDestroySEL, L"FRIBAAnnotDesignerDestroy"},
	{FRCBFInterFormSEL, FRCBFInterFormGetDocumentSEL, L"FRCBFInterFormGetDocument"},
	{FRCBFInterFormSEL, FRCBFInterFormGetWidgetSEL, L"FRCBFInterFormGetWidget"},
	{FRCBFInterFormSEL, FRCBFInterFormRemoveMapSEL, L"FRCBFInterFormRemoveMap"},
	{FRCBFInterFormSEL, FRCBFInterFormGetReaderInterFormSEL, L"FRCBFInterFormGetReaderInterForm"},
	{FRBFFormNotifySEL, FRBFFormNotifyNewSEL, L"FRBFFormNotifyNew"},
	{FRBFFormNotifySEL, FRBFFormNotifyDestroySEL, L"FRBFFormNotifyDestroy"},
	{FRBFAnnotHandlerSEL, FRBFAnnotHandlerNewSEL, L"FRBFAnnotHandlerNew"},
	{FRBFAnnotHandlerSEL, FRBFAnnotHandlerDestroySEL, L"FRBFAnnotHandlerDestroy"},
	{FRBaseFormSEL, FRBaseFormGetBaseFormSEL, L"FRBaseFormGetBaseForm"},
	{FRBaseFormSEL, FRBaseFormBeginTabOrderDesignSEL, L"FRBaseFormBeginTabOrderDesign"},
	{FRBaseFormSEL, FRBaseFormEndTabOrderDesignSEL, L"FRBaseFormEndTabOrderDesign"},
	{FRBaseFormSEL, FRBaseFormShowTabOrderSEL, L"FRBaseFormShowTabOrder"},
	{FRBaseFormSEL, FRBaseFormSetFormFillerSEL, L"FRBaseFormSetFormFiller"},
	{FRBaseFormSEL, FRBaseFormSetSignatureFillerSEL, L"FRBaseFormSetSignatureFiller"},
	{FRBaseFormSEL, FRBaseFormGetFillerByAnnotSEL, L"FRBaseFormGetFillerByAnnot"},
	{FRBaseFormSEL, FRBaseFormSetFormDesignerSEL, L"FRBaseFormSetFormDesigner"},
	{FRBaseFormSEL, FRBaseFormSetSignatureHandlerSEL, L"FRBaseFormSetSignatureHandler"},
	{FRBaseFormSEL, FRBaseFormSetXFASignatureHandlerSEL, L"FRBaseFormSetXFASignatureHandler"},
	{FRBaseFormSEL, FRBaseFormGetXFASignatureHandlerSEL, L"FRBaseFormGetXFASignatureHandler"},
	{FRBaseFormSEL, FRBaseFormIsHighLightSEL, L"FRBaseFormIsHighLight"},
	{FRBaseFormSEL, FRBaseFormSetHighLightSEL, L"FRBaseFormSetHighLight"},
	{FRBaseFormSEL, FRBaseFormSetHighLightColorSEL, L"FRBaseFormSetHighLightColor"},
	{FRBaseFormSEL, FRBaseFormGetHighLightColorSEL, L"FRBaseFormGetHighLightColor"},
	{FRBaseFormSEL, FRBaseFormGetRequiredColorSEL, L"FRBaseFormGetRequiredColor"},
	{FRBaseFormSEL, FRBaseFormIsFormDesignerAssistEnabledSEL, L"FRBaseFormIsFormDesignerAssistEnabled"},
	{FRBaseFormSEL, FRBaseFormSetFormDesignerAssistEnabledSEL, L"FRBaseFormSetFormDesignerAssistEnabled"},
	{FRBaseFormSEL, FRBaseFormGetAutoCompleteChoiceSEL, L"FRBaseFormGetAutoCompleteChoice"},
	{FRBaseFormSEL, FRBaseFormIsOpenPropertyAfterCreateSEL, L"FRBaseFormIsOpenPropertyAfterCreate"},
	{FRBaseFormSEL, FRBaseFormShowFocusRectSEL, L"FRBaseFormShowFocusRect"},
	{FRBaseFormSEL, FRBaseFormShowOverflowIndicatorSEL, L"FRBaseFormShowOverflowIndicator"},
	{FRBaseFormSEL, FRBaseFormIsNumericalDataEnableSEL, L"FRBaseFormIsNumericalDataEnable"},
	{FRBaseFormSEL, FRBaseFormSetFormNotifySEL, L"FRBaseFormSetFormNotify"},
	{FRBaseFormSEL, FRBaseFormCollectAPStreamRefCountSEL, L"FRBaseFormCollectAPStreamRefCount"},
	{FRBaseFormSEL, FRBaseFormClearAPStreamRefCountSEL, L"FRBaseFormClearAPStreamRefCount"},
	{FRBaseFormSEL, FRBaseFormGetAPStreamRefCountSEL, L"FRBaseFormGetAPStreamRefCount"},
	{FRBaseFormSEL, FRBaseFormShowSEL, L"FRBaseFormShow"},
	{FRBaseFormSEL, FRBaseFormSetWidgetMsgHookSEL, L"FRBaseFormSetWidgetMsgHook"},
	{FRBaseFormSEL, FRBaseFormGetWidgetMsgHookSEL, L"FRBaseFormGetWidgetMsgHook"},
	{FRIFormDesignerNotifySEL, FRIFormDesignerNotifyNewSEL, L"FRIFormDesignerNotifyNew"},
	{FRIFormDesignerNotifySEL, FRIFormDesignerNotifyDestroySEL, L"FRIFormDesignerNotifyDestroy"},
	{FRCBFWidgetSEL, FRCBFWidgetResetAppearanceSEL, L"FRCBFWidgetResetAppearance"},
	{FRCBFWidgetSEL, FRCBFWidgetIsAppearanceValidSEL, L"FRCBFWidgetIsAppearanceValid"},
	{FRCBFWidgetSEL, FRCBFWidgetGetFieldTypeSEL, L"FRCBFWidgetGetFieldType"},
	{FRCBFWidgetSEL, FRCBFWidgetGetFieldFlagsSEL, L"FRCBFWidgetGetFieldFlags"},
	{FRCBFWidgetSEL, FRCBFWidgetGetRotateSEL, L"FRCBFWidgetGetRotate"},
	{FRCBFWidgetSEL, FRCBFWidgetGetTextColorSEL, L"FRCBFWidgetGetTextColor"},
	{FRCBFWidgetSEL, FRCBFWidgetGetFontSEL, L"FRCBFWidgetGetFont"},
	{FRCBFWidgetSEL, FRCBFWidgetGetBaseFontSEL, L"FRCBFWidgetGetBaseFont"},
	{FRCBFWidgetSEL, FRCBFWidgetIsReadOnlySEL, L"FRCBFWidgetIsReadOnly"},
	{FRCBFWidgetSEL, FRCBFWidgetIsVisibleSEL, L"FRCBFWidgetIsVisible"},
	{FRCBFWidgetSEL, FRCBFWidgetSetRectSEL, L"FRCBFWidgetSetRect"},
	{FRCBFWidgetSEL, FRCBFWidgetGetRectSEL, L"FRCBFWidgetGetRect"},
	{FRCBFWidgetSEL, FRCBFWidgetClearCachedAPSEL, L"FRCBFWidgetClearCachedAP"},
	{FRCBFWidgetSEL, FRCBFWidgetDrawAppearanceSEL, L"FRCBFWidgetDrawAppearance"},
	{FRCBFWidgetSEL, FRCBFWidgetResetAppearance2SEL, L"FRCBFWidgetResetAppearance2"},
	{FRCBFWidgetSEL, FRCBFWidgetHideHintSEL, L"FRCBFWidgetHideHint"},
	{FRCBFWidgetSEL, FRCBFWidgetShowHintSEL, L"FRCBFWidgetShowHint"},
	{FRCBFWidgetSEL, FRCBFWidgetGetFormControlSEL, L"FRCBFWidgetGetFormControl"},
	{FRCBFWidgetSEL, FRCBFWidgetOnFormatSEL, L"FRCBFWidgetOnFormat"},
	{FRCBFWidgetSEL, FRCBFWidgetGetInterFormSEL, L"FRCBFWidgetGetInterForm"},
	{FRCBFWidgetSEL, FRCBFWidgetGetAnnotDictSEL, L"FRCBFWidgetGetAnnotDict"},
	{FRCBFWidgetSEL, FRCBFWidgetGetNameSEL, L"FRCBFWidgetGetName"},
	{FRCBFWidgetSEL, FRCBFWidgetSetRotateSEL, L"FRCBFWidgetSetRotate"},
	{FRCBFWidgetSEL, FRCBFWidgetGetIReaderAnnotSEL, L"FRCBFWidgetGetIReaderAnnot"},
	{FRCBFWidgetSEL, FRCBFWidgetSetNameSEL, L"FRCBFWidgetSetName"},
	{FRCBFWidgetSEL, FRCBFWidgetHasAActionSEL, L"FRCBFWidgetHasAAction"},
	{FRCBFWidgetSEL, FRCBFWidgetOnAActionSEL, L"FRCBFWidgetOnAAction"},
	{FRCBFWidgetSEL, FRCBFWidgetDrawShadowSEL, L"FRCBFWidgetDrawShadow"},
	{FRCBFWidgetSEL, FRCBFWidgetGetMixXFAWidgetSEL, L"FRCBFWidgetGetMixXFAWidget"},
	{FRCBFWidgetSEL, FRCBFWidgetDrawCustomShadowSEL, L"FRCBFWidgetDrawCustomShadow"},
	{FRIBFSimpleFromPropertiesSEL, FRIBFSimpleFromPropertiesIsVisibleSEL, L"FRIBFSimpleFromPropertiesIsVisible"},
	{FRIBFSimpleFromPropertiesSEL, FRIBFSimpleFromPropertiesShowSEL, L"FRIBFSimpleFromPropertiesShow"},
	{FRIBFSimpleFromPropertiesSEL, FRIBFSimpleFromPropertiesHideSEL, L"FRIBFSimpleFromPropertiesHide"},
	{FRSGRDNSEL, FRSGRDNCreateSEL, L"FRSGRDNCreate"},
	{FRSGRDNSEL, FRSGRDNDestroySEL, L"FRSGRDNDestroy"},
	{FRSGRDNSEL, FRSGRDNSetcwCSEL, L"FRSGRDNSetcwC"},
	{FRSGRDNSEL, FRSGRDNGetcwCSEL, L"FRSGRDNGetcwC"},
	{FRSGRDNSEL, FRSGRDNSetcwCNSEL, L"FRSGRDNSetcwCN"},
	{FRSGRDNSEL, FRSGRDNGetcwCNSEL, L"FRSGRDNGetcwCN"},
	{FRSGRDNSEL, FRSGRDNSetcwESEL, L"FRSGRDNSetcwE"},
	{FRSGRDNSEL, FRSGRDNGetcwESEL, L"FRSGRDNGetcwE"},
	{FRSGRDNSEL, FRSGRDNSetcwLSEL, L"FRSGRDNSetcwL"},
	{FRSGRDNSEL, FRSGRDNGetcwLSEL, L"FRSGRDNGetcwL"},
	{FRSGRDNSEL, FRSGRDNSetcwOSEL, L"FRSGRDNSetcwO"},
	{FRSGRDNSEL, FRSGRDNGetcwOSEL, L"FRSGRDNGetcwO"},
	{FRSGRDNSEL, FRSGRDNSetcwOUSEL, L"FRSGRDNSetcwOU"},
	{FRSGRDNSEL, FRSGRDNGetcwOUSEL, L"FRSGRDNGetcwOU"},
	{FRSGRDNSEL, FRSGRDNSetcwSTSEL, L"FRSGRDNSetcwST"},
	{FRSGRDNSEL, FRSGRDNGetcwSTSEL, L"FRSGRDNGetcwST"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATECreateSEL, L"FRSGCERTIFICATECreate"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATEDestroySEL, L"FRSGCERTIFICATEDestroy"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATESetFlagsSEL, L"FRSGCERTIFICATESetFlags"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATEGetFlagsSEL, L"FRSGCERTIFICATEGetFlags"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATESetIssuersArrSEL, L"FRSGCERTIFICATESetIssuersArr"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATEGetIssuersArrSEL, L"FRSGCERTIFICATEGetIssuersArr"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATESetKeyUsageArrSEL, L"FRSGCERTIFICATESetKeyUsageArr"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATEGetKeyUsageArrSEL, L"FRSGCERTIFICATEGetKeyUsageArr"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATESetOidArrSEL, L"FRSGCERTIFICATESetOidArr"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATEGetOidArrSEL, L"FRSGCERTIFICATEGetOidArr"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATESetSubjectDNArrSEL, L"FRSGCERTIFICATESetSubjectDNArr"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATEGetSubjectDNArrSEL, L"FRSGCERTIFICATEGetSubjectDNArr"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATESetUrlSEL, L"FRSGCERTIFICATESetUrl"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATEGetUrlSEL, L"FRSGCERTIFICATEGetUrl"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATESetUrlTypeSEL, L"FRSGCERTIFICATESetUrlType"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATEGetUrlTypeSEL, L"FRSGCERTIFICATEGetUrlType"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATESetSubjectArrSEL, L"FRSGCERTIFICATESetSubjectArr"},
	{FRSGCERTIFICATESEL, FRSGCERTIFICATEGetSubjectArrSEL, L"FRSGCERTIFICATEGetSubjectArr"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUECreateSEL, L"FRSGSEEDVALUECreate"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEDestroySEL, L"FRSGSEEDVALUEDestroy"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEGetCertInfoSEL, L"FRSGSEEDVALUEGetCertInfo"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUESetDigestMethodArrSEL, L"FRSGSEEDVALUESetDigestMethodArr"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEGetDigestMethodArrSEL, L"FRSGSEEDVALUEGetDigestMethodArr"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUESetFilterSEL, L"FRSGSEEDVALUESetFilter"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEGetFilterSEL, L"FRSGSEEDVALUEGetFilter"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUESetFlagsSEL, L"FRSGSEEDVALUESetFlags"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEGetFlagsSEL, L"FRSGSEEDVALUEGetFlags"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUESetlegalAttestationsArrSEL, L"FRSGSEEDVALUESetlegalAttestationsArr"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEGetlegalAttestationsArrSEL, L"FRSGSEEDVALUEGetlegalAttestationsArr"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUESetmdpSEL, L"FRSGSEEDVALUESetmdp"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEGetmdpSEL, L"FRSGSEEDVALUEGetmdp"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUESetReasonArrSEL, L"FRSGSEEDVALUESetReasonArr"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEGetReasonArrSEL, L"FRSGSEEDVALUEGetReasonArr"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUESetbAddRevInfoSEL, L"FRSGSEEDVALUESetbAddRevInfo"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEGetbAddRevInfoSEL, L"FRSGSEEDVALUEGetbAddRevInfo"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUESetSubFilterArrSEL, L"FRSGSEEDVALUESetSubFilterArr"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEGetSubFilterArrSEL, L"FRSGSEEDVALUEGetSubFilterArr"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUESetVersionSEL, L"FRSGSEEDVALUESetVersion"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEGetVersionSEL, L"FRSGSEEDVALUEGetVersion"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUESettimeStampspecSEL, L"FRSGSEEDVALUESettimeStampspec"},
	{FRSGSEEDVALUESEL, FRSGSEEDVALUEGettimeStampspecSEL, L"FRSGSEEDVALUEGettimeStampspec"},
	{FRSGBaseHandlerSEL, FRSGBaseHandlerNewSEL, L"FRSGBaseHandlerNew"},
	{FRSGBaseHandlerSEL, FRSGBaseHandlerDestroySEL, L"FRSGBaseHandlerDestroy"},
	{FRIClipBoardSEL, FRIClipBoardGetClipboardSEL, L"FRIClipBoardGetClipboard"},
	{FRIClipBoardSEL, FRIClipBoardRemoveElementSEL, L"FRIClipBoardRemoveElement"},
	{FRIClipBoardSEL, FRIClipBoardInitialSEL, L"FRIClipBoardInitial"},
	{FRIClipBoardSEL, FRIClipBoardReleaseSEL, L"FRIClipBoardRelease"},
	{FRIClipBoardSEL, FRIClipBoardGetElementCountsSEL, L"FRIClipBoardGetElementCounts"},
	{FRIClipBoardSEL, FRIClipBoardGetElementSEL, L"FRIClipBoardGetElement"},
	{FRIClipBoardSEL, FRIClipBoardAddElementSEL, L"FRIClipBoardAddElement"},
	{FRIClipBoardSEL, FRIClipBoardGetMD5SEL, L"FRIClipBoardGetMD5"},
	{FRIClipBoardSEL, FRIClipBoardGetTypeSEL, L"FRIClipBoardGetType"},
	{FRIClipBoardSEL, FRIClipBoardGetSubtypeSEL, L"FRIClipBoardGetSubtype"},
	{FRIClipBoardSEL, FRIClipBoardGetRectSEL, L"FRIClipBoardGetRect"},
	{FRIClipBoardSEL, FRIClipBoardExportToXMLSEL, L"FRIClipBoardExportToXML"},
	{FRIClipBoardSEL, FRIClipBoardImportFromXMLSEL, L"FRIClipBoardImportFromXML"},
	{FRCCBAnnotationSEL, FRCCBAnnotationDeleteSEL, L"FRCCBAnnotationDelete"},
	{FRCCBAnnotationSEL, FRCCBAnnotationParseToXMLSEL, L"FRCCBAnnotationParseToXML"},
	{FRCCBAnnotationSEL, FRCCBAnnotationParseToDictSEL, L"FRCCBAnnotationParseToDict"},
	{FRCCBAnnotationSEL, FRCCBAnnotationIsKeyNeeded_ToXMLSEL, L"FRCCBAnnotationIsKeyNeeded_ToXML"},
	{FRCCBAnnotationSEL, FRCCBAnnotationIsKeyNeeded_ToDictSEL, L"FRCCBAnnotationIsKeyNeeded_ToDict"},
	{FRCCBAnnotationSEL, FRCCBAnnotationAddNecessaryKeyToList_ToXMLSEL, L"FRCCBAnnotationAddNecessaryKeyToList_ToXML"},
	{FRCCBAnnotationSEL, FRCCBAnnotationNewSEL, L"FRCCBAnnotationNew"},
	{FRCJavaScriptEditerSEL, FRCJavaScriptEditerIsUseExternalJSEditorSEL, L"FRCJavaScriptEditerIsUseExternalJSEditor"},
	{FRCJavaScriptEditerSEL, FRCJavaScriptEditerEditWithGlobalWndSEL, L"FRCJavaScriptEditerEditWithGlobalWnd"},
	{FRCJavaScriptEditerSEL, FRCJavaScriptEditerEditWithExternalJSEditorSEL, L"FRCJavaScriptEditerEditWithExternalJSEditor"},
	{FRIBAImageSourceSEL, FRIBAImageSourceNewIBAImageSourceSEL, L"FRIBAImageSourceNewIBAImageSource"},
	{FRIBAImageSourceSEL, FRIBAImageSourceDestroyImageSourceSEL, L"FRIBAImageSourceDestroyImageSource"},
	{FRCBAFigureRecognitionSEL, FRCBAFigureRecognitionNewCBAFigureRecognitionSEL, L"FRCBAFigureRecognitionNewCBAFigureRecognition"},
	{FRCBAFigureRecognitionSEL, FRCBAFigureRecognitionDestroyCBA_FigureRecognitionSEL, L"FRCBAFigureRecognitionDestroyCBA_FigureRecognition"},
	{FRCBAFigureRecognitionSEL, FRCBAFigureRecognitionSetColorSourceSEL, L"FRCBAFigureRecognitionSetColorSource"},
	{FRCBAFigureRecognitionSEL, FRCBAFigureRecognitionFindRectBy4PointSEL, L"FRCBAFigureRecognitionFindRectBy4Point"},
	{FRAnnotObserverSEL, FRAnnotObserverCreateAnnotObserverSEL, L"FRAnnotObserverCreateAnnotObserver"},
	{FRAnnotObserverSEL, FRAnnotObserverDestroyAnnotObserverSEL, L"FRAnnotObserverDestroyAnnotObserver"},
	{FRAnnotObserverSEL, FRAnnotObserverIsValidSEL, L"FRAnnotObserverIsValid"},
	{FRAnnotObserverSEL, FRAnnotObserverGetAnnotObjSEL, L"FRAnnotObserverGetAnnotObj"},
	{FRDocumentObserverSEL, FRDocumentObserverCreateDocumentObserverSEL, L"FRDocumentObserverCreateDocumentObserver"},
	{FRDocumentObserverSEL, FRDocumentObserverDestroyDocumentObserverSEL, L"FRDocumentObserverDestroyDocumentObserver"},
	{FRDocumentObserverSEL, FRDocumentObserverIsValidSEL, L"FRDocumentObserverIsValid"},
	{FRDocumentObserverSEL, FRDocumentObserverGetDocumentObjSEL, L"FRDocumentObserverGetDocumentObj"},
	{FRInnerContentProviderSEL, FRInnerContentProviderGetInnerContentProviderSEL, L"FRInnerContentProviderGetInnerContentProvider"},
	{FRInnerContentProviderSEL, FRInnerContentProviderOnGetContentSizeSEL, L"FRInnerContentProviderOnGetContentSize"},
	{FRInnerContentProviderSEL, FRInnerContentProviderOnReadContentSEL, L"FRInnerContentProviderOnReadContent"},
	{FRInnerContentProviderSEL, FRInnerContentProviderOnBackFillContentSEL, L"FRInnerContentProviderOnBackFillContent"},
	{FRInnerContentProviderSEL, FRInnerContentProviderOnGetAppPermissionsSEL, L"FRInnerContentProviderOnGetAppPermissions"},
	{FRInnerContentProviderSEL, FRInnerContentProviderOnGetAttachmentSizeSEL, L"FRInnerContentProviderOnGetAttachmentSize"},
	{FRInnerContentProviderSEL, FRInnerContentProviderOnReadAttachmentContentSEL, L"FRInnerContentProviderOnReadAttachmentContent"},
	{FRIFXPDFAInterfaceSEL, FRIFXPDFAInterfaceGetIFXPDFAInterfaceSEL, L"FRIFXPDFAInterfaceGetIFXPDFAInterface"},
	{FRIFXPDFAInterfaceSEL, FRIFXPDFAInterfaceSimplePDFACheckSEL, L"FRIFXPDFAInterfaceSimplePDFACheck"},
	{FRIFXPDFAInterfaceSEL, FRIFXPDFAInterfacePDFACheckIsClickEditingSEL, L"FRIFXPDFAInterfacePDFACheckIsClickEditing"},
	{FRIFXPDFAInterfaceSEL, FRIFXPDFAInterfaceShowPreflightWndSEL, L"FRIFXPDFAInterfaceShowPreflightWnd"},
	{FRIFXPDFAInterfaceSEL, FRIFXPDFAInterfaceGetPreflightWndShowSEL, L"FRIFXPDFAInterfaceGetPreflightWndShow"},
	{FRIConvertToPDFSEL, FRIConvertToPDFGetFileTypeSEL, L"FRIConvertToPDFGetFileType"},
	{FRIConvertToPDFSEL, FRIConvertToPDFGetFileFilterSEL, L"FRIConvertToPDFGetFileFilter"},
	{FRIConvertToPDFSEL, FRIConvertToPDFConvertToPDFSEL, L"FRIConvertToPDFConvertToPDF"},
	{FRITagePDFSEL, FRITagePDFClearAllDataSEL, L"FRITagePDFClearAllData"},
	{FRITagePDFSEL, FRITagePDFTryRebuildPanelSEL, L"FRITagePDFTryRebuildPanel"},
	{FRITagePDFSEL, FRITagePDFAsyncUpdateCheckerInfoSEL, L"FRITagePDFAsyncUpdateCheckerInfo"},
	{FRTextPageSEL, FRTextPageGetReaderTextPageSEL, L"FRTextPageGetReaderTextPage"},
	{FRTextPageSEL, FRTextPageReParseTextPageSEL, L"FRTextPageReParseTextPage"},
	{FRTextPageSEL, FRTextPageCreateFRTextPageSEL, L"FRTextPageCreateFRTextPage"},
	{FRISignatureCheckSEL, FRISignatureCheckNewSEL, L"FRISignatureCheckNew"},
	{FRISignatureCheckSEL, FRISignatureCheckDestroySEL, L"FRISignatureCheckDestroy"},
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
	{FRSystemHandlerSEL, FRSystemHandlerIsStandardFontSEL, L"FRSystemHandlerIsStandardFont"},
	{FRSystemHandlerSEL, FRSystemHandlerGetDefaultFontNameByCharsetSEL, L"FRSystemHandlerGetDefaultFontNameByCharset"},
	{FRSystemHandlerSEL, FRSystemHandlerGetFullNameSEL, L"FRSystemHandlerGetFullName"},
	{FRSystemHandlerSEL, FRSystemHandlerGetNativeTrueTypeFontSEL, L"FRSystemHandlerGetNativeTrueTypeFont"},
	{FRSystemHandlerSEL, FRSystemHandlerFindNativeTrueTypeFontSEL, L"FRSystemHandlerFindNativeTrueTypeFont"},
	{FRSystemHandlerSEL, FRSystemHandlerGetFontCharsetSEL, L"FRSystemHandlerGetFontCharset"},
	{FRSystemHandlerSEL, FRSystemHandlerConvertToFWLVitrualKeyCodeSEL, L"FRSystemHandlerConvertToFWLVitrualKeyCode"},
	{FRSystemHandlerSEL, FRSystemHandlerCreatePopupMenuSEL, L"FRSystemHandlerCreatePopupMenu"},
	{FRSystemHandlerSEL, FRSystemHandlerAppendMenuItemSEL, L"FRSystemHandlerAppendMenuItem"},
	{FRSystemHandlerSEL, FRSystemHandlerEnableMenuItemSEL, L"FRSystemHandlerEnableMenuItem"},
	{FRSystemHandlerSEL, FRSystemHandlerTrackPopupMenuSEL, L"FRSystemHandlerTrackPopupMenu"},
	{FRSystemHandlerSEL, FRSystemHandlerDestroyMenuSEL, L"FRSystemHandlerDestroyMenu"},
	{FRSystemHandlerSEL, FRSystemHandlerCreatePopupSubMenuSEL, L"FRSystemHandlerCreatePopupSubMenu"},
	{FRSystemHandlerSEL, FRSystemHandlerAppendSubMenuSEL, L"FRSystemHandlerAppendSubMenu"},
	{FRSystemHandlerSEL, FRSystemHandlerSetCursorSEL, L"FRSystemHandlerSetCursor"},
	{FRSystemHandlerSEL, FRSystemHandlerSetCustomCursorHandlerSEL, L"FRSystemHandlerSetCustomCursorHandler"},
	{FRCTBLogFontsSEL, FRCTBLogFontsNewSEL, L"FRCTBLogFontsNew"},
	{FRCTBLogFontsSEL, FRCTBLogFontsDestroySEL, L"FRCTBLogFontsDestroy"},
	{FRCTBLogFontsSEL, FRCTBLogFontsGetSizeSEL, L"FRCTBLogFontsGetSize"},
	{FRCTBLogFontsSEL, FRCTBLogFontsGetAtSEL, L"FRCTBLogFontsGetAt"},
	{FRCTBLogFontsSEL, FRCTBLogFontsAddSEL, L"FRCTBLogFontsAdd"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATACreateSEL, L"FRTBSYSFONTDATACreate"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATADestroySEL, L"FRTBSYSFONTDATADestroy"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATASetFaceNameSEL, L"FRTBSYSFONTDATASetFaceName"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATAGetFaceNameSEL, L"FRTBSYSFONTDATAGetFaceName"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATASetScriptNameSEL, L"FRTBSYSFONTDATASetScriptName"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATAGetScriptNameSEL, L"FRTBSYSFONTDATAGetScriptName"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATASetTagNameSEL, L"FRTBSYSFONTDATASetTagName"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATAGetTagNameSEL, L"FRTBSYSFONTDATAGetTagName"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATASetFullNameSEL, L"FRTBSYSFONTDATASetFullName"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATAGetFullNameSEL, L"FRTBSYSFONTDATAGetFullName"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATASetPSNameSEL, L"FRTBSYSFONTDATASetPSName"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATAGetPSNameSEL, L"FRTBSYSFONTDATAGetPSName"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATASetNamesArrSEL, L"FRTBSYSFONTDATASetNamesArr"},
	{FRTBSYSFONTDATASEL, FRTBSYSFONTDATAGetNamesArrSEL, L"FRTBSYSFONTDATAGetNamesArr"},
	{FRITBSysFontSEL, FRITBSysFontGetSysFontObjectSEL, L"FRITBSysFontGetSysFontObject"},
	{FRITBSysFontSEL, FRITBSysFontLoadLogFontsSEL, L"FRITBSysFontLoadLogFonts"},
	{FRITBSysFontSEL, FRITBSysFontGetSysFontFaceNameSEL, L"FRITBSysFontGetSysFontFaceName"},
	{FRITBSysFontSEL, FRITBSysFontGetAllFormatFontSizeSEL, L"FRITBSysFontGetAllFormatFontSize"},
	{FRITBSysFontSEL, FRITBSysFontGetAtAllFormatFontSEL, L"FRITBSysFontGetAtAllFormatFont"},
	{FRITBSysFontSEL, FRITBSysFontGetFontFaceNameBoldItalicSEL, L"FRITBSysFontGetFontFaceNameBoldItalic"},
	{FRITBSysFontSEL, FRITBSysFontGetStdFontSizeSEL, L"FRITBSysFontGetStdFontSize"},
	{FRITBSysFontSEL, FRITBSysFontGetAtStdFontSEL, L"FRITBSysFontGetAtStdFont"},
	{FRITBSysFontSEL, FRITBSysFontGetAtStdFont2SEL, L"FRITBSysFontGetAtStdFont2"},
	{FRITBSysFontSEL, FRITBSysFontIsStandardFontSEL, L"FRITBSysFontIsStandardFont"},
	{FRITBSysFontSEL, FRITBSysFontGetScriptNameSEL, L"FRITBSysFontGetScriptName"},
	{FRITBSysFontSEL, FRITBSysFontFontNamePDF2NameSEL, L"FRITBSysFontFontNamePDF2Name"},
	{FRITBSysFontSEL, FRITBSysFontGetCharsetByFontNameSEL, L"FRITBSysFontGetCharsetByFontName"},
	{FRITBSysFontSEL, FRITBSysFontGetBaseFontNameSEL, L"FRITBSysFontGetBaseFontName"},
	{FRITBSysFontSEL, FRITBSysFontGetFullNameSEL, L"FRITBSysFontGetFullName"},
// fr_sysImpl.h end

// In file fr_viewImpl.h
	{FRRedactionSEL, FRRedactionApplyDocSEL, L"FRRedactionApplyDoc"},
	{FRRedactionSEL, FRRedactionApplySEL, L"FRRedactionApply"},
	{FRRedactionSEL, FRRedactionApplyDoc2SEL, L"FRRedactionApplyDoc2"},
	{FRReaderSEL, FRReaderCreateDispViewerSEL, L"FRReaderCreateDispViewer"},
	{FRReaderSEL, FRReaderGetDocViewSEL, L"FRReaderGetDocView"},
	{FRReaderSEL, FRReaderSetSizeSEL, L"FRReaderSetSize"},
	{FRReaderSEL, FRReaderGetRenderDataSEL, L"FRReaderGetRenderData"},
	{FRReaderSEL, FRReaderContinueRenderingSEL, L"FRReaderContinueRendering"},
	{FRReaderSEL, FRReaderSetCenterPosSEL, L"FRReaderSetCenterPos"},
	{FRReaderSEL, FRReaderDocToWindowSEL, L"FRReaderDocToWindow"},
	{FRReaderSEL, FRReaderGetCurrentMatrixSEL, L"FRReaderGetCurrentMatrix"},
	{FRReaderSEL, FRReaderGetSizeSEL, L"FRReaderGetSize"},
	{FRReaderSEL, FRReaderDestroyDispViewerSEL, L"FRReaderDestroyDispViewer"},
	{FRIReaderDispViewerHandlerSEL, FRIReaderDispViewerHandlerNewSEL, L"FRIReaderDispViewerHandlerNew"},
	{FRIReaderDispViewerHandlerSEL, FRIReaderDispViewerHandlerDestroySEL, L"FRIReaderDispViewerHandlerDestroy"},
	{FRIPDFViewerEventHandlerSEL, FRIPDFViewerEventHandlerNewSEL, L"FRIPDFViewerEventHandlerNew"},
	{FRIPDFViewerEventHandlerSEL, FRIPDFViewerEventHandlerDestroySEL, L"FRIPDFViewerEventHandlerDestroy"},
	{FRToolFormatMgrSEL, FRToolFormatMgrGetSEL, L"FRToolFormatMgrGet"},
	{FRToolFormatMgrSEL, FRToolFormatMgrRegistFormatEventSEL, L"FRToolFormatMgrRegistFormatEvent"},
	{FRToolFormatMgrSEL, FRToolFormatMgrUnregisterFormatEventSEL, L"FRToolFormatMgrUnregisterFormatEvent"},
	{FRToolFormatMgrSEL, FRToolFormatMgrAddGroupSEL, L"FRToolFormatMgrAddGroup"},
	{FRToolFormatMgrSEL, FRToolFormatMgrAddGroupToFormatSEL, L"FRToolFormatMgrAddGroupToFormat"},
	{FRToolFormatMgrSEL, FRToolFormatMgrShowToolFormatSEL, L"FRToolFormatMgrShowToolFormat"},
	{FRToolFormatMgrSEL, FRToolFormatMgrIsToolFormatExistSEL, L"FRToolFormatMgrIsToolFormatExist"},
	{FRToolFormatMgrSEL, FRToolFormatMgrGetFormatGroupsSEL, L"FRToolFormatMgrGetFormatGroups"},
	{FRToolFormatMgrSEL, FRToolFormatMgrChangeFormatSizeSEL, L"FRToolFormatMgrChangeFormatSize"},
	{FRToolFormatMgrSEL, FRToolFormatMgrUpdateFormatStatusSEL, L"FRToolFormatMgrUpdateFormatStatus"},
	{FRToolFormatMgrSEL, FRToolFormatMgrShowToolFormat2SEL, L"FRToolFormatMgrShowToolFormat2"},
	{FRToolFormatMgrSEL, FRToolFormatMgrGetLastToolFormatNameSEL, L"FRToolFormatMgrGetLastToolFormatName"},
	{FRTextSelectedDataSEL, FRTextSelectedDataNewSEL, L"FRTextSelectedDataNew"},
	{FRTextSelectedDataSEL, FRTextSelectedDataDestroySEL, L"FRTextSelectedDataDestroy"},
	{FRTextSelectedDataSEL, FRTextSelectedDataGetSelectedPagesSEL, L"FRTextSelectedDataGetSelectedPages"},
	{FRTextSelectedDataSEL, FRTextSelectedDataGetSelectedDataCountByPageIndexSEL, L"FRTextSelectedDataGetSelectedDataCountByPageIndex"},
	{FRTextSelectedDataSEL, FRTextSelectedDataGetSelectedDatasSEL, L"FRTextSelectedDataGetSelectedDatas"},
	{FRIRPPropertySourceSEL, FRIRPPropertySourceGetSelectObjectTypeSEL, L"FRIRPPropertySourceGetSelectObjectType"},
	{FRIRPPropertySourceSEL, FRIRPPropertySourceCountSelectObjectsSEL, L"FRIRPPropertySourceCountSelectObjects"},
	{FRIRPPropertySourceSEL, FRIRPPropertySourceGetSelectObjectSEL, L"FRIRPPropertySourceGetSelectObject"},
	{FRIRPPropertySourceSEL, FRIRPPropertySourceSetPropertySourceCallbackSEL, L"FRIRPPropertySourceSetPropertySourceCallback"},
	{FRLayerOperationSEL, FRLayerOperationCreateSEL, L"FRLayerOperationCreate"},
	{FRLayerOperationSEL, FRLayerOperationDestroyLayerOperationSEL, L"FRLayerOperationDestroyLayerOperation"},
	{FRLayerOperationSEL, FRLayerOperationImportLayerSEL, L"FRLayerOperationImportLayer"},
	{FRLayerOperationSEL, FRLayerOperationIsChildOCGSEL, L"FRLayerOperationIsChildOCG"},
	{FRLayerOperationSEL, FRLayerOperationDeleteOCGSEL, L"FRLayerOperationDeleteOCG"},
	{FRLayerOperationSEL, FRLayerOperationReplaceOCGSEL, L"FRLayerOperationReplaceOCG"},
	{FRLayerOperationSEL, FRLayerOperationReplaceOCGContentHandlerSEL, L"FRLayerOperationReplaceOCGContentHandler"},
	{FRLayerOperationSEL, FRLayerOperationInsertChildOCGSEL, L"FRLayerOperationInsertChildOCG"},
	{FRLayerOperationSEL, FRLayerOperationDeleteObjectByVisibleSEL, L"FRLayerOperationDeleteObjectByVisible"},
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
	{FPDCEditObjectSEL, FPDCEditObjectNewSEL, L"FPDCEditObjectNew"},
	{FPDCEditObjectSEL, FPDCEditObjectNew2SEL, L"FPDCEditObjectNew2"},
	{FPDCEditObjectSEL, FPDCEditObjectDeleteSEL, L"FPDCEditObjectDelete"},
	{FPDCEditObjectSEL, FPDCEditObjectCombineObjctSEL, L"FPDCEditObjectCombineObjct"},
	{FPDCEditObjectSEL, FPDCEditObjectIsEqualSEL, L"FPDCEditObjectIsEqual"},
	{FPDCEditObjectSEL, FPDCEditObjectCopyBaseInfoSEL, L"FPDCEditObjectCopyBaseInfo"},
	{FPDCEditObjectSEL, FPDCEditObjectUpdateFormInfoSEL, L"FPDCEditObjectUpdateFormInfo"},
	{FPDCEditObjectSEL, FPDCEditObjectUpdateFormInfo2SEL, L"FPDCEditObjectUpdateFormInfo2"},
	{FPDCEditObjectSEL, FPDCEditObjectGetLastFormObjSEL, L"FPDCEditObjectGetLastFormObj"},
	{FPDCEditObjectSEL, FPDCEditObjectGetFirstFormObjSEL, L"FPDCEditObjectGetFirstFormObj"},
	{FPDCEditObjectSEL, FPDCEditObjectGetContainerSEL, L"FPDCEditObjectGetContainer"},
	{FPDCEditObjectSEL, FPDCEditObjectGetObjBBoxSEL, L"FPDCEditObjectGetObjBBox"},
	{FPDCEditObjectSEL, FPDCEditObjectResetSEL, L"FPDCEditObjectReset"},
	{FPDCEditObjectSEL, FPDCEditObjectUndoRedoStateSEL, L"FPDCEditObjectUndoRedoState"},
	{FPDCEditObjectSEL, FPDCEditObjectMergeTextObjRangeSEL, L"FPDCEditObjectMergeTextObjRange"},
	{FPDCEditObjectSEL, FPDCEditObjectMergeTextObjRange2SEL, L"FPDCEditObjectMergeTextObjRange2"},
	{FPDCEditObjectSEL, FPDCEditObjectGetPageObjectSEL, L"FPDCEditObjectGetPageObject"},
	{FPDCEditObjectSEL, FPDCEditObjectGetIndexSEL, L"FPDCEditObjectGetIndex"},
	{FPDCEditObjectSEL, FPDCEditObjectGetPosSEL, L"FPDCEditObjectGetPos"},
	{FPDCEditObjectSEL, FPDCEditObjectGetTextRangeCountSEL, L"FPDCEditObjectGetTextRangeCount"},
	{FPDCEditObjectSEL, FPDCEditObjectGetIsInFormSEL, L"FPDCEditObjectGetIsInForm"},
	{FPDCEditObjectSEL, FPDCEditObjectGetVecFormObjectSEL, L"FPDCEditObjectGetVecFormObject"},
	{FPDCEditObjectSEL, FPDCEditObjectGetVecFormIndexSEL, L"FPDCEditObjectGetVecFormIndex"},
	{FPDCEditObjectSEL, FPDCEditObjectGetMtFormSEL, L"FPDCEditObjectGetMtForm"},
	{FPDCEditObjectSEL, FPDCEditObjectGetTextRangeByIndexSEL, L"FPDCEditObjectGetTextRangeByIndex"},
	{FPDCEditObjectSEL, FPDCEditObjectSetVecFormObjectSEL, L"FPDCEditObjectSetVecFormObject"},
	{FPDCEditObjectSEL, FPDCEditObjectSetVecFormIndexSEL, L"FPDCEditObjectSetVecFormIndex"},
	{FPDCEditObjectSEL, FPDCEditObjectSetMtFormSEL, L"FPDCEditObjectSetMtForm"},
	{FPDCEditObjectSEL, FPDCEditObjectSetTextRangeSEL, L"FPDCEditObjectSetTextRange"},
	{FPDIJoinSplitSEL, FPDIJoinSplitExitJoinEditingSEL, L"FPDIJoinSplitExitJoinEditing"},
	{FPDIJoinSplitSEL, FPDIJoinSplitOnActivateSEL, L"FPDIJoinSplitOnActivate"},
	{FPDIJoinSplitSEL, FPDIJoinSplitOnDeactivateSEL, L"FPDIJoinSplitOnDeactivate"},
	{FPDIJoinSplitSEL, FPDIJoinSplitOnPaintSEL, L"FPDIJoinSplitOnPaint"},
	{FPDIJoinSplitSEL, FPDIJoinSplitOnLeftButtonDownSEL, L"FPDIJoinSplitOnLeftButtonDown"},
	{FPDIJoinSplitSEL, FPDIJoinSplitOnLeftButtonUpSEL, L"FPDIJoinSplitOnLeftButtonUp"},
	{FPDIJoinSplitSEL, FPDIJoinSplitOnMouseMoveSEL, L"FPDIJoinSplitOnMouseMove"},
	{FPDIJoinSplitSEL, FPDIJoinSplitOnRightButtonUpSEL, L"FPDIJoinSplitOnRightButtonUp"},
	{FPDIJoinSplitSEL, FPDIJoinSplitIsProcessingSEL, L"FPDIJoinSplitIsProcessing"},
	{FPDIJoinSplitSEL, FPDIJoinSplitBtnEnableStatusSEL, L"FPDIJoinSplitBtnEnableStatus"},
	{FPDIJoinSplitSEL, FPDIJoinSplitJoinBoxesSEL, L"FPDIJoinSplitJoinBoxes"},
	{FPDIJoinSplitSEL, FPDIJoinSplitSplitBoxesSEL, L"FPDIJoinSplitSplitBoxes"},
	{FPDIJoinSplitSEL, FPDIJoinSplitLinkBoxesSEL, L"FPDIJoinSplitLinkBoxes"},
	{FPDIJoinSplitSEL, FPDIJoinSplitUnlinkBoxesSEL, L"FPDIJoinSplitUnlinkBoxes"},
	{FPDIJoinSplitSEL, FPDIJoinSplitSelectNoneSEL, L"FPDIJoinSplitSelectNone"},
	{FPDIJoinSplitSEL, FPDIJoinSplitGetEditInfoSEL, L"FPDIJoinSplitGetEditInfo"},
	{FPDITouchupSEL, FPDITouchupOnActivateSEL, L"FPDITouchupOnActivate"},
	{FPDITouchupSEL, FPDITouchupOnDeactivateSEL, L"FPDITouchupOnDeactivate"},
	{FPDITouchupSEL, FPDITouchupExistEditingSEL, L"FPDITouchupExistEditing"},
	{FPDITouchupSEL, FPDITouchupOnPaintSEL, L"FPDITouchupOnPaint"},
	{FPDITouchupSEL, FPDITouchupOnCharSEL, L"FPDITouchupOnChar"},
	{FPDITouchupSEL, FPDITouchupOnVKUPSEL, L"FPDITouchupOnVKUP"},
	{FPDITouchupSEL, FPDITouchupOnVKDOWNSEL, L"FPDITouchupOnVKDOWN"},
	{FPDITouchupSEL, FPDITouchupOnLeftButtonDownSEL, L"FPDITouchupOnLeftButtonDown"},
	{FPDITouchupSEL, FPDITouchupOnLeftButtonUpSEL, L"FPDITouchupOnLeftButtonUp"},
	{FPDITouchupSEL, FPDITouchupOnLeftButtonDblClkSEL, L"FPDITouchupOnLeftButtonDblClk"},
	{FPDITouchupSEL, FPDITouchupOnMouseMoveSEL, L"FPDITouchupOnMouseMove"},
	{FPDITouchupSEL, FPDITouchupOnMouseWheelSEL, L"FPDITouchupOnMouseWheel"},
	{FPDITouchupSEL, FPDITouchupOnRightButtonDownSEL, L"FPDITouchupOnRightButtonDown"},
	{FPDITouchupSEL, FPDITouchupOnRightButtonUpSEL, L"FPDITouchupOnRightButtonUp"},
	{FPDITouchupSEL, FPDITouchupCanSelectAllSEL, L"FPDITouchupCanSelectAll"},
	{FPDITouchupSEL, FPDITouchupDoSelectAllSEL, L"FPDITouchupDoSelectAll"},
	{FPDITouchupSEL, FPDITouchupCanDeleteSEL, L"FPDITouchupCanDelete"},
	{FPDITouchupSEL, FPDITouchupDoDeleteSEL, L"FPDITouchupDoDelete"},
	{FPDITouchupSEL, FPDITouchupCanCopySEL, L"FPDITouchupCanCopy"},
	{FPDITouchupSEL, FPDITouchupDoCopySEL, L"FPDITouchupDoCopy"},
	{FPDITouchupSEL, FPDITouchupCanCutSEL, L"FPDITouchupCanCut"},
	{FPDITouchupSEL, FPDITouchupDoCutSEL, L"FPDITouchupDoCut"},
	{FPDITouchupSEL, FPDITouchupCanPasteSEL, L"FPDITouchupCanPaste"},
	{FPDITouchupSEL, FPDITouchupDoPasteSEL, L"FPDITouchupDoPaste"},
	{FPDITouchupSEL, FPDITouchupCanDeselectAllSEL, L"FPDITouchupCanDeselectAll"},
	{FPDITouchupSEL, FPDITouchupDoDeselectAllSEL, L"FPDITouchupDoDeselectAll"},
	{FPDITouchupSEL, FPDITouchupOnFontNameChangedSEL, L"FPDITouchupOnFontNameChanged"},
	{FPDITouchupSEL, FPDITouchupOnFontSizeChangedSEL, L"FPDITouchupOnFontSizeChanged"},
	{FPDITouchupSEL, FPDITouchupOnTextColorChangedSEL, L"FPDITouchupOnTextColorChanged"},
	{FPDITouchupSEL, FPDITouchupOnBoldItlicChangedSEL, L"FPDITouchupOnBoldItlicChanged"},
	{FPDITouchupSEL, FPDITouchupOnAlignChangedSEL, L"FPDITouchupOnAlignChanged"},
	{FPDITouchupSEL, FPDITouchupOnCharSpaceChangedSEL, L"FPDITouchupOnCharSpaceChanged"},
	{FPDITouchupSEL, FPDITouchupOnCharHorzScaleChangedSEL, L"FPDITouchupOnCharHorzScaleChanged"},
	{FPDITouchupSEL, FPDITouchupOnLineLeadingChangedSEL, L"FPDITouchupOnLineLeadingChanged"},
	{FPDITouchupSEL, FPDITouchupOnUnderlineChangedSEL, L"FPDITouchupOnUnderlineChanged"},
	{FPDITouchupSEL, FPDITouchupOnCrossChangedSEL, L"FPDITouchupOnCrossChanged"},
	{FPDITouchupSEL, FPDITouchupOnSuperScriptChangedSEL, L"FPDITouchupOnSuperScriptChanged"},
	{FPDITouchupSEL, FPDITouchupOnSubScriptChangedSEL, L"FPDITouchupOnSubScriptChanged"},
	{FPDITouchupSEL, FPDITouchupOnParagraphSpacingChangedSEL, L"FPDITouchupOnParagraphSpacingChanged"},
	{FPDITouchupSEL, FPDITouchupOnInDentChangedSEL, L"FPDITouchupOnInDentChanged"},
	{FPDITouchupSEL, FPDITouchupOnDeDentChangedSEL, L"FPDITouchupOnDeDentChanged"},
	{FPDITouchupSEL, FPDITouchupGetFXEditorSEL, L"FPDITouchupGetFXEditor"},
	{FPDITouchupSEL, FPDITouchupOnAfterBulletChangeSEL, L"FPDITouchupOnAfterBulletChange"},
	{FPDITouchupSEL, FPDITouchupGetCaretPositonSEL, L"FPDITouchupGetCaretPositon"},
	{FPDITouchupSEL, FPDITouchupIsProcessingSEL, L"FPDITouchupIsProcessing"},
	{FPDITouchupSEL, FPDITouchupEditContentSEL, L"FPDITouchupEditContent"},
	{FPDITouchupSEL, FPDITouchupEditContent2SEL, L"FPDITouchupEditContent2"},
	{FPDITouchupSEL, FPDITouchupOnInsertTextSEL, L"FPDITouchupOnInsertText"},
	{FPDITouchupSEL, FPDITouchupOnBulletedListSEL, L"FPDITouchupOnBulletedList"},
	{FPDITouchupSEL, FPDITouchupOnNumberedListSEL, L"FPDITouchupOnNumberedList"},
	{FPDITouchupSEL, FPDITouchupOnPageOnVisibleSEL, L"FPDITouchupOnPageOnVisible"},
	{FPDITouchupSEL, FPDITouchupOnWritingDirctionChangedSEL, L"FPDITouchupOnWritingDirctionChanged"},
	{FPDITouchupSEL, FPDITouchupOnBeforeUndoSEL, L"FPDITouchupOnBeforeUndo"},
	{FPDITouchupSEL, FPDITouchupOnBeforeRedoSEL, L"FPDITouchupOnBeforeRedo"},
	{FPDITouchupSEL, FPDITouchupOnAfterUndoSEL, L"FPDITouchupOnAfterUndo"},
	{FPDITouchupSEL, FPDITouchupOnAfterRedoSEL, L"FPDITouchupOnAfterRedo"},
	{FPDITouchupManagerSEL, FPDITouchupManagerCreateManagerSEL, L"FPDITouchupManagerCreateManager"},
	{FPDITouchupManagerSEL, FPDITouchupManagerGetTouchupSEL, L"FPDITouchupManagerGetTouchup"},
	{FPDITouchupManagerSEL, FPDITouchupManagerGetJoinSpiltSEL, L"FPDITouchupManagerGetJoinSpilt"},
	{FPDITouchupManagerSEL, FPDITouchupManagerReleaseManagerSEL, L"FPDITouchupManagerReleaseManager"},
	{FPDITouchupManagerSEL, FPDITouchupManagerGetTouchupSpellCheckSEL, L"FPDITouchupManagerGetTouchupSpellCheck"},
	{FPDITouchupManagerSEL, FPDITouchupManagerGetTouchupFindReplaceSEL, L"FPDITouchupManagerGetTouchupFindReplace"},
	{FPDITouchupManagerSEL, FPDITouchupManagerOnAfterInsertPagesSEL, L"FPDITouchupManagerOnAfterInsertPages"},
	{FPDITouchupManagerSEL, FPDITouchupManagerOnAfterDeletePagesSEL, L"FPDITouchupManagerOnAfterDeletePages"},
	{FPDITouchupManagerSEL, FPDITouchupManagerOnAfterReplacePagesSEL, L"FPDITouchupManagerOnAfterReplacePages"},
	{FPDITouchupManagerSEL, FPDITouchupManagerOnAfterResizePageSEL, L"FPDITouchupManagerOnAfterResizePage"},
	{FPDITouchupManagerSEL, FPDITouchupManagerOnAfterRotatePageSEL, L"FPDITouchupManagerOnAfterRotatePage"},
	{FPDITouchupManagerSEL, FPDITouchupManagerOnAfterMovePagesSEL, L"FPDITouchupManagerOnAfterMovePages"},
	{FPDITouchupManagerSEL, FPDITouchupManagerOnPageContentChangeSEL, L"FPDITouchupManagerOnPageContentChange"},
	{FPDITouchupManagerSEL, FPDITouchupManagerOnDocOCGStateChangedSEL, L"FPDITouchupManagerOnDocOCGStateChanged"},
	{FPDITouchupManagerSEL, FPDITouchupManagerSetInteractionConfigSEL, L"FPDITouchupManagerSetInteractionConfig"},
	{FPDITouchUndoItemSEL, FPDITouchUndoItemOnUndoSEL, L"FPDITouchUndoItemOnUndo"},
	{FPDITouchUndoItemSEL, FPDITouchUndoItemOnRedoSEL, L"FPDITouchUndoItemOnRedo"},
	{FPDITouchUndoItemSEL, FPDITouchUndoItemOnReleaseSEL, L"FPDITouchUndoItemOnRelease"},
	{FPDITouchPopupMenuSEL, FPDITouchPopupMenuNewSEL, L"FPDITouchPopupMenuNew"},
	{FPDITouchPopupMenuSEL, FPDITouchPopupMenuDestroySEL, L"FPDITouchPopupMenuDestroy"},
	{FPDITouchProgressBarSEL, FPDITouchProgressBarNewSEL, L"FPDITouchProgressBarNew"},
	{FPDITouchProgressBarSEL, FPDITouchProgressBarDestroySEL, L"FPDITouchProgressBarDestroy"},
	{FPDITouchOperationNotifySEL, FPDITouchOperationNotifyNewSEL, L"FPDITouchOperationNotifyNew"},
	{FPDITouchOperationNotifySEL, FPDITouchOperationNotifyDestroySEL, L"FPDITouchOperationNotifyDestroy"},
	{FPDITouchUndoHandlerSEL, FPDITouchUndoHandlerNewSEL, L"FPDITouchUndoHandlerNew"},
	{FPDITouchUndoHandlerSEL, FPDITouchUndoHandlerDestroySEL, L"FPDITouchUndoHandlerDestroy"},
	{FPDITouchTextFormatHandlerSEL, FPDITouchTextFormatHandlerNewSEL, L"FPDITouchTextFormatHandlerNew"},
	{FPDITouchTextFormatHandlerSEL, FPDITouchTextFormatHandlerDestroySEL, L"FPDITouchTextFormatHandlerDestroy"},
	{FPDITouchProviderSEL, FPDITouchProviderNewSEL, L"FPDITouchProviderNew"},
	{FPDITouchProviderSEL, FPDITouchProviderDestroySEL, L"FPDITouchProviderDestroy"},
	{FPDITouchupSpellCheckHandlerSEL, FPDITouchupSpellCheckHandlerNewSEL, L"FPDITouchupSpellCheckHandlerNew"},
	{FPDITouchupSpellCheckHandlerSEL, FPDITouchupSpellCheckHandlerDestroySEL, L"FPDITouchupSpellCheckHandlerDestroy"},
	{FPDIFindReplaceSEL, FPDIFindReplaceFindSEL, L"FPDIFindReplaceFind"},
	{FPDIFindReplaceSEL, FPDIFindReplaceReplaceSEL, L"FPDIFindReplaceReplace"},
	{FPDIFindReplaceSEL, FPDIFindReplaceReplaceAllSEL, L"FPDIFindReplaceReplaceAll"},
	{FPDIFindReplaceSEL, FPDIFindReplaceIsProcessInterruptSEL, L"FPDIFindReplaceIsProcessInterrupt"},
	{FPDIFindReplaceSEL, FPDIFindReplaceInterruptProcessSEL, L"FPDIFindReplaceInterruptProcess"},
	{FPDIFindReplaceSEL, FPDIFindReplaceClearCacheSEL, L"FPDIFindReplaceClearCache"},
	{FPDIFindReplaceSEL, FPDIFindReplaceSetHighlightColorSEL, L"FPDIFindReplaceSetHighlightColor"},
	{FPDIFindReplaceSEL, FPDIFindReplaceFind2SEL, L"FPDIFindReplaceFind2"},
	{FPDITouchupSpellCheckSEL, FPDITouchupSpellCheckOnActivateSEL, L"FPDITouchupSpellCheckOnActivate"},
	{FPDITouchupSpellCheckSEL, FPDITouchupSpellCheckOnDeactivateSEL, L"FPDITouchupSpellCheckOnDeactivate"},
	{FPDITouchupSpellCheckSEL, FPDITouchupSpellCheckIsProcessingSEL, L"FPDITouchupSpellCheckIsProcessing"},
	{FPDITouchupSpellCheckSEL, FPDITouchupSpellCheckOnPaintSEL, L"FPDITouchupSpellCheckOnPaint"},
	{FPDITouchupSpellCheckSEL, FPDITouchupSpellCheckSpellCheckSEL, L"FPDITouchupSpellCheckSpellCheck"},
	{FPDITouchupSpellCheckSEL, FPDITouchupSpellCheckRespondToHitSEL, L"FPDITouchupSpellCheckRespondToHit"},
	{FPDIFindReplaceHandlerSEL, FPDIFindReplaceHandlerNewSEL, L"FPDIFindReplaceHandlerNew"},
	{FPDIFindReplaceHandlerSEL, FPDIFindReplaceHandlerDestroySEL, L"FPDIFindReplaceHandlerDestroy"},
	{FPDICollectSensorHandlerSEL, FPDICollectSensorHandlerNewSEL, L"FPDICollectSensorHandlerNew"},
	{FPDICollectSensorHandlerSEL, FPDICollectSensorHandlerDestroySEL, L"FPDICollectSensorHandlerDestroy"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsGetLineWidthSEL, L"FPDPathObjectUtilsGetLineWidth"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsSetLineWidthSEL, L"FPDPathObjectUtilsSetLineWidth"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsSetMiterLimitSEL, L"FPDPathObjectUtilsSetMiterLimit"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsGetMiterLimitSEL, L"FPDPathObjectUtilsGetMiterLimit"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsSetLineCapSEL, L"FPDPathObjectUtilsSetLineCap"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsGetLineCapSEL, L"FPDPathObjectUtilsGetLineCap"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsGetLineJoinSEL, L"FPDPathObjectUtilsGetLineJoin"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsSetLineJoinSEL, L"FPDPathObjectUtilsSetLineJoin"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsGetLineStyleSEL, L"FPDPathObjectUtilsGetLineStyle"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsSetLineStyleSEL, L"FPDPathObjectUtilsSetLineStyle"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsGetStrokeInfoSEL, L"FPDPathObjectUtilsGetStrokeInfo"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsSetStrokeInfoSEL, L"FPDPathObjectUtilsSetStrokeInfo"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsGetFillInfoSEL, L"FPDPathObjectUtilsGetFillInfo"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsSetFillInfoSEL, L"FPDPathObjectUtilsSetFillInfo"},
	{FPDPathObjectUtilsSEL, FPDPathObjectUtilsSetColorSpaceSEL, L"FPDPathObjectUtilsSetColorSpace"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsChangeShadingColorSEL, L"FPDShadingObjectUtilsChangeShadingColor"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsChangeColorUndoStartSEL, L"FPDShadingObjectUtilsChangeColorUndoStart"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsChangeColorUndoEndSEL, L"FPDShadingObjectUtilsChangeColorUndoEnd"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsChangeColorUndoCancleSEL, L"FPDShadingObjectUtilsChangeColorUndoCancle"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsEditReferenceLineSEL, L"FPDShadingObjectUtilsEditReferenceLine"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsSetGridientCursorColorSEL, L"FPDShadingObjectUtilsSetGridientCursorColor"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsGetGridientCursorColorSEL, L"FPDShadingObjectUtilsGetGridientCursorColor"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsGetGridientColorAtSEL, L"FPDShadingObjectUtilsGetGridientColorAt"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsGetGridientCursorLocationSEL, L"FPDShadingObjectUtilsGetGridientCursorLocation"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsGetGridientCursorIndexSEL, L"FPDShadingObjectUtilsGetGridientCursorIndex"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsSetGradientColorShowRectSEL, L"FPDShadingObjectUtilsSetGradientColorShowRect"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsAddGradientCursorInfoBeforeSEL, L"FPDShadingObjectUtilsAddGradientCursorInfoBefore"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsAddGradientCursorInfoExcuteSEL, L"FPDShadingObjectUtilsAddGradientCursorInfoExcute"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsAddGradientCursorInfoEndSEL, L"FPDShadingObjectUtilsAddGradientCursorInfoEnd"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsAddGradientCursorInfoDblClkSEL, L"FPDShadingObjectUtilsAddGradientCursorInfoDblClk"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsDelGradientCursorInfoSEL, L"FPDShadingObjectUtilsDelGradientCursorInfo"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsDefaultGradientDataInitSEL, L"FPDShadingObjectUtilsDefaultGradientDataInit"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsSetGradientCurrentInfoSEL, L"FPDShadingObjectUtilsSetGradientCurrentInfo"},
	{FPDShadingObjectUtilsSEL, FPDShadingObjectUtilsPaintGridientSEL, L"FPDShadingObjectUtilsPaintGridient"},
	{FPDPathEditorSEL, FPDPathEditorHasStartEditSEL, L"FPDPathEditorHasStartEdit"},
	{FPDPathEditorSEL, FPDPathEditorIsClipPathModeSEL, L"FPDPathEditorIsClipPathMode"},
	{FPDPathEditorSEL, FPDPathEditorAppendSubPathSEL, L"FPDPathEditorAppendSubPath"},
	{FPDShadingEditorSEL, FPDShadingEditorIsReferenceLineWorkingSEL, L"FPDShadingEditorIsReferenceLineWorking"},
	{FPDTextEditorSEL, FPDTextEditorOnFontNameChangedSEL, L"FPDTextEditorOnFontNameChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnFontSizeChangedSEL, L"FPDTextEditorOnFontSizeChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnTextColorChangedSEL, L"FPDTextEditorOnTextColorChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnBoldChangedSEL, L"FPDTextEditorOnBoldChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnItalicChangedSEL, L"FPDTextEditorOnItalicChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnAlignChangedSEL, L"FPDTextEditorOnAlignChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnCharSpaceChangedSEL, L"FPDTextEditorOnCharSpaceChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnWordSpaceChangedSEL, L"FPDTextEditorOnWordSpaceChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnCharHorzScaleChangedSEL, L"FPDTextEditorOnCharHorzScaleChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnLineLeadingChangedSEL, L"FPDTextEditorOnLineLeadingChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnUnderlineChangedSEL, L"FPDTextEditorOnUnderlineChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnCrossChangedSEL, L"FPDTextEditorOnCrossChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnSuperScriptChangedSEL, L"FPDTextEditorOnSuperScriptChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnSubScriptChangedSEL, L"FPDTextEditorOnSubScriptChanged"},
	{FPDTextEditorSEL, FPDTextEditorOnWritingDirctionChangedSEL, L"FPDTextEditorOnWritingDirctionChanged"},
	{FPDTextEditorSEL, FPDTextEditorIsSelectSEL, L"FPDTextEditorIsSelect"},
	{FPDTextEditorSEL, FPDTextEditorCopySEL, L"FPDTextEditorCopy"},
	{FPDTextEditorSEL, FPDTextEditorPasteSEL, L"FPDTextEditorPaste"},
	{FPDTextEditorSEL, FPDTextEditorCutSEL, L"FPDTextEditorCut"},
	{FPDTextEditorSEL, FPDTextEditorDeleteSEL, L"FPDTextEditorDelete"},
	{FPDTextEditorSEL, FPDTextEditorSelectAllSEL, L"FPDTextEditorSelectAll"},
	{FPDTextEditorSEL, FPDTextEditorIsAddSEL, L"FPDTextEditorIsAdd"},
	{FPDTextEditorSEL, FPDTextEditorGetCaretPositonSEL, L"FPDTextEditorGetCaretPositon"},
	{FPDTextEditorSEL, FPDTextEditorOnInsertTextSEL, L"FPDTextEditorOnInsertText"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetFontSizeSEL, L"FPDTextObjectUtilsGetFontSize"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsSetFontSizeSEL, L"FPDTextObjectUtilsSetFontSize"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetHorizontalScaleSEL, L"FPDTextObjectUtilsGetHorizontalScale"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsSetHorizontalScaleSEL, L"FPDTextObjectUtilsSetHorizontalScale"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsSetCharSpaceSEL, L"FPDTextObjectUtilsSetCharSpace"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetCharSpaceSEL, L"FPDTextObjectUtilsGetCharSpace"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetWordSpaceSEL, L"FPDTextObjectUtilsGetWordSpace"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsSetWordSpaceSEL, L"FPDTextObjectUtilsSetWordSpace"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsSetFontSEL, L"FPDTextObjectUtilsSetFont"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetFontSEL, L"FPDTextObjectUtilsGetFont"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetTextModeSEL, L"FPDTextObjectUtilsGetTextMode"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsSetTextModeSEL, L"FPDTextObjectUtilsSetTextMode"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsCanRemoveTextKerningSEL, L"FPDTextObjectUtilsCanRemoveTextKerning"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsRemoveTextKerningSEL, L"FPDTextObjectUtilsRemoveTextKerning"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsCanMergeTextSEL, L"FPDTextObjectUtilsCanMergeText"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsMergeTextSEL, L"FPDTextObjectUtilsMergeText"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsCanSplitTextSEL, L"FPDTextObjectUtilsCanSplitText"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsSplitTextSEL, L"FPDTextObjectUtilsSplitText"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsCanText2PathSEL, L"FPDTextObjectUtilsCanText2Path"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetStrokeInfoSEL, L"FPDTextObjectUtilsGetStrokeInfo"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsSetStrokeInfoSEL, L"FPDTextObjectUtilsSetStrokeInfo"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetFillInfoSEL, L"FPDTextObjectUtilsGetFillInfo"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsSetFillInfoSEL, L"FPDTextObjectUtilsSetFillInfo"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsSetColorSpaceSEL, L"FPDTextObjectUtilsSetColorSpace"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetTextColorInfoSEL, L"FPDTextObjectUtilsGetTextColorInfo"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsIsWordSpaceValidSEL, L"FPDTextObjectUtilsIsWordSpaceValid"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetFontBoldInfoSEL, L"FPDTextObjectUtilsGetFontBoldInfo"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetFontItalicSEL, L"FPDTextObjectUtilsGetFontItalic"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsGetLineWidthSEL, L"FPDTextObjectUtilsGetLineWidth"},
	{FPDTextObjectUtilsSEL, FPDTextObjectUtilsSetLineWidthSEL, L"FPDTextObjectUtilsSetLineWidth"},
	{FPDGraphicObjectSEL, FPDGraphicObjectCreateSEL, L"FPDGraphicObjectCreate"},
	{FPDGraphicObjectSEL, FPDGraphicObjectDestroySEL, L"FPDGraphicObjectDestroy"},
	{FPDGraphicObjectSEL, FPDGraphicObjectGetPageSEL, L"FPDGraphicObjectGetPage"},
	{FPDGraphicObjectSEL, FPDGraphicObjectGetGraphicObjectSEL, L"FPDGraphicObjectGetGraphicObject"},
	{FPDGraphicObjectSEL, FPDGraphicObjectGetIndexSEL, L"FPDGraphicObjectGetIndex"},
	{FPDGraphicObjectSEL, FPDGraphicObjectGetPositionSEL, L"FPDGraphicObjectGetPosition"},
	{FPDGraphicObjectSEL, FPDGraphicObjectIsInFormSEL, L"FPDGraphicObjectIsInForm"},
	{FPDGraphicObjectSEL, FPDGraphicObjectGetFormIndexSEL, L"FPDGraphicObjectGetFormIndex"},
	{FPDGraphicObjectSEL, FPDGraphicObjectGetFormObjectsSEL, L"FPDGraphicObjectGetFormObjects"},
	{FPDGraphicObjectSEL, FPDGraphicObjectGetFormMatrixSEL, L"FPDGraphicObjectGetFormMatrix"},
	{FPDGraphicEditorSEL, FPDGraphicEditorGetTypeSEL, L"FPDGraphicEditorGetType"},
	{FPDGraphicEditorSEL, FPDGraphicEditorEndEditSEL, L"FPDGraphicEditorEndEdit"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsGetHeightSEL, L"FPDGraphicObjectUtilsGetHeight"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsSetHeightSEL, L"FPDGraphicObjectUtilsSetHeight"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsSetWidthSEL, L"FPDGraphicObjectUtilsSetWidth"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsGetWidthSEL, L"FPDGraphicObjectUtilsGetWidth"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsGetXPositionSEL, L"FPDGraphicObjectUtilsGetXPosition"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsSetXPositionSEL, L"FPDGraphicObjectUtilsSetXPosition"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsGetYPositionSEL, L"FPDGraphicObjectUtilsGetYPosition"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsSetYPositionSEL, L"FPDGraphicObjectUtilsSetYPosition"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsGetOpacitySEL, L"FPDGraphicObjectUtilsGetOpacity"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsSetOpacitySEL, L"FPDGraphicObjectUtilsSetOpacity"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsRotateSEL, L"FPDGraphicObjectUtilsRotate"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsFlipSEL, L"FPDGraphicObjectUtilsFlip"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsShearSEL, L"FPDGraphicObjectUtilsShear"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsMoveSEL, L"FPDGraphicObjectUtilsMove"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsAlignSEL, L"FPDGraphicObjectUtilsAlign"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsCenterSEL, L"FPDGraphicObjectUtilsCenter"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsDistributeSEL, L"FPDGraphicObjectUtilsDistribute"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsSizeSEL, L"FPDGraphicObjectUtilsSize"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsScaleSEL, L"FPDGraphicObjectUtilsScale"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsScaleFloatSEL, L"FPDGraphicObjectUtilsScaleFloat"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsChangeRenderingOrderSEL, L"FPDGraphicObjectUtilsChangeRenderingOrder"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsCanChangeRenderingOrderSEL, L"FPDGraphicObjectUtilsCanChangeRenderingOrder"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsClearClipPathSEL, L"FPDGraphicObjectUtilsClearClipPath"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsEditClipPathSEL, L"FPDGraphicObjectUtilsEditClipPath"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsAddClipPathSEL, L"FPDGraphicObjectUtilsAddClipPath"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsGetTypeSEL, L"FPDGraphicObjectUtilsGetType"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsCutSEL, L"FPDGraphicObjectUtilsCut"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsCopySEL, L"FPDGraphicObjectUtilsCopy"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsDeleteSEL, L"FPDGraphicObjectUtilsDelete"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsSavePageArchiveSEL, L"FPDGraphicObjectUtilsSavePageArchive"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsReadPageArchiveSEL, L"FPDGraphicObjectUtilsReadPageArchive"},
	{FPDGraphicObjectUtilsSEL, FPDGraphicObjectUtilsReadPageArchive2SEL, L"FPDGraphicObjectUtilsReadPageArchive2"},
	{FPDImageEditorSEL, FPDImageEditorSaveAsImageSEL, L"FPDImageEditorSaveAsImage"},
	{FPDImageEditorSEL, FPDImageEditorPreviewFilterSEL, L"FPDImageEditorPreviewFilter"},
	{FPDImageEditorSEL, FPDImageEditorCancelPreviewFilterSEL, L"FPDImageEditorCancelPreviewFilter"},
	{FPDImageEditorSEL, FPDImageEditorAdjustFilterSEL, L"FPDImageEditorAdjustFilter"},
	{FPDImageEditorSEL, FPDImageEditorRotateVerticallySEL, L"FPDImageEditorRotateVertically"},
	{FPDImageEditorSEL, FPDImageEditorRotateHorizontallySEL, L"FPDImageEditorRotateHorizontally"},
	{FPDImageEditorSEL, FPDImageEditorReplaceSEL, L"FPDImageEditorReplace"},
	{FPDImageEditorSEL, FPDImageEditorCopySEL, L"FPDImageEditorCopy"},
	{FPDImageEditorSEL, FPDImageEditorPasteSEL, L"FPDImageEditorPaste"},
	{FPDImageEditorSEL, FPDImageEditorDeleteRegionSEL, L"FPDImageEditorDeleteRegion"},
	{FPDImageEditorSEL, FPDImageEditorZoomInSEL, L"FPDImageEditorZoomIn"},
	{FPDImageEditorSEL, FPDImageEditorZoomToSEL, L"FPDImageEditorZoomTo"},
	{FPDImageEditorSEL, FPDImageEditorZoomOutSEL, L"FPDImageEditorZoomOut"},
	{FPDImageEditorSEL, FPDImageEditorAdjustColorSEL, L"FPDImageEditorAdjustColor"},
	{FPDImageEditorSEL, FPDImageEditorLoadFromClipboardSEL, L"FPDImageEditorLoadFromClipboard"},
	{FPDImageEditorSEL, FPDImageEditorOnClientRectChangedSEL, L"FPDImageEditorOnClientRectChanged"},
	{FPDImageEditorSEL, FPDImageEditorSetActionTypeSEL, L"FPDImageEditorSetActionType"},
	{FPDImageEditorSEL, FPDImageEditorGetActionTypeSEL, L"FPDImageEditorGetActionType"},
	{FPDImageEditorSEL, FPDImageEditorOnSetCursorSEL, L"FPDImageEditorOnSetCursor"},
	{FPDImageEditorSEL, FPDImageEditorOnSizeSEL, L"FPDImageEditorOnSize"},
	{FPDImageEditorSEL, FPDImageEditorGetCurrentOptionDataSEL, L"FPDImageEditorGetCurrentOptionData"},
	{FPDImageEditorSEL, FPDImageEditorGetPublicOptionDataSEL, L"FPDImageEditorGetPublicOptionData"},
	{FPDImageEditorSEL, FPDImageEditorGetImageHistogramDataSEL, L"FPDImageEditorGetImageHistogramData"},
	{FPDImageEditorSEL, FPDImageEditorCompositeImageObjectSEL, L"FPDImageEditorCompositeImageObject"},
	{FPDImageEditorSEL, FPDImageEditorCancelEditSEL, L"FPDImageEditorCancelEdit"},
	{FPDIPageEditorSEL, FPDIPageEditorStartEditSEL, L"FPDIPageEditorStartEdit"},
	{FPDIPageEditorSEL, FPDIPageEditorRestartEditSEL, L"FPDIPageEditorRestartEdit"},
	{FPDIPageEditorSEL, FPDIPageEditorEndEditSEL, L"FPDIPageEditorEndEdit"},
	{FPDIPageEditorSEL, FPDIPageEditorHasSelectionSEL, L"FPDIPageEditorHasSelection"},
	{FPDIPageEditorSEL, FPDIPageEditorCountSelectionSEL, L"FPDIPageEditorCountSelection"},
	{FPDIPageEditorSEL, FPDIPageEditorGetSelectionSEL, L"FPDIPageEditorGetSelection"},
	{FPDIPageEditorSEL, FPDIPageEditorHaveFillColorInSelectionSEL, L"FPDIPageEditorHaveFillColorInSelection"},
	{FPDIPageEditorSEL, FPDIPageEditorGetActivePageSEL, L"FPDIPageEditorGetActivePage"},
	{FPDIPageEditorSEL, FPDIPageEditorSetObjectFilterSEL, L"FPDIPageEditorSetObjectFilter"},
	{FPDIPageEditorSEL, FPDIPageEditorOnVKUPSEL, L"FPDIPageEditorOnVKUP"},
	{FPDIPageEditorSEL, FPDIPageEditorOnVKDOWNSEL, L"FPDIPageEditorOnVKDOWN"},
	{FPDIPageEditorSEL, FPDIPageEditorOnLeftButtonDownSEL, L"FPDIPageEditorOnLeftButtonDown"},
	{FPDIPageEditorSEL, FPDIPageEditorOnLeftButtonUpSEL, L"FPDIPageEditorOnLeftButtonUp"},
	{FPDIPageEditorSEL, FPDIPageEditorOnLeftButtonDblClkSEL, L"FPDIPageEditorOnLeftButtonDblClk"},
	{FPDIPageEditorSEL, FPDIPageEditorOnMouseMoveSEL, L"FPDIPageEditorOnMouseMove"},
	{FPDIPageEditorSEL, FPDIPageEditorOnMouseWheelSEL, L"FPDIPageEditorOnMouseWheel"},
	{FPDIPageEditorSEL, FPDIPageEditorOnRightButtonDownSEL, L"FPDIPageEditorOnRightButtonDown"},
	{FPDIPageEditorSEL, FPDIPageEditorOnRightButtonUpSEL, L"FPDIPageEditorOnRightButtonUp"},
	{FPDIPageEditorSEL, FPDIPageEditorOnReleaseCaptureSEL, L"FPDIPageEditorOnReleaseCapture"},
	{FPDIPageEditorSEL, FPDIPageEditorOnLeavePageSEL, L"FPDIPageEditorOnLeavePage"},
	{FPDIPageEditorSEL, FPDIPageEditorOnPaintSEL, L"FPDIPageEditorOnPaint"},
	{FPDIPageEditorSEL, FPDIPageEditorGetObjectAtPointSEL, L"FPDIPageEditorGetObjectAtPoint"},
	{FPDIPageEditorSEL, FPDIPageEditorCanPasteSEL, L"FPDIPageEditorCanPaste"},
	{FPDIPageEditorSEL, FPDIPageEditorPasteSEL, L"FPDIPageEditorPaste"},
	{FPDIPageEditorSEL, FPDIPageEditorSelectAllSEL, L"FPDIPageEditorSelectAll"},
	{FPDIPageEditorSEL, FPDIPageEditorGetGraphicEditorSEL, L"FPDIPageEditorGetGraphicEditor"},
	{FPDIPageEditorSEL, FPDIPageEditorGetGraphicObjectUtilsSEL, L"FPDIPageEditorGetGraphicObjectUtils"},
	{FPDIPageEditorSEL, FPDIPageEditorCreatePathSEL, L"FPDIPageEditorCreatePath"},
	{FPDIPageEditorSEL, FPDIPageEditorCreateShadingSEL, L"FPDIPageEditorCreateShading"},
	{FPDIPageEditorSEL, FPDIPageEditorCreateImageSEL, L"FPDIPageEditorCreateImage"},
	{FPDIPageEditorSEL, FPDIPageEditorCreateTextSEL, L"FPDIPageEditorCreateText"},
	{FPDIPageEditorSEL, FPDIPageEditorCreatePageEditorSEL, L"FPDIPageEditorCreatePageEditor"},
	{FPDIPageEditorSEL, FPDIPageEditorDestroyPageEditorSEL, L"FPDIPageEditorDestroyPageEditor"},
	{FPDIPageEditorSEL, FPDIPageEditorClearSelectionSEL, L"FPDIPageEditorClearSelection"},
	{FPDIPageEditorSEL, FPDIPageEditorText2PathSEL, L"FPDIPageEditorText2Path"},
	{FPDIPageEditorSEL, FPDIPageEditorOnCharSEL, L"FPDIPageEditorOnChar"},
	{FPDIPageEditorSEL, FPDIPageEditorEditGraphicObjectSEL, L"FPDIPageEditorEditGraphicObject"},
	{FPDIPageEditorSEL, FPDIPageEditorCreateImage2SEL, L"FPDIPageEditorCreateImage2"},
	{FPDIPageEditorSEL, FPDIPageEditorCreateImage3SEL, L"FPDIPageEditorCreateImage3"},
	{FPDIPageEditorSEL, FPDIPageEditorCreateText2SEL, L"FPDIPageEditorCreateText2"},
	{FPDIPageEditorSEL, FPDIPageEditorPaste2SEL, L"FPDIPageEditorPaste2"},
	{FPDIPageEditorSEL, FPDIPageEditorOnDocOCGStateChangedSEL, L"FPDIPageEditorOnDocOCGStateChanged"},
	{FPDIPageEditorSEL, FPDIPageEditorSetInteractionConfigSEL, L"FPDIPageEditorSetInteractionConfig"},
	{FPDIUndoItemSEL, FPDIUndoItemOnUndoSEL, L"FPDIUndoItemOnUndo"},
	{FPDIUndoItemSEL, FPDIUndoItemOnRedoSEL, L"FPDIUndoItemOnRedo"},
	{FPDIUndoItemSEL, FPDIUndoItemOnReleaseSEL, L"FPDIUndoItemOnRelease"},
	{FPDIClipboardSEL, FPDIClipboardNewSEL, L"FPDIClipboardNew"},
	{FPDIClipboardSEL, FPDIClipboardDestroySEL, L"FPDIClipboardDestroy"},
	{FPDIPopupMenuSEL, FPDIPopupMenuNewSEL, L"FPDIPopupMenuNew"},
	{FPDIPopupMenuSEL, FPDIPopupMenuDestroySEL, L"FPDIPopupMenuDestroy"},
	{FPDITipSEL, FPDITipNewSEL, L"FPDITipNew"},
	{FPDITipSEL, FPDITipDestroySEL, L"FPDITipDestroy"},
	{FPDIOperationNotifySEL, FPDIOperationNotifyNewSEL, L"FPDIOperationNotifyNew"},
	{FPDIOperationNotifySEL, FPDIOperationNotifyDestroySEL, L"FPDIOperationNotifyDestroy"},
	{FPDIPublicOptionDataSEL, FPDIPublicOptionDataSetForegroundColorSEL, L"FPDIPublicOptionDataSetForegroundColor"},
	{FPDIPublicOptionDataSEL, FPDIPublicOptionDataGetForegroundColorSEL, L"FPDIPublicOptionDataGetForegroundColor"},
	{FPDIPublicOptionDataSEL, FPDIPublicOptionDataSetBackgroundColorSEL, L"FPDIPublicOptionDataSetBackgroundColor"},
	{FPDIPublicOptionDataSEL, FPDIPublicOptionDataGetBackgroundColorSEL, L"FPDIPublicOptionDataGetBackgroundColor"},
	{FPDIPublicOptionDataSEL, FPDIPublicOptionDataSetLayerOpacitySEL, L"FPDIPublicOptionDataSetLayerOpacity"},
	{FPDIPublicOptionDataSEL, FPDIPublicOptionDataGetLayerOpacitySEL, L"FPDIPublicOptionDataGetLayerOpacity"},
	{FPDIPublicOptionDataSEL, FPDIPublicOptionDataSetLayerFillSEL, L"FPDIPublicOptionDataSetLayerFill"},
	{FPDIPublicOptionDataSEL, FPDIPublicOptionDataGetLayerFillSEL, L"FPDIPublicOptionDataGetLayerFill"},
	{FPDIPublicOptionDataSEL, FPDIPublicOptionDataSetLayerBlendModeSEL, L"FPDIPublicOptionDataSetLayerBlendMode"},
	{FPDIPublicOptionDataSEL, FPDIPublicOptionDataGetLayerBlendModeSEL, L"FPDIPublicOptionDataGetLayerBlendMode"},
	{FPDIBaseBrushOptionDataSEL, FPDIBaseBrushOptionDataSetBrushDiameterSEL, L"FPDIBaseBrushOptionDataSetBrushDiameter"},
	{FPDIBaseBrushOptionDataSEL, FPDIBaseBrushOptionDataGetBrushDiameterSEL, L"FPDIBaseBrushOptionDataGetBrushDiameter"},
	{FPDIBaseBrushOptionDataSEL, FPDIBaseBrushOptionDataSetBrushHardnessSEL, L"FPDIBaseBrushOptionDataSetBrushHardness"},
	{FPDIBaseBrushOptionDataSEL, FPDIBaseBrushOptionDataGetBrushHardnessSEL, L"FPDIBaseBrushOptionDataGetBrushHardness"},
	{FPDIBrushOptionDataSEL, FPDIBrushOptionDataSetBlendModeSEL, L"FPDIBrushOptionDataSetBlendMode"},
	{FPDIBrushOptionDataSEL, FPDIBrushOptionDataGetBlendModeSEL, L"FPDIBrushOptionDataGetBlendMode"},
	{FPDIBrushOptionDataSEL, FPDIBrushOptionDataSetFlowSEL, L"FPDIBrushOptionDataSetFlow"},
	{FPDIBrushOptionDataSEL, FPDIBrushOptionDataGetFlowSEL, L"FPDIBrushOptionDataGetFlow"},
	{FPDIBrushOptionDataSEL, FPDIBrushOptionDataSetOpacitySEL, L"FPDIBrushOptionDataSetOpacity"},
	{FPDIBrushOptionDataSEL, FPDIBrushOptionDataGetOpacitySEL, L"FPDIBrushOptionDataGetOpacity"},
	{FPDIBrushOptionDataSEL, FPDIBrushOptionDataSetBaseBrushDiameterSEL, L"FPDIBrushOptionDataSetBaseBrushDiameter"},
	{FPDIBrushOptionDataSEL, FPDIBrushOptionDataGetBaseBrushDiameterSEL, L"FPDIBrushOptionDataGetBaseBrushDiameter"},
	{FPDIBrushOptionDataSEL, FPDIBrushOptionDataSetBaseBrushHardnessSEL, L"FPDIBrushOptionDataSetBaseBrushHardness"},
	{FPDIBrushOptionDataSEL, FPDIBrushOptionDataGetBaseBrushHardnessSEL, L"FPDIBrushOptionDataGetBaseBrushHardness"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataSetEraserModeSEL, L"FPDIEraserOptionDataSetEraserMode"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataGetEraserModeSEL, L"FPDIEraserOptionDataGetEraserMode"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataSetFlowSEL, L"FPDIEraserOptionDataSetFlow"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataGetFlowSEL, L"FPDIEraserOptionDataGetFlow"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataSetOpacitySEL, L"FPDIEraserOptionDataSetOpacity"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataGetOpacitySEL, L"FPDIEraserOptionDataGetOpacity"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataSetEraserHistorySEL, L"FPDIEraserOptionDataSetEraserHistory"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataGetEraserHistorySEL, L"FPDIEraserOptionDataGetEraserHistory"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataSetBaseBrushDiameterSEL, L"FPDIEraserOptionDataSetBaseBrushDiameter"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataGetBaseBrushDiameterSEL, L"FPDIEraserOptionDataGetBaseBrushDiameter"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataSetBaseBrushHardnessSEL, L"FPDIEraserOptionDataSetBaseBrushHardness"},
	{FPDIEraserOptionDataSEL, FPDIEraserOptionDataGetBaseBrushHardnessSEL, L"FPDIEraserOptionDataGetBaseBrushHardness"},
	{FPDIMagicWandOptionDataSEL, FPDIMagicWandOptionDataSetToleranceSEL, L"FPDIMagicWandOptionDataSetTolerance"},
	{FPDIMagicWandOptionDataSEL, FPDIMagicWandOptionDataGetToleranceSEL, L"FPDIMagicWandOptionDataGetTolerance"},
	{FPDIMagicWandOptionDataSEL, FPDIMagicWandOptionDataSetIsContinuousSEL, L"FPDIMagicWandOptionDataSetIsContinuous"},
	{FPDIMagicWandOptionDataSEL, FPDIMagicWandOptionDataGetIsContinuousSEL, L"FPDIMagicWandOptionDataGetIsContinuous"},
	{FPDIDodgeOptionDataSEL, FPDIDodgeOptionDataSetDodgeModeSEL, L"FPDIDodgeOptionDataSetDodgeMode"},
	{FPDIDodgeOptionDataSEL, FPDIDodgeOptionDataGetDodgeModeSEL, L"FPDIDodgeOptionDataGetDodgeMode"},
	{FPDIDodgeOptionDataSEL, FPDIDodgeOptionDataSetFlowSEL, L"FPDIDodgeOptionDataSetFlow"},
	{FPDIDodgeOptionDataSEL, FPDIDodgeOptionDataGetFlowSEL, L"FPDIDodgeOptionDataGetFlow"},
	{FPDIDodgeOptionDataSEL, FPDIDodgeOptionDataSetOpacitySEL, L"FPDIDodgeOptionDataSetOpacity"},
	{FPDIDodgeOptionDataSEL, FPDIDodgeOptionDataGetOpacitySEL, L"FPDIDodgeOptionDataGetOpacity"},
	{FPDIDodgeOptionDataSEL, FPDIDodgeOptionDataSetBaseBrushDiameterSEL, L"FPDIDodgeOptionDataSetBaseBrushDiameter"},
	{FPDIDodgeOptionDataSEL, FPDIDodgeOptionDataGetBaseBrushDiameterSEL, L"FPDIDodgeOptionDataGetBaseBrushDiameter"},
	{FPDIDodgeOptionDataSEL, FPDIDodgeOptionDataSetBaseBrushHardnessSEL, L"FPDIDodgeOptionDataSetBaseBrushHardness"},
	{FPDIDodgeOptionDataSEL, FPDIDodgeOptionDataGetBaseBrushHardnessSEL, L"FPDIDodgeOptionDataGetBaseBrushHardness"},
	{FPDIBurnOptionDataSEL, FPDIBurnOptionDataSetFlowSEL, L"FPDIBurnOptionDataSetFlow"},
	{FPDIBurnOptionDataSEL, FPDIBurnOptionDataGetFlowSEL, L"FPDIBurnOptionDataGetFlow"},
	{FPDIBurnOptionDataSEL, FPDIBurnOptionDataSetOpacitySEL, L"FPDIBurnOptionDataSetOpacity"},
	{FPDIBurnOptionDataSEL, FPDIBurnOptionDataGetOpacitySEL, L"FPDIBurnOptionDataGetOpacity"},
	{FPDIBurnOptionDataSEL, FPDIBurnOptionDataSetBurnModeSEL, L"FPDIBurnOptionDataSetBurnMode"},
	{FPDIBurnOptionDataSEL, FPDIBurnOptionDataGetBurnModeSEL, L"FPDIBurnOptionDataGetBurnMode"},
	{FPDIBurnOptionDataSEL, FPDIBurnOptionDataSetBaseBrushDiameterSEL, L"FPDIBurnOptionDataSetBaseBrushDiameter"},
	{FPDIBurnOptionDataSEL, FPDIBurnOptionDataGetBaseBrushDiameterSEL, L"FPDIBurnOptionDataGetBaseBrushDiameter"},
	{FPDIBurnOptionDataSEL, FPDIBurnOptionDataSetBaseBrushHardnessSEL, L"FPDIBurnOptionDataSetBaseBrushHardness"},
	{FPDIBurnOptionDataSEL, FPDIBurnOptionDataGetBaseBrushHardnessSEL, L"FPDIBurnOptionDataGetBaseBrushHardness"},
	{FPDIEyedropperDataSEL, FPDIEyedropperDataGetSampleTypeSEL, L"FPDIEyedropperDataGetSampleType"},
	{FPDIEyedropperDataSEL, FPDIEyedropperDataSetSampleTypeSEL, L"FPDIEyedropperDataSetSampleType"},
	{FPDICloneStampDataSEL, FPDICloneStampDataSetBlendModeSEL, L"FPDICloneStampDataSetBlendMode"},
	{FPDICloneStampDataSEL, FPDICloneStampDataGetBlendModeSEL, L"FPDICloneStampDataGetBlendMode"},
	{FPDICloneStampDataSEL, FPDICloneStampDataSetFlowSEL, L"FPDICloneStampDataSetFlow"},
	{FPDICloneStampDataSEL, FPDICloneStampDataGetFlowSEL, L"FPDICloneStampDataGetFlow"},
	{FPDICloneStampDataSEL, FPDICloneStampDataSetOpacitySEL, L"FPDICloneStampDataSetOpacity"},
	{FPDICloneStampDataSEL, FPDICloneStampDataGetOpacitySEL, L"FPDICloneStampDataGetOpacity"},
	{FPDICloneStampDataSEL, FPDICloneStampDataSetIsAlineCheckSEL, L"FPDICloneStampDataSetIsAlineCheck"},
	{FPDICloneStampDataSEL, FPDICloneStampDataGetIsAlineCheckSEL, L"FPDICloneStampDataGetIsAlineCheck"},
	{FPDICloneStampDataSEL, FPDICloneStampDataSetBaseBrushDiameterSEL, L"FPDICloneStampDataSetBaseBrushDiameter"},
	{FPDICloneStampDataSEL, FPDICloneStampDataGetBaseBrushDiameterSEL, L"FPDICloneStampDataGetBaseBrushDiameter"},
	{FPDICloneStampDataSEL, FPDICloneStampDataSetBaseBrushHardnessSEL, L"FPDICloneStampDataSetBaseBrushHardness"},
	{FPDICloneStampDataSEL, FPDICloneStampDataGetBaseBrushHardnessSEL, L"FPDICloneStampDataGetBaseBrushHardness"},
	{FPDIPaintBucketOptionDataSEL, FPDIPaintBucketOptionDataSetToleranceSEL, L"FPDIPaintBucketOptionDataSetTolerance"},
	{FPDIPaintBucketOptionDataSEL, FPDIPaintBucketOptionDataGetToleranceSEL, L"FPDIPaintBucketOptionDataGetTolerance"},
	{FPDIPaintBucketOptionDataSEL, FPDIPaintBucketOptionDataSetOpacitySEL, L"FPDIPaintBucketOptionDataSetOpacity"},
	{FPDIPaintBucketOptionDataSEL, FPDIPaintBucketOptionDataGetOpacitySEL, L"FPDIPaintBucketOptionDataGetOpacity"},
	{FPDIPaintBucketOptionDataSEL, FPDIPaintBucketOptionDataSetColorBlendModeSEL, L"FPDIPaintBucketOptionDataSetColorBlendMode"},
	{FPDIPaintBucketOptionDataSEL, FPDIPaintBucketOptionDataGetColorBlendModeSEL, L"FPDIPaintBucketOptionDataGetColorBlendMode"},
	{FPDIPaintBucketOptionDataSEL, FPDIPaintBucketOptionDataSetContinuousSEL, L"FPDIPaintBucketOptionDataSetContinuous"},
	{FPDIPaintBucketOptionDataSEL, FPDIPaintBucketOptionDataGetContinuousSEL, L"FPDIPaintBucketOptionDataGetContinuous"},
	{FPDISpotHealingBrushDataSEL, FPDISpotHealingBrushDataGetDiameterSEL, L"FPDISpotHealingBrushDataGetDiameter"},
	{FPDISpotHealingBrushDataSEL, FPDISpotHealingBrushDataSetDiameterSEL, L"FPDISpotHealingBrushDataSetDiameter"},
	{FPDISpotHealingBrushDataSEL, FPDISpotHealingBrushDataGetRoundnessSEL, L"FPDISpotHealingBrushDataGetRoundness"},
	{FPDISpotHealingBrushDataSEL, FPDISpotHealingBrushDataSetRoundnessSEL, L"FPDISpotHealingBrushDataSetRoundness"},
	{FPDISpotHealingBrushDataSEL, FPDISpotHealingBrushDataGetAlineSEL, L"FPDISpotHealingBrushDataGetAline"},
	{FPDISpotHealingBrushDataSEL, FPDISpotHealingBrushDataSetAlineSEL, L"FPDISpotHealingBrushDataSetAline"},
	{FPDISpotHealingBrushDataSEL, FPDISpotHealingBrushDataGetModeSEL, L"FPDISpotHealingBrushDataGetMode"},
	{FPDISpotHealingBrushDataSEL, FPDISpotHealingBrushDataSetModeSEL, L"FPDISpotHealingBrushDataSetMode"},
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
	{FPD3DCompositionProviderSEL, FPD3DCompositionProviderNewSEL, L"FPD3DCompositionProviderNew"},
	{FPD3DCompositionProviderSEL, FPD3DCompositionProviderDestroySEL, L"FPD3DCompositionProviderDestroy"},
	{FPDBoundingBoxSEL, FPDBoundingBoxCreateBoxSEL, L"FPDBoundingBoxCreateBox"},
	{FPDBoundingBoxSEL, FPDBoundingBoxDeleteBoxSEL, L"FPDBoundingBoxDeleteBox"},
	{FPDBoundingBoxSEL, FPDBoundingBoxGetSqrSEL, L"FPDBoundingBoxGetSqr"},
	{FPDBoundingBoxSEL, FPDBoundingBoxGetCenterSEL, L"FPDBoundingBoxGetCenter"},
	{FPDBoundingBoxSEL, FPDBoundingBoxGetSizeSEL, L"FPDBoundingBoxGetSize"},
	{FPDBoundingBoxSEL, FPDBoundingBoxGetMaxValuesSEL, L"FPDBoundingBoxGetMaxValues"},
	{FPDBoundingBoxSEL, FPDBoundingBoxGetMinValuesSEL, L"FPDBoundingBoxGetMinValues"},
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
	{FPDCertStoreSEL, FPDCertStoreNewSEL, L"FPDCertStoreNew"},
	{FPDCertStoreSEL, FPDCertStoreDestroySEL, L"FPDCertStoreDestroy"},
	{FPDCertStoreSEL, FPDCertStoreGetHCertStoreSEL, L"FPDCertStoreGetHCertStore"},
	{FPDCertStoreSEL, FPDCertStoreLoadMYSystemCertsSEL, L"FPDCertStoreLoadMYSystemCerts"},
	{FPDCertStoreSEL, FPDCertStoreGetCertFromCertSNIdSEL, L"FPDCertStoreGetCertFromCertSNId"},
	{FPDCertStoreSEL, FPDCertStoreGetCertSNIDSEL, L"FPDCertStoreGetCertSNID"},
	{FPDCertStoreSEL, FPDCertStoreGetCertCountSEL, L"FPDCertStoreGetCertCount"},
	{FPDCertStoreSEL, FPDCertStoreGetCertsArraySEL, L"FPDCertStoreGetCertsArray"},
	{FPDCertStoreSEL, FPDCertStoreIsPrivateKeyCertSEL, L"FPDCertStoreIsPrivateKeyCert"},
	{FPDCertStoreSEL, FPDCertStoreLoadOtherCertsSEL, L"FPDCertStoreLoadOtherCerts"},
	{FPDCertStoreSEL, FPDCertStoreLoadFileCertsSEL, L"FPDCertStoreLoadFileCerts"},
	{FPDCertStoreSEL, FPDCertStoreAddCertSEL, L"FPDCertStoreAddCert"},
	{FPDCertStoreSEL, FPDCertStoreAddCertsSEL, L"FPDCertStoreAddCerts"},
	{FPDCertStoreSEL, FPDCertStoreAddDocDssCertsSEL, L"FPDCertStoreAddDocDssCerts"},
	{FPDCertStoreSEL, FPDCertStoreGetCertFromCertSNIDHEXSEL, L"FPDCertStoreGetCertFromCertSNIDHEX"},
	{FPDCertStoreSEL, FPDCertStoreFindCertSEL, L"FPDCertStoreFindCert"},
	{FPDCertStoreSEL, FPDCertStoreIsPrivateHasUsageSEL, L"FPDCertStoreIsPrivateHasUsage"},
	{FPDCertStoreSEL, FPDCertStoreIsSm2SignWithSm3SEL, L"FPDCertStoreIsSm2SignWithSm3"},
	{FPDCertStoreSEL, FPDCertStoreAddCert2SEL, L"FPDCertStoreAddCert2"},
	{FPDPageLabelSEL, FPDPageLabelNewSEL, L"FPDPageLabelNew"},
	{FPDPageLabelSEL, FPDPageLabelDestroySEL, L"FPDPageLabelDestroy"},
	{FPDPageLabelSEL, FPDPageLabelGetLabelSEL, L"FPDPageLabelGetLabel"},
	{FPDPageLabelSEL, FPDPageLabelGetPageByLabelSEL, L"FPDPageLabelGetPageByLabel"},
	{FPDPageLabelSEL, FPDPageLabelGetPageByLabel2SEL, L"FPDPageLabelGetPageByLabel2"},
	{FPDSignCertSEL, FPDSignCertCreateCertSEL, L"FPDSignCertCreateCert"},
	{FPDSignCertSEL, FPDSignCertDestroyCertSEL, L"FPDSignCertDestroyCert"},
	{FPDSignCertSEL, FPDSignCertInitSEL, L"FPDSignCertInit"},
	{FPDSignCertSEL, FPDSignCertInit1SEL, L"FPDSignCertInit1"},
	{FPDSignCertSEL, FPDSignCertInit2SEL, L"FPDSignCertInit2"},
	{FPDSignCertSEL, FPDSignCertGetStreamSEL, L"FPDSignCertGetStream"},
	{FPDSignCertHandlerSEL, FPDSignCertHandlerNewSEL, L"FPDSignCertHandlerNew"},
	{FPDSignCertHandlerSEL, FPDSignCertHandlerDestroySEL, L"FPDSignCertHandlerDestroy"},
	{FPDCertMethodSEL, FPDCertMethodGetCertSNIDSEL, L"FPDCertMethodGetCertSNID"},
	{FPDCertMethodSEL, FPDCertMethodGetCertSNIDHEXSEL, L"FPDCertMethodGetCertSNIDHEX"},
	{FPDCertMethodSEL, FPDCertMethodGetCertChainsFromCertSEL, L"FPDCertMethodGetCertChainsFromCert"},
	{FPDCertMethodSEL, FPDCertMethodFreeCertChainsSEL, L"FPDCertMethodFreeCertChains"},
	{FPDCertMethodSEL, FPDCertMethodGetCertChainsFromCert1SEL, L"FPDCertMethodGetCertChainsFromCert1"},
	{FPDCertMethodSEL, FPDCertMethodClearCertPinSEL, L"FPDCertMethodClearCertPin"},
	{FPDCertMethodSEL, FPDCertMethodGetCertIssuerSEL, L"FPDCertMethodGetCertIssuer"},
	{FPDCertMethodSEL, FPDCertMethodGetCertExpriesSEL, L"FPDCertMethodGetCertExpries"},
	{FPDCertMethodSEL, FPDCertMethodGetCertIssuerNameSEL, L"FPDCertMethodGetCertIssuerName"},
	{FPDCertMethodSEL, FPDCertMethodGetCertNameSEL, L"FPDCertMethodGetCertName"},
	{FPDCertMethodSEL, FPDCertMethodGetSignerNameSEL, L"FPDCertMethodGetSignerName"},
	{FPDCertMethodSEL, FPDCertMethodIsSelfSignedCertSEL, L"FPDCertMethodIsSelfSignedCert"},
	{FPDCertMethodSEL, FPDCertMethodIsValidRootSEL, L"FPDCertMethodIsValidRoot"},
	{FPDCertMethodSEL, FPDCertMethodGetCertStartTimeSEL, L"FPDCertMethodGetCertStartTime"},
	{FPDCertMethodSEL, FPDCertMethodGetCertStartTime1SEL, L"FPDCertMethodGetCertStartTime1"},
	{FPDCertMethodSEL, FPDCertMethodGetCertExpiredTimeSEL, L"FPDCertMethodGetCertExpiredTime"},
	{FPDCertMethodSEL, FPDCertMethodSystemTimeToStringSEL, L"FPDCertMethodSystemTimeToString"},
	{FPDCertMethodSEL, FPDCertMethodCertOverdueSEL, L"FPDCertMethodCertOverdue"},
	{FPDCertMethodSEL, FPDCertMethodCertToStringSEL, L"FPDCertMethodCertToString"},
	{FPDCertMethodSEL, FPDCertMethodGetCertDNSEL, L"FPDCertMethodGetCertDN"},
	{FPDCertMethodSEL, FPDCertMethodCertCloneSEL, L"FPDCertMethodCertClone"},
	{FPDCertMethodSEL, FPDCertMethodGetExtKeyUsageSEL, L"FPDCertMethodGetExtKeyUsage"},
	{FPDCertMethodSEL, FPDCertMethodGetCertStartTime2SEL, L"FPDCertMethodGetCertStartTime2"},
	{FPDCertMethodSEL, FPDCertMethodGetCertExpritesTimeSEL, L"FPDCertMethodGetCertExpritesTime"},
	{FPDCertMethodSEL, FPDCertMethodCsToHexSEL, L"FPDCertMethodCsToHex"},
	{FPDCertMethodSEL, FPDCertMethodGenerateHashDataSEL, L"FPDCertMethodGenerateHashData"},
	{FPDCertMethodSEL, FPDCertMethodGenerateHashData1SEL, L"FPDCertMethodGenerateHashData1"},
	{FPDCertMethodSEL, FPDCertMethodFindCustomSignOIDSEL, L"FPDCertMethodFindCustomSignOID"},
	{FPDCertMethodSEL, FPDCertMethodGetQCStatementsSEL, L"FPDCertMethodGetQCStatements"},
	{FPDCertMethodSEL, FPDCertMethodIsTime1NotLaterThanTime2SEL, L"FPDCertMethodIsTime1NotLaterThanTime2"},
	{FPDSignCRLSEL, FPDSignCRLNewSEL, L"FPDSignCRLNew"},
	{FPDSignCRLSEL, FPDSignCRLDestroySEL, L"FPDSignCRLDestroy"},
	{FPDSignCRLSEL, FPDSignCRLInitSEL, L"FPDSignCRLInit"},
	{FPDSignCRLSEL, FPDSignCRLInit1SEL, L"FPDSignCRLInit1"},
	{FPDSignCRLSEL, FPDSignCRLGetStreamSEL, L"FPDSignCRLGetStream"},
	{FPDSignOCSPSEL, FPDSignOCSPNewSEL, L"FPDSignOCSPNew"},
	{FPDSignOCSPSEL, FPDSignOCSPDestroySEL, L"FPDSignOCSPDestroy"},
	{FPDSignOCSPSEL, FPDSignOCSPInitSEL, L"FPDSignOCSPInit"},
	{FPDSignOCSPSEL, FPDSignOCSPInit1SEL, L"FPDSignOCSPInit1"},
	{FPDSignOCSPSEL, FPDSignOCSPGetStreamSEL, L"FPDSignOCSPGetStream"},
	{FPDCGWSignDataRevoInfoSEL, FPDCGWSignDataRevoInfoGetTypeSEL, L"FPDCGWSignDataRevoInfoGetType"},
	{FPDCGWSignDataRevoInfoSEL, FPDCGWSignDataRevoInfoSetTypeSEL, L"FPDCGWSignDataRevoInfoSetType"},
	{FPDCGWSignDataRevoInfoSEL, FPDCGWSignDataRevoInfoGetRevoInfoPDFSteamSEL, L"FPDCGWSignDataRevoInfoGetRevoInfoPDFSteam"},
	{FPDCGWSignDataRevoInfoSEL, FPDCGWSignDataRevoInfoGetRevoinfoSizeSEL, L"FPDCGWSignDataRevoInfoGetRevoinfoSize"},
	{FPDCGWSignDataRevoInfoSEL, FPDCGWSignDataRevoInfoGetLocalSignVarifyTimeSEL, L"FPDCGWSignDataRevoInfoGetLocalSignVarifyTime"},
	{FPDCGWSignDataRevoInfoSEL, FPDCGWSignDataRevoInfoSetLocalSignVarifyTimeSEL, L"FPDCGWSignDataRevoInfoSetLocalSignVarifyTime"},
	{FPDCGWSignDataRevoInfoSEL, FPDCGWSignDataRevoInfoGetLocalRevoCheckTimeSEL, L"FPDCGWSignDataRevoInfoGetLocalRevoCheckTime"},
	{FPDCGWSignDataRevoInfoSEL, FPDCGWSignDataRevoInfoSetLocalRevoCheckTimeSEL, L"FPDCGWSignDataRevoInfoSetLocalRevoCheckTime"},
	{FPDCGWSignDataRevoInfoSEL, FPDCGWSignDataRevoInfoGetRevoInfoHashKeySEL, L"FPDCGWSignDataRevoInfoGetRevoInfoHashKey"},
	{FPDCGWSignDataRevoInfoSEL, FPDCGWSignDataRevoInfoDestroySEL, L"FPDCGWSignDataRevoInfoDestroy"},
	{FPDReovcationProgressCallBackSEL, FPDReovcationProgressCallBackNewSEL, L"FPDReovcationProgressCallBackNew"},
	{FPDReovcationProgressCallBackSEL, FPDReovcationProgressCallBackDestroySEL, L"FPDReovcationProgressCallBackDestroy"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATANewSEL, L"FPDCHECKREVOINFODATANew"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATADestroySEL, L"FPDCHECKREVOINFODATADestroy"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATAGetSignContensSEL, L"FPDCHECKREVOINFODATAGetSignContens"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATASetSignContensSEL, L"FPDCHECKREVOINFODATASetSignContens"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATAGetSignHashSEL, L"FPDCHECKREVOINFODATAGetSignHash"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATASetSignHashSEL, L"FPDCHECKREVOINFODATASetSignHash"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATASetETypeSEL, L"FPDCHECKREVOINFODATASetEType"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATAGetETypeSEL, L"FPDCHECKREVOINFODATAGetEType"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATAGetUTCtimeSEL, L"FPDCHECKREVOINFODATAGetUTCtime"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATASetUTCtimeSEL, L"FPDCHECKREVOINFODATASetUTCtime"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATAGetDSSInfoSEL, L"FPDCHECKREVOINFODATAGetDSSInfo"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATASetDSSInfoSEL, L"FPDCHECKREVOINFODATASetDSSInfo"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATAGetSignInfoSEL, L"FPDCHECKREVOINFODATAGetSignInfo"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATASetSignInfoSEL, L"FPDCHECKREVOINFODATASetSignInfo"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATASetEReturnTypeSEL, L"FPDCHECKREVOINFODATASetEReturnType"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATAGetEReturnTypeSEL, L"FPDCHECKREVOINFODATAGetEReturnType"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATAGetReturnUTCtimeSEL, L"FPDCHECKREVOINFODATAGetReturnUTCtime"},
	{FPDCHECKREVOINFODATASEL, FPDCHECKREVOINFODATASetReturnUTCtimeSEL, L"FPDCHECKREVOINFODATASetReturnUTCtime"},
	{FPDCHECKDataSEL, FPDCHECKDataNewSEL, L"FPDCHECKDataNew"},
	{FPDCHECKDataSEL, FPDCHECKDataDestroySEL, L"FPDCHECKDataDestroy"},
	{FPDCHECKDataSEL, FPDCHECKDataGetCheckDataTypeSEL, L"FPDCHECKDataGetCheckDataType"},
	{FPDCHECKDataSEL, FPDCHECKDataSetCheckDataTypeSEL, L"FPDCHECKDataSetCheckDataType"},
	{FPDCHECKDataSEL, FPDCHECKDataGetSigntimeSEL, L"FPDCHECKDataGetSigntime"},
	{FPDCHECKDataSEL, FPDCHECKDataSetSigntimeSEL, L"FPDCHECKDataSetSigntime"},
	{FPDCHECKDataSEL, FPDCHECKDataGetNexttimeSEL, L"FPDCHECKDataGetNexttime"},
	{FPDCHECKDataSEL, FPDCHECKDataSetNexttimeSEL, L"FPDCHECKDataSetNexttime"},
	{FPDCHECKDataSEL, FPDCHECKDataGetRevocationtimeSEL, L"FPDCHECKDataGetRevocationtime"},
	{FPDCHECKDataSEL, FPDCHECKDataSetRevocationtimeSEL, L"FPDCHECKDataSetRevocationtime"},
	{FPDCHECKDataSEL, FPDCHECKDataGetIssuerSEL, L"FPDCHECKDataGetIssuer"},
	{FPDCHECKDataSEL, FPDCHECKDataSetIssuerSEL, L"FPDCHECKDataSetIssuer"},
	{FPDCHECKDataSEL, FPDCHECKDataGetURLSEL, L"FPDCHECKDataGetURL"},
	{FPDCHECKDataSEL, FPDCHECKDataSetURLSEL, L"FPDCHECKDataSetURL"},
	{FPDCHECKDataSEL, FPDCHECKDataGetResponseDataSEL, L"FPDCHECKDataGetResponseData"},
	{FPDCHECKDataSEL, FPDCHECKDataSetResponseDataSEL, L"FPDCHECKDataSetResponseData"},
	{FPDCHECKDataSEL, FPDCHECKDataGetRevoDataSEL, L"FPDCHECKDataGetRevoData"},
	{FPDCHECKDataSEL, FPDCHECKDataSetResponseData2SEL, L"FPDCHECKDataSetResponseData2"},
	{FPDCHECKDataSEL, FPDCHECKDataGetResponseIssuerSEL, L"FPDCHECKDataGetResponseIssuer"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeCreateRevokeSEL, L"FPDVerifyRevokeCreateRevoke"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeDeleteRevokeSEL, L"FPDVerifyRevokeDeleteRevoke"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeSetReovactionProgressCallBackSEL, L"FPDVerifyRevokeSetReovactionProgressCallBack"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeCheckRevoInfoSEL, L"FPDVerifyRevokeCheckRevoInfo"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeSetRevoCheckTimeSEL, L"FPDVerifyRevokeSetRevoCheckTime"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeSetSignTimeSEL, L"FPDVerifyRevokeSetSignTime"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeSetCRLPathSEL, L"FPDVerifyRevokeSetCRLPath"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeSetTimeOutUrlSEL, L"FPDVerifyRevokeSetTimeOutUrl"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeGetTimeOutUrlSEL, L"FPDVerifyRevokeGetTimeOutUrl"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeSetCertAndIssureSEL, L"FPDVerifyRevokeSetCertAndIssure"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeClearCheckDataSEL, L"FPDVerifyRevokeClearCheckData"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeClearCheckRevoSEL, L"FPDVerifyRevokeClearCheckRevo"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeGetRevoInfoInDssSEL, L"FPDVerifyRevokeGetRevoInfoInDss"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeGetDSSDataRevoinfoSEL, L"FPDVerifyRevokeGetDSSDataRevoinfo"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeGetSignDataRevoinfoSEL, L"FPDVerifyRevokeGetSignDataRevoinfo"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeCheckCertRevo_onlineSEL, L"FPDVerifyRevokeCheckCertRevo_online"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeCheckRevoInfoInSignDataSEL, L"FPDVerifyRevokeCheckRevoInfoInSignData"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeGetXCertSEL, L"FPDVerifyRevokeGetXCert"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeGetXIssuerSEL, L"FPDVerifyRevokeGetXIssuer"},
	{FPDVerifyRevokeSEL, FPDVerifyRevokeSetCRLDownloadHandlerSEL, L"FPDVerifyRevokeSetCRLDownloadHandler"},
	{FPDVRISEL, FPDVRICreateVRISEL, L"FPDVRICreateVRI"},
	{FPDVRISEL, FPDVRICreateVRI1SEL, L"FPDVRICreateVRI1"},
	{FPDVRISEL, FPDVRIDeleteVRISEL, L"FPDVRIDeleteVRI"},
	{FPDVRISEL, FPDVRIAddTUSEL, L"FPDVRIAddTU"},
	{FPDVRISEL, FPDVRIAddCRLSEL, L"FPDVRIAddCRL"},
	{FPDVRISEL, FPDVRIAddOCSPSEL, L"FPDVRIAddOCSP"},
	{FPDVRISEL, FPDVRIIsInArraySEL, L"FPDVRIIsInArray"},
	{FPDVRISEL, FPDVRIGetDictSEL, L"FPDVRIGetDict"},
	{FPDVRISEL, FPDVRIGetCRLArraySEL, L"FPDVRIGetCRLArray"},
	{FPDVRISEL, FPDVRIGetOCSPArraySEL, L"FPDVRIGetOCSPArray"},
	{FPDDSSSEL, FPDDSSCreateDSSSEL, L"FPDDSSCreateDSS"},
	{FPDDSSSEL, FPDDSSDeleteDSSSEL, L"FPDDSSDeleteDSS"},
	{FPDDSSSEL, FPDDSSIsEmptySEL, L"FPDDSSIsEmpty"},
	{FPDDSSSEL, FPDDSSAddVRISEL, L"FPDDSSAddVRI"},
	{FPDDSSSEL, FPDDSSAddVRI1SEL, L"FPDDSSAddVRI1"},
	{FPDDSSSEL, FPDDSSGetVRIDictSEL, L"FPDDSSGetVRIDict"},
	{FPDDSSSEL, FPDDSSGetCertArraySEL, L"FPDDSSGetCertArray"},
	{FPDDSSSEL, FPDDSSGetCRLArraySEL, L"FPDDSSGetCRLArray"},
	{FPDDSSSEL, FPDDSSGetOCSPArraySEL, L"FPDDSSGetOCSPArray"},
	{FPDDSSSEL, FPDDSSGetDSSSEL, L"FPDDSSGetDSS"},
	{FPDDSSSEL, FPDDSSCreateDSSForDocSEL, L"FPDDSSCreateDSSForDoc"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultCreateVerifyResultSEL, L"FPDSignatureVerifyResultCreateVerifyResult"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultDeleteResultSEL, L"FPDSignatureVerifyResultDeleteResult"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultSetOCSPRespResultSEL, L"FPDSignatureVerifyResultSetOCSPRespResult"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultSetTSTResultSEL, L"FPDSignatureVerifyResultSetTSTResult"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultGetSignatureNameSEL, L"FPDSignatureVerifyResultGetSignatureName"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultGetSignatureHashSEL, L"FPDSignatureVerifyResultGetSignatureHash"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultGetSignatureStatusSEL, L"FPDSignatureVerifyResultGetSignatureStatus"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultGetSigCheckTimeSEL, L"FPDSignatureVerifyResultGetSigCheckTime"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultGetLTVattributeSEL, L"FPDSignatureVerifyResultGetLTVattribute"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultGetSigCheckTimeTypeSEL, L"FPDSignatureVerifyResultGetSigCheckTimeType"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultGetCertResultStringSEL, L"FPDSignatureVerifyResultGetCertResultString"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultGetCertVerifyResultSEL, L"FPDSignatureVerifyResultGetCertVerifyResult"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultGetOCSPSigResultSEL, L"FPDSignatureVerifyResultGetOCSPSigResult"},
	{FPDSignatureVerifyResultSEL, FPDSignatureVerifyResultGetSigTSTResultSEL, L"FPDSignatureVerifyResultGetSigTSTResult"},
	{FPDTrustedCertStoreSEL, FPDTrustedCertStoreNewSEL, L"FPDTrustedCertStoreNew"},
	{FPDTrustedCertStoreSEL, FPDTrustedCertStoreDestroySEL, L"FPDTrustedCertStoreDestroy"},
	{FPDLtvVerifierSEL, FPDLtvVerifierNewSEL, L"FPDLtvVerifierNew"},
	{FPDLtvVerifierSEL, FPDLtvVerifierDestorySEL, L"FPDLtvVerifierDestory"},
	{FPDLtvVerifierSEL, FPDLtvVerifierSetRevocationHandlerSEL, L"FPDLtvVerifierSetRevocationHandler"},
	{FPDLtvVerifierSEL, FPDLtvVerifierSetVerifyModeSEL, L"FPDLtvVerifierSetVerifyMode"},
	{FPDLtvVerifierSEL, FPDLtvVerifierSetCertStoreSEL, L"FPDLtvVerifierSetCertStore"},
	{FPDLtvVerifierSEL, FPDLtvVerifierVerifySEL, L"FPDLtvVerifierVerify"},
	{FPDLtvVerifierSEL, FPDLtvVerifierVerifySingleSigSEL, L"FPDLtvVerifierVerifySingleSig"},
	{FPDLtvVerifierSEL, FPDLtvVerifierAddDSSSEL, L"FPDLtvVerifierAddDSS"},
	{FPDSigModifyListSEL, FPDSigModifyListNewSEL, L"FPDSigModifyListNew"},
	{FPDSigModifyListSEL, FPDSigModifyListDeleteSEL, L"FPDSigModifyListDelete"},
	{FPDSigModifyListSEL, FPDSigModifyListGetOBJECTTYPEListSEL, L"FPDSigModifyListGetOBJECTTYPEList"},
	{FPDSigModifyListSEL, FPDSigModifyListGetMODIFYTYPEByOBJTYPESEL, L"FPDSigModifyListGetMODIFYTYPEByOBJTYPE"},
	{FPDSigModifyListSEL, FPDSigModifyListGetMODIFYADATACountByModifyTypeSEL, L"FPDSigModifyListGetMODIFYADATACountByModifyType"},
	{FPDSigModifyListSEL, FPDSigModifyListGetMODIFYADATAByModifyTypeAndIndexSEL, L"FPDSigModifyListGetMODIFYADATAByModifyTypeAndIndex"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorNewSEL, L"FPDIncreSaveModifyDetectorNew"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorDeleteSEL, L"FPDIncreSaveModifyDetectorDelete"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorParseIncrementObjectSEL, L"FPDIncreSaveModifyDetectorParseIncrementObject"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorCheckLegalityForModifySEL, L"FPDIncreSaveModifyDetectorCheckLegalityForModify"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorGetAccessPermissionsSEL, L"FPDIncreSaveModifyDetectorGetAccessPermissions"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorIsHasSignSEL, L"FPDIncreSaveModifyDetectorIsHasSign"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorGetSignListCountSEL, L"FPDIncreSaveModifyDetectorGetSignListCount"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorFindIncrementIndexSEL, L"FPDIncreSaveModifyDetectorFindIncrementIndex"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorFindNextIncrementIndexSEL, L"FPDIncreSaveModifyDetectorFindNextIncrementIndex"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorFindPreIncrementIndexSEL, L"FPDIncreSaveModifyDetectorFindPreIncrementIndex"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorClearSignDataSEL, L"FPDIncreSaveModifyDetectorClearSignData"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorClearDataSEL, L"FPDIncreSaveModifyDetectorClearData"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorUpdateVerifyFromCHECKRESULTSEL, L"FPDIncreSaveModifyDetectorUpdateVerifyFromCHECKRESULT"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorGetModifyListForSignSEL, L"FPDIncreSaveModifyDetectorGetModifyListForSign"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorAddModifyDataSEL, L"FPDIncreSaveModifyDetectorAddModifyData"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorGetModifySignSEL, L"FPDIncreSaveModifyDetectorGetModifySign"},
	{FPDIncreSaveModifyDetectorSEL, FPDIncreSaveModifyDetectorGetSignByIndexSEL, L"FPDIncreSaveModifyDetectorGetSignByIndex"},
	{FPDPermissionResultSEL, FPDPermissionResultNewSEL, L"FPDPermissionResultNew"},
	{FPDPermissionResultSEL, FPDPermissionResultDestroySEL, L"FPDPermissionResultDestroy"},
	{FPDPermissionResultSEL, FPDPermissionResultGetPermissionsKeyArraySEL, L"FPDPermissionResultGetPermissionsKeyArray"},
	{FPDPermissionResultSEL, FPDPermissionResultGetPermissionsValueByKeySEL, L"FPDPermissionResultGetPermissionsValueByKey"},
	{FPDSignatureEditSEL, FPDSignatureEditNewSignatureEditSEL, L"FPDSignatureEditNewSignatureEdit"},
	{FPDSignatureEditSEL, FPDSignatureEditNewSignatureEdit1SEL, L"FPDSignatureEditNewSignatureEdit1"},
	{FPDSignatureEditSEL, FPDSignatureEditDeleteSignatureEditSEL, L"FPDSignatureEditDeleteSignatureEdit"},
	{FPDSignatureEditSEL, FPDSignatureEditLoadSignaturesSEL, L"FPDSignatureEditLoadSignatures"},
	{FPDSignatureEditSEL, FPDSignatureEditFixPageSignatureFieldsSEL, L"FPDSignatureEditFixPageSignatureFields"},
	{FPDSignatureEditSEL, FPDSignatureEditCountSignaturesSEL, L"FPDSignatureEditCountSignatures"},
	{FPDSignatureEditSEL, FPDSignatureEditGetSignatureSEL, L"FPDSignatureEditGetSignature"},
	{FPDSignatureEditSEL, FPDSignatureEditGetSignatureAtPosSEL, L"FPDSignatureEditGetSignatureAtPos"},
	{FPDSignatureEditSEL, FPDSignatureEditAddNewSignatureSEL, L"FPDSignatureEditAddNewSignature"},
	{FPDSignatureEditSEL, FPDSignatureEditUpdateSignatureSEL, L"FPDSignatureEditUpdateSignature"},
	{FPDSignatureEditSEL, FPDSignatureEditRemoveSignatureSEL, L"FPDSignatureEditRemoveSignature"},
	{FPDSignatureEditSEL, FPDSignatureEditRemoveSignaturesSEL, L"FPDSignatureEditRemoveSignatures"},
	{FPDSignatureEditSEL, FPDSignatureEditIsSignedSEL, L"FPDSignatureEditIsSigned"},
	{FPDSignatureSEL, FPDSignatureNewSignatureSEL, L"FPDSignatureNewSignature"},
	{FPDSignatureSEL, FPDSignatureNewSignature1SEL, L"FPDSignatureNewSignature1"},
	{FPDSignatureSEL, FPDSignatureDeleteSignatureSEL, L"FPDSignatureDeleteSignature"},
	{FPDSignatureSEL, FPDSignatureCreateSigVDictSEL, L"FPDSignatureCreateSigVDict"},
	{FPDSignatureSEL, FPDSignatureGetSignatureDictSEL, L"FPDSignatureGetSignatureDict"},
	{FPDSignatureSEL, FPDSignatureGetSignatureVDictSEL, L"FPDSignatureGetSignatureVDict"},
	{FPDSignatureSEL, FPDSignatureSetKeyValueSEL, L"FPDSignatureSetKeyValue"},
	{FPDSignatureSEL, FPDSignatureSetKeyValue1SEL, L"FPDSignatureSetKeyValue1"},
	{FPDSignatureSEL, FPDSignatureGetKeyValueSEL, L"FPDSignatureGetKeyValue"},
	{FPDSignatureSEL, FPDSignatureGetKeyValue1SEL, L"FPDSignatureGetKeyValue1"},
	{FPDSignatureSEL, FPDSignatureSetFlagsSEL, L"FPDSignatureSetFlags"},
	{FPDSignatureSEL, FPDSignatureGetFlagsSEL, L"FPDSignatureGetFlags"},
	{FPDSignatureSEL, FPDSignatureSetCertChainSEL, L"FPDSignatureSetCertChain"},
	{FPDSignatureSEL, FPDSignatureCountCertsSEL, L"FPDSignatureCountCerts"},
	{FPDSignatureSEL, FPDSignatureGetCertSEL, L"FPDSignatureGetCert"},
	{FPDSignatureSEL, FPDSignatureSetDataTimeSEL, L"FPDSignatureSetDataTime"},
	{FPDSignatureSEL, FPDSignatureGetDataTimeSEL, L"FPDSignatureGetDataTime"},
	{FPDSignatureSEL, FPDSignatureSetEstimateContentLengthSEL, L"FPDSignatureSetEstimateContentLength"},
	{FPDSignatureSEL, FPDSignatureGetEstimateContentLengthSEL, L"FPDSignatureGetEstimateContentLength"},
	{FPDSignatureSEL, FPDSignatureIsTimeStampSEL, L"FPDSignatureIsTimeStamp"},
	{FPDSignatureSEL, FPDSignatureResetAppearanceSEL, L"FPDSignatureResetAppearance"},
	{FPDSignatureSEL, FPDSignatureGetAppearanceSEL, L"FPDSignatureGetAppearance"},
	{FPDSignatureSEL, FPDSignatureSetPermissionsSEL, L"FPDSignatureSetPermissions"},
	{FPDSignatureSEL, FPDSignatureGetPermissionsSEL, L"FPDSignatureGetPermissions"},
	{FPDSignatureSEL, FPDSignatureSetFormFieldActionSEL, L"FPDSignatureSetFormFieldAction"},
	{FPDSignatureSEL, FPDSignatureGetFormFieldActionSEL, L"FPDSignatureGetFormFieldAction"},
	{FPDSignatureSEL, FPDSignatureSetJavaScriptSEL, L"FPDSignatureSetJavaScript"},
	{FPDSignatureSEL, FPDSignatureSetSignerCertPathSEL, L"FPDSignatureSetSignerCertPath"},
	{FPDSignatureSEL, FPDSignatureGetSignerCertPathSEL, L"FPDSignatureGetSignerCertPath"},
	{FPDSignatureSEL, FPDSignatureSetSignerCertFileStreamSEL, L"FPDSignatureSetSignerCertFileStream"},
	{FPDSignatureSEL, FPDSignatureGetSignerCertFileStreamSEL, L"FPDSignatureGetSignerCertFileStream"},
	{FPDSignatureSEL, FPDSignatureSetCertIDSEL, L"FPDSignatureSetCertID"},
	{FPDSignatureSEL, FPDSignatureGetPrivateKeySEL, L"FPDSignatureGetPrivateKey"},
	{FPDSignatureSEL, FPDSignatureGetCertIDSEL, L"FPDSignatureGetCertID"},
	{FPDSignatureSEL, FPDSignatureGetCertInfoTypeSEL, L"FPDSignatureGetCertInfoType"},
	{FPDSignatureSEL, FPDSignatureSetSignatureTypeSEL, L"FPDSignatureSetSignatureType"},
	{FPDSignatureSEL, FPDSignatureGetSignatureTypeSEL, L"FPDSignatureGetSignatureType"},
	{FPDSignatureSEL, FPDSignatureSetVerifyStateSEL, L"FPDSignatureSetVerifyState"},
	{FPDSignatureSEL, FPDSignatureGetVerifyStateSEL, L"FPDSignatureGetVerifyState"},
	{FPDSignatureSEL, FPDSignatureSetIncludeRevocationStatusSEL, L"FPDSignatureSetIncludeRevocationStatus"},
	{FPDSignatureSEL, FPDSignatureGetIncludeRevocationStatusSEL, L"FPDSignatureGetIncludeRevocationStatus"},
	{FPDSignatureSEL, FPDSignatureSetSMIDSEL, L"FPDSignatureSetSMID"},
	{FPDSignatureSEL, FPDSignatureGetSMIDSEL, L"FPDSignatureGetSMID"},
	{FPDSignatureSEL, FPDSignatureSetSealIDSEL, L"FPDSignatureSetSealID"},
	{FPDSignatureSEL, FPDSignatureGetSealIDSEL, L"FPDSignatureGetSealID"},
	{FPDSignatureSEL, FPDSignatureSetOnLineSEL, L"FPDSignatureSetOnLine"},
	{FPDSignatureSEL, FPDSignatureGetOnLineSEL, L"FPDSignatureGetOnLine"},
	{FPDSignatureSEL, FPDSignatureAddDSSVRISEL, L"FPDSignatureAddDSSVRI"},
	{FPDSignatureSEL, FPDSignatureAddDSSCertsSEL, L"FPDSignatureAddDSSCerts"},
	{FPDSignatureSEL, FPDSignatureAddDSSCRLsSEL, L"FPDSignatureAddDSSCRLs"},
	{FPDSignatureSEL, FPDSignatureAddDSSOCSPsSEL, L"FPDSignatureAddDSSOCSPs"},
	{FPDSignatureSEL, FPDSignatureIsHasFieldMDPSEL, L"FPDSignatureIsHasFieldMDP"},
	{FPDSignatureSignSEL, FPDSignatureSignNewSEL, L"FPDSignatureSignNew"},
	{FPDSignatureSignSEL, FPDSignatureSignNew1SEL, L"FPDSignatureSignNew1"},
	{FPDSignatureSignSEL, FPDSignatureSignNew2SEL, L"FPDSignatureSignNew2"},
	{FPDSignatureSignSEL, FPDSignatureSignDeleteSEL, L"FPDSignatureSignDelete"},
	{FPDSignatureSignSEL, FPDSignatureSignStartSEL, L"FPDSignatureSignStart"},
	{FPDSignatureSignSEL, FPDSignatureSignContinueSEL, L"FPDSignatureSignContinue"},
	{FPDSignatureSignSEL, FPDSignatureSignGetPercentSEL, L"FPDSignatureSignGetPercent"},
	{FPDSignatureSignSEL, FPDSignatureSignSetSignedFileSEL, L"FPDSignatureSignSetSignedFile"},
	{FPDSignatureSignSEL, FPDSignatureSignSetParserCallbackSEL, L"FPDSignatureSignSetParserCallback"},
	{FPDSignatureVerifySEL, FPDSignatureVerifyNewSEL, L"FPDSignatureVerifyNew"},
	{FPDSignatureVerifySEL, FPDSignatureVerifyNew1SEL, L"FPDSignatureVerifyNew1"},
	{FPDSignatureVerifySEL, FPDSignatureVerifyNew2SEL, L"FPDSignatureVerifyNew2"},
	{FPDSignatureVerifySEL, FPDSignatureVerifyNew3SEL, L"FPDSignatureVerifyNew3"},
	{FPDSignatureVerifySEL, FPDSignatureVerifyDeleteSEL, L"FPDSignatureVerifyDelete"},
	{FPDSignatureVerifySEL, FPDSignatureVerifyStartSEL, L"FPDSignatureVerifyStart"},
	{FPDSignatureVerifySEL, FPDSignatureVerifyContinueSEL, L"FPDSignatureVerifyContinue"},
	{FPDSignatureVerifySEL, FPDSignatureVerifyGetVerifyResultSEL, L"FPDSignatureVerifyGetVerifyResult"},
	{FPDSignatureVerifySEL, FPDSignatureVerifyGetVerifySubResultSEL, L"FPDSignatureVerifyGetVerifySubResult"},
	{FPDSignatureVerifySEL, FPDSignatureVerifyGetPercentSEL, L"FPDSignatureVerifyGetPercent"},
	{FPDTimeStampServerSEL, FPDTimeStampServerSendTimestampRequestSEL, L"FPDTimeStampServerSendTimestampRequest"},
	{FPDTimeStampServerSEL, FPDTimeStampServerGetTimestampSEL, L"FPDTimeStampServerGetTimestamp"},
	{FPDTimeStampServerSEL, FPDTimeStampServerGetServerNameSEL, L"FPDTimeStampServerGetServerName"},
	{FPDTimeStampServerSEL, FPDTimeStampServerGetUserNameFSEL, L"FPDTimeStampServerGetUserNameF"},
	{FPDTimeStampServerSEL, FPDTimeStampServerGetServerURLSEL, L"FPDTimeStampServerGetServerURL"},
	{FPDTimeStampServerSEL, FPDTimeStampServerGetPasswordSEL, L"FPDTimeStampServerGetPassword"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrCreateTimeStampServerMgrSEL, L"FPDTimeStampServerMgrCreateTimeStampServerMgr"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrGetTimeStampServerMgrSEL, L"FPDTimeStampServerMgrGetTimeStampServerMgr"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrDestroySEL, L"FPDTimeStampServerMgrDestroy"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrCreateNewServerSEL, L"FPDTimeStampServerMgrCreateNewServer"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrCountServersSEL, L"FPDTimeStampServerMgrCountServers"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrGetServerSEL, L"FPDTimeStampServerMgrGetServer"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrGetIndexSEL, L"FPDTimeStampServerMgrGetIndex"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrGetDefaultServerSEL, L"FPDTimeStampServerMgrGetDefaultServer"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrSetDefaultServerSEL, L"FPDTimeStampServerMgrSetDefaultServer"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrRemoveServerSEL, L"FPDTimeStampServerMgrRemoveServer"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrSetServerNotifySEL, L"FPDTimeStampServerMgrSetServerNotify"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrGetServerNotifySEL, L"FPDTimeStampServerMgrGetServerNotify"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrSetSSLRequestServerNotifySEL, L"FPDTimeStampServerMgrSetSSLRequestServerNotify"},
	{FPDTimeStampServerMgrSEL, FPDTimeStampServerMgrGetSSLRequestServerNotifySEL, L"FPDTimeStampServerMgrGetSSLRequestServerNotify"},
	{FPDSGBufferSEL, FPDSGBufferCreateBufferSEL, L"FPDSGBufferCreateBuffer"},
	{FPDSGBufferSEL, FPDSGBufferCreateBuffer1SEL, L"FPDSGBufferCreateBuffer1"},
	{FPDSGBufferSEL, FPDSGBufferDeleteBufferSEL, L"FPDSGBufferDeleteBuffer"},
	{FPDSGBufferSEL, FPDSGBufferGetBufferSEL, L"FPDSGBufferGetBuffer"},
	{FPDSGBufferSEL, FPDSGBufferGetSizeSEL, L"FPDSGBufferGetSize"},
	{FPDSGBufferSEL, FPDSGBufferIsEmptySEL, L"FPDSGBufferIsEmpty"},
	{FPDSGBufferSEL, FPDSGBufferIsEqualSEL, L"FPDSGBufferIsEqual"},
	{FPDSGBufferSEL, FPDSGBufferResetSEL, L"FPDSGBufferReset"},
	{FPDSGBufferSEL, FPDSGBufferDetachBufferSEL, L"FPDSGBufferDetachBuffer"},
	{FPDSGBufferSEL, FPDSGBufferReAllocSEL, L"FPDSGBufferReAlloc"},
	{FPDCertVerifyCallBackSEL, FPDCertVerifyCallBackNewSEL, L"FPDCertVerifyCallBackNew"},
	{FPDCertVerifyCallBackSEL, FPDCertVerifyCallBackDestroySEL, L"FPDCertVerifyCallBackDestroy"},
	{FPDCheckDataTemplateSEL, FPDCheckDataTemplateGetCheckDataTemplateSEL, L"FPDCheckDataTemplateGetCheckDataTemplate"},
	{FPDCheckDataTemplateSEL, FPDCheckDataTemplateGetCheckDataTemplate2SEL, L"FPDCheckDataTemplateGetCheckDataTemplate2"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerCreateWinDefaultHandlerSEL, L"FPDWinDefaultHandlerCreateWinDefaultHandler"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerDeleteWinDefaultHandlerSEL, L"FPDWinDefaultHandlerDeleteWinDefaultHandler"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerGetCertificateInfoSEL, L"FPDWinDefaultHandlerGetCertificateInfo"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerStartCalcDigestSEL, L"FPDWinDefaultHandlerStartCalcDigest"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerContinueCalcDigestSEL, L"FPDWinDefaultHandlerContinueCalcDigest"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerStartSignSEL, L"FPDWinDefaultHandlerStartSign"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerIsNeedPadDataSEL, L"FPDWinDefaultHandlerIsNeedPadData"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerSetCertVerifyCallBackSEL, L"FPDWinDefaultHandlerSetCertVerifyCallBack"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerSetReovactionProgressCallBackSEL, L"FPDWinDefaultHandlerSetReovactionProgressCallBack"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerSetCRLDownloadHandlerSEL, L"FPDWinDefaultHandlerSetCRLDownloadHandler"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerVerifySEL, L"FPDWinDefaultHandlerVerify"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerSetSigmedVDictObjNumSEL, L"FPDWinDefaultHandlerSetSigmedVDictObjNum"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerGetSignVDictObjNumSEL, L"FPDWinDefaultHandlerGetSignVDictObjNum"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerIsSignCancelSEL, L"FPDWinDefaultHandlerIsSignCancel"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerSetDocumentSEL, L"FPDWinDefaultHandlerSetDocument"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerGetSignedHashDataSEL, L"FPDWinDefaultHandlerGetSignedHashData"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerVerifyDigestSEL, L"FPDWinDefaultHandlerVerifyDigest"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerGetSignedTimeSEL, L"FPDWinDefaultHandlerGetSignedTime"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerGetTimeStampErrorSEL, L"FPDWinDefaultHandlerGetTimeStampError"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerGetReocationTypeSEL, L"FPDWinDefaultHandlerGetReocationType"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerIsLTVSEL, L"FPDWinDefaultHandlerIsLTV"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerGetCadesLevelSEL, L"FPDWinDefaultHandlerGetCadesLevel"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerSetPDFSigForPoliciesDataSEL, L"FPDWinDefaultHandlerSetPDFSigForPoliciesData"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerGetSignatureHandlerSEL, L"FPDWinDefaultHandlerGetSignatureHandler"},
	{FPDWinDefaultHandlerSEL, FPDWinDefaultHandlerContinueSignSEL, L"FPDWinDefaultHandlerContinueSign"},
	{FPDCertPolicesDataSEL, FPDCertPolicesDataNewSEL, L"FPDCertPolicesDataNew"},
	{FPDCertPolicesDataSEL, FPDCertPolicesDataDestroySEL, L"FPDCertPolicesDataDestroy"},
	{FPDCertPolicesDataSEL, FPDCertPolicesDataAddItemSEL, L"FPDCertPolicesDataAddItem"},
	{FPDCertPolicesDataSEL, FPDCertPolicesDataGetKeysSEL, L"FPDCertPolicesDataGetKeys"},
	{FPDCertPolicesDataSEL, FPDCertPolicesDataGetPoliciesDataByKeySEL, L"FPDCertPolicesDataGetPoliciesDataByKey"},
	{FPDSignatureHandlerSEL, FPDSignatureHandlerNewSEL, L"FPDSignatureHandlerNew"},
	{FPDSignatureHandlerSEL, FPDSignatureHandlerDestroySEL, L"FPDSignatureHandlerDestroy"},
	{FPDSignatureHandlerSEL, FPDSignatureHandlerGetWinDefaultHandlerSEL, L"FPDSignatureHandlerGetWinDefaultHandler"},
	{FPDSignatureHandlerMgrSEL, FPDSignatureHandlerMgrCreateSignatureHandlerMgrSEL, L"FPDSignatureHandlerMgrCreateSignatureHandlerMgr"},
	{FPDSignatureHandlerMgrSEL, FPDSignatureHandlerMgrGetSignatureHandlerMgrSEL, L"FPDSignatureHandlerMgrGetSignatureHandlerMgr"},
	{FPDSignatureHandlerMgrSEL, FPDSignatureHandlerMgrDestroySEL, L"FPDSignatureHandlerMgrDestroy"},
	{FPDSignatureHandlerMgrSEL, FPDSignatureHandlerMgrRegisterSignatureHandlerSEL, L"FPDSignatureHandlerMgrRegisterSignatureHandler"},
	{FPDSignatureHandlerMgrSEL, FPDSignatureHandlerMgrRegisterDefaultSignatureHandlerSEL, L"FPDSignatureHandlerMgrRegisterDefaultSignatureHandler"},
	{FPDSignatureHandlerMgrSEL, FPDSignatureHandlerMgrUnRegisterSignatureHandlerSEL, L"FPDSignatureHandlerMgrUnRegisterSignatureHandler"},
	{FPDSignatureHandlerMgrSEL, FPDSignatureHandlerMgrGetSignatureHandlerSEL, L"FPDSignatureHandlerMgrGetSignatureHandler"},
	{FPDResponseSEL, FPDResponseCreateResonseSEL, L"FPDResponseCreateResonse"},
	{FPDResponseSEL, FPDResponseDeleteResonseSEL, L"FPDResponseDeleteResonse"},
	{FPDResponseSEL, FPDResponseGetResponseTypeSEL, L"FPDResponseGetResponseType"},
	{FPDResponseSEL, FPDResponseFPD_ResponseDataSEL, L"FPDResponseFPD_ResponseData"},
	{FPDRevocationHandlerSEL, FPDRevocationHandlerNewSEL, L"FPDRevocationHandlerNew"},
	{FPDRevocationHandlerSEL, FPDRevocationHandlerDestroySEL, L"FPDRevocationHandlerDestroy"},
	{FPDDownloadHandlerSEL, FPDDownloadHandlerCreateDefaultRevocationHandlerSEL, L"FPDDownloadHandlerCreateDefaultRevocationHandler"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATANewSEL, L"FPDSGCLIENTDATANew"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATADeleteSEL, L"FPDSGCLIENTDATADelete"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetCreateStoreSEL, L"FPDSGCLIENTDATASetCreateStore"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetCreateStoreSEL, L"FPDSGCLIENTDATAGetCreateStore"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetVerifyStoreSEL, L"FPDSGCLIENTDATASetVerifyStore"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetVerifyStoreSEL, L"FPDSGCLIENTDATAGetVerifyStore"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAAddVerifyCertListSEL, L"FPDSGCLIENTDATAAddVerifyCertList"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetVerifyCertListCountSEL, L"FPDSGCLIENTDATAGetVerifyCertListCount"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetVerifyCertListByIndexSEL, L"FPDSGCLIENTDATAGetVerifyCertListByIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetChainListIndexSEL, L"FPDSGCLIENTDATASetChainListIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetChainListIndexSEL, L"FPDSGCLIENTDATAGetChainListIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASettsverifyStoreSEL, L"FPDSGCLIENTDATASettsverifyStore"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGettsverifyStoreSEL, L"FPDSGCLIENTDATAGettsverifyStore"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAAddVerifyTimeStampCertListSEL, L"FPDSGCLIENTDATAAddVerifyTimeStampCertList"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetVerifyTimeStampCertListCountSEL, L"FPDSGCLIENTDATAGetVerifyTimeStampCertListCount"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetVerifytsTimeStampCertListByIndexSEL, L"FPDSGCLIENTDATAGetVerifytsTimeStampCertListByIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetCurTimeStampChainListIndexSEL, L"FPDSGCLIENTDATASetCurTimeStampChainListIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetCurTimeStampChainListIndexSEL, L"FPDSGCLIENTDATAGetCurTimeStampChainListIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetTrustStoreSEL, L"FPDSGCLIENTDATASetTrustStore"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetTrustStoreSEL, L"FPDSGCLIENTDATAGetTrustStore"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetHashAlgSEL, L"FPDSGCLIENTDATASetHashAlg"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetHashAlgSEL, L"FPDSGCLIENTDATAGetHashAlg"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetSignAlgSEL, L"FPDSGCLIENTDATASetSignAlg"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetSignAlgSEL, L"FPDSGCLIENTDATAGetSignAlg"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetRevocTimeoutURLsSEL, L"FPDSGCLIENTDATASetRevocTimeoutURLs"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetRevocTimeoutURLsSEL, L"FPDSGCLIENTDATAGetRevocTimeoutURLs"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetCRLPathSEL, L"FPDSGCLIENTDATASetCRLPath"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetCRLPathSEL, L"FPDSGCLIENTDATAGetCRLPath"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetFileStorePathSEL, L"FPDSGCLIENTDATASetFileStorePath"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetFileStorePathSEL, L"FPDSGCLIENTDATAGetFileStorePath"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetCertFilePathSEL, L"FPDSGCLIENTDATASetCertFilePath"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetCertFilePathSEL, L"FPDSGCLIENTDATAGetCertFilePath"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetCertFilePassSEL, L"FPDSGCLIENTDATASetCertFilePass"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetCertFilePassSEL, L"FPDSGCLIENTDATAGetCertFilePass"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetVERIFYDATASEL, L"FPDSGCLIENTDATASetVERIFYDATA"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetVERIFYDATASEL, L"FPDSGCLIENTDATAGetVERIFYDATA"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAAddToRevocVerifySEL, L"FPDSGCLIENTDATAAddToRevocVerify"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetRevocVerifyKeyIndexSEL, L"FPDSGCLIENTDATAGetRevocVerifyKeyIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetRevocVerifyCountByKeyIndexSEL, L"FPDSGCLIENTDATAGetRevocVerifyCountByKeyIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetRevocVerifyByIndexSEL, L"FPDSGCLIENTDATAGetRevocVerifyByIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAAddToTimeStampRevocVerifySEL, L"FPDSGCLIENTDATAAddToTimeStampRevocVerify"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetTimeStampRevocVerifyKeyIndexSEL, L"FPDSGCLIENTDATAGetTimeStampRevocVerifyKeyIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetTimeStampRevocVerifyCountByKeyIndexSEL, L"FPDSGCLIENTDATAGetTimeStampRevocVerifyCountByKeyIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetTimeStampRevocRevocVerifyByIndexSEL, L"FPDSGCLIENTDATAGetTimeStampRevocRevocVerifyByIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetVerifytsTimeStampCertListByIndexAndArryIndexSEL, L"FPDSGCLIENTDATAGetVerifytsTimeStampCertListByIndexAndArryIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetVerifyCertListByIndexAndArryIndexSEL, L"FPDSGCLIENTDATAGetVerifyCertListByIndexAndArryIndex"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATASetIsEnableSealSEL, L"FPDSGCLIENTDATASetIsEnableSeal"},
	{FPDSGCLIENTDATASEL, FPDSGCLIENTDATAGetSealInfoSEL, L"FPDSGCLIENTDATAGetSealInfo"},
	{FPDMODIFYDATASEL, FPDMODIFYDATACreateSEL, L"FPDMODIFYDATACreate"},
	{FPDMODIFYDATASEL, FPDMODIFYDATADestroySEL, L"FPDMODIFYDATADestroy"},
	{FPDMODIFYDATASEL, FPDMODIFYDATASetRectSEL, L"FPDMODIFYDATASetRect"},
	{FPDMODIFYDATASEL, FPDMODIFYDATAGetRectSEL, L"FPDMODIFYDATAGetRect"},
	{FPDMODIFYDATASEL, FPDMODIFYDATASetObjectNumSEL, L"FPDMODIFYDATASetObjectNum"},
	{FPDMODIFYDATASEL, FPDMODIFYDATAGetObjectNumSEL, L"FPDMODIFYDATAGetObjectNum"},
	{FPDMODIFYDATASEL, FPDMODIFYDATASetPageIndexSEL, L"FPDMODIFYDATASetPageIndex"},
	{FPDMODIFYDATASEL, FPDMODIFYDATAGetPageIndexSEL, L"FPDMODIFYDATAGetPageIndex"},
	{FPDMODIFYDATASEL, FPDMODIFYDATASetTypeSEL, L"FPDMODIFYDATASetType"},
	{FPDMODIFYDATASEL, FPDMODIFYDATAGetTypeSEL, L"FPDMODIFYDATAGetType"},
	{FPDMODIFYDATASEL, FPDMODIFYDATASetTNameSEL, L"FPDMODIFYDATASetTName"},
	{FPDMODIFYDATASEL, FPDMODIFYDATAGetTNameSEL, L"FPDMODIFYDATAGetTName"},
	{FPDMODIFYDATASEL, FPDMODIFYDATASetNMSEL, L"FPDMODIFYDATASetNM"},
	{FPDMODIFYDATASEL, FPDMODIFYDATAGetNMSEL, L"FPDMODIFYDATAGetNM"},
	{FPDMODIFYDATASEL, FPDMODIFYDATASetbNomodifySEL, L"FPDMODIFYDATASetbNomodify"},
	{FPDMODIFYDATASEL, FPDMODIFYDATAGetbNomodifySEL, L"FPDMODIFYDATAGetbNomodify"},
	{FPDXFADocViewSEL, FPDXFADocViewGetDocSEL, L"FPDXFADocViewGetDoc"},
	{FPDXFADocViewSEL, FPDXFADocViewStartLayoutSEL, L"FPDXFADocViewStartLayout"},
	{FPDXFADocViewSEL, FPDXFADocViewDoLayoutSEL, L"FPDXFADocViewDoLayout"},
	{FPDXFADocViewSEL, FPDXFADocViewStopLayoutSEL, L"FPDXFADocViewStopLayout"},
	{FPDXFADocViewSEL, FPDXFADocViewGetLayoutStatusSEL, L"FPDXFADocViewGetLayoutStatus"},
	{FPDXFADocViewSEL, FPDXFADocViewUpdateDocViewSEL, L"FPDXFADocViewUpdateDocView"},
	{FPDXFADocViewSEL, FPDXFADocViewCountPageViewsSEL, L"FPDXFADocViewCountPageViews"},
	{FPDXFADocViewSEL, FPDXFADocViewGetPageViewSEL, L"FPDXFADocViewGetPageView"},
	{FPDXFADocViewSEL, FPDXFADocViewGetWidgetByNameSEL, L"FPDXFADocViewGetWidgetByName"},
	{FPDXFADocViewSEL, FPDXFADocViewGetWidgetAccByNameSEL, L"FPDXFADocViewGetWidgetAccByName"},
	{FPDXFADocViewSEL, FPDXFADocViewResetWidgetDataSEL, L"FPDXFADocViewResetWidgetData"},
	{FPDXFADocViewSEL, FPDXFADocViewProcessWidgetEventSEL, L"FPDXFADocViewProcessWidgetEvent"},
	{FPDXFADocViewSEL, FPDXFADocViewGetWidgetHandlerSEL, L"FPDXFADocViewGetWidgetHandler"},
	{FPDXFADocViewSEL, FPDXFADocViewCreateWidgetIteratorSEL, L"FPDXFADocViewCreateWidgetIterator"},
	{FPDXFADocViewSEL, FPDXFADocViewCreateWidgetAccIteratorSEL, L"FPDXFADocViewCreateWidgetAccIterator"},
	{FPDXFADocViewSEL, FPDXFADocViewGetFocusWidgetSEL, L"FPDXFADocViewGetFocusWidget"},
	{FPDXFADocViewSEL, FPDXFADocViewKillFocusSEL, L"FPDXFADocViewKillFocus"},
	{FPDXFADocViewSEL, FPDXFADocViewSetFocusSEL, L"FPDXFADocViewSetFocus"},
	{FPDXFADocViewSEL, FPDXFADocViewIsTableFormFirstPageSEL, L"FPDXFADocViewIsTableFormFirstPage"},
	{FPDXFADocViewSEL, FPDXFADocViewGetChangedFieldFullNamesSEL, L"FPDXFADocViewGetChangedFieldFullNames"},
	{FPDIXFAPageViewSEL, FPDIXFAPageViewGetDocViewSEL, L"FPDIXFAPageViewGetDocView"},
	{FPDIXFAPageViewSEL, FPDIXFAPageViewGetPageViewIndexSEL, L"FPDIXFAPageViewGetPageViewIndex"},
	{FPDIXFAPageViewSEL, FPDIXFAPageViewGetPageViewRectSEL, L"FPDIXFAPageViewGetPageViewRect"},
	{FPDIXFAPageViewSEL, FPDIXFAPageViewGetDisplayMatrixSEL, L"FPDIXFAPageViewGetDisplayMatrix"},
	{FPDIXFAPageViewSEL, FPDIXFAPageViewLoadPageViewSEL, L"FPDIXFAPageViewLoadPageView"},
	{FPDIXFAPageViewSEL, FPDIXFAPageViewUnloadPageViewSEL, L"FPDIXFAPageViewUnloadPageView"},
	{FPDIXFAPageViewSEL, FPDIXFAPageViewGetWidgetByPosSEL, L"FPDIXFAPageViewGetWidgetByPos"},
	{FPDIXFAPageViewSEL, FPDIXFAPageViewCreateWidgetIteratorSEL, L"FPDIXFAPageViewCreateWidgetIterator"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccGetNameSEL, L"FPDCXFAWidgetAccGetName"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccProcessValueChangedSEL, L"FPDCXFAWidgetAccProcessValueChanged"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccResetDataSEL, L"FPDCXFAWidgetAccResetData"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccSetImageEditSEL, L"FPDCXFAWidgetAccSetImageEdit"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccGetExclGroupSEL, L"FPDCXFAWidgetAccGetExclGroup"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccProcessEventSEL, L"FPDCXFAWidgetAccProcessEvent"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccGetManifestActionSEL, L"FPDCXFAWidgetAccGetManifestAction"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccGetManifestCountReivesSEL, L"FPDCXFAWidgetAccGetManifestCountReives"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccGetManifestRefContentSEL, L"FPDCXFAWidgetAccGetManifestRefContent"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccGetUITypeSEL, L"FPDCXFAWidgetAccGetUIType"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccGetAccessSEL, L"FPDCXFAWidgetAccGetAccess"},
	{FPDCXFAWidgetAccSEL, FPDCXFAWidgetAccSetAccessSEL, L"FPDCXFAWidgetAccSetAccess"},
	{FPDIXFAWidgetHandlerSEL, FPDIXFAWidgetHandlerGetNameSEL, L"FPDIXFAWidgetHandlerGetName"},
	{FPDIXFAWidgetHandlerSEL, FPDIXFAWidgetHandlerGetDataAccSEL, L"FPDIXFAWidgetHandlerGetDataAcc"},
	{FPDIXFAWidgetHandlerSEL, FPDIXFAWidgetHandlerGetBBoxSEL, L"FPDIXFAWidgetHandlerGetBBox"},
	{FPDIXFAWidgetHandlerSEL, FPDIXFAWidgetHandlerHasEventSEL, L"FPDIXFAWidgetHandlerHasEvent"},
	{FPDIXFAWidgetHandlerSEL, FPDIXFAWidgetHandlerProcessEventSEL, L"FPDIXFAWidgetHandlerProcessEvent"},
	{FPDIXFAWidgetHandlerSEL, FPDIXFAWidgetHandlerGetStatusSEL, L"FPDIXFAWidgetHandlerGetStatus"},
	{FPDIXFAWidgetHandlerSEL, FPDIXFAWidgetHandlerGetPageViewSEL, L"FPDIXFAWidgetHandlerGetPageView"},
	{FPDIXFAWidgetHandlerSEL, FPDIXFAWidgetHandlerRenderWidgetSEL, L"FPDIXFAWidgetHandlerRenderWidget"},
	{FPDIXFAWidgetIteratorSEL, FPDIXFAWidgetIteratorReleaseSEL, L"FPDIXFAWidgetIteratorRelease"},
	{FPDIXFAWidgetIteratorSEL, FPDIXFAWidgetIteratorResetSEL, L"FPDIXFAWidgetIteratorReset"},
	{FPDIXFAWidgetIteratorSEL, FPDIXFAWidgetIteratorMoveToFirstSEL, L"FPDIXFAWidgetIteratorMoveToFirst"},
	{FPDIXFAWidgetIteratorSEL, FPDIXFAWidgetIteratorMoveToLastSEL, L"FPDIXFAWidgetIteratorMoveToLast"},
	{FPDIXFAWidgetIteratorSEL, FPDIXFAWidgetIteratorMoveToNextSEL, L"FPDIXFAWidgetIteratorMoveToNext"},
	{FPDIXFAWidgetIteratorSEL, FPDIXFAWidgetIteratorMoveToPreviousSEL, L"FPDIXFAWidgetIteratorMoveToPrevious"},
	{FPDIXFAWidgetIteratorSEL, FPDIXFAWidgetIteratorGetCurrentWidgetSEL, L"FPDIXFAWidgetIteratorGetCurrentWidget"},
	{FPDIXFAWidgetIteratorSEL, FPDIXFAWidgetIteratorSetCurrentWidgetSEL, L"FPDIXFAWidgetIteratorSetCurrentWidget"},
	{FPDIXFAWidgetAccIteratorSEL, FPDIXFAWidgetAccIteratorReleaseSEL, L"FPDIXFAWidgetAccIteratorRelease"},
	{FPDIXFAWidgetAccIteratorSEL, FPDIXFAWidgetAccIteratorResetSEL, L"FPDIXFAWidgetAccIteratorReset"},
	{FPDIXFAWidgetAccIteratorSEL, FPDIXFAWidgetAccIteratorMoveToFirstSEL, L"FPDIXFAWidgetAccIteratorMoveToFirst"},
	{FPDIXFAWidgetAccIteratorSEL, FPDIXFAWidgetAccIteratorMoveToLastSEL, L"FPDIXFAWidgetAccIteratorMoveToLast"},
	{FPDIXFAWidgetAccIteratorSEL, FPDIXFAWidgetAccIteratorMoveToNextSEL, L"FPDIXFAWidgetAccIteratorMoveToNext"},
	{FPDIXFAWidgetAccIteratorSEL, FPDIXFAWidgetAccIteratorMoveToPreviousSEL, L"FPDIXFAWidgetAccIteratorMoveToPrevious"},
	{FPDIXFAWidgetAccIteratorSEL, FPDIXFAWidgetAccIteratorGetCurrentWidgetAccSEL, L"FPDIXFAWidgetAccIteratorGetCurrentWidgetAcc"},
	{FPDIXFAWidgetAccIteratorSEL, FPDIXFAWidgetAccIteratorSetCurrentWidgetAccSEL, L"FPDIXFAWidgetAccIteratorSetCurrentWidgetAcc"},
	{FPDIXFAWidgetAccIteratorSEL, FPDIXFAWidgetAccIteratorSkipTreeSEL, L"FPDIXFAWidgetAccIteratorSkipTree"},
	{FPDCXFAEventParamSEL, FPDCXFAEventParamCreateEventParamSEL, L"FPDCXFAEventParamCreateEventParam"},
	{FPDCXFAEventParamSEL, FPDCXFAEventParamSetEventTypeSEL, L"FPDCXFAEventParamSetEventType"},
	{FPDCXFAEventParamSEL, FPDCXFAEventParamDeleteEventParamSEL, L"FPDCXFAEventParamDeleteEventParam"},
	{FPDCXFAEventParamSEL, FPDCXFAEventParamSetIsCancelActionSEL, L"FPDCXFAEventParamSetIsCancelAction"},
	{FPDCXFAEventParamSEL, FPDCXFAEventParamGetIsCancelActionSEL, L"FPDCXFAEventParamGetIsCancelAction"},
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
	{FPDStandardCryptoHandlerSEL, FPDStandardCryptoHandlerNewSEL, L"FPDStandardCryptoHandlerNew"},
	{FPDStandardCryptoHandlerSEL, FPDStandardCryptoHandlerDestroySEL, L"FPDStandardCryptoHandlerDestroy"},
	{FPDStandardCryptoHandlerSEL, FPDStandardCryptoHandlerInitSEL, L"FPDStandardCryptoHandlerInit"},
	{FPDStandardCryptoHandlerSEL, FPDStandardCryptoHandlerInitByDicSEL, L"FPDStandardCryptoHandlerInitByDic"},
	{FPDStandardCryptoHandlerSEL, FPDStandardCryptoHandlerDecryptGetSizeSEL, L"FPDStandardCryptoHandlerDecryptGetSize"},
	{FPDStandardCryptoHandlerSEL, FPDStandardCryptoHandlerDecryptStartSEL, L"FPDStandardCryptoHandlerDecryptStart"},
	{FPDStandardCryptoHandlerSEL, FPDStandardCryptoHandlerDecryptStreamSEL, L"FPDStandardCryptoHandlerDecryptStream"},
	{FPDStandardCryptoHandlerSEL, FPDStandardCryptoHandlerDecryptFinishSEL, L"FPDStandardCryptoHandlerDecryptFinish"},
	{FPDStandardCryptoHandlerSEL, FPDStandardCryptoHandlerEncryptGetSizeSEL, L"FPDStandardCryptoHandlerEncryptGetSize"},
	{FPDStandardCryptoHandlerSEL, FPDStandardCryptoHandlerEncryptContentSEL, L"FPDStandardCryptoHandlerEncryptContent"},
	{FPDStandardCryptoHandlerSEL, FPDStandardCryptoHandlerCloneSEL, L"FPDStandardCryptoHandlerClone"},
	{FPDFipsStandardCryptoHandlerSEL, FPDFipsStandardCryptoHandlerNewSEL, L"FPDFipsStandardCryptoHandlerNew"},
	{FPDFipsStandardCryptoHandlerSEL, FPDFipsStandardCryptoHandlerDestroySEL, L"FPDFipsStandardCryptoHandlerDestroy"},
	{FPDFipsStandardCryptoHandlerSEL, FPDFipsStandardCryptoHandlerInitSEL, L"FPDFipsStandardCryptoHandlerInit"},
	{FPDFipsStandardCryptoHandlerSEL, FPDFipsStandardCryptoHandlerInit2SEL, L"FPDFipsStandardCryptoHandlerInit2"},
	{FPDSimpleParserSEL, FPDSimpleParserNewSEL, L"FPDSimpleParserNew"},
	{FPDSimpleParserSEL, FPDSimpleParserNew2SEL, L"FPDSimpleParserNew2"},
	{FPDSimpleParserSEL, FPDSimpleParserDestroySEL, L"FPDSimpleParserDestroy"},
	{FPDSimpleParserSEL, FPDSimpleParserGetWordSEL, L"FPDSimpleParserGetWord"},
	{FPDSimpleParserSEL, FPDSimpleParserSearchTokenSEL, L"FPDSimpleParserSearchToken"},
	{FPDSimpleParserSEL, FPDSimpleParserSkipWordSEL, L"FPDSimpleParserSkipWord"},
	{FPDSimpleParserSEL, FPDSimpleParserFindTagPairSEL, L"FPDSimpleParserFindTagPair"},
	{FPDSimpleParserSEL, FPDSimpleParserFindTagParamSEL, L"FPDSimpleParserFindTagParam"},
	{FPDSimpleParserSEL, FPDSimpleParserGetPosSEL, L"FPDSimpleParserGetPos"},
	{FPDSimpleParserSEL, FPDSimpleParserSetPosSEL, L"FPDSimpleParserSetPos"},
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
	{FPDWinBitmapDeviceSEL, FPDWinBitmapDeviceNewSEL, L"FPDWinBitmapDeviceNew"},
	{FPDWinBitmapDeviceSEL, FPDWinBitmapDeviceDestroySEL, L"FPDWinBitmapDeviceDestroy"},
	{FPDWinBitmapDeviceSEL, FPDWinBitmapDeviceGetDCSEL, L"FPDWinBitmapDeviceGetDC"},
	{FPDWinBitmapDeviceSEL, FPDWinBitmapDeviceCastToRenderDeviceSEL, L"FPDWinBitmapDeviceCastToRenderDevice"},
	{FPDCPWLImageSEL, FPDCPWLImageNewSEL, L"FPDCPWLImageNew"},
	{FPDCPWLImageSEL, FPDCPWLImageDeleteSEL, L"FPDCPWLImageDelete"},
	{FPDCPWLImageSEL, FPDCPWLImageGetImageAppStreamSEL, L"FPDCPWLImageGetImageAppStream"},
	{FPDCPWLImageSEL, FPDCPWLImageGetScaleSEL, L"FPDCPWLImageGetScale"},
	{FPDCPWLImageSEL, FPDCPWLImageGetImageOffsetSEL, L"FPDCPWLImageGetImageOffset"},
	{FPDCPWLImageSEL, FPDCPWLImageGetPDFStreamSEL, L"FPDCPWLImageGetPDFStream"},
	{FPDCPWLImageSEL, FPDCPWLImageSetPDFStreamSEL, L"FPDCPWLImageSetPDFStream"},
	{FPDCPWLImageSEL, FPDCPWLImageGetImageSizeSEL, L"FPDCPWLImageGetImageSize"},
	{FPDCPWLImageSEL, FPDCPWLImageGetImageMatrixSEL, L"FPDCPWLImageGetImageMatrix"},
	{FPDCPWLImageSEL, FPDCPWLImageGetImageAliasSEL, L"FPDCPWLImageGetImageAlias"},
	{FPDCPWLImageSEL, FPDCPWLImageSetImageAliasSEL, L"FPDCPWLImageSetImageAlias"},
	{FPDCPWLImageSEL, FPDCPWLImageGetCPWLWndSEL, L"FPDCPWLImageGetCPWLWnd"},
	{FPDCPWLImageSEL, FPDCPWLImageDrawThisAppearanceSEL, L"FPDCPWLImageDrawThisAppearance"},
	{FPDCPWLImageSEL, FPDCPWLImageDrawChildAppearanceSEL, L"FPDCPWLImageDrawChildAppearance"},
	{FPDCPWLImageSEL, FPDCPWLImageNew2SEL, L"FPDCPWLImageNew2"},
	{FPDCPWLLabelSEL, FPDCPWLLabelNewSEL, L"FPDCPWLLabelNew"},
	{FPDCPWLLabelSEL, FPDCPWLLabelDeleteSEL, L"FPDCPWLLabelDelete"},
	{FPDCPWLLabelSEL, FPDCPWLLabelGetClassNamePWLSEL, L"FPDCPWLLabelGetClassNamePWL"},
	{FPDCPWLLabelSEL, FPDCPWLLabelSetFontSizeSEL, L"FPDCPWLLabelSetFontSize"},
	{FPDCPWLLabelSEL, FPDCPWLLabelGetFontSizeSEL, L"FPDCPWLLabelGetFontSize"},
	{FPDCPWLLabelSEL, FPDCPWLLabelSetDirectionRTLSEL, L"FPDCPWLLabelSetDirectionRTL"},
	{FPDCPWLLabelSEL, FPDCPWLLabelSetTextSEL, L"FPDCPWLLabelSetText"},
	{FPDCPWLLabelSEL, FPDCPWLLabelGetTextSEL, L"FPDCPWLLabelGetText"},
	{FPDCPWLLabelSEL, FPDCPWLLabelSetLimitCharSEL, L"FPDCPWLLabelSetLimitChar"},
	{FPDCPWLLabelSEL, FPDCPWLLabelSetHorzScaleSEL, L"FPDCPWLLabelSetHorzScale"},
	{FPDCPWLLabelSEL, FPDCPWLLabelSetCharSpaceSEL, L"FPDCPWLLabelSetCharSpace"},
	{FPDCPWLLabelSEL, FPDCPWLLabelGetContentRectSEL, L"FPDCPWLLabelGetContentRect"},
	{FPDCPWLLabelSEL, FPDCPWLLabelGetTotalWordsSEL, L"FPDCPWLLabelGetTotalWords"},
	{FPDCPWLLabelSEL, FPDCPWLLabelGetTextAppearanceStreamSEL, L"FPDCPWLLabelGetTextAppearanceStream"},
	{FPDCPWLLabelSEL, FPDCPWLLabelDrawPrintAppearanceSEL, L"FPDCPWLLabelDrawPrintAppearance"},
	{FPDCPWLLabelSEL, FPDCPWLLabelGetEditSEL, L"FPDCPWLLabelGetEdit"},
	{FPDCPWLLabelSEL, FPDCPWLLabelGetCPWLWndSEL, L"FPDCPWLLabelGetCPWLWnd"},
	{FPDCPWLLabelSEL, FPDCPWLLabelOnCreatedSEL, L"FPDCPWLLabelOnCreated"},
	{FPDCPWLLabelSEL, FPDCPWLLabelDrawThisAppearanceSEL, L"FPDCPWLLabelDrawThisAppearance"},
	{FPDCPWLLabelSEL, FPDCPWLLabelGetThisAppearanceStreamSEL, L"FPDCPWLLabelGetThisAppearanceStream"},
	{FPDCPWLLabelSEL, FPDCPWLLabelRePosChildWndSEL, L"FPDCPWLLabelRePosChildWnd"},
	{FPDCPWLLabelSEL, FPDCPWLLabelSetParamByFlagSEL, L"FPDCPWLLabelSetParamByFlag"},
	{FPDCPWLLabelSEL, FPDCPWLLabelNew2SEL, L"FPDCPWLLabelNew2"},
	{FPDCPWLLabelSEL, FPDCPWLLabelSetRichTextByXMLSEL, L"FPDCPWLLabelSetRichTextByXML"},
	{FPDCPWLTimerHandlerSEL, FPDCPWLTimerHandlerNewSEL, L"FPDCPWLTimerHandlerNew"},
	{FPDCPWLTimerHandlerSEL, FPDCPWLTimerHandlerDestroySEL, L"FPDCPWLTimerHandlerDestroy"},
	{FPDCPWLTimerHandlerSEL, FPDCPWLTimerHandlerBeginTimerSEL, L"FPDCPWLTimerHandlerBeginTimer"},
	{FPDCPWLTimerHandlerSEL, FPDCPWLTimerHandlerEndTimerSEL, L"FPDCPWLTimerHandlerEndTimer"},
	{FPDCPWLFocusHandlerSEL, FPDCPWLFocusHandlerNewSEL, L"FPDCPWLFocusHandlerNew"},
	{FPDCPWLFocusHandlerSEL, FPDCPWLFocusHandlerDestroySEL, L"FPDCPWLFocusHandlerDestroy"},
	{FPDCPWLProviderHandlerSEL, FPDCPWLProviderHandlerNewSEL, L"FPDCPWLProviderHandlerNew"},
	{FPDCPWLProviderHandlerSEL, FPDCPWLProviderHandlerDestroySEL, L"FPDCPWLProviderHandlerDestroy"},
	{FPDCPWLWndSEL, FPDCPWLWndNewSEL, L"FPDCPWLWndNew"},
	{FPDCPWLWndSEL, FPDCPWLWndDestroySEL, L"FPDCPWLWndDestroy"},
	{FPDCPWLWndSEL, FPDCPWLWndCreateChildItemPWLLabelSEL, L"FPDCPWLWndCreateChildItemPWLLabel"},
	{FPDCPWLWndSEL, FPDCPWLWndCreateSEL, L"FPDCPWLWndCreate"},
	{FPDCPWLWndSEL, FPDCPWLWndGetClassNamePWLSEL, L"FPDCPWLWndGetClassNamePWL"},
	{FPDCPWLWndSEL, FPDCPWLWndMoveSEL, L"FPDCPWLWndMove"},
	{FPDCPWLWndSEL, FPDCPWLWndInvalidateRectSEL, L"FPDCPWLWndInvalidateRect"},
	{FPDCPWLWndSEL, FPDCPWLWndGetAppearanceStreamSEL, L"FPDCPWLWndGetAppearanceStream"},
	{FPDCPWLWndSEL, FPDCPWLWndDrawAppearanceSEL, L"FPDCPWLWndDrawAppearance"},
	{FPDCPWLWndSEL, FPDCPWLWndOnKeyDownSEL, L"FPDCPWLWndOnKeyDown"},
	{FPDCPWLWndSEL, FPDCPWLWndOnKeyUpSEL, L"FPDCPWLWndOnKeyUp"},
	{FPDCPWLWndSEL, FPDCPWLWndOnCharSEL, L"FPDCPWLWndOnChar"},
	{FPDCPWLWndSEL, FPDCPWLWndOnLButtonDblClkSEL, L"FPDCPWLWndOnLButtonDblClk"},
	{FPDCPWLWndSEL, FPDCPWLWndOnLButtonDownSEL, L"FPDCPWLWndOnLButtonDown"},
	{FPDCPWLWndSEL, FPDCPWLWndOnLButtonUpSEL, L"FPDCPWLWndOnLButtonUp"},
	{FPDCPWLWndSEL, FPDCPWLWndOnMButtonDblClkSEL, L"FPDCPWLWndOnMButtonDblClk"},
	{FPDCPWLWndSEL, FPDCPWLWndOnMButtonDownSEL, L"FPDCPWLWndOnMButtonDown"},
	{FPDCPWLWndSEL, FPDCPWLWndOnMButtonUpSEL, L"FPDCPWLWndOnMButtonUp"},
	{FPDCPWLWndSEL, FPDCPWLWndOnRButtonDblClkSEL, L"FPDCPWLWndOnRButtonDblClk"},
	{FPDCPWLWndSEL, FPDCPWLWndOnRButtonDownSEL, L"FPDCPWLWndOnRButtonDown"},
	{FPDCPWLWndSEL, FPDCPWLWndOnRButtonUpSEL, L"FPDCPWLWndOnRButtonUp"},
	{FPDCPWLWndSEL, FPDCPWLWndOnMouseMoveSEL, L"FPDCPWLWndOnMouseMove"},
	{FPDCPWLWndSEL, FPDCPWLWndOnMouseWheelSEL, L"FPDCPWLWndOnMouseWheel"},
	{FPDCPWLWndSEL, FPDCPWLWndSetShowTextColorSEL, L"FPDCPWLWndSetShowTextColor"},
	{FPDCPWLWndSEL, FPDCPWLWndSetShowBackColorSEL, L"FPDCPWLWndSetShowBackColor"},
	{FPDCPWLWndSEL, FPDCPWLWndSetFocusSEL, L"FPDCPWLWndSetFocus"},
	{FPDCPWLWndSEL, FPDCPWLWndKillFocusSEL, L"FPDCPWLWndKillFocus"},
	{FPDCPWLWndSEL, FPDCPWLWndSetCaptureSEL, L"FPDCPWLWndSetCapture"},
	{FPDCPWLWndSEL, FPDCPWLWndReleaseCaptureSEL, L"FPDCPWLWndReleaseCapture"},
	{FPDCPWLWndSEL, FPDCPWLWndOnNotifySEL, L"FPDCPWLWndOnNotify"},
	{FPDCPWLWndSEL, FPDCPWLWndSetTextColorSEL, L"FPDCPWLWndSetTextColor"},
	{FPDCPWLWndSEL, FPDCPWLWndSetTextStrokeColorSEL, L"FPDCPWLWndSetTextStrokeColor"},
	{FPDCPWLWndSEL, FPDCPWLWndSetVisibleSEL, L"FPDCPWLWndSetVisible"},
	{FPDCPWLWndSEL, FPDCPWLWndGetFocusRectSEL, L"FPDCPWLWndGetFocusRect"},
	{FPDCPWLWndSEL, FPDCPWLWndGetBackgroundColorSEL, L"FPDCPWLWndGetBackgroundColor"},
	{FPDCPWLWndSEL, FPDCPWLWndGetBorderColorSEL, L"FPDCPWLWndGetBorderColor"},
	{FPDCPWLWndSEL, FPDCPWLWndGetTextColorSEL, L"FPDCPWLWndGetTextColor"},
	{FPDCPWLWndSEL, FPDCPWLWndGetTextStrokeColorSEL, L"FPDCPWLWndGetTextStrokeColor"},
	{FPDCPWLWndSEL, FPDCPWLWndGetFontSizeSEL, L"FPDCPWLWndGetFontSize"},
	{FPDCPWLWndSEL, FPDCPWLWndGetInnerBorderWidthSEL, L"FPDCPWLWndGetInnerBorderWidth"},
	{FPDCPWLWndSEL, FPDCPWLWndGetBorderLeftTopColorSEL, L"FPDCPWLWndGetBorderLeftTopColor"},
	{FPDCPWLWndSEL, FPDCPWLWndGetBorderRightBottomColorSEL, L"FPDCPWLWndGetBorderRightBottomColor"},
	{FPDCPWLWndSEL, FPDCPWLWndIsModifiedSEL, L"FPDCPWLWndIsModified"},
	{FPDCPWLWndSEL, FPDCPWLWndSetFontSizeSEL, L"FPDCPWLWndSetFontSize"},
	{FPDCPWLWndSEL, FPDCPWLWndSetBackgroundColorSEL, L"FPDCPWLWndSetBackgroundColor"},
	{FPDCPWLWndSEL, FPDCPWLWndSetBorderColorSEL, L"FPDCPWLWndSetBorderColor"},
	{FPDCPWLWndSEL, FPDCPWLWndSetBorderWidthSEL, L"FPDCPWLWndSetBorderWidth"},
	{FPDCPWLWndSEL, FPDCPWLWndSetClipRectSEL, L"FPDCPWLWndSetClipRect"},
	{FPDCPWLWndSEL, FPDCPWLWndSetBorderStyleSEL, L"FPDCPWLWndSetBorderStyle"},
	{FPDCPWLWndSEL, FPDCPWLWndSetBorderDashSEL, L"FPDCPWLWndSetBorderDash"},
	{FPDCPWLWndSEL, FPDCPWLWndGetOriginWindowRectSEL, L"FPDCPWLWndGetOriginWindowRect"},
	{FPDCPWLWndSEL, FPDCPWLWndGetWindowRectSEL, L"FPDCPWLWndGetWindowRect"},
	{FPDCPWLWndSEL, FPDCPWLWndGetClientRectSEL, L"FPDCPWLWndGetClientRect"},
	{FPDCPWLWndSEL, FPDCPWLWndGetCenterPointSEL, L"FPDCPWLWndGetCenterPoint"},
	{FPDCPWLWndSEL, FPDCPWLWndGetClientCenterSquareSEL, L"FPDCPWLWndGetClientCenterSquare"},
	{FPDCPWLWndSEL, FPDCPWLWndGetWindowCenterSquareSEL, L"FPDCPWLWndGetWindowCenterSquare"},
	{FPDCPWLWndSEL, FPDCPWLWndGetBorderWidthSEL, L"FPDCPWLWndGetBorderWidth"},
	{FPDCPWLWndSEL, FPDCPWLWndIsVisibleSEL, L"FPDCPWLWndIsVisible"},
	{FPDCPWLWndSEL, FPDCPWLWndHasFlagSEL, L"FPDCPWLWndHasFlag"},
	{FPDCPWLWndSEL, FPDCPWLWndAddFlagSEL, L"FPDCPWLWndAddFlag"},
	{FPDCPWLWndSEL, FPDCPWLWndRemoveFlagSEL, L"FPDCPWLWndRemoveFlag"},
	{FPDCPWLWndSEL, FPDCPWLWndIsUseFXFontDeAscentSEL, L"FPDCPWLWndIsUseFXFontDeAscent"},
	{FPDCPWLWndSEL, FPDCPWLWndGetClipRectSEL, L"FPDCPWLWndGetClipRect"},
	{FPDCPWLWndSEL, FPDCPWLWndGetParentWindowSEL, L"FPDCPWLWndGetParentWindow"},
	{FPDCPWLWndSEL, FPDCPWLWndGetBorderStyleSEL, L"FPDCPWLWndGetBorderStyle"},
	{FPDCPWLWndSEL, FPDCPWLWndGetBorderDashSEL, L"FPDCPWLWndGetBorderDash"},
	{FPDCPWLWndSEL, FPDCPWLWndGetAttachedDataSEL, L"FPDCPWLWndGetAttachedData"},
	{FPDCPWLWndSEL, FPDCPWLWndWndHitTestSEL, L"FPDCPWLWndWndHitTest"},
	{FPDCPWLWndSEL, FPDCPWLWndClientHitTestSEL, L"FPDCPWLWndClientHitTest"},
	{FPDCPWLWndSEL, FPDCPWLWndIsCaptureMouseSEL, L"FPDCPWLWndIsCaptureMouse"},
	{FPDCPWLWndSEL, FPDCPWLWndGetFocusedSEL, L"FPDCPWLWndGetFocused"},
	{FPDCPWLWndSEL, FPDCPWLWndIsFocusedSEL, L"FPDCPWLWndIsFocused"},
	{FPDCPWLWndSEL, FPDCPWLWndIsReadOnlySEL, L"FPDCPWLWndIsReadOnly"},
	{FPDCPWLWndSEL, FPDCPWLWndGetVScrollBarSEL, L"FPDCPWLWndGetVScrollBar"},
	{FPDCPWLWndSEL, FPDCPWLWndGetFontMapSEL, L"FPDCPWLWndGetFontMap"},
	{FPDCPWLWndSEL, FPDCPWLWndGetProviderSEL, L"FPDCPWLWndGetProvider"},
	{FPDCPWLWndSEL, FPDCPWLWndGetSystemHandlerSEL, L"FPDCPWLWndGetSystemHandler"},
	{FPDCPWLWndSEL, FPDCPWLWndGetFocusHandlerSEL, L"FPDCPWLWndGetFocusHandler"},
	{FPDCPWLWndSEL, FPDCPWLWndGetTransparencySEL, L"FPDCPWLWndGetTransparency"},
	{FPDCPWLWndSEL, FPDCPWLWndSetTransparencySEL, L"FPDCPWLWndSetTransparency"},
	{FPDCPWLWndSEL, FPDCPWLWndGetChildToRootSEL, L"FPDCPWLWndGetChildToRoot"},
	{FPDCPWLWndSEL, FPDCPWLWndGetChildMatrixSEL, L"FPDCPWLWndGetChildMatrix"},
	{FPDCPWLWndSEL, FPDCPWLWndSetChildMatrixSEL, L"FPDCPWLWndSetChildMatrix"},
	{FPDCPWLWndSEL, FPDCPWLWndGetWindowMatrixSEL, L"FPDCPWLWndGetWindowMatrix"},
	{FPDCPWLWndSEL, FPDCPWLWndChildToParentSEL, L"FPDCPWLWndChildToParent"},
	{FPDCPWLWndSEL, FPDCPWLWndChildToParent2SEL, L"FPDCPWLWndChildToParent2"},
	{FPDCPWLWndSEL, FPDCPWLWndParentToChildSEL, L"FPDCPWLWndParentToChild"},
	{FPDCPWLWndSEL, FPDCPWLWndParentToChild2SEL, L"FPDCPWLWndParentToChild2"},
	{FPDCPWLWndSEL, FPDCPWLWndGetItemHeightSEL, L"FPDCPWLWndGetItemHeight"},
	{FPDCPWLWndSEL, FPDCPWLWndGetItemLeftMarginSEL, L"FPDCPWLWndGetItemLeftMargin"},
	{FPDCPWLWndSEL, FPDCPWLWndGetItemRightMarginSEL, L"FPDCPWLWndGetItemRightMargin"},
	{FPDCPWLWndSEL, FPDCPWLWndEnableWindowSEL, L"FPDCPWLWndEnableWindow"},
	{FPDCPWLWndSEL, FPDCPWLWndIsEnabledSEL, L"FPDCPWLWndIsEnabled"},
	{FPDCPWLWndSEL, FPDCPWLWndSetCursorSEL, L"FPDCPWLWndSetCursor"},
	{FPDCPWLWndSEL, FPDCPWLWndEnableRefreshSEL, L"FPDCPWLWndEnableRefresh"},
	{FPDCPWLWndSEL, FPDCPWLWndGetListTooltipSEL, L"FPDCPWLWndGetListTooltip"},
	{FPDCPWLWndSEL, FPDCPWLWndSetLayoutSEL, L"FPDCPWLWndSetLayout"},
	{FPDCPWLWndSEL, FPDCPWLWndSetNofifySEL, L"FPDCPWLWndSetNofify"},
	{FPDCPWLWndSEL, FPDCPWLWndSetClientRectSEL, L"FPDCPWLWndSetClientRect"},
	{FPDCPWLWndSEL, FPDCPWLWndGetOwnerClientRectSEL, L"FPDCPWLWndGetOwnerClientRect"},
	{FPDCPWLWndSEL, FPDCPWLWndAdpatDPI_XSEL, L"FPDCPWLWndAdpatDPI_X"},
	{FPDCPWLWndSEL, FPDCPWLWndAdpatDPI_YSEL, L"FPDCPWLWndAdpatDPI_Y"},
	{FPDCPWLWndSEL, FPDCPWLWndAddChildSEL, L"FPDCPWLWndAddChild"},
	{FPDCPWLWndSEL, FPDCPWLWndRemoveChildSEL, L"FPDCPWLWndRemoveChild"},
	{FPDCPWLWndSEL, FPDCPWLWndDrawThisAppearanceSEL, L"FPDCPWLWndDrawThisAppearance"},
	{FPDCPWLWndSEL, FPDCPWLWndCreateChildWndSEL, L"FPDCPWLWndCreateChildWnd"},
	{FPDCPWLWndSEL, FPDCPWLWndRePosChildWndSEL, L"FPDCPWLWndRePosChildWnd"},
	{FPDCPWLWndSEL, FPDCPWLWndGetAppearanceStream2SEL, L"FPDCPWLWndGetAppearanceStream2"},
	{FPDCPWLWndSEL, FPDCPWLWndNew2SEL, L"FPDCPWLWndNew2"},
	{FPDCPWLWndSEL, FPDCPWLWndSetCaretToEndSEL, L"FPDCPWLWndSetCaretToEnd"},
	{FPDCPWLWndSEL, FPDCPWLWndCreateNotifySEL, L"FPDCPWLWndCreateNotify"},
	{FPDCPWLWndSEL, FPDCPWLWndDeleteNotifySEL, L"FPDCPWLWndDeleteNotify"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetIconAppStreamSEL, L"FPDCPWLUtilsGetIconAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsDrawIconAppStreamSEL, L"FPDCPWLUtilsDrawIconAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetDBClickWordRangeSEL, L"FPDCPWLUtilsGetDBClickWordRange"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetRectFillAppStreamSEL, L"FPDCPWLUtilsGetRectFillAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetBorderAppStreamSEL, L"FPDCPWLUtilsGetBorderAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetColorAppStreamSEL, L"FPDCPWLUtilsGetColorAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsInflateRectSEL, L"FPDCPWLUtilsInflateRect"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsDrawFillRectSEL, L"FPDCPWLUtilsDrawFillRect"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsDrawFillRect2SEL, L"FPDCPWLUtilsDrawFillRect2"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetEditAppStreamSEL, L"FPDCPWLUtilsGetEditAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsPWLColorToARGBSEL, L"FPDCPWLUtilsPWLColorToARGB"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsPWLColorToFXColorSEL, L"FPDCPWLUtilsPWLColorToFXColor"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsDeflateRectSEL, L"FPDCPWLUtilsDeflateRect"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsDevideColorSEL, L"FPDCPWLUtilsDevideColor"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetCheckBoxAppStreamSEL, L"FPDCPWLUtilsGetCheckBoxAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetCircleBorderAppStreamSEL, L"FPDCPWLUtilsGetCircleBorderAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetCircleFillAppStreamSEL, L"FPDCPWLUtilsGetCircleFillAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetDropButtonAppStreamSEL, L"FPDCPWLUtilsGetDropButtonAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetPushButtonAppStreamSEL, L"FPDCPWLUtilsGetPushButtonAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetRadioButtonAppStreamSEL, L"FPDCPWLUtilsGetRadioButtonAppStream"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsSubstractColorSEL, L"FPDCPWLUtilsSubstractColor"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsGetCenterSquareSEL, L"FPDCPWLUtilsGetCenterSquare"},
	{FPDCPWLUtilsSEL, FPDCPWLUtilsDrawStrokeRectSEL, L"FPDCPWLUtilsDrawStrokeRect"},
	{FPDColorFSEL, FPDColorFConvertColorTypeSEL, L"FPDColorFConvertColorType"},
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
	{FPDOutputPreviewSEL, FPDOutputPreviewCreateSEL, L"FPDOutputPreviewCreate"},
	{FPDOutputPreviewSEL, FPDOutputPreviewDestroySEL, L"FPDOutputPreviewDestroy"},
	{FPDOutputPreviewSEL, FPDOutputPreviewSetSimulationProfileSEL, L"FPDOutputPreviewSetSimulationProfile"},
	{FPDOutputPreviewSEL, FPDOutputPreviewHasPageOverprintSEL, L"FPDOutputPreviewHasPageOverprint"},
	{FPDOutputPreviewSEL, FPDOutputPreviewSetShowSEL, L"FPDOutputPreviewSetShow"},
	{FPDOutputPreviewSEL, FPDOutputPreviewSetPreviewSEL, L"FPDOutputPreviewSetPreview"},
	{FPDOutputPreviewSEL, FPDOutputPreviewGetPlatesSEL, L"FPDOutputPreviewGetPlates"},
	{FPDOutputPreviewSEL, FPDOutputPreviewSetCheckSEL, L"FPDOutputPreviewSetCheck"},
	{FPDOutputPreviewSEL, FPDOutputPreviewGetCheckSEL, L"FPDOutputPreviewGetCheck"},
	{FPDOutputPreviewSEL, FPDOutputPreviewGetFinalBitmapSEL, L"FPDOutputPreviewGetFinalBitmap"},
	{FPDImageSetParamSEL, FPDImageSetParamCreateSEL, L"FPDImageSetParamCreate"},
	{FPDImageSetParamSEL, FPDImageSetParamDestroySEL, L"FPDImageSetParamDestroy"},
	{FPDImageSetParamSEL, FPDImageSetParamSetColorSEL, L"FPDImageSetParamSetColor"},
	{FPDImageSetParamSEL, FPDImageSetParamGetColorSEL, L"FPDImageSetParamGetColor"},
	{FPDImageSetParamSEL, FPDImageSetParamSetQualitySEL, L"FPDImageSetParamSetQuality"},
	{FPDImageSetParamSEL, FPDImageSetParamGetQualitySEL, L"FPDImageSetParamGetQuality"},
	{FPDType3FontDictSEL, FPDType3FontDictCreateSEL, L"FPDType3FontDictCreate"},
	{FPDType3FontDictSEL, FPDType3FontDictDestroySEL, L"FPDType3FontDictDestroy"},
	{FPDType3FontDictSEL, FPDType3FontDictAddUnicodeSEL, L"FPDType3FontDictAddUnicode"},
	{FPDType3FontDictSEL, FPDType3FontDictGenerateFontDictSEL, L"FPDType3FontDictGenerateFontDict"},
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
	{FPDStandardLinearizationSEL, FPDStandardLinearizationGetCFPDLinearizedObjSEL, L"FPDStandardLinearizationGetCFPDLinearizedObj"},
	{FPDStandardLinearizationSEL, FPDStandardLinearizationGetLinearizedObjNumSEL, L"FPDStandardLinearizationGetLinearizedObjNum"},
	{FPDStandardLinearizationSEL, FPDStandardLinearizationLinearizeSEL, L"FPDStandardLinearizationLinearize"},
	{FPDStandardLinearizationSEL, FPDStandardLinearizationNewSEL, L"FPDStandardLinearizationNew"},
	{FPDStandardLinearizationSEL, FPDStandardLinearizationDeleteSEL, L"FPDStandardLinearizationDelete"},
	{FPDStandardLinearizationSEL, FPDStandardLinearizationCastToCreatorSEL, L"FPDStandardLinearizationCastToCreator"},
	{FPDStandardLinearizationSEL, FPDStandardLinearizationCreateSEL, L"FPDStandardLinearizationCreate"},
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V15----------
// In file fs_basicImpl.h
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
	{FRFormTextFindSEL, FRFormTextFindCreateFormTextFindSEL, L"FRFormTextFindCreateFormTextFind"},
	{FRFormTextFindSEL, FRFormTextFindDeleteFormTextFindSEL, L"FRFormTextFindDeleteFormTextFind"},
	{FRFormTextFindSEL, FRFormTextFindFindFirstSEL, L"FRFormTextFindFindFirst"},
	{FRFormTextFindSEL, FRFormTextFindFindNextSEL, L"FRFormTextFindFindNext"},
	{FRFormTextFindSEL, FRFormTextFindFindPrevSEL, L"FRFormTextFindFindPrev"},
	{FRFormTextFindSEL, FRFormTextFindGetRectArraySEL, L"FRFormTextFindGetRectArray"},
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
	{FPDFlattenSEL, FPDFlattenCreateFlattenSEL, L"FPDFlattenCreateFlatten"},
	{FPDFlattenSEL, FPDFlattenDeleteFlattenSEL, L"FPDFlattenDeleteFlatten"},
	{FPDFlattenSEL, FPDFlattenFlattenPageSEL, L"FPDFlattenFlattenPage"},
	{FPDFlattenSEL, FPDFlattenFlattenPage2SEL, L"FPDFlattenFlattenPage2"},
	{FPDFlattenSEL, FPDFlattenSetFlattenProviderSEL, L"FPDFlattenSetFlattenProvider"},
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
	{FPD3DFRMConfigurationSEL, FPD3DFRMConfigurationGetNameSEL, L"FPD3DFRMConfigurationGetName"},
	{FPD3DFRMConfigurationSEL, FPD3DFRMConfigurationGetContentTypeSEL, L"FPD3DFRMConfigurationGetContentType"},
	{FPD3DFRMConfigurationSEL, FPD3DFRMConfigurationGetInstancesSEL, L"FPD3DFRMConfigurationGetInstances"},
	{FPD3DFRMInstanceSEL, FPD3DFRMInstanceAs3DInstanceSEL, L"FPD3DFRMInstanceAs3DInstance"},
	{FPD3DFRMInstanceSEL, FPD3DFRMInstanceGetContextSEL, L"FPD3DFRMInstanceGetContext"},
	{FPD3DFRMInstanceSEL, FPD3DFRMInstanceGetAnnotDataSEL, L"FPD3DFRMInstanceGetAnnotData"},
	{FPD3DFRMInstanceSEL, FPD3DFRMInstanceGetContentTypeSEL, L"FPD3DFRMInstanceGetContentType"},
	{FPD3DFRMInstanceSEL, FPD3DFRMInstanceGetAssetFileSpecSEL, L"FPD3DFRMInstanceGetAssetFileSpec"},
	{FPD3DInstanceSEL, FPD3DInstancePrepareActivateSEL, L"FPD3DInstancePrepareActivate"},
	{FPD3DInstanceSEL, FPD3DInstanceAllocAndActivateCanvasToplevelSEL, L"FPD3DInstanceAllocAndActivateCanvasToplevel"},
	{FPD3DInstanceSEL, FPD3DInstanceAllocAndActivateCanvasEmbeddedSEL, L"FPD3DInstanceAllocAndActivateCanvasEmbedded"},
	{FPD3DInstanceSEL, FPD3DInstanceActivateSEL, L"FPD3DInstanceActivate"},
	{FPD3DInstanceSEL, FPD3DInstanceAllocCanvasToplevelSEL, L"FPD3DInstanceAllocCanvasToplevel"},
	{FPD3DInstanceSEL, FPD3DInstanceAllocCanvasEmbeddedSEL, L"FPD3DInstanceAllocCanvasEmbedded"},
	{FPD3DInstanceSEL, FPD3DInstanceReleaseCanvasSEL, L"FPD3DInstanceReleaseCanvas"},
	{FPD3DInstanceSEL, FPD3DInstanceDeactivateSEL, L"FPD3DInstanceDeactivate"},
	{FPD3DInstanceSEL, FPD3DInstanceGetSceneSEL, L"FPD3DInstanceGetScene"},
	{FPD3DInstanceSEL, FPD3DInstanceGetAssetSEL, L"FPD3DInstanceGetAsset"},
	{FPD3DInstanceSEL, FPD3DInstanceGetToolSEL, L"FPD3DInstanceGetTool"},
	{FPD3DInstanceSEL, FPD3DInstanceGetDefaultPresetViewSEL, L"FPD3DInstanceGetDefaultPresetView"},
	{FPD3DInstanceSEL, FPD3DInstanceExecuteCustomMenuItemSEL, L"FPD3DInstanceExecuteCustomMenuItem"},
	{FPD3DInstanceSEL, FPD3DInstanceGetCustomMenuItemByIndexSEL, L"FPD3DInstanceGetCustomMenuItemByIndex"},
	{FPD3DInstanceSEL, FPD3DInstanceFindCustomMenuItemIndexByNameSEL, L"FPD3DInstanceFindCustomMenuItemIndexByName"},
	{FPD3DInstanceSEL, FPD3DInstanceCountCustomMenuItemsSEL, L"FPD3DInstanceCountCustomMenuItems"},
	{FPD3DInstanceSEL, FPD3DInstanceGetCustomToolButtonDataByIndexSEL, L"FPD3DInstanceGetCustomToolButtonDataByIndex"},
	{FPD3DInstanceSEL, FPD3DInstanceFindCustomToolButtonIndexByNameSEL, L"FPD3DInstanceFindCustomToolButtonIndexByName"},
	{FPD3DInstanceSEL, FPD3DInstanceSetCustomToolButtonVisibleSEL, L"FPD3DInstanceSetCustomToolButtonVisible"},
	{FPD3DInstanceSEL, FPD3DInstanceSetCustomToolButtonEnabledSEL, L"FPD3DInstanceSetCustomToolButtonEnabled"},
	{FPD3DInstanceSEL, FPD3DInstanceCountCustomToolsSEL, L"FPD3DInstanceCountCustomTools"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaRetrieve3DPresetViewListSEL, L"FPD3dAnnotDataRichMediaRetrieve3DPresetViewList"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaUpdate3DPresetViewListSEL, L"FPD3dAnnotDataRichMediaUpdate3DPresetViewList"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaCreate3DPresetViewSEL, L"FPD3dAnnotDataRichMediaCreate3DPresetView"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaFind3DPresetViewSEL, L"FPD3dAnnotDataRichMediaFind3DPresetView"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaGetArtworkDefault3DPresetViewSEL, L"FPD3dAnnotDataRichMediaGetArtworkDefault3DPresetView"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaLoadSettingsOptionsSEL, L"FPD3dAnnotDataRichMediaLoadSettingsOptions"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaGetActivationOptionsSEL, L"FPD3dAnnotDataRichMediaGetActivationOptions"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaGetDeactivationOptionsSEL, L"FPD3dAnnotDataRichMediaGetDeactivationOptions"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaGetActivationConfigurationSEL, L"FPD3dAnnotDataRichMediaGetActivationConfiguration"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaGetActivationPresetViewSEL, L"FPD3dAnnotDataRichMediaGetActivationPresetView"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaGetAnnotDictSEL, L"FPD3dAnnotDataRichMediaGetAnnotDict"},
	{FPD3dAnnotDataRichMediaSEL, FPD3dAnnotDataRichMediaGetPageDictSEL, L"FPD3dAnnotDataRichMediaGetPageDict"},
	{FPD3deAnimationStyleSEL, FPD3deAnimationStyleNewSEL, L"FPD3deAnimationStyleNew"},
	{FPD3deAnimationStyleSEL, FPD3deAnimationStyleDestorySEL, L"FPD3deAnimationStyleDestory"},
	{FPD3deAnimationStyleSEL, FPD3deAnimationStyleNoAnimationSEL, L"FPD3deAnimationStyleNoAnimation"},
	{FPD3deAnimationStyleSEL, FPD3deAnimationStyleLinearAnimationSEL, L"FPD3deAnimationStyleLinearAnimation"},
	{FPD3deAnimationStyleSEL, FPD3deAnimationStyleOscillatingAnimationSEL, L"FPD3deAnimationStyleOscillatingAnimation"},
	{FPD3deAnimationStyleSEL, FPD3deAnimationStyleSetTypeSEL, L"FPD3deAnimationStyleSetType"},
	{FPD3deAnimationStyleSEL, FPD3deAnimationStyleGetTypeSEL, L"FPD3deAnimationStyleGetType"},
	{FPD3deAnimationStyleSEL, FPD3deAnimationStyleSetPlayCountSEL, L"FPD3deAnimationStyleSetPlayCount"},
	{FPD3deAnimationStyleSEL, FPD3deAnimationStyleGetPlayCountSEL, L"FPD3deAnimationStyleGetPlayCount"},
	{FPD3deAnimationStyleSEL, FPD3deAnimationStyleSetTimeMultiplierSEL, L"FPD3deAnimationStyleSetTimeMultiplier"},
	{FPD3deAnimationStyleSEL, FPD3deAnimationStyleGetTimeMultiplierSEL, L"FPD3deAnimationStyleGetTimeMultiplier"},
	{FPD3DFRMWindowDimenSEL, FPD3DFRMWindowDimenNewSEL, L"FPD3DFRMWindowDimenNew"},
	{FPD3DFRMWindowDimenSEL, FPD3DFRMWindowDimenDestorySEL, L"FPD3DFRMWindowDimenDestory"},
	{FPD3DFRMWindowDimenSEL, FPD3DFRMWindowDimenSetDefaultSEL, L"FPD3DFRMWindowDimenSetDefault"},
	{FPD3DFRMWindowDimenSEL, FPD3DFRMWindowDimenGetDefaultSEL, L"FPD3DFRMWindowDimenGetDefault"},
	{FPD3DFRMWindowDimenSEL, FPD3DFRMWindowDimenSetMaxSEL, L"FPD3DFRMWindowDimenSetMax"},
	{FPD3DFRMWindowDimenSEL, FPD3DFRMWindowDimenGetMaxSEL, L"FPD3DFRMWindowDimenGetMax"},
	{FPD3DFRMWindowDimenSEL, FPD3DFRMWindowDimenSetMinSEL, L"FPD3DFRMWindowDimenSetMin"},
	{FPD3DFRMWindowDimenSEL, FPD3DFRMWindowDimenGetMinSEL, L"FPD3DFRMWindowDimenGetMin"},
	{FPD3DFRMWindowPosSEL, FPD3DFRMWindowPosNewSEL, L"FPD3DFRMWindowPosNew"},
	{FPD3DFRMWindowPosSEL, FPD3DFRMWindowPosDestorySEL, L"FPD3DFRMWindowPosDestory"},
	{FPD3DFRMWindowPosSEL, FPD3DFRMWindowPosSetHAlignSEL, L"FPD3DFRMWindowPosSetHAlign"},
	{FPD3DFRMWindowPosSEL, FPD3DFRMWindowPosGetHAlignSEL, L"FPD3DFRMWindowPosGetHAlign"},
	{FPD3DFRMWindowPosSEL, FPD3DFRMWindowPosSetVAlignSEL, L"FPD3DFRMWindowPosSetVAlign"},
	{FPD3DFRMWindowPosSEL, FPD3DFRMWindowPosGetVAlignSEL, L"FPD3DFRMWindowPosGetVAlign"},
	{FPD3DFRMWindowPosSEL, FPD3DFRMWindowPosSetHOffsetSEL, L"FPD3DFRMWindowPosSetHOffset"},
	{FPD3DFRMWindowPosSEL, FPD3DFRMWindowPosGetHOffsetSEL, L"FPD3DFRMWindowPosGetHOffset"},
	{FPD3DFRMWindowPosSEL, FPD3DFRMWindowPosSetVOffsetSEL, L"FPD3DFRMWindowPosSetVOffset"},
	{FPD3DFRMWindowPosSEL, FPD3DFRMWindowPosGetVOffsetSEL, L"FPD3DFRMWindowPosGetVOffset"},
	{FPD3DFRMWindowSEL, FPD3DFRMWindowNewSEL, L"FPD3DFRMWindowNew"},
	{FPD3DFRMWindowSEL, FPD3DFRMWindowDestorySEL, L"FPD3DFRMWindowDestory"},
	{FPD3DFRMWindowSEL, FPD3DFRMWindowSetDimWidthSEL, L"FPD3DFRMWindowSetDimWidth"},
	{FPD3DFRMWindowSEL, FPD3DFRMWindowGetDimWidthSEL, L"FPD3DFRMWindowGetDimWidth"},
	{FPD3DFRMWindowSEL, FPD3DFRMWindowSetDimHeightSEL, L"FPD3DFRMWindowSetDimHeight"},
	{FPD3DFRMWindowSEL, FPD3DFRMWindowGetDimHeightSEL, L"FPD3DFRMWindowGetDimHeight"},
	{FPD3DFRMWindowSEL, FPD3DFRMWindowSetPosPositionSEL, L"FPD3DFRMWindowSetPosPosition"},
	{FPD3DFRMWindowSEL, FPD3DFRMWindowGetPosPositionSEL, L"FPD3DFRMWindowGetPosPosition"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationNewSEL, L"FPD3DFRMPresentationNew"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationDestorySEL, L"FPD3DFRMPresentationDestory"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationSetStyleSEL, L"FPD3DFRMPresentationSetStyle"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationGetStyleSEL, L"FPD3DFRMPresentationGetStyle"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationSetWindowSEL, L"FPD3DFRMPresentationSetWindow"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationGetWindowSEL, L"FPD3DFRMPresentationGetWindow"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationSetTransparentCanvasSEL, L"FPD3DFRMPresentationSetTransparentCanvas"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationGetTransparentCanvasSEL, L"FPD3DFRMPresentationGetTransparentCanvas"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationSetShowNavigationPanelSEL, L"FPD3DFRMPresentationSetShowNavigationPanel"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationGetShowNavigationPanelSEL, L"FPD3DFRMPresentationGetShowNavigationPanel"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationSetShowToolbarSEL, L"FPD3DFRMPresentationSetShowToolbar"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationGetShowToolbarSEL, L"FPD3DFRMPresentationGetShowToolbar"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationSetPassContextClickSEL, L"FPD3DFRMPresentationSetPassContextClick"},
	{FPD3DFRMPresentationSEL, FPD3DFRMPresentationGetPassContextClickSEL, L"FPD3DFRMPresentationGetPassContextClick"},
	{FPD3DFRMActivationSEL, FPD3DFRMActivationNewSEL, L"FPD3DFRMActivationNew"},
	{FPD3DFRMActivationSEL, FPD3DFRMActivationDestorySEL, L"FPD3DFRMActivationDestory"},
	{FPD3DFRMActivationSEL, FPD3DFRMActivationSetConditionSEL, L"FPD3DFRMActivationSetCondition"},
	{FPD3DFRMActivationSEL, FPD3DFRMActivationGetConditionSEL, L"FPD3DFRMActivationGetCondition"},
	{FPD3DFRMActivationSEL, FPD3DFRMActivationSetAnimationSEL, L"FPD3DFRMActivationSetAnimation"},
	{FPD3DFRMActivationSEL, FPD3DFRMActivationGetAnimationSEL, L"FPD3DFRMActivationGetAnimation"},
	{FPD3DFRMActivationSEL, FPD3DFRMActivationSetPresentationSEL, L"FPD3DFRMActivationSetPresentation"},
	{FPD3DFRMActivationSEL, FPD3DFRMActivationGetPresentationSEL, L"FPD3DFRMActivationGetPresentation"},
	{FPD3DFRMActivation2SEL, FPD3DFRMActivation2NewSEL, L"FPD3DFRMActivation2New"},
	{FPD3DFRMActivation2SEL, FPD3DFRMActivation2DestorySEL, L"FPD3DFRMActivation2Destory"},
	{FPD3DFRMActivation2SEL, FPD3DFRMActivation2SetViewSEL, L"FPD3DFRMActivation2SetView"},
	{FPD3DFRMActivation2SEL, FPD3DFRMActivation2GetViewSEL, L"FPD3DFRMActivation2GetView"},
	{FPD3DFRMActivation2SEL, FPD3DFRMActivation2SetConfigurationSEL, L"FPD3DFRMActivation2SetConfiguration"},
	{FPD3DFRMActivation2SEL, FPD3DFRMActivation2GetConfigurationSEL, L"FPD3DFRMActivation2GetConfiguration"},
	{FPD3DFRMDeactivationSEL, FPD3DFRMDeactivationNewSEL, L"FPD3DFRMDeactivationNew"},
	{FPD3DFRMDeactivationSEL, FPD3DFRMDeactivationDestorySEL, L"FPD3DFRMDeactivationDestory"},
	{FPD3DFRMDeactivationSEL, FPD3DFRMDeactivationSetConditionSEL, L"FPD3DFRMDeactivationSetCondition"},
	{FPD3DFRMDeactivationSEL, FPD3DFRMDeactivationGetConditionSEL, L"FPD3DFRMDeactivationGetCondition"},
	{FPD3dCustomMenuItemDataSEL, FPD3dCustomMenuItemDataNewSEL, L"FPD3dCustomMenuItemDataNew"},
	{FPD3dCustomMenuItemDataSEL, FPD3dCustomMenuItemDataDestorySEL, L"FPD3dCustomMenuItemDataDestory"},
	{FPD3dCustomMenuItemDataSEL, FPD3dCustomMenuItemDataSetMenuItemNameSEL, L"FPD3dCustomMenuItemDataSetMenuItemName"},
	{FPD3dCustomMenuItemDataSEL, FPD3dCustomMenuItemDataGetMenuItemNameSEL, L"FPD3dCustomMenuItemDataGetMenuItemName"},
	{FPD3dCustomMenuItemDataSEL, FPD3dCustomMenuItemDataSetMenuLabelSEL, L"FPD3dCustomMenuItemDataSetMenuLabel"},
	{FPD3dCustomMenuItemDataSEL, FPD3dCustomMenuItemDataGetMenuLabelSEL, L"FPD3dCustomMenuItemDataGetMenuLabel"},
	{FPD3dCustomMenuItemDataSEL, FPD3dCustomMenuItemDataSetTypeSEL, L"FPD3dCustomMenuItemDataSetType"},
	{FPD3dCustomMenuItemDataSEL, FPD3dCustomMenuItemDataGetTypeSEL, L"FPD3dCustomMenuItemDataGetType"},
	{FPD3dCustomMenuItemDataSEL, FPD3dCustomMenuItemDataSetCheckedSEL, L"FPD3dCustomMenuItemDataSetChecked"},
	{FPD3dCustomMenuItemDataSEL, FPD3dCustomMenuItemDataGetCheckedSEL, L"FPD3dCustomMenuItemDataGetChecked"},
	{FPD3deSpriteDataSEL, FPD3deSpriteDataAsMeasureSEL, L"FPD3deSpriteDataAsMeasure"},
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
	{FPDSystemHanlerSEL, FPDSystemHanlerCreateSystemHandlerSEL, L"FPDSystemHanlerCreateSystemHandler"},
	{FPDSystemHanlerSEL, FPDSystemHanlerDeleteSystemHandlerSEL, L"FPDSystemHanlerDeleteSystemHandler"},
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V16----------
// In file fs_basicImpl.h
	{FSCORLORSEL, FSCORLORToArgbDecodeSEL, L"FSCORLORToArgbDecode"},
	{FSCORLORSEL, FSCORLORToArgbDecode2SEL, L"FSCORLORToArgbDecode2"},
	{FSCORLORSEL, FSCORLORToArgbEncodeSEL, L"FSCORLORToArgbEncode"},
	{FSCORLORSEL, FSCORLORToArgbEncode2SEL, L"FSCORLORToArgbEncode2"},
	{FSCORLORSEL, FSCORLORToRgbEncodeSEL, L"FSCORLORToRgbEncode"},
	{FSCORLORSEL, FSCORLORGetGValueFromColorSEL, L"FSCORLORGetGValueFromColor"},
	{FSCORLORSEL, FSCORLORGetRValueFromColorSEL, L"FSCORLORGetRValueFromColor"},
	{FSCORLORSEL, FSCORLORGetBValueFromColorSEL, L"FSCORLORGetBValueFromColor"},
	{FSCORLORSEL, FSCORLORAdobeCMYKtosRGBSEL, L"FSCORLORAdobeCMYKtosRGB"},
	{FSGLOGSEL, FSGLOGLogMessageSEL, L"FSGLOGLogMessage"},
	{FSCCodecSEL, FSCCodecCreateSEL, L"FSCCodecCreate"},
	{FSCCodecSEL, FSCCodecDestroyMgrSEL, L"FSCCodecDestroyMgr"},
	{FSCCodecSEL, FSCCodecPngEncodeSEL, L"FSCCodecPngEncode"},
	{FSCCodecSEL, FSCCodecBmpEncodeSEL, L"FSCCodecBmpEncode"},
	{FSCCodecSEL, FSCCodecTiffEncodeSEL, L"FSCCodecTiffEncode"},
	{FSCCodecSEL, FSCCodecLoadWorkingIccProfileSEL, L"FSCCodecLoadWorkingIccProfile"},
	{FSCCodecSEL, FSCCodecCreateTransformSEL, L"FSCCodecCreateTransform"},
	{FSCCodecSEL, FSCCodecJpegEncodeSEL, L"FSCCodecJpegEncode"},
	{FSCCodecSEL, FSCCodecJpegEncode2SEL, L"FSCCodecJpegEncode2"},
	{FSCCodecSEL, FSCCodecPngEncode2SEL, L"FSCCodecPngEncode2"},
	{FSCCodecSEL, FSCCodecTiffModuleSetICCProfileSEL, L"FSCCodecTiffModuleSetICCProfile"},
	{FSCCodecSEL, FSCCodecPngModuleSetICCProfileSEL, L"FSCCodecPngModuleSetICCProfile"},
	{FSCCodecSEL, FSCCodecCreateJpxEncoderSEL, L"FSCCodecCreateJpxEncoder"},
	{FSCCodecSEL, FSCCodecDeleteJpxEncoderSEL, L"FSCCodecDeleteJpxEncoder"},
	{FSCCodecSEL, FSCCodecJpxEncoderSetICCProfileSEL, L"FSCCodecJpxEncoderSetICCProfile"},
	{FSCCodecSEL, FSCCodecJpxEncoderSetLosslessSEL, L"FSCCodecJpxEncoderSetLossless"},
	{FSCCodecSEL, FSCCodecJpxEncoderSetColorSpaceSEL, L"FSCCodecJpxEncoderSetColorSpace"},
	{FSCCodecSEL, FSCCodecJpxEncoderEncodeSEL, L"FSCCodecJpxEncoderEncode"},
	{FSCCodecSEL, FSCCodecJpxEncoderEncode2SEL, L"FSCCodecJpxEncoderEncode2"},
	{FSCCodecSEL, FSCCodecCreateProgressvieJpxEncoderSEL, L"FSCCodecCreateProgressvieJpxEncoder"},
	{FSCCodecSEL, FSCCodecDeleteProgressvieJpxEncoderSEL, L"FSCCodecDeleteProgressvieJpxEncoder"},
	{FSCCodecSEL, FSCCodecProgressiveJpxEncodeStartSEL, L"FSCCodecProgressiveJpxEncodeStart"},
	{FSCCodecSEL, FSCCodecProgressiveJpxEncodeStart2SEL, L"FSCCodecProgressiveJpxEncodeStart2"},
	{FSCCodecSEL, FSCCodecProgressiveJpxEncodeContinueSEL, L"FSCCodecProgressiveJpxEncodeContinue"},
	{FSCCodecSEL, FSCCodecGetWebpModuleSEL, L"FSCCodecGetWebpModule"},
	{FSCCodecSEL, FSCCodecWebpModuleCreateDecoderSEL, L"FSCCodecWebpModuleCreateDecoder"},
	{FSCCodecSEL, FSCCodecWebpModuleGetImageInfoSEL, L"FSCCodecWebpModuleGetImageInfo"},
	{FSCCodecSEL, FSCCodecWebpModuleDecodeSEL, L"FSCCodecWebpModuleDecode"},
	{FSCCodecSEL, FSCCodecWebpModuleDestroyDecoderSEL, L"FSCCodecWebpModuleDestroyDecoder"},
	{FSCCodecSEL, FSCCodecSetIccProfilesPathSEL, L"FSCCodecSetIccProfilesPath"},
	{FSCCodecSEL, FSCCodecIsSetIccProfilesPathSEL, L"FSCCodecIsSetIccProfilesPath"},
	{FSCCodecSEL, FSCCodecSetWorkingIccProfileSEL, L"FSCCodecSetWorkingIccProfile"},
	{FSCCodecSEL, FSCCodecLoadIccProfileSEL, L"FSCCodecLoadIccProfile"},
	{FSSYSCommonMethodSEL, FSSYSCommonMethodSYS_wtoiSEL, L"FSSYSCommonMethodSYS_wtoi"},
	{FSSYSCommonMethodSEL, FSSYSCommonMethodSYS_atoiSEL, L"FSSYSCommonMethodSYS_atoi"},
	{FSSYSCommonMethodSEL, FSSYSCommonMethodClientToScreenPointSEL, L"FSSYSCommonMethodClientToScreenPoint"},
	{FSSYSCommonMethodSEL, FSSYSCommonMethodScreenToClientPointSEL, L"FSSYSCommonMethodScreenToClientPoint"},
	{FSSYSCommonMethodSEL, FSSYSCommonMethodGetDefaultScreenDpiSEL, L"FSSYSCommonMethodGetDefaultScreenDpi"},
	{FSSYSCommonMethodSEL, FSSYSCommonMethodUncompressSEL, L"FSSYSCommonMethodUncompress"},
	{FSDIBSourceSEL, FSDIBSourceCastToBitmapSEL, L"FSDIBSourceCastToBitmap"},
	{FSDIBSourceSEL, FSDIBSourceDestroySEL, L"FSDIBSourceDestroy"},
	{FSDIBSourceSEL, FSDIBSourceIsAlphaMaskSEL, L"FSDIBSourceIsAlphaMask"},
	{FSDIBSourceSEL, FSDIBSourceCloneConvertSEL, L"FSDIBSourceCloneConvert"},
	{FSDIBSourceSEL, FSDIBSourceCloneSEL, L"FSDIBSourceClone"},
	{FSDIBSourceSEL, FSDIBSourceGetWidthSEL, L"FSDIBSourceGetWidth"},
	{FSDIBSourceSEL, FSDIBSourceGetHeightSEL, L"FSDIBSourceGetHeight"},
	{FSDIBSourceSEL, FSDIBSourceGetFormatSEL, L"FSDIBSourceGetFormat"},
	{FSDIBSourceSEL, FSDIBSourceGetPitchSEL, L"FSDIBSourceGetPitch"},
	{FSDIBSourceSEL, FSDIBSourceGetPaletteSEL, L"FSDIBSourceGetPalette"},
	{FSDIBSourceSEL, FSDIBSourceGetBufferSEL, L"FSDIBSourceGetBuffer"},
	{FSDIBSourceSEL, FSDIBSourceGetScanlineSEL, L"FSDIBSourceGetScanline"},
	{FSDIBSourceSEL, FSDIBSourceDownSampleScanlineSEL, L"FSDIBSourceDownSampleScanline"},
	{FSDIBSourceSEL, FSDIBSourceGetBPPSEL, L"FSDIBSourceGetBPP"},
	{FSDIBSourceSEL, FSDIBSourceHasAlphaSEL, L"FSDIBSourceHasAlpha"},
	{FSDIBSourceSEL, FSDIBSourceIsOpaqueImageSEL, L"FSDIBSourceIsOpaqueImage"},
	{FSDIBSourceSEL, FSDIBSourceGetPaletteSizeSEL, L"FSDIBSourceGetPaletteSize"},
	{FSDIBSourceSEL, FSDIBSourceGetPaletteArgbSEL, L"FSDIBSourceGetPaletteArgb"},
	{FSDIBSourceSEL, FSDIBSourceSetPaletteArgbSEL, L"FSDIBSourceSetPaletteArgb"},
	{FSDIBSourceSEL, FSDIBSourceGetAlphaMaskSEL, L"FSDIBSourceGetAlphaMask"},
	{FSDIBSourceSEL, FSDIBSourceStretchToSEL, L"FSDIBSourceStretchTo"},
	{FSDIBSourceSEL, FSDIBSourceTransformToSEL, L"FSDIBSourceTransformTo"},
	{FSDIBSourceSEL, FSDIBSourceSwapXYSEL, L"FSDIBSourceSwapXY"},
	{FSDIBSourceSEL, FSDIBSourceFlipImageSEL, L"FSDIBSourceFlipImage"},
	{FSDIBSourceSEL, FSDIBSourceGetBitmapAlphaMaskSEL, L"FSDIBSourceGetBitmapAlphaMask"},
	{FSDIBSourceSEL, FSDIBSourceGetColorKeySEL, L"FSDIBSourceGetColorKey"},
	{FSDIBSourceSEL, FSDIBSourceGetBitmapWithoutColorKeySEL, L"FSDIBSourceGetBitmapWithoutColorKey"},
	{FSDIBSourceSEL, FSDIBSourceIsCmykImageSEL, L"FSDIBSourceIsCmykImage"},
	{FSDIBAttributeSEL, FSDIBAttributeCreateSEL, L"FSDIBAttributeCreate"},
	{FSDIBAttributeSEL, FSDIBAttributeDeleteSEL, L"FSDIBAttributeDelete"},
	{FSDIBAttributeSEL, FSDIBAttributeSetXDPISEL, L"FSDIBAttributeSetXDPI"},
	{FSDIBAttributeSEL, FSDIBAttributeGetXDPISEL, L"FSDIBAttributeGetXDPI"},
	{FSDIBAttributeSEL, FSDIBAttributeSetYDPISEL, L"FSDIBAttributeSetYDPI"},
	{FSDIBAttributeSEL, FSDIBAttributeGetYDPISEL, L"FSDIBAttributeGetYDPI"},
	{FSDIBAttributeSEL, FSDIBAttributeGetDPIUnitSEL, L"FSDIBAttributeGetDPIUnit"},
	{FSDIBAttributeSEL, FSDIBAttributeGetExifInfoSEL, L"FSDIBAttributeGetExifInfo"},
	{FSDIBAttributeSEL, FSDIBAttributeSetTiffFrameCompressTypeSEL, L"FSDIBAttributeSetTiffFrameCompressType"},
	{FSDIBAttributeSEL, FSDIBAttributeSetTiffFrameCompressJpegQualitySEL, L"FSDIBAttributeSetTiffFrameCompressJpegQuality"},
	{FSDIBAttributeSEL, FSDIBAttributeSetDPIUnitSEL, L"FSDIBAttributeSetDPIUnit"},
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
	{FRUIMgrSEL, FRUIMgrSplitChildFrameColumnSEL, L"FRUIMgrSplitChildFrameColumn"},
	{FRUIMgrSEL, FRUIMgrSplitChildFrameRowSEL, L"FRUIMgrSplitChildFrameRow"},
	{FRUIMgrSEL, FRUIMgrDeleteSplitNewWndSEL, L"FRUIMgrDeleteSplitNewWnd"},
	{FRUIMgrSEL, FRUIMgrSetFloatyTransparencySEL, L"FRUIMgrSetFloatyTransparency"},
	{FRUIMgrSEL, FRUIMgrAddFloatyBarBtnSEL, L"FRUIMgrAddFloatyBarBtn"},
	{FRUIMgrSEL, FRUIMgrCreateRibbonFloatySEL, L"FRUIMgrCreateRibbonFloaty"},
	{FRUIMgrSEL, FRUIMgrInsertRibbonBtnsAfterFloatyCreateSEL, L"FRUIMgrInsertRibbonBtnsAfterFloatyCreate"},
	{FRUIMgrSEL, FRUIMgrRemoveFloatyRibbonBtnsSEL, L"FRUIMgrRemoveFloatyRibbonBtns"},
	{FRUIMgrSEL, FRUIMgrGetDocTabIconSEL, L"FRUIMgrGetDocTabIcon"},
	{FRUIMgrSEL, FRUIMgrGetPDFChildFrmSplitWndRectSEL, L"FRUIMgrGetPDFChildFrmSplitWndRect"},
	{FRUIMgrSEL, FRUIMgrChangeUIRTLSEL, L"FRUIMgrChangeUIRTL"},
	{FRContainerFrmMgrHandlerSEL, FRContainerFrmMgrHandlerNewSEL, L"FRContainerFrmMgrHandlerNew"},
	{FRContainerFrmMgrHandlerSEL, FRContainerFrmMgrHandlerDestroySEL, L"FRContainerFrmMgrHandlerDestroy"},
	{FRContainerFrmMgrSEL, FRContainerFrmMgrGetContainerFrmMgrSEL, L"FRContainerFrmMgrGetContainerFrmMgr"},
	{FRContainerFrmMgrSEL, FRContainerFrmMgrCreateContainerFrameSEL, L"FRContainerFrmMgrCreateContainerFrame"},
	{FRContainerFrmMgrSEL, FRContainerFrmMgrGetContainerFrameSEL, L"FRContainerFrmMgrGetContainerFrame"},
	{FRContainerFrmMgrSEL, FRContainerFrmMgrOpenDocumentSEL, L"FRContainerFrmMgrOpenDocument"},
	{FRContainerFrmMgrSEL, FRContainerFrmMgrRegisterContainerFrmEventHandlerSEL, L"FRContainerFrmMgrRegisterContainerFrmEventHandler"},
	{FRContainerFrmMgrSEL, FRContainerFrmMgrUnRegisterContainerFrmEventHandlerSEL, L"FRContainerFrmMgrUnRegisterContainerFrmEventHandler"},
	{FRContainerFrmMgrSEL, FRContainerFrmMgrOnContainerFrmCreateSEL, L"FRContainerFrmMgrOnContainerFrmCreate"},
	{FRContainerFrmMgrSEL, FRContainerFrmMgrOnContainerFrmLoadFinishSEL, L"FRContainerFrmMgrOnContainerFrmLoadFinish"},
	{FRContainerFrmMgrSEL, FRContainerFrmMgrOnContainerFrmDestorySEL, L"FRContainerFrmMgrOnContainerFrmDestory"},
	{FRPrintProviderSEL, FRPrintProviderGetPrintProviderSEL, L"FRPrintProviderGetPrintProvider"},
	{FRPrintProviderSEL, FRPrintProviderGetPrintDocSEL, L"FRPrintProviderGetPrintDoc"},
	{FRPrintProviderSEL, FRPrintProviderGetDefaultPrinterNameSEL, L"FRPrintProviderGetDefaultPrinterName"},
	{FRPrintProviderSEL, FRPrintProviderIsSnapShotSEL, L"FRPrintProviderIsSnapShot"},
	{FRPrintProviderSEL, FRPrintProviderGetDispModeSEL, L"FRPrintProviderGetDispMode"},
	{FRPrintProviderSEL, FRPrintProviderGetDefaultPrinterDevModeSEL, L"FRPrintProviderGetDefaultPrinterDevMode"},
	{FRPrintProviderSEL, FRPrintProviderSetDefaultPrinterDevModeSEL, L"FRPrintProviderSetDefaultPrinterDevMode"},
	{FRPrintProviderSEL, FRPrintProviderAnnotsSortByOrderSEL, L"FRPrintProviderAnnotsSortByOrder"},
	{FRPrintProviderSEL, FRPrintProviderGetPrintParentHwndSEL, L"FRPrintProviderGetPrintParentHwnd"},
	{FRPrintProviderSEL, FRPrintProviderReleasePrintProviderSEL, L"FRPrintProviderReleasePrintProvider"},
	{FRWndProviderSEL, FRWndProviderGetCurrentWndProvideSEL, L"FRWndProviderGetCurrentWndProvide"},
	{FRWndProviderSEL, FRWndProviderGetProviderNameSEL, L"FRWndProviderGetProviderName"},
	{FRGlobalDataSEL, FRGlobalDataIsForbiddenActionChangeZoomSEL, L"FRGlobalDataIsForbiddenActionChangeZoom"},
	{FRGlobalDataSEL, FRGlobalDataIsReplaceDocumentColorsSEL, L"FRGlobalDataIsReplaceDocumentColors"},
	{FRGlobalDataSEL, FRGlobalDataIsOnlyChangeColorBlackTextSEL, L"FRGlobalDataIsOnlyChangeColorBlackText"},
	{FRGlobalDataSEL, FRGlobalDataIsChangeColorTextOrBlackLineArtSEL, L"FRGlobalDataIsChangeColorTextOrBlackLineArt"},
	{FRGlobalDataSEL, FRGlobalDataIsEnableAssistiveTechnologySupportSEL, L"FRGlobalDataIsEnableAssistiveTechnologySupport"},
	{FRGlobalDataSEL, FRGlobalDataIsEmbedContentTextFontSEL, L"FRGlobalDataIsEmbedContentTextFont"},
	{FRGlobalDataSEL, FRGlobalDataIsUseLogicalPageSEL, L"FRGlobalDataIsUseLogicalPage"},
	{FRGlobalDataSEL, FRGlobalDataGetEidtDirectionSEL, L"FRGlobalDataGetEidtDirection"},
	{FRGlobalDataSEL, FRGlobalDataGetInitialOpenDirSEL, L"FRGlobalDataGetInitialOpenDir"},
	{FRHandlerDataTypeSEL, FRHandlerDataTypeCreateDataTypeSEL, L"FRHandlerDataTypeCreateDataType"},
	{FRHandlerDataTypeSEL, FRHandlerDataTypeDeleteDataTypeSEL, L"FRHandlerDataTypeDeleteDataType"},
	{FRMuCopyDataSEL, FRMuCopyDataCreateSEL, L"FRMuCopyDataCreate"},
	{FRMuCopyDataSEL, FRMuCopyDataDestroySEL, L"FRMuCopyDataDestroy"},
	{FRMuCopyDataSEL, FRMuCopyDataGetClientDataSEL, L"FRMuCopyDataGetClientData"},
	{FRMuCopyDataSEL, FRMuCopyDataGetRectArraySEL, L"FRMuCopyDataGetRectArray"},
	{FRMuCopyDataSEL, FRMuCopyDataGetRowCountSEL, L"FRMuCopyDataGetRowCount"},
	{FRMuCopyDataSEL, FRMuCopyDataSetClientDataSEL, L"FRMuCopyDataSetClientData"},
	{FRMuCopyDataSEL, FRMuCopyDataSetRectArraySEL, L"FRMuCopyDataSetRectArray"},
	{FRMuCopyDataSEL, FRMuCopyDataSetRowCountSEL, L"FRMuCopyDataSetRowCount"},
	{FRMuCopyDataSEL, FRMuCopyDataCopyDataSEL, L"FRMuCopyDataCopyData"},
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
	{FRTextLinkInfoSEL, FRTextLinkInfoCreateTextLinkInfoSEL, L"FRTextLinkInfoCreateTextLinkInfo"},
	{FRTextLinkInfoSEL, FRTextLinkInfoDeleteTextLinkInfoSEL, L"FRTextLinkInfoDeleteTextLinkInfo"},
	{FRTextLinkInfoSEL, FRTextLinkInfoGetPageIndexSEL, L"FRTextLinkInfoGetPageIndex"},
	{FRTextLinkInfoSEL, FRTextLinkInfoGetLinkUrlSEL, L"FRTextLinkInfoGetLinkUrl"},
	{FRTextLinkInfoSEL, FRTextLinkInfoGetRectArraySEL, L"FRTextLinkInfoGetRectArray"},
	{FRTextLinkInfoSEL, FRTextLinkInfoGetModifyDateSEL, L"FRTextLinkInfoGetModifyDate"},
	{FRTextLinkMgrSEL, FRTextLinkMgrIsEmailAddressSEL, L"FRTextLinkMgrIsEmailAddress"},
	{FRTextLinkMgrSEL, FRTextLinkMgrGetLinkListSEL, L"FRTextLinkMgrGetLinkList"},
	{FRTextLinkMgrSEL, FRTextLinkMgrExecuteTextLinkSEL, L"FRTextLinkMgrExecuteTextLink"},
	{FRSelectedImageInfoSEL, FRSelectedImageInfoGetImagePDFRectSEL, L"FRSelectedImageInfoGetImagePDFRect"},
	{FRSelectedImageInfoSEL, FRSelectedImageInfoGetParentFormSEL, L"FRSelectedImageInfoGetParentForm"},
	{FRSelectedImageInfoSEL, FRSelectedImageInfoGetObjSEL, L"FRSelectedImageInfoGetObj"},
	{FRContentObjectSEL, FRContentObjectCreateContentObjectSEL, L"FRContentObjectCreateContentObject"},
	{FRContentObjectSEL, FRContentObjectDeleteContentObjectSEL, L"FRContentObjectDeleteContentObject"},
	{FRContentObjectSEL, FRContentObjectGetDocViewSEL, L"FRContentObjectGetDocView"},
	{FRContentObjectSEL, FRContentObjectGetPageIndexSEL, L"FRContentObjectGetPageIndex"},
	{FRContentObjectSEL, FRContentObjectGetPosSEL, L"FRContentObjectGetPos"},
	{FRContentObjectSEL, FRContentObjectGetIsInFormXObjectSEL, L"FRContentObjectGetIsInFormXObject"},
	{FRContentObjectSEL, FRContentObjectGetFormLayerSEL, L"FRContentObjectGetFormLayer"},
	{FRContentObjectSEL, FRContentObjectGetObjSEL, L"FRContentObjectGetObj"},
	{FRContentObjectSEL, FRContentObjectGetObj2SEL, L"FRContentObjectGetObj2"},
	{FRContentObjectSEL, FRContentObjectGetContainerSEL, L"FRContentObjectGetContainer"},
	{FRContentObjectSEL, FRContentObjectGetFormMatrixSEL, L"FRContentObjectGetFormMatrix"},
	{FRContentObjectSEL, FRContentObjectGetObjContainerSEL, L"FRContentObjectGetObjContainer"},
	{FRContentObjectSEL, FRContentObjectSetDocViewSEL, L"FRContentObjectSetDocView"},
	{FRContentObjectSEL, FRContentObjectSetPageIndexSEL, L"FRContentObjectSetPageIndex"},
	{FRContentObjectSEL, FRContentObjectSetPosSEL, L"FRContentObjectSetPos"},
	{FRContentObjectSEL, FRContentObjectSetIsInFormXObjectSEL, L"FRContentObjectSetIsInFormXObject"},
	{FRContentObjectSEL, FRContentObjectSetFormLayerSEL, L"FRContentObjectSetFormLayer"},
	{FRContentObjectSEL, FRContentObjectSetTextRangeSEL, L"FRContentObjectSetTextRange"},
	{FRContentObjectSEL, FRContentObjectGetTextRangeSizeSEL, L"FRContentObjectGetTextRangeSize"},
	{FRContentObjectSEL, FRContentObjectGetTextRangeByIndexSEL, L"FRContentObjectGetTextRangeByIndex"},
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
	{FRPDFVerwerContentProviderExSEL, FRPDFVerwerContentProviderExCreatePDFVerwerContentProviderExSEL, L"FRPDFVerwerContentProviderExCreatePDFVerwerContentProviderEx"},
	{FRPDFVerwerContentProviderExSEL, FRPDFVerwerContentProviderExDeletePDFVerwerContentProviderExSEL, L"FRPDFVerwerContentProviderExDeletePDFVerwerContentProviderEx"},
	{FRPDFViewerSEL, FRPDFViewerCreatePDFViewerSEL, L"FRPDFViewerCreatePDFViewer"},
	{FRPDFViewerSEL, FRPDFViewerGetPageCountSEL, L"FRPDFViewerGetPageCount"},
	{FRPDFViewerSEL, FRPDFViewerGetPageSEL, L"FRPDFViewerGetPage"},
	{FRPDFViewerSEL, FRPDFViewerGetCurrentPageIndexSEL, L"FRPDFViewerGetCurrentPageIndex"},
	{FRPDFViewerSEL, FRPDFViewerGotoPageSEL, L"FRPDFViewerGotoPage"},
	{FRPDFViewerSEL, FRPDFViewerGotoPage2SEL, L"FRPDFViewerGotoPage2"},
	{FRPDFViewerSEL, FRPDFViewerGotoPage3SEL, L"FRPDFViewerGotoPage3"},
	{FRPDFViewerSEL, FRPDFViewerGetZoomScaleSEL, L"FRPDFViewerGetZoomScale"},
	{FRPDFViewerSEL, FRPDFViewerZoomtoPageSEL, L"FRPDFViewerZoomtoPage"},
	{FRPDFViewerSEL, FRPDFViewerSetPageRotateSEL, L"FRPDFViewerSetPageRotate"},
	{FRPDFViewerSEL, FRPDFViewerGetPageRotateSEL, L"FRPDFViewerGetPageRotate"},
	{FRPDFViewerSEL, FRPDFViewerSetSizeSEL, L"FRPDFViewerSetSize"},
	{FRPDFViewerSEL, FRPDFViewerGetSizeSEL, L"FRPDFViewerGetSize"},
	{FRPDFViewerSEL, FRPDFViewerGetRenderDataSEL, L"FRPDFViewerGetRenderData"},
	{FRPDFViewerSEL, FRPDFViewerSetDisplayAnnotSEL, L"FRPDFViewerSetDisplayAnnot"},
	{FRPDFViewerSEL, FRPDFViewerGetCanvasWidthSEL, L"FRPDFViewerGetCanvasWidth"},
	{FRPDFViewerSEL, FRPDFViewerGetCanvasHeightSEL, L"FRPDFViewerGetCanvasHeight"},
	{FRPDFViewerSEL, FRPDFViewerGetScrollPosXSEL, L"FRPDFViewerGetScrollPosX"},
	{FRPDFViewerSEL, FRPDFViewerGetScrollPosYSEL, L"FRPDFViewerGetScrollPosY"},
	{FRPDFViewerSEL, FRPDFViewerScrollSEL, L"FRPDFViewerScroll"},
	{FRPDFViewerSEL, FRPDFViewerGetBrowserModeSEL, L"FRPDFViewerGetBrowserMode"},
	{FRPDFViewerSEL, FRPDFViewerScrollToPosXSEL, L"FRPDFViewerScrollToPosX"},
	{FRPDFViewerSEL, FRPDFViewerScrollToPosYSEL, L"FRPDFViewerScrollToPosY"},
	{FRPDFViewerSEL, FRPDFViewerContinueRenderingSEL, L"FRPDFViewerContinueRendering"},
	{FRPDFViewerSEL, FRPDFViewerAddRecordSEL, L"FRPDFViewerAddRecord"},
	{FRPDFViewerSEL, FRPDFViewerSetViewEventHandlerSEL, L"FRPDFViewerSetViewEventHandler"},
	{FRPDFViewerSEL, FRPDFViewerDeletePDFViewerSEL, L"FRPDFViewerDeletePDFViewer"},
	{FRPDFViewerPageSEL, FRPDFViewerPageGetPageRectSEL, L"FRPDFViewerPageGetPageRect"},
	{FRPDFViewerPageSEL, FRPDFViewerPageIsVisibleSEL, L"FRPDFViewerPageIsVisible"},
	{FRPDFViewerPageSEL, FRPDFViewerPageGetPageIndexSEL, L"FRPDFViewerPageGetPageIndex"},
	{FRPDFViewerPageSEL, FRPDFViewerPageGetPageFullRectSEL, L"FRPDFViewerPageGetPageFullRect"},
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
	{FPDGetBaseSEL, FPDGetBaseNewImageGetHandlerSEL, L"FPDGetBaseNewImageGetHandler"},
	{FPDGetBaseSEL, FPDGetBaseDestroyImageGetHandlerSEL, L"FPDGetBaseDestroyImageGetHandler"},
	{FPDPageImageCompressSEL, FPDPageImageCompressCreatePageImageCompressSEL, L"FPDPageImageCompressCreatePageImageCompress"},
	{FPDPageImageCompressSEL, FPDPageImageCompressDeletePageImageCompressSEL, L"FPDPageImageCompressDeletePageImageCompress"},
	{FPDPageImageCompressSEL, FPDPageImageCompressImageCompressForPageSEL, L"FPDPageImageCompressImageCompressForPage"},
	{FPDPageImageCompressSEL, FPDPageImageCompressSetDPIAboveSEL, L"FPDPageImageCompressSetDPIAbove"},
	{FPDImageInfoSEL, FPDImageInfoCreateImageInfoSEL, L"FPDImageInfoCreateImageInfo"},
	{FPDImageInfoSEL, FPDImageInfoDeleteImageInfoSEL, L"FPDImageInfoDeleteImageInfo"},
	{FPDImageInfoSEL, FPDImageInfoGetBufferSEL, L"FPDImageInfoGetBuffer"},
	{FPDImageInfoSEL, FPDImageInfoSetBufferSEL, L"FPDImageInfoSetBuffer"},
	{FPDImageInfoSEL, FPDImageInfoGetBufSizeSEL, L"FPDImageInfoGetBufSize"},
	{FPDImageInfoSEL, FPDImageInfoSetBufSizeSEL, L"FPDImageInfoSetBufSize"},
	{FPDImageInfoSEL, FPDImageInfoGetWidthSEL, L"FPDImageInfoGetWidth"},
	{FPDImageInfoSEL, FPDImageInfoSetWidthSEL, L"FPDImageInfoSetWidth"},
	{FPDImageInfoSEL, FPDImageInfoGetHeightSEL, L"FPDImageInfoGetHeight"},
	{FPDImageInfoSEL, FPDImageInfoSetHeightSEL, L"FPDImageInfoSetHeight"},
	{FPDImageInfoSEL, FPDImageInfoGetBppSEL, L"FPDImageInfoGetBpp"},
	{FPDImageInfoSEL, FPDImageInfoSetBppSEL, L"FPDImageInfoSetBpp"},
	{FPDImageInfoSEL, FPDImageInfoGetCompressionflagSEL, L"FPDImageInfoGetCompressionflag"},
	{FPDImageInfoSEL, FPDImageInfoSetCompressionflagSEL, L"FPDImageInfoSetCompressionflag"},
	{FPDImageInfoSEL, FPDImageInfoGetMaskInfoSEL, L"FPDImageInfoGetMaskInfo"},
	{FPDImageInfoSEL, FPDImageInfoSetMaskInfoSEL, L"FPDImageInfoSetMaskInfo"},
	{FPDImageInfoSEL, FPDImageInfoGetGlobalBufferSEL, L"FPDImageInfoGetGlobalBuffer"},
	{FPDImageInfoSEL, FPDImageInfoSetGlobalBufferSEL, L"FPDImageInfoSetGlobalBuffer"},
	{FPDImageInfoSEL, FPDImageInfoGetGlobalBufferSizeSEL, L"FPDImageInfoGetGlobalBufferSize"},
	{FPDImageInfoSEL, FPDImageInfoSetGlobalBufferSizeSEL, L"FPDImageInfoSetGlobalBufferSize"},
	{FPDImageInfoSEL, FPDImageInfoGetColorSpaceSEL, L"FPDImageInfoGetColorSpace"},
	{FPDImageInfoSEL, FPDImageInfoSetColorSpaceSEL, L"FPDImageInfoSetColorSpace"},
	{FPDImageInfoSEL, FPDImageInfoGetEncodeingTypeSEL, L"FPDImageInfoGetEncodeingType"},
	{FPDImageInfoSEL, FPDImageInfoSetEncodeingTypeSEL, L"FPDImageInfoSetEncodeingType"},
	{FPDImageCompressSEL, FPDImageCompressCreateImageCompressSEL, L"FPDImageCompressCreateImageCompress"},
	{FPDImageCompressSEL, FPDImageCompressDeleteImageCompressSEL, L"FPDImageCompressDeleteImageCompress"},
	{FPDImageCompressSEL, FPDImageCompressCompressSEL, L"FPDImageCompressCompress"},
	{FPDImageCompressSEL, FPDImageCompressStretchSEL, L"FPDImageCompressStretch"},
	{FPDImageCompressSEL, FPDImageCompressStretchDIBitmapWithGetSEL, L"FPDImageCompressStretchDIBitmapWithGet"},
	{FPDImageCompressSEL, FPDImageCompressGetImageInfoSEL, L"FPDImageCompressGetImageInfo"},
	{FPDImageCompressSEL, FPDImageCompressGetImageInfoByIndexSEL, L"FPDImageCompressGetImageInfoByIndex"},
	{FPDImageCompressSEL, FPDImageCompressGetImageInfoCountSEL, L"FPDImageCompressGetImageInfoCount"},
	{FPDImageCompressSEL, FPDImageCompressGetDIBitmapSEL, L"FPDImageCompressGetDIBitmap"},
	{FPDImageCompressSEL, FPDImageCompressGetSrcDIBitmapSEL, L"FPDImageCompressGetSrcDIBitmap"},
	{FPDImageCompressSEL, FPDImageCompressCanHighMrcSEL, L"FPDImageCompressCanHighMrc"},
	{FPDImageToPDFDocSEL, FPDImageToPDFDocAddImageToPageSEL, L"FPDImageToPDFDocAddImageToPage"},
	{FPDImageToPDFDocSEL, FPDImageToPDFDocGenPDFImageSEL, L"FPDImageToPDFDocGenPDFImage"},
	{FPDImageToPDFDocSEL, FPDImageToPDFDocGenImageObjSEL, L"FPDImageToPDFDocGenImageObj"},
	{FPDImageToPDFDocSEL, FPDImageToPDFDocGeneratePDFImageSEL, L"FPDImageToPDFDocGeneratePDFImage"},
	{FPDImageToPDFDocSEL, FPDImageToPDFDocDealMaskSEL, L"FPDImageToPDFDocDealMask"},
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
	{FPDCleanupSEL, FPDCleanupCreateCleanupSEL, L"FPDCleanupCreateCleanup"},
	{FPDCleanupSEL, FPDCleanupDeleteCleanupSEL, L"FPDCleanupDeleteCleanup"},
	{FPDCleanupSEL, FPDCleanupDisInvalidBookMarkSEL, L"FPDCleanupDisInvalidBookMark"},
	{FPDCleanupSEL, FPDCleanupDisInvalidLinkSEL, L"FPDCleanupDisInvalidLink"},
	{FPDCleanupSEL, FPDCleanupFlateEncodeStreamSEL, L"FPDCleanupFlateEncodeStream"},
	{FPDCleanupSEL, FPDCleanupFlateInsteadOfLZWSEL, L"FPDCleanupFlateInsteadOfLZW"},
	{FPDCleanupSEL, FPDCleanupGetObjsToDeleteSEL, L"FPDCleanupGetObjsToDelete"},
	{FPDCleanupSEL, FPDCleanupDiscardUnreferencedNamedDestinationsSEL, L"FPDCleanupDiscardUnreferencedNamedDestinations"},
	{FPDDiscardObjsSEL, FPDDiscardObjsCreateDiscardObjsSEL, L"FPDDiscardObjsCreateDiscardObjs"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDeleteDiscardObjsSEL, L"FPDDiscardObjsDeleteDiscardObjs"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDisDocFormSIRActionInfoSEL, L"FPDDiscardObjsDisDocFormSIRActionInfo"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDisFormSIRActionSEL, L"FPDDiscardObjsDisFormSIRAction"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDisPageThumbnailsSEL, L"FPDDiscardObjsDisPageThumbnails"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDisEmPrintSettingsSEL, L"FPDDiscardObjsDisEmPrintSettings"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDisBookmarksSEL, L"FPDDiscardObjsDisBookmarks"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDisJavaScriptActionSEL, L"FPDDiscardObjsDisJavaScriptAction"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDiscardAlternateImagesSEL, L"FPDDiscardObjsDiscardAlternateImages"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDiscardEmbeddedSearchIndexSEL, L"FPDDiscardObjsDiscardEmbeddedSearchIndex"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDiscardStrutureContentMarkSEL, L"FPDDiscardObjsDiscardStrutureContentMark"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDiscardStructuralParentTreeSEL, L"FPDDiscardObjsDiscardStructuralParentTree"},
	{FPDDiscardObjsSEL, FPDDiscardObjsGetObjsToDeleteSEL, L"FPDDiscardObjsGetObjsToDelete"},
	{FPDDiscardObjsSEL, FPDDiscardObjsDetectAndMergeImageDebrisSEL, L"FPDDiscardObjsDetectAndMergeImageDebris"},
	{FPDDiscardUserDataSEL, FPDDiscardUserDataCreateDiscardUserDataSEL, L"FPDDiscardUserDataCreateDiscardUserData"},
	{FPDDiscardUserDataSEL, FPDDiscardUserDataDeleteDiscardUserDataSEL, L"FPDDiscardUserDataDeleteDiscardUserData"},
	{FPDDiscardUserDataSEL, FPDDiscardUserDataDisAllCommentsFormsAndMultimediaSEL, L"FPDDiscardUserDataDisAllCommentsFormsAndMultimedia"},
	{FPDDiscardUserDataSEL, FPDDiscardUserDataDisExCrossRefSEL, L"FPDDiscardUserDataDisExCrossRef"},
	{FPDDiscardUserDataSEL, FPDDiscardUserDataDisDocInfoAndMetaDataSEL, L"FPDDiscardUserDataDisDocInfoAndMetaData"},
	{FPDDiscardUserDataSEL, FPDDiscardUserDataDisFileAttchmentsSEL, L"FPDDiscardUserDataDisFileAttchments"},
	{FPDDiscardUserDataSEL, FPDDiscardUserDataDisPrivateDataOfOtherAppSEL, L"FPDDiscardUserDataDisPrivateDataOfOtherApp"},
	{FPDDiscardUserDataSEL, FPDDiscardUserDataDiscardLayerSEL, L"FPDDiscardUserDataDiscardLayer"},
	{FPDDiscardUserDataSEL, FPDDiscardUserDataGetObjsToDeleteSEL, L"FPDDiscardUserDataGetObjsToDelete"},
	{FPDDiscardUserDataSEL, FPDDiscardUserDataHasFileAttatchSEL, L"FPDDiscardUserDataHasFileAttatch"},
	{FPDOptimizerSEL, FPDOptimizerCreateSEL, L"FPDOptimizerCreate"},
	{FPDOptimizerSEL, FPDOptimizerDeleteSEL, L"FPDOptimizerDelete"},
	{FPDOptimizerSEL, FPDOptimizerSetCallBackSEL, L"FPDOptimizerSetCallBack"},
	{FPDOptimizerSEL, FPDOptimizerSetOptimizerProviderSEL, L"FPDOptimizerSetOptimizerProvider"},
	{FPDOptimizerSEL, FPDOptimizerSetDeleteDataCallBackSEL, L"FPDOptimizerSetDeleteDataCallBack"},
	{FPDOptimizerSEL, FPDOptimizerStartOptimizerSEL, L"FPDOptimizerStartOptimizer"},
	{FPDOptimizerSEL, FPDOptimizerContinueOptimizerSEL, L"FPDOptimizerContinueOptimizer"},
	{FPDOptimizerSEL, FPDOptimizerGetNeedDeleteObjNumSEL, L"FPDOptimizerGetNeedDeleteObjNum"},
	{FPDOptimizerSEL, FPDOptimizerSetOptimizerCompressTypeSEL, L"FPDOptimizerSetOptimizerCompressType"},
	{FPDUnEmbeddedFontSEL, FPDUnEmbeddedFontCreateUnEmbeddedFontSEL, L"FPDUnEmbeddedFontCreateUnEmbeddedFont"},
	{FPDUnEmbeddedFontSEL, FPDUnEmbeddedFontDeleteUnEmbeddedFontSEL, L"FPDUnEmbeddedFontDeleteUnEmbeddedFont"},
	{FPDUnEmbeddedFontSEL, FPDUnEmbeddedFontUnEmbeddedFontSEL, L"FPDUnEmbeddedFontUnEmbeddedFont"},
	{FPDUnEmbeddedFontSEL, FPDUnEmbeddedFontGetAvailEmbeddedFontArySEL, L"FPDUnEmbeddedFontGetAvailEmbeddedFontAry"},
	{FPDSanitizeSEL, FPDSanitizeCreateSanitizeSEL, L"FPDSanitizeCreateSanitize"},
	{FPDSanitizeSEL, FPDSanitizeDeleteSanitizeSEL, L"FPDSanitizeDeleteSanitize"},
	{FPDSanitizeSEL, FPDSanitizeSetCallBackSEL, L"FPDSanitizeSetCallBack"},
	{FPDSanitizeSEL, FPDSanitizeOptimizeSEL, L"FPDSanitizeOptimize"},
	{FPDSanitizeSEL, FPDSanitizeSetDeleteDataCallBackSEL, L"FPDSanitizeSetDeleteDataCallBack"},
	{FPDSanitizeSEL, FPDSanitizeDeleteHiddenDataSEL, L"FPDSanitizeDeleteHiddenData"},
	{FPDSanitizeSEL, FPDSanitizeSanitizeSEL, L"FPDSanitizeSanitize"},
	{FPDSanitizeSEL, FPDSanitizeSetSanitizeOptimizerFlagSEL, L"FPDSanitizeSetSanitizeOptimizerFlag"},
	{FPDSanitizeSEL, FPDSanitizeGetObjsToDeleteSEL, L"FPDSanitizeGetObjsToDelete"},
	{FPDSanitizeSEL, FPDSanitizeSetSanitizeProviderSEL, L"FPDSanitizeSetSanitizeProvider"},
	{FPDOptimizerProviderSEL, FPDOptimizerProviderCreateSEL, L"FPDOptimizerProviderCreate"},
	{FPDOptimizerProviderSEL, FPDOptimizerProviderDeleteSEL, L"FPDOptimizerProviderDelete"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsCreateSEL, L"FPDOptimizerOptionsCreate"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsDeleteSEL, L"FPDOptimizerOptionsDelete"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetIsOptImageSEL, L"FPDOptimizerOptionsSetIsOptImage"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetIsOptImageSEL, L"FPDOptimizerOptionsGetIsOptImage"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetcpParamSEL, L"FPDOptimizerOptionsSetcpParam"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetcpParamSEL, L"FPDOptimizerOptionsGetcpParam"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetmpParamSEL, L"FPDOptimizerOptionsSetmpParam"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetmpParamSEL, L"FPDOptimizerOptionsGetmpParam"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetColorDPIAboveSEL, L"FPDOptimizerOptionsSetColorDPIAbove"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetColorDPIAboveSEL, L"FPDOptimizerOptionsGetColorDPIAbove"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetMonoDPIAboveSEL, L"FPDOptimizerOptionsSetMonoDPIAbove"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetMonoDPIAboveSEL, L"FPDOptimizerOptionsGetMonoDPIAbove"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetUnEmbedFontNameArySEL, L"FPDOptimizerOptionsSetUnEmbedFontNameAry"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetUnEmbedFontNameArySEL, L"FPDOptimizerOptionsGetUnEmbedFontNameAry"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetEmbedAllSubFontsSEL, L"FPDOptimizerOptionsSetEmbedAllSubFonts"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetEmbedAllSubFontsSEL, L"FPDOptimizerOptionsGetEmbedAllSubFonts"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetOptimizerTransparencyFlattenerSEL, L"FPDOptimizerOptionsSetOptimizerTransparencyFlattener"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetOptimizerTransparencyFlattenerSEL, L"FPDOptimizerOptionsGetOptimizerTransparencyFlattener"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetOptimizerDisOptionsSEL, L"FPDOptimizerOptionsSetOptimizerDisOptions"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetOptimizerDisOptionsSEL, L"FPDOptimizerOptionsGetOptimizerDisOptions"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetOptimizerDisUserDataOptionSEL, L"FPDOptimizerOptionsSetOptimizerDisUserDataOption"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetOptimizerDisUserDataOptionSEL, L"FPDOptimizerOptionsGetOptimizerDisUserDataOption"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetOptimizerClearUpOptionsSEL, L"FPDOptimizerOptionsSetOptimizerClearUpOptions"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetOptimizerClearUpOptionsSEL, L"FPDOptimizerOptionsGetOptimizerClearUpOptions"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetFlattenOptionsSEL, L"FPDOptimizerOptionsSetFlattenOptions"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetFlattenOptionsSEL, L"FPDOptimizerOptionsGetFlattenOptions"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsSetIsGreaterThanContinueCompressSEL, L"FPDOptimizerOptionsSetIsGreaterThanContinueCompress"},
	{FPDOptimizerOptionsSEL, FPDOptimizerOptionsGetIsGreaterThanContinueCompressSEL, L"FPDOptimizerOptionsGetIsGreaterThanContinueCompress"},
	{FPDSanitizeProviderSEL, FPDSanitizeProviderCreateSEL, L"FPDSanitizeProviderCreate"},
	{FPDSanitizeProviderSEL, FPDSanitizeProviderDeleteSEL, L"FPDSanitizeProviderDelete"},
	{FPDFlattenProviderSEL, FPDFlattenProviderCreateSEL, L"FPDFlattenProviderCreate"},
	{FPDFlattenProviderSEL, FPDFlattenProviderDeleteSEL, L"FPDFlattenProviderDelete"},
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
	{FPDIExternalImageEditorHandlerSEL, FPDIExternalImageEditorHandlerNewSEL, L"FPDIExternalImageEditorHandlerNew"},
	{FPDIExternalImageEditorHandlerSEL, FPDIExternalImageEditorHandlerDestroySEL, L"FPDIExternalImageEditorHandlerDestroy"},
	{FPDImageObjectUtilsSEL, FPDImageObjectUtilsEditImageWithSEL, L"FPDImageObjectUtilsEditImageWith"},
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
	{FPDPortfolioSEL, FPDPortfolioIsPortfolioPDFSEL, L"FPDPortfolioIsPortfolioPDF"},
	{FPDPortfolioSEL, FPDPortfolioConvertPortfolioPDFSEL, L"FPDPortfolioConvertPortfolioPDF"},
	{FPDPortfolioSEL, FPDPortfolioCreatePortfolioPDFSEL, L"FPDPortfolioCreatePortfolioPDF"},
	{FPDPortfolioSEL, FPDPortfolioCreatePortfolioSEL, L"FPDPortfolioCreatePortfolio"},
	{FPDPortfolioSEL, FPDPortfolioReleasePortfolioSEL, L"FPDPortfolioReleasePortfolio"},
	{FPDPortfolioSEL, FPDPortfolioAddFileSEL, L"FPDPortfolioAddFile"},
	{FPDPortfolioSEL, FPDPortfolioAddFile2SEL, L"FPDPortfolioAddFile2"},
	{FPDPortfolioSEL, FPDPortfolioAddFile3SEL, L"FPDPortfolioAddFile3"},
	{FPDPortfolioSEL, FPDPortfolioAddFile4SEL, L"FPDPortfolioAddFile4"},
	{FPDPortfolioSEL, FPDPortfolioAddFile5SEL, L"FPDPortfolioAddFile5"},
	{FPDPortfolioSEL, FPDPortfolioAddFile6SEL, L"FPDPortfolioAddFile6"},
	{FPDPortfolioSEL, FPDPortfolioRemoveFileSEL, L"FPDPortfolioRemoveFile"},
	{FPDPortfolioSEL, FPDPortfolioCreateFolderSEL, L"FPDPortfolioCreateFolder"},
	{FPDPortfolioSEL, FPDPortfolioDeleteFolderSEL, L"FPDPortfolioDeleteFolder"},
	{FPDPortfolioSEL, FPDPortfolioDeleteFolder2SEL, L"FPDPortfolioDeleteFolder2"},
	{FPDPortfolioSEL, FPDPortfolioModifyFolderModDateSEL, L"FPDPortfolioModifyFolderModDate"},
	{FPDPortfolioSEL, FPDPortfolioModifyFileStreamSEL, L"FPDPortfolioModifyFileStream"},
	{FPDPortfolioSEL, FPDPortfolioDragFileToFoderSEL, L"FPDPortfolioDragFileToFoder"},
	{FPDPortfolioSEL, FPDPortfolioDragFolderToFolderSEL, L"FPDPortfolioDragFolderToFolder"},
	{FPDPortfolioSEL, FPDPortfolioGetDocumentSEL, L"FPDPortfolioGetDocument"},
	{FPDPortfolioSEL, FPDPortfolioGetCollectionDictSEL, L"FPDPortfolioGetCollectionDict"},
	{FPDPortfolioSEL, FPDPortfolioGetSchemaDictSEL, L"FPDPortfolioGetSchemaDict"},
	{FPDPortfolioSEL, FPDPortfolioGetNamesDictSEL, L"FPDPortfolioGetNamesDict"},
	{FPDPortfolioSEL, FPDPortfolioGetEmbeddedFilesDictSEL, L"FPDPortfolioGetEmbeddedFilesDict"},
	{FPDPortfolioSEL, FPDPortfolioSetInitSortSEL, L"FPDPortfolioSetInitSort"},
	{FPDPortfolioSEL, FPDPortfolioGetInitSortCountSEL, L"FPDPortfolioGetInitSortCount"},
	{FPDPortfolioSEL, FPDPortfolioGetInitSortByIndexSEL, L"FPDPortfolioGetInitSortByIndex"},
	{FPDPortfolioSEL, FPDPortfolioGetFilesSizeSEL, L"FPDPortfolioGetFilesSize"},
	{FPDPortfolioSEL, FPDPortfolioGetFilesByIndexSEL, L"FPDPortfolioGetFilesByIndex"},
	{FPDPortfolioSEL, FPDPortfolioGetFoldersSizeSEL, L"FPDPortfolioGetFoldersSize"},
	{FPDPortfolioSEL, FPDPortfolioGetFoldersByIndexSEL, L"FPDPortfolioGetFoldersByIndex"},
	{FPDPortfolioSEL, FPDPortfolioSortPtlFilesSEL, L"FPDPortfolioSortPtlFiles"},
	{FPDPortfolioSEL, FPDPortfolioGetFoldersDictSEL, L"FPDPortfolioGetFoldersDict"},
	{FPDPortfolioSEL, FPDPortfolioGetFolderDictSEL, L"FPDPortfolioGetFolderDict"},
	{FPDPortfolioSEL, FPDPortfolioGetFolderDict2SEL, L"FPDPortfolioGetFolderDict2"},
	{FPDPortfolioSEL, FPDPortfolioGetFolderDict3SEL, L"FPDPortfolioGetFolderDict3"},
	{FPDPortfolioSEL, FPDPortfolioGetFolderIDSEL, L"FPDPortfolioGetFolderID"},
	{FPDPortfolioSEL, FPDPortfolioGetFolderFilesSizeSEL, L"FPDPortfolioGetFolderFilesSize"},
	{FPDPortfolioSEL, FPDPortfolioGetReorderNameSEL, L"FPDPortfolioGetReorderName"},
	{FPDPortfolioSEL, FPDPortfolioSetSchemaInfoSEL, L"FPDPortfolioSetSchemaInfo"},
	{FPDPortfolioSEL, FPDPortfolioGetSchemaInfoSEL, L"FPDPortfolioGetSchemaInfo"},
	{FPDPortfolioSEL, FPDPortfolioAddSchemaEleSEL, L"FPDPortfolioAddSchemaEle"},
	{FPDPortfolioSEL, FPDPortfolioDeleteSchemaEleSEL, L"FPDPortfolioDeleteSchemaEle"},
	{FPDPortfolioSEL, FPDPortfolioSetFileCISEL, L"FPDPortfolioSetFileCI"},
	{FPDPortfolioSEL, FPDPortfolioSetFileCI2SEL, L"FPDPortfolioSetFileCI2"},
	{FPDPortfolioSEL, FPDPortfolioSetFileCI3SEL, L"FPDPortfolioSetFileCI3"},
	{FPDPortfolioSEL, FPDPortfolioSetFileCI4SEL, L"FPDPortfolioSetFileCI4"},
	{FPDPortfolioSEL, FPDPortfolioGetFileCIIntSEL, L"FPDPortfolioGetFileCIInt"},
	{FPDPortfolioSEL, FPDPortfolioGetFileCIFloatSEL, L"FPDPortfolioGetFileCIFloat"},
	{FPDPortfolioSEL, FPDPortfolioGetFileCITextSEL, L"FPDPortfolioGetFileCIText"},
	{FPDPortfolioSEL, FPDPortfolioSetInitFileSEL, L"FPDPortfolioSetInitFile"},
	{FPDPortfolioSEL, FPDPortfolioGetInitFileSEL, L"FPDPortfolioGetInitFile"},
	{FPDPortfolioSEL, FPDPortfolioSetInitViewModeSEL, L"FPDPortfolioSetInitViewMode"},
	{FPDPortfolioSEL, FPDPortfolioGetInitViewModeSEL, L"FPDPortfolioGetInitViewMode"},
	{FPDPortfolioSEL, FPDPortfolioSetSplitSEL, L"FPDPortfolioSetSplit"},
	{FPDPortfolioSEL, FPDPortfolioGetSplitSEL, L"FPDPortfolioGetSplit"},
	{FPDPortfolioSEL, FPDPortfolioModifyFileStream2SEL, L"FPDPortfolioModifyFileStream2"},
	{FPDSCHEMASEL, FPDSCHEMACreateSchemaSEL, L"FPDSCHEMACreateSchema"},
	{FPDSCHEMASEL, FPDSCHEMADestroySchemaSEL, L"FPDSCHEMADestroySchema"},
	{FPDSCHEMASEL, FPDSCHEMASetSCHMEA_DATASEL, L"FPDSCHEMASetSCHMEA_DATA"},
	{FPDSCHEMASEL, FPDSCHEMAGetSCHMEA_DATASEL, L"FPDSCHEMAGetSCHMEA_DATA"},
	{FPDSCHEMASEL, FPDSCHEMASetSCHEMA_DICTSEL, L"FPDSCHEMASetSCHEMA_DICT"},
	{FPDSCHEMASEL, FPDSCHEMAGetSCHEMA_DICTSEL, L"FPDSCHEMAGetSCHEMA_DICT"},
	{FPDCONFIGADDSEL, FPDCONFIGADDCreateConfigSEL, L"FPDCONFIGADDCreateConfig"},
	{FPDCONFIGADDSEL, FPDCONFIGADDDestroyConfigSEL, L"FPDCONFIGADDDestroyConfig"},
	{FPDCONFIGADDSEL, FPDCONFIGADDSetFileNameSEL, L"FPDCONFIGADDSetFileName"},
	{FPDCONFIGADDSEL, FPDCONFIGADDGetFileNameSEL, L"FPDCONFIGADDGetFileName"},
	{FPDCONFIGADDSEL, FPDCONFIGADDGetIsOverWriteSEL, L"FPDCONFIGADDGetIsOverWrite"},
	{FPDCONFIGADDSEL, FPDCONFIGADDSetIsOverWriteSEL, L"FPDCONFIGADDSetIsOverWrite"},
	{FPDCONFIGADDSEL, FPDCONFIGADDGetParentFolderSEL, L"FPDCONFIGADDGetParentFolder"},
	{FPDCONFIGADDSEL, FPDCONFIGADDSetParentFolderSEL, L"FPDCONFIGADDSetParentFolder"},
	{FPDCONFIGADDSEL, FPDCONFIGADDSetProgressSEL, L"FPDCONFIGADDSetProgress"},
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
	{FPDPreflightResultSEL, FPDPreflightResultExportResultSEL, L"FPDPreflightResultExportResult"},
	{FPDPreflightResultSEL, FPDPreflightResultGetPreflightUIResultSEL, L"FPDPreflightResultGetPreflightUIResult"},
	{FPDPreflightResultSEL, FPDPreflightResultGetKeySEL, L"FPDPreflightResultGetKey"},
	{FPDPreflightResultSEL, FPDPreflightResultGetPageRangeSEL, L"FPDPreflightResultGetPageRange"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetPreflightEngineSEL, L"FPDPreflightEngineGetPreflightEngine"},
	{FPDPreflightEngineSEL, FPDPreflightEngineReleasetPreflightEngineSEL, L"FPDPreflightEngineReleasetPreflightEngine"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetOutputIntentSEL, L"FPDPreflightEngineGetOutputIntent"},
	{FPDPreflightEngineSEL, FPDPreflightEngineInitEngineSEL, L"FPDPreflightEngineInitEngine"},
	{FPDPreflightEngineSEL, FPDPreflightEngineSetLibrarySEL, L"FPDPreflightEngineSetLibrary"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetCurLibrarySEL, L"FPDPreflightEngineGetCurLibrary"},
	{FPDPreflightEngineSEL, FPDPreflightEngineSetLanguageSEL, L"FPDPreflightEngineSetLanguage"},
	{FPDPreflightEngineSEL, FPDPreflightEngineCreateResultSEL, L"FPDPreflightEngineCreateResult"},
	{FPDPreflightEngineSEL, FPDPreflightEngineReleaseResultSEL, L"FPDPreflightEngineReleaseResult"},
	{FPDPreflightEngineSEL, FPDPreflightEngineSetFavoriteSEL, L"FPDPreflightEngineSetFavorite"},
	{FPDPreflightEngineSEL, FPDPreflightEngineIsFavoriteSEL, L"FPDPreflightEngineIsFavorite"},
	{FPDPreflightEngineSEL, FPDPreflightEngineHaveFavoriteSEL, L"FPDPreflightEngineHaveFavorite"},
	{FPDPreflightEngineSEL, FPDPreflightEngineSaveConfigSEL, L"FPDPreflightEngineSaveConfig"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetProfileCurOutPutIntentSEL, L"FPDPreflightEngineGetProfileCurOutPutIntent"},
	{FPDPreflightEngineSEL, FPDPreflightEngineConvertPDFASEL, L"FPDPreflightEngineConvertPDFA"},
	{FPDPreflightEngineSEL, FPDPreflightEngineConvertPDFXSEL, L"FPDPreflightEngineConvertPDFX"},
	{FPDPreflightEngineSEL, FPDPreflightEngineConvertPDFESEL, L"FPDPreflightEngineConvertPDFE"},
	{FPDPreflightEngineSEL, FPDPreflightEngineConvertDocVersionSEL, L"FPDPreflightEngineConvertDocVersion"},
	{FPDPreflightEngineSEL, FPDPreflightEngineCheckSEL, L"FPDPreflightEngineCheck"},
	{FPDPreflightEngineSEL, FPDPreflightEngineFixupSEL, L"FPDPreflightEngineFixup"},
	{FPDPreflightEngineSEL, FPDPreflightEngineExecuteProfileSEL, L"FPDPreflightEngineExecuteProfile"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetRuleKeyArraySEL, L"FPDPreflightEngineGetRuleKeyArray"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetRuleValueArrayByKeySEL, L"FPDPreflightEngineGetRuleValueArrayByKey"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetFixupKeyArraySEL, L"FPDPreflightEngineGetFixupKeyArray"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetFixupValueArrayByKeySEL, L"FPDPreflightEngineGetFixupValueArrayByKey"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetProfileKeyArraySEL, L"FPDPreflightEngineGetProfileKeyArray"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetProfileValueArrayByKeySEL, L"FPDPreflightEngineGetProfileValueArrayByKey"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetMostUseKeyArraySEL, L"FPDPreflightEngineGetMostUseKeyArray"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetMostUseValueArrayByKeySEL, L"FPDPreflightEngineGetMostUseValueArrayByKey"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetMostFreqUseKeyArraySEL, L"FPDPreflightEngineGetMostFreqUseKeyArray"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetMostFreqUseValueMapByKeySEL, L"FPDPreflightEngineGetMostFreqUseValueMapByKey"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetIncludeVariablesKeyArraySEL, L"FPDPreflightEngineGetIncludeVariablesKeyArray"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetIncludeVariablesValueArrayByKeySEL, L"FPDPreflightEngineGetIncludeVariablesValueArrayByKey"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGenerateLibrarySEL, L"FPDPreflightEngineGenerateLibrary"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGenerateHeaderSEL, L"FPDPreflightEngineGenerateHeader"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetNameCommentSEL, L"FPDPreflightEngineGetNameComment"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetAProfileExSEL, L"FPDPreflightEngineGetAProfileEx"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetXProfileExSEL, L"FPDPreflightEngineGetXProfileEx"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetNameCommentExSEL, L"FPDPreflightEngineGetNameCommentEx"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetAProfileSEL, L"FPDPreflightEngineGetAProfile"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetXProfileSEL, L"FPDPreflightEngineGetXProfile"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetNameAndKeySEL, L"FPDPreflightEngineGetNameAndKey"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetKeyFromNameOrKeySEL, L"FPDPreflightEngineGetKeyFromNameOrKey"},
	{FPDPreflightEngineSEL, FPDPreflightEngineIsProfileCanDoFixSEL, L"FPDPreflightEngineIsProfileCanDoFix"},
	{FPDPreflightEngineSEL, FPDPreflightEngineGetErrorMsgSEL, L"FPDPreflightEngineGetErrorMsg"},
	{FPDPreflightPlateNameElementSEL, FPDPreflightPlateNameElementNewSEL, L"FPDPreflightPlateNameElementNew"},
	{FPDPreflightPlateNameElementSEL, FPDPreflightPlateNameElementDestorySEL, L"FPDPreflightPlateNameElementDestory"},
	{FPDPreflightPlateNameElementSEL, FPDPreflightPlateNameElementGetPalteNamesSEL, L"FPDPreflightPlateNameElementGetPalteNames"},
	{FPDPreflightICCProfileElementSEL, FPDPreflightICCProfileElementNewSEL, L"FPDPreflightICCProfileElementNew"},
	{FPDPreflightICCProfileElementSEL, FPDPreflightICCProfileElementDestorySEL, L"FPDPreflightICCProfileElementDestory"},
	{FPDPreflightICCProfileElementSEL, FPDPreflightICCProfileElementGetICCProfileInfoSEL, L"FPDPreflightICCProfileElementGetICCProfileInfo"},
	{FPDPreflightColorspaceElementSEL, FPDPreflightColorspaceElementNewSEL, L"FPDPreflightColorspaceElementNew"},
	{FPDPreflightColorspaceElementSEL, FPDPreflightColorspaceElementDestorySEL, L"FPDPreflightColorspaceElementDestory"},
	{FPDPreflightColorspaceElementSEL, FPDPreflightColorspaceElementGetColorspaceInfoSEL, L"FPDPreflightColorspaceElementGetColorspaceInfo"},
	{FPDPreflightColorspaceElementSEL, FPDPreflightColorspaceElementType2StringSEL, L"FPDPreflightColorspaceElementType2String"},
	{FPDPreflightColorspaceElementSEL, FPDPreflightColorspaceElementString2TypeSEL, L"FPDPreflightColorspaceElementString2Type"},
	{FPDPreflightImageInfoSEL, FPDPreflightImageInfoNewSEL, L"FPDPreflightImageInfoNew"},
	{FPDPreflightImageInfoSEL, FPDPreflightImageInfoDestorySEL, L"FPDPreflightImageInfoDestory"},
	{FPDPreflightImageInfoSEL, FPDPreflightImageInfoGetWidthSEL, L"FPDPreflightImageInfoGetWidth"},
	{FPDPreflightImageInfoSEL, FPDPreflightImageInfoGetHeightSEL, L"FPDPreflightImageInfoGetHeight"},
	{FPDPreflightImageInfoSEL, FPDPreflightImageInfoGetBPCSEL, L"FPDPreflightImageInfoGetBPC"},
	{FPDPreflightImageInfoSEL, FPDPreflightImageInfoIsMaskSEL, L"FPDPreflightImageInfoIsMask"},
	{FPDPreflightImageInfoSEL, FPDPreflightImageInfoGetFilterSEL, L"FPDPreflightImageInfoGetFilter"},
	{FPDPreflightImageInfoSEL, FPDPreflightImageInfoGetColorSpaceSEL, L"FPDPreflightImageInfoGetColorSpace"},
	{FPDPreflightFontElementSEL, FPDPreflightFontElementNewSEL, L"FPDPreflightFontElementNew"},
	{FPDPreflightFontElementSEL, FPDPreflightFontElementDestorySEL, L"FPDPreflightFontElementDestory"},
	{FPDPreflightFontElementSEL, FPDPreflightFontElementGetFontInfoSEL, L"FPDPreflightFontElementGetFontInfo"},
	{FPDPreflightShadeElementSEL, FPDPreflightShadeElementNewSEL, L"FPDPreflightShadeElementNew"},
	{FPDPreflightShadeElementSEL, FPDPreflightShadeElementDestorySEL, L"FPDPreflightShadeElementDestory"},
	{FPDPreflightShadeElementSEL, FPDPreflightShadeElementGetShadeInfoSEL, L"FPDPreflightShadeElementGetShadeInfo"},
	{FPDPreflightFormXObjetElementSEL, FPDPreflightFormXObjetElementNewSEL, L"FPDPreflightFormXObjetElementNew"},
	{FPDPreflightFormXObjetElementSEL, FPDPreflightFormXObjetElementDestorySEL, L"FPDPreflightFormXObjetElementDestory"},
	{FPDPreflightFormXObjetElementSEL, FPDPreflightFormXObjetElementGetFormXObjectInfoSEL, L"FPDPreflightFormXObjetElementGetFormXObjectInfo"},
	{FPDPreflightReportElementSEL, FPDPreflightReportElementNewSEL, L"FPDPreflightReportElementNew"},
	{FPDPreflightReportElementSEL, FPDPreflightReportElementDestorySEL, L"FPDPreflightReportElementDestory"},
	{FPDPreflightReportElementSEL, FPDPreflightReportElementCountElementsSEL, L"FPDPreflightReportElementCountElements"},
	{FPDPreflightReportElementSEL, FPDPreflightReportElementGetElementContentSEL, L"FPDPreflightReportElementGetElementContent"},
	{FPDPreflightReportElementSEL, FPDPreflightReportElementGetElementTagSEL, L"FPDPreflightReportElementGetElementTag"},
	{FPDPreflightPageElementSEL, FPDPreflightPageElementNewSEL, L"FPDPreflightPageElementNew"},
	{FPDPreflightPageElementSEL, FPDPreflightPageElementDestorySEL, L"FPDPreflightPageElementDestory"},
	{FPDPreflightPageElementSEL, FPDPreflightPageElementGetPageInfoSEL, L"FPDPreflightPageElementGetPageInfo"},
	{FPDPreflightPageElementSEL, FPDPreflightPageElementGetUserunitSEL, L"FPDPreflightPageElementGetUserunit"},
	{FPDPreflightAnnotElementSEL, FPDPreflightAnnotElementNewSEL, L"FPDPreflightAnnotElementNew"},
	{FPDPreflightAnnotElementSEL, FPDPreflightAnnotElementDestorySEL, L"FPDPreflightAnnotElementDestory"},
	{FPDPreflightAnnotElementSEL, FPDPreflightAnnotElementGetAnnotInfoSEL, L"FPDPreflightAnnotElementGetAnnotInfo"},
	{FPDPreflightAnnotElementSEL, FPDPreflightAnnotElementGetTypeSEL, L"FPDPreflightAnnotElementGetType"},
	{FPDPreflightAnnotElementSEL, FPDPreflightAnnotElementString2TypeSEL, L"FPDPreflightAnnotElementString2Type"},
	{FPDPreflightResourceElmentSEL, FPDPreflightResourceElmentNewSEL, L"FPDPreflightResourceElmentNew"},
	{FPDPreflightResourceElmentSEL, FPDPreflightResourceElmentDestorySEL, L"FPDPreflightResourceElmentDestory"},
	{FPDPreflightResourceElmentSEL, FPDPreflightResourceElmentGetResourceItemSEL, L"FPDPreflightResourceElmentGetResourceItem"},
	{FPDPreflightResourceElmentSEL, FPDPreflightResourceElmentGetCSSEL, L"FPDPreflightResourceElmentGetCS"},
	{FPDPreflightResourceElmentSEL, FPDPreflightResourceElmentGetFontSEL, L"FPDPreflightResourceElmentGetFont"},
	{FPDPreflightResourceElmentSEL, FPDPreflightResourceElmentGetFormXObjSEL, L"FPDPreflightResourceElmentGetFormXObj"},
	{FPDPreflightResourceElmentSEL, FPDPreflightResourceElmentGetPageSEL, L"FPDPreflightResourceElmentGetPage"},
	{FPDPreflightResourceElmentSEL, FPDPreflightResourceElmentGetShadeSEL, L"FPDPreflightResourceElmentGetShade"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementNewSEL, L"FPDPreflightDocumentElementNew"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementDestorySEL, L"FPDPreflightDocumentElementDestory"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementGetDocInfoSEL, L"FPDPreflightDocumentElementGetDocInfo"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementGetColorspacesSEL, L"FPDPreflightDocumentElementGetColorspaces"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementGetImagesSEL, L"FPDPreflightDocumentElementGetImages"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementGetFontsSEL, L"FPDPreflightDocumentElementGetFonts"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementGetSmoothShadesSEL, L"FPDPreflightDocumentElementGetSmoothShades"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementGetPatternsSEL, L"FPDPreflightDocumentElementGetPatterns"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementGetOuputIntentSEL, L"FPDPreflightDocumentElementGetOuputIntent"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementGetLayerSEL, L"FPDPreflightDocumentElementGetLayer"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementGetEmbeddedFileSEL, L"FPDPreflightDocumentElementGetEmbeddedFile"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementGetFormXObjectSEL, L"FPDPreflightDocumentElementGetFormXObject"},
	{FPDPreflightDocumentElementSEL, FPDPreflightDocumentElementGetPageSEL, L"FPDPreflightDocumentElementGetPage"},
	{FPDPreflightResultItemSEL, FPDPreflightResultItemGetNameSEL, L"FPDPreflightResultItemGetName"},
	{FPDPreflightResultItemSEL, FPDPreflightResultItemGetCommentSEL, L"FPDPreflightResultItemGetComment"},
	{FPDPreflightResultItemSEL, FPDPreflightResultItemGetDoneStatusSEL, L"FPDPreflightResultItemGetDoneStatus"},
	{FPDPreflightResultItemSEL, FPDPreflightResultItemGetDicKeySEL, L"FPDPreflightResultItemGetDicKey"},
	{FPDPreflightResultItemSEL, FPDPreflightResultItemString2TypeSEL, L"FPDPreflightResultItemString2Type"},
	{FPDPreflightFixupItemSEL, FPDPreflightFixupItemNewSEL, L"FPDPreflightFixupItemNew"},
	{FPDPreflightFixupItemSEL, FPDPreflightFixupItemDestorySEL, L"FPDPreflightFixupItemDestory"},
	{FPDPreflightFixupItemSEL, FPDPreflightFixupItemGetNameSEL, L"FPDPreflightFixupItemGetName"},
	{FPDPreflightFixupItemSEL, FPDPreflightFixupItemGetCommentSEL, L"FPDPreflightFixupItemGetComment"},
	{FPDPreflightFixupItemSEL, FPDPreflightFixupItemGetDoneStatusSEL, L"FPDPreflightFixupItemGetDoneStatus"},
	{FPDPreflightFixupItemSEL, FPDPreflightFixupItemGetDicKeySEL, L"FPDPreflightFixupItemGetDicKey"},
	{FPDPreflightFixupItemSEL, FPDPreflightFixupItemGetCountFailedSEL, L"FPDPreflightFixupItemGetCountFailed"},
	{FPDPreflightFixupItemSEL, FPDPreflightFixupItemGetCountsucceededSEL, L"FPDPreflightFixupItemGetCountsucceeded"},
	{FPDPreflightFixupItemSEL, FPDPreflightFixupItemGetDetailsSEL, L"FPDPreflightFixupItemGetDetails"},
	{FPDPreflightGeneralStateSEL, FPDPreflightGeneralStateNewSEL, L"FPDPreflightGeneralStateNew"},
	{FPDPreflightGeneralStateSEL, FPDPreflightGeneralStateDestorySEL, L"FPDPreflightGeneralStateDestory"},
	{FPDPreflightGeneralStateSEL, FPDPreflightGeneralStateGetFillColorSpaceSEL, L"FPDPreflightGeneralStateGetFillColorSpace"},
	{FPDPreflightGeneralStateSEL, FPDPreflightGeneralStateGetFillColorantValueSEL, L"FPDPreflightGeneralStateGetFillColorantValue"},
	{FPDPreflightGeneralStateSEL, FPDPreflightGeneralStateGetStrokeColorSpaceSEL, L"FPDPreflightGeneralStateGetStrokeColorSpace"},
	{FPDPreflightGeneralStateSEL, FPDPreflightGeneralStateGetStrokeColorantValueSEL, L"FPDPreflightGeneralStateGetStrokeColorantValue"},
	{FPDPreflightGeneralStateSEL, FPDPreflightGeneralStateGetRenderIntentSEL, L"FPDPreflightGeneralStateGetRenderIntent"},
	{FPDPreflightTextStateSEL, FPDPreflightTextStateNewSEL, L"FPDPreflightTextStateNew"},
	{FPDPreflightTextStateSEL, FPDPreflightTextStateDestorySEL, L"FPDPreflightTextStateDestory"},
	{FPDPreflightTextStateSEL, FPDPreflightTextStateGetFontSizeSEL, L"FPDPreflightTextStateGetFontSize"},
	{FPDPreflightTextStateSEL, FPDPreflightTextStateGetFontInfoSEL, L"FPDPreflightTextStateGetFontInfo"},
	{FPDPreflightGstateSEL, FPDPreflightGstateNewSEL, L"FPDPreflightGstateNew"},
	{FPDPreflightGstateSEL, FPDPreflightGstateDestorySEL, L"FPDPreflightGstateDestory"},
	{FPDPreflightGstateSEL, FPDPreflightGstateGetLineWidthSEL, L"FPDPreflightGstateGetLineWidth"},
	{FPDPreflightGstateSEL, FPDPreflightGstateGetMiterLimitSEL, L"FPDPreflightGstateGetMiterLimit"},
	{FPDPreflightGstateSEL, FPDPreflightGstateIsStrokeSEL, L"FPDPreflightGstateIsStroke"},
	{FPDPreflightGstateSEL, FPDPreflightGstateGetFlatnessToleranceSEL, L"FPDPreflightGstateGetFlatnessTolerance"},
	{FPDPreflightGstateSEL, FPDPreflightGstateGetSmoothnessToleranceSEL, L"FPDPreflightGstateGetSmoothnessTolerance"},
	{FPDPreflightGstateSEL, FPDPreflightGstateGetOverprintModeSEL, L"FPDPreflightGstateGetOverprintMode"},
	{FPDPreflightGstateSEL, FPDPreflightGstateIsOverprintForStrokeSEL, L"FPDPreflightGstateIsOverprintForStroke"},
	{FPDPreflightGstateSEL, FPDPreflightGstateIsOverprintForFillSEL, L"FPDPreflightGstateIsOverprintForFill"},
	{FPDPreflightImageStateSEL, FPDPreflightImageStateNewSEL, L"FPDPreflightImageStateNew"},
	{FPDPreflightImageStateSEL, FPDPreflightImageStateDestorySEL, L"FPDPreflightImageStateDestory"},
	{FPDPreflightImageStateSEL, FPDPreflightImageStateGetVResolutionSEL, L"FPDPreflightImageStateGetVResolution"},
	{FPDPreflightImageStateSEL, FPDPreflightImageStateGetHResolutionSEL, L"FPDPreflightImageStateGetHResolution"},
	{FPDPreflightImageStateSEL, FPDPreflightImageStateGetImageInfoSEL, L"FPDPreflightImageStateGetImageInfo"},
	{FPDPreflightTriggersSEL, FPDPreflightTriggersNewSEL, L"FPDPreflightTriggersNew"},
	{FPDPreflightTriggersSEL, FPDPreflightTriggersDestorySEL, L"FPDPreflightTriggersDestory"},
	{FPDPreflightTriggersSEL, FPDPreflightTriggersCountElementSEL, L"FPDPreflightTriggersCountElement"},
	{FPDPreflightTriggersSEL, FPDPreflightTriggersGetElementSEL, L"FPDPreflightTriggersGetElement"},
	{FPDPreflightTriggersSEL, FPDPreflightTriggersGetRuleDicKeySEL, L"FPDPreflightTriggersGetRuleDicKey"},
	{FPDPreflightFormxobjStateSEL, FPDPreflightFormxobjStateNewSEL, L"FPDPreflightFormxobjStateNew"},
	{FPDPreflightFormxobjStateSEL, FPDPreflightFormxobjStateDestorySEL, L"FPDPreflightFormxobjStateDestory"},
	{FPDPreflightFormxobjStateSEL, FPDPreflightFormxobjStateGetFormXObjectElementSEL, L"FPDPreflightFormxobjStateGetFormXObjectElement"},
	{FPDPreflightShadeStateSEL, FPDPreflightShadeStateNewSEL, L"FPDPreflightShadeStateNew"},
	{FPDPreflightShadeStateSEL, FPDPreflightShadeStateDestorySEL, L"FPDPreflightShadeStateDestory"},
	{FPDPreflightShadeStateSEL, FPDPreflightShadeStateGetShadeElementSEL, L"FPDPreflightShadeStateGetShadeElement"},
	{FPDPreflightInkStateSEL, FPDPreflightInkStateNewSEL, L"FPDPreflightInkStateNew"},
	{FPDPreflightInkStateSEL, FPDPreflightInkStateDestorySEL, L"FPDPreflightInkStateDestory"},
	{FPDPreflightInkStateSEL, FPDPreflightInkStateGetPlatenameElementSEL, L"FPDPreflightInkStateGetPlatenameElement"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemNewSEL, L"FPDPreflightHitItemNew"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemDestorySEL, L"FPDPreflightHitItemDestory"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetTriggersSEL, L"FPDPreflightHitItemGetTriggers"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetGStateSEL, L"FPDPreflightHitItemGetGState"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetTextStateSEL, L"FPDPreflightHitItemGetTextState"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetImageStateSEL, L"FPDPreflightHitItemGetImageState"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetFormxobjStateSEL, L"FPDPreflightHitItemGetFormxobjState"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetShadeStateSEL, L"FPDPreflightHitItemGetShadeState"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetHitTypeSEL, L"FPDPreflightHitItemGetHitType"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetPageIndexSEL, L"FPDPreflightHitItemGetPageIndex"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetPageElementSEL, L"FPDPreflightHitItemGetPageElement"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetPosXSEL, L"FPDPreflightHitItemGetPosX"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetPosYSEL, L"FPDPreflightHitItemGetPosY"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetSizeXSEL, L"FPDPreflightHitItemGetSizeX"},
	{FPDPreflightHitItemSEL, FPDPreflightHitItemGetSizeYSEL, L"FPDPreflightHitItemGetSizeY"},
	{FPDPreflightHitsElementSEL, FPDPreflightHitsElementNewSEL, L"FPDPreflightHitsElementNew"},
	{FPDPreflightHitsElementSEL, FPDPreflightHitsElementDestorySEL, L"FPDPreflightHitsElementDestory"},
	{FPDPreflightHitsElementSEL, FPDPreflightHitsElementGetElementSEL, L"FPDPreflightHitsElementGetElement"},
	{FPDPreflightHitsElementSEL, FPDPreflightHitsElementGetNameSEL, L"FPDPreflightHitsElementGetName"},
	{FPDPreflightHitsElementSEL, FPDPreflightHitsElementGetCommentSEL, L"FPDPreflightHitsElementGetComment"},
	{FPDPreflightHitsElementSEL, FPDPreflightHitsElementGetDoneStatusSEL, L"FPDPreflightHitsElementGetDoneStatus"},
	{FPDPreflightHitsElementSEL, FPDPreflightHitsElementGetDicKeySEL, L"FPDPreflightHitsElementGetDicKey"},
	{FPDPreflightHitssetElementSEL, FPDPreflightHitssetElementNewSEL, L"FPDPreflightHitssetElementNew"},
	{FPDPreflightHitssetElementSEL, FPDPreflightHitssetElementDestorySEL, L"FPDPreflightHitssetElementDestory"},
	{FPDPreflightHitssetElementSEL, FPDPreflightHitssetElementCountElementsSEL, L"FPDPreflightHitssetElementCountElements"},
	{FPDPreflightHitssetElementSEL, FPDPreflightHitssetElementGetElementContentSEL, L"FPDPreflightHitssetElementGetElementContent"},
	{FPDPreflightHitssetElementSEL, FPDPreflightHitssetElementGetElementSEL, L"FPDPreflightHitssetElementGetElement"},
	{FPDPreflightFixupElementSEL, FPDPreflightFixupElementNewSEL, L"FPDPreflightFixupElementNew"},
	{FPDPreflightFixupElementSEL, FPDPreflightFixupElementDestorySEL, L"FPDPreflightFixupElementDestory"},
	{FPDPreflightFixupElementSEL, FPDPreflightFixupElementCountElementsSEL, L"FPDPreflightFixupElementCountElements"},
	{FPDPreflightFixupElementSEL, FPDPreflightFixupElementGetElementContentSEL, L"FPDPreflightFixupElementGetElementContent"},
	{FPDPreflightFixupElementSEL, FPDPreflightFixupElementGetElementSEL, L"FPDPreflightFixupElementGetElement"},
	{FPDPreflightResultElementSEL, FPDPreflightResultElementNewSEL, L"FPDPreflightResultElementNew"},
	{FPDPreflightResultElementSEL, FPDPreflightResultElementDestorySEL, L"FPDPreflightResultElementDestory"},
	{FPDPreflightResultElementSEL, FPDPreflightResultElementGetHitsElementSEL, L"FPDPreflightResultElementGetHitsElement"},
	{FPDPreflightResultElementSEL, FPDPreflightResultElementGetFixupElementSEL, L"FPDPreflightResultElementGetFixupElement"},
	{FPDPreflightInfoElementSEL, FPDPreflightInfoElementNewSEL, L"FPDPreflightInfoElementNew"},
	{FPDPreflightInfoElementSEL, FPDPreflightInfoElementDestorySEL, L"FPDPreflightInfoElementDestory"},
	{FPDPreflightInfoElementSEL, FPDPreflightInfoElementGetPreflightInfoSEL, L"FPDPreflightInfoElementGetPreflightInfo"},
	{FPDPreflightUIResultSEL, FPDPreflightUIResultGetDocumentElementSEL, L"FPDPreflightUIResultGetDocumentElement"},
	{FPDPreflightUIResultSEL, FPDPreflightUIResultGetPreflightInfoElementSEL, L"FPDPreflightUIResultGetPreflightInfoElement"},
	{FPDPreflightUIResultSEL, FPDPreflightUIResultGetResultElementSEL, L"FPDPreflightUIResultGetResultElement"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaNewSEL, L"FPDPreflightStructProgressCBFunParaNew"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaDestorySEL, L"FPDPreflightStructProgressCBFunParaDestory"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaSetMaxSEL, L"FPDPreflightStructProgressCBFunParaSetMax"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaGetMaxSEL, L"FPDPreflightStructProgressCBFunParaGetMax"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaSetCurrentSEL, L"FPDPreflightStructProgressCBFunParaSetCurrent"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaGetCurrentSEL, L"FPDPreflightStructProgressCBFunParaGetCurrent"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaSetPartSEL, L"FPDPreflightStructProgressCBFunParaSetPart"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaGetPartSEL, L"FPDPreflightStructProgressCBFunParaGetPart"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaSetIDStrSEL, L"FPDPreflightStructProgressCBFunParaSetIDStr"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaGetIDStrSEL, L"FPDPreflightStructProgressCBFunParaGetIDStr"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaSetStateSEL, L"FPDPreflightStructProgressCBFunParaSetState"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaGetStateSEL, L"FPDPreflightStructProgressCBFunParaGetState"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaSetPageSEL, L"FPDPreflightStructProgressCBFunParaSetPage"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaGetPageSEL, L"FPDPreflightStructProgressCBFunParaGetPage"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaSetUserDataSEL, L"FPDPreflightStructProgressCBFunParaSetUserData"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaGetUserDataSEL, L"FPDPreflightStructProgressCBFunParaGetUserData"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaSetRuleTriggerPairSEL, L"FPDPreflightStructProgressCBFunParaSetRuleTriggerPair"},
	{FPDPreflightStructProgressCBFunParaSEL, FPDPreflightStructProgressCBFunParaGetRuleTriggerPairSEL, L"FPDPreflightStructProgressCBFunParaGetRuleTriggerPair"},
	{FPDPreflightStructConvertDataSEL, FPDPreflightStructConvertDataNewSEL, L"FPDPreflightStructConvertDataNew"},
	{FPDPreflightStructConvertDataSEL, FPDPreflightStructConvertDataDestorySEL, L"FPDPreflightStructConvertDataDestory"},
	{FPDPreflightStructConvertDataSEL, FPDPreflightStructConvertDataSetProfileDickeySEL, L"FPDPreflightStructConvertDataSetProfileDickey"},
	{FPDPreflightStructConvertDataSEL, FPDPreflightStructConvertDataGetProfileDickeySEL, L"FPDPreflightStructConvertDataGetProfileDickey"},
	{FPDPreflightStructConvertDataSEL, FPDPreflightStructConvertDataSetICCpathSEL, L"FPDPreflightStructConvertDataSetICCpath"},
	{FPDPreflightStructConvertDataSEL, FPDPreflightStructConvertDataGetICCpathSEL, L"FPDPreflightStructConvertDataGetICCpath"},
	{FPDPreflightStructConvertDataSEL, FPDPreflightStructConvertDataSetApplyFixSEL, L"FPDPreflightStructConvertDataSetApplyFix"},
	{FPDPreflightStructConvertDataSEL, FPDPreflightStructConvertDataGetApplyFixSEL, L"FPDPreflightStructConvertDataGetApplyFix"},
	{FPDPreflightStructConvertPDFXDataSEL, FPDPreflightStructConvertPDFXDataNewSEL, L"FPDPreflightStructConvertPDFXDataNew"},
	{FPDPreflightStructConvertPDFXDataSEL, FPDPreflightStructConvertPDFXDataDestorySEL, L"FPDPreflightStructConvertPDFXDataDestory"},
	{FPDPreflightStructConvertPDFXDataSEL, FPDPreflightStructConvertPDFXDataSetVersionSEL, L"FPDPreflightStructConvertPDFXDataSetVersion"},
	{FPDPreflightStructConvertPDFXDataSEL, FPDPreflightStructConvertPDFXDataGetVersionSEL, L"FPDPreflightStructConvertPDFXDataGetVersion"},
	{FPDPreflightStructConvertPDFXDataSEL, FPDPreflightStructConvertPDFXDataSetConvertDataSEL, L"FPDPreflightStructConvertPDFXDataSetConvertData"},
	{FPDPreflightStructConvertPDFXDataSEL, FPDPreflightStructConvertPDFXDataGetConvertDataSEL, L"FPDPreflightStructConvertPDFXDataGetConvertData"},
	{FPDPreflightStructConvertPDFXDataSEL, FPDPreflightStructConvertPDFXDataSetFxaXRGB2DestMaskSEL, L"FPDPreflightStructConvertPDFXDataSetFxaXRGB2DestMask"},
	{FPDPreflightStructConvertPDFXDataSEL, FPDPreflightStructConvertPDFXDataGetFxaXRGB2DestMaskSEL, L"FPDPreflightStructConvertPDFXDataGetFxaXRGB2DestMask"},
	{FPDPreflightStructConvertPDFXDataSEL, FPDPreflightStructConvertPDFXDataSetFxaXDecCMYKMaskSEL, L"FPDPreflightStructConvertPDFXDataSetFxaXDecCMYKMask"},
	{FPDPreflightStructConvertPDFXDataSEL, FPDPreflightStructConvertPDFXDataGetFxaXDecCMYKMaskSEL, L"FPDPreflightStructConvertPDFXDataGetFxaXDecCMYKMask"},
	{FPDPreflightStructConvertPDFADataSEL, FPDPreflightStructConvertPDFADataNewSEL, L"FPDPreflightStructConvertPDFADataNew"},
	{FPDPreflightStructConvertPDFADataSEL, FPDPreflightStructConvertPDFADataDestorySEL, L"FPDPreflightStructConvertPDFADataDestory"},
	{FPDPreflightStructConvertPDFADataSEL, FPDPreflightStructConvertPDFADataSetVersionSEL, L"FPDPreflightStructConvertPDFADataSetVersion"},
	{FPDPreflightStructConvertPDFADataSEL, FPDPreflightStructConvertPDFADataGetVersionSEL, L"FPDPreflightStructConvertPDFADataGetVersion"},
	{FPDPreflightStructConvertPDFADataSEL, FPDPreflightStructConvertPDFADataSetConvertDataSEL, L"FPDPreflightStructConvertPDFADataSetConvertData"},
	{FPDPreflightStructConvertPDFADataSEL, FPDPreflightStructConvertPDFADataGetConvertDataSEL, L"FPDPreflightStructConvertPDFADataGetConvertData"},
	{FPDPreflightStructConvertPDFADataSEL, FPDPreflightStructConvertPDFADataSetForceconvResolutionSEL, L"FPDPreflightStructConvertPDFADataSetForceconvResolution"},
	{FPDPreflightStructConvertPDFADataSEL, FPDPreflightStructConvertPDFADataGetForceconvResolutionSEL, L"FPDPreflightStructConvertPDFADataGetForceconvResolution"},
	{FPDPreflightStructConvertPDFADataSEL, FPDPreflightStructConvertPDFADataSetFlagsSEL, L"FPDPreflightStructConvertPDFADataSetFlags"},
	{FPDPreflightStructConvertPDFADataSEL, FPDPreflightStructConvertPDFADataGetFlagsSEL, L"FPDPreflightStructConvertPDFADataGetFlags"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterNewSEL, L"FPDPreflightStructParameterNew"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterDestorySEL, L"FPDPreflightStructParameterDestory"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterSetPdfFileSEL, L"FPDPreflightStructParameterSetPdfFile"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterGetPdfFileSEL, L"FPDPreflightStructParameterGetPdfFile"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterSetOutputFileSEL, L"FPDPreflightStructParameterSetOutputFile"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterGetOutputFileSEL, L"FPDPreflightStructParameterGetOutputFile"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterSetBeginPageIdxSEL, L"FPDPreflightStructParameterSetBeginPageIdx"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterGetBeginPageIdxSEL, L"FPDPreflightStructParameterGetBeginPageIdx"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterSetEndPageIdxSEL, L"FPDPreflightStructParameterSetEndPageIdx"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterGetEndPageIdxSEL, L"FPDPreflightStructParameterGetEndPageIdx"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterSetDicKeySEL, L"FPDPreflightStructParameterSetDicKey"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterGetDicKeySEL, L"FPDPreflightStructParameterGetDicKey"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterSetResultSEL, L"FPDPreflightStructParameterSetResult"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterGetResultSEL, L"FPDPreflightStructParameterGetResult"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterSetProgressDataSEL, L"FPDPreflightStructParameterSetProgressData"},
	{FPDPreflightStructParameterSEL, FPDPreflightStructParameterGetProgressDataSEL, L"FPDPreflightStructParameterGetProgressData"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoNewSEL, L"FPDPreflightStructInfoNew"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoDestorySEL, L"FPDPreflightStructInfoDestory"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoSetProductNameSEL, L"FPDPreflightStructInfoSetProductName"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoGetProductNameSEL, L"FPDPreflightStructInfoGetProductName"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoSetProductVersionSEL, L"FPDPreflightStructInfoSetProductVersion"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoGetProductVersionSEL, L"FPDPreflightStructInfoGetProductVersion"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoSetDateSEL, L"FPDPreflightStructInfoSetDate"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoGetDateSEL, L"FPDPreflightStructInfoGetDate"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoSetUserNameSEL, L"FPDPreflightStructInfoSetUserName"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoGetUserNameSEL, L"FPDPreflightStructInfoGetUserName"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoSetComputerNameSEL, L"FPDPreflightStructInfoSetComputerName"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoGetComputerNameSEL, L"FPDPreflightStructInfoGetComputerName"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoSetOSSEL, L"FPDPreflightStructInfoSetOS"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoGetOSSEL, L"FPDPreflightStructInfoGetOS"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoSetDurationSEL, L"FPDPreflightStructInfoSetDuration"},
	{FPDPreflightStructInfoSEL, FPDPreflightStructInfoGetDurationSEL, L"FPDPreflightStructInfoGetDuration"},
	{FPDPreflightStructPlateNameSEL, FPDPreflightStructPlateNameNewSEL, L"FPDPreflightStructPlateNameNew"},
	{FPDPreflightStructPlateNameSEL, FPDPreflightStructPlateNameDestorySEL, L"FPDPreflightStructPlateNameDestory"},
	{FPDPreflightStructPlateNameSEL, FPDPreflightStructPlateNameSetNameSEL, L"FPDPreflightStructPlateNameSetName"},
	{FPDPreflightStructPlateNameSEL, FPDPreflightStructPlateNameGetNameSEL, L"FPDPreflightStructPlateNameGetName"},
	{FPDPreflightStructPlateNameSEL, FPDPreflightStructPlateNameSetInkcovPtctSEL, L"FPDPreflightStructPlateNameSetInkcovPtct"},
	{FPDPreflightStructPlateNameSEL, FPDPreflightStructPlateNameGetInkcovPtctSEL, L"FPDPreflightStructPlateNameGetInkcovPtct"},
	{FPDPreflightStructPlateNameSEL, FPDPreflightStructPlateNameSetInkcovCm2SEL, L"FPDPreflightStructPlateNameSetInkcovCm2"},
	{FPDPreflightStructPlateNameSEL, FPDPreflightStructPlateNameGetInkcovCm2SEL, L"FPDPreflightStructPlateNameGetInkcovCm2"},
	{FPDPreflightStructPlateNameSEL, FPDPreflightStructPlateNameSetInkcovInch2SEL, L"FPDPreflightStructPlateNameSetInkcovInch2"},
	{FPDPreflightStructPlateNameSEL, FPDPreflightStructPlateNameGetInkcovInch2SEL, L"FPDPreflightStructPlateNameGetInkcovInch2"},
	{FPDPreflightStructPlateNamesSEL, FPDPreflightStructPlateNamesNewSEL, L"FPDPreflightStructPlateNamesNew"},
	{FPDPreflightStructPlateNamesSEL, FPDPreflightStructPlateNamesDestorySEL, L"FPDPreflightStructPlateNamesDestory"},
	{FPDPreflightStructPlateNamesSEL, FPDPreflightStructPlateNamesSetInkcovResulutionPPISEL, L"FPDPreflightStructPlateNamesSetInkcovResulutionPPI"},
	{FPDPreflightStructPlateNamesSEL, FPDPreflightStructPlateNamesGetInkcovResulutionPPISEL, L"FPDPreflightStructPlateNamesGetInkcovResulutionPPI"},
	{FPDPreflightStructPlateNamesSEL, FPDPreflightStructPlateNamesSetInkcovPageBoxSEL, L"FPDPreflightStructPlateNamesSetInkcovPageBox"},
	{FPDPreflightStructPlateNamesSEL, FPDPreflightStructPlateNamesGetInkcovPageBoxSEL, L"FPDPreflightStructPlateNamesGetInkcovPageBox"},
	{FPDPreflightStructPlateNamesSEL, FPDPreflightStructPlateNamesSetPlateNamesSEL, L"FPDPreflightStructPlateNamesSetPlateNames"},
	{FPDPreflightStructPlateNamesSEL, FPDPreflightStructPlateNamesGetPlateNamesSEL, L"FPDPreflightStructPlateNamesGetPlateNames"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoNewSEL, L"FPDPreflightStructDocumentInfoNew"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoDestorySEL, L"FPDPreflightStructDocumentInfoDestory"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetFileNameSEL, L"FPDPreflightStructDocumentInfoSetFileName"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetFileNameSEL, L"FPDPreflightStructDocumentInfoGetFileName"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetPathSEL, L"FPDPreflightStructDocumentInfoSetPath"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetPathSEL, L"FPDPreflightStructDocumentInfoGetPath"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetPDFVersionSEL, L"FPDPreflightStructDocumentInfoSetPDFVersion"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetPDFVersionSEL, L"FPDPreflightStructDocumentInfoGetPDFVersion"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetFileSizeSEL, L"FPDPreflightStructDocumentInfoSetFileSize"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetFileSizeSEL, L"FPDPreflightStructDocumentInfoGetFileSize"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetTitleSEL, L"FPDPreflightStructDocumentInfoSetTitle"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetTitleSEL, L"FPDPreflightStructDocumentInfoGetTitle"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetAuthorSEL, L"FPDPreflightStructDocumentInfoSetAuthor"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetAuthorSEL, L"FPDPreflightStructDocumentInfoGetAuthor"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetCreatorSEL, L"FPDPreflightStructDocumentInfoSetCreator"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetCreatorSEL, L"FPDPreflightStructDocumentInfoGetCreator"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetProducerSEL, L"FPDPreflightStructDocumentInfoSetProducer"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetProducerSEL, L"FPDPreflightStructDocumentInfoGetProducer"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetCreatedTimeSEL, L"FPDPreflightStructDocumentInfoSetCreatedTime"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetCreatedTimeSEL, L"FPDPreflightStructDocumentInfoGetCreatedTime"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetCreatedTimeZoneSEL, L"FPDPreflightStructDocumentInfoSetCreatedTimeZone"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetCreatedTimeZoneSEL, L"FPDPreflightStructDocumentInfoGetCreatedTimeZone"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetModifiedTimeSEL, L"FPDPreflightStructDocumentInfoSetModifiedTime"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetModifiedTimeSEL, L"FPDPreflightStructDocumentInfoGetModifiedTime"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetModifiedTimeZoneSEL, L"FPDPreflightStructDocumentInfoSetModifiedTimeZone"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetModifiedTimeZoneSEL, L"FPDPreflightStructDocumentInfoGetModifiedTimeZone"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetKeywordsSEL, L"FPDPreflightStructDocumentInfoSetKeywords"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetKeywordsSEL, L"FPDPreflightStructDocumentInfoGetKeywords"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetSubjectSEL, L"FPDPreflightStructDocumentInfoSetSubject"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetSubjectSEL, L"FPDPreflightStructDocumentInfoGetSubject"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetTrappingSEL, L"FPDPreflightStructDocumentInfoSetTrapping"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetTrappingSEL, L"FPDPreflightStructDocumentInfoGetTrapping"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetPDFXVersionSEL, L"FPDPreflightStructDocumentInfoSetPDFXVersion"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetPDFXVersionSEL, L"FPDPreflightStructDocumentInfoGetPDFXVersion"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetPDFXConformanceSEL, L"FPDPreflightStructDocumentInfoSetPDFXConformance"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetPDFXConformanceSEL, L"FPDPreflightStructDocumentInfoGetPDFXConformance"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoSetPlateNamesSEL, L"FPDPreflightStructDocumentInfoSetPlateNames"},
	{FPDPreflightStructDocumentInfoSEL, FPDPreflightStructDocumentInfoGetPlateNamesSEL, L"FPDPreflightStructDocumentInfoGetPlateNames"},
	{FPDPreflightStructProfileIlluminantSEL, FPDPreflightStructProfileIlluminantNewSEL, L"FPDPreflightStructProfileIlluminantNew"},
	{FPDPreflightStructProfileIlluminantSEL, FPDPreflightStructProfileIlluminantDestorySEL, L"FPDPreflightStructProfileIlluminantDestory"},
	{FPDPreflightStructProfileIlluminantSEL, FPDPreflightStructProfileIlluminantSetIlluminantXSEL, L"FPDPreflightStructProfileIlluminantSetIlluminantX"},
	{FPDPreflightStructProfileIlluminantSEL, FPDPreflightStructProfileIlluminantGetIlluminantXSEL, L"FPDPreflightStructProfileIlluminantGetIlluminantX"},
	{FPDPreflightStructProfileIlluminantSEL, FPDPreflightStructProfileIlluminantSetIlluminantYSEL, L"FPDPreflightStructProfileIlluminantSetIlluminantY"},
	{FPDPreflightStructProfileIlluminantSEL, FPDPreflightStructProfileIlluminantGetIlluminantYSEL, L"FPDPreflightStructProfileIlluminantGetIlluminantY"},
	{FPDPreflightStructProfileIlluminantSEL, FPDPreflightStructProfileIlluminantSetIlluminantZSEL, L"FPDPreflightStructProfileIlluminantSetIlluminantZ"},
	{FPDPreflightStructProfileIlluminantSEL, FPDPreflightStructProfileIlluminantGetIlluminantZSEL, L"FPDPreflightStructProfileIlluminantGetIlluminantZ"},
	{FPDPreflightStructProfileIDHashSEL, FPDPreflightStructProfileIDHashNewSEL, L"FPDPreflightStructProfileIDHashNew"},
	{FPDPreflightStructProfileIDHashSEL, FPDPreflightStructProfileIDHashDestorySEL, L"FPDPreflightStructProfileIDHashDestory"},
	{FPDPreflightStructProfileIDHashSEL, FPDPreflightStructProfileIDHashSetISOSEL, L"FPDPreflightStructProfileIDHashSetISO"},
	{FPDPreflightStructProfileIDHashSEL, FPDPreflightStructProfileIDHashGetISOSEL, L"FPDPreflightStructProfileIDHashGetISO"},
	{FPDPreflightStructProfileIDHashSEL, FPDPreflightStructProfileIDHashSetIDSEL, L"FPDPreflightStructProfileIDHashSetID"},
	{FPDPreflightStructProfileIDHashSEL, FPDPreflightStructProfileIDHashGetIDSEL, L"FPDPreflightStructProfileIDHashGetID"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileNewSEL, L"FPDPreflightStructICCProfileNew"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileDestorySEL, L"FPDPreflightStructICCProfileDestory"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetProfileVersionNumberSEL, L"FPDPreflightStructICCProfileSetProfileVersionNumber"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetProfileVersionNumberSEL, L"FPDPreflightStructICCProfileGetProfileVersionNumber"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetColorManagmentModuleSEL, L"FPDPreflightStructICCProfileSetColorManagmentModule"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetColorManagmentModuleSEL, L"FPDPreflightStructICCProfileGetColorManagmentModule"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetDeviceClassSignatureSEL, L"FPDPreflightStructICCProfileSetDeviceClassSignature"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetDeviceClassSignatureSEL, L"FPDPreflightStructICCProfileGetDeviceClassSignature"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetColorspaceOfDataSEL, L"FPDPreflightStructICCProfileSetColorspaceOfData"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetColorspaceOfDataSEL, L"FPDPreflightStructICCProfileGetColorspaceOfData"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetProfileConnectionSpaceSEL, L"FPDPreflightStructICCProfileSetProfileConnectionSpace"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetProfileConnectionSpaceSEL, L"FPDPreflightStructICCProfileGetProfileConnectionSpace"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetMagicNumberSEL, L"FPDPreflightStructICCProfileSetMagicNumber"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetMagicNumberSEL, L"FPDPreflightStructICCProfileGetMagicNumber"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetPrimaryPlatformSEL, L"FPDPreflightStructICCProfileSetPrimaryPlatform"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetPrimaryPlatformSEL, L"FPDPreflightStructICCProfileGetPrimaryPlatform"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetDeviceManufacturerSEL, L"FPDPreflightStructICCProfileSetDeviceManufacturer"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetDeviceManufacturerSEL, L"FPDPreflightStructICCProfileGetDeviceManufacturer"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetDeviceModelSEL, L"FPDPreflightStructICCProfileSetDeviceModel"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetDeviceModelSEL, L"FPDPreflightStructICCProfileGetDeviceModel"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetProfileCreatorSEL, L"FPDPreflightStructICCProfileSetProfileCreator"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetProfileCreatorSEL, L"FPDPreflightStructICCProfileGetProfileCreator"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetCreationDateSEL, L"FPDPreflightStructICCProfileSetCreationDate"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetCreationDateSEL, L"FPDPreflightStructICCProfileGetCreationDate"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetDefaultRenderingIntentSEL, L"FPDPreflightStructICCProfileSetDefaultRenderingIntent"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetDefaultRenderingIntentSEL, L"FPDPreflightStructICCProfileGetDefaultRenderingIntent"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetProfileIlluminantSEL, L"FPDPreflightStructICCProfileSetProfileIlluminant"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetProfileIlluminantSEL, L"FPDPreflightStructICCProfileGetProfileIlluminant"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetCopyrightSEL, L"FPDPreflightStructICCProfileSetCopyright"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetCopyrightSEL, L"FPDPreflightStructICCProfileGetCopyright"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetPostscriptProductNameSEL, L"FPDPreflightStructICCProfileSetPostscriptProductName"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetPostscriptProductNameSEL, L"FPDPreflightStructICCProfileGetPostscriptProductName"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetColorInformationProvidingAPcsSEL, L"FPDPreflightStructICCProfileSetColorInformationProvidingAPcs"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetColorInformationProvidingAPcsSEL, L"FPDPreflightStructICCProfileGetColorInformationProvidingAPcs"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetProfileDescriptionSEL, L"FPDPreflightStructICCProfileSetProfileDescription"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetProfileDescriptionSEL, L"FPDPreflightStructICCProfileGetProfileDescription"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileSetProfileIDHashSEL, L"FPDPreflightStructICCProfileSetProfileIDHash"},
	{FPDPreflightStructICCProfileSEL, FPDPreflightStructICCProfileGetProfileIDHashSEL, L"FPDPreflightStructICCProfileGetProfileIDHash"},
	{FPDPreflightStructAlternateColorantsSEL, FPDPreflightStructAlternateColorantsNewSEL, L"FPDPreflightStructAlternateColorantsNew"},
	{FPDPreflightStructAlternateColorantsSEL, FPDPreflightStructAlternateColorantsDestorySEL, L"FPDPreflightStructAlternateColorantsDestory"},
	{FPDPreflightStructAlternateColorantsSEL, FPDPreflightStructAlternateColorantsSetNameSEL, L"FPDPreflightStructAlternateColorantsSetName"},
	{FPDPreflightStructAlternateColorantsSEL, FPDPreflightStructAlternateColorantsGetNameSEL, L"FPDPreflightStructAlternateColorantsGetName"},
	{FPDPreflightStructAlternateColorantsSEL, FPDPreflightStructAlternateColorantsSetAltColorspaceElementSEL, L"FPDPreflightStructAlternateColorantsSetAltColorspaceElement"},
	{FPDPreflightStructAlternateColorantsSEL, FPDPreflightStructAlternateColorantsGetAltColorspaceElementSEL, L"FPDPreflightStructAlternateColorantsGetAltColorspaceElement"},
	{FPDPreflightStructAlternateColorantsSEL, FPDPreflightStructAlternateColorantsSetAltValueSEL, L"FPDPreflightStructAlternateColorantsSetAltValue"},
	{FPDPreflightStructAlternateColorantsSEL, FPDPreflightStructAlternateColorantsGetAltValueSEL, L"FPDPreflightStructAlternateColorantsGetAltValue"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceNewSEL, L"FPDPreflightStructColorspaceNew"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceDestorySEL, L"FPDPreflightStructColorspaceDestory"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceSetIDSEL, L"FPDPreflightStructColorspaceSetID"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceGetIDSEL, L"FPDPreflightStructColorspaceGetID"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceSetTypeSEL, L"FPDPreflightStructColorspaceSetType"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceGetTypeSEL, L"FPDPreflightStructColorspaceGetType"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceSetChannelsSEL, L"FPDPreflightStructColorspaceSetChannels"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceGetChannelsSEL, L"FPDPreflightStructColorspaceGetChannels"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceSetBaseColorspaceSEL, L"FPDPreflightStructColorspaceSetBaseColorspace"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceGetBaseColorspaceSEL, L"FPDPreflightStructColorspaceGetBaseColorspace"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceSetNameSEL, L"FPDPreflightStructColorspaceSetName"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceGetNameSEL, L"FPDPreflightStructColorspaceGetName"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceSetIccProfileSEL, L"FPDPreflightStructColorspaceSetIccProfile"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceGetIccProfileSEL, L"FPDPreflightStructColorspaceGetIccProfile"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceSetAltColorspaceElementSEL, L"FPDPreflightStructColorspaceSetAltColorspaceElement"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceGetAltColorspaceElementSEL, L"FPDPreflightStructColorspaceGetAltColorspaceElement"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceSetAltColorspacetypeSEL, L"FPDPreflightStructColorspaceSetAltColorspacetype"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceGetAltColorspacetypeSEL, L"FPDPreflightStructColorspaceGetAltColorspacetype"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceSetAltValueSEL, L"FPDPreflightStructColorspaceSetAltValue"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceGetAltValueSEL, L"FPDPreflightStructColorspaceGetAltValue"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceSetAlternateColorantsSEL, L"FPDPreflightStructColorspaceSetAlternateColorants"},
	{FPDPreflightStructColorspaceSEL, FPDPreflightStructColorspaceGetAlternateColorantsSEL, L"FPDPreflightStructColorspaceGetAlternateColorants"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontNewSEL, L"FPDPreflightStructFontNew"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontDestorySEL, L"FPDPreflightStructFontDestory"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontSetIDSEL, L"FPDPreflightStructFontSetID"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontGetIDSEL, L"FPDPreflightStructFontGetID"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontSetTypeSEL, L"FPDPreflightStructFontSetType"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontGetTypeSEL, L"FPDPreflightStructFontGetType"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontSetEmbededSEL, L"FPDPreflightStructFontSetEmbeded"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontGetEmbededSEL, L"FPDPreflightStructFontGetEmbeded"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontSetSubSetSEL, L"FPDPreflightStructFontSetSubSet"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontGetSubSetSEL, L"FPDPreflightStructFontGetSubSet"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontSetHasUnicodeCmapSEL, L"FPDPreflightStructFontSetHasUnicodeCmap"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontGetHasUnicodeCmapSEL, L"FPDPreflightStructFontGetHasUnicodeCmap"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontSetNameSEL, L"FPDPreflightStructFontSetName"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontGetNameSEL, L"FPDPreflightStructFontGetName"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontSetEncodingSEL, L"FPDPreflightStructFontSetEncoding"},
	{FPDPreflightStructFontSEL, FPDPreflightStructFontGetEncodingSEL, L"FPDPreflightStructFontGetEncoding"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentNewSEL, L"FPDPreflightStructOutputIntentNew"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentDestorySEL, L"FPDPreflightStructOutputIntentDestory"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentSetIDSEL, L"FPDPreflightStructOutputIntentSetID"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentGetIDSEL, L"FPDPreflightStructOutputIntentGetID"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentSetOutputConditionIdentifierSEL, L"FPDPreflightStructOutputIntentSetOutputConditionIdentifier"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentGetOutputConditionIdentifierSEL, L"FPDPreflightStructOutputIntentGetOutputConditionIdentifier"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentSetSubtypeSEL, L"FPDPreflightStructOutputIntentSetSubtype"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentGetSubtypeSEL, L"FPDPreflightStructOutputIntentGetSubtype"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentSetRegistryNameSEL, L"FPDPreflightStructOutputIntentSetRegistryName"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentGetRegistryNameSEL, L"FPDPreflightStructOutputIntentGetRegistryName"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentSetOutputConditionSEL, L"FPDPreflightStructOutputIntentSetOutputCondition"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentGetOutputConditionSEL, L"FPDPreflightStructOutputIntentGetOutputCondition"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentSetInfoSEL, L"FPDPreflightStructOutputIntentSetInfo"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentGetInfoSEL, L"FPDPreflightStructOutputIntentGetInfo"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentSetPreflightHashSEL, L"FPDPreflightStructOutputIntentSetPreflightHash"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentGetPreflightHashSEL, L"FPDPreflightStructOutputIntentGetPreflightHash"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentSetOutputProfilenameSEL, L"FPDPreflightStructOutputIntentSetOutputProfilename"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentGetOutputProfilenameSEL, L"FPDPreflightStructOutputIntentGetOutputProfilename"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentSetIccprofileSEL, L"FPDPreflightStructOutputIntentSetIccprofile"},
	{FPDPreflightStructOutputIntentSEL, FPDPreflightStructOutputIntentGetIccprofileSEL, L"FPDPreflightStructOutputIntentGetIccprofile"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerNewSEL, L"FPDPreflightStructLayerNew"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerDestorySEL, L"FPDPreflightStructLayerDestory"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerSetIDSEL, L"FPDPreflightStructLayerSetID"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerGetIDSEL, L"FPDPreflightStructLayerGetID"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerSetTypeSEL, L"FPDPreflightStructLayerSetType"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerGetTypeSEL, L"FPDPreflightStructLayerGetType"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerSetNameSEL, L"FPDPreflightStructLayerSetName"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerGetNameSEL, L"FPDPreflightStructLayerGetName"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerSetIntentSEL, L"FPDPreflightStructLayerSetIntent"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerGetIntentSEL, L"FPDPreflightStructLayerGetIntent"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerSetDefaultStateSEL, L"FPDPreflightStructLayerSetDefaultState"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerGetDefaultStateSEL, L"FPDPreflightStructLayerGetDefaultState"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerSetGTSProcStepsGroupSEL, L"FPDPreflightStructLayerSetGTSProcStepsGroup"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerGetGTSProcStepsGroupSEL, L"FPDPreflightStructLayerGetGTSProcStepsGroup"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerSetGTSProcStepsTypeSEL, L"FPDPreflightStructLayerSetGTSProcStepsType"},
	{FPDPreflightStructLayerSEL, FPDPreflightStructLayerGetGTSProcStepsTypeSEL, L"FPDPreflightStructLayerGetGTSProcStepsType"},
	{FPDPreflightStructEmbeddedFileSEL, FPDPreflightStructEmbeddedFileNewSEL, L"FPDPreflightStructEmbeddedFileNew"},
	{FPDPreflightStructEmbeddedFileSEL, FPDPreflightStructEmbeddedFileDestorySEL, L"FPDPreflightStructEmbeddedFileDestory"},
	{FPDPreflightStructEmbeddedFileSEL, FPDPreflightStructEmbeddedFileSetIDSEL, L"FPDPreflightStructEmbeddedFileSetID"},
	{FPDPreflightStructEmbeddedFileSEL, FPDPreflightStructEmbeddedFileGetIDSEL, L"FPDPreflightStructEmbeddedFileGetID"},
	{FPDPreflightStructEmbeddedFileSEL, FPDPreflightStructEmbeddedFileSetFilenameSEL, L"FPDPreflightStructEmbeddedFileSetFilename"},
	{FPDPreflightStructEmbeddedFileSEL, FPDPreflightStructEmbeddedFileGetFilenameSEL, L"FPDPreflightStructEmbeddedFileGetFilename"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectNewSEL, L"FPDPreflightStructFormXObjectNew"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectDestorySEL, L"FPDPreflightStructFormXObjectDestory"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectSetIDSEL, L"FPDPreflightStructFormXObjectSetID"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectGetIDSEL, L"FPDPreflightStructFormXObjectGetID"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectSetBoundingBoxPTSEL, L"FPDPreflightStructFormXObjectSetBoundingBoxPT"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectGetBoundingBoxPTSEL, L"FPDPreflightStructFormXObjectGetBoundingBoxPT"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectSetTransformationMatrixSEL, L"FPDPreflightStructFormXObjectSetTransformationMatrix"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectGetTransformationMatrixSEL, L"FPDPreflightStructFormXObjectGetTransformationMatrix"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectSetExtUniqueIDSEL, L"FPDPreflightStructFormXObjectSetExtUniqueID"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectGetExtUniqueIDSEL, L"FPDPreflightStructFormXObjectGetExtUniqueID"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectSetFormPInfoSEL, L"FPDPreflightStructFormXObjectSetFormPInfo"},
	{FPDPreflightStructFormXObjectSEL, FPDPreflightStructFormXObjectGetFormPInfoSEL, L"FPDPreflightStructFormXObjectGetFormPInfo"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeNewSEL, L"FPDPreflightStructShadeNew"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeDestorySEL, L"FPDPreflightStructShadeDestory"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeSetIDSEL, L"FPDPreflightStructShadeSetID"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeGetIDSEL, L"FPDPreflightStructShadeGetID"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeSetTypeSEL, L"FPDPreflightStructShadeSetType"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeGetTypeSEL, L"FPDPreflightStructShadeGetType"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeSetPreventAliasingArtifactsSEL, L"FPDPreflightStructShadeSetPreventAliasingArtifacts"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeGetPreventAliasingArtifactsSEL, L"FPDPreflightStructShadeGetPreventAliasingArtifacts"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeSetColorspaceSEL, L"FPDPreflightStructShadeSetColorspace"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeGetColorspaceSEL, L"FPDPreflightStructShadeGetColorspace"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeSetBitsPerCoordinateSEL, L"FPDPreflightStructShadeSetBitsPerCoordinate"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeGetBitsPerCoordinateSEL, L"FPDPreflightStructShadeGetBitsPerCoordinate"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeSetBitsPerComponentSEL, L"FPDPreflightStructShadeSetBitsPerComponent"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeGetBitsPerComponentSEL, L"FPDPreflightStructShadeGetBitsPerComponent"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeSetBitsPerFlagSEL, L"FPDPreflightStructShadeSetBitsPerFlag"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeGetBitsPerFlagSEL, L"FPDPreflightStructShadeGetBitsPerFlag"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeSetVerticesPerRowSEL, L"FPDPreflightStructShadeSetVerticesPerRow"},
	{FPDPreflightStructShadeSEL, FPDPreflightStructShadeGetVerticesPerRowSEL, L"FPDPreflightStructShadeGetVerticesPerRow"},
	{FPDPreflightStructPatternSEL, FPDPreflightStructPatternNewSEL, L"FPDPreflightStructPatternNew"},
	{FPDPreflightStructPatternSEL, FPDPreflightStructPatternDestorySEL, L"FPDPreflightStructPatternDestory"},
	{FPDPreflightStructPatternSEL, FPDPreflightStructPatternSetTypeSEL, L"FPDPreflightStructPatternSetType"},
	{FPDPreflightStructPatternSEL, FPDPreflightStructPatternGetTypeSEL, L"FPDPreflightStructPatternGetType"},
	{FPDPreflightStructPatternSEL, FPDPreflightStructPatternSetIDSEL, L"FPDPreflightStructPatternSetID"},
	{FPDPreflightStructPatternSEL, FPDPreflightStructPatternGetIDSEL, L"FPDPreflightStructPatternGetID"},
	{FPDPreflightStructPatternSEL, FPDPreflightStructPatternSetShadeElementSEL, L"FPDPreflightStructPatternSetShadeElement"},
	{FPDPreflightStructPatternSEL, FPDPreflightStructPatternGetShadeElementSEL, L"FPDPreflightStructPatternGetShadeElement"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotNewSEL, L"FPDPreflightStructAnnotNew"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotDestorySEL, L"FPDPreflightStructAnnotDestory"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetIDSEL, L"FPDPreflightStructAnnotSetID"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetIDSEL, L"FPDPreflightStructAnnotGetID"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetTypeSEL, L"FPDPreflightStructAnnotSetType"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetTypeSEL, L"FPDPreflightStructAnnotGetType"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetNameSEL, L"FPDPreflightStructAnnotSetName"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetNameSEL, L"FPDPreflightStructAnnotGetName"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetStateSEL, L"FPDPreflightStructAnnotSetState"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetStateSEL, L"FPDPreflightStructAnnotGetState"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetTitleSEL, L"FPDPreflightStructAnnotSetTitle"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetTitleSEL, L"FPDPreflightStructAnnotGetTitle"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetSubjectSEL, L"FPDPreflightStructAnnotSetSubject"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetSubjectSEL, L"FPDPreflightStructAnnotGetSubject"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetIntentSEL, L"FPDPreflightStructAnnotSetIntent"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetIntentSEL, L"FPDPreflightStructAnnotGetIntent"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetFlagsSEL, L"FPDPreflightStructAnnotSetFlags"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetFlagsSEL, L"FPDPreflightStructAnnotGetFlags"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetFilepathSEL, L"FPDPreflightStructAnnotSetFilepath"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetFilepathSEL, L"FPDPreflightStructAnnotGetFilepath"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetPageElementSEL, L"FPDPreflightStructAnnotSetPageElement"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetPageElementSEL, L"FPDPreflightStructAnnotGetPageElement"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetRectSEL, L"FPDPreflightStructAnnotSetRect"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetRectSEL, L"FPDPreflightStructAnnotGetRect"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetContentSEL, L"FPDPreflightStructAnnotSetContent"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetContentSEL, L"FPDPreflightStructAnnotGetContent"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetCreationdateSEL, L"FPDPreflightStructAnnotSetCreationdate"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetCreationdateSEL, L"FPDPreflightStructAnnotGetCreationdate"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetModificationdateSEL, L"FPDPreflightStructAnnotSetModificationdate"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetModificationdateSEL, L"FPDPreflightStructAnnotGetModificationdate"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetActionTypeSEL, L"FPDPreflightStructAnnotSetActionType"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetActionTypeSEL, L"FPDPreflightStructAnnotGetActionType"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotSetOptionalcontentidsSEL, L"FPDPreflightStructAnnotSetOptionalcontentids"},
	{FPDPreflightStructAnnotSEL, FPDPreflightStructAnnotGetOptionalcontentidsSEL, L"FPDPreflightStructAnnotGetOptionalcontentids"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageNewSEL, L"FPDPreflightStructPageNew"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageDestorySEL, L"FPDPreflightStructPageDestory"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetIDSEL, L"FPDPreflightStructPageSetID"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetIDSEL, L"FPDPreflightStructPageGetID"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetNRSEL, L"FPDPreflightStructPageSetNR"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetNRSEL, L"FPDPreflightStructPageGetNR"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetPagelabelSEL, L"FPDPreflightStructPageSetPagelabel"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetPagelabelSEL, L"FPDPreflightStructPageGetPagelabel"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetMediaboxSEL, L"FPDPreflightStructPageSetMediabox"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetMediaboxSEL, L"FPDPreflightStructPageGetMediabox"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetCropboxSEL, L"FPDPreflightStructPageSetCropbox"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetCropboxSEL, L"FPDPreflightStructPageGetCropbox"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetTrimboxSEL, L"FPDPreflightStructPageSetTrimbox"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetTrimboxSEL, L"FPDPreflightStructPageGetTrimbox"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetBleedboxSEL, L"FPDPreflightStructPageSetBleedbox"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetBleedboxSEL, L"FPDPreflightStructPageGetBleedbox"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetArtboxSEL, L"FPDPreflightStructPageSetArtbox"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetArtboxSEL, L"FPDPreflightStructPageGetArtbox"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetRotateSEL, L"FPDPreflightStructPageSetRotate"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetRotateSEL, L"FPDPreflightStructPageGetRotate"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetUserunitSEL, L"FPDPreflightStructPageSetUserunit"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetUserunitSEL, L"FPDPreflightStructPageGetUserunit"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetPlatesSEL, L"FPDPreflightStructPageSetPlates"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetPlatesSEL, L"FPDPreflightStructPageGetPlates"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetPlatesElementSEL, L"FPDPreflightStructPageSetPlatesElement"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetPlatesElementSEL, L"FPDPreflightStructPageGetPlatesElement"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageSetAnnotsSEL, L"FPDPreflightStructPageSetAnnots"},
	{FPDPreflightStructPageSEL, FPDPreflightStructPageGetAnnotsSEL, L"FPDPreflightStructPageGetAnnots"},
	{FPDPreflightStructTriggerItemSEL, FPDPreflightStructTriggerItemNewSEL, L"FPDPreflightStructTriggerItemNew"},
	{FPDPreflightStructTriggerItemSEL, FPDPreflightStructTriggerItemDestorySEL, L"FPDPreflightStructTriggerItemDestory"},
	{FPDPreflightStructTriggerItemSEL, FPDPreflightStructTriggerItemSetConditonKeySEL, L"FPDPreflightStructTriggerItemSetConditonKey"},
	{FPDPreflightStructTriggerItemSEL, FPDPreflightStructTriggerItemGetConditonKeySEL, L"FPDPreflightStructTriggerItemGetConditonKey"},
	{FPDPreflightStructTriggerItemSEL, FPDPreflightStructTriggerItemSetConditionResultSEL, L"FPDPreflightStructTriggerItemSetConditionResult"},
	{FPDPreflightStructTriggerItemSEL, FPDPreflightStructTriggerItemGetConditionResultSEL, L"FPDPreflightStructTriggerItemGetConditionResult"},
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
	{FPD3DBuiltinSEL, FPD3DBuiltinCreateTempFileInfoSEL, L"FPD3DBuiltinCreateTempFileInfo"},
	{FPD3DBuiltinSEL, FPD3DBuiltinDeleteTempFileInfoSEL, L"FPD3DBuiltinDeleteTempFileInfo"},
	{FPD3DBuiltinSEL, FPD3DBuiltinGetFilePathSEL, L"FPD3DBuiltinGetFilePath"},
	{FPD3DBuiltinSEL, FPD3DBuiltinSetFilePathSEL, L"FPD3DBuiltinSetFilePath"},
	{FPD3DBuiltinSEL, FPD3DBuiltinGetReservedSEL, L"FPD3DBuiltinGetReserved"},
	{FPD3DBuiltinSEL, FPD3DBuiltinSetReservedSEL, L"FPD3DBuiltinSetReserved"},
	{FPD3DBuiltinSEL, FPD3DBuiltinU3DLoaderSEL, L"FPD3DBuiltinU3DLoader"},
	{FPD3DBuiltinSEL, FPD3DBuiltinPRCLoaderSEL, L"FPD3DBuiltinPRCLoader"},
	{FPD3DBuiltinSEL, FPD3DBuiltinU3DorPRCLoaderSEL, L"FPD3DBuiltinU3DorPRCLoader"},
	{FPD3DBuiltinSEL, FPD3DBuiltinSetTempFileGenerationRuleSEL, L"FPD3DBuiltinSetTempFileGenerationRule"},
	{FPD3DBuiltinSEL, FPD3DBuiltinSetTempFileCallbackSEL, L"FPD3DBuiltinSetTempFileCallback"},
	{FPD3DBuiltinSEL, FPD3DBuiltinReleaseTempFileCallbackSEL, L"FPD3DBuiltinReleaseTempFileCallback"},
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
	{FPDConvertTaggedPDFHandlerSEL, FPDConvertTaggedPDFHandlerNewHandlerSEL, L"FPDConvertTaggedPDFHandlerNewHandler"},
	{FPDConvertTaggedPDFHandlerSEL, FPDConvertTaggedPDFHandlerDestroyHandlerSEL, L"FPDConvertTaggedPDFHandlerDestroyHandler"},
	{FPDDestructObjectSEL, FPDDestructObjectFormRecognitionCreateSEL, L"FPDDestructObjectFormRecognitionCreate"},
	{FPDDestructObjectSEL, FPDDestructObjectRecognitionCreateFromSEL, L"FPDDestructObjectRecognitionCreateFrom"},
	{FPDDestructObjectSEL, FPDDestructObjectFormRecognitionCreate2SEL, L"FPDDestructObjectFormRecognitionCreate2"},
	{FPDDestructObjectSEL, FPDDestructObjectCreateFormRecHandlerSEL, L"FPDDestructObjectCreateFormRecHandler"},
	{FPDDestructObjectSEL, FPDDestructObjectDeleteFormRecHandlerSEL, L"FPDDestructObjectDeleteFormRecHandler"},
	{FPDDestructObjectSEL, FPDDestructObjectCreateFormRecOptionSEL, L"FPDDestructObjectCreateFormRecOption"},
	{FPDDestructObjectSEL, FPDDestructObjectDeleteFormRecOptionSEL, L"FPDDestructObjectDeleteFormRecOption"},
	{FPDDestructObjectSEL, FPDDestructObjectGetRecCallbackSEL, L"FPDDestructObjectGetRecCallback"},
	{FPDDestructObjectSEL, FPDDestructObjectSetRecCallbackSEL, L"FPDDestructObjectSetRecCallback"},
	{FPDDestructObjectSEL, FPDDestructObjectGetOutputPathSEL, L"FPDDestructObjectGetOutputPath"},
	{FPDDestructObjectSEL, FPDDestructObjectSetOutputPathSEL, L"FPDDestructObjectSetOutputPath"},
	{FPDDestructObjectSEL, FPDDestructObjectGetFileStreamSEL, L"FPDDestructObjectGetFileStream"},
	{FPDDestructObjectSEL, FPDDestructObjectSetFileStreamSEL, L"FPDDestructObjectSetFileStream"},
	{FPDConverterOptionsSEL, FPDConverterOptionsNewConverterOptionsSEL, L"FPDConverterOptionsNewConverterOptions"},
	{FPDConverterOptionsSEL, FPDConverterOptionsDestroyConverterOptionsSEL, L"FPDConverterOptionsDestroyConverterOptions"},
	{FPDConverterOptionsSEL, FPDConverterOptionsGetImageDPPSEL, L"FPDConverterOptionsGetImageDPP"},
	{FPDConverterOptionsSEL, FPDConverterOptionsSetImageDPPSEL, L"FPDConverterOptionsSetImageDPP"},
	{FPDConverterOptionsSEL, FPDConverterOptionsGetStopWhenTimeoutSEL, L"FPDConverterOptionsGetStopWhenTimeout"},
	{FPDConverterOptionsSEL, FPDConverterOptionsSetStopWhenTimeoutSEL, L"FPDConverterOptionsSetStopWhenTimeout"},
	{FPDConverterOptionsSEL, FPDConverterOptionsGetOCContextSEL, L"FPDConverterOptionsGetOCContext"},
	{FPDConverterOptionsSEL, FPDConverterOptionsSetOCContextSEL, L"FPDConverterOptionsSetOCContext"},
	{FPDConverterOptionsSEL, FPDConverterOptionsGetLRVersionSEL, L"FPDConverterOptionsGetLRVersion"},
	{FPDConverterOptionsSEL, FPDConverterOptionsSetLRVersionSEL, L"FPDConverterOptionsSetLRVersion"},
	{FPDConverterHandlerSEL, FPDConverterHandlerNewConvertHandlerSEL, L"FPDConverterHandlerNewConvertHandler"},
	{FPDConverterHandlerSEL, FPDConverterHandlerDestroyConvertHandlerSEL, L"FPDConverterHandlerDestroyConvertHandler"},
	{FPDConverterHandlerSEL, FPDConverterHandlerNeedToPauseNowSEL, L"FPDConverterHandlerNeedToPauseNow"},
	{FPDConverterHandlerSEL, FPDConverterHandlerPreparePageSEL, L"FPDConverterHandlerPreparePage"},
	{FPDConverterHandlerSEL, FPDConverterHandlerConfigureAnalysisOptionsSEL, L"FPDConverterHandlerConfigureAnalysisOptions"},
	{FPDConverterHandlerSEL, FPDConverterHandlerUpdateProgressSEL, L"FPDConverterHandlerUpdateProgress"},
	{FPDConverterSEL, FPDConverterCreateSEL, L"FPDConverterCreate"},
	{FPDConverterSEL, FPDConverterDestroyConverterSEL, L"FPDConverterDestroyConverter"},
	{FPDConverterSEL, FPDConverterStartSEL, L"FPDConverterStart"},
	{FPDConverterSEL, FPDConverterStart2SEL, L"FPDConverterStart2"},
	{FPDConverterSEL, FPDConverterStart3SEL, L"FPDConverterStart3"},
	{FPDConverterSEL, FPDConverterContinueSEL, L"FPDConverterContinue"},
// fpd_convertImpl.h end

// In file fpd_docImpl.h
	{FPDStructTreeSEL, FPDStructTreeLoadDocSEL, L"FPDStructTreeLoadDoc"},
	{FPDStructTreeSEL, FPDStructTreeCountKidsSEL, L"FPDStructTreeCountKids"},
	{FPDStructTreeSEL, FPDStructTreeGetKidSEL, L"FPDStructTreeGetKid"},
	{FPDStructTreeSEL, FPDStructTreeGetMCRSEL, L"FPDStructTreeGetMCR"},
	{FPDStructTreeSEL, FPDStructTreeGetMCR2SEL, L"FPDStructTreeGetMCR2"},
	{FPDStructTreeSEL, FPDStructTreeGetOBJRSEL, L"FPDStructTreeGetOBJR"},
	{FPDStructTreeSEL, FPDStructTreeGetOBJR2SEL, L"FPDStructTreeGetOBJR2"},
	{FPDStructTreeSEL, FPDStructTreeGetOBJR3SEL, L"FPDStructTreeGetOBJR3"},
	{FPDStructTreeSEL, FPDStructTreeGetOBJR4SEL, L"FPDStructTreeGetOBJR4"},
	{FPDStructTreeSEL, FPDStructTreeDetachFromTreeSEL, L"FPDStructTreeDetachFromTree"},
	{FPDStructTreeSEL, FPDStructTreeReleaseStructTreeSEL, L"FPDStructTreeReleaseStructTree"},
	{FPDStructTreeSEL, FPDStructTreeGetRootDictSEL, L"FPDStructTreeGetRootDict"},
	{FPDStructTreeSEL, FPDStructTreeGetStructElementSEL, L"FPDStructTreeGetStructElement"},
	{FPDStructTreeSEL, FPDStructTreeCreateStructElementSEL, L"FPDStructTreeCreateStructElement"},
	{FPDStructTreeSEL, FPDStructTreeIsConnectedWithRootSEL, L"FPDStructTreeIsConnectedWithRoot"},
	{FPDStructTreeSEL, FPDStructTreeAttachAsTreeKidSEL, L"FPDStructTreeAttachAsTreeKid"},
	{FPDStructTreeSEL, FPDStructTreeAttachAsElementKidSEL, L"FPDStructTreeAttachAsElementKid"},
	{FPDStructTreeSEL, FPDStructTreeGetDocumentSEL, L"FPDStructTreeGetDocument"},
	{FPDStructTreeSEL, FPDStructTreeGetMCRWithMCIDSEL, L"FPDStructTreeGetMCRWithMCID"},
	{FPDStructTreeSEL, FPDStructTreeGetMCRWithMCID2SEL, L"FPDStructTreeGetMCRWithMCID2"},
	{FPDStructTreeSEL, FPDStructTreeTraverseForPageSEL, L"FPDStructTreeTraverseForPage"},
	{FPDStructTreeSEL, FPDStructTreeGetElementByIDSEL, L"FPDStructTreeGetElementByID"},
	{FPDStructTreeSEL, FPDStructTreeGetDefaultStructNamespaceSEL, L"FPDStructTreeGetDefaultStructNamespace"},
	{FPDStructTreeSEL, FPDStructTreeLoadDoc2SEL, L"FPDStructTreeLoadDoc2"},
	{FPDStructElementSEL, FPDStructElementGetTypeSEL, L"FPDStructElementGetType"},
	{FPDStructElementSEL, FPDStructElementGetMappedRoleSEL, L"FPDStructElementGetMappedRole"},
	{FPDStructElementSEL, FPDStructElementCountKidsSEL, L"FPDStructElementCountKids"},
	{FPDStructElementSEL, FPDStructElementGetKidSEL, L"FPDStructElementGetKid"},
	{FPDStructElementSEL, FPDStructElementGetRoleSEL, L"FPDStructElementGetRole"},
	{FPDStructElementSEL, FPDStructElementGetInfoSEL, L"FPDStructElementGetInfo"},
	{FPDStructElementSEL, FPDStructElementGetIDSEL, L"FPDStructElementGetID"},
	{FPDStructElementSEL, FPDStructElementSetInfoSEL, L"FPDStructElementSetInfo"},
	{FPDStructElementSEL, FPDStructElementSetRoleSEL, L"FPDStructElementSetRole"},
	{FPDStructElementSEL, FPDStructElementSetIDSEL, L"FPDStructElementSetID"},
	{FPDStructElementSEL, FPDStructElementHasInfoSEL, L"FPDStructElementHasInfo"},
	{FPDStructElementSEL, FPDStructElementGetInfoRawSEL, L"FPDStructElementGetInfoRaw"},
	{FPDStructElementSEL, FPDStructElementGetAttrSEL, L"FPDStructElementGetAttr"},
	{FPDStructElementSEL, FPDStructElementSetAttrSEL, L"FPDStructElementSetAttr"},
	{FPDStructElementSEL, FPDStructElementGetNSSEL, L"FPDStructElementGetNS"},
	{FPDStructElementSEL, FPDStructElementSetNSSEL, L"FPDStructElementSetNS"},
	{FPDStructElementSEL, FPDStructElementGetMappedRoleAndNSSEL, L"FPDStructElementGetMappedRoleAndNS"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityAsStructElemSEL, L"FPDStructTreeEntityAsStructElem"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityGetPageSEL, L"FPDStructTreeEntityGetPage"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityGetTypeSEL, L"FPDStructTreeEntityGetType"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityAsMCRSEL, L"FPDStructTreeEntityAsMCR"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityAsOBJRSEL, L"FPDStructTreeEntityAsOBJR"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityGetObjectFSEL, L"FPDStructTreeEntityGetObjectF"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityCastFromStructElementSEL, L"FPDStructTreeEntityCastFromStructElement"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityCastFromMarkContentSEL, L"FPDStructTreeEntityCastFromMarkContent"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityCastFromObjectRefSEL, L"FPDStructTreeEntityCastFromObjectRef"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityGetParentSEL, L"FPDStructTreeEntityGetParent"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityGetTreeSEL, L"FPDStructTreeEntityGetTree"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntityCastToStructElementSEL, L"FPDStructTreeEntityCastToStructElement"},
	{FPDStructTreeEntitySEL, FPDStructTreeEntitySetPageSEL, L"FPDStructTreeEntitySetPage"},
	{FPDMarkContentReferenceSEL, FPDMarkContentReferenceGetTypeSEL, L"FPDMarkContentReferenceGetType"},
	{FPDMarkContentReferenceSEL, FPDMarkContentReferenceGetContentStreamSEL, L"FPDMarkContentReferenceGetContentStream"},
	{FPDMarkContentReferenceSEL, FPDMarkContentReferenceGetOwnerSEL, L"FPDMarkContentReferenceGetOwner"},
	{FPDMarkContentReferenceSEL, FPDMarkContentReferenceGetMCIDSEL, L"FPDMarkContentReferenceGetMCID"},
	{FPDObjectReferenceSEL, FPDObjectReferenceGetTypeSEL, L"FPDObjectReferenceGetType"},
	{FPDObjectReferenceSEL, FPDObjectReferenceGetTargetSEL, L"FPDObjectReferenceGetTarget"},
	{FPDObjectReferenceSEL, FPDObjectReferenceGetTargetTypeSEL, L"FPDObjectReferenceGetTargetType"},
	{FPDObjectReferenceSEL, FPDObjectReferenceGetTargetImageDictSEL, L"FPDObjectReferenceGetTargetImageDict"},
	{FPDObjectReferenceSEL, FPDObjectReferenceGetTargetFormDictSEL, L"FPDObjectReferenceGetTargetFormDict"},
	{FPDObjectReferenceSEL, FPDObjectReferenceGetTargetAnnotDictSEL, L"FPDObjectReferenceGetTargetAnnotDict"},
	{FPDMarkInfoSEL, FPDMarkInfoCreateMarkInfoSEL, L"FPDMarkInfoCreateMarkInfo"},
	{FPDMarkInfoSEL, FPDMarkInfoDeleteMarkInfoSEL, L"FPDMarkInfoDeleteMarkInfo"},
	{FPDMarkInfoSEL, FPDMarkInfoGetMarkedSEL, L"FPDMarkInfoGetMarked"},
	{FPDMarkInfoSEL, FPDMarkInfoGetUserPropertiesSEL, L"FPDMarkInfoGetUserProperties"},
	{FPDMarkInfoSEL, FPDMarkInfoGetSuspectsSEL, L"FPDMarkInfoGetSuspects"},
	{FPDMarkInfoSEL, FPDMarkInfoSetMarkedSEL, L"FPDMarkInfoSetMarked"},
	{FPDMarkInfoSEL, FPDMarkInfoSetUserPropertiesSEL, L"FPDMarkInfoSetUserProperties"},
	{FPDMarkInfoSEL, FPDMarkInfoSetSuspectsSEL, L"FPDMarkInfoSetSuspects"},
	{FPDPageTemplateSEL, FPDPageTemplateCreatePageTemplateSEL, L"FPDPageTemplateCreatePageTemplate"},
	{FPDPageTemplateSEL, FPDPageTemplateDestroyFPDPageTemplateSEL, L"FPDPageTemplateDestroyFPDPageTemplate"},
	{FPDPageTemplateSEL, FPDPageTemplateLoadTemplateDatasSEL, L"FPDPageTemplateLoadTemplateDatas"},
	{FPDPageTemplateSEL, FPDPageTemplateGetTemplateCountSEL, L"FPDPageTemplateGetTemplateCount"},
	{FPDPageTemplateSEL, FPDPageTemplateGetTemplateNameSEL, L"FPDPageTemplateGetTemplateName"},
	{FPDPageTemplateSEL, FPDPageTemplateAddTemplateSEL, L"FPDPageTemplateAddTemplate"},
	{FPDPageTemplateSEL, FPDPageTemplateCheckExistForTempNameSEL, L"FPDPageTemplateCheckExistForTempName"},
	{FPDPageTemplateSEL, FPDPageTemplateCheckExistForDictSEL, L"FPDPageTemplateCheckExistForDict"},
	{FPDPageTemplateSEL, FPDPageTemplateRenameTemplateSEL, L"FPDPageTemplateRenameTemplate"},
	{FPDPageTemplateSEL, FPDPageTemplateDeleteTemplateSEL, L"FPDPageTemplateDeleteTemplate"},
	{FPDPageTemplateSEL, FPDPageTemplateGetTemplateVisibleSEL, L"FPDPageTemplateGetTemplateVisible"},
	{FPDPageTemplateSEL, FPDPageTemplateSetTemplateVisibleSEL, L"FPDPageTemplateSetTemplateVisible"},
	{FPDPageTemplateSEL, FPDPageTemplateGetPageIndexSEL, L"FPDPageTemplateGetPageIndex"},
	{FPDPageTemplateSEL, FPDPageTemplateGetTemplateObjectSEL, L"FPDPageTemplateGetTemplateObject"},
	{FPDEmbedFontSubsetSEL, FPDEmbedFontSubsetCreateSEL, L"FPDEmbedFontSubsetCreate"},
	{FPDEmbedFontSubsetSEL, FPDEmbedFontSubsetDeleteSEL, L"FPDEmbedFontSubsetDelete"},
	{FPDEmbedFontSubsetSEL, FPDEmbedFontSubsetStartSEL, L"FPDEmbedFontSubsetStart"},
	{FPDEmbedFontSubsetSEL, FPDEmbedFontSubsetContinueSEL, L"FPDEmbedFontSubsetContinue"},
	{FPDEngineSEL, FPDEngineCreateNofifySEL, L"FPDEngineCreateNofify"},
	{FPDEngineSEL, FPDEngineReleaseNofifySEL, L"FPDEngineReleaseNofify"},
	{FPDEngineSEL, FPDEngineGetEngineSEL, L"FPDEngineGetEngine"},
	{FPDEngineSEL, FPDEngineSetDeriverSEL, L"FPDEngineSetDeriver"},
	{FPDEngineSEL, FPDEngineClearSEL, L"FPDEngineClear"},
	{FPDEngineSEL, FPDEngineGetX509CertSEL, L"FPDEngineGetX509Cert"},
	{FPDEngineSEL, FPDEngineGetTokenInfoSizeSEL, L"FPDEngineGetTokenInfoSize"},
	{FPDEngineSEL, FPDEngineGetTokenInfoByIndexSEL, L"FPDEngineGetTokenInfoByIndex"},
	{FPDEngineSEL, FPDEngineGetlibInfoSEL, L"FPDEngineGetlibInfo"},
	{FPDEngineSEL, FPDEngineLoginSEL, L"FPDEngineLogin"},
	{FPDEngineSEL, FPDEngineLogoutSEL, L"FPDEngineLogout"},
	{FPDEngineSEL, FPDEngineReleaseCertSEL, L"FPDEngineReleaseCert"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsCreateSEL, L"FPDFlattenOptionsCreate"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsDeleteSEL, L"FPDFlattenOptionsDelete"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetRasterVectorBalanceSEL, L"FPDFlattenOptionsGetRasterVectorBalance"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetRasterVectorBalanceSEL, L"FPDFlattenOptionsSetRasterVectorBalance"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetLineArtAndTextResolutionSEL, L"FPDFlattenOptionsGetLineArtAndTextResolution"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetLineArtAndTextResolutionSEL, L"FPDFlattenOptionsSetLineArtAndTextResolution"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetGradientAndMeshResolutionSEL, L"FPDFlattenOptionsGetGradientAndMeshResolution"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetGradientAndMeshResolutionSEL, L"FPDFlattenOptionsSetGradientAndMeshResolution"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetIsConvertTextToOutlineSEL, L"FPDFlattenOptionsGetIsConvertTextToOutline"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetIsConvertTextToOutlineSEL, L"FPDFlattenOptionsSetIsConvertTextToOutline"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetIsConvertStrokeToOutlineSEL, L"FPDFlattenOptionsGetIsConvertStrokeToOutline"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetIsConvertStrokeToOutlineSEL, L"FPDFlattenOptionsSetIsConvertStrokeToOutline"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetIsClipComplexRegionsSEL, L"FPDFlattenOptionsGetIsClipComplexRegions"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetIsClipComplexRegionsSEL, L"FPDFlattenOptionsSetIsClipComplexRegions"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetIsPreserveOverprintSEL, L"FPDFlattenOptionsGetIsPreserveOverprint"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetIsPreserveOverprintSEL, L"FPDFlattenOptionsSetIsPreserveOverprint"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetIccProfileSEL, L"FPDFlattenOptionsGetIccProfile"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetIccProfileSEL, L"FPDFlattenOptionsSetIccProfile"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetMonochromeSEL, L"FPDFlattenOptionsGetMonochrome"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetMonochromeSEL, L"FPDFlattenOptionsSetMonochrome"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetGrayscaleSEL, L"FPDFlattenOptionsGetGrayscale"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetGrayscaleSEL, L"FPDFlattenOptionsSetGrayscale"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetColorSEL, L"FPDFlattenOptionsGetColor"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetColorSEL, L"FPDFlattenOptionsSetColor"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetQualitySEL, L"FPDFlattenOptionsGetQuality"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetQualitySEL, L"FPDFlattenOptionsSetQuality"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetDPISEL, L"FPDFlattenOptionsGetDPI"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetDPISEL, L"FPDFlattenOptionsSetDPI"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetBackColorSEL, L"FPDFlattenOptionsGetBackColor"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetBackColorSEL, L"FPDFlattenOptionsSetBackColor"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsGetRenderFlagsSEL, L"FPDFlattenOptionsGetRenderFlags"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetRenderFlagsSEL, L"FPDFlattenOptionsSetRenderFlags"},
	{FPDFlattenOptionsSEL, FPDFlattenOptionsSetOCContextSEL, L"FPDFlattenOptionsSetOCContext"},
	{FPDOCSPCacheSEL, FPDOCSPCacheDisableAutoCacheSEL, L"FPDOCSPCacheDisableAutoCache"},
	{FPDOCSPCacheSEL, FPDOCSPCacheDiscardExpiredCacheSEL, L"FPDOCSPCacheDiscardExpiredCache"},
	{FPDOCSPCacheSEL, FPDOCSPCacheClearAllCacheSEL, L"FPDOCSPCacheClearAllCache"},
	{FPDTimeStampServerNotifySEL, FPDTimeStampServerNotifyCreateSEL, L"FPDTimeStampServerNotifyCreate"},
	{FPDTimeStampServerNotifySEL, FPDTimeStampServerNotifyDestroySEL, L"FPDTimeStampServerNotifyDestroy"},
// fpd_docImpl.h end

// In file fpd_editImpl.h
	{FPDWordRangeSEL, FPDWordRangeNewSEL, L"FPDWordRangeNew"},
	{FPDWordRangeSEL, FPDWordRangeDestroySEL, L"FPDWordRangeDestroy"},
	{FPDWordRangeSEL, FPDWordRangeSetDefaultSEL, L"FPDWordRangeSetDefault"},
	{FPDWordRangeSEL, FPDWordRangeSetSEL, L"FPDWordRangeSet"},
	{FPDWordRangeSEL, FPDWordRangeSetBeginPosSEL, L"FPDWordRangeSetBeginPos"},
	{FPDWordRangeSEL, FPDWordRangeSetEndPosSEL, L"FPDWordRangeSetEndPos"},
	{FPDWordRangeSEL, FPDWordRangeIsExistSEL, L"FPDWordRangeIsExist"},
	{FPDWordRangeSEL, FPDWordRangeEqualSEL, L"FPDWordRangeEqual"},
	{FPDWordRangeSEL, FPDWordRangeSwapWordPlaceSEL, L"FPDWordRangeSwapWordPlace"},
	{FPDWordRangeSEL, FPDWordRangeGetBeginPosSEL, L"FPDWordRangeGetBeginPos"},
	{FPDWordRangeSEL, FPDWordRangeGetEndPosSEL, L"FPDWordRangeGetEndPos"},
	{FPDWordPropsSEL, FPDWordPropsNewSEL, L"FPDWordPropsNew"},
	{FPDWordPropsSEL, FPDWordPropsNewIISEL, L"FPDWordPropsNewII"},
	{FPDWordPropsSEL, FPDWordPropsDestroySEL, L"FPDWordPropsDestroy"},
	{FPDWordPropsSEL, FPDWordPropsSetFontIndexSEL, L"FPDWordPropsSetFontIndex"},
	{FPDWordPropsSEL, FPDWordPropsGetFontIndexSEL, L"FPDWordPropsGetFontIndex"},
	{FPDWordPropsSEL, FPDWordPropsSetFontSizeSEL, L"FPDWordPropsSetFontSize"},
	{FPDWordPropsSEL, FPDWordPropsGetFontSizeSEL, L"FPDWordPropsGetFontSize"},
	{FPDWordPropsSEL, FPDWordPropsSetWordColorSEL, L"FPDWordPropsSetWordColor"},
	{FPDWordPropsSEL, FPDWordPropsGetWordColorSEL, L"FPDWordPropsGetWordColor"},
	{FPDWordPropsSEL, FPDWordPropsSetStrokeColorSEL, L"FPDWordPropsSetStrokeColor"},
	{FPDWordPropsSEL, FPDWordPropsGetStrokeColorSEL, L"FPDWordPropsGetStrokeColor"},
	{FPDWordPropsSEL, FPDWordPropsSetScriptTypeSEL, L"FPDWordPropsSetScriptType"},
	{FPDWordPropsSEL, FPDWordPropsGetScriptTypeSEL, L"FPDWordPropsGetScriptType"},
	{FPDWordPropsSEL, FPDWordPropsSetWordStyleSEL, L"FPDWordPropsSetWordStyle"},
	{FPDWordPropsSEL, FPDWordPropsGetWordStyleSEL, L"FPDWordPropsGetWordStyle"},
	{FPDWordPropsSEL, FPDWordPropsSetCharSpaceSEL, L"FPDWordPropsSetCharSpace"},
	{FPDWordPropsSEL, FPDWordPropsGetCharSpaceSEL, L"FPDWordPropsGetCharSpace"},
	{FPDWordPropsSEL, FPDWordPropsSetHorzScaleSEL, L"FPDWordPropsSetHorzScale"},
	{FPDWordPropsSEL, FPDWordPropsGetHorzScaleSEL, L"FPDWordPropsGetHorzScale"},
	{FPDWordPropsSEL, FPDWordPropsSetXOffsetSEL, L"FPDWordPropsSetXOffset"},
	{FPDWordPropsSEL, FPDWordPropsGetXOffsetSEL, L"FPDWordPropsGetXOffset"},
	{FPDWordPropsSEL, FPDWordPropsSetYOffsetSEL, L"FPDWordPropsSetYOffset"},
	{FPDWordPropsSEL, FPDWordPropsGetYOffsetSEL, L"FPDWordPropsGetYOffset"},
	{FPDWordPropsSEL, FPDWordPropsSetRenderingModeSEL, L"FPDWordPropsSetRenderingMode"},
	{FPDWordPropsSEL, FPDWordPropsGetRenderingModeSEL, L"FPDWordPropsGetRenderingMode"},
	{FPDWordPropsSEL, FPDWordPropsSetClientDataSEL, L"FPDWordPropsSetClientData"},
	{FPDWordPropsSEL, FPDWordPropsGetClientDataSEL, L"FPDWordPropsGetClientData"},
	{FPDWordPropsSEL, FPDWordPropsSetLineWidthSEL, L"FPDWordPropsSetLineWidth"},
	{FPDWordPropsSEL, FPDWordPropsGetLineWidthSEL, L"FPDWordPropsGetLineWidth"},
	{FPDWordPropsSEL, FPDWordPropsSetWordSpaceSEL, L"FPDWordPropsSetWordSpace"},
	{FPDWordPropsSEL, FPDWordPropsGetWordSpaceSEL, L"FPDWordPropsGetWordSpace"},
	{FPDWordPropsSEL, FPDWordPropsSetCharCodeSEL, L"FPDWordPropsSetCharCode"},
	{FPDWordPropsSEL, FPDWordPropsGetCharCodeSEL, L"FPDWordPropsGetCharCode"},
	{FPDWordPropsSEL, FPDWordPropsSetAlphaSEL, L"FPDWordPropsSetAlpha"},
	{FPDWordPropsSEL, FPDWordPropsGetAlphaSEL, L"FPDWordPropsGetAlpha"},
	{FPDEditSEL, FPDEditNewSEL, L"FPDEditNew"},
	{FPDEditSEL, FPDEditDelSEL, L"FPDEditDel"},
	{FPDEditSEL, FPDEditSetFontMapSEL, L"FPDEditSetFontMap"},
	{FPDEditSEL, FPDEditSetVTProviderSEL, L"FPDEditSetVTProvider"},
	{FPDEditSEL, FPDEditSetNotifySEL, L"FPDEditSetNotify"},
	{FPDEditSEL, FPDEditSetOprNotifySEL, L"FPDEditSetOprNotify"},
	{FPDEditSEL, FPDEditGetIteratorSEL, L"FPDEditGetIterator"},
	{FPDEditSEL, FPDEditGetVariableTextSEL, L"FPDEditGetVariableText"},
	{FPDEditSEL, FPDEditGetFontMapSEL, L"FPDEditGetFontMap"},
	{FPDEditSEL, FPDEditInitializeSEL, L"FPDEditInitialize"},
	{FPDEditSEL, FPDEditSetPlateRectSEL, L"FPDEditSetPlateRect"},
	{FPDEditSEL, FPDEditSetScrollPosSEL, L"FPDEditSetScrollPos"},
	{FPDEditSEL, FPDEditIsVerticalWritingSEL, L"FPDEditIsVerticalWriting"},
	{FPDEditSEL, FPDEditSetAlignmentHSEL, L"FPDEditSetAlignmentH"},
	{FPDEditSEL, FPDEditSetAlignmentVSEL, L"FPDEditSetAlignmentV"},
	{FPDEditSEL, FPDEditSetPasswordCharSEL, L"FPDEditSetPasswordChar"},
	{FPDEditSEL, FPDEditSetLimitCharSEL, L"FPDEditSetLimitChar"},
	{FPDEditSEL, FPDEditSetCharArraySEL, L"FPDEditSetCharArray"},
	{FPDEditSEL, FPDEditSetCharSpaceSEL, L"FPDEditSetCharSpace"},
	{FPDEditSEL, FPDEditSetWordSpaceSEL, L"FPDEditSetWordSpace"},
	{FPDEditSEL, FPDEditSetHorzScaleSEL, L"FPDEditSetHorzScale"},
	{FPDEditSEL, FPDEditSetLineLeadingSEL, L"FPDEditSetLineLeading"},
	{FPDEditSEL, FPDEditSetMultiLineSEL, L"FPDEditSetMultiLine"},
	{FPDEditSEL, FPDEditSetAutoReturnSEL, L"FPDEditSetAutoReturn"},
	{FPDEditSEL, FPDEditSetAutoFontSizeSEL, L"FPDEditSetAutoFontSize"},
	{FPDEditSEL, FPDEditSetAutoScrollSEL, L"FPDEditSetAutoScroll"},
	{FPDEditSEL, FPDEditSetFontSizeSEL, L"FPDEditSetFontSize"},
	{FPDEditSEL, FPDEditSetTextOverflowSEL, L"FPDEditSetTextOverflow"},
	{FPDEditSEL, FPDEditSetDirectionRTLSEL, L"FPDEditSetDirectionRTL"},
	{FPDEditSEL, FPDEditIsRichTextSEL, L"FPDEditIsRichText"},
	{FPDEditSEL, FPDEditSetRichTextSEL, L"FPDEditSetRichText"},
	{FPDEditSEL, FPDEditSetRichTextFontSEL, L"FPDEditSetRichTextFont"},
	{FPDEditSEL, FPDEditSetRichTextIsBoldSEL, L"FPDEditSetRichTextIsBold"},
	{FPDEditSEL, FPDEditSetRichTextIsItalicSEL, L"FPDEditSetRichTextIsItalic"},
	{FPDEditSEL, FPDEditSetRichFontSizeSEL, L"FPDEditSetRichFontSize"},
	{FPDEditSEL, FPDEditSetRichTextColorSEL, L"FPDEditSetRichTextColor"},
	{FPDEditSEL, FPDEditSetRichTextStrokeColorSEL, L"FPDEditSetRichTextStrokeColor"},
	{FPDEditSEL, FPDEditSetRichRenderingModeSEL, L"FPDEditSetRichRenderingMode"},
	{FPDEditSEL, FPDEditSetRichTextScriptSEL, L"FPDEditSetRichTextScript"},
	{FPDEditSEL, FPDEditSetRichTextUnderlineSEL, L"FPDEditSetRichTextUnderline"},
	{FPDEditSEL, FPDEditSetRichTextCrossoutSEL, L"FPDEditSetRichTextCrossout"},
	{FPDEditSEL, FPDEditSetRichTextCharSpaceSEL, L"FPDEditSetRichTextCharSpace"},
	{FPDEditSEL, FPDEditSetRichTextWordSpaceSEL, L"FPDEditSetRichTextWordSpace"},
	{FPDEditSEL, FPDEditSetRichTextHorzScaleSEL, L"FPDEditSetRichTextHorzScale"},
	{FPDEditSEL, FPDEditSetRichTextLineLeadingSEL, L"FPDEditSetRichTextLineLeading"},
	{FPDEditSEL, FPDEditSetRichTextLineIndentSEL, L"FPDEditSetRichTextLineIndent"},
	{FPDEditSEL, FPDEditSetRichTextAlignmentSEL, L"FPDEditSetRichTextAlignment"},
	{FPDEditSEL, FPDEditSetRichTextSoftReturnSEL, L"FPDEditSetRichTextSoftReturn"},
	{FPDEditSEL, FPDEditSetSelSEL, L"FPDEditSetSel"},
	{FPDEditSEL, FPDEditGetSelSEL, L"FPDEditGetSel"},
	{FPDEditSEL, FPDEditSelectAllSEL, L"FPDEditSelectAll"},
	{FPDEditSEL, FPDEditSelectNoneSEL, L"FPDEditSelectNone"},
	{FPDEditSEL, FPDEditGetCaretSEL, L"FPDEditGetCaret"},
	{FPDEditSEL, FPDEditGetCaretWordPlaceSEL, L"FPDEditGetCaretWordPlace"},
	{FPDEditSEL, FPDEditGetSelTextSEL, L"FPDEditGetSelText"},
	{FPDEditSEL, FPDEditGetTextSEL, L"FPDEditGetText"},
	{FPDEditSEL, FPDEditGetRichTextXMLSEL, L"FPDEditGetRichTextXML"},
	{FPDEditSEL, FPDEditIsSelectedSEL, L"FPDEditIsSelected"},
	{FPDEditSEL, FPDEditGetScrollPosSEL, L"FPDEditGetScrollPos"},
	{FPDEditSEL, FPDEditGetPlateRectSEL, L"FPDEditGetPlateRect"},
	{FPDEditSEL, FPDEditGetContentRectSEL, L"FPDEditGetContentRect"},
	{FPDEditSEL, FPDEditGetVisibleWordRangeSEL, L"FPDEditGetVisibleWordRange"},
	{FPDEditSEL, FPDEditGetWholeWordRangeSEL, L"FPDEditGetWholeWordRange"},
	{FPDEditSEL, FPDEditGetSelectWordRangeSEL, L"FPDEditGetSelectWordRange"},
	{FPDEditSEL, FPDEditOnMouseDownSEL, L"FPDEditOnMouseDown"},
	{FPDEditSEL, FPDEditOnMouseMoveSEL, L"FPDEditOnMouseMove"},
	{FPDEditSEL, FPDEditOnVK_UPSEL, L"FPDEditOnVK_UP"},
	{FPDEditSEL, FPDEditOnVK_DOWNSEL, L"FPDEditOnVK_DOWN"},
	{FPDEditSEL, FPDEditOnVK_LEFTSEL, L"FPDEditOnVK_LEFT"},
	{FPDEditSEL, FPDEditOnVK_RIGHTSEL, L"FPDEditOnVK_RIGHT"},
	{FPDEditSEL, FPDEditOnVK_HOMESEL, L"FPDEditOnVK_HOME"},
	{FPDEditSEL, FPDEditOnVK_ENDSEL, L"FPDEditOnVK_END"},
	{FPDEditSEL, FPDEditSetTextSEL, L"FPDEditSetText"},
	{FPDEditSEL, FPDEditSetRichTextByXMLSEL, L"FPDEditSetRichTextByXML"},
	{FPDEditSEL, FPDEditInsertWordSEL, L"FPDEditInsertWord"},
	{FPDEditSEL, FPDEditInsertReturnSEL, L"FPDEditInsertReturn"},
	{FPDEditSEL, FPDEditInsertTextSEL, L"FPDEditInsertText"},
	{FPDEditSEL, FPDEditBackspaceSEL, L"FPDEditBackspace"},
	{FPDEditSEL, FPDEditDeleteSEL, L"FPDEditDelete"},
	{FPDEditSEL, FPDEditClearSEL, L"FPDEditClear"},
	{FPDEditSEL, FPDEditRedoSEL, L"FPDEditRedo"},
	{FPDEditSEL, FPDEditUndoSEL, L"FPDEditUndo"},
	{FPDEditSEL, FPDEditSetCaretSEL, L"FPDEditSetCaret"},
	{FPDEditSEL, FPDEditPaintSEL, L"FPDEditPaint"},
	{FPDEditSEL, FPDEditEnableRefreshSEL, L"FPDEditEnableRefresh"},
	{FPDEditSEL, FPDEditRefreshWordRangeSEL, L"FPDEditRefreshWordRange"},
	{FPDEditSEL, FPDEditEnableUndoSEL, L"FPDEditEnableUndo"},
	{FPDEditSEL, FPDEditEnableNotifySEL, L"FPDEditEnableNotify"},
	{FPDEditSEL, FPDEditEnableOprNotifySEL, L"FPDEditEnableOprNotify"},
	{FPDEditSEL, FPDEditWordPlaceToWordIndexSEL, L"FPDEditWordPlaceToWordIndex"},
	{FPDEditSEL, FPDEditWordIndexToWordPlaceSEL, L"FPDEditWordIndexToWordPlace"},
	{FPDEditSEL, FPDEditGetLineBeginPlaceSEL, L"FPDEditGetLineBeginPlace"},
	{FPDEditSEL, FPDEditGetLineEndPlaceSEL, L"FPDEditGetLineEndPlace"},
	{FPDEditSEL, FPDEditGetSectionBeginPlaceSEL, L"FPDEditGetSectionBeginPlace"},
	{FPDEditSEL, FPDEditGetSectionEndPlaceSEL, L"FPDEditGetSectionEndPlace"},
	{FPDEditSEL, FPDEditSearchWordPlaceSEL, L"FPDEditSearchWordPlace"},
	{FPDEditSEL, FPDEditGetFontSizeSEL, L"FPDEditGetFontSize"},
	{FPDEditSEL, FPDEditGetPasswordCharSEL, L"FPDEditGetPasswordChar"},
	{FPDEditSEL, FPDEditGetCharArraySEL, L"FPDEditGetCharArray"},
	{FPDEditSEL, FPDEditGetHorzScaleSEL, L"FPDEditGetHorzScale"},
	{FPDEditSEL, FPDEditGetCharSpaceSEL, L"FPDEditGetCharSpace"},
	{FPDEditSEL, FPDEditGetRangeTextSEL, L"FPDEditGetRangeText"},
	{FPDEditSEL, FPDEditIsTextFullSEL, L"FPDEditIsTextFull"},
	{FPDEditSEL, FPDEditCanUndoSEL, L"FPDEditCanUndo"},
	{FPDEditSEL, FPDEditCanRedoSEL, L"FPDEditCanRedo"},
	{FPDEditSEL, FPDEditResetUndoSEL, L"FPDEditResetUndo"},
	{FPDEditSEL, FPDEditIsModifiedSEL, L"FPDEditIsModified"},
	{FPDEditSEL, FPDEditGetTotalWordsSEL, L"FPDEditGetTotalWords"},
	{FPDEditSEL, FPDEditAddUndoItemSEL, L"FPDEditAddUndoItem"},
	{FPDEditSEL, FPDEditBeginGroupUndoSEL, L"FPDEditBeginGroupUndo"},
	{FPDEditSEL, FPDEditEndGroupUndoSEL, L"FPDEditEndGroupUndo"},
	{FPDEditSEL, FPDEditSaveLineOffsetSEL, L"FPDEditSaveLineOffset"},
	{FPDEditSEL, FPDEditGetEditAppearanceStreamSEL, L"FPDEditGetEditAppearanceStream"},
	{FPDEditSEL, FPDEditGetRichEditAppearanceStreamSEL, L"FPDEditGetRichEditAppearanceStream"},
	{FPDEditSEL, FPDEditGetSelectAppearanceStreamSEL, L"FPDEditGetSelectAppearanceStream"},
	{FPDEditSEL, FPDEditDrawEditSEL, L"FPDEditDrawEdit"},
	{FPDEditSEL, FPDEditDrawUnderlineSEL, L"FPDEditDrawUnderline"},
	{FPDEditSEL, FPDEditDrawRichEditSEL, L"FPDEditDrawRichEdit"},
	{FPDEditSEL, FPDEditGeneratePageObjectsSEL, L"FPDEditGeneratePageObjects"},
	{FPDEditSEL, FPDEditGenerateRichPageObjectsSEL, L"FPDEditGenerateRichPageObjects"},
	{FPDEditSEL, FPDEditGenerateUnderlineObjectsSEL, L"FPDEditGenerateUnderlineObjects"},
	{FPDEditSEL, FPDEditGetRichTextPlainTextSEL, L"FPDEditGetRichTextPlainText"},
	{FPDEditSEL, FPDEditSetText2SEL, L"FPDEditSetText2"},
	{FPDEditSEL, FPDEditIsPunctuationSEL, L"FPDEditIsPunctuation"},
	{FPDEditSEL, FPDEditEnableArtificialBoldSEL, L"FPDEditEnableArtificialBold"},
	{FPDEditSEL, FPDEditSetFillModeSEL, L"FPDEditSetFillMode"},
	{FPDEditSEL, FPDEditBeginOperBulletSEL, L"FPDEditBeginOperBullet"},
	{FPDEditSEL, FPDEditEndOperBulletSEL, L"FPDEditEndOperBullet"},
	{FPDEditSEL, FPDEditGetBulletSEL, L"FPDEditGetBullet"},
	{FPDEditSEL, FPDEditGetBulletWordIteratorSEL, L"FPDEditGetBulletWordIterator"},
	{FPDEditSEL, FPDEditSetLineLeadingRatioSEL, L"FPDEditSetLineLeadingRatio"},
	{FPDEditSEL, FPDEditGetRichTextXML2SEL, L"FPDEditGetRichTextXML2"},
	{FPDEditSEL, FPDEditDeleteTextListSEL, L"FPDEditDeleteTextList"},
	{FPDEditSEL, FPDEditModifyNumberedListSEL, L"FPDEditModifyNumberedList"},
	{FPDEditSEL, FPDEditModifyBulletedListSEL, L"FPDEditModifyBulletedList"},
	{FPDEditFontMapSEL, FPDEditFontMapGetFontStyleSEL, L"FPDEditFontMapGetFontStyle"},
	{FPDEditFontMapSEL, FPDEditFontMapIsExternalEmbedFontSEL, L"FPDEditFontMapIsExternalEmbedFont"},
	{FPDEditFontMapSEL, FPDEditFontMapIsEmbeddedSEL, L"FPDEditFontMapIsEmbedded"},
	{FPDEditFontMapSEL, FPDEditFontMapGetFontIndexByUnicode3SEL, L"FPDEditFontMapGetFontIndexByUnicode3"},
	{FPDEditFontMapSEL, FPDEditFontMapGetFontIndex3SEL, L"FPDEditFontMapGetFontIndex3"},
	{FPDEditFontMapSEL, FPDEditFontMapAddFXFont2SEL, L"FPDEditFontMapAddFXFont2"},
	{FPDEditFontMapSEL, FPDEditFontMapAddPDFFont2SEL, L"FPDEditFontMapAddPDFFont2"},
	{FPDEditFontMapSEL, FPDEditFontMapLoadAllFontByDictSEL, L"FPDEditFontMapLoadAllFontByDict"},
	{FPDEditFontMapSEL, FPDEditFontMapCreateSEL, L"FPDEditFontMapCreate"},
	{FPDEditFontMapSEL, FPDEditFontMapDestroySEL, L"FPDEditFontMapDestroy"},
	{FPDEditFontMapSEL, FPDEditFontMapGetFontNameSEL, L"FPDEditFontMapGetFontName"},
	{FPDEditFontMapSEL, FPDEditFontMapGetFXFontSEL, L"FPDEditFontMapGetFXFont"},
	{FPDEditFontMapSEL, FPDEditFontMapGetCharsetSEL, L"FPDEditFontMapGetCharset"},
	{FPDEditFontMapSEL, FPDEditFontMapInitializeSEL, L"FPDEditFontMapInitialize"},
	{FPDEditFontMapSEL, FPDEditFontMapGetPDFFontSEL, L"FPDEditFontMapGetPDFFont"},
	{FPDEditFontMapSEL, FPDEditFontMapGetRealNameFromTagNameSEL, L"FPDEditFontMapGetRealNameFromTagName"},
	{FPDEditFontMapSEL, FPDEditFontMapGetSysDefaultFontNameSEL, L"FPDEditFontMapGetSysDefaultFontName"},
	{FPDVTWordSEL, FPDVTWordNewSEL, L"FPDVTWordNew"},
	{FPDVTWordSEL, FPDVTWordDestroySEL, L"FPDVTWordDestroy"},
	{FPDVTWordSEL, FPDVTWordSetWordSEL, L"FPDVTWordSetWord"},
	{FPDVTWordSEL, FPDVTWordGetWordSEL, L"FPDVTWordGetWord"},
	{FPDVTWordSEL, FPDVTWordSetWordDisplaySEL, L"FPDVTWordSetWordDisplay"},
	{FPDVTWordSEL, FPDVTWordGetWordDisplaySEL, L"FPDVTWordGetWordDisplay"},
	{FPDVTWordSEL, FPDVTWordSetBidiOrderSEL, L"FPDVTWordSetBidiOrder"},
	{FPDVTWordSEL, FPDVTWordGetBidiOrderSEL, L"FPDVTWordGetBidiOrder"},
	{FPDVTWordSEL, FPDVTWordSetCharsetSEL, L"FPDVTWordSetCharset"},
	{FPDVTWordSEL, FPDVTWordGetCharsetSEL, L"FPDVTWordGetCharset"},
	{FPDVTWordSEL, FPDVTWordSetWordPlaceSEL, L"FPDVTWordSetWordPlace"},
	{FPDVTWordSEL, FPDVTWordGetWordPlaceSEL, L"FPDVTWordGetWordPlace"},
	{FPDVTWordSEL, FPDVTWordSetWordPointSEL, L"FPDVTWordSetWordPoint"},
	{FPDVTWordSEL, FPDVTWordGetWordPointSEL, L"FPDVTWordGetWordPoint"},
	{FPDVTWordSEL, FPDVTWordSetAscentSEL, L"FPDVTWordSetAscent"},
	{FPDVTWordSEL, FPDVTWordGetAscentSEL, L"FPDVTWordGetAscent"},
	{FPDVTWordSEL, FPDVTWordSetDescentSEL, L"FPDVTWordSetDescent"},
	{FPDVTWordSEL, FPDVTWordGetDescentSEL, L"FPDVTWordGetDescent"},
	{FPDVTWordSEL, FPDVTWordSetWidthSEL, L"FPDVTWordSetWidth"},
	{FPDVTWordSEL, FPDVTWordGetWidthSEL, L"FPDVTWordGetWidth"},
	{FPDVTWordSEL, FPDVTWordSetFontIndexSEL, L"FPDVTWordSetFontIndex"},
	{FPDVTWordSEL, FPDVTWordGetFontIndexSEL, L"FPDVTWordGetFontIndex"},
	{FPDVTWordSEL, FPDVTWordSetFontSizeSEL, L"FPDVTWordSetFontSize"},
	{FPDVTWordSEL, FPDVTWordGetFontSizeSEL, L"FPDVTWordGetFontSize"},
	{FPDVTWordSEL, FPDVTWordSetWordPropsSEL, L"FPDVTWordSetWordProps"},
	{FPDVTWordSEL, FPDVTWordGetWordPropsSEL, L"FPDVTWordGetWordProps"},
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsCreateXFARenderOptionsSEL, L"FPDXFARenderOptionsCreateXFARenderOptions"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsDeleteXFARenderOptionsSEL, L"FPDXFARenderOptionsDeleteXFARenderOptions"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsGetIsPrintSEL, L"FPDXFARenderOptionsGetIsPrint"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsSetIsPrintSEL, L"FPDXFARenderOptionsSetIsPrint"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsGetIsHighlightSEL, L"FPDXFARenderOptionsGetIsHighlight"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsSetIsHighlightSEL, L"FPDXFARenderOptionsSetIsHighlight"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsGetIsConverPdfSEL, L"FPDXFARenderOptionsGetIsConverPdf"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsSetIsConverPdfSEL, L"FPDXFARenderOptionsSetIsConverPdf"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsGetColorModeSEL, L"FPDXFARenderOptionsGetColorMode"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsSetColorModeSEL, L"FPDXFARenderOptionsSetColorMode"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsGetDocTextColorSEL, L"FPDXFARenderOptionsGetDocTextColor"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsSetDocTextColorSEL, L"FPDXFARenderOptionsSetDocTextColor"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsSetCustomColorModeSEL, L"FPDXFARenderOptionsSetCustomColorMode"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsTranslateColorSEL, L"FPDXFARenderOptionsTranslateColor"},
	{FPDXFARenderOptionsSEL, FPDXFARenderOptionsGetCustomColorModeSEL, L"FPDXFARenderOptionsGetCustomColorMode"},
	{FPDXFARenderContextSEL, FPDXFARenderContextCreateSEL, L"FPDXFARenderContextCreate"},
	{FPDXFARenderContextSEL, FPDXFARenderContextReleaseSEL, L"FPDXFARenderContextRelease"},
	{FPDXFARenderContextSEL, FPDXFARenderContextStartRenderSEL, L"FPDXFARenderContextStartRender"},
	{FPDXFARenderContextSEL, FPDXFARenderContextDoRenderSEL, L"FPDXFARenderContextDoRender"},
	{FPDXFARenderContextSEL, FPDXFARenderContextStopRenderSEL, L"FPDXFARenderContextStopRender"},
	{FPDXFAConverterSEL, FPDXFAConverterCreateSEL, L"FPDXFAConverterCreate"},
	{FPDXFAConverterSEL, FPDXFAConverterReleaseSEL, L"FPDXFAConverterRelease"},
	{FPDXFAConverterSEL, FPDXFAConverterStartConvertSEL, L"FPDXFAConverterStartConvert"},
	{FPDXFAConverterSEL, FPDXFAConverterStartConvert2SEL, L"FPDXFAConverterStartConvert2"},
	{FPDXFAConverterSEL, FPDXFAConverterStartConvert3SEL, L"FPDXFAConverterStartConvert3"},
	{FPDXFAConverterSEL, FPDXFAConverterStartConvert4SEL, L"FPDXFAConverterStartConvert4"},
	{FPDXFAConverterSEL, FPDXFAConverterDoConvertSEL, L"FPDXFAConverterDoConvert"},
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
	{FPDLRContextSEL, FPDLRContextCreatePageContextSEL, L"FPDLRContextCreatePageContext"},
	{FPDLRContextSEL, FPDLRContextContinueSEL, L"FPDLRContextContinue"},
	{FPDLRContextSEL, FPDLRContextReleaseSEL, L"FPDLRContextRelease"},
	{FPDLRContextSEL, FPDLRContextGetRootElementSEL, L"FPDLRContextGetRootElement"},
	{FPDLRContextSEL, FPDLRContextReleaseStructureTreeSEL, L"FPDLRContextReleaseStructureTree"},
	{FPDLRContextSEL, FPDLRContextStartSEL, L"FPDLRContextStart"},
	{FPDLRContextSEL, FPDLRContextReleaseStructureTree2SEL, L"FPDLRContextReleaseStructureTree2"},
	{FPDLRContextSEL, FPDLRContextAnalysisOptionsSEL, L"FPDLRContextAnalysisOptions"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefCreateSEL, L"FPDLRStructureElementRefCreate"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefDestroySEL, L"FPDLRStructureElementRefDestroy"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefGetChildrenSEL, L"FPDLRStructureElementRefGetChildren"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefGetStdStructureTypeSEL, L"FPDLRStructureElementRefGetStdStructureType"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefIsNullSEL, L"FPDLRStructureElementRefIsNull"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefGetStdAttrValueFloatSEL, L"FPDLRStructureElementRefGetStdAttrValueFloat"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefGetElementTypeSEL, L"FPDLRStructureElementRefGetElementType"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefGetParentElementSEL, L"FPDLRStructureElementRefGetParentElement"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefAsStructureElementSEL, L"FPDLRStructureElementRefAsStructureElement"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefGetBBoxSEL, L"FPDLRStructureElementRefGetBBox"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefIsEqualSEL, L"FPDLRStructureElementRefIsEqual"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefGetStdAttrTypeSEL, L"FPDLRStructureElementRefGetStdAttrType"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefGetStdAttrValueEnumSEL, L"FPDLRStructureElementRefGetStdAttrValueEnum"},
	{FPDLRStructureElementRefSEL, FPDLRStructureElementRefGetStdAttrValueInt32SEL, L"FPDLRStructureElementRefGetStdAttrValueInt32"},
	{FPDLRElementListRefSEL, FPDLRElementListRefCreateSEL, L"FPDLRElementListRefCreate"},
	{FPDLRElementListRefSEL, FPDLRElementListRefDestroySEL, L"FPDLRElementListRefDestroy"},
	{FPDLRElementListRefSEL, FPDLRElementListRefGetSizeSEL, L"FPDLRElementListRefGetSize"},
	{FPDLRElementListRefSEL, FPDLRElementListRefGetAtSEL, L"FPDLRElementListRefGetAt"},
	{FPDLRElementRefSEL, FPDLRElementRefCreateSEL, L"FPDLRElementRefCreate"},
	{FPDLRElementRefSEL, FPDLRElementRefDestroySEL, L"FPDLRElementRefDestroy"},
	{FPDLRElementRefSEL, FPDLRElementRefAsStructureElementSEL, L"FPDLRElementRefAsStructureElement"},
	{FPDLRElementRefSEL, FPDLRElementRefGetElementTypeSEL, L"FPDLRElementRefGetElementType"},
	{FPDLRElementRefSEL, FPDLRElementRefAsContentElementSEL, L"FPDLRElementRefAsContentElement"},
	{FPDLRElementRefSEL, FPDLRElementRefLR_ISCONTENTTYPESEL, L"FPDLRElementRefLR_ISCONTENTTYPE"},
	{FPDLRElementRefSEL, FPDLRElementRefLR_IS_PAGEOBJTYPESEL, L"FPDLRElementRefLR_IS_PAGEOBJTYPE"},
	{FPDLRElementRefSEL, FPDLRElementRefLR_IS_STRUCTURETYPESEL, L"FPDLRElementRefLR_IS_STRUCTURETYPE"},
	{FPDLRContentElementRefSEL, FPDLRContentElementRefCreateSEL, L"FPDLRContentElementRefCreate"},
	{FPDLRContentElementRefSEL, FPDLRContentElementRefDestroySEL, L"FPDLRContentElementRefDestroy"},
	{FPDLRContentElementRefSEL, FPDLRContentElementRefGetPageObjectElementSEL, L"FPDLRContentElementRefGetPageObjectElement"},
	{FPDLRContentElementRefSEL, FPDLRContentElementRefGetPageObjectRangeSEL, L"FPDLRContentElementRefGetPageObjectRange"},
	{FPDLRContentElementRefSEL, FPDLRContentElementRefGetBBoxSEL, L"FPDLRContentElementRefGetBBox"},
	{FPDLRContentElementRefSEL, FPDLRContentElementRefGetElementTypeSEL, L"FPDLRContentElementRefGetElementType"},
	{FPDLRPageObjectElementRefSEL, FPDLRPageObjectElementRefCreateSEL, L"FPDLRPageObjectElementRefCreate"},
	{FPDLRPageObjectElementRefSEL, FPDLRPageObjectElementRefDestroySEL, L"FPDLRPageObjectElementRefDestroy"},
	{FPDLRPageObjectElementRefSEL, FPDLRPageObjectElementRefGetBBoxSEL, L"FPDLRPageObjectElementRefGetBBox"},
	{FPDLRPageObjectElementRefSEL, FPDLRPageObjectElementRefGetDictSEL, L"FPDLRPageObjectElementRefGetDict"},
	{FPDLRPageObjectElementRefSEL, FPDLRPageObjectElementRefGetPageObjectSEL, L"FPDLRPageObjectElementRefGetPageObject"},
	{FPDLRPageObjectElementRefSEL, FPDLRPageObjectElementRefGetElementTypeSEL, L"FPDLRPageObjectElementRefGetElementType"},
	{FPDLRPageObjectElementRefSEL, FPDLRPageObjectElementRefGetParentPageObjectSEL, L"FPDLRPageObjectElementRefGetParentPageObject"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsCreateSEL, L"FPDLRParseOptionsCreate"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsDeleteSEL, L"FPDLRParseOptionsDelete"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetRecognizeDivisionSEL, L"FPDLRParseOptionsGetRecognizeDivision"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetRecognizeDivisionSEL, L"FPDLRParseOptionsSetRecognizeDivision"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetLRVersionSEL, L"FPDLRParseOptionsGetLRVersion"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetLRVersionSEL, L"FPDLRParseOptionsSetLRVersion"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetProfileSEL, L"FPDLRParseOptionsGetProfile"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetProfileSEL, L"FPDLRParseOptionsSetProfile"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetUsePageMatrixSEL, L"FPDLRParseOptionsGetUsePageMatrix"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetUsePageMatrixSEL, L"FPDLRParseOptionsSetUsePageMatrix"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetOCContextSEL, L"FPDLRParseOptionsGetOCContext"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetOCContextSEL, L"FPDLRParseOptionsSetOCContext"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetSelectionRectSEL, L"FPDLRParseOptionsGetSelectionRect"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetSelectionRectSEL, L"FPDLRParseOptionsSetSelectionRect"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetRecognizeFontConservativelySEL, L"FPDLRParseOptionsGetRecognizeFontConservatively"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetRecognizeFontConservativelySEL, L"FPDLRParseOptionsSetRecognizeFontConservatively"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetEnableLayoutAnalyzeSEL, L"FPDLRParseOptionsGetEnableLayoutAnalyze"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetEnableLayoutAnalyzeSEL, L"FPDLRParseOptionsSetEnableLayoutAnalyze"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetEnableTableContainsFloatSEL, L"FPDLRParseOptionsGetEnableTableContainsFloat"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetEnableTableContainsFloatSEL, L"FPDLRParseOptionsSetEnableTableContainsFloat"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetKeepContainerConsistencySEL, L"FPDLRParseOptionsGetKeepContainerConsistency"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetKeepContainerConsistencySEL, L"FPDLRParseOptionsSetKeepContainerConsistency"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetNNCfgNameSEL, L"FPDLRParseOptionsGetNNCfgName"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetNNCfgNameSEL, L"FPDLRParseOptionsSetNNCfgName"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetNNWeightsNameSEL, L"FPDLRParseOptionsGetNNWeightsName"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetNNWeightsNameSEL, L"FPDLRParseOptionsSetNNWeightsName"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsGetNNConfidenceLevelSEL, L"FPDLRParseOptionsGetNNConfidenceLevel"},
	{FPDLRParseOptionsSEL, FPDLRParseOptionsSetNNConfidenceLevelSEL, L"FPDLRParseOptionsSetNNConfidenceLevel"},
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
	{FPDLongImageEncoderSEL, FPDLongImageEncoderCreateLongImageEncoderSEL, L"FPDLongImageEncoderCreateLongImageEncoder"},
	{FPDLongImageEncoderSEL, FPDLongImageEncoderDeleteLongImageEncoderSEL, L"FPDLongImageEncoderDeleteLongImageEncoder"},
	{FPDLongImageSEL, FPDLongImageCreateLongImageSEL, L"FPDLongImageCreateLongImage"},
	{FPDLongImageSEL, FPDLongImageDeleteLongImageSEL, L"FPDLongImageDeleteLongImage"},
	{FPDLongImageSEL, FPDLongImageAddPageSEL, L"FPDLongImageAddPage"},
	{FPDLongImageSEL, FPDLongImageAddPage2SEL, L"FPDLongImageAddPage2"},
	{FPDLongImageSEL, FPDLongImageOutputSEL, L"FPDLongImageOutput"},
	{FPDLongImageSEL, FPDLongImageOutput2SEL, L"FPDLongImageOutput2"},
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
	{FPDGraphicObjectsSEL, FPDGraphicObjectsCastToFPDPageSEL, L"FPDGraphicObjectsCastToFPDPage"},
	{FPDGraphicObjectsSEL, FPDGraphicObjectsCastToFPDFormSEL, L"FPDGraphicObjectsCastToFPDForm"},
	{FPDGraphicObjectsSEL, FPDGraphicObjectsGetTypeSEL, L"FPDGraphicObjectsGetType"},
	{FPDPDFObjectExtracterSEL, FPDPDFObjectExtracterCreateSEL, L"FPDPDFObjectExtracterCreate"},
	{FPDPDFObjectExtracterSEL, FPDPDFObjectExtracterDestroySEL, L"FPDPDFObjectExtracterDestroy"},
	{FPDPDFObjectExtracterSEL, FPDPDFObjectExtracterCreateNewPageFromOrigalSEL, L"FPDPDFObjectExtracterCreateNewPageFromOrigal"},
	{FPDPDFObjectExtracterSEL, FPDPDFObjectExtracterAddGraphicsObjectSEL, L"FPDPDFObjectExtracterAddGraphicsObject"},
	{FPDPDFObjectExtracterSEL, FPDPDFObjectExtracterCloseNewPageSEL, L"FPDPDFObjectExtracterCloseNewPage"},
	{FPDPDFObjectExtracterSEL, FPDPDFObjectExtracterUpdateStructTreeSEL, L"FPDPDFObjectExtracterUpdateStructTree"},
	{FPDPDFObjectExtracterSEL, FPDPDFObjectExtracterGetExtracterPDFDocSEL, L"FPDPDFObjectExtracterGetExtracterPDFDoc"},
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
	{FPDContentMarkItemRefSEL, FPDContentMarkItemRefGetContentMarkItemObjectSEL, L"FPDContentMarkItemRefGetContentMarkItemObject"},
	{FPDContentMarkItemRefSEL, FPDContentMarkItemRefNewSEL, L"FPDContentMarkItemRefNew"},
	{FPDContentMarkItemRefSEL, FPDContentMarkItemRefGetModifySEL, L"FPDContentMarkItemRefGetModify"},
	{FPDContentMarkItemRefSEL, FPDContentMarkItemRefCreateSEL, L"FPDContentMarkItemRefCreate"},
	{FPDContentMarkItemRefSEL, FPDContentMarkItemRefDeleteSEL, L"FPDContentMarkItemRefDelete"},
	{FPDContentMarkItemRefSEL, FPDContentMarkItemRefCopySEL, L"FPDContentMarkItemRefCopy"},
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
	{FPDNumberTreeSEL, FPDNumberTreeCreteNumberTreeSEL, L"FPDNumberTreeCreteNumberTree"},
	{FPDNumberTreeSEL, FPDNumberTreeDeleteNumberTreeSEL, L"FPDNumberTreeDeleteNumberTree"},
	{FPDNumberTreeSEL, FPDNumberTreeLookupValueSEL, L"FPDNumberTreeLookupValue"},
	{FPDNumberTreeSEL, FPDNumberTreeSetValueSEL, L"FPDNumberTreeSetValue"},
	{FPDNumberTreeSEL, FPDNumberTreeRemoveSEL, L"FPDNumberTreeRemove"},
	{FPDSizeAnalysisSEL, FPDSizeAnalysisGetObjectSizeSEL, L"FPDSizeAnalysisGetObjectSize"},
	{FPDSizeAnalysisSEL, FPDSizeAnalysisGetContentSizeSEL, L"FPDSizeAnalysisGetContentSize"},
	{FPDSizeAnalysisSEL, FPDSizeAnalysisGetXRefSizeSEL, L"FPDSizeAnalysisGetXRefSize"},
	{FPDSizeAnalysisSEL, FPDSizeAnalysisClearSEL, L"FPDSizeAnalysisClear"},
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
	{FPDGraphicsSEL, FPDGraphicsCreateGraphicsSEL, L"FPDGraphicsCreateGraphics"},
	{FPDGraphicsSEL, FPDGraphicsDeleteGraphicsSEL, L"FPDGraphicsDeleteGraphics"},
	{FPDGraphicsSEL, FPDGraphicsCreateSEL, L"FPDGraphicsCreate"},
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
	{FPDProgressHandlerSEL, FPDProgressHandlerNewValidatorHandlerSEL, L"FPDProgressHandlerNewValidatorHandler"},
	{FPDProgressHandlerSEL, FPDProgressHandlerDestroyValidatorHandlerSEL, L"FPDProgressHandlerDestroyValidatorHandler"},
	{FPDRuleSetSEL, FPDRuleSetCreateAccessiblityRuleSetSEL, L"FPDRuleSetCreateAccessiblityRuleSet"},
	{FPDRuleSetSEL, FPDRuleSetDestroyAccessiblityRuleSetSEL, L"FPDRuleSetDestroyAccessiblityRuleSet"},
	{FPDRuleSetSEL, FPDRuleSetEnableAllRulesSEL, L"FPDRuleSetEnableAllRules"},
	{FPDRuleSetSEL, FPDRuleSetEnableRuleSEL, L"FPDRuleSetEnableRule"},
	{FPDRuleSetSEL, FPDRuleSetCreateSEL, L"FPDRuleSetCreate"},
	{FPDRuleSetSEL, FPDRuleSetCreatePDFUARuleSetSEL, L"FPDRuleSetCreatePDFUARuleSet"},
	{FPDRuleSetSEL, FPDRuleSetCreatePDFUAFixRuleSetSEL, L"FPDRuleSetCreatePDFUAFixRuleSet"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemCreateValidatorFeedbackItemSEL, L"FPDValidatorFeedbackItemCreateValidatorFeedbackItem"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemDestroyValidatorFeedbackItemSEL, L"FPDValidatorFeedbackItemDestroyValidatorFeedbackItem"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemGetFeedbackItemClassSEL, L"FPDValidatorFeedbackItemGetFeedbackItemClass"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemSetFeedbackItemClassSEL, L"FPDValidatorFeedbackItemSetFeedbackItemClass"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemGetFeedbackItemTypeSEL, L"FPDValidatorFeedbackItemGetFeedbackItemType"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemSetFeedbackItemTypeSEL, L"FPDValidatorFeedbackItemSetFeedbackItemType"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemGetRuleIDSEL, L"FPDValidatorFeedbackItemGetRuleID"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemSetRuleIDSEL, L"FPDValidatorFeedbackItemSetRuleID"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemGetDocumentSEL, L"FPDValidatorFeedbackItemGetDocument"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemSetDocumentSEL, L"FPDValidatorFeedbackItemSetDocument"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemCastToFontSEL, L"FPDValidatorFeedbackItemCastToFont"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemCastToAnnotSEL, L"FPDValidatorFeedbackItemCastToAnnot"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemCastToPageSEL, L"FPDValidatorFeedbackItemCastToPage"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemCastToPageContentSEL, L"FPDValidatorFeedbackItemCastToPageContent"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemCastToStructElemSEL, L"FPDValidatorFeedbackItemCastToStructElem"},
	{FPDValidatorFeedbackItemSEL, FPDValidatorFeedbackItemCastToFieldSEL, L"FPDValidatorFeedbackItemCastToField"},
	{FPDValidatorFeedbackItemFontSEL, FPDValidatorFeedbackItemFontCreateValidatorFeedbackItemFontSEL, L"FPDValidatorFeedbackItemFontCreateValidatorFeedbackItemFont"},
	{FPDValidatorFeedbackItemFontSEL, FPDValidatorFeedbackItemFontDestroyValidatorFeedbackItemFontSEL, L"FPDValidatorFeedbackItemFontDestroyValidatorFeedbackItemFont"},
	{FPDValidatorFeedbackItemFontSEL, FPDValidatorFeedbackItemFontGetFontSEL, L"FPDValidatorFeedbackItemFontGetFont"},
	{FPDValidatorFeedbackItemFontSEL, FPDValidatorFeedbackItemFontSetFontSEL, L"FPDValidatorFeedbackItemFontSetFont"},
	{FPDValidatorFeedbackItemFontSEL, FPDValidatorFeedbackItemFontCastToValidatorFeedbackItemSEL, L"FPDValidatorFeedbackItemFontCastToValidatorFeedbackItem"},
	{FPDValidatorFeedbackItemAnnotSEL, FPDValidatorFeedbackItemAnnotCreateValidatorFeedbackItemAnnotSEL, L"FPDValidatorFeedbackItemAnnotCreateValidatorFeedbackItemAnnot"},
	{FPDValidatorFeedbackItemAnnotSEL, FPDValidatorFeedbackItemAnnotDestroyValidatorFeedbackItemAnnotSEL, L"FPDValidatorFeedbackItemAnnotDestroyValidatorFeedbackItemAnnot"},
	{FPDValidatorFeedbackItemAnnotSEL, FPDValidatorFeedbackItemAnnotGetAnnotDictSEL, L"FPDValidatorFeedbackItemAnnotGetAnnotDict"},
	{FPDValidatorFeedbackItemAnnotSEL, FPDValidatorFeedbackItemAnnotSetAnnotDictSEL, L"FPDValidatorFeedbackItemAnnotSetAnnotDict"},
	{FPDValidatorFeedbackItemAnnotSEL, FPDValidatorFeedbackItemAnnotCastToValidatorFeedbackItemSEL, L"FPDValidatorFeedbackItemAnnotCastToValidatorFeedbackItem"},
	{FPDValidatorFeedbackItemPageSEL, FPDValidatorFeedbackItemPageCreateValidatorFeedbackItemPageSEL, L"FPDValidatorFeedbackItemPageCreateValidatorFeedbackItemPage"},
	{FPDValidatorFeedbackItemPageSEL, FPDValidatorFeedbackItemPageDestroyValidatorFeedbackItemPageSEL, L"FPDValidatorFeedbackItemPageDestroyValidatorFeedbackItemPage"},
	{FPDValidatorFeedbackItemPageSEL, FPDValidatorFeedbackItemPageGetPageDictSEL, L"FPDValidatorFeedbackItemPageGetPageDict"},
	{FPDValidatorFeedbackItemPageSEL, FPDValidatorFeedbackItemPageSetPageDictSEL, L"FPDValidatorFeedbackItemPageSetPageDict"},
	{FPDValidatorFeedbackItemPageSEL, FPDValidatorFeedbackItemPageGetPageIndexSEL, L"FPDValidatorFeedbackItemPageGetPageIndex"},
	{FPDValidatorFeedbackItemPageSEL, FPDValidatorFeedbackItemPageSetPageIndexSEL, L"FPDValidatorFeedbackItemPageSetPageIndex"},
	{FPDValidatorFeedbackItemPageSEL, FPDValidatorFeedbackItemPageCastToValidatorFeedbackItemSEL, L"FPDValidatorFeedbackItemPageCastToValidatorFeedbackItem"},
	{FPDValidatorFeedbackItemPageContentSEL, FPDValidatorFeedbackItemPageContentCreateValidatorFeedbackItemPageContentSEL, L"FPDValidatorFeedbackItemPageContentCreateValidatorFeedbackItemPageContent"},
	{FPDValidatorFeedbackItemPageContentSEL, FPDValidatorFeedbackItemPageContentDestroyValidatorFeedbackItemPageSEL, L"FPDValidatorFeedbackItemPageContentDestroyValidatorFeedbackItemPage"},
	{FPDValidatorFeedbackItemPageContentSEL, FPDValidatorFeedbackItemPageContentGetPageDictSEL, L"FPDValidatorFeedbackItemPageContentGetPageDict"},
	{FPDValidatorFeedbackItemPageContentSEL, FPDValidatorFeedbackItemPageContentSetPageDictSEL, L"FPDValidatorFeedbackItemPageContentSetPageDict"},
	{FPDValidatorFeedbackItemPageContentSEL, FPDValidatorFeedbackItemPageContentGetPageIndexSEL, L"FPDValidatorFeedbackItemPageContentGetPageIndex"},
	{FPDValidatorFeedbackItemPageContentSEL, FPDValidatorFeedbackItemPageContentSetPageIndexSEL, L"FPDValidatorFeedbackItemPageContentSetPageIndex"},
	{FPDValidatorFeedbackItemPageContentSEL, FPDValidatorFeedbackItemPageContentGetContentIndexsSEL, L"FPDValidatorFeedbackItemPageContentGetContentIndexs"},
	{FPDValidatorFeedbackItemPageContentSEL, FPDValidatorFeedbackItemPageContentSetContentIndexsSEL, L"FPDValidatorFeedbackItemPageContentSetContentIndexs"},
	{FPDValidatorFeedbackItemPageContentSEL, FPDValidatorFeedbackItemPageContentGetPageContentRectSEL, L"FPDValidatorFeedbackItemPageContentGetPageContentRect"},
	{FPDValidatorFeedbackItemPageContentSEL, FPDValidatorFeedbackItemPageContentSetPageContentRectSEL, L"FPDValidatorFeedbackItemPageContentSetPageContentRect"},
	{FPDValidatorFeedbackItemPageContentSEL, FPDValidatorFeedbackItemPageContentCastToValidatorFeedbackItemSEL, L"FPDValidatorFeedbackItemPageContentCastToValidatorFeedbackItem"},
	{FPDValidatorFeedbackItemStructElemSEL, FPDValidatorFeedbackItemStructElemCreateValidatorFeedbackItemStructElemSEL, L"FPDValidatorFeedbackItemStructElemCreateValidatorFeedbackItemStructElem"},
	{FPDValidatorFeedbackItemStructElemSEL, FPDValidatorFeedbackItemStructElemDestroyValidatorFeedbackItemStructElemSEL, L"FPDValidatorFeedbackItemStructElemDestroyValidatorFeedbackItemStructElem"},
	{FPDValidatorFeedbackItemStructElemSEL, FPDValidatorFeedbackItemStructElemGetStructElementSEL, L"FPDValidatorFeedbackItemStructElemGetStructElement"},
	{FPDValidatorFeedbackItemStructElemSEL, FPDValidatorFeedbackItemStructElemSetStructElementSEL, L"FPDValidatorFeedbackItemStructElemSetStructElement"},
	{FPDValidatorFeedbackItemStructElemSEL, FPDValidatorFeedbackItemStructElemCastToValidatorFeedbackItemSEL, L"FPDValidatorFeedbackItemStructElemCastToValidatorFeedbackItem"},
	{FPDValidatorFeedbackItemFieldSEL, FPDValidatorFeedbackItemFieldCreateValidatorFeedbackItemFieldSEL, L"FPDValidatorFeedbackItemFieldCreateValidatorFeedbackItemField"},
	{FPDValidatorFeedbackItemFieldSEL, FPDValidatorFeedbackItemFieldDestroyValidatorFeedbackItemFieldSEL, L"FPDValidatorFeedbackItemFieldDestroyValidatorFeedbackItemField"},
	{FPDValidatorFeedbackItemFieldSEL, FPDValidatorFeedbackItemFieldGetFieldDictSEL, L"FPDValidatorFeedbackItemFieldGetFieldDict"},
	{FPDValidatorFeedbackItemFieldSEL, FPDValidatorFeedbackItemFieldSetFieldDictSEL, L"FPDValidatorFeedbackItemFieldSetFieldDict"},
	{FPDValidatorFeedbackItemFieldSEL, FPDValidatorFeedbackItemFieldCastToValidatorFeedbackItemSEL, L"FPDValidatorFeedbackItemFieldCastToValidatorFeedbackItem"},
	{FPDValidatorSEL, FPDValidatorCreateSEL, L"FPDValidatorCreate"},
	{FPDValidatorSEL, FPDValidatorDestroyValidatorSEL, L"FPDValidatorDestroyValidator"},
	{FPDValidatorSEL, FPDValidatorEnableAllPagesSEL, L"FPDValidatorEnableAllPages"},
	{FPDValidatorSEL, FPDValidatorEnablePageSEL, L"FPDValidatorEnablePage"},
	{FPDValidatorSEL, FPDValidatorStartSEL, L"FPDValidatorStart"},
	{FPDValidatorSEL, FPDValidatorContinueSEL, L"FPDValidatorContinue"},
	{FPDValidatorSEL, FPDValidatorNextFeedbackItemSEL, L"FPDValidatorNextFeedbackItem"},
// fpd_validateImpl.h end

//----------_V17----------
// In file fs_basicImpl.h
	{FSRectSEL, FSRectWidthSEL, L"FSRectWidth"},
	{FSRectSEL, FSRectHeightSEL, L"FSRectHeight"},
	{FSRectSEL, FSRectIsEmptySEL, L"FSRectIsEmpty"},
	{FSRectSEL, FSRectNormalizeSEL, L"FSRectNormalize"},
	{FSRectSEL, FSRectIntersectSEL, L"FSRectIntersect"},
	{FSRectSEL, FSRectIntersect2SEL, L"FSRectIntersect2"},
	{FSRectSEL, FSRectUnionSEL, L"FSRectUnion"},
	{FSRectSEL, FSRectIsEqualRectSEL, L"FSRectIsEqualRect"},
	{FSRectSEL, FSRectIsNotEqualRectSEL, L"FSRectIsNotEqualRect"},
	{FSRectSEL, FSRectOffsetSEL, L"FSRectOffset"},
	{FSRectSEL, FSRectContainsSEL, L"FSRectContains"},
	{FSRectSEL, FSRectContains2SEL, L"FSRectContains2"},
	{FSRectSEL, FSRectValidSEL, L"FSRectValid"},
	{FSRectSEL, FSRectInflateSEL, L"FSRectInflate"},
	{FSMemoryMgrSEL, FSMemoryMgrAllocSEL, L"FSMemoryMgrAlloc"},
	{FSMemoryMgrSEL, FSMemoryMgrFreeSEL, L"FSMemoryMgrFree"},
// fs_basicImpl.h end

// In file fs_stringImpl.h
	{FSUnicodeMgrSEL, FSUnicodeMgrGetUnicodeGeneralCategorySEL, L"FSUnicodeMgrGetUnicodeGeneralCategory"},
	{FSUnicodeMgrSEL, FSUnicodeMgrEastAsianWidthSEL, L"FSUnicodeMgrEastAsianWidth"},
	{FSUnicodeMgrSEL, FSUnicodeMgrNFKDSEL, L"FSUnicodeMgrNFKD"},
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
	{FRPrintMgrSEL, FRPrintMgrCreateSEL, L"FRPrintMgrCreate"},
	{FRPrintMgrSEL, FRPrintMgrDeleteSEL, L"FRPrintMgrDelete"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintRangeSEL, L"FRPrintMgrSetPrintRange"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintRangeSEL, L"FRPrintMgrGetPrintRange"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintSubsetSEL, L"FRPrintMgrSetPrintSubset"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintSubsetSEL, L"FRPrintMgrGetPrintSubset"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintRotateSEL, L"FRPrintMgrSetPrintRotate"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintRotateSEL, L"FRPrintMgrGetPrintRotate"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintScaleSEL, L"FRPrintMgrSetPrintScale"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintScaleSEL, L"FRPrintMgrGetPrintScale"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintArrangeSEL, L"FRPrintMgrSetPrintArrange"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintArrangeSEL, L"FRPrintMgrGetPrintArrange"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintCopiesSEL, L"FRPrintMgrSetPrintCopies"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintCopiesSEL, L"FRPrintMgrGetPrintCopies"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintAutoCenterSEL, L"FRPrintMgrSetPrintAutoCenter"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintAutoCenterSEL, L"FRPrintMgrGetPrintAutoCenter"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintAutoRotateSEL, L"FRPrintMgrSetPrintAutoRotate"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintAutoRotateSEL, L"FRPrintMgrGetPrintAutoRotate"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintGraySEL, L"FRPrintMgrSetPrintGray"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintGraySEL, L"FRPrintMgrGetPrintGray"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintCollateSEL, L"FRPrintMgrSetPrintCollate"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintCollateSEL, L"FRPrintMgrGetPrintCollate"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintPageOrderSEL, L"FRPrintMgrSetPrintPageOrder"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintPageBorderSEL, L"FRPrintMgrSetPrintPageBorder"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintPageBorderSEL, L"FRPrintMgrGetPrintPageBorder"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintPrintWhatSEL, L"FRPrintMgrSetPrintPrintWhat"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintOrientationSEL, L"FRPrintMgrSetPrintOrientation"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintPagesPerSheetSEL, L"FRPrintMgrSetPrintPagesPerSheet"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintPagesPerSheetSEL, L"FRPrintMgrGetPrintPagesPerSheet"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintPaperSizeByPageSEL, L"FRPrintMgrSetPrintPaperSizeByPage"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintReverseSEL, L"FRPrintMgrSetPrintReverse"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintReverseSEL, L"FRPrintMgrGetPrintReverse"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintMarginsSEL, L"FRPrintMgrSetPrintMargins"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintAsImageSEL, L"FRPrintMgrSetPrintAsImage"},
	{FRPrintMgrSEL, FRPrintMgrSetSimulateOverprintingSEL, L"FRPrintMgrSetSimulateOverprinting"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintIgnoreAdvancedSettingSEL, L"FRPrintMgrSetPrintIgnoreAdvancedSetting"},
	{FRPrintMgrSEL, FRPrintMgrSetProgressDisplaySEL, L"FRPrintMgrSetProgressDisplay"},
	{FRPrintMgrSEL, FRPrintMgrSetPaperSizeSEL, L"FRPrintMgrSetPaperSize"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintPageArraySEL, L"FRPrintMgrSetPrintPageArray"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintPageArraySEL, L"FRPrintMgrGetPrintPageArray"},
	{FRPrintMgrSEL, FRPrintMgrGetDefaultPrintSEL, L"FRPrintMgrGetDefaultPrint"},
	{FRPrintMgrSEL, FRPrintMgrSetDefaultPrintSEL, L"FRPrintMgrSetDefaultPrint"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintOutputFileNameSEL, L"FRPrintMgrSetPrintOutputFileName"},
	{FRPrintMgrSEL, FRPrintMgrDoModalSEL, L"FRPrintMgrDoModal"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintDevModeSEL, L"FRPrintMgrSetPrintDevMode"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintPreviewSEL, L"FRPrintMgrSetPrintPreview"},
	{FRPrintMgrSEL, FRPrintMgrEnablePrintAnnotSEL, L"FRPrintMgrEnablePrintAnnot"},
	{FRPrintMgrSEL, FRPrintMgrSetRangeModeSEL, L"FRPrintMgrSetRangeMode"},
	{FRPrintMgrSEL, FRPrintMgrGetRangeModeSEL, L"FRPrintMgrGetRangeMode"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintBookletBindingSEL, L"FRPrintMgrSetPrintBookletBinding"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintBookletSubSetSEL, L"FRPrintMgrSetPrintBookletSubSet"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintCutMarksSEL, L"FRPrintMgrSetPrintCutMarks"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintLabelsSEL, L"FRPrintMgrSetPrintLabels"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintPageScaleTypeSEL, L"FRPrintMgrSetPrintPageScaleType"},
	{FRPrintMgrSEL, FRPrintMgrEnumPrinterNameSEL, L"FRPrintMgrEnumPrinterName"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintDuplexTypeSEL, L"FRPrintMgrSetPrintDuplexType"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintOverlapSEL, L"FRPrintMgrSetPrintOverlap"},
	{FRPrintMgrSEL, FRPrintMgrSetPrintHandlingTypeSEL, L"FRPrintMgrSetPrintHandlingType"},
	{FRPrintMgrSEL, FRPrintMgrGetPrintHandlingTypeSEL, L"FRPrintMgrGetPrintHandlingType"},
	{FREncryptedDocMgrSEL, FREncryptedDocMgrToDecFileSEL, L"FREncryptedDocMgrToDecFile"},
	{FREncryptedDocMgrSEL, FREncryptedDocMgrToDelDecFileSEL, L"FREncryptedDocMgrToDelDecFile"},
	{FREncryptedDocMgrSEL, FREncryptedDocMgrToEncFileSEL, L"FREncryptedDocMgrToEncFile"},
	{FREncryptedDocMgrSEL, FREncryptedDocMgrToDelEncFileSEL, L"FREncryptedDocMgrToDelEncFile"},
	{FRPDFBitmapMgrSEL, FRPDFBitmapMgrCreateSEL, L"FRPDFBitmapMgrCreate"},
	{FRPDFBitmapMgrSEL, FRPDFBitmapMgrGetByNameSEL, L"FRPDFBitmapMgrGetByName"},
	{FRPDFBitmapMgrSEL, FRPDFBitmapMgrGetBitmapSEL, L"FRPDFBitmapMgrGetBitmap"},
	{FRPDFBitmapMgrSEL, FRPDFBitmapMgrGetFXBitmapSEL, L"FRPDFBitmapMgrGetFXBitmap"},
	{FRPDFBitmapMgrSEL, FRPDFBitmapMgrDrawSEL, L"FRPDFBitmapMgrDraw"},
	{FRPDFBitmapMgrSEL, FRPDFBitmapMgrFillRoundedRectangleSEL, L"FRPDFBitmapMgrFillRoundedRectangle"},
	{FRPDFBitmapMgrSEL, FRPDFBitmapMgrDrawRoundedRectangleSEL, L"FRPDFBitmapMgrDrawRoundedRectangle"},
// fr_appImpl.h end

// In file fr_barImpl.h
	{FRRibbonHandlerSEL, FRRibbonHandlerCreateSEL, L"FRRibbonHandlerCreate"},
	{FRRibbonHandlerSEL, FRRibbonHandlerDeleteSEL, L"FRRibbonHandlerDelete"},
	{FRCustomControSEL, FRCustomControShowColorPaletteSEL, L"FRCustomControShowColorPalette"},
	{FRCustomControSEL, FRCustomControShowColorPalette2SEL, L"FRCustomControShowColorPalette2"},
	{FRCustomControSEL, FRCustomControGetCustomColorsSEL, L"FRCustomControGetCustomColors"},
	{FRCustomControSEL, FRCustomControGetCustomColors2SEL, L"FRCustomControGetCustomColors2"},
	{FRCustomControSEL, FRCustomControHideColorPaletteSEL, L"FRCustomControHideColorPalette"},
	{FRCustomControSEL, FRCustomControIsColorPaletteShowSEL, L"FRCustomControIsColorPaletteShow"},
	{FRCustomControSEL, FRCustomControShowColorDialogSEL, L"FRCustomControShowColorDialog"},
	{FRCustomControSEL, FRCustomControSetTransparentSEL, L"FRCustomControSetTransparent"},
	{FRFloatBarManagerSEL, FRFloatBarManagerCreateFloatyBarSEL, L"FRFloatBarManagerCreateFloatyBar"},
	{FRFloatBarManagerSEL, FRFloatBarManagerDestoryRibbonFloatySEL, L"FRFloatBarManagerDestoryRibbonFloaty"},
	{FRFloatBarManagerSEL, FRFloatBarManagerSetFloatyTransparencySEL, L"FRFloatBarManagerSetFloatyTransparency"},
	{FRFloatBarManagerSEL, FRFloatBarManagerGetFloatyWndSEL, L"FRFloatBarManagerGetFloatyWnd"},
	{FRFloatBarManagerSEL, FRFloatBarManagerShowArrangeFloatyBarSEL, L"FRFloatBarManagerShowArrangeFloatyBar"},
	{FRFloatBarManagerSEL, FRFloatBarManagerHideArrangeFloatyBarSEL, L"FRFloatBarManagerHideArrangeFloatyBar"},
	{FRFloatBarManagerSEL, FRFloatBarManagerGetButtonPosSEL, L"FRFloatBarManagerGetButtonPos"},
	{FRFloatBarManagerSEL, FRFloatBarManagerSetReferenceRectsSEL, L"FRFloatBarManagerSetReferenceRects"},
	{FRFloatBarManagerSEL, FRFloatBarManagerSetMarkButtonSEL, L"FRFloatBarManagerSetMarkButton"},
	{FRFloatBarManagerSEL, FRFloatBarManagerSetTransparentSEL, L"FRFloatBarManagerSetTransparent"},
	{FRFloatBarManagerSEL, FRFloatBarManagerIsTransparentSEL, L"FRFloatBarManagerIsTransparent"},
// fr_barImpl.h end

// In file fr_docImpl.h
	{FRAccessibleSEL, FRAccessibleNewSEL, L"FRAccessibleNew"},
	{FRAccessibleSEL, FRAccessibleDeleteSEL, L"FRAccessibleDelete"},
	{FRPageObserverSEL, FRPageObserverCreatePageObserverSEL, L"FRPageObserverCreatePageObserver"},
	{FRPageObserverSEL, FRPageObserverDestroyPageObserverSEL, L"FRPageObserverDestroyPageObserver"},
	{FRPageObserverSEL, FRPageObserverIsValidSEL, L"FRPageObserverIsValid"},
	{FRPageObserverSEL, FRPageObserverGetPageObjSEL, L"FRPageObserverGetPageObj"},
	{FRAnnotHandlerSEL, FRAnnotHandlerGetAnnotHandlerByTypeSEL, L"FRAnnotHandlerGetAnnotHandlerByType"},
	{FRAnnotHandlerSEL, FRAnnotHandlerGetAnnotHandlerByAnnotSEL, L"FRAnnotHandlerGetAnnotHandlerByAnnot"},
	{FRAnnotHandlerSEL, FRAnnotHandlerIsPermissionAllowedSEL, L"FRAnnotHandlerIsPermissionAllowed"},
	{FRAnnotHandlerSEL, FRAnnotHandlerGetPropertyBoxTitleSEL, L"FRAnnotHandlerGetPropertyBoxTitle"},
	{FRAnnotHandlerSEL, FRAnnotHandlerGetTypeSEL, L"FRAnnotHandlerGetType"},
	{FRAnnotHandlerSEL, FRAnnotHandlerGetNameSEL, L"FRAnnotHandlerGetName"},
	{FRWidgetAnnotHandlerSEL, FRWidgetAnnotHandlerCreateSEL, L"FRWidgetAnnotHandlerCreate"},
	{FRWidgetAnnotHandlerSEL, FRWidgetAnnotHandlerDeleteSEL, L"FRWidgetAnnotHandlerDelete"},
	{FRWidgetAnnotHandlerSEL, FRWidgetAnnotHandlerOnGetCustomHightColorSEL, L"FRWidgetAnnotHandlerOnGetCustomHightColor"},
	{FRWidgetAnnotHandlerSEL, FRWidgetAnnotHandlerOnIsShowQuickAccProperySEL, L"FRWidgetAnnotHandlerOnIsShowQuickAccPropery"},
	{FRWidgetAnnotHandlerSEL, FRWidgetAnnotHandlerOnGetSignatureAuditTrailSEL, L"FRWidgetAnnotHandlerOnGetSignatureAuditTrail"},
	{FRWidgetAnnotHandlerSEL, FRWidgetAnnotHandlerOnGetSignatureHashInfoSEL, L"FRWidgetAnnotHandlerOnGetSignatureHashInfo"},
	{FRWidgetAnnotHandlerSEL, FRWidgetAnnotHandlerOnIsShowSignaturePanelMenuSEL, L"FRWidgetAnnotHandlerOnIsShowSignaturePanelMenu"},
	{FRAnnotOperateHandlerSEL, FRAnnotOperateHandlerCreateSEL, L"FRAnnotOperateHandlerCreate"},
	{FRAnnotOperateHandlerSEL, FRAnnotOperateHandlerDeleteSEL, L"FRAnnotOperateHandlerDelete"},
	{FRAnnotOperateHandlerSEL, FRAnnotOperateHandlerOnMouseMsgSEL, L"FRAnnotOperateHandlerOnMouseMsg"},
	{FRAnnotOperateHandlerSEL, FRAnnotOperateHandlerOnCanMoveSEL, L"FRAnnotOperateHandlerOnCanMove"},
	{FRAnnotOperateHandlerSEL, FRAnnotOperateHandlerOnCanAnswerSEL, L"FRAnnotOperateHandlerOnCanAnswer"},
	{FRAnnotOperateHandlerSEL, FRAnnotOperateHandlerCanCopySEL, L"FRAnnotOperateHandlerCanCopy"},
	{FRAnnotOperateHandlerSEL, FRAnnotOperateHandlerOnLockSEL, L"FRAnnotOperateHandlerOnLock"},
	{FRBaseAnnotSEL, FRBaseAnnotSetAnnotMsgHookSEL, L"FRBaseAnnotSetAnnotMsgHook"},
	{FRBaseAnnotSEL, FRBaseAnnotGetAnnotMsgHookHandlerSEL, L"FRBaseAnnotGetAnnotMsgHookHandler"},
	{FRBaseAnnotSEL, FRBaseAnnotRemoveAnnotMsgHookSEL, L"FRBaseAnnotRemoveAnnotMsgHook"},
	{FRBaseAnnotSEL, FRBaseAnnotGetAnnotMsgHookCountSEL, L"FRBaseAnnotGetAnnotMsgHookCount"},
	{FRSaveAsNotifySEL, FRSaveAsNotifyNewSEL, L"FRSaveAsNotifyNew"},
	{FRSaveAsNotifySEL, FRSaveAsNotifyDeleteSEL, L"FRSaveAsNotifyDelete"},
	{FRSaveAsNotifySEL, FRSaveAsNotifyIsSaveAsSaveToSEL, L"FRSaveAsNotifyIsSaveAsSaveTo"},
	{FRSaveAsNotifySEL, FRSaveAsNotifyGetSaveToDefaultNameSEL, L"FRSaveAsNotifyGetSaveToDefaultName"},
	{FRSaveAsNotifySEL, FRSaveAsNotifyIsNeedShowSaveDlgSEL, L"FRSaveAsNotifyIsNeedShowSaveDlg"},
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
	{FPDITipTouchupSEL, FPDITipTouchupNewSEL, L"FPDITipTouchupNew"},
	{FPDITipTouchupSEL, FPDITipTouchupDestroySEL, L"FPDITipTouchupDestroy"},
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
	{FPD3DMatrix4x4SEL, FPD3DMatrix4x4NewSEL, L"FPD3DMatrix4x4New"},
	{FPD3DMatrix4x4SEL, FPD3DMatrix4x4DeleteSEL, L"FPD3DMatrix4x4Delete"},
	{FPD3DMatrix4x4SEL, FPD3DMatrix4x4GetCoeffsSEL, L"FPD3DMatrix4x4GetCoeffs"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataNewSEL, L"FPD3dCustomToolButtonDataNew"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataDestorySEL, L"FPD3dCustomToolButtonDataDestory"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataSetNameSEL, L"FPD3dCustomToolButtonDataSetName"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataGetNameSEL, L"FPD3dCustomToolButtonDataGetName"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataSetLabelSEL, L"FPD3dCustomToolButtonDataSetLabel"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataGetLabelSEL, L"FPD3dCustomToolButtonDataGetLabel"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataSetTypeSEL, L"FPD3dCustomToolButtonDataSetType"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataGetTypeSEL, L"FPD3dCustomToolButtonDataGetType"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataSetRemovedStateSEL, L"FPD3dCustomToolButtonDataSetRemovedState"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataGetRemovedStateSEL, L"FPD3dCustomToolButtonDataGetRemovedState"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataSetEnabledStateSEL, L"FPD3dCustomToolButtonDataSetEnabledState"},
	{FPD3dCustomToolButtonDataSEL, FPD3dCustomToolButtonDataGetEnabledStateSEL, L"FPD3dCustomToolButtonDataGetEnabledState"},
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseGetTypeSEL, L"FPDCBCCodeBaseGetType"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseSetWidthSEL, L"FPDCBCCodeBaseSetWidth"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseEncodeSEL, L"FPDCBCCodeBaseEncode"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseRenderDeviceSEL, L"FPDCBCCodeBaseRenderDevice"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseRenderBitmapSEL, L"FPDCBCCodeBaseRenderBitmap"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseDecodeSEL, L"FPDCBCCodeBaseDecode"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseDecode2SEL, L"FPDCBCCodeBaseDecode2"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseSetCharEncodingSEL, L"FPDCBCCodeBaseSetCharEncoding"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseSetModuleHeightSEL, L"FPDCBCCodeBaseSetModuleHeight"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseSetModuleWidthSEL, L"FPDCBCCodeBaseSetModuleWidth"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseSetHeightSEL, L"FPDCBCCodeBaseSetHeight"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseSetBackgroundColorSEL, L"FPDCBCCodeBaseSetBackgroundColor"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseSetBarcodeColorSEL, L"FPDCBCCodeBaseSetBarcodeColor"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseCreateSEL, L"FPDCBCCodeBaseCreate"},
	{FPDCBCCodeBaseSEL, FPDCBCCodeBaseDeleteSEL, L"FPDCBCCodeBaseDelete"},
	{FPDCBCPDF417ISEL, FPDCBCPDF417ISetIsXFABarcodeSEL, L"FPDCBCPDF417ISetIsXFABarcode"},
	{FPDCBCPDF417ISEL, FPDCBCPDF417ISetErrorCorrectionLevelSEL, L"FPDCBCPDF417ISetErrorCorrectionLevel"},
	{FPDCBCPDF417ISEL, FPDCBCPDF417ISetTruncatedSEL, L"FPDCBCPDF417ISetTruncated"},
	{FPDCBCQRCodeSEL, FPDCBCQRCodeSetVersionSEL, L"FPDCBCQRCodeSetVersion"},
	{FPDCBCQRCodeSEL, FPDCBCQRCodeSetErrorCorrectionLevelSEL, L"FPDCBCQRCodeSetErrorCorrectionLevel"},
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
	{FPDDateTimeSEL, FPDDateTimeCreateSEL, L"FPDDateTimeCreate"},
	{FPDDateTimeSEL, FPDDateTimeCreate2SEL, L"FPDDateTimeCreate2"},
	{FPDDateTimeSEL, FPDDateTimeCreate3SEL, L"FPDDateTimeCreate3"},
	{FPDDateTimeSEL, FPDDateTimeDestroySEL, L"FPDDateTimeDestroy"},
	{FPDDateTimeSEL, FPDDateTimeParserPDFDateTimeStringSEL, L"FPDDateTimeParserPDFDateTimeString"},
	{FPDDateTimeSEL, FPDDateTimeParserPDFXMPDateTimeStringSEL, L"FPDDateTimeParserPDFXMPDateTimeString"},
	{FPDDateTimeSEL, FPDDateTimeToPDFDateTimeStringSEL, L"FPDDateTimeToPDFDateTimeString"},
	{FPDDateTimeSEL, FPDDateTimeToXMPDateTimeStringSEL, L"FPDDateTimeToXMPDateTimeString"},
	{FPDDateTimeSEL, FPDDateTimeSetCurrentSystemDateTimeSEL, L"FPDDateTimeSetCurrentSystemDateTime"},
	{FPDDateTimeSEL, FPDDateTimeGetCRTDateTimeZoneSEL, L"FPDDateTimeGetCRTDateTimeZone"},
	{FPDDateTimeSEL, FPDDateTimeGetCurrentSystemTimeSEL, L"FPDDateTimeGetCurrentSystemTime"},
	{FPDOrganizeParamSEL, FPDOrganizeParamCreateSEL, L"FPDOrganizeParamCreate"},
	{FPDOrganizeParamSEL, FPDOrganizeParamDestroySEL, L"FPDOrganizeParamDestroy"},
	{FPDOrganizeParamSEL, FPDOrganizeParamGetInterFormSEL, L"FPDOrganizeParamGetInterForm"},
	{FPDOrganizeParamSEL, FPDOrganizeParamSetInterFormSEL, L"FPDOrganizeParamSetInterForm"},
	{FPDOrganizeParamSEL, FPDOrganizeParamGetStructTreeSEL, L"FPDOrganizeParamGetStructTree"},
	{FPDOrganizeParamSEL, FPDOrganizeParamSetStructTreeSEL, L"FPDOrganizeParamSetStructTree"},
	{FPDOrganizeParamSEL, FPDOrganizeParamGetOtherInterFormSEL, L"FPDOrganizeParamGetOtherInterForm"},
	{FPDOrganizeParamSEL, FPDOrganizeParamSetOtherInterFormSEL, L"FPDOrganizeParamSetOtherInterForm"},
	{FPDOrganizerSEL, FPDOrganizerCreateSEL, L"FPDOrganizerCreate"},
	{FPDOrganizerSEL, FPDOrganizerDestroySEL, L"FPDOrganizerDestroy"},
	{FPDOrganizerSEL, FPDOrganizerSetOrganizeParamSEL, L"FPDOrganizerSetOrganizeParam"},
	{FPDOrganizerSEL, FPDOrganizerInsertDocumentAtPosSEL, L"FPDOrganizerInsertDocumentAtPos"},
	{FPDFormExportHandlerSEL, FPDFormExportHandlerCreateSEL, L"FPDFormExportHandlerCreate"},
	{FPDFormExportHandlerSEL, FPDFormExportHandlerDeleteSEL, L"FPDFormExportHandlerDelete"},
	{FPDEngineLIBINFOSEL, FPDEngineLIBINFOCreateSEL, L"FPDEngineLIBINFOCreate"},
	{FPDEngineLIBINFOSEL, FPDEngineLIBINFODeleteSEL, L"FPDEngineLIBINFODelete"},
	{FPDEngineLIBINFOSEL, FPDEngineLIBINFOGetCrypVersionSEL, L"FPDEngineLIBINFOGetCrypVersion"},
	{FPDEngineLIBINFOSEL, FPDEngineLIBINFOSetCrypVersionSEL, L"FPDEngineLIBINFOSetCrypVersion"},
	{FPDEngineLIBINFOSEL, FPDEngineLIBINFOGetManuIDSEL, L"FPDEngineLIBINFOGetManuID"},
	{FPDEngineLIBINFOSEL, FPDEngineLIBINFOSetManuIDSEL, L"FPDEngineLIBINFOSetManuID"},
	{FPDEngineLIBINFOSEL, FPDEngineLIBINFOGetLibDesSEL, L"FPDEngineLIBINFOGetLibDes"},
	{FPDEngineLIBINFOSEL, FPDEngineLIBINFOSetLibDesSEL, L"FPDEngineLIBINFOSetLibDes"},
	{FPDEngineLIBINFOSEL, FPDEngineLIBINFOGetLibVersionSEL, L"FPDEngineLIBINFOGetLibVersion"},
	{FPDEngineLIBINFOSEL, FPDEngineLIBINFOSetLibVersionSEL, L"FPDEngineLIBINFOSetLibVersion"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFOCreateSEL, L"FPDEngineTokenINFOCreate"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFODeleteSEL, L"FPDEngineTokenINFODelete"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFOGetTokenSEL, L"FPDEngineTokenINFOGetToken"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFOSetTokenSEL, L"FPDEngineTokenINFOSetToken"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFOGetTokenLabelSEL, L"FPDEngineTokenINFOGetTokenLabel"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFOSetTokenLabelSEL, L"FPDEngineTokenINFOSetTokenLabel"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFOGetManuIDSEL, L"FPDEngineTokenINFOGetManuID"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFOSetManuIDSEL, L"FPDEngineTokenINFOSetManuID"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFOGetModelSEL, L"FPDEngineTokenINFOGetModel"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFOSetModelSEL, L"FPDEngineTokenINFOSetModel"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFOGetSerialNumberSEL, L"FPDEngineTokenINFOGetSerialNumber"},
	{FPDEngineTokenINFOSEL, FPDEngineTokenINFOSetSerialNumberSEL, L"FPDEngineTokenINFOSetSerialNumber"},
	{FPDExtracterSEL, FPDExtracterCreateSEL, L"FPDExtracterCreate"},
	{FPDExtracterSEL, FPDExtracterLoadDocumentSEL, L"FPDExtracterLoadDocument"},
	{FPDExtracterSEL, FPDExtracterLoadDocument2SEL, L"FPDExtracterLoadDocument2"},
	{FPDExtracterSEL, FPDExtracterStartSEL, L"FPDExtracterStart"},
	{FPDExtracterSEL, FPDExtracterContinueSEL, L"FPDExtracterContinue"},
	{FPDExtracterSEL, FPDExtracterDeleteSEL, L"FPDExtracterDelete"},
// fpd_docImpl.h end

// In file fpd_editImpl.h
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamNewSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamNew"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetFontMapSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetFontMap"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetFontIndexSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetFontIndex"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetFlagSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetFlag"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetFontSizeSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetFontSize"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetTextColorSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetTextColor"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetTextColorIISEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetTextColorII"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetRectSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetRect"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamDestroySEL, L"FPDPWLCREATEPARAMPWLWndCreationParamDestroy"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetSystemHandlerSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetSystemHandler"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetProviderSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetProvider"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetFocusHandlerSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetFocusHandler"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetBackgroundColorSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetBackgroundColor"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetAttachedWndSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetAttachedWnd"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetSpellCheckSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetSpellCheck"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetBorderStyleSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetBorderStyle"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetBorderWidthSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetBorderWidth"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetBorderColorSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetBorderColor"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetTextStrokeColorSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetTextStrokeColor"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetTransparencySEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetTransparency"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetUseFXFontDeAscentSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetUseFXFontDeAscent"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetDashSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetDash"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetAttachedDataSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetAttachedData"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetParentWndSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetParentWnd"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetCursorTypeSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetCursorType"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetMtChildSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetMtChild"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetShowFontSizeDPISEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetShowFontSizeDPI"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetNeedEmbedSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetNeedEmbed"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMPWLWndCreationParamSetListBoxFontSizeSEL, L"FPDPWLCREATEPARAMPWLWndCreationParamSetListBoxFontSize"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMGetFlagsSEL, L"FPDPWLCREATEPARAMGetFlags"},
	{FPDPWLCREATEPARAMSEL, FPDPWLCREATEPARAMGetRectSEL, L"FPDPWLCREATEPARAMGetRect"},
	{FPDCPWLEditSEL, FPDCPWLEditNewSEL, L"FPDCPWLEditNew"},
	{FPDCPWLEditSEL, FPDCPWLEditSetTextColorSEL, L"FPDCPWLEditSetTextColor"},
	{FPDCPWLEditSEL, FPDCPWLEditSetTextColorIISEL, L"FPDCPWLEditSetTextColorII"},
	{FPDCPWLEditSEL, FPDCPWLEditSetTextSEL, L"FPDCPWLEditSetText"},
	{FPDCPWLEditSEL, FPDCPWLEditGetContentRectSEL, L"FPDCPWLEditGetContentRect"},
	{FPDCPWLEditSEL, FPDCPWLEditGeneratePageObjectsSEL, L"FPDCPWLEditGeneratePageObjects"},
	{FPDCPWLEditSEL, FPDCPWLEditGeneratePageObjectsIISEL, L"FPDCPWLEditGeneratePageObjectsII"},
	{FPDCPWLEditSEL, FPDCPWLEditDestroySEL, L"FPDCPWLEditDestroy"},
	{FPDCPWLEditSEL, FPDCPWLEditEnableRefreshSEL, L"FPDCPWLEditEnableRefresh"},
	{FPDCPWLEditSEL, FPDCPWLEditSetAlignFormatHSEL, L"FPDCPWLEditSetAlignFormatH"},
	{FPDCPWLEditSEL, FPDCPWLEditSetAlignFormatVSEL, L"FPDCPWLEditSetAlignFormatV"},
	{FPDCPWLEditSEL, FPDCPWLEditSetHorzScaleSEL, L"FPDCPWLEditSetHorzScale"},
	{FPDCPWLEditSEL, FPDCPWLEditSetCharSpaceSEL, L"FPDCPWLEditSetCharSpace"},
	{FPDCPWLEditSEL, FPDCPWLEditSetLineLeadingSEL, L"FPDCPWLEditSetLineLeading"},
	{FPDCPWLEditSEL, FPDCPWLEditGetEditSEL, L"FPDCPWLEditGetEdit"},
	{FPDCPWLEditSEL, FPDCPWLEditGetTextAppearanceStreamSEL, L"FPDCPWLEditGetTextAppearanceStream"},
	{FPDCPWLEditSEL, FPDCPWLEditGetFXEditSEL, L"FPDCPWLEditGetFXEdit"},
	{FPDCPWLEditSEL, FPDCPWLEditChangeApplyAllSectionSEL, L"FPDCPWLEditChangeApplyAllSection"},
	{FPDCPWLEditSEL, FPDCPWLEditSetRichTextSEL, L"FPDCPWLEditSetRichText"},
	{FPDCPWLEditSEL, FPDCPWLEditGetCPWLWndSEL, L"FPDCPWLEditGetCPWLWnd"},
	{FPDCPWLEditSEL, FPDCPWLEditRedoSEL, L"FPDCPWLEditRedo"},
	{FPDCPWLEditSEL, FPDCPWLEditUndoSEL, L"FPDCPWLEditUndo"},
	{FPDCPWLEditSEL, FPDCPWLEditCanSelectAllSEL, L"FPDCPWLEditCanSelectAll"},
	{FPDCPWLEditSEL, FPDCPWLEditCanClearSEL, L"FPDCPWLEditCanClear"},
	{FPDCPWLEditSEL, FPDCPWLEditCanCopySEL, L"FPDCPWLEditCanCopy"},
	{FPDCPWLEditSEL, FPDCPWLEditCanCutSEL, L"FPDCPWLEditCanCut"},
	{FPDCPWLEditSEL, FPDCPWLEditCopyTextSEL, L"FPDCPWLEditCopyText"},
	{FPDCPWLEditSEL, FPDCPWLEditPasteTextSEL, L"FPDCPWLEditPasteText"},
	{FPDCPWLEditSEL, FPDCPWLEditCutTextSEL, L"FPDCPWLEditCutText"},
	{FPDCPWLEditSEL, FPDCPWLEditCanPasteSEL, L"FPDCPWLEditCanPaste"},
	{FPDCPWLEditSEL, FPDCPWLEditGetTextWithBulletSEL, L"FPDCPWLEditGetTextWithBullet"},
	{FPDCPWLEditSEL, FPDCPWLEditCreateNotifySEL, L"FPDCPWLEditCreateNotify"},
	{FPDCPWLEditSEL, FPDCPWLEditDeleteNotifySEL, L"FPDCPWLEditDeleteNotify"},
	{FPDCPWLEditSEL, FPDCPWLEditSetEditNotifySEL, L"FPDCPWLEditSetEditNotify"},
	{FPDCPWLEditSEL, FPDCPWLEditSetFillerNotifySEL, L"FPDCPWLEditSetFillerNotify"},
	{FPDCPWLEditSEL, FPDCPWLEditReplaceSelSEL, L"FPDCPWLEditReplaceSel"},
	{FPDCPWLEditSEL, FPDCPWLEditNew2SEL, L"FPDCPWLEditNew2"},
	{FPDCPWLEditSEL, FPDCPWLEditGetFromWndSEL, L"FPDCPWLEditGetFromWnd"},
	{FPDCPWLEditSEL, FPDCPWLEditSetRichTextIsBoldSEL, L"FPDCPWLEditSetRichTextIsBold"},
	{FPDCPWLEditSEL, FPDCPWLEditSetRichTextIsItalicSEL, L"FPDCPWLEditSetRichTextIsItalic"},
	{FPDCPWLEditSEL, FPDCPWLEditSetRichTextUnderlineSEL, L"FPDCPWLEditSetRichTextUnderline"},
	{FPDCPWLEditSEL, FPDCPWLEditSetRichTextScriptSEL, L"FPDCPWLEditSetRichTextScript"},
	{FPDCPWLEditSEL, FPDCPWLEditCastToEditCtrlSEL, L"FPDCPWLEditCastToEditCtrl"},
	{FPDCPWLEditSEL, FPDCPWLEditIOnSetCaretSEL, L"FPDCPWLEditIOnSetCaret"},
	{FPDCPWLEditSEL, FPDCPWLEditSetCharSetSEL, L"FPDCPWLEditSetCharSet"},
	{FPDCPWLEditSEL, FPDCPWLEditGetCharSetSEL, L"FPDCPWLEditGetCharSet"},
	{FPDCPWLEditSEL, FPDCPWLEditSetCodePageSEL, L"FPDCPWLEditSetCodePage"},
	{FPDCPWLEditSEL, FPDCPWLEditSetInputTextSEL, L"FPDCPWLEditSetInputText"},
	{FPDCPWLEditSEL, FPDCPWLEditGetWindowMatrixSEL, L"FPDCPWLEditGetWindowMatrix"},
	{FPDCPWLEditSEL, FPDCPWLEditGetCaretPosSEL, L"FPDCPWLEditGetCaretPos"},
	{FPDCPWLEditSEL, FPDCPWLEditGetCaretFontSizeSEL, L"FPDCPWLEditGetCaretFontSize"},
	{FPDCPWLEditSEL, FPDCPWLEditIsTextFullSEL, L"FPDCPWLEditIsTextFull"},
	{FPDCPWLEditSEL, FPDCPWLEditSetFontSizeSEL, L"FPDCPWLEditSetFontSize"},
	{FPDCPWLEditSEL, FPDCPWLEditGetFontSizeSEL, L"FPDCPWLEditGetFontSize"},
	{FPDCPWLEditSEL, FPDCPWLEditOnCharSEL, L"FPDCPWLEditOnChar"},
	{FPDCPWLEditSEL, FPDCPWLEditSetRichTextColorSEL, L"FPDCPWLEditSetRichTextColor"},
	{FPDCPWLEditSEL, FPDCPWLEditSetCaretColorSEL, L"FPDCPWLEditSetCaretColor"},
	{FPDCPWLEditSEL, FPDCPWLEditGetTextSEL, L"FPDCPWLEditGetText"},
	{FPDCPWLEditSEL, FPDCPWLEditGetRichTextXMLSEL, L"FPDCPWLEditGetRichTextXML"},
	{FPDCPWLEditSEL, FPDCPWLEditCanUndoSEL, L"FPDCPWLEditCanUndo"},
	{FPDCPWLEditSEL, FPDCPWLEditCanRedoSEL, L"FPDCPWLEditCanRedo"},
	{FPDCPWLEditSEL, FPDCPWLEditSelectAllSEL, L"FPDCPWLEditSelectAll"},
	{FPDCPWLEditSEL, FPDCPWLEditSetRichTextAlignmentSEL, L"FPDCPWLEditSetRichTextAlignment"},
	{FPDCPWLEditSEL, FPDCPWLEditOnLButtonDownSEL, L"FPDCPWLEditOnLButtonDown"},
	{FPDCPWLEditSEL, FPDCPWLEditOnLButtonDblClkSEL, L"FPDCPWLEditOnLButtonDblClk"},
	{FPDCPWLEditSEL, FPDCPWLEditOnRButtonUpSEL, L"FPDCPWLEditOnRButtonUp"},
	{FPDCPWLEditSEL, FPDCPWLEditOnKeyDownSEL, L"FPDCPWLEditOnKeyDown"},
	{FPDCPWLEditSEL, FPDCPWLEditOnMouseMoveSEL, L"FPDCPWLEditOnMouseMove"},
	{FPDCPWLEditSEL, FPDCPWLEditOnLButtonUpSEL, L"FPDCPWLEditOnLButtonUp"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorNextWordSEL, L"FPDVariableTextIteratorNextWord"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorPrevWordSEL, L"FPDVariableTextIteratorPrevWord"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorNextLineSEL, L"FPDVariableTextIteratorNextLine"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorPrevLineSEL, L"FPDVariableTextIteratorPrevLine"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorNextSectionSEL, L"FPDVariableTextIteratorNextSection"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorPrevSectionSEL, L"FPDVariableTextIteratorPrevSection"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorGetWordSEL, L"FPDVariableTextIteratorGetWord"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorSetWordSEL, L"FPDVariableTextIteratorSetWord"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorGetLineSEL, L"FPDVariableTextIteratorGetLine"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorGetSectionSEL, L"FPDVariableTextIteratorGetSection"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorSetSectionSEL, L"FPDVariableTextIteratorSetSection"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorSetAtSEL, L"FPDVariableTextIteratorSetAt"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorSetAtIISEL, L"FPDVariableTextIteratorSetAtII"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorGetAtSEL, L"FPDVariableTextIteratorGetAt"},
	{FPDVariableTextIteratorSEL, FPDVariableTextIteratorGetDisplayWordSEL, L"FPDVariableTextIteratorGetDisplayWord"},
	{FPDVTLineSEL, FPDVTLineNewSEL, L"FPDVTLineNew"},
	{FPDVTLineSEL, FPDVTLineDestroySEL, L"FPDVTLineDestroy"},
	{FPDVTLineSEL, FPDVTLineSetStartWordPlaceSEL, L"FPDVTLineSetStartWordPlace"},
	{FPDVTLineSEL, FPDVTLineGetStartWordPlaceSEL, L"FPDVTLineGetStartWordPlace"},
	{FPDVTLineSEL, FPDVTLineSetEndWordPlaceSEL, L"FPDVTLineSetEndWordPlace"},
	{FPDVTLineSEL, FPDVTLineGetEndWordPlaceSEL, L"FPDVTLineGetEndWordPlace"},
	{FPDVTLineSEL, FPDVTLineSetOriginalPositionSEL, L"FPDVTLineSetOriginalPosition"},
	{FPDVTLineSEL, FPDVTLineGetOriginalPositionSEL, L"FPDVTLineGetOriginalPosition"},
	{FPDVTLineSEL, FPDVTLineSetWidthSEL, L"FPDVTLineSetWidth"},
	{FPDVTLineSEL, FPDVTLineGetWidthSEL, L"FPDVTLineGetWidth"},
	{FPDVTLineSEL, FPDVTLineSetAscentSEL, L"FPDVTLineSetAscent"},
	{FPDVTLineSEL, FPDVTLineGetAscentSEL, L"FPDVTLineGetAscent"},
	{FPDVTLineSEL, FPDVTLineSetDescentSEL, L"FPDVTLineSetDescent"},
	{FPDVTLineSEL, FPDVTLineGetDescentSEL, L"FPDVTLineGetDescent"},
	{FPDVTSectionSEL, FPDVTSectionNewSEL, L"FPDVTSectionNew"},
	{FPDVTSectionSEL, FPDVTSectionDestroySEL, L"FPDVTSectionDestroy"},
	{FPDVTSectionSEL, FPDVTSectionSetStartWordPlaceSEL, L"FPDVTSectionSetStartWordPlace"},
	{FPDVTSectionSEL, FPDVTSectionGetStartWordPlaceSEL, L"FPDVTSectionGetStartWordPlace"},
	{FPDVTSectionSEL, FPDVTSectionSetRectSEL, L"FPDVTSectionSetRect"},
	{FPDVTSectionSEL, FPDVTSectionGetRectSEL, L"FPDVTSectionGetRect"},
	{FPDVTSectionSEL, FPDVTSectionSetSectionPropertiesSEL, L"FPDVTSectionSetSectionProperties"},
	{FPDVTSectionSEL, FPDVTSectionGetSectionPropertiesSEL, L"FPDVTSectionGetSectionProperties"},
	{FPDVTSectionSEL, FPDVTSectionSetWordPropertiesSEL, L"FPDVTSectionSetWordProperties"},
	{FPDVTSectionSEL, FPDVTSectionGetWordPropertiesSEL, L"FPDVTSectionGetWordProperties"},
	{FPDVariableTextSEL, FPDVariableTextNewSEL, L"FPDVariableTextNew"},
	{FPDVariableTextSEL, FPDVariableTextDestroySEL, L"FPDVariableTextDestroy"},
	{FPDVariableTextSEL, FPDVariableTextProviderNewSEL, L"FPDVariableTextProviderNew"},
	{FPDVariableTextSEL, FPDVariableTextProviderDestroySEL, L"FPDVariableTextProviderDestroy"},
	{FPDVariableTextSEL, FPDVariableTextSetProviderSEL, L"FPDVariableTextSetProvider"},
	{FPDVariableTextSEL, FPDVariableTextGetIteratorSEL, L"FPDVariableTextGetIterator"},
	{FPDVariableTextSEL, FPDVariableTextSetPlateRectSEL, L"FPDVariableTextSetPlateRect"},
	{FPDVariableTextSEL, FPDVariableTextIsVerticalWritingSEL, L"FPDVariableTextIsVerticalWriting"},
	{FPDVariableTextSEL, FPDVariableTextSetAlignmentSEL, L"FPDVariableTextSetAlignment"},
	{FPDVariableTextSEL, FPDVariableTextSetPasswordCharSEL, L"FPDVariableTextSetPasswordChar"},
	{FPDVariableTextSEL, FPDVariableTextSetLimitCharSEL, L"FPDVariableTextSetLimitChar"},
	{FPDVariableTextSEL, FPDVariableTextSetCharArraySEL, L"FPDVariableTextSetCharArray"},
	{FPDVariableTextSEL, FPDVariableTextSetCharSpaceSEL, L"FPDVariableTextSetCharSpace"},
	{FPDVariableTextSEL, FPDVariableTextSetWordSpaceSEL, L"FPDVariableTextSetWordSpace"},
	{FPDVariableTextSEL, FPDVariableTextSetHorzScaleSEL, L"FPDVariableTextSetHorzScale"},
	{FPDVariableTextSEL, FPDVariableTextSetMultiLineSEL, L"FPDVariableTextSetMultiLine"},
	{FPDVariableTextSEL, FPDVariableTextSetAutoReturnSEL, L"FPDVariableTextSetAutoReturn"},
	{FPDVariableTextSEL, FPDVariableTextSetAutoFontSizeSEL, L"FPDVariableTextSetAutoFontSize"},
	{FPDVariableTextSEL, FPDVariableTextSetFontSizeSEL, L"FPDVariableTextSetFontSize"},
	{FPDVariableTextSEL, FPDVariableTextSetLineLeadingSEL, L"FPDVariableTextSetLineLeading"},
	{FPDVariableTextSEL, FPDVariableTextSetRichTextSEL, L"FPDVariableTextSetRichText"},
	{FPDVariableTextSEL, FPDVariableTextSetDirectionRTLSEL, L"FPDVariableTextSetDirectionRTL"},
	{FPDVariableTextSEL, FPDVariableTextInitializeSEL, L"FPDVariableTextInitialize"},
	{FPDVariableTextSEL, FPDVariableTextIsValidSEL, L"FPDVariableTextIsValid"},
	{FPDVariableTextSEL, FPDVariableTextIsRichTextSEL, L"FPDVariableTextIsRichText"},
	{FPDVariableTextSEL, FPDVariableTextRearrangeAllSEL, L"FPDVariableTextRearrangeAll"},
	{FPDVariableTextSEL, FPDVariableTextRearrangePartSEL, L"FPDVariableTextRearrangePart"},
	{FPDVariableTextSEL, FPDVariableTextResetAllSEL, L"FPDVariableTextResetAll"},
	{FPDVariableTextSEL, FPDVariableTextSetTextSEL, L"FPDVariableTextSetText"},
	{FPDVariableTextSEL, FPDVariableTextInsertWordSEL, L"FPDVariableTextInsertWord"},
	{FPDVariableTextSEL, FPDVariableTextInsertSectionSEL, L"FPDVariableTextInsertSection"},
	{FPDVariableTextSEL, FPDVariableTextInsertTextSEL, L"FPDVariableTextInsertText"},
	{FPDVariableTextSEL, FPDVariableTextDeleteWordsSEL, L"FPDVariableTextDeleteWords"},
	{FPDVariableTextSEL, FPDVariableTextDeleteWordSEL, L"FPDVariableTextDeleteWord"},
	{FPDVariableTextSEL, FPDVariableTextBackSpaceWordSEL, L"FPDVariableTextBackSpaceWord"},
	{FPDVariableTextSEL, FPDVariableTextGetPlateRectSEL, L"FPDVariableTextGetPlateRect"},
	{FPDVariableTextSEL, FPDVariableTextGetContentRectSEL, L"FPDVariableTextGetContentRect"},
	{FPDVariableTextSEL, FPDVariableTextGetTotalWordsSEL, L"FPDVariableTextGetTotalWords"},
	{FPDVariableTextSEL, FPDVariableTextGetFontSizeSEL, L"FPDVariableTextGetFontSize"},
	{FPDVariableTextSEL, FPDVariableTextGetAlignmentSEL, L"FPDVariableTextGetAlignment"},
	{FPDVariableTextSEL, FPDVariableTextGetWordSpaceSEL, L"FPDVariableTextGetWordSpace"},
	{FPDVariableTextSEL, FPDVariableTextGetPasswordCharSEL, L"FPDVariableTextGetPasswordChar"},
	{FPDVariableTextSEL, FPDVariableTextGetCharArraySEL, L"FPDVariableTextGetCharArray"},
	{FPDVariableTextSEL, FPDVariableTextGetLimitCharSEL, L"FPDVariableTextGetLimitChar"},
	{FPDVariableTextSEL, FPDVariableTextIsMultiLineSEL, L"FPDVariableTextIsMultiLine"},
	{FPDVariableTextSEL, FPDVariableTextIsAutoReturnSEL, L"FPDVariableTextIsAutoReturn"},
	{FPDVariableTextSEL, FPDVariableTextGetHorzScaleSEL, L"FPDVariableTextGetHorzScale"},
	{FPDVariableTextSEL, FPDVariableTextGetCharSpaceSEL, L"FPDVariableTextGetCharSpace"},
	{FPDVariableTextSEL, FPDVariableTextGetBeginWordPlaceSEL, L"FPDVariableTextGetBeginWordPlace"},
	{FPDVariableTextSEL, FPDVariableTextGetEndWordPlaceSEL, L"FPDVariableTextGetEndWordPlace"},
	{FPDVariableTextSEL, FPDVariableTextGetPrevWordPlaceSEL, L"FPDVariableTextGetPrevWordPlace"},
	{FPDVariableTextSEL, FPDVariableTextGetNextWordPlaceSEL, L"FPDVariableTextGetNextWordPlace"},
	{FPDVariableTextSEL, FPDVariableTextSearchWordPlaceSEL, L"FPDVariableTextSearchWordPlace"},
	{FPDVariableTextSEL, FPDVariableTextGetUpWordPlaceSEL, L"FPDVariableTextGetUpWordPlace"},
	{FPDVariableTextSEL, FPDVariableTextGetDownWordPlaceSEL, L"FPDVariableTextGetDownWordPlace"},
	{FPDVariableTextSEL, FPDVariableTextGetLineBeginPlaceSEL, L"FPDVariableTextGetLineBeginPlace"},
	{FPDVariableTextSEL, FPDVariableTextGetLineEndPlaceSEL, L"FPDVariableTextGetLineEndPlace"},
	{FPDVariableTextSEL, FPDVariableTextGetSectionBeginPlaceSEL, L"FPDVariableTextGetSectionBeginPlace"},
	{FPDVariableTextSEL, FPDVariableTextGetSectionEndPlaceSEL, L"FPDVariableTextGetSectionEndPlace"},
	{FPDVariableTextSEL, FPDVariableTextUpdateWordPlaceSEL, L"FPDVariableTextUpdateWordPlace"},
	{FPDVariableTextSEL, FPDVariableTextAjustLineHeaderSEL, L"FPDVariableTextAjustLineHeader"},
	{FPDVariableTextSEL, FPDVariableTextWordPlaceToWordIndexSEL, L"FPDVariableTextWordPlaceToWordIndex"},
	{FPDVariableTextSEL, FPDVariableTextWordIndexToWordPlaceSEL, L"FPDVariableTextWordIndexToWordPlace"},
	{FPDVariableTextSEL, FPDVariableTextIsSectionComplexScriptSEL, L"FPDVariableTextIsSectionComplexScript"},
	{FPDVariableTextSEL, FPDVariableTextIsVerticalFontSEL, L"FPDVariableTextIsVerticalFont"},
	{FPDEDITFontDataSEL, FPDEDITFontDataNewSEL, L"FPDEDITFontDataNew"},
	{FPDEDITFontDataSEL, FPDEDITFontDataDestroySEL, L"FPDEDITFontDataDestroy"},
	{FPDEDITFontDataSEL, FPDEDITFontDataSetFontSEL, L"FPDEDITFontDataSetFont"},
	{FPDEDITFontDataSEL, FPDEDITFontDataGetFontSEL, L"FPDEDITFontDataGetFont"},
	{FPDEDITFontDataSEL, FPDEDITFontDataSetFontNameSEL, L"FPDEDITFontDataSetFontName"},
	{FPDEDITFontDataSEL, FPDEDITFontDataGetFontNameSEL, L"FPDEDITFontDataGetFontName"},
	{FPDBulletWordIteratorSEL, FPDBulletWordIteratorSetBeginBulletWordPosSEL, L"FPDBulletWordIteratorSetBeginBulletWordPos"},
	{FPDBulletWordIteratorSEL, FPDBulletWordIteratorNextBulletWordSEL, L"FPDBulletWordIteratorNextBulletWord"},
	{FPDBulletWordIteratorSEL, FPDBulletWordIteratorGetBulletWordSEL, L"FPDBulletWordIteratorGetBulletWord"},
	{FPDBulletWordIteratorSEL, FPDBulletWordIteratorSetBulletWordSEL, L"FPDBulletWordIteratorSetBulletWord"},
	{FPDBulletWordIteratorSEL, FPDBulletWordIteratorGetBulletDisplayWordSEL, L"FPDBulletWordIteratorGetBulletDisplayWord"},
	{FPDBulletWordIteratorSEL, FPDBulletWordIteratorGetBeginBulletWordPosSEL, L"FPDBulletWordIteratorGetBeginBulletWordPos"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceNewSEL, L"FPDVTWordPlaceNew"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceDestroySEL, L"FPDVTWordPlaceDestroy"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceSetDefaultSEL, L"FPDVTWordPlaceSetDefault"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceEqualSEL, L"FPDVTWordPlaceEqual"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceWordCmpSEL, L"FPDVTWordPlaceWordCmp"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceLineCmpSEL, L"FPDVTWordPlaceLineCmp"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceSecCmpSEL, L"FPDVTWordPlaceSecCmp"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceSetSectionIndexSEL, L"FPDVTWordPlaceSetSectionIndex"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceGetSectionIndexSEL, L"FPDVTWordPlaceGetSectionIndex"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceSetLineIndexSEL, L"FPDVTWordPlaceSetLineIndex"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceGetLineIndexSEL, L"FPDVTWordPlaceGetLineIndex"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceSetWordIndexSEL, L"FPDVTWordPlaceSetWordIndex"},
	{FPDVTWordPlaceSEL, FPDVTWordPlaceGetWordIndexSEL, L"FPDVTWordPlaceGetWordIndex"},
	{FPDEDITFONTDATAArraySEL, FPDEDITFONTDATAArrayCreateSEL, L"FPDEDITFONTDATAArrayCreate"},
	{FPDEDITFONTDATAArraySEL, FPDEDITFONTDATAArrayDeleteSEL, L"FPDEDITFONTDATAArrayDelete"},
	{FPDEDITFONTDATAArraySEL, FPDEDITFONTDATAArrayGetSizeSEL, L"FPDEDITFONTDATAArrayGetSize"},
	{FPDEDITFONTDATAArraySEL, FPDEDITFONTDATAArrayGetDataSEL, L"FPDEDITFONTDATAArrayGetData"},
	{FPDEDITFONTDATAArraySEL, FPDEDITFONTDATAArrayRemoveAtSEL, L"FPDEDITFONTDATAArrayRemoveAt"},
	{FPDEDITFONTDATAArraySEL, FPDEDITFONTDATAArrayRemoveAllSEL, L"FPDEDITFONTDATAArrayRemoveAll"},
	{FPDVTBulletIteratorSEL, FPDVTBulletIteratorNextBulletSEL, L"FPDVTBulletIteratorNextBullet"},
	{FPDVTBulletIteratorSEL, FPDVTBulletIteratorGetBulletSEL, L"FPDVTBulletIteratorGetBullet"},
	{FPDVTBulletIteratorSEL, FPDVTBulletIteratorSetBeginnIndexSEL, L"FPDVTBulletIteratorSetBeginnIndex"},
	{FPDVTBulletIteratorSEL, FPDVTBulletIteratorGetCurIndexSEL, L"FPDVTBulletIteratorGetCurIndex"},
	{FPDTextListSEL, FPDTextListGetChildItemSEL, L"FPDTextListGetChildItem"},
	{FPDTextListSEL, FPDTextListReCalculateLableWidthSEL, L"FPDTextListReCalculateLableWidth"},
	{FPDTextListSEL, FPDTextListGetNextSiblingItemSEL, L"FPDTextListGetNextSiblingItem"},
	{FPDPWLFillerNotifySEL, FPDPWLFillerNotifyCreateSEL, L"FPDPWLFillerNotifyCreate"},
	{FPDPWLFillerNotifySEL, FPDPWLFillerNotifyDeleteSEL, L"FPDPWLFillerNotifyDelete"},
	{FPDListSEL, FPDListSetDirectionRTLSEL, L"FPDListSetDirectionRTL"},
	{FPDListSEL, FPDListSetAlignmentSEL, L"FPDListSetAlignment"},
	{FPDListSEL, FPDListGetAlignmentSEL, L"FPDListGetAlignment"},
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
	{FPDFMFontMgrSEL, FPDFMFontMgrGetSEL, L"FPDFMFontMgrGet"},
	{FPDFMFontMgrSEL, FPDFMFontMgrGetCodePageFromCharsetSEL, L"FPDFMFontMgrGetCodePageFromCharset"},
	{FPDFMFontMgrSEL, FPDFMFontMgrSetPlatformLanguageSEL, L"FPDFMFontMgrSetPlatformLanguage"},
	{FPDFMFontMgrSEL, FPDFMFontMgrLoadSystemFontsSEL, L"FPDFMFontMgrLoadSystemFonts"},
	{FPDFMFontMgrSEL, FPDFMFontMgrGetFontDescArraySEL, L"FPDFMFontMgrGetFontDescArray"},
	{FPDFMFontDescriptorSEL, FPDFMFontDescriptorCreateSEL, L"FPDFMFontDescriptorCreate"},
	{FPDFMFontDescriptorSEL, FPDFMFontDescriptorDeleteSEL, L"FPDFMFontDescriptorDelete"},
	{FPDFMFontDescriptorSEL, FPDFMFontDescriptorGetFamiliyNameSEL, L"FPDFMFontDescriptorGetFamiliyName"},
	{FPDFMFontDescriptorSEL, FPDFMFontDescriptorSetFamiliyNameSEL, L"FPDFMFontDescriptorSetFamiliyName"},
	{FPDFMFontDescriptorSEL, FPDFMFontDescriptorGetPostscriptNameSEL, L"FPDFMFontDescriptorGetPostscriptName"},
	{FPDFMFontDescriptorSEL, FPDFMFontDescriptorSetPostscriptNameSEL, L"FPDFMFontDescriptorSetPostscriptName"},
	{FPDFMFontDescriptorSEL, FPDFMFontDescriptorGetFullNameSEL, L"FPDFMFontDescriptorGetFullName"},
	{FPDFMFontDescriptorSEL, FPDFMFontDescriptorSetFullNameSEL, L"FPDFMFontDescriptorSetFullName"},
	{FPDFMFontDescriptorSEL, FPDFMFontDescriptorGetBsFamilyNameSEL, L"FPDFMFontDescriptorGetBsFamilyName"},
	{FPDFMFontDescriptorSEL, FPDFMFontDescriptorSetBsFamilyNameSEL, L"FPDFMFontDescriptorSetBsFamilyName"},
	{FPDFMFontDescriptorSEL, FPDFMFontDescriptorGetCharsetSEL, L"FPDFMFontDescriptorGetCharset"},
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
	{FPDJSEngineSEL, FPDJSEngineGetJSEngineSEL, L"FPDJSEngineGetJSEngine"},
	{FPDJSEngineSEL, FPDJSEngineRunFieldCalculateSEL, L"FPDJSEngineRunFieldCalculate"},
	{FPDJSEngineSEL, FPDJSEngineGetAppProviderSEL, L"FPDJSEngineGetAppProvider"},
	{FPDJSEngineSEL, FPDJSEngineGetDocJSRuntimeSEL, L"FPDJSEngineGetDocJSRuntime"},
	{FPDJSEngineSEL, FPDJSEngineSetJSRuntimeSEL, L"FPDJSEngineSetJSRuntime"},
	{FPDJSEngineSEL, FPDJSEngineReleaseJSEngineSEL, L"FPDJSEngineReleaseJSEngine"},
	{FPDJSEngineSEL, FPDJSEngineRunDocJavaScriptSEL, L"FPDJSEngineRunDocJavaScript"},
	{FPDJSEngineSEL, FPDJSEngineRunFieldJavaScriptSEL, L"FPDJSEngineRunFieldJavaScript"},
	{FPDJSEngineSEL, FPDJSEngineRunFieldFormatSEL, L"FPDJSEngineRunFieldFormat"},
	{FPDJSEngineSEL, FPDJSEngineRunLinkJavaScriptSEL, L"FPDJSEngineRunLinkJavaScript"},
	{FPDJSEngineSEL, FPDJSEngineRunOutsideEnvSEL, L"FPDJSEngineRunOutsideEnv"},
	{FPDJSAppProviderSEL, FPDJSAppProviderGetReaderDocumentSEL, L"FPDJSAppProviderGetReaderDocument"},
	{FPDJSAppProviderSEL, FPDJSAppProviderJSSetValueNotifySEL, L"FPDJSAppProviderJSSetValueNotify"},
	{FPDJSAppProviderSEL, FPDJSAppProviderExecuteNamedActionSEL, L"FPDJSAppProviderExecuteNamedAction"},
	{FPDJSAppProviderSEL, FPDJSAppProviderOpenURLSEL, L"FPDJSAppProviderOpenURL"},
	{FPDJSRuntimeSEL, FPDJSRuntimeNewContextSEL, L"FPDJSRuntimeNewContext"},
	{FPDJSRuntimeSEL, FPDJSRuntimeReleaseContextSEL, L"FPDJSRuntimeReleaseContext"},
	{FPDJSRuntimeSEL, FPDJSRuntimeSetReaderDocumentSEL, L"FPDJSRuntimeSetReaderDocument"},
	{FPDJSContextSEL, FPDJSContextOnField_CalculateSEL, L"FPDJSContextOnField_Calculate"},
	{FPDJSContextSEL, FPDJSContextRunScriptSEL, L"FPDJSContextRunScript"},
	{FPDJSContextSEL, FPDJSContextOnDocOpenSEL, L"FPDJSContextOnDocOpen"},
	{FPDJSFieldActionSEL, FPDJSFieldActionNewSEL, L"FPDJSFieldActionNew"},
	{FPDJSFieldActionSEL, FPDJSFieldActionDeleteSEL, L"FPDJSFieldActionDelete"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetbModifierSEL, L"FPDJSFieldActionGetbModifier"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetbModifierSEL, L"FPDJSFieldActionSetbModifier"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetbShiftSEL, L"FPDJSFieldActionGetbShift"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetbShiftSEL, L"FPDJSFieldActionSetbShift"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetCommitKeySEL, L"FPDJSFieldActionGetCommitKey"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetCommitKeySEL, L"FPDJSFieldActionSetCommitKey"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetChangeSEL, L"FPDJSFieldActionGetChange"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetChangeSEL, L"FPDJSFieldActionSetChange"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetChangeExSEL, L"FPDJSFieldActionGetChangeEx"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetChangeExSEL, L"FPDJSFieldActionSetChangeEx"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetbKeyDownSEL, L"FPDJSFieldActionGetbKeyDown"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetbKeyDownSEL, L"FPDJSFieldActionSetbKeyDown"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetSelEndSEL, L"FPDJSFieldActionGetSelEnd"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetSelEndSEL, L"FPDJSFieldActionSetSelEnd"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetSelStartSEL, L"FPDJSFieldActionGetSelStart"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetSelStartSEL, L"FPDJSFieldActionSetSelStart"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetValueSEL, L"FPDJSFieldActionGetValue"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetValueSEL, L"FPDJSFieldActionSetValue"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetbWillCommitSEL, L"FPDJSFieldActionGetbWillCommit"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetbWillCommitSEL, L"FPDJSFieldActionSetbWillCommit"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetbFieldFullSEL, L"FPDJSFieldActionGetbFieldFull"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetbFieldFullSEL, L"FPDJSFieldActionSetbFieldFull"},
	{FPDJSFieldActionSEL, FPDJSFieldActionGetbRCSEL, L"FPDJSFieldActionGetbRC"},
	{FPDJSFieldActionSEL, FPDJSFieldActionSetbRCSEL, L"FPDJSFieldActionSetbRC"},
	{FPDJSDocumentProviderSEL, FPDJSDocumentProviderGetInterFormSEL, L"FPDJSDocumentProviderGetInterForm"},
	{FPDJSFormProviderSEL, FPDJSFormProviderSubmitFormSEL, L"FPDJSFormProviderSubmitForm"},
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
	{FPDLRAnalysisOptionsSEL, FPDLRAnalysisOptionsSetOptionStringSEL, L"FPDLRAnalysisOptionsSetOptionString"},
	{FPDLRAnalysisOptionsSEL, FPDLRAnalysisOptionsGetSupportedOptionsSEL, L"FPDLRAnalysisOptionsGetSupportedOptions"},
	{FPDLRAnalysisOptionsSEL, FPDLRAnalysisOptionsSetOptionIntegerSEL, L"FPDLRAnalysisOptionsSetOptionInteger"},
	{FPDLRAnalysisOptionsSEL, FPDLRAnalysisOptionsSetOptionFloatSEL, L"FPDLRAnalysisOptionsSetOptionFloat"},
	{FPDLRAnalysisOptionsSEL, FPDLRAnalysisOptionsSetOptionBooleanSEL, L"FPDLRAnalysisOptionsSetOptionBoolean"},
	{FPDLRAnalysisOptionsSEL, FPDLRAnalysisOptionsSetOptionFloatRectSEL, L"FPDLRAnalysisOptionsSetOptionFloatRect"},
	{FPDLRAnalysisOptionsSEL, FPDLRAnalysisOptionsSetOptionOCContextSEL, L"FPDLRAnalysisOptionsSetOptionOCContext"},
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
	{FPDMathGraphicsSEL, FPDMathGraphicsGetGraphicsSEL, L"FPDMathGraphicsGetGraphics"},
	{FPDMathGraphicsSEL, FPDMathGraphicsDifferenceSEL, L"FPDMathGraphicsDifference"},
	{FPDMathGraphicsSEL, FPDMathGraphicsIntersectionSEL, L"FPDMathGraphicsIntersection"},
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
	{FPDPathDataSEL, FPDPathDataNewSEL, L"FPDPathDataNew"},
	{FPDPathDataSEL, FPDPathDataNew2SEL, L"FPDPathDataNew2"},
	{FPDPathDataSEL, FPDPathDataDestrotySEL, L"FPDPathDataDestroty"},
	{FPDPathDataSEL, FPDPathDataGetPointCountSEL, L"FPDPathDataGetPointCount"},
	{FPDPathDataSEL, FPDPathDataGetFlagSEL, L"FPDPathDataGetFlag"},
	{FPDPathDataSEL, FPDPathDataGetPointXSEL, L"FPDPathDataGetPointX"},
	{FPDPathDataSEL, FPDPathDataGetPointYSEL, L"FPDPathDataGetPointY"},
	{FPDPathDataSEL, FPDPathDataGetPointSEL, L"FPDPathDataGetPoint"},
	{FPDPathDataSEL, FPDPathDataSetPointCountSEL, L"FPDPathDataSetPointCount"},
	{FPDPathDataSEL, FPDPathDataAllocPointCountSEL, L"FPDPathDataAllocPointCount"},
	{FPDPathDataSEL, FPDPathDataAddPointCountSEL, L"FPDPathDataAddPointCount"},
	{FPDPathDataSEL, FPDPathDataGetBoundingBoxSEL, L"FPDPathDataGetBoundingBox"},
	{FPDPathDataSEL, FPDPathDataGetBoundingBox2SEL, L"FPDPathDataGetBoundingBox2"},
	{FPDPathDataSEL, FPDPathDataTransformSEL, L"FPDPathDataTransform"},
	{FPDPathDataSEL, FPDPathDataAppendSEL, L"FPDPathDataAppend"},
	{FPDPathDataSEL, FPDPathDataAppendRectSEL, L"FPDPathDataAppendRect"},
	{FPDPathDataSEL, FPDPathDataSetPointSEL, L"FPDPathDataSetPoint"},
	{FPDPathDataSEL, FPDPathDataTrimPointsSEL, L"FPDPathDataTrimPoints"},
	{FPDPathDataSEL, FPDPathDataCopySEL, L"FPDPathDataCopy"},
	{FPDPathDataSEL, FPDPathDataIsRectSEL, L"FPDPathDataIsRect"},
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
	{FPDSyntaxParserSEL, FPDSyntaxParserNewSEL, L"FPDSyntaxParserNew"},
	{FPDSyntaxParserSEL, FPDSyntaxParserDestroySEL, L"FPDSyntaxParserDestroy"},
	{FPDSyntaxParserSEL, FPDSyntaxParserInitParserSEL, L"FPDSyntaxParserInitParser"},
	{FPDSyntaxParserSEL, FPDSyntaxParserGetObjectSEL, L"FPDSyntaxParserGetObject"},
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
	{FPDFXGInkPathSEL, FPDFXGInkPathAddPointSEL, L"FPDFXGInkPathAddPoint"},
	{FPDFXGInkPathSEL, FPDFXGInkPathGeneratePSISEL, L"FPDFXGInkPathGeneratePSI"},
	{FPDFXGPaintModuleMgrSEL, FPDFXGPaintModuleMgrCreateSEL, L"FPDFXGPaintModuleMgrCreate"},
	{FPDFXGPaintModuleMgrSEL, FPDFXGPaintModuleMgrDestroySEL, L"FPDFXGPaintModuleMgrDestroy"},
	{FPDFXGPaintModuleMgrSEL, FPDFXGPaintModuleMgrGetCanvasSEL, L"FPDFXGPaintModuleMgrGetCanvas"},
	{FPDFXGPaintModuleMgrSEL, FPDFXGPaintModuleMgrGetPaintSEL, L"FPDFXGPaintModuleMgrGetPaint"},
	{FPDFXGPaintModuleMgrSEL, FPDFXGPaintModuleMgrSetCacheLimitSEL, L"FPDFXGPaintModuleMgrSetCacheLimit"},
	{FPDFXGPaintModuleMgrSEL, FPDFXGPaintModuleMgrCreatePaintNibSEL, L"FPDFXGPaintModuleMgrCreatePaintNib"},
	{FPDFXGPaintModuleMgrSEL, FPDFXGPaintModuleMgrDestroyPaintNibSEL, L"FPDFXGPaintModuleMgrDestroyPaintNib"},
	{FPDFXGPaintModuleMgrSEL, FPDFXGPaintModuleMgrLoadPaintNibSEL, L"FPDFXGPaintModuleMgrLoadPaintNib"},
	{FPDFXGPaintModuleMgrSEL, FPDFXGPaintModuleMgrSavePaintNibSEL, L"FPDFXGPaintModuleMgrSavePaintNib"},
	{FPDFXGPaintModuleMgrSEL, FPDFXGPaintModuleMgrListAllPaintNibSEL, L"FPDFXGPaintModuleMgrListAllPaintNib"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsSetbFlipXSEL, L"FPDFXGNIBParamsSetbFlipX"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsSetbFlipYSEL, L"FPDFXGNIBParamsSetbFlipY"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsCreateSEL, L"FPDFXGNIBParamsCreate"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsDeleteSEL, L"FPDFXGNIBParamsDelete"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsGetDiameterSEL, L"FPDFXGNIBParamsGetDiameter"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsSetDiameterSEL, L"FPDFXGNIBParamsSetDiameter"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsGetbFlipXSEL, L"FPDFXGNIBParamsGetbFlipX"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsGetbFlipYSEL, L"FPDFXGNIBParamsGetbFlipY"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsGetAngleSEL, L"FPDFXGNIBParamsGetAngle"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsSetAngleSEL, L"FPDFXGNIBParamsSetAngle"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsGetRoundnessSEL, L"FPDFXGNIBParamsGetRoundness"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsSetRoundnessSEL, L"FPDFXGNIBParamsSetRoundness"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsGetDashScaleSEL, L"FPDFXGNIBParamsGetDashScale"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsSetDashScaleSEL, L"FPDFXGNIBParamsSetDashScale"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsGetHardnessSEL, L"FPDFXGNIBParamsGetHardness"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsSetHardnessSEL, L"FPDFXGNIBParamsSetHardness"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsGetPathSEL, L"FPDFXGNIBParamsGetPath"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsSetPathSEL, L"FPDFXGNIBParamsSetPath"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsGetPatternSEL, L"FPDFXGNIBParamsGetPattern"},
	{FPDFXGNIBParamsSEL, FPDFXGNIBParamsSetPatternSEL, L"FPDFXGNIBParamsSetPattern"},
	{FPDFXGCanvasSEL, FPDFXGCanvasCreateSEL, L"FPDFXGCanvasCreate"},
	{FPDFXGCanvasSEL, FPDFXGCanvasDestroySEL, L"FPDFXGCanvasDestroy"},
	{FPDFXGCanvasSEL, FPDFXGCanvasSetFilterNotifySEL, L"FPDFXGCanvasSetFilterNotify"},
	{FPDFXGCanvasSEL, FPDFXGCanvasAttachLayerSEL, L"FPDFXGCanvasAttachLayer"},
	{FPDFXGCanvasSEL, FPDFXGCanvasCreateLayerSEL, L"FPDFXGCanvasCreateLayer"},
	{FPDFXGCanvasSEL, FPDFXGCanvasSetFGColorSEL, L"FPDFXGCanvasSetFGColor"},
	{FPDFXGCanvasSEL, FPDFXGCanvasSetBGColorSEL, L"FPDFXGCanvasSetBGColor"},
	{FPDFXGCanvasSEL, FPDFXGCanvasSetActiveChannelSEL, L"FPDFXGCanvasSetActiveChannel"},
	{FPDFXGCanvasSEL, FPDFXGCanvasGetFilterNotifySEL, L"FPDFXGCanvasGetFilterNotify"},
	{FPDFXGCanvasSEL, FPDFXGCanvasGetLayerSEL, L"FPDFXGCanvasGetLayer"},
	{FPDFXGCanvasSEL, FPDFXGCanvasGetFGColorSEL, L"FPDFXGCanvasGetFGColor"},
	{FPDFXGCanvasSEL, FPDFXGCanvasGetBGColorSEL, L"FPDFXGCanvasGetBGColor"},
	{FPDFXGCanvasSEL, FPDFXGCanvasGetActiveChannelSEL, L"FPDFXGCanvasGetActiveChannel"},
	{FPDFXGCanvasSEL, FPDFXGCanvasCreateFilterNofitySEL, L"FPDFXGCanvasCreateFilterNofity"},
	{FPDFXGCanvasSEL, FPDFXGCanvasDeleteFilterNofitySEL, L"FPDFXGCanvasDeleteFilterNofity"},
	{FPDFXGPaintNibSEL, FPDFXGPaintNibGetTypeSEL, L"FPDFXGPaintNibGetType"},
	{FPDFXGPaintNibSEL, FPDFXGPaintNibGetNibSEL, L"FPDFXGPaintNibGetNib"},
	{FPDFXGPaintNibSEL, FPDFXGPaintNibGetNameSEL, L"FPDFXGPaintNibGetName"},
	{FPDFXGPaintNibSEL, FPDFXGPaintNibGetParamsSEL, L"FPDFXGPaintNibGetParams"},
	{FPDFXGPaintRenderOptionSEL, FPDFXGPaintRenderOptionCreateSEL, L"FPDFXGPaintRenderOptionCreate"},
	{FPDFXGPaintRenderOptionSEL, FPDFXGPaintRenderOptionDestroySEL, L"FPDFXGPaintRenderOptionDestroy"},
	{FPDFXGPaintRenderOptionSEL, FPDFXGPaintRenderOptionGetBlendModeSEL, L"FPDFXGPaintRenderOptionGetBlendMode"},
	{FPDFXGPaintRenderOptionSEL, FPDFXGPaintRenderOptionGetOpacitySEL, L"FPDFXGPaintRenderOptionGetOpacity"},
	{FPDFXGPaintRenderOptionSEL, FPDFXGPaintRenderOptionGetFlowSEL, L"FPDFXGPaintRenderOptionGetFlow"},
	{FPDFXGPaintRenderOptionSEL, FPDFXGPaintRenderOptionGetAutoEraseSEL, L"FPDFXGPaintRenderOptionGetAutoErase"},
	{FPDFXGPaintSEL, FPDFXGPaintGetPaintTypeSEL, L"FPDFXGPaintGetPaintType"},
	{FPDFXGPaintSEL, FPDFXGPaintGetInkPathSEL, L"FPDFXGPaintGetInkPath"},
	{FPDFXGPaintSEL, FPDFXGPaintAddPathFilterSEL, L"FPDFXGPaintAddPathFilter"},
	{FPDFXGPaintSEL, FPDFXGPaintRemovePathFilterSEL, L"FPDFXGPaintRemovePathFilter"},
	{FPDFXGPaintSEL, FPDFXGPaintGetPaintNibSEL, L"FPDFXGPaintGetPaintNib"},
	{FPDFXGPaintSEL, FPDFXGPaintSetPaintNibSEL, L"FPDFXGPaintSetPaintNib"},
	{FPDFXGPaintSEL, FPDFXGPaintSetRenderOptionSEL, L"FPDFXGPaintSetRenderOption"},
	{FPDFXGPaintSEL, FPDFXGPaintGetFilterTypeSEL, L"FPDFXGPaintGetFilterType"},
	{FPDFXGPaintSEL, FPDFXGPaintSetCanvasSEL, L"FPDFXGPaintSetCanvas"},
	{FPDFXGPaintSEL, FPDFXGPaintGetCanvasSEL, L"FPDFXGPaintGetCanvas"},
	{FPDFXGPaintSEL, FPDFXGPaintPrepareSEL, L"FPDFXGPaintPrepare"},
	{FPDFXGPaintSEL, FPDFXGPaintRenderSEL, L"FPDFXGPaintRender"},
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
	{FPDCPWLListBoxSEL, FPDCPWLListBoxNewSEL, L"FPDCPWLListBoxNew"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxDeleteSEL, L"FPDCPWLListBoxDelete"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxCastToCPWLWndSEL, L"FPDCPWLListBoxCastToCPWLWnd"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxAddStringSEL, L"FPDCPWLListBoxAddString"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxGetTopVisibleIndexSEL, L"FPDCPWLListBoxGetTopVisibleIndex"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxSelectSEL, L"FPDCPWLListBoxSelect"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxSetTopVisibleIndexSEL, L"FPDCPWLListBoxSetTopVisibleIndex"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxSetSelectBackColorSEL, L"FPDCPWLListBoxSetSelectBackColor"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxSetSelectTextColorSEL, L"FPDCPWLListBoxSetSelectTextColor"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxGetCurSelSEL, L"FPDCPWLListBoxGetCurSel"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxGetCountSEL, L"FPDCPWLListBoxGetCount"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxIsItemSelectedSEL, L"FPDCPWLListBoxIsItemSelected"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxGetFontSizeSEL, L"FPDCPWLListBoxGetFontSize"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxSetCaretSEL, L"FPDCPWLListBoxSetCaret"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxCastToWndSEL, L"FPDCPWLListBoxCastToWnd"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxGetFromWndSEL, L"FPDCPWLListBoxGetFromWnd"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxGetTextSEL, L"FPDCPWLListBoxGetText"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxSetFillerNotifySEL, L"FPDCPWLListBoxSetFillerNotify"},
	{FPDCPWLListBoxSEL, FPDCPWLListBoxGetControlListSEL, L"FPDCPWLListBoxGetControlList"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxNewSEL, L"FPDCPWLComboBoxNew"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxDeleteSEL, L"FPDCPWLComboBoxDelete"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxAddStringSEL, L"FPDCPWLComboBoxAddString"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxGetSelectSEL, L"FPDCPWLComboBoxGetSelect"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxSetSelectSEL, L"FPDCPWLComboBoxSetSelect"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxGetLastSelectSEL, L"FPDCPWLComboBoxGetLastSelect"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxGetTextSEL, L"FPDCPWLComboBoxGetText"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxSetTextSEL, L"FPDCPWLComboBoxSetText"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxSelectAllSEL, L"FPDCPWLComboBoxSelectAll"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxGetListFontSizeSEL, L"FPDCPWLComboBoxGetListFontSize"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxCastToWndSEL, L"FPDCPWLComboBoxCastToWnd"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxGetFromWndSEL, L"FPDCPWLComboBoxGetFromWnd"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxSetEditSelSEL, L"FPDCPWLComboBoxSetEditSel"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxGetEditSelSEL, L"FPDCPWLComboBoxGetEditSel"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxSetFillerNotifySEL, L"FPDCPWLComboBoxSetFillerNotify"},
	{FPDCPWLComboBoxSEL, FPDCPWLComboBoxGetEditSEL, L"FPDCPWLComboBoxGetEdit"},
	{FPDCPWLCheckBoxSEL, FPDCPWLCheckBoxNewSEL, L"FPDCPWLCheckBoxNew"},
	{FPDCPWLCheckBoxSEL, FPDCPWLCheckBoxDeleteSEL, L"FPDCPWLCheckBoxDelete"},
	{FPDCPWLCheckBoxSEL, FPDCPWLCheckBoxSetCheckSEL, L"FPDCPWLCheckBoxSetCheck"},
	{FPDCPWLCheckBoxSEL, FPDCPWLCheckBoxIsCheckedSEL, L"FPDCPWLCheckBoxIsChecked"},
	{FPDCPWLCheckBoxSEL, FPDCPWLCheckBoxCastToWndSEL, L"FPDCPWLCheckBoxCastToWnd"},
	{FPDCPWLCheckBoxSEL, FPDCPWLCheckBoxGetFromWndSEL, L"FPDCPWLCheckBoxGetFromWnd"},
	{FPDCPWLRadioButtonSEL, FPDCPWLRadioButtonNewSEL, L"FPDCPWLRadioButtonNew"},
	{FPDCPWLRadioButtonSEL, FPDCPWLRadioButtonDeleteSEL, L"FPDCPWLRadioButtonDelete"},
	{FPDCPWLRadioButtonSEL, FPDCPWLRadioButtonSetCheckSEL, L"FPDCPWLRadioButtonSetCheck"},
	{FPDCPWLRadioButtonSEL, FPDCPWLRadioButtonIsCheckedSEL, L"FPDCPWLRadioButtonIsChecked"},
	{FPDCPWLRadioButtonSEL, FPDCPWLRadioButtonCastToWndSEL, L"FPDCPWLRadioButtonCastToWnd"},
	{FPDCPWLRadioButtonSEL, FPDCPWLRadioButtonGetFromWndSEL, L"FPDCPWLRadioButtonGetFromWnd"},
	{FPDCPWLPushButtonSEL, FPDCPWLPushButtonNewSEL, L"FPDCPWLPushButtonNew"},
	{FPDCPWLPushButtonSEL, FPDCPWLPushButtonDeleteSEL, L"FPDCPWLPushButtonDelete"},
	{FPDCPWLPushButtonSEL, FPDCPWLPushButtonCastToWndSEL, L"FPDCPWLPushButtonCastToWnd"},
	{FPDCPWLPushButtonSEL, FPDCPWLPushButtonGetFromWndSEL, L"FPDCPWLPushButtonGetFromWnd"},
	{FPDCPWLIconSEL, FPDCPWLIconNewSEL, L"FPDCPWLIconNew"},
	{FPDCPWLIconSEL, FPDCPWLIconDeleteSEL, L"FPDCPWLIconDelete"},
	{FPDCPWLIconSEL, FPDCPWLIconGetScaleMethodSEL, L"FPDCPWLIconGetScaleMethod"},
	{FPDCPWLIconSEL, FPDCPWLIconIsProportionalScaleSEL, L"FPDCPWLIconIsProportionalScale"},
	{FPDCPWLIconSEL, FPDCPWLIconGetIconPositionSEL, L"FPDCPWLIconGetIconPosition"},
	{FPDCPWLIconSEL, FPDCPWLIconGetFittingBoundsSEL, L"FPDCPWLIconGetFittingBounds"},
	{FPDCPWLIconSEL, FPDCPWLIconSetIconFitSEL, L"FPDCPWLIconSetIconFit"},
	{FPDCPWLIconSEL, FPDCPWLIconCastToImageSEL, L"FPDCPWLIconCastToImage"},
	{FPDCPWLEditCtrlSEL, FPDCPWLEditCtrlNewSEL, L"FPDCPWLEditCtrlNew"},
	{FPDCPWLEditCtrlSEL, FPDCPWLEditCtrlDeleteSEL, L"FPDCPWLEditCtrlDelete"},
	{FPDCPWLEditCtrlSEL, FPDCPWLEditCtrlCastToWndSEL, L"FPDCPWLEditCtrlCastToWnd"},
	{FPDCPWLEditCtrlSEL, FPDCPWLEditCtrlGetCharSetSEL, L"FPDCPWLEditCtrlGetCharSet"},
	{FPDCPWLEditCtrlSEL, FPDCPWLEditCtrlGetFromWndSEL, L"FPDCPWLEditCtrlGetFromWnd"},
	{FPDCPWLEditCtrlSEL, FPDCPWLEditCtrlGetCaretSEL, L"FPDCPWLEditCtrlGetCaret"},
	{FPDCPWLEditCtrlSEL, FPDCPWLEditCtrlLoadCurrentWordPropsSEL, L"FPDCPWLEditCtrlLoadCurrentWordProps"},
	{FPDCPWLEditCtrlSEL, FPDCPWLEditCtrlIsCJKSEL, L"FPDCPWLEditCtrlIsCJK"},
	{FPDCPWLEditCtrlSEL, FPDCPWLEditCtrlGetCaretPosSEL, L"FPDCPWLEditCtrlGetCaretPos"},
	{FPDSpellCheckSEL, FPDSpellCheckNewSEL, L"FPDSpellCheckNew"},
	{FPDSpellCheckSEL, FPDSpellCheckDeleteSEL, L"FPDSpellCheckDelete"},
	{FPDSpellCheckSEL, FPDSpellCheckCheckWordSEL, L"FPDSpellCheckCheckWord"},
	{FPDSpellCheckSEL, FPDSpellCheckSuggestWordsSEL, L"FPDSpellCheckSuggestWords"},
	{FPDSpellCheckSEL, FPDSpellCheckIsCurSCSupWordSEL, L"FPDSpellCheckIsCurSCSupWord"},
	{FPDSpellCheckSEL, FPDSpellCheckIsSCAvalibleSEL, L"FPDSpellCheckIsSCAvalible"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureNewSEL, L"FPDCPWLSignatureNew"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureDeleteSEL, L"FPDCPWLSignatureDelete"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureSetIconTextSEL, L"FPDCPWLSignatureSetIconText"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureSetDescriptionSEL, L"FPDCPWLSignatureSetDescription"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureSetImageSEL, L"FPDCPWLSignatureSetImage"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureSetImageStreamSEL, L"FPDCPWLSignatureSetImageStream"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureSetTextFlagSEL, L"FPDCPWLSignatureSetTextFlag"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureSetImageFlagSEL, L"FPDCPWLSignatureSetImageFlag"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureSetFoxitFlagSEL, L"FPDCPWLSignatureSetFoxitFlag"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureSetIconTextFontSizeSEL, L"FPDCPWLSignatureSetIconTextFontSize"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureSetDescriptionFontSizeSEL, L"FPDCPWLSignatureSetDescriptionFontSize"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureSetIconTextColorSEL, L"FPDCPWLSignatureSetIconTextColor"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureSetDescriptionColorSEL, L"FPDCPWLSignatureSetDescriptionColor"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureCastToWndSEL, L"FPDCPWLSignatureCastToWnd"},
	{FPDCPWLSignatureSEL, FPDCPWLSignatureGetFromWndSEL, L"FPDCPWLSignatureGetFromWnd"},
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
	{FPDCustomCursorHandlerSEL, FPDCustomCursorHandlerNewSEL, L"FPDCustomCursorHandlerNew"},
	{FPDCustomCursorHandlerSEL, FPDCustomCursorHandlerDeleteSEL, L"FPDCustomCursorHandlerDelete"},
	{FPDCustomCursorHandlerSEL, FPDCustomCursorHandlerSetCustomCursorSEL, L"FPDCustomCursorHandlerSetCustomCursor"},
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
	{FPDCustomCryptoHandlerSEL, FPDCustomCryptoHandlerCreateSEL, L"FPDCustomCryptoHandlerCreate"},
	{FPDCustomCryptoHandlerSEL, FPDCustomCryptoHandlerDestroySEL, L"FPDCustomCryptoHandlerDestroy"},
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
	{FPDOprCallbackSEL, FPDOprCallbackCreateSEL, L"FPDOprCallbackCreate"},
	{FPDOprCallbackSEL, FPDOprCallbackDestroySEL, L"FPDOprCallbackDestroy"},
	{FPDFixSEL, FPDFixCreateSEL, L"FPDFixCreate"},
	{FPDFixSEL, FPDFixDestroySEL, L"FPDFixDestroy"},
	{FPDFixSEL, FPDFixEnableAllPagesSEL, L"FPDFixEnableAllPages"},
	{FPDFixSEL, FPDFixEnablePageSEL, L"FPDFixEnablePage"},
	{FPDFixSEL, FPDFixStartSEL, L"FPDFixStart"},
	{FPDFixSEL, FPDFixContinueSEL, L"FPDFixContinue"},
	{FPDFixSEL, FPDFixNextFeedbackItemSEL, L"FPDFixNextFeedbackItem"},
	{FPDValidatorFeedbackItemRoleMapSEL, FPDValidatorFeedbackItemRoleMapCreateSEL, L"FPDValidatorFeedbackItemRoleMapCreate"},
	{FPDValidatorFeedbackItemRoleMapSEL, FPDValidatorFeedbackItemRoleMapDestroySEL, L"FPDValidatorFeedbackItemRoleMapDestroy"},
	{FPDValidatorFeedbackItemRoleMapSEL, FPDValidatorFeedbackItemRoleMapGetRolesSEL, L"FPDValidatorFeedbackItemRoleMapGetRoles"},
	{FPDValidatorFeedbackItemRoleMapSEL, FPDValidatorFeedbackItemRoleMapSetRolesSEL, L"FPDValidatorFeedbackItemRoleMapSetRoles"},
	{FPDValidatorFeedbackItemRoleMapSEL, FPDValidatorFeedbackItemRoleMapCastToValidatorFeedbackItemSEL, L"FPDValidatorFeedbackItemRoleMapCastToValidatorFeedbackItem"},
	{FPDValidatorFeedbackItemMarkInfoSEL, FPDValidatorFeedbackItemMarkInfoCreateSEL, L"FPDValidatorFeedbackItemMarkInfoCreate"},
	{FPDValidatorFeedbackItemMarkInfoSEL, FPDValidatorFeedbackItemMarkInfoDestroySEL, L"FPDValidatorFeedbackItemMarkInfoDestroy"},
	{FPDValidatorFeedbackItemMarkInfoSEL, FPDValidatorFeedbackItemMarkInfoGetRolesSEL, L"FPDValidatorFeedbackItemMarkInfoGetRoles"},
	{FPDValidatorFeedbackItemMarkInfoSEL, FPDValidatorFeedbackItemMarkInfoSetRolesSEL, L"FPDValidatorFeedbackItemMarkInfoSetRoles"},
	{FPDValidatorFeedbackItemMarkInfoSEL, FPDValidatorFeedbackItemMarkInfoCastToValidatorFeedbackItemSEL, L"FPDValidatorFeedbackItemMarkInfoCastToValidatorFeedbackItem"},
// fpd_validateImpl.h end

//----------_V18----------
// In file fs_basicImpl.h
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
	{FPDSSLServerNoifyNotifySEL, FPDSSLServerNoifyNotifyCreateSEL, L"FPDSSLServerNoifyNotifyCreate"},
	{FPDSSLServerNoifyNotifySEL, FPDSSLServerNoifyNotifyCreateDefaultSEL, L"FPDSSLServerNoifyNotifyCreateDefault"},
	{FPDSSLServerNoifyNotifySEL, FPDSSLServerNoifyNotifyDestroySEL, L"FPDSSLServerNoifyNotifyDestroy"},
	{FPDSSLServerNoifyNotifySEL, FPDSSLServerNoifyNotifyGetTimeStampSEL, L"FPDSSLServerNoifyNotifyGetTimeStamp"},
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
	{FPDMonoscaleBitmapSEL, FPDMonoscaleBitmapGetSEL, L"FPDMonoscaleBitmapGet"},
	{FPDMonoscaleBitmapSEL, FPDMonoscaleBitmapNewSEL, L"FPDMonoscaleBitmapNew"},
	{FPDMonoscaleBitmapSEL, FPDMonoscaleBitmapReleaseSEL, L"FPDMonoscaleBitmapRelease"},
	{FPDMonoscaleBitmapSEL, FPDMonoscaleBitmapCreateSEL, L"FPDMonoscaleBitmapCreate"},
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V19----------
// In file fs_basicImpl.h
	{FSPrivateDataSEL, FSPrivateDataNewSEL, L"FSPrivateDataNew"},
	{FSPrivateDataSEL, FSPrivateDataDestroySEL, L"FSPrivateDataDestroy"},
	{FSPrivateDataSEL, FSPrivateDataClearAllSEL, L"FSPrivateDataClearAll"},
	{FSPrivateDataSEL, FSPrivateDataSetPrivateDataSEL, L"FSPrivateDataSetPrivateData"},
	{FSPrivateDataSEL, FSPrivateDataSetPrivateObjSEL, L"FSPrivateDataSetPrivateObj"},
	{FSPrivateDataSEL, FSPrivateDataGetPrivateDataSEL, L"FSPrivateDataGetPrivateData"},
	{FSPrivateDataSEL, FSPrivateDataLookupPrivateDataSEL, L"FSPrivateDataLookupPrivateData"},
	{FSPrivateDataSEL, FSPrivateDataRemovePrivateDataSEL, L"FSPrivateDataRemovePrivateData"},
	{FSVectorFSEL, FSVectorFCreateSEL, L"FSVectorFCreate"},
	{FSVectorFSEL, FSVectorFDestroySEL, L"FSVectorFDestroy"},
	{FSVectorFSEL, FSVectorFSetSEL, L"FSVectorFSet"},
	{FSVectorFSEL, FSVectorFSet2SEL, L"FSVectorFSet2"},
	{FSVectorFSEL, FSVectorFResetSEL, L"FSVectorFReset"},
	{FSVectorFSEL, FSVectorFSquareLengthSEL, L"FSVectorFSquareLength"},
	{FSVectorFSEL, FSVectorFLengthSEL, L"FSVectorFLength"},
	{FSVectorFSEL, FSVectorFNormalizeSEL, L"FSVectorFNormalize"},
	{FSVectorFSEL, FSVectorFGetXSEL, L"FSVectorFGetX"},
	{FSVectorFSEL, FSVectorFGetYSEL, L"FSVectorFGetY"},
	{FSVectorFSEL, FSVectorFDotProductSEL, L"FSVectorFDotProduct"},
	{FSVectorFSEL, FSVectorFDotProduct2SEL, L"FSVectorFDotProduct2"},
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
	{FRStartPageEventHandlerSEL, FRStartPageEventHandlerNewSEL, L"FRStartPageEventHandlerNew"},
	{FRStartPageEventHandlerSEL, FRStartPageEventHandlerDeleteSEL, L"FRStartPageEventHandlerDelete"},
	{FRUndoEventHandlerSEL, FRUndoEventHandlerNewSEL, L"FRUndoEventHandlerNew"},
	{FRUndoEventHandlerSEL, FRUndoEventHandlerDeleteSEL, L"FRUndoEventHandlerDelete"},
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
	{FPDEditAnnotHandlerSEL, FPDEditAnnotHandlerNewSEL, L"FPDEditAnnotHandlerNew"},
	{FPDEditAnnotHandlerSEL, FPDEditAnnotHandlerDestroySEL, L"FPDEditAnnotHandlerDestroy"},
	{FPDITextEnhancerSEL, FPDITextEnhancerCreateTextEnhancerSEL, L"FPDITextEnhancerCreateTextEnhancer"},
	{FPDITextEnhancerSEL, FPDITextEnhancerDeleteSEL, L"FPDITextEnhancerDelete"},
	{FPDITextEnhancerSEL, FPDITextEnhancerGetTextEnhancerOptionSEL, L"FPDITextEnhancerGetTextEnhancerOption"},
	{FPDITextEnhancerSEL, FPDITextEnhancerAnalyzePageTextBlocksSEL, L"FPDITextEnhancerAnalyzePageTextBlocks"},
	{FPDITextEnhancerSEL, FPDITextEnhancerGetPageTextBlockSizeSEL, L"FPDITextEnhancerGetPageTextBlockSize"},
	{FPDITextEnhancerSEL, FPDITextEnhancerGetTextBlockTextSEL, L"FPDITextEnhancerGetTextBlockText"},
	{FPDITextEnhancerSEL, FPDITextEnhancerSetTextBlockTextSEL, L"FPDITextEnhancerSetTextBlockText"},
	{FPDITextEnhancerOptionSEL, FPDITextEnhancerOptionGetCustomizationOptionSEL, L"FPDITextEnhancerOptionGetCustomizationOption"},
	{FPDITextEnhancerOptionSEL, FPDITextEnhancerOptionSetOptionOCContextSEL, L"FPDITextEnhancerOptionSetOptionOCContext"},
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

//----------_V20----------
// In file fs_basicImpl.h
// fs_basicImpl.h end

// In file fs_stringImpl.h
// fs_stringImpl.h end

// In file fdrm_descImpl.h
// fdrm_descImpl.h end

// In file fdrm_managerImpl.h
// fdrm_managerImpl.h end

// In file fdrm_pdfImpl.h
// fdrm_pdfImpl.h end

// In file fdrm_pkiImpl.h
// fdrm_pkiImpl.h end

// In file fhtml_impl.h
// fhtml_impl.h end

// In file fr_appImpl.h
// fr_appImpl.h end

// In file fr_barImpl.h
// fr_barImpl.h end

// In file fr_docImpl.h
// fr_docImpl.h end

// In file fr_fxnetappImpl.h
// fr_fxnetappImpl.h end

// In file fr_menuImpl.h
// fr_menuImpl.h end

// In file fr_sysImpl.h
// fr_sysImpl.h end

// In file fr_viewImpl.h
// fr_viewImpl.h end

// In file middle_imagecompressImpl.h
// middle_imagecompressImpl.h end

// In file middle_optimizeImpl.h
// middle_optimizeImpl.h end

// In file middle_pdfImpl.h
// middle_pdfImpl.h end

// In file middle_portfolioImpl.h
// middle_portfolioImpl.h end

// In file middle_preflightImpl.h
// middle_preflightImpl.h end

// In file fofd_basicImpl.h
// fofd_basicImpl.h end

// In file fofd_docImpl.h
// fofd_docImpl.h end

// In file fofd_pageImpl.h
// fofd_pageImpl.h end

// In file fofd_renderImpl.h
// fofd_renderImpl.h end

// In file fofd_sigImpl.h
// fofd_sigImpl.h end

// In file fpd_3DImpl.h
// fpd_3DImpl.h end

// In file fpd_barcodeImpl.h
// fpd_barcodeImpl.h end

// In file fpd_convertImpl.h
// fpd_convertImpl.h end

// In file fpd_docImpl.h
	{FPDSealInfoSEL, FPDSealInfoCreateSEL, L"FPDSealInfoCreate"},
	{FPDSealInfoSEL, FPDSealInfoDeleteSEL, L"FPDSealInfoDelete"},
	{FPDSealInfoSEL, FPDSealInfoGetNohterCurChainListIndexSEL, L"FPDSealInfoGetNohterCurChainListIndex"},
	{FPDSealInfoSEL, FPDSealInfoGetVerifyohterCertListCountSEL, L"FPDSealInfoGetVerifyohterCertListCount"},
	{FPDSealInfoSEL, FPDSealInfoGetVerifyohterCertByIndexSEL, L"FPDSealInfoGetVerifyohterCertByIndex"},
	{FPDSealInfoSEL, FPDSealInfoGetSealNameSEL, L"FPDSealInfoGetSealName"},
	{FPDSealInfoSEL, FPDSealInfoGetSealmaketimeSEL, L"FPDSealInfoGetSealmaketime"},
	{FPDSealInfoSEL, FPDSealInfoGetSealbeginSEL, L"FPDSealInfoGetSealbegin"},
	{FPDSealInfoSEL, FPDSealInfoGetSealEndSEL, L"FPDSealInfoGetSealEnd"},
	{FPDSealInfoSEL, FPDSealInfoGetRevocVerifyKeyIndexSEL, L"FPDSealInfoGetRevocVerifyKeyIndex"},
	{FPDSealInfoSEL, FPDSealInfoGetRevocVerifyByKeySEL, L"FPDSealInfoGetRevocVerifyByKey"},
// fpd_docImpl.h end

// In file fpd_editImpl.h
// fpd_editImpl.h end

// In file fpd_epubImpl.h
// fpd_epubImpl.h end

// In file fpd_fontmgrImpl.h
// fpd_fontmgrImpl.h end

// In file fpd_fxxfaImpl.h
// fpd_fxxfaImpl.h end

// In file fpd_jsImpl.h
// fpd_jsImpl.h end

// In file fpd_lrImpl.h
// fpd_lrImpl.h end

// In file fpd_mathImpl.h
// fpd_mathImpl.h end

// In file fpd_objsImpl.h
// fpd_objsImpl.h end

// In file fpd_pageImpl.h
// fpd_pageImpl.h end

// In file fpd_pageobjImpl.h
// fpd_pageobjImpl.h end

// In file fpd_parserImpl.h
// fpd_parserImpl.h end

// In file fpd_psiImpl.h
// fpd_psiImpl.h end

// In file fpd_pwlImpl.h
// fpd_pwlImpl.h end

// In file fpd_renderImpl.h
// fpd_renderImpl.h end

// In file fpd_resourceImpl.h
// fpd_resourceImpl.h end

// In file fpd_serialImpl.h
// fpd_serialImpl.h end

// In file fpd_textImpl.h
// fpd_textImpl.h end

// In file fpd_validateImpl.h
// fpd_validateImpl.h end

{-1, -1, L""}
};

//Auto generated file end!
#endif

#endif


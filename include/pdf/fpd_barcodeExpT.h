/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.

 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.

 ---------------------------------------------------------------------

fpd_convertExpT.h

 - Types, macros, structures, etc. required to use the FPDLayer HFT.

*********************************************************************/

#ifndef FPD_BARCODEEXPT_H
#define FPD_BARCODEEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif


/* @OBJSTART FPD_CBCCodeBase */
#ifndef FPD_CBCCODEBASE
#define	FPD_CBCCODEBASE
/**
* @brief
*/
	typedef struct _t_FPD_CBCCodeBase* FPD_CBCCodeBase;
#endif

	/* @ENUMSTART */
	/** @brief Barcode type. */
	enum FPD_BC_TYPE
	{
		FPD_BC_UNKNOWN = -1,
		FPD_BC_CODE39 = 0,
		FPD_BC_CODABAR,
		FPD_BC_CODE128,
		FPD_BC_CODE128_B,
		FPD_BC_CODE128_C,
		FPD_BC_EAN8,
		FPD_BC_UPCA,
		FPD_BC_EAN13,
		FPD_BC_QR_CODE,
		FPD_BC_PDF417,
		FPD_BC_DATAMATRIX
	};
	/* @ENUMEND */

	/* @ENUMSTART */
	/** @brief Barcode text position.*/
	enum FPD_BC_TEXT_LOC
	{
		FPD_BC_TEXT_LOC_NONE = 0,
		FPD_BC_TEXT_LOC_ABOVE,
		FPD_BC_TEXT_LOC_BELOW,
		FPD_BC_TEXT_LOC_ABOVEEMBED,
		FPD_BC_TEXT_LOC_BELOWEMBED
	};
	/* @ENUMEND */

	/* @ENUMSTART */
	/** @brief Barcode char encoding.*/
	enum FPD_BC_CHAR_ENCODING
	{
		FPD_CHAR_ENCODING_UTF8 = 0,
		FPD_CHAR_ENCODING_UNICODE
	};
	/* @ENUMEND */

/* @DEFGROUPSTART exception info */
/**
* @brief Definitions exception info.
*/

/*@{*/
/** @brief Hand Tool*/
#define	FPD_BCExceptionNO											           0
#define	FPD_BCExceptionNotFound										           1
#define	FPD_BCExceptionEndLessThanStart								           2
#define	FPD_BCExceptionUnknownDecoder								           3
#define	FPD_BCExceptionRotateNotSupported							           4
#define	FPD_BCExceptionHeightAndWidthMustBeAtLeast1					           5
#define	FPD_BCExceptionRegionMustFitInsideMatrix				               6
#define	FPD_BCExceptionCanNotCallGetDimensionOnNonSquareMatrix		           7
#define	FPD_BCExceptionFormatException								           8
#define	FPD_BCExceptionIllegalArgumentMustMatchVersionSize		               9
#define	FPD_BCExceptionChecksumException							          10
#define	FPD_BCExceptionIllegalArgumentInvalidFirstDigit			              11
#define	FPD_BCExceptionIllegalArgumentInvalidSecondDigit			          12
#define	FPD_BCExceptionRuntimeDecodingInvalidISO_IEC				          13
#define	FPD_BCExceptionRuntimeDecodingInvalidAlphanumeric			          14
#define	FPD_BCExceptionLeftAndTopMustBeNonnegative					          15
#define	FPD_BCExceptionIllegalArgument								          16
#define	FPD_BCExceptionBadECI										          17
#define	FPD_BCExceptionUnSupportedBarcode							          18
#define	FPD_BCExceptionUnSupportedString							          19
#define	FPD_BCExceptionDigitLengthMustBe8							          20
#define	FPD_BCExceptionDataCheckException							          21
#define FPD_BCExceptionExtractNumberValueFromBitArray                         22
#define FPD_BCExceptionRead											          23
#define FPD_BCExceptionRequestedRowIsOutSizeTheImage                          24
#define FPD_BCExceptionNoContents                                             26
#define FPD_BCExceptionUnSupportEclevel                                       27
#define FPD_BCExceptionUnSupportMode								          28
#define FPD_BCExceptionReferenceMustBeBetween0And7					          29
#define FPD_BCExceptionBadErrorLocation								          30
#define FPD_BCExceptionDegreeIsNegative							 	          31
#define FPD_BCExceptionDivideByZero									          32
#define FPD_BCExceptionCoefficientsSizeIsNull						          33
#define FPD_BCExceptionNoCorrectionBytes							          34
#define FPD_BCExceptionNoDataBytesProvided						              35
#define FPD_BCExceptionR_I_1IsZero									          36
#define FPD_BCExceptionAIsZero										          37
#define FPD_BCExceptionIsZero										          38	
#define FPD_BCExceptionDegreeNotMatchRoots					                  39
#define	FPD_BCExceptionContentsLengthShouldBetween1and80	                  40					
#define	FPD_BCExceptionOnlyEncodeCODE_128                                     41
#define	FPD_BCExceptionOnlyEncodeCODE_39                                      42
#define	FPD_BCExceptionOnlyEncodeEAN_13                                       43
#define	FPD_BCExceptionOnlyEncodeEAN_8                                        44
#define	FPD_BCExceptionOnlyEncodeITF                                          45
#define	FPD_BCExceptionDigitLengthShould13                                    46
#define	FPD_BCExceptionDigitLengthMustBe6or8or10or12or14or16or20or24or44      47
#define	FPD_BCExceptionOnlyEncodeUPC_A                                        48
#define FPD_BCExceptionDigitLengthShouldBe12                                  49
#define FPD_BCExceptionValueMustBeEither0or1                                  50
#define FPD_BCExceptionReedsolomnDecodeException                              51
#define FPD_BCExceptionBadIndexException                                      52
#define FPD_BCExceptionBadValueException                                      53
#define FPD_BCExceptionBadNumBitsException                                    54
#define FPD_BCExceptioncanNotOperatexorOperator                               55
#define FPD_BCExceptionVersionMust1_40										  56
#define FPD_BCExceptionUnknown												  57
#define FPD_BCExceptionNoSuchVersion						    		      58
#define FPD_BCExceptionCannotFindBlockInfo									  59
#define FPD_BCExceptionDataTooBig							         		  60
#define FPD_BCExceptionInvalidQRCode										  61
#define FPD_BCExceptionDataTooMany											  62
#define FPD_BCExceptionBitsNotEqualCacity								      63
#define FPD_BCExceptionUnsupportedMode										  64
#define FPD_BCExceptionInvalidateCharacter					                  65
#define FPD_BCExceptionBytesNotMatchOffset								      66
#define FPD_BCExceptionSizeInBytesDiffer			       					  67
#define FPD_BCExceptionInvalidateMaskPattern								  68
#define FPD_BCExceptionNullPointer 											  69
#define FPD_BCExceptionBadMask 											      70
#define FPD_BCExceptionBitSizeNot15										      71
#define FPD_BCExceptionBitSizeNot18											  72
#define FPD_BCExceptionInvalidateImageData									  73
#define FPD_BCExceptionHeight_8BeZero										  74
#define FPD_BCExceptionCharacterNotThisMode									  75
#define FPD_BCExceptionBitsBytesNotMatch									  76
#define FPD_BCExceptionInvalidateData										  77
#define FPD_BCExceptionLoadFile												  78
#define FPD_BCExceptionPDF417EncodeFail								          79
#define FPD_BCExceptionFailToCreateBitmap									  80
#define FPD_BCExceptionLoadFontFail											  81

#define FPD_BCExceptionOnlyEncodeCODEBAR                                      82
#define FPD_BCExceptionCodabarShouldStartWithOneOfABCD                        83
#define FPD_BCExceptionCodabarShouldEndWithOneOfTNE                           84//???? 
#define FPD_BCExceptionCodabarEncodeCharsInvalid                              85 

#define FPD_BCExceptionOnlyEncodeDATAMATRIX                                   86
#define FPD_BCExceptionCharactersOutsideISO88591Encoding                      87

#define FPD_BCExceptionIllegalDataCodewords                                   88
#define FPD_BCExceptionCannotHandleThisNumberOfDataRegions                    89

#define FPD_BCExceptionIllegalStateUnexpectedCase                             90
#define FPD_BCExceptionIllegalStateCountMustNotExceed4                        91
#define FPD_BCExceptionIllegalStateMessageLengthInvalid                       92
#define FPD_BCExceptionIllegalArgumentNotGigits                               93
#define FPD_BCExceptionIllegalStateIllegalMode                                94

#define	FPD_BCExceptionOnlyEncodePDF417                                       95
#define	FPD_BCExceptionNonEncodableCharacterDetected                          96
#define	FPD_BCExceptionErrorCorrectionLevelMustBeBetween0And8                 97
#define	FPD_BCExceptionNoRecommendationPossible                               98
#define	FPD_BCExceptionIllegalArgumentnMustBeAbove0                           99
#define	FPD_BCExceptionUnableToFitMessageInColumns                            100
#define	FPD_BCExceptionEncodedMessageContainsTooManyCodeWords                 101
#define FPD_BCExceptionBitmapSizeError										  102

#define FPD_BCExceptionFormatInstance                                         102
#define FPD_BCExceptionChecksumInstance                                       103
#define FPD_BCExceptiontNotFoundInstance                                      104

#define FPD_BCExceptionNotFoundInstance                                       105
#define FPD_BCExceptionCannotMetadata                                         106      

#define FPD_BC_EXCEPTION_CHECK_ReturnVoid(e) if (e != FPD_BCExceptionNO) return;
#define FPD_BC_EXCEPTION_CHECK_ReturnValue(e, v) if (e != FPD_BCExceptionNO) return v;
#define FPD_BC_EXCEPTION_CHECK_DeleteReturnValue(e, p, v) if (e != FPD_BCExceptionNO) {if (p) delete p;  return v;}
/* @DEFGROUPEND */

/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
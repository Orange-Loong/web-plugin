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

#ifndef FPD_VALIDATEEXPT_H
#define FPD_VALIDATEEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "fpd_docExpt.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


	/* @OBJSTART FPD_ValidatorHandler */
#ifndef FPD_VALIDATORHANDLER
#define	FPD_VALIDATORHANDLER
	/**
	* @brief
	*/
	typedef struct _t_FPD_ProgressHandler* FPD_ProgressHandler;
#endif

/* @CALLBACKGROUPSTART FPD_ValidatorCallbacks */
/** @brief A set of callbacks for Validator handler. */
	typedef struct _fpd_progress_callbacks_
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_ConverterCallbacksRec</a>) */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART FPDNeedToPauseNow */
		/**
		* @brief FPDNeedToPauseNow.
		* @param[in] clientData	The user-supplied data.
		* @return void
		* @note
		*/
		FS_BOOLEAN(*FPDNeedToPauseNow)(FS_LPVOID clientData);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FPDPreparePage */
		/**
		* @brief FPDPreparePage.
		* @param[in] clientData	The user-supplied data.
		* @param[in] nPageIdx	The page index.
		* @param[in] pPage	    The page object.
		* @return void
		* @note
		*/
		FS_BOOLEAN(*FPDPreparePage)(FS_LPVOID clientData, FS_INT32 nPageIdx, FPD_Page pPage);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FPDUpdateProgress */
		/**
		* @brief FPDUpdateProgress.
		* @param[in] clientData    	    The user-supplied data.
		* @param[in] nConvertedCount	The convert count.
		* @return void
		* @note
		*/
		void(*FPDUpdateProgress)(FS_LPVOID clientData, FS_INT32 nConvertedCount);
		/* @CALLBACKEND */
	}FPD_ProgressCallbacksRec, *FPD_ProgressCallbacks;
/* @CALLBACKGROUPEND */

	/* @OBJEND */


/* @OBJSTART FPD_Validator */
#ifndef FPD_VALIDATOR
#define	FPD_VALIDATOR
	/**
	* @brief
	*/
	typedef struct _t_FPD_Validator* FPD_Validator;
#endif

	/* @STRUCTSTART FPD_ValidatorOptions*/
	typedef struct __FPD_FPD_ValidatorOptions__
	{
		__FPD_FPD_ValidatorOptions__()
		{
			bStopAtFirstError = false;
		}

		FS_BOOLEAN bStopAtFirstError; //stop validate when occur the first error.
	}FPD_ValidatorOptions, *PFPD_ValidatorOptions;
	/* @STRUCTEND */
/* @OBJEND */

/* @OBJSTART FPD_ValidatorFeedbackItem */
#ifndef FPD_VALIDATORFEEDBACKITEM
#define	FPD_VALIDATORFEEDBACKITEM
	/**
	* @brief
	*/
	typedef struct _t_FPD_ValidatorFeedbackItem* FPD_ValidatorFeedbackItem;
#endif

	enum FPD_ValidatorFeedbackItemClass
	{
		FPD_ValidatorFeedbackItemClass_Error,
		FPD_ValidatorFeedbackItemClass_Info,
		FPD_ValidatorFeedbackItemClass_HumanCheck,
		FPD_ValidatorFeedbackItemClass_NotImplemented,
	};

	enum FPD_ValidatorFeedbackItemType
	{
		FPD_ValidatorFeedbackItemType_Document,
		FPD_ValidatorFeedbackItemType_Font,
		FPD_ValidatorFeedbackItemType_Page,
		FPD_ValidatorFeedbackItemType_PageContent,
		FPD_ValidatorFeedbackItemType_Annot,
		FPD_ValidatorFeedbackItemType_StructElem,
		FPD_ValidatorFeedbackItemType_Field,
		FPD_ValidatorFeedbackItemType_RoleMap,
		FPD_ValidatorFeedbackItemType_MarkInfo
	};
	/* @OBJEND */

	/* @OBJSTART FPD_ValidatorFeedbackItem_Font */
#ifndef FPD_VALIDATORFEEDBACKITEMFONT
#define	FPD_VALIDATORFEEDBACKITEMFONT
	/**
	* @brief
	*/
	typedef struct _t_FPD_ValidatorFeedbackItem_Font* FPD_ValidatorFeedbackItem_Font;
#endif
	/* @OBJEND */

	/* @OBJSTART FPD_ValidatorFeedbackItem_Annot */
#ifndef FPD_VALIDATORFEEDBACKITEMANNOT
#define	FPD_VALIDATORFEEDBACKITEMANNOT
	/**
	* @brief
	*/
	typedef struct _t_FPD_ValidatorFeedbackItem_Annot* FPD_ValidatorFeedbackItem_Annot;
#endif
	/* @OBJEND */

	/* @OBJSTART FPD_ValidatorFeedbackItem_Page */
#ifndef FPD_VALIDATORFEEDBACKITEMPAGE
#define	FPD_VALIDATORFEEDBACKITEMPAGE
	/**
	* @brief
	*/
	typedef struct _t_FPD_ValidatorFeedbackItem_Page* FPD_ValidatorFeedbackItem_Page;
#endif
	/* @OBJEND */

/* @OBJSTART FPD_ValidatorFeedbackItem_PageContent */
#ifndef FPD_VALIDATORFEEDBACKITEMPAGECONTENT
#define	FPD_VALIDATORFEEDBACKITEMPAGECONTENT
	/**
	* @brief
	*/
	typedef struct _t_FPD_ValidatorFeedbackItem_PageContent* FPD_ValidatorFeedbackItem_PageContent;
#endif
	/* @OBJEND */

	/* @OBJSTART FPD_ValidatorFeedbackItem_StructElem */
#ifndef FPD_VALIDATORFEEDBACKITEMSTRUCTELEM
#define	FPD_VALIDATORFEEDBACKITEMSTRUCTELEM
	/**
	* @brief
	*/
	typedef struct _t_FPD_ValidatorFeedbackItem_StructElem* FPD_ValidatorFeedbackItem_StructElem;
#endif
	/* @OBJEND */

/* @OBJSTART FPD_ValidatorFeedbackItem_Field */
#ifndef FPD_VALIDATORFEEDBACKITEMFIELD
#define	FPD_VALIDATORFEEDBACKITEMFIELD
	/**
	* @brief
	*/
	typedef struct _t_FPD_ValidatorFeedbackItem_Field* FPD_ValidatorFeedbackItem_Field;
#endif
	/* @OBJEND */

/* @OBJSTART FPD_RuleSet */
#ifndef FPD_RULESET
#define	FPD_RULESET
	/**
	* @brief
	*/
	typedef struct _t_FPD_RuleSet* FPD_RuleSet;
#endif

	/* @CALLBACKGROUPSTART FPD_ValidatorCallbacks */
/** @brief A set of callbacks for Validator handler. */
	typedef struct _fpd_ruleset_callbacks_
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_ConverterCallbacksRec</a>) */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;
		
		FS_BOOLEAN(*FPDEnableAllRules)(FS_LPVOID clientData, FS_BOOLEAN bEnabled);
		
		FS_BOOLEAN(*FPDEnableRule)(FS_LPVOID clientData, FS_DWORD dwRuleID, FS_BOOLEAN bEnabled);
		
	}FPD_RuleSetCallbacksRec, *FPD_RuleSetCallbacks;
	/* @CALLBACKGROUPEND */

/* @DEFGROUPSTART ValidateRuleType */
/**
* @brief Definitions validate rule type.
*/
/*@{*/
#define FPDVALIDATE_ACC_RULE_01_DOC_PERMISSION          0x0101
#define FPDVALIDATE_ACC_RULE_02_DOC_PUREIMAGE           0x0102
#define FPDVALIDATE_ACC_RULE_03_DOC_TAGGED              0x0103
#define FPDVALIDATE_ACC_RULE_04_DOC_STRUCTTREEORDER     0x0104
#define FPDVALIDATE_ACC_RULE_05_DOC_LANGSPECIFIED       0x0105
#define FPDVALIDATE_ACC_RULE_06_DOC_TITLE               0x0106
#define FPDVALIDATE_ACC_RULE_07_DOC_OUTLINEFORLARGE     0x0107
#define FPDVALIDATE_ACC_RULE_08_DOC_COLORCONTRAST       0x0108
#define FPDVALIDATE_ACC_RULE_09_PAGE_CONTENTTAGGED      0x0109
#define FPDVALIDATE_ACC_RULE_10_PAGE_ANNOTTAGGED        0x010A
#define FPDVALIDATE_ACC_RULE_11_PAGE_TABORDER           0x010B
#define FPDVALIDATE_ACC_RULE_12_PAGE_FONTENCODING       0x010C
#define FPDVALIDATE_ACC_RULE_13_PAGE_MMOBJTAGGED        0x010D
#define FPDVALIDATE_ACC_RULE_14_PAGE_NOFLICKERING       0x010E
#define FPDVALIDATE_ACC_RULE_15_PAGE_NOINACCSCRIPT      0x010F
#define FPDVALIDATE_ACC_RULE_16_PAGE_NOTIMEDRESPONSE    0x0110
#define FPDVALIDATE_ACC_RULE_17_PAGE_NAVLINKREPEAT      0x0111
#define FPDVALIDATE_ACC_RULE_18_FTL_FIELDTAGGED         0x0112
#define FPDVALIDATE_ACC_RULE_19_FTL_FIELDALTTEXT        0x0113
#define FPDVALIDATE_ACC_RULE_20_FTL_TRPROPERUSED        0x0114
#define FPDVALIDATE_ACC_RULE_21_FTL_THTDPROPERUSED      0x0115
#define FPDVALIDATE_ACC_RULE_22_FTL_HASTHEXIST          0x0116
#define FPDVALIDATE_ACC_RULE_23_FTL_TBLSPANCORRECT      0x0117
#define FPDVALIDATE_ACC_RULE_24_FTL_TBLSUMMARY          0x0118
#define FPDVALIDATE_ACC_RULE_25_FTL_LIPROPERUSED        0x0119
#define FPDVALIDATE_ACC_RULE_26_FTL_LBLLBODYPROPERUSED  0x011A
#define FPDVALIDATE_ACC_RULE_27_ACH_FIGUREALTTEXT       0x011B
#define FPDVALIDATE_ACC_RULE_28_ACH_NONESTEDALTTEXT     0x011C
#define FPDVALIDATE_ACC_RULE_29_ACH_ALTTEXTHASCONTENT   0x011D
#define FPDVALIDATE_ACC_RULE_30_ACH_ALTTEXTHIDEANNOT    0x011E
#define FPDVALIDATE_ACC_RULE_31_ACH_ELEMENTALTTEXT      0x011F
#define FPDVALIDATE_ACC_RULE_32_ACH_HEADINGPROPERNEST   0x0120
#define FPDVALIDATE_ACC_RULE_MIN 0x0101
#define FPDVALIDATE_ACC_RULE_MAX 0x0120
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART PREFLIGHT_PDFUA */
/**
* @brief Definitions validate rule type.
*/
/*@{*/
#define FPDPREFLIGHT_PDFUA_01_003 0x2003
#define FPDPREFLIGHT_PDFUA_01_004 0x2004
#define FPDPREFLIGHT_PDFUA_01_005 0x2005
#define FPDPREFLIGHT_PDFUA_01_006 0x2006
#define FPDPREFLIGHT_PDFUA_01_007 0x2007
#define FPDPREFLIGHT_PDFUA_02_001 0x2008
#define FPDPREFLIGHT_PDFUA_02_003 0x200A
#define FPDPREFLIGHT_PDFUA_02_004 0x200B
#define FPDPREFLIGHT_PDFUA_06_001 0x2013
#define FPDPREFLIGHT_PDFUA_06_002 0x2014
#define FPDPREFLIGHT_PDFUA_06_003 0x2015
#define FPDPREFLIGHT_PDFUA_07_001 0x2017
#define FPDPREFLIGHT_PDFUA_07_002 0x2018
#define FPDPREFLIGHT_PDFUA_08_001 0x2019
#define FPDPREFLIGHT_PDFUA_08_002 0x201A
#define FPDPREFLIGHT_PDFUA_09_004 0x201E
#define FPDPREFLIGHT_PDFUA_09_005 0x201F
#define FPDPREFLIGHT_PDFUA_09_006 0x2020
#define FPDPREFLIGHT_PDFUA_09_007 0x2021
#define FPDPREFLIGHT_PDFUA_09_008 0x2022
#define FPDPREFLIGHT_PDFUA_10_001 0x2023
#define FPDPREFLIGHT_PDFUA_11_001 0x2024
#define FPDPREFLIGHT_PDFUA_11_002 0x2025
#define FPDPREFLIGHT_PDFUA_11_003 0x2026
#define FPDPREFLIGHT_PDFUA_11_004 0x2027
#define FPDPREFLIGHT_PDFUA_11_005 0x2028
#define FPDPREFLIGHT_PDFUA_11_006 0x2029
#define FPDPREFLIGHT_PDFUA_13_004 0x202F
#define FPDPREFLIGHT_PDFUA_14_002 0x2035
#define FPDPREFLIGHT_PDFUA_14_003 0x2036
#define FPDPREFLIGHT_PDFUA_14_006 0x2039
#define FPDPREFLIGHT_PDFUA_14_007 0x203A
#define FPDPREFLIGHT_PDFUA_15_003 0x203D
#define FPDPREFLIGHT_PDFUA_17_002 0x2044
#define FPDPREFLIGHT_PDFUA_17_003 FPDPREFLIGHT_PDFUA_10_001 
#define FPDPREFLIGHT_PDFUA_19_003 0x204A
#define FPDPREFLIGHT_PDFUA_19_004 0x204B
#define FPDPREFLIGHT_PDFUA_20_001 0x204C
#define FPDPREFLIGHT_PDFUA_20_002 0x204D
#define FPDPREFLIGHT_PDFUA_20_003 0x204E
#define FPDPREFLIGHT_PDFUA_21_001 0x204F
#define FPDPREFLIGHT_PDFUA_25_001 0x2053
#define FPDPREFLIGHT_PDFUA_26_001 0x2054
#define FPDPREFLIGHT_PDFUA_26_002 0x2055
#define FPDPREFLIGHT_PDFUA_28_002 0x2058
#define FPDPREFLIGHT_PDFUA_28_004 0x205A
#define FPDPREFLIGHT_PDFUA_28_005 0x205B
#define FPDPREFLIGHT_PDFUA_28_006 0x205C
#define FPDPREFLIGHT_PDFUA_28_007 0x205D
#define FPDPREFLIGHT_PDFUA_28_008 0x205E
#define FPDPREFLIGHT_PDFUA_28_009 0x205F
#define FPDPREFLIGHT_PDFUA_28_010 0x2060
#define FPDPREFLIGHT_PDFUA_28_011 0x2061
#define FPDPREFLIGHT_PDFUA_28_012 0x2062
#define FPDPREFLIGHT_PDFUA_28_014 0x2064
#define FPDPREFLIGHT_PDFUA_28_015 0x2065
#define FPDPREFLIGHT_PDFUA_28_016 0x2066		
#define FPDPREFLIGHT_PDFUA_28_017 0x2067
#define FPDPREFLIGHT_PDFUA_28_018 0x2068
#define FPDPREFLIGHT_PDFUA_29_001 0x2069
#define FPDPREFLIGHT_PDFUA_30_001 0x206A
#define FPDPREFLIGHT_PDFUA_30_002 0x206B
#define FPDPREFLIGHT_PDFUA_31_001 0x206C
#define FPDPREFLIGHT_PDFUA_31_002 0x206D
#define FPDPREFLIGHT_PDFUA_31_003 0x206E
#define FPDPREFLIGHT_PDFUA_31_004 0x206F
#define FPDPREFLIGHT_PDFUA_31_005 0x2070
#define FPDPREFLIGHT_PDFUA_31_006 0x2071
#define FPDPREFLIGHT_PDFUA_31_007 0x2072
#define FPDPREFLIGHT_PDFUA_31_008 0x2073
#define FPDPREFLIGHT_PDFUA_31_009 0x2074
#define FPDPREFLIGHT_PDFUA_31_011 0x2075
#define FPDPREFLIGHT_PDFUA_31_012 0x2076
#define FPDPREFLIGHT_PDFUA_31_013 0x2077
#define FPDPREFLIGHT_PDFUA_31_014 0x2078
#define FPDPREFLIGHT_PDFUA_31_015 0x2079
#define FPDPREFLIGHT_PDFUA_31_016 0x207A
#define FPDPREFLIGHT_PDFUA_31_017 0x207B
#define FPDPREFLIGHT_PDFUA_31_018 0x207C
#define FPDPREFLIGHT_PDFUA_31_019 0x207D
#define FPDPREFLIGHT_PDFUA_31_020 0x207E
#define FPDPREFLIGHT_PDFUA_31_021 0x207F
#define FPDPREFLIGHT_PDFUA_31_022 0x2080
#define FPDPREFLIGHT_PDFUA_31_023 0x2081
#define FPDPREFLIGHT_PDFUA_31_024 0x2082
#define FPDPREFLIGHT_PDFUA_31_025 0x2083
#define FPDPREFLIGHT_PDFUA_31_026 0x2084
#define FPDPREFLIGHT_PDFUA_31_027 0x2085
#define FPDPREFLIGHT_PDFUA_31_028 0x2086
#define FPDPREFLIGHT_PDFUA_31_029 0x2087
#define FPDPREFLIGHT_PDFUA_31_030 0x2088
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_OprCallback */
#ifndef FPD_OPRCALLBACK
#define	FPD_OPRCALLBACK
	/**
	* @brief
	*/
	typedef struct _t_FPD_OprCallback* FPD_OprCallback;
#endif

	/* @CALLBACKGROUPSTART FPD_OprerateCallbacks */
/** @brief A set of callbacks for Validator handler. */
	typedef struct _fpd_Oprerate_callbacks_
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_ConverterCallbacksRec</a>) */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		FS_BOOLEAN(*FPDReloadPage)(FS_LPVOID clientData, FS_INT32 nPageIndex);

		FS_BOOLEAN(*FPDRebuildStructTree)(FS_LPVOID clientData, FPD_StructTree pStructTree);

	}FPD_OprerateCallbacksRec, *FPD_OprerateCallbacks;
	/* @CALLBACKGROUPEND */
/* @OBJEND */

/* @OBJSTART FPD_Fix */
#ifndef FPD_FIX
#define	FPD_FIX
	/**
	* @brief
	*/
	typedef struct _t_FPD_Fix* FPD_Fix;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ValidatorFeedbackItem_RoleMap */
#ifndef FPD_VALIDATORFEEDBACKITEMROLEMAP
#define	FPD_VALIDATORFEEDBACKITEMROLEMAP
	/**
	* @brief
	*/
	typedef struct _t_FPD_ValidatorFeedbackItem_RoleMap* FPD_ValidatorFeedbackItem_RoleMap;
#endif
	/* @OBJEND */

/* @OBJSTART FPD_ValidatorFeedbackItem_MarkInfo */
#ifndef FPD_VALIDATORFEEDBACKITEMMARKINFO
#define	FPD_VALIDATORFEEDBACKITEMMARKINFO
	/**
	* @brief
	*/
	typedef struct _t_FPD_ValidatorFeedbackItem_MarkInfo* FPD_ValidatorFeedbackItem_MarkInfo;
#endif
	/* @OBJEND */

	
#ifdef __cplusplus
};
#endif

#endif
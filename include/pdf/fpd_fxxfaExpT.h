#ifndef FPD_FXXFAEXPT_H
#define FPD_FXXFAEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "fpd_objsExpT.h"
#endif

#ifndef FPD_RESOURCEEXPT_H
#include "fpd_resourceExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/* @OBJSTART FPD_XFARenderOptions */
#ifndef FPD_XFARENDEROPTIONS
#define	FPD_XFARENDEROPTIONS
	typedef struct _t_FPD_XFARenderOptions* FPD_XFARenderOptions;
#endif
	/* @OBJEND */

    /* @OBJSTART FPD_XFARenderContext */
#ifndef FPD_XFARENDERCONTEXT
#define	FPD_XFARENDERCONTEXT
	typedef struct _t_FPD_XFARenderContext* FPD_XFARenderContext;
#endif
	/* @OBJEND */


	/* @OBJSTART FPD_XFAConverter */
#ifndef FPD_XFACONVERTER
#define	FPD_XFACONVERTER
	typedef struct _t_FPD_XFAConverter* FPD_XFAConverter;
#endif

	enum FPDXFA_CONVERT_TYPE
	{
		FPDXFA_CONVERT_TO_PDF = 0
	};

	enum FPDXFA_CONVERT_STATUS
	{
		FPDXFA_CONVERT_STATUS_ERROR = -1,
		FPDXFA_CONVERT_STATUS_READY,
		FPDXFA_CONVERT_STATUS_TOBECONTINUE,
		FPDXFA_CONVERT_STATUS_FINISH,
	};
	/* @OBJEND */	


#ifdef __cplusplus
};
#endif

#endif
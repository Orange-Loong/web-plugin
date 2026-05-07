/*****************************************************************************

  Copyright (C) 2024 Foxit Corporation
  All rights reserved.
  
	NOTICE: Foxit permits you to use, modify, and distribute this file
	in accordance with the terms of the Foxit license agreement
	accompanying it. If you have received this file from a source other
	than Foxit, then your use, modification, or distribution of it
	requires the prior written permission of Foxit.
	
*****************************************************************************/

#ifndef FDRM_MANAGERIMPL_H
#define FDRM_MANAGERIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../../basic/fs_basicExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../../pdf/fpd_parserExpT.h"
#endif

#ifndef FDRM_MANAGEREXPT_H
#include "../fdrm_managerExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

class CFDRM_Mgr_V2
{
public:
	static FDRM_Mgr CreateDef(void);
	static FDRM_Mgr GetCurrentUse(void);
	static void SetCurrentUse(FDRM_Mgr mgr);
	static void Destroy(FDRM_Mgr mgr);

};


#ifdef __cplusplus
};
#endif

#endif
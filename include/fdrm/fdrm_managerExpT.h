/*********************************************************************

  Copyright (C) 2024 Foxit Corporation
  All rights reserved.
  
	NOTICE: Foxit permits you to use, modify, and distribute this file
	in accordance with the terms of the Foxit license agreement
	accompanying it. If you have received this file from a source other
	than Foxit, then your use, modification, or distribution of it
	requires the prior written permission of Foxit.
	
	  ---------------------------------------------------------------------
	  
		fdrm_managerExpT.h
		
		  - Types, macros, structures, etc. required to use the FDRMLayer HFT.
		  
*********************************************************************/
#ifndef FDRM_MANAGEREXPT_H
#define FDRM_MANAGEREXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../pdf/fpd_parserExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../pdf/fpd_objsExpT.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

#ifndef FDRM_MANAGER
#define FDRM_MANAGER
typedef struct _t_FDRM_Mgr* FDRM_Mgr;
#endif

/** @brief Environment values. */
enum E_FDRM_ENVVALUE
{
	E_FDRM_ENVVALUE_MgrGUID = 0,		//GUID of FDRM manager
	E_FDRM_ENVVALUE_DeviceSN,			//device SN
	E_FDRM_ENVVALUE_DeviceName,		//device name, computer name, domain name, DNS name, etc.
	E_FDRM_ENVVALUE_DeviceDesc,		//device description
	E_FDRM_ENVVALUE_OSType,			//OS type 
	E_FDRM_ENVVALUE_OSVersion,		//OS version 
	E_FDRM_ENVVALUE_OSDesc,			//OS description 
	E_FDRM_ENVVALUE_CPUType,			//CPU type 
	E_FDRM_ENVVALUE_CPUCount,			//amount of total CPUs
	E_FDRM_ENVVALUE_CPUID,			//CPU ID, separate by '|' if there are several CPUs
	E_FDRM_ENVVALUE_MemorySize,		//total size of physical memory
	E_FDRM_ENVVALUE_BIOS,				//BIOS Manufacturer and version information, separate by '|'
	E_FDRM_ENVVALUE_MotherBoard,		//Motherboard, Product, version, serialnumber information , separate by '|'
	E_FDRM_ENVVALUE_HDCount,			//amount of total hard diskettes
	E_FDRM_ENVVALUE_HDSN,				//hard diskette SN, separate by '|' if there are several HDs
	E_FDRM_ENVVALUE_NICCount,			//amount of total NICs
	E_FDRM_ENVVALUE_MACAddr,			//MAC address, separate by '|' if there are several MAC addresses
	E_FDRM_ENVVALUE_UserName,			//user name
	E_FDRM_ENVVALUE_ProcessID,		//process ID
	E_FDRM_ENVVALUE_MAX				//MAX index of environment item
};


#ifdef __cplusplus
};
#endif


#endif

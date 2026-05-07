/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.	

*********************************************************************/


/**
 * @defgroup FRLayer Foxit Reader Layer
 */

/*@{*/

/**
 * @addtogroup FRAPP
 * @{
 */

/** @file fr_appExpT.h
 *  @brief 
 */

#ifndef FR_FXNETAPPEXPT_H
#define FR_FXNETAPPEXPT_H

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif



#ifndef FR_DOCEXPT_H
#include "fr_docExpT.h"
#endif

#ifndef FR_VIEWEXPT_H
#include "fr_viewExpT.h"
#endif

#ifndef FR_BAREXPT_H
#include "fr_barExpT.h"
#endif

#ifndef FR_MENUEXPT_H
#include "fr_menuExpT.h"
#endif


#ifndef FPD_DOCEXPT_H
#include "../pdf/fpd_docExpT.h"
#endif

#ifndef FPD_RENDEREXPT_H
#include "../pdf/fpd_renderExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif
	typedef struct _fr_appeventfxnet_callbacks_
	{
		/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_AppEventCallbacksRec</a>). */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;
		//#7392-BEGIN-FXNET-HCM 升级方案改后，主程序启动慢
		//#11353-FXNET-HCM 2018-0712 延迟加载,处理主程序启动慢问题
		void(*FRAppOnDelayLoadPlugin)(FS_LPVOID clientData);
		//#7392-END-FXNET-HCM 升级方案改后，主程序启动慢
		void(*FRAppOnRibbonCategoryChange)(FS_LPVOID clientData);
		void(*FRAppOnPDFViewerFinishRender)(FS_LPVOID clientData);
		void(*FRAppOnMainFrameOnMove)(FS_LPVOID clientData, HWND hMainframe);
	}FR_AppEventFxNetCallbacksRec, *FR_AppEventFxNetCallbacks;
#ifdef __cplusplus
};
#endif
#endif//FR_APPEXPT_H
/*@}*/ 


/*@}*/ 
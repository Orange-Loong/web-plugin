

#ifndef FOFD_RENDERIMPL_H
#define FOFD_RENDERIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FOFD_BASICEXPT_H
#include "../fofd_basicExpt.h"
#endif

#ifndef FOFD_OBJEXPT_H
#include "../fofd_objExpT.h"
#endif

#ifndef FOFD_DOCEXPT_H
#include "../fofd_docExpT.h"
#endif

#ifndef FOFD_PAGEEXPT_H
#include "../fofd_pageExpT.h"
#endif

#ifndef FOFD_RENDEREXPT_H
#include "../fofd_renderExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/************************************************************************/
/*                      OFD Render	                                    */
/************************************************************************/
class CFOFD_RenderOptions_V10
{
public:
	
};

class CFOFD_RenderContext_V10
{
public:
	
};

class CFOFD_RenderDevice_V10
{
public:	
	static void						SaveBitmap(FS_DIBitmap pDIBitmap, FS_WideString sPathBMP);
};

class CFOFD_ProgressiveRenderer_V10
{
public:
	
};

#ifdef __cplusplus
};
#endif

#endif//FOFD_PAGEIMPL_H

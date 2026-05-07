#ifndef FOFD_SIGNIMPL_H
#define FOFD_SIGNIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FOFD_SIGNATUREEXPT_H
#include "../fofd_sigExpt.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

class CFOFD_Sign_V10
{
public:
	static FS_DIBitmap				CreateSealBitmap(FS_ByteString bsSealData);
};

#ifdef __cplusplus
};
#endif

#endif//FOFD_SIGNIMPL_H

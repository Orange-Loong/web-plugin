#ifndef FS_INTERNALINC_H
#define FS_INTERNALINC_H

#include "../../../ExternalModule/fxcore/include/fpdfapi/fpdf_module.h" 
#include "../../../ExternalModule/fxcore/include/fpdfapi/fpdf_render.h" 
#include "../../../ExternalModule/fxcore/include/fpdfapi/fpdf_pageobj.h" 
#include "../../../ExternalModule/fxcore/include/fpdftext/fpdf_text.h"
#include "../../../ExternalModule/fxcore/include/fxge/fx_ge_win32.h"
#include "../../../ExternalModule/fxcore/include/fxcodec/fx_codec.h"
#include "../../../ExternalModule/fxcore/include/fxge/fx_ge.h"
#include "../../../ExternalModule/fxcore/include/fpdfapi/fpdf_serial.h" 
#include "../../../ExternalModule/fxcore/include/fpdfdoc/fpdf_doc.h" 
#include "../../../ExternalModule/fxcore/include/fpdfdoc/fpdf_vt.h" 
#include "../../../ExternalModule/fxcore/include/fxcrt/fx_xml.h" 
#include "../../../ExternalModule/fxcore/include/FDRM/fdrm.h"
#include "../../../ExternalModule/fxcore/include/fxcrt/fx_memory.h"


#include "../../../ExternalModule/fxcore/include/fpdfapi/fpdf_page.h" 
#include "../../../ExternalModule/fxcore/include/fpdfapi/fpdf_parser.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/ipath_editor.h" 
#include "../../../ExternalModule/middle_layer/pageeditor/include/ipath_object_utils.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/ishading_editor.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/ishading_object_utils.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/itext_editor.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/itext_object_utils.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/graphic_object.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/igraphic_editor.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/iimage_editor.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/igraphicobject_utils.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/iundo.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/ipage_editor.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/image_editor_option_data.h"
#include "../../../ExternalModule/middle_layer/pageeditor/include/iimage_object_utils.h"

#include "../../../ExternalModule/middle_layer/touchup/include/graphic_object.h"
#include "../../../ExternalModule/middle_layer/touchup/include/ijoin_split.h"
#include "../../../ExternalModule/middle_layer/touchup/include/itouchup.h"
#include "../../../ExternalModule/middle_layer/touchup/include/itouchup_manager.h"
#include "../../../ExternalModule/middle_layer/touchup/include/iundo.h"
#include "../../../ExternalModule/middle_layer/touchup/include/tc_data_structure.h"
#include "../../../ExternalModule/middle_layer/touchup/include/touchup_provider.h"
#include "../../../ExternalModule/middle_layer/touchup/include/ifind_replace.h"
#include "../../../ExternalModule/middle_layer/touchup/include/Itouchup_spellcheck.h"

#include "../../../ExternalModule/fxcore/include/pdfwindow/pwl_icon.h"
#include "../../../ExternalModule/fxcore/include/pdfwindow/pwl_label.h"
#include "../../../ExternalModule/fxcore/include/pdfwindow/pwl_wnd.h"

#include "../../../ExternalModule/middle_layer/portfolio/include/fpdf_ptldef.h"
#include "../../../ExternalModule/middle_layer/portfolio/include/fpdf_portfolio.h"
#ifndef FX_READER_DLL
//#define FX_READER_DLL
#endif

/*
#ifdef FX_READER_DLL
#ifdef _DEBUG
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/dbg_w32_vc6/fxcoredll[dbg_x86_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/dbg_w32_vc6/fpdfdocdll[dbg_x86_vc6].lib")
#else
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/rel_w32_vc6/fxcoredll[rel_x86_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/rel_w32_vc6/fpdfdocdll[rel_x86_vc6].lib")
#endif 
#else
#ifdef _DEBUG
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/dbg_w32_vc6/fpdfapi[dbg_x86_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/dbg_w32_vc6/fpdfdoc[dbg_x86_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/dbg_w32_vc6/fxcodec[dbg_x86_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/dbg_w32_vc6/fxcrt[dbg_x86_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/dbg_w32_vc6/fxge[dbg_x86_win32_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/dbg_w32_vc6/fpdftext[dbg_x86_vc6].lib")
//	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/dbg_w32_vc6/fcodec[dbg_x86_vc6].lib")
#else
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/rel_w32_vc6/fpdfapi[rel_x86_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/rel_w32_vc6/fpdfdoc[rel_x86_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/rel_w32_vc6/fxcodec[rel_x86_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/rel_w32_vc6/fxcrt[rel_x86_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/rel_w32_vc6/fxge[rel_x86_win32_vc6].lib")
	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/rel_w32_vc6/fpdftext[rel_x86_vc6].lib")
//	#pragma comment(lib, "../../../ExternalModule/fxcore/Lib/rel_w32_vc6/fcodec[rel_x86_vc6].lib")
#endif



#endif
*/

#include "fs_common.h"
#include "fs_basicExpT.h"
#include "fs_stringExpT.h"
#include "commonstub.h"

#endif //FS_INTERNALINC_H
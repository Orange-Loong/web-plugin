#include <type_traits>
#include "../pdf/fpd_objsExpT.h"
namespace fxFPD {
	template<class T> struct PDFObjType {
		static constexpr int value = PDFOBJ_INVALID;
	};

#define fxPDFBIND(Class,Type) template<> struct PDFObjType <Class> {static constexpr int value = Type;  }
	fxPDFBIND(CPDF_Boolean, PDFOBJ_BOOLEAN);
	fxPDFBIND(CPDF_Number, PDFOBJ_NUMBER);
	fxPDFBIND(CPDF_String, PDFOBJ_STRING);
	fxPDFBIND(CPDF_Name, PDFOBJ_NAME);
	fxPDFBIND(CPDF_Array, PDFOBJ_ARRAY);
	fxPDFBIND(CPDF_Dictionary, PDFOBJ_DICTIONARY);
	fxPDFBIND(CPDF_Stream, PDFOBJ_STREAM);
	fxPDFBIND(CPDF_Null, PDFOBJ_NULL);
	fxPDFBIND(CPDF_Reference, PDFOBJ_REFERENCE);
#undef fxPDFBIND


	template<class T, std::enable_if_t<std::is_base_of_v<CPDF_Object, T>, int> = 0>
	inline T* cast(FPD_Object pObj) {
		return (pObj && PDFObjType<T>::value == cast<CPDF_Object>(pObj)->GetType()) ? reinterpret_cast<T*>(pObj) : nullptr;
	}
	template<>
	inline CPDF_Object* cast<CPDF_Object, 0>(FPD_Object pObj) {
		return reinterpret_cast<CPDF_Object*>(pObj);
	}
}
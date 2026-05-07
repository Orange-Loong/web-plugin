#ifndef FPD_LRIMPL_H
#define FPD_LRIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_LREXPT_H
#include "../fpd_lrExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "../fpd_parserExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "../fpd_objsExpT.h"
#endif

#ifndef FPD_RESOURCEIMPL_H
#include "../fpd_resourceExpT.h"
#endif

#ifndef FPD_RESOURCEIMPL_H
#include "../fpd_renderExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

class CFPD_LRContext_V16
{
public:
	//************************************
	// Function: CreatePageContext
	// Param[in]: pPage          The input FPD_Page object.	
	// Return: FPD_LR_Context    Create page context.
	// Remarks:	Create page context.
	// Notes:	
	//************************************ 
    static FPD_LR_Context CreatePageContext(FPD_Page pPage);

	//************************************
	// Function: Continue
	// Param[in]: context          The input FPD_LR_Context object.	
	// Param[in]: pPause           Simple pause interface.
	// Return: void
	// Remarks:	Start processing elements.
	// Notes:	
	//************************************ 
	static FPD_ProgressiveStatus Continue(FPD_LR_Context context, FS_PauseHandler pPause);

	//************************************
	// Function: Release
	// Param[in]: context          The input FPD_LR_Context object.	
	// Return: void
	// Remarks:	Destroy this context.
	// Notes:	The structure tree should be retrieved by GetRootElement()
	// and destroyed separately by ReleaseStructureTree().
	//************************************ 
	static void Release(FPD_LR_Context context);

	//************************************
	// Function: GetRootElement
	// Param[in]: context          The input FPD_LR_Context object.	
	// Param[out]: eleRef          Get The root element.
	// Return: void
	// Remarks:	Retrieve pointer to the root element of the structure tree when successful.
	// Notes:	
	//************************************ 
	static void GetRootElement(FPD_LR_Context context, FPD_LR_StructureElementRef* eleRef);

	//************************************
	// Function: ReleaseStructureTree	
	// Param[in]: pRoot            The root element.
	// Return: void
	// Remarks:	To release structure tree we constructed.
	// Notes:	
	//************************************ 
	static void ReleaseStructureTree(FPD_LR_ElementRef pRoot);

	//************************************
	// Function: Start
	// Param[in]: context          The input FPD_LR_Context object.		
	// Return: FPD_ProgressiveStatus   Enum value ,like done,fail,ready.
	// Remarks: Start initializing Context.
	// Notes: It need set FPD_LR_AnalysisOptions first. FPD_LR_AnalysisOptions get from FPDLRContextAnalysisOptions.
	//************************************ 
	static FPD_ProgressiveStatus Start(FPD_LR_Context context);

	//************************************
	// Function: ReleaseStructureTree2	
	// Param[in]: pRoot            The input struct element.
	// Return: void
	// Remarks:	To release struct element.
	// Notes:	
	//************************************ 
	static void ReleaseStructureTree2(FPD_LR_StructureElementRef structEleRef);
	
	//************************************
	// Function: AnalysisOptions	
	// Param[in]: context            The input FPD_LR_Context object.
	// Return: FPD_LR_AnalysisOptions
	// Remarks:	Retrieve pointer of current page context's analysis option.
	// Notes:	
	//************************************ 
	static FPD_LR_AnalysisOptions AnalysisOptions(FPD_LR_Context context);
};

class CFPD_LRStructureElementRef_V16
{
public:
	//************************************
	// Function: Create	
	// Return: FPD_LR_StructureElementRef    Create struct element.
	// Remarks:	 Create struct element.
	// Notes:	
	//************************************    
	static FPD_LR_StructureElementRef Create();

	//************************************
	// Function: Destroy	
	// Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.
	// Return: void
	// Remarks:	 Release struct element.
	// Notes:	
	//************************************    
	static void Destroy(FPD_LR_StructureElementRef structEleRef);

	//************************************
	// Function: GetChildren
	// Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.
	// Param[out]: pListRef             Get the child Elements of this structure element.
	// Return: void
	// Remarks:	 A function to get the child Elements of this structure element.
	// Notes:	
	//************************************    
	static void  GetChildren(FPD_LR_StructureElementRef structEleRef, FPD_LR_ElementListRef* pListRef);

	//************************************
	// Function: GetStdStructureType
	// Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.
	// Return: FPD_LRStdStructElemType  The sequence number of type in FPDFLR_StdStructElemType.
	// Remarks:	 A function to the get the type of structure element.
	// Notes:
	// See: FPDLRContextGetRootElement
	//************************************     
	static FPD_LRStdStructElemType GetStdStructureType(FPD_LR_StructureElementRef structEleRef);

	//************************************
	// Function: IsNull
	// Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.
	// Return: FS_BOOL  The sequence number of type in FPDFLR_StdStructElemType.
	// Remarks:	 Check element is null.
	// Notes:
	// See: 
	//************************************     
	static FS_BOOL IsNull(FPD_LR_StructureElementRef structEleRef);
	
	 //************************************
	 // Function: GetStdAttrValueFloat
	 // Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.
	 // Param[in]: attr					 The attr Layout attribute type.
	 // Param[in]: defvalue              Default value of Layout attribute Float.
	 // Param[in]: index				 The sequence number in array if it's a array.
	 // Return: FS_BOOL  The value of Float.
	 // Remarks: To the get the value of Float type.
	 // Notes:
	 // See: 
	 //************************************  
	static FS_FLOAT GetStdAttrValueFloat(FPD_LR_StructureElementRef structEleRef,FPDLR_StdAttr attr, FS_FLOAT defvalue, FS_INT32 index);
	
	 //************************************
	 // Function: GetElementType
	 // Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.	
	 // Return: FS_DWORD  The type of element.
	 // Remarks: This is a function to get the type of element,like it's a pageobj
	 // element, structure element or TextObj element and so on.
	 // Notes:
	 // See: 
	 //************************************  
	static FS_DWORD GetElementType(FPD_LR_StructureElementRef structEleRef);
	
	 //************************************
	 // Function: GetParentElement
	 // Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.	
	 // Param[out]: parentRef            Get the parent Element of this structure element.
	 // Return: FS_BOOL   TRUE: Get the parent element success.
	 // Remarks:  To the get the parent Element of this structure element.
	 // Notes:
	 // See: 
	 //************************************  
	static FS_BOOL GetParentElement(FPD_LR_StructureElementRef structEleRef, FPD_LR_StructureElementRef* parentRef);
	
	 //************************************
	 // Function: AsStructureElement
	 // Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.	
	 // Param[out]: elementRef           Get the struct element.
	 // Return: FS_BOOL   TRUE: Get struct element success.
	 // Remarks:  Get the structure element.
	 // Notes:
	 // See: 
	 //************************************  
	static FS_BOOL AsStructureElement(FPD_LR_StructureElementRef structEleRef, FPD_LR_StructureElementRef* elementRef);
	
	 //************************************
	 // Function: GetBBox
	 // Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.	
	 // Param[in]: iBBoxIndex            To indicate which the block used,when the page object passed many pages(eg.table).
	 // Return: FS_FloatRect            Get the bounding box.
	 // Remarks:  To get the bounding box of this structure element.
	 // Notes:
	 // See: 
	 //************************************
	static FS_FloatRect GetBBox(FPD_LR_StructureElementRef structEleRef, FS_INT32 iBBoxIndex);

	//************************************
	 // Function: IsEqual
	 // Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.	
	 // Param[in]: structEleRef2         The input structEleRef2 need to compare.
	 // Return: FS_BOOLEAN            
	 // Remarks:  Compare two FPD_LR_StructureElementRef object.
	 // Notes:
	 // See: 
	 //************************************
	static FS_BOOLEAN  IsEqual(FPD_LR_StructureElementRef structEleRef, FPD_LR_StructureElementRef structEleRef2);
	
	//************************************
	 // Function: GetStdAttrType
	 // Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.	
	 // Param[in]: attr                  The input layout attribute type.
	 // Param[in]: length                The length of an array.
	 // Return: FPDLR_StdAttrValueType   The sequence number of attribute value type.       
	 // Remarks:  To get the type of structure element.
	 // Notes:
	 // See: 
	 //************************************
	static FPDLR_StdAttrValueType GetStdAttrType(FPD_LR_StructureElementRef structEleRef, FPDLR_StdAttr attr, FS_INT32* length);

	//************************************
	 // Function: GetStdAttrValueEnum
	 // Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.	
	 // Param[in]: attr                  The input layout attribute type.
	 // Param[in]: defvalue              Default value of Layout attribute enum.
	 // Param[in]: index                 The sequence number in array if it's a array .
	 // Return: FPDLR_StdAttrValueEnum   The layout attribute value in enumeration values.       
	 // Remarks:  To get the value of Enum type.
	 // Notes:
	 // See: 
	 //************************************
	static FPDLR_StdAttrValueEnum GetStdAttrValueEnum(FPD_LR_StructureElementRef structEleRef, FPDLR_StdAttr attr,
		FPDLR_StdAttrValueEnum defvalue, FS_INT32 index);

	//************************************
	// Function: GetStdAttrValueInt32
	// Param[in]: structEleRef          The input FPD_LR_StructureElementRef object.	
	// Param[in]: attr                  The input layout attribute type.
	// Param[in]: defvalue              Default value of Layout attribute Int32.
	// Param[in]: index                 The sequence number in array if it's a array .
	// Return: FS_INT32   The value of Int32.
	// Remarks:  To get the value of Int32 type.
	// Notes:
	// See: 
	//************************************
	static FS_INT32 GetStdAttrValueInt32(FPD_LR_StructureElementRef structEleRef, FPDLR_StdAttr attr, FS_INT32 defvalue, FS_INT32 index);
};

class CFPD_LRElementListRef_V16
{
public:
	//************************************
	// Function: Create	
	// Return: FPD_LR_ElementListRef    Create element of the list.
	// Remarks:	 Create element of the list.
	// Notes:	
	//************************************    
	static FPD_LR_ElementListRef Create();

	//************************************
	// Function: Destroy	
	// Param[in]: structEleRef          The input FPD_LR_ElementListRef object.
	// Return: void
	// Remarks:	 Release element of the list.
	// Notes:	
	//************************************    
	static void Destroy(FPD_LR_ElementListRef elementListRef);

	//************************************
	// Function: GetSize
	// Param[in]: elementListRef          The input FPD_LR_ElementListRef object.
	// Return: FS_INT32                   The size of the list.
	// Remarks:	 Get size of the element list.
	// Notes:
	// See: FPDLRContextGetRootElement
	//************************************ 
	static FS_INT32		  GetSize(FPD_LR_ElementListRef elementListRef);

	//************************************
	// Function: GetAt
	// Param[in]: elementListRef          The input FPD_LR_ElementListRef object.
	// Param[in]: nIndex                  The index of the list.
	// Param[out]: pRef                   Get element of the list.
	// Return: void
	// Remarks:	 Get element of the list.
	// Notes:
	// See: FPDLRContextGetRootElement
	//************************************ 
	static void GetAt(FPD_LR_ElementListRef elementListRef, FS_INT32 nIndex, FPD_LR_ElementRef* pRef);
};

class CFPD_LRElementRef_V16
{
public:
	//************************************
	// Function: Create	
	// Return: FPD_LR_ElementRef    Create element.
	// Remarks:	 Create element.
	// Notes:	
	//************************************    
	static FPD_LR_ElementRef Create();

	//************************************
	// Function: Destroy	
	// Param[in]: elementRef          The input FPD_LR_ElementRef object.
	// Return: void
	// Remarks:	 Release element.
	// Notes:	
	//************************************    
	static void Destroy(FPD_LR_ElementRef elementRef);

	//************************************
	// Function: AsStructureElement
	// Param[in]: elementRef          The input FPD_LR_ElementRef object.	
	// Param[out]: structref          Get the structureElement.
	// Return: void
	// Remarks:	 Get the structureElement.
	// Notes:	
	//************************************ 
	static void AsStructureElement(FPD_LR_ElementRef elementRef, FPD_LR_StructureElementRef* structref);

	//************************************
	// Function: GetElementType
	// Param[in]: elementRef          The input FPD_LR_ElementRef object.	
	// Return: FS_DWORD               Get the type of element.
	// Remarks:	 This is a function to get the type of element,like it's a pageobj
	// element, structure element or TextObj element and so on.
	// Notes:	
	//************************************ 
	static FS_DWORD GetElementType(FPD_LR_ElementRef elementRef);

	//************************************
	// Function: AsContentElement
	// Param[in]: elementRef                The input FPD_LR_ElementRef object.	
	// Param[out]: contentref               Get the contentElement.
	// Return: void
	// Remarks:	  A function to the get the ContentElement.
	// Notes:	
	//************************************ 
	static void  AsContentElement(FPD_LR_ElementRef elementRef, FPD_LR_ContentElementRef* contentref);

	//************************************
	// Function: LR_ISCONTENTTYPE
	// Param[in]: elementType                The input element type.	
	// Return: FS_BOOL
	// Remarks:	  Check is content type.
	// Notes:	
	//************************************ 
	static FS_BOOL LR_ISCONTENTTYPE(FS_DWORD elementType);

	//************************************
	// Function: LR_IS_PAGEOBJTYPE
	// Param[in]: elementType                The input element type.	
	// Return: FS_BOOL
	// Remarks:	  Check is pageobject type.
	// Notes:	
	//************************************ 
	static FS_BOOL LR_IS_PAGEOBJTYPE(FS_DWORD elemType);

	//************************************
	// Function: LR_IS_STRUCTURETYPE
	// Param[in]: elementType                The input element type.	
	// Return: FS_BOOL
	// Remarks:	  Check is structure type.
	// Notes:	
	//************************************ 
	static FS_BOOL LR_IS_STRUCTURETYPE(FS_DWORD elemType);
};

class CFPD_LRContentElementRef_V16
{
public:
	//************************************
	// Function: Create	
	// Return: FPD_LR_ContentElementRef    Create content element.
	// Remarks:	 Create struct element.
	// Notes:	
	//************************************    
	static FPD_LR_ContentElementRef Create();

	//************************************
	// Function: Destroy	
	// Param[in]: contentEleRef          The input FPD_LR_ContentElementRef object.
	// Return: void
	// Remarks:	 Release content element.
	// Notes:	
	//************************************    
	static void Destroy(FPD_LR_ContentElementRef contentEleRef);

	//************************************
	// Function: GetPageObjectElement
	// Param[in]: contentEleRef               The input FPD_LR_ContentElementRef object.	
	// Param[out]: pageobjEleObj              Get the page object Element of this Content element.
	// Return: void    
	// Remarks:	  The function to the get the page object Element of this Content element.
	// Notes:	
	//************************************ 
	static void GetPageObjectElement(FPD_LR_ContentElementRef contentEleRef, FPD_LR_PageObjectElementRef* pageobjEleObj);

	//************************************
	// Function: GetPageObjectRange
	// Param[in]: contentEleRef            The input FPD_LR_ContentElementRef object.	
	// Param[out]: nStartPos               Get start position of this content element in this page object.	
	// Param[out]: nLength                 Get the size of page object we need.
	// Return: FS_BOOLEAN                  Whether this function get the range of page object.
	// Remarks:	  The function to get the range of page object.
	// Notes:	
	//************************************ 
	static FS_BOOLEAN GetPageObjectRange(FPD_LR_ContentElementRef contentEleRef, FS_INT32* nStartPos, FS_INT32* nLength);

	//************************************
	// Function: GetBBox
	// Param[in]: contentEleRef            The input FPD_LR_ContentElementRef object.	
	// Param[out]: rcBBox                  Get the bounding box.
	// Param[in]: bTransformed             Whether need switch to the page's coordinate.
	// Return: void                  
	// Remarks:	  The function to get the bounding box of this Content element.
	// Notes:	
	//************************************ 
	static void GetBBox(FPD_LR_ContentElementRef contentEleRef, FS_FloatRect* rcBBox, FS_BOOLEAN bTransformed);

	//************************************
	// Function: GetElementType
	// Param[in]: contentEleRef            The input FPD_LR_ContentElementRef object.		
	// Return: FS_DWORD   return the type of element.                
	// Remarks: This is a function to get the type of element,like it's a pageobj
	// element, structure element or TextObj element and so on.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0
	//************************************ 
	static FS_DWORD GetElementType(FPD_LR_ContentElementRef contentEleRef);
};


class CFPD_LRPageObjectElementRef_V16
{
public:
	//************************************
	// Function: Create	
	// Return: FPD_LR_PageObjectElementRef    Create Page Object element.
	// Remarks:	 Create Page Object element.
	// Notes:	
	//************************************    
	static FPD_LR_PageObjectElementRef Create();

	//************************************
	// Function: Destroy	
	// Param[in]: pageobjectEleRef          The input FPD_LR_PageObjectElementRef object.
	// Return: void
	// Remarks:	 Release Page Object element.
	// Notes:	
	//************************************    
	static void Destroy(FPD_LR_PageObjectElementRef pageobjectEleRef);

	//************************************
	// Function: GetBBox
	// Param[in]: pageobjectEleRef         The input FPD_LR_PageObjectElementRef object.	
	// Param[out]: rcBBox                  Get the bounding box.
	// Param[in]: bTransformed             Whether need switch to the page's coordinate.
	// Return: void                  
	// Remarks:	  The function to get the bounding box of this Page Object element.
	// Notes:	
	//************************************ 
	static void GetBBox(FPD_LR_PageObjectElementRef pageobjectEleRef, FS_FloatRect* rcBBox, FS_BOOLEAN bTransformed);

	//************************************
	// Function: GetDict
	// Param[in]: pageobjectEleRef         The input FPD_LR_PageObjectElementRef object.	
	// Return: FPD_Object                  Get the dictionary or dictionary of stream.             
	// Remarks:	  The function to the get the annot or xobject dictionary of this page object.
	// Notes:	
	//************************************ 
	static FPD_Object GetDict(FPD_LR_PageObjectElementRef pageobjectEleRef);
	
	 //************************************
	 // Function: GetPageObject
	 // Param[in]: pageobjectEleRef         The input FPD_LR_PageObjectElementRef object.	
	 // Return: FPD_PageObject              Get the Page Object of this Page Object element.            
	 // Remarks:	  The function to to the get the page object of this Page Object element.
	 // Notes:	
	 //************************************ 
	static FPD_PageObject GetPageObject(FPD_LR_PageObjectElementRef pageobjectEleRef);
	
	//************************************
	// Function: GetElementType
	// Param[in]: pageobjectEleRef         The input FPD_LR_PageObjectElementRef object.	
	// Return: FS_DWORD              return the type of element. Like FPDLR_ET_TextObject.          
	// Remarks:	This is a function to get the type of element,like it's a pageobj
	// element, structure element or TextObj element and so on.
	// Notes:	
	//************************************ 
	static FS_DWORD GetElementType(FPD_LR_PageObjectElementRef pageobjectEleRef);

	//************************************
	// Function: GetParentPageObject
	// Param[in]: pageobjectEleRef         The input FPD_LR_PageObjectElementRef object.	
	// Param[out]: outParentPageObj        Get the parent Element of this Page Object element.
	// Return: FS_BOOL     TRUE: Get the parent page object success.       
	// Remarks: Get the parent Element of this Page Object element.
	// Notes:	
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.1.0
	//************************************ 
	static FS_BOOL GetParentPageObject(FPD_LR_PageObjectElementRef pageobjectEleRef, FPD_LR_PageObjectElementRef* outParentPageObj);
};

class CFPD_LRParseOptions_V16
{
public:
	//************************************
	// Function: Create	
	// Return: FPD_LR_ParseOptions    Create FPD_LR_ParseOptions.
	// Remarks:	 Create FPD_LR_ParseOptions.
	// Notes:	
	//************************************   
	static FPD_LR_ParseOptions Create();

	//************************************
	// Function: Delete	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: void          
	// Remarks:	 Delete FPD_LR_ParseOptions.
	// Notes:	
	//************************************   
	static void Delete(FPD_LR_ParseOptions option);

	//************************************
	// Function: GetRecognizeDivision	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_BOOLEAN          
	// Remarks:	 To indicate whether use division.
	// Notes:	
	//************************************   
	static FS_BOOLEAN GetRecognizeDivision(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetRecognizeDivision	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: bRecognize         Whether use division.
	// Return: void          
	// Remarks:	 To indicate whether use division.
	// Notes:	
	//************************************   
	static void SetRecognizeDivision(FPD_LR_ParseOptions option, FS_BOOLEAN bRecognize);

	//************************************
	// Function: GetLRVersion	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_INT32          
	// Remarks:	To indicate the LR version used.
	// Notes:	
	//************************************  
	static FS_INT32 GetLRVersion(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetLRVersion	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: version            The input LR version.
	// Return: void          
	// Remarks:	To indicate the LR version used.
	// Notes:	
	//************************************  
	static void SetLRVersion(FPD_LR_ParseOptions option, FS_INT32 version);

	//************************************
	// Function: GetProfile	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_DWORD          
	// Remarks:	To select the LR analysis method.
	// Notes:	
	//************************************ 
	static FS_DWORD GetProfile(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetProfile	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: profile            The input LR analysis method.
	// Return: void          
	// Remarks:	To select the LR analysis method.
	// Notes:	
	//************************************ 
	static void SetProfile(FPD_LR_ParseOptions option, FS_DWORD profile);

	//************************************
	// Function: GetUsePageMatrix	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_BOOLEAN          
	// Remarks:	To indicate whether use PageMatrix.	
	// Notes:	
	//************************************ 
	static FS_BOOLEAN GetUsePageMatrix(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetUsePageMatrix	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: bUsePageMatrix     The input if use PageMatrix.	
	// Return: FS_BOOLEAN          
	// Remarks:	To indicate whether use PageMatrix.	
	// Notes:	
	//************************************ 
	static void SetUsePageMatrix(FPD_LR_ParseOptions option, FS_BOOLEAN bUsePageMatrix);

	//************************************
	// Function: GetOCContext	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FPD_OCContext          
	// Remarks:	To indicate OC context.	
	// Notes:	
	//************************************ 
	static FPD_OCContext GetOCContext(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetOCContext	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: pOCContext         The input OC context.	
	// Return: void          
	// Remarks:	To indicate OC context.	
	// Notes:	
	//************************************ 
	static void SetOCContext(FPD_LR_ParseOptions option, FPD_OCContext pOCContext);

	//************************************
	// Function: GetSelectionRect	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_FloatRect          
	// Remarks:	To indicate the selection rect.
	// Notes:	
	//************************************ 
	static FS_FloatRect GetSelectionRect(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetSelectionRect	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: rect               The input selection rect.
	// Return: void          
	// Remarks:	To indicate the selection rect.
	// Notes:	
	//************************************ 
	static void SetSelectionRect(FPD_LR_ParseOptions option, FS_FloatRect rect);

	//************************************
	// Function: GetRecognizeFontConservatively	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_BOOLEAN          
	// Remarks:	To indicate whether recognize font conservatively.
	// Notes:	
	//************************************ 
	static FS_BOOLEAN GetRecognizeFontConservatively(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetRecognizeFontConservatively	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: bRecognize         The input whether recognize font conservatively.
	// Return: FS_BOOLEAN          
	// Remarks:	To indicate whether recognize font conservatively.
	// Notes:	
	//************************************ 
	static void SetRecognizeFontConservatively(FPD_LR_ParseOptions option, FS_BOOLEAN bRecognize);

	//************************************
	// Function: GetEnableLayoutAnalyze	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_BOOLEAN          
	// Remarks:	To indicate whether enable layout analyze.
	// Notes:	
	//************************************ 
	static FS_BOOLEAN GetEnableLayoutAnalyze(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetEnableLayoutAnalyze	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: bEnableLayout      The input whether recognize font conservatively.
	// Return: FS_BOOLEAN          
	// Remarks:	To indicate whether enable layout analyze.
	// Notes:	
	//************************************ 
	static void SetEnableLayoutAnalyze(FPD_LR_ParseOptions option, FS_BOOLEAN bEnableLayout);

	//************************************
	// Function: GetEnableTableContainsFloat	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_BOOLEAN          
	// Remarks:	To indicate whether enable table contains float.
	// Notes:	
	//************************************ 
	static FS_BOOLEAN GetEnableTableContainsFloat(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetEnableTableContainsFloat	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: bEnable            The input whether enable table contains float.
	// Return: FS_BOOLEAN          
	// Remarks:	To indicate whether enable table contains float.
	// Notes:	
	//************************************ 
	static void SetEnableTableContainsFloat(FPD_LR_ParseOptions option, FS_BOOLEAN bEnable);

	//************************************
	// Function: GetKeepContainerConsistency	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_BOOLEAN          
	// Remarks:	To indicate whether keep container consistency.
	// Notes:	
	//************************************ 
	static FS_BOOLEAN GetKeepContainerConsistency(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetKeepContainerConsistency	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: bKeep              The input  whether keep container consistency.
	// Return: FS_BOOLEAN          
	// Remarks:	To indicate whether keep container consistency.
	// Notes:	
	//************************************ 
	static void SetKeepContainerConsistency(FPD_LR_ParseOptions option, FS_BOOLEAN bKeep);

	//************************************
	// Function: GetNNCfgName	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_LPCSTR          
	// Remarks:	To indicate NNC name.
	// Notes:	
	//************************************ 
	static FS_LPCSTR GetNNCfgName(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetNNCfgName	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: name               The input  NNC name.
	// Return: void          
	// Remarks:	To indicate NNC name.
	// Notes:	
	//************************************ 
	static void SetNNCfgName(FPD_LR_ParseOptions option, FS_LPCSTR name);

	//************************************
	// Function: GetNNWeightsName	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_LPCSTR          
	// Remarks:	To indicate NNC weight name.
	// Notes:	
	//************************************ 
	static FS_LPCSTR GetNNWeightsName(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetNNWeightsName	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: name               The input NNC weight name.
	// Return: void          
	// Remarks:	To indicate NNC weight name.
	// Notes:	
	//************************************ 
	static void SetNNWeightsName(FPD_LR_ParseOptions option, FS_LPCSTR name);

	//************************************
	// Function: GetNNConfidenceLevel	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Return: FS_FLOAT          
	// Remarks:	To indicate confidence level.
	// Notes:	
	//************************************ 
	static FS_FLOAT GetNNConfidenceLevel(FPD_LR_ParseOptions option);

	//************************************
	// Function: SetNNConfidenceLevel	
	// Param[in]: option             The input FPD_LR_ParseOptions object.
	// Param[in]: level              The input confidence level.
	// Return: void          
	// Remarks:	To indicate confidence level.
	// Notes:	
	//************************************ 
	static void SetNNConfidenceLevel(FPD_LR_ParseOptions option, FS_FLOAT level);
};

class CFPD_LRAnalysisOptions_V17
{
public:
	//************************************
	// Function: SetOptionString
	// Param[in]: option             The input FPD_LR_AnalysisOptions.
	// Param[in]: sName              The input setting name.
	// Param[in]: sInput             The input setting value.
	// Return: FS_BOOLEAN    true: set success.
	// Remarks:	 Set option string.
	// Notes:	
	//************************************   
	static FS_BOOLEAN SetOptionString(FPD_LR_AnalysisOptions option, FS_LPCSTR sName, FS_LPCSTR sInput);

	//************************************
	// Function: GetSupportedOptions
	// Param[in]: option             The input FPD_LR_AnalysisOptions.
	// Param[in\out]: rgOptions      Get supperted options.
	// Return: FS_INT32    The count of supperted options.
	// Remarks:	 Get supperted options.
	// Notes:	
	//************************************   
	static FS_INT32 GetSupportedOptions(FPD_LR_AnalysisOptions option,  FS_ByteStringArray* rgOptions);

	//************************************
	// Function: SetOptionInteger
	// Param[in]: option             The input FPD_LR_AnalysisOptions.
	// Param[in]: sName              The input setting name.
	// Param[in]: sInput             The input setting value.
	// Return: FS_BOOLEAN    true: set success.
	// Remarks:	 Set option integer value.
	// Notes:	
	//************************************  
	static FS_BOOLEAN SetOptionInteger(FPD_LR_AnalysisOptions option, FS_LPCSTR sName, FS_INT32 nInput);

	//************************************
	// Function: SetOptionFloat
	// Param[in]: option             The input FPD_LR_AnalysisOptions.
	// Param[in]: sName              The input setting name.
	// Param[in]: fInput             The input setting value.
	// Return: FS_BOOLEAN    true: set success.
	// Remarks:	 Set option float value.
	// Notes:	
	//************************************  
	static FS_BOOLEAN SetOptionFloat(FPD_LR_AnalysisOptions option, FS_LPCSTR sName, FS_FLOAT fInput);

	//************************************
	// Function: SetOptionBoolean
	// Param[in]: option             The input FPD_LR_AnalysisOptions.
	// Param[in]: sName              The input setting name.
	// Param[in]: bInput             The input setting value.
	// Return: FS_BOOLEAN    true: set success.
	// Remarks:	 Set option boolean value.
	// Notes:	
	//************************************  
	static FS_BOOLEAN SetOptionBoolean(FPD_LR_AnalysisOptions option, FS_LPCSTR sName, FS_BOOLEAN bInput);

	//************************************
	// Function: SetOptionFloatRect
	// Param[in]: option             The input FPD_LR_AnalysisOptions.
	// Param[in]: sName              The input setting name.
	// Param[in]: rcInput            The input setting value.
	// Return: FS_BOOLEAN    true: set success.
	// Remarks:	 Set option rect value.
	// Notes:	
	//************************************  
	static FS_BOOLEAN SetOptionFloatRect(FPD_LR_AnalysisOptions option, FS_LPCSTR sName, FS_FloatRect rcInput);

	//************************************
	// Function: SetOptionOCContext
	// Param[in]: option             The input FPD_LR_AnalysisOptions.
	// Param[in]: sName              The input setting name.
	// Param[in]: pInput            The input setting value.
	// Return: FS_BOOLEAN    true: set success.
	// Remarks:	 Set option OC context value.
	// Notes:	
	//************************************  
	static FS_BOOLEAN SetOptionOCContext(FPD_LR_AnalysisOptions option, FS_LPCSTR sName, FPD_OCContext pInput);
};

#ifdef __cplusplus
};
#endif

#endif


#ifndef FPD_PAGEIMPL_H
#define FPD_PAGEIMPL_H

#ifndef FS_INTERNALINC_H
#include "../../basic/fs_internalInc.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "../fpd_pageExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../fpd_docExpT.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus


class CFPD_Page_V1
{	
public:
	//************************************
	// Function: New
	// Param[in]: void
	// Return:    A new empty PDF page.
	// Remarks:   Creates a new empty PDF page.
	// Notes:
	//************************************
	static FPD_Page	New(void);

	//************************************
	// Function: Destroy
	// Param[in]: page The input PDF page.
	// Return:    void
	// Remarks:   Destroys the PDF page.
	// Notes:
	//************************************
	static void	Destroy(FPD_Page page);
	
	//************************************
	// Function:  ContinueParse
	// Param[in]: page				The input PDF page.
	// Param[in]: pauseHandler		The user-supplied pause handler.
	// Return:    void
	// Remarks:   Continue parsing.
	// Notes:
	//************************************
	static void	ContinueParse(FPD_Page page, FS_PauseHandler pauseHandler);

	//************************************
	// Function: GetParseState
	// Param[in]: page	The input PDF page.
	// Return:   The current parsing state:
	//            <ul><li>FPD_CONTENT_NOT_PARSED</li>
    //            <li>FPD_CONTENT_PARSING</li>
    //            <li>FPD_CONTENT_PARSED</li></ul>
	// Remarks:  Gets the current parsing state.
	// Notes:
	//************************************
	static FS_INT32	GetParseState(FPD_Page page);

	//************************************
	// Function: IsParsed
	// Param[in]: page	The input PDF page.
	// Return:   <a>TRUE</a> if the content has been parsed into page objects, otherwise <a>FALSE</a>.
	// Remarks:  Checks whether the content has been parsed into page objects.
	// Notes:
	//************************************
	static FS_BOOL IsParsed(FPD_Page page);

	//************************************
	// Function: EstimateParseProgress
	// Param[in]: page	The input PDF page.
	// Return:   The percentage of parse progress.
	// Remarks:  Estimates the percentage of parse progress.
	// Notes:
	//************************************
	static FS_INT32	EstimateParseProgress(FPD_Page page);


	//************************************
	// Function: GetFirstObjectPosition
	// Param[in]: page	The input PDF page.
	// Return:   The position of the first page object.
	// Remarks:  Gets the position of the first page object.
	// Notes:
	//************************************
	static FS_POSITION GetFirstObjectPosition(FPD_Page page);

	//************************************
	// Function: GetLastObjectPosition
	// Param[in]: page	The input PDF page.
	// Return:   The position of the last page object
	// Remarks:  Gets the position of the last page object
	// Notes:
	//************************************
	static FS_POSITION GetLastObjectPosition(FPD_Page page);

	//************************************
	// Function:   GetNextObject
	// Param[in]:     page			The input PDF page.
	// Param[in,out]: inOutPos		The input current position, and receives the next position.
	// Return:   A page object.
	// Remarks:  Gets the current object and moves to next position.
	// Notes:
	//************************************
	static FPD_PageObject GetNextObject(FPD_Page page, FS_POSITION* inOutPos);

	//************************************
	// Function:   GetPrevObject
	// Param[in]:     page			The input PDF page.
	// Param[in,out]: inOutPos		The input current position, and receives the previous position.
	// Return:       A page object.
	// Remarks:      Gets the current object and moves to previous position
	// Notes:
	//************************************
	static FPD_PageObject GetPrevObject(FPD_Page page, FS_POSITION* inOutPos);

	//************************************
	// Function: GetObjectAt
	// Param[in]: page	The input PDF page.
	// Param[in]: pos	Specifies the position of the page object.
	// Return:   A page object.
	// Remarks:  Gets an object at specified position.
	// Notes:
	//************************************
	static FPD_PageObject GetObjectAt(FPD_Page page, FS_POSITION pos);

	//************************************
	// Function: CountObjects
	// Param[in]: page	The input PDF page.
	// Return:   The count of page objects in the collection.
	// Remarks:  Gets the count of page objects in the collection.
	// Notes:
	//************************************
	static FS_DWORD	CountObjects(FPD_Page page);

	//************************************
	// Function: GetObjectIndex
	// Param[in]: page		The input PDF page.
	// Param[in]: obj		The input page object.
	// Return:   The zero-based index of the page object.
	// Remarks:  Gets the zero-based page object index in the object array.
	// Notes:
	//************************************
	static FS_INT32	GetObjectIndex(FPD_Page page, FPD_PageObject obj);

	//************************************
	// Function: GetObjectByIndex
	// Param[in]: page		The input PDF page.
	// Param[in]: index		Specifies the zero-based index of the page object.
	// Return:   A page object.
	// Remarks:  Gets an object by a zero-based page object index.
	// Notes:
	//************************************
	static FPD_PageObject GetObjectByIndex(FPD_Page page, FS_INT32 index);


	//************************************
	// Function: ReplaceObject
	// Param[in]: page		The input PDF page.
	// Param[in]: pos		Specifies the position of the page object to be replaced.
	// Param[in]: newObj	The input new page object.
	// Return:   void
	// Remarks:  Replaces a page object with a new page object.
	// Notes:
	//************************************
	static void	ReplaceObject(FPD_Page page, FS_POSITION pos, FPD_PageObject newObj);

	//************************************
	// Function: InsertObject
	// Param[in]: page					The input PDF page.
	// Param[in]: posInsertAfter		Specifies the position to insert after.
	// Param[in]: newObj				The input new page object.
	// Return:   The position of inserted page object
	// Remarks:  Inserts a page object. To insert before all objects, use NULL for <param>posInsertAfter</param>.
	// Notes:
	//************************************
	static FS_POSITION InsertObject(FPD_Page page, FS_POSITION posInsertAfter, FPD_PageObject newObj);

	//************************************
	// Function: RemoveObject
	// Param[in]: page	The input PDF page.
	// Param[in]: pos	Specifies the position of the page object to be removed.
	// Return:  
	// Remarks:  Removes a page object.
	// Notes:
	//************************************
	static void	RemoveObject(FPD_Page page, FS_POSITION pos);

	//************************************
	// Function: MoveObject
	// Param[in]: page			The input PDF page.
	// Param[in]: pos			The original position of the page object.
	// Param[in]: newPosAfter	The new position to move after.
	// Return:   The new position of the page object.
	// Remarks:  Moves a page object from a position to another position.
	// Notes:
	//************************************
	static FS_POSITION MoveObject(FPD_Page page, FS_POSITION pos, FS_POSITION newPosAfter);

	//************************************
	// Function: DebugOutput
	// Param[in]: page				The input PDF page.
	// Param[in]: szFileName		The input file name.
	// Return:    void
	// Remarks:   Outputs debug information. For debug only: list all page objects.
	// Notes:
	//************************************
	static void DebugOutput(FPD_Page page, FS_LPSTR szFileName);

	//************************************
	// Function: Transform
	// Param[in]: page			The input PDF page.
	// Param[in]: matrix		The input transformation matrix.
	// Return:    void
	// Remarks:  Transforms all objects.
	// Notes:
	//************************************
	static void	Transform(FPD_Page page, FS_AffineMatrix matrix);

	//************************************
	// Function: BackgroundAlphaNeeded
	// Param[in]: page	The input PDF page.
	// Return:   <a>TRUE</a> for this object list needing background alpha channel to render.
	// Remarks:  Checks whether this object list needs background alpha channel to render.
	// Notes:    If it's TRUE, then the application should better use ARGB device to render it,
	//           otherwise the objects may need more time to render.
	//           Please call this function after the page has been parsed.
	//************************************
	static FS_BOOL BackgroundAlphaNeeded(FPD_Page page);

	//************************************
	// Function: CalcBoundingBox
	// Param[in]: page	The input PDF page.
	// Return:   The bounding box of all page objects in the collection.
	// Remarks:  Calculates the bounding box of all page objects in the collection.
	// Notes:
	//************************************
	static FS_FloatRect CalcBoundingBox(FPD_Page page);
	
	//************************************
	// Function: GetDict
	// Param[in]: page	The input PDF page.
	// Return:   The page dictionary.
	// Remarks:  Gets the page dictionary.
	// Notes:
	//************************************
	static FPD_Object GetDict(FPD_Page page);

	//************************************
	// Function: GetDocument
	// Param[in]: page	The input PDF page.
	// Return:   The PDF document. 
	// Remarks:  Gets the PDF document. 
	// Notes:
	//************************************
	static FPD_Document GetDocument(FPD_Page page);
	
	//************************************
	// Function:  RealizeResource
	// Param[in]:  page				The input PDF page.
	// Param[in]:  pageResObj		The input resource object
	// Param[in]:  objMapping		The input object mapping from object number to object pointer.
	// Param[in]:  szType			The resource type name.
	// Param[out]: outResObj		It receives the result resource object.
	// Param[out]: outResName		It receives the resource name.
	// Return:    void
	// Remarks:   Adds a resource to current object list. Returns the resource name.
	// Notes:     Will try to use an existing resource first, if available.
	//            Caller should not release the result resource object, which may be same as the input object.
	//            The input object can be an external object (which comes from another document, or archive),
	//            in this case, the object mapping should be specified.
	//************************************
	static void RealizeResource(
		FPD_Page page, 
		FPD_Object pageResObj, 
		FS_MapPtrToPtr objMapping, 
		FS_LPSTR szType, 
		FPD_Object* outResObj,
		FS_ByteString* outResName
		);


	//************************************
	// Function: FindCSName
	// Param[in]: page					The input PDF page.
	// Param[in]: cs					The input color space.
	// Param[out]:outResName			It receive the resource name of the color space.
	// Return:   void
	// Remarks:  Finds a resource name of specified color space.
	// Notes:
	//************************************
	static void FindCSName(FPD_Page page, FPD_ColorSpace cs, FS_ByteString* outResName);

	//************************************
	// Function: FindFontName
	// Param[in]:  page			The input PDF page.
	// Param[in]:  font			The input font.
	// Param[out]: outResName   It receive the resource name of the font.
	// Return:    void
	// Remarks:   Finds a resource name of specified font.
	// Notes:
	//************************************
	static void FindFontName(FPD_Page page, FPD_Font font, FS_ByteString* outResName);
	
	//************************************
	// Function: Load
	// Param[in]: page			The input PDF page.
	// Param[in]: doc			The PDF document
	// Param[in]: pageDict		The page dictionary.
	// Param[in]: bPageCache	Whether images and masks used in page rendering will be cached or not.
	// Return:   void
	// Remarks:  Constructs a page. For saving memory, the page caching feature can be disabled, then
	//           images and masks used in page rendering won't be cached. Of course this will affect the speed.
	// Notes:
	//************************************
	static void	Load(FPD_Page page, FPD_Document doc, FPD_Object pageDict, FS_BOOL bPageCache);

	//************************************
	// Function: StartParse
	// Param[in]: page		The input PDF page.
	// Param[in]: options	The parser options.
	// Return:   void
	// Remarks:  Start parsing the page. If pausing is enabled, application should check current parsing state
	//           after this function returns. If parsing not finished, ContinueParse() should be called.
	// Notes:
	//************************************
	static void	StartParse(FPD_Page page, FPD_ParseOptions options);

	//************************************
	// Function: ParseContent
	// Param[in]: page		The input PDF page.
	// Param[in]: options	The parser options.
	// Return:   void
	// Remarks:  Parses all contents.
	// Notes:
	//************************************
	static void	ParseContent(FPD_Page page, FPD_ParseOptions options);

	//************************************
	// Function: GetDisplayMatrix
	// Param[in]: page		The input PDF page.
	// Param[in]: xPos		The x-coordinate of the top-left position in the device space.
	// Param[in]: yPos		The y-coordinate of the top-left position in the device space.
	// Param[in]: xSize		The x-direction size in the device space.
	// Param[in]: ySize		The y-direction size in the device space.
	// Param[in]: iRotate	The rotation degrees.
	// Return:   The transformation matrix from PDF user space to targeted device space.
	// Remarks:  Builds a matrix from PDF user space to targeted device space, according to metrics info
	//           (top-left position and widht-height size) provided in device space.
	// Notes:
	//************************************
	static FS_AffineMatrix GetDisplayMatrix(
		FPD_Page page, 
		FS_INT32 xPos, 
		FS_INT32 yPos, 
		FS_INT32 xSize, 
		FS_INT32 ySize,
		FS_INT32 iRotate
		);

	//************************************
	// Function: GetPageWidth
	// Param[in]: page	The input PDF page.
	// Return:   The page width in user space.
	// Remarks:  Gets the page width in user space.
	// Notes:
	//************************************
	static FS_FLOAT	GetPageWidth(FPD_Page page);

	//************************************
	// Function: GetPageHeight
	// Param[in]: page	The input PDF page.
	// Return:   The page height in user space.
	// Remarks:  Gets the page height in user space.
	// Notes:
	//************************************
	static FS_FLOAT	GetPageHeight(FPD_Page page);

	//************************************
	// Function: GetPageBBox
	// Param[in]: page	The input PDF page.
	// Return:   The page bounding box in user space.
	// Remarks:  Gets the page bounding box in user space.
	// Notes:
	//************************************
	static FS_FloatRect	GetPageBBox(FPD_Page page);

	//************************************
	// Function: GetPageMatrix
	// Param[in]: page	The input PDF page.
	// Return:   The page matrix.
	// Remarks:  Gets the page matrix.
	// Notes:
	//************************************
	static FS_AffineMatrix GetPageMatrix(FPD_Page page);

	//************************************
	// Function: GetPageAttr
	// Param[in]: page			The input PDF page.
	// Param[in]: szName		The attribute(entry) name
	// Return:   The attribute value
	// Remarks:  Gets an inheritable attribute value.
	// Notes:
	//************************************
	static FPD_Object GetPageAttr(FPD_Page page, FS_LPSTR szName);


	//************************************
	// Function: GetRenderCache
	// Param[in]: page	The input PDF page.
	// Return:   The render cache. for RENDER module.
	// Remarks:  Gets render cache. for RENDER module.
	// Notes:
	//************************************
	static FPD_PageRenderCache GetRenderCache(FPD_Page page);

	//************************************
	// Function: ClearRenderCache
	// Param[in]: page	The input PDF page.
	// Return:   void
	// Remarks:  Clears render cache.
	// Notes:
	//************************************
	static void	ClearRenderCache(FPD_Page page);

	//************************************
	// Function: GenerateContent
	// Param[in]: page	The input PDF page.
	// Return:   void
	// Remarks:  Replaces the page content stream.
	// Notes:
	//************************************
	static void	GenerateContent(FPD_Page page);

	//************************************
	// Function:   GetPageText	
	// Param[out]:outLines		It receives the text lines.
	// Param[in]: doc			The input PDF document.
	// Param[in]: pageDic		The input PDF page.
	// Param[in]: iMinWidth		The input minimum width of the text.
	// Param[in]: flags			The input OS text extracting flags.
	// Return:   void
	// Remarks:  Extracts pure text from a page, in appearance order.
	// Notes:
	//************************************
	static void	GetPageText(
		FS_ByteStringArray* outLines, 
		FPD_Document doc, 
		FPD_Object pageDic, 
		FS_INT32 iMinWidth, 
		FS_DWORD flags
		);
	
	//************************************
	// Function: GetPageText_Unicode
	// Param[out]:outLines		It receives the text lines.
	// Param[in]: doc			The input PDF document.
	// Param[in]: pageDic		The input PDF page.
	// Param[in]: iMinWidth		The input minimum width of the text.
	// Param[in]: flags			The input OS text extracting flags.
	// Return:   void
	// Remarks:  Extracts Unicode pure text from a page, in appearance order.
	// Notes:
	//************************************
	static void	GetPageText_Unicode(
		FS_WideStringArray* outLines, 
		FPD_Document doc, 
		FPD_Object pageDic,
		FS_INT32 iMinWidth,
		FS_DWORD flags
		);

	//************************************
	// Function: NewContentGenerator
	// Param[in]: page	The input PDF page.
	// Return:   The PDF page content generator.
	// Remarks:  Creates the PDF page content generator.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:  FPDPageDestroyContentGenerator
	//************************************
	static FPD_ContentGenerator	NewContentGenerator(FPD_Page page);

	//************************************
	// Function: DestroyContentGenerator
	// Param[in]: generator	The input PDF content generator.
	// Return: void.
	// Remarks:  Destroys the PDF page content generator.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void	DestroyContentGenerator(FPD_ContentGenerator generator);
	
	//************************************
	// Function: StartGenerateContent
	// Param[in]: generator		The input PDF content generator.
	// Param[in]: fileStream	The input file stream object. Sets it NULL as default.
	// Return: TRUE for success, otherwise not.
	// Remarks: Starts to generate the PDF content progressively.
	// Notes: It has been deprecated. Suggest use FPDPageContinueGenerateContent2.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:  FPDPageContinueGenerateContent
	//************************************
	static FS_BOOL StartGenerateContent(FPD_ContentGenerator generator, FS_FileStream fileStream);

	//************************************
	// Function: ContinueGenerateContent
	// Param[in]: generator	The input PDF content generator.
	// Param[in]: pause		The input pause handler. Creates the pause handler by <a>FSPauseHandlerCreate</a>. Sets it NULL as default.
	// Return: The status of generating PDF page content progressively.
	// Remarks: Continues to generate the PDF content progressively.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FPD_ProgressiveStatus ContinueGenerateContent(FPD_ContentGenerator generator, FS_PauseHandler pause);

	//************************************
	// Function: GetResourcesDictionary
	// Param[in]: page	The input PDF page.
	// Return:   The PDF page resources dictionary.
	// Remarks:  Gets the PDF page resources dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:  
	//************************************
	static FPD_Object GetResourcesDictionary(FPD_Page page);

	//************************************
	// Function: SetResourcesDictionary
	// Param[in]: page			The input PDF page.
	// Param[in]: resourcesDict	The input PDF page resources dictionary.
	// Return:   void.
	// Remarks:  Sets the PDF page resources dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:  
	//************************************
	static void SetResourcesDictionary(FPD_Page page, FPD_Object resourcesDict);

	//************************************
	// Function: StartGenerateContent2
	// Param[in]: generator		The input PDF content generator.
	// Return: TRUE for success, otherwise not.
	// Remarks: Starts to generate the PDF content progressively.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:  FPDPageContinueGenerateContent
	//************************************
	static FS_BOOL StartGenerateContent2(FPD_ContentGenerator generator);

	//************************************
	// Function: GetPageRotation
	// Param[in]: page			The input PDF page.	
	// Return:   void.
	// Remarks:  Get rotation of the page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:  
	//************************************
	static FS_INT32	GetPageRotation(FPD_Page page);

	//************************************
	// Function: GetPageResources
	// Param[in]: page			The input PDF page.	
	// Return:   FPD_Object.The page resources dictionaries inheritable
	// Remarks:  Get PageResource of the page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:  
	//************************************
	static FPD_Object  GetPageResources(FPD_Page page);
	
	//************************************
	// Function: GetPageBleedBox
	// Param[in]: page			The input PDF page.	
	// Return:   FS_FloatRect. Get the page bounding box in user space. 
	// Remarks:  Get the page bounding box in user space. 
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:  
	//************************************
	static FS_FloatRect		GetPageBleedBox(FPD_Page page);
	
	 //************************************
	 // Function: New2
	 // Param[in]: bReleaseMembers		Whether the collection takes charge of releasing of graphics objects.	
	 // Return:   FPD_Page     Construct an empty collection of graphics objects.
	 // Remarks:  Construct an empty collection of graphics objects.
	 // Notes:
	 // Since: <a>SDK_LATEEST_VERSION</a> > 11.1.0.0
	 // See:  
	 //************************************
	static FPD_Page New2(FS_BOOL bReleaseMembers);

	//************************************
	// Function:  SetFormStream
	// Param[in]: page	    The input PDF page object.
	// Param[in]: stream	The input form stream.
	// Return:   void.
	// Remarks:   Set the form stream. For form only.
	// Notes:
	//************************************
	static void SetFormStream(FPD_Page page, FPD_Object stream);

	//************************************
	// Function:  SetFormDict
	// Param[in]: page	    The input PDF page object.
	// Param[in]: dict	    The input form dictionary.
	// Return:   void.
	// Remarks:   Set the form dictionary. For form only.
	// Notes:
	//************************************
	static void SetFormDict(FPD_Page page, FPD_Object dict);

	//************************************
	// Function:  CastToFPDGraphicsObjects
	// Param[in]: page	                 The input PDF form data object.
	// Return:   FPD_GraphicsObjects     Convert to its parent object of FPD_GraphicsObjects.
	// Remarks:   Convert to its parent object of FPD_GraphicsObjects.
	// Notes:
	//************************************
	static FPD_GraphicsObjects CastToFPDGraphicsObjects(FPD_Page page);

	//************************************
	// Function: GenerateContent2
	// Param[in]: page	        The input PDF page.
	// Param[out]: bsContent	It receives the content stream.		
	// Return:   void
	// Remarks:  Replaces the page content stream.
	// Notes:
	//************************************
	static void	GenerateContent2(FPD_Page page, FS_ByteString* bsContent);
};

class CFPD_ParseOptions_V1
{	
public:
	//************************************
	// Function: New
	// Param[in]: bTextOnly			Whether only text object is parsed into object list or not.
	// Param[in]: bMarkedContent	Whether load marked content (including foxit tag) information or not.
	// Param[in]: bSeparateForm		Whether Generate FPD_FormObject for form or not.
	// Param[in]: bDecodeInlineImg  Whether decode inline image for better performance.
	//                              This should be disabled for PDF Editor, to keep the result file size smaller.
	// Return:   A new empty page parsing options object.
	// Remarks:  Creates a new empty page parsing options object.
	// Notes:
	//************************************
	static FPD_ParseOptions New(
		FS_BOOL bTextOnly, 
		FS_BOOL bMarkedContent,
		FS_BOOL bSeparateForm, 
		FS_BOOL bDecodeInlineImg
		);

	//************************************
	// Function: Destroy
	// Param[in]: opt	The input page parsing options object.
	// Return:   void
	// Remarks:  Destroys the page parsing options object.
	// Notes:
	//************************************
	static void	Destroy(FPD_ParseOptions opt);
	
	//************************************
	// Function: SetTextFlag
	// Param[in]: opt					The input page parsing options object.
	// Param[in]: bParseTextOnly		Whether only text object is parsed into object list or not.
	// Return:   void
	// Remarks:  Sets whether only text object is parsed into object list or not.
	// Notes:
	//************************************
	static void	SetTextFlag(FPD_ParseOptions opt, FS_BOOL bParseTextOnly);

	//************************************
	// Function: SetMarkedContentLoadFlag
	// Param[in]: opt		The input page parsing options object.
	// Param[in]: bLoad		Whether load marked content (including foxit tag) information or not.
	// Return:   void
	// Remarks:  Sets whether load marked content (including foxit tag) information or not.
	// Notes:
	//************************************
	static void	SetMarkedContentLoadFlag(FPD_ParseOptions opt, FS_BOOL bLoad);

	//************************************
	// Function: SetFormGenerateFlag
	// Param[in]: opt					The input page parsing options object.
	// Param[in]: bGernerateForm		Whether Generate FPD_FormObject for form or not.
	// Return:   void
	// Remarks:  Sets whether Generate FPD_FormObject for form or not.
	// Notes:
	//************************************
	static void	SetFormGenerateFlag(FPD_ParseOptions opt, FS_BOOL bGernerateForm);

	//************************************
	// Function: SetInlineImageDecodeFlag
	// Param[in]: opt				The input page parsing options object.
	// Param[in]: bDecodeInlineImg	Whether decode inline image for better performance.
	// Return:   void
	// Remarks:  Sets whether decode inline image for better performance,
	//           This should be disabled for PDF Editor, to keep the result file size smaller.
	// Notes:
	//************************************
	static void	SetInlineImageDecodeFlag(FPD_ParseOptions opt, FS_BOOL bDecodeInlineImg);	
};

class CFPD_Form_V1
{	
public:
	//************************************
	// Function: New
	// Param[in]: doc				The PDF document.
	// Param[in]: pageResources		The page resources.
	// Param[in]: formStream		The form stream.
	// Return:    A new empty PDF form data object.
	// Remarks:   Creates a new empty PDF form object.
	// Notes:
	//************************************
	static FPD_Form	New(FPD_Document doc, FPD_Object pageResources, FPD_Object formStream);

	//************************************
	// Function: Destroy
	// Param[in]: form	The input PDF form data object.
	// Return:   void
	// Remarks:  Destroys the PDF form data object. If it is added into the page, it is taken over by page and don't destroy it.
	// Notes:
	//************************************
	static void	Destroy(FPD_Form form);
	
	//************************************
	// Function: ContinueParse
	// Param[in]: form				The input PDF form data object.
	// Param[in]: pauseHandler		The user-supplied pause handler.
	// Return:   void
	// Remarks:  Continues parsing.
	// Notes:
	//************************************
	static void	ContinueParse(FPD_Form form, FS_PauseHandler pauseHandler);

	//************************************
	// Function: GetParseState
	// Param[in]: form	The input PDF form data object.
	// Return:   The current parsing state:
	//            <ul><li>FPD_CONTENT_NOT_PARSED</li>
	//            <li>FPD_CONTENT_PARSING</li>
	//            <li>FPD_CONTENT_PARSED</li></ul>
	// Remarks:  Gets the current parsing state.
	// Notes:
	//************************************
	static FS_INT32	GetParseState(FPD_Form form);

	//************************************
	// Function: IsParsed
	// Param[in]: form	The input PDF form data object.
	// Return:   <a>TRUE</a> if the content has been parsed into form objects, otherwise <a>FALSE</a>.
	// Remarks:  Checks whether the content has been parsed into form objects.
	// Notes:
	//************************************
	static FS_BOOL IsParsed(FPD_Form form);

	//************************************
	// Function: EstimateParseProgress
	// Param[in]: form	The input PDF form data object.
	// Return:   The percentage of parse progress.
	// Remarks:  Estimates the percentage of parse progress.
	// Notes:
	//************************************
	static FS_INT32	EstimateParseProgress(FPD_Form form);


	//************************************
	// Function: GetFirstObjectPosition
	// Param[in]: form	The input PDF form data object.
	// Return:   The position of the first form object.
	// Remarks:  Gets the position of the first form object.
	// Notes:
	//************************************
	static FS_POSITION GetFirstObjectPosition(FPD_Form form);

	//************************************
	// Function: GetLastObjectPosition
	// Param[in]: form	The input PDF form data object.
	// Return:   The position of the last form object
	// Remarks:  Gets the position of the last form object
	// Notes:
	//************************************
	static FS_POSITION GetLastObjectPosition(FPD_Form form);

	//************************************
	// Function:   GetNextObject
	// Param[in]:     form			The input PDF form data object.
	// Param[in,out]: inOutPos		The input current position, and receives the next position.
	// Return:   A form object.
	// Remarks:  Gets the current object and moves to next position.
	// Notes:
	//************************************
	static FPD_PageObject GetNextObject(FPD_Form form, FS_POSITION* inOutPos);

	//************************************
	// Function:   GetPrevObject
	// Param[in]:     form			The input PDF form data object.
	// Param[in,out]: inOutPos		It input the current position, and receives the previous position.
	// Return:       A form object.
	// Remarks:      Gets the current object and move to previous position
	// Notes:
	//************************************
	static FPD_PageObject GetPrevObject(FPD_Form form, FS_POSITION* inOutPos);

	//************************************
	// Function: GetObjectAt
	// Param[in]: form	The input PDF form data object.
	// Param[in]: pos	Specifies the position of the form object.
	// Return:   A form object.
	// Remarks:  Gets an object at specified position.
	// Notes:
	//************************************
	static FPD_PageObject GetObjectAt(FPD_Form form, FS_POSITION pos);

	//************************************
	// Function: CountObjects
	// Param[in]: form	The input PDF form data object.
	// Return:   The count of form objects in the collection.
	// Remarks:  Gets the count of form objects in the collection.
	// Notes:
	//************************************
	static FS_DWORD	CountObjects(FPD_Form form);

	//************************************
	// Function: GetObjectIndex
	// Param[in]: form		The input PDF form data object.
	// Param[in]: obj		The form object pointer.
	// Return:   The zero-based index of the form object.
	// Remarks:  Gets the zero-based form object index in the object array.
	// Notes:
	//************************************
	static FS_INT32	GetObjectIndex(FPD_Form form, FPD_PageObject obj);

	//************************************
	// Function: GetObjectByIndex
	// Param[in]: form		The input PDF form data object.
	// Param[in]: index		Specifies the zero-based index of the form object.
	// Return:   A form object.
	// Remarks:  Gets an object by a zero-based form object index.
	// Notes:
	//************************************
	static FPD_PageObject GetObjectByIndex(FPD_Form form, FS_INT32 index);


	//************************************
	// Function: ReplaceObject
	// Param[in]: form		The input PDF form data object.
	// Param[in]: pos		Specifies the position of the form object to be replaced.
	// Param[in]: newObj	The input new form object.
	// Return:   void
	// Remarks:  Replaces a form object with a new form object.
	// Notes:
	//************************************
	static void	ReplaceObject(FPD_Form form, FS_POSITION pos, FPD_PageObject newObj);

	//************************************
	// Function: InsertObject
	// Param[in]: form					The input PDF form data object.	
	// Param[in]: posInsertAfter		Specifies the position to insert after.
	// Param[in]: newObj				The input new form object.
	// Return:   The position of inserted form object
	// Remarks:  Inserts a form object. To insert before all objects, use NULL for posInsertAfter.
	// Notes:
	//************************************
	static FS_POSITION InsertObject(FPD_Form form, FS_POSITION posInsertAfter, FPD_PageObject newObj);

	//************************************
	// Function: RemoveObject
	// Param[in]: form	The input PDF form data object.
	// Param[in]: pos	Specifies the position of the form object to be removed.
	// Return:   void
	// Remarks:  Removes a form object.
	// Notes:
	//************************************
	static void	RemoveObject(FPD_Form form, FS_POSITION pos);

	//************************************
	// Function: MoveObject
	// Param[in]: form			The input PDF form data object.
	// Param[in]: pos			The original position of the form object.
	// Param[in]: newPosAfter	The new position to move after.
	// Return:   The new position of the form object.
	// Remarks:  Moves a form object from a position to another position.
	// Notes:
	//************************************
	static FS_POSITION MoveObject(FPD_Form form, FS_POSITION pos, FS_POSITION newPosAfter);

	//************************************
	// Function: DebugOutput
	// Param[in]: form				The input PDF form data object.
	// Param[in]: szFileName		Input file name.
	// Return:   void
	// Remarks:  Outputs debug information. For debug only: list all form objects.
	// Notes:
	//************************************
	static void DebugOutput(FPD_Form form, FS_LPSTR szFileName);

	//************************************
	// Function: Transform
	// Param[in]: form			The input PDF form data object.
	// Param[in]: matrix		The input transform matrix.
	// Return:   void
	// Remarks:  Transforms all objects.
	// Notes:
	//************************************
	static void	Transform(FPD_Form form, FS_AffineMatrix matrix);

	//************************************
	// Function: BackgroundAlphaNeeded
	// Param[in]: form	The input PDF form data object.
	// Return:   <a>TRUE</a> for this object list needing background alpha channel to render, otherwise not.
	// Remarks:  Checks whether this object list needs background alpha channel to render.
	// Notes:    If it's <a>TRUE</a>, then the application should better use ARGB device to render it,
	//           otherwise the objects may need more time to render.
	//           Please call this function after the form has been parsed.
	//************************************
	static FS_BOOL BackgroundAlphaNeeded(FPD_Form form);

	//************************************
	// Function: CalcBoundingBox
	// Param[in]: form	The input PDF form data object.
	// Return:   The bounding box of all form objects in the collection.
	// Remarks:  Calculates the bounding box of all form objects in the collection.
	// Notes:
	//************************************
	static FS_FloatRect CalcBoundingBox(FPD_Form form);

	//************************************
	// Function: GetDict
	// Param[in]: form	The input PDF form data object.
	// Return:   The form stream dictionary.
	// Remarks:  Gets the form stream dictionary.
	// Notes:
	//************************************
	static FPD_Object GetDict(FPD_Form form);

	//************************************
	// Function: GetDocument
	// Param[in]: form	The input PDF form data object.
	// Return:   The PDF document. 
	// Remarks:  Gets the PDF document. 
	// Notes:
	//************************************
	static FPD_Document GetDocument(FPD_Form form);

	//************************************
	// Function:  RealizeResource
	// Param[in]:  form				The input PDF form data object.
	// Param[in]:  pageResObj		The input resource object
	// Param[in]:  objMapping		The input object mapping from object number to object pointer.
	// Param[in]:  szType			The resource type name.
	// Param[out]: outResObj		It receives the result resource object.
	// Param[out]: outResName		It receives the resource name.
	// Return:    The resource name.
	// Remarks:   Adds a resource to current object list. Return the resource name.
	// Notes:     Will try to use an existing resource first, if available.
	//            Caller should not release the result resource object, which may be same as the input object.
	//            The input object can be an external object (which comes from another document, or archive),
	//            in this case, the object mapping should be specified.
	//************************************
	static void RealizeResource(
		FPD_Form form, 
		FPD_Object pageResObj, 
		FS_MapPtrToPtr objMapping, 
		FS_LPSTR szType, 
		FPD_Object* outResObj,
		FS_ByteString* outResName
		);


	//************************************
	// Function: FindCSName
	// Param[in]: form					The input PDF form data object.
	// Param[in]: cs					The input color space.
	// Param[out]:outResName			It receives the resource name of the color space.
	// Return:   void
	// Remarks:  Finds a resource name of specified color space.
	// Notes:
	//************************************
	static void FindCSName(FPD_Form form, FPD_ColorSpace cs, FS_ByteString* outResName);

	//************************************
	// Function: FindFontName
	// Param[in]:  form			The input PDF form data object.
	// Param[in]:  font			The input font.
	// Param[out]: outResName   It receives the resource name of the font.
	// Return:    void
	// Remarks:   Finds a resource name of specified font.
	// Notes:
	//************************************
	static void FindFontName(FPD_Form form, FPD_Font font, FS_ByteString* outResName);
	

	//************************************
	// Function:  GetFormStream
	// Param[in]: form	The input PDF form data object.
	// Return:   The form stream.
	// Remarks:   Gets the form stream. For form only.
	// Notes:
	//************************************
	static FPD_Object GetFormStream( FPD_Form form );

	//************************************
	// Function:   StartParse
	// Param[in]: form				The input PDF form data object.
	// Param[in]: graphicStates		The current graphics states. Set to NULL for current version.
	// Param[in]: pParentMatrix		Matrix from form object to parent page/form. Optional.
	// Param[in]: Type3Char			Used only when parsing Type3 character forms.
	// Param[in]: opts				Parsing options.
	// Return:   void
	// Remarks:  Start parsing
	// Notes:
	//************************************
	static void	StartParse(
		FPD_Form form, 
		FPD_AllStates graphicStates, 
		FS_AffineMatrix* pParentMatrix,
		FPD_Type3Char Type3Char,
		FPD_ParseOptions opts
		);
	
	//************************************
	// Function: ParseContent
	// Param[in]: form				The input PDF form data object.
	// Param[in]: graphicStates		The current graphics states. Set to NULL for current version.
	// Param[in]: pParentMatrix		Matrix from form object to parent page/form. Optional.
	// Param[in]: Type3Char			Used only when parsing Type3 character forms.
	// Param[in]: opts				Parsing options.
	// Return:   void
	// Remarks:  Parses all contents.
	// Notes:
	//************************************
	static void ParseContent( FPD_Form form, 
		FPD_AllStates graphicStates, 
		FS_AffineMatrix* pParentMatrix, 
		FPD_Type3Char Type3Char, 
		FPD_ParseOptions opts 
		);
	
	//************************************
	// Function: Clone
	// Param[in]: form	The input PDF form data object.
	// Return:   A form cloned from <param>form</param>.
	// Remarks:  Clones a form.
	// Notes:
	//************************************
	static FPD_Form	Clone(FPD_Form form);

	//************************************
	// Function: GenerateContent
	// Param[in]: form	The input PDF form data object.
	// Return:   void
	// Remarks:  Replaces the form content stream.
	// Notes:
	//************************************
	static void	GenerateContent(FPD_Form form);

	//************************************
	// Function: NewContentGenerator
	// Param[in]: form	The input PDF form data object.
	// Return:   The PDF form content generator.
	// Remarks:  Creates the PDF form content generator.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:  FPDFormDestroyContentGenerator
	//************************************
	static FPD_ContentGenerator	NewContentGenerator(FPD_Form form);

	//************************************
	// Function: DestroyContentGenerator
	// Param[in]: generator	The input PDF form content generator.
	// Return: void.
	// Remarks:  Destroys the PDF form content generator.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static void	DestroyContentGenerator(FPD_ContentGenerator generator);
	
	//************************************
	// Function: StartGenerateContent
	// Param[in]: generator		The input PDF content generator.
	// Param[in]: fileStream	The param has been deprecated.
	// Return: TRUE for success, otherwise not.
	// Remarks: Starts to generate the PDF content progressively.
	// Notes: It has been deprecated. Suggest use FPDPageContinueGenerateContent2.
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:  FPDFormContinueGenerateContent	
	//************************************
	static FS_BOOL StartGenerateContent(FPD_ContentGenerator generator, FS_FileStream fileStream);

	//************************************
	// Function: ContinueGenerateContent
	// Param[in]: generator	The input PDF content generator.
	// Param[in]: pause		The input pause handler. Creates the pause handler by <a>FSPauseHandlerCreate</a>. Sets it NULL as default.
	// Return: The status of generating PDF form content progressively.
	// Remarks: Continues to generate the PDF content progressively.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	//************************************
	static FPD_ProgressiveStatus ContinueGenerateContent(FPD_ContentGenerator generator, FS_PauseHandler pause);

	//************************************
	// Function: GetResourcesDictionary
	// Param[in]: form	The input PDF form data object.
	// Return:   The PDF form resources dictionary.
	// Remarks:  Gets the PDF form resources dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:  
	//************************************
	static FPD_Object GetResourcesDictionary(FPD_Form form);

	//************************************
	// Function: SetResourcesDictionary
	// Param[in]: form			The input PDF form data object.
	// Param[in]: resourcesDict	The input PDF form resources dictionary.
	// Return:   void.
	// Remarks:  Sets the PDF form resources dictionary.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 7.2.2
	// See:  
	//************************************
	static void SetResourcesDictionary(FPD_Form form, FPD_Object resourcesDict);

	//************************************
	// Function:  SetFormStream
	// Param[in]: form	    The input PDF form data object.
	// Param[in]: stream	The input form stream.
	// Return:   void.
	// Remarks:   Set the form stream. For form only.
	// Notes:
	//************************************
	static void SetFormStream(FPD_Form form, FPD_Object stream);

	//************************************
	// Function:  SetFormDict
	// Param[in]: form	    The input PDF form data object.
	// Param[in]: dict   	The input form dictionary.
	// Return:   void.
	// Remarks:   Set the form dictionary. For form only.
	// Notes:
	//************************************
	static void SetFormDict(FPD_Form form, FPD_Object dict);	

	//************************************
	// Function:  CastToFPDGraphicsObjects
	// Param[in]: form	                 The input PDF form data object.
	// Return:   FPD_GraphicsObjects     Convert to its parent object of FPD_GraphicsObjects.
	// Remarks:   Convert to its parent object of FPD_GraphicsObjects.
	// Notes:
	//************************************
	static FPD_GraphicsObjects CastToFPDGraphicsObjects(FPD_Form form);

	//************************************
	// Function: StartGenerateContent2
	// Param[in]: generator		The input PDF content generator.
	// Return: TRUE for success, otherwise not.
	// Remarks: Starts to generate the PDF content progressively.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
	// See:  FPDFormContinueGenerateContent
	//************************************
	static FS_BOOL StartGenerateContent2(FPD_ContentGenerator generator);

	//************************************
	// Function: GenerateContent2
	// Param[in]: form	        The input PDF form data object.
	// Param[out]: bsContent	It receives the content stream.
	// Return:   void
	// Remarks:  Replaces the form content stream.
	// Notes:
	//************************************
	static void	GenerateContent2(FPD_Form form, FS_ByteString* bsContent);
};

class CFPD_ColorSeparator_V11
{
public:
	//************************************
	// Function: New
	// Param[in]: pDoc The input PDF document.
	// Return:    A new color separator object.
	// Remarks:   Creates a new color separator object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static FPD_ColorSeparator New(FPD_Document pDoc);

	//************************************
	// Function: Destroy
	// Param[in]: colorSeparator The input color separator object.
	// Return:    void
	// Remarks:   Destroys the color separator object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static void	Destroy(FPD_ColorSeparator colorSeparator);

	//************************************
	// Function: CountColorants
	// Param[in]: colorSeparator The input color separator object.
	// Param[in]: pInputPage The input pdf page.
	// Param[in]: bReCount Sets it <a>FALSE</a> as default.
	// Return:    The count of colorants.
	// Remarks:   Gets the count of colorants.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static FS_INT32 CountColorants(FPD_ColorSeparator colorSeparator, FPD_Page pInputPage, FS_BOOL bReCount);

	//************************************
	// Function: GetColorantName
	// Param[in]: colorSeparator The input color separator object.
	// Param[in]: index The specified index.
	// Param[out]: outColorantName It receives the colorant name.
	// Return:    <a>TRUE</a> means success, otherwise failure.
	// Remarks:   Gets the name of specified colorant.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static FS_BOOL GetColorantName(FPD_ColorSeparator colorSeparator, FS_INT32 index, FS_ByteString outColorantName);

	//************************************
	// Function: SeparateColorant
	// Param[in]: colorSeparator The input color separator object.
	// Param[in]: ColorantName The input colorant name.
	// Return:    <a>TRUE</a> means success, otherwise failure.
	// Remarks:   Starts to separate colorant.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static FS_BOOL SeparateColorant(FPD_ColorSeparator colorSeparator, const FS_ByteString ColorantName);

	//************************************
	// Function: GetResultDoc
	// Param[in]: colorSeparator The input color separator object.
	// Return:    The result document.
	// Remarks:   Gets the result document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static FPD_Document GetResultDoc(FPD_ColorSeparator colorSeparator);

	//************************************
	// Function: SetColorConverter
	// Param[in]: colorSeparator The input color separator object.
	// Param[in]: colorConverter The input color converter object.
	// Return:    <a>TRUE</a> means success, otherwise failure.
	// Remarks:   Sets the color converter.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 9.6
	//************************************
	static FS_BOOL SetColorConverter(FPD_ColorSeparator colorSeparator, FPD_ColorConvertor colorConverter);
};

class CFPD_GraphicObjects_V16
{
public:
	//************************************
	// Function: CastToFPDPage
	// Param[in]: object   The input FPD_GraphicsObjects.
	// Return:  FPD_Page   Convert FPD_GraphicsObjects to FPD_Page.
	// Remarks:  Convert FPD_GraphicsObjects to FPD_Page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_Page CastToFPDPage(FPD_GraphicsObjects object);

	//************************************
	// Function: CastToFPDForm
	// Param[in]: object   The input FPD_GraphicsObjects.
	// Return:  FPD_Form   Convert FPD_GraphicsObjects to FPD_Form.
	// Remarks:  Convert FPD_GraphicsObjects to FPD_Form.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_Form CastToFPDForm(FPD_GraphicsObjects object);

	//************************************
	// Function: GetType
	// Param[in]: object   The input FPD_GraphicsObjects.
	// Return:  FS_INT32   Get the type of FPD_GraphicsObjects,
	// like FPDPAGEOBJECTS_PAGE,FPDPAGEOBJECTS_FORMX.
	// Remarks:  Get the type of FPD_GraphicsObjects,
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FS_INT32 GetType(FPD_GraphicsObjects object);
};

class CFPD_PDFObjectExtracter_V16
{
public:
	//************************************
	// Function: Create
	// Param[in]: pDoc   The input FPD_Document.
	// Return:  FPD_PDFObjectExtracter    Create FPD_PDFObjectExtracter object.
	// Remarks:  Create FPD_PDFObjectExtracter object.
	// The object is used extractor some page object and product a new document.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_PDFObjectExtracter Create(FPD_Document pDoc);

	//************************************
	// Function: Destroy
	// Param[in]: extracter   The input FPD_PDFObjectExtracter.
	// Return: void
	// Remarks: Destroy FPD_PDFObjectExtracter object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static void Destroy(FPD_PDFObjectExtracter extracter);

	//************************************
	// Function: CreateNewPageFromOrigal
	// Param[in]: extracter   The input FPD_PDFObjectExtracter.
	// Param[in]: pOriPage    The input orgin page object.
	// Param[in]: index       The input page index.
	// Return: FPD_Page  Create new page.
	// Remarks: Create new page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_Page CreateNewPageFromOrigal(FPD_PDFObjectExtracter extracter,FPD_Page pOriPage, FS_INT32 index);

	//************************************
	// Function: AddGraphicsObject
	// Param[in]: extracter            The input FPD_PDFObjectExtracter.
	// Param[in]: pNewPage             The input new page object.
	// Param[in]: pOrgFormParent       The input original form objects.
	// Param[in]: pOrgPageObject       The input original object.
	// Return: FS_BOOLEAN     true means add success.
	// Remarks: Add graphis object.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FS_BOOLEAN AddGraphicsObject(FPD_PDFObjectExtracter extracter,FPD_GraphicsObjects pNewPage, FS_PtrArray pOrgFormParent, FPD_PageObject pOrgPageObject);
	
	//************************************
	// Function: CloseNewPage
	// Param[in]: extracter            The input FPD_PDFObjectExtracter.
	// Param[in]: pNewPage             The input new page object.	
	// Return: FS_BOOLEAN     true means close success.
	// Remarks: Close new page.
	// Notes:
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FS_BOOLEAN CloseNewPage(FPD_PDFObjectExtracter extracter,FPD_Page pNewPage);
	
	//************************************
	// Function: UpdateStructTree
	// Param[in]: extracter            The input FPD_PDFObjectExtracter.
	// Return: FS_BOOLEAN              true means success, otherwise not.
	// Remarks: Update the struct tree for the extracter PDF Document.
	// Notes: It must be called befor save the PDF document.
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FS_BOOLEAN UpdateStructTree(FPD_PDFObjectExtracter extracter);

	//************************************
	// Function: GetExtracterPDFDoc
	// Param[in]: extracter            The input FPD_PDFObjectExtracter.
	// Return: FPD_Document            Get extract pdf document.
	// Remarks: Get extract pdf document.
	// Notes: 
	// Since: <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	//************************************
	static FPD_Document GetExtracterPDFDoc(FPD_PDFObjectExtracter extracter);
};

#ifdef __cplusplus
};
#endif//__cplusplus

#endif//FPD_PAGEIMPL_H

/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_docExpT.h
		
 - Types, macros, structures, etc. required to use the FPDLayer HFT.

*********************************************************************/
/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/


/**
  * @addtogroup FPDDOCUMENT
  * @{
  */


/**
* @file
* @brief data types for PDDoc layer
*/

#ifndef FPD_DOCEXPT_H
#define FPD_DOCEXPT_H

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
#include "fpd_parserExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "fpd_objsExpT.h"
#endif

#ifndef FPD_RESOURCEEXPT_H
#include "fpd_resourceExpT.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "fpd_pageExpT.h"
#endif

#ifndef FPD_RENDEREXPT_H
#include "fpd_renderExpT.h"
#endif

#include <math.h>


#ifdef __cplusplus
extern "C" {
#endif

/* @OBJSTART FPD_Document */

/* @DEFGROUPSTART FPDLoadErrCodes */
	/**
	* @brief The error codes definitions for PDF loading.
	*/
/*@{*/
/** @brief Load document successfully. */
#define FPD_LOADERR_SUCCESS		0

/** @brief Out of memory. */
#define FPD_LOADERR_MEMORY		1

/** @brief Error of any kind, without specific reason. */
#define FPD_LOADERR_ERROR		2		

/** @brief Incorrect password. */
#define FPD_LOADERR_PASSWORD	3		

/** @brief Not PDF format. */
#define FPD_LOADERR_FORMAT		4

/** @brief File access error. */
#define FPD_LOADERR_FILE		5	

/** @brief Parameter error. */
#define FPD_LOADERR_PARAM		6

/** @brief Not in correct status. */
#define FPD_LOADERR_STATUS		7

/** @brief To be continued. */
#define FPD_LOADERR_TOBECONTINUED	8

/** @brief Not found. */
#define FPD_LOADERR_NOTFOUND	9
/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDDocPermissions */

	/**
	* @name PDF document permissions, according to PDF Reference, Table 3.20.
	* 1-2 bits must be zero, 7-8, 13-32 bits must be 1. 
	*/

	/*@{*/

	/**
	* @brief bit 3.
	*
	* <br><ul>
	* <li>- (Revision 2) Print the document.</li>
	* <li>- (Revision 3 or greater) Print the document (possibly not at the highest
	* quality level, depending on whether bit 12 is also set). </li>
	* </ul>
	*/
#define FPD_PERM_PRINT			0x0004
	/**
	* @brief bit 4. 
	*
	* Modify the contents of the document by operations other than 
	* those controlled by bits 6, 9, and 11.
	*/
#define FPD_PERM_MODIFY			0x0008
	/**
	* @brief bit 5.
	*
	* <br><ul>
	* <li>- (Revision 2) Copy or otherwise extract text and graphics from the 
	* document, including extracting text and graphics (in support of accessibility
	* to users with disabilities or for other purposes).</li>
	* <li>- (Revision 3 or greater) Copy or otherwise extract text and graphics 
	* from the document by operations other than that controlled by bit 10.</li>
	* </ul>
	*/
#define FPD_PERM_EXTRACT		0x0010
	/**
	* @brief bit 6. 
	*
	* Add or modify text annotations, fill in interactive form fields, and, 
	* if bit 4 is also set, create or modify interactive form fields (including signature fields).
	*/
#define FPD_PERM_ANNOT_FORM		0x0020
	/**
	* @brief bit 9. 
	*
	* (Revision 3 or greater) Fill in existing interactive form fields (including signature fields),
	* even if bit 6 is clear. 
	*/
#define FPD_PERM_FILL_FORM		0x0100
	/**
	* @brief bit 10. 
	*
	* (Revision 3 or greater) Extract text and graphics (in support of accessibility
	* to users with disabilities or for other purposes). 
	*/
#define FPD_PERM_EXTRACT_ACCESS	0x0200
	/**
	* @brief bit 11. 
	*
	* (Revision 3 or greater) Assemble the document (insert, rotate, or delete pages
	* and create bookmarks or thumbnail images), even if bit 4 is clear. 
	*/
#define FPD_PERM_ASSEMBLE		0x0400
	/**
	* @brief bit 12. 
	*
	* (Revision 3 or greater) Print the document to a representation from 
	* which a faithful digital copy of the PDF content could be generated. 
	* When this bit is clear (and bit 3 is set), printing is limited to a low-level
	* representation of the appearance, possibly of degraded quality. 
	* (See implementation note 25 in Appendix H.) 
	*/
#define FPD_PERM_PRINT_HIGH		0x0800

	/*@}*/ 

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDDocSaveFlags */

/**
 * @name Flags for saving PDF document.
 */
/*@{*/

/** @brief Default. */
#define FPD_SAVE_DEFAULT			0
/** @brief Incremental. */
#define FPD_SAVE_INCREMENTAL		1
/** @brief No original. */
#define FPD_SAVE_NO_ORIGINAL		2
/** @brief Use progressive creator. */
#define FPD_SAVE_PROGRESSIVE		4
/** @brief Use object stream creator. */
#define FPD_SAVE_OBJECTSTREAM		8
/*@}*/

/* @DEFGROUPEND */


#ifndef FPD_DOCUMENT
#define	FPD_DOCUMENT
	/**
	* @brief The underlying PDF representation of a document.
	*
	* Each PDF document contains, among other things:<br>
	* <ul>
	* <li>- A tree of pages(<a>FPD_Page</a>).</li>
	* <li>- (Optional) Trees of bookmarks and articles.</li>
	* <li>- (Optional) Information and security dictionaries.</li>
	* </ul>
	* The FPD_Document object is the hidden object behind every FR_Document. 
	* Through FPD_Document objects, your application can perform most of the menu items for pages
	* from Foxit Phantom (delete, replace, and so on). Thumbnails and Bookmarks can be created and deleted
	* through this object. You can set and retrieve document information fields through this
	* object as well. The first page in a FPD_Document is page 0. See <a>FPDDocNew</a>, <a>FPDDocDestroy</a>, 
	* <a>FPDDocOpen</a>, <a>FPDDocOpenMemDocument</a>, <a>FPDDocClose</a>, <a>FPDPageGetDocument</a>.
	*/
	typedef struct _t_FPD_Document* FPD_Document;

#endif

/* @OBJEND */


/* @OBJSTART FDF_Document */
#ifndef FPD_FDFDOCUMENT
#define	FPD_FDFDOCUMENT
	/**
	* @brief The underlying FDF (Form Data Format) representation of a document.The file
	* format used for interactive form data.
	*
    * An FDF file is structured in essentially the same way as a PDF file but contains
	* only those elements required for the export and import of interactive form and
	* annotation data. It consists of three required elements and one optional element:
	* For more information, see Section 8.6 in the PDF Reference".
	* The FDF document can be created from scratch, or
	* parsed from a file or memory block. See <a>FPDFDFDocNew</a>, <a>FPDFDFDocOpenFromFile</a>, 
	* <a>FPDFDFDocPareMemory</a>.
	*/
	typedef struct _t_FDF_Document* FDF_Document;
#endif


	/* @ENUMSTART */
	 /** @brief It is provided for information and semantic purposes for those processors
	   * that are able to use such additional information.
	 */
	enum FPD_AFRelationship
	{
		FPD_AFRelationship_Unspecified = 0,
		FPD_AFRelationship_Source = 1,
		FPD_AFRelationship_Data = 2,
		FPD_AFRelationship_Alternative = 3,
		FPD_AFRelationship_Supplement = 4,
		FPD_AFRelationship_EncryptedPayload = 5,
		FPD_AFRelationship_FormData = 6,
		FPD_AFRelationship_Schema = 7,
	};
	/* @ENUMEND */

/* @OBJEND */

/* @OBJSTART FPD_PARSER */
#ifndef FPD_PARSER
#define FPD_PARSER
	/**
	* @brief The PDF file parser to parse a pdf file to get a <a>FPD_Document</a>.
	*
	* Each PDF file need a FPD_Parser to parse the content, call <a>FPDParserStartParse</a> to
	* start to parse a file. See <a>FPDParserNew</a>, <a>FPDParserDestroy</a>.
	*/

	typedef struct _t_FPD_Parser* FPD_Parser;
#endif
	/* @OBJEND */



/* @OBJSTART FPD_NameTree */
#ifndef FPD_NAMETREE
#define FPD_NAMETREE
	/**
	* @brief The dictionary used to store all of the Named Destinations in a PDF file.
	*
	* A name tree is used to map FS ByteString to FPD Objects.You create a FPD_NameTree 
	* and locate it where you think is appropriate (perhaps under a page, but most 
	* often right under the catalog). See <a>FPDNameTreeNew</a>, <a>FPDNameTreeNew2</a>, <a>FPDNameTreeDestroy</a>.
	*/
	typedef struct _t_FPD_NameTree* FPD_NameTree;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Bookmark */
/* @DEFGROUPSTART FPDBookmarkFontFlags */

	/**
	* @name Bookmark font flags.
	*/
	/*@{*/

	/** @brief Italic style. */
#define FPD_BOOKMARK_ITALIC			1
	/** @brief Bold style. */
#define FPD_BOOKMARK_BOLD			2

	/*@}*/

/* @DEFGROUPEND */

#ifndef FPD_BOOKMARK
#define FPD_BOOKMARK
	/**
	* @brief A bookmark corresponds to an outline object in a PDF document 
	* (<Italic>see Section 8.2.2, Document Outline, in the PDF Reference</Italic>). 
	*
	* Each bookmark has a title that appears on screen, and an action that specifies what happens 
	* when a user clicks on the bookmark.<br>
	*
	* Bookmarks can either be created interactively by the user through the
	* Foxit Reader user interface or programmatically generated. The typical action for a
	* user-created bookmark is to move to another location in the current document,
	* although any action (see FPD_Action) can be specified. See <a>FPDBookmarkNew</a>, <a>FPDBookmarkDestroy</a>.
	*/
	typedef struct _t_FPD_Bookmark* FPD_Bookmark;
#endif
/* @OBJEND */

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// Destinations
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

/* @OBJSTART FPD_Dest */
/* @DEFGROUPSTART FPDDestinationZoomMode */

	/**
	* @name Zoom mode for PDF destination. '/FitB', '/FitBH', '/FitBV' is not supported currently.
	*/

	/*@{*/

	/**
	* @brief Left, top, zoom.
	*
	* With the coordinates (left, top) positioned at 
	* the upper-left corner of the window and the contents of the page 
	* magnified by the factor zoom. 
	*/
#define FPD_ZOOM_XYZ					1
	/**
	* @brief Fit page.
	*
	* With its contents magnified just enough to fit the entire page
	* within the window both horizontally and vertically.
	*/ 
#define FPD_ZOOM_FITPAGE				2
	/**
	* @brief Fit horizontal. 
	*
	* With the vertical coordinate top positioned at the top edge
	* of the window and the contents of the page magnified just enough to fit 
	* the entire width of the page within the window.
	*/
#define FPD_ZOOM_FITHORZ				3
	/**
	* @brief Fit vertical. 
	*
	* With the horizontal coordinate left positioned at the left edge
	* of the window and the contents of the page magnified just enough to fit the 
	* entire height of the page within the window.
	*/
#define FPD_ZOOM_FITVERT				4
	/**
	* @brief Fit rectangle. 
	*
	* With its contents magnified just enough 
	* to fit the rectangle specified by the coordinates left, bottom, right, and top
	* entirely within the window both horizontally and vertically.
	*/
#define FPD_ZOOM_FITRECT				5
/**
 * @brief Fit bounding box entirely
 *
 * with its contents magnified just enough to fit its bounding box entirely
 * within the window both horizontally and vertically.
 */
#define FPD_ZOOM_FITBBOX				6
/**
 * @brief Fit the entire width of its bounding box within the window
 *
 * with the vertical coordinate top positioned at the top edge of
 * the window and the contents of the page magnified just enough to fit
 * the entire width of its bounding box within the window
 */
#define FPD_ZOOM_FITBHORZ			7
 /**
  * @brief Fit the entire height of its bounding box within the window.
  *
  * with the horizontal coordinate left positioned at the left edge
  * of the window and the contents of the page magnified just enough to fit the entire
  * height of its bounding box within the window.
  */
#define FPD_ZOOM_FITBVERT			8
	/**
 * @brief with its contents magnified just enough to fit its bounding box entirely
 * within the window both horizontally and vertically.
 */
#define FPD_ZOOM_FITBBOX				6

 /**
  * @brief with the vertical coordinate top positioned at the top edge of
  * the window and the contents of the page magnified just enough to fit
  * the entire width of its bounding box within the window
  */
#define FPD_ZOOM_FITBHORZ			7

  /**
   * @brief with the horizontal coordinate left positioned at the left edge
   * of the window and the contents of the page magnified just enough to fit the entire
   * height of its bounding box within the window.
   */
#define FPD_ZOOM_FITBVERT			8

	/*@}*/
/* @DEFGROUPEND */


#ifndef FPD_DEST
#define FPD_DEST
	/**
	* @brief Corresponding to a PDF Dest array. 
	*
	* It contains a reference to a page, a
	* rectangle on that page, and information specifying how to adjust the view to fit the
	* window's size and shape. See <a>FPDDestNew</a>, <a>FPDDestDestroy</a>, <a>FPDBookmarkGetDest</a>, 
	* <a>FPDActionGetDest</a>, <a>FPDActionSetDest</a>, <a>FPDLinkGetDest</a>.
	*/
	typedef struct _t_FPD_Dest* FPD_Dest;
#endif

/* @OBJEND */

/* @OBJSTART FPD_OCContext */
/* @ENUMSTART */
	/** 
	* @name The usage type of optional content. See <a>FPDOCContextNew</a>.
	*/

	/*@{*/
	enum FPD_OCC_UsageType 
	{
		View = 0, /**< Used for a viewer . */
		Design, /**< Used to represent a document designer's structural organization of artwork. */
		Print,	/**< Used for printing. */
		Export	/**< Used for exporting. */
	};
	/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
	/**
	* @name State, for action type SetOCGState. See <a>FPDActionCountOCGStates</a>, <a>FPDActionGetOCGStates</a>, 
	* <a>FPDActionInsertOCGStates</a>, <a>FPDActionReplaceOCGStates</a>, <a>FPDActionRemoveOCGStates</a>.
	*/

	/*@{*/

	enum FPD_OCGState 
	{
		ON = 0,		/**< Sets the state of subsequent groups to ON. */
		OFF,		/**< Sets the state of subsequent groups to OFF. */
		Toggle		/**< Reverses the state of subsequent groups. */
	};

	/*@}*/
/* @ENUMEND */

#ifndef FPD_OCCONTEXT
#define FPD_OCCONTEXT
	/**
	* @brief A FPD_OCContext is an object that keeps track the on/off states of all of the OCGs
	* in a document.
	*
	* There can be more than one FPD_OCContext object, representing different combinations of OCG
	* states. The FPD_Document contains an internal FPD_OCContext that is used for on-screen 
	* drawing and as the default state used for any other drawing or content enumeration. <br>
	* Clients can change the states of OCGs within any FPD_OCContext. Clients can
	* build (and save in the PDF file) FPD_OCContext objects with their own combination of OCG 
	* states, and issue drawing or enumeration commands using their own FPD_OCContext instead of 
	* the document's internal FPD_OCContext. See <a>FPDOCContextNew</a>, <a>FPDOCContextDestroy</a>, 
	* <a>FPDOCContextGetDocument</a>, <a>FPDOCContextGetUsageType</a>, <a>FPDOCContextCheckOCGVisible</a>, 
	*<a>FPDOCContextResetOCContext</a>.
	*/
	typedef struct _t_FPD_OCContext* FPD_OCContext;
#endif
/* @OBJEND */

/* @OBJSTART FPD_OCGroup */
#ifndef FPD_OCGROUP
#define FPD_OCGROUP
	/**
	* @brief A FPD_OCGroup represents a named object whose state can be toggled in a user 
	* interface to affect changes in visibility of content.
	* 
	* The FPD_OCGroup object represents an optional-content group. This corresponds to a PDF OCG
	* dictionary representing a collection of graphic objects that can be made visible or invisible.
	* Any graphic content of the PDF can be made optional, including page contents, XObjects, and 
	* annotations. The specific content objects in the group have an OC entry in the PDF. 
	* See <a>FPDOCGroupNew</a>, <a>FPDOCGroupDestroy</a>, <a>FPDOCGroupSetIsSubGroupSet</a>.
	*/
	typedef struct _t_FPD_OCGroup* FPD_OCGroup;
#endif

/* @CALLBACKSTART FPD_OCGStateChangedNotify */
/** 
 * @brief A callback for Optional Content Notification <a>FPD_OCNotify</a> object. Triggered when OCG 
 * state has been changed.
 *
 * @param[in] doc		The PDF document.
 * @param[in] ocg		The optional content group object.
 * @param[in] bVisible	Whether the OCG is visible.
 * @return void
 * @note
	*/
	typedef void (*FPD_OCGStateChangedNotify)(FPD_Document doc, FPD_OCGroup ocg, FS_BOOL bVisible);	
/* @CALLBACKEND */
/* @OBJEND */

/* @OBJSTART FPD_OCGroupSet */
#ifndef FPD_OCGROUPSET
#define FPD_OCGROUPSET
	/**
	* @brief A set of mutually exclusive OCGs. See <a>FPDOCGroupSetNew</a>, <a>FPDOCGroupSetDestroy</a>, <a>FPDOCGroupSetIsSubGroupSet</a>, 
	*<a>FPDOCGroupSetGetGroup</a>, <a>FPDOCGroupSetFindGroup</a>.
	*/
	typedef struct _t_FPD_OCGroupSet* FPD_OCGroupSet;
#endif
/* @OBJEND */

/* @OBJSTART FPD_OCNotify */
#ifndef FPD_OCNOTIFY
#define FPD_OCNOTIFY
	/** 
	 * @brief Optional Content Notification Interface. See <a>FPDOCNotifyFPD_OCNotifyNew</a>, 
	 * <a>FPDOCNotifyFPD_OCNotifyDestroy</a>, <a>FPDOCPropertiesAddOCNotify</a>, <a>FPDOCPropertiesRemoveOCNotify</a>.
	 */
	typedef struct _t_FPD_OCNotify* FPD_OCNotify;
#endif
/* @OBJEND */

/* @OBJSTART FPD_OCProperties */
#ifndef FPD_OCPROPERTIES
#define FPD_OCPROPERTIES
	/**
	 * @brief The optional content properties dictionary for a document. See <a>FPDOCPropertiesNew</a>, 
	 * <a>FPDOCPropertiesDestroy</a>, <a>FPDOCPropertiesCountConfigs</a>, <a>FPDOCPropertiesGetConfig</a>, 
	 * <a>FPDOCPropertiesAddOCNotify</a>, <a>FPDOCPropertiesRemoveOCNotify</a>.
	 */
	typedef struct _t_FPD_OCProperties* FPD_OCProperties;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Action */
#ifndef FPD_ACTION
#define FPD_ACTION
	/** @brief Actions are what happens when a user clicks on a link or bookmark.  
	*
	* In addition,the Foxit Reader allows a document to have an action that is executed 
	* automatically when the document is opened. See <a>FPDActionNew</a>, <a>FPDActionNew2</a>, 
	* <a>FPDActionNew3</a>, <a>FPDActionDestroy</a>, <a>FPDAActionGetAction</a>, <a>FPDAActionGetNextAction</a>, 
	* <a>FPDDocJSActionsGetJSAction2</a>, <a>FPDLinkGetAction</a>, <a>FPDBookmarkGetAction</a>.
	*/
	typedef struct _t_FPD_Action* FPD_Action;
#endif

/* @DEFGROUPSTART FPDActionTypeNamed */
	/**
	* @name macros define, for action type Named.
	*/
	/*@{*/	

	/** @brief Go to the next page of the document. */
#define FPD_NAMED_NEXTPAGE		1
	/** @brief Go to the previous page of the document. */
#define FPD_NAMED_PREVPAGE		2
	/** @brief Go to the first page of the document. */
#define FPD_NAMED_FIRSTPAGE		3
	/** @brief Go to the last page of the document. */
#define FPD_NAMED_LASTPAGE		4

	/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDJavaScriptString */
/**
* @name macro for JavaScript string.
*/

/*@{*/
/** @brief macro for JavaScript string, maximum length. */
#define FPD_JS_MAXLENGTH			64
/*@}*/
/* @DEFGROUPEND */


/* @ENUMSTART */
	/**
	* @brief PDF Action Type Enumeration. See <a>FPDActionNew2</a>.
	*/

	enum FPD_ActionType
	{
		UnknownType = 0,/**< Unknown action type. */
		GoTo,			/**< Go-To Actions. */ 
		GoToR,			/**< Remote Go-To Actions. */
		GoToE,			/**< Embedded Go-To Actions. */
		Launch,			/**< Launch Actions. */
		Thread,			/**< Thread Actions. */
		URI,			/**< URI Actions. */
		Sound,			/**< Sound Actions. */
		Movie,			/**< Movie Actions. */
		Hide,			/**< Hide Actions. */
		Named,			/**< Named Actions. */
		SubmitForm,		/**< Submit-Form Actions. */
		ResetForm,		/**< Reset-Form Actions. */
		ImportData,		/**< Import-Data Actions. */
		JavaScript,		/**< JavaScript Actions. */
		SetOCGState,	/**< Set-OCG-State Actions. */
		Rendition,		/**< Rendition Actions. */
		Trans,			/**< Transition Actions. */
		GoTo3DView		/**< Go-To-3D-View Actions. */
};

/* @ENUMEND */

/* @OBJEND */


/* @OBJSTART FPD_LWinParam */
#ifndef FPD_LWINPARAM
#define FPD_LWINPARAM
	/** @brief A FPD_LWinParam represents a set of parameter on Windows desktop to launch an   
	* application or open or print a document. It is used by launch actions. See <a>FPDLWinParamNew</a>, 
	* <a>FPDLWinParamDestroy</a>, <a>FPDActionGetWinParam</a>.
	*
	*/
	typedef struct _t_FPD_LWinParam* FPD_LWinParam;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ActionFields */
#ifndef FPD_ACTIONFIELDS
#define FPD_ACTIONFIELDS
	/** 
	* @brief FPD_ActionFields represents the /Fields entry in submit-form actions dictionary.
	* We can use a FPD_ActionFields object to get field's information easily. See <a>FPDActionFieldsNew</a>, 
	* <a>FPDActionFieldsDestroy</a>, <a>FPDActionGetWidgets</a>.
	*/
	typedef struct _t_FPD_ActionFields* FPD_ActionFields;
#endif
/* @OBJEND */

/* @OBJSTART FPD_AAction */
#ifndef FPD_AACTION
#define FPD_AACTION 
	/** @brief Additional-action extends a set of events that can trigger the execution of an
	* actions. It is specified in /AA entry in a annotation, page object, interactive form
	* or document catalog. See <a>FPDAActionNew</a>, <a>FPDAActionDestroy</a>, 
	* <a>FPDFormFieldGetAdditionalAction</a>, <a>FPDFormControlGetAdditionalAction</a>.
	*
	*/
	typedef struct _t_FPD_AAction* FPD_AAction;
#endif

/* @ENUMSTART */
	/** @brief Additional-action type enumeration. */
	enum FPD_AActionType
	{
		CursorEnter = 0,	/**< E, cursor enters annotation, arbitrary action. */
		CursorExit,			/**< X, cursor exits annotation, arbitrary action. */
		ButtonDown,			/**< D, mouse button is pressed, arbitrary action. */
		ButtonUp,			/**< U, mouse button is released, arbitrary action. */
		GetInputFocus,		/**< Fo, annotation get input focus, arbitrary action. */
		LoseInputFocus,		/**< Bl, annotation loses input focus, arbitrary action. */
		PageOpen,			/**< PO, page is opened, executed after O, arbitrary action. */
		PageClose,			/**< PC, page is closed, executed before C, arbitrary action. */
		PageVisible,		/**< PV, page becomes visible, arbitrary action. */
		PageInvisible,		/**< PI, page is no longer visible, arbitrary action. */

		// additional actions defined in a page's dictionary.
		OpenPage,			/**< O, page is opened, arbitrary action. */
		ClosePage,			/**< C, page is closed, arbitrary action. */

		// additional actions defined in a form field's dictionary.
		KeyStroke,			/**< K, user types a key-stroke into field, JavaScript action. */
		Format,				/**< F, field is to be formatted, JavaScript action. */
		Validate,			/**< V, field is to be validated, JavaScript action. */
		Calculate,			/**< C, recalculate value, JavaScript action. */

		// additional actions defined in the document catalog's dictionary.
		CloseDocument,		/**< DC, before closing document, JavaScript action. */
		SaveDocument,		/**< WS, before saving document, JavaScript action. */
		DocumentSaved,		/**< DS, after saving document, JavaScript action. */
		PrintDocument,		/**< WP, before printing document, JavaScript action. */
		DocumentPrinted		/**< DP, after printing document, JavaScript action. */
	};
/* @ENUMEND */
/* @OBJEND */

/* @OBJSTART FPD_DocJSActions */
#ifndef FPD_DOCJSACTIONS
#define FPD_DOCJSACTIONS
	/** @brief A JavaScript action causes a script to be complied and executed by the JavaScript
	* interpreter. See <a>FPDDocJSActionsNew</a>, <a>FPDDocJSActionsDestroy</a>.
	*
	*/
	typedef struct _t_FPD_DocJSActions* FPD_DocJSActions;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Link */
#ifndef FPD_LINK
#define FPD_LINK
	/** @brief A FPD_Link corresponds to a link annotation(see Sections 8.4.5, Annotation Types,
	* in the PDF Reference). See <a>FPDLinkNew</a>, <a>FPDLinkDestroy</a>
	* <a>FPDLinkGetLinkAtPoint</a>, <a>FPDLinkGetLink</a>.
	*
	*/
	typedef struct _t_FPD_Link* FPD_Link;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Annot */
/* @DEFGROUPSTART FPDAnnotationFlagBits */
	/**
	* @name Annotation flag bits.
	*/
	/*@{*/

	/**
	* @brief If set, do not display the annotation if it does not belong to one of the standard
	* annotation types and no annotation handler is available. If clear, display 
	* such an unknown annotation using an appearance stream specified by its appearance dictionary, if any.
	*/
#define FPD_ANNOTFLAG_INVISIBLE			1
	/**
	* @brief If set, do not display or print the annotation or allow it to interact 
	* with the user, regardless of its annotation type or whether an annotation 
	* handler is available.
	*/
#define FPD_ANNOTFLAG_HIDDEN			2
	/**
	* @brief If set, print the annotation when the page is printed. If clear, never 
	* print the annotation, regardless of whether it is displayed on the screen.
	*/
#define FPD_ANNOTFLAG_PRINT				4
	/**
	* @brief If set, do not scale the annotation's appearance to match the magnification of the page. 
	*/
#define FPD_ANNOTFLAG_NOZOOM			8
	/**
	* @brief If set, do not rotate the annotation's appearance to match the rotation of the page. 
	*/
#define FPD_ANNOTFLAG_NOROTATE			0x10
	/**
	* @brief If set, do not display the annotation on the screen or allow it to interact with the user.
	*/ 
#define FPD_ANNOTFLAG_NOVIEW			0x20
	/**
	* @brief If set, do not allow the annotation to interact with the user.
	*/
#define FPD_ANNOTFLAG_READONLY			0x40
	/**
	* @brief If set, do not allow the annotation to be deleted or its properties (including position and size) to be modified by the user. 
	*/
#define FPD_ANNOTFLAG_LOCKED			0x80
	/**
	* @brief If set, invert the interpretation of the NoView flag for certain events.
	*/
#define FPD_ANNOTFLAG_TOGGLENOVIEW		0x100

	/*@}*/
/* @DEFGROUPEND */

/* @ENUMSTART */
    /**
	* @brief Appearance mode enumeration of annotation. See <a>FPDAnnotDrawAppearance</a>, 
	* <a>FPDAnnotGetAPForm</a>, <a>FPDFormControlDrawControl</a>.
	*/
	enum FPD_AnnotAppearanceMode	
	{
		NormalAppearanceMode,		/**< Used when the annotation is not interacting with the user. This appearance is also used for printing the annotation. */
		RolloverAppearanceMode,		/**< Used when the user moves the cursor into the annotation's active area without pressing the mouse button. */ 
		DownAppearanceMode			/**< Used when the mouse button is pressed or held down within the annotation's active area. */
	};
/* @ENUMEND */


#ifndef FPD_ANNOT
#define FPD_ANNOT
	/** @brief An annotation on a page in a PDF file. See <a>FPDAnnotNew</a>, <a>FPDAnnotDestroy</a>
	* <a>FRAnnotGetPDAnnot</a>, <a>FPDAnnotListGetAt</a>.
	*
	*/
	typedef struct _t_FPD_Annot* FPD_Annot;
#endif
/* @OBJEND */

/* @OBJSTART FPD_AnnotList */
#ifndef FPD_ANNOTLIST
#define FPD_ANNOTLIST
	/** @brief An annotation accessor. See <a>FPDAnnotListNew</a>, <a>FPDAnnotListDestroy</a>.
	*
	*/
	typedef struct _t_FPD_AnnotList* FPD_AnnotList;
#endif
/* @OBJEND */

/* @OBJSTART FPD_DefaultAppearance */
#ifndef FPD_DEFUALTAPPEARANCE
#define FPD_DEFUALTAPPEARANCE

/*@brief Default appearance interpreter, serves for DA entry in form field dictionary.*/
	typedef struct _t_FPD_DefaultAppearance* FPD_DefaultAppearance;
#endif
/* @OBJEND */

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// Forms
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

/* @OBJSTART FPD_FormControl */
#ifndef FPD_FORMCONTROL
#define FPD_FORMCONTROL
	/** @brief A FPD_FormControl is an appearance controller, it used to draw an annotation's
	* presentation on the page or set the appearance data to change an annotation's appearance.
	* See <a>FPDInterFormNewControl</a>, <a>FPDInterFormGetControl</a>, <a>FPDInterFormGetPageControl</a>, 
	* <a>FPDInterFormGetControlAtPoint</a>, <a>FPDInterFormGetControlByDict</a>, <a>FPDInterFormDeleteControl</a>.
	*
	*/
	typedef struct _t_FPD_FormControl* FPD_FormControl;
#endif

/* @DEFGROUPSTART FPDFieldTypes */
	/**
	* @name macros definition for field types in CreateControl method.
	* Note: They are used in some interfaces about FPD_InterForm, especially for JavaScript.
	*/
	/*@{*/

	/** @brief Unknown. */
#define FPD_FORM_FIELDTYPE_UNKNOWN			0
	/** @brief Push button. */
#define FPD_FORM_FIELDTYPE_PUSHBUTTON		1
	/** @brief Check box. */
#define FPD_FORM_FIELDTYPE_CHECKBOX			2
	/** @brief Radio button. */
#define FPD_FORM_FIELDTYPE_RADIOBUTTON		3
	/** @brief Combo box. */
#define FPD_FORM_FIELDTYPE_COMBOBOX			4
	/** @brief List box. */
#define FPD_FORM_FIELDTYPE_LISTBOX			5
	/** @brief Text field. */
#define FPD_FORM_FIELDTYPE_TEXTFIELD		6
	/** @brief Signature. */
#define FPD_FORM_FIELDTYPE_SIGNATURE		7

	/*@}*/

/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_FormField */
#ifndef FPD_FORMFIELD
#define FPD_FORMFIELD
	/** @brief A field in a interactive form. See <a>FPDInterFormNewField</a>, 
	* <a>FPDInterFormGetField</a>, <a>FPDInterFormGetFieldByDict</a>, 
	* <a>FPDInterFormDeleteField</a>, <a>FPDInterFormDeleteField2</a>.
	*/
	typedef struct _t_FPD_FormField* FPD_FormField;
#endif

/* @DEFGROUPSTART FPDFormFieldFlags */
/**
* @name Form field flags.
*/
/*@{*/
// for all fields
#define FPD_FIELDFLAG_READONLY                 1   
#define FPD_FIELDFLAG_REQUIRED                 2
#define FPD_FIELDFLAG_NOEXPORT                 4

// for text fields
#define FPD_FIELDFLAG_MULTILINE (1 << 12)
#define FPD_FIELDFLAG_PASSWORD (1 << 13)
#define FPD_FIELDFLAG_FILESELECT (1 << 20)
#define FPD_FIELDFLAG_DONOTSPELLCHECK (1 << 22)
#define FPD_FIELDFLAG_DONOTSCROLL (1 << 23)
#define FPD_FIELDFLAG_COMB (1 << 24)
#define FPD_FIELDFLAG_RICHTEXT (1 << 25)

// for button fileds
#define FPD_FIELDFLAG_NOTOGGLETOOFF (1 << 14)
#define FPD_FIELDFLAG_RADIO (1 << 15)                // fxcore none
#define FPD_FIELDFLAG_PUSHBUTTON (1 << 16)    //fxcore  none
#define FPD_FIELDFLAG_RADIOSINUNISON (1 << 25)
// for choice fields
#define FPD_FIELDFLAG_COMBO (1 << 17)             // fxcore none
#define FPD_FIELDFLAG_EDIT (1 << 18)
#define FPD_FIELDFLAG_SORT (1 << 19)
#define FPD_FIELDFLAG_MULTISELECT (1 << 21)
#ifndef FPD_FIELDFLAG_DONOTSPELLCHECK
#define FPD_FIELDFLAG_DONOTSPELLCHECK (1 << 22)
#endif
#define FPD_FIELDFLAG_COMMITONSELCHANGE (1 << 26)
/*@}*/
/* @DEFGROUPEND */



/* @DEFGROUPSTART FPDFormFieldFlags */
	/**
	* @name Form field flags.
	*/
	/*@{*/

	/** @brief This field is read only, no editing allowed. */
#define FPD_FORM_FIELD_READONLY		0x01
	/** @brief This field is required when submit. */
#define FPD_FORM_FIELD_REQUIRED		0x02
	/** @brief Don't export the field when submitting. Not supported for now. */
#define FPD_FORM_FIELD_NOEXPORT		0x04

	/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDRadioButtonAdditionalFlags */

	/**
	* @name Additional flags for radio button fields.
	*/
	/*@{*/

	/**
	* @brief For radio button only: if set, one radio button has to be selected at any time;
	* Otherwise, when the selected radio button is clicked, it will be turned off,
	* (leaving no radio button selected at this time).
	*/
#define FPD_FORM_RADIO_NOTOGGLEOFF	0x100
	/**
	* @brief If set, radio buttons with same value in a field will be turned on or off
	* in unison (either all one, or all off). If cleared, all buttons are 
	* mutually exclusive.
	*/
#define FPD_FORM_RADIO_UNISON		0x200

	/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDTextFieldsAdditionalFlags */

	/**
	* @name Additional flags for text fields.
	*/
	/*@{*/

	/** @brief Multiple lines. */
#define FPD_FORM_TEXT_MULTILINE		0x100
	/** @brief This is a password field. Password shouldn't be displayed or exported. */
#define FPD_FORM_TEXT_PASSWORD		0x200
	/**
	* @brief Do not scroll (vertically for multi-line field, or horizontally for
	* single-line field). If the field is full, no more text is accepted.
	*/
#define FPD_FORM_TEXT_NOSCROLL		0x400
	/**
	* @brief If set, this field is arranged in a number of equally spaced positions
	* ("combs"), the number of positions is determined by MaxLen parameter.
	*/
#define FPD_FORM_TEXT_COMB			0x800

	/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDComboBoxFieldsAdditionalFlags */

	/**
	* @name Additional flags for combo box fields.
	*/
	/*@{*/

	/**
	* @brief (Meaningful only when FORMCHOICE_COMBO flag is set): if set, the combo box
	* includes an editable text control, otherwise, it's only a drop list.
	*/
#define FPD_FORM_COMBO_EDIT			0x100

	/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDListBoxFieldsAdditionalFlags */

	/**
	* @name Additional flags for list box fields.
	*/
	/*@{*/

	/** @brief If set, more than one items can be selected. */
#define FPD_FORM_LIST_MULTISELECT	0x100

	/*@}*/

/* @DEFGROUPEND */

/* @ENUMSTART */
	/**
	  * @name PDF interactive form field type enumeration. See <a>FPDFormFieldGetType</a>.
	  */

	/*@{*/

	enum FPD_FormFieldType 
	{
		FormField_Unknown,			/**< unsupported or invalid field. */
		FormField_PushButton,		/**< push button without any value. */
		FormField_RadioButton,		/**< a group of radio buttons, at most one item can be selected. */
		FormField_CheckBox,			/**< check box with on/off states. */
		FormField_TextField,		/**< single line or multi-line texts. */
		FormField_RichText,			/**< rich text (using XML to store rich text). */
		FormField_File,				/**< file content. */
		FormField_ListBox,			/**< list box, single or multiple selections. */
		FormField_ComboBox,			/**< combo box with or without the edit box. */
		FormField_Sign				/**< digital signature. */
	};
	/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
	/**
	  * @name Scale method enumeration. 
	  * @brief The circumstances under which the icon should be scaled inside the annotation rectangle. See <a>FPDIconFitSetScaleMethod</a>.
	  */

	/*@{*/

	enum FPD_IconScaleMethod
	{
		IconScaleMethod_Always = 0,		/**< A, Always scale. */
		IconScaleMethod_Bigger,			/**< B, Scale only when the icon is bigger than the annotation rectangle. */
		IconScaleMethod_Smaller,		/**< S, Scale only when the icon is smaller then the annotation rectangle. */
		IconScaleMethod_Never			/**< N, Never scale. */
	};
	/*@}*/
/* @ENUMEND */

/* @DEFGROUPSTART FPDFormFieldTextPosition */

	/**
	* @name Text Position definition, for "TP" entry in MK of Widget dictionary.
	*/
	/*@{*/

	/** @brief no icon, caption only. */
#define FPD_TEXT_POS_CAPTION		0
	/** @brief no caption, icon only. */
#define FPD_TEXT_POS_ICON		1
	/** @brief caption below the icon. */
#define FPD_TEXT_POS_BELOW		2
	/** @brief caption above the icon. */
#define FPD_TEXT_POS_ABOVE		3
	/** @brief caption to the right of the icon. */
#define FPD_TEXT_POS_RIGHT		4
	/** @brief caption to the left of the icon. */
#define FPD_TEXT_POS_LEFT		5
	/** caption overlaid directly on the icon. */
#define FPD_TEXT_POS_OVERLAID	6

	/*@}*/
/* @DEFGROUPEND */

/* @ENUMSTART */

	/**
	  * @brief HighLighting mode definition, for annotation or control. See <a>FPDFormControlGetHighlightingMode</a>.
	  */

	/*@{*/

	enum FPD_FormCtrlHighlightingMode	
	{
		FormCtrlHL_None = 0,	/**< (None) No highlighting. */

		FormCtrlHL_Invert,		/**< (Invert) Invert the contents of the annotation rectangle. */

		FormCtrlHL_Outline,		/**< (Outline) Invert the annotation's border. */

        /**< (Push) Display the annotation's down appearance, if any; 
		If no down appearance is defined, offset the contents of the annotation rectangle 
		to appear as if it were being pushed below the surface of the page. */
		FormCtrlHL_Push,		
								
		FormCtrlHL_ToggleMode		/**< (Toggle) Same as P (which is preferred). */
	};

	/*@}*/
/* @ENUMEND */

/* @OBJEND */

/* @OBJSTART FPD_InterForm */

/* @DEFGROUPSTART FPDInterFormColorTypes */
	/**
	* @name macros definition for color types in interactive form.
	* used for color operator like G/g, RG/rg, K/k, or "BC"/"BG" entries in MK of Widget dictionary, etc...
	*/
	/*@{*/

	/** @brief Transparent. */
#define FPD_CLRTYPE_TRANSPARENT		0
	/** @brief Gray. */
#define FPD_CLRTYPE_GRAY			1
	/** @brief RGB. */
#define FPD_CLRTYPE_RGB				2
	/** @brief CMYK. */
#define FPD_CLRTYPE_CMYK			3

	/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPD_NOTIFY */
	/**
	* @name Status of notifying, returned by functions associated with notify.
	*/
	/*@{*/
/** @brief Whether reset the signature field. */
#define FPD_NOTIFY_RESET_SIGNATURE_FIELD		3
/** @brief success and the notify was executed. */
#define FPD_NOTIFY_SUCCESS						2
/** @brief success but no notify was executed. */
#define FPD_NOTIFY_SUCCESS_WITHOUT_NOTIFY		1
/** @brief failed and no notify was executed. */
#define FPD_NOTIFY_FAILED_WITHOUT_NOTIFY		0
/** @brief failed and the field was destroyed by the notify. */
#define FPD_NOTIFY_FAILED_DESTROY_FIELD			-1
/** @brief failed and the control was destroyed by the notify. */
#define FPD_NOTIFY_FAILED_DESTROY_CONTROL		-2
/** @brief failed and the page was destroyed by the notify. */
#define FPD_NOTIFY_FAILED_DESTROY_PAGE			-3
/** @brief failed and the document was destroyed by the notify. */
#define FPD_NOTIFY_FAILED_DESTROY_DOCUMENT		-4
/** @brief failed and the Opt item of the field was deleted by the notify. */
#define FPD_NOTIFY_FAILED_DESTROY_OPTIONS		-5
	/*@}*/
/* @DEFGROUPEND */

#ifndef FPD_INTERFORM
#define FPD_INTERFORM
	/** @brief A PDF interactive form (AcroForm) object. 
	*
	* It is a collection of fields for gathering
	* information interactively form user. A FPD_Document object may contain any number of fields 
	* appearing on any combination of pages, all of which make up a single, global interactive 
	* form spanning the entire document.
	*
	* @note FPD_InterForm should not be confused with <a>FPD_Form</a> object, <a>FPD_Form</a> is a form XObjects.
	* See <a>FPDInterFormNew</a>, <a>FPDInterFormDestroy</a>.
	*/
	typedef struct _t_FPD_InterForm* FPD_InterForm;
#endif
/* @OBJEND */

/* @OBJSTART FPD_IconFit */
#ifndef FPD_ICONFIT
#define FPD_ICONFIT
	/** @brief A FPD_IconFit represents a set of icon that specifying how to display the widget
	*	annotation's icon within its annotation rectangle. See <a>FPDIconFitNew</a>, <a>FPDIconFitDestroy</a>.
	*
	*/
	typedef struct _t_FPD_IconFit* FPD_IconFit;
#endif
/* @OBJEND */

/* @OBJSTART FPD_FormNotify */
#ifndef FPD_FORMNOTIFY
#define FPD_FORMNOTIFY
	/** @brief A object representing a form notify handler. 
	*
	* It is a event trigger for modifying form element. See <a>FPDInterFormGetFormNotify</a>, <a>FPDInterFormSetFormNotify</a>.
	*/
	typedef struct _t_FPD_FormNotify* FPD_FormNotify;
#endif

/* @CALLBACKGROUPSTART FPD_FormNotifyCallbacks */
	/** @brief A set of callbacks for PDF form notify handler. */
	typedef struct _fpd_formnotify_callbacks_
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART BeforeValueChange */
		/**
		* @brief Triggered before a value changing.
		* @param[in] clientData	The user-supplied data.
		* @param[in] field		The field which will be changed.
		* @param[in] csValue	The value to change to.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*BeforeValueChange)(FS_LPVOID clientData, FPD_FormField field, FS_WideString csValue);
		/* @CALLBACKEND */

		/* @CALLBACKSTART AfterValueChange */
		/**
		* @brief Triggered after a value changed.
		* @param[in] clientData	The user-supplied data.
		* @param[in] field		The field which was just changed.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*AfterValueChange)(FS_LPVOID clientData, FPD_FormField field);
		/* @CALLBACKEND */

		/* @CALLBACKSTART BeforeSelectionChange */
		/**
		* @brief Triggered before the selection changing.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] field		The field who's selection will be changed.
		* @param[in] csValue	The option label to change to.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*BeforeSelectionChange)(FS_LPVOID clientData, FPD_FormField field, FS_WideString csValue);
		/* @CALLBACKEND */

		/* @CALLBACKSTART AfterSelectionChange */
		/**
		* @brief Triggered after the selection changed.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] field		The field who's selection was just changed.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*AfterSelectionChange)(FS_LPVOID clientData, FPD_FormField field);
		/* @CALLBACKEND */

		/* @CALLBACKSTART AfterCheckedStatusChange */
		/**
		* @brief Triggered after the checked status changed.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] field			The field who's checked status was just changed.
		* @param[in] statusArray	The changed status array.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*AfterCheckedStatusChange)(FS_LPVOID clientData, FPD_FormField field, FS_ByteArray statusArray);
		/* @CALLBACKEND */

		/* @CALLBACKSTART BeforeFormReset */
		/**
		* @brief Triggered before form resetting.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] form		The interactive form to reset.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*BeforeFormReset)(FS_LPVOID clientData, FPD_InterForm form);
		/* @CALLBACKEND */

		/* @CALLBACKSTART AfterFormReset */
		/**
		* @brief Triggered after form reset.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] form		The interactive form who has just reset.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*AfterFormReset)(FS_LPVOID clientData, FPD_InterForm form);
		/* @CALLBACKEND */

		/* @CALLBACKSTART BeforeFormImportData */
		/**
		* @brief Triggered before form importing data.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] form		The interactive form to import data.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*BeforeFormImportData)(FS_LPVOID clientData, FPD_InterForm form);
		/* @CALLBACKEND */

		/* @CALLBACKSTART AfterFormImportData */
		/**
		* @brief Triggered after form data imported.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] form		The interactive form who has just imported data.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*AfterFormImportData)(FS_LPVOID clientData, FPD_InterForm form);
		/* @CALLBACKEND */

	}FPD_FormNotifyCallbacksRec, *FPD_FormNotifyCallbacks;
/* @CALLBACKGROUPEND */
/* @OBJEND */


/* @OBJSTART FPD_MediaPlayer */
/* @ENUMSTART */
	/**
	  * @brief PDF media permission type enumeration.
	  *
	  * Indicates the circumstances under which it is acceptable to write a temporary file in order to play a media clip.
	  * See <a>FPDRenditionGetPermission</a>.
	  */

	/*@{*/

	enum FPD_MediaPermission 
	{
		TempNever = 0,		/**< Never allowed. */
		TempExtract,		/**< Allowed only if the document permissions allow content extraction. */
		TempAccess,			/**< Allowed only if the document permissions allow content extraction, including for accessibility purposes. */
		TempAlways			/**< Always allowed. */
	};

	/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
	/** 
	  * @name PDF media play parameter type enumeration. See <a>FPDRenditionSetVolumn</a>.
	  */

	/*@{*/
	enum FPD_MediaPlayParamType 
	{
		MustBeHonored = 0,		/**< Must be honored for the media play parameters to be considered viable. */
		BestEffort				/**< Need only be honored in a "best effort" sense. */
	};
	/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
	/**
	  * @name Enumeration of PDF media player classified type in PDF Media Players dictionary. See <a>FPDRenditionCountMediaPlayers</a>, 
	  * <a>FPDRenditionGetMediaPlayer</a>, <a>FPDRenditionAddMediaPlayer</a>, <a>FPDRenditionRemoveMediaPlayer</a>.
	  */

	/*@{*/
	enum FPD_MediaPlayerType
	{
		MustUsed = 0,		/**< Which must be used in playing the associated media object. */
		Available,			/**< Which may be used in playing the associated media object. */
		NotUsed				/**< Which must not be used in playing the associated media object. */
	};
	/*@}*/
/* @ENUMEND */

#ifndef FPD_MEDIAPLAYER
#define FPD_MEDIAPLAYER
	/** @brief A media player information object. See <a>FPDMediaNew</a>, <a>FPDMediaNewFromDict</a>, <a>FPDMediaDestroy</a>.
	*
	*/

	typedef struct _t_FPD_MediaPlayer* FPD_MediaPlayer;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Rendition */
#ifndef FPD_RENDITION
#define FPD_RENDITION
	/** @brief A Rendition object. See <a>FPDRenditionNew</a>, <a>FPDRenditionNewFromDict</a>, <a>FPDRenditionDestroy</a>.
	*/
	typedef struct _t_FPD_Rendition* FPD_Rendition;
#endif
/* @OBJEND */


	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// File access
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

/* @OBJSTART FPD_FileSpec */
#ifndef FPD_FILESPEC
#define FPD_FILESPEC
	
/*@brief PDF file specification object.
 *A FPD_FileSpec corresponds to the PDF file specification object (see Section 3.10, File 
 *Specifications, in the PDF Reference). It is used to specify a file in an action.
 */
	typedef struct _t_FPD_FileSpec* FPD_FileSpec;

#endif
/* @OBJEND */
	
/* @OBJSTART FPD_EnumPageHandler */
#ifndef FPD_ENUMPAGEHANDLER
#define FPD_ENUMPAGEHANDLER
  /** @brief A handler to enumerate the count of pages for a document. See <a>FPDDocNewEnumPageHandler</a>, <a>FPDDocDeleteEnumPageHandler</a>.
	*
	*/
	typedef struct _t_FPD_EnumPageHandler* FPD_EnumPageHandler;
#endif

/* @CALLBACKGROUPSTART FPD_EnumPage */
#ifndef FPD_ENUMPAGE
#define FPD_ENUMPAGE
	/** @brief A callback for <a>FPD_EnumPageHandler</a>. See <a>FPDDocEnumPages</a>.
	*/
	typedef struct
	{	
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EnumPage</a>).  */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART EnumPage */
		/**
		* @brief Enumerates page function for call back.
		*
		* Enumerates page function for call back. Returns <a>TRUE</a> if you want the enumeration to continue.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] pageDict	The page dictionary. 
		* @return Non-zero means you want the enumeration to continue, otherwise want not.
		* @note
		*/
		FS_BOOL (*EnumPage)(FS_LPVOID clientData, FPD_Object pageDict);
		/* @CALLBACKEND */
	}FPD_EnumPage,*PFPD_EnumPage;
#endif
/* @CALLBACKGROUPEND */
/* @OBJEND */

/* @OBJSTART FPD_ConnectedInfo */
#ifndef FPD_CONNECTEDINFO
#define FPD_CONNECTEDINFO
	/** @brief The connected PDF info object can get connected PDF document ID and version ID etc.
	* Typical usage of this object is to get and set connected PDF info.
	*
	*/
	typedef struct _t_FPD_ConnectedInfo* FPD_ConnectedInfo;
#endif

/* @DEFGROUPSTART FPDConnectedInfoIdTypes */
	/**
	* @brief The Id types of connected PDF info object.
	*/
/*@{*/
/** @brief It is document Id. */
#define FPD_CONNECT_DOCUMENTID					0x01

/** @brief It is version Id. */
#define FPD_CONNECT_VERSIONID					0x02

/** @brief It is review Id. */
#define FPD_CONNECT_REVIEWID					0x03
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDConnectedInfoTrackingTypes */
	/**
	* @brief The tracking types of connected PDF info object.
	*/
/*@{*/
/** @brief Tracking printing. */
#define FPD_CONNECT_PRINTING	0x0001

/** @brief Tracking filling form. */
#define FPD_CONNECT_FORMFILL	0x0002

/** @brief Tracking commenting. */
#define FPD_CONNECT_COMMENT		0x0004

/** @brief Tracking pages. */
#define FPD_CONNECT_PAGES		0x0008

/** @brief Tracking bookmarks. */
#define FPD_CONNECT_BOOKMARKS	0x0010

/** @brief Tracking copying. */
#define FPD_CONNECT_COPY		0x0020

/** @brief Tracking signing. */
#define FPD_CONNECT_SIGN		0x0040

/** @brief Tracking extracting. */
#define FPD_CONNECT_EXTRACT		0x0080
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDConnectedOpenActionURLTypes */
	/**
	* @brief The open action URL types of connected PDF info object.
	*/
/*@{*/
/** @brief Update open message. */
#define FPD_CONNECT_SUBMIT_UPDATE				0x01
/** @brief Receives open message. */
#define FPD_CONNECT_SUBMIT_RECEIVE				0x02
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_WrapperDoc */
#ifndef FPD_WRAPPERDOC
#define FPD_WRAPPERDOC
	typedef struct _t_FPD_WrapperDoc* FPD_WrapperDoc;

/* @DEFGROUPSTART FPDWrapperDocGetWrapperType */
	/**
	* @brief The Id types of connected PDF info object.
	*/
/*@{*/
	/** @brief Normal document. */
#define  FPD_WRAPPERTYPE_NO		 0
	/** @brief For Foxit wrapper document. */
#define  FPD_WRAPPERTYPE_FOXIT	 1
	/** @brief For PDF2.0 wrapper document. */
#define  FPD_WRAPPERTYPE_PDF2	 2
#endif
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_3dContext */
#ifndef FPD_3D_CONTEXT
#define FPD_3D_CONTEXT

	typedef struct _t_FXJSE_HVALUE* FSJSE_HVALUE;
	typedef struct _t_FSJSE_HRUNTIME* FSJSE_HRUNTIME;
	typedef struct _t_FSJSE_HCONTEXT* FSJSE_HCONTEXT;

#endif
/* @OBJEND */


#ifndef FPD_CERTSTORE
#define FPD_CERTSTORE
	/** @brief A PDF interactive form (AcroForm) object.
	*
	* It is a collection of fields for gathering
	* information interactively form user. A FPD_Document object may contain any number of fields
	* appearing on any combination of pages, all of which make up a single, global interactive
	* form spanning the entire document.
	*
	* @note FPD_InterForm should not be confused with <a>FPD_Form</a> object, <a>FPD_Form</a> is a form XObjects.
	* See <a>FPDInterFormNew</a>, <a>FPDInterFormDestroy</a>.
	*/
	typedef struct _t_FPD_CertStore* FPD_CertStore;
#endif

typedef void(*FRPD_CALLBACK_FREEDATA)(FS_LPVOID pData);

typedef struct _t_FPD_PageLabel* FPD_PageLabel;

/////////////////////////////////////////////////////////////
//Signature
/////////////////////////////////////////////////////////////

typedef struct _t_FPD_SignCert* FPD_SignCert;
typedef struct _t_FPD_SignCertHandler* FPD_SignCertHandler;
typedef struct _t_FPD_VRI* FPD_VRI;
typedef struct _t_FPD_CRL* FPD_CRL;
typedef struct _t_FPD_OCSP* FPD_OCSP;
typedef struct _t_FPD_ICGW_SignDataRevoInfo* FPD_ICGW_SignDataRevoInfo;
typedef struct _t_FPD_ReovationProgressCallbackMgr* FPD_ReovationProgressCallbackMgr;
typedef struct _t_FPD_VerifyRevoke* FPD_VerifyRevoke;
typedef struct _t_FPD_CHECKREVOINFODATA* FPD_CHECKREVOINFODATA;
typedef struct _t_FPD_CHECKData* FPD_CHECKData;
typedef struct _t_FPD_DSS* FPD_DSS;
typedef struct _t_FPD_SignatureVerifyResult* FPD_SignatureVerifyResult;
typedef struct _t_FPD_TrustedCertStore* FPD_TrustedCertStore;
typedef struct _t_FPD_LtvVerifier* FPD_LtvVerifier;
typedef struct _t_FPD_SignatureEdit* FPD_SignatureEdit;
typedef struct _t_FPD_Signature* FPD_Signature;
typedef struct _t_FPD_IncreSaveModifyDetector* FPD_IncreSaveModifyDetector;
typedef struct _t_FPD_SigModifyList* FPD_SigModifyList;
typedef struct _t_FPD_SignatureSign* FPD_SignatureSign;
typedef struct _t_FPD_SignatureVerify* FPD_SignatureVerify;
typedef struct _t_FPD_TimeStampServer* FPD_TimeStampServer;
typedef struct _t_FPD_TimeStampServerMgr* FPD_TimeStampServerMgr;
typedef struct _t_FPD_SGBuffer* FPD_SGBuffer;
typedef struct _t_FPD_CertVerifyCallBack* FPD_CertVerifyCallBack;
typedef struct _t_FPD_WinDefaultHandler* FPD_WinDefaultHandler;
typedef struct _t_FPD_CheckDataTemplate* FPD_CheckDataTemplate;
typedef struct _t_FPD_SignatureHandler* FPD_SignatureHandler;
typedef struct _t_FPD_SignatureHandlerMgr* FPD_SignatureHandlerMgr;
typedef struct _t_FPD_RevocationHandler* FPD_RevocationHandler;
typedef struct _t_FPD_Response* FPD_Response;
typedef struct _t_FPD_SGCLIENTDATA* FPD_SGCLIENTDATA;
typedef struct _t_FPD_CertPolicesData* FPD_CertPolicesData;
typedef struct _t_FPD_PermissionResult* FPD_PermissionResult;
typedef struct _t_FPD_MODIFYDATA* FPD_MODIFYDATA;

typedef struct _t_FPD_TimeStampServerNotify* FPD_TimeStampServerNotify;

typedef struct _fpd_TimeStampServerNotify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DocEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOLEAN(*FPDGetTimeStampServerInfo)(FS_LPVOID clientData, FPD_TimeStampServer pServer, FS_WideString* outusername, FS_WideString* outpassword, void **hWnd);
}FPD_TimeStampServerNotifyCallbacksRec, *FPD_TimeStampServerNotifyCallbacks;

/** @brief	Signature field. */
#define FPD_SIGNATURE_FIELD				-1
/** @brief	Ordinary signature. */
#define FPD_SIGNATURE_ORDINARY			0
/** @brief	DocMDP signature. */
#define FPD_SIGNATURE_DOCMDP			1
/** @brief	FieldMDP signature. */
#define FPD_SIGNATURE_FIELDMDP			2
/** @brief	Timestamp signature. */
#define FPD_SIGNATURE_TIMESTAMP			3


/* @STRUCTSTART FPD_PoliciesData*/
typedef struct __FPD_PoliciesData__
{
    FS_ByteStringArray policiesOID;	// Restricted OID
    FS_WideString certSubjectName;				// The name of the certificate
}FPD_PoliciesData, *PFPD_PoliciesData;
/* @STRUCTEND */

/* @STRUCTSTART FPD_CertSummary*/
typedef struct __FPD_CertSummary__
{
    FS_ByteString m_subjectName;
    FS_ByteString m_issuerName;
    FPD_SYSTEMTIME m_expireTime;
}FPD_CertSummary, *PFPD_CertSummary;
/* @STRUCTEND */

/* @ENUMSTART FPD_VRICreatedTimeType*/
enum FPD_VRICreatedTimeType
{
    FPDVRINone,
    FPDVRIDate,
    FPDVRITimestamp,
    FPDVRIDateAndTimestamp
};
/* @ENUMEND */

/* @ENUMSTART FPD_VERIFYTIMETYPE*/
enum FPD_VERIFYTIMETYPE
{
    FPDTIMETYPE_CURRENTTIME = 0,
    FPDTIMETYPE_SIGNTIME,
    FPDTIMETYPE_STAMPTIME,
    FPDTIMETYPE_VEROTIME
};
/* @ENUMEND */

/* @ENUMSTART FPD_OCSPSTATUSTYPE*/
enum FPD_OCSPSTATUSTYPE
{
    FPDIN_DOC,
    FPDIN_SIGNINFO,
    FPDIN_CRLLOCAL,
    FPDIN_ONLINE
};
/* @ENUMEND */

/* @ENUMSTART FPD_OCSPSTATUS*/
enum FPD_OCSPSTATUS
{
    FPDOCSP_CERTSTATUS_NONE,
    FPDOCSP_RESPONSE_STATUS_SUCCESSFUL,
    FPDOCSP_RESPONSE_STATUS_MALFORMEDREQUEST,	// error request
    FPDOCSP_RESPONSE_STATUS_INTERNALERROR,		// net error
    FPDOCSP_RESPONSE_STATUS_TRYLATER,			// timeout, try later
    FPDOCSP_RESPONSE_STATUS_SIGREQUIRED,			// need signature
    FPDOCSP_RESPONSE_STATUS_SELF,				// self signature
    FPDOCSP_RESPONSE_STATUS_CERTTIME,			// cert out of data
    FPDOCSP_RESPONSE_STATUS_CRL_CERTTIME,		// crl time out of data
    FPDOCSP_RESPONSE_STATUS_UNAUTHORIZED,		// unknown error
    FPDOCSP_RESPONSE_STATUS_OCSPERROR,			// OCSP error
    FPDOCSP_RESPONSE_STATUS_CRLERROR,			// CRL error
    FPDOCSP_RESPONSE_STATUS_OCSPNOCHECK,			// no check
    FPDOCSP_RESPONSE_STATUS_NOCHAIN,				// no cert chain
    FPDOCSP_CERTSTATUS_NOOCSPORCRL,				// no OCSP or crl
    FPDOCSP_CERTSTATUS_SIGNINVALID,				// OCSP invalid
    FPDOCSP_CERTSTATUS_TRUSTCHAIN,				// trust
    FPDOCSP_CERTSTATUS_GOOD,						// good
    FPDOCSP_CERTSTATUS_REVOKED,					// revoked
    FPDOCSP_CERTSTATUS_UNKNOWN,					// unknown
    FPDCRL_CERTSTATUS_GOOD,						// good
    FPDCRL_CERTSTATUS_REVOKED,					// revoked
    FPDOCSP_RESPONSE_STATUS_CHAINCERTTIME,		// chainlistcerts overdue
};
/* @ENUMEND */

/* @ENUMSTART FPDOCSP_PROCESSTYPE*/
enum FPDOCSP_PROCESSTYPE
{
    FPDOCSP_OCSP,
    FPDOCSP_CRL
};
/* @ENUMEND */

/* @ENUMSTART FPD_TIMETYPE*/
enum FPD_TIMETYPE
{
    FPDSPECIFY_TIME,	// specify time
    FPDCUR_TIME,		 // current time
};
/* @ENUMEND */

/* @STRUCTSTART FPD_OCSPCHECKDATATYPE*/
typedef struct __FPD_OCSPCHECKDATATYPE__
{
    __FPD_OCSPCHECKDATATYPE__()
    {
        eStatus = FPDOCSP_CERTSTATUS_NONE;
        eStatusType = FPDIN_ONLINE;
    };

    __FPD_OCSPCHECKDATATYPE__(FPD_OCSPSTATUS _eStatus, FPD_OCSPSTATUSTYPE _eStatusType)
    {
        eStatus = _eStatus;
        eStatusType = _eStatusType;
    };

    FS_BOOL isRevocatoinOrGood()
    {
        if (eStatus == FPDOCSP_CERTSTATUS_GOOD || eStatus == FPDOCSP_CERTSTATUS_REVOKED ||
            eStatus == FPDCRL_CERTSTATUS_GOOD || eStatus == FPDCRL_CERTSTATUS_REVOKED ||
            eStatus == FPDOCSP_CERTSTATUS_SIGNINVALID)
            return TRUE;
        return FALSE;
    }
    FS_BOOL isValid()
    {
        if (eStatus == FPDOCSP_CERTSTATUS_GOOD || eStatus == FPDCRL_CERTSTATUS_GOOD)
            return TRUE;
        return FALSE;
    }

    FPD_OCSPSTATUS eStatus;
    FPD_OCSPSTATUSTYPE eStatusType;
}FPD_OCSPCHECKDATATYPE, *PFPD_OCSPCHECKDATATYPE;
/* @STRUCTEND */

/* @CALLBACKGROUPSTART */
#ifndef FPD_SIGNCERTHANDLER
#define FPD_SIGNCERTHANDLER
/** @brief A callback for <a>FPD_ScriptHostProvider</a>. See <a>FPD_ScriptHostProvider</a>.
*/
typedef struct
{
    /* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EnumPage</a>).  */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    FS_BOOL(*FPDGetCertSummary)(FS_LPVOID clientData, const FS_ByteString X509CertData, FPD_CertSummary* pCertSummary);
    FS_BOOL(*FPDIsIssuerMatchCert)(FS_LPVOID clientData, const FS_ByteString X509CertData, const FS_ByteString X509IssuerData);
    FS_BOOL(*FPDIsCA)(FS_LPVOID clientData, const FS_ByteString X509CertData);
    FS_BOOL(*FPDIsCertCanUsedForSigning)(FS_LPVOID clientData, const FS_ByteString X509CertData);
    FS_BOOL(*FPDIsCertExpired)(FS_LPVOID clientData, const FS_ByteString X509CertData);

    /* @CALLBACKEND */
}FPD_SignCertHandlerCallbacksRec, *FPD_SignCertHandlerCallbacks;
#endif
/* @CALLBACKGROUPEND */

/* @ENUMSTART FPD_REOVACATIONTEXT*/
enum FPD_REOVACATIONTEXT
{
    FPDCHECK = 0,
    FPDDOWNLOADCRL,
    FPDDOWNLOADOCSP
};
/* @ENUMEND */


/* @ENUMSTART FPD_ResponseType*/
enum FPD_ResponseType
{
    FPDNOT_SET,						//no response.
    FPDCRL,							//CRL response.
    FPDOCSP							//OCSP response.
};
/* @ENUMEND */

/* @ENUMSTART FPD_VerifyResult*/
 /** @brief VerifyResult show the verify process success or failure. */
enum FPD_VerifyResult
{
    FPDVERIFY_SUCCESS,			//verify success
    FPDNO_HANDLER,				//handler not set
    FPDLOAD_SIG_FAILED,		//load signature failed
    FPDALLOC_FAILED,			//alloc memory failed
    FPDDTS_CHECK_FAILED,		//DTS check failed
    FPDSWITCH_VERSION_FAILED,	//switch PDF version failed
    FPDLOAD_DSS_FAILED,		//load DSS failed
    FPDLOAD_DTS_TIME_FAILED,	//load DTS time failed
    FPDEMPTY_POINTER_ERROR,	//empty pointer error
    FPDVERIFY_MODE_NOT_SET,	//verify mode is not set
};
/* @ENUMEND */

/* @ENUMSTART FPD_LTVState*/
/** @brief LTVState show if the signature is LTV signature. */
enum FPD_LTVState
{
    FPDINACTIVE,				//inactive, should not show in signature detail.
    FPDLTV_ENABLE,				//enable
    FPDLTV_NOT_ENABLE			//not enable
};
/* @ENUMEND */

/* @ENUMSTART FPD_SigTimeType*/
/** @brief SigTimeType show where the time come from. */
enum FPD_SigTimeType
{
    FPDSIG_CREATE_TIME = 0,	//time from signature create time.
    FPDSIG_TST_TIME,			//time from signature time stamp token.
    FPDCURRENT_TIME,			//time of current time.
    FPDTU_TIME,				//time from TU of VRI.
};
/* @ENUMEND */

/* @ENUMSTART FPD_VerifyMode*/
/** @brief VerifyMode used for express two validation process. */
enum FPD_VerifyMode
{
    FPDMODE_ETSI,				//ETSI verify process.
    FPDMODE_ACROBAT			//acrobat verify process.
};
/* @ENUMEND */

/* @ENUMSTART FPD_RevocationReason*/
/** @brief The revocation reason for a certificate. */
enum FPD_RevocationReason
{
    FPDNO_STATUS = -1,					//no status.
    FPDUNSPECIFIED = 0,				//unspecified.
    FPDKEY_COMPROMISE,					//key compromise.
    FPDCA_COMPROMISE,					//CA compromise.
    FPDAFFILIATION_CHANGED,			//affiliation changed.
    FPDSUPERSEDED,						//superseded.
    FPDCESSATION_OF_OPERATION,			//cessation of operation.
    FPDCERTIFICATE_HOLD,				//certificate hold.
    FPDREMOVE_FROM_CRL,				//remove from CRL.
    FPDPRIVILEGE_WITH_DRAWN,			//privilege with drawn.
    FPDAA_COMPROMISE					//AA compromise.
};
/* @ENUMEND */

/* @ENUMSTART FPD_CertStatus*/
enum FPD_CertStatus
{
    FPDCERTSTATUS_GOOD = 0,			//cert is valid.
    FPDCERTSTATUS_REVOKED,				//cert is revoked.
    FPDCERTSTATUS_EXPIRE,				//cert is out of date.
    FPDCERTSTATUS_UNKNOWN,				//cert status is unknown.
};
/* @ENUMEND */

/* @ENUMSTART FPD_ResponseInfoLocation*/
enum FPD_ResponseInfoLocation
{
    FPDLOCATION_NOT_SET,				//location is no set.
    FPDLOCATION_DSS,					//revocation info be found in doc DSS dictionary.
    FPDLOCATION_SIG,					//revocation info be found in signature content.
    FPDLOCATION_ONLINE,				//revocation info got by online request.
};
/* @ENUMEND */


/* @CALLBACKGROUPSTART */
#ifndef FPD_REOVATIONPROGRESSCALLBACK
#define FPD_REOVATIONPROGRESSCALLBACK
typedef struct
{
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    void(*FPDSetCurValue)(FS_LPVOID clientData, FS_INT32 nCurPos);
    FS_BOOL(*FPDIsCancelled)(FS_LPVOID clientData);
    void(*FPDPeekAndPump)(FS_LPVOID clientData);
    void(*FPDSetText)(FS_LPVOID clientData, FPD_REOVACATIONTEXT type, const FS_ByteString csURL);
    void(*FPDCreateUIProgress)(FS_LPVOID clientData);
    void(*FPDDestroyUIProgress)(FS_LPVOID clientData);
}FPD_ReovcationProgressCallBackRec, *FPD_ReovcationProgressCallBack;
#endif
/* @CALLBACKGROUPEND */


typedef struct __CertVerifyResult__
{
    FS_BOOL			isCA;			//if the cert is a CA cert.
    FS_BOOL			isTrustCert;	//if the cert is trusted by user.
    FS_BOOL			isTrustRoot;	//if the cert is set as trusted root.

    FPD_Response*		resp;			//the response for the cert.
    FPD_SYSTEMTIME		thisUpdTime;	//the start time for the response take effect.
    FPD_SYSTEMTIME		nextUpdTime;	//the end time for the response take effect.
    FPD_SYSTEMTIME		revokeTime;		//the revoked time got from the response.
    FPD_CertStatus		certStatus;		//the cert status of the cert.
    FS_INT32				revokeReason;	//the revoke reason of the cert.

    FPD_SYSTEMTIME	certCheckTime;	//the actual time for check the cert validity.
    FS_BOOL			isExistSigTU;	//is exist signature TU in the VRI dictionary.
    FPD_SYSTEMTIME	TUForSig;		//the TU time for the signature.
    FS_BOOL			isExistRespTU;	//is exist response signature TU in the VRI dictionary.
    FPD_SYSTEMTIME	TUForResp;		//the TU time for the response signature.
    FPD_ResponseInfoLocation RIL;		//the location where the cert response found.

    __CertVerifyResult__()
    {
        isCA = FALSE;
        isTrustCert = FALSE;
        isTrustRoot = FALSE;
        resp = nullptr;
        thisUpdTime = { 0 };
        nextUpdTime = { 0 };
        revokeTime = { 0 };
        certStatus = FPD_CertStatus::FPDCERTSTATUS_UNKNOWN;
        revokeReason = FPD_RevocationReason::FPDNO_STATUS;
        certCheckTime = { 0 };
        isExistSigTU = FALSE;
        TUForSig = { 0 };
        isExistRespTU = FALSE;
        TUForResp = { 0 };
        RIL = FPD_ResponseInfoLocation::FPDLOCATION_NOT_SET;
    }
}FPD_CertVerifyResult, *PFPD_CertVerifyResult;



/* @CALLBACKGROUPSTART */
#ifndef FPD_TRUSTEDCERTSTORECALLBACK
#define FPD_TRUSTEDCERTSTORECALLBACK
typedef struct
{
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    FS_BOOL(*FPDIsCertTrusted)(FS_LPVOID clientData, FS_ByteString cert);
    FS_BOOL(*FPDIsCertTrustedRoot)(FS_LPVOID clientData, FS_ByteString cert);
}FPD_TrustedCertStoreCallBackRec, *FPD_TrustedCertStoreCallBack;
#endif
/* @CALLBACKGROUPEND */


/* @STRUCTSTART FPD_IncrementIndex */
typedef struct __FPD_IncrementIndex__
{
    __FPD_IncrementIndex__()
    {
        nIndex = -1;
        nincrement = 0;
    }
    __FPD_IncrementIndex__(FS_INT32 _nIndex)
    {
        nIndex = _nIndex;
    }

    FS_BOOL operator<(const __FPD_IncrementIndex__& other) const
    {
        return nIndex < other.nIndex;
    }

    FS_INT32 nIndex;
    FS_INT32 nincrement;
}FPD_IncrementIndex, *PFPD_IncrementIndex;
/* @STRUCTEND*/

/* @STRUCTSTART FPD_SignAndIncrementIndex */
typedef struct __FPD_SignAndIncrementIndex__
{
    __FPD_SignAndIncrementIndex__()
    {
        dSignObjNoum = 0;
        nIncrementIndexPos = 0;
        bDelete = FALSE;
        nPageindex = -1;
        dwSignVNum = 0;
    };
    FS_DWORD dSignObjNoum;
    FPD_IncrementIndex sIncrementIndex;
    FS_BOOL bDelete;
    FS_INT64 nIncrementIndexPos;
    FS_INT32 nPageindex;
    FS_WideString sIssuerType;
    FS_WideString sSubType;
    FPD_IncrementIndex sDeleteIncrementIndex;
    FS_DWORD dwSignVNum;
	FS_INT64 nTrailerPos = 0;
}FPD_SignAndIncrementIndex, *PFPD_SignAndIncrementIndex;
/* @STRUCTEND*/


/* @STRUCTSTART FPD_SignAndIncrementIndex */
typedef struct __FPD_OBJECTNUM__
{
    FS_DWORD objNum;
    FS_BOOL operator<(const __FPD_OBJECTNUM__& other) const
    {
        return objNum < other.objNum;
    }
}FPD_OBJECTNUM, *PFPD_OBJECTNUM;
/* @STRUCTEND*/

/* @ENUMSTART FPDOBJECTTYPE*/
enum  FPD_OBJECTTYPE
{
    FPDSIGNOBJECT_SIGN,
    // This modification is not allowed when there is a signature,
    // this signature will be invalid, and there is no need to verify the modification list
    FPDSIGNOBJECT_SIGNREEOR,
    // annot modify
    FPDSIGNOBJECT_ANNOT,
    // form modify
    FPDSIGNOBJECT_FORM,
    // file attachment
    FPDSIGNOBJECT_DOCFILE,
    // modify in page
    FPDSIGNOBJECT_PAGE,
    // If a change is unrelated to the page, such as if the bookmark, etc. appears,
    // the signature is invalid.Because in the signature case, you're not allowed to change doc or
    // anything
    FPDSIGNOBJECT_DOC,
    // Is used to indicate whether there is any change after the signature of file
    FPDSIGNOBJECT_FILE,
	FPDSIGNOBJECT_INCREMENTAL,
};
/* @ENUMEND*/

/* @ENUMSTART FPDMODIFYTYPE*/
enum FPD_MODIFYTYPE
{
    FPDSIGNMODIFY_DELETE,
    FPDSIGNMODIFY_CREATE,
    // Fill in form, fill in annot
    FPDSIGNMODIFY_EDIT,
    // Property modification, such as form font, color, etc
    FPDSIGNMODIFY_PROPERTY,
    // Miscellaneous items, such as aa in root dictionary, are currently only required in root
    FPDSIGNMODIFY_MISCELLANESOUS,
    FPDSIGNMODIFY_XFA,
	FPDSIGNMODIFY_INCREMENTALJUMP
};
/* @ENUMEND*/

/* @ENUMSTART FPDCHECKRESULT*/
enum FPD_CHECKRESULT
{
    // The current permissions are not modified
    FPDCHECK_NOMODIFY,
    // The current permission cannot be modified
    FPDCHECK_NOCANMODIFY,
    // Current permissions can be modified
    FPDCHECK_CANMODIFY,
    // Signature hacked
    FPDCHECK_A,
    // Signature modified
    FPDCHECK_ERROR,
	FPDCHECK_INCREMENTALERROR
};
/* @ENUMEND*/


/* @ENUMSTART FPDPERRESULT*/
enum FPD_PERRESULT
{
    // can not modify
    FPDPER_NOMODIFY = 1,
    // can fill in form
    FPDPER_CANFILLINFORM,
    // can fill in form and modify annot
    FPDPER_CANANNOTANDFILL,
    FPDPER_ALL
};
/* @ENUMEND*/

/* @ENUMSTART FPDPERRESULT*/
enum FPD_CertInfoType
{
    FPDNone,
    FPDCertPath,
    FPDCertID,
    FPDCertFileStream,
};
/* @ENUMEND*/

/* @ENUMSTART FPDPERRESULT*/
enum FPD_RequestResult
{
    FPDSUCCESS = 0,			//success
    FPDERROR_CREATE_SOCKET,	//can't create socket
    FPDERROR_CONNECT_FAILED,	//connect failed
    FPDERROR_SEND_DATA,		//send data failed
    FPDERROR_RECEIVE_DATA,		//receive data failed
    FPDERROR_REQUEST_FAILED,	//request failed
    FPDERROR_CANNOT_GET_DATA,	//can't get data
    FPDERROR_OUT_OF_MEMORY		//out of memory
};
/* @ENUMEND*/

/* @ENUMSTART FPDCHAINROOTVERITY_RESULT*/
enum FPD_CHAINROOTVERITY_RESULT
{
    FPDCHAINROOTVERITY_VALID,
    FPDCHAINROOTVERITY_INVALID,
    FPDCHAINROOTVERITY_INVALID_MID,
    FPDCHAINROOTVERITY_INVALID_POLICYR
};
/* @ENUMEND*/

/* @ENUMSTART FPDREVOCATION_TYPE*/
enum FPD_REVOCATION_TYPE
{
    FPDREVOCATION_NONE,
    FPDREVOCATION_OK,
    FPDREVOCATION_REVOCATION,
    FPDREVOCATION_CHAIN_REVOCATION,
    FPDREVOCATION_UNKOWN
};
/* @ENUMEND*/

/* @ENUMSTART FPDLTVTYPE*/
enum FPD_LTVTYPE
{
    FPDLTV_ENABLED,
    FPDLTV_NOTENABLED,
    FPDLTV_NONE
};
/* @ENUMEND*/

/* @ENUMSTART FPDCADESLEVEL*/
enum FPD_CADESLEVEL
{
    FPDCADES_NONE,
    FPDCADES_B,
    FPDCADES_T,
    FPDCADES_LT,
    FPDCADES_LTA,
};
/* @ENUMEND*/

/* @ENUMSTART FPD_CertificateStatus*/
enum FPD_CertificateStatus
{
    FPD_Valid = 0,
    FPD_Expired,
    FPD_NotSupported,
    FPD_ErrorData,
    FPD_WrongPassword,
    FPD_WrongPath,
};
/* @ENUMEND*/

/* @ENUMSTART FPD_DigestAlgorithm*/
enum FPD_DigestAlgorithm
{
    FPD_SHA1 = 0,
    FPD_SHA256 = 1,
    FPD_SHA384 = 2,
    FPD_SHA512 = 3,
    FPD_RIPEMD160 = 4,
};
/* @ENUMEND*/

/* @ENUMSTART FPD_SignatureHandlerType*/
enum FPD_SignatureHandlerType
{
    FPD_PKCS7 = 0,
    FPD_CADES = 1,
    FPD_RFC3161 = 2,
};
/* @ENUMEND*/

/* @ENUMSTART FPD_DownLoadStatus*/
enum FPD_DownLoadStatus
{
    FPDDR_SUCCESS,
    FPDDR_FAILED
};
/* @ENUMEND*/

/* @STRUCTSTART FPD_MODIFYDATA */
typedef struct __FPD_RefData__
{
    __FPD_RefData__()
    {
        bFillIn = FALSE;
        bAnnot = FALSE;	// form  or annot
        bSignfield = FALSE;
        bDelete = FALSE;
        bignore = FALSE;
        bAP = FALSE;
    }

    FS_BOOL bFillIn;
    FS_BOOL bAnnot;
    FS_BOOL bSignfield;
    FS_BOOL bDelete;
    FS_BOOL bignore;
    FS_BOOL bAP;
    FPD_MODIFYDATA annotinfo;
}FPD_RefData, *PFPD_RefData;
/* @STRUCTEND*/


/* @STRUCTSTART FPDCRT_DATETIMEZONE */
typedef struct __FPDCRT_DATETIMEZONE__
{
    /** @brief Year, a four-digit number, such as 2014. */
    FS_WORD		year;
    /** @brief Month, from 1 to 12. */
    FS_WORD		month;
    /** @brief Day of month, from 1 to 31. */
    FS_WORD		day;
    /** @brief Day of week, from 0 to 6. PDF standard doesn't support now, you can omit this field if it is not applicable. */
    FS_WORD		dayOfWeek;
    /** @brief Hour, from 0 to 23. */
    FS_WORD		hour;
    /** @brief Minute, from 0 to 59. */
    FS_WORD		minute;
    /** @brief Second, from 0 to 60. 60 for leap second. */
    FS_WORD		second;
    /** @brief Millisecond, from 0 to 999. PDF standard doesn't support now, you can omit this field if it is not applicable. */
    FS_WORD		milliseconds;
    /**
     * @brief Hour of time zone, from -12 to 12.
     *
     * @details	Positive value for the eastern time zone, and negative value for the western time zone.
     */
    FS_INT32	tzHour;//TESTDOC: BUG#CORE-2923
    /** @brief Minute of time zone, from 0 to 59. */
    FS_WORD		tzMinute;
}FPDCRT_DATETIMEZONE, *PFPDCRT_DATETIMEZONE;
/* @STRUCTEND*/

/* @STRUCTSTART FPDVERIFY_DATA */
typedef struct __FPDVERIFY_DATA__
{
    FPD_VERIFYTIMETYPE verifyType = FPD_VERIFYTIMETYPE::FPDTIMETYPE_CURRENTTIME;
    FPD_SYSTEMTIME verifySignTime = { 0 };
    FPD_SYSTEMTIME verifyRevoTime = { 0 };
    FPD_SYSTEMTIME verifyTSTime = { 0 };
    FPD_SYSTEMTIME verifyCurrentUTCTime = { 0 };

	FS_BOOLEAN bVerifyUseExpirdTime = TRUE;
	FS_BOOLEAN bVerifyReovction = TRUE;
	FS_BOOLEAN bIgnoreDoc = FALSE;
	FS_BOOLEAN bGetValidDSS = FALSE;
}FPDVERIFY_DATA, *PFPDVERIFY_DATA;
/* @STRUCTEND*/

/* @STRUCTSTART FPDRespInfo */
typedef struct __FPDRespInfo__	// header info
{
    FS_INT32 status_code;		   // HTTP/1.1 '200' OK
    FS_CHAR content_type[128];	// Content-Type: application/gzip
    FS_DWORD content_length;	   // Content-Length: 11683079
    FS_WideString wfile_name;
    FS_ByteString Location;
    FS_BOOL bChunked;
    __FPDRespInfo__()
    {
        bChunked = FALSE;
        status_code = 0;
        content_length = 0;
        memset(content_type, '\0', sizeof(char) * 128);
		wfile_name = NULL;
		Location = NULL;
    }
}FPDRespInfo, *PFPDRespInfo;
/* @STRUCTEND*/

/* @STRUCTSTART FPDDownLoadResult */
typedef struct __FPDDownLoadResult__
{
    FPD_DownLoadStatus status;
    FPDRespInfo respheader;
    __FPDDownLoadResult__()
    {
        status = FPD_DownLoadStatus::FPDDR_SUCCESS;
    }
}FPDDownLoadResult, *PFPDDownLoadResult;
/* @STRUCTEND*/

/* @CALLBACKGROUPSTART */
#ifndef FPD_CERTVERIFCALLBACK
#define FPD_CERTVERIFCALLBACK
typedef struct _fpd_CertVerifyHandler_callbacks_
{
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

	FS_BOOL(*FPDVerifyIsCertTrusted)(FS_LPVOID clientData, FS_LPVOID pCert,
		FS_PtrArray cerList,
		FS_BOOL bDigitalSig,
		FS_BOOL bTimeStamp,
		FS_INT32 nCurIndex,
		FS_INT32& nTrustIndex);
	FS_BOOL(*FPDVerifyIsCertTrustedRoot)(FS_LPVOID clientData, FS_LPVOID pCert, FS_BOOL bDigitalSig);
	FS_BOOL(*FPDVerifyTimeStampBefore)(FS_LPVOID clientData);
	FS_LPVOID(*FPDGetCertSoureType)(FS_LPVOID clientData, const FS_ByteString Certid, FS_SHORT* nType);
}FPD_CertVerifyHandlerCallBackRec, *FPD_CertVerifyHandlerCallBack;
#endif
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART */
#ifndef FPD_SignatureHandlerCallback
#define FPD_SignatureHandlerCallback
typedef struct _fpd_SignatureHandler_callbacks_
{
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    FS_INT32(*FPDGetCertificateInfo)(FS_LPVOID clientData, FPD_Signature pSig, FS_LPVOID pClientData);
    FS_BOOL(*FPDStartCalcDigest)(FS_LPVOID clientData, FS_FileReadHandler pFile, const FS_DWordArray byteArray, FPD_Signature pSig, FS_LPVOID pClientData);
    FS_INT32(*FPDContinueCalcDigest)(FS_LPVOID clientData, FS_PauseHandler pPause, FS_LPVOID pClientData);
    FS_BOOL(*FPDStartSign)(FS_LPVOID clientData, FS_LPVOID pClientData);
    FS_BOOL(*FPDIsNeedPadData)(FS_LPVOID clientData);
    FS_BOOL(*FPDVerify)(FS_LPVOID clientData, const FS_ByteString bsSignedData, FS_DWORD* dwVerResult, FS_LPVOID pClientData, FS_DWORD* pVerSubResult);
    FS_BOOL(*FPDGetSignVDictObjNum)(FS_LPVOID clientData, FS_DWORD* objNum);
	FS_INT32(*FPDContinueSign)(FS_LPVOID clientData, FS_PauseHandler pPause, FS_LPVOID pClientData);
	void(*FPDGetSignedData)(FS_LPVOID clientData, FS_LPVOID pClientData, FS_ByteString* outData);
}FPD_SignatureHandlerCallBackRec, *FPD_SignatureHandlerCallBack;
#endif
/* @CALLBACKGROUPEND */


/* @CALLBACKGROUPSTART */
#ifndef FPD_RevocationHandlerCallback
#define FPD_RevocationHandlerCallback
typedef struct _fpd_RevocationHandler_callbacks_
{
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    FS_BOOL(*FPDGetCertChainFromSig)(FS_LPVOID clientData, const FS_ByteString sigContent, FS_ByteStringArray* certChain);
    FPD_Response(*FPDGetResponseOnLineForSingleCert)(FS_LPVOID clientData, const FS_ByteString cert, const FS_ByteString issuer);
    FS_BOOL(*FPDVerifyOCSP)(FS_LPVOID clientData, const FS_ByteString cert, const FS_ByteString issuer, const FS_ByteString OCSPData, FPD_CertVerifyResult* result);
    FS_BOOL(*FPDVerifyCRL)(FS_LPVOID clientData, const FS_ByteString cert, const FS_ByteString issuer, const FS_ByteString CRLData, FPD_CertVerifyResult* reason);
    FS_BOOL(*FPDIsCA)(FS_LPVOID clientData, const FS_ByteString cert);
    FS_BOOL(*FPDGetDTSTime)(FS_LPVOID clientData, const FS_ByteString sigContent, FPD_SYSTEMTIME* sysTime);
    FS_BOOL(*FPDGetTSTSig)(FS_LPVOID clientData, const FS_ByteString sigContent, FS_ByteString TSTsig);
    FS_BOOL(*FPDGetTSTTime)(FS_LPVOID clientData, const FS_ByteString sigContent, FPD_SYSTEMTIME* sysTime);
    FS_BOOL(*FPDGetOCSPCertAndIssuer)(FS_LPVOID clientData, const FS_ByteString OCSPData,
        const FS_ByteStringArray trustChain,
        FS_ByteString* OCSPCert,
        FS_ByteString* OCSPIssuer);
    FS_BOOL(*FPDGetOCSPProducedAtTime)(FS_LPVOID clientData, const FS_ByteString OCSPData, FPD_SYSTEMTIME* producedAtTime);
    FS_BOOL(*FPDIsOCSPNeedCheck)(FS_LPVOID clientData, const FS_ByteString OCSPData);
    FS_BOOL(*FPDGetCertValidDate)(FS_LPVOID clientData, const FS_ByteString cert, FPD_SYSTEMTIME* certStart, FPD_SYSTEMTIME* certEnd);
    FS_BOOL(*FPDGetOCSPSig)(FS_LPVOID clientData, const FS_ByteString OCSPData, FS_ByteString* sigContent);
    FS_BOOL(*FPDGetCRLSig)(FS_LPVOID clientData, const FS_ByteString& CRLData, FS_ByteString* sigContent);
    FS_BOOL(*FPDGetRevocationInfoFromSignData)(FS_LPVOID clientData, const FS_ByteString sigContent, FS_ByteStringArray* OCSPVector, FS_ByteStringArray* CRLVector);
    FS_BOOL(*FPDIsIssuerMatchCert)(FS_LPVOID clientData, const FS_ByteString cert, const FS_ByteString issuer);
    void(*FPDSetSignTime)(FS_LPVOID clientData, FPD_TIMETYPE eType, const FPD_SYSTEMTIME ctSignTime);
    FPD_SYSTEMTIME(*FPDGetRevoCheckTime)(FS_LPVOID clientData);
    void(*FPDSetRevoCheckTime)(FS_LPVOID clientData, const FPD_SYSTEMTIME ptime);
    void(*FPDGetTimeOutUrl)(FS_LPVOID clientData, FS_ByteStringArray* url);
    void(*FPDSetTimeOutUrl)(FS_LPVOID clientData, FS_ByteStringArray url);
    void(*FPDClearCheckData)(FS_LPVOID clientData);
    void(*FPDClearCheckRevocation)(FS_LPVOID clientData);
}FPD_RevocationHandlerCallBackRec, *FPD_RevocationHandlerCallBack;
#endif
/* @CALLBACKGROUPEND */


/* @CALLBACKGROUPSTART */
#ifndef FPD_DownloadHandlerCallback
#define FPD_DownloadHandlerCallback
typedef struct _fpd_DownloadHandler_callbacks_
{
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

	void(*FPDDownloadData)(FS_LPVOID clientData, const FS_CHAR* url, FS_FileStream pFile, FPDDownLoadResult* outResult);
}FPD_DownloadHandlerCallBackRec, *FPD_DownloadHandlerCallBack;
#endif
/* @CALLBACKGROUPEND */


/* @CALLBACKSTART FPD_CALLBACK_GETKEY */
	/**
	* @brief When the signature parsing document fails, this will be called to let the
				application layer set the key needed for parsing.
	* @param[in] nFlag    Parsing failure error type PDFPARSE_ERROR_PASSWORD
						  PDFPARSE_ERROR_CERT,PDFPARSE_ERROR_HANDLER
	* @param[in] pParser  The parser used to parse documents needs to set the key such as
						  password or certificate
	* @param[in] pSrcDoc  The source document is used to represent the document being signed in
						 the current period
	*/
typedef void(*FPD_CALLBACK_GETKEY)(FS_DWORD nFlag, FPD_Parser pParser, FPD_Document pSrcDoc);
/* @CALLBACKEND */

/* @OBJSTART FPD_SSLServerNoify */
typedef struct _t_FPD_SSLServerNoify* FPD_SSLServerNoify;

/* @CALLBACKSTART FPD_CALLBACK_GETKEY */
typedef struct _fpd_SSLServerNoify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_DocEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOLEAN(*FPDGetTimeStampBySSL)(FS_LPVOID clientData, FS_ByteString* buffer, const FS_LPCSTR bsHost, FS_ByteString* sendData, FPD_RequestResult* outresult);
}FPD_SSLServerNoifyCallbacksRec, *FPD_SSLServerNoifyCallbacks;
/* @CALLBACKEND */
/* @OBJEND */

/* @OBJSTART FPD_SealInfo */
#ifndef FPD_SEALINFO
#define	FPD_SEALINFO
/**
* @brief
*/
typedef struct _t_FPD_SealInfo* FPD_SealInfo;
#endif

#define FPD_SIGNATURE_STATE_SUB_SEAL_CERT_NOT_IN_VALIDITY_PERIOD  0x00000004
#define FPD_SIGNATURE_STATE_SUB_SEAL_NOT_IN_VALIDITY_PERIOD	      0x00000008
#define FPD_SIGNATURE_STATE_SUB_SEAL_INVALID				      0x00000010
#define FPD_SIGNATURE_STATE_SUB_SEAL_CERT_NOTINLIST		          0x00000020
#define FPD_SIGNATURE_STATE_SUB_SEAL_MUST_CHECKREVOKE		      0x00000040
#define FPD_SIGNATURE_STATE_SUB_TIMESTAMP_BEFORE			      0x00000080
#define FPD_SIGNATURE_STATE_SUB_SIGN_INVALID				      0x00000100
#define FPD_SIGNATURE_STATE_SUB_SIGN_HASH_INVALID			      0x00000200

/* @OBJEND */

////////////////////////////////////////////////////
//XFA
typedef struct _t_FPD_XFADocView* FPD_XFADocView;
typedef struct _t_FPD_XFAPageView* FPD_XFAPageView;
typedef struct _t_FPD_XFAWidgetAcc* FPD_XFAWidgetAcc;
typedef struct _t_FPD_XFAWidgetHandler* FPD_XFAWidgetHandler;
typedef struct _t_FPD_XFAEventParam* FPD_XFAEventParam;
typedef struct _t_FPD_XFAWidgetIterator* FPD_XFAWidgetIterator;
typedef struct _t_FPD_XFAWidgetAccIterator* FPD_XFAWidgetAccIterator;


/* @STRUCTSTART FPDXFA_HDOC */
typedef struct  __FPDXFA_HDOC__
{
    FS_LPVOID pData;
}*PFPDXFA_HDOC;
/* @STRUCTEBD */


/* @STRUCTSTART FPDXFA_HDOC */
typedef struct __FPDXFA_HWIDGET__
{
    FS_LPVOID pData;
}*PFPDXFA_HWIDGET;
/* @STRUCTEBD */

enum FPDXFA_WIDGETORDER
{
    FPDXFA_WIDGETORDER_PreOrder,
};


/* XFA Element enumerations*/
enum FPDXFA_ELEMENT
{
    FPDXFA_ELEMENT_Ps,
    FPDXFA_ELEMENT_To,
    FPDXFA_ELEMENT_Ui,
    FPDXFA_ELEMENT_RecordSet,
    FPDXFA_ELEMENT_SubsetBelow,
    FPDXFA_ELEMENT_SubformSet,
    FPDXFA_ELEMENT_AdobeExtensionLevel,
    FPDXFA_ELEMENT_Typeface,
    FPDXFA_ELEMENT_Break,
    FPDXFA_ELEMENT_FontInfo,
    FPDXFA_ELEMENT_NumberPattern,
    FPDXFA_ELEMENT_DynamicRender,
    FPDXFA_ELEMENT_PrintScaling,
    FPDXFA_ELEMENT_CheckButton,
    FPDXFA_ELEMENT_DatePatterns,
    FPDXFA_ELEMENT_SourceSet,
    FPDXFA_ELEMENT_Amd,
    FPDXFA_ELEMENT_Arc,
    FPDXFA_ELEMENT_Day,
    FPDXFA_ELEMENT_Era,
    FPDXFA_ELEMENT_Jog,
    FPDXFA_ELEMENT_Log,
    FPDXFA_ELEMENT_Map,
    FPDXFA_ELEMENT_Mdp,
    FPDXFA_ELEMENT_BreakBefore,
    FPDXFA_ELEMENT_Oid,
    FPDXFA_ELEMENT_Pcl,
    FPDXFA_ELEMENT_Pdf,
    FPDXFA_ELEMENT_Ref,
    FPDXFA_ELEMENT_Uri,
    FPDXFA_ELEMENT_Xdc,
    FPDXFA_ELEMENT_Xdp,
    FPDXFA_ELEMENT_Xfa,
    FPDXFA_ELEMENT_Xsl,
    FPDXFA_ELEMENT_Zpl,
    FPDXFA_ELEMENT_Cache,
    FPDXFA_ELEMENT_Margin,
    FPDXFA_ELEMENT_KeyUsage,
    FPDXFA_ELEMENT_Exclude,
    FPDXFA_ELEMENT_ChoiceList,
    FPDXFA_ELEMENT_Level,
    FPDXFA_ELEMENT_LabelPrinter,
    FPDXFA_ELEMENT_CalendarSymbols,
    FPDXFA_ELEMENT_Para,
    FPDXFA_ELEMENT_Part,
    FPDXFA_ELEMENT_Pdfa,
    FPDXFA_ELEMENT_Filter,
    FPDXFA_ELEMENT_Present,
    FPDXFA_ELEMENT_Pagination,
    FPDXFA_ELEMENT_Encoding,
    FPDXFA_ELEMENT_Event,
    FPDXFA_ELEMENT_Whitespace,
    FPDXFA_ELEMENT_DefaultUi,
    FPDXFA_ELEMENT_DataModel,
    FPDXFA_ELEMENT_Barcode,
    FPDXFA_ELEMENT_TimePattern,
    FPDXFA_ELEMENT_BatchOutput,
    FPDXFA_ELEMENT_Enforce,
    FPDXFA_ELEMENT_CurrencySymbols,
    FPDXFA_ELEMENT_AddSilentPrint,
    FPDXFA_ELEMENT_Rename,
    FPDXFA_ELEMENT_Operation,
    FPDXFA_ELEMENT_Typefaces,
    FPDXFA_ELEMENT_SubjectDNs,
    FPDXFA_ELEMENT_Issuers,
    FPDXFA_ELEMENT_SignaturePseudoModel,
    FPDXFA_ELEMENT_WsdlConnection,
    FPDXFA_ELEMENT_Debug,
    FPDXFA_ELEMENT_Delta,
    FPDXFA_ELEMENT_EraNames,
    FPDXFA_ELEMENT_ModifyAnnots,
    FPDXFA_ELEMENT_StartNode,
    FPDXFA_ELEMENT_Button,
    FPDXFA_ELEMENT_Format,
    FPDXFA_ELEMENT_Border,
    FPDXFA_ELEMENT_Area,
    FPDXFA_ELEMENT_Hyphenation,
    FPDXFA_ELEMENT_Text,
    FPDXFA_ELEMENT_Time,
    FPDXFA_ELEMENT_Type,
    FPDXFA_ELEMENT_Overprint,
    FPDXFA_ELEMENT_Certificates,
    FPDXFA_ELEMENT_EncryptionMethods,
    FPDXFA_ELEMENT_SetProperty,
    FPDXFA_ELEMENT_PrinterName,
    FPDXFA_ELEMENT_StartPage,
    FPDXFA_ELEMENT_PageOffset,
    FPDXFA_ELEMENT_DateTime,
    FPDXFA_ELEMENT_Comb,
    FPDXFA_ELEMENT_Pattern,
    FPDXFA_ELEMENT_IfEmpty,
    FPDXFA_ELEMENT_SuppressBanner,
    FPDXFA_ELEMENT_OutputBin,
    FPDXFA_ELEMENT_Field,
    FPDXFA_ELEMENT_Agent,
    FPDXFA_ELEMENT_OutputXSL,
    FPDXFA_ELEMENT_AdjustData,
    FPDXFA_ELEMENT_AutoSave,
    FPDXFA_ELEMENT_ContentArea,
    FPDXFA_ELEMENT_EventPseudoModel,
    FPDXFA_ELEMENT_WsdlAddress,
    FPDXFA_ELEMENT_Solid,
    FPDXFA_ELEMENT_DateTimeSymbols,
    FPDXFA_ELEMENT_EncryptionLevel,
    FPDXFA_ELEMENT_Edge,
    FPDFPDXFA_ELEMENT_Stipple,
    FPDXFA_ELEMENT_Attributes,
    FPDXFA_ELEMENT_VersionControl,
    FPDXFA_ELEMENT_Meridiem,
    FPDXFA_ELEMENT_ExclGroup,
    FPDXFA_ELEMENT_ToolTip,
    FPDXFA_ELEMENT_Compress,
    FPDXFA_ELEMENT_Reason,
    FPDXFA_ELEMENT_Execute,
    FPDXFA_ELEMENT_ContentCopy,
    FPDXFA_ELEMENT_DateTimeEdit,
    FPDXFA_ELEMENT_Config,
    FPDXFA_ELEMENT_Image,
    FPDXFA_ELEMENT_SharpxHTML,
    FPDXFA_ELEMENT_NumberOfCopies,
    FPDXFA_ELEMENT_BehaviorOverride,
    FPDXFA_ELEMENT_TimeStamp,
    FPDXFA_ELEMENT_Month,
    FPDXFA_ELEMENT_ViewerPreferences,
    FPDXFA_ELEMENT_ScriptModel,
    FPDXFA_ELEMENT_Decimal,
    FPDXFA_ELEMENT_Subform,
    FPDXFA_ELEMENT_Select,
    FPDXFA_ELEMENT_Window,
    FPDXFA_ELEMENT_LocaleSet,
    FPDXFA_ELEMENT_Handler,
    FPDXFA_ELEMENT_HostPseudoModel,
    FPDXFA_ELEMENT_Presence,
    FPDXFA_ELEMENT_Record,
    FPDXFA_ELEMENT_Embed,
    FPDXFA_ELEMENT_Version,
    FPDXFA_ELEMENT_Command,
    FPDXFA_ELEMENT_Copies,
    FPDXFA_ELEMENT_Staple,
    FPDXFA_ELEMENT_SubmitFormat,
    FPDXFA_ELEMENT_Boolean,
    FPDXFA_ELEMENT_Message,
    FPDXFA_ELEMENT_Output,
    FPDXFA_ELEMENT_PsMap,
    FPDXFA_ELEMENT_ExcludeNS,
    FPDXFA_ELEMENT_Assist,
    FPDXFA_ELEMENT_Picture,
    FPDXFA_ELEMENT_Traversal,
    FPDXFA_ELEMENT_SilentPrint,
    FPDXFA_ELEMENT_WebClient,
    FPDXFA_ELEMENT_LayoutPseudoModel,
    FPDXFA_ELEMENT_Producer,
    FPDXFA_ELEMENT_Corner,
    FPDXFA_ELEMENT_MsgId,
    FPDXFA_ELEMENT_Color,
    FPDXFA_ELEMENT_Keep,
    FPDXFA_ELEMENT_Query,
    FPDXFA_ELEMENT_Insert,
    FPDXFA_ELEMENT_ImageEdit,
    FPDXFA_ELEMENT_Validate,
    FPDXFA_ELEMENT_DigestMethods,
    FPDXFA_ELEMENT_NumberPatterns,
    FPDXFA_ELEMENT_PageSet,
    FPDXFA_ELEMENT_Integer,
    FPDXFA_ELEMENT_SoapAddress,
    FPDXFA_ELEMENT_Equate,
    FPDXFA_ELEMENT_FormFieldFilling,
    FPDXFA_ELEMENT_PageRange,
    FPDXFA_ELEMENT_Update,
    FPDXFA_ELEMENT_ConnectString,
    FPDXFA_ELEMENT_Mode,
    FPDXFA_ELEMENT_Layout,
    FPDXFA_ELEMENT_Sharpxml,
    FPDXFA_ELEMENT_XsdConnection,
    FPDXFA_ELEMENT_Traverse,
    FPDXFA_ELEMENT_Encodings,
    FPDXFA_ELEMENT_Template,
    FPDXFA_ELEMENT_Acrobat,
    FPDXFA_ELEMENT_ValidationMessaging,
    FPDXFA_ELEMENT_Signing,
    FPDXFA_ELEMENT_DataWindow,
    FPDXFA_ELEMENT_Script,
    FPDXFA_ELEMENT_AddViewerPreferences,
    FPDXFA_ELEMENT_AlwaysEmbed,
    FPDXFA_ELEMENT_PasswordEdit,
    FPDXFA_ELEMENT_NumericEdit,
    FPDXFA_ELEMENT_EncryptionMethod,
    FPDXFA_ELEMENT_Change,
    FPDXFA_ELEMENT_PageArea,
    FPDXFA_ELEMENT_SubmitUrl,
    FPDXFA_ELEMENT_Oids,
    FPDXFA_ELEMENT_Signature,
    FPDXFA_ELEMENT_ADBE_JSConsole,
    FPDXFA_ELEMENT_Caption,
    FPDXFA_ELEMENT_Relevant,
    FPDXFA_ELEMENT_FlipLabel,
    FPDXFA_ELEMENT_ExData,
    FPDXFA_ELEMENT_DayNames,
    FPDXFA_ELEMENT_SoapAction,
    FPDXFA_ELEMENT_DefaultTypeface,
    FPDXFA_ELEMENT_Manifest,
    FPDXFA_ELEMENT_Overflow,
    FPDXFA_ELEMENT_Linear,
    FPDXFA_ELEMENT_CurrencySymbol,
    FPDXFA_ELEMENT_Delete,
    FPDXFA_ELEMENT_Deltas,
    FPDXFA_ELEMENT_DigestMethod,
    FPDXFA_ELEMENT_InstanceManager,
    FPDXFA_ELEMENT_EquateRange,
    FPDXFA_ELEMENT_Medium,
    FPDXFA_ELEMENT_TextEdit,
    FPDXFA_ELEMENT_TemplateCache,
    FPDXFA_ELEMENT_CompressObjectStream,
    FPDXFA_ELEMENT_DataValue,
    FPDXFA_ELEMENT_AccessibleContent,
    FPDXFA_ELEMENT_NodeList,
    FPDXFA_ELEMENT_IncludeXDPContent,
    FPDXFA_ELEMENT_XmlConnection,
    FPDXFA_ELEMENT_ValidateApprovalSignatures,
    FPDXFA_ELEMENT_SignData,
    FPDXFA_ELEMENT_Packets,
    FPDXFA_ELEMENT_DatePattern,
    FPDXFA_ELEMENT_DuplexOption,
    FPDXFA_ELEMENT_Base,
    FPDXFA_ELEMENT_Bind,
    FPDXFA_ELEMENT_Compression,
    FPDXFA_ELEMENT_User,
    FPDXFA_ELEMENT_Rectangle,
    FPDXFA_ELEMENT_EffectiveOutputPolicy,
    FPDXFA_ELEMENT_ADBE_JSDebugger,
    FPDXFA_ELEMENT_Acrobat7,
    FPDXFA_ELEMENT_Interactive,
    FPDXFA_ELEMENT_Locale,
    FPDXFA_ELEMENT_CurrentPage,
    FPDXFA_ELEMENT_Data,
    FPDXFA_ELEMENT_Date,
    FPDXFA_ELEMENT_Desc,
    FPDXFA_ELEMENT_Encrypt,
    FPDXFA_ELEMENT_Draw,
    FPDXFA_ELEMENT_Encryption,
    FPDXFA_ELEMENT_MeridiemNames,
    FPDXFA_ELEMENT_Messaging,
    FPDXFA_ELEMENT_Speak,
    FPDXFA_ELEMENT_DataGroup,
    FPDXFA_ELEMENT_Common,
    FPDXFA_ELEMENT_Sharptext,
    FPDXFA_ELEMENT_PaginationOverride,
    FPDXFA_ELEMENT_Reasons,
    FPDXFA_ELEMENT_SignatureProperties,
    FPDXFA_ELEMENT_Threshold,
    FPDXFA_ELEMENT_AppearanceFilter,
    FPDXFA_ELEMENT_Fill,
    FPDXFA_ELEMENT_Font,
    FPDXFA_ELEMENT_Form,
    FPDXFA_ELEMENT_MediumInfo,
    FPDXFA_ELEMENT_Certificate,
    FPDXFA_ELEMENT_Password,
    FPDXFA_ELEMENT_RunScripts,
    FPDXFA_ELEMENT_Trace,
    FPDXFA_ELEMENT_Float,
    FPDXFA_ELEMENT_RenderPolicy,
    FPDXFA_ELEMENT_LogPseudoModel,
    FPDXFA_ELEMENT_Destination,
    FPDXFA_ELEMENT_Value,
    FPDXFA_ELEMENT_Bookend,
    FPDXFA_ELEMENT_ExObject,
    FPDXFA_ELEMENT_OpenAction,
    FPDXFA_ELEMENT_NeverEmbed,
    FPDXFA_ELEMENT_BindItems,
    FPDXFA_ELEMENT_Calculate,
    FPDXFA_ELEMENT_Print,
    FPDXFA_ELEMENT_Extras,
    FPDXFA_ELEMENT_Proto,
    FPDXFA_ELEMENT_DSigData,
    FPDXFA_ELEMENT_Creator,
    FPDXFA_ELEMENT_Connect,
    FPDXFA_ELEMENT_Permissions,
    FPDXFA_ELEMENT_ConnectionSet,
    FPDXFA_ELEMENT_Submit,
    FPDXFA_ELEMENT_Range,
    FPDXFA_ELEMENT_Linearized,
    FPDXFA_ELEMENT_Packet,
    FPDXFA_ELEMENT_RootElement,
    FPDXFA_ELEMENT_PlaintextMetadata,
    FPDXFA_ELEMENT_NumberSymbols,
    FPDXFA_ELEMENT_PrintHighQuality,
    FPDXFA_ELEMENT_Driver,
    FPDXFA_ELEMENT_IncrementalLoad,
    FPDXFA_ELEMENT_SubjectDN,
    FPDXFA_ELEMENT_CompressLogicalStructure,
    FPDXFA_ELEMENT_IncrementalMerge,
    FPDXFA_ELEMENT_Radial,
    FPDXFA_ELEMENT_Variables,
    FPDXFA_ELEMENT_TimePatterns,
    FPDXFA_ELEMENT_EffectiveInputPolicy,
    FPDXFA_ELEMENT_NameAttr,
    FPDXFA_ELEMENT_Conformance,
    FPDXFA_ELEMENT_Transform,
    FPDXFA_ELEMENT_LockDocument,
    FPDXFA_ELEMENT_BreakAfter,
    FPDXFA_ELEMENT_Line,
    FPDXFA_ELEMENT_List,
    FPDXFA_ELEMENT_Source,
    FPDXFA_ELEMENT_Occur,
    FPDXFA_ELEMENT_PickTrayByPDFSize,
    FPDXFA_ELEMENT_MonthNames,
    FPDXFA_ELEMENT_Severity,
    FPDXFA_ELEMENT_GroupParent,
    FPDXFA_ELEMENT_DocumentAssembly,
    FPDXFA_ELEMENT_NumberSymbol,
    FPDXFA_ELEMENT_Tagged,
    FPDXFA_ELEMENT_Items,
};


//* XFA Attribute enumerations
//*****************************************************************************
enum FPDXFA_ATTRIBUTEENUM
{
    FPDXFA_ATTRIBUTEENUM_Asterisk,
    FPDXFA_ATTRIBUTEENUM_Slash,
    FPDXFA_ATTRIBUTEENUM_Backslash,
    FPDXFA_ATTRIBUTEENUM_On,
    FPDXFA_ATTRIBUTEENUM_Tb,
    FPDXFA_ATTRIBUTEENUM_Up,
    FPDXFA_ATTRIBUTEENUM_MetaData,
    FPDXFA_ATTRIBUTEENUM_Delegate,
    FPDXFA_ATTRIBUTEENUM_PostSubmit,
    FPDXFA_ATTRIBUTEENUM_Name,
    FPDXFA_ATTRIBUTEENUM_Cross,
    FPDXFA_ATTRIBUTEENUM_Next,
    FPDXFA_ATTRIBUTEENUM_None,
    FPDXFA_ATTRIBUTEENUM_ShortEdge,
    FPDXFA_ATTRIBUTEENUM_1mod10_1mod11,
    FPDXFA_ATTRIBUTEENUM_Height,
    FPDXFA_ATTRIBUTEENUM_CrossDiagonal,
    FPDXFA_ATTRIBUTEENUM_All,
    FPDXFA_ATTRIBUTEENUM_Any,
    FPDXFA_ATTRIBUTEENUM_ToRight,
    FPDXFA_ATTRIBUTEENUM_MatchTemplate,
    FPDXFA_ATTRIBUTEENUM_Dpl,
    FPDXFA_ATTRIBUTEENUM_Invisible,
    FPDXFA_ATTRIBUTEENUM_Fit,
    FPDXFA_ATTRIBUTEENUM_Width,
    FPDXFA_ATTRIBUTEENUM_PreSubmit,
    FPDXFA_ATTRIBUTEENUM_Ipl,
    FPDXFA_ATTRIBUTEENUM_FlateCompress,
    FPDXFA_ATTRIBUTEENUM_Med,
    FPDXFA_ATTRIBUTEENUM_Odd,
    FPDXFA_ATTRIBUTEENUM_Off,
    FPDXFA_ATTRIBUTEENUM_Pdf,
    FPDXFA_ATTRIBUTEENUM_Row,
    FPDXFA_ATTRIBUTEENUM_Top,
    FPDXFA_ATTRIBUTEENUM_Xdp,
    FPDXFA_ATTRIBUTEENUM_Xfd,
    FPDXFA_ATTRIBUTEENUM_Xml,
    FPDXFA_ATTRIBUTEENUM_Zip,
    FPDXFA_ATTRIBUTEENUM_Zpl,
    FPDXFA_ATTRIBUTEENUM_Visible,
    FPDXFA_ATTRIBUTEENUM_Exclude,
    FPDXFA_ATTRIBUTEENUM_Filler,
    FPDXFA_ATTRIBUTEENUM_MouseEnter,
    FPDXFA_ATTRIBUTEENUM_Pair,
    FPDXFA_ATTRIBUTEENUM_MoveLast,
    FPDXFA_ATTRIBUTEENUM_ExportAndImport,
    FPDXFA_ATTRIBUTEENUM_Push,
    FPDXFA_ATTRIBUTEENUM_Decrypt,
    FPDXFA_ATTRIBUTEENUM_Portrait,
    FPDXFA_ATTRIBUTEENUM_Default,
    FPDXFA_ATTRIBUTEENUM_StoredProc,
    FPDXFA_ATTRIBUTEENUM_StayBOF,
    FPDXFA_ATTRIBUTEENUM_StayEOF,
    FPDXFA_ATTRIBUTEENUM_PostPrint,
    FPDXFA_ATTRIBUTEENUM_UsCarrier,
    FPDXFA_ATTRIBUTEENUM_Right,
    FPDXFA_ATTRIBUTEENUM_PreOpen,
    FPDXFA_ATTRIBUTEENUM_Actual,
    FPDXFA_ATTRIBUTEENUM_Rest,
    FPDXFA_ATTRIBUTEENUM_TopCenter,
    FPDXFA_ATTRIBUTEENUM_StandardSymbol,
    FPDXFA_ATTRIBUTEENUM_Initialize,
    FPDXFA_ATTRIBUTEENUM_JustifyAll,
    FPDXFA_ATTRIBUTEENUM_Normal,
    FPDXFA_ATTRIBUTEENUM_Landscape,
    FPDXFA_ATTRIBUTEENUM_NonInteractive,
    FPDXFA_ATTRIBUTEENUM_MouseExit,
    FPDXFA_ATTRIBUTEENUM_Minus,
    FPDXFA_ATTRIBUTEENUM_DiagonalLeft,
    FPDXFA_ATTRIBUTEENUM_SimplexPaginated,
    FPDXFA_ATTRIBUTEENUM_Document,
    FPDXFA_ATTRIBUTEENUM_Warning,
    FPDXFA_ATTRIBUTEENUM_Auto,
    FPDXFA_ATTRIBUTEENUM_Below,
    FPDXFA_ATTRIBUTEENUM_BottomLeft,
    FPDXFA_ATTRIBUTEENUM_BottomCenter,
    FPDXFA_ATTRIBUTEENUM_Tcpl,
    FPDXFA_ATTRIBUTEENUM_Text,
    FPDXFA_ATTRIBUTEENUM_Grouping,
    FPDXFA_ATTRIBUTEENUM_SecureSymbol,
    FPDXFA_ATTRIBUTEENUM_PreExecute,
    FPDXFA_ATTRIBUTEENUM_DocClose,
    FPDXFA_ATTRIBUTEENUM_Keyset,
    FPDXFA_ATTRIBUTEENUM_Vertical,
    FPDXFA_ATTRIBUTEENUM_PreSave,
    FPDXFA_ATTRIBUTEENUM_PreSign,
    FPDXFA_ATTRIBUTEENUM_Bottom,
    FPDXFA_ATTRIBUTEENUM_ToTop,
    FPDXFA_ATTRIBUTEENUM_Verify,
    FPDXFA_ATTRIBUTEENUM_First,
    FPDXFA_ATTRIBUTEENUM_ContentArea,
    FPDXFA_ATTRIBUTEENUM_Solid,
    FPDXFA_ATTRIBUTEENUM_Pessimistic,
    FPDXFA_ATTRIBUTEENUM_DuplexPaginated,
    FPDXFA_ATTRIBUTEENUM_Round,
    FPDXFA_ATTRIBUTEENUM_Remerge,
    FPDXFA_ATTRIBUTEENUM_Ordered,
    FPDXFA_ATTRIBUTEENUM_Percent,
    FPDXFA_ATTRIBUTEENUM_Even,
    FPDXFA_ATTRIBUTEENUM_Exit,
    FPDXFA_ATTRIBUTEENUM_ToolTip,
    FPDXFA_ATTRIBUTEENUM_OrderedOccurrence,
    FPDXFA_ATTRIBUTEENUM_ReadOnly,
    FPDXFA_ATTRIBUTEENUM_Currency,
    FPDXFA_ATTRIBUTEENUM_Concat,
    FPDXFA_ATTRIBUTEENUM_Thai,
    FPDXFA_ATTRIBUTEENUM_Embossed,
    FPDXFA_ATTRIBUTEENUM_Formdata,
    FPDXFA_ATTRIBUTEENUM_Greek,
    FPDXFA_ATTRIBUTEENUM_Decimal,
    FPDXFA_ATTRIBUTEENUM_Select,
    FPDXFA_ATTRIBUTEENUM_LongEdge,
    FPDXFA_ATTRIBUTEENUM_Protected,
    FPDXFA_ATTRIBUTEENUM_BottomRight,
    FPDXFA_ATTRIBUTEENUM_Zero,
    FPDXFA_ATTRIBUTEENUM_ForwardOnly,
    FPDXFA_ATTRIBUTEENUM_DocReady,
    FPDXFA_ATTRIBUTEENUM_Hidden,
    FPDXFA_ATTRIBUTEENUM_Include,
    FPDXFA_ATTRIBUTEENUM_Dashed,
    FPDXFA_ATTRIBUTEENUM_MultiSelect,
    FPDXFA_ATTRIBUTEENUM_Inactive,
    FPDXFA_ATTRIBUTEENUM_Embed,
    FPDXFA_ATTRIBUTEENUM_Static,
    FPDXFA_ATTRIBUTEENUM_OnEntry,
    FPDXFA_ATTRIBUTEENUM_Cyrillic,
    FPDXFA_ATTRIBUTEENUM_TopRight,
    FPDXFA_ATTRIBUTEENUM_Hebrew,
    FPDXFA_ATTRIBUTEENUM_TopLeft,
    FPDXFA_ATTRIBUTEENUM_Center,
    FPDXFA_ATTRIBUTEENUM_MoveFirst,
    FPDXFA_ATTRIBUTEENUM_Diamond,
    FPDXFA_ATTRIBUTEENUM_PageOdd,
    FPDXFA_ATTRIBUTEENUM_1mod10,
    FPDXFA_ATTRIBUTEENUM_Korean,
    FPDXFA_ATTRIBUTEENUM_AboveEmbedded,
    FPDXFA_ATTRIBUTEENUM_ZipCompress,
    FPDXFA_ATTRIBUTEENUM_Numeric,
    FPDXFA_ATTRIBUTEENUM_Circle,
    FPDXFA_ATTRIBUTEENUM_ToBottom,
    FPDXFA_ATTRIBUTEENUM_Inverted,
    FPDXFA_ATTRIBUTEENUM_Update,
    FPDXFA_ATTRIBUTEENUM_Isoname,
    FPDXFA_ATTRIBUTEENUM_Server,
    FPDXFA_ATTRIBUTEENUM_Position,
    FPDXFA_ATTRIBUTEENUM_MiddleCenter,
    FPDXFA_ATTRIBUTEENUM_Optional,
    FPDXFA_ATTRIBUTEENUM_UsePrinterSetting,
    FPDXFA_ATTRIBUTEENUM_Outline,
    FPDXFA_ATTRIBUTEENUM_IndexChange,
    FPDXFA_ATTRIBUTEENUM_Change,
    FPDXFA_ATTRIBUTEENUM_PageArea,
    FPDXFA_ATTRIBUTEENUM_Once,
    FPDXFA_ATTRIBUTEENUM_Only,
    FPDXFA_ATTRIBUTEENUM_Open,
    FPDXFA_ATTRIBUTEENUM_Caption,
    FPDXFA_ATTRIBUTEENUM_Raised,
    FPDXFA_ATTRIBUTEENUM_Justify,
    FPDXFA_ATTRIBUTEENUM_RefAndDescendants,
    FPDXFA_ATTRIBUTEENUM_Short,
    FPDXFA_ATTRIBUTEENUM_PageFront,
    FPDXFA_ATTRIBUTEENUM_Monospace,
    FPDXFA_ATTRIBUTEENUM_Middle,
    FPDXFA_ATTRIBUTEENUM_PrePrint,
    FPDXFA_ATTRIBUTEENUM_Always,
    FPDXFA_ATTRIBUTEENUM_Unknown,
    FPDXFA_ATTRIBUTEENUM_ToLeft,
    FPDXFA_ATTRIBUTEENUM_Above,
    FPDXFA_ATTRIBUTEENUM_DashDot,
    FPDXFA_ATTRIBUTEENUM_Gregorian,
    FPDXFA_ATTRIBUTEENUM_Roman,
    FPDXFA_ATTRIBUTEENUM_MouseDown,
    FPDXFA_ATTRIBUTEENUM_Symbol,
    FPDXFA_ATTRIBUTEENUM_PageEven,
    FPDXFA_ATTRIBUTEENUM_Sign,
    FPDXFA_ATTRIBUTEENUM_AddNew,
    FPDXFA_ATTRIBUTEENUM_Star,
    FPDXFA_ATTRIBUTEENUM_Optimistic,
    FPDXFA_ATTRIBUTEENUM_Rl_tb,
    FPDXFA_ATTRIBUTEENUM_MiddleRight,
    FPDXFA_ATTRIBUTEENUM_Maintain,
    FPDXFA_ATTRIBUTEENUM_Package,
    FPDXFA_ATTRIBUTEENUM_SimplifiedChinese,
    FPDXFA_ATTRIBUTEENUM_ToCenter,
    FPDXFA_ATTRIBUTEENUM_Back,
    FPDXFA_ATTRIBUTEENUM_Unspecified,
    FPDXFA_ATTRIBUTEENUM_BatchOptimistic,
    FPDXFA_ATTRIBUTEENUM_Bold,
    FPDXFA_ATTRIBUTEENUM_Both,
    FPDXFA_ATTRIBUTEENUM_Butt,
    FPDXFA_ATTRIBUTEENUM_Client,
    FPDXFA_ATTRIBUTEENUM_2mod10,
    FPDXFA_ATTRIBUTEENUM_ImageOnly,
    FPDXFA_ATTRIBUTEENUM_Horizontal,
    FPDXFA_ATTRIBUTEENUM_Dotted,
    FPDXFA_ATTRIBUTEENUM_UserControl,
    FPDXFA_ATTRIBUTEENUM_DiagonalRight,
    FPDXFA_ATTRIBUTEENUM_ConsumeData,
    FPDXFA_ATTRIBUTEENUM_Check,
    FPDXFA_ATTRIBUTEENUM_Data,
    FPDXFA_ATTRIBUTEENUM_Down,
    FPDXFA_ATTRIBUTEENUM_SansSerif,
    FPDXFA_ATTRIBUTEENUM_Inline,
    FPDXFA_ATTRIBUTEENUM_TraditionalChinese,
    FPDXFA_ATTRIBUTEENUM_Warn,
    FPDXFA_ATTRIBUTEENUM_RefOnly,
    FPDXFA_ATTRIBUTEENUM_InteractiveForms,
    FPDXFA_ATTRIBUTEENUM_Word,
    FPDXFA_ATTRIBUTEENUM_Unordered,
    FPDXFA_ATTRIBUTEENUM_Required,
    FPDXFA_ATTRIBUTEENUM_ImportOnly,
    FPDXFA_ATTRIBUTEENUM_BelowEmbedded,
    FPDXFA_ATTRIBUTEENUM_Japanese,
    FPDXFA_ATTRIBUTEENUM_Full,
    FPDXFA_ATTRIBUTEENUM_Rl_row,
    FPDXFA_ATTRIBUTEENUM_Vietnamese,
    FPDXFA_ATTRIBUTEENUM_EastEuropeanRoman,
    FPDXFA_ATTRIBUTEENUM_MouseUp,
    FPDXFA_ATTRIBUTEENUM_ExportOnly,
    FPDXFA_ATTRIBUTEENUM_Clear,
    FPDXFA_ATTRIBUTEENUM_Click,
    FPDXFA_ATTRIBUTEENUM_Base64,
    FPDXFA_ATTRIBUTEENUM_Close,
    FPDXFA_ATTRIBUTEENUM_Host,
    FPDXFA_ATTRIBUTEENUM_Global,
    FPDXFA_ATTRIBUTEENUM_Blank,
    FPDXFA_ATTRIBUTEENUM_Table,
    FPDXFA_ATTRIBUTEENUM_Import,
    FPDXFA_ATTRIBUTEENUM_Custom,
    FPDXFA_ATTRIBUTEENUM_MiddleLeft,
    FPDXFA_ATTRIBUTEENUM_PostExecute,
    FPDXFA_ATTRIBUTEENUM_NotBlank,
    FPDXFA_ATTRIBUTEENUM_Radix,
    FPDXFA_ATTRIBUTEENUM_PostOpen,
    FPDXFA_ATTRIBUTEENUM_Enter,
    FPDXFA_ATTRIBUTEENUM_Ignore,
    FPDXFA_ATTRIBUTEENUM_Lr_tb,
    FPDXFA_ATTRIBUTEENUM_Fantasy,
    FPDXFA_ATTRIBUTEENUM_Italic,
    FPDXFA_ATTRIBUTEENUM_Author,
    FPDXFA_ATTRIBUTEENUM_ToEdge,
    FPDXFA_ATTRIBUTEENUM_Choice,
    FPDXFA_ATTRIBUTEENUM_Disabled,
    FPDXFA_ATTRIBUTEENUM_CrossHatch,
    FPDXFA_ATTRIBUTEENUM_DataRef,
    FPDXFA_ATTRIBUTEENUM_DashDotDot,
    FPDXFA_ATTRIBUTEENUM_Square,
    FPDXFA_ATTRIBUTEENUM_Dynamic,
    FPDXFA_ATTRIBUTEENUM_Manual,
    FPDXFA_ATTRIBUTEENUM_Etched,
    FPDXFA_ATTRIBUTEENUM_ValidationState,
    FPDXFA_ATTRIBUTEENUM_Cursive,
    FPDXFA_ATTRIBUTEENUM_Last,
    FPDXFA_ATTRIBUTEENUM_Left,
    FPDXFA_ATTRIBUTEENUM_Link,
    FPDXFA_ATTRIBUTEENUM_Long,
    FPDXFA_ATTRIBUTEENUM_InternationalCarrier,
    FPDXFA_ATTRIBUTEENUM_PDF1_3,
    FPDXFA_ATTRIBUTEENUM_PDF1_6,
    FPDXFA_ATTRIBUTEENUM_Serif,
    FPDXFA_ATTRIBUTEENUM_PostSave,
    FPDXFA_ATTRIBUTEENUM_Ready,
    FPDXFA_ATTRIBUTEENUM_PostSign,
    FPDXFA_ATTRIBUTEENUM_Arabic,
    FPDXFA_ATTRIBUTEENUM_Error,
    FPDXFA_ATTRIBUTEENUM_Urlencoded,
    FPDXFA_ATTRIBUTEENUM_Lowered,
};


enum FPDXFA_EVENTTYPE
{
    FPDXFA_EVENT_Click,			/**< Occurs when the user clicks in the field. */
    FPDXFA_EVENT_Change,			/**< Occurs when the user changes the field value. */
    FPDXFA_EVENT_DocClose,			/**< This event fires at the very end of processing if and only if all validations succeeded. */
    FPDXFA_EVENT_DocReady,			/**< This event fires before the document is rendered but after data binding. */
    FPDXFA_EVENT_Enter,			/**< The enter event fires when the field gains keyboard focus, whether caused by a user action
                                    (tabbing into the field or clicking on it with the mouse) or by a script programmatically setting
                                    the preSubmit event applies only to the Form DOM ($form). */
    FPDXFA_EVENT_Exit,				/**< The exit event fires when keyboard focus is yielded from a field directly or indirectly within the
                                    subform to a field or other object outside the subform. */
    FPDXFA_EVENT_Full,				/**< This event fires when the user has entered the maximum allowed amount of content into the field
                                    and tries to enter more content. */
    FPDXFA_EVENT_IndexChange,		/**< This event fires to tell an object that it has just been added to an array or that its position in
                                    the array (its subscript) has changed. */
    FPDXFA_EVENT_Initialize,		/**< This event fires after data binding is complete. */
    FPDXFA_EVENT_MouseDown,		/**< The mouseDown event fires when the mouse button is depressed at a moment when the mouse pointer is
                                    within the region. */
    FPDXFA_EVENT_MouseEnter,		/**< The mouseEnter event fires when the user moves the mouse pointer into the region of the field,
                                    without necessarily pressing the mouse button. */
    FPDXFA_EVENT_MouseExit,		/**< The mouseExit event fires when user moves the mouse pointer out of the field, whether the mouse
                                    button is depressed or not. */
    FPDXFA_EVENT_MouseUp,			/**< The mouseUp event fires when the mouse button is released at a moment when the mouse pointer is
                                    within the region. */
    FPDXFA_EVENT_PostExecute,		/**< After a successful WSDL transaction the postExecute event fires just after the reply to the
                                    request has been received and the received data is marshalled in the Connection Data DOM. */
    FPDXFA_EVENT_PostOpen,			/**< @see #EVENT_PreOpen */
    FPDXFA_EVENT_PostPrint,		/**< The postPrint event fires just after the rendered form has been sent to the printer, spooler, or
                                    output destination. */
    FPDXFA_EVENT_PostSave,			/**< The postSave event fires just after the form has been written out in PDF or XDP format. */
    FPDXFA_EVENT_PostSign,			/**< After successfully applying a signature the postSign event fires. */
    FPDXFA_EVENT_PostSubmit,		/**< postSubmit fires just after the returned data has been marshalled in the Connection Data DOM. */
    FPDXFA_EVENT_PreExecute,		/**< The preExecute event fires when a request is sent to a web service via WSDL, just after the data
                                    has been marshalled in the Connection Data DOM but before the request has been sent. */
    FPDXFA_EVENT_PreOpen,			/**< These events apply only to drop-down choice lists, or more specifically choice lists for which
                                    open="userControl" or open="onEntry".  The events are intended to trigger scripts that
                                    add choices to and remove choices from the choice list. This is especially useful when the choice
                                    list varies dynamically.*/
    FPDXFA_EVENT_PrePrint,			/**< The prePrint event fires just before rendering for print begins. */
    FPDXFA_EVENT_PreSave,			/**< The preSave event fires just before the form data is written out in PDF or XDP format. */
    FPDXFA_EVENT_PreSign,			/**< The preSign event fires when a signature is about to be applied. */
    FPDXFA_EVENT_PreSubmit,		/**< preSubmit fires just after the data has been marshalled in the Connection Data DOM but before
                                    validation and before the data is submitted to the host. */
    FPDXFA_EVENT_Ready,			/**< The ready event fires after an XFA DOM has finished loading. */

    FPDXFA_EVENT_InitCalculate,		/**< first run calculate. */
    FPDXFA_EVENT_InitVariables,	/**< Not a evnet activity, just sign script in variables. */
    FPDXFA_EVENT_Calculate,		/**< call calculate. */
    FPDXFA_EVENT_Validate,			/**< call validate. */
    FPDXFA_EVENT_Unknown,			/**< Unknown. */
};


/**
 * @name XFA widget status
 */
#define FPDXFA_WIDGETSTATUS_Visible	    0x00000001
/** @brief Invisible. */
#define FPDXFA_WIDGETSTATUS_Invisible	0x00000002
/** @brief Hidden. */
#define FPDXFA_WIDGETSTATUS_Hidden		0x00000004
/** @brief Viewable. */
#define FPDXFA_WIDGETSTATUS_Viewable	0x00000010
/** @brief Print. */
#define FPDXFA_WIDGETSTATUS_Printable	0x00000020
/** @brief Focused. */
#define FPDXFA_WIDGETSTATUS_Focused	    0x00000100


/** @brief Invalidate all pages. */
#define FPDXFA_INVALIDATE_AllPages		0x00000000
/** @brief Invalidate current page only. */
#define FPDXFA_INVALIDATE_CurrentPage	0x00000001


/* @OBJSTART FPD_StructTreeEntity */
#ifndef FPD_STRUCTTREEENTITY
#define FPD_STRUCTTREEENTITY
	/**
	* @brief PDF structure tree entity class.
	*/
typedef struct _t_FPD_StructTreeEntity* FPD_StructTreeEntity;
#endif
/* @OBJEND */


/* @OBJSTART FPD_StructTree */
#ifndef FPD_STRUCTTREE
#define FPD_STRUCTTREE
	/**
	* @brief PDF structure tree class. The logical structure tree. 	
	*/
typedef struct _t_FPD_StructTree* FPD_StructTree;
#endif

enum FPD_TraverseCommand
{
	FPD_TraverseContinue,
	FPD_TraverseSkipChildren,
	FPD_TraverseBreak,
};

typedef FPD_TraverseCommand(*FPDTraverseCallback)(FPD_StructTreeEntity pEntity, FS_LPVOID pUserData);
/* @OBJEND */


/* @OBJSTART FPD_StructElement */
#ifndef FPD_STRUCTELEMENT
#define FPD_STRUCTELEMENT
	/**
	* @brief PDF structure element class. You can use any FPD_StructTreeEntity method on FPD_StructElement.
	*/
typedef struct _t_FPD_StructElement* FPD_StructElement;
#endif

/* @ENUMSTART */
/** @brief entity type.
 */
enum FPD_EntityType {
	FPD_EntityElement,			/** Structure element. */
	FPD_EntityMarkedContentSeq,	/** Marked-content sequence. */
	FPD_EntityObject				/** An entire object, such as an XObject or an annotation. */
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief entity type.
 */
enum FPD_StructElementInfo
{
	FPD_StructElementInfo_Title,
	FPD_StructElementInfo_Lang,
	FPD_StructElementInfo_AltDesc,
	FPD_StructElementInfo_ExpandedForm,
	FPD_StructElementInfo_ActualText,
};
/* @ENUMEND */
/* @OBJEND */

/* @OBJSTART FPD_MarkContentReference */
#ifndef FPD_MARKCONTENTREFERENCE
#define FPD_MARKCONTENTREFERENCE
	/**
	* @brief PDF content reference. You can use any FPD_StructTreeEntity method on FPD_MarkContentReference.
	*/
typedef struct _t_FPD_MarkContentReference* FPD_MarkContentReference;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ObjectReference */
#ifndef FPD_OBJECTREFERENCE
#define FPD_OBJECTREFERENCE
	/**
	* @brief PDF object reference. You can use any FPD_StructTreeEntity method on FPD_ObjectReference.
	*/
typedef struct _t_FPD_ObjectReference* FPD_ObjectReference;
#endif

enum FPD_ObjectType {
	/** Invalid data */
	FPD_ObjInvalid,	
	/** Image XObject. */
	FPD_ObjImage,	
	/** Form XObject. */
	FPD_ObjForm,	
	/** Annotation. */
	FPD_ObjAnnot,			
};
/* @OBJEND */

/* @OBJSTART FPD_MarkInfo */
#ifndef FPD_MARKINFO
#define FPD_MARKINFO
	/**
	* @brief A mark information about the document’s usage of Tagged PDF conventions.
	* It used to set mark information dictionary of the document.
	*/
typedef struct _t_FPD_MarkInfo* FPD_MarkInfo;
#endif
/* @OBJEND */

/* @OBJSTART FPD_PageTemplate */
#ifndef FPD_PAGETEMPLATE
#define	FPD_PAGETEMPLATE
/**
* @brief  Page template Support.
*
*/
typedef struct _t_FPD_PageTemplate* FPD_PageTemplate;
#endif

/* @ENUMSTART */
/** @brief find template type.
 */
enum FPD_FINDTEMPLATETYPE
{
	FPD_FIND_VISIBLE = 0,
	FPD_FIND_INVISIBLE,
	FPD_FIND_ALL
};
/* @ENUMEND */
/* @OBJEND */

/* @OBJSTART FPD_EmbedFontSubset */
#ifndef FPD_EMBEDFONTSUBSET
#define	FPD_EMBEDFONTSUBSET
/**
* @brief  Embed font subset.
*
*/
typedef struct _t_FPD_EmbedFontSubset* FPD_EmbedFontSubset;
#endif
/* @OBJEND */


/* @OBJSTART FPD_GMSKFEngine */
/* @DEFGROUPSTART FPDLoadErrCodes */
	/**
	* @brief The error codes definitions for PDF loading.
	*/
	/*@{*/
// The driver cannot be enumerated. Generally, the key is not inserted
#define FPDSKFError_EnumDev 0x0001
// Unable to enumerate to container, the set driver may be wrong
#define FPDSKFError_EnumContainer 0x0002
// The driver cannot be Connect. Generally, the key is not inserted
#define FPDSKFError_ConnectDev 0x0003
// Unable to enumerate to Application , the set driver may be wrong
#define FPDSKFError_EnumApplication 0x0004
// Unable to open to Application , the set driver may be wrong
#define FPDSKFError_OpenApplication 0x0005
// password error
#define FPDSKFError_VerifyPIN 0x0006
// Unable to open to Application , password error
#define FPDSKFError_OpenContainer 0x0007
// Unable to get cert , password error or the set driver may be wrong
#define FPDSKFError_ExportCertificate 0x0008
// Unable to  , the set driver may be wrong
#define FPDSKFError_NoFindCert 0x000D
// Unable to match certificate , the set driver may be wrong
#define FPDSKFError_DeriverLoadError 0x000E
// Unable to get Private key, the set driver may be wrong
#define FPDSKFError_CannotGetPriKey 0x000F
#define FPDSKFError_Cancel    0x0010
#define FPDSKFError_SetDriver 0x0011
/*@}*/

/* @DEFGROUPEND */

#ifndef FPD_ENGINE
#define	FPD_ENGINE
/**
* @brief  GMSKF engine.
*
*/
/** @deprecated Internal use. */
typedef struct _t_FPD_Engine* FPD_Engine;
#endif

enum FPD_EngineType
{
	FPD_ENGINE_SKF = 0,
	FPD_ENGINE_PKCS11
};

/* @CALLBACKGROUPSTART */
#ifndef FPD_ENGINENOTIFYCALLBACK
#define FPD_ENGINENOTIFYCALLBACK
typedef struct _fpd_EngineNoify_callbacks_
{
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOLEAN(*FPDGetPinPassWord)(FS_LPVOID clientData, FS_LPVOID token, FS_ByteString* password, FS_DWORD* nerrorcount);
	FS_BOOLEAN(*FPDErrorTip)(FS_LPVOID clientData, FS_INT32 nTip, FS_BOOLEAN bInitSKF);
}FPD_EngineNoifyCallBackRec, *FPD_EngineNoifyCallBack;
#endif
/* @CALLBACKGROUPEND */
/* @OBJEND */

/* @OBJSTART FPD_EngineNotify */
#ifndef FPD_ENGINENOTIFY
#define	FPD_ENGINENOTIFY
/**
* @brief  GMSKF engine.
*
*/
/** @deprecated Internal use. */
typedef struct _t_FPD_EngineNotify* FPD_EngineNotify;
#endif
/* @OBJEND */

/* @OBJSTART FPD_EngineLIBINFO */
#ifndef FPD_ENGINELIBINFO
#define	FPD_ENGINELIBINFO
/**
* @brief  LIBINFO
*
*/
/** @deprecated Internal use. */
typedef struct _t_FPD_EngineLIBINFO* FPD_EngineLIBINFO;
#endif
/* @OBJEND */

/* @OBJSTART FPD_EngineTokenINFO */
#ifndef FPD_ENGINETOKENINFO
#define	FPD_ENGINETOKENINFO
/**
* @brief  LIBINFO
*
*/
/** @deprecated Internal use. */
typedef struct _t_FPD_EngineTokenINFO* FPD_EngineTokenINFO;
#endif
/* @OBJEND */


/* @OBJSTART FPD_FlattenOptions */
#ifndef FPD_FLATTENOPTIONS
#define	FPD_FLATTENOPTIONS
/**
* @brief  Flatten options.
*
*/
typedef struct _t_FPD_FlattenOptions* FPD_FlattenOptions;
#endif

enum FPD_FlattenCompression
{
	FPD_CCITTG3,
	FPD_CCITTG4,
	FPD_ZIP,
	FPD_RunLength,
	FPD_JPEG,
	FPD_JPEG2000
};
enum FPD_FlattenQuality
{
	FPD_Minimum,
	FPD_Low,
	FPD_Medium,
	FPD_Hight,
	FPD_Maximum
};
/* @OBJEND */

/* @OBJSTART FPD_DateTime */
#ifndef FPD_DATETIME
#define	FPD_DATETIME
/**
* @brief  PDF CPDF_DateTime class, to parse  FXCRT_DATETIMEZONE.
*
*/
typedef struct _t_FPD_DateTime* FPD_DateTime;
#endif
/* @OBJEND */

/* @OBJSTART FPD_OrganizeParam */
#ifndef FPD_ORGANIZEPARAM
#define	FPD_ORGANIZEPARAM
/**
* @brief  The organizer param.
*/
typedef struct _t_FPD_OrganizeParam* FPD_OrganizeParam;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Organize */
#ifndef FPD_ORGANIZE
#define	FPD_ORGANIZE
/**
* @brief  The default implementation of PDF progressive organizer.
*/
typedef struct _t_FPD_Organize* FPD_Organize;
#endif

/* @DEFGROUPSTART insert options */
/**
* @brief Definitions insert option.
*/
/** Whether insert the attachments when insert a new pdf file. */
#define FPDINSERT_OPTION_ATTACHMENTS				0x0001
/** Whether insert the ineserted pdf file bookmark. */
#define FPDINSERT_OPTION_BOOKMARK					0x0002
/** brief Do not insert annots of ineserted pdf file, this flag doesn't set in default */
#define FPDINSERT_OPTION_NOANNOT                    0x0004
/** brief Do not insert acroform of ineserted pdf file, this flag doesn't set in default */
#define FPDINSERT_OPTION_NOACROFORM                 0x0008
/** brief Do not delete acroform of pdf file, this flag doesn't set in default */
#define FPDDELETE_OPTION_NOACROFORM                 0x0001
/** brief Do not delete annotaction of pdf file, this flag doesn't set in default */
#define FPDDELETE_OPTION_NOANNOTACTION              0x0002
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_FormExportHandler */
#ifndef FPD_FORMEXPORTHANDLER
#define	FPD_FORMEXPORTHANDLER
/**
* @brief  Form export handler.
*/
typedef struct _t_FPD_FormExportHandler* FPD_FormExportHandler;
#endif

/* @CALLBACKGROUPSTART */
#ifndef FPD_FORMEXPORTCALLBACK
#define FPD_FORMEXPORTCALLBACK
typedef struct _fpd_FormExport_callbacks_
{
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	FS_BOOLEAN(*FPDGetPinPassWord)(FS_LPVOID clientData, FS_ByteString* password, FS_DWORD* nerrorcount);
	FS_BOOLEAN(*FPDErrorTip)(FS_LPVOID clientData, FS_INT32 nTip, FS_BOOLEAN bInitSKF);

	void(*FPDFormExportInitialize)(FS_LPVOID clientData, const FPD_InterForm pInterform);
	FS_FileReadHandler(*FPDFormExportRetrieveEmbeddedFile)(FS_LPVOID clientData, FPD_FormField pField);
	void(*FPDFormExportFinalize)(FS_LPVOID clientData, const FPD_InterForm pInterform);
}FPD_FormExportCallBacksRec, *FPD_FormExportCallBacks;
#endif
/* @CALLBACKGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_Extracter */
#ifndef FPD_EXTRACTER
#define	FPD_EXTRACTER
/**
* @brief  The default implementation of PDF progressive merger.
*/
typedef struct _t_FPD_Extracter* FPD_Extracter;
#endif

enum FPD_EXTRACT_STATE
{
	/** @brief The state of success. */
	FPD_EXTRACT_ERROR = 0,
	/** @brief The state of success. */
	FPD_EXTRACT_SUCCESS,
	/** @brief Invalid password. Please input again. */
	FPD_EXTRACT_PASSWORD,
	/** @brief This document is encrypted by digital certificate and current user doesn't have correct certificate. */
	FPD_EXTRACT_CERT,
	/** @brief The state of access error. */
	FPD_EXTRACT_ACCESS,
	/** @brief The state of the certification signature occurs. Certified documents cannot be extracted. */
	FPD_EXTRACT_SIGNATURE_CERTIFY
};

/* @DEFGROUPSTART Extract option */
/**
* @brief Definitions extract option.
*/
/*@{*/
/** Whether output the annot. */
#define FPDEXTRACT_OPTION_ANNOT				0x0001
/** Whether output the structure tree. */
#define FPDEXTRACT_OPTION_STRUCTRUETREE		0x0002
/** Whether output the Javascript. */
#define FPDEXTRACT_OPTION_JAVASCRIPT		0x0004
/** Whether output the OCProperties. */
#define FPDEXTRACT_OPTION_OCPROPERTIES		0x0008
/** Whether use object streams to reduce result file size. */
#define FPDEXTRACT_OPTION_OBJECTSTREAM		0x0010
/** Whether extract attach file included in the pdf file*/
#define FPDEXTRACT_OPTION_ATTACHFILES		0x0020
/** Whether extract outline included in the pdf file ，it is used by VBA*/
#define FPDEXTRACT_OPTION_OUTLINE			0x0040
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */


/* @OBJSTART FPD_StructNamespace */
#ifndef FPD_STRUCTNAMESPACE
#define	FPD_STRUCTNAMESPACE
/**
* @brief  
*/
typedef struct _t_FPD_StructNamespace* FPD_StructNamespace;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Repair */
#ifndef FPD_REPAIR
#define	FPD_REPAIR
/**
* @brief
*/
typedef struct _t_FPD_Repair* FPD_Repair;
#endif

#define ERROR_CODE(bit) 1 << bit
enum
{
	FPD_REPAIR_SUCCESS = ERROR_CODE(0),
	FPD_REPAIR_NO_OBJ = ERROR_CODE(1),
	FPD_REPAIR_ARGUMENT_ERR = ERROR_CODE(2),
	FPD_REPAIR_LOST_ENDOBJ = ERROR_CODE(3),
	FPD_REPAIR_LOST_PAGE = ERROR_CODE(4),
	FPD_REPAIR_LOST_PAGES = ERROR_CODE(5),
	FPD_REPAIR_LOST_CATALOG = ERROR_CODE(6),
	FPD_REPAIR_LOST_VERSION = ERROR_CODE(7),
	FPD_REPAIR_LOST_XREF = ERROR_CODE(8),
	FPD_REPAIR_PATH_DONT_EXIST = ERROR_CODE(9)
};
/* @OBJEND */

/* @OBJSTART _FPD_BookmarkTree */
#ifndef FPD_BOOKMARKTREE
#define	FPD_BOOKMARKTREE
/**
* @brief
*/
typedef struct _t_FPD_BookmarkTree* FPD_BookmarkTree;
#endif
/* @OBJEND */


#ifdef __cplusplus
};
#endif

#endif
/*@}*/ 


/*@}*/
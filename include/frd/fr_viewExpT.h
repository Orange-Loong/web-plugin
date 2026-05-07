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

/** @file fr_viewExpT.h.
 * 
 *  @brief .
 */

/**
 * @addtogroup FRVIEW
 * @{
 */
#ifndef FR_VIEWEXPT_H
#define FR_VIEWEXPT_H

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../pdf/fpd_docExpT.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "../pdf/fpd_pageExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/*  FR_Page */
#ifndef FR_PAGE
#define FR_PAGE
/**
 * @brief
 * see FPDPage
 */
 /** @deprecated Internal use. */
	typedef struct _t_FR_Page* FR_Page;
#endif
/* FR_Page */

/* @OBJSTART FR_DocView */
#ifndef FR_DOCVIEW
#define FR_DOCVIEW
/**
* @brief A <a>FR_DocView</a> is the area of the Foxit Reader window that displays the contents of a document page. Every 
* <a>FR_DocView</a> may have more than one <a>FR_PageView</a>. It contains references to the <a>FPD_Document</a> 
* for the document being displayed. <br>
*
* <a>FR_DocView</a> has methods to display a page, select a zoom factor, scroll the page displayed inside, 
* control screen redrawing, and traverse the history stack that records where users have been in a document.<br>
* To get a <a>FR_PageView</a> which displayed in a <a>FR_DocView</a>, using <a>FRDocViewGetPageView</a> and 
* <a>FRDocViewGetPageViewAtPoint</a>.
*/
typedef struct _t_FR_DocView* FR_DocView;
#endif

/* @ENUMSTART */
/**
 * @brief A structure that defines the layout of a document. See <a>FRDocViewGetLayoutMode</a>.
 */
enum FRDOCVIEW_LAYOUTMODE
{
    FR_LAYOUTMODE_SINGLE = 0,			/**< Using single page mode. */

    FR_LAYOUTMODE_CONTINUOUS,			/**< Using one-column continue mode. */

    FR_LAYOUTMODE_FACING,				/**< Using facing mode. */

    FR_LAYOUTMODE_CONTINUOUS_FACING,	/**< Using facing continue mode. */

	FR_LAYOUTMODE_AUTOMATIC             /**< Using auto mode. */
};
/* @ENUMEND */

/* @ENUMSTART */
/**
 * @brief Constants that specify the zoom strategy that Foxit Reader is to follow. See <a>FRDocViewGetZoomType</a>.
 */
enum FRDOCVIEW_ZOOMTYPE
{
    FR_ZOOM_MODE_NONE = 0,				/**< None zoom type. */

    FR_ZOOM_MODE_ACTUAL_SCALE,			/**< No variable zoom (the zoom is a fixed value such as 1.0 for 100%). */

    FR_ZOOM_MODE_ACTUAL_SIZE,			/**< Actual size. */

    FR_ZOOM_MODE_FIT_PAGE,				/**< To keep entire page visible. */

    FR_ZOOM_MODE_FIT_WIDTH,				/**< Fits the page width to the window. */

    FR_ZOOM_MODE_FIT_HEIGHT,			/**< Fits the page height to the window. */

    FR_ZOOM_MODE_FIT_RECTANGLE,			/**< Fits rectangle. */

    FR_ZOOM_MODE_FIT_VISIBLE,			/**< Fits visible. */

    FR_ZOOM_MODE_AUTOMATIC				/**< Automatic. */

};
/* @ENUMEND */

/* @DEFGROUPSTART FR_RotationFlags */
/**
 * @brief The rotation flag for document view. See <a>FRDocViewGetRotation</a>.
 */
/*@{*/
/** @brief 0 degree (clockwise). */
#define  FR_ROTATE_POS_TOP           0

/** @brief 90 degree (clockwise). */
#define  FR_ROTATE_POS_RIGHT         1

/** @brief 270 degree (clockwise). */
#define  FR_ROTATE_POS_BOTTOM        2

/** @brief 180 degree (clockwise). */
#define  FR_ROTATE_POS_LEFT          3

/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FR_PageView */
#ifndef FR_PAGEVIEW
#define FR_PAGEVIEW
/**
 * @brief A <a>FR_PageView</a> is a view of a <a>FPD_Page</a> object. 
 * The page view is a part(always a rectangle area) of document view.
 *
 * A <a>FR_PageView</a> must associated with a <a>FPD_Page</a>, but a <a>FPD_Page</a> has more than one <a>FR_PageView</a> some times.
 * <a>FR_PageView</a> has methods to deal with annotations, transform coordinates, control screen redrawing.
 */
typedef struct _t_FR_PageView* FR_PageView;
#endif

/* @DEFGROUPSTART FR_PDFZOOMTYPE */
/**
 * @brief Zoom mode for PDF destination..
 */
/*@{*/
/**
 * @brief left, top, zoom. with the coordinates (left, top) positioned at
 * the upper-left corner of the window and the contents of the page
 * magnified by the factor zoom.
 */
#define FR_PDFZOOM_XYZ					1

/**
 * @brief With its contents magnified just enough to fit the entire page
 * within the window both horizontally and vertically.
 */
#define FR_PDFZOOM_FITPAGE				2

/**
 * @brief top. with the vertical coordinate top positioned at the top edge
 * of the window and the contents of the page magnified just enough to fit
 * the entire width of the page within the window.
 */
#define FR_PDFZOOM_FITHORZ				3

/**
 * @brief left. with the horizontal coordinate left positioned at the left edge
 * of the window and the contents of the page magnified just enough to fit the
 * entire height of the page within the window.
 */
#define FR_PDFZOOM_FITVERT				4

/**
 * @brief left, bottom, right, top. with its contents magnified just enough
 * to fit the rectangle specified by the coordinates left, bottom, right, and top
 * entirely within the window both horizontally and vertically.
 */
#define FR_PDFZOOM_FITRECT				5

/**
 * @brief with its contents magnified just enough to fit its bounding box entirely
 * within the window both horizontally and vertically.
 */
#define FR_PDFZOOM_FITBBOX				6

/**
 * @brief with the vertical coordinate top positioned at the top edge of
 * the window and the contents of the page magnified just enough to fit
 * the entire width of its bounding box within the window
 */
#define FR_PDFZOOM_FITBHORZ			7

 /**
  * @brief with the horizontal coordinate left positioned at the left edge
  * of the window and the contents of the page magnified just enough to fit the entire
  * height of its bounding box within the window.
  */
#define FR_PDFZOOM_FITBVERT			8
/*@}*/
/* @DEFGROUPEND */

/* @STRUCTSTART FR_WinPort */
/**
 * @brief A data structure for <Italic>Machine Port</Italic>. See <a>FRDocViewGetMachinePort</a>. See <a>FRDocViewReleaseMachinePort</a>.
 */
typedef struct _fr_winport_
{
    /** Handle to a window. */
    FS_HWND         hWnd;
    /** Handle to a device context. */
    FS_HDC          hDC;
}FR_WinPortRec, *FR_WinPort;
/* @STRUCTEND */

/* @ENUMSTART */
/**
  * @brief The content change type. See <a>FRPageViewDidContentChanged3</a>.
  */
enum FR_ContentChangeType
{
    FR_ContentChangeType_None = 0,  /**< None Content Obj Operator Type. */

    FR_ContentChangeType_Add,       /**< Add Content Obj Operator Type. */

    FR_ContentChangeType_Delete,    /**< Delete Content Obj Operator Type. */

    FR_ContentChangeType_Modify     /**< Modify Content Obj Operator Type. */
};
/* @ENUMEND */

/* @OBJEND */

/* @OBJSTART FR_TextSelectTool */
#ifndef FR_TEXTSELECTTOOL
#define FR_TEXTSELECTTOOL
/**
 * @brief The text select tool is used to process the operation of text selecting in the doc view.
 */
typedef struct _t_FR_TextSelectTool* FR_TextSelectTool;
#endif

/* @STRUCTSTART FS_SELECTEDTEXT_INFO */
/**
 * @brief  The infomation of the selected text. See <a>FRTextSelectToolGetSelectedTextInfo</a> and <a>FRTextSelectToolReleaseSelectedInfo</a>.
 */
typedef struct __fs_selsected_text_info__
{
    /** select text in the page. */
    FS_WideString wsText;
    /** page index of the select text. */
    FS_INT32 nPageIndex;

    __fs_selsected_text_info__()
    {
        wsText = NULL;
        nPageIndex = -1;
    }
}FS_SELECTEDTEXT_INFO, *PFS_SELECTEDTEXT_INFO;
/* @STRUCTEND */

/* @STRUCTSTART FS_SelectPos */
/**
  * @brief The select text start position and end position in the text select tool. See <a>FRTextSelectToolAddSelectTextRectsWithPages</a>.
  */
typedef struct _fs_selectpos_
{
    /** the start positon of the select text. */
    FS_INT32 startIndex;
    /** the end positon of the select text. */
    FS_INT32 endIndex;
}FS_SelectPos, *PFS_SelectPos;
/* @STRUCTEND */

/* @STRUCTSTART FR_RECTPOINTINFO */
/**
  * @brief .
  */
typedef struct _fr_rectpointinfo_
{
	FS_FLOAT					x1;
	FS_FLOAT                    y1;
	FS_FLOAT					x2;
	FS_FLOAT                    y2;
	FS_FLOAT					x3;
	FS_FLOAT                    y3;
	FS_FLOAT					x4;
	FS_FLOAT                    y4;
}FR_RECTPOINTINFO, *PFR_RECTPOINTINFO;
/* @STRUCTEND */

/* @STRUCTSTART FR_HighLightPageTextPos */
/**
  * @brief .
  */
typedef struct _fr_highlightpagetextpos_
{
	FS_INT32  pageIndex;
	FS_Int32Array arrStartPos;
	FS_Int32Array arrEndPos;	

	_fr_highlightpagetextpos_()
	{
		pageIndex = -1;
		arrStartPos = NULL;
		arrEndPos = NULL;
	}
}FR_HighLightPageTextPos, *PFR_HighLightPageTextPos;
/* @STRUCTEND */


/* @CALLBACKSTART FRSelectTextProgressProc */
/**
 * @brief The callback will be invoked when select text,you can control the progress.
 * @param[in] pUIProgress	The UI progress.
 * @return FS_BOOL
 * @note
 */
typedef FS_BOOL(*FRSelectTextProgressProc)(FS_LPVOID pUIProgress);
/* @CALLBACKEND */

/* @OBJEND */

/* @OBJSTART FR_ThumbnailView */
#ifndef FR_THUMBNAILVIEW
#define FR_THUMBNAILVIEW
/**
 * @brief a thumbnail view related to the document view. It displays the thumbnail of
 * the document in the page panel.
 *
 */
typedef struct _t_FR_ThumbnailView* FR_ThumbnailView;
#endif
/* @OBJEND */

/* FR_ScrollBarThumbnailView */
#ifndef FR_SCROLLBARTHUMBNAILVIEW
#define FR_SCROLLBARTHUMBNAILVIEW
/**
 * @brief a scrollbar thumbnail view related to the document page view. It displays the scrollbar thumbnail of
 * the document page view in the page panel.
*/
typedef struct _t_FR_ScrollBarThumbnailView* FR_ScrollBarThumbnailView;
#endif

/* @OBJSTART FR_Annot */
#ifndef FR_ANNOT
#define FR_ANNOT
/**
 * @brief The UI layer annotation object.
 */
typedef struct _t_FR_Annot* FR_Annot;
#endif

/* @CALLBACKGROUPSTART FR_AnnotCallbacks */
/**
* @brief A callback when get property from FR_Annot.
*/
typedef struct _frd_Annot_callbacks_
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;
	
	void(*FRReleaseClientData)(FS_LPVOID clientData);	
	void(*FRGetDataType)(FS_LPVOID clientData, FS_ByteString* outType);
	void(*FRGetType)(FS_LPVOID clientData, FS_ByteString* outType);
	void(*FRGetSubType)(FS_LPVOID clientData, FS_ByteString* outSubType);
	FS_BOOLEAN(*FRIsSameTabOrder)(FS_LPVOID clientData, FR_Annot pAnnot);
	FS_INT32(*FRGetLayoutOrder)(FS_LPVOID clientData);
	void(*FRSetLayoutOrder)(FS_LPVOID clientData, FS_INT32 nOrder);
	void(*FRSetAuthor)(FS_LPVOID clientData, FS_LPCWSTR cwAuthor);
	FS_BOOLEAN(*FRDrawAppearance)(FS_LPVOID clientData, FPD_RenderDevice pDevice, FS_AffineMatrix pUser2Device,
		FPD_AnnotAppearanceMode mode, const FPD_RenderOptions pOptions);
}FR_AnnotCallbacksRec, *FR_AnnotCallbacks;
/* @CALLBACKGROUPEND */

/* @OBJEND */

/* FR_Document */
#ifndef FR_DOCUMENT
#define FR_DOCUMENT
/**
 * @brief A <a>FR_Document</a> is a view of a PDF document in a window.<br>
 *
 * Usually there is one <a>FR_Document</a> per displayed document, but some times(such as New Window),
 * there may be two or more <a>FR_Document</a> per displayed document.
 * Unlike a <a>FPD_Document</a>, an <a>FR_Document</a> has a window associated with it. And a <a>FPD_Document</a>
 * may have one or more associated <a>FR_Document</a>.<br>
 *
 */
typedef struct _t_FR_Document* FR_Document;
#endif

/*  FR_ResourcePropertySource */
#ifndef FR_RESOURCEPROPERTYSOURCE
#define FR_RESOURCEPROPERTYSOURCE
/**
 * @brief The property source of the property box.
 */
typedef struct _t_FR_ResourcePropertySource* FR_ResourcePropertySource;
#endif

/* @OBJSTART FR_ResourcePropertyPage */
#ifndef FR_RESOURCEPROPERTYPAGE
#define FR_RESOURCEPROPERTYPAGE
/**
 * @brief The property page of the property box.
 */
typedef struct _t_FR_ResourcePropertyPage* FR_ResourcePropertyPage;
#endif
/* @OBJEND */

/*  FR_ResourcePropertyBox */
#ifndef FR_RESOURCEPROPERTYBOX
#define FR_RESOURCEPROPERTYBOX
/**
 * @brief The property box is used to edit the properties of objects, such as the annotations, the pages and so on.
 * The Foxit Reader creates the property box so that many types of objects can reuse the same property box to edit the properties.
 */
typedef struct _t_FR_ResourcePropertyBox* FR_ResourcePropertyBox;
#endif

/* @DEFGROUPSTART FRSOURCETYPE */
/**
 * @brief The source type definitions.
 */
/** @deprecated Internal use */
/*@{*/
/** @brief Unknown type. */
#define FR_SOURCE_TYPE_UNKNOWN		   -1
/** @brief The source type is annotation. */
#define FR_SOURCE_TYPE_ANNOTS			0
/** @brief The source type is bookmark. */
#define FR_SOURCE_TYPE_BOOKMARK			1
/** @brief The source type is page. */
#define FR_SOURCE_TYPE_PAGE				2
/** @brief The source type is page objects. */
#define FR_SOURCE_TYPE_PAGEOBJECTS		3
/** @brief The source type is user. */
#define FR_SOURCE_TYPE_USER				4
/** @brief The source type is tag. */
#define FR_SOURCE_TYPE_TAG				5
/** @brief The source type is multibookmark. */
#define FR_SOURCE_TYPE_MULTIBOOKMARK	6
/*@}*/
/* @DEFGROUPEND */

/* @CALLBACKGROUPSTART FR_ResourcePropertyNotifyCallbacks */
/**
 * @brief The callback set for property box. The callbacks are called by Foxit Reader when the events occur.
 */
/** @deprecated Internal use */
typedef struct _fr_resourceproperty_notify_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ResourcePropertyNotifyCallbacksRec</a>). */
    unsigned long	lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRResourcePropertyNotifyOnLockObjects */
    /**
     * @brief	It is called by foxit reader when the user clicks the check box to lock the source.
     * @param[in] clientData	The user-supplied data.
     * @param[in] bLocked		Indicates whether to lock the source or not.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     * @see FRResourcePropertyBoxRegisterSourceType
     */
    void (*FRResourcePropertyNotifyOnLockObjects)(FS_LPVOID clientData, FS_BOOL bLocked);
    /* @CALLBACKEND */

}FR_ResourcePropertyNotifyCallbacksRec, *FR_ResourcePropertyNotifyCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_ResourcePropertySourceCallbacks */
/**
 * @brief Provided callbacks to enable title change from property page.
 */
 /** @deprecated Internal use */
typedef struct _fr_PropertySourceCallbacks
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ResourcePropertyPageCallbacksRec</a>). */
	unsigned long	lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRGetPropertyBoxTitle */
	/**
	 * @brief	It is called by foxit reader to get title from the plug-in.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] pObjectType	The specified object type.
	 * @return FS_LPWSTR        Get the property title.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
	 */
	FS_LPWSTR(*FRGetPropertyBoxTitle)(FS_LPVOID clientData, const char* pObjectType);
	/* @CALLBACKEND */
}FR_PropertySourceCallbacksRec, *FR_PropertySourceCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_ResourcePropertySourceCallbacks */
/**
 * @brief The callback set for property source. The callbacks are called by Foxit Reader to deal with the source of the property box.
 * See <a>FRResourcePropertyBoxRegisterSourceType</a>.
 */
/** @deprecated Internal use */
typedef struct _fr_resourceproperty_source_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ResourcePropertySourceCallbacksRec</a>). */
    unsigned long	lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRResourcePropertySourceGetFRDocument */
    /**
     * @brief	It is called by foxit reader to get the <a>FR_Document</a> object.
     * @param[in] clientData	The user-supplied data.
     * @return The <a>FR_Document</a> object.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FR_Document (*FRResourcePropertySourceGetFRDocument)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertySourceCountSelectObjects */
    /**
     * @brief	It is called by foxit reader to get the cout of the selected objects.
     * @param[in] clientData	The user-supplied data.
     * @return The cout of the selected objects.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_INT32 (*FRResourcePropertySourceCountSelectObjects)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertySourceGetSelectObject */
    /**
     * @brief	It is called by foxit reader to get the selected object by index.
     * @param[in] clientData	The user-supplied data.
     * @param[in] index			The specified index.
     * @return The selected object.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void* (*FRResourcePropertySourceGetSelectObject)(FS_LPVOID clientData, FS_INT32 index);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertySourceGetSelectObjectType */
    /**
     * @brief	It is called by foxit reader to get the types of the selected objects.
     * @param[in] clientData	The user-supplied data.
     * @param[out] outArray		It receives the types.
     * @return The returned value is reserved.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_INT32 (*FRResourcePropertySourceGetSelectObjectType)(FS_LPVOID clientData, FS_ByteStringArray outArray);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertySourceIsLockedObjectExisted */
    /**
     * @brief	It is called by foxit reader to check whether the locked object exists.
     * @param[in] clientData	The user-supplied data.
     * @return <a>TRUE</a> if the locked object exists, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRResourcePropertySourceIsLockedObjectExisted)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertySourceIsDisabledObjectExisted */
    /**
     * @brief	It is called by foxit reader to check whether the disabled object exists.
     * @param[in] clientData	The user-supplied data.
     * @return <a>TRUE</a> if the disabled object exists, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRResourcePropertySourceIsDisabledObjectExisted)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertySourceIsPropertyBoxEnabled */
    /**
     * @brief	It is called by foxit reader to check whether the property box is enabled.
     * @param[in] clientData	The user-supplied data.
     * @param[in] lpsObjectType	The specified object type.
     * @return <a>TRUE</a> if the property box is enabled, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRResourcePropertySourceIsPropertyBoxEnabled)(FS_LPVOID clientData, FS_LPCSTR lpsObjectType);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertySourceGetPropertyBoxTitle */
    /**
     * @brief	It is called by foxit reader to get the title of the property box.
     * @param[in] clientData	The user-supplied data.
     * @param[in] lpsObjectType	The specified object type.
     * @param[out] outTitle		It receives the title of the property box.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRResourcePropertySourceGetPropertyBoxTitle)(FS_LPVOID clientData, FS_LPCSTR lpsObjectType, FS_WideString outTitle);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertySourceCanExistedSetDefaultButton */
    /**
     * @brief	It is called by foxit reader to determine whether to show the check box to set current properties as default.
     * @param[in] clientData	The user-supplied data.
     * @return <a>TRUE</a> if the check box is to be shown, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRResourcePropertySourceCanExistedSetDefaultButton)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertySourceOnBoxClose */
    /**
     * @brief	It is called by foxit reader when the property box is closed.
     * @param[in] clientData		The user-supplied data.
     * @param[in] nType				The source type.
     * @param[in] bSetDefaultButton	Whether the check box is checked or not.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRResourcePropertySourceOnBoxClose)(FS_LPVOID clientData, FS_INT32 nType, FS_INT32 bSetDefaultButton);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertySourceSetCallback */
	/**
	 * @brief	It is called by foxit reader when the property box is closed.
	 * @param[in] clientData		The user-supplied data.
	 * @param[in] callback			The input FR_PropertySourceCallbacksRec callback.	 
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.0
	 */
	void(*FRResourcePropertySourceSetCallback)(FS_LPVOID clientData, FR_PropertySourceCallbacksRec callback);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertySourceGetLockTypeObject */
	/**
	 * @brief	It is called by foxit reader when the property box is closed.
	 * @param[in] clientData		The user-supplied data.	
	 * @return void
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 13.0
	 */
	FS_INT32(*FRResourcePropertySourceGetLockTypeObject)(FS_LPVOID clientData);
	/* @CALLBACKEND */

}FR_ResourcePropertySourceCallbacksRec, *FR_ResourcePropertySourceCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_ResourcePropertyPageCallbacks */
/**
 * @brief The callback set for property page. The callbacks are called by Foxit Reader to add new property page to the property box.
 * You can register the callbacks through <a>FRResourcePropertyBoxRegisterPropertyPage</a>.
 */
/** @deprecated Internal use */
typedef struct _fr_resourceproperty_page_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ResourcePropertyPageCallbacksRec</a>). */
    unsigned long	lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FRResourcePropertyPageSetPropertyBox */
    /**
     * @brief	It is called by foxit reader to pass the property box to the plug-in.
     * @param[in] clientData		The user-supplied data.
     * @param[in] pPropertyBox		The property box.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRResourcePropertyPageSetPropertyBox)(FS_LPVOID clientData, FR_ResourcePropertyBox pPropertyBox);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertyPageGetPageTitle */
    /**
     * @brief	It is called by foxit reader to get the title of the property page.
     * @param[in] clientData		The user-supplied data.
     * @param[out] outTitle			It receives the title of the property page.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRResourcePropertyPageGetPageTitle)(FS_LPVOID clientData, FS_WideString outTitle);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertyPageGetPageName */
    /**
     * @brief	It is called by foxit reader to get the name of the property page.
     * @param[in] clientData		The user-supplied data.
     * @param[out] outName			It receives the name of the property page.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRResourcePropertyPageGetPageName)(FS_LPVOID clientData, FS_WideString outName);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertyPageGetSequenceNumber */
    /**
     * @brief	It is called by foxit reader to get the sequence number of the property page.
     * @param[in] clientData		The user-supplied data.
     * @return The sequence number of the property page.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_INT32 (*FRResourcePropertyPageGetSequenceNumber)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertyPageIsSourceSupported */
    /**
     * @brief	It is called by foxit reader to check whether the source is supported.
     * @param[in] clientData		The user-supplied data.
     * @param[in] nSource			The source type.
     * @param[in] pSourceFunc		The property source.
     * @return <a>TRUE</a> if the souce is supported, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRResourcePropertyPageIsSourceSupported)(FS_LPVOID clientData, FS_INT32 nSource, FR_ResourcePropertySource pSourceFunc);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertyPageUpdatePage */
    /**
     * @brief	It is called by foxit reader to notify the plug-in to update the property page.
     * @param[in] clientData The user-supplied data.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRResourcePropertyPageUpdatePage)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertyPageGetPageHWnd */
    /**
     * @brief	It is called by foxit reader to get the window handle of the property page.
     * @param[in] clientData The user-supplied data.
     * @return The window handle of the property page.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_HWND (*FRResourcePropertyPageGetPageHWnd)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertyPageGetPageSize */
    /**
     * @brief	It is called by foxit reader to get the size of the property page.
     * @param[in] clientData	The user-supplied data.
     * @param[out] outCX		It receives the width of the property page.
     * @param[out] outCY		It receives the height of the property page.
     * @return <a>TRUE</a> for success, otherwise the property page will use the default size.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRResourcePropertyPageGetPageSize)(FS_LPVOID clientData, FS_INT32* outCX, FS_INT32* outCY);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertyPageCreatePage */
    /**
     * @brief	It is called by foxit reader to notify the plug-in to create the property page.
     * @param[in] clientData	The user-supplied data.
     * @param[] hParent			The parent window handle.
     * @return <a>TRUE</a> for success, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRResourcePropertyPageCreatePage)(FS_LPVOID clientData, FS_HWND hParent);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertyPageOnDeactive */
    /**
     * @brief	It is called by foxit reader to notify the plug-in to deactivate the property page.
     * @param[in] clientData	The user-supplied data.
     * @return <a>TRUE</a> for success, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    FS_BOOL (*FRResourcePropertyPageOnDeactive)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRResourcePropertyPageOnLangUIChange */
    /**
     * @brief	It is called by foxit reader to notify the plug-in to change the language of the property page.
     * @param[in] clientData	The user-supplied data.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
    void (*FRResourcePropertyPageOnLangUIChange)(FS_LPVOID clientData);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertyPageIsHiddenOtherPorpertyPage */
	/**
	 * @brief	It is called by foxit reader to check the plug-in if need to hide the specified page of input pagename.
	 * @param[in] clientData	The user-supplied data.
	 * @param[in] wsPageName	The page name to check if it's need to be hide.
	 * @return FS_BOOL          TRUE is hide.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
	 */
	FS_BOOL(*FRResourcePropertyPageIsHiddenOtherPorpertyPage)(FS_LPVOID clientData, FS_WideString wsPageName);
	/* @CALLBACKEND */
}FR_ResourcePropertyPageCallbacksRec, *FR_ResourcePropertyPageCallbacks;
/* @CALLBACKGROUPEND */

 /* FR_ResourcePropertyBox */

/* FR_IReader_DispViewerHandler */
#ifndef FR_IREADER_DISPVIEWERHANDLER
#define FR_IREADER_DISPVIEWERHANDLER
/**
 * @brief The <a>FR_IReader_DispViewerHandler</a> object represents the event handler of the reader display viewer. The plug-in can register
 * the event handler to process the event when the plug-in creates the reader display viewer. See <a>FRReaderCreateDispViewer</a>.
 */
typedef struct _t_FR_IReader_DispViewerHandler *FR_IReader_DispViewerHandler;
#endif

/* FR_IPDFViewerEventHandler */
#ifndef FR_IPDFVIEWEREVENTHANDLER
#define FR_IPDFVIEWEREVENTHANDLER
/**
 * @brief The <a>FR_IPDFViewerEventHandler</a> object represents the event handler of the PDF document viewer. See <a>FRIPDFViewerEventHandlerNew</a>.
 */
typedef struct _t_FR_IPDFViewerEventHandler *FR_IPDFViewerEventHandler;
#endif

/* @OBJSTART FR_PDFViewerPage */
#ifndef FR_PDFVIEWERPAGE
#define FR_PDFVIEWERPAGE
/**
 * @brief To get page info of pdf viewer.
* @Deprecated: Internal use.
 */
typedef struct _t_FR_PDFViewerPage* FR_PDFViewerPage;
#endif
/* @OBJEND */

/* FR_IReader_DispViewer */
#ifndef FR_IREADER_DISPVIEWER
#define FR_IREADER_DISPVIEWER
/**
 * @brief a displayer view of reader.
 */
typedef struct _t_FR_IReader_DispViewer *FR_IReader_DispViewer;
#endif

/* @STRUCTSTART FPD_IPDFViewerEventHandlerCallbacks */
/**
 * @brief A callback set for the event handler of the PDF document viewer. See <a>FRIPDFViewerEventHandlerNew</a>.
*/
/** @deprecated Internal use.*/
typedef struct _fr_ipdfviewereventhandler_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ResourcePropertyPageCallbacksRec</a>). */
    unsigned long	lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART OnBeforeDraw */
    /**
     * @brief It is called before the PDF document viewer can draw.
     * @param[in] clientData			The user-supplied data.
     * @param[in] pBitmap               The bitmap to draw.
     * @return void.
     * @note
     */
    void(*OnBeforeDraw)(FS_LPVOID clientData, FS_DIBitmap pBitmap);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnAfterDraw */
    /**
     * @brief It is called after the PDF document viewer can draw.
     * @param[in] clientData			The user-supplied data.
     * @param[in] pBitmap               The bitmap to draw.
     * @return void.
     * @note
     */
    void(*OnAfterDraw)(FS_LPVOID clientData, FS_DIBitmap pBitmap);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnDrawBkgnd */
    /**
     * @brief It is called for background rendering in PDF document viewer.
     * @param[in] clientData			The user-supplied data.
     * @param[in] pBitmap               The bitmap to draw.
     * @return void.
     * @note
     */
    void(*OnDrawBkgnd)(FS_LPVOID clientData, FS_DIBitmap pBitmap);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnDrawPageShawdow */
    /**
     * @brief It is called in PDF document viewer page shadow rendering.
     * @param[in] clientData			The user-supplied data.
     * @param[in] pBitmap               The bitmap to draw.
     * @param[in] pPage                 The page view to draw.
     * @return void.
     * @note
     */
    void(*OnDrawPageShawdow)(FS_LPVOID clientData, FS_DIBitmap pBitmap, FR_PDFViewerPage pPage);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnPageVisible */
    /**
     * @brief It is called when the visible state of the PDF document viewer page changes.
     * @param[in] clientData			The user-supplied data.
     * @param[in] pPage                 The page view with status change.
     * @param[in] bVisble               Current visible status.<a>TRUE</a> is visible and <a>FALSE</a> is invisible.
     * @return void.
     * @note
     */
    void(*OnPageVisible)(FS_LPVOID clientData, FR_PDFViewerPage pPage, FS_BOOL bVisble);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnPageIndexChange */
    /**
     * @brief It is called when the index of the current page of the PDF document viewer changes.
     * @param[in] clientData			The user-supplied data.
     * @param[in] pPage                 The current page view.
     * @return void.
     * @note
     */
    void(*OnPageIndexChange)(FS_LPVOID clientData, FR_PDFViewerPage pPage);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnBeginRender */
    /**
     * @brief It is called to the PDF document viewer render begin.
     * @param[in] clientData			The user-supplied data.
     * @return void.
     * @note
     */
    void(*OnBeginRender)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnFinishRender */
    /**
     * @brief It is called to the PDF document viewer render finish.
     * @param[in] clientData			The user-supplied data.
     * @return void.
     * @note
     */
    void(*OnFinishRender)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnRenderDataChange */
    /**
     * @brief It is called when the render data of the PDF document viewer changes.
     * @param[in] clientData			The user-supplied data.
     * @return void.
     * @note
     */
    void(*OnRenderDataChange)(FS_LPVOID clientData);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnZoomPage */
    /**
     * @brief It is called for the PDF document viewer to change page scaling.
     * @param[in] clientData			The user-supplied data.
     * @param[in] nPage                 The changed page index.
     * @return void.
     * @note
     */
    void(*OnZoomPage)(FS_LPVOID clientData, FS_INT32 nPage);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnGotoPage */
    /**
     * @brief It is called when the current page of the PDF document viewer changes.
     * @param[in] clientData			The user-supplied data.
     * @param[in] nPage                 The changed page index.
     * @return void.
     * @note
     */
    void(*OnGotoPage)(FS_LPVOID clientData, FS_INT32 nPage);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnBeforePageDraw */
    /**
     * @brief It is called before the PDF document page can draw.
     * @param[in] clientData			The user-supplied data.
     * @param[in] pPage                 The page view to draw.
     * @param[in] pBitmap               The bitmap to draw.
     * @return void.
     * @note
     */
    void(*OnBeforePageDraw)(FS_LPVOID clientData, FR_PDFViewerPage pPage, FS_DIBitmap pBitmap);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnAfterPageDraw */
    /**
     * @brief It is called after the PDF document page can draw.
     * @param[in] clientData			The user-supplied data.
     * @param[in] pPage                 The page view to draw.
     * @param[in] pBitmap               The bitmap to draw.
     * @return void.
     * @note
     */
    void(*OnAfterPageDraw)(FS_LPVOID clientData, FR_PDFViewerPage pPage, FS_DIBitmap pBitmap);
    /* @CALLBACKEND */

    /* @CALLBACKSTART IsFullScreenLoopPage */
    /**
     * @brief It is called when the state of the full screen looping page of the PDF document viewer changes.
     * @param[in] clientData			The user-supplied data.
     * @return <a>TRUE</a> If the PDF document viewer enter the full screen looping page, otherwist not.
     * @note
     */
    FS_BOOL(*IsFullScreenLoopPage)(FS_LPVOID clientData);
    /* @CALLBACKEND */

}FPD_IPDFViewerEventHandlerCallbacksRec, *FPD_IPDFViewerEventHandlerCallbacks;
/* @STRUCTEND */

/* @STRUCTSTART FR_IReader_DispViewerHandlerCallbacks */
/**
 * @brief A callback set for the event handler of the reader display viewer. See <a>FRIReaderDispViewerHandlerNew</a>.
 */
/** @deprecated Internal use.*/
typedef struct _fr_ireader_dispviewerhandlercallbackrec_callbacks_
{
    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_IReader_DispViewerHandlerCallbacksRec</a>). */
    unsigned long	lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART OnBeginRender */
    /**
     * @brief It is called to the reader display viewer render begin.
     * @param[in] clientData			The user-supplied data.
     * @param[in] pHandler              The name of format.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 4.1.2
     */
    void(*OnBeginRender)(FS_LPVOID clientData, FR_IPDFViewerEventHandler pHandler);
    /* @CALLBACKEND */

    /* @CALLBACKSTART OnFinishRender */
    /**
     * @brief It is called to the reader display viewer render finish.
     * @param[in] clientData			The user-supplied data.
     * @param[in] pHandler              The event handler of the PDF document viewer.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 4.1.2
     */
    void(*OnFinishRender)(FS_LPVOID clientData, FR_IPDFViewerEventHandler pHandler);
    /* @CALLBACKEND */
}FR_IReader_DispViewerHandlerCallbacksRec, *FR_IReader_DispViewerHandlerCallbacks;
/* @STRUCTEND */

/* @OBJSTART FR_ToolFormatMgr */
#ifndef FR_TOOLFORMATMGR
#define FR_TOOLFORMATMGR
/**
 * @brief  The right format tool panel control manager.
 */
typedef struct _t_FR_ToolFormatMgr* FR_ToolFormatMgr;
#endif

/* @STRUCTSTART FR_FormatEventCallbacks */
/**
 * @brief A callback set for the event handler of the right format tool panel. See <a>FRToolFormatMgrRegistFormatEvent</a>.
 */
typedef struct _fr_formatevent_callbacks_
{

    /** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_AppEventCallbacksRec</a>). */
    unsigned long lStructSize;

    /** The user-supplied data. */
    FS_LPVOID		clientData;

    /* @CALLBACKSTART FROnShowFormat */
    /**
     * @brief It is called to the right format tool panel show.
     * @param[in] clientData			The user-supplied data.
     * @param[in] bsFormatName          The name of format.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 4.1.2
     */
    void(*FROnShowFormat)(FS_LPVOID clientData, FS_ByteString bsFormatName);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FROnBeforeShowFormat */
    /**
     * @brief It is called before the right format tool panel show.
     * @param[in] clientData        The user-supplied data.
     * @param[in] bsFormatName      The name of format.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 4.1.2
     */
    void(*FROnBeforeShowFormat)(FS_LPVOID clientData, FS_ByteString bsFormatName);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FRPreTranslateMessage */
    /**
     * @brief The callback is invoked by Foxit Reader to dispatch the message to plug-in.
     * @param[in] clientData        The user-supplied data.
     * @param[in] pMsg              Points to a <Italic>MFC MSG</Italic> structure that contains the message to process.
     * @param[in] hDialog           The dialog for message source.
     * @return <a>TRUE</a> if the message was fully processed in <a>FRPreTranslateMessage</a>
     * and should not be processed further. <a>FALSE</a> if the message should be processed in the normal way.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 4.1.2
     */
    FS_BOOL(*FRPreTranslateMessage)(FS_LPVOID clientData, void* pMsg, FS_HWND hDialog);
    /* @CALLBACKEND */

    /* @CALLBACKSTART FROnUpdateFormatStatus */
    /**
     * @brief Update the right format tool panel button status.
     * @param[in] clientData        The user-supplied data.
     * @param[in] bsFormatName      The name of format.
     * @return void.
     * @note
     * @since <a>SDK_LATEEST_VERSION</a> > 4.1.2
     */
    void(*FROnUpdateFormatStatus)(FS_LPVOID clientData, FS_ByteString bsFormatName);
    /* @CALLBACKEND */

	/* @CALLBACKSTART FROnShowFormat */
	/**
	 * @brief It is called to the right format tool panel show.
	 * @param[in] clientData			The user-supplied data.
	 * @param[in] bsFormatName          The name of format.
	 * @param[in] bMatchsize            Whether need match size.
	 * @return void.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 4.1.2
	 */
	void(*FROnShowFormat2)(FS_LPVOID clientData, FS_ByteString bsFormatName, FS_BOOLEAN bMatchsize);
	/* @CALLBACKEND */
}FR_FormatEventCallbacksRec, *FR_FormatEventCallbacks;
/* @STRUCTEND */

/* @ENUMSTART */
/**
* @name format type.
*/

/*@{*/
enum FR_FormatType
{
	FRNoneFormatType,
	FRCommentFormatType,
	FRMeasureFormatType,
	FREditFormatType,
	FRImageFormatType,
	FRUnknownFormatType,
};
/*@}*/
/* @ENUMEND */

/* @OBJEND */

/* @OBJSTART FR_TextSelectedData */
#ifndef FR_TEXTSELECTEDDATA
#define FR_TEXTSELECTEDDATA
/**
 * @brief  Get the selected data info of all pages.
 */
typedef struct _t_FR_TextSelectedData* FR_TextSelectedData;
#endif

/* @STRUCTSTART FR_SELECTMSG */
/**
 * @brief  The start index and end index of the select data. See <a>FRTextSelectedDataGetSelectedDatas</a>.
 */
typedef struct __fr_selectmsg__
{
    /** the start index of the select data. */
    FS_INT32 nStartIndex;
    /** the end index of the select data. */
    FS_INT32 nEndIndex;
}FR_SELECTMSG;
/* @STRUCTEND */

/* @OBJEND */

/* @OBJSTART FR_LayerOperation */
#ifndef FR_LAYEROPERATION
#define FR_LAYEROPERATION
/**
 * @brief The opreration of layer.
 */
typedef struct _t_FR_LayerOperation* FR_LayerOperation;
#endif

/* @ENUMSTART */
/**
  * @brief The layer import type. See <a>FRLayerOperationImportLayer</a>.
  */
enum FR_ImportType
{
    FR_IMPORT_CREATE,   /**< Create new layer. */
    FR_IMPORT_ADDTO,    /**< Add to already exists. */
    FR_IMPORT_COPY      /**< Copy from source. */
};
/* @ENUMEND */

/* @OBJEND */

/* @OBJSTART FR_FormTextFind */
#ifndef FR_FORMTEXTFIND
#define FR_FORMTEXTFIND
/**
 * @brief To find form text.
 */
typedef struct _t_FR_FormTextFind* FR_FormTextFind;
#endif
/* @OBJEND */

/* @OBJSTART FR_PDFVerwerContentProviderEx */
#ifndef FR_PDFVIEWERCONTENTPROVIDEREX
#define FR_PDFVIEWERCONTENTPROVIDEREX
/**
 * @brief To set content provider in plugin.
 */
typedef struct _t_FR_PDFVerwerContentProviderEx* FR_PDFVerwerContentProviderEx;
#endif
/* @OBJEND */

/* @OBJSTART FR_PDFViewer */
#ifndef FR_PDFVIEWER
#define FR_PDFVIEWER
/**
* @brief  A <a>FR_PDFViewer</a> is used to create view in plugin.
* @Deprecated: Internal use.
*/
typedef struct _t_FR_PDFViewer* FR_PDFViewer;
#endif

/* @STRUCTSTART FR_PDFVerwerContentProviderCallbacks */
/**
 * @brief A callback set for create pdf viewer in plugin.
 * @Deprecated: Internal use.
 */
typedef struct _fr_PDFVerwerContentProvider_callbacks_
{

	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_AppEventCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRGetPDFDocument */
	/**
	 * @brief It is called to get the FPD_Document for plugin.
	 * @param[in] clientData			The user-supplied data.
	 * @return FPD_Document
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	 */
	FPD_Document (*FRGetPDFDocument)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRGetPage */
	/**
	 * @brief It is called to get the FPD_Page for plugin.
	 * @param[in] clientData        The user-supplied data.
	 * @param[in] nPage             The page index.
	 * @return FPD_Page.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 12.0.0.0
	 */
	FPD_Page(*FRGetPage)(FS_LPVOID clientData, FS_INT32 nPage);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRParsePage */
	/**
	 * @brief The callback is to parse specified page.
	 * @param[in] clientData        The user-supplied data.
	 * @param[in] nPage             The page index.
	 * @return FS_BOOLEAN   true: parse success.
	 * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 4.1.2
	 */
	FS_BOOLEAN(*FRParsePage)(FS_LPVOID clientData, FS_INT32 nPage);
	/* @CALLBACKEND */
}FR_PDFVerwerContentProviderCallbacksRec, *FR_PDFVerwerContentProviderCallbacks;
/* @STRUCTEND */

#define FRD_LAYOUT_PREVIEW			0  
#define FRD_LAYOUT_THUMBBAIL		1

#define  FRD_ZMODE_NONE            0
#define  FRD_ZMODE_CUSTOM          1
#define  FRD_ZMODE_ACTUAL_SIZE     2
#define  FRD_ZMODE_FIT_PAGE        3
#define  FRD_ZMODE_FIT_WIDTH       4
#define  FRD_ZMODE_FIT_HEIGHT      5
#define  FRD_ZMODE_FIT_RECTANGLE   6
#define  FRD_ZMODE_FIT_VISIBLE	   7

//browse mode
#define FRD_BRMODE_SINGLE            0  
#define FRD_BRMODE_CONTINUOUS        1
#define FRD_BRMODE_SINGLE_FACING     2
#define FRD_BRMODE_CONTINUOUS_FACING 3
/* @OBJEND */

/* @STRUCTSTART FR_RedactOption */
/**
 * @brief  The redact options.
 */
typedef struct __fr_redactoption__
{
	/** If the current open document. */
	FS_BOOLEAN bCurDoc;
	/** If need show progress bar. */
	FS_BOOLEAN bHasProcess;
	/** If need search redact. */
	FS_BOOLEAN bSearch;
	/** If need save as the file. */
	FS_BOOLEAN bNeedSaveAsNotify;

	__fr_redactoption__()
	{
		bCurDoc = true;
		bHasProcess = true;
		bSearch = false;
		bNeedSaveAsNotify = true;
	}
}FR_RedactOption;
/* @STRUCTEND */

#ifdef __cplusplus
};
#endif

#endif //FR_VIEWEXPT_H
/*@}*/ 

/*@}*/ 

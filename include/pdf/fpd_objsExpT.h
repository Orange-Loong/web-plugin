/*********************************************************************

 Copyright (C) 2024 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_objsExpT.h
		
 - Types, macros, structures, etc. required to use the FPDObj HFT.

*********************************************************************/

/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/

/**
* @addtogroup FPDOBJECT
* @{
 */


#ifndef FPD_OBJSEXPT_H
#define FPD_OBJSEXPT_H

#ifdef __cplusplus
extern "C"{
#endif

/* @OBJSTART FPD_Object */
/* @DEFGROUPSTART FPDObjTypes */
	
/**
 * @name Object types in PDF. Return by FPDObjectGetType() function.
 */
/*@{*/
/** @brief invalid object. */
#define FPD_OBJ_INVALID		0
/** @brief Boolean object. */
#define	FPD_OBJ_BOOLEAN		1
/** @brief Number object. */
#define FPD_OBJ_NUMBER		2
/** @brief String object. */
#define FPD_OBJ_STRING		3
/** @brief Name object. */
#define FPD_OBJ_NAME		4
/** @brief Array object. */
#define FPD_OBJ_ARRAY		5
/** @brief Dictionary object. */
#define FPD_OBJ_DICTIONARY	6
/** @brief Stream object. */
#define FPD_OBJ_STREAM		7
/** @brief Null object. */
#define FPD_OBJ_NULL		8
/** @brief Reference object. */
#define FPD_OBJ_REFERENCE	9

/*@}*/ 
/* @DEFGROUPEND */

#ifndef FPD_OBJECT
#define FPD_OBJECT
/** @brief A <a>FPD_Object</a> is a general object in a PDF file, which may be of any object type.
 * This is the abstract class for all PDF syntax objects.
 *
 * <br>PDF supports eight basic types of objects:<br>
 * <ul>
 * <li>- Boolean values				<a>FPD_Boolean</a></li>
 * <li>- Integer and real numbers	<a>FPD_Number</a></li>
 * <li>- Strings					<a>FPD_String</a></li>
 * <li>- Names						<a>FPD_Name</a></li>
 * <li>- Arrays						<a>FPD_Array</a></li>
 * <li>- Dictionaries				<a>FPD_Dictionary</a></li>
 * <li>- Streams					<a>FPD_Stream</a></li>
 * <li>- The null object			<a>FPD_Null</a></li>
 * </ul>
 *
 * Addtional type of object:	<a>FPD_Reference</a><br>.
 * Objects may be labeled so that they can be referred to by other objects. A labeled 
 * object is called an indirect object.
 * See <a>FPDObjectDestroy</a>, <a>FPDStringNew</a>, <a>FPDStringNewW</a>, <a>FPDNameNew</a>, 
 * <a>FPDBooleanNew</a>, <a>FPDNumberNewByInt</a>, <a>FPDNumberNewByFloat</a>, <a>FPDNumberNewByStr</a>, 
 * <a>FPDNumberNewFromData</a>, <a>FPDArrayNew</a>, <a>FPDDictionaryNew</a>, <a>FPDStreamNew</a>, 
 * <a>FPDNullNew</a>, <a>FPDRefernceNew</a>, <a>FPDRefernceNew2</a>.
 * 
 */
	typedef struct _t_FPD_Object* FPD_Object;
#endif
/* @OBJEND */

/* @OBJSTART FPD_StreamAcc */
#ifndef FPD_STREAMACC
#define FPD_STREAMACC
/**
 * @brief Accessor of stream object: 
 * <a>FPD_StreamAcc</a> depends on a stream, it maintains a buffer for the data of a stream.
 * This buffer may be temporary, if the stream is encoded by one or more data encoders.
 * <a>FPD_StreamAcc</a> doesn't decode any image encoders. See <a>FPDStreamAccNew</a>, <a>FPDStreamAccDestroy</a>.
 *
 */
	typedef struct _t_FPD_StreamAcc* FPD_StreamAcc;
#endif
/* @OBJEND */

/* @OBJSTART FPD_StreamFilter */
#ifndef FPD_STREAMFILTER
#define FPD_STREAMFILTER
/** @brief Data filter created for accessing PDF stream data. See <a>FPDStreamFilterDestroy</a>.
 *
 */
	typedef struct _t_FPD_StreamFilter* FPD_StreamFilter;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Boolean */
/** @brief FPD_Boolean objects can have a value of <a>TRUE</a> or <a>FALSE</a>.
 *
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_Number */
/** 
 * @brief FPD_Number may be specified by signed or unsigned constants. <Italic>See Section 3.2.2 in the PDF Reference</Italic> for 
 * details.
 *
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_String */
/** 
 * @brief A FPD_String is a sequences of characters, enclosed in parentheses. <Italic>See Section 3.2.3 in the PDF Reference</Italic> for 
 * details.
 *
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_Name */
/** 
 * @brief A FPD_Name is a sequence of non-white space characters. In code, a name is preceded by the forward slash (/) 
 * character indicating that it is a string literal, for example: /AName. <Italic>See Section 3.2.4 in the PDF Reference</Italic> for 
 * details.
 *
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_Array */
/** 
 * @brief A FPD_Array is one-dimensional collections of objects accessed by a numeric index. Array indexes are 
 * zero-based. An array's elements may be any combination of the FPD_Object types.
 *
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_Dictionary */
/** 
 * @brief A FPD_Dictionary is an associative table whose elements are pairs of objects:<br>
 *
 * <ul>
 * <li>The first element of a pair is the key, which is always a name object, a sequence of characters 
 * beginning with the forward slash (/) character. </li>
 * <li>The second element is the Cos object representing the value.</li>
 * </ul>
 * See Section 3.2.6 in the PDF Reference for details.
 *
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_Stream */
/** 
 * @brief A FPD_Stream is a sequence of characters that can be read a portion at a time. Streams are used for objects with 
 * large amounts of data, such as images, page content, or private data a plug-in creates. A stream consists of 
 * these elements, which are listed in their relative order in the stream object, starting at the beginning. See 
 * Section 3.2.7 in the PDF Reference for a description of the stream object.
 *
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_Null */
/**
 * @brief There is only one <a>NULL</a> object, which is used to fill empty or uninitialized positions in arrays or dictionaries. 
 * See Section 3.2.8 in the PDF Reference for details.
 *
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_Reference */
/** 
 * @brief A FPD_Reference is a addtional type of object:<br>
 * Objects may be labeled so that they can be referred to by other objects. A labeled 
 * object is called an indirect object.
 *
 *
 */
/* @OBJEND */

/* @CALLBACKSTART FPD_LPFCloneStreamCallback */
/**
 * @brief Callback function is used to create file stream I/O to create PDF Stream object.
 *
 * @param[in] pStream		The input stream object.
 * @param[in] pUserData		User private data pointer passed to callback function.
 * @return void
 * @note
    */
    typedef void (*FPD_LPFCloneStreamCallback)(FPD_Object pStream, FS_LPVOID pUserData);
/* @CALLBACKEND */


/* @OBJSTART FPD_ClonePredicateHandler */
#ifndef FPD_CLONEPREDICATEHANDLER
#define FPD_CLONEPREDICATEHANDLER
/**
 * @brief 
 *
 */
	typedef struct _t_FPD_ClonePredicateHandler* FPD_ClonePredicateHandler;
#endif

	/* @CALLBACKGROUPSTART FPD_ClonePredicateCallbacks */
/** @brief A set of callbacks for Validator handler. */
	typedef struct _fpd_ClonePredicate_callbacks_
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_LongImageEncoderCallbacksRec</a>) */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART FPDCloneIsValid */
		/**
		* @brief FPDCloneIsValid.
		* @param[in] clientData	The user-supplied data.
		* @param[in] key	    The input key.
		* @return FS_BOOLEAN
		* @note
		*/
		FS_BOOLEAN(*FPDCloneIsValid)(FS_LPVOID clientData, FS_LPCBYTE key);
		/* @CALLBACKEND */

		/* @CALLBACKSTART FPDCloneGetDirect */
		/**
		* @brief FPDCloneGetDirect.
		* @param[in] clientData	The user-supplied data.
		* @param[in] key	    The input key.
		* @return FS_BOOLEAN
		* @note
		*/
		FS_BOOLEAN(*FPDCloneGetDirect)(FS_LPVOID clientData, FS_LPCBYTE key);
		/* @CALLBACKEND */

	}FPD_ClonePredicateCallbacksRec, *FPD_ClonePredicateCallbacks;
	/* @CALLBACKGROUPEND */
/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
/** @} */


/*@}*/
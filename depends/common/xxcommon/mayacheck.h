
#ifndef _MAYA_CHECK_
#define _MAYA_CHECK_

//#include "prerequest_maya.h"
#include <maya/MString.h>
#include <maya/MStatus.h>
#include <maya/M3dView.h>
class MMatrix;
class MVector;
class MFloatVectorArray;
class MEulerRotation;
class MStringArray;
class MIntArray;
class MFloatArray;
class MColor;
// class M3dView;
// enum DisplayStatus;
class MGlobal;
//////////////////////////////////////////////////////////////////////////
void displayInfo(const MString& info);
void displayError(const MString& error);
void displayWarning(const MString& warning);
void displayInfo(const MString& prefix, const MMatrix& matrix);
void displayInfo(const MString& prefix, double x, double y, double z);
void displayInfo(const MString& prefix, const MVector& v);
void displayInfo(const MString& prefix, const MFloatVectorArray& v);
void displayInfo(const MString& prefix, const MEulerRotation& v);
void displayInfo(const MString& prefix, double d);
void displayInfo(const MString& prefix, const MStringArray& array);
void displayInfo(const MString& prefix, const MIntArray& array);
void displayInfo(const MString& prefix, const MFloatArray& array);
void displayInfo(const MString& prefix, const MString& value);
void displayInfo(const MString& prefix, const MColor& value);
void displayInfo(const MString& prefix, M3dView::DisplayStatus displayStatus);

// Convenience macros for checking the return status from API methods.
// The output is displayed in the script editor instead of the output window...
// it's more noticeable that way.

// Output an error message and returns the value 'retVal' if status
// is not kSuccess.
//
#define PrintError(msg)	{ MString _m_output = "\nError detected in "; _m_output += __FILE__; _m_output += ", line "; _m_output += __LINE__; _m_output += ": "; _m_output += (msg); displayError(_m_output); }
#define IfMErrorWarn(x) { MStatus _m_s = (x); if (!_m_s) { PrintError(_m_s.errorString()); } }
#define IfMErrorMsgWarn(x, msg) { MStatus _m_s = (x); if (!_m_s) { PrintError((_m_s).errorString() + MString(" : ") + (msg)); } }
#define IfMErrorReturnIt(x) { MStatus _m_s = (x); if (!_m_s) { PrintError(_m_s.errorString()); return _m_s; } }
#define IfMErrorMsgReturnIt(x, msg) { MStatus _m_s = (x); if (!_m_s) { PrintError((_m_s).errorString() + MString(" : ") + (msg)); return _m_s; } }
#define IfMErrorReturnNothing(x) { MStatus _m_s = (x); if (!_m_s) { PrintError((_m_s).errorString()); return; } }
#define IfMErrorMsgReturnNothing(x, msg) { MStatus _m_s = (x); if (!_m_s) { PrintError((_m_s).errorString() + MString(" : ") + (msg)); return; } }
#define IfMErrorReturn(x, retval) { MStatus _m_s = (x); if (!_m_s) { PrintError((_m_s).errorString()); return (retval); } }
#define IfMErrorMsgReturn(x, msg, retval) { MStatus _m_s = (x); if (!_m_s) { PrintError((_m_s).errorString() + MString(" : ") + (msg)); return (retval); } }
#define IfErrorWarn(x) { bool _m_s = (x); if (!_m_s) { PrintError(#x); } }
#define IfErrorMsgWarn(x, msg) { bool _m_s = (x); if (!_m_s) { PrintError(#x + MString(" : ") + (msg)); } }
#define IfErrorReturnIt(x) { bool _m_s = (x); if (!_m_s) { PrintError(#x); return _m_s; } }
#define IfErrorMsgReturnIt(x, msg) { bool _m_s = (x); if (!_m_s) { PrintError(#x + MString(" : ") + (msg)); return _m_s; } }
#define IfErrorReturnNothing(x) { bool _m_s = (x); if (!_m_s) { PrintError(#x); return; } }
#define IfErrorMsgReturnNothing(x, msg) { bool _m_s = (x); if (!_m_s) { PrintError(#x + MString(" : ") + (msg)); return; } }
#define IfErrorReturn(x, retval) { bool _m_s = (x); if (!_m_s) { PrintError(#x); return (retval); } }
#define IfErrorMsgReturn(x, msg, retval) { bool _m_s = (x); if (!_m_s) { PrintError(#x + MString(" : ") + (msg)); return (retval); } }

#define IfGLErrorWarn() { GLenum _gl_err = glGetError(); IfErrorMsgWarn((_gl_err != GL_NO_ERROR), MString("GL Error")); } 
#define IfGLErrorMsgWarn(msg) { GLenum _gl_err = glGetError(); IfErrorMsgWarn((_gl_err == GL_NO_ERROR), MString("GL Error: ") + MString(msg)); } 

#define IF_ERROR_RETURN(x, retVal)						\
{ 														\
	MStatus _maya_status = (x);							\
	if ( MStatus::kSuccess != _maya_status ) 			\
	{													\
		MString _m_output = "\nAPI error detected in ";	\
		_m_output += __FILE__;							\
		_m_output += " at line ";						\
		_m_output += __LINE__;							\
		_m_output += ": ";								\
		_m_output += _maya_status.errorString();		\
		MGlobal::displayError(_m_output);				\
		return (retVal);								\
	}													\
}

#define IF_ERROR_RETURN_NOTHING(x)						\
{ 														\
	MStatus _maya_status = (x);							\
	if ( MStatus::kSuccess != _maya_status ) 			\
	{													\
		MString _m_output = "\nAPI error detected in ";	\
		_m_output += __FILE__;							\
		_m_output += " at line ";						\
		_m_output += __LINE__;							\
		_m_output += ": ";								\
		_m_output += _maya_status.errorString();		\
		MGlobal::displayError(_m_output);				\
		return;											\
	}													\
}

// Same as above, except that the return value is the status itself.
//
#define IF_ERROR_RETURN_IT(x)					\
IF_ERROR_RETURN((x), (x))

// Output an error message if status is not kSuccess.
//
#define CHECK_STATUS(x)									\
{														\
	MStatus _maya_status = (x);							\
	if ( MStatus::kSuccess != _maya_status ) 			\
	{													\
		MString _m_output = "\nAPI error detected in ";	\
		_m_output += __FILE__;							\
		_m_output += " at line ";						\
		_m_output += __LINE__;							\
		_m_output += ": ";								\
		_m_output += _maya_status.errorString();		\
		MGlobal::displayError(_m_output);				\
	}													\
}
//////////////////////////////////////////////////////////////////////////
#endif//_MAYA_CHECK_
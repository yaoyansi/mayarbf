#ifndef _SCALAR_
#define _SCALAR_

#define _USE_DOUBLE_PRECISION_

#include <xxcommon/prerequest_maya.h>

#ifdef _USE_DOUBLE_PRECISION_
	typedef double Scalar;
#else
	typedef float Scalar;
#endif



#ifdef _USE_DOUBLE_PRECISION_
	typedef MPoint		Point;
	typedef MPointArray PointArray;
#else
	typedef MFloatPoint		Point;
	typedef MFloatPointArray PointArray;
#endif

#endif
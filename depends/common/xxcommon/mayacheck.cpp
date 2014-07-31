#include "prerequest_std.h"
#include "prerequest_maya.h"
#include "mayacheck.h"


void displayInfo(const MString& prefix, const MMatrix& matrix)
{
	MString str(prefix);
	str += ":\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			str += matrix[i][j];
			str += " ";
		}

		str += "\n";
	}
	str += "\n";

	MGlobal::displayInfo(str);
}

void displayInfo(const MString& prefix, double x, double y, double z)
{
	MString str(prefix);
	str += ":\n";
	str += x;
	str += ", ";
	str += y;
	str += ", ";
	str += z;

	MGlobal::displayInfo(str);
}

void displayInfo(const MString& prefix, const MVector& v)
{
	displayInfo(prefix, v.x, v.y, v.z);
}

void displayInfo(const MString& prefix, const MFloatVectorArray& v)
{
	for (size_t i = 0; i < v.length(); ++i)
	{
		displayInfo(prefix + "[" + i + "] ", v[i].x, v[i].y, v[i].z);
	}
}

void displayInfo(const MString& prefix, const MEulerRotation& v)
{
	displayInfo(prefix, v.x, v.y, v.z);
}

void displayInfo(const MString& prefix, double d)
{
	MGlobal::displayInfo(prefix + ": " + d);
}

void displayInfo(const MString& prefix, const MStringArray& array)
{
	MString str(prefix);
	str += " (MStringArray of length ";
	str += (int) array.length();
	str += "):\n";
	MGlobal::displayInfo(str);

	for (unsigned int i=0; i < array.length(); i++)
		MGlobal::displayInfo(array[i] + "\n");

	MGlobal::displayInfo("\n");
}

void displayInfo(const MString& prefix, const MIntArray& array)
{
	MString str(prefix);
	str += " (MIntArray of length ";
	str += (int) array.length();
	str += "):\n";
	MGlobal::displayInfo(str);

	for (unsigned int i=0; i < array.length(); i++)
	{
		char buf[128];
		sprintf_s(buf, 128, "%d", array[i]);
		if (i < array.length() - 1) strcat_s(buf, 128, ", ");
		MGlobal::displayInfo(MString(buf));
	}

	MGlobal::displayInfo("\n");
}

void displayInfo(const MString& prefix, const MFloatArray& array)
{
	MString str(prefix);
	str += " (MFloatArray of length ";
	str += (int) array.length();
	str += "):\n";
	MGlobal::displayInfo(str);

	for (unsigned int i=0; i < array.length(); i++)
	{
		char buf[128];
		sprintf_s(buf, 128, "%f", array[i]);
		if (i < array.length() - 1) strcat_s(buf, 128, ", ");
		MGlobal::displayInfo(MString(buf));
	}

	MGlobal::displayInfo("\n");
}

void displayInfo(const MString& info)
{
	MGlobal::displayInfo(info);
	std::cout<< "[INFO]:"<<info.asChar()<< std::endl;
}

void displayError(const MString& error)
{
	MGlobal::displayError(error);
	std::cout<< "[ERR]:"<<error.asChar()<< std::endl;
}

void displayWarning(const MString& warning)
{
	MGlobal::displayWarning(warning);
	std::cout<< "[WARN]:"<<warning.asChar()<< std::endl;
}

void displayInfo(const MString& prefix, const MString& value)
{
	MString str(prefix);
	str += " (MString): ";
	str += value;

	MGlobal::displayInfo(str);
}

void displayInfo(const MString& prefix, const MColor& value)
{
	MString str(prefix);
	str += " (MColor): ";
	str += value.r;
	str += ", ";
	str += value.g;
	str += ", ";
	str += value.b;
	str += " ";

	MGlobal::displayInfo(str);
}

void displayInfo(const MString& prefix, M3dView::DisplayStatus displayStatus)
{
	MString info(prefix + ": ");

	// Print the DisplayStatus.
	switch (displayStatus)
	{
	case M3dView::kActive:
		info += "kActive";
		break;
	case M3dView::kLive:
		info += "kLive";
		break;
	case M3dView::kDormant:
		info += "kDormant";
		break;
	case M3dView::kInvisible:
		info += "kInvisible";
		break;
	case M3dView::kHilite:
		info += "kHilite";
		break;
	case M3dView::kTemplate:
		info += "kTemplate";
		break;
	case M3dView::kActiveTemplate:
		info += "kActiveTemplate";
		break;
	case M3dView::kActiveComponent:
		info += "kActiveComponent";
		break;
	case M3dView::kLead:
		info += "kLead";
		break;
	case M3dView::kIntermediateObject:
		info += "kIntermediateObject";
		break;
	case M3dView::kActiveAffected:
		info += "kActiveAffected";
		break;
	case M3dView::kNoStatus:
		info += "kNoStatus";
		break;
	default:
		info += "unknown";
		break;
	}

	displayInfo(info);
}


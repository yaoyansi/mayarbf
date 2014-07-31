/*
    Copyright (C) 2007 Feeling Software Inc. ("Feeling")    All rights reserved.
    
	These coded instructions, statements and computer programs (collectively
	the "Data") contain unpublished information proprietary to Feeling Software
	which is protected by Canadian and US federal copyright law and by
	international treaties. The data may not be disclosed to third parties
	or copied or duplicated, in whole or in part, without prior written consent
	of Feeling.
*/

// Author: Christian Laforte, Feeling Software Inc. (http://www.feelingsoftware.com)

#include "PhysicsBase.h"
#include <maya/MAngle.h>
#include <maya/MArgDatabase.h>
#include <maya/MColor.h>
#include <maya/MDagPath.h>
#include <maya/MEulerRotation.h>
#include <maya/MFloatArray.h>
#include <maya/MFloatVectorArray.h>
#include <maya/MFnCompoundAttribute.h>
#include <maya/MFnDagNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MGlobal.h>
#include <maya/MMatrix.h>
#include <maya/MPlug.h>
#include <maya/MPxNode.h>
#include <maya/MSelectionList.h>
#include <maya/MStringArray.h>
#include <maya/MFnPointArrayData.h>
#include <maya/MFnIntArrayData.h>
#include <maya/MFnVectorArrayData.h>
#include <maya/MFnStringArrayData.h>
#include <maya/MQuaternion.h>

void getPlugValueFloat3(const MPlug& plug, float& r, float& g, float& b)
{
	MObject obj;
	plug.getValue(obj);
	MStatus status;
	MFnNumericData fcolor(obj, &status);
	if(!status) return;
	status = fcolor.getData(r , g , b);
	//if(status)
	//MGlobal::displayInfo(plug.name()+r+g+b);
}

void getPlugValueFloat3(const MObject& node, const char* attributeName, float& r, float& g, float& b)
{
	MStatus status;
	MPlug plug = MFnDependencyNode(node).findPlug(attributeName, &status);
	if(status) getPlugValueFloat3(plug, r, g, b);
}

void setPlugValueFloat3(MPlug& plug, float& r, float& g, float& b)
{
	MStatus status;
	MFnNumericData fncenter;
	MObject obj = fncenter.create(MFnNumericData::k3Float);
	fncenter.setData(r, g, b);
	plug.setValue(obj);
}

void setPlugValueFloat3(const MObject& node, const char* attributeName, float& r, float& g, float& b)
{
	MStatus status;
	MPlug plug = MFnDependencyNode(node).findPlug(attributeName, &status);
	if(status) setPlugValueFloat3(plug, r, g, b);
}

MVector getPlugVector(const MPlug& parentPlug)
{
	MVector v(0.0, 0.0, 0.0);

	// Verify that this is a vector.
	if (!parentPlug.isCompound() || parentPlug.numChildren() != 3)
	{
		MGlobal::displayWarning("getPlugVector: plug is not a vector.");
		return v;
	}

	// Get the plugs to the children attributes.
	MPlug plug_x = parentPlug.child(0);
	MPlug plug_y = parentPlug.child(1);
	MPlug plug_z = parentPlug.child(2);

	// Get the values from the children plugs.
	float x, y, z;
	plug_x.getValue(x);
	plug_y.getValue(y);
	plug_z.getValue(z);

	v.x = x; v.y = y; v.z = z;
	return v;
}

void setPlugVector(const MPlug& parentPlug, const MVector& v)
{
	// Verify that this is a vector.
	if (!parentPlug.isCompound() || parentPlug.numChildren() != 3)
	{
		MGlobal::displayWarning("setPlugVector: plug is not a vector.");
		return;
	}

	// Get the plugs to the children attributes.
	MPlug plug_x = parentPlug.child(0);
	MPlug plug_y = parentPlug.child(1);
	MPlug plug_z = parentPlug.child(2);

	// Get the values from the children plugs.
	plug_x.setValue(v.x);
	plug_y.setValue(v.y);
	plug_z.setValue(v.z);
}

void setPlugVector(const MObject& node, const char* attrname, const MVector& v)
{
	MStatus status;
	MFnDependencyNode fnode(node, &status);
	if(!status) return;
	MPlug plug = fnode.findPlug(attrname, &status);
	if(!status) return;
	setPlugVector(plug, v);
}

MPoint getPlugPoint(const MPlug& parentPlug)
{
	MVector v = getPlugVector(parentPlug);
	MPoint p(v.x, v.y, v.z);
	return p;
}

void setPlugPoint(const MPlug& parentPlug, const MPoint& p)
{
	MVector v(p.x, p.y, p.z);
	setPlugVector(parentPlug, v);
}

void setPlugValueIntArray(MPlug& plug, const MIntArray& ints)
{
	MFnIntArrayData fndata;
	MObject odata = fndata.create();
	fndata.set(ints);
	plug.setValue(odata);
}

void setPlugValueVectorArray(MPlug& plug, const MVectorArray& vectors)
{
	MFnVectorArrayData fndata;
	MObject odata = fndata.create();
	fndata.set(vectors);
	plug.setValue(odata);
}

void setPlugValuePointArray(MPlug& plug, const MPointArray& points)
{
	MFnPointArrayData fndata;
	MObject odata = fndata.create();
	fndata.set(points);
	plug.setValue(odata);
}

void setPlugValueStringArray(MPlug& plug, const MStringArray& strings)
{
	MFnStringArrayData fndata;
	MObject odata = fndata.create();
	fndata.set(strings);
	plug.setValue(odata);
}


#ifdef WIN32
#include <float.h>
int isNotANumber(float f) { return _isnan(f); }

MString dtos(double val)
{
	MString str;

	int fc = _fpclass(val);
	switch (fc)
	{
	case _FPCLASS_SNAN:
	case _FPCLASS_QNAN:
		str += "NaN";
		break;

	case _FPCLASS_NINF:
		str += "–INF";
		break;

	case _FPCLASS_PINF:
		str += "INF";
		break;

	case _FPCLASS_NZ:
		str += "-0";
		break;

	case _FPCLASS_PZ:
		str += "0";
		break;

	case _FPCLASS_NN:
	case _FPCLASS_ND:
	case _FPCLASS_PD:
	case _FPCLASS_PN:
	default:
		str += val;
	}

	return str;
}

#else // Linux or OS X

int isNotANumber(float f) { return !finite(f); }

MString dtos(double val)
{
	MString str;
	if (finite(val))
		str += val;
	else if (isinf(val) == -1)
		str += "-INF";
	else if (isinf(val) == 1)
		str += "INF";
	else
		str += "NaN";

	return str;
}

#endif

MStatus addDouble3Attribute(MObject& aCompound, 
							MObject& aChildX, MObject& aChildY, MObject& aChildZ, 
							const MString& longName,
							const MString& compoundShortName, 
							const MString& childShortName,
							MVector defaultValue,
							bool keyable /* = false */,
							bool writable /* = true */,
							bool hidden /* = false */,
							bool storable /* = true */,
							bool array /* = false */,
							bool affectsWorldSpace /* = false */)
{
	MStatus status;
	MFnNumericAttribute numAttr;
	
	aChildX = numAttr.create(longName + "X", childShortName + "x", 
		MFnNumericData::kDouble, defaultValue.x, &status);
	IfMErrorMsgReturnIt(status, "couldn't create child attribute " + longName + "X");
	IfMErrorMsgReturnIt(MPxNode::addAttribute(aChildX), "couldn't add child attribute " + longName + "X");
		
	aChildY = numAttr.create(longName + "Y", childShortName + "y", 
		MFnNumericData::kDouble, defaultValue.y, &status);
	IfMErrorMsgReturnIt(status, "couldn't create child attribute " + longName + "Y");
	IfMErrorMsgReturnIt(MPxNode::addAttribute(aChildY), "couldn't add child attribute " + longName + "Y");

	aChildZ = numAttr.create(longName + "Z", childShortName + "z", 
		MFnNumericData::kDouble, defaultValue.z, &status);
	IfMErrorMsgReturnIt(status, "couldn't create child attribute " + longName + "Z");
	IfMErrorMsgReturnIt(MPxNode::addAttribute(aChildZ), "couldn't add child attribute " + longName + "Z");
	
	aCompound = numAttr.create(longName, compoundShortName, aChildX, aChildY, aChildZ, &status);
    IfMErrorMsgReturnIt(status, "couldn't create compound attribute " + longName);
	
	IfMErrorMsgWarn(numAttr.setKeyable(keyable), "couldn't setKeyable() on " + longName);
	IfMErrorMsgWarn(numAttr.setWritable(writable), "couldn't setWritable() on " + longName);
	IfMErrorMsgWarn(numAttr.setHidden(hidden), "couldn't setHidden() on " + longName);
	IfMErrorMsgWarn(numAttr.setStorable(storable), "couldn't setStorable() on " + longName);
	IfMErrorMsgWarn(numAttr.setDefault(defaultValue.x, defaultValue.y, defaultValue.z), 
		"couldn't setDefault() on " + longName);
	IfMErrorMsgWarn(numAttr.setArray(array), "couldn't setArray() on " + longName);
	
	if (affectsWorldSpace)
		IfMErrorMsgWarn(numAttr.setAffectsWorldSpace(true), "couldn't setAffectsWorldSpace() on " + longName);
	

	IfMErrorMsgReturnIt(MPxNode::addAttribute(aCompound), "couldn't add compound attribute " + longName);

	return MS::kSuccess;
}

MStatus addAngle3Attribute(MObject& aCompound, 
							MObject& aChildX, MObject& aChildY, MObject& aChildZ, 
							const MString& longName,
							const MString& compoundShortName, 
							const MString& childShortName,
							bool keyable /* = false */,
							bool writable /* = true */,
							bool hidden /* = false */,
							bool storable /* = true */,
							bool array /* = false */,
							bool affectsWorldSpace /* = false */)
{
	MStatus status;
	MFnUnitAttribute unitAttr;
	MFnCompoundAttribute compAttr;

	// [claforte] NOTE: Trying to set a default value here (e.g. unitAttr.setDefault(MAngle(x)))
	// causes an exception to be thrown.
	//
	aChildX = unitAttr.create(longName + "X", childShortName + "x", MAngle(), &status);
	IfMErrorMsgReturnIt(status, "couldn't create child attribute " + longName + "X");
	IfMErrorMsgReturnIt(MPxNode::addAttribute(aChildX), "couldn't add child attribute " + longName + "X");
		
	aChildY = unitAttr.create(longName + "Y", childShortName + "y", MAngle(), &status);
	IfMErrorMsgReturnIt(status, "couldn't create child attribute " + longName + "Y");
	IfMErrorMsgReturnIt(MPxNode::addAttribute(aChildY), "couldn't add child attribute " + longName + "Y");
	
	aChildZ = unitAttr.create(longName + "Z", childShortName + "z", MAngle(), &status);
	IfMErrorMsgReturnIt(status, "couldn't create child attribute " + longName + "Z");
	IfMErrorMsgReturnIt(MPxNode::addAttribute(aChildZ), "couldn't add child attribute " + longName + "Z");
	
	aCompound = compAttr.create(longName, compoundShortName);
	IfMErrorMsgReturnIt(compAttr.addChild(aChildX), 
		"couldn't add to compound child attribute " + longName + "X");
	IfMErrorMsgReturnIt(compAttr.addChild(aChildY), 
		"couldn't add to compound child attribute " + longName + "Y");
	IfMErrorMsgReturnIt(compAttr.addChild(aChildZ), 
		"couldn't add to compound child attribute " + longName + "Z");
	
	IfMErrorMsgWarn(compAttr.setKeyable(keyable), "couldn't setKeyable() on " + longName);
	IfMErrorMsgWarn(compAttr.setWritable(writable), "couldn't setWritable() on " + longName);
	IfMErrorMsgWarn(compAttr.setHidden(hidden), "couldn't setHidden() on " + longName);
	IfMErrorMsgWarn(compAttr.setStorable(storable), "couldn't setStorable() on " + longName);
	IfMErrorMsgWarn(compAttr.setArray(array), "couldn't setArray() on " + longName);

	if (affectsWorldSpace)
		IfMErrorMsgWarn(compAttr.setAffectsWorldSpace(true), "couldn't setAffectsWorldSpace() on " + longName);

	IfMErrorMsgReturnIt(MPxNode::addAttribute(aCompound), "couldn't add compound attribute " + longName);

	return MS::kSuccess;
}

MStatus addDirtyAttribute(MObject& attrObj, 
						  const MString& longName,
						  const MString& shortName)
{
	MStatus status;
	MFnNumericAttribute numAttr;
	
	attrObj = numAttr.create(longName, shortName, MFnNumericData::kBoolean, false, &status);
	IfMErrorReturnIt(status);
	IfMErrorReturnIt(numAttr.setConnectable(false));
	IfMErrorReturnIt(numAttr.setStorable(false));
	IfMErrorReturnIt(numAttr.setHidden(true));

	IfMErrorMsgReturnIt(MPxNode::addAttribute(attrObj), "couldn't add attribute " + longName);

	return MS::kSuccess;
}

MStatus triggerDirtyEvaluation(MDataBlock& dataBlock, const MObject& attrObj)
{
	MStatus status;

	MDataHandle dirtyHandle = dataBlock.inputValue(attrObj, &status);
	IfMErrorReturnIt(status);
	dirtyHandle.asBool(); // return value ignored.

	return MS::kSuccess;
}

MStatus updateDirtyAttribute(MDataBlock& dataBlock, const MObject& attrObj)
{
	MStatus status;

	MDataHandle handle = dataBlock.outputValue(attrObj, &status);
	IfMErrorReturnIt(status);
	handle.set(false);

	return MS::kSuccess;
}

// bool identical(const btTransform& mat1, const btTransform& mat2)
// {
// 	float m1[9];
// 	float m2[9];
// 	mat1.getRowMajor(m1);
// 	mat2.getRowMajor(m2);
// 
// 	for (int i=0; i < 9; i++)
// 		if (m1[i] != m2[i])
// 			return false;
// 	
// 	return true;
// }
// 
// bool different(const btTransform& mat1, const btTransform& mat2)
// {
// 	float m1[9];
// 	float m2[9];
// 	mat1.getRowMajor(m1);
// 	mat2.getRowMajor(m2);
// 
// 	for (int i=0; i < 9; i++)
// 		if (m1[i] == m2[i])
// 			return false;
// 	
// 	return true;
// }

MVector b2mVector(const btVector3& vec3)
{
	return MVector(vec3.x(), vec3.y(), vec3.z());
}

btVector3 m2bVector(MVector vector)
{
	return btVector3( vector.x, vector.y, vector.z);
}

// Actual theoretical epsilon, taken from FLT_MIN defined in <float.h> on Windows only.
float FLOAT_EPSILON = 1.175494351e-38f;        // min positive value;

btVector3 m2bPositiveVector(MVector vector)
{
	float x = (float) vector.x;
	float y = (float) vector.y;
	float z = (float) vector.z;

	if (x <= FLOAT_EPSILON)
		x = FLOAT_EPSILON;
	if (y <= FLOAT_EPSILON)
		y = FLOAT_EPSILON;
	if (z <= FLOAT_EPSILON)
		z = FLOAT_EPSILON;

	return btVector3(x, y, z);
}

MMatrix b2mMatrix(const btTransform& matrix)
{
	btScalar mat[16];
	matrix.getOpenGLMatrix(mat);

	// [claforte] Somehow this is in the inverse order I
	// would have expected...
	MMatrix m;
	m[0][0] = mat[0];
	m[1][0] = mat[1];
	m[2][0] = mat[2];
	m[3][0] = mat[3];
	m[0][1] = mat[4];
	m[1][1] = mat[5];
	m[2][1] = mat[6];
	m[3][1] = mat[7];
	m[0][2] = mat[8];
	m[1][2] = mat[9];
	m[2][2] = mat[10];
	m[3][2] = mat[11];
	m[0][3] = mat[12];
	m[1][3] = mat[13];
	m[2][3] = mat[14];
	m[3][3] = mat[15];

	return m;
}

btTransform m2bMatrix(const MMatrix& m)
{
	btTransform matrix;

	btScalar mat[16];
	mat[0] = (btScalar) m[0][0];
	mat[1] = (btScalar) m[1][0];
	mat[2] = (btScalar) m[2][0];
	mat[3] = (btScalar) m[3][0];
	mat[4] = (btScalar) m[0][1];
	mat[5] = (btScalar) m[1][1];
	mat[6] = (btScalar) m[2][1];
	mat[7] = (btScalar) m[3][1];
	mat[8] = (btScalar) m[0][2];
	mat[9] = (btScalar) m[1][2];
	mat[10] = (btScalar) m[2][2];
	mat[11] = (btScalar) m[3][2];
	mat[12] = (btScalar) m[0][3];
	mat[13] = (btScalar) m[1][3];
	mat[14] = (btScalar) m[2][3];
	mat[15] = (btScalar) m[3][3];

	matrix.setFromOpenGLMatrix(mat);
	return matrix;
}

btQuaternion m2bQuaternion(const MMatrix& originalMatrix)
{

	MTransformationMatrix transformationMatrix(originalMatrix);
	MQuaternion q = transformationMatrix.rotationOrientation();
	
	return btQuaternion(q.x, q.y, q.z, q.w);
}

// MMatrix n2mPoseMatrix(const NxMat33& orientMat, NxVec3 pos)
// {
// 	float mat[16];
// 	orientMat.getRowMajorStride4(mat);
// 
// 	MMatrix m;
// 
// 	// Set orientation.
// 	m[0][0] = mat[0];
// 	m[1][0] = mat[1];
// 	m[2][0] = mat[2];
// 	m[0][1] = mat[3];
// 	m[1][1] = mat[4];
// 	m[2][1] = mat[5];
// 	m[0][2] = mat[6];
// 	m[1][2] = mat[7];
// 	m[2][2] = mat[8];
// 
// 	// Set position.
// 	m[3][0] = pos.x;
// 	m[3][1] = pos.y;
// 	m[3][2] = pos.z;
// 
// 	return m;
// }

void extractNonRigidMatrix(const MTransformationMatrix& transformationMatrix, 
						   MMatrix* pOutNonRigidMatrix /* = NULL */,
						   MMatrix* pOutRigidMatrix /* = NULL */)
{
	MMatrix rigidMatrix = transformationMatrix.asRotateMatrix();
	MMatrix matrix = transformationMatrix.asMatrix();
	rigidMatrix[3][0] = matrix[3][0];
	rigidMatrix[3][1] = matrix[3][1];
	rigidMatrix[3][2] = matrix[3][2];

	// The non-rigid matrix will be baked onto vertices, therefore applied
	// first. The final transform will be equal to:
	//
	// matrix = rigidMatrix * nonRigidMatrix * vertices;
	//
	// Therefore nonRigidMatrix = rigidMatrix.inverse() * matrix.
	//
	// [claforte] TODO: Verify.
	MMatrix nonRigidMatrix = rigidMatrix.inverse() * matrix;

	// Set the output.
	if (pOutRigidMatrix)
		*pOutRigidMatrix = rigidMatrix;
	if (pOutNonRigidMatrix)
		*pOutNonRigidMatrix = nonRigidMatrix;
}

void convertMatrix(const MMatrix& in, double out[])
{
	// NOTE: this automatically does a transpose()
	// to account for Maya and OpenGL's different
	// conventions.
	out[0] = in[0][0];
	out[1] = in[0][1];
	out[2] = in[0][2];
	out[3] = in[0][3];
	out[4] = in[1][0];
	out[5] = in[1][1];
	out[6] = in[1][2];
	out[7] = in[1][3];
	out[8] = in[2][0];
	out[9] = in[2][1];
	out[10] = in[2][2];
	out[11] = in[2][3];
	out[12] = in[3][0];
	out[13] = in[3][1];
	out[14] = in[3][2];
	out[15] = in[3][3];
}

void glLoadMatrixd(const MMatrix& in)
{
	double out[16];
	convertMatrix(in, out);
	glLoadMatrixd(out);
}

void glMultMatrixd(const MMatrix& in)
{
	double out[16];
	convertMatrix(in, out);
	glMultMatrixd(out);
}

void ifFlagSetVector(const MArgDatabase& argData, 
					 const char* flagName, 
					 MVector& v, 
					 bool* pSpecified /* = NULL */)
{
	bool specified = false;
	if (argData.isFlagSet(flagName))
	{
		specified = true;
		argData.getFlagArgument(flagName, 0, v.x);
		argData.getFlagArgument(flagName, 1, v.y);
		argData.getFlagArgument(flagName, 2, v.z);
	}

	if (pSpecified)
		*pSpecified = specified;
}

MString quotify(const MString& other)
{
	MString str = "\"";
	str += other;
	str += "\"";

	return str;
}

MObject getMObjectFromName(const MString& name)
{
	MObject nodeObj;

	MSelectionList list;
	IfMErrorReturn(list.add(name), nodeObj);
	IfMErrorReturn(list.getDependNode(0, nodeObj), nodeObj);

	return nodeObj;
}

MPxNode* getMPxNode(const MString& name)
{
	return getMPxNode(getMObjectFromName(name));
}

MPxNode* getMPxNode(const MObject& obj)
{
	MStatus status;
	if (obj.isNull() || !obj.hasFn(MFn::kDependencyNode))
		return NULL;

	MFnDependencyNode depNode(obj, &status);
	IfMErrorReturn(status, NULL);
	MPxNode* pMPxNode = depNode.userNode(&status);
	if (!status)
		return NULL;

	return pMPxNode;
}

MString getNodeName(const MPlug& plug, MStatus* pStatus /* = NULL */)
{
	MStatus status;
	if (pStatus == NULL)
		pStatus = &status;

	if (plug.node().hasFn(MFn::kDagNode))
	{
		MFnDagNode node(plug.node(), pStatus);
		IfMErrorReturn(*pStatus, "");

		return node.partialPathName();
	}
	else
	{
		MFnDependencyNode node(plug.node(), pStatus);
		IfMErrorReturn(*pStatus, "");

		return node.name();
	}
}

MStatus removeMultiInstance(const MString& plugName, bool breakConnection /* = false */)
{
	int successfullyRemoved = 0;

	MString command = "removeMultiInstance ";
	if (breakConnection)
		command += "-b true ";
	command += "(\"" + plugName + "\");";

	MStatus status;
	try
	{
		// NOTE: Never call this function with undo enabled. It will cause Maya to throw internal
		// exceptions when undoing, e.g. when undoing a create rigid body operation.
		status = MGlobal::executeCommand(command, successfullyRemoved, false, false);
	}
	catch (...)
	{
		displayError("EXCEPTION occured while trying to execute following command: " + command);
	}

	if (!status)
	{
		// Warn the user.
		//PrintError("removeMultiInstance of plug '" + plugName + MString("' failed."));
	}
	else
	{
		//displayInfo("succesfully removeMultiInstance of plug '" + plugName + MString("'."));
	}

	return MS::kSuccess;
}

MStatus removeMultiInstance(const MPlug& plug, bool breakConnection /* = false */)
{
	return removeMultiInstance(plug.name(), breakConnection);
}

MStatus removeMultiInstance(const MString& nodeName, 
							const MString& attributeName, 
							bool breakConnection /* = false */,
							int index /* = -1 */)
{
	MString plugName = nodeName;
	plugName += ".";
	plugName += attributeName;
	
	if (index >= 0)
	{
		plugName += "[";
		plugName += index;
		plugName += "]";
	}

	return removeMultiInstance(plugName, breakConnection);
}

MStatus copyVectorAttribute(MFnDependencyNode& dependNodeFn, const MString& attrSource, 
							const MString& attrTarget)
{
	MStatus status;

	MPlug sourcePlug = dependNodeFn.findPlug(attrSource, &status);
	IfMErrorWarn(status);
	if (!status || sourcePlug.isNull()) 
	{
		MString str = "Object '";
		str += dependNodeFn.name();
		str += "' has no source attribute '";
		str += attrSource;
		str += "'";
		MGlobal::displayWarning(str);
		return MS::kFailure;
	}

	// Initialize overriddenPosition = currentPosition.
	//
	MPlug targetPlug = dependNodeFn.findPlug(attrTarget, &status);
	IfMErrorWarn(status);
	if (!status || targetPlug.isNull()) 
	{
		MString str = "Object '";
		str += dependNodeFn.name();
		str += "' has no target attribute '";
		str += attrTarget;
		str += "'";
		MGlobal::displayWarning(str);
		return MS::kFailure;
	}
	setPlugVector(targetPlug, getPlugVector(sourcePlug));

	// [claforte] TODO: Support setting a keyframe on anim curve.

	return MS::kSuccess;
}

MMatrix convertPosOrientToMatrix(const MPoint& position, const MVector& orientation)
{
	MTransformationMatrix transformMatrix;

	double rotation[3];
	rotation[0] = orientation.x;
	rotation[1] = orientation.y; 
	rotation[2] = orientation.z; 

	MTransformationMatrix::RotationOrder rotOrder = MTransformationMatrix::kXYZ;
	transformMatrix.setRotation(rotation, rotOrder);

	transformMatrix.setTranslation(position, MSpace::kTransform);

	return transformMatrix.asMatrix();
}

void convertMatrixToPosOrient(const MMatrix& matrix, MPoint& position, MVector& orientation)
{
	MTransformationMatrix transformMatrix(matrix);
	double rotations[3];
	MTransformationMatrix::RotationOrder rotationOrder = MTransformationMatrix::kXYZ;
	transformMatrix.getRotation(rotations, rotationOrder);
	
	orientation.x = rotations[0];
	orientation.y = rotations[1];
	orientation.z = rotations[2];

	position = transformMatrix.translation(MSpace::kTransform);
}

void convertMatrixToPosOrient(const MMatrix& matrix, MPoint& position, MEulerRotation& orientation)
{
	MTransformationMatrix transformMatrix(matrix);
	orientation = transformMatrix.eulerRotation();
	position = transformMatrix.translation(MSpace::kTransform);
}

MStatus getParentInverseMatrix(MObject nodeObj, MMatrix& matrix)
{
	MStatus status;

	// [claforte] WORK-AROUND FOR BUG IN MAYA 6.5:
	// If I try to get the value of the parentInverseMatrix or
	// parentMatrix through the dataBlock, I always get an array with
	// 0 elements. So instead, use a plug... it ends up doing the
	// same thing as the MEL command 
	//     "getAttr \"node.parentInverseMatrix[0]\"".
	//
	// This code assumes that at least one parent inverse matrix is
	// available.
	//
	MFnDagNode dagFn(nodeObj, &status);
	IfMErrorReturnIt(status);
	MDagPath dagPath;
	IfMErrorReturnIt(dagFn.getPath(dagPath));
	matrix = dagPath.exclusiveMatrixInverse(&status);
	IfMErrorReturnIt(status);

	return MS::kSuccess;
}

MStatus getMatrixElement(MDataBlock& dataBlock,
						 MObject attributeObj, 
						 MMatrix& matrix)
{
	MStatus status;
	
	// Get the parent inverse matrix (i.e. world to parent matrix).
	//
	MArrayDataHandle arrayHandle = dataBlock.outputArrayValue(attributeObj, &status);
	IfMErrorReturnIt(status);
	unsigned int instanceCount = arrayHandle.elementCount(&status);
	IfMErrorReturnIt(status);

	if (instanceCount > 0)
	{
		matrix = arrayHandle.inputValue(&status).asMatrix();
		IfMErrorReturnIt(status);
	}
	else
	{
		PrintError("matrix element attribute doesn't exist");
		return MS::kFailure;
	}

	return MS::kSuccess;
}

bool getPlugConnectedTo(const MObject& node, const MString& attribute, MPlug& connectedPlug)
{
	MStatus status;
	MFnDependencyNode dgFn(node);
	MPlug plug = dgFn.findPlug(attribute, &status);
	if (status == MS::kSuccess && plug.isConnected())
	{
		// Get the connection - there can be at most one input to a plug
		//
		MPlugArray connections;
		plug.connectedTo(connections, true, true);
		if (connections.length() > 0)
		{
			connectedPlug = connections[0];
			return true;
		}
	}
	return false;
}

MObject getTypedShape(const MObject& root, MFn::Type type)
{
	MItDag dagIter;
	dagIter.reset( root, MItDag::kDepthFirst, MFn::kInvalid );
	for (; !dagIter.isDone(); dagIter.next()) 
	{
		if( dagIter.item().hasFn(type) ) return dagIter.item();
	}
	return MObject::kNullObj;
}

MMatrix getWorldSpace(const MObject& object)
{
	MMatrix world;
	MStatus status;
	MFnDagNode fndag(object, &status);
	if(!status) return world;
	
	for(unsigned i =0; i< fndag.parentCount(); i++) 
	{
		MObject oparent = fndag.parent(i);
		if(oparent.hasFn(MFn::kTransform)) world *= MFnDagNode(oparent).transformationMatrix();
	}
	return world;
}

MPointArray getHandleValuePointArray(MDataBlock& data, const MObject& attribute)
{
	MDataHandle handle = data.inputValue(attribute);
	MObject obj = handle.data();
	MFnPointArrayData fndata(obj);
	return fndata.array();
}

MVectorArray getHandleValueVectorArray(MDataBlock& data, const MObject& attribute)
{
	MDataHandle handle = data.inputValue(attribute);
	MObject obj = handle.data();
	MFnVectorArrayData fndata(obj);
	return fndata.array();
}

MIntArray getHandleValueIntArray(MDataBlock& data, const MObject& attribute)
{
	MDataHandle handle = data.inputValue(attribute);
	MObject obj = handle.data();
	MFnIntArrayData fndata(obj);
	return fndata.array();
}

MStringArray getHandleValueStringArray(MDataBlock& data, const MObject& attribute)
{
	MDataHandle handle = data.inputValue(attribute);
	MObject obj = handle.data();
	MFnStringArrayData fndata(obj);
	return fndata.array();
}

unsigned getFirstEmptyElementId(const MPlug& parent)
{
	unsigned num_element = 1;
	if(parent.numElements() > num_element) num_element = parent.numElements();
	for(unsigned i = 0; i< num_element; i++)
	{
		if(!parent.elementByLogicalIndex(i).isConnected()) return i;
	}
	return parent.numElements()+1;
}

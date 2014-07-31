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

#ifndef __PHYSICS_BASE_INCLUDED__
#define __PHYSICS_BASE_INCLUDED__

#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

#include <maya/MVector.h>
#include <maya/MPoint.h>
#include <maya/MPointArray.h>
#include <maya/M3dView.h>
#include <maya/MString.h>
#include <maya/MPlugArray.h>
#include <maya/MItDag.h>
#include <maya/MIntArray.h>
#include <maya/MVectorArray.h>
#include <maya/MStringArray.h>
#include <math.h>

#include "mayacheck.h"

class MArgDatabase;
class MColor;
class MDataBlock;
class MFloatArray;
class MFloatVectorArray;
class MFnDependencyNode;
class MEulerRotation;
class MIntArray;
class MMatrix;
class MObject;
class MPlug;
class MPxNode;
class MStringArray;
class MPlugArray;

void getPlugValueFloat3(const MPlug& parentPlug, float& r, float& g, float& b);
void getPlugValueFloat3(const MObject& node, const char* attributeName, float& r, float& g, float& b);
void setPlugValueFloat3(MPlug& parentPlug, float& r, float& g, float& b);
void setPlugValueFloat3(const MObject& node, const char* attributeName, float& r, float& g, float& b);

MVector getPlugVector(const MPlug& parentPlug);
MPoint getPlugPoint(const MPlug& parentPlug);
int getPlugInt(const MPlug& parentPlug);

void setPlugVector(const MPlug& parentPlug, const MVector& v);
void setPlugPoint(const MPlug& parentPlug, const MPoint& p);
void setPlugValueIntArray(MPlug& plug, const MIntArray& ints);
void setPlugValuePointArray(MPlug& plug, const MPointArray& points);
void setPlugValueVectorArray(MPlug& plug, const MVectorArray& vectors);
void setPlugValueStringArray(MPlug& plug, const MStringArray& strings);
void setPlugVector(const MObject& node, const char* attrname, const MVector& v);

MPointArray getHandleValuePointArray(MDataBlock& data, const MObject& attribute);
MVectorArray getHandleValueVectorArray(MDataBlock& data, const MObject& attribute);
MIntArray getHandleValueIntArray(MDataBlock& data, const MObject& attribute);
MStringArray getHandleValueStringArray(MDataBlock& data, const MObject& attribute);

// Convert from radians to degrees
//
inline float radToDeg(float val) { return (val * 180.0f/(float)M_PI); }
inline double radToDeg(double val) { return (val * 180.0/M_PI); }
inline float degToRad(float val) { return (val * (float)M_PI/180.0f); }
inline double degToRad(double val) { return (val * M_PI/180.0); }

// Convert from double to MString, taking in consideration
// -INF, INF and NaN.
MString dtos(double val);

//------------------------------------------------------------------------
//      Attribute creation methods.
//
MStatus addDouble3Attribute(MObject& aCompound, 
							MObject& aChildX, MObject& aChildY, MObject& aChildZ, 
							const MString& longName,
							const MString& compoundShortName, 
							const MString& childShortName,
							MVector defaultValue,
							bool keyable = false,
							bool writable = true,
							bool hidden = false,
							bool storable = true,
							bool array = false,
							bool affectsWorldSpace = false);

MStatus addAngle3Attribute(MObject& aCompound, 
						   MObject& aChildX, MObject& aChildY, MObject& aChildZ, 
						   const MString& longName,
						   const MString& compoundShortName, 
						   const MString& childShortName,
						   bool keyable = false,
						   bool writable = true,
						   bool hidden = false,
						   bool storable = true,
						   bool array = false,
						   bool affectsWorldSpace = false);

MStatus addDirtyAttribute(MObject& attrObj, 
						  const MString& longName,
						  const MString& shortName);

MStatus triggerDirtyEvaluation(MDataBlock& dataBlock, const MObject& attrObj);
MStatus updateDirtyAttribute(MDataBlock& dataBlock, const MObject& attrObj);


//------------------------------------------------------------------------
//      Conversion from Maya <--> Bullet.
//
//bool identical(const btTransform& mat1, const btTransform& mat2);
//bool different(const btTransform& mat1, const btTransform& mat2);

MVector b2mVector(const btVector3& vec3);
btVector3 m2bVector(MVector vector);
btVector3 m2bPositiveVector(MVector vector);
MMatrix b2mMatrix(const btTransform& mat);
btTransform m2bMatrix(const MMatrix& m);
btQuaternion m2bQuaternion(const MMatrix& originalMatrix);
//MMatrix n2mPoseMatrix(const NxMat33& orientMat, NxVec3 pos);
void extractNonRigidMatrix(const MTransformationMatrix& transformationMatrix, 
						   MMatrix* pOutNonRigidMatrix = NULL,
						   MMatrix* pOutRigidMatrix = NULL);

// Convert a Maya matrix in a format suitable for OpenGL.
void convertMatrix(const MMatrix& in, double out[]);

void glLoadMatrixd(const MMatrix& in);
void glMultMatrixd(const MMatrix& in);

void ifFlagSetVector(const MArgDatabase& argData, 
					 const char* flagName, 
					 MVector& v, 
					 bool* pSpecified = NULL);


// Surround the string with "quotes".
MString quotify(const MString&);

const MString comma(", ");

MObject getMObjectFromName(const MString& name);
MPxNode* getMPxNode(const MString& name);
MPxNode* getMPxNode(const MObject& obj);

MString getNodeName(const MPlug& plug, MStatus* pStatus = NULL);

MStatus removeMultiInstance(const MString& plugName, bool breakConnection = false);
MStatus removeMultiInstance(const MPlug& plug, bool breakConnection = false);
MStatus removeMultiInstance(const MString& nodeName, 
							const MString& attributeName, 
							bool breakConnection = false,
							int index = -1);

MStatus copyVectorAttribute(MFnDependencyNode& dependNodeFn, const MString& attrSource, 
							const MString& attrTarget);

MMatrix convertPosOrientToMatrix(const MPoint& position, const MVector& orientation);
void convertMatrixToPosOrient(const MMatrix& matrix, MPoint& position, MVector& orientation);
void convertMatrixToPosOrient(const MMatrix& matrix, MPoint& position, MEulerRotation& orientation);

MStatus getParentInverseMatrix(MObject nodeObj, MMatrix& matrix);
MStatus getMatrixElement(MDataBlock& dataBlock, MObject attributeObj, 
						 MMatrix& matrix);
						 
// attribute connection retrieval
bool getPlugConnectedTo(const MObject& node, const MString& attribute, MPlug& connectedPlug);

MObject getTypedShape(const MObject& root, MFn::Type type);
MMatrix getWorldSpace(const MObject& object);
unsigned getFirstEmptyElementId(const MPlug& parent);

#endif // __PHYSICS_BASE_INCLUDED__

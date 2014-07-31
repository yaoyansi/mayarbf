#ifndef _RBF_CMD_
#define _RBF_CMD_

#include <xxcommon/prerequest_std.h>
#include <xxcommon/prerequest_maya.h>

#include "rbfcore/scalar.h"

// #define _DEFORM_BASE_MESH_
// 
// #ifndef _DEFORM_BASE_MESH_
// #define _DEFORM_TARGET_MESH_
// #endif

//#define _OBJECT_SPACE_ //$xxRBF_USE_OBJECT_SPACE



class RBFWapper;
class EigenPointNode;


class RBFCmd : public MPxCommand 
{
public:
	RBFCmd();
	virtual ~RBFCmd();
	virtual MStatus	doIt ( const MArgList& );
	virtual MStatus undoIt();
	virtual MStatus redoIt();
	virtual bool isUndoable() const { return true; }

	static void *creator() { return new RBFCmd; }
	static MSyntax newSyntax();

	static  const MTypeId     typeId;
	static  const MString     typeName;

	MStatus parseArgs(const MArgList& args);
	MStatus _init();
	MStatus _update();
	MStatus _updateSkeleton();
	 void printArgs();

private:
	MDGModifier dgMod;
	bool fInit;
	bool fUpdate;
	bool fUpdateSkeleton;

	RBFWapper* pRBF;
	//EigenPointNode* pEigenPointNode;
	//size_t numControlPoints;


	MObject getEigenPointNode();
	//EigenPointNode* getEigenPointNodePtr();
	MObject getSourceNodeOfPlug( const MFnDependencyNode &fnDNode,const MString &plugname);
	MObject getDestinyNodeOfPlug( const MFnDependencyNode &fnDNode,const MString &plugname);
	//Point get(const MFnDependencyNode &fnDNode, const MString &eigenPlugName, 
	//	const MString &meshPlugName,const int eigenIndex);
	MStatus updateToMesh(  PointArray &updated );
	void printPointArray(const std::string& tips,const PointArray& points);
	void printPointArray(const std::string& tips, 
		const std::vector<Scalar>& vx,
		const std::vector<Scalar>& vy,
		const std::vector<Scalar>& vz
		);
	//MStatus getEigenPoints(const MPlug& eigenPointsPlug, PointArray& points);
	MStatus getEigenPoints(const MPlug& EigenPointPlug, PointArray & points);
	MVector getOffset(const MVector& base, const MVector& target);
	MStatus _mapJoint(const MString& original, const MString& deformed);

	static PointArray meshPoints_original;//, meshPoints_target;
	static PointArray meshPoints_updated;

	//Displacement of control points in the Y-direction
	static std::vector<Scalar> controlPointDisplacementX;
	static std::vector<Scalar> controlPointDisplacementY;
	static std::vector<Scalar> controlPointDisplacementZ;

};

#endif
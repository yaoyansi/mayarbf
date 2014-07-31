#ifndef _RBF_JOINT_MAPPING__
#define _RBF_JOINT_MAPPING__

#include <xxcommon/prerequest_std.h>
#include <xxcommon/prerequest_maya.h>

#include "rbfcore/scalar.h"


class RBFWapper;
class EigenPointNode;


class RBFJointMapping : public MPxCommand 
{
public:
	RBFJointMapping();
	virtual ~RBFJointMapping();
	virtual MStatus	doIt ( const MArgList& );
	virtual MStatus undoIt();
	virtual MStatus redoIt();
	virtual bool isUndoable() const { return true; }

	static void *creator() { return new RBFJointMapping; }
	static MSyntax newSyntax();

	static  const MTypeId     typeId;
	static  const MString     typeName;

	MStatus parseArgs(const MArgList& args);
	MStatus _updateSkeleton();
	void printArgs();

private:
	MDGModifier dgMod;
	//bool fUpdateSkeleton;

	RBFWapper* pRBF;
	//EigenPointNode* pEigenPointNode;
	//size_t numControlPoints;


	MObject getEigenPointNode();
	//EigenPointNode* getEigenPointNodePtr();
	MObject getSourceNodeOfPlug( const MFnDependencyNode &fnDNode,const MString &plugname);
	MObject getDestinyNodeOfPlug( const MFnDependencyNode &fnDNode,const MString &plugname);
	//Point get(const MFnDependencyNode &fnDNode, const MString &eigenPlugName, 
	//	const MString &meshPlugName,const int eigenIndex);

	void printPointArray(const std::string& tips,const PointArray& points);
	void printPointArray(const std::string& tips, 
		const std::vector<Scalar>& vx,
		const std::vector<Scalar>& vy,
		const std::vector<Scalar>& vz
		);
	//MStatus getEigenPoints(const MPlug& eigenPointsPlug, PointArray& points);
	MStatus getEigenPoints(const MPlug& EigenPointPlug, PointArray & points);
	MVector getOffset(const MVector& base, const MVector& target);
	MStatus _mapJoint(const MString &joint);


};

#endif
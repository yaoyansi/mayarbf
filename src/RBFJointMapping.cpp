#include "RBFJointMapping.h"
#include <xxcommon/prerequest_local.h>
#include <xxcommon/mayacheck.h>
#include "rbfcore/RBFWapper.h"
#include "EigenPointsNode.h"
#include "RBFParameterNode.h"
//#include "rbfcore/scalar.h"

// #define kInitFlag				"-i"
// #define kInitFlagLong			"-init"
// 
// #define kUpdateFlag				"-u"
// #define kUpdateFlagLong			"-update"
// 
// #define kUpdateSkeletonFlag				"-us"
// #define kUpdateSkeletonFlagLong			"-updateSkeleton"

// #ifdef _OBJECT_SPACE_
// MSpace::Space SPACE = MSpace::kObject;
// #else//_WORLD_SPACE_
// MSpace::Space SPACE = MSpace::kWorld;
// #endif

const MTypeId RBFJointMapping::typeId(TI_RBF_JOINT_MAPPING);
const MString RBFJointMapping::typeName(TN_RBF_JOINT_MAPPING);


RBFJointMapping::RBFJointMapping()
{
	_LogFunctionCall("RBFJointMapping::RBFJointMapping()");
	pRBF = RBFWapper::getInstance();
	//pEigenPointNode = NULL;
	//numControlPoints = 0;
}

RBFJointMapping::~RBFJointMapping()
{
	_LogFunctionCall("RBFJointMapping::~RBFJointMapping()");
	RBFWapper::getInstance()->destroy();
	pRBF = NULL;
	//pEigenPointNode = NULL;
	//numControlPoints = 0;
}

MSyntax RBFJointMapping::newSyntax()
{
	_LogFunctionCall("RBFJointMapping::newSyntax()");

	MSyntax syn;

// 	IfMErrorWarn(syn.addFlag(kInitFlag, kInitFlagLong));
// 	IfMErrorWarn(syn.addFlag(kUpdateFlag, kUpdateFlagLong));
// 	IfMErrorWarn(syn.addFlag(kUpdateSkeletonFlag, kUpdateSkeletonFlagLong));

	return syn;
}

MStatus RBFJointMapping::parseArgs(const MArgList& args)
{
	_LogFunctionCall("RBFJointMapping::parseArgs()");

	MStatus status;

	MArgDatabase argData(newSyntax(), args, &status);
	IfMErrorWarn(status);

// 	// Parse each argument.
// 	//
// 	fInit = argData.isFlagSet(kInitFlagLong, &status);
// 	IfMErrorWarn(status);
// 	//
// 	fUpdate = argData.isFlagSet(kUpdateFlagLong, &status);
// 	IfMErrorWarn(status);
// 
// 	fUpdateSkeleton = argData.isFlagSet(kUpdateSkeletonFlagLong, &status);
// 	IfMErrorWarn(status);

	printArgs();
	return status;
}
void RBFJointMapping::printArgs()
{
	_LogFunctionCall("RBFJointMapping::printArgs()");

// 	_LogDebug("printArgs:");
// 	_LogDebug("fInit="<<fInit);
// 	_LogDebug("fUpdate="<<fUpdate);
// 	_LogDebug("fUpdateSkeleton="<<fUpdateSkeleton);
}
MStatus RBFJointMapping::doIt ( const MArgList &args )
{ 
	_LogFunctionCall("RBFJointMapping::doIt()");

	MStatus status = parseArgs(args);
	if (status != MS::kSuccess) 
		return status;

	return redoIt();
}

MStatus RBFJointMapping::undoIt()
{
	_LogFunctionCall("RBFJointMapping::undoIt()");

	return dgMod.undoIt();
}


MStatus RBFJointMapping::redoIt()
{
	_LogFunctionCall("RBFJointMapping::redoIt()");

	MStatus stat;

	// init
// 	if(fInit)
// 	{
// 		_init();
// 	}
// 	else if(fUpdate){
// 		_update();
// 		if(fUpdateSkeleton){
// 			_updateSkeleton();
// 		}
// 	}

	_updateSkeleton();

	return MS::kSuccess;
}

MStatus RBFJointMapping::_updateSkeleton()
{
	_LogFunctionCall("RBFJointMapping::_updateSkeleton()");
	MStatus status;

	const MString baseJointRoot("ROOT");
	const MString deformJointRoot("D_"+baseJointRoot);

	//copy base skeleton
	MString cmd;
	cmd = "duplicate -n "+ deformJointRoot +" "+ baseJointRoot+";";
	_LogDebug(cmd.asChar());
	IfMErrorWarn(MGlobal::executeCommand(cmd));

	//deformJointRoot的初始位置与baseJointRoot一致
	_mapJoint(deformJointRoot);

	return MS::kSuccess;
}

MStatus RBFJointMapping::_mapJoint(const MString &joint)
{
	_LogFunctionCall("RBFJointMapping::_mapJoint("<< joint.asChar()<<")");
	MStatus status;

	MString cmd, result;
	MDoubleArray dArray;


	//get old position(World Coordination)
	cmd = "xform -q -ws -rp "+ joint;
	_LogDebug(cmd.asChar());
	IfMErrorWarn(MGlobal::executeCommand(cmd, dArray));
	//IfMErrorWarn(MGlobal::executeCommand(cmd, result, true));
	//_LogDebug("result:"<< result);
	assert(dArray.length()==3);

	Point oldPos(dArray[0], dArray[1], dArray[2]);
	PointArray oldPosA, newPosA;
	printf("old pos: %f, %f, %f\n", dArray[0], dArray[1], dArray[2]);
	printf("oldpos:[%f, %f, %f]\n", oldPos.x, oldPos.y, oldPos.z);
	_LogDebug("oldpos:"<< oldPos );
	oldPosA.append(oldPos);
	newPosA.append(oldPos);//初始化newPosA的数组长度


	//caculate new position(World Coordination)
	// 	RBFWapper::getInstance()->idle(
	// 		controlPointDisplacementX, 
	// 		controlPointDisplacementY,
	// 		controlPointDisplacementZ,
	// 		newPosA,
	// 		oldPosA
	// 		);
	RBFWapper::getInstance()->deformObject( newPosA,oldPosA );
	assert(newPosA.length()==oldPosA.length());
	Point newPos(newPosA[0]);
	_LogDebug("newPos:"<< newPos );

	//set new position(World Coordination)
	char cmdbuf[128];
	sprintf(cmdbuf, "xform -ws -t %f %f %f %s;",newPos.x, newPos.y, newPos.z, joint.asChar());
	_LogDebug(cmdbuf);
	IfMErrorWarn(MGlobal::executeCommand( cmdbuf ));

	//处理joint的子骨骼
	MStringArray sArray;
	cmd = "listRelatives -c -f " + joint +";";//得到joint的子骨骼
	IfMErrorWarn(MGlobal::executeCommand(cmd, sArray));
	_LogDebug(cmd);
	_LogDebug("subJoints:"<<sArray);
	for(size_t i=0; i<sArray.length(); ++i)
	{
		_mapJoint(sArray[i]);
	}


	return MS::kSuccess;
}

MObject RBFJointMapping::getEigenPointNode()
{
	_LogFunctionCall("RBFJointMapping::getEigenPointNode()");

	MStatus status;

	MSelectionList sList;
	IfMErrorWarn(MGlobal::getSelectionListByName("xxRBF1", sList));
	assert(sList.length()==1);

	// 	MDagPath dagPath;
	// 	IfMErrorWarn(sList.getDagPath(0, dagPath));
	// 	MObject dagnode=dagPath.node(&status);
	// 	IfMErrorWarn(status);
	MObject dagnode;
	IfMErrorWarn(sList.getDependNode(0, dagnode));

	//MFnDependencyNode fnNode(dagnode, &status);
	//IfMErrorWarn(status);

	return dagnode;// build error

}
//
//EigenPointNode* RBFJointMapping::getEigenPointNodePtr()
//{
//	_LogFunctionCall("RBFJointMapping::getEigenPointNodePtr()");
//
//	MFnDependencyNode fnNode = getEigenPointNode();
//	EigenPointNode *pNode = dynamic_cast<EigenPointNode*>(fnNode.userNode());
//	assert(pNode!=NULL);
//	return pNode;
//}

MObject RBFJointMapping::getSourceNodeOfPlug( const MFnDependencyNode &fnDNode,const MString &plugname)
{
	_LogFunctionCall("RBFJointMapping::getSourceNodeOfPlug("<< plugname.asChar()<< ")");

	MStatus status;

	MPlug plug = fnDNode.findPlug(plugname, &status);
	IfMErrorWarn(status);

	MPlugArray array;
	plug.connectedTo(array, true, false, &status);
	//_LogDebug("connect count to inMesh plug: "<<array.length());
	assert(array.length()==1);
	MObject srcNode = array[0].node(&status);
	IfMErrorWarn(status);

	return srcNode;
}
MObject RBFJointMapping::getDestinyNodeOfPlug( const MFnDependencyNode &fnDNode,const MString &plugname)
{
	_LogFunctionCall("RBFJointMapping::getDestinyNodeOfPlug("<< plugname.asChar()<< ")");

	MStatus status;

	MPlug plug = fnDNode.findPlug(plugname, &status);
	IfMErrorWarn(status);

	MPlugArray array;
	plug.connectedTo(array,  false, true, &status);
	//_LogDebug("connect count to outMesh plug: "<<array.length());
	assert(array.length()==1);
	MObject srcNode = array[0].node(&status);
	IfMErrorWarn(status);

	return srcNode;
}


void RBFJointMapping::printPointArray(const string& tips, const PointArray& points)
{
	_LogDebug(tips);
	for(size_t i=0; i<points.length(); ++i)
	{
		_LogDebug( "<"<<points[i].x<<", "<<points[i].y<<", "<<points[i].z<<">" );
	}
}
void RBFJointMapping::printPointArray(const string& tips, 
							 const vector<Scalar>& vx,
							 const vector<Scalar>& vy,
							 const vector<Scalar>& vz
							 )
{
	_LogDebug(tips);
	assert(vx.size()==vy.size() && vy.size()==vz.size() && vx.size()!=0);

	for(size_t i=0; i<vx.size(); ++i)
	{
		_LogDebug( "<"<<vx[i]<<", "<<vy[i]<<", "<<vz[i]<<">" );
	}
}

// MStatus RBFJointMapping::getEigenPoints(const MPlug& eigenPointsPlug, PointArray& points)
// {
// 	_LogFunctionCall("RBFJointMapping::getEigenPoints("<< eigenPointsPlug.name().asChar()<<")");
// 	MStatus status;
// 
// 	MObject obj;
// 	IfMErrorWarn( eigenPointsPlug.getValue(obj) );
// 
// 	MFnPointArrayData fn(obj, &status);
// 	IfMErrorWarn(status);
// 
// 	points = fn.array( &status );
// 	IfMErrorWarn(status);
// 
// 	return MS::kSuccess;
// }
MStatus RBFJointMapping::getEigenPoints(const MPlug& eigenPointsPlug, PointArray & points)
{
	MStatus status;

	size_t pointNum = eigenPointsPlug.numElements(&status)/3;
	for(size_t i=0; i<pointNum; ++i)
	{
		Scalar x,y,z;
		MPlug e;

		e = eigenPointsPlug.elementByLogicalIndex(3*i,   &status);
		IfMErrorWarn(status);
		IfMErrorWarn(e.getValue(x));

		e = eigenPointsPlug.elementByLogicalIndex(3*i+1, &status);
		IfMErrorWarn(status);
		IfMErrorWarn(e.getValue(y));

		e = eigenPointsPlug.elementByLogicalIndex(3*i+2, &status);
		IfMErrorWarn(status);
		IfMErrorWarn(e.getValue(z));

		points.append(x, y, z);
		_LogDebug( "point["<< i<<"]=<"<<x<<", "<< y<<", "<< z <<">");
	}



	// 	MFnDoubleArrayData fn(obj, &status);
	// 	IfMErrorWarn(status);
	// 
	// 	points = fn.array( &status );
	// 	IfMErrorWarn(status);

	return MS::kSuccess;
}

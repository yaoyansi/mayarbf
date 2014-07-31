#include "RBFCmd.h"
#include <xxcommon/prerequest_local.h>
#include <xxcommon/mayacheck.h>
#include "rbfcore/RBFWapper.h"
#include "EigenPointsNode.h"
#include "RBFParameterNode.h"
//#include "rbfcore/scalar.h"

#define kInitFlag				"-i"
#define kInitFlagLong			"-init"

#define kUpdateFlag				"-u"
#define kUpdateFlagLong			"-update"

#define kUpdateSkeletonFlag				"-us"
#define kUpdateSkeletonFlagLong			"-updateSkeleton"

#ifdef _OBJECT_SPACE_
	MSpace::Space SPACE = MSpace::kObject;
#else//_WORLD_SPACE_
	MSpace::Space SPACE = MSpace::kWorld;
#endif

const MTypeId RBFCmd::typeId(TI_RBF_CMD);
const MString RBFCmd::typeName(TN_RBF_CMD);

PointArray RBFCmd::meshPoints_original;
//PointArray RBFCmd::meshPoints_target;
PointArray RBFCmd::meshPoints_updated;

std::vector<Scalar> RBFCmd::controlPointDisplacementX;
std::vector<Scalar> RBFCmd::controlPointDisplacementY;
std::vector<Scalar> RBFCmd::controlPointDisplacementZ;

void copy(vector<Scalar> &vx, vector<Scalar> &vy, vector<Scalar> &vz,
		  const PointArray &points);

RBFCmd::RBFCmd()
{
	_LogFunctionCall("RBFCmd::RBFCmd()");
	pRBF = RBFWapper::getInstance();
	//pEigenPointNode = NULL;
	//numControlPoints = 0;
}

RBFCmd::~RBFCmd()
{
	_LogFunctionCall("RBFCmd::~RBFCmd()");
	RBFWapper::getInstance()->destroy();
	pRBF = NULL;
	//pEigenPointNode = NULL;
	//numControlPoints = 0;
}

MSyntax RBFCmd::newSyntax()
{
	_LogFunctionCall("RBFCmd::newSyntax()");

	MSyntax syn;

	IfMErrorWarn(syn.addFlag(kInitFlag, kInitFlagLong));
	IfMErrorWarn(syn.addFlag(kUpdateFlag, kUpdateFlagLong));
	IfMErrorWarn(syn.addFlag(kUpdateSkeletonFlag, kUpdateSkeletonFlagLong));

	return syn;
}

MStatus RBFCmd::parseArgs(const MArgList& args)
{
	_LogFunctionCall("RBFCmd::parseArgs()");

	MStatus status;

	MArgDatabase argData(newSyntax(), args, &status);
	IfMErrorWarn(status);

	// Parse each argument.
	//
	fInit = argData.isFlagSet(kInitFlagLong, &status);
	IfMErrorWarn(status);
	//
	fUpdate = argData.isFlagSet(kUpdateFlagLong, &status);
	IfMErrorWarn(status);
	
	fUpdateSkeleton = argData.isFlagSet(kUpdateSkeletonFlagLong, &status);
	IfMErrorWarn(status);

	printArgs();
	return status;
}
void RBFCmd::printArgs()
{
	_LogFunctionCall("RBFCmd::printArgs()");

	_LogDebug("printArgs:");
	_LogDebug("fInit="<<fInit);
	_LogDebug("fUpdate="<<fUpdate);
	_LogDebug("fUpdateSkeleton="<<fUpdateSkeleton);
}
MStatus RBFCmd::doIt ( const MArgList &args )
{ 
	_LogFunctionCall("RBFCmd::doIt()");

	MStatus status = parseArgs(args);
	if (status != MS::kSuccess) 
		return status;

	return redoIt();
}

MStatus RBFCmd::undoIt()
{
	_LogFunctionCall("RBFCmd::undoIt()");

	return dgMod.undoIt();
}


MStatus RBFCmd::redoIt()
{
	_LogFunctionCall("RBFCmd::redoIt()");

	MStatus stat;

	// init
	if(fInit)
	{
		_init();
	}
	else if(fUpdate){
		_update();
		if(fUpdateSkeleton){
			_updateSkeleton();
		}
	}

	return MS::kSuccess;
}

MStatus RBFCmd::_init()
{
	_LogFunctionCall("RBFCmd::_init()");

	MStatus status = MStatus::kSuccess;

	MFnDependencyNode eigenPointsNode(getEigenPointNode(), &status);
	IfMErrorWarn(status);

	//MObject targetMeshNode = getSourceNodeOfPlug(eigenPointsNode, "iTargetMesh");##
	MObject inMeshNode = getSourceNodeOfPlug(eigenPointsNode, "iBaseMesh");

	MDagPath inMeshNodePath;
	IfMErrorWarn(MDagPath::getAPathTo(inMeshNode, inMeshNodePath));

	//get mesh points (target)
	MFnMesh mesh(inMeshNodePath, &status);
	IfMErrorWarn(status);
	IfMErrorWarn(mesh.getPoints(meshPoints_original, SPACE));	

	// initialize meshPoints_target_updated
	IfMErrorWarn(mesh.getPoints(meshPoints_updated, SPACE));

	// update new eigen points
	// EigenPointNode::PointIndex_Target里的点
	// --> eigenPoints_target --> vx, vy, vz --> RBFWapper
	MPlug plg(eigenPointsNode.findPlug(EigenPointNode::PointIndex_Base, &status));
	IfMErrorWarn(status);
	PointArray eigenPoints_original;
	getEigenPoints(plg, eigenPoints_original);
	assert(eigenPoints_original.length()>0);
	vector<Scalar> vx, vy, vz;
	copy(vx, vy, vz, eigenPoints_original);
	//初始化特征点的坐标
	RBFWapper::getInstance()->updateControlPoints(vx, vy, vz);

	// allocate control Point Displacement array
	controlPointDisplacementX.clear();
	controlPointDisplacementY.clear();
	controlPointDisplacementZ.clear();
	for (unsigned int i = 0; i<eigenPoints_original.length();  i++)
	{
		controlPointDisplacementX.push_back(0.0f);
		controlPointDisplacementY.push_back(0.0f);
		controlPointDisplacementZ.push_back(0.0f);
	}
	//update control Point Displacement
	RBFType f;
	double constant;
	getRBFTypeParameters(f, constant);
	RBFWapper::getInstance()->initInterpolationFunction(
		controlPointDisplacementX,
		controlPointDisplacementY,
		controlPointDisplacementZ,
		f, constant
	);

	return MStatus::kSuccess;

}
//deform from base to target.
MStatus RBFCmd::_update()
{
	_LogFunctionCall("RBFCmd::_update()");
	MStatus status;

	MFnDependencyNode eigenPointsNode(getEigenPointNode(), &status);
	IfMErrorWarn(status);	

	// move control points
	MPlug plg;
	PointArray eigenPoints_target, eigenPoints_base;

	plg = eigenPointsNode.findPlug(EigenPointNode::PointIndex_Target, &status);
	IfMErrorWarn(status);
	getEigenPoints(plg, eigenPoints_target);

	plg = eigenPointsNode.findPlug(EigenPointNode::PointIndex_Base, &status);
	IfMErrorWarn(status);
	getEigenPoints(plg, eigenPoints_base);

	assert(eigenPoints_base.length()==eigenPoints_target.length() && eigenPoints_base.length()>0);
	for (unsigned int i = 0; i<eigenPoints_base.length(); i++ )
	{
		MVector offset(getOffset(eigenPoints_base[i], eigenPoints_target[i]));//deform from base to target.

		controlPointDisplacementX[i] = offset.x;
		controlPointDisplacementY[i] = offset.y;
		controlPointDisplacementZ[i] = offset.z;
	}
	//printPointArray("control Point Displacement", controlPointDisplacementX,controlPointDisplacementY,controlPointDisplacementZ);
// 	RBFType f;
// 	double constant;
// 	getRBFTypeParameters(f, constant);
	// update the control points based on the new control point positions
	RBFWapper::getInstance()->idle(
		controlPointDisplacementX, 
		controlPointDisplacementY,
		controlPointDisplacementZ,
		meshPoints_updated,
		meshPoints_original
		//, f, constant
		);
	//printPointArray("meshPoints_target_updated:", meshPoints_target_updated);
	updateToMesh(meshPoints_updated);

	return MStatus::kSuccess;
}
MStatus RBFCmd::_updateSkeleton()
{
	_LogFunctionCall("RBFCmd::_updateSkeleton()");
	MStatus status;

	const MString baseJointRoot("ROOT");
	const MString deformJointRoot(baseJointRoot+"_deformed");

	//copy base skeleton
	MString cmd;
	cmd = "duplicate -n "+ deformJointRoot +" "+ baseJointRoot+";";
	_LogDebug(cmd.asChar());
	IfMErrorWarn(MGlobal::executeCommand(cmd));

	//deformJointRoot的初始位置与baseJointRoot一致
	_mapJoint(baseJointRoot, deformJointRoot);

	return MS::kSuccess;
}
// void getJointPoint(const MString& root, PointArray &pointArray)
// {
// 	MString cmd, result;
// 	MDoubleArray dArray;
// 	cmd = "xform -q -ws -rp "+ root;
// 	_LogDebug(cmd.asChar());
// 	IfMErrorWarn(MGlobal::executeCommand(cmd, dArray));
// 	assert(dArray.length()==3);
// 
// 	Point pos(dArray[0], dArray[1], dArray[2]);
// 	pointArray.append(pos);
// 
// 	MStringArray sArray;
// 	cmd = "listRelatives -c -f " + root +";";//得到joint的子骨骼
// 	IfMErrorWarn(MGlobal::executeCommand(cmd, sArray));
// 	_LogDebug(cmd);
// 	_LogDebug("subJoints:"<<sArray);
// 	for(size_t i=0; i<sArray.length(); ++i)
// 	{
// 		getJointPoint(sArray[i], pointArray);
// 	}
// }
MStatus RBFCmd::_mapJoint(const MString& original, const MString& deformed)
{
	_LogFunctionCall("RBFCmd::_mapJoint("<< original.asChar() <<","<< deformed.asChar()<<")");
	MStatus status;

	MString cmd, result;
	MDoubleArray dArray;


	//get old position(World Coordination)
	cmd = "xform -q -ws -rp "+ original;
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
	sprintf(cmdbuf, "xform -ws -t %f %f %f %s;",newPos.x, newPos.y, newPos.z, deformed.asChar());
	_LogDebug(cmdbuf);
	IfMErrorWarn(MGlobal::executeCommand( cmdbuf ));


	//处理子骨骼
	MStringArray subJointOfOriginal, subJointOfDeformed;
	cmd = "listRelatives -c -f " + original +";";//得到original的子骨骼
	IfMErrorWarn(MGlobal::executeCommand(cmd, subJointOfOriginal));
	_LogDebug(cmd);
	_LogDebug("subJointsOfOriginal:"<<subJointOfOriginal);
	cmd = "listRelatives -c -f " + deformed +";";//得到deformed的子骨骼
	IfMErrorWarn(MGlobal::executeCommand(cmd, subJointOfDeformed));
	_LogDebug(cmd);
	_LogDebug("subJointsOfOriginal:"<<subJointOfDeformed);
	assert(subJointOfOriginal.length()==subJointOfDeformed.length());
	for(size_t i=0; i<subJointOfOriginal.length(); ++i)
	{
		_mapJoint(subJointOfOriginal[i], subJointOfDeformed[i]);
	}


	return MS::kSuccess;
}

MObject RBFCmd::getEigenPointNode()
{
	_LogFunctionCall("RBFCmd::getEigenPointNode()");

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
//EigenPointNode* RBFCmd::getEigenPointNodePtr()
//{
//	_LogFunctionCall("RBFCmd::getEigenPointNodePtr()");
//
//	MFnDependencyNode fnNode = getEigenPointNode();
//	EigenPointNode *pNode = dynamic_cast<EigenPointNode*>(fnNode.userNode());
//	assert(pNode!=NULL);
//	return pNode;
//}

MObject RBFCmd::getSourceNodeOfPlug( const MFnDependencyNode &fnDNode,const MString &plugname)
{
	_LogFunctionCall("RBFCmd::getSourceNodeOfPlug("<< plugname.asChar()<< ")");

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
MObject RBFCmd::getDestinyNodeOfPlug( const MFnDependencyNode &fnDNode,const MString &plugname)
{
	_LogFunctionCall("RBFCmd::getDestinyNodeOfPlug("<< plugname.asChar()<< ")");

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

MVector RBFCmd::getOffset(const MVector& from, const MVector& to)
{
	return (to - from);
}

MStatus RBFCmd::updateToMesh( PointArray &updated )
{
	_LogFunctionCall("RBFCmd::updateToBaseMesh()");
	MStatus status;

	MFnDependencyNode eigenPointsNode(getEigenPointNode(), &status);
	IfMErrorWarn(status);

	MObject deformNode = getDestinyNodeOfPlug(eigenPointsNode, EigenPointNode::odummy);
	
	MDagPath deformNodePath;
	IfMErrorWarn(MDagPath::getAPathTo(deformNode, deformNodePath));
	
	MFnMesh mesh(deformNodePath, &status);
	IfMErrorWarn(status);

	if(updated.length()!=mesh.numVertices()){
		_LogError("updated.length()="<<updated.length() <<", mesh.numVertices()="<< mesh.numVertices());
		assert(0&&"updated.length()!=mesh.numVertices()");
	}

	IfMErrorWarn(mesh.setPoints(updated, SPACE));
	return MS::kSuccess;
}
void RBFCmd::printPointArray(const string& tips, const PointArray& points)
{
	_LogDebug(tips);
	for(size_t i=0; i<points.length(); ++i)
	{
		_LogDebug( "<"<<points[i].x<<", "<<points[i].y<<", "<<points[i].z<<">" );
	}
}
void RBFCmd::printPointArray(const string& tips, 
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

// MStatus RBFCmd::getEigenPoints(const MPlug& eigenPointsPlug, PointArray& points)
// {
// 	_LogFunctionCall("RBFCmd::getEigenPoints("<< eigenPointsPlug.name().asChar()<<")");
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
MStatus RBFCmd::getEigenPoints(const MPlug& eigenPointsPlug, PointArray & points)
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
void copy(vector<Scalar> &vx, vector<Scalar> &vy, vector<Scalar> &vz,
		  const PointArray &points)
{
	vx.clear();
	vy.clear();
	vz.clear();

	for(size_t i=0; i<points.length(); ++i)
	{
		vx.push_back(points[i].x);
		vy.push_back(points[i].y);
		vz.push_back(points[i].z);
	}
}

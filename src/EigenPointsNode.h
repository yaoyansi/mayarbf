#ifndef _EIGENPOINTNODE_
#define _EIGENPOINTNODE_


#include <xxcommon/prerequest_maya.h>
#include <xxcommon/prerequest_std.h>
#include "rbfcore/scalar.h"
#include <xxcommon/PlugNameMacro.h>



class EigenPointNode 
	:
	//public MPxNode
	public MPxLocatorNode
{
public:
	PLUGNAME_DECLARE(PointIndex_Base,	pib);
	PLUGNAME_DECLARE(PointIndex_Target, pit);
	PLUGNAME_DECLARE(iBaseMesh,			ibm);
	PLUGNAME_DECLARE(iTargetMesh,		itm);
	PLUGNAME_DECLARE(oMesh,				om);
	PLUGNAME_DECLARE(odummy,			od);

public:
	EigenPointNode();
	virtual ~EigenPointNode();
	static void addedCallback(MObject& node, void *clientData);
	static void removedCallback(MObject& node, void *clientData);

	static void *creator();
	static MStatus initialize();
	virtual void draw( M3dView&, const MDagPath&, M3dView::DisplayStyle,
		M3dView::DisplayStatus);
	virtual MStatus compute (const MPlug &plug, MDataBlock &dataBlock);
	//MStatus init();
	//MStatus getValue(const MObject& EigenPointPlug, PointArray& points);	
	MStatus getValue(const MObject& EigenPointPlug, MDoubleArray & points);
	//PointArray eigenPointArray_base, eigenPointArray_target;

public:
	static const MTypeId typeId;
	static const MString typeName;

	static  MObject ia_EigenPointIndex_Base;
	static  MObject ia_EigenPointIndex_Target;

	static  MObject i_BaseMesh;
	static  MObject i_TargetMesh;
	
	static  MObject o_Mesh;
	static  MObject o_dummy_bool;

protected:
	void _destruct();
	void _init_on1stFrame();
// 	MPoint getVertexPoint_base(const size_t eginPointIndex, const MPlug &plug, MDataBlock &data);
// 	MPoint getVertexPoint_target(const size_t eginPointIndex, const MPlug &plug, MDataBlock &data);
// 	int getVertexIndex(const size_t eigenPointIndex, MObject &eigenPointIndexArray,
// 		const MPlug &plug, MDataBlock &data);
// 	MObject getSourceNodeOfPlug(const MString &plugname);

protected:
	MTime m_prevTime;


};

#endif //_EIGENPOINTNODE_
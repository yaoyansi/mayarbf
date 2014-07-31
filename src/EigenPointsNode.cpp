#include "EigenPointsNode.h"
#include <xxcommon/prerequest_local.h>
#include <xxcommon/prerequest_ogl.h>
#include <xxcommon/mayacheck.h>


const MTypeId EigenPointNode::typeId( TI_RBF_FACE_ANIMATION );
const MString EigenPointNode::typeName(TN_RBF_FACE_ANIMATION);
//MObject EigenPointNode::i_time;
MObject EigenPointNode::ia_EigenPointIndex_Base;
MObject EigenPointNode::ia_EigenPointIndex_Target;
MObject EigenPointNode::i_BaseMesh;
MObject EigenPointNode::i_TargetMesh;
MObject EigenPointNode::o_Mesh;
MObject EigenPointNode::o_dummy_bool;

PLUGNAME_IMPLEMENT(EigenPointNode,	PointIndex_Base,	pib);
PLUGNAME_IMPLEMENT(EigenPointNode,	PointIndex_Target,	pit);
PLUGNAME_IMPLEMENT(EigenPointNode,	iBaseMesh,			ibm);
PLUGNAME_IMPLEMENT(EigenPointNode,	iTargetMesh,		itm);
PLUGNAME_IMPLEMENT(EigenPointNode,	oMesh,				om);
PLUGNAME_IMPLEMENT(EigenPointNode,	odummy,				od);

EigenPointNode::EigenPointNode()
{
	_LogFunctionCall("EigenPointNode::EigenPointNode()");
}

EigenPointNode::~EigenPointNode()
{
	_LogFunctionCall("EigenPointNode::~EigenPointNode()");
}
//
void EigenPointNode::addedCallback(MObject& node, void *clientData)
{	
	_LogFunctionCall("EigenPointNode::addedCallback()");
}

void EigenPointNode::removedCallback(MObject& node, void *clientData)
{
	_LogFunctionCall("EigenPointNode::removedCallback()");
}
void* EigenPointNode::creator()
{
	_LogFunctionCall("EigenPointNode::creator()");

	return new EigenPointNode();
}

void EigenPointNode::_init_on1stFrame()
{
	_LogFunctionCall("EigenPointNode::_init_on1stFrame()");
	m_prevTime = 0.0;
}

void EigenPointNode::_destruct()
{
	_LogFunctionCall("EigenPointNode::_destruct()");
}

MStatus EigenPointNode::initialize()
{
	_LogFunctionCall("EigenPointNode::initialize()");

	MStatus status;
	MFnUnitAttribute uAttr;	
	MFnNumericAttribute nAttr;
	MFnTypedAttribute tAttr;

	ia_EigenPointIndex_Base = nAttr.create( PointIndex_Base, pib, MFnNumericData::kDouble, 0.0, &status );
	//ia_EigenPointIndex_Base = tAttr.create( PointIndex_Base, pib, MFnPointArrayData::kPoint, &status );
	IfMErrorWarn(status);
	IfMErrorWarn(nAttr.setArray(true));
	IfMErrorWarn(nAttr.setConnectable(true));
	IfMErrorWarn(nAttr.setWritable(true));
	IfMErrorWarn(nAttr.setStorable(false));
	IfMErrorWarn(nAttr.setChannelBox(true));
	IfMErrorWarn(nAttr.setKeyable(false));
	IfMErrorWarn(nAttr.setUsesArrayDataBuilder(true));
	IfMErrorWarn(addAttribute(ia_EigenPointIndex_Base));

	ia_EigenPointIndex_Target = nAttr.create( PointIndex_Target, pit, MFnNumericData::kDouble, 0.0, &status );
	//ia_EigenPointIndex_Target = tAttr.create( PointIndex_Target, pit, MFnPointArrayData::kPointArray, &status );
	IfMErrorWarn(status);
	IfMErrorWarn(nAttr.setArray(true));
	IfMErrorWarn(nAttr.setConnectable(true));
	IfMErrorWarn(nAttr.setWritable(true));
	IfMErrorWarn(nAttr.setStorable(false));
	IfMErrorWarn(nAttr.setChannelBox(true));
	IfMErrorWarn(nAttr.setKeyable(false));
	IfMErrorWarn(nAttr.setUsesArrayDataBuilder(true));
	IfMErrorWarn(addAttribute(ia_EigenPointIndex_Target));

	i_BaseMesh = tAttr.create(iBaseMesh, ibm, MFnData::kMesh, MObject::kNullObj, &status);
	IfMErrorWarn(status);
	IfMErrorWarn(tAttr.setConnectable(true));
	IfMErrorWarn(tAttr.setWritable(true));
	IfMErrorWarn(addAttribute(i_BaseMesh));

	i_TargetMesh = tAttr.create(iTargetMesh, itm, MFnData::kMesh, MObject::kNullObj, &status);
	IfMErrorWarn(status);
	IfMErrorWarn(tAttr.setConnectable(true));
	IfMErrorWarn(tAttr.setWritable(true));
	IfMErrorWarn(addAttribute(i_TargetMesh));

	//
	o_Mesh = tAttr.create(oMesh, om, MFnData::kMesh, MObject::kNullObj, &status);
	IfMErrorWarn(status);
	IfMErrorWarn(tAttr.setConnectable(true));
	IfMErrorWarn(tAttr.setWritable(true));
	IfMErrorWarn(addAttribute(o_Mesh));

	o_dummy_bool= nAttr.create( odummy, od, MFnNumericData::kBoolean, true, &status );;
	IfMErrorWarn(status);
	IfMErrorWarn(tAttr.setConnectable(true));
	IfMErrorWarn(tAttr.setWritable(true));
	IfMErrorWarn(addAttribute(o_dummy_bool));

	IfMErrorWarn(attributeAffects(i_BaseMesh,					o_Mesh ));
	IfMErrorWarn(attributeAffects(i_TargetMesh,					o_Mesh ));
	IfMErrorWarn(attributeAffects(ia_EigenPointIndex_Base,		o_Mesh ));
	IfMErrorWarn(attributeAffects(ia_EigenPointIndex_Target,	o_Mesh ));
	IfMErrorWarn(attributeAffects(i_BaseMesh,					o_dummy_bool ));
	IfMErrorWarn(attributeAffects(i_TargetMesh,					o_dummy_bool ));
	IfMErrorWarn(attributeAffects(ia_EigenPointIndex_Base,		o_dummy_bool ));
	IfMErrorWarn(attributeAffects(ia_EigenPointIndex_Target,	o_dummy_bool ));

	return MS::kSuccess;
}
// MStatus EigenPointNode::getValue(const MObject& EigenPointPlug, PointArray& points)
// {
// 	MStatus status;
// 
// 	MObject obj;
// 
// 	MPlug plg(thisMObject(), EigenPointPlug);
// 	IfMErrorWarn(plg.getValue(obj));
// 
// 	MFnPointArrayData fn(obj, &status);
// 	IfMErrorWarn(status);
// 
// 	points = fn.array( &status );
// 	IfMErrorWarn(status);
// 
// 	return MS::kSuccess;
// }
MStatus EigenPointNode::getValue(const MObject& EigenPointPlug, MDoubleArray & points)
{
	MStatus status;
	
	MObject obj;

	MPlug plg(thisMObject(), EigenPointPlug);
	IfMErrorWarn(plg.getValue(obj));

	MFnDoubleArrayData fn(obj, &status);
	IfMErrorWarn(status);

	points = fn.array( &status );
	IfMErrorWarn(status);

	return MS::kSuccess;
}

MStatus EigenPointNode::compute(const MPlug &plug, MDataBlock &data)
{
	_LogFunctionCall("EigenPointNode::compute("<< plug.name().asChar()<< ")");

	MStatus status;

	if( !(plug == o_Mesh) && !(plug == o_dummy_bool))
		return( MS::kUnknownParameter );

// 	PointArray points_base;
// 	getValue(ia_EigenPointIndex_Base, points_base);
// 	PointArray points_target;
// 	getValue(ia_EigenPointIndex_Target, points_target);
// 
// 
// 	const size_t nElems_base = points_base.length();
// 	const size_t nElems_target = points_target.length();
// 
// 	_LogDebug("nElems_base="<<nElems_base<<", "<<"nElems_target="<<nElems_target);
// 	assert(nElems_base==nElems_target && "nElems_base!=nElems_target");


// 	const size_t nEigenPointNum = nElems_base;
// 	eigenPointArray_base.clear();
// 	eigenPointArray_target.clear();
// 	for(size_t i=0; i< nEigenPointNum; ++i)
// 	{
// 		Point eigenPoint_base(getVertexPoint_base(i,  plug, data));
// 		Point eigenPoint_target(getVertexPoint_target(i, plug, data));
// 
// 		eigenPointArray_base.append(eigenPoint_base);
// 		eigenPointArray_target.append(eigenPoint_target);
// 	}

	return MS::kSuccess;
}
void EigenPointNode::draw( M3dView& view,
							const MDagPath& DGpath,
							M3dView::DisplayStyle dstyle,
							M3dView::DisplayStatus dstatus )
{
	//_LogFunctionCall("EigenPointNode::draw()");
	MStatus status;

 	view.beginGL();	
 	glPushAttrib( GL_CURRENT_BIT );
		glBegin(GL_LINES);
		glColor3f( 1.0f, 0.0f, 0.0f );
		glVertex3f( 0.0f, 0.0f, 0.0f );
		glVertex3f( 3.0f, 0.0f, 0.0f );

		glColor3f( 0.0f, 1.0f, 0.0f );
		glVertex3f( 0.0f, 0.0f, 0.0f );
		glVertex3f( 0.0f, 3.0f, 0.0f );

		glColor3f( 0.0f, 0.0f, 1.0f );
		glVertex3f( 0.0f, 0.0f, 0.0f );
		glVertex3f( 0.0f, 0.0f, 3.0f );
		glEnd();
 	glPopAttrib();
 	view.endGL();
}
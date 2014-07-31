#include "RBFParameterNode.h"
#include <xxcommon/prerequest_local.h>
#include <xxcommon/prerequest_std.h>
#include <xxcommon/mayacheck.h>
#include "rbfcore/RBFType.h"


const MTypeId RBFParameterNode::typeId( TI_RBF_PARAMETER );
const MString RBFParameterNode::typeName( TN_RBF_PARAMETER );

MObject RBFParameterNode::m_RBFType;
MObject RBFParameterNode::m_RBFConstant;

PLUGNAME_IMPLEMENT(RBFParameterNode,	type,	t );
PLUGNAME_IMPLEMENT(RBFParameterNode,	constant, cnst );

static void drawWireCuboctahedron(void);

void getRBFTypeParameters(RBFType &f, double &constant);
//
RBFParameterNode::RBFParameterNode()
{
	_LogFunctionCall("RBFParameterNode::RBFParameterNode()");

}

RBFParameterNode::~RBFParameterNode()
{
	_LogFunctionCall("RBFParameterNode::~RBFParameterNode()");
	this->_destruct();
}

void RBFParameterNode::removedCallback(MObject& node, void *clientData)
{
	_LogFunctionCall("RBFParameterNode::removedCallback()");

	MFnDependencyNode fnNode(node);
	RBFParameterNode *this_ = static_cast<RBFParameterNode*>(fnNode.userNode());
	assert(this_!=NULL);
	this_->_destruct();
}
void RBFParameterNode::_destruct()
{
	_LogFunctionCall("RBFParameterNode::_destruct()");
}
//
void RBFParameterNode::draw( M3dView& view,
					   const MDagPath& DGpath,
					   M3dView::DisplayStyle style,
					   M3dView::DisplayStatus status )
{

	//_LogFunctionCall("RBFParameterNode::draw()");

	view.beginGL();
	glPushAttrib( GL_CURRENT_BIT );
		//
		glColor3f(1.0f, 0.0f, 1.0f);
		glutWireCube(3.0f);

	glPopAttrib();
	view.endGL();
}
//
// bool RBFParameterNode::isBounded() const
// {
// 	_LogFunctionCall("RBFParameterNode::isBounded()");
// 	return true;
// }
// 
// //------------------------------------------------------------------------
// /// \brief	returns the bounding box of the locator node
// /// \return	the nodes bounding box
// ///
// MBoundingBox RBFParameterNode::boundingBox() const
// {
// 	_LogFunctionCall("RBFParameterNode::boundingBox()");
// 
// 	float fSize = 1.0f,fHeight=1.0f;
// 
// 	// expand the bounding box to fit all axes of the locator node
// 	MBoundingBox bbox;
// 
// 	bbox.expand( MPoint( -0.5f*fSize, 0.0f, 0.0f ) );
// 	bbox.expand( MPoint(  0.5f*fSize, 0.0f, 0.0f ) );
// 
// 	bbox.expand( MPoint(  0.0f,-0.5f*fHeight,  0.0f ) );
// 	bbox.expand( MPoint(  0.0f, 0.5f*fHeight,  0.0f ) );
// 
// 	bbox.expand( MPoint(  0.0f, 0.0f, -0.5f*fSize ) );
// 	bbox.expand( MPoint(  0.0f, 0.0f,  0.5f*fSize ) );
// 
// 	return bbox;
// }

//
void* RBFParameterNode::creator()
{
	_LogFunctionCall("RBFParameterNode::creator()");
	return new RBFParameterNode();
}
//
MStatus RBFParameterNode::initialize()
{
	_LogFunctionCall("RBFParameterNode::initialize()");

	MStatus status;	

	MFnUnitAttribute uAttr;	
	MFnNumericAttribute nAttr;


	m_RBFType = nAttr.create( type, t, MFnNumericData::kInt, 0, &status );
	IfMErrorWarn(status);
	IfMErrorWarn(nAttr.setStorable(true));
	IfMErrorWarn(nAttr.setKeyable(false));
	IfMErrorWarn(addAttribute(m_RBFType));

	m_RBFConstant = nAttr.create( constant, cnst, MFnNumericData::kDouble, 0, &status );
	IfMErrorWarn(status);
	IfMErrorWarn(nAttr.setStorable(true));
	IfMErrorWarn(nAttr.setKeyable(false));
	IfMErrorWarn(addAttribute(m_RBFConstant));

	return MS::kSuccess;
}
//
#define RADIUS    1.0f
void drawWireCuboctahedron(void)
{
	_LogFunctionCall("drawWireCuboctahedron()");

	glBegin( GL_LINE_LOOP );
	glNormal3d( 1.0, 0.0, 0.0 ); glVertex3d( RADIUS, RADIUS, 0.0 ); glVertex3d( RADIUS, 0.0, RADIUS ); glVertex3d( RADIUS,-RADIUS, 0.0 ); glVertex3d( RADIUS, 0.0,-RADIUS );
	glEnd();
	glBegin( GL_LINE_LOOP );
	glNormal3d(-1.0, 0.0, 0.0 ); glVertex3d(-RADIUS, RADIUS, 0.0 ); glVertex3d(-RADIUS, 0.0,-RADIUS ); glVertex3d(-RADIUS,-RADIUS, 0.0 ); glVertex3d(-RADIUS, 0.0, RADIUS );
	glEnd();
	glBegin( GL_LINE_LOOP );
	glNormal3d( 0.0, 1.0, 0.0 ); glVertex3d( RADIUS, RADIUS, 0.0 ); glVertex3d( 0.0, RADIUS,-RADIUS ); glVertex3d(-RADIUS, RADIUS, 0.0 ); glVertex3d( 0.0, RADIUS, RADIUS );
	glEnd();
	glBegin( GL_LINE_LOOP );
	glNormal3d( 0.0,-1.0, 0.0 ); glVertex3d( RADIUS,-RADIUS, 0.0 ); glVertex3d( 0.0,-RADIUS, RADIUS ); glVertex3d(-RADIUS,-RADIUS, 0.0 ); glVertex3d( 0.0,-RADIUS,-RADIUS );
	glEnd();
	glBegin( GL_LINE_LOOP );
	glNormal3d( 0.0, 0.0, 1.0 ); glVertex3d( RADIUS, 0.0, RADIUS ); glVertex3d( 0.0, RADIUS, RADIUS ); glVertex3d(-RADIUS, 0.0, RADIUS ); glVertex3d( 0.0,-RADIUS, RADIUS );
	glEnd();
	glBegin( GL_LINE_LOOP );
	glNormal3d( 0.0, 0.0,-1.0 ); glVertex3d( RADIUS, 0.0,-RADIUS ); glVertex3d( 0.0,-RADIUS,-RADIUS ); glVertex3d(-RADIUS, 0.0,-RADIUS ); glVertex3d( 0.0, RADIUS,-RADIUS );
	glEnd();
}

//-----------------------------------------------------------------------------
void getRBFTypeParameters(RBFType &f, double &constant)
{
	_LogFunctionCall("getRBFTypeParameters()");

	//RBF parameter node exists.
	int exist = 0;
	MString cmd;
	cmd = "objExists "+ MString(TN_RBF_PARAMETER) +"1;";
	_LogDebug(cmd);
	IfMErrorWarn(MGlobal::executeCommand(cmd, exist ));
	if( exist != 1 ){
		_LogDebug(TN_RBF_PARAMETER<<"1 not exist.");
		assert(exist && "RBF parameter node NOT exist.");
		return;
	}

	//get RBF type
	int f_ret;
	cmd = "getAttr "+ MString(TN_RBF_PARAMETER) +"1."+ RBFParameterNode::type +";";
	_LogDebug(cmd);
	IfMErrorWarn(MGlobal::executeCommand(cmd, f_ret ));


	// get RBF constant parameter
	double c_ret;
	cmd = "getAttr "+ MString(TN_RBF_PARAMETER) +"1."+ RBFParameterNode::cnst +";";
	_LogDebug(cmd);
	IfMErrorWarn(MGlobal::executeCommand(cmd, c_ret ));


	f = (RBFType)f_ret;
	constant = c_ret;

	_LogDebug("RBFTypeParameter: function type:"<< f<<", c="<< constant);

}
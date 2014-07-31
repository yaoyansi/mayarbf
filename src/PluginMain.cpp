//#include "prerequest.h"
#include <xxcommon/prerequest_ogl.h>
#include <xxcommon/prerequest_local.h>
#include <xxcommon/mayacheck.h>
#include <maya/MFnPlugin.h>
#include <maya/MGlobal.h>

#include "EigenPointsNode.h"
#include "RBFCmd.h"
#include "RBFParameterNode.h"
#include "RBFJointMapping.h"
// #include "BasicHwShaderBehavior.h"
// #include "ownerEmitter.h"


// required to link the libraries under VisualC++/Win32
#ifdef WIN32
// 	#pragma comment(lib,"Foundation.lib")
// 	#pragma comment(lib,"OpenMaya.lib")
// 	#pragma comment(lib,"OpenMayaFx.lib")
// 	#pragma comment(lib,"OpenMayaUi.lib")
// 	#pragma comment(lib,"Image.lib")
// 	#pragma comment(lib,"OpenMayaAnim.lib")
// 	#pragma comment(lib,"OpenGl32.lib")
// 	#pragma comment(lib,"glu32.lib")
// 	#pragma comment(lib,"glut32.lib")
#endif

// under WIN32 we have to 'export' these functions so that they are visible
// inside the dll. If maya can't see the functions, it can't load the plugin!
#ifdef WIN32
	#define EXPORT __declspec(dllexport)
#else 
	#define EXPORT
#endif


/// \brief	This function is called once when our plugin is loaded. We can use
///			it to register any custom nodes, mel functions etc.
/// \param	obj	-	a handle to the loaded plugin
/// \return	an MStatus error code
///
EXPORT MStatus initializePlugin( MObject obj )
{
	BOOL ret = AllocConsole();
	freopen("CONOUT$","w+t",stdout);

	_LogFunctionCall("initializePlugin()");
	
	init_logs("e:/tmp/rbf.log");
	MStatus   status;

	// a classification for where the node will appear on the create menus
	// of the multilister and hypershade.
	const MString UserClassify( "shader/surface" );

	MFnPlugin plugin( obj, "Rob Bateman", "1.0", "Any");

// 	// register the hardware shader
// 	status = plugin.registerNode(BasicHwShader::typeName,
// 								 BasicHwShader::typeId,
// 								 BasicHwShader::creator,
// 								 BasicHwShader::initialize,
// 								 MPxNode::kHwShaderNode, &UserClassify );
// 	if( status != MS::kSuccess ) {
// 		IfMErrorMsgWarn(status, "The Basic Hw Shader node could not be registered");
// 		return status;
// 	}
// 	// register the node connection behaviour
// 	status = plugin.registerDragAndDropBehavior("basicHwShaderBehaviour",BasicHwShaderBehavior::creator);
// 	IfMErrorWarn(status);

// 	//
	status = plugin.registerNode( 
		EigenPointNode::typeName, 
		EigenPointNode::typeId,
		EigenPointNode::creator,
		EigenPointNode::initialize,
		MPxNode::kLocatorNode );
	IfMErrorMsgReturn(status, "regist EigenPointNode error.", status);

	//
	status = plugin.registerCommand( 
		RBFCmd::typeName, 
		RBFCmd::creator, 
		RBFCmd::newSyntax);
	IfMErrorMsgReturn(status, "regist RBFCmd error.", status);

	//
	status = plugin.registerNode( 
		RBFParameterNode::typeName, 
		RBFParameterNode::typeId,
		RBFParameterNode::creator,
		RBFParameterNode::initialize,
		MPxNode::kLocatorNode );
	IfMErrorMsgReturn(status, "regist RBFParameterNode error.", status);

	//
	status = plugin.registerCommand( 
		RBFJointMapping::typeName, 
		RBFJointMapping::creator , 
		RBFJointMapping::newSyntax);
	IfMErrorMsgReturn(status, "regist RBFJointMapping error.", status);

	//
	MGlobal::executeCommand("source \"rbfMain.mel\";");

	return status;
}

/// \brief	This function is called once when our plugin is unloaded. We need
/// 		to tell maya which mel funcs, nodes etc we are removing.
/// \param	obj	-	a handle to the loaded plugin
/// \return	an MStatus error code
///
EXPORT MStatus uninitializePlugin( MObject obj)
{
	_LogFunctionCall("uninitializePlugin()");

	MStatus   status;
	MFnPlugin plugin( obj );

	//
	status = plugin.deregisterNode( EigenPointNode::typeId );
	IfMErrorMsgReturn(status, "deregist EigenPointNode error.", status);

	 status = plugin.deregisterCommand( RBFCmd::typeName );
	IfMErrorMsgReturn(status, "deregist RBFCmd error.", status);

	status = plugin.deregisterNode( RBFParameterNode::typeId );
	IfMErrorMsgReturn(status, "deregist RBFParameterNode error.", status);

	status = plugin.deregisterCommand( RBFJointMapping::typeName );
	IfMErrorMsgReturn(status, "deregist RBFJointMapping error.", status);

	close_logs();
	BOOL ret = FreeConsole();
	return status;
}

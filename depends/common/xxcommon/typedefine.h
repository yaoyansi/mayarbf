#ifndef _TYPE_DEFINE_
#define _TYPE_DEFINE_

// For plug-ins that will forever be internal to your site use the constructor 
// that takes a single unsigned int parameter. The numeric range 0 - 0x7ffff (524288 ids)
// has been reserved for such plug-ins.
// 
// The example plug-ins provided with Maya in the plug-in development kit will use ids
// in the range 0x80000 - 0xfffff (524288 ids). If you customize one of these example 
// plug-ins, you should change the id to avoid future conflicts.
// 
// Plug-ins that are intended to be shared between sites will need to have a globally 
// unique id. The Autodesk Developer Network (ADN) will provide such id's in blocks of 
// 256. You will be assigned one or more 24-bit prefixes. Once this has been obtained, 
// used the MTypeId constructor that takes 2 unsigned int parameters. The prefix goes in
// the first parameter, and you are responsible for managing the allocation of the 256 ids 
// that go into the second parameter. 

enum TypeID
{
	TI_NULL = 0x00000000,

	TI_MELT_CMD		= 0x00000335,
	TI_MELT_NODE	= 0x00000336,
	TI_SOFT_CMD		= 0x00000337,
	TI_SOFT_WORLD_NODE	= 0x00000338,
	TI_DEBUG_NODE	= 0x00000339,
//	TI_SOLVER_NODE	= 0x0000033A,
	TI_USER_CONTEXT = 0x0000033B,
	TI_DEBUG_SOFT	= 0x0000033C,
	//--------------  liquid -------------------------------
	liqSurfaceNodeId        = 0x0010351F,
	liqDisplacementNodeId   = 0x00103520,
	liqVolumeNodeId         = 0x00103521,
	liqLightNodeId          = 0x00103522,
	liqRibboxNodeId         = 0x00103523,
	liqGlobalsNodeId        = 0x00103524,
	liqCoordSysNodeId       = 0x00103525,
	liqRibRequestId         = 0x0010F6D1,
	liqBoundingBoxLocatorId = 0x0010F6D8,
	liqCoShaderNodeId       = 0x0010F6D9,
	//------------------------------------------------------
	TI_GEOBAKE_READ_CACHE		= 0x10000,

	TI_XX_CACHE_FILE			= 0x10001,

	TI_XX_SUBD_CMD				= 0x10002,

	//------------------------------------------------------
	TI_MR_PLACE2D_TEXTURE	= 0xFFFFF33D,
	TI_OUTPUT_FILE_NODE		= 0xFFFFF33E,
	TI_INPUT_FILE_NODE		= 0xFFFFF33F,
	TI_SOFT_OBJECT_NODE		= 0xFFFFF340,
	TI_SOFT_OBJECT_DATA		= 0xFFFFF341,
	TI_DUMMY_NODE_IN			= 0xFFFFF342,
	TI_DUMMY_NODE_OUT			= 0xFFFFF343,
	TI_INPUT_FILE_CMD			= 0xFFFFF344,
	TI_SAVE_FILE_CMD			= 0xFFFFF345,
	TI_SMOKE					= 0xFFFFF346,
	TI_SMOKE_EMITTER_NODE		= 0xFFFFF347,
	TI_SMOKE_CONTEXT			= 0xFFFFF348,

	TI_RBF_FACE_ANIMATION		= 0xFFFFF349,
	TI_RBF_CMD					= 0xFFFFF34A,
	TI_RBF_PARAMETER			= 0xFFFFF34B,

	TI_CONSOLE_DEBUG			= 0xFFFFF34C,
	TI_RBF_JOINT_MAPPING		= 0xFFFFF34D,

	TI_ELVISHRAY_CMD			= 0xFFFFF34E,
	TI_ELVISHRAY_VIEW_RENDER_CMD= 0xFFFFF34F,

	TI_BULLET_SPH_NODE			= 0xFFFFF350,
	TI_BULLET_SPH_CONSTEXT		= 0xFFFFF351,
	TI_BULLET_SPH_EMITTER_NODE	= 0xFFFFF352,
	TI_BULLET_SPH_FIELD_NODE	= 0xFFFFF353,
	TI_BULLET_SPH_PARTICLE_ATTR_NODE	= 0xFFFFF354,
	TI_BULLET_SPH_CMD			= 0xFFFFF355,
	TI_BULLET_SPH_MGR_NODE		= 0xFFFFF356,

	TI_MY_CMD_TEMPLATE_SIMPLE	= 0xFFFFF357,
	TI_MY_CMD_TEMPLATE			= 0xFFFFF358,

	TI_XXU_STRING				= 0xFFFFF359,
	TI_UV_EXPORT				= 0xFFFFF35A,

	TI_CURVE_TEXTURE_SURFACE	= 0xFFFFF35B,
	TI_CURVE_TEXTURE_CURVE		= 0xFFFFF35C,
	TI_CURVE_TEXTURE_SURFACE2	= 0xFFFFF35D,

	TI_MY_NODE_TEMPLATE			= 0xFFFFF35E,



	TI_NUM,
};
//
extern const char *TN_MELT_CMD;
extern const char *TN_MELT_NODE;
extern const char *TN_SOFT_CMD;
extern const char *TN_SOFT_WORLD_NODE;
extern const char *TN_DEBUG_NODE;
//extern const char *TN_SOLVER_NODE;
extern const char *TN_USER_CONTEXT;
extern const char *TN_DEBUG_SOFT;
extern const char *TN_MR_PLACE2D_TEXTURE;
extern const char *TN_OUTPUT_FILE_NODE;
extern const char *TN_INPUT_FILE_NODE;
extern const char *TN_SOFT_OBJECT_NODE;
extern const char *TN_SOFT_OBJECT_DATA;
extern const char *TN_DUMMY_NODE_IN;
extern const char *TN_DUMMY_NODE_OUT;
extern const char *TN_INPUT_FILE_CMD;
extern const char *TN_SAVE_FILE_CMD;
extern const char *TN_SMOKE;
extern const char *TN_SMOKE_EMITTER_NODE;
extern const char *TN_SMOKE_CONTEXT;
extern const char *TN_RBF_FACE_ANIMATION;
extern const char *TN_RBF_CMD;
extern const char *TN_RBF_PARAMETER;
extern const char *TN_CONSOLE_DEBUG;
extern const char *TN_RBF_JOINT_MAPPING;
extern const char *TN_ELVISHRAY_CMD;
extern const char *TN_ELVISHRAY_VIEW_RENDER_CMD;
extern const char *TN_BULLET_SPH_NODE;
extern const char *TN_BULLET_SPH_CONSTEXT;
extern const char *TN_BULLET_SPH_EMITTER_NODE;
extern const char *TN_BULLET_SPH_FIELD_NODE;
extern const char *TN_BULLET_SPH_PARTICLE_ATTR_NODE;
extern const char *TN_BULLET_SPH_CMD;
extern const char *TN_BULLET_SPH_MGR_NODE;
extern const char *TN_MY_CMD_TEMPLATE_SIMPLE;
extern const char *TN_MY_CMD_TEMPLATE;
extern const char *TN_XXU_STRING;
extern const char *TN_UV_EXPORT;
extern const char *TN_CURVE_TEXTURE_SURFACE;
extern const char *TN_CURVE_TEXTURE_CURVE;
extern const char *TN_CURVE_TEXTURE_SURFACE2;
extern const char *TN_MY_NODE_TEMPLATE;
extern const char *TN_GEOBAKE_READ_CACHE;
extern const char *TN_XX_CACHE_FILE;
extern const char *TN_XX_SUBD_CMD;
//
#endif

#ifndef _RBF_PARAMETER_
#define _RBF_PARAMETER_

#include <xxcommon/prerequest_std.h>
#include <xxcommon/prerequest_maya.h>
#include <xxcommon/PlugNameMacro.h>

enum RBFType;

class RBFParameterNode : public MPxLocatorNode
{
public:
	PLUGNAME_DECLARE(type,	t);
	PLUGNAME_DECLARE(constant, cnst );
public:
	RBFParameterNode();
	virtual ~RBFParameterNode();

	static void removedCallback(MObject& node, void *clientData);
	virtual void draw( M3dView&, const MDagPath&, M3dView::DisplayStyle, M3dView::DisplayStatus);

	static void *creator();
	static MStatus initialize();

// 	virtual bool isBounded() const;
// 	virtual MBoundingBox boundingBox() const;

public:
	static const MTypeId typeId;
	static const MString typeName;

private:
	static MObject m_RBFType;
	static MObject m_RBFConstant;

private:
	void _destruct();
};

void getRBFTypeParameters(RBFType &f, double &constant);

#endif //_RBF_PARAMETER_
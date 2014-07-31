#include "RBFWapper.h"
#include <iostream>
#include <cassert>

RBFWapper* RBFWapper::m_instance = NULL;

RBFWapper::RBFWapper()
{
	normalUpdatesDesired = true;

}

RBFWapper::~RBFWapper()
{

}
RBFWapper* RBFWapper::getInstance()
{
	if(m_instance==NULL)
	{
		m_instance = new RBFWapper();
	}
	return m_instance;
}
void RBFWapper::destroy()
{
	if(m_instance!=NULL)
	{
		std::cout << "RBFWapper::destroy()" << std::endl;
		delete m_instance;
		m_instance = NULL;
	}
}

void RBFWapper::idle(
					const std::vector<Scalar>& dx,
					const std::vector<Scalar>& dy,
					const std::vector<Scalar>& dz,
					PointArray&       updated,
					const PointArray& original
					//, RBFType f,	double constant
					 )
{
// 	rbfX.updateRBFParameters(f, constant);
// 	rbfY.updateRBFParameters(f, constant);
// 	rbfZ.updateRBFParameters(f, constant);

	rbfX.UpdateFunctionValues(dx);
	rbfY.UpdateFunctionValues(dy);
	rbfZ.UpdateFunctionValues(dz);

	// deform the object to render
	deformObject(updated, original);
}

void RBFWapper::deformObject(					
							 PointArray&       updated,
							 const PointArray& original
							 )
{
	for (unsigned int i = 0; i < original.length(); i++)
	{
		Point pos(original[i].x, original[i].y, original[i].z);

		Point newPos;
		newPos.x = pos.x + rbfX.interpolate(pos.x, pos.y, pos.z);
		newPos.y = pos.y + rbfY.interpolate(pos.x, pos.y, pos.z);
		newPos.z = pos.z + rbfZ.interpolate(pos.x, pos.y, pos.z);

		updated.set( i, newPos.x, newPos.y, newPos.z );
	}
}

// void RBFWapper::loadMesh(const std::string &sourceOBJ)
// {
// 
// 	undeformedMesh = new TriangleMesh(sourceOBJ);
// 	undeformedMesh->updateNormals();
// 
// 	deformedMesh = new TriangleMesh(sourceOBJ);
// 	deformedMesh->updateNormals();
// }
void RBFWapper::updateControlPoints(const vector<Scalar> &vx,
						 const vector<Scalar> &vy, 
						 const vector<Scalar> &vz)
{
	assert( (vx.size()==vy.size()) && (vy.size()==vz.size()) );

	controlPointPosX.clear();
	controlPointPosY.clear();
	controlPointPosZ.clear();

	size_t numControlPoints = vx.size();
	for (size_t i = 0; i<numControlPoints; i++)
	{
		addControlPoint(vx[i], vy[i], vz[i]);
	}
}
void RBFWapper::addControlPoint(Scalar x, Scalar y, Scalar z)
{
	//Vector3 pos = undeformedMesh->getParticles()[pointIndex].getPos();
	controlPointPosX.push_back(x);
	controlPointPosY.push_back(y);
	controlPointPosZ.push_back(z);
}

void RBFWapper::initInterpolationFunction(
	std::vector<Scalar> &FX,
	std::vector<Scalar> &FY, 
	std::vector<Scalar> &FZ,
	RBFType f,	double constant
	)
{
	// initialize interpolation functions
	rbfX = RBFInterpolator(controlPointPosX, controlPointPosY, controlPointPosZ, FX, f, constant );
	rbfY = RBFInterpolator(controlPointPosX, controlPointPosY, controlPointPosZ, FY, f, constant );
	rbfZ = RBFInterpolator(controlPointPosX, controlPointPosY, controlPointPosZ, FZ, f, constant );
}




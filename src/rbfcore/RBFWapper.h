
#ifndef _RBF_WAPPER_
#define _RBF_WAPPER_

#include <string>
#include <vector>

//#include "TriangleMesh.h"											// the structure in which the loaded mesh is stored
#include "RBFInterpolator.h"
#include "RBFType.h"
#include "scalar.h"

class TriangleMesh;


class RBFWapper
{
public:
	virtual ~RBFWapper();
	static RBFWapper* getInstance();
	static void destroy();

	void idle(
		const std::vector<Scalar>& dx,
		const std::vector<Scalar>& dy,
		const std::vector<Scalar>& dz,
		PointArray&       updated,
		const PointArray& original
		//, RBFType f,	double constant
		);
//	void loadMesh(const std::string &filename);
	void updateControlPoints(
		const vector<Scalar> &vx,
		const vector<Scalar> &vy, 
		const vector<Scalar> &vz);

	void initInterpolationFunction(
		std::vector<Scalar> &FX,
		std::vector<Scalar> &FY, 
		std::vector<Scalar> &FZ,
		RBFType f,	double constant
		);
	void deformObject(
		PointArray&       updated,
		const PointArray& original
		);
	//TriangleMesh *deformedMesh;
	//TriangleMesh *undeformedMesh;										// The original triangle mesh
	
	std::vector<Scalar> controlPointPosX;										// X-coordinates of control points
	std::vector<Scalar> controlPointPosY;										// Y-coordinates of control points
	std::vector<Scalar> controlPointPosZ;										// Z-coordinates of control points


protected:
	RBFWapper();
	static RBFWapper* m_instance;


	void addControlPoint(Scalar x, Scalar y, Scalar z);





	RBFInterpolator rbfX, rbfY, rbfZ;									// Our wonderful radial basis function interpolation things :)

	bool normalUpdatesDesired;									// When the program is running press 'n' to disable normal updates


};

#endif
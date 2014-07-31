//////////////////////////////////////////////////////////////////////////
//
// RBFInterpolator : interpolation by radial basis functions
// 
// 2009 Karsten Noe
//
// Read the blog at cg.alexandra.dk for more information
//
//////////////////////////////////////////////////////////////////////////


#ifndef RBFInterpolator_H
#define RBFInterpolator_H

#define WANT_STREAM                  
#define WANT_MATH  

#include <vector>

#include "newmat.h"                  // use matrix operations from the newmat library by R B Davies
									 // http://www.robertnz.net/nm_intro.htm


#include "scalar.h"
#include "RBFType.h"

using namespace std;

class RBFInterpolator
{
public:
	RBFInterpolator();
	~RBFInterpolator();

	//create an interpolation function f that obeys F_i = f(x_i, y_i, z_i)
	RBFInterpolator(vector<Scalar> x, vector<Scalar> y, vector<Scalar> z, 
		vector<Scalar> F, RBFType &f, double &constant);

	//specify new function values F_i while keeping the same 
	void UpdateFunctionValues(vector<Scalar> F);

	//evaluate the interpolation function f at the 3D position (x,y,z)
	Scalar interpolate(Scalar x, Scalar y, Scalar z);
	void updateRBFParameters(RBFType &f, double &constant);

private:

	// read the tutorial on cg.alexandra.dk to make sense of these variable names ;-)
	Scalar g(Scalar t_squared);
	bool successfullyInitialized;
	ColumnVector A;
	Matrix P;		//contains positions
	Matrix Ginv;
	unsigned int M;


	//RBF parameter
	RBFType rbftype;
	double constant; 

protected:

#ifdef Update_Parameter_1
#else
	void updateRBFParameters();
#endif

	void print(const string& prefix, const Matrix& m);

};

#endif
//////////////////////////////////////////////////////////////////////////
//
// RBFInterpolator : interpolation by radial basis functions
// 
// 2009 Karsten Noe
//
// Read the blog at cg.alexandra.dk for more information
//
//////////////////////////////////////////////////////////////////////////

#include "RBFInterpolator.h"
#include <math.h>
#include <xxcommon/prerequest_std.h>
#include <xxcommon/prerequest_local.h>
//#include "RBFParameterNode.h"

#ifdef Update_Parameter_1
extern void getRBFTypeParameters(RBFType &f, double &constant);
#endif


RBFInterpolator::RBFInterpolator()
{
	successfullyInitialized = false;
}

RBFInterpolator::RBFInterpolator(vector<Scalar> x, vector<Scalar> y, vector<Scalar> z,
								 vector<Scalar> f, RBFType &rbftype_, double &constant)
{
	successfullyInitialized = false; // default value for if we end init prematurely.

	M = f.size();

	// all four input vectors must have the same length.
	if ( x.size() != M || y.size() != M || z.size() != M ){
		_LogError("x.size() != M || y.size() != M || z.size() != M ");
		_LogDebug("size x="<<x.size() <<",size y="<<y.size()<<",size z="<<z.size() <<",M(size f)="<<M);
		assert(0&&"x.size() != M || y.size() != M || z.size() != M ");
		return;	
	}

	ColumnVector F = ColumnVector(M + 4);
	P = Matrix(M, 3);

	Matrix G(M + 4,M + 4);

	// copy function values
	for (int i = 1; i <= M; i++)
		F(i) = f[i-1];
	
	F(M+1) = 0;  F(M+2) = 0;  F(M+3) = 0;  F(M+4) = 0;

	// fill xyz coordinates into P 
	for (int i = 1; i <= M; i++)
	{
		P(i,1) = x[i-1];
		P(i,2) = y[i-1];
		P(i,3) = z[i-1];
	}
#ifdef Update_Parameter_1
	// the matrix below is symmetric, so I could save some calculations Hmmm. must be a todo
	this->updateRBFParameters(rbftype_, constant);//在计算g()之前更新RBF参数
#else
	updateRBFParameters();
#endif

	for (int i = 1; i <= M; i++)
	for (int j = 1; j <= M; j++)
	{
		Scalar dx = x[i-1] - x[j-1];
		Scalar dy = y[i-1] - y[j-1];
		Scalar dz = z[i-1] - z[j-1];

		Scalar distance_squared = dx*dx + dy*dy + dz*dz;

		G(i,j) = g(distance_squared);
	}

	//Set last 4 columns of G
	for (int i = 1; i <= M; i++)
	{
		G( i, M+1 ) = 1;
		G( i, M+2 ) = x[i-1];
		G( i, M+3 ) = y[i-1];
		G( i, M+4 ) = z[i-1];
	}

	for (int i = M+1; i <= M+4; i++)
	for (int j = M+1; j <= M+4; j++)
		G( i, j ) = 0;

	//Set last 4 rows of G
	for (int j = 1; j <= M; j++)
	{
		G( M+1, j ) = 1;
		G( M+2, j ) = x[j-1];
		G( M+3, j ) = y[j-1];
		G( M+4, j ) = z[j-1];
	}

	Try 
	{ 
		Ginv = G.i(); 

		print("RBFInterpolator(), Ginv:", Ginv);
		print("RBFInterpolator(), F:", F);

		A = Ginv*F;
		successfullyInitialized = true;
	}
    CatchAll { cout << BaseException::what() << endl; }

}

RBFInterpolator::~RBFInterpolator()
{

}

Scalar RBFInterpolator::interpolate(Scalar x, Scalar y, Scalar z)
{
	if (!successfullyInitialized)
		return 0.0f;

	Scalar sum = 0.0f;

#ifdef Update_Parameter_1
#else
	updateRBFParameters();//在计算g()之前更新RBF参数
#endif
	// RBF part

 	for (int i = 1; i <= M; i++)
	{
		Scalar dx = x - P(i,1);
		Scalar dy = y - P(i,2);
		Scalar dz = z - P(i,3);

		Scalar distance_squared = dx*dx + dy*dy + dz*dz;

		sum += A(i) * g(distance_squared);
	}
	
	//affine part
	sum += A(M+1) + A(M+2)*x + A(M+3)*y + A(M+4)*z;

	return sum;
}

//note: assuming the input is t squared
Scalar RBFInterpolator::g(Scalar t_squared)
{	

	//return sqrt(log10(t_squared + 1.0f));

	//exp( -c * r^2 );
	//return exp( -15.0f * t_squared);

	//return sqrt( t_squared );//http://www.farfieldtechnology.com/products/toolbox/theory/rbffaq.html

	return PHI(rbftype, t_squared, constant);

	
}

void RBFInterpolator::UpdateFunctionValues(vector<Scalar> f)
{
	successfullyInitialized = false;

	ColumnVector F(M+4);

	// copy function values
	for (int i = 1; i <= M; i++)
		F(i) = f[i-1];
	
	F(M+1) = 0;  F(M+2) = 0;  F(M+3) = 0;  F(M+4) = 0;

	Try 
	{ 
		//print("UpdateFunctionValues(), Ginv:", Ginv);
		//print("UpdateFunctionValues(), F:", F);

		A = Ginv*F;

		//print("UpdateFunctionValues(), A:", A);

		successfullyInitialized = true;
	}
    CatchAll { cout << BaseException::what() << endl; }

}

void RBFInterpolator::updateRBFParameters(RBFType &rbftype_, double &constant)
{
	this->rbftype = rbftype_;
	this->constant = constant;
}

#ifdef Update_Parameter_1
#else
void RBFInterpolator::updateRBFParameters()
{
	getRBFTypeParameters(rbftype, constant);
}
#endif

void RBFInterpolator::print(const string& prefix, const Matrix& m)
{
	_LogDebug(prefix<<"("<< m.Nrows()<<","<< m.Ncols()<<")");
		
	stringstream ss;
	for(size_t i=0; i<m.Nrows(); i++){
		for(size_t j=0; j<m.Ncols(); j++){
			ss << m.element(i, j) << ", ";
		}
		ss<<"\n";
	}
	_LogDebug(ss.str());

}
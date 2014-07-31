#ifndef _RBF_TYPE_
#define _RBF_TYPE_

enum RBFType
{
	RBFT_Gaussian = 0,				// phi(r) = exp(-c * r^2)
	RBFT_Multiquadric,				// phi(r) = sqrt( r^2 + c^2 )
	
	RBFT_PolyharmonicSplineOdd,		// phi(r) = r^k;       k=1,3,5,...
// 		RBFT_PolyharmonicSpline_1,	// phi(r) = r;
// 		RBFT_PolyharmonicSpline_3,	// phi(r) = r^3;

	RBFT_PolyharmonicSplineEven,	// phi(r) = r^k * ln(r); k=2,4,6,...
		//RBFT_PolyharmonicSpline_2,	// phi(r) = r^2 * ln(r)

	RBFT_Num,
};

//Radial basis function PHI
// r2 - r*r
double PHI(RBFType f, const double r2, const double c);
bool PHI_check(RBFType f,  const double c);

#endif
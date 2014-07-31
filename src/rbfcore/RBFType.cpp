#include "RBFType.h"

#include <math.h>
#include <cassert>



double PHI(RBFType f, const double r2, const double c)
{
	double ret = 0;

	switch( f )
	{
	case RBFT_Gaussian:
		{
			ret = exp(-c * r2);
			break;
		}
	case RBFT_Multiquadric:
		{
			ret = sqrt( r2 + c*c );
			break;
		}
	case RBFT_PolyharmonicSplineOdd:
		{
			const int exponent = c;
			const double base = sqrt(r2);
			ret = pow(base, exponent);
			break;
		}
	case RBFT_PolyharmonicSplineEven:
		{
			const double base = r2;
			const int exponent = c/2.0f;
			ret = pow(base, exponent) * log( sqrt(r2) );
			break;
		}
	default:
		assert(0&&"Unknown RBF type.");
	}

	return ret;
}

bool PHI_check(RBFType f,  const double c)
{
	bool ret = false;

	switch( f )
	{
	case RBFT_Gaussian:
		{
			assert(abs(c)>0.000001 && "abs(c) is too small. Did you forget to set parameter c?");
			break;
		}
	case RBFT_Multiquadric:
		{
			break;
		}
	case RBFT_PolyharmonicSplineOdd:
		{
			assert(abs(c)>0.000001 && "abs(c) is too small. Did you forget to set parameter c?");

			break;
		}
	case RBFT_PolyharmonicSplineEven:
		{
			assert(abs(c)>0.000001 && "abs(c) is too small. Did you forget to set parameter c?");
			break;
		}
	default:
		assert(0&&"Unknown RBF type.");
	}

	return ret;
};
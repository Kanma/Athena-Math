/** @file   MathUtils.cpp
    @author Philip Abbet
    
    Implementation of the Athena::Math::MathUtils class.
    
    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#include <Athena-Math/MathUtils.h>
#include <Athena-Math/asm_math.h>

using namespace Athena::Math;


/************************************** CONSTANTS ***************************************/

const Real MathUtils::POS_INFINITY       = std::numeric_limits<Real>::infinity();
const Real MathUtils::NEG_INFINITY       = -std::numeric_limits<Real>::infinity();
const Real MathUtils::PI                 = Real(4.0 * atan(1.0));
const Real MathUtils::TWO_PI             = Real(2.0 * PI);
const Real MathUtils::HALF_PI            = Real(0.5 * PI);
const Real MathUtils::DEGREES_TO_RADIANS = PI / Real(180.0);
const Real MathUtils::RADIANS_TO_DEGREES = Real(180.0) / PI;
const Real MathUtils::LOG2               = log(Real(2.0));


/********************************** INTEGER OPERATIONS **********************************/

int MathUtils::ISign(int iValue)
{
    return (iValue > 0 ? +1 : (iValue < 0 ? -1 : 0));
}


/******************************* FLOATING-POINT OPERATIONS ******************************/

Real MathUtils::Sign(Real fValue)
{
    if (fValue > 0.0)
        return 1.0;

    if (fValue < 0.0)
        return -1.0;

    return 0.0;
}


Real MathUtils::InvSqrt(Real fValue)
{
	return Real(asm_rsq(fValue));
}


bool MathUtils::RealEqual(Real a, Real b, Real tolerance)
{
    if (fabs(b-a) <= tolerance)
        return true;
    else
        return false;
}


/******************************* TRIGONOMETRIC OPERATIONS *******************************/

Radian MathUtils::ACos(Real fValue)
{
    if (-1.0 < fValue)
    {
        if (fValue < 1.0)
            return Radian(acos(fValue));
        else
            return Radian(0.0);
    }
    else
    {
        return Radian(PI);
    }
}


Radian MathUtils::ASin(Real fValue)
{
    if (-1.0 < fValue)
    {
        if (fValue < 1.0)
            return Radian(asin(fValue));
        else
            return Radian(HALF_PI);
    }
    else
    {
        return Radian(-HALF_PI);
    }
}


/****************************** RANDOM NUMBERS GENERATION *******************************/

Real MathUtils::UnitRandom()
{
    return asm_rand() / asm_rand_max();
}
    

Real MathUtils::RangeRandom(Real fLow, Real fHigh)
{
    return (fHigh - fLow) * UnitRandom() + fLow;
}


Real MathUtils::SymmetricRandom()
{
	return 2.0f * UnitRandom() - 1.0f;
}


/********************************** SIGNAL GENERATION ***********************************/

Real MathUtils::gaussianDistribution(Real x, Real offset, Real scale)
{
	Real nom = MathUtils::Exp(-MathUtils::Sqr(x - offset) / (2 * MathUtils::Sqr(scale)));
	Real denom = scale * MathUtils::Sqrt(2 * MathUtils::PI);

	return nom / denom;
}

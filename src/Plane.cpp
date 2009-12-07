/** @file   Plane.cpp
    @author Philip Abbet
    
    Implementation of the class Athena::Math::Plane
    
    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#include <Athena-Math/Plane.h>
//#include <Athena-Math/Matrix3.h>
#include <Athena-Math/AxisAlignedBox.h>

using namespace Athena::Math;


/****************************** CONSTRUCTION / DESTRUCTION ******************************/

Plane::Plane()
: normal(Vector3::ZERO), d(0.0)
{
}

//-----------------------------------------------------------------------

Plane::Plane(const Plane& rhs)
: normal(rhs.normal), d(rhs.d)
{
}

//-----------------------------------------------------------------------

Plane::Plane(const Vector3& rkNormal, Real fConstant)
: normal(rkNormal), d(-fConstant)
{
}

//-----------------------------------------------------------------------

Plane::Plane(Real a, Real b, Real c, Real _d)
: normal(a, b, c), d(_d)
{
}

//-----------------------------------------------------------------------

Plane::Plane(const Vector3& rkNormal, const Vector3& rkPoint)
{
	redefine(rkNormal, rkPoint);
}

//-----------------------------------------------------------------------

Plane::Plane(const Vector3& rkPoint0, const Vector3& rkPoint1, const Vector3& rkPoint2)
{
	redefine(rkPoint0, rkPoint1, rkPoint2);
}


/**************************************** METHODS ***************************************/

Real Plane::getDistance(const Vector3& rkPoint) const
{
	return normal.dotProduct(rkPoint) + d;
}

//-----------------------------------------------------------------------

Plane::tSide Plane::getSide(const Vector3& rkPoint) const
{
	Real fDistance = getDistance(rkPoint);

	if (fDistance < 0.0)
		return Plane::NEGATIVE_SIDE;

	if (fDistance > 0.0)
		return Plane::POSITIVE_SIDE;

	return Plane::NO_SIDE;
}

//-----------------------------------------------------------------------

Plane::tSide Plane::getSide(const AxisAlignedBox& box) const
{
	if (box.isNull()) 
		return NO_SIDE;

	if (box.isInfinite())
		return BOTH_SIDE;

    return getSide(box.getCenter(), box.getHalfSize());
}

//-----------------------------------------------------------------------

Plane::tSide Plane::getSide(const Vector3& centre, const Vector3& halfSize) const
{
    Real dist = getDistance(centre);

    Real maxAbsDist = normal.absDotProduct(halfSize);

    if (dist < -maxAbsDist)
        return Plane::NEGATIVE_SIDE;

    if (dist > +maxAbsDist)
        return Plane::POSITIVE_SIDE;

    return Plane::BOTH_SIDE;
}

//-----------------------------------------------------------------------

void Plane::redefine(const Vector3& rkPoint0, const Vector3& rkPoint1,
                     const Vector3& rkPoint2)
{
	Vector3 kEdge1 = rkPoint1 - rkPoint0;
	Vector3 kEdge2 = rkPoint2 - rkPoint0;
	normal = kEdge1.crossProduct(kEdge2);
	normal.normalise();
	d = -normal.dotProduct(rkPoint0);
}

//-----------------------------------------------------------------------

void Plane::redefine(const Vector3& rkNormal, const Vector3& rkPoint)
{
	normal = rkNormal;
	d = -rkNormal.dotProduct(rkPoint);
}

//-----------------------------------------------------------------------
/*
Vector3 Plane::projectVector(const Vector3& p) const
{
    normalize();
    
	Matrix3 xform;
	xform[0][0] = 1.0f - normal.x * normal.x;
	xform[0][1] = -normal.x * normal.y;
	xform[0][2] = -normal.x * normal.z;
	xform[1][0] = -normal.y * normal.x;
	xform[1][1] = 1.0f - normal.y * normal.y;
	xform[1][2] = -normal.y * normal.z;
	xform[2][0] = -normal.z * normal.x;
	xform[2][1] = -normal.z * normal.y;
	xform[2][2] = 1.0f - normal.z * normal.z;

	return xform * p;
}
*/
//-----------------------------------------------------------------------

Real Plane::normalise(void)
{
    Real fLength = normal.length();

    // Will also work for zero-sized vectors, but will change nothing
    if (fLength > 1e-08f)
    {
        Real fInvLength = 1.0f / fLength;
        normal *= fInvLength;
        d *= fInvLength;
    }

    return fLength;
}

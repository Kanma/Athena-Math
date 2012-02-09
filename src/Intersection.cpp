/** @file   Intersection.cpp
    @author Philip Abbet

    Implementation of the class Athena::Math::Intersection

    @note   This is based on some methods from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#include <Athena-Math/Intersection.h>
#include <Athena-Math/AxisAlignedBox.h>
#include <Athena-Math/Plane.h>
#include <Athena-Math/Sphere.h>

using namespace Athena::Math;


/**************************************** METHODS ***************************************/

bool Intersection::intersects(const AxisAlignedBox& box, const Sphere& sphere)
{
    if (box.isNull()) return false;
    if (box.isInfinite()) return true;

    // Use splitting planes
    const Vector3& center = sphere.getCenter();
    Real radius = sphere.getRadius();
    const Vector3& min = box.getMinimum();
    const Vector3& max = box.getMaximum();

    // Arvo's algorithm
    Real s, d = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (center.ptr()[i] < min.ptr()[i])
        {
            s = center.ptr()[i] - min.ptr()[i];
            d += s * s;
        }
        else if(center.ptr()[i] > max.ptr()[i])
        {
            s = center.ptr()[i] - max.ptr()[i];
            d += s * s;
        }
    }

    return d <= radius * radius;
}

//-----------------------------------------------------------------------

bool Intersection::intersects(const AxisAlignedBox& box, const Plane& plane)
{
    return (plane.getSide(box) == Plane::BOTH_SIDE);
}

//-----------------------------------------------------------------------

bool Intersection::intersects(const AxisAlignedBox& box, const Vector3& point)
{
    if (box.isNull())
        return false;
    else if (box.isInfinite())
        return true;

    return (point >= box.getMinimum()) && (point <= box.getMaximum());
}

//-----------------------------------------------------------------------

bool Intersection::intersects(const Sphere& sphere1, const Sphere& sphere2)
{
    return sphere1.intersects(sphere2);
}

//-----------------------------------------------------------------------

bool Intersection::intersects(const Sphere& sphere, const Plane& plane)
{
    return (MathUtils::Abs(plane.getDistance(sphere.getCenter())) <= sphere.getRadius());
}

//-----------------------------------------------------------------------

bool Intersection::intersects(const Sphere& sphere, const Vector3& point)
{
    return ((point - sphere.getCenter()).squaredLength() <= MathUtils::Sqr(sphere.getRadius()));
}

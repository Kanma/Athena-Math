/** @file   Sphere.h
    @author Philip Abbet

    Declaration of the class Athena::Math::Sphere

    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#ifndef _ATHENA_MATH_SPHERE_H_
#define _ATHENA_MATH_SPHERE_H_

#include <Athena-Math/Prerequisites.h>
#include <Athena-Math/Vector3.h>
#include <Athena-Math/MathUtils.h>
#include <Athena-Math/Intersection.h>


namespace Athena {
namespace Math {

    /** \addtogroup Math
    *  @{
    */

    //------------------------------------------------------------------------------------
    /// @brief  A sphere primitive, mostly used for bounds checking
    ///
    /// @remark A sphere in math texts is normally represented by the function
    ///         x^2 + y^2 + z^2 = r^2 (for sphere's centered on the origin). Ogre stores
    ///         spheres simply as a center point and a radius.
    //------------------------------------------------------------------------------------
    class ATHENA_SYMBOL Sphere
    {
        //_____ Construction / Destruction __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Default constructor, creates a unit sphere around the origin
        //--------------------------------------------------------------------------------
        Sphere()
        : mRadius(1.0), mCenter(Vector3::ZERO)
        {
        }

        //--------------------------------------------------------------------------------
        /// @brief  Constructor allowing arbitrary spheres
        ///
        /// @param center   The center point of the sphere
        /// @param radius   The radius of the sphere
        //--------------------------------------------------------------------------------
        Sphere(const Vector3& center, Real radius)
        : mRadius(radius), mCenter(center)
        {
        }


        //_____ Methods __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Returns the radius of the sphere
        //--------------------------------------------------------------------------------
        inline Real getRadius(void) const { return mRadius; }

        //--------------------------------------------------------------------------------
        /// @brief  Sets the radius of the sphere
        //--------------------------------------------------------------------------------
        inline void setRadius(Real radius) { mRadius = radius; }

        //--------------------------------------------------------------------------------
        /// @brief  Returns the center point of the sphere
        //--------------------------------------------------------------------------------
        inline const Vector3& getCenter(void) const { return mCenter; }

        //--------------------------------------------------------------------------------
        /// @brief  Sets the center point of the sphere
        //--------------------------------------------------------------------------------
        inline void setCenter(const Vector3& center) { mCenter = center; }

        //--------------------------------------------------------------------------------
        /// @brief  Indicates if this sphere intersects another sphere
        //--------------------------------------------------------------------------------
        inline bool intersects(const Sphere& s) const
        {
            return (s.mCenter - mCenter).squaredLength() <=
                MathUtils::Sqr(s.mRadius + mRadius);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Indicates if this sphere intersects a box
        //--------------------------------------------------------------------------------
        inline bool intersects(const AxisAlignedBox& box) const
        {
            return Intersection::intersects(box, *this);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Indicates if this sphere intersects a plane
        //--------------------------------------------------------------------------------
        inline bool intersects(const Plane& plane) const
        {
            return Intersection::intersects(*this, plane);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Indicates if this sphere intersects a point
        //--------------------------------------------------------------------------------
        inline bool intersects(const Vector3& point) const
        {
            return Intersection::intersects(*this, point);
        }


        //_____ Attributes __________
    private:
        Real    mRadius;
        Vector3 mCenter;
    };

    /** @} */
    /** @} */
}
}

#endif

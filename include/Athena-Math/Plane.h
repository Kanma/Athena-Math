/** @file   Plane.h
    @author Philip Abbet

    Declaration of the class Athena::Math::Plane

    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#ifndef _ATHENA_MATH_PLANE_H_
#define _ATHENA_MATH_PLANE_H_

#include <Athena-Math/Prerequisites.h>
#include <Athena-Math/MathUtils.h>
#include <Athena-Math/Vector3.h>


namespace Athena {
namespace Math {

    /** \addtogroup Math
    *  @{
    */

    //------------------------------------------------------------------------------------
    /// @brief  Defines a plane in 3D space
    ///
    /// A plane is defined in 3D space by the equation Ax + By + Cz + D = 0
    ///
    /// This equates to a vector (the normal of the plane, whose x, y and z components
    /// equate to the coefficients A, B and C respectively), and a constant (D) which is
    /// the distance along the normal you have to go to move the plane back to the origin.
    ///
    /// For instance, a plane with a normal equals to (0, 1, 0) and D = -4 contains the
    /// following points: (0, 4, 0), (10, 4, 5) and (3, 4, 12)
    //------------------------------------------------------------------------------------
    class ATHENA_MATH_SYMBOL Plane
    {
        //_____ Internal types __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Identify the sides of the plane
        ///
        /// The "positive side" of the plane is the half space to which the plane normal
        /// points. The "negative side" is the other half space. The flag "no side"
        /// indicates the plane itself.
        //--------------------------------------------------------------------------------
        enum tSide
        {
            NO_SIDE,
            POSITIVE_SIDE,
            NEGATIVE_SIDE,
            BOTH_SIDE
        };


        //_____ Construction / Destruction __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Default constructor, set everything to 0
        //--------------------------------------------------------------------------------
        Plane();

        //--------------------------------------------------------------------------------
        /// @brief  Copy constructor
        //--------------------------------------------------------------------------------
        Plane(const Plane& rhs);

        //--------------------------------------------------------------------------------
        /// @brief  Construct a plane through a normal, and a distance to move the plane
        ///         along the normal
        ///
        /// @param  rkNormal    The normal
        /// @param  fConstant   The distance to move the plane along the normal (note:
        ///                     this is the inverse of D!)
        //--------------------------------------------------------------------------------
        Plane(const Vector3& rkNormal, Real fConstant);

        //--------------------------------------------------------------------------------
        /// @brief  Construct a plane using the 4 constants directly
        //--------------------------------------------------------------------------------
        Plane(Real a, Real b, Real c, Real d);

        //--------------------------------------------------------------------------------
        /// @brief  Construct a plane using a normal and a point belonging to it
        //--------------------------------------------------------------------------------
        Plane(const Vector3& rkNormal, const Vector3& rkPoint);

        //--------------------------------------------------------------------------------
        /// @brief  Construct a plane using three points belonging to it
        //--------------------------------------------------------------------------------
        Plane(const Vector3& rkPoint0, const Vector3& rkPoint1, const Vector3& rkPoint2);


        //_____ Methods __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Returns the side where the point is
        ///
        /// @return POSITIVE_SIDE if the point is on the "positive side" of the plane,
        ///         NEGATIVE_SIDE if the point is on the "negative side" of the plane, and
        ///         BOTH_SIDE if the point belongs to the plane.
        //--------------------------------------------------------------------------------
        tSide getSide(const Vector3& rkPoint) const;

        //--------------------------------------------------------------------------------
        /// @brief  Returns the side where the box is
        ///
        /// @return POSITIVE_SIDE if the box is totally on the "positive side" of the
        ///         plane, NEGATIVE_SIDE if the box is totally on the "negative side" of
        ///         the plane, and BOTH_SIDE if the box intersects the plane.
        ///
        /// @remark One corner ON the plane is sufficient to consider the box and the
        ///         plane intersecting.
        //--------------------------------------------------------------------------------
        tSide getSide(const AxisAlignedBox& rkBox) const;

        //--------------------------------------------------------------------------------
        /// @brief  Returns the side of the plane where the given box is. The box is
        ///         defined as centre/half-size pairs for effectively.
        ///
        /// @param  centre   The centre of the box
        /// @param  halfSize The half-size of the box
        /// @return POSITIVE_SIDE if the box is totally on the "positive side" of the
        ///         plane, NEGATIVE_SIDE if the box is totally on the "negative side" of
        ///         the plane, and BOTH_SIDE if the box intersects the plane.
        ///
        /// @remark One corner ON the plane is sufficient to consider the box and the
        ///         plane intersecting.
        //--------------------------------------------------------------------------------
        tSide getSide(const Vector3& centre, const Vector3& halfSize) const;

        //--------------------------------------------------------------------------------
        /// @brief  Returns the "pseudodistance" between the plane and a point
        ///
        /// @return The sign of the return value is positive if the point is on the
        ///         positive side of the plane, negative if the point is on the negative
        ///         side, and zero if the point is on the plane.
        /// @par    The absolute value of the return value is the true distance only when
        ///         the plane normal is a unit length vector.
        //--------------------------------------------------------------------------------
        Real getDistance(const Vector3& rkPoint) const;

        //--------------------------------------------------------------------------------
        /// @brief  Redefine this plane based on 3 points
        //--------------------------------------------------------------------------------
        void redefine(const Vector3& rkPoint0, const Vector3& rkPoint1,
                      const Vector3& rkPoint2);

        //--------------------------------------------------------------------------------
        /// @brief  Redefine this plane based on a normal and a point
        //--------------------------------------------------------------------------------
        void redefine(const Vector3& rkNormal, const Vector3& rkPoint);

        //--------------------------------------------------------------------------------
        /// @brief  Project a vector onto the plane
        ///
        /// @param  v   The input vector
        ///
        /// @remark     This gives you the element of the input vector that is
        ///             perpendicular to the normal of the plane. You can get the element
        ///             which is parallel to the normal of the plane by subtracting the
        ///             result of this method from the original vector, since parallel +
        ///             perpendicular = original.
        //--------------------------------------------------------------------------------
        Vector3 projectVector(const Vector3& v) const;

        //--------------------------------------------------------------------------------
        /// @brief  Normalises the plane
        ///
        /// @return The previous length of the plane's normal
        ///
        /// @remark This method normalises the plane's normal and the length scale of D is
        ///         as well.
        ///
        /// @note   This function will not crash for zero-sized vectors, but there will be
        ///         no changes made to their components.
        //--------------------------------------------------------------------------------
        Real normalise(void);


        //_____ Comparison operators __________
    public:
        inline bool operator==(const Plane& rhs) const
        {
            return (MathUtils::RealEqual(rhs.d, d) && rhs.normal == normal);
        }

        inline bool operator!=(const Plane& rhs) const
        {
            return (!MathUtils::RealEqual(rhs.d, d) && rhs.normal != normal);
        }


        //_____ Attributes __________
    public:
        Vector3 normal;
        Real    d;
    };

    /** @} */
    /** @} */
}
}

#endif

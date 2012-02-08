/** @file   Quaternion.h
    @author Philip Abbet

    Declaration of the class Athena::Math::Quaternion

    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#ifndef _ATHENA_MATH_QUATERNION_H_
#define _ATHENA_MATH_QUATERNION_H_

#include <Athena-Math/Prerequisites.h>
#include <Athena-Math/MathUtils.h>
#include <memory.h>


namespace Athena {
namespace Math {

    /** \addtogroup Math
    *  @{
    */

    //------------------------------------------------------------------------------------
    /// @brief  Implementation of a Quaternion, i.e. a rotation around an axis
    //------------------------------------------------------------------------------------
    class ATHENA_SYMBOL Quaternion
    {
        //_____ Construction / Destruction __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Construct a quaternion from 4 manual w/x/y/z values
        //--------------------------------------------------------------------------------
        inline Quaternion(Real fW = 1.0, Real fX = 0.0, Real fY = 0.0, Real fZ = 0.0)
        : w(fW), x(fX), y(fY), z(fZ)
        {
        }

        //--------------------------------------------------------------------------------
        /// @brief  Construct a quaternion from a rotation matrix
        //--------------------------------------------------------------------------------
        inline Quaternion(const Matrix3& rot)
        {
            this->FromRotationMatrix(rot);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Construct a quaternion from an angle/axis
        //--------------------------------------------------------------------------------
        inline Quaternion(const Radian& rfAngle, const Vector3& rkAxis)
        {
            this->FromAngleAxis(rfAngle, rkAxis);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Construct a quaternion from 3 orthonormal local axes
        //--------------------------------------------------------------------------------
        inline Quaternion(const Vector3& xaxis, const Vector3& yaxis, const Vector3& zaxis)
        {
            this->FromAxes(xaxis, yaxis, zaxis);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Construct a quaternion from 3 orthonormal local axes
        //--------------------------------------------------------------------------------
        inline Quaternion(const Vector3* akAxis)
        {
            this->FromAxes(akAxis);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Construct a quaternion from 4 manual w/x/y/z values
        //--------------------------------------------------------------------------------
        inline Quaternion(Real* valptr)
        {
            memcpy(&w, valptr, sizeof(Real) * 4);
        }


        //_____ Value retrieval __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Array accessor operator
        //--------------------------------------------------------------------------------
        inline Real operator[](const size_t i) const
        {
            assert(i < 4);
            return *(&w+i);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Array accessor operator
        //--------------------------------------------------------------------------------
        inline Real& operator[](const size_t i)
        {
            assert(i < 4);
            return *(&w+i);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Pointer accessor for direct copying
        //--------------------------------------------------------------------------------
        inline Real* ptr()
        {
            return &w;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Pointer accessor for direct copying
        //--------------------------------------------------------------------------------
        inline const Real* ptr() const
        {
            return &w;
        }


        //_____ Methods __________
    public:
        inline Quaternion& operator=(const Quaternion& rkQ)
        {
            w = rkQ.w;
            x = rkQ.x;
            y = rkQ.y;
            z = rkQ.z;
            return *this;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Exchange the contents of this quaternion with another
        //--------------------------------------------------------------------------------
        inline void swap(Quaternion& other)
        {
            std::swap(w, other.w);
            std::swap(x, other.x);
            std::swap(y, other.y);
            std::swap(z, other.z);
        }

        void FromRotationMatrix (const Matrix3& kRot);
        void ToRotationMatrix (Matrix3& kRot) const;

        void FromAngleAxis (const Radian& rfAngle, const Vector3& rkAxis);
        void ToAngleAxis (Radian& rfAngle, Vector3& rkAxis) const;

        inline void ToAngleAxis (Degree& dAngle, Vector3& rkAxis) const
        {
            Radian rAngle;
            ToAngleAxis(rAngle, rkAxis);
            dAngle = rAngle;
        }

        void FromAxes (const Vector3* akAxis);
        void FromAxes (const Vector3& xAxis, const Vector3& yAxis, const Vector3& zAxis);
        void ToAxes (Vector3* akAxis) const;
        void ToAxes (Vector3& xAxis, Vector3& yAxis, Vector3& zAxis) const;

        //--------------------------------------------------------------------------------
        /// @brief  Get the local x-axis
        //--------------------------------------------------------------------------------
        Vector3 xAxis(void) const;

        //--------------------------------------------------------------------------------
        /// @brief  Get the local y-axis
        //--------------------------------------------------------------------------------
        Vector3 yAxis(void) const;

        //--------------------------------------------------------------------------------
        /// @brief  Get the local z-axis
        //--------------------------------------------------------------------------------
        Vector3 zAxis(void) const;

        //--------------------------------------------------------------------------------
        /// @brief  Dot product
        //--------------------------------------------------------------------------------
        Real Dot(const Quaternion& rkQ) const;

        //--------------------------------------------------------------------------------
        /// @brief  Squared-length
        //--------------------------------------------------------------------------------
        Real Norm() const;

        //--------------------------------------------------------------------------------
        /// @brief  Normalises this quaternion, and returns the previous length
        //--------------------------------------------------------------------------------
        Real normalise();

        //--------------------------------------------------------------------------------
        /// @remark Apply to non-zero quaternion
        //--------------------------------------------------------------------------------
        Quaternion Inverse() const;

        //--------------------------------------------------------------------------------
        /// @remark Apply to non-zero quaternion
        //--------------------------------------------------------------------------------
        Quaternion UnitInverse() const;

        Quaternion Exp() const;
        Quaternion Log() const;

        //--------------------------------------------------------------------------------
        /// @brief  Returns the rotation to apply to this quaternion to get to another one
        //--------------------------------------------------------------------------------
        Quaternion rotationTo(const Quaternion& q) const;

        //--------------------------------------------------------------------------------
        /// @brief  Returns the rotation to apply to another quaternion to get to this one
        //--------------------------------------------------------------------------------
        Quaternion rotationFrom(const Quaternion& q) const;

        //--------------------------------------------------------------------------------
        /// @brief  Calculate the local roll element of this quaternion
        ///
        /// @param  reprojectAxis   By default the method returns the 'intuitive' result
        ///                         that is, if you projected the local Z of the quaternion
        ///                         onto the X and Y axes, the angle between them is
        ///                         returned. If set to false though, the result is the
        ///                         actual yaw that will be used to implement the quaternion,
        ///                         which is the shortest possible path to get to the same
        ///                         orientation and may involve less axial rotation.
        //--------------------------------------------------------------------------------
        Radian getRoll(bool reprojectAxis = true) const;

        //--------------------------------------------------------------------------------
        /// @brief  Calculate the local pitch element of this quaternion
        ///
        /// @param  reprojectAxis   By default the method returns the 'intuitive' result
        ///                         that is, if you projected the local Z of the quaternion
        ///                         onto the X and Y axes, the angle between them is
        ///                         returned. If set to false though, the result is the
        ///                         actual yaw that will be used to implement the quaternion,
        ///                         which is the shortest possible path to get to the same
        ///                         orientation and may involve less axial rotation.
        //--------------------------------------------------------------------------------
        Radian getPitch(bool reprojectAxis = true) const;

        //--------------------------------------------------------------------------------
        /// @brief  Calculate the local yaw element of this quaternion
        ///
        /// @param  reprojectAxis   By default the method returns the 'intuitive' result
        ///                         that is, if you projected the local Z of the quaternion
        ///                         onto the X and Y axes, the angle between them is
        ///                         returned. If set to false though, the result is the
        ///                         actual yaw that will be used to implement the quaternion,
        ///                         which is the shortest possible path to get to the same
        ///                         orientation and may involve less axial rotation.
        //--------------------------------------------------------------------------------
        Radian getYaw(bool reprojectAxis = true) const;

        //--------------------------------------------------------------------------------
        /// @brief  Equality with tolerance (tolerance is max angle difference)
        //--------------------------------------------------------------------------------
        bool equals(const Quaternion& rhs, const Radian& tolerance) const;

        //--------------------------------------------------------------------------------
        /// @brief  Check whether this quaternion contains valid values
        //--------------------------------------------------------------------------------
        inline bool isNaN() const
        {
            return MathUtils::isNaN(x) || MathUtils::isNaN(y) || MathUtils::isNaN(z) ||
                   MathUtils::isNaN(w);
        }


        //_____ Arithmetic operations __________
    public:
        Quaternion operator+(const Quaternion& rkQ) const;
        Quaternion operator-(const Quaternion& rkQ) const;
        Quaternion operator*(const Quaternion& rkQ) const;
        Quaternion operator*(Real fScalar) const;
        Quaternion operator-() const;

        inline friend Quaternion operator*(Real fScalar, const Quaternion& rkQ)
        {
            return Quaternion(fScalar*rkQ.w,fScalar*rkQ.x,fScalar*rkQ.y,
                              fScalar*rkQ.z);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Rotation of a vector by a quaternion
        //--------------------------------------------------------------------------------
        Vector3 operator*(const Vector3& rkVector) const;


        //_____ Comparison operations __________
    public:
        inline bool operator==(const Quaternion& rhs) const
        {
            return (rhs.x == x) && (rhs.y == y) &&
                (rhs.z == z) && (rhs.w == w);
        }

        inline bool operator!=(const Quaternion& rhs) const
        {
            return !operator==(rhs);
        }


        //_____ Interpolation __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Spherical linear interpolation
        //--------------------------------------------------------------------------------
        static Quaternion Slerp(Real fT, const Quaternion& rkP, const Quaternion& rkQ,
                                bool shortestPath = false);

        //--------------------------------------------------------------------------------
        /// @brief  Spherical linear interpolation
        //--------------------------------------------------------------------------------
        static Quaternion SlerpExtraSpins(Real fT, const Quaternion& rkP,
                                          const Quaternion& rkQ, int iExtraSpins);

        //--------------------------------------------------------------------------------
        /// @brief  Setup for spherical quadratic interpolation
        //--------------------------------------------------------------------------------
        static void Intermediate(const Quaternion& rkQ0, const Quaternion& rkQ1,
                                 const Quaternion& rkQ2, Quaternion& rka, Quaternion& rkB);

        //--------------------------------------------------------------------------------
        /// @brief  Spherical quadratic interpolation
        //--------------------------------------------------------------------------------
        static Quaternion Squad(Real fT, const Quaternion& rkP, const Quaternion& rkA,
                                const Quaternion& rkB, const Quaternion& rkQ,
                                bool shortestPath = false);

        //--------------------------------------------------------------------------------
        /// @brief  Normalised linear interpolation - faster but less accurate
        ///         (non-constant rotation velocity)
        //--------------------------------------------------------------------------------
        static Quaternion nlerp(Real fT, const Quaternion& rkP, const Quaternion& rkQ,
                                bool shortestPath = false);


        //_____ Constants __________
    public:
        static const Quaternion ZERO;
        static const Quaternion IDENTITY;
        static const Real SINE_CUTOFF;      ///< Cutoff for sine near zero


        //_____ Attributes __________
    public:
        Real w, x, y, z;
    };

    /** @} */
    /** @} */
}
}

#endif

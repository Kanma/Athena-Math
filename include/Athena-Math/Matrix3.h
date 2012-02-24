/** @file   Matrix3.h
    @author Philip Abbet

    Declaration of the class Athena::Math::Matrix3

    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#ifndef _ATHENA_MATH_MATRIX3_H_
#define _ATHENA_MATH_MATRIX3_H_

#include <Athena-Math/Prerequisites.h>
#include <Athena-Math/MathUtils.h>
#include <Athena-Math/Vector3.h>


namespace Athena {
namespace Math {

    /** \addtogroup Math
    *  @{
    */

    //------------------------------------------------------------------------------------
    /// @brief  A 3x3 matrix which can represent rotations around axes
    ///
    /// The coordinate system is assumed to be right-handed.
    /// Coordinate axis rotation matrices are of the form
    ///   RX =    1       0       0
    ///           0     cos(t) -sin(t)
    ///           0     sin(t)  cos(t)
    /// where t > 0 indicates a counterclockwise rotation in the yz-plane
    ///   RY =  cos(t)    0     sin(t)
    ///           0       1       0
    ///        -sin(t)    0     cos(t)
    /// where t > 0 indicates a counterclockwise rotation in the zx-plane
    ///   RZ =  cos(t) -sin(t)    0
    ///         sin(t)  cos(t)    0
    ///           0       0       1
    /// where t > 0 indicates a counterclockwise rotation in the xy-plane.
    //------------------------------------------------------------------------------------
    class ATHENA_MATH_SYMBOL Matrix3
    {
        //_____ Construction / Destruction __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Default constructor
        /// @note   It does <b>NOT</b> initialize the matrix for efficiency.
        //--------------------------------------------------------------------------------
        inline Matrix3() {}

        inline explicit Matrix3(const Real arr[3][3])
        {
            memcpy(m, arr, 9 * sizeof(Real));
        }

        inline Matrix3(const Matrix3& rkMatrix)
        {
            memcpy(m, rkMatrix.m, 9 * sizeof(Real));
        }

        Matrix3(Real fEntry00, Real fEntry01, Real fEntry02,
                Real fEntry10, Real fEntry11, Real fEntry12,
                Real fEntry20, Real fEntry21, Real fEntry22)
        {
            m[0][0] = fEntry00;
            m[0][1] = fEntry01;
            m[0][2] = fEntry02;
            m[1][0] = fEntry10;
            m[1][1] = fEntry11;
            m[1][2] = fEntry12;
            m[2][0] = fEntry20;
            m[2][1] = fEntry21;
            m[2][2] = fEntry22;
        }


        //_____ Value retrieval __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Member access, allows use of construct mat[r][c]
        //--------------------------------------------------------------------------------
        inline Real* operator[](size_t iRow) const
        {
            return (Real*) m[iRow];
        }

        Vector3 GetColumn(size_t iCol) const;


        //_____ Value assignation __________
    public:
        void SetColumn(size_t iCol, const Vector3& vec);

        void FromAxes(const Vector3& xAxis, const Vector3& yAxis, const Vector3& zAxis);

        void FromAxisAngle(const Vector3& rkAxis, const Radian& fRadians);

        inline Matrix3& operator=(const Matrix3& rkMatrix)
        {
            memcpy(m, rkMatrix.m, 9 * sizeof(Real));
            return *this;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Initialization from 3 angles
        /// @remark The decomposition is yaw*pitch*roll where yaw is rotation about the Up
        ///         vector, pitch is rotation about the Right axis, and roll is rotation
        ///         about the Direction axis.
        //--------------------------------------------------------------------------------
        void FromEulerAnglesXYZ(const Radian& fYAngle, const Radian& fPAngle, const Radian& fRAngle);
        void FromEulerAnglesXZY(const Radian& fYAngle, const Radian& fPAngle, const Radian& fRAngle);
        void FromEulerAnglesYXZ(const Radian& fYAngle, const Radian& fPAngle, const Radian& fRAngle);
        void FromEulerAnglesYZX(const Radian& fYAngle, const Radian& fPAngle, const Radian& fRAngle);
        void FromEulerAnglesZXY(const Radian& fYAngle, const Radian& fPAngle, const Radian& fRAngle);
        void FromEulerAnglesZYX(const Radian& fYAngle, const Radian& fPAngle, const Radian& fRAngle);

        //--------------------------------------------------------------------------------
        /// @brief  Exchange the contents of this matrix with another
        //--------------------------------------------------------------------------------
        inline void swap(Matrix3& other)
        {
            std::swap(m[0][0], other.m[0][0]);
            std::swap(m[0][1], other.m[0][1]);
            std::swap(m[0][2], other.m[0][2]);
            std::swap(m[1][0], other.m[1][0]);
            std::swap(m[1][1], other.m[1][1]);
            std::swap(m[1][2], other.m[1][2]);
            std::swap(m[2][0], other.m[2][0]);
            std::swap(m[2][1], other.m[2][1]);
            std::swap(m[2][2], other.m[2][2]);
        }


        //_____ Comparison operations __________
    public:
        bool operator==(const Matrix3& rkMatrix) const;

        inline bool operator!=(const Matrix3& rkMatrix) const
        {
            return !operator==(rkMatrix);
        }


        //_____ Arithmetic operations __________
    public:
        Matrix3 operator+(const Matrix3& rkMatrix) const;
        Matrix3 operator-(const Matrix3& rkMatrix) const;
        Matrix3 operator*(const Matrix3& rkMatrix) const;
        Matrix3 operator-() const;

        //--------------------------------------------------------------------------------
        /// @brief  matrix * vector [3x3 * 3x1 = 3x1]
        //--------------------------------------------------------------------------------
        Vector3 operator*(const Vector3& rkVector) const;

        //--------------------------------------------------------------------------------
        /// @brief  vector * matrix [1x3 * 3x3 = 1x3]
        //--------------------------------------------------------------------------------
        inline friend Vector3 operator*(const Vector3& rkVector, const Matrix3& rkMatrix)
        {
            Vector3 kProd;
            for (size_t iRow = 0; iRow < 3; ++iRow)
            {
                kProd[iRow] =
                    rkVector[0]*rkMatrix.m[0][iRow] +
                    rkVector[1]*rkMatrix.m[1][iRow] +
                    rkVector[2]*rkMatrix.m[2][iRow];
            }

            return kProd;
        }

        //--------------------------------------------------------------------------------
        /// @brief  matrix * scalar
        //--------------------------------------------------------------------------------
        Matrix3 operator*(Real fScalar) const;

        //--------------------------------------------------------------------------------
        /// @brief  scalar * matrix
        //--------------------------------------------------------------------------------
        inline friend Matrix3 operator*(Real fScalar, const Matrix3& rkMatrix)
        {
            Matrix3 kProd;
            for (size_t iRow = 0; iRow < 3; ++iRow)
            {
                for (size_t iCol = 0; iCol < 3; ++iCol)
                    kProd[iRow][iCol] = fScalar * rkMatrix.m[iRow][iCol];
            }

            return kProd;
        }


        //_____ Methods __________
    public:
        Matrix3 Transpose() const;
        bool Inverse(Matrix3& rkInverse, Real fTolerance = 1e-06) const;
        Matrix3 Inverse(Real fTolerance = 1e-06) const;
        Real Determinant() const;

        //--------------------------------------------------------------------------------
        /// @brief  matrix -> rotation around a vector
        /// @remark The matrix must be orthonormal
        //--------------------------------------------------------------------------------
        void ToAxisAngle(Vector3& rkAxis, Radian& rfAngle) const;

        //--------------------------------------------------------------------------------
        /// @brief  matrix -> rotation around a vector
        /// @remark The matrix must be orthonormal
        //--------------------------------------------------------------------------------
        inline void ToAxisAngle(Vector3& rkAxis, Degree& rfAngle) const
        {
            Radian r;
            ToAxisAngle(rkAxis, r);
            rfAngle = r;
        }

        //--------------------------------------------------------------------------------
        /// @brief  matrix -> 3 angles
        /// @remark The matrix must be orthonormal. The decomposition is yaw*pitch*roll
        ///         where yaw is rotation about the Up vector, pitch is rotation about the
        ///         Right axis, and roll is rotation about the Direction axis.
        //--------------------------------------------------------------------------------
        bool ToEulerAnglesXYZ(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;
        bool ToEulerAnglesXZY(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;
        bool ToEulerAnglesYXZ(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;
        bool ToEulerAnglesYZX(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;
        bool ToEulerAnglesZXY(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;
        bool ToEulerAnglesZYX(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const;


        //_____ Constants __________
    public:
        static const Real EPSILON;
        static const Matrix3 ZERO;
        static const Matrix3 IDENTITY;


        //_____ Attributes __________
    public:
        Real m[3][3];
    };

    /** @} */
    /** @} */
}
}

#endif

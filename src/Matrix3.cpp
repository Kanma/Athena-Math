/** @file   Matrix3.cpp
    @author Philip Abbet

    Implementation of the class Athena::Math::Matrix3

    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#include <Athena-Math/Matrix3.h>
#include <Athena-Math/MathUtils.h>

using namespace Athena::Math;


/************************************** CONSTANTS ***************************************/

const Real Matrix3::EPSILON = 1e-06;
const Matrix3 Matrix3::ZERO(0, 0, 0, 0, 0, 0, 0, 0, 0);
const Matrix3 Matrix3::IDENTITY(1, 0, 0, 0, 1, 0, 0, 0, 1);


/*********************************** VALUE RETRIEVAL ************************************/

Vector3 Matrix3::GetColumn(size_t iCol) const
{
    assert(0 <= iCol && iCol < 3);

    return Vector3(m[0][iCol], m[1][iCol], m[2][iCol]);
}


/********************************** VALUE ASSIGNATION ***********************************/

void Matrix3::SetColumn(size_t iCol, const Vector3& vec)
{
    assert(0 <= iCol && iCol < 3);

    m[0][iCol] = vec.x;
    m[1][iCol] = vec.y;
    m[2][iCol] = vec.z;

}

//-----------------------------------------------------------------------

void Matrix3::FromAxes(const Vector3& xAxis, const Vector3& yAxis, const Vector3& zAxis)
{
    SetColumn(0,xAxis);
    SetColumn(1,yAxis);
    SetColumn(2,zAxis);
}

//-----------------------------------------------------------------------

void Matrix3::FromAxisAngle(const Vector3& rkAxis, const Radian& fRadians)
{
    Real fCos = MathUtils::Cos(fRadians);
    Real fSin = MathUtils::Sin(fRadians);
    Real fOneMinusCos = 1.0f-fCos;
    Real fX2 = rkAxis.x*rkAxis.x;
    Real fY2 = rkAxis.y*rkAxis.y;
    Real fZ2 = rkAxis.z*rkAxis.z;
    Real fXYM = rkAxis.x*rkAxis.y*fOneMinusCos;
    Real fXZM = rkAxis.x*rkAxis.z*fOneMinusCos;
    Real fYZM = rkAxis.y*rkAxis.z*fOneMinusCos;
    Real fXSin = rkAxis.x*fSin;
    Real fYSin = rkAxis.y*fSin;
    Real fZSin = rkAxis.z*fSin;

    m[0][0] = fX2*fOneMinusCos+fCos;
    m[0][1] = fXYM-fZSin;
    m[0][2] = fXZM+fYSin;
    m[1][0] = fXYM+fZSin;
    m[1][1] = fY2*fOneMinusCos+fCos;
    m[1][2] = fYZM-fXSin;
    m[2][0] = fXZM-fYSin;
    m[2][1] = fYZM+fXSin;
    m[2][2] = fZ2*fOneMinusCos+fCos;
}

//-----------------------------------------------------------------------

void Matrix3::FromEulerAnglesXYZ(const Radian& fYAngle, const Radian& fPAngle,
                                 const Radian& fRAngle)
{
    Real fCos, fSin;

    fCos = MathUtils::Cos(fYAngle);
    fSin = MathUtils::Sin(fYAngle);
    Matrix3 kXMat(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    fCos = MathUtils::Cos(fPAngle);
    fSin = MathUtils::Sin(fPAngle);
    Matrix3 kYMat(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    fCos = MathUtils::Cos(fRAngle);
    fSin = MathUtils::Sin(fRAngle);
    Matrix3 kZMat(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    *this = kXMat*(kYMat*kZMat);
}

//-----------------------------------------------------------------------

void Matrix3::FromEulerAnglesXZY(const Radian& fYAngle, const Radian& fPAngle,
                                 const Radian& fRAngle)
{
    Real fCos, fSin;

    fCos = MathUtils::Cos(fYAngle);
    fSin = MathUtils::Sin(fYAngle);
    Matrix3 kXMat(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    fCos = MathUtils::Cos(fPAngle);
    fSin = MathUtils::Sin(fPAngle);
    Matrix3 kZMat(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    fCos = MathUtils::Cos(fRAngle);
    fSin = MathUtils::Sin(fRAngle);
    Matrix3 kYMat(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    *this = kXMat*(kZMat*kYMat);
}

//-----------------------------------------------------------------------

void Matrix3::FromEulerAnglesYXZ(const Radian& fYAngle, const Radian& fPAngle,
                                 const Radian& fRAngle)
{
    Real fCos, fSin;

    fCos = MathUtils::Cos(fYAngle);
    fSin = MathUtils::Sin(fYAngle);
    Matrix3 kYMat(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    fCos = MathUtils::Cos(fPAngle);
    fSin = MathUtils::Sin(fPAngle);
    Matrix3 kXMat(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    fCos = MathUtils::Cos(fRAngle);
    fSin = MathUtils::Sin(fRAngle);
    Matrix3 kZMat(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    *this = kYMat*(kXMat*kZMat);
}

//-----------------------------------------------------------------------

void Matrix3::FromEulerAnglesYZX(const Radian& fYAngle, const Radian& fPAngle,
                                 const Radian& fRAngle)
{
    Real fCos, fSin;

    fCos = MathUtils::Cos(fYAngle);
    fSin = MathUtils::Sin(fYAngle);
    Matrix3 kYMat(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    fCos = MathUtils::Cos(fPAngle);
    fSin = MathUtils::Sin(fPAngle);
    Matrix3 kZMat(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    fCos = MathUtils::Cos(fRAngle);
    fSin = MathUtils::Sin(fRAngle);
    Matrix3 kXMat(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    *this = kYMat*(kZMat*kXMat);
}

//-----------------------------------------------------------------------

void Matrix3::FromEulerAnglesZXY(const Radian& fYAngle, const Radian& fPAngle,
                                 const Radian& fRAngle)
{
    Real fCos, fSin;

    fCos = MathUtils::Cos(fYAngle);
    fSin = MathUtils::Sin(fYAngle);
    Matrix3 kZMat(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    fCos = MathUtils::Cos(fPAngle);
    fSin = MathUtils::Sin(fPAngle);
    Matrix3 kXMat(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    fCos = MathUtils::Cos(fRAngle);
    fSin = MathUtils::Sin(fRAngle);
    Matrix3 kYMat(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    *this = kZMat*(kXMat*kYMat);
}

//-----------------------------------------------------------------------

void Matrix3::FromEulerAnglesZYX(const Radian& fYAngle, const Radian& fPAngle,
                                 const Radian& fRAngle)
{
    Real fCos, fSin;

    fCos = MathUtils::Cos(fYAngle);
    fSin = MathUtils::Sin(fYAngle);
    Matrix3 kZMat(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    fCos = MathUtils::Cos(fPAngle);
    fSin = MathUtils::Sin(fPAngle);
    Matrix3 kYMat(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    fCos = MathUtils::Cos(fRAngle);
    fSin = MathUtils::Sin(fRAngle);
    Matrix3 kXMat(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    *this = kZMat*(kYMat*kXMat);
}


/******************************** COMPARISON OPERATIONS *********************************/

bool Matrix3::operator==(const Matrix3& rkMatrix) const
{
    for (size_t iRow = 0; iRow < 3; ++iRow)
    {
        for (size_t iCol = 0; iCol < 3; ++iCol)
        {
            if (m[iRow][iCol] != rkMatrix.m[iRow][iCol])
                return false;
        }
    }

    return true;
}


/******************************** ARITHMETIC OPERATIONS *********************************/

Matrix3 Matrix3::operator+(const Matrix3& rkMatrix) const
{
    Matrix3 kSum;
    for (size_t iRow = 0; iRow < 3; ++iRow)
    {
        for (size_t iCol = 0; iCol < 3; ++iCol)
        {
            kSum.m[iRow][iCol] = m[iRow][iCol] + rkMatrix.m[iRow][iCol];
        }
    }

    return kSum;
}

//-----------------------------------------------------------------------

Matrix3 Matrix3::operator-(const Matrix3& rkMatrix) const
{
    Matrix3 kDiff;
    for (size_t iRow = 0; iRow < 3; ++iRow)
    {
        for (size_t iCol = 0; iCol < 3; ++iCol)
        {
            kDiff.m[iRow][iCol] = m[iRow][iCol] - rkMatrix.m[iRow][iCol];
        }
    }

    return kDiff;
}

//-----------------------------------------------------------------------

Matrix3 Matrix3::operator*(const Matrix3& rkMatrix) const
{
    Matrix3 kProd;
    for (size_t iRow = 0; iRow < 3; ++iRow)
    {
        for (size_t iCol = 0; iCol < 3; ++iCol)
        {
            kProd.m[iRow][iCol] =
                m[iRow][0]*rkMatrix.m[0][iCol] +
                m[iRow][1]*rkMatrix.m[1][iCol] +
                m[iRow][2]*rkMatrix.m[2][iCol];
        }
    }

    return kProd;
}

//-----------------------------------------------------------------------

Vector3 Matrix3::operator*(const Vector3& rkPoint) const
{
    Vector3 kProd;
    for (size_t iRow = 0; iRow < 3; ++iRow)
    {
        kProd[iRow] =
            m[iRow][0]*rkPoint[0] +
            m[iRow][1]*rkPoint[1] +
            m[iRow][2]*rkPoint[2];
    }

    return kProd;
}

//-----------------------------------------------------------------------

Matrix3 Matrix3::operator-() const
{
    Matrix3 kNeg;
    for (size_t iRow = 0; iRow < 3; ++iRow)
    {
        for (size_t iCol = 0; iCol < 3; ++iCol)
            kNeg[iRow][iCol] = -m[iRow][iCol];
    }

    return kNeg;
}

//-----------------------------------------------------------------------

Matrix3 Matrix3::operator*(Real fScalar) const
{
    Matrix3 kProd;
    for (size_t iRow = 0; iRow < 3; ++iRow)
    {
        for (size_t iCol = 0; iCol < 3; ++iCol)
            kProd[iRow][iCol] = fScalar * m[iRow][iCol];
    }

    return kProd;
}


/*************************************** METHODS ****************************************/

Matrix3 Matrix3::Transpose() const
{
    Matrix3 kTranspose;
    for (size_t iRow = 0; iRow < 3; ++iRow)
    {
        for (size_t iCol = 0; iCol < 3; ++iCol)
            kTranspose[iRow][iCol] = m[iCol][iRow];
    }

    return kTranspose;
}

//-----------------------------------------------------------------------

bool Matrix3::Inverse(Matrix3& rkInverse, Real fTolerance) const
{
    // Invert a 3x3 using cofactors. This is about 8 times faster than
    // the Numerical Recipes code which uses Gaussian elimination.

    rkInverse[0][0] = m[1][1]*m[2][2] - m[1][2]*m[2][1];
    rkInverse[0][1] = m[0][2]*m[2][1] - m[0][1]*m[2][2];
    rkInverse[0][2] = m[0][1]*m[1][2] - m[0][2]*m[1][1];
    rkInverse[1][0] = m[1][2]*m[2][0] - m[1][0]*m[2][2];
    rkInverse[1][1] = m[0][0]*m[2][2] - m[0][2]*m[2][0];
    rkInverse[1][2] = m[0][2]*m[1][0] - m[0][0]*m[1][2];
    rkInverse[2][0] = m[1][0]*m[2][1] - m[1][1]*m[2][0];
    rkInverse[2][1] = m[0][1]*m[2][0] - m[0][0]*m[2][1];
    rkInverse[2][2] = m[0][0]*m[1][1] - m[0][1]*m[1][0];

    Real fDet =
        m[0][0] * rkInverse[0][0] +
        m[0][1] * rkInverse[1][0]+
        m[0][2] * rkInverse[2][0];

    if (MathUtils::Abs(fDet) <= fTolerance)
        return false;

    Real fInvDet = 1.0f / fDet;
    for (size_t iRow = 0; iRow < 3; ++iRow)
    {
        for (size_t iCol = 0; iCol < 3; ++iCol)
            rkInverse[iRow][iCol] *= fInvDet;
    }

    return true;
}

//-----------------------------------------------------------------------

Matrix3 Matrix3::Inverse(Real fTolerance) const
{
    Matrix3 kInverse(Matrix3::ZERO);
    Inverse(kInverse,fTolerance);
    return kInverse;
}

//-----------------------------------------------------------------------

Real Matrix3::Determinant() const
{
    Real fCofactor00 = m[1][1]*m[2][2] - m[1][2]*m[2][1];
    Real fCofactor10 = m[1][2]*m[2][0] - m[1][0]*m[2][2];
    Real fCofactor20 = m[1][0]*m[2][1] - m[1][1]*m[2][0];

    Real fDet =
        m[0][0]*fCofactor00 +
        m[0][1]*fCofactor10 +
        m[0][2]*fCofactor20;

    return fDet;
}

//-----------------------------------------------------------------------

void Matrix3::ToAxisAngle(Vector3& rkAxis, Radian& rfRadians) const
{
    // Let (x,y,z) be the unit-length axis and let A be an angle of rotation.
    // The rotation matrix is R = I + sin(A)*P + (1-cos(A))*P^2 where
    // I is the identity and
    //
    //       +-        -+
    //   P = |  0 -z +y |
    //       | +z  0 -x |
    //       | -y +x  0 |
    //       +-        -+
    //
    // If A > 0, R represents a counterclockwise rotation about the axis in
    // the sense of looking from the tip of the axis vector towards the
    // origin.  Some algebra will show that
    //
    //   cos(A) = (trace(R)-1)/2  and  R - R^t = 2*sin(A)*P
    //
    // In the event that A = pi, R-R^t = 0 which prevents us from extracting
    // the axis through P.  Instead note that R = I+2*P^2 when A = pi, so
    // P^2 = (R-I)/2.  The diagonal entries of P^2 are x^2-1, y^2-1, and
    // z^2-1.  We can solve these for axis (x,y,z).  Because the angle is pi,
    // it does not matter which sign you choose on the square roots.

    Real fTrace = m[0][0] + m[1][1] + m[2][2];
    Real fCos = 0.5f*(fTrace-1.0f);
    rfRadians = MathUtils::ACos(fCos);  // in [0,PI]

    if ( rfRadians > Radian(0.0) )
    {
        if ( rfRadians < Radian(MathUtils::PI) )
        {
            rkAxis.x = m[2][1]-m[1][2];
            rkAxis.y = m[0][2]-m[2][0];
            rkAxis.z = m[1][0]-m[0][1];
            rkAxis.normalise();
        }
        else
        {
            // angle is PI
            float fHalfInverse;
            if ( m[0][0] >= m[1][1] )
            {
                // r00 >= r11
                if ( m[0][0] >= m[2][2] )
                {
                    // r00 is maximum diagonal term
                    rkAxis.x = 0.5f*MathUtils::Sqrt(m[0][0] -
                        m[1][1] - m[2][2] + 1.0f);
                    fHalfInverse = 0.5f/rkAxis.x;
                    rkAxis.y = fHalfInverse*m[0][1];
                    rkAxis.z = fHalfInverse*m[0][2];
                }
                else
                {
                    // r22 is maximum diagonal term
                    rkAxis.z = 0.5f*MathUtils::Sqrt(m[2][2] -
                        m[0][0] - m[1][1] + 1.0f);
                    fHalfInverse = 0.5f/rkAxis.z;
                    rkAxis.x = fHalfInverse*m[0][2];
                    rkAxis.y = fHalfInverse*m[1][2];
                }
            }
            else
            {
                // r11 > r00
                if ( m[1][1] >= m[2][2] )
                {
                    // r11 is maximum diagonal term
                    rkAxis.y = 0.5f*MathUtils::Sqrt(m[1][1] -
                        m[0][0] - m[2][2] + 1.0f);
                    fHalfInverse  = 0.5f/rkAxis.y;
                    rkAxis.x = fHalfInverse*m[0][1];
                    rkAxis.z = fHalfInverse*m[1][2];
                }
                else
                {
                    // r22 is maximum diagonal term
                    rkAxis.z = 0.5f*MathUtils::Sqrt(m[2][2] -
                        m[0][0] - m[1][1] + 1.0f);
                    fHalfInverse = 0.5f/rkAxis.z;
                    rkAxis.x = fHalfInverse*m[0][2];
                    rkAxis.y = fHalfInverse*m[1][2];
                }
            }
        }
    }
    else
    {
        // The angle is 0 and the matrix is the identity.  Any axis will
        // work, so just use the x-axis.
        rkAxis.x = 1.0;
        rkAxis.y = 0.0;
        rkAxis.z = 0.0;
    }
}

//-----------------------------------------------------------------------

bool Matrix3::ToEulerAnglesXYZ(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const
{
    // rot =  cy*cz          -cy*sz           sy
    //        cz*sx*sy+cx*sz  cx*cz-sx*sy*sz -cy*sx
    //       -cx*cz*sy+sx*sz  cz*sx+cx*sy*sz  cx*cy

    rfPAngle = Radian(MathUtils::ASin(m[0][2]));
    if ( rfPAngle < Radian(MathUtils::HALF_PI) )
    {
        if ( rfPAngle > Radian(-MathUtils::HALF_PI) )
        {
            rfYAngle = MathUtils::ATan2(-m[1][2],m[2][2]);
            rfRAngle = MathUtils::ATan2(-m[0][1],m[0][0]);
            return true;
        }
        else
        {
            // WARNING.  Not a unique solution.
            Radian fRmY = MathUtils::ATan2(m[1][0],m[1][1]);
            rfRAngle = Radian(0.0);  // any angle works
            rfYAngle = rfRAngle - fRmY;
            return false;
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        Radian fRpY = MathUtils::ATan2(m[1][0],m[1][1]);
        rfRAngle = Radian(0.0);  // any angle works
        rfYAngle = fRpY - rfRAngle;
        return false;
    }
}

//-----------------------------------------------------------------------

bool Matrix3::ToEulerAnglesXZY(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const
{
    // rot =  cy*cz          -sz              cz*sy
    //        sx*sy+cx*cy*sz  cx*cz          -cy*sx+cx*sy*sz
    //       -cx*sy+cy*sx*sz  cz*sx           cx*cy+sx*sy*sz

    rfPAngle = MathUtils::ASin(-m[0][1]);
    if ( rfPAngle < Radian(MathUtils::HALF_PI) )
    {
        if ( rfPAngle > Radian(-MathUtils::HALF_PI) )
        {
            rfYAngle = MathUtils::ATan2(m[2][1],m[1][1]);
            rfRAngle = MathUtils::ATan2(m[0][2],m[0][0]);
            return true;
        }
        else
        {
            // WARNING.  Not a unique solution.
            Radian fRmY = MathUtils::ATan2(-m[2][0],m[2][2]);
            rfRAngle = Radian(0.0);  // any angle works
            rfYAngle = rfRAngle - fRmY;
            return false;
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        Radian fRpY = MathUtils::ATan2(-m[2][0],m[2][2]);
        rfRAngle = Radian(0.0);  // any angle works
        rfYAngle = fRpY - rfRAngle;
        return false;
    }
}

//-----------------------------------------------------------------------

bool Matrix3::ToEulerAnglesYXZ(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const
{
    // rot =  cy*cz+sx*sy*sz  cz*sx*sy-cy*sz  cx*sy
    //        cx*sz           cx*cz          -sx
    //       -cz*sy+cy*sx*sz  cy*cz*sx+sy*sz  cx*cy

    rfPAngle = MathUtils::ASin(-m[1][2]);
    if ( rfPAngle < Radian(MathUtils::HALF_PI) )
    {
        if ( rfPAngle > Radian(-MathUtils::HALF_PI) )
        {
            rfYAngle = MathUtils::ATan2(m[0][2],m[2][2]);
            rfRAngle = MathUtils::ATan2(m[1][0],m[1][1]);
            return true;
        }
        else
        {
            // WARNING.  Not a unique solution.
            Radian fRmY = MathUtils::ATan2(-m[0][1],m[0][0]);
            rfRAngle = Radian(0.0);  // any angle works
            rfYAngle = rfRAngle - fRmY;
            return false;
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        Radian fRpY = MathUtils::ATan2(-m[0][1],m[0][0]);
        rfRAngle = Radian(0.0);  // any angle works
        rfYAngle = fRpY - rfRAngle;
        return false;
    }
}

//-----------------------------------------------------------------------

bool Matrix3::ToEulerAnglesYZX(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const
{
    // rot =  cy*cz           sx*sy-cx*cy*sz  cx*sy+cy*sx*sz
    //        sz              cx*cz          -cz*sx
    //       -cz*sy           cy*sx+cx*sy*sz  cx*cy-sx*sy*sz

    rfPAngle = MathUtils::ASin(m[1][0]);
    if ( rfPAngle < Radian(MathUtils::HALF_PI) )
    {
        if ( rfPAngle > Radian(-MathUtils::HALF_PI) )
        {
            rfYAngle = MathUtils::ATan2(-m[2][0],m[0][0]);
            rfRAngle = MathUtils::ATan2(-m[1][2],m[1][1]);
            return true;
        }
        else
        {
            // WARNING.  Not a unique solution.
            Radian fRmY = MathUtils::ATan2(m[2][1],m[2][2]);
            rfRAngle = Radian(0.0);  // any angle works
            rfYAngle = rfRAngle - fRmY;
            return false;
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        Radian fRpY = MathUtils::ATan2(m[2][1],m[2][2]);
        rfRAngle = Radian(0.0);  // any angle works
        rfYAngle = fRpY - rfRAngle;
        return false;
    }
}

//-----------------------------------------------------------------------

bool Matrix3::ToEulerAnglesZXY(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const
{
    // rot =  cy*cz-sx*sy*sz -cx*sz           cz*sy+cy*sx*sz
    //        cz*sx*sy+cy*sz  cx*cz          -cy*cz*sx+sy*sz
    //       -cx*sy           sx              cx*cy

    rfPAngle = MathUtils::ASin(m[2][1]);
    if ( rfPAngle < Radian(MathUtils::HALF_PI) )
    {
        if ( rfPAngle > Radian(-MathUtils::HALF_PI) )
        {
            rfYAngle = MathUtils::ATan2(-m[0][1],m[1][1]);
            rfRAngle = MathUtils::ATan2(-m[2][0],m[2][2]);
            return true;
        }
        else
        {
            // WARNING.  Not a unique solution.
            Radian fRmY = MathUtils::ATan2(m[0][2],m[0][0]);
            rfRAngle = Radian(0.0);  // any angle works
            rfYAngle = rfRAngle - fRmY;
            return false;
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        Radian fRpY = MathUtils::ATan2(m[0][2],m[0][0]);
        rfRAngle = Radian(0.0);  // any angle works
        rfYAngle = fRpY - rfRAngle;
        return false;
    }
}

//-----------------------------------------------------------------------

bool Matrix3::ToEulerAnglesZYX(Radian& rfYAngle, Radian& rfPAngle, Radian& rfRAngle) const
{
    // rot =  cy*cz           cz*sx*sy-cx*sz  cx*cz*sy+sx*sz
    //        cy*sz           cx*cz+sx*sy*sz -cz*sx+cx*sy*sz
    //       -sy              cy*sx           cx*cy

    rfPAngle = MathUtils::ASin(-m[2][0]);
    if ( rfPAngle < Radian(MathUtils::HALF_PI) )
    {
        if ( rfPAngle > Radian(-MathUtils::HALF_PI) )
        {
            rfYAngle = MathUtils::ATan2(m[1][0],m[0][0]);
            rfRAngle = MathUtils::ATan2(m[2][1],m[2][2]);
            return true;
        }
        else
        {
            // WARNING.  Not a unique solution.
            Radian fRmY = MathUtils::ATan2(-m[0][1],m[0][2]);
            rfRAngle = Radian(0.0);  // any angle works
            rfYAngle = rfRAngle - fRmY;
            return false;
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        Radian fRpY = MathUtils::ATan2(-m[0][1],m[0][2]);
        rfRAngle = Radian(0.0);  // any angle works
        rfYAngle = fRpY - rfRAngle;
        return false;
    }
}

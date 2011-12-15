/** @file   Vector3.h
    @author Philip Abbet
    
    Declaration of the class Athena::Math::Vector3
    
    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#ifndef _ATHENA_MATH_VECTOR3_H_
#define _ATHENA_MATH_VECTOR3_H_

#include <Athena-Math/Prerequisites.h>
#include <Athena-Math/MathUtils.h>
#include <Athena-Math/Quaternion.h>


namespace Athena {
namespace Math {

	/** \addtogroup Math
	*  @{
	*/
	
	//------------------------------------------------------------------------------------
	/// @brief  Standard 3-dimensional vector
	/// 
	/// A direction in 3D space represented as distances along the 3 orthogonal axes
	/// (x, y, z). Note that positions, directions and scaling factors can be represented
	/// by a vector, depending on how you interpret the values.
	//------------------------------------------------------------------------------------
	class ATHENA_SYMBOL Vector3
	{
        //_____ Construction / Destruction __________
    public:
        inline Vector3()
        {
        }

        inline Vector3(const Real fX, const Real fY, const Real fZ)
        : x(fX), y(fY), z(fZ)
        {
        }

        inline explicit Vector3(const Real afCoordinate[3])
        : x(afCoordinate[0]),
          y(afCoordinate[1]),
          z(afCoordinate[2])
        {
        }

        inline explicit Vector3(const int afCoordinate[3])
        {
            x = (Real) afCoordinate[0];
            y = (Real) afCoordinate[1];
            z = (Real) afCoordinate[2];
        }

        inline explicit Vector3(Real* const r)
        : x(r[0]), y(r[1]), z(r[2])
        {
        }

        inline explicit Vector3(const Real scaler)
        : x(scaler), y(scaler), z(scaler)
        {
        }


        //_____ Value retrieval __________
    public:
		inline Real operator[](const size_t i) const
        {
            assert(i < 3);

            return *(&x+i);
        }

		inline Real& operator[](const size_t i)
        {
            assert(i < 3);

            return *(&x+i);
        }
        
        //--------------------------------------------------------------------------------
		/// @brief  Pointer accessor for direct copying
        //--------------------------------------------------------------------------------
		inline Real* ptr()
		{
			return &x;
		}

        //--------------------------------------------------------------------------------
		/// @brief  Pointer accessor for direct copying
        //--------------------------------------------------------------------------------
		inline const Real* ptr() const
		{
			return &x;
		}


        //_____ Value assignation __________
    public:
        inline Vector3& operator=(const Vector3& rkVector)
        {
            x = rkVector.x;
            y = rkVector.y;
            z = rkVector.z;

            return *this;
        }

        inline Vector3& operator=(const Real fScaler)
        {
            x = fScaler;
            y = fScaler;
            z = fScaler;

            return *this;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Exchange the contents of this vector with another
        //--------------------------------------------------------------------------------
		inline void swap(Vector3& other)
		{
			std::swap(x, other.x);
			std::swap(y, other.y);
			std::swap(z, other.z);
		}


        //_____ Comparison operations __________
    public:
        inline bool operator==(const Vector3& rkVector) const
        {
            return (x == rkVector.x && y == rkVector.y && z == rkVector.z);
        }

        inline bool operator!=(const Vector3& rkVector) const
        {
            return (x != rkVector.x || y != rkVector.y || z != rkVector.z);
        }


        //_____ Arithmetic operations __________
    public:
        inline Vector3 operator+(const Vector3& rkVector) const
        {
            return Vector3(
                x + rkVector.x,
                y + rkVector.y,
                z + rkVector.z);
        }

        inline Vector3 operator-(const Vector3& rkVector) const
        {
            return Vector3(
                x - rkVector.x,
                y - rkVector.y,
                z - rkVector.z);
        }

        inline Vector3 operator*(const Real fScalar) const
        {
            return Vector3(
                x * fScalar,
                y * fScalar,
                z * fScalar);
        }

        inline Vector3 operator*(const Vector3& rhs) const
        {
            return Vector3(
                x * rhs.x,
                y * rhs.y,
                z * rhs.z);
        }

        inline Vector3 operator/(const Real fScalar) const
        {
            assert(fScalar != 0.0);

            Real fInv = 1.0f / fScalar;

            return Vector3(
                x * fInv,
                y * fInv,
                z * fInv);
        }

        inline Vector3 operator/(const Vector3& rhs) const
        {
            return Vector3(
                x / rhs.x,
                y / rhs.y,
                z / rhs.z);
        }

        inline const Vector3& operator+() const
        {
            return *this;
        }

        inline Vector3 operator-() const
        {
            return Vector3(-x, -y, -z);
        }

        inline friend Vector3 operator*(const Real fScalar, const Vector3& rkVector)
        {
            return Vector3(
                fScalar * rkVector.x,
                fScalar * rkVector.y,
                fScalar * rkVector.z);
        }

        inline friend Vector3 operator/(const Real fScalar, const Vector3& rkVector)
        {
            return Vector3(
                fScalar / rkVector.x,
                fScalar / rkVector.y,
                fScalar / rkVector.z);
        }

        inline friend Vector3 operator+(const Vector3& lhs, const Real rhs)
        {
            return Vector3(
                lhs.x + rhs,
                lhs.y + rhs,
                lhs.z + rhs);
        }

        inline friend Vector3 operator+(const Real lhs, const Vector3& rhs)
        {
            return Vector3(
                lhs + rhs.x,
                lhs + rhs.y,
                lhs + rhs.z);
        }

        inline friend Vector3 operator-(const Vector3& lhs, const Real rhs)
        {
            return Vector3(
                lhs.x - rhs,
                lhs.y - rhs,
                lhs.z - rhs);
        }

        inline friend Vector3 operator-(const Real lhs, const Vector3& rhs)
        {
            return Vector3(
                lhs - rhs.x,
                lhs - rhs.y,
                lhs - rhs.z);
        }


        //_____ Arithmetic updates __________
    public:
        inline Vector3& operator+=(const Vector3& rkVector)
        {
            x += rkVector.x;
            y += rkVector.y;
            z += rkVector.z;

            return *this;
        }

        inline Vector3& operator+=(const Real fScalar)
        {
            x += fScalar;
            y += fScalar;
            z += fScalar;
            return *this;
        }

        inline Vector3& operator-=(const Vector3& rkVector)
        {
            x -= rkVector.x;
            y -= rkVector.y;
            z -= rkVector.z;

            return *this;
        }

        inline Vector3& operator-=(const Real fScalar)
        {
            x -= fScalar;
            y -= fScalar;
            z -= fScalar;
            return *this;
        }

        inline Vector3& operator*=(const Real fScalar)
        {
            x *= fScalar;
            y *= fScalar;
            z *= fScalar;
            return *this;
        }

        inline Vector3& operator*=(const Vector3& rkVector)
        {
            x *= rkVector.x;
            y *= rkVector.y;
            z *= rkVector.z;

            return *this;
        }

        inline Vector3& operator/=(const Real fScalar)
        {
            assert(fScalar != 0.0);

            Real fInv = 1.0f / fScalar;

            x *= fInv;
            y *= fInv;
            z *= fInv;

            return *this;
        }

        inline Vector3& operator/=(const Vector3& rkVector)
        {
            x /= rkVector.x;
            y /= rkVector.y;
            z /= rkVector.z;

            return *this;
        }


        //_____ Methods __________
    public:
        //--------------------------------------------------------------------------------
		/// @brief  Returns the length (magnitude) of the vector
		///
		/// @warning    This operation requires a square root and is expensive in terms of
		///             CPU operations. If you don't need to know the exact length (e.g.
		///             for just comparing lengths) use squaredLength() instead.
        //--------------------------------------------------------------------------------
        inline Real length() const
        {
            return MathUtils::Sqrt(x * x + y * y + z * z);
        }

        //--------------------------------------------------------------------------------
		/// @brief  Returns the square of the length (magnitude) of the vector
		///
		/// @remark This method is for efficiency - calculating the actual length of a
		///         vector requires a square root, which is expensive in terms of the
		///         operations required. This method returns the square of the length of
		///         the vector, i.e. the same as the length but before the square root is
		///         taken. Use this if you want to find the longest / shortest vector
		///         without incurring the square root.
        //--------------------------------------------------------------------------------
        inline Real squaredLength() const
        {
            return x * x + y * y + z * z;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Returns the distance to another vector
		///
		/// @warning    This operation requires a square root and is expensive in terms of
		///             CPU operations. If you don't need to know the exact distance (e.g.
		///             for just comparing distances) use squaredDistance() instead.
        //--------------------------------------------------------------------------------
        inline Real distance(const Vector3& rhs) const
        {
            return (*this - rhs).length();
        }

        //--------------------------------------------------------------------------------
		/// @brief  Returns the square of the distance to another vector
		///
		/// @remark This method is for efficiency - calculating the actual distance to
		///         another vector requires a square root, which is expensive in terms of
		///         the operations required. This method returns the square of the distance
		///         to another vector, i.e. the same as the distance but before the square
		///         root is taken. Use this if you want to find the longest / shortest
		///         distance without incurring the square root.
        //--------------------------------------------------------------------------------
        inline Real squaredDistance(const Vector3& rhs) const
        {
            return (*this - rhs).squaredLength();
        }

        //--------------------------------------------------------------------------------
		/// @brief  Calculates the dot (scalar) product of this vector with another
		///
		/// @remark The dot product can be used to calculate the angle between 2 vectors.
		///         If both are unit vectors, the dot product is the cosine of the angle;
		///         otherwise the dot product must be divided by the product of the
		///         lengths of both vectors to get the cosine of the angle. This result
		///         can further be used to calculate the distance of a point from a plane.
		///
        /// @param  vec     Vector with which to calculate the dot product (together with
        ///                 this one)
        /// @return         A real representing the dot product value
        //--------------------------------------------------------------------------------
        inline Real dotProduct(const Vector3& vec) const
        {
            return x * vec.x + y * vec.y + z * vec.z;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Calculates the absolute dot (scalar) product of this vector with
		///         another
		///
		/// @remark This function work like dotProduct, except that it use the absolute
        ///         value of each component of the vector while computing
		///
        /// @param  vec     Vector with which to calculate the absolute dot product
        ///                 (together with this one)
        /// @return         A real representing the absolute dot product value
        //--------------------------------------------------------------------------------
        inline Real absDotProduct(const Vector3& vec) const
        {
            return MathUtils::Abs(x * vec.x) + MathUtils::Abs(y * vec.y) + MathUtils::Abs(z * vec.z);
        }

        //--------------------------------------------------------------------------------
		/// @brief  Normalises the vector
		///
		/// This method normalises the vector such that it's length / magnitude is 1. The
		/// result is called a unit vector.
		///
        /// @return The previous length of the vector
        /// 
        /// @note   This function will not crash for zero-sized vectors, but there will be
        ///         no changes made to their components.
        //--------------------------------------------------------------------------------
        inline Real normalise()
        {
            Real fLength = MathUtils::Sqrt(x * x + y * y + z * z);

            // Will also work for zero-sized vectors, but will change nothing
            if (fLength > 1e-08)
            {
                Real fInvLength = 1.0f / fLength;
                x *= fInvLength;
                y *= fInvLength;
                z *= fInvLength;
            }

            return fLength;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Calculates the cross-product of 2 vectors, i.e. the vector that lies
        ///         lies perpendicular to them both
		///
        /// @remark The cross-product is normally used to calculate the normal vector of a
        ///         plane, by calculating the cross-product of 2 non-equivalent vectors
        ///         which lie on the plane (e.g. 2 edges of a triangle).
        ///
        /// @param  rkVector    Vector which, together with this one, will be used to
        ///                     calculate the cross-product
        ///
        /// @return A vector which is the result of the cross-product. This vector will
        ///         <b>NOT</b> be normalised, to maximise efficiency - call
        ///         Vector3::normalise on the result if you wish this to be done. As for
        ///         which side the resultant vector will be on, the returned vector will
        ///         be on the side from which the arc from 'this' to rkVector is
        ///         anticlockwise, e.g. UNIT_Y.crossProduct(UNIT_Z) = UNIT_X, whilst
        ///         UNIT_Z.crossProduct(UNIT_Y) = -UNIT_X. This is because Athena uses a
        ///         right-handed coordinate system.
        /// @par    For a clearer explanation, look a the left and the bottom edges of
        ///         your monitor's screen. Assume that the first vector is the left edge
        ///         and the second vector is the bottom edge, both of them starting from
        ///         the lower-left corner of the screen. The resulting vector is going to
        ///         be perpendicular to both of them and will go <i>inside</i> the screen,
        ///         towards the cathode tube (assuming you're using a CRT monitor, of
        ///         course).
        //--------------------------------------------------------------------------------
        inline Vector3 crossProduct(const Vector3& rkVector) const
        {
            return Vector3(
                y * rkVector.z - z * rkVector.y,
                z * rkVector.x - x * rkVector.z,
                x * rkVector.y - y * rkVector.x);
        }

        //--------------------------------------------------------------------------------
		/// @brief  Returns a vector at a point half way between this one and the passed
        ///         in vector
        //--------------------------------------------------------------------------------
        inline Vector3 midPoint(const Vector3& vec) const
        {
            return Vector3(
                (x + vec.x) * 0.5f,
                (y + vec.y) * 0.5f,
                (z + vec.z) * 0.5f);
        }

        //--------------------------------------------------------------------------------
		/// @brief  Sets this vector's components to the minimum of its own and the ones
		///         of the passed in vector
		///
        /// @remark 'Minimum' in this case means the combination of the lowest value of x,
        ///         y and z from both vectors. Lowest is taken just numerically, not
        ///         magnitude, so -1 < 0.
        //--------------------------------------------------------------------------------
        inline void makeFloor(const Vector3& cmp)
        {
            if(cmp.x < x) x = cmp.x;
            if(cmp.y < y) y = cmp.y;
            if(cmp.z < z) z = cmp.z;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Sets this vector's components to the maximum of its own and the ones
		///         of the passed in vector
		///
        /// @remark 'Maximum' in this case means the combination of the highest value of x,
        ///         y and z from both vectors. Highest is taken just numerically, not
        ///         magnitude, so 1 > -3.
        //--------------------------------------------------------------------------------
        inline void makeCeil(const Vector3& cmp)
        {
            if(cmp.x > x) x = cmp.x;
            if(cmp.y > y) y = cmp.y;
            if(cmp.z > z) z = cmp.z;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Generates a vector perpendicular to this vector (eg an 'up' vector)
		///
        /// @remark This method will return a vector which is perpendicular to this vector.
        ///         There are an infinite number of possibilities but this method will
        ///         guarantee to generate one of them. If you need more control you should
        ///         use the Quaternion class.
        //--------------------------------------------------------------------------------
        inline Vector3 perpendicular(void) const
        {
            static const Real fSquareZero = 1e-06 * 1e-06;

            Vector3 perp = this->crossProduct(Vector3::UNIT_X);

            // Check length
            if(perp.squaredLength() < fSquareZero)
            {
                // This vector is the Y axis multiplied by a scalar, so we have to use
                // another axis.
                perp = this->crossProduct(Vector3::UNIT_Y);
            }
			perp.normalise();

            return perp;
        }
        
        //--------------------------------------------------------------------------------
		/// @brief  Generates a new random vector which deviates from this vector by a
        ///         given angle in a random direction
		///
        /// @param  angle   The angle at which to deviate in radians
        /// @param  up      Any vector perpendicular to this one (which could be generated
        ///                 by cross-product of this vector and any other non-colinear
        ///                 vector). If you choose not to provide this the function will
        ///                 derive one on it's own, however if you provide one yourself
        ///                 the function will be faster (this allows you to reuse up
        ///                 vectors if you call this method more than once)
        /// @return         A random vector which deviates from this vector by angle. This
        ///                 vector will not be normalised, normalise it if you wish
        ///                 afterwards.
        ///    
        /// @remark This method assumes that the random number generator has already
        ///         been seeded appropriately.
        //--------------------------------------------------------------------------------
        inline Vector3 randomDeviant(const Radian& angle,
                                     const Vector3& up = Vector3::ZERO) const
        {
            Vector3 newUp;

            if (up == Vector3::ZERO)
            {
                // Generate an up vector
                newUp = this->perpendicular();
            }
            else
            {
                newUp = up;
            }

            // Rotate up vector by random amount around this
            Quaternion q;
            q.FromAngleAxis(Radian(MathUtils::UnitRandom() * MathUtils::TWO_PI), *this);
            newUp = q * newUp;

            // Finally rotate this by given angle around randomised up
            q.FromAngleAxis(angle, newUp);
            return q * (*this);
        }

        //--------------------------------------------------------------------------------
		/// @brief  Gets the angle between 2 vectors
        ///    
        /// @remark Vectors do not have to be unit-length but must represent directions.
        //--------------------------------------------------------------------------------
		inline Radian angleBetween(const Vector3& dest)
		{
			Real lenProduct = length() * dest.length();

			// Divide by zero check
			if(lenProduct < 1e-6f)
				lenProduct = 1e-6f;

			Real f = dotProduct(dest) / lenProduct;

			f = MathUtils::Clamp(f, (Real) -1.0, (Real) 1.0);
			return MathUtils::ACos(f);
		}
		
        //--------------------------------------------------------------------------------
		/// @brief  Gets the shortest arc quaternion to rotate this vector to the
		///         destination vector
        ///    
        /// @remark If you call this with a dest vector that is close to the inverse
        ///         of this vector, we will rotate 180 degrees around the 'fallbackAxis'
		///         (if specified, or a generated axis if not) since in this case ANY axis
		///         of rotation is valid.
        //--------------------------------------------------------------------------------
        Quaternion getRotationTo(const Vector3& dest,
			                     const Vector3& fallbackAxis = Vector3::ZERO) const
        {
            // Based on Stan Melax's article in Game Programming Gems
            Quaternion q;
            // Copy, since cannot modify local
            Vector3 v0 = *this;
            Vector3 v1 = dest;
            v0.normalise();
            v1.normalise();

            Real d = v0.dotProduct(v1);
            // If dot == 1, vectors are the same
            if (d >= 1.0f)
            {
                return Quaternion::IDENTITY;
            }
			if (d < (1e-6f - 1.0f))
			{
				if (fallbackAxis != Vector3::ZERO)
				{
					// rotate 180 degrees about the fallback axis
					q.FromAngleAxis(Radian(MathUtils::PI), fallbackAxis);
				}
				else
				{
					// Generate an axis
					Vector3 axis = Vector3::UNIT_X.crossProduct(*this);
					if (axis.isZeroLength()) // pick another if colinear
						axis = Vector3::UNIT_Y.crossProduct(*this);
					axis.normalise();
					q.FromAngleAxis(Radian(MathUtils::PI), axis);
				}
			}
			else
			{
                Real s = MathUtils::Sqrt((1+d)*2);
	            Real invs = 1 / s;

				Vector3 c = v0.crossProduct(v1);

    	        q.x = c.x * invs;
        	    q.y = c.y * invs;
            	q.z = c.z * invs;
            	q.w = s * 0.5f;
				q.normalise();
			}
            return q;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Indicates if this vector is zero length
        //--------------------------------------------------------------------------------
        inline bool isZeroLength(void) const
        {
            Real sqlen = (x * x) + (y * y) + (z * z);
            return (sqlen < (1e-06 * 1e-06));

        }

        //--------------------------------------------------------------------------------
		/// @brief  As normalise, except that this vector is unaffected and the normalised
		///         vector is returned as a copy
        //--------------------------------------------------------------------------------
        inline Vector3 normalisedCopy(void) const
        {
            Vector3 ret = *this;
            ret.normalise();
            return ret;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Calculates a reflection vector to the plane with the given normal
		///
		/// @remark Assumes 'this' is pointing AWAY FROM the plane, invert if it is not.
        //--------------------------------------------------------------------------------
        inline Vector3 reflect(const Vector3& normal) const
        {
            return Vector3(*this - (2 * this->dotProduct(normal) * normal));
        }

        //--------------------------------------------------------------------------------
		/// @brief  Indicates whether this vector is within a positional tolerance of
		///         another vector
		///
		/// @param  rhs         The vector to compare with
		/// @param  tolerance   The amount that each element of the vector may vary by
		///                     and still be considered equal
        //--------------------------------------------------------------------------------
		inline bool positionEquals(const Vector3& rhs, Real tolerance = 1e-03) const
		{
			return MathUtils::RealEqual(x, rhs.x, tolerance) &&
				   MathUtils::RealEqual(y, rhs.y, tolerance) &&
				   MathUtils::RealEqual(z, rhs.z, tolerance);
		}

        //--------------------------------------------------------------------------------
		/// @brief  Indicates whether this vector is within a positional tolerance of
		///         another vector, by taking the scales of the vectors into account
		///
		/// @param  rhs         The vector to compare with
		/// @param  tolerance   The amount (related to the scale of vectors) that distance
        ///                     of the vector may vary by and still be considered close
        //--------------------------------------------------------------------------------
		inline bool positionCloses(const Vector3& rhs, Real tolerance = 1e-03f) const
		{
			return squaredDistance(rhs) <=
                (squaredLength() + rhs.squaredLength()) * tolerance;
		}

        //--------------------------------------------------------------------------------
		/// @brief  Indicates whether this vector is within a directional tolerance of
		///         another vector
		///
		/// @param  rhs         The vector to compare with
		/// @param  tolerance   The maximum angle by which the vectors may vary and still
		///                     be considered equal
        ///
		/// @note   Both vectors should be normalised.
        //--------------------------------------------------------------------------------
		inline bool directionEquals(const Vector3& rhs, const Radian& tolerance) const
		{
			Real dot = dotProduct(rhs);
			Radian angle = MathUtils::ACos(dot);

			return MathUtils::Abs(angle.valueRadians()) <= tolerance.valueRadians();
		}

        //--------------------------------------------------------------------------------
		/// @brief  Check whether this vector contains valid values
        //--------------------------------------------------------------------------------
		inline bool isNaN() const
		{
			return MathUtils::isNaN(x) || MathUtils::isNaN(y) || MathUtils::isNaN(z);
		}


        //_____ Comparison operators __________
    public:
        inline bool operator<(const Vector3& rhs) const
        {
            return (x < rhs.x && y < rhs.y && z < rhs.z);
        }

        inline bool operator>(const Vector3& rhs) const
        {
            return (x > rhs.x && y > rhs.y && z > rhs.z);
        }

        inline bool operator<=(const Vector3& rhs) const
        {
            return (x <= rhs.x && y <= rhs.y && z <= rhs.z);
        }

        inline bool operator>=(const Vector3& rhs) const
        {
            return (x >= rhs.x && y >= rhs.y && z >= rhs.z);
        }


        //_____ Constants __________
    public:
        static const Vector3 ZERO;
        static const Vector3 UNIT_X;
        static const Vector3 UNIT_Y;
        static const Vector3 UNIT_Z;
        static const Vector3 NEGATIVE_UNIT_X;
        static const Vector3 NEGATIVE_UNIT_Y;
        static const Vector3 NEGATIVE_UNIT_Z;
        static const Vector3 UNIT_SCALE;


        //_____ Attributes __________
    public:
        Real x, y, z;
    };
    
	/** @} */
	/** @} */
}
}

#endif

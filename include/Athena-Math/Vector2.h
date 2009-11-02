/** @file   Vector2.h
    @author Philip Abbet
    
    Declaration of the class Athena::Math::Vector2
    
    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#ifndef _ATHENA_MATH_VECTOR2_H_
#define _ATHENA_MATH_VECTOR2_H_

#include <Athena-Math/Prerequisites.h>
#include <Athena-Math/MathUtils.h>


namespace Athena {
namespace Math {

	/** \addtogroup Math
	*  @{
	*/
	
	//------------------------------------------------------------------------------------
	/// @brief  Standard 2-dimensional vector
	/// 
	/// A direction in 2D space represented as distances along the 2 orthogonal axes
	/// (x, y). Note that positions, directions and scaling factors can be represented by
	/// a vector, depending on how you interpret the values.
	//------------------------------------------------------------------------------------
	class ATHENA_MATH_SYMBOL Vector2
	{
        //_____ Construction / Destruction __________
	public:
        inline Vector2()
        {
        }

        inline Vector2(const Real fX, const Real fY)
        : x(fX), y(fY)
        {
        }

        inline explicit Vector2(const Real scaler)
        : x(scaler), y(scaler)
        {
        }

        inline explicit Vector2(const Real afCoordinate[2])
        : x(afCoordinate[0]), y(afCoordinate[1])
        {
        }

        inline explicit Vector2(const int afCoordinate[2])
        {
            x = (Real) afCoordinate[0];
            y = (Real) afCoordinate[1];
        }

        inline explicit Vector2(Real* const r)
        : x(r[0]), y(r[1])
        {
        }


        //_____ Value retrieval __________
    public:
		inline Real operator[](const size_t i) const
        {
            assert(i < 2);

            return *(&x+i);
        }

		inline Real& operator[](const size_t i)
        {
            assert(i < 2);

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


        //_____ Value assignement __________
    public:
        inline Vector2& operator=(const Vector2& rkVector)
        {
            x = rkVector.x;
            y = rkVector.y;

            return *this;
        }

		inline Vector2& operator=(const Real fScalar)
		{
			x = fScalar;
			y = fScalar;

			return *this;
		}

        //--------------------------------------------------------------------------------
		/// @brief  Exchange the contents of this vector with another
        //--------------------------------------------------------------------------------
		inline void swap(Vector2& other)
		{
			std::swap(x, other.x);
			std::swap(y, other.y);
		}


        //_____ Comparison operations __________
    public:
        inline bool operator==(const Vector2& rkVector) const
        {
            return (x == rkVector.x && y == rkVector.y);
        }

        inline bool operator!=(const Vector2& rkVector) const
        {
            return (x != rkVector.x || y != rkVector.y );
        }


        //_____ Arithmetic operations __________
    public:
        inline Vector2 operator+(const Vector2& rkVector) const
        {
            return Vector2(
                x + rkVector.x,
                y + rkVector.y);
        }

        inline Vector2 operator-(const Vector2& rkVector) const
        {
            return Vector2(
                x - rkVector.x,
                y - rkVector.y);
        }

        inline Vector2 operator*(const Real fScalar) const
        {
            return Vector2(
                x * fScalar,
                y * fScalar);
        }

        inline Vector2 operator*(const Vector2& rhs) const
        {
            return Vector2(
                x * rhs.x,
                y * rhs.y);
        }

        inline Vector2 operator/(const Real fScalar) const
        {
            assert(fScalar != 0.0);

            Real fInv = 1.0f / fScalar;

            return Vector2(
                x * fInv,
                y * fInv);
        }

        inline Vector2 operator/(const Vector2& rhs) const
        {
            return Vector2(
                x / rhs.x,
                y / rhs.y);
        }

        inline const Vector2& operator+() const
        {
            return *this;
        }

        inline Vector2 operator-() const
        {
            return Vector2(-x, -y);
        }

        inline friend Vector2 operator*(const Real fScalar, const Vector2& rkVector)
        {
            return Vector2(
                fScalar * rkVector.x,
                fScalar * rkVector.y);
        }

        inline friend Vector2 operator/(const Real fScalar, const Vector2& rkVector)
        {
            return Vector2(
                fScalar / rkVector.x,
                fScalar / rkVector.y);
        }

        inline friend Vector2 operator+(const Vector2& lhs, const Real rhs)
        {
            return Vector2(
                lhs.x + rhs,
                lhs.y + rhs);
        }

        inline friend Vector2 operator+(const Real lhs, const Vector2& rhs)
        {
            return Vector2(
                lhs + rhs.x,
                lhs + rhs.y);
        }

        inline friend Vector2 operator-(const Vector2& lhs, const Real rhs)
        {
            return Vector2(
                lhs.x - rhs,
                lhs.y - rhs);
        }

        inline friend Vector2 operator-(const Real lhs, const Vector2& rhs)
        {
            return Vector2(
                lhs - rhs.x,
                lhs - rhs.y);
        }
        

        //_____ Arithmetic updates __________
    public:
        inline Vector2& operator+=(const Vector2& rkVector)
        {
            x += rkVector.x;
            y += rkVector.y;

            return *this;
        }

        inline Vector2& operator+=(const Real fScaler)
        {
            x += fScaler;
            y += fScaler;

            return *this;
        }

        inline Vector2& operator-=(const Vector2& rkVector)
        {
            x -= rkVector.x;
            y -= rkVector.y;

            return *this;
        }

        inline Vector2& operator-=(const Real fScaler)
        {
            x -= fScaler;
            y -= fScaler;

            return *this;
        }

        inline Vector2& operator*=(const Real fScalar)
        {
            x *= fScalar;
            y *= fScalar;

            return *this;
        }

        inline Vector2& operator*=(const Vector2& rkVector)
        {
            x *= rkVector.x;
            y *= rkVector.y;

            return *this;
        }

        inline Vector2& operator/=(const Real fScalar)
        {
            assert(fScalar != 0.0);

            Real fInv = 1.0f / fScalar;

            x *= fInv;
            y *= fInv;

            return *this;
        }

        inline Vector2& operator/=(const Vector2& rkVector)
        {
            x /= rkVector.x;
            y /= rkVector.y;

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
            return MathUtils::Sqrt(x * x + y * y);
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
            return x * x + y * y;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Returns the distance to another vector
		///
		/// @warning    This operation requires a square root and is expensive in terms of
		///             CPU operations. If you don't need to know the exact distance (e.g.
		///             for just comparing distances) use squaredDistance() instead.
        //--------------------------------------------------------------------------------
        inline Real distance(const Vector2& rhs) const
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
        inline Real squaredDistance(const Vector2& rhs) const
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
        inline Real dotProduct(const Vector2& vec) const
        {
            return x * vec.x + y * vec.y;
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
            Real fLength = MathUtils::Sqrt(x * x + y * y);

            // Will also work for zero-sized vectors, but will change nothing
            if (fLength > 1e-08)
            {
                Real fInvLength = 1.0f / fLength;
                x *= fInvLength;
                y *= fInvLength;
            }

            return fLength;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Returns a vector at a point half way between this one and the passed
        ///         in vector
        //--------------------------------------------------------------------------------
        inline Vector2 midPoint(const Vector2& vec) const
        {
            return Vector2((x + vec.x) * 0.5f, (y + vec.y) * 0.5f);
        }

        //--------------------------------------------------------------------------------
		/// @brief  Sets this vector's components to the minimum of its own and the ones
		///         of the passed in vector
		///
        /// @remark 'Minimum' in this case means the combination of the lowest value of x,
        ///         y and z from both vectors. Lowest is taken just numerically, not
        ///         magnitude, so -1 < 0.
        //--------------------------------------------------------------------------------
        inline void makeFloor(const Vector2& cmp)
        {
            if (cmp.x < x) x = cmp.x;
            if (cmp.y < y) y = cmp.y;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Sets this vector's components to the maximum of its own and the ones
		///         of the passed in vector
		///
        /// @remark 'Maximum' in this case means the combination of the highest value of x,
        ///         y and z from both vectors. Highest is taken just numerically, not
        ///         magnitude, so 1 > -3.
        //--------------------------------------------------------------------------------
        inline void makeCeil(const Vector2& cmp)
        {
            if (cmp.x > x) x = cmp.x;
            if (cmp.y > y) y = cmp.y;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Generates a vector perpendicular to this vector (eg an 'up' vector)
		///
        /// @remark This method will return a vector which is perpendicular to this vector.
        ///         There are an infinite number of possibilities but this method will
        ///         guarantee to generate one of them. If you need more control you should
        ///         use the Quaternion class.
        //--------------------------------------------------------------------------------
        inline Vector2 perpendicular(void) const
        {
            return Vector2(-y, x);
        }

        //--------------------------------------------------------------------------------
		/// @brief  Calculates the 2 dimensional cross-product of 2 vectors, which results
		///         on a single floating point value which is 2 times the area of the
		///         triangle.
        //--------------------------------------------------------------------------------
        inline Real crossProduct(const Vector2& rkVector) const
        {
            return x * rkVector.y - y * rkVector.x;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Generates a new random vector which deviates from this vector by a
        ///         given angle in a random direction
		///
        /// @param  angle   The angle at which to deviate in radians
        /// @return         A random vector which deviates from this vector by angle. This
        ///                 vector will not be normalised, normalise it if you wish
        ///                 afterwards.
        ///    
        /// @remark This method assumes that the random number generator has already
        ///         been seeded appropriately.
        //--------------------------------------------------------------------------------
        inline Vector2 randomDeviant(Real angle) const
        {
            angle *= MathUtils::UnitRandom() * MathUtils::TWO_PI;
            Real cosa = cos(angle);
            Real sina = sin(angle);
            return Vector2(cosa * x - sina * y, sina * x + cosa * y);
        }

        //--------------------------------------------------------------------------------
		/// @brief  Indicates if this vector is zero length
        //--------------------------------------------------------------------------------
        inline bool isZeroLength(void) const
        {
            Real sqlen = (x * x) + (y * y);
            return (sqlen < (1e-06 * 1e-06));

        }

        //--------------------------------------------------------------------------------
		/// @brief  As normalise, except that this vector is unaffected and the normalised
		///         vector is returned as a copy
        //--------------------------------------------------------------------------------
        inline Vector2 normalisedCopy(void) const
        {
            Vector2 ret = *this;
            ret.normalise();
            return ret;
        }

        //--------------------------------------------------------------------------------
		/// @brief  Calculates a reflection vector to the plane with the given normal
		///
		/// @remark Assumes 'this' is pointing AWAY FROM the plane, invert if it is not.
        //--------------------------------------------------------------------------------
        inline Vector2 reflect(const Vector2& normal) const
        {
            return Vector2(*this - (2 * this->dotProduct(normal) * normal));
        }
        
        //--------------------------------------------------------------------------------
		/// @brief  Check whether this vector contains valid values
        //--------------------------------------------------------------------------------
		inline bool isNaN() const
		{
			return MathUtils::isNaN(x) || MathUtils::isNaN(y);
		}


        //_____ Comparison operators __________
    public:
        inline bool operator<(const Vector2& rhs) const
        {
            return (x < rhs.x && y < rhs.y);
        }

        inline bool operator>(const Vector2& rhs) const
        {
            return (x > rhs.x && y > rhs.y);
        }


        //_____ Constants __________
    public:
        static const Vector2 ZERO;
        static const Vector2 UNIT_X;
        static const Vector2 UNIT_Y;
        static const Vector2 NEGATIVE_UNIT_X;
        static const Vector2 NEGATIVE_UNIT_Y;
        static const Vector2 UNIT_SCALE;


        //_____ Attributes __________
    public:
        Real x, y;
    };
    
	/** @} */
	/** @} */
}
}

#endif

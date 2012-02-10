/** @file   AxisAlignedPlane.h
    @author Philip Abbet

    Declaration of the class Athena::Math::AxisAlignedPlane

    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#ifndef _ATHENA_MATH_AXISALIGNEDPLANE_H_
#define _ATHENA_MATH_AXISALIGNEDPLANE_H_

#include <Athena-Math/Prerequisites.h>
#include <Athena-Math/Vector3.h>
#include <Athena-Math/Intersection.h>
#include <Athena-Math/Matrix4.h>


namespace Athena {
namespace Math {

    /** \addtogroup Math
    *  @{
    */

    //------------------------------------------------------------------------------------
    /// @brief  A 3D box aligned with the x/y/z axes
    ///
    /// @remark This class represents a simple box which is aligned with the axes.
    ///         Internally it only stores 2 points as the extremeties of the box, one
    ///         which is the minima of all 3 axes, and the other which is the maxima of
    ///         all 3 axes. This class is typically used for an axis-aligned bounding box
    ///         (AABB) for collision and visibility determination.
    //------------------------------------------------------------------------------------
    class ATHENA_SYMBOL AxisAlignedBox
    {
        //_____ Internal types __________
    public:
        enum tExtent
        {
            EXTENT_NULL,
            EXTENT_FINITE,
            EXTENT_INFINITE
        };

        enum tCorner
        {
            FAR_LEFT_BOTTOM     = 0,
            FAR_LEFT_TOP        = 1,
            FAR_RIGHT_TOP       = 2,
            FAR_RIGHT_BOTTOM    = 3,
            NEAR_RIGHT_BOTTOM   = 7,
            NEAR_LEFT_BOTTOM    = 6,
            NEAR_LEFT_TOP       = 5,
            NEAR_RIGHT_TOP      = 4
        };


        //_____ Construction / Destruction __________
    public:
        inline AxisAlignedBox()
        : mMinimum(-0.5, -0.5, -0.5), mMaximum(0.5, 0.5, 0.5), mpCorners(0),
          mExtent(EXTENT_NULL)
        {
        }

        inline AxisAlignedBox(tExtent e)
        : mMinimum(-0.5, -0.5, -0.5), mMaximum(0.5, 0.5, 0.5), mpCorners(0),
          mExtent(e)
        {
        }

        inline AxisAlignedBox(const AxisAlignedBox& rkBox)
        : mMinimum(Vector3::ZERO), mMaximum(Vector3::UNIT_SCALE), mpCorners(0)
        {
            if (rkBox.isNull())
                setNull();
            else if (rkBox.isInfinite())
                setInfinite();
            else
                setExtents(rkBox.mMinimum, rkBox.mMaximum);
        }

        inline AxisAlignedBox(const Vector3& min, const Vector3& max)
        : mMinimum(Vector3::ZERO), mMaximum(Vector3::UNIT_SCALE), mpCorners(0)
        {
            setExtents(min, max);
        }

        inline AxisAlignedBox(Real mx, Real my, Real mz, Real Mx, Real My, Real Mz )
        : mMinimum(Vector3::ZERO), mMaximum(Vector3::UNIT_SCALE), mpCorners(0)
        {
            setExtents(mx, my, mz, Mx, My, Mz);
        }

        AxisAlignedBox& operator=(const AxisAlignedBox& rhs)
        {
            // Specifically overriden to avoid the copying of mpCorners
            if (rhs.isNull())
                setNull();
            else if (rhs.isInfinite())
                setInfinite();
            else
                setExtents(rhs.mMinimum, rhs.mMaximum);

            return *this;
        }

        ~AxisAlignedBox()
        {
            delete[] mpCorners;
        }


        //_____ Methods __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Gets the minimum corner of the box
        //--------------------------------------------------------------------------------
        inline const Vector3& getMinimum(void) const
        {
            return mMinimum;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Gets a modifiable version of the minimum corner of the box
        //--------------------------------------------------------------------------------
        inline Vector3& getMinimum(void)
        {
            return mMinimum;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Gets the maximum corner of the box
        //--------------------------------------------------------------------------------
        inline const Vector3& getMaximum(void) const
        {
            return mMaximum;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Gets a modifiable version of the maximum corner of the box
        //--------------------------------------------------------------------------------
        inline Vector3& getMaximum(void)
        {
            return mMaximum;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Sets the minimum corner of the box
        //--------------------------------------------------------------------------------
        inline void setMinimum(const Vector3& vec)
        {
            mExtent = EXTENT_FINITE;
            mMinimum = vec;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Sets the minimum corner of the box
        //--------------------------------------------------------------------------------
        inline void setMinimum(Real x, Real y, Real z)
        {
            mExtent = EXTENT_FINITE;
            mMinimum.x = x;
            mMinimum.y = y;
            mMinimum.z = z;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Changes one of the components of the minimum corner of the box used to
        ///         resize only one dimension of the box
        //--------------------------------------------------------------------------------
        inline void setMinimumX(Real x)
        {
            mMinimum.x = x;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Changes one of the components of the minimum corner of the box used to
        ///         resize only one dimension of the box
        //--------------------------------------------------------------------------------
        inline void setMinimumY(Real y)
        {
            mMinimum.y = y;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Changes one of the components of the minimum corner of the box used to
        ///         resize only one dimension of the box
        //--------------------------------------------------------------------------------
        inline void setMinimumZ(Real z)
        {
            mMinimum.z = z;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Sets the maximum corner of the box
        //--------------------------------------------------------------------------------
        inline void setMaximum(const Vector3& vec)
        {
            mExtent = EXTENT_FINITE;
            mMaximum = vec;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Sets the maximum corner of the box
        //--------------------------------------------------------------------------------
        inline void setMaximum(Real x, Real y, Real z)
        {
            mExtent = EXTENT_FINITE;
            mMaximum.x = x;
            mMaximum.y = y;
            mMaximum.z = z;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Changes one of the components of the maximum corner of the box used to
        ///         resize only one dimension of the box
        //--------------------------------------------------------------------------------
        inline void setMaximumX(Real x)
        {
            mMaximum.x = x;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Changes one of the components of the maximum corner of the box used to
        ///         resize only one dimension of the box
        //--------------------------------------------------------------------------------
        inline void setMaximumY(Real y)
        {
            mMaximum.y = y;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Changes one of the components of the maximum corner of the box used to
        ///         resize only one dimension of the box
        //--------------------------------------------------------------------------------
        inline void setMaximumZ(Real z)
        {
            mMaximum.z = z;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Sets both minimum and maximum extents at once
        //--------------------------------------------------------------------------------
        inline void setExtents(const Vector3& min, const Vector3& max)
        {
            assert((min.x <= max.x && min.y <= max.y && min.z <= max.z) &&
                "The minimum corner of the box must be less than or equal to maximum corner");

            mExtent = EXTENT_FINITE;
            mMinimum = min;
            mMaximum = max;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Sets both minimum and maximum extents at once
        //--------------------------------------------------------------------------------
        inline void setExtents(Real mx, Real my, Real mz, Real Mx, Real My, Real Mz)
        {
            assert((mx <= Mx && my <= My && mz <= Mz) &&
                "The minimum corner of the box must be less than or equal to maximum corner");

            mExtent = EXTENT_FINITE;

            mMinimum.x = mx;
            mMinimum.y = my;
            mMinimum.z = mz;

            mMaximum.x = Mx;
            mMaximum.y = My;
            mMaximum.z = Mz;

        }

        //--------------------------------------------------------------------------------
        /// @brief  Returns a pointer to an array of 8 corner points, useful for collision
        ///         vs. non-aligned objects
        ///
        /// @remark If the order of these corners is important, they are as follows: The 4
        ///         points of the minimum Z face (note that because we uses right-handed
        ///         coordinates, the minimum Z is at the 'back' of the box) starting with
        ///         the minimum point of all, then anticlockwise around this face (if you
        ///         are looking onto the face from outside the box). Then the 4 points of
        ///         the maximum Z face, starting with maximum point of all, then
        ///         anticlockwise around this face (looking onto the face from outside the
        ///         box). Like this:
        ///         <pre>
        ///         1-----2
        ///         /|    /|
        ///         / |   / |
        ///         5-----4  |
        ///         |  0--|--3
        ///         | /   | /
        ///         |/    |/
        ///         6-----7
        ///         </pre>
        ///
        /// @remark Make sure to use your own copy of the returned value, it can be
        ///         changed at any time!
        //--------------------------------------------------------------------------------
        inline const Vector3* getAllCorners(void) const
        {
            assert((mExtent == EXTENT_FINITE) && "Can't get corners of a null or infinite AAB");

            // The order of these items is, using right-handed co-ordinates:
            // Minimum Z face, starting with Min(all), then anticlockwise
            //   around face (looking onto the face)
            // Maximum Z face, starting with Max(all), then anticlockwise
            //   around face (looking onto the face)
            // Only for optimization/compatibility.
            if (!mpCorners)
                mpCorners = new Vector3[8];

            mpCorners[0] = mMinimum;
            mpCorners[1].x = mMinimum.x; mpCorners[1].y = mMaximum.y; mpCorners[1].z = mMinimum.z;
            mpCorners[2].x = mMaximum.x; mpCorners[2].y = mMaximum.y; mpCorners[2].z = mMinimum.z;
            mpCorners[3].x = mMaximum.x; mpCorners[3].y = mMinimum.y; mpCorners[3].z = mMinimum.z;

            mpCorners[4] = mMaximum;
            mpCorners[5].x = mMinimum.x; mpCorners[5].y = mMaximum.y; mpCorners[5].z = mMaximum.z;
            mpCorners[6].x = mMinimum.x; mpCorners[6].y = mMinimum.y; mpCorners[6].z = mMaximum.z;
            mpCorners[7].x = mMaximum.x; mpCorners[7].y = mMinimum.y; mpCorners[7].z = mMaximum.z;

            return mpCorners;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Gets the position of one of the corners
        //--------------------------------------------------------------------------------
        Vector3 getCorner(tCorner corner) const
        {
            switch(corner)
            {
            case FAR_LEFT_BOTTOM:
                return mMinimum;
            case FAR_LEFT_TOP:
                return Vector3(mMinimum.x, mMaximum.y, mMinimum.z);
            case FAR_RIGHT_TOP:
                return Vector3(mMaximum.x, mMaximum.y, mMinimum.z);
            case FAR_RIGHT_BOTTOM:
                return Vector3(mMaximum.x, mMinimum.y, mMinimum.z);
            case NEAR_RIGHT_BOTTOM:
                return Vector3(mMaximum.x, mMinimum.y, mMaximum.z);
            case NEAR_LEFT_BOTTOM:
                return Vector3(mMinimum.x, mMinimum.y, mMaximum.z);
            case NEAR_LEFT_TOP:
                return Vector3(mMinimum.x, mMaximum.y, mMaximum.z);
            case NEAR_RIGHT_TOP:
                return mMaximum;
            default:
                return Vector3();
            }
        }

        //--------------------------------------------------------------------------------
        /// @brief  Merges the passed in box into the current box. The result is the
        ///         box which encompasses both.
        //--------------------------------------------------------------------------------
        void merge(const AxisAlignedBox& rhs)
        {
            // Do nothing if rhs null, or this is infinite
            if ((rhs.mExtent == EXTENT_NULL) || (mExtent == EXTENT_INFINITE))
            {
                return;
            }
            // Otherwise if rhs is infinite, make this infinite, too
            else if (rhs.mExtent == EXTENT_INFINITE)
            {
                mExtent = EXTENT_INFINITE;
            }
            // Otherwise if current null, just take rhs
            else if (mExtent == EXTENT_NULL)
            {
                setExtents(rhs.mMinimum, rhs.mMaximum);
            }
            // Otherwise merge
            else
            {
                Vector3 min = mMinimum;
                Vector3 max = mMaximum;
                max.makeCeil(rhs.mMaximum);
                min.makeFloor(rhs.mMinimum);

                setExtents(min, max);
            }
        }

        //--------------------------------------------------------------------------------
        /// @brief  Extends the box to encompass the specified point (if needed)
        //--------------------------------------------------------------------------------
        inline void merge(const Vector3& point)
        {
            switch (mExtent)
            {
            case EXTENT_NULL: // if null, use this point
                setExtents(point, point);
                return;

            case EXTENT_FINITE:
                mMaximum.makeCeil(point);
                mMinimum.makeFloor(point);
                return;

            case EXTENT_INFINITE: // if infinite, makes no difference
                return;
            }

            assert(false && "Never reached");
        }

        //--------------------------------------------------------------------------------
        /// @brief  Transforms the box according to the matrix supplied
        ///
        /// @remark By calling this method you get the axis-aligned box which surrounds
        ///         the transformed version of this box. Therefore each corner of the box
        ///         is transformed by the matrix, then the extents are mapped back onto
        ///         the axes to produce another AABB. Useful when you have a local AABB
        ///         for an object which is then transformed.
        //--------------------------------------------------------------------------------
        inline void transform(const Matrix4& matrix)
        {
            // Do nothing if current null or infinite
            if (mExtent != EXTENT_FINITE)
                return;

            Vector3 oldMin, oldMax, currentCorner;

            // Getting the old values so that we can use the existing merge method.
            oldMin = mMinimum;
            oldMax = mMaximum;

            // Reset
            setNull();

            // We sequentially compute the corners in the following order :
            // 0, 6, 5, 1, 2, 4 ,7 , 3
            // This sequence allows us to only change one member at a time to get at all corners.

            // For each one, we transform it using the matrix
            // Which gives the resulting point and merge the resulting point.

            // First corner
            // min min min
            currentCorner = oldMin;
            merge(matrix * currentCorner);

            // min,min,max
            currentCorner.z = oldMax.z;
            merge(matrix * currentCorner);

            // min max max
            currentCorner.y = oldMax.y;
            merge(matrix * currentCorner);

            // min max min
            currentCorner.z = oldMin.z;
            merge(matrix * currentCorner);

            // max max min
            currentCorner.x = oldMax.x;
            merge(matrix * currentCorner);

            // max max max
            currentCorner.z = oldMax.z;
            merge(matrix * currentCorner);

            // max min max
            currentCorner.y = oldMin.y;
            merge(matrix * currentCorner);

            // max min min
            currentCorner.z = oldMin.z;
            merge(matrix * currentCorner);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Transforms the box according to the affine matrix supplied
        ///
        /// @remark By calling this method you get the axis-aligned box which surrounds
        ///         the transformed version of this box. Therefore each corner of the box
        ///         is transformed by the matrix, then the extents are mapped back onto
        ///         the axes to produce another AABB. Useful when you have a local AABB
        ///         for an object which is then transformed.
        ///
        /// @note   The matrix must be an affine matrix. @see Matrix4::isAffine.
        //--------------------------------------------------------------------------------
        void transformAffine(const Matrix4& m)
        {
            assert(m.isAffine());

            // Do nothing if current null or infinite
            if ( mExtent != EXTENT_FINITE )
                return;

            Vector3 centre = getCenter();
            Vector3 halfSize = getHalfSize();

            Vector3 newCentre = m.transformAffine(centre);
            Vector3 newHalfSize(
                MathUtils::Abs(m[0][0]) * halfSize.x + MathUtils::Abs(m[0][1]) * halfSize.y + MathUtils::Abs(m[0][2]) * halfSize.z,
                MathUtils::Abs(m[1][0]) * halfSize.x + MathUtils::Abs(m[1][1]) * halfSize.y + MathUtils::Abs(m[1][2]) * halfSize.z,
                MathUtils::Abs(m[2][0]) * halfSize.x + MathUtils::Abs(m[2][1]) * halfSize.y + MathUtils::Abs(m[2][2]) * halfSize.z);

            setExtents(newCentre - newHalfSize, newCentre + newHalfSize);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Sets the box to a 'null' value i.e. not a box
        //--------------------------------------------------------------------------------
        inline void setNull()
        {
            mExtent = EXTENT_NULL;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Indicates if the box is null i.e. empty
        //--------------------------------------------------------------------------------
        inline bool isNull(void) const
        {
            return (mExtent == EXTENT_NULL);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Indicates if the box is finite
        //--------------------------------------------------------------------------------
        bool isFinite(void) const
        {
            return (mExtent == EXTENT_FINITE);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Sets the box to 'infinite'
        //--------------------------------------------------------------------------------
        inline void setInfinite()
        {
            mExtent = EXTENT_INFINITE;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Indicates if the box is infinite
        //--------------------------------------------------------------------------------
        bool isInfinite(void) const
        {
            return (mExtent == EXTENT_INFINITE);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Indicates if this box intersects another one
        //--------------------------------------------------------------------------------
        inline bool intersects(const AxisAlignedBox& b2) const
        {
            // Early-fail for nulls
            if (this->isNull() || b2.isNull())
                return false;

            // Early-success for infinites
            if (this->isInfinite() || b2.isInfinite())
                return true;

            // Use up to 6 separating planes
            if (mMaximum.x < b2.mMinimum.x)
                return false;
            if (mMaximum.y < b2.mMinimum.y)
                return false;
            if (mMaximum.z < b2.mMinimum.z)
                return false;

            if (mMinimum.x > b2.mMaximum.x)
                return false;
            if (mMinimum.y > b2.mMaximum.y)
                return false;
            if (mMinimum.z > b2.mMaximum.z)
                return false;

            // otherwise, must be intersecting
            return true;

        }

        //--------------------------------------------------------------------------------
        /// @brief  Compute the area of intersection of this box and another one
        //--------------------------------------------------------------------------------
        inline AxisAlignedBox intersection(const AxisAlignedBox& b2) const
        {
            if (this->isNull() || b2.isNull())
            {
                return AxisAlignedBox();
            }
            else if (this->isInfinite())
            {
                return b2;
            }
            else if (b2.isInfinite())
            {
                return *this;
            }

            Vector3 intMin = mMinimum;
            Vector3 intMax = mMaximum;

            intMin.makeCeil(b2.getMinimum());
            intMax.makeFloor(b2.getMaximum());

            // Check intersection isn't null
            if (intMin.x < intMax.x &&
                intMin.y < intMax.y &&
                intMin.z < intMax.z)
            {
                return AxisAlignedBox(intMin, intMax);
            }

            return AxisAlignedBox();
        }

        //--------------------------------------------------------------------------------
        /// @brief  Compute the volume of this box
        //--------------------------------------------------------------------------------
        inline Real volume(void) const
        {
            switch (mExtent)
            {
            case EXTENT_NULL:
                return 0.0f;

            case EXTENT_FINITE:
                {
                    Vector3 diff = mMaximum - mMinimum;
                    return diff.x * diff.y * diff.z;
                }

            case EXTENT_INFINITE:
                return MathUtils::POS_INFINITY;

            default: // shut up compiler
                assert( false && "Never reached" );
                return 0.0f;
            }
        }

        //--------------------------------------------------------------------------------
        /// @brief  Scales the box
        //--------------------------------------------------------------------------------
        inline void scale(const Vector3& s)
        {
            // Do nothing if current null or infinite
            if (mExtent != EXTENT_FINITE)
                return;

            // NB assumes centered on origin
            Vector3 min = mMinimum * s;
            Vector3 max = mMaximum * s;
            setExtents(min, max);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Tests whether this box intersects a sphere
        //--------------------------------------------------------------------------------
        inline bool intersects(const Sphere& sphere) const
        {
            return Intersection::intersects(*this, sphere);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Tests whether this box intersects a plane
        //--------------------------------------------------------------------------------
        inline bool intersects(const Plane& plane) const
        {
            return Intersection::intersects(*this, plane);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Tests whether a point is within this box
        //--------------------------------------------------------------------------------
        inline bool intersects(const Vector3& point) const
        {
            return Intersection::intersects(*this, point);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Gets the centre of the box
        //--------------------------------------------------------------------------------
        Vector3 getCenter(void) const
        {
            assert((mExtent == EXTENT_FINITE) && "Can't get center of a null or infinite AAB");

            return Vector3(
                (mMaximum.x + mMinimum.x) * 0.5f,
                (mMaximum.y + mMinimum.y) * 0.5f,
                (mMaximum.z + mMinimum.z) * 0.5f);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Gets the size of the box
        //--------------------------------------------------------------------------------
        Vector3 getSize(void) const
        {
            switch (mExtent)
            {
            case EXTENT_NULL:
                return Vector3::ZERO;

            case EXTENT_FINITE:
                return mMaximum - mMinimum;

            case EXTENT_INFINITE:
                return Vector3(
                    MathUtils::POS_INFINITY,
                    MathUtils::POS_INFINITY,
                    MathUtils::POS_INFINITY);

            default: // shut up compiler
                assert(false && "Never reached");
                return Vector3::ZERO;
            }
        }

        //--------------------------------------------------------------------------------
        /// @brief  Gets the half-size of the box
        //--------------------------------------------------------------------------------
        Vector3 getHalfSize(void) const
        {
            switch (mExtent)
            {
            case EXTENT_NULL:
                return Vector3::ZERO;

            case EXTENT_FINITE:
                return (mMaximum - mMinimum) * 0.5;

            case EXTENT_INFINITE:
                return Vector3(
                    MathUtils::POS_INFINITY,
                    MathUtils::POS_INFINITY,
                    MathUtils::POS_INFINITY);

            default: // shut up compiler
                assert(false && "Never reached");
                return Vector3::ZERO;
            }
        }

        //--------------------------------------------------------------------------------
        /// @brief  Tests whether a point is within this box
        //--------------------------------------------------------------------------------
        bool contains(const Vector3& v) const
        {
            if (isNull())
                return false;
            if (isInfinite())
                return true;

            return mMinimum.x <= v.x && v.x <= mMaximum.x &&
                   mMinimum.y <= v.y && v.y <= mMaximum.y &&
                   mMinimum.z <= v.z && v.z <= mMaximum.z;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Tests whether a box is contained by this box
        //--------------------------------------------------------------------------------
        bool contains(const AxisAlignedBox& other) const
        {
            if (other.isNull() || this->isInfinite())
                return true;

            if (this->isNull() || other.isInfinite())
                return false;

            return this->mMinimum.x <= other.mMinimum.x &&
                   this->mMinimum.y <= other.mMinimum.y &&
                   this->mMinimum.z <= other.mMinimum.z &&
                   other.mMaximum.x <= this->mMaximum.x &&
                   other.mMaximum.y <= this->mMaximum.y &&
                   other.mMaximum.z <= this->mMaximum.z;
        }


        //_____ Comparison operators __________
    public:
        bool operator==(const AxisAlignedBox& rhs) const
        {
            if (this->mExtent != rhs.mExtent)
                return false;

            if (!this->isFinite())
                return true;

            return this->mMinimum == rhs.mMinimum &&
                   this->mMaximum == rhs.mMaximum;
        }

        bool operator!=(const AxisAlignedBox& rhs) const
        {
            return !(*this == rhs);
        }


        //_____ Constants __________
    private:
        static const AxisAlignedBox BOX_NULL;
        static const AxisAlignedBox BOX_INFINITE;


        //_____ Attributes __________
    private:
        Vector3             mMinimum;
        Vector3             mMaximum;
        tExtent             mExtent;
        mutable Vector3*    mpCorners;
    };

    /** @} */
    /** @} */
}
}

#endif

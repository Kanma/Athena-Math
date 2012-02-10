/** @file   MathUtils.h
    @author Philip Abbet

    Declaration of the classes Athena::Math::Radian, Athena::Math::Degree and
    Athena::Math::MathUtils.

    @note   This is based on the corresponding classes from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#ifndef _ATHENA_MATH_MATH_H_
#define _ATHENA_MATH_MATH_H_

#include <Athena-Math/Prerequisites.h>


namespace Athena {
namespace Math {

    /** \addtogroup Math
    *  @{
    */

    //------------------------------------------------------------------------------------
    /// @brief  Represents an angle in radians
    ///
    /// @remark Radian values are interchangeable with Degree values, and conversions
    ///         will be done automatically between them
    //------------------------------------------------------------------------------------
    class ATHENA_SYMBOL Radian
    {
        //_____ Construction / Destruction __________
    public:
        explicit Radian(Real r=0.0f) : m_radians(r) {}
        Radian(const Degree& d);


        //_____ Value assignation & retrieval __________
    public:
        Radian& operator=(const Real& f) { m_radians = f; return *this; }
        Radian& operator=(const Radian& r) { m_radians = r.m_radians; return *this; }
        Radian& operator=(const Degree& d);

        Real valueDegrees() const;
        Real valueRadians() const { return m_radians; }


        //_____ Mathematical operations __________
    public:
        const Radian& operator+() const { return *this; }
        Radian operator+(const Radian& r) const { return Radian(m_radians + r.m_radians); }
        Radian operator+(const Degree& d) const;
        Radian& operator+=(const Radian& r) { m_radians += r.m_radians; return *this; }
        Radian& operator+=(const Degree& d);
        Radian operator-() const { return Radian(-m_radians); }
        Radian operator-(const Radian& r) const { return Radian(m_radians - r.m_radians); }
        Radian operator-(const Degree& d) const;
        Radian& operator-=(const Radian& r) { m_radians -= r.m_radians; return *this; }
        Radian& operator-=(const Degree& d);
        Radian operator*(Real f ) const { return Radian(m_radians * f); }
        Radian operator*(const Radian& f) const { return Radian(m_radians * f.m_radians); }
        Radian& operator*=(Real f) { m_radians *= f; return *this; }
        Radian operator/(Real f) const { return Radian(m_radians / f); }
        Radian& operator/=(Real f) { m_radians /= f; return *this; }


        //_____ Comparison operations __________
    public:
        bool operator<(const Radian& r) const { return m_radians < r.m_radians; }
        bool operator<=(const Radian& r) const { return m_radians <= r.m_radians; }
        bool operator==(const Radian& r) const { return m_radians == r.m_radians; }
        bool operator!=(const Radian& r) const { return m_radians != r.m_radians; }
        bool operator>=(const Radian& r) const { return m_radians >= r.m_radians; }
        bool operator>(const Radian& r) const { return m_radians > r.m_radians; }


        //_____ Attributes __________
    private:
        Real m_radians;
    };


    //------------------------------------------------------------------------------------
    /// @brief  Represents an angle in degrees
    ///
    /// @remark Degree values are interchangeable with Radian values, and conversions
    ///         will be done automatically between them
    //------------------------------------------------------------------------------------
    class ATHENA_SYMBOL Degree
    {
        //_____ Construction / Destruction __________
    public:
        explicit Degree(Real d=0.0f) : m_degrees(d) {}
        Degree(const Radian& r) : m_degrees(r.valueDegrees()) {}


        //_____ Value assignation & retrieval __________
    public:
        Degree& operator=(const Real& f) { m_degrees = f; return *this; }
        Degree& operator=(const Degree& d) { m_degrees = d.m_degrees; return *this; }
        Degree& operator=(const Radian& r) { m_degrees = r.valueDegrees(); return *this; }

        Real valueDegrees() const { return m_degrees; }
        Real valueRadians() const;


        //_____ Mathematical operations __________
    public:
        const Degree& operator+() const { return *this; }
        Degree operator+(const Degree& d) const { return Degree(m_degrees + d.m_degrees); }
        Degree operator+(const Radian& r) const { return Degree(m_degrees + r.valueDegrees()); }
        Degree& operator+=(const Degree& d) { m_degrees += d.m_degrees; return *this; }
        Degree& operator+=(const Radian& r) { m_degrees += r.valueDegrees(); return *this; }
        Degree operator-() const { return Degree(-m_degrees); }
        Degree operator-(const Degree& d) const { return Degree(m_degrees - d.m_degrees); }
        Degree operator-(const Radian& r) const { return Degree(m_degrees - r.valueDegrees()); }
        Degree& operator-=(const Degree& d) { m_degrees -= d.m_degrees; return *this; }
        Degree& operator-=(const Radian& r) { m_degrees -= r.valueDegrees(); return *this; }
        Degree operator*(Real f) const { return Degree(m_degrees * f); }
        Degree operator*(const Degree& f) const { return Degree(m_degrees * f.m_degrees); }
        Degree& operator*=(Real f) { m_degrees *= f; return *this; }
        Degree operator/(Real f) const { return Degree(m_degrees / f); }
        Degree& operator/=(Real f) { m_degrees /= f; return *this; }

        bool operator<(const Degree& d) const { return m_degrees <  d.m_degrees; }
        bool operator<=(const Degree& d) const { return m_degrees <= d.m_degrees; }
        bool operator==(const Degree& d) const { return m_degrees == d.m_degrees; }
        bool operator!=(const Degree& d) const { return m_degrees != d.m_degrees; }
        bool operator>=(const Degree& d) const { return m_degrees >= d.m_degrees; }
        bool operator>(const Degree& d) const { return m_degrees >  d.m_degrees; }


        //_____ Attributes __________
    private:
        Real m_degrees;
    };


    //------------------------------------------------------------------------------------
    // The following functions could not be defined within the class definition of class
    // Radian because they required class Degree to be defined
    //------------------------------------------------------------------------------------
    inline Radian::Radian(const Degree& d) : m_radians(d.valueRadians()) {}

    inline Radian& Radian::operator=(const Degree& d)
    {
        m_radians = d.valueRadians();
        return *this;
    }

    inline Radian Radian::operator+(const Degree& d) const
    {
        return Radian(m_radians + d.valueRadians());
    }

    inline Radian& Radian::operator+=(const Degree& d)
    {
        m_radians += d.valueRadians();
        return *this;
    }

    inline Radian Radian::operator-(const Degree& d) const
    {
        return Radian(m_radians - d.valueRadians());
    }

    inline Radian& Radian::operator-=(const Degree& d)
    {
        m_radians -= d.valueRadians();
        return *this;
    }


    //------------------------------------------------------------------------------------
    /// @brief  Class to provide access to common mathematical functions
    //------------------------------------------------------------------------------------
    class ATHENA_SYMBOL MathUtils
    {
        //_____ Constants __________
    public:
         static const Real LOG2;                 ///< log(2)
        static const Real POS_INFINITY;         ///< +∞
        static const Real NEG_INFINITY;         ///< -∞
        static const Real PI;                   ///< π
        static const Real TWO_PI;               ///< 2π
        static const Real HALF_PI;              ///< π/2
        static const Real DEGREES_TO_RADIANS;   ///< ° -> rad conversion factor
        static const Real RADIANS_TO_DEGREES;   ///< rad -> ° conversion factor


        //_____ Integer operations __________
    public:
        static inline int IAbs(int iValue) { return ( iValue >= 0 ? iValue : -iValue ); }
        static inline int ICeil(float fValue) { return int(ceil(fValue)); }
        static inline int IFloor(float fValue) { return int(floor(fValue)); }
        static int ISign(int iValue);


        //_____ Floating-point operations __________
    public:
        static inline Real Abs(Real fValue) { return Real(fabs(fValue)); }
        static inline Degree Abs(const Degree& dValue) { return Degree(fabs(dValue.valueDegrees())); }
        static inline Radian Abs(const Radian& rValue) { return Radian(fabs(rValue.valueRadians())); }

        static inline Real Ceil (Real fValue) { return Real(ceil(fValue)); }
        static inline Real Floor(Real fValue) { return Real(floor(fValue)); }

        static Real Sign(Real fValue);
        static inline Radian Sign(const Radian& rValue) { return Radian(Sign(rValue.valueRadians())); }
        static inline Degree Sign(const Degree& dValue) { return Degree(Sign(dValue.valueDegrees())); }

        static inline Real Exp(Real fValue) { return Real(exp(fValue)); }
        static inline Real Log(Real fValue) { return Real(log(fValue)); }
        static inline Real Log2(Real fValue) { return Real(log(fValue)/LOG2); }
        static inline Real LogN(Real base, Real fValue) { return Real(log(fValue)/log(base)); }
        static inline Real Pow(Real fBase, Real fExponent) { return Real(pow(fBase,fExponent)); }

        static inline Real Sqr(Real fValue) { return fValue * fValue; }
        static inline Real Sqrt(Real fValue) { return Real(sqrt(fValue)); }
        static inline Radian Sqrt(const Radian& fValue) { return Radian(sqrt(fValue.valueRadians())); }
        static inline Degree Sqrt(const Degree& fValue) { return Degree(sqrt(fValue.valueDegrees())); }
        static Real InvSqrt(Real fValue);

        static bool RealEqual(Real a, Real b, Real tolerance = std::numeric_limits<Real>::epsilon());

        static inline bool isNaN(Real f)
        {
            // std::isnan() is C99, not supported by all compilers
            // However NaN always fails this next test, no other number does.
            return f != f;
        }

        /// Clamp a value within an inclusive range
        template <typename T>
        static T Clamp(T val, T minval, T maxval)
        {
            assert(minval < maxval && "Invalid clamp range");
            return std::max(std::min(val, maxval), minval);
        }


        //_____ Trigonometric operations __________
    public:
        static Radian ACos(Real fValue);
        static Radian ASin(Real fValue);
        static inline Radian ATan(Real fValue) { return Radian(atan(fValue)); }
        static inline Radian ATan2(Real fY, Real fX) { return Radian(atan2(fY, fX)); }

        static inline Real Cos(const Radian& fValue) { return Real(cos(fValue.valueRadians())); }
        static inline Real Cos(Real fValue) { return Real(cos(fValue)); }

        static inline Real Sin(const Radian& fValue) { return Real(sin(fValue.valueRadians())); }
        static inline Real Sin(Real fValue) { return Real(sin(fValue)); }

        static inline Real Tan(const Radian& fValue) { return Real(tan(fValue.valueRadians())); }
        static inline Real Tan(Real fValue) { return Real(tan(fValue)); }


        //_____ Random numbers generation __________
    public:
        static Real UnitRandom();  // in [0,1]
        static Real RangeRandom(Real fLow, Real fHigh);  // in [fLow,fHigh]
        static Real SymmetricRandom();  // in [-1,1]


        //_____ Unit conversion __________
    public:
        static inline Real DegreesToRadians(Real degrees) { return degrees * DEGREES_TO_RADIANS; }
        static inline Real RadiansToDegrees(Real radians) { return radians * RADIANS_TO_DEGREES; }


        //_____ Signal generation __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Generates a value based on the Gaussian (normal) distribution function
        ///         with the given offset and scale parameters
        //--------------------------------------------------------------------------------
        static Real gaussianDistribution(Real x, Real offset = 0.0f, Real scale = 1.0f);
    };


    //------------------------------------------------------------------------------------
    // The following functions must be defined down here, because they rely on the angle
    // unit conversion functions in class MathUtils
    //------------------------------------------------------------------------------------
    inline Real Radian::valueDegrees() const
    {
        return MathUtils::RadiansToDegrees(m_radians);
    }

    inline Real Degree::valueRadians() const
    {
        return MathUtils::DegreesToRadians(m_degrees);
    }

    inline Radian operator*(Real a, const Radian& b)
    {
        return Radian(a * b.valueRadians());
    }

    inline Radian operator/(Real a, const Radian& b)
    {
        return Radian(a / b.valueRadians());
    }

    inline Degree operator*(Real a, const Degree& b)
    {
        return Degree(a * b.valueDegrees());
    }

    inline Degree operator/(Real a, const Degree& b)
    {
        return Degree(a / b.valueDegrees());
    }

    /** @} */
    /** @} */
}
}

#endif

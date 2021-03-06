/** @file   Color.h
    @author Philip Abbet

    Declaration of the class Athena::Math::Color

    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#ifndef _ATHENA_MATH_COLOR_H_
#define _ATHENA_MATH_COLOR_H_

#include <Athena-Math/Prerequisites.h>


namespace Athena {
namespace Math {

    /** \addtogroup Math
    *  @{
    */

    typedef uint32 RGBA;
    typedef uint32 ARGB;
    typedef uint32 ABGR;
    typedef uint32 BGRA;


    //------------------------------------------------------------------------------------
    /// @brief  Represents a color in RGB-space
    ///
    /// Color is represented as 4 components, each of which is a floating-point value from
    /// 0.0 to 1.0.
    ///
    /// The 3 'normal' colour components are red, green and blue, a higher number
    /// indicating greater amounts of that component in the colour. The forth component
    /// is the 'alpha' value, which represents transparency. In this case, 0.0 is
    /// completely transparent and 1.0 is fully opaque.
    //------------------------------------------------------------------------------------
    class ATHENA_MATH_SYMBOL Color
    {
        //_____ Construction / Destruction __________
    public:
        explicit Color(float red = 1.0f, float green = 1.0f, float blue = 1.0f,
                       float alpha = 1.0f)
        : r(red), g(green), b(blue), a(alpha)
        {
        }


        //_____ Value retrieval __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Retrieves colour as RGBA
        //--------------------------------------------------------------------------------
        RGBA getAsRGBA(void) const;

        //--------------------------------------------------------------------------------
        /// @brief  Retrieves colour as ARGB
        //--------------------------------------------------------------------------------
        ARGB getAsARGB(void) const;

        //--------------------------------------------------------------------------------
        /// @brief  Retrieves colour as BGRA
        //--------------------------------------------------------------------------------
        BGRA getAsBGRA(void) const;

        //--------------------------------------------------------------------------------
        /// @brief  Retrieves colour as ABGR
        //--------------------------------------------------------------------------------
        ABGR getAsABGR(void) const;

        //--------------------------------------------------------------------------------
        /// @brief  Array accessor operator
        //--------------------------------------------------------------------------------
        inline float operator[](const size_t i) const
        {
            assert(i < 4);
            return *(&r+i);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Array accessor operator
        //--------------------------------------------------------------------------------
        inline float& operator[](const size_t i)
        {
            assert(i < 4);
            return *(&r+i);
        }

        //--------------------------------------------------------------------------------
        /// @brief  Pointer accessor for direct copying
        //--------------------------------------------------------------------------------
        inline float* ptr()
        {
            return &r;
        }

        //--------------------------------------------------------------------------------
        /// @brief  Pointer accessor for direct copying
        //--------------------------------------------------------------------------------
        inline const float* ptr() const
        {
            return &r;
        }


        //_____ Value assignation __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Sets colour as RGBA
        //--------------------------------------------------------------------------------
        void setAsRGBA(const RGBA val);

        //--------------------------------------------------------------------------------
        /// @brief  Sets colour as ARGB
        //--------------------------------------------------------------------------------
        void setAsARGB(const ARGB val);

        //--------------------------------------------------------------------------------
        /// @brief  Sets colour as BGRA
        //--------------------------------------------------------------------------------
        void setAsBGRA(const BGRA val);

        //--------------------------------------------------------------------------------
        /// @brief  Sets colour as ABGR
        //--------------------------------------------------------------------------------
        void setAsABGR(const ABGR val);


        //_____ Methods __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Clamps color value to the range [0, 1]
        //--------------------------------------------------------------------------------
        inline void saturate(void)
        {
            if (r < 0)
                r = 0;
            else if (r > 1)
                r = 1;

            if (g < 0)
                g = 0;
            else if (g > 1)
                g = 1;

            if (b < 0)
                b = 0;
            else if (b > 1)
                b = 1;

            if (a < 0)
                a = 0;
            else if (a > 1)
                a = 1;
        }

        //--------------------------------------------------------------------------------
        /// @brief  As saturate, except that this colour value is unaffected and the
        ///         saturated color value is returned as a copy
        //--------------------------------------------------------------------------------
        inline Color saturateCopy(void) const
        {
            Color ret = *this;
            ret.saturate();
            return ret;
        }


        //_____ Arithmetic operations __________
    public:
        inline Color operator+(const Color& rkVector) const
        {
            Color kSum;

            kSum.r = r + rkVector.r;
            kSum.g = g + rkVector.g;
            kSum.b = b + rkVector.b;
            kSum.a = a + rkVector.a;

            return kSum;
        }

        inline Color operator-(const Color& rkVector) const
        {
            Color kDiff;

            kDiff.r = r - rkVector.r;
            kDiff.g = g - rkVector.g;
            kDiff.b = b - rkVector.b;
            kDiff.a = a - rkVector.a;

            return kDiff;
        }

        inline Color operator*(const float fScalar) const
        {
            Color kProd;

            kProd.r = fScalar*r;
            kProd.g = fScalar*g;
            kProd.b = fScalar*b;
            kProd.a = fScalar*a;

            return kProd;
        }

        inline Color operator*(const Color& rhs) const
        {
            Color kProd;

            kProd.r = rhs.r * r;
            kProd.g = rhs.g * g;
            kProd.b = rhs.b * b;
            kProd.a = rhs.a * a;

            return kProd;
        }

        inline Color operator/(const Color& rhs) const
        {
            Color kProd;

            kProd.r = rhs.r / r;
            kProd.g = rhs.g / g;
            kProd.b = rhs.b / b;
            kProd.a = rhs.a / a;

            return kProd;
        }

        inline Color operator/(const float fScalar) const
        {
            assert(fScalar != 0.0);

            Color kDiv;

            float fInv = 1.0f / fScalar;
            kDiv.r = r * fInv;
            kDiv.g = g * fInv;
            kDiv.b = b * fInv;
            kDiv.a = a * fInv;

            return kDiv;
        }

        inline friend Color operator*(const float fScalar, const Color& rkVector)
        {
            Color kProd;

            kProd.r = fScalar * rkVector.r;
            kProd.g = fScalar * rkVector.g;
            kProd.b = fScalar * rkVector.b;
            kProd.a = fScalar * rkVector.a;

            return kProd;
        }


        //_____ Arithmetic updates __________
    public:
        inline Color& operator+=(const Color& rkVector)
        {
            r += rkVector.r;
            g += rkVector.g;
            b += rkVector.b;
            a += rkVector.a;

            return *this;
        }

        inline Color& operator-=(const Color& rkVector)
        {
            r -= rkVector.r;
            g -= rkVector.g;
            b -= rkVector.b;
            a -= rkVector.a;

            return *this;
        }

        inline Color& operator*=(const float fScalar)
        {
            r *= fScalar;
            g *= fScalar;
            b *= fScalar;
            a *= fScalar;
            return *this;
        }

        inline Color& operator/=(const float fScalar)
        {
            assert(fScalar != 0.0);

            float fInv = 1.0f / fScalar;

            r *= fInv;
            g *= fInv;
            b *= fInv;
            a *= fInv;

            return *this;
        }


        //_____ Comparison operators __________
    public:
        inline bool operator==(const Color& rhs) const
        {
            return (r == rhs.r && g == rhs.g && b == rhs.b && a == rhs.a);
        }

        inline bool operator!=(const Color& rhs) const
        {
            return !(*this == rhs);
        }


        //_____ Color-space conversion __________
    public:
        //--------------------------------------------------------------------------------
        /// @brief  Set a colour value from Hue, Saturation and Brightness
        ///
        /// @param  hue         Hue value, scaled to the [0,1] range as opposed to the
        ///                     0-360 one
        /// @param  saturation  Saturation level, [0,1]
        /// @param  brightness  Brightness level, [0,1]
        //--------------------------------------------------------------------------------
        void setHSB(Real hue, Real saturation, Real brightness);

        //--------------------------------------------------------------------------------
        /// @brief  Convert the current colour to Hue, Saturation and Brightness values
        ///
        /// @param[out]  hue        Hue value, scaled to the [0,1] range as opposed to
        ///                         the 0-360 one
        /// @param[out]  saturation Saturation level, [0,1]
        /// @param[out]  brightness Brightness level, [0,1]
        //--------------------------------------------------------------------------------
        void getHSB(Real* hue, Real* saturation, Real* brightness) const;


        //_____ Constants __________
    public:
        static const Color ZERO;
        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Green;
        static const Color Blue;


        //_____ Attributes __________
    public:
        float r, g, b, a;
    };

    /** @} */
    /** @} */
}
}

#endif

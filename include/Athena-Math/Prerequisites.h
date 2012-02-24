/** @file   Prerequisites.h
    @author Philip Abbet

    Declaration of the types of the Athena-Math module
*/

#ifndef _ATHENA_MATH_PREREQUISITES_H_
#define _ATHENA_MATH_PREREQUISITES_H_

#include <Athena-Math/Declarations.h>
#include <limits>
#include <algorithm>
#include <cmath>
#include <assert.h>


/// Used to export symbols from the library
#if ATHENA_PLATFORM == ATHENA_PLATFORM_WIN32
#    ifdef ATHENA_MATH_EXPORTS
#        define ATHENA_MATH_SYMBOL  __declspec(dllexport)
#    else
#        define ATHENA_MATH_SYMBOL  __declspec(dllimport)
#    endif
#else
#    define ATHENA_MATH_SYMBOL
#endif


namespace Athena {
namespace Math {

    #if ATHENA_DOUBLE_PRECISION == 1
        /// Software floating point type.
        typedef double Real;
    #else
        /// Software floating point type.
        typedef float Real;
    #endif


    // Forward declaration of classes
    class AxisAlignedBox;
    class Color;
    class Degree;
    class Intersection;
    class Matrix3;
    class Matrix4;
    class Plane;
    class Quaternion;
    class Radian;
    class RandomNumberGenerator;
    class Sphere;
    class Vector2;
    class Vector3;
    class Vector4;

    typedef unsigned int    uint32;
    typedef unsigned short  uint16;
    typedef unsigned char   uint8;
    typedef int             int32;
    typedef short           int16;
    typedef char            int8;

    #if ATHENA_COMPILER == ATHENA_COMPILER_MSVC
        typedef unsigned __int64    uint64;
        typedef __int64             int64;
    #else
        typedef unsigned long long  uint64;
        typedef long long           int64;
    #endif

    extern const char* VERSION;
}
}

#endif

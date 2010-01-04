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
    class Degree;
    class Intersection;
    class Matrix3;
    class Matrix4;
    class Plane;
    class Radian;
    class Sphere;
    class Vector2;
    class Vector3;
    class Vector4;
}
}

#endif

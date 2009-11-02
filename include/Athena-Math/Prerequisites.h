/** @file   Prerequisites.h
    @author Philip Abbet
    
    Declaration of the types of the Athena-Math module
*/

#ifndef _ATHENA_MATH_PREREQUISITES_H_
#define _ATHENA_MATH_PREREQUISITES_H_

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
    class Degree;
    class Radian;
}
}

#endif

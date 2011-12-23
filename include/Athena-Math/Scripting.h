/** @file   Scripting.h
    @author Philip Abbet
    
    Scripting-related declarations for the Athena-Math module
*/

#ifndef _ATHENA_MATH_SCRIPTING_H_
#define _ATHENA_MATH_SCRIPTING_H_


namespace Athena {
namespace Math {

    enum
    {
        CLASSID_AXIS_ALIGNED_BOX = 100,
        CLASSID_COLOR,
        CLASSID_MATRIX3,
        CLASSID_MATRIX4,
        CLASSID_PLANE,
        CLASSID_QUATERNION,
        CLASSID_RANDOM_NUMBER_GENERATOR,
        CLASSID_SHUFFLE_BAG,
        CLASSID_SPHERE,
        CLASSID_VECTOR2,
        CLASSID_VECTOR3,
        CLASSID_VECTOR4,
    };
}
}

#endif

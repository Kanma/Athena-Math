/** @file   Scripting.h
    @author Philip Abbet
    
    Scripting-related declarations for the Athena-Math module
*/

#ifndef _ATHENA_MATH_SCRIPTING_H_
#define _ATHENA_MATH_SCRIPTING_H_

#include <v8.h>
#include <Athena-Math/Vector3.h>
#include <Athena-Math/Quaternion.h>


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
    
    
    //------------------------------------------------------------------------------------
    /// @brief	Create a C++ Vector3 from a JavaScript one
    //------------------------------------------------------------------------------------
    Vector3 fromJSVector3(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief	Create a JavaScript Vector3 from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> toJavaScript(const Vector3& value);


    //------------------------------------------------------------------------------------
    /// @brief	Create a C++ Quaternion from a JavaScript one
    //------------------------------------------------------------------------------------
    Quaternion fromJSQuaternion(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief	Create a JavaScript Quaternion from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> toJavaScript(const Quaternion& value);
}
}

#endif

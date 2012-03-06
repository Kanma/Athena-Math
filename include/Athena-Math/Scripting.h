/** @file   Scripting.h
    @author Philip Abbet

    Scripting-related declarations for the Athena-Math module
*/

#ifndef _ATHENA_MATH_SCRIPTING_H_
#define _ATHENA_MATH_SCRIPTING_H_

#include <v8.h>
#include <Athena-Math/AxisAlignedBox.h>
#include <Athena-Math/Color.h>
#include <Athena-Math/Matrix4.h>
#include <Athena-Math/Plane.h>
#include <Athena-Math/Quaternion.h>
#include <Athena-Math/Sphere.h>
#include <Athena-Math/Vector2.h>
#include <Athena-Math/Vector3.h>
#include <Athena-Math/Vector4.h>


namespace Athena {
namespace Math {

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ AxisAlignedBox from a JavaScript one
    //------------------------------------------------------------------------------------
    AxisAlignedBox ATHENA_MATH_SYMBOL fromJSAxisAlignedBox(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript AxisAlignedBox from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const AxisAlignedBox& value);


    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Color from a JavaScript one
    //------------------------------------------------------------------------------------
    Color ATHENA_MATH_SYMBOL fromJSColor(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Color from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Color& value);


    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Matrix3 from a JavaScript one
    //------------------------------------------------------------------------------------
    Matrix3 ATHENA_MATH_SYMBOL fromJSMatrix3(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Matrix3 from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Matrix3& value);


    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Matrix4 from a JavaScript one
    //------------------------------------------------------------------------------------
    Matrix4 ATHENA_MATH_SYMBOL fromJSMatrix4(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Matrix4 from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Matrix4& value);


    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Plane from a JavaScript one
    //------------------------------------------------------------------------------------
    Plane ATHENA_MATH_SYMBOL fromJSPlane(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Plane from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Plane& value);


    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Quaternion from a JavaScript one
    //------------------------------------------------------------------------------------
    Quaternion ATHENA_MATH_SYMBOL fromJSQuaternion(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Quaternion from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Quaternion& value);


    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Sphere from a JavaScript one
    //------------------------------------------------------------------------------------
    Sphere ATHENA_MATH_SYMBOL fromJSSphere(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Sphere from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Sphere& value);


    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Vector2 from a JavaScript one
    //------------------------------------------------------------------------------------
    Vector2 ATHENA_MATH_SYMBOL fromJSVector2(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Vector2 from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Vector2& value);


    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Vector3 from a JavaScript one
    //------------------------------------------------------------------------------------
    Vector3 ATHENA_MATH_SYMBOL fromJSVector3(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Vector3 from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Vector3& value);


    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Vector4 from a JavaScript one
    //------------------------------------------------------------------------------------
    Vector4 ATHENA_MATH_SYMBOL fromJSVector4(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Vector4 from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Vector4& value);
}
}

#endif

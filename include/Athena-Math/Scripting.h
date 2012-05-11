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
    /// @brief  Returns the JavaScript object representing the 'Athena.Math' namespace
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL getJSAthenaMath();


    //------------------------------------------------------------------------------------
    /// @brief  Indicates if a JavaScript object is a AxisAlignedBox
    //------------------------------------------------------------------------------------
    bool ATHENA_MATH_SYMBOL isJSAxisAlignedBox(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ AxisAlignedBox from a JavaScript object WITHOUT CHECKING ITS
    ///         TYPE
    ///
    /// Only use this method if you already know that the JavaScript object is an
    /// AxisAlignedBox
    //------------------------------------------------------------------------------------
    AxisAlignedBox ATHENA_MATH_SYMBOL fromJSAxisAlignedBoxUnsafe(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ AxisAlignedBox from a JavaScript one
    //------------------------------------------------------------------------------------
    inline AxisAlignedBox ATHENA_MATH_SYMBOL fromJSAxisAlignedBox(v8::Handle<v8::Value> value)
    {
        if (isJSAxisAlignedBox(value))
            return fromJSAxisAlignedBoxUnsafe(value);
        
        return AxisAlignedBox();
    }

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript AxisAlignedBox from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const AxisAlignedBox& value);


    //------------------------------------------------------------------------------------
    /// @brief  Indicates if a JavaScript object is a Color
    //------------------------------------------------------------------------------------
    bool ATHENA_MATH_SYMBOL isJSColor(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Color from a JavaScript object WITHOUT CHECKING ITS TYPE
    ///
    /// Only use this method if you already know that the JavaScript object is a Color
    //------------------------------------------------------------------------------------
    Color ATHENA_MATH_SYMBOL fromJSColorUnsafe(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Color from a JavaScript one
    //------------------------------------------------------------------------------------
    inline Color ATHENA_MATH_SYMBOL fromJSColor(v8::Handle<v8::Value> value)
    {
        if (isJSColor(value))
            return fromJSColorUnsafe(value);
        
        return Color();
    }

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Color from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Color& value);


    //------------------------------------------------------------------------------------
    /// @brief  Indicates if a JavaScript object is a Matrix3
    //------------------------------------------------------------------------------------
    bool ATHENA_MATH_SYMBOL isJSMatrix3(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Matrix3 from a JavaScript object WITHOUT CHECKING ITS TYPE
    ///
    /// Only use this method if you already know that the JavaScript object is a Matrix3
    //------------------------------------------------------------------------------------
    Matrix3 ATHENA_MATH_SYMBOL fromJSMatrix3Unsafe(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Matrix3 from a JavaScript one
    //------------------------------------------------------------------------------------
    inline Matrix3 ATHENA_MATH_SYMBOL fromJSMatrix3(v8::Handle<v8::Value> value)
    {
        if (isJSMatrix3(value))
            return fromJSMatrix3Unsafe(value);
        
        return Matrix3::ZERO;
    }

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Matrix3 from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Matrix3& value);


    //------------------------------------------------------------------------------------
    /// @brief  Indicates if a JavaScript object is a Matrix4
    //------------------------------------------------------------------------------------
    bool ATHENA_MATH_SYMBOL isJSMatrix4(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Matrix4 from a JavaScript object WITHOUT CHECKING ITS TYPE
    ///
    /// Only use this method if you already know that the JavaScript object is a Matrix4
    //------------------------------------------------------------------------------------
    Matrix4 ATHENA_MATH_SYMBOL fromJSMatrix4Unsafe(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Matrix4 from a JavaScript one
    //------------------------------------------------------------------------------------
    inline Matrix4 ATHENA_MATH_SYMBOL fromJSMatrix4(v8::Handle<v8::Value> value)
    {
        if (isJSMatrix4(value))
            return fromJSMatrix4Unsafe(value);
        
        return Matrix4::ZERO;
    }

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Matrix4 from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Matrix4& value);


    //------------------------------------------------------------------------------------
    /// @brief  Indicates if a JavaScript object is a Plane
    //------------------------------------------------------------------------------------
    bool ATHENA_MATH_SYMBOL isJSPlane(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Plane from a JavaScript object WITHOUT CHECKING ITS TYPE
    ///
    /// Only use this method if you already know that the JavaScript object is a Plane
    //------------------------------------------------------------------------------------
    Plane ATHENA_MATH_SYMBOL fromJSPlaneUnsafe(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Plane from a JavaScript one
    //------------------------------------------------------------------------------------
    inline Plane ATHENA_MATH_SYMBOL fromJSPlane(v8::Handle<v8::Value> value)
    {
        if (isJSPlane(value))
            return fromJSPlaneUnsafe(value);
        
        return Plane();
    }

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Plane from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Plane& value);


    //------------------------------------------------------------------------------------
    /// @brief  Indicates if a JavaScript object is a Quaternion
    //------------------------------------------------------------------------------------
    bool ATHENA_MATH_SYMBOL isJSQuaternion(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Quaternion from a JavaScript object WITHOUT CHECKING ITS TYPE
    ///
    /// Only use this method if you already know that the JavaScript object is a Quaternion
    //------------------------------------------------------------------------------------
    Quaternion ATHENA_MATH_SYMBOL fromJSQuaternionUnsafe(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Quaternion from a JavaScript one
    //------------------------------------------------------------------------------------
    inline Quaternion ATHENA_MATH_SYMBOL fromJSQuaternion(v8::Handle<v8::Value> value)
    {
        if (isJSQuaternion(value))
            return fromJSQuaternionUnsafe(value);
        
        return Quaternion::ZERO;
    }

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Quaternion from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Quaternion& value);


    //------------------------------------------------------------------------------------
    /// @brief  Indicates if a JavaScript object is a Sphere
    //------------------------------------------------------------------------------------
    bool ATHENA_MATH_SYMBOL isJSSphere(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Sphere from a JavaScript object WITHOUT CHECKING ITS TYPE
    ///
    /// Only use this method if you already know that the JavaScript object is a Sphere
    //------------------------------------------------------------------------------------
    Sphere ATHENA_MATH_SYMBOL fromJSSphereUnsafe(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Sphere from a JavaScript one
    //------------------------------------------------------------------------------------
    inline Sphere ATHENA_MATH_SYMBOL fromJSSphere(v8::Handle<v8::Value> value)
    {
        if (isJSSphere(value))
            return fromJSSphereUnsafe(value);
        
        return Sphere();
    }

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Sphere from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Sphere& value);


    //------------------------------------------------------------------------------------
    /// @brief  Indicates if a JavaScript object is a Vector2
    //------------------------------------------------------------------------------------
    bool ATHENA_MATH_SYMBOL isJSVector2(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Vector2 from a JavaScript object WITHOUT CHECKING ITS TYPE
    ///
    /// Only use this method if you already know that the JavaScript object is a Vector2
    //------------------------------------------------------------------------------------
    Vector2 ATHENA_MATH_SYMBOL fromJSVector2Unsafe(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Vector2 from a JavaScript one
    //------------------------------------------------------------------------------------
    inline Vector2 ATHENA_MATH_SYMBOL fromJSVector2(v8::Handle<v8::Value> value)
    {
        if (isJSVector2(value))
            return fromJSVector2Unsafe(value);
        
        return Vector2::ZERO;
    }

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Vector2 from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Vector2& value);


    //------------------------------------------------------------------------------------
    /// @brief  Indicates if a JavaScript object is a Vector3
    //------------------------------------------------------------------------------------
    bool ATHENA_MATH_SYMBOL isJSVector3(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Vector3 from a JavaScript object WITHOUT CHECKING ITS TYPE
    ///
    /// Only use this method if you already know that the JavaScript object is a Vector3
    //------------------------------------------------------------------------------------
    Vector3 ATHENA_MATH_SYMBOL fromJSVector3Unsafe(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Vector3 from a JavaScript one
    //------------------------------------------------------------------------------------
    inline Vector3 ATHENA_MATH_SYMBOL fromJSVector3(v8::Handle<v8::Value> value)
    {
        if (isJSVector3(value))
            return fromJSVector3Unsafe(value);
        
        return Vector3::ZERO;
    }

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Vector3 from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Vector3& value);


    //------------------------------------------------------------------------------------
    /// @brief  Indicates if a JavaScript object is a Vector4
    //------------------------------------------------------------------------------------
    bool ATHENA_MATH_SYMBOL isJSVector4(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Vector4 from a JavaScript object WITHOUT CHECKING ITS TYPE
    ///
    /// Only use this method if you already know that the JavaScript object is a Vector4
    //------------------------------------------------------------------------------------
    Vector4 ATHENA_MATH_SYMBOL fromJSVector4Unsafe(v8::Handle<v8::Value> value);

    //------------------------------------------------------------------------------------
    /// @brief  Create a C++ Vector4 from a JavaScript one
    //------------------------------------------------------------------------------------
    inline Vector4 ATHENA_MATH_SYMBOL fromJSVector4(v8::Handle<v8::Value> value)
    {
        if (isJSVector4(value))
            return fromJSVector4Unsafe(value);
        
        return Vector4::ZERO;
    }

    //------------------------------------------------------------------------------------
    /// @brief  Create a JavaScript Vector4 from a C++ one
    //------------------------------------------------------------------------------------
    v8::Handle<v8::Value> ATHENA_MATH_SYMBOL toJavaScript(const Vector4& value);
}
}

#endif

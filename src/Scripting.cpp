/** @file   Scripting.cpp
    @author Philip Abbet

    Implementation of the scripting-related functions of the Athena-Math module
*/

#include <Athena-Math/Scripting.h>
#include <string>

using namespace Athena::Math;
using namespace v8;


namespace Athena {
namespace Math {


Handle<Value> getJSAthenaMath()
{
    Handle<Value> nsAthena = Context::GetCurrent()->Global()->Get(String::New("Athena"));
    if (!nsAthena->IsObject())
        return ThrowException(String::New("Can't find the namespace 'Athena'"));
    
    Handle<Value> nsMath = nsAthena->ToObject()->Get(String::New("Math"));
    if (!nsMath->IsObject())
        return ThrowException(String::New("Can't find the namespace 'Athena.Math'"));
    
    return nsMath;
}

//-----------------------------------------------------------------------

bool isJSAxisAlignedBox(v8::Handle<v8::Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());

        return (std::string("Athena.Math.AxisAlignedBox") == *String::AsciiValue(prototype->Get(String::New("__classname__"))));
    }

    return false;
}

//-----------------------------------------------------------------------

AxisAlignedBox fromJSAxisAlignedBoxUnsafe(Handle<Value> value)
{
    Handle<Object> object = value->ToObject();

    unsigned int t = object->Get(String::New("extent"))->ToNumber()->NumberValue();

    if (t == 0)
        return AxisAlignedBox(AxisAlignedBox::EXTENT_NULL);

    if (t == 2)
        return AxisAlignedBox(AxisAlignedBox::EXTENT_INFINITE);

    return AxisAlignedBox(fromJSVector3(object->Get(String::New("minimum"))),
                          fromJSVector3(object->Get(String::New("maximum"))));
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const AxisAlignedBox& value)
{
    Handle<Value> constructor = getJSAthenaMath()->ToObject()->Get(String::New("AxisAlignedBox"));
    if (!constructor->IsFunction())
        return ThrowException(String::New("Can't find the constructor function of Athena.Math.AxisAlignedBox"));

    Local<Object> object = Handle<Function>::Cast(constructor)->NewInstance();

    if (value.isNull())
    {
        object->Set(String::New("extent"), Number::New(0));
    }
    else if (value.isInfinite())
    {
        object->Set(String::New("extent"), Number::New(2));
    }
    else
    {
        object->Set(String::New("minimum"), toJavaScript(value.getMinimum()));
        object->Set(String::New("maximum"), toJavaScript(value.getMaximum()));
        object->Set(String::New("extent"), Number::New(1));
    }

    return object;
}

//-----------------------------------------------------------------------

bool isJSColor(v8::Handle<v8::Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());

        return (std::string("Athena.Math.Color") == *String::AsciiValue(prototype->Get(String::New("__classname__"))));
    }

    return false;
}

//-----------------------------------------------------------------------

Color fromJSColorUnsafe(Handle<Value> value)
{
    Handle<Object> object = value->ToObject();

    return Color(object->Get(String::New("r"))->ToNumber()->NumberValue(),
                 object->Get(String::New("g"))->ToNumber()->NumberValue(),
                 object->Get(String::New("b"))->ToNumber()->NumberValue(),
                 object->Get(String::New("a"))->ToNumber()->NumberValue());
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Color& value)
{
    Handle<Value> constructor = getJSAthenaMath()->ToObject()->Get(String::New("Color"));
    if (!constructor->IsFunction())
        return ThrowException(String::New("Can't find the constructor function of Athena.Math.Color"));

    Local<Object> object = Handle<Function>::Cast(constructor)->NewInstance();
    object->Set(String::New("r"), Number::New(value.r));
    object->Set(String::New("g"), Number::New(value.g));
    object->Set(String::New("b"), Number::New(value.b));
    object->Set(String::New("a"), Number::New(value.a));

    return object;
}

//-----------------------------------------------------------------------

bool isJSMatrix3(v8::Handle<v8::Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());

        return (std::string("Athena.Math.Matrix3") == *String::AsciiValue(prototype->Get(String::New("__classname__"))));
    }

    return false;
}

//-----------------------------------------------------------------------

Matrix3 fromJSMatrix3Unsafe(Handle<Value> value)
{
    Handle<Object> object = value->ToObject();

    return Matrix3(object->Get(String::New("m_0_0"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_0_1"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_0_2"))->ToNumber()->NumberValue(),

                   object->Get(String::New("m_1_0"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_1_1"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_1_2"))->ToNumber()->NumberValue(),

                   object->Get(String::New("m_2_0"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_2_1"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_2_2"))->ToNumber()->NumberValue()
    );
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Matrix3& value)
{
    Handle<Value> constructor = getJSAthenaMath()->ToObject()->Get(String::New("Matrix3"));
    if (!constructor->IsFunction())
        return ThrowException(String::New("Can't find the constructor function of Athena.Math.Matrix3"));

    Local<Object> object = Handle<Function>::Cast(constructor)->NewInstance();

    object->Set(String::New("m_0_0"), Number::New(value.m[0][0]));
    object->Set(String::New("m_0_1"), Number::New(value.m[0][1]));
    object->Set(String::New("m_0_2"), Number::New(value.m[0][2]));

    object->Set(String::New("m_1_0"), Number::New(value.m[1][0]));
    object->Set(String::New("m_1_1"), Number::New(value.m[1][1]));
    object->Set(String::New("m_1_2"), Number::New(value.m[1][2]));

    object->Set(String::New("m_2_0"), Number::New(value.m[2][0]));
    object->Set(String::New("m_2_1"), Number::New(value.m[2][1]));
    object->Set(String::New("m_2_2"), Number::New(value.m[2][2]));

    return object;
}

//-----------------------------------------------------------------------

bool isJSMatrix4(v8::Handle<v8::Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());

        return (std::string("Athena.Math.Matrix4") == *String::AsciiValue(prototype->Get(String::New("__classname__"))));
    }

    return false;
}

//-----------------------------------------------------------------------

Matrix4 fromJSMatrix4Unsafe(Handle<Value> value)
{
    Handle<Object> object = value->ToObject();

    return Matrix4(object->Get(String::New("m_0_0"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_0_1"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_0_2"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_0_3"))->ToNumber()->NumberValue(),

                   object->Get(String::New("m_1_0"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_1_1"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_1_2"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_1_3"))->ToNumber()->NumberValue(),

                   object->Get(String::New("m_2_0"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_2_1"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_2_2"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_2_3"))->ToNumber()->NumberValue(),

                   object->Get(String::New("m_3_0"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_3_1"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_3_2"))->ToNumber()->NumberValue(),
                   object->Get(String::New("m_3_3"))->ToNumber()->NumberValue()
    );
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Matrix4& value)
{
    Handle<Value> constructor = getJSAthenaMath()->ToObject()->Get(String::New("Matrix4"));
    if (!constructor->IsFunction())
        return ThrowException(String::New("Can't find the constructor function of Athena.Math.Matrix4"));

    Local<Object> object = Handle<Function>::Cast(constructor)->NewInstance();

    object->Set(String::New("m_0_0"), Number::New(value.m[0][0]));
    object->Set(String::New("m_0_1"), Number::New(value.m[0][1]));
    object->Set(String::New("m_0_2"), Number::New(value.m[0][2]));
    object->Set(String::New("m_0_3"), Number::New(value.m[0][3]));

    object->Set(String::New("m_1_0"), Number::New(value.m[1][0]));
    object->Set(String::New("m_1_1"), Number::New(value.m[1][1]));
    object->Set(String::New("m_1_2"), Number::New(value.m[1][2]));
    object->Set(String::New("m_1_3"), Number::New(value.m[1][3]));

    object->Set(String::New("m_2_0"), Number::New(value.m[2][0]));
    object->Set(String::New("m_2_1"), Number::New(value.m[2][1]));
    object->Set(String::New("m_2_2"), Number::New(value.m[2][2]));
    object->Set(String::New("m_2_3"), Number::New(value.m[2][3]));

    object->Set(String::New("m_3_0"), Number::New(value.m[3][0]));
    object->Set(String::New("m_3_1"), Number::New(value.m[3][1]));
    object->Set(String::New("m_3_2"), Number::New(value.m[3][2]));
    object->Set(String::New("m_3_3"), Number::New(value.m[3][3]));

    return object;
}

//-----------------------------------------------------------------------

bool isJSPlane(v8::Handle<v8::Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());

        return (std::string("Athena.Math.Plane") == *String::AsciiValue(prototype->Get(String::New("__classname__"))));
    }

    return false;
}

//-----------------------------------------------------------------------

Plane fromJSPlaneUnsafe(Handle<Value> value)
{
    Handle<Object> object = value->ToObject();

    return Plane(fromJSVector3(object->Get(String::New("normal"))),
                 object->Get(String::New("d"))->ToNumber()->NumberValue());
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Plane& value)
{
    Handle<Value> constructor = getJSAthenaMath()->ToObject()->Get(String::New("Plane"));
    if (!constructor->IsFunction())
        return ThrowException(String::New("Can't find the constructor function of Athena.Math.Plane"));

    Local<Object> object = Handle<Function>::Cast(constructor)->NewInstance();
    object->Set(String::New("normal"), toJavaScript(value.normal));
    object->Set(String::New("d"), Number::New(value.d));

    return object;
}

//-----------------------------------------------------------------------

bool isJSQuaternion(v8::Handle<v8::Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());

        return (std::string("Athena.Math.Quaternion") == *String::AsciiValue(prototype->Get(String::New("__classname__"))));
    }

    return false;
}

//-----------------------------------------------------------------------

Quaternion fromJSQuaternionUnsafe(Handle<Value> value)
{
    Handle<Object> object = value->ToObject();

    return Quaternion(object->Get(String::New("w"))->ToNumber()->NumberValue(),
                      object->Get(String::New("x"))->ToNumber()->NumberValue(),
                      object->Get(String::New("y"))->ToNumber()->NumberValue(),
                      object->Get(String::New("z"))->ToNumber()->NumberValue());
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Quaternion& value)
{
    Handle<Value> constructor = getJSAthenaMath()->ToObject()->Get(String::New("Quaternion"));
    if (!constructor->IsFunction())
        return ThrowException(String::New("Can't find the constructor function of Athena.Math.Quaternion"));

    Local<Object> object = Handle<Function>::Cast(constructor)->NewInstance();
    object->Set(String::New("w"), Number::New(value.w));
    object->Set(String::New("x"), Number::New(value.x));
    object->Set(String::New("y"), Number::New(value.y));
    object->Set(String::New("z"), Number::New(value.z));

    return object;
}

//-----------------------------------------------------------------------

bool isJSSphere(v8::Handle<v8::Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());

        return (std::string("Athena.Math.Sphere") == *String::AsciiValue(prototype->Get(String::New("__classname__"))));
    }

    return false;
}

//-----------------------------------------------------------------------

Sphere fromJSSphereUnsafe(Handle<Value> value)
{
    Handle<Object> object = value->ToObject();

    return Sphere(fromJSVector3(object->Get(String::New("center"))),
                  object->Get(String::New("radius"))->ToNumber()->NumberValue());
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Sphere& value)
{
    Handle<Value> constructor = getJSAthenaMath()->ToObject()->Get(String::New("Sphere"));
    if (!constructor->IsFunction())
        return ThrowException(String::New("Can't find the constructor function of Athena.Math.Sphere"));

    Local<Object> object = Handle<Function>::Cast(constructor)->NewInstance();
    object->Set(String::New("center"), toJavaScript(value.getCenter()));
    object->Set(String::New("radius"), Number::New(value.getRadius()));

    return object;
}

//-----------------------------------------------------------------------

bool isJSVector2(v8::Handle<v8::Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());

        return (std::string("Athena.Math.Vector2") == *String::AsciiValue(prototype->Get(String::New("__classname__"))));
    }

    return false;
}

//-----------------------------------------------------------------------

Vector2 fromJSVector2Unsafe(Handle<Value> value)
{
    Handle<Object> object = value->ToObject();

    return Vector2(object->Get(String::New("x"))->ToNumber()->NumberValue(),
                   object->Get(String::New("y"))->ToNumber()->NumberValue());
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Vector2& value)
{
    Handle<Value> constructor = getJSAthenaMath()->ToObject()->Get(String::New("Vector2"));
    if (!constructor->IsFunction())
        return ThrowException(String::New("Can't find the constructor function of Athena.Math.Vector2"));

    Local<Object> object = Handle<Function>::Cast(constructor)->NewInstance();
    object->Set(String::New("x"), Number::New(value.x));
    object->Set(String::New("y"), Number::New(value.y));

    return object;
}

//-----------------------------------------------------------------------

bool isJSVector3(v8::Handle<v8::Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());

        return (std::string("Athena.Math.Vector3") == *String::AsciiValue(prototype->Get(String::New("__classname__"))));
    }

    return false;
}

//-----------------------------------------------------------------------

Vector3 fromJSVector3Unsafe(Handle<Value> value)
{
    Handle<Object> object = value->ToObject();

    return Vector3(object->Get(String::New("x"))->ToNumber()->NumberValue(),
                   object->Get(String::New("y"))->ToNumber()->NumberValue(),
                   object->Get(String::New("z"))->ToNumber()->NumberValue());
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Vector3& value)
{
    Handle<Value> constructor = getJSAthenaMath()->ToObject()->Get(String::New("Vector3"));
    if (!constructor->IsFunction())
        return ThrowException(String::New("Can't find the constructor function of Athena.Math.Vector3"));

    Local<Object> object = Handle<Function>::Cast(constructor)->NewInstance();
    object->Set(String::New("x"), Number::New(value.x));
    object->Set(String::New("y"), Number::New(value.y));
    object->Set(String::New("z"), Number::New(value.z));

    return object;
}

//-----------------------------------------------------------------------

bool isJSVector4(v8::Handle<v8::Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());

        return (std::string("Athena.Math.Vector4") == *String::AsciiValue(prototype->Get(String::New("__classname__"))));
    }

    return false;
}

//-----------------------------------------------------------------------

Vector4 fromJSVector4Unsafe(Handle<Value> value)
{
    Handle<Object> object = value->ToObject();

    return Vector4(object->Get(String::New("x"))->ToNumber()->NumberValue(),
                   object->Get(String::New("y"))->ToNumber()->NumberValue(),
                   object->Get(String::New("z"))->ToNumber()->NumberValue(),
                   object->Get(String::New("w"))->ToNumber()->NumberValue());
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Vector4& value)
{
    Handle<Value> constructor = getJSAthenaMath()->ToObject()->Get(String::New("Vector4"));
    if (!constructor->IsFunction())
        return ThrowException(String::New("Can't find the constructor function of Athena.Math.Vector4"));

    Local<Object> object = Handle<Function>::Cast(constructor)->NewInstance();
    object->Set(String::New("x"), Number::New(value.x));
    object->Set(String::New("y"), Number::New(value.y));
    object->Set(String::New("z"), Number::New(value.z));
    object->Set(String::New("w"), Number::New(value.w));

    return object;
}

}
}

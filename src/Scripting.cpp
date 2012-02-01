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

Vector3 fromJSVector3(Handle<Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());
        
        if (std::string("Athena.Math.Vector3") == *String::AsciiValue(prototype->Get(String::New("__classname__"))))
        {
            return Vector3(object->Get(String::New("x"))->ToNumber()->NumberValue(),
                           object->Get(String::New("y"))->ToNumber()->NumberValue(),
                           object->Get(String::New("z"))->ToNumber()->NumberValue());
        }
    }

    return Vector3::ZERO;
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Vector3& value)
{
    Handle<Value> constructor = Context::GetCurrent()->Global()->Get(String::New("Athena.Math.Vector3"));
    if (!constructor->IsFunction())
        return ThrowException(String::New("Can't find the constructor function of Athena.Math.Vector3"));

    Local<Object> object = Handle<Function>::Cast(constructor)->NewInstance();
    object->Set(String::New("x"), Number::New(value.x));
    object->Set(String::New("y"), Number::New(value.y));
    object->Set(String::New("z"), Number::New(value.z));
    
    return object;
}

//-----------------------------------------------------------------------

Quaternion fromJSQuaternion(Handle<Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());
        
        if (std::string("Athena.Math.Quaternion") == *String::AsciiValue(prototype->Get(String::New("__classname__"))))
        {
            return Quaternion(object->Get(String::New("w"))->ToNumber()->NumberValue(),
                              object->Get(String::New("x"))->ToNumber()->NumberValue(),
                              object->Get(String::New("y"))->ToNumber()->NumberValue(),
                              object->Get(String::New("z"))->ToNumber()->NumberValue());
        }
    }

    return Quaternion::ZERO;
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Quaternion& value)
{
    Handle<Value> constructor = Context::GetCurrent()->Global()->Get(String::New("Athena.Math.Quaternion"));
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

Matrix4 fromJSMatrix4(Handle<Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());
        
        if (std::string("Athena.Math.Matrix4") == *String::AsciiValue(prototype->Get(String::New("__classname__"))))
        {
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
    }

    return Matrix4::ZERO;
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Matrix4& value)
{
    Handle<Value> constructor = Context::GetCurrent()->Global()->Get(String::New("Athena.Math.Matrix4"));
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

Matrix3 fromJSMatrix3(Handle<Value> value)
{
    if (value->IsObject())
    {
        Handle<Object> object = value->ToObject();
        Handle<Function> prototype = Handle<Function>::Cast(object->GetPrototype());
        
        if (std::string("Athena.Math.Matrix3") == *String::AsciiValue(prototype->Get(String::New("__classname__"))))
        {
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
    }

    return Matrix3::ZERO;
}

//-----------------------------------------------------------------------

Handle<Value> toJavaScript(const Matrix3& value)
{
    Handle<Value> constructor = Context::GetCurrent()->Global()->Get(String::New("Athena.Math.Matrix3"));
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

}
}

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

}
}

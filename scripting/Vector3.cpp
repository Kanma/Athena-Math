/** @file   Vector3.cpp
    @author Philip Abbet
    
    Javascript binding of the class Athena::Math::Vector3
*/

#include <Athena-Math/Vector3.h>
#include <v8.h>

using namespace Athena::Math;
using namespace v8;


/*************************************** GLOBALS ***************************************/

Persistent<ObjectTemplate> template_Vector3;


/***************************** CONSTRUCTION / DESTRUCTION ******************************/

// Destructor
void Vector3_WeakCallback(Persistent<Value> value, void* data)
{
    if (value.IsNearDeath())
    {
        Local<External> wrap = Local<External>::Cast(Persistent<Object>::Cast(value)->GetInternalField(0));
        Vector3* v = static_cast<Vector3*>(wrap->Value());
        delete v;
    }
}

//-----------------------------------------------------------------------

// Constructor
Handle<Value> Vector3_New(const Arguments& args)
{
    Vector3* v;
    
    if (args.Length() == 3)
    {
        v = new Vector3((Real) args[0]->NumberValue(),
                        (Real) args[1]->NumberValue(),
                        (Real) args[2]->NumberValue());
    }
    else if (args.Length() == 1)
    {
        v = new Vector3((Real) args[0]->NumberValue());
    }
    else
    {
        v = new Vector3();
    }

    Persistent<Object> jsVector = Persistent<Object>::New(template_Vector3->NewInstance());
    jsVector->SetInternalField(0, External::New(v));
    jsVector.MakeWeak(0, Vector3_WeakCallback);
    
    V8::AdjustAmountOfExternalAllocatedMemory(sizeof(Vector3));
    
    return jsVector;
}


/************************************** ATTRIBUTES *************************************/

Handle<Value> Vector3_GetX(Local<String> property, const AccessorInfo &info)
{
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    Vector3* v = static_cast<Vector3*>(wrap->Value());
    return Number::New(v->x);
}

//-----------------------------------------------------------------------

void Vector3_SetX(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    Vector3* v = static_cast<Vector3*>(wrap->Value());
    v->x = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_GetY(Local<String> property, const AccessorInfo &info)
{
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    Vector3* v = static_cast<Vector3*>(wrap->Value());
    return Number::New(v->y);
}

//-----------------------------------------------------------------------

void Vector3_SetY(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    Vector3* v = static_cast<Vector3*>(wrap->Value());
    v->y = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_GetZ(Local<String> property, const AccessorInfo &info)
{
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    Vector3* v = static_cast<Vector3*>(wrap->Value());
    return Number::New(v->z);
}

//-----------------------------------------------------------------------

void Vector3_SetZ(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    Vector3* v = static_cast<Vector3*>(wrap->Value());
    v->z = (Real) value->NumberValue();
}


/*********************************** BINDING FUNCTION **********************************/

bool bind_Vector3(Handle<Object> parent)
{
    template_Vector3 = Persistent<ObjectTemplate>::New(ObjectTemplate::New());
    template_Vector3->SetCallAsFunctionHandler(Vector3_New);
    template_Vector3->SetInternalFieldCount(1);

    template_Vector3->SetAccessor(String::New("x"), Vector3_GetX, Vector3_SetX);
    template_Vector3->SetAccessor(String::New("y"), Vector3_GetY, Vector3_SetY);
    template_Vector3->SetAccessor(String::New("z"), Vector3_GetZ, Vector3_SetZ);

    return parent->Set(String::New("Vector3"), FunctionTemplate::New(Vector3_New)->GetFunction());
}

/** @file   Vector3.cpp
    @author Philip Abbet
    
    Javascript binding of the class Athena::Math::Vector3
*/

#include <Athena-Math/Vector3.h>
#include <Athena-Scripting/Utils.h>
#include <v8.h>

using namespace Athena::Math;
using namespace Athena::Scripting;
using namespace v8;


/*************************************** GLOBALS ***************************************/

Persistent<ObjectTemplate> template_Vector3;


/***************************** CONSTRUCTION / DESTRUCTION ******************************/

// Destructor
void Vector3_WeakCallback(Persistent<Value> value, void* data)
{
    if (value.IsNearDeath())
    {
        Vector3* v = CastJSObject<Vector3>(value);
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
        v = new Vector3(args[0]->IsNumber() ? (Real) args[0]->NumberValue() : 0.0f,
                        args[1]->IsNumber() ? (Real) args[1]->NumberValue() : 0.0f,
                        args[2]->IsNumber() ? (Real) args[2]->NumberValue() : 0.0f);
    }
    else if (args.Length() == 1)
    {
        if (args[0]->IsNumber())
        {
            v = new Vector3((Real) args[0]->NumberValue());
        }
        else if (args[0]->IsObject())
        {
            Vector3* vref = CastJSObject<Vector3>(args[0]);
            if (vref)
                v = new Vector3(*vref);
        }
        else
        {
            return Handle<Value>();
        }
    }

    if (!v)
        v = new Vector3();

    Persistent<Object> jsVector = Persistent<Object>::New(template_Vector3->NewInstance());
    jsVector->SetInternalField(0, External::New(v));
    jsVector.MakeWeak(0, Vector3_WeakCallback);
    
    V8::AdjustAmountOfExternalAllocatedMemory(sizeof(Vector3));
    
    return jsVector;
}


/************************************** ATTRIBUTES *************************************/

Handle<Value> Vector3_GetX(Local<String> property, const AccessorInfo &info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder());
    if (!v)
        return Handle<Value>();
    
    return Number::New(v->x);
}

//-----------------------------------------------------------------------

void Vector3_SetX(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder());
    if (v)
        v->x = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_GetY(Local<String> property, const AccessorInfo &info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder());
    if (!v)
        return Handle<Value>();

    return Number::New(v->y);
}

//-----------------------------------------------------------------------

void Vector3_SetY(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder());
    if (v)
        v->y = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_GetZ(Local<String> property, const AccessorInfo &info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder());
    if (!v)
        return Handle<Value>();

    return Number::New(v->z);
}

//-----------------------------------------------------------------------

void Vector3_SetZ(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder());
    if (v)
        v->z = (Real) value->NumberValue();
}


/**************************************** METHODS ***************************************/

Handle<Value> Vector3_Set(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    if (args[0]->IsNumber())
    {
        *self = (Real) args[0]->NumberValue();
    }
    else if (args[0]->IsObject())
    {
        Vector3* vref = CastJSObject<Vector3>(args[0]);

        if (vref)
            *self = *vref;
    }
    
    return Handle<Value>();
}


/*********************************** BINDING FUNCTION **********************************/

bool bind_Vector3(Handle<Object> parent)
{
    // Create the object template
    template_Vector3 = Persistent<ObjectTemplate>::New(ObjectTemplate::New());
    template_Vector3->SetCallAsFunctionHandler(Vector3_New);
    template_Vector3->SetInternalFieldCount(1);

    // Accessors
    template_Vector3->SetAccessor(String::New("x"), Vector3_GetX, Vector3_SetX);
    template_Vector3->SetAccessor(String::New("y"), Vector3_GetY, Vector3_SetY);
    template_Vector3->SetAccessor(String::New("z"), Vector3_GetZ, Vector3_SetZ);

    // Methods
    template_Vector3->Set(String::New("set"), FunctionTemplate::New(Vector3_Set)->GetFunction());

    // Add the class to the parent
    return parent->Set(String::New("Vector3"), FunctionTemplate::New(Vector3_New)->GetFunction());
}

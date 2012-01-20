/** @file   Quaternion.cpp
    @author Philip Abbet
    
    Javascript binding of the class Athena::Math::Quaternion
*/

#include <Athena-Math/Quaternion.h>
#include <Athena-Math/Scripting.h>
#include <Athena-Scripting/Utils.h>
#include <v8.h>

using namespace Athena::Math;
using namespace Athena::Scripting;
using namespace v8;


/**************************************** MACROS ***************************************/

#define createJSQuaternion(q)                                                   \
    createJSObject<Quaternion>(template_Quaternion, Quaternion_WeakCallback,    \
                               new Quaternion(q),                               \
                               sizeof(Quaternion), CLASSID_QUATERNION);

#define createJSQuaternionFromPtr(q)                                            \
    createJSObject<Quaternion>(template_Quaternion, Quaternion_WeakCallback,    \
                               q, sizeof(Quaternion), CLASSID_QUATERNION);

#define bindMethod(NAME, CALLBACK)                                              \
    template_Quaternion->Set(String::New(NAME), FunctionTemplate::New(CALLBACK)->GetFunction());

#define CastJSQuaternion(HANDLE) CastJSObject<Quaternion>(HANDLE, CLASSID_QUATERNION)

#define CastJSVector3(HANDLE) CastJSObject<Vector3>(HANDLE, CLASSID_VECTOR3)


/*************************************** GLOBALS ***************************************/

Persistent<ObjectTemplate> template_Quaternion;


/***************************** CONSTRUCTION / DESTRUCTION ******************************/

// Destructor
void Quaternion_WeakCallback(Persistent<Value> value, void* data)
{
    if (value.IsNearDeath())
    {
        Quaternion* v = CastJSObject<Quaternion>(value, CLASSID_QUATERNION);
        delete v;
    }
}

//-----------------------------------------------------------------------

// Constructor
Handle<Value> Quaternion_New(const Arguments& args)
{
    Quaternion* q = 0;
    
    if (args.Length() == 4)
    {
        if (!args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsNumber() || !args[3]->IsNumber())
            return ThrowException(String::New("Invalid parameters, expected 4 numbers"));
        
        q = new Quaternion((Real) args[0]->NumberValue(),
                           (Real) args[1]->NumberValue(),
                           (Real) args[2]->NumberValue(),
                           (Real) args[3]->NumberValue());
    }
    else if (args.Length() == 1)
    {
        Quaternion* q2 = CastJSQuaternion(args[0]);
        if (q2)
        {
            q = new Quaternion(*q2);
        }
        else
        {
            return ThrowException(String::New("Invalid parameter, expected a quaternion or a matrix"));
        }
    }
    else if (args.Length() == 2)
    {
        if (!args[0]->IsNumber() || !args[1]->IsObject())
            return ThrowException(String::New("Invalid parameters, expected an angle and a vector"));

        Vector3* rkAxis = CastJSVector3(args[1]);
        if (!rkAxis)
            return ThrowException(String::New("Invalid parameters, expected an angle and a vector"));
        
        q = new Quaternion(Radian((Real) args[0]->NumberValue()), *rkAxis);
    }
    else if (args.Length() == 3)
    {
        if (!args[0]->IsObject() || !args[1]->IsObject() || !args[2]->IsObject())
            return ThrowException(String::New("Invalid parameters, expected 3 vectors"));

        Vector3* xaxis = CastJSVector3(args[0]);
        Vector3* yaxis = CastJSVector3(args[1]);
        Vector3* zaxis = CastJSVector3(args[2]);

        if (!xaxis || !yaxis || !zaxis)
            return ThrowException(String::New("Invalid parameters, expected 3 vectors"));

        q = new Quaternion(*xaxis, *yaxis, *zaxis);
    }
    else if (args.Length() == 0)
    {
        q = new Quaternion();
    }

    if (!q)
        return ThrowException(String::New("Invalid parameters"));

    return createJSQuaternionFromPtr(q);
}


/************************************** ATTRIBUTES *************************************/

Handle<Value> Quaternion_GetW(Local<String> property, const AccessorInfo &info)
{
    Quaternion* q = CastJSQuaternion(info.Holder());
    if (!q)
        return ThrowException(String::New("'this' isn't a Quaternion"));
    
    return Number::New(q->w);
}

//-----------------------------------------------------------------------

void Quaternion_SetW(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Quaternion* q = CastJSQuaternion(info.Holder());
    if (!q)
    {
        ThrowException(String::New("'this' isn't a Quaternion"));
        return;
    }

    q->w = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Quaternion_GetX(Local<String> property, const AccessorInfo &info)
{
    Quaternion* q = CastJSQuaternion(info.Holder());
    if (!q)
        return ThrowException(String::New("'this' isn't a Quaternion"));
    
    return Number::New(q->x);
}

//-----------------------------------------------------------------------

void Quaternion_SetX(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Quaternion* q = CastJSQuaternion(info.Holder());
    if (!q)
    {
        ThrowException(String::New("'this' isn't a Quaternion"));
        return;
    }

    q->x = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Quaternion_GetY(Local<String> property, const AccessorInfo &info)
{
    Quaternion* q = CastJSQuaternion(info.Holder());
    if (!q)
        return ThrowException(String::New("'this' isn't a Quaternion"));

    return Number::New(q->y);
}

//-----------------------------------------------------------------------

void Quaternion_SetY(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Quaternion* q = CastJSQuaternion(info.Holder());
    if (!q)
    {
        ThrowException(String::New("'this' isn't a Quaternion"));
        return;
    }

    q->y = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Quaternion_GetZ(Local<String> property, const AccessorInfo &info)
{
    Quaternion* q = CastJSQuaternion(info.Holder());
    if (!q)
        return ThrowException(String::New("'this' isn't a Quaternion"));

    return Number::New(q->z);
}

//-----------------------------------------------------------------------

void Quaternion_SetZ(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Quaternion* q = CastJSQuaternion(info.Holder());
    if (!q)
    {
        ThrowException(String::New("'this' isn't a Quaternion"));
        return;
    }

    q->z = (Real) value->NumberValue();
}


/*********************************** VALUE ASSIGNATION **********************************/

Handle<Value> Quaternion_Set(const Arguments& args)
{
    if (args.Length() != 1)
        return ThrowException(String::New("Invalid parameter, expected a Vector3"));

    Quaternion* self = CastJSQuaternion(args.This());
    if (!self)
        return ThrowException(String::New("'this' isn't a Quaternion"));

    Quaternion* qref = CastJSQuaternion(args[0]);
    if (!qref)
        return ThrowException(String::New("Invalid parameter, expected a Vector3"));

    *self = *qref;
    
    return Handle<Value>();
}


/************************************ BINDING FUNCTION **********************************/

bool bind_Quaternion(Handle<Object> parent)
{
    // Create the object template
    template_Quaternion = Persistent<ObjectTemplate>::New(ObjectTemplate::New());
    template_Quaternion->SetCallAsFunctionHandler(Quaternion_New);
    template_Quaternion->SetInternalFieldCount(2);

    // Accessors
    template_Quaternion->SetAccessor(String::New("w"), Quaternion_GetW, Quaternion_SetW);
    template_Quaternion->SetAccessor(String::New("x"), Quaternion_GetX, Quaternion_SetX);
    template_Quaternion->SetAccessor(String::New("y"), Quaternion_GetY, Quaternion_SetY);
    template_Quaternion->SetAccessor(String::New("z"), Quaternion_GetZ, Quaternion_SetZ);

    // Value assignation
    bindMethod("set", Quaternion_Set);
    
    // // Comparison operations
    // bindMethod("equals", Vector3_Equals);
    // bindMethod("notEquals", Vector3_NotEquals);
    // bindMethod("lesserThan", Vector3_LesserThan);
    // bindMethod("greaterThan", Vector3_GreaterThan);
    // 
    // // Arithmetic operations
    // bindMethod("add", Vector3_Add);
    // bindMethod("sub", Vector3_Sub);
    // bindMethod("mul", Vector3_Mul);
    // bindMethod("divide", Vector3_Divide);
    // bindMethod("negate", Vector3_Negate);
    // 
    // // Arithmetic updates
    // bindMethod("iadd", Vector3_IAdd);
    // bindMethod("isub", Vector3_ISub);
    // bindMethod("imul", Vector3_IMul);
    // bindMethod("idivide", Vector3_IDivide);
    // bindMethod("inegate", Vector3_INegate);
    // 
    // // Methods
    // bindMethod("length", Vector3_Length);
    // bindMethod("squaredLength", Vector3_SquaredLength);
    // bindMethod("isZeroLength", Vector3_IsZeroLength);
    // bindMethod("distance", Vector3_Distance);
    // bindMethod("squaredDistance", Vector3_SquaredDistance);
    // bindMethod("dot", Vector3_DotProduct);
    // bindMethod("absDot", Vector3_AbsDotProduct);
    // bindMethod("normalise", Vector3_Normalise);
    // bindMethod("normalisedCopy", Vector3_NormalisedCopy);
    // bindMethod("cross", Vector3_CrossProduct);
    // bindMethod("midPoint", Vector3_MidPoint);
    // bindMethod("makeFloor", Vector3_MakeFloor);
    // bindMethod("makeCeil", Vector3_MakeCeil);
    // bindMethod("perpendicular", Vector3_Perpendicular);
    // // MISSING: randomDeviant()
    // // MISSING: angleBetween()
    // // MISSING: getRotationTo()
    // bindMethod("reflect", Vector3_Reflect);
    // bindMethod("positionEquals", Vector3_PositionEquals);
    // bindMethod("positionCloses", Vector3_PositionCloses);
    // // MISSING: directionEquals()
    // bindMethod("isNaN", Vector3_IsNaN);

    // Add the class to the parent
    return parent->Set(String::New("Quaternion"), FunctionTemplate::New(Quaternion_New)->GetFunction());

    // 
    // // Constants (can't be members of Vector3)
    // return parent->SetAccessor(String::New("Vector3_ZERO"), Vector3_ZERO, 0) &&
    //        parent->SetAccessor(String::New("Vector3_UNIT_X"), Vector3_UNIT_X, 0) &&
    //        parent->SetAccessor(String::New("Vector3_UNIT_Y"), Vector3_UNIT_Y, 0) &&
    //        parent->SetAccessor(String::New("Vector3_UNIT_Z"), Vector3_UNIT_Z, 0) &&
    //        parent->SetAccessor(String::New("Vector3_NEGATIVE_UNIT_X"), Vector3_NEGATIVE_UNIT_X, 0) &&
    //        parent->SetAccessor(String::New("Vector3_NEGATIVE_UNIT_Y"), Vector3_NEGATIVE_UNIT_Y, 0) &&
    //        parent->SetAccessor(String::New("Vector3_NEGATIVE_UNIT_Z"), Vector3_NEGATIVE_UNIT_Z, 0) &&
    //        parent->SetAccessor(String::New("Vector3_UNIT_SCALE"), Vector3_UNIT_SCALE, 0);
}

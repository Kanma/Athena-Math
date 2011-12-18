/** @file   Quaternion.cpp
    @author Philip Abbet
    
    Javascript binding of the class Athena::Math::Quaternion
*/

#include <Athena-Math/Quaternion.h>
#include <Athena-Scripting/Utils.h>
#include <v8.h>

using namespace Athena::Math;
using namespace Athena::Scripting;
using namespace v8;


/*************************************** GLOBALS ***************************************/

Persistent<ObjectTemplate> template_Quaternion;


/***************************** CONSTRUCTION / DESTRUCTION ******************************/

// Destructor
void Quaternion_WeakCallback(Persistent<Value> value, void* data)
{
    if (value.IsNearDeath())
    {
        Quaternion* v = CastJSObject<Quaternion>(value);
        delete v;
    }
}

//-----------------------------------------------------------------------

// Helper function
inline Persistent<Object> createJSQuaternion(Quaternion* q)
{
    Persistent<Object> jsQuaternion = Persistent<Object>::New(template_Quaternion->NewInstance());
    jsQuaternion->SetInternalField(0, External::New(q));
    jsQuaternion.MakeWeak(0, Quaternion_WeakCallback);
    
    V8::AdjustAmountOfExternalAllocatedMemory(sizeof(Quaternion));
    
    return jsQuaternion;
}

//-----------------------------------------------------------------------

// Constructor
Handle<Value> Quaternion_New(const Arguments& args)
{
    Quaternion* q = 0;
    
    if (args.Length() == 4)
    {
        q = new Quaternion(args[0]->IsNumber() ? (Real) args[0]->NumberValue() : 0.0f,
                           args[1]->IsNumber() ? (Real) args[1]->NumberValue() : 0.0f,
                           args[2]->IsNumber() ? (Real) args[2]->NumberValue() : 0.0f,
                           args[3]->IsNumber() ? (Real) args[3]->NumberValue() : 0.0f);
    }
    else if (args.Length() == 1)
    {
        // Matrix
    }
    else if (args.Length() == 2)
    {
        if (args[0]->IsNumber() && args[1]->IsObject())
        {
            Vector3* rkAxis = CastJSObject<Vector3>(args[1]);
            if (rkAxis)
                q = new Quaternion(Radian((Real) args[0]->NumberValue()), *rkAxis);
        }
    }
    else if (args.Length() == 3)
    {
        if (args[0]->IsObject() && args[1]->IsObject() && args[2]->IsObject())
        {
            Vector3* xaxis = CastJSObject<Vector3>(args[0]);
            Vector3* yaxis = CastJSObject<Vector3>(args[1]);
            Vector3* zaxis = CastJSObject<Vector3>(args[2]);

            if (xaxis && yaxis && zaxis)
                q = new Quaternion(*xaxis, *yaxis, *zaxis);
        }
    }

    if (!q)
        q = new Quaternion();

    return createJSQuaternion(q);
}


/************************************** ATTRIBUTES *************************************/

Handle<Value> Quaternion_GetW(Local<String> property, const AccessorInfo &info)
{
    Quaternion* q = CastJSObject<Quaternion>(info.Holder());
    if (!q)
        return Handle<Value>();
    
    return Number::New(q->w);
}

//-----------------------------------------------------------------------

void Quaternion_SetW(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Quaternion* q = CastJSObject<Quaternion>(info.Holder());
    if (q)
        q->w = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Quaternion_GetX(Local<String> property, const AccessorInfo &info)
{
    Quaternion* q = CastJSObject<Quaternion>(info.Holder());
    if (!q)
        return Handle<Value>();
    
    return Number::New(q->x);
}

//-----------------------------------------------------------------------

void Quaternion_SetX(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Quaternion* q = CastJSObject<Quaternion>(info.Holder());
    if (q)
        q->x = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Quaternion_GetY(Local<String> property, const AccessorInfo &info)
{
    Quaternion* q = CastJSObject<Quaternion>(info.Holder());
    if (!q)
        return Handle<Value>();

    return Number::New(q->y);
}

//-----------------------------------------------------------------------

void Quaternion_SetY(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Quaternion* q = CastJSObject<Quaternion>(info.Holder());
    if (q)
        q->y = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Quaternion_GetZ(Local<String> property, const AccessorInfo &info)
{
    Quaternion* q = CastJSObject<Quaternion>(info.Holder());
    if (!q)
        return Handle<Value>();

    return Number::New(q->z);
}

//-----------------------------------------------------------------------

void Quaternion_SetZ(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Quaternion* q = CastJSObject<Quaternion>(info.Holder());
    if (q)
        q->z = (Real) value->NumberValue();
}


/************************************ BINDING FUNCTION **********************************/

bool bind_Quaternion(Handle<Object> parent)
{
    // Create the object template
    template_Quaternion = Persistent<ObjectTemplate>::New(ObjectTemplate::New());
    template_Quaternion->SetCallAsFunctionHandler(Quaternion_New);
    template_Quaternion->SetInternalFieldCount(1);

    // Accessors
    template_Quaternion->SetAccessor(String::New("w"), Quaternion_GetW, Quaternion_SetW);
    template_Quaternion->SetAccessor(String::New("x"), Quaternion_GetX, Quaternion_SetX);
    template_Quaternion->SetAccessor(String::New("y"), Quaternion_GetY, Quaternion_SetY);
    template_Quaternion->SetAccessor(String::New("z"), Quaternion_GetZ, Quaternion_SetZ);

    // // Value assignation
    // template_Vector3->Set(String::New("set"), FunctionTemplate::New(Vector3_Set)->GetFunction());
    // 
    // // Comparison operations
    // template_Vector3->Set(String::New("equals"), FunctionTemplate::New(Vector3_Equals)->GetFunction());
    // template_Vector3->Set(String::New("notEquals"), FunctionTemplate::New(Vector3_NotEquals)->GetFunction());
    // template_Vector3->Set(String::New("lesserThan"), FunctionTemplate::New(Vector3_LesserThan)->GetFunction());
    // template_Vector3->Set(String::New("greaterThan"), FunctionTemplate::New(Vector3_GreaterThan)->GetFunction());
    // 
    // // Arithmetic operations
    // template_Vector3->Set(String::New("add"), FunctionTemplate::New(Vector3_Add)->GetFunction());
    // template_Vector3->Set(String::New("sub"), FunctionTemplate::New(Vector3_Sub)->GetFunction());
    // template_Vector3->Set(String::New("mul"), FunctionTemplate::New(Vector3_Mul)->GetFunction());
    // template_Vector3->Set(String::New("divide"), FunctionTemplate::New(Vector3_Divide)->GetFunction());
    // template_Vector3->Set(String::New("negate"), FunctionTemplate::New(Vector3_Negate)->GetFunction());
    // 
    // // Arithmetic updates
    // template_Vector3->Set(String::New("iadd"), FunctionTemplate::New(Vector3_IAdd)->GetFunction());
    // template_Vector3->Set(String::New("isub"), FunctionTemplate::New(Vector3_ISub)->GetFunction());
    // template_Vector3->Set(String::New("imul"), FunctionTemplate::New(Vector3_IMul)->GetFunction());
    // template_Vector3->Set(String::New("idivide"), FunctionTemplate::New(Vector3_IDivide)->GetFunction());
    // template_Vector3->Set(String::New("inegate"), FunctionTemplate::New(Vector3_INegate)->GetFunction());
    // 
    // // Methods
    // template_Vector3->Set(String::New("length"), FunctionTemplate::New(Vector3_Length)->GetFunction());
    // template_Vector3->Set(String::New("squaredLength"), FunctionTemplate::New(Vector3_SquaredLength)->GetFunction());
    // template_Vector3->Set(String::New("isZeroLength"), FunctionTemplate::New(Vector3_IsZeroLength)->GetFunction());
    // template_Vector3->Set(String::New("distance"), FunctionTemplate::New(Vector3_Distance)->GetFunction());
    // template_Vector3->Set(String::New("squaredDistance"), FunctionTemplate::New(Vector3_SquaredDistance)->GetFunction());
    // template_Vector3->Set(String::New("dot"), FunctionTemplate::New(Vector3_DotProduct)->GetFunction());
    // template_Vector3->Set(String::New("absDot"), FunctionTemplate::New(Vector3_AbsDotProduct)->GetFunction());
    // template_Vector3->Set(String::New("normalise"), FunctionTemplate::New(Vector3_Normalise)->GetFunction());
    // template_Vector3->Set(String::New("normalisedCopy"), FunctionTemplate::New(Vector3_NormalisedCopy)->GetFunction());
    // template_Vector3->Set(String::New("cross"), FunctionTemplate::New(Vector3_CrossProduct)->GetFunction());
    // template_Vector3->Set(String::New("midPoint"), FunctionTemplate::New(Vector3_MidPoint)->GetFunction());
    // template_Vector3->Set(String::New("makeFloor"), FunctionTemplate::New(Vector3_MakeFloor)->GetFunction());
    // template_Vector3->Set(String::New("makeCeil"), FunctionTemplate::New(Vector3_MakeCeil)->GetFunction());
    // template_Vector3->Set(String::New("perpendicular"), FunctionTemplate::New(Vector3_Perpendicular)->GetFunction());
    // // MISSING: randomDeviant()
    // // MISSING: angleBetween()
    // // MISSING: getRotationTo()
    // template_Vector3->Set(String::New("reflect"), FunctionTemplate::New(Vector3_Reflect)->GetFunction());
    // template_Vector3->Set(String::New("positionEquals"), FunctionTemplate::New(Vector3_PositionEquals)->GetFunction());
    // template_Vector3->Set(String::New("positionCloses"), FunctionTemplate::New(Vector3_PositionCloses)->GetFunction());
    // // MISSING: directionEquals()
    // template_Vector3->Set(String::New("isNaN"), FunctionTemplate::New(Vector3_IsNaN)->GetFunction());

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

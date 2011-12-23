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


/**************************************** MACROS ***************************************/

#define createJSVector3(v)                                          \
    createJSObject<Vector3>(template_Vector3, Vector3_WeakCallback, \
                            new Vector3(v),                         \
                            sizeof(Vector3), CLASSID_VECTOR3);

#define createJSVector3FromPtr(v)                                   \
    createJSObject<Vector3>(template_Vector3, Vector3_WeakCallback, \
                            v, sizeof(Vector3), CLASSID_VECTOR3);

#define bindMethod(NAME, CALLBACK)                                  \
    template_Vector3->Set(String::New(NAME), FunctionTemplate::New(CALLBACK)->GetFunction());


/*************************************** GLOBALS ***************************************/

Persistent<ObjectTemplate> template_Vector3;


/***************************** CONSTRUCTION / DESTRUCTION ******************************/

// Destructor
void Vector3_WeakCallback(Persistent<Value> value, void* data)
{
    if (value.IsNearDeath())
    {
        Vector3* v = CastJSObject<Vector3>(value, CLASSID_VECTOR3);
        delete v;
    }
}

//-----------------------------------------------------------------------

// Constructor
Handle<Value> Vector3_New(const Arguments& args)
{
    Vector3* v = 0;
    
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
            Vector3* vref = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
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

    return createJSVector3FromPtr(v);
}


/************************************** ATTRIBUTES *************************************/

Handle<Value> Vector3_GetX(Local<String> property, const AccessorInfo &info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder(), CLASSID_VECTOR3);
    if (!v)
        return Handle<Value>();
    
    return Number::New(v->x);
}

//-----------------------------------------------------------------------

void Vector3_SetX(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder(), CLASSID_VECTOR3);
    if (v)
        v->x = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_GetY(Local<String> property, const AccessorInfo &info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder(), CLASSID_VECTOR3);
    if (!v)
        return Handle<Value>();

    return Number::New(v->y);
}

//-----------------------------------------------------------------------

void Vector3_SetY(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder(), CLASSID_VECTOR3);
    if (v)
        v->y = (Real) value->NumberValue();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_GetZ(Local<String> property, const AccessorInfo &info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder(), CLASSID_VECTOR3);
    if (!v)
        return Handle<Value>();

    return Number::New(v->z);
}

//-----------------------------------------------------------------------

void Vector3_SetZ(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
    Vector3* v = CastJSObject<Vector3>(info.Holder(), CLASSID_VECTOR3);
    if (v)
        v->z = (Real) value->NumberValue();
}


/*********************************** VALUE ASSIGNATION **********************************/

Handle<Value> Vector3_Set(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    if (args[0]->IsNumber())
    {
        *self = (Real) args[0]->NumberValue();
    }
    else if (args[0]->IsObject())
    {
        Vector3* vref = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);

        if (vref)
            *self = *vref;
    }
    
    return Handle<Value>();
}


/********************************* COMPARISON OPERATIONS ********************************/

Handle<Value> Vector3_Equals(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rkVector = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rkVector)
        return Handle<Value>();

    return Boolean::New((*self) == (*rkVector));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_NotEquals(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rkVector = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rkVector)
        return Handle<Value>();

    return Boolean::New((*self) != (*rkVector));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_LesserThan(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rkVector = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rkVector)
        return Handle<Value>();

    return Boolean::New((*self) < (*rkVector));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_GreaterThan(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rkVector = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rkVector)
        return Handle<Value>();

    return Boolean::New((*self) > (*rkVector));
}


/********************************* ARITHMETIC OPERATIONS ********************************/

Handle<Value> Vector3_Add(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* result = new Vector3(*self);

    for (unsigned int i = 0; i < args.Length(); ++i)
    {
        if (args[i]->IsNumber())
        {
            (*result) += (Real) args[i]->NumberValue();
        }
        else
        {
            Vector3* v = CastJSObject<Vector3>(args[i], CLASSID_VECTOR3);
            if (!v)
                return Handle<Value>();

            (*result) += *v;
        }
    }

    return createJSVector3FromPtr(result);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Sub(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* result = new Vector3(*self);

    for (unsigned int i = 0; i < args.Length(); ++i)
    {
        if (args[i]->IsNumber())
        {
            (*result) -= (Real) args[i]->NumberValue();
        }
        else
        {
            Vector3* v = CastJSObject<Vector3>(args[i], CLASSID_VECTOR3);
            if (!v)
                return Handle<Value>();

            (*result) -= *v;
        }
    }

    return createJSVector3FromPtr(result);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Mul(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* result = new Vector3(*self);

    for (unsigned int i = 0; i < args.Length(); ++i)
    {
        if (args[i]->IsNumber())
        {
            (*result) *= (Real) args[i]->NumberValue();
        }
        else
        {
            Vector3* v = CastJSObject<Vector3>(args[i], CLASSID_VECTOR3);
            if (!v)
                return Handle<Value>();

            (*result) *= (*v);
        }
    }

    return createJSVector3FromPtr(result);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Divide(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* result = new Vector3(*self);

    for (unsigned int i = 0; i < args.Length(); ++i)
    {
        if (args[i]->IsNumber())
        {
            (*result) /= (Real) args[i]->NumberValue();
        }
        else
        {
            Vector3* v = CastJSObject<Vector3>(args[i], CLASSID_VECTOR3);
            if (!v)
                return Handle<Value>();

            (*result) /= (*v);
        }
    }

    return createJSVector3FromPtr(result);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Negate(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* result = new Vector3(-(*self));

    return createJSVector3FromPtr(result);
}


/********************************** ARITHMETIC UPDATES **********************************/

Handle<Value> Vector3_IAdd(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    for (unsigned int i = 0; i < args.Length(); ++i)
    {
        if (args[i]->IsNumber())
        {
            (*self) += (Real) args[i]->NumberValue();
        }
        else
        {
            Vector3* v = CastJSObject<Vector3>(args[i], CLASSID_VECTOR3);
            if (!v)
                return Handle<Value>();

            (*self) += *v;
        }
    }

    return Handle<Value>();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_ISub(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    for (unsigned int i = 0; i < args.Length(); ++i)
    {
        if (args[i]->IsNumber())
        {
            (*self) -= (Real) args[i]->NumberValue();
        }
        else
        {
            Vector3* v = CastJSObject<Vector3>(args[i], CLASSID_VECTOR3);
            if (!v)
                return Handle<Value>();

            (*self) -= *v;
        }
    }

    return Handle<Value>();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_IMul(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    for (unsigned int i = 0; i < args.Length(); ++i)
    {
        if (args[i]->IsNumber())
        {
            (*self) *= (Real) args[i]->NumberValue();
        }
        else
        {
            Vector3* v = CastJSObject<Vector3>(args[i], CLASSID_VECTOR3);
            if (!v)
                return Handle<Value>();

            (*self) *= (*v);
        }
    }

    return Handle<Value>();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_IDivide(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    for (unsigned int i = 0; i < args.Length(); ++i)
    {
        if (args[i]->IsNumber())
        {
            (*self) /= (Real) args[i]->NumberValue();
        }
        else
        {
            Vector3* v = CastJSObject<Vector3>(args[i], CLASSID_VECTOR3);
            if (!v)
                return Handle<Value>();

            (*self) /= (*v);
        }
    }

    return Handle<Value>();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_INegate(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    (*self) = -(*self);

    return Handle<Value>();
}


/**************************************** METHODS ***************************************/

Handle<Value> Vector3_Length(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    return Number::New(self->length());
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_SquaredLength(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    return Number::New(self->squaredLength());
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_IsZeroLength(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    return Boolean::New(self->isZeroLength());
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Distance(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rhs)
        return Handle<Value>();

    return Number::New(self->distance(*rhs));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_SquaredDistance(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rhs)
        return Handle<Value>();

    return Number::New(self->squaredDistance(*rhs));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_DotProduct(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rhs)
        return Handle<Value>();

    return Number::New(self->dotProduct(*rhs));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_AbsDotProduct(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rhs)
        return Handle<Value>();

    return Number::New(self->absDotProduct(*rhs));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Normalise(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    return Number::New(self->normalise());
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_NormalisedCopy(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    return createJSVector3(self->normalisedCopy());
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_CrossProduct(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rhs)
        return Handle<Value>();

    return createJSVector3(self->crossProduct(*rhs));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_MidPoint(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rhs)
        return Handle<Value>();

    return createJSVector3(self->midPoint(*rhs));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_MakeFloor(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rhs)
        return Handle<Value>();

    self->makeFloor(*rhs);

    return Handle<Value>();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_MakeCeil(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rhs)
        return Handle<Value>();

    self->makeCeil(*rhs);

    return Handle<Value>();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Perpendicular(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    return createJSVector3(self->perpendicular());
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Reflect(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rhs)
        return Handle<Value>();

    return createJSVector3(self->reflect(*rhs));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_PositionEquals(const Arguments& args)
{
    if (args.Length() != 2)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rhs)
        return Handle<Value>();

    if (!args[1]->IsNumber())
        return Handle<Value>();

    return Number::New(self->positionEquals(*rhs, args[1]->ToNumber()->Value()));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_PositionCloses(const Arguments& args)
{
    if (args.Length() != 2)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0], CLASSID_VECTOR3);
    if (!rhs)
        return Handle<Value>();

    if (!args[1]->IsNumber())
        return Handle<Value>();

    return Number::New(self->positionCloses(*rhs, args[1]->ToNumber()->Value()));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_IsNaN(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This(), CLASSID_VECTOR3);
    if (!self)
        return Handle<Value>();

    return Boolean::New(self->isNaN());
}


/**************************************** CONSTANTS *************************************/

Handle<Value> Vector3_ZERO(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(Vector3::ZERO);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_UNIT_X(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(Vector3::UNIT_X);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_UNIT_Y(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(Vector3::UNIT_Y);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_UNIT_Z(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(Vector3::UNIT_Z);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_NEGATIVE_UNIT_X(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(Vector3::NEGATIVE_UNIT_X);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_NEGATIVE_UNIT_Y(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(Vector3::NEGATIVE_UNIT_Y);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_NEGATIVE_UNIT_Z(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(Vector3::NEGATIVE_UNIT_Z);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_UNIT_SCALE(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(Vector3::UNIT_SCALE);
}


/************************************ BINDING FUNCTION **********************************/

bool bind_Vector3(Handle<Object> parent)
{
    // Create the object template
    template_Vector3 = Persistent<ObjectTemplate>::New(ObjectTemplate::New());
    template_Vector3->SetCallAsFunctionHandler(Vector3_New);
    template_Vector3->SetInternalFieldCount(2);

    // Accessors
    template_Vector3->SetAccessor(String::New("x"), Vector3_GetX, Vector3_SetX);
    template_Vector3->SetAccessor(String::New("y"), Vector3_GetY, Vector3_SetY);
    template_Vector3->SetAccessor(String::New("z"), Vector3_GetZ, Vector3_SetZ);

    // Value assignation
    bindMethod("set", Vector3_Set);
    
    // Comparison operations
    bindMethod("equals", Vector3_Equals);
    bindMethod("notEquals", Vector3_NotEquals);
    bindMethod("lesserThan", Vector3_LesserThan);
    bindMethod("greaterThan", Vector3_GreaterThan);

    // Arithmetic operations
    bindMethod("add", Vector3_Add);
    bindMethod("sub", Vector3_Sub);
    bindMethod("mul", Vector3_Mul);
    bindMethod("divide", Vector3_Divide);
    bindMethod("negate", Vector3_Negate);

    // Arithmetic updates
    bindMethod("iadd", Vector3_IAdd);
    bindMethod("isub", Vector3_ISub);
    bindMethod("imul", Vector3_IMul);
    bindMethod("idivide", Vector3_IDivide);
    bindMethod("inegate", Vector3_INegate);

    // Methods
    bindMethod("length", Vector3_Length);
    bindMethod("squaredLength", Vector3_SquaredLength);
    bindMethod("isZeroLength", Vector3_IsZeroLength);
    bindMethod("distance", Vector3_Distance);
    bindMethod("squaredDistance", Vector3_SquaredDistance);
    bindMethod("dot", Vector3_DotProduct);
    bindMethod("absDot", Vector3_AbsDotProduct);
    bindMethod("normalise", Vector3_Normalise);
    bindMethod("normalisedCopy", Vector3_NormalisedCopy);
    bindMethod("cross", Vector3_CrossProduct);
    bindMethod("midPoint", Vector3_MidPoint);
    bindMethod("makeFloor", Vector3_MakeFloor);
    bindMethod("makeCeil", Vector3_MakeCeil);
    bindMethod("perpendicular", Vector3_Perpendicular);
    // MISSING: randomDeviant()
    // MISSING: angleBetween()
    // MISSING: getRotationTo()
    bindMethod("reflect", Vector3_Reflect);
    bindMethod("positionEquals", Vector3_PositionEquals);
    bindMethod("positionCloses", Vector3_PositionCloses);
    // MISSING: directionEquals()
    bindMethod("isNaN", Vector3_IsNaN);

    // Add the class to the parent
    if (!parent->Set(String::New("Vector3"), FunctionTemplate::New(Vector3_New)->GetFunction()))
        return false;
    
    // Constants (can't be members of Vector3)
    return parent->SetAccessor(String::New("Vector3_ZERO"), Vector3_ZERO, 0) &&
           parent->SetAccessor(String::New("Vector3_UNIT_X"), Vector3_UNIT_X, 0) &&
           parent->SetAccessor(String::New("Vector3_UNIT_Y"), Vector3_UNIT_Y, 0) &&
           parent->SetAccessor(String::New("Vector3_UNIT_Z"), Vector3_UNIT_Z, 0) &&
           parent->SetAccessor(String::New("Vector3_NEGATIVE_UNIT_X"), Vector3_NEGATIVE_UNIT_X, 0) &&
           parent->SetAccessor(String::New("Vector3_NEGATIVE_UNIT_Y"), Vector3_NEGATIVE_UNIT_Y, 0) &&
           parent->SetAccessor(String::New("Vector3_NEGATIVE_UNIT_Z"), Vector3_NEGATIVE_UNIT_Z, 0) &&
           parent->SetAccessor(String::New("Vector3_UNIT_SCALE"), Vector3_UNIT_SCALE, 0);
}

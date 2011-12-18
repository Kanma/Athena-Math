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

// Helper function
inline Persistent<Object> createJSVector3(Vector3* v)
{
    Persistent<Object> jsVector = Persistent<Object>::New(template_Vector3->NewInstance());
    jsVector->SetInternalField(0, External::New(v));
    jsVector.MakeWeak(0, Vector3_WeakCallback);
    
    V8::AdjustAmountOfExternalAllocatedMemory(sizeof(Vector3));
    
    return jsVector;
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

    return createJSVector3(v);
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


/*********************************** VALUE ASSIGNATION **********************************/

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


/********************************* COMPARISON OPERATIONS ********************************/

Handle<Value> Vector3_Equals(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rkVector = CastJSObject<Vector3>(args[0]);
    if (!rkVector)
        return Handle<Value>();

    return Boolean::New((*self) == (*rkVector));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_NotEquals(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rkVector = CastJSObject<Vector3>(args[0]);
    if (!rkVector)
        return Handle<Value>();

    return Boolean::New((*self) != (*rkVector));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_LesserThan(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rkVector = CastJSObject<Vector3>(args[0]);
    if (!rkVector)
        return Handle<Value>();

    return Boolean::New((*self) < (*rkVector));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_GreaterThan(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rkVector = CastJSObject<Vector3>(args[0]);
    if (!rkVector)
        return Handle<Value>();

    return Boolean::New((*self) > (*rkVector));
}


/********************************* ARITHMETIC OPERATIONS ********************************/

Handle<Value> Vector3_Add(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
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
            Vector3* v = CastJSObject<Vector3>(args[i]);
            if (!v)
                return Handle<Value>();

            (*result) += *v;
        }
    }

    return createJSVector3(result);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Sub(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
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
            Vector3* v = CastJSObject<Vector3>(args[i]);
            if (!v)
                return Handle<Value>();

            (*result) -= *v;
        }
    }

    return createJSVector3(result);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Mul(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
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
            Vector3* v = CastJSObject<Vector3>(args[i]);
            if (!v)
                return Handle<Value>();

            (*result) *= (*v);
        }
    }

    return createJSVector3(result);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Divide(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
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
            Vector3* v = CastJSObject<Vector3>(args[i]);
            if (!v)
                return Handle<Value>();

            (*result) /= (*v);
        }
    }

    return createJSVector3(result);
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Negate(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* result = new Vector3(-(*self));

    return createJSVector3(result);
}


/********************************** ARITHMETIC UPDATES **********************************/

Handle<Value> Vector3_IAdd(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
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
            Vector3* v = CastJSObject<Vector3>(args[i]);
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
    Vector3* self = CastJSObject<Vector3>(args.This());
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
            Vector3* v = CastJSObject<Vector3>(args[i]);
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
    Vector3* self = CastJSObject<Vector3>(args.This());
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
            Vector3* v = CastJSObject<Vector3>(args[i]);
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
    Vector3* self = CastJSObject<Vector3>(args.This());
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
            Vector3* v = CastJSObject<Vector3>(args[i]);
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
    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    (*self) = -(*self);

    return Handle<Value>();
}


/**************************************** METHODS ***************************************/

Handle<Value> Vector3_Length(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    return Number::New(self->length());
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_SquaredLength(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    return Number::New(self->squaredLength());
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_IsZeroLength(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    return Boolean::New(self->isZeroLength());
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Distance(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0]);
    if (!rhs)
        return Handle<Value>();

    return Number::New(self->distance(*rhs));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_SquaredDistance(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0]);
    if (!rhs)
        return Handle<Value>();

    return Number::New(self->squaredDistance(*rhs));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_DotProduct(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0]);
    if (!rhs)
        return Handle<Value>();

    return Number::New(self->dotProduct(*rhs));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_AbsDotProduct(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0]);
    if (!rhs)
        return Handle<Value>();

    return Number::New(self->absDotProduct(*rhs));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Normalise(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    return Number::New(self->normalise());
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_NormalisedCopy(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    return createJSVector3(new Vector3(self->normalisedCopy()));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_CrossProduct(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0]);
    if (!rhs)
        return Handle<Value>();

    return createJSVector3(new Vector3(self->crossProduct(*rhs)));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_MidPoint(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0]);
    if (!rhs)
        return Handle<Value>();

    return createJSVector3(new Vector3(self->midPoint(*rhs)));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_MakeFloor(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0]);
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

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0]);
    if (!rhs)
        return Handle<Value>();

    self->makeCeil(*rhs);

    return Handle<Value>();
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Perpendicular(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    return createJSVector3(new Vector3(self->perpendicular()));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_Reflect(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0]);
    if (!rhs)
        return Handle<Value>();

    return createJSVector3(new Vector3(self->reflect(*rhs)));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_PositionEquals(const Arguments& args)
{
    if (args.Length() != 2)
        return Handle<Value>();

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0]);
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

    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    Vector3* rhs = CastJSObject<Vector3>(args[0]);
    if (!rhs)
        return Handle<Value>();

    if (!args[1]->IsNumber())
        return Handle<Value>();

    return Number::New(self->positionCloses(*rhs, args[1]->ToNumber()->Value()));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_IsNaN(const Arguments& args)
{
    Vector3* self = CastJSObject<Vector3>(args.This());
    if (!self)
        return Handle<Value>();

    return Boolean::New(self->isNaN());
}


/**************************************** CONSTANTS *************************************/

Handle<Value> Vector3_ZERO(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(new Vector3(Vector3::ZERO));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_UNIT_X(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(new Vector3(Vector3::UNIT_X));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_UNIT_Y(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(new Vector3(Vector3::UNIT_Y));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_UNIT_Z(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(new Vector3(Vector3::UNIT_Z));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_NEGATIVE_UNIT_X(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(new Vector3(Vector3::NEGATIVE_UNIT_X));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_NEGATIVE_UNIT_Y(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(new Vector3(Vector3::NEGATIVE_UNIT_Y));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_NEGATIVE_UNIT_Z(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(new Vector3(Vector3::NEGATIVE_UNIT_Z));
}

//-----------------------------------------------------------------------

Handle<Value> Vector3_UNIT_SCALE(Local<String> property, const AccessorInfo &info)
{
    return createJSVector3(new Vector3(Vector3::UNIT_SCALE));
}


/************************************ BINDING FUNCTION **********************************/

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

    // Value assignation
    template_Vector3->Set(String::New("set"), FunctionTemplate::New(Vector3_Set)->GetFunction());
    
    // Comparison operations
    template_Vector3->Set(String::New("equals"), FunctionTemplate::New(Vector3_Equals)->GetFunction());
    template_Vector3->Set(String::New("notEquals"), FunctionTemplate::New(Vector3_NotEquals)->GetFunction());
    template_Vector3->Set(String::New("lesserThan"), FunctionTemplate::New(Vector3_LesserThan)->GetFunction());
    template_Vector3->Set(String::New("greaterThan"), FunctionTemplate::New(Vector3_GreaterThan)->GetFunction());

    // Arithmetic operations
    template_Vector3->Set(String::New("add"), FunctionTemplate::New(Vector3_Add)->GetFunction());
    template_Vector3->Set(String::New("sub"), FunctionTemplate::New(Vector3_Sub)->GetFunction());
    template_Vector3->Set(String::New("mul"), FunctionTemplate::New(Vector3_Mul)->GetFunction());
    template_Vector3->Set(String::New("divide"), FunctionTemplate::New(Vector3_Divide)->GetFunction());
    template_Vector3->Set(String::New("negate"), FunctionTemplate::New(Vector3_Negate)->GetFunction());

    // Arithmetic updates
    template_Vector3->Set(String::New("iadd"), FunctionTemplate::New(Vector3_IAdd)->GetFunction());
    template_Vector3->Set(String::New("isub"), FunctionTemplate::New(Vector3_ISub)->GetFunction());
    template_Vector3->Set(String::New("imul"), FunctionTemplate::New(Vector3_IMul)->GetFunction());
    template_Vector3->Set(String::New("idivide"), FunctionTemplate::New(Vector3_IDivide)->GetFunction());
    template_Vector3->Set(String::New("inegate"), FunctionTemplate::New(Vector3_INegate)->GetFunction());

    // Methods
    template_Vector3->Set(String::New("length"), FunctionTemplate::New(Vector3_Length)->GetFunction());
    template_Vector3->Set(String::New("squaredLength"), FunctionTemplate::New(Vector3_SquaredLength)->GetFunction());
    template_Vector3->Set(String::New("isZeroLength"), FunctionTemplate::New(Vector3_IsZeroLength)->GetFunction());
    template_Vector3->Set(String::New("distance"), FunctionTemplate::New(Vector3_Distance)->GetFunction());
    template_Vector3->Set(String::New("squaredDistance"), FunctionTemplate::New(Vector3_SquaredDistance)->GetFunction());
    template_Vector3->Set(String::New("dot"), FunctionTemplate::New(Vector3_DotProduct)->GetFunction());
    template_Vector3->Set(String::New("absDot"), FunctionTemplate::New(Vector3_AbsDotProduct)->GetFunction());
    template_Vector3->Set(String::New("normalise"), FunctionTemplate::New(Vector3_Normalise)->GetFunction());
    template_Vector3->Set(String::New("normalisedCopy"), FunctionTemplate::New(Vector3_NormalisedCopy)->GetFunction());
    template_Vector3->Set(String::New("cross"), FunctionTemplate::New(Vector3_CrossProduct)->GetFunction());
    template_Vector3->Set(String::New("midPoint"), FunctionTemplate::New(Vector3_MidPoint)->GetFunction());
    template_Vector3->Set(String::New("makeFloor"), FunctionTemplate::New(Vector3_MakeFloor)->GetFunction());
    template_Vector3->Set(String::New("makeCeil"), FunctionTemplate::New(Vector3_MakeCeil)->GetFunction());
    template_Vector3->Set(String::New("perpendicular"), FunctionTemplate::New(Vector3_Perpendicular)->GetFunction());
    // MISSING: randomDeviant()
    // MISSING: angleBetween()
    // MISSING: getRotationTo()
    template_Vector3->Set(String::New("reflect"), FunctionTemplate::New(Vector3_Reflect)->GetFunction());
    template_Vector3->Set(String::New("positionEquals"), FunctionTemplate::New(Vector3_PositionEquals)->GetFunction());
    template_Vector3->Set(String::New("positionCloses"), FunctionTemplate::New(Vector3_PositionCloses)->GetFunction());
    // MISSING: directionEquals()
    template_Vector3->Set(String::New("isNaN"), FunctionTemplate::New(Vector3_IsNaN)->GetFunction());

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

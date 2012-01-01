/** @file   MathUtils.cpp
    @author Philip Abbet
    
    Javascript binding of the class Athena::Math::MathUtils
*/

#include <Athena-Math/MathUtils.h>
#include <Athena-Scripting/Utils.h>
#include <v8.h>

using namespace Athena::Math;
using namespace Athena::Scripting;
using namespace v8;


/*********************************** INTEGER OPERATIONS *********************************/

Handle<Value> MathUtils_IAbs(const Arguments& args)
{
    if (args.Length() != 1)
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    if (!args[0]->IsNumber())
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    return Integer::New(MathUtils::IAbs(args[0]->IntegerValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_ICeil(const Arguments& args)
{
    if (args.Length() != 1)
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    if (!args[0]->IsNumber())
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    return Integer::New(MathUtils::ICeil(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_IFloor(const Arguments& args)
{
    if (args.Length() != 1)
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    if (!args[0]->IsNumber())
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    return Integer::New(MathUtils::IFloor(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_ISign(const Arguments& args)
{
    if (args.Length() != 1)
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    if (!args[0]->IsNumber())
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    return Integer::New(MathUtils::ISign(args[0]->IntegerValue()));
}


/******************************* FLOATING-POINT OPERATIONS ******************************/

Handle<Value> MathUtils_Sign(const Arguments& args)
{
    if (args.Length() != 1)
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    if (!args[0]->IsNumber())
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    return Number::New(MathUtils::Sign(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Log2(const Arguments& args)
{
    if (args.Length() != 1)
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    if (!args[0]->IsNumber())
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    return Number::New(MathUtils::Log2(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_LogN(const Arguments& args)
{
    if (args.Length() != 2)
        return ThrowException(String::New("Invalid parameters, expected two Numbers"));

    if (!args[0]->IsNumber() || !args[1]->IsNumber())
        return ThrowException(String::New("Invalid parameters, expected two Numbers"));

    return Number::New(MathUtils::LogN(args[0]->NumberValue(), args[1]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Sqr(const Arguments& args)
{
    if (args.Length() != 1)
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    if (!args[0]->IsNumber())
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    return Number::New(MathUtils::Sqr(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_InvSqrt(const Arguments& args)
{
    if (args.Length() != 1)
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    if (!args[0]->IsNumber())
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    return Number::New(MathUtils::InvSqrt(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Equals(const Arguments& args)
{
    if ((args.Length() != 2) && (args.Length() != 3))
        return ThrowException(String::New("Invalid parameters, expected two or three Numbers"));

    if (!args[0]->IsNumber() || !args[1]->IsNumber())
        return ThrowException(String::New("Invalid parameters, expected two or three Numbers"));

    if (args.Length() == 3)
    {
        if (!args[2]->IsNumber())
            return ThrowException(String::New("Invalid parameters, expected two or three Numbers"));

        return Number::New(MathUtils::RealEqual(args[0]->NumberValue(),
                                                args[1]->NumberValue(),
                                                args[2]->NumberValue()));
    }
    
    return Number::New(MathUtils::RealEqual(args[0]->NumberValue(), args[1]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Clamp(const Arguments& args)
{
    if (args.Length() != 3)
        return ThrowException(String::New("Invalid parameters, expected three Numbers"));

    if (args[0]->IsInt32() && args[1]->IsInt32() && args[2]->IsInt32())
    {
        return Integer::New(MathUtils::Clamp<int>(args[0]->IntegerValue(),
                                                  args[1]->IntegerValue(),
                                                  args[2]->IntegerValue()));
    }
    else if (args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsNumber())
    {
        return Number::New(MathUtils::Clamp<Real>(args[0]->NumberValue(),
                                                  args[1]->NumberValue(),
                                                  args[2]->NumberValue()));
    }

    return ThrowException(String::New("Invalid parameters, expected three Numbers"));
}


/******************************** RANDOM NUMBERS GENERATION *****************************/

Handle<Value> MathUtils_UnitRandom(const Arguments& args)
{
    return Number::New(MathUtils::UnitRandom());
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_RangeRandom(const Arguments& args)
{
    if (args.Length() != 2)
        return ThrowException(String::New("Invalid parameters, expected two Numbers"));

    if (!args[0]->IsNumber() || !args[1]->IsNumber())
        return ThrowException(String::New("Invalid parameters, expected two Numbers"));

    return Number::New(MathUtils::RangeRandom(args[0]->NumberValue(), args[1]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_SymmetricRandom(const Arguments& args)
{
    return Number::New(MathUtils::SymmetricRandom());
}


/************************************* UNIT CONVERSION **********************************/

Handle<Value> MathUtils_DegreesToRadians(const Arguments& args)
{
    if (args.Length() != 1)
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    if (!args[0]->IsNumber())
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    return Number::New(MathUtils::DegreesToRadians(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_RadiansToDegrees(const Arguments& args)
{
    if (args.Length() != 1)
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    if (!args[0]->IsNumber())
        return ThrowException(String::New("Invalid parameter, expected one Number"));

    return Number::New(MathUtils::RadiansToDegrees(args[0]->NumberValue()));
}


/**************************************** CONSTANTS *************************************/

Handle<Value> MathUtils_DEGREES_TO_RADIANS(Local<String> property, const AccessorInfo &info)
{
    return Number::New(MathUtils::DEGREES_TO_RADIANS);
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_RADIANS_TO_DEGREES(Local<String> property, const AccessorInfo &info)
{
    return Number::New(MathUtils::RADIANS_TO_DEGREES);
}


/************************************ BINDING FUNCTION **********************************/

bool bind_functions(Handle<Object> parent)
{
    // Integer operations
    return parent->Set(String::New("iabs"), FunctionTemplate::New(MathUtils_IAbs)->GetFunction()) &&
           parent->Set(String::New("iceil"), FunctionTemplate::New(MathUtils_ICeil)->GetFunction()) &&
           parent->Set(String::New("ifloor"), FunctionTemplate::New(MathUtils_IFloor)->GetFunction()) &&
           parent->Set(String::New("isign"), FunctionTemplate::New(MathUtils_ISign)->GetFunction()) &&

    // Floating-point operations
           parent->Set(String::New("sign"), FunctionTemplate::New(MathUtils_Sign)->GetFunction()) &&
           parent->Set(String::New("log2"), FunctionTemplate::New(MathUtils_Log2)->GetFunction()) &&
           parent->Set(String::New("logn"), FunctionTemplate::New(MathUtils_LogN)->GetFunction()) &&
           parent->Set(String::New("sqr"), FunctionTemplate::New(MathUtils_Sqr)->GetFunction()) &&
           parent->Set(String::New("invsqrt"), FunctionTemplate::New(MathUtils_InvSqrt)->GetFunction()) &&
           parent->Set(String::New("equals"), FunctionTemplate::New(MathUtils_Equals)->GetFunction()) &&
           parent->Set(String::New("clamp"), FunctionTemplate::New(MathUtils_Clamp)->GetFunction()) &&

    // Random numbers generation
           parent->Set(String::New("unitRandom"), FunctionTemplate::New(MathUtils_UnitRandom)->GetFunction()) &&
           parent->Set(String::New("rangeRandom"), FunctionTemplate::New(MathUtils_RangeRandom)->GetFunction()) &&
           parent->Set(String::New("symmetricRandom"), FunctionTemplate::New(MathUtils_SymmetricRandom)->GetFunction()) &&

    // Unit conversion
           parent->Set(String::New("degToRad"), FunctionTemplate::New(MathUtils_DegreesToRadians)->GetFunction()) &&
           parent->Set(String::New("radToDeg"), FunctionTemplate::New(MathUtils_RadiansToDegrees)->GetFunction());
}


bool bind_constants(Handle<Object> parent)
{
    return parent->SetAccessor(String::New("DEGREES_TO_RADIANS"), MathUtils_DEGREES_TO_RADIANS, 0) &&
           parent->SetAccessor(String::New("RADIANS_TO_DEGREES"), MathUtils_RADIANS_TO_DEGREES, 0);
}


bool bind_MathUtils(Handle<Object> parent)
{
    return bind_functions(parent) &&
           bind_constants(parent);
}

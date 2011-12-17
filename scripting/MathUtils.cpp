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
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Integer::New(MathUtils::IAbs(args[0]->IntegerValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_ICeil(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Integer::New(MathUtils::ICeil(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_IFloor(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Integer::New(MathUtils::IFloor(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_ISign(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Integer::New(MathUtils::ISign(args[0]->IntegerValue()));
}


/******************************* FLOATING-POINT OPERATIONS ******************************/

Handle<Value> MathUtils_Abs(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Abs(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Ceil(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Ceil(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Floor(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Floor(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Sign(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Sign(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Exp(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Exp(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Log(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Log(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Log2(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Log2(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_LogN(const Arguments& args)
{
    if (args.Length() != 2)
        return Handle<Value>();

    if (!args[0]->IsNumber() || !args[1]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::LogN(args[0]->NumberValue(), args[1]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Pow(const Arguments& args)
{
    if (args.Length() != 2)
        return Handle<Value>();

    if (!args[0]->IsNumber() || !args[1]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Pow(args[0]->NumberValue(), args[1]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Sqr(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Sqr(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Sqrt(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Sqrt(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_InvSqrt(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::InvSqrt(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Equals(const Arguments& args)
{
    if ((args.Length() != 2) && (args.Length() != 3))
        return Handle<Value>();

    if (!args[0]->IsNumber() || !args[1]->IsNumber())
        return Handle<Value>();

    if (args.Length() == 3)
    {
        if (!args[2]->IsNumber())
            return Handle<Value>();

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
        return Handle<Value>();

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

    return Handle<Value>();
}


/******************************** TRIGONOMETRIC OPERATIONS ******************************/

Handle<Value> MathUtils_ACos(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::ACos(args[0]->NumberValue()).valueRadians());
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_ASin(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::ASin(args[0]->NumberValue()).valueRadians());
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_ATan(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::ATan(args[0]->NumberValue()).valueRadians());
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_ATan2(const Arguments& args)
{
    if (args.Length() != 2)
        return Handle<Value>();

    if (!args[0]->IsNumber() || !args[1]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::ATan2(args[0]->NumberValue(), args[1]->NumberValue()).valueRadians());
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Cos(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Cos(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Sin(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Sin(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_Tan(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::Tan(args[0]->NumberValue()));
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
        return Handle<Value>();

    if (!args[0]->IsNumber() || !args[1]->IsNumber())
        return Handle<Value>();

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
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::DegreesToRadians(args[0]->NumberValue()));
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_RadiansToDegrees(const Arguments& args)
{
    if (args.Length() != 1)
        return Handle<Value>();

    if (!args[0]->IsNumber())
        return Handle<Value>();

    return Number::New(MathUtils::RadiansToDegrees(args[0]->NumberValue()));
}


/**************************************** CONSTANTS *************************************/

Handle<Value> MathUtils_LOG2(Local<String> property, const AccessorInfo &info)
{
    return Number::New(MathUtils::LOG2);
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_POS_INFINITY(Local<String> property, const AccessorInfo &info)
{
    return Number::New(MathUtils::POS_INFINITY);
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_NEG_INFINITY(Local<String> property, const AccessorInfo &info)
{
    return Number::New(MathUtils::NEG_INFINITY);
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_PI(Local<String> property, const AccessorInfo &info)
{
    return Number::New(MathUtils::PI);
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_TWO_PI(Local<String> property, const AccessorInfo &info)
{
    return Number::New(MathUtils::TWO_PI);
}

//-----------------------------------------------------------------------

Handle<Value> MathUtils_HALF_PI(Local<String> property, const AccessorInfo &info)
{
    return Number::New(MathUtils::HALF_PI);
}

//-----------------------------------------------------------------------

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
           parent->Set(String::New("abs"), FunctionTemplate::New(MathUtils_Abs)->GetFunction()) &&
           parent->Set(String::New("ceil"), FunctionTemplate::New(MathUtils_Ceil)->GetFunction()) &&
           parent->Set(String::New("floor"), FunctionTemplate::New(MathUtils_Floor)->GetFunction()) &&
           parent->Set(String::New("sign"), FunctionTemplate::New(MathUtils_Sign)->GetFunction()) &&
           parent->Set(String::New("exp"), FunctionTemplate::New(MathUtils_Exp)->GetFunction()) &&
           parent->Set(String::New("log"), FunctionTemplate::New(MathUtils_Log)->GetFunction()) &&
           parent->Set(String::New("log2"), FunctionTemplate::New(MathUtils_Log2)->GetFunction()) &&
           parent->Set(String::New("logn"), FunctionTemplate::New(MathUtils_LogN)->GetFunction()) &&
           parent->Set(String::New("pow"), FunctionTemplate::New(MathUtils_Pow)->GetFunction()) &&
           parent->Set(String::New("sqr"), FunctionTemplate::New(MathUtils_Sqr)->GetFunction()) &&
           parent->Set(String::New("sqrt"), FunctionTemplate::New(MathUtils_Sqrt)->GetFunction()) &&
           parent->Set(String::New("invsqrt"), FunctionTemplate::New(MathUtils_InvSqrt)->GetFunction()) &&
           parent->Set(String::New("equals"), FunctionTemplate::New(MathUtils_Equals)->GetFunction()) &&
           parent->Set(String::New("clamp"), FunctionTemplate::New(MathUtils_Clamp)->GetFunction()) &&

    // Trigonometric operations
           parent->Set(String::New("acos"), FunctionTemplate::New(MathUtils_ACos)->GetFunction()) &&
           parent->Set(String::New("asin"), FunctionTemplate::New(MathUtils_ASin)->GetFunction()) &&
           parent->Set(String::New("atan"), FunctionTemplate::New(MathUtils_ATan)->GetFunction()) &&
           parent->Set(String::New("atan2"), FunctionTemplate::New(MathUtils_ATan2)->GetFunction()) &&
           parent->Set(String::New("cos"), FunctionTemplate::New(MathUtils_Cos)->GetFunction()) &&
           parent->Set(String::New("sin"), FunctionTemplate::New(MathUtils_Sin)->GetFunction()) &&
           parent->Set(String::New("tan"), FunctionTemplate::New(MathUtils_Tan)->GetFunction()) &&

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
    return parent->SetAccessor(String::New("LOG2"), MathUtils_LOG2, 0) &&
           parent->SetAccessor(String::New("POS_INFINITY"), MathUtils_POS_INFINITY, 0) &&
           parent->SetAccessor(String::New("NEG_INFINITY"), MathUtils_NEG_INFINITY, 0) &&
           parent->SetAccessor(String::New("PI"), MathUtils_PI, 0) &&
           parent->SetAccessor(String::New("TWO_PI"), MathUtils_TWO_PI, 0) &&
           parent->SetAccessor(String::New("HALF_PI"), MathUtils_HALF_PI, 0) &&
           parent->SetAccessor(String::New("DEGREES_TO_RADIANS"), MathUtils_DEGREES_TO_RADIANS, 0) &&
           parent->SetAccessor(String::New("RADIANS_TO_DEGREES"), MathUtils_RADIANS_TO_DEGREES, 0);
}


bool bind_MathUtils(Handle<Object> parent)
{
    return bind_functions(parent) &&
           bind_constants(parent);
}

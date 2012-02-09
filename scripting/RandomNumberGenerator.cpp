/** @file   RandomNumberGenerator.cpp
    @author Philip Abbet
    
    Javascript binding of the class Athena::Math::RandomNumberGenerator
*/

#include <Athena-Math/RandomNumberGenerator.h>
#include <Athena-Math/Scripting.h>
#include <Athena-Scripting/Utils.h>
#include <v8.h>

using namespace Athena::Math;
using namespace Athena::Scripting;
using namespace v8;


/**************************************** MACROS ***************************************/

#define createJSRandomNumberGeneratorFromPtr(rng)                                   \
    createJSObject<RandomNumberGenerator>(template_RandomNumberGenerator, RandomNumberGenerator_WeakCallback, \
                                          rng, sizeof(RandomNumberGenerator), CLASSID_RANDOM_NUMBER_GENERATOR);

#define bindMethod(NAME, CALLBACK)                                  \
    template_RandomNumberGenerator->Set(String::New(NAME), FunctionTemplate::New(CALLBACK)->GetFunction());


/*************************************** GLOBALS ***************************************/

Persistent<ObjectTemplate> template_RandomNumberGenerator;


/***************************** CONSTRUCTION / DESTRUCTION ******************************/

// Destructor
void RandomNumberGenerator_WeakCallback(Persistent<Value> value, void* data)
{
    if (value.IsNearDeath())
    {
        RandomNumberGenerator* rng = CastJSObject<RandomNumberGenerator>(value, CLASSID_RANDOM_NUMBER_GENERATOR);
        delete rng;
    }
}

//-----------------------------------------------------------------------

// Constructor
Handle<Value> RandomNumberGenerator_New(const Arguments& args)
{
    return createJSRandomNumberGeneratorFromPtr(new RandomNumberGenerator());
}


/**************************************** METHODS ***************************************/

Handle<Value> RandomNumberGenerator_SetSeed(const Arguments& args)
{
    if ((args.Length() != 1) || !args[0]->IsUint32())
        return ThrowException(String::New("Invalid parameter, expected an unsigned integer"));

    RandomNumberGenerator* self = CastJSObject<RandomNumberGenerator>(args.This(), CLASSID_RANDOM_NUMBER_GENERATOR);
    if (!self)
        return ThrowException(String::New("'this' isn't a RandomNumberGenerator"));

    self->setSeed(args[0]->Uint32Value());
    
    return Handle<Value>();
}

//-----------------------------------------------------------------------

Handle<Value> RandomNumberGenerator_Reset(const Arguments& args)
{
    RandomNumberGenerator* self = CastJSObject<RandomNumberGenerator>(args.This(), CLASSID_RANDOM_NUMBER_GENERATOR);
    if (!self)
        return ThrowException(String::New("'this' isn't a RandomNumberGenerator"));

    self->reset();
    
    return Handle<Value>();
}

//-----------------------------------------------------------------------

Handle<Value> RandomNumberGenerator_RandomizeInt(const Arguments& args)
{
    RandomNumberGenerator* self = CastJSObject<RandomNumberGenerator>(args.This(), CLASSID_RANDOM_NUMBER_GENERATOR);
    if (!self)
        return ThrowException(String::New("'this' isn't a RandomNumberGenerator"));

    if (args.Length() == 0)
    {
        return Uint32::New(self->randomize());
    }
    else if (args.Length() == 1)
    {
        if (args[0]->IsUint32())
            return Uint32::New(self->randomize(args[0]->Uint32Value()));
        else if (args[0]->IsInt32())
            return Int32::New(self->randomize(args[0]->Int32Value()));
    }
    else if (args.Length() == 2)
    {
        if (args[0]->IsUint32() && args[1]->IsUint32())
            return Uint32::New(self->randomize(args[0]->Uint32Value(), args[1]->Uint32Value()));
        else if (args[0]->IsInt32())
            return Int32::New(self->randomize(args[0]->Int32Value(), args[1]->Int32Value()));
    }

    return ThrowException(String::New("Invalid parameters, syntax: randomizeInt(), randomizeInt(max) or randomizeInt(min, max)"));
}

//-----------------------------------------------------------------------

Handle<Value> RandomNumberGenerator_Randomize(const Arguments& args)
{
    RandomNumberGenerator* self = CastJSObject<RandomNumberGenerator>(args.This(), CLASSID_RANDOM_NUMBER_GENERATOR);
    if (!self)
        return ThrowException(String::New("'this' isn't a RandomNumberGenerator"));

    if (args.Length() == 0)
    {
        return Uint32::New(self->randomize());
    }
    else if (args.Length() == 1)
    {
        if (args[0]->IsNumber())
            return Number::New(self->randomize((Real) args[0]->NumberValue()));
    }
    else if (args.Length() == 2)
    {
        if (args[0]->IsNumber() && args[1]->IsNumber())
            return Number::New(self->randomize((Real) args[0]->NumberValue(), (Real) args[1]->NumberValue()));
    }

    return ThrowException(String::New("Invalid parameters, syntax: randomizeInt(), randomizeInt(max) or randomizeInt(min, max)"));
}


/************************************ BINDING FUNCTION **********************************/

bool bind_RandomNumberGenerator(Handle<Object> parent)
{
    // Create the object template
    template_RandomNumberGenerator = Persistent<ObjectTemplate>::New(ObjectTemplate::New());
    template_RandomNumberGenerator->SetCallAsFunctionHandler(RandomNumberGenerator_New);
    template_RandomNumberGenerator->SetInternalFieldCount(2);

    // Methods
    bindMethod("setSeed",      RandomNumberGenerator_SetSeed);
    bindMethod("reset",        RandomNumberGenerator_Reset);
    bindMethod("randomize",    RandomNumberGenerator_Randomize);
    bindMethod("randomizeInt", RandomNumberGenerator_RandomizeInt);

    // Add the class to the parent
    return parent->Set(String::New("RandomNumberGenerator"), FunctionTemplate::New(RandomNumberGenerator_New)->GetFunction());
}

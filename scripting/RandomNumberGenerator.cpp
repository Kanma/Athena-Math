/** @file   RandomNumberGenerator.cpp
    @author Philip Abbet
    
    Javascript binding of the class Athena::Math::RandomNumberGenerator
*/

#include <Athena-Math/RandomNumberGenerator.h>
#include <Athena-Math/Scripting.h>
#include <Athena-Scripting/ScriptingManager.h>
#include <Athena-Scripting/Utils.h>
#include <v8.h>

using namespace Athena::Math;
using namespace Athena::Scripting;
using namespace v8;


/**************************************** MACROS ***************************************/

#define GetObjectPtr(HANDLE) GetObjectPtr<RandomNumberGenerator>(HANDLE)

#define bindMethod(NAME, CALLBACK)                                  \
    template_RandomNumberGenerator->Set(String::New(NAME), FunctionTemplate::New(CALLBACK)->GetFunction());


/*************************************** GLOBALS ***************************************/

Persistent<FunctionTemplate> function_RandomNumberGenerator;


/***************************** CONSTRUCTION / DESTRUCTION ******************************/

// Constructor
Handle<Value> RandomNumberGenerator_New(const Arguments& args)
{
    return SetObjectPtr(args.This(), new RandomNumberGenerator());
}


/**************************************** METHODS ***************************************/

Handle<Value> RandomNumberGenerator_SetSeed(const Arguments& args)
{
    if ((args.Length() != 1) || !args[0]->IsUint32())
        return ThrowException(String::New("Invalid parameter, expected an unsigned integer"));

    RandomNumberGenerator* self = GetObjectPtr(args.This());
    assert(self);

    self->setSeed(args[0]->Uint32Value());
    
    return Handle<Value>();
}

//-----------------------------------------------------------------------

Handle<Value> RandomNumberGenerator_Reset(const Arguments& args)
{
    RandomNumberGenerator* self = GetObjectPtr(args.This());
    assert(self);

    self->reset();
    
    return Handle<Value>();
}

//-----------------------------------------------------------------------

Handle<Value> RandomNumberGenerator_RandomizeInt(const Arguments& args)
{
    RandomNumberGenerator* self = GetObjectPtr(args.This());
    assert(self);

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
    RandomNumberGenerator* self = GetObjectPtr(args.This());
    assert(self);

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
    if (function_RandomNumberGenerator.IsEmpty())
    {
        // Create the object template
        function_RandomNumberGenerator = Persistent<FunctionTemplate>::New(
                                                FunctionTemplate::New(RandomNumberGenerator_New));

        function_RandomNumberGenerator->InstanceTemplate()->SetInternalFieldCount(1);

        // Methods
        Local<ObjectTemplate> template_RandomNumberGenerator =
                function_RandomNumberGenerator->PrototypeTemplate();

        bindMethod("setSeed",      RandomNumberGenerator_SetSeed);
        bindMethod("reset",        RandomNumberGenerator_Reset);
        bindMethod("randomize",    RandomNumberGenerator_Randomize);
        bindMethod("randomizeInt", RandomNumberGenerator_RandomizeInt);

        // Register the class with the Scripting Manager
        ScriptingManager::getSingletonPtr()->declareClassTemplate("Athena.Math.RandomNumberGenerator",
                                                                  function_RandomNumberGenerator);
    }

    // Add the class to the parent
    return parent->Set(String::New("RandomNumberGenerator"), function_RandomNumberGenerator->GetFunction());
}

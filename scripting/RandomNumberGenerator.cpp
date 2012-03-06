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
    ScriptingManager* pManager = ScriptingManager::getSingletonPtr();

    Handle<FunctionTemplate> rng = pManager->getClassTemplate("Athena.Math.RandomNumberGenerator");

    if (rng.IsEmpty())
    {
        // Declaration of the class
        rng = FunctionTemplate::New(RandomNumberGenerator_New);
        rng->InstanceTemplate()->SetInternalFieldCount(1);

        // Methods
        AddMethod(rng, "setSeed",      RandomNumberGenerator_SetSeed);
        AddMethod(rng, "reset",        RandomNumberGenerator_Reset);
        AddMethod(rng, "randomize",    RandomNumberGenerator_Randomize);
        AddMethod(rng, "randomizeInt", RandomNumberGenerator_RandomizeInt);

        // Register the class with the Scripting Manager
        pManager->declareClassTemplate("Athena.Math.RandomNumberGenerator", rng);
    }

    // Add the class to the parent
    return parent->Set(String::New("RandomNumberGenerator"), rng->GetFunction());
}

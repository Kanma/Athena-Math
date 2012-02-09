/** @file   module.cpp
    @author Philip Abbet

    Entry point of the Javascript module of Athena::Math
*/

#include <v8.h>
#include <Athena-Scripting/ScriptingManager.h>
#include <string>

using namespace v8;
using namespace Athena::Scripting;


/*********************************** EXTERNAL FUNCTIONS *********************************/

extern bool bind_RandomNumberGenerator(Handle<Object> parent);


/*************************************** FUNCTIONS *************************************/

bool load_js_file(const std::string& fileName, Handle<Object> parent, const std::string& modulePath)
{
    Handle<Value> result = ScriptingManager::getSingletonPtr()->executeFile(
                                        modulePath + "js/Math/" + fileName + ".js",
                                        Context::GetCurrent());
    return !result.IsEmpty();
}


/****************************** INITIALISATION OF THE MODULE ****************************/

extern "C" {

    bool init_module(Handle<Object> parent, const std::string& modulePath)
    {
        HandleScope handle_scope;

        parent->Set(String::New("VERSION"), String::New(Athena::Math::VERSION));

        return load_js_file("Color", parent, modulePath) &&
               load_js_file("MathUtils", parent, modulePath) &&
               load_js_file("Matrix3", parent, modulePath) &&
               load_js_file("Matrix4", parent, modulePath) &&
               load_js_file("Plane", parent, modulePath) &&
               load_js_file("Quaternion", parent, modulePath) &&
               load_js_file("Sphere", parent, modulePath) &&
               load_js_file("Vector2", parent, modulePath) &&
               load_js_file("Vector3", parent, modulePath) &&
               load_js_file("Vector4", parent, modulePath) &&
               load_js_file("AxisAlignedBox", parent, modulePath) &&
               load_js_file("Intersection", parent, modulePath) &&
               load_js_file("ShuffleBag", parent, modulePath) &&
               bind_RandomNumberGenerator(parent);
    }
}

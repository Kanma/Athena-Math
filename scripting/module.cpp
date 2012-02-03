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


/*************************************** FUNCTIONS *************************************/

bool bind_MathUtils(Handle<Object> parent, const std::string& modulePath)
{
    Handle<Value> result = ScriptingManager::getSingletonPtr()->executeFile(modulePath + "js/Math/MathUtils.js", Context::GetCurrent());
    return !result.IsEmpty();
}


bool bind_Matrix3(Handle<Object> parent, const std::string& modulePath)
{
    Handle<Value> result = ScriptingManager::getSingletonPtr()->executeFile(modulePath + "js/Math/Matrix3.js", Context::GetCurrent());
    return !result.IsEmpty();
}


bool bind_Matrix4(Handle<Object> parent, const std::string& modulePath)
{
    Handle<Value> result = ScriptingManager::getSingletonPtr()->executeFile(modulePath + "js/Math/Matrix4.js", Context::GetCurrent());
    return !result.IsEmpty();
}


bool bind_Quaternion(Handle<Object> parent, const std::string& modulePath)
{
    Handle<Value> result = ScriptingManager::getSingletonPtr()->executeFile(modulePath + "js/Math/Quaternion.js", Context::GetCurrent());
    return !result.IsEmpty();
}


bool bind_Vector2(Handle<Object> parent, const std::string& modulePath)
{
    Handle<Value> result = ScriptingManager::getSingletonPtr()->executeFile(modulePath + "js/Math/Vector2.js", Context::GetCurrent());
    return !result.IsEmpty();
}


bool bind_Vector3(Handle<Object> parent, const std::string& modulePath)
{
    Handle<Value> result = ScriptingManager::getSingletonPtr()->executeFile(modulePath + "js/Math/Vector3.js", Context::GetCurrent());
    return !result.IsEmpty();
}


bool bind_Vector4(Handle<Object> parent, const std::string& modulePath)
{
    Handle<Value> result = ScriptingManager::getSingletonPtr()->executeFile(modulePath + "js/Math/Vector4.js", Context::GetCurrent());
    return !result.IsEmpty();
}


/****************************** INITIALISATION OF THE MODULE ****************************/

extern "C" {

    bool init_module(Handle<Object> parent, const std::string& modulePath)
    {
        HandleScope handle_scope;

        return bind_MathUtils(parent, modulePath) &&
               bind_Matrix3(parent, modulePath) &&
               bind_Matrix4(parent, modulePath) &&
               bind_Quaternion(parent, modulePath) &&
               bind_Vector2(parent, modulePath) &&
               bind_Vector3(parent, modulePath) &&
               bind_Vector4(parent, modulePath);
    }
}

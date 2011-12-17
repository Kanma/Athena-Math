/** @file   module.cpp
    @author Philip Abbet
    
    Entry point of the Javascript module of Athena::Math
*/

#include <v8.h>

using namespace v8;


/*********************************** EXTERNAL FUNCTIONS *********************************/

extern bool bind_MathUtils(Handle<Object> parent);
extern bool bind_Vector3(Handle<Object> parent);


/****************************** INITIALISATION OF THE MODULE ****************************/

extern "C" {

    bool init_module(Handle<Object> parent)
    {
        HandleScope handle_scope;

        return bind_MathUtils(parent) &&
               bind_Vector3(parent);
    }
}

# Setup the search paths
xmake_import_search_paths(ATHENA_SCRIPTING)


# List the source files
set(SRCS module.cpp
         MathUtils.cpp
         Quaternion.cpp
         Vector3.cpp
)


# Declaration of the module
xmake_create_dynamic_library(ATHENA_MATH_SCRIPTING_MODULE Athena-Math-Scripting-module 1.0.0 1.0.0 ${SRCS})
xmake_project_link(ATHENA_MATH_SCRIPTING_MODULE ATHENA_SCRIPTING V8)
set_target_properties(Athena-Math-Scripting-module PROPERTIES OUTPUT_NAME "Math"
                                                              LIBRARY_OUTPUT_DIRECTORY "${XMAKE_BINARY_DIR}/bin/modules/Athena")
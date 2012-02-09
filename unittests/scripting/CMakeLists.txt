# Subdirectories to process
add_subdirectory(js)


# Setup the search paths
xmake_import_search_paths(ATHENA_SCRIPTING)
xmake_import_search_paths(UNITTEST_CPP)


# List the source files
set(SRCS main.cpp
         test_Conversions.cpp
)


# Declaration of the executable
xmake_create_executable(UNITTESTS_ATHENA_MATH_SCRIPTING UnitTests-Athena-Math-Scripting ${SRCS})

xmake_project_link(UNITTESTS_ATHENA_MATH_SCRIPTING UNITTEST_CPP)
xmake_project_link(UNITTESTS_ATHENA_MATH_SCRIPTING ATHENA_MATH)
xmake_project_link(UNITTESTS_ATHENA_MATH_SCRIPTING ATHENA_SCRIPTING)


# Run the unit tests
get_property(PATH TARGET UnitTests-Athena-Math-Scripting PROPERTY RUNTIME_OUTPUT_DIRECTORY)
add_custom_target(Run-UnitTests-Athena-Math-Scripting ALL UnitTests-Athena-Math-Scripting
                  DEPENDS UnitTests-Athena-Math-Scripting
                  WORKING_DIRECTORY ${PATH}
                  COMMENT "Unit testing: Athena-Math-Scripting..." VERBATIM)

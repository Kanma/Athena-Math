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

add_dependencies(UnitTests-Athena-Math-Scripting Run-UnitTests-Athena-Scripting)


# Run the unit tests
set(WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
if (WIN32)
    set(WORKING_DIRECTORY "${WORKING_DIRECTORY}/$(OutDir)")
endif()

add_custom_target(Run-UnitTests-Athena-Math-Scripting ALL UnitTests-Athena-Math-Scripting
                  DEPENDS UnitTests-Athena-Math-Scripting
                  WORKING_DIRECTORY ${WORKING_DIRECTORY}
                  COMMENT "Unit testing: Athena-Math-Scripting..." VERBATIM)

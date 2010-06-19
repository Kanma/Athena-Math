cmake_minimum_required(VERSION 2.6)
project(ATHENA_MATH)

# Settings
set(ATHENA_DOUBLE_PRECISION OFF CACHE BOOL "Use double-precision floating point numbers")

if (NOT DEFINED ATHENA_MATH_STATIC)
    set(ATHENA_MATH_STATIC OFF CACHE BOOL "Build Athena-Math as a static library")
endif()
    
# Set the output paths
if (NOT DEFINED ATHENA_BINARY_DIR)
    set(ATHENA_BINARY_DIR "${ATHENA_MATH_BINARY_DIR}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ATHENA_MATH_BINARY_DIR}/bin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${ATHENA_MATH_BINARY_DIR}/lib")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${ATHENA_MATH_BINARY_DIR}/bin")
endif()

# Set the dependencies path
if (NOT DEFINED ATHENA_DEPENDENCIES_DIR)
    set(ATHENA_DEPENDENCIES_DIR "${ATHENA_MATH_SOURCE_DIR}/dependencies")
endif()

# Import XMake
if (NOT EXISTS "${ATHENA_DEPENDENCIES_DIR}/xmake/XMake.cmake")
    message(FATAL_ERROR
"Missing dependency: XMake
Athena-Math requires XMake to compile. It is provided as a GIT submodule of this repository.
Did you forgot to execute the following commands?
   git submodule init
   git submodule update")
endif()

include("${ATHENA_DEPENDENCIES_DIR}/xmake/XMake.cmake")

# XMake settings
if (ATHENA_MATH_STATIC)
    xmake_init_static(ATHENA_MATH)
    xmake_add_link_paths(ATHENA_MATH "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
else()
    xmake_init_dynamic(ATHENA_MATH)
    xmake_add_link_paths(ATHENA_MATH "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
endif()

xmake_add_include_paths(ATHENA_MATH "${ATHENA_MATH_SOURCE_DIR}/include"
                                    "${ATHENA_BINARY_DIR}/include")
xmake_add_link_targets(ATHENA_MATH Athena-Math)

# Determine system endianess
include(TestBigEndian)
test_big_endian(ATHENA_TEST_BIG_ENDIAN)

# Subdirectories to process
add_subdirectory(include)
add_subdirectory(src)

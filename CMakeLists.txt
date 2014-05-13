cmake_minimum_required(VERSION 2.6)
project(ATHENA_MATH)


##########################################################################################
# Settings

set(ATHENA_DOUBLE_PRECISION OFF CACHE BOOL "Use double-precision floating point numbers")


##########################################################################################
# Library version

set(ATHENA_MATH_VERSION_MAJOR 1)
set(ATHENA_MATH_VERSION_MINOR 1)
set(ATHENA_MATH_VERSION_PATCH 7)
set(ATHENA_MATH_VERSION_SUFFIX "")


##########################################################################################
# XMake-related settings

# Set the output paths
if (NOT DEFINED XMAKE_BINARY_DIR)
    set(XMAKE_BINARY_DIR "${ATHENA_MATH_BINARY_DIR}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${XMAKE_BINARY_DIR}/bin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${XMAKE_BINARY_DIR}/lib")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${XMAKE_BINARY_DIR}/bin")
endif()

# Set the dependencies path
if (NOT DEFINED XMAKE_DEPENDENCIES_DIR)
    set(XMAKE_DEPENDENCIES_DIR "${ATHENA_MATH_SOURCE_DIR}/dependencies")
endif()


##########################################################################################
# XMake importation

if (NOT EXISTS "${XMAKE_DEPENDENCIES_DIR}/XMake/XMake.cmake")
    message(FATAL_ERROR
"Missing dependency: XMake
Athena-Math requires XMake to compile. It is provided as a GIT submodule of this repository.
Did you forgot to execute the following commands?
   git submodule init
   git submodule update")
endif()

include("${XMAKE_DEPENDENCIES_DIR}/XMake/XMake.cmake")


##########################################################################################
# Global definitions

# Determine system endianess
include(TestBigEndian)
test_big_endian(ATHENA_TEST_BIG_ENDIAN)


##########################################################################################
# Process subdirectories

add_subdirectory(include)
add_subdirectory(src)

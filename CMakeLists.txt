cmake_minimum_required(VERSION 2.6)
project(ATHENA_MATH)

# Settings
set(ATHENA_DOUBLE_PRECISION OFF CACHE BOOL "Use double-precision floating point numbers")

# Set the output paths
if (NOT ATHENA_BINARY_DIR)
    set(ATHENA_BINARY_DIR "${ATHENA_MATH_BINARY_DIR}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ATHENA_MATH_BINARY_DIR}/bin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${ATHENA_MATH_BINARY_DIR}/lib")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${ATHENA_MATH_BINARY_DIR}/bin")
endif()

# Determine system endianess
include(TestBigEndian)
test_big_endian(ATHENA_TEST_BIG_ENDIAN)

# Subdirectories to process
add_subdirectory(include)
add_subdirectory(src)

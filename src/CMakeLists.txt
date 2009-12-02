# List the source files
set(SRCS MathUtils.cpp
         Vector2.cpp
         Vector3.cpp
)

# Precompiler definitions
add_definitions(-DATHENA_EXPORTS)

if (ATHENA_DOUBLE_PRECISION)
    add_definitions(-DATHENA_DOUBLE_PRECISION=1)
else()
    add_definitions(-DATHENA_DOUBLE_PRECISION=0)
endif()

# List the include paths
include_directories(${ATHENA_MATH_SOURCE_DIR}/include)

# Declaration of the library
if (NOT ATHENA_MATH_STATIC)
    add_library(Athena-Math SHARED ${SRCS})
else()
    add_library(Athena-Math STATIC ${SRCS})
endif()

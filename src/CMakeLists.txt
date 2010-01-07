# List the source files
set(SRCS AxisAlignedBox.cpp
         Intersection.cpp
         MathUtils.cpp
         Matrix3.cpp
         Matrix4.cpp
         Plane.cpp
         Quaternion.cpp
         Vector2.cpp
         Vector3.cpp
         Vector4.cpp
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

# Disable some warnings in Visual Studio
if (WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# Declaration of the library
if (NOT ATHENA_MATH_STATIC)
    add_library(Athena-Math SHARED ${SRCS})
else()
    add_library(Athena-Math STATIC ${SRCS})
endif()

# Disable some warnings in Visual Studio
if (WIN32)
    set_target_properties(Athena-Math PROPERTIES COMPILE_DEFINITIONS "/wd4244 /wd4305")
endif()

# List the source files
set(SRCS AxisAlignedBox.cpp
         Color.cpp
         Intersection.cpp
         MathUtils.cpp
         Matrix3.cpp
         Matrix4.cpp
         Plane.cpp
         Quaternion.cpp
         RandomNumberGenerator.cpp
         Vector2.cpp
         Vector3.cpp
         Vector4.cpp
)


# List the include paths
set(INCLUDE_PATHS "${ATHENA_MATH_SOURCE_DIR}/include"
                  "${XMAKE_BINARY_DIR}/include")

include_directories(${INCLUDE_PATHS})


# Declaration of the library
if (NOT ATHENA_MATH_STATIC)
    xmake_create_dynamic_library(ATHENA_MATH Athena-Math 1.0.0 1.0.0 ${SRCS})
else()
    xmake_create_static_library(ATHENA_MATH Athena-Math ${SRCS})
endif()

xmake_add_to_property(ATHENA_MATH COMPILE_DEFINITIONS "ATHENA_EXPORTS")

if (WIN32)
    # Disable some warnings in Visual Studio
    xmake_add_to_property(ATHENA_MATH COMPILE_DEFINITIONS "_CRT_SECURE_NO_WARNINGS")
    xmake_add_to_property(ATHENA_MATH COMPILE_DEFINITIONS "/wd4244")
    xmake_add_to_property(ATHENA_MATH COMPILE_DEFINITIONS "/wd4305")
endif()


# Exportations
xmake_export_include_paths(ATHENA_MATH ${INCLUDE_PATHS})

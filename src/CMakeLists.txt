# File generation
configure_file(${ATHENA_MATH_SOURCE_DIR}/src/module.cpp.in
               ${XMAKE_BINARY_DIR}/generated/Athena-Math/module.cpp)

# List the source files
set(SRCS ${XMAKE_BINARY_DIR}/generated/Athena-Math/module.cpp
         AxisAlignedBox.cpp
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

if (DEFINED ATHENA_SCRIPTING_ENABLED AND ATHENA_SCRIPTING_ENABLED)
    set(SRCS ${SRCS} Scripting.cpp)
endif()


# List the include paths
set(INCLUDE_PATHS "${ATHENA_MATH_SOURCE_DIR}/include"
                  "${XMAKE_BINARY_DIR}/include")

include_directories(${INCLUDE_PATHS})

if (DEFINED ATHENA_SCRIPTING_ENABLED AND ATHENA_SCRIPTING_ENABLED)
    xmake_import_search_paths(V8)
endif()


# Declaration of the library
if (NOT ATHENA_MATH_STATIC)
    xmake_create_dynamic_library(ATHENA_MATH Athena-Math
                                 "${ATHENA_MATH_VERSION_MAJOR}.${ATHENA_MATH_VERSION_MINOR}.${ATHENA_MATH_VERSION_PATCH}"
                                 "${ATHENA_MATH_VERSION_MAJOR}.${ATHENA_MATH_VERSION_MINOR}.${ATHENA_MATH_VERSION_PATCH}"
                                 ${SRCS})

    xmake_add_to_list_property(ATHENA_MATH COMPILE_DEFINITIONS "ATHENA_MATH_EXPORTS")
else()
    xmake_create_static_library(ATHENA_MATH Athena-Math ${SRCS})
endif()

if (DEFINED ATHENA_SCRIPTING_ENABLED AND ATHENA_SCRIPTING_ENABLED)
    xmake_project_link(ATHENA_MATH V8)
endif()


if (WIN32)
    # Disable some warnings in Visual Studio
    xmake_add_to_list_property(ATHENA_MATH COMPILE_DEFINITIONS "_CRT_SECURE_NO_WARNINGS")
    xmake_add_to_property(ATHENA_MATH COMPILE_FLAGS /wd4244)
    xmake_add_to_property(ATHENA_MATH COMPILE_FLAGS /wd4305)
endif()


# Exportations
xmake_export_include_paths(ATHENA_MATH ${INCLUDE_PATHS})

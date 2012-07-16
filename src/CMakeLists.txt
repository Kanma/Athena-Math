# File generation
configure_file(${ATHENA_MATH_SOURCE_DIR}/src/module.cpp.in
               ${XMAKE_BINARY_DIR}/generated/Athena-Math/module.cpp)

# List the header files
set(HEADERS ${XMAKE_BINARY_DIR}/include/Athena-Math/Config.h
            ../include/Athena-Math/asm_math.h
            ../include/Athena-Math/AxisAlignedBox.h
            ../include/Athena-Math/Color.h
            ../include/Athena-Math/Declarations.h
            ../include/Athena-Math/Intersection.h
            ../include/Athena-Math/MathUtils.h
            ../include/Athena-Math/Matrix3.h
            ../include/Athena-Math/Matrix4.h
            ../include/Athena-Math/Plane.h
            ../include/Athena-Math/Quaternion.h
            ../include/Athena-Math/RandomNumberGenerator.h
            ../include/Athena-Math/ShuffleBag.h
            ../include/Athena-Math/Sphere.h
            ../include/Athena-Math/Vector2.h
            ../include/Athena-Math/Vector3.h
            ../include/Athena-Math/Vector4.h
)

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
    set(HEADERS ${HEADERS} ../include/Athena-Math/Scripting.h)
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
                                 ${HEADERS} ${SRCS})

    xmake_add_to_list_property(ATHENA_MATH COMPILE_DEFINITIONS "ATHENA_MATH_EXPORTS")
else()
    xmake_create_static_library(ATHENA_MATH Athena-Math ${HEADERS} ${SRCS})
endif()

if (DEFINED ATHENA_SCRIPTING_ENABLED AND ATHENA_SCRIPTING_ENABLED)
    xmake_project_link(ATHENA_MATH V8)
endif()


# Disable some warnings in Visual Studio
xmake_disable_vs_warning(ATHENA_MATH 4244 NO)


# Exportations
xmake_export_include_paths(ATHENA_MATH ${INCLUDE_PATHS})

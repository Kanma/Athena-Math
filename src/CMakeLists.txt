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

# Precompiler definitions
add_definitions(-DATHENA_EXPORTS)

# List the include paths
xmake_include_directories(ATHENA_MATH)

# Disable some warnings in Visual Studio
if (WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# Declaration of the library
if (NOT ATHENA_MATH_STATIC)
    add_library(Athena-Math SHARED ${SRCS})

    # Set the INSTALL_PATH so that the dynamic library can be local
    set_target_properties(Athena-Math PROPERTIES BUILD_WITH_INSTALL_RPATH ON
                                                 INSTALL_NAME_DIR "@rpath"
    )
else()
    add_library(Athena-Math STATIC ${SRCS})

    if (NOT WIN32)
        set_target_properties(Athena-Core PROPERTIES COMPILE_FLAGS "-fPIC")
    endif()
endif()

# Disable some warnings in Visual Studio
if (WIN32)
    set_target_properties(Athena-Math PROPERTIES COMPILE_DEFINITIONS "/wd4244 /wd4305")
endif()

# Setup the search paths
xmake_import_search_paths(ATHENA_SCRIPTING)


# List the source files
set(SRCS module.cpp
         RandomNumberGenerator.cpp
)

set(JS_SRCS AxisAlignedBox.js
            Color.js
            Intersection.js
            MathUtils.js
            Matrix3.js
            Matrix4.js
            Plane.js
            Quaternion.js
            ShuffleBag.js
            Sphere.js
            Vector2.js
            Vector3.js
            Vector4.js
)


# Declaration of the module
xmake_create_dynamic_library(ATHENA_MATH_SCRIPTING_MODULE Athena-Math-Scripting-module
                            "${ATHENA_MATH_VERSION_MAJOR}.${ATHENA_MATH_VERSION_MINOR}.${ATHENA_MATH_VERSION_PATCH}"
                            "${ATHENA_MATH_VERSION_MAJOR}.${ATHENA_MATH_VERSION_MINOR}.${ATHENA_MATH_VERSION_PATCH}"
                            ${SRCS})
xmake_project_link(ATHENA_MATH_SCRIPTING_MODULE ATHENA_SCRIPTING V8)

create_scripting_module(ATHENA_MATH_SCRIPTING_MODULE "Athena.Math" "${JS_SRCS}")

add_dependencies(Athena-Math-Scripting-module Run-UnitTests-Athena-Scripting)

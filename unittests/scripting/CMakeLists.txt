set(JS_FILES Vector3_CreationWithXYZ.js
             Vector3_CreationWithScale.js
             Vector3_CreationWithVector3.js
             Vector3_AttributesAssignement.js
             Vector3_AssignementUsingVector3.js
             Vector3_AssignementUsingScalar.js
)


# set(FULL_JS_FILES "")
# 
# foreach(JS_FILE ${JS_FILES})
#     list(APPEND FULL_JS_FILES "${ATHENA_MATH_SOURCE_DIR}/unittests/scripting/${JS_FILE}")
# endforeach()

# Run the unit tests
add_custom_target(Run-UnitTests-Athena-Scripting-module ALL js_test_runner "${ATHENA_MATH_SOURCE_DIR}/unittests/scripting/" ${JS_FILES}
                  DEPENDS Athena-Math-Scripting-module js_test_runner
                  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
                  COMMENT "Unit testing: Athena-Math-Scripting-module..." VERBATIM)

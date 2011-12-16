set(JS_FILES Vector3_CreationWithXYZ.js
             Vector3_CreationWithScale.js
             Vector3_CreationWithVector3.js
             Vector3_AttributesAssignement.js
             Vector3_AssignementUsingVector3.js
             Vector3_AssignementUsingScalar.js
             Vector3_Equals.js
             Vector3_NotEquals.js
             Vector3_LesserGreater.js
             Vector3_Add.js
             Vector3_Sub.js
             Vector3_Mul.js
             Vector3_Divide.js
             Vector3_Negate.js
             Vector3_IAdd.js
             Vector3_ISub.js
             Vector3_IMul.js
             Vector3_IDivide.js
             Vector3_Length.js
             Vector3_Distance.js
             Vector3_DotProduct.js
             Vector3_Normalise.js
             Vector3_CrossProduct.js
             Vector3_MidPoint.js
             Vector3_FloorCeil.js
             Vector3_Perpendicular.js
             Vector3_PositionEquals.js
             Vector3_PositionCloses.js
             Vector3_IsNaN.js
#             Vector3_Constants.js
)


# Run the unit tests
add_custom_target(Run-UnitTests-Athena-Scripting-module ALL js_test_runner "${ATHENA_MATH_SOURCE_DIR}/unittests/scripting/" ${JS_FILES}
                  DEPENDS Athena-Math-Scripting-module js_test_runner
                  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
                  COMMENT "Unit testing: Athena-Math-Scripting-module..." VERBATIM)

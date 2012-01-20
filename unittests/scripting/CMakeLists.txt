set(JS_FILES # MathUtils
             MathUtils/Sign.js
             MathUtils/Log2.js
             MathUtils/LogN.js
             MathUtils/InvSqrt.js
             MathUtils/Equals.js
             MathUtils/Clamp.js
             MathUtils/UnitConversion.js
             
             # Quaternion
             # Quaternion/CreationWithWXYZ.js
             # Quaternion/CreationWithAngleAxis.js
             # Quaternion/CreationWithAxes.js
             # Quaternion/CreationWithQuaternion.js
             # Quaternion/AttributesAssignement.js
             # Quaternion/Assignement.js
             
             # Vector3
             Vector3/CreationWithXYZ.js
             Vector3/CreationWithScale.js
             Vector3/CreationWithVector3.js
             Vector3/AttributesAssignement.js
             Vector3/AssignementUsingVector3.js
             Vector3/AssignementUsingScalar.js
             Vector3/Equals.js
             Vector3/NotEquals.js
             Vector3/LesserGreater.js
             Vector3/Add.js
             Vector3/Sub.js
             Vector3/Mul.js
             Vector3/Divide.js
             Vector3/Negate.js
             Vector3/IAdd.js
             Vector3/ISub.js
             Vector3/IMul.js
             Vector3/IDivide.js
             Vector3/Length.js
             Vector3/Distance.js
             Vector3/DotProduct.js
             Vector3/Normalise.js
             Vector3/CrossProduct.js
             Vector3/MidPoint.js
             Vector3/FloorCeil.js
             Vector3/Perpendicular.js
             Vector3/AngleBetween.js
             #Vector3/PositionEquals.js
             Vector3/PositionCloses.js
             Vector3/IsNaN.js
             Vector3/Constants.js
)


# Run the unit tests
add_custom_target(Run-UnitTests-Athena-Scripting-module ALL js_test_runner "${ATHENA_MATH_SOURCE_DIR}/unittests/scripting/" ${JS_FILES}
                  DEPENDS Athena-Math-Scripting-module js_test_runner
                  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
                  COMMENT "Unit testing: Athena-Math-Scripting-module..." VERBATIM)

set(JS_FILES # MathUtils
             MathUtils/Sign.js
             MathUtils/Log2.js
             MathUtils/LogN.js
             MathUtils/InvSqrt.js
             MathUtils/Equals.js
             MathUtils/Clamp.js
             MathUtils/UnitConversion.js

             # Matrix3
             Matrix3/CreationWithValues.js
             Matrix3/CreationWithMatrix3.js
             Matrix3/CreationWithVectors.js
             Matrix3/CreationWithAngleAndAxis.js
             Matrix3/Assignement.js
             Matrix3/Equals.js
             Matrix3/NotEquals.js
             Matrix3/Add.js
             Matrix3/Sub.js
             Matrix3/Mul.js
             Matrix3/Negate.js
             Matrix3/Transpose.js
             Matrix3/EulerAnglesXYZ.js
             Matrix3/EulerAnglesXZY.js
             Matrix3/EulerAnglesYXZ.js
             Matrix3/EulerAnglesYZX.js
             Matrix3/EulerAnglesZXY.js
             Matrix3/EulerAnglesZYX.js

             # Matrix4
             Matrix4/CreationWithValues.js
             Matrix4/CreationWithMatrix4.js
             Matrix4/CreationWithMatrix3.js
             Matrix4/CreationWithQuaternion.js
             Matrix4/Assignement.js
             Matrix4/MakeTransform.js
             Matrix4/Add.js
             Matrix4/Sub.js
             Matrix4/Mul.js
             Matrix4/Equals.js
             Matrix4/NotEquals.js
             Matrix4/Transpose.js
             Matrix4/Translation.js
             
             # Quaternion
             Quaternion/CreationWithWXYZ.js
             Quaternion/CreationWithAngleAxis.js
             Quaternion/CreationWithAxes.js
             Quaternion/CreationWithQuaternion.js
             Quaternion/CreationWithMatrix3.js
             Quaternion/AttributesAssignement.js
             Quaternion/Assignement.js
             Quaternion/Length.js
             Quaternion/Normalize.js
             Quaternion/IsNaN.js
             Quaternion/Add.js
             Quaternion/Sub.js
             Quaternion/Mul.js
             Quaternion/Negate.js
             Quaternion/Equals.js
             Quaternion/NotEquals.js
             
             # Vector2
             Vector2/CreationWithXY.js
             Vector2/CreationWithScale.js
             Vector2/CreationWithVector2.js
             Vector2/AttributesAssignement.js
             Vector2/AssignementUsingVector2.js
             Vector2/AssignementUsingScalar.js
             Vector2/Equals.js
             Vector2/NotEquals.js
             Vector2/LesserGreater.js
             Vector2/Add.js
             Vector2/Sub.js
             Vector2/Mul.js
             Vector2/Divide.js
             Vector2/Negate.js
             Vector2/IAdd.js
             Vector2/ISub.js
             Vector2/IMul.js
             Vector2/IDivide.js
             Vector2/Length.js
             Vector2/Distance.js
             Vector2/DotProduct.js
             Vector2/Normalise.js
             Vector2/CrossProduct.js
             Vector2/MidPoint.js
             Vector2/FloorCeil.js
             Vector2/Perpendicular.js
             Vector2/RandomDeviant.js
             Vector2/AngleBetween.js
             Vector2/PositionEquals.js
             Vector2/PositionCloses.js
             Vector2/IsNaN.js
             Vector2/Constants.js

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
             Vector3/RandomDeviant.js
             Vector3/AngleBetween.js
             Vector3/GetRotationTo.js
             Vector3/PositionEquals.js
             Vector3/PositionCloses.js
             Vector3/IsNaN.js
             Vector3/Constants.js
)


# Run the unit tests
add_custom_target(Run-UnitTests-Athena-Math-Scripting-module ALL js_test_runner "${ATHENA_MATH_SOURCE_DIR}/unittests/scripting/js/" ${JS_FILES}
                  DEPENDS Athena-Math-Scripting-module js_test_runner
                  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
                  COMMENT "Unit testing: Athena-Math-Scripting-module..." VERBATIM)

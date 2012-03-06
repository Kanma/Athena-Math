set(JS_FILES # AxisAlignedBox
             AxisAlignedBox/Null.js
             AxisAlignedBox/Infinite.js
             AxisAlignedBox/CreationWithPoints.js
             AxisAlignedBox/CreationWithScalars.js
             AxisAlignedBox/Equals.js
             AxisAlignedBox/NotEquals.js
             AxisAlignedBox/GetCorner.js
             AxisAlignedBox/MergeBox.js
             AxisAlignedBox/MergePoint.js
             AxisAlignedBox/Transform.js
             AxisAlignedBox/Intersection.js
             AxisAlignedBox/Volume.js
             AxisAlignedBox/Scale.js
             AxisAlignedBox/GetCenter.js
             AxisAlignedBox/GetSize.js
             AxisAlignedBox/GetHalfSize.js
             AxisAlignedBox/ContainsBox.js
             AxisAlignedBox/ContainsPoint.js

             # Color
             Color/ConstructionWithoutParameters.js
             Color/ConstructionWithRGB.js
             Color/ConstructionWithRGBA.js
             Color/ConstructionWithPlane.js
             Color/Equals.js
             Color/NotEquals.js
             Color/Saturate.js
             Color/HSB.js

             # MathUtils
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

             # Plane
             Plane/ConstructionWithoutParameters.js
             Plane/ConstructionWithPlane.js
             Plane/ConstructionWithVector3AndConstant.js
             Plane/ConstructionWithScalars.js
             Plane/ConstructionWithNormalAndPoint.js
             Plane/ConstructionWith3Points.js
             Plane/GetSideOfPoint.js
             Plane/GetSideOfBox.js
             Plane/GetSideOfBox2.js
             Plane/ProjectVector.js
             Plane/GetDistance.js

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

             # Vector4
             Vector4/CreationWithXYZW.js
             Vector4/CreationWithScale.js
             Vector4/CreationWithVector4.js
             Vector4/CreationWithVector3.js
             Vector4/AttributesAssignement.js
             Vector4/AssignementUsingVector4.js
             Vector4/AssignementUsingVector3.js
             Vector4/AssignementUsingScalar.js
             Vector4/Equals.js
             Vector4/NotEquals.js
             Vector4/LesserGreater.js
             Vector4/Add.js
             Vector4/Sub.js
             Vector4/Mul.js
             Vector4/Divide.js
             Vector4/Negate.js
             Vector4/IAdd.js
             Vector4/ISub.js
             Vector4/IMul.js
             Vector4/IDivide.js
             Vector4/Length.js
             Vector4/Distance.js
             Vector4/DotProduct.js
             Vector4/Normalise.js
             Vector4/MidPoint.js
             Vector4/FloorCeil.js
             Vector4/PositionEquals.js
             Vector4/PositionCloses.js
             Vector4/IsNaN.js
             Vector4/Constants.js

             # Intersections
             Intersection/AxisAlignedBox_AxisAlignedBox.js
             Intersection/AxisAlignedBox_Sphere.js
             Intersection/AxisAlignedBox_Plane.js
             Intersection/AxisAlignedBox_Vector3.js
             Intersection/Sphere_Sphere.js
             Intersection/Sphere_Plane.js
             Intersection/Sphere_Vector3.js

             # RandomNumberGenerator
             RandomNumberGenerator/RandomizeMax.js
             RandomNumberGenerator/RandomizeMinMax.js
             RandomNumberGenerator/RandomizeIntMax.js
             RandomNumberGenerator/RandomizeIntMinMax.js
             RandomNumberGenerator/SetSeed.js

             # ShuffleBag
             ShuffleBag/ShuffleBag.js
)


# Run the unit tests
set(WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
if (WIN32)
    set(WORKING_DIRECTORY "${WORKING_DIRECTORY}/$(OutDir)")
endif()

add_custom_target(Run-UnitTests-Athena-Math-Scripting-module ALL js_test_runner "${ATHENA_MATH_SOURCE_DIR}/unittests/scripting/js/" ${JS_FILES}
                  DEPENDS Athena-Math-Scripting-module js_test_runner
                  WORKING_DIRECTORY ${WORKING_DIRECTORY}
                  COMMENT "Unit testing: Athena-Math-Scripting-module..." VERBATIM)

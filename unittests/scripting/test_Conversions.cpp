#include <UnitTest++.h>
#include <Athena-Math/Scripting.h>
#include <Athena-Scripting/ScriptingManager.h>

using namespace Athena::Scripting;
using namespace Athena::Math;
using namespace v8;


struct ScriptingTestEnvironment
{
    Athena::Scripting::ScriptingManager* pScriptingManager;

    ScriptingTestEnvironment()
    : pScriptingManager(0)
    {
        pScriptingManager = new Athena::Scripting::ScriptingManager();
    }

    ~ScriptingTestEnvironment()
    {
        delete pScriptingManager;
    }
};


SUITE(Conversions)
{
    TEST_FIXTURE(ScriptingTestEnvironment, ConvertNullAxisAlignedBoxFromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);");

        AxisAlignedBox aab = fromJSAxisAlignedBox(result);

        CHECK(aab.isNull());
    }


    TEST_FIXTURE(ScriptingTestEnvironment, ConvertInfiniteAxisAlignedBoxFromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);");

        AxisAlignedBox aab = fromJSAxisAlignedBox(result);

        CHECK(aab.isInfinite());
    }


    TEST_FIXTURE(ScriptingTestEnvironment, ConvertFiniteAxisAlignedBoxFromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.AxisAlignedBox(1, 2, 3, 4, 5, 6);");

        AxisAlignedBox aab = fromJSAxisAlignedBox(result);

        CHECK(aab.isFinite());
        CHECK_CLOSE(1.0f, aab.getMinimum().x, 1e-6f);
        CHECK_CLOSE(2.0f, aab.getMinimum().y, 1e-6f);
        CHECK_CLOSE(3.0f, aab.getMinimum().z, 1e-6f);
        CHECK_CLOSE(4.0f, aab.getMaximum().x, 1e-6f);
        CHECK_CLOSE(5.0f, aab.getMaximum().y, 1e-6f);
        CHECK_CLOSE(6.0f, aab.getMaximum().z, 1e-6f);
    }


    TEST_FIXTURE(ScriptingTestEnvironment, ConvertColorFromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.Color(0.1, 0.2, 0.3, 0.4);");

        Color color = fromJSColor(result);

        CHECK_CLOSE(0.1f, color.r, 1e-6f);
        CHECK_CLOSE(0.2f, color.g, 1e-6f);
        CHECK_CLOSE(0.3f, color.b, 1e-6f);
        CHECK_CLOSE(0.4f, color.a, 1e-6f);
    }


    TEST_FIXTURE(ScriptingTestEnvironment, ConvertMatrix3FromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);");

        Matrix3 mat = fromJSMatrix3(result);

        CHECK_CLOSE(1.0f, mat[0][0], 1e-6f);
        CHECK_CLOSE(2.0f, mat[0][1], 1e-6f);
        CHECK_CLOSE(3.0f, mat[0][2], 1e-6f);

        CHECK_CLOSE(4.0f, mat[1][0], 1e-6f);
        CHECK_CLOSE(5.0f, mat[1][1], 1e-6f);
        CHECK_CLOSE(6.0f, mat[1][2], 1e-6f);

        CHECK_CLOSE(7.0f, mat[2][0], 1e-6f);
        CHECK_CLOSE(8.0f, mat[2][1], 1e-6f);
        CHECK_CLOSE(9.0f, mat[2][2], 1e-6f);
    }


    TEST_FIXTURE(ScriptingTestEnvironment, ConvertMatrix4FromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.Matrix4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);");

        Matrix4 mat = fromJSMatrix4(result);

        CHECK_CLOSE(1.0f, mat[0][0], 1e-6f);
        CHECK_CLOSE(2.0f, mat[0][1], 1e-6f);
        CHECK_CLOSE(3.0f, mat[0][2], 1e-6f);
        CHECK_CLOSE(4.0f, mat[0][3], 1e-6f);

        CHECK_CLOSE(5.0f, mat[1][0], 1e-6f);
        CHECK_CLOSE(6.0f, mat[1][1], 1e-6f);
        CHECK_CLOSE(7.0f, mat[1][2], 1e-6f);
        CHECK_CLOSE(8.0f, mat[1][3], 1e-6f);

        CHECK_CLOSE(9.0f, mat[2][0], 1e-6f);
        CHECK_CLOSE(10.0f, mat[2][1], 1e-6f);
        CHECK_CLOSE(11.0f, mat[2][2], 1e-6f);
        CHECK_CLOSE(12.0f, mat[2][3], 1e-6f);

        CHECK_CLOSE(13.0f, mat[3][0], 1e-6f);
        CHECK_CLOSE(14.0f, mat[3][1], 1e-6f);
        CHECK_CLOSE(15.0f, mat[3][2], 1e-6f);
        CHECK_CLOSE(16.0f, mat[3][3], 1e-6f);
    }


    TEST_FIXTURE(ScriptingTestEnvironment, ConvertPlaneFromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.Plane(new Athena.Math.Vector3(2, 3, 4), 1);");

        Plane plane = fromJSPlane(result);

        CHECK_CLOSE(1.0f, plane.d, 1e-6f);
        CHECK_CLOSE(2.0f, plane.normal.x, 1e-6f);
        CHECK_CLOSE(3.0f, plane.normal.y, 1e-6f);
        CHECK_CLOSE(4.0f, plane.normal.z, 1e-6f);
    }


    TEST_FIXTURE(ScriptingTestEnvironment, ConvertQuaternionFromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.Quaternion(1, 2, 3, 4);");

        Quaternion quat = fromJSQuaternion(result);

        CHECK_CLOSE(1.0f, quat.w, 1e-6f);
        CHECK_CLOSE(2.0f, quat.x, 1e-6f);
        CHECK_CLOSE(3.0f, quat.y, 1e-6f);
        CHECK_CLOSE(4.0f, quat.z, 1e-6f);
    }


    TEST_FIXTURE(ScriptingTestEnvironment, ConvertSphereFromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.Sphere(new Athena.Math.Vector3(2, 3, 4), 1);");

        Sphere sphere = fromJSSphere(result);

        CHECK_CLOSE(1.0f, sphere.getRadius(), 1e-6f);
        CHECK_CLOSE(2.0f, sphere.getCenter().x, 1e-6f);
        CHECK_CLOSE(3.0f, sphere.getCenter().y, 1e-6f);
        CHECK_CLOSE(4.0f, sphere.getCenter().z, 1e-6f);
    }


    TEST_FIXTURE(ScriptingTestEnvironment, ConvertVector2FromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.Vector2(1, 2);");

        Vector2 vector = fromJSVector2(result);

        CHECK_CLOSE(1.0f, vector.x, 1e-6f);
        CHECK_CLOSE(2.0f, vector.y, 1e-6f);
    }


    TEST_FIXTURE(ScriptingTestEnvironment, ConvertVector3FromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.Vector3(1, 2, 3);");

        Vector3 vector = fromJSVector3(result);

        CHECK_CLOSE(1.0f, vector.x, 1e-6f);
        CHECK_CLOSE(2.0f, vector.y, 1e-6f);
        CHECK_CLOSE(3.0f, vector.z, 1e-6f);
    }


    TEST_FIXTURE(ScriptingTestEnvironment, ConvertVector4FromJavaScript)
    {
        HandleScope handle_scope;

        Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.Vector4(1, 2, 3, 4);");

        Vector4 vector = fromJSVector4(result);

        CHECK_CLOSE(1.0f, vector.x, 1e-6f);
        CHECK_CLOSE(2.0f, vector.y, 1e-6f);
        CHECK_CLOSE(3.0f, vector.z, 1e-6f);
        CHECK_CLOSE(4.0f, vector.w, 1e-6f);
    }
}

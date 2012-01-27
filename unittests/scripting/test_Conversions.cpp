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
	TEST_FIXTURE(ScriptingTestEnvironment, ConvertVector3FromJavaScript)
	{
        HandleScope handle_scope;

		Handle<Value> result = pScriptingManager->execute("import_module('Athena.Math'); new Athena.Math.Vector3(1, 2, 3);");

        Vector3 vector = fromJSVector3(result);

        CHECK_CLOSE(1.0f, vector.x, 1e-6f);
        CHECK_CLOSE(2.0f, vector.y, 1e-6f);
        CHECK_CLOSE(3.0f, vector.z, 1e-6f);
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
}

import_module('Athena.Math');

v1 = new Athena.Math.Vector4(10, 20, 30, 40);
v2 = new Athena.Math.Vector4(10, 20, 30, 40);
v3 = new Athena.Math.Vector4(10, 20, 300, 400);

CHECK(v1.notEquals(v3), "v1.notEquals(v3)");
CHECK(!v1.notEquals(v2), "!v1.notEquals(v2)");

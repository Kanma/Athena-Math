import_module('Athena.Math');

v1 = new Athena.Math.Vector3(10, 20, 30);
v2 = new Athena.Math.Vector3(10.1, 20.05, 29.9);

CHECK(v1.positionEquals(v2, 0.2), "v1.positionEquals(v2, 0.2)");
CHECK(!v1.positionEquals(v2, 0.01), "!v1.positionEquals(v2, 0.01)");

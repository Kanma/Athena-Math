import_module('Athena.Math');

v1 = new Athena.Math.Vector4(10, 20, 30, 40);
v2 = new Athena.Math.Vector4(10.1, 20.05, 29.9, 40.15);

CHECK(v1.positionEquals(v2, 0.2), "v1.positionEquals(v2, 0.2)");
CHECK(!v1.positionEquals(v2, 0.01), "!v1.positionEquals(v2, 0.01)");

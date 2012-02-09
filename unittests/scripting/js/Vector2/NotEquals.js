import_module('Athena.Math');

v1 = new Athena.Math.Vector2(10, 20);
v2 = new Athena.Math.Vector2(10, 20);
v3 = new Athena.Math.Vector2(10, 30);

CHECK(v1.notEquals(v3), "v1.notEquals(v3)");
CHECK(!v1.notEquals(v2), "!v1.notEquals(v2)");

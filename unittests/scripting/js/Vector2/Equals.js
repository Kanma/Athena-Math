import_module('Athena.Math');

v1 = new Athena.Math.Vector2(10, 20);
v2 = new Athena.Math.Vector2(10, 20);
v3 = new Athena.Math.Vector2(10, 30);

CHECK(v1.equals(v2), "v1.equals(v2)");
CHECK(!v1.equals(v3), "!v1.equals(v3)");

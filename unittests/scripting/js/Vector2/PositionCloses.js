import_module('Athena.Math');

v1 = new Athena.Math.Vector2(1, 2);
v2 = new Athena.Math.Vector2(1.1, 2.05);

CHECK(v1.positionCloses(v2, 0.01), "v1.positionCloses(v2, 0.01)");
CHECK(!v1.positionCloses(v2, 0.0001), "!v1.positionCloses(v2, 0.001)");

import_module('Athena.Math');

v1 = new Athena.Math.Vector3(10, 20, 30);
v2 = new Athena.Math.Vector3(100, 200, 300);

CHECK(v1.lesserThan(v2), "v1.lesserThan(v2)");
CHECK(!v2.lesserThan(v1), "!v2.lesserThan(v1)");
CHECK(v2.greaterThan(v1), "v2.greaterThan(v1)");
CHECK(!v1.greaterThan(v2), "!v1.greaterThan(v2)");

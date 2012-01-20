import_module('Athena.Math');

v = new Athena.Math.Vector3(NaN, 2, 3);

CHECK(v.isNaN(), "v.isNaN()");

v = new Athena.Math.Vector3(1, 2, 3);

CHECK(!v.isNaN(), "!v.isNaN()");

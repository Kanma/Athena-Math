import_module('Athena.Math');

v = new Athena.Math.Vector4(NaN, 2, 3, 4);

CHECK(v.isNaN(), "v.isNaN()");

v = new Athena.Math.Vector4(1, 2, 3, 4);

CHECK(!v.isNaN(), "!v.isNaN()");

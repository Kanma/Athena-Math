import_module('Athena.Math');

v = new Athena.Math.Vector2(NaN, 2);

CHECK(v.isNaN(), "v.isNaN()");

v = new Athena.Math.Vector2(1, 2);

CHECK(!v.isNaN(), "!v.isNaN()");

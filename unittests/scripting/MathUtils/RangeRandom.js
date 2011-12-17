import_module('Athena.Math');


n = Athena.Math.rangeRandom(100.0, 200.0);
CHECK(n >= 100.0, "n >= 100.0");
CHECK(n <= 200.0, "n <= 200.0");

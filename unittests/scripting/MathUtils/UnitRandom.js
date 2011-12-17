import_module('Athena.Math');


n = Athena.Math.unitRandom();
CHECK(n >= 0.0, "n >= 0.0");
CHECK(n <= 1.0, "n <= 1.0");

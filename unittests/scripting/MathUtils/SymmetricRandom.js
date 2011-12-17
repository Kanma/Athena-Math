import_module('Athena.Math');


n = Athena.Math.symmetricRandom();
CHECK(n >= -1.0, "n >= -1.0");
CHECK(n <= 1.0, "n <= 1.0");

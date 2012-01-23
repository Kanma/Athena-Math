import_module('Athena.Math');

q = new Athena.Math.Quaternion(NaN, 1, 2, 3);

CHECK(q.isNaN(), "q.isNaN()");

q = new Athena.Math.Quaternion(1, 2, 3, 4);

CHECK(!q.isNaN(), "!q.isNaN()");

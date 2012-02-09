import_module('Athena.Math');

m1 = new Athena.Math.Matrix3(1, 2, 3,
                             5, 6, 7,
                             9, 10, 11);

m2 = new Athena.Math.Matrix3(1, 2, 3,
                             5, 6, 7,
                             9, 10, 11);

m3 = new Athena.Math.Matrix3(100, 200, 300,
                             500, 600, 700,
                             900, 1000, 1100);


CHECK(m1.notEquals(m3), "m1.notEquals(m3)");
CHECK(!m1.notEquals(m2), "!m1.notEquals(m2)");

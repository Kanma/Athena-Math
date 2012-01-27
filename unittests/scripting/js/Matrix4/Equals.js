import_module('Athena.Math');

m1 = new Athena.Math.Matrix4(1, 2, 3, 4,
                             5, 6, 7, 8,
                             9, 10, 11, 12,
                             13, 14, 15, 16);

m2 = new Athena.Math.Matrix4(1, 2, 3, 4,
                             5, 6, 7, 8,
                             9, 10, 11, 12,
                             13, 14, 15, 16);

m3 = new Athena.Math.Matrix4(100, 200, 300, 400,
                             500, 600, 700, 800,
                             900, 1000, 1100, 1200,
                             1300, 1400, 1500, 1600);


CHECK(m1.equals(m2), "m1.equals(m2)");
CHECK(!m1.equals(m3), "!m1.equals(m3)");

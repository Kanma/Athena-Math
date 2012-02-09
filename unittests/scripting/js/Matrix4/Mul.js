import_module('Athena.Math');

m1 = new Athena.Math.Matrix4(1, 2, 3, 4,
                             5, 6, 7, 8,
                             9, 10, 11, 12,
                             13, 14, 15, 16);

m2 = new Athena.Math.Matrix4(100, 200, 300, 400,
                             500, 600, 700, 800,
                             900, 1000, 1100, 1200,
                             1300, 1400, 1500, 1600);

m3 = new Athena.Math.Matrix4(10000, 20000, 30000, 40000,
                             50000, 60000, 70000, 80000,
                             90000, 100000, 110000, 120000,
                             130000, 140000, 150000, 160000);

m = m1.mul(10);

for (var row = 0; row < 4; ++row)
{
    for (var col = 0; col < 4; ++col)
        CHECK_CLOSE(10 * m1.get(row, col), m.get(row, col));
}


m = m1.mul(10, 10);

for (var row = 0; row < 4; ++row)
{
    for (var col = 0; col < 4; ++col)
        CHECK_CLOSE(m.get(row, col), m2.get(row, col));
}

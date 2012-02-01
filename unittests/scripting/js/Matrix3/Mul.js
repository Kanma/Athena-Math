import_module('Athena.Math');

m1 = new Athena.Math.Matrix3(1, 2, 3,
                             4, 5, 6,
                             7, 8, 9);

m2 = new Athena.Math.Matrix3(100, 200, 300,
                             400, 500, 600,
                             700, 800, 900);

m3 = new Athena.Math.Matrix3(10000, 20000, 30000,
                             40000, 50000, 60000,
                             70000, 80000, 90000);

m = m1.mul(10);

for (var row = 0; row < 3; ++row)
{
    for (var col = 0; col < 3; ++col)
        CHECK_CLOSE(10 * m1.get(row, col), m.get(row, col));
}


m = m1.mul(10, 10);

for (var row = 0; row < 3; ++row)
{
    for (var col = 0; col < 3; ++col)
        CHECK_CLOSE(m.get(row, col), m2.get(row, col));
}

import_module('Athena.Math');

m1 = new Athena.Math.Matrix3(1, 2, 3,
                             4, 5, 6,
                             7, 8, 9);


for (var row = 0; row < 3; ++row)
{
    for (var col = 0; col < 3; ++col)
        CHECK_CLOSE(row * 3 + col + 1, m1.get(row, col));
}

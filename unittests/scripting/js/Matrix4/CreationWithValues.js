import_module('Athena.Math');

m1 = new Athena.Math.Matrix4(1, 2, 3, 4,
                             5, 6, 7, 8,
                             9, 10, 11, 12,
                             13, 14, 15, 16);


for (var row = 0; row < 4; ++row)
{
    for (var col = 0; col < 4; ++col)
        CHECK_CLOSE(row * 4 + col + 1, m1.get(row, col));
}

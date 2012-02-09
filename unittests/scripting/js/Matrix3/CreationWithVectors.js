import_module('Athena.Math');

vx = new Athena.Math.Vector3(1, 4, 7);
vy = new Athena.Math.Vector3(2, 5, 8);
vz = new Athena.Math.Vector3(3, 6, 9);

m1 = new Athena.Math.Matrix3(vx, vy, vz);


for (var row = 0; row < 3; ++row)
{
    for (var col = 0; col < 3; ++col)
        CHECK_CLOSE(row * 3 + col + 1, m1.get(row, col));
}

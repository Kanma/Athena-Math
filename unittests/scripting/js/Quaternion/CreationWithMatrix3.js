import_module('Athena.Math');

m = new Athena.Math.Matrix3(Athena.Math.Vector3_UNIT_X, Math.PI / 2);

q = new Athena.Math.Quaternion(m);

m2 = q.toRotationMatrix();

for (var row = 0; row < 3; ++row)
{
    for (var col = 0; col < 3; ++col)
        CHECK_CLOSE(m.get(row, col), m2.get(row, col));
}

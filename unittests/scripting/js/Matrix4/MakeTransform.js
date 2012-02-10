import_module('Athena.Math');

m = new Athena.Math.Matrix4();

m.makeTransform(Athena.Math.Vector3_ZERO,
                new Athena.Math.Vector3(2.0, 3.0, 4.0),
                Athena.Math.Quaternion_IDENTITY);

v1 = new Athena.Math.Vector3(1.0, 2.0, 3.0);

v2 = m.mul(v1);

CHECK_CLOSE(2.0, v2.x);
CHECK_CLOSE(6.0, v2.y);
CHECK_CLOSE(12.0, v2.z);

/////////////////

m.makeTransform(new Athena.Math.Vector3(2.0, 3.0, 4.0),
                Athena.Math.Vector3_UNIT_SCALE,
                Athena.Math.Quaternion_IDENTITY);

v2 = m.mul(v1);

CHECK_CLOSE(3.0, v2.x);
CHECK_CLOSE(5.0, v2.y);
CHECK_CLOSE(7.0, v2.z);

/////////////////

m.makeTransform(Athena.Math.Vector3_ZERO,
                Athena.Math.Vector3_UNIT_SCALE,
                new Athena.Math.Quaternion(Math.PI / 2, Athena.Math.Vector3_UNIT_Y));

v2 = m.mul(v1);

CHECK_CLOSE(3.0, v2.x);
CHECK_CLOSE(2.0, v2.y);
CHECK_CLOSE(-1.0, v2.z);

/////////////////

m.makeTransform(new Athena.Math.Vector3(2.0, 3.0, 4.0),
                new Athena.Math.Vector3(2.0, 3.0, 4.0),
                new Athena.Math.Quaternion(Math.PI / 2, Athena.Math.Vector3_UNIT_Y));

v2 = m.mul(v1);

CHECK_CLOSE(14.0, v2.x);
CHECK_CLOSE(9.0, v2.y);
CHECK_CLOSE(2.0, v2.z);

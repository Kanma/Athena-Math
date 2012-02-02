import_module('Athena.Math');

q1 = new Athena.Math.Quaternion(Math.PI / 2, Athena.Math.Vector3_UNIT_Y);

m1 = new Athena.Math.Matrix4(q1);

v1 = q1.mul(Athena.Math.Vector3_UNIT_X);
v2 = m1.mul(Athena.Math.Vector3_UNIT_X);

CHECK_CLOSE(v1.x, v2.x);
CHECK_CLOSE(v1.y, v2.y);
CHECK_CLOSE(v1.z, v2.z);

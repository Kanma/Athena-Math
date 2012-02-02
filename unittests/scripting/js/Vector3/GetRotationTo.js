import_module('Athena.Math');

v1 = new Athena.Math.Vector3(1, 0, 0);
q1 = new Athena.Math.Quaternion(Math.PI / 2, Athena.Math.Vector3_UNIT_Z);

v2 = q1.mul(v1);

q2 = v1.getRotationTo(v2);

v3 = q2.mul(v1);

CHECK_CLOSE(v2.x, v3.x);
CHECK_CLOSE(v2.y, v3.y);
CHECK_CLOSE(v2.z, v3.z);


q1 = new Athena.Math.Quaternion(Math.PI / 4, Athena.Math.Vector3_UNIT_Y);

v2 = q1.mul(v1);

q2 = v1.getRotationTo(v2);

v3 = q2.mul(v1);

CHECK_CLOSE(v2.x, v3.x);
CHECK_CLOSE(v2.y, v3.y);
CHECK_CLOSE(v2.z, v3.z);

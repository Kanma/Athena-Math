import_module('Athena.Math');

q1 = new Athena.Math.Quaternion(Math.PI / 2, Athena.Math.Vector3_UNIT_Y);
q2 = new Athena.Math.Quaternion(Math.PI, Athena.Math.Vector3_UNIT_Y);
q3 = new Athena.Math.Quaternion(Math.PI * 3 / 2, Athena.Math.Vector3_UNIT_Y);
q4 = new Athena.Math.Quaternion(1, 2, 3, 4);


q = q1.mul(q1);

CHECK_CLOSE(q2.w, q.w);
CHECK_CLOSE(q2.x, q.x);
CHECK_CLOSE(q2.y, q.y);
CHECK_CLOSE(q2.z, q.z);

q = q1.mul(q1, q1);

CHECK_CLOSE(q3.w, q.w);
CHECK_CLOSE(q3.x, q.x);
CHECK_CLOSE(q3.y, q.y);
CHECK_CLOSE(q3.z, q.z);

q = q1.mul(q1, q1, q2.negate());

CHECK_CLOSE(q1.w, q.w);
CHECK_CLOSE(q1.x, q.x);
CHECK_CLOSE(q1.y, q.y);
CHECK_CLOSE(q1.z, q.z);

q = q4.mul(2);

CHECK_CLOSE(2, q.w);
CHECK_CLOSE(4, q.x);
CHECK_CLOSE(6, q.y);
CHECK_CLOSE(8, q.z);

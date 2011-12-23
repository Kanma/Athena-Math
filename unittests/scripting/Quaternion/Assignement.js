import_module('Athena.Math');

q1 = new Athena.Math.Quaternion(1, 0, 0, 0);

q2 = new Athena.Math.Quaternion();

q2.set(q1);

CHECK_CLOSE(q1.w, q2.w);
CHECK_CLOSE(q1.x, q2.x);
CHECK_CLOSE(q1.y, q2.y);
CHECK_CLOSE(q1.z, q2.z);

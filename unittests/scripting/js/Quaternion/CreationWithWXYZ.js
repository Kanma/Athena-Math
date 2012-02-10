import_module('Athena.Math');

q = new Athena.Math.Quaternion(0.707, 0.707, 0, 0);

CHECK_CLOSE(0.707, q.w);
CHECK_CLOSE(0.707, q.x);
CHECK_CLOSE(0, q.y);
CHECK_CLOSE(0, q.z);

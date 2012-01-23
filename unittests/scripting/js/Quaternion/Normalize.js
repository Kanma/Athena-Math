import_module('Athena.Math');

q = new Athena.Math.Quaternion(10, 0, 0, 0);

length = q.normalise();

CHECK_CLOSE(10, length);
CHECK_CLOSE(1, q.w);
CHECK_CLOSE(0, q.x);
CHECK_CLOSE(0, q.y);
CHECK_CLOSE(0, q.z);

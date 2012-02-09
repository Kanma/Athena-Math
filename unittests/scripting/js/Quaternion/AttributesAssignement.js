import_module('Athena.Math');

q = new Athena.Math.Quaternion();

q.w = 1;
q.x = 2;
q.y = 3;
q.z = 4;

CHECK_CLOSE(1, q.w);
CHECK_CLOSE(2, q.x);
CHECK_CLOSE(3, q.y);
CHECK_CLOSE(4, q.z);

import_module('Athena.Math');

q1 = new Athena.Math.Quaternion(10, 20, 30, 40);

q = q1.negate();

CHECK_CLOSE(-10, q.w);
CHECK_CLOSE(-20, q.x);
CHECK_CLOSE(-30, q.y);
CHECK_CLOSE(-40, q.z);

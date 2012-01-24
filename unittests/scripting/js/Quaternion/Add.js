import_module('Athena.Math');

q1 = new Athena.Math.Quaternion(10, 20, 30, 40);
q2 = new Athena.Math.Quaternion(100, 200, 300, 400);
q3 = new Athena.Math.Quaternion(1000, 2000, 3000, 4000);


q = q1.add(q2);

CHECK_CLOSE(110, q.w);
CHECK_CLOSE(220, q.x);
CHECK_CLOSE(330, q.y);
CHECK_CLOSE(440, q.z);

q = q1.add(q2, q3);

CHECK_CLOSE(1110, q.w);
CHECK_CLOSE(2220, q.x);
CHECK_CLOSE(3330, q.y);
CHECK_CLOSE(4440, q.z);

q = q.add(q1);

CHECK_CLOSE(1120, q.w);
CHECK_CLOSE(2240, q.x);
CHECK_CLOSE(3360, q.y);
CHECK_CLOSE(4480, q.z);

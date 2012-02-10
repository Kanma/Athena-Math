import_module('Athena.Math');

q1 = new Athena.Math.Quaternion(1000, 2000, 3000, 4000);
q2 = new Athena.Math.Quaternion(100, 200, 300, 400);
q3 = new Athena.Math.Quaternion(10, 20, 30, 40);


q = q1.sub(q2);

CHECK_CLOSE(900, q.w);
CHECK_CLOSE(1800, q.x);
CHECK_CLOSE(2700, q.y);
CHECK_CLOSE(3600, q.z);

q = q1.sub(q2, q3);

CHECK_CLOSE(890, q.w);
CHECK_CLOSE(1780, q.x);
CHECK_CLOSE(2670, q.y);
CHECK_CLOSE(3560, q.z);

q = q.sub(q1);

CHECK_CLOSE(-110, q.w);
CHECK_CLOSE(-220, q.x);
CHECK_CLOSE(-330, q.y);
CHECK_CLOSE(-440, q.z);

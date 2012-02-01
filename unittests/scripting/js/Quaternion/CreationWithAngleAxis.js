import_module('Athena.Math');

q = new Athena.Math.Quaternion(Math.PI / 2, Athena.Math.Vector3_UNIT_Y);

CHECK_CLOSE(0.707, q.w, 0.001);
CHECK_CLOSE(0, q.x);
CHECK_CLOSE(0.707, q.y, 0.001);
CHECK_CLOSE(0, q.z);

r = q.toAngleAxis();

CHECK_CLOSE(Math.PI / 2, r.angle);
CHECK_CLOSE(0.0, r.axis.x);
CHECK_CLOSE(1.0, r.axis.y);
CHECK_CLOSE(0.0, r.axis.z);

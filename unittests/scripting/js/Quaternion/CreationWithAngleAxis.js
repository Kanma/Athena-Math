import_module('Athena.Math');

q = new Athena.Math.Quaternion(Math.PI / 2, Athena.Math.Vector3_UNIT_Y);

CHECK_CLOSE(0.707, q.w, 0.001);
CHECK_CLOSE(0, q.x);
CHECK_CLOSE(0.707, q.y, 0.001);
CHECK_CLOSE(0, q.z);

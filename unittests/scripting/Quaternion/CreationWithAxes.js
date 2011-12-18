import_module('Athena.Math');

q = new Athena.Math.Quaternion(Athena.Math.Vector3_UNIT_X,
                               Athena.Math.Vector3_UNIT_Y,
                               Athena.Math.Vector3_UNIT_Z);

CHECK_CLOSE(1, q.w);
CHECK_CLOSE(0, q.x);
CHECK_CLOSE(0, q.y);
CHECK_CLOSE(0, q.z);

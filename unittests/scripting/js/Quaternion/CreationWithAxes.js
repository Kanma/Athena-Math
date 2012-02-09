import_module('Athena.Math');

q = new Athena.Math.Quaternion(Athena.Math.Vector3_UNIT_X,
                               Athena.Math.Vector3_UNIT_Y,
                               Athena.Math.Vector3_UNIT_Z);

CHECK_CLOSE(1, q.w);
CHECK_CLOSE(0, q.x);
CHECK_CLOSE(0, q.y);
CHECK_CLOSE(0, q.z);

r = q.toAxes();

CHECK_CLOSE(1.0, r.xaxis.x);
CHECK_CLOSE(0.0, r.xaxis.y);
CHECK_CLOSE(0.0, r.xaxis.z);

CHECK_CLOSE(0.0, r.yaxis.x);
CHECK_CLOSE(1.0, r.yaxis.y);
CHECK_CLOSE(0.0, r.yaxis.z);

CHECK_CLOSE(0.0, r.zaxis.x);
CHECK_CLOSE(0.0, r.zaxis.y);
CHECK_CLOSE(1.0, r.zaxis.z);

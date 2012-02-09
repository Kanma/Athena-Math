import_module('Athena.Math');

m = new Athena.Math.Matrix3();

m.fromEulerAnglesYZX(Math.PI / 2, 0.0, 0.0);
r = m.toEulerAnglesYZX();

CHECK_CLOSE(Math.PI / 2, r.yaw);
CHECK_CLOSE(0.0, r.pitch);
CHECK_CLOSE(0.0, r.roll);


m.fromEulerAnglesYZX(0.0, Math.PI / 2, 0.0);
r = m.toEulerAnglesYZX();

CHECK_CLOSE(0.0, r.yaw);
CHECK_CLOSE(Math.PI / 2, r.pitch);
CHECK_CLOSE(0.0, r.roll);


m.fromEulerAnglesYZX(0.0, 0.0, Math.PI / 2);
r = m.toEulerAnglesYZX();

CHECK_CLOSE(0.0, r.yaw);
CHECK_CLOSE(0.0, r.pitch);
CHECK_CLOSE(Math.PI / 2, r.roll);

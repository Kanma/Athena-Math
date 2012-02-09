import_module('Athena.Math');

m = new Athena.Math.Matrix3();

m.fromEulerAnglesZXY(Math.PI / 2, 0.0, 0.0);
r = m.toEulerAnglesZXY();

CHECK_CLOSE(Math.PI / 2, r.yaw);
CHECK_CLOSE(0.0, r.pitch);
CHECK_CLOSE(0.0, r.roll);


m.fromEulerAnglesZXY(0.0, Math.PI / 2, 0.0);
r = m.toEulerAnglesZXY();

CHECK_CLOSE(0.0, r.yaw);
CHECK_CLOSE(Math.PI / 2, r.pitch);
CHECK_CLOSE(0.0, r.roll);


m.fromEulerAnglesZXY(0.0, 0.0, Math.PI / 2);
r = m.toEulerAnglesZXY();

CHECK_CLOSE(0.0, r.yaw);
CHECK_CLOSE(0.0, r.pitch);
CHECK_CLOSE(Math.PI / 2, r.roll);

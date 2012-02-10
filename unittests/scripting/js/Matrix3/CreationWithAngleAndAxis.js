import_module('Athena.Math');

m = new Athena.Math.Matrix3(Athena.Math.Vector3_UNIT_X, Math.PI / 2);

r = m.toAxisAngle();

CHECK_CLOSE(Athena.Math.Vector3_UNIT_X.x, r.axis.x);
CHECK_CLOSE(Athena.Math.Vector3_UNIT_X.y, r.axis.y);
CHECK_CLOSE(Athena.Math.Vector3_UNIT_X.z, r.axis.z);
CHECK_CLOSE(Math.PI / 2, r.angle);


m = new Athena.Math.Matrix3(Athena.Math.Vector3_UNIT_Y, Math.PI / 2);

r = m.toAxisAngle();

CHECK_CLOSE(Athena.Math.Vector3_UNIT_Y.x, r.axis.x);
CHECK_CLOSE(Athena.Math.Vector3_UNIT_Y.y, r.axis.y);
CHECK_CLOSE(Athena.Math.Vector3_UNIT_Y.z, r.axis.z);
CHECK_CLOSE(Math.PI / 2, r.angle);


m = new Athena.Math.Matrix3(Athena.Math.Vector3_UNIT_Z, Math.PI / 2);

r = m.toAxisAngle();

CHECK_CLOSE(Athena.Math.Vector3_UNIT_Z.x, r.axis.x);
CHECK_CLOSE(Athena.Math.Vector3_UNIT_Z.y, r.axis.y);
CHECK_CLOSE(Athena.Math.Vector3_UNIT_Z.z, r.axis.z);
CHECK_CLOSE(Math.PI / 2, r.angle);

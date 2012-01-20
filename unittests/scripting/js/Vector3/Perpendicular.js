import_module('Athena.Math');

v1 = new Athena.Math.Vector3(0, 0, 1);

v = v1.perpendicular();

CHECK_CLOSE(1, v.length());
CHECK_CLOSE(0, v.z);

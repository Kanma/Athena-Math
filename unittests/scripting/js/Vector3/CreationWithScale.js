import_module('Athena.Math');

v = new Athena.Math.Vector3(10.0);

CHECK_CLOSE(10, v.x);
CHECK_CLOSE(10, v.y);
CHECK_CLOSE(10, v.z);

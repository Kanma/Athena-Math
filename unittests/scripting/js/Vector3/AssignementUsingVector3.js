import_module('Athena.Math');

v1 = new Athena.Math.Vector3(1, 2, 3);

v2 = new Athena.Math.Vector3();

v2.set(v1);

CHECK_CLOSE(v1.x, v2.x);
CHECK_CLOSE(v1.y, v2.y);
CHECK_CLOSE(v1.z, v2.z);

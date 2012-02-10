import_module('Athena.Math');

v1 = new Athena.Math.Vector4(1, 2, 3, 4);

v2 = new Athena.Math.Vector4(v1);

CHECK_CLOSE(v1.x, v2.x);
CHECK_CLOSE(v1.y, v2.y);
CHECK_CLOSE(v1.z, v2.z);
CHECK_CLOSE(v1.w, v2.w);

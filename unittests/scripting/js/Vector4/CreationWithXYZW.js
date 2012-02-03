import_module('Athena.Math');

v = new Athena.Math.Vector4(1, 2, 3, 4);

CHECK_CLOSE(1, v.x);
CHECK_CLOSE(2, v.y);
CHECK_CLOSE(3, v.z);
CHECK_CLOSE(4, v.w);

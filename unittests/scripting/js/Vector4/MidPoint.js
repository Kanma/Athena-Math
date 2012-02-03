import_module('Athena.Math');

v1 = new Athena.Math.Vector4(0, 1, 2, 3);
v2 = new Athena.Math.Vector4(4, 4, 4, 4);

v = v1.midPoint(v2);

CHECK_CLOSE(2, v.x);
CHECK_CLOSE(2.5, v.y);
CHECK_CLOSE(3, v.z);
CHECK_CLOSE(3.5, v.w);

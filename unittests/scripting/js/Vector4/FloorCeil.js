import_module('Athena.Math');

v1 = new Athena.Math.Vector4(0, 10, 2, 5);
v2 = new Athena.Math.Vector4(4, 4, 4, 4);

v = new Athena.Math.Vector4(v1);
v.makeFloor(v2);

CHECK_CLOSE(0, v.x);
CHECK_CLOSE(4, v.y);
CHECK_CLOSE(2, v.z);
CHECK_CLOSE(4, v.w);

v = new Athena.Math.Vector4(v1);
v.makeCeil(v2);

CHECK_CLOSE(4, v.x);
CHECK_CLOSE(10, v.y);
CHECK_CLOSE(4, v.z);
CHECK_CLOSE(5, v.w);

import_module('Athena.Math');

v = new Athena.Math.Vector4();

v.x = 1;
v.y = 2;
v.z = 3;
v.w = 4;

CHECK_CLOSE(1, v.x);
CHECK_CLOSE(2, v.y);
CHECK_CLOSE(3, v.z);
CHECK_CLOSE(4, v.w);

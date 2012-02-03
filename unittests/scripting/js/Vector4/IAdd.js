import_module('Athena.Math');

v1 = new Athena.Math.Vector4(10, 20, 30, 40);
v2 = new Athena.Math.Vector4(100, 200, 300, 400);
v3 = new Athena.Math.Vector4(1000, 2000, 3000, 4000);


v = new Athena.Math.Vector4(v1)
v.iadd(v2);

CHECK_CLOSE(110, v.x);
CHECK_CLOSE(220, v.y);
CHECK_CLOSE(330, v.z);
CHECK_CLOSE(440, v.w);

v = new Athena.Math.Vector4(v1)
v.iadd(v2, v3);

CHECK_CLOSE(1110, v.x);
CHECK_CLOSE(2220, v.y);
CHECK_CLOSE(3330, v.z);
CHECK_CLOSE(4440, v.w);

v.iadd(v);

CHECK_CLOSE(2220, v.x);
CHECK_CLOSE(4440, v.y);
CHECK_CLOSE(6660, v.z);
CHECK_CLOSE(8880, v.w);


v = new Athena.Math.Vector4(v1)
v.iadd(5);

CHECK_CLOSE(15, v.x);
CHECK_CLOSE(25, v.y);
CHECK_CLOSE(35, v.z);
CHECK_CLOSE(45, v.w);

import_module('Athena.Math');

v1 = new Athena.Math.Vector4(10, 20, 30, 40);
v2 = new Athena.Math.Vector4(100, 200, 300, 400);
v3 = new Athena.Math.Vector4(1000, 2000, 3000, 4000);


v = new Athena.Math.Vector4(v1)
v.imul(v2);

CHECK_CLOSE(1000, v.x);
CHECK_CLOSE(4000, v.y);
CHECK_CLOSE(9000, v.z);
CHECK_CLOSE(16000, v.w);

v = new Athena.Math.Vector4(v1)
v.imul(v2, v3);

CHECK_CLOSE(1000 * 1000, v.x);
CHECK_CLOSE(4000 * 2000, v.y);
CHECK_CLOSE(9000 * 3000, v.z);
CHECK_CLOSE(16000 * 4000, v.w);

v = new Athena.Math.Vector4(v1)
v.imul(v);

CHECK_CLOSE(100, v.x);
CHECK_CLOSE(400, v.y);
CHECK_CLOSE(900, v.z);
CHECK_CLOSE(1600, v.w);


v = new Athena.Math.Vector4(v1)
v.imul(2);

CHECK_CLOSE(20, v.x);
CHECK_CLOSE(40, v.y);
CHECK_CLOSE(60, v.z);
CHECK_CLOSE(80, v.w);

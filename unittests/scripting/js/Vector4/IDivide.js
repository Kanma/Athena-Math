import_module('Athena.Math');

v1 = new Athena.Math.Vector4(1000, 2000, 3000, 4000);
v2 = new Athena.Math.Vector4(100, 200, 300, 400);
v3 = new Athena.Math.Vector4(10, 20, 30, 40);


v = new Athena.Math.Vector4(v1)
v.idivide(v2);

CHECK_CLOSE(10, v.x);
CHECK_CLOSE(10, v.y);
CHECK_CLOSE(10, v.z);
CHECK_CLOSE(10, v.w);

v = new Athena.Math.Vector4(v1)
v.idivide(v2, v3);

CHECK_CLOSE(1 , v.x);
CHECK_CLOSE(0.5, v.y);
CHECK_CLOSE(0.3333333, v.z);
CHECK_CLOSE(0.25, v.w);

v.idivide(v);

CHECK_CLOSE(1, v.x);
CHECK_CLOSE(1, v.y);
CHECK_CLOSE(1, v.z);
CHECK_CLOSE(1, v.w);


v = new Athena.Math.Vector4(v1)
v.idivide(2);

CHECK_CLOSE(500, v.x);
CHECK_CLOSE(1000, v.y);
CHECK_CLOSE(1500, v.z);
CHECK_CLOSE(2000, v.w);

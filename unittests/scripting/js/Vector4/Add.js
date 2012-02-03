import_module('Athena.Math');

v1 = new Athena.Math.Vector4(10, 20, 30, 40);
v2 = new Athena.Math.Vector4(100, 200, 300, 400);
v3 = new Athena.Math.Vector4(1000, 2000, 3000, 4000);


v = v1.add(v2);

CHECK_CLOSE(110, v.x);
CHECK_CLOSE(220, v.y);
CHECK_CLOSE(330, v.z);
CHECK_CLOSE(440, v.w);

v = v1.add(v2, v3);

CHECK_CLOSE(1110, v.x);
CHECK_CLOSE(2220, v.y);
CHECK_CLOSE(3330, v.z);
CHECK_CLOSE(4440, v.w);

v = v.add(v1);

CHECK_CLOSE(1120, v.x);
CHECK_CLOSE(2240, v.y);
CHECK_CLOSE(3360, v.z);
CHECK_CLOSE(4480, v.w);

v = v1.add(5);

CHECK_CLOSE(15, v.x);
CHECK_CLOSE(25, v.y);
CHECK_CLOSE(35, v.z);
CHECK_CLOSE(45, v.w);

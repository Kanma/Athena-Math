import_module('Athena.Math');

v1 = new Athena.Math.Vector3(1000, 2000, 3000);
v2 = new Athena.Math.Vector3(100, 200, 300);
v3 = new Athena.Math.Vector3(10, 20, 30);


v = new Athena.Math.Vector3(v1)
v.isub(v2);

CHECK_CLOSE(900, v.x);
CHECK_CLOSE(1800, v.y);
CHECK_CLOSE(2700, v.z);

v = new Athena.Math.Vector3(v1)
v.isub(v2, v3);

CHECK_CLOSE(890, v.x);
CHECK_CLOSE(1780, v.y);
CHECK_CLOSE(2670, v.z);

v.isub(v);

CHECK_CLOSE(0, v.x);
CHECK_CLOSE(0, v.y);
CHECK_CLOSE(0, v.z);


v = new Athena.Math.Vector3(v1)
v.isub(5);

CHECK_CLOSE(995, v.x);
CHECK_CLOSE(1995, v.y);
CHECK_CLOSE(2995, v.z);

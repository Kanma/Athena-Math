import_module('Athena.Math');

v1 = new Athena.Math.Vector3(1000, 2000, 3000);
v2 = new Athena.Math.Vector3(100, 200, 300);
v3 = new Athena.Math.Vector3(10, 20, 30);


v = new Athena.Math.Vector3(v1)
v.idivide(v2);

CHECK_CLOSE(10, v.x);
CHECK_CLOSE(10, v.y);
CHECK_CLOSE(10, v.z);

v = new Athena.Math.Vector3(v1)
v.idivide(v2, v3);

CHECK_CLOSE(1 , v.x);
CHECK_CLOSE(0.5, v.y);
CHECK_CLOSE(0.3333333, v.z);

v.idivide(v);

CHECK_CLOSE(1, v.x);
CHECK_CLOSE(1, v.y);
CHECK_CLOSE(1, v.z);


v = new Athena.Math.Vector3(v1)
v.idivide(2);

CHECK_CLOSE(500, v.x);
CHECK_CLOSE(1000, v.y);
CHECK_CLOSE(1500, v.z);

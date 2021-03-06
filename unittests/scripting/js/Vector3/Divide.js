import_module('Athena.Math');

v1 = new Athena.Math.Vector3(1000, 2000, 3000);
v2 = new Athena.Math.Vector3(100, 200, 300);
v3 = new Athena.Math.Vector3(10, 20, 30);


v = v1.divide(v2);

CHECK_CLOSE(10, v.x);
CHECK_CLOSE(10, v.y);
CHECK_CLOSE(10, v.z);

v = v1.divide(v2, v3);

CHECK_CLOSE(1 , v.x);
CHECK_CLOSE(0.5, v.y);
CHECK_CLOSE(0.3333333, v.z);

v = v.divide(v1);

CHECK_CLOSE(0.001, v.x);
CHECK_CLOSE(0.00025, v.y);
CHECK_CLOSE(0.0001111111, v.z);


v = v1.divide(2);

CHECK_CLOSE(500, v.x);
CHECK_CLOSE(1000, v.y);
CHECK_CLOSE(1500, v.z);

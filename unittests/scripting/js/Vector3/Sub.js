import_module('Athena.Math');

v1 = new Athena.Math.Vector3(1000, 2000, 3000);
v2 = new Athena.Math.Vector3(100, 200, 300);
v3 = new Athena.Math.Vector3(10, 20, 30);


v = v1.sub(v2);

CHECK_CLOSE(900, v.x);
CHECK_CLOSE(1800, v.y);
CHECK_CLOSE(2700, v.z);

v = v1.sub(v2, v3);

CHECK_CLOSE(890, v.x);
CHECK_CLOSE(1780, v.y);
CHECK_CLOSE(2670, v.z);

v = v.sub(v1);

CHECK_CLOSE(-110, v.x);
CHECK_CLOSE(-220, v.y);
CHECK_CLOSE(-330, v.z);


v = v1.sub(5);

CHECK_CLOSE(995, v.x);
CHECK_CLOSE(1995, v.y);
CHECK_CLOSE(2995, v.z);

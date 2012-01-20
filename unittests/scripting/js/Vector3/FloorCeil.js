import_module('Athena.Math');

v1 = new Athena.Math.Vector3(0, 10, 2);
v2 = new Athena.Math.Vector3(4, 4, 4);

v = new Athena.Math.Vector3(v1);
v.makeFloor(v2);

CHECK_CLOSE(0, v.x);
CHECK_CLOSE(4, v.y);
CHECK_CLOSE(2, v.z);

v = new Athena.Math.Vector3(v1);
v.makeCeil(v2);

CHECK_CLOSE(4, v.x);
CHECK_CLOSE(10, v.y);
CHECK_CLOSE(4, v.z);

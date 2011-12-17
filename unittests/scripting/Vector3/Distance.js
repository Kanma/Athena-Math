import_module('Athena.Math');

v1 = new Athena.Math.Vector3(1, 0, 0);
v2 = new Athena.Math.Vector3(3, 0, 0);

CHECK_CLOSE(4, v1.squaredDistance(v2));
CHECK_CLOSE(2, v1.distance(v2));

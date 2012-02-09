import_module('Athena.Math');

p1 = new Athena.Math.Plane(1, 2, 3, 4);
p2 = new Athena.Math.Plane(p1);

CHECK_CLOSE(p1.normal.x, p2.normal.x);
CHECK_CLOSE(p1.normal.y, p2.normal.y);
CHECK_CLOSE(p1.normal.z, p2.normal.z);
CHECK_CLOSE(p1.d, p2.d);

import_module('Athena.Math');

p = new Athena.Math.Plane(1, 2, 3, 4);

CHECK_CLOSE(1, p.normal.x);
CHECK_CLOSE(2, p.normal.y);
CHECK_CLOSE(3, p.normal.z);
CHECK_CLOSE(4, p.d);

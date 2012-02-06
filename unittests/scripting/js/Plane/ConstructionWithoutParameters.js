import_module('Athena.Math');

p = new Athena.Math.Plane();

CHECK_CLOSE(0.0, p.normal.x);
CHECK_CLOSE(0.0, p.normal.y);
CHECK_CLOSE(0.0, p.normal.z);
CHECK_CLOSE(0.0, p.d);

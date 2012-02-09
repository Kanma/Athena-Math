import_module('Athena.Math');

p = new Athena.Math.Plane(new Athena.Math.Vector3(0, 1, 0), new Athena.Math.Vector3(2, 3, 4));

CHECK_CLOSE(0, p.normal.x);
CHECK_CLOSE(1, p.normal.y);
CHECK_CLOSE(0, p.normal.z);
CHECK_CLOSE(-3, p.d);


p = new Athena.Math.Plane(new Athena.Math.Vector3(1, 0, 0), new Athena.Math.Vector3(2, 3, 4));

CHECK_CLOSE(1, p.normal.x);
CHECK_CLOSE(0, p.normal.y);
CHECK_CLOSE(0, p.normal.z);
CHECK_CLOSE(-2, p.d);


p = new Athena.Math.Plane(new Athena.Math.Vector3(0, 0, 1), new Athena.Math.Vector3(2, 3, 4));

CHECK_CLOSE(0, p.normal.x);
CHECK_CLOSE(0, p.normal.y);
CHECK_CLOSE(1, p.normal.z);
CHECK_CLOSE(-4, p.d);

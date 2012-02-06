import_module('Athena.Math');

p = new Athena.Math.Plane(new Athena.Math.Vector3(0, 1, 0), new Athena.Math.Vector3(0, 5, 0));

v = p.projectVector(new Athena.Math.Vector3(1, 2, 3));

CHECK_CLOSE(1, v.x);
CHECK_CLOSE(0, v.y);
CHECK_CLOSE(3, v.z);


p = new Athena.Math.Plane(new Athena.Math.Vector3(1, 0, 0), new Athena.Math.Vector3(0, 5, 0));

v = p.projectVector(new Athena.Math.Vector3(1, 2, 3));

CHECK_CLOSE(0, v.x);
CHECK_CLOSE(2, v.y);
CHECK_CLOSE(3, v.z);


p = new Athena.Math.Plane(new Athena.Math.Vector3(0, 0, 1), new Athena.Math.Vector3(0, 5, 0));

v = p.projectVector(new Athena.Math.Vector3(1, 2, 3));

CHECK_CLOSE(1, v.x);
CHECK_CLOSE(2, v.y);
CHECK_CLOSE(0, v.z);

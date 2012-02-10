import_module('Athena.Math');

p = new Athena.Math.Plane(new Athena.Math.Vector3(0, 1, 0), new Athena.Math.Vector3(0, 5, 0));

CHECK_CLOSE(5.0, p.getDistance(new Athena.Math.Vector3(0, 10, 0)));
CHECK_CLOSE(5.0, p.getDistance(new Athena.Math.Vector3(5, 10, 4)));

import_module('Athena.Math');

p = new Athena.Math.Plane(new Athena.Math.Vector3(0, 1, 0), new Athena.Math.Vector3(0, 5, 0));

CHECK_EQUAL(Athena.Math.Plane_NEGATIVE_SIDE, p.getSide(new Athena.Math.Vector3(0, 0, 0), new Athena.Math.Vector3(1, 1, 1)));
CHECK_EQUAL(Athena.Math.Plane_POSITIVE_SIDE, p.getSide(new Athena.Math.Vector3(3, 10, 2), new Athena.Math.Vector3(1, 1, 1)));
CHECK_EQUAL(Athena.Math.Plane_BOTH_SIDE, p.getSide(new Athena.Math.Vector3(3, 5, 2), new Athena.Math.Vector3(1, 1, 1)));


p = new Athena.Math.Plane(new Athena.Math.Vector3(1, 0, 0), new Athena.Math.Vector3(5, 0, 0));

CHECK_EQUAL(Athena.Math.Plane_NEGATIVE_SIDE, p.getSide(new Athena.Math.Vector3(0, 0, 0), new Athena.Math.Vector3(1, 1, 1)));
CHECK_EQUAL(Athena.Math.Plane_POSITIVE_SIDE, p.getSide(new Athena.Math.Vector3(10, 3, 2), new Athena.Math.Vector3(1, 1, 1)));
CHECK_EQUAL(Athena.Math.Plane_BOTH_SIDE, p.getSide(new Athena.Math.Vector3(5, 3, 2), new Athena.Math.Vector3(1, 1, 1)));


p = new Athena.Math.Plane(new Athena.Math.Vector3(0, 0, 1), new Athena.Math.Vector3(0, 0, 5));

CHECK_EQUAL(Athena.Math.Plane_NEGATIVE_SIDE, p.getSide(new Athena.Math.Vector3(0, 0, 0), new Athena.Math.Vector3(1, 1, 1)));
CHECK_EQUAL(Athena.Math.Plane_POSITIVE_SIDE, p.getSide(new Athena.Math.Vector3(2, 3, 10), new Athena.Math.Vector3(1, 1, 1)));
CHECK_EQUAL(Athena.Math.Plane_BOTH_SIDE, p.getSide(new Athena.Math.Vector3(2, 3, 5), new Athena.Math.Vector3(1, 1, 1)));

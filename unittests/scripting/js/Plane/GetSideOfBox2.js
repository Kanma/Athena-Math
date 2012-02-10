import_module('Athena.Math');

p = new Athena.Math.Plane(new Athena.Math.Vector3(0, 1, 0), new Athena.Math.Vector3(0, 5, 0));

CHECK_EQUAL(Athena.Math.Plane_NEGATIVE_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1)));
CHECK_EQUAL(Athena.Math.Plane_POSITIVE_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(2, 9, 1, 4, 11, 3)));
CHECK_EQUAL(Athena.Math.Plane_BOTH_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(2, 4, 1, 4, 6, 3)));
CHECK_EQUAL(Athena.Math.Plane_NO_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL)));
CHECK_EQUAL(Athena.Math.Plane_BOTH_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE)));


p = new Athena.Math.Plane(new Athena.Math.Vector3(1, 0, 0), new Athena.Math.Vector3(5, 0, 0));

CHECK_EQUAL(Athena.Math.Plane_NEGATIVE_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1)));
CHECK_EQUAL(Athena.Math.Plane_POSITIVE_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(9, 2, 1, 11, 4, 3)));
CHECK_EQUAL(Athena.Math.Plane_BOTH_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(4, 2, 1, 6, 4, 3)));
CHECK_EQUAL(Athena.Math.Plane_NO_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL)));
CHECK_EQUAL(Athena.Math.Plane_BOTH_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE)));


p = new Athena.Math.Plane(new Athena.Math.Vector3(0, 0, 1), new Athena.Math.Vector3(0, 0, 5));

CHECK_EQUAL(Athena.Math.Plane_NEGATIVE_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1)));
CHECK_EQUAL(Athena.Math.Plane_POSITIVE_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(2, 1, 9, 4, 3, 11)));
CHECK_EQUAL(Athena.Math.Plane_BOTH_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(2, 1, 4, 4, 3, 6)));
CHECK_EQUAL(Athena.Math.Plane_NO_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL)));
CHECK_EQUAL(Athena.Math.Plane_BOTH_SIDE, p.getSide(new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE)));

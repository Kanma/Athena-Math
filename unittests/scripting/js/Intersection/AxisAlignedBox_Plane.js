import_module('Athena.Math');

aab1 = new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1);
aab2 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);
aab3 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);

plane1 = new Athena.Math.Plane(new Athena.Math.Vector3(1, 0, 0), 0);
plane2 = new Athena.Math.Plane(new Athena.Math.Vector3(1, 0, 0), 10);


CHECK(Athena.Math.intersects(aab1, plane1), "Athena.Math.intersects(aab1, plane1)");
CHECK(Athena.Math.intersects(plane1, aab1), "Athena.Math.intersects(plane1, aab1)");

CHECK(!Athena.Math.intersects(aab1, plane2), "!Athena.Math.intersects(aab1, plane2)");
CHECK(!Athena.Math.intersects(plane2, aab1), "!Athena.Math.intersects(plane2, aab1)");

CHECK(!Athena.Math.intersects(aab2, plane1), "!Athena.Math.intersects(aab2, plane1)");
CHECK(!Athena.Math.intersects(plane1, aab2), "!Athena.Math.intersects(plane1, aab2)");

CHECK(Athena.Math.intersects(aab3, plane1), "Athena.Math.intersects(aab3, plane1)");
CHECK(Athena.Math.intersects(plane1, aab3), "Athena.Math.intersects(plane1, aab3)");

CHECK(Athena.Math.intersects(aab3, plane2), "Athena.Math.intersects(aab3, plane2)");
CHECK(Athena.Math.intersects(plane2, aab3), "Athena.Math.intersects(plane2, aab3)");

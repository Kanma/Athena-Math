import_module('Athena.Math');

aab1 = new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1);
aab2 = new Athena.Math.AxisAlignedBox(0, 0, 0, 2, 2, 2);
aab3 = new Athena.Math.AxisAlignedBox(10, 10, 10, 20, 20, 20);
aab4 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);
aab5 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);


CHECK(Athena.Math.intersects(aab1, aab2), "Athena.Math.intersects(aab1, aab2)");
CHECK(Athena.Math.intersects(aab2, aab1), "Athena.Math.intersects(aab2, aab1)");

CHECK(!Athena.Math.intersects(aab1, aab3), "!Athena.Math.intersects(aab1, aab3)");
CHECK(!Athena.Math.intersects(aab3, aab1), "!Athena.Math.intersects(aab3, aab1)");

CHECK(!Athena.Math.intersects(aab1, aab4), "!Athena.Math.intersects(aab1, aab4)");
CHECK(!Athena.Math.intersects(aab4, aab1), "!Athena.Math.intersects(aab4, aab1)");

CHECK(Athena.Math.intersects(aab1, aab5), "Athena.Math.intersects(aab1, aab5)");
CHECK(Athena.Math.intersects(aab5, aab1), "Athena.Math.intersects(aab5, aab1)");

CHECK(!Athena.Math.intersects(aab5, aab4), "!Athena.Math.intersects(aab5, aab4)");
CHECK(!Athena.Math.intersects(aab4, aab5), "!Athena.Math.intersects(aab4, aab5)");

CHECK(Athena.Math.intersects(aab5, aab5), "Athena.Math.intersects(aab5, aab5)");
CHECK(Athena.Math.intersects(aab5, aab5), "Athena.Math.intersects(aab5, aab5)");

import_module('Athena.Math');

aab1 = new Athena.Math.AxisAlignedBox(-1, -2, -3, 1, 2, 3);
aab2 = new Athena.Math.AxisAlignedBox(0, 0, -4, 40, 1, 60);

intersection = aab1.intersection(aab2);

CHECK(intersection.isFinite(), "intersection.isFinite()");
CHECK_CLOSE(0.0, intersection.minimum.x);
CHECK_CLOSE(0.0, intersection.minimum.y);
CHECK_CLOSE(-3.0, intersection.minimum.z);
CHECK_CLOSE(1.0, intersection.maximum.x);
CHECK_CLOSE(1.0, intersection.maximum.y);
CHECK_CLOSE(3.0, intersection.maximum.z);


aab1 = new Athena.Math.AxisAlignedBox(-1, -2, -3, 1, 2, 3);
aab2 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);

intersection = aab1.intersection(aab2);
CHECK(intersection.isNull(), "intersection.isNull()");

intersection = aab2.intersection(aab1);
CHECK(intersection.isNull(), "intersection.isNull()");


aab1 = new Athena.Math.AxisAlignedBox(-1, -2, -3, 1, 2, 3);
aab2 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);

intersection = aab1.intersection(aab2);
CHECK(intersection.isFinite(), "intersection.isFinite()");
CHECK(intersection.equals(aab1), "intersection.equals(aab1)");

intersection = aab2.intersection(aab1);
CHECK(intersection.isFinite(), "intersection.isFinite()");
CHECK(intersection.equals(aab1), "intersection.equals(aab1)");

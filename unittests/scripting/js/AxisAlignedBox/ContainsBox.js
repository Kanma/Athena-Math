import_module('Athena.Math');

aab1 = new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1);
aab2 = new Athena.Math.AxisAlignedBox(-0.5, -0.5, -0.5, 0.5, 0.5, 0.5);
aab3 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);
aab4 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);

CHECK(aab1.contains(aab2), "aab1.contains(aab2)");
CHECK(!aab2.contains(aab1), "!aab2.contains(aab1)");

CHECK(aab1.contains(aab3), "aab1.contains(aab3)");
CHECK(!aab3.contains(aab1), "!aab3.contains(aab1)");

CHECK(!aab1.contains(aab4), "!aab1.contains(aab4)");
CHECK(aab4.contains(aab1), "aab4.contains(aab1)");

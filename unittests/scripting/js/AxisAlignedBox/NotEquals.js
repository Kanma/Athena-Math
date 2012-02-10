import_module('Athena.Math');

aab1 = new Athena.Math.AxisAlignedBox(1, 2, 3, 4, 5, 6);
aab2 = new Athena.Math.AxisAlignedBox(1, 2, 3, 4, 5, 6);
aab3 = new Athena.Math.AxisAlignedBox(1, 2, 30, 4, 5, 6);
aab4 = new Athena.Math.AxisAlignedBox(1, 2, 3, 4, 5, 60);

CHECK(aab1.notEquals(aab3), "aab1.notEquals(aab3)");
CHECK(aab1.notEquals(aab4), "aab1.notEquals(aab4)");
CHECK(!aab1.notEquals(aab2), "!aab1.notEquals(aab2)");

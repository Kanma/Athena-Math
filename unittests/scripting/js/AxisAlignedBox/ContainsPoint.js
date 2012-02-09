import_module('Athena.Math');

aab1 = new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1);
aab2 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);
aab3 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);

v1 = new Athena.Math.Vector3(0, 0, 0);
v2 = new Athena.Math.Vector3(10, 10, 10);

CHECK(aab1.contains(v1), "aab1.contains(v1)");
CHECK(!aab1.contains(v2), "!aab1.contains(v2)");

CHECK(!aab2.contains(v1), "aab2.contains(v2)");

CHECK(aab3.contains(v1), "aab3.contains(v1)");

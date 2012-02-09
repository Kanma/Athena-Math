import_module('Athena.Math');

aab = new Athena.Math.AxisAlignedBox();
CHECK(aab.isNull(), "aab.isNull()");

aab = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);
CHECK(aab.isNull(), "aab.isNull()");

aab = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);
aab.setNull();
CHECK(aab.isNull(), "aab.isNull()");

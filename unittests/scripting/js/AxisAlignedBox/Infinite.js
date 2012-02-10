import_module('Athena.Math');

aab = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);
CHECK(aab.isInfinite(), "aab.isInfinite()");

aab = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);
aab.setInfinite();
CHECK(aab.isInfinite(), "aab.isInfinite()");

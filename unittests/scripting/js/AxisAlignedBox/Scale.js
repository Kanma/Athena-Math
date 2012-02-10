import_module('Athena.Math');

aab = new Athena.Math.AxisAlignedBox(-1, -2, -3, 4, 5, 6);
aab.scale(2);

CHECK(aab.isFinite(), "aab.isFinite()");
CHECK_CLOSE(-2.0, aab.minimum.x);
CHECK_CLOSE(-4.0, aab.minimum.y);
CHECK_CLOSE(-6.0, aab.minimum.z);
CHECK_CLOSE(8.0, aab.maximum.x);
CHECK_CLOSE(10.0, aab.maximum.y);
CHECK_CLOSE(12.0, aab.maximum.z);

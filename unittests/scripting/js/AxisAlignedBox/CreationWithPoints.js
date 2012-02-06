import_module('Athena.Math');

aab = new Athena.Math.AxisAlignedBox(new Athena.Math.Vector3(1, 2, 3),
                                     new Athena.Math.Vector3(4, 5, 6));

CHECK(aab.isFinite(), "aab.isFinite()");
CHECK_CLOSE(1.0, aab.minimum.x);
CHECK_CLOSE(2.0, aab.minimum.y);
CHECK_CLOSE(3.0, aab.minimum.z);
CHECK_CLOSE(4.0, aab.maximum.x);
CHECK_CLOSE(5.0, aab.maximum.y);
CHECK_CLOSE(6.0, aab.maximum.z);

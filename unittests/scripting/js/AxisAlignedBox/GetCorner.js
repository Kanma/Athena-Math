import_module('Athena.Math');

aab = new Athena.Math.AxisAlignedBox(-1, -2, -3, 1, 2, 3);

v = aab.getCorner(Athena.Math.AxisAlignedBox_FAR_LEFT_BOTTOM);
CHECK_CLOSE(-1.0, v.x);
CHECK_CLOSE(-2.0, v.y);
CHECK_CLOSE(-3.0, v.z);

v = aab.getCorner(Athena.Math.AxisAlignedBox_FAR_LEFT_TOP);
CHECK_CLOSE(-1.0, v.x);
CHECK_CLOSE(2.0, v.y);
CHECK_CLOSE(-3.0, v.z);

v = aab.getCorner(Athena.Math.AxisAlignedBox_FAR_RIGHT_TOP);
CHECK_CLOSE(1.0, v.x);
CHECK_CLOSE(2.0, v.y);
CHECK_CLOSE(-3.0, v.z);

v = aab.getCorner(Athena.Math.AxisAlignedBox_FAR_RIGHT_BOTTOM);
CHECK_CLOSE(1.0, v.x);
CHECK_CLOSE(-2.0, v.y);
CHECK_CLOSE(-3.0, v.z);

v = aab.getCorner(Athena.Math.AxisAlignedBox_NEAR_RIGHT_BOTTOM);
CHECK_CLOSE(1.0, v.x);
CHECK_CLOSE(-2.0, v.y);
CHECK_CLOSE(3.0, v.z);

v = aab.getCorner(Athena.Math.AxisAlignedBox_NEAR_LEFT_BOTTOM);
CHECK_CLOSE(-1.0, v.x);
CHECK_CLOSE(-2.0, v.y);
CHECK_CLOSE(3.0, v.z);

v = aab.getCorner(Athena.Math.AxisAlignedBox_NEAR_LEFT_TOP);
CHECK_CLOSE(-1.0, v.x);
CHECK_CLOSE(2.0, v.y);
CHECK_CLOSE(3.0, v.z);

v = aab.getCorner(Athena.Math.AxisAlignedBox_NEAR_RIGHT_TOP);
CHECK_CLOSE(1.0, v.x);
CHECK_CLOSE(2.0, v.y);
CHECK_CLOSE(3.0, v.z);

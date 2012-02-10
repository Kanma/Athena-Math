import_module('Athena.Math');

aab1 = new Athena.Math.AxisAlignedBox(-1, -2, -3, 1, 2, 3);
aab2 = new Athena.Math.AxisAlignedBox(10, 20, 30, 40, 50, 60);

aab1.merge(aab2);

CHECK_CLOSE(-1.0, aab1.minimum.x);
CHECK_CLOSE(-2.0, aab1.minimum.y);
CHECK_CLOSE(-3.0, aab1.minimum.z);
CHECK_CLOSE(40.0, aab1.maximum.x);
CHECK_CLOSE(50.0, aab1.maximum.y);
CHECK_CLOSE(60.0, aab1.maximum.z);

aab3 = new Athena.Math.AxisAlignedBox(-10, -10, -10, 0, 0, 0);
aab4 = new Athena.Math.AxisAlignedBox(0, 0, 0, 100, 100, 100);

aab1.merge(aab3, aab4);

CHECK_CLOSE(-10.0, aab1.minimum.x);
CHECK_CLOSE(-10.0, aab1.minimum.y);
CHECK_CLOSE(-10.0, aab1.minimum.z);
CHECK_CLOSE(100.0, aab1.maximum.x);
CHECK_CLOSE(100.0, aab1.maximum.y);
CHECK_CLOSE(100.0, aab1.maximum.z);

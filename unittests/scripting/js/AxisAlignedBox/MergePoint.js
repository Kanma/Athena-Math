import_module('Athena.Math');

aab = new Athena.Math.AxisAlignedBox(-1, -2, -3, 1, 2, 3);
v = new Athena.Math.Vector3(40, 50, 60);

aab.merge(v);

CHECK_CLOSE(-1.0, aab.minimum.x);
CHECK_CLOSE(-2.0, aab.minimum.y);
CHECK_CLOSE(-3.0, aab.minimum.z);
CHECK_CLOSE(40.0, aab.maximum.x);
CHECK_CLOSE(50.0, aab.maximum.y);
CHECK_CLOSE(60.0, aab.maximum.z);

v2 = new Athena.Math.Vector3(-10, -10, -10);
v3 = new Athena.Math.Vector3(100, 100, 100);

aab.merge(v2, v3);

CHECK_CLOSE(-10.0, aab.minimum.x);
CHECK_CLOSE(-10.0, aab.minimum.y);
CHECK_CLOSE(-10.0, aab.minimum.z);
CHECK_CLOSE(100.0, aab.maximum.x);
CHECK_CLOSE(100.0, aab.maximum.y);
CHECK_CLOSE(100.0, aab.maximum.z);

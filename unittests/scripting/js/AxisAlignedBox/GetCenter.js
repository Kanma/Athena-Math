import_module('Athena.Math');

aab = new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1);

center = aab.getCenter();

CHECK_CLOSE(0.0, center.x);
CHECK_CLOSE(0.0, center.y);
CHECK_CLOSE(0.0, center.z);


aab = new Athena.Math.AxisAlignedBox(0, 0, 0, 10, 20, 30);

center = aab.getCenter();

CHECK_CLOSE(5.0, center.x);
CHECK_CLOSE(10.0, center.y);
CHECK_CLOSE(15.0, center.z);

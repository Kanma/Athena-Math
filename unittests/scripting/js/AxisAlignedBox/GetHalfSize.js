import_module('Athena.Math');

aab = new Athena.Math.AxisAlignedBox(-1, -2, -3, 1, 2, 3);

size = aab.getHalfSize();

CHECK_CLOSE(1.0, size.x);
CHECK_CLOSE(2.0, size.y);
CHECK_CLOSE(3.0, size.z);


aab = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);

size = aab.getHalfSize();

CHECK_CLOSE(0.0, size.x);
CHECK_CLOSE(0.0, size.y);
CHECK_CLOSE(0.0, size.z);


aab = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);

size = aab.getHalfSize();

CHECK_CLOSE(Infinity, size.x);
CHECK_CLOSE(Infinity, size.y);
CHECK_CLOSE(Infinity, size.z);

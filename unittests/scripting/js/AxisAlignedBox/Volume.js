import_module('Athena.Math');

aab = new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1);
CHECK_CLOSE(8.0, aab.volume());


aab = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);
CHECK_CLOSE(0.0, aab.volume());


aab = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);
CHECK_CLOSE(Infinity, aab.volume());

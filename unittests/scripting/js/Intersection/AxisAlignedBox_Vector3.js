import_module('Athena.Math');

aab1 = new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1);
aab2 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);
aab3 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);

vector1 = new Athena.Math.Vector3(0, 0, 0);
vector2 = new Athena.Math.Vector3(10, 0, 0);


CHECK(Athena.Math.intersects(aab1, vector1), "Athena.Math.intersects(aab1, vector1)");
CHECK(Athena.Math.intersects(vector1, aab1), "Athena.Math.intersects(vector1, aab1)");

CHECK(!Athena.Math.intersects(aab1, vector2), "!Athena.Math.intersects(aab1, vector2)");
CHECK(!Athena.Math.intersects(vector2, aab1), "!Athena.Math.intersects(vector2, aab1)");

CHECK(!Athena.Math.intersects(aab2, vector1), "!Athena.Math.intersects(aab2, vector1)");
CHECK(!Athena.Math.intersects(vector1, aab2), "!Athena.Math.intersects(vector1, aab2)");

CHECK(Athena.Math.intersects(aab3, vector1), "Athena.Math.intersects(aab3, vector1)");
CHECK(Athena.Math.intersects(vector1, aab3), "Athena.Math.intersects(vector1, aab3)");

CHECK(Athena.Math.intersects(aab3, vector2), "Athena.Math.intersects(aab3, vector2)");
CHECK(Athena.Math.intersects(vector2, aab3), "Athena.Math.intersects(vector2, aab3)");

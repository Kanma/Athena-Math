import_module('Athena.Math');

aab1 = new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1);
aab2 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);
aab3 = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);

sphere1 = new Athena.Math.Sphere(new Athena.Math.Vector3(0, 0, 0), 0.2);
sphere2 = new Athena.Math.Sphere(new Athena.Math.Vector3(10, 0, 0), 0.2);


CHECK(Athena.Math.intersects(aab1, sphere1), "Athena.Math.intersects(aab1, sphere1)");
CHECK(Athena.Math.intersects(sphere1, aab1), "Athena.Math.intersects(sphere1, aab1)");

CHECK(!Athena.Math.intersects(aab1, sphere2), "!Athena.Math.intersects(aab1, sphere2)");
CHECK(!Athena.Math.intersects(sphere2, aab1), "!Athena.Math.intersects(sphere2, aab1)");

CHECK(!Athena.Math.intersects(aab2, sphere1), "!Athena.Math.intersects(aab2, sphere1)");
CHECK(!Athena.Math.intersects(sphere1, aab2), "!Athena.Math.intersects(sphere1, aab2)");

CHECK(Athena.Math.intersects(aab3, sphere1), "Athena.Math.intersects(aab3, sphere1)");
CHECK(Athena.Math.intersects(sphere1, aab3), "Athena.Math.intersects(sphere1, aab3)");

CHECK(Athena.Math.intersects(aab3, sphere2), "Athena.Math.intersects(aab3, sphere2)");
CHECK(Athena.Math.intersects(sphere2, aab3), "Athena.Math.intersects(sphere2, aab3)");

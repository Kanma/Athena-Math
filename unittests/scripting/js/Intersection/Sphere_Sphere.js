import_module('Athena.Math');

sphere1 = new Athena.Math.Sphere(new Athena.Math.Vector3(0, 0, 0), 1);
sphere2 = new Athena.Math.Sphere(new Athena.Math.Vector3(0.5, 0, 0), 2);
sphere3 = new Athena.Math.Sphere(new Athena.Math.Vector3(10, 0, 0), 1);


CHECK(Athena.Math.intersects(sphere1, sphere2), "Athena.Math.intersects(sphere1, sphere2)");
CHECK(Athena.Math.intersects(sphere2, sphere1), "Athena.Math.intersects(sphere2, sphere1)");

CHECK(!Athena.Math.intersects(sphere1, sphere3), "!Athena.Math.intersects(sphere1, sphere3)");
CHECK(!Athena.Math.intersects(sphere3, sphere1), "!Athena.Math.intersects(sphere3, sphere1)");

import_module('Athena.Math');

sphere = new Athena.Math.Sphere(new Athena.Math.Vector3(0, 0, 0), 1);
plane1 = new Athena.Math.Plane(new Athena.Math.Vector3(1, 0, 0), 0);
plane2 = new Athena.Math.Plane(new Athena.Math.Vector3(1, 0, 0), 10);


CHECK(Athena.Math.intersects(sphere, plane1), "Athena.Math.intersects(sphere, plane1)");
CHECK(Athena.Math.intersects(plane1, sphere), "Athena.Math.intersects(plane1, sphere)");

CHECK(!Athena.Math.intersects(sphere, plane2), "!Athena.Math.intersects(sphere, plane2)");
CHECK(!Athena.Math.intersects(plane2, sphere), "!Athena.Math.intersects(plane2, sphere)");

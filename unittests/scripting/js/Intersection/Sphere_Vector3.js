import_module('Athena.Math');

sphere = new Athena.Math.Sphere(new Athena.Math.Vector3(0, 0, 0), 1);
vector1 = new Athena.Math.Vector3(1, 0, 0);
vector2 = new Athena.Math.Vector3(10, 0, 0);


CHECK(Athena.Math.intersects(sphere, vector1), "Athena.Math.intersects(sphere, vector1)");
CHECK(Athena.Math.intersects(vector1, sphere), "Athena.Math.intersects(vector1, sphere)");

CHECK(!Athena.Math.intersects(sphere, vector2), "!Athena.Math.intersects(sphere, vector2)");
CHECK(!Athena.Math.intersects(vector2, sphere), "!Athena.Math.intersects(vector2, sphere)");

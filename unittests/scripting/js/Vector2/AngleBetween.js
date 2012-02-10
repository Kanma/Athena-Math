import_module('Athena.Math');

v1 = new Athena.Math.Vector2(1, 0);
v2 = new Athena.Math.Vector2(0, 1);

CHECK_CLOSE(Math.PI / 2, v1.angleBetween(v2));

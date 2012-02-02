import_module('Athena.Math');

v1 = new Athena.Math.Vector2(1, 0);
v2 = v1.randomDeviant(Math.PI / 2);

CHECK_CLOSE(Math.PI / 2, v2.angleBetween(v1));

import_module('Athena.Math');

v1 = new Athena.Math.Vector3(1, 0, 0);
v2 = new Athena.Math.Vector3(0, 1, 0);

CHECK_CLOSE(Math.PI / 2, v1.angleBetween(v2));

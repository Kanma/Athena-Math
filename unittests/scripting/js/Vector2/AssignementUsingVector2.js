import_module('Athena.Math');

v1 = new Athena.Math.Vector2(1, 2);

v2 = new Athena.Math.Vector2();

v2.set(v1);

CHECK_CLOSE(v1.x, v2.x);
CHECK_CLOSE(v1.y, v2.y);

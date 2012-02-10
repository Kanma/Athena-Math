import_module('Athena.Math');

v = new Athena.Math.Vector2();

v.set(10);

CHECK_CLOSE(10, v.x);
CHECK_CLOSE(10, v.y);

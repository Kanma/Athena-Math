import_module('Athena.Math');

v = new Athena.Math.Vector2();

v.x = 1;
v.y = 2;

CHECK_CLOSE(1, v.x);
CHECK_CLOSE(2, v.y);

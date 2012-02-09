import_module('Athena.Math');

v1 = new Athena.Math.Vector2(0, 1);
v2 = new Athena.Math.Vector2(4, 4);

v = v1.midPoint(v2);

CHECK_CLOSE(2, v.x);
CHECK_CLOSE(2.5, v.y);

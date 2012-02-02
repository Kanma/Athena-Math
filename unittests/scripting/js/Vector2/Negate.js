import_module('Athena.Math');

v1 = new Athena.Math.Vector2(10, 20);

v = v1.negate();

CHECK_CLOSE(-10, v.x);
CHECK_CLOSE(-20, v.y);

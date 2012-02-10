import_module('Athena.Math');

v1 = new Athena.Math.Vector2(1, 2);
v2 = new Athena.Math.Vector2(-1, -2);

CHECK_CLOSE(-5, v1.dot(v2));
CHECK_CLOSE(5, v1.absDot(v2));

import_module('Athena.Math');

v1 = new Athena.Math.Vector2(10, 20);
v2 = new Athena.Math.Vector2(100, 200);
v3 = new Athena.Math.Vector2(1000, 2000);


v = new Athena.Math.Vector2(v1)
v.iadd(v2);

CHECK_CLOSE(110, v.x);
CHECK_CLOSE(220, v.y);

v = new Athena.Math.Vector2(v1)
v.iadd(v2, v3);

CHECK_CLOSE(1110, v.x);
CHECK_CLOSE(2220, v.y);

v.iadd(v);

CHECK_CLOSE(2220, v.x);
CHECK_CLOSE(4440, v.y);

v = new Athena.Math.Vector2(v1)
v.iadd(5);

CHECK_CLOSE(15, v.x);
CHECK_CLOSE(25, v.y);

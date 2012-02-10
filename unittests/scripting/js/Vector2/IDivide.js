import_module('Athena.Math');

v1 = new Athena.Math.Vector2(1000, 2000);
v2 = new Athena.Math.Vector2(100, 200);
v3 = new Athena.Math.Vector2(10, 20);


v = new Athena.Math.Vector2(v1)
v.idivide(v2);

CHECK_CLOSE(10, v.x);
CHECK_CLOSE(10, v.y);

v = new Athena.Math.Vector2(v1)
v.idivide(v2, v3);

CHECK_CLOSE(1 , v.x);
CHECK_CLOSE(0.5, v.y);

v.idivide(v);

CHECK_CLOSE(1, v.x);
CHECK_CLOSE(1, v.y);

v = new Athena.Math.Vector2(v1)
v.idivide(2);

CHECK_CLOSE(500, v.x);
CHECK_CLOSE(1000, v.y);

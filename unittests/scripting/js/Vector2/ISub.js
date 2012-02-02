import_module('Athena.Math');

v1 = new Athena.Math.Vector2(1000, 2000);
v2 = new Athena.Math.Vector2(100, 200);
v3 = new Athena.Math.Vector2(10, 20);


v = new Athena.Math.Vector2(v1)
v.isub(v2);

CHECK_CLOSE(900, v.x);
CHECK_CLOSE(1800, v.y);

v = new Athena.Math.Vector2(v1)
v.isub(v2, v3);

CHECK_CLOSE(890, v.x);
CHECK_CLOSE(1780, v.y);

v.isub(v);

CHECK_CLOSE(0, v.x);
CHECK_CLOSE(0, v.y);

v = new Athena.Math.Vector2(v1)
v.isub(5);

CHECK_CLOSE(995, v.x);
CHECK_CLOSE(1995, v.y);

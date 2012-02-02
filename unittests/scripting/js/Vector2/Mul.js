import_module('Athena.Math');

v1 = new Athena.Math.Vector2(10, 20);
v2 = new Athena.Math.Vector2(100, 200);
v3 = new Athena.Math.Vector2(1000, 2000);


v = v1.mul(v2);

CHECK_CLOSE(1000, v.x);
CHECK_CLOSE(4000, v.y);

v = v1.mul(v2, v3);

CHECK_CLOSE(1000 * 1000, v.x);
CHECK_CLOSE(4000 * 2000, v.y);

v = v.mul(v1);

CHECK_CLOSE(10 * 1000 * 1000, v.x);
CHECK_CLOSE(20 * 4000 * 2000, v.y);

v = v1.mul(2);

CHECK_CLOSE(20, v.x);
CHECK_CLOSE(40, v.y);

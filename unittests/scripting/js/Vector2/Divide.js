import_module('Athena.Math');

v1 = new Athena.Math.Vector2(1000, 2000);
v2 = new Athena.Math.Vector2(100, 200);
v3 = new Athena.Math.Vector2(10, 20);


v = v1.divide(v2);

CHECK_CLOSE(10, v.x);
CHECK_CLOSE(10, v.y);

v = v1.divide(v2, v3);

CHECK_CLOSE(1 , v.x);
CHECK_CLOSE(0.5, v.y);

v = v.divide(v1);

CHECK_CLOSE(0.001, v.x);
CHECK_CLOSE(0.00025, v.y);

v = v1.divide(2);

CHECK_CLOSE(500, v.x);
CHECK_CLOSE(1000, v.y);

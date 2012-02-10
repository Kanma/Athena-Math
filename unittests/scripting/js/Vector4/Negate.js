import_module('Athena.Math');

v1 = new Athena.Math.Vector4(10, 20, 30, 40);

v = v1.negate();

CHECK_CLOSE(-10, v.x);
CHECK_CLOSE(-20, v.y);
CHECK_CLOSE(-30, v.z);
CHECK_CLOSE(-40, v.w);

import_module('Athena.Math');

v1 = new Athena.Math.Vector3(10, 20, 30);

v = v1.negate();

CHECK_CLOSE(-10, v.x);
CHECK_CLOSE(-20, v.y);
CHECK_CLOSE(-30, v.z);

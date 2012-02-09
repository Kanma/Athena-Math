import_module('Athena.Math');

v1 = new Athena.Math.Vector4(1, 2, 3, 4);
v2 = new Athena.Math.Vector4(-1, -2, -3, -4);

CHECK_CLOSE(-30, v1.dot(v2));
CHECK_CLOSE(30, v1.absDot(v2));

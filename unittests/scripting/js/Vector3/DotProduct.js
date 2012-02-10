import_module('Athena.Math');

v1 = new Athena.Math.Vector3(1, 2, 3);
v2 = new Athena.Math.Vector3(-1, -2, -3);

CHECK_CLOSE(-14, v1.dot(v2));
CHECK_CLOSE(14, v1.absDot(v2));

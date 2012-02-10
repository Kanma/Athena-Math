import_module('Athena.Math');

v = new Athena.Math.Vector3(10, 0, 0);

length = v.normalise();

CHECK_CLOSE(10, length);
CHECK_CLOSE(1, v.x);
CHECK_CLOSE(0, v.y);
CHECK_CLOSE(0, v.z);


v = new Athena.Math.Vector3(10, 0, 0);

v2 = v.normalisedCopy();

CHECK_CLOSE(1, v2.length());
CHECK_CLOSE(1, v2.x);
CHECK_CLOSE(0, v2.y);
CHECK_CLOSE(0, v2.z);

CHECK_CLOSE(10, v.length());
CHECK_CLOSE(10, v.x);
CHECK_CLOSE(0, v.y);
CHECK_CLOSE(0, v.z);

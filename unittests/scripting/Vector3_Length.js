import_module('Athena.Math');

v = new Athena.Math.Vector3(10, 20, 30);

squared_length = v.squaredLength();

CHECK_CLOSE(10 * 10 + 20 * 20 + 30 * 30, squared_length, 0.001);

length = v.length();

CHECK_CLOSE(squared_length, length * length, 0.001);

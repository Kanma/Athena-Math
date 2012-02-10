import_module('Athena.Math');

v = new Athena.Math.Vector4(10, 20, 30, 40);

squared_length = v.squaredLength();

CHECK_CLOSE(10 * 10 + 20 * 20 + 30 * 30 + 40 * 40, squared_length, 0.001);

length = v.length();

CHECK_CLOSE(squared_length, length * length, 0.001);

CHECK(!v.isZeroLength(), "!v.isZeroLength()");

v = new Athena.Math.Vector4(0, 0, 0, 0);

CHECK(v.isZeroLength(), "v.isZeroLength()");

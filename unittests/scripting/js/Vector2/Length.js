import_module('Athena.Math');

v = new Athena.Math.Vector2(10, 20);

squared_length = v.squaredLength();

CHECK_CLOSE(10 * 10 + 20 * 20, squared_length, 0.001);

length = v.length();

CHECK_CLOSE(squared_length, length * length, 0.001);

CHECK(!v.isZeroLength(), "!v.isZeroLength()");

v = new Athena.Math.Vector2(0, 0);

CHECK(v.isZeroLength(), "v.isZeroLength()");

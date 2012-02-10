import_module('Athena.Math');

v = new Athena.Math.Vector2(0, 0);
CHECK(v.equals(Athena.Math.Vector2_ZERO), "v.equals(Athena.Math.Vector2_ZERO)");

v = new Athena.Math.Vector2(1, 0);
CHECK(v.equals(Athena.Math.Vector2_UNIT_X), "v.equals(Athena.Math.Vector2_UNIT_X)");

v = new Athena.Math.Vector2(0, 1);
CHECK(v.equals(Athena.Math.Vector2_UNIT_Y), "v.equals(Athena.Math.Vector2_UNIT_Y)");

v = new Athena.Math.Vector2(-1, 0);
CHECK(v.equals(Athena.Math.Vector2_NEGATIVE_UNIT_X), "v.equals(Athena.Math.Vector2_NEGATIVE_UNIT_X)");

v = new Athena.Math.Vector2(0, -1);
CHECK(v.equals(Athena.Math.Vector2_NEGATIVE_UNIT_Y), "v.equals(Athena.Math.Vector2_NEGATIVE_UNIT_Y)");

v = new Athena.Math.Vector2(1, 1);
CHECK(v.equals(Athena.Math.Vector2_UNIT_SCALE), "v.equals(Athena.Math.Vector2_UNIT_SCALE)");

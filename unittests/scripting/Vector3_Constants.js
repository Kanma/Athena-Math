import_module('Athena.Math');

v = new Athena.Math.Vector3(0, 0, 0);
CHECK(v.equals(Athena.Math.Vector3_ZERO), "v.equals(Athena.Math.Vector3_ZERO)");

v = new Athena.Math.Vector3(1, 0, 0);
CHECK(v.equals(Athena.Math.Vector3_UNIT_X), "v.equals(Athena.Math.Vector3_UNIT_X)");

v = new Athena.Math.Vector3(0, 1, 0);
CHECK(v.equals(Athena.Math.Vector3_UNIT_Y), "v.equals(Athena.Math.Vector3_UNIT_Y)");

v = new Athena.Math.Vector3(0, 0, 1);
CHECK(v.equals(Athena.Math.Vector3_UNIT_Z), "v.equals(Athena.Math.Vector3_UNIT_Z)");

v = new Athena.Math.Vector3(-1, 0, 0);
CHECK(v.equals(Athena.Math.Vector3_NEGATIVE_UNIT_X), "v.equals(Athena.Math.Vector3_NEGATIVE_UNIT_X)");

v = new Athena.Math.Vector3(0, -1, 0);
CHECK(v.equals(Athena.Math.Vector3_NEGATIVE_UNIT_Y), "v.equals(Athena.Math.Vector3_NEGATIVE_UNIT_Y)");

v = new Athena.Math.Vector3(0, 0, -1);
CHECK(v.equals(Athena.Math.Vector3_NEGATIVE_UNIT_Z), "v.equals(Athena.Math.Vector3_NEGATIVE_UNIT_Z)");

v = new Athena.Math.Vector3(1, 1, 1);
CHECK(v.equals(Athena.Math.Vector3_UNIT_SCALE), "v.equals(Athena.Math.Vector3_UNIT_SCALE)");

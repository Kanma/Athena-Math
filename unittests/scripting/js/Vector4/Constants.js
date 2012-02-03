import_module('Athena.Math');

v = new Athena.Math.Vector4(0, 0, 0, 0);
CHECK(v.equals(Athena.Math.Vector4_ZERO), "v.equals(Athena.Math.Vector4_ZERO)");

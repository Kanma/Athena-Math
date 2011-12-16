import_module('Athena.Math');

v = new Athena.Math.Vector3(0, 0, 0);

CHECK(v.equals(Athena.Math.Vector3.ZERO()), "v.equals(Athena.Math.Vector3.ZERO())");

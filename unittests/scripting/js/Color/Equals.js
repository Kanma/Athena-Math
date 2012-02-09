import_module('Athena.Math');

c1 = new Athena.Math.Color(0.1, 0.2, 0.3);
c2 = new Athena.Math.Color(0.1, 0.2, 0.3);
c3 = new Athena.Math.Color(0.1, 0.2, 0.35);

CHECK(c1.equals(c2), "c1.equals(c2)");
CHECK(!c1.equals(c3), "!c1.equals(c3)");

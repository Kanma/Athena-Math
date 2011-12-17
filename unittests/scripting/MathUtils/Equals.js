import_module('Athena.Math');


CHECK(Athena.Math.equals(2.0, 2.00000001), "Athena.Math.equals(2.0, 2.00000001)");
CHECK(!Athena.Math.equals(2.0, 2.1), "!Athena.Math.equals(2.0, 2.1)");
CHECK(Athena.Math.equals(2.0, 2.1, 0.2), "Athena.Math.equals(2.0, 2.1, 0.2)");

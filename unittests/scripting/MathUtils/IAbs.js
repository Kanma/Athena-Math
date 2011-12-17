import_module('Athena.Math');


n = Athena.Math.iabs(10);
CHECK_EQUAL(10, n);

n = Athena.Math.iabs(-20);
CHECK_EQUAL(20, n);

n = Athena.Math.iabs(-10.4);
CHECK_EQUAL(10, n);

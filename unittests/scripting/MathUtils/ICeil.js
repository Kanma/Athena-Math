import_module('Athena.Math');


n = Athena.Math.iceil(10.4);
CHECK_EQUAL(11, n);

n = Athena.Math.iceil(-20.4);
CHECK_EQUAL(-20, n);

import_module('Athena.Math');


n = Athena.Math.isign(10);
CHECK_EQUAL(1, n);

n = Athena.Math.isign(-20);
CHECK_EQUAL(-1, n);

n = Athena.Math.isign(-10.4);
CHECK_EQUAL(-1, n);

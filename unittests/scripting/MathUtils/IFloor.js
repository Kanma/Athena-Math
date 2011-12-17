import_module('Athena.Math');


n = Athena.Math.ifloor(10.4);
CHECK_EQUAL(10, n);

n = Athena.Math.ifloor(-20.4);
CHECK_EQUAL(-21, n);

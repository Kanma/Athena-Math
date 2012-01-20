import_module('Athena.Math');


n = Athena.Math.logn(10, 1);
CHECK_CLOSE(0.0, n);

n = Athena.Math.logn(10, 2);
CHECK_CLOSE(0.3010299, n);

n = Athena.Math.logn(10, 10);
CHECK_CLOSE(1.0, n);

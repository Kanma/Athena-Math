import_module('Athena.Math');


n = Athena.Math.invsqrt(4);
CHECK_CLOSE(0.5, n);

n = Athena.Math.invsqrt(100);
CHECK_CLOSE(0.1, n);

import_module('Athena.Math');


n = Athena.Math.exp(0);
CHECK_CLOSE(1, n);

n = Athena.Math.exp(1);
CHECK_CLOSE(2.7182818, n);

n = Athena.Math.exp(-1);
CHECK_CLOSE(0.3678794, n);

import_module('Athena.Math');


n = Athena.Math.sqr(2);
CHECK_CLOSE(4.0, n);

n = Athena.Math.sqr(10);
CHECK_CLOSE(100.0, n);

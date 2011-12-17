import_module('Athena.Math');


n = Athena.Math.abs(10.5);
CHECK_CLOSE(10.5, n);

n = Athena.Math.abs(-20.4);
CHECK_CLOSE(20.4, n);

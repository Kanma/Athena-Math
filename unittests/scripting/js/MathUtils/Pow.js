import_module('Athena.Math');


n = Athena.Math.pow(2, 1);
CHECK_CLOSE(2.0, n);

n = Athena.Math.pow(10, 2);
CHECK_CLOSE(100.0, n);

n = Athena.Math.pow(2, 10);
CHECK_CLOSE(1024.0, n);

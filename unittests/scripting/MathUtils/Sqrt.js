import_module('Athena.Math');


n = Athena.Math.sqrt(4);
CHECK_CLOSE(2.0, n);

n = Athena.Math.sqrt(100);
CHECK_CLOSE(10.0, n);

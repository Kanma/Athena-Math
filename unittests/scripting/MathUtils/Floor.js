import_module('Athena.Math');


n = Athena.Math.floor(10.4);
CHECK_CLOSE(10.0, n);

n = Athena.Math.floor(-20.4);
CHECK_CLOSE(-21.0, n);

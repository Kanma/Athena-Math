import_module('Athena.Math');


n = Athena.Math.sign(10.4);
CHECK_CLOSE(1.0, n);

n = Athena.Math.sign(-20.4);
CHECK_CLOSE(-1.0, n);

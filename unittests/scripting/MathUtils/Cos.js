import_module('Athena.Math');


n = Athena.Math.cos(Athena.Math.HALF_PI);
CHECK_CLOSE(0.0, n);

n = Athena.Math.cos(0.0);
CHECK_CLOSE(1.0, n);

n = Athena.Math.cos(Athena.Math.PI);
CHECK_CLOSE(-1.0, n);

import_module('Athena.Math');


n = Athena.Math.sin(0.0);
CHECK_CLOSE(0.0, n);

n = Athena.Math.sin(Athena.Math.HALF_PI);
CHECK_CLOSE(1.0, n);

n = Athena.Math.sin(-Athena.Math.HALF_PI);
CHECK_CLOSE(-1.0, n);

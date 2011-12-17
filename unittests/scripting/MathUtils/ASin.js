import_module('Athena.Math');


n = Athena.Math.asin(0.0);
CHECK_CLOSE(0.0, n);

n = Athena.Math.asin(1.0);
CHECK_CLOSE(Athena.Math.HALF_PI, n);

n = Athena.Math.asin(-1.0);
CHECK_CLOSE(-Athena.Math.HALF_PI, n);

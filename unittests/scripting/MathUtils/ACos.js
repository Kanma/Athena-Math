import_module('Athena.Math');


n = Athena.Math.acos(0.0);
CHECK_CLOSE(Athena.Math.HALF_PI, n);

n = Athena.Math.acos(1.0);
CHECK_CLOSE(0.0, n);

n = Athena.Math.acos(-1.0);
CHECK_CLOSE(Athena.Math.PI, n);

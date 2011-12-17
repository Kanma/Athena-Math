import_module('Athena.Math');


n = Athena.Math.tan(0.0);
CHECK_CLOSE(0.0, n);

n = Athena.Math.tan(Athena.Math.HALF_PI / 2);
CHECK_CLOSE(1.0, n);

n = Athena.Math.tan(Athena.Math.HALF_PI * 2 / 3);
CHECK_CLOSE(Athena.Math.sqrt(3), n);

n = Athena.Math.tan(Athena.Math.HALF_PI / 3);
CHECK_CLOSE(Athena.Math.sqrt(3) / 3, n);

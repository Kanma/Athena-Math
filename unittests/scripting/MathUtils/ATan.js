import_module('Athena.Math');


n = Athena.Math.atan(0.0);
CHECK_CLOSE(0.0, n);

n = Athena.Math.atan(1.0);
CHECK_CLOSE(Athena.Math.HALF_PI / 2, n);

n = Athena.Math.atan(Athena.Math.sqrt(3));
CHECK_CLOSE(Athena.Math.HALF_PI * 2 / 3, n);

n = Athena.Math.atan(Athena.Math.sqrt(3) / 3);
CHECK_CLOSE(Athena.Math.HALF_PI / 3, n);


n = Athena.Math.atan2(0.0, 1.0);
CHECK_CLOSE(0.0, n);

n = Athena.Math.atan2(1.0, 1.0);
CHECK_CLOSE(Athena.Math.HALF_PI / 2, n);

n = Athena.Math.atan2(Athena.Math.sqrt(3), 1.0);
CHECK_CLOSE(Athena.Math.HALF_PI * 2 / 3, n);

n = Athena.Math.atan2(Athena.Math.sqrt(3), 3.0);
CHECK_CLOSE(Athena.Math.HALF_PI / 3, n);

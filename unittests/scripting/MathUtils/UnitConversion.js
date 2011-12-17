import_module('Athena.Math');


n = Athena.Math.degToRad(0.0);
CHECK_CLOSE(0.0, n);

n = Athena.Math.degToRad(45.0);
CHECK_CLOSE(Athena.Math.HALF_PI / 2, n);

n = Athena.Math.degToRad(90.0);
CHECK_CLOSE(Athena.Math.HALF_PI, n);

n = Athena.Math.degToRad(180.0);
CHECK_CLOSE(Athena.Math.PI, n);

n = Athena.Math.degToRad(270.0);
CHECK_CLOSE(Athena.Math.HALF_PI * 3, n);

n = Athena.Math.degToRad(360.0);
CHECK_CLOSE(Athena.Math.TWO_PI, n);

n = Athena.Math.degToRad(-90.0);
CHECK_CLOSE(-Athena.Math.HALF_PI, n);


n = Athena.Math.radToDeg(0.0);
CHECK_CLOSE(0.0, n);

n = Athena.Math.radToDeg(Athena.Math.HALF_PI / 2);
CHECK_CLOSE(45.0, n);

n = Athena.Math.radToDeg(Athena.Math.HALF_PI);
CHECK_CLOSE(90.0, n);

n = Athena.Math.radToDeg(Athena.Math.PI);
CHECK_CLOSE(180.0, n);

n = Athena.Math.radToDeg(Athena.Math.HALF_PI * 3);
CHECK_CLOSE(270.0, n);

n = Athena.Math.radToDeg(Athena.Math.TWO_PI);
CHECK_CLOSE(360.0, n);

n = Athena.Math.radToDeg(-Athena.Math.HALF_PI);
CHECK_CLOSE(-90.0, n);

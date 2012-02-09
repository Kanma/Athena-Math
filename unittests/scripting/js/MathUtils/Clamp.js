import_module('Athena.Math');


n = Athena.Math.clamp(10, 5, 20);
CHECK_EQUAL(10, n);

n = Athena.Math.clamp(2, 5, 20);
CHECK_EQUAL(5, n);

n = Athena.Math.clamp(30, 5, 20);
CHECK_EQUAL(20, n);


n = Athena.Math.clamp(10, 9.6, 10.4);
CHECK_CLOSE(10.0, n);

n = Athena.Math.clamp(1.2, 9.6, 10.4);
CHECK_CLOSE(9.6, n);

n = Athena.Math.clamp(100.5, 9.6, 10.4);
CHECK_CLOSE(10.4, n);

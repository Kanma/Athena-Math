import_module('Athena.Math');


n = Athena.Math.log2(1);
CHECK_CLOSE(0.0, n);

n = Athena.Math.log2(2);
CHECK_CLOSE(1.0, n);

n = Athena.Math.log2(10);
CHECK_CLOSE(3.321928, n);

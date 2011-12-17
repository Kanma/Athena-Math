import_module('Athena.Math');


n = Athena.Math.log(1);
CHECK_CLOSE(0.0, n);

n = Athena.Math.log(2);
CHECK_CLOSE(0.6931471, n);

n = Athena.Math.log(10);
CHECK_CLOSE(2.3025850, n);

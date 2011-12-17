import_module('Athena.Math');


n = Athena.Math.ceil(10.4);
CHECK_CLOSE(11.0, n);

n = Athena.Math.ceil(-20.4);
CHECK_CLOSE(-20.0, n);

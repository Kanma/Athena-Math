import_module('Athena.Math');

c = new Athena.Math.Color();

CHECK_CLOSE(1.0, c.r);
CHECK_CLOSE(1.0, c.g);
CHECK_CLOSE(1.0, c.b);
CHECK_CLOSE(1.0, c.a);

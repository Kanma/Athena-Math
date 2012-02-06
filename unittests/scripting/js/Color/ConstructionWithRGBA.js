import_module('Athena.Math');

c = new Athena.Math.Color(0.5, 0.7, 0.2, 0.4);

CHECK_CLOSE(0.5, c.r);
CHECK_CLOSE(0.7, c.g);
CHECK_CLOSE(0.2, c.b);
CHECK_CLOSE(0.4, c.a);

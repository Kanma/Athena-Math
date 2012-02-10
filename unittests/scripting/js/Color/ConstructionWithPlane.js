import_module('Athena.Math');

c1 = new Athena.Math.Color(0.5, 0.7, 0.2, 0.4);
c2 = new Athena.Math.Color(c1);

CHECK_CLOSE(c2.r, c1.r);
CHECK_CLOSE(c2.g, c1.g);
CHECK_CLOSE(c2.b, c1.b);
CHECK_CLOSE(c2.a, c1.a);

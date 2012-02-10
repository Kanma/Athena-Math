import_module('Athena.Math');

c = new Athena.Math.Color(-0.5, 2, -0.2, 1.4);
c.saturate();

CHECK_CLOSE(0.0, c.r);
CHECK_CLOSE(1.0, c.g);
CHECK_CLOSE(0.0, c.b);
CHECK_CLOSE(1.0, c.a);


c = new Athena.Math.Color(1.5, -2, 1.2, -0.4);
c.saturate();

CHECK_CLOSE(1.0, c.r);
CHECK_CLOSE(0.0, c.g);
CHECK_CLOSE(1.0, c.b);
CHECK_CLOSE(0.0, c.a);

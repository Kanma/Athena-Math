import_module('Athena.Math');

c = new Athena.Math.Color();

c.setHSB(0.7, 0.3, 0.5);
r = c.getHSB();

CHECK_CLOSE(0.7, r.hue);
CHECK_CLOSE(0.3, r.saturation);
CHECK_CLOSE(0.5, r.brightness);

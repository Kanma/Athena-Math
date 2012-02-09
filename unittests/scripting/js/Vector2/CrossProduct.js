import_module('Athena.Math');

v_unit_x = new Athena.Math.Vector2(1, 0);
v_unit_y = new Athena.Math.Vector2(0, 1);

c = v_unit_x.cross(v_unit_y);

CHECK_CLOSE(1, c);

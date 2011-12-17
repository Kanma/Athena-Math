import_module('Athena.Math');

v_unit_y = new Athena.Math.Vector3(0, 1, 0);
v_unit_z = new Athena.Math.Vector3(0, 0, 1);

v = v_unit_y.cross(v_unit_z);
v.normalise();

CHECK_CLOSE(1, v.length());
CHECK_CLOSE(1, v.x);
CHECK_CLOSE(0, v.y);
CHECK_CLOSE(0, v.z);

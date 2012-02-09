import_module('Athena.Math');

m = new Athena.Math.Matrix4();
m.setTranslation(1, 2, 3);

v = m.translation();

CHECK_CLOSE(1, v.x);
CHECK_CLOSE(2, v.y);
CHECK_CLOSE(3, v.z);


m.setTranslation(new Athena.Math.Vector3(10, 20, 30));

v = m.translation();

CHECK_CLOSE(10, v.x);
CHECK_CLOSE(20, v.y);
CHECK_CLOSE(30, v.z);


m.makeTranslation(1, 2, 3);

v = m.translation();

CHECK_CLOSE(1, v.x);
CHECK_CLOSE(2, v.y);
CHECK_CLOSE(3, v.z);


m.makeTranslation(new Athena.Math.Vector3(10, 20, 30));

v = m.translation();

CHECK_CLOSE(10, v.x);
CHECK_CLOSE(20, v.y);
CHECK_CLOSE(30, v.z);



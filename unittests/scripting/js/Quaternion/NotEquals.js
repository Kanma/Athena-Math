import_module('Athena.Math');

q1 = new Athena.Math.Quaternion(10, 20, 30, 40);
q2 = new Athena.Math.Quaternion(10, 20, 30, 40);
q3 = new Athena.Math.Quaternion(10, 20, 300, 400);

CHECK(q1.notEquals(q3), "q1.notEquals(q3)");
CHECK(!q1.notEquals(q2), "!q1.notEquals(q2)");

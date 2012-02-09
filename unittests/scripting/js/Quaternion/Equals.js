import_module('Athena.Math');

q1 = new Athena.Math.Quaternion(10, 20, 30, 40);
q2 = new Athena.Math.Quaternion(10, 20, 30, 40);
q3 = new Athena.Math.Quaternion(10, 20, 300, 400);

CHECK(q1.equals(q2), "q1.equals(q2)");
CHECK(!q1.equals(q3), "!q1.equals(q3)");

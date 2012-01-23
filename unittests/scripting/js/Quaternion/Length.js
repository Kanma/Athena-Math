import_module('Athena.Math');

q = new Athena.Math.Quaternion(10, 20, 30, 40);

length = q.norm();
squared_length = q.squaredNorm();

CHECK_CLOSE(10 * 10 + 20 * 20 + 30 * 30 + 40 * 40, squared_length, 0.001);
CHECK_CLOSE(Math.sqrt(squared_length), length, 0.001);

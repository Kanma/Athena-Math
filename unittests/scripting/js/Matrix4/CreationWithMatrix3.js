import_module('Athena.Math');

m1 = new Athena.Math.Matrix3(1, 2, 3,
                             4, 5, 6,
                             7, 8, 9);

m2 = new Athena.Math.Matrix4(m1);

m3 = m2.extract3x3Matrix();

CHECK(m3.equals(m1), 'm3.equals(m1)');

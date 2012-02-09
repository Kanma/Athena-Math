import_module('Athena.Math');

aab = new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1);

m = new Athena.Math.Matrix4();
m.makeTransform(new Athena.Math.Vector3(10.0, 20.0, 30.0),
                Athena.Math.Vector3_UNIT_SCALE,
                Athena.Math.Quaternion_IDENTITY);

aab.transform(m);

CHECK(aab.isFinite(), "aab.isFinite()");
CHECK_CLOSE(9.0, aab.minimum.x);
CHECK_CLOSE(19.0, aab.minimum.y);
CHECK_CLOSE(29.0, aab.minimum.z);
CHECK_CLOSE(11.0, aab.maximum.x);
CHECK_CLOSE(21.0, aab.maximum.y);
CHECK_CLOSE(31.0, aab.maximum.z);


aab = new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1);

m = new Athena.Math.Matrix4();
m.makeTransform(Athena.Math.Vector3_ZERO,
                new Athena.Math.Vector3(2.0, 3.0, 4.0),
                Athena.Math.Quaternion_IDENTITY);

aab.transform(m);

CHECK(aab.isFinite(), "aab.isFinite()");
CHECK_CLOSE(-2.0, aab.minimum.x);
CHECK_CLOSE(-3.0, aab.minimum.y);
CHECK_CLOSE(-4.0, aab.minimum.z);
CHECK_CLOSE(2.0, aab.maximum.x);
CHECK_CLOSE(3.0, aab.maximum.y);
CHECK_CLOSE(4.0, aab.maximum.z);


aab = new Athena.Math.AxisAlignedBox(-1, -1, -1, 1, 1, 1);

m = new Athena.Math.Matrix4();
m.makeTransform(Athena.Math.Vector3_ZERO,
                Athena.Math.Vector3_UNIT_SCALE,
                new Athena.Math.Quaternion(Math.PI / 4, Athena.Math.Vector3_UNIT_Y));

aab.transform(m);

CHECK(aab.isFinite(), "aab.isFinite()");
CHECK_CLOSE(-1.414, aab.minimum.x, 0.001);
CHECK_CLOSE(-1.0, aab.minimum.y);
CHECK_CLOSE(-1.414, aab.minimum.z, 0.001);
CHECK_CLOSE(1.414, aab.maximum.x, 0.001);
CHECK_CLOSE(1.0, aab.maximum.y);
CHECK_CLOSE(1.414, aab.maximum.z, 0.001);

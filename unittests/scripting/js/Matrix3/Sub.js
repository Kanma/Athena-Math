import_module('Athena.Math');

m3 = new Athena.Math.Matrix3(1, 2, 3,
                             4, 5, 6,
                             7, 8, 9);

m2 = new Athena.Math.Matrix3(100, 200, 300,
                             400, 500, 600,
                             700, 800, 900);

m1 = new Athena.Math.Matrix3(10000, 20000, 30000,
                             40000, 50000, 60000,
                             70000, 80000, 90000);

m = m1.sub(m2);

CHECK_CLOSE(9900, m.m_0_0);
CHECK_CLOSE(19800, m.m_0_1);
CHECK_CLOSE(29700, m.m_0_2);

CHECK_CLOSE(39600, m.m_1_0);
CHECK_CLOSE(49500, m.m_1_1);
CHECK_CLOSE(59400, m.m_1_2);

CHECK_CLOSE(69300, m.m_2_0);
CHECK_CLOSE(79200, m.m_2_1);
CHECK_CLOSE(89100, m.m_2_2);


m = m1.sub(m2, m3);

CHECK_CLOSE(9899, m.m_0_0);
CHECK_CLOSE(19798, m.m_0_1);
CHECK_CLOSE(29697, m.m_0_2);

CHECK_CLOSE(39596, m.m_1_0);
CHECK_CLOSE(49495, m.m_1_1);
CHECK_CLOSE(59394, m.m_1_2);

CHECK_CLOSE(69293, m.m_2_0);
CHECK_CLOSE(79192, m.m_2_1);
CHECK_CLOSE(89091, m.m_2_2);

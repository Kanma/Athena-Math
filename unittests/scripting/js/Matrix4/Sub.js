import_module('Athena.Math');

m3 = new Athena.Math.Matrix4(1, 2, 3, 4,
                             5, 6, 7, 8,
                             9, 10, 11, 12,
                             13, 14, 15, 16);

m2 = new Athena.Math.Matrix4(100, 200, 300, 400,
                             500, 600, 700, 800,
                             900, 1000, 1100, 1200,
                             1300, 1400, 1500, 1600);

m1 = new Athena.Math.Matrix4(10000, 20000, 30000, 40000,
                             50000, 60000, 70000, 80000,
                             90000, 100000, 110000, 120000,
                             130000, 140000, 150000, 160000);

m = m1.sub(m2);

CHECK_CLOSE(9900, m.m_0_0);
CHECK_CLOSE(19800, m.m_0_1);
CHECK_CLOSE(29700, m.m_0_2);
CHECK_CLOSE(39600, m.m_0_3);

CHECK_CLOSE(49500, m.m_1_0);
CHECK_CLOSE(59400, m.m_1_1);
CHECK_CLOSE(69300, m.m_1_2);
CHECK_CLOSE(79200, m.m_1_3);

CHECK_CLOSE(89100, m.m_2_0);
CHECK_CLOSE(99000, m.m_2_1);
CHECK_CLOSE(108900, m.m_2_2);
CHECK_CLOSE(118800, m.m_2_3);

CHECK_CLOSE(128700, m.m_3_0);
CHECK_CLOSE(138600, m.m_3_1);
CHECK_CLOSE(148500, m.m_3_2);
CHECK_CLOSE(158400, m.m_3_3);

m = m1.sub(m2, m3);

CHECK_CLOSE(9899, m.m_0_0);
CHECK_CLOSE(19798, m.m_0_1);
CHECK_CLOSE(29697, m.m_0_2);
CHECK_CLOSE(39596, m.m_0_3);

CHECK_CLOSE(49495, m.m_1_0);
CHECK_CLOSE(59394, m.m_1_1);
CHECK_CLOSE(69293, m.m_1_2);
CHECK_CLOSE(79192, m.m_1_3);

CHECK_CLOSE(89091, m.m_2_0);
CHECK_CLOSE(98990, m.m_2_1);
CHECK_CLOSE(108889, m.m_2_2);
CHECK_CLOSE(118788, m.m_2_3);

CHECK_CLOSE(128687, m.m_3_0);
CHECK_CLOSE(138586, m.m_3_1);
CHECK_CLOSE(148485, m.m_3_2);
CHECK_CLOSE(158384, m.m_3_3);

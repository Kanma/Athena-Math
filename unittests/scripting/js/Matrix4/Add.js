import_module('Athena.Math');

m1 = new Athena.Math.Matrix4(1, 2, 3, 4,
                             5, 6, 7, 8,
                             9, 10, 11, 12,
                             13, 14, 15, 16);

m2 = new Athena.Math.Matrix4(100, 200, 300, 400,
                             500, 600, 700, 800,
                             900, 1000, 1100, 1200,
                             1300, 1400, 1500, 1600);

m3 = new Athena.Math.Matrix4(10000, 20000, 30000, 40000,
                             50000, 60000, 70000, 80000,
                             90000, 100000, 110000, 120000,
                             130000, 140000, 150000, 160000);

m = m1.add(m2);

CHECK_CLOSE(101, m.m_0_0);
CHECK_CLOSE(202, m.m_0_1);
CHECK_CLOSE(303, m.m_0_2);
CHECK_CLOSE(404, m.m_0_3);

CHECK_CLOSE(505, m.m_1_0);
CHECK_CLOSE(606, m.m_1_1);
CHECK_CLOSE(707, m.m_1_2);
CHECK_CLOSE(808, m.m_1_3);

CHECK_CLOSE(909, m.m_2_0);
CHECK_CLOSE(1010, m.m_2_1);
CHECK_CLOSE(1111, m.m_2_2);
CHECK_CLOSE(1212, m.m_2_3);

CHECK_CLOSE(1313, m.m_3_0);
CHECK_CLOSE(1414, m.m_3_1);
CHECK_CLOSE(1515, m.m_3_2);
CHECK_CLOSE(1616, m.m_3_3);

m = m1.add(m2, m3);

CHECK_CLOSE(10101, m.m_0_0);
CHECK_CLOSE(20202, m.m_0_1);
CHECK_CLOSE(30303, m.m_0_2);
CHECK_CLOSE(40404, m.m_0_3);

CHECK_CLOSE(50505, m.m_1_0);
CHECK_CLOSE(60606, m.m_1_1);
CHECK_CLOSE(70707, m.m_1_2);
CHECK_CLOSE(80808, m.m_1_3);

CHECK_CLOSE(90909, m.m_2_0);
CHECK_CLOSE(101010, m.m_2_1);
CHECK_CLOSE(111111, m.m_2_2);
CHECK_CLOSE(121212, m.m_2_3);

CHECK_CLOSE(131313, m.m_3_0);
CHECK_CLOSE(141414, m.m_3_1);
CHECK_CLOSE(151515, m.m_3_2);
CHECK_CLOSE(161616, m.m_3_3);

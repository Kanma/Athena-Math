import_module('Athena.Math');

bag = new Athena.Math.ShuffleBag();

bag.add(0, 20);
bag.add(1, 70);
bag.add(2, 10);

counters = [0, 0, 0];


for (var i = 0; i < 100; ++i)
    counters[bag.next()]++;

CHECK_EQUAL(20, counters[0]);
CHECK_EQUAL(70, counters[1]);
CHECK_EQUAL(10, counters[2]);


for (var i = 0; i < 900; ++i)
    counters[bag.next()]++;

CHECK_EQUAL(200, counters[0]);
CHECK_EQUAL(700, counters[1]);
CHECK_EQUAL(100, counters[2]);

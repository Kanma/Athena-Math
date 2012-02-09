import_module('Athena.Math');

rng = new Athena.Math.RandomNumberGenerator();

rng.setSeed(1235465487);

var ref = new Array();

for (var i = 0; i < 10000; ++i)
    ref.push(rng.randomize());


rng.setSeed(1235465487);

for (var i = 0; i < 10000; ++i)
    CHECK_CLOSE(ref[i], rng.randomize());

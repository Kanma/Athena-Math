import_module('Athena.Math');

rng = new Athena.Math.RandomNumberGenerator();

for (var i = 0; i < 10000; ++i)
{
    var v = rng.randomize(10.0);
    CHECK(v >= 0.0, "v >= 0.0");
    CHECK(v < 10.0, "v < 10.0");
}

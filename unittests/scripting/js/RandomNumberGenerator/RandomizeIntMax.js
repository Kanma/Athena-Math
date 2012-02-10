import_module('Athena.Math');

rng = new Athena.Math.RandomNumberGenerator();

for (var i = 0; i < 10000; ++i)
{
    var v = rng.randomizeInt(10);
    CHECK(v >= 0, "v >= 0");
    CHECK(v <= 10, "v <= 10");
    CHECK(v == parseInt(v), "v == parseInt(v)");
}

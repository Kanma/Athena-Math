import_module('Athena.Math');

rng = new Athena.Math.RandomNumberGenerator();

for (var i = 0; i < 10000; ++i)
{
    var v = rng.randomizeInt(10, 20);
    CHECK(v >= 10, "v >= 10");
    CHECK(v <= 20, "v <= 20");
    CHECK(v == parseInt(v), "v == parseInt(v)");
}


for (var i = 0; i < 10000; ++i)
{
    var v = rng.randomizeInt(-10, 10);
    CHECK(v >= -10, "v >= -10");
    CHECK(v <= 10, "v <= 10");
    CHECK(v == parseInt(v), "v == parseInt(v)");
}

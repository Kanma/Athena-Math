import_module('Athena.Math');


function time(f)
{
    var start = (new Date).getTime();

    for (var i = 0; i < 100000; i++)
        f();

    var diff = (new Date).getTime() - start;

    print(diff + 'ms\n');

    return diff;
}


function Vector3(x, y, z)
{
    this.__classname__ = 'Vector3';
    this.x = x;
    this.y = y;
    this.z = z;
}

Vector3.prototype.add = function(v)
{
    return new Vector3(this.x + v.x, this.y + v.y, this.z + v.z);
}


Athena.Vector3 = Vector3;


var v1 = new Athena.Math.Vector3(10, 20, 30);
var v2 = new Athena.Math.Vector3(100, 200, 300);

var v3 = new Athena.Vector3(10, 20, 30);
var v4 = new Athena.Vector3(100, 200, 300);


function athena_vector()
{
    var v = v1.add(v2);
}


function js_vector()
{
    var v = v3.add(v4);
}


function athena_vector2()
{
    var v = Athena.Math.test1(v2);
}


function js_vector2()
{
    var v = Athena.Math.test2(v4);
}


var t1 = time(athena_vector);
var t2 = time(js_vector);

print((t1 / t2) + 'x\n');

var t3 = time(athena_vector2);
var t4 = time(js_vector2);

print((t3 / t4) + 'x\n');

print(v4.__classname__);

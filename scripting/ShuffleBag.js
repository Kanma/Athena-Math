/** @file   ShuffleBag.js
    @author Philip Abbet

    Declaration of the class Athena.Math.ShuffleBag

    @note   Using a pure JavaScript class here instead of a binding over
            the C++ one results in a more flexible one.
*/

Athena.Math.ShuffleBag = function()
{
    this.cursor = 0;
    this.data   = new Array();
    this.rng    = new Athena.Math.RandomNumberGenerator();
}


/**************************************** METHODS ***************************************/

Athena.Math.ShuffleBag.prototype.setSeed = function(seed)
{
    this.rng.setSeed(seed);
}

//-----------------------------------------------------------------------

Athena.Math.ShuffleBag.prototype.reset = function()
{
    this.rng.reset();
    this.cursor = this.data.length - 1;
}

//-----------------------------------------------------------------------

Athena.Math.ShuffleBag.prototype.add = function(element, quantity)
{
    if (quantity === undefined)
        quantity = 1;

    for (var i = 0; i < quantity; ++i)
        this.data.push(element);

    this.cursor = this.data.length - 1;
}

//-----------------------------------------------------------------------

Athena.Math.ShuffleBag.prototype.next = function()
{
    if (this.cursor < 1)
    {
        this.cursor = this.data.length - 1;
        return this.data[0];
    }

    var index = this.rng.randomizeInt(this.cursor);

    var element = this.data[index];
    this.data[index] = this.data[this.cursor];
    this.data[this.cursor] = element;

    --this.cursor;

    return element;
}


/***************************************** OTHERS ***************************************/

Athena.Math.ShuffleBag.prototype.__classname__ = 'Athena.Math.ShuffleBag';

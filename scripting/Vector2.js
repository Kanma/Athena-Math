/** @file   Vector2.js
    @author Philip Abbet
    
    Declaration of the class Athena.Math.Vector2
    
    @note   Using a pure JavaScript class here instead of a binding over
            the C++ one results in faster code.
*/

Athena.Math.Vector2 = function()
{
    if (arguments.length == 0)
    {
        this.x = 0.0;
        this.y = 0.0;
    }
    else if (arguments.length == 2)
    {
        this.x = arguments[0];
        this.y = arguments[1];
    }
    else if (arguments.length == 1)
    {
        if (typeof(arguments[0]) === 'object')
        {
            this.x = arguments[0].x;
            this.y = arguments[0].y;
        }
        else
        {
            this.x = arguments[0];
            this.y = arguments[0];
        }
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nVector2()\nVector2(scale)\nVector2(x, y)\nVector2(vector)';
    }
}


/*********************************** VALUE ASSIGNATION **********************************/

Athena.Math.Vector2.prototype.set = function()
{
    if (arguments.length == 2)
    {
        this.x = arguments[0];
        this.y = arguments[1];
    }
    else if (arguments.length == 1)
    {
        if (typeof(arguments[0]) === 'object')
        {
            this.x = arguments[0].x;
            this.y = arguments[0].y;
        }
        else
        {
            this.x = arguments[0];
            this.y = arguments[0];
        }
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nset(scale)\nset(x, y)\nset(vector)';
    }
}


/********************************* COMPARISON OPERATIONS ********************************/

Athena.Math.Vector2.prototype.equals = function(vector)
{
    return (this.x == vector.x) && (this.y == vector.y);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.notEquals = function(vector)
{
    return (this.x != vector.x) || (this.y != vector.y);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.lesserThan = function(vector)
{
    return (this.x < vector.x) && (this.y < vector.y);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.greaterThan = function(vector)
{
    return (this.x > vector.x) && (this.y > vector.y);
}


/********************************* ARITHMETIC OPERATIONS ********************************/

Athena.Math.Vector2.prototype.add = function()
{
    var v = new Athena.Math.Vector2(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x += arguments[i].x;
            v.y += arguments[i].y;  
        }
        else
        {
            v.x += arguments[i];
            v.y += arguments[i];  
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.sub = function()
{
    var v = new Athena.Math.Vector2(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x -= arguments[i].x;
            v.y -= arguments[i].y;  
        }
        else
        {
            v.x -= arguments[i];
            v.y -= arguments[i];  
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.mul = function()
{
    var v = new Athena.Math.Vector2(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x *= arguments[i].x;
            v.y *= arguments[i].y;  
        }
        else
        {
            v.x *= arguments[i];
            v.y *= arguments[i];  
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.divide = function()
{
    var v = new Athena.Math.Vector2(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x /= arguments[i].x;
            v.y /= arguments[i].y;  
        }
        else
        {
            v.x /= arguments[i];
            v.y /= arguments[i];  
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.negate = function()
{
    return new Athena.Math.Vector2(-this.x, -this.y);
}


/********************************** ARITHMETIC UPDATES **********************************/

Athena.Math.Vector2.prototype.iadd = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x += arguments[i].x;
            this.y += arguments[i].y;  
        }
        else
        {
            this.x += arguments[i];
            this.y += arguments[i];  
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.isub = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x -= arguments[i].x;
            this.y -= arguments[i].y;  
        }
        else
        {
            this.x -= arguments[i];
            this.y -= arguments[i];  
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.imul = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x *= arguments[i].x;
            this.y *= arguments[i].y;  
        }
        else
        {
            this.x *= arguments[i];
            this.y *= arguments[i];  
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.idivide = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x /= arguments[i].x;
            this.y /= arguments[i].y;  
        }
        else
        {
            this.x /= arguments[i];
            this.y /= arguments[i];  
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.inegate = function()
{
    this.x = -this.x;
    this.y = -this.y;
}


/**************************************** METHODS ***************************************/

Athena.Math.Vector2.prototype.length = function()
{
    return Math.sqrt(this.x * this.x + this.y * this.y);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.squaredLength = function()
{
    return this.x * this.x + this.y * this.y;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.isZeroLength = function()
{
    return (this.x * this.x + this.y * this.y) < (1e-06 * 1e-06);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.distance = function(vector)
{
    return this.sub(vector).length();
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.squaredDistance = function(vector)
{
    return this.sub(vector).squaredLength();
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.dot = function(vector)
{
    return this.x * vector.x + this.y * vector.y;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.absDot = function(vector)
{
    return Math.abs(this.x * vector.x) + Math.abs(this.y * vector.y);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.normalise = function()
{
    var length = this.length();
    
    if (length > 1e-08)
    {
        inverse = 1.0 / length;
        this.x *= inverse;
        this.y *= inverse;
    }
    
    return length;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.normalisedCopy = function()
{
    var v = new Athena.Math.Vector2(this);
    v.normalise();
    return v;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.cross = function(vector)
{
    return this.x * vector.y - this.y * vector.x;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.midPoint = function(vector)
{
    return new Athena.Math.Vector2(
        (this.x + vector.x) * 0.5,
        (this.y + vector.y) * 0.5);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.makeFloor = function(vector)
{
    if (vector.x < this.x) this.x = vector.x;
    if (vector.y < this.y) this.y = vector.y;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.makeCeil = function(vector)
{
    if (vector.x > this.x) this.x = vector.x;
    if (vector.y > this.y) this.y = vector.y;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.perpendicular = function()
{
    return new Athena.Math.Vector2(-this.y, this.x);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.randomDeviant = function(angle)
{
    var cosa = Math.cos(angle);
    var sina = Math.sin(angle);
    return new Athena.Math.Vector2(cosa * this.x - sina * this.y, sina * this.x + cosa * this.y);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.angleBetween = function(vector)
{
    var lenProduct = Math.sqrt(this.squaredLength() * vector.squaredLength());

	// Divide by zero check
	if (lenProduct < 1e-6)
		lenProduct = 1e-6;

	var f = this.dot(vector) / lenProduct;

	f = Athena.Math.clamp(f, -1.0, 1.0);
	return Math.acos(f);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.reflect = function(normal)
{
    return this.sub(this.dot(normal).mul(normal, 2));
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.positionEquals = function(vector, tolerance)
{
	return Athena.Math.equals(this.x, vector.x, tolerance) &&
		   Athena.Math.equals(this.y, vector.y, tolerance);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.positionCloses = function(vector, tolerance)
{
    return this.squaredDistance(vector) <=
        (this.squaredLength() + vector.squaredLength()) * tolerance;
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.isNaN = function()
{
    return isNaN(this.x) || isNaN(this.y);
}

//-----------------------------------------------------------------------

Athena.Math.Vector2.prototype.toString = function()
{
    return '[' + this.x + ', ' + this.y + ']';
}


/**************************************** OTHERS ***************************************/

Athena.Math.Vector2.prototype.__classname__ = 'Athena.Math.Vector2';

Athena.Math.Vector2_ZERO            = new Athena.Math.Vector2(0.0, 0.0);
Athena.Math.Vector2_UNIT_X          = new Athena.Math.Vector2(1.0, 0.0);
Athena.Math.Vector2_UNIT_Y          = new Athena.Math.Vector2(0.0, 1.0);
Athena.Math.Vector2_NEGATIVE_UNIT_X = new Athena.Math.Vector2(-1.0, 0.0);
Athena.Math.Vector2_NEGATIVE_UNIT_Y = new Athena.Math.Vector2(0.0, -1.0);
Athena.Math.Vector2_UNIT_SCALE      = new Athena.Math.Vector2(1.0, 1.0);

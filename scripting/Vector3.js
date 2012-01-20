/** @file   Vector3.js
    @author Philip Abbet
    
    Declaration of the class Athena.Math.Vector3
    
    @note   Using a pure JavaScript class here instead of a binding over
            the C++ one results in faster code.
*/

function Vector3(x, y, z)
{
    if (arguments.length == 0)
    {
        this.x = 0.0;
        this.y = 0.0;  
        this.z = 0.0;
    }
    else if (arguments.length == 3)
    {
        this.x = arguments[0];
        this.y = arguments[1];  
        this.z = arguments[2];
    }
    else if (arguments.length == 1)
    {
        if (typeof(arguments[0]) === 'object')
        {
            this.x = arguments[0].x;
            this.y = arguments[0].y;  
            this.z = arguments[0].z;
        }
        else
        {
            this.x = arguments[0];
            this.y = arguments[0];  
            this.z = arguments[0];
        }
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nVector3()\nVector3(scale)\nVector3(x, y, z)\nVector3(vector)';
    }
}


/*********************************** VALUE ASSIGNATION **********************************/

Vector3.prototype.set = function()
{
    if (arguments.length == 3)
    {
        this.x = arguments[0];
        this.y = arguments[1];  
        this.z = arguments[2];
    }
    else if (arguments.length == 1)
    {
        if (typeof(arguments[0]) === 'object')
        {
            this.x = arguments[0].x;
            this.y = arguments[0].y;  
            this.z = arguments[0].z;
        }
        else
        {
            this.x = arguments[0];
            this.y = arguments[0];  
            this.z = arguments[0];
        }
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nset(scale)\nset(x, y, z)\nset(vector)';
    }
}


/********************************* COMPARISON OPERATIONS ********************************/

Vector3.prototype.equals = function(vector)
{
    return (this.x == vector.x) && (this.y == vector.y) && (this.z == vector.z);
}

//-----------------------------------------------------------------------

Vector3.prototype.notEquals = function(vector)
{
    return (this.x != vector.x) || (this.y != vector.y) || (this.z != vector.z);
}

//-----------------------------------------------------------------------

Vector3.prototype.lesserThan = function(vector)
{
    return (this.x < vector.x) && (this.y < vector.y) && (this.z < vector.z);
}

//-----------------------------------------------------------------------

Vector3.prototype.greaterThan = function(vector)
{
    return (this.x > vector.x) && (this.y > vector.y) && (this.z > vector.z);
}


/********************************* ARITHMETIC OPERATIONS ********************************/

Vector3.prototype.add = function()
{
    var v = new Vector3(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x += arguments[i].x;
            v.y += arguments[i].y;  
            v.z += arguments[i].z;
        }
        else
        {
            v.x += arguments[i];
            v.y += arguments[i];  
            v.z += arguments[i];
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Vector3.prototype.sub = function()
{
    var v = new Vector3(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x -= arguments[i].x;
            v.y -= arguments[i].y;  
            v.z -= arguments[i].z;
        }
        else
        {
            v.x -= arguments[i];
            v.y -= arguments[i];  
            v.z -= arguments[i];
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Vector3.prototype.mul = function()
{
    var v = new Vector3(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x *= arguments[i].x;
            v.y *= arguments[i].y;  
            v.z *= arguments[i].z;
        }
        else
        {
            v.x *= arguments[i];
            v.y *= arguments[i];  
            v.z *= arguments[i];
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Vector3.prototype.divide = function()
{
    var v = new Vector3(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x /= arguments[i].x;
            v.y /= arguments[i].y;  
            v.z /= arguments[i].z;
        }
        else
        {
            v.x /= arguments[i];
            v.y /= arguments[i];  
            v.z /= arguments[i];
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Vector3.prototype.negate = function()
{
    return new Vector3(-this.x, -this.y, -this.z);
}


/********************************** ARITHMETIC UPDATES **********************************/

Vector3.prototype.iadd = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x += arguments[i].x;
            this.y += arguments[i].y;  
            this.z += arguments[i].z;
        }
        else
        {
            this.x += arguments[i];
            this.y += arguments[i];  
            this.z += arguments[i];
        }
    }
}

//-----------------------------------------------------------------------

Vector3.prototype.isub = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x -= arguments[i].x;
            this.y -= arguments[i].y;  
            this.z -= arguments[i].z;
        }
        else
        {
            this.x -= arguments[i];
            this.y -= arguments[i];  
            this.z -= arguments[i];
        }
    }
}

//-----------------------------------------------------------------------

Vector3.prototype.imul = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x *= arguments[i].x;
            this.y *= arguments[i].y;  
            this.z *= arguments[i].z;
        }
        else
        {
            this.x *= arguments[i];
            this.y *= arguments[i];  
            this.z *= arguments[i];
        }
    }
}

//-----------------------------------------------------------------------

Vector3.prototype.idivide = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x /= arguments[i].x;
            this.y /= arguments[i].y;  
            this.z /= arguments[i].z;
        }
        else
        {
            this.x /= arguments[i];
            this.y /= arguments[i];  
            this.z /= arguments[i];
        }
    }
}

//-----------------------------------------------------------------------

Vector3.prototype.inegate = function()
{
    this.x = -this.x;
    this.y = -this.y;
    this.z = -this.z;
}


/**************************************** METHODS ***************************************/

Vector3.prototype.length = function()
{
    return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
}

//-----------------------------------------------------------------------

Vector3.prototype.squaredLength = function()
{
    return this.x * this.x + this.y * this.y + this.z * this.z;
}

//-----------------------------------------------------------------------

Vector3.prototype.isZeroLength = function()
{
    return (this.x * this.x + this.y * this.y + this.z * this.z) < (1e-06 * 1e-06);
}

//-----------------------------------------------------------------------

Vector3.prototype.distance = function(vector)
{
    return this.sub(vector).length();
}

//-----------------------------------------------------------------------

Vector3.prototype.squaredDistance = function(vector)
{
    return this.sub(vector).squaredLength();
}

//-----------------------------------------------------------------------

Vector3.prototype.dot = function(vector)
{
    return this.x * vector.x + this.y * vector.y + this.z * vector.z;
}

//-----------------------------------------------------------------------

Vector3.prototype.absDot = function(vector)
{
    return Math.abs(this.x * vector.x) + Math.abs(this.y * vector.y) +
           Math.abs(this.z * vector.z);
}

//-----------------------------------------------------------------------

Vector3.prototype.normalise = function()
{
    var length = this.length();
    
    if (length > 1e-08)
    {
        inverse = 1.0 / length;
        this.x *= inverse;
        this.y *= inverse;
        this.z *= inverse;
    }
    
    return length;
}

//-----------------------------------------------------------------------

Vector3.prototype.normalisedCopy = function()
{
    var v = new Vector3(this);
    v.normalise();
    return v;
}

//-----------------------------------------------------------------------

Vector3.prototype.cross = function(vector)
{
    return new Vector3(
        this.y * vector.z - this.z * vector.y,
        this.z * vector.x - this.x * vector.z,
        this.x * vector.y - this.y * vector.x);
}

//-----------------------------------------------------------------------

Vector3.prototype.midPoint = function(vector)
{
    return new Vector3(
        (this.x + vector.x) * 0.5,
        (this.y + vector.y) * 0.5,
        (this.z + vector.z) * 0.5);
}

//-----------------------------------------------------------------------

Vector3.prototype.makeFloor = function(vector)
{
    if (vector.x < this.x) this.x = vector.x;
    if (vector.y < this.y) this.y = vector.y;
    if (vector.z < this.z) this.z = vector.z;
}

//-----------------------------------------------------------------------

Vector3.prototype.makeCeil = function(vector)
{
    if (vector.x > this.x) this.x = vector.x;
    if (vector.y > this.y) this.y = vector.y;
    if (vector.z > this.z) this.z = vector.z;
}

//-----------------------------------------------------------------------

Vector3.prototype.perpendicular = function()
{
    var perp = this.cross(Athena.Math.Vector3_UNIT_X);
    
    if (perp.squaredLength() < 1e-06 * 1e-06)
        perp = this.cross(Athena.Math.Vector3_UNIT_Y);
    
    perp.normalise();

    return perp;
}

//-----------------------------------------------------------------------

// TODO: randomDeviant()

//-----------------------------------------------------------------------

Vector3.prototype.angleBetween = function(vector)
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

// TODO: getRotationTo()

//-----------------------------------------------------------------------

Vector3.prototype.reflect = function(normal)
{
    return this.sub(this.dot(normal).mul(normal, 2));
}

//-----------------------------------------------------------------------

// TODO: positionEquals()

//-----------------------------------------------------------------------

Vector3.prototype.positionCloses = function(vector, tolerance)
{
    return this.squaredDistance(vector) <=
        (this.squaredLength() + vector.squaredLength()) * tolerance;
}

//-----------------------------------------------------------------------

Vector3.prototype.directionEquals = function(vector, tolerance)
{
    var dot = this.dot(vector);
    var angle = Math.acos(dot);
    
    return Math.abs(angle) <= tolerance;
}

//-----------------------------------------------------------------------

Vector3.prototype.isNaN = function()
{
    return isNaN(this.x) || isNaN(this.y) || isNaN(this.z);
}


/**************************************** OTHERS ***************************************/

Vector3.prototype.__classname__ = 'Athena.Math.Vector3';

Athena.Math.Vector3 = Vector3;

Athena.Math.Vector3_ZERO            = new Vector3(0.0, 0.0, 0.0);
Athena.Math.Vector3_UNIT_X          = new Vector3(1.0, 0.0, 0.0);
Athena.Math.Vector3_UNIT_Y          = new Vector3(0.0, 1.0, 0.0);
Athena.Math.Vector3_UNIT_Z          = new Vector3(0.0, 0.0, 1.0);
Athena.Math.Vector3_NEGATIVE_UNIT_X = new Vector3(-1.0, 0.0, 0.0);
Athena.Math.Vector3_NEGATIVE_UNIT_Y = new Vector3(0.0, -1.0, 0.0);
Athena.Math.Vector3_NEGATIVE_UNIT_Z = new Vector3(0.0, 0.0, -1.0);
Athena.Math.Vector3_UNIT_SCALE      = new Vector3(1.0, 1.0, 1.0);

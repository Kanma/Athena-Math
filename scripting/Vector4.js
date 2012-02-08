/** @file   Vector4.js
    @author Philip Abbet

    Declaration of the class Athena.Math.Vector4

    @note   Using a pure JavaScript class here instead of a binding over
            the C++ one results in faster code.
*/

Athena.Math.Vector4 = function()
{
    if (arguments.length == 0)
    {
        this.x = 0.0;
        this.y = 0.0;
        this.z = 0.0;
        this.w = 0.0;
    }
    else if (arguments.length == 4)
    {
        this.x = arguments[0];
        this.y = arguments[1];
        this.z = arguments[2];
        this.w = arguments[3];
    }
    else if (arguments.length == 1)
    {
        if (typeof(arguments[0]) === 'object')
        {
            if (arguments[0].__classname__ == 'Athena.Math.Vector3')
            {
                this.x = arguments[0].x;
                this.y = arguments[0].y;
                this.z = arguments[0].z;
                this.w = 1.0;
            }
            else
            {
                this.x = arguments[0].x;
                this.y = arguments[0].y;
                this.z = arguments[0].z;
                this.w = arguments[0].w;
            }
        }
        else
        {
            this.x = arguments[0];
            this.y = arguments[0];
            this.z = arguments[0];
            this.w = arguments[0];
        }
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nVector4()\nVector4(scale)\nVector4(x, y, z, w)\nVector4(vector4)\nVector4(vector3)';
    }
}


/*********************************** VALUE ASSIGNATION **********************************/

Athena.Math.Vector4.prototype.set = function()
{
    if (arguments.length == 4)
    {
        this.x = arguments[0];
        this.y = arguments[1];
        this.z = arguments[2];
        this.w = arguments[3];
    }
    else if (arguments.length == 1)
    {
        if (typeof(arguments[0]) === 'object')
        {
            if (arguments[0].__classname__ == 'Athena.Math.Vector3')
            {
                this.x = arguments[0].x;
                this.y = arguments[0].y;
                this.z = arguments[0].z;
                this.w = 1.0;
            }
            else
            {
                this.x = arguments[0].x;
                this.y = arguments[0].y;
                this.z = arguments[0].z;
                this.w = arguments[0].w;
            }
        }
        else
        {
            this.x = arguments[0];
            this.y = arguments[0];
            this.z = arguments[0];
            this.w = arguments[0];
        }
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nset(scale)\nset(x, y, z, w)\nset(vector4)\nset(vector3)';
    }
}


/********************************* COMPARISON OPERATIONS ********************************/

Athena.Math.Vector4.prototype.equals = function(vector)
{
    return (this.x == vector.x) && (this.y == vector.y) && (this.z == vector.z) && (this.w == vector.w);
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.notEquals = function(vector)
{
    return (this.x != vector.x) || (this.y != vector.y) || (this.z != vector.z) || (this.w != vector.w);
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.lesserThan = function(vector)
{
    return (this.x < vector.x) && (this.y < vector.y) && (this.z < vector.z) && (this.w < vector.w);
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.greaterThan = function(vector)
{
    return (this.x > vector.x) && (this.y > vector.y) && (this.z > vector.z) && (this.w > vector.w);
}


/********************************* ARITHMETIC OPERATIONS ********************************/

Athena.Math.Vector4.prototype.add = function()
{
    var v = new Athena.Math.Vector4(this);

    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x += arguments[i].x;
            v.y += arguments[i].y;
            v.z += arguments[i].z;
            v.w += arguments[i].w;
        }
        else
        {
            v.x += arguments[i];
            v.y += arguments[i];
            v.z += arguments[i];
            v.w += arguments[i];
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.sub = function()
{
    var v = new Athena.Math.Vector4(this);

    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x -= arguments[i].x;
            v.y -= arguments[i].y;
            v.z -= arguments[i].z;
            v.w -= arguments[i].w;
        }
        else
        {
            v.x -= arguments[i];
            v.y -= arguments[i];
            v.z -= arguments[i];
            v.w -= arguments[i];
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.mul = function()
{
    var v = new Athena.Math.Vector4(this);

    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x *= arguments[i].x;
            v.y *= arguments[i].y;
            v.z *= arguments[i].z;
            v.w *= arguments[i].w;
        }
        else
        {
            v.x *= arguments[i];
            v.y *= arguments[i];
            v.z *= arguments[i];
            v.w *= arguments[i];
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.divide = function()
{
    var v = new Athena.Math.Vector4(this);

    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            v.x /= arguments[i].x;
            v.y /= arguments[i].y;
            v.z /= arguments[i].z;
            v.w /= arguments[i].w;
        }
        else
        {
            v.x /= arguments[i];
            v.y /= arguments[i];
            v.z /= arguments[i];
            v.w /= arguments[i];
        }
    }

    return v;
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.negate = function()
{
    return new Athena.Math.Vector4(-this.x, -this.y, -this.z, -this.w);
}


/********************************** ARITHMETIC UPDATES **********************************/

Athena.Math.Vector4.prototype.iadd = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x += arguments[i].x;
            this.y += arguments[i].y;
            this.z += arguments[i].z;
            this.w += arguments[i].w;
        }
        else
        {
            this.x += arguments[i];
            this.y += arguments[i];
            this.z += arguments[i];
            this.w += arguments[i];
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.isub = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x -= arguments[i].x;
            this.y -= arguments[i].y;
            this.z -= arguments[i].z;
            this.w -= arguments[i].w;
        }
        else
        {
            this.x -= arguments[i];
            this.y -= arguments[i];
            this.z -= arguments[i];
            this.w -= arguments[i];
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.imul = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x *= arguments[i].x;
            this.y *= arguments[i].y;
            this.z *= arguments[i].z;
            this.w *= arguments[i].w;
        }
        else
        {
            this.x *= arguments[i];
            this.y *= arguments[i];
            this.z *= arguments[i];
            this.w *= arguments[i];
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.idivide = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.x /= arguments[i].x;
            this.y /= arguments[i].y;
            this.z /= arguments[i].z;
            this.w /= arguments[i].w;
        }
        else
        {
            this.x /= arguments[i];
            this.y /= arguments[i];
            this.z /= arguments[i];
            this.w /= arguments[i];
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.inegate = function()
{
    this.x = -this.x;
    this.y = -this.y;
    this.z = -this.z;
    this.w = -this.w;
}


/**************************************** METHODS ***************************************/

Athena.Math.Vector4.prototype.length = function()
{
    return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.squaredLength = function()
{
    return this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w;
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.isZeroLength = function()
{
    return (this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w) < (1e-06 * 1e-06);
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.distance = function(vector)
{
    return this.sub(vector).length();
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.squaredDistance = function(vector)
{
    return this.sub(vector).squaredLength();
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.dot = function(vector)
{
    return this.x * vector.x + this.y * vector.y + this.z * vector.z + this.w * vector.w;
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.absDot = function(vector)
{
    return Math.abs(this.x * vector.x) + Math.abs(this.y * vector.y) +
           Math.abs(this.z * vector.z) + Math.abs(this.w * vector.w);
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.normalise = function()
{
    var length = this.length();

    if (length > 1e-08)
    {
        inverse = 1.0 / length;
        this.x *= inverse;
        this.y *= inverse;
        this.z *= inverse;
        this.w *= inverse;
    }

    return length;
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.normalisedCopy = function()
{
    var v = new Athena.Math.Vector4(this);
    v.normalise();
    return v;
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.midPoint = function(vector)
{
    return new Athena.Math.Vector4(
        (this.x + vector.x) * 0.5,
        (this.y + vector.y) * 0.5,
        (this.z + vector.z) * 0.5,
        (this.w + vector.w) * 0.5);
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.makeFloor = function(vector)
{
    if (vector.x < this.x) this.x = vector.x;
    if (vector.y < this.y) this.y = vector.y;
    if (vector.z < this.z) this.z = vector.z;
    if (vector.w < this.w) this.w = vector.w;
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.makeCeil = function(vector)
{
    if (vector.x > this.x) this.x = vector.x;
    if (vector.y > this.y) this.y = vector.y;
    if (vector.z > this.z) this.z = vector.z;
    if (vector.w > this.w) this.w = vector.w;
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.positionEquals = function(vector, tolerance)
{
    return Athena.Math.equals(this.x, vector.x, tolerance) &&
           Athena.Math.equals(this.y, vector.y, tolerance) &&
           Athena.Math.equals(this.z, vector.z, tolerance) &&
           Athena.Math.equals(this.w, vector.w, tolerance);
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.positionCloses = function(vector, tolerance)
{
    return this.squaredDistance(vector) <=
        (this.squaredLength() + vector.squaredLength()) * tolerance;
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.isNaN = function()
{
    return isNaN(this.x) || isNaN(this.y) || isNaN(this.z) || isNaN(this.w);
}

//-----------------------------------------------------------------------

Athena.Math.Vector4.prototype.toString = function()
{
    return '[' + this.x + ', ' + this.y + ', ' + this.z + ', ' + this.w + ']';
}


/**************************************** OTHERS ***************************************/

Athena.Math.Vector4.prototype.__classname__ = 'Athena.Math.Vector4';

Athena.Math.Vector4_ZERO = new Athena.Math.Vector4(0.0, 0.0, 0.0, 0.0);

/** @file   Plane.js
    @author Philip Abbet

    Declaration of the class Athena.Math.Plane

    @note   Using a pure JavaScript class here instead of a binding over
            the C++ one results in faster code.
*/

Athena.Math.Plane = function()
{
    if (arguments.length == 0)
    {
        this.normal = new Athena.Math.Vector3();
        this.d = 0.0;
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Plane'))
    {
        this.normal = arguments[0].normal;
        this.d = arguments[0].d;
    }
    else if ((arguments.length == 2) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[1]) === 'number'))
    {
        this.normal = arguments[0];
        this.d = -arguments[1];
    }
    else if ((arguments.length == 2) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[1]) === 'object') && (arguments[1].__classname__ == 'Athena.Math.Vector3'))
    {
        this.normal = arguments[0];
        this.d = -arguments[0].dot(arguments[1]);
    }
    else if ((arguments.length == 3) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[1]) === 'object') && (arguments[1].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[2]) === 'object') && (arguments[2].__classname__ == 'Athena.Math.Vector3'))
    {
        var edge1 = arguments[1].sub(arguments[0]);
        var edge2 = arguments[2].sub(arguments[0]);
        this.normal = edge1.cross(edge2);
        this.normal.normalise();
        this.d = -this.normal.dot(arguments[0]);
    }
    else if (arguments.length == 4)
    {
        this.normal = new Athena.Math.Vector3(arguments[0], arguments[1], arguments[2]);
        this.d = arguments[3];
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nPlane()\nPlane(plane)\nPlane(normal, constant)\nPlane(a, b, c, d)\nPlane(normal, point)\nPlane(point0, point1, point2)';
    }
}


/*********************************** VALUE ASSIGNATION **********************************/

Athena.Math.Plane.prototype.set = function()
{
    if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Plane'))
    {
        this.normal = arguments[0].normal;
        this.d = arguments[0].d;
    }
    else if ((arguments.length == 2) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[1]) === 'number'))
    {
        this.normal = arguments[0];
        this.d = -arguments[1];
    }
    else if ((arguments.length == 2) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[1]) === 'object') && (arguments[1].__classname__ == 'Athena.Math.Vector3'))
    {
        this.normal = arguments[0];
        this.d = -arguments[0].dot(arguments[1]);
    }
    else if ((arguments.length == 3) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[1]) === 'object') && (arguments[1].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[2]) === 'object') && (arguments[2].__classname__ == 'Athena.Math.Vector3'))
    {
        var edge1 = arguments[1].sub(arguments[0]);
        var edge2 = arguments[2].sub(arguments[0]);
        this.normal = edge1.cross(edge2);
        this.normal.normalise();
        this.d = -this.normal.dot(arguments[0]);
    }
    else if (arguments.length == 4)
    {
        this.normal = new Athena.Math.Vector3(arguments[0], arguments[1], arguments[2]);
        this.d = arguments[3];
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nset(plane)\nset(normal, constant)\nset(a, b, c, d)\nset(normal, point)\nset(point0, point1, point2)';
    }
}


/********************************* COMPARISON OPERATIONS ********************************/

Athena.Math.Plane.prototype.equals = function(plane)
{
    return (this.d == plane.d) && this.normal.equals(plane.normal);
}

//-----------------------------------------------------------------------

Athena.Math.Plane.prototype.notEquals = function(plane)
{
    return (this.d != plane.d) || this.normal.notEquals(plane.normal);
}


/**************************************** METHODS ***************************************/

Athena.Math.Plane.prototype.getSide = function()
{
    if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3'))
    {
        var distance = this.getDistance(arguments[0]);

        if (distance < 0.0)
            return Athena.Math.Plane_NEGATIVE_SIDE;

        if (distance > 0.0)
            return Athena.Math.Plane_POSITIVE_SIDE;

        return Athena.Math.Plane_NO_SIDE;
    }
    else if ((arguments.length == 1) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.AxisAlignedBox'))
    {
        if (arguments[0].isNull())
            return Athena.Math.Plane_NO_SIDE;

        if (arguments[0].isInfinite())
            return Athena.Math.Plane_BOTH_SIDE;

        return this.getSide(arguments[0].getCenter(), arguments[0].getHalfSize());
    }
    else if ((arguments.length == 2) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[1]) === 'object') && (arguments[1].__classname__ == 'Athena.Math.Vector3'))
    {
        var dist = this.getDistance(arguments[0]);

        var maxAbsDist = this.normal.absDot(arguments[1]);

        if (dist < -maxAbsDist)
            return Athena.Math.Plane_NEGATIVE_SIDE;

        if (dist > +maxAbsDist)
            return Athena.Math.Plane_POSITIVE_SIDE;

        return Athena.Math.Plane_BOTH_SIDE;
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\ngetSide(point)\ngetSide(centre, half_size)\ngetSide(axis_aligned_box)';
    }
}

//-----------------------------------------------------------------------

Athena.Math.Plane.prototype.getDistance = function(point)
{
    return this.normal.dot(point) + this.d;
}

//-----------------------------------------------------------------------

Athena.Math.Plane.prototype.projectVector = function(point)
{
    var xform = new Athena.Math.Matrix3();

    xform.m_0_0 = 1.0 - this.normal.x * this.normal.x;
    xform.m_0_1 = -this.normal.x * this.normal.y;
    xform.m_0_2 = -this.normal.x * this.normal.z;
    xform.m_1_0 = -this.normal.y * this.normal.x;
    xform.m_1_1 = 1.0 - this.normal.y * this.normal.y;
    xform.m_1_2 = -this.normal.y * this.normal.z;
    xform.m_2_0 = -this.normal.z * this.normal.x;
    xform.m_2_1 = -this.normal.z * this.normal.y;
    xform.m_2_2 = 1.0 - this.normal.z * this.normal.z;

    return xform.mul(point);
}

//-----------------------------------------------------------------------

Athena.Math.Plane.prototype.normalise = function()
{
    var length = this.normal.length();

    // Will also work for zero-sized vectors, but will change nothing
    if (length > 1e-08)
    {
        var invLength = 1.0 / length;
        this.normal.imul(invLength);
        this.d *= invLength;
    }

    return length;
}

//-----------------------------------------------------------------------

Athena.Math.Plane.prototype.toString = function()
{
    return '{ normal: ' + this.normal.toString() + ', d: ' + this.d + ' }';
}


/**************************************** OTHERS ****************************************/

Athena.Math.Plane.prototype.__classname__ = 'Athena.Math.Plane';

Athena.Math.Plane_NO_SIDE       = 0;
Athena.Math.Plane_POSITIVE_SIDE = 1;
Athena.Math.Plane_NEGATIVE_SIDE = 2;
Athena.Math.Plane_BOTH_SIDE     = 3;

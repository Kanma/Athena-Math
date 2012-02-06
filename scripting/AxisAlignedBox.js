/** @file   AxisAlignedBox.js
    @author Philip Abbet
    
    Declaration of the class Athena.Math.AxisAlignedBox
    
    @note   Using a pure JavaScript class here instead of a binding over
            the C++ one results in faster code.
*/

Athena.Math.AxisAlignedBox = function()
{
    if (arguments.length == 0)
    {
        this.minimum = new Athena.Math.Vector3(-0.5, -0.5, -0.5);
        this.maximum = new Athena.Math.Vector3(0.5, 0.5, 0.5);
        this.extent  = Athena.Math.AxisAlignedBox_EXTENT_NULL;
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.AxisAlignedBox'))
    {
        this.minimum = new Athena.Math.Vector3(arguments[0].minimum);
        this.maximum = new Athena.Math.Vector3(arguments[0].maximum);
        this.extent  = arguments[0].extent;
    }
    else if (arguments.length == 1)
    {
        this.minimum = new Athena.Math.Vector3(-0.5, -0.5, -0.5);
        this.maximum = new Athena.Math.Vector3(0.5, 0.5, 0.5);
        this.extent  = arguments[0];
    }
    else if (arguments.length == 2)
    {
        this.minimum = new Athena.Math.Vector3(arguments[0]);
        this.maximum = new Athena.Math.Vector3(arguments[1]);
        this.extent  = Athena.Math.AxisAlignedBox_EXTENT_FINITE;
    }
    else if (arguments.length == 6)
    {
        this.minimum = new Athena.Math.Vector3(arguments[0], arguments[1], arguments[2]);
        this.maximum = new Athena.Math.Vector3(arguments[3], arguments[4], arguments[5]);
        this.extent  = Athena.Math.AxisAlignedBox_EXTENT_FINITE;
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nAxisAlignedBox()\nAxisAlignedBox(extent)\nAxisAlignedBox(aab)\nAxisAlignedBox(minimum, maximum)\nAxisAlignedBox(minx, miny, minz, maxx, maxym maxz)';
    }
}


/*********************************** VALUE ASSIGNATION **********************************/

Athena.Math.AxisAlignedBox.prototype.set = function()
{
    if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.AxisAlignedBox'))
    {
        this.minimum = new Athena.Math.Vector3(arguments[0].minimum);
        this.maximum = new Athena.Math.Vector3(arguments[0].maximum);
        this.extent  = arguments[0].extent;
    }
    else if (arguments.length == 1)
    {
        this.minimum = new Athena.Math.Vector3(-0.5, -0.5, -0.5);
        this.maximum = new Athena.Math.Vector3(0.5, 0.5, 0.5);
        this.extent  = arguments[0];
    }
    else if (arguments.length == 2)
    {
        this.minimum = new Athena.Math.Vector3(arguments[0]);
        this.maximum = new Athena.Math.Vector3(arguments[1]);
        this.extent  = Athena.Math.AxisAlignedBox_EXTENT_FINITE;
    }
    else if (arguments.length == 6)
    {
        this.minimum = new Athena.Math.Vector3(arguments[0], arguments[1], arguments[2]);
        this.maximum = new Athena.Math.Vector3(arguments[3], arguments[4], arguments[5]);
        this.extent  = Athena.Math.AxisAlignedBox_EXTENT_FINITE;
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nset(extent)\nset(aab)\nset(minimum, maximum)\nset(minx, miny, minz, maxx, maxym maxz)';
    }
}


/********************************* COMPARISON OPERATIONS ********************************/

Athena.Math.AxisAlignedBox.prototype.equals = function(aab)
{
    if (this.extent != aab.extent)
        return false;

    if (!this.isFinite())
        return true;
    
    return this.minimum.equals(aab.minimum) && this.maximum.equals(aab.maximum);
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.notEquals = function(aab)
{
    return !this.equals(aab);
}


/**************************************** METHODS ***************************************/

Athena.Math.AxisAlignedBox.prototype.getCorner = function(corner)
{
    switch (corner)
    {
    case Athena.Math.AxisAlignedBox_FAR_LEFT_BOTTOM:
        return new Athena.Math.Vector3(this.minimum);
    case Athena.Math.AxisAlignedBox_FAR_LEFT_TOP:
        return new Athena.Math.Vector3(this.minimum.x, this.maximum.y, this.minimum.z);
    case Athena.Math.AxisAlignedBox_FAR_RIGHT_TOP:
        return new Athena.Math.Vector3(this.maximum.x, this.maximum.y, this.minimum.z);
    case Athena.Math.AxisAlignedBox_FAR_RIGHT_BOTTOM:
           return new Athena.Math.Vector3(this.maximum.x, this.minimum.y, this.minimum.z);
    case Athena.Math.AxisAlignedBox_NEAR_RIGHT_BOTTOM:
           return new Athena.Math.Vector3(this.maximum.x, this.minimum.y, this.maximum.z);
    case Athena.Math.AxisAlignedBox_NEAR_LEFT_BOTTOM:
           return new Athena.Math.Vector3(this.minimum.x, this.minimum.y, this.maximum.z);
    case Athena.Math.AxisAlignedBox_NEAR_LEFT_TOP:
           return new Athena.Math.Vector3(this.minimum.x, this.maximum.y, this.maximum.z);
    case Athena.Math.AxisAlignedBox_NEAR_RIGHT_TOP:
        return new Athena.Math.Vector3(this.maximum);
    default:
        return new Athena.Math.Vector3();
    }
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.merge = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (arguments[i].__classname__ == 'Athena.Math.AxisAlignedBox')
        {
            // Do nothing if rhs null, or this is infinite
            if ((arguments[i].extent == Athena.Math.AxisAlignedBox_EXTENT_NULL) ||
                (this.extent == Athena.Math.AxisAlignedBox_EXTENT_INFINITE))
            {
                continue;
            }
            // Otherwise if rhs is infinite, make this infinite, too
            else if (arguments[i].mExtent == Athena.Math.AxisAlignedBox_EXTENT_INFINITE)
            {
                this.extent = Athena.Math.AxisAlignedBox_EXTENT_INFINITE;
            }
            // Otherwise if current null, just take rhs
            else if (this.extent == Athena.Math.AxisAlignedBox_EXTENT_NULL)
            {
                this.set(arguments[i].minimum, arguments[i].maximum);
            }
            // Otherwise merge
            else
            {
                this.minimum.makeFloor(arguments[i].minimum);
                this.maximum.makeCeil(arguments[i].maximum);
            }
        }
        else if (arguments[i].__classname__ == 'Athena.Math.Vector3')
        {
            switch (this.extent)
            {
            case Athena.Math.AxisAlignedBox_EXTENT_NULL: // if null, use this point
                this.set(arguments[i], arguments[i]);
                break;

            case Athena.Math.AxisAlignedBox_EXTENT_FINITE:
                this.maximum.makeCeil(arguments[i]);
                this.minimum.makeFloor(arguments[i]);
                break;

            case Athena.Math.AxisAlignedBox_EXTENT_INFINITE: // if infinite, makes no difference
                break;
            }
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.transform = function(matrix)
{
    // Do nothing if current null or infinite
    if (this.extent != Athena.Math.AxisAlignedBox_EXTENT_FINITE)
        return;
    
    // Getting the old values so that we can use the existing merge method.
    var oldMin = new Athena.Math.Vector3(this.minimum);
    var oldMax = new Athena.Math.Vector3(this.maximum);
    
    // Reset
    this.setNull();
    
    // We sequentially compute the corners in the following order :
    // 0, 6, 5, 1, 2, 4 ,7 , 3
    // This sequence allows us to only change one member at a time to get at all corners.
    
    // For each one, we transform it using the matrix
    // Which gives the resulting point and merge the resulting point.
    
    // First corner 
    // min min min
    var currentCorner = new Athena.Math.Vector3(oldMin);
    this.merge(matrix.mul(currentCorner));
    
    // min,min,max
    currentCorner.z = oldMax.z;
    this.merge(matrix.mul(currentCorner));
    
    // min max max
    currentCorner.y = oldMax.y;
    this.merge(matrix.mul(currentCorner));
    
    // min max min
    currentCorner.z = oldMin.z;
    this.merge(matrix.mul(currentCorner));
    
    // max max min
    currentCorner.x = oldMax.x;
    this.merge(matrix.mul(currentCorner));
    
    // max max max
    currentCorner.z = oldMax.z;
    this.merge(matrix.mul(currentCorner));
    
    // max min max
    currentCorner.y = oldMin.y;
    this.merge(matrix.mul(currentCorner));
    
    // max min min
    currentCorner.z = oldMin.z;
    this.merge(matrix.mul(currentCorner));
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.transformAffine = function(matrix)
{
    // Do nothing if current null or infinite
    if (this.extent != Athena.Math.AxisAlignedBox_EXTENT_FINITE)
        return;
    
    var center = this.getCenter();
    var halfSize = this.getHalfSize();
    
    var newCenter = matrix.transformAffine(center);
    var newHalfSize = new Athena.Math.Vector3(
        Math.abs(matrix.m_0_0) * halfSize.x + Math.abs(matrix.m_0_1) * halfSize.y + Math.abs(matrix.m_0_2) * halfSize.z,
        Math.abs(matrix.m_1_0) * halfSize.x + Math.abs(matrix.m_1_1) * halfSize.y + Math.abs(matrix.m_1_2) * halfSize.z,
        Math.abs(matrix.m_2_0) * halfSize.x + Math.abs(matrix.m_2_1) * halfSize.y + Math.abs(matrix.m_2_2) * halfSize.z
    );
    
    this.set(newCenter.sub(newHalfSize), newCenter.add(newHalfSize));
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.setNull = function()
{
    this.extent = Athena.Math.AxisAlignedBox_EXTENT_NULL;
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.isNull = function()
{
    return (this.extent == Athena.Math.AxisAlignedBox_EXTENT_NULL);
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.isFinite = function()
{
    return (this.extent == Athena.Math.AxisAlignedBox_EXTENT_FINITE);
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.setInfinite = function()
{
    this.extent = Athena.Math.AxisAlignedBox_EXTENT_INFINITE;
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.isInfinite = function()
{
    return (this.extent == Athena.Math.AxisAlignedBox_EXTENT_INFINITE);
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.intersection = function(aab)
{
    if (this.isNull() || aab.isNull())
        return new Athena.Math.AxisAlignedBox();
    else if (this.isInfinite())
        return new Athena.Math.AxisAlignedBox(aab);
    else if (aab.isInfinite())
        return new Athena.Math.AxisAlignedBox(this);

    var intMin = new Athena.Math.Vector3(this.minimum);
    var intMax = new Athena.Math.Vector3(this.maximum);

    intMin.makeCeil(aab.minimum);
    intMax.makeFloor(aab.maximum);

    // Check intersection isn't null
    if ((intMin.x < intMax.x) &&
        (intMin.y < intMax.y) &&
        (intMin.z < intMax.z))
    {
        return new Athena.Math.AxisAlignedBox(intMin, intMax);
    }

    return new Athena.Math.AxisAlignedBox();
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.volume = function()
{
    switch (this.extent)
    {
        case Athena.Math.AxisAlignedBox_EXTENT_NULL:
            return 0.0;
    
        case Athena.Math.AxisAlignedBox_EXTENT_FINITE:
        {
            var diff = this.maximum.sub(this.minimum);
            return diff.x * diff.y * diff.z;
        }
       
        case Athena.Math.AxisAlignedBox_EXTENT_INFINITE:
            return Infinity;
    }
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.scale = function(s)
{
    // Do nothing if current null or infinite
    if (this.extent != Athena.Math.AxisAlignedBox_EXTENT_FINITE)
        return;

    // NB assumes centered on origin
    var min = this.minimum.mul(s);
    var max = this.maximum.mul(s);
    this.set(min, max);
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.getCenter = function()
{
    return new Athena.Math.Vector3(
        (this.maximum.x + this.minimum.x) * 0.5,
        (this.maximum.y + this.minimum.y) * 0.5,
        (this.maximum.z + this.minimum.z) * 0.5
    );
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.getSize = function()
{
    switch (this.extent)
    {
    case Athena.Math.AxisAlignedBox_EXTENT_NULL:
        return new Athena.Math.Vector3(Athena.Math.Vector3_ZERO);

    case Athena.Math.AxisAlignedBox_EXTENT_FINITE:
        return this.maximum.sub(this.minimum);

    case Athena.Math.AxisAlignedBox_EXTENT_INFINITE:
        return new Athena.Math.Vector3(Infinity);
    }
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.getHalfSize = function()
{
    switch (this.extent)
    {
    case Athena.Math.AxisAlignedBox_EXTENT_NULL:
        return new Athena.Math.Vector3(Athena.Math.Vector3_ZERO);
    
    case Athena.Math.AxisAlignedBox_EXTENT_FINITE:
        return this.maximum.sub(this.minimum).mul(0.5);
    
    case Athena.Math.AxisAlignedBox_EXTENT_INFINITE:
        return new Athena.Math.Vector3(Infinity);
    }
}

//-----------------------------------------------------------------------

Athena.Math.AxisAlignedBox.prototype.contains = function()
{
    if (arguments[0].__classname__ == 'Athena.Math.Vector3')
    {
        if (this.isNull())
             return false;
     
        if (this.isInfinite())
             return true;

        return arguments[0].greaterThan(this.minimum) && this.maximum.greaterThan(arguments[0]);
    }
    else if (arguments[0].__classname__ == 'Athena.Math.AxisAlignedBox')
    {
        if (arguments[0].isNull() || this.isInfinite())
             return true;
     
        if (this.isNull() || arguments[0].isInfinite())
             return false;

        return arguments[0].minimum.greaterThan(this.minimum) &&
               this.maximum.greaterThan(arguments[0].maximum);
    }
}


/**************************************** OTHERS ***************************************/

Athena.Math.AxisAlignedBox.prototype.__classname__ = 'Athena.Math.AxisAlignedBox';

Athena.Math.AxisAlignedBox_EXTENT_NULL       = 0;
Athena.Math.AxisAlignedBox_EXTENT_FINITE     = 1;
Athena.Math.AxisAlignedBox_EXTENT_INFINITE   = 2;

Athena.Math.AxisAlignedBox_FAR_LEFT_BOTTOM   = 0;
Athena.Math.AxisAlignedBox_FAR_LEFT_TOP      = 1;
Athena.Math.AxisAlignedBox_FAR_RIGHT_TOP     = 2;
Athena.Math.AxisAlignedBox_FAR_RIGHT_BOTTOM  = 3;
Athena.Math.AxisAlignedBox_NEAR_RIGHT_BOTTOM = 7;
Athena.Math.AxisAlignedBox_NEAR_LEFT_BOTTOM  = 6;
Athena.Math.AxisAlignedBox_NEAR_LEFT_TOP     = 5;
Athena.Math.AxisAlignedBox_NEAR_RIGHT_TOP    = 4;

Athena.Math.AxisAlignedBox_BOX_NULL     = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_NULL);
Athena.Math.AxisAlignedBox_BOX_INFINITE = new Athena.Math.AxisAlignedBox(Athena.Math.AxisAlignedBox_EXTENT_INFINITE);

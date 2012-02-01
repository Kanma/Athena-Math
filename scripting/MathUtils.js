/** @file   MathUtils.js
    @author Philip Abbet
    
    Declaration of math-related functions
    
    @note   Using a pure JavaScript implementation here instead of a
            binding over the C++ functions results in faster code.
*/


Athena.Math.sign = function(v)
{
    if (v > 0.0)
        return 1.0;

    if (v < 0.0)
        return -1.0;

    return 0.0;
}

//-----------------------------------------------------------------------

Athena.Math.log2 = function(v)
{
    return Math.log(v) / Math.LN2;
}

//-----------------------------------------------------------------------

Athena.Math.logn = function(base, v)
{
    return Math.log(v) / Math.log(base);
}

//-----------------------------------------------------------------------

Athena.Math.invsqrt = function(v)
{
    return 1.0 / Math.sqrt(v);
}

//-----------------------------------------------------------------------

Athena.Math.equals = function(a, b, tolerance)
{
    if (tolerance === undefined)
        tolerance = 1e-6;
    
    return Math.abs(b - a) <= tolerance;
}

//-----------------------------------------------------------------------

Athena.Math.clamp = function(v, minval, maxval)
{
    return Math.max(Math.min(v, maxval), minval);
}

//-----------------------------------------------------------------------

Athena.Math.degToRad = function(v)
{
    return v * Math.PI / 180.0;
}

//-----------------------------------------------------------------------

Athena.Math.radToDeg = function(v)
{
    return v * 180.0 / Math.PI;
}

//-----------------------------------------------------------------------

Athena.Math.acos = function(v)
{
    if (-1.0 < v)
    {
        if (v < 1.0)
            return Math.acos(v);
        else
            return 0.0;
    }
    else
    {
        return Math.PI;
    }
}

//-----------------------------------------------------------------------

Athena.Math.asin = function(v)
{
    if (-1.0 < v)
    {
        if (v < 1.0)
            return Math.asin(v);
        else
            return Math.PI * 0.5;
    }
    else
    {
        return -Math.PI * 0.5;
    }
}

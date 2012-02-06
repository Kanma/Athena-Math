/** @file   Color.js
    @author Philip Abbet
    
    Declaration of the class Athena.Math.Color
    
    @note   Using a pure JavaScript class here instead of a binding over
            the C++ one results in faster code.
*/

Athena.Math.Color = function()
{
    if (arguments.length == 0)
    {
        this.r = 1.0;
        this.g = 1.0;
        this.b = 1.0;
        this.a = 1.0;
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Color'))
    {
        this.r = arguments[0].r;
        this.g = arguments[0].g;
        this.b = arguments[0].b;
        this.a = arguments[0].a;
    }
    else if (arguments.length == 3)
    {
        this.r = arguments[0];
        this.g = arguments[1];
        this.b = arguments[2];
        this.a = 1.0;
    }
    else if (arguments.length == 4)
    {
        this.r = arguments[0];
        this.g = arguments[1];
        this.b = arguments[2];
        this.a = arguments[3];
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nColor()\nColor(color)\nColor(r, g, b)\nColor(r, g, b, a)';
    }
}


/*********************************** VALUE ASSIGNATION **********************************/

Athena.Math.Color.prototype.set = function()
{
    if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Color'))
    {
        this.r = arguments[0].r;
        this.g = arguments[0].g;
        this.b = arguments[0].b;
        this.a = arguments[0].a;
    }
    else if (arguments.length == 3)
    {
        this.r = arguments[0];
        this.g = arguments[1];
        this.b = arguments[2];
        this.a = 1.0;
    }
    else if (arguments.length == 4)
    {
        this.r = arguments[0];
        this.g = arguments[1];
        this.b = arguments[2];
        this.a = arguments[3];
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nset(color)\nset(r, g, b)\nset(r, g, b, a)';
    }
}


/********************************* COMPARISON OPERATIONS ********************************/

Athena.Math.Color.prototype.equals = function(color)
{
    return (this.r == color.r) && (this.g == color.g) && (this.b == color.b) && (this.a == color.a);
}

//-----------------------------------------------------------------------

Athena.Math.Color.prototype.notEquals = function(plane)
{
    return (this.r != plane.r) || (this.g != plane.g) || (this.b != plane.b) || (this.a != plane.a);
}


/**************************************** METHODS ***************************************/

Athena.Math.Color.prototype.saturate = function()
{
    if (this.r < 0)
        this.r = 0;
    else if (this.r > 1)
        this.r = 1;

    if (this.g < 0)
        this.g = 0;
    else if (this.g > 1)
        this.g = 1;

    if (this.b < 0)
        this.b = 0;
    else if (this.b > 1)
        this.b = 1;

    if (this.a < 0)
        this.a = 0;
    else if (this.a > 1)
        this.a = 1;
}

//-----------------------------------------------------------------------

Athena.Math.Color.prototype.saturateCopy = function()
{
    var color = new Athena.Math.Color(this);
    color.saturate();
    return color;
}


/********************************* ARITHMETIC OPERATIONS ********************************/

Athena.Math.Color.prototype.add = function()
{
    var c = new Athena.Math.Color(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            c.r += arguments[i].r;
            c.g += arguments[i].g;
            c.b += arguments[i].b;
            c.a += arguments[i].a;
        }
        else
        {
            c.r += arguments[i];
            c.g += arguments[i];
            c.b += arguments[i];
            c.a += arguments[i];
        }
    }

    return c;
}

//-----------------------------------------------------------------------

Athena.Math.Color.prototype.sub = function()
{
    var c = new Athena.Math.Color(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            c.r -= arguments[i].r;
            c.g -= arguments[i].g;
            c.b -= arguments[i].b;
            c.a -= arguments[i].a;
        }
        else
        {
            c.r -= arguments[i];
            c.g -= arguments[i];
            c.b -= arguments[i];
            c.a -= arguments[i];
        }
    }

    return c;
}

//-----------------------------------------------------------------------

Athena.Math.Color.prototype.mul = function()
{
    var c = new Athena.Math.Color(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            c.r *= arguments[i].r;
            c.g *= arguments[i].g;
            c.b *= arguments[i].b;
            c.a *= arguments[i].a;
        }
        else
        {
            c.r *= arguments[i];
            c.g *= arguments[i];
            c.b *= arguments[i];
            c.a *= arguments[i];
        }
    }

    return c;
}

//-----------------------------------------------------------------------

Athena.Math.Color.prototype.divide = function()
{
    var c = new Athena.Math.Color(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            c.r /= arguments[i].r;
            c.g /= arguments[i].g;
            c.b /= arguments[i].b;
            c.a /= arguments[i].a;
        }
        else
        {
            c.r /= arguments[i];
            c.g /= arguments[i];
            c.b /= arguments[i];
            c.a /= arguments[i];
        }
    }

    return c;
}


/********************************** ARITHMETIC UPDATES **********************************/

Athena.Math.Color.prototype.iadd = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.r += arguments[i].r;
            this.g += arguments[i].g;
            this.b += arguments[i].b;
            this.a += arguments[i].a;
        }
        else
        {
            this.r += arguments[i];
            this.g += arguments[i];
            this.b += arguments[i];
            this.a += arguments[i];
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.Color.prototype.isub = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.r -= arguments[i].r;
            this.g -= arguments[i].g;
            this.b -= arguments[i].b;
            this.a -= arguments[i].a;
        }
        else
        {
            this.r -= arguments[i];
            this.g -= arguments[i];
            this.b -= arguments[i];
            this.a -= arguments[i];
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.Color.prototype.imul = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.r *= arguments[i].r;
            this.g *= arguments[i].g;
            this.b *= arguments[i].b;
            this.a *= arguments[i].a;
        }
        else
        {
            this.r *= arguments[i];
            this.g *= arguments[i];
            this.b *= arguments[i];
            this.a *= arguments[i];
        }
    }
}

//-----------------------------------------------------------------------

Athena.Math.Color.prototype.idivide = function()
{
    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            this.r /= arguments[i].r;
            this.g /= arguments[i].g;
            this.b /= arguments[i].b;
            this.a /= arguments[i].a;
        }
        else
        {
            this.r /= arguments[i];
            this.g /= arguments[i];
            this.b /= arguments[i];
            this.a /= arguments[i];
        }
    }
}


/******************************** COLOR-SPACE CONVERSION ********************************/

Athena.Math.Color.prototype.setHSB = function(hue, saturation, brightness)
{
    // wrap hue
    if (hue > 1.0)
        hue -= parseInt(hue);
    else if (hue < 0.0)
        hue += parseInt(hue + 1);
    
    // clamp saturation / brightness
    saturation = Math.min(saturation, 1.0);
    saturation = Math.max(saturation, 0.0);
    brightness = Math.min(brightness, 1.0);
    brightness = Math.max(brightness, 0.0);
    
    if (brightness == 0.0)
    {   
        // early exit, this has to be black
        this.r = 0.0;
        this.g = 0.0;
        this.b = 0.0;
        return;
    }
    
    if (saturation == 0.0)
    {   
        // early exit, this has to be grey
        this.r = brightness;
        this.g = brightness;
        this.b = brightness;
        return;
    }
    
    
    var hueDomain  = hue * 6.0;
    if (hueDomain >= 6.0)
    {
        // wrap around, and allow mathematical errors
        hueDomain = 0.0;
    }
    
    var domain = parseInt(hueDomain);
    var f1 = brightness * (1 - saturation);
    var f2 = brightness * (1 - saturation * (hueDomain - domain));
    var f3 = brightness * (1 - saturation * (1 - (hueDomain - domain)));
    
    switch (domain)
    {
    case 0:
        // red domain; green ascends
        this.r = brightness;
        this.g = f3;
        this.b = f1;
        break;
    case 1:
        // yellow domain; red descends
        this.r = f2;
        this.g = brightness;
        this.b = f1;
        break;
    case 2:
        // green domain; blue ascends
        this.r = f1;
        this.g = brightness;
        this.b = f3;
        break;
    case 3:
        // cyan domain; green descends
        this.r = f1;
        this.g = f2;
        this.b = brightness;
        break;
    case 4:
        // blue domain; red ascends
        this.r = f3;
        this.g = f1;
        this.b = brightness;
        break;
    case 5:
        // magenta domain; blue descends
        this.r = brightness;
        this.g = f1;
        this.b = f2;
        break;
    }
}

//-----------------------------------------------------------------------

Athena.Math.Color.prototype.getHSB = function()
{
    var vMin = Math.min(this.r, Math.min(this.g, this.b));
    var vMax = Math.max(this.r, Math.max(this.g, this.b));
    var delta = vMax - vMin;
    
    var brightness = vMax;
    var hue;
    var saturation;
    
    if (Athena.Math.equals(delta, 0.0, 1e-6))
    {
        // grey
        hue = 0;
        saturation = 0;
    }
    else                                    
    {
        // a colour
        saturation = delta / vMax;
    
        var deltaR = (((vMax - this.r) / 6.0) + (delta / 2.0)) / delta;
        var deltaG = (((vMax - this.g) / 6.0) + (delta / 2.0)) / delta;
        var deltaB = (((vMax - this.b) / 6.0) + (delta / 2.0)) / delta;
    
        if (Athena.Math.equals(this.r, vMax))
            hue = deltaB - deltaG;
        else if (Athena.Math.equals(this.g, vMax))
            hue = 0.3333333 + deltaR - deltaB;
        else if (Athena.Math.equals(this.b, vMax)) 
            hue = 0.6666667 + deltaG - deltaR;
    
        if (hue < 0.0) 
            hue += 1.0;
        if (hue > 1.0)
            hue -= 1.0;
    }
    
    return { hue: hue, saturation: saturation, brightness: brightness };
}


/**************************************** OTHERS ***************************************/

Athena.Math.Color.prototype.__classname__ = 'Athena.Math.Color';

Athena.Math.Color_ZERO  = new Athena.Math.Color(0.0, 0.0, 0.0, 0.0);
Athena.Math.Color_BLACK = new Athena.Math.Color(0.0, 0.0, 0.0, 1.0);
Athena.Math.Color_WHITE = new Athena.Math.Color(1.0, 1.0, 1.0, 1.0);
Athena.Math.Color_RED   = new Athena.Math.Color(1.0, 0.0, 0.0, 1.0);
Athena.Math.Color_GREEN = new Athena.Math.Color(0.0, 1.0, 0.0, 1.0);
Athena.Math.Color_BLUE  = new Athena.Math.Color(0.0, 0.0, 1.0, 1.0);

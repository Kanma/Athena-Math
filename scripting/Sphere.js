/** @file   Sphere.js
    @author Philip Abbet
    
    Declaration of the class Athena.Math.Sphere
    
    @note   Using a pure JavaScript class here instead of a binding over
            the C++ one results in faster code.
*/

Athena.Math.Sphere = function()
{
    if (arguments.length == 0)
    {
        this.center = new Athena.Math.Vector3();
        this.radius = 0.0;
    }
    else if ((arguments.length == 2) && (typeof(arguments[0]) === 'object') && ((arguments[0].__classname__ == 'Athena.Math.Vector3')))
    {
        this.center = arguments[0];
        this.radius = arguments[1];
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nSphere()\nSphere(center, radius)';
    }
}


/*********************************** VALUE ASSIGNATION **********************************/

Athena.Math.Sphere.prototype.set = function()
{
    if ((arguments.length == 2) && (typeof(arguments[0]) === 'object') && ((arguments[0].__classname__ == 'Athena.Math.Vector3')))
    {
        this.center = arguments[0];
        this.radius = arguments[1];
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nset(center, radius)';
    }
}


/**************************************** OTHERS ***************************************/

Athena.Math.Sphere.prototype.__classname__ = 'Athena.Math.Sphere';

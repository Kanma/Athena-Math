/** @file   Matrix3.js
    @author Philip Abbet
    
    Declaration of the class Athena.Math.Matrix3
    
    @note   Using a pure JavaScript class here instead of a binding over
            the C++ one results in faster code.
*/

Athena.Math.Matrix3 = function()
{
    if (arguments.length == 0)
    {
        this.m_0_0 = 0.0;
        this.m_0_1 = 0.0;
        this.m_0_2 = 0.0;
        this.m_1_0 = 0.0;
        this.m_1_1 = 0.0;
        this.m_1_2 = 0.0;
        this.m_2_0 = 0.0;
        this.m_2_1 = 0.0;
        this.m_2_2 = 0.0;
    }
    else if (arguments.length == 9)
    {
        this.m_0_0 = arguments[0];
        this.m_0_1 = arguments[1];
        this.m_0_2 = arguments[2];
        this.m_1_0 = arguments[3];
        this.m_1_1 = arguments[4];
        this.m_1_2 = arguments[5];
        this.m_2_0 = arguments[6];
        this.m_2_1 = arguments[7];
        this.m_2_2 = arguments[8];
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') &&
             (arguments[0].__classname__ == 'Athena.Math.Matrix3'))
    {
        this.m_0_0 = arguments[0].m_0_0;
        this.m_0_1 = arguments[0].m_0_1;
        this.m_0_2 = arguments[0].m_0_2;
        this.m_1_0 = arguments[0].m_1_0;
        this.m_1_1 = arguments[0].m_1_1;
        this.m_1_2 = arguments[0].m_1_2;
        this.m_2_0 = arguments[0].m_2_0;
        this.m_2_1 = arguments[0].m_2_1;
        this.m_2_2 = arguments[0].m_2_2;
    }
    else if ((arguments.length == 3) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[1]) === 'object') && (arguments[1].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[2]) === 'object') && (arguments[2].__classname__ == 'Athena.Math.Vector3'))
    {
        this.m_0_0 = arguments[0].x;
        this.m_0_1 = arguments[1].x;
        this.m_0_2 = arguments[2].x;
        this.m_1_0 = arguments[0].y;
        this.m_1_1 = arguments[1].y;
        this.m_1_2 = arguments[2].y;
        this.m_2_0 = arguments[0].z;
        this.m_2_1 = arguments[1].z;
        this.m_2_2 = arguments[2].z;
    }
    else if ((arguments.length == 2) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[1]) === 'number'))
    {
        var fCos = Math.cos(arguments[1]);
        var fSin = Math.sin(arguments[1]);
        var fOneMinusCos = 1.0-fCos;
        var fX2 = arguments[0].x*arguments[0].x;
        var fY2 = arguments[0].y*arguments[0].y;
        var fZ2 = arguments[0].z*arguments[0].z;
        var fXYM = arguments[0].x*arguments[0].y*fOneMinusCos;
        var fXZM = arguments[0].x*arguments[0].z*fOneMinusCos;
        var fYZM = arguments[0].y*arguments[0].z*fOneMinusCos;
        var fXSin = arguments[0].x*fSin;
        var fYSin = arguments[0].y*fSin;
        var fZSin = arguments[0].z*fSin;

        this.m_0_0 = fX2*fOneMinusCos+fCos;
        this.m_0_1 = fXYM-fZSin;
        this.m_0_2 = fXZM+fYSin;
        this.m_1_0 = fXYM+fZSin;
        this.m_1_1 = fY2*fOneMinusCos+fCos;
        this.m_1_2 = fYZM-fXSin;
        this.m_2_0 = fXZM-fYSin;
        this.m_2_1 = fYZM+fXSin;
        this.m_2_2 = fZ2*fOneMinusCos+fCos;
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nMatrix3()\nMatrix3(<9 * numbers>)\nMatrix3(matrix3)\nMatrix3(vector3, vector3, vector3)\nMatrix3(vector3, angle)';
    }
}


/************************************ VALUE RETRIEVAL ***********************************/

Athena.Math.Matrix3.prototype.get = function(row, col)
{
    return this['m_' + row + '_' + col];
}


/*********************************** VALUE ASSIGNATION **********************************/

Athena.Math.Matrix3.prototype.set = function()
{
    if (arguments.length == 9)
    {
        this.m_0_0 = arguments[0];
        this.m_0_1 = arguments[1];
        this.m_0_2 = arguments[2];
        this.m_1_0 = arguments[3];
        this.m_1_1 = arguments[4];
        this.m_1_2 = arguments[5];
        this.m_2_0 = arguments[6];
        this.m_2_1 = arguments[7];
        this.m_2_2 = arguments[8];
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') &&
             (arguments[0].__classname__ == 'Athena.Math.Matrix3'))
    {
        this.m_0_0 = arguments[0].m_0_0;
        this.m_0_1 = arguments[0].m_0_1;
        this.m_0_2 = arguments[0].m_0_2;
        this.m_1_0 = arguments[0].m_1_0;
        this.m_1_1 = arguments[0].m_1_1;
        this.m_1_2 = arguments[0].m_1_2;
        this.m_2_0 = arguments[0].m_2_0;
        this.m_2_1 = arguments[0].m_2_1;
        this.m_2_2 = arguments[0].m_2_2;
    }
    else if ((arguments.length == 3) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[1]) === 'object') && (arguments[1].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[2]) === 'object') && (arguments[2].__classname__ == 'Athena.Math.Vector3'))
    {
        this.m_0_0 = arguments[0].x;
        this.m_0_1 = arguments[1].x;
        this.m_0_2 = arguments[2].x;
        this.m_1_0 = arguments[0].y;
        this.m_1_1 = arguments[1].y;
        this.m_1_2 = arguments[2].y;
        this.m_2_0 = arguments[0].z;
        this.m_2_1 = arguments[1].z;
        this.m_2_2 = arguments[2].z;
    }
    else if ((arguments.length == 2) &&
             (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3') &&
             (typeof(arguments[1]) === 'number'))
    {
        var fCos = Math.cos(arguments[1]);
        var fSin = Math.sin(arguments[1]);
        var fOneMinusCos = 1.0-fCos;
        var fX2 = arguments[0].x*arguments[0].x;
        var fY2 = arguments[0].y*arguments[0].y;
        var fZ2 = arguments[0].z*arguments[0].z;
        var fXYM = arguments[0].x*arguments[0].y*fOneMinusCos;
        var fXZM = arguments[0].x*arguments[0].z*fOneMinusCos;
        var fYZM = arguments[0].y*arguments[0].z*fOneMinusCos;
        var fXSin = arguments[0].x*fSin;
        var fYSin = arguments[0].y*fSin;
        var fZSin = arguments[0].z*fSin;

        this.m_0_0 = fX2*fOneMinusCos+fCos;
        this.m_0_1 = fXYM-fZSin;
        this.m_0_2 = fXZM+fYSin;
        this.m_1_0 = fXYM+fZSin;
        this.m_1_1 = fY2*fOneMinusCos+fCos;
        this.m_1_2 = fYZM-fXSin;
        this.m_2_0 = fXZM-fYSin;
        this.m_2_1 = fYZM+fXSin;
        this.m_2_2 = fZ2*fOneMinusCos+fCos;
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nset()\nset(<9 * numbers>)\nset(matrix3)\nset(vector3, vector3, vector3)\nset(vector3, angle)';
    }
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.fromEulerAnglesXYZ = function(yaw, pitch, roll)
{
    var fCos = Math.cos(yaw);
    var fSin = Math.sin(yaw);
    
    var kXMat = new Athena.Math.Matrix3(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    fCos =  Math.cos(pitch);
    fSin =  Math.sin(pitch);
    
    var kYMat = new Athena.Math.Matrix3(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    fCos =  Math.cos(roll);
    fSin =  Math.sin(roll);

    var kZMat = new Athena.Math.Matrix3(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    this.set(kXMat.mul(kYMat.mul(kZMat)));
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.fromEulerAnglesXZY = function(yaw, pitch, roll)
{
    var fCos = Math.cos(yaw);
    var fSin = Math.sin(yaw);
    
    var kXMat = new Athena.Math.Matrix3(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    fCos =  Math.cos(pitch);
    fSin =  Math.sin(pitch);
    
    var kYMat = new Athena.Math.Matrix3(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    fCos =  Math.cos(roll);
    fSin =  Math.sin(roll);

    var kZMat = new Athena.Math.Matrix3(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    this.set(kXMat.mul(kZMat.mul(kYMat)));
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.fromEulerAnglesYXZ = function(yaw, pitch, roll)
{
    var fCos = Math.cos(yaw);
    var fSin = Math.sin(yaw);
    
    var kXMat = new Athena.Math.Matrix3(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    fCos =  Math.cos(pitch);
    fSin =  Math.sin(pitch);
    
    var kYMat = new Athena.Math.Matrix3(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    fCos =  Math.cos(roll);
    fSin =  Math.sin(roll);

    var kZMat = new Athena.Math.Matrix3(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    this.set(kYMat.mul(kXMat.mul(kZMat)));
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.fromEulerAnglesYZX = function(yaw, pitch, roll)
{
    var fCos = Math.cos(yaw);
    var fSin = Math.sin(yaw);
    
    var kXMat = new Athena.Math.Matrix3(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    fCos =  Math.cos(pitch);
    fSin =  Math.sin(pitch);
    
    var kYMat = new Athena.Math.Matrix3(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    fCos =  Math.cos(roll);
    fSin =  Math.sin(roll);

    var kZMat = new Athena.Math.Matrix3(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    this.set(kYMat.mul(kZMat.mul(kXMat)));
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.fromEulerAnglesZXY = function(yaw, pitch, roll)
{
    var fCos = Math.cos(yaw);
    var fSin = Math.sin(yaw);
    
    var kXMat = new Athena.Math.Matrix3(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    fCos =  Math.cos(pitch);
    fSin =  Math.sin(pitch);
    
    var kYMat = new Athena.Math.Matrix3(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    fCos =  Math.cos(roll);
    fSin =  Math.sin(roll);

    var kZMat = new Athena.Math.Matrix3(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    this.set(kZMat.mul(kXMat.mul(kYMat)));
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.fromEulerAnglesZYX = function(yaw, pitch, roll)
{
    var fCos = Math.cos(yaw);
    var fSin = Math.sin(yaw);
    
    var kXMat = new Athena.Math.Matrix3(fCos,-fSin,0.0,fSin,fCos,0.0,0.0,0.0,1.0);

    fCos =  Math.cos(pitch);
    fSin =  Math.sin(pitch);
    
    var kYMat = new Athena.Math.Matrix3(fCos,0.0,fSin,0.0,1.0,0.0,-fSin,0.0,fCos);

    fCos =  Math.cos(roll);
    fSin =  Math.sin(roll);

    var kZMat = new Athena.Math.Matrix3(1.0,0.0,0.0,0.0,fCos,-fSin,0.0,fSin,fCos);

    this.set(kZMat.mul(kYMat.mul(kXMat)));
}


/********************************* COMPARISON OPERATIONS ********************************/

Athena.Math.Matrix3.prototype.equals = function(matrix)
{
    return (this.m_0_0 == matrix.m_0_0) && (this.m_0_1 == matrix.m_0_1) && (this.m_0_2 == matrix.m_0_2) &&
           (this.m_1_0 == matrix.m_1_0) && (this.m_1_1 == matrix.m_1_1) && (this.m_1_2 == matrix.m_1_2) &&
           (this.m_2_0 == matrix.m_2_0) && (this.m_2_1 == matrix.m_2_1) && (this.m_2_2 == matrix.m_2_2);
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.notEquals = function(matrix)
{
    return (this.m_0_0 != matrix.m_0_0) || (this.m_0_1 != matrix.m_0_1) || (this.m_0_2 != matrix.m_0_2) ||
           (this.m_1_0 != matrix.m_1_0) || (this.m_1_1 != matrix.m_1_1) || (this.m_1_2 != matrix.m_1_2) ||
           (this.m_2_0 != matrix.m_2_0) || (this.m_2_1 != matrix.m_2_1) || (this.m_2_2 != matrix.m_2_2);
}


/**************************************** OTHERS ***************************************/

Athena.Math.Matrix3.prototype.__classname__ = 'Athena.Math.Matrix3';

Athena.Math.Matrix3_ZERO     = new Athena.Math.Matrix3();
Athena.Math.Matrix3_IDENTITY = new Athena.Math.Matrix3(1.0, 0.0, 0.0,
                                                       0.0, 1.0, 0.0,
                                                       0.0, 0.0, 1.0);

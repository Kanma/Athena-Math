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


/********************************* ARITHMETIC OPERATIONS ********************************/

Athena.Math.Matrix3.prototype.add = function()
{
    var r = new Athena.Math.Matrix3(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if ((typeof(arguments[i]) === 'object') && (arguments[i].__classname__ == 'Athena.Math.Matrix3'))
        {
            r.m_0_0 += arguments[i].m_0_0;
            r.m_0_1 += arguments[i].m_0_1;  
            r.m_0_2 += arguments[i].m_0_2;
            r.m_1_0 += arguments[i].m_1_0;
            r.m_1_1 += arguments[i].m_1_1;  
            r.m_1_2 += arguments[i].m_1_2;
            r.m_2_0 += arguments[i].m_2_0;
            r.m_2_1 += arguments[i].m_2_1;  
            r.m_2_2 += arguments[i].m_2_2;
        }
    }

    return r;
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.sub = function()
{
    var r = new Athena.Math.Matrix3(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if ((typeof(arguments[i]) === 'object') && (arguments[i].__classname__ == 'Athena.Math.Matrix3'))
        {
            r.m_0_0 -= arguments[i].m_0_0;
            r.m_0_1 -= arguments[i].m_0_1;  
            r.m_0_2 -= arguments[i].m_0_2;
            r.m_1_0 -= arguments[i].m_1_0;
            r.m_1_1 -= arguments[i].m_1_1;  
            r.m_1_2 -= arguments[i].m_1_2;
            r.m_2_0 -= arguments[i].m_2_0;
            r.m_2_1 -= arguments[i].m_2_1;  
            r.m_2_2 -= arguments[i].m_2_2;
        }
    }

    return r;
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.mul = function()
{
    if ((arguments.length == 1) && (typeof(arguments[0]) === 'object'))
    {
        if (arguments[0].__classname__ == 'Athena.Math.Vector3')
        {
            return new Athena.Math.Vector3(
                this.m_0_0 * arguments[0].x + this.m_0_1 * arguments[0].y + this.m_0_2 * arguments[0].z,
                this.m_1_0 * arguments[0].x + this.m_1_1 * arguments[0].y + this.m_1_2 * arguments[0].z,
                this.m_2_0 * arguments[0].x + this.m_2_1 * arguments[0].y + this.m_2_2 * arguments[0].z
            );
        }
        else if (arguments[0].__classname__ == 'Athena.Math.Matrix3')
        {
            var r = new Athena.Math.Matrix3();
        
            r.m_0_0 += this.m_0_0 * arguments[0].m_0_0 + this.m_0_1 * arguments[0].m_1_0 + this.m_0_2 * arguments[0].m_2_0;
            r.m_0_1 += this.m_0_0 * arguments[0].m_0_1 + this.m_0_1 * arguments[0].m_1_1 + this.m_0_2 * arguments[0].m_2_1;  
            r.m_0_2 += this.m_0_0 * arguments[0].m_0_2 + this.m_0_1 * arguments[0].m_1_2 + this.m_0_2 * arguments[0].m_2_2;
                                                                                                                    
            r.m_1_0 += this.m_1_0 * arguments[0].m_0_0 + this.m_1_1 * arguments[0].m_1_0 + this.m_1_2 * arguments[0].m_2_0;
            r.m_1_1 += this.m_1_0 * arguments[0].m_0_1 + this.m_1_1 * arguments[0].m_1_1 + this.m_1_2 * arguments[0].m_2_1;  
            r.m_1_2 += this.m_1_0 * arguments[0].m_0_2 + this.m_1_1 * arguments[0].m_1_2 + this.m_1_2 * arguments[0].m_2_2;
                                                                                                                    
            r.m_2_0 += this.m_2_0 * arguments[0].m_0_0 + this.m_2_1 * arguments[0].m_1_0 + this.m_2_2 * arguments[0].m_2_0;
            r.m_2_1 += this.m_2_0 * arguments[0].m_0_1 + this.m_2_1 * arguments[0].m_1_1 + this.m_2_2 * arguments[0].m_2_1;  
            r.m_2_2 += this.m_2_0 * arguments[0].m_0_2 + this.m_2_1 * arguments[0].m_1_2 + this.m_2_2 * arguments[0].m_2_2;
            
            return r;
        }
    }

    var r = new Athena.Math.Matrix3(this);

    for (var i = 0; i < arguments.length; i++)
    {
        r.m_0_0 *= arguments[i];
        r.m_0_1 *= arguments[i];
        r.m_0_2 *= arguments[i];
        r.m_1_0 *= arguments[i];
        r.m_1_1 *= arguments[i];
        r.m_1_2 *= arguments[i];
        r.m_2_0 *= arguments[i];
        r.m_2_1 *= arguments[i];
        r.m_2_2 *= arguments[i];
    }

    return r;
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.negate = function()
{
    return new Athena.Math.Matrix3(-this.m_0_0, -this.m_0_1, -this.m_0_2,
                                   -this.m_1_0, -this.m_1_1, -this.m_1_2,
                                   -this.m_2_0, -this.m_2_1, -this.m_2_2);
}


/**************************************** METHODS ***************************************/

Athena.Math.Matrix3.prototype.transpose = function()
{
    return new Athena.Math.Matrix3(
        this.m_0_0, this.m_1_0, this.m_2_0,
        this.m_0_1, this.m_1_1, this.m_2_1,
        this.m_0_2, this.m_1_2, this.m_2_2
    );
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.inverse = function()
{
    var tolerance = 1e-06;
    if (arguments.length == 1)
        tolerance = arguments[0];

    var rkInverse = new Athena.Math.Matrix3();
    
    rkInverse.m_0_0 = this.m_1_1 * this.m_2_2 - this.m_1_2 * this.m_2_1;
    rkInverse.m_0_1 = this.m_0_2 * this.m_2_1 - this.m_0_1 * this.m_2_2;
    rkInverse.m_0_2 = this.m_0_1 * this.m_1_2 - this.m_0_2 * this.m_1_1;
    rkInverse.m_1_0 = this.m_1_2 * this.m_2_0 - this.m_1_0 * this.m_2_2;
    rkInverse.m_1_1 = this.m_0_0 * this.m_2_2 - this.m_0_2 * this.m_2_0;
    rkInverse.m_1_2 = this.m_0_2 * this.m_1_0 - this.m_0_0 * this.m_1_2;
    rkInverse.m_2_0 = this.m_1_0 * this.m_2_1 - this.m_1_1 * this.m_2_0;
    rkInverse.m_2_1 = this.m_0_1 * this.m_2_0 - this.m_0_0 * this.m_2_1;
    rkInverse.m_2_2 = this.m_0_0 * this.m_1_1 - this.m_0_1 * this.m_1_0;

    var det = this.m_0_0 * rkInverse.m_0_0 + this.m_0_1 * rkInverse.m_1_0 + this.m_0_2 * rkInverse.m_2_0;

    if (Math.abs(det) <= tolerance)
        return new Athena.Math.Matrix3(Athena.Math.Matrix3_ZERO);

    return rkInverse.mul(1.0 / det);
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.determinant = function()
{
    var cofactor_0_0 = this.m_1_1 * this.m_2_2 - this.m_1_2 * this.m_2_1;
    var cofactor_1_0 = this.m_1_2 * this.m_2_0 - this.m_1_0 * this.m_2_2;
    var cofactor_2_0 = this.m_1_0 * this.m_2_1 - this.m_1_1 * this.m_2_0;

    return this.m_0_0 * rkInverse.m_0_0 + this.m_0_1 * rkInverse.m_1_0 + this.m_0_2 * rkInverse.m_2_0;
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.toAxisAngle = function()
{
    var axis = new Athena.Math.Vector3(Athena.Math.Vector3_UNIT_X);
    var angle = 0.0;
    
    var fTrace = this.m_0_0 + this.m_1_1 + this.m_2_2;
    var fCos = 0.5 * (fTrace - 1.0);
    angle = Math.acos(fCos);  // in [0,PI]

    if (angle > 0.0)
    {
        if (angle < Math.PI)
        {
            axis.x = this.m_2_1 - this.m_1_2;
            axis.y = this.m_0_2 - this.m_2_0;
            axis.z = this.m_1_0 - this.m_0_1;
            axis.normalise();
        }
        else
        {
            // angle is PI
            var fHalfInverse;
            if (this.m_0_0 >= this.m_1_1)
            {
                // r00 >= r11
                if (this.m_0_0 >= this.m_2_2)
                {
                    // r00 is maximum diagonal term
                    axis.x = 0.5 * Math.sqrt(this.m_0_0 - this.m_1_1 - this.m_2_2 + 1.0);
                    fHalfInverse = 0.5 / axis.x;
                    axis.y = fHalfInverse * this.m_0_1;
                    axis.z = fHalfInverse * this.m_0_2;
                }
                else
                {
                    // r22 is maximum diagonal term
                    axis.z = 0.5 * Math.sqrt(this.m_2_2 - this.m_0_0 - this.m_1_1 + 1.0);
                    fHalfInverse = 0.5 / axis.z;
                    axis.x = fHalfInverse * this.m_0_2;
                    axis.y = fHalfInverse * this.m_1_2;
                }
            }
            else
            {
                // r11 > r00
                if (this.m_1_1 >= this.m_2_2)
                {
                    // r11 is maximum diagonal term
                    axis.y = 0.5 * Math.sqrt(this.m_1_1 - this.m_0_0 - this.m_2_2 + 1.0);
                    fHalfInverse  = 0.5 / axis.y;
                    axis.x = fHalfInverse * this.m_0_1;
                    axis.z = fHalfInverse * this.m_1_2;
                }
                else
                {
                    // r22 is maximum diagonal term
                    axis.z = 0.5 * Math.sqrt(this.m_2_2 - this.m_0_0 - this.m_1_1 + 1.0);
                    fHalfInverse = 0.5 / axis.z;
                    axis.x = fHalfInverse * this.m_0_2;
                    axis.y = fHalfInverse * this.m_1_2;
                }
            }
        }
    }

    return { axis: axis, angle: angle};
}


//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.toEulerAnglesXYZ = function()
{
    // rot =  cy*cz          -cy*sz           sy
    //        cz*sx*sy+cx*sz  cx*cz-sx*sy*sz -cy*sx
    //       -cx*cz*sy+sx*sz  cz*sx+cx*sy*sz  cx*cy

    var pitch = Athena.Math.asin(this.m_0_2);

    if (pitch < Math.PI * 0.5)
    {
        if (pitch > -Math.PI * 0.5)
        {
            var yaw = Math.atan2(-this.m_1_2, this.m_2_2);
            var roll = Math.atan2(-this.m_0_1, this.m_0_0);
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
        else
        {
            // WARNING.  Not a unique solution.
            var fRmY = Math.atan2(this.m_1_0, this.m_1_1);
            var roll = 0.0;  // any angle works
            var yaw = roll - fRmY;
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        var fRpY = Math.atan2(this.m_1_0, this.m_1_1);
        var roll = 0.0;  // any angle works
        var yaw = fRpY - roll;
        return { pitch: pitch, yaw: yaw, roll: roll };
    }
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.toEulerAnglesXZY = function()
{
    // rot =  cy*cz          -sz              cz*sy
    //        sx*sy+cx*cy*sz  cx*cz          -cy*sx+cx*sy*sz
    //       -cx*sy+cy*sx*sz  cz*sx           cx*cy+sx*sy*sz

    var pitch = Athena.Math.asin(-this.m_0_1);

    if (pitch < Math.PI * 0.5)
    {
        if (pitch > -Math.PI * 0.5)
        {
            var yaw = Math.atan2(this.m_2_1, this.m_1_1);
            var roll = Math.atan2(this.m_0_2, this.m_0_0);
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
        else
        {
            // WARNING.  Not a unique solution.
            var fRmY = Math.atan2(-this.m_2_0, this.m_2_2);
            var roll = 0.0;  // any angle works
            var yaw = roll - fRmY;
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        var fRpY = Math.atan2(-this.m_2_0, this.m_2_2);
        var roll = 0.0;  // any angle works
        var yaw = fRpY - roll;
        return { pitch: pitch, yaw: yaw, roll: roll };
    }
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.toEulerAnglesYXZ = function()
{
    // rot =  cy*cz+sx*sy*sz  cz*sx*sy-cy*sz  cx*sy
    //        cx*sz           cx*cz          -sx
    //       -cz*sy+cy*sx*sz  cy*cz*sx+sy*sz  cx*cy

    var pitch = Athena.Math.asin(-this.m_1_2);

    if (pitch < Math.PI * 0.5)
    {
        if (pitch > -Math.PI * 0.5)
        {
            var yaw = Math.atan2(this.m_0_2, this.m_2_2);
            var roll = Math.atan2(this.m_1_0, this.m_1_1);
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
        else
        {
            // WARNING.  Not a unique solution.
            var fRmY = Math.atan2(-this.m_0_1, this.m_0_0);
            var roll = 0.0;  // any angle works
            var yaw = roll - fRmY;
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        var fRpY = Math.atan2(-this.m_0_1, this.m_0_0);
        var roll = 0.0;  // any angle works
        var yaw = fRpY - roll;
        return { pitch: pitch, yaw: yaw, roll: roll };
    }
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.toEulerAnglesYZX = function()
{
    // rot =  cy*cz           sx*sy-cx*cy*sz  cx*sy+cy*sx*sz
    //        sz              cx*cz          -cz*sx
    //       -cz*sy           cy*sx+cx*sy*sz  cx*cy-sx*sy*sz

    var pitch = Athena.Math.asin(this.m_1_0);

    if (pitch < Math.PI * 0.5)
    {
        if (pitch > -Math.PI * 0.5)
        {
            var yaw = Math.atan2(-this.m_2_0, this.m_0_0);
            var roll = Math.atan2(-this.m_1_2, this.m_1_1);
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
        else
        {
            // WARNING.  Not a unique solution.
            var fRmY = Math.atan2(this.m_2_1, this.m_2_2);
            var roll = 0.0;  // any angle works
            var yaw = roll - fRmY;
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        var fRpY = Math.atan2(this.m_2_1, this.m_2_2);
        var roll = 0.0;  // any angle works
        var yaw = fRpY - roll;
        return { pitch: pitch, yaw: yaw, roll: roll };
    }
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.toEulerAnglesZXY = function()
{
    // rot =  cy*cz-sx*sy*sz -cx*sz           cz*sy+cy*sx*sz
    //        cz*sx*sy+cy*sz  cx*cz          -cy*cz*sx+sy*sz
    //       -cx*sy           sx              cx*cy

    var pitch = Athena.Math.asin(this.m_2_1);

    if (pitch < Math.PI * 0.5)
    {
        if (pitch > -Math.PI * 0.5)
        {
            var yaw = Math.atan2(-this.m_0_1, this.m_1_1);
            var roll = Math.atan2(-this.m_2_0, this.m_2_2);
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
        else
        {
            // WARNING.  Not a unique solution.
            var fRmY = Math.atan2(this.m_0_2, this.m_0_0);
            var roll = 0.0;  // any angle works
            var yaw = roll - fRmY;
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        var fRpY = Math.atan2(this.m_0_2, this.m_0_0);
        var roll = 0.0;  // any angle works
        var yaw = fRpY - roll;
        return { pitch: pitch, yaw: yaw, roll: roll };
    }
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.toEulerAnglesZYX = function()
{
    // rot =  cy*cz           cz*sx*sy-cx*sz  cx*cz*sy+sx*sz
    //        cy*sz           cx*cz+sx*sy*sz -cz*sx+cx*sy*sz
    //       -sy              cy*sx           cx*cy

    var pitch = Athena.Math.asin(-this.m_2_0);

    if (pitch < Math.PI * 0.5)
    {
        if (pitch > -Math.PI * 0.5)
        {
            var yaw = Math.atan2(this.m_1_0, this.m_0_0);
            var roll = Math.atan2(this.m_2_1, this.m_2_2);
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
        else
        {
            // WARNING.  Not a unique solution.
            var fRmY = Math.atan2(-this.m_0_1, this.m_0_2);
            var roll = 0.0;  // any angle works
            var yaw = roll - fRmY;
            return { pitch: pitch, yaw: yaw, roll: roll };
        }
    }
    else
    {
        // WARNING.  Not a unique solution.
        var fRpY = Math.atan2(-this.m_0_1, this.m_0_2);
        var roll = 0.0;  // any angle works
        var yaw = fRpY - roll;
        return { pitch: pitch, yaw: yaw, roll: roll };
    }
}

//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.print = function()
{
    print('[');
    
    for (var row = 0; row < 3; ++row)
    {
        for (var col = 0; col < 3; ++col)
            print(this.get(row, col) + ' ');
        
        if (row == 2)
            print(']');
        
        print('\n');
    }
}


//-----------------------------------------------------------------------

Athena.Math.Matrix3.prototype.toString = function()
{
    var s = '[';
    
    for (var row = 0; row < 3; ++row)
    {
        for (var col = 0; col < 3; ++col)
        {
            s += this.get(row, col);
            if (s < 2)
                s += ' ';
        }
        
        if (row == 2)
            s += ']';
        else
            s += '\n';
    }

    return s;
}


/**************************************** OTHERS ***************************************/

Athena.Math.Matrix3.prototype.__classname__ = 'Athena.Math.Matrix3';

Athena.Math.Matrix3_ZERO     = new Athena.Math.Matrix3();
Athena.Math.Matrix3_IDENTITY = new Athena.Math.Matrix3(1.0, 0.0, 0.0,
                                                       0.0, 1.0, 0.0,
                                                       0.0, 0.0, 1.0);

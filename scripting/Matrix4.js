/** @file   Matrix4.js
    @author Philip Abbet
    
    Declaration of the class Athena.Math.Matrix4
    
    @note   Using a pure JavaScript class here instead of a binding over
            the C++ one results in faster code.
*/

Athena.Math.Matrix4 = function()
{
    if (arguments.length == 0)
    {
        this.m_0_0 = 0.0;
        this.m_0_1 = 0.0;  
        this.m_0_2 = 0.0;
        this.m_0_3 = 0.0;
        this.m_1_0 = 0.0;
        this.m_1_1 = 0.0;  
        this.m_1_2 = 0.0;
        this.m_1_3 = 0.0;
        this.m_2_0 = 0.0;
        this.m_2_1 = 0.0;  
        this.m_2_2 = 0.0;
        this.m_2_3 = 0.0;
        this.m_3_0 = 0.0;
        this.m_3_1 = 0.0;  
        this.m_3_2 = 0.0;
        this.m_3_3 = 0.0;
    }
    else if (arguments.length == 16)
    {
        this.m_0_0 = arguments[0];
        this.m_0_1 = arguments[1];  
        this.m_0_2 = arguments[2];
        this.m_0_3 = arguments[3];
        this.m_1_0 = arguments[4];
        this.m_1_1 = arguments[5];  
        this.m_1_2 = arguments[6];
        this.m_1_3 = arguments[7];
        this.m_2_0 = arguments[8];
        this.m_2_1 = arguments[9];  
        this.m_2_2 = arguments[10];
        this.m_2_3 = arguments[11];
        this.m_3_0 = arguments[12];
        this.m_3_1 = arguments[13];  
        this.m_3_2 = arguments[14];
        this.m_3_3 = arguments[15];
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object'))
    {
        if (arguments[0].__classname__ == 'Athena.Math.Matrix4')
        {
            this.m_0_0 = arguments[0].m_0_0;
            this.m_0_1 = arguments[0].m_0_1;  
            this.m_0_2 = arguments[0].m_0_2;
            this.m_0_3 = arguments[0].m_0_3;
            this.m_1_0 = arguments[0].m_1_0;
            this.m_1_1 = arguments[0].m_1_1;  
            this.m_1_2 = arguments[0].m_1_2;
            this.m_1_3 = arguments[0].m_1_3;
            this.m_2_0 = arguments[0].m_2_0;
            this.m_2_1 = arguments[0].m_2_1;  
            this.m_2_2 = arguments[0].m_2_2;
            this.m_2_3 = arguments[0].m_2_3;
            this.m_3_0 = arguments[0].m_3_0;
            this.m_3_1 = arguments[0].m_3_1;  
            this.m_3_2 = arguments[0].m_3_2;
            this.m_3_3 = arguments[0].m_3_3;
        }
        else if (arguments[0].__classname__ == 'Athena.Math.Matrix3')
        {
            this.m_0_0 = arguments[0].m_0_0;
            this.m_0_1 = arguments[0].m_0_1;  
            this.m_0_2 = arguments[0].m_0_2;
            this.m_0_3 = 0.0;
            this.m_1_0 = arguments[0].m_1_0;
            this.m_1_1 = arguments[0].m_1_1;  
            this.m_1_2 = arguments[0].m_1_2;
            this.m_1_3 = 0.0;
            this.m_2_0 = arguments[0].m_2_0;
            this.m_2_1 = arguments[0].m_2_1;  
            this.m_2_2 = arguments[0].m_2_2;
            this.m_2_3 = 0.0;
            this.m_3_0 = 0.0;
            this.m_3_1 = 0.0;  
            this.m_3_2 = 0.0;
            this.m_3_3 = 1.0;
        }
        else if (arguments[0].__classname__ == 'Athena.Math.Quaternion')
        {
            var m3x3 = arguments[0].toRotationMatrix();
            
            this.m_0_0 = m3x3.m_0_0;
            this.m_0_1 = m3x3.m_0_1;  
            this.m_0_2 = m3x3.m_0_2;
            this.m_0_3 = 0.0;
            this.m_1_0 = m3x3.m_1_0;
            this.m_1_1 = m3x3.m_1_1;  
            this.m_1_2 = m3x3.m_1_2;
            this.m_1_3 = 0.0;
            this.m_2_0 = m3x3.m_2_0;
            this.m_2_1 = m3x3.m_2_1;  
            this.m_2_2 = m3x3.m_2_2;
            this.m_2_3 = 0.0;
            this.m_3_0 = 0.0;
            this.m_3_1 = 0.0;  
            this.m_3_2 = 0.0;
            this.m_3_3 = 1.0;
        }
        else
        {
            throw 'Invalid parameters, valid syntaxes:\nMatrix4()\nMatrix4(<16 * numbers>)\nMatrix4(matrix3)\nMatrix4(matrix4)\nMatrix4(quaternion)';
        }
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nMatrix4()\nMatrix4(<16 * numbers>)\nMatrix4(matrix3)\nMatrix4(matrix4)\nMatrix4(quaternion)';
    }
}


/************************************ VALUE RETRIEVAL ***********************************/

Athena.Math.Matrix4.prototype.get = function(row, col)
{
    return this['m_' + row + '_' + col];
}


/*********************************** VALUE ASSIGNATION **********************************/

Athena.Math.Matrix4.prototype.set = function()
{
    if (arguments.length == 16)
    {
        this.m_0_0 = arguments[0];
        this.m_0_1 = arguments[1];  
        this.m_0_2 = arguments[2];
        this.m_0_3 = arguments[3];
        this.m_1_0 = arguments[4];
        this.m_1_1 = arguments[5];  
        this.m_1_2 = arguments[6];
        this.m_1_3 = arguments[7];
        this.m_2_0 = arguments[8];
        this.m_2_1 = arguments[9];  
        this.m_2_2 = arguments[10];
        this.m_2_3 = arguments[11];
        this.m_3_0 = arguments[12];
        this.m_3_1 = arguments[13];  
        this.m_3_2 = arguments[14];
        this.m_3_3 = arguments[15];
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object'))
    {
        if (arguments[0].__classname__ == 'Athena.Math.Matrix4')
        {
            this.m_0_0 = arguments[0].m_0_0;
            this.m_0_1 = arguments[0].m_0_1;  
            this.m_0_2 = arguments[0].m_0_2;
            this.m_0_3 = arguments[0].m_0_3;
            this.m_1_0 = arguments[0].m_1_0;
            this.m_1_1 = arguments[0].m_1_1;  
            this.m_1_2 = arguments[0].m_1_2;
            this.m_1_3 = arguments[0].m_1_3;
            this.m_2_0 = arguments[0].m_2_0;
            this.m_2_1 = arguments[0].m_2_1;  
            this.m_2_2 = arguments[0].m_2_2;
            this.m_2_3 = arguments[0].m_2_3;
            this.m_3_0 = arguments[0].m_3_0;
            this.m_3_1 = arguments[0].m_3_1;  
            this.m_3_2 = arguments[0].m_3_2;
            this.m_3_3 = arguments[0].m_3_3;
        }
        else if (arguments[0].__classname__ == 'Athena.Math.Matrix3')
        {
            this.m_0_0 = arguments[0].m_0_0;
            this.m_0_1 = arguments[0].m_0_1;  
            this.m_0_2 = arguments[0].m_0_2;
            this.m_0_3 = 0.0;
            this.m_1_0 = arguments[0].m_1_0;
            this.m_1_1 = arguments[0].m_1_1;  
            this.m_1_2 = arguments[0].m_1_2;
            this.m_1_3 = 0.0;
            this.m_2_0 = arguments[0].m_2_0;
            this.m_2_1 = arguments[0].m_2_1;  
            this.m_2_2 = arguments[0].m_2_2;
            this.m_2_3 = 0.0;
            this.m_3_0 = 0.0;
            this.m_3_1 = 0.0;  
            this.m_3_2 = 0.0;
            this.m_3_3 = 1.0;
        }
        else if (arguments[0].__classname__ == 'Athena.Math.Quaternion')
        {
            var m3x3 = arguments[0].toRotationMatrix();
            
            this.m_0_0 = m3x3.m_0_0;
            this.m_0_1 = m3x3.m_0_1;  
            this.m_0_2 = m3x3.m_0_2;
            this.m_0_3 = 0.0;
            this.m_1_0 = m3x3.m_1_0;
            this.m_1_1 = m3x3.m_1_1;  
            this.m_1_2 = m3x3.m_1_2;
            this.m_1_3 = 0.0;
            this.m_2_0 = m3x3.m_2_0;
            this.m_2_1 = m3x3.m_2_1;  
            this.m_2_2 = m3x3.m_2_2;
            this.m_2_3 = 0.0;
            this.m_3_0 = 0.0;
            this.m_3_1 = 0.0;  
            this.m_3_2 = 0.0;
            this.m_3_3 = 1.0;
        }
        else
        {
            throw 'Invalid parameters, valid syntaxes:\nset()\nset(<16 * numbers>)\nset(matrix3)\nset(matrix4)\nset(quaternion)';
        }
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nset()\nset(<16 * numbers>)\nset(matrix3)\nset(matrix4)\nset(quaternion)';
    }
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.makeTransform = function(position, scale, orientation)
{
    // Ordering:
    //    1. Scale
    //    2. Rotate
    //    3. Translate

    var rot3x3 = orientation.toRotationMatrix();

    var scale3x3 = new Athena.Math.Matrix3();
    scale3x3.m_0_0 = scale.x;
    scale3x3.m_1_1 = scale.y;
    scale3x3.m_2_2 = scale.z;

    // Set up final matrix with scale, rotation and translation
    this.set(rot3x3.mul(scale3x3));
    this.setTranslation(position);

    // No projection term
    this.m_3_0 = 0.0;
    this.m_3_1 = 0.0;
    this.m_3_2 = 0.0;
    this.m_3_3 = 1.0;
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.makeInverseTransform = function(position, scale, orientation)
{
    // Invert the parameters
    var invTranslate = position.negate();
    var invScale = new Athena.Math.Vector3(1.0 / scale.x, 1.0 / scale.y, 1.0 / scale.z);
    var invRot = orientation.inverse();

    // Because we're inverting, order is translation, rotation, scale
    // So make translation relative to scale & rotation
    invTranslate = invTranslate.mul(invScale); // scale
    invTranslate = invRot.mul(invTranslate); // rotate

    // Next, make a 3x3 rotation matrix and apply inverse scale
    var rot3x3 = invRot.toRotationMatrix();

    var scale3x3 = new Athena.Math.Matrix3();
    scale3x3.m_0_0 = invScale.x;
    scale3x3.m_1_1 = invScale.y;
    scale3x3.m_2_2 = invScale.z;

    // Set up final matrix with scale, rotation and translation
    this.set(scale3x3.mul(rot3x3));
    this.setTranslation(invTranslate);

    // No projection term
    this.m_3_0 = 0.0;
    this.m_3_1 = 0.0;
    this.m_3_2 = 0.0;
    this.m_3_3 = 1.0;
}


/********************************* ARITHMETIC OPERATIONS ********************************/

Athena.Math.Matrix4.prototype.add = function()
{
    var r = new Athena.Math.Matrix4(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if ((typeof(arguments[i]) === 'object') && (arguments[i].__classname__ == 'Athena.Math.Matrix4'))
        {
            r.m_0_0 += arguments[i].m_0_0;
            r.m_0_1 += arguments[i].m_0_1;  
            r.m_0_2 += arguments[i].m_0_2;
            r.m_0_3 += arguments[i].m_0_3;
            r.m_1_0 += arguments[i].m_1_0;
            r.m_1_1 += arguments[i].m_1_1;  
            r.m_1_2 += arguments[i].m_1_2;
            r.m_1_3 += arguments[i].m_1_3;
            r.m_2_0 += arguments[i].m_2_0;
            r.m_2_1 += arguments[i].m_2_1;  
            r.m_2_2 += arguments[i].m_2_2;
            r.m_2_3 += arguments[i].m_2_3;
            r.m_3_0 += arguments[i].m_3_0;
            r.m_3_1 += arguments[i].m_3_1;  
            r.m_3_2 += arguments[i].m_3_2;
            r.m_3_3 += arguments[i].m_3_3;
        }
    }

    return r;
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.sub = function()
{
    var r = new Athena.Math.Matrix4(this);
    
    for (var i = 0; i < arguments.length; i++)
    {
        if ((typeof(arguments[i]) === 'object') && (arguments[i].__classname__ == 'Athena.Math.Matrix4'))
        {
            r.m_0_0 -= arguments[i].m_0_0;
            r.m_0_1 -= arguments[i].m_0_1;  
            r.m_0_2 -= arguments[i].m_0_2;
            r.m_0_3 -= arguments[i].m_0_3;
            r.m_1_0 -= arguments[i].m_1_0;
            r.m_1_1 -= arguments[i].m_1_1;  
            r.m_1_2 -= arguments[i].m_1_2;
            r.m_1_3 -= arguments[i].m_1_3;
            r.m_2_0 -= arguments[i].m_2_0;
            r.m_2_1 -= arguments[i].m_2_1;  
            r.m_2_2 -= arguments[i].m_2_2;
            r.m_2_3 -= arguments[i].m_2_3;
            r.m_3_0 -= arguments[i].m_3_0;
            r.m_3_1 -= arguments[i].m_3_1;  
            r.m_3_2 -= arguments[i].m_3_2;
            r.m_3_3 -= arguments[i].m_3_3;
        }
    }

    return r;
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.mul = function()
{
    if ((arguments.length == 1) && (typeof(arguments[0]) === 'object'))
    {
        if (arguments[0].__classname__ == 'Athena.Math.Vector3')
        {
            var invW = 1.0 / (this.m_3_0 * arguments[0].x + this.m_3_1 * arguments[0].y + this.m_3_2 * arguments[0].z + this.m_3_3);

            return new Athena.Math.Vector3(
                ( this.m_0_0 * arguments[0].x + this.m_0_1 * arguments[0].y + this.m_0_2 * arguments[0].z + this.m_0_3 ) * invW,
                ( this.m_1_0 * arguments[0].x + this.m_1_1 * arguments[0].y + this.m_1_2 * arguments[0].z + this.m_1_3 ) * invW,
                ( this.m_2_0 * arguments[0].x + this.m_2_1 * arguments[0].y + this.m_2_2 * arguments[0].z + this.m_2_3 ) * invW
            );
        }
        // else if (arguments[0].__classname__ == 'Athena.Math.Vector4')
        // {
            // TODO
        // }
        // else if (arguments[0].__classname__ == 'Athena.Math.Plane')
        // {
            // TODO
        // }
    }

    var r = new Athena.Math.Matrix4(this);

    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            if (arguments[i].__classname__ == 'Athena.Math.Matrix4')
            {
                var r2 = new Athena.Math.Matrix4(r);
            
                r.m_0_0 += r2.m_0_0 * arguments[i].m_0_0 + r2.m_0_1 * arguments[i].m_1_0 + r2.m_0_2 * arguments[i].m_2_0 + r2.m_0_3 * arguments[i].m_3_0;
                r.m_0_1 += r2.m_0_0 * arguments[i].m_0_1 + r2.m_0_1 * arguments[i].m_1_1 + r2.m_0_2 * arguments[i].m_2_1 + r2.m_0_3 * arguments[i].m_3_1;  
                r.m_0_2 += r2.m_0_0 * arguments[i].m_0_2 + r2.m_0_1 * arguments[i].m_1_2 + r2.m_0_2 * arguments[i].m_2_2 + r2.m_0_3 * arguments[i].m_3_2;
                r.m_0_3 += r2.m_0_0 * arguments[i].m_0_3 + r2.m_0_1 * arguments[i].m_1_3 + r2.m_0_2 * arguments[i].m_2_3 + r2.m_0_3 * arguments[i].m_3_3;

                r.m_1_0 += r2.m_1_0 * arguments[i].m_0_0 + r2.m_1_1 * arguments[i].m_1_0 + r2.m_1_2 * arguments[i].m_2_0 + r2.m_1_3 * arguments[i].m_3_0;
                r.m_1_1 += r2.m_1_0 * arguments[i].m_0_1 + r2.m_1_1 * arguments[i].m_1_1 + r2.m_1_2 * arguments[i].m_2_1 + r2.m_1_3 * arguments[i].m_3_1;  
                r.m_1_2 += r2.m_1_0 * arguments[i].m_0_2 + r2.m_1_1 * arguments[i].m_1_2 + r2.m_1_2 * arguments[i].m_2_2 + r2.m_1_3 * arguments[i].m_3_2;
                r.m_1_3 += r2.m_1_0 * arguments[i].m_0_3 + r2.m_1_1 * arguments[i].m_1_3 + r2.m_1_2 * arguments[i].m_2_3 + r2.m_1_3 * arguments[i].m_3_3;

                r.m_2_0 += r2.m_2_0 * arguments[i].m_0_0 + r2.m_2_1 * arguments[i].m_1_0 + r2.m_2_2 * arguments[i].m_2_0 + r2.m_2_3 * arguments[i].m_3_0;
                r.m_2_1 += r2.m_2_0 * arguments[i].m_0_1 + r2.m_2_1 * arguments[i].m_1_1 + r2.m_2_2 * arguments[i].m_2_1 + r2.m_2_3 * arguments[i].m_3_1;  
                r.m_2_2 += r2.m_2_0 * arguments[i].m_0_2 + r2.m_2_1 * arguments[i].m_1_2 + r2.m_2_2 * arguments[i].m_2_2 + r2.m_2_3 * arguments[i].m_3_2;
                r.m_2_3 += r2.m_2_0 * arguments[i].m_0_3 + r2.m_2_1 * arguments[i].m_1_3 + r2.m_2_2 * arguments[i].m_2_3 + r2.m_2_3 * arguments[i].m_3_3;

                r.m_3_0 += r2.m_3_0 * arguments[i].m_0_0 + r2.m_3_1 * arguments[i].m_1_0 + r2.m_3_2 * arguments[i].m_2_0 + r2.m_3_3 * arguments[i].m_3_0;
                r.m_3_1 += r2.m_3_0 * arguments[i].m_0_1 + r2.m_3_1 * arguments[i].m_1_1 + r2.m_3_2 * arguments[i].m_2_1 + r2.m_3_3 * arguments[i].m_3_1;  
                r.m_3_2 += r2.m_3_0 * arguments[i].m_0_2 + r2.m_3_1 * arguments[i].m_1_2 + r2.m_3_2 * arguments[i].m_2_2 + r2.m_3_3 * arguments[i].m_3_2;
                r.m_3_3 += r2.m_3_0 * arguments[i].m_0_3 + r2.m_3_1 * arguments[i].m_1_3 + r2.m_3_2 * arguments[i].m_2_3 + r2.m_3_3 * arguments[i].m_3_3;
            }
            else
            {
                throw 'Invalid parameters, valid syntaxes:\nmul(matrix4 | scalar, matrix4 | scalar, ...)\nmul(vector3)\nmul(vector4)\nmul(plane)';
            }
        }
        else
        {
            r.m_0_0 *= arguments[i];
            r.m_0_1 *= arguments[i];  
            r.m_0_2 *= arguments[i];
            r.m_0_3 *= arguments[i];
            r.m_1_0 *= arguments[i];
            r.m_1_1 *= arguments[i];  
            r.m_1_2 *= arguments[i];
            r.m_1_3 *= arguments[i];
            r.m_2_0 *= arguments[i];
            r.m_2_1 *= arguments[i];  
            r.m_2_2 *= arguments[i];
            r.m_2_3 *= arguments[i];
            r.m_3_0 *= arguments[i];
            r.m_3_1 *= arguments[i];  
            r.m_3_2 *= arguments[i];
            r.m_3_3 *= arguments[i];
        }
    }

    return r;
}


/********************************* COMPARISON OPERATIONS ********************************/

Athena.Math.Matrix4.prototype.equals = function(matrix)
{
    return (this.m_0_0 == matrix.m_0_0) && (this.m_0_1 == matrix.m_0_1) && (this.m_0_2 == matrix.m_0_2) && (this.m_0_3 == matrix.m_0_3) &&
           (this.m_1_0 == matrix.m_1_0) && (this.m_1_1 == matrix.m_1_1) && (this.m_1_2 == matrix.m_1_2) && (this.m_1_3 == matrix.m_1_3) &&
           (this.m_2_0 == matrix.m_2_0) && (this.m_2_1 == matrix.m_2_1) && (this.m_2_2 == matrix.m_2_2) && (this.m_2_3 == matrix.m_2_3) &&
           (this.m_3_0 == matrix.m_3_0) && (this.m_3_1 == matrix.m_3_1) && (this.m_3_2 == matrix.m_3_2) && (this.m_3_3 == matrix.m_3_3);
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.notEquals = function(matrix)
{
    return (this.m_0_0 != matrix.m_0_0) || (this.m_0_1 != matrix.m_0_1) || (this.m_0_2 != matrix.m_0_2) || (this.m_0_3 != matrix.m_0_3) ||
           (this.m_1_0 != matrix.m_1_0) || (this.m_1_1 != matrix.m_1_1) || (this.m_1_2 != matrix.m_1_2) || (this.m_1_3 != matrix.m_1_3) ||
           (this.m_2_0 != matrix.m_2_0) || (this.m_2_1 != matrix.m_2_1) || (this.m_2_2 != matrix.m_2_2) || (this.m_2_3 != matrix.m_2_3) ||
           (this.m_3_0 != matrix.m_3_0) || (this.m_3_1 != matrix.m_3_1) || (this.m_3_2 != matrix.m_3_2) || (this.m_3_3 != matrix.m_3_3);
}


/**************************************** METHODS ***************************************/

Athena.Math.Matrix4.prototype.transpose = function()
{
    return new Athena.Math.Matrix4(
        this.m_0_0, this.m_1_0, this.m_2_0, this.m_3_0,
        this.m_0_1, this.m_1_1, this.m_2_1, this.m_3_1,
        this.m_0_2, this.m_1_2, this.m_2_2, this.m_3_2,
        this.m_0_3, this.m_1_3, this.m_2_3, this.m_3_3
    );
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.extract3x3Matrix = function()
{
    return new Athena.Math.Matrix3(
        this.m_0_0, this.m_0_1, this.m_0_2,
        this.m_1_0, this.m_1_1, this.m_1_2,
        this.m_2_0, this.m_2_1, this.m_2_2
    );
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.extractQuaternion = function()
{
    var m = this.extract3x3Matrix();
    return new Athena.Math.Quaternion(m);
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.hasScale = function()
{
    var t = this.m_0_0 * this.m_0_0 + this.m_1_0 * this.m_1_0 + this.m_2_0 * this.m_2_0;
    if (!Athena.Math.equals(t, 1.0, 1e-4))
        return true;

    var t = this.m_0_1 * this.m_0_1 + this.m_1_1 * this.m_1_1 + this.m_2_1 * this.m_2_1;
    if (!Athena.Math.equals(t, 1.0, 1e-4))
        return true;

    var t = this.m_0_2 * this.m_0_2 + this.m_1_2 * this.m_1_2 + this.m_2_2 * this.m_2_2;
    if (!Athena.Math.equals(t, 1.0, 1e-4))
        return true;

    return false;
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.hasNegativeScale = function()
{
    return (this.determinant() < 0);
}

//-----------------------------------------------------------------------

// Helper internal function
Athena.Math.Matrix4.prototype._MINOR = function(r0, r1, r2, c0, c1, c2)
{
    return this['m_' + r0 + '_' + c0] * (this['m_' + r1 + '_' + c1] * this['m_' + r2 + '_' + c2] - this['m_' + r2 + '_' + c1] * this['m_' + r1 + '_' + c2]) -
           this['m_' + r0 + '_' + c1] * (this['m_' + r1 + '_' + c0] * this['m_' + r2 + '_' + c2] - this['m_' + r2 + '_' + c0] * this['m_' + r1 + '_' + c2]) +
           this['m_' + r0 + '_' + c2] * (this['m_' + r1 + '_' + c0] * this['m_' + r2 + '_' + c1] - this['m_' + r2 + '_' + c0] * this['m_' + r1 + '_' + c1]);
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.adjoint = function()
{
    return new Athena.Math.Matrix4(
         this._MINOR(1, 2, 3, 1, 2, 3),
        -this._MINOR(0, 2, 3, 1, 2, 3),
         this._MINOR(0, 1, 3, 1, 2, 3),
        -this._MINOR(0, 1, 2, 1, 2, 3),

        -this._MINOR(1, 2, 3, 0, 2, 3),
         this._MINOR(0, 2, 3, 0, 2, 3),
        -this._MINOR(0, 1, 3, 0, 2, 3),
         this._MINOR(0, 1, 2, 0, 2, 3),

         this._MINOR(1, 2, 3, 0, 1, 3),
        -this._MINOR(0, 2, 3, 0, 1, 3),
         this._MINOR(0, 1, 3, 0, 1, 3),
        -this._MINOR(0, 1, 2, 0, 1, 3),

        -this._MINOR(1, 2, 3, 0, 1, 2),
         this._MINOR(0, 2, 3, 0, 1, 2),
        -this._MINOR(0, 1, 3, 0, 1, 2),
         this._MINOR(0, 1, 2, 0, 1, 2)
    );
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.determinant = function()
{
    return this.m_0_0 * this._MINOR(1, 2, 3, 1, 2, 3) -
           this.m_0_1 * this._MINOR(1, 2, 3, 0, 2, 3) +
           this.m_0_2 * this._MINOR(1, 2, 3, 0, 1, 3) -
           this.m_0_3 * this._MINOR(1, 2, 3, 0, 1, 2);
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.inverse = function()
{
    var m00 = this.m_0_0;
    var m01 = this.m_0_1
    var m02 = this.m_0_2;
    var m03 = this.m_0_3;
    var m10 = this.m_1_0;
    var m11 = this.m_1_1;
    var m12 = this.m_1_2;
    var m13 = this.m_1_3;
    var m20 = this.m_2_0;
    var m21 = this.m_2_1;
    var m22 = this.m_2_2;
    var m23 = this.m_2_3;
    var m30 = this.m_3_0;
    var m31 = this.m_3_1;
    var m32 = this.m_3_2;
    var m33 = this.m_3_3;

    var v0 = m20 * m31 - m21 * m30;
    var v1 = m20 * m32 - m22 * m30;
    var v2 = m20 * m33 - m23 * m30;
    var v3 = m21 * m32 - m22 * m31;
    var v4 = m21 * m33 - m23 * m31;
    var v5 = m22 * m33 - m23 * m32;

    var t00 = + (v5 * m11 - v4 * m12 + v3 * m13);
    var t10 = - (v5 * m10 - v2 * m12 + v1 * m13);
    var t20 = + (v4 * m10 - v2 * m11 + v0 * m13);
    var t30 = - (v3 * m10 - v1 * m11 + v0 * m12);

    var invDet = 1.0 / (t00 * m00 + t10 * m01 + t20 * m02 + t30 * m03);

    var d00 = t00 * invDet;
    var d10 = t10 * invDet;
    var d20 = t20 * invDet;
    var d30 = t30 * invDet;

    var d01 = - (v5 * m01 - v4 * m02 + v3 * m03) * invDet;
    var d11 = + (v5 * m00 - v2 * m02 + v1 * m03) * invDet;
    var d21 = - (v4 * m00 - v2 * m01 + v0 * m03) * invDet;
    var d31 = + (v3 * m00 - v1 * m01 + v0 * m02) * invDet;

    v0 = m10 * m31 - m11 * m30;
    v1 = m10 * m32 - m12 * m30;
    v2 = m10 * m33 - m13 * m30;
    v3 = m11 * m32 - m12 * m31;
    v4 = m11 * m33 - m13 * m31;
    v5 = m12 * m33 - m13 * m32;

    var d02 = + (v5 * m01 - v4 * m02 + v3 * m03) * invDet;
    var d12 = - (v5 * m00 - v2 * m02 + v1 * m03) * invDet;
    var d22 = + (v4 * m00 - v2 * m01 + v0 * m03) * invDet;
    var d32 = - (v3 * m00 - v1 * m01 + v0 * m02) * invDet;

    v0 = m21 * m10 - m20 * m11;
    v1 = m22 * m10 - m20 * m12;
    v2 = m23 * m10 - m20 * m13;
    v3 = m22 * m11 - m21 * m12;
    v4 = m23 * m11 - m21 * m13;
    v5 = m23 * m12 - m22 * m13;

    var d03 = - (v5 * m01 - v4 * m02 + v3 * m03) * invDet;
    var d13 = + (v5 * m00 - v2 * m02 + v1 * m03) * invDet;
    var d23 = - (v4 * m00 - v2 * m01 + v0 * m03) * invDet;
    var d33 = + (v3 * m00 - v1 * m01 + v0 * m02) * invDet;

    return new Athena.Math.Matrix4(d00, d01, d02, d03,
                                   d10, d11, d12, d13,
                                   d20, d21, d22, d23,
                                   d30, d31, d32, d33);
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.print = function()
{
    print('[');
    
    for (var row = 0; row < 4; ++row)
    {
        for (var col = 0; col < 4; ++col)
            print(this.get(row, col) + ' ');
        
        if (row == 3)
            print(']');
        
        print('\n');
    }
}


/****************************** TRANSLATION TRANSFORMATION *****************************/

Athena.Math.Matrix4.prototype.setTranslation = function()
{
    if (arguments.length == 3)
    {
        this.m_0_3 = arguments[0];
        this.m_1_3 = arguments[1];
        this.m_2_3 = arguments[2];
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') &&
             (arguments[0].__classname__ == 'Athena.Math.Vector3'))
    {
        this.m_0_3 = arguments[0].x;
        this.m_1_3 = arguments[0].y;
        this.m_2_3 = arguments[0].z;
    }
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.translation = function()
{
    return new Athena.Math.Vector3(this.m_0_3, this.m_1_3, this.m_2_3);
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.makeTranslation = function()
{
    if (arguments.length == 3)
    {
        this.m_0_0 = 1.0; this.m_0_1 = 0.0; this.m_0_2 = 0.0; this.m_0_3 = arguments[0];
        this.m_1_0 = 0.0; this.m_1_1 = 1.0; this.m_1_2 = 0.0; this.m_1_3 = arguments[1];
        this.m_2_0 = 0.0; this.m_2_1 = 0.0; this.m_2_2 = 1.0; this.m_2_3 = arguments[2];
        this.m_3_0 = 0.0; this.m_3_1 = 0.0; this.m_3_2 = 0.0; this.m_3_3 = 1.0;
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') &&
             (arguments[0].__classname__ == 'Athena.Math.Vector3'))
    {
        this.m_0_0 = 1.0; this.m_0_1 = 0.0; this.m_0_2 = 0.0; this.m_0_3 = arguments[0].x;
        this.m_1_0 = 0.0; this.m_1_1 = 1.0; this.m_1_2 = 0.0; this.m_1_3 = arguments[0].y;
        this.m_2_0 = 0.0; this.m_2_1 = 0.0; this.m_2_2 = 1.0; this.m_2_3 = arguments[0].z;
        this.m_3_0 = 0.0; this.m_3_1 = 0.0; this.m_3_2 = 0.0; this.m_3_3 = 1.0;
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nmakeTranslation(x, y, z)\nmakeTranslation(vector3)';
    }
}


/********************************* SCALE TRANSFORMATION ********************************/

Athena.Math.Matrix4.prototype.setScale = function()
{
    if (arguments.length == 3)
    {
        this.m_0_0 = arguments[0];
        this.m_1_1 = arguments[1];
        this.m_2_2 = arguments[2];
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') &&
             (arguments[0].__classname__ == 'Athena.Math.Vector3'))
    {
        this.m_0_0 = arguments[0].x;
        this.m_1_1 = arguments[0].y;
        this.m_2_2 = arguments[0].z;
    }
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.scale = function()
{
    return new Athena.Math.Vector3(this.m_0_0, this.m_1_1, this.m_2_2);
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.makeScale = function()
{
    if (arguments.length == 3)
    {
        this.m_0_0 = arguments[0]; this.m_0_1 = 0.0;          this.m_0_2 = 0.0;          this.m_0_3 = 0.0;
        this.m_1_0 = 0.0;          this.m_1_1 = arguments[1]; this.m_1_2 = 0.0;          this.m_1_3 = 0.0;
        this.m_2_0 = 0.0;          this.m_2_1 = 0.0;          this.m_2_2 = arguments[2]; this.m_2_3 = 0.0;
        this.m_3_0 = 0.0;          this.m_3_1 = 0.0;          this.m_3_2 = 0.0;          this.m_3_3 = 1.0;
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') &&
             (arguments[0].__classname__ == 'Athena.Math.Vector3'))
    {
        this.m_0_0 = arguments[0].x; this.m_0_1 = 0.0;            this.m_0_2 = 0.0;            this.m_0_3 = 0.0;
        this.m_1_0 = 0.0;            this.m_1_1 = arguments[0].y; this.m_1_2 = 0.0;            this.m_1_3 = 0.0;
        this.m_2_0 = 0.0;            this.m_2_1 = 0.0;            this.m_2_2 = arguments[0].z; this.m_2_3 = 0.0;
        this.m_3_0 = 0.0;            this.m_3_1 = 0.0;            this.m_3_2 = 0.0;            this.m_3_3 = 1.0;
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nmakeScale(x, y, z)\nmakeScale(vector3)';
    }
}


/********************************* AFFINE TRANSFORMATION ********************************/

Athena.Math.Matrix4.prototype.isAffine = function()
{
    return (this.m_3_0 == 0.0) && (this.m_3_1 == 0.0) && (this.m_3_2 == 0.0) && (this.m_3_3 == 1.0);
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.inverseAffine = function()
{
    if (!this.isAffine())
        throw "The matrix isn't affine";

    var m10 = this.m_1_0;
    var m11 = this.m_1_1;
    var m12 = this.m_1_2;
    var m20 = this.m_2_0;
    var m21 = this.m_2_1;
    var m22 = this.m_2_2;

    var t00 = m22 * m11 - m21 * m12;
    var t10 = m20 * m12 - m22 * m10;
    var t20 = m21 * m10 - m20 * m11;

    var m00 = this.m_0_0;
    var m01 = this.m_0_1;
    var m02 = this.m_0_2;

    var invDet = 1.0 / (m00 * t00 + m01 * t10 + m02 * t20);

    t00 *= invDet; t10 *= invDet; t20 *= invDet;

    m00 *= invDet; m01 *= invDet; m02 *= invDet;

    var r00 = t00;
    var r01 = m02 * m21 - m01 * m22;
    var r02 = m01 * m12 - m02 * m11;

    var r10 = t10;
    var r11 = m00 * m22 - m02 * m20;
    var r12 = m02 * m10 - m00 * m12;

    var r20 = t20;
    var r21 = m01 * m20 - m00 * m21;
    var r22 = m00 * m11 - m01 * m10;

    var m03 = this.m_0_3;
    var m13 = this.m_1_3;
    var m23 = this.m_2_3;

    var r03 = - (r00 * m03 + r01 * m13 + r02 * m23);
    var r13 = - (r10 * m03 + r11 * m13 + r12 * m23);
    var r23 = - (r20 * m03 + r21 * m13 + r22 * m23);

    return new Athena.Math.Matrix4(r00, r01, r02, r03,
                                   r10, r11, r12, r13,
                                   r20, r21, r22, r23,
                                   0,   0,   0,   1);
}

//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.concatenateAffine = function(matrix)
{
    if (!this.isAffine() || !matrix.isAffine())
        throw "The matrix isn't affine";

    return new Athena.Math.Matrix4(
        this.m_0_0 * matrix.m_0_0 + this.m_0_1 * matrix.m_1_0 + this.m_0_2 * matrix.m_2_0,
        this.m_0_0 * matrix.m_0_1 + this.m_0_1 * matrix.m_1_1 + this.m_0_2 * matrix.m_2_1,
        this.m_0_0 * matrix.m_0_2 + this.m_0_1 * matrix.m_1_2 + this.m_0_2 * matrix.m_2_2,
        this.m_0_0 * matrix.m_0_3 + this.m_0_1 * matrix.m_1_3 + this.m_0_2 * matrix.m_2_3 + this.m_0_3,

        this.m_1_0 * matrix.m_0_0 + this.m_1_1 * matrix.m_1_0 + this.m_1_2 * matrix.m_2_0,
        this.m_1_0 * matrix.m_0_1 + this.m_1_1 * matrix.m_1_1 + this.m_1_2 * matrix.m_2_1,
        this.m_1_0 * matrix.m_0_2 + this.m_1_1 * matrix.m_1_2 + this.m_1_2 * matrix.m_2_2,
        this.m_1_0 * matrix.m_0_3 + this.m_1_1 * matrix.m_1_3 + this.m_1_2 * matrix.m_2_3 + this.m_1_3,

        this.m_2_0 * matrix.m_0_0 + this.m_2_1 * matrix.m_1_0 + this.m_2_2 * matrix.m_2_0,
        this.m_2_0 * matrix.m_0_1 + this.m_2_1 * matrix.m_1_1 + this.m_2_2 * matrix.m_2_1,
        this.m_2_0 * matrix.m_0_2 + this.m_2_1 * matrix.m_1_2 + this.m_2_2 * matrix.m_2_2,
        this.m_2_0 * matrix.m_0_3 + this.m_2_1 * matrix.m_1_3 + this.m_2_2 * matrix.m_2_3 + this.m_2_3,

        0.0, 0.0, 0.0, 1.0
    );
}


//-----------------------------------------------------------------------

Athena.Math.Matrix4.prototype.transformAffine = function(vector)
{
    if (vector.__classname__ == 'Athena.Math.Vector3')
    {
        return new Athena.Math.Vector3(
            this.m_0_0 * arguments[0].x + this.m_0_1 * arguments[0].y + this.m_0_2 * arguments[0].z + this.m_0_3,
            this.m_1_0 * arguments[0].x + this.m_1_1 * arguments[0].y + this.m_1_2 * arguments[0].z + this.m_1_3,
            this.m_2_0 * arguments[0].x + this.m_2_1 * arguments[0].y + this.m_2_2 * arguments[0].z + this.m_2_3
        );
    }
    // else if (vector.__classname__ == 'Athena.Math.Vector4')
    // {
        // TODO
    // }
    else
    {
        throw 'Invalid parameter, valid syntaxes:\ntransformAffine(vector3)\ntransformAffine(vector4)';
    }
}


/**************************************** OTHERS ***************************************/

Athena.Math.Matrix4.prototype.__classname__ = 'Athena.Math.Matrix4';

Athena.Math.Matrix4_ZERO     = new Athena.Math.Matrix4();
Athena.Math.Matrix4_IDENTITY = new Athena.Math.Matrix4(1.0, 0.0, 0.0, 0.0,
                                                       0.0, 1.0, 0.0, 0.0,
                                                       0.0, 0.0, 1.0, 0.0,
                                                       0.0, 0.0, 0.0, 1.0);

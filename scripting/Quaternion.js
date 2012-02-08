/** @file   Quaternion.js
    @author Philip Abbet

    Declaration of the class Athena.Math.Quaternion

    @note   Using a pure JavaScript class here instead of a binding over
            the C++ one results in faster code.
*/

Athena.Math.Quaternion = function()
{
    if (arguments.length == 0)
    {
        this.w = 1.0;
        this.x = 0.0;
        this.y = 0.0;
        this.z = 0.0;
    }
    else if (arguments.length == 4)
    {
        this.w = arguments[0];
        this.x = arguments[1];
        this.y = arguments[2];
        this.z = arguments[3];
    }
    else if (arguments.length == 2)
    {
        var halfAngle = 0.5 * arguments[0];
        var sin = Math.sin(halfAngle);
        this.w = Math.cos(halfAngle);
        this.x = sin * arguments[1].x;
        this.y = sin * arguments[1].y;
        this.z = sin * arguments[1].z;
    }
    else if (arguments.length == 3)
    {
        var m = new Athena.Math.Matrix3(arguments[0].x, arguments[1].y, arguments[2].z,
                                        arguments[0].x, arguments[1].y, arguments[2].z,
                                        arguments[0].x, arguments[1].y, arguments[2].z);
        this.set(m);
    }
    else if (arguments.length == 1)
    {
        if (arguments[0].__classname__ == 'Athena.Math.Quaternion')
        {
            this.w = arguments[0].w;
            this.x = arguments[0].x;
            this.y = arguments[0].y;
            this.z = arguments[0].z;
        }
        else if (arguments[0].__classname__ == 'Athena.Math.Matrix3')
        {
            var fTrace = arguments[0].m_0_0 + arguments[0].m_1_1 + arguments[0].m_2_2;

            if (fTrace > 0.0)
            {
                // |w| > 1/2, may as well choose w > 1/2
                var fRoot = Math.sqrt(fTrace + 1.0);  // 2w
                this.w = 0.5 * fRoot;
                fRoot = 0.5 / fRoot;  // 1/(4w)
                this.x = (arguments[0].m_2_1 - arguments[0].m_1_2) * fRoot;
                this.y = (arguments[0].m_0_2 - arguments[0].m_2_0) * fRoot;
                this.z = (arguments[0].m_1_0 - arguments[0].m_0_1) * fRoot;
            }
            else
            {
                // |w| <= 1/2
                var s_iNext = [ 1, 2, 0 ];
                var i = 0;
                if ( arguments[0].m_1_1 > arguments[0].m_0_0 )
                    i = 1;
                if ( arguments[0].m_2_2 > arguments[0]['m_' + i + '_' + i] )
                    i = 2;
                var j = s_iNext[i];
                var k = s_iNext[j];

                var fRoot = Math.sqrt(arguments[0]['m_' + i + '_' + i] - arguments[0]['m_' + j + '_' + j] - arguments[0]['m_' + k + '_' + k] + 1.0);
                var apkQuat_i = 0.5 * fRoot;
                fRoot = 0.5 / fRoot;
                this.w = (arguments[0]['m_' + k + '_' + j] - arguments[0]['m_' + j + '_' + k]) * fRoot;
                var apkQuat_j = (arguments[0]['m_' + j + '_' + i] + arguments[0]['m_' + i + '_' + j]) * fRoot;
                var apkQuat_k = (arguments[0]['m_' + k + '_' + i] + arguments[0]['m_' + i + '_' + k]) * fRoot;

                if (i == 0)
                {
                    this.x = apkQuat_i;
                    this.y = apkQuat_j;
                    this.z = apkQuat_k;
                }
                else if (i == 1)
                {
                    this.x = apkQuat_k;
                    this.y = apkQuat_i;
                    this.z = apkQuat_j;
                }
                else
                {
                    this.x = apkQuat_j;
                    this.y = apkQuat_k;
                    this.z = apkQuat_i;
                }
            }
        }
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nQuaternion()\nQuaternion(w, x, y, z)\nQuaternion(angle, axis)\nQuaternion(xaxis, yaxis, zaxis)\nQuaternion(matrix3)';
    }
}


/*********************************** VALUE ASSIGNATION **********************************/

Athena.Math.Quaternion.prototype.set = function()
{
    if (arguments.length == 4)
    {
        this.w = arguments[0];
        this.x = arguments[1];
        this.y = arguments[2];
        this.z = arguments[3];
    }
    else if (arguments.length == 2)
    {
        var halfAngle = 0.5 * arguments[0];
        var sin = Math.sin(halfAngle);
        this.w = Math.cos(halfAngle);
        this.x = sin * arguments[1].x;
        this.y = sin * arguments[1].y;
        this.z = sin * arguments[1].z;
    }
    else if (arguments.length == 3)
    {
        var m = new Athena.Math.Matrix3(arguments[0].x, arguments[1].y, arguments[2].z,
                                        arguments[0].x, arguments[1].y, arguments[2].z,
                                        arguments[0].x, arguments[1].y, arguments[2].z);
        this.set(m);
    }
    else if ((arguments.length == 1) && (typeof(arguments[0]) === 'object'))
    {
        if (arguments[0].__classname__ == 'Athena.Math.Quaternion')
        {
            this.w = arguments[0].w;
            this.x = arguments[0].x;
            this.y = arguments[0].y;
            this.z = arguments[0].z;
        }
        else if (arguments[0].__classname__ == 'Athena.Math.Matrix3')
        {
            var fTrace = arguments[0].m_0_0 + arguments[0].m_1_1 + arguments[0].m_2_2;

            if (fTrace > 0.0)
            {
                // |w| > 1/2, may as well choose w > 1/2
                var fRoot = Math.sqrt(fTrace + 1.0);  // 2w
                this.w = 0.5 * fRoot;
                fRoot = 0.5 / fRoot;  // 1/(4w)
                this.x = (arguments[0].m_2_1 - arguments[0].m_1_2) * fRoot;
                this.y = (arguments[0].m_0_2 - arguments[0].m_2_0) * fRoot;
                this.z = (arguments[0].m_1_0 - arguments[0].m_0_1) * fRoot;
            }
            else
            {
                // |w| <= 1/2
                var s_iNext = [ 1, 2, 0 ];
                var i = 0;
                if ( arguments[0].m_1_1 > arguments[0].m_0_0 )
                    i = 1;
                if ( arguments[0].m_2_2 > arguments[0]['m_' + i + '_' + i] )
                    i = 2;
                var j = s_iNext[i];
                var k = s_iNext[j];

                var fRoot = Math.sqrt(arguments[0]['m_' + i + '_' + i] - arguments[0]['m_' + j + '_' + j] - arguments[0]['m_' + k + '_' + k] + 1.0);
                var apkQuat_i = 0.5 * fRoot;
                fRoot = 0.5 / fRoot;
                this.w = (arguments[0]['m_' + k + '_' + j] - arguments[0]['m_' + j + '_' + k]) * fRoot;
                var apkQuat_j = (arguments[0]['m_' + j + '_' + i] + arguments[0]['m_' + i + '_' + j]) * fRoot;
                var apkQuat_k = (arguments[0]['m_' + k + '_' + i] + arguments[0]['m_' + i + '_' + k]) * fRoot;

                if (i == 0)
                {
                    this.x = apkQuat_i;
                    this.y = apkQuat_j;
                    this.z = apkQuat_k;
                }
                else if (i == 1)
                {
                    this.x = apkQuat_k;
                    this.y = apkQuat_i;
                    this.z = apkQuat_j;
                }
                else
                {
                    this.x = apkQuat_j;
                    this.y = apkQuat_k;
                    this.z = apkQuat_i;
                }
            }
        }
    }
    else
    {
        throw 'Invalid parameters, valid syntaxes:\nset(w, x, y, z)\nset(angle, axis)\nset(xaxis, yaxis, zaxis)\nset(matrix)';
    }
}


/**************************************** METHODS ***************************************/

Athena.Math.Quaternion.prototype.toRotationMatrix = function()
{
    var fTx  = 2.0 * this.x;
    var fTy  = 2.0 * this.y;
    var fTz  = 2.0 * this.z;
    var fTwx = fTx * this.w;
    var fTwy = fTy * this.w;
    var fTwz = fTz * this.w;
    var fTxx = fTx * this.x;
    var fTxy = fTy * this.x;
    var fTxz = fTz * this.x;
    var fTyy = fTy * this.y;
    var fTyz = fTz * this.y;
    var fTzz = fTz * this.z;

    return new Athena.Math.Matrix3(1.0 - (fTyy + fTzz), fTxy - fTwz, fTxz + fTwy,
                                   fTxy + fTwz, 1.0 - (fTxx + fTzz), fTyz - fTwx,
                                   fTxz - fTwy, fTyz + fTwx, 1.0 - (fTxx + fTyy));
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.toAngleAxis = function()
{
    var fSqrLength = this.x * this.x + this.y * this.y + this.z * this.z;
    if ( fSqrLength > 0.0 )
    {
        var angle = 2.0 * Athena.Math.acos(this.w);
        var fInvLength = 1.0 / Math.sqrt(fSqrLength);

        var axis = new Athena.Math.Vector3(this.x * fInvLength,
                                           this.y * fInvLength,
                                           this.z * fInvLength);

        return { angle: angle, axis: axis };
    }
    else
    {
        // angle is 0 (mod 2*pi), so any axis will do
        return { angle: 0.0, axis: new Athena.Math.Vector3(1.0, 0.0, 0.0) };
    }
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.toAxes = function()
{
    var m = this.toRotationMatrix();

    return { xaxis: new Athena.Math.Vector3(m.m_0_0, m.m_1_0, m.m_2_0),
             yaxis: new Athena.Math.Vector3(m.m_0_1, m.m_1_1, m.m_2_1),
             zaxis: new Athena.Math.Vector3(m.m_0_2, m.m_1_2, m.m_2_2) };
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.xAxis = function()
{
    var fTy  = 2.0 * this.y;
    var fTz  = 2.0 * this.z;
    var fTwy = fTy * this.w;
    var fTwz = fTz * this.w;
    var fTxy = fTy * this.x;
    var fTxz = fTz * this.x;
    var fTyy = fTy * this.y;
    var fTzz = fTz * this.z;

    return new Athena.Math.Vector3(1.0 - (fTyy + fTzz), fTxy + fTwz, fTxz - fTwy);
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.yAxis = function()
{
    var fTx  = 2.0 * this.x;
    var fTy  = 2.0 * this.y;
    var fTz  = 2.0 * this.z;
    var fTwx = fTx * this.w;
    var fTwz = fTz * this.w;
    var fTxx = fTx * this.x;
    var fTxy = fTy * this.x;
    var fTyz = fTz * this.y;
    var fTzz = fTz * this.z;

    return new Athena.Math.Vector3(fTxy - fTwz, 1.0 - (fTxx + fTzz), fTyz + fTwx);
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.zAxis = function()
{
    var fTx  = 2.0 * this.x;
    var fTy  = 2.0 * this.y;
    var fTz  = 2.0 * this.z;
    var fTwx = fTx * this.w;
    var fTwy = fTy * this.w;
    var fTxx = fTx * this.x;
    var fTxz = fTz * this.x;
    var fTyy = fTy * this.y;
    var fTyz = fTz * this.y;

    return new Athena.Math.Vector3(fTxz + fTwy, fTyz - fTwx, 1.0 - (fTxx + fTyy));
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.dot = function(quaternion)
{
    return this.w * quaternion.w + this.x * quaternion.x + this.y * quaternion.y + this.z * quaternion.z;
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.norm = function()
{
    return Math.sqrt(this.w * this.w + this.x * this.x + this.y * this.y + this.z * this.z);
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.squaredNorm = function()
{
    return this.w * this.w + this.x * this.x + this.y * this.y + this.z * this.z;
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.normalise = function()
{
    var length = this.norm();

    if (length > 1e-08)
    {
        var inverse = 1.0 / length;
        this.w *= inverse;
        this.x *= inverse;
        this.y *= inverse;
        this.z *= inverse;
    }

    return length;
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.inverse = function()
{
    var squared_length = this.squaredNorm();

    if (length > 1e-08)
    {
        var inverse = 1.0 / squared_length;
        return new Athena.Math.Quaternion(this.w * inverse, -this.x * inverse,
                                          -this.y * inverse, -this.z * inverse);
    }

    return Athena.Math.Quaternion_ZERO;
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.rotationTo = function(quaternion)
{
    return quaternion.mul(this.inverse());
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.rotationFrom = function(quaternion)
{
    return this.mul(quaternion.inverse());
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.isNaN = function()
{
    return isNaN(this.x) || isNaN(this.y) || isNaN(this.z) || isNaN(this.w);
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.toString = function()
{
    return '[' + this.w + ', ' + this.x + ', ' + this.y + ', ' + this.z + ']';
}


/********************************* ARITHMETIC OPERATIONS ********************************/

Athena.Math.Quaternion.prototype.add = function()
{
    var q = new Athena.Math.Quaternion(this);

    for (var i = 0; i < arguments.length; i++)
    {
        if ((typeof(arguments[i]) === 'object') && (arguments[i].__classname__ == 'Athena.Math.Quaternion'))
        {
            q.w += arguments[i].w;
            q.x += arguments[i].x;
            q.y += arguments[i].y;
            q.z += arguments[i].z;
        }
    }

    return q;
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.sub = function()
{
    var q = new Athena.Math.Quaternion(this);

    for (var i = 0; i < arguments.length; i++)
    {
        if ((typeof(arguments[i]) === 'object') && (arguments[i].__classname__ == 'Athena.Math.Quaternion'))
        {
            q.w -= arguments[i].w;
            q.x -= arguments[i].x;
            q.y -= arguments[i].y;
            q.z -= arguments[i].z;
        }
    }

    return q;
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.mul = function()
{
    if ((arguments.length == 1) && (typeof(arguments[0]) === 'object') && (arguments[0].__classname__ == 'Athena.Math.Vector3'))
    {
        var qvec = new Athena.Math.Vector3(this.x, this.y, this.z);
        var uv = qvec.cross(arguments[0]);
        var uuv = qvec.cross(uv);

        uv = uv.mul(2.0 * this.w);
        uuv = uuv.mul(2.0);

        return arguments[0].add(uv, uuv);
    }

    var q = new Athena.Math.Quaternion(this);

    for (var i = 0; i < arguments.length; i++)
    {
        if (typeof(arguments[i]) === 'object')
        {
            if (arguments[i].__classname__ == 'Athena.Math.Quaternion')
            {
                q = new Athena.Math.Quaternion(
                    q.w * arguments[i].w - q.x * arguments[i].x - q.y * arguments[i].y - q.z * arguments[i].z,
                    q.w * arguments[i].x + q.x * arguments[i].w + q.y * arguments[i].z - q.z * arguments[i].y,
                    q.w * arguments[i].y + q.y * arguments[i].w + q.z * arguments[i].x - q.x * arguments[i].z,
                    q.w * arguments[i].z + q.z * arguments[i].w + q.x * arguments[i].y - q.y * arguments[i].x
                );
            }
        }
        else
        {
            q.w *= arguments[i];
            q.x *= arguments[i];
            q.y *= arguments[i];
            q.z *= arguments[i];
        }
    }

    return q;
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.negate = function()
{
    return new Athena.Math.Quaternion(-this.w, -this.x, -this.y, -this.z);
}


/********************************* COMPARISON OPERATIONS ********************************/

Athena.Math.Quaternion.prototype.equals = function(quaternion)
{
    return (this.w == quaternion.w) && (this.x == quaternion.x) &&
           (this.y == quaternion.y) && (this.z == quaternion.z);
}

//-----------------------------------------------------------------------

Athena.Math.Quaternion.prototype.notEquals = function(quaternion)
{
    return (this.w != quaternion.w) || (this.x != quaternion.x) ||
           (this.y != quaternion.y) || (this.z != quaternion.z);
}


/**************************************** OTHERS ***************************************/

Athena.Math.Quaternion.prototype.__classname__ = 'Athena.Math.Quaternion';

Athena.Math.Quaternion_ZERO     = new Athena.Math.Quaternion(0.0, 0.0, 0.0, 0.0);
Athena.Math.Quaternion_IDENTITY = new Athena.Math.Quaternion(1.0, 0.0, 0.0, 0.0);

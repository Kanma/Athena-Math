/** @file   Intersects.js
    @author Philip Abbet

    Declaration of intersection-related functions

    @note   Using a pure JavaScript implementation here instead of a
            binding over the C++ functions results in faster code.
*/

Athena.Math.intersects = function(a, b)
{
    //_____ Internal intersection functions __________

    function intersects_aab_aab(box1, box2)
    {
        // Early-fail for nulls
        if (box1.isNull() || box2.isNull())
            return false;

        // Early-success for infinites
        if (box1.isInfinite() || box2.isInfinite())
            return true;

        // Use up to 6 separating planes
        if (box1.maximum.x < box2.minimum.x)
            return false;
        if (box1.maximum.y < box2.minimum.y)
            return false;
        if (box1.maximum.z < box2.minimum.z)
            return false;

        if (box1.minimum.x > box2.maximum.x)
            return false;
        if (box1.minimum.y > box2.maximum.y)
            return false;
        if (box1.minimum.z > box2.maximum.z)
            return false;

        // otherwise, must be intersecting
        return true;
    }


    function intersects_aab_sphere(box, sphere)
    {
        if (box.isNull())
            return false;

        if (box.isInfinite())
            return true;

        // Arvo's algorithm
        var d = 0;

        function process(c, min, max)
        {
            var s;

            if (c < min)
            {
                s = c - min;
                d += s * s;
            }
            else if (c > max)
            {
                s = c - max;
                d += s * s;
            }
        }

        process(sphere.center.x, box.minimum.x, box.maximum.x);
        process(sphere.center.y, box.minimum.y, box.maximum.y);
        process(sphere.center.z, box.minimum.z, box.maximum.z);

        return d <= sphere.radius * sphere.radius;
    }


    function intersects_aab_plane(box, plane)
    {
        return (plane.getSide(box) == Athena.Math.Plane_BOTH_SIDE);
    }


    function intersects_aab_vector(box, vector)
    {
        return box.contains(vector);
    }


    function intersects_sphere_sphere(sphere1, sphere2)
    {
        return sphere2.center.sub(sphere1.center).squaredLength() <=
                (sphere2.radius + sphere1.radius) * (sphere2.radius + sphere1.radius);
    }


    function intersects_sphere_plane(sphere, plane)
    {
        return (Math.abs(plane.getDistance(sphere.center)) <= sphere.radius);
    }


    function intersects_sphere_vector(sphere, vector)
    {
        return (vector.sub(sphere.center).squaredLength() <= sphere.radius * sphere.radius);
    }


    //_____ Parameters conversion __________

    var box1;
    var box2;
    var sphere1;
    var sphere2;
    var plane;
    var vector;

    function decode(obj)
    {
        if (obj.__classname__ == 'Athena.Math.AxisAlignedBox')
        {
            if (box1 === undefined)
                box1 = obj;
            else
                box2 = obj;
        }
        else if (obj.__classname__ == 'Athena.Math.Sphere')
        {
            if (sphere1 === undefined)
                sphere1 = obj;
            else
                sphere2 = obj;
        }
        else if (obj.__classname__ == 'Athena.Math.Plane')
        {
            plane = obj;
        }
        else if (obj.__classname__ == 'Athena.Math.Vector3')
        {
            vector = obj;
        }
    }

    decode(a);
    decode(b);


    //_____ Call the correct intersection function __________

    if (box1 !== undefined)
    {
        if (box2 !== undefined)
            return intersects_aab_aab(box1, box2);
        else if (sphere1 !== undefined)
            return intersects_aab_sphere(box1, sphere1);
        else if (plane !== undefined)
            return intersects_aab_plane(box1, plane);
        else if (vector !== undefined)
            return intersects_aab_vector(box1, vector);
    }
    else if (sphere1 !== undefined)
    {
        if (sphere2 !== undefined)
            return intersects_sphere_sphere(sphere1, sphere2);
        else if (plane !== undefined)
            return intersects_sphere_plane(sphere1, plane);
        else if (vector !== undefined)
            return intersects_sphere_vector(sphere1, vector);
    }

    return false;
}

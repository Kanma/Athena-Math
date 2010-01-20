/** @file   Intersection.h
    @author Philip Abbet
    
    Declaration of the class Athena::Math::Intersection
    
    @note   This is based on some methods from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#ifndef _ATHENA_MATH_INTERSECTION_H_
#define _ATHENA_MATH_INTERSECTION_H_

#include <Athena-Math/Prerequisites.h>


namespace Athena {
namespace Math {

	/** \addtogroup Math
	*  @{
	*/
	
	//------------------------------------------------------------------------------------
	/// @brief  Contains most of the intersection-related methods
	//------------------------------------------------------------------------------------
	class ATHENA_SYMBOL Intersection
	{
        //_____ Methods __________
    public:
        //--------------------------------------------------------------------------------
    	/// @brief  Tests whether a box intersects a sphere
    	//--------------------------------------------------------------------------------
        static bool intersects(const AxisAlignedBox& box, const Sphere& sphere);
		
    	//--------------------------------------------------------------------------------
    	/// @brief  Tests whether a box intersects a plane
    	//--------------------------------------------------------------------------------
        static bool intersects(const AxisAlignedBox& box, const Plane& plane);

    	//--------------------------------------------------------------------------------
    	/// @brief  Tests whether a point is within a box
    	//--------------------------------------------------------------------------------
        static bool intersects(const AxisAlignedBox& box, const Vector3& point);

    	//--------------------------------------------------------------------------------
    	/// @brief  Indicates if this sphere intersects another sphere
    	//--------------------------------------------------------------------------------
        static bool intersects(const Sphere& sphere1, const Sphere& sphere2);

    	//--------------------------------------------------------------------------------
    	/// @brief  Indicates if a sphere intersects a plane
    	//--------------------------------------------------------------------------------
        static bool intersects(const Sphere& sphere, const Plane& plane);
		
    	//--------------------------------------------------------------------------------
    	/// @brief  Indicates if a sphere intersects a point
    	//--------------------------------------------------------------------------------
        static bool intersects(const Sphere& sphere, const Vector3& point);
    };

	/** @} */
	/** @} */
}
}

#endif

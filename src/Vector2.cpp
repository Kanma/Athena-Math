/** @file   Vector2.cpp
    @author Philip Abbet
    
    Implementation of the class Athena::Math::Vector2
    
    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#include <Athena-Math/Vector2.h>

using namespace Athena::Math;


/************************************** CONSTANTS ***************************************/

const Vector2 Vector2::ZERO(0, 0);
const Vector2 Vector2::UNIT_X(1, 0);
const Vector2 Vector2::UNIT_Y(0, 1);
const Vector2 Vector2::NEGATIVE_UNIT_X(-1,  0);
const Vector2 Vector2::NEGATIVE_UNIT_Y( 0, -1);
const Vector2 Vector2::UNIT_SCALE(1, 1);

/** @file   Vector3.cpp
    @author Philip Abbet
    
    Implementation of the class Athena::Math::Vector3
    
    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#include <Athena-Math/Vector3.h>

using namespace Athena::Math;


/************************************** CONSTANTS ***************************************/

const Vector3 Vector3::ZERO(0, 0, 0);
const Vector3 Vector3::UNIT_X(1, 0, 0);
const Vector3 Vector3::UNIT_Y(0, 1, 0);
const Vector3 Vector3::UNIT_Z(0, 0, 1);
const Vector3 Vector3::NEGATIVE_UNIT_X(-1,  0,  0);
const Vector3 Vector3::NEGATIVE_UNIT_Y( 0, -1,  0);
const Vector3 Vector3::NEGATIVE_UNIT_Z( 0,  0, -1);
const Vector3 Vector3::UNIT_SCALE(1, 1, 1);

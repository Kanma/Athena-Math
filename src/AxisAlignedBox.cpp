/** @file   AxisAlignedBox.cpp
    @author Philip Abbet
    
    Implementation of the class Athena::Math::AxisAlignedBox
    
    @note   This is based on the corresponding class from
            <a href="http://www.ogre3d.org/">Ogre3D</a>.
*/

#include <Athena-Math/AxisAlignedBox.h>

using namespace Athena::Math;


/************************************** CONSTANTS ***************************************/

const AxisAlignedBox AxisAlignedBox::BOX_NULL;
const AxisAlignedBox AxisAlignedBox::BOX_INFINITE(AxisAlignedBox::EXTENT_INFINITE);

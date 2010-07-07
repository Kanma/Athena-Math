/**	@file	RandomNumberGenerator.h
	@author	Philip Abbet

	Declaration of the class 'Athena::Math::RandomNumberGenerator'
*/

#ifndef _ATHENA_MATH_RANDOMNUMBERGENERATOR_H_
#define _ATHENA_MATH_RANDOMNUMBERGENERATOR_H_

#include <Athena-Math/Prerequisites.h>


namespace Athena {
namespace Math {

	/** \addtogroup Math
	*  @{
	*/
	
	//------------------------------------------------------------------------------------
    /// @brief	Random number generator
    ///
    /// See http://en.wikipedia.org/wiki/Linear_congruential_generator
	//------------------------------------------------------------------------------------
    class ATHENA_SYMBOL RandomNumberGenerator
    {
    	//_____ Construction / Destruction __________
    public:
    	//--------------------------------------------------------------------------------
    	/// @brief  Constructor, the seed is derived from the current time
    	//--------------------------------------------------------------------------------
    	RandomNumberGenerator();

    	//--------------------------------------------------------------------------------
    	/// @brief  Destructor
    	//--------------------------------------------------------------------------------
    	~RandomNumberGenerator();


    	//_____ Methods __________
    public:
    	//--------------------------------------------------------------------------------
    	/// @brief  Sets the seed of the random number generation
    	//--------------------------------------------------------------------------------
    	void setSeed(unsigned int uiSeed);

    	//--------------------------------------------------------------------------------
    	/// @brief  Resets the generator to its initial seed
    	//--------------------------------------------------------------------------------
    	void reset();
    	
    	//--------------------------------------------------------------------------------
    	/// @brief  Returns a number in the interval [0, max]
    	//--------------------------------------------------------------------------------
    	unsigned int randomize(unsigned int max);

    	//--------------------------------------------------------------------------------
    	/// @brief  Returns a number in the interval [min, max]
    	//--------------------------------------------------------------------------------
    	unsigned int randomize(unsigned int min, unsigned int max);

    	//--------------------------------------------------------------------------------
    	/// @brief  Returns a number in the interval [0, max]
    	//--------------------------------------------------------------------------------
    	int randomize(int max);

    	//--------------------------------------------------------------------------------
    	/// @brief  Returns a number in the interval [min, max]
    	//--------------------------------------------------------------------------------
    	int randomize(int min, int max);

    	//--------------------------------------------------------------------------------
    	/// @brief  Returns a number in the interval [0, max[
    	//--------------------------------------------------------------------------------
    	float randomize(float max);

    	//--------------------------------------------------------------------------------
    	/// @brief  Returns a number in the interval [min, max[
    	//--------------------------------------------------------------------------------
    	float randomize(float min, float max);
    	
    	//--------------------------------------------------------------------------------
    	/// @brief  Returns a number in the interval [0, (2^32)-1]
    	//--------------------------------------------------------------------------------
    	unsigned int randomize();


    	//_____ Attributes __________
    private:
    	unsigned int m_uiSeed;
        unsigned int m_uiCurrent;
    };

	/** @} */
	/** @} */
}
}

#endif

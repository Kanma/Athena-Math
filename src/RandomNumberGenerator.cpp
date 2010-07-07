/**	@file	RandomGenerator.cpp
	@author	Philip Abbet

	Implementation of the class 'Athena::Math::RandomNumberGenerator'
*/

#include <Athena-Math/RandomNumberGenerator.h>
#include <math.h>
#include <time.h>


using namespace Athena::Math;


/************************************** CONSTANTS ***************************************/

const unsigned int A = 1664525;
const unsigned int B = 1013904223;
const uint64 N = 0x100000000LL;


/****************************** CONSTRUCTION / DESTRUCTION ******************************/

RandomNumberGenerator::RandomNumberGenerator()
: m_uiSeed(0), m_uiCurrent(0)
{
	m_uiSeed = time(0);
    m_uiCurrent = m_uiSeed;
}

//-----------------------------------------------------------------------

RandomNumberGenerator::~RandomNumberGenerator()
{
}


/*************************************** METHODS ****************************************/

void RandomNumberGenerator::setSeed(unsigned int uiSeed)
{
	m_uiSeed = uiSeed;
    m_uiCurrent = m_uiSeed;
}

//-----------------------------------------------------------------------

void RandomNumberGenerator::reset()
{
    m_uiCurrent = m_uiSeed;
}

//-----------------------------------------------------------------------

unsigned int RandomNumberGenerator::randomize(unsigned int max)
{
	return randomize() % ((uint64) max) + 1;
}

//-----------------------------------------------------------------------

unsigned int RandomNumberGenerator::randomize(unsigned int min, unsigned int max)
{
	return randomize() % (((uint64) max) + 1 - min) + min;
}

//-----------------------------------------------------------------------

int RandomNumberGenerator::randomize(int max)
{
	return randomize() % ((int64) max) + 1;
}

//-----------------------------------------------------------------------

int RandomNumberGenerator::randomize(int min, int max)
{
	return randomize() % (((int64) max) + 1 - min) + min;
}

//-----------------------------------------------------------------------

float RandomNumberGenerator::randomize(float max)
{
	return fmod(randomize(), max);
}

//-----------------------------------------------------------------------

float RandomNumberGenerator::randomize(float min, float max)
{
	return fmod(randomize(), max - min) + min;
}

//-----------------------------------------------------------------------

unsigned int RandomNumberGenerator::randomize()
{
	m_uiCurrent = (A * m_uiCurrent + B) % N;
	return m_uiCurrent;
}

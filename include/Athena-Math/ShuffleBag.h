/**	@file	ShuffleBag.h
	@author	Philip Abbet

	Declaration of the class 'Athena::Math::ShuffleBag'
	
    @note   This is based on the article
            <a href="http://kaioa.com/node/53">'Never-ending Shuffled Sequences - When Random is too Random'</a>.
*/

#ifndef _ATHENA_MATH_SHUFFLEBAG_H_
#define _ATHENA_MATH_SHUFFLEBAG_H_

#include <Athena-Math/Prerequisites.h>
#include <Athena-Math/RandomNumberGenerator.h>


namespace Athena {
namespace Math {

	/** \addtogroup Math
	*  @{
	*/
	
	//------------------------------------------------------------------------------------
    /// @brief	Contains some elements that can be retrieved in a
    ///         random-but-still-controlled order
    ///
    /// Each element can appear several times in the bag, giving him a higher probability
    /// being the next retrieved one.
    ///
    /// The goal is to avoid the problem of classical random number generation, where a
    /// number can never appear in practice. With a shuffle bag, each element is guaranted
    /// to be retrieved, as many times as it is present in the bag, each time you retrieve
    /// as many elements as the bag size, but in a random order. 
    ///
    /// See http://kaioa.com/node/53 for more details
	//------------------------------------------------------------------------------------
    template<typename T>
    class ShuffleBag
    {
    	//_____ Construction / Destruction __________
    public:
    	//--------------------------------------------------------------------------------
    	/// @brief  Constructor, the seed is derived from the current time
    	//--------------------------------------------------------------------------------
    	ShuffleBag()
    	: m_uiCursor(0), m_uiSize(0), m_uiCapacity(10), m_data(0)
    	{
            m_data = new T[m_uiCapacity];
    	}

    	//--------------------------------------------------------------------------------
    	/// @brief  Destructor
    	//--------------------------------------------------------------------------------
    	~ShuffleBag()
    	{
            delete[] m_data;
    	}


    	//_____ Methods __________
    public:
    	//--------------------------------------------------------------------------------
    	/// @brief  Sets the seed of the random number generation (used to choose the
    	///         order of the elements)
    	//--------------------------------------------------------------------------------
    	void setSeed(unsigned int uiSeed)
    	{
            m_rnd.setSeed(uiSeed);
    	}

    	//--------------------------------------------------------------------------------
    	/// @brief  Resets the bag to its initial state, like of no element had been
    	///         retrieved yet
    	//--------------------------------------------------------------------------------
    	void reset()
    	{
            m_rnd.reset();
            m_uiCursor = m_uiSize - 1;
    	}
    	
    	//--------------------------------------------------------------------------------
    	/// @brief  Add an element to the bag
    	///
    	/// @param  element     The element
    	/// @param  quantity    Number of occurences of the element in the bag
    	//--------------------------------------------------------------------------------
    	void add(T element, unsigned int quantity = 1)
    	{
            assert(quantity > 0);
    	    
            int pos = m_uiSize;
            m_uiSize += quantity;

            if (m_uiSize > m_uiCapacity)
            {
                m_uiCapacity = (m_uiCapacity * 3) / 2 + 1;
                
                if (m_uiSize > m_uiCapacity)
                    m_uiCapacity = m_uiSize;
                
                T* oldData = m_data;
                m_data = new T[m_uiCapacity];
                memcpy(m_data, oldData, (m_uiSize - quantity) * sizeof(T));
                
                delete[] oldData;
            }

            for (unsigned int i = 0; i < quantity; ++i)
                m_data[pos + i] = element;

            m_uiCursor = m_uiSize - 1;
    	}

    	//--------------------------------------------------------------------------------
    	/// @brief  Retrieves the next element
    	//--------------------------------------------------------------------------------
    	T next()
    	{
    	    if (m_uiCursor < 1)
    	    {
                m_uiCursor = m_uiSize - 1;
                return m_data[0];
            }
            
            unsigned int index = m_rnd.randomize(m_uiCursor);

            T element = m_data[index];
            m_data[index] = m_data[m_uiCursor];
            m_data[m_uiCursor] = element;

            --m_uiCursor;

            return element;
    	}


    	//_____ Attributes __________
    private:
        RandomNumberGenerator   m_rnd;
    	unsigned int            m_uiCursor;
        unsigned int            m_uiSize;
        unsigned int            m_uiCapacity;
        T*                      m_data;
    };


    typedef ShuffleBag<uint64>          UInt64ShuffleBag;
    typedef ShuffleBag<int64>           Int64ShuffleBag;
    typedef ShuffleBag<unsigned int>    UIntShuffleBag;
    typedef ShuffleBag<int>             IntShuffleBag;
    typedef ShuffleBag<unsigned short>  UShortShuffleBag;
    typedef ShuffleBag<short>           ShortShuffleBag;
    typedef ShuffleBag<unsigned char>   UCharShuffleBag;
    typedef ShuffleBag<char>            CharShuffleBag;
    typedef ShuffleBag<Real>            RealShuffleBag;
    typedef ShuffleBag<std::string>     StringShuffleBag;

	/** @} */
	/** @} */
}
}

#endif

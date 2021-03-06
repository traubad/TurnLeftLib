/*!
 * \file TurnLeftLib/utils/src/explosion.h
 * The Explosion class was built to give PHP's 'explode' functionality,
 * aka 'split' in any other language (that was a jab at PHP). 
 */


#ifndef TL_UTILS_EXPLOSION_H_
#define TL_UTILS_EXPLOSION_H_

#include <TurnLeftLib/TurnLeft.h>
#include <string>
#include <sstream>

/*! \brief The TurnLeft namespace describes all C++ modules created by employees
 * of Turn Left, LLC.
 */
namespace TurnLeft {
/*! \brief The Utils namespace encompasses all Turn Left modules that are used as 
 * utilities for other software.
 */
namespace Utils {


/*! \brief A class for splitting strings into an array, separated by 
 * a delimiter.
 */
class Explosion
{
    /*! The string to be exploded */
	std::string str;

	/*! The number of words in the string.
	 * \sa explode()*/
	int numWords;

	/*! A pointer to the array, if desired.
	 * \sa getArrayPtr()
	 */
	std::string *arrayPtr;

public:
	Explosion();
	/*! Standard constructor, takes in the string to be iterated over.
	 * @param a string of up to 300 words.*/
	Explosion(std::string);

	/*! Splits the string at any instance of the delimiter char, filling the instance array.
	 * @param a character delimiting the string
     * @param an array to be filled with the words' contents.
     * @param (optional) Only keep alpha characters (default True).
     * @param (optional) Maintain of strings (default False -- converts to lower)
     */
    void explode(char delim, std::string[], bool alphaOnly=0, bool keepCase=1);

	/*! Returns the pointer to the instance array.
	 * @return a pointer to the instance array
	 * \sa arrayPtr
	 */
    std::string* getArrayPtr();

	/*! Retrieves the number of words that were parsed from the input string.
	 * @return the number of words in the input string
	 * \sa numWords
	 */
    int getNumWords();
};

inline std::string* Explosion::getArrayPtr()
{
	return arrayPtr;
}

inline int Explosion::getNumWords()
{
	return numWords;
}

}//namespace Utils
}//namespace TurnLeft

#endif //TL_UTILS_EXPLOSION_H_

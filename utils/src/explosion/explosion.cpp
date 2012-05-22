/*
 * strings.cpp
 *
 *  Created on: Apr 19, 2012
 *      Author: tom
 */

#include "explosion.h"
#include <iostream>
namespace TurnLeft {
namespace Utils {

Explosion::Explosion(std::string aString)
{
    str = aString;
    numWords = 0;
}

std::string*
Explosion::getArrayPtr()
{
    return arrayPtr;
}

void
Explosion::explode (char delimiter, std::string array[], 
        bool alphaOnly=1, bool keepCase=0)
{
    std::stringstream buffer;
	int maxLength = str.length();
	for (int ch = 0; ch < maxLength; ch++)
	{
	    char char_ = str[ch];
	    
        /* If it's a letter, or the object doesn't care whether about 
         * non alpha characters
         */
        if (isalpha(char_) || !alphaOnly)
	    {
	        if (!keepCase && isupper(char_)) char_ = tolower(char_);
	        buffer << char_;
	    }
	    /*! If we've found a delimiter, or the end of the string,
         * send everything in the buffer to a std::string and clear
         * the buffer so that it can accept more input.
         */
        if (
                char_ == delimiter 
                || char_ == '/' 
                || char_ == '\n'
                || ch == maxLength-1)
	    {
	        std::string asString = buffer.str();
            array[numWords] = asString;
	        numWords++;
	        buffer.str("");
	    }
	}
}

int
Explosion::getNumWords()
{
    return numWords;
}

}}


#include <TurnLeftLib/Utils/wordaggregator.h>
#include <TurnLeftLib/Utils/commonwords.h>
#include <TurnLeftLib/Utils/explosion.h>
namespace TurnLeft
{
namespace Utils{

WordAggregator::WordAggregator()  { library =0;}

WordAggregator::WordAggregator (std::string& words, FrequencyMap& _map, 
        const char* libFilename=0)
{
	library = new CommonWords(libFilename);
    parse(words, _map);
}

WordAggregator::WordAggregator (std::vector <std::string> &words, FrequencyMap& _map, 
        const char* libFilename=0)
{
	library = new CommonWords(libFilename);
    for (unsigned int i = 0; i < words.size(); i++)
    {
        parse(words[i],_map);
    }
}

WordAggregator::WordAggregator (FrequencyVector& words, FrequencyMap& _map,
        const char* libFilename=0)
{
	library = new CommonWords(libFilename);
    for (unsigned int i=0; i < words.size(); i++)
    {
        parse(words[i], _map);
    }
}

void WordAggregator::parse (std::string& words, FrequencyMap& _map)
{
    std::string wordset[WORDSET_ARRAY_SIZE];
    Explosion explosion(words);
    explosion.explode(' ', wordset);

    /* Iterate through all the words in the wordset. */
    for (int w=0; w < WORDSET_ARRAY_SIZE; w++)
    {
        if (wordset[w] == "") break;
        bool found = !(_map.find(wordset[w]) == _map.end());
        bool add = (!found && !library->find(wordset[w]));
        if (found || add)
        {
            _map[wordset[w]]++;
        }
    }
}

WordAggregator::~WordAggregator()
{
	delete library;
}

}//namespace Utils
}//namespace TurnLeft

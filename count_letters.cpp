#include "count_letters.hpp"
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::string;

void count_letters(ifstream &theStream, int *letterCount)
{
    string paragraph;
        if (getline(theStream, paragraph))
        {
            for (int i = 0; i < paragraph.size(); i++)
            {
                int character = paragraph[i];

                //Turn capital letters into lower-case
                if (character > 64 && character < 91)
                {
                    character = character + ('a' - 'A');
                }

                //If the character is a lower-case letter, increment the array accordingly.
                if (character > 96 && character < 123)
                {
                    letterCount[(character - 96)]++;
                }
            }
        }
    
}
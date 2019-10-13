/********************************************************************* 
** Title: Lab 2
** Author: Katheen Thurmes
** Date: 12 Oct., 2019
*********************************************************************/ 

#include "count_letters.hpp"
#include <fstream>
#include <iostream>
#include <string>

using std::getline;
using std::ifstream;
using std::string;

/********************************************************************* 
** count_letters description: count_letters takes two arguments: an 
output file stream variable and a pointer to an array of integers 
that should beat least 27 ints long and initialized to 0 before 
calling this function. 
The function reads the paragraph from the input file stream and then 
counts the letter frequency, storing frequencies in alphabetical 
order in the array, starting with 'a' at index 1. This function is 
not case-sensitive and does not count anything but alphabet 
characters.
Return type is void.
*********************************************************************/ 
void count_letters(ifstream &theStream, int *letterCount)
{
    string paragraph;
        //Save the paragraph in the stream to "paragraph"
        if (getline(theStream, paragraph))
        {
            //Iterate through each character in paragraph
            for (int i = 0; i < paragraph.size(); i++)
            {
                int character = paragraph[i];

                //Turn capital letters into lower-case
                if (character > 64 && character < 91)
                {
                    character = character + ('a' - 'A');
                }

                //If the character is a lower-case letter, increment the array accordingly.
                if (character > 96 && character < 123) //This will ignore all non-letter characters.
                {
                    letterCount[(character - 96)]++;
                }
            }
        }
    
}
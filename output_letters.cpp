/********************************************************************* 
** Title: Lab 2
** Author: Katheen Thurmes
** Date: 12 Oct., 2019
*********************************************************************/

#include "output_letters.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

/********************************************************************* 
** output_letters description: output_letters takes two arguments: an 
output file stream variable and a pointer to an array of integers 
that contain frequencies of letters. The array must be at least 27 
ints long and will have the count for 'a' stored in index 1 of the 
array.
The function asks the user to name a file in which the output will be 
saved. Once the user has entered a file name, then the contents of 
the array of integers is saved in the text file.
Return type is void.
*********************************************************************/ 
void output_letters(std::ofstream &stream, int *letterCount)
{
    //Get output file name from user
    string fileName;
    cout << "What would you like to name this file?\n";
    cin >> fileName;
    fileName = fileName + ".txt";
    //Converting to c_string inspired by http://www.cplusplus.com/forum/beginner/24499/
    //Accessed 10.12.19
    stream.open(fileName.c_str());

    //Save the contents of the array into the file
    for (int i = 1; i <= 26; i++)
    {
        stream << (char)(i + 96) << ": " << letterCount[i] << "\n";
    }

    //Return without closing ofstream
}
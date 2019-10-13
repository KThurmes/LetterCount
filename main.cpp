/********************************************************************* 
** Title: Lab 2
** Author: Katheen Thurmes
** Date: 12 Oct., 2019
** Description: This main function drives the program for Lab 2 of 
Oregon State University's CS162 in the fall of 2019. The program 
takes an input file, counts the frequency of each letter in each 
paragraph, and saves the letter count in a new file for each 
paragraph.
*********************************************************************/ 
#include <fstream>
#include "output_letters.hpp"
#include "count_letters.hpp"
#include <iostream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::string;
using std::cin;

int main()
{

    ifstream inputStream;
    string inFile;

    //Ask user for input file
    cout << "What is the name of the file you would like to use for input (must end in \".txt\")?\n";
    cin >> inFile;
    //Converting to c_string inspired by http://www.cplusplus.com/forum/beginner/24499/
    //Accessed 10.12.19
    inputStream.open(inFile.c_str());

    //If the file doesn't open, ask user to re-enter it.
    while (!inputStream){
        cout << "Could not open the file \""<< inFile <<".\" Please try again.\n";
        cin >> inFile;
        inputStream.open(inFile.c_str());
    }

    //Run count_letters and output_letters on each paragraph until eof has been reached
    while(!(inputStream.eof())){
        int letters[27] = {0};
        count_letters(inputStream, letters);
        ofstream outputStream;
        output_letters(outputStream, letters);
        outputStream.close();
    }
    
    inputStream.close();
    return 0;
}
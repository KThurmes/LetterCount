#include "output_letters.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

void output_letters(std::ofstream &stream, int *letterCount)
{
    string fileName;

    cout << "What would you like to name this file?\n";
    cin >> fileName;

    fileName = fileName + ".txt";
    stream.open(fileName.c_str());

    for (int i = 1; i <= 26; i++)
    {
        stream << (char)(i + 96) << ": " << letterCount[i] << "\n";
    }

    stream.close();
}
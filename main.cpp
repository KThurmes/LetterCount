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
    cout << "What is the name of the file you would like to use for input (must end in \".txt\")?\n";
    cin >> inFile;
    inputStream.open(inFile.c_str());
    while (!inputStream){
        cout << "Could not open the file \""<< inFile <<".\" Please try again.\n";
        cin >> inFile;
        inputStream.open(inFile.c_str());
    }

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
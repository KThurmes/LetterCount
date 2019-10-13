#include <fstream>
#include "output_letters.hpp"
#include "count_letters.hpp"

using std::ifstream;
using std::ofstream;

int main()
{

    ifstream inputStream;
    inputStream.open("file_fun.txt");

    int letters[27] = {0};
    count_letters(inputStream, letters);

    inputStream.close();

    ofstream outputFile;
    output_letters(outputFile, letters);

    return 0;
}
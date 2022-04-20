#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream f1;
    f1.open("D:\\data\\3words-per-line.txt", ios::out);

    string words;
    getline(cin, words);

    int startId = 0, endId = 0, counter = 0;
    string threeWordsPerLine;

    while ((startId = words.find_first_not_of(" ,;:-", endId)) != string::npos)
    {
        endId = words.find_first_of(" ,;:-", startId);

        threeWordsPerLine += words.substr(startId, endId - startId) + " ";

        counter++;

        if (counter % 3 == 0)
        {
            threeWordsPerLine.replace(threeWordsPerLine.length() - 1, 1, "\n");
        }
    }

    f1 << threeWordsPerLine.erase(threeWordsPerLine.length() - 1);

    f1.close();
}
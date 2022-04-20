#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream f1;
    f1.open("D:\\data\\3words-per-line.txt", ios::out);

    string words;
    getline(cin, words);

    int interval = -1;
    while ((interval = words.find("  ")) != string::npos)
    {
        words.erase(interval, 1);
    }

    int whiteSpaceCounter = 0;
    int pos = -1;
    while ((pos = words.find(" ", pos + 1)) != string::npos)
    {
        whiteSpaceCounter++;

        if (whiteSpaceCounter % 3 == 0)
        {
            words[pos] = '\n';
        }
    }

    f1 << words;

    f1.close();
}
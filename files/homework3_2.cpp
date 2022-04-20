#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    fstream f1;
    f1.open("D:\\data\\3duminared.txt", ios::out);

    string line;
    //getline(cin, line);
    line = "Pri razbota s fajlove se izpolzva klasat fstream da go duha stoicho pedala";
    string currentWord;

    vector<string> words;

    //https://stackoverflow.com/a/12447526
    for (size_t p = 0, q = 0; p != line.npos; p = q)
    {
        currentWord = line.substr(p + (p != 0), (q = line.find(' ', p + 1)) - p - (p != 0));
        words.push_back(currentWord);
    }

    while (words.size() > 0)
    {
        string threeWordsPerLine = "";
        for (int i = 0; i < 3; i++)
        {
            if (words.size() > 0)
            {
                threeWordsPerLine += words.at(0) + " ";
                words.erase(words.begin());
            }
        }

        if (words.size() >= 1)
        {
            threeWordsPerLine.replace(threeWordsPerLine.length() - 1, 1, "\n");
        }
        else
        {
            threeWordsPerLine.erase(threeWordsPerLine.length() - 1);
        }

        f1 << threeWordsPerLine;
    }

    f1.close();
}
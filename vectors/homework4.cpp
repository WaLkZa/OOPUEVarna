#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    fstream f1;
    f1.open("D:\\data\\words.txt", ios::in);

    if (!f1.is_open())
    {
        cout << "File is not found!" << endl;
        return -1;
    }

    vector<string> words;
    string word;

    while (!f1.eof())
    {
        getline(f1, word, '\n');

        int id = 0;
        while (id < words.size() && word > words[id])
        {
            id++;
        }

        if (id == words.size())
        {
            words.push_back(word);
        }
        else
        {
            words.insert(words.begin() + id, word);
        }
    }

    f1.close();

    fstream f2;
    f2.open("D:\\data\\output.txt", ios::out);

    for (int i = 0; i < words.size(); i++)
    {
        f2 << words[i] << endl;
    }

    f2.close();
}
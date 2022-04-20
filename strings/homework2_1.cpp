#include <iostream>

using namespace std;

int main()
{
    // Knyaz Boris 3, number 77, room 51
    string words;
    getline(cin, words);

    string currentWord;
    string longestWord;

    for (int i = 0; i < words.length(); i++)
    {
        if (words[i] != ' ')
        {
            currentWord += words[i];
        }
        else
        {
            currentWord.clear();
        }

        if (currentWord.length() >= longestWord.length())
        {
            longestWord = currentWord;
        }
    }

    cout << longestWord << endl;
}
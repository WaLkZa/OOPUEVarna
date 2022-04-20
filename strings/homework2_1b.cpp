#include <iostream>

using namespace std;

int main()
{
    // Knyaz Boris 3, number 77, room 51
    string words;
    getline(cin, words);

    int startId = 0;
    int endId = 0;

    string currentWord;
    string longestWord;

    while ((startId = words.find_first_not_of("0123456789. !,;:?-", endId)) != string::npos)
    {
        endId = words.find_first_of("0123456789. !,;:?-", startId);

        currentWord = words.substr(startId, endId - startId);

        if (currentWord.length() >= longestWord.length())
        {
            longestWord = currentWord;
        }
    }

    cout << longestWord << endl;
}
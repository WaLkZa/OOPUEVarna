#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int vowels_counter(string input)
{
    int vowels = 0;
    for (char ch : input)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            vowels++;
        }
    }

    return vowels;
}

bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}

int main()
{
    //string str;
    //cin >> str;
    // do {
    //     cout << "Enter text: ";
    //     getline(cin, str);
    // } while (str.length() == 0);

    // cout << "Text:" << str << endl;

    //cout << vowels_counter(str);

    // Намерете броят на гласните в един текст
    // string test = "Hello, World! Hello Varna.";
    // size_t p = -1, glas = 0;
    // while ((p = test.find_first_of("aoieuyAOIEUY", p + 1)) != string::npos)
    // {
    //     glas++;
    // }

    // cout << glas << endl;

    // Въведете текст от клавиатурата.
    // Проверете, дали текста е число
    // Пример: 1234.12 -> ДА 12й33к544л -> НЕ
    // size_t p = -1, digit = 0;
    // string chislo;
    // getline(cin, chislo);

    // while ((p = chislo.find_first_of("1234567890,.", p + 1)) != string::npos)
    // {
    //     digit++;
    // }
    // if (digit == chislo.length() && chislo.find(".") == chislo.rfind("."))
    // {
    //     cout << "Yes";
    // }
    // else
    // {
    //     cout << "No";
    // }

    // Премахнете излишните интервали в стринга
    // string prim1 = "Az    se              ucha      da programiram.";
    // size_t pos = 0;
    // while ((pos = prim1.find("  ", pos)) != string::npos) {
    //     prim1.erase(pos, 1);
    // }

    // cout << prim1 << endl;

    // Намерете броят на думите в един стринг
    string prim2 = "Az,    se  123     -       ucha      da programiram.";
    size_t dumi = 0;
    size_t p1 = prim2.find_first_not_of(" ,.!-_0123456789:?");
    while (p1 != string::npos)
    {
        size_t p2 = prim2.find_first_of(" ,.!-_0123456789:?", p1);
        cout << prim2.substr(p1, p2 - p1) << endl;
        p1 = prim2.find_first_not_of(" ,.!-_0123456789:?", p2);
        dumi++;
    }
    cout << "Dumite sa " << dumi << endl;
}
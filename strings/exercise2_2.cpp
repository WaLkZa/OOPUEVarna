#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;

    do
    {
        cout << "Enter text:";
        getline(cin, str); //cin >> str;
    } while (str == "");   // str.length()==0    str.empty()

    cout << "Text:" << str << endl;

    string test = "Hello, World! HELLO VARNA.";
    cout << test.find_first_of("ndr") << endl;
    cout << test.find_first_of("ndr", 12) << endl;
    cout << test.find_last_of("ndr") << endl;
    cout << test.find_last_of("ndr", 12) << endl;
    cout << test << endl;

    for (int i = 0; i < test.size(); i++)
    {
        test[i] = tolower(test[i]);
    }
    cout << test << endl;

    // Намерете броят на гласните в един текст
    size_t p = -1, glas = 0;
    while ((p = test.find_first_of("aeoiuy", p + 1)) != string::npos)
    {
        //cout << "Position:" << p << endl;
        glas++;
    }
    cout << "Glasnite sa " << glas << endl;

    // Въведете текст от клавиатурата. Проверете дали текста е
    // коректно число.
    // Пример:  123.56    -> ДА        12!#3a23bnm2    -> НЕ
    // Вариант 1:
    string chislo;
    size_t pos = -1, digit = 0;
    cout << "Number:";
    cin >> chislo;
    while ((pos = chislo.find_first_of("0123456789.", pos + 1)) != string::npos)
    {
        digit++;
    }
    if (digit == chislo.size() &&
        chislo.find(".") == chislo.rfind("."))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    // Вариант 2:
    if (chislo.find_first_not_of("0123456789.") == string::npos &&
        chislo.find(".") == chislo.rfind("."))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    // Намерете броят на буквите в един текст
    string primer = "Az  ,   se    alpha123   ucha   da   programiram.";
    size_t ind = -1, bukvi = 0;
    while ((ind = primer.find_first_not_of("0123456789. !,;:?-", ind + 1)) != string::npos)
    {
        bukvi++;
    }
    cout << "Bukvite sa " << bukvi << endl;
    cout << primer.erase(10, 7) << endl;
    cout << primer.replace(7, 4, "ne se") << endl;
    cout << primer.insert(10, " shte ") << endl;

    // Да се премахнат излишните интервали между думите
    size_t interval;
    while ((interval = primer.find("  ")) != string::npos)
    {
        primer.erase(interval, 1);
    }
    cout << primer << endl;
    // "Az  ,   se    alpha123   ucha   da   programiram."
    // Намерете броят на думите в текста
    size_t na4alo, krai = 0, dumi = 0;
    while ((na4alo = primer.find_first_not_of("0123456789. !,;:?-", krai)) != string::npos)
    {
        krai = primer.find_first_of("0123456789. !,;:?-", na4alo);
        cout << primer.substr(na4alo, krai - na4alo) << endl;
        dumi++;
    }
    cout << "Dumite sa " << dumi << endl;
}
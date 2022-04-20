#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "Hello, World!";
    cout << a << endl;
    cout << a.length() << endl;
    cout << a.size() << endl;

    for (int i = 0; i < a.length(); i++)
    {
        cout << a[i] << endl;
        cout << a.at(i) << endl;
    }

    // Извеждане на текста на обратно
    for (int i = 0; i < a.length(); i++)
    {
        cout << a[a.length() - i - 1] << endl;
    }
    for (int x = a.length() - 1; x >= 0; x--)
    {
        cout << a[x] << " ";
    }
    cout << endl;

    // Извеждане на текста, чрез while
    int x = a.length() - 1;
    while (x >= 0)
    {
        cout << a[x--] << " ";
    }
    cout << endl;

    string a = "Hello, World!";

    for (string::iterator t = a.begin(); t != a.end(); t++)
    {
        cout << *t << "_";
    }
    cout << endl;

    for (string::reverse_iterator t = a.rbegin(); t != a.rend(); t++)
    {
        cout << *t << "_";
    }
    cout << endl;

    int br = 0; // променлива със стойност 0
    for (string::iterator t = a.begin(); t != a.end(); t++)
    {
        if (*t == 'o')
        {
            br++; // увеличение с 1
        }
    }
    cout << "se sre6ta " << br << endl; // след цикъла се извежда

    string r = "Hello, World!";
    string m = r + "Hello, Varna";
    m = m + '!';
    cout << m << endl;

    cout << m.find("lo") << endl;
    cout << m.find("lol") << endl;
    cout << string::npos << endl; // -1

    if (m.find("lo") == string::npos)
    {
        cout << "No found\n";
    }
    else
    {
        cout << "Found\n";
    }

    size_t pos = -1;
    pos = m.find("o", pos + 1); // 4
    cout << pos << ",";
    pos = m.find("o", pos + 1); // 8
    cout << pos << ",";
    pos = m.find("o", pos + 1); // 17
    cout << pos << ",";
    pos = m.find("o", pos + 1); // -1
    cout << pos << ",";
    pos = m.find("o", pos + 1); // 4
    cout << pos << ",";

    size_t pos = -1;
    while ((pos = m.find("ll", pos + 1)) != string::npos)
    {
        cout << "at " << pos << endl;
    }

    cout << m.substr(7, 5) << endl;
    cout << m.substr(20) << endl;
}
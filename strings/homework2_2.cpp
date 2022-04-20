#include <iostream>

using namespace std;

int main()
{
    // Knyaz Boris 3, number 77, room 51, fn.103567
    string str;
    getline(cin, str);

    int id = -1;

    while ((id = str.find_first_of("1234567890", id + 1)) != string::npos)
    {
        str[id] = '*';
    }

    while ((id = str.find("**")) != string::npos)
    {
        str.replace(id, 2, "*");
    }

    cout << str << endl;
}
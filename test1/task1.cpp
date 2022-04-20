#include <iostream>

using namespace std;

int main()
{
    string date;
    getline(cin, date);

    int p1 = date.find(".");
    int p2 = date.find(".", p1 + 1);
    string day = date.substr(0, p1);
    string month = date.substr(p1 + 1, p2 - p1 - 1);
    string year = date.substr(p2 + 1);

    if (year.length() == 2)
    {
        year.insert(0, "20");
    }

    cout << year << "/" << month << "/" << day;
}
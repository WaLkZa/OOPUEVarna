#include <iostream>

using namespace std;

int main()
{
    // student@ue-varna.bg
    string email;
    cin >> email;

    int id = email.find("@");
    int id2 = email.find_last_of(".");

    cout << "user: " << email.substr(0, id) << endl;
    cout << "host: " << email.substr(id + 1) << endl;
    cout << "nationality: "
         << (email.substr(id2 + 1).compare("bg") == 0 ? "bulgarian" : "not bulgarian")
         << endl;
}
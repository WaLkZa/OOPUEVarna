#include <iostream>
#include <string>
#include <fstream> // 1

using namespace std;

int main()
{
    fstream f1, f2;                          // 2
    f1.open("D:\\data\\staff.txt", ios::in); // 3
    //string pat = "D:\\data\\staff.txt";
    //f1.open(pat, ios::in);
    if (!f1.is_open()) // 4
    {
        cout << "File not found" << endl;
        return -1;
    }
    f2.open("D:\\data\\rezultat.txt", ios::out);
    f2 << "SRAVKA ZA ZAPLATITE\n";
    f2 << "================================\n";
    string ime;
    int dni;
    double nadn;
    double sum = 0;
    double max = -1;
    double min = 1000000;
    string min_ime, max_ime;
    while (!f1.eof())
    {
        getline(f1, ime, '\t');
        f1 >> dni >> nadn;
        cout << ime << "\t" << dni << "\t" << nadn << "\t" << dni * nadn;
        f2 << ime << "\t\t" << dni * nadn << "lv.\t" << dni * nadn * 0.1;
        sum += dni * nadn;

        if (min > dni * nadn)
        {
            min = dni * nadn;
            min_ime = ime;
        }
        if (max < dni * nadn)
        {
            max = dni * nadn;
            max_ime = ime;
        }
    }
    cout << "\nRich: " << max_ime << "\t" << max << "\nPoor: " << min_ime << "\t" << min << endl;
    f2 << "\n================================\n";
    f2 << "Obshta suma:\t\t" << sum << "lv. DOD:\t" << sum * 0.1;
    f1.close(); // 5
    f2.close();
}
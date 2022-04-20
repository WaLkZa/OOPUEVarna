#include <iostream>
#include <string>
#include <fstream> // 1
using namespace std;

int main()
{
    fstream f1, f2; //2
    // Вариант 1
    string filename = "d:\\data\\tech.txt";
    f1.open(filename, ios::in); // 3
    //cout << filename << endl;
    // Вариант 2
    //f1.open("d:\\data\\tech.txt", ios::in);

    if (!f1.is_open())
    {
        cout << "File not found!\n";
        return -1;
    }
    f2.open("d:\\data\\zapis.txt", ios::out);
    f2 << "НАЛИЧНА ТЕХНИКА\n";
    f2 << "---------------------------------------\n";
    //4

    string ime;
    int broi;
    double cena, suma = 0;
    // Да се изведе на екрана най-скъпата техника
    string max_ime = "";
    double max_cena = 0;
    string min_ime = "";
    double min_cena = 1000000;

    while (!f1.eof())
    {
        getline(f1, ime, '\t'); // Четене от файла
        f1 >> broi >> cena;

        if (ime.length() < 9)
        {
            ime += "\t"; // Ако името е по-малко
        }

        //cout << ime << "\t\t" << broi << "\t" << cena << "\t" << broi * cena;

        f2 << ime << "\t\t" << broi << "\t" << cena << "\t" << broi * cena;

        suma += cena * broi;

        if (max_cena < cena)
        {
            max_cena = cena;
            max_ime = ime;
        }
        if (min_cena > cena)
        {
            min_cena = cena;
            min_ime = ime;
        }
    }
    cout << "\nNaj-skapata stoka e " << max_ime << " na cena " << max_cena;
    cout << "\nNaj-eftinata stoka e " << min_ime << " na cena " << min_cena;
    f2 << "\n---------------------------------------\n";
    f2 << "ОБЩА СТОЙНОСТ:\t\t\t\t" << suma;
    f1.close(); // 5
    f2.close();
}
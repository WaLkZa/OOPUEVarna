#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Student
{
public:
    Student();               // Конструктор 1
    Student(int f, string i) // Конструктор 2
    {
        fn = f;
        ime = i;
        kurs = -1;
    }
    Student(int f, string i, int k) // Конструктор 3
    {
        fn = f;
        ime = i;
        setKurs(k);
    }
    ~Student(); // Деструктор
    int fn;
    string ime;
    void view();
    void setKurs(int k)
    {
        if (k >= 1 && k <= 5)
        {
            kurs = k;
        }
        else
        {
            kurs = -1;
        }
    }
    string getKursName()
    {
        string imena[] = {"Parvi kurs", "Vtori kurs", "Treti kurs", "4etvarti kurs", "Magistri"};
        if (kurs >= 1 && kurs <= 5)
        {
            return imena[kurs - 1];
        }
        else
        {
            return "Error kurs";
        }
    }
    int getKurs() { return kurs; };

private:
    int kurs;
};

void Student::view()
{
    cout << "Fn:" << fn << "\tIme:" << ime << "\tKurs:" << kurs << "\t" << getKursName() << endl;
}
Student::Student()
{
    fn = 0;
    ime = "Noname";
    kurs = -1;
}

Student::~Student()
{
}

int main()
{
    // Student a, b;
    // a.fn = 122112;
    // a.ime = "Anna Dimitrova";
    // a.setKurs(14);
    // a.view();
    // b.view();
    // Student c(112121, "Petar Dimitrov");
    // c.setKurs(3);
    // c.view();
    //cout << a.fn << "\t" << a.ime << endl;
    //cout << b.fn << "\t" << b.ime << endl;
    // Student d(111221, "Marina Nikolova", 14);
    // d.view();
    // d.fn = 121531;
    // d.view();
    // cout << b.getKursName() << endl;
    //
    // int fak, kurs;
    // string ime;
    // cout << "fak nomer: ";
    // cin >> fak;
    // cin.ignore(100, '\n');
    // cout << "ime: ";
    // getline(cin, ime);
    // cout << "kurs: ";
    // cin >> kurs;
    // Student q(fak, ime, kurs);
    // q.view();

    vector<Student> spisak;
    int fak, kurs;
    string ime, ans;
    do
    {
        cout << "fak nomer: ";
        cin >> fak;
        cin.ignore(100, '\n');
        cout << "ime: ";
        getline(cin, ime);
        cout << "kurs: ";
        cin >> kurs;
        Student q(fak, ime, kurs);
        spisak.push_back(Student(fak, ime, kurs));
        cout << "Again (Y/n):";
        cin >> ans;
    } while (ans == "Y" || ans == "y");
    cout << "Spisak studenti:\n";
    // for (int i = 0; i < spisak.size(); i++)
    // {
    //     spisak[i].view();
    // }
    for (vector<Student>::iterator it = spisak.begin(); it != spisak.end(); it++)
    {
        it->view();
    }
    // намерете средният курмс на студентите
    double total = 0;
    for (int i = 0; i < spisak.size(); i++)
    {
        total += spisak[i].getKurs();
        cout << "Avrg" << total / spisak.size() << endl;
    }

    return 0;
}
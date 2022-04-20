#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Създайте клас за съхранение на данни за студент.

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
    void View();
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

void Student::View()
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
    Student a, b;
    a.fn = 112112;
    a.ime = "Anna Dimotrova";
    a.setKurs(1);
    a.View();
    b.View();
    Student c(112344, "Petar Petrov");
    c.setKurs(3);
    c.View();
    // cout << a.fn << "\t" << a.ime << "\t" << endl;
    // cout << b.fn << "\t" << b.ime << "\t" << endl;
    Student d(112634, "Marina Nikolova", 4);
    d.View();
    d.fn = 115200;
    d.View();
    cout << b.getKursName() << endl;
    // Въведете данни от клавиатурата и създайте обект с тях от клас Student
    // int fak, kurs;
    // string ime;

    // cout << "Fak.nomer:";
    // cin >> fak;
    // cin.ignore(100, '\n');
    // cout << "Ime:";
    // getline(cin, ime);
    // cout << "Kurs:";
    // cin >> kurs;
    // Student q(fak, ime, kurs);
    // q.View();

    // От клавиатурата да се организира въвеждане на данни за неограничен брой студенти.
    vector<Student> spisak;

    int fak, kurs;
    string ime, ans;
    do
    {
        cout << "Fak.nomer:";
        cin >> fak;
        cin.ignore(100, '\n');
        cout << "Ime:";
        getline(cin, ime);
        cout << "Kurs:";
        cin >> kurs;
        spisak.push_back(Student(fak, ime, kurs));
        cout << "Again (Y/n):";
        cin >> ans;
    } while (ans == "Y" || ans == "y");

    //Извеждане на списъка със обектите за студентите
    cout << "Spisak studenti:\n";
    // for (int i = 0; i < spisak.size(); i++)
    // {
    //     spisak[i].View();
    // }
    for (vector<Student>::iterator it = spisak.begin(); it != spisak.end(); it++)
    {
        it->View();
    }

    // Намерете средният курс на студентите
    double total = 0;
    for (int i = 0; i < spisak.size(); i++)
    {
        total += spisak[i].getKurs();
    }

    cout << "Avrg=" << total / spisak.size() << endl;
}
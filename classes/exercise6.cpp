#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*====================================================*/
class taxPayer // Абстрактен клас
{
public:
    virtual void printInfo() = 0;
    virtual double calcTax() = 0;

protected:
    string ID;
};

/*====================================================*/
class taxDod : public taxPayer
{
public:
    taxDod(string ime, double doh)
    {
        ID = ime;
        dohod = doh;
    }

    virtual void printInfo()
    {
        cout << "DOD: Ime:" << ID << ", Dohod:" << dohod << ", Tax:" << calcTax() << endl;
    };

    virtual double calcTax()
    {
        return dohod * 0.1;
    };

private:
    double dohod;
};
/*====================================================*/
class taxEstate : public taxPayer
{
public:
    taxEstate(string adres, double ocenka)
    {
        ID = adres;
        dan_ocenka = ocenka;
    };

    virtual void printInfo()
    {
        cout << "ESTATE: Adres:" << ID << ", Dan.ocenka:" << dan_ocenka << ", Tax:" << calcTax() << endl;
    };

    virtual double calcTax()
    {
        return dan_ocenka * 0.001;
    };

private:
    double dan_ocenka;
};
/*====================================================*/
class taxCar : public taxPayer
{
public:
    taxCar(string reg, int p, int a)
    {
        ID = reg;
        power = p;
        age = a;
    };

    virtual void printInfo()
    {
        cout << "CAR: Reg.nomer:" << ID << ", Moshnost:" << power << ", Vazrast:" << age << ", Tax:" << calcTax() << endl;
    };

    virtual double calcTax()
    {
        double tax = 200;

        if (power >= 100)
        {
            tax = tax * 2;
        }

        tax = tax - tax * (age * 0.05);

        return tax;
    };

private:
    int power, age;
};
/*====================================================*/
class queryTax
{
public:
    void Add(taxPayer *ptr)
    {
        opashka.push_back(ptr);
    };

    void List()
    {
        cout << "Na opashkata sa:\n";
        
        for (int i = 0; i < opashka.size(); i++)
        {
            opashka[i]->printInfo();            
        }

        if (opashka.empty())
        {
            cout << "Nqma hora na opashkata\n";
        }
    };

    void Process()
    {
        if (opashka.empty())
        {
            cout << "Nqma hora na opashkata\n";
            return;
        }

        cout << "Obrabotva se:\n";
        opashka[0]->printInfo();
        
        cout << "Plashta:" << opashka[0]->calcTax() << endl;
        opashka.erase(opashka.begin());
    };

    vector<taxPayer *> getOpashka()
    {
        return opashka;
    }

    double Total()
    {
        double suma = 0;
        
        for (int a = 0; a < opashka.size(); a++)
        {
            suma += opashka[a]->calcTax();
        }

        return suma;
    };

private:
    vector<taxPayer *> opashka;
};
/*====================================================*/
int main()
{
    queryTax q;
    string izb;
    do
    {
        cout << "\n\nMENU\n==================================\n";
        cout << "1. Dobavqne na DOD\n2. Dobavqne na ESTATE\n3. Dobavqne na MPS\n";
        cout << "4. Izvevdane na spisaka\n5. Obrabotka na danakoplateca\n6. Ochakvani danaci\n0. Izhod\n";
        cout << "IZBERETE:";
        cin >> izb;
        if (izb == "1")
        {
            string ime;
            double suma;
            cin.ignore(100, '\n');
            cout << "Ime:";
            getline(cin, ime);
            cout << "Dohod:";
            cin >> suma;
            taxDod *ptr = new taxDod(ime, suma);
            //taxDod ptr2 = taxDod("Kalin Hristov", 1000); //ptr2.printInfo();
            q.Add(ptr);
            //ptr = &ptr2;
            //ptr->printInfo();
        }
        if (izb == "2")
        {
            string adres;
            double ocenka;
            cin.ignore(100, '\n');
            cout << "Adres:";
            getline(cin, adres);
            cout << "Dan.ocenka:";
            cin >> ocenka;
            q.Add(new taxEstate(adres, ocenka));
        }
        if (izb == "3")
        {
            string reg;
            int p, a;
            cin.ignore(100, '\n');
            cout << "Reg.nomer:";
            cin >> reg;
            cout << "Moshnost:";
            cin >> p;
            cout << "Vazrast:";
            cin >> a;
            q.Add(new taxCar(reg, p, a));
        }
        if (izb == "4")
            q.List();
        if (izb == "5")
            q.Process();
        if (izb == "6")
        { // Да се намери колко данъци се очакват от хората на опашката
            /*double suma = 0;
            for (int a = 0; a < q.getOpashka().size(); a++)
            {
                suma += q.getOpashka()[a]->calcTax();
            }
            cout << "Obshto danaci:" << suma << endl;*/
            cout << "Obshto danaci:" << q.Total() << endl;
        }
    } while (izb != "0");

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> test;
    int chislo;
    do
    {
        cout << "Number:";
        cin >> chislo;
        if (chislo != 0) //test.push_back(chislo);
        {
            int pos = 0; // Метод на вмъкването
            while (pos < test.size() && chislo > test[pos])
            {
                pos++;
            }
            if (pos == test.size())
            {
                test.push_back(chislo); // Добавя като последен
            }
            else
            {
                test.insert(test.begin() + pos, chislo); //Вмъква между елементите
            }
        }

        cout << "Vector is: "; // Извеждане на вектора
        //for(int i=0;i<test.size();i++) cout<<test[i]<<", ";
        for (vector<int>::iterator p = test.begin(); p != test.end(); p++)
        {
            cout << *p << ", ";
        }
        cout << endl;

    } while (chislo != 0);

    // Намерете сумата на елементите във вектора
    int suma = 0;
    for (vector<int>::iterator p = test.begin(); p != test.end(); p++)
    {
        suma += *p;
    }
    cout << "Sumata e " << suma << endl;

    // Изведете чрез итератор стойностите на вектора отзад напред
    //cout<<"Vector is:";    // Извеждане на вектора
    //for(vector<int>::reverse_iterator p=test.rbegin();p!=test.rend();p++) cout<<*p<<", ";
    //cout<<endl;

    // Премахнете всички елементи от вектора
    // 1
    //while ( test.size()!=0 )    test.pop_back();
    //// 2
    //while ( !test.empty() )        test.pop_back();
    //// 3
    //while ( test.size()!=0 )    test.erase(test.begin());
    //// 4
    //while ( !test.empty() )        test.erase(test.begin());
    //// 5
    //test.clear();

    // Премахнете повтарящите се елементи от вектора
    /*int x = 0;
    while (x < test.size() - 1)
    {
        if (test[x] == test[x + 1])
        {
            test.erase(test.begin() + x + 1);
        }
        else
        {
            x++;
        }
    }*/
    /*int x = 1;
    while (x < test.size())
    {
        if (test[x] == test[x - 1])
        {
            test.erase(test.begin() + x);
        }
        else
        {
            x++;
        }
    }*/
    cout << "Vector is: "; // Извеждане на вектора
    for (vector<int>::iterator p = test.begin(); p != test.end(); p++)
    {
        cout << *p << ", ";
    }
    cout << endl;

    // Във втори вектор прехвърлете разликите между съседните елементи от първият вектор
    // Пример: 1 3 4 7 7 11        ->    2 1 3 0 4
    vector<int> v2;
    /*for (int i = 0; i < test.size() - 1; i++)
    {
        v2.push_back(test[i + 1] - test[i]);
    }*/
    for (int i = 1; i < test.size(); i++)
    {
        v2.push_back(test[i] - test[i - 1]);
    }
    
    cout << "V2 is: "; // Извеждане на вектора
    
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << ", ";
    }
    
    cout << endl;
}
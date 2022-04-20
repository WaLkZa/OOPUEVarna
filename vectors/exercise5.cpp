#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
//Даден е текстов файл с думи - на всеки ред по една дума. Част от думите се повтарят.
//Да се изведе колко пъти се повтаря(среща) всяка дума.

int main()
{
    pair<int, double> t1, t2;
    t1 = make_pair(2021, 5.75);
    t2 = make_pair(2021, 5.75);

    cout << t1.first << "  " << t1.second << endl;

    // if (t1 == t2)
    // {
    //     cout << "Equal\n";
    // }
    // else
    // {
    //     cout << "Not equal\n";
    // }

    if (t1.first == t2.first && t1.second == t2.second)
    {
        cout << "Equal\n";
    }
    else
    {
        cout << "Not equal\n";
    }

    fstream fp;
    fp.open("d:\\data\\dumi.txt", ios::in);

    if (!fp.is_open())
    {
        cout << "Error to open file!\n";
        return -1;
    }

    string txt;

    //            дума    брой срещания

    vector<pair<string, int>> dumi;

    while (!fp.eof())
    {
        getline(fp, txt);
        cout << txt << endl;
        int x;
        for (x = 0; x < dumi.size(); x++)
        {
            if (dumi[x].first == txt)
            { // Има такава дума във вектора
                dumi[x].second++;
                break; // Увеличаваме броят на срещанията на думата
            }
        }

        if (x >= dumi.size())
        {
            dumi.push_back(make_pair(txt, 1)); //Нова дума за вектора
        }
    }

    fp.close();

    cout << "Vector is:\n";
    // for (int i = 0; i < dumi.size(); i++) // Извеждане, чрез индекс
    // {
    //     cout << dumi[i].first << "\t\t" << dumi[i].second << endl;
    // }

    for (vector<pair<string, int>>::iterator iter = dumi.begin(); iter != dumi.end(); iter++) //Извеждаме, чрез итератор
    {
        cout << iter->first << "\t\t" << iter->second << endl;
    }

    // Намерете средният брой срещания на думите във файла.
    double suma = 0;

    // for (vector<pair<string, int>>::iterator iter = dumi.begin(); iter != dumi.end(); iter++)
    // {
    //     suma += iter->second;
    // }

    vector<pair<string, int>>::iterator iter = dumi.begin();

    while (iter != dumi.end())
    {
        suma += iter++->second;
    }

    cout << "Avg. count=" << suma / dumi.size() << endl;

    // Във втори вектор подредете думите поброят на срещанията
    vector<pair<string, int>> sort;

    for (int i = 0; i < dumi.size(); i++)
    {
        int pos = 0; // Чрез метода на вмъкването
        while (pos < sort.size() && dumi[i].second < sort[pos].second)
        {
            pos++;
        }

        // make_pair(dumi[i].first,dumi[i].second) <-> dumi[i]
        if (pos == sort.size())
        {
            sort.push_back(dumi[i]); // Добавяне
        }
        else
        {
            sort.insert(sort.begin() + pos, dumi[i]); // Вмъкване
        }
    }
    cout << "Sort Vector is:\n";
    for (int i = 0; i < sort.size(); i++) // Извеждане, чрез индекс
    {
        cout << sort[i].first << "\t\t" << sort[i].second << endl;
    }
    // Запишете във файл, сортирания вектор във формат:
    // поред.номер: дума[TAB][TAB]срещания
    // за тези думи, които се срещат повече от 2 пъти
    fstream newfile;
    newfile.open("d:\\data\\rezult.txt", ios::out);

    for (int d = 0; d < sort.size() && sort[d].second > 2; d++)
    {
        newfile << d + 1 << ": " << sort[d].first << "\t\t" << sort[d].second << endl;
    }

    newfile.close();

    // Подредете думите от вектор - dumi, според  дължината на всяка дума, от най-дългата, към най-късата
    vector<string> v2;
    for (int i = 0; i < dumi.size(); i++)
    {
        int pos = 0; // Чрез метода на вмъкването
        while (pos < v2.size() && dumi[i].first.length() < v2[pos].length())
        {
            pos++;
        }

        if (pos == v2.size())
        {
            v2.push_back(dumi[i].first); // Добавяне
        }
        else
        {
            v2.insert(v2.begin() + pos, dumi[i].first); // Вмъкване
        }
    }

    cout << "Dictionary is:\n";

    for (int i = 0; i < v2.size(); i++) // Извеждане, чрез индекс
    {
        cout << v2[i] << endl;
    }

    return 0;
}
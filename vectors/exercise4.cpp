#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // vector<int> vec;
    // int ch;
    // do
    // {
    //     cout << "Number: ";
    //     cin >> ch;
    //     //vec.push_back(ch);

    //     if (ch != 0)
    //     {
    //         int pos = 0;
    //         while (pos < vec.size() && ch > vec[pos])
    //         {
    //             pos++;
    //         }
    //         if (pos == vec.size())
    //         {
    //             vec.push_back(ch);
    //         }
    //         else
    //         {
    //             vec.insert(vec.begin() + pos, ch);
    //         }
    //     }

    //     cout << "Vector: ";

    //     for (int i = 0; i < vec.size(); i++)
    //     {
    //         cout << vec[i] << ",";
    //     }

    // } while (ch != 0);

    // int sum = 0;
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     sum += vec[i];
    // }

    // cout << "Sumata e " << sum << endl;

    // sum = 0;
    // for (vector<int>::iterator p = vec.begin(); p != vec.end(); p++)
    // {
    //     sum += *p;
    // }

    // cout << "(iterator) Sumata e " << sum << endl;

    // while (!vec.empty())
    // {
    //     vec.pop_back();
    // }

    // while (vec.size() > 0)
    // {
    //     //vec.pop_back();
    //     vec.erase(vec.begin());
    // }

    //cout << "size: " << vec.size();

    //Премахнете повтарящите се стойности от вектора
    // int x = 1;
    // while (x < vec.size())
    // {
    //     if (vec[x - 1] == vec[x])
    //     {
    //         vec.erase(vec.begin() + x);
    //     }
    //     else
    //     {
    //         x++;
    //     }
    // }

    cout << "--------" << endl;

    // for (int i = 0; i < vec.size(); i++)
    // {
    //     cout << vec[i] << ",";
    // }

    // Във втори вектор попълнете с разликите между съседните елементи от първия вектор
    // Пример 1 2 4 8 11 12   -> 1 2 4 3 1

    vector<int> vec2 = {1, 2, 3, 4, 5, 6};

    // for (int i = 1; i < vec.size(); i++)
    // {
    //     vec2.push_back(vec[i] - vec[i - 1]);
    // }

    // for (int i = 0; i < vec2.size(); i++)
    // {
    //     cout << vec2[i] << ",";
    // }

    //Определете дали стойностите са последователни (трябва да има уникални елементи)
    int raz = 0;
    for (int i = 0; i < vec2.size(); i++)
    {
        raz += vec2[i];
        cout << ((raz == vec2.size()) ? "Posledovatelni" : "Ne sa posledovatelni") << endl;
    }
}
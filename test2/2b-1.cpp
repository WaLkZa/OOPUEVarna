#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    fstream f1;
    f1.open("D:\\data\\phone-impulse.txt", ios::in);

    if (!f1.is_open())
    {
        cout << "File is not found!" << endl;
        return -1;
    }

    string phone;
    int impulse = 0;

    vector<pair<string, int>> totalImpulses;

    while (!f1.eof())
    {
        getline(f1, phone, '\t');

        if (phone[0] == '\n')
        {
            phone.erase(0, 1);
        }

        f1 >> impulse;

        int id;

        for (id = 0; id < totalImpulses.size(); id++)
        {
            if (totalImpulses[id].first == phone)
            {
                totalImpulses[id].second += impulse;
                break;
            }
        }

        if (id == totalImpulses.size())
        {
            totalImpulses.push_back(make_pair(phone, impulse));
        }
    }

    for (int id = 0; id < totalImpulses.size(); id++)
    {
        cout << "Phone Number " << totalImpulses[id].first << "\t" << "Impulses " << totalImpulses[id].second << endl;
    }

    f1.close();
}
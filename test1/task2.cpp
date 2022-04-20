#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream f1;
    f1.open("D:\\data\\hotels.txt", ios::in);

    if (!f1.is_open())
    {
        cout << "File is not found" << endl;
        return -1;
    }

    string date;
    int room;
    string maxDate;
    int maxRoomCounter = 0;

    while (!f1.eof())
    {
        getline(f1, date, '\t');
        f1 >> room;

        if (maxRoomCounter < room)
        {
            maxRoomCounter = room;
            maxDate = date;
        }
    }

    cout << maxDate << "\t" << maxRoomCounter << endl;

    f1.close();
}
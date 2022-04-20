#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream f1;
    f1.open("D:\\data\\words.txt", ios::in);

    if (!f1.is_open())
    {
        cout << "File is not found!" << endl;
        return -1;
    }

    string line, result;

    while (!f1.eof())
    {
        getline(f1, line, '\n');
        result += line + " ";
    }

    result.replace(result.length() - 1, 1, ".");

    cout << result << endl;

    f1.close();
}
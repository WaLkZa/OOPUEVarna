#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //1 2 2 3 3 4 4 4 4 5
    vector<int> numbers;
    int number;

    cout << "Enter numbers: " << endl;
    do
    {
        cin >> number;
        numbers.push_back(number);

    } while (number != 0);

    for (int id = 1; id < numbers.size(); id++)
    {
        if (numbers[id - 1] == numbers[id])
        {
            cout << numbers[id] << " ";
        }
    }
}
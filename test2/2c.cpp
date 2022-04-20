#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    fstream file1;
    file1.open("D:\\data\\products.txt", ios::in);

    if (!file1.is_open())
    {
        cout << "File is not found!" << endl;
        return -1;
    }

    string product;
    int quantity = 0;
    int totalQuantity = 0;

    vector<pair<string, double>> totalProducts;

    while (!file1.eof())
    {
        getline(file1, product, '\t');

        if (product[0] == '\n')
        {
            product.erase(0, 1);
        }

        file1 >> quantity;

        totalQuantity += quantity;

        int id;

        for (id = 0; id < totalProducts.size(); id++)
        {
            if (totalProducts[id].first == product)
            {
                totalProducts[id].second += quantity;
                break;
            }
        }

        if (id == totalProducts.size())
        {
            totalProducts.push_back(make_pair(product, quantity));
        }
    }

    vector<pair<string, double>> sortedTotalProducts;

    for (int id = 0; id < totalProducts.size(); id++)
    {
        int pos = 0;

        while (pos < sortedTotalProducts.size() &&
               totalProducts[id].first > sortedTotalProducts[pos].first)
        {
            pos++;
        }

        if (pos == sortedTotalProducts.size())
        {
            sortedTotalProducts.push_back(totalProducts[id]);
        }
        else
        {
            sortedTotalProducts.insert(sortedTotalProducts.begin() + pos, totalProducts[id]);
        }
    }

    file1.close();

    for (int id = 0; id < sortedTotalProducts.size(); id++)
    {
        cout << sortedTotalProducts[id].first
             << "\t" << sortedTotalProducts[id].second << endl;
    }
    
    cout << endl;

    cout << "Total quantity: " << totalQuantity << endl;
}
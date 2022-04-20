#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Product
{
public:
    string name;

    Product(string n, double p)
    {
        name = n;
        setPrice(p);
    }

    void setPrice(double p)
    {
        price = p;
    }

    double getPrice()
    {
        return price;
    }

    void printInfo()
    {
        cout << name << "\t" << getPrice() << "lv." << endl;
    }

private:
    double price;
};

int main()
{
    string productName;
    double productPrice;
    vector<Product> products;
    string answer;

    do
    {
        cout << "Product name: ";
        getline(cin, productName);

        cout << "Product price: ";
        cin >> productPrice;

        products.push_back(Product(productName, productPrice));

        cout << "Again? (y/n): ";
        cin >> answer;

        cin.ignore(100, '\n');
    } while (answer == "Y" || answer == "y");

    fstream file1;
    file1.open("D:\\data\\price-list.txt", ios::out);

    cout << "Price list:\n";

    for (vector<Product>::iterator it = products.begin(); it != products.end(); it++)
    {
        it->printInfo();

        file1 << it->name << "\t" << it->getPrice() << endl;
    }

    file1.close();
}
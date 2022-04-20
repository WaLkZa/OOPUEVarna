#include <iostream>

using namespace std;

int main()
{
    // http://static.ak.fbcdn.net/rsrc.php/zB3EA/hash/7x0yx3gz.gif
    string url;
    cin >> url;

    int id = url.find("://");        // 4
    int id2 = url.find("/", id + 3); // 26
    int id3 = url.find_last_of("/"); // 46

    cout << "protocol: " << url.substr(0, id) << endl;

    int hostLength = id2 - id - 3;
    cout << "host: " << url.substr(id + 3, hostLength) << endl;

    int pathLength = id3 - id2 - 1;
    cout << "path: " << url.substr(id2 + 1, pathLength) << endl;

    cout << "file: " << url.substr(id3 + 1) << endl;
}
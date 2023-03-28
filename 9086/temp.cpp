#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    string str;
    cin >> T;
    while(T--)
    {
        cin >> str;
        cout << str.front() << str.back() << endl;
    }
    return 0;
}

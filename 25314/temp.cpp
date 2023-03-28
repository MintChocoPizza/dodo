#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for(;N>0; N -= 4)
    {
        cout << "long ";
    }

    cout << "int\n";
    return 0;
}

#include <ios>
#include <iostream>

using namespace std;

int main()
{
    long double a,b;
    cin >> a >> b;

    cout.precision(9);
    cout << std::fixed;

    cout << a/b << endl;
    return 0;
}


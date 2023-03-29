#include <iostream>

using namespace std;

int main()
{
    int a=1,b=1;
    while(cin >> a >> b && (a || b))
    {
        if(!(a/b) && a%b)
            cout << "factor\n";
        else if(a/b && !(a%b))
            cout << "multiple\n";
        else
            cout << "neither\n";
    }
    return 0;
}

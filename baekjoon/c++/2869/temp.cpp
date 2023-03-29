#include <iostream>

using namespace std;

int main()
{
    unsigned long A,B,V,i;
    cin >> A >> B >> V;

    i = (V-A)/(A-B);
    if((V-A) % (A-B))
        cout << i+2;
    else 
        cout << i+1;


    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int a;
    bool arr[31] = {0,};
    for(int i=0; i<28; i++)
    {
        cin >> a;
        arr[a] = true;
    }

    for(int i=1; i<=30; i++)
    {
        if(!arr[i])
        {
            cout << i << endl;
        }
    }
    return 0;
}

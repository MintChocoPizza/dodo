#include <iostream>

using namespace std;

int main()
{
    int a;
    int max = -1;
    int x, y;

    for(int i=1; i<10; i++)
    {
        for(int j=1; j<10; j++)
        {
            cin >> a;
            if(a>max)
            {
                max = a;
                y=i;
                x=j;
            }
        }
    }

    cout << max << endl << y << ' ' << x;
    return 0;
}

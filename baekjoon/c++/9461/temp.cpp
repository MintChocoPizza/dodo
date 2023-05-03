#include <iostream>

using namespace std;

int arr[100] = {0,1,1,1,2,2,};
int ret = 5;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;

        if(n<ret)
        {
            cout << arr[n] << '\n';
            continue;
        }

        for(int i=ret+1; i<=n; ++i)
        {
            arr[i] = arr[i-1]+arr[i-5];
        }
        cout << arr[n] << '\n';
        ret = n;
    }
    return 0;
}


// 1    1   1   2   2   3            4             5         7            9         12
//                      2+1(3)     3+1(2)         4+1(1)     5+2(4)       7+2(5)    9+3(6)  

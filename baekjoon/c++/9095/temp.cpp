#include <iostream>

using namespace std;

int arr[11] = {0,1,2,4,};

int main()
{
    int T;
    int n;
    cin >> T;

    while(T--)
    {
        cin >> n;
        
        for(int i=4; i<=n; ++i)
        {
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }
        cout << arr[n] << '\n';
    }

    return 0;
}

// 1,2,3 만 더할 수 있다. => 구해야 할 숫자n에서 1,2,3을 더하면 나오는 수들로 구할 수 있음

#include <iostream>

using namespace std;

int n;
// 1부터 시작하는거 까먹음
int arr[1001] = {0, 1, 2, };

int main()
{
    cin >> n;

    for(int i=3; i<=n; ++i)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout << arr[n]%10007;

    return 0;
}

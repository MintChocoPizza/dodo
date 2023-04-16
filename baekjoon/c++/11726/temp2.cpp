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
        // 너무 커지기 전에 나누기
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;
    }

    cout << arr[n];

    return 0;
}

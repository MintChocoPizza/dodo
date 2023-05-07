#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[501][501];
int dp[501][501];
int res = 0;

void a()
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=i; ++j)
        {
            dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i-1][j-1]);

            res = max(res, dp[i][j]);
        }
    }
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=i; ++j)
        {
            cin >> arr[i][j];
        }
    }

    a();

    cout << res;

    return 0;
}

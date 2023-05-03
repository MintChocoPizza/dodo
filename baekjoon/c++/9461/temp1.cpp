#include <iostream>

using namespace std;

            // 0  1  2  3  4  5  ..
int dp[101] = {0, 1, 1, 1, 2, 2, };
int ret = 5;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;

        if(n <= ret)
        {
            cout << dp[n] << '\n';
        }
        else
        {
            for(int i=ret; i<=n; ++i)
            {
                dp[i] = dp[i-1] + dp[i-5];
            }
            cout << dp[n];
            ret = n;
        }
    }

    return 0;
}

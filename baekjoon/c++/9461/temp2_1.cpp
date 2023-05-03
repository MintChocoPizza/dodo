#include <iostream>

using namespace std;

long long dp[101] = {0, 1, 1, 1,};
int ret = 3;

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
                dp[i] = dp[i-2] + dp[i-3];
            }
            cout << dp[n] << '\n';
            ret = n;
        }
    }
    return 0;
}

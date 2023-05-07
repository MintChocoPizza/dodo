#include <algorithm>
#include <iostream>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int res = 0;

void LIS()
{
    for(int i=1; i<=N; ++i)
    {
        int Max = 0;
        for(int j=1; j<i; ++j)
        {
            if(arr[i] > arr[j])
                Max = max(Max, dp[j]);
        }
        dp[i] = Max+1;
        res = max(res, Max+1);
    }
}

int main()
{
    cin >> N;
    for(int i=1; i<=N; ++i)
    {
        cin >> arr[i];
    }

    LIS();

    cout << res;

    return 0;
}

#include <iostream>

using namespace std;

int stairScore[301];
int dp[301];

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i)
    {
        cin >> stairScore[i];
    }

    dp[1] = stairScore[1];
    dp[2] = stairScore[2];

    for(int i=0; i<=n; ++i)
    {
        int Max = dp[i-2];

        // 바로 직전의 계단 dp값이 전계단점수 + 전전계단 dp값이랑 다르면
        if(dp[i-1] != dp[i-2]+stairScore[i-1] )
        {
            Max = max(Max, dp[i-1]);
        }

        dp[i] = Max + stairScore[i];
    }

    cout << dp[n];

    return 0;
}
// 한칸 혹은 2칸을 움직임
// 바로 직전의 dp값이 따따 한 값이 아니라는 보장?
// 문제를 잘못 이해함, 연속된 세 개의 계단 == 나 포함 전 계단 + 전전 계단을 다 밟았나.


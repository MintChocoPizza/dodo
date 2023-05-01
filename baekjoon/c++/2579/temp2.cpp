#include <iostream>

using namespace std;

int stairScore[301];
int dp[301];

int main()
{
    int n;
    for(int i=1; i<=n; ++i)
        cin >> stairScore[i];

    // 계단을 오르는 방법
    // 1. 두 계단을 오른다.
    // 2. 현재 계단이 첫번째 계단이다. 여기서 한 계단을 오르면 연속된 두 개의 계단을 밟은 상태 이다.
    //  그럼 다음 계단은 무조건 두 계단을 올라야 연속된 세 개의 계단을 밟지 않는다.
    // 3. 마지막 계단을 밟아야 함. 위와 같이 할 경우 마지막 계단에 무조건 두 계단을 오른 상태만 도착하게 됨
    //  그러므로 n-1번째 계단에서 한 계단을 오르는 값을 한번 생각해야 함.

    dp[1] = stairScore[1];
    dp[2] = dp[1] + stairScore[2];

    for(int i=3; i<n; ++i)
    {
        if(i == n-1)
        {
            dp[n] = max(dp[n], dp[n-1]+stairScore[n]);
        }
        if(i < n-2)
            // 1. 두 계단을 오른다.
            dp[i+2] = max(dp[i+2], dp[i]+stairScore[i+2]);
        if(i < n-3)
            // 2. 한 계단을 오르고, 바로 두 계단을 오른다.
            dp[i+3] = max(dp[i+3], dp[i]+dp[i+1]+stairScore[i+3]);
    }

    cout << dp[n];

    return 0;
}

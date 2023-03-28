#include <iostream>

using namespace std;

int main()
{
    int N;
    int ans = 0;
    cin >> N;

    while(N>0)
    {
        if(N%5 == 0)
        {
            ans += (N/5);
            cout << ans;
            return 0;
        }
        N -=3;
        ans++;
    }

    cout << -1;

    return 0;
}


// 추가 다른 답
// 5의 배수가 최대한 많이 들어가기 원한다면
// %5 == 0인 순간 카운트를 증가시키고 
// 그 전까지 계속 -3을 하면 된다.
//
// 약간의 발상의 전환....


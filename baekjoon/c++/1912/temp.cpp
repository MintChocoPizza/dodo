#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int dp[100000];
int ret;


int main()
{
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> arr[i];

    ret = arr[0];

    for(int i=0; i<n; ++i)
    {
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
        ret = max(ret, dp[i]);
    }

    cout << ret;

    return 0;
}


// 1. 재귀호출 함수를 생각해/만들어 봄 -> i부터 i+n까지 전부 계산함 -> i+1부터 다시 똑같이 반복
// 2. 갑자기 dp[i] = max(arr[i], dp[i-1]+arr[i]);가 생각남...

// 1    2   3   4   5   6   7   8   9   10 
// 2    1   -4  3   4   -4  6   5   -5  1
// 2    3   -1  3   7   3   9   14
// 
// 1    1   1   4   4   4   
//      2   2       5   5
//          3           6

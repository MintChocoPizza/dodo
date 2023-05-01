#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int stairScore[301];
int cache[301][2];

int a(int idx, int cnt)
{
    // 기저 사례
    // 만약 마지막 계단을 밟지 못한다면, 매우 작은 값을 return
    if(idx > n) return -9999999;
    // 만약 연속된 3계단을 밟았다면
    if(cnt == 3) return -9999999;
    // 마지막 계단에 도착했다면, 값을 반환
    if(idx == n) return stairScore[idx];
    
    int& ret = cache[idx][cnt];
    if(ret != -1) return ret;

    return ret = stairScore[idx] + max(a(idx+1, cnt+1), a(idx+2, 1));
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> n;
    for(int i=1; i<=n; ++i)
    {
        cin >> stairScore[i];
    }

    int ret = a(1, 1);
    cout << ret;

    return 0;
}

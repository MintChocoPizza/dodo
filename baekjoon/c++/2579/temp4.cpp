#include <algorithm>
#include <cstring>
#include <iostream>

#define MIN -9999999

using namespace std;

int n;
int stairScore[301];
int cache[301][2];

int a(int idx, int cnt)
{
    // 기저 사례
    // 연속된 3계단을 밟았다면
    if(cnt == 3) return MIN;
    // 마지막 계단을 밟지 못했다
    if(idx > n) return MIN;
    // 마지막 계단에 도착
    if(idx == n) return stairScore[idx];

    int& ret = cache[idx][cnt];
    if(cache[idx][cnt] != -1) return ret;

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

    int ret = a(0, 0);
    cout << ret;

    return 0;
}

#include <cstdint>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

int rgb[1001][3];
int arr[1001][3];

int main()
{
    int N;
    cin >> N;
    for(int i=1; i<=N; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            cin >> rgb[i][j];
        }
    }

    arr[1][0] = rgb[1][0];
    arr[1][1] = rgb[1][1];
    arr[1][2] = rgb[1][2];


    for(int i=2; i<=N; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            // INT32_MAX는 컴파일러에 따라 문제가 될 수 있음.
            int temp = INT_MAX;
            for(int z=0; z<3; ++z)
            {
                if(j == z) continue;
                temp = min(temp, arr[i-1][z]);
            }
            arr[i][j] = rgb[i][j] + temp;
        }
    }

    int ret = min(arr[N][0], arr[N][1]);
    ret = min(ret, arr[N][2]);

    cout << ret;

    return 0;
}

// 백준 사이트에서 INT_MAX 를 사용하고 싶으면 #include <climits>를 추가해야함
// 백준 사이트에서 INT32_MAX는 범위 오류를 발생함

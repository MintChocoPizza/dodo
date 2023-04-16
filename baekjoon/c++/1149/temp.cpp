#include <cstdint>
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
            int temp = INT32_MAX;
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


// 런타임 에러 (Segfault)

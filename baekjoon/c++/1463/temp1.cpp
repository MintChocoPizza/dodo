#include <algorithm>
#include <iostream>

using namespace std;

int N;
int arr[1000000];

void DP(int x)
{
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
    
    for(int i=4; i<= x; ++i)
    {
        int res = arr[i-1]+1;
        if(i%3 == 0)
            res = min(res, arr[i/3]+1);
        if(i%2 == 0)
            res = min(res, arr[i/2]+1);
        arr[i] = res;
    }

    cout << arr[x];
}

int main()
{
    cin >> N;
    DP(N);
    return 0;
}

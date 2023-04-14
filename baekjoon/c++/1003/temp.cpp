#include <iostream>

using namespace std;

int arr[41][2] = 
{
    // {0,1}
    {1,0},
    {0,1},
    {1,1}
};

int main()
{
    int T;
    int N;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=3; i<=N; ++i)
        {
            if(arr[i][0]) continue;
            arr[i][0] = arr[i-1][0] + arr[i-2][0];
            arr[i][1] = arr[i-1][1] + arr[i-2][1];
        }
        cout << arr[N][0] << ' ' << arr[N][1] << '\n';
    }
    return 0;
}

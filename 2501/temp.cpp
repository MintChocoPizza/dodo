#include <iostream>

using namespace std;

int main()
{
    int N, K;
    int arr[10001] = {0,};
    int count = 0;

    cin >> N >> K;

    for(int i=1; i<=N/2; i++)
    {
        if(!(N%i))
            arr[i] = arr[N/i] = 1;
    }

    for(int i=1; i<10001; i++)
    {
        if(arr[i])
            count++;
        if(count == K)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

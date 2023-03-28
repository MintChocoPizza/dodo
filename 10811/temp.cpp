#include <iostream>

using namespace std;

int main()
{
    int N, M;
    int a, b, temp;

    int arr[101];
    cin >> N >> M;
    for(int i=1; i<=N;i++)
    {
        arr[i] = i;
    }
    for(int i=0; i<M; i++)
    {
        cin >> a >> b;
        while(a<=b)
        {
            temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
            a++;
            b--;
        }
    }

    for(int i=1; i<=N; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}

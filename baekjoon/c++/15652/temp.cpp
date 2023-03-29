#include <iostream>

using namespace std;

int N, M;
int arr[9];

void BT(int cnt, int idx)
{
    if(cnt == M)
    {
        for(int i=0; i<M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=idx; i<=N; i++)
    {
        arr[cnt] = i;
        BT(cnt+1, i);
    }
}

int main()
{
    cin >> N >> M;

    BT(0, 1);

    return 0;
}

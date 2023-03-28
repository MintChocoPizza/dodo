#include <iostream>

using namespace std;

int N, M;
int res[8];

void BT(int cnt)
{
    if (cnt == M)
    {
        for (int i=0; i< M; i++)
            cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; i++)
    {
        res[cnt] = i;
        BT(cnt+1);
    }
}

int main()
{
    cin >> N >> M;

    BT(0);

    return 0;
}

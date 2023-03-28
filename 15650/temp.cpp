#include <iostream>

using namespace std;

bool visited[9];
int N, M;
int res[9];

void BT(int cnt, int idx)
{
    if(cnt == M)
    {
        for(int i=0; i<M; i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
    for(int i=idx; i<=N; i++)
    {
        if (visited[i])continue;
        visited[i] = true;
        res[cnt] = i;
        BT(cnt+1, i+1);
        visited[i] = false;
        
    }
}

int main()
{
    cin >> N >> M;

    BT(0, 1);

    return 0;
}

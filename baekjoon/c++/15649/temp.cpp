#include <iostream>

using namespace std;

int N, M;
int visited[9];
int res[9];

void backtracking(int cnt, int idx)
{
    if(cnt == M)
    {
        for(int i=0; i<idx; i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
    for(int i=1; i<=N; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        res[idx] = i;
        backtracking(cnt+1,idx+1);
        res[idx] = 0;
        visited[i] = false;
    }
}

int main()
{
    cin >> N >> M;

    backtracking(0,0);
    return 0;
}

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int moveArr[101];
queue<pair<int, int> > q;
int visited[101];

void input()
{
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        int x, y;
        cin >> x >> y;
        moveArr[x] = y;
    }
    for(int i=0; i<M; ++i)
    {
        int u, v;
        cin >> u >> v;
        moveArr[u] = v;
    }
}

int bfs()
{
    // first: depth, second: floor
    q.push(make_pair(0, 1));
    visited[1] = true;

    int ret = 987654321;

    while(!q.empty())
    {
        int depth = q.front().first;
        int floor = q.front().second;
        q.pop();

        if(floor == 100) 
        {
            ret = min(ret, depth);
            continue;
        }

        for(int i=6; i>0; --i)
        {
            int nFloor = floor+i;
            if(visited[nFloor] || nFloor > 100) continue;
            visited[nFloor] = true;

            if(moveArr[nFloor])
            {
                nFloor = moveArr[nFloor];
                visited[nFloor] = true;
            }

            q.push(make_pair(depth+1, nFloor));
        }
        
    }

    return ret;
}

int main()
{
    input();

    cout << bfs();

    return 0;
}

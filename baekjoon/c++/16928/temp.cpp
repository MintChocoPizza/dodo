#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int movingWalkWay[101];

void input()
{
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        int x, y;
        cin >> x >> y;
        movingWalkWay[x] = y;
    }
    for(int i=0; i<M; ++i)
    {
        int u, v;
        cin >> u >> v;
        movingWalkWay[u] = v;
    }
}

int bfs(int depth, int floor)
{
    /*
    if(floor > 100)
    {
        return 987654321;
    }
    if(floor == 100)
    {
        return depth;
    }
    */ 

    if(depth >=5)
        return depth;

    /*
    if(movingWalkWay[floor])
    {
        return bfs(depth, movingWalkWay[floor]);
    }
    */

    int ret = 987654321;

    for(int i=1; i<=6; ++i)
    {
        int cand = bfs(depth+1, floor+i);

        ret = min(ret, cand);
    }

    return ret;
}

int main()
{
    input();

    cout << bfs(0, 1);

    return 0;
}

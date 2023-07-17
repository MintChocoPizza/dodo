#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct Block
{
    int floor;
    int depth;
};

int N, M;
int movingWalkWay[101];
queue<Block> q;
int visited[101];

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

int bfs()
{
    int ret = 987654321;

    Block block;
    block.floor = 1;
    block.depth = 0;

    q.push(block);
    visited[1] = true;

    while (!q.empty()) 
    {
        block = q.front();
        q.pop();

        if(block.floor == 100) 
        {
            ret = min(ret, block.depth);
            continue;
        }
        if(movingWalkWay[block.floor])
        {
            Block temp;
            temp.depth = block.depth;
            temp.floor = movingWalkWay[block.floor];
            q.push(temp);
        }

        for(int i=6; i>=1; --i)
        {
            Block temp;
            if((block.floor + i) > 100) continue;
            if(visited[block.floor + i]) continue;
            visited[block.floor + i] = true;
            
            temp.floor = block.floor+i;
            temp.depth = block.depth+1;

            q.push(temp);
        }
    }

    return ret;
}

int main()
{
    input();

    cout << bfs();
}

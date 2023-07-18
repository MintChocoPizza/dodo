#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Chessmen
{
    int y;
    int x;
    int depth;
};

int N;
int visited[200][200];

int dy[] = {-2, -2,  0, 0,  2, 2};
int dx[] = {-1,  1, -2, 2, -1, 1};

Chessmen starting;
Chessmen ending;

void input()
{
    cin >> N;
    cin >> starting.y >> starting.x >> ending.y >> ending.x;
    starting.depth = 0;
}

int dfs()
{
    queue<Chessmen> q;
    q.push(starting);
    visited[starting.y][starting.x] = true;

    int ret = 987654321;
    
    while(!q.empty())
    {
        Chessmen cur = q.front();
        q.pop();
        
        if(cur.y==ending.y && cur.x==ending.x)
        {
            ret = min(ret, cur.depth);
        }

        for(int i=0; i<6; ++i)
        {
            Chessmen next;
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];
            next.depth = cur.depth+1;

            if(next.y<0 || next.x<0 || next.y>N || next.x>N || visited[next.y][next.x]==true) continue;

            visited[next.y][next.x] = true;
            q.push(next);
        }
        
    }

    return ret;
}

int main()
{
    input();

    int ret = dfs();
    if(ret == 987654321)
        cout << -1;
    else 
        cout << ret;

    return 0;
}

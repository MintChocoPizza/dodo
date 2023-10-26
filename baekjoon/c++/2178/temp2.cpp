#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int N,M;
vector<string> vec;
int visited[101][101];

// 상하좌우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main()
{
    // visited를 -1로 초기화 한다.
    memset(visited, -1, sizeof(visited));
    // 미로를 입력받아 string형으로 저장한다.
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        string str;
        cin >> str;
        vec.push_back(str);
    }

    // {y,x}
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; ++i)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];

            // 범위 체크 
            // 1. 미로를 벗어났는지
            if(!(0<=ny && ny<N && 0<=nx && nx<M)) continue;
            // 2. 이동할 수 있는 칸인지 없는 칸인지 확인
            if(vec[ny][nx] == '0') continue;
            // 3. 방문한적 있는 칸인지 확인한다. 
            if(visited[ny][nx] != -1) continue;
            
            q.push(make_pair(ny, nx));
            visited[ny][nx] = visited[y][x]+1;
        }
    }
    
    cout << visited[N-1][M-1];
    return 0;
}

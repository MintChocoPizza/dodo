#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
bool arr[101][101];
int visited[101][101];  // int형인 이유는 방문표시와 함께 몇칸을 지나왔나 확이하기 위해서

// 상하좌우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() 
{
    // 방문 확인 배열을 -1로 초기화
    memset(visited, -1, sizeof(visited));
    cin >> N >> M;
    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=M; ++j)
        {
            cin >> arr[i][j];
        }
    }

    cout << "탐색을 시작한다" << endl;

    // BFS로 탐색을 한다.
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));
    visited[1][1] = 1;

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; ++i) 
        {
            int ny = y+dy[i];
            int nx = x+dx[i];
            
            if(visited[ny][nx] == -1) continue;
            if(0<=ny && ny<=N && 0<=nx && nx<=M)
            {
                visited[ny][nx] = visited[y][x]+1;
                q.push(make_pair(ny, nx));
            }
        }
    }

    cout << visited[N][M] << '\n';

    return 0;
}

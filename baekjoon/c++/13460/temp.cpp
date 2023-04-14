#include <iostream>
#include <queue>

using namespace std;

struct point {
    int goal;
    int y;
    int x;
};

int N, M;
char board[11][11];
int Min = 999999;
int dx[4] = {  0, -1, 0, 1};        // 위, 왼쪽, 아래, 오른쪽
int dy[4] = { -1,  0, 1, 0};        // board[y][x]
queue<point> queueR;
queue<point> queueB;

void move(point P, int direction)
{
    // 방향이 주어지면 끝까지 이동함.
}

void bfs()
{
    int level = 0;;

    while(queueR.empty())
    {
        if(level == 10)
        {
            // 비교 후 종료
        }
        point R = queueR.front();
        point B = queueB.front();
        queueR.pop();
        queueB.pop();
        for(int i=0; i<4; ++i)
        {
            // 먼저 움직일 구슬 선택
            if(i<2)
            {
                
            }
            else
            {

            }
        }
        ++level;
    }
}

int main()
{
    point P;
    cin >> N >> M;
    for(int i=0; i<N; ++i) 
    {
        for(int j=0; j<M; ++j)
        {
            cin >> board[i][j];
            if(board[i][j] == 'R')
            {
                P.y = i;
                P.x = j;
                queueR.push(P);
            }
            else if(board[i][j] == 'B')
            {
                P.y = i;
                P.x = j;
                queueB.push(P);
            }
        }
    }

    bfs();

}

// 움직이는 함수를 따로 만들어야함
// 

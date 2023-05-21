#include <iostream>
#include <queue>

using namespace std;

struct Ball 
{
    int y;
    int x;
    int level;
};

int N, M;
// 상하좌우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

char board[10][10];

Ball redBall;
Ball blueBall;

queue<Ball> q_redBall;
queue<Ball> q_blueBall;

void input()
{
    char temp;
    cin >> N >> M;

    for(int y=0; y<N; ++y)
    {
        for(int x=0; x<M; ++x)
        {
            cin >> temp;
            if(temp == 'R')
            {
                redBall.y = y;
                redBall.x = x;
                redBall.level = 0;
                board[y][x] = '.';
            }
            else if(temp == 'B')
            {
                blueBall.y = y;
                blueBall.x = x;
                blueBall.level = 0;
                board[y][x] = '.';
            }
            else 
            {
                board[y][x] = temp;
            }
        }
    }
}

// testModul
void boardPrint()
{
    cout << redBall.y << ' ' << redBall.x << endl;
    cout << blueBall.y << ' ' << blueBall.x << endl;
    for(int y=0; y<N; ++y)
    {
        for(int x=0; x<M; ++x)
        {
            cout << board[y][x] << ' ';
        }
        cout << '\n';
    }
}

Ball moveBall(Ball __moveBall, Ball __stayBall, int dir)
{
    Ball ret;

    int curY = __moveBall.y;
    int curX = __moveBall.x;

    // 보드 안에서
    while(0<=curY && curY<N && 0<=curX && curX<M)
    {
        int nextY = curY + dy[dir];
        int nextX = curX + dx[dir];

        if(board[nextY][nextX] == 'O')
        {
            curY = nextY;
            curX = nextX;
            break;
        }
        else if(board[nextY][nextX] == '#')
        {
            break;
        }
        // 다른 구슬을 만난 경우
        else if(nextY == __stayBall.y && nextX == __stayBall.x)
        {
            break;
        }
        else 
        {
            curY = nextY;
            curX = nextX;
        }
    }

    ret.y = curY;
    ret.x = curX;
    ret.level = __moveBall.level + 1;

    return ret;
}

int BFS()
{
    // queue 초기화
    q_redBall.push(redBall);
    q_blueBall.push(blueBall);

    // 임시 조건
    while(1)
    {
        Ball RedBall = q_redBall.front();
        Ball BlueBall = q_blueBall.front();
        q_redBall.pop();
        q_blueBall.pop();

        if(RedBall.level > 10)
        {
            return -1;
        }
//        if(board[RedBall.y][RedBall.x] == 'O' && board[BlueBall.y][BlueBall.x] != 'O')
//        {
//            return RedBall.level;
//        }
        if(board[BlueBall.y][BlueBall.x] == 'O')
        {
            continue;
        }
        if(board[RedBall.y][RedBall.x] == 'O')
        {
            return RedBall.level;
        }

        for(int i=0; i<4; ++i)
        {
            // q_redBall.push( 움직인 red구슬 좌표 );
            // q_blueBall.push( 움직인 Blue 구슬 좌표 );
            Ball R = RedBall;
            Ball B = BlueBall;

            if(i == 0)
            {
                // 상
                if(RedBall.y < BlueBall.y)
                {
                    R = moveBall(R, B, i);
                    B = moveBall(B, R, i);
                }
                else
                {
                    B = moveBall(B, R, i);
                    R = moveBall(R, B, i);
                }
            }
            else if(i == 1)
            {
                // 하
                if(RedBall.y > BlueBall.y)
                {
                    R = moveBall(R, B, i);
                    B = moveBall(B, R, i);
                }
                else
                {
                    B = moveBall(B, R, i);
                    R = moveBall(R, B, i);
                }
            }
            else if(i == 2)
            {
                // 좌
                if(RedBall.x < BlueBall.x)
                {
                    R = moveBall(R, B, i);
                    B = moveBall(B, R, i);
                }
                else
                {
                    B = moveBall(B, R, i);
                    R = moveBall(R, B, i);
                }
            }
            else if(i == 3)
            {
                // 우
                if(RedBall.x > BlueBall.x)
                {
                    R = moveBall(R, B, i);
                    B = moveBall(B, R, i);
                }
                else
                {
                    B = moveBall(B, R, i);
                    R = moveBall(R, B, i);
                }
            }
            
            q_redBall.push(R);
            q_blueBall.push(B);
        }
    }
}

int main()
{
    input();

    cout << BFS() << '\n';

    return 0;
}

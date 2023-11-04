#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int Time = 0;
int board[101][101];    // 뱀:1, 사과:2

// 시계방향: 우 하 좌 상
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void printBoard(int N)
{
    for(int y=1; y<=N; ++y)
    {
        for(int x=1; x<=N; ++x)
        {
            cout << board[y][x] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    int N, K, L;
    queue<pair<int, char> > command;
    queue<pair<int, int> > snake;
    int dire = 0;

    // 뱀 위치 초기화 
    snake.push(make_pair(1, 1));
    board[1][1] = 1;
    
    cin >> N >> K;
    for(int i=0; i<K; ++i)
    {
        int y, x;
        cin >> y >> x;
        board[y][x] = 2;
    }

    cin >> L;
    for(int i=0; i<L; ++i)
    {
        int X;
        char C;
        cin >> X >> C;
        command.push(make_pair(X, C));
    }

    while(1)
    {
        printBoard(N);
        // 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
        snake.push(make_pair(snake.back().first+dy[dire], snake.back().second+dx[dire]));
        
        // 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
        if(snake.back().first<1 || N<snake.back().first || snake.back().second<1 || N<snake.back().second ||
                board[snake.back().first][snake.back().second]==1) break;

        // 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
        if(board[snake.back().first][snake.back().second] == 2)
        {
            board[snake.back().first][snake.back().second] = 0;
        }
        // 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
        else 
        {
            board[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }

        // 머리 이동과 시간을 갱신한다.
        board[snake.back().first][snake.back().second] = 1;
        ++Time;


        if(Time == command.front().first)
        {
            char Alpha = command.front().second;
            command.pop();

            if(Alpha == 'D') 
            {
                dire = (dire+1)%4;
            }
            else 
            {
                --dire;
                if(dire<0) dire = 3;
            }
        }
    }

    cout << Time;

    return 0;
}

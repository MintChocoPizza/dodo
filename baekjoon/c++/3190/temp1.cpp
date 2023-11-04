#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int Time = 0;

// 시계방향: 상 우 하 좌
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main(int argc, char** argv)
{
    int N, K, L;
    bool snakeMap[101][101]; // 뱀의 위치 
    bool apple[101][101]; // 사과의 위치
    queue<pair<int, int> > snake; // 뱀의 head: snake.back/  tail: snake.front
    queue<pair<int, char> > command;
    int dire = 1; // 처음 방향은 오른쪽

    // apple를 0으로 초기화 한다.
    memset(apple, 0, sizeof(apple));
    snakeMap[1][1] = true; // 뱀의 초기 위치를 초기화
    snake.push(make_pair(1,1)); // 뱀의 위치를 (1,1)로 초기화한다. 

    cin >> N >> K;
    
    // K개의 사과위치 입력
    for(int i=0; i<K; ++i)
    {
        int y, x;
        cin >> y >> x;
        apple[y][x] = true;
    }

    // 뱀의 방향 변환 횟수L
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

        // 먼저 뱀은 몸길이를 늘려 "머리를 다음칸에 위치시킨다."
        snake.push(make_pair(snake.back().first+dy[dire], snake.back().second+dx[dire]));

        // "만약" "벽이나 자기자신의 몸과 부딪히면" 게임은 "끝난다."
        if(1>snake.back().first || snake.back().first>N || 1>snake.back().second || snake.back().second>N 
                || snakeMap[snake.back().first][snake.back().second]) break;

        // "만약" 이동한 칸에 사과가 있다면 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
        if(apple[snake.back().first][snake.back().second]) 
        {
            apple[snake.back().first][snake.back().second] = false;
        } else // "만약" 이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 안는다. 
        {
            // 꼬리 저장 위치 지우기
            snakeMap[snake.front().first][snake.front().second] = false;
            snake.pop();
        }

        // 이동한 머리 위치 저장 
        snakeMap[snake.back().first][snake.back().second] = true;
        
        // 게임 시간으로 X초가 끝난 뒤에 머리 방향 전환
        // 게임 시간이랑 명령어의 타임이 같다면 방향전환
        ++Time;
        if(Time == command.front().first)
        {
            char Alpha = command.front().second;
            command.pop();

            if(Alpha == 'D') // 시계방향 회전
            {
                dire = (dire+1)%4;
            }
            else // 반시계방향 회전
            {
                --dire;
                if(dire <0) dire = 3;
            }
        }


    }

    cout << Time;

    return 0;
}

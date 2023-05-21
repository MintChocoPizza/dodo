#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct ball 
{
    int y;
    int x;
    int level;  // 몇번 움직였나
};

int N, M;
// '.', '#', '0', 'R', 'B'
char board[10][10];

// 빨간 구슬의 좌표
// int redY;
// int redX;
ball redBall;
// 파란 구슬의 좌표
// int blueY;
// int blueX;
ball blueBall;

// 방향에 대한 상대적 좌표
// 상좌하우 +2를 하면 반대 좌표가 됨
int dy[4] = {-1,  0, 1, 0};
int dx[4] = { 0, -1, 0, 1};


// 구슬들이 이동한 위치를 큐에 저장하여 너비 우선 탐색
queue<ball> q_redBall;
queue<ball> q_blueBall;

void input()
{
    cin >> N >> M;
    for(int y=0; y<N; ++y)
    {
        for(int x=0; x<M; ++x)
        {
            // board입력
            cin >> board[y][x];
            // 구슬의 좌표를 따로 저장해둠
            if(board[y][x] == 'R')
            {
                // redY = y;
                // redX = x;
                redBall.y = y;
                redBall.x = x;
                redBall.level = 0;
            }
            if(board[y][x] == 'B')
            {
                // blueY = y;
                // blueX = x;
                blueBall.y = y;
                blueBall.x = x;
                blueBall.level = 0;
            }
        }
    }
}

ball moveBall(ball __moveBall, ball __stayBall, int dir)
{
    /*
        구슬이 움직임
        벽을 만나면 멈춤
        다른 구슬을 만나면 멈춤
        구멍을 만나면 들어감?
     */
    // 현재 좌표 저장
    int curY = __moveBall.y;
    int curX = __moveBall.x;

    ball retBall;

    // 보드에서 벗어난 경우가 아니라면
    // 필요 없어보이는데 일단 함
    while(0<=curY && curY<N && 0<=curX && curX<M)
    {
        // 다음에 움직일 좌표 확인
        int nextY = curY + dy[dir];
        int nextX = curX + dx[dir];

        // 벽을 만난 경우
        if(board[nextY][nextX] == '#')
        {
            break;
        }
        // 다른 구슬을 만난 경우
        if(nextY==__stayBall.y && nextX==__stayBall.x)
        {
            break;
        }
        if(board[nextY][nextX] == '0')
        {
            curY = nextY;
            curX = nextX;
            break;
        }

        curY = nextY;
        curX = nextX;
    }

    retBall.y = curY;
    retBall.x = curX;
    retBall.level = __moveBall.level + 1;

    return retBall;

}

// 어떤 구슬이 앞에 있는지 확인하여 move함수를 실행함
void whatISFront(ball R, ball B, int dir)
{
    ball tempR, tempB;
    // 상 좌 하 우
    if(dir == 0)
    {
        if(R.y < B.y)
        {
            tempR = moveBall(R, B, dir);
            tempB = moveBall(B, tempR, dir);
        }
        else
        {
            tempB = moveBall(B, R, dir);
            tempR = moveBall(R, tempB, dir);
        }
    }
    else if(dir == 1)
    {
        if(R.x < B.x)
        {
            tempR = moveBall(R, B, dir);
            tempB = moveBall(B, tempR, dir);
        }
        else
        {
            tempB = moveBall(B, R, dir);
            tempR = moveBall(R, tempB, dir);
        }
    }
    else if(dir == 2)
    {

        if(R.y > B.y)
        {
            tempR = moveBall(R, B, dir);
            tempB = moveBall(B, tempR, dir);
        }
        else
        {
            tempB = moveBall(B, R, dir);
            tempR = moveBall(R, tempB, dir);
        }
    }
    else if(dir == 3)
    {
        if(R.x > B.x)
        {
            tempR = moveBall(R, B, dir);
            tempB = moveBall(B, tempR, dir);
        }
        else
        {
            tempB = moveBall(B, R, dir);
            tempR = moveBall(R, tempB, dir);
        }
    }
    
    blueBall = tempB;
    redBall = tempR;
    
}

int BFS()
{

    /*
        문제가 생겼음
        구슬을 움직이면 다음 구슬을 움직일 때 이동한 위치를 반영해야 함...
        그럼 move를 한번에 생각해야함

        하나의 구슬 묶음은 같은 인덱스에 저장됨 -> 하나의 구슬을 움직이고,
        그 구슬의 위치를 임시 위치에 저장하여도 전혀 상관 없음1
    */
    
    q_redBall.push(redBall);
    q_blueBall.push(blueBall);

    while(true)
    {
        ball tempRedBall = q_redBall.front();
        ball tempBlueBall = q_blueBall.front();

        q_redBall.pop();
        q_blueBall.pop();

        /*
            종료조건
            1. 10번 이상 움직임
            2. 구멍에 들어가면 조건문
            3. blue구슬이 들어가면 무조건 false
            4. 아니고 red구슬이 들어가면 true
         */
        if(tempBlueBall.level > 10)
        {
            return -1;
        }
        // blue구슬이 들어가면 
        if(board[tempBlueBall.y][tempBlueBall.x] == '0')
        {
            return -1;
        }
        // red구슬이 들어가면
        if(board[tempRedBall.y][tempRedBall.y] == '0')
        {
            return tempRedBall.level;
        }

        for(int i=0; i<4; ++i)
        {
            // 먼저 움직일 구슬을 움직이고, 정적 변수에 저장 후 queue에 저장
            whatISFront(tempRedBall, tempBlueBall, i);
            q_redBall.push(redBall);
            q_blueBall.push(blueBall);
        }
    }
}

int main()
{
    input();

    int ret = BFS();

    cout << ret;
    return 0;
}

/*
 
    탐색의 종료 조건: 
        1. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.
        2. 구슬은 동시에 움직인다. 
        3. 빨간 구슬이 구멍에 빠지면 성공
        4. 파란 구멍이 구멍에 빠지면 실패이다.
        5. 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다.
        6. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다.
        7. 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.
            1. 벽을 만남
            2. 다른 구슬을 만남
            3. 구멍에 빠짐 

    1. board를 저장한다.
    1-1. R,B 등 구술이 나온다면 구슬의 위치를 저장해둔다. -> 그래프 너비우선 탐색의 SEED값

    2. 너비우선탐색/ 재귀호출이 아님
        1. 초깃값을 불러온다.
        2. while문을 돌린다. / while문 종료조건 생각 중..../ 
        3. queue에서 R, B의 좌표를 받아오고
        4. 상하좌우 4개의 방향으로 너비우선탐색
        5. 구슬을 동시에 움직일 수 없으므로 각각 움직일 방향에서 앞에 있는 구슬을 먼저 움직인다.

    3. 구슬 움직이는 함수


 */

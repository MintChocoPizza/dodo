// 아래 코드의 문제점음 이상하게 cctv의 시선이 배열에 남아서 다음 계산에 영향을 끼치는 문제가 발생함:
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int board[8][8];

int cctvX[8];
int cctvY[8];
int cctvCount = 0;

int blindSpot = 64;

// 우 하 좌 상
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

// 입력함수
void input()
{
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >> board[i][j];
            if(1<=board[i][j] && board[i][j]<=5)
            {
                // cctv의 y, x좌표 && cctv의 갯수를 파악함
                cctvY[cctvCount] = i;
                cctvX[cctvCount] = j;
                cctvCount++;
            }
        }
    }
}

int cntBlindSpot()
{
    int sum = 0;

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            // 만약 사각지대라면
            // 보완하기
            if(board[i][j] == 0)
            {
                sum++;
            }
        }
    }

    return sum;
}

// 오류발생함
// 1.몇번째cctv 2.초기cctv방향 3.cctv방향이동, 4.cctv의 영향
void visited(int __cctvCnt, int dir, int cnt, int num)
{
    // 한번에 한 방향만을 바라보는데 0부터 3까지 뱡향 설정
    int dDir = (dir+cnt)%4;

    // 현재 CCTV의 좌표
    int currentY = cctvY[__cctvCnt];
    int currentX = cctvX[__cctvCnt];
    
    // 1. CCTV는 벽을 통과할 수 없다.
    // 2. CCTV는 CCTV를 통과할 수 있다.
    // 3. board의 범위를 벗어나면 안된다.
    /*
        // board를 넘어간 경우
        // 아래 코드는 범위가 잘 작동하지 않는 문제가 있음
        if((0>currentY || currentY>=N) && (0>currentX || currentX>=M))
        {
            return;
        }
    */
    while (currentY >= 0 && currentY < N && currentX >= 0 && currentX < M)
    {
        /*
        // 좌표 한 칸 이동
        currentY += dy[dDir];
        currentX += dx[dDir];    

        // 벽을 만난 경우
        if (board[currentY][currentX] == 6)
        {
            return;
        }
        // CCTV는 그냥 지나침
        if (1 <= board[currentY][currentX] && board[currentY][currentX] <= 5)
        {
            continue;
        }
        board[currentY][currentX] += num;
        */

        // 벽을 만난 경우
        if(board[currentY][currentX] == 6)
        {
            break;
            return;
        }
        // cctv인 경우 아무런 연산을 하지 않고 지나침
        if(1<=board[currentY][currentX] && board[currentY][currentX]<=5)
        {
            continue;
        }
        // board를 벗어나지 않고, 벽을(6)을 만나지 않고, 다른cctv(1~5)를 만나지 않은 경우
        // cctv의 영향을 표현함
        board[currentY][currentX] += num;
        currentY += dy[dDir];
        currentX += dx[dDir];
    }


    return ;
}

void BF(int __cctvCount)
{
    // 기저 사례
    // 1. 모든 CCTV를 확인했다면 사각지대를 확인한다.
    if(__cctvCount == cctvCount)
    {
        blindSpot = min(blindSpot, cntBlindSpot());
        return ;
    }
    /*
    if(__cctvCnt == cctvCount)
    {
        int temp = blindSpot;
        blindSpot = min(blindSpot, cntBlindSpot());

        // test code
        if(temp != blindSpot)
        {
            cout << "blindSpot: " << blindSpot << endl;
            for(int i=0; i<N; ++i)
            {
                for(int j=0; j<M; ++j)
                {
                    cout << board[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
    } */

    // cctv의 타입(1~5)를 저장
    int cctvtype = board[cctvY[__cctvCount] ][cctvX[__cctvCount] ];
    
    if(cctvtype == 1)
    {
        for(int i=0; i<4; ++i)
        {
            visited(__cctvCount, 0, i, -1);
            BF(__cctvCount+1);
            visited(__cctvCount, 0, i, 1);
        }
    }
}

int main()
{
    input();
    BF(0);
    cout << blindSpot;
    return 0;
}

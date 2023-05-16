#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int board[8][8];
int minRet = 99;

// 상대적 방향 설정
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

// cctv 위치 저장
vector<pair<int, int> > cctv;
int cctvCnt = 0;

void input()
{
    // 입력
    cin >> N >> M;
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<M; ++j)
            {
                cin >> board[i][j];
                // 1~5인 CCTV인 경우 위치 저장
                if( 0 < board[i][j] && board[i][j] < 6)
                {
                    cctv.push_back(make_pair(i, j));
                    cctvCnt++;
                }
            }
        }
}

int blindSpot()
{
    // 사각지대 계산
    int cnt = 0;

    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            if(board[i][j] == 0)
                cnt++;
        }
    }

    return cnt;
}

void visualRange(int cnt, int num)
{
    
}

void BF(int cnt)
{
    int y = cctv[cnt].first;
    int x = cctv[cnt].second;
    int version = board[y][x];

    // 기저 사례
    // 마지막 CCTV인 경우 사각지대를 계산함.
    if(cnt == cctvCnt)
    {
        minRet = min(minRet, blindSpot());
        return ;
    }

    if(version == 1)
    {
        for(int i=0; i<4; ++i)
        {
            visualRange(cnt, -1, );
            BF(cnt+1);
            visualRange(cnt, 1);
        }
    }
    else if(version == 2)
    {
    }
    else if(version == 3)
    {

    }
    else if(version == 4)
    {
    }
    else if(version == 5)
    {

    }
}

int main()
{
    input();


    cout << minRet;

    return 0;
}


// 1. 입력을 받는다.

// 2. CCTV의 시야를 체크한다. -> -1씩 
// _2 벽을 만나면 멈춤
// _3 보드 밖을 넘어가면 멈춤 
// _4 

// 3. 전체 보드를 돌면서 0인 경우(사각지대를 체크한다)
// _2 2.번이랑 같이 묶어서 다시 +1로 보드를 돌린다. -> 그럼 CCTV도 변경됨 -> 1보다 작은 경우에만

// 4. 브루트포스를 사용하여 CCTV를 돌린다. -> 
// _2 1번은 4개, 2번은 2개, 3번은 4개, 4번은 4개, 5번은 1개의 경우의 수를 가짐

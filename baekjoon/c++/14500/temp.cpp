#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int board[500][500];

// ㅡ, ㅣ
// 총 2개
int barY[2][4] = {{0, 0, 0, 0}, {0, 1, 2, 3}};
int barX[2][4] = {{0, 1, 2, 3}, {0, 0, 0, 0}};

// ㅁ
// 총 1개
int squareY[1][4] = {{0, 0, 1, 1}};
int squareX[1][4] = {{0, 1, 0, 1}};

// L, r, ㄱ, J
// 위의 모양을 뒤집은 상황
// 총 8개
int LY[8][4] = {{0,1,2,2}, {0,0,0,1}, {0,0,1,2}, {0,1, 1, 1}, {0,1,2, 2}, {0,0,0,1}, {0,0,1,2}, {0,1,1,1}};
int LX[8][4] = {{0,0,0,1}, {0,1,2,0}, {0,1,1,1}, {0,0,-1,-2}, {0,0,0,-1}, {0,1,2,2}, {0,1,0,0}, {0,0,1,2}};

// Z
// 총 4개
int ZY[4][4] = {{0,1,1,2}, {0,0,1, 1}, {0,1, 1, 2}, {0,0,1,1}};
int ZX[4][4] = {{0,0,1,1}, {0,1,0,-1}, {0,0,-1,-1}, {0,1,1,2}};

// ㅜ, ㅓ, ㅗ, ㅏ
// 총 4개
int TY[4][4] = {{0,0,0,1}, {0,1,2, 1}, {0,0,0,-1}, {0,1,2,1}};
int TX[4][4] = {{0,1,2,1}, {0,0,0,-1}, {0,1,2, 1}, {0,0,0,1}};

void input()
{
    cin >> N >> M;
    for(int y=0; y<N; ++y)
    {
        for(int x=0; x<M; ++x)
        {
            cin >> board[y][x];
        }
    }
}

// 보드의 범위를 벗어나면 false
bool rangeCheck(int y, int x)
{
    if(0<=y && y<N && 0<=x && x<M)
        return true;
    return false;
}

int selectTypeY(int type, int i, int T)
{
    int ret;
    switch (T) 
    {
        case 0:
            ret = barY[type][i];
            break;
        case 1:
            ret = squareY[type][i];
            break;
        case 2:
            ret = LY[type][i];
            break;
        case 3:
            ret = ZY[type][i];
            break;
        case 4:
            ret = TY[type][i];
            break;
    }
    return ret;
}

int selectTypeX(int type, int i, int T)
{
    int ret;
    switch (T) 
    {
        case 0:
            ret = barX[type][i];
            break;
        case 1:
            ret = squareX[type][i];
            break;
        case 2:
            ret = LX[type][i];
            break;
        case 3:
            ret = ZX[type][i];
            break;
        case 4:
            ret = TX[type][i];
            break;
    }
    return ret;
}

int sumNumbers(int y, int x, int type, int T)
{
    int dy, dx;
    int sum = 0;
    for(int i=0; i<4; ++i)
    {
        dy = selectTypeY(type, i, T);
        dx = selectTypeX(type, i, T);
        // 하나의 정사각형이라도 범위를 벗어나면 해당 type의 탐색을 멈춤 최솟값 반환
        if(!rangeCheck(y+dy, x+dx))
            return 0;
        sum += board[y+dy][x+dx];
    }
    return sum;
}

int maximumSumPosition(int y, int x)
{
    int ret = 0;

    // bar
    for(int type=0; type<2; ++type)
    {
        ret = max(ret, sumNumbers(y, x, type, 0));
    }

    // ㅁ
    for(int type=0; type<1; ++type)
    {
        ret = max(ret, sumNumbers(y, x, type, 1));
    }

    // L
    for(int type=0; type<8; ++type)
    {
        ret = max(ret, sumNumbers(y, x, type, 2));
    }

    // Z 
    for(int type=0; type<4; ++type)
    {
        ret = max(ret, sumNumbers(y, x, type, 3));
    }

    // ㅗ
    for(int type=0; type<4; ++type)
    {
        ret = max(ret, sumNumbers(y, x, type, 4));
    }

    return ret;
}

int searchBoard()
{
    int ret = 0;

    for(int y=0; y<N; ++y)
    {
        for(int x=0; x<M; ++x)
        {
            int temp = maximumSumPosition(y, x); 
            ret = max(ret, temp);
        }
    }

    return ret;
}

int main()
{
    input();
    cout << searchBoard();
    return 0;
}

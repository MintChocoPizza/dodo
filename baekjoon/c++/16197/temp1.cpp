#include <algorithm>
#include <iostream>

using namespace std;

struct Coin 
{
    int y;
    int x;
};

int N, M;
int dy[4] = {-1, 1,  0, 0};
int dx[4] = { 0, 0, -1, 1};

char board[21][21];

Coin coin[2];

void input()
{
    int temp = 0;

    cin >> N >> M;
    for(int y=1; y<=N; ++y)
    {
        for(int x=1; x<=M; ++x)
        {
            cin >> board[y][x];
            if(board[y][x] == 'o')
            {
                coin[temp].y = y;
                coin[temp].x = x;
                temp++;
            }
        }
    }
}

int minMove(Coin coin1, Coin coin2, int cnt)
{
    // 기저 사례
    if(cnt == 11)   // 10번 이상 이동한 경우 최댓값 반환
    {
        return 11;
    }
    int ret = 11;

    for(int di=0; di<4; ++di)
    {
        

        int cand = minMove(Coin coin1, Coin coin2, int cnt);

        ret = min(ret, cand);
    }

    return ret;
}

int main()
{
    input();

    cout << minMove(coin[0], coin[1], 0);
    return 0;
}

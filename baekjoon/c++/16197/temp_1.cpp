#include <iostream>
#include <algorithm>

using namespace std;

// coin의 구조체
struct Coin {
    int y;
    int x;
};

int N, M; 
char board[21][21];
Coin coin[2];
int dy[4] = {-1, 1,  0, 0};
int dx[4] = { 0, 0, -1, 1};

// 보드와 동전을 입력받고, 동전의 위치를 따로 저장한다.
void input()
{
    int idx = 0;

    cin >> N >> M;
    for(int y=0; y<N; ++y)
    {
        for(int x=0; x<M; ++x)
        {
            cin >> board[y][x];
            
            // 동전인경우 따로 위치를 저장한다. 
            if(board[y][x] == 'o')
            {
                coin[idx].y = y;
                coin[idx].x = x;
                idx++;
            }
        }
    }
}

// board 밖으로 나가면 true
bool isCoinOut(Coin tempCoin)
{
    bool ret = false;

    if(tempCoin.y < 0 || tempCoin.x < 0 || tempCoin.y >= N || tempCoin.x >= M)
    {
        ret = true;
    }
    
    return ret;
}

// 코인을 움직인다. 
// 벽 또는 다른 코인에 부딪히면 원래의 자리를 반환한다. 
Coin moveCoin(Coin temp1, Coin temp2, int direction)
{
    Coin coin;
    coin.y = temp1.y + dy[direction];
    coin.x = temp1.x + dx[direction];

    if(coin.y<0 || coin.x<0 || coin.y>=N || coin.x>=M)
        return coin;
    if(board[coin.y][coin.x] == '#')
        return temp1;
    if(coin.y == temp2.y && coin.x == temp2.x)
        return temp1;

    return coin;
}

void firstMove(Coin coin1, Coin coin2, Coin& temp1, Coin& temp2, int direction)
{
    switch(direction)
    {
        case 0:     // 아래
            if(coin1.y > coin2.y)
            {
                temp1 = coin1;
                temp2 = coin2;
            }
            else 
            {
                temp1 = coin2;
                temp2 = coin1;
            }
            break;
        case 1:     // 위
            if(coin1.y < coin2.y)
            {
                temp1 = coin1;
                temp2 = coin2;
            }
            else 
            {
                temp1 = coin2;
                temp2 = coin1;
            }
            break;
        case 2:     // 왼쪽 
            if(coin1.x < coin2.x)
            {
                temp1 = coin1;
                temp2 = coin2;
            }
            else 
            {
                temp1 = coin2;
                temp2 = coin1;
            }
            break;
        case 3:     // 오른쪽
            if(coin1.x > coin2.x)
            {
                temp1 = coin1;
                temp2 = coin2;
            }
            else 
            {
                temp1 = coin2;
                temp2 = coin1;
            }
            break;

    }
}

// 최소로 움직인 값을 반환한다. 두 동전을 떨어뜨릴 수 없거나, 버튼을 10번보다 많이 눌러야 한다면 
int minMove(Coin coin_1, Coin coin_2, int cnt)
{
    // 기저사례
    // 10번보다 많이 눌렀다면 
    if(cnt == 11)
    {
        return cnt;
    }
    // 코인이 둘다 동시에 나갔다면 가장 큰 값 반환 
    if(isCoinOut(coin_1) && isCoinOut(coin_2))
    {
        return 11;
    }
    if(isCoinOut(coin_1) && !isCoinOut(coin_2))
    {
        return cnt;
    }
    if(!isCoinOut(coin_1) && isCoinOut(coin_2))
    {
        return cnt;
    }

    // 10 이상의 값이 나올 수 없음.
    int ret = 11;

    // 4방위 이동 
    for(int i=0; i<4; ++i)
    {
        Coin temp_1;
        Coin temp_2;

        // 어떤 동전을 먼저 움직임
        firstMove(coin_1, coin_2, temp_1, temp_2, i);

        temp_1 = moveCoin(temp_1, temp_2, i);
        temp_2 = moveCoin(temp_2, temp_1, i);

        int cand = minMove(temp_1, temp_2, cnt+1);

        ret = min(ret, cand);
    }

    return ret;
}

int main()
{
    input();

    int ret = minMove(coin[0], coin[1], 0);
    if(ret == 11)
        cout << -1 << '\n';
    else 
        cout << ret << '\n';

    return 0;
}

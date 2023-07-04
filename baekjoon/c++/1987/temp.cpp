#include <algorithm>
#include <iostream>
using namespace std;

int R, C;
int dy[4] = {-1, 1,  0, 0};
int dx[4] = { 0, 0, -1, 1};
char board[20][20];
bool alpha[26];


void printBoard()
{
    for(int i=0; i<R; ++i)
    {
        for(int j=0; j<C; ++j)
        {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}


void input()
{
    cin >> R >> C;
    for(int i=0; i<R; ++i)
    {
        for(int j=0; j<C; ++j)
        {
            cin >> board[i][j];
        }
    }
}

// 말이 지날 수 있는 최대의 칸 수를 반환한다. 
int maxMovePiece(int y, int x, int cnt)
{
    // 기저 사례
    if(y<0 || x<0 || y>=R || x>=C)  // 말이 보드 밖으로 나갔다. 
    {
        return cnt;
    }
    if(alpha[board[y][x]-'A'])      // 말이 방문 했던 단어를 방문했다. 
    {
        return cnt;
    }


    int ret = 1;

    for(int i=0; i<4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // board[ny][nx]-'A'
        // 보드 위의 알파벳을 방문한 적이 있다면, 넘어간다. 
        alpha[board[ny][nx]-'A'] = true;
        int cand = maxMovePiece(ny, nx, cnt+1);

        ret = max(ret, cand);

        alpha[board[ny][nx]-'A'] = false;
    }

    return ret;
}



int main()
{
    input();

    // Piece가 처음 있는 위치의 단어를 방문표시한다.
    alpha[board[0][0]-'A'] = true;

    // Piece는 무조건 (0,0)의 단어를 밟고 시작한다.
    // 하지만 코드에서 +1 된 값이 반환되기 때문에, -1된 값인 0부터 시작한다. 
    cout << maxMovePiece(0, 0, 0);

    return 0;
}

#include <algorithm>
#include <iostream>

using namespace std;

int R, C;
int dy[4] = {-1, 1,  0, 0};
int dx[4] = { 0, 0, -1, 1};
char board[20][20];
bool alpha[26];

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
    int ret = 1;

    // 기저 사례
    if(y<0 || x<0 || y>=R || x>=C)  // 말이 보드 밖으로 나갔다. 
    {
        return cnt;
    }
    if(alpha[board[y][x]-'A'])      // 말이 방문 했던 단어를 방문했다. 
    {
        return cnt;
    }
    else                            // 방문하지 않았다면 방문 체크 후, 다른 방향에 대한 재귀호출을 수행한다.
    {
        alpha[board[y][x]-'A'] = true;  // 현재 밝고 있는 알파벳을 방문처리함 
        for(int i=0; i<4; ++i)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];
            
            int cand = maxMovePiece(ny, nx, cnt+1);

            ret = max(ret, cand);
        }
        alpha[board[y][x]-'A'] = false;
        
    }
    return ret;
}



int main()
{
    input();

    cout << maxMovePiece(0, 0, 0);

    return 0;
}

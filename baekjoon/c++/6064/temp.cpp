// 시간초 초과
#include <iostream>

using namespace std;

int M, N, x, y;

void input()
{
    cin >> M >> N >> x >> y;
}

int thisYear()
{
    int ret = 1;
    int tempX = 1;
    int tempY = 1;

    while(1)
    {
        // 기저 사례
        if(tempX == x && tempY == y)
            break;

        if(tempX == M && tempY == N)
            return -1;
        
        if(tempX < M)
            tempX++;
        else 
            tempX = 1;

        if(tempY < N)
            tempY++;
        else 
            tempY = 1;
        
        ret++;
    }

    return ret;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        input();

        cout << thisYear() << '\n';
    }

    return 0;
}


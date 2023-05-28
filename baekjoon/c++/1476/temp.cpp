#include <iostream>

using namespace std;

int E, S, M;

void input()
{
    cin >> E >> S >> M;
}

void BFS()
{
    int e=0, s=0, m=0;
    int cnt = 0;

    // !(e==E && s==S && m==M)
    while(e!=E || s!=S || m!=M)
    {
        e = (e % 15)+1;
        s = (s % 28)+1;
        m = (m % 19)+1;
        cnt++;
    }

    cout << cnt;
}

int main()
{
    input();
    BFS();

    return 0;
}

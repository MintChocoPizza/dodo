#include <iostream>

using namespace std;

int N;
int cnt;
int visited[15];

bool visitedQueen(int row)
{
    for(int i=0; i<row; i++)
    {
        if(visited[row] == visited[i] || visited[row]+row == visited[i]+i || visited[row]-visited[i] == row-i)
        {
            return true;
        }
    }
    
    return false;
}

void BT(int row)
{
    if(row == N)
    {
        cnt++;
        return;
    }
    for(int i=0; i<N; i++)
    {
        visited[row] = i;
        if(visitedQueen(row)) continue;
        BT(row+1);
    }
}

int main()
{
    cin >> N;
    BT(0);
    cout << cnt;
}

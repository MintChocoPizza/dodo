#include <iostream>

using namespace std;

int N;
int cnt;
int arr[15][15];

bool visited()
{
    
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
        arr[row][i] = true;
        if(visited) continue;
    }
}

int main()
{
    cin >> N;
    BT(0);

}



// 의미 없어서 그만함
// 2차원 배열이지만 로직은 1차원으로 생각하게 됨

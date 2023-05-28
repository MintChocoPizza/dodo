#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

int arr[9];

bool visited[9];

void input()
{
    for(int i=0; i<9; ++i)
    {
        cin >> arr[i];
    }
}

void Print()
{
    for(int i=0; i<9; ++i)
    {
        if(visited[i])
        {
            cout << arr[i] << '\n';
        }
    }
}

void BFS(int cnt, int idx, int sum)
{
    // 기저 사례: 2명을 뽑고, 키가 height과 같으면 종료
    if(cnt == 7)
    {
        if(sum == 100)
        {
            Print();
            exit(0);
        }
    }

    for(int i=idx; i<9; ++i)
    {
        if(!visited[i])
        {
            visited[i] = true;
            BFS(cnt+1, i, sum+arr[i]);
            visited[i] = false;
        }
    }
}

int main()
{
    input();
    sort(arr, arr+9);
    BFS(0, 0, 0);

    return 0;
}

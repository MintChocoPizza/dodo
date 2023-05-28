#include <iostream>

using namespace std;

int arr[9];
int visited[9];
bool End = false;

void input()
{
    for(int i=0; i<9; ++i)
    {
        cin >> arr[i];
    }
}

void BF(int cnt, int sum)
{
    if(End) return;
    if(cnt == 7)
    {
        if(sum == 100)
        {
            for(int i=0; i<9; ++i)
            {
                if(visited[i])
                {
                    cout << arr[i] << '\n';
                }
            }
            End = true;
        }
        return;
    }
    for(int i=0; i<9; ++i)
    {
        if(visited[i]) continue;

        visited[i] = true;
        BF(cnt+1, sum+arr[i]);
        visited[i] = false;
    }
}

int main()
{
    input();

    BF(0, 0);

    return 0;
}
